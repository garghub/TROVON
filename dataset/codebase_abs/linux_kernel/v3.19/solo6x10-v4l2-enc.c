static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
return ( V_3 -> V_4 >> V_2 -> V_5 ) & 1 ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
unsigned long V_6 ;
T_1 V_7 = 1 << V_2 -> V_5 ;
int V_8 = 0 ;
F_3 ( & V_2 -> V_9 , V_6 ) ;
if ( F_4 ( V_3 , V_10 ) & V_7 ) {
F_5 ( V_3 , V_11 , V_7 ) ;
V_8 = 1 ;
}
F_6 ( & V_2 -> V_9 , V_6 ) ;
return V_8 ;
}
static void F_7 ( struct V_1 * V_2 , int V_12 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_13 = 1 << V_2 -> V_5 ;
unsigned long V_6 ;
F_3 ( & V_2 -> V_9 , V_6 ) ;
if ( V_12 )
V_3 -> V_4 |= V_13 ;
else
V_3 -> V_4 &= ~ V_13 ;
F_5 ( V_3 , V_11 , V_13 ) ;
F_5 ( V_3 , V_14 ,
F_8 ( V_3 -> V_4 ) |
( F_9 ( V_3 ) >> 16 ) ) ;
F_6 ( & V_2 -> V_9 , V_6 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
int V_15 ;
unsigned char * V_16 ;
V_2 -> V_17 = ( V_2 -> V_18 & 0x08 ) ? 1 : 0 ;
V_2 -> V_19 = F_11 ( V_3 -> V_20 / V_2 -> V_21 , 1 ) ;
if ( V_2 -> V_18 == V_22 ) {
V_2 -> V_23 = V_3 -> V_24 >> 1 ;
V_2 -> V_25 = V_3 -> V_26 ;
if ( V_3 -> type == V_27 ) {
if ( V_3 -> V_28 == V_29 ) {
V_16 = V_30 ;
V_15 = sizeof( V_30 ) ;
} else {
V_16 = V_31 ;
V_15 = sizeof( V_31 ) ;
}
} else {
if ( V_3 -> V_28 == V_29 ) {
V_16 = V_32 ;
V_15 = sizeof( V_32 ) ;
} else {
V_16 = V_33 ;
V_15 = sizeof( V_33 ) ;
}
}
} else {
V_2 -> V_23 = V_3 -> V_24 ;
V_2 -> V_25 = V_3 -> V_26 << 1 ;
V_2 -> V_19 <<= 2 ;
if ( V_3 -> type == V_27 ) {
if ( V_3 -> V_28 == V_29 ) {
V_16 = V_34 ;
V_15 = sizeof( V_34 ) ;
} else {
V_16 = V_35 ;
V_15 = sizeof( V_35 ) ;
}
} else {
if ( V_3 -> V_28 == V_29 ) {
V_16 = V_36 ;
V_15 = sizeof( V_36 ) ;
} else {
V_16 = V_37 ;
V_15 = sizeof( V_37 ) ;
}
}
}
memcpy ( V_2 -> V_16 , V_16 , V_15 ) ;
if ( V_3 -> type == V_38 ) {
T_2 V_20 = V_3 -> V_20 * 1000 ;
T_2 V_21 = V_2 -> V_21 * 1000 ;
V_16 = V_2 -> V_16 ;
V_16 [ 22 ] = V_20 >> 4 ;
V_16 [ 23 ] = ( ( V_20 << 4 ) & 0xf0 ) | 0x0c
| ( ( V_21 >> 13 ) & 0x3 ) ;
V_16 [ 24 ] = ( V_21 >> 5 ) & 0xff ;
V_16 [ 25 ] = ( ( V_21 << 3 ) & 0xf8 ) | 0x04 ;
}
V_2 -> V_15 = V_15 ;
V_16 = V_2 -> V_39 ;
V_16 [ V_40 + 5 ] = 0xff & ( V_2 -> V_25 >> 8 ) ;
V_16 [ V_40 + 6 ] = 0xff & V_2 -> V_25 ;
V_16 [ V_40 + 7 ] = 0xff & ( V_2 -> V_23 >> 8 ) ;
V_16 [ V_40 + 8 ] = 0xff & V_2 -> V_23 ;
memcpy ( V_16 + V_41 ,
V_42 [ F_12 ( V_3 , V_2 -> V_5 ) ] , V_43 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
T_3 V_5 = V_2 -> V_5 ;
struct V_3 * V_3 = V_2 -> V_3 ;
T_3 V_21 ;
F_10 ( V_2 ) ;
if ( V_2 -> V_19 > V_3 -> V_44 )
return - V_45 ;
V_2 -> V_46 = 0 ;
V_2 -> V_47 = false ;
V_2 -> V_48 = 0 ;
V_3 -> V_44 -= V_2 -> V_19 ;
if ( V_2 -> type == V_49 )
F_5 ( V_3 , F_14 ( V_5 ) , 1 ) ;
F_5 ( V_3 , F_15 ( V_5 ) , 0 ) ;
F_5 ( V_3 , F_16 ( V_5 ) ,
V_2 -> V_17 ? 1 : 0 ) ;
if ( V_2 -> V_17 )
V_21 = V_2 -> V_21 - 1 ;
else
V_21 = V_2 -> V_21 ;
F_5 ( V_3 , F_17 ( V_5 ) , V_2 -> V_50 ) ;
F_5 ( V_3 , F_18 ( V_5 ) , V_2 -> V_51 ) ;
F_5 ( V_3 , F_19 ( V_5 ) , V_21 ) ;
F_5 ( V_3 , F_20 ( V_5 ) , V_2 -> V_50 ) ;
F_5 ( V_3 , F_21 ( V_5 ) , V_2 -> V_51 ) ;
F_5 ( V_3 , F_22 ( V_5 ) , V_21 ) ;
F_5 ( V_3 , F_15 ( V_5 ) , V_2 -> V_18 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
V_3 -> V_44 += V_2 -> V_19 ;
F_5 ( V_3 , F_15 ( V_2 -> V_5 ) , 0 ) ;
F_5 ( V_3 , F_14 ( V_2 -> V_5 ) , 0 ) ;
}
static int F_24 ( struct V_3 * V_3 , T_4 V_52 ,
unsigned int V_53 , unsigned int V_54 )
{
int V_8 ;
if ( V_53 > F_25 ( V_3 ) )
return - V_55 ;
if ( V_53 + V_54 <= F_25 ( V_3 ) ) {
return F_26 ( V_3 , 0 , V_52 ,
F_27 ( V_3 ) + V_53 , V_54 ,
0 , 0 ) ;
}
V_8 = F_26 ( V_3 , 0 , V_52 ,
F_27 ( V_3 ) + V_53 ,
F_25 ( V_3 ) - V_53 , 0 , 0 ) ;
if ( ! V_8 ) {
V_8 = F_26 ( V_3 , 0 ,
V_52 + F_25 ( V_3 ) - V_53 ,
F_27 ( V_3 ) ,
V_54 + V_53 - F_25 ( V_3 ) , 0 , 0 ) ;
}
return V_8 ;
}
static int F_28 ( struct V_1 * V_2 , int V_56 ,
struct V_57 * V_58 , int V_53 , int V_54 ,
unsigned int V_59 , unsigned int V_60 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_61 * V_62 ;
int V_63 ;
int V_8 ;
if ( F_29 ( V_54 > V_64 ) )
return - V_55 ;
V_2 -> V_65 = 1 ;
F_30 (vbuf->sgl, sg, vbuf->nents, i) {
struct V_66 * V_67 ;
T_4 V_52 ;
int V_68 ;
int V_69 = V_60 - V_53 ;
V_67 = & V_2 -> V_70 [ V_2 -> V_65 ++ ] ;
V_52 = F_31 ( V_62 ) ;
V_68 = F_32 ( V_62 ) ;
F_33 ( V_56 >= V_68 ) ;
if ( V_56 ) {
V_68 -= V_56 ;
V_52 += V_56 ;
V_54 -= V_56 ;
V_56 = 0 ;
}
V_68 = F_34 ( V_68 , V_54 ) ;
if ( V_68 <= V_69 ) {
F_35 ( V_67 , 0 , V_52 , V_59 + V_53 ,
V_68 , 0 , 0 ) ;
} else {
V_8 = F_26 ( V_3 , 0 , V_52 , V_59 + V_53 ,
V_69 , 0 , 0 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_26 ( V_3 , 0 , V_52 + V_69 , V_59 ,
V_68 - V_69 , 0 , 0 ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_65 -- ;
}
V_54 -= V_68 ;
if ( V_54 <= 0 )
break;
V_53 += V_68 ;
if ( V_53 >= V_60 )
V_53 -= V_60 ;
if ( V_2 -> V_65 >= ( V_2 -> V_71 - 1 ) ) {
V_8 = F_36 ( V_3 , V_2 -> V_70 ,
V_2 -> V_72 ,
V_2 -> V_65 - 1 ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_65 = 1 ;
}
}
if ( V_2 -> V_65 <= 1 )
return 0 ;
return F_36 ( V_3 , V_2 -> V_70 ,
V_2 -> V_72 , V_2 -> V_65 - 1 ) ;
}
static inline int F_37 ( const T_5 * V_73 )
{
return ( F_38 ( ( * V_73 ) [ 0 ] ) >> 30 ) & 1 ;
}
static inline T_3 F_39 ( const T_5 * V_73 )
{
return ( F_38 ( ( * V_73 ) [ 0 ] ) >> 24 ) & 0x1F ;
}
static inline T_3 F_40 ( const T_5 * V_73 )
{
return ( F_38 ( ( * V_73 ) [ 0 ] ) >> 22 ) & 3 ;
}
static inline T_1 F_41 ( const T_5 * V_73 )
{
return F_38 ( ( * V_73 ) [ 0 ] ) & 0xFFFFF ;
}
static inline T_3 F_42 ( const T_5 * V_73 )
{
return ( F_38 ( ( * V_73 ) [ 1 ] ) >> 8 ) & 0xFF ;
}
static inline T_3 F_43 ( const T_5 * V_73 )
{
return F_38 ( ( * V_73 ) [ 1 ] ) & 0xFF ;
}
static inline T_1 F_44 ( const T_5 * V_73 )
{
return F_38 ( ( * V_73 ) [ 2 ] ) ;
}
static inline T_1 F_45 ( const T_5 * V_73 )
{
return F_38 ( ( * V_73 ) [ 3 ] ) ;
}
static inline T_1 F_46 ( const T_5 * V_73 )
{
return F_38 ( ( * V_73 ) [ 4 ] ) & 0xFFFFF ;
}
static inline T_1 F_47 ( const T_5 * V_73 )
{
return F_38 ( ( * V_73 ) [ 5 ] ) ;
}
static inline T_1 F_48 ( const T_5 * V_73 )
{
return F_38 ( ( * V_73 ) [ 6 ] ) ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_74 * V_75 , const T_5 * V_73 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_57 * V_58 = F_50 ( V_75 , 0 ) ;
int V_76 ;
V_75 -> V_77 . V_6 |= V_78 ;
if ( F_51 ( V_75 , 0 ) < F_46 ( V_73 ) + V_2 -> V_79 )
return - V_80 ;
V_76 = F_52 ( F_46 ( V_73 ) + V_2 -> V_79 , V_81 ) ;
F_53 ( V_75 , 0 , F_46 ( V_73 ) + V_2 -> V_79 ) ;
return F_28 ( V_2 , V_2 -> V_79 , V_58 ,
F_45 ( V_73 ) - F_54 ( V_3 ) ,
V_76 , F_54 ( V_3 ) ,
F_55 ( V_3 ) ) ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_74 * V_75 , const T_5 * V_73 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_57 * V_58 = F_50 ( V_75 , 0 ) ;
int V_82 , V_76 ;
int V_56 = 0 ;
if ( F_51 ( V_75 , 0 ) < F_41 ( V_73 ) )
return - V_80 ;
V_75 -> V_77 . V_6 &= ~ ( V_78 | V_83 |
V_84 ) ;
if ( ! F_40 ( V_73 ) ) {
V_56 = V_2 -> V_15 ;
V_75 -> V_77 . V_6 |= V_78 ;
F_53 ( V_75 , 0 , F_41 ( V_73 ) +
V_2 -> V_15 ) ;
} else {
V_75 -> V_77 . V_6 |= V_83 ;
F_53 ( V_75 , 0 , F_41 ( V_73 ) ) ;
}
V_82 = ( F_44 ( V_73 ) - F_27 ( V_3 ) +
sizeof( * V_73 ) ) % F_25 ( V_3 ) ;
V_76 = F_52 ( F_41 ( V_73 ) + V_56 , V_81 ) ;
return F_28 ( V_2 , V_56 , V_58 , V_82 , V_76 ,
F_27 ( V_3 ) ,
F_25 ( V_3 ) ) ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_74 * V_75 , struct V_85 * V_86 )
{
const T_5 * V_73 = V_86 -> V_73 ;
int V_8 ;
switch ( V_2 -> V_87 ) {
case V_88 :
case V_89 :
V_8 = F_56 ( V_2 , V_75 , V_73 ) ;
break;
default:
V_8 = F_49 ( V_2 , V_75 , V_73 ) ;
break;
}
if ( ! V_8 ) {
bool V_90 = false ;
V_75 -> V_77 . V_46 = V_2 -> V_46 ++ ;
V_75 -> V_77 . V_91 . V_92 = F_47 ( V_73 ) ;
V_75 -> V_77 . V_91 . V_93 = F_48 ( V_73 ) ;
if ( F_1 ( V_2 ) ) {
if ( V_86 -> V_94 == 0 &&
V_2 -> V_47 &&
V_2 -> V_48 ++ > 5 )
V_90 = true ;
else if ( V_86 -> V_94 ) {
V_2 -> V_48 = 0 ;
V_90 = ! V_2 -> V_47 ;
}
}
if ( V_90 ) {
struct V_95 V_96 = {
. type = V_97 ,
. V_98 . V_99 = {
. V_6 = V_100 ,
. V_101 = V_75 -> V_77 . V_46 ,
. V_102 = V_86 -> V_94 ? 1 : 0 ,
} ,
} ;
V_2 -> V_47 = V_86 -> V_94 ;
V_2 -> V_48 = 0 ;
F_58 ( V_2 -> V_103 , & V_96 ) ;
}
}
F_59 ( V_75 , V_8 ? V_104 : V_105 ) ;
return V_8 ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_85 * V_86 )
{
struct V_106 * V_75 ;
unsigned long V_6 ;
F_61 ( & V_2 -> V_107 ) ;
if ( V_2 -> type != V_86 -> type )
goto V_108;
F_3 ( & V_2 -> V_109 , V_6 ) ;
if ( F_62 ( & V_2 -> V_110 ) ) {
F_6 ( & V_2 -> V_109 , V_6 ) ;
goto V_108;
}
V_75 = F_63 ( & V_2 -> V_110 , struct V_106 ,
V_111 ) ;
F_64 ( & V_75 -> V_111 ) ;
F_6 ( & V_2 -> V_109 , V_6 ) ;
F_57 ( V_2 , & V_75 -> V_75 , V_86 ) ;
V_108:
F_65 ( & V_2 -> V_107 ) ;
}
void F_66 ( struct V_3 * V_3 )
{
F_67 ( & V_3 -> V_112 ) ;
}
static void F_68 ( struct V_3 * V_3 )
{
for (; ; ) {
struct V_1 * V_2 ;
struct V_85 V_86 ;
T_1 V_113 , V_53 ;
T_3 V_5 ;
T_3 V_114 ;
V_114 = F_4 ( V_3 , F_69 ( 11 ) ) & 0xff ;
if ( V_114 == V_3 -> V_115 )
break;
V_113 = F_4 ( V_3 ,
F_70 ( V_3 -> V_115 ) ) ;
V_3 -> V_115 = ( V_3 -> V_115 + 1 ) % V_116 ;
V_5 = ( V_113 >> 24 ) & 0x1f ;
V_53 = V_113 & 0x00ffffff ;
if ( V_5 >= V_117 ) {
V_5 -= V_117 ;
V_86 . type = V_49 ;
} else
V_86 . type = V_118 ;
V_2 = V_3 -> V_119 [ V_5 ] ;
if ( V_2 == NULL ) {
F_71 ( & V_3 -> V_120 -> V_121 ,
L_1 , V_5 ) ;
continue;
}
if ( F_24 ( V_3 , V_3 -> V_122 , V_53 ,
sizeof( T_5 ) ) )
continue;
V_86 . V_73 = V_3 -> V_123 ;
if ( F_44 ( V_86 . V_73 ) !=
F_27 ( V_3 ) + V_53 )
continue;
if ( F_2 ( V_2 ) )
V_86 . V_94 = 1 ;
else
V_86 . V_94 = 0 ;
F_60 ( V_2 , & V_86 ) ;
}
}
static int F_72 ( void * V_124 )
{
struct V_3 * V_3 = V_124 ;
F_73 ( V_125 , V_126 ) ;
F_74 () ;
F_75 ( & V_3 -> V_112 , & V_125 ) ;
for (; ; ) {
long V_127 = F_76 ( V_128 ) ;
if ( V_127 == - V_129 || F_77 () )
break;
F_68 ( V_3 ) ;
F_78 () ;
}
F_79 ( & V_3 -> V_112 , & V_125 ) ;
return 0 ;
}
static int F_80 ( struct V_130 * V_131 ,
const struct V_132 * V_87 ,
unsigned int * V_133 ,
unsigned int * V_134 , unsigned int V_135 [] ,
void * V_136 [] )
{
struct V_1 * V_2 = F_81 ( V_131 ) ;
V_135 [ 0 ] = V_64 ;
V_136 [ 0 ] = V_2 -> V_137 ;
* V_134 = 1 ;
if ( * V_133 < V_138 )
* V_133 = V_138 ;
return 0 ;
}
static void F_82 ( struct V_74 * V_75 )
{
struct V_130 * V_139 = V_75 -> V_130 ;
struct V_1 * V_2 = F_81 ( V_139 ) ;
struct V_106 * V_140 =
F_83 ( V_75 , struct V_106 , V_75 ) ;
F_84 ( & V_2 -> V_109 ) ;
F_85 ( & V_140 -> V_111 , & V_2 -> V_110 ) ;
F_86 ( & V_2 -> V_109 ) ;
}
static int F_87 ( struct V_3 * V_3 )
{
V_3 -> V_141 = F_88 ( F_72 , V_3 ,
V_142 L_2 ) ;
if ( F_89 ( V_3 -> V_141 ) ) {
int V_143 = F_90 ( V_3 -> V_141 ) ;
V_3 -> V_141 = NULL ;
return V_143 ;
}
F_91 ( V_3 , V_144 ) ;
return 0 ;
}
static void F_92 ( struct V_3 * V_3 )
{
if ( V_3 -> V_141 ) {
F_93 ( V_3 -> V_141 ) ;
V_3 -> V_141 = NULL ;
}
F_94 ( V_3 , V_144 ) ;
}
static int F_95 ( struct V_130 * V_131 , unsigned int V_145 )
{
struct V_1 * V_2 = F_81 ( V_131 ) ;
return F_13 ( V_2 ) ;
}
static void F_96 ( struct V_130 * V_131 )
{
struct V_1 * V_2 = F_81 ( V_131 ) ;
unsigned long V_6 ;
F_3 ( & V_2 -> V_109 , V_6 ) ;
F_23 ( V_2 ) ;
while ( ! F_62 ( & V_2 -> V_110 ) ) {
struct V_106 * V_146 = F_97 (
V_2 -> V_110 . V_147 ,
struct V_106 , V_111 ) ;
F_64 ( & V_146 -> V_111 ) ;
F_59 ( & V_146 -> V_75 , V_104 ) ;
}
F_6 ( & V_2 -> V_109 , V_6 ) ;
}
static void F_98 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_81 ( V_75 -> V_130 ) ;
struct V_57 * V_58 = F_50 ( V_75 , 0 ) ;
switch ( V_2 -> V_87 ) {
case V_88 :
case V_89 :
if ( V_75 -> V_77 . V_6 & V_78 )
F_99 ( V_58 -> V_148 , V_58 -> V_149 ,
V_2 -> V_16 , V_2 -> V_15 ) ;
break;
default:
F_99 ( V_58 -> V_148 , V_58 -> V_149 ,
V_2 -> V_39 , V_2 -> V_79 ) ;
break;
}
}
static int F_100 ( struct V_150 * V_150 , void * V_151 ,
struct V_152 * V_153 )
{
struct V_1 * V_2 = F_101 ( V_150 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
strcpy ( V_153 -> V_154 , V_142 ) ;
snprintf ( V_153 -> V_155 , sizeof( V_153 -> V_155 ) , L_3 ,
V_2 -> V_5 ) ;
snprintf ( V_153 -> V_156 , sizeof( V_153 -> V_156 ) , L_4 ,
F_102 ( V_3 -> V_120 ) ) ;
V_153 -> V_157 = V_158 |
V_159 | V_160 ;
V_153 -> V_161 = V_153 -> V_157 | V_162 ;
return 0 ;
}
static int F_103 ( struct V_150 * V_150 , void * V_151 ,
struct V_163 * V_164 )
{
struct V_1 * V_2 = F_101 ( V_150 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( V_164 -> V_165 )
return - V_55 ;
snprintf ( V_164 -> V_166 , sizeof( V_164 -> V_166 ) , L_5 ,
V_2 -> V_5 + 1 ) ;
V_164 -> type = V_167 ;
V_164 -> V_168 = V_2 -> V_103 -> V_169 ;
if ( ! F_104 ( V_3 , V_2 -> V_5 ) )
V_164 -> V_170 = V_171 ;
return 0 ;
}
static int F_105 ( struct V_150 * V_150 , void * V_151 ,
unsigned int V_165 )
{
if ( V_165 )
return - V_55 ;
return 0 ;
}
static int F_106 ( struct V_150 * V_150 , void * V_151 ,
unsigned int * V_165 )
{
* V_165 = 0 ;
return 0 ;
}
static int F_107 ( struct V_150 * V_150 , void * V_151 ,
struct V_172 * V_173 )
{
struct V_1 * V_2 = F_101 ( V_150 ) ;
int V_174 = V_2 -> V_3 -> type ;
switch ( V_173 -> V_165 ) {
case 0 :
switch ( V_174 ) {
case V_38 :
V_173 -> V_175 = V_88 ;
strcpy ( V_173 -> V_176 , L_6 ) ;
break;
case V_27 :
V_173 -> V_175 = V_89 ;
strcpy ( V_173 -> V_176 , L_7 ) ;
break;
}
break;
case 1 :
V_173 -> V_175 = V_177 ;
strcpy ( V_173 -> V_176 , L_8 ) ;
break;
default:
return - V_55 ;
}
V_173 -> V_6 = V_178 ;
return 0 ;
}
static inline int F_108 ( T_1 V_179 , int V_174 )
{
return ( V_179 == V_89 && V_174 == V_27 )
|| ( V_179 == V_88 && V_174 == V_38 )
|| V_179 == V_177 ? 0 : - V_55 ;
}
static int F_109 ( struct V_150 * V_150 , void * V_151 ,
struct V_132 * V_173 )
{
struct V_1 * V_2 = F_101 ( V_150 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_180 * V_181 = & V_173 -> V_87 . V_181 ;
if ( F_108 ( V_181 -> V_175 , V_3 -> type ) )
return - V_55 ;
if ( V_181 -> V_23 < V_3 -> V_24 ||
V_181 -> V_25 < V_3 -> V_26 << 1 ) {
V_181 -> V_23 = V_3 -> V_24 >> 1 ;
V_181 -> V_25 = V_3 -> V_26 ;
} else {
V_181 -> V_23 = V_3 -> V_24 ;
V_181 -> V_25 = V_3 -> V_26 << 1 ;
}
switch ( V_181 -> V_182 ) {
case V_183 :
case V_184 :
break;
case V_185 :
default:
V_181 -> V_182 = V_184 ;
break;
}
V_181 -> V_186 = V_187 ;
V_181 -> V_188 = V_64 ;
V_181 -> V_189 = 0 ;
V_181 -> V_151 = 0 ;
return 0 ;
}
static int F_110 ( struct V_150 * V_150 , void * V_151 ,
struct V_132 * V_173 )
{
struct V_1 * V_2 = F_101 ( V_150 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_180 * V_181 = & V_173 -> V_87 . V_181 ;
int V_8 ;
if ( F_111 ( & V_2 -> V_190 ) )
return - V_45 ;
V_8 = F_109 ( V_150 , V_151 , V_173 ) ;
if ( V_8 )
return V_8 ;
if ( V_181 -> V_23 == V_3 -> V_24 )
V_2 -> V_18 = V_191 ;
else
V_2 -> V_18 = V_22 ;
V_2 -> V_87 = V_181 -> V_175 ;
F_10 ( V_2 ) ;
return 0 ;
}
static int F_112 ( struct V_150 * V_150 , void * V_151 ,
struct V_132 * V_173 )
{
struct V_1 * V_2 = F_101 ( V_150 ) ;
struct V_180 * V_181 = & V_173 -> V_87 . V_181 ;
V_181 -> V_23 = V_2 -> V_23 ;
V_181 -> V_25 = V_2 -> V_25 ;
V_181 -> V_175 = V_2 -> V_87 ;
V_181 -> V_182 = V_2 -> V_17 ? V_184 :
V_183 ;
V_181 -> V_188 = V_64 ;
V_181 -> V_186 = V_187 ;
V_181 -> V_151 = 0 ;
return 0 ;
}
static int F_113 ( struct V_150 * V_150 , void * V_151 , T_6 * V_63 )
{
struct V_1 * V_2 = F_101 ( V_150 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( V_3 -> V_28 == V_29 )
* V_63 = V_192 ;
else
* V_63 = V_193 ;
return 0 ;
}
static int F_114 ( struct V_150 * V_150 , void * V_151 , T_6 V_168 )
{
struct V_1 * V_2 = F_101 ( V_150 ) ;
return F_115 ( V_2 -> V_3 , V_168 & V_194 ) ;
}
static int F_116 ( struct V_150 * V_150 , void * V_151 ,
struct V_195 * V_196 )
{
struct V_1 * V_2 = F_101 ( V_150 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( F_108 ( V_196 -> V_197 , V_3 -> type ) )
return - V_55 ;
switch ( V_196 -> V_165 ) {
case 0 :
V_196 -> V_198 . V_23 = V_3 -> V_24 >> 1 ;
V_196 -> V_198 . V_25 = V_3 -> V_26 ;
break;
case 1 :
V_196 -> V_198 . V_23 = V_3 -> V_24 ;
V_196 -> V_198 . V_25 = V_3 -> V_26 << 1 ;
break;
default:
return - V_55 ;
}
V_196 -> type = V_199 ;
return 0 ;
}
static int F_117 ( struct V_150 * V_150 , void * V_151 ,
struct V_200 * V_201 )
{
struct V_1 * V_2 = F_101 ( V_150 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( F_108 ( V_201 -> V_197 , V_3 -> type ) )
return - V_55 ;
if ( V_201 -> V_165 )
return - V_55 ;
if ( ( V_201 -> V_23 != V_3 -> V_24 >> 1 ||
V_201 -> V_25 != V_3 -> V_26 ) &&
( V_201 -> V_23 != V_3 -> V_24 ||
V_201 -> V_25 != V_3 -> V_26 << 1 ) )
return - V_55 ;
V_201 -> type = V_202 ;
V_201 -> V_203 . F_34 . V_204 = 1 ;
V_201 -> V_203 . F_34 . V_205 = V_3 -> V_20 ;
V_201 -> V_203 . F_11 . V_204 = 15 ;
V_201 -> V_203 . F_11 . V_205 = V_3 -> V_20 ;
V_201 -> V_203 . V_206 . V_204 = 1 ;
V_201 -> V_203 . V_206 . V_205 = V_3 -> V_20 ;
return 0 ;
}
static int F_118 ( struct V_150 * V_150 , void * V_151 ,
struct V_207 * V_208 )
{
struct V_1 * V_2 = F_101 ( V_150 ) ;
struct V_209 * V_210 = & V_208 -> V_211 . V_212 ;
V_210 -> V_213 = V_214 ;
V_210 -> V_215 . V_204 = V_2 -> V_21 ;
V_210 -> V_215 . V_205 = V_2 -> V_3 -> V_20 ;
V_210 -> V_216 = 0 ;
V_210 -> V_217 = 2 ;
return 0 ;
}
static inline int F_119 ( T_3 V_20 , T_1 V_218 , T_1 V_219 )
{
if ( ! V_218 || ! V_219 )
return 1 ;
if ( V_219 == V_20 )
return V_218 ;
V_218 *= V_20 ;
return F_34 ( 15U , V_218 / V_219 + ( V_218 % V_219 >= ( V_20 >> 1 ) ) ) ;
}
static int F_120 ( struct V_150 * V_150 , void * V_151 ,
struct V_207 * V_208 )
{
struct V_1 * V_2 = F_101 ( V_150 ) ;
struct V_220 * V_221 = & V_208 -> V_211 . V_212 . V_215 ;
T_3 V_20 = V_2 -> V_3 -> V_20 ;
if ( F_121 ( & V_2 -> V_190 ) )
return - V_45 ;
V_2 -> V_21 = F_119 ( V_20 , V_221 -> V_204 , V_221 -> V_205 ) ;
F_10 ( V_2 ) ;
return F_118 ( V_150 , V_151 , V_208 ) ;
}
static int F_122 ( struct V_222 * V_223 )
{
struct V_1 * V_2 =
F_83 ( V_223 -> V_224 , struct V_1 , V_225 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
int V_143 ;
switch ( V_223 -> V_226 ) {
case V_227 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
return F_123 ( V_3 , V_223 -> V_226 , V_2 -> V_5 ,
V_223 -> V_232 ) ;
case V_233 :
V_2 -> V_50 = V_223 -> V_232 ;
F_5 ( V_3 , F_17 ( V_2 -> V_5 ) , V_2 -> V_50 ) ;
F_5 ( V_3 , F_20 ( V_2 -> V_5 ) , V_2 -> V_50 ) ;
return 0 ;
case V_234 :
V_2 -> V_51 = V_223 -> V_232 ;
F_5 ( V_3 , F_18 ( V_2 -> V_5 ) , V_2 -> V_51 ) ;
F_5 ( V_3 , F_21 ( V_2 -> V_5 ) , V_2 -> V_51 ) ;
return 0 ;
case V_235 :
V_2 -> V_236 = V_223 -> V_232 << 8 ;
if ( ! V_2 -> V_237 || ! V_2 -> V_238 )
return 0 ;
return F_124 ( V_3 , V_2 -> V_5 ,
V_2 -> V_236 ) ;
case V_239 :
V_2 -> V_237 = V_223 -> V_232 == V_240 ;
V_2 -> V_238 = V_223 -> V_232 > V_241 ;
if ( V_223 -> V_232 ) {
if ( V_2 -> V_237 )
V_143 = F_124 ( V_3 , V_2 -> V_5 ,
V_2 -> V_236 ) ;
else
V_143 = F_125 ( V_3 , V_2 -> V_5 ,
V_2 -> V_242 -> V_243 . V_244 ) ;
if ( V_143 )
return V_143 ;
}
F_7 ( V_2 , V_223 -> V_232 ) ;
return 0 ;
case V_245 :
if ( V_2 -> V_238 && ! V_2 -> V_237 )
return F_125 ( V_3 , V_2 -> V_5 ,
V_2 -> V_242 -> V_246 . V_244 ) ;
break;
case V_247 :
strcpy ( V_2 -> V_248 , V_223 -> V_246 . V_249 ) ;
return F_126 ( V_2 ) ;
default:
return - V_55 ;
}
return 0 ;
}
static int F_127 ( struct V_250 * V_251 ,
const struct V_252 * V_253 )
{
switch ( V_253 -> type ) {
case V_254 :
return F_128 ( V_251 , V_253 ) ;
case V_97 :
return F_129 ( V_251 , V_253 , 30 , NULL ) ;
}
return - V_55 ;
}
static struct V_1 * F_130 ( struct V_3 * V_3 ,
T_3 V_5 , unsigned V_255 )
{
struct V_1 * V_2 ;
struct V_256 * V_225 ;
int V_8 ;
V_2 = F_131 ( sizeof( * V_2 ) , V_257 ) ;
if ( ! V_2 )
return F_132 ( - V_258 ) ;
V_225 = & V_2 -> V_225 ;
V_2 -> V_137 = F_133 ( & V_3 -> V_120 -> V_121 ) ;
if ( F_89 ( V_2 -> V_137 ) ) {
V_8 = F_90 ( V_2 -> V_137 ) ;
goto V_259;
}
F_134 ( V_225 , 10 ) ;
F_135 ( V_225 , & V_260 ,
V_227 , 0 , 255 , 1 , 128 ) ;
F_135 ( V_225 , & V_260 ,
V_228 , 0 , 255 , 1 , 128 ) ;
F_135 ( V_225 , & V_260 ,
V_229 , 0 , 255 , 1 , 128 ) ;
F_135 ( V_225 , & V_260 ,
V_230 , 0 , 255 , 1 , 128 ) ;
if ( F_136 ( V_3 , V_5 ) )
F_135 ( V_225 , & V_260 ,
V_231 , 0 , 15 , 1 , 0 ) ;
F_135 ( V_225 , & V_260 ,
V_233 , 1 , 255 , 1 , V_3 -> V_20 ) ;
F_135 ( V_225 , & V_260 ,
V_234 , 0 , 31 , 1 , V_261 ) ;
F_137 ( V_225 , & V_260 ,
V_239 ,
V_262 , 0 ,
V_241 ) ;
F_135 ( V_225 , & V_260 ,
V_235 , 0 , 0xff , 1 ,
V_263 >> 8 ) ;
F_138 ( V_225 , & V_264 , NULL ) ;
V_2 -> V_242 =
F_138 ( V_225 , & V_265 , NULL ) ;
if ( V_225 -> error ) {
V_8 = V_225 -> error ;
goto V_259;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_5 = V_5 ;
F_139 ( & V_2 -> V_107 ) ;
F_140 ( & V_2 -> V_109 ) ;
F_141 ( & V_2 -> V_110 ) ;
V_2 -> V_87 = ( V_3 -> type == V_38 ) ?
V_88 : V_89 ;
V_2 -> type = V_118 ;
V_2 -> V_51 = V_261 ;
V_2 -> V_50 = V_3 -> V_20 ;
V_2 -> V_21 = 1 ;
V_2 -> V_18 = V_22 ;
V_2 -> V_237 = true ;
V_2 -> V_236 = V_263 ;
V_2 -> V_190 . type = V_266 ;
V_2 -> V_190 . V_267 = V_268 | V_269 | V_270 ;
V_2 -> V_190 . V_271 = & V_272 ;
V_2 -> V_190 . V_273 = & V_274 ;
V_2 -> V_190 . V_275 = V_2 ;
V_2 -> V_190 . V_276 = V_277 ;
V_2 -> V_190 . V_278 = V_279 ;
V_2 -> V_190 . V_280 = sizeof( struct V_106 ) ;
V_2 -> V_190 . V_107 = & V_2 -> V_107 ;
V_8 = F_142 ( & V_2 -> V_190 ) ;
if ( V_8 )
goto V_259;
F_10 ( V_2 ) ;
F_140 ( & V_2 -> V_9 ) ;
V_2 -> V_79 = sizeof( V_39 ) ;
memcpy ( V_2 -> V_39 , V_39 , V_2 -> V_79 ) ;
V_2 -> V_71 = 32 ;
V_2 -> V_70 = F_143 ( V_3 -> V_120 ,
sizeof( struct V_66 ) *
V_2 -> V_71 ,
& V_2 -> V_72 ) ;
V_8 = - V_258 ;
if ( V_2 -> V_70 == NULL )
goto V_259;
V_2 -> V_103 = F_144 () ;
if ( ! V_2 -> V_103 )
goto V_281;
* V_2 -> V_103 = V_282 ;
V_2 -> V_103 -> V_283 = & V_3 -> V_283 ;
V_2 -> V_103 -> V_284 = V_225 ;
V_2 -> V_103 -> V_285 = & V_2 -> V_190 ;
V_2 -> V_103 -> V_107 = & V_2 -> V_107 ;
F_145 ( V_2 -> V_103 , V_2 ) ;
V_8 = F_146 ( V_2 -> V_103 , V_286 , V_255 ) ;
if ( V_8 < 0 )
goto V_287;
snprintf ( V_2 -> V_103 -> V_166 , sizeof( V_2 -> V_103 -> V_166 ) ,
L_9 , V_142 , V_3 -> V_103 -> V_288 ,
V_2 -> V_103 -> V_288 ) ;
return V_2 ;
V_287:
F_147 ( V_2 -> V_103 ) ;
V_281:
F_148 ( V_2 -> V_3 -> V_120 ,
sizeof( struct V_66 ) * V_2 -> V_71 ,
V_2 -> V_70 , V_2 -> V_72 ) ;
V_259:
F_149 ( V_225 ) ;
F_150 ( V_2 -> V_137 ) ;
F_151 ( V_2 ) ;
return F_132 ( V_8 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
F_148 ( V_2 -> V_3 -> V_120 ,
sizeof( struct V_66 ) * V_2 -> V_71 ,
V_2 -> V_70 , V_2 -> V_72 ) ;
F_153 ( V_2 -> V_103 ) ;
F_149 ( & V_2 -> V_225 ) ;
F_150 ( V_2 -> V_137 ) ;
F_151 ( V_2 ) ;
}
int F_154 ( struct V_3 * V_3 , unsigned V_255 )
{
int V_63 ;
F_155 ( & V_3 -> V_112 ) ;
V_3 -> V_289 = sizeof( T_5 ) ;
V_3 -> V_123 = F_143 ( V_3 -> V_120 ,
V_3 -> V_289 ,
& V_3 -> V_122 ) ;
if ( V_3 -> V_123 == NULL )
return - V_258 ;
for ( V_63 = 0 ; V_63 < V_3 -> V_290 ; V_63 ++ ) {
V_3 -> V_119 [ V_63 ] = F_130 ( V_3 , V_63 , V_255 ) ;
if ( F_89 ( V_3 -> V_119 [ V_63 ] ) )
break;
}
if ( V_63 != V_3 -> V_290 ) {
int V_8 = F_90 ( V_3 -> V_119 [ V_63 ] ) ;
while ( V_63 -- )
F_152 ( V_3 -> V_119 [ V_63 ] ) ;
F_148 ( V_3 -> V_120 , V_3 -> V_289 ,
V_3 -> V_123 , V_3 -> V_122 ) ;
V_3 -> V_123 = NULL ;
return V_8 ;
}
if ( V_3 -> type == V_38 )
V_3 -> V_44 = V_3 -> V_20 * 4 * 4 ;
else
V_3 -> V_44 = V_3 -> V_20 * 4 * 5 ;
F_156 ( & V_3 -> V_120 -> V_121 , L_10 ,
V_3 -> V_119 [ 0 ] -> V_103 -> V_288 ,
V_3 -> V_119 [ V_3 -> V_290 - 1 ] -> V_103 -> V_288 ) ;
return F_87 ( V_3 ) ;
}
void F_157 ( struct V_3 * V_3 )
{
int V_63 ;
F_92 ( V_3 ) ;
for ( V_63 = 0 ; V_63 < V_3 -> V_290 ; V_63 ++ )
F_152 ( V_3 -> V_119 [ V_63 ] ) ;
if ( V_3 -> V_123 )
F_148 ( V_3 -> V_120 , V_3 -> V_289 ,
V_3 -> V_123 , V_3 -> V_122 ) ;
}
