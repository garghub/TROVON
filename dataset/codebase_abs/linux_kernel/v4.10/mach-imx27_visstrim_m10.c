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
V_10 = F_10 ( 3 * V_11 ,
V_11 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
T_2 V_14 , void * V_15 )
{
int V_16 ;
V_16 = F_12 ( F_13 ( V_17 ) , V_14 ,
V_18 , L_1 , V_15 ) ;
return V_16 ;
}
static void F_14 ( struct V_1 * V_2 , void * V_15 )
{
F_15 ( F_13 ( V_17 ) , V_15 ) ;
}
static int F_16 ( struct V_6 * V_7 )
{
return F_17 ( V_7 -> V_19 , V_20 ) ;
}
static void T_1 F_18 ( void )
{
struct V_6 * V_7 ;
int V_8 ;
V_7 = F_19 () ;
V_8 = F_8 ( & V_7 -> V_2 ,
V_10 + V_11 ,
V_10 + V_11 ,
V_11 ,
V_12 | V_13 ) ;
if ( ! ( V_8 & V_12 ) )
return;
}
static void T_1 F_20 ( void )
{
int V_16 = - V_21 ;
struct V_6 * V_7 = & V_22 ;
int V_8 ;
V_16 = F_21 ( V_7 ) ;
V_8 = F_8 ( & V_7 -> V_2 ,
V_10 + 2 * V_11 ,
V_10 + 2 * V_11 ,
V_11 ,
V_12 | V_13 ) ;
if ( ! ( V_8 & V_12 ) )
return;
}
static void T_1 F_22 ( void )
{
struct V_6 * V_7 ;
int V_8 ;
V_7 = F_23 () ;
if ( F_7 ( V_7 ) )
return;
V_8 = F_8 ( & V_7 -> V_2 ,
V_10 , V_10 ,
V_11 ,
V_12 | V_13 ) ;
if ( ! ( V_8 & V_12 ) )
F_24 ( L_2 ) ;
}
static void T_1 F_25 ( void )
{
int V_23 = 0 ;
int V_24 = 0 ;
int V_16 ;
V_16 = F_26 ( V_25 ,
F_27 ( V_25 ) ) ;
if ( V_16 ) {
F_24 ( L_3 ) ;
return;
}
V_23 |= ! F_28 ( V_26 ) << 2 ;
V_23 |= ! F_28 ( V_27 ) << 1 ;
V_23 |= ! F_28 ( V_28 ) ;
V_24 |= ! F_28 ( V_29 ) << 2 ;
V_24 |= ! F_28 ( V_30 ) << 1 ;
V_24 |= ! F_28 ( V_31 ) ;
V_32 = 0x27000 ;
V_32 |= ( V_24 << V_33 ) ;
V_32 |= ( V_23 << V_34 ) ;
}
static void T_1 F_29 ( void )
{
int V_16 ;
F_30 () ;
F_25 () ;
V_16 = F_31 ( V_35 ,
F_27 ( V_35 ) , L_4 ) ;
if ( V_16 )
F_24 ( L_5 , V_16 ) ;
F_32 ( 0 , & V_36 ) ;
F_33 ( & V_37 ) ;
F_34 ( 0 , & V_38 ) ;
F_34 ( 1 , & V_38 ) ;
F_35 ( 0 , V_39 ,
F_27 ( V_39 ) ) ;
F_36 ( 0 , & V_40 ) ;
F_37 ( & V_41 ) ;
F_38 ( NULL ) ;
F_39 ( V_42 , F_27 ( V_42 ) ) ;
}
static void T_1 F_40 ( void )
{
int V_24 , V_16 ;
V_16 = F_26 ( V_43 ,
F_27 ( V_43 ) ) ;
if ( V_16 )
F_24 ( L_6 , V_16 ) ;
F_41 ( & V_44 ) ;
F_42 ( L_7 , 0 , NULL , 0 , & V_45 ,
sizeof( V_45 ) ) ;
F_43 ( NULL , L_8 , 0 , NULL , 0 ,
& V_46 , sizeof( V_46 ) ) ;
F_44 ( 0 , & V_47 ) ;
V_24 = ( V_32 >> V_33 ) & V_48 ;
if ( V_24 & 0x1 ) {
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
