static void F_1 ( struct V_1 * V_2 , int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_8 ;
if ( V_3 == V_9 )
return;
V_8 = ( V_4 & V_10 ) ? 0x02 : 0 ;
if ( V_4 & V_11 )
V_8 |= 0x04 ;
F_2 ( V_3 , ( unsigned long ) V_6 -> V_12 | V_8 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_13 ) ;
}
static void T_1 F_5 ( void )
{
F_6 ( 1 , V_14 ) ;
F_7 ( 50 ) ;
F_6 ( F_8 ( V_14 ) & ~ 1 ,
V_14 ) ;
F_7 ( 50 ) ;
}
static void T_1 F_9 ( void )
{
F_10 ( F_11 ( V_15 ) & ~ 1 , V_15 ) ;
F_12 ( 0x0000fff3 , V_16 ) ;
F_12 ( 0x00000088 , V_17 ) ;
F_12 ( 0x0000fff3 , V_18 ) ;
F_12 ( 0x00000000 , V_19 ) ;
F_12 ( F_13 ( V_20 ) & 0x1FFFFFFF ,
V_20 ) ;
F_5 () ;
if ( F_14 ( V_13 , L_1 ) < 0 )
F_15 () ;
F_16 ( V_13 ) ;
F_17 ( V_21 ) ;
F_17 ( V_22 ) ;
F_17 ( V_23 ) ;
F_17 ( V_24 ) ;
F_17 ( V_25 ) ;
F_17 ( V_26 ) ;
F_17 ( V_27 ) ;
F_17 ( V_28 ) ;
F_17 ( V_29 ) ;
F_17 ( V_30 ) ;
F_17 ( V_31 ) ;
F_17 ( V_32 ) ;
F_18 ( V_33 , F_19 ( V_33 ) ) ;
V_34 = V_35 ;
V_36 = F_19 ( V_35 ) ;
F_20 () ;
F_21 ( 1 , 100 , NULL , 0 ) ;
}
static void T_1 F_22 ( void )
{
F_23 () ;
F_24 ( V_37 ,
F_19 ( V_37 ) ) ;
}
