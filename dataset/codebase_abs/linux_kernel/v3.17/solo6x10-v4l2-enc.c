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
int V_8 ;
V_75 -> V_77 . V_6 |= V_78 ;
if ( F_51 ( V_75 , 0 ) < F_46 ( V_73 ) + V_2 -> V_79 )
return - V_80 ;
V_76 = F_52 ( F_46 ( V_73 ) + V_2 -> V_79 , V_81 ) ;
F_53 ( V_75 , 0 , F_46 ( V_73 ) + V_2 -> V_79 ) ;
if ( ! F_54 ( & V_3 -> V_82 -> V_83 , V_58 -> V_84 , V_58 -> V_85 ,
V_86 ) )
return - V_87 ;
V_8 = F_28 ( V_2 , V_2 -> V_79 , V_58 ,
F_45 ( V_73 ) - F_55 ( V_3 ) ,
V_76 , F_55 ( V_3 ) ,
F_56 ( V_3 ) ) ;
F_57 ( & V_3 -> V_82 -> V_83 , V_58 -> V_84 , V_58 -> V_85 ,
V_86 ) ;
F_58 ( V_58 -> V_84 , V_58 -> V_85 ,
V_2 -> V_39 , V_2 -> V_79 ) ;
return V_8 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_74 * V_75 , const T_5 * V_73 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_57 * V_58 = F_50 ( V_75 , 0 ) ;
int V_88 , V_76 ;
int V_56 = 0 ;
int V_8 ;
if ( F_51 ( V_75 , 0 ) < F_41 ( V_73 ) )
return - V_80 ;
V_75 -> V_77 . V_6 &= ~ ( V_78 | V_89 |
V_90 ) ;
if ( ! F_40 ( V_73 ) ) {
V_56 = V_2 -> V_15 ;
V_75 -> V_77 . V_6 |= V_78 ;
F_53 ( V_75 , 0 , F_41 ( V_73 ) +
V_2 -> V_15 ) ;
} else {
V_75 -> V_77 . V_6 |= V_89 ;
F_53 ( V_75 , 0 , F_41 ( V_73 ) ) ;
}
V_88 = ( F_44 ( V_73 ) - F_27 ( V_3 ) +
sizeof( * V_73 ) ) % F_25 ( V_3 ) ;
V_76 = F_52 ( F_41 ( V_73 ) + V_56 , V_81 ) ;
if ( ! F_54 ( & V_3 -> V_82 -> V_83 , V_58 -> V_84 , V_58 -> V_85 ,
V_86 ) )
return - V_87 ;
V_8 = F_28 ( V_2 , V_56 , V_58 , V_88 , V_76 ,
F_27 ( V_3 ) ,
F_25 ( V_3 ) ) ;
F_57 ( & V_3 -> V_82 -> V_83 , V_58 -> V_84 , V_58 -> V_85 ,
V_86 ) ;
if ( ! F_40 ( V_73 ) )
F_58 ( V_58 -> V_84 , V_58 -> V_85 ,
V_2 -> V_16 , V_2 -> V_15 ) ;
return V_8 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_74 * V_75 , struct V_91 * V_92 )
{
const T_5 * V_73 = V_92 -> V_73 ;
int V_8 ;
switch ( V_2 -> V_93 ) {
case V_94 :
case V_95 :
V_8 = F_59 ( V_2 , V_75 , V_73 ) ;
break;
default:
V_8 = F_49 ( V_2 , V_75 , V_73 ) ;
break;
}
if ( ! V_8 ) {
bool V_96 = false ;
V_75 -> V_77 . V_46 = V_2 -> V_46 ++ ;
V_75 -> V_77 . V_97 . V_98 = F_47 ( V_73 ) ;
V_75 -> V_77 . V_97 . V_99 = F_48 ( V_73 ) ;
if ( F_1 ( V_2 ) ) {
if ( V_92 -> V_100 == 0 &&
V_2 -> V_47 &&
V_2 -> V_48 ++ > 5 )
V_96 = true ;
else if ( V_92 -> V_100 ) {
V_2 -> V_48 = 0 ;
V_96 = ! V_2 -> V_47 ;
}
}
if ( V_96 ) {
struct V_101 V_102 = {
. type = V_103 ,
. V_104 . V_105 = {
. V_6 = V_106 ,
. V_107 = V_75 -> V_77 . V_46 ,
. V_108 = V_92 -> V_100 ? 1 : 0 ,
} ,
} ;
V_2 -> V_47 = V_92 -> V_100 ;
V_2 -> V_48 = 0 ;
F_61 ( V_2 -> V_109 , & V_102 ) ;
}
}
F_62 ( V_75 , V_8 ? V_110 : V_111 ) ;
return V_8 ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_91 * V_92 )
{
struct V_112 * V_75 ;
unsigned long V_6 ;
F_64 ( & V_2 -> V_113 ) ;
if ( V_2 -> type != V_92 -> type )
goto V_114;
F_3 ( & V_2 -> V_115 , V_6 ) ;
if ( F_65 ( & V_2 -> V_116 ) ) {
F_6 ( & V_2 -> V_115 , V_6 ) ;
goto V_114;
}
V_75 = F_66 ( & V_2 -> V_116 , struct V_112 ,
V_117 ) ;
F_67 ( & V_75 -> V_117 ) ;
F_6 ( & V_2 -> V_115 , V_6 ) ;
F_60 ( V_2 , & V_75 -> V_75 , V_92 ) ;
V_114:
F_68 ( & V_2 -> V_113 ) ;
}
void F_69 ( struct V_3 * V_3 )
{
F_70 ( & V_3 -> V_118 ) ;
}
static void F_71 ( struct V_3 * V_3 )
{
for (; ; ) {
struct V_1 * V_2 ;
struct V_91 V_92 ;
T_1 V_119 , V_53 ;
T_3 V_5 ;
T_3 V_120 ;
V_120 = F_4 ( V_3 , F_72 ( 11 ) ) & 0xff ;
if ( V_120 == V_3 -> V_121 )
break;
V_119 = F_4 ( V_3 ,
F_73 ( V_3 -> V_121 ) ) ;
V_3 -> V_121 = ( V_3 -> V_121 + 1 ) % V_122 ;
V_5 = ( V_119 >> 24 ) & 0x1f ;
V_53 = V_119 & 0x00ffffff ;
if ( V_5 >= V_123 ) {
V_5 -= V_123 ;
V_92 . type = V_49 ;
} else
V_92 . type = V_124 ;
V_2 = V_3 -> V_125 [ V_5 ] ;
if ( V_2 == NULL ) {
F_74 ( & V_3 -> V_82 -> V_83 ,
L_1 , V_5 ) ;
continue;
}
if ( F_24 ( V_3 , V_3 -> V_126 , V_53 ,
sizeof( T_5 ) ) )
continue;
V_92 . V_73 = V_3 -> V_127 ;
if ( F_44 ( V_92 . V_73 ) !=
F_27 ( V_3 ) + V_53 )
continue;
if ( F_2 ( V_2 ) )
V_92 . V_100 = 1 ;
else
V_92 . V_100 = 0 ;
F_63 ( V_2 , & V_92 ) ;
}
}
static int F_75 ( void * V_128 )
{
struct V_3 * V_3 = V_128 ;
F_76 ( V_129 , V_130 ) ;
F_77 () ;
F_78 ( & V_3 -> V_118 , & V_129 ) ;
for (; ; ) {
long V_131 = F_79 ( V_132 ) ;
if ( V_131 == - V_133 || F_80 () )
break;
F_81 ( V_3 , V_134 ) ;
F_71 ( V_3 ) ;
F_82 ( V_3 , V_134 ) ;
F_83 () ;
}
F_84 ( & V_3 -> V_118 , & V_129 ) ;
return 0 ;
}
static int F_85 ( struct V_135 * V_136 ,
const struct V_137 * V_93 ,
unsigned int * V_138 ,
unsigned int * V_139 , unsigned int V_140 [] ,
void * V_141 [] )
{
V_140 [ 0 ] = V_64 ;
* V_139 = 1 ;
if ( * V_138 < V_142 )
* V_138 = V_142 ;
return 0 ;
}
static void F_86 ( struct V_74 * V_75 )
{
struct V_135 * V_143 = V_75 -> V_135 ;
struct V_1 * V_2 = F_87 ( V_143 ) ;
struct V_112 * V_144 =
F_88 ( V_75 , struct V_112 , V_75 ) ;
F_89 ( & V_2 -> V_115 ) ;
F_90 ( & V_144 -> V_117 , & V_2 -> V_116 ) ;
F_91 ( & V_2 -> V_115 ) ;
}
static int F_92 ( struct V_3 * V_3 )
{
V_3 -> V_145 = F_93 ( F_75 , V_3 ,
V_146 L_2 ) ;
if ( F_94 ( V_3 -> V_145 ) ) {
int V_147 = F_95 ( V_3 -> V_145 ) ;
V_3 -> V_145 = NULL ;
return V_147 ;
}
F_82 ( V_3 , V_134 ) ;
return 0 ;
}
static void F_96 ( struct V_3 * V_3 )
{
if ( V_3 -> V_145 ) {
F_97 ( V_3 -> V_145 ) ;
V_3 -> V_145 = NULL ;
}
F_81 ( V_3 , V_134 ) ;
}
static int F_98 ( struct V_135 * V_136 , unsigned int V_148 )
{
struct V_1 * V_2 = F_87 ( V_136 ) ;
int V_8 ;
V_8 = F_13 ( V_2 ) ;
if ( V_8 )
return V_8 ;
return F_92 ( V_2 -> V_3 ) ;
}
static void F_99 ( struct V_135 * V_136 )
{
struct V_1 * V_2 = F_87 ( V_136 ) ;
F_23 ( V_2 ) ;
F_100 ( & V_2 -> V_116 ) ;
F_96 ( V_2 -> V_3 ) ;
}
static int F_101 ( struct V_149 * V_149 , void * V_150 ,
struct V_151 * V_152 )
{
struct V_1 * V_2 = F_102 ( V_149 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
strcpy ( V_152 -> V_153 , V_146 ) ;
snprintf ( V_152 -> V_154 , sizeof( V_152 -> V_154 ) , L_3 ,
V_2 -> V_5 ) ;
snprintf ( V_152 -> V_155 , sizeof( V_152 -> V_155 ) , L_4 ,
F_103 ( V_3 -> V_82 ) ) ;
V_152 -> V_156 = V_157 |
V_158 | V_159 ;
V_152 -> V_160 = V_152 -> V_156 | V_161 ;
return 0 ;
}
static int F_104 ( struct V_149 * V_149 , void * V_150 ,
struct V_162 * V_163 )
{
struct V_1 * V_2 = F_102 ( V_149 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( V_163 -> V_164 )
return - V_55 ;
snprintf ( V_163 -> V_165 , sizeof( V_163 -> V_165 ) , L_5 ,
V_2 -> V_5 + 1 ) ;
V_163 -> type = V_166 ;
V_163 -> V_167 = V_2 -> V_109 -> V_168 ;
if ( ! F_105 ( V_3 , V_2 -> V_5 ) )
V_163 -> V_169 = V_170 ;
return 0 ;
}
static int F_106 ( struct V_149 * V_149 , void * V_150 ,
unsigned int V_164 )
{
if ( V_164 )
return - V_55 ;
return 0 ;
}
static int F_107 ( struct V_149 * V_149 , void * V_150 ,
unsigned int * V_164 )
{
* V_164 = 0 ;
return 0 ;
}
static int F_108 ( struct V_149 * V_149 , void * V_150 ,
struct V_171 * V_172 )
{
struct V_1 * V_2 = F_102 ( V_149 ) ;
int V_173 = V_2 -> V_3 -> type ;
switch ( V_172 -> V_164 ) {
case 0 :
switch ( V_173 ) {
case V_38 :
V_172 -> V_174 = V_94 ;
strcpy ( V_172 -> V_175 , L_6 ) ;
break;
case V_27 :
V_172 -> V_174 = V_95 ;
strcpy ( V_172 -> V_175 , L_7 ) ;
break;
}
break;
case 1 :
V_172 -> V_174 = V_176 ;
strcpy ( V_172 -> V_175 , L_8 ) ;
break;
default:
return - V_55 ;
}
V_172 -> V_6 = V_177 ;
return 0 ;
}
static inline int F_109 ( T_1 V_178 , int V_173 )
{
return ( V_178 == V_95 && V_173 == V_27 )
|| ( V_178 == V_94 && V_173 == V_38 )
|| V_178 == V_176 ? 0 : - V_55 ;
}
static int F_110 ( struct V_149 * V_149 , void * V_150 ,
struct V_137 * V_172 )
{
struct V_1 * V_2 = F_102 ( V_149 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_179 * V_180 = & V_172 -> V_93 . V_180 ;
if ( F_109 ( V_180 -> V_174 , V_3 -> type ) )
return - V_55 ;
if ( V_180 -> V_23 < V_3 -> V_24 ||
V_180 -> V_25 < V_3 -> V_26 << 1 ) {
V_180 -> V_23 = V_3 -> V_24 >> 1 ;
V_180 -> V_25 = V_3 -> V_26 ;
} else {
V_180 -> V_23 = V_3 -> V_24 ;
V_180 -> V_25 = V_3 -> V_26 << 1 ;
}
switch ( V_180 -> V_181 ) {
case V_182 :
case V_183 :
break;
case V_184 :
default:
V_180 -> V_181 = V_183 ;
break;
}
V_180 -> V_185 = V_186 ;
V_180 -> V_187 = V_64 ;
V_180 -> V_188 = 0 ;
V_180 -> V_150 = 0 ;
return 0 ;
}
static int F_111 ( struct V_149 * V_149 , void * V_150 ,
struct V_137 * V_172 )
{
struct V_1 * V_2 = F_102 ( V_149 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_179 * V_180 = & V_172 -> V_93 . V_180 ;
int V_8 ;
if ( F_112 ( & V_2 -> V_189 ) )
return - V_45 ;
V_8 = F_110 ( V_149 , V_150 , V_172 ) ;
if ( V_8 )
return V_8 ;
if ( V_180 -> V_23 == V_3 -> V_24 )
V_2 -> V_18 = V_190 ;
else
V_2 -> V_18 = V_22 ;
V_2 -> V_93 = V_180 -> V_174 ;
F_10 ( V_2 ) ;
return 0 ;
}
static int F_113 ( struct V_149 * V_149 , void * V_150 ,
struct V_137 * V_172 )
{
struct V_1 * V_2 = F_102 ( V_149 ) ;
struct V_179 * V_180 = & V_172 -> V_93 . V_180 ;
V_180 -> V_23 = V_2 -> V_23 ;
V_180 -> V_25 = V_2 -> V_25 ;
V_180 -> V_174 = V_2 -> V_93 ;
V_180 -> V_181 = V_2 -> V_17 ? V_183 :
V_182 ;
V_180 -> V_187 = V_64 ;
V_180 -> V_185 = V_186 ;
V_180 -> V_150 = 0 ;
return 0 ;
}
static int F_114 ( struct V_149 * V_149 , void * V_150 , T_6 * V_63 )
{
struct V_1 * V_2 = F_102 ( V_149 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( V_3 -> V_28 == V_29 )
* V_63 = V_191 ;
else
* V_63 = V_192 ;
return 0 ;
}
static int F_115 ( struct V_149 * V_149 , void * V_150 , T_6 V_167 )
{
struct V_1 * V_2 = F_102 ( V_149 ) ;
return F_116 ( V_2 -> V_3 , V_167 & V_193 ) ;
}
static int F_117 ( struct V_149 * V_149 , void * V_150 ,
struct V_194 * V_195 )
{
struct V_1 * V_2 = F_102 ( V_149 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( F_109 ( V_195 -> V_196 , V_3 -> type ) )
return - V_55 ;
switch ( V_195 -> V_164 ) {
case 0 :
V_195 -> V_197 . V_23 = V_3 -> V_24 >> 1 ;
V_195 -> V_197 . V_25 = V_3 -> V_26 ;
break;
case 1 :
V_195 -> V_197 . V_23 = V_3 -> V_24 ;
V_195 -> V_197 . V_25 = V_3 -> V_26 << 1 ;
break;
default:
return - V_55 ;
}
V_195 -> type = V_198 ;
return 0 ;
}
static int F_118 ( struct V_149 * V_149 , void * V_150 ,
struct V_199 * V_200 )
{
struct V_1 * V_2 = F_102 ( V_149 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( F_109 ( V_200 -> V_196 , V_3 -> type ) )
return - V_55 ;
if ( V_200 -> V_164 )
return - V_55 ;
if ( ( V_200 -> V_23 != V_3 -> V_24 >> 1 ||
V_200 -> V_25 != V_3 -> V_26 ) &&
( V_200 -> V_23 != V_3 -> V_24 ||
V_200 -> V_25 != V_3 -> V_26 << 1 ) )
return - V_55 ;
V_200 -> type = V_201 ;
V_200 -> V_202 . F_34 . V_203 = 1 ;
V_200 -> V_202 . F_34 . V_204 = V_3 -> V_20 ;
V_200 -> V_202 . F_11 . V_203 = 15 ;
V_200 -> V_202 . F_11 . V_204 = V_3 -> V_20 ;
V_200 -> V_202 . V_205 . V_203 = 1 ;
V_200 -> V_202 . V_205 . V_204 = V_3 -> V_20 ;
return 0 ;
}
static int F_119 ( struct V_149 * V_149 , void * V_150 ,
struct V_206 * V_207 )
{
struct V_1 * V_2 = F_102 ( V_149 ) ;
struct V_208 * V_209 = & V_207 -> V_210 . V_211 ;
V_209 -> V_212 = V_213 ;
V_209 -> V_214 . V_203 = V_2 -> V_21 ;
V_209 -> V_214 . V_204 = V_2 -> V_3 -> V_20 ;
V_209 -> V_215 = 0 ;
V_209 -> V_216 = 2 ;
return 0 ;
}
static inline int F_120 ( T_3 V_20 , T_1 V_217 , T_1 V_218 )
{
if ( ! V_217 || ! V_218 )
return 1 ;
if ( V_218 == V_20 )
return V_217 ;
V_217 *= V_20 ;
return F_34 ( 15U , V_217 / V_218 + ( V_217 % V_218 >= ( V_20 >> 1 ) ) ) ;
}
static int F_121 ( struct V_149 * V_149 , void * V_150 ,
struct V_206 * V_207 )
{
struct V_1 * V_2 = F_102 ( V_149 ) ;
struct V_219 * V_220 = & V_207 -> V_210 . V_211 . V_214 ;
T_3 V_20 = V_2 -> V_3 -> V_20 ;
if ( F_122 ( & V_2 -> V_189 ) )
return - V_45 ;
V_2 -> V_21 = F_120 ( V_20 , V_220 -> V_203 , V_220 -> V_204 ) ;
F_10 ( V_2 ) ;
return F_119 ( V_149 , V_150 , V_207 ) ;
}
static int F_123 ( struct V_221 * V_222 )
{
struct V_1 * V_2 =
F_88 ( V_222 -> V_223 , struct V_1 , V_224 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
int V_147 ;
switch ( V_222 -> V_225 ) {
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case V_230 :
return F_124 ( V_3 , V_222 -> V_225 , V_2 -> V_5 ,
V_222 -> V_231 ) ;
case V_232 :
V_2 -> V_50 = V_222 -> V_231 ;
F_5 ( V_3 , F_17 ( V_2 -> V_5 ) , V_2 -> V_50 ) ;
F_5 ( V_3 , F_20 ( V_2 -> V_5 ) , V_2 -> V_50 ) ;
return 0 ;
case V_233 :
V_2 -> V_51 = V_222 -> V_231 ;
F_5 ( V_3 , F_18 ( V_2 -> V_5 ) , V_2 -> V_51 ) ;
F_5 ( V_3 , F_21 ( V_2 -> V_5 ) , V_2 -> V_51 ) ;
return 0 ;
case V_234 :
V_2 -> V_235 = V_222 -> V_231 << 8 ;
if ( ! V_2 -> V_236 || ! V_2 -> V_237 )
return 0 ;
return F_125 ( V_3 , V_2 -> V_5 ,
V_2 -> V_235 ) ;
case V_238 :
V_2 -> V_236 = V_222 -> V_231 == V_239 ;
V_2 -> V_237 = V_222 -> V_231 > V_240 ;
if ( V_222 -> V_231 ) {
if ( V_2 -> V_236 )
V_147 = F_125 ( V_3 , V_2 -> V_5 ,
V_2 -> V_235 ) ;
else
V_147 = F_126 ( V_3 , V_2 -> V_5 ,
V_2 -> V_241 -> V_242 . V_243 ) ;
if ( V_147 )
return V_147 ;
}
F_7 ( V_2 , V_222 -> V_231 ) ;
return 0 ;
case V_244 :
if ( V_2 -> V_237 && ! V_2 -> V_236 )
return F_126 ( V_3 , V_2 -> V_5 ,
V_2 -> V_241 -> V_245 . V_243 ) ;
break;
case V_246 :
strcpy ( V_2 -> V_247 , V_222 -> V_245 . V_248 ) ;
return F_127 ( V_2 ) ;
default:
return - V_55 ;
}
return 0 ;
}
static int F_128 ( struct V_249 * V_250 ,
const struct V_251 * V_252 )
{
switch ( V_252 -> type ) {
case V_253 :
return F_129 ( V_250 , V_252 ) ;
case V_103 :
return F_130 ( V_250 , V_252 , 30 , NULL ) ;
}
return - V_55 ;
}
static struct V_1 * F_131 ( struct V_3 * V_3 ,
T_3 V_5 , unsigned V_254 )
{
struct V_1 * V_2 ;
struct V_255 * V_224 ;
int V_8 ;
V_2 = F_132 ( sizeof( * V_2 ) , V_256 ) ;
if ( ! V_2 )
return F_133 ( - V_87 ) ;
V_224 = & V_2 -> V_224 ;
F_134 ( V_224 , 10 ) ;
F_135 ( V_224 , & V_257 ,
V_226 , 0 , 255 , 1 , 128 ) ;
F_135 ( V_224 , & V_257 ,
V_227 , 0 , 255 , 1 , 128 ) ;
F_135 ( V_224 , & V_257 ,
V_228 , 0 , 255 , 1 , 128 ) ;
F_135 ( V_224 , & V_257 ,
V_229 , 0 , 255 , 1 , 128 ) ;
if ( F_136 ( V_3 , V_5 ) )
F_135 ( V_224 , & V_257 ,
V_230 , 0 , 15 , 1 , 0 ) ;
F_135 ( V_224 , & V_257 ,
V_232 , 1 , 255 , 1 , V_3 -> V_20 ) ;
F_135 ( V_224 , & V_257 ,
V_233 , 0 , 31 , 1 , V_258 ) ;
F_137 ( V_224 , & V_257 ,
V_238 ,
V_259 , 0 ,
V_240 ) ;
F_135 ( V_224 , & V_257 ,
V_234 , 0 , 0xff , 1 ,
V_260 >> 8 ) ;
F_138 ( V_224 , & V_261 , NULL ) ;
V_2 -> V_241 =
F_138 ( V_224 , & V_262 , NULL ) ;
if ( V_224 -> error ) {
V_8 = V_224 -> error ;
goto V_263;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_5 = V_5 ;
F_139 ( & V_2 -> V_113 ) ;
F_140 ( & V_2 -> V_115 ) ;
F_100 ( & V_2 -> V_116 ) ;
V_2 -> V_93 = ( V_3 -> type == V_38 ) ?
V_94 : V_95 ;
V_2 -> type = V_124 ;
V_2 -> V_51 = V_258 ;
V_2 -> V_50 = V_3 -> V_20 ;
V_2 -> V_21 = 1 ;
V_2 -> V_18 = V_22 ;
V_2 -> V_236 = true ;
V_2 -> V_235 = V_260 ;
V_2 -> V_189 . type = V_264 ;
V_2 -> V_189 . V_265 = V_266 | V_267 | V_268 ;
V_2 -> V_189 . V_269 = & V_270 ;
V_2 -> V_189 . V_271 = & V_272 ;
V_2 -> V_189 . V_273 = V_2 ;
V_2 -> V_189 . V_274 = V_275 ;
V_2 -> V_189 . V_276 = V_277 ;
V_2 -> V_189 . V_278 = sizeof( struct V_112 ) ;
V_2 -> V_189 . V_113 = & V_2 -> V_113 ;
V_8 = F_141 ( & V_2 -> V_189 ) ;
if ( V_8 )
goto V_263;
F_10 ( V_2 ) ;
F_140 ( & V_2 -> V_9 ) ;
V_2 -> V_79 = sizeof( V_39 ) ;
memcpy ( V_2 -> V_39 , V_39 , V_2 -> V_79 ) ;
V_2 -> V_71 = 32 ;
V_2 -> V_70 = F_142 ( V_3 -> V_82 ,
sizeof( struct V_66 ) *
V_2 -> V_71 ,
& V_2 -> V_72 ) ;
V_8 = - V_87 ;
if ( V_2 -> V_70 == NULL )
goto V_263;
V_2 -> V_109 = F_143 () ;
if ( ! V_2 -> V_109 )
goto V_279;
* V_2 -> V_109 = V_280 ;
V_2 -> V_109 -> V_281 = & V_3 -> V_281 ;
V_2 -> V_109 -> V_282 = V_224 ;
V_2 -> V_109 -> V_283 = & V_2 -> V_189 ;
V_2 -> V_109 -> V_113 = & V_2 -> V_113 ;
F_144 ( V_2 -> V_109 , V_2 ) ;
V_8 = F_145 ( V_2 -> V_109 , V_284 , V_254 ) ;
if ( V_8 < 0 )
goto V_285;
snprintf ( V_2 -> V_109 -> V_165 , sizeof( V_2 -> V_109 -> V_165 ) ,
L_9 , V_146 , V_3 -> V_109 -> V_286 ,
V_2 -> V_109 -> V_286 ) ;
return V_2 ;
V_285:
F_146 ( V_2 -> V_109 ) ;
V_279:
F_147 ( V_2 -> V_3 -> V_82 ,
sizeof( struct V_66 ) * V_2 -> V_71 ,
V_2 -> V_70 , V_2 -> V_72 ) ;
V_263:
F_148 ( V_224 ) ;
F_149 ( V_2 ) ;
return F_133 ( V_8 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
F_151 ( V_2 -> V_109 ) ;
F_148 ( & V_2 -> V_224 ) ;
F_149 ( V_2 ) ;
}
int F_152 ( struct V_3 * V_3 , unsigned V_254 )
{
int V_63 ;
F_153 ( & V_3 -> V_118 ) ;
V_3 -> V_287 = sizeof( T_5 ) ;
V_3 -> V_127 = F_142 ( V_3 -> V_82 ,
V_3 -> V_287 ,
& V_3 -> V_126 ) ;
if ( V_3 -> V_127 == NULL )
return - V_87 ;
for ( V_63 = 0 ; V_63 < V_3 -> V_288 ; V_63 ++ ) {
V_3 -> V_125 [ V_63 ] = F_131 ( V_3 , V_63 , V_254 ) ;
if ( F_94 ( V_3 -> V_125 [ V_63 ] ) )
break;
}
if ( V_63 != V_3 -> V_288 ) {
int V_8 = F_95 ( V_3 -> V_125 [ V_63 ] ) ;
while ( V_63 -- )
F_150 ( V_3 -> V_125 [ V_63 ] ) ;
F_147 ( V_3 -> V_82 , V_3 -> V_287 ,
V_3 -> V_127 , V_3 -> V_126 ) ;
V_3 -> V_127 = NULL ;
return V_8 ;
}
if ( V_3 -> type == V_38 )
V_3 -> V_44 = V_3 -> V_20 * 4 * 4 ;
else
V_3 -> V_44 = V_3 -> V_20 * 4 * 5 ;
F_154 ( & V_3 -> V_82 -> V_83 , L_10 ,
V_3 -> V_125 [ 0 ] -> V_109 -> V_286 ,
V_3 -> V_125 [ V_3 -> V_288 - 1 ] -> V_109 -> V_286 ) ;
return 0 ;
}
void F_155 ( struct V_3 * V_3 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_3 -> V_288 ; V_63 ++ )
F_150 ( V_3 -> V_125 [ V_63 ] ) ;
if ( V_3 -> V_127 )
F_147 ( V_3 -> V_82 , V_3 -> V_287 ,
V_3 -> V_127 , V_3 -> V_126 ) ;
}
