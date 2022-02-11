static void T_1 F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_2 ) ; V_1 ++ ) {
struct V_3 * V_4 = & V_2 [ V_1 ] ;
F_3 ( V_4 -> V_5 , V_4 -> V_4 , V_4 -> V_6 ) ;
}
F_4 ( V_7 , V_8 , V_9 ) ;
F_4 ( V_10 , V_11 , V_9 ) ;
F_4 ( V_12 , V_13 , V_14 ) ;
F_4 ( V_12 , V_15 , V_16 ) ;
F_5 ( & V_17 -> V_18 . V_19 , 0x00000180 ) ;
}
static void T_1 F_6 ( void )
{
struct V_20 * V_21 ;
F_7 () ;
F_1 () ;
V_21 = F_8 ( NULL , NULL , L_1 ) ;
if ( ! V_21 ) {
F_9 ( V_22 L_2 ) ;
return;
}
V_23 = F_10 ( V_21 , 0 ) ;
V_24 = F_10 ( V_21 , 1 ) ;
F_11 ( V_21 ) ;
if ( ! V_23 || ! V_24 ) {
F_9 ( V_22 L_3 ) ;
return;
}
F_5 ( & V_23 [ 1 ] , V_25 ) ;
#ifdef F_12
F_13 ( & V_23 [ 1 ] , V_26 ) ;
#else
F_5 ( & V_23 [ 1 ] , V_26 ) ;
#endif
F_5 ( V_24 , V_27 ) ;
F_13 ( V_24 , V_28 ) ;
F_14 ( 1000 ) ;
F_5 ( V_24 , V_28 ) ;
#ifdef F_12
F_5 ( V_24 , V_29 ) ;
F_13 ( V_24 , V_30 ) ;
F_14 ( 1000 ) ;
F_5 ( V_24 , V_30 ) ;
#else
F_13 ( V_24 , V_29 ) ;
#endif
#ifdef F_15
F_5 ( & V_23 [ 4 ] , V_31 ) ;
F_14 ( 1000 ) ;
F_13 ( & V_23 [ 4 ] , V_31 ) ;
F_13 ( & V_23 [ 1 ] , V_32 ) ;
V_21 = F_16 ( L_4 ) ;
#else
V_21 = F_16 ( L_5 ) ;
#endif
if ( V_21 ) {
F_17 ( V_21 ) ;
F_11 ( V_21 ) ;
}
}
static int T_1 F_18 ( void )
{
unsigned long V_33 = F_19 () ;
return F_20 ( V_33 , L_6 ) ;
}
static int T_1 F_21 ( void )
{
F_22 ( NULL , V_34 , NULL ) ;
return 0 ;
}
