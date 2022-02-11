static void F_1 ( struct V_1 * V_2 , T_1 V_3 , unsigned long V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , unsigned long V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static unsigned long F_5 ( struct V_1 * V_2 ,
unsigned long V_4 )
{
if ( V_2 -> V_6 )
V_4 += ( V_4 >= V_7 ) ? 0x10 : 0x40 ;
return V_4 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned long V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + F_5 ( V_2 , V_4 ) ) ;
if ( V_4 != V_7 )
F_4 ( V_2 -> V_5 + F_5 ( V_2 , V_4 ) ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , unsigned long V_4 )
{
return F_4 ( V_2 -> V_5 + F_5 ( V_2 , V_4 ) ) ;
}
static void F_8 ( struct V_1 * V_2 , void * V_8 ,
unsigned long V_4 , int V_9 )
{
F_9 ( V_2 -> V_5 + F_5 ( V_2 , V_4 ) , V_8 , V_9 ) ;
}
static void F_10 ( struct V_1 * V_2 , void * V_8 ,
unsigned long V_4 , int V_9 )
{
F_11 ( V_2 -> V_5 + F_5 ( V_2 , V_4 ) , V_8 , V_9 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_10 )
{
T_1 V_11 = F_7 ( V_2 , V_12 ) ;
V_11 &= ~ V_10 ;
F_6 ( V_2 , V_11 , V_12 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_10 )
{
T_1 V_11 = F_7 ( V_2 , V_12 ) ;
V_11 |= V_10 ;
F_6 ( V_2 , V_11 , V_12 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
unsigned long V_13 = V_14 + V_15 ;
T_1 V_3 = F_7 ( V_2 , V_16 ) ;
V_3 |= V_17 | V_18 ;
F_6 ( V_2 , V_3 , V_16 ) ;
while ( F_7 ( V_2 , V_16 ) &
( V_17 | V_18 ) ) {
if ( F_15 ( V_14 , V_13 ) ) {
F_16 ( V_2 -> V_19 , L_1 ) ;
return - V_20 ;
}
F_17 ( 1 ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_21 ;
T_2 * V_22 = V_2 -> V_23 ;
T_3 V_24 = V_2 -> V_25 ;
int V_26 ;
V_3 = F_7 ( V_2 , V_27 ) ;
V_21 = ( V_3 & V_28 ) >>
V_29 ;
V_26 = V_24 / V_30 ;
if ( V_26 > V_21 )
V_26 = V_21 ;
F_10 ( V_2 , V_22 , V_31 , V_26 ) ;
V_22 += V_26 * V_30 ;
V_24 -= V_26 * V_30 ;
V_21 -= V_26 ;
if ( V_21 > 0 && V_24 > 0 ) {
F_19 ( V_24 > 3 ) ;
V_3 = F_7 ( V_2 , V_31 ) ;
memcpy ( V_22 , & V_3 , V_24 ) ;
V_24 = 0 ;
V_21 -- ;
}
F_19 ( V_21 > 0 && V_24 > 0 ) ;
V_2 -> V_25 = V_24 ;
V_2 -> V_23 = V_22 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_32 ;
T_2 * V_22 = V_2 -> V_23 ;
T_3 V_24 = V_2 -> V_25 ;
int V_26 ;
V_3 = F_7 ( V_2 , V_27 ) ;
V_32 = ( V_3 & V_33 ) >>
V_34 ;
V_26 = V_24 / V_30 ;
if ( V_26 ) {
if ( V_26 > V_32 )
V_26 = V_32 ;
V_24 -= V_26 * V_30 ;
V_32 -= V_26 ;
V_2 -> V_25 = V_24 ;
V_2 -> V_23 = V_22 +
V_26 * V_30 ;
F_21 () ;
F_8 ( V_2 , V_22 , V_7 , V_26 ) ;
V_22 += V_26 * V_30 ;
}
if ( V_32 > 0 && V_24 > 0 ) {
F_19 ( V_24 > 3 ) ;
memcpy ( & V_3 , V_22 , V_24 ) ;
V_2 -> V_25 = 0 ;
V_2 -> V_23 = NULL ;
F_21 () ;
F_6 ( V_2 , V_3 , V_7 ) ;
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
V_3 = F_3 ( V_2 , V_35 ) ;
V_3 |= V_36 ;
V_3 |= V_37 ;
F_1 ( V_2 , V_3 , V_35 ) ;
V_3 = F_3 ( V_2 , V_38 ) ;
V_3 |= V_39 ;
F_1 ( V_2 , V_3 , V_38 ) ;
}
static inline int F_23 ( struct V_1 * V_2 )
{
int V_40 ;
if ( ! V_2 -> V_41 -> V_42 ) {
V_40 = F_24 ( V_2 -> V_43 ) ;
if ( V_40 < 0 ) {
F_25 ( V_2 -> V_19 ,
L_2 , V_40 ) ;
return V_40 ;
}
}
V_40 = F_24 ( V_2 -> V_44 ) ;
if ( V_40 < 0 ) {
F_25 ( V_2 -> V_19 ,
L_3 , V_40 ) ;
F_26 ( V_2 -> V_43 ) ;
}
return V_40 ;
}
static inline void F_27 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_44 ) ;
if ( ! V_2 -> V_41 -> V_42 )
F_26 ( V_2 -> V_43 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_45 = 0 ;
int V_46 = V_47 ;
T_1 V_48 ;
V_45 = F_23 ( V_2 ) ;
if ( V_45 < 0 ) {
F_25 ( V_2 -> V_19 , L_4 , V_45 ) ;
return V_45 ;
}
F_29 ( V_2 -> V_44 ) ;
F_30 ( 2 ) ;
F_31 ( V_2 -> V_44 ) ;
if ( V_2 -> V_6 )
F_22 ( V_2 ) ;
V_3 = V_49 | V_50 |
( 0x2 << V_51 ) ;
F_6 ( V_2 , V_3 , V_52 ) ;
F_6 ( V_2 , 0 , V_12 ) ;
V_46 *= ( V_2 -> V_41 -> V_53 + 1 ) ;
F_32 ( V_2 -> V_44 , V_2 -> V_54 * V_46 ) ;
V_48 = V_2 -> V_41 -> V_55 ;
V_48 |= V_2 -> V_41 -> V_53 <<
V_56 ;
F_6 ( V_2 , V_48 , V_57 ) ;
if ( ! V_2 -> V_6 ) {
T_1 V_58 = F_7 ( V_2 , V_59 ) ;
V_58 |= V_60 | V_61 ;
F_6 ( V_2 , V_58 , V_59 ) ;
F_6 ( V_2 , 0xfc , V_62 ) ;
F_6 ( V_2 , 0x00 , V_63 ) ;
}
V_3 = 7 << V_64 |
0 << V_65 ;
F_6 ( V_2 , V_3 , V_16 ) ;
if ( F_14 ( V_2 ) )
V_45 = - V_20 ;
F_27 ( V_2 ) ;
if ( V_2 -> V_66 ) {
V_2 -> V_66 = 0 ;
F_33 ( V_2 -> V_67 ) ;
}
return V_45 ;
}
static T_4 F_34 ( int V_67 , void * V_68 )
{
T_1 V_69 ;
const T_1 V_70 = V_71 | V_72 ;
struct V_1 * V_2 = V_68 ;
V_69 = F_7 ( V_2 , V_73 ) ;
if ( V_69 == 0 ) {
F_16 ( V_2 -> V_19 , L_5 ,
F_7 ( V_2 , V_74 ) ,
F_7 ( V_2 , V_75 ) ,
F_7 ( V_2 , V_52 ) ) ;
V_2 -> V_76 |= V_77 ;
if ( ! V_2 -> V_66 ) {
F_35 ( V_2 -> V_67 ) ;
V_2 -> V_66 = 1 ;
}
goto V_45;
}
if ( F_36 ( V_69 & V_70 ) ) {
if ( V_69 & V_71 )
V_2 -> V_76 |= V_78 ;
if ( V_69 & V_72 )
V_2 -> V_76 |= V_79 ;
goto V_45;
}
if ( V_2 -> V_80 && ( V_69 & V_81 ) ) {
if ( V_2 -> V_25 )
F_18 ( V_2 ) ;
else
F_37 () ;
}
if ( ! V_2 -> V_80 && ( V_69 & V_82 ) ) {
if ( V_2 -> V_25 )
F_20 ( V_2 ) ;
else
F_12 ( V_2 , V_82 ) ;
}
F_6 ( V_2 , V_69 , V_73 ) ;
if ( V_2 -> V_6 )
F_1 ( V_2 , V_83 , V_84 ) ;
if ( V_69 & V_85 ) {
F_19 ( V_2 -> V_25 ) ;
F_38 ( & V_2 -> V_86 ) ;
}
return V_87 ;
V_45:
F_12 ( V_2 , V_71 | V_72 |
V_85 | V_82 |
V_81 ) ;
F_6 ( V_2 , V_69 , V_73 ) ;
if ( V_2 -> V_6 )
F_1 ( V_2 , V_83 , V_84 ) ;
F_38 ( & V_2 -> V_86 ) ;
return V_87 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_88 * V_89 , enum V_90 V_91 )
{
T_1 V_92 ;
T_1 V_11 ;
int V_40 ;
F_14 ( V_2 ) ;
if ( V_89 -> V_9 == 0 )
return - V_93 ;
V_2 -> V_23 = V_89 -> V_22 ;
V_2 -> V_25 = V_89 -> V_9 ;
V_2 -> V_76 = V_94 ;
V_2 -> V_80 = ( V_89 -> V_95 & V_96 ) ;
F_40 ( V_2 -> V_86 ) ;
V_92 = ( 0 << V_97 ) |
V_98 |
( V_2 -> V_99 << V_100 ) |
( 1 << V_101 ) ;
F_6 ( V_2 , V_92 , V_7 ) ;
V_92 = V_89 -> V_9 - 1 ;
F_6 ( V_2 , V_92 , V_7 ) ;
V_92 = V_102 ;
if ( V_91 == V_103 )
V_92 |= V_104 ;
else if ( V_91 == V_105 )
V_92 |= V_106 ;
if ( V_89 -> V_95 & V_107 ) {
V_92 |= V_89 -> V_108 ;
V_92 |= V_109 ;
} else {
V_92 |= V_89 -> V_108 << V_110 ;
}
if ( V_89 -> V_95 & V_111 )
V_92 |= V_112 ;
if ( V_89 -> V_95 & V_96 )
V_92 |= V_113 ;
F_6 ( V_2 , V_92 , V_7 ) ;
if ( ! ( V_89 -> V_95 & V_96 ) )
F_20 ( V_2 ) ;
V_11 = V_71 | V_72 ;
if ( V_2 -> V_41 -> V_114 )
V_11 |= V_85 ;
if ( V_89 -> V_95 & V_96 )
V_11 |= V_81 ;
else if ( V_2 -> V_25 )
V_11 |= V_82 ;
F_13 ( V_2 , V_11 ) ;
F_41 ( V_2 -> V_19 , L_6 ,
F_7 ( V_2 , V_12 ) ) ;
V_40 = F_42 ( & V_2 -> V_86 , V_115 ) ;
F_12 ( V_2 , V_11 ) ;
if ( V_40 == 0 ) {
F_25 ( V_2 -> V_19 , L_7 ) ;
F_28 ( V_2 ) ;
return - V_20 ;
}
F_41 ( V_2 -> V_19 , L_8 ,
V_40 , F_43 ( & V_2 -> V_86 ) , V_2 -> V_76 ) ;
if ( F_44 ( V_2 -> V_76 == V_94 ) )
return 0 ;
if ( V_2 -> V_76 == V_78 )
F_30 ( F_45 ( 2 * 1000000 , V_2 -> V_54 ) ) ;
F_28 ( V_2 ) ;
if ( V_2 -> V_76 == V_78 ) {
if ( V_89 -> V_95 & V_111 )
return 0 ;
return - V_116 ;
}
return - V_117 ;
}
static int F_46 ( struct V_118 * V_119 , struct V_88 V_120 [] ,
int V_121 )
{
struct V_1 * V_2 = F_47 ( V_119 ) ;
int V_122 ;
int V_40 = 0 ;
if ( V_2 -> V_123 )
return - V_124 ;
V_40 = F_23 ( V_2 ) ;
if ( V_40 < 0 ) {
F_25 ( V_2 -> V_19 , L_4 , V_40 ) ;
return V_40 ;
}
for ( V_122 = 0 ; V_122 < V_121 ; V_122 ++ ) {
enum V_90 V_125 = V_126 ;
if ( V_122 < ( V_121 - 1 ) ) {
if ( V_120 [ V_122 + 1 ] . V_95 & V_127 )
V_125 = V_103 ;
else
V_125 = V_105 ;
}
V_40 = F_39 ( V_2 , & V_120 [ V_122 ] , V_125 ) ;
if ( V_40 )
break;
}
F_27 ( V_2 ) ;
return V_40 ? : V_122 ;
}
static T_1 F_48 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_47 ( V_119 ) ;
T_1 V_40 = V_128 | V_129 | V_130 |
V_131 ;
if ( V_2 -> V_41 -> V_132 )
V_40 |= V_133 ;
return V_40 ;
}
static int F_49 ( struct V_134 * V_135 )
{
struct V_1 * V_2 ;
struct V_136 * V_137 ;
struct V_138 * V_44 ;
struct V_138 * V_43 ;
void T_5 * V_5 ;
int V_67 ;
int V_40 = 0 ;
V_137 = F_50 ( V_135 , V_139 , 0 ) ;
V_5 = F_51 ( & V_135 -> V_19 , V_137 ) ;
if ( F_52 ( V_5 ) )
return F_53 ( V_5 ) ;
V_137 = F_50 ( V_135 , V_140 , 0 ) ;
if ( ! V_137 ) {
F_25 ( & V_135 -> V_19 , L_9 ) ;
return - V_93 ;
}
V_67 = V_137 -> V_141 ;
V_44 = F_54 ( & V_135 -> V_19 , L_10 ) ;
if ( F_52 ( V_44 ) ) {
F_25 ( & V_135 -> V_19 , L_11 ) ;
return F_53 ( V_44 ) ;
}
V_2 = F_55 ( & V_135 -> V_19 , sizeof( * V_2 ) , V_142 ) ;
if ( ! V_2 ) {
F_25 ( & V_135 -> V_19 , L_12 ) ;
return - V_143 ;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_44 = V_44 ;
V_2 -> V_144 . V_145 = & V_146 ;
V_2 -> V_67 = V_67 ;
V_2 -> V_99 = V_135 -> V_147 ;
V_2 -> V_19 = & V_135 -> V_19 ;
V_40 = F_56 ( V_2 -> V_19 -> V_148 , L_13 ,
& V_2 -> V_54 ) ;
if ( V_40 )
V_2 -> V_54 = 100000 ;
V_2 -> V_41 = & V_149 ;
if ( V_135 -> V_19 . V_148 ) {
const struct V_150 * V_151 ;
V_151 = F_57 ( V_152 , & V_135 -> V_19 ) ;
V_2 -> V_41 = V_151 -> V_8 ;
V_2 -> V_6 = F_58 ( V_135 -> V_19 . V_148 ,
L_14 ) ;
} else if ( V_135 -> V_147 == 3 ) {
V_2 -> V_6 = 1 ;
}
F_59 ( & V_2 -> V_86 ) ;
if ( ! V_2 -> V_41 -> V_42 ) {
V_43 = F_54 ( & V_135 -> V_19 , L_15 ) ;
if ( F_52 ( V_43 ) ) {
F_25 ( & V_135 -> V_19 , L_16 ) ;
return F_53 ( V_43 ) ;
}
V_2 -> V_43 = V_43 ;
}
F_60 ( V_135 , V_2 ) ;
V_40 = F_28 ( V_2 ) ;
if ( V_40 ) {
F_25 ( & V_135 -> V_19 , L_17 ) ;
return V_40 ;
}
V_40 = F_61 ( & V_135 -> V_19 , V_2 -> V_67 ,
F_34 , 0 , F_62 ( & V_135 -> V_19 ) , V_2 ) ;
if ( V_40 ) {
F_25 ( & V_135 -> V_19 , L_18 , V_2 -> V_67 ) ;
return V_40 ;
}
F_63 ( & V_2 -> V_144 , V_2 ) ;
V_2 -> V_144 . V_153 = V_154 ;
V_2 -> V_144 . V_155 = V_156 ;
F_64 ( V_2 -> V_144 . V_157 , L_19 ,
sizeof( V_2 -> V_144 . V_157 ) ) ;
V_2 -> V_144 . V_145 = & V_146 ;
V_2 -> V_144 . V_19 . V_158 = & V_135 -> V_19 ;
V_2 -> V_144 . V_159 = V_135 -> V_147 ;
V_2 -> V_144 . V_19 . V_148 = V_135 -> V_19 . V_148 ;
V_40 = F_65 ( & V_2 -> V_144 ) ;
if ( V_40 ) {
F_25 ( & V_135 -> V_19 , L_20 ) ;
return V_40 ;
}
F_66 ( & V_2 -> V_144 ) ;
return 0 ;
}
static int F_67 ( struct V_134 * V_135 )
{
struct V_1 * V_2 = F_68 ( V_135 ) ;
F_69 ( & V_2 -> V_144 ) ;
return 0 ;
}
static int F_70 ( struct V_160 * V_19 )
{
struct V_1 * V_2 = F_71 ( V_19 ) ;
F_72 ( & V_2 -> V_144 ) ;
V_2 -> V_123 = true ;
F_73 ( & V_2 -> V_144 ) ;
return 0 ;
}
static int F_74 ( struct V_160 * V_19 )
{
struct V_1 * V_2 = F_71 ( V_19 ) ;
int V_40 ;
F_72 ( & V_2 -> V_144 ) ;
V_40 = F_28 ( V_2 ) ;
if ( V_40 ) {
F_73 ( & V_2 -> V_144 ) ;
return V_40 ;
}
V_2 -> V_123 = false ;
F_73 ( & V_2 -> V_144 ) ;
return 0 ;
}
static int T_6 F_75 ( void )
{
return F_76 ( & V_161 ) ;
}
static void T_7 F_77 ( void )
{
F_78 ( & V_161 ) ;
}
