static inline int F_1 ( T_1 V_1 )
{
return ( F_2 ( V_2 , V_1 ) == V_3 ) ;
}
static int F_3 ( struct V_4 * V_4 , struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 = F_4 ( V_4 -> V_11 ,
struct V_9 ,
V_12 ) ;
F_5 ( & V_10 -> V_13 ) ;
V_8 = F_6 ( sizeof( * V_8 ) , V_14 ) ;
if ( V_8 ) {
V_8 -> V_15 = - 1 ;
V_8 -> V_16 = V_17 -> V_16 ;
F_7 ( & V_8 -> V_16 -> V_18 ) ;
}
V_6 -> V_19 = V_8 ;
return V_8 ? 0 : - V_20 ;
}
static long F_8 ( struct V_5 * V_6 , unsigned int V_21 ,
unsigned long V_22 )
{
struct V_7 * V_8 = V_6 -> V_19 ;
struct V_23 * V_24 = V_8 -> V_24 ;
struct V_25 V_26 ;
struct V_27 V_28 ;
int V_29 = 0 ;
unsigned long V_30 ;
int V_31 = 0 ;
unsigned long V_32 = 0 ;
T_2 V_33 = 0 ;
F_9 ( V_34 , L_1 , V_21 ) ;
if ( V_21 != V_35 &&
V_21 != V_36 &&
! V_24 )
return - V_37 ;
switch ( V_21 ) {
case V_35 :
if ( V_24 )
return - V_37 ;
if ( F_10 ( & V_26 ,
(struct V_25 V_38 * ) V_22 ,
sizeof( V_26 ) ) )
return - V_39 ;
V_29 = F_11 ( V_6 , & V_26 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_12 ( V_6 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_13 ( V_6 ) ;
break;
case V_40 :
V_29 = F_14 ( V_6 , ( void V_38 * ) ( unsigned long ) V_22 ,
sizeof( struct V_41 ) ) ;
break;
case V_42 :
V_29 = F_15 ( V_6 , ( void V_38 * ) ( unsigned long ) V_22 ,
sizeof( struct V_43 ) ) ;
break;
case V_44 :
if ( V_24 )
F_16 ( V_24 -> V_45 ) ;
break;
case V_46 :
if ( F_10 ( & V_28 ,
(struct V_47 V_38 * ) V_22 ,
sizeof( V_28 ) ) )
return - V_39 ;
V_29 = F_17 ( V_6 , & V_28 ) ;
if ( ! V_29 ) {
V_30 = V_22 + F_18 ( struct V_27 , V_48 ) ;
if ( F_19 ( ( void V_38 * ) V_30 , & V_28 . V_48 ,
sizeof( V_28 . V_48 ) +
sizeof( V_28 . V_49 ) ) )
V_29 = - V_39 ;
}
break;
case V_50 :
if ( F_10 ( & V_28 ,
(struct V_47 V_38 * ) V_22 ,
sizeof( V_28 ) ) )
return - V_39 ;
V_29 = F_20 ( V_6 , & V_28 ) ;
if ( V_29 )
break;
V_30 = V_22 + F_18 ( struct V_27 , V_48 ) ;
if ( F_19 ( ( void V_38 * ) V_30 , & V_28 . V_48 ,
sizeof( V_28 . V_48 ) ) )
V_29 = - V_39 ;
break;
case V_51 :
if ( F_10 ( & V_28 ,
(struct V_47 V_38 * ) V_22 ,
sizeof( V_28 ) ) )
return - V_39 ;
V_29 = F_21 ( V_6 , & V_28 ) ;
if ( V_29 )
break;
V_30 = V_22 + F_18 ( struct V_27 , V_48 ) ;
if ( F_19 ( ( void V_38 * ) V_30 , & V_28 . V_48 ,
sizeof( V_28 . V_48 ) ) )
V_29 = - V_39 ;
break;
case V_52 :
V_29 = F_22 ( V_31 , ( int V_38 * ) V_22 ) ;
if ( V_29 != 0 )
return - V_39 ;
V_29 = F_23 ( V_24 , V_8 -> V_53 , V_31 ) ;
break;
case V_54 :
V_29 = F_22 ( V_31 , ( int V_38 * ) V_22 ) ;
if ( V_29 != 0 )
return - V_39 ;
V_24 -> V_55 = ( F_24 ( V_24 -> V_55 ) ) V_31 ;
break;
case V_56 :
V_29 = F_22 ( V_32 , ( unsigned long V_38 * ) V_22 ) ;
if ( V_29 != 0 )
return - V_39 ;
V_29 = F_25 ( V_24 , V_8 -> V_53 , V_32 ) ;
break;
case V_57 :
V_29 = F_22 ( V_33 , ( T_2 V_38 * ) V_22 ) ;
if ( V_29 != 0 )
return - V_39 ;
if ( F_26 ( V_58 ) )
V_29 = F_27 ( V_24 , V_8 -> V_53 , V_33 ) ;
else
return - V_59 ;
break;
case V_60 : {
struct V_61 * V_45 ;
struct V_9 * V_10 ;
if ( ! V_24 || ! V_24 -> V_10 || ! V_24 -> V_45 )
return - V_37 ;
V_10 = V_24 -> V_10 ;
V_45 = V_24 -> V_45 ;
F_28 (
V_45 -> V_62 , ( V_45 -> V_63 & V_64 ) ,
F_29 ( V_65 ) ) ;
if ( ! ( V_45 -> V_63 & V_64 ) )
return - V_66 ;
if ( V_45 -> V_63 & V_67 ) {
F_28 (
V_10 -> V_68 ,
! ( F_30 ( V_10 -> V_63 ) & V_69 ) ,
F_29 ( V_65 ) ) ;
if ( V_10 -> V_63 & V_69 )
return - V_66 ;
if ( V_10 -> V_63 & V_70 )
return - V_71 ;
F_31 ( V_45 ) ;
V_29 = F_32 ( V_45 ) ;
F_33 ( V_10 , V_72 ,
V_24 -> V_73 ) ;
} else {
V_29 = F_34 ( V_45 ) ;
}
if ( ! V_29 )
F_16 ( V_45 ) ;
break;
}
case V_36 :
V_31 = V_74 ;
if ( F_35 ( V_31 , ( int V_38 * ) V_22 ) )
return - V_39 ;
break;
default:
return - V_37 ;
}
return V_29 ;
}
static T_3 F_36 ( struct V_75 * V_75 , struct V_76 * V_77 )
{
struct V_7 * V_8 = V_75 -> V_78 -> V_19 ;
struct V_79 * V_80 = V_8 -> V_80 ;
struct V_81 * V_82 = V_8 -> V_82 ;
int V_83 = 0 , V_84 = 0 ;
unsigned long V_85 = V_77 -> V_86 ;
if ( ! V_82 || ! V_80 )
return - V_87 ;
if ( ! F_37 ( V_77 ) || ! V_85 )
return - V_37 ;
F_9 ( V_88 , L_2 ,
V_8 -> V_24 -> V_73 , V_8 -> V_53 , V_85 ) ;
if ( F_38 ( & V_80 -> V_89 ) == V_80 -> V_90 )
return - V_91 ;
while ( V_85 ) {
int V_29 ;
unsigned long V_92 = 0 ;
V_29 = F_39 (
V_75 -> V_78 , (struct V_93 * ) ( V_77 -> V_94 + V_83 ) ,
V_85 , & V_92 ) ;
if ( V_29 ) {
V_84 = V_29 ;
break;
}
V_85 -= V_92 ;
V_83 += V_92 ;
V_84 ++ ;
}
return V_84 ;
}
static int F_40 ( struct V_5 * V_6 , struct V_95 * V_96 )
{
struct V_7 * V_8 = V_6 -> V_19 ;
struct V_23 * V_24 = V_8 -> V_24 ;
struct V_9 * V_10 ;
unsigned long V_63 , V_97 ;
T_1 V_1 = V_96 -> V_98 << V_99 ,
V_100 = 0 ;
T_4 V_53 , V_101 = 0 , V_102 = 0 , type ;
T_3 V_103 = 0 ;
int V_29 = 0 ;
T_2 V_73 ;
if ( ! F_1 ( V_1 ) || ! V_24 ||
! ( V_96 -> V_104 & V_105 ) ) {
V_29 = - V_37 ;
goto V_83;
}
V_10 = V_24 -> V_10 ;
V_73 = F_2 ( V_106 , V_1 ) ;
V_53 = F_2 ( V_107 , V_1 ) ;
type = F_2 ( TYPE , V_1 ) ;
if ( V_73 != V_24 -> V_73 || V_53 != V_8 -> V_53 ) {
V_29 = - V_37 ;
goto V_83;
}
V_63 = V_96 -> V_104 ;
switch ( type ) {
case V_108 :
case V_109 :
V_100 = ( ( V_10 -> V_110 + V_111 ) +
( V_24 -> V_45 -> V_112 * F_41 ( 16 ) ) ) +
( type == V_109 ?
( V_113 / 2 ) : 0 ) ;
V_103 = F_42 ( V_24 -> V_45 -> V_114 * V_115 ) ;
V_63 &= ~ V_116 ;
V_63 |= V_117 | V_118 ;
V_96 -> V_119 = F_43 ( V_96 -> V_119 ) ;
V_101 = 1 ;
break;
case V_120 :
if ( V_63 & V_121 ) {
V_29 = - V_59 ;
goto V_83;
}
V_100 = V_10 -> V_122 [ V_24 -> V_123 ] . V_124 +
( ( ( T_1 ) V_24 -> V_45 -> V_125 -
( T_1 ) V_10 -> V_122 [ V_24 -> V_123 ] . V_126 ) & V_127 ) ;
V_103 = V_128 ;
V_63 &= ~ V_129 ;
V_63 |= V_117 | V_118 ;
V_101 = 1 ;
break;
case V_130 :
V_100 = V_24 -> V_131 ;
V_103 = V_24 -> V_132 ;
break;
case V_133 : {
unsigned long V_30 ;
int V_134 ;
V_103 = V_24 -> V_135 . V_136 ;
if ( ( V_96 -> V_137 - V_96 -> V_138 ) != V_103 ) {
F_44 ( V_10 , L_3 ,
( V_96 -> V_137 - V_96 -> V_138 ) , V_103 ) ;
V_29 = - V_37 ;
goto V_83;
}
if ( V_96 -> V_104 & V_121 ) {
V_29 = - V_59 ;
goto V_83;
}
V_96 -> V_104 &= ~ V_129 ;
V_30 = V_96 -> V_138 ;
for ( V_134 = 0 ; V_134 < V_24 -> V_135 . V_139 ; V_134 ++ ) {
V_29 = F_45 (
V_96 , V_30 ,
V_24 -> V_135 . V_140 [ V_134 ] . V_141 >> V_99 ,
V_24 -> V_135 . V_140 [ V_134 ] . V_142 ,
V_96 -> V_119 ) ;
if ( V_29 < 0 )
goto V_83;
V_30 += V_24 -> V_135 . V_140 [ V_134 ] . V_142 ;
}
V_29 = 0 ;
goto V_83;
}
case V_143 :
V_100 = ( unsigned long )
( V_10 -> V_110 + V_144 )
+ ( V_24 -> V_73 * V_145 ) ;
V_103 = V_128 ;
V_63 |= V_117 | V_118 ;
V_96 -> V_119 = F_46 ( V_96 -> V_119 ) ;
V_101 = 1 ;
break;
case V_146 :
V_100 = ( unsigned long ) ( V_10 -> V_147 +
( ( V_24 -> V_73 - V_10 -> V_148 ) *
V_149 ) ) & V_127 ;
V_103 = V_128 ;
V_63 |= V_150 | V_118 ;
V_102 = 1 ;
break;
case V_151 :
V_100 = F_47 ( ( void * ) V_10 -> V_152 ) ;
V_103 = V_128 ;
V_63 |= V_150 | V_118 ;
break;
case V_153 :
if ( ! F_26 ( V_154 ) ) {
V_29 = - V_37 ;
goto V_83;
}
if ( V_63 & V_121 ) {
V_29 = - V_59 ;
goto V_83;
}
V_100 = V_24 -> V_155 ;
V_103 = V_128 ;
V_63 &= ~ V_129 ;
break;
case V_156 :
V_100 = ( T_1 ) V_24 -> V_157 ;
V_103 = V_128 ;
V_63 |= V_150 | V_118 ;
V_102 = 1 ;
break;
case V_158 :
V_100 = ( T_1 ) V_24 -> V_159 ;
V_103 = V_24 -> V_132 * V_24 -> V_160 ;
V_63 |= V_150 | V_118 ;
V_102 = 1 ;
break;
case V_161 :
V_100 = ( T_1 ) V_24 -> V_162 ;
V_103 = V_24 -> V_135 . V_136 * V_24 -> V_160 ;
V_63 |= V_150 | V_118 ;
V_63 &= ~ V_129 ;
V_102 = 1 ;
break;
case V_163 : {
struct V_81 * V_82 = V_8 -> V_82 ;
if ( ! V_82 ) {
V_29 = - V_39 ;
goto V_83;
}
V_100 = ( T_1 ) V_82 -> V_164 ;
V_103 = F_42 ( sizeof( * V_82 -> V_164 ) * V_82 -> V_165 ) ;
V_63 |= V_150 | V_118 ;
V_102 = 1 ;
break;
}
default:
V_29 = - V_37 ;
break;
}
if ( ( V_96 -> V_137 - V_96 -> V_138 ) != V_103 ) {
F_9 ( V_166 , L_4 ,
V_24 -> V_73 , V_8 -> V_53 ,
( V_96 -> V_137 - V_96 -> V_138 ) , V_103 ) ;
V_29 = - V_37 ;
goto V_83;
}
V_96 -> V_104 = V_63 ;
F_9 ( V_166 ,
L_5 ,
V_73 , V_53 , type , V_101 , V_102 , V_100 , V_103 ,
V_96 -> V_137 - V_96 -> V_138 , V_96 -> V_104 ) ;
V_97 = ( unsigned long ) ( V_100 >> V_99 ) ;
if ( V_102 ) {
V_96 -> V_98 = V_97 ;
V_96 -> V_167 = & V_167 ;
V_29 = 0 ;
} else if ( V_101 ) {
V_29 = F_48 ( V_96 , V_96 -> V_138 , V_97 , V_103 ,
V_96 -> V_119 ) ;
} else {
V_29 = F_45 ( V_96 , V_96 -> V_138 , V_97 , V_103 ,
V_96 -> V_119 ) ;
}
V_83:
return V_29 ;
}
static int F_49 ( struct V_95 * V_96 , struct V_168 * V_102 )
{
struct V_169 * V_169 ;
V_169 = F_50 ( ( void * ) ( V_102 -> V_170 << V_99 ) ) ;
if ( ! V_169 )
return V_171 ;
F_51 ( V_169 ) ;
V_102 -> V_169 = V_169 ;
return 0 ;
}
static unsigned int F_52 ( struct V_5 * V_6 , struct V_172 * V_173 )
{
struct V_23 * V_24 ;
unsigned V_174 ;
V_24 = ( (struct V_7 * ) V_6 -> V_19 ) -> V_24 ;
if ( ! V_24 )
V_174 = V_175 ;
else if ( V_24 -> V_55 == V_176 )
V_174 = F_53 ( V_6 , V_173 ) ;
else if ( V_24 -> V_55 == V_177 )
V_174 = F_54 ( V_6 , V_173 ) ;
else
V_174 = V_175 ;
return V_174 ;
}
static int F_55 ( struct V_4 * V_4 , struct V_5 * V_6 )
{
struct V_7 * V_178 = V_6 -> V_19 ;
struct V_23 * V_24 = V_178 -> V_24 ;
struct V_9 * V_10 = F_4 ( V_4 -> V_11 ,
struct V_9 ,
V_12 ) ;
unsigned long V_63 , * V_179 ;
V_6 -> V_19 = NULL ;
if ( ! V_24 )
goto V_83;
F_9 ( V_166 , L_6 , V_24 -> V_73 , V_178 -> V_53 ) ;
F_56 ( & V_180 ) ;
F_57 () ;
F_58 ( V_178 ) ;
F_59 ( V_178 -> V_15 ) ;
V_179 = V_10 -> V_147 + ( ( V_24 -> V_73 - V_10 -> V_148 ) *
V_149 ) + V_178 -> V_53 ;
* V_179 = 0 ;
if ( -- V_24 -> V_181 ) {
V_24 -> V_182 &= ~ ( 1 << V_178 -> V_53 ) ;
F_60 ( & V_180 ) ;
goto V_83;
}
F_61 ( & V_10 -> V_183 , V_63 ) ;
F_33 ( V_10 , V_184 |
V_185 |
V_186 |
V_187 |
V_188 |
V_189 |
V_190 , V_24 -> V_73 ) ;
F_62 ( V_10 , V_24 -> V_73 ) ;
F_63 ( V_10 , V_24 -> V_45 -> V_112 , V_191 ,
F_64 ( V_10 , V_24 -> V_45 -> type ) ) ;
F_31 ( V_24 -> V_45 ) ;
F_65 ( & V_10 -> V_183 , V_63 ) ;
V_10 -> V_192 [ V_24 -> V_73 ] = NULL ;
F_66 ( V_178 ) ;
F_67 ( V_10 , V_24 -> V_73 ) ;
V_24 -> V_193 = 0 ;
V_24 -> V_194 = 0 ;
V_24 -> V_195 = 0 ;
V_24 -> V_196 = 0 ;
V_24 -> V_197 = 0 ;
V_198 . V_199 -- ;
if ( ++ V_10 -> V_200 == V_10 -> V_201 )
F_68 ( V_10 ) ;
F_60 ( & V_180 ) ;
F_69 ( V_10 , V_24 ) ;
V_83:
F_70 ( V_178 -> V_16 ) ;
F_71 ( & V_10 -> V_13 ) ;
F_72 ( V_178 ) ;
return 0 ;
}
static T_1 F_47 ( void * V_30 )
{
struct V_169 * V_169 ;
T_1 V_202 = 0 ;
V_169 = F_50 ( V_30 ) ;
if ( V_169 )
V_202 = F_73 ( V_169 ) << V_99 ;
return V_202 ;
}
static int F_11 ( struct V_5 * V_6 , struct V_25 * V_26 )
{
int V_203 , V_29 = 0 ;
unsigned int V_204 , V_205 ;
V_204 = V_26 -> V_206 >> 16 ;
if ( V_204 != V_207 ) {
V_29 = - V_71 ;
goto V_83;
}
V_205 = V_26 -> V_206 & 0xffff ;
F_56 ( & V_180 ) ;
if ( V_26 -> V_160 ) {
struct V_7 * V_8 = V_6 -> V_19 ;
V_29 = F_74 ( V_6 , V_26 ) ;
if ( V_29 < 0 )
goto V_208;
if ( V_29 ) {
V_8 -> V_15 =
F_75 ( V_8 -> V_24 -> V_123 ) ;
}
}
if ( ! V_29 ) {
V_203 = F_76 ( F_77 ( V_6 ) ) - V_209 ;
V_29 = F_78 ( V_6 , V_26 , V_203 ) ;
}
V_208:
F_60 ( & V_180 ) ;
V_83:
return V_29 ;
}
static int F_78 ( struct V_5 * V_6 , struct V_25 * V_26 ,
int V_210 )
{
struct V_9 * V_10 = NULL ;
int V_211 , V_212 , V_213 ;
V_211 = F_79 ( & V_212 , & V_213 ) ;
if ( ! V_212 )
return - V_214 ;
if ( ! V_213 )
return - V_215 ;
V_10 = F_80 ( V_210 ) ;
if ( ! V_10 )
return - V_71 ;
else if ( ! V_10 -> V_200 )
return - V_216 ;
return F_81 ( V_6 , V_10 , V_26 ) ;
}
static int F_74 ( struct V_5 * V_6 ,
const struct V_25 * V_26 )
{
int V_211 , V_217 , V_134 ;
int V_29 = 0 ;
struct V_7 * V_8 = V_6 -> V_19 ;
V_211 = F_79 ( NULL , NULL ) ;
for ( V_217 = 0 ; V_217 < V_211 ; V_217 ++ ) {
struct V_9 * V_10 = F_80 ( V_217 ) ;
if ( ! ( V_10 && ( V_10 -> V_63 & V_218 ) && V_10 -> V_219 ) )
continue;
for ( V_134 = V_10 -> V_148 ; V_134 < V_10 -> V_220 ; V_134 ++ ) {
struct V_23 * V_24 = V_10 -> V_192 [ V_134 ] ;
if ( ! V_24 || ! V_24 -> V_181 )
continue;
if ( memcmp ( V_24 -> V_221 , V_26 -> V_221 ,
sizeof( V_24 -> V_221 ) ) ||
V_24 -> V_222 != F_82 ( F_83 () ) ||
V_24 -> V_223 != V_26 -> V_223 ||
V_24 -> V_160 != V_26 -> V_160 )
continue;
if ( V_24 -> V_206 != V_26 -> V_206 ||
V_24 -> V_181 >= V_24 -> V_160 ) {
V_29 = - V_37 ;
goto V_83;
}
V_8 -> V_24 = V_24 ;
V_8 -> V_53 = V_24 -> V_181 ++ ;
V_24 -> V_182 |= 1 << V_8 -> V_53 ;
V_29 = 1 ;
goto V_83;
}
}
V_83:
return V_29 ;
}
static int F_81 ( struct V_5 * V_6 , struct V_9 * V_10 ,
struct V_25 * V_26 )
{
struct V_7 * V_8 = V_6 -> V_19 ;
struct V_23 * V_24 ;
unsigned V_73 ;
int V_29 , V_224 ;
if ( V_10 -> V_63 & V_69 ) {
return - V_87 ;
}
for ( V_73 = V_10 -> V_148 ; V_73 < V_10 -> V_220 ; V_73 ++ )
if ( ! V_10 -> V_192 [ V_73 ] )
break;
if ( V_73 == V_10 -> V_220 )
return - V_216 ;
V_8 -> V_15 = F_75 ( V_10 -> V_225 ) ;
if ( V_8 -> V_15 != - 1 )
V_224 = F_84 ( V_8 -> V_15 ) ;
else
V_224 = F_85 () ;
V_24 = F_86 ( V_10 -> V_226 , V_73 , V_224 ) ;
if ( ! V_24 ) {
F_44 ( V_10 ,
L_7 ) ;
return - V_20 ;
}
F_9 ( V_166 , L_8 ,
V_24 -> V_73 , V_8 -> V_53 , V_17 -> V_227 , V_8 -> V_15 ,
V_24 -> V_123 ) ;
V_24 -> V_45 = F_87 ( V_10 , V_228 , V_24 -> V_229 ,
V_24 -> V_10 -> V_225 ) ;
if ( ! V_24 -> V_45 )
return - V_20 ;
F_9 ( V_166 , L_9 , V_24 -> V_45 -> V_230 ,
V_24 -> V_45 -> V_112 ) ;
V_29 = F_32 ( V_24 -> V_45 ) ;
if ( V_29 )
return V_29 ;
if ( V_26 -> V_160 && ! V_8 -> V_53 ) {
V_29 = F_88 ( V_24 , V_26 ) ;
if ( V_29 )
return V_29 ;
}
V_24 -> V_206 = V_26 -> V_206 ;
V_24 -> V_63 = V_231 ;
F_89 ( & V_24 -> V_232 ) ;
F_90 ( V_24 -> V_233 , V_17 -> V_233 , sizeof( V_24 -> V_233 ) ) ;
memcpy ( V_24 -> V_221 , V_26 -> V_221 , sizeof( V_24 -> V_221 ) ) ;
V_24 -> V_222 = F_82 ( F_83 () ) ;
F_91 ( & V_24 -> V_234 ) ;
F_92 ( & V_24 -> V_235 ) ;
V_198 . V_199 ++ ;
if ( V_10 -> V_200 -- == V_10 -> V_201 )
F_93 ( V_10 ) ;
V_8 -> V_24 = V_24 ;
return 0 ;
}
static int F_88 ( struct V_23 * V_24 ,
const struct V_25 * V_26 )
{
unsigned V_236 ;
V_236 = V_26 -> V_160 ;
if ( V_236 > V_149 )
return - V_37 ;
V_24 -> V_160 = V_26 -> V_160 ;
V_24 -> V_223 = V_26 -> V_223 ;
V_24 -> V_182 = 1 ;
V_24 -> V_237 = 1 ;
F_94 ( V_238 , & V_24 -> V_197 ) ;
return 0 ;
}
static int F_95 ( struct V_23 * V_24 )
{
int V_29 = 0 ;
unsigned V_236 = V_24 -> V_160 ;
V_24 -> V_157 = F_96 ( V_128 ) ;
if ( ! V_24 -> V_157 ) {
V_29 = - V_20 ;
goto V_239;
}
V_24 -> V_159 = F_96 ( V_24 -> V_132 *
V_236 ) ;
if ( ! V_24 -> V_159 ) {
V_29 = - V_20 ;
goto V_240;
}
V_24 -> V_162 = F_96 ( V_24 -> V_135 . V_136 *
V_236 ) ;
if ( ! V_24 -> V_162 ) {
V_29 = - V_20 ;
goto V_241;
}
goto V_239;
V_241:
F_97 ( V_24 -> V_159 ) ;
V_240:
F_97 ( V_24 -> V_157 ) ;
V_24 -> V_157 = NULL ;
V_239:
return V_29 ;
}
static int F_13 ( struct V_5 * V_6 )
{
unsigned int V_242 = 0 ;
struct V_7 * V_8 = V_6 -> V_19 ;
struct V_23 * V_24 = V_8 -> V_24 ;
if ( ! F_98 ( V_243 , & V_24 -> V_197 ) )
return - V_39 ;
V_24 -> V_244 = 0 ;
V_24 -> V_245 = 0 ;
if ( V_24 -> V_246 )
F_99 ( V_24 ) ;
F_100 ( V_24 -> V_10 , V_24 -> V_73 , V_24 -> V_222 ) ;
V_242 = V_72 ;
if ( F_101 ( V_24 -> V_63 , V_247 ) )
V_242 |= V_248 ;
if ( ! F_101 ( V_24 -> V_63 , V_249 ) )
V_242 |= V_250 ;
if ( F_101 ( V_24 -> V_63 , V_251 ) )
V_242 |= V_252 ;
if ( F_101 ( V_24 -> V_63 , V_253 ) )
V_242 |= V_254 ;
if ( F_101 ( V_24 -> V_63 , V_154 ) )
V_242 |= V_255 ;
else
V_242 |= V_187 ;
F_33 ( V_24 -> V_10 , V_242 , V_24 -> V_73 ) ;
if ( V_24 -> V_160 ) {
F_102 ( V_238 , & V_24 -> V_197 ) ;
F_103 ( & V_24 -> V_232 ) ;
}
return 0 ;
}
static int F_14 ( struct V_5 * V_6 , void V_38 * V_256 , T_5 V_142 )
{
struct V_41 V_257 ;
struct V_7 * V_8 = V_6 -> V_19 ;
struct V_23 * V_24 = V_8 -> V_24 ;
int V_29 = 0 ;
memset ( & V_257 , 0 , sizeof( V_257 ) ) ;
V_257 . V_258 = ( ( ( V_24 -> V_63 >> V_259 ) &
V_260 ) << V_261 ) |
F_101 ( V_24 -> V_63 , V_262 ) |
F_104 ( V_24 -> V_63 , V_263 ) ;
if ( ! V_8 -> V_264 )
V_257 . V_258 |= V_265 ;
V_257 . V_266 = F_105 () ;
V_257 . V_267 = V_24 -> V_10 -> V_267 ;
V_257 . V_73 = V_24 -> V_73 ;
V_257 . V_53 = V_8 -> V_53 ;
V_257 . V_268 = F_106 ( V_24 -> V_135 . V_269 ,
V_24 -> V_10 -> V_270 . V_271 ) +
V_24 -> V_272 ;
V_257 . V_114 = V_24 -> V_45 -> V_114 ;
V_257 . V_273 = V_24 -> V_123 ;
V_257 . V_274 = V_8 -> V_15 ;
V_257 . V_275 = V_24 -> V_45 -> V_112 ;
V_257 . V_276 = V_24 -> V_135 . V_269 ;
V_257 . V_277 = V_24 -> V_277 ;
V_257 . V_278 = V_24 -> V_229 << 2 ;
V_257 . V_279 = V_8 -> V_82 -> V_165 ;
V_257 . V_280 = V_24 -> V_135 . V_281 ;
F_107 ( V_24 -> V_10 , V_24 -> V_73 , V_8 -> V_53 , V_257 ) ;
if ( F_19 ( V_256 , & V_257 , sizeof( V_257 ) ) )
V_29 = - V_39 ;
return V_29 ;
}
static int F_12 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_19 ;
struct V_23 * V_24 = V_8 -> V_24 ;
struct V_9 * V_10 = V_24 -> V_10 ;
int V_29 = 0 ;
if ( ! V_24 -> V_160 || ! V_8 -> V_53 ) {
V_29 = F_108 ( V_24 -> V_45 ) ;
if ( V_29 )
goto V_83;
V_29 = F_109 ( V_10 , V_24 ) ;
if ( V_29 )
goto V_83;
V_29 = F_110 ( V_24 ) ;
if ( V_29 )
goto V_83;
if ( V_24 -> V_160 && ! V_8 -> V_53 ) {
V_29 = F_95 ( V_24 ) ;
if ( V_29 )
goto V_83;
}
} else {
V_29 = F_111 ( V_24 -> V_232 , ! F_98 (
V_238 ,
& V_24 -> V_197 ) ) ;
if ( V_29 )
goto V_83;
}
V_29 = F_112 ( V_24 , V_6 ) ;
if ( V_29 )
goto V_83;
V_29 = F_113 ( V_6 ) ;
if ( V_29 )
goto V_83;
F_94 ( V_243 , & V_24 -> V_197 ) ;
V_83:
return V_29 ;
}
static int F_15 ( struct V_5 * V_6 , void V_38 * V_256 , T_5 V_142 )
{
struct V_43 V_282 ;
struct V_7 * V_8 = V_6 -> V_19 ;
struct V_23 * V_24 = V_8 -> V_24 ;
struct V_9 * V_10 = V_24 -> V_10 ;
T_3 V_283 ;
unsigned V_284 ;
int V_29 = 0 ;
F_114 ( V_24 -> V_10 , V_24 ) ;
memset ( & V_282 , 0 , sizeof( V_282 ) ) ;
V_282 . V_285 = V_10 -> V_286 ;
V_282 . V_287 = V_288 ;
V_282 . V_289 = V_290 ;
V_282 . V_222 = V_24 -> V_222 ;
V_284 = ( ( T_1 ) V_24 -> V_45 -> V_125 -
( T_1 ) V_10 -> V_122 [ V_24 -> V_123 ] . V_126 ) % V_128 ;
V_282 . V_291 = F_115 ( V_120 , V_24 -> V_73 ,
V_8 -> V_53 , V_284 ) ;
V_282 . V_292 = F_115 ( V_108 , V_24 -> V_73 ,
V_8 -> V_53 ,
V_24 -> V_45 -> V_293 ) ;
V_282 . V_294 = F_115 ( V_109 ,
V_24 -> V_73 ,
V_8 -> V_53 ,
V_24 -> V_45 -> V_293 ) ;
V_282 . V_295 = F_115 ( V_130 , V_24 -> V_73 ,
V_8 -> V_53 ,
V_24 -> V_296 ) ;
V_282 . V_297 = F_115 ( V_133 , V_24 -> V_73 ,
V_8 -> V_53 ,
V_24 -> V_135 . V_268 [ 0 ] . V_141 ) ;
V_282 . V_298 = F_115 ( V_163 , V_24 -> V_73 ,
V_8 -> V_53 , 0 ) ;
V_282 . V_299 = F_115 ( V_143 , V_24 -> V_73 ,
V_8 -> V_53 , 0 ) ;
V_284 = F_116 ( ( ( ( V_24 -> V_73 - V_10 -> V_148 ) *
V_149 ) + V_8 -> V_53 ) *
sizeof( * V_10 -> V_147 ) ) ;
V_282 . V_300 = F_115 ( V_146 , V_24 -> V_73 ,
V_8 -> V_53 ,
V_284 ) ;
V_282 . V_301 = F_115 ( V_151 , V_24 -> V_73 ,
V_8 -> V_53 ,
V_10 -> V_152 ) ;
if ( F_26 ( V_154 ) )
V_282 . V_302 = F_115 ( V_153 , V_24 -> V_73 ,
V_8 -> V_53 , 0 ) ;
if ( V_24 -> V_160 ) {
V_282 . V_157 = F_115 ( V_156 ,
V_24 -> V_73 ,
V_8 -> V_53 , 0 ) ;
V_282 . V_303 = F_115 ( V_158 ,
V_24 -> V_73 ,
V_8 -> V_53 , 0 ) ;
V_282 . V_162 = F_115 ( V_161 ,
V_24 -> V_73 ,
V_8 -> V_53 , 0 ) ;
}
V_283 = ( V_142 < sizeof( V_282 ) ) ? V_142 : sizeof( V_282 ) ;
if ( F_19 ( V_256 , & V_282 , V_283 ) )
V_29 = - V_39 ;
return V_29 ;
}
static unsigned int F_53 ( struct V_5 * V_6 ,
struct V_172 * V_173 )
{
struct V_7 * V_8 = V_6 -> V_19 ;
struct V_23 * V_24 = V_8 -> V_24 ;
struct V_9 * V_10 = V_24 -> V_10 ;
unsigned V_174 ;
F_117 ( V_6 , & V_24 -> V_232 , V_173 ) ;
F_118 ( & V_10 -> V_183 ) ;
if ( V_24 -> V_244 != V_24 -> V_245 ) {
V_174 = V_304 | V_305 ;
V_24 -> V_245 = V_24 -> V_244 ;
} else {
V_174 = 0 ;
F_94 ( V_306 , & V_24 -> V_197 ) ;
}
F_119 ( & V_10 -> V_183 ) ;
return V_174 ;
}
static unsigned int F_54 ( struct V_5 * V_6 ,
struct V_172 * V_173 )
{
struct V_7 * V_8 = V_6 -> V_19 ;
struct V_23 * V_24 = V_8 -> V_24 ;
struct V_9 * V_10 = V_24 -> V_10 ;
unsigned V_174 ;
F_117 ( V_6 , & V_24 -> V_232 , V_173 ) ;
F_118 ( & V_10 -> V_183 ) ;
if ( F_120 ( V_24 ) ) {
F_94 ( V_307 , & V_24 -> V_197 ) ;
F_33 ( V_10 , V_308 , V_24 -> V_73 ) ;
V_174 = 0 ;
} else {
V_174 = V_304 | V_305 ;
}
F_119 ( & V_10 -> V_183 ) ;
return V_174 ;
}
int F_121 ( struct V_309 * V_310 , const int V_311 )
{
struct V_23 * V_24 ;
struct V_9 * V_10 = V_310 -> V_10 ;
unsigned V_73 ;
int V_29 = 0 ;
unsigned long V_63 ;
if ( ! V_10 -> V_147 ) {
V_29 = - V_37 ;
goto V_83;
}
F_61 ( & V_10 -> V_183 , V_63 ) ;
for ( V_73 = V_10 -> V_148 ; V_73 < V_10 -> V_220 ;
V_73 ++ ) {
V_24 = V_10 -> V_192 [ V_73 ] ;
if ( V_24 ) {
unsigned long * V_312 = V_10 -> V_147 +
( V_24 -> V_73 - V_10 -> V_148 ) *
V_149 ;
int V_134 ;
F_94 ( V_311 , V_312 ) ;
for ( V_134 = 1 ; V_134 < V_24 -> V_160 ; V_134 ++ )
F_94 ( V_311 , V_312 + V_134 ) ;
}
}
F_65 ( & V_10 -> V_183 , V_63 ) ;
V_83:
return V_29 ;
}
static int F_23 ( struct V_23 * V_24 , unsigned V_53 ,
int V_313 )
{
struct V_9 * V_10 = V_24 -> V_10 ;
unsigned int V_314 ;
if ( V_53 )
goto V_239;
if ( V_313 ) {
if ( V_24 -> V_246 )
F_99 ( V_24 ) ;
V_314 = V_72 ;
} else {
V_314 = V_184 ;
}
F_33 ( V_10 , V_314 , V_24 -> V_73 ) ;
V_239:
return 0 ;
}
static int F_25 ( struct V_23 * V_24 , int V_53 ,
unsigned long V_147 )
{
int V_134 ;
struct V_9 * V_10 = V_24 -> V_10 ;
unsigned long * V_312 ;
if ( ! V_10 -> V_147 )
return 0 ;
V_312 = V_10 -> V_147 + ( ( V_24 -> V_73 - V_10 -> V_148 ) *
V_149 ) + V_53 ;
for ( V_134 = 0 ; V_134 <= V_315 ; V_134 ++ ) {
if ( ! F_98 ( V_134 , & V_147 ) )
continue;
F_102 ( V_134 , V_312 ) ;
}
return 0 ;
}
static int F_27 ( struct V_23 * V_24 , unsigned V_53 ,
T_2 V_316 )
{
int V_29 = - V_317 , V_134 , V_318 = 0 ;
struct V_309 * V_310 = V_24 -> V_310 ;
struct V_9 * V_10 = V_24 -> V_10 ;
if ( V_316 == V_319 || V_316 == V_320 ) {
V_29 = - V_37 ;
goto V_83;
}
for ( V_134 = 0 ; V_134 < F_122 ( V_310 -> V_321 ) ; V_134 ++ )
if ( V_316 == V_310 -> V_321 [ V_134 ] ) {
V_318 = 1 ;
break;
}
if ( V_318 )
V_29 = F_123 ( V_10 , V_24 -> V_73 , V_316 ) ;
V_83:
return V_29 ;
}
static void F_124 ( struct V_9 * V_10 )
{
F_125 ( & V_10 -> V_12 , & V_10 -> V_322 ) ;
}
static int F_126 ( struct V_9 * V_10 )
{
char V_323 [ 10 ] ;
int V_29 ;
snprintf ( V_323 , sizeof( V_323 ) , L_10 , F_127 () , V_10 -> V_267 ) ;
V_29 = F_128 ( V_10 -> V_267 , V_323 , & V_324 ,
& V_10 -> V_12 , & V_10 -> V_322 ,
true , & V_10 -> V_13 ) ;
if ( V_29 )
F_124 ( V_10 ) ;
return V_29 ;
}
int F_129 ( struct V_9 * V_10 )
{
return F_126 ( V_10 ) ;
}
void F_130 ( struct V_9 * V_10 )
{
F_124 ( V_10 ) ;
}
