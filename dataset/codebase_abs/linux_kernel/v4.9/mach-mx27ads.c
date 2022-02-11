static void F_1 ( struct V_1 * V_2 , unsigned V_3 , int V_4 )
{
if ( V_4 )
F_2 ( V_5 , V_6 ) ;
else
F_2 ( V_5 , V_7 ) ;
}
static int F_3 ( struct V_1 * V_2 , unsigned V_3 , int V_4 )
{
return 0 ;
}
static void T_1 F_4 ( void )
{
struct V_1 * V_8 ;
V_8 = F_5 ( sizeof( * V_8 ) , V_9 ) ;
V_8 -> V_10 = V_11 ;
V_8 -> V_12 = L_1 ;
V_8 -> V_13 = V_14 ;
V_8 -> V_15 = 1 ;
V_8 -> V_16 = F_3 ;
V_8 -> V_17 = F_1 ;
F_6 ( V_8 , NULL ) ;
F_7 ( NULL , L_2 ,
V_18 ,
& V_19 ,
sizeof( V_19 ) ) ;
}
static int F_8 ( struct V_20 * V_21 , T_2 V_22 ,
void * V_23 )
{
return F_9 ( F_10 ( F_11 ( 5 , 21 ) ) , V_22 ,
V_24 , L_3 , V_23 ) ;
}
static int F_12 ( struct V_20 * V_21 , T_2 V_22 ,
void * V_23 )
{
return F_9 ( F_10 ( F_11 ( 2 , 7 ) ) , V_22 ,
V_24 , L_4 , V_23 ) ;
}
static void F_13 ( struct V_20 * V_21 , void * V_23 )
{
F_14 ( F_10 ( F_11 ( 5 , 21 ) ) , V_23 ) ;
}
static void F_15 ( struct V_20 * V_21 , void * V_23 )
{
F_14 ( F_10 ( F_11 ( 2 , 7 ) ) , V_23 ) ;
}
static void T_1 F_16 ( void )
{
F_17 () ;
F_18 ( V_25 , F_19 ( V_25 ) ,
L_5 ) ;
F_20 ( & V_26 ) ;
F_21 ( & V_26 ) ;
F_22 ( & V_26 ) ;
F_23 ( & V_26 ) ;
F_24 ( & V_26 ) ;
F_25 ( & V_26 ) ;
F_26 ( & V_27 ) ;
F_27 ( 1 , V_28 ,
F_19 ( V_28 ) ) ;
F_28 ( 1 , & V_29 ) ;
F_29 ( & V_30 ) ;
F_30 ( NULL ) ;
F_31 () ;
}
static void T_1 F_32 ( void )
{
F_4 () ;
F_33 ( 0 , & V_31 ) ;
F_33 ( 1 , & V_32 ) ;
F_34 ( V_33 , F_19 ( V_33 ) ) ;
}
static void T_1 F_35 ( void )
{
unsigned long V_34 = 26000000 ;
if ( ( F_36 ( V_35 ) & V_36 ) == 0 )
V_34 = 27000000 ;
F_37 ( V_34 ) ;
}
static void T_1 F_38 ( void )
{
F_39 () ;
F_40 ( V_37 , F_19 ( V_37 ) ) ;
}
