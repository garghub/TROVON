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
static int F_8 ( struct V_1 * V_2 )
{
unsigned int V_13 ;
V_13 = F_1 ( V_2 , V_14 ) ;
return ( V_13 >> ( 5 * V_2 -> V_15 ) ) & 0x1f ;
}
static void F_9 ( struct V_1 * V_2 , int V_16 )
{
T_1 V_13 ;
int V_17 = 5 * V_2 -> V_15 ;
V_13 = F_1 ( V_2 , V_14 ) ;
V_13 &= ~ ( 0x1f << V_17 ) ;
V_13 |= ( V_16 & 0x1f ) << V_17 ;
F_3 ( V_2 , V_14 , V_13 ) ;
}
static void F_10 ( struct V_18 * V_11 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_23 ;
while ( V_2 -> V_24 < V_2 -> V_25 ) {
int V_26 ;
V_20 = F_12 ( V_11 , V_2 -> V_27 ) ;
if ( ! V_20 )
break;
if ( V_28 )
F_13 ( V_20 , V_28 ) ;
V_2 -> V_24 ++ ;
V_23 = V_2 -> V_29 ;
V_22 = & V_2 -> V_30 [ V_23 ] ;
V_26 = F_14 ( V_20 ) - V_20 -> V_5 ;
V_22 -> V_31 = F_15 ( NULL ,
V_20 -> V_5 ,
V_26 ,
V_32 ) ;
V_22 -> V_33 = V_26 ;
V_2 -> V_34 [ V_23 ] = V_20 ;
F_16 () ;
V_22 -> V_35 = V_36 | V_37 ;
F_16 () ;
V_2 -> V_29 = ( V_23 + 1 ) % V_2 -> V_25 ;
V_2 -> V_38 = 0 ;
F_13 ( V_20 , V_39 ) ;
}
if ( V_2 -> V_24 == 0 ) {
V_2 -> V_40 . V_41 = V_42 + ( V_43 / 10 ) ;
F_17 ( & V_2 -> V_40 ) ;
}
}
static inline void F_18 ( unsigned long V_5 )
{
struct V_1 * V_2 = ( void * ) V_5 ;
F_19 ( & V_2 -> V_44 ) ;
}
static inline T_2 F_20 ( T_2 V_45 )
{
return ( ( ( V_45 ) & 0x01 ) << 3 ) | ( ( ( V_45 ) & 0x02 ) << 1 )
| ( ( ( V_45 ) & 0x04 ) >> 1 ) | ( ( ( V_45 ) & 0x08 ) >> 3 )
| ( ( ( V_45 ) & 0x10 ) << 3 ) | ( ( ( V_45 ) & 0x20 ) << 1 )
| ( ( ( V_45 ) & 0x40 ) >> 1 ) | ( ( ( V_45 ) & 0x80 ) >> 3 ) ;
}
static void F_21 ( unsigned char * V_46 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
V_46 [ V_47 ] = ( ( V_46 [ V_47 ] & 0x0f ) << 4 ) |
( ( V_46 [ V_47 ] & 0xf0 ) >> 4 ) ;
}
}
static void F_22 ( unsigned char * V_46 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ )
V_46 [ V_47 ] = F_20 ( V_46 [ V_47 ] ) ;
}
static T_1 F_23 ( unsigned char * V_49 )
{
T_1 V_50 ;
T_1 V_51 ;
T_1 V_52 ;
T_1 V_53 ;
T_1 V_54 ;
unsigned char V_46 [ V_48 ] ;
memcpy ( V_46 , V_49 , V_48 ) ;
F_21 ( V_46 ) ;
F_22 ( V_46 ) ;
V_51 = ( V_46 [ 5 ] >> 2 ) & 0x3f ;
V_52 = ( V_46 [ 5 ] & 0x03 ) | ( ( ( V_46 [ 4 ] & 0x7f ) ) << 2 ) ;
V_53 = ( ( V_46 [ 4 ] & 0x80 ) >> 7 ) | V_46 [ 3 ] << 1 ;
V_54 = ( V_46 [ 2 ] & 0xff ) | ( ( V_46 [ 1 ] & 1 ) << 8 ) ;
V_50 = ( V_51 << 9 ) | ( V_52 ^ V_53 ^ V_54 ) ;
V_50 = V_50 & 0x07ff ;
return V_50 ;
}
static int F_24 ( struct V_1 * V_2 ,
unsigned char * V_46 ,
T_1 V_55 , T_1 V_56 , int V_57 )
{
struct V_58 * V_59 , * V_60 ;
T_1 V_61 ;
T_1 V_62 ;
T_1 V_47 ;
V_62 = ( ( ( V_46 [ 1 ] >> 4 ) & 0xf ) << 15 )
| ( ( ( V_46 [ 1 ] >> 0 ) & 0xf ) << 11 )
| ( ( ( V_46 [ 0 ] >> 4 ) & 0xf ) << 7 )
| ( ( ( V_46 [ 0 ] >> 0 ) & 0xf ) << 3 )
| ( ( ( V_46 [ 3 ] >> 4 ) & 0x1 ) << 31 )
| ( ( ( V_46 [ 3 ] >> 0 ) & 0xf ) << 27 )
| ( ( ( V_46 [ 2 ] >> 4 ) & 0xf ) << 23 )
| ( ( ( V_46 [ 2 ] >> 0 ) & 0xf ) << 19 )
| ( V_56 << V_63 ) | ( V_55 << V_64 )
| V_65 ;
V_61 = ( ( ( V_46 [ 5 ] >> 4 ) & 0xf ) << 15 )
| ( ( ( V_46 [ 5 ] >> 0 ) & 0xf ) << 11 )
| ( ( ( V_46 [ 4 ] >> 4 ) & 0xf ) << 7 )
| ( ( ( V_46 [ 4 ] >> 0 ) & 0xf ) << 3 )
| ( ( ( V_46 [ 3 ] >> 5 ) & 0x7 ) << 0 ) ;
V_60 = V_2 -> V_66 ;
V_59 = V_60 + F_23 ( V_46 ) ;
for ( V_47 = 0 ; V_47 < V_67 ; V_47 ++ ) {
if ( ! ( F_25 ( V_59 -> V_68 ) & V_65 ) ) {
break;
} else {
if ( ( ( F_25 ( V_59 -> V_68 ) & 0xfffffff8 ) ==
( V_62 & 0xfffffff8 ) ) &&
( F_25 ( V_59 -> V_69 ) == V_61 ) ) {
break;
}
}
if ( V_59 == V_60 + 0x7ff )
V_59 = V_60 ;
else
V_59 ++ ;
}
if ( ( ( F_25 ( V_59 -> V_68 ) & 0xfffffff8 ) != ( V_62 & 0xfffffff8 ) ) &&
( F_25 ( V_59 -> V_69 ) != V_61 ) && V_57 )
return 0 ;
if ( V_47 == V_67 ) {
if ( ! V_57 ) {
F_26 ( V_2 -> V_11 ,
L_2
L_3 ,
__FILE__ ) ;
return - V_70 ;
} else
return 0 ;
}
if ( V_57 ) {
V_59 -> V_69 = 0 ;
V_59 -> V_68 = 0 ;
} else {
V_59 -> V_69 = F_27 ( V_61 ) ;
V_59 -> V_68 = F_27 ( V_62 ) ;
}
return 0 ;
}
static void F_28 ( struct V_1 * V_2 ,
unsigned char * V_71 ,
unsigned char * V_72 )
{
if ( V_71 )
F_24 ( V_2 , V_71 , 1 , 0 , V_73 ) ;
F_24 ( V_2 , V_72 , 1 , 0 , V_74 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_66 == NULL ) {
V_2 -> V_66 = F_30 ( V_2 -> V_11 -> V_11 . V_75 ,
V_76 ,
& V_2 -> V_77 , V_78 ) ;
if ( V_2 -> V_66 == NULL )
return - V_79 ;
} else {
memset ( V_2 -> V_66 , 0 , V_76 ) ;
}
F_3 ( V_2 , V_80 , V_2 -> V_77 ) ;
return 0 ;
}
static void F_31 ( struct V_18 * V_11 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
struct V_81 * V_82 ;
T_1 V_83 ;
V_83 = F_1 ( V_2 , V_84 ) ;
if ( V_11 -> V_85 & V_86 )
V_83 |= V_87 ;
else
V_83 &= ~ V_87 ;
F_3 ( V_2 , V_84 , V_83 ) ;
memset ( V_2 -> V_66 , 0 , V_76 ) ;
F_28 ( V_2 , NULL , V_11 -> V_88 ) ;
F_32 (ha, dev)
F_28 ( V_2 , NULL , V_82 -> V_72 ) ;
}
static void F_33 ( struct V_18 * V_11 ,
unsigned char * V_72 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
unsigned int V_89 = F_1 ( V_2 , V_90 ) ;
unsigned int V_91 = F_1 ( V_2 , V_92 ) ;
V_72 [ 0 ] = ( V_89 >> 24 ) & 0xff ;
V_72 [ 1 ] = ( V_89 >> 16 ) & 0xff ;
V_72 [ 2 ] = ( V_89 >> 8 ) & 0xff ;
V_72 [ 3 ] = V_89 & 0xff ;
V_72 [ 4 ] = ( V_91 >> 8 ) & 0xff ;
V_72 [ 5 ] = V_91 & 0xff ;
}
static int F_34 ( struct V_18 * V_11 , void * V_72 )
{
struct V_93 * V_94 = V_72 ;
struct V_1 * V_2 = F_11 ( V_11 ) ;
unsigned char V_95 [ V_48 ] ;
T_1 V_89 , V_91 ;
if ( ! F_35 ( V_94 -> V_96 ) )
return - V_97 ;
memcpy ( V_95 , V_11 -> V_88 , V_48 ) ;
memcpy ( V_11 -> V_88 , V_94 -> V_96 , V_48 ) ;
V_89 = V_11 -> V_88 [ 0 ] << 24 ;
V_89 |= V_11 -> V_88 [ 1 ] << 16 ;
V_89 |= V_11 -> V_88 [ 2 ] << 8 ;
V_89 |= V_11 -> V_88 [ 3 ] ;
V_91 = V_11 -> V_88 [ 4 ] << 8 ;
V_91 |= V_11 -> V_88 [ 5 ] ;
F_3 ( V_2 , V_90 , V_89 ) ;
F_3 ( V_2 , V_92 , V_91 ) ;
F_36 ( V_11 ) ;
F_28 ( V_2 , V_95 , V_11 -> V_88 ) ;
F_37 ( V_11 ) ;
return 0 ;
}
static void F_38 ( struct V_18 * V_11 )
{
unsigned int V_83 = 0 ;
struct V_1 * V_2 = F_11 ( V_11 ) ;
int V_98 , V_99 ;
if ( V_2 -> V_100 != NULL ) {
struct V_101 V_102 ;
F_39 ( V_2 -> V_11 , & V_102 ) ;
F_40 ( V_2 -> V_100 ) ;
F_41 ( V_2 -> V_11 , & V_102 ) ;
}
V_98 = V_2 -> V_103 ;
F_3 ( V_2 , V_104 ,
( T_1 ) ( V_2 -> V_105 + V_98 * sizeof( struct V_106 ) ) ) ;
V_99 = V_2 -> V_107 ;
F_3 ( V_2 , V_108 ,
( T_1 ) ( V_2 -> V_109 + V_99 * sizeof( struct V_21 ) ) ) ;
F_3 ( V_2 , V_110 ,
( T_1 ) ( V_2 -> V_109 + V_99 * sizeof( struct V_21 ) ) ) ;
F_3 ( V_2 , V_111 , 0 ) ;
F_3 ( V_2 , V_112 , V_113 ) ;
V_83 = F_1 ( V_2 , V_84 ) ;
V_83 |= V_114 ;
F_3 ( V_2 , V_84 , V_83 ) ;
V_83 = F_1 ( V_2 , V_8 ) ;
V_83 |= V_115 ;
F_3 ( V_2 , V_8 , V_83 ) ;
}
static void F_42 ( struct V_18 * V_11 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
unsigned int V_83 = 0 ;
F_3 ( V_2 , V_112 , 0 ) ;
F_3 ( V_2 , V_111 , 0 ) ;
V_83 = F_1 ( V_2 , V_8 ) ;
V_83 &= ~ V_115 ;
F_5 ( V_2 ) ;
V_83 = F_1 ( V_2 , V_84 ) ;
V_83 &= ~ V_114 ;
F_3 ( V_2 , V_84 , V_83 ) ;
}
static int F_43 ( struct V_18 * V_11 , int V_116 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
struct V_106 * V_117 ;
T_1 V_35 ;
struct V_19 * V_20 ;
int V_118 ;
T_3 V_72 ;
int V_119 ;
int V_120 = 0 ;
F_44 ( V_11 ) ;
V_2 -> V_121 &= ~ V_122 ;
while ( V_2 -> V_123 > 0 ) {
V_118 = V_2 -> V_124 ;
V_117 = & V_2 -> V_125 [ V_118 ] ;
V_35 = V_117 -> V_35 ;
if ( ! V_116 && ( V_35 & V_36 ) ) {
if ( V_120 > 0 ) {
goto V_126;
} else {
V_120 = - 1 ;
goto V_126;
}
}
V_2 -> V_124 = ( V_118 + 1 ) % V_2 -> V_127 ;
V_2 -> V_123 -- ;
V_72 = V_117 -> V_31 ;
V_119 = V_117 -> V_128 ;
V_20 = V_2 -> V_129 [ V_118 ] ;
if ( V_20 )
V_2 -> V_129 [ V_118 ] = NULL ;
if ( V_35 & V_130 ) {
if ( F_45 () )
F_7 ( V_11 , L_4 ) ;
V_11 -> V_131 . V_132 ++ ;
}
F_46 ( NULL , V_72 , V_119 , V_133 ) ;
if ( V_20 )
F_47 ( V_20 ) ;
V_120 ++ ;
}
V_126:
F_48 ( V_11 ) ;
return V_120 ;
}
static void F_49 ( struct V_18 * V_11 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
F_26 ( V_11 , L_5 , V_2 -> V_123 ) ;
F_50 ( & V_2 -> V_134 ) ;
}
static void F_51 ( struct V_135 * V_136 )
{
struct V_1 * V_2 = F_52 ( V_136 ,
struct V_1 ,
V_134 ) ;
struct V_18 * V_11 = V_2 -> V_11 ;
F_53 ( V_11 ) ;
F_54 ( V_11 ) ;
}
static int F_55 ( struct V_18 * V_11 , int V_137 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
struct V_138 * V_131 = & V_11 -> V_131 ;
unsigned int V_139 = 0 ;
struct V_19 * V_20 ;
while ( V_137 -- > 0 ) {
int V_140 , V_99 , V_141 ;
struct V_21 * V_21 ;
unsigned int V_35 ;
if ( V_2 -> V_38 )
break;
V_99 = V_2 -> V_107 ;
V_141 = V_2 -> V_29 ;
V_21 = & V_2 -> V_30 [ V_99 ] ;
V_35 = V_21 -> V_35 ;
F_56 () ;
if ( V_35 & ( V_36 ) )
break;
V_20 = V_2 -> V_34 [ V_99 ] ;
V_2 -> V_34 [ V_99 ] = NULL ;
V_140 = ( V_99 + 1 ) % V_2 -> V_25 ;
V_2 -> V_107 = V_140 ;
if ( V_140 == V_141 )
V_2 -> V_38 = 1 ;
V_2 -> V_24 -- ;
F_46 ( NULL , V_21 -> V_31 ,
V_21 -> V_33 ,
V_32 ) ;
V_139 ++ ;
V_131 -> V_142 ++ ;
V_131 -> V_143 += V_21 -> V_128 ;
if ( ( ( V_35 & ( V_144 | V_145 ) ) !=
( V_144 | V_145 ) )
|| ( V_35 & V_146 ) ) {
V_131 -> V_147 ++ ;
if ( ( V_35 & ( V_144 | V_145 ) ) !=
( V_144 | V_145 ) ) {
if ( F_45 () )
F_7 ( V_11 ,
L_6 ) ;
}
if ( V_35 & V_146 )
V_131 -> V_148 ++ ;
F_47 ( V_20 ) ;
} else {
F_57 ( V_20 , V_21 -> V_128 - 4 ) ;
V_20 -> V_149 = F_58 ( V_20 , V_11 ) ;
F_59 ( V_20 ) ;
}
}
F_10 ( V_11 ) ;
return V_139 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_18 * V_11 )
{
T_1 V_150 ;
int V_151 = 0 ;
V_150 = F_1 ( V_2 , V_111 ) ;
if ( V_150 == 0 )
return V_152 ;
F_3 ( V_2 , V_111 , ~ V_150 ) ;
if ( V_150 & ( V_153 | V_154 ) ) {
V_2 -> V_121 |= V_122 ;
V_151 = 1 ;
}
if ( V_150 & V_155 )
V_151 = 1 ;
if ( V_150 & V_156 ) {
V_2 -> V_121 |= V_157 ;
V_151 = 1 ;
}
return V_151 ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_18 * V_11 = V_2 -> V_11 ;
T_1 V_158 ;
int V_159 ;
int V_160 ;
int V_161 ;
V_158 = F_1 ( V_2 , V_162 ) ;
if ( ! ( V_158 & V_163 ) ) {
if ( F_62 ( V_11 ) ) {
F_26 ( V_11 , L_7 ) ;
F_63 ( V_11 ) ;
F_43 ( V_11 , 1 ) ;
}
return;
}
if ( V_158 & V_164 )
V_159 = 100 ;
else
V_159 = 10 ;
V_160 = ( V_158 & V_165 ) ? 1 : 0 ;
V_161 = ( V_158 & V_166 ) ? 0 : 1 ;
F_26 ( V_11 , L_8 ,
V_159 , V_160 ? L_9 : L_10 , V_161 ? L_11 : L_12 ) ;
if ( ! F_62 ( V_11 ) )
F_64 ( V_11 ) ;
}
static T_4 F_65 ( int V_167 , void * V_168 )
{
struct V_18 * V_11 = (struct V_18 * ) V_168 ;
struct V_1 * V_2 = F_11 ( V_11 ) ;
if ( F_66 ( ! F_60 ( V_2 , V_11 ) ) )
return V_152 ;
F_3 ( V_2 , V_112 , 0 ) ;
F_19 ( & V_2 -> V_44 ) ;
return V_169 ;
}
static void F_67 ( struct V_1 * V_2 )
{
int V_27 ;
V_27 = V_2 -> V_11 -> V_170 + 36 ;
V_2 -> V_27 = ( V_27 + 7 ) & ~ 7 ;
V_2 -> V_27 += V_28 ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_27 ;
F_67 ( V_2 ) ;
if ( V_2 -> V_27 <= 1518 )
V_27 = V_171 ;
else if ( V_2 -> V_27 <= 1536 )
V_27 = V_172 ;
else if ( V_2 -> V_27 <= 2048 )
V_27 = V_173 ;
else
V_27 = V_174 ;
F_3 ( V_2 ,
V_175 , V_176 |
V_177 |
V_27 | V_178 |
V_179 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
int V_180 = 0 ;
F_3 ( V_2 , V_112 , 0 ) ;
F_3 ( V_2 , V_111 , 0 ) ;
F_3 ( V_2 , V_181 , 0 ) ;
F_5 ( V_2 ) ;
V_180 = F_29 ( V_2 ) ;
if ( V_180 )
return V_180 ;
F_3 ( V_2 , V_182 , V_183 |
V_184 |
V_185 |
V_186 |
V_187 ) ;
F_3 ( V_2 , V_84 , V_188 ) ;
F_68 ( V_2 ) ;
return V_180 ;
}
static int F_70 ( struct V_18 * V_11 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
struct V_21 * V_189 ;
int V_26 = 0 , V_47 = 0 ;
int V_190 = V_2 -> V_25 ;
V_2 -> V_34 = F_71 ( sizeof( * V_2 -> V_34 ) * V_2 -> V_25 ,
V_78 ) ;
if ( ! V_2 -> V_34 )
return - V_79 ;
V_2 -> V_24 = 0 ;
V_26 = V_2 -> V_25 * sizeof( struct V_21 ) ;
V_2 -> V_191 = V_26 ;
V_2 -> V_30 = F_30 ( V_2 -> V_11 -> V_11 . V_75 , V_26 ,
& V_2 -> V_109 ,
V_78 ) ;
if ( ! V_2 -> V_30 )
goto V_192;
V_189 = V_2 -> V_30 ;
for ( V_47 = 0 ; V_47 < V_190 ; V_47 ++ ) {
V_189 [ V_47 ] . V_193 = V_2 -> V_109 +
( ( V_47 + 1 ) % V_190 ) * sizeof( struct V_21 ) ;
}
V_2 -> V_107 = 0 ;
V_2 -> V_29 = 0 ;
V_2 -> V_191 = V_190 * sizeof( struct V_21 ) ;
return 0 ;
V_192:
F_72 ( V_2 -> V_34 ) ;
return - V_79 ;
}
static void F_73 ( struct V_18 * V_11 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
int V_194 ;
for ( V_194 = 0 ; V_2 -> V_24 && V_194 < V_2 -> V_25 ; V_194 ++ ) {
if ( V_2 -> V_34 [ V_194 ] ) {
F_74 ( V_2 -> V_34 [ V_194 ] ) ;
V_2 -> V_24 -- ;
}
}
if ( V_2 -> V_24 )
F_7 ( V_11 , L_13 ,
V_2 -> V_24 ) ;
if ( V_2 -> V_30 )
F_75 ( V_2 -> V_11 -> V_11 . V_75 , V_2 -> V_191 ,
V_2 -> V_30 , V_2 -> V_109 ) ;
F_72 ( V_2 -> V_34 ) ;
}
static int F_76 ( struct V_18 * V_11 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
struct V_106 * V_195 ;
int V_26 = 0 , V_47 = 0 ;
int V_196 = V_2 -> V_127 ;
V_2 -> V_129 = F_71 ( sizeof( * V_2 -> V_129 ) * V_2 -> V_127 ,
V_78 ) ;
if ( ! V_2 -> V_129 )
return - V_79 ;
V_2 -> V_123 = 0 ;
V_26 = V_2 -> V_127 * sizeof( struct V_106 ) ;
V_2 -> V_197 = V_26 ;
V_2 -> V_125 = F_30 ( V_2 -> V_11 -> V_11 . V_75 , V_26 ,
& V_2 -> V_105 ,
V_78 ) ;
if ( ! V_2 -> V_125 )
goto V_192;
V_195 = V_2 -> V_125 ;
for ( V_47 = 0 ; V_47 < V_196 ; V_47 ++ ) {
V_195 [ V_47 ] . V_193 = V_2 -> V_105 +
( ( V_47 + 1 ) % V_196 ) * sizeof( struct V_106 ) ;
}
V_2 -> V_103 = 0 ;
V_2 -> V_124 = 0 ;
V_2 -> V_197 = V_196 * sizeof( struct V_106 ) ;
return 0 ;
V_192:
F_72 ( V_2 -> V_129 ) ;
return - V_79 ;
}
static void F_77 ( struct V_18 * V_11 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
F_43 ( V_11 , 1 ) ;
F_78 ( V_2 -> V_124 != V_2 -> V_103 ) ;
if ( V_2 -> V_125 )
F_75 ( V_2 -> V_11 -> V_11 . V_75 , V_2 -> V_197 ,
V_2 -> V_125 , V_2 -> V_105 ) ;
F_72 ( V_2 -> V_129 ) ;
}
static int F_54 ( struct V_18 * V_11 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
int V_180 ;
V_180 = F_79 ( V_11 -> V_167 , F_65 , 0 , V_11 -> V_198 , V_11 ) ;
if ( V_180 ) {
F_80 ( & V_11 -> V_11 , L_14 ) ;
return - V_199 ;
}
V_2 -> V_38 = 0 ;
V_180 = F_70 ( V_11 ) ;
if ( V_180 != 0 )
goto V_200;
V_180 = F_76 ( V_11 ) ;
if ( V_180 != 0 )
goto V_201;
V_2 -> V_29 = 0 ;
V_2 -> V_107 = 0 ;
F_10 ( V_11 ) ;
V_2 -> V_29 = 0 ;
V_2 -> V_107 = 0 ;
F_63 ( V_11 ) ;
F_38 ( V_11 ) ;
F_81 ( & V_2 -> V_44 ) ;
return 0 ;
V_201:
F_73 ( V_11 ) ;
V_200:
F_82 ( V_11 -> V_167 , V_11 ) ;
return V_180 ;
}
static int F_53 ( struct V_18 * V_11 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
F_42 ( V_11 ) ;
F_3 ( V_2 , V_112 , 0 ) ;
F_3 ( V_2 , V_111 , 0 ) ;
F_3 ( V_2 , V_181 , 0 ) ;
F_83 ( & V_2 -> V_44 ) ;
F_84 ( & V_2 -> V_40 ) ;
F_63 ( V_11 ) ;
F_82 ( V_11 -> V_167 , V_11 ) ;
F_73 ( V_11 ) ;
F_77 ( V_11 ) ;
return 0 ;
}
static int F_85 ( struct V_18 * V_11 , int V_170 )
{
int V_202 ;
struct V_1 * V_2 = F_11 ( V_11 ) ;
if ( ( V_170 > 9500 ) || ( V_170 < 68 ) )
return - V_203 ;
V_11 -> V_170 = V_170 ;
V_202 = F_68 ( V_2 ) ;
if ( ! F_86 ( V_11 ) )
return 0 ;
F_53 ( V_11 ) ;
if ( F_54 ( V_11 ) ) {
F_80 ( & V_11 -> V_11 ,
L_15 ) ;
}
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
int V_204 ;
V_204 = V_2 -> V_103 ;
V_2 -> V_103 = ( V_204 + 1 ) % V_2 -> V_127 ;
F_78 ( V_2 -> V_103 == V_2 -> V_124 ) ;
V_2 -> V_123 ++ ;
return V_204 ;
}
static int F_88 ( struct V_205 * V_44 , int V_137 )
{
struct V_1 * V_2 =
F_52 ( V_44 , struct V_1 , V_44 ) ;
struct V_18 * V_11 = V_2 -> V_11 ;
int V_206 = 0 ;
if ( F_66 ( V_2 -> V_121 & V_157 ) ) {
V_2 -> V_121 &= ~ ( V_157 ) ;
F_61 ( V_2 ) ;
}
F_43 ( V_11 , 0 ) ;
if ( F_89 ( V_11 )
&& V_2 -> V_127 - V_2 -> V_123 > 1 ) {
F_90 ( V_11 ) ;
}
V_206 = F_55 ( V_11 , V_137 ) ;
if ( V_206 < V_137 ) {
F_91 ( V_44 ) ;
F_3 ( V_2 , V_112 , V_113 ) ;
}
return V_206 ;
}
static int F_92 ( struct V_19 * V_20 , struct V_18 * V_11 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
struct V_138 * V_131 = & V_11 -> V_131 ;
struct V_106 * V_117 ;
int V_118 ;
int V_207 ;
V_118 = F_87 ( V_2 ) ;
V_117 = & V_2 -> V_125 [ V_118 ] ;
V_207 = V_20 -> V_208 ;
V_2 -> V_129 [ V_118 ] = V_20 ;
V_117 -> V_128 = V_207 ;
V_117 -> V_31 = F_15 ( NULL , V_20 -> V_5 , V_207 , V_133 ) ;
F_93 ( V_20 ) ;
F_16 () ;
V_117 -> V_35 = V_36 | V_209 | V_210 |
V_211 | V_212 | V_213 ;
F_16 () ;
F_3 ( V_2 , V_8 , V_214 | V_115 ) ;
V_131 -> V_215 += V_207 ;
V_131 -> V_216 ++ ;
V_11 -> V_217 = V_42 ;
if ( V_2 -> V_127 - V_2 -> V_123 <= 1 ) {
F_94 ( V_11 ) ;
}
return V_218 ;
}
static int F_95 ( struct V_1 * V_2 )
{
int V_47 = 0 ;
for ( V_47 = 0 ; F_1 ( V_2 , V_219 ) & V_220 ; V_47 ++ ) {
if ( V_47 == V_221 )
return - V_222 ;
F_96 ( 10 ) ;
}
return 0 ;
}
static int F_97 ( struct V_223 * V_224 , int V_16 , int V_225 )
{
struct V_1 * V_2 = V_224 -> V_226 ;
int V_47 = 0 ;
int V_83 ;
if ( F_95 ( V_2 ) ) {
F_98 ( V_2 -> V_11 , L_16 ) ;
return - V_222 ;
}
F_3 ( V_2 , V_219 , ( V_16 << 16 ) | ( V_225 << 21 ) | V_227 ) ;
for ( V_47 = 0 ; ! ( ( V_83 = F_1 ( V_2 , V_219 ) ) & V_228 ) ; V_47 ++ ) {
if ( V_47 == V_221 ) {
F_98 ( V_2 -> V_11 ,
L_17 ) ;
return - V_229 ;
}
F_96 ( 10 ) ;
}
return V_83 & 0xffff ;
}
static int F_99 ( struct V_223 * V_224 , int V_16 , int V_225 ,
T_5 V_230 )
{
struct V_1 * V_2 = V_224 -> V_226 ;
if ( F_95 ( V_2 ) ) {
F_98 ( V_2 -> V_11 , L_16 ) ;
return - V_222 ;
}
F_3 ( V_2 , V_219 , ( V_16 << 16 ) | ( V_225 << 21 ) |
V_231 | ( V_230 & 0xffff ) ) ;
if ( F_95 ( V_2 ) ) {
F_7 ( V_2 -> V_11 , L_16 ) ;
return - V_222 ;
}
return 0 ;
}
static int F_100 ( struct V_18 * V_11 , struct V_232 * V_233 ,
int V_102 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
if ( V_2 -> V_100 != NULL )
return F_101 ( V_2 -> V_100 , V_233 , V_102 ) ;
return - V_234 ;
}
static struct V_235 * F_102 ( struct V_1 * V_2 , int V_16 )
{
struct V_223 * V_224 = V_2 -> V_236 ;
struct V_235 * V_237 ;
int V_60 ;
int V_238 ;
int V_47 ;
if ( V_16 == V_239 ) {
V_60 = F_8 ( V_2 ) ;
V_238 = 32 ;
} else {
V_60 = V_16 & 0x1f ;
V_238 = 1 ;
}
V_237 = NULL ;
for ( V_47 = 0 ; V_47 < V_238 ; V_47 ++ ) {
int V_72 = ( V_60 + V_47 ) & 0x1f ;
if ( V_224 -> V_240 [ V_72 ] == NULL )
F_103 ( V_224 , V_72 ) ;
if ( V_237 == NULL ) {
V_237 = V_224 -> V_240 [ V_72 ] ;
if ( V_237 != NULL )
F_9 ( V_2 , V_72 ) ;
}
}
return V_237 ;
}
static void F_104 ( struct V_1 * V_2 )
{
struct V_235 * V_100 = V_2 -> V_100 ;
F_105 ( V_2 -> V_11 , F_106 ( & V_100 -> V_11 ) , V_241 ) ;
if ( V_2 -> V_242 && V_2 -> V_242 -> V_159 != 0 ) {
V_100 -> V_243 = V_244 ;
V_100 -> V_245 = 0 ;
V_100 -> V_159 = V_2 -> V_242 -> V_159 ;
V_100 -> V_160 = V_2 -> V_242 -> V_160 ;
} else {
V_100 -> V_243 = V_246 ;
V_100 -> V_159 = 0 ;
V_100 -> V_160 = 0 ;
V_100 -> V_247 &= V_248 ;
V_100 -> V_245 = V_100 -> V_247 | V_249 ;
}
F_107 ( V_100 ) ;
}
static int F_108 ( struct V_18 * V_11 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
if ( V_2 -> V_242 && V_2 -> V_242 -> V_250 )
V_2 -> V_242 -> V_250 () ;
V_2 -> V_100 = F_102 ( V_2 , V_2 -> V_16 & 0x1f ) ;
if ( V_2 -> V_100 != NULL )
F_104 ( V_2 ) ;
F_28 ( V_2 , NULL , V_11 -> V_88 ) ;
return 0 ;
}
static int F_39 ( struct V_18 * V_11 , struct V_101 * V_102 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
int V_180 ;
V_180 = F_109 ( V_2 -> V_100 ) ;
if ( V_180 == 0 )
V_180 = F_110 ( V_2 -> V_100 , V_102 ) ;
return V_180 ;
}
static int F_41 ( struct V_18 * V_11 , struct V_101 * V_102 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
return F_111 ( V_2 -> V_100 , V_102 ) ;
}
static void F_112 ( struct V_18 * V_11 ,
struct V_251 * V_252 )
{
F_113 ( V_252 -> V_253 , V_254 , sizeof( V_252 -> V_253 ) ) ;
F_113 ( V_252 -> V_255 , V_256 , sizeof( V_252 -> V_255 ) ) ;
F_113 ( V_252 -> V_257 , L_18 , sizeof( V_252 -> V_257 ) ) ;
F_113 ( V_252 -> V_258 , L_18 , sizeof( V_252 -> V_258 ) ) ;
}
static int F_114 ( struct V_259 * V_260 )
{
struct V_1 * V_2 = NULL ;
struct V_18 * V_11 = NULL ;
struct V_261 * V_262 ;
struct V_263 * V_263 ;
struct V_264 * V_265 ;
const unsigned char * V_46 = NULL ;
int V_180 ;
F_115 ( V_266 L_19 ) ;
V_263 = F_116 ( & V_260 -> V_11 , NULL ) ;
if ( F_117 ( V_263 ) ) {
F_80 ( & V_260 -> V_11 , L_20 ) ;
return - V_229 ;
}
F_118 ( V_263 ) ;
V_11 = F_119 ( sizeof( struct V_1 ) ) ;
if ( ! V_11 ) {
V_180 = - V_79 ;
goto V_267;
}
F_120 ( V_260 , V_11 ) ;
V_2 = F_11 ( V_11 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_263 = V_263 ;
V_262 = F_121 ( V_260 , V_268 , 0 ) ;
if ( V_262 == NULL ) {
V_180 = - V_229 ;
goto V_269;
}
V_2 -> V_4 = F_122 ( & V_260 -> V_11 , V_262 ) ;
if ( F_117 ( V_2 -> V_4 ) ) {
V_180 = - V_79 ;
goto V_269;
}
V_262 = F_121 ( V_260 , V_270 , 0 ) ;
F_78 ( ! V_262 ) ;
V_11 -> V_167 = V_262 -> V_60 ;
V_11 -> V_271 = & V_272 ;
V_11 -> V_273 = 2 * V_43 ;
V_11 -> V_274 = 0 ;
V_11 -> V_275 = & V_276 ;
F_123 ( & V_2 -> V_134 , F_51 ) ;
if ( V_260 -> V_11 . V_277 )
V_46 = F_124 ( V_260 -> V_11 . V_277 ) ;
if ( V_46 && F_35 ( V_46 ) ) {
F_125 ( V_11 -> V_88 , V_46 ) ;
} else {
F_33 ( V_11 , V_11 -> V_88 ) ;
if ( ! F_35 ( V_11 -> V_88 ) ) {
F_126 ( & V_260 -> V_11 , L_21 ) ;
F_127 ( V_11 ) ;
}
}
V_2 -> V_25 = V_278 ;
V_2 -> V_127 = V_279 ;
V_2 -> V_242 = F_128 ( & V_260 -> V_11 ) ;
if ( V_2 -> V_242 ) {
if ( V_2 -> V_242 -> V_280 )
V_2 -> V_25 = V_2 -> V_242 -> V_280 ;
if ( V_2 -> V_242 -> V_281 )
V_2 -> V_127 = V_2 -> V_242 -> V_281 ;
V_2 -> V_15 = V_2 -> V_242 -> V_282 ;
V_2 -> V_16 = V_2 -> V_242 -> V_16 ;
} else if ( V_260 -> V_11 . V_277 ) {
F_129 ( V_260 -> V_11 . V_277 , L_22 ,
& V_2 -> V_15 ) ;
V_265 = F_130 ( V_260 -> V_11 . V_277 , L_23 , 0 ) ;
if ( V_265 )
F_129 ( V_265 , L_24 , & V_2 -> V_16 ) ;
}
F_78 ( V_2 -> V_15 > 2 ) ;
F_131 ( V_11 , & V_2 -> V_44 , F_88 , V_2 -> V_25 ) ;
memset ( & V_2 -> V_40 , 0 , sizeof( struct V_283 ) ) ;
F_132 ( & V_2 -> V_40 ) ;
V_2 -> V_40 . V_284 = F_18 ;
V_2 -> V_40 . V_5 = ( unsigned long ) V_2 ;
V_2 -> V_236 = F_133 () ;
if ( V_2 -> V_236 == NULL ) {
V_180 = - V_79 ;
goto V_285;
}
V_2 -> V_236 -> V_226 = V_2 ;
V_2 -> V_236 -> V_198 = L_25 ;
V_2 -> V_236 -> V_286 = F_97 ;
V_2 -> V_236 -> V_287 = F_99 ;
snprintf ( V_2 -> V_236 -> V_288 , V_289 , L_26 ,
V_260 -> V_198 , V_260 -> V_288 ) ;
V_2 -> V_236 -> V_75 = & V_260 -> V_11 ;
V_2 -> V_236 -> V_290 = 0xffffffff ;
V_180 = F_134 ( V_2 -> V_236 ) ;
if ( V_180 )
goto V_291;
F_69 ( V_2 ) ;
V_180 = F_108 ( V_11 ) ;
if ( V_180 )
goto V_292;
F_135 ( V_11 , & V_260 -> V_11 ) ;
V_180 = F_136 ( V_11 ) ;
if ( V_180 )
goto V_292;
return 0 ;
V_292:
F_137 ( V_2 -> V_236 ) ;
V_291:
F_138 ( V_2 -> V_236 ) ;
V_285:
F_139 ( V_2 -> V_4 ) ;
V_269:
F_140 ( V_11 ) ;
V_267:
F_141 ( V_263 ) ;
F_142 ( V_263 ) ;
return V_180 ;
}
static int F_143 ( struct V_259 * V_260 )
{
struct V_18 * V_11 = F_144 ( V_260 ) ;
struct V_1 * V_2 = F_11 ( V_11 ) ;
if ( V_2 -> V_66 ) {
F_75 ( V_2 -> V_11 -> V_11 . V_75 , V_76 ,
V_2 -> V_66 , V_2 -> V_77 ) ;
V_2 -> V_66 = NULL ;
}
if ( V_2 -> V_263 ) {
F_141 ( V_2 -> V_263 ) ;
F_142 ( V_2 -> V_263 ) ;
V_2 -> V_263 = NULL ;
}
if ( V_2 -> V_100 != NULL )
F_145 ( V_2 -> V_100 ) ;
F_139 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
F_137 ( V_2 -> V_236 ) ;
F_138 ( V_2 -> V_236 ) ;
F_146 ( V_11 ) ;
F_147 ( & V_2 -> V_134 ) ;
F_140 ( V_11 ) ;
return 0 ;
}
static void F_148 ( struct V_259 * V_260 )
{
struct V_18 * V_11 = F_144 ( V_260 ) ;
F_42 ( V_11 ) ;
}
static int F_149 ( struct V_259 * V_260 )
{
return - V_293 ;
}
static int F_150 ( struct V_259 * V_260 , T_6 V_294 )
{
return - V_293 ;
}
