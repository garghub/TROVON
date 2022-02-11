static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
T_1 V_6 ;
F_3 ( V_4 -> V_7 ) ;
F_4 ( V_4 -> V_8 ) ;
F_5 ( & V_4 -> V_9 , V_5 ) ;
V_10 = V_11 + ( V_12 * V_13 ) ;
F_6 ( & V_4 -> V_14 , F_7 ( V_15 ) ) ;
V_6 = F_8 () ;
V_6 |= V_16 | V_15 ;
F_9 ( V_6 ) ;
F_10 ( 0 ) ;
V_6 = F_8 () ;
V_6 |= V_17 ;
V_6 &= ~ V_18 ;
F_9 ( V_6 ) ;
#ifdef F_11
V_6 = F_12 () ;
V_6 &= ~ V_19 ;
F_13 ( V_6 ) ;
#endif
F_14 ( & V_4 -> V_9 , V_5 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
T_1 V_6 ;
F_5 ( & V_4 -> V_9 , V_5 ) ;
F_16 ( & V_4 -> V_14 ) ;
V_6 = F_8 () ;
V_6 &= ~ V_17 ;
F_9 ( V_6 ) ;
F_14 ( & V_4 -> V_9 , V_5 ) ;
F_17 ( V_4 -> V_8 ) ;
F_18 ( V_4 -> V_7 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
F_5 ( & V_4 -> V_9 , V_5 ) ;
V_10 = V_11 + ( V_12 * V_13 ) ;
F_14 ( & V_4 -> V_9 , V_5 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , unsigned V_20 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
if ( F_21 ( V_20 < 1 || V_20 > 3600 ) )
return - V_21 ;
F_5 ( & V_4 -> V_9 , V_5 ) ;
V_12 = V_20 ;
V_2 -> V_22 = V_20 ;
F_14 ( & V_4 -> V_9 , V_5 ) ;
return 0 ;
}
static void F_22 ( unsigned long V_23 )
{
struct V_3 * V_4 = (struct V_3 * ) V_23 ;
unsigned long V_5 ;
F_5 ( & V_4 -> V_9 , V_5 ) ;
if ( F_23 ( V_11 , V_10 ) ) {
T_1 V_6 ;
V_6 = F_8 () ;
V_6 &= ~ V_24 ;
F_9 ( V_6 ) ;
F_10 ( 0 ) ;
F_6 ( & V_4 -> V_14 , F_7 ( V_15 ) ) ;
} else
F_24 ( V_4 -> V_7 , L_1
L_2 ) ;
F_14 ( & V_4 -> V_9 , V_5 ) ;
}
static int F_25 ( struct V_25 * V_26 )
{
struct V_3 * V_4 ;
struct V_27 * V_28 ;
int V_29 ;
if ( V_26 -> V_30 != - 1 )
return - V_21 ;
V_4 = F_26 ( & V_26 -> V_7 , sizeof( struct V_3 ) , V_31 ) ;
if ( F_21 ( ! V_4 ) )
return - V_32 ;
V_4 -> V_7 = & V_26 -> V_7 ;
V_4 -> V_8 = F_27 ( & V_26 -> V_7 , NULL ) ;
if ( F_28 ( V_4 -> V_8 ) ) {
V_4 -> V_8 = NULL ;
}
V_28 = F_29 ( V_26 , V_33 , 0 ) ;
V_4 -> V_34 = F_30 ( V_4 -> V_7 , V_28 ) ;
if ( F_28 ( V_4 -> V_34 ) )
return F_31 ( V_4 -> V_34 ) ;
F_32 ( & V_35 , V_36 ) ;
F_33 ( & V_35 , V_4 ) ;
V_35 . V_37 = & V_26 -> V_7 ;
F_34 ( & V_4 -> V_9 ) ;
V_29 = F_20 ( & V_35 , V_12 ) ;
if ( F_21 ( V_29 ) ) {
F_20 ( & V_35 , V_38 ) ;
F_24 ( & V_26 -> V_7 ,
L_3 ,
V_35 . V_22 ) ;
}
F_35 ( & V_26 -> V_7 , L_4 ,
V_35 . V_22 , V_36 ) ;
V_29 = F_36 ( & V_35 ) ;
if ( F_21 ( V_29 ) ) {
F_37 ( & V_26 -> V_7 , L_5 , V_29 ) ;
return V_29 ;
}
F_38 ( & V_4 -> V_14 , F_22 , ( unsigned long ) V_4 ) ;
V_4 -> V_14 . V_39 = F_7 ( V_15 ) ;
F_35 ( & V_26 -> V_7 , L_6 ) ;
F_39 ( & V_26 -> V_7 ) ;
return 0 ;
}
static int F_40 ( struct V_25 * V_26 )
{
F_41 ( & V_35 ) ;
F_42 ( & V_26 -> V_7 ) ;
return 0 ;
}
static void F_43 ( struct V_25 * V_26 )
{
F_15 ( & V_35 ) ;
}
static int T_2 F_44 ( void )
{
if ( F_21 ( V_15 < 0x5 ||
V_15 > 0x7 ) ) {
V_15 = V_40 ;
F_45 ( L_7 ,
V_15 ) ;
}
return F_46 ( & V_41 ) ;
}
static void T_3 F_47 ( void )
{
F_48 ( & V_41 ) ;
}
