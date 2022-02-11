const char * F_1 ( unsigned int V_1 )
{
static const char * const V_2 [] = {
[ V_3 ] = L_1 ,
[ V_4 ] = L_2 ,
[ V_5 ] = L_3 ,
[ V_6 ] = L_4 ,
[ V_7 ] = L_5 ,
[ V_8 ] = L_6 ,
[ V_9 ] = L_7 ,
[ V_10 ] = L_8 ,
[ V_11 ] = L_9 ,
[ V_12 ] = L_10 ,
} ;
if ( V_1 < F_2 ( V_2 ) && V_2 [ V_1 ] )
return V_2 [ V_1 ] ;
else
return L_11 ;
}
int F_3 ( struct V_13 * V_14 , int V_15 ,
T_1 V_16 , void * V_17 , T_2 V_18 )
{
struct V_19 * V_20 = F_4 ( V_14 ) ;
int V_21 , V_1 , V_22 = 0 ;
for (; ; ) {
V_21 = V_20 -> V_21 ;
F_5 () ;
V_1 = F_6 ( V_20 -> V_23 , V_15 ,
V_20 -> V_24 , V_21 ,
V_20 -> V_25 , V_16 ,
V_17 , V_18 ) ;
if ( V_1 == V_3 )
return 0 ;
if ( F_7 ( V_1 ) || ++ V_22 >= 3 ) {
F_8 ( & V_14 -> V_20 , L_12 ,
F_1 ( V_1 ) ) ;
return - V_26 ;
}
F_9 ( V_27 ) ;
}
}
