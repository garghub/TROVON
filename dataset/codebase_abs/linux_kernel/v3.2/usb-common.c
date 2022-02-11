const char * F_1 ( enum V_1 V_2 )
{
static const char * const V_3 [] = {
[ V_4 ] = L_1 ,
[ V_5 ] = L_2 ,
[ V_6 ] = L_3 ,
[ V_7 ] = L_4 ,
[ V_8 ] = L_5 ,
[ V_9 ] = L_6 ,
} ;
if ( V_2 < 0 || V_2 >= F_2 ( V_3 ) )
V_2 = V_4 ;
return V_3 [ V_2 ] ;
}
