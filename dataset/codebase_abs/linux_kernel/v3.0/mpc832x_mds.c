static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
T_2 T_3 * V_3 = NULL ;
if ( V_4 . V_5 )
V_4 . V_5 ( L_1 , 0 ) ;
V_2 = F_2 ( NULL , L_2 ) ;
if ( V_2 ) {
struct V_6 V_7 ;
F_3 ( V_2 , 0 , & V_7 ) ;
V_3 = F_4 ( V_7 . V_8 , V_7 . V_9 - V_7 . V_8 + 1 ) ;
F_5 ( V_2 ) ;
}
#ifdef F_6
F_7 (np, L_3 , L_4 )
F_8 ( V_2 ) ;
#endif
#ifdef F_9
F_10 () ;
if ( ( V_2 = F_2 ( NULL , L_5 ) ) != NULL ) {
F_11 ( V_2 ) ;
F_5 ( V_2 ) ;
for ( V_2 = NULL ; ( V_2 = F_2 ( V_2 , L_6 ) ) != NULL ; )
F_12 ( V_2 ) ;
}
if ( ( V_2 = F_13 ( NULL , L_7 , L_8 ) )
!= NULL ) {
#define F_14 0x50
F_15 ( & V_3 [ 8 ] , F_14 ) ;
F_16 ( 1000 ) ;
F_17 ( & V_3 [ 8 ] , F_14 ) ;
F_18 ( V_3 ) ;
F_5 ( V_2 ) ;
}
#endif
}
static int T_1 F_19 ( void )
{
F_20 ( NULL , V_10 , NULL ) ;
return 0 ;
}
static void T_1 F_21 ( void )
{
struct V_1 * V_2 ;
V_2 = F_22 ( NULL , L_9 ) ;
if ( ! V_2 )
return;
F_23 ( V_2 , 0 ) ;
F_24 () ;
F_5 ( V_2 ) ;
#ifdef F_9
V_2 = F_13 ( NULL , NULL , L_10 ) ;
if ( ! V_2 ) {
V_2 = F_22 ( NULL , L_11 ) ;
if ( ! V_2 )
return;
}
F_25 ( V_2 , 0 , V_11 , V_12 ) ;
F_5 ( V_2 ) ;
#endif
}
static int T_1 F_26 ( void )
{
unsigned long V_13 = F_27 () ;
return F_28 ( V_13 , L_12 ) ;
}
