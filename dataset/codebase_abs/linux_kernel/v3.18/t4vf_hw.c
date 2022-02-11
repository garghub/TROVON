int F_1 ( struct V_1 * V_1 )
{
const T_1 V_2 = V_3 + V_4 ;
const T_1 V_5 = 0xffffffff ;
const T_1 V_6 = 0xeeeeeeee ;
T_1 V_7 ;
V_7 = F_2 ( V_1 , V_2 ) ;
if ( V_7 != V_5 && V_7 != V_6 )
return 0 ;
F_3 ( 500 ) ;
V_7 = F_2 ( V_1 , V_2 ) ;
if ( V_7 != V_5 && V_7 != V_6 )
return 0 ;
else
return - V_8 ;
}
static void F_4 ( struct V_1 * V_1 , T_2 * V_9 , int V_10 ,
T_1 V_11 )
{
for ( ; V_10 ; V_10 -= 8 , V_11 += 8 )
* V_9 ++ = F_5 ( F_6 ( V_1 , V_11 ) ) ;
}
static void F_7 ( struct V_1 * V_1 , const char * V_12 , T_1 V_11 )
{
F_8 ( V_1 -> V_13 ,
L_1 , V_12 ,
( unsigned long long ) F_6 ( V_1 , V_11 + 0 ) ,
( unsigned long long ) F_6 ( V_1 , V_11 + 8 ) ,
( unsigned long long ) F_6 ( V_1 , V_11 + 16 ) ,
( unsigned long long ) F_6 ( V_1 , V_11 + 24 ) ,
( unsigned long long ) F_6 ( V_1 , V_11 + 32 ) ,
( unsigned long long ) F_6 ( V_1 , V_11 + 40 ) ,
( unsigned long long ) F_6 ( V_1 , V_11 + 48 ) ,
( unsigned long long ) F_6 ( V_1 , V_11 + 56 ) ) ;
}
int F_9 ( struct V_1 * V_1 , const void * V_14 , int V_10 ,
void * V_9 , bool V_15 )
{
static const int V_16 [] = {
1 , 1 , 3 , 5 , 10 , 10 , 20 , 50 , 100
} ;
T_1 V_17 ;
int V_18 , V_19 , V_20 ;
const T_2 * V_21 ;
T_1 V_11 = V_22 ;
T_1 V_23 = V_24 + V_25 ;
if ( ( V_10 % 16 ) != 0 ||
V_10 > V_26 * 4 )
return - V_27 ;
V_17 = F_10 ( F_2 ( V_1 , V_23 ) ) ;
for ( V_18 = 0 ; V_17 == V_28 && V_18 < 3 ; V_18 ++ )
V_17 = F_10 ( F_2 ( V_1 , V_23 ) ) ;
if ( V_17 != V_29 )
return V_17 == V_30 ? - V_31 : - V_32 ;
for ( V_18 = 0 , V_21 = V_14 ; V_18 < V_10 ; V_18 += 8 )
F_11 ( V_1 , V_11 + V_18 , F_12 ( * V_21 ++ ) ) ;
F_2 ( V_1 , V_11 ) ;
F_13 ( V_1 , V_23 ,
V_33 | F_14 ( V_30 ) ) ;
F_2 ( V_1 , V_23 ) ;
V_20 = 0 ;
V_19 = V_16 [ 0 ] ;
for ( V_18 = 0 ; V_18 < V_34 ; V_18 += V_19 ) {
if ( V_15 ) {
V_19 = V_16 [ V_20 ] ;
if ( V_20 < F_15 ( V_16 ) - 1 )
V_20 ++ ;
F_3 ( V_19 ) ;
} else
F_16 ( V_19 ) ;
V_17 = F_2 ( V_1 , V_23 ) ;
if ( F_10 ( V_17 ) == V_29 ) {
if ( ( V_17 & V_33 ) == 0 ) {
F_13 ( V_1 , V_23 ,
F_14 ( V_28 ) ) ;
continue;
}
V_17 = F_2 ( V_1 , V_11 ) ;
if ( F_17 ( V_17 ) )
F_7 ( V_1 , L_2 , V_11 ) ;
if ( V_9 ) {
F_18 ( ( F_19 ( * ( const T_1 * ) V_14 )
& V_35 ) == 0 ) ;
F_4 ( V_1 , V_9 , V_10 , V_11 ) ;
F_18 ( ( F_19 ( * ( T_1 * ) V_9 )
& V_35 ) != 0 ) ;
}
F_13 ( V_1 , V_23 ,
F_14 ( V_28 ) ) ;
return - F_17 ( V_17 ) ;
}
}
F_7 ( V_1 , L_3 , V_11 ) ;
return - V_32 ;
}
static int F_20 ( const T_3 * V_36 )
{
T_1 V_37 = ( ( T_1 ) V_36 [ 0 ] << 16 ) | ( ( T_1 ) V_36 [ 1 ] << 8 ) | V_36 [ 2 ] ;
T_1 V_38 = ( ( T_1 ) V_36 [ 3 ] << 16 ) | ( ( T_1 ) V_36 [ 4 ] << 8 ) | V_36 [ 5 ] ;
V_37 ^= V_38 ;
V_37 ^= ( V_37 >> 12 ) ;
V_37 ^= ( V_37 >> 6 ) ;
return V_37 & 0x3f ;
}
static void F_21 ( struct V_39 * V_40 , unsigned int V_41 )
{
V_40 -> V_42 = V_41 ;
V_40 -> V_43 = 0 ;
V_40 -> V_44 = 0 ;
V_40 -> V_45 = V_40 -> V_46 = V_47 | V_48 ;
if ( V_40 -> V_42 & V_49 ) {
V_40 -> V_50 = V_40 -> V_42 ;
V_40 -> V_51 = V_52 ;
V_40 -> V_45 |= V_53 ;
} else {
V_40 -> V_50 = 0 ;
V_40 -> V_51 = V_54 ;
}
}
int F_22 ( struct V_1 * V_1 , int V_55 )
{
struct V_56 * V_57 = F_23 ( V_1 , V_55 ) ;
struct V_58 V_59 , V_60 ;
struct V_61 V_62 , V_63 ;
int V_17 ;
T_1 V_64 ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
V_59 . V_65 = F_24 ( F_25 ( V_66 ) |
V_35 |
V_67 ) ;
V_59 . V_68 = F_24 ( F_26 ( V_59 ) ) ;
V_59 . V_69 = F_27 ( F_28 ( V_57 -> V_70 ) ) ;
V_17 = F_29 ( V_1 , & V_59 , sizeof( V_59 ) , & V_60 ) ;
if ( V_17 )
return V_17 ;
F_30 ( V_57 -> V_71 != F_31 ( V_60 . V_72 ) ) ;
V_57 -> V_73 = F_32 ( F_33 ( V_60 . V_74 ) ) ;
F_34 ( V_1 , V_55 , V_60 . V_75 ) ;
if ( ! ( V_1 -> V_76 . V_77 . V_78 & V_79 ) )
return 0 ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_62 . V_80 = F_24 ( F_25 ( V_81 ) |
V_35 |
V_67 |
F_35 ( V_57 -> V_71 ) ) ;
V_62 . V_82 =
F_24 ( F_36 ( V_83 ) |
F_26 ( V_62 ) ) ;
V_17 = F_29 ( V_1 , & V_62 , sizeof( V_62 ) , & V_63 ) ;
if ( V_17 )
return V_17 ;
V_17 = 0 ;
V_64 = F_33 ( V_63 . V_84 . V_85 . V_86 ) ;
if ( V_64 & V_87 )
V_17 |= V_88 ;
if ( V_64 & V_89 )
V_17 |= V_90 ;
if ( V_64 & V_91 )
V_17 |= V_92 ;
if ( V_64 & V_93 )
V_17 |= V_94 ;
if ( V_64 & V_95 )
V_17 |= V_49 ;
F_21 ( & V_57 -> V_96 , V_17 ) ;
return 0 ;
}
int F_37 ( struct V_1 * V_1 )
{
struct V_97 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_98 = F_24 ( F_25 ( V_99 ) |
V_100 ) ;
V_14 . V_101 = F_24 ( F_26 ( V_14 ) ) ;
return F_29 ( V_1 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
static int F_38 ( struct V_1 * V_1 , unsigned int V_102 ,
const T_1 * V_76 , T_1 * V_103 )
{
int V_18 , V_104 ;
struct V_105 V_14 , V_9 ;
struct V_106 * V_21 ;
T_4 V_107 ;
if ( V_102 > 7 )
return - V_27 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_65 = F_24 ( F_25 ( V_108 ) |
V_35 |
V_67 ) ;
V_107 = F_39 ( F_40 ( struct V_105 ,
V_109 [ V_102 ] . V_110 ) , 16 ) ;
V_14 . V_101 = F_24 ( F_41 ( V_107 ) ) ;
for ( V_18 = 0 , V_21 = & V_14 . V_109 [ 0 ] ; V_18 < V_102 ; V_18 ++ , V_21 ++ )
V_21 -> V_110 = F_42 ( * V_76 ++ ) ;
V_104 = F_29 ( V_1 , & V_14 , sizeof( V_14 ) , & V_9 ) ;
if ( V_104 == 0 )
for ( V_18 = 0 , V_21 = & V_9 . V_109 [ 0 ] ; V_18 < V_102 ; V_18 ++ , V_21 ++ )
* V_103 ++ = F_19 ( V_21 -> V_7 ) ;
return V_104 ;
}
int F_43 ( struct V_1 * V_1 , unsigned int V_102 ,
const T_1 * V_76 , const T_1 * V_103 )
{
int V_18 ;
struct V_105 V_14 ;
struct V_106 * V_21 ;
T_4 V_107 ;
if ( V_102 > 7 )
return - V_27 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_65 = F_24 ( F_25 ( V_108 ) |
V_35 |
V_100 ) ;
V_107 = F_39 ( F_40 ( struct V_105 ,
V_109 [ V_102 ] ) , 16 ) ;
V_14 . V_101 = F_24 ( F_41 ( V_107 ) ) ;
for ( V_18 = 0 , V_21 = & V_14 . V_109 [ 0 ] ; V_18 < V_102 ; V_18 ++ , V_21 ++ ) {
V_21 -> V_110 = F_24 ( * V_76 ++ ) ;
V_21 -> V_7 = F_24 ( * V_103 ++ ) ;
}
return F_29 ( V_1 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_44 ( struct V_1 * V_1 )
{
struct V_111 * V_111 = & V_1 -> V_76 . V_112 ;
T_1 V_76 [ 7 ] , V_103 [ 7 ] ;
int V_17 ;
V_76 [ 0 ] = ( F_45 ( V_113 ) |
F_46 ( V_114 ) ) ;
V_76 [ 1 ] = ( F_45 ( V_113 ) |
F_46 ( V_115 ) ) ;
V_76 [ 2 ] = ( F_45 ( V_113 ) |
F_46 ( V_116 ) ) ;
V_76 [ 3 ] = ( F_45 ( V_113 ) |
F_46 ( V_117 ) ) ;
V_76 [ 4 ] = ( F_45 ( V_113 ) |
F_46 ( V_118 ) ) ;
V_76 [ 5 ] = ( F_45 ( V_113 ) |
F_46 ( V_119 ) ) ;
V_76 [ 6 ] = ( F_45 ( V_113 ) |
F_46 ( V_120 ) ) ;
V_17 = F_38 ( V_1 , 7 , V_76 , V_103 ) ;
if ( V_17 )
return V_17 ;
V_111 -> V_121 = V_103 [ 0 ] ;
V_111 -> V_122 = V_103 [ 1 ] ;
V_111 -> V_123 [ 0 ] = V_103 [ 2 ] ;
V_111 -> V_123 [ 1 ] = V_103 [ 3 ] ;
V_111 -> V_124 = V_103 [ 4 ] ;
V_111 -> V_125 = V_103 [ 5 ] ;
V_111 -> V_126 = V_103 [ 6 ] ;
if ( ! F_47 ( V_1 -> V_76 . V_127 ) ) {
V_76 [ 0 ] = ( F_45 ( V_113 ) |
F_46 ( V_128 ) ) ;
V_17 = F_38 ( V_1 , 1 , V_76 , V_103 ) ;
if ( V_17 != V_129 ) {
F_8 ( V_1 -> V_13 ,
L_4
L_5 ) ;
return V_17 ;
}
V_111 -> V_130 = V_103 [ 0 ] ;
}
V_76 [ 0 ] = ( F_45 ( V_113 ) |
F_46 ( V_131 ) ) ;
V_76 [ 1 ] = ( F_45 ( V_113 ) |
F_46 ( V_132 ) ) ;
V_17 = F_38 ( V_1 , 2 , V_76 , V_103 ) ;
if ( V_17 )
return V_17 ;
V_111 -> V_133 = V_103 [ 0 ] ;
V_111 -> V_134 = V_103 [ 1 ] ;
return 0 ;
}
int F_48 ( struct V_1 * V_1 )
{
struct V_135 * V_135 = & V_1 -> V_76 . V_136 ;
T_1 V_76 [ 7 ] , V_103 [ 7 ] ;
int V_17 ;
V_76 [ 0 ] = ( F_45 ( V_137 ) |
F_49 ( V_138 ) ) ;
V_17 = F_38 ( V_1 , 1 , V_76 , V_103 ) ;
if ( V_17 )
return V_17 ;
V_135 -> V_139 = V_103 [ 0 ] ;
return 0 ;
}
int F_50 ( struct V_1 * V_1 )
{
struct V_140 * V_140 = & V_1 -> V_76 . V_141 ;
T_1 V_76 [ 7 ] , V_103 [ 7 ] ;
int V_17 ;
V_76 [ 0 ] = ( F_45 ( V_137 ) |
F_49 ( V_142 ) ) ;
V_76 [ 1 ] = ( F_45 ( V_137 ) |
F_49 ( V_143 ) ) ;
V_17 = F_38 ( V_1 , 2 , V_76 , V_103 ) ;
if ( V_17 )
return V_17 ;
V_140 -> V_144 = V_103 [ 0 ] ;
V_140 -> V_145 = V_103 [ 1 ] ;
return 0 ;
}
int F_51 ( struct V_1 * V_1 )
{
struct V_146 * V_147 = & V_1 -> V_76 . V_147 ;
struct V_148 V_14 , V_9 ;
int V_17 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_98 = F_24 ( F_25 ( V_149 ) |
V_35 |
V_67 ) ;
V_14 . V_101 = F_24 ( F_26 ( V_14 ) ) ;
V_17 = F_29 ( V_1 , & V_14 , sizeof( V_14 ) , & V_9 ) ;
if ( V_17 )
return V_17 ;
V_147 -> V_150 = F_52 (
F_19 ( V_9 . V_84 . V_151 . V_152 ) ) ;
switch ( V_147 -> V_150 ) {
case V_153 : {
T_1 V_64 = F_19 (
V_9 . V_84 . V_154 . V_155 ) ;
V_147 -> V_84 . V_154 . V_156 =
( ( V_64 & V_157 ) != 0 ) ;
V_147 -> V_84 . V_154 . V_158 =
( ( V_64 & V_159 ) != 0 ) ;
V_147 -> V_84 . V_154 . V_160 =
( ( V_64 & V_161 ) != 0 ) ;
V_147 -> V_84 . V_154 . V_162 =
( ( V_64 & V_163 ) != 0 ) ;
V_147 -> V_84 . V_154 . V_164 =
( ( V_64 & V_165 ) != 0 ) ;
V_147 -> V_84 . V_154 . V_166 =
( ( V_64 & V_167 ) != 0 ) ;
V_147 -> V_84 . V_154 . V_168 =
( ( V_64 & V_169 ) != 0 ) ;
V_147 -> V_84 . V_154 . V_170 =
( ( V_64 & V_171 ) != 0 ) ;
V_147 -> V_84 . V_154 . V_172 =
( ( V_64 & V_173 ) != 0 ) ;
if ( ! V_147 -> V_84 . V_154 . V_168 )
return - V_27 ;
break;
}
default:
return - V_27 ;
}
return 0 ;
}
int F_53 ( struct V_1 * V_1 )
{
struct V_174 * V_77 = & V_1 -> V_76 . V_77 ;
struct V_175 V_14 , V_9 ;
int V_17 ;
T_1 V_64 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_65 = F_24 ( F_25 ( V_176 ) |
V_35 |
V_67 ) ;
V_14 . V_101 = F_24 ( F_26 ( V_14 ) ) ;
V_17 = F_29 ( V_1 , & V_14 , sizeof( V_14 ) , & V_9 ) ;
if ( V_17 )
return V_17 ;
V_64 = F_19 ( V_9 . V_177 ) ;
V_77 -> V_178 = F_54 ( V_64 ) ;
V_77 -> V_179 = F_55 ( V_64 ) ;
V_64 = F_19 ( V_9 . V_180 ) ;
V_77 -> V_181 = F_56 ( V_64 ) ;
V_77 -> V_182 = F_57 ( V_64 ) ;
V_64 = F_19 ( V_9 . V_183 ) ;
V_77 -> V_184 = F_58 ( V_64 ) ;
V_77 -> V_185 = F_59 ( V_64 ) ;
V_77 -> V_186 = F_60 ( V_64 ) ;
V_64 = F_19 ( V_9 . V_187 ) ;
V_77 -> V_78 = F_61 ( V_64 ) ;
V_77 -> V_188 = F_62 ( V_64 ) ;
V_77 -> V_189 = F_63 ( V_64 ) ;
return 0 ;
}
int F_64 ( struct V_1 * V_1 , unsigned int V_70 ,
union V_190 * V_191 )
{
struct V_192 V_14 , V_9 ;
int V_17 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_193 = F_24 ( F_25 ( V_194 ) |
V_35 |
V_67 |
F_65 ( V_70 ) ) ;
V_14 . V_101 = F_24 ( F_26 ( V_14 ) ) ;
V_17 = F_29 ( V_1 , & V_14 , sizeof( V_14 ) , & V_9 ) ;
if ( V_17 )
return V_17 ;
switch ( V_1 -> V_76 . V_147 . V_150 ) {
case V_153 : {
T_1 V_64 = F_19 ( V_9 . V_84 . V_154 . V_195 ) ;
V_191 -> V_154 . V_196 =
( ( V_64 & V_197 ) != 0 ) ;
V_191 -> V_154 . V_198 =
( ( V_64 & V_199 ) != 0 ) ;
V_191 -> V_154 . V_200 =
( ( V_64 & V_201 ) != 0 ) ;
V_191 -> V_154 . V_202 =
( ( V_64 & V_203 ) != 0 ) ;
V_191 -> V_154 . V_204 =
( ( V_64 & V_205 ) != 0 ) ;
V_191 -> V_154 . V_206 =
F_66 ( V_64 ) ;
break;
}
default:
return - V_27 ;
}
return 0 ;
}
int F_67 ( struct V_1 * V_1 , unsigned int V_70 ,
union V_190 * V_191 )
{
struct V_192 V_14 , V_9 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_193 = F_24 ( F_25 ( V_194 ) |
V_35 |
V_100 |
F_65 ( V_70 ) ) ;
V_14 . V_101 = F_24 ( F_26 ( V_14 ) ) ;
switch ( V_1 -> V_76 . V_147 . V_150 ) {
case V_153 : {
T_1 V_64 = 0 ;
if ( V_191 -> V_154 . V_196 )
V_64 |= V_197 ;
if ( V_191 -> V_154 . V_198 )
V_64 |= V_199 ;
if ( V_191 -> V_154 . V_200 )
V_64 |= V_201 ;
if ( V_191 -> V_154 . V_202 )
V_64 |= V_203 ;
if ( V_191 -> V_154 . V_204 )
V_64 |= V_205 ;
V_64 |= F_68 (
V_191 -> V_154 . V_206 ) ;
V_14 . V_84 . V_154 . V_195 = F_24 ( V_64 ) ;
break;
}
default:
return - V_27 ;
}
return F_29 ( V_1 , & V_14 , sizeof( V_14 ) , & V_9 ) ;
}
int F_69 ( struct V_1 * V_1 , unsigned int V_70 ,
int V_207 , int V_208 , const T_5 * V_209 , int V_210 )
{
const T_5 * V_211 = V_209 ;
const T_5 * V_212 = V_209 + V_210 ;
struct V_213 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_193 = F_24 ( F_25 ( V_214 ) |
V_35 |
V_100 |
F_70 ( V_70 ) ) ;
V_14 . V_101 = F_24 ( F_26 ( V_14 ) ) ;
while ( V_208 > 0 ) {
T_6 * V_215 = & V_14 . V_216 ;
int V_217 = F_71 ( V_208 , 32 ) ;
int V_104 ;
V_14 . V_218 = F_27 ( V_217 ) ;
V_14 . V_219 = F_27 ( V_207 ) ;
V_207 += V_217 ;
V_208 -= V_217 ;
while ( V_217 > 0 ) {
T_5 V_220 [ 3 ] ;
T_5 * V_221 = V_220 ;
int V_222 = F_71 ( 3 , V_217 ) ;
V_217 -= V_222 ;
V_220 [ 0 ] = V_220 [ 1 ] = V_220 [ 2 ] = 0 ;
while ( V_222 ) {
V_222 -- ;
* V_221 ++ = * V_211 ++ ;
if ( V_211 >= V_212 )
V_211 = V_209 ;
}
* V_215 ++ = F_24 ( F_72 ( V_220 [ 0 ] ) |
F_73 ( V_220 [ 1 ] ) |
F_74 ( V_220 [ 2 ] ) ) ;
}
V_104 = F_29 ( V_1 , & V_14 , sizeof( V_14 ) , NULL ) ;
if ( V_104 )
return V_104 ;
}
return 0 ;
}
int F_75 ( struct V_1 * V_1 , int V_71 )
{
struct V_58 V_14 , V_9 ;
int V_17 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_65 = F_24 ( F_25 ( V_66 ) |
V_35 |
V_100 |
V_223 ) ;
V_14 . V_68 = F_24 ( F_26 ( V_14 ) |
V_224 ) ;
V_14 . V_72 = F_76 ( V_71 ) ;
V_17 = F_29 ( V_1 , & V_14 , sizeof( V_14 ) , & V_9 ) ;
if ( V_17 )
return V_17 ;
return F_77 ( F_33 ( V_9 . V_69 ) ) ;
}
int F_78 ( struct V_1 * V_1 , int V_70 )
{
struct V_58 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_65 = F_24 ( F_25 ( V_66 ) |
V_35 |
V_223 ) ;
V_14 . V_68 = F_24 ( F_26 ( V_14 ) |
V_225 ) ;
V_14 . V_69 = F_27 ( F_28 ( V_70 ) ) ;
return F_29 ( V_1 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_79 ( struct V_1 * V_1 , unsigned int V_70 ,
bool V_226 , bool V_227 )
{
struct V_228 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_193 = F_24 ( F_25 ( V_229 ) |
V_35 |
V_223 |
F_80 ( V_70 ) ) ;
V_14 . V_230 = F_24 ( F_81 ( V_226 ) |
F_82 ( V_227 ) |
F_26 ( V_14 ) ) ;
return F_29 ( V_1 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_83 ( struct V_1 * V_1 , unsigned int V_70 ,
unsigned int V_231 )
{
struct V_228 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_193 = F_24 ( F_25 ( V_229 ) |
V_35 |
V_223 |
F_80 ( V_70 ) ) ;
V_14 . V_230 = F_24 ( V_232 |
F_26 ( V_14 ) ) ;
V_14 . V_233 = F_27 ( V_231 ) ;
return F_29 ( V_1 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_84 ( struct V_1 * V_1 , unsigned int V_70 ,
int V_234 , int V_235 , int V_236 , int V_237 , int V_238 ,
bool V_15 )
{
struct V_239 V_14 ;
if ( V_234 < 0 )
V_234 = V_240 ;
if ( V_235 < 0 )
V_235 = V_241 ;
if ( V_236 < 0 )
V_236 = V_242 ;
if ( V_237 < 0 )
V_237 = V_243 ;
if ( V_238 < 0 )
V_238 = V_244 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_193 = F_24 ( F_25 ( V_245 ) |
V_35 |
V_100 |
F_85 ( V_70 ) ) ;
V_14 . V_101 = F_24 ( F_26 ( V_14 ) ) ;
V_14 . V_246 =
F_24 ( F_86 ( V_234 ) |
F_87 ( V_235 ) |
F_88 ( V_236 ) |
F_89 ( V_237 ) |
F_90 ( V_238 ) ) ;
return F_9 ( V_1 , & V_14 , sizeof( V_14 ) , NULL , V_15 ) ;
}
int F_91 ( struct V_1 * V_1 , unsigned int V_70 , bool free ,
unsigned int V_247 , const T_3 * * V_36 , T_5 * V_248 ,
T_7 * V_249 , bool V_15 )
{
int V_250 , V_104 = 0 ;
unsigned V_251 = 0 ;
unsigned int V_252 = V_247 ;
struct V_253 V_14 , V_9 ;
unsigned int V_254 = F_47 ( V_1 -> V_76 . V_127 ) ?
V_255 :
V_256 ;
if ( V_247 > V_254 )
return - V_27 ;
for ( V_250 = 0 ; V_250 < V_247 ; ) {
unsigned int V_257 = ( V_252 < F_15 ( V_14 . V_84 . V_258 )
? V_252
: F_15 ( V_14 . V_84 . V_258 ) ) ;
T_4 V_107 = F_39 ( F_40 ( struct V_253 ,
V_84 . V_258 [ V_257 ] ) , 16 ) ;
struct V_259 * V_21 ;
int V_18 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_193 = F_24 ( F_25 ( V_260 ) |
V_35 |
V_100 |
( free ? V_223 : 0 ) |
F_92 ( V_70 ) ) ;
V_14 . V_261 =
F_24 ( F_93 ( free ) |
F_41 ( V_107 ) ) ;
for ( V_18 = 0 , V_21 = V_14 . V_84 . V_258 ; V_18 < V_257 ; V_18 ++ , V_21 ++ ) {
V_21 -> V_262 = F_27 (
V_263 |
F_94 ( V_264 ) ) ;
memcpy ( V_21 -> V_265 , V_36 [ V_250 + V_18 ] , sizeof( V_21 -> V_265 ) ) ;
}
V_104 = F_9 ( V_1 , & V_14 , sizeof( V_14 ) , & V_9 ,
V_15 ) ;
if ( V_104 && V_104 != - V_266 )
break;
for ( V_18 = 0 , V_21 = V_9 . V_84 . V_258 ; V_18 < V_257 ; V_18 ++ , V_21 ++ ) {
T_5 V_267 = F_95 (
F_33 ( V_21 -> V_262 ) ) ;
if ( V_248 )
V_248 [ V_250 + V_18 ] =
( V_267 >= V_254
? 0xffff
: V_267 ) ;
if ( V_267 < V_254 )
V_251 ++ ;
else if ( V_249 )
* V_249 |= ( 1ULL << F_20 ( V_36 [ V_250 + V_18 ] ) ) ;
}
free = false ;
V_250 += V_257 ;
V_252 -= V_257 ;
}
if ( V_104 == 0 || V_104 == - V_266 )
V_104 = V_251 ;
return V_104 ;
}
int F_96 ( struct V_1 * V_1 , unsigned int V_70 ,
int V_248 , const T_3 * V_36 , bool V_268 )
{
int V_104 ;
struct V_253 V_14 , V_9 ;
struct V_259 * V_21 = & V_14 . V_84 . V_258 [ 0 ] ;
T_4 V_107 = F_39 ( F_40 ( struct V_253 ,
V_84 . V_258 [ 1 ] ) , 16 ) ;
unsigned int V_254 = F_47 ( V_1 -> V_76 . V_127 ) ?
V_255 :
V_256 ;
if ( V_248 < 0 )
V_248 = V_268 ? V_269 : V_264 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_193 = F_24 ( F_25 ( V_260 ) |
V_35 |
V_100 |
F_92 ( V_70 ) ) ;
V_14 . V_261 = F_24 ( F_41 ( V_107 ) ) ;
V_21 -> V_262 = F_27 ( V_263 |
F_94 ( V_248 ) ) ;
memcpy ( V_21 -> V_265 , V_36 , sizeof( V_21 -> V_265 ) ) ;
V_104 = F_29 ( V_1 , & V_14 , sizeof( V_14 ) , & V_9 ) ;
if ( V_104 == 0 ) {
V_21 = & V_9 . V_84 . V_258 [ 0 ] ;
V_104 = F_95 ( F_33 ( V_21 -> V_262 ) ) ;
if ( V_104 >= V_254 )
V_104 = - V_266 ;
}
return V_104 ;
}
int F_97 ( struct V_1 * V_1 , unsigned int V_70 ,
bool V_270 , T_7 V_271 , bool V_15 )
{
struct V_253 V_14 ;
T_4 V_107 = F_39 ( F_40 ( struct V_253 ,
V_84 . V_258 [ 0 ] ) , 16 ) ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_193 = F_24 ( F_25 ( V_260 ) |
V_35 |
V_100 |
F_80 ( V_70 ) ) ;
V_14 . V_261 = F_24 ( V_272 |
F_98 ( V_270 ) |
F_41 ( V_107 ) ) ;
V_14 . V_84 . V_249 . V_273 = F_5 ( V_271 ) ;
return F_9 ( V_1 , & V_14 , sizeof( V_14 ) , NULL , V_15 ) ;
}
int F_99 ( struct V_1 * V_1 , int V_55 ,
struct V_274 * V_275 )
{
struct V_56 * V_57 = F_23 ( V_1 , V_55 ) ;
struct V_276 V_277 ;
unsigned int V_252 = V_278 ;
T_2 * V_279 = ( T_2 * ) & V_277 ;
while ( V_252 ) {
unsigned int V_280 = V_278 - V_252 ;
unsigned int V_281 = F_71 ( 6U , V_252 ) ;
struct V_282 V_14 , V_9 ;
T_4 V_283 = ( F_40 ( struct V_282 , V_84 ) +
sizeof( struct V_284 ) ) ;
T_4 V_107 = F_39 ( V_283 , 16 ) ;
int V_104 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_193 = F_24 ( F_25 ( V_285 ) |
F_100 ( V_57 -> V_70 ) |
V_35 |
V_67 ) ;
V_14 . V_101 = F_24 ( F_41 ( V_107 ) ) ;
V_14 . V_84 . V_286 . V_287 =
F_27 ( F_101 ( V_280 ) |
F_102 ( V_281 ) ) ;
V_104 = F_103 ( V_1 , & V_14 , V_283 , & V_9 ) ;
if ( V_104 )
return V_104 ;
memcpy ( V_279 , & V_9 . V_84 . V_286 . V_288 , sizeof( T_2 ) * V_281 ) ;
V_252 -= V_281 ;
V_279 += V_281 ;
}
V_275 -> V_289 = F_12 ( V_277 . V_289 ) ;
V_275 -> V_290 = F_12 ( V_277 . V_290 ) ;
V_275 -> V_291 = F_12 ( V_277 . V_291 ) ;
V_275 -> V_292 = F_12 ( V_277 . V_292 ) ;
V_275 -> V_293 = F_12 ( V_277 . V_293 ) ;
V_275 -> V_294 = F_12 ( V_277 . V_294 ) ;
V_275 -> V_295 = F_12 ( V_277 . V_295 ) ;
V_275 -> V_296 = F_12 ( V_277 . V_296 ) ;
V_275 -> V_297 = F_12 ( V_277 . V_297 ) ;
V_275 -> V_298 = F_12 ( V_277 . V_298 ) ;
V_275 -> V_299 = F_12 ( V_277 . V_299 ) ;
V_275 -> V_300 = F_12 ( V_277 . V_300 ) ;
V_275 -> V_301 = F_12 ( V_277 . V_301 ) ;
V_275 -> V_302 = F_12 ( V_277 . V_302 ) ;
V_275 -> V_303 = F_12 ( V_277 . V_303 ) ;
V_275 -> V_304 = F_12 ( V_277 . V_304 ) ;
return 0 ;
}
int F_104 ( struct V_1 * V_1 , unsigned int V_305 ,
unsigned int V_306 , unsigned int V_307 , unsigned int V_308 )
{
struct V_309 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_65 = F_24 ( F_25 ( V_310 ) |
V_35 |
V_223 ) ;
V_14 . V_68 = F_24 ( V_311 |
F_26 ( V_14 ) ) ;
V_14 . V_312 =
F_24 ( F_105 ( V_305 ) ) ;
V_14 . V_306 = F_27 ( V_306 ) ;
V_14 . V_307 = F_27 ( V_307 ) ;
V_14 . V_308 = F_27 ( V_308 ) ;
return F_29 ( V_1 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_106 ( struct V_1 * V_1 , unsigned int V_313 )
{
struct V_314 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_65 = F_24 ( F_25 ( V_315 ) |
V_35 |
V_223 ) ;
V_14 . V_68 = F_24 ( V_316 |
F_26 ( V_14 ) ) ;
V_14 . V_317 = F_24 ( F_107 ( V_313 ) ) ;
return F_29 ( V_1 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_108 ( struct V_1 * V_1 , const T_2 * V_9 )
{
const struct V_318 * V_319 = ( const struct V_318 * ) V_9 ;
T_3 V_320 = F_109 ( F_19 ( V_319 -> V_321 ) ) ;
switch ( V_320 ) {
case V_81 : {
const struct V_61 * V_62 =
( const struct V_61 * ) V_9 ;
T_1 V_64 ;
int V_322 , V_71 , V_323 , V_44 , V_46 , V_55 ;
V_322 = F_110 (
F_19 ( V_62 -> V_82 ) ) ;
if ( V_322 != V_83 ) {
F_8 ( V_1 -> V_13 ,
L_6 ,
V_322 ) ;
break;
}
V_71 = F_111 (
F_19 ( V_62 -> V_80 ) ) ;
V_64 = F_19 ( V_62 -> V_84 . V_85 . V_324 ) ;
V_323 = ( V_64 & V_325 ) != 0 ;
V_44 = 0 ;
V_46 = 0 ;
if ( V_64 & V_326 )
V_46 |= V_47 ;
if ( V_64 & V_327 )
V_46 |= V_48 ;
if ( V_64 & F_112 ( V_87 ) )
V_44 = 100 ;
else if ( V_64 & F_112 ( V_89 ) )
V_44 = 1000 ;
else if ( V_64 & F_112 ( V_91 ) )
V_44 = 10000 ;
else if ( V_64 & F_112 ( V_93 ) )
V_44 = 40000 ;
F_113 (adapter, pidx) {
struct V_56 * V_57 = F_23 ( V_1 , V_55 ) ;
struct V_39 * V_40 ;
if ( V_57 -> V_71 != V_71 )
continue;
V_40 = & V_57 -> V_96 ;
if ( V_323 != V_40 -> V_323 || V_44 != V_40 -> V_44 ||
V_46 != V_40 -> V_46 ) {
V_40 -> V_323 = V_323 ;
V_40 -> V_44 = V_44 ;
V_40 -> V_46 = V_46 ;
F_114 ( V_1 , V_55 , V_323 ) ;
}
}
break;
}
default:
F_8 ( V_1 -> V_13 , L_7 ,
V_320 ) ;
}
return 0 ;
}
