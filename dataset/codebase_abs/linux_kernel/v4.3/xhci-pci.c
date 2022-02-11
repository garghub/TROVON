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
V_2 -> V_12 |= V_35 ;
}
if ( V_4 -> V_7 == V_25 &&
( V_4 -> V_5 == V_36 ||
V_4 -> V_5 == V_37 ||
V_4 -> V_5 == V_38 ) ) {
V_2 -> V_12 |= V_39 ;
}
if ( V_4 -> V_7 == V_40 &&
V_4 -> V_5 == V_41 ) {
V_2 -> V_12 |= V_42 ;
V_2 -> V_12 |= V_18 ;
V_2 -> V_12 |= V_16 ;
}
if ( V_4 -> V_7 == V_43 &&
V_4 -> V_5 == 0x0015 )
V_2 -> V_12 |= V_42 ;
if ( V_4 -> V_7 == V_44 )
V_2 -> V_12 |= V_42 ;
if ( V_4 -> V_7 == V_44 &&
V_4 -> V_5 == 0x3432 )
V_2 -> V_12 |= V_16 ;
if ( V_4 -> V_7 == V_45 &&
V_4 -> V_5 == 0x1042 )
V_2 -> V_12 |= V_16 ;
if ( V_2 -> V_12 & V_42 )
F_6 ( V_2 , V_14 ,
L_9 ) ;
}
static void F_8 ( struct V_3 * V_6 )
{
static const T_1 V_46 [] = {
0xb7 , 0x0c , 0x34 , 0xac , 0x01 , 0xe9 , 0xbf , 0x45 ,
0xb7 , 0xe6 , 0x2b , 0x34 , 0xec , 0x93 , 0x1e , 0x23 ,
} ;
F_9 ( F_10 ( & V_6 -> V_6 ) , V_46 , 3 , 1 , NULL ) ;
}
static void F_8 ( struct V_3 * V_6 ) { }
static int F_11 ( struct V_47 * V_48 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_5 ( V_48 -> V_49 . V_50 ) ;
int V_51 ;
V_51 = F_12 ( V_48 , F_4 ) ;
if ( V_51 )
return V_51 ;
V_2 = F_13 ( V_48 ) ;
if ( ! F_14 ( V_48 ) )
return 0 ;
F_15 ( V_4 , V_52 , & V_2 -> V_53 ) ;
F_3 ( V_2 , L_10 , ( unsigned int ) V_2 -> V_53 ) ;
V_51 = F_1 ( V_2 , V_4 ) ;
if ( ! V_51 )
return V_51 ;
return V_51 ;
}
static int F_16 ( struct V_3 * V_6 , const struct V_54 * V_55 )
{
int V_51 ;
struct V_1 * V_2 ;
struct V_56 * V_57 ;
struct V_47 * V_48 ;
V_57 = (struct V_56 * ) V_55 -> V_58 ;
F_17 ( & V_6 -> V_6 ) ;
V_51 = F_18 ( V_6 , V_55 ) ;
if ( V_51 )
goto V_59;
V_48 = F_19 ( & V_6 -> V_6 ) ;
V_2 = F_13 ( V_48 ) ;
V_2 -> V_60 = F_20 ( V_57 , & V_6 -> V_6 ,
F_21 ( V_6 ) , V_48 ) ;
if ( ! V_2 -> V_60 ) {
V_51 = - V_61 ;
goto V_62;
}
V_51 = F_22 ( V_2 -> V_60 , V_6 -> V_63 ,
V_64 ) ;
if ( V_51 )
goto V_65;
if ( ! ( V_2 -> V_12 & V_16 ) &&
F_23 ( V_2 -> V_66 ) >= 4 )
V_2 -> V_60 -> V_67 = 1 ;
if ( V_2 -> V_12 & V_39 )
F_8 ( V_6 ) ;
F_24 ( & V_6 -> V_6 ) ;
return 0 ;
V_65:
F_25 ( V_2 -> V_60 ) ;
V_62:
F_26 ( V_6 ) ;
V_59:
F_24 ( & V_6 -> V_6 ) ;
return V_51 ;
}
static void F_27 ( struct V_3 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_13 ( F_28 ( V_6 ) ) ;
if ( V_2 -> V_60 ) {
F_29 ( V_2 -> V_60 ) ;
F_25 ( V_2 -> V_60 ) ;
}
F_26 ( V_6 ) ;
if ( V_2 -> V_12 & V_35 )
F_30 ( V_6 , V_68 ) ;
}
static void F_31 ( struct V_47 * V_48 , bool V_69 )
{
struct V_1 * V_2 = F_13 ( V_48 ) ;
struct V_3 * V_4 = F_5 ( V_48 -> V_49 . V_50 ) ;
T_2 V_70 ;
void T_3 * V_71 ;
if ( V_4 -> V_7 == V_25 &&
V_4 -> V_5 == V_38 ) {
V_71 = ( void T_3 * ) V_2 -> V_72 + V_73 ;
V_70 = F_32 ( V_71 ) & ~ V_74 ;
F_33 ( V_70 , V_71 ) ;
V_70 = F_32 ( V_71 ) ;
if ( V_69 )
V_70 |= V_75 ;
else
V_70 &= ~ V_75 ;
F_33 ( V_70 , V_71 ) ;
V_70 = F_32 ( V_71 ) | V_74 ;
F_33 ( V_70 , V_71 ) ;
F_32 ( V_71 ) ;
}
V_71 = ( void T_3 * ) V_2 -> V_72 + 0x80a4 ;
V_70 = F_32 ( V_71 ) ;
F_33 ( V_70 | F_34 ( 28 ) , V_71 ) ;
F_32 ( V_71 ) ;
}
static int F_35 ( struct V_47 * V_48 , bool V_76 )
{
struct V_1 * V_2 = F_13 ( V_48 ) ;
struct V_3 * V_4 = F_5 ( V_48 -> V_49 . V_50 ) ;
if ( V_2 -> V_12 & V_77 )
V_4 -> V_78 = true ;
if ( V_2 -> V_12 & V_39 )
F_31 ( V_48 , true ) ;
return F_36 ( V_2 , V_76 ) ;
}
static int F_37 ( struct V_47 * V_48 , bool V_79 )
{
struct V_1 * V_2 = F_13 ( V_48 ) ;
struct V_3 * V_4 = F_5 ( V_48 -> V_49 . V_50 ) ;
int V_51 = 0 ;
if ( V_4 -> V_7 == V_25 )
F_38 ( V_4 ) ;
if ( V_2 -> V_12 & V_39 )
F_31 ( V_48 , false ) ;
V_51 = F_39 ( V_2 , V_79 ) ;
return V_51 ;
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
