static void T_1 F_1 ( void )
{
struct V_1 * V_2 = F_2 (
NULL , NULL , L_1 ) ;
struct V_3 V_4 ;
struct V_5 * V_5 ;
V_4 . V_2 = V_2 ;
V_4 . V_6 = 1 ;
V_4 . args [ 0 ] = V_7 ;
V_5 = F_3 ( & V_4 ) ;
F_4 ( V_5 ) ;
V_4 . args [ 0 ] = V_8 ;
V_5 = F_3 ( & V_4 ) ;
F_4 ( V_5 ) ;
}
static void T_1 F_5 ( void )
{
struct V_1 * V_2 ;
F_6 (np, NULL, L_2 ) {
struct V_1 * V_9 = F_7 ( V_2 ) ;
struct V_5 * V_5 ;
struct V_10 * V_11 ;
void T_2 * V_12 ;
T_3 * V_13 ;
T_4 V_14 ;
if ( ! V_9 )
continue;
if ( ! F_8 ( V_9 ) || F_9 ( V_2 ) )
goto V_15;
V_5 = F_10 ( V_9 , 0 ) ;
if ( F_11 ( V_5 ) )
goto V_15;
V_12 = F_12 ( V_9 , 0 ) ;
if ( ! V_12 )
goto V_16;
F_4 ( V_5 ) ;
F_13 ( V_17 L_3 ,
V_2 -> V_18 ) ;
V_11 = F_14 ( sizeof( * V_11 ) + 6 , V_19 ) ;
if ( ! V_11 )
goto V_20;
V_11 -> V_21 = V_11 + 1 ;
V_11 -> V_22 = 6 ;
V_11 -> V_23 = F_15 ( L_4 , V_19 ) ;
if ( ! V_11 -> V_23 ) {
F_16 ( V_11 ) ;
goto V_20;
}
V_13 = V_11 -> V_21 ;
V_14 = F_17 ( V_12 + V_24 ) ;
V_13 [ 0 ] = ( V_14 >> 24 ) & 0xff ;
V_13 [ 1 ] = ( V_14 >> 16 ) & 0xff ;
V_13 [ 2 ] = ( V_14 >> 8 ) & 0xff ;
V_13 [ 3 ] = V_14 & 0xff ;
V_14 = F_17 ( V_12 + V_25 ) ;
V_13 [ 4 ] = ( V_14 >> 8 ) & 0xff ;
V_13 [ 5 ] = V_14 & 0xff ;
F_18 ( V_2 , V_11 ) ;
V_20:
F_19 ( V_12 ) ;
F_20 ( V_5 ) ;
V_16:
F_21 ( V_5 ) ;
V_15:
F_22 ( V_9 ) ;
}
}
static void T_1 F_23 ( void )
{
F_24 ( L_5 , F_25 () , V_26 ) ;
F_26 ( F_17 ( V_27 ) & ~ V_28 , V_27 ) ;
F_27 ( F_28 () ) ;
F_29 () ;
F_30 () ;
F_31 () ;
F_1 () ;
F_32 () ;
F_5 () ;
#ifdef F_33
V_29 = V_30 ;
#endif
if ( F_34 ( L_6 ) )
F_35 () ;
F_36 ( NULL , V_31 , NULL , NULL ) ;
}
