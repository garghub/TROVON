const struct V_1 * F_1 ( int V_2 , int V_3 )
{
int V_4 ;
static const struct {
int V_5 ;
int V_6 ;
const struct V_1 * V_7 ;
const struct V_1 * V_8 ;
} V_9 [] = {
{ 27 , 32 , V_10 , V_11 } ,
{ 23 , 26 , V_12 , V_13 } ,
{ 20 , 22 , V_14 , V_15 } ,
{ 17 , 19 , V_16 , V_17 } ,
{ 15 , 16 , V_18 , V_19 } ,
{ 14 , 14 , V_20 , V_21 } ,
{ 13 , 13 , V_22 , V_23 } ,
{ 12 , 12 , V_24 , V_25 } ,
{ 11 , 11 , V_26 , V_27 } ,
{ 10 , 10 , V_28 , V_29 } ,
{ 9 , 9 , V_30 , V_31 } ,
{ 4 , 8 , V_32 , V_33 } ,
{ 3 , 3 , V_26 , V_27 } ,
{ 2 , 2 , V_18 , V_19 } ,
{ 0 , 1 , V_16 , V_17 } ,
} ;
V_2 /= 128 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_9 ) ; ++ V_4 )
if ( V_2 >= V_9 [ V_4 ] . V_5 && V_2 <= V_9 [ V_4 ] . V_6 )
return V_3 ? V_9 [ V_4 ] . V_8 : V_9 [ V_4 ] . V_7 ;
return NULL ;
}
