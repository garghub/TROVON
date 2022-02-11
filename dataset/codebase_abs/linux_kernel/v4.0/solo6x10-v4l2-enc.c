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
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_55 * V_56 = F_50 ( V_73 , 0 ) ;
int V_74 ;
V_73 -> V_75 . V_6 |= V_76 ;
if ( F_51 ( V_73 , 0 ) < F_46 ( V_71 ) + V_2 -> V_77 )
return - V_78 ;
V_74 = F_52 ( F_46 ( V_71 ) + V_2 -> V_77 , V_79 ) ;
F_53 ( V_73 , 0 , F_46 ( V_71 ) + V_2 -> V_77 ) ;
return F_28 ( V_2 , V_2 -> V_77 , V_56 ,
F_45 ( V_71 ) - F_54 ( V_3 ) ,
V_74 , F_54 ( V_3 ) ,
F_55 ( V_3 ) ) ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_72 * V_73 , const T_5 * V_71 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_55 * V_56 = F_50 ( V_73 , 0 ) ;
int V_80 , V_74 ;
int V_54 = 0 ;
if ( F_51 ( V_73 , 0 ) < F_41 ( V_71 ) )
return - V_78 ;
V_73 -> V_75 . V_6 &= ~ ( V_76 | V_81 |
V_82 ) ;
if ( ! F_40 ( V_71 ) ) {
V_54 = V_2 -> V_15 ;
V_73 -> V_75 . V_6 |= V_76 ;
F_53 ( V_73 , 0 , F_41 ( V_71 ) +
V_2 -> V_15 ) ;
} else {
V_73 -> V_75 . V_6 |= V_81 ;
F_53 ( V_73 , 0 , F_41 ( V_71 ) ) ;
}
V_80 = ( F_44 ( V_71 ) - F_27 ( V_3 ) +
sizeof( * V_71 ) ) % F_25 ( V_3 ) ;
V_74 = F_52 ( F_41 ( V_71 ) + V_54 , V_79 ) ;
return F_28 ( V_2 , V_54 , V_56 , V_80 , V_74 ,
F_27 ( V_3 ) ,
F_25 ( V_3 ) ) ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_72 * V_73 , struct V_83 * V_84 )
{
const T_5 * V_71 = V_84 -> V_71 ;
int V_8 ;
switch ( V_2 -> V_85 ) {
case V_86 :
case V_87 :
V_8 = F_56 ( V_2 , V_73 , V_71 ) ;
break;
default:
V_8 = F_49 ( V_2 , V_73 , V_71 ) ;
break;
}
if ( ! V_8 ) {
V_73 -> V_75 . V_46 = V_2 -> V_46 ++ ;
V_73 -> V_75 . V_88 . V_89 = F_47 ( V_71 ) ;
V_73 -> V_75 . V_88 . V_90 = F_48 ( V_71 ) ;
if ( F_1 ( V_2 ) && V_84 -> V_91 ) {
struct V_92 V_93 = {
. type = V_94 ,
. V_95 . V_96 = {
. V_6 = V_97 ,
. V_98 = V_73 -> V_75 . V_46 ,
. V_99 = V_84 -> V_91 ? 1 : 0 ,
} ,
} ;
F_58 ( V_2 -> V_100 , & V_93 ) ;
}
}
F_59 ( V_73 , V_8 ? V_101 : V_102 ) ;
return V_8 ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_83 * V_84 )
{
struct V_103 * V_73 ;
unsigned long V_6 ;
F_61 ( & V_2 -> V_104 ) ;
if ( V_2 -> type != V_84 -> type )
goto V_105;
F_3 ( & V_2 -> V_106 , V_6 ) ;
if ( F_62 ( & V_2 -> V_107 ) ) {
F_6 ( & V_2 -> V_106 , V_6 ) ;
goto V_105;
}
V_73 = F_63 ( & V_2 -> V_107 , struct V_103 ,
V_108 ) ;
F_64 ( & V_73 -> V_108 ) ;
F_6 ( & V_2 -> V_106 , V_6 ) ;
F_57 ( V_2 , & V_73 -> V_73 , V_84 ) ;
V_105:
F_65 ( & V_2 -> V_104 ) ;
}
void F_66 ( struct V_3 * V_3 )
{
F_67 ( & V_3 -> V_109 ) ;
}
static void F_68 ( struct V_3 * V_3 )
{
for (; ; ) {
struct V_1 * V_2 ;
struct V_83 V_84 ;
T_1 V_110 , V_51 ;
T_2 V_5 ;
T_2 V_111 ;
V_111 = F_4 ( V_3 , F_69 ( 11 ) ) & 0xff ;
if ( V_111 == V_3 -> V_112 )
break;
V_110 = F_4 ( V_3 ,
F_70 ( V_3 -> V_112 ) ) ;
V_3 -> V_112 = ( V_3 -> V_112 + 1 ) % V_113 ;
V_5 = ( V_110 >> 24 ) & 0x1f ;
V_51 = V_110 & 0x00ffffff ;
if ( V_5 >= V_114 ) {
V_5 -= V_114 ;
V_84 . type = V_47 ;
} else
V_84 . type = V_115 ;
V_2 = V_3 -> V_116 [ V_5 ] ;
if ( V_2 == NULL ) {
F_71 ( & V_3 -> V_117 -> V_118 ,
L_1 , V_5 ) ;
continue;
}
if ( F_24 ( V_3 , V_3 -> V_119 , V_51 ,
sizeof( T_5 ) ) )
continue;
V_84 . V_71 = V_3 -> V_120 ;
if ( F_44 ( V_84 . V_71 ) !=
F_27 ( V_3 ) + V_51 )
continue;
if ( F_2 ( V_2 ) )
V_84 . V_91 = 1 ;
else
V_84 . V_91 = 0 ;
F_60 ( V_2 , & V_84 ) ;
}
}
static int F_72 ( void * V_121 )
{
struct V_3 * V_3 = V_121 ;
F_73 ( V_122 , V_123 ) ;
F_74 () ;
F_75 ( & V_3 -> V_109 , & V_122 ) ;
for (; ; ) {
long V_124 = F_76 ( V_125 ) ;
if ( V_124 == - V_126 || F_77 () )
break;
F_68 ( V_3 ) ;
F_78 () ;
}
F_79 ( & V_3 -> V_109 , & V_122 ) ;
return 0 ;
}
static int F_80 ( struct V_127 * V_128 ,
const struct V_129 * V_85 ,
unsigned int * V_130 ,
unsigned int * V_131 , unsigned int V_132 [] ,
void * V_133 [] )
{
struct V_1 * V_2 = F_81 ( V_128 ) ;
V_132 [ 0 ] = V_62 ;
V_133 [ 0 ] = V_2 -> V_134 ;
* V_131 = 1 ;
if ( * V_130 < V_135 )
* V_130 = V_135 ;
return 0 ;
}
static void F_82 ( struct V_72 * V_73 )
{
struct V_127 * V_136 = V_73 -> V_127 ;
struct V_1 * V_2 = F_81 ( V_136 ) ;
struct V_103 * V_137 =
F_83 ( V_73 , struct V_103 , V_73 ) ;
F_84 ( & V_2 -> V_106 ) ;
F_85 ( & V_137 -> V_108 , & V_2 -> V_107 ) ;
F_86 ( & V_2 -> V_106 ) ;
}
static int F_87 ( struct V_3 * V_3 )
{
V_3 -> V_138 = F_88 ( F_72 , V_3 ,
V_139 L_2 ) ;
if ( F_89 ( V_3 -> V_138 ) ) {
int V_140 = F_90 ( V_3 -> V_138 ) ;
V_3 -> V_138 = NULL ;
return V_140 ;
}
F_91 ( V_3 , V_141 ) ;
return 0 ;
}
static void F_92 ( struct V_3 * V_3 )
{
if ( V_3 -> V_138 ) {
F_93 ( V_3 -> V_138 ) ;
V_3 -> V_138 = NULL ;
}
F_94 ( V_3 , V_141 ) ;
}
static int F_95 ( struct V_127 * V_128 , unsigned int V_142 )
{
struct V_1 * V_2 = F_81 ( V_128 ) ;
return F_13 ( V_2 ) ;
}
static void F_96 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_81 ( V_128 ) ;
unsigned long V_6 ;
F_3 ( & V_2 -> V_106 , V_6 ) ;
F_23 ( V_2 ) ;
while ( ! F_62 ( & V_2 -> V_107 ) ) {
struct V_103 * V_143 = F_97 (
V_2 -> V_107 . V_144 ,
struct V_103 , V_108 ) ;
F_64 ( & V_143 -> V_108 ) ;
F_59 ( & V_143 -> V_73 , V_101 ) ;
}
F_6 ( & V_2 -> V_106 , V_6 ) ;
}
static void F_98 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_81 ( V_73 -> V_127 ) ;
struct V_55 * V_56 = F_50 ( V_73 , 0 ) ;
switch ( V_2 -> V_85 ) {
case V_86 :
case V_87 :
if ( V_73 -> V_75 . V_6 & V_76 )
F_99 ( V_56 -> V_145 , V_56 -> V_146 ,
V_2 -> V_16 , V_2 -> V_15 ) ;
break;
default:
F_99 ( V_56 -> V_145 , V_56 -> V_146 ,
V_2 -> V_39 , V_2 -> V_77 ) ;
break;
}
}
static int F_100 ( struct V_147 * V_147 , void * V_148 ,
struct V_149 * V_150 )
{
struct V_1 * V_2 = F_101 ( V_147 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
strcpy ( V_150 -> V_151 , V_139 ) ;
snprintf ( V_150 -> V_152 , sizeof( V_150 -> V_152 ) , L_3 ,
V_2 -> V_5 ) ;
snprintf ( V_150 -> V_153 , sizeof( V_150 -> V_153 ) , L_4 ,
F_102 ( V_3 -> V_117 ) ) ;
V_150 -> V_154 = V_155 |
V_156 | V_157 ;
V_150 -> V_158 = V_150 -> V_154 | V_159 ;
return 0 ;
}
static int F_103 ( struct V_147 * V_147 , void * V_148 ,
struct V_160 * V_161 )
{
struct V_1 * V_2 = F_101 ( V_147 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( V_161 -> V_162 )
return - V_53 ;
snprintf ( V_161 -> V_163 , sizeof( V_161 -> V_163 ) , L_5 ,
V_2 -> V_5 + 1 ) ;
V_161 -> type = V_164 ;
V_161 -> V_165 = V_2 -> V_100 -> V_166 ;
if ( ! F_104 ( V_3 , V_2 -> V_5 ) )
V_161 -> V_167 = V_168 ;
return 0 ;
}
static int F_105 ( struct V_147 * V_147 , void * V_148 ,
unsigned int V_162 )
{
if ( V_162 )
return - V_53 ;
return 0 ;
}
static int F_106 ( struct V_147 * V_147 , void * V_148 ,
unsigned int * V_162 )
{
* V_162 = 0 ;
return 0 ;
}
static int F_107 ( struct V_147 * V_147 , void * V_148 ,
struct V_169 * V_170 )
{
struct V_1 * V_2 = F_101 ( V_147 ) ;
int V_171 = V_2 -> V_3 -> type ;
switch ( V_170 -> V_162 ) {
case 0 :
switch ( V_171 ) {
case V_38 :
V_170 -> V_172 = V_86 ;
strcpy ( V_170 -> V_173 , L_6 ) ;
break;
case V_27 :
V_170 -> V_172 = V_87 ;
strcpy ( V_170 -> V_173 , L_7 ) ;
break;
}
break;
case 1 :
V_170 -> V_172 = V_174 ;
strcpy ( V_170 -> V_173 , L_8 ) ;
break;
default:
return - V_53 ;
}
V_170 -> V_6 = V_175 ;
return 0 ;
}
static inline int F_108 ( T_1 V_176 , int V_171 )
{
return ( V_176 == V_87 && V_171 == V_27 )
|| ( V_176 == V_86 && V_171 == V_38 )
|| V_176 == V_174 ? 0 : - V_53 ;
}
static int F_109 ( struct V_147 * V_147 , void * V_148 ,
struct V_129 * V_170 )
{
struct V_1 * V_2 = F_101 ( V_147 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_177 * V_178 = & V_170 -> V_85 . V_178 ;
if ( F_108 ( V_178 -> V_172 , V_3 -> type ) )
return - V_53 ;
if ( V_178 -> V_23 < V_3 -> V_24 ||
V_178 -> V_25 < V_3 -> V_26 << 1 ) {
V_178 -> V_23 = V_3 -> V_24 >> 1 ;
V_178 -> V_25 = V_3 -> V_26 ;
} else {
V_178 -> V_23 = V_3 -> V_24 ;
V_178 -> V_25 = V_3 -> V_26 << 1 ;
}
switch ( V_178 -> V_179 ) {
case V_180 :
case V_181 :
break;
case V_182 :
default:
V_178 -> V_179 = V_181 ;
break;
}
V_178 -> V_183 = V_184 ;
V_178 -> V_185 = V_62 ;
V_178 -> V_186 = 0 ;
V_178 -> V_148 = 0 ;
return 0 ;
}
static int F_110 ( struct V_147 * V_147 , void * V_148 ,
struct V_129 * V_170 )
{
struct V_1 * V_2 = F_101 ( V_147 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_177 * V_178 = & V_170 -> V_85 . V_178 ;
int V_8 ;
if ( F_111 ( & V_2 -> V_187 ) )
return - V_45 ;
V_8 = F_109 ( V_147 , V_148 , V_170 ) ;
if ( V_8 )
return V_8 ;
if ( V_178 -> V_23 == V_3 -> V_24 )
V_2 -> V_18 = V_188 ;
else
V_2 -> V_18 = V_22 ;
V_2 -> V_85 = V_178 -> V_172 ;
F_10 ( V_2 ) ;
return 0 ;
}
static int F_112 ( struct V_147 * V_147 , void * V_148 ,
struct V_129 * V_170 )
{
struct V_1 * V_2 = F_101 ( V_147 ) ;
struct V_177 * V_178 = & V_170 -> V_85 . V_178 ;
V_178 -> V_23 = V_2 -> V_23 ;
V_178 -> V_25 = V_2 -> V_25 ;
V_178 -> V_172 = V_2 -> V_85 ;
V_178 -> V_179 = V_2 -> V_17 ? V_181 :
V_180 ;
V_178 -> V_185 = V_62 ;
V_178 -> V_183 = V_184 ;
V_178 -> V_148 = 0 ;
return 0 ;
}
static int F_113 ( struct V_147 * V_147 , void * V_148 , T_6 * V_61 )
{
struct V_1 * V_2 = F_101 ( V_147 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( V_3 -> V_28 == V_29 )
* V_61 = V_189 ;
else
* V_61 = V_190 ;
return 0 ;
}
static int F_114 ( struct V_147 * V_147 , void * V_148 , T_6 V_165 )
{
struct V_1 * V_2 = F_101 ( V_147 ) ;
return F_115 ( V_2 -> V_3 , V_165 & V_191 ) ;
}
static int F_116 ( struct V_147 * V_147 , void * V_148 ,
struct V_192 * V_193 )
{
struct V_1 * V_2 = F_101 ( V_147 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( F_108 ( V_193 -> V_194 , V_3 -> type ) )
return - V_53 ;
switch ( V_193 -> V_162 ) {
case 0 :
V_193 -> V_195 . V_23 = V_3 -> V_24 >> 1 ;
V_193 -> V_195 . V_25 = V_3 -> V_26 ;
break;
case 1 :
V_193 -> V_195 . V_23 = V_3 -> V_24 ;
V_193 -> V_195 . V_25 = V_3 -> V_26 << 1 ;
break;
default:
return - V_53 ;
}
V_193 -> type = V_196 ;
return 0 ;
}
static int F_117 ( struct V_147 * V_147 , void * V_148 ,
struct V_197 * V_198 )
{
struct V_1 * V_2 = F_101 ( V_147 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( F_108 ( V_198 -> V_194 , V_3 -> type ) )
return - V_53 ;
if ( V_198 -> V_162 )
return - V_53 ;
if ( ( V_198 -> V_23 != V_3 -> V_24 >> 1 ||
V_198 -> V_25 != V_3 -> V_26 ) &&
( V_198 -> V_23 != V_3 -> V_24 ||
V_198 -> V_25 != V_3 -> V_26 << 1 ) )
return - V_53 ;
V_198 -> type = V_199 ;
V_198 -> V_200 . F_34 . V_201 = 1 ;
V_198 -> V_200 . F_34 . V_202 = V_3 -> V_20 ;
V_198 -> V_200 . F_11 . V_201 = 15 ;
V_198 -> V_200 . F_11 . V_202 = V_3 -> V_20 ;
V_198 -> V_200 . V_203 . V_201 = 1 ;
V_198 -> V_200 . V_203 . V_202 = V_3 -> V_20 ;
return 0 ;
}
static int F_118 ( struct V_147 * V_147 , void * V_148 ,
struct V_204 * V_205 )
{
struct V_1 * V_2 = F_101 ( V_147 ) ;
struct V_206 * V_207 = & V_205 -> V_208 . V_209 ;
V_207 -> V_210 = V_211 ;
V_207 -> V_212 . V_201 = V_2 -> V_21 ;
V_207 -> V_212 . V_202 = V_2 -> V_3 -> V_20 ;
V_207 -> V_213 = 0 ;
V_207 -> V_214 = 2 ;
return 0 ;
}
static inline int F_119 ( T_2 V_20 , T_1 V_215 , T_1 V_216 )
{
if ( ! V_215 || ! V_216 )
return 1 ;
if ( V_216 == V_20 )
return V_215 ;
V_215 *= V_20 ;
return F_34 ( 15U , V_215 / V_216 + ( V_215 % V_216 >= ( V_20 >> 1 ) ) ) ;
}
static int F_120 ( struct V_147 * V_147 , void * V_148 ,
struct V_204 * V_205 )
{
struct V_1 * V_2 = F_101 ( V_147 ) ;
struct V_217 * V_218 = & V_205 -> V_208 . V_209 . V_212 ;
T_2 V_20 = V_2 -> V_3 -> V_20 ;
if ( F_121 ( & V_2 -> V_187 ) )
return - V_45 ;
V_2 -> V_21 = F_119 ( V_20 , V_218 -> V_201 , V_218 -> V_202 ) ;
F_10 ( V_2 ) ;
return F_118 ( V_147 , V_148 , V_205 ) ;
}
static int F_122 ( struct V_219 * V_220 )
{
struct V_1 * V_2 =
F_83 ( V_220 -> V_221 , struct V_1 , V_222 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
int V_140 ;
switch ( V_220 -> V_223 ) {
case V_224 :
case V_225 :
case V_226 :
case V_227 :
case V_228 :
return F_123 ( V_3 , V_220 -> V_223 , V_2 -> V_5 ,
V_220 -> V_229 ) ;
case V_230 :
V_2 -> V_48 = V_220 -> V_229 ;
F_5 ( V_3 , F_17 ( V_2 -> V_5 ) , V_2 -> V_48 ) ;
F_5 ( V_3 , F_20 ( V_2 -> V_5 ) , V_2 -> V_48 ) ;
return 0 ;
case V_231 :
V_2 -> V_49 = V_220 -> V_229 ;
F_5 ( V_3 , F_18 ( V_2 -> V_5 ) , V_2 -> V_49 ) ;
F_5 ( V_3 , F_21 ( V_2 -> V_5 ) , V_2 -> V_49 ) ;
return 0 ;
case V_232 :
V_2 -> V_233 = V_220 -> V_229 << 8 ;
if ( ! V_2 -> V_234 || ! V_2 -> V_235 )
return 0 ;
return F_124 ( V_3 , V_2 -> V_5 ,
V_2 -> V_233 ) ;
case V_236 :
V_2 -> V_234 = V_220 -> V_229 == V_237 ;
V_2 -> V_235 = V_220 -> V_229 > V_238 ;
if ( V_220 -> V_229 ) {
if ( V_2 -> V_234 )
V_140 = F_124 ( V_3 , V_2 -> V_5 ,
V_2 -> V_233 ) ;
else
V_140 = F_125 ( V_3 , V_2 -> V_5 ,
V_2 -> V_239 -> V_240 . V_241 ) ;
if ( V_140 )
return V_140 ;
}
F_7 ( V_2 , V_220 -> V_229 ) ;
return 0 ;
case V_242 :
if ( V_2 -> V_235 && ! V_2 -> V_234 )
return F_125 ( V_3 , V_2 -> V_5 ,
V_2 -> V_239 -> V_243 . V_241 ) ;
break;
case V_244 :
strcpy ( V_2 -> V_245 , V_220 -> V_243 . V_246 ) ;
return F_126 ( V_2 ) ;
default:
return - V_53 ;
}
return 0 ;
}
static int F_127 ( struct V_247 * V_248 ,
const struct V_249 * V_250 )
{
switch ( V_250 -> type ) {
case V_251 :
return F_128 ( V_248 , V_250 ) ;
case V_94 :
return F_129 ( V_248 , V_250 , 30 , NULL ) ;
}
return - V_53 ;
}
static struct V_1 * F_130 ( struct V_3 * V_3 ,
T_2 V_5 , unsigned V_252 )
{
struct V_1 * V_2 ;
struct V_253 * V_222 ;
int V_8 ;
V_2 = F_131 ( sizeof( * V_2 ) , V_254 ) ;
if ( ! V_2 )
return F_132 ( - V_255 ) ;
V_222 = & V_2 -> V_222 ;
V_2 -> V_134 = F_133 ( & V_3 -> V_117 -> V_118 ) ;
if ( F_89 ( V_2 -> V_134 ) ) {
V_8 = F_90 ( V_2 -> V_134 ) ;
goto V_256;
}
F_134 ( V_222 , 10 ) ;
F_135 ( V_222 , & V_257 ,
V_224 , 0 , 255 , 1 , 128 ) ;
F_135 ( V_222 , & V_257 ,
V_225 , 0 , 255 , 1 , 128 ) ;
F_135 ( V_222 , & V_257 ,
V_226 , 0 , 255 , 1 , 128 ) ;
F_135 ( V_222 , & V_257 ,
V_227 , 0 , 255 , 1 , 128 ) ;
if ( F_136 ( V_3 , V_5 ) )
F_135 ( V_222 , & V_257 ,
V_228 , 0 , 15 , 1 , 0 ) ;
F_135 ( V_222 , & V_257 ,
V_230 , 1 , 255 , 1 , V_3 -> V_20 ) ;
F_135 ( V_222 , & V_257 ,
V_231 , 0 , 31 , 1 , V_258 ) ;
F_137 ( V_222 , & V_257 ,
V_236 ,
V_259 , 0 ,
V_238 ) ;
F_135 ( V_222 , & V_257 ,
V_232 , 0 , 0xff , 1 ,
V_260 >> 8 ) ;
F_138 ( V_222 , & V_261 , NULL ) ;
V_2 -> V_239 =
F_138 ( V_222 , & V_262 , NULL ) ;
if ( V_222 -> error ) {
V_8 = V_222 -> error ;
goto V_256;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_5 = V_5 ;
F_139 ( & V_2 -> V_104 ) ;
F_140 ( & V_2 -> V_106 ) ;
F_141 ( & V_2 -> V_107 ) ;
V_2 -> V_85 = ( V_3 -> type == V_38 ) ?
V_86 : V_87 ;
V_2 -> type = V_115 ;
V_2 -> V_49 = V_258 ;
V_2 -> V_48 = V_3 -> V_20 ;
V_2 -> V_21 = 1 ;
V_2 -> V_18 = V_22 ;
V_2 -> V_234 = true ;
V_2 -> V_233 = V_260 ;
V_2 -> V_187 . type = V_263 ;
V_2 -> V_187 . V_264 = V_265 | V_266 | V_267 ;
V_2 -> V_187 . V_268 = & V_269 ;
V_2 -> V_187 . V_270 = & V_271 ;
V_2 -> V_187 . V_272 = V_2 ;
V_2 -> V_187 . V_273 = V_274 ;
V_2 -> V_187 . V_275 = V_276 ;
V_2 -> V_187 . V_277 = sizeof( struct V_103 ) ;
V_2 -> V_187 . V_104 = & V_2 -> V_104 ;
V_8 = F_142 ( & V_2 -> V_187 ) ;
if ( V_8 )
goto V_256;
F_10 ( V_2 ) ;
F_140 ( & V_2 -> V_9 ) ;
V_2 -> V_77 = sizeof( V_39 ) ;
memcpy ( V_2 -> V_39 , V_39 , V_2 -> V_77 ) ;
V_2 -> V_69 = 32 ;
V_2 -> V_68 = F_143 ( V_3 -> V_117 ,
sizeof( struct V_64 ) *
V_2 -> V_69 ,
& V_2 -> V_70 ) ;
V_8 = - V_255 ;
if ( V_2 -> V_68 == NULL )
goto V_256;
V_2 -> V_100 = F_144 () ;
if ( ! V_2 -> V_100 )
goto V_278;
* V_2 -> V_100 = V_279 ;
V_2 -> V_100 -> V_280 = & V_3 -> V_280 ;
V_2 -> V_100 -> V_281 = V_222 ;
V_2 -> V_100 -> V_282 = & V_2 -> V_187 ;
V_2 -> V_100 -> V_104 = & V_2 -> V_104 ;
F_145 ( V_2 -> V_100 , V_2 ) ;
V_8 = F_146 ( V_2 -> V_100 , V_283 , V_252 ) ;
if ( V_8 < 0 )
goto V_284;
snprintf ( V_2 -> V_100 -> V_163 , sizeof( V_2 -> V_100 -> V_163 ) ,
L_9 , V_139 , V_3 -> V_100 -> V_285 ,
V_2 -> V_100 -> V_285 ) ;
return V_2 ;
V_284:
F_147 ( V_2 -> V_100 ) ;
V_278:
F_148 ( V_2 -> V_3 -> V_117 ,
sizeof( struct V_64 ) * V_2 -> V_69 ,
V_2 -> V_68 , V_2 -> V_70 ) ;
V_256:
F_149 ( V_222 ) ;
F_150 ( V_2 -> V_134 ) ;
F_151 ( V_2 ) ;
return F_132 ( V_8 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
F_148 ( V_2 -> V_3 -> V_117 ,
sizeof( struct V_64 ) * V_2 -> V_69 ,
V_2 -> V_68 , V_2 -> V_70 ) ;
F_153 ( V_2 -> V_100 ) ;
F_149 ( & V_2 -> V_222 ) ;
F_150 ( V_2 -> V_134 ) ;
F_151 ( V_2 ) ;
}
int F_154 ( struct V_3 * V_3 , unsigned V_252 )
{
int V_61 ;
F_155 ( & V_3 -> V_109 ) ;
V_3 -> V_286 = sizeof( T_5 ) ;
V_3 -> V_120 = F_143 ( V_3 -> V_117 ,
V_3 -> V_286 ,
& V_3 -> V_119 ) ;
if ( V_3 -> V_120 == NULL )
return - V_255 ;
for ( V_61 = 0 ; V_61 < V_3 -> V_287 ; V_61 ++ ) {
V_3 -> V_116 [ V_61 ] = F_130 ( V_3 , V_61 , V_252 ) ;
if ( F_89 ( V_3 -> V_116 [ V_61 ] ) )
break;
}
if ( V_61 != V_3 -> V_287 ) {
int V_8 = F_90 ( V_3 -> V_116 [ V_61 ] ) ;
while ( V_61 -- )
F_152 ( V_3 -> V_116 [ V_61 ] ) ;
F_148 ( V_3 -> V_117 , V_3 -> V_286 ,
V_3 -> V_120 , V_3 -> V_119 ) ;
V_3 -> V_120 = NULL ;
return V_8 ;
}
if ( V_3 -> type == V_38 )
V_3 -> V_44 = V_3 -> V_20 * 4 * 4 ;
else
V_3 -> V_44 = V_3 -> V_20 * 4 * 5 ;
F_156 ( & V_3 -> V_117 -> V_118 , L_10 ,
V_3 -> V_116 [ 0 ] -> V_100 -> V_285 ,
V_3 -> V_116 [ V_3 -> V_287 - 1 ] -> V_100 -> V_285 ) ;
return F_87 ( V_3 ) ;
}
void F_157 ( struct V_3 * V_3 )
{
int V_61 ;
F_92 ( V_3 ) ;
for ( V_61 = 0 ; V_61 < V_3 -> V_287 ; V_61 ++ )
F_152 ( V_3 -> V_116 [ V_61 ] ) ;
if ( V_3 -> V_120 )
F_148 ( V_3 -> V_117 , V_3 -> V_286 ,
V_3 -> V_120 , V_3 -> V_119 ) ;
}
