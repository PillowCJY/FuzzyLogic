#include <algorithm>
#include "fuzzylogic.h"

/////////////////////////////////////////////////////////////////

//Initialise Fuzzy Rules

void initFuzzyRules(fuzzy_system_rec *fl) {
	
   const int
      no_of_x_rules = 25,
      no_of_theta_rules = 25;
   
   int i;
	
//---------------------------------------------------------------------------- 	
//THETA vs. THETA_DOT	
//   
   for (i = 0;i < no_of_theta_rules;i++) {
       fl->rules[i].inp_index[0] = in_theta;
       fl->rules[i].inp_index[1] = in_theta_dot;
   }
      
   /* Regions for theta and theta_dot: */
   //sample only
   // fl->rules[0].inp_fuzzy_set[0] = in_nl;
   // fl->rules[0].inp_fuzzy_set[1] = in_nl;
   setRules(fl, in_nl, in_nl, out_nvl, 0);
   setRules(fl, in_nl, in_ns, out_nl, 1);
   setRules(fl, in_nl, in_ze, out_nm, 2);
   setRules(fl, in_nl, in_ps, out_ns, 3);
   setRules(fl, in_nl, in_pl, out_ze, 4);

   setRules(fl, in_ns, in_nl, out_nl, 5);
   setRules(fl, in_ns, in_ns, out_nm, 6);
   setRules(fl, in_ns, in_ze, out_ns, 7);
   setRules(fl, in_ns, in_ps, out_ze, 8);
   setRules(fl, in_ns, in_pl, out_ps, 9);

   setRules(fl, in_ze, in_nl, out_nvl, 10);
   setRules(fl, in_ze, in_ns, out_ns, 11);
   setRules(fl, in_ze, in_ze, out_ze, 12);
   setRules(fl, in_ze, in_ps, out_ps, 13);
   setRules(fl, in_ze, in_pl, out_pvl, 14);

   setRules(fl, in_ps, in_nl, out_ps, 15);
   setRules(fl, in_ps, in_ns, out_ze, 16);
   setRules(fl, in_ps, in_ze, out_ps, 17);
   setRules(fl, in_ps, in_ps, out_pm, 18);
   setRules(fl, in_ps, in_pl, out_pl, 19);

   setRules(fl, in_pl, in_nl, out_ze, 20);
   setRules(fl, in_pl, in_ns, out_ps, 21);
   setRules(fl, in_pl, in_ze, out_pm, 22);
   setRules(fl, in_pl, in_ps, out_pl, 23);
   setRules(fl, in_pl, in_pl, out_pvl, 24);
	
	
//----------------------------------------------------------------------------   
//X vs. X_DOT
//
   for (i = 0;i < no_of_x_rules;i++) {
   	  fl->rules[i + no_of_theta_rules].inp_index[0] = in_x;
   	  fl->rules[i + no_of_theta_rules].inp_index[1] = in_x_dot;
	}
	  
   setRules(fl, in_nl, in_nl, out_pvl, 25);
   setRules(fl, in_nl, in_ns, out_pl, 26);
   setRules(fl, in_nl, in_ze, out_pm, 27);
   setRules(fl, in_nl, in_ps, out_ps, 28);
   setRules(fl, in_nl, in_pl, out_ze, 29);

   setRules(fl, in_ns, in_nl, out_pl, 30);
   setRules(fl, in_ns, in_ns, out_pm, 31);
   setRules(fl, in_ns, in_ze, out_ps, 32);
   setRules(fl, in_ns, in_ps, out_ze, 33);
   setRules(fl, in_ns, in_pl, out_ns, 34);

   setRules(fl, in_ze, in_nl, out_pvl, 35);
   setRules(fl, in_ze, in_ns, out_pl, 36);
   setRules(fl, in_ze, in_ze, out_ze, 37);
   setRules(fl, in_ze, in_ps, out_nl, 38);
   setRules(fl, in_ze, in_pl, out_nvl, 39);

   setRules(fl, in_ps, in_nl, out_ps, 40);
   setRules(fl, in_ps, in_ns, out_ze, 41);
   setRules(fl, in_ps, in_ze, out_ns, 42);
   setRules(fl, in_ps, in_ps, out_nm, 43);
   setRules(fl, in_ps, in_pl, out_nl, 44);

   setRules(fl, in_pl, in_nl, out_ze, 45);
   setRules(fl, in_pl, in_ns, out_ns, 46);
   setRules(fl, in_pl, in_ze, out_nm, 47);
   setRules(fl, in_pl, in_ps, out_nl, 48);
   setRules(fl, in_pl, in_pl, out_nvl, 49);

	/* Regions for x and x_dot: */
   
   // fl->rules[25+0].inp_fuzzy_set[0] = in_nl;
   // fl->rules[25+0].inp_fuzzy_set[1] = in_nl;
   
   //and so on, and so forth...

   // fl->rules[25+24].out_fuzzy_set = out_nl;
      return;
}

/*fucntion to set up the fuzzy rules*/
void setRules(fuzzy_system_rec *fl, short inputA, short inputB, short outPut, int i) {
	fl->rules[i].inp_fuzzy_set[0] = inputA;
	fl->rules[i].inp_fuzzy_set[1] = inputB;
	fl->rules[i].out_fuzzy_set = outPut;

}

