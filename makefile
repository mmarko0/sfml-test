all:
	clang++ main.cpp renderer.cpp -o app -std=c++17 -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -I include/ -L /opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-window -lsfml-system -lsfml-graphics
