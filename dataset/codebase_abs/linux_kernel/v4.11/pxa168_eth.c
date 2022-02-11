static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_6 ;
int V_7 = 40 ;
do {
F_3 ( V_2 , V_8 , V_9 | V_10 ) ;
F_6 ( 100 ) ;
V_6 = 10 ;
while ( ( F_1 ( V_2 , V_8 ) & ( V_9 | V_10 ) )
&& V_6 -- > 0 ) {
F_6 ( 10 ) ;
}
} while ( V_7 -- > 0 && V_6 <= 0 );
if ( V_7 <= 0 )
F_7 ( V_2 -> V_11 , L_1 , V_12 ) ;
}
static void F_8 ( struct V_13 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
int V_18 ;
while ( V_2 -> V_19 < V_2 -> V_20 ) {
int V_21 ;
V_15 = F_10 ( V_11 , V_2 -> V_22 ) ;
if ( ! V_15 )
break;
if ( V_23 )
F_11 ( V_15 , V_23 ) ;
V_2 -> V_19 ++ ;
V_18 = V_2 -> V_24 ;
V_17 = & V_2 -> V_25 [ V_18 ] ;
V_21 = F_12 ( V_15 ) - V_15 -> V_5 ;
V_17 -> V_26 = F_13 ( NULL ,
V_15 -> V_5 ,
V_21 ,
V_27 ) ;
V_17 -> V_28 = V_21 ;
V_2 -> V_29 [ V_18 ] = V_15 ;
F_14 () ;
V_17 -> V_30 = V_31 | V_32 ;
F_14 () ;
V_2 -> V_24 = ( V_18 + 1 ) % V_2 -> V_20 ;
V_2 -> V_33 = 0 ;
F_11 ( V_15 , V_34 ) ;
}
if ( V_2 -> V_19 == 0 ) {
V_2 -> V_35 . V_36 = V_37 + ( V_38 / 10 ) ;
F_15 ( & V_2 -> V_35 ) ;
}
}
static inline void F_16 ( unsigned long V_5 )
{
struct V_1 * V_2 = ( void * ) V_5 ;
F_17 ( & V_2 -> V_39 ) ;
}
static inline T_2 F_18 ( T_2 V_40 )
{
return ( ( ( V_40 ) & 0x01 ) << 3 ) | ( ( ( V_40 ) & 0x02 ) << 1 )
| ( ( ( V_40 ) & 0x04 ) >> 1 ) | ( ( ( V_40 ) & 0x08 ) >> 3 )
| ( ( ( V_40 ) & 0x10 ) << 3 ) | ( ( ( V_40 ) & 0x20 ) << 1 )
| ( ( ( V_40 ) & 0x40 ) >> 1 ) | ( ( ( V_40 ) & 0x80 ) >> 3 ) ;
}
static void F_19 ( unsigned char * V_41 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
V_41 [ V_42 ] = ( ( V_41 [ V_42 ] & 0x0f ) << 4 ) |
( ( V_41 [ V_42 ] & 0xf0 ) >> 4 ) ;
}
}
static void F_20 ( unsigned char * V_41 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ )
V_41 [ V_42 ] = F_18 ( V_41 [ V_42 ] ) ;
}
static T_1 F_21 ( unsigned char * V_44 )
{
T_1 V_45 ;
T_1 V_46 ;
T_1 V_47 ;
T_1 V_48 ;
T_1 V_49 ;
unsigned char V_41 [ V_43 ] ;
memcpy ( V_41 , V_44 , V_43 ) ;
F_19 ( V_41 ) ;
F_20 ( V_41 ) ;
V_46 = ( V_41 [ 5 ] >> 2 ) & 0x3f ;
V_47 = ( V_41 [ 5 ] & 0x03 ) | ( ( ( V_41 [ 4 ] & 0x7f ) ) << 2 ) ;
V_48 = ( ( V_41 [ 4 ] & 0x80 ) >> 7 ) | V_41 [ 3 ] << 1 ;
V_49 = ( V_41 [ 2 ] & 0xff ) | ( ( V_41 [ 1 ] & 1 ) << 8 ) ;
V_45 = ( V_46 << 9 ) | ( V_47 ^ V_48 ^ V_49 ) ;
V_45 = V_45 & 0x07ff ;
return V_45 ;
}
static int F_22 ( struct V_1 * V_2 ,
unsigned char * V_41 ,
T_1 V_50 , T_1 V_51 , int V_52 )
{
struct V_53 * V_54 , * V_55 ;
T_1 V_56 ;
T_1 V_57 ;
T_1 V_42 ;
V_57 = ( ( ( V_41 [ 1 ] >> 4 ) & 0xf ) << 15 )
| ( ( ( V_41 [ 1 ] >> 0 ) & 0xf ) << 11 )
| ( ( ( V_41 [ 0 ] >> 4 ) & 0xf ) << 7 )
| ( ( ( V_41 [ 0 ] >> 0 ) & 0xf ) << 3 )
| ( ( ( V_41 [ 3 ] >> 4 ) & 0x1 ) << 31 )
| ( ( ( V_41 [ 3 ] >> 0 ) & 0xf ) << 27 )
| ( ( ( V_41 [ 2 ] >> 4 ) & 0xf ) << 23 )
| ( ( ( V_41 [ 2 ] >> 0 ) & 0xf ) << 19 )
| ( V_51 << V_58 ) | ( V_50 << V_59 )
| V_60 ;
V_56 = ( ( ( V_41 [ 5 ] >> 4 ) & 0xf ) << 15 )
| ( ( ( V_41 [ 5 ] >> 0 ) & 0xf ) << 11 )
| ( ( ( V_41 [ 4 ] >> 4 ) & 0xf ) << 7 )
| ( ( ( V_41 [ 4 ] >> 0 ) & 0xf ) << 3 )
| ( ( ( V_41 [ 3 ] >> 5 ) & 0x7 ) << 0 ) ;
V_55 = V_2 -> V_61 ;
V_54 = V_55 + F_21 ( V_41 ) ;
for ( V_42 = 0 ; V_42 < V_62 ; V_42 ++ ) {
if ( ! ( F_23 ( V_54 -> V_63 ) & V_60 ) ) {
break;
} else {
if ( ( ( F_23 ( V_54 -> V_63 ) & 0xfffffff8 ) ==
( V_57 & 0xfffffff8 ) ) &&
( F_23 ( V_54 -> V_64 ) == V_56 ) ) {
break;
}
}
if ( V_54 == V_55 + 0x7ff )
V_54 = V_55 ;
else
V_54 ++ ;
}
if ( ( ( F_23 ( V_54 -> V_63 ) & 0xfffffff8 ) != ( V_57 & 0xfffffff8 ) ) &&
( F_23 ( V_54 -> V_64 ) != V_56 ) && V_52 )
return 0 ;
if ( V_42 == V_62 ) {
if ( ! V_52 ) {
F_24 ( V_2 -> V_11 ,
L_2
L_3 ,
__FILE__ ) ;
return - V_65 ;
} else
return 0 ;
}
if ( V_52 ) {
V_54 -> V_64 = 0 ;
V_54 -> V_63 = 0 ;
} else {
V_54 -> V_64 = F_25 ( V_56 ) ;
V_54 -> V_63 = F_25 ( V_57 ) ;
}
return 0 ;
}
static void F_26 ( struct V_1 * V_2 ,
unsigned char * V_66 ,
unsigned char * V_67 )
{
if ( V_66 )
F_22 ( V_2 , V_66 , 1 , 0 , V_68 ) ;
F_22 ( V_2 , V_67 , 1 , 0 , V_69 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
if ( V_2 -> V_61 == NULL ) {
V_2 -> V_61 = F_28 ( V_2 -> V_11 -> V_11 . V_70 ,
V_71 ,
& V_2 -> V_72 , V_73 ) ;
if ( V_2 -> V_61 == NULL )
return - V_74 ;
} else {
memset ( V_2 -> V_61 , 0 , V_71 ) ;
}
F_3 ( V_2 , V_75 , V_2 -> V_72 ) ;
return 0 ;
}
static void F_29 ( struct V_13 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
struct V_76 * V_77 ;
T_1 V_78 ;
V_78 = F_1 ( V_2 , V_79 ) ;
if ( V_11 -> V_80 & V_81 )
V_78 |= V_82 ;
else
V_78 &= ~ V_82 ;
F_3 ( V_2 , V_79 , V_78 ) ;
memset ( V_2 -> V_61 , 0 , V_71 ) ;
F_26 ( V_2 , NULL , V_11 -> V_83 ) ;
F_30 (ha, dev)
F_26 ( V_2 , NULL , V_77 -> V_67 ) ;
}
static void F_31 ( struct V_13 * V_11 ,
unsigned char * V_67 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
unsigned int V_84 = F_1 ( V_2 , V_85 ) ;
unsigned int V_86 = F_1 ( V_2 , V_87 ) ;
V_67 [ 0 ] = ( V_84 >> 24 ) & 0xff ;
V_67 [ 1 ] = ( V_84 >> 16 ) & 0xff ;
V_67 [ 2 ] = ( V_84 >> 8 ) & 0xff ;
V_67 [ 3 ] = V_84 & 0xff ;
V_67 [ 4 ] = ( V_86 >> 8 ) & 0xff ;
V_67 [ 5 ] = V_86 & 0xff ;
}
static int F_32 ( struct V_13 * V_11 , void * V_67 )
{
struct V_88 * V_89 = V_67 ;
struct V_1 * V_2 = F_9 ( V_11 ) ;
unsigned char V_90 [ V_43 ] ;
T_1 V_84 , V_86 ;
if ( ! F_33 ( V_89 -> V_91 ) )
return - V_92 ;
memcpy ( V_90 , V_11 -> V_83 , V_43 ) ;
memcpy ( V_11 -> V_83 , V_89 -> V_91 , V_43 ) ;
V_84 = V_11 -> V_83 [ 0 ] << 24 ;
V_84 |= V_11 -> V_83 [ 1 ] << 16 ;
V_84 |= V_11 -> V_83 [ 2 ] << 8 ;
V_84 |= V_11 -> V_83 [ 3 ] ;
V_86 = V_11 -> V_83 [ 4 ] << 8 ;
V_86 |= V_11 -> V_83 [ 5 ] ;
F_3 ( V_2 , V_85 , V_84 ) ;
F_3 ( V_2 , V_87 , V_86 ) ;
F_34 ( V_11 ) ;
F_26 ( V_2 , V_90 , V_11 -> V_83 ) ;
F_35 ( V_11 ) ;
return 0 ;
}
static void F_36 ( struct V_13 * V_11 )
{
unsigned int V_78 = 0 ;
struct V_1 * V_2 = F_9 ( V_11 ) ;
int V_93 , V_94 ;
F_37 ( V_11 -> V_95 ) ;
V_93 = V_2 -> V_96 ;
F_3 ( V_2 , V_97 ,
( T_1 ) ( V_2 -> V_98 + V_93 * sizeof( struct V_99 ) ) ) ;
V_94 = V_2 -> V_100 ;
F_3 ( V_2 , V_101 ,
( T_1 ) ( V_2 -> V_102 + V_94 * sizeof( struct V_16 ) ) ) ;
F_3 ( V_2 , V_103 ,
( T_1 ) ( V_2 -> V_102 + V_94 * sizeof( struct V_16 ) ) ) ;
F_3 ( V_2 , V_104 , 0 ) ;
F_3 ( V_2 , V_105 , V_106 ) ;
V_78 = F_1 ( V_2 , V_79 ) ;
V_78 |= V_107 ;
F_3 ( V_2 , V_79 , V_78 ) ;
V_78 = F_1 ( V_2 , V_8 ) ;
V_78 |= V_108 ;
F_3 ( V_2 , V_8 , V_78 ) ;
}
static void F_38 ( struct V_13 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
unsigned int V_78 = 0 ;
F_3 ( V_2 , V_105 , 0 ) ;
F_3 ( V_2 , V_104 , 0 ) ;
V_78 = F_1 ( V_2 , V_8 ) ;
V_78 &= ~ V_108 ;
F_5 ( V_2 ) ;
V_78 = F_1 ( V_2 , V_79 ) ;
V_78 &= ~ V_107 ;
F_3 ( V_2 , V_79 , V_78 ) ;
F_39 ( V_11 -> V_95 ) ;
}
static int F_40 ( struct V_13 * V_11 , int V_109 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
struct V_99 * V_110 ;
T_1 V_30 ;
struct V_14 * V_15 ;
int V_111 ;
T_3 V_67 ;
int V_112 ;
int V_113 = 0 ;
F_41 ( V_11 ) ;
V_2 -> V_114 &= ~ V_115 ;
while ( V_2 -> V_116 > 0 ) {
V_111 = V_2 -> V_117 ;
V_110 = & V_2 -> V_118 [ V_111 ] ;
V_30 = V_110 -> V_30 ;
if ( ! V_109 && ( V_30 & V_31 ) ) {
if ( V_113 > 0 ) {
goto V_119;
} else {
V_113 = - 1 ;
goto V_119;
}
}
V_2 -> V_117 = ( V_111 + 1 ) % V_2 -> V_120 ;
V_2 -> V_116 -- ;
V_67 = V_110 -> V_26 ;
V_112 = V_110 -> V_121 ;
V_15 = V_2 -> V_122 [ V_111 ] ;
if ( V_15 )
V_2 -> V_122 [ V_111 ] = NULL ;
if ( V_30 & V_123 ) {
if ( F_42 () )
F_7 ( V_11 , L_4 ) ;
V_11 -> V_124 . V_125 ++ ;
}
F_43 ( NULL , V_67 , V_112 , V_126 ) ;
if ( V_15 )
F_44 ( V_15 ) ;
V_113 ++ ;
}
V_119:
F_45 ( V_11 ) ;
return V_113 ;
}
static void F_46 ( struct V_13 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
F_24 ( V_11 , L_5 , V_2 -> V_116 ) ;
F_47 ( & V_2 -> V_127 ) ;
}
static void F_48 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_49 ( V_129 ,
struct V_1 ,
V_127 ) ;
struct V_13 * V_11 = V_2 -> V_11 ;
F_50 ( V_11 ) ;
F_51 ( V_11 ) ;
}
static int F_52 ( struct V_13 * V_11 , int V_130 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
struct V_131 * V_124 = & V_11 -> V_124 ;
unsigned int V_132 = 0 ;
struct V_14 * V_15 ;
while ( V_130 -- > 0 ) {
int V_133 , V_94 , V_134 ;
struct V_16 * V_16 ;
unsigned int V_30 ;
if ( V_2 -> V_33 )
break;
V_94 = V_2 -> V_100 ;
V_134 = V_2 -> V_24 ;
V_16 = & V_2 -> V_25 [ V_94 ] ;
V_30 = V_16 -> V_30 ;
F_53 () ;
if ( V_30 & ( V_31 ) )
break;
V_15 = V_2 -> V_29 [ V_94 ] ;
V_2 -> V_29 [ V_94 ] = NULL ;
V_133 = ( V_94 + 1 ) % V_2 -> V_20 ;
V_2 -> V_100 = V_133 ;
if ( V_133 == V_134 )
V_2 -> V_33 = 1 ;
V_2 -> V_19 -- ;
F_43 ( NULL , V_16 -> V_26 ,
V_16 -> V_28 ,
V_27 ) ;
V_132 ++ ;
V_124 -> V_135 ++ ;
V_124 -> V_136 += V_16 -> V_121 ;
if ( ( ( V_30 & ( V_137 | V_138 ) ) !=
( V_137 | V_138 ) )
|| ( V_30 & V_139 ) ) {
V_124 -> V_140 ++ ;
if ( ( V_30 & ( V_137 | V_138 ) ) !=
( V_137 | V_138 ) ) {
if ( F_42 () )
F_7 ( V_11 ,
L_6 ) ;
}
if ( V_30 & V_139 )
V_124 -> V_141 ++ ;
F_44 ( V_15 ) ;
} else {
F_54 ( V_15 , V_16 -> V_121 - 4 ) ;
V_15 -> V_142 = F_55 ( V_15 , V_11 ) ;
F_56 ( V_15 ) ;
}
}
F_8 ( V_11 ) ;
return V_132 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_13 * V_11 )
{
T_1 V_143 ;
int V_144 = 0 ;
V_143 = F_1 ( V_2 , V_104 ) ;
if ( V_143 == 0 )
return V_145 ;
F_3 ( V_2 , V_104 , ~ V_143 ) ;
if ( V_143 & ( V_146 | V_147 ) ) {
V_2 -> V_114 |= V_115 ;
V_144 = 1 ;
}
if ( V_143 & V_148 )
V_144 = 1 ;
return V_144 ;
}
static T_4 F_58 ( int V_149 , void * V_150 )
{
struct V_13 * V_11 = (struct V_13 * ) V_150 ;
struct V_1 * V_2 = F_9 ( V_11 ) ;
if ( F_59 ( ! F_57 ( V_2 , V_11 ) ) )
return V_145 ;
F_3 ( V_2 , V_105 , 0 ) ;
F_17 ( & V_2 -> V_39 ) ;
return V_151 ;
}
static void F_60 ( struct V_1 * V_2 )
{
int V_22 ;
V_22 = V_2 -> V_11 -> V_152 + 36 ;
V_2 -> V_22 = ( V_22 + 7 ) & ~ 7 ;
V_2 -> V_22 += V_23 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_22 ;
F_60 ( V_2 ) ;
if ( V_2 -> V_22 <= 1518 )
V_22 = V_153 ;
else if ( V_2 -> V_22 <= 1536 )
V_22 = V_154 ;
else if ( V_2 -> V_22 <= 2048 )
V_22 = V_155 ;
else
V_22 = V_156 ;
F_3 ( V_2 , V_157 ,
V_158 |
V_159 |
V_160 |
V_161 |
V_162 |
V_22 | V_163 |
V_164 ) ;
return 0 ;
}
static void F_62 ( struct V_13 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
struct V_165 * V_166 = V_11 -> V_95 ;
T_1 V_167 , V_168 = F_1 ( V_2 , V_79 ) ;
T_1 V_169 , V_170 = F_1 ( V_2 , V_157 ) ;
V_167 = V_168 & ~ V_171 ;
V_169 = V_170 & ~ ( V_172 | V_173 | V_174 ) ;
if ( V_166 -> V_175 == V_176 )
V_169 |= V_174 ;
if ( V_166 -> V_177 == V_178 )
V_169 |= V_172 ;
if ( V_166 -> V_179 )
V_167 |= V_171 ;
if ( ! V_166 -> V_180 )
V_169 |= V_173 ;
if ( V_167 == V_168 && V_169 == V_170 )
return;
F_3 ( V_2 , V_79 , V_167 ) ;
F_3 ( V_2 , V_157 , V_169 ) ;
F_63 ( V_166 ) ;
}
static int F_64 ( struct V_13 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
struct V_181 V_182 ;
struct V_165 * V_166 = NULL ;
int V_183 ;
if ( V_11 -> V_95 )
return 0 ;
V_166 = F_65 ( V_2 -> V_184 , V_2 -> V_185 ) ;
if ( F_66 ( V_166 ) )
return F_67 ( V_166 ) ;
V_183 = F_68 ( V_11 , V_166 , F_62 ,
V_2 -> V_186 ) ;
if ( V_183 )
return V_183 ;
V_182 . V_4 . V_187 = V_2 -> V_185 ;
V_182 . V_4 . V_177 = V_2 -> V_188 ;
V_182 . V_4 . V_179 = V_2 -> V_189 ;
F_69 ( V_182 . V_190 . V_191 ,
V_192 ) ;
V_182 . V_4 . V_193 = V_194 ;
if ( V_182 . V_4 . V_177 != 0 )
V_182 . V_4 . V_193 = V_195 ;
return F_70 ( V_11 , & V_182 ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
int V_183 = 0 ;
F_3 ( V_2 , V_105 , 0 ) ;
F_3 ( V_2 , V_104 , 0 ) ;
F_3 ( V_2 , V_196 , 0 ) ;
F_5 ( V_2 ) ;
V_183 = F_27 ( V_2 ) ;
if ( V_183 )
return V_183 ;
F_3 ( V_2 , V_197 , V_198 |
V_199 |
V_200 |
V_201 |
V_202 ) ;
F_3 ( V_2 , V_79 , V_203 ) ;
F_61 ( V_2 ) ;
return V_183 ;
}
static int F_72 ( struct V_13 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
struct V_16 * V_204 ;
int V_21 = 0 , V_42 = 0 ;
int V_205 = V_2 -> V_20 ;
V_2 -> V_29 = F_73 ( sizeof( * V_2 -> V_29 ) * V_2 -> V_20 ,
V_73 ) ;
if ( ! V_2 -> V_29 )
return - V_74 ;
V_2 -> V_19 = 0 ;
V_21 = V_2 -> V_20 * sizeof( struct V_16 ) ;
V_2 -> V_206 = V_21 ;
V_2 -> V_25 = F_28 ( V_2 -> V_11 -> V_11 . V_70 , V_21 ,
& V_2 -> V_102 ,
V_73 ) ;
if ( ! V_2 -> V_25 )
goto V_207;
V_204 = V_2 -> V_25 ;
for ( V_42 = 0 ; V_42 < V_205 ; V_42 ++ ) {
V_204 [ V_42 ] . V_208 = V_2 -> V_102 +
( ( V_42 + 1 ) % V_205 ) * sizeof( struct V_16 ) ;
}
V_2 -> V_100 = 0 ;
V_2 -> V_24 = 0 ;
V_2 -> V_206 = V_205 * sizeof( struct V_16 ) ;
return 0 ;
V_207:
F_74 ( V_2 -> V_29 ) ;
return - V_74 ;
}
static void F_75 ( struct V_13 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
int V_209 ;
for ( V_209 = 0 ; V_2 -> V_19 && V_209 < V_2 -> V_20 ; V_209 ++ ) {
if ( V_2 -> V_29 [ V_209 ] ) {
F_76 ( V_2 -> V_29 [ V_209 ] ) ;
V_2 -> V_19 -- ;
}
}
if ( V_2 -> V_19 )
F_7 ( V_11 , L_7 ,
V_2 -> V_19 ) ;
if ( V_2 -> V_25 )
F_77 ( V_2 -> V_11 -> V_11 . V_70 , V_2 -> V_206 ,
V_2 -> V_25 , V_2 -> V_102 ) ;
F_74 ( V_2 -> V_29 ) ;
}
static int F_78 ( struct V_13 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
struct V_99 * V_210 ;
int V_21 = 0 , V_42 = 0 ;
int V_211 = V_2 -> V_120 ;
V_2 -> V_122 = F_73 ( sizeof( * V_2 -> V_122 ) * V_2 -> V_120 ,
V_73 ) ;
if ( ! V_2 -> V_122 )
return - V_74 ;
V_2 -> V_116 = 0 ;
V_21 = V_2 -> V_120 * sizeof( struct V_99 ) ;
V_2 -> V_212 = V_21 ;
V_2 -> V_118 = F_28 ( V_2 -> V_11 -> V_11 . V_70 , V_21 ,
& V_2 -> V_98 ,
V_73 ) ;
if ( ! V_2 -> V_118 )
goto V_207;
V_210 = V_2 -> V_118 ;
for ( V_42 = 0 ; V_42 < V_211 ; V_42 ++ ) {
V_210 [ V_42 ] . V_208 = V_2 -> V_98 +
( ( V_42 + 1 ) % V_211 ) * sizeof( struct V_99 ) ;
}
V_2 -> V_96 = 0 ;
V_2 -> V_117 = 0 ;
V_2 -> V_212 = V_211 * sizeof( struct V_99 ) ;
return 0 ;
V_207:
F_74 ( V_2 -> V_122 ) ;
return - V_74 ;
}
static void F_79 ( struct V_13 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
F_40 ( V_11 , 1 ) ;
F_80 ( V_2 -> V_117 != V_2 -> V_96 ) ;
if ( V_2 -> V_118 )
F_77 ( V_2 -> V_11 -> V_11 . V_70 , V_2 -> V_212 ,
V_2 -> V_118 , V_2 -> V_98 ) ;
F_74 ( V_2 -> V_122 ) ;
}
static int F_51 ( struct V_13 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
int V_183 ;
V_183 = F_64 ( V_11 ) ;
if ( V_183 )
return V_183 ;
V_183 = F_81 ( V_11 -> V_149 , F_58 , 0 , V_11 -> V_213 , V_11 ) ;
if ( V_183 ) {
F_82 ( & V_11 -> V_11 , L_8 ) ;
return - V_214 ;
}
V_2 -> V_33 = 0 ;
V_183 = F_72 ( V_11 ) ;
if ( V_183 != 0 )
goto V_215;
V_183 = F_78 ( V_11 ) ;
if ( V_183 != 0 )
goto V_216;
V_2 -> V_24 = 0 ;
V_2 -> V_100 = 0 ;
F_8 ( V_11 ) ;
V_2 -> V_24 = 0 ;
V_2 -> V_100 = 0 ;
F_83 ( V_11 ) ;
F_84 ( & V_2 -> V_39 ) ;
F_36 ( V_11 ) ;
return 0 ;
V_216:
F_75 ( V_11 ) ;
V_215:
F_85 ( V_11 -> V_149 , V_11 ) ;
return V_183 ;
}
static int F_50 ( struct V_13 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
F_38 ( V_11 ) ;
F_3 ( V_2 , V_105 , 0 ) ;
F_3 ( V_2 , V_104 , 0 ) ;
F_3 ( V_2 , V_196 , 0 ) ;
F_86 ( & V_2 -> V_39 ) ;
F_87 ( & V_2 -> V_35 ) ;
F_83 ( V_11 ) ;
F_85 ( V_11 -> V_149 , V_11 ) ;
F_75 ( V_11 ) ;
F_79 ( V_11 ) ;
return 0 ;
}
static int F_88 ( struct V_13 * V_11 , int V_152 )
{
int V_217 ;
struct V_1 * V_2 = F_9 ( V_11 ) ;
V_11 -> V_152 = V_152 ;
V_217 = F_61 ( V_2 ) ;
if ( ! F_89 ( V_11 ) )
return 0 ;
F_50 ( V_11 ) ;
if ( F_51 ( V_11 ) ) {
F_82 ( & V_11 -> V_11 ,
L_9 ) ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
int V_218 ;
V_218 = V_2 -> V_96 ;
V_2 -> V_96 = ( V_218 + 1 ) % V_2 -> V_120 ;
F_80 ( V_2 -> V_96 == V_2 -> V_117 ) ;
V_2 -> V_116 ++ ;
return V_218 ;
}
static int F_91 ( struct V_219 * V_39 , int V_130 )
{
struct V_1 * V_2 =
F_49 ( V_39 , struct V_1 , V_39 ) ;
struct V_13 * V_11 = V_2 -> V_11 ;
int V_220 = 0 ;
F_40 ( V_11 , 0 ) ;
if ( F_92 ( V_11 )
&& V_2 -> V_120 - V_2 -> V_116 > 1 ) {
F_93 ( V_11 ) ;
}
V_220 = F_52 ( V_11 , V_130 ) ;
if ( V_220 < V_130 ) {
F_94 ( V_39 , V_220 ) ;
F_3 ( V_2 , V_105 , V_106 ) ;
}
return V_220 ;
}
static int F_95 ( struct V_14 * V_15 , struct V_13 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
struct V_131 * V_124 = & V_11 -> V_124 ;
struct V_99 * V_110 ;
int V_111 ;
int V_221 ;
V_111 = F_90 ( V_2 ) ;
V_110 = & V_2 -> V_118 [ V_111 ] ;
V_221 = V_15 -> V_222 ;
V_2 -> V_122 [ V_111 ] = V_15 ;
V_110 -> V_121 = V_221 ;
V_110 -> V_26 = F_13 ( NULL , V_15 -> V_5 , V_221 , V_126 ) ;
F_96 ( V_15 ) ;
F_14 () ;
V_110 -> V_30 = V_31 | V_223 | V_224 |
V_225 | V_226 | V_227 ;
F_97 () ;
F_3 ( V_2 , V_8 , V_228 | V_108 ) ;
V_124 -> V_229 += V_221 ;
V_124 -> V_230 ++ ;
F_98 ( V_11 ) ;
if ( V_2 -> V_120 - V_2 -> V_116 <= 1 ) {
F_99 ( V_11 ) ;
}
return V_231 ;
}
static int F_100 ( struct V_1 * V_2 )
{
int V_42 = 0 ;
for ( V_42 = 0 ; F_1 ( V_2 , V_232 ) & V_233 ; V_42 ++ ) {
if ( V_42 == V_234 )
return - V_235 ;
F_101 ( 10 ) ;
}
return 0 ;
}
static int F_102 ( struct V_236 * V_237 , int V_185 , int V_238 )
{
struct V_1 * V_2 = V_237 -> V_239 ;
int V_42 = 0 ;
int V_78 ;
if ( F_100 ( V_2 ) ) {
F_103 ( V_2 -> V_11 , L_10 ) ;
return - V_235 ;
}
F_3 ( V_2 , V_232 , ( V_185 << 16 ) | ( V_238 << 21 ) | V_240 ) ;
for ( V_42 = 0 ; ! ( ( V_78 = F_1 ( V_2 , V_232 ) ) & V_241 ) ; V_42 ++ ) {
if ( V_42 == V_234 ) {
F_103 ( V_2 -> V_11 ,
L_11 ) ;
return - V_242 ;
}
F_101 ( 10 ) ;
}
return V_78 & 0xffff ;
}
static int F_104 ( struct V_236 * V_237 , int V_185 , int V_238 ,
T_5 V_243 )
{
struct V_1 * V_2 = V_237 -> V_239 ;
if ( F_100 ( V_2 ) ) {
F_103 ( V_2 -> V_11 , L_10 ) ;
return - V_235 ;
}
F_3 ( V_2 , V_232 , ( V_185 << 16 ) | ( V_238 << 21 ) |
V_244 | ( V_243 & 0xffff ) ) ;
if ( F_100 ( V_2 ) ) {
F_7 ( V_2 -> V_11 , L_10 ) ;
return - V_235 ;
}
return 0 ;
}
static int F_105 ( struct V_13 * V_11 , struct V_245 * V_246 ,
int V_182 )
{
if ( V_11 -> V_95 != NULL )
return F_106 ( V_11 -> V_95 , V_246 , V_182 ) ;
return - V_247 ;
}
static void F_107 ( struct V_13 * V_11 ,
struct V_248 * V_249 )
{
F_108 ( V_249 -> V_250 , V_251 , sizeof( V_249 -> V_250 ) ) ;
F_108 ( V_249 -> V_252 , V_253 , sizeof( V_249 -> V_252 ) ) ;
F_108 ( V_249 -> V_254 , L_12 , sizeof( V_249 -> V_254 ) ) ;
F_108 ( V_249 -> V_255 , L_12 , sizeof( V_249 -> V_255 ) ) ;
}
static int F_109 ( struct V_256 * V_257 )
{
struct V_1 * V_2 = NULL ;
struct V_13 * V_11 = NULL ;
struct V_258 * V_259 ;
struct V_260 * V_260 ;
struct V_261 * V_262 ;
const unsigned char * V_41 = NULL ;
int V_183 ;
F_110 ( V_263 L_13 ) ;
V_260 = F_111 ( & V_257 -> V_11 , NULL ) ;
if ( F_66 ( V_260 ) ) {
F_82 ( & V_257 -> V_11 , L_14 ) ;
return - V_242 ;
}
F_112 ( V_260 ) ;
V_11 = F_113 ( sizeof( struct V_1 ) ) ;
if ( ! V_11 ) {
V_183 = - V_74 ;
goto V_264;
}
F_114 ( V_257 , V_11 ) ;
V_2 = F_9 ( V_11 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_260 = V_260 ;
V_259 = F_115 ( V_257 , V_265 , 0 ) ;
V_2 -> V_4 = F_116 ( & V_257 -> V_11 , V_259 ) ;
if ( F_66 ( V_2 -> V_4 ) ) {
V_183 = - V_74 ;
goto V_266;
}
V_259 = F_115 ( V_257 , V_267 , 0 ) ;
F_80 ( ! V_259 ) ;
V_11 -> V_149 = V_259 -> V_55 ;
V_11 -> V_268 = & V_269 ;
V_11 -> V_270 = 2 * V_38 ;
V_11 -> V_271 = 0 ;
V_11 -> V_272 = & V_273 ;
V_11 -> V_274 = V_275 ;
V_11 -> V_276 = 9500 ;
F_117 ( & V_2 -> V_127 , F_48 ) ;
if ( V_257 -> V_11 . V_277 )
V_41 = F_118 ( V_257 -> V_11 . V_277 ) ;
if ( V_41 && F_33 ( V_41 ) ) {
F_119 ( V_11 -> V_83 , V_41 ) ;
} else {
F_31 ( V_11 , V_11 -> V_83 ) ;
if ( ! F_33 ( V_11 -> V_83 ) ) {
F_120 ( & V_257 -> V_11 , L_15 ) ;
F_121 ( V_11 ) ;
}
}
V_2 -> V_20 = V_278 ;
V_2 -> V_120 = V_279 ;
V_2 -> V_280 = F_122 ( & V_257 -> V_11 ) ;
if ( V_2 -> V_280 ) {
if ( V_2 -> V_280 -> V_281 )
V_2 -> V_20 = V_2 -> V_280 -> V_281 ;
if ( V_2 -> V_280 -> V_282 )
V_2 -> V_120 = V_2 -> V_280 -> V_282 ;
V_2 -> V_283 = V_2 -> V_280 -> V_284 ;
V_2 -> V_185 = V_2 -> V_280 -> V_185 ;
V_2 -> V_188 = V_2 -> V_280 -> V_177 ;
V_2 -> V_189 = V_2 -> V_280 -> V_179 ;
V_2 -> V_186 = V_2 -> V_280 -> V_285 ;
if ( V_2 -> V_280 -> V_286 )
V_2 -> V_280 -> V_286 () ;
} else if ( V_257 -> V_11 . V_277 ) {
F_123 ( V_257 -> V_11 . V_277 , L_16 ,
& V_2 -> V_283 ) ;
V_262 = F_124 ( V_257 -> V_11 . V_277 , L_17 , 0 ) ;
if ( ! V_262 ) {
F_82 ( & V_257 -> V_11 , L_18 ) ;
V_183 = - V_287 ;
goto V_266;
}
F_123 ( V_262 , L_19 , & V_2 -> V_185 ) ;
V_2 -> V_186 = F_125 ( V_257 -> V_11 . V_277 ) ;
F_126 ( V_262 ) ;
}
F_80 ( V_2 -> V_283 > 2 ) ;
F_127 ( V_11 , & V_2 -> V_39 , F_91 , V_2 -> V_20 ) ;
memset ( & V_2 -> V_35 , 0 , sizeof( struct V_288 ) ) ;
F_128 ( & V_2 -> V_35 ) ;
V_2 -> V_35 . V_289 = F_16 ;
V_2 -> V_35 . V_5 = ( unsigned long ) V_2 ;
V_2 -> V_184 = F_129 () ;
if ( V_2 -> V_184 == NULL ) {
V_183 = - V_74 ;
goto V_266;
}
V_2 -> V_184 -> V_239 = V_2 ;
V_2 -> V_184 -> V_213 = L_20 ;
V_2 -> V_184 -> V_290 = F_102 ;
V_2 -> V_184 -> V_291 = F_104 ;
snprintf ( V_2 -> V_184 -> V_292 , V_293 , L_21 ,
V_257 -> V_213 , V_257 -> V_292 ) ;
V_2 -> V_184 -> V_70 = & V_257 -> V_11 ;
V_2 -> V_184 -> V_294 = 0xffffffff ;
V_183 = F_130 ( V_2 -> V_184 ) ;
if ( V_183 )
goto V_295;
F_131 ( V_11 , & V_257 -> V_11 ) ;
F_71 ( V_2 ) ;
V_183 = F_132 ( V_11 ) ;
if ( V_183 )
goto V_296;
return 0 ;
V_296:
F_133 ( V_2 -> V_184 ) ;
V_295:
F_134 ( V_2 -> V_184 ) ;
V_266:
F_135 ( V_11 ) ;
V_264:
F_136 ( V_260 ) ;
return V_183 ;
}
static int F_137 ( struct V_256 * V_257 )
{
struct V_13 * V_11 = F_138 ( V_257 ) ;
struct V_1 * V_2 = F_9 ( V_11 ) ;
if ( V_2 -> V_61 ) {
F_77 ( V_2 -> V_11 -> V_11 . V_70 , V_71 ,
V_2 -> V_61 , V_2 -> V_72 ) ;
V_2 -> V_61 = NULL ;
}
if ( V_11 -> V_95 )
F_139 ( V_11 -> V_95 ) ;
if ( V_2 -> V_260 ) {
F_136 ( V_2 -> V_260 ) ;
}
F_133 ( V_2 -> V_184 ) ;
F_134 ( V_2 -> V_184 ) ;
F_140 ( V_11 ) ;
F_141 ( & V_2 -> V_127 ) ;
F_135 ( V_11 ) ;
return 0 ;
}
static void F_142 ( struct V_256 * V_257 )
{
struct V_13 * V_11 = F_138 ( V_257 ) ;
F_38 ( V_11 ) ;
}
static int F_143 ( struct V_256 * V_257 )
{
return - V_297 ;
}
static int F_144 ( struct V_256 * V_257 , T_6 V_298 )
{
return - V_297 ;
}
