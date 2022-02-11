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
F_2 ( V_4 , 1 ) ;
F_4 ( 1 ) ;
F_2 ( V_5 , 0 ) ;
F_4 ( 500 ) ;
F_2 ( V_5 , 1 ) ;
F_4 ( 200000 ) ;
V_7 = F_6 ( & V_8 ) ;
if ( F_7 ( V_7 ) )
return;
F_8 ( & V_7 -> V_2 , V_9 ,
V_9 , V_10 ,
V_11 ) ;
}
static void T_1 F_9 ( void )
{
V_9 = F_10 ( 3 * V_10 ,
V_10 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
T_2 V_12 , void * V_13 )
{
int V_14 ;
V_14 = F_12 ( F_13 ( V_15 ) , V_12 ,
V_16 , L_1 , V_13 ) ;
return V_14 ;
}
static void F_14 ( struct V_1 * V_2 , void * V_13 )
{
F_15 ( F_13 ( V_15 ) , V_13 ) ;
}
static int F_16 ( struct V_6 * V_7 )
{
return F_17 ( V_7 -> V_17 , V_18 ) ;
}
static void T_1 F_18 ( void )
{
struct V_6 * V_7 ;
V_7 = F_19 () ;
F_8 ( & V_7 -> V_2 ,
V_9 + V_10 ,
V_9 + V_10 ,
V_10 ,
V_11 ) ;
}
static void T_1 F_20 ( void )
{
int V_14 = - V_19 ;
struct V_6 * V_7 = & V_20 ;
V_14 = F_21 ( V_7 ) ;
F_8 ( & V_7 -> V_2 ,
V_9 + 2 * V_10 ,
V_9 + 2 * V_10 ,
V_10 ,
V_11 ) ;
}
static void T_1 F_22 ( void )
{
struct V_6 * V_7 ;
int V_14 ;
V_7 = F_23 () ;
if ( F_7 ( V_7 ) )
return;
V_14 = F_8 ( & V_7 -> V_2 ,
V_9 , V_9 ,
V_10 ,
V_11 ) ;
if ( V_14 )
F_24 ( L_2 ) ;
}
static void T_1 F_25 ( void )
{
int V_21 = 0 ;
int V_22 = 0 ;
int V_14 ;
V_14 = F_26 ( V_23 ,
F_27 ( V_23 ) ) ;
if ( V_14 ) {
F_24 ( L_3 ) ;
return;
}
V_21 |= ! F_28 ( V_24 ) << 2 ;
V_21 |= ! F_28 ( V_25 ) << 1 ;
V_21 |= ! F_28 ( V_26 ) ;
V_22 |= ! F_28 ( V_27 ) << 2 ;
V_22 |= ! F_28 ( V_28 ) << 1 ;
V_22 |= ! F_28 ( V_29 ) ;
V_30 = 0x27000 ;
V_30 |= ( V_22 << V_31 ) ;
V_30 |= ( V_21 << V_32 ) ;
}
static void T_1 F_29 ( void )
{
int V_14 ;
F_30 () ;
F_25 () ;
V_14 = F_31 ( V_33 ,
F_27 ( V_33 ) , L_4 ) ;
if ( V_14 )
F_24 ( L_5 , V_14 ) ;
F_32 ( 0 , & V_34 ) ;
F_33 ( & V_35 ) ;
F_34 ( 0 , & V_36 ) ;
F_34 ( 1 , & V_36 ) ;
F_35 ( 0 , V_37 ,
F_27 ( V_37 ) ) ;
F_36 ( 0 , & V_38 ) ;
F_37 ( & V_39 ) ;
F_38 ( NULL ) ;
F_39 ( V_40 , F_27 ( V_40 ) ) ;
}
static void T_1 F_40 ( void )
{
int V_22 , V_14 ;
V_14 = F_26 ( V_41 ,
F_27 ( V_41 ) ) ;
if ( V_14 )
F_24 ( L_6 , V_14 ) ;
F_41 ( & V_42 ) ;
F_42 ( L_7 , 0 , NULL , 0 , & V_43 ,
sizeof( V_43 ) ) ;
F_43 ( NULL , L_8 , 0 , NULL , 0 ,
& V_44 , sizeof( V_44 ) ) ;
F_44 ( 0 , & V_45 ) ;
V_22 = ( V_30 >> V_31 ) & V_46 ;
if ( V_22 & 0x1 ) {
F_22 () ;
F_2 ( V_4 , 1 ) ;
F_4 ( 1 ) ;
F_2 ( V_5 , 0 ) ;
} else {
F_20 () ;
F_5 () ;
}
F_18 () ;
}
static void T_1 F_45 ( void )
{
F_46 ( ( unsigned long ) 25000000 ) ;
}
