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
V_22 -> V_100 &= ~ V_101 ;
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
int V_102 , V_103 ;
if ( V_2 -> V_18 != NULL ) {
struct V_104 V_105 ;
F_39 ( V_2 -> V_22 , & V_105 ) ;
F_10 ( V_2 ) ;
F_40 ( V_2 -> V_22 , & V_105 ) ;
}
V_102 = V_2 -> V_106 ;
F_3 ( V_2 , V_107 ,
( T_1 ) ( V_2 -> V_108 + V_102 * sizeof( struct V_109 ) ) ) ;
V_103 = V_2 -> V_110 ;
F_3 ( V_2 , V_111 ,
( T_1 ) ( V_2 -> V_112 + V_103 * sizeof( struct V_25 ) ) ) ;
F_3 ( V_2 , V_113 ,
( T_1 ) ( V_2 -> V_112 + V_103 * sizeof( struct V_25 ) ) ) ;
F_3 ( V_2 , V_114 , 0 ) ;
F_3 ( V_2 , V_115 , V_116 ) ;
V_89 = F_1 ( V_2 , V_90 ) ;
V_89 |= V_117 ;
F_3 ( V_2 , V_90 , V_89 ) ;
V_89 = F_1 ( V_2 , V_8 ) ;
V_89 |= V_118 ;
F_3 ( V_2 , V_8 , V_89 ) ;
}
static void F_41 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
unsigned int V_89 = 0 ;
F_3 ( V_2 , V_115 , 0 ) ;
F_3 ( V_2 , V_114 , 0 ) ;
V_89 = F_1 ( V_2 , V_8 ) ;
V_89 &= ~ V_118 ;
F_5 ( V_2 ) ;
V_89 = F_1 ( V_2 , V_90 ) ;
V_89 &= ~ V_117 ;
F_3 ( V_2 , V_90 , V_89 ) ;
}
static int F_42 ( struct V_21 * V_22 , int V_119 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_109 * V_120 ;
T_1 V_40 ;
struct V_23 * V_24 ;
int V_121 ;
T_3 V_78 ;
int V_122 ;
int V_123 = 0 ;
F_43 ( V_22 ) ;
V_2 -> V_124 &= ~ V_125 ;
while ( V_2 -> V_126 > 0 ) {
V_121 = V_2 -> V_127 ;
V_120 = & V_2 -> V_128 [ V_121 ] ;
V_40 = V_120 -> V_40 ;
if ( ! V_119 && ( V_40 & V_41 ) ) {
if ( V_123 > 0 ) {
goto V_129;
} else {
V_123 = - 1 ;
goto V_129;
}
}
V_2 -> V_127 = ( V_121 + 1 ) % V_2 -> V_130 ;
V_2 -> V_126 -- ;
V_78 = V_120 -> V_36 ;
V_122 = V_120 -> V_131 ;
V_24 = V_2 -> V_132 [ V_121 ] ;
if ( V_24 )
V_2 -> V_132 [ V_121 ] = NULL ;
if ( V_40 & V_133 ) {
if ( F_44 () )
F_7 ( V_11 L_4 , V_22 -> V_134 ) ;
V_22 -> V_135 . V_136 ++ ;
}
F_45 ( NULL , V_78 , V_122 , V_137 ) ;
if ( V_24 )
F_46 ( V_24 ) ;
V_123 ++ ;
}
V_129:
F_47 ( V_22 ) ;
return V_123 ;
}
static void F_48 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
F_7 ( V_75 L_5 ,
V_22 -> V_134 , V_2 -> V_126 ) ;
F_49 ( & V_2 -> V_138 ) ;
}
static void F_50 ( struct V_139 * V_140 )
{
struct V_1 * V_2 = F_51 ( V_140 ,
struct V_1 ,
V_138 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
F_52 ( V_22 ) ;
F_53 ( V_22 ) ;
}
static int F_54 ( struct V_21 * V_22 , int V_141 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_142 * V_135 = & V_22 -> V_135 ;
unsigned int V_143 = 0 ;
struct V_23 * V_24 ;
while ( V_141 -- > 0 ) {
int V_144 , V_103 , V_145 ;
struct V_25 * V_25 ;
unsigned int V_40 ;
if ( V_2 -> V_43 )
break;
V_103 = V_2 -> V_110 ;
V_145 = V_2 -> V_33 ;
V_25 = & V_2 -> V_34 [ V_103 ] ;
V_40 = V_25 -> V_40 ;
F_55 () ;
if ( V_40 & ( V_41 ) )
break;
V_24 = V_2 -> V_39 [ V_103 ] ;
V_2 -> V_39 [ V_103 ] = NULL ;
V_144 = ( V_103 + 1 ) % V_2 -> V_29 ;
V_2 -> V_110 = V_144 ;
if ( V_144 == V_145 )
V_2 -> V_43 = 1 ;
V_2 -> V_28 -- ;
F_45 ( NULL , V_25 -> V_36 ,
V_25 -> V_38 ,
V_37 ) ;
V_143 ++ ;
V_135 -> V_146 ++ ;
V_135 -> V_147 += V_25 -> V_131 ;
if ( ( ( V_40 & ( V_148 | V_149 ) ) !=
( V_148 | V_149 ) )
|| ( V_40 & V_150 ) ) {
V_135 -> V_151 ++ ;
if ( ( V_40 & ( V_148 | V_149 ) ) !=
( V_148 | V_149 ) ) {
if ( F_44 () )
F_7 ( V_11
L_6 ,
V_22 -> V_134 ) ;
}
if ( V_40 & V_150 )
V_135 -> V_152 ++ ;
F_46 ( V_24 ) ;
} else {
F_56 ( V_24 , V_25 -> V_131 - 4 ) ;
V_24 -> V_153 = F_57 ( V_24 , V_22 ) ;
F_58 ( V_24 ) ;
}
}
F_13 ( V_22 ) ;
return V_143 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
T_1 V_154 ;
int V_155 = 0 ;
V_154 = F_1 ( V_2 , V_114 ) ;
if ( V_154 == 0 )
return V_156 ;
F_3 ( V_2 , V_114 , ~ V_154 ) ;
if ( V_154 & ( V_157 | V_158 ) ) {
V_2 -> V_124 |= V_125 ;
V_155 = 1 ;
}
if ( V_154 & V_159 )
V_155 = 1 ;
if ( V_154 & V_160 ) {
V_2 -> V_124 |= V_161 ;
V_155 = 1 ;
}
return V_155 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_162 ;
int V_163 ;
int V_164 ;
int V_165 ;
V_162 = F_1 ( V_2 , V_166 ) ;
if ( ! ( V_162 & V_167 ) ) {
if ( F_61 ( V_22 ) ) {
F_7 ( V_75 L_7 , V_22 -> V_134 ) ;
F_62 ( V_22 ) ;
F_42 ( V_22 , 1 ) ;
}
return;
}
if ( V_162 & V_168 )
V_163 = 100 ;
else
V_163 = 10 ;
V_164 = ( V_162 & V_169 ) ? 1 : 0 ;
V_165 = ( V_162 & V_170 ) ? 1 : 0 ;
F_7 ( V_75 L_8
L_9 , V_22 -> V_134 ,
V_163 , V_164 ? L_10 : L_11 , V_165 ? L_12 : L_13 ) ;
if ( ! F_61 ( V_22 ) )
F_63 ( V_22 ) ;
}
static T_4 F_64 ( int V_171 , void * V_172 )
{
struct V_21 * V_22 = (struct V_21 * ) V_172 ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
if ( F_65 ( ! F_59 ( V_2 , V_22 ) ) )
return V_156 ;
F_3 ( V_2 , V_115 , 0 ) ;
F_21 ( & V_2 -> V_49 ) ;
return V_173 ;
}
static void F_66 ( struct V_1 * V_2 )
{
int V_31 ;
V_31 = V_2 -> V_22 -> V_174 + 36 ;
V_2 -> V_31 = ( V_31 + 7 ) & ~ 7 ;
V_2 -> V_31 += V_32 ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_31 ;
F_66 ( V_2 ) ;
if ( V_2 -> V_31 <= 1518 )
V_31 = V_175 ;
else if ( V_2 -> V_31 <= 1536 )
V_31 = V_176 ;
else if ( V_2 -> V_31 <= 2048 )
V_31 = V_177 ;
else
V_31 = V_178 ;
F_3 ( V_2 ,
V_179 , V_180 |
V_181 |
V_31 | V_182 |
V_183 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_184 = 0 ;
F_3 ( V_2 , V_115 , 0 ) ;
F_3 ( V_2 , V_114 , 0 ) ;
F_3 ( V_2 , V_185 , 0 ) ;
F_5 ( V_2 ) ;
V_184 = F_30 ( V_2 ) ;
if ( V_184 )
return V_184 ;
F_3 ( V_2 , V_186 , V_187 |
V_188 |
V_189 |
V_190 |
V_191 ) ;
F_3 ( V_2 , V_90 , V_192 ) ;
F_67 ( V_2 ) ;
return V_184 ;
}
static int F_69 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_25 * V_193 ;
int V_30 = 0 , V_52 = 0 ;
int V_194 = V_2 -> V_29 ;
V_2 -> V_39 = F_70 ( sizeof( * V_2 -> V_39 ) * V_2 -> V_29 ,
V_84 ) ;
if ( ! V_2 -> V_39 )
return - V_85 ;
V_2 -> V_28 = 0 ;
V_30 = V_2 -> V_29 * sizeof( struct V_25 ) ;
V_2 -> V_195 = V_30 ;
V_2 -> V_34 = F_31 ( V_2 -> V_22 -> V_22 . V_81 , V_30 ,
& V_2 -> V_112 , V_84 ) ;
if ( ! V_2 -> V_34 ) {
F_7 ( V_11 L_14 ,
V_22 -> V_134 , V_30 ) ;
goto V_196;
}
memset ( ( void * ) V_2 -> V_34 , 0 , V_30 ) ;
V_193 = V_2 -> V_34 ;
for ( V_52 = 0 ; V_52 < V_194 ; V_52 ++ ) {
V_193 [ V_52 ] . V_197 = V_2 -> V_112 +
( ( V_52 + 1 ) % V_194 ) * sizeof( struct V_25 ) ;
}
V_2 -> V_110 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_195 = V_194 * sizeof( struct V_25 ) ;
return 0 ;
V_196:
F_71 ( V_2 -> V_39 ) ;
return - V_85 ;
}
static void F_72 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_198 ;
for ( V_198 = 0 ; V_2 -> V_28 && V_198 < V_2 -> V_29 ; V_198 ++ ) {
if ( V_2 -> V_39 [ V_198 ] ) {
F_73 ( V_2 -> V_39 [ V_198 ] ) ;
V_2 -> V_28 -- ;
}
}
if ( V_2 -> V_28 )
F_7 ( V_11
L_15 ,
V_2 -> V_28 ) ;
if ( V_2 -> V_34 )
F_74 ( V_2 -> V_22 -> V_22 . V_81 , V_2 -> V_195 ,
V_2 -> V_34 , V_2 -> V_112 ) ;
F_71 ( V_2 -> V_39 ) ;
}
static int F_75 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_109 * V_199 ;
int V_30 = 0 , V_52 = 0 ;
int V_200 = V_2 -> V_130 ;
V_2 -> V_132 = F_70 ( sizeof( * V_2 -> V_132 ) * V_2 -> V_130 ,
V_84 ) ;
if ( ! V_2 -> V_132 )
return - V_85 ;
V_2 -> V_126 = 0 ;
V_30 = V_2 -> V_130 * sizeof( struct V_109 ) ;
V_2 -> V_201 = V_30 ;
V_2 -> V_128 = F_31 ( V_2 -> V_22 -> V_22 . V_81 , V_30 ,
& V_2 -> V_108 , V_84 ) ;
if ( ! V_2 -> V_128 ) {
F_7 ( V_11 L_16 ,
V_22 -> V_134 , V_30 ) ;
goto V_196;
}
memset ( ( void * ) V_2 -> V_128 , 0 , V_2 -> V_201 ) ;
V_199 = V_2 -> V_128 ;
for ( V_52 = 0 ; V_52 < V_200 ; V_52 ++ ) {
V_199 [ V_52 ] . V_197 = V_2 -> V_108 +
( ( V_52 + 1 ) % V_200 ) * sizeof( struct V_109 ) ;
}
V_2 -> V_106 = 0 ;
V_2 -> V_127 = 0 ;
V_2 -> V_201 = V_200 * sizeof( struct V_109 ) ;
return 0 ;
V_196:
F_71 ( V_2 -> V_132 ) ;
return - V_85 ;
}
static void F_76 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
F_42 ( V_22 , 1 ) ;
F_77 ( V_2 -> V_127 != V_2 -> V_106 ) ;
if ( V_2 -> V_128 )
F_74 ( V_2 -> V_22 -> V_22 . V_81 , V_2 -> V_201 ,
V_2 -> V_128 , V_2 -> V_108 ) ;
F_71 ( V_2 -> V_132 ) ;
}
static int F_53 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_184 ;
V_184 = F_78 ( V_22 -> V_171 , F_64 ,
V_202 , V_22 -> V_134 , V_22 ) ;
if ( V_184 ) {
F_79 ( & V_22 -> V_22 , L_17 ) ;
return - V_203 ;
}
V_2 -> V_43 = 0 ;
V_184 = F_69 ( V_22 ) ;
if ( V_184 != 0 )
goto V_204;
V_184 = F_75 ( V_22 ) ;
if ( V_184 != 0 )
goto V_205;
V_2 -> V_33 = 0 ;
V_2 -> V_110 = 0 ;
F_13 ( V_22 ) ;
V_2 -> V_33 = 0 ;
V_2 -> V_110 = 0 ;
F_62 ( V_22 ) ;
F_38 ( V_22 ) ;
F_80 ( & V_2 -> V_49 ) ;
return 0 ;
V_205:
F_72 ( V_22 ) ;
V_204:
F_81 ( V_22 -> V_171 , V_22 ) ;
return V_184 ;
}
static int F_52 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
F_41 ( V_22 ) ;
F_3 ( V_2 , V_115 , 0 ) ;
F_3 ( V_2 , V_114 , 0 ) ;
F_3 ( V_2 , V_185 , 0 ) ;
F_82 ( & V_2 -> V_49 ) ;
F_83 ( & V_2 -> V_45 ) ;
F_62 ( V_22 ) ;
F_81 ( V_22 -> V_171 , V_22 ) ;
F_72 ( V_22 ) ;
F_76 ( V_22 ) ;
return 0 ;
}
static int F_84 ( struct V_21 * V_22 , int V_174 )
{
int V_206 ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
if ( ( V_174 > 9500 ) || ( V_174 < 68 ) )
return - V_207 ;
V_22 -> V_174 = V_174 ;
V_206 = F_67 ( V_2 ) ;
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
int V_208 ;
V_208 = V_2 -> V_106 ;
V_2 -> V_106 = ( V_208 + 1 ) % V_2 -> V_130 ;
F_77 ( V_2 -> V_106 == V_2 -> V_127 ) ;
V_2 -> V_126 ++ ;
return V_208 ;
}
static int F_87 ( struct V_209 * V_49 , int V_141 )
{
struct V_1 * V_2 =
F_51 ( V_49 , struct V_1 , V_49 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
int V_210 = 0 ;
if ( F_65 ( V_2 -> V_124 & V_161 ) ) {
V_2 -> V_124 &= ~ ( V_161 ) ;
F_60 ( V_2 ) ;
}
F_42 ( V_22 , 0 ) ;
if ( F_88 ( V_22 )
&& V_2 -> V_130 - V_2 -> V_126 > 1 ) {
F_89 ( V_22 ) ;
}
V_210 = F_54 ( V_22 , V_141 ) ;
if ( V_210 < V_141 ) {
F_90 ( V_49 ) ;
F_3 ( V_2 , V_115 , V_116 ) ;
}
return V_210 ;
}
static int F_91 ( struct V_23 * V_24 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_142 * V_135 = & V_22 -> V_135 ;
struct V_109 * V_120 ;
int V_121 ;
int V_211 ;
V_121 = F_86 ( V_2 ) ;
V_120 = & V_2 -> V_128 [ V_121 ] ;
V_211 = V_24 -> V_212 ;
V_2 -> V_132 [ V_121 ] = V_24 ;
V_120 -> V_131 = V_211 ;
V_120 -> V_36 = F_17 ( NULL , V_24 -> V_5 , V_211 , V_137 ) ;
F_92 ( V_24 ) ;
F_18 () ;
V_120 -> V_40 = V_41 | V_213 | V_214 |
V_215 | V_216 | V_217 ;
F_18 () ;
F_3 ( V_2 , V_8 , V_218 | V_118 ) ;
V_135 -> V_219 += V_211 ;
V_135 -> V_220 ++ ;
V_22 -> V_221 = V_47 ;
if ( V_2 -> V_130 - V_2 -> V_126 <= 1 ) {
F_93 ( V_22 ) ;
}
return V_222 ;
}
static int F_94 ( struct V_1 * V_2 )
{
int V_52 = 0 ;
for ( V_52 = 0 ; F_1 ( V_2 , V_223 ) & V_224 ; V_52 ++ ) {
if ( V_52 == V_225 )
return - V_226 ;
F_95 ( 10 ) ;
}
return 0 ;
}
static int F_96 ( struct V_227 * V_228 , int V_16 , int V_229 )
{
struct V_1 * V_2 = V_228 -> V_230 ;
int V_52 = 0 ;
int V_89 ;
if ( F_94 ( V_2 ) ) {
F_7 ( V_231 L_19 ) ;
return - V_226 ;
}
F_3 ( V_2 , V_223 , ( V_16 << 16 ) | ( V_229 << 21 ) | V_232 ) ;
for ( V_52 = 0 ; ! ( ( V_89 = F_1 ( V_2 , V_223 ) ) & V_233 ) ; V_52 ++ ) {
if ( V_52 == V_225 ) {
F_7 ( V_231
L_20 ) ;
return - V_234 ;
}
F_95 ( 10 ) ;
}
return V_89 & 0xffff ;
}
static int F_97 ( struct V_227 * V_228 , int V_16 , int V_229 ,
T_5 V_235 )
{
struct V_1 * V_2 = V_228 -> V_230 ;
if ( F_94 ( V_2 ) ) {
F_7 ( V_231 L_19 ) ;
return - V_226 ;
}
F_3 ( V_2 , V_223 , ( V_16 << 16 ) | ( V_229 << 21 ) |
V_236 | ( V_235 & 0xffff ) ) ;
if ( F_94 ( V_2 ) ) {
F_7 ( V_11 L_19 ) ;
return - V_226 ;
}
return 0 ;
}
static int F_98 ( struct V_21 * V_22 , struct V_237 * V_238 ,
int V_105 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
if ( V_2 -> V_18 != NULL )
return F_99 ( V_2 -> V_18 , V_238 , V_105 ) ;
return - V_239 ;
}
static struct V_240 * F_100 ( struct V_1 * V_2 , int V_16 )
{
struct V_227 * V_228 = V_2 -> V_241 ;
struct V_240 * V_242 ;
int V_65 ;
int V_243 ;
int V_52 ;
if ( V_16 == V_244 ) {
V_65 = F_8 ( V_2 ) ;
V_243 = 32 ;
} else {
V_65 = V_16 & 0x1f ;
V_243 = 1 ;
}
V_242 = NULL ;
for ( V_52 = 0 ; V_52 < V_243 ; V_52 ++ ) {
int V_78 = ( V_65 + V_52 ) & 0x1f ;
if ( V_228 -> V_245 [ V_78 ] == NULL )
F_101 ( V_228 , V_78 ) ;
if ( V_242 == NULL ) {
V_242 = V_228 -> V_245 [ V_78 ] ;
if ( V_242 != NULL )
F_9 ( V_2 , V_78 ) ;
}
}
return V_242 ;
}
static void F_102 ( struct V_1 * V_2 , int V_163 , int V_164 )
{
struct V_240 * V_18 = V_2 -> V_18 ;
F_10 ( V_2 ) ;
F_103 ( V_2 -> V_22 , F_104 ( & V_18 -> V_22 ) , 0 , V_246 ) ;
if ( V_163 == 0 ) {
V_18 -> V_247 = V_248 ;
V_18 -> V_163 = 0 ;
V_18 -> V_164 = 0 ;
V_18 -> V_249 &= V_250 ;
V_18 -> V_251 = V_18 -> V_249 | V_252 ;
} else {
V_18 -> V_247 = V_253 ;
V_18 -> V_251 = 0 ;
V_18 -> V_163 = V_163 ;
V_18 -> V_164 = V_164 ;
}
F_105 ( V_18 ) ;
}
static int F_106 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
if ( V_2 -> V_254 -> V_255 )
V_2 -> V_254 -> V_255 () ;
V_2 -> V_18 = F_100 ( V_2 , V_2 -> V_254 -> V_16 & 0x1f ) ;
if ( V_2 -> V_18 != NULL )
F_102 ( V_2 , V_2 -> V_254 -> V_163 , V_2 -> V_254 -> V_164 ) ;
F_29 ( V_2 , NULL , V_22 -> V_94 ) ;
return 0 ;
}
static int F_39 ( struct V_21 * V_22 , struct V_104 * V_105 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_184 ;
V_184 = F_107 ( V_2 -> V_18 ) ;
if ( V_184 == 0 )
V_184 = F_108 ( V_2 -> V_18 , V_105 ) ;
return V_184 ;
}
static int F_40 ( struct V_21 * V_22 , struct V_104 * V_105 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
return F_109 ( V_2 -> V_18 , V_105 ) ;
}
static void F_110 ( struct V_21 * V_22 ,
struct V_256 * V_257 )
{
strncpy ( V_257 -> V_258 , V_259 , 32 ) ;
strncpy ( V_257 -> V_260 , V_261 , 32 ) ;
strncpy ( V_257 -> V_262 , L_21 , 32 ) ;
strncpy ( V_257 -> V_263 , L_21 , 32 ) ;
}
static int F_111 ( struct V_264 * V_265 )
{
struct V_1 * V_2 = NULL ;
struct V_21 * V_22 = NULL ;
struct V_266 * V_267 ;
struct V_268 * V_268 ;
int V_184 ;
F_7 ( V_269 L_22 ) ;
V_268 = F_112 ( & V_265 -> V_22 , L_23 ) ;
if ( F_113 ( V_268 ) ) {
F_7 ( V_11 L_24 ,
V_259 ) ;
return - V_234 ;
}
F_114 ( V_268 ) ;
V_22 = F_115 ( sizeof( struct V_1 ) ) ;
if ( ! V_22 ) {
V_184 = - V_85 ;
goto V_270;
}
F_116 ( V_265 , V_22 ) ;
V_2 = F_14 ( V_22 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_268 = V_268 ;
V_267 = F_117 ( V_265 , V_271 , 0 ) ;
if ( V_267 == NULL ) {
V_184 = - V_234 ;
goto V_272;
}
V_2 -> V_4 = F_118 ( V_267 -> V_65 , F_119 ( V_267 ) ) ;
if ( V_2 -> V_4 == NULL ) {
V_184 = - V_85 ;
goto V_272;
}
V_267 = F_117 ( V_265 , V_273 , 0 ) ;
F_77 ( ! V_267 ) ;
V_22 -> V_171 = V_267 -> V_65 ;
V_22 -> V_274 = & V_275 ;
V_22 -> V_276 = 2 * V_48 ;
V_22 -> V_277 = 0 ;
F_120 ( V_22 , & V_278 ) ;
F_121 ( & V_2 -> V_138 , F_50 ) ;
F_7 ( V_75 L_25 , V_259 ) ;
F_122 ( V_22 ) ;
V_2 -> V_254 = V_265 -> V_22 . V_279 ;
V_2 -> V_29 = V_280 ;
if ( V_2 -> V_254 -> V_281 )
V_2 -> V_29 = V_2 -> V_254 -> V_281 ;
V_2 -> V_130 = V_282 ;
if ( V_2 -> V_254 -> V_283 )
V_2 -> V_130 = V_2 -> V_254 -> V_283 ;
V_2 -> V_15 = V_2 -> V_254 -> V_284 ;
F_77 ( V_2 -> V_15 > 2 ) ;
F_123 ( V_22 , & V_2 -> V_49 , F_87 , V_2 -> V_29 ) ;
memset ( & V_2 -> V_45 , 0 , sizeof( struct V_285 ) ) ;
F_124 ( & V_2 -> V_45 ) ;
V_2 -> V_45 . V_286 = F_20 ;
V_2 -> V_45 . V_5 = ( unsigned long ) V_2 ;
V_2 -> V_241 = F_125 () ;
if ( V_2 -> V_241 == NULL ) {
V_184 = - V_85 ;
goto V_287;
}
V_2 -> V_241 -> V_230 = V_2 ;
V_2 -> V_241 -> V_134 = L_26 ;
V_2 -> V_241 -> V_288 = F_96 ;
V_2 -> V_241 -> V_289 = F_97 ;
snprintf ( V_2 -> V_241 -> V_290 , V_291 , L_27 ,
V_265 -> V_134 , V_265 -> V_290 ) ;
V_2 -> V_241 -> V_81 = & V_265 -> V_22 ;
V_2 -> V_241 -> V_292 = 0xffffffff ;
V_184 = F_126 ( V_2 -> V_241 ) ;
if ( V_184 )
goto V_293;
F_68 ( V_2 ) ;
V_184 = F_106 ( V_22 ) ;
if ( V_184 )
goto V_294;
F_127 ( V_22 , & V_265 -> V_22 ) ;
V_184 = F_128 ( V_22 ) ;
if ( V_184 )
goto V_294;
return 0 ;
V_294:
F_129 ( V_2 -> V_241 ) ;
V_293:
F_130 ( V_2 -> V_241 ) ;
V_287:
F_131 ( V_2 -> V_4 ) ;
V_272:
F_132 ( V_22 ) ;
V_270:
F_133 ( V_268 ) ;
F_134 ( V_268 ) ;
return V_184 ;
}
static int F_135 ( struct V_264 * V_265 )
{
struct V_21 * V_22 = F_136 ( V_265 ) ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
if ( V_2 -> V_71 ) {
F_74 ( V_2 -> V_22 -> V_22 . V_81 , V_82 ,
V_2 -> V_71 , V_2 -> V_83 ) ;
V_2 -> V_71 = NULL ;
}
if ( V_2 -> V_268 ) {
F_133 ( V_2 -> V_268 ) ;
F_134 ( V_2 -> V_268 ) ;
V_2 -> V_268 = NULL ;
}
if ( V_2 -> V_18 != NULL )
F_137 ( V_2 -> V_18 ) ;
F_131 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
F_129 ( V_2 -> V_241 ) ;
F_130 ( V_2 -> V_241 ) ;
F_138 ( V_22 ) ;
F_139 ( & V_2 -> V_138 ) ;
F_132 ( V_22 ) ;
F_116 ( V_265 , NULL ) ;
return 0 ;
}
static void F_140 ( struct V_264 * V_265 )
{
struct V_21 * V_22 = F_136 ( V_265 ) ;
F_41 ( V_22 ) ;
}
static int F_141 ( struct V_264 * V_265 )
{
return - V_295 ;
}
static int F_142 ( struct V_264 * V_265 , T_6 V_296 )
{
return - V_295 ;
}
