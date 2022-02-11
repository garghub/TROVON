static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
F_3 ( V_2 -> V_5 ) ;
if ( V_2 -> V_6 -> V_7 )
F_3 ( V_2 -> V_8 ) ;
F_4 ( & V_2 -> V_4 , V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
if ( V_2 -> V_6 -> V_7 )
F_6 ( V_2 -> V_8 ) ;
F_6 ( V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_4 , V_3 ) ;
}
static T_1 F_7 ( int V_9 , void * V_10 )
{
struct V_1 * V_2 = (struct V_1 * ) V_10 ;
if ( V_2 -> V_6 -> V_11 )
V_2 -> V_6 -> V_11 ( V_2 , V_12 ) ;
return V_13 ;
}
static T_1 F_8 ( int V_9 , void * V_10 )
{
struct V_1 * V_2 = (struct V_1 * ) V_10 ;
if ( V_2 -> V_6 -> V_11 )
V_2 -> V_6 -> V_11 ( V_2 , V_14 ) ;
return V_13 ;
}
static int F_9 ( struct V_15 * V_16 , unsigned int V_17 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
unsigned int V_18 ;
F_11 ( V_2 -> V_16 , L_1 , V_19 , V_17 ) ;
F_1 ( V_2 ) ;
V_18 = F_12 ( V_2 -> V_20 + V_21 ) & ~ V_22 ;
if ( V_17 )
V_18 |= V_22 ;
F_13 ( V_18 , V_2 -> V_20 + V_21 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int V_23 )
{
if ( ! F_15 ( V_23 ) )
return - V_24 ;
F_16 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_6 -> V_26 )
V_2 -> V_6 -> V_26 ( V_2 , V_23 ) ;
F_17 ( & V_2 -> V_25 ) ;
return 0 ;
}
static int F_18 ( struct V_15 * V_16 , struct V_27 * V_28 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
unsigned int V_29 = 0 ;
F_1 ( V_2 ) ;
V_30:
V_28 -> V_31 = F_12 ( V_2 -> V_20 + V_32 ) ;
V_28 -> V_33 = F_12 ( V_2 -> V_20 + V_34 ) ;
V_28 -> V_35 = F_12 ( V_2 -> V_20 + V_36 ) ;
V_28 -> V_37 = F_12 ( V_2 -> V_20 + V_38 ) ;
V_28 -> V_39 = F_12 ( V_2 -> V_20 + V_40 ) ;
V_28 -> V_41 = F_12 ( V_2 -> V_20 + V_42 ) ;
if ( V_28 -> V_41 == 0 && ! V_29 ) {
V_29 = 1 ;
goto V_30;
}
V_28 -> V_41 = F_19 ( V_28 -> V_41 ) ;
V_28 -> V_31 = F_19 ( V_28 -> V_31 ) ;
V_28 -> V_33 = F_19 ( V_28 -> V_33 ) ;
V_28 -> V_35 = F_19 ( V_28 -> V_35 ) ;
V_28 -> V_37 = F_19 ( V_28 -> V_37 ) ;
V_28 -> V_39 = F_19 ( V_28 -> V_39 ) ;
F_5 ( V_2 ) ;
V_28 -> V_39 += 100 ;
F_11 ( V_16 , L_2 ,
1900 + V_28 -> V_39 , V_28 -> V_37 , V_28 -> V_35 ,
V_28 -> V_33 , V_28 -> V_31 , V_28 -> V_41 ) ;
V_28 -> V_37 -= 1 ;
return F_20 ( V_28 ) ;
}
static int F_21 ( struct V_15 * V_16 , struct V_27 * V_43 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
int V_44 = V_43 -> V_39 - 100 ;
F_11 ( V_16 , L_3 ,
1900 + V_43 -> V_39 , V_43 -> V_37 , V_43 -> V_35 ,
V_43 -> V_33 , V_43 -> V_31 , V_43 -> V_41 ) ;
if ( V_44 < 0 || V_44 >= 100 ) {
F_22 ( V_16 , L_4 ) ;
return - V_24 ;
}
F_1 ( V_2 ) ;
F_13 ( F_23 ( V_43 -> V_41 ) , V_2 -> V_20 + V_42 ) ;
F_13 ( F_23 ( V_43 -> V_31 ) , V_2 -> V_20 + V_32 ) ;
F_13 ( F_23 ( V_43 -> V_33 ) , V_2 -> V_20 + V_34 ) ;
F_13 ( F_23 ( V_43 -> V_35 ) , V_2 -> V_20 + V_36 ) ;
F_13 ( F_23 ( V_43 -> V_37 + 1 ) , V_2 -> V_20 + V_38 ) ;
F_13 ( F_23 ( V_44 ) , V_2 -> V_20 + V_40 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_15 * V_16 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
struct V_27 * V_47 = & V_46 -> time ;
unsigned int V_48 ;
F_1 ( V_2 ) ;
V_47 -> V_41 = F_12 ( V_2 -> V_20 + V_49 ) ;
V_47 -> V_31 = F_12 ( V_2 -> V_20 + V_50 ) ;
V_47 -> V_33 = F_12 ( V_2 -> V_20 + V_51 ) ;
V_47 -> V_37 = F_12 ( V_2 -> V_20 + V_52 ) ;
V_47 -> V_35 = F_12 ( V_2 -> V_20 + V_53 ) ;
V_47 -> V_39 = F_12 ( V_2 -> V_20 + V_54 ) ;
V_48 = F_12 ( V_2 -> V_20 + V_21 ) ;
F_5 ( V_2 ) ;
V_46 -> V_17 = ( V_48 & V_22 ) ? 1 : 0 ;
F_11 ( V_16 , L_5 ,
V_48 ,
1900 + V_47 -> V_39 , V_47 -> V_37 , V_47 -> V_35 ,
V_47 -> V_33 , V_47 -> V_31 , V_47 -> V_41 ) ;
if ( V_48 & V_55 )
V_47 -> V_41 = F_19 ( V_47 -> V_41 ) ;
else
V_47 -> V_41 = - 1 ;
if ( V_48 & V_56 )
V_47 -> V_31 = F_19 ( V_47 -> V_31 ) ;
else
V_47 -> V_31 = - 1 ;
if ( V_48 & V_57 )
V_47 -> V_33 = F_19 ( V_47 -> V_33 ) ;
else
V_47 -> V_33 = - 1 ;
if ( V_48 & V_58 )
V_47 -> V_35 = F_19 ( V_47 -> V_35 ) ;
else
V_47 -> V_35 = - 1 ;
if ( V_48 & V_59 ) {
V_47 -> V_37 = F_19 ( V_47 -> V_37 ) ;
V_47 -> V_37 -= 1 ;
} else {
V_47 -> V_37 = - 1 ;
}
if ( V_48 & V_60 )
V_47 -> V_39 = F_19 ( V_47 -> V_39 ) ;
else
V_47 -> V_39 = - 1 ;
return 0 ;
}
static int F_25 ( struct V_15 * V_16 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
struct V_27 * V_43 = & V_46 -> time ;
unsigned int V_61 ;
F_11 ( V_16 , L_6 ,
V_46 -> V_17 ,
1900 + V_43 -> V_39 , V_43 -> V_37 + 1 , V_43 -> V_35 ,
V_43 -> V_33 , V_43 -> V_31 , V_43 -> V_41 ) ;
F_1 ( V_2 ) ;
V_61 = F_12 ( V_2 -> V_20 + V_21 ) & V_22 ;
F_13 ( 0x00 , V_2 -> V_20 + V_21 ) ;
if ( V_43 -> V_41 < 60 && V_43 -> V_41 >= 0 ) {
V_61 |= V_55 ;
F_13 ( F_23 ( V_43 -> V_41 ) , V_2 -> V_20 + V_49 ) ;
}
if ( V_43 -> V_31 < 60 && V_43 -> V_31 >= 0 ) {
V_61 |= V_56 ;
F_13 ( F_23 ( V_43 -> V_31 ) , V_2 -> V_20 + V_50 ) ;
}
if ( V_43 -> V_33 < 24 && V_43 -> V_33 >= 0 ) {
V_61 |= V_57 ;
F_13 ( F_23 ( V_43 -> V_33 ) , V_2 -> V_20 + V_51 ) ;
}
F_11 ( V_16 , L_7 , V_61 ) ;
F_13 ( V_61 , V_2 -> V_20 + V_21 ) ;
F_5 ( V_2 ) ;
F_9 ( V_16 , V_46 -> V_17 ) ;
return 0 ;
}
static int F_26 ( struct V_15 * V_16 , struct V_62 * V_63 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_6 -> V_64 )
V_2 -> V_6 -> V_64 ( V_2 , V_63 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
unsigned int V_65 , V_18 ;
V_65 = F_28 ( V_2 -> V_20 + V_66 ) ;
if ( ( V_65 & V_67 ) == 0 ) {
F_29 ( V_2 -> V_16 , L_8 ) ;
V_18 = F_28 ( V_2 -> V_20 + V_66 ) ;
F_30 ( V_18 | V_67 ,
V_2 -> V_20 + V_66 ) ;
}
if ( V_65 & V_68 ) {
F_29 ( V_2 -> V_16 , L_9 ) ;
V_18 = F_28 ( V_2 -> V_20 + V_66 ) ;
F_30 ( V_18 & ~ V_68 ,
V_2 -> V_20 + V_66 ) ;
}
if ( V_65 & V_69 ) {
F_29 ( V_2 -> V_16 , L_10 ) ;
V_18 = F_28 ( V_2 -> V_20 + V_66 ) ;
F_30 ( V_18 & ~ V_69 ,
V_2 -> V_20 + V_66 ) ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
unsigned int V_65 ;
V_65 = F_28 ( V_2 -> V_20 + V_66 ) ;
V_65 &= ~ V_67 ;
F_30 ( V_65 , V_2 -> V_20 + V_66 ) ;
V_65 = F_12 ( V_2 -> V_20 + V_70 ) ;
V_65 &= ~ V_71 ;
F_13 ( V_65 , V_2 -> V_20 + V_70 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
unsigned int V_65 ;
V_65 = F_28 ( V_2 -> V_20 + V_66 ) ;
V_65 &= ~ V_72 ;
V_65 &= ~ V_67 ;
F_30 ( V_65 , V_2 -> V_20 + V_66 ) ;
}
static int F_33 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = F_34 ( V_74 ) ;
F_9 ( V_2 -> V_16 , 0 ) ;
F_35 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
static struct V_75 * F_36 ( struct V_73 * V_74 )
{
const struct V_76 * V_77 ;
V_77 = F_37 ( V_78 , V_74 -> V_16 . V_79 ) ;
return (struct V_75 * ) V_77 -> V_6 ;
}
static int F_38 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = NULL ;
struct V_27 V_28 ;
struct V_80 * V_81 ;
int V_82 ;
V_2 = F_39 ( & V_74 -> V_16 , sizeof( * V_2 ) , V_83 ) ;
if ( ! V_2 )
return - V_84 ;
V_2 -> V_85 = F_40 ( V_74 , 1 ) ;
if ( V_2 -> V_85 < 0 ) {
F_22 ( & V_74 -> V_16 , L_11 ) ;
return V_2 -> V_85 ;
}
V_2 -> V_16 = & V_74 -> V_16 ;
V_2 -> V_6 = F_36 ( V_74 ) ;
if ( ! V_2 -> V_6 ) {
F_22 ( & V_74 -> V_16 , L_12 ) ;
return - V_24 ;
}
F_41 ( & V_2 -> V_25 ) ;
F_41 ( & V_2 -> V_4 ) ;
F_42 ( V_74 , V_2 ) ;
V_2 -> V_86 = F_40 ( V_74 , 0 ) ;
if ( V_2 -> V_86 < 0 ) {
F_22 ( & V_74 -> V_16 , L_13 ) ;
return V_2 -> V_86 ;
}
F_11 ( & V_74 -> V_16 , L_14 ,
V_2 -> V_85 , V_2 -> V_86 ) ;
V_81 = F_43 ( V_74 , V_87 , 0 ) ;
V_2 -> V_20 = F_44 ( & V_74 -> V_16 , V_81 ) ;
if ( F_45 ( V_2 -> V_20 ) )
return F_46 ( V_2 -> V_20 ) ;
V_2 -> V_5 = F_47 ( & V_74 -> V_16 , L_15 ) ;
if ( F_45 ( V_2 -> V_5 ) ) {
F_22 ( & V_74 -> V_16 , L_16 ) ;
return F_46 ( V_2 -> V_5 ) ;
}
F_48 ( V_2 -> V_5 ) ;
if ( V_2 -> V_6 -> V_7 ) {
V_2 -> V_8 = F_47 ( & V_74 -> V_16 , L_17 ) ;
if ( F_45 ( V_2 -> V_8 ) ) {
F_22 ( & V_74 -> V_16 ,
L_18 ) ;
return F_46 ( V_2 -> V_8 ) ;
}
F_48 ( V_2 -> V_8 ) ;
}
if ( V_2 -> V_6 -> V_88 )
V_2 -> V_6 -> V_88 ( V_2 ) ;
F_11 ( & V_74 -> V_16 , L_19 ,
F_28 ( V_2 -> V_20 + V_66 ) ) ;
F_49 ( & V_74 -> V_16 , 1 ) ;
if ( F_18 ( & V_74 -> V_16 , & V_28 ) ) {
V_28 . V_39 = 100 ;
V_28 . V_37 = 0 ;
V_28 . V_35 = 1 ;
V_28 . V_33 = 0 ;
V_28 . V_31 = 0 ;
V_28 . V_41 = 0 ;
F_21 ( & V_74 -> V_16 , & V_28 ) ;
F_50 ( & V_74 -> V_16 , L_20 ) ;
}
V_2 -> V_89 = F_51 ( & V_74 -> V_16 , L_21 , & V_90 ,
V_91 ) ;
if ( F_45 ( V_2 -> V_89 ) ) {
F_22 ( & V_74 -> V_16 , L_22 ) ;
V_82 = F_46 ( V_2 -> V_89 ) ;
goto V_92;
}
V_82 = F_52 ( & V_74 -> V_16 , V_2 -> V_86 , F_8 ,
0 , L_23 , V_2 ) ;
if ( V_82 ) {
F_22 ( & V_74 -> V_16 , L_24 , V_2 -> V_86 , V_82 ) ;
goto V_92;
}
V_82 = F_52 ( & V_74 -> V_16 , V_2 -> V_85 , F_7 ,
0 , L_25 , V_2 ) ;
if ( V_82 ) {
F_22 ( & V_74 -> V_16 , L_24 , V_2 -> V_85 , V_82 ) ;
goto V_92;
}
if ( V_2 -> V_6 -> V_93 )
V_2 -> V_6 -> V_93 ( V_2 ) ;
F_14 ( V_2 , 1 ) ;
F_5 ( V_2 ) ;
return 0 ;
V_92:
if ( V_2 -> V_6 -> V_94 )
V_2 -> V_6 -> V_94 ( V_2 ) ;
if ( V_2 -> V_6 -> V_7 )
F_53 ( V_2 -> V_8 ) ;
F_53 ( V_2 -> V_5 ) ;
return V_82 ;
}
static int F_54 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_6 -> V_95 )
V_2 -> V_6 -> V_95 ( V_2 ) ;
if ( V_2 -> V_6 -> V_94 )
V_2 -> V_6 -> V_94 ( V_2 ) ;
if ( F_55 ( V_16 ) && ! V_2 -> V_96 ) {
if ( F_56 ( V_2 -> V_86 ) == 0 )
V_2 -> V_96 = true ;
else
F_22 ( V_16 , L_26 ) ;
}
return 0 ;
}
static int F_57 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
if ( V_2 -> V_6 -> V_88 )
V_2 -> V_6 -> V_88 ( V_2 ) ;
if ( V_2 -> V_6 -> V_97 )
V_2 -> V_6 -> V_97 ( V_2 ) ;
F_5 ( V_2 ) ;
if ( F_55 ( V_16 ) && V_2 -> V_96 ) {
F_58 ( V_2 -> V_86 ) ;
V_2 -> V_96 = false ;
}
return 0 ;
}
static void F_59 ( struct V_1 * V_2 , int V_98 )
{
F_60 ( V_2 -> V_89 , 1 , V_99 | V_100 ) ;
}
static void F_61 ( struct V_1 * V_2 , int V_98 )
{
F_60 ( V_2 -> V_89 , 1 , V_99 | V_100 ) ;
F_13 ( V_98 , V_2 -> V_20 + V_101 ) ;
}
static void F_62 ( struct V_1 * V_2 , int V_23 )
{
unsigned int V_18 = 0 ;
int V_102 ;
V_18 = F_12 ( V_2 -> V_20 + V_70 ) ;
V_18 &= V_71 ;
V_102 = ( V_2 -> V_89 -> V_103 / V_23 ) - 1 ;
V_18 |= V_102 ;
F_63 ( V_18 , V_2 -> V_20 + V_70 ) ;
}
static void F_64 ( struct V_1 * V_2 , int V_23 )
{
unsigned int V_18 = 0 ;
int V_102 ;
V_18 = F_12 ( V_2 -> V_20 + V_70 ) ;
V_18 &= V_71 ;
V_102 = ( V_2 -> V_89 -> V_103 / V_23 ) - 1 ;
V_18 |= F_65 ( V_102 ) ;
F_63 ( F_66 ( V_102 ) , V_2 -> V_20 + V_104 ) ;
F_63 ( F_67 ( V_102 ) , V_2 -> V_20 + V_105 ) ;
F_63 ( V_18 , V_2 -> V_20 + V_70 ) ;
}
static void F_68 ( struct V_1 * V_2 , int V_23 )
{
unsigned int V_18 = 0 ;
int V_102 ;
V_18 = F_12 ( V_2 -> V_20 + V_70 ) ;
V_18 &= V_71 ;
V_102 = ( V_2 -> V_89 -> V_103 / V_23 ) - 1 ;
V_18 |= F_65 ( V_102 ) ;
F_63 ( F_66 ( V_102 ) , V_2 -> V_20 + V_104 ) ;
F_63 ( V_18 , V_2 -> V_20 + V_70 ) ;
}
static void F_69 ( struct V_1 * V_2 , int V_23 )
{
int V_102 ;
V_102 = ( V_2 -> V_89 -> V_103 / V_23 ) - 1 ;
F_63 ( V_102 , V_2 -> V_20 + V_70 ) ;
}
static void F_70 ( struct V_1 * V_2 , struct V_62 * V_63 )
{
unsigned int V_106 ;
V_106 = F_12 ( V_2 -> V_20 + V_70 ) ;
V_106 &= V_71 ;
F_71 ( V_63 , L_27 , V_106 ? L_28 : L_29 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
unsigned int V_65 ;
V_65 = F_28 ( V_2 -> V_20 + V_66 ) ;
V_65 |= V_107 ;
F_30 ( V_65 , V_2 -> V_20 + V_66 ) ;
}
static void F_73 ( struct V_1 * V_2 , struct V_62 * V_63 )
{
unsigned int V_106 ;
V_106 = F_28 ( V_2 -> V_20 + V_66 ) ;
V_106 &= V_72 ;
F_71 ( V_63 , L_27 , V_106 ? L_28 : L_29 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
V_2 -> V_108 = F_12 ( V_2 -> V_20 + V_70 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_108 , V_2 -> V_20 + V_70 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
V_2 -> V_109 = F_28 ( V_2 -> V_20 + V_66 ) ;
V_2 -> V_109 &= V_72 ;
V_2 -> V_108 = F_77 ( V_2 -> V_20 + V_70 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
unsigned int V_65 ;
F_63 ( V_2 -> V_108 , V_2 -> V_20 + V_70 ) ;
if ( V_2 -> V_109 ) {
V_65 = F_28 ( V_2 -> V_20 + V_66 ) ;
F_30 ( V_65 | V_2 -> V_109 ,
V_2 -> V_20 + V_66 ) ;
}
}
