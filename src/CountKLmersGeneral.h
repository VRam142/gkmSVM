/* CountKLmersGeneral.h
 *
 * Copyright (C) 2014 Mahmoud Ghandi
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include "LKTree.h"
class CCountKLmersGeneral
{
public:
	CCountKLmersGeneral(int L, int K);
	~CCountKLmersGeneral(void);

	int **table; // keeps the count
	int K,L; 
	int nrow,ncol; // nrow = C(L,K), ncol= 4^K
	int **w; //matrix for weights sum(wij*sj, 0<=j<L) gives the col index
	
//	double mu_y, mu_x; // average for all KLmers (mu_y) and all Kmers (mu_x) 
//	double N0; 


	void addSequence(int *seqBID, int size); 
	
	char *convertCol2KmerString(int col, char *sKmer); // returns K-mer for idx=col
	char *convertRow2KLmerString(int row, char *sKmer, char *sKLmer); // maps Kmer to KLmer for idx=row
	int *convertCol2bid(int col, int *bid); // returns K-mer for idx=col
	CLKTree *generateFreqTree(); 
	void calcPosNegRatio(int **negTable); // replaces the counts by 1000000*(Np-Nn)/(Np+Nn). neg table should be of exactly same size
private: 
	int *wdata; //allocated memory for w
	int fillwij(int pos, int nfilled, int idx, int *partial);
};

