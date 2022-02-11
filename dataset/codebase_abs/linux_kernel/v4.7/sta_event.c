void
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( ! V_2 -> V_6 )
return;
F_2 ( V_5 , V_7 ,
L_1 ) ;
V_2 -> V_6 = false ;
V_2 -> V_8 = false ;
V_2 -> V_9 = false ;
if ( ( F_3 ( V_2 ) == V_10 ) &&
F_4 ( V_2 -> V_5 -> V_11 ) ) {
F_5 ( V_2 ) ;
if ( V_2 -> V_5 -> V_12 )
F_6 ( V_2 ) ;
}
F_7 ( V_2 ) ;
V_2 -> V_13 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_21 = 0 ;
V_2 -> V_22 = 0 ;
V_2 -> V_23 . V_24 = false ;
V_2 -> V_23 . V_25 = false ;
V_2 -> V_26 = 0 ;
V_2 -> V_23 . V_27 = false ;
V_2 -> V_28 = 0 ;
V_2 -> V_23 . V_29 = false ;
V_2 -> V_23 . V_30 = 0 ;
V_2 -> V_31 = true ;
V_2 -> V_32 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_34 = false ;
if ( ( F_3 ( V_2 ) == V_10 ||
F_3 ( V_2 ) == V_35 ) && V_2 -> V_36 )
F_8 ( V_2 ) ;
if ( V_2 -> V_37 == V_38 ) {
V_2 -> V_39 = V_40 ;
V_2 -> V_41 = false ;
}
F_2 ( V_5 , V_7 ,
L_2 ,
V_2 -> V_42 . V_43 , V_2 -> V_42 . V_44 ) ;
F_2 ( V_5 , V_7 ,
L_3 ,
V_2 -> V_45 . V_46 . V_43 . V_43 ,
V_2 -> V_45 . V_46 . V_43 . V_44 ) ;
memcpy ( & V_2 -> V_42 ,
& V_2 -> V_45 . V_46 . V_43 ,
sizeof( struct V_47 ) ) ;
memcpy ( V_2 -> V_48 ,
V_2 -> V_45 . V_46 . V_49 , V_50 ) ;
memset ( & V_2 -> V_45 , 0x00 , sizeof( V_2 -> V_45 ) ) ;
V_5 -> V_51 = false ;
V_5 -> V_52 = false ;
if ( V_5 -> V_53 && V_5 -> V_54 )
return;
V_2 -> V_6 = false ;
F_2 ( V_5 , V_55 ,
L_4 ,
V_2 -> V_56 , V_3 ) ;
if ( V_2 -> V_37 == V_57 ||
V_2 -> V_37 == V_58 ) {
F_9 ( V_2 -> V_59 , V_3 , NULL , 0 ,
false , V_60 ) ;
}
F_10 ( V_2 -> V_56 ) ;
F_11 ( V_2 -> V_59 , V_5 ) ;
if ( F_12 ( V_2 -> V_59 ) )
F_13 ( V_2 -> V_59 ) ;
F_14 ( V_2 , V_61 ,
V_62 , 0 , NULL , false ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
int V_65 = 0 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_66 * V_67 ;
struct V_68 * V_69 =
( void * ) V_64 -> V_70 + sizeof( V_5 -> V_71 ) ;
T_2 * V_72 = V_69 -> V_73 ;
if ( V_64 -> V_74 < ( sizeof( struct V_68 ) -
sizeof( T_1 ) - sizeof( V_5 -> V_71 ) ) ) {
F_2 ( V_5 , ERROR , L_5 ) ;
return - 1 ;
}
V_67 = F_16 ( V_2 , V_69 -> V_73 ) ;
if ( ! V_67 ) {
F_2 ( V_5 , ERROR , L_6 ) ;
return - 1 ;
}
switch ( F_17 ( V_69 -> type ) ) {
case V_75 :
F_18 ( V_2 -> V_59 ,
V_69 -> V_73 ,
V_76 ,
F_17 ( V_69 -> V_77 . V_3 ) ,
V_60 ) ;
break;
case V_78 :
F_2 ( V_5 , V_79 , L_7 ) ;
F_2 ( V_5 , V_79 ,
L_8 ,
V_69 -> V_77 . V_80 . V_81 ,
V_69 -> V_77 . V_80 . V_82 ,
V_69 -> V_77 . V_80 . V_83 ) ;
if ( V_69 -> V_77 . V_80 . V_81 != 0 ) {
switch ( V_69 -> V_77 . V_80 . V_83 ) {
case V_84 :
V_67 -> V_85 = V_86 ;
break;
case V_87 :
V_67 -> V_85 = V_88 ;
break;
default:
break;
}
return V_65 ;
}
switch ( V_69 -> V_77 . V_80 . V_83 ) {
case V_84 :
if ( V_67 -> V_85 == V_86 )
break;
F_19 ( V_2 , V_72 ,
false ) ;
V_67 -> V_85 = V_86 ;
break;
case V_87 :
if ( V_67 -> V_85 == V_88 )
break;
F_19 ( V_2 , V_72 ,
true ) ;
V_67 -> V_85 = V_88 ;
break;
default:
break;
}
break;
case V_89 :
F_2 ( V_5 , V_79 , L_9 ) ;
V_67 -> V_85 = V_90 ;
break;
case V_91 :
F_2 ( V_5 , V_79 ,
L_10 ,
V_69 -> V_77 . V_92 ) ;
break;
default:
break;
}
return V_65 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
struct V_95 * V_96 ;
struct V_66 * V_67 ;
unsigned long V_97 ;
V_96 = ( void * ) V_94 ;
F_2 ( V_2 -> V_5 , V_79 ,
L_11 ,
V_96 -> V_98 , V_96 -> V_99 ,
V_96 -> V_100 ) ;
if ( F_21 ( V_96 -> V_98 , V_2 -> V_59 -> V_101 ) ) {
if ( V_96 -> V_99 )
V_2 -> V_9 = false ;
else
V_2 -> V_9 = true ;
} else if ( F_22 ( V_96 -> V_98 ) ) {
F_23 ( V_2 , V_96 -> V_98 , V_96 -> V_99 ) ;
} else {
F_24 ( & V_2 -> V_102 , V_97 ) ;
V_67 = F_16 ( V_2 , V_96 -> V_98 ) ;
F_25 ( & V_2 -> V_102 , V_97 ) ;
if ( V_67 && V_67 -> V_99 != V_96 -> V_99 ) {
V_67 -> V_99 = V_96 -> V_99 ;
F_23 ( V_2 , V_96 -> V_98 ,
V_96 -> V_99 ) ;
}
}
}
static void F_26 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
struct V_95 * V_96 ;
struct V_66 * V_67 ;
int V_81 ;
unsigned long V_97 ;
V_96 = ( void * ) V_94 ;
F_2 ( V_2 -> V_5 , V_79 ,
L_12 ,
V_96 -> V_98 , V_96 -> V_99 ,
V_96 -> V_100 ) ;
if ( F_21 ( V_96 -> V_98 , V_2 -> V_56 ) ) {
if ( V_96 -> V_99 )
V_2 -> V_9 = false ;
else
V_2 -> V_9 = true ;
} else {
if ( ! F_4 ( V_2 -> V_5 -> V_11 ) )
return;
V_81 = F_27 ( V_2 , V_96 -> V_98 ) ;
if ( F_28 ( V_81 ) ) {
F_24 ( & V_2 -> V_102 , V_97 ) ;
V_67 = F_16 ( V_2 , V_96 -> V_98 ) ;
F_25 ( & V_2 -> V_102 , V_97 ) ;
if ( V_67 && V_67 -> V_99 != V_96 -> V_99 ) {
V_67 -> V_99 = V_96 -> V_99 ;
F_23 ( V_2 ,
V_96 -> V_98 ,
V_96 -> V_99 ) ;
}
}
}
}
void F_29 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_103 * V_104 ;
struct V_105 * V_106 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_93 * V_94 ;
T_1 V_107 , V_108 , V_109 ;
int V_110 , V_111 , V_112 , V_113 ;
struct V_1 * V_114 ;
V_107 = V_64 -> V_74 - sizeof( V_115 ) ;
V_104 = ( void * ) V_64 -> V_70 + sizeof( V_115 ) ;
if ( F_17 ( V_104 -> V_116 . type ) != V_117 ||
V_107 < sizeof( struct V_103 ) ) {
F_2 ( V_5 , ERROR ,
L_13 ) ;
return;
}
V_5 -> V_118 = F_17 ( V_104 -> V_81 ) ;
F_2 ( V_5 , V_79 , L_14 ,
V_5 -> V_118 ? L_15 : L_16 ) ;
V_107 -= sizeof( struct V_103 ) ;
V_94 = (struct V_93 * ) V_104 -> V_119 ;
while ( V_107 >= ( int ) sizeof( struct V_93 ) ) {
V_108 = F_17 ( V_94 -> type ) ;
V_109 = F_17 ( V_94 -> V_74 ) ;
if ( ( sizeof( struct V_93 ) + V_109 ) >
V_107 ) {
F_2 ( V_5 , ERROR , L_17
L_18 , V_109 , V_107 ) ;
break;
}
if ( V_108 != V_120 ) {
F_2 ( V_5 , ERROR , L_19 ,
V_108 ) ;
break;
}
V_106 = (struct V_105 * ) V_94 ;
V_110 = V_106 -> V_110 ;
for ( V_113 = 0 ; V_113 < V_110 ; V_113 ++ ) {
V_111 = V_106 -> V_121 [ V_113 ] >> 4 ;
V_112 = V_106 -> V_121 [ V_113 ] & V_122 ;
V_114 = F_30 ( V_5 , V_112 ,
V_111 ) ;
if ( ! V_114 ) {
F_2 ( V_5 , ERROR ,
L_20
L_21 ) ;
continue;
}
if ( V_5 -> V_123 == V_124 ) {
T_2 V_125 ;
V_125 = V_106 -> V_126 . V_127 ;
if ( V_125 == V_128 ||
V_125 == V_129 )
V_114 -> V_130 = V_125 ;
}
}
V_107 -= sizeof( struct V_93 ) +
V_109 ;
V_94 = ( void * ) ( ( T_2 * ) V_94 + V_109 +
sizeof( struct V_93 ) ) ;
}
if ( V_5 -> V_123 == V_124 ) {
V_5 -> V_51 = true ;
V_5 -> V_131 = true ;
F_31 ( V_5 ) ;
}
}
void F_32 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_93 * V_94 ;
T_1 V_108 , V_109 ;
int V_107 ;
if ( ! V_2 -> V_6 ) {
F_2 ( V_2 -> V_5 , ERROR ,
L_22 ,
V_2 -> V_132 ) ;
return;
}
V_107 = V_64 -> V_74 - sizeof( V_115 ) ;
V_94 = ( void * ) V_64 -> V_70 + sizeof( V_115 ) ;
while ( V_107 >= ( int ) sizeof( struct V_93 ) ) {
V_108 = F_17 ( V_94 -> type ) ;
V_109 = F_17 ( V_94 -> V_74 ) ;
if ( ( sizeof( struct V_93 ) + V_109 ) >
V_107 ) {
F_2 ( V_2 -> V_5 , ERROR ,
L_23 ,
V_109 , V_107 ) ;
break;
}
if ( V_108 == V_133 ) {
if ( F_3 ( V_2 ) == V_10 )
F_26 ( V_2 , V_94 ) ;
else
F_20 ( V_2 , V_94 ) ;
}
V_107 -= sizeof( struct V_93 ) +
V_109 ;
V_94 = ( void * ) ( ( T_2 * ) V_94 + V_109 +
sizeof( struct V_93 ) ) ;
}
}
void F_33 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_93 * V_94 ;
struct V_134 * V_135 ;
struct V_136 * V_137 ;
T_3 V_74 = V_64 -> V_74 - sizeof( V_115 ) ;
T_2 * V_138 = V_64 -> V_70 + sizeof( V_115 ) ;
T_1 V_108 , V_109 ;
while ( V_74 >= sizeof( struct V_93 ) ) {
V_94 = (struct V_93 * ) V_138 ;
V_109 = F_17 ( V_94 -> V_74 ) ;
V_108 = F_17 ( V_94 -> type ) ;
if ( ( V_109 + sizeof( struct V_93 ) ) > V_74 )
break;
switch ( V_108 ) {
case V_139 :
V_135 =
(struct V_134 * ) V_94 ;
V_5 -> V_140 = V_135 -> V_140 ;
V_5 -> V_141 =
V_135 -> V_142 ;
V_5 -> V_143 =
V_135 -> V_144 ;
F_34 ( V_5 ) ;
F_35 ( V_5 ) ;
break;
case V_145 :
V_137 =
(struct V_136 * ) V_94 ;
V_5 -> V_146 = V_137 -> V_146 ;
V_5 -> V_147 = V_137 -> V_148 ;
V_5 -> V_149 = V_137 -> V_150 ;
break;
default:
break;
}
V_74 -= V_109 + sizeof( struct V_93 ) ;
V_138 += V_109 +
sizeof( struct V_93 ) ;
}
F_36 ( V_5 -> V_151 , L_24 ,
V_5 -> V_146 , V_5 -> V_147 ,
V_5 -> V_140 , V_5 -> V_141 ,
V_5 -> V_143 ) ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_65 = 0 ;
V_115 V_152 = V_5 -> V_71 ;
T_1 V_153 , V_3 ;
switch ( V_152 ) {
case V_154 :
F_2 ( V_5 , ERROR ,
L_25 ) ;
break;
case V_155 :
F_2 ( V_5 , V_79 , L_26 ) ;
if ( ! F_12 ( V_2 -> V_59 ) )
F_38 ( V_2 -> V_59 ) ;
F_39 ( V_2 -> V_59 , V_5 ) ;
break;
case V_156 :
F_2 ( V_5 , V_79 , L_27 ) ;
if ( V_2 -> V_157 . V_158 ) {
F_2 ( V_5 , V_7 ,
L_28 ) ;
break;
}
V_5 -> V_159 . V_160 ++ ;
if ( V_2 -> V_6 ) {
V_3 =
F_17 ( * ( V_161 * ) V_5 -> V_162 ) ;
F_1 ( V_2 , V_3 ) ;
}
break;
case V_163 :
F_2 ( V_5 , V_79 , L_29 ) ;
if ( V_2 -> V_157 . V_158 ) {
F_2 ( V_5 , V_7 ,
L_30 ) ;
break;
}
V_5 -> V_159 . V_164 ++ ;
if ( V_2 -> V_6 ) {
V_3 =
F_17 ( * ( V_161 * ) V_5 -> V_162 ) ;
F_1 ( V_2 , V_3 ) ;
}
break;
case V_165 :
F_2 ( V_5 , V_79 , L_31 ) ;
V_5 -> V_159 . V_166 ++ ;
if ( V_2 -> V_6 ) {
V_3 =
F_17 ( * ( V_161 * ) V_5 -> V_162 ) ;
F_1 ( V_2 , V_3 ) ;
}
break;
case V_167 :
F_2 ( V_5 , V_79 , L_32 ) ;
V_5 -> V_168 = V_169 ;
F_40 ( V_5 ) ;
break;
case V_170 :
F_2 ( V_5 , V_79 , L_33 ) ;
if ( ! V_5 -> V_52 &&
( V_2 -> V_9 ||
( V_2 -> V_37 == V_38 ) ) &&
V_2 -> V_6 && V_5 -> V_171 . V_172 ) {
V_5 -> V_52 = true ;
F_2 ( V_5 , V_79 ,
L_34 ) ;
}
V_5 -> V_51 = false ;
if ( V_5 -> V_52 && V_5 -> V_173 ) {
if ( F_41 ( V_2 ) ) {
if ( V_5 -> V_174 ||
( V_5 -> V_175 . V_176 &&
! V_5 -> V_175 . V_176 ( V_2 ) ) ) {
V_5 -> V_168 = V_177 ;
V_5 -> V_178 = false ;
V_5 -> V_179 = false ;
F_42 ( & V_5 -> V_180 ) ;
break;
}
if ( ! F_43
( V_2 ,
V_181 |
V_182 ) )
V_5 -> V_168 =
V_183 ;
return 0 ;
}
}
V_5 -> V_168 = V_177 ;
V_5 -> V_178 = false ;
V_5 -> V_179 = false ;
F_42 ( & V_5 -> V_180 ) ;
break;
case V_184 :
V_5 -> V_175 . V_185 ( V_5 ) ;
F_2 ( V_5 , V_79 , L_35 ) ;
if ( V_5 -> V_186 )
V_5 -> V_186 = false ;
break;
case V_187 :
F_2 ( V_5 , V_79 , L_36 ) ;
V_65 = F_14 ( V_2 , V_188 ,
0 , 0 , NULL , false ) ;
break;
case V_189 :
F_2 ( V_5 , V_79 , L_37 ) ;
F_44 ( V_2 -> V_59 , V_2 -> V_56 ,
V_190 ,
- 1 , NULL , V_60 ) ;
break;
case V_191 :
F_2 ( V_5 , V_79 , L_38 ) ;
F_44 ( V_2 -> V_59 , V_2 -> V_56 ,
V_192 ,
- 1 , NULL , V_60 ) ;
break;
case V_193 :
case V_194 :
break;
case V_195 :
F_2 ( V_5 , V_79 , L_39 ) ;
V_2 -> V_41 = false ;
F_7 ( V_2 ) ;
F_11 ( V_2 -> V_59 , V_5 ) ;
if ( F_12 ( V_2 -> V_59 ) )
F_13 ( V_2 -> V_59 ) ;
break;
case V_196 :
F_2 ( V_5 , V_79 , L_40 ) ;
V_65 = F_14 ( V_2 , V_197 ,
V_198 , 0 , NULL , false ) ;
break;
case V_199 :
F_36 ( V_5 -> V_151 , L_41 ) ;
F_45 ( V_2 -> V_200 . V_201 ) ;
if ( V_2 -> V_202 )
V_2 -> V_202 = false ;
break;
case V_203 :
F_2 ( V_5 , V_79 , L_42 ) ;
V_2 -> V_9 = true ;
break;
case V_204 :
F_2 ( V_5 , V_79 , L_43 ) ;
if ( V_5 -> V_205 )
V_65 = F_46 ( V_2 ,
V_5 -> V_64 -> V_70 ) ;
break;
case V_206 :
F_2 ( V_5 , V_79 , L_44 ) ;
V_65 = F_14 ( V_2 , V_207 ,
0 , 0 , NULL , false ) ;
break;
case V_208 :
F_47 ( V_2 -> V_59 ,
V_209 ,
V_60 ) ;
F_14 ( V_2 , V_210 ,
V_198 , 0 , NULL , false ) ;
V_2 -> V_211 = V_212 ;
F_2 ( V_5 , V_79 , L_45 ) ;
break;
case V_213 :
F_2 ( V_5 , V_79 , L_46 ) ;
break;
case V_214 :
F_2 ( V_5 , V_79 , L_47 ) ;
break;
case V_215 :
F_47 ( V_2 -> V_59 ,
V_216 ,
V_60 ) ;
F_14 ( V_2 , V_210 ,
V_198 , 0 , NULL , false ) ;
V_2 -> V_211 = V_217 ;
F_2 ( V_5 , V_79 , L_48 ) ;
break;
case V_218 :
F_2 ( V_5 , V_79 , L_49 ) ;
break;
case V_219 :
F_2 ( V_5 , V_79 , L_50 ) ;
break;
case V_220 :
F_2 ( V_5 , V_79 , L_51 ) ;
break;
case V_221 :
F_2 ( V_5 , V_79 , L_52 ) ;
break;
case V_222 :
F_2 ( V_5 , V_79 , L_53 ) ;
break;
case V_223 :
F_2 ( V_5 , V_79 , L_54 ) ;
break;
case V_224 :
F_2 ( V_5 , V_79 , L_55 ) ;
break;
case V_225 :
F_2 ( V_5 , V_79 , L_56 ) ;
V_65 = F_14 ( V_2 ,
V_226 ,
V_198 , 0 , NULL , false ) ;
break;
case V_227 :
F_2 ( V_5 , V_79 , L_57 ) ;
F_14 ( V_2 , V_228 ,
V_229 , 0 ,
V_5 -> V_162 , false ) ;
break;
case V_230 :
F_2 ( V_5 , V_79 , L_58 ) ;
F_48 ( V_2 , V_5 -> V_162 ) ;
break;
case V_231 :
F_2 ( V_5 , V_79 , L_59 ) ;
F_49 ( V_2 ,
(struct V_232
* )
V_5 -> V_162 ) ;
break;
case V_233 :
V_153 = F_17 ( * ( V_161 * ) V_5 -> V_162 ) ;
F_2 ( V_5 , V_79 ,
L_60 , V_153 ) ;
V_5 -> V_234 =
F_50 ( T_1 , V_5 -> V_235 , V_153 ) ;
F_2 ( V_5 , V_79 , L_61 ,
V_5 -> V_234 ) ;
break;
case V_236 :
F_2 ( V_5 , V_79 , L_62 ) ;
break;
case V_237 :
F_2 ( V_5 , V_79 , L_63 ) ;
break;
case V_238 :
F_2 ( V_5 , V_79 ,
L_64 , V_152 ) ;
break;
case V_239 :
F_2 ( V_5 , V_79 ,
L_65 ) ;
F_51 ( & V_2 -> V_200 ,
V_2 -> V_240 . V_241 ,
& V_2 -> V_240 . V_242 ,
V_243 ) ;
memset ( & V_2 -> V_240 , 0x00 , sizeof( struct V_244 ) ) ;
break;
case V_245 :
F_2 ( V_5 , V_79 , L_66 ) ;
V_2 -> V_246 =
V_247 + F_52 ( V_248 ) ;
V_2 -> V_249 = V_2 -> V_45 . V_46 . V_250 ;
V_65 = F_14 ( V_2 , V_251 ,
V_229 , 0 ,
V_2 -> V_45 . V_46 . V_49 ,
false ) ;
break;
case V_252 :
V_65 = F_15 ( V_2 , V_5 -> V_64 ) ;
break;
case V_253 :
F_2 ( V_5 , V_79 , L_67 ) ;
F_32 ( V_2 , V_5 -> V_64 ) ;
break;
case V_254 :
F_2 ( V_5 , V_79 , L_68 ) ;
F_29 ( V_2 , V_5 -> V_64 ) ;
break;
case V_255 :
F_2 ( V_5 , V_79 , L_69 ) ;
F_53 ( V_2 , V_5 -> V_162 ) ;
break;
case V_256 :
F_2 ( V_5 , V_79 , L_70 ) ;
V_65 = F_54 ( V_2 ,
V_5 -> V_64 ) ;
break;
case V_257 :
F_2 ( V_5 , V_79 , L_71 ) ;
V_65 = F_55 ( V_2 ,
V_5 -> V_64 ) ;
break;
case V_258 :
F_36 ( V_5 -> V_151 , L_72 ) ;
F_33 ( V_2 ,
V_5 -> V_64 ) ;
break;
default:
F_2 ( V_5 , ERROR , L_73 ,
V_152 ) ;
break;
}
return V_65 ;
}
