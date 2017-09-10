/*################################################################################
  ##
  ##   Copyright (C) 2011-2017 Keith O'Hara
  ##
  ##   This file is part of the BMLib C++ library.
  ##
  ##   BMLib is free software: you can redistribute it and/or modify
  ##   it under the terms of the GNU General Public License as published by
  ##   the Free Software Foundation, either version 2 of the License, or
  ##   (at your option) any later version.
  ##
  ##   BMLib is distributed in the hope that it will be useful,
  ##   but WITHOUT ANY WARRANTY; without even the implied warranty of
  ##   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  ##   GNU General Public License for more details.
  ##
  ##   You should have received a copy of the GNU General Public License
  ##   along with BMLib. If not, see <http://www.gnu.org/licenses/>.
  ##
  ################################################################################*/

/*
 * Embed a matrix
 */

inline 
arma::mat 
embed(const arma::mat& X, const int p)
{
    const int n = X.n_rows;
    const int k = X.n_cols;

    arma::mat ret(n-p,k*(p+1));
    
    for (int i=0; i < (p+1); i++) {
        ret.cols(i*k,(i+1)*k-1) = X.rows(p-i,n-i-1);
    }
    //
    return ret;
}