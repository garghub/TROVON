static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 = 0 ;
V_2 -> V_5 = F_2 ( V_2 -> V_5 , ( V_6 ) V_7 ,
( V_6 ) V_8 ) ;
V_2 -> V_9 = F_2 ( V_2 -> V_9 , ( V_6 ) V_10 , ( V_6 ) V_11 ) ;
for ( V_3 = 0 ; V_3 < V_12 ; V_3 ++ ) {
if ( V_2 -> V_13 == V_14 [ V_3 ] . V_13 )
break;
}
if ( V_3 == V_12 )
V_3 = 0 ;
V_2 -> V_13 = V_14 [ V_3 ] . V_13 ;
V_2 -> V_15 = V_16 ;
switch ( V_2 -> V_13 ) {
case V_17 :
case V_18 :
default:
V_2 -> V_19 = V_20 ;
V_4 = V_21 ;
break;
case V_22 :
case V_23 :
V_2 -> V_19 = V_24 ;
V_4 = V_25 ;
break;
case V_26 :
V_2 -> V_19 = V_24 ;
V_4 = V_27 ;
break;
case V_28 :
case V_29 :
V_2 -> V_19 = V_24 ;
V_4 = V_30 ;
break;
}
V_2 -> V_31 = V_2 -> V_9 * V_4 ;
V_2 -> V_32 = V_2 -> V_31 * V_2 -> V_5 ;
return V_4 ;
}
static unsigned long F_3 ( unsigned long V_33 )
{
unsigned long V_34 = 0 ;
struct V_35 * V_36 ;
struct V_37 * V_38 = V_39 -> V_38 ;
if ( V_33 >= V_40 )
return F_4 ( ( void * ) V_33 ) ;
F_5 ( & V_39 -> V_38 -> V_41 ) ;
V_36 = F_6 ( V_38 , V_33 ) ;
if ( V_36 && ( V_36 -> V_42 & V_43 ) && V_36 -> V_44 ) {
V_34 = ( V_36 -> V_44 << V_45 ) + ( V_33 - V_36 -> V_46 ) ;
F_7 ( & V_39 -> V_38 -> V_41 ) ;
} else {
int V_47 , V_48 = 1 ;
struct V_49 * V_50 ;
V_47 = F_8 ( V_39 , V_39 -> V_38 , V_33 , V_48 , 1 ,
0 , & V_50 , NULL ) ;
F_7 ( & V_39 -> V_38 -> V_41 ) ;
if ( V_47 == V_48 ) {
V_34 = F_9 ( F_10 ( & V_50 [ 0 ] ) +
( V_33 & ~ V_51 ) ) ;
} else {
F_11 (KERN_WARNING VOUT_NAME
L_1 ) ;
return 0 ;
}
}
return V_34 ;
}
void F_12 ( struct V_52 * V_53 )
{
int V_54 , V_55 ;
V_55 = ( V_53 -> V_56 ) ? V_57 : V_58 ;
V_53 -> V_59 = ( V_53 -> V_56 ) ? V_60 : V_61 ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
F_13 ( V_53 -> V_62 [ V_54 ] ,
V_53 -> V_59 ) ;
V_53 -> V_63 [ V_54 ] = 0 ;
V_53 -> V_62 [ V_54 ] = 0 ;
}
}
static int F_14 ( int V_64 ,
enum V_65 * V_66 , bool V_67 )
{
int V_68 = 0 ;
switch ( V_64 ) {
case 90 :
* V_66 = V_69 ;
break;
case 180 :
* V_66 = V_70 ;
break;
case 270 :
* V_66 = V_71 ;
break;
case 0 :
* V_66 = V_72 ;
break;
default:
V_68 = - V_73 ;
}
return V_68 ;
}
static int F_15 ( struct V_52 * V_53 )
{
struct V_74 * V_75 ;
struct V_76 * V_77 = & V_53 -> V_77 ;
struct V_1 * V_2 = & V_53 -> V_2 ;
int * V_78 = & V_53 -> V_78 ;
int V_79 = 2 , V_80 = 0 ;
V_75 = & V_53 -> V_81 ;
if ( V_75 -> V_82 == V_83 ) {
F_16 ( V_53 ) ;
} else {
V_53 -> V_80 = V_80 = V_2 -> V_9 ;
if ( V_17 == V_2 -> V_13 ||
V_18 == V_2 -> V_13 )
V_79 = 2 ;
else if ( V_28 == V_2 -> V_13 )
V_79 = 4 ;
else if ( V_26 == V_2 -> V_13 )
V_79 = 3 ;
V_53 -> V_79 = V_79 ;
* V_78 = ( V_80 * V_79 ) *
V_77 -> V_84 + V_77 -> V_85 * V_79 ;
}
F_17 ( 1 , V_86 , & V_53 -> V_87 -> V_88 , L_2 ,
V_89 , V_53 -> V_78 ) ;
return 0 ;
}
static int F_18 ( struct V_52 * V_53 )
{
struct V_90 * V_91 ;
struct V_74 * V_75 ;
struct V_1 * V_2 = & V_53 -> V_2 ;
enum V_92 V_93 ;
V_75 = & V_53 -> V_81 ;
V_91 = V_75 -> V_94 [ 0 ] ;
switch ( V_2 -> V_13 ) {
case V_17 :
V_93 = V_95 ;
break;
case V_18 :
V_93 = V_96 ;
break;
case V_22 :
V_93 = V_97 ;
break;
case V_26 :
V_93 = V_98 ;
break;
case V_28 :
V_93 = ( V_91 -> V_99 == V_100 ) ?
V_101 : V_102 ;
break;
case V_29 :
V_93 = V_103 ;
break;
default:
V_93 = - V_73 ;
break;
}
return V_93 ;
}
static int F_19 ( struct V_52 * V_53 ,
struct V_90 * V_91 , int V_104 , int V_105 , int V_106 ,
int V_107 , V_6 V_108 )
{
int V_68 = 0 ;
struct V_109 V_110 ;
int V_111 , V_112 , V_113 ;
if ( ( V_91 -> V_114 & V_115 ) == 0 &&
( V_106 != V_53 -> V_2 . V_9 || V_107 != V_53 -> V_2 . V_5 ) ) {
V_68 = - V_73 ;
goto V_116;
}
V_53 -> V_117 = F_18 ( V_53 ) ;
if ( V_53 -> V_117 == - V_73 ) {
V_68 = - V_73 ;
goto V_116;
}
if ( F_20 ( V_53 ) ) {
V_111 = V_53 -> V_77 . V_9 ;
V_112 = V_53 -> V_77 . V_5 ;
V_113 = V_53 -> V_2 . V_5 ;
} else {
V_111 = V_53 -> V_77 . V_5 ;
V_112 = V_53 -> V_77 . V_9 ;
V_113 = V_53 -> V_2 . V_9 ;
}
V_91 -> V_118 ( V_91 , & V_110 ) ;
V_110 . V_119 = V_108 ;
V_110 . V_9 = V_112 ;
V_110 . V_5 = V_111 ;
V_110 . V_120 = V_53 -> V_117 ;
V_110 . V_67 = V_53 -> V_67 ;
V_110 . V_121 = V_104 ;
V_110 . V_122 = V_105 ;
V_110 . V_123 = V_106 ;
V_110 . V_124 = V_107 ;
V_110 . V_125 = V_53 -> V_126 . V_125 ;
if ( ! F_21 ( V_53 ) ) {
V_110 . V_66 = 0 ;
V_110 . V_82 = V_127 ;
V_110 . V_128 = V_113 ;
} else {
V_110 . V_66 = V_53 -> V_66 ;
V_110 . V_82 = V_129 ;
V_110 . V_128 = 2048 ;
}
F_17 ( 1 , V_86 , & V_53 -> V_87 -> V_88 ,
L_3
L_4
L_5 ,
V_89 , V_91 -> V_130 ( V_91 ) , & V_110 . V_119 , V_110 . V_9 , V_110 . V_5 ,
V_110 . V_120 , V_110 . V_66 , V_110 . V_67 , V_110 . V_121 ,
V_110 . V_122 , V_110 . V_123 , V_110 . V_124 , V_110 . V_82 ,
V_110 . V_128 ) ;
V_68 = V_91 -> V_131 ( V_91 , & V_110 ) ;
if ( V_68 )
goto V_116;
return 0 ;
V_116:
F_22 ( & V_53 -> V_87 -> V_88 , L_6 ) ;
return V_68 ;
}
static int F_23 ( struct V_52 * V_53 , V_6 V_108 )
{
int V_68 = 0 , V_54 ;
struct V_132 * V_126 ;
struct V_90 * V_91 ;
int V_104 , V_105 , V_106 , V_107 ;
struct V_133 * V_134 ;
struct V_74 * V_75 = & V_53 -> V_81 ;
V_126 = & V_53 -> V_126 ;
for ( V_54 = 0 ; V_54 < V_75 -> V_135 ; V_54 ++ ) {
struct V_136 * V_137 ;
V_91 = V_75 -> V_94 [ V_54 ] ;
V_137 = V_91 -> V_138 ( V_91 ) ;
if ( ! V_137 )
return - V_73 ;
V_134 = & V_137 -> V_139 . V_140 ;
V_106 = V_126 -> V_141 . V_9 ;
V_107 = V_126 -> V_141 . V_5 ;
switch ( V_53 -> V_66 ) {
case V_69 :
F_24 ( V_106 , V_107 ) ;
V_105 = ( V_134 -> V_142 - V_126 -> V_141 . V_9 ) - V_126 -> V_141 . V_85 ;
V_104 = V_126 -> V_141 . V_84 ;
break;
case V_70 :
V_104 = ( V_134 -> V_143 - V_126 -> V_141 . V_9 ) - V_126 -> V_141 . V_85 ;
V_105 = ( V_134 -> V_142 - V_126 -> V_141 . V_5 ) - V_126 -> V_141 . V_84 ;
break;
case V_71 :
F_24 ( V_106 , V_107 ) ;
V_105 = V_126 -> V_141 . V_85 ;
V_104 = ( V_134 -> V_143 - V_126 -> V_141 . V_5 ) - V_126 -> V_141 . V_84 ;
break;
default:
V_104 = V_126 -> V_141 . V_85 ;
V_105 = V_126 -> V_141 . V_84 ;
break;
}
V_68 = F_19 ( V_53 , V_91 , V_104 , V_105 ,
V_106 , V_107 , V_108 ) ;
if ( V_68 )
goto V_144;
}
return 0 ;
V_144:
F_22 ( & V_53 -> V_87 -> V_88 , L_7 ) ;
return V_68 ;
}
static int F_25 ( struct V_52 * V_53 )
{
int V_54 ;
struct V_90 * V_91 ;
struct V_74 * V_75 = & V_53 -> V_81 ;
for ( V_54 = 0 ; V_54 < V_75 -> V_135 ; V_54 ++ ) {
struct V_136 * V_137 ;
V_91 = V_75 -> V_94 [ V_54 ] ;
V_137 = V_91 -> V_138 ( V_91 ) ;
if ( ! V_137 )
return - V_73 ;
V_91 -> V_145 -> V_146 ( V_91 -> V_145 ) ;
}
return 0 ;
}
static int F_26 ( struct V_52 * V_53 ,
unsigned int V_147 , struct V_148 V_149 )
{
V_6 V_150 ;
if ( V_53 -> V_151 ) {
V_53 -> V_151 = 0 ;
goto V_152;
}
if ( V_147 & V_153 )
V_150 = 1 ;
else if ( V_147 & V_154 )
V_150 = 0 ;
else
goto V_152;
V_53 -> V_155 ^= 1 ;
if ( V_150 != V_53 -> V_155 ) {
if ( V_150 == 0 )
V_53 -> V_155 = V_150 ;
} else if ( 0 == V_150 ) {
if ( V_53 -> V_156 == V_53 -> V_157 )
goto V_152;
V_53 -> V_156 -> V_158 = V_149 ;
V_53 -> V_156 -> V_159 = V_160 ;
F_27 ( & V_53 -> V_156 -> V_161 ) ;
V_53 -> V_156 = V_53 -> V_157 ;
} else {
if ( F_28 ( & V_53 -> V_162 ) ||
( V_53 -> V_156 != V_53 -> V_157 ) )
goto V_152;
}
return V_53 -> V_155 ;
V_152:
return 0 ;
}
static void F_29 ( void * V_163 , unsigned int V_147 )
{
int V_68 , V_150 , V_164 ;
V_6 V_108 , V_165 ;
struct V_90 * V_91 ;
struct V_148 V_149 ;
struct V_74 * V_75 ;
struct V_136 * V_166 ;
struct V_52 * V_53 = (struct V_52 * ) V_163 ;
if ( ! V_53 -> V_167 )
return;
V_75 = & V_53 -> V_81 ;
V_91 = V_75 -> V_94 [ 0 ] ;
V_164 = V_91 -> V_145 -> V_99 ;
V_166 = V_91 -> V_138 ( V_91 ) ;
if ( ! V_166 )
return;
F_30 ( & V_53 -> V_168 ) ;
F_31 ( & V_149 ) ;
switch ( V_166 -> type ) {
case V_169 :
case V_170 :
case V_171 :
if ( V_164 == V_172 )
V_165 = V_173 ;
else if ( V_164 == V_174 )
V_165 = V_175 ;
else
goto V_176;
if ( ! ( V_147 & V_165 ) )
goto V_176;
break;
case V_177 :
V_150 = F_26 ( V_53 , V_147 ,
V_149 ) ;
if ( ! V_150 )
goto V_176;
break;
case V_178 :
if ( ! ( V_147 & V_154 ) )
goto V_176;
break;
default:
goto V_176;
}
if ( ! V_53 -> V_151 && ( V_53 -> V_156 != V_53 -> V_157 ) ) {
V_53 -> V_156 -> V_158 = V_149 ;
V_53 -> V_156 -> V_159 = V_160 ;
F_27 ( & V_53 -> V_156 -> V_161 ) ;
V_53 -> V_156 = V_53 -> V_157 ;
}
V_53 -> V_151 = 0 ;
if ( F_28 ( & V_53 -> V_162 ) )
goto V_176;
V_53 -> V_157 = F_32 ( V_53 -> V_162 . V_179 ,
struct V_180 , V_181 ) ;
F_33 ( & V_53 -> V_157 -> V_181 ) ;
V_53 -> V_157 -> V_159 = V_182 ;
V_108 = ( unsigned long ) V_53 -> V_183 [ V_53 -> V_157 -> V_54 ]
+ V_53 -> V_78 ;
V_68 = F_23 ( V_53 , V_108 ) ;
if ( V_68 ) {
F_11 (KERN_ERR VOUT_NAME
L_8 ) ;
goto V_176;
}
V_68 = F_25 ( V_53 ) ;
if ( V_68 )
F_11 (KERN_ERR VOUT_NAME L_9 ) ;
V_176:
F_34 ( & V_53 -> V_168 ) ;
}
static int F_35 ( struct V_184 * V_185 , unsigned int * V_186 ,
unsigned int * V_187 )
{
int V_188 = 0 , V_54 , V_189 ;
V_6 V_190 = 0 , V_191 = 0 ;
struct V_52 * V_53 = V_185 -> V_192 ;
struct V_74 * V_75 = & V_53 -> V_81 ;
int V_193 ;
if ( ! V_53 )
return - V_73 ;
V_193 = V_53 -> V_56 == V_194 ? V_61 :
V_60 ;
if ( V_195 != V_185 -> type )
return - V_73 ;
V_188 = ( V_53 -> V_56 == V_194 ) ?
V_58 : V_57 ;
if ( V_196 == V_53 -> V_197 && * V_186 < V_188 )
* V_186 = V_188 ;
if ( V_75 -> V_82 == V_83 ) {
if ( F_36 ( V_53 , V_186 , V_188 ) )
return - V_198 ;
}
if ( V_196 != V_53 -> V_197 )
return 0 ;
* V_187 = F_37 ( V_53 -> V_2 . V_9 * V_53 -> V_2 . V_5 * V_53 -> V_4 ) ;
V_188 = ( V_53 -> V_56 == V_194 ) ?
V_58 : V_57 ;
if ( * V_187 > V_193 ) {
F_38 ( & V_53 -> V_87 -> V_88 ,
L_10 ,
* V_187 , V_53 -> V_59 ) ;
return - V_198 ;
}
for ( V_54 = V_188 ; V_54 < * V_186 ; V_54 ++ ) {
V_53 -> V_59 = * V_187 ;
V_191 = F_39 ( V_53 -> V_59 ,
& V_190 ) ;
if ( ! V_191 ) {
if ( V_75 -> V_82 == V_199 ) {
break;
} else {
if ( ! F_21 ( V_53 ) )
break;
for ( V_189 = V_54 ; V_189 < * V_186 ; V_189 ++ ) {
F_13 (
V_53 -> V_200 [ V_189 ] ,
V_53 -> V_201 ) ;
V_53 -> V_200 [ V_189 ] = 0 ;
V_53 -> V_202 [ V_189 ] = 0 ;
}
}
}
V_53 -> V_62 [ V_54 ] = V_191 ;
V_53 -> V_63 [ V_54 ] = V_190 ;
}
* V_186 = V_53 -> V_203 = V_54 ;
return 0 ;
}
static void F_40 ( struct V_52 * V_53 )
{
int V_204 = 0 , V_54 ;
V_204 = ( V_53 -> V_56 == V_194 ) ?
V_58 : V_57 ;
for ( V_54 = V_204 ; V_54 < V_53 -> V_203 ; V_54 ++ ) {
if ( V_53 -> V_62 [ V_54 ] )
F_13 ( V_53 -> V_62 [ V_54 ] ,
V_53 -> V_59 ) ;
V_53 -> V_62 [ V_54 ] = 0 ;
V_53 -> V_63 [ V_54 ] = 0 ;
}
V_53 -> V_203 = V_204 ;
}
static int F_41 ( struct V_184 * V_185 ,
struct V_180 * V_205 ,
enum V_206 V_15 )
{
struct V_52 * V_53 = V_185 -> V_192 ;
struct V_74 * V_75 = & V_53 -> V_81 ;
if ( V_207 == V_205 -> V_159 ) {
V_205 -> V_9 = V_53 -> V_2 . V_9 ;
V_205 -> V_5 = V_53 -> V_2 . V_5 ;
V_205 -> V_187 = V_205 -> V_9 * V_205 -> V_5 * V_53 -> V_4 ;
V_205 -> V_15 = V_15 ;
}
V_205 -> V_159 = V_208 ;
if ( V_209 == V_205 -> V_197 ) {
if ( 0 == V_205 -> V_210 )
return - V_73 ;
V_53 -> V_183 [ V_205 -> V_54 ] = ( V_211 * )
F_3 ( V_205 -> V_210 ) ;
} else {
unsigned long V_108 , V_212 ;
unsigned long V_187 ;
V_108 = ( unsigned long ) V_53 -> V_62 [ V_205 -> V_54 ] ;
V_187 = ( unsigned long ) V_205 -> V_187 ;
V_212 = F_42 ( V_53 -> V_87 -> V_88 . V_213 , ( void * ) V_108 ,
V_187 , V_214 ) ;
if ( F_43 ( V_53 -> V_87 -> V_88 . V_213 , V_212 ) )
F_38 ( & V_53 -> V_87 -> V_88 , L_11 ) ;
V_53 -> V_183 [ V_205 -> V_54 ] = ( V_211 * ) V_53 -> V_63 [ V_205 -> V_54 ] ;
}
if ( V_75 -> V_82 == V_83 )
return F_44 ( V_53 , V_205 ) ;
else
return 0 ;
}
static void F_45 ( struct V_184 * V_185 ,
struct V_180 * V_205 )
{
struct V_52 * V_53 = V_185 -> V_192 ;
F_46 ( & V_205 -> V_181 , & V_53 -> V_162 ) ;
V_205 -> V_159 = V_215 ;
}
static void F_47 ( struct V_184 * V_185 ,
struct V_180 * V_205 )
{
struct V_52 * V_53 = V_185 -> V_192 ;
V_205 -> V_159 = V_207 ;
if ( V_196 != V_53 -> V_197 )
return;
}
static unsigned int F_48 ( struct V_216 * V_216 ,
struct V_217 * V_218 )
{
struct V_52 * V_53 = V_216 -> V_219 ;
struct V_184 * V_185 = & V_53 -> V_220 ;
return F_49 ( V_216 , V_185 , V_218 ) ;
}
static void F_50 ( struct V_35 * V_36 )
{
struct V_52 * V_53 = V_36 -> V_221 ;
F_17 ( 1 , V_86 , & V_53 -> V_87 -> V_88 ,
L_12 , V_36 -> V_46 , V_36 -> V_222 ) ;
V_53 -> V_223 ++ ;
}
static void F_51 ( struct V_35 * V_36 )
{
struct V_52 * V_53 = V_36 -> V_221 ;
F_17 ( 1 , V_86 , & V_53 -> V_87 -> V_88 ,
L_13 , V_36 -> V_46 , V_36 -> V_222 ) ;
V_53 -> V_223 -- ;
}
static int F_52 ( struct V_216 * V_216 , struct V_35 * V_36 )
{
int V_54 ;
void * V_224 ;
unsigned long V_225 = V_36 -> V_46 ;
unsigned long V_187 = ( V_36 -> V_222 - V_36 -> V_46 ) ;
struct V_52 * V_53 = V_216 -> V_219 ;
struct V_184 * V_185 = & V_53 -> V_220 ;
F_17 ( 1 , V_86 , & V_53 -> V_87 -> V_88 ,
L_14 , V_89 ,
V_36 -> V_44 , V_36 -> V_46 , V_36 -> V_222 ) ;
for ( V_54 = 0 ; V_54 < V_226 ; V_54 ++ ) {
if ( NULL == V_185 -> V_227 [ V_54 ] )
continue;
if ( V_196 != V_185 -> V_227 [ V_54 ] -> V_197 )
continue;
if ( V_185 -> V_227 [ V_54 ] -> V_228 == ( V_36 -> V_44 << V_45 ) )
break;
}
if ( V_226 == V_54 ) {
F_17 ( 1 , V_86 , & V_53 -> V_87 -> V_88 ,
L_15 ,
( V_36 -> V_44 << V_45 ) ) ;
return - V_73 ;
}
if ( V_187 > V_53 -> V_59 ) {
F_38 ( & V_53 -> V_87 -> V_88 ,
L_16 ,
V_187 , V_53 -> V_59 ) ;
return - V_198 ;
}
V_185 -> V_227 [ V_54 ] -> V_210 = V_36 -> V_46 ;
V_36 -> V_42 |= V_229 | V_230 ;
V_36 -> V_231 = F_53 ( V_36 -> V_231 ) ;
V_36 -> V_232 = & V_233 ;
V_36 -> V_221 = ( void * ) V_53 ;
V_224 = ( void * ) V_53 -> V_62 [ V_54 ] ;
V_36 -> V_44 = F_4 ( ( void * ) V_224 ) >> V_45 ;
while ( V_187 > 0 ) {
unsigned long V_234 ;
V_234 = F_4 ( ( void * ) V_224 ) >> V_45 ;
if ( F_54 ( V_36 , V_225 , V_234 , V_235 , V_236 ) )
return - V_237 ;
V_225 += V_235 ;
V_224 += V_235 ;
V_187 -= V_235 ;
}
V_53 -> V_223 ++ ;
F_17 ( 1 , V_86 , & V_53 -> V_87 -> V_88 , L_17 , V_89 ) ;
return 0 ;
}
static int F_55 ( struct V_216 * V_216 )
{
unsigned int V_68 , V_54 ;
struct V_184 * V_185 ;
struct V_74 * V_75 ;
struct V_52 * V_53 = V_216 -> V_219 ;
F_17 ( 1 , V_86 , & V_53 -> V_87 -> V_88 , L_18 , V_89 ) ;
V_75 = & V_53 -> V_81 ;
if ( ! V_53 )
return 0 ;
V_185 = & V_53 -> V_220 ;
for ( V_54 = 0 ; V_54 < V_75 -> V_135 ; V_54 ++ ) {
struct V_90 * V_91 = V_75 -> V_94 [ V_54 ] ;
struct V_136 * V_137 = V_91 -> V_138 ( V_91 ) ;
if ( V_137 )
V_91 -> V_238 ( V_91 ) ;
}
V_68 = F_25 ( V_53 ) ;
if ( V_68 )
F_22 ( & V_53 -> V_87 -> V_88 ,
L_19 ) ;
F_40 ( V_53 ) ;
if ( V_75 -> V_82 == V_83 ) {
if ( ! V_53 -> V_239 )
F_56 ( V_53 ) ;
}
F_57 ( V_185 ) ;
if ( V_53 -> V_167 ) {
V_6 V_240 = 0 ;
V_240 = V_173 | V_154 |
V_153 | V_175 ;
F_58 ( F_29 , V_53 , V_240 ) ;
V_53 -> V_167 = false ;
F_59 ( V_185 ) ;
F_60 ( V_185 ) ;
}
if ( V_53 -> V_223 != 0 )
V_53 -> V_223 = 0 ;
V_53 -> V_241 -= 1 ;
V_216 -> V_219 = NULL ;
if ( V_53 -> V_203 )
F_57 ( V_185 ) ;
F_17 ( 1 , V_86 , & V_53 -> V_87 -> V_88 , L_17 , V_89 ) ;
return V_68 ;
}
static int F_61 ( struct V_216 * V_216 )
{
struct V_184 * V_185 ;
struct V_52 * V_53 = NULL ;
V_53 = F_62 ( V_216 ) ;
F_17 ( 1 , V_86 , & V_53 -> V_87 -> V_88 , L_18 , V_89 ) ;
if ( V_53 == NULL )
return - V_242 ;
if ( V_53 -> V_241 )
return - V_243 ;
V_53 -> V_241 += 1 ;
V_216 -> V_219 = V_53 ;
V_53 -> type = V_195 ;
V_185 = & V_53 -> V_220 ;
V_244 . V_245 = F_35 ;
V_244 . V_246 = F_41 ;
V_244 . V_247 = F_47 ;
V_244 . V_248 = F_45 ;
F_63 ( & V_53 -> V_168 ) ;
F_64 ( V_185 , & V_244 , V_185 -> V_213 ,
& V_53 -> V_168 , V_53 -> type , V_249 ,
sizeof( struct V_180 ) , V_53 , NULL ) ;
F_17 ( 1 , V_86 , & V_53 -> V_87 -> V_88 , L_17 , V_89 ) ;
return 0 ;
}
static int F_65 ( struct V_216 * V_216 , void * V_250 ,
struct V_251 * V_252 )
{
struct V_52 * V_53 = V_250 ;
F_66 ( V_252 -> V_253 , V_254 , sizeof( V_252 -> V_253 ) ) ;
F_66 ( V_252 -> V_255 , V_53 -> V_256 -> V_257 , sizeof( V_252 -> V_255 ) ) ;
V_252 -> V_258 [ 0 ] = '\0' ;
V_252 -> V_259 = V_260 | V_261 |
V_262 ;
V_252 -> V_263 = V_252 -> V_259 | V_264 ;
return 0 ;
}
static int F_67 ( struct V_216 * V_216 , void * V_250 ,
struct V_265 * V_266 )
{
int V_267 = V_266 -> V_267 ;
if ( V_267 >= V_12 )
return - V_73 ;
V_266 -> V_268 = V_14 [ V_267 ] . V_268 ;
F_66 ( V_266 -> V_269 , V_14 [ V_267 ] . V_269 ,
sizeof( V_266 -> V_269 ) ) ;
V_266 -> V_13 = V_14 [ V_267 ] . V_13 ;
return 0 ;
}
static int F_68 ( struct V_216 * V_216 , void * V_250 ,
struct V_270 * V_271 )
{
struct V_52 * V_53 = V_250 ;
V_271 -> V_266 . V_2 = V_53 -> V_2 ;
return 0 ;
}
static int F_69 ( struct V_216 * V_216 , void * V_250 ,
struct V_270 * V_271 )
{
struct V_90 * V_91 ;
struct V_74 * V_75 ;
struct V_133 * V_134 ;
struct V_52 * V_53 = V_250 ;
struct V_136 * V_137 ;
V_75 = & V_53 -> V_81 ;
V_91 = V_75 -> V_94 [ 0 ] ;
V_137 = V_91 -> V_138 ( V_91 ) ;
if ( ! V_137 )
return - V_73 ;
V_134 = & V_137 -> V_139 . V_140 ;
V_53 -> V_272 . V_266 . V_5 = V_134 -> V_142 ;
V_53 -> V_272 . V_266 . V_9 = V_134 -> V_143 ;
F_1 ( & V_271 -> V_266 . V_2 ) ;
return 0 ;
}
static int F_70 ( struct V_216 * V_216 , void * V_250 ,
struct V_270 * V_271 )
{
int V_68 , V_4 ;
struct V_90 * V_91 ;
struct V_74 * V_75 ;
struct V_133 * V_134 ;
struct V_52 * V_53 = V_250 ;
struct V_136 * V_137 ;
if ( V_53 -> V_167 )
return - V_243 ;
F_71 ( & V_53 -> V_273 ) ;
V_75 = & V_53 -> V_81 ;
V_91 = V_75 -> V_94 [ 0 ] ;
V_137 = V_91 -> V_138 ( V_91 ) ;
if ( ! V_137 ) {
V_68 = - V_73 ;
goto V_274;
}
V_134 = & V_137 -> V_139 . V_140 ;
if ( ( F_21 ( V_53 ) ) &&
V_271 -> V_266 . V_2 . V_13 == V_26 ) {
V_68 = - V_73 ;
goto V_274;
}
if ( F_20 ( V_53 ) ) {
V_53 -> V_272 . V_266 . V_5 = V_134 -> V_143 ;
V_53 -> V_272 . V_266 . V_9 = V_134 -> V_142 ;
} else {
V_53 -> V_272 . V_266 . V_5 = V_134 -> V_142 ;
V_53 -> V_272 . V_266 . V_9 = V_134 -> V_143 ;
}
V_4 = F_1 ( & V_271 -> V_266 . V_2 ) ;
V_271 -> V_266 . V_2 . V_32 = V_271 -> V_266 . V_2 . V_9 * V_271 -> V_266 . V_2 . V_5 * V_4 ;
V_53 -> V_4 = V_4 ;
V_53 -> V_2 = V_271 -> V_266 . V_2 ;
V_53 -> V_275 = 1 ;
if ( V_17 == V_53 -> V_2 . V_13 ||
V_18 == V_53 -> V_2 . V_13 )
V_53 -> V_275 = 2 ;
F_72 ( & V_53 -> V_2 , & V_53 -> V_272 , & V_53 -> V_77 , & V_53 -> V_126 ) ;
V_68 = 0 ;
V_274:
F_73 ( & V_53 -> V_273 ) ;
return V_68 ;
}
static int F_74 ( struct V_216 * V_216 , void * V_250 ,
struct V_270 * V_271 )
{
int V_68 = 0 ;
struct V_52 * V_53 = V_250 ;
struct V_90 * V_91 ;
struct V_74 * V_75 ;
struct V_132 * V_126 = & V_271 -> V_266 . V_126 ;
V_75 = & V_53 -> V_81 ;
V_91 = V_75 -> V_94 [ 0 ] ;
V_68 = F_75 ( & V_53 -> V_272 , V_126 ) ;
if ( ! V_68 ) {
if ( ( V_91 -> V_114 & V_276 ) == 0 )
V_126 -> V_125 = 255 ;
else
V_126 -> V_125 = V_271 -> V_266 . V_126 . V_125 ;
}
return V_68 ;
}
static int F_76 ( struct V_216 * V_216 , void * V_250 ,
struct V_270 * V_271 )
{
int V_68 = 0 ;
struct V_90 * V_91 ;
struct V_74 * V_75 ;
struct V_52 * V_53 = V_250 ;
struct V_132 * V_126 = & V_271 -> V_266 . V_126 ;
F_71 ( & V_53 -> V_273 ) ;
V_75 = & V_53 -> V_81 ;
V_91 = V_75 -> V_94 [ 0 ] ;
V_68 = F_77 ( & V_53 -> V_77 , & V_53 -> V_126 , & V_53 -> V_272 , V_126 ) ;
if ( ! V_68 ) {
if ( ( V_91 -> V_114 & V_276 ) == 0 )
V_53 -> V_126 . V_125 = 255 ;
else
V_53 -> V_126 . V_125 = V_271 -> V_266 . V_126 . V_125 ;
V_53 -> V_126 . V_277 = V_271 -> V_266 . V_126 . V_277 ;
}
F_73 ( & V_53 -> V_273 ) ;
return V_68 ;
}
static int F_78 ( struct V_216 * V_216 , void * V_250 ,
struct V_270 * V_271 )
{
V_6 V_278 = 0 ;
struct V_90 * V_91 ;
struct V_74 * V_75 ;
struct V_52 * V_53 = V_250 ;
struct V_279 V_110 ;
struct V_132 * V_126 = & V_271 -> V_266 . V_126 ;
V_75 = & V_53 -> V_81 ;
V_91 = V_75 -> V_94 [ 0 ] ;
V_126 -> V_141 = V_53 -> V_126 . V_141 ;
V_126 -> V_15 = V_53 -> V_126 . V_15 ;
V_126 -> V_125 = V_53 -> V_126 . V_125 ;
if ( V_91 -> V_145 && V_91 -> V_145 -> V_280 ) {
V_91 -> V_145 -> V_280 ( V_91 -> V_145 , & V_110 ) ;
V_278 = V_110 . V_281 ;
}
V_126 -> V_277 = V_278 ;
return 0 ;
}
static int F_79 ( struct V_216 * V_216 , void * V_250 ,
struct V_282 * V_283 )
{
struct V_52 * V_53 = V_250 ;
struct V_1 * V_2 = & V_53 -> V_2 ;
if ( V_283 -> type != V_195 )
return - V_73 ;
V_283 -> V_284 . V_9 = V_2 -> V_9 & ~ 1 ;
V_283 -> V_284 . V_5 = V_2 -> V_5 & ~ 1 ;
F_80 ( & V_53 -> V_2 , & V_53 -> V_272 , & V_283 -> V_285 ) ;
V_283 -> V_286 . V_287 = 1 ;
V_283 -> V_286 . V_288 = 1 ;
return 0 ;
}
static int F_81 ( struct V_216 * V_216 , void * V_250 , struct V_289 * V_77 )
{
struct V_52 * V_53 = V_250 ;
if ( V_77 -> type != V_195 )
return - V_73 ;
V_77 -> V_290 = V_53 -> V_77 ;
return 0 ;
}
static int F_82 ( struct V_216 * V_216 , void * V_250 , const struct V_289 * V_77 )
{
int V_68 = - V_73 ;
struct V_52 * V_53 = V_250 ;
struct V_74 * V_75 ;
struct V_90 * V_91 ;
struct V_133 * V_134 ;
struct V_136 * V_137 ;
if ( V_53 -> V_167 )
return - V_243 ;
F_71 ( & V_53 -> V_273 ) ;
V_75 = & V_53 -> V_81 ;
V_91 = V_75 -> V_94 [ 0 ] ;
V_137 = V_91 -> V_138 ( V_91 ) ;
if ( ! V_137 ) {
V_68 = - V_73 ;
goto V_291;
}
V_134 = & V_137 -> V_139 . V_140 ;
if ( F_20 ( V_53 ) ) {
V_53 -> V_272 . V_266 . V_5 = V_134 -> V_143 ;
V_53 -> V_272 . V_266 . V_9 = V_134 -> V_142 ;
} else {
V_53 -> V_272 . V_266 . V_5 = V_134 -> V_142 ;
V_53 -> V_272 . V_266 . V_9 = V_134 -> V_143 ;
}
if ( V_77 -> type == V_195 )
V_68 = F_83 ( & V_53 -> V_2 , & V_53 -> V_77 , & V_53 -> V_126 ,
& V_53 -> V_272 , & V_77 -> V_290 ) ;
V_291:
F_73 ( & V_53 -> V_273 ) ;
return V_68 ;
}
static int F_84 ( struct V_216 * V_216 , void * V_250 ,
struct V_292 * V_293 )
{
int V_68 = 0 ;
switch ( V_293 -> V_99 ) {
case V_294 :
V_68 = F_85 ( V_293 , 0 , 270 , 90 , 0 ) ;
break;
case V_295 :
V_68 = F_85 ( V_293 , 0 , 0xFFFFFF , 1 , 0 ) ;
break;
case V_296 :
V_68 = F_85 ( V_293 , 0 , 1 , 1 , 0 ) ;
break;
default:
V_293 -> V_257 [ 0 ] = '\0' ;
V_68 = - V_73 ;
}
return V_68 ;
}
static int F_86 ( struct V_216 * V_216 , void * V_250 , struct V_297 * V_293 )
{
int V_68 = 0 ;
struct V_52 * V_53 = V_250 ;
switch ( V_293 -> V_99 ) {
case V_294 :
V_293 -> V_298 = V_53 -> V_299 [ 0 ] . V_298 ;
break;
case V_295 :
{
struct V_279 V_110 ;
struct V_90 * V_91 ;
V_91 = V_53 -> V_81 . V_94 [ 0 ] ;
if ( ! V_91 -> V_145 || ! V_91 -> V_145 -> V_280 ) {
V_68 = - V_73 ;
break;
}
V_91 -> V_145 -> V_280 ( V_91 -> V_145 , & V_110 ) ;
V_293 -> V_298 = V_110 . V_300 ;
break;
}
case V_296 :
V_293 -> V_298 = V_53 -> V_299 [ 2 ] . V_298 ;
break;
default:
V_68 = - V_73 ;
}
return V_68 ;
}
static int F_87 ( struct V_216 * V_216 , void * V_250 , struct V_297 * V_301 )
{
int V_68 = 0 ;
struct V_52 * V_53 = V_250 ;
switch ( V_301 -> V_99 ) {
case V_294 :
{
struct V_74 * V_75 ;
int V_66 = V_301 -> V_298 ;
V_75 = & V_53 -> V_81 ;
F_71 ( & V_53 -> V_273 ) ;
if ( V_66 && V_75 -> V_82 == V_199 ) {
F_73 ( & V_53 -> V_273 ) ;
V_68 = - V_302 ;
break;
}
if ( V_66 && V_53 -> V_2 . V_13 == V_26 ) {
F_73 ( & V_53 -> V_273 ) ;
V_68 = - V_73 ;
break;
}
if ( F_14 ( V_66 , & V_53 -> V_66 ,
V_53 -> V_67 ) ) {
F_73 ( & V_53 -> V_273 ) ;
V_68 = - V_73 ;
break;
}
V_53 -> V_299 [ 0 ] . V_298 = V_66 ;
F_73 ( & V_53 -> V_273 ) ;
break;
}
case V_295 :
{
struct V_90 * V_91 ;
unsigned int V_303 = V_301 -> V_298 ;
struct V_279 V_110 ;
V_91 = V_53 -> V_81 . V_94 [ 0 ] ;
F_71 ( & V_53 -> V_273 ) ;
if ( ! V_91 -> V_145 || ! V_91 -> V_145 -> V_280 ) {
F_73 ( & V_53 -> V_273 ) ;
V_68 = - V_73 ;
break;
}
V_91 -> V_145 -> V_280 ( V_91 -> V_145 , & V_110 ) ;
V_110 . V_300 = V_303 ;
if ( V_91 -> V_145 -> V_304 ( V_91 -> V_145 , & V_110 ) ) {
F_73 ( & V_53 -> V_273 ) ;
V_68 = - V_73 ;
break;
}
V_53 -> V_299 [ 1 ] . V_298 = V_303 ;
F_73 ( & V_53 -> V_273 ) ;
break;
}
case V_296 :
{
struct V_74 * V_75 ;
unsigned int V_67 = V_301 -> V_298 ;
V_75 = & V_53 -> V_81 ;
F_71 ( & V_53 -> V_273 ) ;
if ( V_67 && V_75 -> V_82 == V_199 ) {
F_73 ( & V_53 -> V_273 ) ;
V_68 = - V_302 ;
break;
}
if ( V_67 && V_53 -> V_2 . V_13 == V_26 ) {
F_73 ( & V_53 -> V_273 ) ;
V_68 = - V_73 ;
break;
}
V_53 -> V_67 = V_67 ;
V_53 -> V_299 [ 2 ] . V_298 = V_67 ;
F_73 ( & V_53 -> V_273 ) ;
break;
}
default:
V_68 = - V_73 ;
}
return V_68 ;
}
static int F_88 ( struct V_216 * V_216 , void * V_250 ,
struct V_305 * V_306 )
{
int V_68 = 0 ;
unsigned int V_54 , V_204 = 0 ;
struct V_52 * V_53 = V_250 ;
struct V_184 * V_185 = & V_53 -> V_220 ;
if ( V_306 -> type != V_195 )
return - V_73 ;
if ( ( V_196 != V_306 -> V_197 ) &&
( V_209 != V_306 -> V_197 ) )
return - V_73 ;
F_71 ( & V_53 -> V_273 ) ;
if ( V_53 -> V_167 ) {
V_68 = - V_243 ;
goto V_307;
}
if ( V_185 -> V_227 [ 0 ] && ( V_196 == V_185 -> V_227 [ 0 ] -> V_197 ) ) {
if ( V_53 -> V_223 ) {
V_68 = - V_243 ;
goto V_307;
}
V_204 = ( V_53 -> V_56 == V_194 ) ?
V_58 : V_57 ;
for ( V_54 = V_204 ; V_54 < V_53 -> V_203 ; V_54 ++ ) {
F_13 ( V_53 -> V_62 [ V_54 ] ,
V_53 -> V_59 ) ;
V_53 -> V_62 [ V_54 ] = 0 ;
V_53 -> V_63 [ V_54 ] = 0 ;
}
V_53 -> V_203 = V_204 ;
F_57 ( V_185 ) ;
} else if ( V_185 -> V_227 [ 0 ] && ( V_209 == V_185 -> V_227 [ 0 ] -> V_197 ) ) {
if ( V_53 -> V_203 ) {
F_57 ( V_185 ) ;
for ( V_54 = 0 ; V_54 < V_53 -> V_203 ; V_54 ++ ) {
F_89 ( V_185 -> V_227 [ V_54 ] ) ;
V_185 -> V_227 [ V_54 ] = NULL ;
}
V_53 -> V_203 = 0 ;
}
}
V_53 -> V_197 = V_306 -> V_197 ;
F_90 ( & V_53 -> V_162 ) ;
V_68 = F_91 ( V_185 , V_306 ) ;
if ( V_68 < 0 )
goto V_307;
V_53 -> V_203 = V_306 -> V_186 ;
V_307:
F_73 ( & V_53 -> V_273 ) ;
return V_68 ;
}
static int F_92 ( struct V_216 * V_216 , void * V_250 ,
struct V_308 * V_309 )
{
struct V_52 * V_53 = V_250 ;
return F_93 ( & V_53 -> V_220 , V_309 ) ;
}
static int F_94 ( struct V_216 * V_216 , void * V_250 ,
struct V_308 * V_310 )
{
struct V_52 * V_53 = V_250 ;
struct V_184 * V_185 = & V_53 -> V_220 ;
if ( ( V_195 != V_310 -> type ) ||
( V_310 -> V_267 >= V_53 -> V_203 ) ||
( V_185 -> V_227 [ V_310 -> V_267 ] -> V_197 != V_310 -> V_197 ) ) {
return - V_73 ;
}
if ( V_209 == V_310 -> V_197 ) {
if ( ( V_310 -> V_311 < V_53 -> V_2 . V_32 ) ||
( 0 == V_310 -> V_312 . V_313 ) ) {
return - V_73 ;
}
}
if ( ( F_21 ( V_53 ) ) &&
V_53 -> V_314 . V_315 == V_316 ) {
F_22 ( & V_53 -> V_87 -> V_88 ,
L_20 ) ;
return - V_73 ;
}
return F_95 ( V_185 , V_310 ) ;
}
static int F_96 ( struct V_216 * V_216 , void * V_250 , struct V_308 * V_309 )
{
struct V_52 * V_53 = V_250 ;
struct V_184 * V_185 = & V_53 -> V_220 ;
int V_68 ;
V_6 V_108 ;
unsigned long V_187 ;
struct V_180 * V_205 ;
V_205 = V_185 -> V_227 [ V_309 -> V_267 ] ;
if ( ! V_53 -> V_167 )
return - V_73 ;
if ( V_216 -> V_317 & V_318 )
V_68 = F_97 ( V_185 , (struct V_308 * ) V_309 , 1 ) ;
else
V_68 = F_97 ( V_185 , (struct V_308 * ) V_309 , 0 ) ;
V_108 = ( unsigned long ) V_53 -> V_63 [ V_205 -> V_54 ] ;
V_187 = ( unsigned long ) V_205 -> V_187 ;
F_98 ( V_53 -> V_87 -> V_88 . V_213 , V_108 ,
V_187 , V_214 ) ;
return V_68 ;
}
static int F_99 ( struct V_216 * V_216 , void * V_250 , enum V_319 V_54 )
{
int V_68 = 0 , V_189 ;
V_6 V_108 = 0 , V_240 = 0 ;
struct V_52 * V_53 = V_250 ;
struct V_184 * V_185 = & V_53 -> V_220 ;
struct V_74 * V_75 = & V_53 -> V_81 ;
F_71 ( & V_53 -> V_273 ) ;
if ( V_53 -> V_167 ) {
V_68 = - V_243 ;
goto V_320;
}
V_68 = F_100 ( V_185 ) ;
if ( V_68 )
goto V_320;
if ( F_28 ( & V_53 -> V_162 ) ) {
V_68 = - V_321 ;
goto V_322;
}
V_53 -> V_157 = V_53 -> V_156 = F_32 ( V_53 -> V_162 . V_179 ,
struct V_180 , V_181 ) ;
F_33 ( & V_53 -> V_156 -> V_181 ) ;
V_53 -> V_156 -> V_159 = V_182 ;
V_53 -> V_155 = 0 ;
V_53 -> V_167 = true ;
V_53 -> V_151 = 1 ;
if ( F_15 ( V_53 ) ) {
V_68 = - V_73 ;
goto V_322;
}
V_108 = ( unsigned long ) V_53 -> V_183 [ V_53 -> V_156 -> V_54 ]
+ V_53 -> V_78 ;
V_240 = V_173 | V_154 | V_153
| V_175 ;
V_68 = F_23 ( V_53 , V_108 ) ;
if ( V_68 ) {
F_38 ( & V_53 -> V_87 -> V_88 ,
L_8 ) ;
goto V_322;
}
F_101 ( F_29 , V_53 , V_240 ) ;
V_68 = F_25 ( V_53 ) ;
if ( V_68 )
F_38 ( & V_53 -> V_87 -> V_88 , L_9 ) ;
for ( V_189 = 0 ; V_189 < V_75 -> V_135 ; V_189 ++ ) {
struct V_90 * V_91 = V_75 -> V_94 [ V_189 ] ;
struct V_136 * V_137 = V_91 -> V_138 ( V_91 ) ;
if ( V_137 ) {
V_68 = V_91 -> V_323 ( V_91 ) ;
if ( V_68 )
goto V_322;
}
}
V_68 = 0 ;
V_322:
if ( V_68 )
V_68 = F_59 ( V_185 ) ;
V_320:
F_73 ( & V_53 -> V_273 ) ;
return V_68 ;
}
static int F_102 ( struct V_216 * V_216 , void * V_250 , enum V_319 V_54 )
{
V_6 V_240 = 0 ;
int V_68 = 0 , V_189 ;
struct V_52 * V_53 = V_250 ;
struct V_74 * V_75 = & V_53 -> V_81 ;
if ( ! V_53 -> V_167 )
return - V_73 ;
V_53 -> V_167 = false ;
V_240 = V_173 | V_154 | V_153
| V_175 ;
F_58 ( F_29 , V_53 , V_240 ) ;
for ( V_189 = 0 ; V_189 < V_75 -> V_135 ; V_189 ++ ) {
struct V_90 * V_91 = V_75 -> V_94 [ V_189 ] ;
struct V_136 * V_137 = V_91 -> V_138 ( V_91 ) ;
if ( V_137 )
V_91 -> V_238 ( V_91 ) ;
}
V_68 = F_25 ( V_53 ) ;
if ( V_68 )
F_38 ( & V_53 -> V_87 -> V_88 , L_21
L_22 ) ;
F_90 ( & V_53 -> V_162 ) ;
V_68 = F_59 ( & V_53 -> V_220 ) ;
return V_68 ;
}
static int F_103 ( struct V_216 * V_216 , void * V_250 ,
const struct V_324 * V_301 )
{
int V_323 = 0 ;
struct V_90 * V_91 ;
struct V_74 * V_75 ;
struct V_52 * V_53 = V_250 ;
struct V_279 V_110 ;
enum V_325 V_326 = V_327 ;
V_75 = & V_53 -> V_81 ;
V_91 = V_75 -> V_94 [ 0 ] ;
if ( ( V_301 -> V_268 & V_328 ) &&
( V_301 -> V_268 & V_329 ) )
return - V_73 ;
if ( ( V_301 -> V_268 & V_329 ) &&
( V_301 -> V_268 & V_330 ) )
return - V_73 ;
if ( ( V_301 -> V_268 & V_328 ) ) {
V_53 -> V_272 . V_268 |= V_328 ;
V_326 = V_331 ;
} else
V_53 -> V_272 . V_268 &= ~ V_328 ;
if ( ( V_301 -> V_268 & V_329 ) ) {
V_53 -> V_272 . V_268 |= V_329 ;
V_326 = V_327 ;
} else
V_53 -> V_272 . V_268 &= ~ V_329 ;
if ( V_301 -> V_268 & ( V_329 |
V_328 ) )
V_323 = 1 ;
else
V_323 = 0 ;
if ( V_91 -> V_145 && V_91 -> V_145 -> V_280 &&
V_91 -> V_145 -> V_304 ) {
V_91 -> V_145 -> V_280 ( V_91 -> V_145 , & V_110 ) ;
V_110 . V_332 = V_323 ;
V_110 . V_333 = V_326 ;
V_110 . V_281 = V_53 -> V_126 . V_277 ;
if ( V_91 -> V_145 -> V_304 ( V_91 -> V_145 , & V_110 ) )
return - V_73 ;
}
if ( V_301 -> V_268 & V_330 ) {
V_53 -> V_272 . V_268 |= V_330 ;
V_323 = 1 ;
} else {
V_53 -> V_272 . V_268 &= ~ V_330 ;
V_323 = 0 ;
}
if ( V_91 -> V_145 && V_91 -> V_145 -> V_280 &&
V_91 -> V_145 -> V_304 ) {
V_91 -> V_145 -> V_280 ( V_91 -> V_145 , & V_110 ) ;
if ( ( V_91 -> V_114 & V_334 ) == 0 )
V_110 . V_335 = V_323 ;
if ( V_91 -> V_145 -> V_304 ( V_91 -> V_145 , & V_110 ) )
return - V_73 ;
}
return 0 ;
}
static int F_104 ( struct V_216 * V_216 , void * V_250 ,
struct V_324 * V_301 )
{
struct V_90 * V_91 ;
struct V_74 * V_75 ;
struct V_52 * V_53 = V_250 ;
struct V_279 V_110 ;
V_75 = & V_53 -> V_81 ;
V_91 = V_75 -> V_94 [ 0 ] ;
V_301 -> V_268 = V_336 ;
V_301 -> V_337 = V_338 | V_339
| V_340 ;
if ( V_91 -> V_145 && V_91 -> V_145 -> V_280 ) {
V_91 -> V_145 -> V_280 ( V_91 -> V_145 , & V_110 ) ;
if ( V_110 . V_333 == V_331 )
V_301 -> V_268 |= V_328 ;
if ( V_110 . V_333 == V_327 )
V_301 -> V_268 |= V_329 ;
}
if ( V_91 -> V_145 && V_91 -> V_145 -> V_280 ) {
V_91 -> V_145 -> V_280 ( V_91 -> V_145 , & V_110 ) ;
if ( V_110 . V_335 )
V_301 -> V_268 |= V_330 ;
}
return 0 ;
}
static int T_1 F_105 ( struct V_52 * V_53 )
{
struct V_341 * V_256 ;
struct V_1 * V_2 ;
struct V_297 * V_299 ;
struct V_90 * V_91 = V_53 -> V_81 . V_94 [ 0 ] ;
struct V_136 * V_342 = V_91 -> V_138 ( V_91 ) ;
V_2 = & V_53 -> V_2 ;
V_2 -> V_9 = V_343 ;
V_2 -> V_5 = V_344 ;
V_2 -> V_13 = V_22 ;
V_2 -> V_15 = V_16 ;
V_2 -> V_31 = V_2 -> V_9 * 2 ;
V_2 -> V_32 = V_2 -> V_31 * V_2 -> V_5 ;
V_2 -> V_19 = V_20 ;
V_53 -> V_4 = V_25 ;
V_53 -> V_272 . V_266 . V_9 = V_342 -> V_139 . V_140 . V_143 ;
V_53 -> V_272 . V_266 . V_5 = V_342 -> V_139 . V_140 . V_142 ;
V_53 -> V_126 . V_125 = 255 ;
V_53 -> V_272 . V_268 = 0 ;
V_53 -> V_272 . V_337 = V_338 |
V_340 | V_339 ;
V_53 -> V_126 . V_277 = 0 ;
F_72 ( V_2 , & V_53 -> V_272 , & V_53 -> V_77 , & V_53 -> V_126 ) ;
V_299 = V_53 -> V_299 ;
V_299 [ 0 ] . V_99 = V_294 ;
V_299 [ 0 ] . V_298 = 0 ;
V_53 -> V_66 = 0 ;
V_53 -> V_67 = false ;
V_53 -> V_299 [ 2 ] . V_99 = V_345 ;
V_53 -> V_299 [ 2 ] . V_298 = 0 ;
if ( V_53 -> V_81 . V_82 == V_83 )
V_53 -> V_275 = 2 ;
V_299 [ 1 ] . V_99 = V_295 ;
V_299 [ 1 ] . V_298 = 0 ;
V_256 = V_53 -> V_256 = F_106 () ;
if ( ! V_256 ) {
F_11 (KERN_ERR VOUT_NAME L_23
L_24 ) ;
return - V_198 ;
}
V_256 -> V_346 = V_347 ;
V_256 -> V_348 = & V_349 ;
F_66 ( V_256 -> V_257 , V_254 , sizeof( V_256 -> V_257 ) ) ;
V_256 -> V_350 = & V_351 ;
V_256 -> V_88 = & V_53 -> V_87 -> V_88 ;
V_256 -> V_352 = V_353 ;
F_107 ( & V_53 -> V_273 ) ;
V_256 -> V_354 = - 1 ;
return 0 ;
}
static int T_1 F_108 ( struct V_355 * V_356 ,
int V_357 )
{
V_6 V_55 ;
int V_68 = 0 , V_54 ;
struct V_74 * V_75 ;
struct V_52 * V_53 ;
struct V_358 * V_88 = F_109 ( V_356 ) ;
struct V_359 * V_87 =
F_110 ( V_88 , struct V_359 , V_88 ) ;
V_53 = V_87 -> V_360 [ V_357 ] ;
V_75 = & V_53 -> V_81 ;
V_55 = ( V_357 == 0 ) ? V_58 : V_57 ;
V_53 -> V_59 = ( V_357 == 0 ) ? V_61 : V_60 ;
F_111 ( & V_356 -> V_213 , L_25 , V_53 -> V_59 ) ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
V_53 -> V_62 [ V_54 ] =
F_39 ( V_53 -> V_59 ,
( V_6 * ) & V_53 -> V_63 [ V_54 ] ) ;
if ( ! V_53 -> V_62 [ V_54 ] ) {
V_55 = V_54 ;
V_68 = - V_198 ;
goto V_361;
}
}
V_53 -> V_78 = 0 ;
if ( V_75 -> V_82 == V_83 ) {
bool V_362 = ( V_357 == 0 ) ?
V_363 : V_364 ;
V_68 = F_112 ( V_356 , V_357 ,
V_362 ) ;
}
return V_68 ;
V_361:
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
F_13 ( V_53 -> V_62 [ V_54 ] ,
V_53 -> V_59 ) ;
V_53 -> V_62 [ V_54 ] = 0 ;
V_53 -> V_63 [ V_54 ] = 0 ;
}
return V_68 ;
}
static int T_1 F_113 ( struct V_355 * V_356 )
{
int V_68 = 0 , V_365 ;
struct V_52 * V_53 ;
struct V_341 * V_256 = NULL ;
struct V_358 * V_88 = F_109 ( V_356 ) ;
struct V_359 * V_87 = F_110 ( V_88 ,
struct V_359 , V_88 ) ;
for ( V_365 = 0 ; V_365 < V_356 -> V_366 ; V_365 ++ ) {
V_53 = F_114 ( sizeof( struct V_52 ) , V_367 ) ;
if ( ! V_53 ) {
F_115 ( & V_356 -> V_213 , L_26 ) ;
return - V_198 ;
}
V_53 -> V_56 = V_365 ;
V_87 -> V_360 [ V_365 ] = V_53 ;
V_53 -> V_87 = V_87 ;
if ( V_356 -> V_366 == 1 )
V_53 -> V_81 . V_94 [ 0 ] = V_87 -> V_94 [ V_365 + 2 ] ;
else
V_53 -> V_81 . V_94 [ 0 ] = V_87 -> V_94 [ V_365 + 1 ] ;
V_53 -> V_81 . V_135 = 1 ;
V_53 -> V_81 . V_99 = V_365 + 1 ;
if ( F_116 () || F_117 () )
V_53 -> V_81 . V_82 = V_83 ;
if ( F_105 ( V_53 ) != 0 ) {
V_68 = - V_198 ;
goto error;
}
if ( F_108 ( V_356 , V_365 ) != 0 ) {
V_68 = - V_198 ;
goto V_368;
}
V_256 = V_53 -> V_256 ;
if ( F_118 ( V_256 , V_369 , - 1 ) < 0 ) {
F_115 ( & V_356 -> V_213 , L_27
L_28 ) ;
V_256 -> V_354 = - 1 ;
V_68 = - V_242 ;
goto V_370;
}
F_119 ( V_256 , V_53 ) ;
F_111 ( & V_356 -> V_213 , L_29
L_30 , V_256 -> V_354 ) ;
if ( V_365 == ( V_356 -> V_366 - 1 ) )
return 0 ;
continue;
V_370:
if ( V_53 -> V_81 . V_82 == V_83 )
F_120 ( V_53 ) ;
F_12 ( V_53 ) ;
V_368:
V_347 ( V_256 ) ;
error:
F_89 ( V_53 ) ;
return V_68 ;
}
return - V_242 ;
}
static void F_121 ( struct V_52 * V_53 )
{
struct V_341 * V_256 ;
struct V_74 * V_75 ;
if ( ! V_53 )
return;
V_256 = V_53 -> V_256 ;
V_75 = & V_53 -> V_81 ;
if ( V_256 ) {
if ( ! F_122 ( V_256 ) ) {
V_347 ( V_256 ) ;
} else {
F_123 ( V_256 ) ;
}
}
if ( V_75 -> V_82 == V_83 ) {
F_120 ( V_53 ) ;
if ( V_53 -> V_239 )
F_56 ( V_53 ) ;
}
F_12 ( V_53 ) ;
F_89 ( V_53 ) ;
}
static int F_124 ( struct V_355 * V_356 )
{
int V_365 ;
struct V_358 * V_88 = F_109 ( V_356 ) ;
struct V_359 * V_87 = F_110 ( V_88 , struct
V_359 , V_88 ) ;
F_125 ( V_88 ) ;
for ( V_365 = 0 ; V_365 < V_356 -> V_366 ; V_365 ++ )
F_121 ( V_87 -> V_360 [ V_365 ] ) ;
for ( V_365 = 0 ; V_365 < V_87 -> V_371 ; V_365 ++ ) {
if ( V_87 -> V_372 [ V_365 ] -> V_159 != V_373 )
V_87 -> V_372 [ V_365 ] -> V_253 -> V_238 ( V_87 -> V_372 [ V_365 ] ) ;
F_126 ( V_87 -> V_372 [ V_365 ] ) ;
}
F_89 ( V_87 ) ;
return 0 ;
}
static int T_1 F_127 ( struct V_355 * V_356 )
{
int V_68 = 0 , V_54 ;
struct V_90 * V_91 ;
struct V_136 * V_137 = NULL ;
struct V_136 * V_374 ;
struct V_359 * V_87 = NULL ;
if ( F_128 () == false )
return - V_375 ;
V_68 = F_129 () ;
if ( V_68 ) {
F_115 ( & V_356 -> V_213 , L_31 ) ;
return V_68 ;
}
if ( V_356 -> V_366 == 0 ) {
F_115 ( & V_356 -> V_213 , L_32 ) ;
V_68 = - V_242 ;
goto V_376;
}
V_87 = F_114 ( sizeof( struct V_359 ) , V_367 ) ;
if ( V_87 == NULL ) {
V_68 = - V_198 ;
goto V_376;
}
V_87 -> V_371 = 0 ;
F_130 (dssdev) {
F_131 ( V_137 ) ;
if ( ! V_137 -> V_253 ) {
F_132 ( & V_356 -> V_213 , L_33 ,
V_137 -> V_257 ) ;
F_126 ( V_137 ) ;
continue;
}
V_87 -> V_372 [ V_87 -> V_371 ++ ] = V_137 ;
}
if ( V_87 -> V_371 == 0 ) {
F_115 ( & V_356 -> V_213 , L_34 ) ;
V_68 = - V_73 ;
goto V_377;
}
V_87 -> V_135 = F_133 () ;
for ( V_54 = 0 ; V_54 < V_87 -> V_135 ; V_54 ++ )
V_87 -> V_94 [ V_54 ] = F_134 ( V_54 ) ;
V_87 -> V_378 = F_135 () ;
for ( V_54 = 0 ; V_54 < V_87 -> V_378 ; V_54 ++ )
V_87 -> V_379 [ V_54 ] = F_136 ( V_54 ) ;
for ( V_54 = 1 ; V_54 < V_87 -> V_135 ; V_54 ++ ) {
V_91 = F_134 ( V_54 ) ;
V_137 = V_91 -> V_138 ( V_91 ) ;
if ( V_137 ) {
V_374 = V_137 ;
} else {
F_132 ( & V_356 -> V_213 , L_35 ) ;
V_374 = NULL ;
}
if ( V_374 ) {
struct V_380 * V_381 = V_374 -> V_253 ;
V_68 = V_381 -> V_323 ( V_374 ) ;
if ( V_68 ) {
F_132 ( & V_356 -> V_213 ,
L_36 ,
V_374 -> V_257 ) ;
}
}
}
if ( F_137 ( & V_356 -> V_213 , & V_87 -> V_88 ) < 0 ) {
F_115 ( & V_356 -> V_213 , L_37 ) ;
V_68 = - V_242 ;
goto V_382;
}
V_68 = F_113 ( V_356 ) ;
if ( V_68 )
goto V_383;
for ( V_54 = 0 ; V_54 < V_87 -> V_371 ; V_54 ++ ) {
struct V_136 * V_342 = V_87 -> V_372 [ V_54 ] ;
if ( V_342 -> V_253 -> V_384 )
V_342 -> V_253 -> V_384 ( V_342 , 0 , 0 ,
V_342 -> V_139 . V_140 . V_143 ,
V_342 -> V_139 . V_140 . V_142 ) ;
}
return 0 ;
V_383:
F_125 ( & V_87 -> V_88 ) ;
V_382:
for ( V_54 = 1 ; V_54 < V_87 -> V_135 ; V_54 ++ ) {
V_374 = NULL ;
V_91 = F_134 ( V_54 ) ;
V_137 = V_91 -> V_138 ( V_91 ) ;
if ( V_137 )
V_374 = V_137 ;
if ( V_374 && V_374 -> V_253 )
V_374 -> V_253 -> V_238 ( V_374 ) ;
}
V_377:
F_89 ( V_87 ) ;
V_376:
F_138 () ;
return V_68 ;
}
static int T_1 F_139 ( void )
{
if ( F_140 ( & V_385 , F_127 ) != 0 ) {
F_11 (KERN_ERR VOUT_NAME L_38 ) ;
return - V_73 ;
}
return 0 ;
}
static void F_141 ( void )
{
F_142 ( & V_385 ) ;
}
