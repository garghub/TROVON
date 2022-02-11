static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! F_2 ( V_4 ) )
F_3 ( V_2 , L_1 ) ;
F_3 ( V_2 , L_2 ) ;
return 0 ;
}
static void F_4 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_5 ( V_6 ) ;
if ( V_4 -> V_7 == V_8 &&
( V_4 -> V_5 == V_9 ||
V_4 -> V_5 == V_10 ) ) {
if ( V_4 -> V_5 == V_9 &&
V_4 -> V_11 == 0x0 ) {
V_2 -> V_12 |= V_13 ;
F_6 ( V_2 , V_14 ,
L_3
L_4 ) ;
}
if ( V_4 -> V_5 == V_9 &&
V_4 -> V_11 == 0x4 ) {
V_2 -> V_12 |= V_15 ;
F_6 ( V_2 , V_14 ,
L_5
L_6 ,
V_4 -> V_11 ) ;
}
if ( V_4 -> V_5 == V_9 )
V_2 -> V_12 |= V_16 ;
V_2 -> V_12 |= V_17 ;
F_6 ( V_2 , V_14 ,
L_7
L_8 ,
V_4 -> V_11 ) ;
V_2 -> V_12 |= V_18 ;
}
if ( V_4 -> V_7 == V_19 )
V_2 -> V_12 |= V_20 ;
if ( V_4 -> V_7 == V_21 && V_2 -> V_22 == 0x96 )
V_2 -> V_12 |= V_23 ;
if ( V_4 -> V_7 == V_21 && F_7 () )
V_2 -> V_12 |= V_24 ;
if ( V_4 -> V_7 == V_21 )
V_2 -> V_12 |= V_18 ;
if ( V_4 -> V_7 == V_25 ) {
V_2 -> V_12 |= V_26 ;
V_2 -> V_12 |= V_27 ;
V_2 -> V_12 |= V_28 ;
}
if ( V_4 -> V_7 == V_25 &&
V_4 -> V_5 == V_29 ) {
V_2 -> V_12 |= V_30 ;
V_2 -> V_31 = 64 ;
V_2 -> V_12 |= V_32 ;
V_2 -> V_12 |= V_33 ;
}
if ( V_4 -> V_7 == V_25 &&
V_4 -> V_5 == V_34 ) {
V_2 -> V_12 |= V_33 ;
}
if ( V_4 -> V_7 == V_25 &&
( V_4 -> V_5 == V_35 ||
V_4 -> V_5 == V_36 ||
V_4 -> V_5 == V_37 ) ) {
V_2 -> V_12 |= V_38 ;
}
if ( V_4 -> V_7 == V_39 &&
V_4 -> V_5 == V_40 ) {
V_2 -> V_12 |= V_41 ;
V_2 -> V_12 |= V_18 ;
V_2 -> V_12 |= V_16 ;
}
if ( V_4 -> V_7 == V_42 &&
V_4 -> V_5 == 0x0015 )
V_2 -> V_12 |= V_41 ;
if ( V_4 -> V_7 == V_43 )
V_2 -> V_12 |= V_41 ;
if ( V_4 -> V_7 == V_43 &&
V_4 -> V_5 == 0x3432 )
V_2 -> V_12 |= V_16 ;
if ( V_4 -> V_7 == V_44 &&
V_4 -> V_5 == 0x1042 )
V_2 -> V_12 |= V_16 ;
if ( V_2 -> V_12 & V_41 )
F_6 ( V_2 , V_14 ,
L_9 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
T_1 V_45 ;
void T_2 * V_46 ;
V_46 = ( void T_2 * ) V_2 -> V_47 + 0x80a4 ;
V_45 = F_9 ( V_46 ) ;
F_10 ( V_45 | F_11 ( 28 ) , V_46 ) ;
F_9 ( V_46 ) ;
}
static int F_12 ( struct V_48 * V_49 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_5 ( V_49 -> V_50 . V_51 ) ;
int V_52 ;
V_52 = F_13 ( V_49 , F_4 ) ;
if ( V_52 )
return V_52 ;
V_2 = F_14 ( V_49 ) ;
if ( ! F_15 ( V_49 ) )
return 0 ;
F_16 ( V_4 , V_53 , & V_2 -> V_54 ) ;
F_3 ( V_2 , L_10 , ( unsigned int ) V_2 -> V_54 ) ;
V_52 = F_1 ( V_2 , V_4 ) ;
if ( ! V_52 )
return V_52 ;
F_17 ( V_2 ) ;
return V_52 ;
}
static int F_18 ( struct V_3 * V_6 , const struct V_55 * V_56 )
{
int V_52 ;
struct V_1 * V_2 ;
struct V_57 * V_58 ;
struct V_48 * V_49 ;
V_58 = (struct V_57 * ) V_56 -> V_59 ;
F_19 ( & V_6 -> V_6 ) ;
V_52 = F_20 ( V_6 , V_56 ) ;
if ( V_52 )
goto V_60;
V_49 = F_21 ( & V_6 -> V_6 ) ;
V_2 = F_14 ( V_49 ) ;
V_2 -> V_61 = F_22 ( V_58 , & V_6 -> V_6 ,
F_23 ( V_6 ) , V_49 ) ;
if ( ! V_2 -> V_61 ) {
V_52 = - V_62 ;
goto V_63;
}
* ( (struct V_1 * * ) V_2 -> V_61 -> V_64 ) = V_2 ;
V_52 = F_24 ( V_2 -> V_61 , V_6 -> V_65 ,
V_66 ) ;
if ( V_52 )
goto V_67;
if ( ! ( V_2 -> V_12 & V_16 ) &&
F_25 ( V_2 -> V_68 ) >= 4 )
V_2 -> V_61 -> V_69 = 1 ;
F_26 ( & V_6 -> V_6 ) ;
return 0 ;
V_67:
F_27 ( V_2 -> V_61 ) ;
V_63:
F_28 ( V_6 ) ;
V_60:
F_26 ( & V_6 -> V_6 ) ;
return V_52 ;
}
static void F_29 ( struct V_3 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_14 ( F_30 ( V_6 ) ) ;
if ( V_2 -> V_61 ) {
F_31 ( V_2 -> V_61 ) ;
F_27 ( V_2 -> V_61 ) ;
}
F_28 ( V_6 ) ;
if ( V_2 -> V_12 & V_70 )
F_32 ( V_6 , V_71 ) ;
F_17 ( V_2 ) ;
}
static int F_33 ( struct V_48 * V_49 , bool V_72 )
{
struct V_1 * V_2 = F_14 ( V_49 ) ;
struct V_3 * V_4 = F_5 ( V_49 -> V_50 . V_51 ) ;
if ( V_2 -> V_12 & V_73 )
V_4 -> V_74 = true ;
if ( V_2 -> V_12 & V_38 )
F_8 ( V_2 ) ;
return F_34 ( V_2 , V_72 ) ;
}
static int F_35 ( struct V_48 * V_49 , bool V_75 )
{
struct V_1 * V_2 = F_14 ( V_49 ) ;
struct V_3 * V_4 = F_5 ( V_49 -> V_50 . V_51 ) ;
int V_52 = 0 ;
if ( V_4 -> V_7 == V_25 )
F_36 ( V_4 ) ;
if ( V_2 -> V_12 & V_38 )
F_8 ( V_2 ) ;
V_52 = F_37 ( V_2 , V_75 ) ;
return V_52 ;
}
static int T_3 F_38 ( void )
{
F_39 ( & V_76 , F_12 ) ;
#ifdef F_40
V_76 . V_77 = F_33 ;
V_76 . V_78 = F_35 ;
#endif
return F_41 ( & V_79 ) ;
}
static void T_4 F_42 ( void )
{
F_43 ( & V_79 ) ;
}
