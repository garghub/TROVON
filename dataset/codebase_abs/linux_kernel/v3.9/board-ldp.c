static inline void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
if ( F_4 ( V_4 ) )
F_5 ( V_4 , 1 ) ;
if ( F_4 ( V_5 ) )
F_5 ( V_5 , 1 ) ;
return 0 ;
}
static void F_6 ( struct V_2 * V_3 )
{
if ( F_4 ( V_4 ) )
F_5 ( V_4 , 0 ) ;
if ( F_4 ( V_5 ) )
F_5 ( V_5 , 0 ) ;
}
static void T_1 F_7 ( void )
{
int V_6 ;
static struct V_7 V_8 [] V_9 = {
{ V_10 , V_11 , L_1 } ,
{ V_12 , V_11 , L_2 } ,
} ;
V_6 = F_8 ( V_8 , F_9 ( V_8 ) ) ;
if ( V_6 ) {
F_10 ( L_3 , V_6 ) ;
return;
}
F_11 ( & V_13 ) ;
}
static int F_12 ( struct V_14 * V_15 , unsigned V_7 , unsigned V_16 )
{
int V_6 ;
struct V_7 V_8 [] = {
{ V_7 + 7 , V_17 , L_4 } ,
{ V_7 + 15 , V_17 , L_5 } ,
} ;
V_6 = F_8 ( V_8 , F_9 ( V_8 ) ) ;
if ( V_6 ) {
F_10 ( L_3 , V_6 ) ;
V_5 = - V_18 ;
V_4 = - V_18 ;
return V_6 ;
}
V_5 = V_7 + 15 ;
V_4 = V_7 + 7 ;
return 0 ;
}
static int T_1 F_13 ( void )
{
F_14 ( & V_19 ,
V_20 | V_21 , 0 ) ;
F_15 ( L_6 , & V_19 ) ;
F_16 ( 2 , 400 , NULL , 0 ) ;
F_16 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void T_1 F_17 ( void )
{
F_18 ( 0 , V_22 , F_9 ( V_22 ) ) ;
F_19 ( V_23 , V_24 ) ;
F_1 () ;
F_13 () ;
F_20 ( V_25 , F_9 ( V_25 ) ) ;
F_21 ( 1 , 54 , 310 , NULL ) ;
F_22 () ;
F_23 ( NULL , NULL ) ;
F_24 ( L_7 , 0 , L_8 ) ;
F_25 ( NULL ) ;
F_26 ( V_26 , F_9 ( V_26 ) ,
V_27 , 0 , V_28 ) ;
F_27 ( V_29 ) ;
F_7 () ;
}
