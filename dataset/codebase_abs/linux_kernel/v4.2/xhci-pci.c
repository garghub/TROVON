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
static void F_8 ( struct V_45 * V_46 , bool V_47 )
{
struct V_1 * V_2 = F_9 ( V_46 ) ;
struct V_3 * V_4 = F_5 ( V_46 -> V_48 . V_49 ) ;
T_1 V_50 ;
void T_2 * V_51 ;
if ( V_4 -> V_7 == V_25 &&
V_4 -> V_5 == V_37 ) {
V_51 = ( void T_2 * ) V_2 -> V_52 + V_53 ;
V_50 = F_10 ( V_51 ) & ~ V_54 ;
F_11 ( V_50 , V_51 ) ;
V_50 = F_10 ( V_51 ) ;
if ( V_47 )
V_50 |= V_55 ;
else
V_50 &= ~ V_55 ;
F_11 ( V_50 , V_51 ) ;
V_50 = F_10 ( V_51 ) | V_54 ;
F_11 ( V_50 , V_51 ) ;
F_10 ( V_51 ) ;
}
V_51 = ( void T_2 * ) V_2 -> V_52 + 0x80a4 ;
V_50 = F_10 ( V_51 ) ;
F_11 ( V_50 | F_12 ( 28 ) , V_51 ) ;
F_10 ( V_51 ) ;
}
static void F_13 ( struct V_3 * V_6 )
{
static const T_3 V_56 [] = {
0xb7 , 0x0c , 0x34 , 0xac , 0x01 , 0xe9 , 0xbf , 0x45 ,
0xb7 , 0xe6 , 0x2b , 0x34 , 0xec , 0x93 , 0x1e , 0x23 ,
} ;
F_14 ( F_15 ( & V_6 -> V_6 ) , V_56 , 3 , 1 , NULL ) ;
}
static void F_13 ( struct V_3 * V_6 ) { }
static int F_16 ( struct V_45 * V_46 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_5 ( V_46 -> V_48 . V_49 ) ;
int V_57 ;
V_57 = F_17 ( V_46 , F_4 ) ;
if ( V_57 )
return V_57 ;
V_2 = F_9 ( V_46 ) ;
if ( ! F_18 ( V_46 ) )
return 0 ;
F_19 ( V_4 , V_58 , & V_2 -> V_59 ) ;
F_3 ( V_2 , L_10 , ( unsigned int ) V_2 -> V_59 ) ;
V_57 = F_1 ( V_2 , V_4 ) ;
if ( ! V_57 )
return V_57 ;
return V_57 ;
}
static int F_20 ( struct V_3 * V_6 , const struct V_60 * V_61 )
{
int V_57 ;
struct V_1 * V_2 ;
struct V_62 * V_63 ;
struct V_45 * V_46 ;
V_63 = (struct V_62 * ) V_61 -> V_64 ;
F_21 ( & V_6 -> V_6 ) ;
V_57 = F_22 ( V_6 , V_61 ) ;
if ( V_57 )
goto V_65;
V_46 = F_23 ( & V_6 -> V_6 ) ;
V_2 = F_9 ( V_46 ) ;
V_2 -> V_66 = F_24 ( V_63 , & V_6 -> V_6 ,
F_25 ( V_6 ) , V_46 ) ;
if ( ! V_2 -> V_66 ) {
V_57 = - V_67 ;
goto V_68;
}
V_57 = F_26 ( V_2 -> V_66 , V_6 -> V_69 ,
V_70 ) ;
if ( V_57 )
goto V_71;
if ( ! ( V_2 -> V_12 & V_16 ) &&
F_27 ( V_2 -> V_72 ) >= 4 )
V_2 -> V_66 -> V_73 = 1 ;
if ( V_2 -> V_12 & V_38 )
F_13 ( V_6 ) ;
F_28 ( & V_6 -> V_6 ) ;
return 0 ;
V_71:
F_29 ( V_2 -> V_66 ) ;
V_68:
F_30 ( V_6 ) ;
V_65:
F_28 ( & V_6 -> V_6 ) ;
return V_57 ;
}
static void F_31 ( struct V_3 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_9 ( F_32 ( V_6 ) ) ;
if ( V_2 -> V_66 ) {
F_33 ( V_2 -> V_66 ) ;
F_29 ( V_2 -> V_66 ) ;
}
F_30 ( V_6 ) ;
if ( V_2 -> V_12 & V_74 )
F_34 ( V_6 , V_75 ) ;
}
static int F_35 ( struct V_45 * V_46 , bool V_76 )
{
struct V_1 * V_2 = F_9 ( V_46 ) ;
struct V_3 * V_4 = F_5 ( V_46 -> V_48 . V_49 ) ;
if ( V_2 -> V_12 & V_77 )
V_4 -> V_78 = true ;
if ( V_2 -> V_12 & V_38 )
F_8 ( V_46 , true ) ;
return F_36 ( V_2 , V_76 ) ;
}
static int F_37 ( struct V_45 * V_46 , bool V_79 )
{
struct V_1 * V_2 = F_9 ( V_46 ) ;
struct V_3 * V_4 = F_5 ( V_46 -> V_48 . V_49 ) ;
int V_57 = 0 ;
if ( V_4 -> V_7 == V_25 )
F_38 ( V_4 ) ;
if ( V_2 -> V_12 & V_38 )
F_8 ( V_46 , false ) ;
V_57 = F_39 ( V_2 , V_79 ) ;
return V_57 ;
}
static int T_4 F_40 ( void )
{
F_41 ( & V_80 , & V_81 ) ;
#ifdef F_42
V_80 . V_82 = F_35 ;
V_80 . V_83 = F_37 ;
#endif
return F_43 ( & V_84 ) ;
}
static void T_5 F_44 ( void )
{
F_45 ( & V_84 ) ;
}
