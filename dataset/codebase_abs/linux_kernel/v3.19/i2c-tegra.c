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
T_1 V_46 ;
V_45 = F_23 ( V_2 ) ;
if ( V_45 < 0 ) {
F_25 ( V_2 -> V_19 , L_4 , V_45 ) ;
return V_45 ;
}
F_29 ( V_2 -> V_47 ) ;
F_30 ( 2 ) ;
F_31 ( V_2 -> V_47 ) ;
if ( V_2 -> V_6 )
F_22 ( V_2 ) ;
V_3 = V_48 | V_49 |
( 0x2 << V_50 ) ;
F_6 ( V_2 , V_3 , V_51 ) ;
F_6 ( V_2 , 0 , V_12 ) ;
V_46 = V_2 -> V_41 -> V_52 ;
V_46 |= V_2 -> V_41 -> V_53 <<
V_54 ;
F_6 ( V_2 , V_46 , V_55 ) ;
if ( ! V_2 -> V_6 ) {
T_1 V_56 = F_7 ( V_2 , V_57 ) ;
V_56 |= V_58 | V_59 ;
F_6 ( V_2 , V_56 , V_57 ) ;
F_6 ( V_2 , 0xfc , V_60 ) ;
F_6 ( V_2 , 0x00 , V_61 ) ;
}
V_3 = 7 << V_62 |
0 << V_63 ;
F_6 ( V_2 , V_3 , V_16 ) ;
if ( F_14 ( V_2 ) )
V_45 = - V_20 ;
F_27 ( V_2 ) ;
if ( V_2 -> V_64 ) {
V_2 -> V_64 = 0 ;
F_32 ( V_2 -> V_65 ) ;
}
return V_45 ;
}
static T_4 F_33 ( int V_65 , void * V_66 )
{
T_1 V_67 ;
const T_1 V_68 = V_69 | V_70 ;
struct V_1 * V_2 = V_66 ;
V_67 = F_7 ( V_2 , V_71 ) ;
if ( V_67 == 0 ) {
F_16 ( V_2 -> V_19 , L_5 ,
F_7 ( V_2 , V_72 ) ,
F_7 ( V_2 , V_73 ) ,
F_7 ( V_2 , V_51 ) ) ;
V_2 -> V_74 |= V_75 ;
if ( ! V_2 -> V_64 ) {
F_34 ( V_2 -> V_65 ) ;
V_2 -> V_64 = 1 ;
}
goto V_45;
}
if ( F_35 ( V_67 & V_68 ) ) {
if ( V_67 & V_69 )
V_2 -> V_74 |= V_76 ;
if ( V_67 & V_70 )
V_2 -> V_74 |= V_77 ;
goto V_45;
}
if ( V_2 -> V_78 && ( V_67 & V_79 ) ) {
if ( V_2 -> V_25 )
F_18 ( V_2 ) ;
else
F_36 () ;
}
if ( ! V_2 -> V_78 && ( V_67 & V_80 ) ) {
if ( V_2 -> V_25 )
F_20 ( V_2 ) ;
else
F_12 ( V_2 , V_80 ) ;
}
F_6 ( V_2 , V_67 , V_71 ) ;
if ( V_2 -> V_6 )
F_1 ( V_2 , V_81 , V_82 ) ;
if ( V_67 & V_83 ) {
F_19 ( V_2 -> V_25 ) ;
F_37 ( & V_2 -> V_84 ) ;
}
return V_85 ;
V_45:
F_12 ( V_2 , V_69 | V_70 |
V_83 | V_80 |
V_79 ) ;
F_6 ( V_2 , V_67 , V_71 ) ;
if ( V_2 -> V_6 )
F_1 ( V_2 , V_81 , V_82 ) ;
F_37 ( & V_2 -> V_84 ) ;
return V_85 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_86 * V_87 , enum V_88 V_89 )
{
T_1 V_90 ;
T_1 V_11 ;
int V_40 ;
F_14 ( V_2 ) ;
if ( V_87 -> V_9 == 0 )
return - V_91 ;
V_2 -> V_23 = V_87 -> V_22 ;
V_2 -> V_25 = V_87 -> V_9 ;
V_2 -> V_74 = V_92 ;
V_2 -> V_78 = ( V_87 -> V_93 & V_94 ) ;
F_39 ( & V_2 -> V_84 ) ;
V_90 = ( 0 << V_95 ) |
V_96 |
( V_2 -> V_97 << V_98 ) |
( 1 << V_99 ) ;
F_6 ( V_2 , V_90 , V_7 ) ;
V_90 = V_87 -> V_9 - 1 ;
F_6 ( V_2 , V_90 , V_7 ) ;
V_90 = V_100 ;
if ( V_89 == V_101 )
V_90 |= V_102 ;
else if ( V_89 == V_103 )
V_90 |= V_104 ;
if ( V_87 -> V_93 & V_105 ) {
V_90 |= V_87 -> V_106 ;
V_90 |= V_107 ;
} else {
V_90 |= V_87 -> V_106 << V_108 ;
}
if ( V_87 -> V_93 & V_109 )
V_90 |= V_110 ;
if ( V_87 -> V_93 & V_94 )
V_90 |= V_111 ;
F_6 ( V_2 , V_90 , V_7 ) ;
if ( ! ( V_87 -> V_93 & V_94 ) )
F_20 ( V_2 ) ;
V_11 = V_69 | V_70 ;
if ( V_2 -> V_41 -> V_112 )
V_11 |= V_83 ;
if ( V_87 -> V_93 & V_94 )
V_11 |= V_79 ;
else if ( V_2 -> V_25 )
V_11 |= V_80 ;
F_13 ( V_2 , V_11 ) ;
F_40 ( V_2 -> V_19 , L_6 ,
F_7 ( V_2 , V_12 ) ) ;
V_40 = F_41 ( & V_2 -> V_84 , V_113 ) ;
F_12 ( V_2 , V_11 ) ;
if ( V_40 == 0 ) {
F_25 ( V_2 -> V_19 , L_7 ) ;
F_28 ( V_2 ) ;
return - V_20 ;
}
F_40 ( V_2 -> V_19 , L_8 ,
V_40 , F_42 ( & V_2 -> V_84 ) , V_2 -> V_74 ) ;
if ( F_43 ( V_2 -> V_74 == V_92 ) )
return 0 ;
if ( V_2 -> V_74 == V_76 )
F_30 ( F_44 ( 2 * 1000000 , V_2 -> V_114 ) ) ;
F_28 ( V_2 ) ;
if ( V_2 -> V_74 == V_76 ) {
if ( V_87 -> V_93 & V_109 )
return 0 ;
return - V_115 ;
}
return - V_116 ;
}
static int F_45 ( struct V_117 * V_118 , struct V_86 V_119 [] ,
int V_120 )
{
struct V_1 * V_2 = F_46 ( V_118 ) ;
int V_121 ;
int V_40 = 0 ;
if ( V_2 -> V_122 )
return - V_123 ;
V_40 = F_23 ( V_2 ) ;
if ( V_40 < 0 ) {
F_25 ( V_2 -> V_19 , L_4 , V_40 ) ;
return V_40 ;
}
for ( V_121 = 0 ; V_121 < V_120 ; V_121 ++ ) {
enum V_88 V_124 = V_125 ;
if ( V_121 < ( V_120 - 1 ) ) {
if ( V_119 [ V_121 + 1 ] . V_93 & V_126 )
V_124 = V_101 ;
else
V_124 = V_103 ;
}
V_40 = F_38 ( V_2 , & V_119 [ V_121 ] , V_124 ) ;
if ( V_40 )
break;
}
F_27 ( V_2 ) ;
return V_40 ? : V_121 ;
}
static T_1 F_47 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = F_46 ( V_118 ) ;
T_1 V_40 = V_127 | V_128 | V_129 |
V_130 ;
if ( V_2 -> V_41 -> V_131 )
V_40 |= V_132 ;
return V_40 ;
}
static int F_48 ( struct V_133 * V_134 )
{
struct V_1 * V_2 ;
struct V_135 * V_136 ;
struct V_137 * V_44 ;
struct V_137 * V_43 ;
void T_5 * V_5 ;
int V_65 ;
int V_40 = 0 ;
int V_138 = V_139 ;
V_136 = F_49 ( V_134 , V_140 , 0 ) ;
V_5 = F_50 ( & V_134 -> V_19 , V_136 ) ;
if ( F_51 ( V_5 ) )
return F_52 ( V_5 ) ;
V_136 = F_49 ( V_134 , V_141 , 0 ) ;
if ( ! V_136 ) {
F_25 ( & V_134 -> V_19 , L_9 ) ;
return - V_91 ;
}
V_65 = V_136 -> V_142 ;
V_44 = F_53 ( & V_134 -> V_19 , L_10 ) ;
if ( F_51 ( V_44 ) ) {
F_25 ( & V_134 -> V_19 , L_11 ) ;
return F_52 ( V_44 ) ;
}
V_2 = F_54 ( & V_134 -> V_19 , sizeof( * V_2 ) , V_143 ) ;
if ( ! V_2 )
return - V_144 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_44 = V_44 ;
V_2 -> V_145 . V_146 = & V_147 ;
V_2 -> V_65 = V_65 ;
V_2 -> V_97 = V_134 -> V_148 ;
V_2 -> V_19 = & V_134 -> V_19 ;
V_2 -> V_47 = F_55 ( & V_134 -> V_19 , L_12 ) ;
if ( F_51 ( V_2 -> V_47 ) ) {
F_25 ( & V_134 -> V_19 , L_13 ) ;
return F_52 ( V_2 -> V_47 ) ;
}
V_40 = F_56 ( V_2 -> V_19 -> V_149 , L_14 ,
& V_2 -> V_114 ) ;
if ( V_40 )
V_2 -> V_114 = 100000 ;
V_2 -> V_41 = & V_150 ;
if ( V_134 -> V_19 . V_149 ) {
const struct V_151 * V_152 ;
V_152 = F_57 ( V_153 , & V_134 -> V_19 ) ;
V_2 -> V_41 = V_152 -> V_8 ;
V_2 -> V_6 = F_58 ( V_134 -> V_19 . V_149 ,
L_15 ) ;
} else if ( V_134 -> V_148 == 3 ) {
V_2 -> V_6 = 1 ;
}
F_59 ( & V_2 -> V_84 ) ;
if ( ! V_2 -> V_41 -> V_42 ) {
V_43 = F_53 ( & V_134 -> V_19 , L_16 ) ;
if ( F_51 ( V_43 ) ) {
F_25 ( & V_134 -> V_19 , L_17 ) ;
return F_52 ( V_43 ) ;
}
V_2 -> V_43 = V_43 ;
}
F_60 ( V_134 , V_2 ) ;
if ( ! V_2 -> V_41 -> V_42 ) {
V_40 = F_61 ( V_2 -> V_43 ) ;
if ( V_40 < 0 ) {
F_25 ( V_2 -> V_19 , L_18 , V_40 ) ;
return V_40 ;
}
}
V_138 *= ( V_2 -> V_41 -> V_53 + 1 ) ;
V_40 = F_62 ( V_2 -> V_44 ,
V_2 -> V_114 * V_138 ) ;
if ( V_40 ) {
F_25 ( V_2 -> V_19 , L_19 , V_40 ) ;
goto V_154;
}
V_40 = F_61 ( V_2 -> V_44 ) ;
if ( V_40 < 0 ) {
F_25 ( V_2 -> V_19 , L_18 , V_40 ) ;
goto V_154;
}
V_40 = F_28 ( V_2 ) ;
if ( V_40 ) {
F_25 ( & V_134 -> V_19 , L_20 ) ;
goto V_155;
}
V_40 = F_63 ( & V_134 -> V_19 , V_2 -> V_65 ,
F_33 , 0 , F_64 ( & V_134 -> V_19 ) , V_2 ) ;
if ( V_40 ) {
F_25 ( & V_134 -> V_19 , L_21 , V_2 -> V_65 ) ;
goto V_155;
}
F_65 ( & V_2 -> V_145 , V_2 ) ;
V_2 -> V_145 . V_156 = V_157 ;
V_2 -> V_145 . V_158 = V_159 ;
F_66 ( V_2 -> V_145 . V_160 , L_22 ,
sizeof( V_2 -> V_145 . V_160 ) ) ;
V_2 -> V_145 . V_146 = & V_147 ;
V_2 -> V_145 . V_19 . V_161 = & V_134 -> V_19 ;
V_2 -> V_145 . V_162 = V_134 -> V_148 ;
V_2 -> V_145 . V_19 . V_149 = V_134 -> V_19 . V_149 ;
V_40 = F_67 ( & V_2 -> V_145 ) ;
if ( V_40 ) {
F_25 ( & V_134 -> V_19 , L_23 ) ;
goto V_155;
}
return 0 ;
V_155:
F_68 ( V_2 -> V_44 ) ;
V_154:
if ( ! V_2 -> V_41 -> V_42 )
F_68 ( V_2 -> V_43 ) ;
return V_40 ;
}
static int F_69 ( struct V_133 * V_134 )
{
struct V_1 * V_2 = F_70 ( V_134 ) ;
F_71 ( & V_2 -> V_145 ) ;
F_68 ( V_2 -> V_44 ) ;
if ( ! V_2 -> V_41 -> V_42 )
F_68 ( V_2 -> V_43 ) ;
return 0 ;
}
static int F_72 ( struct V_163 * V_19 )
{
struct V_1 * V_2 = F_73 ( V_19 ) ;
F_74 ( & V_2 -> V_145 ) ;
V_2 -> V_122 = true ;
F_75 ( & V_2 -> V_145 ) ;
return 0 ;
}
static int F_76 ( struct V_163 * V_19 )
{
struct V_1 * V_2 = F_73 ( V_19 ) ;
int V_40 ;
F_74 ( & V_2 -> V_145 ) ;
V_40 = F_28 ( V_2 ) ;
if ( V_40 ) {
F_75 ( & V_2 -> V_145 ) ;
return V_40 ;
}
V_2 -> V_122 = false ;
F_75 ( & V_2 -> V_145 ) ;
return 0 ;
}
static int T_6 F_77 ( void )
{
return F_78 ( & V_164 ) ;
}
static void T_7 F_79 ( void )
{
F_80 ( & V_164 ) ;
}
