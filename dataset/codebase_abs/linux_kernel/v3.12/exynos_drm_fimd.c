static inline struct V_1 * F_1 (
struct V_2 * V_3 )
{
const struct V_4 * V_5 =
F_2 ( V_6 , & V_3 -> V_7 ) ;
return (struct V_1 * ) V_5 -> V_8 ;
}
static bool F_3 ( struct V_9 * V_7 )
{
return true ;
}
static void * F_4 ( struct V_9 * V_7 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
return & V_11 -> V_12 ;
}
static int F_6 ( struct V_9 * V_7 , struct V_13 * V_14 )
{
return 0 ;
}
static int F_7 ( struct V_9 * V_7 , int V_14 )
{
return 0 ;
}
static void F_8 ( struct V_9 * V_15 , int V_14 )
{
struct V_10 * V_11 = F_5 ( V_15 ) ;
F_9 ( L_1 , V_14 ) ;
F_10 ( & V_11 -> V_16 ) ;
switch ( V_14 ) {
case V_17 :
if ( V_11 -> V_18 )
F_11 ( V_15 ) ;
break;
case V_19 :
case V_20 :
case V_21 :
if ( ! V_11 -> V_18 )
F_12 ( V_15 ) ;
break;
default:
F_9 ( L_2 , V_14 ) ;
break;
}
F_13 ( & V_11 -> V_16 ) ;
}
static void F_14 ( struct V_9 * V_15 )
{
struct V_10 * V_11 = F_5 ( V_15 ) ;
struct V_22 * V_23 = V_11 -> V_24 . V_25 ;
struct V_26 * V_27 = V_23 -> V_28 ;
struct V_29 * V_30 = V_23 -> V_31 ;
struct V_32 * V_33 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
V_33 = & V_11 -> V_33 [ V_34 ] ;
if ( V_33 -> V_36 && ( V_30 && V_30 -> V_37 ) )
V_30 -> V_37 ( V_15 , V_34 ) ;
}
if ( V_27 && V_27 -> V_37 )
V_27 -> V_37 ( V_15 ) ;
}
static void F_15 ( struct V_9 * V_7 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_38 * V_12 = & V_11 -> V_12 ;
struct V_39 * V_40 = & V_12 -> V_40 ;
struct V_1 * V_41 ;
T_1 V_42 ;
V_41 = V_11 -> V_41 ;
if ( V_11 -> V_18 )
return;
F_16 ( V_11 -> V_43 , V_11 -> V_44 + V_41 -> V_45 + V_46 ) ;
V_42 = F_17 ( V_40 -> V_47 - 1 ) |
F_18 ( V_40 -> V_48 - 1 ) |
F_19 ( V_40 -> V_49 - 1 ) ;
F_16 ( V_42 , V_11 -> V_44 + V_41 -> V_45 + V_50 ) ;
V_42 = F_20 ( V_40 -> V_51 - 1 ) |
F_21 ( V_40 -> V_52 - 1 ) |
F_22 ( V_40 -> V_53 - 1 ) ;
F_16 ( V_42 , V_11 -> V_44 + V_41 -> V_45 + V_54 ) ;
V_42 = F_23 ( V_40 -> V_55 - 1 ) |
F_24 ( V_40 -> V_56 - 1 ) |
F_25 ( V_40 -> V_55 - 1 ) |
F_26 ( V_40 -> V_56 - 1 ) ;
F_16 ( V_42 , V_11 -> V_44 + V_41 -> V_45 + V_57 ) ;
V_42 = V_11 -> V_58 ;
V_42 &= ~ ( V_59 | V_60 ) ;
if ( V_11 -> V_41 -> V_61 ) {
V_42 &= ~ V_62 ;
V_42 |= V_63 ;
}
if ( V_11 -> V_64 > 1 )
V_42 |= F_27 ( V_11 -> V_64 - 1 ) | V_60 ;
else
V_42 &= ~ V_60 ;
V_42 |= V_65 | V_66 ;
F_16 ( V_42 , V_11 -> V_44 + V_67 ) ;
}
static int F_28 ( struct V_9 * V_7 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
T_1 V_42 ;
if ( V_11 -> V_18 )
return - V_68 ;
if ( ! F_29 ( 0 , & V_11 -> V_69 ) ) {
V_42 = F_30 ( V_11 -> V_44 + V_70 ) ;
V_42 |= V_71 ;
V_42 |= V_72 ;
V_42 &= ~ V_73 ;
V_42 |= V_74 ;
V_42 &= ~ V_75 ;
V_42 |= V_76 ;
F_16 ( V_42 , V_11 -> V_44 + V_70 ) ;
}
return 0 ;
}
static void F_31 ( struct V_9 * V_7 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
T_1 V_42 ;
if ( V_11 -> V_18 )
return;
if ( F_32 ( 0 , & V_11 -> V_69 ) ) {
V_42 = F_30 ( V_11 -> V_44 + V_70 ) ;
V_42 &= ~ V_72 ;
V_42 &= ~ V_71 ;
F_16 ( V_42 , V_11 -> V_44 + V_70 ) ;
}
}
static void F_33 ( struct V_9 * V_7 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
if ( V_11 -> V_18 )
return;
F_34 ( & V_11 -> V_77 , 1 ) ;
if ( ! F_35 ( V_11 -> V_78 ,
! F_36 ( & V_11 -> V_77 ) ,
V_79 / 20 ) )
F_9 ( L_3 ) ;
}
static void F_37 ( struct V_9 * V_7 ,
struct V_80 * V_81 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_32 * V_33 ;
int V_82 ;
unsigned long V_83 ;
if ( ! V_81 ) {
F_38 ( V_7 , L_4 ) ;
return;
}
V_82 = V_81 -> V_84 ;
if ( V_82 == V_85 )
V_82 = V_11 -> V_86 ;
if ( V_82 < 0 || V_82 >= V_35 )
return;
V_83 = V_81 -> V_87 * ( V_81 -> V_88 >> 3 ) ;
V_83 += V_81 -> V_89 * V_81 -> V_90 ;
F_9 ( L_5 , V_83 , V_81 -> V_90 ) ;
V_33 = & V_11 -> V_33 [ V_82 ] ;
V_33 -> V_91 = V_81 -> V_92 ;
V_33 -> V_93 = V_81 -> V_94 ;
V_33 -> V_95 = V_81 -> V_96 ;
V_33 -> V_97 = V_81 -> V_98 ;
V_33 -> V_99 = V_81 -> V_99 ;
V_33 -> V_100 = V_81 -> V_100 ;
V_33 -> V_101 = V_81 -> V_101 [ 0 ] + V_83 ;
V_33 -> V_88 = V_81 -> V_88 ;
V_33 -> V_102 = V_81 -> V_102 ;
V_33 -> V_103 = ( V_81 -> V_99 - V_81 -> V_96 ) *
( V_81 -> V_88 >> 3 ) ;
V_33 -> V_104 = V_81 -> V_96 * ( V_81 -> V_88 >> 3 ) ;
F_9 ( L_6 ,
V_33 -> V_91 , V_33 -> V_93 ) ;
F_9 ( L_7 ,
V_33 -> V_95 , V_33 -> V_97 ) ;
F_9 ( L_8 , ( unsigned long ) V_33 -> V_101 ) ;
F_9 ( L_9 ,
V_81 -> V_99 , V_81 -> V_96 ) ;
}
static void F_39 ( struct V_9 * V_7 , unsigned int V_82 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_32 * V_33 = & V_11 -> V_33 [ V_82 ] ;
unsigned long V_42 ;
V_42 = V_105 ;
if ( V_11 -> V_41 -> V_106 && ! V_82 ) {
if ( V_33 -> V_102 == V_107 )
V_33 -> V_102 = V_108 ;
}
switch ( V_33 -> V_102 ) {
case V_109 :
V_42 |= V_110 ;
V_42 |= V_111 ;
V_42 |= V_112 ;
break;
case V_113 :
V_42 |= V_114 ;
V_42 |= V_115 ;
V_42 |= V_116 ;
break;
case V_117 :
V_42 |= V_118 ;
V_42 |= V_115 ;
V_42 |= V_116 ;
break;
case V_108 :
V_42 |= V_119 ;
V_42 |= V_120 ;
V_42 |= V_116 ;
break;
case V_107 :
V_42 |= V_121
| V_122 | V_123 ;
V_42 |= V_120 ;
V_42 |= V_116 ;
break;
default:
F_9 ( L_10 ) ;
V_42 |= V_119 ;
V_42 |= V_120 ;
V_42 |= V_116 ;
break;
}
F_9 ( L_11 , V_33 -> V_88 ) ;
F_16 ( V_42 , V_11 -> V_44 + F_40 ( V_82 ) ) ;
}
static void F_41 ( struct V_9 * V_7 , unsigned int V_82 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
unsigned int V_124 = 0 , V_125 = 0 ;
V_124 = ~ ( V_126 | V_127 |
V_128 ) | F_42 ( 0 ) ;
V_125 = F_43 ( 0xffffffff ) ;
F_16 ( V_124 , V_11 -> V_44 + F_44 ( V_82 ) ) ;
F_16 ( V_125 , V_11 -> V_44 + F_45 ( V_82 ) ) ;
}
static void F_46 ( struct V_10 * V_11 ,
int V_82 , bool V_129 )
{
T_1 V_130 , V_131 , V_42 ;
if ( V_11 -> V_41 -> V_132 ) {
V_130 = V_133 ;
V_131 = F_47 ( V_82 ) ;
} else {
V_130 = V_134 ;
V_131 = V_135 ;
}
V_42 = F_30 ( V_11 -> V_44 + V_130 ) ;
if ( V_129 )
V_42 |= V_131 ;
else
V_42 &= ~ V_131 ;
F_16 ( V_42 , V_11 -> V_44 + V_130 ) ;
}
static void F_48 ( struct V_9 * V_7 , int V_84 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_32 * V_33 ;
int V_82 = V_84 ;
unsigned long V_42 , V_136 , V_137 ;
unsigned int V_138 ;
unsigned int V_139 ;
if ( V_11 -> V_18 )
return;
if ( V_82 == V_85 )
V_82 = V_11 -> V_86 ;
if ( V_82 < 0 || V_82 >= V_35 )
return;
V_33 = & V_11 -> V_33 [ V_82 ] ;
F_46 ( V_11 , V_82 , true ) ;
V_42 = ( unsigned long ) V_33 -> V_101 ;
F_16 ( V_42 , V_11 -> V_44 + F_49 ( V_82 , 0 ) ) ;
V_137 = V_33 -> V_99 * V_33 -> V_97 * ( V_33 -> V_88 >> 3 ) ;
V_42 = ( unsigned long ) ( V_33 -> V_101 + V_137 ) ;
F_16 ( V_42 , V_11 -> V_44 + F_50 ( V_82 , 0 ) ) ;
F_9 ( L_12 ,
( unsigned long ) V_33 -> V_101 , V_42 , V_137 ) ;
F_9 ( L_7 ,
V_33 -> V_95 , V_33 -> V_97 ) ;
V_42 = F_51 ( V_33 -> V_103 ) |
F_52 ( V_33 -> V_104 ) |
F_53 ( V_33 -> V_103 ) |
F_54 ( V_33 -> V_104 ) ;
F_16 ( V_42 , V_11 -> V_44 + F_55 ( V_82 , 0 ) ) ;
V_42 = F_56 ( V_33 -> V_91 ) |
F_57 ( V_33 -> V_93 ) |
F_58 ( V_33 -> V_91 ) |
F_59 ( V_33 -> V_93 ) ;
F_16 ( V_42 , V_11 -> V_44 + F_60 ( V_82 ) ) ;
V_138 = V_33 -> V_91 + V_33 -> V_95 ;
if ( V_138 )
V_138 -- ;
V_139 = V_33 -> V_93 + V_33 -> V_97 ;
if ( V_139 )
V_139 -- ;
V_42 = F_61 ( V_138 ) | F_62 ( V_139 ) |
F_63 ( V_138 ) | F_64 ( V_139 ) ;
F_16 ( V_42 , V_11 -> V_44 + F_65 ( V_82 ) ) ;
F_9 ( L_13 ,
V_33 -> V_91 , V_33 -> V_93 , V_138 , V_139 ) ;
if ( V_82 != 0 ) {
V_136 = F_66 ( 0xf ) |
F_67 ( 0xf ) |
F_68 ( 0xf ) ;
F_16 ( V_136 , V_11 -> V_44 + F_69 ( V_82 ) ) ;
}
if ( V_82 != 3 && V_82 != 4 ) {
T_1 V_83 = F_70 ( V_82 ) ;
if ( V_82 == 0 )
V_83 = F_69 ( V_82 ) ;
V_42 = V_33 -> V_95 * V_33 -> V_97 ;
F_16 ( V_42 , V_11 -> V_44 + V_83 ) ;
F_9 ( L_14 , ( unsigned int ) V_42 ) ;
}
F_39 ( V_7 , V_82 ) ;
if ( V_82 != 0 )
F_41 ( V_7 , V_82 ) ;
V_42 = F_30 ( V_11 -> V_44 + F_40 ( V_82 ) ) ;
V_42 |= V_105 ;
F_16 ( V_42 , V_11 -> V_44 + F_40 ( V_82 ) ) ;
F_46 ( V_11 , V_82 , false ) ;
if ( V_11 -> V_41 -> V_132 ) {
V_42 = F_30 ( V_11 -> V_44 + V_133 ) ;
V_42 |= F_71 ( V_82 ) ;
F_16 ( V_42 , V_11 -> V_44 + V_133 ) ;
}
V_33 -> V_36 = true ;
}
static void F_72 ( struct V_9 * V_7 , int V_84 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_32 * V_33 ;
int V_82 = V_84 ;
T_1 V_42 ;
if ( V_82 == V_85 )
V_82 = V_11 -> V_86 ;
if ( V_82 < 0 || V_82 >= V_35 )
return;
V_33 = & V_11 -> V_33 [ V_82 ] ;
if ( V_11 -> V_18 ) {
V_33 -> V_140 = false ;
return;
}
F_46 ( V_11 , V_82 , true ) ;
V_42 = F_30 ( V_11 -> V_44 + F_40 ( V_82 ) ) ;
V_42 &= ~ V_105 ;
F_16 ( V_42 , V_11 -> V_44 + F_40 ( V_82 ) ) ;
if ( V_11 -> V_41 -> V_132 ) {
V_42 = F_30 ( V_11 -> V_44 + V_133 ) ;
V_42 &= ~ F_71 ( V_82 ) ;
F_16 ( V_42 , V_11 -> V_44 + V_133 ) ;
}
F_46 ( V_11 , V_82 , false ) ;
V_33 -> V_36 = false ;
}
static T_2 F_73 ( int V_141 , void * V_142 )
{
struct V_10 * V_11 = (struct V_10 * ) V_142 ;
struct V_143 * V_24 = & V_11 -> V_24 ;
struct V_144 * V_145 = V_24 -> V_145 ;
struct V_22 * V_25 = V_24 -> V_25 ;
T_1 V_42 ;
V_42 = F_30 ( V_11 -> V_44 + V_146 ) ;
if ( V_42 & V_147 )
F_16 ( V_147 , V_11 -> V_44 + V_146 ) ;
if ( V_25 -> V_148 < 0 )
goto V_149;
F_74 ( V_145 , V_25 -> V_148 ) ;
F_75 ( V_145 , V_25 -> V_148 ) ;
if ( F_36 ( & V_11 -> V_77 ) ) {
F_34 ( & V_11 -> V_77 , 0 ) ;
F_76 ( & V_11 -> V_78 ) ;
}
V_149:
return V_150 ;
}
static int F_77 ( struct V_144 * V_145 , struct V_9 * V_7 )
{
V_145 -> V_151 = 1 ;
V_145 -> V_152 = 1 ;
if ( F_78 ( V_145 ) )
F_79 ( V_145 , V_7 ) ;
return 0 ;
}
static void F_80 ( struct V_144 * V_145 , struct V_9 * V_7 )
{
if ( F_78 ( V_145 ) )
F_81 ( V_145 , V_7 ) ;
}
static int F_82 ( struct V_10 * V_11 , struct V_9 * V_7 )
{
struct V_39 * V_40 = & V_11 -> V_12 . V_40 ;
unsigned long V_153 ;
V_11 -> V_154 = F_83 ( V_7 , L_15 ) ;
if ( F_84 ( V_11 -> V_154 ) ) {
F_38 ( V_7 , L_16 ) ;
return F_85 ( V_11 -> V_154 ) ;
}
V_11 -> V_155 = F_83 ( V_7 , L_17 ) ;
if ( F_84 ( V_11 -> V_155 ) ) {
F_38 ( V_7 , L_18 ) ;
return F_85 ( V_11 -> V_155 ) ;
}
V_153 = F_86 ( V_11 -> V_155 ) ;
if ( V_153 == 0 ) {
F_38 ( V_7 , L_19 ) ;
return - V_156 ;
}
if ( V_40 -> V_157 == 0 ) {
unsigned long V_158 ;
V_158 = V_40 -> V_56 + V_40 -> V_51 + V_40 -> V_52 +
V_40 -> V_53 ;
V_158 *= V_40 -> V_55 + V_40 -> V_47 + V_40 -> V_48 +
V_40 -> V_49 ;
V_40 -> V_157 = V_158 * V_159 ;
if ( V_40 -> V_157 == 0 ) {
F_38 ( V_7 , L_20 ) ;
return - V_156 ;
}
F_87 ( V_7 , L_21 ,
V_40 -> V_157 , V_159 ) ;
}
V_11 -> V_64 = F_88 ( V_153 , V_40 -> V_157 ) ;
if ( V_11 -> V_64 > 256 ) {
F_87 ( V_7 , L_22 ,
V_11 -> V_64 ) ;
V_11 -> V_64 = 256 ;
}
V_40 -> V_157 = V_153 / V_11 -> V_64 ;
F_9 ( L_23 , V_40 -> V_157 ,
V_11 -> V_64 ) ;
return 0 ;
}
static void F_89 ( struct V_10 * V_11 , int V_82 )
{
F_16 ( 0 , V_11 -> V_44 + F_40 ( V_82 ) ) ;
F_16 ( 0 , V_11 -> V_44 + F_60 ( V_82 ) ) ;
F_16 ( 0 , V_11 -> V_44 + F_65 ( V_82 ) ) ;
F_16 ( 0 , V_11 -> V_44 + F_69 ( V_82 ) ) ;
if ( V_82 == 1 || V_82 == 2 )
F_16 ( 0 , V_11 -> V_44 + F_70 ( V_82 ) ) ;
F_46 ( V_11 , V_82 , false ) ;
}
static int F_90 ( struct V_10 * V_11 , bool V_160 )
{
if ( V_160 ) {
int V_161 ;
V_161 = F_91 ( V_11 -> V_154 ) ;
if ( V_161 < 0 )
return V_161 ;
V_161 = F_91 ( V_11 -> V_155 ) ;
if ( V_161 < 0 ) {
F_92 ( V_11 -> V_154 ) ;
return V_161 ;
}
} else {
F_92 ( V_11 -> V_155 ) ;
F_92 ( V_11 -> V_154 ) ;
}
return 0 ;
}
static void F_93 ( struct V_9 * V_7 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_32 * V_33 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
V_33 = & V_11 -> V_33 [ V_34 ] ;
V_33 -> V_140 = V_33 -> V_36 ;
F_72 ( V_7 , V_34 ) ;
}
F_33 ( V_7 ) ;
}
static void F_94 ( struct V_9 * V_7 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_32 * V_33 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
V_33 = & V_11 -> V_33 [ V_34 ] ;
V_33 -> V_36 = V_33 -> V_140 ;
V_33 -> V_140 = false ;
}
}
static int F_95 ( struct V_10 * V_11 , bool V_160 )
{
struct V_9 * V_7 = V_11 -> V_24 . V_7 ;
if ( V_160 ) {
int V_161 ;
V_161 = F_90 ( V_11 , true ) ;
if ( V_161 < 0 )
return V_161 ;
V_11 -> V_18 = false ;
if ( F_32 ( 0 , & V_11 -> V_69 ) )
F_28 ( V_7 ) ;
F_94 ( V_7 ) ;
} else {
F_93 ( V_7 ) ;
F_90 ( V_11 , false ) ;
V_11 -> V_18 = true ;
}
return 0 ;
}
static int F_96 ( struct V_10 * V_11 , struct V_9 * V_7 )
{
struct V_39 * V_40 ;
int V_161 ;
V_40 = & V_11 -> V_12 . V_40 ;
V_161 = F_97 ( V_7 -> V_162 , V_40 , V_163 ) ;
if ( V_161 ) {
F_98 ( L_24 , V_161 ) ;
return V_161 ;
}
if ( V_40 -> V_164 & V_165 )
V_11 -> V_43 |= V_166 ;
if ( V_40 -> V_164 & V_167 )
V_11 -> V_43 |= V_168 ;
if ( V_40 -> V_164 & V_169 )
V_11 -> V_43 |= V_170 ;
if ( V_40 -> V_164 & V_171 )
V_11 -> V_43 |= V_172 ;
return 0 ;
}
static int F_99 ( struct V_2 * V_3 )
{
struct V_9 * V_7 = & V_3 -> V_7 ;
struct V_10 * V_11 ;
struct V_143 * V_24 ;
struct V_173 * V_174 ;
int V_82 ;
int V_161 = - V_156 ;
if ( ! V_7 -> V_162 )
return - V_175 ;
V_11 = F_100 ( V_7 , sizeof( * V_11 ) , V_176 ) ;
if ( ! V_11 )
return - V_177 ;
V_161 = F_96 ( V_11 , V_7 ) ;
if ( V_161 )
return V_161 ;
V_161 = F_82 ( V_11 , V_7 ) ;
if ( V_161 )
return V_161 ;
V_174 = F_101 ( V_3 , V_178 , 0 ) ;
V_11 -> V_44 = F_102 ( V_7 , V_174 ) ;
if ( F_84 ( V_11 -> V_44 ) )
return F_85 ( V_11 -> V_44 ) ;
V_174 = F_103 ( V_3 , V_179 , L_25 ) ;
if ( ! V_174 ) {
F_38 ( V_7 , L_26 ) ;
return - V_180 ;
}
V_11 -> V_141 = V_174 -> V_181 ;
V_161 = F_104 ( V_7 , V_11 -> V_141 , F_73 ,
0 , L_27 , V_11 ) ;
if ( V_161 ) {
F_38 ( V_7 , L_26 ) ;
return V_161 ;
}
V_11 -> V_41 = F_1 ( V_3 ) ;
F_105 ( & V_11 -> V_78 ) ;
F_34 ( & V_11 -> V_77 , 0 ) ;
V_24 = & V_11 -> V_24 ;
V_24 -> V_7 = V_7 ;
V_24 -> V_25 = & V_182 ;
V_24 -> V_183 = F_77 ;
V_24 -> remove = F_80 ;
F_106 ( & V_11 -> V_16 ) ;
F_107 ( V_3 , V_11 ) ;
F_108 ( V_7 ) ;
F_11 ( V_7 ) ;
for ( V_82 = 0 ; V_82 < V_35 ; V_82 ++ )
F_89 ( V_11 , V_82 ) ;
F_109 ( V_24 ) ;
return 0 ;
}
static int F_110 ( struct V_2 * V_3 )
{
struct V_9 * V_7 = & V_3 -> V_7 ;
struct V_10 * V_11 = F_111 ( V_3 ) ;
F_112 ( & V_11 -> V_24 ) ;
if ( V_11 -> V_18 )
goto V_149;
F_113 ( V_7 ) ;
F_12 ( V_7 ) ;
V_149:
F_114 ( V_7 ) ;
return 0 ;
}
static int F_115 ( struct V_9 * V_7 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
if ( ! F_116 ( V_7 ) )
return F_95 ( V_11 , false ) ;
return 0 ;
}
static int F_117 ( struct V_9 * V_7 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
if ( ! F_116 ( V_7 ) ) {
int V_161 ;
V_161 = F_95 ( V_11 , true ) ;
if ( V_161 < 0 )
return V_161 ;
F_14 ( V_7 ) ;
}
return 0 ;
}
static int F_118 ( struct V_9 * V_7 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
return F_95 ( V_11 , false ) ;
}
static int F_119 ( struct V_9 * V_7 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
return F_95 ( V_11 , true ) ;
}
