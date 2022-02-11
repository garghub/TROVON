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
if ( F_6 ( 0 , L_1 ) < 0 ) {
F_7 ( L_2 ) ;
return;
}
}
static int F_8 ( struct V_14 * V_15 , void * V_16 )
{
F_9 ( V_17 | V_18 |
V_19 | V_20 ) ;
return 0 ;
}
static void T_1 F_10 ( void )
{
F_5 () ;
V_21 . V_22 = V_21 . V_23 = F_11 () ;
V_21 . V_22 += V_24 - 1 ;
V_25 . V_22 = V_25 . V_23 = V_26 ;
V_25 . V_22 += V_27 - 1 ;
if ( F_6 ( V_13 , L_3 ) < 0 )
F_12 () ;
F_13 ( V_13 ) ;
F_14 ( V_28 ) ;
F_14 ( V_29 ) ;
F_14 ( V_30 ) ;
F_14 ( V_31 ) ;
F_14 ( V_32 ) ;
F_14 ( V_33 ) ;
F_14 ( V_34 ) ;
F_14 ( V_35 ) ;
F_14 ( V_36 ) ;
F_14 ( V_37 ) ;
F_14 ( V_38 ) ;
F_14 ( V_39 ) ;
F_14 ( V_40 ) ;
F_14 ( V_41 ) ;
F_15 ( V_42 , F_16 ( V_42 ) ) ;
V_43 = V_44 ;
V_45 = F_16 ( V_44 ) ;
F_17 () ;
F_18 ( 1 , 100 , V_46 ,
F_16 ( V_46 ) ) ;
F_19 ( & V_47 ) ;
F_20 () ;
}
