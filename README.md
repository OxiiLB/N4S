# B-AIA-200-BDX-2-1-n4s-gaetan.dubernat

# 1. Need4Stek

Need4Stek is an autonomous car simulation project written in C. The goal of this project is to create an AI capable of driving a car on a track without hitting walls or going in the wrong direction. The project uses CoppeliaSim, a robot simulator by Coppelia Robotics, for creating and controlling the virtual track and car, and a custom API (n4s) for communication between the AI and the simulator.
## 2. Dependencies

- CoppeliaSim Edu V4.3.0 (Linux and Mac only)
- B-CPE-201_Need4stek_package.tgz (from the project description)

## 2. Installation

1. Download and install CoppeliaSim Edu V4.3.0 from the official website.
2. Download and unzip the B-CPE-201_Need4stek_package.tgz file.
## 3. Compilation

The project can be compiled using the provided Makefile, which includes the following rules:

- `make`: Compile the project.
- `make re`: Recompile the project.
- `make clean`: Remove object files.
- `make fclean`: Remove object files and the executable.

To compile the project, simply run:

```bash
make
```
## 4. Usage

Describe how to use your project, including any necessary steps to set up the environment and run simulations.

- `./coppeliaSim.sh`: Launch the Simulation software
- `./pipes.sh`: start your binary

## 5. API and Communication Protocol

Provide an overview of the API used in your project and the communication protocol.

The n4s binary communicates with CoppeliaSim (via a socket in C) and controls the elements in the scene. It reads commands from the standard input, performs the task, and responds by writing on the standard output.

Your binary should do the opposite: send commands by writing on the standard output and receive n4s responses by reading on the standard input.