void initMembershipFunctions(fuzzy_system_rec *fl) {
	
   /* The X membership functions */

   //Sample routines only, to give you an idea of what to do here
  	//~ fl->inp_mem_fns[in_x][in_neg] = init_trapz (-1.5,-0.5,0,0,left_trapezoid);
   //~ fl->inp_mem_fns[in_x][in_ze] = init_trapz (-1.5,-0.5,0.5,1.5,regular_trapezoid);
   //~ fl->inp_mem_fns[in_x][in_pos] = init_trapz (0.5,1.5,0,0,right_trapezoid);
	fl->inp_mem_fns[in_x][in_nl] = init_trapz(-2.4, -2.25, -0.75, -0.25, left_trapezoid);

   /* The X dot membership functions */
   //enter the appropriate membership function initialisations here 


   /* The theta membership functions */
   //enter the appropriate membership function initialisations here
  	
   /* The theta dot membership functions */
   //enter the appropriate membership function initialisations here
  	

	
	
   return;
}

void initFuzzySystem (fuzzy_system_rec *fl) {

   //Note: The settings of these parameters will depend upon your fuzzy system design
   fl->no_of_inputs = 2;  /* Inputs are handled 2 at a time only */
   fl->no_of_rules = 50;
   fl->no_of_inp_regions = 5;
   fl->no_of_outputs = 9;
	
	
	//Sample only
	// fl->output_values [out_nvl]=-95.0;
	// fl->output_values [out_nl] = -85.0;
   

   fl->rules = (rule *) malloc ((size_t)(fl->no_of_rules*sizeof(rule)));
   initFuzzyRules(fl);
   initMembershipFunctions(fl);
   return;
}

//////////////////////////////////////////////////////////////////////////////

trapezoid init_trapz (float x1,float x2,float x3,float x4, trapz_type typ) {
	
   trapezoid trz;
   trz.a = x1;
   trz.b = x2;
   trz.c = x3;
   trz.d = x4;
   trz.tp = typ;
   switch (trz.tp) {
	   
      case regular_trapezoid:
         	 trz.l_slope = 1.0/(trz.b - trz.a);
         	 trz.r_slope = 1.0/(trz.c - trz.d);
         	 break;
	 
      case left_trapezoid:
         	 trz.r_slope = 1.0/(trz.a - trz.b);
         	 trz.l_slope = 0.0;
         	 break;
	 
      case right_trapezoid:
         	 trz.l_slope = 1.0/(trz.b - trz.a);
         	 trz.r_slope = 0.0;
         	 break;
   }  /* end switch  */
   
   return trz;
}  /* end function */

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
float trapz (float x, trapezoid trz) {
   switch (trz.tp) {
	   
      case left_trapezoid:
         	 if (x <= trz.a)
         	    return 1.0;
         	 if (x >= trz.b)
         	    return 0.0;
         	 /* a < x < b */
         	 return trz.r_slope * (x - trz.b);
	 
	 
      case right_trapezoid:
         	 if (x <= trz.a)
         	    return 0.0;
         	 if (x >= trz.b)
         	    return 1.0;
         	 /* a < x < b */
         	 return trz.l_slope * (x - trz.a);
	 
      case regular_trapezoid:
         	 if ((x <= trz.a) || (x >= trz.d))
         	    return 0.0;
         	 if ((x >= trz.b) && (x <= trz.c))
         	    return 1.0;
         	 if ((x >= trz.a) && (x <= trz.b))
         	    return trz.l_slope * (x - trz.a);
         	 if ((x >= trz.c) && (x <= trz.d))
         	    return  trz.r_slope * (x - trz.d);
         	    
	 }  /* End switch  */
	 
   return 0.0;  /* should not get to this point */
}  /* End function */

//////////////////////////////////////////////////////////////////////////////
float min_of(float values[],int no_of_inps) {
   int i;
   float val;
   val = values [0];
   for (i = 1;i < no_of_inps;i++) {
       if (values[i] < val)
	  val = values [i];
   }
   return val;
}



//////////////////////////////////////////////////////////////////////////////
float fuzzy_system (float inputs[],fuzzy_system_rec fz) {
   int i,j;
   short variable_index,fuzzy_set;
   float sum1 = 0.0,sum2 = 0.0,weight;
   float m_values[MAX_NO_OF_INPUTS];
	
   
   for (i = 0;i < fz.no_of_rules;i++) {
      for (j = 0;j < fz.no_of_inputs;j++) {
	   variable_index = fz.rules[i].inp_index[j];
	   fuzzy_set = fz.rules[i].inp_fuzzy_set[j];
	   m_values[j] = trapz(inputs[variable_index],
	       fz.inp_mem_fns[variable_index][fuzzy_set]);
	   } /* end j  */
      
       weight = min_of (m_values,fz.no_of_inputs);
				
       sum1 += weight * fz.output_values[fz.rules[i].out_fuzzy_set];
       sum2 += weight;
   } /* end i  */
 
	
	if (fabs(sum2) < TOO_SMALL) {
      cout << "\r\nFLPRCS Error: Sum2 in fuzzy_system is 0.  Press key: " << endl;
      //~ getch();
      //~ exit(1);
      return 0.0;
   }
   
   return (sum1/sum2);
}  /* end fuzzy_system  */

//////////////////////////////////////////////////////////////////////////////
void free_fuzzy_rules (fuzzy_system_rec *fz) {
   if (fz->allocated){
	   free (fz->rules);
	}
	
   fz->allocated = false;
   return;
}

