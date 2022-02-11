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
int V_3 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
T_2 V_16 ;
if ( ! V_10 )
return 0 ;
if ( V_11 >= V_17 )
return 0 ;
V_15 = F_3 ( V_10 ) ;
V_13 = & V_15 -> V_13 ;
V_2 = & V_13 -> V_2 [ V_11 ] ;
if ( ! V_2 -> V_5 )
return 0 ;
V_3 = V_2 -> V_3 ;
if ( V_2 -> V_4 ) {
F_4 ( & V_13 -> V_18 ) ;
F_5 ( & V_15 -> V_19 , V_20 , 0 ) ;
F_5 ( & V_15 -> V_19 , V_21 ,
( V_11 | V_22 ) ) ;
F_5 ( & V_15 -> V_19 , V_23 , 0 ) ;
F_5 ( & V_15 -> V_19 , V_24 ,
( V_11 | V_25 ) ) ;
F_5 ( & V_15 -> V_19 , V_24 ,
( V_11 | V_26 ) ) ;
V_16 = F_6 ( & V_15 -> V_19 , V_23 ) ;
F_7 ( & V_13 -> V_18 ) ;
if ( V_16 & V_27 )
F_8 ( 100 ) ;
}
if ( V_2 -> V_7 )
F_9 ( & V_15 -> V_28 -> V_29 , V_2 -> V_7 , V_2 -> V_8 ,
V_30 ) ;
if ( V_2 -> V_31 ) {
F_10 ( V_2 -> V_31 , V_2 -> V_5 , V_2 -> V_6 ) ;
V_2 -> V_31 = NULL ;
}
F_1 ( V_2 ) ;
return V_3 ;
}
static int F_11 ( struct V_9 * V_10 , T_1 V_11 ,
struct V_32 * V_7 , unsigned int V_8 ,
int V_33 )
{
struct V_14 * V_15 ;
struct V_34 * V_19 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
struct V_35 * V_36 ;
struct V_32 * V_37 ;
unsigned int V_38 , V_39 , V_40 ;
unsigned int V_3 ;
static const unsigned int V_41 = V_42 ;
unsigned int V_43 = 0 ;
unsigned int V_44 ;
unsigned int V_45 = 0 ;
unsigned int V_46 = 0 ;
T_2 V_16 , V_47 , V_48 , V_49 ;
T_3 V_50 = 0 ;
if ( ! V_10 || ! V_7 )
return 0 ;
V_15 = F_3 ( V_10 ) ;
if ( V_11 >= V_17 ) {
F_12 ( V_51 , L_1 , V_11 ) ;
return 0 ;
}
if ( F_13 ( V_52 , & V_15 -> V_53 ) ||
F_13 ( V_54 , & V_15 -> V_53 ) )
return 0 ;
V_13 = & V_15 -> V_13 ;
V_2 = & V_13 -> V_2 [ V_11 ] ;
if ( V_2 -> V_7 ) {
F_14 ( V_51 , L_2 ,
V_11 , V_2 -> V_7 , V_2 -> V_8 ) ;
return 0 ;
}
F_1 ( V_2 ) ;
if ( ! V_13 -> V_36 ) {
F_12 ( V_51 , L_3 ) ;
return 0 ;
}
V_36 = F_15 ( V_13 -> V_36 , F_16 () ) ;
if ( ! V_36 -> V_31 ) {
F_12 ( V_51 , L_4 , V_11 ) ;
goto V_55;
}
V_40 = F_17 ( & V_15 -> V_28 -> V_29 , V_7 , V_8 , V_30 ) ;
if ( V_40 == 0 ) {
F_14 ( V_51 , L_5 , V_11 ) ;
goto V_55;
}
V_2 -> V_5 = F_18 ( V_36 -> V_31 , V_56 , & V_2 -> V_6 ) ;
if ( ! V_2 -> V_5 ) {
F_14 ( V_51 , L_6 ) ;
goto V_57;
}
V_2 -> V_31 = V_36 -> V_31 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_8 = V_8 ;
V_39 = 0 ;
F_19 (sgl, sg, dmacount, i) {
V_50 = F_20 ( V_37 ) ;
V_3 = F_21 ( V_37 ) ;
while ( V_3 ) {
if ( V_39 >= V_58 ) {
V_36 -> V_59 ++ ;
goto V_60;
}
V_45 = V_50 & ( ( T_3 ) V_41 - 1 ) ;
V_46 = F_22 ( ( V_41 - V_45 ) , V_3 ) ;
if ( ( V_39 != 0 ) && ( V_45 ) )
goto V_60;
if ( ( ( V_38 != ( V_40 - 1 ) ) || ( V_46 != V_3 ) )
&& ( ( V_46 + V_45 ) != V_41 ) )
goto V_60;
V_2 -> V_5 [ V_39 ] = ( V_61 ) ( V_50 - V_45 ) ;
if ( V_39 == 0 )
V_43 = V_45 ;
V_3 -= V_46 ;
V_50 += V_46 ;
V_39 ++ ;
}
}
V_44 = V_45 + V_46 ;
if ( V_44 == V_41 ) {
if ( V_39 >= V_58 ) {
V_36 -> V_62 ++ ;
goto V_60;
}
V_2 -> V_5 [ V_39 ] = ( V_61 ) ( V_13 -> V_63 ) ;
V_39 ++ ;
V_44 = 1 ;
}
F_23 () ;
V_16 = ( V_64 << V_65 ) ;
V_16 |= ( ( V_39 & 0xff ) << V_66 ) ;
V_16 |= ( V_43 << V_67 ) ;
if ( V_33 )
V_16 |= ( V_68 ) ;
V_16 |= ( V_27 ) ;
V_47 = V_11 ;
V_47 |= V_25 ;
V_47 |= ( V_44 << V_69 ) ;
V_48 = V_11 ;
V_48 |= V_22 ;
V_19 = & V_15 -> V_19 ;
F_4 ( & V_13 -> V_18 ) ;
if ( V_33 && ! F_13 ( V_70 , & V_13 -> V_71 ) ) {
F_24 ( V_70 , & V_13 -> V_71 ) ;
V_49 = F_6 ( V_19 , V_72 ) ;
V_49 |= V_73 ;
F_5 ( V_19 , V_72 , V_49 ) ;
}
F_5 ( V_19 , V_74 , V_2 -> V_6 & F_25 ( 32 ) ) ;
F_5 ( V_19 , V_75 , ( V_61 ) V_2 -> V_6 >> 32 ) ;
F_5 ( V_19 , V_23 , V_16 ) ;
F_5 ( V_19 , V_24 , V_47 ) ;
F_5 ( V_19 , V_76 , 0 ) ;
F_5 ( V_19 , V_20 , V_77 ) ;
F_5 ( V_19 , V_21 , V_48 ) ;
F_7 ( & V_13 -> V_18 ) ;
return 1 ;
V_60:
F_10 ( V_2 -> V_31 , V_2 -> V_5 , V_2 -> V_6 ) ;
F_1 ( V_2 ) ;
V_57:
F_9 ( & V_15 -> V_28 -> V_29 , V_7 , V_8 , V_30 ) ;
V_55:
F_23 () ;
return 0 ;
}
int F_26 ( struct V_9 * V_10 , T_1 V_11 ,
struct V_32 * V_7 , unsigned int V_8 )
{
return F_11 ( V_10 , V_11 , V_7 , V_8 , 0 ) ;
}
int F_27 ( struct V_9 * V_10 , T_1 V_11 ,
struct V_32 * V_7 , unsigned int V_8 )
{
return F_11 ( V_10 , V_11 , V_7 , V_8 , 1 ) ;
}
int V_1 ( struct V_14 * V_15 ,
union V_78 * V_79 ,
struct V_80 * V_81 )
{
int V_82 = - V_83 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
struct V_84 * V_85 ;
struct V_86 * V_87 ;
T_4 V_88 = F_28 ( V_79 , V_89 ) ;
T_4 V_90 ;
T_2 V_91 ;
T_1 V_11 ;
if ( V_88 == F_29 ( V_92 ) )
V_81 -> V_93 = V_94 ;
else
V_81 -> V_93 = V_95 ;
if ( F_30 ( V_81 ) -> V_96 == F_31 ( V_97 ) )
V_85 = (struct V_84 * ) ( V_81 -> V_98 +
sizeof( struct V_99 ) + sizeof( struct V_100 ) ) ;
else
V_85 = (struct V_84 * ) ( V_81 -> V_98 +
sizeof( struct V_100 ) ) ;
V_91 = F_32 ( V_85 -> V_101 ) ;
if ( V_91 & V_102 )
V_11 = F_33 ( V_85 -> V_103 ) ;
else
V_11 = F_33 ( V_85 -> V_104 ) ;
if ( V_11 >= V_17 )
return - V_83 ;
V_13 = & V_15 -> V_13 ;
V_2 = & V_13 -> V_2 [ V_11 ] ;
if ( ! V_2 -> V_5 )
return - V_83 ;
V_90 = F_28 ( V_79 , V_105 |
V_89 ) ;
if ( V_90 )
return - V_83 ;
switch ( F_28 ( V_79 , V_106 ) ) {
case F_29 ( V_107 ) :
V_2 -> V_3 = F_34 ( V_79 -> V_108 . V_109 . V_110 . V_111 ) ;
V_82 = 0 ;
break;
case F_29 ( V_112 ) :
F_9 ( & V_15 -> V_28 -> V_29 , V_2 -> V_7 ,
V_2 -> V_8 , V_30 ) ;
V_2 -> V_4 = V_90 ;
V_2 -> V_7 = NULL ;
V_2 -> V_8 = 0 ;
case F_29 ( V_113 ) :
V_2 -> V_3 = F_34 ( V_79 -> V_108 . V_109 . V_110 . V_111 ) ;
if ( V_2 -> V_3 )
V_82 = V_2 -> V_3 ;
break;
case F_29 ( V_114 ) :
default:
break;
}
if ( ( V_85 -> V_115 == V_116 ) &&
( V_91 & V_117 ) ) {
F_35 ( V_81 ) ;
V_87 = (struct V_86 * ) F_36 ( V_81 , sizeof( * V_87 ) ) ;
V_87 -> V_118 = V_119 ;
}
return V_82 ;
}
int F_37 ( struct V_120 * V_121 ,
struct V_122 * V_123 ,
T_5 * V_124 )
{
struct V_80 * V_81 = V_123 -> V_81 ;
struct V_84 * V_85 ;
T_2 V_125 ;
T_2 V_126 = 0 ;
T_2 V_127 ;
T_5 V_128 , V_129 ;
if ( F_38 ( V_81 ) && ( F_39 ( V_81 ) -> V_130 != V_131 ) ) {
F_40 ( V_121 -> V_29 , L_7 ,
F_39 ( V_81 ) -> V_130 ) ;
return - V_83 ;
}
F_41 ( V_81 , V_81 -> V_132 ) ;
F_42 ( V_81 , V_81 -> V_132 +
sizeof( struct V_100 ) ) ;
V_128 = ( (struct V_100 * ) F_43 ( V_81 ) ) -> V_133 ;
switch ( V_128 ) {
case V_134 :
V_126 = V_135 ;
break;
case V_136 :
V_126 = V_137 |
V_135 ;
break;
case V_138 :
break;
case V_139 :
V_126 = V_137 ;
break;
default:
F_44 ( V_121 -> V_29 , L_8 , V_128 ) ;
return - V_83 ;
}
F_45 ( V_81 , V_81 -> V_3 - 4 , & V_129 , 1 ) ;
switch ( V_129 ) {
case V_140 :
V_126 |= V_141 ;
break;
case V_119 :
if ( F_38 ( V_81 ) )
V_126 |= V_141 |
V_142 ;
else
V_126 |= V_143 ;
break;
case V_144 :
V_126 |= V_145 ;
break;
case V_146 :
V_126 |= V_147 ;
break;
default:
F_44 ( V_121 -> V_29 , L_9 , V_129 ) ;
return - V_83 ;
}
V_85 = (struct V_84 * ) F_46 ( V_81 ) ;
if ( V_85 -> V_101 [ 2 ] & V_148 )
V_126 |= V_149 ;
* V_124 = sizeof( struct V_86 ) ;
if ( F_38 ( V_81 ) ) {
* V_124 += F_47 ( V_81 ) +
sizeof( struct V_84 ) ;
V_123 -> V_150 = F_48 ( V_81 -> V_3 - * V_124 ,
F_39 ( V_81 ) -> V_151 ) ;
V_123 -> V_152 += ( V_123 -> V_150 - 1 ) * * V_124 ;
V_123 -> V_153 |= V_154 ;
}
V_123 -> V_153 |= V_155 | V_156 ;
V_127 = F_39 ( V_81 ) -> V_151 << V_157 ;
V_125 = F_47 ( V_81 ) +
sizeof( struct V_84 ) ;
V_125 |= ( F_47 ( V_81 ) - 4 )
<< V_158 ;
V_125 |= V_123 -> V_153 & V_159 ;
F_49 ( V_121 , V_125 , V_126 ,
V_160 , V_127 ) ;
return 0 ;
}
static void F_50 ( struct V_12 * V_13 , unsigned int V_161 )
{
struct V_35 * V_36 ;
V_36 = F_15 ( V_13 -> V_36 , V_161 ) ;
if ( V_36 -> V_31 )
F_51 ( V_36 -> V_31 ) ;
V_36 -> V_31 = NULL ;
}
static int F_52 ( struct V_12 * V_13 ,
struct V_162 * V_29 ,
unsigned int V_161 )
{
struct V_35 * V_36 ;
struct V_163 * V_31 ;
char V_164 [ 32 ] ;
snprintf ( V_164 , 32 , L_10 , V_161 ) ;
V_31 = F_53 ( V_164 , V_29 , V_165 ,
V_166 , V_167 ) ;
if ( ! V_31 )
return - V_168 ;
V_36 = F_15 ( V_13 -> V_36 , V_161 ) ;
V_36 -> V_31 = V_31 ;
V_36 -> V_59 = 0 ;
V_36 -> V_62 = 0 ;
return 0 ;
}
void F_54 ( struct V_14 * V_15 )
{
struct V_169 * V_13 = & V_15 -> V_170 [ V_171 ] ;
struct V_34 * V_19 = & V_15 -> V_19 ;
int V_38 , V_172 , V_173 ;
T_2 V_174 ;
if ( ! ( V_15 -> V_10 -> V_175 & V_176 ) )
return;
V_174 = V_177 | V_178 | V_179 ;
if ( V_15 -> V_180 & V_181 ) {
V_174 |= V_182 ;
V_174 |= F_55 ( 0 ) << V_183 ;
}
F_5 ( V_19 , F_56 ( V_184 ) , V_174 ) ;
F_5 ( V_19 , F_57 ( V_184 ) , 0 ) ;
if ( ! ( V_15 -> V_180 & V_185 ) )
return;
for ( V_38 = 0 ; V_38 < V_186 ; V_38 ++ ) {
V_173 = V_13 -> V_187 + ( V_38 % V_13 -> V_188 ) ;
V_173 &= V_189 ;
V_172 = V_15 -> V_190 [ V_173 ] -> V_191 ;
F_5 ( V_19 , F_58 ( V_38 ) , V_172 ) ;
}
F_5 ( V_19 , V_192 , V_193 ) ;
V_174 = V_194 | V_179 ;
if ( V_15 -> V_180 & V_181 ) {
V_174 |= V_182 ;
V_174 |= F_55 ( 0 ) << V_183 ;
}
F_5 ( V_19 , F_56 ( V_195 ) , V_174 ) ;
V_172 = V_15 -> V_190 [ V_13 -> V_187 ] -> V_191 ;
F_5 ( V_19 , F_57 ( V_195 ) ,
V_196 |
( V_172 << V_197 ) ) ;
F_5 ( V_19 , V_72 ,
V_198 |
( V_199 << V_200 ) ) ;
}
void F_59 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = & V_15 -> V_13 ;
int V_161 , V_38 ;
if ( ! V_13 -> V_36 )
return;
for ( V_38 = 0 ; V_38 < V_17 ; V_38 ++ )
F_2 ( V_15 -> V_10 , V_38 ) ;
F_60 (cpu)
F_50 ( V_13 , V_161 ) ;
F_61 ( & V_15 -> V_28 -> V_29 ,
V_13 -> V_63 ,
V_42 ,
V_30 ) ;
F_62 ( V_13 -> V_201 ) ;
V_13 -> V_201 = NULL ;
V_13 -> V_63 = 0 ;
}
int F_63 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = & V_15 -> V_13 ;
struct V_162 * V_29 = & V_15 -> V_28 -> V_29 ;
void * V_202 ;
T_3 V_203 ;
unsigned int V_161 ;
if ( ! V_13 -> V_36 )
return 0 ;
V_202 = F_64 ( V_42 , V_56 ) ;
if ( ! V_202 )
return - V_168 ;
V_203 = F_65 ( V_29 , V_202 , V_42 , V_30 ) ;
if ( F_66 ( V_29 , V_203 ) ) {
F_14 ( V_51 , L_11 ) ;
F_62 ( V_202 ) ;
return - V_168 ;
}
V_13 -> V_201 = V_202 ;
V_13 -> V_63 = V_203 ;
F_60 (cpu) {
int V_4 = F_52 ( V_13 , V_29 , V_161 ) ;
if ( ! V_4 )
continue;
F_14 ( V_51 , L_12 , V_161 ) ;
F_59 ( V_15 ) ;
return - V_168 ;
}
return 0 ;
}
static int F_67 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = & V_15 -> V_13 ;
if ( ! ( V_15 -> V_180 & V_204 ) )
return - V_83 ;
V_13 -> V_36 = F_68 ( struct V_35 ) ;
if ( ! V_13 -> V_36 ) {
F_14 ( V_51 , L_13 ) ;
return - V_168 ;
}
V_15 -> V_10 -> V_205 = V_17 - 1 ;
return 0 ;
}
static void F_69 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = & V_15 -> V_13 ;
V_15 -> V_10 -> V_205 = 0 ;
if ( ! V_13 -> V_36 )
return;
F_70 ( V_13 -> V_36 ) ;
V_13 -> V_36 = NULL ;
}
int F_71 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = F_3 ( V_10 ) ;
struct V_12 * V_13 = & V_15 -> V_13 ;
F_72 ( & V_13 -> V_206 ) ;
if ( ! ( V_15 -> V_180 & V_204 ) )
return - V_83 ;
if ( V_15 -> V_180 & V_185 )
return - V_83 ;
F_73 ( V_51 , L_14 ) ;
if ( V_15 -> V_180 & V_181 )
F_12 ( V_207 , L_15 ) ;
if ( F_74 ( V_10 ) )
V_10 -> V_208 -> V_209 ( V_10 ) ;
F_67 ( V_15 ) ;
V_15 -> V_180 |= V_185 ;
V_10 -> V_175 |= V_210 ;
F_75 ( V_10 ) ;
F_76 ( V_15 ) ;
F_77 ( V_15 ) ;
if ( F_74 ( V_10 ) )
V_10 -> V_208 -> V_211 ( V_10 ) ;
return 0 ;
}
int F_78 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = F_3 ( V_10 ) ;
if ( ! F_79 ( & V_15 -> V_13 . V_206 ) )
return - V_83 ;
if ( ! ( V_15 -> V_180 & V_185 ) )
return - V_83 ;
F_73 ( V_51 , L_16 ) ;
if ( F_74 ( V_10 ) )
V_10 -> V_208 -> V_209 ( V_10 ) ;
F_69 ( V_15 ) ;
V_15 -> V_180 &= ~ V_185 ;
V_10 -> V_175 &= ~ V_210 ;
F_75 ( V_10 ) ;
F_76 ( V_15 ) ;
F_77 ( V_15 ) ;
if ( F_74 ( V_10 ) )
V_10 -> V_208 -> V_211 ( V_10 ) ;
return 0 ;
}
int F_80 ( struct V_9 * V_10 , V_61 * V_212 , int type )
{
T_1 V_213 = 0xffff ;
struct V_14 * V_15 = F_3 ( V_10 ) ;
struct V_214 * V_215 = & V_15 -> V_19 . V_215 ;
switch ( type ) {
case V_216 :
V_213 = V_215 -> V_217 ;
break;
case V_218 :
V_213 = V_215 -> V_219 ;
break;
default:
break;
}
if ( ( V_213 != 0xffff ) &&
F_81 ( V_215 -> V_220 ) ) {
* V_212 = ( ( V_61 ) V_213 << 48 ) |
( ( V_61 ) V_215 -> V_220 [ 0 ] << 40 ) |
( ( V_61 ) V_215 -> V_220 [ 1 ] << 32 ) |
( ( V_61 ) V_215 -> V_220 [ 2 ] << 24 ) |
( ( V_61 ) V_215 -> V_220 [ 3 ] << 16 ) |
( ( V_61 ) V_215 -> V_220 [ 4 ] << 8 ) |
( ( V_61 ) V_215 -> V_220 [ 5 ] ) ;
return 0 ;
}
return - V_83 ;
}
int F_82 ( struct V_9 * V_10 ,
struct V_221 * V_222 )
{
struct V_14 * V_15 = F_3 ( V_10 ) ;
struct V_34 * V_19 = & V_15 -> V_19 ;
int V_38 , V_223 ;
T_5 V_224 [ 8 ] ;
if ( ! V_222 )
return - V_83 ;
if ( V_19 -> V_215 . type != V_225 &&
V_19 -> V_215 . type != V_226 )
return - V_83 ;
snprintf ( V_222 -> V_227 , sizeof( V_222 -> V_227 ) ,
L_17 ) ;
V_223 = F_83 ( V_15 -> V_28 , V_228 ) ;
if ( V_223 ) {
V_223 += 4 ;
for ( V_38 = 0 ; V_38 < 8 ; V_38 ++ )
F_84 ( V_15 -> V_28 , V_223 + V_38 , & V_224 [ V_38 ] ) ;
snprintf ( V_222 -> V_229 , sizeof( V_222 -> V_229 ) ,
L_18 ,
V_224 [ 7 ] , V_224 [ 6 ] , V_224 [ 5 ] , V_224 [ 4 ] ,
V_224 [ 3 ] , V_224 [ 2 ] , V_224 [ 1 ] , V_224 [ 0 ] ) ;
} else
snprintf ( V_222 -> V_229 , sizeof( V_222 -> V_229 ) ,
L_19 ) ;
snprintf ( V_222 -> V_230 ,
sizeof( V_222 -> V_230 ) ,
L_20 , V_19 -> V_231 ) ;
snprintf ( V_222 -> V_232 ,
sizeof( V_222 -> V_232 ) ,
L_21 ,
V_233 ,
V_234 ) ;
snprintf ( V_222 -> V_235 ,
sizeof( V_222 -> V_235 ) ,
L_22 ,
( V_15 -> V_236 << 16 ) |
V_15 -> V_237 ) ;
if ( V_19 -> V_215 . type == V_225 ) {
snprintf ( V_222 -> V_238 ,
sizeof( V_222 -> V_238 ) ,
L_23 ) ;
} else {
snprintf ( V_222 -> V_238 ,
sizeof( V_222 -> V_238 ) ,
L_24 ) ;
}
snprintf ( V_222 -> V_239 ,
sizeof( V_222 -> V_239 ) ,
L_25 ,
V_240 ) ;
return 0 ;
}
T_5 F_85 ( struct V_14 * V_15 )
{
#ifdef F_86
return F_87 ( V_15 -> V_10 , V_15 -> V_13 . V_241 ) ;
#else
return 0 ;
#endif
}
