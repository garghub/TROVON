static void F_1 ( T_1 * V_1 , int V_2 )
{
int V_3 = ( V_2 & V_4 ) >> 0 ;
int V_5 = ( V_2 & V_6 ) >> 3 ;
int V_7 = ( V_2 & V_8 ) >> 5 ;
T_1 V_9 = 0 ;
T_1 V_10 = 1 << V_3 ;
V_5 = 3 - V_5 ;
V_9 = V_1 [ V_7 * sizeof( V_11 ) + V_5 ] ;
#ifdef F_2
F_3 ( L_1 ,
V_7 * sizeof( V_11 ) + V_5 ) ;
F_3 ( L_2 , V_9 ) ;
F_4 ( L_3 , V_3 ) ;
#endif
if ( V_9 & V_10 ) {
V_9 &= ~ V_10 ;
} else {
V_9 |= V_10 ;
}
V_1 [ V_7 * sizeof( V_11 ) + V_5 ] = V_9 ;
}
int F_5 ( T_1 * V_1 , T_1 * V_12 ,
int V_13 )
{
int V_14 ;
int V_2 ;
int V_15 ;
V_11 V_16 ;
V_16 = F_6 () ;
if ( ( V_16 & V_17 ) > 0 ) {
int V_18 ;
for ( V_18 = 0 ; V_18 < V_13 ; V_18 ++ ) {
if ( V_12 [ V_18 ] != 0xff ) {
return - 1 ;
}
}
return 0 ;
}
if ( ( V_16 & V_19 ) == 0 ) {
return 0 ;
}
V_14 = ( V_16 & V_20 ) >> 20 ;
for ( V_15 = 0 ; V_15 < V_14 ; V_15 ++ ) {
V_2 =
F_7 ( V_15 ) & V_21 ;
F_1 ( V_1 , V_2 ) ;
}
return V_14 ;
}
