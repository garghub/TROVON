static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 = V_3 ;
}
static void F_2 ( struct V_5 * V_6 , T_1 V_7 , T_1 V_8 )
{
F_3 ( V_8 , V_6 -> V_9 + V_7 ) ;
}
static T_1 F_4 ( struct V_5 * V_6 , T_1 V_7 )
{
return F_5 ( V_6 -> V_9 + V_7 ) ;
}
static int F_6 ( struct V_5 * V_6 , T_1 V_10 ,
T_1 V_11 , enum V_12 V_13 )
{
T_1 V_14 , V_15 ;
switch ( V_13 ) {
case V_16 :
V_15 = V_17 ;
break;
case V_18 :
V_15 = V_19 ;
break;
case V_20 :
V_15 = V_21 ;
break;
case V_22 :
V_15 = V_23 ;
break;
case V_24 :
V_15 = V_25 ;
break;
default:
return - V_26 ;
}
F_2 ( V_6 , V_27 , V_28 ) ;
V_14 = F_4 ( V_6 , V_29 ) ;
V_14 |= V_15 ;
V_14 &= ~ ( V_30 ) ;
V_14 |= ( ( V_10 - 1 ) << V_31 ) &
V_30 ;
V_14 &= ~ ( V_32 ) ;
V_14 |= ( ( V_11 - 1 ) << V_33 )
& V_32 ;
F_2 ( V_6 , V_29 , V_14 ) ;
return 0 ;
}
static T_2 F_7 ( struct V_5 * V_6 )
{
if ( V_6 -> V_34 ) {
struct V_35 * V_36 = & V_6 -> V_34 -> V_36 ;
struct V_37 * V_38 = V_6 -> V_34 ;
F_8 ( & V_38 -> V_39 ) ;
F_9 ( & V_36 -> V_40 . V_41 ) ;
V_36 -> V_40 . V_42 = V_6 -> V_42 ++ ;
F_10 ( V_36 , V_43 ) ;
}
if ( F_11 ( & V_6 -> V_44 ) ) {
V_6 -> V_34 = NULL ;
} else {
V_6 -> V_34 = F_12 ( V_6 -> V_44 . V_45 ,
struct V_37 , V_39 ) ;
F_2 ( V_6 , V_46 ,
V_6 -> V_34 -> V_47 -> V_48 ) ;
F_2 ( V_6 , V_49 ,
V_50 | V_51 ) ;
F_2 ( V_6 , V_52 , V_53 ) ;
}
return V_54 ;
}
static T_2 F_13 ( int V_55 , void * V_56 )
{
struct V_5 * V_6 = V_56 ;
T_1 V_57 , V_58 , V_59 ;
T_2 V_60 = V_61 ;
F_14 ( & V_6 -> V_62 ) ;
V_57 = F_4 ( V_6 , V_63 ) ;
V_58 = F_4 ( V_6 , V_64 ) ;
V_59 = V_57 & V_58 ;
if ( V_59 & V_65 ) {
F_15 ( & V_6 -> F_15 ) ;
F_2 ( V_6 , V_66 , V_65 ) ;
V_60 = V_54 ;
} else if ( V_59 & V_28 ) {
F_15 ( & V_6 -> F_15 ) ;
F_2 ( V_6 , V_66 , V_28 ) ;
V_60 = V_54 ;
} else {
if ( ( V_59 & V_67 ) &&
( V_6 -> V_68 == V_69 ) ) {
V_6 -> V_68 = V_70 ;
F_16 ( & V_6 -> V_71 ) ;
V_60 = V_54 ;
}
if ( F_17 ( V_59 & V_72 ) )
V_60 = F_7 ( V_6 ) ;
}
F_18 ( & V_6 -> V_62 ) ;
return V_60 ;
}
static int F_19 ( struct V_5 * V_6 , int V_73 )
{
unsigned long V_74 ;
F_20 ( & V_6 -> F_15 ) ;
if ( V_73 ) {
F_2 ( V_6 , V_75 , V_65 ) ;
F_2 ( V_6 , V_27 , V_65 ) ;
} else {
F_2 ( V_6 , V_75 , V_28 ) ;
F_2 ( V_6 , V_27 , V_28 ) ;
}
V_74 = F_21 ( & V_6 -> F_15 ,
F_22 ( 100 ) ) ;
if ( V_74 == 0 )
return - V_76 ;
return 0 ;
}
static int F_23 ( struct V_77 * V_78 , unsigned int * V_79 ,
unsigned int * V_80 , unsigned long V_81 [] ,
void * V_82 [] )
{
struct V_83 * V_84 = F_24 ( V_78 ) ;
struct V_85 * V_86 = F_25 ( V_84 -> V_87 ) ;
struct V_5 * V_6 = V_86 -> V_88 ;
unsigned long V_89 ;
int V_60 , V_90 ;
V_60 = F_19 ( V_6 , V_91 ) ;
if ( V_60 < 0 ) {
F_26 ( V_84 -> V_87 , L_1 ) ;
return V_60 ;
}
F_2 ( V_6 , V_66 , ~ 0UL ) ;
V_90 = F_27 ( V_84 -> V_92 ,
V_84 -> V_93 -> V_94 ) ;
if ( V_90 < 0 )
return V_90 ;
V_89 = V_90 * V_84 -> V_95 ;
if ( ! * V_79 || * V_79 > V_96 )
* V_79 = V_96 ;
if ( V_89 * * V_79 > V_97 )
* V_79 = V_97 / V_89 ;
* V_80 = 1 ;
V_81 [ 0 ] = V_89 ;
V_82 [ 0 ] = V_6 -> V_98 ;
V_6 -> V_42 = 0 ;
V_6 -> V_34 = NULL ;
F_28 ( V_84 -> V_87 , L_2 , V_99 ,
* V_79 , V_89 ) ;
return 0 ;
}
static int F_29 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = F_30 ( V_36 , struct V_37 , V_36 ) ;
V_38 -> V_47 = NULL ;
F_31 ( & V_38 -> V_39 ) ;
return 0 ;
}
static int F_32 ( struct V_35 * V_36 )
{
struct V_83 * V_84 = F_24 ( V_36 -> V_77 ) ;
struct V_37 * V_38 = F_30 ( V_36 , struct V_37 , V_36 ) ;
struct V_85 * V_86 = F_25 ( V_84 -> V_87 ) ;
struct V_5 * V_6 = V_86 -> V_88 ;
unsigned long V_89 ;
struct V_100 * V_101 ;
int V_90 = F_27 ( V_84 -> V_92 ,
V_84 -> V_93 -> V_94 ) ;
if ( V_90 < 0 )
return V_90 ;
V_89 = V_90 * V_84 -> V_95 ;
if ( F_33 ( V_36 , 0 ) < V_89 ) {
F_26 ( V_84 -> V_87 , L_3 ,
V_99 , F_33 ( V_36 , 0 ) , V_89 ) ;
return - V_26 ;
}
F_34 ( & V_38 -> V_36 , 0 , V_89 ) ;
if ( ! V_38 -> V_47 ) {
if ( F_11 ( & V_6 -> V_102 ) ) {
F_26 ( V_84 -> V_87 , L_4 ) ;
return - V_26 ;
} else {
V_101 = F_12 ( V_6 -> V_102 . V_45 ,
struct V_100 , V_39 ) ;
F_8 ( & V_101 -> V_39 ) ;
V_101 -> V_103 -> V_104 =
F_35 ( V_36 , 0 ) ;
V_101 -> V_103 -> V_105 = 0 ;
F_1 ( V_101 -> V_103 , V_106 ) ;
V_38 -> V_47 = V_101 ;
}
}
return 0 ;
}
static void F_36 ( struct V_35 * V_36 )
{
struct V_83 * V_84 = F_24 ( V_36 -> V_77 ) ;
struct V_85 * V_86 = F_25 ( V_84 -> V_87 ) ;
struct V_5 * V_6 = V_86 -> V_88 ;
struct V_37 * V_38 = F_30 ( V_36 , struct V_37 , V_36 ) ;
if ( V_38 -> V_47 )
F_37 ( & V_38 -> V_47 -> V_39 , & V_6 -> V_102 ) ;
}
static void F_38 ( struct V_5 * V_6 , struct V_37 * V_107 )
{
T_1 V_3 , V_108 ;
V_108 = F_4 ( V_6 , V_109 ) ;
F_2 ( V_6 , V_75 ,
V_72 | V_110 ) ;
if ( F_4 ( V_6 , V_63 ) & V_111 ) {
F_26 ( V_6 -> V_84 -> V_87 , L_5 ) ;
return;
}
F_2 ( V_6 , V_46 , V_107 -> V_47 -> V_48 ) ;
F_2 ( V_6 , V_49 , V_50 | V_51 ) ;
F_2 ( V_6 , V_52 , V_53 ) ;
V_108 |= V_6 -> V_112 -> V_113 | V_114 ;
V_3 = V_111 | V_115 ;
F_2 ( V_6 , V_27 , V_3 ) ;
F_2 ( V_6 , V_109 , V_108 ) ;
}
static void F_39 ( struct V_35 * V_36 )
{
struct V_83 * V_84 = F_24 ( V_36 -> V_77 ) ;
struct V_85 * V_86 = F_25 ( V_84 -> V_87 ) ;
struct V_5 * V_6 = V_86 -> V_88 ;
struct V_37 * V_38 = F_30 ( V_36 , struct V_37 , V_36 ) ;
unsigned long V_116 = 0 ;
F_40 ( & V_6 -> V_62 , V_116 ) ;
F_41 ( & V_38 -> V_39 , & V_6 -> V_44 ) ;
if ( V_6 -> V_34 == NULL ) {
V_6 -> V_34 = V_38 ;
F_38 ( V_6 , V_38 ) ;
}
F_42 ( & V_6 -> V_62 , V_116 ) ;
}
static int F_43 ( struct V_77 * V_78 )
{
struct V_83 * V_84 = F_24 ( V_78 ) ;
struct V_85 * V_86 = F_25 ( V_84 -> V_87 ) ;
struct V_5 * V_6 = V_86 -> V_88 ;
T_1 V_117 = 0 ;
int V_60 ;
F_44 ( & V_6 -> V_62 ) ;
V_6 -> V_68 = V_69 ;
V_117 = F_4 ( V_6 , V_63 ) ;
F_2 ( V_6 , V_75 , V_67 ) ;
F_2 ( V_6 , V_27 , V_115 ) ;
F_45 ( & V_6 -> V_62 ) ;
F_28 ( V_84 -> V_87 , L_6 ) ;
V_60 = F_46 ( V_6 -> V_71 ,
V_6 -> V_68 != V_69 ) ;
if ( V_60 )
return V_60 ;
if ( V_6 -> V_68 != V_70 )
return - V_118 ;
F_44 ( & V_6 -> V_62 ) ;
V_6 -> V_68 = V_119 ;
F_2 ( V_6 , V_66 , V_67 ) ;
F_45 ( & V_6 -> V_62 ) ;
return 0 ;
}
static int F_47 ( struct V_77 * V_78 )
{
struct V_83 * V_84 = F_24 ( V_78 ) ;
struct V_85 * V_86 = F_25 ( V_84 -> V_87 ) ;
struct V_5 * V_6 = V_86 -> V_88 ;
struct V_37 * V_38 , * V_120 ;
int V_60 = 0 ;
unsigned long V_74 ;
F_44 ( & V_6 -> V_62 ) ;
V_6 -> V_34 = NULL ;
F_48 (buf, node, &isi->video_buffer_list, list) {
F_8 ( & V_38 -> V_39 ) ;
F_10 ( & V_38 -> V_36 , V_121 ) ;
}
F_45 ( & V_6 -> V_62 ) ;
V_74 = V_122 + V_123 * V_124 ;
while ( ( F_4 ( V_6 , V_63 ) & V_111 ) &&
F_49 ( V_122 , V_74 ) )
F_50 ( 1 ) ;
if ( F_51 ( V_122 , V_74 ) ) {
F_26 ( V_84 -> V_87 ,
L_7 ) ;
return - V_76 ;
}
F_2 ( V_6 , V_66 ,
V_72 | V_110 ) ;
V_60 = F_19 ( V_6 , V_125 ) ;
if ( V_60 < 0 )
F_26 ( V_84 -> V_87 , L_8 ) ;
return V_60 ;
}
static int F_52 ( struct V_77 * V_126 ,
struct V_83 * V_84 )
{
V_126 -> type = V_127 ;
V_126 -> V_128 = V_129 ;
V_126 -> V_130 = V_84 ;
V_126 -> V_131 = sizeof( struct V_37 ) ;
V_126 -> V_132 = & V_133 ;
V_126 -> V_134 = & V_135 ;
return F_53 ( V_126 ) ;
}
static int F_54 ( struct V_83 * V_84 ,
struct V_136 * V_137 )
{
struct V_85 * V_86 = F_25 ( V_84 -> V_87 ) ;
struct V_5 * V_6 = V_86 -> V_88 ;
struct V_138 * V_139 = F_55 ( V_84 ) ;
const struct V_140 * V_141 ;
struct V_142 * V_143 = & V_137 -> V_144 . V_143 ;
struct V_145 V_146 ;
int V_60 ;
V_141 = F_56 ( V_84 , V_143 -> V_147 ) ;
if ( ! V_141 ) {
F_57 ( V_84 -> V_87 , L_9 ,
V_143 -> V_147 ) ;
return - V_26 ;
}
F_28 ( V_84 -> V_87 , L_10 ,
V_143 -> V_10 , V_143 -> V_11 ) ;
V_146 . V_10 = V_143 -> V_10 ;
V_146 . V_11 = V_143 -> V_11 ;
V_146 . V_148 = V_143 -> V_148 ;
V_146 . V_149 = V_143 -> V_149 ;
V_146 . V_13 = V_141 -> V_13 ;
V_60 = F_58 ( V_139 , V_150 , V_151 , & V_146 ) ;
if ( V_60 < 0 )
return V_60 ;
if ( V_146 . V_13 != V_141 -> V_13 )
return - V_26 ;
V_60 = F_6 ( V_6 , V_143 -> V_10 , V_143 -> V_11 , V_141 -> V_13 ) ;
if ( V_60 < 0 )
return V_60 ;
V_143 -> V_10 = V_146 . V_10 ;
V_143 -> V_11 = V_146 . V_11 ;
V_143 -> V_148 = V_146 . V_148 ;
V_143 -> V_149 = V_146 . V_149 ;
V_84 -> V_93 = V_141 ;
F_28 ( V_84 -> V_87 , L_11 ,
V_143 -> V_10 , V_143 -> V_11 ) ;
return V_60 ;
}
static int F_59 ( struct V_83 * V_84 ,
struct V_136 * V_137 )
{
struct V_138 * V_139 = F_55 ( V_84 ) ;
const struct V_140 * V_141 ;
struct V_142 * V_143 = & V_137 -> V_144 . V_143 ;
struct V_145 V_146 ;
T_1 V_152 = V_143 -> V_147 ;
int V_60 ;
V_141 = F_56 ( V_84 , V_152 ) ;
if ( V_152 && ! V_141 ) {
F_57 ( V_84 -> V_87 , L_9 , V_152 ) ;
return - V_26 ;
}
if ( V_143 -> V_11 > V_153 )
V_143 -> V_11 = V_153 ;
if ( V_143 -> V_10 > V_154 )
V_143 -> V_10 = V_154 ;
V_146 . V_10 = V_143 -> V_10 ;
V_146 . V_11 = V_143 -> V_11 ;
V_146 . V_148 = V_143 -> V_148 ;
V_146 . V_149 = V_143 -> V_149 ;
V_146 . V_13 = V_141 -> V_13 ;
V_60 = F_58 ( V_139 , V_150 , V_155 , & V_146 ) ;
if ( V_60 < 0 )
return V_60 ;
V_143 -> V_10 = V_146 . V_10 ;
V_143 -> V_11 = V_146 . V_11 ;
V_143 -> V_149 = V_146 . V_149 ;
switch ( V_146 . V_148 ) {
case V_156 :
V_143 -> V_148 = V_157 ;
break;
case V_157 :
break;
default:
F_26 ( V_84 -> V_87 , L_12 ,
V_146 . V_148 ) ;
V_60 = - V_26 ;
}
return V_60 ;
}
static bool F_60 ( const struct V_158 * V_144 )
{
return V_144 -> V_159 == V_160 ||
( V_144 -> V_161 == 8 &&
V_144 -> V_159 == V_162 ) ||
( V_144 -> V_161 > 8 &&
V_144 -> V_159 == V_163 ) ;
}
static unsigned long F_61 ( struct V_5 * V_6 )
{
unsigned long V_116 ;
V_116 = V_164 |
V_165 |
V_166 |
V_167 |
V_168 |
V_169 |
V_170 |
V_171 ;
if ( V_6 -> V_112 -> V_172 & V_173 )
V_116 |= V_174 ;
if ( V_6 -> V_112 -> V_172 & V_175 )
V_116 |= V_176 ;
if ( V_116 & V_177 )
return V_116 ;
return 0 ;
}
static int F_62 ( struct V_83 * V_84 ,
unsigned char V_178 )
{
struct V_85 * V_86 = F_25 ( V_84 -> V_87 ) ;
struct V_5 * V_6 = V_86 -> V_88 ;
unsigned long V_179 ;
int V_60 ;
V_179 = V_84 -> V_132 -> V_180 ( V_84 ) ;
V_60 = F_63 ( V_179 ,
F_61 ( V_6 ) ) ;
if ( ! V_60 )
return - V_26 ;
return 0 ;
}
static int F_64 ( struct V_83 * V_84 ,
unsigned int V_181 ,
struct V_140 * V_141 )
{
struct V_138 * V_139 = F_55 ( V_84 ) ;
int V_182 = 0 , V_60 ;
enum V_12 V_13 ;
const struct V_158 * V_144 ;
V_60 = F_58 ( V_139 , V_150 , V_183 , V_181 , & V_13 ) ;
if ( V_60 < 0 )
return 0 ;
V_144 = F_65 ( V_13 ) ;
if ( ! V_144 ) {
F_26 ( V_84 -> V_87 ,
L_13 , V_181 , V_13 ) ;
return 0 ;
}
V_60 = F_62 ( V_84 , V_144 -> V_161 ) ;
if ( V_60 < 0 ) {
F_26 ( V_84 -> V_87 ,
L_14 ) ;
return 0 ;
}
switch ( V_13 ) {
case V_18 :
case V_20 :
case V_22 :
case V_24 :
V_182 ++ ;
if ( V_141 ) {
V_141 -> V_94 = & V_184 [ 0 ] ;
V_141 -> V_13 = V_13 ;
V_141 ++ ;
F_28 ( V_84 -> V_87 , L_15 ,
V_184 [ 0 ] . V_185 , V_13 ) ;
}
break;
default:
if ( ! F_60 ( V_144 ) )
return 0 ;
if ( V_141 )
F_28 ( V_84 -> V_87 ,
L_16 ,
V_144 -> V_185 ) ;
}
V_182 ++ ;
if ( V_141 ) {
V_141 -> V_94 = V_144 ;
V_141 -> V_13 = V_13 ;
V_141 ++ ;
}
return V_182 ;
}
static int F_66 ( struct V_83 * V_84 )
{
struct V_85 * V_86 = F_25 ( V_84 -> V_87 ) ;
struct V_5 * V_6 = V_86 -> V_88 ;
int V_60 ;
if ( V_6 -> V_84 )
return - V_186 ;
V_60 = F_67 ( V_6 -> V_187 ) ;
if ( V_60 )
return V_60 ;
V_6 -> V_84 = V_84 ;
F_28 ( V_84 -> V_87 , L_17 ,
V_84 -> V_188 ) ;
return 0 ;
}
static void F_68 ( struct V_83 * V_84 )
{
struct V_85 * V_86 = F_25 ( V_84 -> V_87 ) ;
struct V_5 * V_6 = V_86 -> V_88 ;
F_69 ( V_84 != V_6 -> V_84 ) ;
F_70 ( V_6 -> V_187 ) ;
V_6 -> V_84 = NULL ;
F_28 ( V_84 -> V_87 , L_18 ,
V_84 -> V_188 ) ;
}
static unsigned int F_71 ( struct V_189 * V_189 , T_3 * V_190 )
{
struct V_83 * V_84 = V_189 -> V_191 ;
return F_72 ( & V_84 -> V_192 , V_189 , V_190 ) ;
}
static int F_73 ( struct V_85 * V_86 ,
struct V_193 * V_194 )
{
strcpy ( V_194 -> V_195 , L_19 ) ;
strcpy ( V_194 -> V_196 , L_20 ) ;
V_194 -> V_197 = ( V_198 |
V_199 ) ;
return 0 ;
}
static int F_74 ( struct V_83 * V_84 , T_1 V_152 )
{
struct V_85 * V_86 = F_25 ( V_84 -> V_87 ) ;
struct V_5 * V_6 = V_86 -> V_88 ;
unsigned long V_200 , V_179 , V_201 ;
int V_60 ;
T_1 V_108 = 0 ;
V_179 = V_84 -> V_132 -> V_180 ( V_84 ) ;
V_200 = F_61 ( V_6 ) ;
V_201 = F_63 ( V_179 , V_200 ) ;
F_28 ( V_84 -> V_87 , L_21 ,
V_179 , V_200 , V_201 ) ;
if ( ! V_201 )
return - V_26 ;
if ( ( V_201 & V_165 ) &&
( V_201 & V_166 ) ) {
if ( V_6 -> V_112 -> V_202 )
V_201 &= ~ V_165 ;
else
V_201 &= ~ V_166 ;
}
if ( ( V_201 & V_167 ) &&
( V_201 & V_168 ) ) {
if ( V_6 -> V_112 -> V_203 )
V_201 &= ~ V_167 ;
else
V_201 &= ~ V_168 ;
}
if ( ( V_201 & V_169 ) &&
( V_201 & V_170 ) ) {
if ( V_6 -> V_112 -> V_204 )
V_201 &= ~ V_169 ;
else
V_201 &= ~ V_170 ;
}
V_60 = V_84 -> V_132 -> V_205 ( V_84 , V_201 ) ;
if ( V_60 < 0 ) {
F_28 ( V_84 -> V_87 , L_22 ,
V_201 , V_60 ) ;
return V_60 ;
}
if ( V_201 & V_166 )
V_108 |= V_206 ;
if ( V_201 & V_168 )
V_108 |= V_207 ;
if ( V_201 & V_170 )
V_108 |= V_208 ;
if ( V_6 -> V_112 -> V_209 )
V_108 |= V_210 ;
if ( V_6 -> V_112 -> V_211 )
V_108 |= V_212 ;
F_2 ( V_6 , V_27 , V_28 ) ;
F_2 ( V_6 , V_109 , V_108 ) ;
return 0 ;
}
static int T_4 F_75 ( struct V_213 * V_214 )
{
struct V_85 * V_215 = F_25 ( & V_214 -> V_216 ) ;
struct V_5 * V_6 = F_30 ( V_215 ,
struct V_5 , V_215 ) ;
F_76 ( V_6 -> V_55 , V_6 ) ;
F_77 ( V_215 ) ;
F_78 ( V_6 -> V_98 ) ;
F_79 ( & V_214 -> V_216 ,
sizeof( struct V_1 ) * V_96 ,
V_6 -> V_217 ,
V_6 -> V_218 ) ;
F_80 ( V_6 -> V_9 ) ;
F_81 ( V_6 -> V_187 ) ;
F_82 ( V_6 ) ;
return 0 ;
}
static int T_5 F_83 ( struct V_213 * V_214 )
{
unsigned int V_55 ;
struct V_5 * V_6 ;
struct V_219 * V_187 ;
struct V_220 * V_9 ;
int V_60 , V_221 ;
struct V_222 * V_216 = & V_214 -> V_216 ;
struct V_85 * V_215 ;
struct V_223 * V_112 ;
V_112 = V_216 -> V_224 ;
if ( ! V_112 || ! V_112 -> V_172 ) {
F_26 ( & V_214 -> V_216 ,
L_23 ) ;
return - V_26 ;
}
V_9 = F_84 ( V_214 , V_225 , 0 ) ;
if ( ! V_9 )
return - V_226 ;
V_187 = F_85 ( & V_214 -> V_216 , L_24 ) ;
if ( F_86 ( V_187 ) )
return F_87 ( V_187 ) ;
V_6 = F_88 ( sizeof( struct V_5 ) , V_227 ) ;
if ( ! V_6 ) {
V_60 = - V_228 ;
F_26 ( & V_214 -> V_216 , L_25 ) ;
goto V_229;
}
V_6 -> V_187 = V_187 ;
V_6 -> V_112 = V_112 ;
V_6 -> V_34 = NULL ;
F_89 ( & V_6 -> V_62 ) ;
F_90 ( & V_6 -> V_71 ) ;
F_31 ( & V_6 -> V_44 ) ;
F_31 ( & V_6 -> V_102 ) ;
V_6 -> V_217 = F_91 ( & V_214 -> V_216 ,
sizeof( struct V_1 ) * V_96 ,
& V_6 -> V_218 ,
V_227 ) ;
if ( ! V_6 -> V_217 ) {
V_60 = - V_228 ;
F_26 ( & V_214 -> V_216 , L_26 ) ;
goto V_230;
}
for ( V_221 = 0 ; V_221 < V_96 ; V_221 ++ ) {
V_6 -> V_231 [ V_221 ] . V_103 = V_6 -> V_217 + V_221 ;
V_6 -> V_231 [ V_221 ] . V_48 = V_6 -> V_218 +
V_221 * sizeof( struct V_1 ) ;
F_37 ( & V_6 -> V_231 [ V_221 ] . V_39 , & V_6 -> V_102 ) ;
}
V_6 -> V_98 = F_92 ( & V_214 -> V_216 ) ;
if ( F_86 ( V_6 -> V_98 ) ) {
V_60 = F_87 ( V_6 -> V_98 ) ;
goto V_232;
}
V_6 -> V_9 = F_93 ( V_9 -> V_233 , F_94 ( V_9 ) ) ;
if ( ! V_6 -> V_9 ) {
V_60 = - V_228 ;
goto V_234;
}
F_2 ( V_6 , V_27 , V_28 ) ;
V_55 = F_95 ( V_214 , 0 ) ;
if ( V_55 < 0 ) {
V_60 = V_55 ;
goto V_235;
}
V_60 = F_96 ( V_55 , F_13 , 0 , L_27 , V_6 ) ;
if ( V_60 ) {
F_26 ( & V_214 -> V_216 , L_28 , V_55 ) ;
goto V_235;
}
V_6 -> V_55 = V_55 ;
V_215 = & V_6 -> V_215 ;
V_215 -> V_236 = L_29 ;
V_215 -> V_132 = & V_237 ;
V_215 -> V_88 = V_6 ;
V_215 -> V_238 . V_216 = & V_214 -> V_216 ;
V_215 -> V_239 = V_214 -> V_240 ;
V_60 = F_97 ( V_215 ) ;
if ( V_60 ) {
F_26 ( & V_214 -> V_216 , L_30 ) ;
goto V_241;
}
return 0 ;
V_241:
F_76 ( V_6 -> V_55 , V_6 ) ;
V_235:
F_80 ( V_6 -> V_9 ) ;
V_234:
F_78 ( V_6 -> V_98 ) ;
V_232:
F_79 ( & V_214 -> V_216 ,
sizeof( struct V_1 ) * V_96 ,
V_6 -> V_217 ,
V_6 -> V_218 ) ;
V_230:
F_82 ( V_6 ) ;
V_229:
F_81 ( V_6 -> V_187 ) ;
return V_60 ;
}
static int T_6 F_98 ( void )
{
return F_99 ( & V_242 , & F_83 ) ;
}
static void T_7 F_100 ( void )
{
F_101 ( & V_242 ) ;
}
