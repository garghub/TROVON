static inline int F_1 ( T_1 V_1 )
{
return ( F_2 ( V_2 , V_1 ) == V_3 ) ;
}
static int F_3 ( struct V_4 * V_4 , struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_4 -> V_9 ,
struct V_7 ,
V_10 ) ;
F_5 ( & V_8 -> V_11 ) ;
V_6 -> V_12 = F_6 ( sizeof( struct V_13 ) , V_14 ) ;
if ( V_6 -> V_12 )
( (struct V_13 * ) V_6 -> V_12 ) -> V_15 = - 1 ;
return V_6 -> V_12 ? 0 : - V_16 ;
}
static long F_7 ( struct V_5 * V_6 , unsigned int V_17 ,
unsigned long V_18 )
{
struct V_13 * V_19 = V_6 -> V_12 ;
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 V_23 ;
struct V_24 V_25 ;
int V_26 = 0 ;
unsigned long V_27 ;
int V_28 = 0 ;
unsigned long V_29 = 0 ;
T_2 V_30 = 0 ;
F_8 ( V_31 , L_1 , V_17 ) ;
if ( V_17 != V_32 &&
V_17 != V_33 &&
! V_21 )
return - V_34 ;
switch ( V_17 ) {
case V_32 :
if ( V_21 )
return - V_34 ;
if ( F_9 ( & V_23 ,
(struct V_22 V_35 * ) V_18 ,
sizeof( V_23 ) ) )
return - V_36 ;
V_26 = F_10 ( V_6 , & V_23 ) ;
if ( V_26 < 0 )
return V_26 ;
F_11 ( V_6 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_12 ( V_6 ) ;
break;
case V_37 :
V_26 = F_13 ( V_6 , ( void V_35 * ) ( unsigned long ) V_18 ,
sizeof( struct V_38 ) ) ;
break;
case V_39 :
V_26 = F_14 ( V_6 , ( void V_35 * ) ( unsigned long ) V_18 ,
sizeof( struct V_40 ) ) ;
break;
case V_41 :
if ( V_21 && V_21 -> V_42 )
F_15 ( V_21 -> V_42 ) ;
break;
case V_43 :
if ( F_9 ( & V_25 ,
(struct V_44 V_35 * ) V_18 ,
sizeof( V_25 ) ) )
return - V_36 ;
V_26 = F_16 ( V_6 , & V_25 ) ;
if ( ! V_26 ) {
V_27 = V_18 + F_17 ( struct V_24 , V_45 ) ;
if ( F_18 ( ( void V_35 * ) V_27 , & V_25 . V_45 ,
sizeof( V_25 . V_45 ) +
sizeof( V_25 . V_46 ) ) )
V_26 = - V_36 ;
}
break;
case V_47 :
if ( F_9 ( & V_25 ,
(struct V_44 V_35 * ) V_18 ,
sizeof( V_25 ) ) )
return - V_36 ;
V_26 = F_19 ( V_6 , & V_25 ) ;
if ( V_26 )
break;
V_27 = V_18 + F_17 ( struct V_24 , V_45 ) ;
if ( F_18 ( ( void V_35 * ) V_27 , & V_25 . V_45 ,
sizeof( V_25 . V_45 ) ) )
V_26 = - V_36 ;
break;
case V_48 :
if ( F_9 ( & V_25 ,
(struct V_44 V_35 * ) V_18 ,
sizeof( V_25 ) ) )
return - V_36 ;
V_26 = F_20 ( V_6 , & V_25 ) ;
if ( V_26 )
break;
V_27 = V_18 + F_17 ( struct V_24 , V_45 ) ;
if ( F_18 ( ( void V_35 * ) V_27 , & V_25 . V_45 ,
sizeof( V_25 . V_45 ) ) )
V_26 = - V_36 ;
break;
case V_49 :
V_26 = F_21 ( V_28 , ( int V_35 * ) V_18 ) ;
if ( V_26 != 0 )
return - V_36 ;
V_26 = F_22 ( V_21 , V_19 -> V_50 , V_28 ) ;
break;
case V_51 :
V_26 = F_21 ( V_28 , ( int V_35 * ) V_18 ) ;
if ( V_26 != 0 )
return - V_36 ;
V_21 -> V_52 = ( F_23 ( V_21 -> V_52 ) ) V_28 ;
break;
case V_53 :
V_26 = F_21 ( V_29 , ( unsigned long V_35 * ) V_18 ) ;
if ( V_26 != 0 )
return - V_36 ;
V_26 = F_24 ( V_21 , V_19 -> V_50 , V_29 ) ;
break;
case V_54 :
V_26 = F_21 ( V_30 , ( T_2 V_35 * ) V_18 ) ;
if ( V_26 != 0 )
return - V_36 ;
if ( F_25 ( V_55 ) )
V_26 = F_26 ( V_21 , V_19 -> V_50 , V_30 ) ;
else
return - V_56 ;
break;
case V_57 : {
struct V_58 * V_42 ;
struct V_7 * V_8 ;
if ( ! V_21 || ! V_21 -> V_8 || ! V_21 -> V_42 )
return - V_34 ;
V_8 = V_21 -> V_8 ;
V_42 = V_21 -> V_42 ;
F_27 (
V_42 -> V_59 , ( V_42 -> V_60 & V_61 ) ,
F_28 ( V_62 ) ) ;
if ( ! ( V_42 -> V_60 & V_61 ) )
return - V_63 ;
if ( V_42 -> V_60 & V_64 ) {
F_27 (
V_8 -> V_65 ,
! ( F_29 ( V_8 -> V_60 ) & V_66 ) ,
F_28 ( V_62 ) ) ;
if ( V_8 -> V_60 & V_66 )
return - V_63 ;
if ( V_8 -> V_60 & V_67 )
return - V_68 ;
F_30 ( V_42 ) ;
V_26 = F_31 ( V_42 ) ;
F_32 ( V_8 , V_69 ,
V_21 -> V_70 ) ;
} else {
V_26 = F_33 ( V_42 ) ;
}
if ( ! V_26 )
F_15 ( V_42 ) ;
break;
}
case V_33 :
V_28 = V_71 ;
if ( F_34 ( V_28 , ( int V_35 * ) V_18 ) )
return - V_36 ;
break;
default:
return - V_34 ;
}
return V_26 ;
}
static T_3 F_35 ( struct V_72 * V_72 , struct V_73 * V_74 )
{
struct V_13 * V_19 = V_72 -> V_75 -> V_12 ;
struct V_76 * V_77 = V_19 -> V_77 ;
struct V_78 * V_79 = V_19 -> V_79 ;
int V_26 = 0 , V_80 = 0 , V_81 = 0 ;
unsigned long V_82 = V_74 -> V_83 ;
if ( ! V_79 || ! V_77 ) {
V_26 = - V_84 ;
goto V_80;
}
if ( ! F_36 ( V_74 ) || ! V_82 ) {
V_26 = - V_34 ;
goto V_80;
}
F_8 ( V_85 , L_2 ,
V_19 -> V_21 -> V_70 , V_19 -> V_50 , V_82 ) ;
if ( F_37 ( & V_77 -> V_86 ) == V_77 -> V_87 ) {
V_26 = - V_88 ;
goto V_80;
}
while ( V_82 ) {
unsigned long V_89 = 0 ;
V_26 = F_38 (
V_72 -> V_75 , (struct V_90 * ) ( V_74 -> V_91 + V_80 ) ,
V_82 , & V_89 ) ;
if ( V_26 )
goto V_80;
V_82 -= V_89 ;
V_80 += V_89 ;
V_81 ++ ;
}
V_80:
return V_26 ? V_26 : V_81 ;
}
static int F_39 ( struct V_5 * V_6 , struct V_92 * V_93 )
{
struct V_13 * V_19 = V_6 -> V_12 ;
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_7 * V_8 ;
unsigned long V_60 , V_94 ;
T_1 V_1 = V_93 -> V_95 << V_96 ,
V_97 = 0 ;
T_4 V_50 , V_98 = 0 , V_99 = 0 , type ;
T_3 V_100 = 0 ;
int V_26 = 0 ;
T_2 V_70 ;
if ( ! F_1 ( V_1 ) || ! V_21 ||
! ( V_93 -> V_101 & V_102 ) ) {
V_26 = - V_34 ;
goto V_80;
}
V_8 = V_21 -> V_8 ;
V_70 = F_2 ( V_103 , V_1 ) ;
V_50 = F_2 ( V_104 , V_1 ) ;
type = F_2 ( TYPE , V_1 ) ;
if ( V_70 != V_21 -> V_70 || V_50 != V_19 -> V_50 ) {
V_26 = - V_34 ;
goto V_80;
}
V_60 = V_93 -> V_101 ;
switch ( type ) {
case V_105 :
case V_106 :
V_97 = ( ( V_8 -> V_107 + V_108 ) +
( V_21 -> V_42 -> V_109 * F_40 ( 16 ) ) ) +
( type == V_106 ?
( V_110 / 2 ) : 0 ) ;
V_100 = F_41 ( V_21 -> V_42 -> V_111 * V_112 ) ;
V_60 &= ~ V_113 ;
V_60 |= V_114 | V_115 ;
V_93 -> V_116 = F_42 ( V_93 -> V_116 ) ;
V_98 = 1 ;
break;
case V_117 :
if ( V_60 & V_118 ) {
V_26 = - V_56 ;
goto V_80;
}
V_97 = V_8 -> V_119 [ V_21 -> V_120 ] . V_121 +
( ( ( T_1 ) V_21 -> V_42 -> V_122 -
( T_1 ) V_8 -> V_119 [ V_21 -> V_120 ] . V_123 ) & V_124 ) ;
V_100 = V_125 ;
V_60 &= ~ V_126 ;
V_60 |= V_114 | V_115 ;
V_98 = 1 ;
break;
case V_127 :
V_97 = V_21 -> V_128 ;
V_100 = V_21 -> V_129 ;
break;
case V_130 : {
unsigned long V_27 ;
int V_131 ;
V_100 = V_21 -> V_132 . V_133 ;
if ( ( V_93 -> V_134 - V_93 -> V_135 ) != V_100 ) {
F_43 ( V_8 , L_3 ,
( V_93 -> V_134 - V_93 -> V_135 ) , V_100 ) ;
V_26 = - V_34 ;
goto V_80;
}
if ( V_93 -> V_101 & V_118 ) {
V_26 = - V_56 ;
goto V_80;
}
V_93 -> V_101 &= ~ V_126 ;
V_27 = V_93 -> V_135 ;
for ( V_131 = 0 ; V_131 < V_21 -> V_132 . V_136 ; V_131 ++ ) {
V_26 = F_44 (
V_93 , V_27 ,
V_21 -> V_132 . V_137 [ V_131 ] . V_138 >> V_96 ,
V_21 -> V_132 . V_137 [ V_131 ] . V_139 ,
V_93 -> V_116 ) ;
if ( V_26 < 0 )
goto V_80;
V_27 += V_21 -> V_132 . V_137 [ V_131 ] . V_139 ;
}
V_26 = 0 ;
goto V_80;
}
case V_140 :
V_97 = ( unsigned long )
( V_8 -> V_107 + V_141 )
+ ( V_21 -> V_70 * V_142 ) ;
V_100 = V_125 ;
V_60 |= V_114 | V_115 ;
V_93 -> V_116 = F_45 ( V_93 -> V_116 ) ;
V_98 = 1 ;
break;
case V_143 :
V_97 = ( unsigned long ) ( V_8 -> V_144 +
( ( V_21 -> V_70 - V_8 -> V_145 ) *
V_146 ) ) & V_124 ;
V_100 = V_125 ;
V_60 |= V_147 | V_115 ;
V_99 = 1 ;
break;
case V_148 :
V_97 = F_46 ( ( void * ) V_8 -> V_149 ) ;
V_100 = V_125 ;
V_60 |= V_147 | V_115 ;
break;
case V_150 :
if ( ! F_25 ( V_151 ) ) {
V_26 = - V_34 ;
goto V_80;
}
if ( V_60 & V_118 ) {
V_26 = - V_56 ;
goto V_80;
}
V_97 = V_21 -> V_152 ;
V_100 = V_125 ;
V_60 &= ~ V_126 ;
break;
case V_153 :
V_97 = ( T_1 ) V_21 -> V_154 ;
V_100 = V_125 ;
V_60 |= V_147 | V_115 ;
V_99 = 1 ;
break;
case V_155 :
V_97 = ( T_1 ) V_21 -> V_156 ;
V_100 = V_21 -> V_129 * V_21 -> V_157 ;
V_60 |= V_147 | V_115 ;
V_99 = 1 ;
break;
case V_158 :
V_97 = ( T_1 ) V_21 -> V_159 ;
V_100 = V_21 -> V_132 . V_133 * V_21 -> V_157 ;
V_60 |= V_147 | V_115 ;
V_60 &= ~ V_126 ;
V_99 = 1 ;
break;
case V_160 : {
struct V_78 * V_79 = V_19 -> V_79 ;
if ( ! V_79 ) {
V_26 = - V_36 ;
goto V_80;
}
V_97 = ( T_1 ) V_79 -> V_161 ;
V_100 = F_41 ( sizeof( * V_79 -> V_161 ) * V_79 -> V_162 ) ;
V_60 |= V_147 | V_115 ;
V_99 = 1 ;
break;
}
default:
V_26 = - V_34 ;
break;
}
if ( ( V_93 -> V_134 - V_93 -> V_135 ) != V_100 ) {
F_8 ( V_163 , L_4 ,
V_21 -> V_70 , V_19 -> V_50 ,
( V_93 -> V_134 - V_93 -> V_135 ) , V_100 ) ;
V_26 = - V_34 ;
goto V_80;
}
V_93 -> V_101 = V_60 ;
F_8 ( V_163 ,
L_5 ,
V_70 , V_50 , type , V_98 , V_99 , V_97 , V_100 ,
V_93 -> V_134 - V_93 -> V_135 , V_93 -> V_101 ) ;
V_94 = ( unsigned long ) ( V_97 >> V_96 ) ;
if ( V_99 ) {
V_93 -> V_95 = V_94 ;
V_93 -> V_164 = & V_164 ;
V_26 = 0 ;
} else if ( V_98 ) {
V_26 = F_47 ( V_93 , V_93 -> V_135 , V_94 , V_100 ,
V_93 -> V_116 ) ;
} else {
V_26 = F_44 ( V_93 , V_93 -> V_135 , V_94 , V_100 ,
V_93 -> V_116 ) ;
}
V_80:
return V_26 ;
}
static int F_48 ( struct V_92 * V_93 , struct V_165 * V_99 )
{
struct V_166 * V_166 ;
V_166 = F_49 ( ( void * ) ( V_99 -> V_167 << V_96 ) ) ;
if ( ! V_166 )
return V_168 ;
F_50 ( V_166 ) ;
V_99 -> V_166 = V_166 ;
return 0 ;
}
static unsigned int F_51 ( struct V_5 * V_6 , struct V_169 * V_170 )
{
struct V_20 * V_21 ;
unsigned V_171 ;
V_21 = ( (struct V_13 * ) V_6 -> V_12 ) -> V_21 ;
if ( ! V_21 )
V_171 = V_172 ;
else if ( V_21 -> V_52 == V_173 )
V_171 = F_52 ( V_6 , V_170 ) ;
else if ( V_21 -> V_52 == V_174 )
V_171 = F_53 ( V_6 , V_170 ) ;
else
V_171 = V_172 ;
return V_171 ;
}
static int F_54 ( struct V_4 * V_4 , struct V_5 * V_6 )
{
struct V_13 * V_175 = V_6 -> V_12 ;
struct V_20 * V_21 = V_175 -> V_21 ;
struct V_7 * V_8 = F_4 ( V_4 -> V_9 ,
struct V_7 ,
V_10 ) ;
unsigned long V_60 , * V_176 ;
V_6 -> V_12 = NULL ;
if ( ! V_21 )
goto V_80;
F_8 ( V_163 , L_6 , V_21 -> V_70 , V_175 -> V_50 ) ;
F_55 ( & V_177 ) ;
F_56 () ;
F_57 ( V_175 ) ;
F_58 ( V_8 , V_175 -> V_15 ) ;
V_176 = V_8 -> V_144 + ( ( V_21 -> V_70 - V_8 -> V_145 ) *
V_146 ) + V_175 -> V_50 ;
* V_176 = 0 ;
if ( -- V_21 -> V_178 ) {
V_21 -> V_179 &= ~ ( 1 << V_175 -> V_50 ) ;
V_21 -> V_180 [ V_175 -> V_50 ] = 0 ;
F_59 ( & V_177 ) ;
goto V_80;
}
F_60 ( & V_8 -> V_181 , V_60 ) ;
F_32 ( V_8 , V_182 |
V_183 |
V_184 |
V_185 |
V_186 |
V_187 |
V_188 , V_21 -> V_70 ) ;
F_61 ( V_8 , V_21 -> V_70 ) ;
F_62 ( V_8 , V_21 -> V_42 -> V_109 , V_189 ,
F_63 ( V_8 , V_21 -> V_42 -> type ) ) ;
F_30 ( V_21 -> V_42 ) ;
V_21 -> V_190 = 0 ;
F_64 ( & V_8 -> V_181 , V_60 ) ;
V_8 -> V_191 [ V_21 -> V_70 ] = NULL ;
F_65 ( V_175 ) ;
F_66 ( V_8 , V_21 -> V_70 ) ;
V_21 -> V_192 = 0 ;
V_21 -> V_193 = 0 ;
V_21 -> V_194 = 0 ;
V_21 -> V_195 = 0 ;
V_21 -> V_196 = 0 ;
V_197 . V_198 -- ;
if ( ++ V_8 -> V_199 == V_8 -> V_200 )
F_67 ( V_8 ) ;
F_59 ( & V_177 ) ;
F_68 ( V_8 , V_21 ) ;
V_80:
F_69 ( & V_8 -> V_11 ) ;
F_70 ( V_175 ) ;
return 0 ;
}
static T_1 F_46 ( void * V_27 )
{
struct V_166 * V_166 ;
T_1 V_201 = 0 ;
V_166 = F_49 ( V_27 ) ;
if ( V_166 )
V_201 = F_71 ( V_166 ) << V_96 ;
return V_201 ;
}
static int F_10 ( struct V_5 * V_6 , struct V_22 * V_23 )
{
int V_202 , V_26 = 0 ;
unsigned int V_203 , V_204 ;
V_203 = V_23 -> V_205 >> 16 ;
if ( V_203 != V_206 ) {
V_26 = - V_68 ;
goto V_80;
}
V_204 = V_23 -> V_205 & 0xffff ;
F_55 ( & V_177 ) ;
if ( V_23 -> V_157 ) {
struct V_13 * V_19 = V_6 -> V_12 ;
V_26 = F_72 ( V_6 , V_23 ) ;
if ( V_26 < 0 )
goto V_207;
if ( V_26 )
V_19 -> V_15 = F_73 (
V_19 -> V_21 -> V_8 , V_19 -> V_21 -> V_120 ) ;
}
if ( ! V_26 ) {
V_202 = F_74 ( F_75 ( V_6 ) ) - V_208 ;
V_26 = F_76 ( V_6 , V_23 , V_202 ) ;
}
V_207:
F_59 ( & V_177 ) ;
V_80:
return V_26 ;
}
static int F_76 ( struct V_5 * V_6 , struct V_22 * V_23 ,
int V_209 )
{
struct V_7 * V_8 = NULL ;
int V_210 , V_211 , V_212 ;
V_210 = F_77 ( & V_211 , & V_212 ) ;
if ( ! V_211 )
return - V_213 ;
if ( ! V_212 )
return - V_214 ;
V_8 = F_78 ( V_209 ) ;
if ( ! V_8 )
return - V_68 ;
else if ( ! V_8 -> V_199 )
return - V_215 ;
return F_79 ( V_6 , V_8 , V_23 ) ;
}
static int F_72 ( struct V_5 * V_6 ,
const struct V_22 * V_23 )
{
int V_210 , V_216 , V_131 ;
int V_26 = 0 ;
struct V_13 * V_19 = V_6 -> V_12 ;
V_210 = F_77 ( NULL , NULL ) ;
for ( V_216 = 0 ; V_216 < V_210 ; V_216 ++ ) {
struct V_7 * V_8 = F_78 ( V_216 ) ;
if ( ! ( V_8 && ( V_8 -> V_60 & V_217 ) && V_8 -> V_218 ) )
continue;
for ( V_131 = V_8 -> V_145 ; V_131 < V_8 -> V_219 ; V_131 ++ ) {
struct V_20 * V_21 = V_8 -> V_191 [ V_131 ] ;
if ( ! V_21 || ! V_21 -> V_178 )
continue;
if ( memcmp ( V_21 -> V_220 , V_23 -> V_220 ,
sizeof( V_21 -> V_220 ) ) ||
V_21 -> V_221 != F_80 ( F_81 () ) ||
V_21 -> V_222 != V_23 -> V_222 ||
V_21 -> V_157 != V_23 -> V_157 )
continue;
if ( V_21 -> V_205 != V_23 -> V_205 ||
V_21 -> V_178 >= V_21 -> V_157 ) {
V_26 = - V_34 ;
goto V_80;
}
V_19 -> V_21 = V_21 ;
V_19 -> V_50 = V_21 -> V_178 ++ ;
V_21 -> V_180 [ V_19 -> V_50 ] = V_223 -> V_190 ;
V_21 -> V_179 |= 1 << V_19 -> V_50 ;
V_26 = 1 ;
goto V_80;
}
}
V_80:
return V_26 ;
}
static int F_79 ( struct V_5 * V_6 , struct V_7 * V_8 ,
struct V_22 * V_23 )
{
struct V_13 * V_19 = V_6 -> V_12 ;
struct V_20 * V_21 ;
unsigned V_70 ;
int V_26 , V_224 ;
if ( V_8 -> V_60 & V_66 ) {
return - V_84 ;
}
for ( V_70 = V_8 -> V_145 ; V_70 < V_8 -> V_219 ; V_70 ++ )
if ( ! V_8 -> V_191 [ V_70 ] )
break;
if ( V_70 == V_8 -> V_219 )
return - V_215 ;
V_19 -> V_15 = F_73 ( V_8 , - 1 ) ;
if ( V_19 -> V_15 != - 1 )
V_224 = F_82 ( V_19 -> V_15 ) ;
else
V_224 = F_83 () ;
V_21 = F_84 ( V_8 -> V_225 , V_70 , V_224 ) ;
if ( ! V_21 ) {
F_43 ( V_8 ,
L_7 ) ;
return - V_16 ;
}
F_8 ( V_163 , L_8 ,
V_21 -> V_70 , V_19 -> V_50 , V_223 -> V_190 , V_19 -> V_15 ,
V_21 -> V_120 ) ;
V_21 -> V_42 = F_85 ( V_8 , V_226 , V_21 -> V_227 ,
V_21 -> V_8 -> V_228 ) ;
if ( ! V_21 -> V_42 )
return - V_16 ;
F_8 ( V_163 , L_9 , V_21 -> V_42 -> V_229 ,
V_21 -> V_42 -> V_109 ) ;
V_26 = F_31 ( V_21 -> V_42 ) ;
if ( V_26 )
return V_26 ;
if ( V_23 -> V_157 && ! V_19 -> V_50 ) {
V_26 = F_86 ( V_21 , V_23 ) ;
if ( V_26 )
return V_26 ;
}
V_21 -> V_205 = V_23 -> V_205 ;
V_21 -> V_190 = V_223 -> V_190 ;
V_21 -> V_60 = F_87 ( V_230 ) ;
F_88 ( & V_21 -> V_231 ) ;
F_89 ( V_21 -> V_232 , V_223 -> V_232 , sizeof( V_21 -> V_232 ) ) ;
memcpy ( V_21 -> V_220 , V_23 -> V_220 , sizeof( V_21 -> V_220 ) ) ;
V_21 -> V_221 = F_80 ( F_81 () ) ;
F_90 ( & V_21 -> V_233 ) ;
F_91 ( & V_21 -> V_234 ) ;
V_197 . V_198 ++ ;
if ( V_8 -> V_199 -- == V_8 -> V_200 )
F_92 ( V_8 ) ;
V_19 -> V_21 = V_21 ;
return 0 ;
}
static int F_86 ( struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
unsigned V_235 ;
V_235 = V_23 -> V_157 ;
if ( V_235 > V_146 )
return - V_34 ;
V_21 -> V_157 = V_23 -> V_157 ;
V_21 -> V_222 = V_23 -> V_222 ;
V_21 -> V_179 = 1 ;
V_21 -> V_236 = 1 ;
F_93 ( V_237 , & V_21 -> V_196 ) ;
return 0 ;
}
static int F_94 ( struct V_20 * V_21 )
{
int V_26 = 0 ;
unsigned V_235 = V_21 -> V_157 ;
V_21 -> V_154 = F_95 ( V_125 ) ;
if ( ! V_21 -> V_154 ) {
V_26 = - V_16 ;
goto V_238;
}
V_21 -> V_156 = F_95 ( V_21 -> V_129 *
V_235 ) ;
if ( ! V_21 -> V_156 ) {
V_26 = - V_16 ;
goto V_239;
}
V_21 -> V_159 = F_95 ( V_21 -> V_132 . V_133 *
V_235 ) ;
if ( ! V_21 -> V_159 ) {
V_26 = - V_16 ;
goto V_240;
}
goto V_238;
V_240:
F_96 ( V_21 -> V_156 ) ;
V_239:
F_96 ( V_21 -> V_154 ) ;
V_21 -> V_154 = NULL ;
V_238:
return V_26 ;
}
static int F_12 ( struct V_5 * V_6 )
{
unsigned int V_241 = 0 ;
struct V_13 * V_19 = V_6 -> V_12 ;
struct V_20 * V_21 = V_19 -> V_21 ;
if ( ! F_97 ( V_242 , & V_21 -> V_196 ) )
return - V_36 ;
V_21 -> V_243 = 0 ;
V_21 -> V_244 = 0 ;
if ( V_21 -> V_245 )
F_98 ( V_21 ) ;
F_99 ( V_21 -> V_8 , V_21 -> V_70 , V_21 -> V_221 ) ;
V_241 = V_69 ;
if ( F_100 ( V_21 -> V_60 , V_246 ) )
V_241 |= V_247 ;
if ( ! F_100 ( V_21 -> V_60 , V_248 ) )
V_241 |= V_249 ;
if ( F_100 ( V_21 -> V_60 , V_250 ) )
V_241 |= V_251 ;
if ( F_100 ( V_21 -> V_60 , V_252 ) )
V_241 |= V_253 ;
if ( F_100 ( V_21 -> V_60 , V_151 ) )
V_241 |= V_254 ;
else
V_241 |= V_185 ;
F_32 ( V_21 -> V_8 , V_241 , V_21 -> V_70 ) ;
if ( V_21 -> V_157 ) {
F_101 ( V_237 , & V_21 -> V_196 ) ;
F_102 ( & V_21 -> V_231 ) ;
}
return 0 ;
}
static int F_13 ( struct V_5 * V_6 , void V_35 * V_255 , T_5 V_139 )
{
struct V_38 V_256 ;
struct V_13 * V_19 = V_6 -> V_12 ;
struct V_20 * V_21 = V_19 -> V_21 ;
int V_26 = 0 ;
memset ( & V_256 , 0 , sizeof( V_256 ) ) ;
V_26 = F_103 ( V_21 , & V_256 ) ;
if ( V_26 < 0 )
goto V_80;
V_256 . V_257 = F_104 () ;
V_256 . V_258 = V_21 -> V_8 -> V_258 ;
V_256 . V_70 = V_21 -> V_70 ;
V_256 . V_50 = V_19 -> V_50 ;
V_256 . V_259 = F_105 ( V_21 -> V_132 . V_260 ,
V_21 -> V_8 -> V_261 . V_262 ) +
V_21 -> V_263 ;
V_256 . V_111 = V_21 -> V_42 -> V_111 ;
V_256 . V_264 = V_21 -> V_120 ;
V_256 . V_265 = V_19 -> V_15 ;
V_256 . V_266 = V_21 -> V_42 -> V_109 ;
V_256 . V_267 = V_21 -> V_132 . V_260 ;
V_256 . V_268 = V_21 -> V_268 ;
V_256 . V_269 = V_21 -> V_227 << 2 ;
V_256 . V_270 = V_19 -> V_79 -> V_162 ;
V_256 . V_271 = V_21 -> V_132 . V_272 ;
F_106 ( V_21 -> V_8 , V_21 -> V_70 , V_19 -> V_50 , V_256 ) ;
if ( F_18 ( V_255 , & V_256 , sizeof( V_256 ) ) )
V_26 = - V_36 ;
V_80:
return V_26 ;
}
static int F_11 ( struct V_5 * V_6 )
{
struct V_13 * V_19 = V_6 -> V_12 ;
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_7 * V_8 = V_21 -> V_8 ;
int V_26 = 0 ;
if ( ! V_21 -> V_157 || ! V_19 -> V_50 ) {
V_26 = F_107 ( V_21 -> V_42 ) ;
if ( V_26 )
goto V_80;
V_26 = F_108 ( V_8 , V_21 ) ;
if ( V_26 )
goto V_80;
V_26 = F_109 ( V_21 ) ;
if ( V_26 )
goto V_80;
if ( V_21 -> V_157 && ! V_19 -> V_50 ) {
V_26 = F_94 ( V_21 ) ;
if ( V_26 )
goto V_80;
}
} else {
V_26 = F_110 ( V_21 -> V_231 , ! F_97 (
V_237 ,
& V_21 -> V_196 ) ) ;
if ( V_26 )
goto V_80;
}
V_26 = F_111 ( V_21 , V_6 ) ;
if ( V_26 )
goto V_80;
V_26 = F_112 ( V_6 ) ;
if ( V_26 )
goto V_80;
F_93 ( V_242 , & V_21 -> V_196 ) ;
V_80:
return V_26 ;
}
static int F_14 ( struct V_5 * V_6 , void V_35 * V_255 , T_5 V_139 )
{
struct V_40 V_273 ;
struct V_13 * V_19 = V_6 -> V_12 ;
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_7 * V_8 = V_21 -> V_8 ;
T_3 V_274 ;
unsigned V_275 ;
int V_26 = 0 ;
F_113 ( V_21 -> V_8 , V_21 ) ;
memset ( & V_273 , 0 , sizeof( V_273 ) ) ;
V_273 . V_276 = V_8 -> V_277 ;
V_273 . V_278 = V_279 ;
V_273 . V_280 = V_281 ;
V_273 . V_221 = V_21 -> V_221 ;
V_275 = ( ( T_1 ) V_21 -> V_42 -> V_122 -
( T_1 ) V_8 -> V_119 [ V_21 -> V_120 ] . V_123 ) % V_125 ;
V_273 . V_282 = F_114 ( V_117 , V_21 -> V_70 ,
V_19 -> V_50 , V_275 ) ;
V_273 . V_283 = F_114 ( V_105 , V_21 -> V_70 ,
V_19 -> V_50 ,
V_21 -> V_42 -> V_284 ) ;
V_273 . V_285 = F_114 ( V_106 ,
V_21 -> V_70 ,
V_19 -> V_50 ,
V_21 -> V_42 -> V_284 ) ;
V_273 . V_286 = F_114 ( V_127 , V_21 -> V_70 ,
V_19 -> V_50 ,
V_21 -> V_287 ) ;
V_273 . V_288 = F_114 ( V_130 , V_21 -> V_70 ,
V_19 -> V_50 ,
V_21 -> V_132 . V_259 [ 0 ] . V_138 ) ;
V_273 . V_289 = F_114 ( V_160 , V_21 -> V_70 ,
V_19 -> V_50 , 0 ) ;
V_273 . V_290 = F_114 ( V_140 , V_21 -> V_70 ,
V_19 -> V_50 , 0 ) ;
V_275 = F_115 ( ( ( ( V_21 -> V_70 - V_8 -> V_145 ) *
V_146 ) + V_19 -> V_50 ) *
sizeof( * V_8 -> V_144 ) ) ;
V_273 . V_291 = F_114 ( V_143 , V_21 -> V_70 ,
V_19 -> V_50 ,
V_275 ) ;
V_273 . V_292 = F_114 ( V_148 , V_21 -> V_70 ,
V_19 -> V_50 ,
V_8 -> V_149 ) ;
if ( F_25 ( V_151 ) )
V_273 . V_293 = F_114 ( V_150 , V_21 -> V_70 ,
V_19 -> V_50 , 0 ) ;
if ( V_21 -> V_157 ) {
V_273 . V_154 = F_114 ( V_153 ,
V_21 -> V_70 ,
V_19 -> V_50 , 0 ) ;
V_273 . V_294 = F_114 ( V_155 ,
V_21 -> V_70 ,
V_19 -> V_50 , 0 ) ;
V_273 . V_159 = F_114 ( V_158 ,
V_21 -> V_70 ,
V_19 -> V_50 , 0 ) ;
}
V_274 = ( V_139 < sizeof( V_273 ) ) ? V_139 : sizeof( V_273 ) ;
if ( F_18 ( V_255 , & V_273 , V_274 ) )
V_26 = - V_36 ;
return V_26 ;
}
static unsigned int F_52 ( struct V_5 * V_6 ,
struct V_169 * V_170 )
{
struct V_13 * V_19 = V_6 -> V_12 ;
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_7 * V_8 = V_21 -> V_8 ;
unsigned V_171 ;
F_116 ( V_6 , & V_21 -> V_231 , V_170 ) ;
F_117 ( & V_8 -> V_181 ) ;
if ( V_21 -> V_243 != V_21 -> V_244 ) {
V_171 = V_295 | V_296 ;
V_21 -> V_244 = V_21 -> V_243 ;
} else {
V_171 = 0 ;
F_93 ( V_297 , & V_21 -> V_196 ) ;
}
F_118 ( & V_8 -> V_181 ) ;
return V_171 ;
}
static unsigned int F_53 ( struct V_5 * V_6 ,
struct V_169 * V_170 )
{
struct V_13 * V_19 = V_6 -> V_12 ;
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_7 * V_8 = V_21 -> V_8 ;
unsigned V_171 ;
F_116 ( V_6 , & V_21 -> V_231 , V_170 ) ;
F_117 ( & V_8 -> V_181 ) ;
if ( F_119 ( V_21 ) ) {
F_93 ( V_298 , & V_21 -> V_196 ) ;
F_32 ( V_8 , V_299 , V_21 -> V_70 ) ;
V_171 = 0 ;
} else {
V_171 = V_295 | V_296 ;
}
F_118 ( & V_8 -> V_181 ) ;
return V_171 ;
}
int F_120 ( struct V_300 * V_301 , const int V_302 )
{
struct V_20 * V_21 ;
struct V_7 * V_8 = V_301 -> V_8 ;
unsigned V_70 ;
int V_26 = 0 ;
unsigned long V_60 ;
if ( ! V_8 -> V_144 ) {
V_26 = - V_34 ;
goto V_80;
}
F_60 ( & V_8 -> V_181 , V_60 ) ;
for ( V_70 = V_8 -> V_145 ; V_70 < V_8 -> V_219 ;
V_70 ++ ) {
V_21 = V_8 -> V_191 [ V_70 ] ;
if ( V_21 ) {
unsigned long * V_303 = V_8 -> V_144 +
( V_21 -> V_70 - V_8 -> V_145 ) *
V_146 ;
int V_131 ;
F_93 ( V_302 , V_303 ) ;
for ( V_131 = 1 ; V_131 < V_21 -> V_157 ; V_131 ++ )
F_93 ( V_302 , V_303 + V_131 ) ;
}
}
F_64 ( & V_8 -> V_181 , V_60 ) ;
V_80:
return V_26 ;
}
static int F_22 ( struct V_20 * V_21 , unsigned V_50 ,
int V_304 )
{
struct V_7 * V_8 = V_21 -> V_8 ;
unsigned int V_305 ;
if ( V_50 )
goto V_238;
if ( V_304 ) {
if ( V_21 -> V_245 )
F_98 ( V_21 ) ;
V_305 = V_69 ;
} else {
V_305 = V_182 ;
}
F_32 ( V_8 , V_305 , V_21 -> V_70 ) ;
V_238:
return 0 ;
}
static int F_24 ( struct V_20 * V_21 , int V_50 ,
unsigned long V_144 )
{
int V_131 ;
struct V_7 * V_8 = V_21 -> V_8 ;
unsigned long * V_303 ;
if ( ! V_8 -> V_144 )
return 0 ;
V_303 = V_8 -> V_144 + ( ( V_21 -> V_70 - V_8 -> V_145 ) *
V_146 ) + V_50 ;
for ( V_131 = 0 ; V_131 <= V_306 ; V_131 ++ ) {
if ( ! F_97 ( V_131 , & V_144 ) )
continue;
F_101 ( V_131 , V_303 ) ;
}
return 0 ;
}
static int F_26 ( struct V_20 * V_21 , unsigned V_50 ,
T_2 V_307 )
{
int V_26 = - V_308 , V_131 , V_309 = 0 ;
struct V_300 * V_301 = V_21 -> V_301 ;
struct V_7 * V_8 = V_21 -> V_8 ;
if ( V_307 == V_310 || V_307 == V_311 ) {
V_26 = - V_34 ;
goto V_80;
}
for ( V_131 = 0 ; V_131 < F_121 ( V_301 -> V_312 ) ; V_131 ++ )
if ( V_307 == V_301 -> V_312 [ V_131 ] ) {
V_309 = 1 ;
break;
}
if ( V_309 )
V_26 = F_122 ( V_8 , V_21 -> V_70 , V_307 ) ;
V_80:
return V_26 ;
}
static void F_123 ( struct V_7 * V_8 )
{
F_124 ( & V_8 -> V_10 , & V_8 -> V_313 ) ;
}
static int F_125 ( struct V_7 * V_8 )
{
char V_314 [ 10 ] ;
int V_26 ;
snprintf ( V_314 , sizeof( V_314 ) , L_10 , F_126 () , V_8 -> V_258 ) ;
V_26 = F_127 ( V_8 -> V_258 , V_314 , & V_315 ,
& V_8 -> V_10 , & V_8 -> V_313 ,
true , & V_8 -> V_11 ) ;
if ( V_26 )
F_123 ( V_8 ) ;
return V_26 ;
}
int F_128 ( struct V_7 * V_8 )
{
return F_125 ( V_8 ) ;
}
void F_129 ( struct V_7 * V_8 )
{
F_123 ( V_8 ) ;
}
