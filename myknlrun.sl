#!/bin/bash -l

#SBATCH -p debug
#SBATCH -N 8
#SBATCH -C haswell
#SBATCH -t 00:30:00
#SBATCH -L SCRATCH
#SBATCH -J gloompi

#OpenMP stuff
#export OMP_NUM_THREADS=68
#export OMP_PLACES=threads
#export OMP_PROC_BIND=spread

srun -n 8 -N 8 ./mpigloo
#mpirun -n 8 -ppn 1 ./mpigloo
