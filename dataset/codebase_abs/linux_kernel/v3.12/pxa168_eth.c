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
F_7 ( V_11 L_1 , V_12 ) ;
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
static void F_10 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_11 ( V_2 -> V_18 , V_19 ) ;
if ( V_5 < 0 )
return;
V_5 |= V_20 ;
if ( F_12 ( V_2 -> V_18 , V_19 , V_5 ) < 0 )
return;
do {
V_5 = F_11 ( V_2 -> V_18 , V_19 ) ;
} while ( V_5 >= 0 && V_5 & V_20 );
}
static void F_13 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
int V_27 ;
while ( V_2 -> V_28 < V_2 -> V_29 ) {
int V_30 ;
V_24 = F_15 ( V_22 , V_2 -> V_31 ) ;
if ( ! V_24 )
break;
if ( V_32 )
F_16 ( V_24 , V_32 ) ;
V_2 -> V_28 ++ ;
V_27 = V_2 -> V_33 ;
V_26 = & V_2 -> V_34 [ V_27 ] ;
V_30 = F_17 ( V_24 ) - V_24 -> V_5 ;
V_26 -> V_35 = F_18 ( NULL ,
V_24 -> V_5 ,
V_30 ,
V_36 ) ;
V_26 -> V_37 = V_30 ;
V_2 -> V_38 [ V_27 ] = V_24 ;
F_19 () ;
V_26 -> V_39 = V_40 | V_41 ;
F_19 () ;
V_2 -> V_33 = ( V_27 + 1 ) % V_2 -> V_29 ;
V_2 -> V_42 = 0 ;
F_16 ( V_24 , V_43 ) ;
}
if ( V_2 -> V_28 == 0 ) {
V_2 -> V_44 . V_45 = V_46 + ( V_47 / 10 ) ;
F_20 ( & V_2 -> V_44 ) ;
}
}
static inline void F_21 ( unsigned long V_5 )
{
struct V_1 * V_2 = ( void * ) V_5 ;
F_22 ( & V_2 -> V_48 ) ;
}
static inline T_2 F_23 ( T_2 V_49 )
{
return ( ( ( V_49 ) & 0x01 ) << 3 ) | ( ( ( V_49 ) & 0x02 ) << 1 )
| ( ( ( V_49 ) & 0x04 ) >> 1 ) | ( ( ( V_49 ) & 0x08 ) >> 3 )
| ( ( ( V_49 ) & 0x10 ) << 3 ) | ( ( ( V_49 ) & 0x20 ) << 1 )
| ( ( ( V_49 ) & 0x40 ) >> 1 ) | ( ( ( V_49 ) & 0x80 ) >> 3 ) ;
}
static void F_24 ( unsigned char * V_50 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ ) {
V_50 [ V_51 ] = ( ( V_50 [ V_51 ] & 0x0f ) << 4 ) |
( ( V_50 [ V_51 ] & 0xf0 ) >> 4 ) ;
}
}
static void F_25 ( unsigned char * V_50 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ )
V_50 [ V_51 ] = F_23 ( V_50 [ V_51 ] ) ;
}
static T_1 F_26 ( unsigned char * V_53 )
{
T_1 V_54 ;
T_1 V_55 ;
T_1 V_56 ;
T_1 V_57 ;
T_1 V_58 ;
unsigned char V_50 [ V_52 ] ;
memcpy ( V_50 , V_53 , V_52 ) ;
F_24 ( V_50 ) ;
F_25 ( V_50 ) ;
V_55 = ( V_50 [ 5 ] >> 2 ) & 0x3f ;
V_56 = ( V_50 [ 5 ] & 0x03 ) | ( ( ( V_50 [ 4 ] & 0x7f ) ) << 2 ) ;
V_57 = ( ( V_50 [ 4 ] & 0x80 ) >> 7 ) | V_50 [ 3 ] << 1 ;
V_58 = ( V_50 [ 2 ] & 0xff ) | ( ( V_50 [ 1 ] & 1 ) << 8 ) ;
V_54 = ( V_55 << 9 ) | ( V_56 ^ V_57 ^ V_58 ) ;
V_54 = V_54 & 0x07ff ;
return V_54 ;
}
static int F_27 ( struct V_1 * V_2 ,
unsigned char * V_50 ,
T_1 V_59 , T_1 V_60 , int V_61 )
{
struct V_62 * V_63 , * V_64 ;
T_1 V_65 ;
T_1 V_66 ;
T_1 V_51 ;
V_66 = ( ( ( V_50 [ 1 ] >> 4 ) & 0xf ) << 15 )
| ( ( ( V_50 [ 1 ] >> 0 ) & 0xf ) << 11 )
| ( ( ( V_50 [ 0 ] >> 4 ) & 0xf ) << 7 )
| ( ( ( V_50 [ 0 ] >> 0 ) & 0xf ) << 3 )
| ( ( ( V_50 [ 3 ] >> 4 ) & 0x1 ) << 31 )
| ( ( ( V_50 [ 3 ] >> 0 ) & 0xf ) << 27 )
| ( ( ( V_50 [ 2 ] >> 4 ) & 0xf ) << 23 )
| ( ( ( V_50 [ 2 ] >> 0 ) & 0xf ) << 19 )
| ( V_60 << V_67 ) | ( V_59 << V_68 )
| V_69 ;
V_65 = ( ( ( V_50 [ 5 ] >> 4 ) & 0xf ) << 15 )
| ( ( ( V_50 [ 5 ] >> 0 ) & 0xf ) << 11 )
| ( ( ( V_50 [ 4 ] >> 4 ) & 0xf ) << 7 )
| ( ( ( V_50 [ 4 ] >> 0 ) & 0xf ) << 3 )
| ( ( ( V_50 [ 3 ] >> 5 ) & 0x7 ) << 0 ) ;
V_64 = V_2 -> V_70 ;
V_63 = V_64 + F_26 ( V_50 ) ;
for ( V_51 = 0 ; V_51 < V_71 ; V_51 ++ ) {
if ( ! ( F_28 ( V_63 -> V_72 ) & V_69 ) ) {
break;
} else {
if ( ( ( F_28 ( V_63 -> V_72 ) & 0xfffffff8 ) ==
( V_66 & 0xfffffff8 ) ) &&
( F_28 ( V_63 -> V_73 ) == V_65 ) ) {
break;
}
}
if ( V_63 == V_64 + 0x7ff )
V_63 = V_64 ;
else
V_63 ++ ;
}
if ( ( ( F_28 ( V_63 -> V_72 ) & 0xfffffff8 ) != ( V_66 & 0xfffffff8 ) ) &&
( F_28 ( V_63 -> V_73 ) != V_65 ) && V_61 )
return 0 ;
if ( V_51 == V_71 ) {
if ( ! V_61 ) {
F_7 ( V_74 L_2
L_3 ,
__FILE__ ) ;
return - V_75 ;
} else
return 0 ;
}
if ( V_61 ) {
V_63 -> V_73 = 0 ;
V_63 -> V_72 = 0 ;
} else {
V_63 -> V_73 = F_29 ( V_65 ) ;
V_63 -> V_72 = F_29 ( V_66 ) ;
}
return 0 ;
}
static void F_30 ( struct V_1 * V_2 ,
unsigned char * V_76 ,
unsigned char * V_77 )
{
if ( V_76 )
F_27 ( V_2 , V_76 , 1 , 0 , V_78 ) ;
F_27 ( V_2 , V_77 , 1 , 0 , V_79 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
if ( V_2 -> V_70 == NULL ) {
V_2 -> V_70 = F_32 ( V_2 -> V_22 -> V_22 . V_80 ,
V_81 ,
& V_2 -> V_82 , V_83 ) ;
if ( V_2 -> V_70 == NULL )
return - V_84 ;
} else {
memset ( V_2 -> V_70 , 0 , V_81 ) ;
}
F_3 ( V_2 , V_85 , V_2 -> V_82 ) ;
return 0 ;
}
static void F_33 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_86 * V_87 ;
T_1 V_88 ;
V_88 = F_1 ( V_2 , V_89 ) ;
if ( V_22 -> V_90 & V_91 )
V_88 |= V_92 ;
else
V_88 &= ~ V_92 ;
F_3 ( V_2 , V_89 , V_88 ) ;
memset ( V_2 -> V_70 , 0 , V_81 ) ;
F_30 ( V_2 , NULL , V_22 -> V_93 ) ;
F_34 (ha, dev)
F_30 ( V_2 , NULL , V_87 -> V_77 ) ;
}
static int F_35 ( struct V_21 * V_22 , void * V_77 )
{
struct V_94 * V_95 = V_77 ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
unsigned char V_96 [ V_52 ] ;
if ( ! F_36 ( V_95 -> V_97 ) )
return - V_98 ;
memcpy ( V_96 , V_22 -> V_93 , V_52 ) ;
memcpy ( V_22 -> V_93 , V_95 -> V_97 , V_52 ) ;
F_37 ( V_22 ) ;
F_30 ( V_2 , V_96 , V_22 -> V_93 ) ;
F_38 ( V_22 ) ;
return 0 ;
}
static void F_39 ( struct V_21 * V_22 )
{
unsigned int V_88 = 0 ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_99 , V_100 ;
if ( V_2 -> V_18 != NULL ) {
struct V_101 V_102 ;
F_40 ( V_2 -> V_22 , & V_102 ) ;
F_10 ( V_2 ) ;
F_41 ( V_2 -> V_22 , & V_102 ) ;
}
V_99 = V_2 -> V_103 ;
F_3 ( V_2 , V_104 ,
( T_1 ) ( V_2 -> V_105 + V_99 * sizeof( struct V_106 ) ) ) ;
V_100 = V_2 -> V_107 ;
F_3 ( V_2 , V_108 ,
( T_1 ) ( V_2 -> V_109 + V_100 * sizeof( struct V_25 ) ) ) ;
F_3 ( V_2 , V_110 ,
( T_1 ) ( V_2 -> V_109 + V_100 * sizeof( struct V_25 ) ) ) ;
F_3 ( V_2 , V_111 , 0 ) ;
F_3 ( V_2 , V_112 , V_113 ) ;
V_88 = F_1 ( V_2 , V_89 ) ;
V_88 |= V_114 ;
F_3 ( V_2 , V_89 , V_88 ) ;
V_88 = F_1 ( V_2 , V_8 ) ;
V_88 |= V_115 ;
F_3 ( V_2 , V_8 , V_88 ) ;
}
static void F_42 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
unsigned int V_88 = 0 ;
F_3 ( V_2 , V_112 , 0 ) ;
F_3 ( V_2 , V_111 , 0 ) ;
V_88 = F_1 ( V_2 , V_8 ) ;
V_88 &= ~ V_115 ;
F_5 ( V_2 ) ;
V_88 = F_1 ( V_2 , V_89 ) ;
V_88 &= ~ V_114 ;
F_3 ( V_2 , V_89 , V_88 ) ;
}
static int F_43 ( struct V_21 * V_22 , int V_116 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_106 * V_117 ;
T_1 V_39 ;
struct V_23 * V_24 ;
int V_118 ;
T_3 V_77 ;
int V_119 ;
int V_120 = 0 ;
F_44 ( V_22 ) ;
V_2 -> V_121 &= ~ V_122 ;
while ( V_2 -> V_123 > 0 ) {
V_118 = V_2 -> V_124 ;
V_117 = & V_2 -> V_125 [ V_118 ] ;
V_39 = V_117 -> V_39 ;
if ( ! V_116 && ( V_39 & V_40 ) ) {
if ( V_120 > 0 ) {
goto V_126;
} else {
V_120 = - 1 ;
goto V_126;
}
}
V_2 -> V_124 = ( V_118 + 1 ) % V_2 -> V_127 ;
V_2 -> V_123 -- ;
V_77 = V_117 -> V_35 ;
V_119 = V_117 -> V_128 ;
V_24 = V_2 -> V_129 [ V_118 ] ;
if ( V_24 )
V_2 -> V_129 [ V_118 ] = NULL ;
if ( V_39 & V_130 ) {
if ( F_45 () )
F_7 ( V_11 L_4 , V_22 -> V_131 ) ;
V_22 -> V_132 . V_133 ++ ;
}
F_46 ( NULL , V_77 , V_119 , V_134 ) ;
if ( V_24 )
F_47 ( V_24 ) ;
V_120 ++ ;
}
V_126:
F_48 ( V_22 ) ;
return V_120 ;
}
static void F_49 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
F_7 ( V_74 L_5 ,
V_22 -> V_131 , V_2 -> V_123 ) ;
F_50 ( & V_2 -> V_135 ) ;
}
static void F_51 ( struct V_136 * V_137 )
{
struct V_1 * V_2 = F_52 ( V_137 ,
struct V_1 ,
V_135 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
F_53 ( V_22 ) ;
F_54 ( V_22 ) ;
}
static int F_55 ( struct V_21 * V_22 , int V_138 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_139 * V_132 = & V_22 -> V_132 ;
unsigned int V_140 = 0 ;
struct V_23 * V_24 ;
while ( V_138 -- > 0 ) {
int V_141 , V_100 , V_142 ;
struct V_25 * V_25 ;
unsigned int V_39 ;
if ( V_2 -> V_42 )
break;
V_100 = V_2 -> V_107 ;
V_142 = V_2 -> V_33 ;
V_25 = & V_2 -> V_34 [ V_100 ] ;
V_39 = V_25 -> V_39 ;
F_56 () ;
if ( V_39 & ( V_40 ) )
break;
V_24 = V_2 -> V_38 [ V_100 ] ;
V_2 -> V_38 [ V_100 ] = NULL ;
V_141 = ( V_100 + 1 ) % V_2 -> V_29 ;
V_2 -> V_107 = V_141 ;
if ( V_141 == V_142 )
V_2 -> V_42 = 1 ;
V_2 -> V_28 -- ;
F_46 ( NULL , V_25 -> V_35 ,
V_25 -> V_37 ,
V_36 ) ;
V_140 ++ ;
V_132 -> V_143 ++ ;
V_132 -> V_144 += V_25 -> V_128 ;
if ( ( ( V_39 & ( V_145 | V_146 ) ) !=
( V_145 | V_146 ) )
|| ( V_39 & V_147 ) ) {
V_132 -> V_148 ++ ;
if ( ( V_39 & ( V_145 | V_146 ) ) !=
( V_145 | V_146 ) ) {
if ( F_45 () )
F_7 ( V_11
L_6 ,
V_22 -> V_131 ) ;
}
if ( V_39 & V_147 )
V_132 -> V_149 ++ ;
F_47 ( V_24 ) ;
} else {
F_57 ( V_24 , V_25 -> V_128 - 4 ) ;
V_24 -> V_150 = F_58 ( V_24 , V_22 ) ;
F_59 ( V_24 ) ;
}
}
F_13 ( V_22 ) ;
return V_140 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
T_1 V_151 ;
int V_152 = 0 ;
V_151 = F_1 ( V_2 , V_111 ) ;
if ( V_151 == 0 )
return V_153 ;
F_3 ( V_2 , V_111 , ~ V_151 ) ;
if ( V_151 & ( V_154 | V_155 ) ) {
V_2 -> V_121 |= V_122 ;
V_152 = 1 ;
}
if ( V_151 & V_156 )
V_152 = 1 ;
if ( V_151 & V_157 ) {
V_2 -> V_121 |= V_158 ;
V_152 = 1 ;
}
return V_152 ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_159 ;
int V_160 ;
int V_161 ;
int V_162 ;
V_159 = F_1 ( V_2 , V_163 ) ;
if ( ! ( V_159 & V_164 ) ) {
if ( F_62 ( V_22 ) ) {
F_7 ( V_74 L_7 , V_22 -> V_131 ) ;
F_63 ( V_22 ) ;
F_43 ( V_22 , 1 ) ;
}
return;
}
if ( V_159 & V_165 )
V_160 = 100 ;
else
V_160 = 10 ;
V_161 = ( V_159 & V_166 ) ? 1 : 0 ;
V_162 = ( V_159 & V_167 ) ? 1 : 0 ;
F_7 ( V_74 L_8
L_9 , V_22 -> V_131 ,
V_160 , V_161 ? L_10 : L_11 , V_162 ? L_12 : L_13 ) ;
if ( ! F_62 ( V_22 ) )
F_64 ( V_22 ) ;
}
static T_4 F_65 ( int V_168 , void * V_169 )
{
struct V_21 * V_22 = (struct V_21 * ) V_169 ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
if ( F_66 ( ! F_60 ( V_2 , V_22 ) ) )
return V_153 ;
F_3 ( V_2 , V_112 , 0 ) ;
F_22 ( & V_2 -> V_48 ) ;
return V_170 ;
}
static void F_67 ( struct V_1 * V_2 )
{
int V_31 ;
V_31 = V_2 -> V_22 -> V_171 + 36 ;
V_2 -> V_31 = ( V_31 + 7 ) & ~ 7 ;
V_2 -> V_31 += V_32 ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_31 ;
F_67 ( V_2 ) ;
if ( V_2 -> V_31 <= 1518 )
V_31 = V_172 ;
else if ( V_2 -> V_31 <= 1536 )
V_31 = V_173 ;
else if ( V_2 -> V_31 <= 2048 )
V_31 = V_174 ;
else
V_31 = V_175 ;
F_3 ( V_2 ,
V_176 , V_177 |
V_178 |
V_31 | V_179 |
V_180 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
int V_181 = 0 ;
F_3 ( V_2 , V_112 , 0 ) ;
F_3 ( V_2 , V_111 , 0 ) ;
F_3 ( V_2 , V_182 , 0 ) ;
F_5 ( V_2 ) ;
V_181 = F_31 ( V_2 ) ;
if ( V_181 )
return V_181 ;
F_3 ( V_2 , V_183 , V_184 |
V_185 |
V_186 |
V_187 |
V_188 ) ;
F_3 ( V_2 , V_89 , V_189 ) ;
F_68 ( V_2 ) ;
return V_181 ;
}
static int F_70 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_25 * V_190 ;
int V_30 = 0 , V_51 = 0 ;
int V_191 = V_2 -> V_29 ;
V_2 -> V_38 = F_71 ( sizeof( * V_2 -> V_38 ) * V_2 -> V_29 ,
V_83 ) ;
if ( ! V_2 -> V_38 )
return - V_84 ;
V_2 -> V_28 = 0 ;
V_30 = V_2 -> V_29 * sizeof( struct V_25 ) ;
V_2 -> V_192 = V_30 ;
V_2 -> V_34 = F_32 ( V_2 -> V_22 -> V_22 . V_80 , V_30 ,
& V_2 -> V_109 ,
V_83 ) ;
if ( ! V_2 -> V_34 )
goto V_193;
V_190 = V_2 -> V_34 ;
for ( V_51 = 0 ; V_51 < V_191 ; V_51 ++ ) {
V_190 [ V_51 ] . V_194 = V_2 -> V_109 +
( ( V_51 + 1 ) % V_191 ) * sizeof( struct V_25 ) ;
}
V_2 -> V_107 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_192 = V_191 * sizeof( struct V_25 ) ;
return 0 ;
V_193:
F_72 ( V_2 -> V_38 ) ;
return - V_84 ;
}
static void F_73 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_195 ;
for ( V_195 = 0 ; V_2 -> V_28 && V_195 < V_2 -> V_29 ; V_195 ++ ) {
if ( V_2 -> V_38 [ V_195 ] ) {
F_74 ( V_2 -> V_38 [ V_195 ] ) ;
V_2 -> V_28 -- ;
}
}
if ( V_2 -> V_28 )
F_7 ( V_11
L_14 ,
V_2 -> V_28 ) ;
if ( V_2 -> V_34 )
F_75 ( V_2 -> V_22 -> V_22 . V_80 , V_2 -> V_192 ,
V_2 -> V_34 , V_2 -> V_109 ) ;
F_72 ( V_2 -> V_38 ) ;
}
static int F_76 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_106 * V_196 ;
int V_30 = 0 , V_51 = 0 ;
int V_197 = V_2 -> V_127 ;
V_2 -> V_129 = F_71 ( sizeof( * V_2 -> V_129 ) * V_2 -> V_127 ,
V_83 ) ;
if ( ! V_2 -> V_129 )
return - V_84 ;
V_2 -> V_123 = 0 ;
V_30 = V_2 -> V_127 * sizeof( struct V_106 ) ;
V_2 -> V_198 = V_30 ;
V_2 -> V_125 = F_32 ( V_2 -> V_22 -> V_22 . V_80 , V_30 ,
& V_2 -> V_105 ,
V_83 ) ;
if ( ! V_2 -> V_125 )
goto V_193;
V_196 = V_2 -> V_125 ;
for ( V_51 = 0 ; V_51 < V_197 ; V_51 ++ ) {
V_196 [ V_51 ] . V_194 = V_2 -> V_105 +
( ( V_51 + 1 ) % V_197 ) * sizeof( struct V_106 ) ;
}
V_2 -> V_103 = 0 ;
V_2 -> V_124 = 0 ;
V_2 -> V_198 = V_197 * sizeof( struct V_106 ) ;
return 0 ;
V_193:
F_72 ( V_2 -> V_129 ) ;
return - V_84 ;
}
static void F_77 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
F_43 ( V_22 , 1 ) ;
F_78 ( V_2 -> V_124 != V_2 -> V_103 ) ;
if ( V_2 -> V_125 )
F_75 ( V_2 -> V_22 -> V_22 . V_80 , V_2 -> V_198 ,
V_2 -> V_125 , V_2 -> V_105 ) ;
F_72 ( V_2 -> V_129 ) ;
}
static int F_54 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_181 ;
V_181 = F_79 ( V_22 -> V_168 , F_65 , 0 , V_22 -> V_131 , V_22 ) ;
if ( V_181 ) {
F_80 ( & V_22 -> V_22 , L_15 ) ;
return - V_199 ;
}
V_2 -> V_42 = 0 ;
V_181 = F_70 ( V_22 ) ;
if ( V_181 != 0 )
goto V_200;
V_181 = F_76 ( V_22 ) ;
if ( V_181 != 0 )
goto V_201;
V_2 -> V_33 = 0 ;
V_2 -> V_107 = 0 ;
F_13 ( V_22 ) ;
V_2 -> V_33 = 0 ;
V_2 -> V_107 = 0 ;
F_63 ( V_22 ) ;
F_39 ( V_22 ) ;
F_81 ( & V_2 -> V_48 ) ;
return 0 ;
V_201:
F_73 ( V_22 ) ;
V_200:
F_82 ( V_22 -> V_168 , V_22 ) ;
return V_181 ;
}
static int F_53 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
F_42 ( V_22 ) ;
F_3 ( V_2 , V_112 , 0 ) ;
F_3 ( V_2 , V_111 , 0 ) ;
F_3 ( V_2 , V_182 , 0 ) ;
F_83 ( & V_2 -> V_48 ) ;
F_84 ( & V_2 -> V_44 ) ;
F_63 ( V_22 ) ;
F_82 ( V_22 -> V_168 , V_22 ) ;
F_73 ( V_22 ) ;
F_77 ( V_22 ) ;
return 0 ;
}
static int F_85 ( struct V_21 * V_22 , int V_171 )
{
int V_202 ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
if ( ( V_171 > 9500 ) || ( V_171 < 68 ) )
return - V_203 ;
V_22 -> V_171 = V_171 ;
V_202 = F_68 ( V_2 ) ;
if ( ! F_86 ( V_22 ) )
return 0 ;
F_53 ( V_22 ) ;
if ( F_54 ( V_22 ) ) {
F_80 ( & V_22 -> V_22 ,
L_16 ) ;
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
static int F_88 ( struct V_205 * V_48 , int V_138 )
{
struct V_1 * V_2 =
F_52 ( V_48 , struct V_1 , V_48 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
int V_206 = 0 ;
if ( F_66 ( V_2 -> V_121 & V_158 ) ) {
V_2 -> V_121 &= ~ ( V_158 ) ;
F_61 ( V_2 ) ;
}
F_43 ( V_22 , 0 ) ;
if ( F_89 ( V_22 )
&& V_2 -> V_127 - V_2 -> V_123 > 1 ) {
F_90 ( V_22 ) ;
}
V_206 = F_55 ( V_22 , V_138 ) ;
if ( V_206 < V_138 ) {
F_91 ( V_48 ) ;
F_3 ( V_2 , V_112 , V_113 ) ;
}
return V_206 ;
}
static int F_92 ( struct V_23 * V_24 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_139 * V_132 = & V_22 -> V_132 ;
struct V_106 * V_117 ;
int V_118 ;
int V_207 ;
V_118 = F_87 ( V_2 ) ;
V_117 = & V_2 -> V_125 [ V_118 ] ;
V_207 = V_24 -> V_208 ;
V_2 -> V_129 [ V_118 ] = V_24 ;
V_117 -> V_128 = V_207 ;
V_117 -> V_35 = F_18 ( NULL , V_24 -> V_5 , V_207 , V_134 ) ;
F_93 ( V_24 ) ;
F_19 () ;
V_117 -> V_39 = V_40 | V_209 | V_210 |
V_211 | V_212 | V_213 ;
F_19 () ;
F_3 ( V_2 , V_8 , V_214 | V_115 ) ;
V_132 -> V_215 += V_207 ;
V_132 -> V_216 ++ ;
V_22 -> V_217 = V_46 ;
if ( V_2 -> V_127 - V_2 -> V_123 <= 1 ) {
F_94 ( V_22 ) ;
}
return V_218 ;
}
static int F_95 ( struct V_1 * V_2 )
{
int V_51 = 0 ;
for ( V_51 = 0 ; F_1 ( V_2 , V_219 ) & V_220 ; V_51 ++ ) {
if ( V_51 == V_221 )
return - V_222 ;
F_96 ( 10 ) ;
}
return 0 ;
}
static int F_97 ( struct V_223 * V_224 , int V_16 , int V_225 )
{
struct V_1 * V_2 = V_224 -> V_226 ;
int V_51 = 0 ;
int V_88 ;
if ( F_95 ( V_2 ) ) {
F_7 ( V_227 L_17 ) ;
return - V_222 ;
}
F_3 ( V_2 , V_219 , ( V_16 << 16 ) | ( V_225 << 21 ) | V_228 ) ;
for ( V_51 = 0 ; ! ( ( V_88 = F_1 ( V_2 , V_219 ) ) & V_229 ) ; V_51 ++ ) {
if ( V_51 == V_221 ) {
F_7 ( V_227
L_18 ) ;
return - V_230 ;
}
F_96 ( 10 ) ;
}
return V_88 & 0xffff ;
}
static int F_98 ( struct V_223 * V_224 , int V_16 , int V_225 ,
T_5 V_231 )
{
struct V_1 * V_2 = V_224 -> V_226 ;
if ( F_95 ( V_2 ) ) {
F_7 ( V_227 L_17 ) ;
return - V_222 ;
}
F_3 ( V_2 , V_219 , ( V_16 << 16 ) | ( V_225 << 21 ) |
V_232 | ( V_231 & 0xffff ) ) ;
if ( F_95 ( V_2 ) ) {
F_7 ( V_11 L_17 ) ;
return - V_222 ;
}
return 0 ;
}
static int F_99 ( struct V_21 * V_22 , struct V_233 * V_234 ,
int V_102 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
if ( V_2 -> V_18 != NULL )
return F_100 ( V_2 -> V_18 , V_234 , V_102 ) ;
return - V_235 ;
}
static struct V_236 * F_101 ( struct V_1 * V_2 , int V_16 )
{
struct V_223 * V_224 = V_2 -> V_237 ;
struct V_236 * V_238 ;
int V_64 ;
int V_239 ;
int V_51 ;
if ( V_16 == V_240 ) {
V_64 = F_8 ( V_2 ) ;
V_239 = 32 ;
} else {
V_64 = V_16 & 0x1f ;
V_239 = 1 ;
}
V_238 = NULL ;
for ( V_51 = 0 ; V_51 < V_239 ; V_51 ++ ) {
int V_77 = ( V_64 + V_51 ) & 0x1f ;
if ( V_224 -> V_241 [ V_77 ] == NULL )
F_102 ( V_224 , V_77 ) ;
if ( V_238 == NULL ) {
V_238 = V_224 -> V_241 [ V_77 ] ;
if ( V_238 != NULL )
F_9 ( V_2 , V_77 ) ;
}
}
return V_238 ;
}
static void F_103 ( struct V_1 * V_2 , int V_160 , int V_161 )
{
struct V_236 * V_18 = V_2 -> V_18 ;
F_10 ( V_2 ) ;
F_104 ( V_2 -> V_22 , F_105 ( & V_18 -> V_22 ) , V_242 ) ;
if ( V_160 == 0 ) {
V_18 -> V_243 = V_244 ;
V_18 -> V_160 = 0 ;
V_18 -> V_161 = 0 ;
V_18 -> V_245 &= V_246 ;
V_18 -> V_247 = V_18 -> V_245 | V_248 ;
} else {
V_18 -> V_243 = V_249 ;
V_18 -> V_247 = 0 ;
V_18 -> V_160 = V_160 ;
V_18 -> V_161 = V_161 ;
}
F_106 ( V_18 ) ;
}
static int F_107 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
if ( V_2 -> V_250 -> V_251 )
V_2 -> V_250 -> V_251 () ;
V_2 -> V_18 = F_101 ( V_2 , V_2 -> V_250 -> V_16 & 0x1f ) ;
if ( V_2 -> V_18 != NULL )
F_103 ( V_2 , V_2 -> V_250 -> V_160 , V_2 -> V_250 -> V_161 ) ;
F_30 ( V_2 , NULL , V_22 -> V_93 ) ;
return 0 ;
}
static int F_40 ( struct V_21 * V_22 , struct V_101 * V_102 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_181 ;
V_181 = F_108 ( V_2 -> V_18 ) ;
if ( V_181 == 0 )
V_181 = F_109 ( V_2 -> V_18 , V_102 ) ;
return V_181 ;
}
static int F_41 ( struct V_21 * V_22 , struct V_101 * V_102 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
return F_110 ( V_2 -> V_18 , V_102 ) ;
}
static void F_111 ( struct V_21 * V_22 ,
struct V_252 * V_253 )
{
F_112 ( V_253 -> V_254 , V_255 , sizeof( V_253 -> V_254 ) ) ;
F_112 ( V_253 -> V_256 , V_257 , sizeof( V_253 -> V_256 ) ) ;
F_112 ( V_253 -> V_258 , L_19 , sizeof( V_253 -> V_258 ) ) ;
F_112 ( V_253 -> V_259 , L_19 , sizeof( V_253 -> V_259 ) ) ;
}
static int F_113 ( struct V_260 * V_261 )
{
struct V_1 * V_2 = NULL ;
struct V_21 * V_22 = NULL ;
struct V_262 * V_263 ;
struct V_264 * V_264 ;
int V_181 ;
F_7 ( V_265 L_20 ) ;
V_264 = F_114 ( & V_261 -> V_22 , L_21 ) ;
if ( F_115 ( V_264 ) ) {
F_7 ( V_11 L_22 ,
V_255 ) ;
return - V_230 ;
}
F_116 ( V_264 ) ;
V_22 = F_117 ( sizeof( struct V_1 ) ) ;
if ( ! V_22 ) {
V_181 = - V_84 ;
goto V_266;
}
F_118 ( V_261 , V_22 ) ;
V_2 = F_14 ( V_22 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_264 = V_264 ;
V_263 = F_119 ( V_261 , V_267 , 0 ) ;
if ( V_263 == NULL ) {
V_181 = - V_230 ;
goto V_268;
}
V_2 -> V_4 = F_120 ( V_263 -> V_64 , F_121 ( V_263 ) ) ;
if ( V_2 -> V_4 == NULL ) {
V_181 = - V_84 ;
goto V_268;
}
V_263 = F_119 ( V_261 , V_269 , 0 ) ;
F_78 ( ! V_263 ) ;
V_22 -> V_168 = V_263 -> V_64 ;
V_22 -> V_270 = & V_271 ;
V_22 -> V_272 = 2 * V_47 ;
V_22 -> V_273 = 0 ;
F_122 ( V_22 , & V_274 ) ;
F_123 ( & V_2 -> V_135 , F_51 ) ;
F_7 ( V_74 L_23 , V_255 ) ;
F_124 ( V_22 ) ;
V_2 -> V_250 = F_125 ( & V_261 -> V_22 ) ;
V_2 -> V_29 = V_275 ;
if ( V_2 -> V_250 -> V_276 )
V_2 -> V_29 = V_2 -> V_250 -> V_276 ;
V_2 -> V_127 = V_277 ;
if ( V_2 -> V_250 -> V_278 )
V_2 -> V_127 = V_2 -> V_250 -> V_278 ;
V_2 -> V_15 = V_2 -> V_250 -> V_279 ;
F_78 ( V_2 -> V_15 > 2 ) ;
F_126 ( V_22 , & V_2 -> V_48 , F_88 , V_2 -> V_29 ) ;
memset ( & V_2 -> V_44 , 0 , sizeof( struct V_280 ) ) ;
F_127 ( & V_2 -> V_44 ) ;
V_2 -> V_44 . V_281 = F_21 ;
V_2 -> V_44 . V_5 = ( unsigned long ) V_2 ;
V_2 -> V_237 = F_128 () ;
if ( V_2 -> V_237 == NULL ) {
V_181 = - V_84 ;
goto V_282;
}
V_2 -> V_237 -> V_226 = V_2 ;
V_2 -> V_237 -> V_131 = L_24 ;
V_2 -> V_237 -> V_283 = F_97 ;
V_2 -> V_237 -> V_284 = F_98 ;
snprintf ( V_2 -> V_237 -> V_285 , V_286 , L_25 ,
V_261 -> V_131 , V_261 -> V_285 ) ;
V_2 -> V_237 -> V_80 = & V_261 -> V_22 ;
V_2 -> V_237 -> V_287 = 0xffffffff ;
V_181 = F_129 ( V_2 -> V_237 ) ;
if ( V_181 )
goto V_288;
F_69 ( V_2 ) ;
V_181 = F_107 ( V_22 ) ;
if ( V_181 )
goto V_289;
F_130 ( V_22 , & V_261 -> V_22 ) ;
V_181 = F_131 ( V_22 ) ;
if ( V_181 )
goto V_289;
return 0 ;
V_289:
F_132 ( V_2 -> V_237 ) ;
V_288:
F_133 ( V_2 -> V_237 ) ;
V_282:
F_134 ( V_2 -> V_4 ) ;
V_268:
F_135 ( V_22 ) ;
V_266:
F_136 ( V_264 ) ;
F_137 ( V_264 ) ;
return V_181 ;
}
static int F_138 ( struct V_260 * V_261 )
{
struct V_21 * V_22 = F_139 ( V_261 ) ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
if ( V_2 -> V_70 ) {
F_75 ( V_2 -> V_22 -> V_22 . V_80 , V_81 ,
V_2 -> V_70 , V_2 -> V_82 ) ;
V_2 -> V_70 = NULL ;
}
if ( V_2 -> V_264 ) {
F_136 ( V_2 -> V_264 ) ;
F_137 ( V_2 -> V_264 ) ;
V_2 -> V_264 = NULL ;
}
if ( V_2 -> V_18 != NULL )
F_140 ( V_2 -> V_18 ) ;
F_134 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
F_132 ( V_2 -> V_237 ) ;
F_133 ( V_2 -> V_237 ) ;
F_141 ( V_22 ) ;
F_142 ( & V_2 -> V_135 ) ;
F_135 ( V_22 ) ;
return 0 ;
}
static void F_143 ( struct V_260 * V_261 )
{
struct V_21 * V_22 = F_139 ( V_261 ) ;
F_42 ( V_22 ) ;
}
static int F_144 ( struct V_260 * V_261 )
{
return - V_290 ;
}
static int F_145 ( struct V_260 * V_261 , T_6 V_291 )
{
return - V_290 ;
}
