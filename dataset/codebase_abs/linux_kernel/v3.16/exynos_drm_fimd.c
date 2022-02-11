static inline struct V_1 * F_1 (
struct V_2 * V_3 )
{
const struct V_4 * V_5 =
F_2 ( V_6 , & V_3 -> V_7 ) ;
return (struct V_1 * ) V_5 -> V_8 ;
}
static void F_3 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
if ( V_12 -> V_13 )
return;
F_4 ( & V_12 -> V_14 , 1 ) ;
if ( ! F_5 ( V_12 -> V_15 ,
! F_6 ( & V_12 -> V_14 ) ,
V_16 / 20 ) )
F_7 ( L_1 ) ;
}
static void F_8 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
int V_17 , V_18 = 0 ;
F_7 ( L_2 , __FILE__ ) ;
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ ) {
T_1 V_20 = F_9 ( V_12 -> V_21 + V_22 ) ;
if ( V_20 & F_10 ( V_17 ) ) {
V_20 &= ~ F_10 ( V_17 ) ;
F_11 ( V_20 , V_12 -> V_21 + V_22 ) ;
V_18 = 1 ;
}
}
if ( V_18 )
F_3 ( V_10 ) ;
}
static int F_12 ( struct V_9 * V_10 ,
struct V_23 * V_24 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_25 * V_26 ;
V_26 = V_24 -> V_27 ;
V_10 -> V_24 = V_12 -> V_24 = V_24 ;
V_10 -> V_28 = V_12 -> V_28 = V_26 -> V_28 ++ ;
V_24 -> V_29 = true ;
V_24 -> V_30 = true ;
if ( F_13 ( V_12 -> V_24 ) ) {
F_8 ( V_10 ) ;
F_14 ( V_12 -> V_24 , V_12 -> V_7 ) ;
}
return 0 ;
}
static void F_15 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
if ( F_13 ( V_12 -> V_24 ) )
F_16 ( V_12 -> V_24 , V_12 -> V_7 ) ;
}
static T_1 F_17 ( struct V_11 * V_12 ,
const struct V_31 * V_32 )
{
unsigned long V_33 = V_32 -> V_34 * V_32 -> V_35 * V_32 -> V_36 ;
T_1 V_37 ;
V_37 = F_18 ( F_19 ( V_12 -> V_38 ) , V_33 ) ;
return ( V_37 < 0x100 ) ? V_37 : 0xff ;
}
static bool F_20 ( struct V_9 * V_10 ,
const struct V_31 * V_32 ,
struct V_31 * V_39 )
{
if ( V_39 -> V_36 == 0 )
V_39 -> V_36 = V_40 ;
return true ;
}
static void F_21 ( struct V_9 * V_10 ,
const struct V_31 * V_41 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
F_22 ( & V_12 -> V_32 , V_41 ) ;
}
static void F_23 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_31 * V_32 = & V_12 -> V_32 ;
struct V_1 * V_42 ;
T_1 V_20 , V_37 , V_43 ;
int V_44 , V_45 , V_46 , V_47 , V_48 , V_49 ;
V_42 = V_12 -> V_42 ;
if ( V_12 -> V_13 )
return;
if ( V_32 -> V_34 == 0 || V_32 -> V_35 == 0 )
return;
V_43 = V_12 -> V_43 ;
if ( V_32 -> V_50 & V_51 )
V_43 |= V_52 ;
if ( V_32 -> V_50 & V_53 )
V_43 |= V_54 ;
F_11 ( V_43 , V_12 -> V_21 + V_42 -> V_55 + V_56 ) ;
V_44 = V_32 -> V_57 - V_32 -> V_58 ;
V_45 = V_32 -> V_59 - V_32 -> V_57 ;
V_46 = V_32 -> V_58 - V_32 -> V_60 ;
V_20 = F_24 ( V_45 - 1 ) |
F_25 ( V_46 - 1 ) |
F_26 ( V_44 - 1 ) ;
F_11 ( V_20 , V_12 -> V_21 + V_42 -> V_55 + V_61 ) ;
V_47 = V_32 -> V_62 - V_32 -> V_63 ;
V_48 = V_32 -> V_64 - V_32 -> V_62 ;
V_49 = V_32 -> V_63 - V_32 -> V_65 ;
V_20 = F_27 ( V_48 - 1 ) |
F_28 ( V_49 - 1 ) |
F_29 ( V_47 - 1 ) ;
F_11 ( V_20 , V_12 -> V_21 + V_42 -> V_55 + V_66 ) ;
V_20 = F_30 ( V_32 -> V_67 - 1 ) |
F_31 ( V_32 -> V_68 - 1 ) |
F_32 ( V_32 -> V_67 - 1 ) |
F_33 ( V_32 -> V_68 - 1 ) ;
F_11 ( V_20 , V_12 -> V_21 + V_42 -> V_55 + V_69 ) ;
V_20 = V_70 | V_71 ;
if ( V_12 -> V_42 -> V_72 )
V_20 |= V_73 ;
V_37 = F_17 ( V_12 , V_32 ) ;
if ( V_37 > 1 )
V_20 |= F_34 ( V_37 - 1 ) | V_74 ;
F_11 ( V_20 , V_12 -> V_21 + V_75 ) ;
}
static int F_35 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
T_1 V_20 ;
if ( V_12 -> V_13 )
return - V_76 ;
if ( ! F_36 ( 0 , & V_12 -> V_77 ) ) {
V_20 = F_9 ( V_12 -> V_21 + V_78 ) ;
V_20 |= V_79 ;
V_20 |= V_80 ;
V_20 &= ~ V_81 ;
V_20 |= V_82 ;
V_20 &= ~ V_83 ;
V_20 |= V_84 ;
F_11 ( V_20 , V_12 -> V_21 + V_78 ) ;
}
return 0 ;
}
static void F_37 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
T_1 V_20 ;
if ( V_12 -> V_13 )
return;
if ( F_38 ( 0 , & V_12 -> V_77 ) ) {
V_20 = F_9 ( V_12 -> V_21 + V_78 ) ;
V_20 &= ~ V_80 ;
V_20 &= ~ V_79 ;
F_11 ( V_20 , V_12 -> V_21 + V_78 ) ;
}
}
static void F_39 ( struct V_9 * V_10 ,
struct V_85 * V_86 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_87 * V_88 ;
int V_17 ;
unsigned long V_89 ;
if ( ! V_86 ) {
F_40 ( L_3 ) ;
return;
}
V_17 = V_86 -> V_90 ;
if ( V_17 == V_91 )
V_17 = V_12 -> V_92 ;
if ( V_17 < 0 || V_17 >= V_19 )
return;
V_89 = V_86 -> V_93 * ( V_86 -> V_94 >> 3 ) ;
V_89 += V_86 -> V_95 * V_86 -> V_96 ;
F_7 ( L_4 , V_89 , V_86 -> V_96 ) ;
V_88 = & V_12 -> V_88 [ V_17 ] ;
V_88 -> V_97 = V_86 -> V_98 ;
V_88 -> V_99 = V_86 -> V_100 ;
V_88 -> V_101 = V_86 -> V_102 ;
V_88 -> V_103 = V_86 -> V_104 ;
V_88 -> V_105 = V_86 -> V_105 ;
V_88 -> V_106 = V_86 -> V_106 ;
V_88 -> V_107 = V_86 -> V_107 [ 0 ] + V_89 ;
V_88 -> V_94 = V_86 -> V_94 ;
V_88 -> V_108 = V_86 -> V_108 ;
V_88 -> V_109 = ( V_86 -> V_105 - V_86 -> V_102 ) *
( V_86 -> V_94 >> 3 ) ;
V_88 -> V_110 = V_86 -> V_102 * ( V_86 -> V_94 >> 3 ) ;
F_7 ( L_5 ,
V_88 -> V_97 , V_88 -> V_99 ) ;
F_7 ( L_6 ,
V_88 -> V_101 , V_88 -> V_103 ) ;
F_7 ( L_7 , ( unsigned long ) V_88 -> V_107 ) ;
F_7 ( L_8 ,
V_86 -> V_105 , V_86 -> V_102 ) ;
}
static void F_41 ( struct V_11 * V_12 , unsigned int V_17 )
{
struct V_87 * V_88 = & V_12 -> V_88 [ V_17 ] ;
unsigned long V_20 ;
V_20 = V_111 ;
if ( V_12 -> V_42 -> V_112 && ! V_17 ) {
if ( V_88 -> V_108 == V_113 )
V_88 -> V_108 = V_114 ;
}
switch ( V_88 -> V_108 ) {
case V_115 :
V_20 |= V_116 ;
V_20 |= V_117 ;
V_20 |= V_118 ;
break;
case V_119 :
V_20 |= V_120 ;
V_20 |= V_121 ;
V_20 |= V_122 ;
break;
case V_123 :
V_20 |= V_124 ;
V_20 |= V_121 ;
V_20 |= V_122 ;
break;
case V_114 :
V_20 |= V_125 ;
V_20 |= V_126 ;
V_20 |= V_122 ;
break;
case V_113 :
V_20 |= V_127
| V_128 | V_129 ;
V_20 |= V_126 ;
V_20 |= V_122 ;
break;
default:
F_7 ( L_9 ) ;
V_20 |= V_125 ;
V_20 |= V_126 ;
V_20 |= V_122 ;
break;
}
F_7 ( L_10 , V_88 -> V_94 ) ;
if ( V_88 -> V_105 < V_130 ) {
V_20 &= ~ V_131 ;
V_20 |= V_132 ;
}
F_11 ( V_20 , V_12 -> V_21 + F_42 ( V_17 ) ) ;
}
static void F_43 ( struct V_11 * V_12 , unsigned int V_17 )
{
unsigned int V_133 = 0 , V_134 = 0 ;
V_133 = ~ ( V_135 | V_136 |
V_137 ) | F_44 ( 0 ) ;
V_134 = F_45 ( 0xffffffff ) ;
F_11 ( V_133 , V_12 -> V_21 + F_46 ( V_17 ) ) ;
F_11 ( V_134 , V_12 -> V_21 + F_47 ( V_17 ) ) ;
}
static void F_48 ( struct V_11 * V_12 ,
int V_17 , bool V_138 )
{
T_1 V_139 , V_140 , V_20 ;
if ( V_12 -> V_42 -> V_141 ) {
V_139 = V_22 ;
V_140 = F_49 ( V_17 ) ;
} else {
V_139 = V_142 ;
V_140 = V_143 ;
}
V_20 = F_9 ( V_12 -> V_21 + V_139 ) ;
if ( V_138 )
V_20 |= V_140 ;
else
V_20 &= ~ V_140 ;
F_11 ( V_20 , V_12 -> V_21 + V_139 ) ;
}
static void F_50 ( struct V_9 * V_10 , int V_90 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_87 * V_88 ;
int V_17 = V_90 ;
unsigned long V_20 , V_144 , V_145 ;
unsigned int V_146 ;
unsigned int V_147 ;
if ( V_12 -> V_13 )
return;
if ( V_17 == V_91 )
V_17 = V_12 -> V_92 ;
if ( V_17 < 0 || V_17 >= V_19 )
return;
V_88 = & V_12 -> V_88 [ V_17 ] ;
if ( V_12 -> V_13 ) {
V_88 -> V_148 = true ;
return;
}
F_48 ( V_12 , V_17 , true ) ;
V_20 = ( unsigned long ) V_88 -> V_107 ;
F_11 ( V_20 , V_12 -> V_21 + F_51 ( V_17 , 0 ) ) ;
V_145 = V_88 -> V_105 * V_88 -> V_103 * ( V_88 -> V_94 >> 3 ) ;
V_20 = ( unsigned long ) ( V_88 -> V_107 + V_145 ) ;
F_11 ( V_20 , V_12 -> V_21 + F_52 ( V_17 , 0 ) ) ;
F_7 ( L_11 ,
( unsigned long ) V_88 -> V_107 , V_20 , V_145 ) ;
F_7 ( L_6 ,
V_88 -> V_101 , V_88 -> V_103 ) ;
V_20 = F_53 ( V_88 -> V_109 ) |
F_54 ( V_88 -> V_110 ) |
F_55 ( V_88 -> V_109 ) |
F_56 ( V_88 -> V_110 ) ;
F_11 ( V_20 , V_12 -> V_21 + F_57 ( V_17 , 0 ) ) ;
V_20 = F_58 ( V_88 -> V_97 ) |
F_59 ( V_88 -> V_99 ) |
F_60 ( V_88 -> V_97 ) |
F_61 ( V_88 -> V_99 ) ;
F_11 ( V_20 , V_12 -> V_21 + F_62 ( V_17 ) ) ;
V_146 = V_88 -> V_97 + V_88 -> V_101 ;
if ( V_146 )
V_146 -- ;
V_147 = V_88 -> V_99 + V_88 -> V_103 ;
if ( V_147 )
V_147 -- ;
V_20 = F_63 ( V_146 ) | F_64 ( V_147 ) |
F_65 ( V_146 ) | F_66 ( V_147 ) ;
F_11 ( V_20 , V_12 -> V_21 + F_67 ( V_17 ) ) ;
F_7 ( L_12 ,
V_88 -> V_97 , V_88 -> V_99 , V_146 , V_147 ) ;
if ( V_17 != 0 ) {
V_144 = F_68 ( 0xf ) |
F_69 ( 0xf ) |
F_70 ( 0xf ) ;
F_11 ( V_144 , V_12 -> V_21 + F_71 ( V_17 ) ) ;
}
if ( V_17 != 3 && V_17 != 4 ) {
T_1 V_89 = F_72 ( V_17 ) ;
if ( V_17 == 0 )
V_89 = F_71 ( V_17 ) ;
V_20 = V_88 -> V_101 * V_88 -> V_103 ;
F_11 ( V_20 , V_12 -> V_21 + V_89 ) ;
F_7 ( L_13 , ( unsigned int ) V_20 ) ;
}
F_41 ( V_12 , V_17 ) ;
if ( V_17 != 0 )
F_43 ( V_12 , V_17 ) ;
V_20 = F_9 ( V_12 -> V_21 + F_42 ( V_17 ) ) ;
V_20 |= V_111 ;
F_11 ( V_20 , V_12 -> V_21 + F_42 ( V_17 ) ) ;
F_48 ( V_12 , V_17 , false ) ;
if ( V_12 -> V_42 -> V_141 ) {
V_20 = F_9 ( V_12 -> V_21 + V_22 ) ;
V_20 |= F_10 ( V_17 ) ;
F_11 ( V_20 , V_12 -> V_21 + V_22 ) ;
}
V_88 -> V_149 = true ;
}
static void F_73 ( struct V_9 * V_10 , int V_90 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_87 * V_88 ;
int V_17 = V_90 ;
T_1 V_20 ;
if ( V_17 == V_91 )
V_17 = V_12 -> V_92 ;
if ( V_17 < 0 || V_17 >= V_19 )
return;
V_88 = & V_12 -> V_88 [ V_17 ] ;
if ( V_12 -> V_13 ) {
V_88 -> V_148 = false ;
return;
}
F_48 ( V_12 , V_17 , true ) ;
V_20 = F_9 ( V_12 -> V_21 + F_42 ( V_17 ) ) ;
V_20 &= ~ V_111 ;
F_11 ( V_20 , V_12 -> V_21 + F_42 ( V_17 ) ) ;
if ( V_12 -> V_42 -> V_141 ) {
V_20 = F_9 ( V_12 -> V_21 + V_22 ) ;
V_20 &= ~ F_10 ( V_17 ) ;
F_11 ( V_20 , V_12 -> V_21 + V_22 ) ;
}
F_48 ( V_12 , V_17 , false ) ;
V_88 -> V_149 = false ;
}
static void F_74 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_87 * V_88 ;
int V_150 ;
for ( V_150 = 0 ; V_150 < V_19 ; V_150 ++ ) {
V_88 = & V_12 -> V_88 [ V_150 ] ;
V_88 -> V_148 = V_88 -> V_149 ;
if ( V_88 -> V_149 )
F_73 ( V_10 , V_150 ) ;
}
F_3 ( V_10 ) ;
}
static void F_75 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_87 * V_88 ;
int V_150 ;
for ( V_150 = 0 ; V_150 < V_19 ; V_150 ++ ) {
V_88 = & V_12 -> V_88 [ V_150 ] ;
V_88 -> V_149 = V_88 -> V_148 ;
V_88 -> V_148 = false ;
}
}
static void F_76 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_87 * V_88 ;
int V_150 ;
for ( V_150 = 0 ; V_150 < V_19 ; V_150 ++ ) {
V_88 = & V_12 -> V_88 [ V_150 ] ;
if ( V_88 -> V_149 )
F_50 ( V_10 , V_150 ) ;
else
F_73 ( V_10 , V_150 ) ;
}
F_23 ( V_10 ) ;
}
static int F_77 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
int V_151 ;
if ( ! V_12 -> V_13 )
return 0 ;
V_12 -> V_13 = false ;
F_78 ( V_12 -> V_7 ) ;
V_151 = F_79 ( V_12 -> V_152 ) ;
if ( V_151 < 0 ) {
F_40 ( L_14 , V_151 ) ;
goto V_153;
}
V_151 = F_79 ( V_12 -> V_38 ) ;
if ( V_151 < 0 ) {
F_40 ( L_15 , V_151 ) ;
goto V_154;
}
if ( F_38 ( 0 , & V_12 -> V_77 ) ) {
V_151 = F_35 ( V_10 ) ;
if ( V_151 ) {
F_40 ( L_16 , V_151 ) ;
goto V_155;
}
}
F_75 ( V_10 ) ;
F_76 ( V_10 ) ;
return 0 ;
V_155:
F_80 ( V_12 -> V_38 ) ;
V_154:
F_80 ( V_12 -> V_152 ) ;
V_153:
V_12 -> V_13 = true ;
return V_151 ;
}
static int F_81 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
if ( V_12 -> V_13 )
return 0 ;
F_74 ( V_10 ) ;
F_80 ( V_12 -> V_38 ) ;
F_80 ( V_12 -> V_152 ) ;
F_82 ( V_12 -> V_7 ) ;
V_12 -> V_13 = true ;
return 0 ;
}
static void F_83 ( struct V_9 * V_10 , int V_32 )
{
F_7 ( L_17 , __FILE__ , V_32 ) ;
switch ( V_32 ) {
case V_156 :
F_77 ( V_10 ) ;
break;
case V_157 :
case V_158 :
case V_159 :
F_81 ( V_10 ) ;
break;
default:
F_7 ( L_18 , V_32 ) ;
break;
}
}
static T_2 F_84 ( int V_160 , void * V_161 )
{
struct V_11 * V_12 = (struct V_11 * ) V_161 ;
T_1 V_20 ;
V_20 = F_9 ( V_12 -> V_21 + V_162 ) ;
if ( V_20 & V_163 )
F_11 ( V_163 , V_12 -> V_21 + V_162 ) ;
if ( V_12 -> V_28 < 0 || ! V_12 -> V_24 )
goto V_164;
F_85 ( V_12 -> V_24 , V_12 -> V_28 ) ;
F_86 ( V_12 -> V_24 , V_12 -> V_28 ) ;
if ( F_6 ( & V_12 -> V_14 ) ) {
F_4 ( & V_12 -> V_14 , 0 ) ;
F_87 ( & V_12 -> V_15 ) ;
}
V_164:
return V_165 ;
}
static int F_88 ( struct V_166 * V_7 , struct V_166 * V_167 , void * V_8 )
{
struct V_11 * V_12 = V_168 . V_12 ;
struct V_23 * V_24 = V_8 ;
F_12 ( & V_168 , V_24 ) ;
F_89 ( & V_168 ) ;
if ( V_12 -> V_169 )
F_90 ( V_24 , V_12 -> V_169 ) ;
return 0 ;
}
static void F_91 ( struct V_166 * V_7 , struct V_166 * V_167 ,
void * V_8 )
{
struct V_9 * V_10 = F_92 ( V_7 ) ;
struct V_11 * V_12 = V_168 . V_12 ;
struct V_170 * V_171 = V_10 -> V_171 ;
F_83 ( V_10 , V_159 ) ;
if ( V_12 -> V_169 )
F_93 ( V_7 ) ;
F_15 ( V_10 ) ;
V_171 -> V_172 -> V_173 ( V_171 ) ;
}
static int F_94 ( struct V_2 * V_3 )
{
struct V_166 * V_7 = & V_3 -> V_7 ;
struct V_11 * V_12 ;
struct V_174 * V_175 ;
int V_151 = - V_176 ;
V_151 = F_95 ( & V_3 -> V_7 , V_177 ,
V_168 . type ) ;
if ( V_151 )
return V_151 ;
if ( ! V_7 -> V_178 ) {
V_151 = - V_179 ;
goto V_180;
}
V_12 = F_96 ( V_7 , sizeof( * V_12 ) , V_181 ) ;
if ( ! V_12 ) {
V_151 = - V_182 ;
goto V_180;
}
V_12 -> V_7 = V_7 ;
V_12 -> V_13 = true ;
if ( F_97 ( V_7 -> V_178 , L_19 ) )
V_12 -> V_43 |= V_183 ;
if ( F_97 ( V_7 -> V_178 , L_20 ) )
V_12 -> V_43 |= V_184 ;
V_12 -> V_152 = F_98 ( V_7 , L_21 ) ;
if ( F_99 ( V_12 -> V_152 ) ) {
F_100 ( V_7 , L_22 ) ;
V_151 = F_101 ( V_12 -> V_152 ) ;
goto V_180;
}
V_12 -> V_38 = F_98 ( V_7 , L_23 ) ;
if ( F_99 ( V_12 -> V_38 ) ) {
F_100 ( V_7 , L_24 ) ;
V_151 = F_101 ( V_12 -> V_38 ) ;
goto V_180;
}
V_175 = F_102 ( V_3 , V_185 , 0 ) ;
V_12 -> V_21 = F_103 ( V_7 , V_175 ) ;
if ( F_99 ( V_12 -> V_21 ) ) {
V_151 = F_101 ( V_12 -> V_21 ) ;
goto V_180;
}
V_175 = F_104 ( V_3 , V_186 , L_25 ) ;
if ( ! V_175 ) {
F_100 ( V_7 , L_26 ) ;
V_151 = - V_187 ;
goto V_180;
}
V_151 = F_105 ( V_7 , V_175 -> V_188 , F_84 ,
0 , L_27 , V_12 ) ;
if ( V_151 ) {
F_100 ( V_7 , L_26 ) ;
goto V_180;
}
V_12 -> V_42 = F_1 ( V_3 ) ;
F_106 ( & V_12 -> V_15 ) ;
F_4 ( & V_12 -> V_14 , 0 ) ;
F_107 ( V_3 , & V_168 ) ;
V_168 . V_12 = V_12 ;
V_12 -> V_169 = F_108 ( V_7 ) ;
if ( F_99 ( V_12 -> V_169 ) )
return F_101 ( V_12 -> V_169 ) ;
F_109 ( & V_3 -> V_7 ) ;
V_151 = F_110 ( & V_3 -> V_7 , & V_189 ) ;
if ( V_151 )
goto V_190;
return V_151 ;
V_190:
F_111 ( & V_3 -> V_7 ) ;
V_180:
F_112 ( & V_3 -> V_7 , V_177 ) ;
return V_151 ;
}
static int F_113 ( struct V_2 * V_3 )
{
F_111 ( & V_3 -> V_7 ) ;
F_114 ( & V_3 -> V_7 , & V_189 ) ;
F_112 ( & V_3 -> V_7 , V_177 ) ;
return 0 ;
}
