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
static T_1 F_6 ( struct V_5 * V_6 ,
const struct V_10 * V_11 )
{
if ( V_11 -> V_12 -> V_13 == V_14 ) {
switch ( V_11 -> V_15 ) {
case V_16 :
return V_17 ;
case V_18 :
return V_19 ;
case V_20 :
return V_21 ;
}
} else if ( V_11 -> V_12 -> V_13 == V_22 ) {
switch ( V_11 -> V_15 ) {
case V_16 :
return V_21 ;
case V_23 :
return V_19 ;
case V_20 :
return V_17 ;
}
}
return V_24 ;
}
static void F_7 ( struct V_5 * V_6 , T_1 V_25 ,
T_1 V_26 , const struct V_10 * V_11 )
{
T_1 V_27 , V_28 ;
T_1 V_13 = V_11 -> V_12 -> V_13 ;
V_6 -> V_29 = V_13 == V_22 ||
V_13 == V_30 ;
switch ( V_11 -> V_15 ) {
default:
case V_31 :
V_27 = V_32 | V_33 ;
break;
case V_16 :
case V_18 :
case V_20 :
case V_23 :
V_27 = V_33 |
F_6 ( V_6 , V_11 ) ;
break;
}
F_2 ( V_6 , V_34 , V_35 ) ;
V_27 |= ( ( V_25 - 1 ) << V_36 ) &
V_37 ;
V_27 |= ( ( V_26 - 1 ) << V_38 )
& V_39 ;
F_2 ( V_6 , V_40 , V_27 ) ;
V_28 = ( ( V_25 - 1 ) << V_41 ) &
V_42 ;
V_28 |= ( ( V_26 - 1 ) << V_43 ) &
V_44 ;
F_2 ( V_6 , V_45 , V_28 ) ;
F_2 ( V_6 , V_46 , V_47 ) ;
return;
}
static bool F_8 ( struct V_48 * V_49 ,
const T_1 V_50 )
{
switch ( V_50 ) {
case V_51 :
case V_14 :
case V_52 :
case V_53 :
case V_54 :
case V_22 :
return true ;
default:
return false ;
}
}
static T_2 F_9 ( struct V_5 * V_6 )
{
if ( V_6 -> V_55 ) {
struct V_56 * V_57 = & V_6 -> V_55 -> V_58 ;
struct V_59 * V_60 = V_6 -> V_55 ;
F_10 ( & V_60 -> V_61 ) ;
V_57 -> V_62 . V_63 = F_11 () ;
V_57 -> V_64 = V_6 -> V_64 ++ ;
F_12 ( & V_57 -> V_62 , V_65 ) ;
}
if ( F_13 ( & V_6 -> V_66 ) ) {
V_6 -> V_55 = NULL ;
} else {
V_6 -> V_55 = F_14 ( V_6 -> V_66 . V_67 ,
struct V_59 , V_61 ) ;
if ( ! V_6 -> V_29 ) {
F_2 ( V_6 , V_68 ,
( T_1 ) V_6 -> V_55 -> V_69 -> V_70 ) ;
F_2 ( V_6 , V_71 ,
V_72 | V_73 ) ;
F_2 ( V_6 , V_74 , V_75 ) ;
} else {
F_2 ( V_6 , V_76 ,
( T_1 ) V_6 -> V_55 -> V_69 -> V_70 ) ;
F_2 ( V_6 , V_77 ,
V_72 | V_73 ) ;
F_2 ( V_6 , V_74 , V_78 ) ;
}
}
return V_79 ;
}
static T_2 F_15 ( int V_80 , void * V_81 )
{
struct V_5 * V_6 = V_81 ;
T_1 V_82 , V_83 , V_84 ;
T_2 V_85 = V_86 ;
F_16 ( & V_6 -> V_87 ) ;
V_82 = F_4 ( V_6 , V_88 ) ;
V_83 = F_4 ( V_6 , V_89 ) ;
V_84 = V_82 & V_83 ;
if ( V_84 & V_90 ) {
F_17 ( & V_6 -> F_17 ) ;
F_2 ( V_6 , V_91 , V_90 ) ;
V_85 = V_79 ;
} else if ( V_84 & V_35 ) {
F_17 ( & V_6 -> F_17 ) ;
F_2 ( V_6 , V_91 , V_35 ) ;
V_85 = V_79 ;
} else {
if ( F_18 ( V_84 & V_92 ) ||
F_18 ( V_84 & V_93 ) )
V_85 = F_9 ( V_6 ) ;
}
F_19 ( & V_6 -> V_87 ) ;
return V_85 ;
}
static int F_20 ( struct V_5 * V_6 , int V_94 )
{
unsigned long V_95 ;
F_21 ( & V_6 -> F_17 ) ;
if ( V_94 ) {
F_2 ( V_6 , V_96 , V_90 ) ;
F_2 ( V_6 , V_34 , V_90 ) ;
} else {
F_2 ( V_6 , V_96 , V_35 ) ;
F_2 ( V_6 , V_34 , V_35 ) ;
}
V_95 = F_22 ( & V_6 -> F_17 ,
F_23 ( 500 ) ) ;
if ( V_95 == 0 )
return - V_97 ;
return 0 ;
}
static int F_24 ( struct V_98 * V_99 ,
unsigned int * V_100 , unsigned int * V_101 ,
unsigned int V_102 [] , struct V_103 * V_104 [] )
{
struct V_48 * V_49 = F_25 ( V_99 ) ;
struct V_105 * V_106 = F_26 ( V_49 -> V_107 ) ;
struct V_5 * V_6 = V_106 -> V_108 ;
unsigned long V_109 ;
V_109 = V_49 -> V_110 ;
if ( ! * V_100 || * V_100 > V_111 )
* V_100 = V_111 ;
if ( V_109 * * V_100 > V_112 )
* V_100 = V_112 / V_109 ;
* V_101 = 1 ;
V_102 [ 0 ] = V_109 ;
V_6 -> V_64 = 0 ;
V_6 -> V_55 = NULL ;
F_27 ( V_49 -> V_107 , L_1 , V_113 ,
* V_100 , V_109 ) ;
return 0 ;
}
static int F_28 ( struct V_114 * V_58 )
{
struct V_56 * V_57 = F_29 ( V_58 ) ;
struct V_59 * V_60 = F_30 ( V_57 , struct V_59 , V_58 ) ;
V_60 -> V_69 = NULL ;
F_31 ( & V_60 -> V_61 ) ;
return 0 ;
}
static int F_32 ( struct V_114 * V_58 )
{
struct V_56 * V_57 = F_29 ( V_58 ) ;
struct V_48 * V_49 = F_25 ( V_58 -> V_98 ) ;
struct V_59 * V_60 = F_30 ( V_57 , struct V_59 , V_58 ) ;
struct V_105 * V_106 = F_26 ( V_49 -> V_107 ) ;
struct V_5 * V_6 = V_106 -> V_108 ;
unsigned long V_109 ;
struct V_115 * V_116 ;
V_109 = V_49 -> V_110 ;
if ( F_33 ( V_58 , 0 ) < V_109 ) {
F_34 ( V_49 -> V_107 , L_2 ,
V_113 , F_33 ( V_58 , 0 ) , V_109 ) ;
return - V_117 ;
}
F_35 ( V_58 , 0 , V_109 ) ;
if ( ! V_60 -> V_69 ) {
if ( F_13 ( & V_6 -> V_118 ) ) {
F_34 ( V_49 -> V_107 , L_3 ) ;
return - V_117 ;
} else {
V_116 = F_14 ( V_6 -> V_118 . V_67 ,
struct V_115 , V_61 ) ;
F_10 ( & V_116 -> V_61 ) ;
V_116 -> V_119 -> V_120 =
F_36 ( V_58 , 0 ) ;
V_116 -> V_119 -> V_121 = 0 ;
F_1 ( V_116 -> V_119 , V_122 ) ;
V_60 -> V_69 = V_116 ;
}
}
return 0 ;
}
static void F_37 ( struct V_114 * V_58 )
{
struct V_56 * V_57 = F_29 ( V_58 ) ;
struct V_48 * V_49 = F_25 ( V_58 -> V_98 ) ;
struct V_105 * V_106 = F_26 ( V_49 -> V_107 ) ;
struct V_5 * V_6 = V_106 -> V_108 ;
struct V_59 * V_60 = F_30 ( V_57 , struct V_59 , V_58 ) ;
if ( V_60 -> V_69 )
F_38 ( & V_60 -> V_69 -> V_61 , & V_6 -> V_118 ) ;
}
static void F_39 ( struct V_5 * V_6 , struct V_59 * V_123 )
{
T_1 V_3 , V_124 ;
V_124 = F_4 ( V_6 , V_125 ) ;
F_2 ( V_6 , V_96 ,
V_92 | V_93 ) ;
if ( ! V_6 -> V_29 ) {
if ( F_4 ( V_6 , V_88 ) & V_126 ) {
F_34 ( V_6 -> V_127 . V_49 -> V_107 , L_4 ) ;
return;
}
F_2 ( V_6 , V_68 ,
( T_1 ) V_123 -> V_69 -> V_70 ) ;
F_2 ( V_6 , V_71 ,
V_72 | V_73 ) ;
F_2 ( V_6 , V_74 , V_75 ) ;
} else {
F_2 ( V_6 , V_76 ,
( T_1 ) V_123 -> V_69 -> V_70 ) ;
F_2 ( V_6 , V_77 ,
V_72 | V_73 ) ;
F_2 ( V_6 , V_74 , V_78 ) ;
}
V_124 &= ~ V_128 ;
V_124 |= V_6 -> V_129 . V_130 | V_131 ;
V_3 = V_132 ;
if ( ! V_6 -> V_29 )
V_3 |= V_126 ;
F_2 ( V_6 , V_34 , V_3 ) ;
F_2 ( V_6 , V_125 , V_124 ) ;
}
static void F_40 ( struct V_114 * V_58 )
{
struct V_56 * V_57 = F_29 ( V_58 ) ;
struct V_48 * V_49 = F_25 ( V_58 -> V_98 ) ;
struct V_105 * V_106 = F_26 ( V_49 -> V_107 ) ;
struct V_5 * V_6 = V_106 -> V_108 ;
struct V_59 * V_60 = F_30 ( V_57 , struct V_59 , V_58 ) ;
unsigned long V_133 = 0 ;
F_41 ( & V_6 -> V_87 , V_133 ) ;
F_42 ( & V_60 -> V_61 , & V_6 -> V_66 ) ;
if ( V_6 -> V_55 == NULL ) {
V_6 -> V_55 = V_60 ;
if ( F_43 ( V_58 -> V_98 ) )
F_39 ( V_6 , V_60 ) ;
}
F_44 ( & V_6 -> V_87 , V_133 ) ;
}
static int F_45 ( struct V_98 * V_99 , unsigned int V_134 )
{
struct V_48 * V_49 = F_25 ( V_99 ) ;
struct V_105 * V_106 = F_26 ( V_49 -> V_107 ) ;
struct V_5 * V_6 = V_106 -> V_108 ;
int V_85 ;
F_46 ( V_106 -> V_135 . V_136 ) ;
V_85 = F_20 ( V_6 , V_137 ) ;
if ( V_85 < 0 ) {
F_34 ( V_49 -> V_107 , L_5 ) ;
F_47 ( V_106 -> V_135 . V_136 ) ;
return V_85 ;
}
F_2 ( V_6 , V_91 , ( T_1 ) ~ 0UL ) ;
F_7 ( V_6 , V_49 -> V_138 , V_49 -> V_139 ,
V_49 -> V_140 ) ;
F_48 ( & V_6 -> V_87 ) ;
F_4 ( V_6 , V_88 ) ;
if ( V_134 )
F_39 ( V_6 , V_6 -> V_55 ) ;
F_49 ( & V_6 -> V_87 ) ;
return 0 ;
}
static void F_50 ( struct V_98 * V_99 )
{
struct V_48 * V_49 = F_25 ( V_99 ) ;
struct V_105 * V_106 = F_26 ( V_49 -> V_107 ) ;
struct V_5 * V_6 = V_106 -> V_108 ;
struct V_59 * V_60 , * V_141 ;
int V_85 = 0 ;
unsigned long V_95 ;
F_48 ( & V_6 -> V_87 ) ;
V_6 -> V_55 = NULL ;
F_51 (buf, node, &isi->video_buffer_list, list) {
F_10 ( & V_60 -> V_61 ) ;
F_12 ( & V_60 -> V_58 . V_62 , V_142 ) ;
}
F_49 ( & V_6 -> V_87 ) ;
if ( ! V_6 -> V_29 ) {
V_95 = V_143 + V_144 * V_145 ;
while ( ( F_4 ( V_6 , V_88 ) & V_126 ) &&
F_52 ( V_143 , V_95 ) )
F_53 ( 1 ) ;
if ( F_54 ( V_143 , V_95 ) )
F_34 ( V_49 -> V_107 ,
L_6 ) ;
}
F_2 ( V_6 , V_91 ,
V_92 | V_93 ) ;
V_85 = F_20 ( V_6 , V_146 ) ;
if ( V_85 < 0 )
F_34 ( V_49 -> V_107 , L_7 ) ;
F_47 ( V_106 -> V_135 . V_136 ) ;
}
static int F_55 ( struct V_98 * V_147 ,
struct V_48 * V_49 )
{
struct V_105 * V_106 = F_26 ( V_49 -> V_107 ) ;
V_147 -> type = V_148 ;
V_147 -> V_149 = V_150 ;
V_147 -> V_151 = V_49 ;
V_147 -> V_152 = sizeof( struct V_59 ) ;
V_147 -> V_153 = & V_154 ;
V_147 -> V_155 = & V_156 ;
V_147 -> V_157 = V_158 ;
V_147 -> V_87 = & V_106 -> V_159 ;
V_147 -> V_136 = V_106 -> V_135 . V_136 ;
return F_56 ( V_147 ) ;
}
static int F_57 ( struct V_48 * V_49 ,
struct V_160 * V_161 )
{
struct V_162 * V_163 = F_58 ( V_49 ) ;
const struct V_10 * V_11 ;
struct V_164 * V_165 = & V_161 -> V_166 . V_165 ;
struct V_167 V_168 = {
. V_169 = V_170 ,
} ;
struct V_171 * V_172 = & V_168 . V_168 ;
int V_85 ;
if ( ! F_8 ( V_49 , V_165 -> V_173 ) )
V_165 -> V_173 = V_14 ;
V_11 = F_59 ( V_49 , V_165 -> V_173 ) ;
if ( ! V_11 ) {
F_60 ( V_49 -> V_107 , L_8 ,
V_165 -> V_173 ) ;
return - V_117 ;
}
F_27 ( V_49 -> V_107 , L_9 ,
V_165 -> V_25 , V_165 -> V_26 ) ;
V_172 -> V_25 = V_165 -> V_25 ;
V_172 -> V_26 = V_165 -> V_26 ;
V_172 -> V_174 = V_165 -> V_174 ;
V_172 -> V_175 = V_165 -> V_175 ;
V_172 -> V_15 = V_11 -> V_15 ;
V_85 = F_61 ( V_163 , V_176 , V_177 , NULL , & V_168 ) ;
if ( V_85 < 0 )
return V_85 ;
if ( V_172 -> V_15 != V_11 -> V_15 )
return - V_117 ;
V_165 -> V_25 = V_172 -> V_25 ;
V_165 -> V_26 = V_172 -> V_26 ;
V_165 -> V_174 = V_172 -> V_174 ;
V_165 -> V_175 = V_172 -> V_175 ;
V_49 -> V_140 = V_11 ;
F_27 ( V_49 -> V_107 , L_10 ,
V_165 -> V_25 , V_165 -> V_26 ) ;
return V_85 ;
}
static int F_62 ( struct V_48 * V_49 ,
struct V_160 * V_161 )
{
struct V_162 * V_163 = F_58 ( V_49 ) ;
const struct V_10 * V_11 ;
struct V_164 * V_165 = & V_161 -> V_166 . V_165 ;
struct V_178 V_179 ;
struct V_167 V_168 = {
. V_169 = V_180 ,
} ;
struct V_171 * V_172 = & V_168 . V_168 ;
T_1 V_181 = V_165 -> V_173 ;
int V_85 ;
if ( ! F_8 ( V_49 , V_165 -> V_173 ) )
V_165 -> V_173 = V_14 ;
V_11 = F_59 ( V_49 , V_181 ) ;
if ( V_181 && ! V_11 ) {
F_60 ( V_49 -> V_107 , L_8 , V_181 ) ;
return - V_117 ;
}
if ( V_165 -> V_26 > V_182 )
V_165 -> V_26 = V_182 ;
if ( V_165 -> V_25 > V_183 )
V_165 -> V_25 = V_183 ;
V_172 -> V_25 = V_165 -> V_25 ;
V_172 -> V_26 = V_165 -> V_26 ;
V_172 -> V_174 = V_165 -> V_174 ;
V_172 -> V_175 = V_165 -> V_175 ;
V_172 -> V_15 = V_11 -> V_15 ;
V_85 = F_61 ( V_163 , V_176 , V_177 , & V_179 , & V_168 ) ;
if ( V_85 < 0 )
return V_85 ;
V_165 -> V_25 = V_172 -> V_25 ;
V_165 -> V_26 = V_172 -> V_26 ;
V_165 -> V_175 = V_172 -> V_175 ;
switch ( V_172 -> V_174 ) {
case V_184 :
V_165 -> V_174 = V_185 ;
break;
case V_185 :
break;
default:
F_34 ( V_49 -> V_107 , L_11 ,
V_172 -> V_174 ) ;
V_85 = - V_117 ;
}
return V_85 ;
}
static bool F_63 ( const struct V_186 * V_166 )
{
return V_166 -> V_187 == V_188 ||
( V_166 -> V_189 == 8 &&
V_166 -> V_187 == V_190 ) ||
( V_166 -> V_189 > 8 &&
V_166 -> V_187 == V_191 ) ;
}
static int F_64 ( struct V_48 * V_49 ,
unsigned char V_192 )
{
struct V_162 * V_163 = F_58 ( V_49 ) ;
struct V_105 * V_106 = F_26 ( V_49 -> V_107 ) ;
struct V_5 * V_6 = V_106 -> V_108 ;
struct V_193 V_194 = { . type = V_195 ,} ;
unsigned long V_196 ;
int V_85 ;
V_85 = F_61 ( V_163 , V_197 , V_198 , & V_194 ) ;
if ( ! V_85 ) {
V_196 = F_65 ( & V_194 ,
V_199 ) ;
if ( ! V_196 ) {
F_60 ( V_49 -> V_107 ,
L_12 ,
V_194 . V_133 , V_199 ) ;
return - V_117 ;
}
} else if ( V_85 != - V_200 ) {
return V_85 ;
}
if ( ( 1 << ( V_192 - 1 ) ) & V_6 -> V_201 )
return 0 ;
return - V_117 ;
}
static int F_66 ( struct V_48 * V_49 ,
unsigned int V_202 ,
struct V_10 * V_11 )
{
struct V_162 * V_163 = F_58 ( V_49 ) ;
int V_203 = 0 , V_85 , V_204 , V_205 ;
struct V_206 V_15 = {
. V_169 = V_170 ,
. V_207 = V_202 ,
} ;
const struct V_186 * V_166 ;
V_85 = F_61 ( V_163 , V_176 , V_208 , NULL , & V_15 ) ;
if ( V_85 < 0 )
return 0 ;
V_166 = F_67 ( V_15 . V_15 ) ;
if ( ! V_166 ) {
F_34 ( V_49 -> V_107 ,
L_13 , V_202 , V_15 . V_15 ) ;
return 0 ;
}
V_85 = F_64 ( V_49 , V_166 -> V_189 ) ;
if ( V_85 < 0 ) {
F_34 ( V_49 -> V_107 ,
L_14 ) ;
return 0 ;
}
switch ( V_15 . V_15 ) {
case V_18 :
case V_16 :
case V_23 :
case V_20 :
V_205 = F_68 ( V_209 ) ;
V_203 += V_205 ;
for ( V_204 = 0 ; V_11 && V_204 < V_205 ; V_204 ++ , V_11 ++ ) {
V_11 -> V_12 = & V_209 [ V_204 ] ;
V_11 -> V_15 = V_15 . V_15 ;
F_27 ( V_49 -> V_107 , L_15 ,
V_11 -> V_12 -> V_210 , V_11 -> V_15 ) ;
}
break;
default:
if ( ! F_63 ( V_166 ) )
return 0 ;
if ( V_11 )
F_27 ( V_49 -> V_107 ,
L_16 ,
V_166 -> V_210 ) ;
}
V_203 ++ ;
if ( V_11 ) {
V_11 -> V_12 = V_166 ;
V_11 -> V_15 = V_15 . V_15 ;
V_11 ++ ;
}
return V_203 ;
}
static int F_69 ( struct V_48 * V_49 )
{
F_27 ( V_49 -> V_107 , L_17 ,
V_49 -> V_211 ) ;
return 0 ;
}
static void F_70 ( struct V_48 * V_49 )
{
F_27 ( V_49 -> V_107 , L_18 ,
V_49 -> V_211 ) ;
}
static unsigned int F_71 ( struct V_212 * V_212 , T_3 * V_213 )
{
struct V_48 * V_49 = V_212 -> V_214 ;
return F_72 ( & V_49 -> V_215 , V_212 , V_213 ) ;
}
static int F_73 ( struct V_105 * V_106 ,
struct V_216 * V_217 )
{
strcpy ( V_217 -> V_218 , L_19 ) ;
strcpy ( V_217 -> V_219 , L_20 ) ;
V_217 -> V_220 = V_221 | V_222 ;
V_217 -> V_223 = V_217 -> V_220 | V_224 ;
return 0 ;
}
static int F_74 ( struct V_48 * V_49 )
{
struct V_162 * V_163 = F_58 ( V_49 ) ;
struct V_105 * V_106 = F_26 ( V_49 -> V_107 ) ;
struct V_5 * V_6 = V_106 -> V_108 ;
struct V_193 V_194 = { . type = V_195 ,} ;
unsigned long V_196 ;
int V_85 ;
T_1 V_124 = 0 ;
V_85 = F_61 ( V_163 , V_197 , V_198 , & V_194 ) ;
if ( ! V_85 ) {
V_196 = F_65 ( & V_194 ,
V_199 ) ;
if ( ! V_196 ) {
F_60 ( V_49 -> V_107 ,
L_12 ,
V_194 . V_133 , V_199 ) ;
return - V_117 ;
}
} else if ( V_85 != - V_200 ) {
return V_85 ;
} else {
V_196 = V_199 ;
}
F_27 ( V_49 -> V_107 , L_21 ,
V_194 . V_133 , V_199 , V_196 ) ;
if ( ( V_196 & V_225 ) &&
( V_196 & V_226 ) ) {
if ( V_6 -> V_129 . V_227 )
V_196 &= ~ V_225 ;
else
V_196 &= ~ V_226 ;
}
if ( ( V_196 & V_228 ) &&
( V_196 & V_229 ) ) {
if ( V_6 -> V_129 . V_230 )
V_196 &= ~ V_228 ;
else
V_196 &= ~ V_229 ;
}
if ( ( V_196 & V_231 ) &&
( V_196 & V_232 ) ) {
if ( V_6 -> V_129 . V_233 )
V_196 &= ~ V_231 ;
else
V_196 &= ~ V_232 ;
}
V_194 . V_133 = V_196 ;
V_85 = F_61 ( V_163 , V_197 , V_234 , & V_194 ) ;
if ( V_85 < 0 && V_85 != - V_200 ) {
F_27 ( V_49 -> V_107 , L_22 ,
V_196 , V_85 ) ;
return V_85 ;
}
if ( V_196 & V_226 )
V_124 |= V_235 ;
if ( V_196 & V_229 )
V_124 |= V_236 ;
if ( V_196 & V_232 )
V_124 |= V_237 ;
F_27 ( V_49 -> V_107 , L_23 ,
V_196 & V_229 ? L_24 : L_25 ,
V_196 & V_226 ? L_24 : L_25 ,
V_196 & V_232 ? L_26 : L_27 ) ;
if ( V_6 -> V_129 . V_238 )
V_124 |= V_239 ;
if ( V_6 -> V_129 . V_240 )
V_124 |= V_241 ;
V_124 |= V_242 ;
F_46 ( V_106 -> V_135 . V_136 ) ;
F_2 ( V_6 , V_34 , V_35 ) ;
F_2 ( V_6 , V_125 , V_124 ) ;
F_47 ( V_106 -> V_135 . V_136 ) ;
return 0 ;
}
static int F_75 ( struct V_243 * V_244 )
{
struct V_105 * V_127 = F_26 ( & V_244 -> V_136 ) ;
struct V_5 * V_6 = F_30 ( V_127 ,
struct V_5 , V_127 ) ;
F_76 ( V_127 ) ;
F_77 ( & V_244 -> V_136 ,
sizeof( struct V_1 ) * V_111 ,
V_6 -> V_245 ,
V_6 -> V_246 ) ;
F_78 ( & V_244 -> V_136 ) ;
return 0 ;
}
static int F_79 ( struct V_5 * V_6 ,
struct V_243 * V_244 )
{
struct V_247 * V_248 = V_244 -> V_136 . V_249 ;
struct V_250 V_251 ;
int V_252 ;
V_6 -> V_129 . V_240 = 1 ;
V_6 -> V_129 . V_130 = V_253 ;
V_248 = F_80 ( V_248 , NULL ) ;
if ( ! V_248 ) {
F_34 ( & V_244 -> V_136 , L_28 ) ;
return - V_117 ;
}
V_252 = F_81 ( V_248 , & V_251 ) ;
F_82 ( V_248 ) ;
if ( V_252 ) {
F_34 ( & V_244 -> V_136 , L_29 ) ;
return V_252 ;
}
switch ( V_251 . V_254 . V_255 . V_256 ) {
case 8 :
V_6 -> V_129 . V_257 = V_258 ;
break;
case 10 :
V_6 -> V_129 . V_257 =
V_258 | V_259 ;
break;
default:
F_34 ( & V_244 -> V_136 , L_30 ,
V_251 . V_254 . V_255 . V_256 ) ;
return - V_117 ;
}
if ( V_251 . V_254 . V_255 . V_133 & V_226 )
V_6 -> V_129 . V_227 = true ;
if ( V_251 . V_254 . V_255 . V_133 & V_229 )
V_6 -> V_129 . V_230 = true ;
if ( V_251 . V_254 . V_255 . V_133 & V_232 )
V_6 -> V_129 . V_233 = true ;
if ( V_251 . V_260 == V_261 )
V_6 -> V_129 . V_238 = true ;
return 0 ;
}
static int F_83 ( struct V_243 * V_244 )
{
int V_80 ;
struct V_5 * V_6 ;
struct V_262 * V_9 ;
int V_85 , V_204 ;
struct V_105 * V_127 ;
V_6 = F_84 ( & V_244 -> V_136 , sizeof( struct V_5 ) , V_263 ) ;
if ( ! V_6 ) {
F_34 ( & V_244 -> V_136 , L_31 ) ;
return - V_264 ;
}
V_6 -> V_265 = F_85 ( & V_244 -> V_136 , L_32 ) ;
if ( F_86 ( V_6 -> V_265 ) )
return F_87 ( V_6 -> V_265 ) ;
V_85 = F_79 ( V_6 , V_244 ) ;
if ( V_85 )
return V_85 ;
V_6 -> V_55 = NULL ;
F_88 ( & V_6 -> V_87 ) ;
F_31 ( & V_6 -> V_66 ) ;
F_31 ( & V_6 -> V_118 ) ;
V_6 -> V_245 = F_89 ( & V_244 -> V_136 ,
sizeof( struct V_1 ) * V_111 ,
& V_6 -> V_246 ,
V_263 ) ;
if ( ! V_6 -> V_245 ) {
F_34 ( & V_244 -> V_136 , L_33 ) ;
return - V_264 ;
}
for ( V_204 = 0 ; V_204 < V_111 ; V_204 ++ ) {
V_6 -> V_266 [ V_204 ] . V_119 = V_6 -> V_245 + V_204 ;
V_6 -> V_266 [ V_204 ] . V_70 = V_6 -> V_246 +
V_204 * sizeof( struct V_1 ) ;
F_38 ( & V_6 -> V_266 [ V_204 ] . V_61 , & V_6 -> V_118 ) ;
}
V_9 = F_90 ( V_244 , V_267 , 0 ) ;
V_6 -> V_9 = F_91 ( & V_244 -> V_136 , V_9 ) ;
if ( F_86 ( V_6 -> V_9 ) ) {
V_85 = F_87 ( V_6 -> V_9 ) ;
goto V_268;
}
if ( V_6 -> V_129 . V_257 & V_258 )
V_6 -> V_201 = 1 << 7 ;
if ( V_6 -> V_129 . V_257 & V_259 )
V_6 -> V_201 |= 1 << 9 ;
V_80 = F_92 ( V_244 , 0 ) ;
if ( V_80 < 0 ) {
V_85 = V_80 ;
goto V_269;
}
V_85 = F_93 ( & V_244 -> V_136 , V_80 , F_15 , 0 , L_34 , V_6 ) ;
if ( V_85 ) {
F_34 ( & V_244 -> V_136 , L_35 , V_80 ) ;
goto V_269;
}
V_6 -> V_80 = V_80 ;
V_127 = & V_6 -> V_127 ;
V_127 -> V_270 = L_36 ;
V_127 -> V_153 = & V_271 ;
V_127 -> V_108 = V_6 ;
V_127 -> V_135 . V_136 = & V_244 -> V_136 ;
V_127 -> V_272 = V_244 -> V_273 ;
F_94 ( & V_244 -> V_136 , true ) ;
F_95 ( & V_244 -> V_136 ) ;
V_85 = F_96 ( V_127 ) ;
if ( V_85 ) {
F_34 ( & V_244 -> V_136 , L_37 ) ;
goto V_274;
}
return 0 ;
V_274:
F_78 ( & V_244 -> V_136 ) ;
V_269:
V_268:
F_77 ( & V_244 -> V_136 ,
sizeof( struct V_1 ) * V_111 ,
V_6 -> V_245 ,
V_6 -> V_246 ) ;
return V_85 ;
}
static int F_97 ( struct V_103 * V_136 )
{
struct V_105 * V_127 = F_26 ( V_136 ) ;
struct V_5 * V_6 = F_30 ( V_127 ,
struct V_5 , V_127 ) ;
F_98 ( V_6 -> V_265 ) ;
return 0 ;
}
static int F_99 ( struct V_103 * V_136 )
{
struct V_105 * V_127 = F_26 ( V_136 ) ;
struct V_5 * V_6 = F_30 ( V_127 ,
struct V_5 , V_127 ) ;
return F_100 ( V_6 -> V_265 ) ;
}
