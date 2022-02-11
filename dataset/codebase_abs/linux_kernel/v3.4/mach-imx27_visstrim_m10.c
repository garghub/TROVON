static int F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_4 , V_3 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
F_2 ( V_5 , 0 ) ;
F_4 ( 500 ) ;
F_2 ( V_5 , 1 ) ;
return 0 ;
}
static void T_1 F_5 ( void )
{
struct V_6 * V_7 ;
int V_8 ;
F_6 ( V_5 | V_9 | V_10 ) ;
F_6 ( V_4 | V_9 | V_10 ) ;
F_2 ( V_5 , 1 ) ;
F_2 ( V_4 , 0 ) ;
F_4 ( 1 ) ;
F_2 ( V_4 , 1 ) ;
F_4 ( 1 ) ;
F_2 ( V_5 , 0 ) ;
F_4 ( 500 ) ;
F_2 ( V_5 , 1 ) ;
F_4 ( 200000 ) ;
V_7 = F_7 ( & V_11 ) ;
if ( F_8 ( V_7 ) )
return;
V_8 = F_9 ( & V_7 -> V_2 ,
V_12 , V_12 ,
V_13 ,
V_14 | V_15 ) ;
if ( ! ( V_8 & V_14 ) )
return;
}
static void T_1 F_10 ( void )
{
V_12 = F_11 ( V_13 ,
V_13 ) ;
F_12 ( V_12 , V_13 ) ;
F_13 ( V_12 , V_13 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
T_2 V_16 , void * V_17 )
{
int V_18 ;
V_18 = F_15 ( V_19 , V_16 , V_20 ,
L_1 , V_17 ) ;
return V_18 ;
}
static void F_16 ( struct V_1 * V_2 , void * V_17 )
{
F_17 ( V_19 , V_17 ) ;
}
static int F_18 ( struct V_6 * V_7 )
{
F_2 ( V_21 , 0 ) ;
F_19 ( 10 ) ;
return F_20 ( V_7 -> V_22 , V_23 ) ;
}
static void T_1 F_21 ( void )
{
int V_18 ;
F_22 () ;
V_18 = F_23 ( V_24 ,
F_24 ( V_24 ) , L_2 ) ;
if ( V_18 )
F_25 ( L_3 , V_18 ) ;
F_26 ( 0 , & V_25 ) ;
F_27 ( & V_26 ) ;
F_28 ( 0 , & V_27 ) ;
F_28 ( 1 , & V_27 ) ;
F_29 ( 0 , V_28 ,
F_24 ( V_28 ) ) ;
F_30 ( 0 , & V_29 ) ;
F_31 ( & V_30 ) ;
F_32 ( NULL ) ;
F_33 ( & V_31 ) ;
F_34 ( V_32 , F_24 ( V_32 ) ) ;
F_35 ( L_4 , 0 , NULL , 0 , NULL , 0 ) ;
F_36 ( NULL , L_5 , 0 , NULL , 0 ,
& V_33 , sizeof( V_33 ) ) ;
F_37 ( 0 , & V_34 ) ;
F_5 () ;
}
static void T_1 F_38 ( void )
{
F_39 ( ( unsigned long ) 25000000 ) ;
}
