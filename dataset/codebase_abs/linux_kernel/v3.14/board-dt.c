static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
F_2 (np, NULL, L_1 ) {
struct V_1 * V_3 = F_3 ( V_2 ) ;
struct V_4 * V_4 ;
struct V_5 * V_6 ;
void T_2 * V_7 ;
T_3 * V_8 ;
T_4 V_9 ;
if ( ! V_3 )
continue;
if ( ! F_4 ( V_3 ) || F_5 ( V_2 ) )
goto V_10;
V_4 = F_6 ( V_3 , 0 ) ;
if ( F_7 ( V_4 ) )
goto V_10;
V_7 = F_8 ( V_3 , 0 ) ;
if ( ! V_7 )
goto V_11;
F_9 ( V_4 ) ;
F_10 ( V_12 L_2 ,
V_2 -> V_13 ) ;
V_6 = F_11 ( sizeof( * V_6 ) + 6 , V_14 ) ;
if ( ! V_6 )
goto V_15;
V_6 -> V_16 = V_6 + 1 ;
V_6 -> V_17 = 6 ;
V_6 -> V_18 = F_12 ( L_3 , V_14 ) ;
if ( ! V_6 -> V_18 ) {
F_13 ( V_6 ) ;
goto V_15;
}
V_8 = V_6 -> V_16 ;
V_9 = F_14 ( V_7 + V_19 ) ;
V_8 [ 0 ] = ( V_9 >> 24 ) & 0xff ;
V_8 [ 1 ] = ( V_9 >> 16 ) & 0xff ;
V_8 [ 2 ] = ( V_9 >> 8 ) & 0xff ;
V_8 [ 3 ] = V_9 & 0xff ;
V_9 = F_14 ( V_7 + V_20 ) ;
V_8 [ 4 ] = ( V_9 >> 8 ) & 0xff ;
V_8 [ 5 ] = V_9 & 0xff ;
F_15 ( V_2 , V_6 ) ;
V_15:
F_16 ( V_7 ) ;
F_17 ( V_4 ) ;
V_11:
F_18 ( V_4 ) ;
V_10:
F_19 ( V_3 ) ;
}
}
static void T_1 F_20 ( void )
{
F_21 ( L_4 , F_22 () ) ;
F_23 ( F_14 ( V_21 ) & ~ V_22 , V_21 ) ;
F_24 ( F_25 () ) ;
F_26 () ;
F_27 () ;
F_28 () ;
F_29 () ;
F_1 () ;
#ifdef F_30
V_23 = V_24 ;
#endif
if ( F_31 ( L_5 ) )
F_32 () ;
F_33 ( NULL , V_25 , NULL , NULL ) ;
}
