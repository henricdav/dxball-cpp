#
# Makefile
#

# SFML
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
INCLUDES = -I${SFML_ROOT}/include -L${SFML_ROOT}/lib

# Diagnosmeddelanden från kompilatorn (g++) filtreras av gccfilter.
CCC = g++

# Kompilatorflaggor, lägg till '-g' om kompilering för avlusning ska göras.
CCFLAGS += -std=c++14 -Wpedantic -Wall -Wextra -Werror #-Weffc++

# Preprocessorflaggor, -I lägger till en filkatalog i inkluderingssökvägen.
# CPPFLAGS += -I$(CODE)

# Objektkodsmoduler som ingår i det kompletta spelet
OBJECTS = dxball.o Game.o Shape.o Paddle.o Ball.o

# Huvudmål - skapas med kommandot 'make' eller 'make playingwithfire'.
dxball: $(OBJECTS) Makefile
	$(CCC) $(INCLUDES) $(CPPFLAGS) $(CCFLAGS) $(LDFLAGS) -o dxball.game $(OBJECTS) $(LIBS)

# map_test: Map.o map_test.cc
#	$(CCC) $(INCLUDES) $(CPPFLAGS) $(CCFLAGS) Map.o map_test.cc -o map_test.game $(LIBS)

# Delmål (flaggan -c avbryter innan länkning, objektkodsfil erhålls)
dxball.o: dxball.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c dxball.cc

Game.o: Game.h Game.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Game.cc

Shape.o: Shape.h Shape.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Shape.cc

Paddle.o: Paddle.h Paddle.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Paddle.cc

Ball.o: Ball.h Ball.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Ball.cc

# 'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
clean:
	@ \rm -rf *.o *.gch core

# 'make zap' tar även bort det körbara programmet och reservkopior (filer
# som slutar med tecknet '~').
zap: clean
	@ \rm -rf dxball.game *~

# Se upp vid eventuell ändring, '*' får absolut inte finnas för sig!!!
#
# '@' medför att kommandot inte skrivs ut på skärmen då det utförs av make.
# 'rm' är ett alias för 'rm -i' på IDA:s system, '\rm' innebär att "original-
# versionen", utan flaggan '-i', används.
