/* -*- c++ -*- ----------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under 
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------
   Contributing author: Axel Kohlmeyer (Temple U)
------------------------------------------------------------------------- */

#ifdef PAIR_CLASS

PairStyle(lj/cut/omp,PairLJCutOMP)

#else

#ifndef LMP_PAIR_LJ_CUT_OMP_H
#define LMP_PAIR_LJ_CUT_OMP_H

#include "pair_omp.h"

namespace LAMMPS_NS {

class PairLJCutOMP : public PairOMP {
 public:
  PairLJCutOMP(class LAMMPS *);
  ~PairLJCutOMP();
  virtual void compute(int, int);
  virtual void settings(int, char **);
  void coeff(int, char **);
  virtual void init_style();
  void init_list(int, class NeighList *);
  double init_one(int, int);
  void write_restart(FILE *);
  void read_restart(FILE *);
  void write_restart_settings(FILE *);
  void read_restart_settings(FILE *);
  double single(int, int, int, int, double, double, double, double &);

  void compute_inner();
  void compute_middle();
  void compute_outer(int, int);

 protected:
  double cut_global;
  double **cut;
  double **epsilon,**sigma;
  double **lj1,**lj2,**lj3,**lj4,**offset;
  double *cut_respa;

  void allocate();
};

}

#endif
#endif
