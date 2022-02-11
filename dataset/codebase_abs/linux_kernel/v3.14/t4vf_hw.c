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
V_17 |= V_49 ;
F_21 ( & V_57 -> V_94 , V_17 ) ;
return 0 ;
}
int F_37 ( struct V_1 * V_1 )
{
struct V_95 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_96 = F_24 ( F_25 ( V_97 ) |
V_98 ) ;
V_14 . V_99 = F_24 ( F_26 ( V_14 ) ) ;
return F_29 ( V_1 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
static int F_38 ( struct V_1 * V_1 , unsigned int V_100 ,
const T_1 * V_76 , T_1 * V_101 )
{
int V_18 , V_102 ;
struct V_103 V_14 , V_9 ;
struct V_104 * V_21 ;
T_4 V_105 ;
if ( V_100 > 7 )
return - V_27 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_65 = F_24 ( F_25 ( V_106 ) |
V_35 |
V_67 ) ;
V_105 = F_39 ( F_40 ( struct V_103 ,
V_107 [ V_100 ] . V_108 ) , 16 ) ;
V_14 . V_99 = F_24 ( F_41 ( V_105 ) ) ;
for ( V_18 = 0 , V_21 = & V_14 . V_107 [ 0 ] ; V_18 < V_100 ; V_18 ++ , V_21 ++ )
V_21 -> V_108 = F_42 ( * V_76 ++ ) ;
V_102 = F_29 ( V_1 , & V_14 , sizeof( V_14 ) , & V_9 ) ;
if ( V_102 == 0 )
for ( V_18 = 0 , V_21 = & V_9 . V_107 [ 0 ] ; V_18 < V_100 ; V_18 ++ , V_21 ++ )
* V_101 ++ = F_19 ( V_21 -> V_7 ) ;
return V_102 ;
}
int F_43 ( struct V_1 * V_1 , unsigned int V_100 ,
const T_1 * V_76 , const T_1 * V_101 )
{
int V_18 ;
struct V_103 V_14 ;
struct V_104 * V_21 ;
T_4 V_105 ;
if ( V_100 > 7 )
return - V_27 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_65 = F_24 ( F_25 ( V_106 ) |
V_35 |
V_98 ) ;
V_105 = F_39 ( F_40 ( struct V_103 ,
V_107 [ V_100 ] ) , 16 ) ;
V_14 . V_99 = F_24 ( F_41 ( V_105 ) ) ;
for ( V_18 = 0 , V_21 = & V_14 . V_107 [ 0 ] ; V_18 < V_100 ; V_18 ++ , V_21 ++ ) {
V_21 -> V_108 = F_24 ( * V_76 ++ ) ;
V_21 -> V_7 = F_24 ( * V_101 ++ ) ;
}
return F_29 ( V_1 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_44 ( struct V_1 * V_1 )
{
struct V_109 * V_109 = & V_1 -> V_76 . V_110 ;
T_1 V_76 [ 7 ] , V_101 [ 7 ] ;
int V_17 ;
V_76 [ 0 ] = ( F_45 ( V_111 ) |
F_46 ( V_112 ) ) ;
V_76 [ 1 ] = ( F_45 ( V_111 ) |
F_46 ( V_113 ) ) ;
V_76 [ 2 ] = ( F_45 ( V_111 ) |
F_46 ( V_114 ) ) ;
V_76 [ 3 ] = ( F_45 ( V_111 ) |
F_46 ( V_115 ) ) ;
V_76 [ 4 ] = ( F_45 ( V_111 ) |
F_46 ( V_116 ) ) ;
V_76 [ 5 ] = ( F_45 ( V_111 ) |
F_46 ( V_117 ) ) ;
V_76 [ 6 ] = ( F_45 ( V_111 ) |
F_46 ( V_118 ) ) ;
V_17 = F_38 ( V_1 , 7 , V_76 , V_101 ) ;
if ( V_17 )
return V_17 ;
V_109 -> V_119 = V_101 [ 0 ] ;
V_109 -> V_120 = V_101 [ 1 ] ;
V_109 -> V_121 [ 0 ] = V_101 [ 2 ] ;
V_109 -> V_121 [ 1 ] = V_101 [ 3 ] ;
V_109 -> V_122 = V_101 [ 4 ] ;
V_109 -> V_123 = V_101 [ 5 ] ;
V_109 -> V_124 = V_101 [ 6 ] ;
V_76 [ 0 ] = ( F_45 ( V_111 ) |
F_46 ( V_125 ) ) ;
V_17 = F_38 ( V_1 , 1 , V_76 , V_101 ) ;
if ( V_17 )
return V_17 ;
V_109 -> V_126 = V_101 [ 0 ] ;
return 0 ;
}
int F_47 ( struct V_1 * V_1 )
{
struct V_127 * V_127 = & V_1 -> V_76 . V_128 ;
T_1 V_76 [ 7 ] , V_101 [ 7 ] ;
int V_17 ;
V_76 [ 0 ] = ( F_45 ( V_129 ) |
F_48 ( V_130 ) ) ;
V_17 = F_38 ( V_1 , 1 , V_76 , V_101 ) ;
if ( V_17 )
return V_17 ;
V_127 -> V_131 = V_101 [ 0 ] ;
return 0 ;
}
int F_49 ( struct V_1 * V_1 )
{
struct V_132 * V_132 = & V_1 -> V_76 . V_133 ;
T_1 V_76 [ 7 ] , V_101 [ 7 ] ;
int V_17 ;
V_76 [ 0 ] = ( F_45 ( V_129 ) |
F_48 ( V_134 ) ) ;
V_76 [ 1 ] = ( F_45 ( V_129 ) |
F_48 ( V_135 ) ) ;
V_17 = F_38 ( V_1 , 2 , V_76 , V_101 ) ;
if ( V_17 )
return V_17 ;
V_132 -> V_136 = V_101 [ 0 ] ;
V_132 -> V_137 = V_101 [ 1 ] ;
return 0 ;
}
int F_50 ( struct V_1 * V_1 )
{
struct V_138 * V_139 = & V_1 -> V_76 . V_139 ;
struct V_140 V_14 , V_9 ;
int V_17 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_96 = F_24 ( F_25 ( V_141 ) |
V_35 |
V_67 ) ;
V_14 . V_99 = F_24 ( F_26 ( V_14 ) ) ;
V_17 = F_29 ( V_1 , & V_14 , sizeof( V_14 ) , & V_9 ) ;
if ( V_17 )
return V_17 ;
V_139 -> V_142 = F_51 (
F_19 ( V_9 . V_84 . V_143 . V_144 ) ) ;
switch ( V_139 -> V_142 ) {
case V_145 : {
T_1 V_64 = F_19 (
V_9 . V_84 . V_146 . V_147 ) ;
V_139 -> V_84 . V_146 . V_148 =
( ( V_64 & V_149 ) != 0 ) ;
V_139 -> V_84 . V_146 . V_150 =
( ( V_64 & V_151 ) != 0 ) ;
V_139 -> V_84 . V_146 . V_152 =
( ( V_64 & V_153 ) != 0 ) ;
V_139 -> V_84 . V_146 . V_154 =
( ( V_64 & V_155 ) != 0 ) ;
V_139 -> V_84 . V_146 . V_156 =
( ( V_64 & V_157 ) != 0 ) ;
V_139 -> V_84 . V_146 . V_158 =
( ( V_64 & V_159 ) != 0 ) ;
V_139 -> V_84 . V_146 . V_160 =
( ( V_64 & V_161 ) != 0 ) ;
V_139 -> V_84 . V_146 . V_162 =
( ( V_64 & V_163 ) != 0 ) ;
V_139 -> V_84 . V_146 . V_164 =
( ( V_64 & V_165 ) != 0 ) ;
if ( ! V_139 -> V_84 . V_146 . V_160 )
return - V_27 ;
break;
}
default:
return - V_27 ;
}
return 0 ;
}
int F_52 ( struct V_1 * V_1 )
{
struct V_166 * V_77 = & V_1 -> V_76 . V_77 ;
struct V_167 V_14 , V_9 ;
int V_17 ;
T_1 V_64 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_65 = F_24 ( F_25 ( V_168 ) |
V_35 |
V_67 ) ;
V_14 . V_99 = F_24 ( F_26 ( V_14 ) ) ;
V_17 = F_29 ( V_1 , & V_14 , sizeof( V_14 ) , & V_9 ) ;
if ( V_17 )
return V_17 ;
V_64 = F_19 ( V_9 . V_169 ) ;
V_77 -> V_170 = F_53 ( V_64 ) ;
V_77 -> V_171 = F_54 ( V_64 ) ;
V_64 = F_19 ( V_9 . V_172 ) ;
V_77 -> V_173 = F_55 ( V_64 ) ;
V_77 -> V_174 = F_56 ( V_64 ) ;
V_64 = F_19 ( V_9 . V_175 ) ;
V_77 -> V_176 = F_57 ( V_64 ) ;
V_77 -> V_177 = F_58 ( V_64 ) ;
V_77 -> V_178 = F_59 ( V_64 ) ;
V_64 = F_19 ( V_9 . V_179 ) ;
V_77 -> V_78 = F_60 ( V_64 ) ;
V_77 -> V_180 = F_61 ( V_64 ) ;
V_77 -> V_181 = F_62 ( V_64 ) ;
return 0 ;
}
int F_63 ( struct V_1 * V_1 , unsigned int V_70 ,
union V_182 * V_183 )
{
struct V_184 V_14 , V_9 ;
int V_17 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_185 = F_24 ( F_25 ( V_186 ) |
V_35 |
V_67 |
F_64 ( V_70 ) ) ;
V_14 . V_99 = F_24 ( F_26 ( V_14 ) ) ;
V_17 = F_29 ( V_1 , & V_14 , sizeof( V_14 ) , & V_9 ) ;
if ( V_17 )
return V_17 ;
switch ( V_1 -> V_76 . V_139 . V_142 ) {
case V_145 : {
T_1 V_64 = F_19 ( V_9 . V_84 . V_146 . V_187 ) ;
V_183 -> V_146 . V_188 =
( ( V_64 & V_189 ) != 0 ) ;
V_183 -> V_146 . V_190 =
( ( V_64 & V_191 ) != 0 ) ;
V_183 -> V_146 . V_192 =
( ( V_64 & V_193 ) != 0 ) ;
V_183 -> V_146 . V_194 =
( ( V_64 & V_195 ) != 0 ) ;
V_183 -> V_146 . V_196 =
( ( V_64 & V_197 ) != 0 ) ;
V_183 -> V_146 . V_198 =
F_65 ( V_64 ) ;
break;
}
default:
return - V_27 ;
}
return 0 ;
}
int F_66 ( struct V_1 * V_1 , unsigned int V_70 ,
union V_182 * V_183 )
{
struct V_184 V_14 , V_9 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_185 = F_24 ( F_25 ( V_186 ) |
V_35 |
V_98 |
F_64 ( V_70 ) ) ;
V_14 . V_99 = F_24 ( F_26 ( V_14 ) ) ;
switch ( V_1 -> V_76 . V_139 . V_142 ) {
case V_145 : {
T_1 V_64 = 0 ;
if ( V_183 -> V_146 . V_188 )
V_64 |= V_189 ;
if ( V_183 -> V_146 . V_190 )
V_64 |= V_191 ;
if ( V_183 -> V_146 . V_192 )
V_64 |= V_193 ;
if ( V_183 -> V_146 . V_194 )
V_64 |= V_195 ;
if ( V_183 -> V_146 . V_196 )
V_64 |= V_197 ;
V_64 |= F_67 (
V_183 -> V_146 . V_198 ) ;
V_14 . V_84 . V_146 . V_187 = F_24 ( V_64 ) ;
break;
}
default:
return - V_27 ;
}
return F_29 ( V_1 , & V_14 , sizeof( V_14 ) , & V_9 ) ;
}
int F_68 ( struct V_1 * V_1 , unsigned int V_70 ,
int V_199 , int V_200 , const T_5 * V_201 , int V_202 )
{
const T_5 * V_203 = V_201 ;
const T_5 * V_204 = V_201 + V_202 ;
struct V_205 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_185 = F_24 ( F_25 ( V_206 ) |
V_35 |
V_98 |
F_69 ( V_70 ) ) ;
V_14 . V_99 = F_24 ( F_26 ( V_14 ) ) ;
while ( V_200 > 0 ) {
T_6 * V_207 = & V_14 . V_208 ;
int V_209 = F_70 ( V_200 , 32 ) ;
int V_102 ;
V_14 . V_210 = F_27 ( V_209 ) ;
V_14 . V_211 = F_27 ( V_199 ) ;
V_199 += V_209 ;
V_200 -= V_209 ;
while ( V_209 > 0 ) {
T_5 V_212 [ 3 ] ;
T_5 * V_213 = V_212 ;
int V_214 = F_70 ( 3 , V_209 ) ;
V_209 -= V_214 ;
V_212 [ 0 ] = V_212 [ 1 ] = V_212 [ 2 ] = 0 ;
while ( V_214 ) {
V_214 -- ;
* V_213 ++ = * V_203 ++ ;
if ( V_203 >= V_204 )
V_203 = V_201 ;
}
* V_207 ++ = F_24 ( F_71 ( V_212 [ 0 ] ) |
F_72 ( V_212 [ 1 ] ) |
F_73 ( V_212 [ 2 ] ) ) ;
}
V_102 = F_29 ( V_1 , & V_14 , sizeof( V_14 ) , NULL ) ;
if ( V_102 )
return V_102 ;
}
return 0 ;
}
int F_74 ( struct V_1 * V_1 , int V_71 )
{
struct V_58 V_14 , V_9 ;
int V_17 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_65 = F_24 ( F_25 ( V_66 ) |
V_35 |
V_98 |
V_215 ) ;
V_14 . V_68 = F_24 ( F_26 ( V_14 ) |
V_216 ) ;
V_14 . V_72 = F_75 ( V_71 ) ;
V_17 = F_29 ( V_1 , & V_14 , sizeof( V_14 ) , & V_9 ) ;
if ( V_17 )
return V_17 ;
return F_76 ( F_33 ( V_9 . V_69 ) ) ;
}
int F_77 ( struct V_1 * V_1 , int V_70 )
{
struct V_58 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_65 = F_24 ( F_25 ( V_66 ) |
V_35 |
V_215 ) ;
V_14 . V_68 = F_24 ( F_26 ( V_14 ) |
V_217 ) ;
V_14 . V_69 = F_27 ( F_28 ( V_70 ) ) ;
return F_29 ( V_1 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_78 ( struct V_1 * V_1 , unsigned int V_70 ,
bool V_218 , bool V_219 )
{
struct V_220 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_185 = F_24 ( F_25 ( V_221 ) |
V_35 |
V_215 |
F_79 ( V_70 ) ) ;
V_14 . V_222 = F_24 ( F_80 ( V_218 ) |
F_81 ( V_219 ) |
F_26 ( V_14 ) ) ;
return F_29 ( V_1 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_82 ( struct V_1 * V_1 , unsigned int V_70 ,
unsigned int V_223 )
{
struct V_220 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_185 = F_24 ( F_25 ( V_221 ) |
V_35 |
V_215 |
F_79 ( V_70 ) ) ;
V_14 . V_222 = F_24 ( V_224 |
F_26 ( V_14 ) ) ;
V_14 . V_225 = F_27 ( V_223 ) ;
return F_29 ( V_1 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_83 ( struct V_1 * V_1 , unsigned int V_70 ,
int V_226 , int V_227 , int V_228 , int V_229 , int V_230 ,
bool V_15 )
{
struct V_231 V_14 ;
if ( V_226 < 0 )
V_226 = V_232 ;
if ( V_227 < 0 )
V_227 = V_233 ;
if ( V_228 < 0 )
V_228 = V_234 ;
if ( V_229 < 0 )
V_229 = V_235 ;
if ( V_230 < 0 )
V_230 = V_236 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_185 = F_24 ( F_25 ( V_237 ) |
V_35 |
V_98 |
F_84 ( V_70 ) ) ;
V_14 . V_99 = F_24 ( F_26 ( V_14 ) ) ;
V_14 . V_238 =
F_24 ( F_85 ( V_226 ) |
F_86 ( V_227 ) |
F_87 ( V_228 ) |
F_88 ( V_229 ) |
F_89 ( V_230 ) ) ;
return F_9 ( V_1 , & V_14 , sizeof( V_14 ) , NULL , V_15 ) ;
}
int F_90 ( struct V_1 * V_1 , unsigned int V_70 , bool free ,
unsigned int V_239 , const T_3 * * V_36 , T_5 * V_240 ,
T_7 * V_241 , bool V_15 )
{
int V_242 , V_102 = 0 ;
unsigned V_243 = 0 ;
unsigned int V_244 = V_239 ;
struct V_245 V_14 , V_9 ;
unsigned int V_246 = F_91 ( V_1 -> V_76 . V_247 ) ?
V_248 :
V_249 ;
if ( V_239 > V_246 )
return - V_27 ;
for ( V_242 = 0 ; V_242 < V_239 ; ) {
unsigned int V_250 = ( V_244 < F_15 ( V_14 . V_84 . V_251 )
? V_244
: F_15 ( V_14 . V_84 . V_251 ) ) ;
T_4 V_105 = F_39 ( F_40 ( struct V_245 ,
V_84 . V_251 [ V_250 ] ) , 16 ) ;
struct V_252 * V_21 ;
int V_18 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_185 = F_24 ( F_25 ( V_253 ) |
V_35 |
V_98 |
( free ? V_215 : 0 ) |
F_92 ( V_70 ) ) ;
V_14 . V_254 =
F_24 ( F_93 ( free ) |
F_41 ( V_105 ) ) ;
for ( V_18 = 0 , V_21 = V_14 . V_84 . V_251 ; V_18 < V_250 ; V_18 ++ , V_21 ++ ) {
V_21 -> V_255 = F_27 (
V_256 |
F_94 ( V_257 ) ) ;
memcpy ( V_21 -> V_258 , V_36 [ V_242 + V_18 ] , sizeof( V_21 -> V_258 ) ) ;
}
V_102 = F_9 ( V_1 , & V_14 , sizeof( V_14 ) , & V_9 ,
V_15 ) ;
if ( V_102 && V_102 != - V_259 )
break;
for ( V_18 = 0 , V_21 = V_9 . V_84 . V_251 ; V_18 < V_250 ; V_18 ++ , V_21 ++ ) {
T_5 V_260 = F_95 (
F_33 ( V_21 -> V_255 ) ) ;
if ( V_240 )
V_240 [ V_242 + V_18 ] =
( V_260 >= V_246
? 0xffff
: V_260 ) ;
if ( V_260 < V_246 )
V_243 ++ ;
else if ( V_241 )
* V_241 |= ( 1ULL << F_20 ( V_36 [ V_242 + V_18 ] ) ) ;
}
free = false ;
V_242 += V_250 ;
V_244 -= V_250 ;
}
if ( V_102 == 0 || V_102 == - V_259 )
V_102 = V_243 ;
return V_102 ;
}
int F_96 ( struct V_1 * V_1 , unsigned int V_70 ,
int V_240 , const T_3 * V_36 , bool V_261 )
{
int V_102 ;
struct V_245 V_14 , V_9 ;
struct V_252 * V_21 = & V_14 . V_84 . V_251 [ 0 ] ;
T_4 V_105 = F_39 ( F_40 ( struct V_245 ,
V_84 . V_251 [ 1 ] ) , 16 ) ;
unsigned int V_246 = F_91 ( V_1 -> V_76 . V_247 ) ?
V_248 :
V_249 ;
if ( V_240 < 0 )
V_240 = V_261 ? V_262 : V_257 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_185 = F_24 ( F_25 ( V_253 ) |
V_35 |
V_98 |
F_92 ( V_70 ) ) ;
V_14 . V_254 = F_24 ( F_41 ( V_105 ) ) ;
V_21 -> V_255 = F_27 ( V_256 |
F_94 ( V_240 ) ) ;
memcpy ( V_21 -> V_258 , V_36 , sizeof( V_21 -> V_258 ) ) ;
V_102 = F_29 ( V_1 , & V_14 , sizeof( V_14 ) , & V_9 ) ;
if ( V_102 == 0 ) {
V_21 = & V_9 . V_84 . V_251 [ 0 ] ;
V_102 = F_95 ( F_33 ( V_21 -> V_255 ) ) ;
if ( V_102 >= V_246 )
V_102 = - V_259 ;
}
return V_102 ;
}
int F_97 ( struct V_1 * V_1 , unsigned int V_70 ,
bool V_263 , T_7 V_264 , bool V_15 )
{
struct V_245 V_14 ;
T_4 V_105 = F_39 ( F_40 ( struct V_245 ,
V_84 . V_251 [ 0 ] ) , 16 ) ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_185 = F_24 ( F_25 ( V_253 ) |
V_35 |
V_98 |
F_79 ( V_70 ) ) ;
V_14 . V_254 = F_24 ( V_265 |
F_98 ( V_263 ) |
F_41 ( V_105 ) ) ;
V_14 . V_84 . V_241 . V_266 = F_5 ( V_264 ) ;
return F_9 ( V_1 , & V_14 , sizeof( V_14 ) , NULL , V_15 ) ;
}
int F_99 ( struct V_1 * V_1 , int V_55 ,
struct V_267 * V_268 )
{
struct V_56 * V_57 = F_23 ( V_1 , V_55 ) ;
struct V_269 V_270 ;
unsigned int V_244 = V_271 ;
T_2 * V_272 = ( T_2 * ) & V_270 ;
while ( V_244 ) {
unsigned int V_273 = V_271 - V_244 ;
unsigned int V_274 = F_70 ( 6U , V_244 ) ;
struct V_275 V_14 , V_9 ;
T_4 V_276 = ( F_40 ( struct V_275 , V_84 ) +
sizeof( struct V_277 ) ) ;
T_4 V_105 = F_39 ( V_276 , 16 ) ;
int V_102 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_185 = F_24 ( F_25 ( V_278 ) |
F_100 ( V_57 -> V_70 ) |
V_35 |
V_67 ) ;
V_14 . V_99 = F_24 ( F_41 ( V_105 ) ) ;
V_14 . V_84 . V_279 . V_280 =
F_27 ( F_101 ( V_273 ) |
F_102 ( V_274 ) ) ;
V_102 = F_103 ( V_1 , & V_14 , V_276 , & V_9 ) ;
if ( V_102 )
return V_102 ;
memcpy ( V_272 , & V_9 . V_84 . V_279 . V_281 , sizeof( T_2 ) * V_274 ) ;
V_244 -= V_274 ;
V_272 += V_274 ;
}
V_268 -> V_282 = F_12 ( V_270 . V_282 ) ;
V_268 -> V_283 = F_12 ( V_270 . V_283 ) ;
V_268 -> V_284 = F_12 ( V_270 . V_284 ) ;
V_268 -> V_285 = F_12 ( V_270 . V_285 ) ;
V_268 -> V_286 = F_12 ( V_270 . V_286 ) ;
V_268 -> V_287 = F_12 ( V_270 . V_287 ) ;
V_268 -> V_288 = F_12 ( V_270 . V_288 ) ;
V_268 -> V_289 = F_12 ( V_270 . V_289 ) ;
V_268 -> V_290 = F_12 ( V_270 . V_290 ) ;
V_268 -> V_291 = F_12 ( V_270 . V_291 ) ;
V_268 -> V_292 = F_12 ( V_270 . V_292 ) ;
V_268 -> V_293 = F_12 ( V_270 . V_293 ) ;
V_268 -> V_294 = F_12 ( V_270 . V_294 ) ;
V_268 -> V_295 = F_12 ( V_270 . V_295 ) ;
V_268 -> V_296 = F_12 ( V_270 . V_296 ) ;
V_268 -> V_297 = F_12 ( V_270 . V_297 ) ;
return 0 ;
}
int F_104 ( struct V_1 * V_1 , unsigned int V_298 ,
unsigned int V_299 , unsigned int V_300 , unsigned int V_301 )
{
struct V_302 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_65 = F_24 ( F_25 ( V_303 ) |
V_35 |
V_215 ) ;
V_14 . V_68 = F_24 ( V_304 |
F_26 ( V_14 ) ) ;
V_14 . V_305 =
F_24 ( F_105 ( V_298 ) ) ;
V_14 . V_299 = F_27 ( V_299 ) ;
V_14 . V_300 = F_27 ( V_300 ) ;
V_14 . V_301 = F_27 ( V_301 ) ;
return F_29 ( V_1 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_106 ( struct V_1 * V_1 , unsigned int V_306 )
{
struct V_307 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_65 = F_24 ( F_25 ( V_308 ) |
V_35 |
V_215 ) ;
V_14 . V_68 = F_24 ( V_309 |
F_26 ( V_14 ) ) ;
V_14 . V_310 = F_24 ( F_107 ( V_306 ) ) ;
return F_29 ( V_1 , & V_14 , sizeof( V_14 ) , NULL ) ;
}
int F_108 ( struct V_1 * V_1 , const T_2 * V_9 )
{
const struct V_311 * V_312 = ( const struct V_311 * ) V_9 ;
T_3 V_313 = F_109 ( F_19 ( V_312 -> V_314 ) ) ;
switch ( V_313 ) {
case V_81 : {
const struct V_61 * V_62 =
( const struct V_61 * ) V_9 ;
T_1 V_64 ;
int V_315 , V_71 , V_316 , V_44 , V_46 , V_55 ;
V_315 = F_110 (
F_19 ( V_62 -> V_82 ) ) ;
if ( V_315 != V_83 ) {
F_8 ( V_1 -> V_13 ,
L_4 ,
V_315 ) ;
break;
}
V_71 = F_111 (
F_19 ( V_62 -> V_80 ) ) ;
V_64 = F_19 ( V_62 -> V_84 . V_85 . V_317 ) ;
V_316 = ( V_64 & V_318 ) != 0 ;
V_44 = 0 ;
V_46 = 0 ;
if ( V_64 & V_319 )
V_46 |= V_47 ;
if ( V_64 & V_320 )
V_46 |= V_48 ;
if ( V_64 & F_112 ( V_87 ) )
V_44 = V_321 ;
else if ( V_64 & F_112 ( V_89 ) )
V_44 = V_322 ;
else if ( V_64 & F_112 ( V_91 ) )
V_44 = V_323 ;
F_113 (adapter, pidx) {
struct V_56 * V_57 = F_23 ( V_1 , V_55 ) ;
struct V_39 * V_40 ;
if ( V_57 -> V_71 != V_71 )
continue;
V_40 = & V_57 -> V_94 ;
if ( V_316 != V_40 -> V_316 || V_44 != V_40 -> V_44 ||
V_46 != V_40 -> V_46 ) {
V_40 -> V_316 = V_316 ;
V_40 -> V_44 = V_44 ;
V_40 -> V_46 = V_46 ;
F_114 ( V_1 , V_55 , V_316 ) ;
}
}
break;
}
default:
F_8 ( V_1 -> V_13 , L_5 ,
V_313 ) ;
}
return 0 ;
}
