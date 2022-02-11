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
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_27 = V_2 -> V_13 ( V_2 , V_28 ) ;
if ( F_24 ( V_2 , V_27 ) )
return 1 ;
if ( ( V_27 & V_29 ) == V_29 ) {
( void ) V_2 -> V_13 ( V_2 , V_6 -> V_30 ) ;
return 1 ;
}
return 0 ;
}
static void
F_25 ( struct V_1 * V_31 , unsigned int V_32 , unsigned int V_33 )
{
if ( ! V_32 )
F_26 ( V_31 -> V_34 ) ;
F_27 ( V_31 , V_32 , V_33 ) ;
if ( V_32 )
F_28 ( V_31 -> V_34 ) ;
}
static void F_29 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_35 * V_33 )
{
unsigned int V_37 = F_30 ( V_36 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_38 ;
int V_39 ;
if ( F_31 ( V_6 -> V_40 ) || ! V_33 )
goto V_41;
F_32 ( V_6 -> V_40 ) ;
V_38 = F_33 ( V_6 -> V_40 , V_37 * 16 ) ;
V_39 = F_34 ( V_6 -> V_40 , V_38 ) ;
F_35 ( V_6 -> V_40 ) ;
if ( ! V_39 )
V_2 -> V_42 = V_38 ;
V_2 -> V_43 &= ~ V_44 ;
if ( V_36 -> V_45 & V_46 )
V_2 -> V_43 |= V_44 ;
V_41:
F_36 ( V_2 , V_36 , V_33 ) ;
}
static void F_37 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
unsigned int V_47 = V_2 -> V_13 ( V_2 , V_48 ) ;
if ( V_12 -> V_49 & V_50 ) {
if ( V_36 -> V_51 == V_52 )
V_47 |= V_53 ;
else
V_47 &= ~ V_53 ;
V_2 -> V_54 ( V_2 , V_48 , V_47 ) ;
}
F_38 ( V_2 , V_36 ) ;
}
static bool F_39 ( struct V_55 * V_56 , void * V_57 )
{
return false ;
}
static bool F_40 ( struct V_55 * V_56 , void * V_57 )
{
return V_57 == V_56 -> V_58 -> V_34 -> V_59 ;
}
static void F_41 ( struct V_1 * V_2 , struct V_5 * V_60 )
{
if ( V_2 -> V_34 -> V_61 ) {
struct V_62 * V_63 = V_2 -> V_34 -> V_61 ;
int V_64 ;
V_64 = F_42 ( V_63 , L_1 ) ;
if ( V_64 >= 0 )
V_2 -> line = V_64 ;
#ifdef F_6
if ( F_43 ( V_63 , L_2 ) ) {
V_2 -> V_13 = F_14 ;
V_2 -> V_54 = F_16 ;
V_2 -> V_65 = V_66 | V_67 | V_68 ;
V_2 -> type = V_21 ;
V_60 -> V_30 = 0x27 ;
V_60 -> V_69 = true ;
}
#endif
if ( F_44 ( V_2 -> V_34 -> V_61 ) ) {
V_2 -> V_22 = V_24 ;
V_2 -> V_13 = F_21 ;
V_2 -> V_54 = F_20 ;
}
} else if ( F_45 ( V_2 -> V_34 ) ) {
const struct V_70 * V_64 ;
V_64 = F_46 ( V_2 -> V_34 -> V_71 -> V_72 ,
V_2 -> V_34 ) ;
if ( V_64 && ! strcmp ( V_64 -> V_64 , L_3 ) ) {
V_2 -> V_22 = V_23 ;
V_2 -> V_17 = 2 ;
V_2 -> V_13 = F_18 ;
V_60 -> V_25 = true ;
}
V_2 -> V_73 = F_29 ;
}
if ( F_47 ( F_48 ( V_2 -> V_34 ) ,
V_74 , L_4 ) ) {
V_2 -> V_73 = F_29 ;
V_60 -> V_75 . V_76 = V_2 -> V_34 -> V_59 ;
V_60 -> V_75 . V_77 = V_2 -> V_34 -> V_59 ;
V_60 -> V_75 . V_78 = F_40 ;
}
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
T_2 V_79 ;
if ( V_2 -> V_22 == V_24 )
V_79 = F_22 ( V_2 -> V_15 + V_80 ) ;
else
V_79 = F_19 ( V_2 -> V_15 + V_80 ) ;
if ( ! V_79 )
return;
F_50 ( V_2 -> V_34 , L_5 ,
( V_79 >> 24 ) & 0xff , ( V_79 >> 16 ) & 0xff , ( V_79 >> 8 ) & 0xff ) ;
if ( V_2 -> V_22 == V_24 )
V_79 = F_22 ( V_2 -> V_15 + V_81 ) ;
else
V_79 = F_19 ( V_2 -> V_15 + V_81 ) ;
if ( ! V_79 )
return;
if ( V_79 & V_82 ) {
V_2 -> type = V_83 ;
V_2 -> V_65 |= V_68 ;
V_2 -> V_84 = F_51 ( V_79 ) ;
V_12 -> V_49 = V_85 ;
}
if ( V_79 & V_86 )
V_12 -> V_49 |= V_87 ;
if ( V_79 & V_88 )
V_12 -> V_49 |= V_50 ;
}
static int F_52 ( struct V_89 * V_90 )
{
struct V_11 V_91 = {} ;
struct V_92 * V_93 = F_53 ( V_90 , V_74 , 0 ) ;
int V_94 = F_54 ( V_90 , 0 ) ;
struct V_1 * V_2 = & V_91 . V_31 ;
struct V_58 * V_34 = & V_90 -> V_34 ;
struct V_5 * V_60 ;
int V_95 ;
T_2 V_96 ;
if ( ! V_93 ) {
F_55 ( V_34 , L_6 ) ;
return - V_97 ;
}
if ( V_94 < 0 ) {
if ( V_94 != - V_98 )
F_55 ( V_34 , L_7 ) ;
return V_94 ;
}
F_56 ( & V_2 -> V_99 ) ;
V_2 -> V_100 = V_93 -> V_101 ;
V_2 -> V_94 = V_94 ;
V_2 -> V_102 = F_23 ;
V_2 -> V_103 = F_25 ;
V_2 -> type = V_104 ;
V_2 -> V_65 = V_67 | V_105 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_22 = V_106 ;
V_2 -> V_13 = F_12 ;
V_2 -> V_54 = F_11 ;
V_2 -> V_107 = F_37 ;
V_2 -> V_15 = F_57 ( V_34 , V_93 -> V_101 , F_58 ( V_93 ) ) ;
if ( ! V_2 -> V_15 )
return - V_108 ;
V_60 = F_59 ( V_34 , sizeof( * V_60 ) , V_109 ) ;
if ( ! V_60 )
return - V_108 ;
V_60 -> V_75 . V_78 = F_39 ;
V_60 -> V_30 = V_110 ;
V_2 -> V_7 = V_60 ;
V_60 -> V_25 = F_60 ( V_34 ,
L_8 ) ;
V_95 = F_61 ( V_34 , L_9 , & V_96 ) ;
if ( ! V_95 )
V_2 -> V_17 = V_96 ;
V_95 = F_61 ( V_34 , L_10 , & V_96 ) ;
if ( ! V_95 && V_96 == 4 ) {
V_2 -> V_22 = V_23 ;
V_2 -> V_13 = F_18 ;
V_2 -> V_54 = F_17 ;
}
if ( F_60 ( V_34 , L_11 ) ) {
V_60 -> V_9 |= V_111 ;
V_60 -> V_10 |= V_112 ;
}
if ( F_60 ( V_34 , L_12 ) ) {
V_60 -> V_9 |= V_113 ;
V_60 -> V_10 |= V_114 ;
}
if ( F_60 ( V_34 , L_13 ) ) {
V_60 -> V_9 |= V_115 ;
V_60 -> V_10 |= V_116 ;
}
if ( F_60 ( V_34 , L_14 ) ) {
V_60 -> V_10 |= V_117 ;
V_60 -> V_10 |= V_118 ;
}
F_61 ( V_34 , L_15 , & V_2 -> V_42 ) ;
V_60 -> V_40 = F_62 ( V_34 , L_16 ) ;
if ( F_31 ( V_60 -> V_40 ) && F_63 ( V_60 -> V_40 ) != - V_98 )
V_60 -> V_40 = F_62 ( V_34 , NULL ) ;
if ( F_31 ( V_60 -> V_40 ) && F_63 ( V_60 -> V_40 ) == - V_98 )
return - V_98 ;
if ( ! F_64 ( V_60 -> V_40 ) ) {
V_95 = F_35 ( V_60 -> V_40 ) ;
if ( V_95 )
F_65 ( V_34 , L_17 ,
V_95 ) ;
else
V_2 -> V_42 = F_66 ( V_60 -> V_40 ) ;
}
if ( ! V_2 -> V_42 ) {
F_55 ( V_34 , L_18 ) ;
return - V_97 ;
}
V_60 -> V_119 = F_62 ( V_34 , L_19 ) ;
if ( F_31 ( V_60 -> V_119 ) && F_63 ( V_60 -> V_119 ) == - V_98 ) {
V_95 = - V_98 ;
goto V_120;
}
if ( ! F_31 ( V_60 -> V_119 ) ) {
V_95 = F_35 ( V_60 -> V_119 ) ;
if ( V_95 ) {
F_55 ( V_34 , L_20 ) ;
goto V_120;
}
}
V_60 -> V_121 = F_67 ( V_34 , NULL ) ;
if ( F_31 ( V_60 -> V_121 ) && F_63 ( V_60 -> V_121 ) == - V_98 ) {
V_95 = - V_98 ;
goto V_122;
}
if ( ! F_31 ( V_60 -> V_121 ) )
F_68 ( V_60 -> V_121 ) ;
F_41 ( V_2 , V_60 ) ;
if ( V_60 -> V_25 )
V_2 -> V_102 = NULL ;
if ( ! V_60 -> V_69 )
F_49 ( V_2 ) ;
if ( V_2 -> V_84 ) {
V_60 -> V_75 . V_123 . V_124 = V_2 -> V_84 / 4 ;
V_60 -> V_75 . V_125 . V_126 = V_2 -> V_84 / 4 ;
V_91 . V_75 = & V_60 -> V_75 ;
}
V_60 -> line = F_69 ( & V_91 ) ;
if ( V_60 -> line < 0 ) {
V_95 = V_60 -> line ;
goto V_127;
}
F_70 ( V_90 , V_60 ) ;
F_71 ( V_34 ) ;
F_72 ( V_34 ) ;
return 0 ;
V_127:
if ( ! F_31 ( V_60 -> V_121 ) )
F_73 ( V_60 -> V_121 ) ;
V_122:
if ( ! F_31 ( V_60 -> V_119 ) )
F_32 ( V_60 -> V_119 ) ;
V_120:
if ( ! F_31 ( V_60 -> V_40 ) )
F_32 ( V_60 -> V_40 ) ;
return V_95 ;
}
static int F_74 ( struct V_89 * V_90 )
{
struct V_5 * V_60 = F_75 ( V_90 ) ;
F_26 ( & V_90 -> V_34 ) ;
F_76 ( V_60 -> line ) ;
if ( ! F_31 ( V_60 -> V_121 ) )
F_73 ( V_60 -> V_121 ) ;
if ( ! F_31 ( V_60 -> V_119 ) )
F_32 ( V_60 -> V_119 ) ;
if ( ! F_31 ( V_60 -> V_40 ) )
F_32 ( V_60 -> V_40 ) ;
F_77 ( & V_90 -> V_34 ) ;
F_78 ( & V_90 -> V_34 ) ;
return 0 ;
}
static int F_79 ( struct V_58 * V_34 )
{
struct V_5 * V_60 = F_80 ( V_34 ) ;
F_81 ( V_60 -> line ) ;
return 0 ;
}
static int F_82 ( struct V_58 * V_34 )
{
struct V_5 * V_60 = F_80 ( V_34 ) ;
F_83 ( V_60 -> line ) ;
return 0 ;
}
static int F_84 ( struct V_58 * V_34 )
{
struct V_5 * V_60 = F_80 ( V_34 ) ;
if ( ! F_31 ( V_60 -> V_40 ) )
F_32 ( V_60 -> V_40 ) ;
if ( ! F_31 ( V_60 -> V_119 ) )
F_32 ( V_60 -> V_119 ) ;
return 0 ;
}
static int F_85 ( struct V_58 * V_34 )
{
struct V_5 * V_60 = F_80 ( V_34 ) ;
if ( ! F_31 ( V_60 -> V_119 ) )
F_35 ( V_60 -> V_119 ) ;
if ( ! F_31 ( V_60 -> V_40 ) )
F_35 ( V_60 -> V_40 ) ;
return 0 ;
}
