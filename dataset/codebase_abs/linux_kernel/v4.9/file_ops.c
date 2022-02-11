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
if ( ! F_5 ( & V_10 -> V_13 ) )
return - V_14 ;
F_6 ( & V_10 -> V_15 ) ;
V_8 = F_7 ( sizeof( * V_8 ) , V_16 ) ;
if ( V_8 ) {
V_8 -> V_17 = - 1 ;
V_8 -> V_18 = V_19 -> V_18 ;
F_8 ( & V_8 -> V_18 -> V_20 ) ;
V_6 -> V_21 = V_8 ;
} else {
V_6 -> V_21 = NULL ;
if ( F_9 ( & V_10 -> V_13 ) )
F_10 ( & V_10 -> V_22 ) ;
return - V_23 ;
}
return 0 ;
}
static long F_11 ( struct V_5 * V_6 , unsigned int V_24 ,
unsigned long V_25 )
{
struct V_7 * V_8 = V_6 -> V_21 ;
struct V_26 * V_27 = V_8 -> V_27 ;
struct V_28 V_29 ;
struct V_30 V_31 ;
int V_32 = 0 ;
unsigned long V_33 ;
int V_34 = 0 ;
unsigned long V_35 = 0 ;
T_2 V_36 = 0 ;
F_12 ( V_37 , L_1 , V_24 ) ;
if ( V_24 != V_38 &&
V_24 != V_39 &&
! V_27 )
return - V_40 ;
switch ( V_24 ) {
case V_38 :
if ( V_27 )
return - V_40 ;
if ( F_13 ( & V_29 ,
(struct V_28 V_41 * ) V_25 ,
sizeof( V_29 ) ) )
return - V_42 ;
V_32 = F_14 ( V_6 , & V_29 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = F_15 ( V_6 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_16 ( V_6 ) ;
break;
case V_43 :
V_32 = F_17 ( V_6 , ( void V_41 * ) ( unsigned long ) V_25 ,
sizeof( struct V_44 ) ) ;
break;
case V_45 :
V_32 = F_18 ( V_6 , ( void V_41 * ) ( unsigned long ) V_25 ,
sizeof( struct V_46 ) ) ;
break;
case V_47 :
if ( V_27 )
F_19 ( V_27 -> V_48 ) ;
break;
case V_49 :
if ( F_13 ( & V_31 ,
(struct V_50 V_41 * ) V_25 ,
sizeof( V_31 ) ) )
return - V_42 ;
V_32 = F_20 ( V_6 , & V_31 ) ;
if ( ! V_32 ) {
V_33 = V_25 + F_21 ( struct V_30 , V_51 ) ;
if ( F_22 ( ( void V_41 * ) V_33 , & V_31 . V_51 ,
sizeof( V_31 . V_51 ) +
sizeof( V_31 . V_52 ) ) )
V_32 = - V_42 ;
}
break;
case V_53 :
if ( F_13 ( & V_31 ,
(struct V_50 V_41 * ) V_25 ,
sizeof( V_31 ) ) )
return - V_42 ;
V_32 = F_23 ( V_6 , & V_31 ) ;
if ( V_32 )
break;
V_33 = V_25 + F_21 ( struct V_30 , V_51 ) ;
if ( F_22 ( ( void V_41 * ) V_33 , & V_31 . V_51 ,
sizeof( V_31 . V_51 ) ) )
V_32 = - V_42 ;
break;
case V_54 :
if ( F_13 ( & V_31 ,
(struct V_50 V_41 * ) V_25 ,
sizeof( V_31 ) ) )
return - V_42 ;
V_32 = F_24 ( V_6 , & V_31 ) ;
if ( V_32 )
break;
V_33 = V_25 + F_21 ( struct V_30 , V_51 ) ;
if ( F_22 ( ( void V_41 * ) V_33 , & V_31 . V_51 ,
sizeof( V_31 . V_51 ) ) )
V_32 = - V_42 ;
break;
case V_55 :
V_32 = F_25 ( V_34 , ( int V_41 * ) V_25 ) ;
if ( V_32 != 0 )
return - V_42 ;
V_32 = F_26 ( V_27 , V_8 -> V_56 , V_34 ) ;
break;
case V_57 :
V_32 = F_25 ( V_34 , ( int V_41 * ) V_25 ) ;
if ( V_32 != 0 )
return - V_42 ;
V_27 -> V_58 = ( F_27 ( V_27 -> V_58 ) ) V_34 ;
break;
case V_59 :
V_32 = F_25 ( V_35 , ( unsigned long V_41 * ) V_25 ) ;
if ( V_32 != 0 )
return - V_42 ;
V_32 = F_28 ( V_27 , V_8 -> V_56 , V_35 ) ;
break;
case V_60 :
V_32 = F_25 ( V_36 , ( T_2 V_41 * ) V_25 ) ;
if ( V_32 != 0 )
return - V_42 ;
if ( F_29 ( V_61 ) )
V_32 = F_30 ( V_27 , V_8 -> V_56 , V_36 ) ;
else
return - V_62 ;
break;
case V_63 : {
struct V_64 * V_48 ;
struct V_9 * V_10 ;
if ( ! V_27 || ! V_27 -> V_10 || ! V_27 -> V_48 )
return - V_40 ;
V_10 = V_27 -> V_10 ;
V_48 = V_27 -> V_48 ;
F_31 (
V_48 -> V_65 , ( V_48 -> V_66 & V_67 ) ,
F_32 ( V_68 ) ) ;
if ( ! ( V_48 -> V_66 & V_67 ) )
return - V_69 ;
if ( V_48 -> V_66 & V_70 ) {
F_31 (
V_10 -> V_71 ,
! ( F_33 ( V_10 -> V_66 ) & V_72 ) ,
F_32 ( V_68 ) ) ;
if ( V_10 -> V_66 & V_72 )
return - V_69 ;
if ( V_10 -> V_66 & V_73 )
return - V_74 ;
F_34 ( V_48 ) ;
V_32 = F_35 ( V_48 ) ;
F_36 ( V_10 , V_75 ,
V_27 -> V_76 ) ;
} else {
V_32 = F_37 ( V_48 ) ;
}
if ( ! V_32 )
F_19 ( V_48 ) ;
break;
}
case V_39 :
V_34 = V_77 ;
if ( F_38 ( V_34 , ( int V_41 * ) V_25 ) )
return - V_42 ;
break;
default:
return - V_40 ;
}
return V_32 ;
}
static T_3 F_39 ( struct V_78 * V_78 , struct V_79 * V_80 )
{
struct V_7 * V_8 = V_78 -> V_81 -> V_21 ;
struct V_82 * V_83 = V_8 -> V_83 ;
struct V_84 * V_85 = V_8 -> V_85 ;
int V_86 = 0 , V_87 = 0 ;
unsigned long V_88 = V_80 -> V_89 ;
if ( ! V_85 || ! V_83 )
return - V_90 ;
if ( ! F_40 ( V_80 ) || ! V_88 )
return - V_40 ;
F_12 ( V_91 , L_2 ,
V_8 -> V_27 -> V_76 , V_8 -> V_56 , V_88 ) ;
if ( F_41 ( & V_83 -> V_92 ) == V_83 -> V_93 )
return - V_94 ;
while ( V_88 ) {
int V_32 ;
unsigned long V_95 = 0 ;
V_32 = F_42 (
V_78 -> V_81 , (struct V_96 * ) ( V_80 -> V_97 + V_86 ) ,
V_88 , & V_95 ) ;
if ( V_32 ) {
V_87 = V_32 ;
break;
}
V_88 -= V_95 ;
V_86 += V_95 ;
V_87 ++ ;
}
return V_87 ;
}
static int F_43 ( struct V_5 * V_6 , struct V_98 * V_99 )
{
struct V_7 * V_8 = V_6 -> V_21 ;
struct V_26 * V_27 = V_8 -> V_27 ;
struct V_9 * V_10 ;
unsigned long V_66 ;
T_1 V_1 = V_99 -> V_100 << V_101 ,
V_102 = 0 ;
void * V_103 = NULL ;
T_4 V_56 , V_104 = 0 , V_105 = 0 , type ;
T_3 V_106 = 0 ;
int V_32 = 0 ;
T_2 V_76 ;
if ( ! F_1 ( V_1 ) || ! V_27 ||
! ( V_99 -> V_107 & V_108 ) ) {
V_32 = - V_40 ;
goto V_86;
}
V_10 = V_27 -> V_10 ;
V_76 = F_2 ( V_109 , V_1 ) ;
V_56 = F_2 ( V_110 , V_1 ) ;
type = F_2 ( TYPE , V_1 ) ;
if ( V_76 != V_27 -> V_76 || V_56 != V_8 -> V_56 ) {
V_32 = - V_40 ;
goto V_86;
}
V_66 = V_99 -> V_107 ;
switch ( type ) {
case V_111 :
case V_112 :
V_102 = ( ( V_10 -> V_113 + V_114 ) +
( V_27 -> V_48 -> V_115 * F_44 ( 16 ) ) ) +
( type == V_112 ?
( V_116 / 2 ) : 0 ) ;
V_106 = F_45 ( V_27 -> V_48 -> V_117 * V_118 ) ;
V_66 &= ~ V_119 ;
V_66 |= V_120 | V_121 ;
V_99 -> V_122 = F_46 ( V_99 -> V_122 ) ;
V_104 = 1 ;
break;
case V_123 :
if ( V_66 & V_124 ) {
V_32 = - V_62 ;
goto V_86;
}
V_103 = V_10 -> V_125 [ V_27 -> V_126 ] . V_127 ;
V_102 = F_47 ( V_103 ) +
( ( ( T_1 ) V_27 -> V_48 -> V_128 -
( T_1 ) V_10 -> V_125 [ V_27 -> V_126 ] . V_127 ) & V_129 ) ;
V_106 = V_130 ;
V_66 &= ~ V_131 ;
V_66 |= V_120 | V_121 ;
V_104 = 1 ;
break;
case V_132 :
V_106 = V_27 -> V_133 ;
V_103 = V_27 -> V_134 ;
break;
case V_135 : {
unsigned long V_33 ;
int V_136 ;
V_106 = V_27 -> V_137 . V_138 ;
if ( ( V_99 -> V_139 - V_99 -> V_140 ) != V_106 ) {
F_48 ( V_10 , L_3 ,
( V_99 -> V_139 - V_99 -> V_140 ) , V_106 ) ;
V_32 = - V_40 ;
goto V_86;
}
if ( V_99 -> V_107 & V_124 ) {
V_32 = - V_62 ;
goto V_86;
}
V_99 -> V_107 &= ~ V_131 ;
V_33 = V_99 -> V_140 ;
for ( V_136 = 0 ; V_136 < V_27 -> V_137 . V_141 ; V_136 ++ ) {
V_106 = V_27 -> V_137 . V_142 [ V_136 ] . V_143 ;
V_103 = V_27 -> V_137 . V_142 [ V_136 ] . V_33 ;
V_32 = F_49 (
V_99 , V_33 ,
F_50 ( F_51 ( V_103 ) ) ,
V_106 ,
V_99 -> V_122 ) ;
if ( V_32 < 0 )
goto V_86;
V_33 += V_106 ;
}
V_32 = 0 ;
goto V_86;
}
case V_144 :
V_102 = ( unsigned long )
( V_10 -> V_113 + V_145 )
+ ( V_27 -> V_76 * V_146 ) ;
V_106 = V_130 ;
V_66 |= V_120 | V_121 ;
V_99 -> V_122 = F_52 ( V_99 -> V_122 ) ;
V_104 = 1 ;
break;
case V_147 :
V_102 = ( unsigned long ) ( V_10 -> V_148 +
( ( V_27 -> V_76 - V_10 -> V_149 ) *
V_150 ) ) & V_129 ;
V_106 = V_130 ;
V_66 |= V_151 | V_121 ;
V_105 = 1 ;
break;
case V_152 :
V_102 = F_53 ( ( void * ) V_10 -> V_153 ) ;
V_106 = V_130 ;
V_66 |= V_151 | V_121 ;
break;
case V_154 :
if ( ! F_29 ( V_155 ) ) {
V_32 = - V_40 ;
goto V_86;
}
if ( V_66 & V_124 ) {
V_32 = - V_62 ;
goto V_86;
}
V_106 = V_130 ;
V_103 = ( void * ) V_27 -> V_156 ;
V_66 &= ~ V_131 ;
break;
case V_157 :
V_102 = ( T_1 ) V_27 -> V_158 ;
V_106 = V_130 ;
V_66 |= V_151 | V_121 ;
V_105 = 1 ;
break;
case V_159 :
V_102 = ( T_1 ) V_27 -> V_160 ;
V_106 = V_27 -> V_133 * V_27 -> V_161 ;
V_66 |= V_151 | V_121 ;
V_105 = 1 ;
break;
case V_162 :
V_102 = ( T_1 ) V_27 -> V_163 ;
V_106 = V_27 -> V_137 . V_138 * V_27 -> V_161 ;
V_66 |= V_151 | V_121 ;
V_66 &= ~ V_131 ;
V_105 = 1 ;
break;
case V_164 : {
struct V_84 * V_85 = V_8 -> V_85 ;
if ( ! V_85 ) {
V_32 = - V_42 ;
goto V_86;
}
V_102 = ( T_1 ) V_85 -> V_165 ;
V_106 = F_45 ( sizeof( * V_85 -> V_165 ) * V_85 -> V_166 ) ;
V_66 |= V_151 | V_121 ;
V_105 = 1 ;
break;
}
default:
V_32 = - V_40 ;
break;
}
if ( ( V_99 -> V_139 - V_99 -> V_140 ) != V_106 ) {
F_12 ( V_167 , L_4 ,
V_27 -> V_76 , V_8 -> V_56 ,
( V_99 -> V_139 - V_99 -> V_140 ) , V_106 ) ;
V_32 = - V_40 ;
goto V_86;
}
V_99 -> V_107 = V_66 ;
F_12 ( V_167 ,
L_5 ,
V_76 , V_56 , type , V_104 , V_105 , V_102 , V_106 ,
V_99 -> V_139 - V_99 -> V_140 , V_99 -> V_107 ) ;
if ( V_105 ) {
V_99 -> V_100 = F_50 ( V_102 ) ;
V_99 -> V_168 = & V_168 ;
V_32 = 0 ;
} else if ( V_104 ) {
V_32 = F_54 ( V_99 , V_99 -> V_140 ,
F_50 ( V_102 ) ,
V_106 ,
V_99 -> V_122 ) ;
} else if ( V_103 ) {
V_32 = F_49 ( V_99 , V_99 -> V_140 ,
F_50 ( F_51 ( V_103 ) ) ,
V_106 ,
V_99 -> V_122 ) ;
} else {
V_32 = F_49 ( V_99 , V_99 -> V_140 ,
F_50 ( V_102 ) ,
V_106 ,
V_99 -> V_122 ) ;
}
V_86:
return V_32 ;
}
static int F_55 ( struct V_98 * V_99 , struct V_169 * V_105 )
{
struct V_170 * V_170 ;
V_170 = F_56 ( ( void * ) ( V_105 -> V_171 << V_101 ) ) ;
if ( ! V_170 )
return V_172 ;
F_57 ( V_170 ) ;
V_105 -> V_170 = V_170 ;
return 0 ;
}
static unsigned int F_58 ( struct V_5 * V_6 , struct V_173 * V_174 )
{
struct V_26 * V_27 ;
unsigned V_175 ;
V_27 = ( (struct V_7 * ) V_6 -> V_21 ) -> V_27 ;
if ( ! V_27 )
V_175 = V_176 ;
else if ( V_27 -> V_58 == V_177 )
V_175 = F_59 ( V_6 , V_174 ) ;
else if ( V_27 -> V_58 == V_178 )
V_175 = F_60 ( V_6 , V_174 ) ;
else
V_175 = V_176 ;
return V_175 ;
}
static int F_61 ( struct V_4 * V_4 , struct V_5 * V_6 )
{
struct V_7 * V_179 = V_6 -> V_21 ;
struct V_26 * V_27 = V_179 -> V_27 ;
struct V_9 * V_10 = F_4 ( V_4 -> V_11 ,
struct V_9 ,
V_12 ) ;
unsigned long V_66 , * V_180 ;
V_6 -> V_21 = NULL ;
if ( ! V_27 )
goto V_86;
F_12 ( V_167 , L_6 , V_27 -> V_76 , V_179 -> V_56 ) ;
F_62 ( & V_181 ) ;
F_63 () ;
F_64 ( V_179 ) ;
F_65 ( V_179 -> V_17 ) ;
V_180 = V_10 -> V_148 + ( ( V_27 -> V_76 - V_10 -> V_149 ) *
V_150 ) + V_179 -> V_56 ;
* V_180 = 0 ;
if ( -- V_27 -> V_182 ) {
V_27 -> V_183 &= ~ ( 1 << V_179 -> V_56 ) ;
F_66 ( & V_181 ) ;
goto V_86;
}
F_67 ( & V_10 -> V_184 , V_66 ) ;
F_36 ( V_10 , V_185 |
V_186 |
V_187 |
V_188 |
V_189 |
V_190 |
V_191 , V_27 -> V_76 ) ;
F_68 ( V_10 , V_27 -> V_76 ) ;
F_69 ( V_10 , V_27 -> V_48 -> V_115 , V_192 ,
F_70 ( V_10 , V_27 -> V_48 -> type ) ) ;
F_34 ( V_27 -> V_48 ) ;
F_71 ( & V_10 -> V_184 , V_66 ) ;
V_10 -> V_193 [ V_27 -> V_76 ] = NULL ;
F_72 ( V_179 ) ;
F_73 ( V_10 , V_27 -> V_76 ) ;
V_27 -> V_194 = 0 ;
V_27 -> V_195 = 0 ;
V_27 -> V_196 = 0 ;
V_27 -> V_197 = 0 ;
V_27 -> V_198 = 0 ;
V_199 . V_200 -- ;
if ( ++ V_10 -> V_201 == V_10 -> V_202 )
F_74 ( V_10 ) ;
F_66 ( & V_181 ) ;
F_75 ( V_10 , V_27 ) ;
V_86:
F_76 ( V_179 -> V_18 ) ;
F_77 ( & V_10 -> V_15 ) ;
if ( F_9 ( & V_10 -> V_13 ) )
F_10 ( & V_10 -> V_22 ) ;
F_78 ( V_179 ) ;
return 0 ;
}
static T_1 F_53 ( void * V_33 )
{
struct V_170 * V_170 ;
T_1 V_203 = 0 ;
V_170 = F_56 ( V_33 ) ;
if ( V_170 )
V_203 = F_79 ( V_170 ) << V_101 ;
return V_203 ;
}
static int F_14 ( struct V_5 * V_6 , struct V_28 * V_29 )
{
int V_204 , V_32 = 0 ;
unsigned int V_205 , V_206 ;
V_205 = V_29 -> V_207 >> 16 ;
if ( V_205 != V_208 ) {
V_32 = - V_74 ;
goto V_86;
}
V_206 = V_29 -> V_207 & 0xffff ;
F_62 ( & V_181 ) ;
if ( V_29 -> V_161 ) {
struct V_7 * V_8 = V_6 -> V_21 ;
V_32 = F_80 ( V_6 , V_29 ) ;
if ( V_32 < 0 )
goto V_209;
if ( V_32 ) {
V_8 -> V_17 =
F_81 ( V_8 -> V_27 -> V_126 ) ;
}
}
if ( ! V_32 ) {
V_204 = F_82 ( F_83 ( V_6 ) ) - V_210 ;
V_32 = F_84 ( V_6 , V_29 , V_204 ) ;
}
V_209:
F_66 ( & V_181 ) ;
V_86:
return V_32 ;
}
static int F_84 ( struct V_5 * V_6 , struct V_28 * V_29 ,
int V_211 )
{
struct V_9 * V_10 = NULL ;
int V_212 , V_213 , V_214 ;
V_212 = F_85 ( & V_213 , & V_214 ) ;
if ( ! V_213 )
return - V_14 ;
if ( ! V_214 )
return - V_215 ;
V_10 = F_86 ( V_211 ) ;
if ( ! V_10 )
return - V_74 ;
else if ( ! V_10 -> V_201 )
return - V_216 ;
return F_87 ( V_6 , V_10 , V_29 ) ;
}
static int F_80 ( struct V_5 * V_6 ,
const struct V_28 * V_29 )
{
int V_212 , V_217 , V_136 ;
int V_32 = 0 ;
struct V_7 * V_8 = V_6 -> V_21 ;
V_212 = F_85 ( NULL , NULL ) ;
for ( V_217 = 0 ; V_217 < V_212 ; V_217 ++ ) {
struct V_9 * V_10 = F_86 ( V_217 ) ;
if ( ! ( V_10 && ( V_10 -> V_66 & V_218 ) && V_10 -> V_219 ) )
continue;
for ( V_136 = V_10 -> V_149 ; V_136 < V_10 -> V_220 ; V_136 ++ ) {
struct V_26 * V_27 = V_10 -> V_193 [ V_136 ] ;
if ( ! V_27 || ! V_27 -> V_182 )
continue;
if ( memcmp ( V_27 -> V_221 , V_29 -> V_221 ,
sizeof( V_27 -> V_221 ) ) ||
V_27 -> V_222 != F_88 ( F_89 () ) ||
V_27 -> V_223 != V_29 -> V_223 ||
V_27 -> V_161 != V_29 -> V_161 )
continue;
if ( V_27 -> V_207 != V_29 -> V_207 ||
V_27 -> V_182 >= V_27 -> V_161 ) {
V_32 = - V_40 ;
goto V_86;
}
V_8 -> V_27 = V_27 ;
V_8 -> V_56 = V_27 -> V_182 ++ ;
V_27 -> V_183 |= 1 << V_8 -> V_56 ;
V_32 = 1 ;
goto V_86;
}
}
V_86:
return V_32 ;
}
static int F_87 ( struct V_5 * V_6 , struct V_9 * V_10 ,
struct V_28 * V_29 )
{
struct V_7 * V_8 = V_6 -> V_21 ;
struct V_26 * V_27 ;
unsigned V_76 ;
int V_32 , V_224 ;
if ( V_10 -> V_66 & V_72 ) {
return - V_90 ;
}
for ( V_76 = V_10 -> V_149 ; V_76 < V_10 -> V_220 ; V_76 ++ )
if ( ! V_10 -> V_193 [ V_76 ] )
break;
if ( V_76 == V_10 -> V_220 )
return - V_216 ;
V_8 -> V_17 = F_81 ( V_10 -> V_225 ) ;
if ( V_8 -> V_17 != - 1 )
V_224 = F_90 ( V_8 -> V_17 ) ;
else
V_224 = F_91 () ;
V_27 = F_92 ( V_10 -> V_226 , V_76 , V_224 ) ;
if ( ! V_27 ) {
F_48 ( V_10 ,
L_7 ) ;
return - V_23 ;
}
F_12 ( V_167 , L_8 ,
V_27 -> V_76 , V_8 -> V_56 , V_19 -> V_227 , V_8 -> V_17 ,
V_27 -> V_126 ) ;
V_27 -> V_48 = F_93 ( V_10 , V_228 , V_27 -> V_229 ,
V_27 -> V_10 -> V_225 ) ;
if ( ! V_27 -> V_48 ) {
V_32 = - V_23 ;
goto V_230;
}
F_12 ( V_167 , L_9 , V_27 -> V_48 -> V_231 ,
V_27 -> V_48 -> V_115 ) ;
V_32 = F_35 ( V_27 -> V_48 ) ;
if ( V_32 )
goto V_230;
if ( V_29 -> V_161 && ! V_8 -> V_56 ) {
V_32 = F_94 ( V_27 , V_29 ) ;
if ( V_32 )
goto V_230;
}
V_27 -> V_207 = V_29 -> V_207 ;
V_27 -> V_66 = V_232 ;
F_95 ( & V_27 -> V_233 ) ;
F_96 ( V_27 -> V_234 , V_19 -> V_234 , sizeof( V_27 -> V_234 ) ) ;
memcpy ( V_27 -> V_221 , V_29 -> V_221 , sizeof( V_27 -> V_221 ) ) ;
V_27 -> V_222 = F_88 ( F_89 () ) ;
F_97 ( & V_27 -> V_235 ) ;
F_98 ( & V_27 -> V_236 ) ;
V_199 . V_200 ++ ;
if ( V_10 -> V_201 -- == V_10 -> V_202 )
F_99 ( V_10 ) ;
V_8 -> V_27 = V_27 ;
return 0 ;
V_230:
V_10 -> V_193 [ V_76 ] = NULL ;
F_75 ( V_10 , V_27 ) ;
return V_32 ;
}
static int F_94 ( struct V_26 * V_27 ,
const struct V_28 * V_29 )
{
unsigned V_237 ;
V_237 = V_29 -> V_161 ;
if ( V_237 > V_150 )
return - V_40 ;
V_27 -> V_161 = V_29 -> V_161 ;
V_27 -> V_223 = V_29 -> V_223 ;
V_27 -> V_183 = 1 ;
V_27 -> V_238 = 1 ;
F_100 ( V_239 , & V_27 -> V_198 ) ;
return 0 ;
}
static int F_101 ( struct V_26 * V_27 )
{
int V_32 = 0 ;
unsigned V_237 = V_27 -> V_161 ;
V_27 -> V_158 = F_102 ( V_130 ) ;
if ( ! V_27 -> V_158 ) {
V_32 = - V_23 ;
goto V_240;
}
V_27 -> V_160 = F_102 ( V_27 -> V_133 *
V_237 ) ;
if ( ! V_27 -> V_160 ) {
V_32 = - V_23 ;
goto V_241;
}
V_27 -> V_163 = F_102 ( V_27 -> V_137 . V_138 *
V_237 ) ;
if ( ! V_27 -> V_163 ) {
V_32 = - V_23 ;
goto V_242;
}
goto V_240;
V_242:
F_103 ( V_27 -> V_160 ) ;
V_241:
F_103 ( V_27 -> V_158 ) ;
V_27 -> V_158 = NULL ;
V_240:
return V_32 ;
}
static int F_16 ( struct V_5 * V_6 )
{
unsigned int V_243 = 0 ;
struct V_7 * V_8 = V_6 -> V_21 ;
struct V_26 * V_27 = V_8 -> V_27 ;
if ( ! F_104 ( V_244 , & V_27 -> V_198 ) )
return - V_42 ;
V_27 -> V_245 = 0 ;
V_27 -> V_246 = 0 ;
if ( V_27 -> V_156 )
F_105 ( V_27 ) ;
F_106 ( V_27 -> V_10 , V_27 -> V_76 , V_27 -> V_222 ) ;
V_243 = V_75 ;
if ( F_107 ( V_27 -> V_66 , V_247 ) )
V_243 |= V_248 ;
if ( ! F_107 ( V_27 -> V_66 , V_249 ) )
V_243 |= V_250 ;
if ( F_107 ( V_27 -> V_66 , V_251 ) )
V_243 |= V_252 ;
if ( F_107 ( V_27 -> V_66 , V_253 ) )
V_243 |= V_254 ;
if ( F_107 ( V_27 -> V_66 , V_155 ) )
V_243 |= V_255 ;
else
V_243 |= V_188 ;
F_36 ( V_27 -> V_10 , V_243 , V_27 -> V_76 ) ;
if ( V_27 -> V_161 ) {
F_108 ( V_239 , & V_27 -> V_198 ) ;
F_109 ( & V_27 -> V_233 ) ;
}
return 0 ;
}
static int F_17 ( struct V_5 * V_6 , void V_41 * V_256 , T_5 V_143 )
{
struct V_44 V_257 ;
struct V_7 * V_8 = V_6 -> V_21 ;
struct V_26 * V_27 = V_8 -> V_27 ;
int V_32 = 0 ;
memset ( & V_257 , 0 , sizeof( V_257 ) ) ;
V_257 . V_258 = ( ( ( V_27 -> V_66 >> V_259 ) &
V_260 ) << V_261 ) |
F_107 ( V_27 -> V_66 , V_262 ) |
F_110 ( V_27 -> V_66 , V_263 ) ;
if ( ! V_8 -> V_264 )
V_257 . V_258 |= V_265 ;
V_257 . V_266 = F_111 () ;
V_257 . V_267 = V_27 -> V_10 -> V_267 ;
V_257 . V_76 = V_27 -> V_76 ;
V_257 . V_56 = V_8 -> V_56 ;
V_257 . V_268 = F_112 ( V_27 -> V_137 . V_269 ,
V_27 -> V_10 -> V_270 . V_271 ) +
V_27 -> V_272 ;
V_257 . V_117 = V_27 -> V_48 -> V_117 ;
V_257 . V_273 = V_27 -> V_126 ;
V_257 . V_274 = V_8 -> V_17 ;
V_257 . V_275 = V_27 -> V_48 -> V_115 ;
V_257 . V_276 = V_27 -> V_137 . V_269 ;
V_257 . V_277 = V_27 -> V_277 ;
V_257 . V_278 = V_27 -> V_229 << 2 ;
V_257 . V_279 = V_8 -> V_85 -> V_166 ;
V_257 . V_280 = V_27 -> V_137 . V_281 ;
F_113 ( V_27 -> V_10 , V_27 -> V_76 , V_8 -> V_56 , V_257 ) ;
if ( F_22 ( V_256 , & V_257 , sizeof( V_257 ) ) )
V_32 = - V_42 ;
return V_32 ;
}
static int F_15 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_21 ;
struct V_26 * V_27 = V_8 -> V_27 ;
struct V_9 * V_10 = V_27 -> V_10 ;
int V_32 = 0 ;
if ( ! V_27 -> V_161 || ! V_8 -> V_56 ) {
V_32 = F_114 ( V_27 -> V_48 ) ;
if ( V_32 )
goto V_86;
V_32 = F_115 ( V_10 , V_27 ) ;
if ( V_32 )
goto V_86;
V_32 = F_116 ( V_27 ) ;
if ( V_32 )
goto V_86;
if ( V_27 -> V_161 && ! V_8 -> V_56 ) {
V_32 = F_101 ( V_27 ) ;
if ( V_32 )
goto V_86;
}
} else {
V_32 = F_117 ( V_27 -> V_233 , ! F_104 (
V_239 ,
& V_27 -> V_198 ) ) ;
if ( V_32 )
goto V_86;
}
V_32 = F_118 ( V_27 , V_6 ) ;
if ( V_32 )
goto V_86;
V_32 = F_119 ( V_6 ) ;
if ( V_32 )
goto V_86;
F_100 ( V_244 , & V_27 -> V_198 ) ;
V_86:
return V_32 ;
}
static int F_18 ( struct V_5 * V_6 , void V_41 * V_256 , T_5 V_143 )
{
struct V_46 V_282 ;
struct V_7 * V_8 = V_6 -> V_21 ;
struct V_26 * V_27 = V_8 -> V_27 ;
struct V_9 * V_10 = V_27 -> V_10 ;
T_3 V_283 ;
unsigned V_284 ;
int V_32 = 0 ;
F_120 ( V_27 -> V_10 , V_27 ) ;
memset ( & V_282 , 0 , sizeof( V_282 ) ) ;
V_282 . V_285 = V_10 -> V_286 ;
V_282 . V_287 = V_288 ;
V_282 . V_289 = V_290 ;
V_282 . V_222 = V_27 -> V_222 ;
V_284 = ( ( T_1 ) V_27 -> V_48 -> V_128 -
( T_1 ) V_10 -> V_125 [ V_27 -> V_126 ] . V_127 ) % V_130 ;
V_282 . V_291 = F_121 ( V_123 , V_27 -> V_76 ,
V_8 -> V_56 , V_284 ) ;
V_282 . V_292 = F_121 ( V_111 , V_27 -> V_76 ,
V_8 -> V_56 ,
V_27 -> V_48 -> V_293 ) ;
V_282 . V_294 = F_121 ( V_112 ,
V_27 -> V_76 ,
V_8 -> V_56 ,
V_27 -> V_48 -> V_293 ) ;
V_282 . V_295 = F_121 ( V_132 , V_27 -> V_76 ,
V_8 -> V_56 ,
V_27 -> V_134 ) ;
V_282 . V_296 = F_121 ( V_135 , V_27 -> V_76 ,
V_8 -> V_56 ,
V_27 -> V_137 . V_268 [ 0 ] . V_297 ) ;
V_282 . V_298 = F_121 ( V_164 , V_27 -> V_76 ,
V_8 -> V_56 , 0 ) ;
V_282 . V_299 = F_121 ( V_144 , V_27 -> V_76 ,
V_8 -> V_56 , 0 ) ;
V_284 = F_122 ( ( ( ( V_27 -> V_76 - V_10 -> V_149 ) *
V_150 ) + V_8 -> V_56 ) *
sizeof( * V_10 -> V_148 ) ) ;
V_282 . V_300 = F_121 ( V_147 , V_27 -> V_76 ,
V_8 -> V_56 ,
V_284 ) ;
V_282 . V_301 = F_121 ( V_152 , V_27 -> V_76 ,
V_8 -> V_56 ,
V_10 -> V_153 ) ;
if ( F_29 ( V_155 ) )
V_282 . V_302 = F_121 ( V_154 , V_27 -> V_76 ,
V_8 -> V_56 , 0 ) ;
if ( V_27 -> V_161 ) {
V_282 . V_158 = F_121 ( V_157 ,
V_27 -> V_76 ,
V_8 -> V_56 , 0 ) ;
V_282 . V_303 = F_121 ( V_159 ,
V_27 -> V_76 ,
V_8 -> V_56 , 0 ) ;
V_282 . V_163 = F_121 ( V_162 ,
V_27 -> V_76 ,
V_8 -> V_56 , 0 ) ;
}
V_283 = ( V_143 < sizeof( V_282 ) ) ? V_143 : sizeof( V_282 ) ;
if ( F_22 ( V_256 , & V_282 , V_283 ) )
V_32 = - V_42 ;
return V_32 ;
}
static unsigned int F_59 ( struct V_5 * V_6 ,
struct V_173 * V_174 )
{
struct V_7 * V_8 = V_6 -> V_21 ;
struct V_26 * V_27 = V_8 -> V_27 ;
struct V_9 * V_10 = V_27 -> V_10 ;
unsigned V_175 ;
F_123 ( V_6 , & V_27 -> V_233 , V_174 ) ;
F_124 ( & V_10 -> V_184 ) ;
if ( V_27 -> V_245 != V_27 -> V_246 ) {
V_175 = V_304 | V_305 ;
V_27 -> V_246 = V_27 -> V_245 ;
} else {
V_175 = 0 ;
F_100 ( V_306 , & V_27 -> V_198 ) ;
}
F_125 ( & V_10 -> V_184 ) ;
return V_175 ;
}
static unsigned int F_60 ( struct V_5 * V_6 ,
struct V_173 * V_174 )
{
struct V_7 * V_8 = V_6 -> V_21 ;
struct V_26 * V_27 = V_8 -> V_27 ;
struct V_9 * V_10 = V_27 -> V_10 ;
unsigned V_175 ;
F_123 ( V_6 , & V_27 -> V_233 , V_174 ) ;
F_124 ( & V_10 -> V_184 ) ;
if ( F_126 ( V_27 ) ) {
F_100 ( V_307 , & V_27 -> V_198 ) ;
F_36 ( V_10 , V_308 , V_27 -> V_76 ) ;
V_175 = 0 ;
} else {
V_175 = V_304 | V_305 ;
}
F_125 ( & V_10 -> V_184 ) ;
return V_175 ;
}
int F_127 ( struct V_309 * V_310 , const int V_311 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 = V_310 -> V_10 ;
unsigned V_76 ;
int V_32 = 0 ;
unsigned long V_66 ;
if ( ! V_10 -> V_148 ) {
V_32 = - V_40 ;
goto V_86;
}
F_67 ( & V_10 -> V_184 , V_66 ) ;
for ( V_76 = V_10 -> V_149 ; V_76 < V_10 -> V_220 ;
V_76 ++ ) {
V_27 = V_10 -> V_193 [ V_76 ] ;
if ( V_27 ) {
unsigned long * V_312 = V_10 -> V_148 +
( V_27 -> V_76 - V_10 -> V_149 ) *
V_150 ;
int V_136 ;
F_100 ( V_311 , V_312 ) ;
for ( V_136 = 1 ; V_136 < V_27 -> V_161 ; V_136 ++ )
F_100 ( V_311 , V_312 + V_136 ) ;
}
}
F_71 ( & V_10 -> V_184 , V_66 ) ;
V_86:
return V_32 ;
}
static int F_26 ( struct V_26 * V_27 , unsigned V_56 ,
int V_313 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
unsigned int V_314 ;
if ( V_56 )
goto V_240;
if ( V_313 ) {
if ( V_27 -> V_156 )
F_105 ( V_27 ) ;
V_314 = V_75 ;
} else {
V_314 = V_185 ;
}
F_36 ( V_10 , V_314 , V_27 -> V_76 ) ;
V_240:
return 0 ;
}
static int F_28 ( struct V_26 * V_27 , int V_56 ,
unsigned long V_148 )
{
int V_136 ;
struct V_9 * V_10 = V_27 -> V_10 ;
unsigned long * V_312 ;
if ( ! V_10 -> V_148 )
return 0 ;
V_312 = V_10 -> V_148 + ( ( V_27 -> V_76 - V_10 -> V_149 ) *
V_150 ) + V_56 ;
for ( V_136 = 0 ; V_136 <= V_315 ; V_136 ++ ) {
if ( ! F_104 ( V_136 , & V_148 ) )
continue;
F_108 ( V_136 , V_312 ) ;
}
return 0 ;
}
static int F_30 ( struct V_26 * V_27 , unsigned V_56 ,
T_2 V_316 )
{
int V_32 = - V_317 , V_136 , V_318 = 0 ;
struct V_309 * V_310 = V_27 -> V_310 ;
struct V_9 * V_10 = V_27 -> V_10 ;
if ( V_316 == V_319 || V_316 == V_320 ) {
V_32 = - V_40 ;
goto V_86;
}
for ( V_136 = 0 ; V_136 < F_128 ( V_310 -> V_321 ) ; V_136 ++ )
if ( V_316 == V_310 -> V_321 [ V_136 ] ) {
V_318 = 1 ;
break;
}
if ( V_318 )
V_32 = F_129 ( V_10 , V_27 -> V_76 , V_316 ) ;
V_86:
return V_32 ;
}
static void F_130 ( struct V_9 * V_10 )
{
F_131 ( & V_10 -> V_12 , & V_10 -> V_322 ) ;
}
static int F_132 ( struct V_9 * V_10 )
{
char V_323 [ 10 ] ;
int V_32 ;
snprintf ( V_323 , sizeof( V_323 ) , L_10 , F_133 () , V_10 -> V_267 ) ;
V_32 = F_134 ( V_10 -> V_267 , V_323 , & V_324 ,
& V_10 -> V_12 , & V_10 -> V_322 ,
true , & V_10 -> V_15 ) ;
if ( V_32 )
F_130 ( V_10 ) ;
return V_32 ;
}
int F_135 ( struct V_9 * V_10 )
{
return F_132 ( V_10 ) ;
}
void F_136 ( struct V_9 * V_10 )
{
F_130 ( V_10 ) ;
}
