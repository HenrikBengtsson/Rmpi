/* Copyright (C) 2002 Hao Yu
 *  
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or   
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of 
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
   
#include "Rmpi.h"
#include <sys/types.h>
#include <unistd.h>

SEXP AsInt (int x)
{
    SEXP sexp_x;
    PROTECT (sexp_x = allocVector (INTSXP, 1));
    INTEGER (sexp_x)[0] = x;
    UNPROTECT (1);
    return sexp_x;
}

SEXP pid(){
	return AsInt(getpid());
}

SEXP mkstr(SEXP sexp_charlen){
	int i, charlen = INTEGER(sexp_charlen)[0];
	char *tmp, spchar[1]=" ";
	SEXP new_strvec;
	PROTECT (new_strvec = allocVector (STRSXP, 1));
	tmp = (char *) R_alloc (charlen, sizeof(char));
	for (i=0; i < charlen; tmp[i++]=spchar[0]);	
	SET_STRING_ELT(new_strvec, 0, COPY_TO_USER_STRING(tmp));
	
	UNPROTECT(1);
	return new_strvec;
}