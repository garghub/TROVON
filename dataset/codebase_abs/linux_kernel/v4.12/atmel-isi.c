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
static void F_6 ( struct V_5 * V_6 )
{
T_1 V_10 , V_11 ;
T_1 V_12 = V_6 -> V_13 -> V_12 ;
V_6 -> V_14 = V_12 == V_15 ||
V_12 == V_16 ;
V_10 = V_6 -> V_13 -> V_17 ;
F_2 ( V_6 , V_18 , V_19 ) ;
V_10 |= ( ( V_6 -> V_20 . V_20 . V_21 . V_22 - 1 ) << V_23 ) &
V_24 ;
V_10 |= ( ( V_6 -> V_20 . V_20 . V_21 . V_25 - 1 ) << V_26 )
& V_27 ;
F_2 ( V_6 , V_28 , V_10 ) ;
V_11 = ( ( V_6 -> V_20 . V_20 . V_21 . V_22 - 1 ) << V_29 ) &
V_30 ;
V_11 |= ( ( V_6 -> V_20 . V_20 . V_21 . V_25 - 1 ) << V_31 ) &
V_32 ;
F_2 ( V_6 , V_33 , V_11 ) ;
F_2 ( V_6 , V_34 , V_35 ) ;
}
static T_2 F_7 ( struct V_5 * V_6 )
{
if ( V_6 -> V_36 ) {
struct V_37 * V_38 = & V_6 -> V_36 -> V_39 ;
struct V_40 * V_41 = V_6 -> V_36 ;
F_8 ( & V_41 -> V_42 ) ;
V_38 -> V_43 . V_44 = F_9 () ;
V_38 -> V_45 = V_6 -> V_45 ++ ;
V_38 -> V_46 = V_47 ;
F_10 ( & V_38 -> V_43 , V_48 ) ;
}
if ( F_11 ( & V_6 -> V_49 ) ) {
V_6 -> V_36 = NULL ;
} else {
V_6 -> V_36 = F_12 ( V_6 -> V_49 . V_50 ,
struct V_40 , V_42 ) ;
if ( ! V_6 -> V_14 ) {
F_2 ( V_6 , V_51 ,
( T_1 ) V_6 -> V_36 -> V_52 -> V_53 ) ;
F_2 ( V_6 , V_54 ,
V_55 | V_56 ) ;
F_2 ( V_6 , V_57 , V_58 ) ;
} else {
F_2 ( V_6 , V_59 ,
( T_1 ) V_6 -> V_36 -> V_52 -> V_53 ) ;
F_2 ( V_6 , V_60 ,
V_55 | V_56 ) ;
F_2 ( V_6 , V_57 , V_61 ) ;
}
}
return V_62 ;
}
static T_2 F_13 ( int V_63 , void * V_64 )
{
struct V_5 * V_6 = V_64 ;
T_1 V_65 , V_66 , V_67 ;
T_2 V_68 = V_69 ;
F_14 ( & V_6 -> V_70 ) ;
V_65 = F_4 ( V_6 , V_71 ) ;
V_66 = F_4 ( V_6 , V_72 ) ;
V_67 = V_65 & V_66 ;
if ( V_67 & V_73 ) {
F_15 ( & V_6 -> F_15 ) ;
F_2 ( V_6 , V_74 , V_73 ) ;
V_68 = V_62 ;
} else if ( V_67 & V_19 ) {
F_15 ( & V_6 -> F_15 ) ;
F_2 ( V_6 , V_74 , V_19 ) ;
V_68 = V_62 ;
} else {
if ( F_16 ( V_67 & V_75 ) ||
F_16 ( V_67 & V_76 ) )
V_68 = F_7 ( V_6 ) ;
}
F_17 ( & V_6 -> V_70 ) ;
return V_68 ;
}
static int F_18 ( struct V_5 * V_6 , int V_77 )
{
unsigned long V_78 ;
F_19 ( & V_6 -> F_15 ) ;
if ( V_77 ) {
F_2 ( V_6 , V_79 , V_73 ) ;
F_2 ( V_6 , V_18 , V_73 ) ;
} else {
F_2 ( V_6 , V_79 , V_19 ) ;
F_2 ( V_6 , V_18 , V_19 ) ;
}
V_78 = F_20 ( & V_6 -> F_15 ,
F_21 ( 500 ) ) ;
if ( V_78 == 0 )
return - V_80 ;
return 0 ;
}
static int F_22 ( struct V_81 * V_82 ,
unsigned int * V_83 , unsigned int * V_84 ,
unsigned int V_85 [] , struct V_86 * V_87 [] )
{
struct V_5 * V_6 = F_23 ( V_82 ) ;
unsigned long V_88 ;
V_88 = V_6 -> V_20 . V_20 . V_21 . V_89 ;
if ( * V_84 )
return V_85 [ 0 ] < V_88 ? - V_90 : 0 ;
* V_84 = 1 ;
V_85 [ 0 ] = V_88 ;
V_6 -> V_36 = NULL ;
F_24 ( V_6 -> V_91 , L_1 , V_92 ,
* V_83 , V_88 ) ;
return 0 ;
}
static int F_25 ( struct V_93 * V_39 )
{
struct V_37 * V_38 = F_26 ( V_39 ) ;
struct V_40 * V_41 = F_27 ( V_38 , struct V_40 , V_39 ) ;
V_41 -> V_52 = NULL ;
F_28 ( & V_41 -> V_42 ) ;
return 0 ;
}
static int F_29 ( struct V_93 * V_39 )
{
struct V_37 * V_38 = F_26 ( V_39 ) ;
struct V_40 * V_41 = F_27 ( V_38 , struct V_40 , V_39 ) ;
struct V_5 * V_6 = F_23 ( V_39 -> V_81 ) ;
unsigned long V_88 ;
struct V_94 * V_95 ;
V_88 = V_6 -> V_20 . V_20 . V_21 . V_89 ;
if ( F_30 ( V_39 , 0 ) < V_88 ) {
F_31 ( V_6 -> V_91 , L_2 ,
V_92 , F_30 ( V_39 , 0 ) , V_88 ) ;
return - V_90 ;
}
F_32 ( V_39 , 0 , V_88 ) ;
if ( ! V_41 -> V_52 ) {
if ( F_11 ( & V_6 -> V_96 ) ) {
F_31 ( V_6 -> V_91 , L_3 ) ;
return - V_90 ;
} else {
V_95 = F_12 ( V_6 -> V_96 . V_50 ,
struct V_94 , V_42 ) ;
F_8 ( & V_95 -> V_42 ) ;
V_95 -> V_97 -> V_98 =
F_33 ( V_39 , 0 ) ;
V_95 -> V_97 -> V_99 = 0 ;
F_1 ( V_95 -> V_97 , V_100 ) ;
V_41 -> V_52 = V_95 ;
}
}
return 0 ;
}
static void F_34 ( struct V_93 * V_39 )
{
struct V_37 * V_38 = F_26 ( V_39 ) ;
struct V_5 * V_6 = F_23 ( V_39 -> V_81 ) ;
struct V_40 * V_41 = F_27 ( V_38 , struct V_40 , V_39 ) ;
if ( V_41 -> V_52 )
F_35 ( & V_41 -> V_52 -> V_42 , & V_6 -> V_96 ) ;
}
static void F_36 ( struct V_5 * V_6 , struct V_40 * V_101 )
{
T_1 V_3 , V_102 ;
V_102 = F_4 ( V_6 , V_103 ) ;
F_2 ( V_6 , V_79 ,
V_75 | V_76 ) ;
if ( ! V_6 -> V_14 ) {
if ( F_4 ( V_6 , V_71 ) & V_104 ) {
F_31 ( V_6 -> V_91 , L_4 ) ;
return;
}
F_2 ( V_6 , V_51 ,
( T_1 ) V_101 -> V_52 -> V_53 ) ;
F_2 ( V_6 , V_54 ,
V_55 | V_56 ) ;
F_2 ( V_6 , V_57 , V_58 ) ;
} else {
F_2 ( V_6 , V_59 ,
( T_1 ) V_101 -> V_52 -> V_53 ) ;
F_2 ( V_6 , V_60 ,
V_55 | V_56 ) ;
F_2 ( V_6 , V_57 , V_61 ) ;
}
V_102 &= ~ V_105 ;
V_102 |= V_6 -> V_106 . V_107 | V_108 ;
V_3 = V_109 ;
if ( ! V_6 -> V_14 )
V_3 |= V_104 ;
F_2 ( V_6 , V_18 , V_3 ) ;
F_2 ( V_6 , V_103 , V_102 ) ;
}
static void F_37 ( struct V_93 * V_39 )
{
struct V_37 * V_38 = F_26 ( V_39 ) ;
struct V_5 * V_6 = F_23 ( V_39 -> V_81 ) ;
struct V_40 * V_41 = F_27 ( V_38 , struct V_40 , V_39 ) ;
unsigned long V_110 = 0 ;
F_38 ( & V_6 -> V_70 , V_110 ) ;
F_39 ( & V_41 -> V_42 , & V_6 -> V_49 ) ;
if ( V_6 -> V_36 == NULL ) {
V_6 -> V_36 = V_41 ;
if ( F_40 ( V_39 -> V_81 ) )
F_36 ( V_6 , V_41 ) ;
}
F_41 ( & V_6 -> V_70 , V_110 ) ;
}
static int F_42 ( struct V_81 * V_82 , unsigned int V_111 )
{
struct V_5 * V_6 = F_23 ( V_82 ) ;
struct V_40 * V_41 , * V_112 ;
int V_68 ;
V_68 = F_43 ( V_6 -> V_113 . V_114 , V_115 , V_116 , 1 ) ;
if ( V_68 && V_68 != - V_117 ) {
F_31 ( V_6 -> V_91 , L_5 ) ;
goto V_118;
}
F_44 ( V_6 -> V_91 ) ;
V_68 = F_18 ( V_6 , V_119 ) ;
if ( V_68 < 0 ) {
F_31 ( V_6 -> V_91 , L_6 ) ;
goto V_120;
}
F_2 ( V_6 , V_74 , ( T_1 ) ~ 0UL ) ;
V_6 -> V_45 = 0 ;
F_6 ( V_6 ) ;
F_45 ( & V_6 -> V_70 ) ;
F_4 ( V_6 , V_71 ) ;
F_36 ( V_6 , V_6 -> V_36 ) ;
F_46 ( & V_6 -> V_70 ) ;
return 0 ;
V_120:
F_47 ( V_6 -> V_91 ) ;
F_43 ( V_6 -> V_113 . V_114 , V_115 , V_116 , 0 ) ;
V_118:
F_45 ( & V_6 -> V_70 ) ;
V_6 -> V_36 = NULL ;
F_48 (buf, node, &isi->video_buffer_list, list) {
F_8 ( & V_41 -> V_42 ) ;
F_10 ( & V_41 -> V_39 . V_43 , V_121 ) ;
}
F_46 ( & V_6 -> V_70 ) ;
return V_68 ;
}
static void F_49 ( struct V_81 * V_82 )
{
struct V_5 * V_6 = F_23 ( V_82 ) ;
struct V_40 * V_41 , * V_112 ;
int V_68 = 0 ;
unsigned long V_78 ;
V_68 = F_43 ( V_6 -> V_113 . V_114 , V_115 , V_116 , 0 ) ;
if ( V_68 && V_68 != - V_117 )
F_31 ( V_6 -> V_91 , L_7 ) ;
F_45 ( & V_6 -> V_70 ) ;
V_6 -> V_36 = NULL ;
F_48 (buf, node, &isi->video_buffer_list, list) {
F_8 ( & V_41 -> V_42 ) ;
F_10 ( & V_41 -> V_39 . V_43 , V_122 ) ;
}
F_46 ( & V_6 -> V_70 ) ;
if ( ! V_6 -> V_14 ) {
V_78 = V_123 + V_124 * V_125 ;
while ( ( F_4 ( V_6 , V_71 ) & V_104 ) &&
F_50 ( V_123 , V_78 ) )
F_51 ( 1 ) ;
if ( F_52 ( V_123 , V_78 ) )
F_31 ( V_6 -> V_91 ,
L_8 ) ;
}
F_2 ( V_6 , V_74 ,
V_75 | V_76 ) ;
V_68 = F_18 ( V_6 , V_126 ) ;
if ( V_68 < 0 )
F_31 ( V_6 -> V_91 , L_9 ) ;
F_47 ( V_6 -> V_91 ) ;
}
static int F_53 ( struct V_127 * V_127 , void * V_128 ,
struct V_129 * V_20 )
{
struct V_5 * V_6 = F_54 ( V_127 ) ;
* V_20 = V_6 -> V_20 ;
return 0 ;
}
static const struct V_130 * F_55 ( struct V_5 * V_6 ,
unsigned int V_12 )
{
unsigned int V_131 = V_6 -> V_132 ;
const struct V_130 * V_20 ;
unsigned int V_133 ;
for ( V_133 = 0 ; V_133 < V_131 ; V_133 ++ ) {
V_20 = V_6 -> V_134 [ V_133 ] ;
if ( V_20 -> V_12 == V_12 )
return V_20 ;
}
return NULL ;
}
static int F_56 ( struct V_5 * V_6 , struct V_129 * V_135 ,
const struct V_130 * * V_13 )
{
const struct V_130 * V_136 ;
struct V_137 * V_138 = & V_135 -> V_20 . V_21 ;
struct V_139 V_140 ;
struct V_141 V_142 = {
. V_143 = V_144 ,
} ;
int V_68 ;
if ( V_135 -> type != V_145 )
return - V_90 ;
V_136 = F_55 ( V_6 , V_138 -> V_146 ) ;
if ( ! V_136 ) {
V_136 = V_6 -> V_134 [ V_6 -> V_132 - 1 ] ;
V_138 -> V_146 = V_136 -> V_12 ;
}
if ( V_138 -> V_22 > V_147 )
V_138 -> V_22 = V_147 ;
if ( V_138 -> V_25 > V_148 )
V_138 -> V_25 = V_148 ;
F_57 ( & V_142 . V_142 , V_138 , V_136 -> V_149 ) ;
V_68 = F_43 ( V_6 -> V_113 . V_114 , V_150 , V_151 ,
& V_140 , & V_142 ) ;
if ( V_68 < 0 )
return V_68 ;
F_58 ( V_138 , & V_142 . V_142 ) ;
V_138 -> V_46 = V_47 ;
V_138 -> V_152 = V_138 -> V_22 * V_136 -> V_153 ;
V_138 -> V_89 = V_138 -> V_152 * V_138 -> V_25 ;
if ( V_13 )
* V_13 = V_136 ;
return 0 ;
}
static int F_59 ( struct V_5 * V_6 , struct V_129 * V_135 )
{
struct V_141 V_142 = {
. V_143 = V_154 ,
} ;
const struct V_130 * V_13 ;
int V_68 ;
V_68 = F_56 ( V_6 , V_135 , & V_13 ) ;
if ( V_68 )
return V_68 ;
F_57 ( & V_142 . V_142 , & V_135 -> V_20 . V_21 ,
V_13 -> V_149 ) ;
V_68 = F_43 ( V_6 -> V_113 . V_114 , V_150 ,
V_151 , NULL , & V_142 ) ;
if ( V_68 < 0 )
return V_68 ;
V_6 -> V_20 = * V_135 ;
V_6 -> V_13 = V_13 ;
return 0 ;
}
static int F_60 ( struct V_127 * V_127 , void * V_128 ,
struct V_129 * V_135 )
{
struct V_5 * V_6 = F_54 ( V_127 ) ;
if ( F_40 ( & V_6 -> V_155 ) )
return - V_156 ;
return F_59 ( V_6 , V_135 ) ;
}
static int F_61 ( struct V_127 * V_127 , void * V_128 ,
struct V_129 * V_135 )
{
struct V_5 * V_6 = F_54 ( V_127 ) ;
return F_56 ( V_6 , V_135 , NULL ) ;
}
static int F_62 ( struct V_127 * V_127 , void * V_128 ,
struct V_157 * V_135 )
{
struct V_5 * V_6 = F_54 ( V_127 ) ;
if ( V_135 -> V_158 >= V_6 -> V_132 )
return - V_90 ;
V_135 -> V_146 = V_6 -> V_134 [ V_135 -> V_158 ] -> V_12 ;
return 0 ;
}
static int F_63 ( struct V_127 * V_127 , void * V_128 ,
struct V_159 * V_160 )
{
F_64 ( V_160 -> V_161 , L_10 , sizeof( V_160 -> V_161 ) ) ;
F_64 ( V_160 -> V_162 , L_11 , sizeof( V_160 -> V_162 ) ) ;
F_64 ( V_160 -> V_163 , L_12 , sizeof( V_160 -> V_163 ) ) ;
return 0 ;
}
static int F_65 ( struct V_127 * V_127 , void * V_128 ,
struct V_164 * V_133 )
{
if ( V_133 -> V_158 != 0 )
return - V_90 ;
V_133 -> type = V_165 ;
F_64 ( V_133 -> V_166 , L_13 , sizeof( V_133 -> V_166 ) ) ;
return 0 ;
}
static int F_66 ( struct V_127 * V_127 , void * V_128 , unsigned int * V_133 )
{
* V_133 = 0 ;
return 0 ;
}
static int F_67 ( struct V_127 * V_127 , void * V_128 , unsigned int V_133 )
{
if ( V_133 > 0 )
return - V_90 ;
return 0 ;
}
static int F_68 ( struct V_127 * V_127 , void * V_167 , struct V_168 * V_169 )
{
struct V_5 * V_6 = F_54 ( V_127 ) ;
if ( V_169 -> type != V_145 )
return - V_90 ;
V_169 -> V_170 . V_171 . V_172 = 2 ;
return F_43 ( V_6 -> V_113 . V_114 , V_115 , V_173 , V_169 ) ;
}
static int F_69 ( struct V_127 * V_127 , void * V_167 , struct V_168 * V_169 )
{
struct V_5 * V_6 = F_54 ( V_127 ) ;
if ( V_169 -> type != V_145 )
return - V_90 ;
V_169 -> V_170 . V_171 . V_172 = 2 ;
return F_43 ( V_6 -> V_113 . V_114 , V_115 , V_174 , V_169 ) ;
}
static int F_70 ( struct V_127 * V_127 , void * V_167 ,
struct V_175 * V_176 )
{
struct V_5 * V_6 = F_54 ( V_127 ) ;
const struct V_130 * V_136 ;
struct V_177 V_178 = {
. V_158 = V_176 -> V_158 ,
. V_143 = V_154 ,
} ;
int V_68 ;
V_136 = F_55 ( V_6 , V_176 -> V_179 ) ;
if ( ! V_136 )
return - V_90 ;
V_178 . V_180 = V_136 -> V_149 ;
V_68 = F_43 ( V_6 -> V_113 . V_114 , V_150 , V_181 ,
NULL , & V_178 ) ;
if ( V_68 )
return V_68 ;
V_176 -> type = V_182 ;
V_176 -> V_183 . V_22 = V_178 . V_184 ;
V_176 -> V_183 . V_25 = V_178 . V_185 ;
return 0 ;
}
static int F_71 ( struct V_127 * V_127 , void * V_167 ,
struct V_186 * V_187 )
{
struct V_5 * V_6 = F_54 ( V_127 ) ;
const struct V_130 * V_136 ;
struct V_188 V_189 = {
. V_158 = V_187 -> V_158 ,
. V_22 = V_187 -> V_22 ,
. V_25 = V_187 -> V_25 ,
. V_143 = V_154 ,
} ;
int V_68 ;
V_136 = F_55 ( V_6 , V_187 -> V_179 ) ;
if ( ! V_136 )
return - V_90 ;
V_189 . V_180 = V_136 -> V_149 ;
V_68 = F_43 ( V_6 -> V_113 . V_114 , V_150 ,
V_190 , NULL , & V_189 ) ;
if ( V_68 )
return V_68 ;
V_187 -> type = V_191 ;
V_187 -> V_183 = V_189 . V_192 ;
return 0 ;
}
static void F_72 ( struct V_5 * V_6 )
{
T_1 V_102 = 0 ;
if ( V_6 -> V_106 . V_193 )
V_102 |= V_194 ;
if ( V_6 -> V_106 . V_195 )
V_102 |= V_196 ;
if ( V_6 -> V_106 . V_197 )
V_102 |= V_198 ;
if ( V_6 -> V_106 . V_199 )
V_102 |= V_200 ;
if ( V_6 -> V_106 . V_201 )
V_102 |= V_202 ;
V_102 |= V_203 ;
F_44 ( V_6 -> V_91 ) ;
F_2 ( V_6 , V_18 , V_19 ) ;
F_2 ( V_6 , V_103 , V_102 ) ;
F_47 ( V_6 -> V_91 ) ;
}
static int F_73 ( struct V_5 * V_6 ,
struct V_204 * V_205 )
{
struct V_206 * V_207 = V_205 -> V_91 . V_208 ;
struct V_209 V_210 ;
int V_211 ;
V_6 -> V_106 . V_201 = 1 ;
V_6 -> V_106 . V_107 = V_212 ;
V_207 = F_74 ( V_207 , NULL ) ;
if ( ! V_207 ) {
F_31 ( & V_205 -> V_91 , L_14 ) ;
return - V_90 ;
}
V_211 = F_75 ( V_207 , & V_210 ) ;
F_76 ( V_207 ) ;
if ( V_211 ) {
F_31 ( & V_205 -> V_91 , L_15 ) ;
return V_211 ;
}
switch ( V_210 . V_213 . V_214 . V_215 ) {
case 8 :
V_6 -> V_106 . V_216 = V_217 ;
break;
case 10 :
V_6 -> V_106 . V_216 =
V_217 | V_218 ;
break;
default:
F_31 ( & V_205 -> V_91 , L_16 ,
V_210 . V_213 . V_214 . V_215 ) ;
return - V_90 ;
}
if ( V_210 . V_213 . V_214 . V_110 & V_219 )
V_6 -> V_106 . V_193 = true ;
if ( V_210 . V_213 . V_214 . V_110 & V_220 )
V_6 -> V_106 . V_195 = true ;
if ( V_210 . V_213 . V_214 . V_110 & V_221 )
V_6 -> V_106 . V_197 = true ;
if ( V_210 . V_222 == V_223 )
V_6 -> V_106 . V_199 = true ;
return 0 ;
}
static int F_77 ( struct V_127 * V_127 )
{
struct V_5 * V_6 = F_54 ( V_127 ) ;
struct V_224 * V_225 = V_6 -> V_113 . V_114 ;
int V_68 ;
if ( F_78 ( & V_6 -> V_226 ) )
return - V_227 ;
V_68 = F_79 ( V_127 ) ;
if ( V_68 < 0 )
goto V_228;
if ( ! F_80 ( V_127 ) )
goto V_229;
V_68 = F_43 ( V_225 , V_230 , V_231 , 1 ) ;
if ( V_68 < 0 && V_68 != - V_117 )
goto V_229;
V_68 = F_59 ( V_6 , & V_6 -> V_20 ) ;
if ( V_68 )
F_43 ( V_225 , V_230 , V_231 , 0 ) ;
V_229:
if ( V_68 )
F_81 ( V_127 ) ;
V_228:
F_82 ( & V_6 -> V_226 ) ;
return V_68 ;
}
static int F_83 ( struct V_127 * V_127 )
{
struct V_5 * V_6 = F_54 ( V_127 ) ;
struct V_224 * V_225 = V_6 -> V_113 . V_114 ;
bool V_232 ;
int V_68 ;
F_84 ( & V_6 -> V_226 ) ;
V_232 = F_80 ( V_127 ) ;
V_68 = F_85 ( V_127 , NULL ) ;
if ( V_232 )
F_43 ( V_225 , V_230 , V_231 , 0 ) ;
F_82 ( & V_6 -> V_226 ) ;
return V_68 ;
}
static int F_86 ( struct V_5 * V_6 )
{
struct V_129 V_135 = {
. type = V_145 ,
. V_20 . V_21 = {
. V_22 = V_233 ,
. V_25 = V_234 ,
. V_46 = V_47 ,
. V_146 = V_6 -> V_134 [ 0 ] -> V_12 ,
} ,
} ;
int V_68 ;
V_68 = F_56 ( V_6 , & V_135 , NULL ) ;
if ( V_68 )
return V_68 ;
V_6 -> V_13 = V_6 -> V_134 [ 0 ] ;
V_6 -> V_20 = V_135 ;
return 0 ;
}
static int F_87 ( struct V_5 * V_6 )
{
const struct V_130 * V_235 [ F_88 ( V_236 ) ] ;
unsigned int V_237 = 0 , V_133 , V_238 ;
struct V_224 * V_114 = V_6 -> V_113 . V_114 ;
struct V_239 V_149 = {
. V_143 = V_154 ,
} ;
while ( ! F_43 ( V_114 , V_150 , V_240 ,
NULL , & V_149 ) ) {
for ( V_133 = 0 ; V_133 < F_88 ( V_236 ) ; V_133 ++ ) {
if ( V_236 [ V_133 ] . V_149 != V_149 . V_180 )
continue;
for ( V_238 = 0 ; V_238 < V_237 ; V_238 ++ )
if ( V_235 [ V_238 ] -> V_12 == V_236 [ V_133 ] . V_12 )
break;
if ( V_238 == V_237 )
V_235 [ V_237 ++ ] = V_236 + V_133 ;
}
V_149 . V_158 ++ ;
}
if ( ! V_237 )
return - V_241 ;
V_6 -> V_132 = V_237 ;
V_6 -> V_134 = F_89 ( V_6 -> V_91 ,
V_237 , sizeof( struct V_130 * ) ,
V_242 ) ;
if ( ! V_6 -> V_134 ) {
F_31 ( V_6 -> V_91 , L_17 ) ;
return - V_243 ;
}
memcpy ( V_6 -> V_134 , V_235 ,
V_237 * sizeof( struct V_130 * ) ) ;
V_6 -> V_13 = V_6 -> V_134 [ 0 ] ;
return 0 ;
}
static int F_90 ( struct V_244 * V_245 )
{
struct V_5 * V_6 = F_91 ( V_245 ) ;
int V_68 ;
V_6 -> V_246 -> V_247 = V_6 -> V_113 . V_114 -> V_247 ;
V_68 = F_87 ( V_6 ) ;
if ( V_68 ) {
F_31 ( V_6 -> V_91 , L_18 ) ;
return V_68 ;
}
F_72 ( V_6 ) ;
V_68 = F_86 ( V_6 ) ;
if ( V_68 ) {
F_31 ( V_6 -> V_91 , L_19 ) ;
return V_68 ;
}
V_68 = F_92 ( V_6 -> V_246 , V_248 , - 1 ) ;
if ( V_68 ) {
F_31 ( V_6 -> V_91 , L_20 ) ;
return V_68 ;
}
F_24 ( V_6 -> V_91 , L_21 ,
F_93 ( V_6 -> V_246 ) ) ;
return 0 ;
}
static void F_94 ( struct V_244 * V_245 ,
struct V_224 * V_225 ,
struct V_249 * V_250 )
{
struct V_5 * V_6 = F_91 ( V_245 ) ;
F_24 ( V_6 -> V_91 , L_22 , F_93 ( V_6 -> V_246 ) ) ;
F_95 ( V_6 -> V_246 ) ;
}
static int F_96 ( struct V_244 * V_245 ,
struct V_224 * V_114 ,
struct V_249 * V_250 )
{
struct V_5 * V_6 = F_91 ( V_245 ) ;
F_24 ( V_6 -> V_91 , L_23 , V_114 -> V_166 ) ;
V_6 -> V_113 . V_114 = V_114 ;
return 0 ;
}
static int F_97 ( struct V_5 * V_6 , struct V_206 * V_112 )
{
struct V_206 * V_210 = NULL ;
struct V_206 * V_251 ;
while ( 1 ) {
V_210 = F_74 ( V_112 , V_210 ) ;
if ( ! V_210 )
return - V_90 ;
V_251 = F_98 ( V_210 ) ;
if ( ! V_251 ) {
F_76 ( V_210 ) ;
return - V_90 ;
}
V_6 -> V_113 . V_112 = V_251 ;
V_6 -> V_113 . V_250 . V_252 = V_253 ;
V_6 -> V_113 . V_250 . V_254 . V_255 . V_112 = V_251 ;
return 0 ;
}
}
static int F_99 ( struct V_5 * V_6 )
{
struct V_249 * * V_256 = NULL ;
int V_68 ;
V_68 = F_97 ( V_6 , V_6 -> V_91 -> V_208 ) ;
if ( V_68 < 0 ) {
F_31 ( V_6 -> V_91 , L_24 ) ;
return V_68 ;
}
V_256 = F_100 ( V_6 -> V_91 , sizeof( * V_256 ) , V_242 ) ;
if ( V_256 == NULL ) {
F_76 ( V_6 -> V_113 . V_112 ) ;
return - V_243 ;
}
V_256 [ 0 ] = & V_6 -> V_113 . V_250 ;
V_6 -> V_245 . V_256 = V_256 ;
V_6 -> V_245 . V_257 = 1 ;
V_6 -> V_245 . V_258 = F_96 ;
V_6 -> V_245 . V_259 = F_94 ;
V_6 -> V_245 . F_15 = F_90 ;
V_68 = F_101 ( & V_6 -> V_260 , & V_6 -> V_245 ) ;
if ( V_68 < 0 ) {
F_31 ( V_6 -> V_91 , L_25 ) ;
F_76 ( V_6 -> V_113 . V_112 ) ;
return V_68 ;
}
return 0 ;
}
static int F_102 ( struct V_204 * V_205 )
{
int V_63 ;
struct V_5 * V_6 ;
struct V_81 * V_261 ;
struct V_262 * V_9 ;
int V_68 , V_133 ;
V_6 = F_100 ( & V_205 -> V_91 , sizeof( struct V_5 ) , V_242 ) ;
if ( ! V_6 ) {
F_31 ( & V_205 -> V_91 , L_26 ) ;
return - V_243 ;
}
V_6 -> V_263 = F_103 ( & V_205 -> V_91 , L_27 ) ;
if ( F_104 ( V_6 -> V_263 ) )
return F_105 ( V_6 -> V_263 ) ;
V_68 = F_73 ( V_6 , V_205 ) ;
if ( V_68 )
return V_68 ;
V_6 -> V_36 = NULL ;
V_6 -> V_91 = & V_205 -> V_91 ;
F_106 ( & V_6 -> V_226 ) ;
F_107 ( & V_6 -> V_70 ) ;
F_28 ( & V_6 -> V_49 ) ;
F_28 ( & V_6 -> V_96 ) ;
V_261 = & V_6 -> V_155 ;
V_68 = F_108 ( & V_205 -> V_91 , & V_6 -> V_260 ) ;
if ( V_68 )
return V_68 ;
V_6 -> V_246 = F_109 () ;
if ( V_6 -> V_246 == NULL ) {
V_68 = - V_243 ;
goto V_264;
}
V_6 -> V_246 -> V_265 = & V_266 ;
V_6 -> V_246 -> V_260 = & V_6 -> V_260 ;
V_6 -> V_246 -> V_155 = & V_6 -> V_155 ;
F_64 ( V_6 -> V_246 -> V_166 , V_267 , sizeof( V_6 -> V_246 -> V_166 ) ) ;
V_6 -> V_246 -> V_268 = V_269 ;
V_6 -> V_246 -> V_270 = & V_271 ;
V_6 -> V_246 -> V_226 = & V_6 -> V_226 ;
V_6 -> V_246 -> V_272 = V_273 | V_274 |
V_275 ;
F_110 ( V_6 -> V_246 , V_6 ) ;
V_261 -> type = V_145 ;
V_261 -> V_276 = V_277 | V_278 | V_279 ;
V_261 -> V_226 = & V_6 -> V_226 ;
V_261 -> V_280 = V_6 ;
V_261 -> V_281 = sizeof( struct V_40 ) ;
V_261 -> V_282 = & V_283 ;
V_261 -> V_284 = & V_285 ;
V_261 -> V_286 = V_287 ;
V_261 -> V_288 = 2 ;
V_261 -> V_91 = & V_205 -> V_91 ;
V_68 = F_111 ( V_261 ) ;
if ( V_68 < 0 ) {
F_31 ( & V_205 -> V_91 , L_28 ) ;
goto V_289;
}
V_6 -> V_290 = F_112 ( & V_205 -> V_91 ,
sizeof( struct V_1 ) * V_291 ,
& V_6 -> V_292 ,
V_242 ) ;
if ( ! V_6 -> V_290 ) {
F_31 ( & V_205 -> V_91 , L_29 ) ;
V_68 = - V_243 ;
goto V_293;
}
for ( V_133 = 0 ; V_133 < V_291 ; V_133 ++ ) {
V_6 -> V_294 [ V_133 ] . V_97 = V_6 -> V_290 + V_133 ;
V_6 -> V_294 [ V_133 ] . V_53 = V_6 -> V_292 +
V_133 * sizeof( struct V_1 ) ;
F_35 ( & V_6 -> V_294 [ V_133 ] . V_42 , & V_6 -> V_96 ) ;
}
V_9 = F_113 ( V_205 , V_295 , 0 ) ;
V_6 -> V_9 = F_114 ( & V_205 -> V_91 , V_9 ) ;
if ( F_104 ( V_6 -> V_9 ) ) {
V_68 = F_105 ( V_6 -> V_9 ) ;
goto V_296;
}
if ( V_6 -> V_106 . V_216 & V_217 )
V_6 -> V_297 = 1 << 7 ;
if ( V_6 -> V_106 . V_216 & V_218 )
V_6 -> V_297 |= 1 << 9 ;
V_63 = F_115 ( V_205 , 0 ) ;
if ( V_63 < 0 ) {
V_68 = V_63 ;
goto V_298;
}
V_68 = F_116 ( & V_205 -> V_91 , V_63 , F_13 , 0 , L_30 , V_6 ) ;
if ( V_68 ) {
F_31 ( & V_205 -> V_91 , L_31 , V_63 ) ;
goto V_298;
}
V_6 -> V_63 = V_63 ;
V_68 = F_99 ( V_6 ) ;
if ( V_68 < 0 )
goto V_298;
F_117 ( & V_205 -> V_91 , true ) ;
F_118 ( & V_205 -> V_91 ) ;
F_119 ( V_205 , V_6 ) ;
return 0 ;
V_298:
V_296:
F_120 ( & V_205 -> V_91 ,
sizeof( struct V_1 ) * V_291 ,
V_6 -> V_290 ,
V_6 -> V_292 ) ;
V_293:
V_289:
V_269 ( V_6 -> V_246 ) ;
V_264:
F_121 ( & V_6 -> V_260 ) ;
return V_68 ;
}
static int F_122 ( struct V_204 * V_205 )
{
struct V_5 * V_6 = F_123 ( V_205 ) ;
F_120 ( & V_205 -> V_91 ,
sizeof( struct V_1 ) * V_291 ,
V_6 -> V_290 ,
V_6 -> V_292 ) ;
F_124 ( & V_205 -> V_91 ) ;
F_125 ( & V_6 -> V_245 ) ;
F_121 ( & V_6 -> V_260 ) ;
return 0 ;
}
static int F_126 ( struct V_86 * V_91 )
{
struct V_5 * V_6 = F_127 ( V_91 ) ;
F_128 ( V_6 -> V_263 ) ;
return 0 ;
}
static int F_129 ( struct V_86 * V_91 )
{
struct V_5 * V_6 = F_127 ( V_91 ) ;
return F_130 ( V_6 -> V_263 ) ;
}
