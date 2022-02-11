static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
static void T_1 F_4 ( void )
{
F_5 ( & V_2 ) ;
}
static void T_1 F_6 ( void )
{
F_5 ( & V_3 ) ;
}
static void F_7 ( enum V_4 V_5 , const char * V_6 )
{
F_8 ( V_7 , V_8 ) ;
F_8 ( V_9 , V_10 ) ;
while ( 1 )
;
}
static void T_1 F_9 ( void )
{
struct V_11 * V_12 ;
F_10 (np, NULL, L_1 ) {
struct V_11 * V_13 = F_11 ( V_12 ) ;
struct V_14 * V_14 ;
struct V_15 * V_16 ;
void T_2 * V_17 ;
T_3 * V_18 ;
T_4 V_19 ;
if ( ! V_13 )
continue;
if ( ! F_12 ( V_13 ) || F_13 ( V_12 ) )
goto V_20;
V_14 = F_14 ( V_13 , 0 ) ;
if ( F_15 ( V_14 ) )
goto V_20;
V_17 = F_16 ( V_13 , 0 ) ;
if ( ! V_17 )
goto V_21;
F_17 ( V_14 ) ;
F_18 ( V_22 L_2 ,
V_12 -> V_23 ) ;
V_16 = F_19 ( sizeof( * V_16 ) + 6 , V_24 ) ;
if ( ! V_16 )
goto V_25;
V_16 -> V_26 = V_16 + 1 ;
V_16 -> V_27 = 6 ;
V_16 -> V_28 = F_20 ( L_3 , V_24 ) ;
if ( ! V_16 -> V_28 ) {
F_21 ( V_16 ) ;
goto V_25;
}
V_18 = V_16 -> V_26 ;
V_19 = F_22 ( V_17 + V_29 ) ;
V_18 [ 0 ] = ( V_19 >> 24 ) & 0xff ;
V_18 [ 1 ] = ( V_19 >> 16 ) & 0xff ;
V_18 [ 2 ] = ( V_19 >> 8 ) & 0xff ;
V_18 [ 3 ] = V_19 & 0xff ;
V_19 = F_22 ( V_17 + V_30 ) ;
V_18 [ 4 ] = ( V_19 >> 8 ) & 0xff ;
V_18 [ 5 ] = V_19 & 0xff ;
F_23 ( V_12 , V_16 ) ;
V_25:
F_24 ( V_17 ) ;
F_25 ( V_14 ) ;
V_21:
F_26 ( V_14 ) ;
V_20:
F_27 ( V_13 ) ;
}
}
static void T_1 F_28 ( void )
{
void T_2 * V_31 ;
V_31 = F_29 ( V_32 , 4 ) ;
F_8 ( F_22 ( V_31 ) & ~ V_33 , V_31 ) ;
F_24 ( V_31 ) ;
}
static void T_1 F_30 ( void )
{
F_28 () ;
F_31 ( F_32 () ) ;
#ifdef F_33
F_34 () ;
#endif
F_4 () ;
F_6 () ;
F_35 () ;
F_9 () ;
F_36 ( NULL , V_34 , NULL , NULL ) ;
}
