static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
T_1 V_5 ;
F_4 ( & V_3 -> V_6 ) ;
if ( V_3 -> V_7 ++ > 0 )
goto V_8;
V_5 = F_5 ( V_3 , V_9 ) ;
V_5 &= ~ V_10 ;
F_6 ( V_3 , V_5 , V_9 ) ;
F_7 ( 100 , 200 ) ;
V_5 = F_5 ( V_3 , V_9 ) ;
V_5 &= ~ V_11 ;
F_6 ( V_3 , V_5 , V_9 ) ;
F_7 ( 100 , 200 ) ;
V_5 = F_5 ( V_3 , V_9 ) ;
V_5 &= ~ V_12 ;
F_6 ( V_3 , V_5 , V_9 ) ;
V_8:
F_8 ( & V_3 -> V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 )
{
T_1 V_5 ;
F_4 ( & V_3 -> V_6 ) ;
if ( F_10 ( V_3 -> V_7 == 0 ) )
goto V_8;
if ( -- V_3 -> V_7 > 0 )
goto V_8;
V_5 = F_5 ( V_3 , V_9 ) ;
V_5 |= V_12 ;
F_6 ( V_3 , V_5 , V_9 ) ;
F_7 ( 100 , 200 ) ;
V_5 = F_5 ( V_3 , V_9 ) ;
V_5 |= V_11 ;
F_6 ( V_3 , V_5 , V_9 ) ;
F_7 ( 100 , 200 ) ;
V_5 = F_5 ( V_3 , V_9 ) ;
V_5 |= V_10 ;
F_6 ( V_3 , V_5 , V_9 ) ;
V_8:
F_8 ( & V_3 -> V_6 ) ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 ,
unsigned int V_13 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
T_1 V_5 , V_18 ;
V_15 = F_12 ( V_3 , V_13 ) ;
if ( ! V_15 )
return - V_19 ;
V_15 -> V_20 = true ;
V_17 = V_15 -> V_4 . V_17 ;
if ( V_17 -> V_21 == V_3 -> V_22 )
V_18 = F_13 ( V_17 -> V_13 ) ;
else
V_18 = V_23 ;
V_5 = F_5 ( V_3 , V_18 ) ;
V_5 &= ~ ( V_24 <<
V_25 ) ;
V_5 |= V_26 <<
V_25 ;
F_6 ( V_3 , V_5 , V_18 ) ;
V_5 = F_5 ( V_3 , V_18 ) >>
V_27 ;
V_15 -> V_28 = V_5 & V_29 ;
V_5 = F_5 ( V_3 , V_18 ) ;
V_5 &= ~ ( V_24 <<
V_25 ) ;
V_5 |= V_30 <<
V_25 ;
F_6 ( V_3 , V_5 , V_18 ) ;
V_5 = F_5 ( V_3 , V_18 ) >>
V_27 ;
V_15 -> V_31 = V_5 & V_32 ;
V_5 = F_5 ( V_3 , F_14 ( V_13 ) ) ;
V_5 &= ~ ( ( V_33 <<
V_34 ) |
( V_35 <<
V_36 ) ) ;
V_5 |= ( V_15 -> V_28 <<
V_34 ) |
( V_15 -> V_31 <<
V_36 ) ;
F_6 ( V_3 , V_5 , F_14 ( V_13 ) ) ;
V_5 = F_5 ( V_3 , V_18 ) ;
V_5 &= ~ ( V_24 <<
V_25 ) ;
V_5 |= V_37 <<
V_25 ;
F_6 ( V_3 , V_5 , V_18 ) ;
V_5 = F_5 ( V_3 , V_18 ) ;
V_5 &= ~ ( V_24 <<
V_25 ) ;
V_5 |= V_38 <<
V_25 ;
F_6 ( V_3 , V_5 , V_18 ) ;
V_5 = F_5 ( V_3 , V_18 ) >>
V_27 ;
V_15 -> V_39 = V_5 &
V_40 ;
V_5 = F_5 ( V_3 , V_18 ) ;
V_5 &= ~ ( V_24 <<
V_25 ) ;
V_5 |= V_41 <<
V_25 ;
F_6 ( V_3 , V_5 , V_18 ) ;
V_5 = F_5 ( V_3 , V_18 ) >>
V_27 ;
V_15 -> V_42 = V_5 &
V_40 ;
V_5 = F_5 ( V_3 , F_15 ( V_13 ) ) ;
V_5 &= ~ ( ( V_43 <<
V_44 ) |
( V_45 <<
V_46 ) ) ;
V_5 |= ( V_15 -> V_39 <<
V_44 ) |
( V_15 -> V_42 <<
V_46 ) ;
F_6 ( V_3 , V_5 , F_15 ( V_13 ) ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 ,
unsigned int V_13 , bool V_47 )
{
T_1 V_5 ;
V_5 = F_5 ( V_3 , F_17 ( V_13 ) ) ;
if ( V_47 )
V_5 |= V_48 |
V_49 ;
else
V_5 &= ~ ( V_48 |
V_49 ) ;
F_6 ( V_3 , V_5 , F_17 ( V_13 ) ) ;
return 0 ;
}
static struct V_16 *
F_18 ( struct V_50 * V_21 , struct V_51 * V_52 ,
unsigned int V_13 )
{
struct V_53 * V_54 ;
int V_55 ;
V_54 = F_19 ( sizeof( * V_54 ) , V_56 ) ;
if ( ! V_54 )
return F_20 ( - V_57 ) ;
F_21 ( & V_54 -> V_4 . V_58 ) ;
V_54 -> V_4 . V_59 = & V_21 -> V_59 -> V_60 [ V_13 ] ;
V_54 -> V_4 . V_13 = V_13 ;
V_54 -> V_4 . V_21 = V_21 ;
V_54 -> V_4 . V_52 = V_52 ;
V_55 = F_22 ( & V_54 -> V_4 , V_52 ) ;
if ( V_55 < 0 ) {
F_23 ( V_54 ) ;
return F_20 ( V_55 ) ;
}
return & V_54 -> V_4 ;
}
static void F_24 ( struct V_16 * V_17 )
{
struct V_53 * V_54 = F_25 ( V_17 ) ;
F_23 ( V_54 ) ;
}
static int F_26 ( struct V_61 * V_61 )
{
struct V_16 * V_17 = F_27 ( V_61 ) ;
return F_3 ( V_17 -> V_21 -> V_3 ) ;
}
static int F_28 ( struct V_61 * V_61 )
{
struct V_16 * V_17 = F_27 ( V_61 ) ;
return F_9 ( V_17 -> V_21 -> V_3 ) ;
}
static int F_29 ( struct V_61 * V_61 )
{
struct V_16 * V_17 = F_27 ( V_61 ) ;
struct V_53 * V_54 = F_25 ( V_17 ) ;
struct V_62 * V_21 = F_30 ( V_17 -> V_21 ) ;
struct V_2 * V_3 = V_17 -> V_21 -> V_3 ;
struct V_1 * V_63 ;
struct V_64 * V_15 ;
unsigned int V_13 = V_17 -> V_13 ;
T_1 V_5 ;
int V_55 ;
V_15 = F_31 ( V_3 , V_13 ) ;
if ( ! V_15 ) {
F_32 ( & V_61 -> V_65 , L_1 , V_13 ) ;
return - V_19 ;
}
V_63 = F_1 ( V_3 ) ;
V_5 = F_5 ( V_3 , V_66 ) ;
V_5 &= ~ ( ( V_67 <<
V_68 ) |
( V_69 <<
V_70 ) ) ;
V_5 |= ( V_63 -> V_71 . V_72 <<
V_68 ) |
( V_73 <<
V_70 ) ;
F_6 ( V_3 , V_5 , V_66 ) ;
V_5 = F_5 ( V_3 , V_74 ) ;
V_5 &= ~ ( V_75 <<
F_33 ( V_13 ) ) ;
V_5 |= V_76 <<
F_33 ( V_13 ) ;
F_6 ( V_3 , V_5 , V_74 ) ;
V_5 = F_5 ( V_3 , F_34 ( V_13 ) ) ;
V_5 &= ~ ( ( V_77 <<
V_78 ) |
( V_79 <<
V_80 ) |
( V_81 <<
V_82 ) |
V_83 |
V_84 |
V_85 ) ;
V_5 |= ( V_63 -> V_71 . V_86 [ V_13 ] +
V_54 -> V_87 ) <<
V_78 ;
V_5 |= V_88 <<
V_80 ;
V_5 |= F_35 ( V_13 ) <<
V_82 ;
F_6 ( V_3 , V_5 , F_34 ( V_13 ) ) ;
V_5 = F_5 ( V_3 , F_36 ( V_13 ) ) ;
V_5 &= ~ ( ( V_89 <<
V_90 ) |
( V_91 <<
V_92 ) |
V_93 |
V_94 |
V_95 ) ;
V_5 |= ( V_63 -> V_71 . V_96 <<
V_90 ) |
( V_63 -> V_71 . V_97 <<
V_92 ) ;
F_6 ( V_3 , V_5 , F_36 ( V_13 ) ) ;
V_55 = F_37 ( V_15 -> V_98 ) ;
if ( V_55 )
return V_55 ;
F_4 ( & V_21 -> V_6 ) ;
if ( V_21 -> V_7 ++ > 0 )
goto V_8;
V_5 = F_5 ( V_3 , V_66 ) ;
V_5 &= ~ V_99 ;
F_6 ( V_3 , V_5 , V_66 ) ;
V_8:
F_8 ( & V_21 -> V_6 ) ;
return 0 ;
}
static int F_38 ( struct V_61 * V_61 )
{
struct V_16 * V_17 = F_27 ( V_61 ) ;
struct V_62 * V_21 = F_30 ( V_17 -> V_21 ) ;
struct V_2 * V_3 = V_17 -> V_21 -> V_3 ;
struct V_64 * V_15 ;
T_1 V_5 ;
V_15 = F_31 ( V_3 , V_17 -> V_13 ) ;
if ( ! V_15 ) {
F_32 ( & V_61 -> V_65 , L_1 ,
V_17 -> V_13 ) ;
return - V_19 ;
}
F_4 ( & V_21 -> V_6 ) ;
if ( F_10 ( V_21 -> V_7 == 0 ) )
goto V_8;
if ( -- V_21 -> V_7 > 0 )
goto V_8;
V_5 = F_5 ( V_3 , V_66 ) ;
V_5 |= V_99 ;
F_6 ( V_3 , V_5 , V_66 ) ;
V_8:
F_39 ( V_15 -> V_98 ) ;
F_8 ( & V_21 -> V_6 ) ;
return 0 ;
}
static struct V_50 *
F_40 ( struct V_2 * V_3 ,
const struct V_100 * V_59 ,
struct V_51 * V_52 )
{
struct V_62 * V_54 ;
struct V_50 * V_21 ;
int V_55 ;
V_54 = F_19 ( sizeof( * V_54 ) , V_56 ) ;
if ( ! V_54 )
return F_20 ( - V_57 ) ;
F_41 ( & V_54 -> V_6 ) ;
V_21 = & V_54 -> V_4 ;
V_21 -> V_101 = & V_102 ;
V_21 -> V_59 = V_59 ;
V_55 = F_42 ( V_21 , V_3 , V_52 ) ;
if ( V_55 < 0 ) {
F_23 ( V_54 ) ;
goto V_8;
}
V_55 = F_43 ( V_21 , & V_103 ) ;
if ( V_55 < 0 )
goto V_104;
F_44 ( & V_21 -> V_65 , V_21 ) ;
return V_21 ;
V_104:
F_45 ( & V_21 -> V_65 ) ;
V_8:
return F_20 ( V_55 ) ;
}
static void F_46 ( struct V_50 * V_21 )
{
struct V_62 * V_54 = F_30 ( V_21 ) ;
F_23 ( V_54 ) ;
}
static struct V_16 *
F_47 ( struct V_50 * V_21 , struct V_51 * V_52 ,
unsigned int V_13 )
{
struct V_105 * V_106 ;
int V_55 ;
V_106 = F_19 ( sizeof( * V_106 ) , V_56 ) ;
if ( ! V_106 )
return F_20 ( - V_57 ) ;
F_21 ( & V_106 -> V_4 . V_58 ) ;
V_106 -> V_4 . V_59 = & V_21 -> V_59 -> V_60 [ V_13 ] ;
V_106 -> V_4 . V_13 = V_13 ;
V_106 -> V_4 . V_21 = V_21 ;
V_106 -> V_4 . V_52 = V_52 ;
V_55 = F_22 ( & V_106 -> V_4 , V_52 ) ;
if ( V_55 < 0 ) {
F_23 ( V_106 ) ;
return F_20 ( V_55 ) ;
}
return & V_106 -> V_4 ;
}
static void F_48 ( struct V_16 * V_17 )
{
struct V_105 * V_106 = F_49 ( V_17 ) ;
F_23 ( V_106 ) ;
}
static int F_50 ( struct V_61 * V_61 )
{
struct V_16 * V_17 = F_27 ( V_61 ) ;
return F_3 ( V_17 -> V_21 -> V_3 ) ;
}
static int F_51 ( struct V_61 * V_61 )
{
struct V_16 * V_17 = F_27 ( V_61 ) ;
return F_9 ( V_17 -> V_21 -> V_3 ) ;
}
static int F_52 ( struct V_61 * V_61 )
{
return 0 ;
}
static int F_53 ( struct V_61 * V_61 )
{
return 0 ;
}
static struct V_50 *
F_54 ( struct V_2 * V_3 ,
const struct V_100 * V_59 ,
struct V_51 * V_52 )
{
struct V_107 * V_106 ;
struct V_50 * V_21 ;
int V_55 ;
V_106 = F_19 ( sizeof( * V_106 ) , V_56 ) ;
if ( ! V_106 )
return F_20 ( - V_57 ) ;
V_21 = & V_106 -> V_4 ;
V_21 -> V_101 = & V_108 ;
V_21 -> V_59 = V_59 ;
V_55 = F_42 ( V_21 , V_3 , V_52 ) ;
if ( V_55 < 0 ) {
F_23 ( V_106 ) ;
goto V_8;
}
V_55 = F_43 ( V_21 , & V_109 ) ;
if ( V_55 < 0 )
goto V_104;
F_44 ( & V_21 -> V_65 , V_21 ) ;
return V_21 ;
V_104:
F_45 ( & V_21 -> V_65 ) ;
V_8:
return F_20 ( V_55 ) ;
}
static void F_55 ( struct V_50 * V_21 )
{
struct V_107 * V_106 = F_56 ( V_21 ) ;
F_23 ( V_106 ) ;
}
static struct V_16 *
F_57 ( struct V_50 * V_21 , struct V_51 * V_52 ,
unsigned int V_13 )
{
struct V_110 * V_111 ;
int V_55 ;
V_111 = F_19 ( sizeof( * V_111 ) , V_56 ) ;
if ( ! V_111 )
return F_20 ( - V_57 ) ;
F_21 ( & V_111 -> V_4 . V_58 ) ;
V_111 -> V_4 . V_59 = & V_21 -> V_59 -> V_60 [ V_13 ] ;
V_111 -> V_4 . V_13 = V_13 ;
V_111 -> V_4 . V_21 = V_21 ;
V_111 -> V_4 . V_52 = V_52 ;
V_55 = F_22 ( & V_111 -> V_4 , V_52 ) ;
if ( V_55 < 0 ) {
F_23 ( V_111 ) ;
return F_20 ( V_55 ) ;
}
return & V_111 -> V_4 ;
}
static void F_58 ( struct V_16 * V_17 )
{
struct V_110 * V_111 = F_59 ( V_17 ) ;
F_23 ( V_111 ) ;
}
static int F_60 ( struct V_61 * V_61 )
{
struct V_16 * V_17 = F_27 ( V_61 ) ;
return F_3 ( V_17 -> V_21 -> V_3 ) ;
}
static int F_61 ( struct V_61 * V_61 )
{
struct V_16 * V_17 = F_27 ( V_61 ) ;
return F_9 ( V_17 -> V_21 -> V_3 ) ;
}
static int F_62 ( struct V_61 * V_61 )
{
struct V_16 * V_17 = F_27 ( V_61 ) ;
struct V_110 * V_111 = F_59 ( V_17 ) ;
struct V_112 * V_21 = F_63 ( V_17 -> V_21 ) ;
struct V_2 * V_3 = V_17 -> V_21 -> V_3 ;
unsigned int V_13 = V_17 -> V_13 ;
T_1 V_5 ;
int V_55 ;
V_55 = F_37 ( V_21 -> V_98 ) ;
if ( V_55 )
return V_55 ;
F_6 ( V_3 , V_111 -> V_113 ,
V_114 ) ;
V_5 = F_5 ( V_3 , F_17 ( V_13 ) ) ;
if ( V_111 -> V_115 )
V_5 |= V_116 ;
else
V_5 &= ~ V_116 ;
F_6 ( V_3 , V_5 , F_17 ( V_13 ) ) ;
V_5 = F_5 ( V_3 , F_64 ( V_13 ) ) ;
V_5 &= ~ ( ( V_117 <<
V_118 ) |
( V_119 <<
V_120 ) |
( V_121 <<
V_122 ) |
( V_123 <<
V_124 ) ) ;
V_5 |= ( V_111 -> V_125 <<
V_118 ) |
( V_111 -> V_126 <<
V_120 ) |
( V_111 -> V_127 <<
V_122 ) |
( V_111 -> V_128 <<
V_124 ) ;
F_6 ( V_3 , V_5 , F_64 ( V_13 ) ) ;
V_5 = F_5 ( V_3 , F_65 ( V_13 ) ) ;
V_5 &= ~ ( ( V_129 <<
V_130 ) |
( V_131 <<
V_132 ) ) ;
V_5 |= ( V_111 -> V_133 <<
V_130 ) |
( V_111 -> V_134 <<
V_132 ) ;
F_6 ( V_3 , V_5 , F_65 ( V_13 ) ) ;
V_5 = F_5 ( V_3 , F_17 ( V_13 ) ) ;
V_5 &= ~ ( V_135 |
V_136 |
V_137 |
V_138 |
V_139 |
V_140 ) ;
V_5 |= V_48 |
V_49 ;
F_6 ( V_3 , V_5 , F_17 ( V_13 ) ) ;
return 0 ;
}
static int F_66 ( struct V_61 * V_61 )
{
struct V_16 * V_17 = F_27 ( V_61 ) ;
struct V_112 * V_21 = F_63 ( V_17 -> V_21 ) ;
struct V_2 * V_3 = V_17 -> V_21 -> V_3 ;
unsigned int V_13 = V_17 -> V_13 ;
T_1 V_5 ;
V_5 = F_5 ( V_3 , F_17 ( V_13 ) ) ;
V_5 |= V_137 |
V_138 |
V_139 |
V_140 ;
F_6 ( V_3 , V_5 , F_17 ( V_13 ) ) ;
F_39 ( V_21 -> V_98 ) ;
return 0 ;
}
static struct V_50 *
F_67 ( struct V_2 * V_3 ,
const struct V_100 * V_59 ,
struct V_51 * V_52 )
{
struct V_112 * V_111 ;
struct V_50 * V_21 ;
int V_55 ;
V_111 = F_19 ( sizeof( * V_111 ) , V_56 ) ;
if ( ! V_111 )
return F_20 ( - V_57 ) ;
V_21 = & V_111 -> V_4 ;
V_21 -> V_101 = & V_141 ;
V_21 -> V_59 = V_59 ;
V_55 = F_42 ( V_21 , V_3 , V_52 ) ;
if ( V_55 < 0 ) {
F_23 ( V_111 ) ;
goto V_8;
}
V_55 = F_43 ( V_21 , & V_142 ) ;
if ( V_55 < 0 )
goto V_104;
F_44 ( & V_21 -> V_65 , V_21 ) ;
return V_21 ;
V_104:
F_45 ( & V_21 -> V_65 ) ;
V_8:
return F_20 ( V_55 ) ;
}
static void F_68 ( struct V_50 * V_21 )
{
struct V_112 * V_111 = F_63 ( V_21 ) ;
F_23 ( V_111 ) ;
}
static struct V_16 *
F_69 ( struct V_50 * V_21 , struct V_51 * V_52 ,
unsigned int V_13 )
{
struct V_143 * V_22 ;
int V_55 ;
V_22 = F_19 ( sizeof( * V_22 ) , V_56 ) ;
if ( ! V_22 )
return F_20 ( - V_57 ) ;
F_21 ( & V_22 -> V_4 . V_58 ) ;
V_22 -> V_4 . V_59 = & V_21 -> V_59 -> V_60 [ V_13 ] ;
V_22 -> V_4 . V_13 = V_13 ;
V_22 -> V_4 . V_21 = V_21 ;
V_22 -> V_4 . V_52 = V_52 ;
V_55 = F_22 ( & V_22 -> V_4 , V_52 ) ;
if ( V_55 < 0 ) {
F_23 ( V_22 ) ;
return F_20 ( V_55 ) ;
}
return & V_22 -> V_4 ;
}
static void F_70 ( struct V_16 * V_17 )
{
struct V_143 * V_22 = F_71 ( V_17 ) ;
F_23 ( V_22 ) ;
}
static int F_72 ( struct V_61 * V_61 )
{
struct V_16 * V_17 = F_27 ( V_61 ) ;
return F_3 ( V_17 -> V_21 -> V_3 ) ;
}
static int F_73 ( struct V_61 * V_61 )
{
struct V_16 * V_17 = F_27 ( V_61 ) ;
return F_9 ( V_17 -> V_21 -> V_3 ) ;
}
static int F_74 ( struct V_61 * V_61 )
{
struct V_16 * V_17 = F_27 ( V_61 ) ;
struct V_2 * V_3 = V_17 -> V_21 -> V_3 ;
unsigned long V_144 ;
int V_55 = - V_145 ;
T_1 V_5 ;
V_5 = F_5 ( V_3 , V_146 ) ;
V_5 &= ~ V_147 ;
F_6 ( V_3 , V_5 , V_146 ) ;
V_5 = F_5 ( V_3 , V_148 ) ;
V_5 |= V_149 |
V_150 |
V_151 ;
F_6 ( V_3 , V_5 , V_148 ) ;
V_5 = F_5 ( V_3 , V_146 ) ;
V_5 |= V_152 ;
F_6 ( V_3 , V_5 , V_146 ) ;
V_144 = V_153 + F_75 ( 50 ) ;
while ( F_76 ( V_153 , V_144 ) ) {
V_5 = F_5 ( V_3 , V_146 ) ;
if ( V_5 & V_154 ) {
V_55 = 0 ;
break;
}
F_7 ( 100 , 200 ) ;
}
V_5 = F_5 ( V_3 , V_155 ) ;
V_5 |= F_77 ( V_17 -> V_13 ) ;
F_6 ( V_3 , V_5 , V_155 ) ;
return V_55 ;
}
static int F_78 ( struct V_61 * V_61 )
{
struct V_16 * V_17 = F_27 ( V_61 ) ;
struct V_2 * V_3 = V_17 -> V_21 -> V_3 ;
T_1 V_5 ;
V_5 = F_5 ( V_3 , V_155 ) ;
V_5 &= ~ F_77 ( V_17 -> V_13 ) ;
F_6 ( V_3 , V_5 , V_155 ) ;
V_5 = F_5 ( V_3 , V_146 ) ;
V_5 &= ~ V_152 ;
F_6 ( V_3 , V_5 , V_146 ) ;
return 0 ;
}
static struct V_50 *
F_79 ( struct V_2 * V_3 ,
const struct V_100 * V_59 ,
struct V_51 * V_52 )
{
struct V_156 * V_22 ;
struct V_50 * V_21 ;
int V_55 ;
V_22 = F_19 ( sizeof( * V_22 ) , V_56 ) ;
if ( ! V_22 )
return F_20 ( - V_57 ) ;
V_21 = & V_22 -> V_4 ;
V_21 -> V_101 = & V_157 ;
V_21 -> V_59 = V_59 ;
V_55 = F_42 ( V_21 , V_3 , V_52 ) ;
if ( V_55 < 0 ) {
F_23 ( V_22 ) ;
goto V_8;
}
V_55 = F_43 ( V_21 , & V_158 ) ;
if ( V_55 < 0 )
goto V_104;
F_44 ( & V_21 -> V_65 , V_21 ) ;
return V_21 ;
V_104:
F_45 ( & V_21 -> V_65 ) ;
V_8:
return F_20 ( V_55 ) ;
}
static void F_80 ( struct V_50 * V_21 )
{
struct V_156 * V_22 = F_81 ( V_21 ) ;
F_23 ( V_22 ) ;
}
static struct V_16 *
F_82 ( struct V_50 * V_21 , struct V_51 * V_52 ,
unsigned int V_13 )
{
struct V_159 * V_160 ;
int V_55 ;
V_160 = F_19 ( sizeof( * V_160 ) , V_56 ) ;
if ( ! V_160 )
return F_20 ( - V_57 ) ;
F_21 ( & V_160 -> V_4 . V_58 ) ;
V_160 -> V_4 . V_59 = & V_21 -> V_59 -> V_60 [ V_13 ] ;
V_160 -> V_4 . V_13 = V_13 ;
V_160 -> V_4 . V_21 = V_21 ;
V_160 -> V_4 . V_52 = V_52 ;
V_55 = F_22 ( & V_160 -> V_4 , V_52 ) ;
if ( V_55 < 0 ) {
F_23 ( V_160 ) ;
return F_20 ( V_55 ) ;
}
return & V_160 -> V_4 ;
}
static void F_83 ( struct V_16 * V_17 )
{
struct V_159 * V_160 = F_84 ( V_17 ) ;
F_23 ( V_160 ) ;
}
static int F_85 ( struct V_61 * V_61 )
{
struct V_16 * V_17 = F_27 ( V_61 ) ;
return F_3 ( V_17 -> V_21 -> V_3 ) ;
}
static int F_86 ( struct V_61 * V_61 )
{
struct V_16 * V_17 = F_27 ( V_61 ) ;
return F_9 ( V_17 -> V_21 -> V_3 ) ;
}
static int F_87 ( struct V_61 * V_61 )
{
struct V_16 * V_17 = F_27 ( V_61 ) ;
struct V_2 * V_3 = V_17 -> V_21 -> V_3 ;
unsigned long V_144 ;
int V_55 = - V_145 ;
T_1 V_5 ;
V_5 = F_5 ( V_3 , V_161 ) ;
V_5 &= ~ V_162 ;
V_5 &= ~ V_163 ;
F_6 ( V_3 , V_5 , V_161 ) ;
V_5 = F_5 ( V_3 , V_164 ) ;
V_5 &= ~ V_165 ;
V_5 &= ~ V_166 ;
F_6 ( V_3 , V_5 , V_164 ) ;
V_5 = F_5 ( V_3 , V_164 ) ;
V_5 |= V_167 ;
F_6 ( V_3 , V_5 , V_164 ) ;
V_5 = F_5 ( V_3 , V_164 ) ;
V_5 |= V_168 ;
F_6 ( V_3 , V_5 , V_164 ) ;
V_144 = V_153 + F_75 ( 50 ) ;
while ( F_76 ( V_153 , V_144 ) ) {
V_5 = F_5 ( V_3 , V_164 ) ;
if ( V_5 & V_169 ) {
V_55 = 0 ;
break;
}
F_7 ( 100 , 200 ) ;
}
V_5 = F_5 ( V_3 , V_155 ) ;
V_5 |= F_88 ( V_17 -> V_13 ) ;
F_6 ( V_3 , V_5 , V_155 ) ;
return V_55 ;
}
static int F_89 ( struct V_61 * V_61 )
{
struct V_16 * V_17 = F_27 ( V_61 ) ;
struct V_2 * V_3 = V_17 -> V_21 -> V_3 ;
T_1 V_5 ;
V_5 = F_5 ( V_3 , V_155 ) ;
V_5 &= ~ F_88 ( V_17 -> V_13 ) ;
F_6 ( V_3 , V_5 , V_155 ) ;
V_5 = F_5 ( V_3 , V_164 ) ;
V_5 &= ~ V_168 ;
F_6 ( V_3 , V_5 , V_164 ) ;
V_5 = F_5 ( V_3 , V_164 ) ;
V_5 &= ~ V_167 ;
F_6 ( V_3 , V_5 , V_164 ) ;
V_5 = F_5 ( V_3 , V_164 ) ;
V_5 |= V_165 ;
V_5 |= V_166 ;
F_6 ( V_3 , V_5 , V_164 ) ;
V_5 = F_5 ( V_3 , V_161 ) ;
V_5 |= ~ V_162 ;
V_5 |= ~ V_163 ;
F_6 ( V_3 , V_5 , V_161 ) ;
return 0 ;
}
static struct V_50 *
F_90 ( struct V_2 * V_3 ,
const struct V_100 * V_59 ,
struct V_51 * V_52 )
{
struct V_170 * V_160 ;
struct V_50 * V_21 ;
int V_55 ;
V_160 = F_19 ( sizeof( * V_160 ) , V_56 ) ;
if ( ! V_160 )
return F_20 ( - V_57 ) ;
V_21 = & V_160 -> V_4 ;
V_21 -> V_101 = & V_171 ;
V_21 -> V_59 = V_59 ;
V_55 = F_42 ( V_21 , V_3 , V_52 ) ;
if ( V_55 < 0 ) {
F_23 ( V_160 ) ;
goto V_8;
}
V_55 = F_43 ( V_21 , & V_172 ) ;
if ( V_55 < 0 )
goto V_104;
F_44 ( & V_21 -> V_65 , V_21 ) ;
return V_21 ;
V_104:
F_45 ( & V_21 -> V_65 ) ;
V_8:
return F_20 ( V_55 ) ;
}
static void F_91 ( struct V_50 * V_21 )
{
struct V_170 * V_160 = F_92 ( V_21 ) ;
F_23 ( V_160 ) ;
}
static int F_93 ( struct V_173 * V_15 )
{
return 0 ;
}
static void F_94 ( struct V_173 * V_15 )
{
}
static struct V_16 *
F_95 ( struct V_173 * V_15 )
{
return F_96 ( V_15 -> V_3 , L_2 , V_15 -> V_13 ) ;
}
static int F_97 ( struct V_173 * V_15 )
{
return 0 ;
}
static void F_98 ( struct V_173 * V_15 )
{
}
static struct V_16 *
F_99 ( struct V_173 * V_15 )
{
return F_96 ( V_15 -> V_3 , L_3 , V_15 -> V_13 ) ;
}
static int F_100 ( struct V_173 * V_15 )
{
return 0 ;
}
static void F_101 ( struct V_173 * V_15 )
{
}
static struct V_16 *
F_102 ( struct V_173 * V_15 )
{
return F_96 ( V_15 -> V_3 , L_4 , V_15 -> V_13 ) ;
}
static int F_103 ( struct V_173 * V_15 )
{
struct V_14 * V_174 = F_104 ( V_15 ) ;
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_16 * V_17 = V_174 -> V_4 . V_17 ;
unsigned int V_13 = V_15 -> V_13 , V_18 ;
int V_175 = 0 ;
T_1 V_5 ;
V_5 = F_5 ( V_3 , V_176 ) ;
if ( ! V_174 -> V_177 )
V_5 &= ~ F_105 ( V_13 ) ;
else
V_5 |= F_105 ( V_13 ) ;
V_5 &= ~ F_106 ( V_13 ) ;
V_5 |= F_107 ( V_13 , V_174 -> V_15 ) ;
F_6 ( V_3 , V_5 , V_176 ) ;
V_5 = F_5 ( V_3 , F_15 ( V_13 ) ) ;
V_5 &= ~ ( ( V_178 <<
V_179 ) |
( V_180 <<
V_181 ) |
( V_182 <<
V_183 ) ) ;
V_5 |= ( V_184 <<
V_179 ) |
( V_185 <<
V_183 ) |
( V_186 <<
V_181 ) ;
if ( V_174 -> V_20 ) {
V_5 &= ~ ( ( V_43 <<
V_44 ) |
( V_45 <<
V_46 ) ) ;
V_5 |= ( V_174 -> V_39 <<
V_44 ) |
( V_174 -> V_42 <<
V_46 ) ;
}
F_6 ( V_3 , V_5 , F_15 ( V_13 ) ) ;
V_5 = V_187 ;
if ( V_174 -> V_20 ) {
V_5 &= ~ ( ( V_33 <<
V_34 ) |
( V_35 <<
V_36 ) ) ;
V_5 |= ( V_174 -> V_28 <<
V_34 ) |
( V_174 -> V_31 <<
V_36 ) ;
}
F_6 ( V_3 , V_5 , F_14 ( V_13 ) ) ;
if ( V_17 -> V_21 == V_3 -> V_22 )
V_18 = F_108 ( V_17 -> V_13 ) ;
else
V_18 = V_188 ;
V_5 = F_5 ( V_3 , V_18 ) ;
V_5 &= ~ ( V_189 <<
V_190 ) ;
V_5 |= V_191 <<
V_190 ;
F_6 ( V_3 , V_5 , V_18 ) ;
if ( V_17 -> V_21 == V_3 -> V_22 )
V_18 = F_109 ( V_17 -> V_13 ) ;
else
V_18 = V_192 ;
V_5 = F_5 ( V_3 , V_18 ) ;
V_5 |= V_193 ;
F_6 ( V_3 , V_5 , V_18 ) ;
if ( V_17 -> V_21 == V_3 -> V_160 ) {
V_5 = F_5 ( V_3 , V_164 ) ;
V_5 &= ~ ( V_194 <<
V_195 ) ;
V_5 |= 0x2 <<
V_195 ;
F_6 ( V_3 , V_5 , V_164 ) ;
V_5 = F_5 ( V_3 , V_196 ) ;
V_5 &= ~ ( ( V_197 <<
V_198 ) |
( V_199 <<
V_200 ) |
( V_201 <<
V_202 ) |
V_203 ) ;
V_5 |= ( 0x7 <<
V_198 ) |
( 0x8 <<
V_200 ) |
( 0x8 <<
V_202 ) |
V_204 ;
F_6 ( V_3 , V_5 , V_196 ) ;
V_5 = F_5 ( V_3 , V_205 ) ;
V_5 &= ~ V_206 ;
F_6 ( V_3 , V_5 , V_205 ) ;
}
V_5 = F_5 ( V_3 , V_9 ) ;
V_5 &= ~ F_110 ( V_13 ) ;
F_6 ( V_3 , V_5 , V_9 ) ;
F_7 ( 100 , 200 ) ;
V_5 = F_5 ( V_3 , V_9 ) ;
V_5 &= ~ F_111 ( V_13 ) ;
F_6 ( V_3 , V_5 , V_9 ) ;
F_7 ( 100 , 200 ) ;
V_5 = F_5 ( V_3 , V_9 ) ;
V_5 &= ~ F_112 ( V_13 ) ;
F_6 ( V_3 , V_5 , V_9 ) ;
return V_175 ;
}
static void F_113 ( struct V_173 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
T_1 V_5 ;
V_5 = F_5 ( V_3 , V_9 ) ;
V_5 |= F_111 ( V_15 -> V_13 ) ;
F_6 ( V_3 , V_5 , V_9 ) ;
F_7 ( 100 , 200 ) ;
V_5 = F_5 ( V_3 , V_9 ) ;
V_5 |= F_112 ( V_15 -> V_13 ) ;
F_6 ( V_3 , V_5 , V_9 ) ;
F_7 ( 250 , 350 ) ;
V_5 = F_5 ( V_3 , V_9 ) ;
V_5 |= F_110 ( V_15 -> V_13 ) ;
F_6 ( V_3 , V_5 , V_9 ) ;
V_5 = F_5 ( V_3 , V_176 ) ;
V_5 &= ~ F_106 ( V_15 -> V_13 ) ;
V_5 |= F_107 ( V_15 -> V_13 , 0x7 ) ;
F_6 ( V_3 , V_5 , V_176 ) ;
}
static struct V_16 *
F_114 ( struct V_173 * V_15 )
{
return F_115 ( V_15 , V_207 , L_5 ) ;
}
static int
F_116 ( struct V_208 * V_71 )
{
unsigned int V_209 ;
int V_55 ;
T_1 V_5 ;
V_55 = F_117 ( V_210 , & V_5 ) ;
if ( V_55 < 0 )
return V_55 ;
for ( V_209 = 0 ; V_209 < F_118 ( V_71 -> V_86 ) ; V_209 ++ ) {
V_71 -> V_86 [ V_209 ] =
( V_5 >> F_119 ( V_209 ) ) &
V_211 ;
}
V_71 -> V_97 =
( V_5 >> V_212 ) &
V_213 ;
V_71 -> V_96 =
( V_5 >> V_214 ) &
V_215 ;
V_71 -> V_72 =
( V_5 >> V_216 ) &
V_217 ;
return 0 ;
}
static struct V_2 *
F_120 ( struct V_218 * V_65 ,
const struct V_219 * V_59 )
{
struct V_1 * V_3 ;
int V_55 ;
V_3 = F_121 ( V_65 , sizeof( * V_3 ) , V_56 ) ;
if ( ! V_3 )
return F_20 ( - V_57 ) ;
V_3 -> V_4 . V_65 = V_65 ;
V_3 -> V_4 . V_59 = V_59 ;
V_55 = F_116 ( & V_3 -> V_71 ) ;
if ( V_55 < 0 )
return F_20 ( V_55 ) ;
return & V_3 -> V_4 ;
}
static void F_122 ( struct V_2 * V_3 )
{
}
