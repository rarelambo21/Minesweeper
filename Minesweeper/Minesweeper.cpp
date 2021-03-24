#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

int main() {
	srand(time(0));

	// creating a render of the game
	RenderWindow app(VideoMode(400, 400), "Minesweaper Game!!!");

	int w = 32;
	int grid[12][12]; // game grid
	int sgrid[12][12];	// game grid for showing

	Texture t; 
	t.loadFromFile("images/tiles.jpg");
	Sprite s(t);

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			sgrid[i][j] = 10;
		}

	while (app.isOpen()) {
		Event e;

		while (app.pollEvent(e)) {
			if (e.type == Event::Closed)
				app.close();
		}

		app.clear(Color::White);

		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++) {
				s.setTextureRect(IntRect(sgrid[i][j] * w, 0, w, w));
				s.setPosition(i * w, j * w);
				app.draw(s);
			}

		app.display();
	}

	return 0;
}
