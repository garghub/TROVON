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
static inline T_3 F_39 ( const T_5 * V_71 )
{
return ( F_38 ( ( * V_71 ) [ 0 ] ) >> 24 ) & 0x1F ;
}
static inline T_3 F_40 ( const T_5 * V_71 )
{
return ( F_38 ( ( * V_71 ) [ 0 ] ) >> 22 ) & 3 ;
}
static inline T_1 F_41 ( const T_5 * V_71 )
{
return F_38 ( ( * V_71 ) [ 0 ] ) & 0xFFFFF ;
}
static inline T_3 F_42 ( const T_5 * V_71 )
{
return ( F_38 ( ( * V_71 ) [ 1 ] ) >> 8 ) & 0xFF ;
}
static inline T_3 F_43 ( const T_5 * V_71 )
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
int V_8 ;
V_73 -> V_75 . V_6 |= V_76 ;
if ( F_51 ( V_73 , 0 ) < F_46 ( V_71 ) + V_2 -> V_77 )
return - V_78 ;
V_74 = F_52 ( F_46 ( V_71 ) + V_2 -> V_77 , V_79 ) ;
F_53 ( V_73 , 0 , F_46 ( V_71 ) + V_2 -> V_77 ) ;
F_54 ( & V_3 -> V_80 -> V_81 , V_56 -> V_82 , V_56 -> V_83 ,
V_84 ) ;
V_8 = F_28 ( V_2 , V_2 -> V_77 , V_56 ,
F_45 ( V_71 ) - F_55 ( V_3 ) ,
V_74 , F_55 ( V_3 ) ,
F_56 ( V_3 ) ) ;
F_57 ( & V_3 -> V_80 -> V_81 , V_56 -> V_82 , V_56 -> V_83 ,
V_84 ) ;
F_58 ( V_56 -> V_82 , V_56 -> V_83 ,
V_2 -> V_39 , V_2 -> V_77 ) ;
return V_8 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_72 * V_73 , const T_5 * V_71 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_55 * V_56 = F_50 ( V_73 , 0 ) ;
int V_85 , V_74 ;
int V_54 = 0 ;
int V_8 ;
if ( F_51 ( V_73 , 0 ) < F_41 ( V_71 ) )
return - V_78 ;
V_73 -> V_75 . V_6 &= ~ ( V_76 | V_86 |
V_87 ) ;
if ( ! F_40 ( V_71 ) ) {
V_54 = V_2 -> V_15 ;
V_73 -> V_75 . V_6 |= V_76 ;
F_53 ( V_73 , 0 , F_41 ( V_71 ) +
V_2 -> V_15 ) ;
} else {
V_73 -> V_75 . V_6 |= V_86 ;
F_53 ( V_73 , 0 , F_41 ( V_71 ) ) ;
}
V_85 = ( F_44 ( V_71 ) - F_27 ( V_3 ) +
sizeof( * V_71 ) ) % F_25 ( V_3 ) ;
V_74 = F_52 ( F_41 ( V_71 ) + V_54 , V_79 ) ;
F_54 ( & V_3 -> V_80 -> V_81 , V_56 -> V_82 , V_56 -> V_83 ,
V_84 ) ;
V_8 = F_28 ( V_2 , V_54 , V_56 , V_85 , V_74 ,
F_27 ( V_3 ) ,
F_25 ( V_3 ) ) ;
F_57 ( & V_3 -> V_80 -> V_81 , V_56 -> V_82 , V_56 -> V_83 ,
V_84 ) ;
if ( ! F_40 ( V_71 ) )
F_58 ( V_56 -> V_82 , V_56 -> V_83 ,
V_2 -> V_16 , V_2 -> V_15 ) ;
return V_8 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_72 * V_73 , struct V_88 * V_89 )
{
const T_5 * V_71 = V_89 -> V_71 ;
int V_8 ;
V_73 -> V_75 . V_6 &= ~ ( V_90 |
V_91 ) ;
if ( F_1 ( V_2 ) ) {
V_73 -> V_75 . V_6 |= V_90 ;
if ( V_89 -> V_92 )
V_73 -> V_75 . V_6 |= V_91 ;
}
switch ( V_2 -> V_93 ) {
case V_94 :
case V_95 :
V_8 = F_59 ( V_2 , V_73 , V_71 ) ;
break;
default:
V_8 = F_49 ( V_2 , V_73 , V_71 ) ;
break;
}
if ( ! V_8 ) {
V_73 -> V_75 . V_46 = V_2 -> V_46 ++ ;
V_73 -> V_75 . V_96 . V_97 = F_47 ( V_71 ) ;
V_73 -> V_75 . V_96 . V_98 = F_48 ( V_71 ) ;
}
F_61 ( V_73 , V_8 ? V_99 : V_100 ) ;
return V_8 ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_88 * V_89 )
{
struct V_101 * V_73 ;
unsigned long V_6 ;
F_63 ( & V_2 -> V_102 ) ;
if ( V_2 -> type != V_89 -> type )
goto V_103;
F_3 ( & V_2 -> V_104 , V_6 ) ;
if ( F_64 ( & V_2 -> V_105 ) ) {
F_6 ( & V_2 -> V_104 , V_6 ) ;
goto V_103;
}
V_73 = F_65 ( & V_2 -> V_105 , struct V_101 ,
V_106 ) ;
F_66 ( & V_73 -> V_106 ) ;
F_6 ( & V_2 -> V_104 , V_6 ) ;
F_60 ( V_2 , & V_73 -> V_73 , V_89 ) ;
V_103:
F_67 ( & V_2 -> V_102 ) ;
}
void F_68 ( struct V_3 * V_3 )
{
F_69 ( & V_3 -> V_107 ) ;
}
static void F_70 ( struct V_3 * V_3 )
{
for (; ; ) {
struct V_1 * V_2 ;
struct V_88 V_89 ;
T_1 V_108 , V_51 ;
T_3 V_5 ;
T_3 V_109 ;
V_109 = F_4 ( V_3 , F_71 ( 11 ) ) & 0xff ;
if ( V_109 == V_3 -> V_110 )
break;
V_108 = F_4 ( V_3 ,
F_72 ( V_3 -> V_110 ) ) ;
V_3 -> V_110 = ( V_3 -> V_110 + 1 ) % V_111 ;
V_5 = ( V_108 >> 24 ) & 0x1f ;
V_51 = V_108 & 0x00ffffff ;
if ( V_5 >= V_112 ) {
V_5 -= V_112 ;
V_89 . type = V_47 ;
} else
V_89 . type = V_113 ;
V_2 = V_3 -> V_114 [ V_5 ] ;
if ( V_2 == NULL ) {
F_73 ( & V_3 -> V_80 -> V_81 ,
L_1 , V_5 ) ;
continue;
}
if ( F_24 ( V_3 , V_3 -> V_115 , V_51 ,
sizeof( T_5 ) ) )
continue;
V_89 . V_71 = V_3 -> V_116 ;
if ( F_44 ( V_89 . V_71 ) !=
F_27 ( V_3 ) + V_51 )
continue;
if ( F_2 ( V_2 ) )
V_89 . V_92 = 1 ;
else
V_89 . V_92 = 0 ;
F_62 ( V_2 , & V_89 ) ;
}
}
static int F_74 ( void * V_117 )
{
struct V_3 * V_3 = V_117 ;
F_75 ( V_118 , V_119 ) ;
F_76 () ;
F_77 ( & V_3 -> V_107 , & V_118 ) ;
for (; ; ) {
long V_120 = F_78 ( V_121 ) ;
if ( V_120 == - V_122 || F_79 () )
break;
F_80 ( V_3 , V_123 ) ;
F_70 ( V_3 ) ;
F_81 ( V_3 , V_123 ) ;
F_82 () ;
}
F_83 ( & V_3 -> V_107 , & V_118 ) ;
return 0 ;
}
static int F_84 ( struct V_124 * V_125 ,
const struct V_126 * V_93 ,
unsigned int * V_127 ,
unsigned int * V_128 , unsigned int V_129 [] ,
void * V_130 [] )
{
V_129 [ 0 ] = V_62 ;
* V_128 = 1 ;
if ( * V_127 < V_131 )
* V_127 = V_131 ;
return 0 ;
}
static void F_85 ( struct V_72 * V_73 )
{
struct V_124 * V_132 = V_73 -> V_124 ;
struct V_1 * V_2 = F_86 ( V_132 ) ;
struct V_101 * V_133 =
F_87 ( V_73 , struct V_101 , V_73 ) ;
F_88 ( & V_2 -> V_104 ) ;
F_89 ( & V_133 -> V_106 , & V_2 -> V_105 ) ;
F_90 ( & V_2 -> V_104 ) ;
}
static int F_91 ( struct V_3 * V_3 )
{
V_3 -> V_134 = F_92 ( F_74 , V_3 ,
V_135 L_2 ) ;
if ( F_93 ( V_3 -> V_134 ) ) {
int V_136 = F_94 ( V_3 -> V_134 ) ;
V_3 -> V_134 = NULL ;
return V_136 ;
}
F_81 ( V_3 , V_123 ) ;
return 0 ;
}
static void F_95 ( struct V_3 * V_3 )
{
if ( V_3 -> V_134 ) {
F_96 ( V_3 -> V_134 ) ;
V_3 -> V_134 = NULL ;
}
F_80 ( V_3 , V_123 ) ;
}
static int F_97 ( struct V_124 * V_125 , unsigned int V_137 )
{
struct V_1 * V_2 = F_86 ( V_125 ) ;
int V_8 ;
V_8 = F_13 ( V_2 ) ;
if ( V_8 )
return V_8 ;
return F_91 ( V_2 -> V_3 ) ;
}
static int F_98 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = F_86 ( V_125 ) ;
F_23 ( V_2 ) ;
F_99 ( & V_2 -> V_105 ) ;
F_95 ( V_2 -> V_3 ) ;
return 0 ;
}
static int F_100 ( struct V_138 * V_138 , void * V_139 ,
struct V_140 * V_141 )
{
struct V_1 * V_2 = F_101 ( V_138 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
strcpy ( V_141 -> V_142 , V_135 ) ;
snprintf ( V_141 -> V_143 , sizeof( V_141 -> V_143 ) , L_3 ,
V_2 -> V_5 ) ;
snprintf ( V_141 -> V_144 , sizeof( V_141 -> V_144 ) , L_4 ,
F_102 ( V_3 -> V_80 ) ) ;
V_141 -> V_145 = V_146 |
V_147 | V_148 ;
V_141 -> V_149 = V_141 -> V_145 | V_150 ;
return 0 ;
}
static int F_103 ( struct V_138 * V_138 , void * V_139 ,
struct V_151 * V_152 )
{
struct V_1 * V_2 = F_101 ( V_138 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( V_152 -> V_153 )
return - V_53 ;
snprintf ( V_152 -> V_154 , sizeof( V_152 -> V_154 ) , L_5 ,
V_2 -> V_5 + 1 ) ;
V_152 -> type = V_155 ;
V_152 -> V_156 = V_2 -> V_157 -> V_158 ;
if ( ! F_104 ( V_3 , V_2 -> V_5 ) )
V_152 -> V_159 = V_160 ;
return 0 ;
}
static int F_105 ( struct V_138 * V_138 , void * V_139 ,
unsigned int V_153 )
{
if ( V_153 )
return - V_53 ;
return 0 ;
}
static int F_106 ( struct V_138 * V_138 , void * V_139 ,
unsigned int * V_153 )
{
* V_153 = 0 ;
return 0 ;
}
static int F_107 ( struct V_138 * V_138 , void * V_139 ,
struct V_161 * V_162 )
{
struct V_1 * V_2 = F_101 ( V_138 ) ;
int V_163 = V_2 -> V_3 -> type ;
switch ( V_162 -> V_153 ) {
case 0 :
switch ( V_163 ) {
case V_38 :
V_162 -> V_164 = V_94 ;
strcpy ( V_162 -> V_165 , L_6 ) ;
break;
case V_27 :
V_162 -> V_164 = V_95 ;
strcpy ( V_162 -> V_165 , L_7 ) ;
break;
}
break;
case 1 :
V_162 -> V_164 = V_166 ;
strcpy ( V_162 -> V_165 , L_8 ) ;
break;
default:
return - V_53 ;
}
V_162 -> V_6 = V_167 ;
return 0 ;
}
static inline int F_108 ( T_1 V_168 , int V_163 )
{
return ( V_168 == V_95 && V_163 == V_27 )
|| ( V_168 == V_94 && V_163 == V_38 )
|| V_168 == V_166 ? 0 : - V_53 ;
}
static int F_109 ( struct V_138 * V_138 , void * V_139 ,
struct V_126 * V_162 )
{
struct V_1 * V_2 = F_101 ( V_138 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_169 * V_170 = & V_162 -> V_93 . V_170 ;
if ( F_108 ( V_170 -> V_164 , V_3 -> type ) )
return - V_53 ;
if ( V_170 -> V_23 < V_3 -> V_24 ||
V_170 -> V_25 < V_3 -> V_26 << 1 ) {
V_170 -> V_23 = V_3 -> V_24 >> 1 ;
V_170 -> V_25 = V_3 -> V_26 ;
} else {
V_170 -> V_23 = V_3 -> V_24 ;
V_170 -> V_25 = V_3 -> V_26 << 1 ;
}
switch ( V_170 -> V_171 ) {
case V_172 :
case V_173 :
break;
case V_174 :
default:
V_170 -> V_171 = V_173 ;
break;
}
V_170 -> V_175 = V_176 ;
V_170 -> V_177 = V_62 ;
V_170 -> V_178 = 0 ;
V_170 -> V_139 = 0 ;
return 0 ;
}
static int F_110 ( struct V_138 * V_138 , void * V_139 ,
struct V_126 * V_162 )
{
struct V_1 * V_2 = F_101 ( V_138 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_169 * V_170 = & V_162 -> V_93 . V_170 ;
int V_8 ;
if ( F_111 ( & V_2 -> V_179 ) )
return - V_45 ;
V_8 = F_109 ( V_138 , V_139 , V_162 ) ;
if ( V_8 )
return V_8 ;
if ( V_170 -> V_23 == V_3 -> V_24 )
V_2 -> V_18 = V_180 ;
else
V_2 -> V_18 = V_22 ;
V_2 -> V_93 = V_170 -> V_164 ;
F_10 ( V_2 ) ;
return 0 ;
}
static int F_112 ( struct V_138 * V_138 , void * V_139 ,
struct V_126 * V_162 )
{
struct V_1 * V_2 = F_101 ( V_138 ) ;
struct V_169 * V_170 = & V_162 -> V_93 . V_170 ;
V_170 -> V_23 = V_2 -> V_23 ;
V_170 -> V_25 = V_2 -> V_25 ;
V_170 -> V_164 = V_2 -> V_93 ;
V_170 -> V_171 = V_2 -> V_17 ? V_173 :
V_172 ;
V_170 -> V_177 = V_62 ;
V_170 -> V_175 = V_176 ;
V_170 -> V_139 = 0 ;
return 0 ;
}
static int F_113 ( struct V_138 * V_138 , void * V_139 , T_6 * V_61 )
{
struct V_1 * V_2 = F_101 ( V_138 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( V_3 -> V_28 == V_29 )
* V_61 = V_181 ;
else
* V_61 = V_182 ;
return 0 ;
}
static int F_114 ( struct V_138 * V_138 , void * V_139 , T_6 V_156 )
{
struct V_1 * V_2 = F_101 ( V_138 ) ;
return F_115 ( V_2 -> V_3 , V_156 & V_183 ) ;
}
static int F_116 ( struct V_138 * V_138 , void * V_139 ,
struct V_184 * V_185 )
{
struct V_1 * V_2 = F_101 ( V_138 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( F_108 ( V_185 -> V_186 , V_3 -> type ) )
return - V_53 ;
switch ( V_185 -> V_153 ) {
case 0 :
V_185 -> V_187 . V_23 = V_3 -> V_24 >> 1 ;
V_185 -> V_187 . V_25 = V_3 -> V_26 ;
break;
case 1 :
V_185 -> V_187 . V_23 = V_3 -> V_24 ;
V_185 -> V_187 . V_25 = V_3 -> V_26 << 1 ;
break;
default:
return - V_53 ;
}
V_185 -> type = V_188 ;
return 0 ;
}
static int F_117 ( struct V_138 * V_138 , void * V_139 ,
struct V_189 * V_190 )
{
struct V_1 * V_2 = F_101 ( V_138 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( F_108 ( V_190 -> V_186 , V_3 -> type ) )
return - V_53 ;
if ( V_190 -> V_153 )
return - V_53 ;
if ( ( V_190 -> V_23 != V_3 -> V_24 >> 1 ||
V_190 -> V_25 != V_3 -> V_26 ) &&
( V_190 -> V_23 != V_3 -> V_24 ||
V_190 -> V_25 != V_3 -> V_26 << 1 ) )
return - V_53 ;
V_190 -> type = V_191 ;
V_190 -> V_192 . F_34 . V_193 = 1 ;
V_190 -> V_192 . F_34 . V_194 = V_3 -> V_20 ;
V_190 -> V_192 . F_11 . V_193 = 15 ;
V_190 -> V_192 . F_11 . V_194 = V_3 -> V_20 ;
V_190 -> V_192 . V_195 . V_193 = 1 ;
V_190 -> V_192 . V_195 . V_194 = V_3 -> V_20 ;
return 0 ;
}
static int F_118 ( struct V_138 * V_138 , void * V_139 ,
struct V_196 * V_197 )
{
struct V_1 * V_2 = F_101 ( V_138 ) ;
struct V_198 * V_199 = & V_197 -> V_200 . V_201 ;
V_199 -> V_202 = V_203 ;
V_199 -> V_204 . V_193 = V_2 -> V_21 ;
V_199 -> V_204 . V_194 = V_2 -> V_3 -> V_20 ;
V_199 -> V_205 = 0 ;
V_199 -> V_206 = 2 ;
return 0 ;
}
static inline int F_119 ( T_3 V_20 , T_1 V_207 , T_1 V_208 )
{
if ( ! V_207 || ! V_208 )
return 1 ;
if ( V_208 == V_20 )
return V_207 ;
V_207 *= V_20 ;
return F_34 ( 15U , V_207 / V_208 + ( V_207 % V_208 >= ( V_20 >> 1 ) ) ) ;
}
static int F_120 ( struct V_138 * V_138 , void * V_139 ,
struct V_196 * V_197 )
{
struct V_1 * V_2 = F_101 ( V_138 ) ;
struct V_209 * V_210 = & V_197 -> V_200 . V_201 . V_204 ;
T_3 V_20 = V_2 -> V_3 -> V_20 ;
if ( F_121 ( & V_2 -> V_179 ) )
return - V_45 ;
V_2 -> V_21 = F_119 ( V_20 , V_210 -> V_193 , V_210 -> V_194 ) ;
F_10 ( V_2 ) ;
return F_118 ( V_138 , V_139 , V_197 ) ;
}
static long F_122 ( struct V_138 * V_138 , void * V_211 ,
bool V_212 , unsigned int V_213 , void * V_214 )
{
struct V_1 * V_2 = F_101 ( V_138 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_215 * V_216 = V_214 ;
switch ( V_213 ) {
case V_217 :
* V_216 = V_2 -> V_218 ;
return 0 ;
case V_219 :
if ( ! V_212 )
return - V_45 ;
V_2 -> V_218 = * V_216 ;
if ( V_2 -> V_220 && ! V_2 -> V_221 )
return F_123 ( V_3 , V_2 -> V_5 ,
& V_2 -> V_218 ) ;
return 0 ;
default:
return - V_222 ;
}
}
static int F_124 ( struct V_223 * V_224 )
{
struct V_1 * V_2 =
F_87 ( V_224 -> V_225 , struct V_1 , V_226 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
int V_136 ;
switch ( V_224 -> V_227 ) {
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
return F_125 ( V_3 , V_224 -> V_227 , V_2 -> V_5 ,
V_224 -> V_233 ) ;
case V_234 :
V_2 -> V_48 = V_224 -> V_233 ;
return 0 ;
case V_235 :
V_2 -> V_236 = V_224 -> V_233 ;
if ( ! V_2 -> V_221 || ! V_2 -> V_220 )
return 0 ;
return F_126 ( V_3 , V_2 -> V_5 ,
V_224 -> V_233 ) ;
case V_237 :
V_2 -> V_221 = V_224 -> V_233 == 1 ;
V_2 -> V_220 = V_224 -> V_233 > 0 ;
if ( V_224 -> V_233 ) {
if ( V_2 -> V_221 )
F_126 ( V_3 ,
V_2 -> V_5 , V_2 -> V_236 ) ;
else
F_123 ( V_3 , V_2 -> V_5 ,
& V_2 -> V_218 ) ;
}
F_7 ( V_2 , V_224 -> V_233 ) ;
return 0 ;
case V_238 :
strcpy ( V_2 -> V_239 , V_224 -> string ) ;
V_136 = F_127 ( V_2 ) ;
return V_136 ;
default:
return - V_53 ;
}
return 0 ;
}
static struct V_1 * F_128 ( struct V_3 * V_3 ,
T_3 V_5 , unsigned V_240 )
{
struct V_1 * V_2 ;
struct V_241 * V_226 ;
int V_8 ;
int V_242 , V_243 ;
V_2 = F_129 ( sizeof( * V_2 ) , V_244 ) ;
if ( ! V_2 )
return F_130 ( - V_245 ) ;
V_226 = & V_2 -> V_226 ;
F_131 ( V_226 , 10 ) ;
F_132 ( V_226 , & V_246 ,
V_228 , 0 , 255 , 1 , 128 ) ;
F_132 ( V_226 , & V_246 ,
V_229 , 0 , 255 , 1 , 128 ) ;
F_132 ( V_226 , & V_246 ,
V_230 , 0 , 255 , 1 , 128 ) ;
F_132 ( V_226 , & V_246 ,
V_231 , 0 , 255 , 1 , 128 ) ;
if ( F_133 ( V_3 , V_5 ) )
F_132 ( V_226 , & V_246 ,
V_232 , 0 , 15 , 1 , 0 ) ;
F_132 ( V_226 , & V_246 ,
V_234 , 1 , 255 , 1 , V_3 -> V_20 ) ;
F_134 ( V_226 , & V_247 , NULL ) ;
F_134 ( V_226 , & V_248 , NULL ) ;
F_134 ( V_226 , & V_249 , NULL ) ;
if ( V_226 -> error ) {
V_8 = V_226 -> error ;
goto V_250;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_5 = V_5 ;
F_135 ( & V_2 -> V_102 ) ;
F_136 ( & V_2 -> V_104 ) ;
F_99 ( & V_2 -> V_105 ) ;
V_2 -> V_93 = ( V_3 -> type == V_38 ) ?
V_94 : V_95 ;
V_2 -> type = V_113 ;
V_2 -> V_49 = V_251 ;
V_2 -> V_48 = V_3 -> V_20 ;
V_2 -> V_21 = 1 ;
V_2 -> V_18 = V_22 ;
V_2 -> V_221 = true ;
V_2 -> V_236 = V_252 ;
for ( V_243 = 0 ; V_243 < V_253 ; V_243 ++ )
for ( V_242 = 0 ; V_242 < V_253 ; V_242 ++ )
V_2 -> V_218 . V_216 [ V_243 ] [ V_242 ] =
V_252 ;
V_2 -> V_179 . type = V_254 ;
V_2 -> V_179 . V_255 = V_256 | V_257 | V_258 ;
V_2 -> V_179 . V_259 = & V_260 ;
V_2 -> V_179 . V_261 = & V_262 ;
V_2 -> V_179 . V_263 = V_2 ;
V_2 -> V_179 . V_264 = V_265 ;
V_2 -> V_179 . V_266 = V_267 ;
V_2 -> V_179 . V_268 = sizeof( struct V_101 ) ;
V_2 -> V_179 . V_102 = & V_2 -> V_102 ;
V_8 = F_137 ( & V_2 -> V_179 ) ;
if ( V_8 )
goto V_250;
F_10 ( V_2 ) ;
F_136 ( & V_2 -> V_9 ) ;
V_2 -> V_77 = sizeof( V_39 ) ;
memcpy ( V_2 -> V_39 , V_39 , V_2 -> V_77 ) ;
V_2 -> V_69 = 32 ;
V_2 -> V_68 = F_138 ( V_3 -> V_80 ,
sizeof( struct V_64 ) *
V_2 -> V_69 ,
& V_2 -> V_70 ) ;
V_8 = - V_245 ;
if ( V_2 -> V_68 == NULL )
goto V_250;
V_2 -> V_157 = F_139 () ;
if ( ! V_2 -> V_157 )
goto V_269;
* V_2 -> V_157 = V_270 ;
V_2 -> V_157 -> V_271 = & V_3 -> V_271 ;
V_2 -> V_157 -> V_272 = V_226 ;
V_2 -> V_157 -> V_273 = & V_2 -> V_179 ;
V_2 -> V_157 -> V_102 = & V_2 -> V_102 ;
F_140 ( V_274 , & V_2 -> V_157 -> V_6 ) ;
F_141 ( V_2 -> V_157 , V_2 ) ;
V_8 = F_142 ( V_2 -> V_157 , V_275 , V_240 ) ;
if ( V_8 < 0 )
goto V_276;
snprintf ( V_2 -> V_157 -> V_154 , sizeof( V_2 -> V_157 -> V_154 ) ,
L_9 , V_135 , V_3 -> V_157 -> V_277 ,
V_2 -> V_157 -> V_277 ) ;
return V_2 ;
V_276:
F_143 ( V_2 -> V_157 ) ;
V_269:
F_144 ( V_2 -> V_3 -> V_80 ,
sizeof( struct V_64 ) * V_2 -> V_69 ,
V_2 -> V_68 , V_2 -> V_70 ) ;
V_250:
F_145 ( V_226 ) ;
F_146 ( V_2 ) ;
return F_130 ( V_8 ) ;
}
static void F_147 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
F_148 ( V_2 -> V_157 ) ;
F_145 ( & V_2 -> V_226 ) ;
F_146 ( V_2 ) ;
}
int F_149 ( struct V_3 * V_3 , unsigned V_240 )
{
int V_61 ;
F_150 ( & V_3 -> V_107 ) ;
V_3 -> V_278 = sizeof( T_5 ) ;
V_3 -> V_116 = F_138 ( V_3 -> V_80 ,
V_3 -> V_278 ,
& V_3 -> V_115 ) ;
if ( V_3 -> V_116 == NULL )
return - V_245 ;
for ( V_61 = 0 ; V_61 < V_3 -> V_279 ; V_61 ++ ) {
V_3 -> V_114 [ V_61 ] = F_128 ( V_3 , V_61 , V_240 ) ;
if ( F_93 ( V_3 -> V_114 [ V_61 ] ) )
break;
}
if ( V_61 != V_3 -> V_279 ) {
int V_8 = F_94 ( V_3 -> V_114 [ V_61 ] ) ;
while ( V_61 -- )
F_147 ( V_3 -> V_114 [ V_61 ] ) ;
F_144 ( V_3 -> V_80 , V_3 -> V_278 ,
V_3 -> V_116 , V_3 -> V_115 ) ;
V_3 -> V_116 = NULL ;
return V_8 ;
}
if ( V_3 -> type == V_38 )
V_3 -> V_44 = V_3 -> V_20 * 4 * 4 ;
else
V_3 -> V_44 = V_3 -> V_20 * 4 * 5 ;
F_151 ( & V_3 -> V_80 -> V_81 , L_10 ,
V_3 -> V_114 [ 0 ] -> V_157 -> V_277 ,
V_3 -> V_114 [ V_3 -> V_279 - 1 ] -> V_157 -> V_277 ) ;
return 0 ;
}
void F_152 ( struct V_3 * V_3 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_3 -> V_279 ; V_61 ++ )
F_147 ( V_3 -> V_114 [ V_61 ] ) ;
if ( V_3 -> V_116 )
F_144 ( V_3 -> V_80 , V_3 -> V_278 ,
V_3 -> V_116 , V_3 -> V_115 ) ;
}
