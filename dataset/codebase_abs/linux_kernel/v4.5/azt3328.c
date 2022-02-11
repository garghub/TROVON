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
static inline T_2
F_17 ( const struct V_14 * V_15 , unsigned V_1 )
{
return F_9 ( V_15 -> V_16 + V_1 ) ;
}
static inline void
F_18 ( const struct V_14 * V_15 , unsigned V_1 , T_2 V_8 )
{
F_7 ( V_8 , V_15 -> V_16 + V_1 ) ;
}
static inline void
F_19 ( const struct V_14 * V_15 , unsigned V_1 , T_3 V_8 )
{
F_11 ( V_8 , V_15 -> V_16 + V_1 ) ;
}
static inline void
F_20 ( const struct V_14 * V_15 , unsigned V_1 , T_1 V_8 )
{
F_3 ( V_8 , V_15 -> V_17 + V_1 ) ;
}
static inline void
F_21 ( const struct V_14 * V_15 , unsigned V_1 , T_2 V_8 )
{
F_7 ( V_8 , V_15 -> V_17 + V_1 ) ;
}
static inline T_1
F_22 ( const struct V_14 * V_15 , unsigned V_1 )
{
return F_2 ( V_15 -> V_17 + V_1 ) ;
}
static inline T_2
F_23 ( const struct V_14 * V_15 , unsigned V_1 )
{
return F_9 ( V_15 -> V_17 + V_1 ) ;
}
static inline void
F_24 ( const struct V_14 * V_15 , unsigned V_1 , T_2 V_8 )
{
F_7 ( V_8 , V_15 -> V_18 + V_1 ) ;
}
static inline T_2
F_25 ( const struct V_14 * V_15 , unsigned V_1 )
{
return F_9 ( V_15 -> V_18 + V_1 ) ;
}
static bool
F_26 ( const struct V_14 * V_15 ,
unsigned V_1 , bool V_19
)
{
unsigned long V_20 = V_15 -> V_18 + V_1 + 1 ;
bool V_21 ;
V_21 = F_1 ( V_20 , V_22 , V_19 ) ;
return ( V_19 ) ? ! V_21 : V_21 ;
}
static inline bool
F_27 ( const struct V_14 * V_15 ,
bool V_19
)
{
return F_26 (
V_15 ,
V_23 ,
V_19
) ;
}
static inline bool
F_28 ( const struct V_14 * V_15 ,
bool V_19
)
{
return F_26 (
V_15 ,
V_24 ,
V_19
) ;
}
static inline void
F_29 ( const struct V_14 * V_15 )
{
F_27 ( V_15 , 1 ) ;
F_24 ( V_15 , V_25 , 0x0000 ) ;
}
static inline void
F_30 ( const struct V_14 * V_15 ,
unsigned short V_1 , const char * V_26 )
{
F_31 ( V_15 -> V_27 -> V_28 ,
L_1 ,
V_26 , V_1 ) ;
}
static unsigned short
F_32 ( unsigned short V_1 )
{
static const struct {
unsigned short V_29 ;
} V_30 [] = {
{ V_25
| V_31
| V_32 } ,
{ V_23 } ,
{ V_33 } ,
{ V_34 } ,
{ V_35 } ,
{ V_36 } ,
{ V_37 } ,
{ V_38 } ,
{ V_39 } ,
{ V_40 } ,
{ V_41 } ,
{ V_42 } ,
{ V_24 } ,
{ V_43 } ,
{ V_44 } ,
{ V_45 } ,
{ V_46 } ,
{ V_47 } ,
} ;
unsigned short V_48 = V_49 ;
if ( V_1 <= V_50 ) {
unsigned short V_51 = V_1 / 2 ;
V_48 = V_30 [ V_51 ] . V_29 ;
if ( ! ( V_48 & ~ V_52 ) )
V_48 |= V_53 ;
} else {
switch ( V_1 ) {
case V_54 :
V_48 = V_45 ;
break;
case V_55 :
V_48 = V_32 ;
break;
case V_56 :
V_48 = V_45 ;
break;
case V_57 :
case V_58 :
V_48 = V_32 ;
break;
}
}
return V_48 ;
}
static unsigned short
F_33 ( struct V_59 * V_60 , unsigned short V_61 )
{
const struct V_14 * V_15 = V_60 -> V_62 ;
unsigned short V_48 = F_32 ( V_61 ) ;
unsigned short V_63 = 0 ;
bool V_64 = false ;
F_34 ( V_15 -> V_27 -> V_28 , L_2 ,
V_61 ) ;
if ( V_48 & V_49 )
V_64 = true ;
else {
if ( V_48 & V_65 )
V_63 = F_25 ( V_15 ,
V_48 & V_52 ) ;
else {
F_25 ( V_15 , V_66 ) ;
}
if ( V_48 & V_32 ) {
switch ( V_61 ) {
case V_67 :
V_63 |= V_68 ;
break;
case V_54 :
V_63 |= V_69 ;
break;
case V_55 :
case V_56 :
V_63 |= 0 ;
break;
case V_57 :
V_63 = V_70 >> 16 ;
break;
case V_58 :
V_63 = V_70 & 0xffff ;
break;
default:
V_64 = true ;
break;
}
}
}
if ( V_64 )
F_30 ( V_15 , V_61 , L_3 ) ;
return V_63 ;
}
static void
F_35 ( struct V_59 * V_60 ,
unsigned short V_61 , unsigned short V_71 )
{
const struct V_14 * V_15 = V_60 -> V_62 ;
unsigned short V_48 = F_32 ( V_61 ) ;
bool V_64 = false ;
F_34 ( V_15 -> V_27 -> V_28 ,
L_4 ,
V_61 , V_71 ) ;
if ( V_48 & V_49 )
V_64 = true ;
else {
if ( V_48 & V_31 )
F_24 (
V_15 ,
V_48 & V_52 ,
V_71
) ;
else
if ( V_48 & V_72 ) {
switch ( V_61 ) {
case V_73 :
case V_54 :
case V_56 :
break;
default:
V_64 = true ;
break;
}
}
}
if ( V_64 )
F_30 ( V_15 , V_61 , L_5 ) ;
}
static int
F_36 ( struct V_14 * V_15 )
{
struct V_74 * V_75 ;
struct V_76 V_60 ;
static struct V_77 V_78 = {
. V_79 = F_35 ,
. V_80 = F_33 ,
} ;
int V_81 ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_82 = V_83
| V_84
| V_85 ;
V_60 . V_62 = V_15 ;
V_60 . V_86 = V_15 -> V_86 ;
V_81 = V_74 ( V_15 -> V_27 , 0 , & V_78 , NULL , & V_75 ) ;
if ( ! V_81 )
V_81 = F_37 ( V_75 , & V_60 , & V_15 -> V_60 ) ;
if ( V_81 )
F_38 ( V_15 -> V_27 -> V_28 , L_6 , V_81 ) ;
return V_81 ;
}
static void
F_39 ( const struct V_14 * V_15 ,
unsigned V_1 ,
unsigned char V_87 ,
unsigned char V_88 ,
int V_89 , int V_90
)
{
unsigned long V_20 = V_15 -> V_18 + V_1 ;
unsigned char V_91 = 0 , V_92 = 0 ;
int V_93 = 0 , V_94 = 0 ;
if ( V_89 & V_95 ) {
V_91 = F_2 ( V_20 + 1 ) ;
if ( V_91 & V_22 )
V_87 |= V_22 ;
else
V_87 &= ~ V_22 ;
V_93 = ( V_91 > V_87 ) ? - 1 : 1 ;
}
if ( V_89 & V_96 ) {
V_92 = F_2 ( V_20 + 0 ) ;
V_94 = ( V_92 > V_88 ) ? - 1 : 1 ;
}
do {
if ( V_93 ) {
if ( V_91 != V_87 ) {
V_91 += V_93 ;
F_3 ( V_91 , V_20 + 1 ) ;
} else
V_93 = 0 ;
}
if ( V_94 ) {
if ( V_92 != V_88 ) {
V_92 += V_94 ;
F_3 ( V_92 , V_20 + 0 ) ;
} else
V_94 = 0 ;
}
if ( V_90 )
F_40 ( V_90 ) ;
} while ( ( V_93 ) || ( V_94 ) );
}
static void F_41 ( struct V_97 * V_98 , unsigned long V_71 )
{
V_98 -> V_1 = V_71 & 0xff ;
V_98 -> V_99 = ( V_71 >> 8 ) & 0x0f ;
V_98 -> V_100 = ( V_71 >> 12 ) & 0x0f ;
V_98 -> V_2 = ( V_71 >> 16 ) & 0xff ;
V_98 -> V_101 = ( V_71 >> 24 ) & 1 ;
V_98 -> V_102 = ( V_71 >> 25 ) & 1 ;
V_98 -> V_103 = ( V_71 >> 26 ) & 0x0f ;
}
static int
F_42 ( struct V_104 * V_105 ,
struct V_106 * V_107 )
{
struct V_97 V_1 ;
F_41 ( & V_1 , V_105 -> V_108 ) ;
V_107 -> type = V_1 . V_2 == 1 ?
V_109 : V_110 ;
V_107 -> V_11 = V_1 . V_102 + 1 ;
V_107 -> V_8 . integer . V_111 = 0 ;
V_107 -> V_8 . integer . V_112 = V_1 . V_2 ;
return 0 ;
}
static int
F_43 ( struct V_104 * V_105 ,
struct V_113 * V_114 )
{
struct V_14 * V_15 = F_44 ( V_105 ) ;
struct V_97 V_1 ;
T_2 V_115 , V_71 ;
F_41 ( & V_1 , V_105 -> V_108 ) ;
V_115 = F_25 ( V_15 , V_1 . V_1 ) ;
V_71 = ( V_115 >> V_1 . V_99 ) & V_1 . V_2 ;
if ( V_1 . V_101 )
V_71 = V_1 . V_2 - V_71 ;
V_114 -> V_8 . integer . V_8 [ 0 ] = V_71 ;
if ( V_1 . V_102 ) {
V_71 = ( V_115 >> V_1 . V_100 ) & V_1 . V_2 ;
if ( V_1 . V_101 )
V_71 = V_1 . V_2 - V_71 ;
V_114 -> V_8 . integer . V_8 [ 1 ] = V_71 ;
}
F_34 ( V_15 -> V_27 -> V_28 ,
L_7 ,
V_1 . V_1 , V_115 ,
V_114 -> V_8 . integer . V_8 [ 0 ] , V_114 -> V_8 . integer . V_8 [ 1 ] ,
V_1 . V_99 , V_1 . V_100 , V_1 . V_2 , V_1 . V_101 , V_1 . V_102 ) ;
return 0 ;
}
static int
F_45 ( struct V_104 * V_105 ,
struct V_113 * V_114 )
{
struct V_14 * V_15 = F_44 ( V_105 ) ;
struct V_97 V_1 ;
T_2 V_115 , V_116 , V_71 ;
F_41 ( & V_1 , V_105 -> V_108 ) ;
V_115 = F_25 ( V_15 , V_1 . V_1 ) ;
V_71 = V_114 -> V_8 . integer . V_8 [ 0 ] & V_1 . V_2 ;
if ( V_1 . V_101 )
V_71 = V_1 . V_2 - V_71 ;
V_116 = V_115 & ~ ( V_1 . V_2 << V_1 . V_99 ) ;
V_116 |= ( V_71 << V_1 . V_99 ) ;
if ( V_1 . V_102 ) {
V_71 = V_114 -> V_8 . integer . V_8 [ 1 ] & V_1 . V_2 ;
if ( V_1 . V_101 )
V_71 = V_1 . V_2 - V_71 ;
V_116 &= ~ ( V_1 . V_2 << V_1 . V_100 ) ;
V_116 |= ( V_71 << V_1 . V_100 ) ;
}
if ( V_1 . V_2 >= 0x07 )
F_39 (
V_15 , V_1 . V_1 , V_116 >> 8 , V_116 & 0xff ,
V_95 | V_96 ,
0 ) ;
else
F_24 ( V_15 , V_1 . V_1 , V_116 ) ;
F_34 ( V_15 -> V_27 -> V_28 ,
L_8 ,
V_1 . V_1 , V_114 -> V_8 . integer . V_8 [ 0 ] , V_114 -> V_8 . integer . V_8 [ 1 ] ,
V_115 , V_1 . V_99 , V_1 . V_100 ,
V_116 , F_25 ( V_15 , V_1 . V_1 ) ) ;
return ( V_116 != V_115 ) ;
}
static int
F_46 ( struct V_104 * V_105 ,
struct V_106 * V_107 )
{
static const char * const V_117 [] = {
L_9 , L_10
} ;
static const char * const V_118 [] = {
L_11 , L_12
} ;
static const char * const V_119 [] = {
L_12 , L_13 , L_14 , L_15 ,
L_16 , L_11 , L_17 , L_18
} ;
static const char * const V_120 [] = {
L_19 , L_20
} ;
struct V_97 V_1 ;
const char * const * V_121 = NULL ;
F_41 ( & V_1 , V_105 -> V_108 ) ;
if ( V_1 . V_1 == V_46 ) {
switch( V_1 . V_99 ) {
case 8 :
V_121 = V_117 ;
break;
case 9 :
V_121 = V_118 ;
break;
case 15 :
V_121 = V_120 ;
break;
}
} else if ( V_1 . V_1 == V_43 )
V_121 = V_119 ;
return F_47 ( V_107 ,
( V_1 . V_1 == V_43 ) ? 2 : 1 ,
V_1 . V_103 , V_121 ) ;
}
static int
F_48 ( struct V_104 * V_105 ,
struct V_113 * V_114 )
{
struct V_14 * V_15 = F_44 ( V_105 ) ;
struct V_97 V_1 ;
unsigned short V_71 ;
F_41 ( & V_1 , V_105 -> V_108 ) ;
V_71 = F_25 ( V_15 , V_1 . V_1 ) ;
if ( V_1 . V_1 == V_43 ) {
V_114 -> V_8 . V_122 . V_123 [ 0 ] = ( V_71 >> 8 ) & ( V_1 . V_103 - 1 ) ;
V_114 -> V_8 . V_122 . V_123 [ 1 ] = ( V_71 >> 0 ) & ( V_1 . V_103 - 1 ) ;
} else
V_114 -> V_8 . V_122 . V_123 [ 0 ] = ( V_71 >> V_1 . V_99 ) & ( V_1 . V_103 - 1 ) ;
F_34 ( V_15 -> V_27 -> V_28 ,
L_21 ,
V_1 . V_1 , V_71 , V_114 -> V_8 . V_122 . V_123 [ 0 ] , V_114 -> V_8 . V_122 . V_123 [ 1 ] ,
V_1 . V_99 , V_1 . V_103 ) ;
return 0 ;
}
static int
F_49 ( struct V_104 * V_105 ,
struct V_113 * V_114 )
{
struct V_14 * V_15 = F_44 ( V_105 ) ;
struct V_97 V_1 ;
T_2 V_115 , V_116 , V_71 ;
F_41 ( & V_1 , V_105 -> V_108 ) ;
V_115 = F_25 ( V_15 , V_1 . V_1 ) ;
V_71 = V_115 ;
if ( V_1 . V_1 == V_43 ) {
if ( V_114 -> V_8 . V_122 . V_123 [ 0 ] > V_1 . V_103 - 1U ||
V_114 -> V_8 . V_122 . V_123 [ 1 ] > V_1 . V_103 - 1U )
return - V_124 ;
V_71 = ( V_114 -> V_8 . V_122 . V_123 [ 0 ] << 8 ) |
( V_114 -> V_8 . V_122 . V_123 [ 1 ] << 0 ) ;
} else {
if ( V_114 -> V_8 . V_122 . V_123 [ 0 ] > V_1 . V_103 - 1U )
return - V_124 ;
V_71 &= ~ ( ( V_1 . V_103 - 1 ) << V_1 . V_99 ) ;
V_71 |= ( V_114 -> V_8 . V_122 . V_123 [ 0 ] << V_1 . V_99 ) ;
}
F_24 ( V_15 , V_1 . V_1 , V_71 ) ;
V_116 = V_71 ;
F_34 ( V_15 -> V_27 -> V_28 ,
L_22 , V_1 . V_1 , V_71 , V_115 ) ;
return ( V_116 != V_115 ) ;
}
static int
F_36 ( struct V_14 * V_15 )
{
struct V_125 * V_27 ;
const struct V_126 * V_127 ;
unsigned int V_128 ;
int V_129 ;
if ( F_50 ( ! V_15 || ! V_15 -> V_27 ) )
return - V_124 ;
V_27 = V_15 -> V_27 ;
F_24 ( V_15 , V_25 , 0x0000 ) ;
for ( V_128 = 0 ; V_128 < F_51 ( V_130 ) ; ++ V_128 ) {
F_24 ( V_15 ,
V_130 [ V_128 ] [ 0 ] ,
V_130 [ V_128 ] [ 1 ] ) ;
}
V_127 = V_131 ;
for ( V_128 = 0 ; V_128 < F_51 ( V_131 ) ;
++ V_128 , ++ V_127 ) {
if ( ( V_129 = F_52 ( V_15 -> V_27 , F_53 ( V_127 , V_15 ) ) ) < 0 )
return V_129 ;
}
F_54 ( V_27 , L_23 ) ;
strcpy ( V_27 -> V_132 , L_23 ) ;
return 0 ;
}
static int
F_55 ( struct V_133 * V_134 ,
struct V_135 * V_136 )
{
return F_56 ( V_134 , F_57 ( V_136 ) ) ;
}
static int
F_58 ( struct V_133 * V_134 )
{
F_59 ( V_134 ) ;
return 0 ;
}
static void
F_60 ( struct V_6 * V_7 ,
enum V_137 V_138 ,
unsigned int V_139 ,
unsigned int V_140
)
{
unsigned long V_141 ;
T_2 V_71 = 0xff00 ;
T_1 V_142 = 0 ;
switch ( V_138 ) {
case V_143 : V_142 = V_144 ; break;
case V_145 : V_142 = V_146 ; break;
case V_147 :
V_142 = V_148 ; break;
case V_149 : V_142 = V_150 ; break;
case V_151 : V_142 = V_152 ; break;
case V_153 : V_142 = V_154 ; break;
case V_155 : V_142 = V_156 ; break;
case V_157 : V_142 = V_158 ; break;
case V_159 : V_142 = V_160 ; break;
case V_161 : V_142 = V_162 ; break;
case V_163 : V_142 = V_164 ; break;
default:
F_61 ( V_165 L_24 , V_138 ) ;
case V_166 : V_142 = V_167 ; break;
case V_168 : V_142 = V_169 ; break;
case V_170 : V_142 = V_171 ; break;
}
V_71 |= V_142 ;
if ( V_140 == 2 )
V_71 |= V_172 ;
if ( V_139 == 16 )
V_71 |= V_173 ;
F_62 ( V_7 -> V_174 , V_141 ) ;
F_6 ( V_7 , V_175 , V_71 ) ;
if ( V_7 -> type != V_176 )
F_6 ( V_7 , V_177 ,
F_8 ( V_7 , V_177 ) |
V_178 |
V_179 |
V_180 |
V_181 |
V_182
) ;
F_63 ( V_7 -> V_174 , V_141 ) ;
}
static inline void
F_64 ( struct V_6 * V_7
)
{
F_60 ( V_7 , V_143 , 8 , 1 ) ;
}
static void
F_65 ( struct V_14 * V_15 ,
unsigned V_183 ,
bool V_184
)
{
bool V_185 = ! V_184 ;
if ( V_185 )
V_15 -> V_186 |= V_183 ;
else
V_15 -> V_186 &= ~ V_183 ;
F_34 ( V_15 -> V_27 -> V_28 ,
L_25 ,
V_183 , V_185 , V_15 -> V_186 ) ;
F_18 ( V_15 , V_187 , V_15 -> V_186 ) ;
}
static inline void
F_66 ( struct V_14 * V_15 , bool V_184 )
{
F_34 ( V_15 -> V_27 -> V_28 , L_26 , V_184 ) ;
F_65 (
V_15 , V_188 , V_184
) ;
}
static void
F_67 ( struct V_14 * V_15 ,
enum V_189 V_190 ,
bool V_184
)
{
struct V_6 * V_7 = & V_15 -> V_191 [ V_190 ] ;
bool V_192 = ( V_7 -> V_193 != V_184 ) ;
F_34 ( V_15 -> V_27 -> V_28 ,
L_27 ,
V_7 -> V_194 , V_184 , V_192
) ;
if ( V_192 ) {
static const struct {
enum V_189 V_195 ;
enum V_189 V_196 ;
} V_197 [ 3 ] =
{ { V_176 , V_198 } ,
{ V_199 , V_198 } ,
{ V_199 , V_176 } } ;
bool V_200 ;
if ( V_184 )
V_200 = 1 ;
else {
V_200 =
( ( ! V_15 -> V_191 [ V_197 [ V_190 ] . V_195 ]
. V_193 )
&& ( ! V_15 -> V_191 [ V_197 [ V_190 ] . V_196 ]
. V_193 ) ) ;
}
if ( V_200 )
F_66 ( V_15 , V_184 ) ;
if ( ! V_184 )
F_64 ( V_7 ) ;
V_7 -> V_193 = V_184 ;
}
}
static void
F_68 ( struct V_14 * V_15 ,
struct V_6 * V_7 ,
unsigned long V_12 ,
unsigned int V_201 ,
unsigned int V_202
)
{
F_69 ( V_201 & 1 , L_28 ) ;
F_69 ( V_202 != 2 * V_201 ,
L_29 ,
V_202 , V_201 ) ;
if ( ! V_7 -> V_193 ) {
unsigned long V_141 ;
T_3 V_203 ;
struct V_204 {
T_3 V_205 ;
T_3 V_206 ;
T_3 V_207 ;
} V_208 ( ( V_209 ) ) V_210 ;
V_203 = V_202 / 2 ;
V_210 . V_205 = V_12 ;
V_210 . V_206 = V_12 + V_203 ;
F_34 ( V_15 -> V_27 -> V_28 ,
L_30 ,
V_210 . V_205 , V_203 ,
V_210 . V_206 , V_203 ,
V_201 , V_202 ) ;
V_210 . V_207 = ( V_203 << 16 ) | ( V_203 ) ;
F_62 ( V_7 -> V_174 , V_141 ) ;
F_12 (
V_7 , V_211 , & V_210 , 3
) ;
F_63 ( V_7 -> V_174 , V_141 ) ;
}
}
static int
F_70 ( struct V_133 * V_134 )
{
struct V_212 * V_213 = V_134 -> V_213 ;
struct V_6 * V_7 = V_213 -> V_62 ;
#if 0
unsigned int size = snd_pcm_lib_buffer_bytes(substream);
unsigned int count = snd_pcm_lib_period_bytes(substream);
#endif
V_7 -> V_214 = V_213 -> V_215 ;
#if 0
snd_azf3328_codec_setfmt(codec,
runtime->rate,
snd_pcm_format_width(runtime->format),
runtime->channels);
snd_azf3328_codec_setdmaa(chip, codec,
runtime->dma_addr, count, size);
#endif
return 0 ;
}
static int
F_71 ( struct V_133 * V_134 , int V_216 )
{
struct V_14 * V_15 = F_72 ( V_134 ) ;
struct V_212 * V_213 = V_134 -> V_213 ;
struct V_6 * V_7 = V_213 -> V_62 ;
int V_217 = 0 ;
T_2 V_218 ;
bool V_219 = false ;
bool V_220 = ( V_199 == V_7 -> type ) ;
switch ( V_216 ) {
case V_221 :
F_34 ( V_15 -> V_27 -> V_28 , L_31 , V_7 -> V_194 ) ;
if ( V_220 ) {
V_219 =
F_28 (
V_15 , 1
) ;
}
F_60 ( V_7 ,
V_213 -> V_222 ,
F_73 ( V_213 -> V_223 ) ,
V_213 -> V_140 ) ;
F_74 ( V_7 -> V_174 ) ;
V_218 = F_8 ( V_7 , V_177 ) ;
V_218 &= ~ V_224 ;
F_6 ( V_7 , V_177 , V_218 ) ;
F_6 ( V_7 , V_225 , 0xffff ) ;
F_75 ( V_7 -> V_174 ) ;
F_68 ( V_15 , V_7 , V_213 -> V_215 ,
F_76 ( V_134 ) ,
F_77 ( V_134 )
) ;
F_74 ( V_7 -> V_174 ) ;
#ifdef F_78
V_218 |= V_178 | V_179 ;
F_6 ( V_7 , V_177 , V_218 ) ;
V_218 |= V_224 | V_181 ;
F_6 ( V_7 , V_177 , V_218 ) ;
#else
F_6 ( V_7 , V_177 ,
0x0000 ) ;
F_6 ( V_7 , V_177 ,
V_178 ) ;
F_6 ( V_7 , V_177 ,
V_178 |
V_179 ) ;
F_6 ( V_7 , V_177 ,
V_224 |
V_180 |
V_181 |
V_182 ) ;
#endif
F_75 ( V_7 -> V_174 ) ;
F_67 ( V_15 , V_7 -> type , 1 ) ;
if ( V_220 ) {
if ( ! V_219 )
F_28 (
V_15 , 0
) ;
}
F_34 ( V_15 -> V_27 -> V_28 , L_32 , V_7 -> V_194 ) ;
break;
case V_226 :
F_34 ( V_15 -> V_27 -> V_28 , L_33 , V_7 -> V_194 ) ;
F_74 ( V_7 -> V_174 ) ;
if ( V_7 -> V_193 )
F_6 ( V_7 , V_177 ,
F_8 (
V_7 , V_177
) | V_224
) ;
F_75 ( V_7 -> V_174 ) ;
break;
case V_227 :
F_34 ( V_15 -> V_27 -> V_28 , L_34 , V_7 -> V_194 ) ;
if ( V_220 ) {
V_219 =
F_28 (
V_15 , 1
) ;
}
F_74 ( V_7 -> V_174 ) ;
V_218 = F_8 ( V_7 , V_177 ) ;
V_218 &= ~ V_224 ;
F_6 ( V_7 , V_177 , V_218 ) ;
V_218 |= V_178 ;
F_6 ( V_7 , V_177 , V_218 ) ;
V_218 &= ~ V_178 ;
F_6 ( V_7 , V_177 , V_218 ) ;
F_75 ( V_7 -> V_174 ) ;
F_67 ( V_15 , V_7 -> type , 0 ) ;
if ( V_220 ) {
if ( ! V_219 )
F_28 (
V_15 , 0
) ;
}
F_34 ( V_15 -> V_27 -> V_28 , L_35 , V_7 -> V_194 ) ;
break;
case V_228 :
F_34 ( V_15 -> V_27 -> V_28 , L_36 , V_7 -> V_194 ) ;
F_6 ( V_7 , V_177 ,
F_8 (
V_7 , V_177
) & ~ V_224
) ;
break;
case V_229 :
F_79 ( 1 , L_37 ) ;
break;
case V_230 :
F_79 ( 1 , L_38 ) ;
break;
default:
F_79 ( 1 , L_39 ) ;
return - V_124 ;
}
return V_217 ;
}
static T_4
F_80 ( struct V_133 * V_134
)
{
const struct V_6 * V_7 =
V_134 -> V_213 -> V_62 ;
unsigned long V_217 ;
T_4 V_231 ;
V_217 = F_13 ( V_7 , V_232 ) ;
#ifdef F_81
V_217 -= F_13 ( V_7 , V_211 ) ;
#else
V_217 -= V_7 -> V_214 ;
#endif
V_231 = F_82 ( V_134 -> V_213 , V_217 ) ;
F_34 ( V_134 -> V_233 -> V_27 -> V_28 , L_40 ,
V_234 , V_7 -> V_194 , V_217 , V_231 ) ;
return V_231 ;
}
static inline void
F_83 ( struct V_14 * V_15 ,
bool V_184
)
{
F_1 (
V_15 -> V_17 + V_235 ,
V_236 ,
V_184
) ;
}
static inline void
F_84 ( struct V_14 * V_15 ,
bool V_184
)
{
F_1 (
V_15 -> V_17 + V_235 ,
V_237 ,
V_184
) ;
}
static void
F_85 ( struct V_14 * V_15 ,
unsigned int V_238
)
{
F_1 (
V_15 -> V_17 + V_235 ,
0x02 ,
( V_238 & 1 ) != 0
) ;
F_1 (
V_15 -> V_17 + V_235 ,
0x04 ,
( V_238 & 2 ) != 0
) ;
}
static inline void
F_86 ( struct V_14 * V_15 , bool V_184 )
{
F_65 (
V_15 , V_239 , V_184
) ;
}
static inline void
F_87 ( struct V_14 * V_15 )
{
F_34 ( V_15 -> V_27 -> V_28 , L_41 ) ;
F_23 ( V_15 , V_240 ) ;
}
static int
F_88 ( struct V_241 * V_241 , int V_26 )
{
struct V_14 * V_15 = F_89 ( V_241 ) ;
int V_242 ;
F_34 ( V_15 -> V_27 -> V_28 , L_42 , V_26 ) ;
switch ( V_26 ) {
case V_243 :
case V_244 :
V_242 = 0 ;
break;
default:
V_242 = - 1 ;
break;
}
F_85 ( V_15 ,
V_245 ) ;
F_86 ( V_15 , ( V_242 == 0 ) ) ;
return V_242 ;
}
static void
F_90 ( struct V_241 * V_241 )
{
struct V_14 * V_15 = F_89 ( V_241 ) ;
F_34 ( V_15 -> V_27 -> V_28 , L_43 ) ;
F_85 ( V_15 ,
V_246 ) ;
F_86 ( V_15 , 0 ) ;
}
static int
F_91 ( struct V_241 * V_241 ,
int * V_247 ,
int * V_248
)
{
struct V_14 * V_15 = F_89 ( V_241 ) ;
int V_249 ;
T_1 V_71 ;
unsigned long V_141 ;
if ( F_50 ( ! V_15 ) )
return 0 ;
F_62 ( & V_15 -> V_250 , V_141 ) ;
V_71 = F_22 ( V_15 , V_251 ) ;
* V_248 = ( ~ ( V_71 ) >> 4 ) & 0xf ;
V_71 = F_22 ( V_15 , V_252 ) ;
if ( V_71 & V_253 ) {
for ( V_249 = 0 ; V_249 < F_51 ( V_15 -> V_247 ) ; ++ V_249 ) {
V_71 = ( V_249 << 4 ) | 0x0f ;
F_20 ( V_15 , V_252 , V_71 ) ;
V_15 -> V_247 [ V_249 ] = F_23 (
V_15 , V_240
) ;
}
}
V_71 = 0x03 ;
F_20 ( V_15 , V_252 , V_71 ) ;
F_21 ( V_15 , V_240 , 0xffff ) ;
F_63 ( & V_15 -> V_250 , V_141 ) ;
for ( V_249 = 0 ; V_249 < F_51 ( V_15 -> V_247 ) ; V_249 ++ ) {
V_247 [ V_249 ] = V_15 -> V_247 [ V_249 ] ;
if ( V_247 [ V_249 ] == 0xffff )
V_247 [ V_249 ] = - 1 ;
}
F_34 ( V_15 -> V_27 -> V_28 , L_44 ,
V_247 [ 0 ] , V_247 [ 1 ] , V_247 [ 2 ] , V_247 [ 3 ] , * V_248 ) ;
return 0 ;
}
static int
F_92 ( struct V_14 * V_15 , int V_28 )
{
struct V_241 * V_254 ;
V_15 -> V_241 = V_254 = F_93 () ;
if ( ! V_254 ) {
F_38 ( V_15 -> V_27 -> V_28 , L_45 ) ;
return - V_255 ;
}
F_94 ( V_254 , L_46 ) ;
F_95 ( V_254 , L_47 , F_96 ( V_15 -> V_86 ) ) ;
F_97 ( V_254 , & V_15 -> V_86 -> V_28 ) ;
V_254 -> V_256 = V_15 -> V_17 ;
F_98 ( V_254 , V_15 ) ;
V_254 -> V_257 = F_88 ;
V_254 -> V_258 = F_90 ;
V_254 -> V_259 = 16 ;
V_254 -> V_260 = F_91 ;
F_84 ( V_15 , 0 ) ;
F_85 ( V_15 ,
V_246 ) ;
F_86 ( V_15 , 0 ) ;
F_99 ( V_15 -> V_241 ) ;
return 0 ;
}
static void
F_100 ( struct V_14 * V_15 )
{
if ( V_15 -> V_241 ) {
F_101 ( V_15 -> V_241 ) ;
V_15 -> V_241 = NULL ;
}
F_83 ( V_15 , 0 ) ;
}
static inline int
F_92 ( struct V_14 * V_15 , int V_28 ) { return - V_261 ; }
static inline void
F_100 ( struct V_14 * V_15 ) { }
static inline void
F_87 ( struct V_14 * V_15 )
{
F_31 ( V_15 -> V_27 -> V_28 , L_48 ) ;
}
static inline void
F_102 ( struct V_14 * V_15 , T_1 V_262 )
{
F_34 ( V_15 -> V_27 -> V_28 ,
L_49 ,
V_262 ) ;
}
static inline void
F_103 ( struct V_14 * V_15 ,
const struct V_6 * V_263 ,
T_1 V_264
)
{
T_1 V_262 ;
enum V_189 V_190 ;
const struct V_6 * V_7 = V_263 ;
for ( V_190 = V_199 ;
V_190 <= V_198 ;
++ V_190 , ++ V_7 ) {
if ( ! ( V_264 & ( 1 << V_190 ) ) )
continue;
F_74 ( V_7 -> V_174 ) ;
V_262 = F_5 ( V_7 , V_225 ) ;
F_4 ( V_7 , V_225 , V_262 ) ;
F_75 ( V_7 -> V_174 ) ;
if ( V_7 -> V_134 ) {
F_104 ( V_7 -> V_134 ) ;
F_34 ( V_15 -> V_27 -> V_28 , L_50 ,
V_7 -> V_194 ,
V_262 ,
F_13 (
V_7 , V_232 ) ) ;
} else
F_31 ( V_15 -> V_27 -> V_28 , L_51 ) ;
if ( V_262 & V_265 )
F_102 ( V_15 , V_262 ) ;
}
}
static T_5
F_105 ( int V_266 , void * V_267 )
{
struct V_14 * V_15 = V_267 ;
T_1 V_264 ;
static unsigned long V_268 ;
V_264 = F_16 ( V_15 , V_269 ) ;
if ( ! ( V_264 &
( V_270 | V_271 | V_272
| V_273 | V_274 | V_275 )
) )
return V_276 ;
F_34 ( V_15 -> V_27 -> V_28 ,
L_52 ,
V_268 ++ ,
V_264 ) ;
if ( V_264 & V_275 ) {
if ( V_15 -> V_277 )
F_106 ( V_15 -> V_277 , V_15 -> V_277 -> V_278 ) ;
F_74 ( & V_15 -> V_250 ) ;
F_15 ( V_15 , V_279 + 3 , 0x07 ) ;
F_75 ( & V_15 -> V_250 ) ;
F_34 ( V_15 -> V_27 -> V_28 , L_53 ) ;
}
if ( V_264 & ( V_270 | V_271 | V_272 ) )
F_103 ( V_15 , V_15 -> V_191 , V_264 ) ;
if ( V_264 & V_273 )
F_87 ( V_15 ) ;
if ( V_264 & V_274 ) {
F_107 ( V_266 , V_15 -> V_280 -> V_62 ) ;
F_34 ( V_15 -> V_27 -> V_28 , L_54 ) ;
}
return V_281 ;
}
static int
F_108 ( struct V_133 * V_134 ,
enum V_189 V_190
)
{
struct V_14 * V_15 = F_72 ( V_134 ) ;
struct V_212 * V_213 = V_134 -> V_213 ;
struct V_6 * V_7 = & V_15 -> V_191 [ V_190 ] ;
V_7 -> V_134 = V_134 ;
V_213 -> V_282 = V_283 ;
F_109 ( V_213 , 0 , V_284 ,
& V_285 ) ;
V_213 -> V_62 = V_7 ;
return 0 ;
}
static int
F_110 ( struct V_133 * V_134 )
{
return F_108 ( V_134 , V_199 ) ;
}
static int
F_111 ( struct V_133 * V_134 )
{
return F_108 ( V_134 , V_176 ) ;
}
static int
F_112 ( struct V_133 * V_134 )
{
return F_108 ( V_134 , V_198 ) ;
}
static int
F_113 ( struct V_133 * V_134
)
{
struct V_6 * V_7 =
V_134 -> V_213 -> V_62 ;
V_7 -> V_134 = NULL ;
return 0 ;
}
static int
F_114 ( struct V_14 * V_15 )
{
enum { V_286 , V_287 , V_288 };
struct V_289 * V_233 ;
int V_129 ;
V_129 = F_115 ( V_15 -> V_27 , L_55 , V_286 ,
1 , 1 , & V_233 ) ;
if ( V_129 < 0 )
return V_129 ;
F_116 ( V_233 , V_290 ,
& V_291 ) ;
F_116 ( V_233 , V_292 ,
& V_293 ) ;
V_233 -> V_62 = V_15 ;
V_233 -> V_294 = 0 ;
strcpy ( V_233 -> V_194 , V_15 -> V_27 -> V_295 ) ;
V_15 -> V_233 [ V_199 ] = V_233 ;
V_15 -> V_233 [ V_176 ] = V_233 ;
F_117 ( V_233 , V_296 ,
F_118 ( V_15 -> V_86 ) ,
64 * 1024 , 64 * 1024 ) ;
V_129 = F_115 ( V_15 -> V_27 , L_56 , V_287 ,
1 , 0 , & V_233 ) ;
if ( V_129 < 0 )
return V_129 ;
F_116 ( V_233 , V_290 ,
& V_297 ) ;
V_233 -> V_62 = V_15 ;
V_233 -> V_294 = 0 ;
strcpy ( V_233 -> V_194 , V_15 -> V_27 -> V_295 ) ;
V_15 -> V_233 [ V_198 ] = V_233 ;
F_117 ( V_233 , V_296 ,
F_118 ( V_15 -> V_86 ) ,
64 * 1024 , 64 * 1024 ) ;
return 0 ;
}
static int
F_119 ( struct V_298 * V_277 )
{
struct V_14 * V_15 ;
unsigned long V_141 ;
unsigned int V_90 ;
V_15 = F_120 ( V_277 ) ;
V_90 = ( ( V_277 -> V_278 * V_299 ) - 1 ) & V_300 ;
if ( V_90 < 49 ) {
F_34 ( V_15 -> V_27 -> V_28 , L_57 , V_90 ) ;
V_90 = 49 ;
}
F_34 ( V_15 -> V_27 -> V_28 , L_58 , V_90 ) ;
V_90 |= V_301 | V_302 ;
F_62 ( & V_15 -> V_250 , V_141 ) ;
F_19 ( V_15 , V_279 , V_90 ) ;
F_63 ( & V_15 -> V_250 , V_141 ) ;
return 0 ;
}
static int
F_121 ( struct V_298 * V_277 )
{
struct V_14 * V_15 ;
unsigned long V_141 ;
V_15 = F_120 ( V_277 ) ;
F_62 ( & V_15 -> V_250 , V_141 ) ;
F_15 ( V_15 , V_279 + 3 , 0x04 ) ;
F_63 ( & V_15 -> V_250 , V_141 ) ;
return 0 ;
}
static int
F_122 ( struct V_298 * V_277 ,
unsigned long * V_303 , unsigned long * V_304 )
{
* V_303 = 1 ;
* V_304 = 1024000 / V_299 ;
return 0 ;
}
static int
F_123 ( struct V_14 * V_15 , int V_305 )
{
struct V_298 * V_277 = NULL ;
struct V_306 V_307 ;
int V_129 ;
V_307 . V_308 = V_309 ;
V_307 . V_310 = V_311 ;
V_307 . V_27 = V_15 -> V_27 -> V_312 ;
V_307 . V_305 = V_305 ;
V_307 . V_313 = 0 ;
V_314 . V_315 *= V_299 ;
V_314 . V_316 /= V_299 ;
V_129 = F_124 ( V_15 -> V_27 , L_59 , & V_307 , & V_277 ) ;
if ( V_129 < 0 )
goto V_317;
strcpy ( V_277 -> V_194 , L_60 ) ;
V_277 -> V_62 = V_15 ;
V_277 -> V_282 = V_314 ;
V_15 -> V_277 = V_277 ;
F_121 ( V_277 ) ;
V_129 = 0 ;
V_317:
return V_129 ;
}
static int
F_125 ( struct V_14 * V_15 )
{
if ( V_15 -> V_266 < 0 )
goto V_318;
F_29 ( V_15 ) ;
F_121 ( V_15 -> V_277 ) ;
F_100 ( V_15 ) ;
V_318:
if ( V_15 -> V_266 >= 0 )
F_126 ( V_15 -> V_266 , V_15 ) ;
F_127 ( V_15 -> V_86 ) ;
F_128 ( V_15 -> V_86 ) ;
F_129 ( V_15 ) ;
return 0 ;
}
static int
F_130 ( struct V_319 * V_305 )
{
struct V_14 * V_15 = V_305 -> V_320 ;
return F_125 ( V_15 ) ;
}
static inline void
F_131 ( const struct V_14 * V_15 )
{
T_2 V_321 ;
F_34 ( V_15 -> V_27 -> V_28 ,
L_61
L_62 ,
V_15 -> V_16 , V_15 -> V_17 , V_15 -> V_322 ,
V_15 -> V_323 , V_15 -> V_18 , V_15 -> V_266 ) ;
F_34 ( V_15 -> V_27 -> V_28 ,
L_63 ,
F_22 ( V_15 , 0 ) ,
F_22 ( V_15 , 1 ) ,
F_22 ( V_15 , 2 ) ,
F_22 ( V_15 , 3 ) ,
F_22 ( V_15 , 4 ) ,
F_22 ( V_15 , 5 ) ) ;
for ( V_321 = 0 ; V_321 < 0x07 ; V_321 += 1 )
F_34 ( V_15 -> V_27 -> V_28 ,
L_64 , F_2 ( V_15 -> V_322 + V_321 ) ) ;
for ( V_321 = 0 ; V_321 <= 0x07 ; V_321 += 1 )
F_34 ( V_15 -> V_27 -> V_28 ,
L_65 ,
V_321 , F_2 ( 0x200 + V_321 ) , F_2 ( 0x208 + V_321 ) ) ;
for ( V_321 = 0 ; V_321 <= 0x01 ; V_321 += 1 )
F_34 ( V_15 -> V_27 -> V_28 ,
L_66
L_67 ,
V_321 ,
F_2 ( 0x300 + V_321 ) ,
F_2 ( 0x310 + V_321 ) ,
F_2 ( 0x320 + V_321 ) ,
F_2 ( 0x330 + V_321 ) ,
F_2 ( 0x388 + V_321 ) ,
F_2 ( 0x38c + V_321 ) ) ;
for ( V_321 = 0 ; V_321 < V_324 ; V_321 += 2 )
F_34 ( V_15 -> V_27 -> V_28 ,
L_68 ,
V_321 , F_17 ( V_15 , V_321 ) ) ;
for ( V_321 = 0 ; V_321 < V_325 ; V_321 += 2 )
F_34 ( V_15 -> V_27 -> V_28 ,
L_69 ,
V_321 , F_25 ( V_15 , V_321 ) ) ;
}
static int
F_132 ( struct V_125 * V_27 ,
struct V_326 * V_86 ,
unsigned long V_327 ,
struct V_14 * * V_328 )
{
struct V_14 * V_15 ;
int V_129 ;
static struct V_329 V_78 = {
. V_330 = F_130 ,
} ;
T_1 V_331 ;
enum V_189 V_190 ;
struct V_6 * V_332 ;
* V_328 = NULL ;
V_129 = F_133 ( V_86 ) ;
if ( V_129 < 0 )
return V_129 ;
V_15 = F_134 ( sizeof( * V_15 ) , V_333 ) ;
if ( V_15 == NULL ) {
V_129 = - V_255 ;
goto V_334;
}
F_135 ( & V_15 -> V_250 ) ;
V_15 -> V_27 = V_27 ;
V_15 -> V_86 = V_86 ;
V_15 -> V_266 = - 1 ;
if ( F_136 ( & V_86 -> V_28 , F_137 ( 24 ) ) < 0 ||
F_138 ( & V_86 -> V_28 , F_137 ( 24 ) ) < 0 ) {
F_38 ( V_27 -> V_28 ,
L_70
) ;
V_129 = - V_335 ;
goto V_334;
}
V_129 = F_139 ( V_86 , L_71 ) ;
if ( V_129 < 0 )
goto V_334;
V_15 -> V_16 = F_140 ( V_86 , 0 ) ;
V_15 -> V_17 = F_140 ( V_86 , 1 ) ;
V_15 -> V_322 = F_140 ( V_86 , 2 ) ;
V_15 -> V_323 = F_140 ( V_86 , 3 ) ;
V_15 -> V_18 = F_140 ( V_86 , 4 ) ;
V_332 = & V_15 -> V_191 [ V_199 ] ;
V_332 -> V_9 = V_15 -> V_16 + V_336 ;
V_332 -> V_174 = & V_15 -> V_250 ;
V_332 -> type = V_199 ;
V_332 -> V_194 = L_72 ;
V_332 = & V_15 -> V_191 [ V_176 ] ;
V_332 -> V_9 = V_15 -> V_16 + V_337 ;
V_332 -> V_174 = & V_15 -> V_250 ;
V_332 -> type = V_176 ;
V_332 -> V_194 = L_73 ;
V_332 = & V_15 -> V_191 [ V_198 ] ;
V_332 -> V_9 = V_15 -> V_16 + V_338 ;
V_332 -> V_174 = & V_15 -> V_250 ;
V_332 -> type = V_198 ;
V_332 -> V_194 = L_74 ;
if ( F_141 ( V_86 -> V_266 , F_105 ,
V_339 , V_340 , V_15 ) ) {
F_38 ( V_27 -> V_28 , L_75 , V_86 -> V_266 ) ;
V_129 = - V_341 ;
goto V_334;
}
V_15 -> V_266 = V_86 -> V_266 ;
F_142 ( V_86 ) ;
F_143 ( V_15 -> V_266 ) ;
F_131 ( V_15 ) ;
V_129 = F_144 ( V_27 , V_342 , V_15 , & V_78 ) ;
if ( V_129 < 0 )
goto V_334;
V_129 = F_36 ( V_15 ) ;
if ( V_129 < 0 )
goto V_334;
V_331 = V_179 | V_181 | V_182 ;
for ( V_190 = V_199 ;
V_190 <= V_198 ; ++ V_190 ) {
struct V_6 * V_7 =
& V_15 -> V_191 [ V_190 ] ;
V_7 -> V_193 = 1 ;
F_67 ( V_15 , V_190 , 0 ) ;
F_145 ( V_7 -> V_174 ) ;
F_4 ( V_7 , V_177 ,
V_331 ) ;
F_146 ( V_7 -> V_174 ) ;
}
* V_328 = V_15 ;
V_129 = 0 ;
goto V_317;
V_334:
if ( V_15 )
F_125 ( V_15 ) ;
F_128 ( V_86 ) ;
V_317:
return V_129 ;
}
static int
F_147 ( struct V_326 * V_86 , const struct V_343 * V_344 )
{
static int V_28 ;
struct V_125 * V_27 ;
struct V_14 * V_15 ;
struct V_345 * V_346 ;
int V_129 ;
if ( V_28 >= V_347 ) {
V_129 = - V_348 ;
goto V_317;
}
if ( ! V_184 [ V_28 ] ) {
V_28 ++ ;
V_129 = - V_349 ;
goto V_317;
}
V_129 = F_148 ( & V_86 -> V_28 , V_350 [ V_28 ] , V_351 [ V_28 ] , V_352 ,
0 , & V_27 ) ;
if ( V_129 < 0 )
goto V_317;
strcpy ( V_27 -> V_353 , L_59 ) ;
strcpy ( V_27 -> V_295 , L_76 ) ;
V_129 = F_132 ( V_27 , V_86 , V_344 -> V_354 , & V_15 ) ;
if ( V_129 < 0 )
goto V_334;
V_27 -> V_62 = V_15 ;
V_129 = F_149 (
V_27 , 0 ,
V_355 , V_15 -> V_322 ,
V_356 | V_357 ,
- 1 , & V_15 -> V_280
) ;
if ( V_129 < 0 ) {
F_38 ( V_27 -> V_28 , L_77 ,
V_15 -> V_322
) ;
goto V_334;
}
V_129 = F_123 ( V_15 , 0 ) ;
if ( V_129 < 0 )
goto V_334;
V_129 = F_114 ( V_15 ) ;
if ( V_129 < 0 )
goto V_334;
if ( F_150 ( V_27 , V_15 -> V_323 , V_15 -> V_323 + 2 ,
V_358 , 1 , & V_346 ) < 0 ) {
F_38 ( V_27 -> V_28 , L_78 ,
V_15 -> V_323 , V_15 -> V_323 + 2
) ;
} else {
V_129 = F_151 ( V_346 , 1 , 2 ) ;
if ( V_129 < 0 )
goto V_334;
V_129 = F_152 ( V_346 , 0 , 1 , NULL ) ;
if ( V_129 < 0 )
goto V_334;
V_346 -> V_62 = V_15 ;
}
sprintf ( V_27 -> V_359 , L_79 ,
V_27 -> V_295 , V_15 -> V_16 , V_15 -> V_266 ) ;
V_129 = F_153 ( V_27 ) ;
if ( V_129 < 0 )
goto V_334;
#ifdef F_154
F_155 ( V_27 -> V_28 ,
L_80 ) ;
F_155 ( V_27 -> V_28 ,
L_81 ) ;
F_155 ( V_27 -> V_28 ,
L_82 ) ;
F_155 ( V_27 -> V_28 ,
L_83 ,
1024000 / V_299 , V_299 ) ;
#endif
F_92 ( V_15 , V_28 ) ;
F_156 ( V_86 , V_27 ) ;
V_28 ++ ;
V_129 = 0 ;
goto V_317;
V_334:
F_38 ( V_27 -> V_28 , L_84 ) ;
F_157 ( V_27 ) ;
V_317:
return V_129 ;
}
static void
F_158 ( struct V_326 * V_86 )
{
F_157 ( F_159 ( V_86 ) ) ;
}
static inline void
F_160 ( const struct V_14 * V_15 ,
unsigned long V_360 , unsigned V_11 , T_3 * V_361 )
{
unsigned V_1 ;
for ( V_1 = 0 ; V_1 < V_11 ; ++ V_1 ) {
* V_361 = F_14 ( V_360 ) ;
F_34 ( V_15 -> V_27 -> V_28 , L_85 ,
V_360 , * V_361 ) ;
++ V_361 ;
V_360 += sizeof( * V_361 ) ;
}
}
static inline void
F_161 ( const struct V_14 * V_15 ,
const T_3 * V_361 ,
unsigned long V_360 ,
unsigned V_11
)
{
unsigned V_1 ;
for ( V_1 = 0 ; V_1 < V_11 ; ++ V_1 ) {
F_11 ( * V_361 , V_360 ) ;
F_34 ( V_15 -> V_27 -> V_28 ,
L_86 ,
V_360 , * V_361 , F_14 ( V_360 ) ) ;
++ V_361 ;
V_360 += sizeof( * V_361 ) ;
}
}
static inline void
F_162 ( struct V_14 * V_15 )
{
#ifdef F_163
F_164 ( V_15 -> V_60 ) ;
#else
F_160 ( V_15 , V_15 -> V_18 ,
F_51 ( V_15 -> V_362 ) , V_15 -> V_362 ) ;
F_27 ( V_15 , 1 ) ;
F_28 ( V_15 , 1 ) ;
#endif
}
static inline void
F_165 ( const struct V_14 * V_15 )
{
#ifdef F_163
F_166 ( V_15 -> V_60 ) ;
#else
F_161 ( V_15 , V_15 -> V_362 , V_15 -> V_18 ,
F_51 ( V_15 -> V_362 ) ) ;
F_7 ( ( ( T_2 * ) V_15 -> V_362 ) [ 1 ] , V_15 -> V_18 + 2 ) ;
#endif
}
static int
F_167 ( struct V_305 * V_28 )
{
struct V_125 * V_27 = F_168 ( V_28 ) ;
struct V_14 * V_15 = V_27 -> V_62 ;
T_2 * V_363 ;
F_169 ( V_27 , V_364 ) ;
F_170 ( V_15 -> V_233 [ V_199 ] ) ;
F_170 ( V_15 -> V_233 [ V_198 ] ) ;
F_162 ( V_15 ) ;
F_160 ( V_15 , V_15 -> V_16 ,
F_51 ( V_15 -> V_365 ) , V_15 -> V_365 ) ;
V_363 = ( T_2 * ) V_15 -> V_365 ;
V_363 [ V_187 / 2 ] = V_15 -> V_186 ;
F_160 ( V_15 , V_15 -> V_17 ,
F_51 ( V_15 -> V_366 ) , V_15 -> V_366 ) ;
F_160 ( V_15 , V_15 -> V_322 ,
F_51 ( V_15 -> V_367 ) , V_15 -> V_367 ) ;
F_160 ( V_15 , V_15 -> V_323 ,
F_51 ( V_15 -> V_368 ) , V_15 -> V_368 ) ;
return 0 ;
}
static int
F_171 ( struct V_305 * V_28 )
{
struct V_125 * V_27 = F_168 ( V_28 ) ;
const struct V_14 * V_15 = V_27 -> V_62 ;
F_161 ( V_15 , V_15 -> V_366 , V_15 -> V_17 ,
F_51 ( V_15 -> V_366 ) ) ;
F_161 ( V_15 , V_15 -> V_367 , V_15 -> V_322 ,
F_51 ( V_15 -> V_367 ) ) ;
F_161 ( V_15 , V_15 -> V_368 , V_15 -> V_323 ,
F_51 ( V_15 -> V_368 ) ) ;
F_165 ( V_15 ) ;
F_161 ( V_15 , V_15 -> V_365 , V_15 -> V_16 ,
F_51 ( V_15 -> V_365 ) ) ;
F_169 ( V_27 , V_369 ) ;
return 0 ;
}
