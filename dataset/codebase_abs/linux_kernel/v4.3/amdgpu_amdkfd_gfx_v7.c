struct V_1 * F_1 ()
{
return (struct V_1 * ) & V_2 ;
}
static inline struct V_3 * F_2 ( struct V_4 * V_5 )
{
return (struct V_3 * ) V_5 ;
}
static void F_3 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_7 ,
T_1 V_8 , T_1 V_9 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_11 = F_4 ( V_7 ) | F_5 ( V_6 ) | F_6 ( V_9 ) | F_7 ( V_8 ) ;
F_8 ( & V_10 -> V_12 ) ;
F_9 ( V_13 , V_11 ) ;
}
static void F_10 ( struct V_4 * V_5 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
F_9 ( V_13 , 0 ) ;
F_11 ( & V_10 -> V_12 ) ;
}
static void F_12 ( struct V_4 * V_5 , T_1 V_14 ,
T_1 V_15 )
{
T_1 V_6 = ( ++ V_14 / V_16 ) + 1 ;
T_1 V_7 = ( V_14 % V_16 ) ;
F_3 ( V_5 , V_6 , V_7 , V_15 , 0 ) ;
}
static void F_13 ( struct V_4 * V_5 )
{
F_10 ( V_5 ) ;
}
static void F_14 ( struct V_4 * V_5 , T_1 V_9 ,
T_1 V_17 ,
T_1 V_18 ,
T_1 V_19 ,
T_1 V_20 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
F_3 ( V_5 , 0 , 0 , 0 , V_9 ) ;
F_9 ( V_21 , V_17 ) ;
F_9 ( V_22 , V_18 ) ;
F_9 ( V_23 , V_19 ) ;
F_9 ( V_24 , V_20 ) ;
F_10 ( V_5 ) ;
}
static int F_15 ( struct V_4 * V_5 , unsigned int V_25 ,
unsigned int V_9 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_26 = ( V_25 == 0 ) ? 0 : ( T_1 ) V_25 |
V_27 ;
F_9 ( V_28 + V_9 , V_26 ) ;
while ( ! ( F_16 ( V_29 ) & ( 1U << V_9 ) ) )
F_17 () ;
F_9 ( V_29 , 1U << V_9 ) ;
F_9 ( V_30 + V_9 , V_26 ) ;
return 0 ;
}
static int F_18 ( struct V_4 * V_5 , T_1 V_14 ,
T_1 V_31 , T_2 V_32 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_6 = ( ++ V_14 / V_16 ) + 1 ;
T_1 V_7 = ( V_14 % V_16 ) ;
F_3 ( V_5 , V_6 , V_7 , 0 , 0 ) ;
F_9 ( V_33 , F_19 ( V_32 >> 8 ) ) ;
F_9 ( V_34 , F_20 ( V_32 >> 8 ) ) ;
F_9 ( V_35 , 0 ) ;
F_9 ( V_36 , V_31 ) ;
F_10 ( V_5 ) ;
return 0 ;
}
static int F_21 ( struct V_4 * V_5 , T_1 V_14 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_6 ;
T_1 V_7 ;
V_6 = ( V_14 / V_16 ) + 1 ;
V_7 = ( V_14 % V_16 ) ;
F_3 ( V_5 , V_6 , V_7 , 0 , 0 ) ;
F_9 ( V_37 , V_38 |
V_39 ) ;
F_10 ( V_5 ) ;
return 0 ;
}
static inline T_1 F_22 ( struct V_40 * V_41 )
{
T_1 V_42 ;
V_42 = V_41 -> V_43 * V_44 +
V_41 -> V_45 * V_46 ;
F_23 ( L_1 , V_42 ) ;
return V_42 ;
}
static inline struct V_47 * F_24 ( void * V_48 )
{
return (struct V_47 * ) V_48 ;
}
static inline struct V_40 * F_25 ( void * V_48 )
{
return (struct V_40 * ) V_48 ;
}
static int F_26 ( struct V_4 * V_5 , void * V_48 , T_1 V_14 ,
T_1 V_15 , T_1 T_3 * V_49 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_50 , V_51 ;
struct V_47 * V_41 ;
V_41 = F_24 ( V_48 ) ;
V_51 = ! F_27 ( V_50 , V_49 ) ;
F_12 ( V_5 , V_14 , V_15 ) ;
F_9 ( V_52 , V_41 -> V_53 ) ;
F_9 ( V_54 , V_41 -> V_55 ) ;
F_9 ( V_56 , V_41 -> V_57 ) ;
F_9 ( V_58 , V_41 -> V_59 ) ;
F_9 ( V_60 , V_41 -> V_61 ) ;
F_9 ( V_62 , V_41 -> V_63 ) ;
F_9 ( V_64 , V_41 -> V_65 ) ;
F_9 ( V_66 , V_41 -> V_67 ) ;
F_9 ( V_68 , V_41 -> V_69 ) ;
F_9 ( V_70 , V_41 -> V_71 ) ;
F_9 ( V_72 , V_41 -> V_73 ) ;
F_9 ( V_74 , V_41 -> V_75 ) ;
F_9 ( V_76 , V_41 -> V_77 ) ;
F_9 ( V_78 , V_41 -> V_79 ) ;
F_9 ( V_80 , V_41 -> V_81 ) ;
F_9 ( V_82 , V_41 -> V_83 ) ;
F_9 ( V_84 , V_41 -> V_85 ) ;
F_9 ( V_86 , V_41 -> V_87 ) ;
F_9 ( V_88 ,
V_41 -> V_89 ) ;
F_9 ( V_90 , V_41 -> V_91 ) ;
F_9 ( V_92 , V_41 -> V_93 ) ;
F_9 ( V_94 , V_41 -> V_95 ) ;
F_9 ( V_96 , V_41 -> V_97 ) ;
F_9 ( V_98 , V_41 -> V_99 ) ;
F_9 ( V_100 , V_41 -> V_101 ) ;
F_9 ( V_102 , V_41 -> V_103 ) ;
F_9 ( V_104 , V_41 -> V_105 ) ;
F_9 ( V_106 , V_41 -> V_107 ) ;
if ( V_51 )
F_9 ( V_108 , V_50 ) ;
F_9 ( V_109 , V_41 -> V_110 ) ;
F_13 ( V_5 ) ;
return 0 ;
}
static int F_28 ( struct V_4 * V_5 , void * V_48 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
struct V_40 * V_41 ;
T_1 V_111 ;
V_41 = F_25 ( V_48 ) ;
V_111 = F_22 ( V_41 ) ;
F_9 ( V_111 + V_112 ,
V_41 -> V_113 ) ;
F_9 ( V_111 + V_114 ,
V_41 -> V_115 ) ;
F_9 ( V_111 + V_116 ,
V_41 -> V_117 ) ;
F_9 ( V_111 + V_118 ,
V_41 -> V_119 ) ;
F_9 ( V_111 + V_120 ,
V_41 -> V_121 ) ;
F_9 ( V_111 + V_122 ,
V_41 -> V_123 ) ;
F_9 ( V_111 + V_124 ,
V_41 -> V_125 ) ;
return 0 ;
}
static bool F_29 ( struct V_4 * V_5 , T_2 V_126 ,
T_1 V_14 , T_1 V_15 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_127 ;
bool V_42 = false ;
T_1 V_128 , V_129 ;
F_12 ( V_5 , V_14 , V_15 ) ;
V_127 = F_16 ( V_109 ) ;
if ( V_127 ) {
V_128 = F_19 ( V_126 >> 8 ) ;
V_129 = F_20 ( V_126 >> 8 ) ;
if ( V_128 == F_16 ( V_58 ) &&
V_129 == F_16 ( V_60 ) )
V_42 = true ;
}
F_13 ( V_5 ) ;
return V_42 ;
}
static bool F_30 ( struct V_4 * V_5 , void * V_48 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
struct V_40 * V_41 ;
T_1 V_111 ;
T_1 V_125 ;
V_41 = F_25 ( V_48 ) ;
V_111 = F_22 ( V_41 ) ;
V_125 = F_16 ( V_111 + V_124 ) ;
if ( V_125 & V_130 )
return true ;
return false ;
}
static int F_31 ( struct V_4 * V_5 , T_1 V_131 ,
unsigned int V_132 , T_1 V_14 ,
T_1 V_15 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_133 ;
F_12 ( V_5 , V_14 , V_15 ) ;
F_9 ( V_96 , 0 ) ;
F_9 ( V_134 , V_131 ) ;
while ( true ) {
V_133 = F_16 ( V_109 ) ;
if ( V_133 & V_135 )
break;
if ( V_132 == 0 ) {
F_32 ( L_2 ,
V_133 ) ;
F_13 ( V_5 ) ;
return - V_136 ;
}
F_33 ( 20 ) ;
V_132 -= 20 ;
}
F_13 ( V_5 ) ;
return 0 ;
}
static int F_34 ( struct V_4 * V_5 , void * V_48 ,
unsigned int V_132 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
struct V_40 * V_41 ;
T_1 V_111 ;
T_1 V_133 ;
V_41 = F_25 ( V_48 ) ;
V_111 = F_22 ( V_41 ) ;
V_133 = F_16 ( V_111 + V_124 ) ;
V_133 = V_133 & ~ V_130 ;
F_9 ( V_111 + V_124 , V_133 ) ;
while ( true ) {
V_133 = F_16 ( V_111 + V_137 ) ;
if ( V_133 & V_138 )
break;
if ( V_132 == 0 )
return - V_136 ;
F_33 ( 20 ) ;
V_132 -= 20 ;
}
F_9 ( V_111 + V_122 , 0 ) ;
F_9 ( V_111 + V_139 , 0 ) ;
F_9 ( V_111 + V_140 , 0 ) ;
F_9 ( V_111 + V_114 , 0 ) ;
return 0 ;
}
static int F_35 ( struct V_4 * V_5 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
union V_141 V_142 ;
unsigned int V_143 ;
V_142 . V_144 = 0 ;
V_142 . V_145 . V_146 = 0 ;
V_142 . V_145 . V_147 = V_148 ;
V_142 . V_145 . V_149 = 1 ;
for ( V_143 = 0 ; V_143 < V_150 ; V_143 ++ )
F_9 ( V_151 [ V_143 * V_152 +
V_153 ] , V_142 . V_144 ) ;
return 0 ;
}
static int F_36 ( struct V_4 * V_5 ,
unsigned int V_154 ,
T_1 V_155 ,
T_1 V_156 ,
T_1 V_157 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
union V_141 V_142 ;
V_142 . V_144 = V_155 ;
V_142 . V_145 . V_146 = 0 ;
F_9 ( V_151 [ V_154 * V_152 +
V_153 ] , V_142 . V_144 ) ;
F_9 ( V_151 [ V_154 * V_152 +
V_158 ] , V_156 ) ;
F_9 ( V_151 [ V_154 * V_152 +
V_159 ] , V_157 ) ;
V_142 . V_145 . V_146 = 1 ;
F_9 ( V_151 [ V_154 * V_152 +
V_153 ] , V_142 . V_144 ) ;
return 0 ;
}
static int F_37 ( struct V_4 * V_5 ,
T_1 V_160 ,
T_1 V_161 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_162 ;
F_8 ( & V_10 -> V_163 ) ;
F_9 ( V_164 , V_160 ) ;
F_9 ( V_165 , V_161 ) ;
V_162 = V_166 |
V_167 |
V_168 ;
F_9 ( V_164 , V_162 ) ;
F_11 ( & V_10 -> V_163 ) ;
return 0 ;
}
static T_1 F_38 ( struct V_4 * V_5 ,
unsigned int V_154 ,
unsigned int V_169 )
{
return V_151 [ V_154 * V_152 + V_169 ] ;
}
static bool F_39 ( struct V_4 * V_5 ,
T_4 V_9 )
{
T_1 V_170 ;
struct V_3 * V_10 = (struct V_3 * ) V_5 ;
V_170 = F_16 ( V_28 + V_9 ) ;
return V_170 & V_27 ;
}
static T_5 F_40 ( struct V_4 * V_5 ,
T_4 V_9 )
{
T_1 V_170 ;
struct V_3 * V_10 = (struct V_3 * ) V_5 ;
V_170 = F_16 ( V_28 + V_9 ) ;
return V_170 & V_27 ;
}
static void F_41 ( struct V_4 * V_5 , T_4 V_9 )
{
struct V_3 * V_10 = (struct V_3 * ) V_5 ;
F_9 ( V_171 , 1 << V_9 ) ;
}
static T_5 F_42 ( struct V_4 * V_5 , enum V_172 type )
{
struct V_3 * V_10 = (struct V_3 * ) V_5 ;
const union V_173 * V_174 ;
F_43 ( V_5 == NULL ) ;
switch ( type ) {
case V_175 :
V_174 = ( const union V_173 * )
V_10 -> V_176 . V_177 -> V_162 ;
break;
case V_178 :
V_174 = ( const union V_173 * )
V_10 -> V_176 . V_179 -> V_162 ;
break;
case V_180 :
V_174 = ( const union V_173 * )
V_10 -> V_176 . V_181 -> V_162 ;
break;
case V_182 :
V_174 = ( const union V_173 * )
V_10 -> V_176 . V_183 -> V_162 ;
break;
case V_184 :
V_174 = ( const union V_173 * )
V_10 -> V_176 . V_185 -> V_162 ;
break;
case V_186 :
V_174 = ( const union V_173 * )
V_10 -> V_176 . V_187 -> V_162 ;
break;
case V_188 :
V_174 = ( const union V_173 * )
V_10 -> V_189 [ 0 ] . V_190 -> V_162 ;
break;
case V_191 :
V_174 = ( const union V_173 * )
V_10 -> V_189 [ 1 ] . V_190 -> V_162 ;
break;
default:
return 0 ;
}
if ( V_174 == NULL )
return 0 ;
return V_174 -> V_192 . V_193 ;
}
