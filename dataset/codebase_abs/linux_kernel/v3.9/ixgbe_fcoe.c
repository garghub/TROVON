static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 1 ;
V_2 -> V_5 = NULL ;
V_2 -> V_6 = 0UL ;
V_2 -> V_7 = NULL ;
V_2 -> V_8 = 0 ;
}
int F_2 ( struct V_9 * V_10 , T_1 V_11 )
{
int V_3 = 0 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
T_2 V_16 ;
if ( ! V_10 )
goto V_17;
if ( V_11 >= V_18 )
goto V_17;
V_15 = F_3 ( V_10 ) ;
V_13 = & V_15 -> V_13 ;
V_2 = & V_13 -> V_2 [ V_11 ] ;
if ( ! V_2 -> V_5 )
goto V_17;
V_3 = V_2 -> V_3 ;
if ( V_2 -> V_4 ) {
F_4 ( & V_13 -> V_19 ) ;
F_5 ( & V_15 -> V_20 , V_21 , 0 ) ;
F_5 ( & V_15 -> V_20 , V_22 ,
( V_11 | V_23 ) ) ;
F_5 ( & V_15 -> V_20 , V_24 , 0 ) ;
F_5 ( & V_15 -> V_20 , V_25 ,
( V_11 | V_26 ) ) ;
F_5 ( & V_15 -> V_20 , V_25 ,
( V_11 | V_27 ) ) ;
V_16 = F_6 ( & V_15 -> V_20 , V_24 ) ;
F_7 ( & V_13 -> V_19 ) ;
if ( V_16 & V_28 )
F_8 ( 100 ) ;
}
if ( V_2 -> V_7 )
F_9 ( & V_15 -> V_29 -> V_30 , V_2 -> V_7 , V_2 -> V_8 ,
V_31 ) ;
if ( V_2 -> V_32 ) {
F_10 ( V_2 -> V_32 , V_2 -> V_5 , V_2 -> V_6 ) ;
V_2 -> V_32 = NULL ;
}
F_1 ( V_2 ) ;
V_17:
return V_3 ;
}
static int F_11 ( struct V_9 * V_10 , T_1 V_11 ,
struct V_33 * V_7 , unsigned int V_8 ,
int V_34 )
{
struct V_14 * V_15 ;
struct V_35 * V_20 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
struct V_36 * V_37 ;
struct V_33 * V_38 ;
unsigned int V_39 , V_40 , V_41 ;
unsigned int V_3 ;
static const unsigned int V_42 = V_43 ;
unsigned int V_44 = 0 ;
unsigned int V_45 ;
unsigned int V_46 = 0 ;
unsigned int V_47 = 0 ;
T_2 V_16 , V_48 , V_49 , V_50 ;
T_3 V_51 = 0 ;
if ( ! V_10 || ! V_7 )
return 0 ;
V_15 = F_3 ( V_10 ) ;
if ( V_11 >= V_18 ) {
F_12 ( V_52 , L_1 , V_11 ) ;
return 0 ;
}
if ( F_13 ( V_53 , & V_15 -> V_54 ) ||
F_13 ( V_55 , & V_15 -> V_54 ) )
return 0 ;
V_13 = & V_15 -> V_13 ;
V_2 = & V_13 -> V_2 [ V_11 ] ;
if ( V_2 -> V_7 ) {
F_14 ( V_52 , L_2 ,
V_11 , V_2 -> V_7 , V_2 -> V_8 ) ;
return 0 ;
}
F_1 ( V_2 ) ;
if ( ! V_13 -> V_37 ) {
F_12 ( V_52 , L_3 ) ;
return 0 ;
}
V_37 = F_15 ( V_13 -> V_37 , F_16 () ) ;
if ( ! V_37 -> V_32 ) {
F_12 ( V_52 , L_4 , V_11 ) ;
goto V_56;
}
V_41 = F_17 ( & V_15 -> V_29 -> V_30 , V_7 , V_8 , V_31 ) ;
if ( V_41 == 0 ) {
F_14 ( V_52 , L_5 , V_11 ) ;
goto V_56;
}
V_2 -> V_5 = F_18 ( V_37 -> V_32 , V_57 , & V_2 -> V_6 ) ;
if ( ! V_2 -> V_5 ) {
F_14 ( V_52 , L_6 ) ;
goto V_58;
}
V_2 -> V_32 = V_37 -> V_32 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_8 = V_8 ;
V_40 = 0 ;
F_19 (sgl, sg, dmacount, i) {
V_51 = F_20 ( V_38 ) ;
V_3 = F_21 ( V_38 ) ;
while ( V_3 ) {
if ( V_40 >= V_59 ) {
V_37 -> V_60 ++ ;
goto V_61;
}
V_46 = V_51 & ( ( T_3 ) V_42 - 1 ) ;
V_47 = F_22 ( ( V_42 - V_46 ) , V_3 ) ;
if ( ( V_40 != 0 ) && ( V_46 ) )
goto V_61;
if ( ( ( V_39 != ( V_41 - 1 ) ) || ( V_47 != V_3 ) )
&& ( ( V_47 + V_46 ) != V_42 ) )
goto V_61;
V_2 -> V_5 [ V_40 ] = ( V_62 ) ( V_51 - V_46 ) ;
if ( V_40 == 0 )
V_44 = V_46 ;
V_3 -= V_47 ;
V_51 += V_47 ;
V_40 ++ ;
}
}
V_45 = V_46 + V_47 ;
if ( V_45 == V_42 ) {
if ( V_40 >= V_59 ) {
V_37 -> V_63 ++ ;
goto V_61;
}
V_2 -> V_5 [ V_40 ] = ( V_62 ) ( V_13 -> V_64 ) ;
V_40 ++ ;
V_45 = 1 ;
}
F_23 () ;
V_16 = ( V_65 << V_66 ) ;
V_16 |= ( ( V_40 & 0xff ) << V_67 ) ;
V_16 |= ( V_44 << V_68 ) ;
if ( V_34 )
V_16 |= ( V_69 ) ;
V_16 |= ( V_28 ) ;
V_48 = V_11 ;
V_48 |= V_26 ;
V_48 |= ( V_45 << V_70 ) ;
V_49 = V_11 ;
V_49 |= V_23 ;
V_20 = & V_15 -> V_20 ;
F_4 ( & V_13 -> V_19 ) ;
if ( V_34 && ! F_13 ( V_71 , & V_13 -> V_72 ) ) {
F_24 ( V_71 , & V_13 -> V_72 ) ;
V_50 = F_6 ( V_20 , V_73 ) ;
V_50 |= V_74 ;
F_5 ( V_20 , V_73 , V_50 ) ;
}
F_5 ( V_20 , V_75 , V_2 -> V_6 & F_25 ( 32 ) ) ;
F_5 ( V_20 , V_76 , ( V_62 ) V_2 -> V_6 >> 32 ) ;
F_5 ( V_20 , V_24 , V_16 ) ;
F_5 ( V_20 , V_25 , V_48 ) ;
F_5 ( V_20 , V_77 , 0 ) ;
F_5 ( V_20 , V_21 , V_78 ) ;
F_5 ( V_20 , V_22 , V_49 ) ;
F_7 ( & V_13 -> V_19 ) ;
return 1 ;
V_61:
F_10 ( V_2 -> V_32 , V_2 -> V_5 , V_2 -> V_6 ) ;
F_1 ( V_2 ) ;
V_58:
F_9 ( & V_15 -> V_29 -> V_30 , V_7 , V_8 , V_31 ) ;
V_56:
F_23 () ;
return 0 ;
}
int F_26 ( struct V_9 * V_10 , T_1 V_11 ,
struct V_33 * V_7 , unsigned int V_8 )
{
return F_11 ( V_10 , V_11 , V_7 , V_8 , 0 ) ;
}
int F_27 ( struct V_9 * V_10 , T_1 V_11 ,
struct V_33 * V_7 , unsigned int V_8 )
{
return F_11 ( V_10 , V_11 , V_7 , V_8 , 1 ) ;
}
int V_1 ( struct V_14 * V_15 ,
union V_79 * V_80 ,
struct V_81 * V_82 )
{
int V_83 = - V_84 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
struct V_85 * V_86 ;
struct V_87 * V_88 ;
T_4 V_89 = F_28 ( V_80 , V_90 ) ;
T_4 V_91 ;
T_2 V_92 ;
T_1 V_11 ;
if ( V_89 == F_29 ( V_93 ) )
V_82 -> V_94 = V_95 ;
else
V_82 -> V_94 = V_96 ;
if ( F_30 ( V_82 ) -> V_97 == F_31 ( V_98 ) )
V_86 = (struct V_85 * ) ( V_82 -> V_99 +
sizeof( struct V_100 ) + sizeof( struct V_101 ) ) ;
else
V_86 = (struct V_85 * ) ( V_82 -> V_99 +
sizeof( struct V_101 ) ) ;
V_92 = F_32 ( V_86 -> V_102 ) ;
if ( V_92 & V_103 )
V_11 = F_33 ( V_86 -> V_104 ) ;
else
V_11 = F_33 ( V_86 -> V_105 ) ;
if ( V_11 >= V_18 )
goto V_106;
V_13 = & V_15 -> V_13 ;
V_2 = & V_13 -> V_2 [ V_11 ] ;
if ( ! V_2 -> V_5 )
goto V_106;
V_91 = F_28 ( V_80 , V_107 |
V_90 ) ;
if ( V_91 )
goto V_106;
switch ( F_28 ( V_80 , V_108 ) ) {
case F_34 ( V_109 ) :
V_2 -> V_3 = F_35 ( V_80 -> V_110 . V_111 . V_112 . V_113 ) ;
V_83 = 0 ;
break;
case F_34 ( V_114 ) :
F_9 ( & V_15 -> V_29 -> V_30 , V_2 -> V_7 ,
V_2 -> V_8 , V_31 ) ;
V_2 -> V_4 = V_91 ;
V_2 -> V_7 = NULL ;
V_2 -> V_8 = 0 ;
case F_34 ( V_115 ) :
V_2 -> V_3 = F_35 ( V_80 -> V_110 . V_111 . V_112 . V_113 ) ;
if ( V_2 -> V_3 )
V_83 = V_2 -> V_3 ;
break;
case F_34 ( V_116 ) :
default:
break;
}
if ( ( V_86 -> V_117 == V_118 ) &&
( V_92 & V_119 ) ) {
F_36 ( V_82 ) ;
V_88 = (struct V_87 * ) F_37 ( V_82 , sizeof( * V_88 ) ) ;
V_88 -> V_120 = V_121 ;
}
V_106:
return V_83 ;
}
int F_38 ( struct V_122 * V_123 ,
struct V_124 * V_125 ,
T_5 * V_126 )
{
struct V_81 * V_82 = V_125 -> V_82 ;
struct V_85 * V_86 ;
T_2 V_127 ;
T_2 V_128 = 0 ;
T_2 V_129 ;
T_5 V_130 , V_131 ;
if ( F_39 ( V_82 ) && ( F_40 ( V_82 ) -> V_132 != V_133 ) ) {
F_41 ( V_123 -> V_30 , L_7 ,
F_40 ( V_82 ) -> V_132 ) ;
return - V_84 ;
}
F_42 ( V_82 , V_82 -> V_134 ) ;
F_43 ( V_82 , V_82 -> V_134 +
sizeof( struct V_101 ) ) ;
V_130 = ( (struct V_101 * ) F_44 ( V_82 ) ) -> V_135 ;
switch ( V_130 ) {
case V_136 :
V_128 = V_137 ;
break;
case V_138 :
V_128 = V_139 |
V_137 ;
break;
case V_140 :
break;
case V_141 :
V_128 = V_139 ;
break;
default:
F_45 ( V_123 -> V_30 , L_8 , V_130 ) ;
return - V_84 ;
}
F_46 ( V_82 , V_82 -> V_3 - 4 , & V_131 , 1 ) ;
switch ( V_131 ) {
case V_142 :
V_128 |= V_143 ;
break;
case V_121 :
if ( F_39 ( V_82 ) )
V_128 |= V_143 |
V_144 ;
else
V_128 |= V_145 ;
break;
case V_146 :
V_128 |= V_147 ;
break;
case V_148 :
V_128 |= V_149 ;
break;
default:
F_45 ( V_123 -> V_30 , L_9 , V_131 ) ;
return - V_84 ;
}
V_86 = (struct V_85 * ) F_47 ( V_82 ) ;
if ( V_86 -> V_102 [ 2 ] & V_150 )
V_128 |= V_151 ;
* V_126 = sizeof( struct V_87 ) ;
if ( F_39 ( V_82 ) ) {
* V_126 += F_48 ( V_82 ) +
sizeof( struct V_85 ) ;
V_125 -> V_152 = F_49 ( V_82 -> V_3 - * V_126 ,
F_40 ( V_82 ) -> V_153 ) ;
V_125 -> V_154 += ( V_125 -> V_152 - 1 ) * * V_126 ;
V_125 -> V_155 |= V_156 ;
}
V_125 -> V_155 |= V_157 | V_158 ;
V_129 = F_40 ( V_82 ) -> V_153 << V_159 ;
V_127 = F_48 ( V_82 ) +
sizeof( struct V_85 ) ;
V_127 |= ( F_48 ( V_82 ) - 4 )
<< V_160 ;
V_127 |= V_125 -> V_155 & V_161 ;
F_50 ( V_123 , V_127 , V_128 ,
V_162 , V_129 ) ;
return 0 ;
}
static void F_51 ( struct V_12 * V_13 , unsigned int V_163 )
{
struct V_36 * V_37 ;
V_37 = F_15 ( V_13 -> V_37 , V_163 ) ;
if ( V_37 -> V_32 )
F_52 ( V_37 -> V_32 ) ;
V_37 -> V_32 = NULL ;
}
static int F_53 ( struct V_12 * V_13 ,
struct V_164 * V_30 ,
unsigned int V_163 )
{
struct V_36 * V_37 ;
struct V_165 * V_32 ;
char V_166 [ 32 ] ;
snprintf ( V_166 , 32 , L_10 , V_163 ) ;
V_32 = F_54 ( V_166 , V_30 , V_167 ,
V_168 , V_169 ) ;
if ( ! V_32 )
return - V_170 ;
V_37 = F_15 ( V_13 -> V_37 , V_163 ) ;
V_37 -> V_32 = V_32 ;
V_37 -> V_60 = 0 ;
V_37 -> V_63 = 0 ;
return 0 ;
}
void F_55 ( struct V_14 * V_15 )
{
struct V_171 * V_13 = & V_15 -> V_172 [ V_173 ] ;
struct V_35 * V_20 = & V_15 -> V_20 ;
int V_39 , V_174 , V_175 ;
T_2 V_176 ;
if ( ! ( V_15 -> V_10 -> V_177 & V_178 ) )
return;
V_176 = V_179 | V_180 | V_181 ;
if ( V_15 -> V_182 & V_183 ) {
V_176 |= V_184 ;
V_176 |= F_56 ( 0 ) << V_185 ;
}
F_5 ( V_20 , F_57 ( V_186 ) , V_176 ) ;
F_5 ( V_20 , F_58 ( V_186 ) , 0 ) ;
if ( ! ( V_15 -> V_182 & V_187 ) )
return;
for ( V_39 = 0 ; V_39 < V_188 ; V_39 ++ ) {
V_175 = V_13 -> V_189 + ( V_39 % V_13 -> V_190 ) ;
V_175 &= V_191 ;
V_174 = V_15 -> V_192 [ V_175 ] -> V_193 ;
F_5 ( V_20 , F_59 ( V_39 ) , V_174 ) ;
}
F_5 ( V_20 , V_194 , V_195 ) ;
V_176 = V_196 | V_181 ;
if ( V_15 -> V_182 & V_183 ) {
V_176 |= V_184 ;
V_176 |= F_56 ( 0 ) << V_185 ;
}
F_5 ( V_20 , F_57 ( V_197 ) , V_176 ) ;
V_174 = V_15 -> V_192 [ V_13 -> V_189 ] -> V_193 ;
F_5 ( V_20 , F_58 ( V_197 ) ,
V_198 |
( V_174 << V_199 ) ) ;
F_5 ( V_20 , V_73 ,
V_200 |
( V_201 << V_202 ) ) ;
}
void F_60 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = & V_15 -> V_13 ;
int V_163 , V_39 ;
if ( ! V_13 -> V_37 )
return;
for ( V_39 = 0 ; V_39 < V_18 ; V_39 ++ )
F_2 ( V_15 -> V_10 , V_39 ) ;
F_61 (cpu)
F_51 ( V_13 , V_163 ) ;
F_62 ( & V_15 -> V_29 -> V_30 ,
V_13 -> V_64 ,
V_43 ,
V_31 ) ;
F_63 ( V_13 -> V_203 ) ;
V_13 -> V_203 = NULL ;
V_13 -> V_64 = 0 ;
}
int F_64 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = & V_15 -> V_13 ;
struct V_164 * V_30 = & V_15 -> V_29 -> V_30 ;
void * V_204 ;
T_3 V_205 ;
unsigned int V_163 ;
if ( ! V_13 -> V_37 )
return 0 ;
V_204 = F_65 ( V_43 , V_57 ) ;
if ( ! V_204 )
return - V_170 ;
V_205 = F_66 ( V_30 , V_204 , V_43 , V_31 ) ;
if ( F_67 ( V_30 , V_205 ) ) {
F_14 ( V_52 , L_11 ) ;
F_63 ( V_204 ) ;
return - V_170 ;
}
V_13 -> V_203 = V_204 ;
V_13 -> V_64 = V_205 ;
F_61 (cpu) {
int V_4 = F_53 ( V_13 , V_30 , V_163 ) ;
if ( ! V_4 )
continue;
F_14 ( V_52 , L_12 , V_163 ) ;
F_60 ( V_15 ) ;
return - V_170 ;
}
return 0 ;
}
static int F_68 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = & V_15 -> V_13 ;
if ( ! ( V_15 -> V_182 & V_206 ) )
return - V_84 ;
V_13 -> V_37 = F_69 ( struct V_36 ) ;
if ( ! V_13 -> V_37 ) {
F_14 ( V_52 , L_13 ) ;
return - V_170 ;
}
V_15 -> V_10 -> V_207 = V_18 - 1 ;
return 0 ;
}
static void F_70 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = & V_15 -> V_13 ;
V_15 -> V_10 -> V_207 = 0 ;
if ( ! V_13 -> V_37 )
return;
F_71 ( V_13 -> V_37 ) ;
V_13 -> V_37 = NULL ;
}
int F_72 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = F_3 ( V_10 ) ;
struct V_12 * V_13 = & V_15 -> V_13 ;
F_73 ( & V_13 -> V_208 ) ;
if ( ! ( V_15 -> V_182 & V_206 ) )
return - V_84 ;
if ( V_15 -> V_182 & V_187 )
return - V_84 ;
F_74 ( V_52 , L_14 ) ;
if ( V_15 -> V_182 & V_183 )
F_12 ( V_209 , L_15 ) ;
if ( F_75 ( V_10 ) )
V_10 -> V_210 -> V_211 ( V_10 ) ;
F_68 ( V_15 ) ;
V_15 -> V_182 |= V_187 ;
V_10 -> V_177 |= V_212 ;
F_76 ( V_10 ) ;
F_77 ( V_15 ) ;
F_78 ( V_15 ) ;
if ( F_75 ( V_10 ) )
V_10 -> V_210 -> V_213 ( V_10 ) ;
return 0 ;
}
int F_79 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = F_3 ( V_10 ) ;
if ( ! F_80 ( & V_15 -> V_13 . V_208 ) )
return - V_84 ;
if ( ! ( V_15 -> V_182 & V_187 ) )
return - V_84 ;
F_74 ( V_52 , L_16 ) ;
if ( F_75 ( V_10 ) )
V_10 -> V_210 -> V_211 ( V_10 ) ;
F_70 ( V_15 ) ;
V_15 -> V_182 &= ~ V_187 ;
V_10 -> V_177 &= ~ V_212 ;
F_76 ( V_10 ) ;
F_77 ( V_15 ) ;
F_78 ( V_15 ) ;
if ( F_75 ( V_10 ) )
V_10 -> V_210 -> V_213 ( V_10 ) ;
return 0 ;
}
int F_81 ( struct V_9 * V_10 , V_62 * V_214 , int type )
{
int V_83 = - V_84 ;
T_1 V_215 = 0xffff ;
struct V_14 * V_15 = F_3 ( V_10 ) ;
struct V_216 * V_217 = & V_15 -> V_20 . V_217 ;
switch ( type ) {
case V_218 :
V_215 = V_217 -> V_219 ;
break;
case V_220 :
V_215 = V_217 -> V_221 ;
break;
default:
break;
}
if ( ( V_215 != 0xffff ) &&
F_82 ( V_217 -> V_222 ) ) {
* V_214 = ( ( V_62 ) V_215 << 48 ) |
( ( V_62 ) V_217 -> V_222 [ 0 ] << 40 ) |
( ( V_62 ) V_217 -> V_222 [ 1 ] << 32 ) |
( ( V_62 ) V_217 -> V_222 [ 2 ] << 24 ) |
( ( V_62 ) V_217 -> V_222 [ 3 ] << 16 ) |
( ( V_62 ) V_217 -> V_222 [ 4 ] << 8 ) |
( ( V_62 ) V_217 -> V_222 [ 5 ] ) ;
V_83 = 0 ;
}
return V_83 ;
}
int F_83 ( struct V_9 * V_10 ,
struct V_223 * V_224 )
{
struct V_14 * V_15 = F_3 ( V_10 ) ;
struct V_35 * V_20 = & V_15 -> V_20 ;
int V_39 , V_225 ;
T_5 V_226 [ 8 ] ;
if ( ! V_224 )
return - V_84 ;
if ( V_20 -> V_217 . type != V_227 &&
V_20 -> V_217 . type != V_228 )
return - V_84 ;
snprintf ( V_224 -> V_229 , sizeof( V_224 -> V_229 ) ,
L_17 ) ;
V_225 = F_84 ( V_15 -> V_29 , V_230 ) ;
if ( V_225 ) {
V_225 += 4 ;
for ( V_39 = 0 ; V_39 < 8 ; V_39 ++ )
F_85 ( V_15 -> V_29 , V_225 + V_39 , & V_226 [ V_39 ] ) ;
snprintf ( V_224 -> V_231 , sizeof( V_224 -> V_231 ) ,
L_18 ,
V_226 [ 7 ] , V_226 [ 6 ] , V_226 [ 5 ] , V_226 [ 4 ] ,
V_226 [ 3 ] , V_226 [ 2 ] , V_226 [ 1 ] , V_226 [ 0 ] ) ;
} else
snprintf ( V_224 -> V_231 , sizeof( V_224 -> V_231 ) ,
L_19 ) ;
snprintf ( V_224 -> V_232 ,
sizeof( V_224 -> V_232 ) ,
L_20 , V_20 -> V_233 ) ;
snprintf ( V_224 -> V_234 ,
sizeof( V_224 -> V_234 ) ,
L_21 ,
V_235 ,
V_236 ) ;
snprintf ( V_224 -> V_237 ,
sizeof( V_224 -> V_237 ) ,
L_22 ,
( V_15 -> V_238 << 16 ) |
V_15 -> V_239 ) ;
if ( V_20 -> V_217 . type == V_227 ) {
snprintf ( V_224 -> V_240 ,
sizeof( V_224 -> V_240 ) ,
L_23 ) ;
} else {
snprintf ( V_224 -> V_240 ,
sizeof( V_224 -> V_240 ) ,
L_24 ) ;
}
snprintf ( V_224 -> V_241 ,
sizeof( V_224 -> V_241 ) ,
L_25 ,
V_242 ) ;
return 0 ;
}
T_5 F_86 ( struct V_14 * V_15 )
{
#ifdef F_87
return F_88 ( V_15 -> V_10 , V_15 -> V_13 . V_243 ) ;
#else
return 0 ;
#endif
}
