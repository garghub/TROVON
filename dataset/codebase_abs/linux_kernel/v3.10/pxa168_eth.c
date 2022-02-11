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
& V_2 -> V_83 ,
V_84 | V_85 ) ;
if ( V_2 -> V_71 == NULL )
return - V_86 ;
} else {
memset ( V_2 -> V_71 , 0 , V_82 ) ;
}
F_3 ( V_2 , V_87 , V_2 -> V_83 ) ;
return 0 ;
}
static void F_32 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_88 * V_89 ;
T_1 V_90 ;
V_90 = F_1 ( V_2 , V_91 ) ;
if ( V_22 -> V_92 & V_93 )
V_90 |= V_94 ;
else
V_90 &= ~ V_94 ;
F_3 ( V_2 , V_91 , V_90 ) ;
memset ( V_2 -> V_71 , 0 , V_82 ) ;
F_29 ( V_2 , NULL , V_22 -> V_95 ) ;
F_33 (ha, dev)
F_29 ( V_2 , NULL , V_89 -> V_78 ) ;
}
static int F_34 ( struct V_21 * V_22 , void * V_78 )
{
struct V_96 * V_97 = V_78 ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
unsigned char V_98 [ V_53 ] ;
if ( ! F_35 ( V_97 -> V_99 ) )
return - V_100 ;
memcpy ( V_98 , V_22 -> V_95 , V_53 ) ;
memcpy ( V_22 -> V_95 , V_97 -> V_99 , V_53 ) ;
F_36 ( V_22 ) ;
F_29 ( V_2 , V_98 , V_22 -> V_95 ) ;
F_37 ( V_22 ) ;
return 0 ;
}
static void F_38 ( struct V_21 * V_22 )
{
unsigned int V_90 = 0 ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_101 , V_102 ;
if ( V_2 -> V_18 != NULL ) {
struct V_103 V_104 ;
F_39 ( V_2 -> V_22 , & V_104 ) ;
F_10 ( V_2 ) ;
F_40 ( V_2 -> V_22 , & V_104 ) ;
}
V_101 = V_2 -> V_105 ;
F_3 ( V_2 , V_106 ,
( T_1 ) ( V_2 -> V_107 + V_101 * sizeof( struct V_108 ) ) ) ;
V_102 = V_2 -> V_109 ;
F_3 ( V_2 , V_110 ,
( T_1 ) ( V_2 -> V_111 + V_102 * sizeof( struct V_25 ) ) ) ;
F_3 ( V_2 , V_112 ,
( T_1 ) ( V_2 -> V_111 + V_102 * sizeof( struct V_25 ) ) ) ;
F_3 ( V_2 , V_113 , 0 ) ;
F_3 ( V_2 , V_114 , V_115 ) ;
V_90 = F_1 ( V_2 , V_91 ) ;
V_90 |= V_116 ;
F_3 ( V_2 , V_91 , V_90 ) ;
V_90 = F_1 ( V_2 , V_8 ) ;
V_90 |= V_117 ;
F_3 ( V_2 , V_8 , V_90 ) ;
}
static void F_41 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
unsigned int V_90 = 0 ;
F_3 ( V_2 , V_114 , 0 ) ;
F_3 ( V_2 , V_113 , 0 ) ;
V_90 = F_1 ( V_2 , V_8 ) ;
V_90 &= ~ V_117 ;
F_5 ( V_2 ) ;
V_90 = F_1 ( V_2 , V_91 ) ;
V_90 &= ~ V_116 ;
F_3 ( V_2 , V_91 , V_90 ) ;
}
static int F_42 ( struct V_21 * V_22 , int V_118 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_108 * V_119 ;
T_1 V_40 ;
struct V_23 * V_24 ;
int V_120 ;
T_3 V_78 ;
int V_121 ;
int V_122 = 0 ;
F_43 ( V_22 ) ;
V_2 -> V_123 &= ~ V_124 ;
while ( V_2 -> V_125 > 0 ) {
V_120 = V_2 -> V_126 ;
V_119 = & V_2 -> V_127 [ V_120 ] ;
V_40 = V_119 -> V_40 ;
if ( ! V_118 && ( V_40 & V_41 ) ) {
if ( V_122 > 0 ) {
goto V_128;
} else {
V_122 = - 1 ;
goto V_128;
}
}
V_2 -> V_126 = ( V_120 + 1 ) % V_2 -> V_129 ;
V_2 -> V_125 -- ;
V_78 = V_119 -> V_36 ;
V_121 = V_119 -> V_130 ;
V_24 = V_2 -> V_131 [ V_120 ] ;
if ( V_24 )
V_2 -> V_131 [ V_120 ] = NULL ;
if ( V_40 & V_132 ) {
if ( F_44 () )
F_7 ( V_11 L_4 , V_22 -> V_133 ) ;
V_22 -> V_134 . V_135 ++ ;
}
F_45 ( NULL , V_78 , V_121 , V_136 ) ;
if ( V_24 )
F_46 ( V_24 ) ;
V_122 ++ ;
}
V_128:
F_47 ( V_22 ) ;
return V_122 ;
}
static void F_48 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
F_7 ( V_75 L_5 ,
V_22 -> V_133 , V_2 -> V_125 ) ;
F_49 ( & V_2 -> V_137 ) ;
}
static void F_50 ( struct V_138 * V_139 )
{
struct V_1 * V_2 = F_51 ( V_139 ,
struct V_1 ,
V_137 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
F_52 ( V_22 ) ;
F_53 ( V_22 ) ;
}
static int F_54 ( struct V_21 * V_22 , int V_140 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_141 * V_134 = & V_22 -> V_134 ;
unsigned int V_142 = 0 ;
struct V_23 * V_24 ;
while ( V_140 -- > 0 ) {
int V_143 , V_102 , V_144 ;
struct V_25 * V_25 ;
unsigned int V_40 ;
if ( V_2 -> V_43 )
break;
V_102 = V_2 -> V_109 ;
V_144 = V_2 -> V_33 ;
V_25 = & V_2 -> V_34 [ V_102 ] ;
V_40 = V_25 -> V_40 ;
F_55 () ;
if ( V_40 & ( V_41 ) )
break;
V_24 = V_2 -> V_39 [ V_102 ] ;
V_2 -> V_39 [ V_102 ] = NULL ;
V_143 = ( V_102 + 1 ) % V_2 -> V_29 ;
V_2 -> V_109 = V_143 ;
if ( V_143 == V_144 )
V_2 -> V_43 = 1 ;
V_2 -> V_28 -- ;
F_45 ( NULL , V_25 -> V_36 ,
V_25 -> V_38 ,
V_37 ) ;
V_142 ++ ;
V_134 -> V_145 ++ ;
V_134 -> V_146 += V_25 -> V_130 ;
if ( ( ( V_40 & ( V_147 | V_148 ) ) !=
( V_147 | V_148 ) )
|| ( V_40 & V_149 ) ) {
V_134 -> V_150 ++ ;
if ( ( V_40 & ( V_147 | V_148 ) ) !=
( V_147 | V_148 ) ) {
if ( F_44 () )
F_7 ( V_11
L_6 ,
V_22 -> V_133 ) ;
}
if ( V_40 & V_149 )
V_134 -> V_151 ++ ;
F_46 ( V_24 ) ;
} else {
F_56 ( V_24 , V_25 -> V_130 - 4 ) ;
V_24 -> V_152 = F_57 ( V_24 , V_22 ) ;
F_58 ( V_24 ) ;
}
}
F_13 ( V_22 ) ;
return V_142 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
T_1 V_153 ;
int V_154 = 0 ;
V_153 = F_1 ( V_2 , V_113 ) ;
if ( V_153 == 0 )
return V_155 ;
F_3 ( V_2 , V_113 , ~ V_153 ) ;
if ( V_153 & ( V_156 | V_157 ) ) {
V_2 -> V_123 |= V_124 ;
V_154 = 1 ;
}
if ( V_153 & V_158 )
V_154 = 1 ;
if ( V_153 & V_159 ) {
V_2 -> V_123 |= V_160 ;
V_154 = 1 ;
}
return V_154 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_161 ;
int V_162 ;
int V_163 ;
int V_164 ;
V_161 = F_1 ( V_2 , V_165 ) ;
if ( ! ( V_161 & V_166 ) ) {
if ( F_61 ( V_22 ) ) {
F_7 ( V_75 L_7 , V_22 -> V_133 ) ;
F_62 ( V_22 ) ;
F_42 ( V_22 , 1 ) ;
}
return;
}
if ( V_161 & V_167 )
V_162 = 100 ;
else
V_162 = 10 ;
V_163 = ( V_161 & V_168 ) ? 1 : 0 ;
V_164 = ( V_161 & V_169 ) ? 1 : 0 ;
F_7 ( V_75 L_8
L_9 , V_22 -> V_133 ,
V_162 , V_163 ? L_10 : L_11 , V_164 ? L_12 : L_13 ) ;
if ( ! F_61 ( V_22 ) )
F_63 ( V_22 ) ;
}
static T_4 F_64 ( int V_170 , void * V_171 )
{
struct V_21 * V_22 = (struct V_21 * ) V_171 ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
if ( F_65 ( ! F_59 ( V_2 , V_22 ) ) )
return V_155 ;
F_3 ( V_2 , V_114 , 0 ) ;
F_21 ( & V_2 -> V_49 ) ;
return V_172 ;
}
static void F_66 ( struct V_1 * V_2 )
{
int V_31 ;
V_31 = V_2 -> V_22 -> V_173 + 36 ;
V_2 -> V_31 = ( V_31 + 7 ) & ~ 7 ;
V_2 -> V_31 += V_32 ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_31 ;
F_66 ( V_2 ) ;
if ( V_2 -> V_31 <= 1518 )
V_31 = V_174 ;
else if ( V_2 -> V_31 <= 1536 )
V_31 = V_175 ;
else if ( V_2 -> V_31 <= 2048 )
V_31 = V_176 ;
else
V_31 = V_177 ;
F_3 ( V_2 ,
V_178 , V_179 |
V_180 |
V_31 | V_181 |
V_182 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_183 = 0 ;
F_3 ( V_2 , V_114 , 0 ) ;
F_3 ( V_2 , V_113 , 0 ) ;
F_3 ( V_2 , V_184 , 0 ) ;
F_5 ( V_2 ) ;
V_183 = F_30 ( V_2 ) ;
if ( V_183 )
return V_183 ;
F_3 ( V_2 , V_185 , V_186 |
V_187 |
V_188 |
V_189 |
V_190 ) ;
F_3 ( V_2 , V_91 , V_191 ) ;
F_67 ( V_2 ) ;
return V_183 ;
}
static int F_69 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_25 * V_192 ;
int V_30 = 0 , V_52 = 0 ;
int V_193 = V_2 -> V_29 ;
V_2 -> V_39 = F_70 ( sizeof( * V_2 -> V_39 ) * V_2 -> V_29 ,
V_84 ) ;
if ( ! V_2 -> V_39 )
return - V_86 ;
V_2 -> V_28 = 0 ;
V_30 = V_2 -> V_29 * sizeof( struct V_25 ) ;
V_2 -> V_194 = V_30 ;
V_2 -> V_34 = F_31 ( V_2 -> V_22 -> V_22 . V_81 , V_30 ,
& V_2 -> V_111 ,
V_84 | V_85 ) ;
if ( ! V_2 -> V_34 )
goto V_195;
V_192 = V_2 -> V_34 ;
for ( V_52 = 0 ; V_52 < V_193 ; V_52 ++ ) {
V_192 [ V_52 ] . V_196 = V_2 -> V_111 +
( ( V_52 + 1 ) % V_193 ) * sizeof( struct V_25 ) ;
}
V_2 -> V_109 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_194 = V_193 * sizeof( struct V_25 ) ;
return 0 ;
V_195:
F_71 ( V_2 -> V_39 ) ;
return - V_86 ;
}
static void F_72 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_197 ;
for ( V_197 = 0 ; V_2 -> V_28 && V_197 < V_2 -> V_29 ; V_197 ++ ) {
if ( V_2 -> V_39 [ V_197 ] ) {
F_73 ( V_2 -> V_39 [ V_197 ] ) ;
V_2 -> V_28 -- ;
}
}
if ( V_2 -> V_28 )
F_7 ( V_11
L_14 ,
V_2 -> V_28 ) ;
if ( V_2 -> V_34 )
F_74 ( V_2 -> V_22 -> V_22 . V_81 , V_2 -> V_194 ,
V_2 -> V_34 , V_2 -> V_111 ) ;
F_71 ( V_2 -> V_39 ) ;
}
static int F_75 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_108 * V_198 ;
int V_30 = 0 , V_52 = 0 ;
int V_199 = V_2 -> V_129 ;
V_2 -> V_131 = F_70 ( sizeof( * V_2 -> V_131 ) * V_2 -> V_129 ,
V_84 ) ;
if ( ! V_2 -> V_131 )
return - V_86 ;
V_2 -> V_125 = 0 ;
V_30 = V_2 -> V_129 * sizeof( struct V_108 ) ;
V_2 -> V_200 = V_30 ;
V_2 -> V_127 = F_31 ( V_2 -> V_22 -> V_22 . V_81 , V_30 ,
& V_2 -> V_107 ,
V_84 | V_85 ) ;
if ( ! V_2 -> V_127 )
goto V_195;
V_198 = V_2 -> V_127 ;
for ( V_52 = 0 ; V_52 < V_199 ; V_52 ++ ) {
V_198 [ V_52 ] . V_196 = V_2 -> V_107 +
( ( V_52 + 1 ) % V_199 ) * sizeof( struct V_108 ) ;
}
V_2 -> V_105 = 0 ;
V_2 -> V_126 = 0 ;
V_2 -> V_200 = V_199 * sizeof( struct V_108 ) ;
return 0 ;
V_195:
F_71 ( V_2 -> V_131 ) ;
return - V_86 ;
}
static void F_76 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
F_42 ( V_22 , 1 ) ;
F_77 ( V_2 -> V_126 != V_2 -> V_105 ) ;
if ( V_2 -> V_127 )
F_74 ( V_2 -> V_22 -> V_22 . V_81 , V_2 -> V_200 ,
V_2 -> V_127 , V_2 -> V_107 ) ;
F_71 ( V_2 -> V_131 ) ;
}
static int F_53 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_183 ;
V_183 = F_78 ( V_22 -> V_170 , F_64 ,
V_201 , V_22 -> V_133 , V_22 ) ;
if ( V_183 ) {
F_79 ( & V_22 -> V_22 , L_15 ) ;
return - V_202 ;
}
V_2 -> V_43 = 0 ;
V_183 = F_69 ( V_22 ) ;
if ( V_183 != 0 )
goto V_203;
V_183 = F_75 ( V_22 ) ;
if ( V_183 != 0 )
goto V_204;
V_2 -> V_33 = 0 ;
V_2 -> V_109 = 0 ;
F_13 ( V_22 ) ;
V_2 -> V_33 = 0 ;
V_2 -> V_109 = 0 ;
F_62 ( V_22 ) ;
F_38 ( V_22 ) ;
F_80 ( & V_2 -> V_49 ) ;
return 0 ;
V_204:
F_72 ( V_22 ) ;
V_203:
F_81 ( V_22 -> V_170 , V_22 ) ;
return V_183 ;
}
static int F_52 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
F_41 ( V_22 ) ;
F_3 ( V_2 , V_114 , 0 ) ;
F_3 ( V_2 , V_113 , 0 ) ;
F_3 ( V_2 , V_184 , 0 ) ;
F_82 ( & V_2 -> V_49 ) ;
F_83 ( & V_2 -> V_45 ) ;
F_62 ( V_22 ) ;
F_81 ( V_22 -> V_170 , V_22 ) ;
F_72 ( V_22 ) ;
F_76 ( V_22 ) ;
return 0 ;
}
static int F_84 ( struct V_21 * V_22 , int V_173 )
{
int V_205 ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
if ( ( V_173 > 9500 ) || ( V_173 < 68 ) )
return - V_206 ;
V_22 -> V_173 = V_173 ;
V_205 = F_67 ( V_2 ) ;
if ( ! F_85 ( V_22 ) )
return 0 ;
F_52 ( V_22 ) ;
if ( F_53 ( V_22 ) ) {
F_79 ( & V_22 -> V_22 ,
L_16 ) ;
}
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
int V_207 ;
V_207 = V_2 -> V_105 ;
V_2 -> V_105 = ( V_207 + 1 ) % V_2 -> V_129 ;
F_77 ( V_2 -> V_105 == V_2 -> V_126 ) ;
V_2 -> V_125 ++ ;
return V_207 ;
}
static int F_87 ( struct V_208 * V_49 , int V_140 )
{
struct V_1 * V_2 =
F_51 ( V_49 , struct V_1 , V_49 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
int V_209 = 0 ;
if ( F_65 ( V_2 -> V_123 & V_160 ) ) {
V_2 -> V_123 &= ~ ( V_160 ) ;
F_60 ( V_2 ) ;
}
F_42 ( V_22 , 0 ) ;
if ( F_88 ( V_22 )
&& V_2 -> V_129 - V_2 -> V_125 > 1 ) {
F_89 ( V_22 ) ;
}
V_209 = F_54 ( V_22 , V_140 ) ;
if ( V_209 < V_140 ) {
F_90 ( V_49 ) ;
F_3 ( V_2 , V_114 , V_115 ) ;
}
return V_209 ;
}
static int F_91 ( struct V_23 * V_24 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_141 * V_134 = & V_22 -> V_134 ;
struct V_108 * V_119 ;
int V_120 ;
int V_210 ;
V_120 = F_86 ( V_2 ) ;
V_119 = & V_2 -> V_127 [ V_120 ] ;
V_210 = V_24 -> V_211 ;
V_2 -> V_131 [ V_120 ] = V_24 ;
V_119 -> V_130 = V_210 ;
V_119 -> V_36 = F_17 ( NULL , V_24 -> V_5 , V_210 , V_136 ) ;
F_92 ( V_24 ) ;
F_18 () ;
V_119 -> V_40 = V_41 | V_212 | V_213 |
V_214 | V_215 | V_216 ;
F_18 () ;
F_3 ( V_2 , V_8 , V_217 | V_117 ) ;
V_134 -> V_218 += V_210 ;
V_134 -> V_219 ++ ;
V_22 -> V_220 = V_47 ;
if ( V_2 -> V_129 - V_2 -> V_125 <= 1 ) {
F_93 ( V_22 ) ;
}
return V_221 ;
}
static int F_94 ( struct V_1 * V_2 )
{
int V_52 = 0 ;
for ( V_52 = 0 ; F_1 ( V_2 , V_222 ) & V_223 ; V_52 ++ ) {
if ( V_52 == V_224 )
return - V_225 ;
F_95 ( 10 ) ;
}
return 0 ;
}
static int F_96 ( struct V_226 * V_227 , int V_16 , int V_228 )
{
struct V_1 * V_2 = V_227 -> V_229 ;
int V_52 = 0 ;
int V_90 ;
if ( F_94 ( V_2 ) ) {
F_7 ( V_230 L_17 ) ;
return - V_225 ;
}
F_3 ( V_2 , V_222 , ( V_16 << 16 ) | ( V_228 << 21 ) | V_231 ) ;
for ( V_52 = 0 ; ! ( ( V_90 = F_1 ( V_2 , V_222 ) ) & V_232 ) ; V_52 ++ ) {
if ( V_52 == V_224 ) {
F_7 ( V_230
L_18 ) ;
return - V_233 ;
}
F_95 ( 10 ) ;
}
return V_90 & 0xffff ;
}
static int F_97 ( struct V_226 * V_227 , int V_16 , int V_228 ,
T_5 V_234 )
{
struct V_1 * V_2 = V_227 -> V_229 ;
if ( F_94 ( V_2 ) ) {
F_7 ( V_230 L_17 ) ;
return - V_225 ;
}
F_3 ( V_2 , V_222 , ( V_16 << 16 ) | ( V_228 << 21 ) |
V_235 | ( V_234 & 0xffff ) ) ;
if ( F_94 ( V_2 ) ) {
F_7 ( V_11 L_17 ) ;
return - V_225 ;
}
return 0 ;
}
static int F_98 ( struct V_21 * V_22 , struct V_236 * V_237 ,
int V_104 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
if ( V_2 -> V_18 != NULL )
return F_99 ( V_2 -> V_18 , V_237 , V_104 ) ;
return - V_238 ;
}
static struct V_239 * F_100 ( struct V_1 * V_2 , int V_16 )
{
struct V_226 * V_227 = V_2 -> V_240 ;
struct V_239 * V_241 ;
int V_65 ;
int V_242 ;
int V_52 ;
if ( V_16 == V_243 ) {
V_65 = F_8 ( V_2 ) ;
V_242 = 32 ;
} else {
V_65 = V_16 & 0x1f ;
V_242 = 1 ;
}
V_241 = NULL ;
for ( V_52 = 0 ; V_52 < V_242 ; V_52 ++ ) {
int V_78 = ( V_65 + V_52 ) & 0x1f ;
if ( V_227 -> V_244 [ V_78 ] == NULL )
F_101 ( V_227 , V_78 ) ;
if ( V_241 == NULL ) {
V_241 = V_227 -> V_244 [ V_78 ] ;
if ( V_241 != NULL )
F_9 ( V_2 , V_78 ) ;
}
}
return V_241 ;
}
static void F_102 ( struct V_1 * V_2 , int V_162 , int V_163 )
{
struct V_239 * V_18 = V_2 -> V_18 ;
F_10 ( V_2 ) ;
F_103 ( V_2 -> V_22 , F_104 ( & V_18 -> V_22 ) , V_245 ) ;
if ( V_162 == 0 ) {
V_18 -> V_246 = V_247 ;
V_18 -> V_162 = 0 ;
V_18 -> V_163 = 0 ;
V_18 -> V_248 &= V_249 ;
V_18 -> V_250 = V_18 -> V_248 | V_251 ;
} else {
V_18 -> V_246 = V_252 ;
V_18 -> V_250 = 0 ;
V_18 -> V_162 = V_162 ;
V_18 -> V_163 = V_163 ;
}
F_105 ( V_18 ) ;
}
static int F_106 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
if ( V_2 -> V_253 -> V_254 )
V_2 -> V_253 -> V_254 () ;
V_2 -> V_18 = F_100 ( V_2 , V_2 -> V_253 -> V_16 & 0x1f ) ;
if ( V_2 -> V_18 != NULL )
F_102 ( V_2 , V_2 -> V_253 -> V_162 , V_2 -> V_253 -> V_163 ) ;
F_29 ( V_2 , NULL , V_22 -> V_95 ) ;
return 0 ;
}
static int F_39 ( struct V_21 * V_22 , struct V_103 * V_104 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_183 ;
V_183 = F_107 ( V_2 -> V_18 ) ;
if ( V_183 == 0 )
V_183 = F_108 ( V_2 -> V_18 , V_104 ) ;
return V_183 ;
}
static int F_40 ( struct V_21 * V_22 , struct V_103 * V_104 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
return F_109 ( V_2 -> V_18 , V_104 ) ;
}
static void F_110 ( struct V_21 * V_22 ,
struct V_255 * V_256 )
{
F_111 ( V_256 -> V_257 , V_258 , sizeof( V_256 -> V_257 ) ) ;
F_111 ( V_256 -> V_259 , V_260 , sizeof( V_256 -> V_259 ) ) ;
F_111 ( V_256 -> V_261 , L_19 , sizeof( V_256 -> V_261 ) ) ;
F_111 ( V_256 -> V_262 , L_19 , sizeof( V_256 -> V_262 ) ) ;
}
static int F_112 ( struct V_263 * V_264 )
{
struct V_1 * V_2 = NULL ;
struct V_21 * V_22 = NULL ;
struct V_265 * V_266 ;
struct V_267 * V_267 ;
int V_183 ;
F_7 ( V_268 L_20 ) ;
V_267 = F_113 ( & V_264 -> V_22 , L_21 ) ;
if ( F_114 ( V_267 ) ) {
F_7 ( V_11 L_22 ,
V_258 ) ;
return - V_233 ;
}
F_115 ( V_267 ) ;
V_22 = F_116 ( sizeof( struct V_1 ) ) ;
if ( ! V_22 ) {
V_183 = - V_86 ;
goto V_269;
}
F_117 ( V_264 , V_22 ) ;
V_2 = F_14 ( V_22 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_267 = V_267 ;
V_266 = F_118 ( V_264 , V_270 , 0 ) ;
if ( V_266 == NULL ) {
V_183 = - V_233 ;
goto V_271;
}
V_2 -> V_4 = F_119 ( V_266 -> V_65 , F_120 ( V_266 ) ) ;
if ( V_2 -> V_4 == NULL ) {
V_183 = - V_86 ;
goto V_271;
}
V_266 = F_118 ( V_264 , V_272 , 0 ) ;
F_77 ( ! V_266 ) ;
V_22 -> V_170 = V_266 -> V_65 ;
V_22 -> V_273 = & V_274 ;
V_22 -> V_275 = 2 * V_48 ;
V_22 -> V_276 = 0 ;
F_121 ( V_22 , & V_277 ) ;
F_122 ( & V_2 -> V_137 , F_50 ) ;
F_7 ( V_75 L_23 , V_258 ) ;
F_123 ( V_22 ) ;
V_2 -> V_253 = V_264 -> V_22 . V_278 ;
V_2 -> V_29 = V_279 ;
if ( V_2 -> V_253 -> V_280 )
V_2 -> V_29 = V_2 -> V_253 -> V_280 ;
V_2 -> V_129 = V_281 ;
if ( V_2 -> V_253 -> V_282 )
V_2 -> V_129 = V_2 -> V_253 -> V_282 ;
V_2 -> V_15 = V_2 -> V_253 -> V_283 ;
F_77 ( V_2 -> V_15 > 2 ) ;
F_124 ( V_22 , & V_2 -> V_49 , F_87 , V_2 -> V_29 ) ;
memset ( & V_2 -> V_45 , 0 , sizeof( struct V_284 ) ) ;
F_125 ( & V_2 -> V_45 ) ;
V_2 -> V_45 . V_285 = F_20 ;
V_2 -> V_45 . V_5 = ( unsigned long ) V_2 ;
V_2 -> V_240 = F_126 () ;
if ( V_2 -> V_240 == NULL ) {
V_183 = - V_86 ;
goto V_286;
}
V_2 -> V_240 -> V_229 = V_2 ;
V_2 -> V_240 -> V_133 = L_24 ;
V_2 -> V_240 -> V_287 = F_96 ;
V_2 -> V_240 -> V_288 = F_97 ;
snprintf ( V_2 -> V_240 -> V_289 , V_290 , L_25 ,
V_264 -> V_133 , V_264 -> V_289 ) ;
V_2 -> V_240 -> V_81 = & V_264 -> V_22 ;
V_2 -> V_240 -> V_291 = 0xffffffff ;
V_183 = F_127 ( V_2 -> V_240 ) ;
if ( V_183 )
goto V_292;
F_68 ( V_2 ) ;
V_183 = F_106 ( V_22 ) ;
if ( V_183 )
goto V_293;
F_128 ( V_22 , & V_264 -> V_22 ) ;
V_183 = F_129 ( V_22 ) ;
if ( V_183 )
goto V_293;
return 0 ;
V_293:
F_130 ( V_2 -> V_240 ) ;
V_292:
F_131 ( V_2 -> V_240 ) ;
V_286:
F_132 ( V_2 -> V_4 ) ;
V_271:
F_133 ( V_22 ) ;
V_269:
F_134 ( V_267 ) ;
F_135 ( V_267 ) ;
return V_183 ;
}
static int F_136 ( struct V_263 * V_264 )
{
struct V_21 * V_22 = F_137 ( V_264 ) ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
if ( V_2 -> V_71 ) {
F_74 ( V_2 -> V_22 -> V_22 . V_81 , V_82 ,
V_2 -> V_71 , V_2 -> V_83 ) ;
V_2 -> V_71 = NULL ;
}
if ( V_2 -> V_267 ) {
F_134 ( V_2 -> V_267 ) ;
F_135 ( V_2 -> V_267 ) ;
V_2 -> V_267 = NULL ;
}
if ( V_2 -> V_18 != NULL )
F_138 ( V_2 -> V_18 ) ;
F_132 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
F_130 ( V_2 -> V_240 ) ;
F_131 ( V_2 -> V_240 ) ;
F_139 ( V_22 ) ;
F_140 ( & V_2 -> V_137 ) ;
F_133 ( V_22 ) ;
F_117 ( V_264 , NULL ) ;
return 0 ;
}
static void F_141 ( struct V_263 * V_264 )
{
struct V_21 * V_22 = F_137 ( V_264 ) ;
F_41 ( V_22 ) ;
}
static int F_142 ( struct V_263 * V_264 )
{
return - V_294 ;
}
static int F_143 ( struct V_263 * V_264 , T_6 V_295 )
{
return - V_294 ;
}
