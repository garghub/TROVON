T_1 F_1 ( T_1 V_1 , struct V_2 * V_3 )
{
T_1 V_4 , V_5 , V_6 ;
V_4 = V_1 - V_3 -> V_7 ;
V_5 = V_4 / V_3 -> V_8 ;
V_6 = V_4 % V_3 -> V_8 ;
return ( V_5 << V_3 -> V_9 ) +
( V_6 << V_3 -> V_9 ) / V_3 -> V_8 ;
}
T_1 F_2 ( T_1 V_10 , struct V_2 * V_3 )
{
T_1 V_5 , V_6 ;
V_5 = V_10 >> V_3 -> V_9 ;
V_6 = V_10 & ( ( 1 << V_3 -> V_9 ) - 1 ) ;
return V_3 -> V_7 + V_5 * V_3 -> V_8 +
( ( V_6 * V_3 -> V_8 ) >> V_3 -> V_9 ) ;
}
int F_3 ( const struct V_11 * V_12 ,
struct V_2 * V_3 )
{
bool V_13 ;
T_2 V_14 ;
int V_15 = 0 ;
while ( 1 ) {
V_14 = V_12 -> V_16 ;
F_4 () ;
V_3 -> V_8 = V_12 -> V_8 ;
V_3 -> V_9 = V_12 -> V_9 ;
V_3 -> V_7 = V_12 -> V_7 ;
V_13 = V_12 -> V_13 ;
F_4 () ;
if ( V_12 -> V_16 == V_14 && ! ( V_14 & 1 ) )
break;
if ( ++ V_15 > 10000 ) {
F_5 ( L_1 ) ;
return - V_17 ;
}
}
if ( ! V_13 )
return - V_18 ;
return 0 ;
}
