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
T_2 * V_16 ;
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
T_3 V_20 = V_3 -> V_20 * 1000 ;
T_3 V_21 = V_2 -> V_21 * 1000 ;
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
T_2 V_5 = V_2 -> V_5 ;
struct V_3 * V_3 = V_2 -> V_3 ;
T_2 V_21 ;
F_10 ( V_2 ) ;
if ( V_2 -> V_19 > V_3 -> V_44 )
return - V_45 ;
V_2 -> V_46 = 0 ;
V_3 -> V_44 -= V_2 -> V_19 ;
if ( V_2 -> type == V_47 )
F_5 ( V_3 , F_14 ( V_5 ) , 1 ) ;
F_5 ( V_3 , F_15 ( V_5 ) , 0 ) ;
F_5 ( V_3 , F_16 ( V_5 ) ,
V_2 -> V_17 ? 1 : 0 ) ;
if ( V_2 -> V_17 )
V_21 = V_2 -> V_21 - 1 ;
else
V_21 = V_2 -> V_21 ;
F_5 ( V_3 , F_17 ( V_5 ) , V_2 -> V_48 ) ;
F_5 ( V_3 , F_18 ( V_5 ) , V_2 -> V_49 ) ;
F_5 ( V_3 , F_19 ( V_5 ) , V_21 ) ;
F_5 ( V_3 , F_20 ( V_5 ) , V_2 -> V_48 ) ;
F_5 ( V_3 , F_21 ( V_5 ) , V_2 -> V_49 ) ;
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
static int F_24 ( struct V_3 * V_3 , T_4 V_50 ,
unsigned int V_51 , unsigned int V_52 )
{
int V_8 ;
if ( V_51 > F_25 ( V_3 ) )
return - V_53 ;
if ( V_51 + V_52 <= F_25 ( V_3 ) ) {
return F_26 ( V_3 , 0 , V_50 ,
F_27 ( V_3 ) + V_51 , V_52 ,
0 , 0 ) ;
}
V_8 = F_26 ( V_3 , 0 , V_50 ,
F_27 ( V_3 ) + V_51 ,
F_25 ( V_3 ) - V_51 , 0 , 0 ) ;
if ( ! V_8 ) {
V_8 = F_26 ( V_3 , 0 ,
V_50 + F_25 ( V_3 ) - V_51 ,
F_27 ( V_3 ) ,
V_52 + V_51 - F_25 ( V_3 ) , 0 , 0 ) ;
}
return V_8 ;
}
static int F_28 ( struct V_1 * V_2 , int V_54 ,
struct V_55 * V_56 , int V_51 , int V_52 ,
unsigned int V_57 , unsigned int V_58 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_59 * V_60 ;
int V_61 ;
int V_8 ;
if ( F_29 ( V_52 > V_62 ) )
return - V_53 ;
V_2 -> V_63 = 1 ;
F_30 (vbuf->sgl, sg, vbuf->nents, i) {
struct V_64 * V_65 ;
T_4 V_50 ;
int V_66 ;
int V_67 = V_58 - V_51 ;
V_65 = & V_2 -> V_68 [ V_2 -> V_63 ++ ] ;
V_50 = F_31 ( V_60 ) ;
V_66 = F_32 ( V_60 ) ;
F_33 ( V_54 >= V_66 ) ;
if ( V_54 ) {
V_66 -= V_54 ;
V_50 += V_54 ;
V_52 -= V_54 ;
V_54 = 0 ;
}
V_66 = F_34 ( V_66 , V_52 ) ;
if ( V_66 <= V_67 ) {
F_35 ( V_65 , 0 , V_50 , V_57 + V_51 ,
V_66 , 0 , 0 ) ;
} else {
V_8 = F_26 ( V_3 , 0 , V_50 , V_57 + V_51 ,
V_67 , 0 , 0 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_26 ( V_3 , 0 , V_50 + V_67 , V_57 ,
V_66 - V_67 , 0 , 0 ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_63 -- ;
}
V_52 -= V_66 ;
if ( V_52 <= 0 )
break;
V_51 += V_66 ;
if ( V_51 >= V_58 )
V_51 -= V_58 ;
if ( V_2 -> V_63 >= ( V_2 -> V_69 - 1 ) ) {
V_8 = F_36 ( V_3 , V_2 -> V_68 ,
V_2 -> V_70 ,
V_2 -> V_63 - 1 ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_63 = 1 ;
}
}
if ( V_2 -> V_63 <= 1 )
return 0 ;
return F_36 ( V_3 , V_2 -> V_68 ,
V_2 -> V_70 , V_2 -> V_63 - 1 ) ;
}
static inline int F_37 ( const T_5 * V_71 )
{
return ( F_38 ( ( * V_71 ) [ 0 ] ) >> 30 ) & 1 ;
}
static inline T_2 F_39 ( const T_5 * V_71 )
{
return ( F_38 ( ( * V_71 ) [ 0 ] ) >> 24 ) & 0x1F ;
}
static inline T_2 F_40 ( const T_5 * V_71 )
{
return ( F_38 ( ( * V_71 ) [ 0 ] ) >> 22 ) & 3 ;
}
static inline T_1 F_41 ( const T_5 * V_71 )
{
return F_38 ( ( * V_71 ) [ 0 ] ) & 0xFFFFF ;
}
static inline T_2 F_42 ( const T_5 * V_71 )
{
return ( F_38 ( ( * V_71 ) [ 1 ] ) >> 8 ) & 0xFF ;
}
static inline T_2 F_43 ( const T_5 * V_71 )
{
return F_38 ( ( * V_71 ) [ 1 ] ) & 0xFF ;
}
static inline T_1 F_44 ( const T_5 * V_71 )
{
return F_38 ( ( * V_71 ) [ 2 ] ) ;
}
static inline T_1 F_45 ( const T_5 * V_71 )
{
return F_38 ( ( * V_71 ) [ 3 ] ) ;
}
static inline T_1 F_46 ( const T_5 * V_71 )
{
return F_38 ( ( * V_71 ) [ 4 ] ) & 0xFFFFF ;
}
static inline T_1 F_47 ( const T_5 * V_71 )
{
return F_38 ( ( * V_71 ) [ 5 ] ) ;
}
static inline T_1 F_48 ( const T_5 * V_71 )
{
return F_38 ( ( * V_71 ) [ 6 ] ) ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_72 * V_73 , const T_5 * V_71 )
{
struct V_74 * V_56 = F_50 ( V_73 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_55 * V_75 = F_51 ( V_73 , 0 ) ;
int V_76 ;
V_56 -> V_6 |= V_77 ;
if ( F_52 ( V_73 , 0 ) < F_46 ( V_71 ) + V_2 -> V_78 )
return - V_79 ;
V_76 = F_53 ( F_46 ( V_71 ) + V_2 -> V_78 , V_80 ) ;
F_54 ( V_73 , 0 , F_46 ( V_71 ) + V_2 -> V_78 ) ;
return F_28 ( V_2 , V_2 -> V_78 , V_75 ,
F_45 ( V_71 ) - F_55 ( V_3 ) ,
V_76 , F_55 ( V_3 ) ,
F_56 ( V_3 ) ) ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_72 * V_73 , const T_5 * V_71 )
{
struct V_74 * V_56 = F_50 ( V_73 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_55 * V_75 = F_51 ( V_73 , 0 ) ;
int V_81 , V_76 ;
int V_54 = 0 ;
if ( F_52 ( V_73 , 0 ) < F_41 ( V_71 ) )
return - V_79 ;
V_56 -> V_6 &= ~ ( V_77 | V_82 |
V_83 ) ;
if ( ! F_40 ( V_71 ) ) {
V_54 = V_2 -> V_15 ;
V_56 -> V_6 |= V_77 ;
F_54 ( V_73 , 0 , F_41 ( V_71 ) +
V_2 -> V_15 ) ;
} else {
V_56 -> V_6 |= V_82 ;
F_54 ( V_73 , 0 , F_41 ( V_71 ) ) ;
}
V_81 = ( F_44 ( V_71 ) - F_27 ( V_3 ) +
sizeof( * V_71 ) ) % F_25 ( V_3 ) ;
V_76 = F_53 ( F_41 ( V_71 ) + V_54 , V_80 ) ;
return F_28 ( V_2 , V_54 , V_75 , V_81 , V_76 ,
F_27 ( V_3 ) ,
F_25 ( V_3 ) ) ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_72 * V_73 , struct V_84 * V_85 )
{
struct V_74 * V_56 = F_50 ( V_73 ) ;
const T_5 * V_71 = V_85 -> V_71 ;
int V_8 ;
switch ( V_2 -> V_86 ) {
case V_87 :
case V_88 :
V_8 = F_57 ( V_2 , V_73 , V_71 ) ;
break;
default:
V_8 = F_49 ( V_2 , V_73 , V_71 ) ;
break;
}
if ( ! V_8 ) {
V_56 -> V_46 = V_2 -> V_46 ++ ;
V_56 -> V_89 . V_90 = F_47 ( V_71 ) ;
V_56 -> V_89 . V_91 = F_48 ( V_71 ) ;
if ( F_1 ( V_2 ) && V_85 -> V_92 ) {
struct V_93 V_94 = {
. type = V_95 ,
. V_96 . V_97 = {
. V_6
= V_98 ,
. V_99 = V_56 -> V_46 ,
. V_100 = V_85 -> V_92 ? 1 : 0 ,
} ,
} ;
F_59 ( V_2 -> V_101 , & V_94 ) ;
}
}
F_60 ( V_73 , V_8 ? V_102 : V_103 ) ;
return V_8 ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_104 * V_73 ;
unsigned long V_6 ;
F_62 ( & V_2 -> V_105 ) ;
if ( V_2 -> type != V_85 -> type )
goto V_106;
F_3 ( & V_2 -> V_107 , V_6 ) ;
if ( F_63 ( & V_2 -> V_108 ) ) {
F_6 ( & V_2 -> V_107 , V_6 ) ;
goto V_106;
}
V_73 = F_64 ( & V_2 -> V_108 , struct V_104 ,
V_109 ) ;
F_65 ( & V_73 -> V_109 ) ;
F_6 ( & V_2 -> V_107 , V_6 ) ;
F_58 ( V_2 , & V_73 -> V_73 . V_110 , V_85 ) ;
V_106:
F_66 ( & V_2 -> V_105 ) ;
}
void F_67 ( struct V_3 * V_3 )
{
F_68 ( & V_3 -> V_111 ) ;
}
static void F_69 ( struct V_3 * V_3 )
{
for (; ; ) {
struct V_1 * V_2 ;
struct V_84 V_85 ;
T_1 V_112 , V_51 ;
T_2 V_5 ;
T_2 V_113 ;
V_113 = F_4 ( V_3 , F_70 ( 11 ) ) & 0xff ;
if ( V_113 == V_3 -> V_114 )
break;
V_112 = F_4 ( V_3 ,
F_71 ( V_3 -> V_114 ) ) ;
V_3 -> V_114 = ( V_3 -> V_114 + 1 ) % V_115 ;
V_5 = ( V_112 >> 24 ) & 0x1f ;
V_51 = V_112 & 0x00ffffff ;
if ( V_5 >= V_116 ) {
V_5 -= V_116 ;
V_85 . type = V_47 ;
} else
V_85 . type = V_117 ;
V_2 = V_3 -> V_118 [ V_5 ] ;
if ( V_2 == NULL ) {
F_72 ( & V_3 -> V_119 -> V_120 ,
L_1 , V_5 ) ;
continue;
}
if ( F_24 ( V_3 , V_3 -> V_121 , V_51 ,
sizeof( T_5 ) ) )
continue;
V_85 . V_71 = V_3 -> V_122 ;
if ( F_44 ( V_85 . V_71 ) !=
F_27 ( V_3 ) + V_51 )
continue;
if ( F_2 ( V_2 ) )
V_85 . V_92 = 1 ;
else
V_85 . V_92 = 0 ;
F_61 ( V_2 , & V_85 ) ;
}
}
static int F_73 ( void * V_123 )
{
struct V_3 * V_3 = V_123 ;
F_74 ( V_124 , V_125 ) ;
F_75 () ;
F_76 ( & V_3 -> V_111 , & V_124 ) ;
for (; ; ) {
long V_126 = F_77 ( V_127 ) ;
if ( V_126 == - V_128 || F_78 () )
break;
F_69 ( V_3 ) ;
F_79 () ;
}
F_80 ( & V_3 -> V_111 , & V_124 ) ;
return 0 ;
}
static int F_81 ( struct V_129 * V_130 ,
const void * V_131 ,
unsigned int * V_132 ,
unsigned int * V_133 , unsigned int V_134 [] ,
void * V_135 [] )
{
struct V_1 * V_2 = F_82 ( V_130 ) ;
V_134 [ 0 ] = V_62 ;
V_135 [ 0 ] = V_2 -> V_136 ;
* V_133 = 1 ;
if ( * V_132 < V_137 )
* V_132 = V_137 ;
return 0 ;
}
static void F_83 ( struct V_72 * V_73 )
{
struct V_74 * V_56 = F_50 ( V_73 ) ;
struct V_129 * V_138 = V_73 -> V_129 ;
struct V_1 * V_2 = F_82 ( V_138 ) ;
struct V_104 * V_139 =
F_84 ( V_56 , struct V_104 , V_73 ) ;
F_85 ( & V_2 -> V_107 ) ;
F_86 ( & V_139 -> V_109 , & V_2 -> V_108 ) ;
F_87 ( & V_2 -> V_107 ) ;
}
static int F_88 ( struct V_3 * V_3 )
{
V_3 -> V_140 = F_89 ( F_73 , V_3 ,
V_141 L_2 ) ;
if ( F_90 ( V_3 -> V_140 ) ) {
int V_142 = F_91 ( V_3 -> V_140 ) ;
V_3 -> V_140 = NULL ;
return V_142 ;
}
F_92 ( V_3 , V_143 ) ;
return 0 ;
}
static void F_93 ( struct V_3 * V_3 )
{
if ( V_3 -> V_140 ) {
F_94 ( V_3 -> V_140 ) ;
V_3 -> V_140 = NULL ;
}
F_95 ( V_3 , V_143 ) ;
}
static int F_96 ( struct V_129 * V_130 , unsigned int V_144 )
{
struct V_1 * V_2 = F_82 ( V_130 ) ;
return F_13 ( V_2 ) ;
}
static void F_97 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = F_82 ( V_130 ) ;
unsigned long V_6 ;
F_3 ( & V_2 -> V_107 , V_6 ) ;
F_23 ( V_2 ) ;
while ( ! F_63 ( & V_2 -> V_108 ) ) {
struct V_104 * V_145 = F_98 (
V_2 -> V_108 . V_146 ,
struct V_104 , V_109 ) ;
F_65 ( & V_145 -> V_109 ) ;
F_60 ( & V_145 -> V_73 . V_110 , V_102 ) ;
}
F_6 ( & V_2 -> V_107 , V_6 ) ;
}
static void F_99 ( struct V_72 * V_73 )
{
struct V_74 * V_56 = F_50 ( V_73 ) ;
struct V_1 * V_2 = F_82 ( V_73 -> V_129 ) ;
struct V_55 * V_75 = F_51 ( V_73 , 0 ) ;
switch ( V_2 -> V_86 ) {
case V_87 :
case V_88 :
if ( V_56 -> V_6 & V_77 )
F_100 ( V_75 -> V_147 , V_75 -> V_148 ,
V_2 -> V_16 , V_2 -> V_15 ) ;
break;
default:
F_100 ( V_75 -> V_147 , V_75 -> V_148 ,
V_2 -> V_39 , V_2 -> V_78 ) ;
break;
}
}
static int F_101 ( struct V_149 * V_149 , void * V_150 ,
struct V_151 * V_152 )
{
struct V_1 * V_2 = F_102 ( V_149 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
strcpy ( V_152 -> V_153 , V_141 ) ;
snprintf ( V_152 -> V_154 , sizeof( V_152 -> V_154 ) , L_3 ,
V_2 -> V_5 ) ;
snprintf ( V_152 -> V_155 , sizeof( V_152 -> V_155 ) , L_4 ,
F_103 ( V_3 -> V_119 ) ) ;
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
return - V_53 ;
snprintf ( V_163 -> V_165 , sizeof( V_163 -> V_165 ) , L_5 ,
V_2 -> V_5 + 1 ) ;
V_163 -> type = V_166 ;
V_163 -> V_167 = V_2 -> V_101 -> V_168 ;
if ( ! F_105 ( V_3 , V_2 -> V_5 ) )
V_163 -> V_169 = V_170 ;
return 0 ;
}
static int F_106 ( struct V_149 * V_149 , void * V_150 ,
unsigned int V_164 )
{
if ( V_164 )
return - V_53 ;
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
V_172 -> V_174 = V_87 ;
strcpy ( V_172 -> V_175 , L_6 ) ;
break;
case V_27 :
V_172 -> V_174 = V_88 ;
strcpy ( V_172 -> V_175 , L_7 ) ;
break;
}
break;
case 1 :
V_172 -> V_174 = V_176 ;
strcpy ( V_172 -> V_175 , L_8 ) ;
break;
default:
return - V_53 ;
}
V_172 -> V_6 = V_177 ;
return 0 ;
}
static inline int F_109 ( T_1 V_178 , int V_173 )
{
return ( V_178 == V_88 && V_173 == V_27 )
|| ( V_178 == V_87 && V_173 == V_38 )
|| V_178 == V_176 ? 0 : - V_53 ;
}
static int F_110 ( struct V_149 * V_149 , void * V_150 ,
struct V_179 * V_172 )
{
struct V_1 * V_2 = F_102 ( V_149 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_180 * V_181 = & V_172 -> V_86 . V_181 ;
if ( F_109 ( V_181 -> V_174 , V_3 -> type ) )
return - V_53 ;
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
V_181 -> V_188 = V_62 ;
V_181 -> V_189 = 0 ;
V_181 -> V_150 = 0 ;
return 0 ;
}
static int F_111 ( struct V_149 * V_149 , void * V_150 ,
struct V_179 * V_172 )
{
struct V_1 * V_2 = F_102 ( V_149 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_180 * V_181 = & V_172 -> V_86 . V_181 ;
int V_8 ;
if ( F_112 ( & V_2 -> V_190 ) )
return - V_45 ;
V_8 = F_110 ( V_149 , V_150 , V_172 ) ;
if ( V_8 )
return V_8 ;
if ( V_181 -> V_23 == V_3 -> V_24 )
V_2 -> V_18 = V_191 ;
else
V_2 -> V_18 = V_22 ;
V_2 -> V_86 = V_181 -> V_174 ;
F_10 ( V_2 ) ;
return 0 ;
}
static int F_113 ( struct V_149 * V_149 , void * V_150 ,
struct V_179 * V_172 )
{
struct V_1 * V_2 = F_102 ( V_149 ) ;
struct V_180 * V_181 = & V_172 -> V_86 . V_181 ;
V_181 -> V_23 = V_2 -> V_23 ;
V_181 -> V_25 = V_2 -> V_25 ;
V_181 -> V_174 = V_2 -> V_86 ;
V_181 -> V_182 = V_2 -> V_17 ? V_184 :
V_183 ;
V_181 -> V_188 = V_62 ;
V_181 -> V_186 = V_187 ;
V_181 -> V_150 = 0 ;
return 0 ;
}
static int F_114 ( struct V_149 * V_149 , void * V_150 , T_6 * V_61 )
{
struct V_1 * V_2 = F_102 ( V_149 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( V_3 -> V_28 == V_29 )
* V_61 = V_192 ;
else
* V_61 = V_193 ;
return 0 ;
}
static int F_115 ( struct V_149 * V_149 , void * V_150 , T_6 V_167 )
{
struct V_1 * V_2 = F_102 ( V_149 ) ;
return F_116 ( V_2 -> V_3 , V_167 & V_194 ) ;
}
static int F_117 ( struct V_149 * V_149 , void * V_150 ,
struct V_195 * V_196 )
{
struct V_1 * V_2 = F_102 ( V_149 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( F_109 ( V_196 -> V_197 , V_3 -> type ) )
return - V_53 ;
switch ( V_196 -> V_164 ) {
case 0 :
V_196 -> V_198 . V_23 = V_3 -> V_24 >> 1 ;
V_196 -> V_198 . V_25 = V_3 -> V_26 ;
break;
case 1 :
V_196 -> V_198 . V_23 = V_3 -> V_24 ;
V_196 -> V_198 . V_25 = V_3 -> V_26 << 1 ;
break;
default:
return - V_53 ;
}
V_196 -> type = V_199 ;
return 0 ;
}
static int F_118 ( struct V_149 * V_149 , void * V_150 ,
struct V_200 * V_201 )
{
struct V_1 * V_2 = F_102 ( V_149 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( F_109 ( V_201 -> V_197 , V_3 -> type ) )
return - V_53 ;
if ( V_201 -> V_164 )
return - V_53 ;
if ( ( V_201 -> V_23 != V_3 -> V_24 >> 1 ||
V_201 -> V_25 != V_3 -> V_26 ) &&
( V_201 -> V_23 != V_3 -> V_24 ||
V_201 -> V_25 != V_3 -> V_26 << 1 ) )
return - V_53 ;
V_201 -> type = V_202 ;
V_201 -> V_203 . F_34 . V_204 = 1 ;
V_201 -> V_203 . F_34 . V_205 = V_3 -> V_20 ;
V_201 -> V_203 . F_11 . V_204 = 15 ;
V_201 -> V_203 . F_11 . V_205 = V_3 -> V_20 ;
V_201 -> V_203 . V_206 . V_204 = 1 ;
V_201 -> V_203 . V_206 . V_205 = V_3 -> V_20 ;
return 0 ;
}
static int F_119 ( struct V_149 * V_149 , void * V_150 ,
struct V_207 * V_208 )
{
struct V_1 * V_2 = F_102 ( V_149 ) ;
struct V_209 * V_210 = & V_208 -> V_211 . V_212 ;
V_210 -> V_213 = V_214 ;
V_210 -> V_215 . V_204 = V_2 -> V_21 ;
V_210 -> V_215 . V_205 = V_2 -> V_3 -> V_20 ;
V_210 -> V_216 = 0 ;
V_210 -> V_217 = 2 ;
return 0 ;
}
static inline int F_120 ( T_2 V_20 , T_1 V_218 , T_1 V_219 )
{
if ( ! V_218 || ! V_219 )
return 1 ;
if ( V_219 == V_20 )
return V_218 ;
V_218 *= V_20 ;
return F_34 ( 15U , V_218 / V_219 + ( V_218 % V_219 >= ( V_20 >> 1 ) ) ) ;
}
static int F_121 ( struct V_149 * V_149 , void * V_150 ,
struct V_207 * V_208 )
{
struct V_1 * V_2 = F_102 ( V_149 ) ;
struct V_220 * V_221 = & V_208 -> V_211 . V_212 . V_215 ;
T_2 V_20 = V_2 -> V_3 -> V_20 ;
if ( F_122 ( & V_2 -> V_190 ) )
return - V_45 ;
V_2 -> V_21 = F_120 ( V_20 , V_221 -> V_204 , V_221 -> V_205 ) ;
F_10 ( V_2 ) ;
return F_119 ( V_149 , V_150 , V_208 ) ;
}
static int F_123 ( struct V_222 * V_223 )
{
struct V_1 * V_2 =
F_84 ( V_223 -> V_224 , struct V_1 , V_225 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
int V_142 ;
switch ( V_223 -> V_226 ) {
case V_227 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
return F_124 ( V_3 , V_223 -> V_226 , V_2 -> V_5 ,
V_223 -> V_232 ) ;
case V_233 :
V_2 -> V_48 = V_223 -> V_232 ;
F_5 ( V_3 , F_17 ( V_2 -> V_5 ) , V_2 -> V_48 ) ;
F_5 ( V_3 , F_20 ( V_2 -> V_5 ) , V_2 -> V_48 ) ;
return 0 ;
case V_234 :
V_2 -> V_49 = V_223 -> V_232 ;
F_5 ( V_3 , F_18 ( V_2 -> V_5 ) , V_2 -> V_49 ) ;
F_5 ( V_3 , F_21 ( V_2 -> V_5 ) , V_2 -> V_49 ) ;
return 0 ;
case V_235 :
V_2 -> V_236 = V_223 -> V_232 << 8 ;
if ( ! V_2 -> V_237 || ! V_2 -> V_238 )
return 0 ;
return F_125 ( V_3 , V_2 -> V_5 ,
V_2 -> V_236 ) ;
case V_239 :
V_2 -> V_237 = V_223 -> V_232 == V_240 ;
V_2 -> V_238 = V_223 -> V_232 > V_241 ;
if ( V_223 -> V_232 ) {
if ( V_2 -> V_237 )
V_142 = F_125 ( V_3 , V_2 -> V_5 ,
V_2 -> V_236 ) ;
else
V_142 = F_126 ( V_3 , V_2 -> V_5 ,
V_2 -> V_242 -> V_243 . V_244 ) ;
if ( V_142 )
return V_142 ;
}
F_7 ( V_2 , V_223 -> V_232 ) ;
return 0 ;
case V_245 :
if ( V_2 -> V_238 && ! V_2 -> V_237 )
return F_126 ( V_3 , V_2 -> V_5 ,
V_2 -> V_242 -> V_246 . V_244 ) ;
break;
case V_247 :
strcpy ( V_2 -> V_248 , V_223 -> V_246 . V_249 ) ;
return F_127 ( V_2 ) ;
default:
return - V_53 ;
}
return 0 ;
}
static int F_128 ( struct V_250 * V_251 ,
const struct V_252 * V_253 )
{
switch ( V_253 -> type ) {
case V_254 :
return F_129 ( V_251 , V_253 ) ;
case V_95 :
return F_130 ( V_251 , V_253 , 30 , NULL ) ;
}
return - V_53 ;
}
static struct V_1 * F_131 ( struct V_3 * V_3 ,
T_2 V_5 , unsigned V_255 )
{
struct V_1 * V_2 ;
struct V_256 * V_225 ;
int V_8 ;
V_2 = F_132 ( sizeof( * V_2 ) , V_257 ) ;
if ( ! V_2 )
return F_133 ( - V_258 ) ;
V_225 = & V_2 -> V_225 ;
V_2 -> V_136 = F_134 ( & V_3 -> V_119 -> V_120 ) ;
if ( F_90 ( V_2 -> V_136 ) ) {
V_8 = F_91 ( V_2 -> V_136 ) ;
goto V_259;
}
F_135 ( V_225 , 10 ) ;
F_136 ( V_225 , & V_260 ,
V_227 , 0 , 255 , 1 , 128 ) ;
F_136 ( V_225 , & V_260 ,
V_228 , 0 , 255 , 1 , 128 ) ;
F_136 ( V_225 , & V_260 ,
V_229 , 0 , 255 , 1 , 128 ) ;
F_136 ( V_225 , & V_260 ,
V_230 , 0 , 255 , 1 , 128 ) ;
if ( F_137 ( V_3 , V_5 ) )
F_136 ( V_225 , & V_260 ,
V_231 , 0 , 15 , 1 , 0 ) ;
F_136 ( V_225 , & V_260 ,
V_233 , 1 , 255 , 1 , V_3 -> V_20 ) ;
F_136 ( V_225 , & V_260 ,
V_234 , 0 , 31 , 1 , V_261 ) ;
F_138 ( V_225 , & V_260 ,
V_239 ,
V_262 , 0 ,
V_241 ) ;
F_136 ( V_225 , & V_260 ,
V_235 , 0 , 0xff , 1 ,
V_263 >> 8 ) ;
F_139 ( V_225 , & V_264 , NULL ) ;
V_2 -> V_242 =
F_139 ( V_225 , & V_265 , NULL ) ;
if ( V_225 -> error ) {
V_8 = V_225 -> error ;
goto V_259;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_5 = V_5 ;
F_140 ( & V_2 -> V_105 ) ;
F_141 ( & V_2 -> V_107 ) ;
F_142 ( & V_2 -> V_108 ) ;
V_2 -> V_86 = ( V_3 -> type == V_38 ) ?
V_87 : V_88 ;
V_2 -> type = V_117 ;
V_2 -> V_49 = V_261 ;
V_2 -> V_48 = V_3 -> V_20 ;
V_2 -> V_21 = 1 ;
V_2 -> V_18 = V_22 ;
V_2 -> V_237 = true ;
V_2 -> V_236 = V_263 ;
V_2 -> V_190 . type = V_266 ;
V_2 -> V_190 . V_267 = V_268 | V_269 | V_270 ;
V_2 -> V_190 . V_271 = & V_272 ;
V_2 -> V_190 . V_273 = & V_274 ;
V_2 -> V_190 . V_275 = V_2 ;
V_2 -> V_190 . V_276 = V_277 | V_278 ;
V_2 -> V_190 . V_279 = V_280 ;
V_2 -> V_190 . V_281 = sizeof( struct V_104 ) ;
V_2 -> V_190 . V_105 = & V_2 -> V_105 ;
V_8 = F_143 ( & V_2 -> V_190 ) ;
if ( V_8 )
goto V_259;
F_10 ( V_2 ) ;
F_141 ( & V_2 -> V_9 ) ;
V_2 -> V_78 = sizeof( V_39 ) ;
memcpy ( V_2 -> V_39 , V_39 , V_2 -> V_78 ) ;
V_2 -> V_69 = 32 ;
V_2 -> V_68 = F_144 ( V_3 -> V_119 ,
sizeof( struct V_64 ) *
V_2 -> V_69 ,
& V_2 -> V_70 ) ;
V_8 = - V_258 ;
if ( V_2 -> V_68 == NULL )
goto V_259;
V_2 -> V_101 = F_145 () ;
if ( ! V_2 -> V_101 )
goto V_282;
* V_2 -> V_101 = V_283 ;
V_2 -> V_101 -> V_284 = & V_3 -> V_284 ;
V_2 -> V_101 -> V_285 = V_225 ;
V_2 -> V_101 -> V_286 = & V_2 -> V_190 ;
V_2 -> V_101 -> V_105 = & V_2 -> V_105 ;
F_146 ( V_2 -> V_101 , V_2 ) ;
V_8 = F_147 ( V_2 -> V_101 , V_287 , V_255 ) ;
if ( V_8 < 0 )
goto V_288;
snprintf ( V_2 -> V_101 -> V_165 , sizeof( V_2 -> V_101 -> V_165 ) ,
L_9 , V_141 , V_3 -> V_101 -> V_289 ,
V_2 -> V_101 -> V_289 ) ;
return V_2 ;
V_288:
F_148 ( V_2 -> V_101 ) ;
V_282:
F_149 ( V_2 -> V_3 -> V_119 ,
sizeof( struct V_64 ) * V_2 -> V_69 ,
V_2 -> V_68 , V_2 -> V_70 ) ;
V_259:
F_150 ( V_225 ) ;
F_151 ( V_2 -> V_136 ) ;
F_152 ( V_2 ) ;
return F_133 ( V_8 ) ;
}
static void F_153 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
F_149 ( V_2 -> V_3 -> V_119 ,
sizeof( struct V_64 ) * V_2 -> V_69 ,
V_2 -> V_68 , V_2 -> V_70 ) ;
F_154 ( V_2 -> V_101 ) ;
F_150 ( & V_2 -> V_225 ) ;
F_151 ( V_2 -> V_136 ) ;
F_152 ( V_2 ) ;
}
int F_155 ( struct V_3 * V_3 , unsigned V_255 )
{
int V_61 ;
F_156 ( & V_3 -> V_111 ) ;
V_3 -> V_290 = sizeof( T_5 ) ;
V_3 -> V_122 = F_144 ( V_3 -> V_119 ,
V_3 -> V_290 ,
& V_3 -> V_121 ) ;
if ( V_3 -> V_122 == NULL )
return - V_258 ;
for ( V_61 = 0 ; V_61 < V_3 -> V_291 ; V_61 ++ ) {
V_3 -> V_118 [ V_61 ] = F_131 ( V_3 , V_61 , V_255 ) ;
if ( F_90 ( V_3 -> V_118 [ V_61 ] ) )
break;
}
if ( V_61 != V_3 -> V_291 ) {
int V_8 = F_91 ( V_3 -> V_118 [ V_61 ] ) ;
while ( V_61 -- )
F_153 ( V_3 -> V_118 [ V_61 ] ) ;
F_149 ( V_3 -> V_119 , V_3 -> V_290 ,
V_3 -> V_122 , V_3 -> V_121 ) ;
V_3 -> V_122 = NULL ;
return V_8 ;
}
if ( V_3 -> type == V_38 )
V_3 -> V_44 = V_3 -> V_20 * 4 * 4 ;
else
V_3 -> V_44 = V_3 -> V_20 * 4 * 5 ;
F_157 ( & V_3 -> V_119 -> V_120 , L_10 ,
V_3 -> V_118 [ 0 ] -> V_101 -> V_289 ,
V_3 -> V_118 [ V_3 -> V_291 - 1 ] -> V_101 -> V_289 ) ;
return F_88 ( V_3 ) ;
}
void F_158 ( struct V_3 * V_3 )
{
int V_61 ;
F_93 ( V_3 ) ;
for ( V_61 = 0 ; V_61 < V_3 -> V_291 ; V_61 ++ )
F_153 ( V_3 -> V_118 [ V_61 ] ) ;
if ( V_3 -> V_122 )
F_149 ( V_3 -> V_119 , V_3 -> V_290 ,
V_3 -> V_122 , V_3 -> V_121 ) ;
}
