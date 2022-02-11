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
if ( ( F_3 ( V_2 ) == V_10 ||
F_3 ( V_2 ) == V_33 ) && V_2 -> V_34 )
F_8 ( V_2 ) ;
if ( V_2 -> V_35 == V_36 ) {
V_2 -> V_37 = V_38 ;
V_2 -> V_39 = false ;
}
F_2 ( V_5 , V_7 ,
L_2 ,
V_2 -> V_40 . V_41 , V_2 -> V_40 . V_42 ) ;
F_2 ( V_5 , V_7 ,
L_3 ,
V_2 -> V_43 . V_44 . V_41 . V_41 ,
V_2 -> V_43 . V_44 . V_41 . V_42 ) ;
memcpy ( & V_2 -> V_40 ,
& V_2 -> V_43 . V_44 . V_41 ,
sizeof( struct V_45 ) ) ;
memcpy ( V_2 -> V_46 ,
V_2 -> V_43 . V_44 . V_47 , V_48 ) ;
memset ( & V_2 -> V_43 , 0x00 , sizeof( V_2 -> V_43 ) ) ;
V_5 -> V_49 = false ;
V_5 -> V_50 = false ;
if ( V_5 -> V_51 && V_5 -> V_52 )
return;
V_2 -> V_6 = false ;
F_2 ( V_5 , V_53 ,
L_4 ,
V_2 -> V_54 , V_3 ) ;
if ( V_2 -> V_35 == V_55 ||
V_2 -> V_35 == V_56 ) {
F_9 ( V_2 -> V_57 , V_3 , NULL , 0 ,
false , V_58 ) ;
}
F_10 ( V_2 -> V_54 ) ;
F_11 ( V_2 -> V_57 , V_5 ) ;
if ( F_12 ( V_2 -> V_57 ) )
F_13 ( V_2 -> V_57 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
int V_61 = 0 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_62 * V_63 ;
struct V_64 * V_65 =
( void * ) V_60 -> V_66 + sizeof( V_5 -> V_67 ) ;
T_2 * V_68 = V_65 -> V_69 ;
if ( V_60 -> V_70 < ( sizeof( struct V_64 ) -
sizeof( T_1 ) - sizeof( V_5 -> V_67 ) ) ) {
F_2 ( V_5 , ERROR , L_5 ) ;
return - 1 ;
}
V_63 = F_15 ( V_2 , V_65 -> V_69 ) ;
if ( ! V_63 ) {
F_2 ( V_5 , ERROR , L_6 ) ;
return - 1 ;
}
switch ( F_16 ( V_65 -> type ) ) {
case V_71 :
F_17 ( V_2 -> V_57 ,
V_65 -> V_69 ,
V_72 ,
F_16 ( V_65 -> V_73 . V_3 ) ,
V_58 ) ;
break;
case V_74 :
F_2 ( V_5 , V_75 , L_7 ) ;
F_2 ( V_5 , V_75 ,
L_8 ,
V_65 -> V_73 . V_76 . V_77 ,
V_65 -> V_73 . V_76 . V_78 ,
V_65 -> V_73 . V_76 . V_79 ) ;
if ( V_65 -> V_73 . V_76 . V_77 != 0 ) {
switch ( V_65 -> V_73 . V_76 . V_79 ) {
case V_80 :
V_63 -> V_81 = V_82 ;
break;
case V_83 :
V_63 -> V_81 = V_84 ;
break;
default:
break;
}
return V_61 ;
}
switch ( V_65 -> V_73 . V_76 . V_79 ) {
case V_80 :
if ( V_63 -> V_81 == V_82 )
break;
F_18 ( V_2 , V_68 ,
false ) ;
V_63 -> V_81 = V_82 ;
break;
case V_83 :
if ( V_63 -> V_81 == V_84 )
break;
F_18 ( V_2 , V_68 ,
true ) ;
V_63 -> V_81 = V_84 ;
break;
default:
break;
}
break;
case V_85 :
F_2 ( V_5 , V_75 , L_9 ) ;
V_63 -> V_81 = V_86 ;
break;
case V_87 :
F_2 ( V_5 , V_75 ,
L_10 ,
V_65 -> V_73 . V_88 ) ;
break;
default:
break;
}
return V_61 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_89 * V_90 )
{
struct V_91 * V_92 ;
struct V_62 * V_63 ;
unsigned long V_93 ;
V_92 = ( void * ) V_90 ;
F_2 ( V_2 -> V_5 , V_75 ,
L_11 ,
V_92 -> V_94 , V_92 -> V_95 ,
V_92 -> V_96 ) ;
if ( F_20 ( V_92 -> V_94 , V_2 -> V_57 -> V_97 ) ) {
if ( V_92 -> V_95 )
V_2 -> V_9 = false ;
else
V_2 -> V_9 = true ;
} else if ( F_21 ( V_92 -> V_94 ) ) {
F_22 ( V_2 , V_92 -> V_94 , V_92 -> V_95 ) ;
} else {
F_23 ( & V_2 -> V_98 , V_93 ) ;
V_63 = F_15 ( V_2 , V_92 -> V_94 ) ;
F_24 ( & V_2 -> V_98 , V_93 ) ;
if ( V_63 && V_63 -> V_95 != V_92 -> V_95 ) {
V_63 -> V_95 = V_92 -> V_95 ;
F_22 ( V_2 , V_92 -> V_94 ,
V_92 -> V_95 ) ;
}
}
}
static void F_25 ( struct V_1 * V_2 ,
struct V_89 * V_90 )
{
struct V_91 * V_92 ;
struct V_62 * V_63 ;
int V_77 ;
unsigned long V_93 ;
V_92 = ( void * ) V_90 ;
F_2 ( V_2 -> V_5 , V_75 ,
L_12 ,
V_92 -> V_94 , V_92 -> V_95 ,
V_92 -> V_96 ) ;
if ( F_20 ( V_92 -> V_94 , V_2 -> V_54 ) ) {
if ( V_92 -> V_95 )
V_2 -> V_9 = false ;
else
V_2 -> V_9 = true ;
} else {
if ( ! F_4 ( V_2 -> V_5 -> V_11 ) )
return;
V_77 = F_26 ( V_2 , V_92 -> V_94 ) ;
if ( F_27 ( V_77 ) ) {
F_23 ( & V_2 -> V_98 , V_93 ) ;
V_63 = F_15 ( V_2 , V_92 -> V_94 ) ;
F_24 ( & V_2 -> V_98 , V_93 ) ;
if ( V_63 && V_63 -> V_95 != V_92 -> V_95 ) {
V_63 -> V_95 = V_92 -> V_95 ;
F_22 ( V_2 ,
V_92 -> V_94 ,
V_92 -> V_95 ) ;
}
}
}
}
void F_28 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_99 * V_100 ;
struct V_101 * V_102 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_89 * V_90 ;
T_1 V_103 , V_104 , V_105 ;
int V_106 , V_107 , V_108 , V_109 ;
struct V_1 * V_110 ;
V_103 = V_60 -> V_70 - sizeof( V_111 ) ;
V_100 = ( void * ) V_60 -> V_66 + sizeof( V_111 ) ;
if ( F_16 ( V_100 -> V_112 . type ) != V_113 ||
V_103 < sizeof( struct V_99 ) ) {
F_2 ( V_5 , ERROR ,
L_13 ) ;
return;
}
V_5 -> V_114 = F_16 ( V_100 -> V_77 ) ;
F_2 ( V_5 , V_75 , L_14 ,
V_5 -> V_114 ? L_15 : L_16 ) ;
V_103 -= sizeof( struct V_99 ) ;
V_90 = (struct V_89 * ) V_100 -> V_115 ;
while ( V_103 >= ( int ) sizeof( struct V_89 ) ) {
V_104 = F_16 ( V_90 -> type ) ;
V_105 = F_16 ( V_90 -> V_70 ) ;
if ( ( sizeof( struct V_89 ) + V_105 ) >
V_103 ) {
F_2 ( V_5 , ERROR , L_17
L_18 , V_105 , V_103 ) ;
break;
}
if ( V_104 != V_116 ) {
F_2 ( V_5 , ERROR , L_19 ,
V_104 ) ;
break;
}
V_102 = (struct V_101 * ) V_90 ;
V_106 = V_102 -> V_106 ;
for ( V_109 = 0 ; V_109 < V_106 ; V_109 ++ ) {
V_107 = V_102 -> V_117 [ V_109 ] >> 4 ;
V_108 = V_102 -> V_117 [ V_109 ] & V_118 ;
V_110 = F_29 ( V_5 , V_108 ,
V_107 ) ;
if ( ! V_110 ) {
F_2 ( V_5 , ERROR ,
L_20
L_21 ) ;
continue;
}
if ( V_5 -> V_119 == V_120 ) {
T_2 V_121 ;
V_121 = V_102 -> V_122 . V_123 ;
if ( V_121 == V_124 ||
V_121 == V_125 )
V_110 -> V_126 = V_121 ;
}
}
V_103 -= sizeof( struct V_89 ) +
V_105 ;
V_90 = ( void * ) ( ( T_2 * ) V_90 + V_105 +
sizeof( struct V_89 ) ) ;
}
if ( V_5 -> V_119 == V_120 ) {
V_5 -> V_49 = true ;
V_5 -> V_127 = true ;
F_30 ( V_5 ) ;
}
}
void F_31 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_89 * V_90 ;
T_1 V_104 , V_105 ;
int V_103 ;
if ( ! V_2 -> V_6 ) {
F_2 ( V_2 -> V_5 , ERROR ,
L_22 ,
V_2 -> V_128 ) ;
return;
}
V_103 = V_60 -> V_70 - sizeof( V_111 ) ;
V_90 = ( void * ) V_60 -> V_66 + sizeof( V_111 ) ;
while ( V_103 >= ( int ) sizeof( struct V_89 ) ) {
V_104 = F_16 ( V_90 -> type ) ;
V_105 = F_16 ( V_90 -> V_70 ) ;
if ( ( sizeof( struct V_89 ) + V_105 ) >
V_103 ) {
F_2 ( V_2 -> V_5 , ERROR ,
L_23 ,
V_105 , V_103 ) ;
break;
}
if ( V_104 == V_129 ) {
if ( F_3 ( V_2 ) == V_10 )
F_25 ( V_2 , V_90 ) ;
else
F_19 ( V_2 , V_90 ) ;
}
V_103 -= sizeof( struct V_89 ) +
V_105 ;
V_90 = ( void * ) ( ( T_2 * ) V_90 + V_105 +
sizeof( struct V_89 ) ) ;
}
}
void F_32 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_89 * V_90 ;
struct V_130 * V_131 ;
struct V_132 * V_133 ;
T_3 V_70 = V_60 -> V_70 - sizeof( V_111 ) ;
T_2 * V_134 = V_60 -> V_66 + sizeof( V_111 ) ;
T_1 V_104 , V_105 ;
while ( V_70 >= sizeof( struct V_89 ) ) {
V_90 = (struct V_89 * ) V_134 ;
V_105 = F_16 ( V_90 -> V_70 ) ;
V_104 = F_16 ( V_90 -> type ) ;
if ( ( V_105 + sizeof( struct V_89 ) ) > V_70 )
break;
switch ( V_104 ) {
case V_135 :
V_131 =
(struct V_130 * ) V_90 ;
V_5 -> V_136 = V_131 -> V_136 ;
V_5 -> V_137 =
V_131 -> V_138 ;
V_5 -> V_139 =
V_131 -> V_140 ;
F_33 ( V_5 ) ;
F_34 ( V_5 ) ;
break;
case V_141 :
V_133 =
(struct V_132 * ) V_90 ;
V_5 -> V_142 = V_133 -> V_142 ;
V_5 -> V_143 = V_133 -> V_144 ;
V_5 -> V_145 = V_133 -> V_146 ;
break;
default:
break;
}
V_70 -= V_105 + sizeof( struct V_89 ) ;
V_134 += V_105 +
sizeof( struct V_89 ) ;
}
F_35 ( V_5 -> V_147 , L_24 ,
V_5 -> V_142 , V_5 -> V_143 ,
V_5 -> V_136 , V_5 -> V_137 ,
V_5 -> V_139 ) ;
}
int F_36 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_61 = 0 ;
V_111 V_148 = V_5 -> V_67 ;
T_1 V_149 , V_3 ;
switch ( V_148 ) {
case V_150 :
F_2 ( V_5 , ERROR ,
L_25 ) ;
break;
case V_151 :
F_2 ( V_5 , V_75 , L_26 ) ;
if ( ! F_12 ( V_2 -> V_57 ) )
F_37 ( V_2 -> V_57 ) ;
F_38 ( V_2 -> V_57 , V_5 ) ;
break;
case V_152 :
F_2 ( V_5 , V_75 , L_27 ) ;
if ( V_2 -> V_153 . V_154 ) {
F_2 ( V_5 , V_7 ,
L_28 ) ;
break;
}
V_5 -> V_155 . V_156 ++ ;
if ( V_2 -> V_6 ) {
V_3 =
F_16 ( * ( V_157 * ) V_5 -> V_158 ) ;
F_1 ( V_2 , V_3 ) ;
}
break;
case V_159 :
F_2 ( V_5 , V_75 , L_29 ) ;
if ( V_2 -> V_153 . V_154 ) {
F_2 ( V_5 , V_7 ,
L_30 ) ;
break;
}
V_5 -> V_155 . V_160 ++ ;
if ( V_2 -> V_6 ) {
V_3 =
F_16 ( * ( V_157 * ) V_5 -> V_158 ) ;
F_1 ( V_2 , V_3 ) ;
}
break;
case V_161 :
F_2 ( V_5 , V_75 , L_31 ) ;
V_5 -> V_155 . V_162 ++ ;
if ( V_2 -> V_6 ) {
V_3 =
F_16 ( * ( V_157 * ) V_5 -> V_158 ) ;
F_1 ( V_2 , V_3 ) ;
}
break;
case V_163 :
F_2 ( V_5 , V_75 , L_32 ) ;
V_5 -> V_164 = V_165 ;
F_39 ( V_5 ) ;
break;
case V_166 :
F_2 ( V_5 , V_75 , L_33 ) ;
if ( ! V_5 -> V_50 && V_2 -> V_9 &&
V_2 -> V_6 && V_5 -> V_167 . V_168 ) {
V_5 -> V_50 = true ;
F_2 ( V_5 , V_75 ,
L_34 ) ;
}
V_5 -> V_49 = false ;
if ( V_5 -> V_50 && V_5 -> V_169 ) {
if ( F_40 ( V_2 ) ) {
if ( V_5 -> V_170 ||
( V_5 -> V_171 . V_172 &&
! V_5 -> V_171 . V_172 ( V_2 ) ) ) {
V_5 -> V_164 = V_173 ;
V_5 -> V_174 = false ;
V_5 -> V_175 = false ;
F_41 ( & V_5 -> V_176 ) ;
break;
}
if ( ! F_42
( V_2 ,
V_177 |
V_178 ) )
V_5 -> V_164 =
V_179 ;
return 0 ;
}
}
V_5 -> V_164 = V_173 ;
V_5 -> V_174 = false ;
V_5 -> V_175 = false ;
F_41 ( & V_5 -> V_176 ) ;
break;
case V_180 :
V_5 -> V_171 . V_181 ( V_5 ) ;
F_2 ( V_5 , V_75 , L_35 ) ;
if ( V_5 -> V_182 )
V_5 -> V_182 = false ;
break;
case V_183 :
F_2 ( V_5 , V_75 , L_36 ) ;
V_61 = F_43 ( V_2 , V_184 ,
0 , 0 , NULL , false ) ;
break;
case V_185 :
F_2 ( V_5 , V_75 , L_37 ) ;
F_44 ( V_2 -> V_57 , V_2 -> V_54 ,
V_186 ,
- 1 , NULL , V_58 ) ;
break;
case V_187 :
F_2 ( V_5 , V_75 , L_38 ) ;
F_44 ( V_2 -> V_57 , V_2 -> V_54 ,
V_188 ,
- 1 , NULL , V_58 ) ;
break;
case V_189 :
case V_190 :
break;
case V_191 :
F_2 ( V_5 , V_75 , L_39 ) ;
V_2 -> V_39 = false ;
F_7 ( V_2 ) ;
F_11 ( V_2 -> V_57 , V_5 ) ;
if ( F_12 ( V_2 -> V_57 ) )
F_13 ( V_2 -> V_57 ) ;
break;
case V_192 :
F_2 ( V_5 , V_75 , L_40 ) ;
V_61 = F_43 ( V_2 , V_193 ,
V_194 , 0 , NULL , false ) ;
break;
case V_195 :
F_2 ( V_5 , V_75 , L_41 ) ;
V_2 -> V_9 = true ;
break;
case V_196 :
F_2 ( V_5 , V_75 , L_42 ) ;
if ( V_5 -> V_197 )
V_61 = F_45 ( V_2 ,
V_5 -> V_60 -> V_66 ) ;
break;
case V_198 :
F_2 ( V_5 , V_75 , L_43 ) ;
V_61 = F_43 ( V_2 , V_199 ,
0 , 0 , NULL , false ) ;
break;
case V_200 :
F_46 ( V_2 -> V_57 ,
V_201 ,
V_58 ) ;
F_43 ( V_2 , V_202 ,
V_194 , 0 , NULL , false ) ;
V_2 -> V_203 = V_204 ;
F_2 ( V_5 , V_75 , L_44 ) ;
break;
case V_205 :
F_2 ( V_5 , V_75 , L_45 ) ;
break;
case V_206 :
F_2 ( V_5 , V_75 , L_46 ) ;
break;
case V_207 :
F_46 ( V_2 -> V_57 ,
V_208 ,
V_58 ) ;
F_43 ( V_2 , V_202 ,
V_194 , 0 , NULL , false ) ;
V_2 -> V_203 = V_209 ;
F_2 ( V_5 , V_75 , L_47 ) ;
break;
case V_210 :
F_2 ( V_5 , V_75 , L_48 ) ;
break;
case V_211 :
F_2 ( V_5 , V_75 , L_49 ) ;
break;
case V_212 :
F_2 ( V_5 , V_75 , L_50 ) ;
break;
case V_213 :
F_2 ( V_5 , V_75 , L_51 ) ;
break;
case V_214 :
F_2 ( V_5 , V_75 , L_52 ) ;
break;
case V_215 :
F_2 ( V_5 , V_75 , L_53 ) ;
break;
case V_216 :
F_2 ( V_5 , V_75 , L_54 ) ;
break;
case V_217 :
F_2 ( V_5 , V_75 , L_55 ) ;
V_61 = F_43 ( V_2 ,
V_218 ,
V_194 , 0 , NULL , false ) ;
break;
case V_219 :
F_2 ( V_5 , V_75 , L_56 ) ;
F_43 ( V_2 , V_220 ,
V_221 , 0 ,
V_5 -> V_158 , false ) ;
break;
case V_222 :
F_2 ( V_5 , V_75 , L_57 ) ;
F_47 ( V_2 , V_5 -> V_158 ) ;
break;
case V_223 :
F_2 ( V_5 , V_75 , L_58 ) ;
F_48 ( V_2 ,
(struct V_224
* )
V_5 -> V_158 ) ;
break;
case V_225 :
V_149 = F_16 ( * ( V_157 * ) V_5 -> V_158 ) ;
F_2 ( V_5 , V_75 ,
L_59 , V_149 ) ;
V_5 -> V_226 =
F_49 ( T_1 , V_5 -> V_227 , V_149 ) ;
F_2 ( V_5 , V_75 , L_60 ,
V_5 -> V_226 ) ;
break;
case V_228 :
F_2 ( V_5 , V_75 , L_61 ) ;
break;
case V_229 :
F_2 ( V_5 , V_75 , L_62 ) ;
break;
case V_230 :
F_2 ( V_5 , V_75 ,
L_63 , V_148 ) ;
break;
case V_231 :
F_2 ( V_5 , V_75 ,
L_64 ) ;
F_50 ( & V_2 -> V_232 ,
V_2 -> V_233 . V_234 ,
& V_2 -> V_233 . V_235 ,
V_236 ) ;
memset ( & V_2 -> V_233 , 0x00 , sizeof( struct V_237 ) ) ;
break;
case V_238 :
F_2 ( V_5 , V_75 , L_65 ) ;
V_2 -> V_239 =
V_240 + F_51 ( V_241 ) ;
V_2 -> V_242 = V_2 -> V_43 . V_44 . V_243 ;
V_61 = F_43 ( V_2 , V_244 ,
V_221 , 0 ,
V_2 -> V_43 . V_44 . V_47 ,
false ) ;
break;
case V_245 :
V_61 = F_14 ( V_2 , V_5 -> V_60 ) ;
break;
case V_246 :
F_2 ( V_5 , V_75 , L_66 ) ;
F_31 ( V_2 , V_5 -> V_60 ) ;
break;
case V_247 :
F_2 ( V_5 , V_75 , L_67 ) ;
F_28 ( V_2 , V_5 -> V_60 ) ;
break;
case V_248 :
F_2 ( V_5 , V_75 , L_68 ) ;
F_52 ( V_2 , V_5 -> V_158 ) ;
break;
case V_249 :
F_2 ( V_5 , V_75 , L_69 ) ;
V_61 = F_53 ( V_2 ,
V_5 -> V_60 ) ;
break;
case V_250 :
F_2 ( V_5 , V_75 , L_70 ) ;
V_61 = F_54 ( V_2 ,
V_5 -> V_60 ) ;
break;
case V_251 :
F_35 ( V_5 -> V_147 , L_71 ) ;
F_32 ( V_2 ,
V_5 -> V_60 ) ;
break;
default:
F_2 ( V_5 , ERROR , L_72 ,
V_148 ) ;
break;
}
return V_61 ;
}
