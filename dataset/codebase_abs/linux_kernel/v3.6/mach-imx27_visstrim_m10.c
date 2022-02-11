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
F_2 ( V_4 , 1 ) ;
F_4 ( 1 ) ;
F_2 ( V_5 , 0 ) ;
F_4 ( 500 ) ;
F_2 ( V_5 , 1 ) ;
F_4 ( 200000 ) ;
V_7 = F_6 ( & V_9 ) ;
if ( F_7 ( V_7 ) )
return;
V_8 = F_8 ( & V_7 -> V_2 ,
V_10 , V_10 ,
V_11 ,
V_12 | V_13 ) ;
if ( ! ( V_8 & V_12 ) )
return;
}
static void T_1 F_9 ( void )
{
V_10 = F_10 ( V_11 ,
V_11 ) ;
F_11 ( V_10 , V_11 ) ;
F_12 ( V_10 , V_11 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
T_2 V_14 , void * V_15 )
{
int V_16 ;
V_16 = F_14 ( F_15 ( V_17 ) , V_14 ,
V_18 , L_1 , V_15 ) ;
return V_16 ;
}
static void F_16 ( struct V_1 * V_2 , void * V_15 )
{
F_17 ( F_15 ( V_17 ) , V_15 ) ;
}
static int F_18 ( struct V_6 * V_7 )
{
return F_19 ( V_7 -> V_19 , V_20 ) ;
}
static void T_1 F_20 ( void )
{
int V_21 = 0 ;
int V_22 = 0 ;
int V_16 ;
V_16 = F_21 ( V_23 ,
F_22 ( V_23 ) ) ;
if ( V_16 ) {
F_23 ( L_2 ) ;
return;
}
V_21 |= ! F_24 ( V_24 ) << 2 ;
V_21 |= ! F_24 ( V_25 ) << 1 ;
V_21 |= ! F_24 ( V_26 ) ;
V_22 |= ! F_24 ( V_27 ) << 2 ;
V_22 |= ! F_24 ( V_28 ) << 1 ;
V_22 |= ! F_24 ( V_29 ) ;
V_30 = 0x27000 ;
V_30 |= ( V_22 << 4 ) ;
V_30 |= V_21 ;
}
static void T_1 F_25 ( void )
{
int V_16 ;
F_26 () ;
F_20 () ;
V_16 = F_27 ( V_31 ,
F_22 ( V_31 ) , L_3 ) ;
if ( V_16 )
F_23 ( L_4 , V_16 ) ;
V_16 = F_21 ( V_32 ,
F_22 ( V_32 ) ) ;
if ( V_16 )
F_23 ( L_5 , V_16 ) ;
F_28 ( 0 , & V_33 ) ;
F_29 ( & V_34 ) ;
F_30 ( 0 , & V_35 ) ;
F_30 ( 1 , & V_35 ) ;
F_31 ( 0 , V_36 ,
F_22 ( V_36 ) ) ;
F_32 ( 0 , & V_37 ) ;
F_33 ( & V_38 ) ;
F_34 ( NULL ) ;
F_35 ( & V_39 ) ;
F_36 ( V_40 , F_22 ( V_40 ) ) ;
F_37 ( L_6 , 0 , NULL , 0 , NULL , 0 ) ;
F_38 ( NULL , L_7 , 0 , NULL , 0 ,
& V_41 , sizeof( V_41 ) ) ;
F_39 ( 0 , & V_42 ) ;
F_5 () ;
}
static void T_1 F_40 ( void )
{
F_41 ( ( unsigned long ) 25000000 ) ;
}
