CC = gcc
CFLAGS = -lncurses -O3
PARTICLE_OUT = particle_curve
PARTICLE_FLAGS = $(CFLAGS) -o $(PARTICLE_OUT) $(PARTICLE_OUT).c

paticle_curve:
	$(CC) $(PARTICLE_FLAGS)