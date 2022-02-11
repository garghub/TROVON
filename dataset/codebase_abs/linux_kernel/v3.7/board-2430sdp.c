static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , 1 ) ;
F_2 ( V_4 , 1 ) ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_3 , 0 ) ;
F_2 ( V_4 , 0 ) ;
}
static void T_1 F_4 ( void )
{
int V_5 ;
static struct V_6 V_7 [] V_8 = {
{ V_3 , V_9 ,
L_1 } ,
{ V_4 , V_9 ,
L_2 } ,
} ;
V_5 = F_5 ( V_7 , F_6 ( V_7 ) ) ;
if ( V_5 ) {
F_7 ( L_3 , V_5 ) ;
return;
}
F_8 ( & V_10 ) ;
}
static void T_1 F_9 ( void )
{
F_10 ( 149 , V_11 ) ;
F_11 ( & V_12 ) ;
}
static inline void F_9 ( void )
{
}
static int T_1 F_12 ( void )
{
V_13 [ 0 ] . V_14 = F_13 ( 78 ) ;
F_14 ( 1 , 100 , V_13 ,
F_6 ( V_13 ) ) ;
F_15 ( 2 , 100 , L_4 , 7 + V_15 ,
& V_16 ) ;
return 0 ;
}
static void T_1 F_16 ( void )
{
F_17 ( V_17 , V_18 ) ;
F_12 () ;
F_18 ( V_19 , F_6 ( V_19 ) ) ;
F_19 () ;
F_20 ( NULL , NULL ) ;
F_21 ( V_20 ) ;
F_22 ( L_5 , V_21 | V_22 ) ;
F_23 ( NULL ) ;
F_9 () ;
F_24 ( V_23 , V_9 ,
L_6 ) ;
F_4 () ;
}
