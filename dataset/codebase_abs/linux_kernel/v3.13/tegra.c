static void T_1 F_1 ( void )
{
#ifdef F_2
int V_1 ;
void T_2 * V_2 = F_3 ( V_3 ) + 0x3000 ;
T_3 V_4 , V_5 ;
V_5 = F_4 ( V_2 + V_6 ) ;
V_4 = ( V_5 & 0x700 ) << ( 17 - 8 ) ;
V_4 |= 0x7C400001 ;
V_1 = F_5 ( V_4 , 0x8200c3fe ) ;
if ( ! V_1 )
V_7 = F_6 ( & V_8 ) ;
#endif
}
static void T_1 F_7 ( void )
{
F_8 () ;
F_9 () ;
F_10 () ;
F_1 () ;
F_11 () ;
F_12 () ;
}
static void T_1 F_13 ( void )
{
F_14 () ;
F_15 () ;
F_16 () ;
F_17 () ;
}
static void T_1 F_18 ( void )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 = NULL ;
F_19 () ;
F_20 () ;
V_10 = F_21 ( sizeof( * V_10 ) , V_15 ) ;
if ( ! V_10 )
goto V_16;
V_10 -> V_17 = F_22 ( V_15 , L_1 ) ;
V_10 -> V_18 = F_22 ( V_15 , L_2 , V_19 ) ;
V_10 -> V_20 = F_22 ( V_15 , L_2 , V_21 ) ;
V_12 = F_23 ( V_10 ) ;
if ( F_24 ( V_12 ) ) {
F_25 ( V_10 -> V_17 ) ;
F_25 ( V_10 -> V_18 ) ;
F_25 ( V_10 -> V_20 ) ;
F_25 ( V_10 ) ;
goto V_16;
}
V_14 = F_26 ( V_12 ) ;
V_16:
F_27 ( NULL , V_22 , NULL , V_14 ) ;
}
static void T_1 F_28 ( void )
{
if ( F_29 ( V_23 ) )
F_30 () ;
}
static void T_1 F_31 ( void )
{
int V_24 ;
F_32 () ;
F_33 () ;
F_34 () ;
for ( V_24 = 0 ; V_24 < F_35 ( V_25 ) ; V_24 ++ ) {
if ( F_36 ( V_25 [ V_24 ] . V_26 ) ) {
V_25 [ V_24 ] . F_37 () ;
break;
}
}
}
