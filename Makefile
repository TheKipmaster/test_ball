.PHONY: all, clean, distclean, pack, pack-solution

all: test-ball test-ball-graphics test-springmass test-springmass-graphics

ball.o: ball.h ball.cpp
	$(CXX) ball.cpp $(CFLAGS)

test-ball: ball.o test-ball.cpp
	$(CXX) test-ball.cpp ball.o $(LFLAGS) -o test-ball

graphics.o: graphics.h graphics.cpp
	$(CXX) graphics.cpp $(CFLAGS)

test-ball-graphics: graphics.o ball.o test-ball-graphics.cpp
	$(CXX) test-ball-graphics.cpp $(OBJS1) $(LFLAGS) -o test-ball-graphics

springmass.o: springmass.cpp springmass.h
	$(CXX) springmass.cpp $(CFLAGS)

test-springmass: springmass.o test-springmass.cpp
	$(CXX) test-springmass.cpp springmass.o $(LFLAGS) -o test-springmass

test-springmass-graphics: graphics.o springmass.o test-springmass-graphics.cpp
	$(CXX) test-springmass-graphics.cpp $(OBJS2) $(LFLAGS) -o test-springmass-graphics


CXX				= g++
OBJ0			= graphics.o
OBJS1			= $(OBJ0) ball.o
OBJS2			= $(OBJ0) springmass.o
STD				= -std=c++11
LFLAGS		= $(STD) -lglut -lGL -lGLU
CFLAGS		= $(LFLAGS) -c

clean:
	find . -name '*~' -delete
	rm -f b16-lab.{ncb,suo,v11.suo,sdf,opensdf}
	rm -f b16-lab.vcproj.*.user
	rm -rf Debug/
	rm -rf b16-lab/
	rm -f test-ball test-ball-graphics test-springmass test-springmass-graphics
	rm *.o*

distclean: clean
	rm -f b16-lab.zip b16-lab-solution.zip

pack-solution:
	rm -f b16-lab-solution.zip
	git archive --format zip --prefix=b16-lab-solution/ --output b16-lab-solution.zip master

pack: pack-solution
	git archive master --prefix=b16-lab/ | tar x
	echo "$$sed_command"
	cd b16-lab ; \
	for x in *.h *.cpp ; \
	do \
	  cat "$$x" | \
	  sed '/begin remove/,/end remove/c\'$$'\n'$$'\\\n''/* INCOMPLETE: TYPE YOUR CODE HERE */'$$'\\\n'$$'\\\n' \
	  > "$${x}.tmp" ; \
	  mv "$${x}.tmp" "$$x" ; \
	done
	rm -f b16-lab.zip
	zip -r b16-lab.zip b16-lab/
	rm -rf b16-lab/
