static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
if ( V_3 . V_4 )
V_3 . V_4 ( L_1 , 0 ) ;
V_2 = F_2 ( NULL , L_2 ) ;
if ( V_2 != NULL ) {
static T_2 T_3 * V_5 ;
V_5 = F_3 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
if ( ! V_5 ) {
F_5 ( V_6
L_3 ) ;
return;
} else {
#define F_6 0x07
#define F_7 0x02
#ifdef F_8
F_9 ( & V_5 [ 15 ] , F_6 ) ;
F_10 ( & V_5 [ 15 ] , F_7 ) ;
#endif
F_11 ( V_5 ) ;
}
}
#ifdef F_12
F_13 (np, L_4 , L_5 )
F_14 ( V_2 , 0 ) ;
#endif
#ifdef F_15
F_16 () ;
#endif
}
static int T_1 F_17 ( void )
{
F_18 ( NULL , V_7 , NULL ) ;
return 0 ;
}
static void T_1 F_19 ( void )
{
struct V_8 * V_8 ;
struct V_9 V_10 ;
struct V_1 * V_2 = NULL ;
V_2 = F_20 ( NULL , L_6 ) ;
if ( ! V_2 ) {
F_5 ( V_6 L_7 ) ;
return;
}
if ( F_21 ( V_2 , 0 , & V_10 ) ) {
F_5 ( V_6 L_8 ) ;
F_4 ( V_2 ) ;
return;
}
V_8 = F_22 ( V_2 , V_10 . V_11 ,
V_12 | V_13 | V_14 |
V_15 | V_16 ,
0 , 256 , L_9 ) ;
F_23 ( V_8 == NULL ) ;
F_4 ( V_2 ) ;
F_24 ( V_8 ) ;
}
static int T_1 F_25 ( void )
{
unsigned long V_17 = F_26 () ;
return F_27 ( V_17 , L_10 ) ;
}
