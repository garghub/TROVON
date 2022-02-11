static inline int F_1 ( T_1 V_1 )
{
return ( F_2 ( V_2 , V_1 ) == V_3 ) ;
}
static int F_3 ( struct V_4 * V_4 , struct V_5 * V_6 )
{
V_6 -> V_7 = F_4 ( sizeof( struct V_8 ) , V_9 ) ;
if ( V_6 -> V_7 )
( (struct V_8 * ) V_6 -> V_7 ) -> V_10 = - 1 ;
return V_6 -> V_7 ? 0 : - V_11 ;
}
static T_2 F_5 ( struct V_5 * V_6 , const char T_3 * V_12 ,
T_4 V_13 , T_5 * V_14 )
{
const struct V_15 T_3 * V_16 ;
struct V_8 * V_17 = V_6 -> V_7 ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_15 V_20 ;
struct V_21 V_22 ;
struct V_23 V_24 ;
T_2 V_25 = 0 , V_26 = 0 , V_27 = 0 ;
void * V_28 = NULL ;
T_6 V_29 = 0 ;
int V_30 = 1 ;
int V_31 = 0 ;
if ( V_13 < sizeof( V_20 ) ) {
V_27 = - V_32 ;
goto V_33;
}
V_16 = ( const struct V_15 T_3 * ) V_12 ;
if ( F_6 ( & V_20 , V_16 , sizeof( V_20 ) ) ) {
V_27 = - V_34 ;
goto V_33;
}
V_25 = sizeof( V_20 ) ;
switch ( V_20 . type ) {
case V_35 :
V_30 = 0 ;
V_26 = sizeof( V_22 ) ;
V_28 = & V_22 ;
break;
case V_36 :
case V_37 :
V_26 = 0 ;
break;
case V_38 :
case V_39 :
V_26 = sizeof( V_24 ) ;
V_28 = & V_24 ;
break;
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
V_26 = 0 ;
V_29 = V_20 . V_47 ;
break;
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
V_30 = 0 ;
V_31 = 1 ;
V_26 = 0 ;
break;
default:
V_27 = - V_32 ;
goto V_33;
}
if ( V_26 ) {
if ( F_6 ( V_28 , ( void T_3 * ) V_20 . V_47 , V_26 ) ) {
V_27 = - V_34 ;
goto V_33;
}
V_25 += V_26 ;
}
if ( V_30 && ! V_19 ) {
V_27 = - V_32 ;
goto V_33;
}
if ( V_31 && ! F_7 ( V_53 ) ) {
V_27 = - V_54 ;
goto V_33;
}
switch ( V_20 . type ) {
case V_35 :
V_27 = F_8 ( V_6 , & V_22 ) ;
if ( V_27 < 0 )
goto V_33;
V_27 = F_9 ( V_6 ) ;
if ( V_27 )
goto V_33;
V_27 = F_10 ( V_6 ) ;
break;
case V_44 :
V_27 = F_11 ( V_6 , ( void T_3 * ) ( unsigned long )
V_29 , V_20 . V_55 ) ;
break;
case V_40 :
V_27 = F_12 ( V_6 , ( void T_3 * ) ( unsigned long )
V_29 , V_20 . V_55 ) ;
break;
case V_36 :
break;
case V_37 :
if ( V_19 && V_19 -> V_56 )
F_13 ( V_19 -> V_56 ) ;
break;
case V_38 :
V_27 = F_14 ( V_6 , & V_24 ) ;
if ( ! V_27 ) {
unsigned long V_47 ;
V_47 = ( unsigned long ) V_20 . V_47 +
F_15 ( struct V_23 , V_57 ) ;
if ( F_16 ( ( void T_3 * ) V_47 , & V_24 . V_57 ,
sizeof( V_24 . V_57 ) +
sizeof( V_24 . V_58 ) ) )
V_27 = - V_34 ;
}
break;
case V_39 :
V_27 = F_17 ( V_6 , & V_24 ) ;
break;
case V_41 :
V_27 = F_18 ( V_19 , V_17 -> V_59 , ( int ) V_29 ) ;
break;
case V_42 :
V_19 -> V_60 = ( F_19 ( V_19 -> V_60 ) ) V_29 ;
break;
case V_43 :
V_27 = F_20 ( V_19 , V_17 -> V_59 , V_29 ) ;
break;
case V_45 :
if ( F_21 ( V_61 ) )
V_27 = F_22 ( V_19 , V_17 -> V_59 , V_29 ) ;
else
V_27 = - V_54 ;
break;
case V_46 : {
struct V_62 * V_56 ;
struct V_63 * V_64 ;
if ( ! V_19 || ! V_19 -> V_64 || ! V_19 -> V_56 ) {
V_27 = - V_32 ;
break;
}
V_64 = V_19 -> V_64 ;
V_56 = V_19 -> V_56 ;
F_23 (
V_56 -> V_65 , ( V_56 -> V_66 & V_67 ) ,
F_24 ( V_68 ) ) ;
if ( ! ( V_56 -> V_66 & V_67 ) ) {
V_27 = - V_69 ;
break;
}
if ( V_56 -> V_66 & V_70 ) {
F_23 (
V_64 -> V_71 ,
! ( F_25 ( V_64 -> V_66 ) & V_72 ) ,
F_24 ( V_68 ) ) ;
if ( V_64 -> V_66 & V_72 ) {
V_27 = - V_69 ;
break;
}
if ( V_64 -> V_66 & V_73 ) {
V_27 = - V_74 ;
break;
}
F_26 ( V_56 ) ;
V_27 = F_27 ( V_56 ) ;
F_28 ( V_64 , V_75 ,
V_19 -> V_76 ) ;
} else
V_27 = F_29 ( V_56 ) ;
if ( ! V_27 )
F_13 ( V_56 ) ;
break;
}
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
V_27 = F_30 ( & V_20 ) ;
break;
}
if ( V_27 >= 0 )
V_27 = V_25 ;
V_33:
return V_27 ;
}
static T_2 F_31 ( struct V_77 * V_77 , struct V_78 * V_79 )
{
struct V_8 * V_17 = V_77 -> V_80 -> V_7 ;
struct V_81 * V_82 = V_17 -> V_82 ;
struct V_83 * V_84 = V_17 -> V_84 ;
int V_27 = 0 , V_85 = 0 , V_86 = 0 ;
unsigned long V_87 = V_79 -> V_88 ;
if ( ! V_84 || ! V_82 ) {
V_27 = - V_89 ;
goto V_85;
}
if ( ! F_32 ( V_79 ) || ! V_87 ) {
V_27 = - V_32 ;
goto V_85;
}
F_33 ( V_90 , L_1 ,
V_17 -> V_19 -> V_76 , V_17 -> V_59 , V_87 ) ;
if ( F_34 ( & V_82 -> V_91 ) == V_82 -> V_92 ) {
V_27 = - V_93 ;
goto V_85;
}
while ( V_87 ) {
unsigned long V_13 = 0 ;
V_27 = F_35 (
V_77 -> V_80 , (struct V_94 * ) ( V_79 -> V_95 + V_85 ) ,
V_87 , & V_13 ) ;
if ( V_27 )
goto V_85;
V_87 -= V_13 ;
V_85 += V_13 ;
V_86 ++ ;
}
V_85:
return V_27 ? V_27 : V_86 ;
}
static int F_36 ( struct V_5 * V_6 , struct V_96 * V_97 )
{
struct V_8 * V_17 = V_6 -> V_7 ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_63 * V_64 ;
unsigned long V_66 , V_98 ;
T_1 V_1 = V_97 -> V_99 << V_100 ,
V_101 = 0 ;
T_7 V_59 , V_102 = 0 , V_103 = 0 , type ;
T_2 V_104 = 0 ;
int V_27 = 0 ;
T_8 V_76 ;
if ( ! F_1 ( V_1 ) || ! V_19 ||
! ( V_97 -> V_105 & V_106 ) ) {
V_27 = - V_32 ;
goto V_85;
}
V_64 = V_19 -> V_64 ;
V_76 = F_2 ( V_107 , V_1 ) ;
V_59 = F_2 ( V_108 , V_1 ) ;
type = F_2 ( TYPE , V_1 ) ;
if ( V_76 != V_19 -> V_76 || V_59 != V_17 -> V_59 ) {
V_27 = - V_32 ;
goto V_85;
}
V_66 = V_97 -> V_105 ;
switch ( type ) {
case V_109 :
case V_110 :
V_101 = ( ( V_64 -> V_111 + V_112 ) +
( V_19 -> V_56 -> V_113 * F_37 ( 16 ) ) ) +
( type == V_110 ?
( V_114 / 2 ) : 0 ) ;
V_104 = F_38 ( V_19 -> V_56 -> V_115 * V_116 ,
V_117 ) ;
V_66 &= ~ V_118 ;
V_66 |= V_119 | V_120 ;
V_97 -> V_121 = F_39 ( V_97 -> V_121 ) ;
V_102 = 1 ;
break;
case V_122 :
if ( V_66 & V_123 ) {
V_27 = - V_54 ;
goto V_85;
}
V_101 = V_64 -> V_124 [ V_19 -> V_125 ] . V_126 +
( ( ( T_1 ) V_19 -> V_56 -> V_127 -
( T_1 ) V_64 -> V_124 [ V_19 -> V_125 ] . V_128 ) & V_129 ) ;
V_104 = V_117 ;
V_66 &= ~ V_130 ;
V_66 |= V_119 | V_120 ;
V_102 = 1 ;
break;
case V_131 :
V_101 = V_19 -> V_132 ;
V_104 = V_19 -> V_133 ;
break;
case V_134 : {
unsigned long V_47 ;
int V_135 ;
V_104 = V_19 -> V_136 . V_137 ;
if ( ( V_97 -> V_138 - V_97 -> V_139 ) != V_104 ) {
F_40 ( V_64 , L_2 ,
( V_97 -> V_138 - V_97 -> V_139 ) , V_104 ) ;
V_27 = - V_32 ;
goto V_85;
}
if ( V_97 -> V_105 & V_123 ) {
V_27 = - V_54 ;
goto V_85;
}
V_97 -> V_105 &= ~ V_130 ;
V_47 = V_97 -> V_139 ;
for ( V_135 = 0 ; V_135 < V_19 -> V_136 . V_140 ; V_135 ++ ) {
V_27 = F_41 (
V_97 , V_47 ,
V_19 -> V_136 . V_141 [ V_135 ] . V_142 >> V_100 ,
V_19 -> V_136 . V_141 [ V_135 ] . V_55 ,
V_97 -> V_121 ) ;
if ( V_27 < 0 )
goto V_85;
V_47 += V_19 -> V_136 . V_141 [ V_135 ] . V_55 ;
}
V_27 = 0 ;
goto V_85;
}
case V_143 :
V_101 = ( unsigned long )
( V_64 -> V_111 + V_144 )
+ ( V_19 -> V_76 * V_145 ) ;
V_104 = V_117 ;
V_66 |= V_119 | V_120 ;
V_97 -> V_121 = F_42 ( V_97 -> V_121 ) ;
V_102 = 1 ;
break;
case V_146 :
V_101 = ( unsigned long ) ( V_64 -> V_147 +
( ( V_19 -> V_76 - V_64 -> V_148 ) *
V_149 ) ) & V_129 ;
V_104 = V_117 ;
V_66 |= V_150 | V_120 ;
V_103 = 1 ;
break;
case V_151 :
V_101 = F_43 ( ( void * ) V_64 -> V_152 ) ;
V_104 = V_117 ;
V_66 |= V_150 | V_120 ;
break;
case V_153 :
if ( ! F_21 ( V_154 ) ) {
V_27 = - V_32 ;
goto V_85;
}
if ( V_66 & V_123 ) {
V_27 = - V_54 ;
goto V_85;
}
V_101 = V_19 -> V_155 ;
V_104 = V_117 ;
V_66 &= ~ V_130 ;
break;
case V_156 :
V_101 = ( T_1 ) V_19 -> V_157 ;
V_104 = V_117 ;
V_66 |= V_150 | V_120 ;
V_103 = 1 ;
break;
case V_158 :
V_101 = ( T_1 ) V_19 -> V_159 ;
V_104 = V_19 -> V_133 * V_19 -> V_160 ;
V_66 |= V_150 | V_120 ;
V_103 = 1 ;
break;
case V_161 :
V_101 = ( T_1 ) V_19 -> V_162 ;
V_104 = V_19 -> V_136 . V_137 * V_19 -> V_160 ;
V_66 |= V_150 | V_120 ;
V_66 &= ~ V_130 ;
V_103 = 1 ;
break;
case V_163 : {
struct V_83 * V_84 = V_17 -> V_84 ;
if ( ! V_84 ) {
V_27 = - V_34 ;
goto V_85;
}
V_101 = ( T_1 ) V_84 -> V_164 ;
V_104 = F_38 ( sizeof( * V_84 -> V_164 ) * V_84 -> V_165 , V_117 ) ;
V_66 |= V_150 | V_120 ;
V_103 = 1 ;
break;
}
default:
V_27 = - V_32 ;
break;
}
if ( ( V_97 -> V_138 - V_97 -> V_139 ) != V_104 ) {
F_33 ( V_166 , L_3 ,
V_19 -> V_76 , V_17 -> V_59 ,
( V_97 -> V_138 - V_97 -> V_139 ) , V_104 ) ;
V_27 = - V_32 ;
goto V_85;
}
V_97 -> V_105 = V_66 ;
F_33 ( V_166 ,
L_4 ,
V_76 , V_59 , type , V_102 , V_103 , V_101 , V_104 ,
V_97 -> V_138 - V_97 -> V_139 , V_97 -> V_105 ) ;
V_98 = ( unsigned long ) ( V_101 >> V_100 ) ;
if ( V_103 ) {
V_97 -> V_99 = V_98 ;
V_97 -> V_167 = & V_167 ;
V_27 = 0 ;
} else if ( V_102 ) {
V_27 = F_44 ( V_97 , V_97 -> V_139 , V_98 , V_104 ,
V_97 -> V_121 ) ;
} else {
V_27 = F_41 ( V_97 , V_97 -> V_139 , V_98 , V_104 ,
V_97 -> V_121 ) ;
}
V_85:
return V_27 ;
}
static int F_45 ( struct V_96 * V_97 , struct V_168 * V_103 )
{
struct V_169 * V_169 ;
V_169 = F_46 ( ( void * ) ( V_103 -> V_170 << V_100 ) ) ;
if ( ! V_169 )
return V_171 ;
F_47 ( V_169 ) ;
V_103 -> V_169 = V_169 ;
return 0 ;
}
static unsigned int F_48 ( struct V_5 * V_6 , struct V_172 * V_173 )
{
struct V_18 * V_19 ;
unsigned V_174 ;
V_19 = ( (struct V_8 * ) V_6 -> V_7 ) -> V_19 ;
if ( ! V_19 )
V_174 = V_175 ;
else if ( V_19 -> V_60 == V_176 )
V_174 = F_49 ( V_6 , V_173 ) ;
else if ( V_19 -> V_60 == V_177 )
V_174 = F_50 ( V_6 , V_173 ) ;
else
V_174 = V_175 ;
return V_174 ;
}
static int F_51 ( struct V_4 * V_4 , struct V_5 * V_6 )
{
struct V_8 * V_178 = V_6 -> V_7 ;
struct V_18 * V_19 = V_178 -> V_19 ;
struct V_63 * V_64 ;
unsigned long V_66 , * V_179 ;
V_6 -> V_7 = NULL ;
if ( ! V_19 )
goto V_85;
F_33 ( V_166 , L_5 , V_19 -> V_76 , V_178 -> V_59 ) ;
V_64 = V_19 -> V_64 ;
F_52 ( & V_180 ) ;
F_53 () ;
F_54 ( V_178 ) ;
V_179 = V_64 -> V_147 + ( ( V_19 -> V_76 - V_64 -> V_148 ) *
V_149 ) + V_178 -> V_59 ;
* V_179 = 0 ;
if ( -- V_19 -> V_181 ) {
V_19 -> V_182 &= ~ ( 1 << V_178 -> V_59 ) ;
V_19 -> V_183 [ V_178 -> V_59 ] = 0 ;
F_55 ( & V_180 ) ;
goto V_85;
}
F_56 ( & V_64 -> V_184 , V_66 ) ;
F_28 ( V_64 , V_185 |
V_186 |
V_187 |
V_188 |
V_189 |
V_190 , V_19 -> V_76 ) ;
F_57 ( V_64 , V_19 -> V_76 ) ;
F_58 ( V_64 , V_19 -> V_56 -> V_113 , V_191 ,
F_59 ( V_64 , V_19 -> V_56 -> type ) ) ;
F_26 ( V_19 -> V_56 ) ;
V_19 -> V_192 = 0 ;
F_60 ( & V_64 -> V_184 , V_66 ) ;
V_64 -> V_193 [ V_19 -> V_76 ] = NULL ;
V_19 -> V_194 = 0 ;
V_19 -> V_195 = 0 ;
V_19 -> V_196 = 0 ;
V_19 -> V_197 = 0 ;
V_19 -> V_198 = 0 ;
F_61 ( V_19 ) ;
F_62 ( V_64 , V_19 -> V_76 ) ;
if ( V_19 -> V_199 )
F_63 ( V_19 ) ;
V_200 . V_201 -- ;
V_64 -> V_202 ++ ;
F_55 ( & V_180 ) ;
F_64 ( V_64 , V_19 ) ;
V_85:
F_65 ( V_178 ) ;
return 0 ;
}
static T_1 F_43 ( void * V_47 )
{
struct V_169 * V_169 ;
T_1 V_203 = 0 ;
V_169 = F_46 ( V_47 ) ;
if ( V_169 )
V_203 = F_66 ( V_169 ) << V_100 ;
return V_203 ;
}
static int F_8 ( struct V_5 * V_6 , struct V_21 * V_22 )
{
int V_204 , V_27 = 0 ;
unsigned V_205 , V_206 , V_207 = V_208 ;
V_205 = V_22 -> V_209 >> 16 ;
if ( V_205 != V_210 ) {
V_27 = - V_74 ;
goto V_85;
}
V_206 = V_22 -> V_209 & 0xffff ;
if ( V_22 -> V_211 < V_212 )
V_207 = V_22 -> V_211 ;
F_52 ( & V_180 ) ;
if ( V_22 -> V_160 )
V_27 = F_67 ( V_6 , V_22 ) ;
if ( ! V_27 ) {
V_204 = F_68 ( F_69 ( V_6 ) ) - V_213 ;
V_27 = F_70 ( V_6 , V_22 , V_204 - 1 , V_207 ) ;
}
F_55 ( & V_180 ) ;
V_85:
return V_27 ;
}
static int F_71 ( struct V_63 * V_64 )
{
struct V_214 * V_215 = V_64 -> V_216 ;
return F_72 ( V_215 ) == V_217 ;
}
static int F_70 ( struct V_5 * V_6 , struct V_21 * V_22 ,
int V_218 , unsigned V_207 )
{
struct V_63 * V_64 = NULL ;
int V_27 = 0 , V_219 , V_220 , V_221 , V_222 ;
V_219 = F_73 ( & V_220 , & V_221 ) ;
if ( ! V_220 ) {
V_27 = - V_223 ;
goto V_85;
}
if ( ! V_221 ) {
V_27 = - V_224 ;
goto V_85;
}
if ( V_218 >= 0 ) {
V_64 = F_74 ( V_218 ) ;
if ( ! V_64 )
V_27 = - V_74 ;
else if ( ! V_64 -> V_202 )
V_27 = - V_225 ;
} else {
struct V_63 * V_226 ;
if ( V_207 == V_208 ) {
unsigned free = 0U ;
for ( V_222 = 0 ; V_222 < V_219 ; V_222 ++ ) {
V_226 = F_74 ( V_222 ) ;
if ( ! V_226 )
continue;
if ( ! F_71 ( V_226 ) )
continue;
if ( V_226 -> V_202 &&
V_226 -> V_202 > free ) {
V_64 = V_226 ;
free = V_226 -> V_202 ;
}
}
} else {
for ( V_222 = 0 ; V_222 < V_219 ; V_222 ++ ) {
V_226 = F_74 ( V_222 ) ;
if ( ! V_226 )
continue;
if ( ! F_71 ( V_226 ) )
continue;
if ( V_226 -> V_202 ) {
V_64 = V_226 ;
break;
}
}
}
if ( ! V_64 )
V_27 = - V_225 ;
}
V_85:
return V_27 ? V_27 : F_75 ( V_6 , V_64 , V_22 ) ;
}
static int F_67 ( struct V_5 * V_6 ,
const struct V_21 * V_22 )
{
int V_219 , V_227 , V_135 ;
int V_27 = 0 ;
struct V_8 * V_17 = V_6 -> V_7 ;
V_219 = F_73 ( NULL , NULL ) ;
for ( V_227 = 0 ; V_227 < V_219 ; V_227 ++ ) {
struct V_63 * V_64 = F_74 ( V_227 ) ;
if ( ! ( V_64 && ( V_64 -> V_66 & V_228 ) && V_64 -> V_229 ) )
continue;
for ( V_135 = V_64 -> V_148 ; V_135 < V_64 -> V_230 ; V_135 ++ ) {
struct V_18 * V_19 = V_64 -> V_193 [ V_135 ] ;
if ( ! V_19 || ! V_19 -> V_181 )
continue;
if ( memcmp ( V_19 -> V_231 , V_22 -> V_231 ,
sizeof( V_19 -> V_231 ) ) ||
V_19 -> V_232 != F_76 ( F_77 () ) ||
V_19 -> V_233 != V_22 -> V_233 ||
V_19 -> V_160 != V_22 -> V_160 )
continue;
if ( V_19 -> V_209 != V_22 -> V_209 ||
V_19 -> V_181 >= V_19 -> V_160 ) {
V_27 = - V_32 ;
goto V_85;
}
V_17 -> V_19 = V_19 ;
V_17 -> V_59 = V_19 -> V_181 ++ ;
V_19 -> V_183 [ V_17 -> V_59 ] = V_234 -> V_192 ;
V_19 -> V_182 |= 1 << V_17 -> V_59 ;
V_27 = 1 ;
goto V_85;
}
}
V_85:
return V_27 ;
}
static int F_75 ( struct V_5 * V_6 , struct V_63 * V_64 ,
struct V_21 * V_22 )
{
struct V_8 * V_17 = V_6 -> V_7 ;
struct V_18 * V_19 ;
unsigned V_76 ;
int V_27 ;
if ( V_64 -> V_66 & V_72 ) {
return - V_89 ;
}
for ( V_76 = V_64 -> V_148 ; V_76 < V_64 -> V_230 ; V_76 ++ )
if ( ! V_64 -> V_193 [ V_76 ] )
break;
if ( V_76 == V_64 -> V_230 )
return - V_225 ;
V_19 = F_78 ( V_64 -> V_216 , V_76 ) ;
if ( ! V_19 ) {
F_40 ( V_64 ,
L_6 ) ;
return - V_11 ;
}
V_19 -> V_56 = F_79 ( V_64 , V_235 , V_19 -> V_236 ,
V_19 -> V_125 ) ;
if ( ! V_19 -> V_56 )
return - V_11 ;
F_33 ( V_166 , L_7 , V_19 -> V_56 -> V_237 ,
V_19 -> V_56 -> V_113 ) ;
V_27 = F_27 ( V_19 -> V_56 ) ;
if ( V_27 )
return V_27 ;
if ( V_22 -> V_160 && ! V_17 -> V_59 ) {
V_27 = F_80 ( V_19 , V_22 ) ;
if ( V_27 )
return V_27 ;
}
V_19 -> V_209 = V_22 -> V_209 ;
V_19 -> V_192 = V_234 -> V_192 ;
V_19 -> V_66 = F_81 ( V_238 ) ;
F_82 ( & V_19 -> V_239 ) ;
F_83 ( V_19 -> V_240 , V_234 -> V_240 , sizeof( V_19 -> V_240 ) ) ;
memcpy ( V_19 -> V_231 , V_22 -> V_231 , sizeof( V_19 -> V_231 ) ) ;
V_19 -> V_232 = F_76 ( F_77 () ) ;
F_84 ( & V_19 -> V_241 ) ;
F_85 ( & V_19 -> V_242 ) ;
V_200 . V_201 ++ ;
V_64 -> V_202 -- ;
V_17 -> V_19 = V_19 ;
return 0 ;
}
static int F_80 ( struct V_18 * V_19 ,
const struct V_21 * V_22 )
{
int V_27 = 0 ;
unsigned V_243 ;
V_243 = V_22 -> V_160 ;
if ( V_243 > V_149 ) {
V_27 = - V_32 ;
goto V_33;
}
V_19 -> V_160 = V_22 -> V_160 ;
V_19 -> V_233 = V_22 -> V_233 ;
V_19 -> V_182 = 1 ;
V_19 -> V_244 = 1 ;
F_86 ( V_245 , & V_19 -> V_198 ) ;
V_33:
return V_27 ;
}
static int F_87 ( struct V_18 * V_19 )
{
int V_27 = 0 ;
unsigned V_243 = V_19 -> V_160 ;
V_19 -> V_157 = F_88 ( V_117 ) ;
if ( ! V_19 -> V_157 ) {
V_27 = - V_11 ;
goto V_33;
}
V_19 -> V_159 = F_88 ( V_19 -> V_133 *
V_243 ) ;
if ( ! V_19 -> V_159 ) {
V_27 = - V_11 ;
goto V_246;
}
V_19 -> V_162 = F_88 ( V_19 -> V_136 . V_137 *
V_243 ) ;
if ( ! V_19 -> V_162 ) {
V_27 = - V_11 ;
goto V_247;
}
goto V_33;
V_247:
F_89 ( V_19 -> V_159 ) ;
V_246:
F_89 ( V_19 -> V_157 ) ;
V_19 -> V_157 = NULL ;
V_33:
return V_27 ;
}
static int F_10 ( struct V_5 * V_6 )
{
int V_27 ;
unsigned int V_248 = 0 ;
struct V_8 * V_17 = V_6 -> V_7 ;
struct V_18 * V_19 = V_17 -> V_19 ;
if ( ! F_90 ( V_249 , & V_19 -> V_198 ) ) {
V_27 = - V_34 ;
goto V_85;
}
if ( V_17 -> V_59 ) {
V_27 = F_91 ( V_19 -> V_239 ,
! F_90 ( V_245 ,
& V_19 -> V_198 ) ) ;
goto V_85;
}
V_19 -> V_250 = 0 ;
V_19 -> V_251 = 0 ;
if ( V_19 -> V_252 )
F_92 ( V_19 ) ;
F_93 ( V_19 -> V_64 , V_19 -> V_76 , V_19 -> V_232 ) ;
V_248 = V_75 ;
if ( F_94 ( V_19 -> V_66 , V_253 ) )
V_248 |= V_254 ;
if ( ! F_94 ( V_19 -> V_66 , V_255 ) )
V_248 |= V_256 ;
if ( F_94 ( V_19 -> V_66 , V_257 ) )
V_248 |= V_258 ;
if ( F_94 ( V_19 -> V_66 , V_259 ) )
V_248 |= V_260 ;
if ( F_94 ( V_19 -> V_66 , V_154 ) )
V_248 |= V_261 ;
F_28 ( V_19 -> V_64 , V_248 , V_19 -> V_76 ) ;
if ( V_19 -> V_160 ) {
F_95 ( V_245 , & V_19 -> V_198 ) ;
F_96 ( & V_19 -> V_239 ) ;
}
V_27 = 0 ;
V_85:
return V_27 ;
}
static int F_11 ( struct V_5 * V_6 , void T_3 * V_262 , T_9 V_55 )
{
struct V_263 V_264 ;
struct V_8 * V_17 = V_6 -> V_7 ;
struct V_18 * V_19 = V_17 -> V_19 ;
int V_27 = 0 ;
memset ( & V_264 , 0 , sizeof( V_264 ) ) ;
V_27 = F_97 ( V_19 , & V_264 ) ;
if ( V_27 < 0 )
goto V_85;
V_264 . V_265 = F_98 () ;
V_264 . V_266 = V_19 -> V_64 -> V_266 ;
V_264 . V_76 = V_19 -> V_76 ;
V_264 . V_59 = V_17 -> V_59 ;
V_264 . V_267 = F_99 ( V_19 -> V_136 . V_268 ,
V_19 -> V_64 -> V_269 . V_270 ) +
V_19 -> V_271 ;
V_264 . V_115 = V_19 -> V_56 -> V_115 ;
V_264 . V_272 = V_19 -> V_125 ;
V_264 . V_273 = V_17 -> V_10 ;
V_264 . V_274 = V_19 -> V_56 -> V_113 ;
V_264 . V_275 = V_19 -> V_136 . V_268 ;
V_264 . V_276 = V_19 -> V_276 ;
V_264 . V_277 = V_19 -> V_236 << 2 ;
V_264 . V_278 = V_17 -> V_84 -> V_165 ;
V_264 . V_279 = V_19 -> V_136 . V_280 ;
F_100 ( V_19 -> V_64 , V_19 -> V_76 , V_17 -> V_59 , V_264 ) ;
if ( F_16 ( V_262 , & V_264 , sizeof( V_264 ) ) )
V_27 = - V_34 ;
V_85:
return V_27 ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_8 * V_17 = V_6 -> V_7 ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_63 * V_64 = V_19 -> V_64 ;
int V_27 = 0 ;
if ( ! V_19 -> V_160 || ! V_17 -> V_59 ) {
V_27 = F_101 ( V_19 -> V_56 ) ;
if ( V_27 )
goto V_85;
V_27 = F_102 ( V_64 , V_19 ) ;
if ( V_27 )
goto V_85;
V_27 = F_103 ( V_19 ) ;
if ( V_27 )
goto V_85;
if ( V_19 -> V_160 && ! V_17 -> V_59 ) {
V_27 = F_87 ( V_19 ) ;
if ( V_27 )
goto V_85;
}
V_19 -> V_199 = F_104 ( V_19 -> V_271 *
sizeof( struct V_169 * * ) ) ;
if ( ! V_19 -> V_199 ) {
V_27 = - V_11 ;
goto V_85;
}
V_19 -> V_281 = F_104 ( V_19 -> V_271 *
sizeof( * V_19 -> V_281 ) ) ;
if ( ! V_19 -> V_281 ) {
V_27 = - V_11 ;
goto V_85;
}
F_105 ( & V_19 -> V_282 , 0 ) ;
V_19 -> V_283 = V_19 -> V_271 /
V_64 -> V_269 . V_270 ;
V_19 -> V_284 = V_19 -> V_283 / V_285 +
! ! ( V_19 -> V_283 % V_285 ) ;
V_19 -> V_286 = F_106 ( V_19 -> V_284 *
sizeof( * V_19 -> V_286 ) ,
V_9 , V_19 -> V_125 ) ;
if ( ! V_19 -> V_286 ) {
V_27 = - V_11 ;
goto V_85;
}
if ( V_19 -> V_283 % V_285 )
V_19 -> V_286 [ V_19 -> V_284 - 1 ] =
~ ( ( 1ULL << ( V_19 -> V_283 %
V_285 ) ) - 1 ) ;
F_107 ( V_19 -> V_76 , V_17 -> V_59 , 0 ,
V_19 -> V_286 , V_19 -> V_284 ) ;
}
V_27 = F_108 ( V_19 , V_6 ) ;
if ( V_27 )
goto V_85;
F_86 ( V_249 , & V_19 -> V_198 ) ;
V_85:
return V_27 ;
}
static int F_12 ( struct V_5 * V_6 , void T_3 * V_262 , T_9 V_55 )
{
struct V_287 V_288 ;
struct V_8 * V_17 = V_6 -> V_7 ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_63 * V_64 = V_19 -> V_64 ;
T_2 V_289 ;
unsigned V_14 ;
int V_27 = 0 ;
F_109 ( V_19 -> V_64 , V_19 ) ;
memset ( & V_288 , 0 , sizeof( V_288 ) ) ;
V_288 . V_290 = V_64 -> V_291 ;
V_288 . V_292 = V_293 ;
V_288 . V_294 = V_295 ;
V_288 . V_232 = V_19 -> V_232 ;
V_14 = ( ( T_1 ) V_19 -> V_56 -> V_127 -
( T_1 ) V_64 -> V_124 [ V_19 -> V_125 ] . V_128 ) % V_117 ;
V_288 . V_296 = F_110 ( V_122 , V_19 -> V_76 ,
V_17 -> V_59 , V_14 ) ;
V_288 . V_297 = F_110 ( V_109 , V_19 -> V_76 ,
V_17 -> V_59 ,
V_19 -> V_56 -> V_298 ) ;
V_288 . V_299 = F_110 ( V_110 ,
V_19 -> V_76 ,
V_17 -> V_59 ,
V_19 -> V_56 -> V_298 ) ;
V_288 . V_300 = F_110 ( V_131 , V_19 -> V_76 ,
V_17 -> V_59 ,
V_19 -> V_301 ) ;
V_288 . V_302 = F_110 ( V_134 , V_19 -> V_76 ,
V_17 -> V_59 ,
V_19 -> V_136 . V_267 [ 0 ] . V_142 ) ;
V_288 . V_303 = F_110 ( V_163 , V_19 -> V_76 ,
V_17 -> V_59 , 0 ) ;
V_288 . V_304 = F_110 ( V_143 , V_19 -> V_76 ,
V_17 -> V_59 , 0 ) ;
V_14 = F_111 ( ( ( ( V_19 -> V_76 - V_64 -> V_148 ) *
V_149 ) + V_17 -> V_59 ) *
sizeof( * V_64 -> V_147 ) ) ;
V_288 . V_305 = F_110 ( V_146 , V_19 -> V_76 ,
V_17 -> V_59 ,
V_14 ) ;
V_288 . V_306 = F_110 ( V_151 , V_19 -> V_76 ,
V_17 -> V_59 ,
V_64 -> V_152 ) ;
if ( F_21 ( V_154 ) )
V_288 . V_307 = F_110 ( V_153 , V_19 -> V_76 ,
V_17 -> V_59 , 0 ) ;
if ( V_19 -> V_160 ) {
V_288 . V_157 = F_110 ( V_156 ,
V_19 -> V_76 ,
V_17 -> V_59 , 0 ) ;
V_288 . V_308 = F_110 ( V_158 ,
V_19 -> V_76 ,
V_17 -> V_59 , 0 ) ;
V_288 . V_162 = F_110 ( V_161 ,
V_19 -> V_76 ,
V_17 -> V_59 , 0 ) ;
}
V_289 = ( V_55 < sizeof( V_288 ) ) ? V_55 : sizeof( V_288 ) ;
if ( F_16 ( V_262 , & V_288 , V_289 ) )
V_27 = - V_34 ;
return V_27 ;
}
static unsigned int F_49 ( struct V_5 * V_6 ,
struct V_172 * V_173 )
{
struct V_8 * V_17 = V_6 -> V_7 ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_63 * V_64 = V_19 -> V_64 ;
unsigned V_174 ;
F_112 ( V_6 , & V_19 -> V_239 , V_173 ) ;
F_113 ( & V_64 -> V_184 ) ;
if ( V_19 -> V_250 != V_19 -> V_251 ) {
V_174 = V_309 | V_310 ;
V_19 -> V_251 = V_19 -> V_250 ;
} else {
V_174 = 0 ;
F_86 ( V_311 , & V_19 -> V_198 ) ;
}
F_114 ( & V_64 -> V_184 ) ;
return V_174 ;
}
static unsigned int F_50 ( struct V_5 * V_6 ,
struct V_172 * V_173 )
{
struct V_8 * V_17 = V_6 -> V_7 ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_63 * V_64 = V_19 -> V_64 ;
unsigned V_174 ;
F_112 ( V_6 , & V_19 -> V_239 , V_173 ) ;
F_113 ( & V_64 -> V_184 ) ;
if ( F_115 ( V_19 ) ) {
F_86 ( V_312 , & V_19 -> V_198 ) ;
F_28 ( V_64 , V_313 , V_19 -> V_76 ) ;
V_174 = 0 ;
} else
V_174 = V_309 | V_310 ;
F_114 ( & V_64 -> V_184 ) ;
return V_174 ;
}
int F_116 ( struct V_214 * V_215 , const int V_314 )
{
struct V_18 * V_19 ;
struct V_63 * V_64 = V_215 -> V_64 ;
unsigned V_76 ;
int V_27 = 0 ;
unsigned long V_66 ;
if ( ! V_64 -> V_147 ) {
V_27 = - V_32 ;
goto V_85;
}
F_56 ( & V_64 -> V_184 , V_66 ) ;
for ( V_76 = V_64 -> V_148 ; V_76 < V_64 -> V_230 ;
V_76 ++ ) {
V_19 = V_64 -> V_193 [ V_76 ] ;
if ( V_19 ) {
unsigned long * V_315 = V_64 -> V_147 +
( V_19 -> V_76 - V_64 -> V_148 ) *
V_149 ;
int V_135 ;
F_86 ( V_314 , V_315 ) ;
for ( V_135 = 1 ; V_135 < V_19 -> V_160 ; V_135 ++ )
F_86 ( V_314 , V_315 + V_135 ) ;
}
}
F_60 ( & V_64 -> V_184 , V_66 ) ;
V_85:
return V_27 ;
}
static int F_18 ( struct V_18 * V_19 , unsigned V_59 ,
int V_316 )
{
struct V_63 * V_64 = V_19 -> V_64 ;
unsigned int V_317 ;
if ( V_59 )
goto V_33;
if ( V_316 ) {
if ( V_19 -> V_252 )
F_92 ( V_19 ) ;
V_317 = V_75 ;
} else
V_317 = V_185 ;
F_28 ( V_64 , V_317 , V_19 -> V_76 ) ;
V_33:
return 0 ;
}
static int F_20 ( struct V_18 * V_19 , int V_59 ,
unsigned long V_147 )
{
int V_135 ;
struct V_63 * V_64 = V_19 -> V_64 ;
unsigned long * V_315 ;
if ( ! V_64 -> V_147 )
return 0 ;
V_315 = V_64 -> V_147 + ( ( V_19 -> V_76 - V_64 -> V_148 ) *
V_149 ) + V_59 ;
for ( V_135 = 0 ; V_135 <= V_318 ; V_135 ++ ) {
if ( ! F_90 ( V_135 , & V_147 ) )
continue;
F_95 ( V_135 , V_315 ) ;
}
return 0 ;
}
static inline T_7 F_117 ( T_1 V_319 )
{
return V_319 ? F_118 ( V_319 ) : sizeof( V_319 ) * 8 ;
}
static inline unsigned F_119 ( unsigned long V_320 , T_8 * V_321 )
{
unsigned free ;
T_8 V_322 = * V_321 ;
if ( V_322 >= V_285 )
return 0 ;
V_320 &= ~ ( ( 1ULL << V_322 ) - 1 ) ;
free = F_117 ( V_320 ) - V_322 ;
while ( ! free && V_322 < V_285 ) {
V_320 &= ~ ( 1ULL << V_322 ) ;
free = F_117 ( V_320 ) - ++ V_322 ;
}
* V_321 = V_322 ;
return free ;
}
static int F_14 ( struct V_5 * V_6 , struct V_23 * V_24 )
{
int V_27 = 0 ;
struct V_8 * V_17 = V_6 -> V_7 ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_63 * V_64 = V_19 -> V_64 ;
unsigned V_323 , V_324 = 0 , V_325 , V_326 , V_327 ,
V_328 = V_19 -> V_271 / 2 ;
struct V_169 * * V_329 ;
unsigned long V_330 , V_331 [ V_19 -> V_284 ] ;
T_10 * V_142 ;
T_11 V_332 [ V_328 ] , V_333 = 0 , V_282 ;
T_8 V_334 , V_335 , V_322 , V_57 = 0 ;
V_330 = V_24 -> V_330 ;
if ( F_111 ( V_330 ) ) {
V_27 = - V_32 ;
goto V_33;
}
V_325 = F_120 ( V_330 , V_24 -> V_58 ) ;
if ( ! V_325 ) {
V_27 = - V_32 ;
goto V_33;
}
if ( ! F_121 ( V_336 , ( void T_3 * ) V_330 ,
V_325 * V_117 ) ) {
F_40 ( V_64 , L_8 ,
( void * ) V_330 , V_325 ) ;
V_27 = - V_34 ;
goto V_33;
}
memset ( V_331 , 0 , sizeof( V_331 [ 0 ] ) * V_19 -> V_284 ) ;
memset ( V_332 , 0 , sizeof( V_332 [ 0 ] ) * V_328 ) ;
V_327 = V_19 -> V_271 / V_64 -> V_269 . V_270 ;
V_282 = F_34 ( & V_19 -> V_282 ) ;
V_334 = ( V_282 >> 16 ) & 0xffff ;
V_322 = V_282 & 0xffff ;
for ( V_324 = 0 , V_335 = 0 ;
V_324 < V_325 && V_335 <= V_19 -> V_284 ; ) {
T_1 V_135 , V_14 = 0 ;
unsigned free , V_337 , V_338 = 0 , V_339 ;
T_8 V_340 ;
F_122 ( & V_19 -> V_341 ) ;
if ( V_19 -> V_286 [ V_334 ] == - 1ULL ||
V_322 >= V_285 ) {
V_334 = ( V_334 + 1 ) % V_19 -> V_284 ;
V_335 ++ ;
V_322 = 0 ;
F_123 ( & V_19 -> V_341 ) ;
continue;
}
V_326 = ( ( V_325 - V_324 ) / V_64 -> V_269 . V_270 ) +
! ! ( ( V_325 - V_324 ) % V_64 -> V_269 . V_270 ) ;
free = F_119 ( V_19 -> V_286 [ V_334 ] , & V_322 ) ;
if ( ! free ) {
F_123 ( & V_19 -> V_341 ) ;
continue;
}
V_339 = F_124 ( free , V_326 ) ;
V_331 [ V_334 ] |= ( ( 1ULL << V_339 ) - 1 ) << V_322 ;
V_19 -> V_286 [ V_334 ] |= V_331 [ V_334 ] ;
F_123 ( & V_19 -> V_341 ) ;
V_14 = ( ( V_334 * V_285 ) + V_322 ) *
V_64 -> V_269 . V_270 ;
V_329 = V_19 -> V_199 + V_14 ;
V_142 = V_19 -> V_281 + V_14 ;
V_323 = V_19 -> V_342 + V_14 ;
V_337 = F_124 ( ( V_339 * V_64 -> V_269 . V_270 ) ,
( V_325 - V_324 ) ) ;
V_27 = F_125 ( V_330 + ( V_324 * V_117 ) ,
V_337 , true , V_329 ) ;
if ( V_27 ) {
F_126 ( V_64 ,
L_9 ,
( void * ) V_330 , V_337 , - V_27 ) ;
F_122 ( & V_19 -> V_341 ) ;
V_19 -> V_286 [ V_334 ] &=
~ ( ( ( 1ULL << V_339 ) - 1 ) << V_322 ) ;
F_123 ( & V_19 -> V_341 ) ;
goto V_85;
}
V_326 = ( V_337 / V_64 -> V_269 . V_270 ) +
! ! ( V_337 % V_64 -> V_269 . V_270 ) ;
for ( V_135 = 0 , V_340 = 0 ; V_340 < V_326 ; V_135 ++ , V_340 ++ ) {
unsigned V_343 ;
T_11 V_344 = 0 , V_345 ;
for ( V_343 = 0 ; V_343 < V_64 -> V_269 . V_270 &&
V_338 < V_337 ; V_343 ++ , V_338 ++ , V_323 ++ ) {
V_345 = V_117 ;
V_142 [ V_338 ] = F_127 ( V_64 -> V_346 ,
V_329 [ V_338 ] , 0 ,
V_345 , V_347 ) ;
F_128 ( V_19 -> V_76 ,
V_17 -> V_59 ,
V_323 , V_330 ,
V_142 [ V_338 ] ,
V_329 [ V_338 ] ) ;
F_129 ( V_64 , V_323 , V_348 ,
V_142 [ V_338 ] ,
F_130 ( V_345 >> V_100 ) + 1 ) ;
V_344 += V_345 >> V_100 ;
F_131 ( V_332 [ V_333 ] , V_349 , V_344 ) ;
if ( ! ( V_323 % 2 ) ) {
V_332 [ V_333 ] |=
F_132 ( V_350 ,
( V_323 - V_19 -> V_342 )
/ 2 ) ;
V_332 [ V_333 ] |=
F_132 ( V_351 , 1 ) ;
V_57 ++ ;
} else {
V_332 [ V_333 ] |=
F_132 ( V_351 , 2 ) ;
V_344 = 0 ;
V_333 ++ ;
}
}
F_53 () ;
}
V_324 += V_337 ;
F_105 ( & V_19 -> V_282 ,
( ( ( V_334 & 0xffffff ) << 16 ) |
( ( V_322 + V_339 ) & 0xffffff ) ) ) ;
}
F_107 ( V_19 -> V_76 , V_17 -> V_59 , 0 , V_19 -> V_286 ,
V_19 -> V_284 ) ;
V_85:
if ( V_324 ) {
if ( F_16 ( ( void T_3 * ) ( unsigned long ) V_24 -> V_332 ,
V_332 , sizeof( V_332 [ 0 ] ) * V_57 ) ) {
V_27 = - V_34 ;
goto V_85;
}
if ( F_16 ( ( void T_3 * ) ( unsigned long ) V_24 -> V_331 ,
V_331 , sizeof( V_331 [ 0 ] ) * V_19 -> V_284 ) )
V_27 = - V_34 ;
}
V_33:
V_24 -> V_58 = V_324 * V_117 ;
V_24 -> V_57 = V_57 ;
return V_27 ;
}
static int F_17 ( struct V_5 * V_6 , struct V_23 * V_24 )
{
struct V_8 * V_17 = V_6 -> V_7 ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_63 * V_64 = V_19 -> V_64 ;
unsigned long V_331 [ V_19 -> V_284 ] ;
struct V_169 * * V_329 ;
T_10 * V_142 ;
T_8 V_335 , V_322 , V_323 ;
int V_27 = 0 ;
if ( F_6 ( & V_331 , ( void T_3 * ) ( unsigned long )
V_24 -> V_331 ,
sizeof( V_331 [ 0 ] ) * V_19 -> V_284 ) ) {
V_27 = - V_34 ;
goto V_85;
}
for ( V_335 = 0 ; V_335 < V_19 -> V_284 ; V_335 ++ ) {
unsigned long V_320 ;
V_322 = 0 ;
if ( ! V_331 [ V_335 ] )
continue;
V_320 = V_331 [ V_335 ] ;
while ( ( V_322 = F_117 ( V_320 ) ) < V_285 ) {
int V_135 , V_352 = 0 ;
struct V_169 * V_353 [ V_64 -> V_269 . V_270 ] ;
unsigned V_14 = ( ( V_335 * V_285 ) + V_322 ) *
V_64 -> V_269 . V_270 ;
V_329 = V_19 -> V_199 + V_14 ;
V_142 = V_19 -> V_281 + V_14 ;
V_323 = V_19 -> V_342 + V_14 ;
for ( V_135 = 0 ; V_135 < V_64 -> V_269 . V_270 ;
V_135 ++ , V_323 ++ ) {
if ( V_329 [ V_135 ] ) {
F_129 ( V_64 , V_323 , V_354 ,
0 , 0 ) ;
F_133 ( V_19 -> V_76 ,
V_17 -> V_59 ,
V_323 , V_142 [ V_135 ] ,
V_329 [ V_135 ] ) ;
F_134 ( V_64 -> V_346 , V_142 [ V_135 ] ,
V_117 , V_347 ) ;
V_353 [ V_352 ] = V_329 [ V_135 ] ;
V_329 [ V_135 ] = NULL ;
V_352 ++ ;
V_142 [ V_135 ] = 0 ;
}
}
F_53 () ;
F_135 ( V_353 , V_352 , true ) ;
F_95 ( V_322 , & V_19 -> V_286 [ V_335 ] ) ;
V_320 &= ~ ( 1ULL << V_322 ) ;
}
}
F_107 ( V_19 -> V_76 , V_17 -> V_59 , 1 , V_19 -> V_286 ,
V_19 -> V_284 ) ;
V_85:
return V_27 ;
}
static void F_63 ( struct V_18 * V_19 )
{
struct V_63 * V_64 = V_19 -> V_64 ;
unsigned V_323 ;
F_126 ( V_64 , L_10 ,
V_19 -> V_76 ) ;
for ( V_323 = 0 ; V_323 < V_19 -> V_271 ; V_323 ++ ) {
struct V_169 * V_355 = V_19 -> V_199 [ V_323 ] ;
T_10 V_142 ;
if ( ! V_355 )
continue;
V_142 = V_19 -> V_281 [ V_323 ] ;
V_19 -> V_281 [ V_323 ] = 0 ;
V_19 -> V_199 [ V_323 ] = NULL ;
F_134 ( V_64 -> V_346 , V_142 , V_117 , V_347 ) ;
F_135 ( & V_355 , 1 , true ) ;
}
}
static int F_22 ( struct V_18 * V_19 , unsigned V_59 ,
T_8 V_356 )
{
int V_27 = - V_357 , V_135 , V_358 = 0 ;
struct V_214 * V_215 = V_19 -> V_215 ;
struct V_63 * V_64 = V_19 -> V_64 ;
if ( V_356 == V_359 || V_356 == V_360 ) {
V_27 = - V_32 ;
goto V_85;
}
for ( V_135 = 0 ; V_135 < F_136 ( V_215 -> V_361 ) ; V_135 ++ )
if ( V_356 == V_215 -> V_361 [ V_135 ] ) {
V_358 = 1 ;
break;
}
if ( V_358 )
V_27 = F_137 ( V_64 , V_19 -> V_76 , V_356 ) ;
V_85:
return V_27 ;
}
static int F_138 ( struct V_4 * V_4 , struct V_5 * V_362 )
{
struct V_63 * V_64 ;
V_64 = F_139 ( V_4 -> V_363 , struct V_63 , V_364 ) ;
V_362 -> V_7 = V_64 ;
return 0 ;
}
static int F_140 ( struct V_4 * V_4 , struct V_5 * V_362 )
{
return 0 ;
}
static T_5 F_141 ( struct V_5 * V_362 , T_5 V_14 , int V_365 )
{
struct V_63 * V_64 = V_362 -> V_7 ;
switch ( V_365 ) {
case V_366 :
break;
case V_367 :
V_14 += V_362 -> V_368 ;
break;
case V_369 :
V_14 = ( ( V_64 -> V_370 - V_64 -> V_229 ) + V_371 ) -
V_14 ;
break;
default:
return - V_32 ;
}
if ( V_14 < 0 )
return - V_32 ;
if ( V_14 >= ( V_64 -> V_370 - V_64 -> V_229 ) + V_371 )
return - V_32 ;
V_362 -> V_368 = V_14 ;
return V_362 -> V_368 ;
}
static T_2 F_142 ( struct V_5 * V_362 , char T_3 * V_372 , T_4 V_13 ,
T_5 * V_368 )
{
struct V_63 * V_64 = V_362 -> V_7 ;
void T_12 * V_373 = V_64 -> V_229 ;
unsigned long V_374 , V_375 ,
V_376 = ( V_64 -> V_370 - V_64 -> V_229 ) ;
T_1 V_12 ;
if ( ( V_13 % 8 ) != 0 )
return - V_32 ;
if ( ( * V_368 % 8 ) != 0 )
return - V_32 ;
if ( ( unsigned long ) V_372 % 8 != 0 )
return - V_32 ;
if ( * V_368 + V_13 > ( V_376 + V_371 ) )
return - V_32 ;
if ( * V_368 < V_376 )
V_373 += * V_368 ;
V_375 = * V_368 ;
for ( V_374 = 0 ; V_374 < V_13 ; V_374 += 8 , V_375 += 8 ) {
if ( F_143 ( V_375 ) ) {
if ( F_144 ( V_64 , V_375 , ( T_1 * ) & V_12 ) )
break;
}
else if ( V_375 == V_377
|| V_375 == V_378
|| V_375 == V_379
|| V_375 == V_380
|| V_375 == V_381
|| V_375 == V_382 )
V_12 = 0 ;
else if ( V_375 >= V_376 ) {
if ( F_145 ( V_64 ,
( T_11 ) ( V_375 - V_376 ) ,
sizeof( V_12 ) , & V_12 ) )
break;
} else
V_12 = F_146 ( V_373 + V_374 ) ;
if ( F_147 ( V_12 , ( unsigned long T_3 * ) ( V_372 + V_374 ) ) )
break;
}
* V_368 += V_374 ;
return V_374 ;
}
static T_2 F_148 ( struct V_5 * V_362 , const char T_3 * V_372 ,
T_4 V_13 , T_5 * V_368 )
{
struct V_63 * V_64 = V_362 -> V_7 ;
void T_12 * V_373 ;
unsigned long V_374 , V_12 , V_375 ;
int V_383 ;
if ( ( V_13 % 8 ) != 0 )
return - V_32 ;
if ( ( * V_368 % 8 ) != 0 )
return - V_32 ;
if ( ( unsigned long ) V_372 % 8 != 0 )
return - V_32 ;
if ( * V_368 + V_13 > V_64 -> V_370 - V_64 -> V_229 )
return - V_32 ;
V_373 = ( void T_12 * ) V_64 -> V_229 + * V_368 ;
V_375 = * V_368 ;
V_383 = 0 ;
for ( V_374 = 0 ; V_374 < V_13 ; V_374 += 8 , V_375 += 8 ) {
if ( F_149 ( V_12 , ( unsigned long T_3 * ) ( V_372 + V_374 ) ) )
break;
if ( F_143 ( V_375 ) ) {
if ( ! V_383 ) {
int V_27 = F_150 ( V_64 , 1 ) ;
if ( V_27 )
break;
V_383 = 1 ;
}
} else {
if ( V_383 ) {
F_151 ( V_64 , 1 ) ;
V_383 = 0 ;
}
}
F_152 ( V_12 , V_373 + V_374 ) ;
}
if ( V_383 )
F_151 ( V_64 , 1 ) ;
* V_368 += V_374 ;
return V_374 ;
}
static void F_153 ( struct V_63 * V_64 )
{
if ( F_154 ( & V_384 ) == 0 )
F_155 ( & V_385 , & V_386 ) ;
F_155 ( & V_64 -> V_387 , & V_64 -> V_388 ) ;
F_155 ( & V_64 -> V_364 , & V_64 -> V_389 ) ;
}
static int F_156 ( struct V_63 * V_64 )
{
char V_390 [ 10 ] ;
int V_27 ;
if ( F_157 ( & V_384 ) == 1 ) {
V_27 = F_158 ( 0 , F_159 () , & V_391 ,
& V_385 , & V_386 ,
true ) ;
if ( V_27 )
goto V_85;
}
snprintf ( V_390 , sizeof( V_390 ) , L_11 , F_159 () , V_64 -> V_266 ) ;
V_27 = F_158 ( V_64 -> V_266 + 1 , V_390 , & V_391 ,
& V_64 -> V_387 , & V_64 -> V_388 ,
true ) ;
if ( V_27 )
goto V_85;
if ( V_392 ) {
snprintf ( V_390 , sizeof( V_390 ) ,
L_12 , F_159 () , V_64 -> V_266 ) ;
V_27 = F_158 ( V_64 -> V_266 + V_393 , V_390 , & V_394 ,
& V_64 -> V_364 , & V_64 -> V_389 ,
false ) ;
if ( V_27 )
goto V_85;
}
return 0 ;
V_85:
F_153 ( V_64 ) ;
return V_27 ;
}
int F_160 ( struct V_63 * V_64 )
{
int V_395 , V_27 ;
V_395 = F_156 ( V_64 ) ;
V_27 = F_161 ( V_64 ) ;
if ( V_395 && ! V_27 )
V_27 = V_395 ;
return V_27 ;
}
void F_162 ( struct V_63 * V_64 )
{
F_153 ( V_64 ) ;
F_163 ( V_64 ) ;
}
