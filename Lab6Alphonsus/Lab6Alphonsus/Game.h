// author alphonsus
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "MyVector3.h"

class Game
{
public:
	Game();
	~Game();


	void run();

private:
	MyVector3 newBallPosition = { 600.0f, 300.0f, 0.0f };
	MyVector3 ballPosition = { 600.0f, 300.0f, 0.0f };
	MyVector3 ballVelocity = { 0.0f, 0.0f, 0.0f };
	MyVector3 mousePosition = { 0.0f, 0.0f, 0.0f };

	MyVector3 newRedBallPosition = { 400.0f, 300.0f, 0.0f };
	MyVector3 redBallPosition = { 50.0f, 100.0f, 0.0f };
	MyVector3 redBallVelocity = { 0.0f, 0.0f, 0.0f };

	MyVector3 newYellowBallPosition = { 200.0f, 300.0f, 0.0f };
	MyVector3 yellowBallPosition = { 200.0f, 300.0f, 0.0f };
	MyVector3 yellowBallVelocity = { 0.0f, 0.0f, 0.0f };

	MyVector3 pocketPositionOne = { 0,0,0 };
	MyVector3 pocketPositionTwo = { 400,0,0 };
	MyVector3 pocketPositionThree = { 800,0,0 };
	MyVector3 pocketPositionFour = { 0,600,0 };
	MyVector3 pocketPositionFive = { 400,600,0 };
	MyVector3 pocketPositionSix = { 800,600,0 };

	MyVector3 pocketPostion[6] = { pocketPositionOne, pocketPositionTwo, pocketPositionThree, pocketPositionFour, pocketPositionFive, pocketPositionSix }; // when put in an array its easier to the collisions 

	sf::RectangleShape table;
	sf::RectangleShape cushion;
	sf::CircleShape cueBall;
	sf::Vertex mouseVertex;
	sf::Vertex ballVertex;
	sf::Vertex yellowBallVertex;
	sf::VertexArray aimingLine{ sf::Lines };

	MyVector3 Radius{ 20, 20, 0 };

	const double POWER = 0.06;
	int theScoreForWhite = 0;
	int theScoreForYellow = 0;
	int InOff = 0;

	std::string display;
	sf::Font font;
	sf::Text messages;


	void friction(MyVector3 &t_ballVelocity);
	void allBallStopped();
	void collisions(MyVector3 t_positionA, MyVector3 &t_velocityA, MyVector3 t_positionB, MyVector3 &t_velocityB);
	void collisionDetection();
	void scoring();
	void cannon();
	void cannonDetection();
	void border();
	void fouls();
	void pottedBalls();
	void ballMovement(MyVector3 &t_ballPosition, MyVector3 &t_ballVelocity);
	void setUpBackgroud();
	void passBall(sf::Color, MyVector3);
	void setUpAim();
	void displayMessages();
	void loadMessages();
	void boolReset();
	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();



	sf::RenderWindow m_window; // main SFML window

	bool m_exitGame; // control exiting game
	bool m_ballStop = false;
	bool m_aim = false;
	bool m_score = false;
	bool collision = false;
	bool m_aimDone = false;
	bool m_turns = false;
	bool m_whitePocketed = false;
	bool m_yellowPocketed = false;
	bool m_redPocketed = false;
	bool m_whiteHitsRed = false;
	bool m_yellowHitsRed = false;
	bool m_whiteHitsYellow = false;
	bool m_yellowHitsWhite = false;
	bool m_cannon = false;
	bool m_foulPotting = false;
	bool m_nothingHit = false;
	bool m_redPotByWhite = false;
	bool m_redPotByYellow = false;
	bool m_whitePotByYellow = false;
	bool m_yellowPotByWhite = false;
	bool m_inOffWhite = false;
	bool m_inOffYellow = false;
	bool m_whiteSpawn = false;
	bool m_yellowSpawn = false;


};

#endif // !GAME

