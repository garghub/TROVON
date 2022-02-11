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
V_107 -> type = V_122 ;
V_107 -> V_11 = ( V_1 . V_1 == V_43 ) ? 2 : 1 ;
V_107 -> V_8 . V_123 . V_124 = V_1 . V_103 ;
if ( V_107 -> V_8 . V_123 . V_125 > V_1 . V_103 - 1U )
V_107 -> V_8 . V_123 . V_125 = V_1 . V_103 - 1U ;
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
} else
if ( V_1 . V_1 == V_43 )
V_121 = V_119 ;
strcpy ( V_107 -> V_8 . V_123 . V_126 , V_121 [ V_107 -> V_8 . V_123 . V_125 ] ) ;
return 0 ;
}
static int
F_47 ( struct V_104 * V_105 ,
struct V_113 * V_114 )
{
struct V_14 * V_15 = F_44 ( V_105 ) ;
struct V_97 V_1 ;
unsigned short V_71 ;
F_41 ( & V_1 , V_105 -> V_108 ) ;
V_71 = F_25 ( V_15 , V_1 . V_1 ) ;
if ( V_1 . V_1 == V_43 ) {
V_114 -> V_8 . V_123 . V_125 [ 0 ] = ( V_71 >> 8 ) & ( V_1 . V_103 - 1 ) ;
V_114 -> V_8 . V_123 . V_125 [ 1 ] = ( V_71 >> 0 ) & ( V_1 . V_103 - 1 ) ;
} else
V_114 -> V_8 . V_123 . V_125 [ 0 ] = ( V_71 >> V_1 . V_99 ) & ( V_1 . V_103 - 1 ) ;
F_34 ( V_15 -> V_27 -> V_28 ,
L_21 ,
V_1 . V_1 , V_71 , V_114 -> V_8 . V_123 . V_125 [ 0 ] , V_114 -> V_8 . V_123 . V_125 [ 1 ] ,
V_1 . V_99 , V_1 . V_103 ) ;
return 0 ;
}
static int
F_48 ( struct V_104 * V_105 ,
struct V_113 * V_114 )
{
struct V_14 * V_15 = F_44 ( V_105 ) ;
struct V_97 V_1 ;
T_2 V_115 , V_116 , V_71 ;
F_41 ( & V_1 , V_105 -> V_108 ) ;
V_115 = F_25 ( V_15 , V_1 . V_1 ) ;
V_71 = V_115 ;
if ( V_1 . V_1 == V_43 ) {
if ( V_114 -> V_8 . V_123 . V_125 [ 0 ] > V_1 . V_103 - 1U ||
V_114 -> V_8 . V_123 . V_125 [ 1 ] > V_1 . V_103 - 1U )
return - V_127 ;
V_71 = ( V_114 -> V_8 . V_123 . V_125 [ 0 ] << 8 ) |
( V_114 -> V_8 . V_123 . V_125 [ 1 ] << 0 ) ;
} else {
if ( V_114 -> V_8 . V_123 . V_125 [ 0 ] > V_1 . V_103 - 1U )
return - V_127 ;
V_71 &= ~ ( ( V_1 . V_103 - 1 ) << V_1 . V_99 ) ;
V_71 |= ( V_114 -> V_8 . V_123 . V_125 [ 0 ] << V_1 . V_99 ) ;
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
struct V_128 * V_27 ;
const struct V_129 * V_130 ;
unsigned int V_131 ;
int V_132 ;
if ( F_49 ( ! V_15 || ! V_15 -> V_27 ) )
return - V_127 ;
V_27 = V_15 -> V_27 ;
F_24 ( V_15 , V_25 , 0x0000 ) ;
for ( V_131 = 0 ; V_131 < F_50 ( V_133 ) ; ++ V_131 ) {
F_24 ( V_15 ,
V_133 [ V_131 ] [ 0 ] ,
V_133 [ V_131 ] [ 1 ] ) ;
}
V_130 = V_134 ;
for ( V_131 = 0 ; V_131 < F_50 ( V_134 ) ;
++ V_131 , ++ V_130 ) {
if ( ( V_132 = F_51 ( V_15 -> V_27 , F_52 ( V_130 , V_15 ) ) ) < 0 )
return V_132 ;
}
F_53 ( V_27 , L_23 ) ;
strcpy ( V_27 -> V_135 , L_23 ) ;
return 0 ;
}
static int
F_54 ( struct V_136 * V_137 ,
struct V_138 * V_139 )
{
return F_55 ( V_137 , F_56 ( V_139 ) ) ;
}
static int
F_57 ( struct V_136 * V_137 )
{
F_58 ( V_137 ) ;
return 0 ;
}
static void
F_59 ( struct V_6 * V_7 ,
enum V_140 V_141 ,
unsigned int V_142 ,
unsigned int V_143
)
{
unsigned long V_144 ;
T_2 V_71 = 0xff00 ;
T_1 V_145 = 0 ;
switch ( V_141 ) {
case V_146 : V_145 = V_147 ; break;
case V_148 : V_145 = V_149 ; break;
case V_150 :
V_145 = V_151 ; break;
case V_152 : V_145 = V_153 ; break;
case V_154 : V_145 = V_155 ; break;
case V_156 : V_145 = V_157 ; break;
case V_158 : V_145 = V_159 ; break;
case V_160 : V_145 = V_161 ; break;
case V_162 : V_145 = V_163 ; break;
case V_164 : V_145 = V_165 ; break;
case V_166 : V_145 = V_167 ; break;
default:
F_60 ( V_168 L_24 , V_141 ) ;
case V_169 : V_145 = V_170 ; break;
case V_171 : V_145 = V_172 ; break;
case V_173 : V_145 = V_174 ; break;
}
V_71 |= V_145 ;
if ( V_143 == 2 )
V_71 |= V_175 ;
if ( V_142 == 16 )
V_71 |= V_176 ;
F_61 ( V_7 -> V_177 , V_144 ) ;
F_6 ( V_7 , V_178 , V_71 ) ;
if ( V_7 -> type != V_179 )
F_6 ( V_7 , V_180 ,
F_8 ( V_7 , V_180 ) |
V_181 |
V_182 |
V_183 |
V_184 |
V_185
) ;
F_62 ( V_7 -> V_177 , V_144 ) ;
}
static inline void
F_63 ( struct V_6 * V_7
)
{
F_59 ( V_7 , V_146 , 8 , 1 ) ;
}
static void
F_64 ( struct V_14 * V_15 ,
unsigned V_186 ,
bool V_187
)
{
bool V_188 = ! V_187 ;
if ( V_188 )
V_15 -> V_189 |= V_186 ;
else
V_15 -> V_189 &= ~ V_186 ;
F_34 ( V_15 -> V_27 -> V_28 ,
L_25 ,
V_186 , V_188 , V_15 -> V_189 ) ;
F_18 ( V_15 , V_190 , V_15 -> V_189 ) ;
}
static inline void
F_65 ( struct V_14 * V_15 , bool V_187 )
{
F_34 ( V_15 -> V_27 -> V_28 , L_26 , V_187 ) ;
F_64 (
V_15 , V_191 , V_187
) ;
}
static void
F_66 ( struct V_14 * V_15 ,
enum V_192 V_193 ,
bool V_187
)
{
struct V_6 * V_7 = & V_15 -> V_194 [ V_193 ] ;
bool V_195 = ( V_7 -> V_196 != V_187 ) ;
F_34 ( V_15 -> V_27 -> V_28 ,
L_27 ,
V_7 -> V_126 , V_187 , V_195
) ;
if ( V_195 ) {
static const struct {
enum V_192 V_197 ;
enum V_192 V_198 ;
} V_199 [ 3 ] =
{ { V_179 , V_200 } ,
{ V_201 , V_200 } ,
{ V_201 , V_179 } } ;
bool V_202 ;
if ( V_187 )
V_202 = 1 ;
else {
V_202 =
( ( ! V_15 -> V_194 [ V_199 [ V_193 ] . V_197 ]
. V_196 )
&& ( ! V_15 -> V_194 [ V_199 [ V_193 ] . V_198 ]
. V_196 ) ) ;
}
if ( V_202 )
F_65 ( V_15 , V_187 ) ;
if ( ! V_187 )
F_63 ( V_7 ) ;
V_7 -> V_196 = V_187 ;
}
}
static void
F_67 ( struct V_14 * V_15 ,
struct V_6 * V_7 ,
unsigned long V_12 ,
unsigned int V_203 ,
unsigned int V_204
)
{
F_68 ( V_203 & 1 , L_28 ) ;
F_68 ( V_204 != 2 * V_203 ,
L_29 ,
V_204 , V_203 ) ;
if ( ! V_7 -> V_196 ) {
unsigned long V_144 ;
T_3 V_205 ;
struct V_206 {
T_3 V_207 ;
T_3 V_208 ;
T_3 V_209 ;
} V_210 ( ( V_211 ) ) V_212 ;
V_205 = V_204 / 2 ;
V_212 . V_207 = V_12 ;
V_212 . V_208 = V_12 + V_205 ;
F_34 ( V_15 -> V_27 -> V_28 ,
L_30 ,
V_212 . V_207 , V_205 ,
V_212 . V_208 , V_205 ,
V_203 , V_204 ) ;
V_212 . V_209 = ( V_205 << 16 ) | ( V_205 ) ;
F_61 ( V_7 -> V_177 , V_144 ) ;
F_12 (
V_7 , V_213 , & V_212 , 3
) ;
F_62 ( V_7 -> V_177 , V_144 ) ;
}
}
static int
F_69 ( struct V_136 * V_137 )
{
struct V_214 * V_215 = V_137 -> V_215 ;
struct V_6 * V_7 = V_215 -> V_62 ;
#if 0
unsigned int size = snd_pcm_lib_buffer_bytes(substream);
unsigned int count = snd_pcm_lib_period_bytes(substream);
#endif
V_7 -> V_216 = V_215 -> V_217 ;
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
F_70 ( struct V_136 * V_137 , int V_218 )
{
struct V_14 * V_15 = F_71 ( V_137 ) ;
struct V_214 * V_215 = V_137 -> V_215 ;
struct V_6 * V_7 = V_215 -> V_62 ;
int V_219 = 0 ;
T_2 V_220 ;
bool V_221 = false ;
bool V_222 = ( V_201 == V_7 -> type ) ;
switch ( V_218 ) {
case V_223 :
F_34 ( V_15 -> V_27 -> V_28 , L_31 , V_7 -> V_126 ) ;
if ( V_222 ) {
V_221 =
F_28 (
V_15 , 1
) ;
}
F_59 ( V_7 ,
V_215 -> V_224 ,
F_72 ( V_215 -> V_225 ) ,
V_215 -> V_143 ) ;
F_73 ( V_7 -> V_177 ) ;
V_220 = F_8 ( V_7 , V_180 ) ;
V_220 &= ~ V_226 ;
F_6 ( V_7 , V_180 , V_220 ) ;
F_6 ( V_7 , V_227 , 0xffff ) ;
F_74 ( V_7 -> V_177 ) ;
F_67 ( V_15 , V_7 , V_215 -> V_217 ,
F_75 ( V_137 ) ,
F_76 ( V_137 )
) ;
F_73 ( V_7 -> V_177 ) ;
#ifdef F_77
V_220 |= V_181 | V_182 ;
F_6 ( V_7 , V_180 , V_220 ) ;
V_220 |= V_226 | V_184 ;
F_6 ( V_7 , V_180 , V_220 ) ;
#else
F_6 ( V_7 , V_180 ,
0x0000 ) ;
F_6 ( V_7 , V_180 ,
V_181 ) ;
F_6 ( V_7 , V_180 ,
V_181 |
V_182 ) ;
F_6 ( V_7 , V_180 ,
V_226 |
V_183 |
V_184 |
V_185 ) ;
#endif
F_74 ( V_7 -> V_177 ) ;
F_66 ( V_15 , V_7 -> type , 1 ) ;
if ( V_222 ) {
if ( ! V_221 )
F_28 (
V_15 , 0
) ;
}
F_34 ( V_15 -> V_27 -> V_28 , L_32 , V_7 -> V_126 ) ;
break;
case V_228 :
F_34 ( V_15 -> V_27 -> V_28 , L_33 , V_7 -> V_126 ) ;
F_73 ( V_7 -> V_177 ) ;
if ( V_7 -> V_196 )
F_6 ( V_7 , V_180 ,
F_8 (
V_7 , V_180
) | V_226
) ;
F_74 ( V_7 -> V_177 ) ;
break;
case V_229 :
F_34 ( V_15 -> V_27 -> V_28 , L_34 , V_7 -> V_126 ) ;
if ( V_222 ) {
V_221 =
F_28 (
V_15 , 1
) ;
}
F_73 ( V_7 -> V_177 ) ;
V_220 = F_8 ( V_7 , V_180 ) ;
V_220 &= ~ V_226 ;
F_6 ( V_7 , V_180 , V_220 ) ;
V_220 |= V_181 ;
F_6 ( V_7 , V_180 , V_220 ) ;
V_220 &= ~ V_181 ;
F_6 ( V_7 , V_180 , V_220 ) ;
F_74 ( V_7 -> V_177 ) ;
F_66 ( V_15 , V_7 -> type , 0 ) ;
if ( V_222 ) {
if ( ! V_221 )
F_28 (
V_15 , 0
) ;
}
F_34 ( V_15 -> V_27 -> V_28 , L_35 , V_7 -> V_126 ) ;
break;
case V_230 :
F_34 ( V_15 -> V_27 -> V_28 , L_36 , V_7 -> V_126 ) ;
F_6 ( V_7 , V_180 ,
F_8 (
V_7 , V_180
) & ~ V_226
) ;
break;
case V_231 :
F_78 ( 1 , L_37 ) ;
break;
case V_232 :
F_78 ( 1 , L_38 ) ;
break;
default:
F_78 ( 1 , L_39 ) ;
return - V_127 ;
}
return V_219 ;
}
static T_4
F_79 ( struct V_136 * V_137
)
{
const struct V_6 * V_7 =
V_137 -> V_215 -> V_62 ;
unsigned long V_219 ;
T_4 V_233 ;
V_219 = F_13 ( V_7 , V_234 ) ;
#ifdef F_80
V_219 -= F_13 ( V_7 , V_213 ) ;
#else
V_219 -= V_7 -> V_216 ;
#endif
V_233 = F_81 ( V_137 -> V_215 , V_219 ) ;
F_34 ( V_137 -> V_235 -> V_27 -> V_28 , L_40 ,
V_236 , V_7 -> V_126 , V_219 , V_233 ) ;
return V_233 ;
}
static inline void
F_82 ( struct V_14 * V_15 ,
bool V_187
)
{
F_1 (
V_15 -> V_17 + V_237 ,
V_238 ,
V_187
) ;
}
static inline void
F_83 ( struct V_14 * V_15 ,
bool V_187
)
{
F_1 (
V_15 -> V_17 + V_237 ,
V_239 ,
V_187
) ;
}
static void
F_84 ( struct V_14 * V_15 ,
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
F_85 ( struct V_14 * V_15 , bool V_187 )
{
F_64 (
V_15 , V_241 , V_187
) ;
}
static inline void
F_86 ( struct V_14 * V_15 )
{
F_34 ( V_15 -> V_27 -> V_28 , L_41 ) ;
F_23 ( V_15 , V_242 ) ;
}
static int
F_87 ( struct V_243 * V_243 , int V_26 )
{
struct V_14 * V_15 = F_88 ( V_243 ) ;
int V_244 ;
F_34 ( V_15 -> V_27 -> V_28 , L_42 , V_26 ) ;
switch ( V_26 ) {
case V_245 :
case V_246 :
V_244 = 0 ;
break;
default:
V_244 = - 1 ;
break;
}
F_84 ( V_15 ,
V_247 ) ;
F_85 ( V_15 , ( V_244 == 0 ) ) ;
return V_244 ;
}
static void
F_89 ( struct V_243 * V_243 )
{
struct V_14 * V_15 = F_88 ( V_243 ) ;
F_34 ( V_15 -> V_27 -> V_28 , L_43 ) ;
F_84 ( V_15 ,
V_248 ) ;
F_85 ( V_15 , 0 ) ;
}
static int
F_90 ( struct V_243 * V_243 ,
int * V_249 ,
int * V_250
)
{
struct V_14 * V_15 = F_88 ( V_243 ) ;
int V_251 ;
T_1 V_71 ;
unsigned long V_144 ;
if ( F_49 ( ! V_15 ) )
return 0 ;
F_61 ( & V_15 -> V_252 , V_144 ) ;
V_71 = F_22 ( V_15 , V_253 ) ;
* V_250 = ( ~ ( V_71 ) >> 4 ) & 0xf ;
V_71 = F_22 ( V_15 , V_254 ) ;
if ( V_71 & V_255 ) {
for ( V_251 = 0 ; V_251 < F_50 ( V_15 -> V_249 ) ; ++ V_251 ) {
V_71 = ( V_251 << 4 ) | 0x0f ;
F_20 ( V_15 , V_254 , V_71 ) ;
V_15 -> V_249 [ V_251 ] = F_23 (
V_15 , V_242
) ;
}
}
V_71 = 0x03 ;
F_20 ( V_15 , V_254 , V_71 ) ;
F_21 ( V_15 , V_242 , 0xffff ) ;
F_62 ( & V_15 -> V_252 , V_144 ) ;
for ( V_251 = 0 ; V_251 < F_50 ( V_15 -> V_249 ) ; V_251 ++ ) {
V_249 [ V_251 ] = V_15 -> V_249 [ V_251 ] ;
if ( V_249 [ V_251 ] == 0xffff )
V_249 [ V_251 ] = - 1 ;
}
F_34 ( V_15 -> V_27 -> V_28 , L_44 ,
V_249 [ 0 ] , V_249 [ 1 ] , V_249 [ 2 ] , V_249 [ 3 ] , * V_250 ) ;
return 0 ;
}
static int
F_91 ( struct V_14 * V_15 , int V_28 )
{
struct V_243 * V_256 ;
V_15 -> V_243 = V_256 = F_92 () ;
if ( ! V_256 ) {
F_38 ( V_15 -> V_27 -> V_28 , L_45 ) ;
return - V_257 ;
}
F_93 ( V_256 , L_46 ) ;
F_94 ( V_256 , L_47 , F_95 ( V_15 -> V_86 ) ) ;
F_96 ( V_256 , & V_15 -> V_86 -> V_28 ) ;
V_256 -> V_258 = V_15 -> V_17 ;
F_97 ( V_256 , V_15 ) ;
V_256 -> V_259 = F_87 ;
V_256 -> V_260 = F_89 ;
V_256 -> V_261 = 16 ;
V_256 -> V_262 = F_90 ;
F_83 ( V_15 , 0 ) ;
F_84 ( V_15 ,
V_248 ) ;
F_85 ( V_15 , 0 ) ;
F_98 ( V_15 -> V_243 ) ;
return 0 ;
}
static void
F_99 ( struct V_14 * V_15 )
{
if ( V_15 -> V_243 ) {
F_100 ( V_15 -> V_243 ) ;
V_15 -> V_243 = NULL ;
}
F_82 ( V_15 , 0 ) ;
}
static inline int
F_91 ( struct V_14 * V_15 , int V_28 ) { return - V_263 ; }
static inline void
F_99 ( struct V_14 * V_15 ) { }
static inline void
F_86 ( struct V_14 * V_15 )
{
F_31 ( V_15 -> V_27 -> V_28 , L_48 ) ;
}
static inline void
F_101 ( struct V_14 * V_15 , T_1 V_264 )
{
F_34 ( V_15 -> V_27 -> V_28 ,
L_49 ,
V_264 ) ;
}
static inline void
F_102 ( struct V_14 * V_15 ,
const struct V_6 * V_265 ,
T_1 V_266
)
{
T_1 V_264 ;
enum V_192 V_193 ;
const struct V_6 * V_7 = V_265 ;
for ( V_193 = V_201 ;
V_193 <= V_200 ;
++ V_193 , ++ V_7 ) {
if ( ! ( V_266 & ( 1 << V_193 ) ) )
continue;
F_73 ( V_7 -> V_177 ) ;
V_264 = F_5 ( V_7 , V_227 ) ;
F_4 ( V_7 , V_227 , V_264 ) ;
F_74 ( V_7 -> V_177 ) ;
if ( V_7 -> V_137 ) {
F_103 ( V_7 -> V_137 ) ;
F_34 ( V_15 -> V_27 -> V_28 , L_50 ,
V_7 -> V_126 ,
V_264 ,
F_13 (
V_7 , V_234 ) ) ;
} else
F_31 ( V_15 -> V_27 -> V_28 , L_51 ) ;
if ( V_264 & V_267 )
F_101 ( V_15 , V_264 ) ;
}
}
static T_5
F_104 ( int V_268 , void * V_269 )
{
struct V_14 * V_15 = V_269 ;
T_1 V_266 ;
static unsigned long V_270 ;
V_266 = F_16 ( V_15 , V_271 ) ;
if ( ! ( V_266 &
( V_272 | V_273 | V_274
| V_275 | V_276 | V_277 )
) )
return V_278 ;
F_34 ( V_15 -> V_27 -> V_28 ,
L_52 ,
V_270 ++ ,
V_266 ) ;
if ( V_266 & V_277 ) {
if ( V_15 -> V_279 )
F_105 ( V_15 -> V_279 , V_15 -> V_279 -> V_280 ) ;
F_73 ( & V_15 -> V_252 ) ;
F_15 ( V_15 , V_281 + 3 , 0x07 ) ;
F_74 ( & V_15 -> V_252 ) ;
F_34 ( V_15 -> V_27 -> V_28 , L_53 ) ;
}
if ( V_266 & ( V_272 | V_273 | V_274 ) )
F_102 ( V_15 , V_15 -> V_194 , V_266 ) ;
if ( V_266 & V_275 )
F_86 ( V_15 ) ;
if ( V_266 & V_276 ) {
F_106 ( V_268 , V_15 -> V_282 -> V_62 ) ;
F_34 ( V_15 -> V_27 -> V_28 , L_54 ) ;
}
return V_283 ;
}
static int
F_107 ( struct V_136 * V_137 ,
enum V_192 V_193
)
{
struct V_14 * V_15 = F_71 ( V_137 ) ;
struct V_214 * V_215 = V_137 -> V_215 ;
struct V_6 * V_7 = & V_15 -> V_194 [ V_193 ] ;
V_7 -> V_137 = V_137 ;
V_215 -> V_284 = V_285 ;
F_108 ( V_215 , 0 , V_286 ,
& V_287 ) ;
V_215 -> V_62 = V_7 ;
return 0 ;
}
static int
F_109 ( struct V_136 * V_137 )
{
return F_107 ( V_137 , V_201 ) ;
}
static int
F_110 ( struct V_136 * V_137 )
{
return F_107 ( V_137 , V_179 ) ;
}
static int
F_111 ( struct V_136 * V_137 )
{
return F_107 ( V_137 , V_200 ) ;
}
static int
F_112 ( struct V_136 * V_137
)
{
struct V_6 * V_7 =
V_137 -> V_215 -> V_62 ;
V_7 -> V_137 = NULL ;
return 0 ;
}
static int
F_113 ( struct V_14 * V_15 )
{
enum { V_288 , V_289 , V_290 };
struct V_291 * V_235 ;
int V_132 ;
V_132 = F_114 ( V_15 -> V_27 , L_55 , V_288 ,
1 , 1 , & V_235 ) ;
if ( V_132 < 0 )
return V_132 ;
F_115 ( V_235 , V_292 ,
& V_293 ) ;
F_115 ( V_235 , V_294 ,
& V_295 ) ;
V_235 -> V_62 = V_15 ;
V_235 -> V_296 = 0 ;
strcpy ( V_235 -> V_126 , V_15 -> V_27 -> V_297 ) ;
V_15 -> V_235 [ V_201 ] = V_235 ;
V_15 -> V_235 [ V_179 ] = V_235 ;
F_116 ( V_235 , V_298 ,
F_117 ( V_15 -> V_86 ) ,
64 * 1024 , 64 * 1024 ) ;
V_132 = F_114 ( V_15 -> V_27 , L_56 , V_289 ,
1 , 0 , & V_235 ) ;
if ( V_132 < 0 )
return V_132 ;
F_115 ( V_235 , V_292 ,
& V_299 ) ;
V_235 -> V_62 = V_15 ;
V_235 -> V_296 = 0 ;
strcpy ( V_235 -> V_126 , V_15 -> V_27 -> V_297 ) ;
V_15 -> V_235 [ V_200 ] = V_235 ;
F_116 ( V_235 , V_298 ,
F_117 ( V_15 -> V_86 ) ,
64 * 1024 , 64 * 1024 ) ;
return 0 ;
}
static int
F_118 ( struct V_300 * V_279 )
{
struct V_14 * V_15 ;
unsigned long V_144 ;
unsigned int V_90 ;
V_15 = F_119 ( V_279 ) ;
V_90 = ( ( V_279 -> V_280 * V_301 ) - 1 ) & V_302 ;
if ( V_90 < 49 ) {
F_34 ( V_15 -> V_27 -> V_28 , L_57 , V_90 ) ;
V_90 = 49 ;
}
F_34 ( V_15 -> V_27 -> V_28 , L_58 , V_90 ) ;
V_90 |= V_303 | V_304 ;
F_61 ( & V_15 -> V_252 , V_144 ) ;
F_19 ( V_15 , V_281 , V_90 ) ;
F_62 ( & V_15 -> V_252 , V_144 ) ;
return 0 ;
}
static int
F_120 ( struct V_300 * V_279 )
{
struct V_14 * V_15 ;
unsigned long V_144 ;
V_15 = F_119 ( V_279 ) ;
F_61 ( & V_15 -> V_252 , V_144 ) ;
F_15 ( V_15 , V_281 + 3 , 0x04 ) ;
F_62 ( & V_15 -> V_252 , V_144 ) ;
return 0 ;
}
static int
F_121 ( struct V_300 * V_279 ,
unsigned long * V_305 , unsigned long * V_306 )
{
* V_305 = 1 ;
* V_306 = 1024000 / V_301 ;
return 0 ;
}
static int
F_122 ( struct V_14 * V_15 , int V_307 )
{
struct V_300 * V_279 = NULL ;
struct V_308 V_309 ;
int V_132 ;
V_309 . V_310 = V_311 ;
V_309 . V_312 = V_313 ;
V_309 . V_27 = V_15 -> V_27 -> V_314 ;
V_309 . V_307 = V_307 ;
V_309 . V_315 = 0 ;
V_316 . V_317 *= V_301 ;
V_316 . V_318 /= V_301 ;
V_132 = F_123 ( V_15 -> V_27 , L_59 , & V_309 , & V_279 ) ;
if ( V_132 < 0 )
goto V_319;
strcpy ( V_279 -> V_126 , L_60 ) ;
V_279 -> V_62 = V_15 ;
V_279 -> V_284 = V_316 ;
V_15 -> V_279 = V_279 ;
F_120 ( V_279 ) ;
V_132 = 0 ;
V_319:
return V_132 ;
}
static int
F_124 ( struct V_14 * V_15 )
{
if ( V_15 -> V_268 < 0 )
goto V_320;
F_29 ( V_15 ) ;
F_120 ( V_15 -> V_279 ) ;
F_99 ( V_15 ) ;
if ( V_15 -> V_268 >= 0 )
F_125 ( V_15 -> V_268 ) ;
V_320:
if ( V_15 -> V_268 >= 0 )
F_126 ( V_15 -> V_268 , V_15 ) ;
F_127 ( V_15 -> V_86 ) ;
F_128 ( V_15 -> V_86 ) ;
F_129 ( V_15 ) ;
return 0 ;
}
static int
F_130 ( struct V_321 * V_307 )
{
struct V_14 * V_15 = V_307 -> V_322 ;
return F_124 ( V_15 ) ;
}
static inline void
F_131 ( const struct V_14 * V_15 )
{
T_2 V_323 ;
F_34 ( V_15 -> V_27 -> V_28 ,
L_61
L_62 ,
V_15 -> V_16 , V_15 -> V_17 , V_15 -> V_324 ,
V_15 -> V_325 , V_15 -> V_18 , V_15 -> V_268 ) ;
F_34 ( V_15 -> V_27 -> V_28 ,
L_63 ,
F_22 ( V_15 , 0 ) ,
F_22 ( V_15 , 1 ) ,
F_22 ( V_15 , 2 ) ,
F_22 ( V_15 , 3 ) ,
F_22 ( V_15 , 4 ) ,
F_22 ( V_15 , 5 ) ) ;
for ( V_323 = 0 ; V_323 < 0x07 ; V_323 += 1 )
F_34 ( V_15 -> V_27 -> V_28 ,
L_64 , F_2 ( V_15 -> V_324 + V_323 ) ) ;
for ( V_323 = 0 ; V_323 <= 0x07 ; V_323 += 1 )
F_34 ( V_15 -> V_27 -> V_28 ,
L_65 ,
V_323 , F_2 ( 0x200 + V_323 ) , F_2 ( 0x208 + V_323 ) ) ;
for ( V_323 = 0 ; V_323 <= 0x01 ; V_323 += 1 )
F_34 ( V_15 -> V_27 -> V_28 ,
L_66
L_67 ,
V_323 ,
F_2 ( 0x300 + V_323 ) ,
F_2 ( 0x310 + V_323 ) ,
F_2 ( 0x320 + V_323 ) ,
F_2 ( 0x330 + V_323 ) ,
F_2 ( 0x388 + V_323 ) ,
F_2 ( 0x38c + V_323 ) ) ;
for ( V_323 = 0 ; V_323 < V_326 ; V_323 += 2 )
F_34 ( V_15 -> V_27 -> V_28 ,
L_68 ,
V_323 , F_17 ( V_15 , V_323 ) ) ;
for ( V_323 = 0 ; V_323 < V_327 ; V_323 += 2 )
F_34 ( V_15 -> V_27 -> V_28 ,
L_69 ,
V_323 , F_25 ( V_15 , V_323 ) ) ;
}
static int
F_132 ( struct V_128 * V_27 ,
struct V_328 * V_86 ,
unsigned long V_329 ,
struct V_14 * * V_330 )
{
struct V_14 * V_15 ;
int V_132 ;
static struct V_331 V_78 = {
. V_332 = F_130 ,
} ;
T_1 V_333 ;
enum V_192 V_193 ;
struct V_6 * V_334 ;
* V_330 = NULL ;
V_132 = F_133 ( V_86 ) ;
if ( V_132 < 0 )
return V_132 ;
V_15 = F_134 ( sizeof( * V_15 ) , V_335 ) ;
if ( V_15 == NULL ) {
V_132 = - V_257 ;
goto V_336;
}
F_135 ( & V_15 -> V_252 ) ;
V_15 -> V_27 = V_27 ;
V_15 -> V_86 = V_86 ;
V_15 -> V_268 = - 1 ;
if ( F_136 ( V_86 , F_137 ( 24 ) ) < 0 ||
F_138 ( V_86 , F_137 ( 24 ) ) < 0 ) {
F_38 ( V_27 -> V_28 ,
L_70
) ;
V_132 = - V_337 ;
goto V_336;
}
V_132 = F_139 ( V_86 , L_71 ) ;
if ( V_132 < 0 )
goto V_336;
V_15 -> V_16 = F_140 ( V_86 , 0 ) ;
V_15 -> V_17 = F_140 ( V_86 , 1 ) ;
V_15 -> V_324 = F_140 ( V_86 , 2 ) ;
V_15 -> V_325 = F_140 ( V_86 , 3 ) ;
V_15 -> V_18 = F_140 ( V_86 , 4 ) ;
V_334 = & V_15 -> V_194 [ V_201 ] ;
V_334 -> V_9 = V_15 -> V_16 + V_338 ;
V_334 -> V_177 = & V_15 -> V_252 ;
V_334 -> type = V_201 ;
V_334 -> V_126 = L_72 ;
V_334 = & V_15 -> V_194 [ V_179 ] ;
V_334 -> V_9 = V_15 -> V_16 + V_339 ;
V_334 -> V_177 = & V_15 -> V_252 ;
V_334 -> type = V_179 ;
V_334 -> V_126 = L_73 ;
V_334 = & V_15 -> V_194 [ V_200 ] ;
V_334 -> V_9 = V_15 -> V_16 + V_340 ;
V_334 -> V_177 = & V_15 -> V_252 ;
V_334 -> type = V_200 ;
V_334 -> V_126 = L_74 ;
if ( F_141 ( V_86 -> V_268 , F_104 ,
V_341 , V_342 , V_15 ) ) {
F_38 ( V_27 -> V_28 , L_75 , V_86 -> V_268 ) ;
V_132 = - V_343 ;
goto V_336;
}
V_15 -> V_268 = V_86 -> V_268 ;
F_142 ( V_86 ) ;
F_125 ( V_15 -> V_268 ) ;
F_131 ( V_15 ) ;
V_132 = F_143 ( V_27 , V_344 , V_15 , & V_78 ) ;
if ( V_132 < 0 )
goto V_336;
V_132 = F_36 ( V_15 ) ;
if ( V_132 < 0 )
goto V_336;
V_333 = V_182 | V_184 | V_185 ;
for ( V_193 = V_201 ;
V_193 <= V_200 ; ++ V_193 ) {
struct V_6 * V_7 =
& V_15 -> V_194 [ V_193 ] ;
V_7 -> V_196 = 1 ;
F_66 ( V_15 , V_193 , 0 ) ;
F_144 ( V_7 -> V_177 ) ;
F_4 ( V_7 , V_180 ,
V_333 ) ;
F_145 ( V_7 -> V_177 ) ;
}
* V_330 = V_15 ;
V_132 = 0 ;
goto V_319;
V_336:
if ( V_15 )
F_124 ( V_15 ) ;
F_128 ( V_86 ) ;
V_319:
return V_132 ;
}
static int
F_146 ( struct V_328 * V_86 , const struct V_345 * V_346 )
{
static int V_28 ;
struct V_128 * V_27 ;
struct V_14 * V_15 ;
struct V_347 * V_348 ;
int V_132 ;
if ( V_28 >= V_349 ) {
V_132 = - V_350 ;
goto V_319;
}
if ( ! V_187 [ V_28 ] ) {
V_28 ++ ;
V_132 = - V_351 ;
goto V_319;
}
V_132 = F_147 ( & V_86 -> V_28 , V_352 [ V_28 ] , V_353 [ V_28 ] , V_354 ,
0 , & V_27 ) ;
if ( V_132 < 0 )
goto V_319;
strcpy ( V_27 -> V_355 , L_59 ) ;
strcpy ( V_27 -> V_297 , L_76 ) ;
V_132 = F_132 ( V_27 , V_86 , V_346 -> V_356 , & V_15 ) ;
if ( V_132 < 0 )
goto V_336;
V_27 -> V_62 = V_15 ;
V_132 = F_148 (
V_27 , 0 ,
V_357 , V_15 -> V_324 ,
V_358 | V_359 ,
- 1 , & V_15 -> V_282
) ;
if ( V_132 < 0 ) {
F_38 ( V_27 -> V_28 , L_77 ,
V_15 -> V_324
) ;
goto V_336;
}
V_132 = F_122 ( V_15 , 0 ) ;
if ( V_132 < 0 )
goto V_336;
V_132 = F_113 ( V_15 ) ;
if ( V_132 < 0 )
goto V_336;
if ( F_149 ( V_27 , V_15 -> V_325 , V_15 -> V_325 + 2 ,
V_360 , 1 , & V_348 ) < 0 ) {
F_38 ( V_27 -> V_28 , L_78 ,
V_15 -> V_325 , V_15 -> V_325 + 2
) ;
} else {
V_132 = F_150 ( V_348 , 1 , 2 ) ;
if ( V_132 < 0 )
goto V_336;
V_132 = F_151 ( V_348 , 0 , 1 , NULL ) ;
if ( V_132 < 0 )
goto V_336;
V_348 -> V_62 = V_15 ;
}
sprintf ( V_27 -> V_361 , L_79 ,
V_27 -> V_297 , V_15 -> V_16 , V_15 -> V_268 ) ;
V_132 = F_152 ( V_27 ) ;
if ( V_132 < 0 )
goto V_336;
#ifdef F_153
F_154 ( V_27 -> V_28 ,
L_80 ) ;
F_154 ( V_27 -> V_28 ,
L_81 ) ;
F_154 ( V_27 -> V_28 ,
L_82 ) ;
F_154 ( V_27 -> V_28 ,
L_83 ,
1024000 / V_301 , V_301 ) ;
#endif
F_91 ( V_15 , V_28 ) ;
F_155 ( V_86 , V_27 ) ;
V_28 ++ ;
V_132 = 0 ;
goto V_319;
V_336:
F_38 ( V_27 -> V_28 , L_84 ) ;
F_156 ( V_27 ) ;
V_319:
return V_132 ;
}
static void
F_157 ( struct V_328 * V_86 )
{
F_156 ( F_158 ( V_86 ) ) ;
}
static inline void
F_159 ( const struct V_14 * V_15 ,
unsigned long V_362 , unsigned V_11 , T_3 * V_363 )
{
unsigned V_1 ;
for ( V_1 = 0 ; V_1 < V_11 ; ++ V_1 ) {
* V_363 = F_14 ( V_362 ) ;
F_34 ( V_15 -> V_27 -> V_28 , L_85 ,
V_362 , * V_363 ) ;
++ V_363 ;
V_362 += sizeof( * V_363 ) ;
}
}
static inline void
F_160 ( const struct V_14 * V_15 ,
const T_3 * V_363 ,
unsigned long V_362 ,
unsigned V_11
)
{
unsigned V_1 ;
for ( V_1 = 0 ; V_1 < V_11 ; ++ V_1 ) {
F_11 ( * V_363 , V_362 ) ;
F_34 ( V_15 -> V_27 -> V_28 ,
L_86 ,
V_362 , * V_363 , F_14 ( V_362 ) ) ;
++ V_363 ;
V_362 += sizeof( * V_363 ) ;
}
}
static inline void
F_161 ( struct V_14 * V_15 )
{
#ifdef F_162
F_163 ( V_15 -> V_60 ) ;
#else
F_159 ( V_15 , V_15 -> V_18 ,
F_50 ( V_15 -> V_364 ) , V_15 -> V_364 ) ;
F_27 ( V_15 , 1 ) ;
F_28 ( V_15 , 1 ) ;
#endif
}
static inline void
F_164 ( const struct V_14 * V_15 )
{
#ifdef F_162
F_165 ( V_15 -> V_60 ) ;
#else
F_160 ( V_15 , V_15 -> V_364 , V_15 -> V_18 ,
F_50 ( V_15 -> V_364 ) ) ;
F_7 ( ( ( T_2 * ) V_15 -> V_364 ) [ 1 ] , V_15 -> V_18 + 2 ) ;
#endif
}
static int
F_166 ( struct V_307 * V_28 )
{
struct V_328 * V_86 = F_167 ( V_28 ) ;
struct V_128 * V_27 = F_168 ( V_28 ) ;
struct V_14 * V_15 = V_27 -> V_62 ;
T_2 * V_365 ;
F_169 ( V_27 , V_366 ) ;
F_170 ( V_15 -> V_235 [ V_201 ] ) ;
F_170 ( V_15 -> V_235 [ V_200 ] ) ;
F_161 ( V_15 ) ;
F_159 ( V_15 , V_15 -> V_16 ,
F_50 ( V_15 -> V_367 ) , V_15 -> V_367 ) ;
V_365 = ( T_2 * ) V_15 -> V_367 ;
V_365 [ V_190 / 2 ] = V_15 -> V_189 ;
F_159 ( V_15 , V_15 -> V_17 ,
F_50 ( V_15 -> V_368 ) , V_15 -> V_368 ) ;
F_159 ( V_15 , V_15 -> V_324 ,
F_50 ( V_15 -> V_369 ) , V_15 -> V_369 ) ;
F_159 ( V_15 , V_15 -> V_325 ,
F_50 ( V_15 -> V_370 ) , V_15 -> V_370 ) ;
F_128 ( V_86 ) ;
F_171 ( V_86 ) ;
F_172 ( V_86 , V_371 ) ;
return 0 ;
}
static int
F_173 ( struct V_307 * V_28 )
{
struct V_328 * V_86 = F_167 ( V_28 ) ;
struct V_128 * V_27 = F_168 ( V_28 ) ;
const struct V_14 * V_15 = V_27 -> V_62 ;
F_172 ( V_86 , V_372 ) ;
F_174 ( V_86 ) ;
if ( F_133 ( V_86 ) < 0 ) {
F_38 ( V_28 , L_87 ) ;
F_175 ( V_27 ) ;
return - V_373 ;
}
F_142 ( V_86 ) ;
F_160 ( V_15 , V_15 -> V_368 , V_15 -> V_17 ,
F_50 ( V_15 -> V_368 ) ) ;
F_160 ( V_15 , V_15 -> V_369 , V_15 -> V_324 ,
F_50 ( V_15 -> V_369 ) ) ;
F_160 ( V_15 , V_15 -> V_370 , V_15 -> V_325 ,
F_50 ( V_15 -> V_370 ) ) ;
F_164 ( V_15 ) ;
F_160 ( V_15 , V_15 -> V_367 , V_15 -> V_16 ,
F_50 ( V_15 -> V_367 ) ) ;
F_169 ( V_27 , V_374 ) ;
return 0 ;
}
