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
V_13 . V_14 = V_3 + 7 ;
V_13 . V_15 = V_3 + 15 ;
return 0 ;
}
static int T_1 F_9 ( void )
{
F_10 ( & V_16 ,
V_17 | V_18 , 0 ) ;
F_11 ( L_4 , & V_16 ) ;
F_12 ( 2 , 400 , NULL , 0 ) ;
F_12 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void T_1 F_13 ( void )
{
F_14 ( 0 , V_19 , F_5 ( V_19 ) ) ;
F_15 ( V_20 , V_21 ) ;
F_1 () ;
F_9 () ;
F_16 ( V_22 , F_5 ( V_22 ) ) ;
F_17 ( 1 , 54 , 310 , NULL ) ;
F_18 () ;
F_19 ( NULL , NULL ) ;
F_20 ( L_5 , 0 , L_6 ) ;
F_21 ( NULL ) ;
F_22 ( V_23 , F_5 ( V_23 ) ,
V_24 , 0 , V_25 ) ;
F_23 ( V_26 ) ;
F_3 () ;
}
