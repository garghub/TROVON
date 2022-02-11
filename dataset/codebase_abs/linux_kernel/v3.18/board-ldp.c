static inline void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static void T_1 F_3 ( void )
{
int V_2 ;
static struct V_3 V_4 [] V_5 = {
{ V_6 , V_7 , L_1 } ,
{ V_8 , V_7 , L_2 } ,
} ;
V_2 = F_4 ( V_4 , F_5 ( V_4 ) ) ;
if ( V_2 ) {
F_6 ( L_3 , V_2 ) ;
return;
}
F_7 ( & V_9 ) ;
}
static int F_8 ( struct V_10 * V_11 , unsigned V_3 , unsigned V_12 )
{
int V_13 ;
V_14 . V_15 = V_3 + 7 ;
V_14 . V_16 = V_3 + 15 ;
V_13 = F_9 ( & V_17 ) ;
if ( V_13 )
F_6 ( L_4 , V_13 ) ;
return 0 ;
}
static int T_1 F_10 ( void )
{
F_11 ( & V_18 ,
V_19 | V_20 , 0 ) ;
F_12 ( L_5 , & V_18 ) ;
F_13 ( 2 , 400 , NULL , 0 ) ;
F_13 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void T_1 F_14 ( void )
{
F_15 ( 0 , V_21 , F_5 ( V_21 ) ) ;
F_16 ( V_22 , V_23 ) ;
F_1 () ;
F_10 () ;
F_17 ( V_24 , F_5 ( V_24 ) ) ;
F_18 ( 1 , 54 , 310 , NULL ) ;
F_19 () ;
F_20 ( NULL , NULL ) ;
F_21 ( L_6 , 0 , L_7 ) ;
F_22 ( NULL ) ;
F_23 ( V_25 , F_5 ( V_25 ) ,
0 , 0 , V_26 ) ;
F_24 ( V_27 ) ;
F_3 () ;
}
