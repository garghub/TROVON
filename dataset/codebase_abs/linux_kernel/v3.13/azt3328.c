static int
F_1 ( unsigned V_1 , T_1 V_2 , bool V_3 )
{
T_1 V_4 = F_2 ( V_1 ) , V_5 ;
V_5 = ( V_3 ) ? ( V_4 | V_2 ) : ( V_4 & ~ V_2 ) ;
F_3 ( V_5 , V_1 ) ;
if ( V_5 != V_4 )
return 1 ;
return 0 ;
}
static inline void
F_4 ( const struct V_6 * V_7 ,
unsigned V_1 ,
T_1 V_8
)
{
F_3 ( V_8 , V_7 -> V_9 + V_1 ) ;
}
static inline T_1
F_5 ( const struct V_6 * V_7 , unsigned V_1 )
{
return F_2 ( V_7 -> V_9 + V_1 ) ;
}
static inline void
F_6 ( const struct V_6 * V_7 ,
unsigned V_1 ,
T_2 V_8
)
{
F_7 ( V_8 , V_7 -> V_9 + V_1 ) ;
}
static inline T_2
F_8 ( const struct V_6 * V_7 , unsigned V_1 )
{
return F_9 ( V_7 -> V_9 + V_1 ) ;
}
static inline void
F_10 ( const struct V_6 * V_7 ,
unsigned V_1 ,
T_3 V_8
)
{
F_11 ( V_8 , V_7 -> V_9 + V_1 ) ;
}
static inline void
F_12 ( const struct V_6 * V_7 ,
unsigned V_1 , const void * V_10 , int V_11
)
{
unsigned long V_12 = V_7 -> V_9 + V_1 ;
if ( V_11 ) {
const T_3 * V_13 = V_10 ;
do {
F_11 ( * V_13 ++ , V_12 ) ;
V_12 += 4 ;
} while ( -- V_11 );
}
}
static inline T_3
F_13 ( const struct V_6 * V_7 , unsigned V_1 )
{
return F_14 ( V_7 -> V_9 + V_1 ) ;
}
static inline void
F_15 ( const struct V_14 * V_15 , unsigned V_1 , T_1 V_8 )
{
F_3 ( V_8 , V_15 -> V_16 + V_1 ) ;
}
static inline T_1
F_16 ( const struct V_14 * V_15 , unsigned V_1 )
{
return F_2 ( V_15 -> V_16 + V_1 ) ;
}
static inline void
F_17 ( const struct V_14 * V_15 , unsigned V_1 , T_2 V_8 )
{
F_7 ( V_8 , V_15 -> V_16 + V_1 ) ;
}
static inline void
F_18 ( const struct V_14 * V_15 , unsigned V_1 , T_3 V_8 )
{
F_11 ( V_8 , V_15 -> V_16 + V_1 ) ;
}
static inline void
F_19 ( const struct V_14 * V_15 , unsigned V_1 , T_1 V_8 )
{
F_3 ( V_8 , V_15 -> V_17 + V_1 ) ;
}
static inline void
F_20 ( const struct V_14 * V_15 , unsigned V_1 , T_2 V_8 )
{
F_7 ( V_8 , V_15 -> V_17 + V_1 ) ;
}
static inline T_1
F_21 ( const struct V_14 * V_15 , unsigned V_1 )
{
return F_2 ( V_15 -> V_17 + V_1 ) ;
}
static inline T_2
F_22 ( const struct V_14 * V_15 , unsigned V_1 )
{
return F_9 ( V_15 -> V_17 + V_1 ) ;
}
static inline void
F_23 ( const struct V_14 * V_15 , unsigned V_1 , T_2 V_8 )
{
F_7 ( V_8 , V_15 -> V_18 + V_1 ) ;
}
static inline T_2
F_24 ( const struct V_14 * V_15 , unsigned V_1 )
{
return F_9 ( V_15 -> V_18 + V_1 ) ;
}
static bool
F_25 ( const struct V_14 * V_15 ,
unsigned V_1 , bool V_19
)
{
unsigned long V_20 = V_15 -> V_18 + V_1 + 1 ;
bool V_21 ;
V_21 = F_1 ( V_20 , V_22 , V_19 ) ;
return ( V_19 ) ? ! V_21 : V_21 ;
}
static inline bool
F_26 ( const struct V_14 * V_15 ,
bool V_19
)
{
return F_25 (
V_15 ,
V_23 ,
V_19
) ;
}
static inline bool
F_27 ( const struct V_14 * V_15 ,
bool V_19
)
{
return F_25 (
V_15 ,
V_24 ,
V_19
) ;
}
static inline void
F_28 ( const struct V_14 * V_15 )
{
F_26 ( V_15 , 1 ) ;
F_23 ( V_15 , V_25 , 0x0000 ) ;
}
static inline void
F_29 ( unsigned short V_1 , const char * V_26 )
{
F_30 ( V_27
L_1 ,
V_26 , V_1 ) ;
}
static unsigned short
F_31 ( unsigned short V_1 )
{
static const struct {
unsigned short V_28 ;
} V_29 [] = {
{ V_25
| V_30
| V_31 } ,
{ V_23 } ,
{ V_32 } ,
{ V_33 } ,
{ V_34 } ,
{ V_35 } ,
{ V_36 } ,
{ V_37 } ,
{ V_38 } ,
{ V_39 } ,
{ V_40 } ,
{ V_41 } ,
{ V_24 } ,
{ V_42 } ,
{ V_43 } ,
{ V_44 } ,
{ V_45 } ,
{ V_46 } ,
} ;
unsigned short V_47 = V_48 ;
if ( V_1 <= V_49 ) {
unsigned short V_50 = V_1 / 2 ;
V_47 = V_29 [ V_50 ] . V_28 ;
if ( ! ( V_47 & ~ V_51 ) )
V_47 |= V_52 ;
} else {
switch ( V_1 ) {
case V_53 :
V_47 = V_44 ;
break;
case V_54 :
V_47 = V_31 ;
break;
case V_55 :
V_47 = V_44 ;
break;
case V_56 :
case V_57 :
V_47 = V_31 ;
break;
}
}
return V_47 ;
}
static unsigned short
F_32 ( struct V_58 * V_59 , unsigned short V_60 )
{
const struct V_14 * V_15 = V_59 -> V_61 ;
unsigned short V_47 = F_31 ( V_60 ) ;
unsigned short V_62 = 0 ;
bool V_63 = false ;
F_33 (
L_2 ,
V_60
) ;
if ( V_47 & V_48 )
V_63 = true ;
else {
if ( V_47 & V_64 )
V_62 = F_24 ( V_15 ,
V_47 & V_51 ) ;
else {
F_24 ( V_15 , V_65 ) ;
}
if ( V_47 & V_31 ) {
switch ( V_60 ) {
case V_66 :
V_62 |= V_67 ;
break;
case V_53 :
V_62 |= V_68 ;
break;
case V_54 :
case V_55 :
V_62 |= 0 ;
break;
case V_56 :
V_62 = V_69 >> 16 ;
break;
case V_57 :
V_62 = V_69 & 0xffff ;
break;
default:
V_63 = true ;
break;
}
}
}
if ( V_63 )
F_29 ( V_60 , L_3 ) ;
return V_62 ;
}
static void
F_34 ( struct V_58 * V_59 ,
unsigned short V_60 , unsigned short V_70 )
{
const struct V_14 * V_15 = V_59 -> V_61 ;
unsigned short V_47 = F_31 ( V_60 ) ;
bool V_63 = false ;
F_33 (
L_4 ,
V_60 , V_70
) ;
if ( V_47 & V_48 )
V_63 = true ;
else {
if ( V_47 & V_30 )
F_23 (
V_15 ,
V_47 & V_51 ,
V_70
) ;
else
if ( V_47 & V_71 ) {
switch ( V_60 ) {
case V_72 :
case V_53 :
case V_55 :
break;
default:
V_63 = true ;
break;
}
}
}
if ( V_63 )
F_29 ( V_60 , L_5 ) ;
}
static int
F_35 ( struct V_14 * V_15 )
{
struct V_73 * V_74 ;
struct V_75 V_59 ;
static struct V_76 V_77 = {
. V_78 = F_34 ,
. V_79 = F_32 ,
} ;
int V_80 ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
V_59 . V_81 = V_82
| V_83
| V_84 ;
V_59 . V_61 = V_15 ;
V_59 . V_85 = V_15 -> V_85 ;
V_80 = V_73 ( V_15 -> V_86 , 0 , & V_77 , NULL , & V_74 ) ;
if ( ! V_80 )
V_80 = F_36 ( V_74 , & V_59 , & V_15 -> V_59 ) ;
if ( V_80 )
F_30 ( V_87 L_6 , V_80 ) ;
return V_80 ;
}
static void
F_37 ( const struct V_14 * V_15 ,
unsigned V_1 ,
unsigned char V_88 ,
unsigned char V_89 ,
int V_90 , int V_91
)
{
unsigned long V_20 = V_15 -> V_18 + V_1 ;
unsigned char V_92 = 0 , V_93 = 0 ;
int V_94 = 0 , V_95 = 0 ;
F_38 () ;
if ( V_90 & V_96 ) {
V_92 = F_2 ( V_20 + 1 ) ;
if ( V_92 & V_22 )
V_88 |= V_22 ;
else
V_88 &= ~ V_22 ;
V_94 = ( V_92 > V_88 ) ? - 1 : 1 ;
}
if ( V_90 & V_97 ) {
V_93 = F_2 ( V_20 + 0 ) ;
V_95 = ( V_93 > V_89 ) ? - 1 : 1 ;
}
do {
if ( V_94 ) {
if ( V_92 != V_88 ) {
V_92 += V_94 ;
F_3 ( V_92 , V_20 + 1 ) ;
} else
V_94 = 0 ;
}
if ( V_95 ) {
if ( V_93 != V_89 ) {
V_93 += V_95 ;
F_3 ( V_93 , V_20 + 0 ) ;
} else
V_95 = 0 ;
}
if ( V_91 )
F_39 ( V_91 ) ;
} while ( ( V_94 ) || ( V_95 ) );
F_40 () ;
}
static void F_41 ( struct V_98 * V_99 , unsigned long V_70 )
{
V_99 -> V_1 = V_70 & 0xff ;
V_99 -> V_100 = ( V_70 >> 8 ) & 0x0f ;
V_99 -> V_101 = ( V_70 >> 12 ) & 0x0f ;
V_99 -> V_2 = ( V_70 >> 16 ) & 0xff ;
V_99 -> V_102 = ( V_70 >> 24 ) & 1 ;
V_99 -> V_103 = ( V_70 >> 25 ) & 1 ;
V_99 -> V_104 = ( V_70 >> 26 ) & 0x0f ;
}
static int
F_42 ( struct V_105 * V_106 ,
struct V_107 * V_108 )
{
struct V_98 V_1 ;
F_38 () ;
F_41 ( & V_1 , V_106 -> V_109 ) ;
V_108 -> type = V_1 . V_2 == 1 ?
V_110 : V_111 ;
V_108 -> V_11 = V_1 . V_103 + 1 ;
V_108 -> V_8 . integer . V_112 = 0 ;
V_108 -> V_8 . integer . V_113 = V_1 . V_2 ;
F_40 () ;
return 0 ;
}
static int
F_43 ( struct V_105 * V_106 ,
struct V_114 * V_115 )
{
struct V_14 * V_15 = F_44 ( V_106 ) ;
struct V_98 V_1 ;
T_2 V_116 , V_70 ;
F_38 () ;
F_41 ( & V_1 , V_106 -> V_109 ) ;
V_116 = F_24 ( V_15 , V_1 . V_1 ) ;
V_70 = ( V_116 >> V_1 . V_100 ) & V_1 . V_2 ;
if ( V_1 . V_102 )
V_70 = V_1 . V_2 - V_70 ;
V_115 -> V_8 . integer . V_8 [ 0 ] = V_70 ;
if ( V_1 . V_103 ) {
V_70 = ( V_116 >> V_1 . V_101 ) & V_1 . V_2 ;
if ( V_1 . V_102 )
V_70 = V_1 . V_2 - V_70 ;
V_115 -> V_8 . integer . V_8 [ 1 ] = V_70 ;
}
F_33 ( L_7
L_8 ,
V_1 . V_1 , V_116 ,
V_115 -> V_8 . integer . V_8 [ 0 ] , V_115 -> V_8 . integer . V_8 [ 1 ] ,
V_1 . V_100 , V_1 . V_101 , V_1 . V_2 , V_1 . V_102 , V_1 . V_103 ) ;
F_40 () ;
return 0 ;
}
static int
F_45 ( struct V_105 * V_106 ,
struct V_114 * V_115 )
{
struct V_14 * V_15 = F_44 ( V_106 ) ;
struct V_98 V_1 ;
T_2 V_116 , V_117 , V_70 ;
F_38 () ;
F_41 ( & V_1 , V_106 -> V_109 ) ;
V_116 = F_24 ( V_15 , V_1 . V_1 ) ;
V_70 = V_115 -> V_8 . integer . V_8 [ 0 ] & V_1 . V_2 ;
if ( V_1 . V_102 )
V_70 = V_1 . V_2 - V_70 ;
V_117 = V_116 & ~ ( V_1 . V_2 << V_1 . V_100 ) ;
V_117 |= ( V_70 << V_1 . V_100 ) ;
if ( V_1 . V_103 ) {
V_70 = V_115 -> V_8 . integer . V_8 [ 1 ] & V_1 . V_2 ;
if ( V_1 . V_102 )
V_70 = V_1 . V_2 - V_70 ;
V_117 &= ~ ( V_1 . V_2 << V_1 . V_101 ) ;
V_117 |= ( V_70 << V_1 . V_101 ) ;
}
if ( V_1 . V_2 >= 0x07 )
F_37 (
V_15 , V_1 . V_1 , V_117 >> 8 , V_117 & 0xff ,
V_96 | V_97 ,
0 ) ;
else
F_23 ( V_15 , V_1 . V_1 , V_117 ) ;
F_33 ( L_9
L_10 ,
V_1 . V_1 , V_115 -> V_8 . integer . V_8 [ 0 ] , V_115 -> V_8 . integer . V_8 [ 1 ] ,
V_116 , V_1 . V_100 , V_1 . V_101 ,
V_117 , F_24 ( V_15 , V_1 . V_1 ) ) ;
F_40 () ;
return ( V_117 != V_116 ) ;
}
static int
F_46 ( struct V_105 * V_106 ,
struct V_107 * V_108 )
{
static const char * const V_118 [] = {
L_11 , L_12
} ;
static const char * const V_119 [] = {
L_13 , L_14
} ;
static const char * const V_120 [] = {
L_14 , L_15 , L_16 , L_17 ,
L_18 , L_13 , L_19 , L_20
} ;
static const char * const V_121 [] = {
L_21 , L_22
} ;
struct V_98 V_1 ;
const char * const * V_122 = NULL ;
F_41 ( & V_1 , V_106 -> V_109 ) ;
V_108 -> type = V_123 ;
V_108 -> V_11 = ( V_1 . V_1 == V_42 ) ? 2 : 1 ;
V_108 -> V_8 . V_124 . V_125 = V_1 . V_104 ;
if ( V_108 -> V_8 . V_124 . V_126 > V_1 . V_104 - 1U )
V_108 -> V_8 . V_124 . V_126 = V_1 . V_104 - 1U ;
if ( V_1 . V_1 == V_45 ) {
switch( V_1 . V_100 ) {
case 8 :
V_122 = V_118 ;
break;
case 9 :
V_122 = V_119 ;
break;
case 15 :
V_122 = V_121 ;
break;
}
} else
if ( V_1 . V_1 == V_42 )
V_122 = V_120 ;
strcpy ( V_108 -> V_8 . V_124 . V_127 , V_122 [ V_108 -> V_8 . V_124 . V_126 ] ) ;
return 0 ;
}
static int
F_47 ( struct V_105 * V_106 ,
struct V_114 * V_115 )
{
struct V_14 * V_15 = F_44 ( V_106 ) ;
struct V_98 V_1 ;
unsigned short V_70 ;
F_41 ( & V_1 , V_106 -> V_109 ) ;
V_70 = F_24 ( V_15 , V_1 . V_1 ) ;
if ( V_1 . V_1 == V_42 ) {
V_115 -> V_8 . V_124 . V_126 [ 0 ] = ( V_70 >> 8 ) & ( V_1 . V_104 - 1 ) ;
V_115 -> V_8 . V_124 . V_126 [ 1 ] = ( V_70 >> 0 ) & ( V_1 . V_104 - 1 ) ;
} else
V_115 -> V_8 . V_124 . V_126 [ 0 ] = ( V_70 >> V_1 . V_100 ) & ( V_1 . V_104 - 1 ) ;
F_33 ( L_23 ,
V_1 . V_1 , V_70 , V_115 -> V_8 . V_124 . V_126 [ 0 ] , V_115 -> V_8 . V_124 . V_126 [ 1 ] ,
V_1 . V_100 , V_1 . V_104 ) ;
return 0 ;
}
static int
F_48 ( struct V_105 * V_106 ,
struct V_114 * V_115 )
{
struct V_14 * V_15 = F_44 ( V_106 ) ;
struct V_98 V_1 ;
T_2 V_116 , V_117 , V_70 ;
F_41 ( & V_1 , V_106 -> V_109 ) ;
V_116 = F_24 ( V_15 , V_1 . V_1 ) ;
V_70 = V_116 ;
if ( V_1 . V_1 == V_42 ) {
if ( V_115 -> V_8 . V_124 . V_126 [ 0 ] > V_1 . V_104 - 1U ||
V_115 -> V_8 . V_124 . V_126 [ 1 ] > V_1 . V_104 - 1U )
return - V_128 ;
V_70 = ( V_115 -> V_8 . V_124 . V_126 [ 0 ] << 8 ) |
( V_115 -> V_8 . V_124 . V_126 [ 1 ] << 0 ) ;
} else {
if ( V_115 -> V_8 . V_124 . V_126 [ 0 ] > V_1 . V_104 - 1U )
return - V_128 ;
V_70 &= ~ ( ( V_1 . V_104 - 1 ) << V_1 . V_100 ) ;
V_70 |= ( V_115 -> V_8 . V_124 . V_126 [ 0 ] << V_1 . V_100 ) ;
}
F_23 ( V_15 , V_1 . V_1 , V_70 ) ;
V_117 = V_70 ;
F_33 ( L_24 , V_1 . V_1 , V_70 , V_116 ) ;
return ( V_117 != V_116 ) ;
}
static int
F_35 ( struct V_14 * V_15 )
{
struct V_129 * V_86 ;
const struct V_130 * V_131 ;
unsigned int V_132 ;
int V_133 ;
F_38 () ;
if ( F_49 ( ! V_15 || ! V_15 -> V_86 ) )
return - V_128 ;
V_86 = V_15 -> V_86 ;
F_23 ( V_15 , V_25 , 0x0000 ) ;
for ( V_132 = 0 ; V_132 < F_50 ( V_134 ) ; ++ V_132 ) {
F_23 ( V_15 ,
V_134 [ V_132 ] [ 0 ] ,
V_134 [ V_132 ] [ 1 ] ) ;
}
V_131 = V_135 ;
for ( V_132 = 0 ; V_132 < F_50 ( V_135 ) ;
++ V_132 , ++ V_131 ) {
if ( ( V_133 = F_51 ( V_15 -> V_86 , F_52 ( V_131 , V_15 ) ) ) < 0 )
return V_133 ;
}
F_53 ( V_86 , L_25 ) ;
strcpy ( V_86 -> V_136 , L_25 ) ;
F_40 () ;
return 0 ;
}
static int
F_54 ( struct V_137 * V_138 ,
struct V_139 * V_140 )
{
int V_141 ;
F_38 () ;
V_141 = F_55 ( V_138 , F_56 ( V_140 ) ) ;
F_40 () ;
return V_141 ;
}
static int
F_57 ( struct V_137 * V_138 )
{
F_38 () ;
F_58 ( V_138 ) ;
F_40 () ;
return 0 ;
}
static void
F_59 ( struct V_6 * V_7 ,
enum V_142 V_143 ,
unsigned int V_144 ,
unsigned int V_145
)
{
unsigned long V_146 ;
T_2 V_70 = 0xff00 ;
T_1 V_147 = 0 ;
F_38 () ;
switch ( V_143 ) {
case V_148 : V_147 = V_149 ; break;
case V_150 : V_147 = V_151 ; break;
case V_152 :
V_147 = V_153 ; break;
case V_154 : V_147 = V_155 ; break;
case V_156 : V_147 = V_157 ; break;
case V_158 : V_147 = V_159 ; break;
case V_160 : V_147 = V_161 ; break;
case V_162 : V_147 = V_163 ; break;
case V_164 : V_147 = V_165 ; break;
case V_166 : V_147 = V_167 ; break;
case V_168 : V_147 = V_169 ; break;
default:
F_60 ( V_27 L_26 , V_143 ) ;
case V_170 : V_147 = V_171 ; break;
case V_172 : V_147 = V_173 ; break;
case V_174 : V_147 = V_175 ; break;
}
V_70 |= V_147 ;
if ( V_145 == 2 )
V_70 |= V_176 ;
if ( V_144 == 16 )
V_70 |= V_177 ;
F_61 ( V_7 -> V_178 , V_146 ) ;
F_6 ( V_7 , V_179 , V_70 ) ;
if ( V_7 -> type != V_180 )
F_6 ( V_7 , V_181 ,
F_8 ( V_7 , V_181 ) |
V_182 |
V_183 |
V_184 |
V_185 |
V_186
) ;
F_62 ( V_7 -> V_178 , V_146 ) ;
F_40 () ;
}
static inline void
F_63 ( struct V_6 * V_7
)
{
F_59 ( V_7 , V_148 , 8 , 1 ) ;
}
static void
F_64 ( struct V_14 * V_15 ,
unsigned V_187 ,
bool V_188
)
{
bool V_189 = ! V_188 ;
if ( V_189 )
V_15 -> V_190 |= V_187 ;
else
V_15 -> V_190 &= ~ V_187 ;
F_65 ( L_27 ,
V_187 , V_189 , V_15 -> V_190 ) ;
F_17 ( V_15 , V_191 , V_15 -> V_190 ) ;
}
static inline void
F_66 ( struct V_14 * V_15 , bool V_188 )
{
F_65 ( L_28 , V_188 ) ;
F_64 (
V_15 , V_192 , V_188
) ;
}
static void
F_67 ( struct V_14 * V_15 ,
enum V_193 V_194 ,
bool V_188
)
{
struct V_6 * V_7 = & V_15 -> V_195 [ V_194 ] ;
bool V_196 = ( V_7 -> V_197 != V_188 ) ;
F_65 (
L_29 ,
V_7 -> V_127 , V_188 , V_196
) ;
if ( V_196 ) {
static const struct {
enum V_193 V_198 ;
enum V_193 V_199 ;
} V_200 [ 3 ] =
{ { V_180 , V_201 } ,
{ V_202 , V_201 } ,
{ V_202 , V_180 } } ;
bool V_203 ;
if ( V_188 )
V_203 = 1 ;
else {
V_203 =
( ( ! V_15 -> V_195 [ V_200 [ V_194 ] . V_198 ]
. V_197 )
&& ( ! V_15 -> V_195 [ V_200 [ V_194 ] . V_199 ]
. V_197 ) ) ;
}
if ( V_203 )
F_66 ( V_15 , V_188 ) ;
if ( ! V_188 )
F_63 ( V_7 ) ;
V_7 -> V_197 = V_188 ;
}
}
static void
F_68 ( struct V_6 * V_7 ,
unsigned long V_12 ,
unsigned int V_204 ,
unsigned int V_205
)
{
F_38 () ;
F_69 ( V_204 & 1 , L_30 ) ;
F_69 ( V_205 != 2 * V_204 ,
L_31 ,
V_205 , V_204 ) ;
if ( ! V_7 -> V_197 ) {
unsigned long V_146 ;
T_3 V_206 ;
struct V_207 {
T_3 V_208 ;
T_3 V_209 ;
T_3 V_210 ;
} V_211 ( ( V_212 ) ) V_213 ;
V_206 = V_205 / 2 ;
V_213 . V_208 = V_12 ;
V_213 . V_209 = V_12 + V_206 ;
F_65 (
L_32 ,
V_213 . V_208 , V_206 ,
V_213 . V_209 , V_206 ,
V_204 , V_205 ) ;
V_213 . V_210 = ( V_206 << 16 ) | ( V_206 ) ;
F_61 ( V_7 -> V_178 , V_146 ) ;
F_12 (
V_7 , V_214 , & V_213 , 3
) ;
F_62 ( V_7 -> V_178 , V_146 ) ;
}
F_40 () ;
}
static int
F_70 ( struct V_137 * V_138 )
{
struct V_215 * V_216 = V_138 -> V_216 ;
struct V_6 * V_7 = V_216 -> V_61 ;
#if 0
unsigned int size = snd_pcm_lib_buffer_bytes(substream);
unsigned int count = snd_pcm_lib_period_bytes(substream);
#endif
F_38 () ;
V_7 -> V_217 = V_216 -> V_218 ;
#if 0
snd_azf3328_codec_setfmt(codec,
runtime->rate,
snd_pcm_format_width(runtime->format),
runtime->channels);
snd_azf3328_codec_setdmaa(codec,
runtime->dma_addr, count, size);
#endif
F_40 () ;
return 0 ;
}
static int
F_71 ( struct V_137 * V_138 , int V_219 )
{
struct V_14 * V_15 = F_72 ( V_138 ) ;
struct V_215 * V_216 = V_138 -> V_216 ;
struct V_6 * V_7 = V_216 -> V_61 ;
int V_220 = 0 ;
T_2 V_221 ;
bool V_222 = false ;
bool V_223 = ( V_202 == V_7 -> type ) ;
F_73 ( L_33 , V_219 ) ;
switch ( V_219 ) {
case V_224 :
F_65 ( L_34 , V_7 -> V_127 ) ;
if ( V_223 ) {
V_222 =
F_27 (
V_15 , 1
) ;
}
F_59 ( V_7 ,
V_216 -> V_225 ,
F_74 ( V_216 -> V_226 ) ,
V_216 -> V_145 ) ;
F_75 ( V_7 -> V_178 ) ;
V_221 = F_8 ( V_7 , V_181 ) ;
V_221 &= ~ V_227 ;
F_6 ( V_7 , V_181 , V_221 ) ;
F_6 ( V_7 , V_228 , 0xffff ) ;
F_76 ( V_7 -> V_178 ) ;
F_68 ( V_7 , V_216 -> V_218 ,
F_77 ( V_138 ) ,
F_78 ( V_138 )
) ;
F_75 ( V_7 -> V_178 ) ;
#ifdef F_79
V_221 |= V_182 | V_183 ;
F_6 ( V_7 , V_181 , V_221 ) ;
V_221 |= V_227 | V_185 ;
F_6 ( V_7 , V_181 , V_221 ) ;
#else
F_6 ( V_7 , V_181 ,
0x0000 ) ;
F_6 ( V_7 , V_181 ,
V_182 ) ;
F_6 ( V_7 , V_181 ,
V_182 |
V_183 ) ;
F_6 ( V_7 , V_181 ,
V_227 |
V_184 |
V_185 |
V_186 ) ;
#endif
F_76 ( V_7 -> V_178 ) ;
F_67 ( V_15 , V_7 -> type , 1 ) ;
if ( V_223 ) {
if ( ! V_222 )
F_27 (
V_15 , 0
) ;
}
F_65 ( L_35 , V_7 -> V_127 ) ;
break;
case V_229 :
F_65 ( L_36 , V_7 -> V_127 ) ;
F_75 ( V_7 -> V_178 ) ;
if ( V_7 -> V_197 )
F_6 ( V_7 , V_181 ,
F_8 (
V_7 , V_181
) | V_227
) ;
F_76 ( V_7 -> V_178 ) ;
break;
case V_230 :
F_65 ( L_37 , V_7 -> V_127 ) ;
if ( V_223 ) {
V_222 =
F_27 (
V_15 , 1
) ;
}
F_75 ( V_7 -> V_178 ) ;
V_221 = F_8 ( V_7 , V_181 ) ;
V_221 &= ~ V_227 ;
F_6 ( V_7 , V_181 , V_221 ) ;
V_221 |= V_182 ;
F_6 ( V_7 , V_181 , V_221 ) ;
V_221 &= ~ V_182 ;
F_6 ( V_7 , V_181 , V_221 ) ;
F_76 ( V_7 -> V_178 ) ;
F_67 ( V_15 , V_7 -> type , 0 ) ;
if ( V_223 ) {
if ( ! V_222 )
F_27 (
V_15 , 0
) ;
}
F_65 ( L_38 , V_7 -> V_127 ) ;
break;
case V_231 :
F_65 ( L_39 , V_7 -> V_127 ) ;
F_6 ( V_7 , V_181 ,
F_8 (
V_7 , V_181
) & ~ V_227
) ;
break;
case V_232 :
F_60 ( V_87 L_40 ) ;
break;
case V_233 :
F_60 ( V_87 L_41 ) ;
break;
default:
F_60 ( V_87 L_42 ) ;
return - V_128 ;
}
F_40 () ;
return V_220 ;
}
static T_4
F_80 ( struct V_137 * V_138
)
{
const struct V_6 * V_7 =
V_138 -> V_216 -> V_61 ;
unsigned long V_220 ;
T_4 V_234 ;
V_220 = F_13 ( V_7 , V_235 ) ;
#ifdef F_81
V_220 -= F_13 ( V_7 , V_214 ) ;
#else
V_220 -= V_7 -> V_217 ;
#endif
V_234 = F_82 ( V_138 -> V_216 , V_220 ) ;
F_65 ( L_43 ,
V_236 , V_7 -> V_127 , V_220 , V_234 ) ;
return V_234 ;
}
static inline void
F_83 ( struct V_14 * V_15 ,
bool V_188
)
{
F_1 (
V_15 -> V_17 + V_237 ,
V_238 ,
V_188
) ;
}
static inline void
F_84 ( struct V_14 * V_15 ,
bool V_188
)
{
F_1 (
V_15 -> V_17 + V_237 ,
V_239 ,
V_188
) ;
}
static void
F_85 ( struct V_14 * V_15 ,
unsigned int V_240
)
{
F_1 (
V_15 -> V_17 + V_237 ,
0x02 ,
( V_240 & 1 ) != 0
) ;
F_1 (
V_15 -> V_17 + V_237 ,
0x04 ,
( V_240 & 2 ) != 0
) ;
}
static inline void
F_86 ( struct V_14 * V_15 , bool V_188 )
{
F_64 (
V_15 , V_241 , V_188
) ;
}
static inline void
F_87 ( struct V_14 * V_15 )
{
F_88 ( L_44 ) ;
F_22 ( V_15 , V_242 ) ;
}
static int
F_89 ( struct V_243 * V_243 , int V_26 )
{
struct V_14 * V_15 = F_90 ( V_243 ) ;
int V_141 ;
F_88 ( L_45 , V_26 ) ;
switch ( V_26 ) {
case V_244 :
case V_245 :
V_141 = 0 ;
break;
default:
V_141 = - 1 ;
break;
}
F_85 ( V_15 ,
V_246 ) ;
F_86 ( V_15 , ( V_141 == 0 ) ) ;
return V_141 ;
}
static void
F_91 ( struct V_243 * V_243 )
{
struct V_14 * V_15 = F_90 ( V_243 ) ;
F_88 ( L_46 ) ;
F_85 ( V_15 ,
V_247 ) ;
F_86 ( V_15 , 0 ) ;
}
static int
F_92 ( struct V_243 * V_243 ,
int * V_248 ,
int * V_249
)
{
struct V_14 * V_15 = F_90 ( V_243 ) ;
int V_250 ;
T_1 V_70 ;
unsigned long V_146 ;
if ( F_49 ( ! V_15 ) )
return 0 ;
F_61 ( & V_15 -> V_251 , V_146 ) ;
V_70 = F_21 ( V_15 , V_252 ) ;
* V_249 = ( ~ ( V_70 ) >> 4 ) & 0xf ;
V_70 = F_21 ( V_15 , V_253 ) ;
if ( V_70 & V_254 ) {
for ( V_250 = 0 ; V_250 < F_50 ( V_15 -> V_248 ) ; ++ V_250 ) {
V_70 = ( V_250 << 4 ) | 0x0f ;
F_19 ( V_15 , V_253 , V_70 ) ;
V_15 -> V_248 [ V_250 ] = F_22 (
V_15 , V_242
) ;
}
}
V_70 = 0x03 ;
F_19 ( V_15 , V_253 , V_70 ) ;
F_20 ( V_15 , V_242 , 0xffff ) ;
F_62 ( & V_15 -> V_251 , V_146 ) ;
for ( V_250 = 0 ; V_250 < F_50 ( V_15 -> V_248 ) ; V_250 ++ ) {
V_248 [ V_250 ] = V_15 -> V_248 [ V_250 ] ;
if ( V_248 [ V_250 ] == 0xffff )
V_248 [ V_250 ] = - 1 ;
}
F_88 ( L_47 ,
V_248 [ 0 ] , V_248 [ 1 ] , V_248 [ 2 ] , V_248 [ 3 ] , * V_249
) ;
return 0 ;
}
static int
F_93 ( struct V_14 * V_15 , int V_255 )
{
struct V_243 * V_256 ;
V_15 -> V_243 = V_256 = F_94 () ;
if ( ! V_256 ) {
F_30 ( V_87 L_48 ) ;
return - V_257 ;
}
F_95 ( V_256 , L_49 ) ;
F_96 ( V_256 , L_50 , F_97 ( V_15 -> V_85 ) ) ;
F_98 ( V_256 , & V_15 -> V_85 -> V_255 ) ;
V_256 -> V_258 = V_15 -> V_17 ;
F_99 ( V_256 , V_15 ) ;
V_256 -> V_259 = F_89 ;
V_256 -> V_260 = F_91 ;
V_256 -> V_261 = 16 ;
V_256 -> V_262 = F_92 ;
F_84 ( V_15 , 0 ) ;
F_85 ( V_15 ,
V_247 ) ;
F_86 ( V_15 , 0 ) ;
F_100 ( V_15 -> V_243 ) ;
return 0 ;
}
static void
F_101 ( struct V_14 * V_15 )
{
if ( V_15 -> V_243 ) {
F_102 ( V_15 -> V_243 ) ;
V_15 -> V_243 = NULL ;
}
F_83 ( V_15 , 0 ) ;
}
static inline int
F_93 ( struct V_14 * V_15 , int V_255 ) { return - V_263 ; }
static inline void
F_101 ( struct V_14 * V_15 ) { }
static inline void
F_87 ( struct V_14 * V_15 )
{
F_30 ( V_27 L_51 ) ;
}
static inline void
F_103 ( T_1 V_264 )
{
F_65 (
L_52 ,
V_264
) ;
}
static inline void
F_104 ( const struct V_6 * V_265 ,
T_1 V_266
)
{
T_1 V_264 ;
enum V_193 V_194 ;
const struct V_6 * V_7 = V_265 ;
for ( V_194 = V_202 ;
V_194 <= V_201 ;
++ V_194 , ++ V_7 ) {
if ( ! ( V_266 & ( 1 << V_194 ) ) )
continue;
F_75 ( V_7 -> V_178 ) ;
V_264 = F_5 ( V_7 , V_228 ) ;
F_4 ( V_7 , V_228 , V_264 ) ;
F_76 ( V_7 -> V_178 ) ;
if ( V_7 -> V_138 ) {
F_105 ( V_7 -> V_138 ) ;
F_65 ( L_53 ,
V_7 -> V_127 ,
V_264 ,
F_13 (
V_7 , V_235
)
) ;
} else
F_30 ( V_27 L_54 ) ;
if ( V_264 & V_267 )
F_103 ( V_264 ) ;
}
}
static T_5
F_106 ( int V_268 , void * V_269 )
{
struct V_14 * V_15 = V_269 ;
T_1 V_266 ;
#if V_270
static unsigned long V_271 ;
#endif
V_266 = F_16 ( V_15 , V_272 ) ;
if ( ! ( V_266 &
( V_273 | V_274 | V_275
| V_276 | V_277 | V_278 )
) )
return V_279 ;
F_65 (
L_55 ,
V_271 ++ ,
V_266
) ;
if ( V_266 & V_278 ) {
if ( V_15 -> V_280 )
F_107 ( V_15 -> V_280 , V_15 -> V_280 -> V_281 ) ;
F_75 ( & V_15 -> V_251 ) ;
F_15 ( V_15 , V_282 + 3 , 0x07 ) ;
F_76 ( & V_15 -> V_251 ) ;
F_65 ( L_56 ) ;
}
if ( V_266 & ( V_273 | V_274 | V_275 ) )
F_104 ( V_15 -> V_195 , V_266 ) ;
if ( V_266 & V_276 )
F_87 ( V_15 ) ;
if ( V_266 & V_277 ) {
F_108 ( V_268 , V_15 -> V_283 -> V_61 ) ;
F_65 ( L_57 ) ;
}
return V_284 ;
}
static int
F_109 ( struct V_137 * V_138 ,
enum V_193 V_194
)
{
struct V_14 * V_15 = F_72 ( V_138 ) ;
struct V_215 * V_216 = V_138 -> V_216 ;
struct V_6 * V_7 = & V_15 -> V_195 [ V_194 ] ;
F_38 () ;
V_7 -> V_138 = V_138 ;
V_216 -> V_285 = V_286 ;
F_110 ( V_216 , 0 , V_287 ,
& V_288 ) ;
V_216 -> V_61 = V_7 ;
F_40 () ;
return 0 ;
}
static int
F_111 ( struct V_137 * V_138 )
{
return F_109 ( V_138 , V_202 ) ;
}
static int
F_112 ( struct V_137 * V_138 )
{
return F_109 ( V_138 , V_180 ) ;
}
static int
F_113 ( struct V_137 * V_138 )
{
return F_109 ( V_138 , V_201 ) ;
}
static int
F_114 ( struct V_137 * V_138
)
{
struct V_6 * V_7 =
V_138 -> V_216 -> V_61 ;
F_38 () ;
V_7 -> V_138 = NULL ;
F_40 () ;
return 0 ;
}
static int
F_115 ( struct V_14 * V_15 )
{
enum { V_289 , V_290 , V_291 };
struct V_292 * V_293 ;
int V_133 ;
F_38 () ;
V_133 = F_116 ( V_15 -> V_86 , L_58 , V_289 ,
1 , 1 , & V_293 ) ;
if ( V_133 < 0 )
return V_133 ;
F_117 ( V_293 , V_294 ,
& V_295 ) ;
F_117 ( V_293 , V_296 ,
& V_297 ) ;
V_293 -> V_61 = V_15 ;
V_293 -> V_298 = 0 ;
strcpy ( V_293 -> V_127 , V_15 -> V_86 -> V_299 ) ;
V_15 -> V_293 [ V_202 ] = V_293 ;
V_15 -> V_293 [ V_180 ] = V_293 ;
F_118 ( V_293 , V_300 ,
F_119 ( V_15 -> V_85 ) ,
64 * 1024 , 64 * 1024 ) ;
V_133 = F_116 ( V_15 -> V_86 , L_59 , V_290 ,
1 , 0 , & V_293 ) ;
if ( V_133 < 0 )
return V_133 ;
F_117 ( V_293 , V_294 ,
& V_301 ) ;
V_293 -> V_61 = V_15 ;
V_293 -> V_298 = 0 ;
strcpy ( V_293 -> V_127 , V_15 -> V_86 -> V_299 ) ;
V_15 -> V_293 [ V_201 ] = V_293 ;
F_118 ( V_293 , V_300 ,
F_119 ( V_15 -> V_85 ) ,
64 * 1024 , 64 * 1024 ) ;
F_40 () ;
return 0 ;
}
static int
F_120 ( struct V_302 * V_280 )
{
struct V_14 * V_15 ;
unsigned long V_146 ;
unsigned int V_91 ;
F_38 () ;
V_15 = F_121 ( V_280 ) ;
V_91 = ( ( V_280 -> V_281 * V_303 ) - 1 ) & V_304 ;
if ( V_91 < 49 ) {
F_122 ( L_60 , V_91 ) ;
V_91 = 49 ;
}
F_122 ( L_61 , V_91 ) ;
V_91 |= V_305 | V_306 ;
F_61 ( & V_15 -> V_251 , V_146 ) ;
F_18 ( V_15 , V_282 , V_91 ) ;
F_62 ( & V_15 -> V_251 , V_146 ) ;
F_40 () ;
return 0 ;
}
static int
F_123 ( struct V_302 * V_280 )
{
struct V_14 * V_15 ;
unsigned long V_146 ;
F_38 () ;
V_15 = F_121 ( V_280 ) ;
F_61 ( & V_15 -> V_251 , V_146 ) ;
F_15 ( V_15 , V_282 + 3 , 0x04 ) ;
F_62 ( & V_15 -> V_251 , V_146 ) ;
F_40 () ;
return 0 ;
}
static int
F_124 ( struct V_302 * V_280 ,
unsigned long * V_307 , unsigned long * V_308 )
{
F_38 () ;
* V_307 = 1 ;
* V_308 = 1024000 / V_303 ;
F_40 () ;
return 0 ;
}
static int
F_125 ( struct V_14 * V_15 , int V_309 )
{
struct V_302 * V_280 = NULL ;
struct V_310 V_311 ;
int V_133 ;
F_38 () ;
V_311 . V_312 = V_313 ;
V_311 . V_314 = V_315 ;
V_311 . V_86 = V_15 -> V_86 -> V_316 ;
V_311 . V_309 = V_309 ;
V_311 . V_317 = 0 ;
V_318 . V_319 *= V_303 ;
V_318 . V_320 /= V_303 ;
V_133 = F_126 ( V_15 -> V_86 , L_62 , & V_311 , & V_280 ) ;
if ( V_133 < 0 )
goto V_321;
strcpy ( V_280 -> V_127 , L_63 ) ;
V_280 -> V_61 = V_15 ;
V_280 -> V_285 = V_318 ;
V_15 -> V_280 = V_280 ;
F_123 ( V_280 ) ;
V_133 = 0 ;
V_321:
F_40 () ;
return V_133 ;
}
static int
F_127 ( struct V_14 * V_15 )
{
if ( V_15 -> V_268 < 0 )
goto V_322;
F_28 ( V_15 ) ;
F_123 ( V_15 -> V_280 ) ;
F_101 ( V_15 ) ;
if ( V_15 -> V_268 >= 0 )
F_128 ( V_15 -> V_268 ) ;
V_322:
if ( V_15 -> V_268 >= 0 )
F_129 ( V_15 -> V_268 , V_15 ) ;
F_130 ( V_15 -> V_85 ) ;
F_131 ( V_15 -> V_85 ) ;
F_132 ( V_15 ) ;
return 0 ;
}
static int
F_133 ( struct V_323 * V_309 )
{
struct V_14 * V_15 = V_309 -> V_324 ;
return F_127 ( V_15 ) ;
}
static inline void
F_134 ( const struct V_14 * V_15 )
{
#if V_325
T_2 V_326 ;
F_135 (
L_64
L_65 ,
V_15 -> V_16 , V_15 -> V_17 , V_15 -> V_327 ,
V_15 -> V_328 , V_15 -> V_18 , V_15 -> V_268
) ;
F_135 ( L_66 ,
F_21 ( V_15 , 0 ) ,
F_21 ( V_15 , 1 ) ,
F_21 ( V_15 , 2 ) ,
F_21 ( V_15 , 3 ) ,
F_21 ( V_15 , 4 ) ,
F_21 ( V_15 , 5 )
) ;
for ( V_326 = 0 ; V_326 < 0x07 ; V_326 += 1 )
F_135 ( L_67 , F_2 ( V_15 -> V_327 + V_326 ) ) ;
for ( V_326 = 0 ; V_326 <= 0x07 ; V_326 += 1 )
F_135 ( L_68 ,
V_326 , F_2 ( 0x200 + V_326 ) , F_2 ( 0x208 + V_326 ) ) ;
for ( V_326 = 0 ; V_326 <= 0x01 ; V_326 += 1 )
F_135 (
L_69
L_70 ,
V_326 ,
F_2 ( 0x300 + V_326 ) ,
F_2 ( 0x310 + V_326 ) ,
F_2 ( 0x320 + V_326 ) ,
F_2 ( 0x330 + V_326 ) ,
F_2 ( 0x388 + V_326 ) ,
F_2 ( 0x38c + V_326 )
) ;
for ( V_326 = 0 ; V_326 < V_329 ; V_326 += 2 )
F_135 ( L_71 ,
V_326 , F_136 ( V_15 , V_326 )
) ;
for ( V_326 = 0 ; V_326 < V_330 ; V_326 += 2 )
F_135 ( L_72 ,
V_326 , F_24 ( V_15 , V_326 )
) ;
#endif
}
static int
F_137 ( struct V_129 * V_86 ,
struct V_331 * V_85 ,
unsigned long V_332 ,
struct V_14 * * V_333 )
{
struct V_14 * V_15 ;
int V_133 ;
static struct V_334 V_77 = {
. V_335 = F_133 ,
} ;
T_1 V_336 ;
enum V_193 V_194 ;
struct V_6 * V_337 ;
* V_333 = NULL ;
V_133 = F_138 ( V_85 ) ;
if ( V_133 < 0 )
return V_133 ;
V_15 = F_139 ( sizeof( * V_15 ) , V_338 ) ;
if ( V_15 == NULL ) {
V_133 = - V_257 ;
goto V_339;
}
F_140 ( & V_15 -> V_251 ) ;
V_15 -> V_86 = V_86 ;
V_15 -> V_85 = V_85 ;
V_15 -> V_268 = - 1 ;
if ( F_141 ( V_85 , F_142 ( 24 ) ) < 0 ||
F_143 ( V_85 , F_142 ( 24 ) ) < 0 ) {
F_60 ( V_87 L_73
L_74
) ;
V_133 = - V_340 ;
goto V_339;
}
V_133 = F_144 ( V_85 , L_75 ) ;
if ( V_133 < 0 )
goto V_339;
V_15 -> V_16 = F_145 ( V_85 , 0 ) ;
V_15 -> V_17 = F_145 ( V_85 , 1 ) ;
V_15 -> V_327 = F_145 ( V_85 , 2 ) ;
V_15 -> V_328 = F_145 ( V_85 , 3 ) ;
V_15 -> V_18 = F_145 ( V_85 , 4 ) ;
V_337 = & V_15 -> V_195 [ V_202 ] ;
V_337 -> V_9 = V_15 -> V_16 + V_341 ;
V_337 -> V_178 = & V_15 -> V_251 ;
V_337 -> type = V_202 ;
V_337 -> V_127 = L_76 ;
V_337 = & V_15 -> V_195 [ V_180 ] ;
V_337 -> V_9 = V_15 -> V_16 + V_342 ;
V_337 -> V_178 = & V_15 -> V_251 ;
V_337 -> type = V_180 ;
V_337 -> V_127 = L_77 ;
V_337 = & V_15 -> V_195 [ V_201 ] ;
V_337 -> V_9 = V_15 -> V_16 + V_343 ;
V_337 -> V_178 = & V_15 -> V_251 ;
V_337 -> type = V_201 ;
V_337 -> V_127 = L_78 ;
if ( F_146 ( V_85 -> V_268 , F_106 ,
V_344 , V_345 , V_15 ) ) {
F_60 ( V_87 L_79 , V_85 -> V_268 ) ;
V_133 = - V_346 ;
goto V_339;
}
V_15 -> V_268 = V_85 -> V_268 ;
F_147 ( V_85 ) ;
F_128 ( V_15 -> V_268 ) ;
F_134 ( V_15 ) ;
V_133 = F_148 ( V_86 , V_347 , V_15 , & V_77 ) ;
if ( V_133 < 0 )
goto V_339;
V_133 = F_35 ( V_15 ) ;
if ( V_133 < 0 )
goto V_339;
V_336 = V_183 | V_185 | V_186 ;
for ( V_194 = V_202 ;
V_194 <= V_201 ; ++ V_194 ) {
struct V_6 * V_7 =
& V_15 -> V_195 [ V_194 ] ;
V_7 -> V_197 = 1 ;
F_67 ( V_15 , V_194 , 0 ) ;
F_149 ( V_7 -> V_178 ) ;
F_4 ( V_7 , V_181 ,
V_336 ) ;
F_150 ( V_7 -> V_178 ) ;
}
F_151 ( V_86 , & V_85 -> V_255 ) ;
* V_333 = V_15 ;
V_133 = 0 ;
goto V_321;
V_339:
if ( V_15 )
F_127 ( V_15 ) ;
F_131 ( V_85 ) ;
V_321:
return V_133 ;
}
static int
F_152 ( struct V_331 * V_85 , const struct V_348 * V_349 )
{
static int V_255 ;
struct V_129 * V_86 ;
struct V_14 * V_15 ;
struct V_350 * V_351 ;
int V_133 ;
F_38 () ;
if ( V_255 >= V_352 ) {
V_133 = - V_353 ;
goto V_321;
}
if ( ! V_188 [ V_255 ] ) {
V_255 ++ ;
V_133 = - V_354 ;
goto V_321;
}
V_133 = F_153 ( V_355 [ V_255 ] , V_356 [ V_255 ] , V_357 , 0 , & V_86 ) ;
if ( V_133 < 0 )
goto V_321;
strcpy ( V_86 -> V_358 , L_62 ) ;
strcpy ( V_86 -> V_299 , L_80 ) ;
V_133 = F_137 ( V_86 , V_85 , V_349 -> V_359 , & V_15 ) ;
if ( V_133 < 0 )
goto V_339;
V_86 -> V_61 = V_15 ;
V_133 = F_154 (
V_86 , 0 ,
V_360 , V_15 -> V_327 ,
V_361 | V_362 ,
- 1 , & V_15 -> V_283
) ;
if ( V_133 < 0 ) {
F_60 ( V_87 L_81 ,
V_15 -> V_327
) ;
goto V_339;
}
V_133 = F_125 ( V_15 , 0 ) ;
if ( V_133 < 0 )
goto V_339;
V_133 = F_115 ( V_15 ) ;
if ( V_133 < 0 )
goto V_339;
if ( F_155 ( V_86 , V_15 -> V_328 , V_15 -> V_328 + 2 ,
V_363 , 1 , & V_351 ) < 0 ) {
F_60 ( V_87 L_82 ,
V_15 -> V_328 , V_15 -> V_328 + 2
) ;
} else {
V_133 = F_156 ( V_351 , 1 , 2 ) ;
if ( V_133 < 0 )
goto V_339;
V_133 = F_157 ( V_351 , 0 , 1 , NULL ) ;
if ( V_133 < 0 )
goto V_339;
V_351 -> V_61 = V_15 ;
}
sprintf ( V_86 -> V_364 , L_83 ,
V_86 -> V_299 , V_15 -> V_16 , V_15 -> V_268 ) ;
V_133 = F_158 ( V_86 ) ;
if ( V_133 < 0 )
goto V_339;
#ifdef F_159
F_30 ( V_365
L_84
L_85
L_86
L_87 ,
1024000 / V_303 , V_303 ) ;
#endif
F_93 ( V_15 , V_255 ) ;
F_160 ( V_85 , V_86 ) ;
V_255 ++ ;
V_133 = 0 ;
goto V_321;
V_339:
F_60 ( V_87 L_88 ) ;
F_161 ( V_86 ) ;
V_321:
F_40 () ;
return V_133 ;
}
static void
F_162 ( struct V_331 * V_85 )
{
F_38 () ;
F_161 ( F_163 ( V_85 ) ) ;
F_40 () ;
}
static inline void
F_164 ( unsigned long V_366 , unsigned V_11 , T_3 * V_367 )
{
unsigned V_1 ;
for ( V_1 = 0 ; V_1 < V_11 ; ++ V_1 ) {
* V_367 = F_14 ( V_366 ) ;
F_165 ( L_89 ,
V_366 , * V_367 ) ;
++ V_367 ;
V_366 += sizeof( * V_367 ) ;
}
}
static inline void
F_166 ( const T_3 * V_367 ,
unsigned long V_366 ,
unsigned V_11
)
{
unsigned V_1 ;
for ( V_1 = 0 ; V_1 < V_11 ; ++ V_1 ) {
F_11 ( * V_367 , V_366 ) ;
F_165 ( L_90 ,
V_366 , * V_367 , F_14 ( V_366 ) ) ;
++ V_367 ;
V_366 += sizeof( * V_367 ) ;
}
}
static inline void
F_167 ( struct V_14 * V_15 )
{
#ifdef F_168
F_169 ( V_15 -> V_59 ) ;
#else
F_164 ( V_15 -> V_18 ,
F_50 ( V_15 -> V_368 ) , V_15 -> V_368 ) ;
F_26 ( V_15 , 1 ) ;
F_27 ( V_15 , 1 ) ;
#endif
}
static inline void
F_170 ( const struct V_14 * V_15 )
{
#ifdef F_168
F_171 ( V_15 -> V_59 ) ;
#else
F_166 ( V_15 -> V_368 , V_15 -> V_18 ,
F_50 ( V_15 -> V_368 ) ) ;
F_7 ( ( ( T_2 * ) V_15 -> V_368 ) [ 1 ] , V_15 -> V_18 + 2 ) ;
#endif
}
static int
F_172 ( struct V_309 * V_255 )
{
struct V_331 * V_85 = F_173 ( V_255 ) ;
struct V_129 * V_86 = F_174 ( V_255 ) ;
struct V_14 * V_15 = V_86 -> V_61 ;
T_2 * V_369 ;
F_175 ( V_86 , V_370 ) ;
F_176 ( V_15 -> V_293 [ V_202 ] ) ;
F_176 ( V_15 -> V_293 [ V_201 ] ) ;
F_167 ( V_15 ) ;
F_164 ( V_15 -> V_16 ,
F_50 ( V_15 -> V_371 ) , V_15 -> V_371 ) ;
V_369 = ( T_2 * ) V_15 -> V_371 ;
V_369 [ V_191 / 2 ] = V_15 -> V_190 ;
F_164 ( V_15 -> V_17 ,
F_50 ( V_15 -> V_372 ) , V_15 -> V_372 ) ;
F_164 ( V_15 -> V_327 ,
F_50 ( V_15 -> V_373 ) , V_15 -> V_373 ) ;
F_164 ( V_15 -> V_328 ,
F_50 ( V_15 -> V_374 ) , V_15 -> V_374 ) ;
F_131 ( V_85 ) ;
F_177 ( V_85 ) ;
F_178 ( V_85 , V_375 ) ;
return 0 ;
}
static int
F_179 ( struct V_309 * V_255 )
{
struct V_331 * V_85 = F_173 ( V_255 ) ;
struct V_129 * V_86 = F_174 ( V_255 ) ;
const struct V_14 * V_15 = V_86 -> V_61 ;
F_178 ( V_85 , V_376 ) ;
F_180 ( V_85 ) ;
if ( F_138 ( V_85 ) < 0 ) {
F_30 ( V_87 L_91
L_92 ) ;
F_181 ( V_86 ) ;
return - V_377 ;
}
F_147 ( V_85 ) ;
F_166 ( V_15 -> V_372 , V_15 -> V_17 ,
F_50 ( V_15 -> V_372 ) ) ;
F_166 ( V_15 -> V_373 , V_15 -> V_327 ,
F_50 ( V_15 -> V_373 ) ) ;
F_166 ( V_15 -> V_374 , V_15 -> V_328 ,
F_50 ( V_15 -> V_374 ) ) ;
F_170 ( V_15 ) ;
F_166 ( V_15 -> V_371 , V_15 -> V_16 ,
F_50 ( V_15 -> V_371 ) ) ;
F_175 ( V_86 , V_378 ) ;
return 0 ;
}
