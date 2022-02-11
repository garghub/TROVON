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
F_8 ( V_8 -> V_18 ) ;
V_6 -> V_20 = V_8 ;
} else {
V_6 -> V_20 = NULL ;
if ( F_9 ( & V_10 -> V_13 ) )
F_10 ( & V_10 -> V_21 ) ;
return - V_22 ;
}
return 0 ;
}
static long F_11 ( struct V_5 * V_6 , unsigned int V_23 ,
unsigned long V_24 )
{
struct V_7 * V_8 = V_6 -> V_20 ;
struct V_25 * V_26 = V_8 -> V_26 ;
struct V_27 V_28 ;
struct V_29 V_30 ;
int V_31 = 0 ;
unsigned long V_32 ;
int V_33 = 0 ;
unsigned long V_34 = 0 ;
T_2 V_35 = 0 ;
F_12 ( V_36 , L_1 , V_23 ) ;
if ( V_23 != V_37 &&
V_23 != V_38 &&
! V_26 )
return - V_39 ;
switch ( V_23 ) {
case V_37 :
if ( V_26 )
return - V_39 ;
if ( F_13 ( & V_28 ,
(struct V_27 V_40 * ) V_24 ,
sizeof( V_28 ) ) )
return - V_41 ;
V_31 = F_14 ( V_6 , & V_28 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_15 ( V_6 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_16 ( V_6 ) ;
break;
case V_42 :
V_31 = F_17 ( V_6 , ( void V_40 * ) ( unsigned long ) V_24 ,
sizeof( struct V_43 ) ) ;
break;
case V_44 :
V_31 = F_18 ( V_6 , ( void V_40 * ) ( unsigned long ) V_24 ,
sizeof( struct V_45 ) ) ;
break;
case V_46 :
if ( V_26 )
F_19 ( V_26 -> V_47 ) ;
break;
case V_48 :
if ( F_13 ( & V_30 ,
(struct V_49 V_40 * ) V_24 ,
sizeof( V_30 ) ) )
return - V_41 ;
V_31 = F_20 ( V_6 , & V_30 ) ;
if ( ! V_31 ) {
V_32 = V_24 + F_21 ( struct V_29 , V_50 ) ;
if ( F_22 ( ( void V_40 * ) V_32 , & V_30 . V_50 ,
sizeof( V_30 . V_50 ) +
sizeof( V_30 . V_51 ) ) )
V_31 = - V_41 ;
}
break;
case V_52 :
if ( F_13 ( & V_30 ,
(struct V_49 V_40 * ) V_24 ,
sizeof( V_30 ) ) )
return - V_41 ;
V_31 = F_23 ( V_6 , & V_30 ) ;
if ( V_31 )
break;
V_32 = V_24 + F_21 ( struct V_29 , V_50 ) ;
if ( F_22 ( ( void V_40 * ) V_32 , & V_30 . V_50 ,
sizeof( V_30 . V_50 ) ) )
V_31 = - V_41 ;
break;
case V_53 :
if ( F_13 ( & V_30 ,
(struct V_49 V_40 * ) V_24 ,
sizeof( V_30 ) ) )
return - V_41 ;
V_31 = F_24 ( V_6 , & V_30 ) ;
if ( V_31 )
break;
V_32 = V_24 + F_21 ( struct V_29 , V_50 ) ;
if ( F_22 ( ( void V_40 * ) V_32 , & V_30 . V_50 ,
sizeof( V_30 . V_50 ) ) )
V_31 = - V_41 ;
break;
case V_54 :
V_31 = F_25 ( V_33 , ( int V_40 * ) V_24 ) ;
if ( V_31 != 0 )
return - V_41 ;
V_31 = F_26 ( V_26 , V_8 -> V_55 , V_33 ) ;
break;
case V_56 :
V_31 = F_25 ( V_33 , ( int V_40 * ) V_24 ) ;
if ( V_31 != 0 )
return - V_41 ;
V_26 -> V_57 = ( F_27 ( V_26 -> V_57 ) ) V_33 ;
break;
case V_58 :
V_31 = F_25 ( V_34 , ( unsigned long V_40 * ) V_24 ) ;
if ( V_31 != 0 )
return - V_41 ;
V_31 = F_28 ( V_26 , V_8 -> V_55 , V_34 ) ;
break;
case V_59 :
V_31 = F_25 ( V_35 , ( T_2 V_40 * ) V_24 ) ;
if ( V_31 != 0 )
return - V_41 ;
if ( F_29 ( V_60 ) )
V_31 = F_30 ( V_26 , V_8 -> V_55 , V_35 ) ;
else
return - V_61 ;
break;
case V_62 : {
struct V_63 * V_47 ;
struct V_9 * V_10 ;
if ( ! V_26 || ! V_26 -> V_10 || ! V_26 -> V_47 )
return - V_39 ;
V_10 = V_26 -> V_10 ;
V_47 = V_26 -> V_47 ;
F_31 (
V_47 -> V_64 , ( V_47 -> V_65 & V_66 ) ,
F_32 ( V_67 ) ) ;
if ( ! ( V_47 -> V_65 & V_66 ) )
return - V_68 ;
if ( V_47 -> V_65 & V_69 ) {
F_31 (
V_10 -> V_70 ,
! ( F_33 ( V_10 -> V_65 ) & V_71 ) ,
F_32 ( V_67 ) ) ;
if ( V_10 -> V_65 & V_71 )
return - V_68 ;
if ( V_10 -> V_65 & V_72 )
return - V_73 ;
F_34 ( V_47 ) ;
V_31 = F_35 ( V_47 ) ;
F_36 ( V_10 , V_74 ,
V_26 -> V_75 ) ;
} else {
V_31 = F_37 ( V_47 ) ;
}
if ( ! V_31 )
F_19 ( V_47 ) ;
break;
}
case V_38 :
V_33 = V_76 ;
if ( F_38 ( V_33 , ( int V_40 * ) V_24 ) )
return - V_41 ;
break;
default:
return - V_39 ;
}
return V_31 ;
}
static T_3 F_39 ( struct V_77 * V_77 , struct V_78 * V_79 )
{
struct V_7 * V_8 = V_77 -> V_80 -> V_20 ;
struct V_81 * V_82 = V_8 -> V_82 ;
struct V_83 * V_84 = V_8 -> V_84 ;
int V_85 = 0 , V_86 = 0 ;
unsigned long V_87 = V_79 -> V_88 ;
if ( ! V_84 || ! V_82 )
return - V_89 ;
if ( ! F_40 ( V_79 ) || ! V_87 )
return - V_39 ;
F_12 ( V_90 , L_2 ,
V_8 -> V_26 -> V_75 , V_8 -> V_55 , V_87 ) ;
if ( F_41 ( & V_82 -> V_91 ) == V_82 -> V_92 )
return - V_93 ;
while ( V_87 ) {
int V_31 ;
unsigned long V_94 = 0 ;
V_31 = F_42 (
V_77 -> V_80 , (struct V_95 * ) ( V_79 -> V_96 + V_85 ) ,
V_87 , & V_94 ) ;
if ( V_31 ) {
V_86 = V_31 ;
break;
}
V_87 -= V_94 ;
V_85 += V_94 ;
V_86 ++ ;
}
return V_86 ;
}
static int F_43 ( struct V_5 * V_6 , struct V_97 * V_98 )
{
struct V_7 * V_8 = V_6 -> V_20 ;
struct V_25 * V_26 = V_8 -> V_26 ;
struct V_9 * V_10 ;
unsigned long V_65 ;
T_1 V_1 = V_98 -> V_99 << V_100 ,
V_101 = 0 ;
void * V_102 = NULL ;
T_4 V_55 , V_103 = 0 , V_104 = 0 , type ;
T_3 V_105 = 0 ;
int V_31 = 0 ;
T_2 V_75 ;
if ( ! F_1 ( V_1 ) || ! V_26 ||
! ( V_98 -> V_106 & V_107 ) ) {
V_31 = - V_39 ;
goto V_85;
}
V_10 = V_26 -> V_10 ;
V_75 = F_2 ( V_108 , V_1 ) ;
V_55 = F_2 ( V_109 , V_1 ) ;
type = F_2 ( TYPE , V_1 ) ;
if ( V_75 != V_26 -> V_75 || V_55 != V_8 -> V_55 ) {
V_31 = - V_39 ;
goto V_85;
}
V_65 = V_98 -> V_106 ;
switch ( type ) {
case V_110 :
case V_111 :
V_101 = ( ( V_10 -> V_112 + V_113 ) +
( V_26 -> V_47 -> V_114 * F_44 ( 16 ) ) ) +
( type == V_111 ?
( V_115 / 2 ) : 0 ) ;
V_105 = F_45 ( V_26 -> V_47 -> V_116 * V_117 ) ;
V_65 &= ~ V_118 ;
V_65 |= V_119 | V_120 ;
V_98 -> V_121 = F_46 ( V_98 -> V_121 ) ;
V_103 = 1 ;
break;
case V_122 :
if ( V_65 & V_123 ) {
V_31 = - V_61 ;
goto V_85;
}
V_102 = V_10 -> V_124 [ V_26 -> V_125 ] . V_126 ;
V_101 = F_47 ( V_102 ) +
( ( ( T_1 ) V_26 -> V_47 -> V_127 -
( T_1 ) V_10 -> V_124 [ V_26 -> V_125 ] . V_126 ) & V_128 ) ;
V_105 = V_129 ;
V_65 &= ~ V_130 ;
V_65 |= V_119 | V_120 ;
V_103 = 1 ;
break;
case V_131 :
V_105 = V_26 -> V_132 ;
V_102 = V_26 -> V_133 ;
break;
case V_134 : {
unsigned long V_32 ;
int V_135 ;
V_105 = V_26 -> V_136 . V_137 ;
if ( ( V_98 -> V_138 - V_98 -> V_139 ) != V_105 ) {
F_48 ( V_10 , L_3 ,
( V_98 -> V_138 - V_98 -> V_139 ) , V_105 ) ;
V_31 = - V_39 ;
goto V_85;
}
if ( V_98 -> V_106 & V_123 ) {
V_31 = - V_61 ;
goto V_85;
}
V_98 -> V_106 &= ~ V_130 ;
V_32 = V_98 -> V_139 ;
for ( V_135 = 0 ; V_135 < V_26 -> V_136 . V_140 ; V_135 ++ ) {
V_105 = V_26 -> V_136 . V_141 [ V_135 ] . V_142 ;
V_102 = V_26 -> V_136 . V_141 [ V_135 ] . V_32 ;
V_31 = F_49 (
V_98 , V_32 ,
F_50 ( F_51 ( V_102 ) ) ,
V_105 ,
V_98 -> V_121 ) ;
if ( V_31 < 0 )
goto V_85;
V_32 += V_105 ;
}
V_31 = 0 ;
goto V_85;
}
case V_143 :
V_101 = ( unsigned long )
( V_10 -> V_112 + V_144 )
+ ( V_26 -> V_75 * V_145 ) ;
V_105 = V_129 ;
V_65 |= V_119 | V_120 ;
V_98 -> V_121 = F_52 ( V_98 -> V_121 ) ;
V_103 = 1 ;
break;
case V_146 :
V_101 = ( unsigned long ) ( V_10 -> V_147 +
( ( V_26 -> V_75 - V_10 -> V_148 ) *
V_149 ) ) & V_128 ;
V_105 = V_129 ;
V_65 |= V_150 | V_120 ;
V_104 = 1 ;
break;
case V_151 :
V_101 = F_53 ( ( void * ) V_10 -> V_152 ) ;
V_105 = V_129 ;
V_65 |= V_150 | V_120 ;
break;
case V_153 :
if ( ! F_29 ( V_154 ) ) {
V_31 = - V_39 ;
goto V_85;
}
if ( V_65 & V_123 ) {
V_31 = - V_61 ;
goto V_85;
}
V_105 = V_129 ;
V_102 = ( void * ) V_26 -> V_155 ;
V_65 &= ~ V_130 ;
break;
case V_156 :
V_101 = ( T_1 ) V_26 -> V_157 ;
V_105 = V_129 ;
V_65 |= V_150 | V_120 ;
V_104 = 1 ;
break;
case V_158 :
V_101 = ( T_1 ) V_26 -> V_159 ;
V_105 = V_26 -> V_132 * V_26 -> V_160 ;
V_65 |= V_150 | V_120 ;
V_104 = 1 ;
break;
case V_161 :
V_101 = ( T_1 ) V_26 -> V_162 ;
V_105 = V_26 -> V_136 . V_137 * V_26 -> V_160 ;
V_65 |= V_150 | V_120 ;
V_65 &= ~ V_130 ;
V_104 = 1 ;
break;
case V_163 : {
struct V_83 * V_84 = V_8 -> V_84 ;
if ( ! V_84 ) {
V_31 = - V_41 ;
goto V_85;
}
V_101 = ( T_1 ) V_84 -> V_164 ;
V_105 = F_45 ( sizeof( * V_84 -> V_164 ) * V_84 -> V_165 ) ;
V_65 |= V_150 | V_120 ;
V_104 = 1 ;
break;
}
default:
V_31 = - V_39 ;
break;
}
if ( ( V_98 -> V_138 - V_98 -> V_139 ) != V_105 ) {
F_12 ( V_166 , L_4 ,
V_26 -> V_75 , V_8 -> V_55 ,
( V_98 -> V_138 - V_98 -> V_139 ) , V_105 ) ;
V_31 = - V_39 ;
goto V_85;
}
V_98 -> V_106 = V_65 ;
F_12 ( V_166 ,
L_5 ,
V_75 , V_55 , type , V_103 , V_104 , V_101 , V_105 ,
V_98 -> V_138 - V_98 -> V_139 , V_98 -> V_106 ) ;
if ( V_104 ) {
V_98 -> V_99 = F_50 ( V_101 ) ;
V_98 -> V_167 = & V_167 ;
V_31 = 0 ;
} else if ( V_103 ) {
V_31 = F_54 ( V_98 , V_98 -> V_139 ,
F_50 ( V_101 ) ,
V_105 ,
V_98 -> V_121 ) ;
} else if ( V_102 ) {
V_31 = F_49 ( V_98 , V_98 -> V_139 ,
F_50 ( F_51 ( V_102 ) ) ,
V_105 ,
V_98 -> V_121 ) ;
} else {
V_31 = F_49 ( V_98 , V_98 -> V_139 ,
F_50 ( V_101 ) ,
V_105 ,
V_98 -> V_121 ) ;
}
V_85:
return V_31 ;
}
static int F_55 ( struct V_168 * V_104 )
{
struct V_169 * V_169 ;
V_169 = F_56 ( ( void * ) ( V_104 -> V_170 << V_100 ) ) ;
if ( ! V_169 )
return V_171 ;
F_57 ( V_169 ) ;
V_104 -> V_169 = V_169 ;
return 0 ;
}
static unsigned int F_58 ( struct V_5 * V_6 , struct V_172 * V_173 )
{
struct V_25 * V_26 ;
unsigned V_174 ;
V_26 = ( (struct V_7 * ) V_6 -> V_20 ) -> V_26 ;
if ( ! V_26 )
V_174 = V_175 ;
else if ( V_26 -> V_57 == V_176 )
V_174 = F_59 ( V_6 , V_173 ) ;
else if ( V_26 -> V_57 == V_177 )
V_174 = F_60 ( V_6 , V_173 ) ;
else
V_174 = V_175 ;
return V_174 ;
}
static int F_61 ( struct V_4 * V_4 , struct V_5 * V_6 )
{
struct V_7 * V_178 = V_6 -> V_20 ;
struct V_25 * V_26 = V_178 -> V_26 ;
struct V_9 * V_10 = F_4 ( V_4 -> V_11 ,
struct V_9 ,
V_12 ) ;
unsigned long V_65 , * V_179 ;
V_6 -> V_20 = NULL ;
if ( ! V_26 )
goto V_85;
F_12 ( V_166 , L_6 , V_26 -> V_75 , V_178 -> V_55 ) ;
F_62 ( & V_180 ) ;
F_63 () ;
F_64 ( V_178 ) ;
F_65 ( V_178 -> V_17 ) ;
V_179 = V_10 -> V_147 + ( ( V_26 -> V_75 - V_10 -> V_148 ) *
V_149 ) + V_178 -> V_55 ;
* V_179 = 0 ;
if ( -- V_26 -> V_181 ) {
V_26 -> V_182 &= ~ ( 1 << V_178 -> V_55 ) ;
F_66 ( & V_180 ) ;
goto V_85;
}
F_67 ( & V_10 -> V_183 , V_65 ) ;
F_36 ( V_10 , V_184 |
V_185 |
V_186 |
V_187 |
V_188 |
V_189 |
V_190 , V_26 -> V_75 ) ;
F_68 ( V_10 , V_26 -> V_75 ) ;
F_69 ( V_10 , V_26 -> V_47 -> V_114 , V_191 ,
F_70 ( V_10 , V_26 -> V_47 -> type ) ) ;
F_34 ( V_26 -> V_47 ) ;
F_71 ( & V_10 -> V_183 , V_65 ) ;
V_10 -> V_192 [ V_26 -> V_75 ] = NULL ;
F_72 ( V_178 ) ;
F_73 ( V_10 , V_26 -> V_75 ) ;
V_26 -> V_193 = 0 ;
V_26 -> V_194 = 0 ;
V_26 -> V_195 = 0 ;
V_26 -> V_196 = 0 ;
V_26 -> V_197 = 0 ;
V_198 . V_199 -- ;
if ( ++ V_10 -> V_200 == V_10 -> V_201 )
F_74 ( V_10 ) ;
F_66 ( & V_180 ) ;
F_75 ( V_10 , V_26 ) ;
V_85:
F_76 ( V_178 -> V_18 ) ;
F_77 ( & V_10 -> V_15 ) ;
if ( F_9 ( & V_10 -> V_13 ) )
F_10 ( & V_10 -> V_21 ) ;
F_78 ( V_178 ) ;
return 0 ;
}
static T_1 F_53 ( void * V_32 )
{
struct V_169 * V_169 ;
T_1 V_202 = 0 ;
V_169 = F_56 ( V_32 ) ;
if ( V_169 )
V_202 = F_79 ( V_169 ) << V_100 ;
return V_202 ;
}
static int F_14 ( struct V_5 * V_6 , struct V_27 * V_28 )
{
int V_203 , V_31 = 0 ;
unsigned int V_204 , V_205 ;
V_204 = V_28 -> V_206 >> 16 ;
if ( V_204 != V_207 ) {
V_31 = - V_73 ;
goto V_85;
}
V_205 = V_28 -> V_206 & 0xffff ;
F_62 ( & V_180 ) ;
if ( V_28 -> V_160 ) {
struct V_7 * V_8 = V_6 -> V_20 ;
V_31 = F_80 ( V_6 , V_28 ) ;
if ( V_31 < 0 )
goto V_208;
if ( V_31 ) {
V_8 -> V_17 =
F_81 ( V_8 -> V_26 -> V_125 ) ;
}
}
if ( ! V_31 ) {
V_203 = F_82 ( F_83 ( V_6 ) ) - V_209 ;
V_31 = F_84 ( V_6 , V_28 , V_203 ) ;
}
V_208:
F_66 ( & V_180 ) ;
V_85:
return V_31 ;
}
static int F_84 ( struct V_5 * V_6 , struct V_27 * V_28 ,
int V_210 )
{
struct V_9 * V_10 = NULL ;
int V_211 , V_212 , V_213 ;
V_211 = F_85 ( & V_212 , & V_213 ) ;
if ( ! V_212 )
return - V_14 ;
if ( ! V_213 )
return - V_214 ;
V_10 = F_86 ( V_210 ) ;
if ( ! V_10 )
return - V_73 ;
else if ( ! V_10 -> V_200 )
return - V_215 ;
return F_87 ( V_6 , V_10 , V_28 ) ;
}
static int F_80 ( struct V_5 * V_6 ,
const struct V_27 * V_28 )
{
int V_211 , V_216 , V_135 ;
int V_31 = 0 ;
struct V_7 * V_8 = V_6 -> V_20 ;
V_211 = F_85 ( NULL , NULL ) ;
for ( V_216 = 0 ; V_216 < V_211 ; V_216 ++ ) {
struct V_9 * V_10 = F_86 ( V_216 ) ;
if ( ! ( V_10 && ( V_10 -> V_65 & V_217 ) && V_10 -> V_218 ) )
continue;
for ( V_135 = V_10 -> V_148 ; V_135 < V_10 -> V_219 ; V_135 ++ ) {
struct V_25 * V_26 = V_10 -> V_192 [ V_135 ] ;
if ( ! V_26 || ! V_26 -> V_181 )
continue;
if ( memcmp ( V_26 -> V_220 , V_28 -> V_220 ,
sizeof( V_26 -> V_220 ) ) ||
V_26 -> V_221 != F_88 ( F_89 () ) ||
V_26 -> V_222 != V_28 -> V_222 ||
V_26 -> V_160 != V_28 -> V_160 )
continue;
if ( V_26 -> V_206 != V_28 -> V_206 ||
V_26 -> V_181 >= V_26 -> V_160 ) {
V_31 = - V_39 ;
goto V_85;
}
V_8 -> V_26 = V_26 ;
V_8 -> V_55 = V_26 -> V_181 ++ ;
V_26 -> V_182 |= 1 << V_8 -> V_55 ;
V_31 = 1 ;
goto V_85;
}
}
V_85:
return V_31 ;
}
static int F_87 ( struct V_5 * V_6 , struct V_9 * V_10 ,
struct V_27 * V_28 )
{
struct V_7 * V_8 = V_6 -> V_20 ;
struct V_25 * V_26 ;
unsigned V_75 ;
int V_31 , V_223 ;
if ( V_10 -> V_65 & V_71 ) {
return - V_89 ;
}
for ( V_75 = V_10 -> V_148 ; V_75 < V_10 -> V_219 ; V_75 ++ )
if ( ! V_10 -> V_192 [ V_75 ] )
break;
if ( V_75 == V_10 -> V_219 )
return - V_215 ;
V_8 -> V_17 = F_81 ( V_10 -> V_224 ) ;
if ( V_8 -> V_17 != - 1 )
V_223 = F_90 ( V_8 -> V_17 ) ;
else
V_223 = F_91 () ;
V_26 = F_92 ( V_10 -> V_225 , V_75 , V_223 ) ;
if ( ! V_26 ) {
F_48 ( V_10 ,
L_7 ) ;
return - V_22 ;
}
F_12 ( V_166 , L_8 ,
V_26 -> V_75 , V_8 -> V_55 , V_19 -> V_226 , V_8 -> V_17 ,
V_26 -> V_125 ) ;
V_26 -> V_47 = F_93 ( V_10 , V_227 , V_26 -> V_228 ,
V_26 -> V_10 -> V_224 ) ;
if ( ! V_26 -> V_47 ) {
V_31 = - V_22 ;
goto V_229;
}
F_12 ( V_166 , L_9 , V_26 -> V_47 -> V_230 ,
V_26 -> V_47 -> V_114 ) ;
V_31 = F_35 ( V_26 -> V_47 ) ;
if ( V_31 )
goto V_229;
if ( V_28 -> V_160 && ! V_8 -> V_55 ) {
V_31 = F_94 ( V_26 , V_28 ) ;
if ( V_31 )
goto V_229;
}
V_26 -> V_206 = V_28 -> V_206 ;
V_26 -> V_65 = V_231 ;
F_95 ( & V_26 -> V_232 ) ;
F_96 ( V_26 -> V_233 , V_19 -> V_233 , sizeof( V_26 -> V_233 ) ) ;
memcpy ( V_26 -> V_220 , V_28 -> V_220 , sizeof( V_26 -> V_220 ) ) ;
V_26 -> V_221 = F_88 ( F_89 () ) ;
F_97 ( & V_26 -> V_234 ) ;
F_98 ( & V_26 -> V_235 ) ;
V_198 . V_199 ++ ;
if ( V_10 -> V_200 -- == V_10 -> V_201 )
F_99 ( V_10 ) ;
V_8 -> V_26 = V_26 ;
return 0 ;
V_229:
V_10 -> V_192 [ V_75 ] = NULL ;
F_75 ( V_10 , V_26 ) ;
return V_31 ;
}
static int F_94 ( struct V_25 * V_26 ,
const struct V_27 * V_28 )
{
unsigned V_236 ;
V_236 = V_28 -> V_160 ;
if ( V_236 > V_149 )
return - V_39 ;
V_26 -> V_160 = V_28 -> V_160 ;
V_26 -> V_222 = V_28 -> V_222 ;
V_26 -> V_182 = 1 ;
V_26 -> V_237 = 1 ;
F_100 ( V_238 , & V_26 -> V_197 ) ;
return 0 ;
}
static int F_101 ( struct V_25 * V_26 )
{
int V_31 = 0 ;
unsigned V_236 = V_26 -> V_160 ;
V_26 -> V_157 = F_102 ( V_129 ) ;
if ( ! V_26 -> V_157 ) {
V_31 = - V_22 ;
goto V_239;
}
V_26 -> V_159 = F_102 ( V_26 -> V_132 *
V_236 ) ;
if ( ! V_26 -> V_159 ) {
V_31 = - V_22 ;
goto V_240;
}
V_26 -> V_162 = F_102 ( V_26 -> V_136 . V_137 *
V_236 ) ;
if ( ! V_26 -> V_162 ) {
V_31 = - V_22 ;
goto V_241;
}
goto V_239;
V_241:
F_103 ( V_26 -> V_159 ) ;
V_240:
F_103 ( V_26 -> V_157 ) ;
V_26 -> V_157 = NULL ;
V_239:
return V_31 ;
}
static int F_16 ( struct V_5 * V_6 )
{
unsigned int V_242 = 0 ;
struct V_7 * V_8 = V_6 -> V_20 ;
struct V_25 * V_26 = V_8 -> V_26 ;
if ( ! F_104 ( V_243 , & V_26 -> V_197 ) )
return - V_41 ;
V_26 -> V_244 = 0 ;
V_26 -> V_245 = 0 ;
if ( V_26 -> V_155 )
F_105 ( V_26 ) ;
F_106 ( V_26 -> V_10 , V_26 -> V_75 , V_26 -> V_221 ) ;
V_242 = V_74 ;
if ( F_107 ( V_26 -> V_65 , V_246 ) )
V_242 |= V_247 ;
if ( ! F_107 ( V_26 -> V_65 , V_248 ) )
V_242 |= V_249 ;
if ( F_107 ( V_26 -> V_65 , V_250 ) )
V_242 |= V_251 ;
if ( F_107 ( V_26 -> V_65 , V_252 ) )
V_242 |= V_253 ;
if ( F_107 ( V_26 -> V_65 , V_154 ) )
V_242 |= V_254 ;
else
V_242 |= V_187 ;
F_36 ( V_26 -> V_10 , V_242 , V_26 -> V_75 ) ;
if ( V_26 -> V_160 ) {
F_108 ( V_238 , & V_26 -> V_197 ) ;
F_109 ( & V_26 -> V_232 ) ;
}
return 0 ;
}
static int F_17 ( struct V_5 * V_6 , void V_40 * V_255 , T_5 V_142 )
{
struct V_43 V_256 ;
struct V_7 * V_8 = V_6 -> V_20 ;
struct V_25 * V_26 = V_8 -> V_26 ;
int V_31 = 0 ;
memset ( & V_256 , 0 , sizeof( V_256 ) ) ;
V_256 . V_257 = ( ( ( V_26 -> V_65 >> V_258 ) &
V_259 ) << V_260 ) |
F_107 ( V_26 -> V_65 , V_261 ) |
F_110 ( V_26 -> V_65 , V_262 ) ;
if ( ! V_8 -> V_263 )
V_256 . V_257 |= V_264 ;
V_256 . V_265 = F_111 () ;
V_256 . V_266 = V_26 -> V_10 -> V_266 ;
V_256 . V_75 = V_26 -> V_75 ;
V_256 . V_55 = V_8 -> V_55 ;
V_256 . V_267 = F_112 ( V_26 -> V_136 . V_268 ,
V_26 -> V_10 -> V_269 . V_270 ) +
V_26 -> V_271 ;
V_256 . V_116 = V_26 -> V_47 -> V_116 ;
V_256 . V_272 = V_26 -> V_125 ;
V_256 . V_273 = V_8 -> V_17 ;
V_256 . V_274 = V_26 -> V_47 -> V_114 ;
V_256 . V_275 = V_26 -> V_136 . V_268 ;
V_256 . V_276 = V_26 -> V_276 ;
V_256 . V_277 = V_26 -> V_228 << 2 ;
V_256 . V_278 = V_8 -> V_84 -> V_165 ;
V_256 . V_279 = V_26 -> V_136 . V_280 ;
F_113 ( V_26 -> V_10 , V_26 -> V_75 , V_8 -> V_55 , V_256 ) ;
if ( F_22 ( V_255 , & V_256 , sizeof( V_256 ) ) )
V_31 = - V_41 ;
return V_31 ;
}
static int F_15 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_20 ;
struct V_25 * V_26 = V_8 -> V_26 ;
struct V_9 * V_10 = V_26 -> V_10 ;
int V_31 = 0 ;
if ( ! V_26 -> V_160 || ! V_8 -> V_55 ) {
V_31 = F_114 ( V_26 -> V_47 ) ;
if ( V_31 )
goto V_85;
V_31 = F_115 ( V_10 , V_26 ) ;
if ( V_31 )
goto V_85;
V_31 = F_116 ( V_26 ) ;
if ( V_31 )
goto V_85;
if ( V_26 -> V_160 && ! V_8 -> V_55 ) {
V_31 = F_101 ( V_26 ) ;
if ( V_31 )
goto V_85;
}
} else {
V_31 = F_117 ( V_26 -> V_232 , ! F_104 (
V_238 ,
& V_26 -> V_197 ) ) ;
if ( V_31 )
goto V_85;
}
V_31 = F_118 ( V_26 , V_6 ) ;
if ( V_31 )
goto V_85;
V_31 = F_119 ( V_6 ) ;
if ( V_31 )
goto V_85;
F_100 ( V_243 , & V_26 -> V_197 ) ;
V_85:
return V_31 ;
}
static int F_18 ( struct V_5 * V_6 , void V_40 * V_255 , T_5 V_142 )
{
struct V_45 V_281 ;
struct V_7 * V_8 = V_6 -> V_20 ;
struct V_25 * V_26 = V_8 -> V_26 ;
struct V_9 * V_10 = V_26 -> V_10 ;
T_3 V_282 ;
unsigned V_283 ;
int V_31 = 0 ;
F_120 ( V_26 -> V_10 , V_26 ) ;
memset ( & V_281 , 0 , sizeof( V_281 ) ) ;
V_281 . V_284 = V_10 -> V_285 ;
V_281 . V_286 = V_287 ;
V_281 . V_288 = V_289 ;
V_281 . V_221 = V_26 -> V_221 ;
V_283 = ( ( T_1 ) V_26 -> V_47 -> V_127 -
( T_1 ) V_10 -> V_124 [ V_26 -> V_125 ] . V_126 ) % V_129 ;
V_281 . V_290 = F_121 ( V_122 , V_26 -> V_75 ,
V_8 -> V_55 , V_283 ) ;
V_281 . V_291 = F_121 ( V_110 , V_26 -> V_75 ,
V_8 -> V_55 ,
V_26 -> V_47 -> V_292 ) ;
V_281 . V_293 = F_121 ( V_111 ,
V_26 -> V_75 ,
V_8 -> V_55 ,
V_26 -> V_47 -> V_292 ) ;
V_281 . V_294 = F_121 ( V_131 , V_26 -> V_75 ,
V_8 -> V_55 ,
V_26 -> V_133 ) ;
V_281 . V_295 = F_121 ( V_134 , V_26 -> V_75 ,
V_8 -> V_55 ,
V_26 -> V_136 . V_267 [ 0 ] . V_296 ) ;
V_281 . V_297 = F_121 ( V_163 , V_26 -> V_75 ,
V_8 -> V_55 , 0 ) ;
V_281 . V_298 = F_121 ( V_143 , V_26 -> V_75 ,
V_8 -> V_55 , 0 ) ;
V_283 = F_122 ( ( ( ( V_26 -> V_75 - V_10 -> V_148 ) *
V_149 ) + V_8 -> V_55 ) *
sizeof( * V_10 -> V_147 ) ) ;
V_281 . V_299 = F_121 ( V_146 , V_26 -> V_75 ,
V_8 -> V_55 ,
V_283 ) ;
V_281 . V_300 = F_121 ( V_151 , V_26 -> V_75 ,
V_8 -> V_55 ,
V_10 -> V_152 ) ;
if ( F_29 ( V_154 ) )
V_281 . V_301 = F_121 ( V_153 , V_26 -> V_75 ,
V_8 -> V_55 , 0 ) ;
if ( V_26 -> V_160 ) {
V_281 . V_157 = F_121 ( V_156 ,
V_26 -> V_75 ,
V_8 -> V_55 , 0 ) ;
V_281 . V_302 = F_121 ( V_158 ,
V_26 -> V_75 ,
V_8 -> V_55 , 0 ) ;
V_281 . V_162 = F_121 ( V_161 ,
V_26 -> V_75 ,
V_8 -> V_55 , 0 ) ;
}
V_282 = ( V_142 < sizeof( V_281 ) ) ? V_142 : sizeof( V_281 ) ;
if ( F_22 ( V_255 , & V_281 , V_282 ) )
V_31 = - V_41 ;
return V_31 ;
}
static unsigned int F_59 ( struct V_5 * V_6 ,
struct V_172 * V_173 )
{
struct V_7 * V_8 = V_6 -> V_20 ;
struct V_25 * V_26 = V_8 -> V_26 ;
struct V_9 * V_10 = V_26 -> V_10 ;
unsigned V_174 ;
F_123 ( V_6 , & V_26 -> V_232 , V_173 ) ;
F_124 ( & V_10 -> V_183 ) ;
if ( V_26 -> V_244 != V_26 -> V_245 ) {
V_174 = V_303 | V_304 ;
V_26 -> V_245 = V_26 -> V_244 ;
} else {
V_174 = 0 ;
F_100 ( V_305 , & V_26 -> V_197 ) ;
}
F_125 ( & V_10 -> V_183 ) ;
return V_174 ;
}
static unsigned int F_60 ( struct V_5 * V_6 ,
struct V_172 * V_173 )
{
struct V_7 * V_8 = V_6 -> V_20 ;
struct V_25 * V_26 = V_8 -> V_26 ;
struct V_9 * V_10 = V_26 -> V_10 ;
unsigned V_174 ;
F_123 ( V_6 , & V_26 -> V_232 , V_173 ) ;
F_124 ( & V_10 -> V_183 ) ;
if ( F_126 ( V_26 ) ) {
F_100 ( V_306 , & V_26 -> V_197 ) ;
F_36 ( V_10 , V_307 , V_26 -> V_75 ) ;
V_174 = 0 ;
} else {
V_174 = V_303 | V_304 ;
}
F_125 ( & V_10 -> V_183 ) ;
return V_174 ;
}
int F_127 ( struct V_308 * V_309 , const int V_310 )
{
struct V_25 * V_26 ;
struct V_9 * V_10 = V_309 -> V_10 ;
unsigned V_75 ;
int V_31 = 0 ;
unsigned long V_65 ;
if ( ! V_10 -> V_147 ) {
V_31 = - V_39 ;
goto V_85;
}
F_67 ( & V_10 -> V_183 , V_65 ) ;
for ( V_75 = V_10 -> V_148 ; V_75 < V_10 -> V_219 ;
V_75 ++ ) {
V_26 = V_10 -> V_192 [ V_75 ] ;
if ( V_26 ) {
unsigned long * V_311 = V_10 -> V_147 +
( V_26 -> V_75 - V_10 -> V_148 ) *
V_149 ;
int V_135 ;
F_100 ( V_310 , V_311 ) ;
for ( V_135 = 1 ; V_135 < V_26 -> V_160 ; V_135 ++ )
F_100 ( V_310 , V_311 + V_135 ) ;
}
}
F_71 ( & V_10 -> V_183 , V_65 ) ;
V_85:
return V_31 ;
}
static int F_26 ( struct V_25 * V_26 , unsigned V_55 ,
int V_312 )
{
struct V_9 * V_10 = V_26 -> V_10 ;
unsigned int V_313 ;
if ( V_55 )
goto V_239;
if ( V_312 ) {
if ( V_26 -> V_155 )
F_105 ( V_26 ) ;
V_313 = V_74 ;
} else {
V_313 = V_184 ;
}
F_36 ( V_10 , V_313 , V_26 -> V_75 ) ;
V_239:
return 0 ;
}
static int F_28 ( struct V_25 * V_26 , int V_55 ,
unsigned long V_147 )
{
int V_135 ;
struct V_9 * V_10 = V_26 -> V_10 ;
unsigned long * V_311 ;
if ( ! V_10 -> V_147 )
return 0 ;
V_311 = V_10 -> V_147 + ( ( V_26 -> V_75 - V_10 -> V_148 ) *
V_149 ) + V_55 ;
for ( V_135 = 0 ; V_135 <= V_314 ; V_135 ++ ) {
if ( ! F_104 ( V_135 , & V_147 ) )
continue;
F_108 ( V_135 , V_311 ) ;
}
return 0 ;
}
static int F_30 ( struct V_25 * V_26 , unsigned V_55 ,
T_2 V_315 )
{
int V_31 = - V_316 , V_135 , V_317 = 0 ;
struct V_308 * V_309 = V_26 -> V_309 ;
struct V_9 * V_10 = V_26 -> V_10 ;
if ( V_315 == V_318 || V_315 == V_319 ) {
V_31 = - V_39 ;
goto V_85;
}
for ( V_135 = 0 ; V_135 < F_128 ( V_309 -> V_320 ) ; V_135 ++ )
if ( V_315 == V_309 -> V_320 [ V_135 ] ) {
V_317 = 1 ;
break;
}
if ( V_317 )
V_31 = F_129 ( V_10 , V_26 -> V_75 , V_315 ) ;
V_85:
return V_31 ;
}
static void F_130 ( struct V_9 * V_10 )
{
F_131 ( & V_10 -> V_12 , & V_10 -> V_321 ) ;
}
static int F_132 ( struct V_9 * V_10 )
{
char V_322 [ 10 ] ;
int V_31 ;
snprintf ( V_322 , sizeof( V_322 ) , L_10 , F_133 () , V_10 -> V_266 ) ;
V_31 = F_134 ( V_10 -> V_266 , V_322 , & V_323 ,
& V_10 -> V_12 , & V_10 -> V_321 ,
true , & V_10 -> V_15 ) ;
if ( V_31 )
F_130 ( V_10 ) ;
return V_31 ;
}
int F_135 ( struct V_9 * V_10 )
{
return F_132 ( V_10 ) ;
}
void F_136 ( struct V_9 * V_10 )
{
F_130 ( V_10 ) ;
}
