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
unsigned long V_25 ;
T_2 V_26 = 0 , V_27 = 0 , V_28 = 0 ;
void * V_29 = NULL ;
T_6 V_30 = 0 ;
int V_31 = 1 ;
int V_32 = 0 ;
if ( F_6 ( ! F_7 ( V_6 ) ) )
return - V_33 ;
if ( V_13 < sizeof( V_20 ) ) {
V_28 = - V_34 ;
goto V_35;
}
V_16 = ( const struct V_15 T_3 * ) V_12 ;
if ( F_8 ( & V_20 , V_16 , sizeof( V_20 ) ) ) {
V_28 = - V_36 ;
goto V_35;
}
V_26 = sizeof( V_20 ) ;
switch ( V_20 . type ) {
case V_37 :
V_31 = 0 ;
V_27 = sizeof( V_22 ) ;
V_29 = & V_22 ;
break;
case V_38 :
case V_39 :
V_27 = 0 ;
break;
case V_40 :
case V_41 :
case V_42 :
V_27 = sizeof( V_24 ) ;
V_29 = & V_24 ;
break;
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
V_27 = 0 ;
V_30 = V_20 . V_25 ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
V_31 = 0 ;
V_32 = 1 ;
V_27 = 0 ;
break;
default:
V_28 = - V_34 ;
goto V_35;
}
if ( V_27 ) {
if ( F_8 ( V_29 , ( void T_3 * ) V_20 . V_25 , V_27 ) ) {
V_28 = - V_36 ;
goto V_35;
}
V_26 += V_27 ;
}
if ( V_31 && ! V_19 ) {
V_28 = - V_34 ;
goto V_35;
}
if ( V_32 && ! F_9 ( V_55 ) ) {
V_28 = - V_56 ;
goto V_35;
}
switch ( V_20 . type ) {
case V_37 :
V_28 = F_10 ( V_6 , & V_22 ) ;
if ( V_28 < 0 )
goto V_35;
V_28 = F_11 ( V_6 ) ;
if ( V_28 )
goto V_35;
V_28 = F_12 ( V_6 ) ;
break;
case V_47 :
V_28 = F_13 ( V_6 , ( void T_3 * ) ( unsigned long )
V_30 , V_20 . V_57 ) ;
break;
case V_43 :
V_28 = F_14 ( V_6 , ( void T_3 * ) ( unsigned long )
V_30 , V_20 . V_57 ) ;
break;
case V_38 :
break;
case V_39 :
if ( V_19 && V_19 -> V_58 )
F_15 ( V_19 -> V_58 ) ;
break;
case V_40 :
V_28 = F_16 ( V_6 , & V_24 ) ;
if ( ! V_28 ) {
V_25 = ( unsigned long ) V_20 . V_25 +
F_17 ( struct V_23 , V_59 ) ;
if ( F_18 ( ( void T_3 * ) V_25 , & V_24 . V_59 ,
sizeof( V_24 . V_59 ) +
sizeof( V_24 . V_60 ) ) )
V_28 = - V_36 ;
}
break;
case V_42 :
V_28 = F_19 ( V_6 , & V_24 ) ;
if ( V_28 )
break;
V_25 = ( unsigned long ) V_20 . V_25 +
F_17 ( struct V_23 , V_59 ) ;
if ( F_18 ( ( void T_3 * ) V_25 , & V_24 . V_59 ,
sizeof( V_24 . V_59 ) ) )
V_28 = - V_36 ;
break;
case V_41 :
V_28 = F_20 ( V_6 , & V_24 ) ;
if ( V_28 )
break;
V_25 = ( unsigned long ) V_20 . V_25 +
F_17 ( struct V_23 , V_59 ) ;
if ( F_18 ( ( void T_3 * ) V_25 , & V_24 . V_59 ,
sizeof( V_24 . V_59 ) ) )
V_28 = - V_36 ;
break;
case V_44 :
V_28 = F_21 ( V_19 , V_17 -> V_61 , ( int ) V_30 ) ;
break;
case V_45 :
V_19 -> V_62 = ( F_22 ( V_19 -> V_62 ) ) V_30 ;
break;
case V_46 :
V_28 = F_23 ( V_19 , V_17 -> V_61 , V_30 ) ;
break;
case V_48 :
if ( F_24 ( V_63 ) )
V_28 = F_25 ( V_19 , V_17 -> V_61 , V_30 ) ;
else
V_28 = - V_56 ;
break;
case V_49 : {
struct V_64 * V_58 ;
struct V_65 * V_66 ;
if ( ! V_19 || ! V_19 -> V_66 || ! V_19 -> V_58 ) {
V_28 = - V_34 ;
break;
}
V_66 = V_19 -> V_66 ;
V_58 = V_19 -> V_58 ;
F_26 (
V_58 -> V_67 , ( V_58 -> V_68 & V_69 ) ,
F_27 ( V_70 ) ) ;
if ( ! ( V_58 -> V_68 & V_69 ) ) {
V_28 = - V_71 ;
break;
}
if ( V_58 -> V_68 & V_72 ) {
F_26 (
V_66 -> V_73 ,
! ( F_28 ( V_66 -> V_68 ) & V_74 ) ,
F_27 ( V_70 ) ) ;
if ( V_66 -> V_68 & V_74 ) {
V_28 = - V_71 ;
break;
}
if ( V_66 -> V_68 & V_75 ) {
V_28 = - V_76 ;
break;
}
F_29 ( V_58 ) ;
V_28 = F_30 ( V_58 ) ;
F_31 ( V_66 , V_77 ,
V_19 -> V_78 ) ;
} else {
V_28 = F_32 ( V_58 ) ;
}
if ( ! V_28 )
F_15 ( V_58 ) ;
break;
}
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
V_28 = F_33 ( V_6 , & V_20 ) ;
break;
}
if ( V_28 >= 0 )
V_28 = V_26 ;
V_35:
return V_28 ;
}
static T_2 F_34 ( struct V_79 * V_79 , struct V_80 * V_81 )
{
struct V_8 * V_17 = V_79 -> V_82 -> V_7 ;
struct V_83 * V_84 = V_17 -> V_84 ;
struct V_85 * V_86 = V_17 -> V_86 ;
int V_28 = 0 , V_87 = 0 , V_88 = 0 ;
unsigned long V_89 = V_81 -> V_90 ;
if ( ! V_86 || ! V_84 ) {
V_28 = - V_91 ;
goto V_87;
}
if ( ! F_35 ( V_81 ) || ! V_89 ) {
V_28 = - V_34 ;
goto V_87;
}
F_36 ( V_92 , L_1 ,
V_17 -> V_19 -> V_78 , V_17 -> V_61 , V_89 ) ;
if ( F_37 ( & V_84 -> V_93 ) == V_84 -> V_94 ) {
V_28 = - V_95 ;
goto V_87;
}
while ( V_89 ) {
unsigned long V_13 = 0 ;
V_28 = F_38 (
V_79 -> V_82 , (struct V_96 * ) ( V_81 -> V_97 + V_87 ) ,
V_89 , & V_13 ) ;
if ( V_28 )
goto V_87;
V_89 -= V_13 ;
V_87 += V_13 ;
V_88 ++ ;
}
V_87:
return V_28 ? V_28 : V_88 ;
}
static int F_39 ( struct V_5 * V_6 , struct V_98 * V_99 )
{
struct V_8 * V_17 = V_6 -> V_7 ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_65 * V_66 ;
unsigned long V_68 , V_100 ;
T_1 V_1 = V_99 -> V_101 << V_102 ,
V_103 = 0 ;
T_7 V_61 , V_104 = 0 , V_105 = 0 , type ;
T_2 V_106 = 0 ;
int V_28 = 0 ;
T_8 V_78 ;
if ( ! F_1 ( V_1 ) || ! V_19 ||
! ( V_99 -> V_107 & V_108 ) ) {
V_28 = - V_34 ;
goto V_87;
}
V_66 = V_19 -> V_66 ;
V_78 = F_2 ( V_109 , V_1 ) ;
V_61 = F_2 ( V_110 , V_1 ) ;
type = F_2 ( TYPE , V_1 ) ;
if ( V_78 != V_19 -> V_78 || V_61 != V_17 -> V_61 ) {
V_28 = - V_34 ;
goto V_87;
}
V_68 = V_99 -> V_107 ;
switch ( type ) {
case V_111 :
case V_112 :
V_103 = ( ( V_66 -> V_113 + V_114 ) +
( V_19 -> V_58 -> V_115 * F_40 ( 16 ) ) ) +
( type == V_112 ?
( V_116 / 2 ) : 0 ) ;
V_106 = F_41 ( V_19 -> V_58 -> V_117 * V_118 ) ;
V_68 &= ~ V_119 ;
V_68 |= V_120 | V_121 ;
V_99 -> V_122 = F_42 ( V_99 -> V_122 ) ;
V_104 = 1 ;
break;
case V_123 :
if ( V_68 & V_124 ) {
V_28 = - V_56 ;
goto V_87;
}
V_103 = V_66 -> V_125 [ V_19 -> V_126 ] . V_127 +
( ( ( T_1 ) V_19 -> V_58 -> V_128 -
( T_1 ) V_66 -> V_125 [ V_19 -> V_126 ] . V_129 ) & V_130 ) ;
V_106 = V_131 ;
V_68 &= ~ V_132 ;
V_68 |= V_120 | V_121 ;
V_104 = 1 ;
break;
case V_133 :
V_103 = V_19 -> V_134 ;
V_106 = V_19 -> V_135 ;
break;
case V_136 : {
unsigned long V_25 ;
int V_137 ;
V_106 = V_19 -> V_138 . V_139 ;
if ( ( V_99 -> V_140 - V_99 -> V_141 ) != V_106 ) {
F_43 ( V_66 , L_2 ,
( V_99 -> V_140 - V_99 -> V_141 ) , V_106 ) ;
V_28 = - V_34 ;
goto V_87;
}
if ( V_99 -> V_107 & V_124 ) {
V_28 = - V_56 ;
goto V_87;
}
V_99 -> V_107 &= ~ V_132 ;
V_25 = V_99 -> V_141 ;
for ( V_137 = 0 ; V_137 < V_19 -> V_138 . V_142 ; V_137 ++ ) {
V_28 = F_44 (
V_99 , V_25 ,
V_19 -> V_138 . V_143 [ V_137 ] . V_144 >> V_102 ,
V_19 -> V_138 . V_143 [ V_137 ] . V_57 ,
V_99 -> V_122 ) ;
if ( V_28 < 0 )
goto V_87;
V_25 += V_19 -> V_138 . V_143 [ V_137 ] . V_57 ;
}
V_28 = 0 ;
goto V_87;
}
case V_145 :
V_103 = ( unsigned long )
( V_66 -> V_113 + V_146 )
+ ( V_19 -> V_78 * V_147 ) ;
V_106 = V_131 ;
V_68 |= V_120 | V_121 ;
V_99 -> V_122 = F_45 ( V_99 -> V_122 ) ;
V_104 = 1 ;
break;
case V_148 :
V_103 = ( unsigned long ) ( V_66 -> V_149 +
( ( V_19 -> V_78 - V_66 -> V_150 ) *
V_151 ) ) & V_130 ;
V_106 = V_131 ;
V_68 |= V_152 | V_121 ;
V_105 = 1 ;
break;
case V_153 :
V_103 = F_46 ( ( void * ) V_66 -> V_154 ) ;
V_106 = V_131 ;
V_68 |= V_152 | V_121 ;
break;
case V_155 :
if ( ! F_24 ( V_156 ) ) {
V_28 = - V_34 ;
goto V_87;
}
if ( V_68 & V_124 ) {
V_28 = - V_56 ;
goto V_87;
}
V_103 = V_19 -> V_157 ;
V_106 = V_131 ;
V_68 &= ~ V_132 ;
break;
case V_158 :
V_103 = ( T_1 ) V_19 -> V_159 ;
V_106 = V_131 ;
V_68 |= V_152 | V_121 ;
V_105 = 1 ;
break;
case V_160 :
V_103 = ( T_1 ) V_19 -> V_161 ;
V_106 = V_19 -> V_135 * V_19 -> V_162 ;
V_68 |= V_152 | V_121 ;
V_105 = 1 ;
break;
case V_163 :
V_103 = ( T_1 ) V_19 -> V_164 ;
V_106 = V_19 -> V_138 . V_139 * V_19 -> V_162 ;
V_68 |= V_152 | V_121 ;
V_68 &= ~ V_132 ;
V_105 = 1 ;
break;
case V_165 : {
struct V_85 * V_86 = V_17 -> V_86 ;
if ( ! V_86 ) {
V_28 = - V_36 ;
goto V_87;
}
V_103 = ( T_1 ) V_86 -> V_166 ;
V_106 = F_41 ( sizeof( * V_86 -> V_166 ) * V_86 -> V_167 ) ;
V_68 |= V_152 | V_121 ;
V_105 = 1 ;
break;
}
default:
V_28 = - V_34 ;
break;
}
if ( ( V_99 -> V_140 - V_99 -> V_141 ) != V_106 ) {
F_36 ( V_168 , L_3 ,
V_19 -> V_78 , V_17 -> V_61 ,
( V_99 -> V_140 - V_99 -> V_141 ) , V_106 ) ;
V_28 = - V_34 ;
goto V_87;
}
V_99 -> V_107 = V_68 ;
F_36 ( V_168 ,
L_4 ,
V_78 , V_61 , type , V_104 , V_105 , V_103 , V_106 ,
V_99 -> V_140 - V_99 -> V_141 , V_99 -> V_107 ) ;
V_100 = ( unsigned long ) ( V_103 >> V_102 ) ;
if ( V_105 ) {
V_99 -> V_101 = V_100 ;
V_99 -> V_169 = & V_169 ;
V_28 = 0 ;
} else if ( V_104 ) {
V_28 = F_47 ( V_99 , V_99 -> V_141 , V_100 , V_106 ,
V_99 -> V_122 ) ;
} else {
V_28 = F_44 ( V_99 , V_99 -> V_141 , V_100 , V_106 ,
V_99 -> V_122 ) ;
}
V_87:
return V_28 ;
}
static int F_48 ( struct V_98 * V_99 , struct V_170 * V_105 )
{
struct V_171 * V_171 ;
V_171 = F_49 ( ( void * ) ( V_105 -> V_172 << V_102 ) ) ;
if ( ! V_171 )
return V_173 ;
F_50 ( V_171 ) ;
V_105 -> V_171 = V_171 ;
return 0 ;
}
static unsigned int F_51 ( struct V_5 * V_6 , struct V_174 * V_175 )
{
struct V_18 * V_19 ;
unsigned V_176 ;
V_19 = ( (struct V_8 * ) V_6 -> V_7 ) -> V_19 ;
if ( ! V_19 )
V_176 = V_177 ;
else if ( V_19 -> V_62 == V_178 )
V_176 = F_52 ( V_6 , V_175 ) ;
else if ( V_19 -> V_62 == V_179 )
V_176 = F_53 ( V_6 , V_175 ) ;
else
V_176 = V_177 ;
return V_176 ;
}
static int F_54 ( struct V_4 * V_4 , struct V_5 * V_6 )
{
struct V_8 * V_180 = V_6 -> V_7 ;
struct V_18 * V_19 = V_180 -> V_19 ;
struct V_65 * V_66 ;
unsigned long V_68 , * V_181 ;
V_6 -> V_7 = NULL ;
if ( ! V_19 )
goto V_87;
F_36 ( V_168 , L_5 , V_19 -> V_78 , V_180 -> V_61 ) ;
V_66 = V_19 -> V_66 ;
F_55 ( & V_182 ) ;
F_56 () ;
F_57 ( V_180 ) ;
F_58 ( V_66 , V_180 -> V_10 ) ;
V_181 = V_66 -> V_149 + ( ( V_19 -> V_78 - V_66 -> V_150 ) *
V_151 ) + V_180 -> V_61 ;
* V_181 = 0 ;
if ( -- V_19 -> V_183 ) {
V_19 -> V_184 &= ~ ( 1 << V_180 -> V_61 ) ;
V_19 -> V_185 [ V_180 -> V_61 ] = 0 ;
F_59 ( & V_182 ) ;
goto V_87;
}
F_60 ( & V_66 -> V_186 , V_68 ) ;
F_31 ( V_66 , V_187 |
V_188 |
V_189 |
V_190 |
V_191 |
V_192 |
V_193 , V_19 -> V_78 ) ;
F_61 ( V_66 , V_19 -> V_78 ) ;
F_62 ( V_66 , V_19 -> V_58 -> V_115 , V_194 ,
F_63 ( V_66 , V_19 -> V_58 -> type ) ) ;
F_29 ( V_19 -> V_58 ) ;
V_19 -> V_195 = 0 ;
F_64 ( & V_66 -> V_186 , V_68 ) ;
V_66 -> V_196 [ V_19 -> V_78 ] = NULL ;
F_65 ( V_180 ) ;
F_66 ( V_66 , V_19 -> V_78 ) ;
V_19 -> V_197 = 0 ;
V_19 -> V_198 = 0 ;
V_19 -> V_199 = 0 ;
V_19 -> V_200 = 0 ;
V_19 -> V_201 = 0 ;
V_202 . V_203 -- ;
if ( ++ V_66 -> V_204 == V_66 -> V_205 )
F_67 ( V_66 ) ;
F_59 ( & V_182 ) ;
F_68 ( V_66 , V_19 ) ;
V_87:
F_69 ( V_180 ) ;
return 0 ;
}
static T_1 F_46 ( void * V_25 )
{
struct V_171 * V_171 ;
T_1 V_206 = 0 ;
V_171 = F_49 ( V_25 ) ;
if ( V_171 )
V_206 = F_70 ( V_171 ) << V_102 ;
return V_206 ;
}
static int F_10 ( struct V_5 * V_6 , struct V_21 * V_22 )
{
int V_207 , V_28 = 0 ;
unsigned V_208 , V_209 , V_210 = V_211 ;
V_208 = V_22 -> V_212 >> 16 ;
if ( V_208 != V_213 ) {
V_28 = - V_76 ;
goto V_87;
}
V_209 = V_22 -> V_212 & 0xffff ;
if ( V_22 -> V_214 < V_215 )
V_210 = V_22 -> V_214 ;
F_55 ( & V_182 ) ;
if ( V_22 -> V_162 ) {
struct V_8 * V_17 = V_6 -> V_7 ;
V_28 = F_71 ( V_6 , V_22 ) ;
if ( V_28 < 0 )
goto V_216;
if ( V_28 )
V_17 -> V_10 = F_72 (
V_17 -> V_19 -> V_66 , V_17 -> V_19 -> V_126 ) ;
}
if ( ! V_28 ) {
V_207 = F_73 ( F_74 ( V_6 ) ) - V_217 ;
V_28 = F_75 ( V_6 , V_22 , V_207 - 1 , V_210 ) ;
}
V_216:
F_59 ( & V_182 ) ;
V_87:
return V_28 ;
}
static int F_76 ( struct V_65 * V_66 )
{
struct V_218 * V_219 = V_66 -> V_220 ;
return F_77 ( V_219 ) == V_221 ;
}
static int F_75 ( struct V_5 * V_6 , struct V_21 * V_22 ,
int V_222 , unsigned V_210 )
{
struct V_65 * V_66 = NULL ;
int V_28 = 0 , V_223 , V_224 , V_225 , V_226 ;
V_223 = F_78 ( & V_224 , & V_225 ) ;
if ( ! V_224 ) {
V_28 = - V_227 ;
goto V_87;
}
if ( ! V_225 ) {
V_28 = - V_228 ;
goto V_87;
}
if ( V_222 >= 0 ) {
V_66 = F_79 ( V_222 ) ;
if ( ! V_66 )
V_28 = - V_76 ;
else if ( ! V_66 -> V_204 )
V_28 = - V_229 ;
} else {
struct V_65 * V_230 ;
if ( V_210 == V_211 ) {
unsigned free = 0U ;
for ( V_226 = 0 ; V_226 < V_223 ; V_226 ++ ) {
V_230 = F_79 ( V_226 ) ;
if ( ! V_230 )
continue;
if ( ! F_76 ( V_230 ) )
continue;
if ( V_230 -> V_204 &&
V_230 -> V_204 > free ) {
V_66 = V_230 ;
free = V_230 -> V_204 ;
}
}
} else {
for ( V_226 = 0 ; V_226 < V_223 ; V_226 ++ ) {
V_230 = F_79 ( V_226 ) ;
if ( ! V_230 )
continue;
if ( ! F_76 ( V_230 ) )
continue;
if ( V_230 -> V_204 ) {
V_66 = V_230 ;
break;
}
}
}
if ( ! V_66 )
V_28 = - V_229 ;
}
V_87:
return V_28 ? V_28 : F_80 ( V_6 , V_66 , V_22 ) ;
}
static int F_71 ( struct V_5 * V_6 ,
const struct V_21 * V_22 )
{
int V_223 , V_231 , V_137 ;
int V_28 = 0 ;
struct V_8 * V_17 = V_6 -> V_7 ;
V_223 = F_78 ( NULL , NULL ) ;
for ( V_231 = 0 ; V_231 < V_223 ; V_231 ++ ) {
struct V_65 * V_66 = F_79 ( V_231 ) ;
if ( ! ( V_66 && ( V_66 -> V_68 & V_232 ) && V_66 -> V_233 ) )
continue;
for ( V_137 = V_66 -> V_150 ; V_137 < V_66 -> V_234 ; V_137 ++ ) {
struct V_18 * V_19 = V_66 -> V_196 [ V_137 ] ;
if ( ! V_19 || ! V_19 -> V_183 )
continue;
if ( memcmp ( V_19 -> V_235 , V_22 -> V_235 ,
sizeof( V_19 -> V_235 ) ) ||
V_19 -> V_236 != F_81 ( F_82 () ) ||
V_19 -> V_237 != V_22 -> V_237 ||
V_19 -> V_162 != V_22 -> V_162 )
continue;
if ( V_19 -> V_212 != V_22 -> V_212 ||
V_19 -> V_183 >= V_19 -> V_162 ) {
V_28 = - V_34 ;
goto V_87;
}
V_17 -> V_19 = V_19 ;
V_17 -> V_61 = V_19 -> V_183 ++ ;
V_19 -> V_185 [ V_17 -> V_61 ] = V_238 -> V_195 ;
V_19 -> V_184 |= 1 << V_17 -> V_61 ;
V_28 = 1 ;
goto V_87;
}
}
V_87:
return V_28 ;
}
static int F_80 ( struct V_5 * V_6 , struct V_65 * V_66 ,
struct V_21 * V_22 )
{
struct V_8 * V_17 = V_6 -> V_7 ;
struct V_18 * V_19 ;
unsigned V_78 ;
int V_28 , V_239 ;
if ( V_66 -> V_68 & V_74 ) {
return - V_91 ;
}
for ( V_78 = V_66 -> V_150 ; V_78 < V_66 -> V_234 ; V_78 ++ )
if ( ! V_66 -> V_196 [ V_78 ] )
break;
if ( V_78 == V_66 -> V_234 )
return - V_229 ;
V_17 -> V_10 = F_72 ( V_66 , - 1 ) ;
if ( V_17 -> V_10 != - 1 )
V_239 = F_83 ( V_17 -> V_10 ) ;
else
V_239 = F_84 () ;
V_19 = F_85 ( V_66 -> V_220 , V_78 , V_239 ) ;
if ( ! V_19 ) {
F_43 ( V_66 ,
L_6 ) ;
return - V_11 ;
}
F_36 ( V_168 , L_7 ,
V_19 -> V_78 , V_17 -> V_61 , V_238 -> V_195 , V_17 -> V_10 ,
V_19 -> V_126 ) ;
V_19 -> V_58 = F_86 ( V_66 , V_240 , V_19 -> V_241 ,
V_19 -> V_66 -> V_242 ) ;
if ( ! V_19 -> V_58 )
return - V_11 ;
F_36 ( V_168 , L_8 , V_19 -> V_58 -> V_243 ,
V_19 -> V_58 -> V_115 ) ;
V_28 = F_30 ( V_19 -> V_58 ) ;
if ( V_28 )
return V_28 ;
if ( V_22 -> V_162 && ! V_17 -> V_61 ) {
V_28 = F_87 ( V_19 , V_22 ) ;
if ( V_28 )
return V_28 ;
}
V_19 -> V_212 = V_22 -> V_212 ;
V_19 -> V_195 = V_238 -> V_195 ;
V_19 -> V_68 = F_88 ( V_244 ) ;
F_89 ( & V_19 -> V_245 ) ;
F_90 ( V_19 -> V_246 , V_238 -> V_246 , sizeof( V_19 -> V_246 ) ) ;
memcpy ( V_19 -> V_235 , V_22 -> V_235 , sizeof( V_19 -> V_235 ) ) ;
V_19 -> V_236 = F_81 ( F_82 () ) ;
F_91 ( & V_19 -> V_247 ) ;
F_92 ( & V_19 -> V_248 ) ;
V_202 . V_203 ++ ;
if ( V_66 -> V_204 -- == V_66 -> V_205 )
F_93 ( V_66 ) ;
V_17 -> V_19 = V_19 ;
return 0 ;
}
static int F_87 ( struct V_18 * V_19 ,
const struct V_21 * V_22 )
{
unsigned V_249 ;
V_249 = V_22 -> V_162 ;
if ( V_249 > V_151 )
return - V_34 ;
V_19 -> V_162 = V_22 -> V_162 ;
V_19 -> V_237 = V_22 -> V_237 ;
V_19 -> V_184 = 1 ;
V_19 -> V_250 = 1 ;
F_94 ( V_251 , & V_19 -> V_201 ) ;
return 0 ;
}
static int F_95 ( struct V_18 * V_19 )
{
int V_28 = 0 ;
unsigned V_249 = V_19 -> V_162 ;
V_19 -> V_159 = F_96 ( V_131 ) ;
if ( ! V_19 -> V_159 ) {
V_28 = - V_11 ;
goto V_35;
}
V_19 -> V_161 = F_96 ( V_19 -> V_135 *
V_249 ) ;
if ( ! V_19 -> V_161 ) {
V_28 = - V_11 ;
goto V_252;
}
V_19 -> V_164 = F_96 ( V_19 -> V_138 . V_139 *
V_249 ) ;
if ( ! V_19 -> V_164 ) {
V_28 = - V_11 ;
goto V_253;
}
goto V_35;
V_253:
F_97 ( V_19 -> V_161 ) ;
V_252:
F_97 ( V_19 -> V_159 ) ;
V_19 -> V_159 = NULL ;
V_35:
return V_28 ;
}
static int F_12 ( struct V_5 * V_6 )
{
unsigned int V_254 = 0 ;
struct V_8 * V_17 = V_6 -> V_7 ;
struct V_18 * V_19 = V_17 -> V_19 ;
if ( ! F_98 ( V_255 , & V_19 -> V_201 ) )
return - V_36 ;
V_19 -> V_256 = 0 ;
V_19 -> V_257 = 0 ;
if ( V_19 -> V_258 )
F_99 ( V_19 ) ;
F_100 ( V_19 -> V_66 , V_19 -> V_78 , V_19 -> V_236 ) ;
V_254 = V_77 ;
if ( F_101 ( V_19 -> V_68 , V_259 ) )
V_254 |= V_260 ;
if ( ! F_101 ( V_19 -> V_68 , V_261 ) )
V_254 |= V_262 ;
if ( F_101 ( V_19 -> V_68 , V_263 ) )
V_254 |= V_264 ;
if ( F_101 ( V_19 -> V_68 , V_265 ) )
V_254 |= V_266 ;
if ( F_101 ( V_19 -> V_68 , V_156 ) )
V_254 |= V_267 ;
else
V_254 |= V_190 ;
F_31 ( V_19 -> V_66 , V_254 , V_19 -> V_78 ) ;
if ( V_19 -> V_162 ) {
F_102 ( V_251 , & V_19 -> V_201 ) ;
F_103 ( & V_19 -> V_245 ) ;
}
return 0 ;
}
static int F_13 ( struct V_5 * V_6 , void T_3 * V_268 , T_9 V_57 )
{
struct V_269 V_270 ;
struct V_8 * V_17 = V_6 -> V_7 ;
struct V_18 * V_19 = V_17 -> V_19 ;
int V_28 = 0 ;
memset ( & V_270 , 0 , sizeof( V_270 ) ) ;
V_28 = F_104 ( V_19 , & V_270 ) ;
if ( V_28 < 0 )
goto V_87;
V_270 . V_271 = F_105 () ;
V_270 . V_272 = V_19 -> V_66 -> V_272 ;
V_270 . V_78 = V_19 -> V_78 ;
V_270 . V_61 = V_17 -> V_61 ;
V_270 . V_273 = F_106 ( V_19 -> V_138 . V_274 ,
V_19 -> V_66 -> V_275 . V_276 ) +
V_19 -> V_277 ;
V_270 . V_117 = V_19 -> V_58 -> V_117 ;
V_270 . V_278 = V_19 -> V_126 ;
V_270 . V_279 = V_17 -> V_10 ;
V_270 . V_280 = V_19 -> V_58 -> V_115 ;
V_270 . V_281 = V_19 -> V_138 . V_274 ;
V_270 . V_282 = V_19 -> V_282 ;
V_270 . V_283 = V_19 -> V_241 << 2 ;
V_270 . V_284 = V_17 -> V_86 -> V_167 ;
V_270 . V_285 = V_19 -> V_138 . V_286 ;
F_107 ( V_19 -> V_66 , V_19 -> V_78 , V_17 -> V_61 , V_270 ) ;
if ( F_18 ( V_268 , & V_270 , sizeof( V_270 ) ) )
V_28 = - V_36 ;
V_87:
return V_28 ;
}
static int F_11 ( struct V_5 * V_6 )
{
struct V_8 * V_17 = V_6 -> V_7 ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_65 * V_66 = V_19 -> V_66 ;
int V_28 = 0 ;
if ( ! V_19 -> V_162 || ! V_17 -> V_61 ) {
V_28 = F_108 ( V_19 -> V_58 ) ;
if ( V_28 )
goto V_87;
V_28 = F_109 ( V_66 , V_19 ) ;
if ( V_28 )
goto V_87;
V_28 = F_110 ( V_19 ) ;
if ( V_28 )
goto V_87;
if ( V_19 -> V_162 && ! V_17 -> V_61 ) {
V_28 = F_95 ( V_19 ) ;
if ( V_28 )
goto V_87;
}
} else {
V_28 = F_111 ( V_19 -> V_245 , ! F_98 (
V_251 ,
& V_19 -> V_201 ) ) ;
if ( V_28 )
goto V_87;
}
V_28 = F_112 ( V_19 , V_6 ) ;
if ( V_28 )
goto V_87;
V_28 = F_113 ( V_6 ) ;
if ( V_28 )
goto V_87;
F_94 ( V_255 , & V_19 -> V_201 ) ;
V_87:
return V_28 ;
}
static int F_14 ( struct V_5 * V_6 , void T_3 * V_268 , T_9 V_57 )
{
struct V_287 V_288 ;
struct V_8 * V_17 = V_6 -> V_7 ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_65 * V_66 = V_19 -> V_66 ;
T_2 V_289 ;
unsigned V_14 ;
int V_28 = 0 ;
F_114 ( V_19 -> V_66 , V_19 ) ;
memset ( & V_288 , 0 , sizeof( V_288 ) ) ;
V_288 . V_290 = V_66 -> V_291 ;
V_288 . V_292 = V_293 ;
V_288 . V_294 = V_295 ;
V_288 . V_236 = V_19 -> V_236 ;
V_14 = ( ( T_1 ) V_19 -> V_58 -> V_128 -
( T_1 ) V_66 -> V_125 [ V_19 -> V_126 ] . V_129 ) % V_131 ;
V_288 . V_296 = F_115 ( V_123 , V_19 -> V_78 ,
V_17 -> V_61 , V_14 ) ;
V_288 . V_297 = F_115 ( V_111 , V_19 -> V_78 ,
V_17 -> V_61 ,
V_19 -> V_58 -> V_298 ) ;
V_288 . V_299 = F_115 ( V_112 ,
V_19 -> V_78 ,
V_17 -> V_61 ,
V_19 -> V_58 -> V_298 ) ;
V_288 . V_300 = F_115 ( V_133 , V_19 -> V_78 ,
V_17 -> V_61 ,
V_19 -> V_301 ) ;
V_288 . V_302 = F_115 ( V_136 , V_19 -> V_78 ,
V_17 -> V_61 ,
V_19 -> V_138 . V_273 [ 0 ] . V_144 ) ;
V_288 . V_303 = F_115 ( V_165 , V_19 -> V_78 ,
V_17 -> V_61 , 0 ) ;
V_288 . V_304 = F_115 ( V_145 , V_19 -> V_78 ,
V_17 -> V_61 , 0 ) ;
V_14 = F_116 ( ( ( ( V_19 -> V_78 - V_66 -> V_150 ) *
V_151 ) + V_17 -> V_61 ) *
sizeof( * V_66 -> V_149 ) ) ;
V_288 . V_305 = F_115 ( V_148 , V_19 -> V_78 ,
V_17 -> V_61 ,
V_14 ) ;
V_288 . V_306 = F_115 ( V_153 , V_19 -> V_78 ,
V_17 -> V_61 ,
V_66 -> V_154 ) ;
if ( F_24 ( V_156 ) )
V_288 . V_307 = F_115 ( V_155 , V_19 -> V_78 ,
V_17 -> V_61 , 0 ) ;
if ( V_19 -> V_162 ) {
V_288 . V_159 = F_115 ( V_158 ,
V_19 -> V_78 ,
V_17 -> V_61 , 0 ) ;
V_288 . V_308 = F_115 ( V_160 ,
V_19 -> V_78 ,
V_17 -> V_61 , 0 ) ;
V_288 . V_164 = F_115 ( V_163 ,
V_19 -> V_78 ,
V_17 -> V_61 , 0 ) ;
}
V_289 = ( V_57 < sizeof( V_288 ) ) ? V_57 : sizeof( V_288 ) ;
if ( F_18 ( V_268 , & V_288 , V_289 ) )
V_28 = - V_36 ;
return V_28 ;
}
static unsigned int F_52 ( struct V_5 * V_6 ,
struct V_174 * V_175 )
{
struct V_8 * V_17 = V_6 -> V_7 ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_65 * V_66 = V_19 -> V_66 ;
unsigned V_176 ;
F_117 ( V_6 , & V_19 -> V_245 , V_175 ) ;
F_118 ( & V_66 -> V_186 ) ;
if ( V_19 -> V_256 != V_19 -> V_257 ) {
V_176 = V_309 | V_310 ;
V_19 -> V_257 = V_19 -> V_256 ;
} else {
V_176 = 0 ;
F_94 ( V_311 , & V_19 -> V_201 ) ;
}
F_119 ( & V_66 -> V_186 ) ;
return V_176 ;
}
static unsigned int F_53 ( struct V_5 * V_6 ,
struct V_174 * V_175 )
{
struct V_8 * V_17 = V_6 -> V_7 ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_65 * V_66 = V_19 -> V_66 ;
unsigned V_176 ;
F_117 ( V_6 , & V_19 -> V_245 , V_175 ) ;
F_118 ( & V_66 -> V_186 ) ;
if ( F_120 ( V_19 ) ) {
F_94 ( V_312 , & V_19 -> V_201 ) ;
F_31 ( V_66 , V_313 , V_19 -> V_78 ) ;
V_176 = 0 ;
} else {
V_176 = V_309 | V_310 ;
}
F_119 ( & V_66 -> V_186 ) ;
return V_176 ;
}
int F_121 ( struct V_218 * V_219 , const int V_314 )
{
struct V_18 * V_19 ;
struct V_65 * V_66 = V_219 -> V_66 ;
unsigned V_78 ;
int V_28 = 0 ;
unsigned long V_68 ;
if ( ! V_66 -> V_149 ) {
V_28 = - V_34 ;
goto V_87;
}
F_60 ( & V_66 -> V_186 , V_68 ) ;
for ( V_78 = V_66 -> V_150 ; V_78 < V_66 -> V_234 ;
V_78 ++ ) {
V_19 = V_66 -> V_196 [ V_78 ] ;
if ( V_19 ) {
unsigned long * V_315 = V_66 -> V_149 +
( V_19 -> V_78 - V_66 -> V_150 ) *
V_151 ;
int V_137 ;
F_94 ( V_314 , V_315 ) ;
for ( V_137 = 1 ; V_137 < V_19 -> V_162 ; V_137 ++ )
F_94 ( V_314 , V_315 + V_137 ) ;
}
}
F_64 ( & V_66 -> V_186 , V_68 ) ;
V_87:
return V_28 ;
}
static int F_21 ( struct V_18 * V_19 , unsigned V_61 ,
int V_316 )
{
struct V_65 * V_66 = V_19 -> V_66 ;
unsigned int V_317 ;
if ( V_61 )
goto V_35;
if ( V_316 ) {
if ( V_19 -> V_258 )
F_99 ( V_19 ) ;
V_317 = V_77 ;
} else {
V_317 = V_187 ;
}
F_31 ( V_66 , V_317 , V_19 -> V_78 ) ;
V_35:
return 0 ;
}
static int F_23 ( struct V_18 * V_19 , int V_61 ,
unsigned long V_149 )
{
int V_137 ;
struct V_65 * V_66 = V_19 -> V_66 ;
unsigned long * V_315 ;
if ( ! V_66 -> V_149 )
return 0 ;
V_315 = V_66 -> V_149 + ( ( V_19 -> V_78 - V_66 -> V_150 ) *
V_151 ) + V_61 ;
for ( V_137 = 0 ; V_137 <= V_318 ; V_137 ++ ) {
if ( ! F_98 ( V_137 , & V_149 ) )
continue;
F_102 ( V_137 , V_315 ) ;
}
return 0 ;
}
static int F_25 ( struct V_18 * V_19 , unsigned V_61 ,
T_8 V_319 )
{
int V_28 = - V_320 , V_137 , V_321 = 0 ;
struct V_218 * V_219 = V_19 -> V_219 ;
struct V_65 * V_66 = V_19 -> V_66 ;
if ( V_319 == V_322 || V_319 == V_323 ) {
V_28 = - V_34 ;
goto V_87;
}
for ( V_137 = 0 ; V_137 < F_122 ( V_219 -> V_324 ) ; V_137 ++ )
if ( V_319 == V_219 -> V_324 [ V_137 ] ) {
V_321 = 1 ;
break;
}
if ( V_321 )
V_28 = F_123 ( V_66 , V_19 -> V_78 , V_319 ) ;
V_87:
return V_28 ;
}
static int F_124 ( struct V_4 * V_4 , struct V_5 * V_325 )
{
struct V_65 * V_66 ;
V_66 = F_125 ( V_4 -> V_326 , struct V_65 , V_327 ) ;
V_325 -> V_7 = V_66 ;
return 0 ;
}
static int F_126 ( struct V_4 * V_4 , struct V_5 * V_325 )
{
return 0 ;
}
static T_5 F_127 ( struct V_5 * V_325 , T_5 V_14 , int V_328 )
{
struct V_65 * V_66 = V_325 -> V_7 ;
return F_128 ( V_325 , V_14 , V_328 ,
( V_66 -> V_329 - V_66 -> V_233 ) + V_330 ) ;
}
static T_2 F_129 ( struct V_5 * V_325 , char T_3 * V_331 , T_4 V_13 ,
T_5 * V_332 )
{
struct V_65 * V_66 = V_325 -> V_7 ;
void T_10 * V_333 = V_66 -> V_233 ;
unsigned long V_334 , V_335 ,
V_336 = ( V_66 -> V_329 - V_66 -> V_233 ) ;
T_1 V_12 ;
if ( ( V_13 % 8 ) != 0 )
return - V_34 ;
if ( ( * V_332 % 8 ) != 0 )
return - V_34 ;
if ( ( unsigned long ) V_331 % 8 != 0 )
return - V_34 ;
if ( * V_332 + V_13 > ( V_336 + V_330 ) )
return - V_34 ;
if ( * V_332 < V_336 )
V_333 += * V_332 ;
V_335 = * V_332 ;
for ( V_334 = 0 ; V_334 < V_13 ; V_334 += 8 , V_335 += 8 ) {
if ( F_130 ( V_335 ) ) {
if ( F_131 ( V_66 , V_335 , ( T_1 * ) & V_12 ) )
break;
}
else if ( V_335 == V_337 ||
V_335 == V_338 ||
V_335 == V_339 ||
V_335 == V_340 ||
V_335 == V_341 ||
V_335 == V_342 )
V_12 = 0 ;
else if ( V_335 >= V_336 ) {
if ( F_132 ( V_66 ,
( V_343 ) ( V_335 - V_336 ) ,
sizeof( V_12 ) , & V_12 ) )
break;
} else
V_12 = F_133 ( V_333 + V_334 ) ;
if ( F_134 ( V_12 , ( unsigned long T_3 * ) ( V_331 + V_334 ) ) )
break;
}
* V_332 += V_334 ;
return V_334 ;
}
static T_2 F_135 ( struct V_5 * V_325 , const char T_3 * V_331 ,
T_4 V_13 , T_5 * V_332 )
{
struct V_65 * V_66 = V_325 -> V_7 ;
void T_10 * V_333 ;
unsigned long V_334 , V_12 , V_335 ;
int V_344 ;
if ( ( V_13 % 8 ) != 0 )
return - V_34 ;
if ( ( * V_332 % 8 ) != 0 )
return - V_34 ;
if ( ( unsigned long ) V_331 % 8 != 0 )
return - V_34 ;
if ( * V_332 + V_13 > V_66 -> V_329 - V_66 -> V_233 )
return - V_34 ;
V_333 = ( void T_10 * ) V_66 -> V_233 + * V_332 ;
V_335 = * V_332 ;
V_344 = 0 ;
for ( V_334 = 0 ; V_334 < V_13 ; V_334 += 8 , V_335 += 8 ) {
if ( F_136 ( V_12 , ( unsigned long T_3 * ) ( V_331 + V_334 ) ) )
break;
if ( F_130 ( V_335 ) ) {
if ( ! V_344 ) {
int V_28 = F_137 ( V_66 , 1 ) ;
if ( V_28 )
break;
V_344 = 1 ;
}
} else {
if ( V_344 ) {
F_138 ( V_66 , 1 ) ;
V_344 = 0 ;
}
}
F_139 ( V_12 , V_333 + V_334 ) ;
}
if ( V_344 )
F_138 ( V_66 , 1 ) ;
* V_332 += V_334 ;
return V_334 ;
}
static void F_140 ( struct V_65 * V_66 )
{
if ( F_141 ( & V_345 ) == 0 )
F_142 ( & V_346 , & V_347 ) ;
F_142 ( & V_66 -> V_348 , & V_66 -> V_349 ) ;
F_142 ( & V_66 -> V_327 , & V_66 -> V_350 ) ;
}
static int F_143 ( struct V_65 * V_66 )
{
char V_351 [ 10 ] ;
int V_28 ;
if ( F_144 ( & V_345 ) == 1 ) {
V_28 = F_145 ( 0 , F_146 () , & V_352 ,
& V_346 , & V_347 ,
true ) ;
if ( V_28 )
goto V_87;
}
snprintf ( V_351 , sizeof( V_351 ) , L_9 , F_146 () , V_66 -> V_272 ) ;
V_28 = F_145 ( V_66 -> V_272 + 1 , V_351 , & V_352 ,
& V_66 -> V_348 , & V_66 -> V_349 ,
true ) ;
if ( V_28 )
goto V_87;
if ( V_353 ) {
snprintf ( V_351 , sizeof( V_351 ) ,
L_10 , F_146 () , V_66 -> V_272 ) ;
V_28 = F_145 ( V_66 -> V_272 + V_354 , V_351 , & V_355 ,
& V_66 -> V_327 , & V_66 -> V_350 ,
false ) ;
if ( V_28 )
goto V_87;
}
return 0 ;
V_87:
F_140 ( V_66 ) ;
return V_28 ;
}
int F_147 ( struct V_65 * V_66 )
{
int V_356 , V_28 ;
V_356 = F_143 ( V_66 ) ;
V_28 = F_148 ( V_66 ) ;
if ( V_356 && ! V_28 )
V_28 = V_356 ;
return V_28 ;
}
void F_149 ( struct V_65 * V_66 )
{
F_140 ( V_66 ) ;
F_150 ( V_66 ) ;
}
