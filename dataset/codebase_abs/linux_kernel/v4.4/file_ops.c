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
struct V_17 * V_18 = F_6 ( V_6 ) ;
struct V_15 V_19 ;
struct V_20 V_21 ;
struct V_22 V_23 ;
T_2 V_24 = 0 , V_25 = 0 , V_26 = 0 ;
void * V_27 = NULL ;
T_6 V_28 = 0 ;
int V_29 = 1 ;
int V_30 = 0 ;
if ( V_13 < sizeof( V_19 ) ) {
V_26 = - V_31 ;
goto V_32;
}
V_16 = ( const struct V_15 T_3 * ) V_12 ;
if ( F_7 ( & V_19 , V_16 , sizeof( V_19 ) ) ) {
V_26 = - V_33 ;
goto V_32;
}
V_24 = sizeof( V_19 ) ;
switch ( V_19 . type ) {
case V_34 :
V_29 = 0 ;
V_25 = sizeof( V_21 ) ;
V_27 = & V_21 ;
break;
case V_35 :
case V_36 :
V_25 = 0 ;
break;
case V_37 :
case V_38 :
V_25 = sizeof( V_23 ) ;
V_27 = & V_23 ;
break;
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
V_25 = 0 ;
V_28 = V_19 . V_46 ;
break;
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
V_29 = 0 ;
V_30 = 1 ;
V_25 = 0 ;
break;
default:
V_26 = - V_31 ;
goto V_32;
}
if ( V_25 ) {
if ( F_7 ( V_27 , ( void T_3 * ) V_19 . V_46 , V_25 ) ) {
V_26 = - V_33 ;
goto V_32;
}
V_24 += V_25 ;
}
if ( V_29 && ! V_18 ) {
V_26 = - V_31 ;
goto V_32;
}
if ( V_30 && ! F_8 ( V_55 ) ) {
V_26 = - V_56 ;
goto V_32;
}
switch ( V_19 . type ) {
case V_34 :
V_26 = F_9 ( V_6 , & V_21 ) ;
if ( V_26 < 0 )
goto V_32;
V_26 = F_10 ( V_6 ) ;
if ( V_26 )
goto V_32;
V_26 = F_11 ( V_6 ) ;
break;
case V_43 :
V_26 = F_12 ( V_6 , ( void T_3 * ) ( unsigned long )
V_28 , V_19 . V_57 ) ;
break;
case V_39 :
V_26 = F_13 ( V_6 , ( void T_3 * ) ( unsigned long )
V_28 , V_19 . V_57 ) ;
break;
case V_35 :
break;
case V_36 :
if ( V_18 && V_18 -> V_58 )
F_14 ( V_18 -> V_58 ) ;
break;
case V_37 :
V_26 = F_15 ( V_6 , & V_23 ) ;
if ( ! V_26 ) {
unsigned long V_46 ;
V_46 = ( unsigned long ) V_19 . V_46 +
F_16 ( struct V_22 , V_59 ) ;
if ( F_17 ( ( void T_3 * ) V_46 , & V_23 . V_59 ,
sizeof( V_23 . V_59 ) +
sizeof( V_23 . V_60 ) ) )
V_26 = - V_33 ;
}
break;
case V_38 :
V_26 = F_18 ( V_6 , & V_23 ) ;
break;
case V_40 :
V_26 = F_19 ( V_18 , F_20 ( V_6 ) , ( int ) V_28 ) ;
break;
case V_41 :
V_18 -> V_61 = ( F_21 ( V_18 -> V_61 ) ) V_28 ;
break;
case V_42 :
V_26 = F_22 ( V_18 , F_20 ( V_6 ) , V_28 ) ;
break;
case V_44 :
if ( F_23 ( V_62 ) )
V_26 = F_24 ( V_18 , F_20 ( V_6 ) , V_28 ) ;
else
V_26 = - V_56 ;
break;
case V_45 : {
struct V_63 * V_58 ;
struct V_64 * V_65 ;
if ( ! V_18 || ! V_18 -> V_65 || ! V_18 -> V_58 ) {
V_26 = - V_31 ;
break;
}
V_65 = V_18 -> V_65 ;
V_58 = V_18 -> V_58 ;
F_25 (
V_58 -> V_66 , ( V_58 -> V_67 & V_68 ) ,
F_26 ( V_69 ) ) ;
if ( ! ( V_58 -> V_67 & V_68 ) ) {
V_26 = - V_70 ;
break;
}
if ( V_58 -> V_67 & V_71 ) {
F_25 (
V_65 -> V_72 ,
! ( F_27 ( V_65 -> V_67 ) & V_73 ) ,
F_26 ( V_69 ) ) ;
if ( V_65 -> V_67 & V_73 ) {
V_26 = - V_70 ;
break;
}
if ( V_65 -> V_67 & V_74 ) {
V_26 = - V_75 ;
break;
}
F_28 ( V_58 ) ;
V_26 = F_29 ( V_58 ) ;
F_30 ( V_65 , V_76 ,
V_18 -> V_77 ) ;
} else
V_26 = F_31 ( V_58 ) ;
if ( ! V_26 )
F_14 ( V_58 ) ;
break;
}
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
V_26 = F_32 ( & V_19 ) ;
break;
}
if ( V_26 >= 0 )
V_26 = V_24 ;
V_32:
return V_26 ;
}
static T_2 F_33 ( struct V_78 * V_78 , struct V_79 * V_80 )
{
struct V_81 * V_82 ;
struct V_83 * V_84 ;
int V_26 = 0 , V_85 = 0 , V_86 = 0 ;
unsigned long V_87 = V_80 -> V_88 ;
if ( ! F_34 ( V_78 -> V_89 ) ||
! F_35 ( V_78 -> V_89 ) ) {
V_26 = - V_90 ;
goto V_85;
}
if ( ! F_36 ( V_80 ) || ! V_87 ) {
V_26 = - V_31 ;
goto V_85;
}
F_37 ( V_91 , L_1 ,
F_6 ( V_78 -> V_89 ) -> V_77 , F_20 ( V_78 -> V_89 ) ,
V_87 ) ;
V_82 = F_35 ( V_78 -> V_89 ) ;
V_84 = F_34 ( V_78 -> V_89 ) ;
if ( F_38 ( & V_82 -> V_92 ) == V_82 -> V_93 ) {
V_26 = - V_94 ;
goto V_85;
}
while ( V_87 ) {
unsigned long V_13 = 0 ;
V_26 = F_39 (
V_78 -> V_89 , (struct V_95 * ) ( V_80 -> V_96 + V_85 ) ,
V_87 , & V_13 ) ;
if ( V_26 )
goto V_85;
V_87 -= V_13 ;
V_85 += V_13 ;
V_86 ++ ;
}
V_85:
return V_26 ? V_26 : V_86 ;
}
static int F_40 ( struct V_5 * V_6 , struct V_97 * V_98 )
{
struct V_17 * V_18 ;
struct V_64 * V_65 ;
unsigned long V_67 , V_99 ;
T_1 V_1 = V_98 -> V_100 << V_101 ,
V_102 = 0 ;
T_7 V_103 , V_104 = 0 , V_105 = 0 , type ;
T_2 V_106 = 0 ;
int V_26 = 0 ;
T_8 V_77 ;
V_18 = F_6 ( V_6 ) ;
if ( ! F_1 ( V_1 ) || ! V_18 ||
! ( V_98 -> V_107 & V_108 ) ) {
V_26 = - V_31 ;
goto V_85;
}
V_65 = V_18 -> V_65 ;
V_77 = F_2 ( V_109 , V_1 ) ;
V_103 = F_2 ( V_110 , V_1 ) ;
type = F_2 ( TYPE , V_1 ) ;
if ( V_77 != V_18 -> V_77 || V_103 != F_20 ( V_6 ) ) {
V_26 = - V_31 ;
goto V_85;
}
V_67 = V_98 -> V_107 ;
switch ( type ) {
case V_111 :
case V_112 :
V_102 = ( ( V_65 -> V_113 + V_114 ) +
( V_18 -> V_58 -> V_115 * F_41 ( 16 ) ) ) +
( type == V_112 ?
( V_116 / 2 ) : 0 ) ;
V_106 = F_42 ( V_18 -> V_58 -> V_117 * V_118 ,
V_119 ) ;
V_67 &= ~ V_120 ;
V_67 |= V_121 | V_122 ;
V_98 -> V_123 = F_43 ( V_98 -> V_123 ) ;
V_104 = 1 ;
break;
case V_124 :
if ( V_67 & V_125 ) {
V_26 = - V_56 ;
goto V_85;
}
V_102 = V_65 -> V_126 [ V_18 -> V_127 ] . V_128 +
( ( ( T_1 ) V_18 -> V_58 -> V_129 -
( T_1 ) V_65 -> V_126 [ V_18 -> V_127 ] . V_130 ) & V_131 ) ;
V_106 = V_119 ;
V_67 &= ~ V_132 ;
V_67 |= V_121 | V_122 ;
V_104 = 1 ;
break;
case V_133 :
V_102 = V_18 -> V_134 ;
V_106 = V_18 -> V_135 ;
break;
case V_136 : {
unsigned long V_46 ;
int V_137 ;
V_106 = V_18 -> V_138 . V_139 ;
if ( ( V_98 -> V_140 - V_98 -> V_141 ) != V_106 ) {
F_44 ( V_65 , L_2 ,
( V_98 -> V_140 - V_98 -> V_141 ) , V_106 ) ;
V_26 = - V_31 ;
goto V_85;
}
if ( V_98 -> V_107 & V_125 ) {
V_26 = - V_56 ;
goto V_85;
}
V_98 -> V_107 &= ~ V_132 ;
V_46 = V_98 -> V_141 ;
for ( V_137 = 0 ; V_137 < V_18 -> V_138 . V_142 ; V_137 ++ ) {
V_26 = F_45 (
V_98 , V_46 ,
V_18 -> V_138 . V_143 [ V_137 ] . V_144 >> V_101 ,
V_18 -> V_138 . V_143 [ V_137 ] . V_57 ,
V_98 -> V_123 ) ;
if ( V_26 < 0 )
goto V_85;
V_46 += V_18 -> V_138 . V_143 [ V_137 ] . V_57 ;
}
V_26 = 0 ;
goto V_85;
}
case V_145 :
V_102 = ( unsigned long )
( V_65 -> V_113 + V_146 )
+ ( V_18 -> V_77 * V_147 ) ;
V_106 = V_119 ;
V_67 |= V_121 | V_122 ;
V_98 -> V_123 = F_46 ( V_98 -> V_123 ) ;
V_104 = 1 ;
break;
case V_148 :
V_102 = ( unsigned long ) ( V_65 -> V_149 +
( ( V_18 -> V_77 - V_65 -> V_150 ) *
V_151 ) ) & V_131 ;
V_106 = V_119 ;
V_67 |= V_152 | V_122 ;
V_105 = 1 ;
break;
case V_153 :
V_102 = F_47 ( ( void * ) V_65 -> V_154 ) ;
V_106 = V_119 ;
V_67 |= V_152 | V_122 ;
break;
case V_155 :
if ( ! F_23 ( V_156 ) ) {
V_26 = - V_31 ;
goto V_85;
}
if ( V_67 & V_125 ) {
V_26 = - V_56 ;
goto V_85;
}
V_102 = V_18 -> V_157 ;
V_106 = V_119 ;
V_67 &= ~ V_132 ;
break;
case V_158 :
V_102 = ( T_1 ) V_18 -> V_159 ;
V_106 = V_119 ;
V_67 |= V_152 | V_122 ;
V_105 = 1 ;
break;
case V_160 :
V_102 = ( T_1 ) V_18 -> V_161 ;
V_106 = V_18 -> V_135 * V_18 -> V_162 ;
V_67 |= V_152 | V_122 ;
V_105 = 1 ;
break;
case V_163 :
V_102 = ( T_1 ) V_18 -> V_164 ;
V_106 = V_18 -> V_138 . V_139 * V_18 -> V_162 ;
V_67 |= V_152 | V_122 ;
V_67 &= ~ V_132 ;
V_105 = 1 ;
break;
case V_165 : {
struct V_83 * V_84 ;
if ( ! F_34 ( V_6 ) ) {
V_26 = - V_33 ;
goto V_85;
}
V_84 = F_34 ( V_6 ) ;
V_102 = ( T_1 ) V_84 -> V_166 ;
V_106 = F_42 ( sizeof( * V_84 -> V_166 ) * V_84 -> V_167 , V_119 ) ;
V_67 |= V_152 | V_122 ;
V_105 = 1 ;
break;
}
default:
V_26 = - V_31 ;
break;
}
if ( ( V_98 -> V_140 - V_98 -> V_141 ) != V_106 ) {
F_37 ( V_168 , L_3 ,
V_18 -> V_77 , F_20 ( V_6 ) ,
( V_98 -> V_140 - V_98 -> V_141 ) , V_106 ) ;
V_26 = - V_31 ;
goto V_85;
}
V_98 -> V_107 = V_67 ;
F_48 ( V_65 ,
L_4 ,
V_169 , V_77 , V_103 , type , V_104 , V_105 , V_102 , V_106 ,
V_98 -> V_140 - V_98 -> V_141 , V_98 -> V_107 ) ;
V_99 = ( unsigned long ) ( V_102 >> V_101 ) ;
if ( V_105 ) {
V_98 -> V_100 = V_99 ;
V_98 -> V_170 = & V_170 ;
V_26 = 0 ;
} else if ( V_104 ) {
V_26 = F_49 ( V_98 , V_98 -> V_141 , V_99 , V_106 ,
V_98 -> V_123 ) ;
} else {
V_26 = F_45 ( V_98 , V_98 -> V_141 , V_99 , V_106 ,
V_98 -> V_123 ) ;
}
V_85:
return V_26 ;
}
static int F_50 ( struct V_97 * V_98 , struct V_171 * V_105 )
{
struct V_172 * V_172 ;
V_172 = F_51 ( ( void * ) ( V_105 -> V_173 << V_101 ) ) ;
if ( ! V_172 )
return V_174 ;
F_52 ( V_172 ) ;
V_105 -> V_172 = V_172 ;
return 0 ;
}
static unsigned int F_53 ( struct V_5 * V_6 , struct V_175 * V_176 )
{
struct V_17 * V_18 ;
unsigned V_177 ;
V_18 = F_6 ( V_6 ) ;
if ( ! V_18 )
V_177 = V_178 ;
else if ( V_18 -> V_61 == V_179 )
V_177 = F_54 ( V_6 , V_176 ) ;
else if ( V_18 -> V_61 == V_180 )
V_177 = F_55 ( V_6 , V_176 ) ;
else
V_177 = V_178 ;
return V_177 ;
}
static int F_56 ( struct V_4 * V_4 , struct V_5 * V_6 )
{
struct V_8 * V_181 = V_6 -> V_7 ;
struct V_17 * V_18 = V_181 -> V_18 ;
struct V_64 * V_65 ;
unsigned long V_67 , * V_182 ;
V_6 -> V_7 = NULL ;
if ( ! V_18 )
goto V_85;
F_37 ( V_168 , L_5 , V_18 -> V_77 , V_181 -> V_103 ) ;
V_65 = V_18 -> V_65 ;
F_57 ( & V_183 ) ;
F_58 () ;
if ( V_181 -> V_82 )
F_59 ( V_181 ) ;
V_182 = V_65 -> V_149 + ( ( V_18 -> V_77 - V_65 -> V_150 ) *
V_151 ) + V_181 -> V_103 ;
* V_182 = 0 ;
if ( -- V_18 -> V_184 ) {
V_18 -> V_185 &= ~ ( 1 << V_181 -> V_103 ) ;
V_18 -> V_186 [ V_181 -> V_103 ] = 0 ;
F_60 ( & V_183 ) ;
goto V_85;
}
F_61 ( & V_65 -> V_187 , V_67 ) ;
F_30 ( V_65 , V_188 |
V_189 |
V_190 |
V_191 |
V_192 |
V_193 , V_18 -> V_77 ) ;
F_62 ( V_65 , V_18 -> V_77 ) ;
F_63 ( V_65 , V_18 -> V_58 -> V_115 , V_194 ,
F_64 ( V_65 , V_18 -> V_58 -> type ) ) ;
F_28 ( V_18 -> V_58 ) ;
V_18 -> V_195 = 0 ;
F_65 ( & V_65 -> V_187 , V_67 ) ;
V_65 -> V_196 [ V_18 -> V_77 ] = NULL ;
V_18 -> V_197 = 0 ;
V_18 -> V_198 = 0 ;
V_18 -> V_199 = 0 ;
V_18 -> V_200 = 0 ;
V_18 -> V_201 = 0 ;
F_66 ( V_18 ) ;
F_67 ( V_65 , V_18 -> V_77 ) ;
if ( V_18 -> V_202 )
F_68 ( V_18 ) ;
V_203 . V_204 -- ;
V_65 -> V_205 ++ ;
F_60 ( & V_183 ) ;
F_69 ( V_65 , V_18 ) ;
V_85:
F_70 ( V_181 ) ;
return 0 ;
}
static T_1 F_47 ( void * V_46 )
{
struct V_172 * V_172 ;
T_1 V_206 = 0 ;
V_172 = F_51 ( V_46 ) ;
if ( V_172 )
V_206 = F_71 ( V_172 ) << V_101 ;
return V_206 ;
}
static int F_9 ( struct V_5 * V_6 , struct V_20 * V_21 )
{
int V_207 , V_26 = 0 ;
unsigned V_208 , V_209 , V_210 = V_211 ;
V_208 = V_21 -> V_212 >> 16 ;
if ( V_208 != V_213 ) {
V_26 = - V_75 ;
goto V_85;
}
V_209 = V_21 -> V_212 & 0xffff ;
if ( V_21 -> V_214 < V_215 )
V_210 = V_21 -> V_214 ;
F_57 ( & V_183 ) ;
if ( V_21 -> V_162 )
V_26 = F_72 ( V_6 , V_21 ) ;
if ( ! V_26 ) {
V_207 = F_73 ( F_74 ( V_6 ) ) - V_216 ;
V_26 = F_75 ( V_6 , V_21 , V_207 - 1 , V_210 ) ;
}
F_60 ( & V_183 ) ;
V_85:
return V_26 ;
}
static int F_75 ( struct V_5 * V_6 , struct V_20 * V_21 ,
int V_217 , unsigned V_210 )
{
struct V_64 * V_65 = NULL ;
int V_26 = 0 , V_218 , V_219 , V_220 , V_221 ;
V_218 = F_76 ( & V_219 , & V_220 ) ;
if ( ! V_219 ) {
V_26 = - V_222 ;
goto V_85;
}
if ( ! V_220 ) {
V_26 = - V_223 ;
goto V_85;
}
if ( V_217 >= 0 ) {
V_65 = F_77 ( V_217 ) ;
if ( ! V_65 )
V_26 = - V_75 ;
else if ( ! V_65 -> V_205 )
V_26 = - V_224 ;
} else {
struct V_64 * V_225 ;
if ( V_210 == V_211 ) {
unsigned free = 0U ;
for ( V_221 = 0 ; V_221 < V_218 ; V_221 ++ ) {
V_225 = F_77 ( V_221 ) ;
if ( V_225 && V_225 -> V_205 &&
V_225 -> V_205 > free ) {
V_65 = V_225 ;
free = V_225 -> V_205 ;
}
}
} else {
for ( V_221 = 0 ; V_221 < V_218 ; V_221 ++ ) {
V_225 = F_77 ( V_221 ) ;
if ( V_225 && V_225 -> V_205 ) {
V_65 = V_225 ;
break;
}
}
}
if ( ! V_65 )
V_26 = - V_224 ;
}
V_85:
return V_26 ? V_26 : F_78 ( V_6 , V_65 , V_21 ) ;
}
static int F_72 ( struct V_5 * V_6 ,
const struct V_20 * V_21 )
{
int V_218 , V_226 , V_137 ;
int V_26 = 0 ;
V_218 = F_76 ( NULL , NULL ) ;
for ( V_226 = 0 ; V_226 < V_218 ; V_226 ++ ) {
struct V_64 * V_65 = F_77 ( V_226 ) ;
if ( ! ( V_65 && ( V_65 -> V_67 & V_227 ) && V_65 -> V_228 ) )
continue;
for ( V_137 = V_65 -> V_150 ; V_137 < V_65 -> V_229 ; V_137 ++ ) {
struct V_17 * V_18 = V_65 -> V_196 [ V_137 ] ;
if ( ! V_18 || ! V_18 -> V_184 )
continue;
if ( memcmp ( V_18 -> V_230 , V_21 -> V_230 ,
sizeof( V_18 -> V_230 ) ) ||
V_18 -> V_231 != F_79 ( F_80 () ) ||
V_18 -> V_232 != V_21 -> V_232 ||
V_18 -> V_162 != V_21 -> V_162 )
continue;
if ( V_18 -> V_212 != V_21 -> V_212 ||
V_18 -> V_184 >= V_18 -> V_162 ) {
V_26 = - V_31 ;
goto V_85;
}
F_6 ( V_6 ) = V_18 ;
F_20 ( V_6 ) = V_18 -> V_184 ++ ;
V_18 -> V_186 [ F_20 ( V_6 ) ] = V_233 -> V_195 ;
V_18 -> V_185 |= 1 << F_20 ( V_6 ) ;
V_26 = 1 ;
goto V_85;
}
}
V_85:
return V_26 ;
}
static int F_78 ( struct V_5 * V_6 , struct V_64 * V_65 ,
struct V_20 * V_21 )
{
struct V_17 * V_18 ;
unsigned V_77 ;
int V_26 ;
if ( V_65 -> V_67 & V_73 ) {
return - V_90 ;
}
for ( V_77 = V_65 -> V_150 ; V_77 < V_65 -> V_229 ; V_77 ++ )
if ( ! V_65 -> V_196 [ V_77 ] )
break;
if ( V_77 == V_65 -> V_229 )
return - V_224 ;
V_18 = F_81 ( V_65 -> V_234 , V_77 ) ;
if ( ! V_18 ) {
F_44 ( V_65 ,
L_6 ) ;
return - V_11 ;
}
V_18 -> V_58 = F_82 ( V_65 , V_235 , V_18 -> V_236 ,
V_18 -> V_127 ) ;
if ( ! V_18 -> V_58 )
return - V_11 ;
F_83 ( L_7 , V_18 -> V_58 -> V_237 ,
V_18 -> V_58 -> V_115 ) ;
V_26 = F_29 ( V_18 -> V_58 ) ;
if ( V_26 )
return V_26 ;
if ( V_21 -> V_162 && ! F_20 ( V_6 ) ) {
V_26 = F_84 ( V_18 , V_21 ) ;
if ( V_26 )
return V_26 ;
}
V_18 -> V_212 = V_21 -> V_212 ;
V_18 -> V_195 = V_233 -> V_195 ;
V_18 -> V_67 = F_85 ( V_238 ) ;
F_86 ( & V_18 -> V_239 ) ;
F_87 ( V_18 -> V_240 , V_233 -> V_240 , sizeof( V_18 -> V_240 ) ) ;
memcpy ( V_18 -> V_230 , V_21 -> V_230 , sizeof( V_18 -> V_230 ) ) ;
V_18 -> V_231 = F_79 ( F_80 () ) ;
F_88 ( & V_18 -> V_241 ) ;
F_89 ( & V_18 -> V_242 ) ;
V_203 . V_204 ++ ;
V_65 -> V_205 -- ;
F_6 ( V_6 ) = V_18 ;
return 0 ;
}
static int F_84 ( struct V_17 * V_18 ,
const struct V_20 * V_21 )
{
int V_26 = 0 ;
unsigned V_243 ;
V_243 = V_21 -> V_162 ;
if ( V_243 > V_151 ) {
V_26 = - V_31 ;
goto V_32;
}
V_18 -> V_162 = V_21 -> V_162 ;
V_18 -> V_232 = V_21 -> V_232 ;
V_18 -> V_185 = 1 ;
V_18 -> V_244 = 1 ;
F_90 ( V_245 , & V_18 -> V_201 ) ;
V_32:
return V_26 ;
}
static int F_91 ( struct V_17 * V_18 )
{
int V_26 = 0 ;
unsigned V_243 = V_18 -> V_162 ;
V_18 -> V_159 = F_92 ( V_119 ) ;
if ( ! V_18 -> V_159 ) {
V_26 = - V_11 ;
goto V_32;
}
V_18 -> V_161 = F_92 ( V_18 -> V_135 *
V_243 ) ;
if ( ! V_18 -> V_161 ) {
V_26 = - V_11 ;
goto V_246;
}
V_18 -> V_164 = F_92 ( V_18 -> V_138 . V_139 *
V_243 ) ;
if ( ! V_18 -> V_164 ) {
V_26 = - V_11 ;
goto V_247;
}
goto V_32;
V_247:
F_93 ( V_18 -> V_161 ) ;
V_246:
F_93 ( V_18 -> V_159 ) ;
V_18 -> V_159 = NULL ;
V_32:
return V_26 ;
}
static int F_11 ( struct V_5 * V_6 )
{
int V_26 ;
unsigned int V_248 = 0 ;
struct V_17 * V_18 = F_6 ( V_6 ) ;
if ( ! F_94 ( V_249 , & V_18 -> V_201 ) ) {
V_26 = - V_33 ;
goto V_85;
}
if ( F_20 ( V_6 ) ) {
V_26 = F_95 ( V_18 -> V_239 ,
! F_94 ( V_245 ,
& V_18 -> V_201 ) ) ;
goto V_85;
}
V_18 -> V_250 = 0 ;
V_18 -> V_251 = 0 ;
if ( V_18 -> V_252 )
F_96 ( V_18 ) ;
F_97 ( V_18 -> V_65 , V_18 -> V_77 , V_18 -> V_231 ) ;
V_248 = V_76 ;
if ( F_98 ( V_18 -> V_67 , V_253 ) )
V_248 |= V_254 ;
if ( ! F_98 ( V_18 -> V_67 , V_255 ) )
V_248 |= V_256 ;
if ( F_98 ( V_18 -> V_67 , V_257 ) )
V_248 |= V_258 ;
if ( F_98 ( V_18 -> V_67 , V_259 ) )
V_248 |= V_260 ;
if ( F_98 ( V_18 -> V_67 , V_156 ) )
V_248 |= V_261 ;
F_30 ( V_18 -> V_65 , V_248 , V_18 -> V_77 ) ;
if ( V_18 -> V_162 ) {
F_99 ( V_245 , & V_18 -> V_201 ) ;
F_100 ( & V_18 -> V_239 ) ;
}
V_26 = 0 ;
V_85:
return V_26 ;
}
static int F_12 ( struct V_5 * V_6 , void T_3 * V_262 , T_9 V_57 )
{
struct V_263 V_264 ;
struct V_17 * V_18 = F_6 ( V_6 ) ;
struct V_8 * V_265 = V_6 -> V_7 ;
int V_26 = 0 ;
memset ( & V_264 , 0 , sizeof( V_264 ) ) ;
V_26 = F_101 ( V_18 , & V_264 ) ;
if ( V_26 < 0 )
goto V_85;
V_264 . V_266 = F_102 () ;
V_264 . V_267 = V_18 -> V_65 -> V_267 ;
V_264 . V_77 = V_18 -> V_77 ;
V_264 . V_103 = F_20 ( V_6 ) ;
V_264 . V_268 = F_103 ( V_18 -> V_138 . V_269 ,
V_18 -> V_65 -> V_270 . V_271 ) +
V_18 -> V_272 ;
V_264 . V_117 = V_18 -> V_58 -> V_117 ;
V_264 . V_273 = V_18 -> V_127 ;
V_264 . V_274 = V_265 -> V_10 ;
V_264 . V_275 = V_18 -> V_58 -> V_115 ;
V_264 . V_276 = V_18 -> V_138 . V_269 ;
V_264 . V_277 = V_18 -> V_277 ;
V_264 . V_278 = V_18 -> V_236 << 2 ;
V_264 . V_279 = F_34 ( V_6 ) -> V_167 ;
V_264 . V_280 = V_18 -> V_138 . V_281 ;
F_104 ( V_18 -> V_65 , V_18 -> V_77 , F_20 ( V_6 ) , V_264 ) ;
if ( F_17 ( V_262 , & V_264 , sizeof( V_264 ) ) )
V_26 = - V_33 ;
V_85:
return V_26 ;
}
static int F_10 ( struct V_5 * V_6 )
{
struct V_17 * V_18 = F_6 ( V_6 ) ;
struct V_64 * V_65 = V_18 -> V_65 ;
int V_26 = 0 ;
if ( ! V_18 -> V_162 || ! F_20 ( V_6 ) ) {
V_26 = F_105 ( V_18 -> V_58 ) ;
if ( V_26 )
goto V_85;
V_26 = F_106 ( V_65 , V_18 ) ;
if ( V_26 )
goto V_85;
V_26 = F_107 ( V_18 ) ;
if ( V_26 )
goto V_85;
if ( V_18 -> V_162 && ! F_20 ( V_6 ) ) {
V_26 = F_91 ( V_18 ) ;
if ( V_26 )
goto V_85;
}
V_18 -> V_202 = F_108 ( V_18 -> V_272 *
sizeof( struct V_172 * * ) ) ;
if ( ! V_18 -> V_202 ) {
V_26 = - V_11 ;
goto V_85;
}
V_18 -> V_282 = F_108 ( V_18 -> V_272 *
sizeof( * V_18 -> V_282 ) ) ;
if ( ! V_18 -> V_282 ) {
V_26 = - V_11 ;
goto V_85;
}
F_109 ( & V_18 -> V_283 , 0 ) ;
V_18 -> V_284 = V_18 -> V_272 /
V_65 -> V_270 . V_271 ;
V_18 -> V_285 = V_18 -> V_284 / V_286 +
! ! ( V_18 -> V_284 % V_286 ) ;
V_18 -> V_287 = F_110 ( V_18 -> V_285 *
sizeof( * V_18 -> V_287 ) ,
V_9 , V_18 -> V_127 ) ;
if ( ! V_18 -> V_287 ) {
V_26 = - V_11 ;
goto V_85;
}
if ( V_18 -> V_284 % V_286 )
V_18 -> V_287 [ V_18 -> V_285 - 1 ] =
~ ( ( 1ULL << ( V_18 -> V_284 %
V_286 ) ) - 1 ) ;
F_111 ( V_18 -> V_77 , F_20 ( V_6 ) , 0 ,
V_18 -> V_287 , V_18 -> V_285 ) ;
}
V_26 = F_112 ( V_18 , V_6 ) ;
if ( V_26 )
goto V_85;
F_90 ( V_249 , & V_18 -> V_201 ) ;
V_85:
return V_26 ;
}
static int F_13 ( struct V_5 * V_6 , void T_3 * V_262 , T_9 V_57 )
{
struct V_288 V_289 ;
struct V_17 * V_18 = F_6 ( V_6 ) ;
struct V_64 * V_65 = V_18 -> V_65 ;
T_2 V_290 ;
unsigned V_14 ;
int V_26 = 0 ;
F_113 ( V_18 -> V_65 , V_18 ) ;
memset ( & V_289 , 0 , sizeof( V_289 ) ) ;
V_289 . V_291 = V_65 -> V_292 ;
V_289 . V_293 = V_294 ;
V_289 . V_295 = V_296 ;
V_289 . V_231 = V_18 -> V_231 ;
V_14 = ( ( T_1 ) V_18 -> V_58 -> V_129 -
( T_1 ) V_65 -> V_126 [ V_18 -> V_127 ] . V_130 ) % V_119 ;
V_289 . V_297 = F_114 ( V_124 , V_18 -> V_77 ,
F_20 ( V_6 ) , V_14 ) ;
V_289 . V_298 = F_114 ( V_111 , V_18 -> V_77 ,
F_20 ( V_6 ) ,
V_18 -> V_58 -> V_299 ) ;
V_289 . V_300 = F_114 ( V_112 ,
V_18 -> V_77 ,
F_20 ( V_6 ) ,
V_18 -> V_58 -> V_299 ) ;
V_289 . V_301 = F_114 ( V_133 , V_18 -> V_77 ,
F_20 ( V_6 ) ,
V_18 -> V_302 ) ;
V_289 . V_303 = F_114 ( V_136 , V_18 -> V_77 ,
F_20 ( V_6 ) ,
V_18 -> V_138 . V_268 [ 0 ] . V_144 ) ;
V_289 . V_304 = F_114 ( V_165 , V_18 -> V_77 ,
F_20 ( V_6 ) , 0 ) ;
V_289 . V_305 = F_114 ( V_145 , V_18 -> V_77 ,
F_20 ( V_6 ) , 0 ) ;
V_14 = F_115 ( ( ( ( V_18 -> V_77 - V_65 -> V_150 ) *
V_151 ) + F_20 ( V_6 ) ) *
sizeof( * V_65 -> V_149 ) ) ;
V_289 . V_306 = F_114 ( V_148 , V_18 -> V_77 ,
F_20 ( V_6 ) ,
V_14 ) ;
V_289 . V_307 = F_114 ( V_153 , V_18 -> V_77 ,
F_20 ( V_6 ) ,
V_65 -> V_154 ) ;
if ( F_23 ( V_156 ) )
V_289 . V_308 = F_114 ( V_155 , V_18 -> V_77 ,
F_20 ( V_6 ) , 0 ) ;
if ( V_18 -> V_162 ) {
V_289 . V_159 = F_114 ( V_158 ,
V_18 -> V_77 ,
F_20 ( V_6 ) , 0 ) ;
V_289 . V_309 = F_114 ( V_160 ,
V_18 -> V_77 ,
F_20 ( V_6 ) , 0 ) ;
V_289 . V_164 = F_114 ( V_163 ,
V_18 -> V_77 ,
F_20 ( V_6 ) , 0 ) ;
}
V_290 = ( V_57 < sizeof( V_289 ) ) ? V_57 : sizeof( V_289 ) ;
if ( F_17 ( V_262 , & V_289 , V_290 ) )
V_26 = - V_33 ;
return V_26 ;
}
static unsigned int F_54 ( struct V_5 * V_6 ,
struct V_175 * V_176 )
{
struct V_17 * V_18 = F_6 ( V_6 ) ;
struct V_64 * V_65 = V_18 -> V_65 ;
unsigned V_177 ;
F_116 ( V_6 , & V_18 -> V_239 , V_176 ) ;
F_117 ( & V_65 -> V_187 ) ;
if ( V_18 -> V_250 != V_18 -> V_251 ) {
V_177 = V_310 | V_311 ;
V_18 -> V_251 = V_18 -> V_250 ;
} else {
V_177 = 0 ;
F_90 ( V_312 , & V_18 -> V_201 ) ;
}
F_118 ( & V_65 -> V_187 ) ;
return V_177 ;
}
static unsigned int F_55 ( struct V_5 * V_6 ,
struct V_175 * V_176 )
{
struct V_17 * V_18 = F_6 ( V_6 ) ;
struct V_64 * V_65 = V_18 -> V_65 ;
unsigned V_177 ;
F_116 ( V_6 , & V_18 -> V_239 , V_176 ) ;
F_117 ( & V_65 -> V_187 ) ;
if ( F_119 ( V_18 ) ) {
F_90 ( V_313 , & V_18 -> V_201 ) ;
F_30 ( V_65 , V_314 , V_18 -> V_77 ) ;
V_177 = 0 ;
} else
V_177 = V_310 | V_311 ;
F_118 ( & V_65 -> V_187 ) ;
return V_177 ;
}
int F_120 ( struct V_315 * V_316 , const int V_317 )
{
struct V_17 * V_18 ;
struct V_64 * V_65 = V_316 -> V_65 ;
unsigned V_77 ;
int V_26 = 0 ;
unsigned long V_67 ;
if ( ! V_65 -> V_149 ) {
V_26 = - V_31 ;
goto V_85;
}
F_61 ( & V_65 -> V_187 , V_67 ) ;
for ( V_77 = V_65 -> V_150 ; V_77 < V_65 -> V_229 ;
V_77 ++ ) {
V_18 = V_65 -> V_196 [ V_77 ] ;
if ( V_18 ) {
unsigned long * V_318 = V_65 -> V_149 +
( V_18 -> V_77 - V_65 -> V_150 ) *
V_151 ;
int V_137 ;
F_90 ( V_317 , V_318 ) ;
for ( V_137 = 1 ; V_137 < V_18 -> V_162 ; V_137 ++ )
F_90 ( V_317 , V_318 + V_137 ) ;
}
}
F_65 ( & V_65 -> V_187 , V_67 ) ;
V_85:
return V_26 ;
}
static int F_19 ( struct V_17 * V_18 , unsigned V_103 ,
int V_319 )
{
struct V_64 * V_65 = V_18 -> V_65 ;
unsigned int V_320 ;
if ( V_103 )
goto V_32;
if ( V_319 ) {
if ( V_18 -> V_252 )
F_96 ( V_18 ) ;
V_320 = V_76 ;
} else
V_320 = V_188 ;
F_30 ( V_65 , V_320 , V_18 -> V_77 ) ;
V_32:
return 0 ;
}
static int F_22 ( struct V_17 * V_18 , int V_103 ,
unsigned long V_149 )
{
int V_137 ;
struct V_64 * V_65 = V_18 -> V_65 ;
unsigned long * V_318 ;
if ( ! V_65 -> V_149 )
return 0 ;
V_318 = V_65 -> V_149 + ( ( V_18 -> V_77 - V_65 -> V_150 ) *
V_151 ) + V_103 ;
for ( V_137 = 0 ; V_137 <= V_321 ; V_137 ++ ) {
if ( ! F_94 ( V_137 , & V_149 ) )
continue;
F_99 ( V_137 , V_318 ) ;
}
return 0 ;
}
static inline T_7 F_121 ( T_1 V_322 )
{
return V_322 ? F_122 ( V_322 ) : sizeof( V_322 ) * 8 ;
}
static inline unsigned F_123 ( unsigned long V_323 , T_8 * V_324 )
{
unsigned free ;
T_8 V_325 = * V_324 ;
if ( V_325 >= V_286 )
return 0 ;
V_323 &= ~ ( ( 1ULL << V_325 ) - 1 ) ;
free = F_121 ( V_323 ) - V_325 ;
while ( ! free && V_325 < V_286 ) {
V_323 &= ~ ( 1ULL << V_325 ) ;
free = F_121 ( V_323 ) - ++ V_325 ;
}
* V_324 = V_325 ;
return free ;
}
static int F_15 ( struct V_5 * V_6 , struct V_22 * V_23 )
{
int V_26 = 0 ;
struct V_17 * V_18 = F_6 ( V_6 ) ;
struct V_64 * V_65 = V_18 -> V_65 ;
unsigned V_326 , V_327 = 0 , V_328 , V_329 , V_330 ,
V_331 = V_18 -> V_272 / 2 ;
struct V_172 * * V_332 ;
unsigned long V_333 , V_334 [ V_18 -> V_285 ] ;
T_10 * V_144 ;
T_11 V_335 [ V_331 ] , V_336 = 0 , V_283 ;
T_8 V_337 , V_338 , V_325 , V_59 = 0 ;
V_333 = V_23 -> V_333 ;
if ( F_115 ( V_333 ) ) {
V_26 = - V_31 ;
goto V_32;
}
V_328 = F_124 ( V_333 , V_23 -> V_60 ) ;
if ( ! V_328 ) {
V_26 = - V_31 ;
goto V_32;
}
if ( ! F_125 ( V_339 , ( void T_3 * ) V_333 ,
V_328 * V_119 ) ) {
F_44 ( V_65 , L_8 ,
( void * ) V_333 , V_328 ) ;
V_26 = - V_33 ;
goto V_32;
}
memset ( V_334 , 0 , sizeof( V_334 [ 0 ] ) * V_18 -> V_285 ) ;
memset ( V_335 , 0 , sizeof( V_335 [ 0 ] ) * V_331 ) ;
V_330 = V_18 -> V_272 / V_65 -> V_270 . V_271 ;
V_283 = F_38 ( & V_18 -> V_283 ) ;
V_337 = ( V_283 >> 16 ) & 0xffff ;
V_325 = V_283 & 0xffff ;
for ( V_327 = 0 , V_338 = 0 ;
V_327 < V_328 && V_338 <= V_18 -> V_285 ; ) {
T_1 V_137 , V_14 = 0 ;
unsigned free , V_340 , V_341 = 0 , V_342 ;
T_8 V_343 ;
F_126 ( & V_18 -> V_344 ) ;
if ( V_18 -> V_287 [ V_337 ] == - 1ULL ||
V_325 >= V_286 ) {
V_337 = ( V_337 + 1 ) % V_18 -> V_285 ;
V_338 ++ ;
V_325 = 0 ;
F_127 ( & V_18 -> V_344 ) ;
continue;
}
V_329 = ( ( V_328 - V_327 ) / V_65 -> V_270 . V_271 ) +
! ! ( ( V_328 - V_327 ) % V_65 -> V_270 . V_271 ) ;
free = F_123 ( V_18 -> V_287 [ V_337 ] , & V_325 ) ;
if ( ! free ) {
F_127 ( & V_18 -> V_344 ) ;
continue;
}
V_342 = F_128 ( free , V_329 ) ;
V_334 [ V_337 ] |= ( ( 1ULL << V_342 ) - 1 ) << V_325 ;
V_18 -> V_287 [ V_337 ] |= V_334 [ V_337 ] ;
F_127 ( & V_18 -> V_344 ) ;
V_14 = ( ( V_337 * V_286 ) + V_325 ) *
V_65 -> V_270 . V_271 ;
V_332 = V_18 -> V_202 + V_14 ;
V_144 = V_18 -> V_282 + V_14 ;
V_326 = V_18 -> V_345 + V_14 ;
V_340 = F_128 ( ( V_342 * V_65 -> V_270 . V_271 ) ,
( V_328 - V_327 ) ) ;
V_26 = F_129 ( V_333 + ( V_327 * V_119 ) ,
V_340 , V_332 ) ;
if ( V_26 ) {
F_48 ( V_65 ,
L_9 ,
( void * ) V_333 , V_340 , - V_26 ) ;
F_126 ( & V_18 -> V_344 ) ;
V_18 -> V_287 [ V_337 ] &=
~ ( ( ( 1ULL << V_342 ) - 1 ) << V_325 ) ;
F_127 ( & V_18 -> V_344 ) ;
goto V_85;
}
V_329 = ( V_340 / V_65 -> V_270 . V_271 ) +
! ! ( V_340 % V_65 -> V_270 . V_271 ) ;
for ( V_137 = 0 , V_343 = 0 ; V_343 < V_329 ; V_137 ++ , V_343 ++ ) {
unsigned V_346 ;
T_11 V_347 = 0 , V_348 ;
for ( V_346 = 0 ; V_346 < V_65 -> V_270 . V_271 &&
V_341 < V_340 ; V_346 ++ , V_341 ++ , V_326 ++ ) {
V_348 = V_119 ;
V_144 [ V_341 ] = F_130 ( V_65 -> V_349 ,
V_332 [ V_341 ] , 0 ,
V_348 , V_350 ) ;
F_131 ( V_18 -> V_77 ,
F_20 ( V_6 ) ,
V_326 , V_333 ,
V_144 [ V_341 ] ,
V_332 [ V_341 ] ) ;
F_132 ( V_65 , V_326 , V_351 ,
V_144 [ V_341 ] ,
F_133 ( V_348 >> V_101 ) + 1 ) ;
V_347 += V_348 >> V_101 ;
F_134 ( V_335 [ V_336 ] , V_352 , V_347 ) ;
if ( ! ( V_326 % 2 ) ) {
V_335 [ V_336 ] |=
F_135 ( V_353 ,
( V_326 - V_18 -> V_345 )
/ 2 ) ;
V_335 [ V_336 ] |=
F_135 ( V_354 , 1 ) ;
V_59 ++ ;
} else {
V_335 [ V_336 ] |=
F_135 ( V_354 , 2 ) ;
V_347 = 0 ;
V_336 ++ ;
}
}
F_58 () ;
}
V_327 += V_340 ;
F_109 ( & V_18 -> V_283 ,
( ( ( V_337 & 0xffffff ) << 16 ) |
( ( V_325 + V_342 ) & 0xffffff ) ) ) ;
}
F_111 ( V_18 -> V_77 , F_20 ( V_6 ) , 0 , V_18 -> V_287 ,
V_18 -> V_285 ) ;
V_85:
if ( V_327 ) {
if ( F_17 ( ( void T_3 * ) ( unsigned long ) V_23 -> V_335 ,
V_335 , sizeof( V_335 [ 0 ] ) * V_59 ) ) {
V_26 = - V_33 ;
goto V_85;
}
if ( F_17 ( ( void T_3 * ) ( unsigned long ) V_23 -> V_334 ,
V_334 , sizeof( V_334 [ 0 ] ) * V_18 -> V_285 ) )
V_26 = - V_33 ;
}
V_32:
V_23 -> V_60 = V_327 * V_119 ;
V_23 -> V_59 = V_59 ;
return V_26 ;
}
static int F_18 ( struct V_5 * V_6 , struct V_22 * V_23 )
{
struct V_17 * V_18 = F_6 ( V_6 ) ;
struct V_64 * V_65 = V_18 -> V_65 ;
unsigned long V_334 [ V_18 -> V_285 ] ;
struct V_172 * * V_332 ;
T_10 * V_144 ;
T_8 V_338 , V_325 , V_326 ;
int V_26 = 0 ;
if ( F_7 ( & V_334 , ( void T_3 * ) ( unsigned long )
V_23 -> V_334 ,
sizeof( V_334 [ 0 ] ) * V_18 -> V_285 ) ) {
V_26 = - V_33 ;
goto V_85;
}
for ( V_338 = 0 ; V_338 < V_18 -> V_285 ; V_338 ++ ) {
unsigned long V_323 ;
V_325 = 0 ;
if ( ! V_334 [ V_338 ] )
continue;
V_323 = V_334 [ V_338 ] ;
while ( ( V_325 = F_121 ( V_323 ) ) < V_286 ) {
int V_137 , V_355 = 0 ;
struct V_172 * V_356 [ V_65 -> V_270 . V_271 ] ;
unsigned V_14 = ( ( V_338 * V_286 ) + V_325 ) *
V_65 -> V_270 . V_271 ;
V_332 = V_18 -> V_202 + V_14 ;
V_144 = V_18 -> V_282 + V_14 ;
V_326 = V_18 -> V_345 + V_14 ;
for ( V_137 = 0 ; V_137 < V_65 -> V_270 . V_271 ;
V_137 ++ , V_326 ++ ) {
if ( V_332 [ V_137 ] ) {
F_132 ( V_65 , V_326 , V_357 ,
0 , 0 ) ;
F_136 ( V_18 -> V_77 ,
F_20 ( V_6 ) ,
V_326 , V_144 [ V_137 ] ,
V_332 [ V_137 ] ) ;
F_137 ( V_65 -> V_349 , V_144 [ V_137 ] ,
V_119 , V_350 ) ;
V_356 [ V_355 ] = V_332 [ V_137 ] ;
V_332 [ V_137 ] = NULL ;
V_355 ++ ;
V_144 [ V_137 ] = 0 ;
}
}
F_58 () ;
F_138 ( V_356 , V_355 ) ;
F_99 ( V_325 , & V_18 -> V_287 [ V_338 ] ) ;
V_323 &= ~ ( 1ULL << V_325 ) ;
}
}
F_111 ( V_18 -> V_77 , F_20 ( V_6 ) , 1 , V_18 -> V_287 ,
V_18 -> V_285 ) ;
V_85:
return V_26 ;
}
static void F_68 ( struct V_17 * V_18 )
{
struct V_64 * V_65 = V_18 -> V_65 ;
unsigned V_326 ;
F_48 ( V_65 , L_10 ,
V_18 -> V_77 ) ;
for ( V_326 = 0 ; V_326 < V_18 -> V_272 ; V_326 ++ ) {
struct V_172 * V_358 = V_18 -> V_202 [ V_326 ] ;
T_10 V_144 ;
if ( ! V_358 )
continue;
V_144 = V_18 -> V_282 [ V_326 ] ;
V_18 -> V_282 [ V_326 ] = 0 ;
V_18 -> V_202 [ V_326 ] = NULL ;
F_137 ( V_65 -> V_349 , V_144 , V_119 , V_350 ) ;
F_138 ( & V_358 , 1 ) ;
}
}
static int F_24 ( struct V_17 * V_18 , unsigned V_103 ,
T_8 V_359 )
{
int V_26 = - V_360 , V_137 , V_361 = 0 ;
struct V_315 * V_316 = V_18 -> V_316 ;
struct V_64 * V_65 = V_18 -> V_65 ;
if ( V_359 == V_362 || V_359 == V_363 ) {
V_26 = - V_31 ;
goto V_85;
}
for ( V_137 = 0 ; V_137 < F_139 ( V_316 -> V_364 ) ; V_137 ++ )
if ( V_359 == V_316 -> V_364 [ V_137 ] ) {
V_361 = 1 ;
break;
}
if ( V_361 )
V_26 = F_140 ( V_65 , V_18 -> V_77 , V_359 ) ;
V_85:
return V_26 ;
}
static int F_141 ( struct V_4 * V_4 , struct V_5 * V_365 )
{
struct V_64 * V_65 ;
V_65 = F_142 ( V_4 -> V_366 , struct V_64 , V_367 ) ;
V_365 -> V_7 = V_65 ;
return 0 ;
}
static int F_143 ( struct V_4 * V_4 , struct V_5 * V_365 )
{
return 0 ;
}
static T_5 F_144 ( struct V_5 * V_365 , T_5 V_14 , int V_368 )
{
struct V_64 * V_65 = V_365 -> V_7 ;
switch ( V_368 ) {
case V_369 :
break;
case V_370 :
V_14 += V_365 -> V_371 ;
break;
case V_372 :
V_14 = ( ( V_65 -> V_373 - V_65 -> V_228 ) + V_374 ) -
V_14 ;
break;
default:
return - V_31 ;
}
if ( V_14 < 0 )
return - V_31 ;
if ( V_14 >= ( V_65 -> V_373 - V_65 -> V_228 ) + V_374 )
return - V_31 ;
V_365 -> V_371 = V_14 ;
return V_365 -> V_371 ;
}
static T_2 F_145 ( struct V_5 * V_365 , char T_3 * V_375 , T_4 V_13 ,
T_5 * V_371 )
{
struct V_64 * V_65 = V_365 -> V_7 ;
void T_12 * V_376 = V_65 -> V_228 ;
unsigned long V_377 , V_378 ,
V_379 = ( V_65 -> V_373 - V_65 -> V_228 ) ;
T_1 V_12 ;
if ( ( V_13 % 8 ) != 0 )
return - V_31 ;
if ( ( * V_371 % 8 ) != 0 )
return - V_31 ;
if ( ( unsigned long ) V_375 % 8 != 0 )
return - V_31 ;
if ( * V_371 + V_13 > ( V_379 + V_374 ) )
return - V_31 ;
if ( * V_371 < V_379 )
V_376 += * V_371 ;
V_378 = * V_371 ;
for ( V_377 = 0 ; V_377 < V_13 ; V_377 += 8 , V_378 += 8 ) {
if ( F_146 ( V_378 ) ) {
if ( F_147 ( V_65 , V_378 , ( T_1 * ) & V_12 ) )
break;
}
else if ( V_378 == V_380
|| V_378 == V_381
|| V_378 == V_382
|| V_378 == V_383
|| V_378 == V_384
|| V_378 == V_385 )
V_12 = 0 ;
else if ( V_378 >= V_379 ) {
if ( F_148 ( V_65 ,
( T_11 ) ( V_378 - V_379 ) ,
sizeof( V_12 ) , & V_12 ) )
break;
} else
V_12 = F_149 ( V_376 + V_377 ) ;
if ( F_150 ( V_12 , ( unsigned long T_3 * ) ( V_375 + V_377 ) ) )
break;
}
* V_371 += V_377 ;
return V_377 ;
}
static T_2 F_151 ( struct V_5 * V_365 , const char T_3 * V_375 ,
T_4 V_13 , T_5 * V_371 )
{
struct V_64 * V_65 = V_365 -> V_7 ;
void T_12 * V_376 ;
unsigned long V_377 , V_12 , V_378 ;
int V_386 ;
if ( ( V_13 % 8 ) != 0 )
return - V_31 ;
if ( ( * V_371 % 8 ) != 0 )
return - V_31 ;
if ( ( unsigned long ) V_375 % 8 != 0 )
return - V_31 ;
if ( * V_371 + V_13 > V_65 -> V_373 - V_65 -> V_228 )
return - V_31 ;
V_376 = ( void T_12 * ) V_65 -> V_228 + * V_371 ;
V_378 = * V_371 ;
V_386 = 0 ;
for ( V_377 = 0 ; V_377 < V_13 ; V_377 += 8 , V_378 += 8 ) {
if ( F_152 ( V_12 , ( unsigned long T_3 * ) ( V_375 + V_377 ) ) )
break;
if ( F_146 ( V_378 ) ) {
if ( ! V_386 ) {
int V_26 = F_153 ( V_65 , 1 ) ;
if ( V_26 )
break;
V_386 = 1 ;
}
} else {
if ( V_386 ) {
F_154 ( V_65 , 1 ) ;
V_386 = 0 ;
}
}
F_155 ( V_12 , V_376 + V_377 ) ;
}
if ( V_386 )
F_154 ( V_65 , 1 ) ;
* V_371 += V_377 ;
return V_377 ;
}
static void F_156 ( struct V_64 * V_65 )
{
if ( F_157 ( & V_387 ) == 0 )
F_158 ( & V_388 , & V_389 ) ;
F_158 ( & V_65 -> V_390 , & V_65 -> V_391 ) ;
F_158 ( & V_65 -> V_367 , & V_65 -> V_392 ) ;
}
static int F_159 ( struct V_64 * V_65 )
{
char V_393 [ 10 ] ;
int V_26 ;
if ( F_160 ( & V_387 ) == 1 ) {
V_26 = F_161 ( 0 , F_162 () , & V_394 ,
& V_388 , & V_389 ,
true ) ;
if ( V_26 )
goto V_85;
}
snprintf ( V_393 , sizeof( V_393 ) , L_11 , F_162 () , V_65 -> V_267 ) ;
V_26 = F_161 ( V_65 -> V_267 + 1 , V_393 , & V_394 ,
& V_65 -> V_390 , & V_65 -> V_391 ,
true ) ;
if ( V_26 )
goto V_85;
if ( V_395 ) {
snprintf ( V_393 , sizeof( V_393 ) ,
L_12 , F_162 () , V_65 -> V_267 ) ;
V_26 = F_161 ( V_65 -> V_267 + V_396 , V_393 , & V_397 ,
& V_65 -> V_367 , & V_65 -> V_392 ,
false ) ;
if ( V_26 )
goto V_85;
}
return 0 ;
V_85:
F_156 ( V_65 ) ;
return V_26 ;
}
int F_163 ( struct V_64 * V_65 )
{
int V_398 , V_26 ;
V_398 = F_159 ( V_65 ) ;
V_26 = F_164 ( V_65 ) ;
if ( V_398 && ! V_26 )
V_26 = V_398 ;
return V_26 ;
}
void F_165 ( struct V_64 * V_65 )
{
F_156 ( V_65 ) ;
F_166 ( V_65 ) ;
}
