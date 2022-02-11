static T_1 F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
return 1 ;
case V_3 :
return 10 ;
case V_4 :
return 100 ;
case V_5 :
return 1000 ;
case V_6 :
return 10000 ;
case V_7 :
return 100000 ;
default:
return 1 ;
}
}
static long F_2 ( unsigned long V_8 ,
unsigned long V_9 ,
unsigned long V_10 ,
unsigned long V_11 ,
unsigned long V_12 ,
unsigned long V_13 ,
unsigned long V_14 ,
unsigned long V_15 )
{
long V_16 ;
int V_17 , V_18 ;
unsigned long V_19 = 0 ;
if ( F_3 ( V_20 >= 2 ) )
F_4 ( L_1 V_21 ,
V_8 , V_9 , V_10 , V_11 , V_12 , V_13 , V_14 , V_15 ) ;
for ( V_17 = 0 ; V_17 < 5 ; V_17 ++ ) {
if ( V_22 )
F_5 ( & V_23 , V_19 ) ;
V_16 = F_6 ( V_8 , V_9 , V_10 , V_11 , V_12 ,
V_13 , V_14 , V_15 ) ;
if ( V_22 )
F_7 ( & V_23 , V_19 ) ;
if ( F_8 ( V_16 ) ) {
V_18 = F_1 ( V_16 ) ;
F_9 ( V_18 ) ;
continue;
}
if ( V_16 < V_24 )
F_10 ( L_2 V_21 ,
V_8 , V_16 , V_9 , V_10 , V_11 ,
V_12 , V_13 , V_14 , V_15 ) ;
else
if ( F_3 ( V_20 >= 2 ) )
F_4 ( L_3 , V_8 , V_16 ) ;
return V_16 ;
}
return V_25 ;
}
static long F_11 ( unsigned long V_8 ,
unsigned long * V_26 ,
unsigned long V_9 ,
unsigned long V_10 ,
unsigned long V_11 ,
unsigned long V_12 ,
unsigned long V_13 ,
unsigned long V_14 ,
unsigned long V_15 ,
unsigned long V_27 ,
unsigned long V_28 )
{
long V_16 ;
int V_17 , V_18 ;
unsigned long V_19 = 0 ;
if ( F_3 ( V_20 >= 2 ) )
F_4 ( L_4 V_29 , V_8 ,
V_9 , V_10 , V_11 , V_12 , V_13 ,
V_14 , V_15 , V_27 , V_28 ) ;
for ( V_17 = 0 ; V_17 < 5 ; V_17 ++ ) {
if ( V_22 )
F_5 ( & V_23 , V_19 ) ;
V_16 = F_12 ( V_8 , V_26 ,
V_9 , V_10 , V_11 , V_12 , V_13 ,
V_14 , V_15 , V_27 , V_28 ) ;
if ( V_22 )
F_7 ( & V_23 , V_19 ) ;
if ( F_8 ( V_16 ) ) {
V_18 = F_1 ( V_16 ) ;
F_9 ( V_18 ) ;
continue;
}
if ( V_16 < V_24 ) {
F_10 ( L_4 V_29 ,
V_8 , V_9 , V_10 , V_11 , V_12 , V_13 ,
V_14 , V_15 , V_27 , V_28 ) ;
F_10 ( L_5 V_29 ,
V_16 , V_26 [ 0 ] , V_26 [ 1 ] , V_26 [ 2 ] , V_26 [ 3 ] ,
V_26 [ 4 ] , V_26 [ 5 ] , V_26 [ 6 ] , V_26 [ 7 ] ,
V_26 [ 8 ] ) ;
} else if ( F_3 ( V_20 >= 2 ) )
F_4 ( L_5 V_29 ,
V_16 , V_26 [ 0 ] , V_26 [ 1 ] , V_26 [ 2 ] , V_26 [ 3 ] ,
V_26 [ 4 ] , V_26 [ 5 ] , V_26 [ 6 ] , V_26 [ 7 ] ,
V_26 [ 8 ] ) ;
return V_16 ;
}
return V_25 ;
}
T_2 F_13 ( const struct V_30 V_31 ,
struct V_32 * V_33 ,
const T_1 V_34 ,
const T_1 V_35 ,
struct V_36 * V_37 ,
T_1 * V_38 ,
T_1 * V_39 ,
T_1 * V_40 )
{
T_2 V_16 ;
unsigned long V_26 [ V_41 ] ;
T_2 V_42 ;
V_42 = 3ULL ;
if ( V_34 != 1 )
V_42 = ( 1ULL << ( 63 - 7 ) ) | V_42 ;
else
V_42 = ( 1ULL << 63 ) | V_42 ;
V_16 = F_11 ( V_43 , V_26 ,
V_31 . V_44 ,
V_42 ,
V_35 ,
0 , 0 , 0 , 0 , 0 , 0 ) ;
V_37 -> V_44 = V_26 [ 0 ] ;
* V_38 = ( T_1 ) V_26 [ 3 ] ;
* V_39 = ( T_1 ) V_26 [ 4 ] ;
* V_40 = ( T_1 ) V_26 [ 5 ] ;
if ( V_16 == V_45 )
F_10 ( L_6 , V_16 ) ;
return V_16 ;
}
T_2 F_14 ( const struct V_30 V_31 ,
struct V_36 V_37 ,
const T_2 V_46 )
{
return F_2 ( V_47 ,
V_31 . V_44 ,
V_37 . V_44 ,
V_46 ,
0 , 0 , 0 , 0 ) ;
}
T_2 F_15 ( const struct V_30 V_31 ,
struct V_48 * V_49 ,
struct V_50 * V_51 )
{
int V_52 ;
T_2 V_16 ;
unsigned long V_26 [ V_41 ] ;
V_16 = F_11 ( V_43 , V_26 ,
V_31 . V_44 ,
2 ,
V_51 -> V_37 . V_44 ,
V_49 -> V_53 ,
V_51 -> V_54 ,
0 , 0 , 0 , 0 ) ;
V_49 -> V_55 . V_44 = V_26 [ 0 ] ;
V_51 -> V_38 = ( T_1 ) V_26 [ 3 ] ;
V_51 -> V_39 = ( T_1 ) V_26 [ 4 ] ;
if ( V_16 == V_24 ) {
V_52 = F_16 ( & V_49 -> V_56 , 0 , V_26 [ 5 ] , V_26 [ 6 ] ) ;
if ( V_52 ) {
F_10 ( L_7 ,
V_52 , V_26 [ 5 ] ) ;
F_2 ( V_57 ,
V_31 . V_44 ,
V_49 -> V_55 . V_44 ,
0 , 0 , 0 , 0 , 0 ) ;
V_16 = V_58 ;
}
}
if ( V_16 == V_45 )
F_10 ( L_8 , V_16 ) ;
return V_16 ;
}
T_2 F_17 ( const struct V_30 V_31 ,
struct V_59 * V_60 , int V_61 )
{
int V_52 ;
T_2 V_16 ;
T_2 V_42 , V_62 , V_63 , V_64 ;
unsigned long V_26 [ V_41 ] ;
V_42 =
F_18 ( V_65 , V_60 -> V_66 )
| F_18 ( V_67 , 0 )
| F_18 ( V_68 , V_60 -> V_69 )
| F_18 ( V_70 , V_60 -> V_71 )
| F_18 ( V_72 , V_60 -> V_73 )
| F_18 ( V_74 ,
V_60 -> V_75 . V_76 )
| F_18 ( V_77 ,
V_60 -> V_78 . V_76 )
| F_18 ( V_79 ,
! ! ( V_60 -> V_80 & V_81 ) )
| F_18 ( V_82 ,
! ! ( V_60 -> V_80 & V_83 ) )
| F_18 ( V_84 ,
V_60 -> V_85 )
| F_18 ( V_86 , 1 ) ;
V_62 =
F_18 ( V_87 ,
V_60 -> V_75 . V_88 + 1 )
| F_18 ( V_89 ,
V_60 -> V_78 . V_88 + 1 )
| F_18 ( V_90 ,
V_60 -> V_75 . V_91 )
| F_18 ( V_92 ,
V_60 -> V_78 . V_91 ) ;
V_63 = F_18 ( V_93 , V_60 -> V_94 ) ;
if ( V_60 -> V_66 == V_95 )
V_64 = F_18 ( V_96 , V_60 -> V_97 ) ;
else
V_64 = F_18 ( V_98 , V_60 -> V_99 ) ;
V_16 = F_11 ( V_43 , V_26 ,
V_31 . V_44 ,
V_42 ,
V_60 -> V_100 . V_44 ,
V_60 -> V_101 . V_44 ,
V_60 -> V_37 . V_44 ,
( ( T_2 ) V_60 -> V_53 << 32 ) | V_60 -> V_102 . V_103 ,
V_62 , V_63 , V_64 ) ;
V_60 -> V_104 . V_44 = V_26 [ 0 ] ;
V_60 -> V_105 = ( T_1 ) V_26 [ 1 ] ;
V_60 -> V_75 . V_106 =
( V_107 ) F_19 ( V_108 , V_26 [ 2 ] ) ;
V_60 -> V_78 . V_106 =
( V_107 ) F_19 ( V_109 , V_26 [ 2 ] ) ;
V_60 -> V_75 . V_110 =
( V_111 ) F_19 ( V_112 , V_26 [ 3 ] ) ;
V_60 -> V_78 . V_110 =
( V_111 ) F_19 ( V_113 , V_26 [ 3 ] ) ;
V_60 -> V_75 . V_114 =
( T_1 ) F_19 ( V_115 , V_26 [ 4 ] ) ;
V_60 -> V_78 . V_114 =
( T_1 ) F_19 ( V_116 , V_26 [ 4 ] ) ;
if ( V_16 == V_24 ) {
V_52 = F_16 ( & V_60 -> V_56 , V_61 , V_26 [ 6 ] , V_26 [ 6 ] ) ;
if ( V_52 ) {
F_10 ( L_7 ,
V_52 , V_26 [ 6 ] ) ;
F_2 ( V_57 ,
V_31 . V_44 ,
V_60 -> V_104 . V_44 ,
0 , 0 , 0 , 0 , 0 ) ;
V_16 = V_58 ;
}
}
if ( V_16 == V_45 )
F_10 ( L_8 , V_16 ) ;
return V_16 ;
}
T_2 F_20 ( const struct V_30 V_31 ,
const V_111 V_117 ,
struct V_118 * V_119 )
{
T_2 V_16 ;
T_2 V_120 = F_21 ( V_119 ) ;
if ( V_120 & ( V_121 - 1 ) ) {
F_10 ( L_9 ) ;
return V_122 ;
}
V_16 = F_2 ( V_123 ,
V_31 . V_44 ,
V_117 ,
V_120 ,
0 , 0 , 0 , 0 ) ;
if ( V_20 >= 2 )
F_22 ( V_119 , 64 , L_10 ) ;
return V_16 ;
}
T_2 F_23 ( const struct V_30 V_31 ,
const V_111 V_117 , const T_1 V_124 ,
const V_111 V_125 , const int V_126 )
{
T_2 V_127 = V_124 ;
if ( V_126 & V_128 )
V_127 |= F_18 ( V_129 , 1 ) ;
if ( V_126 & V_130 )
V_127 |= F_18 ( V_131 , V_125 ) ;
if ( V_126 & V_132 )
V_127 |= F_18 ( V_133 , 1 ) ;
return F_2 ( V_134 ,
V_31 . V_44 ,
V_117 ,
V_127 ,
0 , 0 , 0 , 0 ) ;
}
T_2 F_24 ( const struct V_30 V_31 ,
struct V_135 * V_136 )
{
T_2 V_120 = F_21 ( V_136 ) ;
if ( V_120 & ( V_121 - 1 ) ) {
F_10 ( L_11 ,
V_136 ) ;
return V_122 ;
}
return F_2 ( V_137 ,
V_31 . V_44 ,
V_120 ,
0 , 0 , 0 , 0 , 0 ) ;
}
T_2 F_25 ( const struct V_30 V_31 ,
const V_111 V_138 ,
const V_111 V_139 ,
const T_2 V_140 ,
const T_2 V_141 ,
T_2 V_142 )
{
return F_2 ( V_143 ,
V_31 . V_44 ,
( T_2 ) V_139 | ( ( T_2 ) V_138 ) << 8 ,
V_140 ,
V_141 ,
V_142 ,
0 , 0 ) ;
}
T_2 F_26 ( const struct V_30 V_31 ,
const struct V_36 V_37 ,
struct V_32 * V_33 ,
const V_111 V_138 ,
const V_111 V_139 ,
const T_2 V_141 ,
const T_2 V_142 )
{
if ( V_142 != 1 ) {
F_10 ( L_12 , V_142 ) ;
return V_122 ;
}
return F_25 ( V_31 ,
V_138 ,
V_139 ,
V_37 . V_44 ,
V_141 , V_142 ) ;
}
T_2 F_27 ( const struct V_30 V_31 ,
T_1 V_144 )
{
T_2 V_16 ;
V_16 = F_2 ( V_145 ,
V_31 . V_44 ,
V_144 ,
0 , 0 , 0 , 0 , 0 ) ;
if ( V_16 != V_24 && V_16 != V_25 )
F_10 ( L_13 ) ;
return V_16 ;
}
T_2 F_28 ( const struct V_30 V_31 ,
const struct V_55 V_146 ,
struct V_147 * V_148 ,
const V_111 V_138 ,
const V_111 V_139 ,
const T_2 V_141 ,
const T_2 V_142 ,
const struct V_149 V_150 )
{
if ( V_142 != 1 ) {
F_10 ( L_14 , V_142 ) ;
return V_122 ;
}
return F_25 ( V_31 , V_138 , V_139 ,
V_146 . V_44 , V_141 ,
V_142 ) ;
}
T_2 F_29 ( const struct V_30 V_31 ,
const struct V_151 V_104 ,
struct V_152 * V_153 ,
const V_111 V_138 ,
const V_111 V_139 ,
const T_2 V_141 ,
const T_2 V_142 ,
const struct V_149 V_154 )
{
if ( V_142 > 1 ) {
F_10 ( L_14 , V_142 ) ;
return V_122 ;
}
return F_25 ( V_31 , V_138 , V_139 ,
V_104 . V_44 , V_141 ,
V_142 ) ;
}
T_2 F_30 ( const struct V_30 V_31 ,
const struct V_151 V_104 ,
struct V_152 * V_153 ,
void * * V_155 ,
void * * V_156 ,
int V_157 )
{
T_2 V_16 ;
unsigned long V_26 [ V_41 ] ;
V_16 = F_11 ( V_158 , V_26 ,
V_31 . V_44 ,
V_157 ,
V_104 . V_44 ,
0 , 0 , 0 , 0 , 0 , 0 ) ;
if ( V_155 )
* V_155 = ( void * ) V_26 [ 0 ] ;
if ( V_156 )
* V_156 = ( void * ) V_26 [ 1 ] ;
return V_16 ;
}
T_2 F_31 ( const struct V_30 V_31 ,
const struct V_151 V_104 ,
struct V_152 * V_153 ,
const T_2 V_159 ,
struct V_160 * V_161 ,
struct V_149 V_150 )
{
T_2 V_16 ;
unsigned long V_26 [ V_41 ] ;
V_16 = F_11 ( V_162 , V_26 ,
V_31 . V_44 ,
V_104 . V_44 ,
V_159 ,
F_21 ( V_161 ) ,
0 , 0 , 0 , 0 , 0 ) ;
if ( V_16 == V_45 )
F_10 ( L_15 , V_16 ) ;
return V_16 ;
}
T_2 F_32 ( const struct V_30 V_31 ,
const struct V_151 V_104 ,
struct V_152 * V_153 ,
struct V_160 * V_163 ,
struct V_149 V_150 )
{
return F_2 ( V_164 ,
V_31 . V_44 ,
V_104 . V_44 ,
F_21 ( V_163 ) ,
0 , 0 , 0 , 0 ) ;
}
T_2 F_33 ( const struct V_30 V_31 ,
struct V_165 * V_166 )
{
T_2 V_16 ;
unsigned long V_26 [ V_41 ] ;
V_16 = F_34 ( & V_166 -> V_56 ) ;
if ( V_16 ) {
F_10 ( L_16 ) ;
return V_167 ;
}
V_16 = F_11 ( V_158 , V_26 ,
V_31 . V_44 ,
1 ,
V_166 -> V_151 . V_44 ,
0 , 0 , 0 , 0 , 0 , 0 ) ;
if ( V_16 == V_168 )
F_10 ( L_17 , V_16 ) ;
V_16 = F_2 ( V_57 ,
V_31 . V_44 ,
V_166 -> V_151 . V_44 ,
0 , 0 , 0 , 0 , 0 ) ;
if ( V_16 == V_167 )
F_10 ( L_18 , V_16 ) ;
return V_16 ;
}
T_2 F_35 ( const struct V_30 V_31 ,
const struct V_151 V_104 ,
struct V_149 V_150 ,
T_1 V_169 )
{
return F_2 ( V_170 ,
V_31 . V_44 ,
V_104 . V_44 ,
V_169 ,
0 , 0 , 0 , 0 ) ;
}
T_2 F_36 ( const struct V_30 V_31 ,
const struct V_151 V_104 ,
struct V_149 V_150 ,
T_1 V_169 , T_1 * V_171 ,
T_1 * V_172 )
{
T_2 V_16 ;
unsigned long V_26 [ V_41 ] ;
V_16 = F_11 ( V_173 , V_26 ,
V_31 . V_44 ,
V_104 . V_44 ,
V_169 ,
0 , 0 , 0 , 0 , 0 , 0 ) ;
* V_171 = ( T_1 ) V_26 [ 0 ] ;
* V_172 = ( T_1 ) V_26 [ 1 ] ;
if ( V_16 == V_174 )
F_10 ( L_19 , V_16 ) ;
return V_16 ;
}
T_2 F_37 ( const struct V_30 V_31 ,
const struct V_151 V_104 ,
struct V_149 V_150 ,
V_107 V_175 ,
T_2 V_176 , T_2 V_177 )
{
T_2 V_16 ;
V_16 = F_2 ( V_178 ,
V_31 . V_44 ,
V_104 . V_44 ,
V_175 ,
V_177 ,
V_176 ,
0 , 0 ) ;
if ( V_16 == V_45 )
F_10 ( L_8 , V_16 ) ;
return V_16 ;
}
T_2 F_38 ( const struct V_30 V_31 ,
const struct V_151 V_104 ,
struct V_149 V_150 ,
V_107 V_175 ,
T_2 V_176 , T_2 V_177 )
{
return F_2 ( V_179 ,
V_31 . V_44 ,
V_104 . V_44 ,
V_175 ,
V_177 ,
V_176 ,
0 , 0 ) ;
}
T_2 F_39 ( const struct V_30 V_31 ,
struct V_48 * V_49 ,
V_111 V_180 )
{
T_2 V_16 ;
V_16 = F_34 ( & V_49 -> V_56 ) ;
if ( V_16 ) {
F_10 ( L_20 ) ;
return V_167 ;
}
V_16 = F_2 ( V_57 ,
V_31 . V_44 ,
V_49 -> V_55 . V_44 ,
V_180 != 0 ? 1L : 0L ,
0 , 0 , 0 , 0 ) ;
if ( V_16 == V_167 )
F_10 ( L_21 , V_16 ) ;
return V_16 ;
}
T_2 F_40 ( const struct V_30 V_31 ,
struct V_181 * V_182 )
{
T_2 V_16 ;
V_16 = F_34 ( & V_182 -> V_56 ) ;
if ( V_16 ) {
F_10 ( L_22 ) ;
return V_167 ;
}
V_16 = F_2 ( V_57 ,
V_31 . V_44 ,
V_182 -> V_36 . V_44 ,
0 , 0 , 0 , 0 , 0 ) ;
if ( V_16 == V_167 )
F_10 ( L_23 , V_16 ) ;
return V_16 ;
}
T_2 F_41 ( const struct V_30 V_31 ,
const struct V_183 * V_184 ,
const T_2 V_185 ,
const T_2 V_186 ,
const T_1 V_187 ,
const struct V_188 V_102 ,
struct V_189 * V_190 )
{
T_2 V_16 ;
unsigned long V_26 [ V_41 ] ;
V_16 = F_11 ( V_43 , V_26 ,
V_31 . V_44 ,
5 ,
V_185 ,
V_186 ,
( ( ( T_2 ) V_187 ) << 32ULL ) ,
V_102 . V_103 ,
0 , 0 , 0 ) ;
V_190 -> V_44 . V_44 = V_26 [ 0 ] ;
V_190 -> V_191 = ( T_1 ) V_26 [ 2 ] ;
V_190 -> V_192 = ( T_1 ) V_26 [ 3 ] ;
return V_16 ;
}
T_2 F_42 ( const struct V_30 V_31 ,
const struct V_183 * V_184 ,
const V_111 V_138 ,
const V_111 V_139 ,
const T_2 V_141 ,
const T_2 V_142 )
{
T_2 V_16 ;
if ( F_3 ( V_20 >= 3 ) ) {
if ( V_142 > 1 ) {
T_2 * V_193 ;
int V_17 ;
V_193 = F_43 ( V_141 ) ;
for ( V_17 = 0 ; V_17 < V_142 ; V_17 ++ )
F_4 ( L_24 ,
V_17 , ( void * ) V_193 [ V_17 ] ) ;
} else
F_4 ( L_25 ,
( void * ) V_141 ) ;
}
if ( ( V_142 > 1 ) && ( V_141 & ( V_121 - 1 ) ) ) {
F_10 ( L_26
L_27
L_28
L_29 ,
V_31 . V_44 , V_184 ,
V_184 -> V_194 . V_44 , V_138 , V_139 ,
V_141 , V_142 ) ;
V_16 = V_122 ;
} else
V_16 = F_25 ( V_31 , V_138 ,
V_139 ,
V_184 -> V_194 . V_44 ,
V_141 , V_142 ) ;
return V_16 ;
}
T_2 F_44 ( const struct V_30 V_31 ,
const struct V_183 * V_184 ,
struct V_189 * V_190 )
{
T_2 V_16 ;
unsigned long V_26 [ V_41 ] ;
V_16 = F_11 ( V_195 , V_26 ,
V_31 . V_44 ,
V_184 -> V_194 . V_44 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
V_190 -> V_196 = V_26 [ 0 ] ;
V_190 -> V_185 = V_26 [ 1 ] ;
V_190 -> V_197 = V_26 [ 4 ] >> 32 ;
V_190 -> V_191 = ( T_1 ) ( V_26 [ 5 ] >> 32 ) ;
V_190 -> V_192 = ( T_1 ) ( V_26 [ 5 ] & ( 0xffffffff ) ) ;
return V_16 ;
}
T_2 F_45 ( const struct V_30 V_31 ,
const struct V_183 * V_184 )
{
return F_2 ( V_57 ,
V_31 . V_44 ,
V_184 -> V_194 . V_44 ,
0 , 0 , 0 , 0 , 0 ) ;
}
T_2 F_46 ( const struct V_30 V_31 ,
const struct V_183 * V_184 ,
const T_2 V_198 ,
const T_2 V_186 ,
const T_1 V_187 ,
const struct V_188 V_102 ,
const T_2 V_199 ,
struct V_189 * V_190 )
{
T_2 V_16 ;
unsigned long V_26 [ V_41 ] ;
V_16 = F_11 ( V_200 , V_26 ,
V_31 . V_44 ,
V_184 -> V_194 . V_44 ,
V_198 ,
V_186 ,
( ( ( ( T_2 ) V_187 ) << 32ULL ) | V_102 . V_103 ) ,
V_199 ,
0 , 0 , 0 ) ;
V_190 -> V_185 = V_26 [ 1 ] ;
V_190 -> V_191 = ( T_1 ) V_26 [ 2 ] ;
V_190 -> V_192 = ( T_1 ) V_26 [ 3 ] ;
return V_16 ;
}
T_2 F_47 ( const struct V_30 V_31 ,
const struct V_183 * V_184 ,
const struct V_183 * V_201 ,
const T_2 V_198 ,
const T_1 V_187 ,
const struct V_188 V_102 ,
struct V_189 * V_190 )
{
T_2 V_16 ;
unsigned long V_26 [ V_41 ] ;
V_16 = F_11 ( V_202 , V_26 ,
V_31 . V_44 ,
V_201 -> V_194 . V_44 ,
V_198 ,
( ( ( T_2 ) V_187 ) << 32ULL ) ,
V_102 . V_103 ,
0 , 0 , 0 , 0 ) ;
V_190 -> V_44 . V_44 = V_26 [ 0 ] ;
V_190 -> V_191 = ( T_1 ) V_26 [ 2 ] ;
V_190 -> V_192 = ( T_1 ) V_26 [ 3 ] ;
return V_16 ;
}
T_2 F_48 ( const struct V_30 V_31 ,
const struct V_203 * V_204 ,
const struct V_188 V_102 ,
struct V_205 * V_190 )
{
T_2 V_16 ;
unsigned long V_26 [ V_41 ] ;
V_16 = F_11 ( V_43 , V_26 ,
V_31 . V_44 ,
6 ,
V_102 . V_103 ,
0 , 0 , 0 , 0 , 0 , 0 ) ;
V_190 -> V_44 . V_44 = V_26 [ 0 ] ;
V_190 -> V_192 = ( T_1 ) V_26 [ 3 ] ;
return V_16 ;
}
T_2 F_49 ( const struct V_30 V_31 ,
const struct V_203 * V_204 ,
struct V_205 * V_190 )
{
T_2 V_16 ;
unsigned long V_26 [ V_41 ] ;
V_16 = F_11 ( V_206 , V_26 ,
V_31 . V_44 ,
V_204 -> V_207 . V_44 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
V_190 -> V_192 = ( T_1 ) V_26 [ 3 ] ;
return V_16 ;
}
T_2 F_50 ( const struct V_30 V_31 ,
const struct V_203 * V_204 )
{
return F_2 ( V_57 ,
V_31 . V_44 ,
V_204 -> V_207 . V_44 ,
0 , 0 , 0 , 0 , 0 ) ;
}
T_2 F_51 ( const struct V_30 V_31 ,
const T_2 V_208 ,
void * V_209 ,
unsigned long * V_210 )
{
T_2 V_120 = F_21 ( V_209 ) ;
if ( V_120 & ( V_121 - 1 ) ) {
F_10 ( L_30 ) ;
return V_122 ;
}
return F_2 ( V_211 ,
V_31 . V_44 ,
V_208 ,
V_120 ,
0 , 0 , 0 , 0 ) ;
}
T_2 F_52 ( int V_212 )
{
unsigned long V_213 ;
F_53 () ;
V_213 = ( 0xffULL << 24 ) | V_212 ;
return F_6 ( V_214 , V_213 ) ;
}
