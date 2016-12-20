#include "Terrain.h"

using namespace std;

Terrain::Terrain(int xPos, int yPos, string picName):xPos(xPos), yPos(yPos), picName(picName) {
	if (!texture.loadFromFile(picName))
	{
		// error...
	}
	sprite.setTexture(texture);
	sprite.setOrigin(xPos, yPos);
	boundBox = sprite.getGlobalBounds();
}

sf::FloatRect Terrain::getBoundBox() {
	return boundBox;
}

void Terrain::drawTerrain(sf::RenderWindow &window) {
	window.draw(sprite);
}

int Terrain::getYPos()
{
	return yPos;
}

int Terrain::getXPos()
{
	return xPos;
}