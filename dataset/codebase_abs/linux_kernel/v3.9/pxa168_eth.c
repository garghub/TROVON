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
V_30 = V_24 -> V_35 - V_24 -> V_5 ;
V_26 -> V_36 = F_17 ( NULL ,
V_24 -> V_5 ,
V_30 ,
V_37 ) ;
V_26 -> V_38 = V_30 ;
V_2 -> V_39 [ V_27 ] = V_24 ;
F_18 () ;
V_26 -> V_40 = V_41 | V_42 ;
F_18 () ;
V_2 -> V_33 = ( V_27 + 1 ) % V_2 -> V_29 ;
V_2 -> V_43 = 0 ;
F_16 ( V_24 , V_44 ) ;
}
if ( V_2 -> V_28 == 0 ) {
V_2 -> V_45 . V_46 = V_47 + ( V_48 / 10 ) ;
F_19 ( & V_2 -> V_45 ) ;
}
}
static inline void F_20 ( unsigned long V_5 )
{
struct V_1 * V_2 = ( void * ) V_5 ;
F_21 ( & V_2 -> V_49 ) ;
}
static inline T_2 F_22 ( T_2 V_50 )
{
return ( ( ( V_50 ) & 0x01 ) << 3 ) | ( ( ( V_50 ) & 0x02 ) << 1 )
| ( ( ( V_50 ) & 0x04 ) >> 1 ) | ( ( ( V_50 ) & 0x08 ) >> 3 )
| ( ( ( V_50 ) & 0x10 ) << 3 ) | ( ( ( V_50 ) & 0x20 ) << 1 )
| ( ( ( V_50 ) & 0x40 ) >> 1 ) | ( ( ( V_50 ) & 0x80 ) >> 3 ) ;
}
static void F_23 ( unsigned char * V_51 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ ) {
V_51 [ V_52 ] = ( ( V_51 [ V_52 ] & 0x0f ) << 4 ) |
( ( V_51 [ V_52 ] & 0xf0 ) >> 4 ) ;
}
}
static void F_24 ( unsigned char * V_51 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ )
V_51 [ V_52 ] = F_22 ( V_51 [ V_52 ] ) ;
}
static T_1 F_25 ( unsigned char * V_54 )
{
T_1 V_55 ;
T_1 V_56 ;
T_1 V_57 ;
T_1 V_58 ;
T_1 V_59 ;
unsigned char V_51 [ V_53 ] ;
memcpy ( V_51 , V_54 , V_53 ) ;
F_23 ( V_51 ) ;
F_24 ( V_51 ) ;
V_56 = ( V_51 [ 5 ] >> 2 ) & 0x3f ;
V_57 = ( V_51 [ 5 ] & 0x03 ) | ( ( ( V_51 [ 4 ] & 0x7f ) ) << 2 ) ;
V_58 = ( ( V_51 [ 4 ] & 0x80 ) >> 7 ) | V_51 [ 3 ] << 1 ;
V_59 = ( V_51 [ 2 ] & 0xff ) | ( ( V_51 [ 1 ] & 1 ) << 8 ) ;
V_55 = ( V_56 << 9 ) | ( V_57 ^ V_58 ^ V_59 ) ;
V_55 = V_55 & 0x07ff ;
return V_55 ;
}
static int F_26 ( struct V_1 * V_2 ,
unsigned char * V_51 ,
T_1 V_60 , T_1 V_61 , int V_62 )
{
struct V_63 * V_64 , * V_65 ;
T_1 V_66 ;
T_1 V_67 ;
T_1 V_52 ;
V_67 = ( ( ( V_51 [ 1 ] >> 4 ) & 0xf ) << 15 )
| ( ( ( V_51 [ 1 ] >> 0 ) & 0xf ) << 11 )
| ( ( ( V_51 [ 0 ] >> 4 ) & 0xf ) << 7 )
| ( ( ( V_51 [ 0 ] >> 0 ) & 0xf ) << 3 )
| ( ( ( V_51 [ 3 ] >> 4 ) & 0x1 ) << 31 )
| ( ( ( V_51 [ 3 ] >> 0 ) & 0xf ) << 27 )
| ( ( ( V_51 [ 2 ] >> 4 ) & 0xf ) << 23 )
| ( ( ( V_51 [ 2 ] >> 0 ) & 0xf ) << 19 )
| ( V_61 << V_68 ) | ( V_60 << V_69 )
| V_70 ;
V_66 = ( ( ( V_51 [ 5 ] >> 4 ) & 0xf ) << 15 )
| ( ( ( V_51 [ 5 ] >> 0 ) & 0xf ) << 11 )
| ( ( ( V_51 [ 4 ] >> 4 ) & 0xf ) << 7 )
| ( ( ( V_51 [ 4 ] >> 0 ) & 0xf ) << 3 )
| ( ( ( V_51 [ 3 ] >> 5 ) & 0x7 ) << 0 ) ;
V_65 = V_2 -> V_71 ;
V_64 = V_65 + F_25 ( V_51 ) ;
for ( V_52 = 0 ; V_52 < V_72 ; V_52 ++ ) {
if ( ! ( F_27 ( V_64 -> V_73 ) & V_70 ) ) {
break;
} else {
if ( ( ( F_27 ( V_64 -> V_73 ) & 0xfffffff8 ) ==
( V_67 & 0xfffffff8 ) ) &&
( F_27 ( V_64 -> V_74 ) == V_66 ) ) {
break;
}
}
if ( V_64 == V_65 + 0x7ff )
V_64 = V_65 ;
else
V_64 ++ ;
}
if ( ( ( F_27 ( V_64 -> V_73 ) & 0xfffffff8 ) != ( V_67 & 0xfffffff8 ) ) &&
( F_27 ( V_64 -> V_74 ) != V_66 ) && V_62 )
return 0 ;
if ( V_52 == V_72 ) {
if ( ! V_62 ) {
F_7 ( V_75 L_2
L_3 ,
__FILE__ ) ;
return - V_76 ;
} else
return 0 ;
}
if ( V_62 ) {
V_64 -> V_74 = 0 ;
V_64 -> V_73 = 0 ;
} else {
V_64 -> V_74 = F_28 ( V_66 ) ;
V_64 -> V_73 = F_28 ( V_67 ) ;
}
return 0 ;
}
static void F_29 ( struct V_1 * V_2 ,
unsigned char * V_77 ,
unsigned char * V_78 )
{
if ( V_77 )
F_26 ( V_2 , V_77 , 1 , 0 , V_79 ) ;
F_26 ( V_2 , V_78 , 1 , 0 , V_80 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_71 == NULL ) {
V_2 -> V_71 = F_31 ( V_2 -> V_22 -> V_22 . V_81 ,
V_82 ,
& V_2 -> V_83 , V_84 ) ;
if ( V_2 -> V_71 == NULL )
return - V_85 ;
}
memset ( V_2 -> V_71 , 0 , V_82 ) ;
F_3 ( V_2 , V_86 , V_2 -> V_83 ) ;
return 0 ;
}
static void F_32 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_87 * V_88 ;
T_1 V_89 ;
V_89 = F_1 ( V_2 , V_90 ) ;
if ( V_22 -> V_91 & V_92 )
V_89 |= V_93 ;
else
V_89 &= ~ V_93 ;
F_3 ( V_2 , V_90 , V_89 ) ;
memset ( V_2 -> V_71 , 0 , V_82 ) ;
F_29 ( V_2 , NULL , V_22 -> V_94 ) ;
F_33 (ha, dev)
F_29 ( V_2 , NULL , V_88 -> V_78 ) ;
}
static int F_34 ( struct V_21 * V_22 , void * V_78 )
{
struct V_95 * V_96 = V_78 ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
unsigned char V_97 [ V_53 ] ;
if ( ! F_35 ( V_96 -> V_98 ) )
return - V_99 ;
memcpy ( V_97 , V_22 -> V_94 , V_53 ) ;
memcpy ( V_22 -> V_94 , V_96 -> V_98 , V_53 ) ;
F_36 ( V_22 ) ;
F_29 ( V_2 , V_97 , V_22 -> V_94 ) ;
F_37 ( V_22 ) ;
return 0 ;
}
static void F_38 ( struct V_21 * V_22 )
{
unsigned int V_89 = 0 ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_100 , V_101 ;
if ( V_2 -> V_18 != NULL ) {
struct V_102 V_103 ;
F_39 ( V_2 -> V_22 , & V_103 ) ;
F_10 ( V_2 ) ;
F_40 ( V_2 -> V_22 , & V_103 ) ;
}
V_100 = V_2 -> V_104 ;
F_3 ( V_2 , V_105 ,
( T_1 ) ( V_2 -> V_106 + V_100 * sizeof( struct V_107 ) ) ) ;
V_101 = V_2 -> V_108 ;
F_3 ( V_2 , V_109 ,
( T_1 ) ( V_2 -> V_110 + V_101 * sizeof( struct V_25 ) ) ) ;
F_3 ( V_2 , V_111 ,
( T_1 ) ( V_2 -> V_110 + V_101 * sizeof( struct V_25 ) ) ) ;
F_3 ( V_2 , V_112 , 0 ) ;
F_3 ( V_2 , V_113 , V_114 ) ;
V_89 = F_1 ( V_2 , V_90 ) ;
V_89 |= V_115 ;
F_3 ( V_2 , V_90 , V_89 ) ;
V_89 = F_1 ( V_2 , V_8 ) ;
V_89 |= V_116 ;
F_3 ( V_2 , V_8 , V_89 ) ;
}
static void F_41 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
unsigned int V_89 = 0 ;
F_3 ( V_2 , V_113 , 0 ) ;
F_3 ( V_2 , V_112 , 0 ) ;
V_89 = F_1 ( V_2 , V_8 ) ;
V_89 &= ~ V_116 ;
F_5 ( V_2 ) ;
V_89 = F_1 ( V_2 , V_90 ) ;
V_89 &= ~ V_115 ;
F_3 ( V_2 , V_90 , V_89 ) ;
}
static int F_42 ( struct V_21 * V_22 , int V_117 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_107 * V_118 ;
T_1 V_40 ;
struct V_23 * V_24 ;
int V_119 ;
T_3 V_78 ;
int V_120 ;
int V_121 = 0 ;
F_43 ( V_22 ) ;
V_2 -> V_122 &= ~ V_123 ;
while ( V_2 -> V_124 > 0 ) {
V_119 = V_2 -> V_125 ;
V_118 = & V_2 -> V_126 [ V_119 ] ;
V_40 = V_118 -> V_40 ;
if ( ! V_117 && ( V_40 & V_41 ) ) {
if ( V_121 > 0 ) {
goto V_127;
} else {
V_121 = - 1 ;
goto V_127;
}
}
V_2 -> V_125 = ( V_119 + 1 ) % V_2 -> V_128 ;
V_2 -> V_124 -- ;
V_78 = V_118 -> V_36 ;
V_120 = V_118 -> V_129 ;
V_24 = V_2 -> V_130 [ V_119 ] ;
if ( V_24 )
V_2 -> V_130 [ V_119 ] = NULL ;
if ( V_40 & V_131 ) {
if ( F_44 () )
F_7 ( V_11 L_4 , V_22 -> V_132 ) ;
V_22 -> V_133 . V_134 ++ ;
}
F_45 ( NULL , V_78 , V_120 , V_135 ) ;
if ( V_24 )
F_46 ( V_24 ) ;
V_121 ++ ;
}
V_127:
F_47 ( V_22 ) ;
return V_121 ;
}
static void F_48 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
F_7 ( V_75 L_5 ,
V_22 -> V_132 , V_2 -> V_124 ) ;
F_49 ( & V_2 -> V_136 ) ;
}
static void F_50 ( struct V_137 * V_138 )
{
struct V_1 * V_2 = F_51 ( V_138 ,
struct V_1 ,
V_136 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
F_52 ( V_22 ) ;
F_53 ( V_22 ) ;
}
static int F_54 ( struct V_21 * V_22 , int V_139 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_140 * V_133 = & V_22 -> V_133 ;
unsigned int V_141 = 0 ;
struct V_23 * V_24 ;
while ( V_139 -- > 0 ) {
int V_142 , V_101 , V_143 ;
struct V_25 * V_25 ;
unsigned int V_40 ;
if ( V_2 -> V_43 )
break;
V_101 = V_2 -> V_108 ;
V_143 = V_2 -> V_33 ;
V_25 = & V_2 -> V_34 [ V_101 ] ;
V_40 = V_25 -> V_40 ;
F_55 () ;
if ( V_40 & ( V_41 ) )
break;
V_24 = V_2 -> V_39 [ V_101 ] ;
V_2 -> V_39 [ V_101 ] = NULL ;
V_142 = ( V_101 + 1 ) % V_2 -> V_29 ;
V_2 -> V_108 = V_142 ;
if ( V_142 == V_143 )
V_2 -> V_43 = 1 ;
V_2 -> V_28 -- ;
F_45 ( NULL , V_25 -> V_36 ,
V_25 -> V_38 ,
V_37 ) ;
V_141 ++ ;
V_133 -> V_144 ++ ;
V_133 -> V_145 += V_25 -> V_129 ;
if ( ( ( V_40 & ( V_146 | V_147 ) ) !=
( V_146 | V_147 ) )
|| ( V_40 & V_148 ) ) {
V_133 -> V_149 ++ ;
if ( ( V_40 & ( V_146 | V_147 ) ) !=
( V_146 | V_147 ) ) {
if ( F_44 () )
F_7 ( V_11
L_6 ,
V_22 -> V_132 ) ;
}
if ( V_40 & V_148 )
V_133 -> V_150 ++ ;
F_46 ( V_24 ) ;
} else {
F_56 ( V_24 , V_25 -> V_129 - 4 ) ;
V_24 -> V_151 = F_57 ( V_24 , V_22 ) ;
F_58 ( V_24 ) ;
}
}
F_13 ( V_22 ) ;
return V_141 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
T_1 V_152 ;
int V_153 = 0 ;
V_152 = F_1 ( V_2 , V_112 ) ;
if ( V_152 == 0 )
return V_154 ;
F_3 ( V_2 , V_112 , ~ V_152 ) ;
if ( V_152 & ( V_155 | V_156 ) ) {
V_2 -> V_122 |= V_123 ;
V_153 = 1 ;
}
if ( V_152 & V_157 )
V_153 = 1 ;
if ( V_152 & V_158 ) {
V_2 -> V_122 |= V_159 ;
V_153 = 1 ;
}
return V_153 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_160 ;
int V_161 ;
int V_162 ;
int V_163 ;
V_160 = F_1 ( V_2 , V_164 ) ;
if ( ! ( V_160 & V_165 ) ) {
if ( F_61 ( V_22 ) ) {
F_7 ( V_75 L_7 , V_22 -> V_132 ) ;
F_62 ( V_22 ) ;
F_42 ( V_22 , 1 ) ;
}
return;
}
if ( V_160 & V_166 )
V_161 = 100 ;
else
V_161 = 10 ;
V_162 = ( V_160 & V_167 ) ? 1 : 0 ;
V_163 = ( V_160 & V_168 ) ? 1 : 0 ;
F_7 ( V_75 L_8
L_9 , V_22 -> V_132 ,
V_161 , V_162 ? L_10 : L_11 , V_163 ? L_12 : L_13 ) ;
if ( ! F_61 ( V_22 ) )
F_63 ( V_22 ) ;
}
static T_4 F_64 ( int V_169 , void * V_170 )
{
struct V_21 * V_22 = (struct V_21 * ) V_170 ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
if ( F_65 ( ! F_59 ( V_2 , V_22 ) ) )
return V_154 ;
F_3 ( V_2 , V_113 , 0 ) ;
F_21 ( & V_2 -> V_49 ) ;
return V_171 ;
}
static void F_66 ( struct V_1 * V_2 )
{
int V_31 ;
V_31 = V_2 -> V_22 -> V_172 + 36 ;
V_2 -> V_31 = ( V_31 + 7 ) & ~ 7 ;
V_2 -> V_31 += V_32 ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_31 ;
F_66 ( V_2 ) ;
if ( V_2 -> V_31 <= 1518 )
V_31 = V_173 ;
else if ( V_2 -> V_31 <= 1536 )
V_31 = V_174 ;
else if ( V_2 -> V_31 <= 2048 )
V_31 = V_175 ;
else
V_31 = V_176 ;
F_3 ( V_2 ,
V_177 , V_178 |
V_179 |
V_31 | V_180 |
V_181 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_182 = 0 ;
F_3 ( V_2 , V_113 , 0 ) ;
F_3 ( V_2 , V_112 , 0 ) ;
F_3 ( V_2 , V_183 , 0 ) ;
F_5 ( V_2 ) ;
V_182 = F_30 ( V_2 ) ;
if ( V_182 )
return V_182 ;
F_3 ( V_2 , V_184 , V_185 |
V_186 |
V_187 |
V_188 |
V_189 ) ;
F_3 ( V_2 , V_90 , V_190 ) ;
F_67 ( V_2 ) ;
return V_182 ;
}
static int F_69 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_25 * V_191 ;
int V_30 = 0 , V_52 = 0 ;
int V_192 = V_2 -> V_29 ;
V_2 -> V_39 = F_70 ( sizeof( * V_2 -> V_39 ) * V_2 -> V_29 ,
V_84 ) ;
if ( ! V_2 -> V_39 )
return - V_85 ;
V_2 -> V_28 = 0 ;
V_30 = V_2 -> V_29 * sizeof( struct V_25 ) ;
V_2 -> V_193 = V_30 ;
V_2 -> V_34 = F_31 ( V_2 -> V_22 -> V_22 . V_81 , V_30 ,
& V_2 -> V_110 , V_84 ) ;
if ( ! V_2 -> V_34 ) {
F_7 ( V_11 L_14 ,
V_22 -> V_132 , V_30 ) ;
goto V_194;
}
memset ( ( void * ) V_2 -> V_34 , 0 , V_30 ) ;
V_191 = V_2 -> V_34 ;
for ( V_52 = 0 ; V_52 < V_192 ; V_52 ++ ) {
V_191 [ V_52 ] . V_195 = V_2 -> V_110 +
( ( V_52 + 1 ) % V_192 ) * sizeof( struct V_25 ) ;
}
V_2 -> V_108 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_193 = V_192 * sizeof( struct V_25 ) ;
return 0 ;
V_194:
F_71 ( V_2 -> V_39 ) ;
return - V_85 ;
}
static void F_72 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_196 ;
for ( V_196 = 0 ; V_2 -> V_28 && V_196 < V_2 -> V_29 ; V_196 ++ ) {
if ( V_2 -> V_39 [ V_196 ] ) {
F_73 ( V_2 -> V_39 [ V_196 ] ) ;
V_2 -> V_28 -- ;
}
}
if ( V_2 -> V_28 )
F_7 ( V_11
L_15 ,
V_2 -> V_28 ) ;
if ( V_2 -> V_34 )
F_74 ( V_2 -> V_22 -> V_22 . V_81 , V_2 -> V_193 ,
V_2 -> V_34 , V_2 -> V_110 ) ;
F_71 ( V_2 -> V_39 ) ;
}
static int F_75 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_107 * V_197 ;
int V_30 = 0 , V_52 = 0 ;
int V_198 = V_2 -> V_128 ;
V_2 -> V_130 = F_70 ( sizeof( * V_2 -> V_130 ) * V_2 -> V_128 ,
V_84 ) ;
if ( ! V_2 -> V_130 )
return - V_85 ;
V_2 -> V_124 = 0 ;
V_30 = V_2 -> V_128 * sizeof( struct V_107 ) ;
V_2 -> V_199 = V_30 ;
V_2 -> V_126 = F_31 ( V_2 -> V_22 -> V_22 . V_81 , V_30 ,
& V_2 -> V_106 , V_84 ) ;
if ( ! V_2 -> V_126 ) {
F_7 ( V_11 L_16 ,
V_22 -> V_132 , V_30 ) ;
goto V_194;
}
memset ( ( void * ) V_2 -> V_126 , 0 , V_2 -> V_199 ) ;
V_197 = V_2 -> V_126 ;
for ( V_52 = 0 ; V_52 < V_198 ; V_52 ++ ) {
V_197 [ V_52 ] . V_195 = V_2 -> V_106 +
( ( V_52 + 1 ) % V_198 ) * sizeof( struct V_107 ) ;
}
V_2 -> V_104 = 0 ;
V_2 -> V_125 = 0 ;
V_2 -> V_199 = V_198 * sizeof( struct V_107 ) ;
return 0 ;
V_194:
F_71 ( V_2 -> V_130 ) ;
return - V_85 ;
}
static void F_76 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
F_42 ( V_22 , 1 ) ;
F_77 ( V_2 -> V_125 != V_2 -> V_104 ) ;
if ( V_2 -> V_126 )
F_74 ( V_2 -> V_22 -> V_22 . V_81 , V_2 -> V_199 ,
V_2 -> V_126 , V_2 -> V_106 ) ;
F_71 ( V_2 -> V_130 ) ;
}
static int F_53 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_182 ;
V_182 = F_78 ( V_22 -> V_169 , F_64 ,
V_200 , V_22 -> V_132 , V_22 ) ;
if ( V_182 ) {
F_79 ( & V_22 -> V_22 , L_17 ) ;
return - V_201 ;
}
V_2 -> V_43 = 0 ;
V_182 = F_69 ( V_22 ) ;
if ( V_182 != 0 )
goto V_202;
V_182 = F_75 ( V_22 ) ;
if ( V_182 != 0 )
goto V_203;
V_2 -> V_33 = 0 ;
V_2 -> V_108 = 0 ;
F_13 ( V_22 ) ;
V_2 -> V_33 = 0 ;
V_2 -> V_108 = 0 ;
F_62 ( V_22 ) ;
F_38 ( V_22 ) ;
F_80 ( & V_2 -> V_49 ) ;
return 0 ;
V_203:
F_72 ( V_22 ) ;
V_202:
F_81 ( V_22 -> V_169 , V_22 ) ;
return V_182 ;
}
static int F_52 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
F_41 ( V_22 ) ;
F_3 ( V_2 , V_113 , 0 ) ;
F_3 ( V_2 , V_112 , 0 ) ;
F_3 ( V_2 , V_183 , 0 ) ;
F_82 ( & V_2 -> V_49 ) ;
F_83 ( & V_2 -> V_45 ) ;
F_62 ( V_22 ) ;
F_81 ( V_22 -> V_169 , V_22 ) ;
F_72 ( V_22 ) ;
F_76 ( V_22 ) ;
return 0 ;
}
static int F_84 ( struct V_21 * V_22 , int V_172 )
{
int V_204 ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
if ( ( V_172 > 9500 ) || ( V_172 < 68 ) )
return - V_205 ;
V_22 -> V_172 = V_172 ;
V_204 = F_67 ( V_2 ) ;
if ( ! F_85 ( V_22 ) )
return 0 ;
F_52 ( V_22 ) ;
if ( F_53 ( V_22 ) ) {
F_79 ( & V_22 -> V_22 ,
L_18 ) ;
}
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
int V_206 ;
V_206 = V_2 -> V_104 ;
V_2 -> V_104 = ( V_206 + 1 ) % V_2 -> V_128 ;
F_77 ( V_2 -> V_104 == V_2 -> V_125 ) ;
V_2 -> V_124 ++ ;
return V_206 ;
}
static int F_87 ( struct V_207 * V_49 , int V_139 )
{
struct V_1 * V_2 =
F_51 ( V_49 , struct V_1 , V_49 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
int V_208 = 0 ;
if ( F_65 ( V_2 -> V_122 & V_159 ) ) {
V_2 -> V_122 &= ~ ( V_159 ) ;
F_60 ( V_2 ) ;
}
F_42 ( V_22 , 0 ) ;
if ( F_88 ( V_22 )
&& V_2 -> V_128 - V_2 -> V_124 > 1 ) {
F_89 ( V_22 ) ;
}
V_208 = F_54 ( V_22 , V_139 ) ;
if ( V_208 < V_139 ) {
F_90 ( V_49 ) ;
F_3 ( V_2 , V_113 , V_114 ) ;
}
return V_208 ;
}
static int F_91 ( struct V_23 * V_24 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_140 * V_133 = & V_22 -> V_133 ;
struct V_107 * V_118 ;
int V_119 ;
int V_209 ;
V_119 = F_86 ( V_2 ) ;
V_118 = & V_2 -> V_126 [ V_119 ] ;
V_209 = V_24 -> V_210 ;
V_2 -> V_130 [ V_119 ] = V_24 ;
V_118 -> V_129 = V_209 ;
V_118 -> V_36 = F_17 ( NULL , V_24 -> V_5 , V_209 , V_135 ) ;
F_92 ( V_24 ) ;
F_18 () ;
V_118 -> V_40 = V_41 | V_211 | V_212 |
V_213 | V_214 | V_215 ;
F_18 () ;
F_3 ( V_2 , V_8 , V_216 | V_116 ) ;
V_133 -> V_217 += V_209 ;
V_133 -> V_218 ++ ;
V_22 -> V_219 = V_47 ;
if ( V_2 -> V_128 - V_2 -> V_124 <= 1 ) {
F_93 ( V_22 ) ;
}
return V_220 ;
}
static int F_94 ( struct V_1 * V_2 )
{
int V_52 = 0 ;
for ( V_52 = 0 ; F_1 ( V_2 , V_221 ) & V_222 ; V_52 ++ ) {
if ( V_52 == V_223 )
return - V_224 ;
F_95 ( 10 ) ;
}
return 0 ;
}
static int F_96 ( struct V_225 * V_226 , int V_16 , int V_227 )
{
struct V_1 * V_2 = V_226 -> V_228 ;
int V_52 = 0 ;
int V_89 ;
if ( F_94 ( V_2 ) ) {
F_7 ( V_229 L_19 ) ;
return - V_224 ;
}
F_3 ( V_2 , V_221 , ( V_16 << 16 ) | ( V_227 << 21 ) | V_230 ) ;
for ( V_52 = 0 ; ! ( ( V_89 = F_1 ( V_2 , V_221 ) ) & V_231 ) ; V_52 ++ ) {
if ( V_52 == V_223 ) {
F_7 ( V_229
L_20 ) ;
return - V_232 ;
}
F_95 ( 10 ) ;
}
return V_89 & 0xffff ;
}
static int F_97 ( struct V_225 * V_226 , int V_16 , int V_227 ,
T_5 V_233 )
{
struct V_1 * V_2 = V_226 -> V_228 ;
if ( F_94 ( V_2 ) ) {
F_7 ( V_229 L_19 ) ;
return - V_224 ;
}
F_3 ( V_2 , V_221 , ( V_16 << 16 ) | ( V_227 << 21 ) |
V_234 | ( V_233 & 0xffff ) ) ;
if ( F_94 ( V_2 ) ) {
F_7 ( V_11 L_19 ) ;
return - V_224 ;
}
return 0 ;
}
static int F_98 ( struct V_21 * V_22 , struct V_235 * V_236 ,
int V_103 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
if ( V_2 -> V_18 != NULL )
return F_99 ( V_2 -> V_18 , V_236 , V_103 ) ;
return - V_237 ;
}
static struct V_238 * F_100 ( struct V_1 * V_2 , int V_16 )
{
struct V_225 * V_226 = V_2 -> V_239 ;
struct V_238 * V_240 ;
int V_65 ;
int V_241 ;
int V_52 ;
if ( V_16 == V_242 ) {
V_65 = F_8 ( V_2 ) ;
V_241 = 32 ;
} else {
V_65 = V_16 & 0x1f ;
V_241 = 1 ;
}
V_240 = NULL ;
for ( V_52 = 0 ; V_52 < V_241 ; V_52 ++ ) {
int V_78 = ( V_65 + V_52 ) & 0x1f ;
if ( V_226 -> V_243 [ V_78 ] == NULL )
F_101 ( V_226 , V_78 ) ;
if ( V_240 == NULL ) {
V_240 = V_226 -> V_243 [ V_78 ] ;
if ( V_240 != NULL )
F_9 ( V_2 , V_78 ) ;
}
}
return V_240 ;
}
static void F_102 ( struct V_1 * V_2 , int V_161 , int V_162 )
{
struct V_238 * V_18 = V_2 -> V_18 ;
F_10 ( V_2 ) ;
F_103 ( V_2 -> V_22 , F_104 ( & V_18 -> V_22 ) , V_244 ) ;
if ( V_161 == 0 ) {
V_18 -> V_245 = V_246 ;
V_18 -> V_161 = 0 ;
V_18 -> V_162 = 0 ;
V_18 -> V_247 &= V_248 ;
V_18 -> V_249 = V_18 -> V_247 | V_250 ;
} else {
V_18 -> V_245 = V_251 ;
V_18 -> V_249 = 0 ;
V_18 -> V_161 = V_161 ;
V_18 -> V_162 = V_162 ;
}
F_105 ( V_18 ) ;
}
static int F_106 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
if ( V_2 -> V_252 -> V_253 )
V_2 -> V_252 -> V_253 () ;
V_2 -> V_18 = F_100 ( V_2 , V_2 -> V_252 -> V_16 & 0x1f ) ;
if ( V_2 -> V_18 != NULL )
F_102 ( V_2 , V_2 -> V_252 -> V_161 , V_2 -> V_252 -> V_162 ) ;
F_29 ( V_2 , NULL , V_22 -> V_94 ) ;
return 0 ;
}
static int F_39 ( struct V_21 * V_22 , struct V_102 * V_103 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_182 ;
V_182 = F_107 ( V_2 -> V_18 ) ;
if ( V_182 == 0 )
V_182 = F_108 ( V_2 -> V_18 , V_103 ) ;
return V_182 ;
}
static int F_40 ( struct V_21 * V_22 , struct V_102 * V_103 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
return F_109 ( V_2 -> V_18 , V_103 ) ;
}
static void F_110 ( struct V_21 * V_22 ,
struct V_254 * V_255 )
{
F_111 ( V_255 -> V_256 , V_257 , sizeof( V_255 -> V_256 ) ) ;
F_111 ( V_255 -> V_258 , V_259 , sizeof( V_255 -> V_258 ) ) ;
F_111 ( V_255 -> V_260 , L_21 , sizeof( V_255 -> V_260 ) ) ;
F_111 ( V_255 -> V_261 , L_21 , sizeof( V_255 -> V_261 ) ) ;
}
static int F_112 ( struct V_262 * V_263 )
{
struct V_1 * V_2 = NULL ;
struct V_21 * V_22 = NULL ;
struct V_264 * V_265 ;
struct V_266 * V_266 ;
int V_182 ;
F_7 ( V_267 L_22 ) ;
V_266 = F_113 ( & V_263 -> V_22 , L_23 ) ;
if ( F_114 ( V_266 ) ) {
F_7 ( V_11 L_24 ,
V_257 ) ;
return - V_232 ;
}
F_115 ( V_266 ) ;
V_22 = F_116 ( sizeof( struct V_1 ) ) ;
if ( ! V_22 ) {
V_182 = - V_85 ;
goto V_268;
}
F_117 ( V_263 , V_22 ) ;
V_2 = F_14 ( V_22 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_266 = V_266 ;
V_265 = F_118 ( V_263 , V_269 , 0 ) ;
if ( V_265 == NULL ) {
V_182 = - V_232 ;
goto V_270;
}
V_2 -> V_4 = F_119 ( V_265 -> V_65 , F_120 ( V_265 ) ) ;
if ( V_2 -> V_4 == NULL ) {
V_182 = - V_85 ;
goto V_270;
}
V_265 = F_118 ( V_263 , V_271 , 0 ) ;
F_77 ( ! V_265 ) ;
V_22 -> V_169 = V_265 -> V_65 ;
V_22 -> V_272 = & V_273 ;
V_22 -> V_274 = 2 * V_48 ;
V_22 -> V_275 = 0 ;
F_121 ( V_22 , & V_276 ) ;
F_122 ( & V_2 -> V_136 , F_50 ) ;
F_7 ( V_75 L_25 , V_257 ) ;
F_123 ( V_22 ) ;
V_2 -> V_252 = V_263 -> V_22 . V_277 ;
V_2 -> V_29 = V_278 ;
if ( V_2 -> V_252 -> V_279 )
V_2 -> V_29 = V_2 -> V_252 -> V_279 ;
V_2 -> V_128 = V_280 ;
if ( V_2 -> V_252 -> V_281 )
V_2 -> V_128 = V_2 -> V_252 -> V_281 ;
V_2 -> V_15 = V_2 -> V_252 -> V_282 ;
F_77 ( V_2 -> V_15 > 2 ) ;
F_124 ( V_22 , & V_2 -> V_49 , F_87 , V_2 -> V_29 ) ;
memset ( & V_2 -> V_45 , 0 , sizeof( struct V_283 ) ) ;
F_125 ( & V_2 -> V_45 ) ;
V_2 -> V_45 . V_284 = F_20 ;
V_2 -> V_45 . V_5 = ( unsigned long ) V_2 ;
V_2 -> V_239 = F_126 () ;
if ( V_2 -> V_239 == NULL ) {
V_182 = - V_85 ;
goto V_285;
}
V_2 -> V_239 -> V_228 = V_2 ;
V_2 -> V_239 -> V_132 = L_26 ;
V_2 -> V_239 -> V_286 = F_96 ;
V_2 -> V_239 -> V_287 = F_97 ;
snprintf ( V_2 -> V_239 -> V_288 , V_289 , L_27 ,
V_263 -> V_132 , V_263 -> V_288 ) ;
V_2 -> V_239 -> V_81 = & V_263 -> V_22 ;
V_2 -> V_239 -> V_290 = 0xffffffff ;
V_182 = F_127 ( V_2 -> V_239 ) ;
if ( V_182 )
goto V_291;
F_68 ( V_2 ) ;
V_182 = F_106 ( V_22 ) ;
if ( V_182 )
goto V_292;
F_128 ( V_22 , & V_263 -> V_22 ) ;
V_182 = F_129 ( V_22 ) ;
if ( V_182 )
goto V_292;
return 0 ;
V_292:
F_130 ( V_2 -> V_239 ) ;
V_291:
F_131 ( V_2 -> V_239 ) ;
V_285:
F_132 ( V_2 -> V_4 ) ;
V_270:
F_133 ( V_22 ) ;
V_268:
F_134 ( V_266 ) ;
F_135 ( V_266 ) ;
return V_182 ;
}
static int F_136 ( struct V_262 * V_263 )
{
struct V_21 * V_22 = F_137 ( V_263 ) ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
if ( V_2 -> V_71 ) {
F_74 ( V_2 -> V_22 -> V_22 . V_81 , V_82 ,
V_2 -> V_71 , V_2 -> V_83 ) ;
V_2 -> V_71 = NULL ;
}
if ( V_2 -> V_266 ) {
F_134 ( V_2 -> V_266 ) ;
F_135 ( V_2 -> V_266 ) ;
V_2 -> V_266 = NULL ;
}
if ( V_2 -> V_18 != NULL )
F_138 ( V_2 -> V_18 ) ;
F_132 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
F_130 ( V_2 -> V_239 ) ;
F_131 ( V_2 -> V_239 ) ;
F_139 ( V_22 ) ;
F_140 ( & V_2 -> V_136 ) ;
F_133 ( V_22 ) ;
F_117 ( V_263 , NULL ) ;
return 0 ;
}
static void F_141 ( struct V_262 * V_263 )
{
struct V_21 * V_22 = F_137 ( V_263 ) ;
F_41 ( V_22 ) ;
}
static int F_142 ( struct V_262 * V_263 )
{
return - V_293 ;
}
static int F_143 ( struct V_262 * V_263 , T_6 V_294 )
{
return - V_293 ;
}
