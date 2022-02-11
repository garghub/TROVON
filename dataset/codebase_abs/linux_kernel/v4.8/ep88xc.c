static void T_1 F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_2 ) ; V_1 ++ ) {
struct V_3 * V_4 = & V_2 [ V_1 ] ;
F_3 ( V_4 -> V_5 , V_4 -> V_4 , V_4 -> V_6 ) ;
}
F_4 ( V_7 , V_8 , V_9 ) ;
F_4 ( V_10 , V_11 , V_12 ) ;
F_4 ( V_10 , V_11 , V_13 ) ;
F_4 ( V_14 , V_15 , V_12 ) ;
F_4 ( V_14 , V_15 , V_13 ) ;
}
static void T_1 F_5 ( void )
{
struct V_16 * V_17 ;
F_6 () ;
F_1 () ;
V_17 = F_7 ( NULL , NULL , L_1 ) ;
if ( ! V_17 ) {
F_8 ( V_18 L_2 ) ;
return;
}
V_19 = F_9 ( V_17 , 0 ) ;
F_10 ( V_17 ) ;
if ( ! V_19 ) {
F_8 ( V_18 L_3 ) ;
return;
}
F_11 ( & V_19 [ 7 ] , V_20 ) ;
F_11 ( & V_19 [ 8 ] , V_21 | V_22 |
V_23 | V_24 ) ;
}
static int T_1 F_12 ( void )
{
return F_13 ( L_4 ) ;
}
static int T_1 F_14 ( void )
{
F_15 ( NULL , V_25 , NULL ) ;
return 0 ;
}
