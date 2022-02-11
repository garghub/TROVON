static void F_1 ( char * V_1 )
{
int V_2 , V_3 , V_4 ;
V_2 = ( V_1 [ 0 ] & 1 ) | ( ( V_1 [ 0 ] & 2 ) << 1 ) ;
#ifdef F_2
V_2 |= V_5 & 2 ;
V_5 = V_2 ;
#endif
V_3 = V_1 [ 1 ] ;
V_4 = V_1 [ 2 ] ;
F_3 ( V_6 , V_7 , V_3 ) ;
F_3 ( V_6 , V_8 , V_4 ) ;
F_4 ( V_6 , V_9 , V_2 & 0x4 ) ;
F_4 ( V_6 , V_10 , V_2 & 0x2 ) ;
F_4 ( V_6 , V_11 , V_2 & 0x1 ) ;
F_5 ( V_6 ) ;
return;
}
static int F_6 ( struct V_12 * V_13 )
{
#ifdef F_2
V_5 = 0 ;
#endif
F_7 () ;
F_8 ( V_14 [ 0 ] , V_14 [ 1 ] ) ;
F_9 () ;
V_15 = F_1 ;
return 0 ;
}
static void F_10 ( struct V_12 * V_13 )
{
F_11 () ;
V_15 = NULL ;
}
static int T_1 F_12 ( void )
{
int error ;
if ( ! V_16 || ! F_13 ( V_17 ) )
return - V_18 ;
error = F_14 () ;
if ( error )
return error ;
V_6 = F_15 () ;
if ( ! V_6 )
return - V_19 ;
V_6 -> V_20 = L_1 ;
V_6 -> V_21 = L_2 ;
V_6 -> V_22 . V_23 = V_24 ;
V_6 -> V_22 . V_25 = 0x0001 ;
V_6 -> V_22 . V_26 = 0x0002 ;
V_6 -> V_22 . V_27 = 0x0100 ;
V_6 -> V_28 [ 0 ] = F_16 ( V_29 ) | F_16 ( V_30 ) ;
V_6 -> V_31 [ 0 ] = F_16 ( V_7 ) | F_16 ( V_8 ) ;
V_6 -> V_32 [ F_17 ( V_9 ) ] = F_16 ( V_9 ) |
F_16 ( V_10 ) | F_16 ( V_11 ) ;
V_6 -> V_33 = F_6 ;
V_6 -> V_34 = F_10 ;
error = F_18 ( V_6 ) ;
if ( error ) {
F_19 ( V_6 ) ;
return error ;
}
return 0 ;
}
static void T_2 F_20 ( void )
{
F_21 ( V_6 ) ;
}
