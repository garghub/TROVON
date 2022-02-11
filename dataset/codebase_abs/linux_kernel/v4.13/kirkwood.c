static void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static void T_1 F_3 ( void )
{
F_2 ( & V_2 ) ;
}
static void T_1 F_4 ( void )
{
struct V_3 * V_4 ;
F_5 (np, NULL, L_1 ) {
struct V_3 * V_5 = F_6 ( V_4 ) ;
struct V_6 * V_6 ;
struct V_7 * V_8 ;
void T_2 * V_9 ;
T_3 * V_10 ;
T_4 V_11 ;
if ( ! V_5 )
continue;
if ( ! F_7 ( V_5 ) || F_8 ( V_4 ) )
goto V_12;
V_6 = F_9 ( V_5 , 0 ) ;
if ( F_10 ( V_6 ) )
goto V_12;
V_9 = F_11 ( V_5 , 0 ) ;
if ( ! V_9 )
goto V_13;
F_12 ( V_6 ) ;
F_13 ( V_14 L_2 ,
V_4 -> V_15 ) ;
V_8 = F_14 ( sizeof( * V_8 ) + 6 , V_16 ) ;
if ( ! V_8 )
goto V_17;
V_8 -> V_18 = V_8 + 1 ;
V_8 -> V_19 = 6 ;
V_8 -> V_20 = F_15 ( L_3 , V_16 ) ;
if ( ! V_8 -> V_20 ) {
F_16 ( V_8 ) ;
goto V_17;
}
V_10 = V_8 -> V_18 ;
V_11 = F_17 ( V_9 + V_21 ) ;
V_10 [ 0 ] = ( V_11 >> 24 ) & 0xff ;
V_10 [ 1 ] = ( V_11 >> 16 ) & 0xff ;
V_10 [ 2 ] = ( V_11 >> 8 ) & 0xff ;
V_10 [ 3 ] = V_11 & 0xff ;
V_11 = F_17 ( V_9 + V_22 ) ;
V_10 [ 4 ] = ( V_11 >> 8 ) & 0xff ;
V_10 [ 5 ] = V_11 & 0xff ;
F_18 ( V_4 , V_8 ) ;
V_17:
F_19 ( V_9 ) ;
F_20 ( V_6 ) ;
V_13:
F_21 ( V_6 ) ;
V_12:
F_22 ( V_5 ) ;
}
}
static void F_23 ( void )
{
void T_2 * V_23 ;
V_23 = F_24 ( V_24 , 4 ) ;
F_25 ( F_17 ( V_23 ) & ~ V_25 , V_23 ) ;
}
static void T_1 F_26 ( void )
{
F_23 () ;
F_27 ( F_28 ( false ) ) ;
#ifdef F_29
F_30 () ;
#endif
F_1 () ;
F_3 () ;
F_31 () ;
F_4 () ;
F_32 ( NULL , V_26 , NULL ) ;
}
