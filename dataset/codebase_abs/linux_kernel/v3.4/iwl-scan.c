static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 V_5 = {
. V_6 = V_7 ,
. V_8 = V_9 | V_10 ,
} ;
T_1 * V_11 ;
if ( ! F_2 ( V_12 , & V_2 -> V_11 ) ||
! F_2 ( V_13 , & V_2 -> V_11 ) ||
! F_2 ( V_14 , & V_2 -> V_11 ) ||
F_2 ( V_15 , & V_2 -> V_16 -> V_11 ) )
return - V_17 ;
V_3 = F_3 ( V_2 , & V_5 ) ;
if ( V_3 )
return V_3 ;
V_11 = ( void * ) V_5 . V_18 -> V_19 ;
if ( * V_11 != V_20 ) {
F_4 ( V_2 , L_1 ,
F_5 ( * V_11 ) ) ;
V_3 = - V_17 ;
}
F_6 ( & V_5 ) ;
return V_3 ;
}
static void F_7 ( struct V_1 * V_2 , bool V_21 )
{
if ( V_2 -> V_22 ) {
F_4 ( V_2 , L_2 ) ;
F_8 ( V_2 -> V_23 , V_21 ) ;
}
if ( V_2 -> V_24 == V_25 ) {
F_9 ( V_2 -> V_23 ) ;
V_2 -> V_26 = NULL ;
F_10 ( & V_2 -> V_27 , 10 * V_28 ) ;
}
V_2 -> V_24 = V_29 ;
V_2 -> V_30 = NULL ;
V_2 -> V_22 = NULL ;
}
static void F_11 ( struct V_1 * V_2 )
{
bool V_21 ;
F_12 ( & V_2 -> V_31 ) ;
if ( ! F_13 ( V_32 , & V_2 -> V_11 ) )
return;
F_4 ( V_2 , L_3 ) ;
F_14 ( & V_2 -> V_33 ) ;
V_21 = F_13 ( V_34 , & V_2 -> V_11 ) ;
if ( V_21 )
F_4 ( V_2 , L_4 ) ;
if ( ! F_13 ( V_35 , & V_2 -> V_11 ) ) {
F_4 ( V_2 , L_5 ) ;
goto V_36;
}
if ( V_2 -> V_24 == V_25 ) {
F_9 ( V_2 -> V_23 ) ;
V_2 -> V_26 = NULL ;
F_10 ( & V_2 -> V_27 , 10 * V_28 ) ;
}
if ( V_2 -> V_24 != V_29 && ! V_21 ) {
int V_37 ;
if ( V_2 -> V_22 == NULL )
goto V_38;
V_37 = F_15 ( V_2 , V_2 -> V_30 , V_29 ,
V_2 -> V_22 -> V_39 [ 0 ] -> V_40 ) ;
if ( V_37 ) {
F_4 ( V_2 ,
L_6 , V_37 ) ;
V_21 = true ;
goto V_38;
}
return;
}
V_38:
F_7 ( V_2 , V_21 ) ;
V_36:
if ( ! F_16 ( V_2 ) )
return;
F_17 ( V_2 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_31 ) ;
if ( ! F_2 ( V_35 , & V_2 -> V_11 ) ) {
F_4 ( V_2 , L_7 ) ;
return;
}
F_4 ( V_2 , L_8 ) ;
F_19 ( V_35 , & V_2 -> V_11 ) ;
F_19 ( V_14 , & V_2 -> V_11 ) ;
F_19 ( V_34 , & V_2 -> V_11 ) ;
F_19 ( V_32 , & V_2 -> V_11 ) ;
F_7 ( V_2 , true ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
int V_3 ;
F_12 ( & V_2 -> V_31 ) ;
if ( ! F_2 ( V_35 , & V_2 -> V_11 ) ) {
F_4 ( V_2 , L_9 ) ;
return;
}
if ( F_21 ( V_34 , & V_2 -> V_11 ) ) {
F_4 ( V_2 , L_10 ) ;
return;
}
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_4 ( V_2 , L_11 , V_3 ) ;
F_18 ( V_2 ) ;
} else
F_4 ( V_2 , L_12 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
F_4 ( V_2 , L_13 ) ;
F_23 ( V_2 -> V_41 , & V_2 -> V_42 ) ;
return 0 ;
}
void F_24 ( struct V_1 * V_2 , unsigned long V_43 )
{
unsigned long V_44 = V_45 + F_25 ( V_43 ) ;
F_12 ( & V_2 -> V_31 ) ;
F_4 ( V_2 , L_14 ) ;
F_20 ( V_2 ) ;
while ( F_26 ( V_45 , V_44 ) ) {
if ( ! F_2 ( V_14 , & V_2 -> V_11 ) )
goto V_46;
F_27 ( 20 ) ;
}
return;
V_46:
F_11 ( V_2 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
struct V_49 * V_5 )
{
#ifdef F_29
struct V_50 * V_51 = F_30 ( V_48 ) ;
struct V_52 * V_53 = ( void * ) V_51 -> V_19 ;
F_4 ( V_2 , L_15 , V_53 -> V_11 ) ;
#endif
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
struct V_49 * V_5 )
{
struct V_50 * V_51 = F_30 ( V_48 ) ;
struct V_54 * V_53 = ( void * ) V_51 -> V_19 ;
V_2 -> V_55 = F_5 ( V_53 -> V_56 ) ;
F_4 ( V_2 , L_16
L_17
L_18 ,
V_53 -> V_57 ,
V_53 -> V_40 ? L_19 : L_20 ,
F_5 ( V_53 -> V_58 ) ,
F_5 ( V_53 -> V_56 ) ,
V_53 -> V_11 , V_53 -> V_59 ) ;
if ( V_2 -> V_24 == V_25 &&
! V_2 -> V_60 ) {
F_32 ( V_2 -> V_23 ) ;
V_2 -> V_60 = true ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
struct V_49 * V_5 )
{
#ifdef F_29
struct V_50 * V_51 = F_30 ( V_48 ) ;
struct V_61 * V_53 = ( void * ) V_51 -> V_19 ;
F_4 ( V_2 , L_21
L_17
L_22
L_23
L_24 ,
V_53 -> V_57 ,
V_53 -> V_40 ? L_19 : L_20 ,
V_53 -> V_62 , V_53 -> V_63 ,
F_5 ( V_53 -> V_58 ) ,
F_5 ( V_53 -> V_56 ) ,
F_5 ( V_53 -> V_64 [ 0 ] ) ,
F_5 ( V_53 -> V_56 ) - V_2 -> V_55 ) ;
#endif
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
struct V_49 * V_5 )
{
struct V_50 * V_51 = F_30 ( V_48 ) ;
struct V_65 * V_66 = ( void * ) V_51 -> V_19 ;
F_4 ( V_2 , L_25 ,
V_66 -> V_67 ,
V_66 -> V_56 ,
V_66 -> V_58 , V_66 -> V_11 ) ;
F_4 ( V_2 , L_26 ,
( V_2 -> V_68 == V_69 ) ? L_27 : L_28 ,
F_35 ( V_45 - V_2 -> V_70 ) ) ;
F_36 ( V_32 , & V_2 -> V_11 ) ;
F_19 ( V_14 , & V_2 -> V_11 ) ;
F_23 ( V_2 -> V_41 , & V_2 -> V_71 ) ;
if ( V_2 -> V_72 != V_73 &&
F_37 ( V_2 ) &&
V_2 -> V_74 != V_66 -> V_74 ) {
if ( V_66 -> V_74 ) {
if ( ! V_2 -> V_75 )
V_2 -> V_76 =
V_77 ;
} else {
V_2 -> V_76 =
V_78 ;
}
V_2 -> V_74 = V_66 -> V_74 ;
F_23 ( V_2 -> V_41 ,
& V_2 -> V_79 ) ;
}
return 0 ;
}
void F_38 ( struct V_1 * V_2 )
{
V_2 -> V_80 [ V_81 ] = F_28 ;
V_2 -> V_80 [ V_82 ] = F_31 ;
V_2 -> V_80 [ V_83 ] =
F_33 ;
V_2 -> V_80 [ V_84 ] =
F_34 ;
}
static T_2 F_39 ( struct V_1 * V_2 ,
enum V_85 V_40 , T_3 V_86 )
{
if ( V_40 == V_87 )
return V_88 +
V_89 * ( V_86 + 1 ) ;
else
return V_90 +
V_91 * ( V_86 + 1 ) ;
}
static T_2 F_40 ( struct V_1 * V_2 , T_2 V_92 )
{
struct V_93 * V_94 ;
F_41 (priv, ctx) {
T_2 V_95 ;
switch ( V_94 -> V_96 . V_97 ) {
case V_98 :
continue;
case V_99 :
default:
if ( ! F_42 ( V_94 ) )
continue;
break;
case V_100 :
case V_101 :
break;
}
V_95 = V_94 -> V_102 ;
if ( ! V_95 )
V_95 = V_103 ;
V_95 = ( V_95 * 98 ) / 100 - V_104 * 2 ;
V_92 = F_43 ( V_95 , V_92 ) ;
}
return V_92 ;
}
static T_2 F_44 ( struct V_1 * V_2 ,
enum V_85 V_40 )
{
T_2 V_105 = ( V_40 == V_69 ) ?
V_103 + V_106 :
V_103 + V_107 ;
return F_40 ( V_2 , V_105 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_108 * V_109 ,
enum V_85 V_40 ,
struct V_110 * V_111 )
{
const struct V_112 * V_113 ;
T_2 V_114 = 0 ;
T_2 V_115 = 0 ;
int V_116 = 0 ;
T_2 V_57 = 0 ;
V_113 = F_46 ( V_2 , V_40 ) ;
if ( ! V_113 ) {
F_47 ( V_2 , L_29 ) ;
return V_116 ;
}
V_115 = F_39 ( V_2 , V_40 , 0 ) ;
V_114 = F_44 ( V_2 , V_40 ) ;
if ( V_114 <= V_115 )
V_114 = V_115 + 1 ;
V_57 = F_48 ( V_2 , V_40 ) ;
if ( V_57 ) {
V_111 -> V_57 = F_49 ( V_57 ) ;
V_111 -> type = V_117 ;
V_111 -> V_115 = F_49 ( V_115 ) ;
V_111 -> V_114 = F_49 ( V_114 ) ;
V_111 -> V_118 = 110 ;
if ( V_40 == V_87 )
V_111 -> V_119 = ( ( 1 << 5 ) | ( 3 << 3 ) ) | 3 ;
else
V_111 -> V_119 = ( ( 1 << 5 ) | ( 5 << 3 ) ) ;
V_116 ++ ;
} else
F_47 ( V_2 , L_30 ) ;
return V_116 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_108 * V_109 ,
enum V_85 V_40 ,
T_3 V_120 , T_3 V_86 ,
struct V_110 * V_111 )
{
struct V_121 * V_122 ;
const struct V_112 * V_113 ;
const struct V_123 * V_124 ;
T_2 V_114 = 0 ;
T_2 V_115 = 0 ;
int V_116 , V_125 ;
T_2 V_57 ;
V_113 = F_46 ( V_2 , V_40 ) ;
if ( ! V_113 )
return 0 ;
V_115 = F_39 ( V_2 , V_40 , V_86 ) ;
V_114 = F_44 ( V_2 , V_40 ) ;
if ( V_114 <= V_115 )
V_114 = V_115 + 1 ;
for ( V_125 = 0 , V_116 = 0 ; V_125 < V_2 -> V_22 -> V_126 ; V_125 ++ ) {
V_122 = V_2 -> V_22 -> V_39 [ V_125 ] ;
if ( V_122 -> V_40 != V_40 )
continue;
V_57 = V_122 -> V_127 ;
V_111 -> V_57 = F_49 ( V_57 ) ;
V_124 = F_51 ( V_2 , V_40 , V_57 ) ;
if ( ! F_52 ( V_124 ) ) {
F_4 ( V_2 ,
L_31 ,
V_57 ) ;
continue;
}
if ( ! V_120 || F_53 ( V_124 ) ||
( V_122 -> V_8 & V_128 ) )
V_111 -> type = V_117 ;
else
V_111 -> type = V_129 ;
if ( V_86 )
V_111 -> type |= F_54 ( V_86 ) ;
V_111 -> V_115 = F_49 ( V_115 ) ;
V_111 -> V_114 = F_49 ( V_114 ) ;
V_111 -> V_118 = 110 ;
if ( V_40 == V_87 )
V_111 -> V_119 = ( ( 1 << 5 ) | ( 3 << 3 ) ) | 3 ;
else
V_111 -> V_119 = ( ( 1 << 5 ) | ( 5 << 3 ) ) ;
F_4 ( V_2 , L_32 ,
V_57 , F_5 ( V_111 -> type ) ,
( V_111 -> type & V_129 ) ?
L_33 : L_34 ,
( V_111 -> type & V_129 ) ?
V_115 : V_114 ) ;
V_111 ++ ;
V_116 ++ ;
}
F_4 ( V_2 , L_35 , V_116 ) ;
return V_116 ;
}
static T_2 F_55 ( struct V_130 * V_131 , const T_3 * V_132 ,
const T_3 * V_133 , int V_134 , int V_135 )
{
int V_136 = 0 ;
T_3 * V_137 = NULL ;
V_135 -= 24 ;
if ( V_135 < 0 )
return 0 ;
V_131 -> V_138 = F_49 ( V_139 ) ;
memcpy ( V_131 -> V_140 , V_141 , V_142 ) ;
memcpy ( V_131 -> V_143 , V_132 , V_142 ) ;
memcpy ( V_131 -> V_144 , V_141 , V_142 ) ;
V_131 -> V_145 = 0 ;
V_136 += 24 ;
V_137 = & V_131 -> V_146 . V_147 . V_148 [ 0 ] ;
V_135 -= 2 ;
if ( V_135 < 0 )
return 0 ;
* V_137 ++ = V_149 ;
* V_137 ++ = 0 ;
V_136 += 2 ;
if ( F_56 ( V_135 < V_134 ) )
return V_136 ;
if ( V_133 && V_134 ) {
memcpy ( V_137 , V_133 , V_134 ) ;
V_136 += V_134 ;
}
return ( T_2 ) V_136 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_108 * V_109 )
{
struct V_4 V_5 = {
. V_6 = V_81 ,
. V_136 = { sizeof( struct V_150 ) , } ,
. V_8 = V_9 ,
} ;
struct V_150 * V_151 ;
struct V_93 * V_94 = & V_2 -> V_152 [ V_153 ] ;
T_4 V_154 = 0 ;
T_2 V_155 = 0 ;
T_2 V_156 = 0 ;
enum V_85 V_40 ;
T_3 V_86 = 0 ;
T_3 V_157 = F_58 ( V_2 ) . V_158 ;
T_3 V_159 ;
bool V_120 = false ;
int V_160 ;
T_3 V_161 ;
T_3 V_162 = F_58 ( V_2 ) . V_163 ;
int V_3 ;
F_12 ( & V_2 -> V_31 ) ;
if ( V_109 )
V_94 = F_59 ( V_109 ) ;
if ( ! V_2 -> V_164 ) {
V_2 -> V_164 = F_60 ( sizeof( struct V_150 ) +
V_165 , V_166 ) ;
if ( ! V_2 -> V_164 ) {
F_4 ( V_2 ,
L_36 ) ;
return - V_167 ;
}
}
V_151 = V_2 -> V_164 ;
memset ( V_151 , 0 , sizeof( struct V_150 ) + V_165 ) ;
V_151 -> V_168 = V_169 ;
V_151 -> V_170 = V_171 ;
if ( V_2 -> V_24 != V_25 &&
F_61 ( V_2 ) ) {
T_2 V_172 = 0 ;
T_4 V_173 ;
T_4 V_174 = 100 ;
T_4 V_175 = 100 ;
F_62 ( V_2 , L_37 ) ;
switch ( V_2 -> V_24 ) {
case V_25 :
F_56 ( 1 ) ;
break;
case V_176 :
V_172 = 0 ;
break;
case V_29 :
V_172 = V_109 -> V_177 . V_102 ;
break;
}
V_151 -> V_174 = 0 ;
V_151 -> V_178 = F_63 ( 200 * 1024 ) ;
if ( ! V_172 )
V_172 = V_174 ;
V_173 = ( V_174 / V_172 ) << 22 ;
V_175 = ( V_173 |
( ( V_174 % V_172 ) * 1024 ) ) ;
V_151 -> V_174 = F_63 ( V_175 ) ;
F_4 ( V_2 , L_38 ,
V_175 , V_172 ) ;
} else if ( V_2 -> V_24 == V_25 ) {
V_151 -> V_174 = 0 ;
V_151 -> V_178 = 0 ;
V_151 -> V_170 = 0 ;
V_151 -> V_168 = 0 ;
}
switch ( V_2 -> V_24 ) {
case V_176 :
F_4 ( V_2 , L_39 ) ;
break;
case V_29 :
if ( V_2 -> V_22 -> V_179 ) {
int V_125 , V_180 = 0 ;
F_4 ( V_2 , L_40 ) ;
for ( V_125 = 0 ; V_125 < V_2 -> V_22 -> V_179 ; V_125 ++ ) {
if ( ! V_2 -> V_22 -> V_181 [ V_125 ] . V_182 )
continue;
V_151 -> V_183 [ V_180 ] . V_6 = V_149 ;
V_151 -> V_183 [ V_180 ] . V_136 =
V_2 -> V_22 -> V_181 [ V_125 ] . V_182 ;
memcpy ( V_151 -> V_183 [ V_180 ] . V_184 ,
V_2 -> V_22 -> V_181 [ V_125 ] . V_184 ,
V_2 -> V_22 -> V_181 [ V_125 ] . V_182 ) ;
V_86 ++ ;
V_180 ++ ;
}
V_120 = true ;
} else
F_4 ( V_2 , L_41 ) ;
break;
case V_25 :
F_4 ( V_2 , L_42 ) ;
break;
}
V_151 -> V_185 . V_186 = V_187 ;
V_151 -> V_185 . V_188 = V_94 -> V_189 ;
V_151 -> V_185 . V_190 . V_191 = V_192 ;
switch ( V_2 -> V_68 ) {
case V_69 :
V_151 -> V_8 = V_193 | V_194 ;
V_160 = F_5 (
V_2 -> V_152 [ V_153 ] . V_195 . V_8 &
V_196 )
>> V_197 ;
if ( ( V_2 -> V_22 && V_2 -> V_22 -> V_198 ) ||
V_160 == V_199 ) {
V_159 = V_200 ;
} else {
V_159 = V_201 ;
V_154 = V_202 ;
}
if ( F_64 ( V_2 ) -> V_203 &&
F_64 ( V_2 ) -> V_203 -> V_204 )
V_151 -> V_185 . V_186 |= V_205 ;
break;
case V_87 :
V_159 = V_200 ;
break;
default:
F_65 ( V_2 , L_43 ) ;
return - V_17 ;
}
if ( V_2 -> V_206 )
V_151 -> V_207 = V_120 ? V_208 :
V_209 ;
else
V_151 -> V_207 = V_120 ? V_208 :
V_210 ;
V_40 = V_2 -> V_68 ;
if ( F_64 ( V_2 ) -> V_211 [ V_40 ] )
V_157 = F_64 ( V_2 ) -> V_211 [ V_40 ] ;
if ( V_40 == V_69 &&
F_64 ( V_2 ) -> V_203 &&
F_64 ( V_2 ) -> V_203 -> V_204 ) {
V_162 = F_66 ( V_162 ) ;
}
V_2 -> V_212 [ V_40 ] = F_67 ( V_2 ,
V_2 -> V_212 [ V_40 ] ,
V_162 ) ;
V_154 |= F_68 ( V_2 -> V_212 [ V_40 ] ) ;
V_151 -> V_185 . V_213 = F_69 ( V_159 , V_154 ) ;
if ( F_2 ( V_214 , & V_2 -> V_16 -> V_11 ) ) {
V_161 = V_157 &
( ( T_3 ) ( V_2 -> V_215 . V_161 ) ) ;
if ( ! V_161 )
V_161 = V_157 ;
F_4 ( V_2 , L_44 ,
V_2 -> V_215 . V_161 ) ;
V_157 = F_66 ( V_161 ) ;
}
if ( F_64 ( V_2 ) -> V_203 &&
F_64 ( V_2 ) -> V_203 -> V_204 &&
V_2 -> V_216 ) {
V_157 = F_66 ( V_157 ) ;
}
V_156 |=
F_58 ( V_2 ) . V_158 << V_217 ;
V_156 |= V_157 << V_218 ;
V_156 |= V_157 << V_219 ;
V_156 |= 0x1 << V_220 ;
V_151 -> V_156 = F_49 ( V_156 ) ;
switch ( V_2 -> V_24 ) {
case V_29 :
V_155 = F_55 (
(struct V_130 * ) V_151 -> V_19 ,
V_109 -> V_221 ,
V_2 -> V_22 -> V_222 ,
V_2 -> V_22 -> V_134 ,
V_165 - sizeof( * V_151 ) ) ;
break;
case V_176 :
case V_25 :
V_155 = F_55 (
(struct V_130 * ) V_151 -> V_19 ,
V_141 , NULL , 0 ,
V_165 - sizeof( * V_151 ) ) ;
break;
default:
F_70 () ;
}
V_151 -> V_185 . V_136 = F_49 ( V_155 ) ;
V_151 -> V_223 |= ( V_224 |
V_225 ) ;
switch ( V_2 -> V_24 ) {
case V_176 :
V_151 -> V_226 =
F_45 ( V_2 , V_109 , V_40 ,
( void * ) & V_151 -> V_19 [ V_155 ] ) ;
break;
case V_29 :
V_151 -> V_226 =
F_50 ( V_2 , V_109 , V_40 ,
V_120 , V_86 ,
( void * ) & V_151 -> V_19 [ V_155 ] ) ;
break;
case V_25 : {
struct V_110 * V_111 ;
int V_227 , V_125 ;
T_2 V_228 ;
V_228 = F_40 ( V_2 , V_2 -> V_229 ) ;
V_227 = F_71 ( V_2 -> V_229 , V_228 ) ;
V_151 -> V_226 = V_227 ;
V_111 = ( void * ) & V_151 -> V_19 [ V_155 ] ;
for ( V_125 = 0 ; V_125 < V_227 ; V_125 ++ ) {
V_111 -> type = V_117 ;
V_111 -> V_57 =
F_49 ( V_2 -> V_26 -> V_127 ) ;
if ( V_125 == V_227 - 1 )
V_228 = V_2 -> V_229 - V_125 * V_228 ;
V_111 -> V_115 =
V_111 -> V_114 = F_49 ( V_228 ) ;
V_111 -> V_118 = 110 ;
if ( V_2 -> V_26 -> V_40 == V_87 )
V_111 -> V_119 = ( ( 1 << 5 ) | ( 3 << 3 ) ) | 3 ;
else
V_111 -> V_119 = ( ( 1 << 5 ) | ( 5 << 3 ) ) ;
V_111 ++ ;
}
}
break;
}
if ( V_151 -> V_226 == 0 ) {
F_4 ( V_2 , L_45 , V_151 -> V_226 ) ;
return - V_17 ;
}
V_5 . V_136 [ 0 ] += F_72 ( V_151 -> V_185 . V_136 ) +
V_151 -> V_226 * sizeof( struct V_110 ) ;
V_5 . V_19 [ 0 ] = V_151 ;
V_5 . V_230 [ 0 ] = V_231 ;
V_151 -> V_136 = F_49 ( V_5 . V_136 [ 0 ] ) ;
F_36 ( V_14 , & V_2 -> V_11 ) ;
V_3 = F_73 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_3 ( V_2 , & V_5 ) ;
if ( V_3 ) {
F_19 ( V_14 , & V_2 -> V_11 ) ;
F_73 ( V_2 ) ;
}
return V_3 ;
}
void F_74 ( struct V_1 * V_2 )
{
T_3 V_232 = F_75 ( F_58 ( V_2 ) . V_163 ) - 1 ;
if ( ! V_2 -> V_212 [ V_87 ] )
V_2 -> V_212 [ V_87 ] = V_232 ;
if ( ! V_2 -> V_212 [ V_69 ] )
V_2 -> V_212 [ V_69 ] = V_232 ;
}
int T_5 F_15 ( struct V_1 * V_2 ,
struct V_108 * V_109 ,
enum V_233 V_24 ,
enum V_85 V_40 )
{
int V_3 ;
F_12 ( & V_2 -> V_31 ) ;
F_14 ( & V_2 -> V_33 ) ;
if ( ! F_16 ( V_2 ) ) {
F_65 ( V_2 , L_46 ) ;
return - V_17 ;
}
if ( F_2 ( V_14 , & V_2 -> V_11 ) ) {
F_4 ( V_2 ,
L_47 ) ;
return - V_234 ;
}
if ( F_2 ( V_34 , & V_2 -> V_11 ) ) {
F_4 ( V_2 , L_48 ) ;
return - V_234 ;
}
F_4 ( V_2 , L_49 ,
V_24 == V_29 ? L_50 :
V_24 == V_25 ? L_51 :
L_52 ) ;
F_36 ( V_35 , & V_2 -> V_11 ) ;
V_2 -> V_24 = V_24 ;
V_2 -> V_70 = V_45 ;
V_2 -> V_68 = V_40 ;
V_3 = F_57 ( V_2 , V_109 ) ;
if ( V_3 ) {
F_19 ( V_35 , & V_2 -> V_11 ) ;
V_2 -> V_24 = V_29 ;
return V_3 ;
}
F_76 ( V_2 -> V_41 , & V_2 -> V_33 ,
V_235 ) ;
return 0 ;
}
void F_77 ( struct V_1 * V_2 )
{
F_23 ( V_2 -> V_41 , & V_2 -> V_236 ) ;
}
static void F_78 ( struct V_237 * V_238 )
{
struct V_1 * V_2 =
F_79 ( V_238 , struct V_1 , V_236 ) ;
F_4 ( V_2 , L_53 ) ;
F_80 ( & V_2 -> V_31 ) ;
if ( V_2 -> V_24 == V_176 ) {
F_4 ( V_2 , L_54 ) ;
goto V_239;
}
if ( F_2 ( V_35 , & V_2 -> V_11 ) ) {
F_4 ( V_2 , L_55 ) ;
goto V_239;
}
if ( F_15 ( V_2 , NULL , V_176 , V_2 -> V_40 ) )
F_4 ( V_2 , L_56 ) ;
V_239:
F_81 ( & V_2 -> V_31 ) ;
}
static void F_82 ( struct V_237 * V_19 )
{
struct V_1 * V_2 =
F_79 ( V_19 , struct V_1 , V_33 . V_238 ) ;
F_4 ( V_2 , L_57 ) ;
F_80 ( & V_2 -> V_31 ) ;
F_18 ( V_2 ) ;
F_81 ( & V_2 -> V_31 ) ;
}
static void F_83 ( struct V_237 * V_238 )
{
struct V_1 * V_2 = F_79 ( V_238 , struct V_1 , V_42 ) ;
F_4 ( V_2 , L_58 ) ;
F_80 ( & V_2 -> V_31 ) ;
F_24 ( V_2 , 200 ) ;
F_81 ( & V_2 -> V_31 ) ;
}
static void F_84 ( struct V_237 * V_238 )
{
struct V_1 * V_2 =
F_79 ( V_238 , struct V_1 , V_71 ) ;
F_80 ( & V_2 -> V_31 ) ;
F_11 ( V_2 ) ;
F_81 ( & V_2 -> V_31 ) ;
}
void F_85 ( struct V_1 * V_2 )
{
F_86 ( & V_2 -> V_71 , F_84 ) ;
F_86 ( & V_2 -> V_42 , F_83 ) ;
F_86 ( & V_2 -> V_236 , F_78 ) ;
F_87 ( & V_2 -> V_33 , F_82 ) ;
}
void F_88 ( struct V_1 * V_2 )
{
F_89 ( & V_2 -> V_236 ) ;
F_89 ( & V_2 -> V_42 ) ;
F_89 ( & V_2 -> V_71 ) ;
if ( F_90 ( & V_2 -> V_33 ) ) {
F_80 ( & V_2 -> V_31 ) ;
F_18 ( V_2 ) ;
F_81 ( & V_2 -> V_31 ) ;
}
}
