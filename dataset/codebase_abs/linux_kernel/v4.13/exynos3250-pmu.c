static void F_1 ( enum V_1 V_2 )
{
unsigned int V_3 ;
unsigned int V_4 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_5 ) ; V_3 ++ ) {
V_4 = F_3 ( V_5 [ V_3 ] ) ;
V_4 &= ~ ( V_6 ) ;
V_4 |= V_7 ;
F_4 ( V_4 , V_5 [ V_3 ] ) ;
}
if ( V_2 != V_8 )
return;
F_4 ( V_9 , V_10 ) ;
F_4 ( V_11 , V_12 ) ;
F_4 ( V_13 , V_14 ) ;
F_4 ( V_15 ,
V_16 ) ;
}
static void F_5 ( void )
{
unsigned int V_17 ;
V_17 = F_3 ( V_18 ) ;
V_17 |= V_19 ;
F_4 ( V_17 , V_18 ) ;
F_4 ( V_20 , V_21 ) ;
V_17 = F_3 ( V_22 ) ;
V_17 |= V_23 ;
F_4 ( V_17 , V_22 ) ;
V_17 = F_3 ( V_22 ) ;
V_17 |= V_24 ;
F_4 ( V_17 , V_22 ) ;
}
