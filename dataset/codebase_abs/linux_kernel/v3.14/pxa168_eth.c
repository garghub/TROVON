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
static void F_10 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
int V_24 ;
while ( V_2 -> V_25 < V_2 -> V_26 ) {
int V_27 ;
V_21 = F_12 ( V_19 , V_2 -> V_28 ) ;
if ( ! V_21 )
break;
if ( V_29 )
F_13 ( V_21 , V_29 ) ;
V_2 -> V_25 ++ ;
V_24 = V_2 -> V_30 ;
V_23 = & V_2 -> V_31 [ V_24 ] ;
V_27 = F_14 ( V_21 ) - V_21 -> V_5 ;
V_23 -> V_32 = F_15 ( NULL ,
V_21 -> V_5 ,
V_27 ,
V_33 ) ;
V_23 -> V_34 = V_27 ;
V_2 -> V_35 [ V_24 ] = V_21 ;
F_16 () ;
V_23 -> V_36 = V_37 | V_38 ;
F_16 () ;
V_2 -> V_30 = ( V_24 + 1 ) % V_2 -> V_26 ;
V_2 -> V_39 = 0 ;
F_13 ( V_21 , V_40 ) ;
}
if ( V_2 -> V_25 == 0 ) {
V_2 -> V_41 . V_42 = V_43 + ( V_44 / 10 ) ;
F_17 ( & V_2 -> V_41 ) ;
}
}
static inline void F_18 ( unsigned long V_5 )
{
struct V_1 * V_2 = ( void * ) V_5 ;
F_19 ( & V_2 -> V_45 ) ;
}
static inline T_2 F_20 ( T_2 V_46 )
{
return ( ( ( V_46 ) & 0x01 ) << 3 ) | ( ( ( V_46 ) & 0x02 ) << 1 )
| ( ( ( V_46 ) & 0x04 ) >> 1 ) | ( ( ( V_46 ) & 0x08 ) >> 3 )
| ( ( ( V_46 ) & 0x10 ) << 3 ) | ( ( ( V_46 ) & 0x20 ) << 1 )
| ( ( ( V_46 ) & 0x40 ) >> 1 ) | ( ( ( V_46 ) & 0x80 ) >> 3 ) ;
}
static void F_21 ( unsigned char * V_47 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ ) {
V_47 [ V_48 ] = ( ( V_47 [ V_48 ] & 0x0f ) << 4 ) |
( ( V_47 [ V_48 ] & 0xf0 ) >> 4 ) ;
}
}
static void F_22 ( unsigned char * V_47 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ )
V_47 [ V_48 ] = F_20 ( V_47 [ V_48 ] ) ;
}
static T_1 F_23 ( unsigned char * V_50 )
{
T_1 V_51 ;
T_1 V_52 ;
T_1 V_53 ;
T_1 V_54 ;
T_1 V_55 ;
unsigned char V_47 [ V_49 ] ;
memcpy ( V_47 , V_50 , V_49 ) ;
F_21 ( V_47 ) ;
F_22 ( V_47 ) ;
V_52 = ( V_47 [ 5 ] >> 2 ) & 0x3f ;
V_53 = ( V_47 [ 5 ] & 0x03 ) | ( ( ( V_47 [ 4 ] & 0x7f ) ) << 2 ) ;
V_54 = ( ( V_47 [ 4 ] & 0x80 ) >> 7 ) | V_47 [ 3 ] << 1 ;
V_55 = ( V_47 [ 2 ] & 0xff ) | ( ( V_47 [ 1 ] & 1 ) << 8 ) ;
V_51 = ( V_52 << 9 ) | ( V_53 ^ V_54 ^ V_55 ) ;
V_51 = V_51 & 0x07ff ;
return V_51 ;
}
static int F_24 ( struct V_1 * V_2 ,
unsigned char * V_47 ,
T_1 V_56 , T_1 V_57 , int V_58 )
{
struct V_59 * V_60 , * V_61 ;
T_1 V_62 ;
T_1 V_63 ;
T_1 V_48 ;
V_63 = ( ( ( V_47 [ 1 ] >> 4 ) & 0xf ) << 15 )
| ( ( ( V_47 [ 1 ] >> 0 ) & 0xf ) << 11 )
| ( ( ( V_47 [ 0 ] >> 4 ) & 0xf ) << 7 )
| ( ( ( V_47 [ 0 ] >> 0 ) & 0xf ) << 3 )
| ( ( ( V_47 [ 3 ] >> 4 ) & 0x1 ) << 31 )
| ( ( ( V_47 [ 3 ] >> 0 ) & 0xf ) << 27 )
| ( ( ( V_47 [ 2 ] >> 4 ) & 0xf ) << 23 )
| ( ( ( V_47 [ 2 ] >> 0 ) & 0xf ) << 19 )
| ( V_57 << V_64 ) | ( V_56 << V_65 )
| V_66 ;
V_62 = ( ( ( V_47 [ 5 ] >> 4 ) & 0xf ) << 15 )
| ( ( ( V_47 [ 5 ] >> 0 ) & 0xf ) << 11 )
| ( ( ( V_47 [ 4 ] >> 4 ) & 0xf ) << 7 )
| ( ( ( V_47 [ 4 ] >> 0 ) & 0xf ) << 3 )
| ( ( ( V_47 [ 3 ] >> 5 ) & 0x7 ) << 0 ) ;
V_61 = V_2 -> V_67 ;
V_60 = V_61 + F_23 ( V_47 ) ;
for ( V_48 = 0 ; V_48 < V_68 ; V_48 ++ ) {
if ( ! ( F_25 ( V_60 -> V_69 ) & V_66 ) ) {
break;
} else {
if ( ( ( F_25 ( V_60 -> V_69 ) & 0xfffffff8 ) ==
( V_63 & 0xfffffff8 ) ) &&
( F_25 ( V_60 -> V_70 ) == V_62 ) ) {
break;
}
}
if ( V_60 == V_61 + 0x7ff )
V_60 = V_61 ;
else
V_60 ++ ;
}
if ( ( ( F_25 ( V_60 -> V_69 ) & 0xfffffff8 ) != ( V_63 & 0xfffffff8 ) ) &&
( F_25 ( V_60 -> V_70 ) != V_62 ) && V_58 )
return 0 ;
if ( V_48 == V_68 ) {
if ( ! V_58 ) {
F_7 ( V_71 L_2
L_3 ,
__FILE__ ) ;
return - V_72 ;
} else
return 0 ;
}
if ( V_58 ) {
V_60 -> V_70 = 0 ;
V_60 -> V_69 = 0 ;
} else {
V_60 -> V_70 = F_26 ( V_62 ) ;
V_60 -> V_69 = F_26 ( V_63 ) ;
}
return 0 ;
}
static void F_27 ( struct V_1 * V_2 ,
unsigned char * V_73 ,
unsigned char * V_74 )
{
if ( V_73 )
F_24 ( V_2 , V_73 , 1 , 0 , V_75 ) ;
F_24 ( V_2 , V_74 , 1 , 0 , V_76 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
if ( V_2 -> V_67 == NULL ) {
V_2 -> V_67 = F_29 ( V_2 -> V_19 -> V_19 . V_77 ,
V_78 ,
& V_2 -> V_79 , V_80 ) ;
if ( V_2 -> V_67 == NULL )
return - V_81 ;
} else {
memset ( V_2 -> V_67 , 0 , V_78 ) ;
}
F_3 ( V_2 , V_82 , V_2 -> V_79 ) ;
return 0 ;
}
static void F_30 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
struct V_83 * V_84 ;
T_1 V_85 ;
V_85 = F_1 ( V_2 , V_86 ) ;
if ( V_19 -> V_87 & V_88 )
V_85 |= V_89 ;
else
V_85 &= ~ V_89 ;
F_3 ( V_2 , V_86 , V_85 ) ;
memset ( V_2 -> V_67 , 0 , V_78 ) ;
F_27 ( V_2 , NULL , V_19 -> V_90 ) ;
F_31 (ha, dev)
F_27 ( V_2 , NULL , V_84 -> V_74 ) ;
}
static int F_32 ( struct V_18 * V_19 , void * V_74 )
{
struct V_91 * V_92 = V_74 ;
struct V_1 * V_2 = F_11 ( V_19 ) ;
unsigned char V_93 [ V_49 ] ;
if ( ! F_33 ( V_92 -> V_94 ) )
return - V_95 ;
memcpy ( V_93 , V_19 -> V_90 , V_49 ) ;
memcpy ( V_19 -> V_90 , V_92 -> V_94 , V_49 ) ;
F_34 ( V_19 ) ;
F_27 ( V_2 , V_93 , V_19 -> V_90 ) ;
F_35 ( V_19 ) ;
return 0 ;
}
static void F_36 ( struct V_18 * V_19 )
{
unsigned int V_85 = 0 ;
struct V_1 * V_2 = F_11 ( V_19 ) ;
int V_96 , V_97 ;
if ( V_2 -> V_98 != NULL ) {
struct V_99 V_100 ;
F_37 ( V_2 -> V_19 , & V_100 ) ;
F_38 ( V_2 -> V_98 ) ;
F_39 ( V_2 -> V_19 , & V_100 ) ;
}
V_96 = V_2 -> V_101 ;
F_3 ( V_2 , V_102 ,
( T_1 ) ( V_2 -> V_103 + V_96 * sizeof( struct V_104 ) ) ) ;
V_97 = V_2 -> V_105 ;
F_3 ( V_2 , V_106 ,
( T_1 ) ( V_2 -> V_107 + V_97 * sizeof( struct V_22 ) ) ) ;
F_3 ( V_2 , V_108 ,
( T_1 ) ( V_2 -> V_107 + V_97 * sizeof( struct V_22 ) ) ) ;
F_3 ( V_2 , V_109 , 0 ) ;
F_3 ( V_2 , V_110 , V_111 ) ;
V_85 = F_1 ( V_2 , V_86 ) ;
V_85 |= V_112 ;
F_3 ( V_2 , V_86 , V_85 ) ;
V_85 = F_1 ( V_2 , V_8 ) ;
V_85 |= V_113 ;
F_3 ( V_2 , V_8 , V_85 ) ;
}
static void F_40 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
unsigned int V_85 = 0 ;
F_3 ( V_2 , V_110 , 0 ) ;
F_3 ( V_2 , V_109 , 0 ) ;
V_85 = F_1 ( V_2 , V_8 ) ;
V_85 &= ~ V_113 ;
F_5 ( V_2 ) ;
V_85 = F_1 ( V_2 , V_86 ) ;
V_85 &= ~ V_112 ;
F_3 ( V_2 , V_86 , V_85 ) ;
}
static int F_41 ( struct V_18 * V_19 , int V_114 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
struct V_104 * V_115 ;
T_1 V_36 ;
struct V_20 * V_21 ;
int V_116 ;
T_3 V_74 ;
int V_117 ;
int V_118 = 0 ;
F_42 ( V_19 ) ;
V_2 -> V_119 &= ~ V_120 ;
while ( V_2 -> V_121 > 0 ) {
V_116 = V_2 -> V_122 ;
V_115 = & V_2 -> V_123 [ V_116 ] ;
V_36 = V_115 -> V_36 ;
if ( ! V_114 && ( V_36 & V_37 ) ) {
if ( V_118 > 0 ) {
goto V_124;
} else {
V_118 = - 1 ;
goto V_124;
}
}
V_2 -> V_122 = ( V_116 + 1 ) % V_2 -> V_125 ;
V_2 -> V_121 -- ;
V_74 = V_115 -> V_32 ;
V_117 = V_115 -> V_126 ;
V_21 = V_2 -> V_127 [ V_116 ] ;
if ( V_21 )
V_2 -> V_127 [ V_116 ] = NULL ;
if ( V_36 & V_128 ) {
if ( F_43 () )
F_7 ( V_11 L_4 , V_19 -> V_129 ) ;
V_19 -> V_130 . V_131 ++ ;
}
F_44 ( NULL , V_74 , V_117 , V_132 ) ;
if ( V_21 )
F_45 ( V_21 ) ;
V_118 ++ ;
}
V_124:
F_46 ( V_19 ) ;
return V_118 ;
}
static void F_47 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
F_7 ( V_71 L_5 ,
V_19 -> V_129 , V_2 -> V_121 ) ;
F_48 ( & V_2 -> V_133 ) ;
}
static void F_49 ( struct V_134 * V_135 )
{
struct V_1 * V_2 = F_50 ( V_135 ,
struct V_1 ,
V_133 ) ;
struct V_18 * V_19 = V_2 -> V_19 ;
F_51 ( V_19 ) ;
F_52 ( V_19 ) ;
}
static int F_53 ( struct V_18 * V_19 , int V_136 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
struct V_137 * V_130 = & V_19 -> V_130 ;
unsigned int V_138 = 0 ;
struct V_20 * V_21 ;
while ( V_136 -- > 0 ) {
int V_139 , V_97 , V_140 ;
struct V_22 * V_22 ;
unsigned int V_36 ;
if ( V_2 -> V_39 )
break;
V_97 = V_2 -> V_105 ;
V_140 = V_2 -> V_30 ;
V_22 = & V_2 -> V_31 [ V_97 ] ;
V_36 = V_22 -> V_36 ;
F_54 () ;
if ( V_36 & ( V_37 ) )
break;
V_21 = V_2 -> V_35 [ V_97 ] ;
V_2 -> V_35 [ V_97 ] = NULL ;
V_139 = ( V_97 + 1 ) % V_2 -> V_26 ;
V_2 -> V_105 = V_139 ;
if ( V_139 == V_140 )
V_2 -> V_39 = 1 ;
V_2 -> V_25 -- ;
F_44 ( NULL , V_22 -> V_32 ,
V_22 -> V_34 ,
V_33 ) ;
V_138 ++ ;
V_130 -> V_141 ++ ;
V_130 -> V_142 += V_22 -> V_126 ;
if ( ( ( V_36 & ( V_143 | V_144 ) ) !=
( V_143 | V_144 ) )
|| ( V_36 & V_145 ) ) {
V_130 -> V_146 ++ ;
if ( ( V_36 & ( V_143 | V_144 ) ) !=
( V_143 | V_144 ) ) {
if ( F_43 () )
F_7 ( V_11
L_6 ,
V_19 -> V_129 ) ;
}
if ( V_36 & V_145 )
V_130 -> V_147 ++ ;
F_45 ( V_21 ) ;
} else {
F_55 ( V_21 , V_22 -> V_126 - 4 ) ;
V_21 -> V_148 = F_56 ( V_21 , V_19 ) ;
F_57 ( V_21 ) ;
}
}
F_10 ( V_19 ) ;
return V_138 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
T_1 V_149 ;
int V_150 = 0 ;
V_149 = F_1 ( V_2 , V_109 ) ;
if ( V_149 == 0 )
return V_151 ;
F_3 ( V_2 , V_109 , ~ V_149 ) ;
if ( V_149 & ( V_152 | V_153 ) ) {
V_2 -> V_119 |= V_120 ;
V_150 = 1 ;
}
if ( V_149 & V_154 )
V_150 = 1 ;
if ( V_149 & V_155 ) {
V_2 -> V_119 |= V_156 ;
V_150 = 1 ;
}
return V_150 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_1 V_157 ;
int V_158 ;
int V_159 ;
int V_160 ;
V_157 = F_1 ( V_2 , V_161 ) ;
if ( ! ( V_157 & V_162 ) ) {
if ( F_60 ( V_19 ) ) {
F_7 ( V_71 L_7 , V_19 -> V_129 ) ;
F_61 ( V_19 ) ;
F_41 ( V_19 , 1 ) ;
}
return;
}
if ( V_157 & V_163 )
V_158 = 100 ;
else
V_158 = 10 ;
V_159 = ( V_157 & V_164 ) ? 1 : 0 ;
V_160 = ( V_157 & V_165 ) ? 1 : 0 ;
F_7 ( V_71 L_8
L_9 , V_19 -> V_129 ,
V_158 , V_159 ? L_10 : L_11 , V_160 ? L_12 : L_13 ) ;
if ( ! F_60 ( V_19 ) )
F_62 ( V_19 ) ;
}
static T_4 F_63 ( int V_166 , void * V_167 )
{
struct V_18 * V_19 = (struct V_18 * ) V_167 ;
struct V_1 * V_2 = F_11 ( V_19 ) ;
if ( F_64 ( ! F_58 ( V_2 , V_19 ) ) )
return V_151 ;
F_3 ( V_2 , V_110 , 0 ) ;
F_19 ( & V_2 -> V_45 ) ;
return V_168 ;
}
static void F_65 ( struct V_1 * V_2 )
{
int V_28 ;
V_28 = V_2 -> V_19 -> V_169 + 36 ;
V_2 -> V_28 = ( V_28 + 7 ) & ~ 7 ;
V_2 -> V_28 += V_29 ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_28 ;
F_65 ( V_2 ) ;
if ( V_2 -> V_28 <= 1518 )
V_28 = V_170 ;
else if ( V_2 -> V_28 <= 1536 )
V_28 = V_171 ;
else if ( V_2 -> V_28 <= 2048 )
V_28 = V_172 ;
else
V_28 = V_173 ;
F_3 ( V_2 ,
V_174 , V_175 |
V_176 |
V_28 | V_177 |
V_178 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_179 = 0 ;
F_3 ( V_2 , V_110 , 0 ) ;
F_3 ( V_2 , V_109 , 0 ) ;
F_3 ( V_2 , V_180 , 0 ) ;
F_5 ( V_2 ) ;
V_179 = F_28 ( V_2 ) ;
if ( V_179 )
return V_179 ;
F_3 ( V_2 , V_181 , V_182 |
V_183 |
V_184 |
V_185 |
V_186 ) ;
F_3 ( V_2 , V_86 , V_187 ) ;
F_66 ( V_2 ) ;
return V_179 ;
}
static int F_68 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
struct V_22 * V_188 ;
int V_27 = 0 , V_48 = 0 ;
int V_189 = V_2 -> V_26 ;
V_2 -> V_35 = F_69 ( sizeof( * V_2 -> V_35 ) * V_2 -> V_26 ,
V_80 ) ;
if ( ! V_2 -> V_35 )
return - V_81 ;
V_2 -> V_25 = 0 ;
V_27 = V_2 -> V_26 * sizeof( struct V_22 ) ;
V_2 -> V_190 = V_27 ;
V_2 -> V_31 = F_29 ( V_2 -> V_19 -> V_19 . V_77 , V_27 ,
& V_2 -> V_107 ,
V_80 ) ;
if ( ! V_2 -> V_31 )
goto V_191;
V_188 = V_2 -> V_31 ;
for ( V_48 = 0 ; V_48 < V_189 ; V_48 ++ ) {
V_188 [ V_48 ] . V_192 = V_2 -> V_107 +
( ( V_48 + 1 ) % V_189 ) * sizeof( struct V_22 ) ;
}
V_2 -> V_105 = 0 ;
V_2 -> V_30 = 0 ;
V_2 -> V_190 = V_189 * sizeof( struct V_22 ) ;
return 0 ;
V_191:
F_70 ( V_2 -> V_35 ) ;
return - V_81 ;
}
static void F_71 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
int V_193 ;
for ( V_193 = 0 ; V_2 -> V_25 && V_193 < V_2 -> V_26 ; V_193 ++ ) {
if ( V_2 -> V_35 [ V_193 ] ) {
F_72 ( V_2 -> V_35 [ V_193 ] ) ;
V_2 -> V_25 -- ;
}
}
if ( V_2 -> V_25 )
F_7 ( V_11
L_14 ,
V_2 -> V_25 ) ;
if ( V_2 -> V_31 )
F_73 ( V_2 -> V_19 -> V_19 . V_77 , V_2 -> V_190 ,
V_2 -> V_31 , V_2 -> V_107 ) ;
F_70 ( V_2 -> V_35 ) ;
}
static int F_74 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
struct V_104 * V_194 ;
int V_27 = 0 , V_48 = 0 ;
int V_195 = V_2 -> V_125 ;
V_2 -> V_127 = F_69 ( sizeof( * V_2 -> V_127 ) * V_2 -> V_125 ,
V_80 ) ;
if ( ! V_2 -> V_127 )
return - V_81 ;
V_2 -> V_121 = 0 ;
V_27 = V_2 -> V_125 * sizeof( struct V_104 ) ;
V_2 -> V_196 = V_27 ;
V_2 -> V_123 = F_29 ( V_2 -> V_19 -> V_19 . V_77 , V_27 ,
& V_2 -> V_103 ,
V_80 ) ;
if ( ! V_2 -> V_123 )
goto V_191;
V_194 = V_2 -> V_123 ;
for ( V_48 = 0 ; V_48 < V_195 ; V_48 ++ ) {
V_194 [ V_48 ] . V_192 = V_2 -> V_103 +
( ( V_48 + 1 ) % V_195 ) * sizeof( struct V_104 ) ;
}
V_2 -> V_101 = 0 ;
V_2 -> V_122 = 0 ;
V_2 -> V_196 = V_195 * sizeof( struct V_104 ) ;
return 0 ;
V_191:
F_70 ( V_2 -> V_127 ) ;
return - V_81 ;
}
static void F_75 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
F_41 ( V_19 , 1 ) ;
F_76 ( V_2 -> V_122 != V_2 -> V_101 ) ;
if ( V_2 -> V_123 )
F_73 ( V_2 -> V_19 -> V_19 . V_77 , V_2 -> V_196 ,
V_2 -> V_123 , V_2 -> V_103 ) ;
F_70 ( V_2 -> V_127 ) ;
}
static int F_52 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
int V_179 ;
V_179 = F_77 ( V_19 -> V_166 , F_63 , 0 , V_19 -> V_129 , V_19 ) ;
if ( V_179 ) {
F_78 ( & V_19 -> V_19 , L_15 ) ;
return - V_197 ;
}
V_2 -> V_39 = 0 ;
V_179 = F_68 ( V_19 ) ;
if ( V_179 != 0 )
goto V_198;
V_179 = F_74 ( V_19 ) ;
if ( V_179 != 0 )
goto V_199;
V_2 -> V_30 = 0 ;
V_2 -> V_105 = 0 ;
F_10 ( V_19 ) ;
V_2 -> V_30 = 0 ;
V_2 -> V_105 = 0 ;
F_61 ( V_19 ) ;
F_36 ( V_19 ) ;
F_79 ( & V_2 -> V_45 ) ;
return 0 ;
V_199:
F_71 ( V_19 ) ;
V_198:
F_80 ( V_19 -> V_166 , V_19 ) ;
return V_179 ;
}
static int F_51 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
F_40 ( V_19 ) ;
F_3 ( V_2 , V_110 , 0 ) ;
F_3 ( V_2 , V_109 , 0 ) ;
F_3 ( V_2 , V_180 , 0 ) ;
F_81 ( & V_2 -> V_45 ) ;
F_82 ( & V_2 -> V_41 ) ;
F_61 ( V_19 ) ;
F_80 ( V_19 -> V_166 , V_19 ) ;
F_71 ( V_19 ) ;
F_75 ( V_19 ) ;
return 0 ;
}
static int F_83 ( struct V_18 * V_19 , int V_169 )
{
int V_200 ;
struct V_1 * V_2 = F_11 ( V_19 ) ;
if ( ( V_169 > 9500 ) || ( V_169 < 68 ) )
return - V_201 ;
V_19 -> V_169 = V_169 ;
V_200 = F_66 ( V_2 ) ;
if ( ! F_84 ( V_19 ) )
return 0 ;
F_51 ( V_19 ) ;
if ( F_52 ( V_19 ) ) {
F_78 ( & V_19 -> V_19 ,
L_16 ) ;
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
int V_202 ;
V_202 = V_2 -> V_101 ;
V_2 -> V_101 = ( V_202 + 1 ) % V_2 -> V_125 ;
F_76 ( V_2 -> V_101 == V_2 -> V_122 ) ;
V_2 -> V_121 ++ ;
return V_202 ;
}
static int F_86 ( struct V_203 * V_45 , int V_136 )
{
struct V_1 * V_2 =
F_50 ( V_45 , struct V_1 , V_45 ) ;
struct V_18 * V_19 = V_2 -> V_19 ;
int V_204 = 0 ;
if ( F_64 ( V_2 -> V_119 & V_156 ) ) {
V_2 -> V_119 &= ~ ( V_156 ) ;
F_59 ( V_2 ) ;
}
F_41 ( V_19 , 0 ) ;
if ( F_87 ( V_19 )
&& V_2 -> V_125 - V_2 -> V_121 > 1 ) {
F_88 ( V_19 ) ;
}
V_204 = F_53 ( V_19 , V_136 ) ;
if ( V_204 < V_136 ) {
F_89 ( V_45 ) ;
F_3 ( V_2 , V_110 , V_111 ) ;
}
return V_204 ;
}
static int F_90 ( struct V_20 * V_21 , struct V_18 * V_19 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
struct V_137 * V_130 = & V_19 -> V_130 ;
struct V_104 * V_115 ;
int V_116 ;
int V_205 ;
V_116 = F_85 ( V_2 ) ;
V_115 = & V_2 -> V_123 [ V_116 ] ;
V_205 = V_21 -> V_206 ;
V_2 -> V_127 [ V_116 ] = V_21 ;
V_115 -> V_126 = V_205 ;
V_115 -> V_32 = F_15 ( NULL , V_21 -> V_5 , V_205 , V_132 ) ;
F_91 ( V_21 ) ;
F_16 () ;
V_115 -> V_36 = V_37 | V_207 | V_208 |
V_209 | V_210 | V_211 ;
F_16 () ;
F_3 ( V_2 , V_8 , V_212 | V_113 ) ;
V_130 -> V_213 += V_205 ;
V_130 -> V_214 ++ ;
V_19 -> V_215 = V_43 ;
if ( V_2 -> V_125 - V_2 -> V_121 <= 1 ) {
F_92 ( V_19 ) ;
}
return V_216 ;
}
static int F_93 ( struct V_1 * V_2 )
{
int V_48 = 0 ;
for ( V_48 = 0 ; F_1 ( V_2 , V_217 ) & V_218 ; V_48 ++ ) {
if ( V_48 == V_219 )
return - V_220 ;
F_94 ( 10 ) ;
}
return 0 ;
}
static int F_95 ( struct V_221 * V_222 , int V_16 , int V_223 )
{
struct V_1 * V_2 = V_222 -> V_224 ;
int V_48 = 0 ;
int V_85 ;
if ( F_93 ( V_2 ) ) {
F_7 ( V_225 L_17 ) ;
return - V_220 ;
}
F_3 ( V_2 , V_217 , ( V_16 << 16 ) | ( V_223 << 21 ) | V_226 ) ;
for ( V_48 = 0 ; ! ( ( V_85 = F_1 ( V_2 , V_217 ) ) & V_227 ) ; V_48 ++ ) {
if ( V_48 == V_219 ) {
F_7 ( V_225
L_18 ) ;
return - V_228 ;
}
F_94 ( 10 ) ;
}
return V_85 & 0xffff ;
}
static int F_96 ( struct V_221 * V_222 , int V_16 , int V_223 ,
T_5 V_229 )
{
struct V_1 * V_2 = V_222 -> V_224 ;
if ( F_93 ( V_2 ) ) {
F_7 ( V_225 L_17 ) ;
return - V_220 ;
}
F_3 ( V_2 , V_217 , ( V_16 << 16 ) | ( V_223 << 21 ) |
V_230 | ( V_229 & 0xffff ) ) ;
if ( F_93 ( V_2 ) ) {
F_7 ( V_11 L_17 ) ;
return - V_220 ;
}
return 0 ;
}
static int F_97 ( struct V_18 * V_19 , struct V_231 * V_232 ,
int V_100 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
if ( V_2 -> V_98 != NULL )
return F_98 ( V_2 -> V_98 , V_232 , V_100 ) ;
return - V_233 ;
}
static struct V_234 * F_99 ( struct V_1 * V_2 , int V_16 )
{
struct V_221 * V_222 = V_2 -> V_235 ;
struct V_234 * V_236 ;
int V_61 ;
int V_237 ;
int V_48 ;
if ( V_16 == V_238 ) {
V_61 = F_8 ( V_2 ) ;
V_237 = 32 ;
} else {
V_61 = V_16 & 0x1f ;
V_237 = 1 ;
}
V_236 = NULL ;
for ( V_48 = 0 ; V_48 < V_237 ; V_48 ++ ) {
int V_74 = ( V_61 + V_48 ) & 0x1f ;
if ( V_222 -> V_239 [ V_74 ] == NULL )
F_100 ( V_222 , V_74 ) ;
if ( V_236 == NULL ) {
V_236 = V_222 -> V_239 [ V_74 ] ;
if ( V_236 != NULL )
F_9 ( V_2 , V_74 ) ;
}
}
return V_236 ;
}
static void F_101 ( struct V_1 * V_2 , int V_158 , int V_159 )
{
struct V_234 * V_98 = V_2 -> V_98 ;
F_102 ( V_2 -> V_19 , F_103 ( & V_98 -> V_19 ) , V_240 ) ;
if ( V_158 == 0 ) {
V_98 -> V_241 = V_242 ;
V_98 -> V_158 = 0 ;
V_98 -> V_159 = 0 ;
V_98 -> V_243 &= V_244 ;
V_98 -> V_245 = V_98 -> V_243 | V_246 ;
} else {
V_98 -> V_241 = V_247 ;
V_98 -> V_245 = 0 ;
V_98 -> V_158 = V_158 ;
V_98 -> V_159 = V_159 ;
}
F_104 ( V_98 ) ;
}
static int F_105 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
if ( V_2 -> V_248 -> V_249 )
V_2 -> V_248 -> V_249 () ;
V_2 -> V_98 = F_99 ( V_2 , V_2 -> V_248 -> V_16 & 0x1f ) ;
if ( V_2 -> V_98 != NULL )
F_101 ( V_2 , V_2 -> V_248 -> V_158 , V_2 -> V_248 -> V_159 ) ;
F_27 ( V_2 , NULL , V_19 -> V_90 ) ;
return 0 ;
}
static int F_37 ( struct V_18 * V_19 , struct V_99 * V_100 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
int V_179 ;
V_179 = F_106 ( V_2 -> V_98 ) ;
if ( V_179 == 0 )
V_179 = F_107 ( V_2 -> V_98 , V_100 ) ;
return V_179 ;
}
static int F_39 ( struct V_18 * V_19 , struct V_99 * V_100 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
return F_108 ( V_2 -> V_98 , V_100 ) ;
}
static void F_109 ( struct V_18 * V_19 ,
struct V_250 * V_251 )
{
F_110 ( V_251 -> V_252 , V_253 , sizeof( V_251 -> V_252 ) ) ;
F_110 ( V_251 -> V_254 , V_255 , sizeof( V_251 -> V_254 ) ) ;
F_110 ( V_251 -> V_256 , L_19 , sizeof( V_251 -> V_256 ) ) ;
F_110 ( V_251 -> V_257 , L_19 , sizeof( V_251 -> V_257 ) ) ;
}
static int F_111 ( struct V_258 * V_259 )
{
struct V_1 * V_2 = NULL ;
struct V_18 * V_19 = NULL ;
struct V_260 * V_261 ;
struct V_262 * V_262 ;
int V_179 ;
F_7 ( V_263 L_20 ) ;
V_262 = F_112 ( & V_259 -> V_19 , L_21 ) ;
if ( F_113 ( V_262 ) ) {
F_7 ( V_11 L_22 ,
V_253 ) ;
return - V_228 ;
}
F_114 ( V_262 ) ;
V_19 = F_115 ( sizeof( struct V_1 ) ) ;
if ( ! V_19 ) {
V_179 = - V_81 ;
goto V_264;
}
F_116 ( V_259 , V_19 ) ;
V_2 = F_11 ( V_19 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_262 = V_262 ;
V_261 = F_117 ( V_259 , V_265 , 0 ) ;
if ( V_261 == NULL ) {
V_179 = - V_228 ;
goto V_266;
}
V_2 -> V_4 = F_118 ( V_261 -> V_61 , F_119 ( V_261 ) ) ;
if ( V_2 -> V_4 == NULL ) {
V_179 = - V_81 ;
goto V_266;
}
V_261 = F_117 ( V_259 , V_267 , 0 ) ;
F_76 ( ! V_261 ) ;
V_19 -> V_166 = V_261 -> V_61 ;
V_19 -> V_268 = & V_269 ;
V_19 -> V_270 = 2 * V_44 ;
V_19 -> V_271 = 0 ;
F_120 ( V_19 , & V_272 ) ;
F_121 ( & V_2 -> V_133 , F_49 ) ;
F_7 ( V_71 L_23 , V_253 ) ;
F_122 ( V_19 ) ;
V_2 -> V_248 = F_123 ( & V_259 -> V_19 ) ;
V_2 -> V_26 = V_273 ;
if ( V_2 -> V_248 -> V_274 )
V_2 -> V_26 = V_2 -> V_248 -> V_274 ;
V_2 -> V_125 = V_275 ;
if ( V_2 -> V_248 -> V_276 )
V_2 -> V_125 = V_2 -> V_248 -> V_276 ;
V_2 -> V_15 = V_2 -> V_248 -> V_277 ;
F_76 ( V_2 -> V_15 > 2 ) ;
F_124 ( V_19 , & V_2 -> V_45 , F_86 , V_2 -> V_26 ) ;
memset ( & V_2 -> V_41 , 0 , sizeof( struct V_278 ) ) ;
F_125 ( & V_2 -> V_41 ) ;
V_2 -> V_41 . V_279 = F_18 ;
V_2 -> V_41 . V_5 = ( unsigned long ) V_2 ;
V_2 -> V_235 = F_126 () ;
if ( V_2 -> V_235 == NULL ) {
V_179 = - V_81 ;
goto V_280;
}
V_2 -> V_235 -> V_224 = V_2 ;
V_2 -> V_235 -> V_129 = L_24 ;
V_2 -> V_235 -> V_281 = F_95 ;
V_2 -> V_235 -> V_282 = F_96 ;
snprintf ( V_2 -> V_235 -> V_283 , V_284 , L_25 ,
V_259 -> V_129 , V_259 -> V_283 ) ;
V_2 -> V_235 -> V_77 = & V_259 -> V_19 ;
V_2 -> V_235 -> V_285 = 0xffffffff ;
V_179 = F_127 ( V_2 -> V_235 ) ;
if ( V_179 )
goto V_286;
F_67 ( V_2 ) ;
V_179 = F_105 ( V_19 ) ;
if ( V_179 )
goto V_287;
F_128 ( V_19 , & V_259 -> V_19 ) ;
V_179 = F_129 ( V_19 ) ;
if ( V_179 )
goto V_287;
return 0 ;
V_287:
F_130 ( V_2 -> V_235 ) ;
V_286:
F_131 ( V_2 -> V_235 ) ;
V_280:
F_132 ( V_2 -> V_4 ) ;
V_266:
F_133 ( V_19 ) ;
V_264:
F_134 ( V_262 ) ;
F_135 ( V_262 ) ;
return V_179 ;
}
static int F_136 ( struct V_258 * V_259 )
{
struct V_18 * V_19 = F_137 ( V_259 ) ;
struct V_1 * V_2 = F_11 ( V_19 ) ;
if ( V_2 -> V_67 ) {
F_73 ( V_2 -> V_19 -> V_19 . V_77 , V_78 ,
V_2 -> V_67 , V_2 -> V_79 ) ;
V_2 -> V_67 = NULL ;
}
if ( V_2 -> V_262 ) {
F_134 ( V_2 -> V_262 ) ;
F_135 ( V_2 -> V_262 ) ;
V_2 -> V_262 = NULL ;
}
if ( V_2 -> V_98 != NULL )
F_138 ( V_2 -> V_98 ) ;
F_132 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
F_130 ( V_2 -> V_235 ) ;
F_131 ( V_2 -> V_235 ) ;
F_139 ( V_19 ) ;
F_140 ( & V_2 -> V_133 ) ;
F_133 ( V_19 ) ;
return 0 ;
}
static void F_141 ( struct V_258 * V_259 )
{
struct V_18 * V_19 = F_137 ( V_259 ) ;
F_40 ( V_19 ) ;
}
static int F_142 ( struct V_258 * V_259 )
{
return - V_288 ;
}
static int F_143 ( struct V_258 * V_259 , T_6 V_289 )
{
return - V_288 ;
}
