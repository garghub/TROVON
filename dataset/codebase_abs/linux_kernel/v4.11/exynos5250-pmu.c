static void F_1 ( void )
{
unsigned int V_1 ;
V_1 = F_2 ( V_2 ) ;
V_1 &= ~ V_3 ;
F_3 ( V_1 , V_2 ) ;
V_1 = F_2 ( V_4 ) ;
V_1 &= ~ V_3 ;
F_3 ( V_1 , V_4 ) ;
}
static void F_4 ( enum V_5 V_6 )
{
unsigned int V_7 ;
unsigned int V_8 ;
for ( V_7 = 0 ; V_7 < F_5 ( V_9 ) ; V_7 ++ ) {
V_8 = F_2 ( V_9 [ V_7 ] ) ;
V_8 |= ( V_10 |
V_11 ) ;
F_3 ( V_8 , V_9 [ V_7 ] ) ;
}
V_8 = F_2 ( V_12 ) ;
V_8 |= V_13 ;
F_3 ( V_8 , V_12 ) ;
for ( V_7 = 0 ; V_7 < F_5 ( V_14 ) ; V_7 ++ ) {
V_8 = F_2 ( V_14 [ V_7 ] ) ;
V_8 &= ~ ( V_15 |
V_16 ) ;
F_3 ( V_8 , V_14 [ V_7 ] ) ;
}
}
