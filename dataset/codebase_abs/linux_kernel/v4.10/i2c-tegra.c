static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned long V_4 )
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
T_1 V_11 ;
V_11 = F_7 ( V_2 , V_12 ) & ~ V_10 ;
F_6 ( V_2 , V_11 , V_12 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_10 )
{
T_1 V_11 ;
V_11 = F_7 ( V_2 , V_12 ) | V_10 ;
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
V_3 = F_20 ( V_3 ) ;
memcpy ( V_22 , & V_3 , V_24 ) ;
V_24 = 0 ;
V_21 -- ;
}
F_19 ( V_21 > 0 && V_24 > 0 ) ;
V_2 -> V_25 = V_24 ;
V_2 -> V_23 = V_22 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
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
F_22 () ;
F_8 ( V_2 , V_22 , V_7 , V_26 ) ;
V_22 += V_26 * V_30 ;
}
if ( V_32 > 0 && V_24 > 0 ) {
F_19 ( V_24 > 3 ) ;
memcpy ( & V_3 , V_22 , V_24 ) ;
V_3 = F_23 ( V_3 ) ;
V_2 -> V_25 = 0 ;
V_2 -> V_23 = NULL ;
F_22 () ;
F_6 ( V_2 , V_3 , V_7 ) ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_3 ( V_2 , V_35 ) ;
V_3 |= V_36 ;
V_3 |= V_37 ;
F_1 ( V_2 , V_3 , V_35 ) ;
V_3 = F_3 ( V_2 , V_38 ) ;
V_3 |= V_39 ;
F_1 ( V_2 , V_3 , V_38 ) ;
}
static int F_25 ( struct V_40 * V_19 )
{
struct V_1 * V_2 = F_26 ( V_19 ) ;
int V_41 ;
V_41 = F_27 ( V_2 -> V_19 ) ;
if ( V_41 )
return V_41 ;
if ( ! V_2 -> V_42 -> V_43 ) {
V_41 = F_28 ( V_2 -> V_44 ) ;
if ( V_41 < 0 ) {
F_29 ( V_2 -> V_19 ,
L_2 , V_41 ) ;
return V_41 ;
}
}
V_41 = F_28 ( V_2 -> V_45 ) ;
if ( V_41 < 0 ) {
F_29 ( V_2 -> V_19 ,
L_3 , V_41 ) ;
F_30 ( V_2 -> V_44 ) ;
return V_41 ;
}
return 0 ;
}
static int F_31 ( struct V_40 * V_19 )
{
struct V_1 * V_2 = F_26 ( V_19 ) ;
F_30 ( V_2 -> V_45 ) ;
if ( ! V_2 -> V_42 -> V_43 )
F_30 ( V_2 -> V_44 ) ;
return F_32 ( V_2 -> V_19 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
unsigned long V_46 ;
void T_4 * V_47 ;
T_1 V_3 ;
int V_48 ;
if ( V_2 -> V_42 -> V_49 ) {
V_46 = F_5 ( V_2 , V_50 ) ;
V_47 = V_2 -> V_5 + V_46 ;
F_6 ( V_2 , V_51 , V_50 ) ;
if ( F_34 () )
V_48 = F_35 ( V_47 , V_3 , V_3 == 0 ,
1000 , V_52 ) ;
else
V_48 = F_36 ( V_47 , V_3 , V_3 == 0 ,
1000 , V_52 ) ;
if ( V_48 ) {
F_16 ( V_2 -> V_19 ,
L_4 ) ;
return V_48 ;
}
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_48 ;
T_1 V_53 ;
V_48 = F_38 ( V_2 -> V_19 ) ;
if ( V_48 < 0 ) {
F_29 ( V_2 -> V_19 , L_5 , V_48 ) ;
return V_48 ;
}
F_39 ( V_2 -> V_54 ) ;
F_40 ( 2 ) ;
F_41 ( V_2 -> V_54 ) ;
if ( V_2 -> V_6 )
F_24 ( V_2 ) ;
V_3 = V_55 | V_56 |
( 0x2 << V_57 ) ;
if ( V_2 -> V_42 -> V_58 )
V_3 |= V_59 ;
F_6 ( V_2 , V_3 , V_60 ) ;
F_6 ( V_2 , 0 , V_12 ) ;
V_53 = V_2 -> V_42 -> V_61 ;
V_53 |= V_2 -> V_62 <<
V_63 ;
F_6 ( V_2 , V_53 , V_64 ) ;
if ( ! V_2 -> V_6 ) {
T_1 V_65 = F_7 ( V_2 , V_66 ) ;
V_65 |= V_67 | V_68 ;
F_6 ( V_2 , V_65 , V_66 ) ;
F_6 ( V_2 , 0xfc , V_69 ) ;
F_6 ( V_2 , 0x00 , V_70 ) ;
}
V_3 = 7 << V_71 |
0 << V_72 ;
F_6 ( V_2 , V_3 , V_16 ) ;
V_48 = F_14 ( V_2 ) ;
if ( V_48 )
goto V_48;
if ( V_2 -> V_73 && V_2 -> V_42 -> V_74 )
F_6 ( V_2 , V_75 , V_76 ) ;
V_48 = F_33 ( V_2 ) ;
if ( V_48 )
goto V_48;
if ( V_2 -> V_77 ) {
V_2 -> V_77 = false ;
F_42 ( V_2 -> V_78 ) ;
}
V_48:
F_43 ( V_2 -> V_19 ) ;
return V_48 ;
}
static int F_44 ( struct V_1 * V_2 )
{
T_1 V_79 ;
V_79 = F_7 ( V_2 , V_60 ) ;
if ( V_79 & V_56 )
F_6 ( V_2 , V_79 & ~ V_56 , V_60 ) ;
return F_33 ( V_2 ) ;
}
static T_5 F_45 ( int V_78 , void * V_80 )
{
T_1 V_81 ;
const T_1 V_82 = V_83 | V_84 ;
struct V_1 * V_2 = V_80 ;
unsigned long V_85 ;
V_81 = F_7 ( V_2 , V_86 ) ;
F_46 ( & V_2 -> V_87 , V_85 ) ;
if ( V_81 == 0 ) {
F_16 ( V_2 -> V_19 , L_6 ,
F_7 ( V_2 , V_88 ) ,
F_7 ( V_2 , V_89 ) ,
F_7 ( V_2 , V_60 ) ) ;
V_2 -> V_90 |= V_91 ;
if ( ! V_2 -> V_77 ) {
F_47 ( V_2 -> V_78 ) ;
V_2 -> V_77 = true ;
}
goto V_48;
}
if ( F_48 ( V_81 & V_82 ) ) {
F_44 ( V_2 ) ;
if ( V_81 & V_83 )
V_2 -> V_90 |= V_92 ;
if ( V_81 & V_84 )
V_2 -> V_90 |= V_93 ;
goto V_48;
}
if ( V_2 -> V_94 && ( V_81 & V_95 ) ) {
if ( V_2 -> V_25 )
F_18 ( V_2 ) ;
else
F_49 () ;
}
if ( ! V_2 -> V_94 && ( V_81 & V_96 ) ) {
if ( V_2 -> V_25 )
F_21 ( V_2 ) ;
else
F_12 ( V_2 , V_96 ) ;
}
F_6 ( V_2 , V_81 , V_86 ) ;
if ( V_2 -> V_6 )
F_1 ( V_2 , V_97 , V_98 ) ;
if ( V_81 & V_99 ) {
F_19 ( V_2 -> V_25 ) ;
F_50 ( & V_2 -> V_100 ) ;
}
goto V_101;
V_48:
F_12 ( V_2 , V_83 | V_84 |
V_99 | V_96 |
V_95 ) ;
F_6 ( V_2 , V_81 , V_86 ) ;
if ( V_2 -> V_6 )
F_1 ( V_2 , V_97 , V_98 ) ;
F_50 ( & V_2 -> V_100 ) ;
V_101:
F_51 ( & V_2 -> V_87 , V_85 ) ;
return V_102 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_103 * V_104 , enum V_105 V_106 )
{
T_1 V_107 ;
T_1 V_11 ;
unsigned long V_108 ;
unsigned long V_85 ;
F_14 ( V_2 ) ;
if ( V_104 -> V_9 == 0 )
return - V_109 ;
V_2 -> V_23 = V_104 -> V_22 ;
V_2 -> V_25 = V_104 -> V_9 ;
V_2 -> V_90 = V_110 ;
V_2 -> V_94 = ( V_104 -> V_85 & V_111 ) ;
F_53 ( & V_2 -> V_100 ) ;
F_46 ( & V_2 -> V_87 , V_85 ) ;
V_11 = V_83 | V_84 ;
F_13 ( V_2 , V_11 ) ;
V_107 = ( 0 << V_112 ) |
V_113 |
( V_2 -> V_114 << V_115 ) |
( 1 << V_116 ) ;
F_6 ( V_2 , V_107 , V_7 ) ;
V_107 = V_104 -> V_9 - 1 ;
F_6 ( V_2 , V_107 , V_7 ) ;
V_107 = V_117 ;
if ( V_106 == V_118 )
V_107 |= V_119 ;
else if ( V_106 == V_120 )
V_107 |= V_121 ;
if ( V_104 -> V_85 & V_122 ) {
V_107 |= V_104 -> V_47 ;
V_107 |= V_123 ;
} else {
V_107 |= V_104 -> V_47 << V_124 ;
}
if ( V_104 -> V_85 & V_125 )
V_107 |= V_126 ;
if ( V_104 -> V_85 & V_111 )
V_107 |= V_127 ;
F_6 ( V_2 , V_107 , V_7 ) ;
if ( ! ( V_104 -> V_85 & V_111 ) )
F_21 ( V_2 ) ;
if ( V_2 -> V_42 -> V_128 )
V_11 |= V_99 ;
if ( V_104 -> V_85 & V_111 )
V_11 |= V_95 ;
else if ( V_2 -> V_25 )
V_11 |= V_96 ;
F_13 ( V_2 , V_11 ) ;
F_51 ( & V_2 -> V_87 , V_85 ) ;
F_54 ( V_2 -> V_19 , L_7 ,
F_7 ( V_2 , V_12 ) ) ;
V_108 = F_55 ( & V_2 -> V_100 ,
V_129 ) ;
F_12 ( V_2 , V_11 ) ;
if ( V_108 == 0 ) {
F_29 ( V_2 -> V_19 , L_8 ) ;
F_37 ( V_2 ) ;
return - V_20 ;
}
F_54 ( V_2 -> V_19 , L_9 ,
V_108 , F_56 ( & V_2 -> V_100 ) ,
V_2 -> V_90 ) ;
if ( F_57 ( V_2 -> V_90 == V_110 ) )
return 0 ;
if ( V_2 -> V_90 == V_92 )
F_40 ( F_58 ( 2 * 1000000 , V_2 -> V_130 ) ) ;
F_37 ( V_2 ) ;
if ( V_2 -> V_90 == V_92 ) {
if ( V_104 -> V_85 & V_125 )
return 0 ;
return - V_131 ;
}
return - V_132 ;
}
static int F_59 ( struct V_133 * V_134 , struct V_103 V_135 [] ,
int V_136 )
{
struct V_1 * V_2 = F_60 ( V_134 ) ;
int V_137 ;
int V_41 = 0 ;
if ( V_2 -> V_138 )
return - V_139 ;
V_41 = F_38 ( V_2 -> V_19 ) ;
if ( V_41 < 0 ) {
F_29 ( V_2 -> V_19 , L_5 , V_41 ) ;
return V_41 ;
}
for ( V_137 = 0 ; V_137 < V_136 ; V_137 ++ ) {
enum V_105 V_140 = V_141 ;
if ( V_137 < ( V_136 - 1 ) ) {
if ( V_135 [ V_137 + 1 ] . V_85 & V_142 )
V_140 = V_118 ;
else
V_140 = V_120 ;
}
V_41 = F_52 ( V_2 , & V_135 [ V_137 ] , V_140 ) ;
if ( V_41 )
break;
}
F_43 ( V_2 -> V_19 ) ;
return V_41 ? : V_137 ;
}
static T_1 F_61 ( struct V_133 * V_134 )
{
struct V_1 * V_2 = F_60 ( V_134 ) ;
T_1 V_41 = V_143 | ( V_144 & ~ V_145 ) |
V_146 | V_147 ;
if ( V_2 -> V_42 -> V_148 )
V_41 |= V_149 ;
return V_41 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_150 * V_151 = V_2 -> V_19 -> V_152 ;
int V_41 ;
V_41 = F_63 ( V_151 , L_10 ,
& V_2 -> V_130 ) ;
if ( V_41 )
V_2 -> V_130 = 100000 ;
V_2 -> V_73 = F_64 ( V_151 ,
L_11 ) ;
}
static int F_65 ( struct V_153 * V_154 )
{
struct V_1 * V_2 ;
struct V_155 * V_156 ;
struct V_157 * V_45 ;
struct V_157 * V_44 ;
void T_4 * V_5 ;
int V_78 ;
int V_41 = 0 ;
int V_158 = V_159 ;
V_156 = F_66 ( V_154 , V_160 , 0 ) ;
V_5 = F_67 ( & V_154 -> V_19 , V_156 ) ;
if ( F_68 ( V_5 ) )
return F_69 ( V_5 ) ;
V_156 = F_66 ( V_154 , V_161 , 0 ) ;
if ( ! V_156 ) {
F_29 ( & V_154 -> V_19 , L_12 ) ;
return - V_109 ;
}
V_78 = V_156 -> V_162 ;
V_45 = F_70 ( & V_154 -> V_19 , L_13 ) ;
if ( F_68 ( V_45 ) ) {
F_29 ( & V_154 -> V_19 , L_14 ) ;
return F_69 ( V_45 ) ;
}
V_2 = F_71 ( & V_154 -> V_19 , sizeof( * V_2 ) , V_163 ) ;
if ( ! V_2 )
return - V_164 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_165 . V_166 = & V_167 ;
V_2 -> V_165 . V_168 = & V_169 ;
V_2 -> V_78 = V_78 ;
V_2 -> V_114 = V_154 -> V_170 ;
V_2 -> V_19 = & V_154 -> V_19 ;
V_2 -> V_54 = F_72 ( & V_154 -> V_19 , L_15 ) ;
if ( F_68 ( V_2 -> V_54 ) ) {
F_29 ( & V_154 -> V_19 , L_16 ) ;
return F_69 ( V_2 -> V_54 ) ;
}
F_62 ( V_2 ) ;
V_2 -> V_42 = F_73 ( & V_154 -> V_19 ) ;
V_2 -> V_6 = F_74 ( V_154 -> V_19 . V_152 ,
L_17 ) ;
F_75 ( & V_2 -> V_100 ) ;
F_76 ( & V_2 -> V_87 ) ;
if ( ! V_2 -> V_42 -> V_43 ) {
V_44 = F_70 ( & V_154 -> V_19 , L_18 ) ;
if ( F_68 ( V_44 ) ) {
F_29 ( & V_154 -> V_19 , L_19 ) ;
return F_69 ( V_44 ) ;
}
V_2 -> V_44 = V_44 ;
}
F_77 ( V_154 , V_2 ) ;
if ( ! V_2 -> V_42 -> V_43 ) {
V_41 = F_78 ( V_2 -> V_44 ) ;
if ( V_41 < 0 ) {
F_29 ( V_2 -> V_19 , L_20 , V_41 ) ;
return V_41 ;
}
}
V_2 -> V_62 =
V_2 -> V_42 -> V_171 ;
if ( V_2 -> V_42 -> V_172 &&
( V_2 -> V_130 == 1000000 ) )
V_2 -> V_62 =
V_2 -> V_42 -> V_172 ;
V_158 *= ( V_2 -> V_62 + 1 ) ;
V_41 = F_79 ( V_2 -> V_45 ,
V_2 -> V_130 * V_158 ) ;
if ( V_41 ) {
F_29 ( V_2 -> V_19 , L_21 , V_41 ) ;
goto V_173;
}
V_41 = F_78 ( V_2 -> V_45 ) ;
if ( V_41 < 0 ) {
F_29 ( V_2 -> V_19 , L_20 , V_41 ) ;
goto V_173;
}
F_80 ( & V_154 -> V_19 ) ;
if ( ! F_81 ( & V_154 -> V_19 ) ) {
V_41 = F_25 ( & V_154 -> V_19 ) ;
if ( V_41 < 0 ) {
F_29 ( & V_154 -> V_19 , L_22 ) ;
goto V_174;
}
}
if ( V_2 -> V_73 ) {
V_41 = F_28 ( V_2 -> V_45 ) ;
if ( V_41 < 0 ) {
F_29 ( V_2 -> V_19 , L_23 ,
V_41 ) ;
goto V_175;
}
}
V_41 = F_37 ( V_2 ) ;
if ( V_41 ) {
F_29 ( & V_154 -> V_19 , L_24 ) ;
goto V_176;
}
V_41 = F_82 ( & V_154 -> V_19 , V_2 -> V_78 ,
F_45 , 0 , F_83 ( & V_154 -> V_19 ) , V_2 ) ;
if ( V_41 ) {
F_29 ( & V_154 -> V_19 , L_25 , V_2 -> V_78 ) ;
goto V_176;
}
F_84 ( & V_2 -> V_165 , V_2 ) ;
V_2 -> V_165 . V_177 = V_178 ;
V_2 -> V_165 . V_179 = V_180 ;
F_85 ( V_2 -> V_165 . V_181 , F_83 ( & V_154 -> V_19 ) ,
sizeof( V_2 -> V_165 . V_181 ) ) ;
V_2 -> V_165 . V_19 . V_182 = & V_154 -> V_19 ;
V_2 -> V_165 . V_183 = V_154 -> V_170 ;
V_2 -> V_165 . V_19 . V_152 = V_154 -> V_19 . V_152 ;
V_41 = F_86 ( & V_2 -> V_165 ) ;
if ( V_41 )
goto V_176;
return 0 ;
V_176:
if ( V_2 -> V_73 )
F_30 ( V_2 -> V_45 ) ;
V_175:
F_87 ( & V_154 -> V_19 ) ;
if ( ! F_88 ( & V_154 -> V_19 ) )
F_31 ( & V_154 -> V_19 ) ;
V_174:
F_89 ( V_2 -> V_45 ) ;
V_173:
if ( ! V_2 -> V_42 -> V_43 )
F_89 ( V_2 -> V_44 ) ;
return V_41 ;
}
static int F_90 ( struct V_153 * V_154 )
{
struct V_1 * V_2 = F_91 ( V_154 ) ;
F_92 ( & V_2 -> V_165 ) ;
if ( V_2 -> V_73 )
F_30 ( V_2 -> V_45 ) ;
F_87 ( & V_154 -> V_19 ) ;
if ( ! F_88 ( & V_154 -> V_19 ) )
F_31 ( & V_154 -> V_19 ) ;
F_89 ( V_2 -> V_45 ) ;
if ( ! V_2 -> V_42 -> V_43 )
F_89 ( V_2 -> V_44 ) ;
return 0 ;
}
static int F_93 ( struct V_40 * V_19 )
{
struct V_1 * V_2 = F_26 ( V_19 ) ;
F_94 ( & V_2 -> V_165 ) ;
V_2 -> V_138 = true ;
F_95 ( & V_2 -> V_165 ) ;
return 0 ;
}
static int F_96 ( struct V_40 * V_19 )
{
struct V_1 * V_2 = F_26 ( V_19 ) ;
int V_41 ;
F_94 ( & V_2 -> V_165 ) ;
V_41 = F_37 ( V_2 ) ;
if ( ! V_41 )
V_2 -> V_138 = false ;
F_95 ( & V_2 -> V_165 ) ;
return V_41 ;
}
static int T_6 F_97 ( void )
{
return F_98 ( & V_184 ) ;
}
static void T_7 F_99 ( void )
{
F_100 ( & V_184 ) ;
}
