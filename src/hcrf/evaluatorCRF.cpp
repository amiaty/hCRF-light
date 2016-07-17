/*
 hCRF-light Library 2.0 (full version http://hcrf.sf.net)
 Copyright (C) 2012 Yale Song (yalesong@mit.edu)
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <assert.h>

#include "hcrf/evaluator.h"

using namespace std;

/////////////////////////////////////////////////////////////////////
// Evaluator CRF Class
/////////////////////////////////////////////////////////////////////

// *
// Constructor and Destructor
// *

EvaluatorCRF::EvaluatorCRF() : Evaluator()
{}


EvaluatorCRF::EvaluatorCRF(InferenceEngine* infEngine, FeatureGenerator* featureGen)
:Evaluator(infEngine, featureGen)
{}

EvaluatorCRF::~EvaluatorCRF()
{}

// *
// Public Methods
// *

double EvaluatorCRF::computeError(DataSequence* X, Model* m)
{
  if(!pInfEngine || !pFeatureGen){
    throw HcrfBadPointer("In EvaluatorOCCRF::computeError");
  }
  double phi, partition;
  phi = pFeatureGen->evaluateLabels(X,m);
  partition = pInfEngine->computePartition(pFeatureGen, X, m);
  return partition - phi;
}
