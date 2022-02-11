static inline int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_8 ) {
V_4 |= V_6 -> V_9 ;
V_4 &= ~ V_6 -> V_10 ;
}
return V_4 ;
}
static void F_2 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
F_4 ( V_12 ) ;
( void ) V_2 -> V_13 ( V_2 , V_14 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_4 )
{
void T_1 * V_3 = V_2 -> V_15 + ( V_16 << V_2 -> V_17 ) ;
int V_18 = 1000 ;
while ( V_18 -- ) {
unsigned int V_19 = V_2 -> V_13 ( V_2 , V_16 ) ;
if ( ( V_4 & ~ V_20 ) == ( V_19 & ~ V_20 ) )
return;
F_2 ( V_2 ) ;
#ifdef F_6
if ( V_2 -> type == V_21 )
F_7 ( V_4 & 0xff , V_3 ) ;
else
#endif
if ( V_2 -> V_22 == V_23 )
F_8 ( V_4 , V_3 ) ;
else if ( V_2 -> V_22 == V_24 )
F_9 ( V_4 , V_3 ) ;
else
F_10 ( V_4 , V_3 ) ;
}
}
static void F_11 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_10 ( V_4 , V_2 -> V_15 + ( V_3 << V_2 -> V_17 ) ) ;
if ( V_3 == V_16 && ! V_6 -> V_25 )
F_5 ( V_2 , V_4 ) ;
}
static unsigned int F_12 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 = F_13 ( V_2 -> V_15 + ( V_3 << V_2 -> V_17 ) ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static unsigned int F_14 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 ;
V_4 = ( V_26 ) F_15 ( V_2 -> V_15 + ( V_3 << V_2 -> V_17 ) ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_4 &= 0xff ;
F_7 ( V_4 , V_2 -> V_15 + ( V_3 << V_2 -> V_17 ) ) ;
F_15 ( V_2 -> V_15 + ( V_16 << V_2 -> V_17 ) ) ;
if ( V_3 == V_16 && ! V_6 -> V_25 )
F_5 ( V_2 , V_4 ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_8 ( V_4 , V_2 -> V_15 + ( V_3 << V_2 -> V_17 ) ) ;
if ( V_3 == V_16 && ! V_6 -> V_25 )
F_5 ( V_2 , V_4 ) ;
}
static unsigned int F_18 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 = F_19 ( V_2 -> V_15 + ( V_3 << V_2 -> V_17 ) ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static void F_20 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_9 ( V_4 , V_2 -> V_15 + ( V_3 << V_2 -> V_17 ) ) ;
if ( V_3 == V_16 && ! V_6 -> V_25 )
F_5 ( V_2 , V_4 ) ;
}
static unsigned int F_21 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 = F_22 ( V_2 -> V_15 + ( V_3 << V_2 -> V_17 ) ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_27 = V_2 -> V_13 ( V_2 , V_28 ) ;
unsigned int V_29 ;
unsigned long V_30 ;
if ( ! V_12 -> V_31 && ( ( V_27 & 0x3f ) == V_32 ) ) {
F_24 ( & V_2 -> V_33 , V_30 ) ;
V_29 = V_2 -> V_13 ( V_2 , V_34 ) ;
if ( ! ( V_29 & ( V_35 | V_36 ) ) )
( void ) V_2 -> V_13 ( V_2 , V_14 ) ;
F_25 ( & V_2 -> V_33 , V_30 ) ;
}
if ( F_26 ( V_2 , V_27 ) )
return 1 ;
if ( ( V_27 & V_37 ) == V_37 ) {
( void ) V_2 -> V_13 ( V_2 , V_6 -> V_38 ) ;
return 1 ;
}
return 0 ;
}
static void
F_27 ( struct V_1 * V_39 , unsigned int V_40 , unsigned int V_41 )
{
if ( ! V_40 )
F_28 ( V_39 -> V_42 ) ;
F_29 ( V_39 , V_40 , V_41 ) ;
if ( V_40 )
F_30 ( V_39 -> V_42 ) ;
}
static void F_31 ( struct V_1 * V_2 , struct V_43 * V_44 ,
struct V_43 * V_41 )
{
unsigned int V_45 = F_32 ( V_44 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
long V_46 ;
int V_47 ;
if ( F_33 ( V_6 -> V_48 ) || ! V_41 )
goto V_49;
F_34 ( V_6 -> V_48 ) ;
V_46 = F_35 ( V_6 -> V_48 , V_45 * 16 ) ;
if ( V_46 < 0 )
V_47 = V_46 ;
else if ( V_46 == 0 )
V_47 = - V_50 ;
else
V_47 = F_36 ( V_6 -> V_48 , V_46 ) ;
F_37 ( V_6 -> V_48 ) ;
if ( ! V_47 )
V_2 -> V_51 = V_46 ;
V_49:
V_2 -> V_29 &= ~ V_52 ;
if ( V_44 -> V_53 & V_54 )
V_2 -> V_29 |= V_52 ;
F_38 ( V_2 , V_44 , V_41 ) ;
}
static void F_39 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
unsigned int V_55 = V_2 -> V_13 ( V_2 , V_56 ) ;
if ( V_12 -> V_57 & V_58 ) {
if ( V_44 -> V_59 == V_60 )
V_55 |= V_61 ;
else
V_55 &= ~ V_61 ;
V_2 -> V_62 ( V_2 , V_56 , V_55 ) ;
}
F_40 ( V_2 , V_44 ) ;
}
static bool F_41 ( struct V_63 * V_64 , void * V_65 )
{
return false ;
}
static bool F_42 ( struct V_63 * V_64 , void * V_65 )
{
return V_65 == V_64 -> V_66 -> V_42 -> V_67 ;
}
static void F_43 ( struct V_1 * V_2 , struct V_5 * V_68 )
{
if ( V_2 -> V_42 -> V_69 ) {
struct V_70 * V_71 = V_2 -> V_42 -> V_69 ;
int V_72 ;
V_72 = F_44 ( V_71 , L_1 ) ;
if ( V_72 >= 0 )
V_2 -> line = V_72 ;
#ifdef F_6
if ( F_45 ( V_71 , L_2 ) ) {
V_2 -> V_13 = F_14 ;
V_2 -> V_62 = F_16 ;
V_2 -> V_30 = V_73 | V_74 | V_75 ;
V_2 -> type = V_21 ;
V_68 -> V_38 = 0x27 ;
V_68 -> V_76 = true ;
}
#endif
if ( F_46 ( V_2 -> V_42 -> V_69 ) ) {
V_2 -> V_22 = V_24 ;
V_2 -> V_13 = F_21 ;
V_2 -> V_62 = F_20 ;
}
} else if ( F_47 ( V_2 -> V_42 ) ) {
const struct V_77 * V_72 ;
V_72 = F_48 ( V_2 -> V_42 -> V_78 -> V_79 ,
V_2 -> V_42 ) ;
if ( V_72 && ! strcmp ( V_72 -> V_72 , L_3 ) ) {
V_2 -> V_22 = V_23 ;
V_2 -> V_17 = 2 ;
V_2 -> V_13 = F_18 ;
V_68 -> V_25 = true ;
}
}
if ( F_49 ( F_50 ( V_2 -> V_42 ) ,
V_80 , L_4 ) ) {
V_68 -> V_31 . V_81 = V_2 -> V_42 -> V_67 ;
V_68 -> V_31 . V_82 = V_2 -> V_42 -> V_67 ;
V_68 -> V_31 . V_83 = F_42 ;
}
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
T_2 V_84 ;
if ( V_2 -> V_22 == V_24 )
V_84 = F_22 ( V_2 -> V_15 + V_85 ) ;
else
V_84 = F_19 ( V_2 -> V_15 + V_85 ) ;
if ( ! V_84 )
return;
F_52 ( V_2 -> V_42 , L_5 ,
( V_84 >> 24 ) & 0xff , ( V_84 >> 16 ) & 0xff , ( V_84 >> 8 ) & 0xff ) ;
if ( V_2 -> V_22 == V_24 )
V_84 = F_22 ( V_2 -> V_15 + V_86 ) ;
else
V_84 = F_19 ( V_2 -> V_15 + V_86 ) ;
if ( ! V_84 )
return;
if ( V_84 & V_87 ) {
V_2 -> type = V_88 ;
V_2 -> V_30 |= V_75 ;
V_2 -> V_89 = F_53 ( V_84 ) ;
V_12 -> V_57 = V_90 ;
}
if ( V_84 & V_91 )
V_12 -> V_57 |= V_92 ;
if ( V_84 & V_93 )
V_12 -> V_57 |= V_58 ;
}
static int F_54 ( struct V_94 * V_95 )
{
struct V_11 V_96 = {} ;
struct V_97 * V_98 = F_55 ( V_95 , V_80 , 0 ) ;
int V_99 = F_56 ( V_95 , 0 ) ;
struct V_1 * V_2 = & V_96 . V_39 ;
struct V_66 * V_42 = & V_95 -> V_42 ;
struct V_5 * V_68 ;
int V_100 ;
T_2 V_101 ;
if ( ! V_98 ) {
F_57 ( V_42 , L_6 ) ;
return - V_102 ;
}
if ( V_99 < 0 ) {
if ( V_99 != - V_103 )
F_57 ( V_42 , L_7 ) ;
return V_99 ;
}
F_58 ( & V_2 -> V_33 ) ;
V_2 -> V_104 = V_98 -> V_105 ;
V_2 -> V_99 = V_99 ;
V_2 -> V_106 = F_23 ;
V_2 -> V_107 = F_27 ;
V_2 -> type = V_108 ;
V_2 -> V_30 = V_74 | V_109 ;
V_2 -> V_42 = V_42 ;
V_2 -> V_22 = V_110 ;
V_2 -> V_13 = F_12 ;
V_2 -> V_62 = F_11 ;
V_2 -> V_111 = F_39 ;
V_2 -> V_112 = F_31 ;
V_2 -> V_15 = F_59 ( V_42 , V_98 -> V_105 , F_60 ( V_98 ) ) ;
if ( ! V_2 -> V_15 )
return - V_113 ;
V_68 = F_61 ( V_42 , sizeof( * V_68 ) , V_114 ) ;
if ( ! V_68 )
return - V_113 ;
V_68 -> V_31 . V_83 = F_41 ;
V_68 -> V_38 = V_115 ;
V_2 -> V_7 = V_68 ;
V_68 -> V_25 = F_62 ( V_42 ,
L_8 ) ;
V_100 = F_63 ( V_42 , L_9 , & V_101 ) ;
if ( ! V_100 )
V_2 -> V_17 = V_101 ;
V_100 = F_63 ( V_42 , L_10 , & V_101 ) ;
if ( ! V_100 && V_101 == 4 ) {
V_2 -> V_22 = V_23 ;
V_2 -> V_13 = F_18 ;
V_2 -> V_62 = F_17 ;
}
if ( F_62 ( V_42 , L_11 ) ) {
V_68 -> V_9 |= V_116 ;
V_68 -> V_10 |= V_117 ;
}
if ( F_62 ( V_42 , L_12 ) ) {
V_68 -> V_9 |= V_118 ;
V_68 -> V_10 |= V_119 ;
}
if ( F_62 ( V_42 , L_13 ) ) {
V_68 -> V_9 |= V_120 ;
V_68 -> V_10 |= V_121 ;
}
if ( F_62 ( V_42 , L_14 ) ) {
V_68 -> V_10 |= V_122 ;
V_68 -> V_10 |= V_123 ;
}
F_63 ( V_42 , L_15 , & V_2 -> V_51 ) ;
V_68 -> V_48 = F_64 ( V_42 , L_16 ) ;
if ( F_33 ( V_68 -> V_48 ) && F_65 ( V_68 -> V_48 ) != - V_103 )
V_68 -> V_48 = F_64 ( V_42 , NULL ) ;
if ( F_33 ( V_68 -> V_48 ) && F_65 ( V_68 -> V_48 ) == - V_103 )
return - V_103 ;
if ( ! F_66 ( V_68 -> V_48 ) ) {
V_100 = F_37 ( V_68 -> V_48 ) ;
if ( V_100 )
F_67 ( V_42 , L_17 ,
V_100 ) ;
else
V_2 -> V_51 = F_68 ( V_68 -> V_48 ) ;
}
if ( ! V_2 -> V_51 ) {
F_57 ( V_42 , L_18 ) ;
return - V_102 ;
}
V_68 -> V_124 = F_64 ( V_42 , L_19 ) ;
if ( F_33 ( V_68 -> V_124 ) && F_65 ( V_68 -> V_124 ) == - V_103 ) {
V_100 = - V_103 ;
goto V_125;
}
if ( ! F_33 ( V_68 -> V_124 ) ) {
V_100 = F_37 ( V_68 -> V_124 ) ;
if ( V_100 ) {
F_57 ( V_42 , L_20 ) ;
goto V_125;
}
}
V_68 -> V_126 = F_69 ( V_42 , NULL ) ;
if ( F_33 ( V_68 -> V_126 ) ) {
V_100 = F_65 ( V_68 -> V_126 ) ;
goto V_127;
}
F_70 ( V_68 -> V_126 ) ;
F_43 ( V_2 , V_68 ) ;
if ( V_68 -> V_25 )
V_2 -> V_106 = NULL ;
if ( ! V_68 -> V_76 )
F_51 ( V_2 ) ;
if ( V_2 -> V_89 ) {
V_68 -> V_31 . V_128 . V_129 = V_2 -> V_89 / 4 ;
V_68 -> V_31 . V_130 . V_131 = V_2 -> V_89 / 4 ;
V_96 . V_31 = & V_68 -> V_31 ;
}
V_68 -> line = F_71 ( & V_96 ) ;
if ( V_68 -> line < 0 ) {
V_100 = V_68 -> line ;
goto V_132;
}
F_72 ( V_95 , V_68 ) ;
F_73 ( V_42 ) ;
F_74 ( V_42 ) ;
return 0 ;
V_132:
F_75 ( V_68 -> V_126 ) ;
V_127:
if ( ! F_33 ( V_68 -> V_124 ) )
F_34 ( V_68 -> V_124 ) ;
V_125:
if ( ! F_33 ( V_68 -> V_48 ) )
F_34 ( V_68 -> V_48 ) ;
return V_100 ;
}
static int F_76 ( struct V_94 * V_95 )
{
struct V_5 * V_68 = F_77 ( V_95 ) ;
F_28 ( & V_95 -> V_42 ) ;
F_78 ( V_68 -> line ) ;
F_75 ( V_68 -> V_126 ) ;
if ( ! F_33 ( V_68 -> V_124 ) )
F_34 ( V_68 -> V_124 ) ;
if ( ! F_33 ( V_68 -> V_48 ) )
F_34 ( V_68 -> V_48 ) ;
F_79 ( & V_95 -> V_42 ) ;
F_80 ( & V_95 -> V_42 ) ;
return 0 ;
}
static int F_81 ( struct V_66 * V_42 )
{
struct V_5 * V_68 = F_82 ( V_42 ) ;
F_83 ( V_68 -> line ) ;
return 0 ;
}
static int F_84 ( struct V_66 * V_42 )
{
struct V_5 * V_68 = F_82 ( V_42 ) ;
F_85 ( V_68 -> line ) ;
return 0 ;
}
static int F_86 ( struct V_66 * V_42 )
{
struct V_5 * V_68 = F_82 ( V_42 ) ;
if ( ! F_33 ( V_68 -> V_48 ) )
F_34 ( V_68 -> V_48 ) ;
if ( ! F_33 ( V_68 -> V_124 ) )
F_34 ( V_68 -> V_124 ) ;
return 0 ;
}
static int F_87 ( struct V_66 * V_42 )
{
struct V_5 * V_68 = F_82 ( V_42 ) ;
if ( ! F_33 ( V_68 -> V_124 ) )
F_37 ( V_68 -> V_124 ) ;
if ( ! F_33 ( V_68 -> V_48 ) )
F_37 ( V_68 -> V_48 ) ;
return 0 ;
}
