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
V_2 -> V_17 = 0 ;
switch ( V_2 -> V_13 ) {
case V_18 :
case V_19 :
default:
V_2 -> V_20 = V_21 ;
V_4 = V_22 ;
break;
case V_23 :
case V_24 :
V_2 -> V_20 = V_25 ;
V_4 = V_26 ;
break;
case V_27 :
V_2 -> V_20 = V_25 ;
V_4 = V_28 ;
break;
case V_29 :
case V_30 :
V_2 -> V_20 = V_25 ;
V_4 = V_31 ;
break;
}
V_2 -> V_32 = V_2 -> V_9 * V_4 ;
V_2 -> V_33 = V_2 -> V_32 * V_2 -> V_5 ;
return V_4 ;
}
static V_6 F_3 ( V_6 V_34 )
{
unsigned long V_35 = 0 ;
struct V_36 * V_37 ;
struct V_38 * V_39 = V_40 -> V_39 ;
if ( V_34 >= V_41 )
return F_4 ( ( void * ) V_34 ) ;
F_5 ( & V_40 -> V_39 -> V_42 ) ;
V_37 = F_6 ( V_39 , V_34 ) ;
if ( V_37 && ( V_37 -> V_43 & V_44 ) && V_37 -> V_45 ) {
V_35 = ( V_37 -> V_45 << V_46 ) + ( V_34 - V_37 -> V_47 ) ;
F_7 ( & V_40 -> V_39 -> V_42 ) ;
} else {
int V_48 , V_49 = 1 ;
struct V_50 * V_51 ;
V_48 = F_8 ( V_40 , V_40 -> V_39 , V_34 , V_49 , 1 ,
0 , & V_51 , NULL ) ;
F_7 ( & V_40 -> V_39 -> V_42 ) ;
if ( V_48 == V_49 ) {
V_35 = F_9 ( F_10 ( & V_51 [ 0 ] ) +
( V_34 & ~ V_52 ) ) ;
} else {
F_11 (KERN_WARNING VOUT_NAME
L_1 ) ;
return 0 ;
}
}
return V_35 ;
}
void F_12 ( struct V_53 * V_54 )
{
int V_55 , V_56 ;
V_56 = ( V_54 -> V_57 ) ? V_58 : V_59 ;
V_54 -> V_60 = ( V_54 -> V_57 ) ? V_61 : V_62 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
F_13 ( V_54 -> V_63 [ V_55 ] ,
V_54 -> V_60 ) ;
V_54 -> V_64 [ V_55 ] = 0 ;
V_54 -> V_63 [ V_55 ] = 0 ;
}
}
static int F_14 ( int V_65 ,
enum V_66 * V_67 , bool V_68 )
{
int V_69 = 0 ;
switch ( V_65 ) {
case 90 :
* V_67 = V_70 ;
break;
case 180 :
* V_67 = V_71 ;
break;
case 270 :
* V_67 = V_72 ;
break;
case 0 :
* V_67 = V_73 ;
break;
default:
V_69 = - V_74 ;
}
return V_69 ;
}
static int F_15 ( struct V_53 * V_54 )
{
struct V_75 * V_76 ;
struct V_77 * V_78 = & V_54 -> V_78 ;
struct V_1 * V_2 = & V_54 -> V_2 ;
int * V_79 = & V_54 -> V_79 ;
int V_80 = 2 , V_81 = 0 ;
V_76 = & V_54 -> V_82 ;
if ( V_76 -> V_83 == V_84 ) {
F_16 ( V_54 ) ;
} else {
V_54 -> V_81 = V_81 = V_2 -> V_9 ;
if ( V_18 == V_2 -> V_13 ||
V_19 == V_2 -> V_13 )
V_80 = 2 ;
else if ( V_29 == V_2 -> V_13 )
V_80 = 4 ;
else if ( V_27 == V_2 -> V_13 )
V_80 = 3 ;
V_54 -> V_80 = V_80 ;
* V_79 = ( V_81 * V_80 ) *
V_78 -> V_85 + V_78 -> V_86 * V_80 ;
}
F_17 ( 1 , V_87 , & V_54 -> V_88 -> V_89 , L_2 ,
V_90 , V_54 -> V_79 ) ;
return 0 ;
}
static int F_18 ( struct V_53 * V_54 )
{
struct V_91 * V_92 ;
struct V_75 * V_76 ;
struct V_1 * V_2 = & V_54 -> V_2 ;
enum V_93 V_94 ;
V_76 = & V_54 -> V_82 ;
V_92 = V_76 -> V_95 [ 0 ] ;
switch ( V_2 -> V_13 ) {
case V_18 :
V_94 = V_96 ;
break;
case V_19 :
V_94 = V_97 ;
break;
case V_23 :
V_94 = V_98 ;
break;
case V_27 :
V_94 = V_99 ;
break;
case V_29 :
V_94 = ( V_92 -> V_100 == V_101 ) ?
V_102 : V_103 ;
break;
case V_30 :
V_94 = V_104 ;
break;
default:
V_94 = - V_74 ;
break;
}
return V_94 ;
}
static int F_19 ( struct V_53 * V_54 ,
struct V_91 * V_92 , int V_105 , int V_106 , int V_107 ,
int V_108 , V_6 V_109 )
{
int V_69 = 0 ;
struct V_110 V_111 ;
int V_112 , V_113 , V_114 , V_115 ;
if ( ( V_92 -> V_116 & V_117 ) == 0 &&
( V_107 != V_54 -> V_2 . V_9 || V_108 != V_54 -> V_2 . V_5 ) ) {
V_69 = - V_74 ;
goto V_118;
}
V_54 -> V_119 = F_18 ( V_54 ) ;
if ( V_54 -> V_119 == - V_74 ) {
V_69 = - V_74 ;
goto V_118;
}
if ( F_20 ( V_54 ) ) {
V_112 = V_54 -> V_78 . V_9 ;
V_113 = V_54 -> V_78 . V_5 ;
V_114 = V_54 -> V_2 . V_9 ;
V_115 = V_54 -> V_2 . V_5 ;
} else {
V_112 = V_54 -> V_78 . V_5 ;
V_113 = V_54 -> V_78 . V_9 ;
V_114 = V_54 -> V_2 . V_5 ;
V_115 = V_54 -> V_2 . V_9 ;
}
V_92 -> V_120 ( V_92 , & V_111 ) ;
V_111 . V_121 = V_109 ;
V_111 . V_9 = V_113 ;
V_111 . V_5 = V_112 ;
V_111 . V_122 = V_54 -> V_119 ;
V_111 . V_68 = V_54 -> V_68 ;
V_111 . V_123 = V_105 ;
V_111 . V_124 = V_106 ;
V_111 . V_125 = V_107 ;
V_111 . V_126 = V_108 ;
V_111 . V_127 = V_54 -> V_128 . V_127 ;
if ( ! F_21 ( V_54 ) ) {
V_111 . V_67 = 0 ;
V_111 . V_83 = V_129 ;
V_111 . V_130 = V_115 ;
} else {
V_111 . V_67 = V_54 -> V_67 ;
V_111 . V_83 = V_131 ;
V_111 . V_130 = 2048 ;
}
F_17 ( 1 , V_87 , & V_54 -> V_88 -> V_89 ,
L_3
L_4
L_5 ,
V_90 , V_92 -> V_132 ( V_92 ) , V_111 . V_121 , V_111 . V_9 , V_111 . V_5 ,
V_111 . V_122 , V_111 . V_67 , V_111 . V_68 , V_111 . V_123 ,
V_111 . V_124 , V_111 . V_125 , V_111 . V_126 , V_111 . V_83 ,
V_111 . V_130 ) ;
V_69 = V_92 -> V_133 ( V_92 , & V_111 ) ;
if ( V_69 )
goto V_118;
return 0 ;
V_118:
F_22 ( & V_54 -> V_88 -> V_89 , L_6 ) ;
return V_69 ;
}
static int F_23 ( struct V_53 * V_54 , V_6 V_109 )
{
int V_69 = 0 , V_55 ;
struct V_134 * V_128 ;
struct V_91 * V_92 ;
int V_105 , V_106 , V_107 , V_108 , V_135 ;
struct V_136 * V_137 ;
struct V_75 * V_76 = & V_54 -> V_82 ;
V_128 = & V_54 -> V_128 ;
for ( V_55 = 0 ; V_55 < V_76 -> V_138 ; V_55 ++ ) {
struct V_139 * V_140 ;
V_92 = V_76 -> V_95 [ V_55 ] ;
V_140 = V_92 -> V_141 ( V_92 ) ;
if ( ! V_140 )
return - V_74 ;
V_137 = & V_140 -> V_142 . V_143 ;
V_107 = V_128 -> V_144 . V_9 ;
V_108 = V_128 -> V_144 . V_5 ;
switch ( V_54 -> V_67 ) {
case V_70 :
V_135 = V_107 ;
V_107 = V_108 ;
V_108 = V_135 ;
V_106 = ( V_137 -> V_145 - V_128 -> V_144 . V_9 ) - V_128 -> V_144 . V_86 ;
V_105 = V_128 -> V_144 . V_85 ;
break;
case V_71 :
V_105 = ( V_137 -> V_146 - V_128 -> V_144 . V_9 ) - V_128 -> V_144 . V_86 ;
V_106 = ( V_137 -> V_145 - V_128 -> V_144 . V_5 ) - V_128 -> V_144 . V_85 ;
break;
case V_72 :
V_135 = V_107 ;
V_107 = V_108 ;
V_108 = V_135 ;
V_106 = V_128 -> V_144 . V_86 ;
V_105 = ( V_137 -> V_146 - V_128 -> V_144 . V_5 ) - V_128 -> V_144 . V_85 ;
break;
default:
V_105 = V_128 -> V_144 . V_86 ;
V_106 = V_128 -> V_144 . V_85 ;
break;
}
V_69 = F_19 ( V_54 , V_92 , V_105 , V_106 ,
V_107 , V_108 , V_109 ) ;
if ( V_69 )
goto V_147;
}
return 0 ;
V_147:
F_22 ( & V_54 -> V_88 -> V_89 , L_7 ) ;
return V_69 ;
}
static int F_24 ( struct V_53 * V_54 )
{
int V_55 ;
struct V_91 * V_92 ;
struct V_75 * V_76 = & V_54 -> V_82 ;
for ( V_55 = 0 ; V_55 < V_76 -> V_138 ; V_55 ++ ) {
struct V_139 * V_140 ;
V_92 = V_76 -> V_95 [ V_55 ] ;
V_140 = V_92 -> V_141 ( V_92 ) ;
if ( ! V_140 )
return - V_74 ;
V_92 -> V_148 -> V_149 ( V_92 -> V_148 ) ;
}
return 0 ;
}
static int F_25 ( struct V_53 * V_54 ,
unsigned int V_150 , struct V_151 V_152 )
{
V_6 V_153 ;
if ( V_54 -> V_154 ) {
V_54 -> V_154 = 0 ;
goto V_155;
}
if ( V_150 & V_156 )
V_153 = 1 ;
else if ( V_150 & V_157 )
V_153 = 0 ;
else
goto V_155;
V_54 -> V_158 ^= 1 ;
if ( V_153 != V_54 -> V_158 ) {
if ( V_153 == 0 )
V_54 -> V_158 = V_153 ;
} else if ( 0 == V_153 ) {
if ( V_54 -> V_159 == V_54 -> V_160 )
goto V_155;
V_54 -> V_159 -> V_161 = V_152 ;
V_54 -> V_159 -> V_162 = V_163 ;
F_26 ( & V_54 -> V_159 -> V_164 ) ;
V_54 -> V_159 = V_54 -> V_160 ;
} else {
if ( F_27 ( & V_54 -> V_165 ) ||
( V_54 -> V_159 != V_54 -> V_160 ) )
goto V_155;
}
return V_54 -> V_158 ;
V_155:
return 0 ;
}
static void F_28 ( void * V_166 , unsigned int V_150 )
{
int V_69 , V_153 , V_167 ;
V_6 V_109 , V_168 ;
struct V_91 * V_92 ;
struct V_151 V_152 ;
struct V_75 * V_76 ;
struct V_139 * V_169 ;
struct V_53 * V_54 = (struct V_53 * ) V_166 ;
if ( ! V_54 -> V_170 )
return;
V_76 = & V_54 -> V_82 ;
V_92 = V_76 -> V_95 [ 0 ] ;
V_167 = V_92 -> V_148 -> V_100 ;
V_169 = V_92 -> V_141 ( V_92 ) ;
if ( ! V_169 )
return;
F_29 ( & V_54 -> V_171 ) ;
F_30 ( & V_152 ) ;
switch ( V_169 -> type ) {
case V_172 :
case V_173 :
case V_174 :
if ( V_167 == V_175 )
V_168 = V_176 ;
else if ( V_167 == V_177 )
V_168 = V_178 ;
else
goto V_179;
if ( ! ( V_150 & V_168 ) )
goto V_179;
break;
case V_180 :
V_153 = F_25 ( V_54 , V_150 ,
V_152 ) ;
if ( ! V_153 )
goto V_179;
break;
case V_181 :
if ( ! ( V_150 & V_157 ) )
goto V_179;
break;
default:
goto V_179;
}
if ( ! V_54 -> V_154 && ( V_54 -> V_159 != V_54 -> V_160 ) ) {
V_54 -> V_159 -> V_161 = V_152 ;
V_54 -> V_159 -> V_162 = V_163 ;
F_26 ( & V_54 -> V_159 -> V_164 ) ;
V_54 -> V_159 = V_54 -> V_160 ;
}
V_54 -> V_154 = 0 ;
if ( F_27 ( & V_54 -> V_165 ) )
goto V_179;
V_54 -> V_160 = F_31 ( V_54 -> V_165 . V_182 ,
struct V_183 , V_184 ) ;
F_32 ( & V_54 -> V_160 -> V_184 ) ;
V_54 -> V_160 -> V_162 = V_185 ;
V_109 = ( unsigned long ) V_54 -> V_186 [ V_54 -> V_160 -> V_55 ]
+ V_54 -> V_79 ;
V_69 = F_23 ( V_54 , V_109 ) ;
if ( V_69 ) {
F_11 (KERN_ERR VOUT_NAME
L_8 ) ;
goto V_179;
}
V_69 = F_24 ( V_54 ) ;
if ( V_69 )
F_11 (KERN_ERR VOUT_NAME L_9 ) ;
V_179:
F_33 ( & V_54 -> V_171 ) ;
}
static int F_34 ( struct V_187 * V_188 , unsigned int * V_189 ,
unsigned int * V_190 )
{
int V_191 = 0 , V_55 , V_192 ;
V_6 V_193 = 0 , V_194 = 0 ;
struct V_53 * V_54 = V_188 -> V_195 ;
struct V_75 * V_76 = & V_54 -> V_82 ;
int V_196 ;
if ( ! V_54 )
return - V_74 ;
V_196 = V_54 -> V_57 == V_197 ? V_62 :
V_61 ;
if ( V_198 != V_188 -> type )
return - V_74 ;
V_191 = ( V_54 -> V_57 == V_197 ) ?
V_59 : V_58 ;
if ( V_199 == V_54 -> V_200 && * V_189 < V_191 )
* V_189 = V_191 ;
if ( V_76 -> V_83 == V_84 ) {
if ( F_35 ( V_54 , V_189 , V_191 ) )
return - V_201 ;
}
if ( V_199 != V_54 -> V_200 )
return 0 ;
* V_190 = F_36 ( V_54 -> V_2 . V_9 * V_54 -> V_2 . V_5 * V_54 -> V_4 ) ;
V_191 = ( V_54 -> V_57 == V_197 ) ?
V_59 : V_58 ;
if ( * V_190 > V_196 ) {
F_37 ( & V_54 -> V_88 -> V_89 ,
L_10 ,
* V_190 , V_54 -> V_60 ) ;
return - V_201 ;
}
for ( V_55 = V_191 ; V_55 < * V_189 ; V_55 ++ ) {
V_54 -> V_60 = * V_190 ;
V_194 = F_38 ( V_54 -> V_60 ,
& V_193 ) ;
if ( ! V_194 ) {
if ( V_76 -> V_83 == V_202 ) {
break;
} else {
if ( ! F_21 ( V_54 ) )
break;
for ( V_192 = V_55 ; V_192 < * V_189 ; V_192 ++ ) {
F_13 (
V_54 -> V_203 [ V_192 ] ,
V_54 -> V_204 ) ;
V_54 -> V_203 [ V_192 ] = 0 ;
V_54 -> V_205 [ V_192 ] = 0 ;
}
}
}
V_54 -> V_63 [ V_55 ] = V_194 ;
V_54 -> V_64 [ V_55 ] = V_193 ;
}
* V_189 = V_54 -> V_206 = V_55 ;
return 0 ;
}
static void F_39 ( struct V_53 * V_54 )
{
int V_207 = 0 , V_55 ;
V_207 = ( V_54 -> V_57 == V_197 ) ?
V_59 : V_58 ;
for ( V_55 = V_207 ; V_55 < V_54 -> V_206 ; V_55 ++ ) {
if ( V_54 -> V_63 [ V_55 ] )
F_13 ( V_54 -> V_63 [ V_55 ] ,
V_54 -> V_60 ) ;
V_54 -> V_63 [ V_55 ] = 0 ;
V_54 -> V_64 [ V_55 ] = 0 ;
}
V_54 -> V_206 = V_207 ;
}
static int F_40 ( struct V_187 * V_188 ,
struct V_183 * V_208 ,
enum V_209 V_15 )
{
struct V_53 * V_54 = V_188 -> V_195 ;
struct V_75 * V_76 = & V_54 -> V_82 ;
if ( V_210 == V_208 -> V_162 ) {
V_208 -> V_9 = V_54 -> V_2 . V_9 ;
V_208 -> V_5 = V_54 -> V_2 . V_5 ;
V_208 -> V_190 = V_208 -> V_9 * V_208 -> V_5 * V_54 -> V_4 ;
V_208 -> V_15 = V_15 ;
}
V_208 -> V_162 = V_211 ;
if ( V_212 == V_208 -> V_200 ) {
if ( 0 == V_208 -> V_213 )
return - V_74 ;
V_54 -> V_186 [ V_208 -> V_55 ] = ( V_214 * )
F_3 ( V_208 -> V_213 ) ;
} else {
V_6 V_109 , V_215 ;
unsigned long V_190 ;
V_109 = ( unsigned long ) V_54 -> V_63 [ V_208 -> V_55 ] ;
V_190 = ( unsigned long ) V_208 -> V_190 ;
V_215 = F_41 ( V_54 -> V_88 -> V_89 . V_216 , ( void * ) V_109 ,
V_190 , V_217 ) ;
if ( F_42 ( V_54 -> V_88 -> V_89 . V_216 , V_215 ) )
F_37 ( & V_54 -> V_88 -> V_89 , L_11 ) ;
V_54 -> V_186 [ V_208 -> V_55 ] = ( V_214 * ) V_54 -> V_64 [ V_208 -> V_55 ] ;
}
if ( V_76 -> V_83 == V_84 )
return F_43 ( V_54 , V_208 ) ;
else
return 0 ;
}
static void F_44 ( struct V_187 * V_188 ,
struct V_183 * V_208 )
{
struct V_53 * V_54 = V_188 -> V_195 ;
F_45 ( & V_208 -> V_184 , & V_54 -> V_165 ) ;
V_208 -> V_162 = V_218 ;
}
static void F_46 ( struct V_187 * V_188 ,
struct V_183 * V_208 )
{
struct V_53 * V_54 = V_188 -> V_195 ;
V_208 -> V_162 = V_210 ;
if ( V_199 != V_54 -> V_200 )
return;
}
static unsigned int F_47 ( struct V_219 * V_219 ,
struct V_220 * V_221 )
{
struct V_53 * V_54 = V_219 -> V_222 ;
struct V_187 * V_188 = & V_54 -> V_223 ;
return F_48 ( V_219 , V_188 , V_221 ) ;
}
static void F_49 ( struct V_36 * V_37 )
{
struct V_53 * V_54 = V_37 -> V_224 ;
F_17 ( 1 , V_87 , & V_54 -> V_88 -> V_89 ,
L_12 , V_37 -> V_47 , V_37 -> V_225 ) ;
V_54 -> V_226 ++ ;
}
static void F_50 ( struct V_36 * V_37 )
{
struct V_53 * V_54 = V_37 -> V_224 ;
F_17 ( 1 , V_87 , & V_54 -> V_88 -> V_89 ,
L_13 , V_37 -> V_47 , V_37 -> V_225 ) ;
V_54 -> V_226 -- ;
}
static int F_51 ( struct V_219 * V_219 , struct V_36 * V_37 )
{
int V_55 ;
void * V_227 ;
unsigned long V_228 = V_37 -> V_47 ;
unsigned long V_190 = ( V_37 -> V_225 - V_37 -> V_47 ) ;
struct V_53 * V_54 = V_219 -> V_222 ;
struct V_187 * V_188 = & V_54 -> V_223 ;
F_17 ( 1 , V_87 , & V_54 -> V_88 -> V_89 ,
L_14 , V_90 ,
V_37 -> V_45 , V_37 -> V_47 , V_37 -> V_225 ) ;
for ( V_55 = 0 ; V_55 < V_229 ; V_55 ++ ) {
if ( NULL == V_188 -> V_230 [ V_55 ] )
continue;
if ( V_199 != V_188 -> V_230 [ V_55 ] -> V_200 )
continue;
if ( V_188 -> V_230 [ V_55 ] -> V_231 == ( V_37 -> V_45 << V_46 ) )
break;
}
if ( V_229 == V_55 ) {
F_17 ( 1 , V_87 , & V_54 -> V_88 -> V_89 ,
L_15 ,
( V_37 -> V_45 << V_46 ) ) ;
return - V_74 ;
}
if ( V_190 > V_54 -> V_60 ) {
F_37 ( & V_54 -> V_88 -> V_89 ,
L_16 ,
V_190 , V_54 -> V_60 ) ;
return - V_201 ;
}
V_188 -> V_230 [ V_55 ] -> V_213 = V_37 -> V_47 ;
V_37 -> V_43 |= V_232 | V_233 ;
V_37 -> V_234 = F_52 ( V_37 -> V_234 ) ;
V_37 -> V_235 = & V_236 ;
V_37 -> V_224 = ( void * ) V_54 ;
V_227 = ( void * ) V_54 -> V_63 [ V_55 ] ;
V_37 -> V_45 = F_4 ( ( void * ) V_227 ) >> V_46 ;
while ( V_190 > 0 ) {
unsigned long V_237 ;
V_237 = F_4 ( ( void * ) V_227 ) >> V_46 ;
if ( F_53 ( V_37 , V_228 , V_237 , V_238 , V_239 ) )
return - V_240 ;
V_228 += V_238 ;
V_227 += V_238 ;
V_190 -= V_238 ;
}
V_54 -> V_226 ++ ;
F_17 ( 1 , V_87 , & V_54 -> V_88 -> V_89 , L_17 , V_90 ) ;
return 0 ;
}
static int F_54 ( struct V_219 * V_219 )
{
unsigned int V_69 , V_55 ;
struct V_187 * V_188 ;
struct V_75 * V_76 ;
struct V_53 * V_54 = V_219 -> V_222 ;
F_17 ( 1 , V_87 , & V_54 -> V_88 -> V_89 , L_18 , V_90 ) ;
V_76 = & V_54 -> V_82 ;
if ( ! V_54 )
return 0 ;
V_188 = & V_54 -> V_223 ;
for ( V_55 = 0 ; V_55 < V_76 -> V_138 ; V_55 ++ ) {
struct V_91 * V_92 = V_76 -> V_95 [ V_55 ] ;
struct V_139 * V_140 = V_92 -> V_141 ( V_92 ) ;
if ( V_140 )
V_92 -> V_241 ( V_92 ) ;
}
V_69 = F_24 ( V_54 ) ;
if ( V_69 )
F_22 ( & V_54 -> V_88 -> V_89 ,
L_19 ) ;
F_39 ( V_54 ) ;
if ( V_76 -> V_83 == V_84 ) {
if ( ! V_54 -> V_242 )
F_55 ( V_54 ) ;
}
F_56 ( V_188 ) ;
if ( V_54 -> V_170 ) {
V_6 V_243 = 0 ;
V_243 = V_176 | V_157 |
V_156 | V_178 ;
F_57 ( F_28 , V_54 , V_243 ) ;
V_54 -> V_170 = 0 ;
F_58 ( V_188 ) ;
F_59 ( V_188 ) ;
}
if ( V_54 -> V_226 != 0 )
V_54 -> V_226 = 0 ;
V_54 -> V_244 -= 1 ;
V_219 -> V_222 = NULL ;
if ( V_54 -> V_206 )
F_56 ( V_188 ) ;
F_17 ( 1 , V_87 , & V_54 -> V_88 -> V_89 , L_17 , V_90 ) ;
return V_69 ;
}
static int F_60 ( struct V_219 * V_219 )
{
struct V_187 * V_188 ;
struct V_53 * V_54 = NULL ;
V_54 = F_61 ( V_219 ) ;
F_17 ( 1 , V_87 , & V_54 -> V_88 -> V_89 , L_18 , V_90 ) ;
if ( V_54 == NULL )
return - V_245 ;
if ( V_54 -> V_244 )
return - V_246 ;
V_54 -> V_244 += 1 ;
V_219 -> V_222 = V_54 ;
V_54 -> type = V_198 ;
V_188 = & V_54 -> V_223 ;
V_247 . V_248 = F_34 ;
V_247 . V_249 = F_40 ;
V_247 . V_250 = F_46 ;
V_247 . V_251 = F_44 ;
F_62 ( & V_54 -> V_171 ) ;
F_63 ( V_188 , & V_247 , V_188 -> V_216 ,
& V_54 -> V_171 , V_54 -> type , V_252 ,
sizeof( struct V_183 ) , V_54 , NULL ) ;
F_17 ( 1 , V_87 , & V_54 -> V_88 -> V_89 , L_17 , V_90 ) ;
return 0 ;
}
static int F_64 ( struct V_219 * V_219 , void * V_253 ,
struct V_254 * V_255 )
{
struct V_53 * V_54 = V_253 ;
F_65 ( V_255 -> V_256 , V_257 , sizeof( V_255 -> V_256 ) ) ;
F_65 ( V_255 -> V_258 , V_54 -> V_259 -> V_260 , sizeof( V_255 -> V_258 ) ) ;
V_255 -> V_261 [ 0 ] = '\0' ;
V_255 -> V_262 = V_263 | V_264 |
V_265 ;
return 0 ;
}
static int F_66 ( struct V_219 * V_219 , void * V_253 ,
struct V_266 * V_267 )
{
int V_268 = V_267 -> V_268 ;
if ( V_268 >= V_12 )
return - V_74 ;
V_267 -> V_269 = V_14 [ V_268 ] . V_269 ;
F_65 ( V_267 -> V_270 , V_14 [ V_268 ] . V_270 ,
sizeof( V_267 -> V_270 ) ) ;
V_267 -> V_13 = V_14 [ V_268 ] . V_13 ;
return 0 ;
}
static int F_67 ( struct V_219 * V_219 , void * V_253 ,
struct V_271 * V_272 )
{
struct V_53 * V_54 = V_253 ;
V_272 -> V_267 . V_2 = V_54 -> V_2 ;
return 0 ;
}
static int F_68 ( struct V_219 * V_219 , void * V_253 ,
struct V_271 * V_272 )
{
struct V_91 * V_92 ;
struct V_75 * V_76 ;
struct V_136 * V_137 ;
struct V_53 * V_54 = V_253 ;
struct V_139 * V_140 ;
V_76 = & V_54 -> V_82 ;
V_92 = V_76 -> V_95 [ 0 ] ;
V_140 = V_92 -> V_141 ( V_92 ) ;
if ( ! V_140 )
return - V_74 ;
V_137 = & V_140 -> V_142 . V_143 ;
V_54 -> V_273 . V_267 . V_5 = V_137 -> V_145 ;
V_54 -> V_273 . V_267 . V_9 = V_137 -> V_146 ;
F_1 ( & V_272 -> V_267 . V_2 ) ;
return 0 ;
}
static int F_69 ( struct V_219 * V_219 , void * V_253 ,
struct V_271 * V_272 )
{
int V_69 , V_4 ;
struct V_91 * V_92 ;
struct V_75 * V_76 ;
struct V_136 * V_137 ;
struct V_53 * V_54 = V_253 ;
struct V_139 * V_140 ;
if ( V_54 -> V_170 )
return - V_246 ;
F_70 ( & V_54 -> V_274 ) ;
V_76 = & V_54 -> V_82 ;
V_92 = V_76 -> V_95 [ 0 ] ;
V_140 = V_92 -> V_141 ( V_92 ) ;
if ( ! V_140 ) {
V_69 = - V_74 ;
goto V_275;
}
V_137 = & V_140 -> V_142 . V_143 ;
if ( ( F_21 ( V_54 ) ) &&
V_272 -> V_267 . V_2 . V_13 == V_27 ) {
V_69 = - V_74 ;
goto V_275;
}
if ( F_20 ( V_54 ) ) {
V_54 -> V_273 . V_267 . V_5 = V_137 -> V_146 ;
V_54 -> V_273 . V_267 . V_9 = V_137 -> V_145 ;
} else {
V_54 -> V_273 . V_267 . V_5 = V_137 -> V_145 ;
V_54 -> V_273 . V_267 . V_9 = V_137 -> V_146 ;
}
V_4 = F_1 ( & V_272 -> V_267 . V_2 ) ;
V_272 -> V_267 . V_2 . V_33 = V_272 -> V_267 . V_2 . V_9 * V_272 -> V_267 . V_2 . V_5 * V_4 ;
V_54 -> V_4 = V_4 ;
V_54 -> V_2 = V_272 -> V_267 . V_2 ;
V_54 -> V_276 = 1 ;
if ( V_18 == V_54 -> V_2 . V_13 ||
V_19 == V_54 -> V_2 . V_13 )
V_54 -> V_276 = 2 ;
F_71 ( & V_54 -> V_2 , & V_54 -> V_273 , & V_54 -> V_78 , & V_54 -> V_128 ) ;
V_69 = 0 ;
V_275:
F_72 ( & V_54 -> V_274 ) ;
return V_69 ;
}
static int F_73 ( struct V_219 * V_219 , void * V_253 ,
struct V_271 * V_272 )
{
int V_69 = 0 ;
struct V_53 * V_54 = V_253 ;
struct V_91 * V_92 ;
struct V_75 * V_76 ;
struct V_134 * V_128 = & V_272 -> V_267 . V_128 ;
V_76 = & V_54 -> V_82 ;
V_92 = V_76 -> V_95 [ 0 ] ;
V_69 = F_74 ( & V_54 -> V_273 , V_128 ) ;
if ( ! V_69 ) {
if ( ( V_92 -> V_116 & V_277 ) == 0 )
V_128 -> V_127 = 255 ;
else
V_128 -> V_127 = V_272 -> V_267 . V_128 . V_127 ;
}
return V_69 ;
}
static int F_75 ( struct V_219 * V_219 , void * V_253 ,
struct V_271 * V_272 )
{
int V_69 = 0 ;
struct V_91 * V_92 ;
struct V_75 * V_76 ;
struct V_53 * V_54 = V_253 ;
struct V_134 * V_128 = & V_272 -> V_267 . V_128 ;
F_70 ( & V_54 -> V_274 ) ;
V_76 = & V_54 -> V_82 ;
V_92 = V_76 -> V_95 [ 0 ] ;
V_69 = F_76 ( & V_54 -> V_78 , & V_54 -> V_128 , & V_54 -> V_273 , V_128 ) ;
if ( ! V_69 ) {
if ( ( V_92 -> V_116 & V_277 ) == 0 )
V_54 -> V_128 . V_127 = 255 ;
else
V_54 -> V_128 . V_127 = V_272 -> V_267 . V_128 . V_127 ;
V_54 -> V_128 . V_278 = V_272 -> V_267 . V_128 . V_278 ;
}
F_72 ( & V_54 -> V_274 ) ;
return V_69 ;
}
static int F_77 ( struct V_219 * V_219 , void * V_253 ,
struct V_271 * V_272 )
{
V_6 V_279 = 0 ;
struct V_91 * V_92 ;
struct V_75 * V_76 ;
struct V_53 * V_54 = V_253 ;
struct V_280 V_111 ;
struct V_134 * V_128 = & V_272 -> V_267 . V_128 ;
V_76 = & V_54 -> V_82 ;
V_92 = V_76 -> V_95 [ 0 ] ;
V_128 -> V_144 = V_54 -> V_128 . V_144 ;
V_128 -> V_15 = V_54 -> V_128 . V_15 ;
V_128 -> V_127 = V_54 -> V_128 . V_127 ;
if ( V_92 -> V_148 && V_92 -> V_148 -> V_281 ) {
V_92 -> V_148 -> V_281 ( V_92 -> V_148 , & V_111 ) ;
V_279 = V_111 . V_282 ;
}
V_128 -> V_278 = V_279 ;
return 0 ;
}
static int F_78 ( struct V_219 * V_219 , void * V_253 ,
struct V_283 * V_284 )
{
struct V_53 * V_54 = V_253 ;
struct V_1 * V_2 = & V_54 -> V_2 ;
if ( V_284 -> type != V_198 )
return - V_74 ;
V_284 -> V_285 . V_9 = V_2 -> V_9 & ~ 1 ;
V_284 -> V_285 . V_5 = V_2 -> V_5 & ~ 1 ;
F_79 ( & V_54 -> V_2 , & V_54 -> V_273 , & V_284 -> V_286 ) ;
V_284 -> V_287 . V_288 = 1 ;
V_284 -> V_287 . V_289 = 1 ;
return 0 ;
}
static int F_80 ( struct V_219 * V_219 , void * V_253 , struct V_290 * V_78 )
{
struct V_53 * V_54 = V_253 ;
if ( V_78 -> type != V_198 )
return - V_74 ;
V_78 -> V_291 = V_54 -> V_78 ;
return 0 ;
}
static int F_81 ( struct V_219 * V_219 , void * V_253 , const struct V_290 * V_78 )
{
int V_69 = - V_74 ;
struct V_53 * V_54 = V_253 ;
struct V_75 * V_76 ;
struct V_91 * V_92 ;
struct V_136 * V_137 ;
struct V_139 * V_140 ;
if ( V_54 -> V_170 )
return - V_246 ;
F_70 ( & V_54 -> V_274 ) ;
V_76 = & V_54 -> V_82 ;
V_92 = V_76 -> V_95 [ 0 ] ;
V_140 = V_92 -> V_141 ( V_92 ) ;
if ( ! V_140 ) {
V_69 = - V_74 ;
goto V_292;
}
V_137 = & V_140 -> V_142 . V_143 ;
if ( F_20 ( V_54 ) ) {
V_54 -> V_273 . V_267 . V_5 = V_137 -> V_146 ;
V_54 -> V_273 . V_267 . V_9 = V_137 -> V_145 ;
} else {
V_54 -> V_273 . V_267 . V_5 = V_137 -> V_145 ;
V_54 -> V_273 . V_267 . V_9 = V_137 -> V_146 ;
}
if ( V_78 -> type == V_198 )
V_69 = F_82 ( & V_54 -> V_2 , & V_54 -> V_78 , & V_54 -> V_128 ,
& V_54 -> V_273 , & V_78 -> V_291 ) ;
V_292:
F_72 ( & V_54 -> V_274 ) ;
return V_69 ;
}
static int F_83 ( struct V_219 * V_219 , void * V_253 ,
struct V_293 * V_294 )
{
int V_69 = 0 ;
switch ( V_294 -> V_100 ) {
case V_295 :
V_69 = F_84 ( V_294 , 0 , 270 , 90 , 0 ) ;
break;
case V_296 :
V_69 = F_84 ( V_294 , 0 , 0xFFFFFF , 1 , 0 ) ;
break;
case V_297 :
V_69 = F_84 ( V_294 , 0 , 1 , 1 , 0 ) ;
break;
default:
V_294 -> V_260 [ 0 ] = '\0' ;
V_69 = - V_74 ;
}
return V_69 ;
}
static int F_85 ( struct V_219 * V_219 , void * V_253 , struct V_298 * V_294 )
{
int V_69 = 0 ;
struct V_53 * V_54 = V_253 ;
switch ( V_294 -> V_100 ) {
case V_295 :
V_294 -> V_299 = V_54 -> V_300 [ 0 ] . V_299 ;
break;
case V_296 :
{
struct V_280 V_111 ;
struct V_91 * V_92 ;
V_92 = V_54 -> V_82 . V_95 [ 0 ] ;
if ( ! V_92 -> V_148 || ! V_92 -> V_148 -> V_281 ) {
V_69 = - V_74 ;
break;
}
V_92 -> V_148 -> V_281 ( V_92 -> V_148 , & V_111 ) ;
V_294 -> V_299 = V_111 . V_301 ;
break;
}
case V_297 :
V_294 -> V_299 = V_54 -> V_300 [ 2 ] . V_299 ;
break;
default:
V_69 = - V_74 ;
}
return V_69 ;
}
static int F_86 ( struct V_219 * V_219 , void * V_253 , struct V_298 * V_302 )
{
int V_69 = 0 ;
struct V_53 * V_54 = V_253 ;
switch ( V_302 -> V_100 ) {
case V_295 :
{
struct V_75 * V_76 ;
int V_67 = V_302 -> V_299 ;
V_76 = & V_54 -> V_82 ;
F_70 ( & V_54 -> V_274 ) ;
if ( V_67 && V_76 -> V_83 == V_202 ) {
F_72 ( & V_54 -> V_274 ) ;
V_69 = - V_303 ;
break;
}
if ( V_67 && V_54 -> V_2 . V_13 == V_27 ) {
F_72 ( & V_54 -> V_274 ) ;
V_69 = - V_74 ;
break;
}
if ( F_14 ( V_67 , & V_54 -> V_67 ,
V_54 -> V_68 ) ) {
F_72 ( & V_54 -> V_274 ) ;
V_69 = - V_74 ;
break;
}
V_54 -> V_300 [ 0 ] . V_299 = V_67 ;
F_72 ( & V_54 -> V_274 ) ;
break;
}
case V_296 :
{
struct V_91 * V_92 ;
unsigned int V_304 = V_302 -> V_299 ;
struct V_280 V_111 ;
V_92 = V_54 -> V_82 . V_95 [ 0 ] ;
F_70 ( & V_54 -> V_274 ) ;
if ( ! V_92 -> V_148 || ! V_92 -> V_148 -> V_281 ) {
F_72 ( & V_54 -> V_274 ) ;
V_69 = - V_74 ;
break;
}
V_92 -> V_148 -> V_281 ( V_92 -> V_148 , & V_111 ) ;
V_111 . V_301 = V_304 ;
if ( V_92 -> V_148 -> V_305 ( V_92 -> V_148 , & V_111 ) ) {
F_72 ( & V_54 -> V_274 ) ;
V_69 = - V_74 ;
break;
}
V_54 -> V_300 [ 1 ] . V_299 = V_304 ;
F_72 ( & V_54 -> V_274 ) ;
break;
}
case V_297 :
{
struct V_91 * V_92 ;
struct V_75 * V_76 ;
unsigned int V_68 = V_302 -> V_299 ;
V_76 = & V_54 -> V_82 ;
V_92 = V_76 -> V_95 [ 0 ] ;
F_70 ( & V_54 -> V_274 ) ;
if ( V_68 && V_76 -> V_83 == V_202 ) {
F_72 ( & V_54 -> V_274 ) ;
V_69 = - V_303 ;
break;
}
if ( V_68 && V_54 -> V_2 . V_13 == V_27 ) {
F_72 ( & V_54 -> V_274 ) ;
V_69 = - V_74 ;
break;
}
V_54 -> V_68 = V_68 ;
V_54 -> V_300 [ 2 ] . V_299 = V_68 ;
F_72 ( & V_54 -> V_274 ) ;
break;
}
default:
V_69 = - V_74 ;
}
return V_69 ;
}
static int F_87 ( struct V_219 * V_219 , void * V_253 ,
struct V_306 * V_307 )
{
int V_69 = 0 ;
unsigned int V_55 , V_207 = 0 ;
struct V_53 * V_54 = V_253 ;
struct V_187 * V_188 = & V_54 -> V_223 ;
if ( ( V_307 -> type != V_198 ) || ( V_307 -> V_189 < 0 ) )
return - V_74 ;
if ( ( V_199 != V_307 -> V_200 ) &&
( V_212 != V_307 -> V_200 ) )
return - V_74 ;
F_70 ( & V_54 -> V_274 ) ;
if ( V_54 -> V_170 ) {
V_69 = - V_246 ;
goto V_308;
}
if ( V_188 -> V_230 [ 0 ] && ( V_199 == V_188 -> V_230 [ 0 ] -> V_200 ) ) {
if ( V_54 -> V_226 ) {
V_69 = - V_246 ;
goto V_308;
}
V_207 = ( V_54 -> V_57 == V_197 ) ?
V_59 : V_58 ;
for ( V_55 = V_207 ; V_55 < V_54 -> V_206 ; V_55 ++ ) {
F_13 ( V_54 -> V_63 [ V_55 ] ,
V_54 -> V_60 ) ;
V_54 -> V_63 [ V_55 ] = 0 ;
V_54 -> V_64 [ V_55 ] = 0 ;
}
V_54 -> V_206 = V_207 ;
F_56 ( V_188 ) ;
} else if ( V_188 -> V_230 [ 0 ] && ( V_212 == V_188 -> V_230 [ 0 ] -> V_200 ) ) {
if ( V_54 -> V_206 ) {
F_56 ( V_188 ) ;
for ( V_55 = 0 ; V_55 < V_54 -> V_206 ; V_55 ++ ) {
F_88 ( V_188 -> V_230 [ V_55 ] ) ;
V_188 -> V_230 [ V_55 ] = NULL ;
}
V_54 -> V_206 = 0 ;
}
}
V_54 -> V_200 = V_307 -> V_200 ;
F_89 ( & V_54 -> V_165 ) ;
V_69 = F_90 ( V_188 , V_307 ) ;
if ( V_69 < 0 )
goto V_308;
V_54 -> V_206 = V_307 -> V_189 ;
V_308:
F_72 ( & V_54 -> V_274 ) ;
return V_69 ;
}
static int F_91 ( struct V_219 * V_219 , void * V_253 ,
struct V_309 * V_310 )
{
struct V_53 * V_54 = V_253 ;
return F_92 ( & V_54 -> V_223 , V_310 ) ;
}
static int F_93 ( struct V_219 * V_219 , void * V_253 ,
struct V_309 * V_311 )
{
struct V_53 * V_54 = V_253 ;
struct V_187 * V_188 = & V_54 -> V_223 ;
if ( ( V_198 != V_311 -> type ) ||
( V_311 -> V_268 >= V_54 -> V_206 ) ||
( V_188 -> V_230 [ V_311 -> V_268 ] -> V_200 != V_311 -> V_200 ) ) {
return - V_74 ;
}
if ( V_212 == V_311 -> V_200 ) {
if ( ( V_311 -> V_312 < V_54 -> V_2 . V_33 ) ||
( 0 == V_311 -> V_313 . V_314 ) ) {
return - V_74 ;
}
}
if ( ( F_21 ( V_54 ) ) &&
V_54 -> V_315 . V_316 == V_317 ) {
F_22 ( & V_54 -> V_88 -> V_89 ,
L_20 ) ;
return - V_74 ;
}
return F_94 ( V_188 , V_311 ) ;
}
static int F_95 ( struct V_219 * V_219 , void * V_253 , struct V_309 * V_310 )
{
struct V_53 * V_54 = V_253 ;
struct V_187 * V_188 = & V_54 -> V_223 ;
int V_69 ;
V_6 V_109 ;
unsigned long V_190 ;
struct V_183 * V_208 ;
V_208 = V_188 -> V_230 [ V_310 -> V_268 ] ;
if ( ! V_54 -> V_170 )
return - V_74 ;
if ( V_219 -> V_318 & V_319 )
V_69 = F_96 ( V_188 , (struct V_309 * ) V_310 , 1 ) ;
else
V_69 = F_96 ( V_188 , (struct V_309 * ) V_310 , 0 ) ;
V_109 = ( unsigned long ) V_54 -> V_64 [ V_208 -> V_55 ] ;
V_190 = ( unsigned long ) V_208 -> V_190 ;
F_97 ( V_54 -> V_88 -> V_89 . V_216 , V_109 ,
V_190 , V_217 ) ;
return V_69 ;
}
static int F_98 ( struct V_219 * V_219 , void * V_253 , enum V_320 V_55 )
{
int V_69 = 0 , V_192 ;
V_6 V_109 = 0 , V_243 = 0 ;
struct V_53 * V_54 = V_253 ;
struct V_187 * V_188 = & V_54 -> V_223 ;
struct V_75 * V_76 = & V_54 -> V_82 ;
F_70 ( & V_54 -> V_274 ) ;
if ( V_54 -> V_170 ) {
V_69 = - V_246 ;
goto V_321;
}
V_69 = F_99 ( V_188 ) ;
if ( V_69 )
goto V_321;
if ( F_27 ( & V_54 -> V_165 ) ) {
V_69 = - V_322 ;
goto V_323;
}
V_54 -> V_160 = V_54 -> V_159 = F_31 ( V_54 -> V_165 . V_182 ,
struct V_183 , V_184 ) ;
F_32 ( & V_54 -> V_159 -> V_184 ) ;
V_54 -> V_159 -> V_162 = V_185 ;
V_54 -> V_158 = 0 ;
V_54 -> V_170 = 1 ;
V_54 -> V_154 = 1 ;
if ( F_15 ( V_54 ) ) {
V_69 = - V_74 ;
goto V_323;
}
V_109 = ( unsigned long ) V_54 -> V_186 [ V_54 -> V_159 -> V_55 ]
+ V_54 -> V_79 ;
V_243 = V_176 | V_157 | V_156
| V_178 ;
V_69 = F_23 ( V_54 , V_109 ) ;
if ( V_69 ) {
F_37 ( & V_54 -> V_88 -> V_89 ,
L_8 ) ;
goto V_323;
}
F_100 ( F_28 , V_54 , V_243 ) ;
V_69 = F_24 ( V_54 ) ;
if ( V_69 )
F_37 ( & V_54 -> V_88 -> V_89 , L_9 ) ;
for ( V_192 = 0 ; V_192 < V_76 -> V_138 ; V_192 ++ ) {
struct V_91 * V_92 = V_76 -> V_95 [ V_192 ] ;
struct V_139 * V_140 = V_92 -> V_141 ( V_92 ) ;
if ( V_140 ) {
V_69 = V_92 -> V_324 ( V_92 ) ;
if ( V_69 )
goto V_323;
}
}
V_69 = 0 ;
V_323:
if ( V_69 )
V_69 = F_58 ( V_188 ) ;
V_321:
F_72 ( & V_54 -> V_274 ) ;
return V_69 ;
}
static int F_101 ( struct V_219 * V_219 , void * V_253 , enum V_320 V_55 )
{
V_6 V_243 = 0 ;
int V_69 = 0 , V_192 ;
struct V_53 * V_54 = V_253 ;
struct V_75 * V_76 = & V_54 -> V_82 ;
if ( ! V_54 -> V_170 )
return - V_74 ;
V_54 -> V_170 = 0 ;
V_243 = V_176 | V_157 | V_156
| V_178 ;
F_57 ( F_28 , V_54 , V_243 ) ;
for ( V_192 = 0 ; V_192 < V_76 -> V_138 ; V_192 ++ ) {
struct V_91 * V_92 = V_76 -> V_95 [ V_192 ] ;
struct V_139 * V_140 = V_92 -> V_141 ( V_92 ) ;
if ( V_140 )
V_92 -> V_241 ( V_92 ) ;
}
V_69 = F_24 ( V_54 ) ;
if ( V_69 )
F_37 ( & V_54 -> V_88 -> V_89 , L_21
L_22 ) ;
F_89 ( & V_54 -> V_165 ) ;
V_69 = F_58 ( & V_54 -> V_223 ) ;
return V_69 ;
}
static int F_102 ( struct V_219 * V_219 , void * V_253 ,
const struct V_325 * V_302 )
{
int V_324 = 0 ;
struct V_91 * V_92 ;
struct V_75 * V_76 ;
struct V_53 * V_54 = V_253 ;
struct V_280 V_111 ;
enum V_326 V_327 = V_328 ;
V_76 = & V_54 -> V_82 ;
V_92 = V_76 -> V_95 [ 0 ] ;
if ( ( V_302 -> V_269 & V_329 ) &&
( V_302 -> V_269 & V_330 ) )
return - V_74 ;
if ( ( V_302 -> V_269 & V_330 ) &&
( V_302 -> V_269 & V_331 ) )
return - V_74 ;
if ( ( V_302 -> V_269 & V_329 ) ) {
V_54 -> V_273 . V_269 |= V_329 ;
V_327 = V_332 ;
} else
V_54 -> V_273 . V_269 &= ~ V_329 ;
if ( ( V_302 -> V_269 & V_330 ) ) {
V_54 -> V_273 . V_269 |= V_330 ;
V_327 = V_328 ;
} else
V_54 -> V_273 . V_269 &= ~ V_330 ;
if ( V_302 -> V_269 & ( V_330 |
V_329 ) )
V_324 = 1 ;
else
V_324 = 0 ;
if ( V_92 -> V_148 && V_92 -> V_148 -> V_281 &&
V_92 -> V_148 -> V_305 ) {
V_92 -> V_148 -> V_281 ( V_92 -> V_148 , & V_111 ) ;
V_111 . V_333 = V_324 ;
V_111 . V_334 = V_327 ;
V_111 . V_282 = V_54 -> V_128 . V_278 ;
if ( V_92 -> V_148 -> V_305 ( V_92 -> V_148 , & V_111 ) )
return - V_74 ;
}
if ( V_302 -> V_269 & V_331 ) {
V_54 -> V_273 . V_269 |= V_331 ;
V_324 = 1 ;
} else {
V_54 -> V_273 . V_269 &= ~ V_331 ;
V_324 = 0 ;
}
if ( V_92 -> V_148 && V_92 -> V_148 -> V_281 &&
V_92 -> V_148 -> V_305 ) {
V_92 -> V_148 -> V_281 ( V_92 -> V_148 , & V_111 ) ;
if ( ( V_92 -> V_116 & V_335 ) == 0 )
V_111 . V_336 = V_324 ;
if ( V_92 -> V_148 -> V_305 ( V_92 -> V_148 , & V_111 ) )
return - V_74 ;
}
return 0 ;
}
static int F_103 ( struct V_219 * V_219 , void * V_253 ,
struct V_325 * V_302 )
{
struct V_91 * V_92 ;
struct V_75 * V_76 ;
struct V_53 * V_54 = V_253 ;
struct V_280 V_111 ;
V_76 = & V_54 -> V_82 ;
V_92 = V_76 -> V_95 [ 0 ] ;
V_302 -> V_269 = V_337 ;
V_302 -> V_338 = V_339 | V_340
| V_341 ;
if ( V_92 -> V_148 && V_92 -> V_148 -> V_281 ) {
V_92 -> V_148 -> V_281 ( V_92 -> V_148 , & V_111 ) ;
if ( V_111 . V_334 == V_332 )
V_302 -> V_269 |= V_329 ;
if ( V_111 . V_334 == V_328 )
V_302 -> V_269 |= V_330 ;
}
if ( V_92 -> V_148 && V_92 -> V_148 -> V_281 ) {
V_92 -> V_148 -> V_281 ( V_92 -> V_148 , & V_111 ) ;
if ( V_111 . V_336 )
V_302 -> V_269 |= V_331 ;
}
return 0 ;
}
static int T_1 F_104 ( struct V_53 * V_54 )
{
struct V_342 * V_259 ;
struct V_1 * V_2 ;
struct V_298 * V_300 ;
struct V_91 * V_92 = V_54 -> V_82 . V_95 [ 0 ] ;
struct V_139 * V_343 = V_92 -> V_141 ( V_92 ) ;
V_2 = & V_54 -> V_2 ;
V_2 -> V_9 = V_344 ;
V_2 -> V_5 = V_345 ;
V_2 -> V_13 = V_23 ;
V_2 -> V_15 = V_16 ;
V_2 -> V_32 = V_2 -> V_9 * 2 ;
V_2 -> V_33 = V_2 -> V_32 * V_2 -> V_5 ;
V_2 -> V_17 = 0 ;
V_2 -> V_20 = V_21 ;
V_54 -> V_4 = V_26 ;
V_54 -> V_273 . V_267 . V_9 = V_343 -> V_142 . V_143 . V_146 ;
V_54 -> V_273 . V_267 . V_5 = V_343 -> V_142 . V_143 . V_145 ;
V_54 -> V_128 . V_127 = 255 ;
V_54 -> V_273 . V_269 = 0 ;
V_54 -> V_273 . V_338 = V_339 |
V_341 | V_340 ;
V_54 -> V_128 . V_278 = 0 ;
F_71 ( V_2 , & V_54 -> V_273 , & V_54 -> V_78 , & V_54 -> V_128 ) ;
V_300 = V_54 -> V_300 ;
V_300 [ 0 ] . V_100 = V_295 ;
V_300 [ 0 ] . V_299 = 0 ;
V_54 -> V_67 = 0 ;
V_54 -> V_68 = 0 ;
V_54 -> V_300 [ 2 ] . V_100 = V_346 ;
V_54 -> V_300 [ 2 ] . V_299 = 0 ;
if ( V_54 -> V_82 . V_83 == V_84 )
V_54 -> V_276 = 2 ;
V_300 [ 1 ] . V_100 = V_296 ;
V_300 [ 1 ] . V_299 = 0 ;
V_259 = V_54 -> V_259 = F_105 () ;
if ( ! V_259 ) {
F_11 (KERN_ERR VOUT_NAME L_23
L_24 ) ;
return - V_201 ;
}
V_259 -> V_347 = V_348 ;
V_259 -> V_349 = & V_350 ;
F_65 ( V_259 -> V_260 , V_257 , sizeof( V_259 -> V_260 ) ) ;
V_259 -> V_351 = & V_352 ;
V_259 -> V_89 = & V_54 -> V_88 -> V_89 ;
V_259 -> V_353 = V_354 ;
F_106 ( & V_54 -> V_274 ) ;
V_259 -> V_355 = - 1 ;
return 0 ;
}
static int T_1 F_107 ( struct V_356 * V_357 ,
int V_358 )
{
V_6 V_56 ;
int V_69 = 0 , V_55 ;
struct V_75 * V_76 ;
struct V_53 * V_54 ;
struct V_359 * V_89 = F_108 ( V_357 ) ;
struct V_360 * V_88 =
F_109 ( V_89 , struct V_360 , V_89 ) ;
V_54 = V_88 -> V_361 [ V_358 ] ;
V_76 = & V_54 -> V_82 ;
V_56 = ( V_358 == 0 ) ? V_59 : V_58 ;
V_54 -> V_60 = ( V_358 == 0 ) ? V_62 : V_61 ;
F_110 ( & V_357 -> V_216 , L_25 , V_54 -> V_60 ) ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
V_54 -> V_63 [ V_55 ] =
F_38 ( V_54 -> V_60 ,
( V_6 * ) & V_54 -> V_64 [ V_55 ] ) ;
if ( ! V_54 -> V_63 [ V_55 ] ) {
V_56 = V_55 ;
V_69 = - V_201 ;
goto V_362;
}
}
V_54 -> V_79 = 0 ;
if ( V_76 -> V_83 == V_84 ) {
int V_363 = ( V_358 == 0 ) ?
V_364 : V_365 ;
V_69 = F_111 ( V_357 , V_358 ,
V_363 ) ;
}
return V_69 ;
V_362:
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
F_13 ( V_54 -> V_63 [ V_55 ] ,
V_54 -> V_60 ) ;
V_54 -> V_63 [ V_55 ] = 0 ;
V_54 -> V_64 [ V_55 ] = 0 ;
}
return V_69 ;
}
static int T_1 F_112 ( struct V_356 * V_357 )
{
int V_69 = 0 , V_366 ;
struct V_53 * V_54 ;
struct V_342 * V_259 = NULL ;
struct V_359 * V_89 = F_108 ( V_357 ) ;
struct V_360 * V_88 = F_109 ( V_89 ,
struct V_360 , V_89 ) ;
for ( V_366 = 0 ; V_366 < V_357 -> V_367 ; V_366 ++ ) {
V_54 = F_113 ( sizeof( struct V_53 ) , V_368 ) ;
if ( ! V_54 ) {
F_114 ( & V_357 -> V_216 , L_26 ) ;
return - V_201 ;
}
V_54 -> V_57 = V_366 ;
V_88 -> V_361 [ V_366 ] = V_54 ;
V_54 -> V_88 = V_88 ;
if ( V_357 -> V_367 == 1 )
V_54 -> V_82 . V_95 [ 0 ] = V_88 -> V_95 [ V_366 + 2 ] ;
else
V_54 -> V_82 . V_95 [ 0 ] = V_88 -> V_95 [ V_366 + 1 ] ;
V_54 -> V_82 . V_138 = 1 ;
V_54 -> V_82 . V_100 = V_366 + 1 ;
if ( F_115 () || F_116 () )
V_54 -> V_82 . V_83 = V_84 ;
if ( F_104 ( V_54 ) != 0 ) {
V_69 = - V_201 ;
goto error;
}
if ( F_107 ( V_357 , V_366 ) != 0 ) {
V_69 = - V_201 ;
goto V_369;
}
V_259 = V_54 -> V_259 ;
if ( F_117 ( V_259 , V_370 , - 1 ) < 0 ) {
F_114 ( & V_357 -> V_216 , L_27
L_28 ) ;
V_259 -> V_355 = - 1 ;
V_69 = - V_245 ;
goto V_371;
}
F_118 ( V_259 , V_54 ) ;
F_110 ( & V_357 -> V_216 , L_29
L_30 , V_259 -> V_355 ) ;
if ( V_366 == ( V_357 -> V_367 - 1 ) )
return 0 ;
continue;
V_371:
if ( V_54 -> V_82 . V_83 == V_84 )
F_119 ( V_54 ) ;
F_12 ( V_54 ) ;
V_369:
V_348 ( V_259 ) ;
error:
F_88 ( V_54 ) ;
return V_69 ;
}
return - V_245 ;
}
static void F_120 ( struct V_53 * V_54 )
{
struct V_342 * V_259 ;
struct V_75 * V_76 ;
if ( ! V_54 )
return;
V_259 = V_54 -> V_259 ;
V_76 = & V_54 -> V_82 ;
if ( V_259 ) {
if ( ! F_121 ( V_259 ) ) {
V_348 ( V_259 ) ;
} else {
F_122 ( V_259 ) ;
}
}
if ( V_76 -> V_83 == V_84 ) {
F_119 ( V_54 ) ;
if ( V_54 -> V_242 )
F_55 ( V_54 ) ;
}
F_12 ( V_54 ) ;
F_88 ( V_54 ) ;
}
static int F_123 ( struct V_356 * V_357 )
{
int V_366 ;
struct V_359 * V_89 = F_108 ( V_357 ) ;
struct V_360 * V_88 = F_109 ( V_89 , struct
V_360 , V_89 ) ;
F_124 ( V_89 ) ;
for ( V_366 = 0 ; V_366 < V_357 -> V_367 ; V_366 ++ )
F_120 ( V_88 -> V_361 [ V_366 ] ) ;
for ( V_366 = 0 ; V_366 < V_88 -> V_372 ; V_366 ++ ) {
if ( V_88 -> V_373 [ V_366 ] -> V_162 != V_374 )
V_88 -> V_373 [ V_366 ] -> V_256 -> V_241 ( V_88 -> V_373 [ V_366 ] ) ;
F_125 ( V_88 -> V_373 [ V_366 ] ) ;
}
F_88 ( V_88 ) ;
return 0 ;
}
static int T_1 F_126 ( struct V_356 * V_357 )
{
int V_69 = 0 , V_55 ;
struct V_91 * V_92 ;
struct V_139 * V_140 = NULL ;
struct V_139 * V_375 ;
struct V_360 * V_88 = NULL ;
if ( F_127 () == false )
return - V_376 ;
V_69 = F_128 () ;
if ( V_69 ) {
F_114 ( & V_357 -> V_216 , L_31 ) ;
return V_69 ;
}
if ( V_357 -> V_367 == 0 ) {
F_114 ( & V_357 -> V_216 , L_32 ) ;
V_69 = - V_245 ;
goto V_377;
}
V_88 = F_113 ( sizeof( struct V_360 ) , V_368 ) ;
if ( V_88 == NULL ) {
V_69 = - V_201 ;
goto V_377;
}
V_88 -> V_372 = 0 ;
F_129 (dssdev) {
F_130 ( V_140 ) ;
if ( ! V_140 -> V_256 ) {
F_131 ( & V_357 -> V_216 , L_33 ,
V_140 -> V_260 ) ;
F_125 ( V_140 ) ;
continue;
}
V_88 -> V_373 [ V_88 -> V_372 ++ ] = V_140 ;
}
if ( V_88 -> V_372 == 0 ) {
F_114 ( & V_357 -> V_216 , L_34 ) ;
V_69 = - V_74 ;
goto V_378;
}
V_88 -> V_138 = F_132 () ;
for ( V_55 = 0 ; V_55 < V_88 -> V_138 ; V_55 ++ )
V_88 -> V_95 [ V_55 ] = F_133 ( V_55 ) ;
V_88 -> V_379 = F_134 () ;
for ( V_55 = 0 ; V_55 < V_88 -> V_379 ; V_55 ++ )
V_88 -> V_380 [ V_55 ] = F_135 ( V_55 ) ;
for ( V_55 = 1 ; V_55 < V_88 -> V_138 ; V_55 ++ ) {
V_92 = F_133 ( V_55 ) ;
V_140 = V_92 -> V_141 ( V_92 ) ;
if ( V_140 ) {
V_375 = V_140 ;
} else {
F_131 ( & V_357 -> V_216 , L_35 ) ;
V_375 = NULL ;
}
if ( V_375 ) {
struct V_381 * V_382 = V_375 -> V_256 ;
V_69 = V_382 -> V_324 ( V_375 ) ;
if ( V_69 ) {
F_131 ( & V_357 -> V_216 ,
L_36 ,
V_375 -> V_260 ) ;
}
}
}
if ( F_136 ( & V_357 -> V_216 , & V_88 -> V_89 ) < 0 ) {
F_114 ( & V_357 -> V_216 , L_37 ) ;
V_69 = - V_245 ;
goto V_383;
}
V_69 = F_112 ( V_357 ) ;
if ( V_69 )
goto V_384;
for ( V_55 = 0 ; V_55 < V_88 -> V_372 ; V_55 ++ ) {
struct V_139 * V_343 = V_88 -> V_373 [ V_55 ] ;
if ( V_343 -> V_256 -> V_385 )
V_343 -> V_256 -> V_385 ( V_343 , 0 , 0 ,
V_343 -> V_142 . V_143 . V_146 ,
V_343 -> V_142 . V_143 . V_145 ) ;
}
return 0 ;
V_384:
F_124 ( & V_88 -> V_89 ) ;
V_383:
for ( V_55 = 1 ; V_55 < V_88 -> V_138 ; V_55 ++ ) {
V_375 = NULL ;
V_92 = F_133 ( V_55 ) ;
V_140 = V_92 -> V_141 ( V_92 ) ;
if ( V_140 )
V_375 = V_140 ;
if ( V_375 && V_375 -> V_256 )
V_375 -> V_256 -> V_241 ( V_375 ) ;
}
V_378:
F_88 ( V_88 ) ;
V_377:
F_137 () ;
return V_69 ;
}
static int T_1 F_138 ( void )
{
if ( F_139 ( & V_386 , F_126 ) != 0 ) {
F_11 (KERN_ERR VOUT_NAME L_38 ) ;
return - V_74 ;
}
return 0 ;
}
static void F_140 ( void )
{
F_141 ( & V_386 ) ;
}
