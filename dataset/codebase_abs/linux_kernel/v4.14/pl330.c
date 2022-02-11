static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 [ 0 ] . V_4 != NULL && V_2 -> V_3 [ 1 ] . V_4 != NULL ;
}
static inline bool F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_5 -> V_6 == V_2 ;
}
static inline bool F_3 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 -> V_7 . V_8 & V_9 ) ? true : false ;
}
static inline T_1 F_4 ( T_1 V_10 )
{
return ( V_10 >> V_11 ) & V_12 ;
}
static inline T_1 F_5 ( unsigned V_13 , T_2 V_14 [] )
{
if ( V_13 )
return V_15 ;
V_14 [ 0 ] = V_16 ;
F_6 ( V_15 , L_1 ) ;
return V_15 ;
}
static inline T_1 F_7 ( unsigned V_13 , T_2 V_14 [] , T_2 V_17 )
{
if ( V_13 )
return V_18 ;
V_14 [ 0 ] = V_19 ;
V_17 &= 0x1f ;
V_17 <<= 3 ;
V_14 [ 1 ] = V_17 ;
F_6 ( V_18 , L_2 , V_17 >> 3 ) ;
return V_18 ;
}
static inline T_1 F_8 ( unsigned V_13 , T_2 V_14 [] , enum V_20 V_21 )
{
if ( V_13 )
return V_22 ;
V_14 [ 0 ] = V_23 ;
if ( V_21 == V_24 )
V_14 [ 0 ] |= ( 0 << 1 ) | ( 1 << 0 ) ;
else if ( V_21 == V_25 )
V_14 [ 0 ] |= ( 1 << 1 ) | ( 1 << 0 ) ;
F_6 ( V_22 , L_3 ,
V_21 == V_24 ? 'S' : ( V_21 == V_25 ? 'B' : 'A' ) ) ;
return V_22 ;
}
static inline T_1 F_9 ( unsigned V_13 , T_2 V_14 [] ,
enum V_20 V_21 , T_2 V_17 )
{
if ( V_13 )
return V_26 ;
V_14 [ 0 ] = V_27 ;
if ( V_21 == V_25 )
V_14 [ 0 ] |= ( 1 << 1 ) ;
V_17 &= 0x1f ;
V_17 <<= 3 ;
V_14 [ 1 ] = V_17 ;
F_6 ( V_26 , L_4 ,
V_21 == V_24 ? 'S' : 'B' , V_17 >> 3 ) ;
return V_26 ;
}
static inline T_1 F_10 ( unsigned V_13 , T_2 V_14 [] ,
unsigned V_28 , T_2 V_29 )
{
if ( V_13 )
return V_30 ;
V_14 [ 0 ] = V_31 ;
if ( V_28 )
V_14 [ 0 ] |= ( 1 << 1 ) ;
V_29 -- ;
V_14 [ 1 ] = V_29 ;
F_6 ( V_30 , L_5 , V_28 ? '1' : '0' , V_29 ) ;
return V_30 ;
}
static inline T_1 F_11 ( unsigned V_13 , T_2 V_14 [] ,
const struct V_32 * V_33 )
{
enum V_20 V_21 = V_33 -> V_21 ;
bool V_34 = V_33 -> V_34 ;
unsigned V_28 = V_33 -> V_28 ;
T_2 V_35 = V_33 -> V_35 ;
if ( V_13 )
return V_36 ;
V_14 [ 0 ] = V_37 ;
if ( V_28 )
V_14 [ 0 ] |= ( 1 << 2 ) ;
if ( ! V_34 )
V_14 [ 0 ] |= ( 1 << 4 ) ;
if ( V_21 == V_24 )
V_14 [ 0 ] |= ( 0 << 1 ) | ( 1 << 0 ) ;
else if ( V_21 == V_25 )
V_14 [ 0 ] |= ( 1 << 1 ) | ( 1 << 0 ) ;
V_14 [ 1 ] = V_35 ;
F_6 ( V_36 , L_6 ,
V_34 ? L_7 : L_8 ,
V_21 == V_24 ? 'S' : ( V_21 == V_25 ? 'B' : 'A' ) ,
V_28 ? '1' : '0' ,
V_35 ) ;
return V_36 ;
}
static inline T_1 F_12 ( unsigned V_13 , T_2 V_14 [] )
{
if ( V_13 )
return V_38 ;
V_14 [ 0 ] = V_39 ;
return V_38 ;
}
static inline T_1 F_13 ( unsigned V_13 , T_2 V_14 [] ,
enum V_40 V_41 , T_1 V_42 )
{
if ( V_13 )
return V_43 ;
V_14 [ 0 ] = V_44 ;
V_14 [ 1 ] = V_41 ;
V_14 [ 2 ] = V_42 ;
V_14 [ 3 ] = V_42 >> 8 ;
V_14 [ 4 ] = V_42 >> 16 ;
V_14 [ 5 ] = V_42 >> 24 ;
F_6 ( V_43 , L_9 ,
V_41 == V_45 ? L_10 : ( V_41 == V_46 ? L_11 : L_12 ) , V_42 ) ;
return V_43 ;
}
static inline T_1 F_14 ( unsigned V_13 , T_2 V_14 [] )
{
if ( V_13 )
return V_47 ;
V_14 [ 0 ] = V_48 ;
F_6 ( V_47 , L_13 ) ;
return V_47 ;
}
static inline T_1 F_15 ( unsigned V_13 , T_2 V_14 [] , T_2 V_49 )
{
if ( V_13 )
return V_50 ;
V_14 [ 0 ] = V_51 ;
V_49 &= 0x1f ;
V_49 <<= 3 ;
V_14 [ 1 ] = V_49 ;
F_6 ( V_50 , L_14 , V_49 >> 3 ) ;
return V_50 ;
}
static inline T_1 F_16 ( unsigned V_13 , T_2 V_14 [] , enum V_20 V_21 )
{
if ( V_13 )
return V_52 ;
V_14 [ 0 ] = V_53 ;
if ( V_21 == V_24 )
V_14 [ 0 ] |= ( 0 << 1 ) | ( 1 << 0 ) ;
else if ( V_21 == V_25 )
V_14 [ 0 ] |= ( 1 << 1 ) | ( 1 << 0 ) ;
F_6 ( V_52 , L_15 ,
V_21 == V_24 ? 'S' : ( V_21 == V_25 ? 'B' : 'A' ) ) ;
return V_52 ;
}
static inline T_1 F_17 ( unsigned V_13 , T_2 V_14 [] ,
enum V_20 V_21 , T_2 V_17 )
{
if ( V_13 )
return V_54 ;
V_14 [ 0 ] = V_55 ;
if ( V_21 == V_25 )
V_14 [ 0 ] |= ( 1 << 1 ) ;
V_17 &= 0x1f ;
V_17 <<= 3 ;
V_14 [ 1 ] = V_17 ;
F_6 ( V_54 , L_16 ,
V_21 == V_24 ? 'S' : 'B' , V_17 >> 3 ) ;
return V_54 ;
}
static inline T_1 F_18 ( unsigned V_13 , T_2 V_14 [] ,
enum V_20 V_21 , T_2 V_17 )
{
if ( V_13 )
return V_56 ;
V_14 [ 0 ] = V_57 ;
if ( V_21 == V_24 )
V_14 [ 0 ] |= ( 0 << 1 ) | ( 0 << 0 ) ;
else if ( V_21 == V_25 )
V_14 [ 0 ] |= ( 1 << 1 ) | ( 0 << 0 ) ;
else
V_14 [ 0 ] |= ( 0 << 1 ) | ( 1 << 0 ) ;
V_17 &= 0x1f ;
V_17 <<= 3 ;
V_14 [ 1 ] = V_17 ;
F_6 ( V_56 , L_17 ,
V_21 == V_24 ? 'S' : ( V_21 == V_25 ? 'B' : 'P' ) , V_17 >> 3 ) ;
return V_56 ;
}
static inline T_1 F_19 ( unsigned V_13 , T_2 V_14 [] )
{
if ( V_13 )
return V_58 ;
V_14 [ 0 ] = V_59 ;
F_6 ( V_58 , L_18 ) ;
return V_58 ;
}
static inline T_1 F_20 ( unsigned V_13 , T_2 V_14 [] ,
const struct V_60 * V_33 )
{
T_2 V_61 = V_33 -> V_61 ;
T_1 V_62 = V_33 -> V_62 ;
unsigned V_63 = V_33 -> V_63 ;
if ( V_13 )
return V_64 ;
V_14 [ 0 ] = V_65 ;
V_14 [ 0 ] |= ( V_63 << 1 ) ;
V_14 [ 1 ] = V_61 & 0x7 ;
V_14 [ 2 ] = V_62 ;
V_14 [ 3 ] = V_62 >> 8 ;
V_14 [ 4 ] = V_62 >> 16 ;
V_14 [ 5 ] = V_62 >> 24 ;
return V_64 ;
}
static bool F_21 ( struct V_1 * V_2 )
{
void T_3 * V_66 = V_2 -> V_5 -> V_67 ;
unsigned long V_68 = F_22 ( 5 ) ;
do {
if ( ! ( F_23 ( V_66 + V_69 ) & V_70 ) )
break;
F_24 () ;
} while ( -- V_68 );
if ( ! V_68 )
return true ;
return false ;
}
static inline void F_25 ( struct V_1 * V_2 ,
T_2 V_71 [] , bool V_72 )
{
void T_3 * V_66 = V_2 -> V_5 -> V_67 ;
T_1 V_42 ;
V_42 = ( V_71 [ 0 ] << 16 ) | ( V_71 [ 1 ] << 24 ) ;
if ( ! V_72 ) {
V_42 |= ( 1 << 0 ) ;
V_42 |= ( V_2 -> V_73 << 8 ) ;
}
F_26 ( V_42 , V_66 + V_74 ) ;
V_42 = F_27 ( * ( ( V_75 * ) & V_71 [ 2 ] ) ) ;
F_26 ( V_42 , V_66 + V_76 ) ;
if ( F_21 ( V_2 ) ) {
F_28 ( V_2 -> V_5 -> V_77 . V_78 , L_19 ) ;
return;
}
F_26 ( 0 , V_66 + V_79 ) ;
}
static inline T_1 F_29 ( struct V_1 * V_2 )
{
void T_3 * V_66 = V_2 -> V_5 -> V_67 ;
T_1 V_42 ;
if ( F_2 ( V_2 ) )
V_42 = F_23 ( V_66 + V_80 ) & 0xf ;
else
V_42 = F_23 ( V_66 + F_30 ( V_2 -> V_73 ) ) & 0xf ;
switch ( V_42 ) {
case V_81 :
return V_82 ;
case V_83 :
return V_84 ;
case V_85 :
return V_86 ;
case V_87 :
return V_88 ;
case V_89 :
return V_90 ;
case V_91 :
return V_92 ;
case V_93 :
if ( F_2 ( V_2 ) )
return V_94 ;
else
return V_95 ;
case V_96 :
if ( F_2 ( V_2 ) )
return V_94 ;
else
return V_97 ;
case V_98 :
if ( F_2 ( V_2 ) )
return V_94 ;
else
return V_99 ;
case V_100 :
if ( F_2 ( V_2 ) )
return V_94 ;
else
return V_101 ;
case V_102 :
if ( F_2 ( V_2 ) )
return V_94 ;
else
return V_103 ;
case V_104 :
if ( F_2 ( V_2 ) )
return V_94 ;
else
return V_105 ;
default:
return V_94 ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
void T_3 * V_66 = V_2 -> V_5 -> V_67 ;
T_2 V_71 [ 6 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
if ( F_29 ( V_2 ) == V_105 )
F_32 ( V_2 , V_92 | V_101 ) ;
if ( F_29 ( V_2 ) == V_103
|| F_29 ( V_2 ) == V_101
|| F_29 ( V_2 ) == V_82 )
return;
F_12 ( 0 , V_71 ) ;
F_26 ( F_23 ( V_66 + V_106 ) & ~ ( 1 << V_2 -> V_49 ) , V_66 + V_106 ) ;
F_25 ( V_2 , V_71 , F_2 ( V_2 ) ) ;
}
static bool F_33 ( struct V_1 * V_2 )
{
void T_3 * V_66 = V_2 -> V_5 -> V_67 ;
struct V_107 * V_3 ;
struct V_108 * V_4 ;
struct V_60 V_109 ;
unsigned V_63 ;
T_2 V_71 [ 6 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_110 ;
if ( F_29 ( V_2 ) != V_82 )
return true ;
V_110 = 1 - V_2 -> V_111 ;
if ( V_2 -> V_3 [ V_110 ] . V_4 != NULL ) {
V_3 = & V_2 -> V_3 [ V_110 ] ;
} else {
V_110 = V_2 -> V_111 ;
if ( V_2 -> V_3 [ V_110 ] . V_4 != NULL )
V_3 = & V_2 -> V_3 [ V_110 ] ;
else
V_3 = NULL ;
}
if ( ! V_3 )
return true ;
if ( V_110 == V_2 -> V_112 )
return true ;
V_4 = V_3 -> V_4 ;
V_63 = V_4 -> V_113 . V_114 ? 1 : 0 ;
if ( F_3 ( V_2 ) && ! V_63 )
F_34 ( V_2 -> V_5 -> V_77 . V_78 , L_20 ,
V_115 , __LINE__ ) ;
V_109 . V_61 = V_2 -> V_73 ;
V_109 . V_62 = V_3 -> V_116 ;
V_109 . V_63 = V_63 ;
F_20 ( 0 , V_71 , & V_109 ) ;
F_26 ( F_23 ( V_66 + V_106 ) | ( 1 << V_2 -> V_49 ) , V_66 + V_106 ) ;
F_25 ( V_2 , V_71 , true ) ;
V_2 -> V_112 = V_110 ;
return true ;
}
static bool F_35 ( struct V_1 * V_2 )
{
switch ( F_29 ( V_2 ) ) {
case V_105 :
F_32 ( V_2 , V_92 | V_101 ) ;
if ( F_29 ( V_2 ) == V_101 )
F_32 (thrd, PL330_STATE_STOPPED)
case V_92 :
F_31 ( V_2 ) ;
case V_101 :
case V_103 :
F_32 (thrd, PL330_STATE_STOPPED)
case V_82 :
return F_33 ( V_2 ) ;
case V_99 :
case V_97 :
case V_95 :
case V_88 :
case V_86 :
case V_84 :
return true ;
case V_90 :
default:
return false ;
}
}
static inline int F_36 ( unsigned V_13 , T_2 V_14 [] ,
const struct V_117 * V_118 , int V_119 )
{
int V_120 = 0 ;
struct V_121 * V_7 = V_118 -> V_4 -> V_113 . V_7 ;
if ( F_4 ( V_7 -> V_10 ) >= V_122 ) {
while ( V_119 -- ) {
V_120 += F_8 ( V_13 , & V_14 [ V_120 ] , V_123 ) ;
V_120 += F_16 ( V_13 , & V_14 [ V_120 ] , V_123 ) ;
}
} else {
while ( V_119 -- ) {
V_120 += F_8 ( V_13 , & V_14 [ V_120 ] , V_123 ) ;
V_120 += F_14 ( V_13 , & V_14 [ V_120 ] ) ;
V_120 += F_16 ( V_13 , & V_14 [ V_120 ] , V_123 ) ;
V_120 += F_19 ( V_13 , & V_14 [ V_120 ] ) ;
}
}
return V_120 ;
}
static inline int F_37 ( struct V_124 * V_125 , unsigned V_13 ,
T_2 V_14 [] , const struct V_117 * V_118 ,
int V_119 )
{
int V_120 = 0 ;
enum V_20 V_21 ;
if ( V_125 -> V_126 & V_127 )
V_21 = V_25 ;
else
V_21 = V_24 ;
while ( V_119 -- ) {
V_120 += F_18 ( V_13 , & V_14 [ V_120 ] , V_21 , V_118 -> V_4 -> V_17 ) ;
V_120 += F_9 ( V_13 , & V_14 [ V_120 ] , V_21 , V_118 -> V_4 -> V_17 ) ;
V_120 += F_16 ( V_13 , & V_14 [ V_120 ] , V_123 ) ;
if ( ! ( V_125 -> V_126 & V_127 ) )
V_120 += F_7 ( V_13 , & V_14 [ V_120 ] ,
V_118 -> V_4 -> V_17 ) ;
}
return V_120 ;
}
static inline int F_38 ( struct V_124 * V_125 ,
unsigned V_13 , T_2 V_14 [] ,
const struct V_117 * V_118 , int V_119 )
{
int V_120 = 0 ;
enum V_20 V_21 ;
if ( V_125 -> V_126 & V_127 )
V_21 = V_25 ;
else
V_21 = V_24 ;
while ( V_119 -- ) {
V_120 += F_18 ( V_13 , & V_14 [ V_120 ] , V_21 , V_118 -> V_4 -> V_17 ) ;
V_120 += F_8 ( V_13 , & V_14 [ V_120 ] , V_123 ) ;
V_120 += F_17 ( V_13 , & V_14 [ V_120 ] , V_21 , V_118 -> V_4 -> V_17 ) ;
if ( ! ( V_125 -> V_126 & V_127 ) )
V_120 += F_7 ( V_13 , & V_14 [ V_120 ] ,
V_118 -> V_4 -> V_17 ) ;
}
return V_120 ;
}
static int F_39 ( struct V_124 * V_125 , unsigned V_13 , T_2 V_14 [] ,
const struct V_117 * V_118 , int V_119 )
{
int V_120 = 0 ;
switch ( V_118 -> V_4 -> V_128 ) {
case V_129 :
V_120 += F_38 ( V_125 , V_13 , & V_14 [ V_120 ] , V_118 , V_119 ) ;
break;
case V_130 :
V_120 += F_37 ( V_125 , V_13 , & V_14 [ V_120 ] , V_118 , V_119 ) ;
break;
case V_131 :
V_120 += F_36 ( V_13 , & V_14 [ V_120 ] , V_118 , V_119 ) ;
break;
default:
V_120 += 0x40000000 ;
break;
}
return V_120 ;
}
static inline int F_40 ( struct V_124 * V_125 , unsigned V_13 , T_2 V_14 [] ,
unsigned long * V_132 , const struct V_117 * V_118 )
{
int V_119 , V_133 , V_134 , V_135 , V_136 , V_120 ;
unsigned V_137 , V_138 , V_139 , V_140 ;
struct V_32 V_141 ;
if ( * V_132 == 1 )
return F_39 ( V_125 , V_13 , V_14 , V_118 , 1 ) ;
if ( * V_132 >= 256 * 256 ) {
V_138 = 256 ;
V_137 = 256 ;
V_119 = * V_132 / V_138 / V_137 ;
} else if ( * V_132 > 256 ) {
V_138 = 256 ;
V_137 = * V_132 / V_138 ;
V_119 = 1 ;
} else {
V_138 = * V_132 ;
V_137 = 0 ;
V_119 = 1 ;
}
V_134 = F_10 ( 1 , V_14 , 0 , 0 ) ;
V_136 = F_39 ( V_125 , 1 , V_14 , V_118 , 1 ) ;
V_141 . V_21 = V_123 ;
V_141 . V_34 = false ;
V_141 . V_28 = 0 ;
V_141 . V_35 = 0 ;
V_135 = F_11 ( 1 , V_14 , & V_141 ) ;
if ( V_137 ) {
V_134 *= 2 ;
V_135 *= 2 ;
}
V_133 = ( 255 - ( V_134 + V_135 ) ) / V_136 ;
V_119 = ( V_133 < V_119 ) ? V_133 : V_119 ;
V_120 = 0 ;
if ( V_137 ) {
V_120 += F_10 ( V_13 , & V_14 [ V_120 ] , 0 , V_137 ) ;
V_139 = V_120 ;
}
V_120 += F_10 ( V_13 , & V_14 [ V_120 ] , 1 , V_138 ) ;
V_140 = V_120 ;
V_120 += F_39 ( V_125 , V_13 , & V_14 [ V_120 ] , V_118 , V_119 ) ;
V_141 . V_21 = V_123 ;
V_141 . V_34 = false ;
V_141 . V_28 = 1 ;
V_141 . V_35 = V_120 - V_140 ;
V_120 += F_11 ( V_13 , & V_14 [ V_120 ] , & V_141 ) ;
if ( V_137 ) {
V_141 . V_21 = V_123 ;
V_141 . V_34 = false ;
V_141 . V_28 = 0 ;
V_141 . V_35 = V_120 - V_139 ;
V_120 += F_11 ( V_13 , & V_14 [ V_120 ] , & V_141 ) ;
}
* V_132 = V_138 * V_119 ;
if ( V_137 )
* V_132 *= V_137 ;
return V_120 ;
}
static inline int F_41 ( struct V_124 * V_125 ,
unsigned V_13 , T_2 V_14 [] ,
const struct V_117 * V_118 )
{
struct V_142 * V_143 = & V_118 -> V_4 -> V_144 ;
T_1 V_145 = V_118 -> V_145 ;
unsigned long V_146 , V_132 = F_42 ( V_143 -> V_147 , V_145 ) ;
int V_120 = 0 ;
while ( V_132 ) {
V_146 = V_132 ;
V_120 += F_40 ( V_125 , V_13 , & V_14 [ V_120 ] , & V_146 , V_118 ) ;
V_132 -= V_146 ;
}
return V_120 ;
}
static inline int F_43 ( struct V_124 * V_125 ,
unsigned V_13 , T_2 V_14 [] ,
const struct V_117 * V_118 )
{
struct V_142 * V_143 = & V_118 -> V_4 -> V_144 ;
int V_120 = 0 ;
V_120 += F_13 ( V_13 , & V_14 [ V_120 ] , V_45 , V_143 -> V_148 ) ;
V_120 += F_13 ( V_13 , & V_14 [ V_120 ] , V_46 , V_143 -> V_149 ) ;
V_120 += F_41 ( V_125 , V_13 , & V_14 [ V_120 ] , V_118 ) ;
return V_120 ;
}
static int F_44 ( struct V_124 * V_125 , unsigned V_13 ,
struct V_1 * V_2 , unsigned V_150 ,
struct V_117 * V_118 )
{
struct V_107 * V_3 = & V_2 -> V_3 [ V_150 ] ;
struct V_142 * V_143 ;
T_2 * V_14 = V_3 -> V_151 ;
int V_120 = 0 ;
F_45 ( V_3 -> V_116 ) ;
V_120 += F_13 ( V_13 , & V_14 [ V_120 ] , V_152 , V_118 -> V_145 ) ;
V_143 = & V_118 -> V_4 -> V_144 ;
if ( V_143 -> V_147 % ( F_46 ( V_118 -> V_145 ) * F_47 ( V_118 -> V_145 ) ) )
return - V_153 ;
V_120 += F_43 ( V_125 , V_13 , & V_14 [ V_120 ] , V_118 ) ;
V_120 += F_15 ( V_13 , & V_14 [ V_120 ] , V_2 -> V_49 ) ;
V_120 += F_5 ( V_13 , & V_14 [ V_120 ] ) ;
return V_120 ;
}
static inline T_1 F_48 ( const struct V_154 * V_155 )
{
T_1 V_145 = 0 ;
if ( V_155 -> V_156 )
V_145 |= V_157 ;
if ( V_155 -> V_158 )
V_145 |= V_159 ;
if ( V_155 -> V_160 )
V_145 |= V_161 | V_162 ;
if ( V_155 -> V_114 )
V_145 |= V_163 | V_164 ;
if ( V_155 -> V_165 )
V_145 |= V_166 | V_167 ;
V_145 |= ( ( ( V_155 -> V_168 - 1 ) & 0xf ) << V_169 ) ;
V_145 |= ( ( ( V_155 -> V_168 - 1 ) & 0xf ) << V_170 ) ;
V_145 |= ( V_155 -> V_171 << V_172 ) ;
V_145 |= ( V_155 -> V_171 << V_173 ) ;
V_145 |= ( V_155 -> V_174 << V_175 ) ;
V_145 |= ( V_155 -> V_176 << V_177 ) ;
V_145 |= ( V_155 -> V_178 << V_179 ) ;
return V_145 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_108 * V_4 )
{
struct V_124 * V_125 = V_2 -> V_5 ;
struct V_117 V_180 ;
unsigned long V_181 ;
unsigned V_110 ;
T_1 V_145 ;
int V_182 = 0 ;
if ( V_125 -> V_183 == V_184
|| V_125 -> V_185 . V_186 & ( 1 << V_2 -> V_73 ) ) {
F_34 ( V_2 -> V_5 -> V_77 . V_78 , L_21 ,
V_115 , __LINE__ ) ;
return - V_187 ;
}
if ( V_4 -> V_128 != V_131 &&
V_4 -> V_17 >= V_125 -> V_7 . V_188 ) {
F_34 ( V_2 -> V_5 -> V_77 . V_78 ,
L_22 ,
V_115 , __LINE__ , V_4 -> V_17 ) ;
return - V_153 ;
}
F_50 ( & V_125 -> V_189 , V_181 ) ;
if ( F_1 ( V_2 ) ) {
V_182 = - V_187 ;
goto V_190;
}
if ( ! F_3 ( V_2 ) )
V_4 -> V_113 . V_114 = 0 ;
else
V_4 -> V_113 . V_114 = 1 ;
V_145 = F_48 ( & V_4 -> V_113 ) ;
V_110 = V_2 -> V_3 [ 0 ] . V_4 == NULL ? 0 : 1 ;
V_180 . V_145 = V_145 ;
V_180 . V_4 = V_4 ;
V_182 = F_44 ( V_125 , 1 , V_2 , V_110 , & V_180 ) ;
if ( V_182 < 0 )
goto V_190;
if ( V_182 > V_125 -> V_191 / 2 ) {
F_34 ( V_125 -> V_77 . V_78 , L_23 ,
V_115 , __LINE__ , V_182 , V_125 -> V_191 / 2 ) ;
V_182 = - V_192 ;
goto V_190;
}
V_2 -> V_111 = V_110 ;
V_2 -> V_3 [ V_110 ] . V_4 = V_4 ;
F_44 ( V_125 , 0 , V_2 , V_110 , & V_180 ) ;
V_182 = 0 ;
V_190:
F_51 ( & V_125 -> V_189 , V_181 ) ;
return V_182 ;
}
static void F_52 ( struct V_108 * V_4 , enum V_193 V_194 )
{
struct V_195 * V_196 ;
unsigned long V_181 ;
if ( ! V_4 )
return;
V_196 = V_4 -> V_197 ;
if ( ! V_196 )
return;
F_50 ( & V_196 -> V_189 , V_181 ) ;
V_4 -> V_198 = V_199 ;
F_51 ( & V_196 -> V_189 , V_181 ) ;
F_53 ( & V_196 -> V_200 ) ;
}
static void F_54 ( unsigned long V_201 )
{
struct V_124 * V_125 = (struct V_124 * ) V_201 ;
unsigned long V_181 ;
int V_202 ;
F_50 ( & V_125 -> V_189 , V_181 ) ;
if ( V_125 -> V_185 . V_203 ) {
V_125 -> V_183 = V_184 ;
V_125 -> V_185 . V_204 = true ;
V_125 -> V_185 . V_203 = false ;
}
if ( V_125 -> V_185 . V_204 ) {
F_31 ( V_125 -> V_6 ) ;
V_125 -> V_185 . V_186 = ( 1 << V_125 -> V_7 . V_205 ) - 1 ;
V_125 -> V_185 . V_204 = false ;
}
for ( V_202 = 0 ; V_202 < V_125 -> V_7 . V_205 ; V_202 ++ ) {
if ( V_125 -> V_185 . V_186 & ( 1 << V_202 ) ) {
struct V_1 * V_2 = & V_125 -> V_206 [ V_202 ] ;
void T_3 * V_66 = V_125 -> V_67 ;
enum V_193 V_194 ;
F_31 ( V_2 ) ;
if ( F_23 ( V_66 + V_207 ) & ( 1 << V_2 -> V_73 ) )
V_194 = V_208 ;
else
V_194 = V_209 ;
F_51 ( & V_125 -> V_189 , V_181 ) ;
F_52 ( V_2 -> V_3 [ 1 - V_2 -> V_111 ] . V_4 , V_194 ) ;
F_52 ( V_2 -> V_3 [ V_2 -> V_111 ] . V_4 , V_194 ) ;
F_50 ( & V_125 -> V_189 , V_181 ) ;
V_2 -> V_3 [ 0 ] . V_4 = NULL ;
V_2 -> V_3 [ 1 ] . V_4 = NULL ;
V_2 -> V_112 = - 1 ;
V_125 -> V_185 . V_186 &= ~ ( 1 << V_202 ) ;
}
}
F_51 ( & V_125 -> V_189 , V_181 ) ;
return;
}
static int F_55 ( struct V_124 * V_125 )
{
struct V_108 * V_210 , * V_211 ;
unsigned long V_181 ;
void T_3 * V_66 ;
T_1 V_42 ;
int V_73 , V_49 , V_182 = 0 ;
V_66 = V_125 -> V_67 ;
F_50 ( & V_125 -> V_189 , V_181 ) ;
V_42 = F_23 ( V_66 + V_212 ) & 0x1 ;
if ( V_42 )
V_125 -> V_185 . V_204 = true ;
else
V_125 -> V_185 . V_204 = false ;
V_42 = F_23 ( V_66 + V_207 ) & ( ( 1 << V_125 -> V_7 . V_205 ) - 1 ) ;
V_125 -> V_185 . V_186 |= V_42 ;
if ( V_42 ) {
int V_202 = 0 ;
while ( V_202 < V_125 -> V_7 . V_205 ) {
if ( V_42 & ( 1 << V_202 ) ) {
F_34 ( V_125 -> V_77 . V_78 ,
L_24 ,
V_202 , F_23 ( V_66 + F_30 ( V_202 ) ) ,
F_23 ( V_66 + F_56 ( V_202 ) ) ) ;
F_31 ( & V_125 -> V_206 [ V_202 ] ) ;
}
V_202 ++ ;
}
}
V_42 = F_23 ( V_66 + V_213 ) ;
if ( V_125 -> V_7 . V_214 < 32
&& V_42 & ~ ( ( 1 << V_125 -> V_7 . V_214 ) - 1 ) ) {
V_125 -> V_185 . V_203 = true ;
F_28 ( V_125 -> V_77 . V_78 , L_25 , V_115 ,
__LINE__ ) ;
V_182 = 1 ;
goto V_215;
}
for ( V_49 = 0 ; V_49 < V_125 -> V_7 . V_214 ; V_49 ++ ) {
if ( V_42 & ( 1 << V_49 ) ) {
struct V_1 * V_2 ;
T_1 V_216 = F_23 ( V_66 + V_106 ) ;
int V_217 ;
if ( V_216 & ( 1 << V_49 ) )
F_26 ( 1 << V_49 , V_66 + V_218 ) ;
V_182 = 1 ;
V_73 = V_125 -> V_219 [ V_49 ] ;
V_2 = & V_125 -> V_206 [ V_73 ] ;
V_217 = V_2 -> V_112 ;
if ( V_217 == - 1 )
continue;
V_210 = V_2 -> V_3 [ V_217 ] . V_4 ;
V_2 -> V_3 [ V_217 ] . V_4 = NULL ;
V_2 -> V_112 = - 1 ;
F_35 ( V_2 ) ;
F_57 ( & V_210 -> V_220 , & V_125 -> V_221 ) ;
}
}
F_58 (descdone, tmp, &pl330->req_done, rqd) {
F_59 ( & V_210 -> V_220 ) ;
F_51 ( & V_125 -> V_189 , V_181 ) ;
F_52 ( V_210 , V_222 ) ;
F_50 ( & V_125 -> V_189 , V_181 ) ;
}
V_215:
F_51 ( & V_125 -> V_189 , V_181 ) ;
if ( V_125 -> V_185 . V_203
|| V_125 -> V_185 . V_204
|| V_125 -> V_185 . V_186 ) {
V_182 = 1 ;
F_53 ( & V_125 -> V_223 ) ;
}
return V_182 ;
}
static inline int F_60 ( struct V_1 * V_2 )
{
struct V_124 * V_125 = V_2 -> V_5 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_125 -> V_7 . V_214 ; V_49 ++ )
if ( V_125 -> V_219 [ V_49 ] == - 1 ) {
V_125 -> V_219 [ V_49 ] = V_2 -> V_73 ;
return V_49 ;
}
return - 1 ;
}
static bool F_61 ( const struct V_124 * V_125 , int V_202 )
{
return V_125 -> V_7 . V_224 & ( 1 << V_202 ) ;
}
static struct V_1 * F_62 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = NULL ;
int V_225 , V_202 ;
if ( V_125 -> V_183 == V_184 )
return NULL ;
V_225 = V_125 -> V_7 . V_205 ;
for ( V_202 = 0 ; V_202 < V_225 ; V_202 ++ ) {
V_2 = & V_125 -> V_206 [ V_202 ] ;
if ( ( V_2 -> free ) && ( ! F_3 ( V_2 ) ||
F_61 ( V_125 , V_202 ) ) ) {
V_2 -> V_49 = F_60 ( V_2 ) ;
if ( V_2 -> V_49 >= 0 ) {
V_2 -> free = false ;
V_2 -> V_111 = 1 ;
V_2 -> V_3 [ 0 ] . V_4 = NULL ;
V_2 -> V_3 [ 1 ] . V_4 = NULL ;
V_2 -> V_112 = - 1 ;
break;
}
}
V_2 = NULL ;
}
return V_2 ;
}
static inline void F_63 ( struct V_1 * V_2 , int V_49 )
{
struct V_124 * V_125 = V_2 -> V_5 ;
if ( V_49 >= 0 && V_49 < V_125 -> V_7 . V_214
&& V_125 -> V_219 [ V_49 ] == V_2 -> V_73 )
V_125 -> V_219 [ V_49 ] = - 1 ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_124 * V_125 ;
if ( ! V_2 || V_2 -> free )
return;
F_31 ( V_2 ) ;
F_52 ( V_2 -> V_3 [ 1 - V_2 -> V_111 ] . V_4 , V_209 ) ;
F_52 ( V_2 -> V_3 [ V_2 -> V_111 ] . V_4 , V_209 ) ;
V_125 = V_2 -> V_5 ;
F_63 ( V_2 , V_2 -> V_49 ) ;
V_2 -> free = true ;
}
static void F_65 ( struct V_124 * V_125 )
{
void T_3 * V_66 = V_125 -> V_67 ;
T_1 V_42 ;
V_42 = F_23 ( V_66 + V_226 ) >> V_227 ;
V_42 &= V_228 ;
V_125 -> V_7 . V_229 = 8 * ( 1 << V_42 ) ;
V_42 = F_23 ( V_66 + V_226 ) >> V_230 ;
V_42 &= V_231 ;
V_125 -> V_7 . V_232 = V_42 + 1 ;
V_42 = F_23 ( V_66 + V_233 ) >> V_234 ;
V_42 &= V_235 ;
V_42 += 1 ;
V_125 -> V_7 . V_205 = V_42 ;
V_42 = F_23 ( V_66 + V_233 ) ;
if ( V_42 & V_236 ) {
V_42 = ( V_42 >> V_237 ) & V_238 ;
V_42 += 1 ;
V_125 -> V_7 . V_188 = V_42 ;
V_125 -> V_7 . V_239 = F_23 ( V_66 + V_240 ) ;
} else {
V_125 -> V_7 . V_188 = 0 ;
}
V_42 = F_23 ( V_66 + V_233 ) ;
if ( V_42 & V_241 )
V_125 -> V_7 . V_8 |= V_9 ;
else
V_125 -> V_7 . V_8 &= ~ V_9 ;
V_42 = F_23 ( V_66 + V_233 ) >> V_242 ;
V_42 &= V_243 ;
V_42 += 1 ;
V_125 -> V_7 . V_214 = V_42 ;
V_125 -> V_7 . V_224 = F_23 ( V_66 + V_244 ) ;
}
static inline void F_66 ( struct V_1 * V_2 )
{
struct V_124 * V_125 = V_2 -> V_5 ;
V_2 -> V_3 [ 0 ] . V_151 = V_125 -> V_245
+ ( V_2 -> V_73 * V_125 -> V_191 ) ;
V_2 -> V_3 [ 0 ] . V_116 = V_125 -> V_246
+ ( V_2 -> V_73 * V_125 -> V_191 ) ;
V_2 -> V_3 [ 0 ] . V_4 = NULL ;
V_2 -> V_3 [ 1 ] . V_151 = V_2 -> V_3 [ 0 ] . V_151
+ V_125 -> V_191 / 2 ;
V_2 -> V_3 [ 1 ] . V_116 = V_2 -> V_3 [ 0 ] . V_116
+ V_125 -> V_191 / 2 ;
V_2 -> V_3 [ 1 ] . V_4 = NULL ;
V_2 -> V_112 = - 1 ;
}
static int F_67 ( struct V_124 * V_125 )
{
int V_225 = V_125 -> V_7 . V_205 ;
struct V_1 * V_2 ;
int V_202 ;
V_125 -> V_206 = F_68 ( ( 1 + V_225 ) * sizeof( * V_2 ) ,
V_247 ) ;
if ( ! V_125 -> V_206 )
return - V_192 ;
for ( V_202 = 0 ; V_202 < V_225 ; V_202 ++ ) {
V_2 = & V_125 -> V_206 [ V_202 ] ;
V_2 -> V_73 = V_202 ;
V_2 -> V_5 = V_125 ;
F_66 ( V_2 ) ;
V_2 -> free = true ;
}
V_2 = & V_125 -> V_206 [ V_225 ] ;
V_2 -> V_73 = V_225 ;
V_2 -> V_5 = V_125 ;
V_2 -> free = false ;
V_125 -> V_6 = V_2 ;
return 0 ;
}
static int F_69 ( struct V_124 * V_125 )
{
int V_225 = V_125 -> V_7 . V_205 ;
int V_182 ;
V_125 -> V_245 = F_70 ( V_125 -> V_77 . V_78 ,
V_225 * V_125 -> V_191 ,
& V_125 -> V_246 , V_247 ,
V_248 ) ;
if ( ! V_125 -> V_245 ) {
F_28 ( V_125 -> V_77 . V_78 , L_26 ,
V_115 , __LINE__ ) ;
return - V_192 ;
}
V_182 = F_67 ( V_125 ) ;
if ( V_182 ) {
F_28 ( V_125 -> V_77 . V_78 , L_27 ,
V_115 , __LINE__ ) ;
F_71 ( V_125 -> V_77 . V_78 ,
V_225 * V_125 -> V_191 ,
V_125 -> V_245 , V_125 -> V_246 ) ;
return V_182 ;
}
return 0 ;
}
static int F_72 ( struct V_124 * V_125 )
{
int V_202 , V_182 ;
if ( ( V_125 -> V_7 . V_10 & 0xfffff ) != V_249 ) {
F_28 ( V_125 -> V_77 . V_78 , L_28 ,
V_125 -> V_7 . V_10 ) ;
return - V_153 ;
}
F_65 ( V_125 ) ;
if ( V_125 -> V_7 . V_214 == 0 ) {
F_28 ( V_125 -> V_77 . V_78 , L_29 ,
V_115 , __LINE__ ) ;
return - V_153 ;
}
F_73 ( & V_125 -> V_189 ) ;
F_74 ( & V_125 -> V_221 ) ;
if ( ! V_125 -> V_191 )
V_125 -> V_191 = V_250 * 2 ;
for ( V_202 = 0 ; V_202 < V_125 -> V_7 . V_214 ; V_202 ++ )
V_125 -> V_219 [ V_202 ] = - 1 ;
V_182 = F_69 ( V_125 ) ;
if ( V_182 ) {
F_28 ( V_125 -> V_77 . V_78 , L_30 ) ;
return V_182 ;
}
F_75 ( & V_125 -> V_223 , F_54 , ( unsigned long ) V_125 ) ;
V_125 -> V_183 = V_251 ;
return 0 ;
}
static int F_76 ( struct V_124 * V_125 )
{
struct V_1 * V_2 ;
int V_202 ;
for ( V_202 = 0 ; V_202 < V_125 -> V_7 . V_205 ; V_202 ++ ) {
V_2 = & V_125 -> V_206 [ V_202 ] ;
F_64 ( V_2 ) ;
}
F_77 ( V_125 -> V_206 ) ;
return 0 ;
}
static void F_78 ( struct V_124 * V_125 )
{
V_125 -> V_183 = V_252 ;
F_79 ( & V_125 -> V_223 ) ;
F_76 ( V_125 ) ;
F_71 ( V_125 -> V_77 . V_78 ,
V_125 -> V_7 . V_205 * V_125 -> V_191 , V_125 -> V_245 ,
V_125 -> V_246 ) ;
}
static inline struct V_195 *
F_80 ( struct V_253 * V_254 )
{
if ( ! V_254 )
return NULL ;
return F_81 ( V_254 , struct V_195 , V_61 ) ;
}
static inline struct V_108 *
F_82 ( struct V_255 * V_256 )
{
return F_81 ( V_256 , struct V_108 , V_257 ) ;
}
static inline void F_83 ( struct V_195 * V_196 )
{
struct V_108 * V_4 ;
int V_182 ;
F_84 (desc, &pch->work_list, node) {
if ( V_4 -> V_198 == V_258 )
continue;
V_182 = F_49 ( V_196 -> V_259 , V_4 ) ;
if ( ! V_182 ) {
V_4 -> V_198 = V_258 ;
} else if ( V_182 == - V_187 ) {
break;
} else {
V_4 -> V_198 = V_199 ;
F_28 ( V_196 -> V_5 -> V_77 . V_78 , L_31 ,
V_115 , __LINE__ , V_4 -> V_257 . V_260 ) ;
F_53 ( & V_196 -> V_200 ) ;
}
}
}
static void F_85 ( unsigned long V_201 )
{
struct V_195 * V_196 = (struct V_195 * ) V_201 ;
struct V_108 * V_4 , * V_261 ;
unsigned long V_181 ;
bool V_262 = false ;
F_50 ( & V_196 -> V_189 , V_181 ) ;
F_58 (desc, _dt, &pch->work_list, node)
if ( V_4 -> V_198 == V_199 ) {
if ( ! V_196 -> V_263 )
F_86 ( & V_4 -> V_257 ) ;
F_87 ( & V_4 -> V_264 , & V_196 -> V_265 ) ;
}
F_83 ( V_196 ) ;
if ( F_88 ( & V_196 -> V_266 ) ) {
F_89 ( & V_196 -> V_259 -> V_5 -> V_189 ) ;
F_31 ( V_196 -> V_259 ) ;
F_90 ( & V_196 -> V_259 -> V_5 -> V_189 ) ;
V_262 = true ;
V_196 -> V_217 = false ;
} else {
F_89 ( & V_196 -> V_259 -> V_5 -> V_189 ) ;
F_35 ( V_196 -> V_259 ) ;
F_90 ( & V_196 -> V_259 -> V_5 -> V_189 ) ;
}
while ( ! F_88 ( & V_196 -> V_265 ) ) {
struct V_267 V_268 ;
V_4 = F_91 ( & V_196 -> V_265 ,
struct V_108 , V_264 ) ;
F_92 ( & V_4 -> V_257 , & V_268 ) ;
if ( V_196 -> V_263 ) {
V_4 -> V_198 = V_269 ;
F_87 ( & V_4 -> V_264 , & V_196 -> V_266 ) ;
if ( V_262 ) {
V_196 -> V_217 = true ;
F_89 ( & V_196 -> V_259 -> V_5 -> V_189 ) ;
F_35 ( V_196 -> V_259 ) ;
F_90 ( & V_196 -> V_259 -> V_5 -> V_189 ) ;
V_262 = false ;
}
} else {
V_4 -> V_198 = FREE ;
F_87 ( & V_4 -> V_264 , & V_196 -> V_5 -> V_270 ) ;
}
F_93 ( & V_4 -> V_257 ) ;
if ( F_94 ( & V_268 ) ) {
F_51 ( & V_196 -> V_189 , V_181 ) ;
F_95 ( & V_268 , NULL ) ;
F_50 ( & V_196 -> V_189 , V_181 ) ;
}
}
F_51 ( & V_196 -> V_189 , V_181 ) ;
if ( V_262 ) {
F_96 ( V_196 -> V_5 -> V_77 . V_78 ) ;
F_97 ( V_196 -> V_5 -> V_77 . V_78 ) ;
}
}
static struct V_253 * F_98 ( struct V_271 * V_272 ,
struct V_273 * V_274 )
{
int V_275 = V_272 -> V_276 ;
struct V_124 * V_125 = V_274 -> V_277 ;
unsigned int V_278 ;
if ( ! V_125 )
return NULL ;
if ( V_275 != 1 )
return NULL ;
V_278 = V_272 -> args [ 0 ] ;
if ( V_278 >= V_125 -> V_279 )
return NULL ;
return F_99 ( & V_125 -> V_280 [ V_278 ] . V_61 ) ;
}
static int F_100 ( struct V_253 * V_61 )
{
struct V_195 * V_196 = F_80 ( V_61 ) ;
struct V_124 * V_125 = V_196 -> V_5 ;
unsigned long V_181 ;
F_50 ( & V_125 -> V_189 , V_181 ) ;
F_101 ( V_61 ) ;
V_196 -> V_263 = false ;
V_196 -> V_259 = F_62 ( V_125 ) ;
if ( ! V_196 -> V_259 ) {
F_51 ( & V_125 -> V_189 , V_181 ) ;
return - V_192 ;
}
F_75 ( & V_196 -> V_200 , F_85 , ( unsigned long ) V_196 ) ;
F_51 ( & V_125 -> V_189 , V_181 ) ;
return 1 ;
}
static enum V_281
F_102 ( enum V_282 V_283 )
{
switch ( V_283 ) {
case V_129 :
return V_284 ;
case V_130 :
return V_285 ;
case V_286 :
return V_287 ;
default:
return V_288 ;
}
}
static void F_103 ( struct V_195 * V_196 )
{
if ( V_196 -> V_283 != V_288 )
F_104 ( V_196 -> V_61 . V_289 -> V_78 , V_196 -> V_290 ,
1 << V_196 -> V_291 , V_196 -> V_283 , 0 ) ;
V_196 -> V_283 = V_288 ;
}
static bool F_105 ( struct V_195 * V_196 ,
enum V_282 V_283 )
{
struct V_289 * V_78 = V_196 -> V_61 . V_289 -> V_78 ;
enum V_281 V_292 = F_102 ( V_283 ) ;
if ( V_196 -> V_283 == V_292 )
return true ;
F_103 ( V_196 ) ;
V_196 -> V_290 = F_106 ( V_78 , V_196 -> V_293 ,
1 << V_196 -> V_291 , V_292 , 0 ) ;
if ( F_107 ( V_78 , V_196 -> V_290 ) )
return false ;
V_196 -> V_283 = V_292 ;
return true ;
}
static int V_121 ( struct V_253 * V_61 ,
struct V_294 * V_295 )
{
struct V_195 * V_196 = F_80 ( V_61 ) ;
F_103 ( V_196 ) ;
if ( V_295 -> V_296 == V_129 ) {
if ( V_295 -> V_149 )
V_196 -> V_293 = V_295 -> V_149 ;
if ( V_295 -> V_297 )
V_196 -> V_291 = F_108 ( V_295 -> V_297 ) ;
if ( V_295 -> V_298 )
V_196 -> V_299 = V_295 -> V_298 ;
} else if ( V_295 -> V_296 == V_130 ) {
if ( V_295 -> V_148 )
V_196 -> V_293 = V_295 -> V_148 ;
if ( V_295 -> V_300 )
V_196 -> V_291 = F_108 ( V_295 -> V_300 ) ;
if ( V_295 -> V_301 )
V_196 -> V_299 = V_295 -> V_301 ;
}
return 0 ;
}
static int F_109 ( struct V_253 * V_61 )
{
struct V_195 * V_196 = F_80 ( V_61 ) ;
struct V_108 * V_4 ;
unsigned long V_181 ;
struct V_124 * V_125 = V_196 -> V_5 ;
F_110 ( V_302 ) ;
bool V_262 = false ;
F_111 ( V_125 -> V_77 . V_78 ) ;
F_50 ( & V_196 -> V_189 , V_181 ) ;
F_89 ( & V_125 -> V_189 ) ;
F_31 ( V_196 -> V_259 ) ;
F_90 ( & V_125 -> V_189 ) ;
V_196 -> V_259 -> V_3 [ 0 ] . V_4 = NULL ;
V_196 -> V_259 -> V_3 [ 1 ] . V_4 = NULL ;
V_196 -> V_259 -> V_112 = - 1 ;
V_262 = V_196 -> V_217 ;
V_196 -> V_217 = false ;
F_84 (desc, &pch->submitted_list, node) {
V_4 -> V_198 = FREE ;
F_86 ( & V_4 -> V_257 ) ;
}
F_84 (desc, &pch->work_list , node) {
V_4 -> V_198 = FREE ;
F_86 ( & V_4 -> V_257 ) ;
}
F_112 ( & V_196 -> V_303 , & V_125 -> V_270 ) ;
F_112 ( & V_196 -> V_266 , & V_125 -> V_270 ) ;
F_112 ( & V_196 -> V_265 , & V_125 -> V_270 ) ;
F_51 ( & V_196 -> V_189 , V_181 ) ;
F_96 ( V_125 -> V_77 . V_78 ) ;
if ( V_262 )
F_97 ( V_125 -> V_77 . V_78 ) ;
F_97 ( V_125 -> V_77 . V_78 ) ;
return 0 ;
}
static int F_113 ( struct V_253 * V_61 )
{
struct V_195 * V_196 = F_80 ( V_61 ) ;
struct V_124 * V_125 = V_196 -> V_5 ;
unsigned long V_181 ;
F_111 ( V_125 -> V_77 . V_78 ) ;
F_50 ( & V_196 -> V_189 , V_181 ) ;
F_89 ( & V_125 -> V_189 ) ;
F_31 ( V_196 -> V_259 ) ;
F_90 ( & V_125 -> V_189 ) ;
F_51 ( & V_196 -> V_189 , V_181 ) ;
F_96 ( V_125 -> V_77 . V_78 ) ;
F_97 ( V_125 -> V_77 . V_78 ) ;
return 0 ;
}
static void F_114 ( struct V_253 * V_61 )
{
struct V_195 * V_196 = F_80 ( V_61 ) ;
struct V_124 * V_125 = V_196 -> V_5 ;
unsigned long V_181 ;
F_79 ( & V_196 -> V_200 ) ;
F_111 ( V_196 -> V_5 -> V_77 . V_78 ) ;
F_50 ( & V_125 -> V_189 , V_181 ) ;
F_64 ( V_196 -> V_259 ) ;
V_196 -> V_259 = NULL ;
if ( V_196 -> V_263 )
F_112 ( & V_196 -> V_266 , & V_196 -> V_5 -> V_270 ) ;
F_51 ( & V_125 -> V_189 , V_181 ) ;
F_96 ( V_196 -> V_5 -> V_77 . V_78 ) ;
F_97 ( V_196 -> V_5 -> V_77 . V_78 ) ;
F_103 ( V_196 ) ;
}
static int F_115 ( struct V_195 * V_196 ,
struct V_108 * V_4 )
{
struct V_1 * V_2 = V_196 -> V_259 ;
struct V_124 * V_125 = V_196 -> V_5 ;
void T_3 * V_66 = V_2 -> V_5 -> V_67 ;
T_1 V_42 , V_62 ;
F_111 ( V_125 -> V_77 . V_78 ) ;
V_42 = V_62 = 0 ;
if ( V_4 -> V_113 . V_156 ) {
V_42 = F_23 ( V_66 + F_116 ( V_2 -> V_73 ) ) ;
V_62 = V_4 -> V_144 . V_148 ;
} else {
V_42 = F_23 ( V_66 + F_117 ( V_2 -> V_73 ) ) ;
V_62 = V_4 -> V_144 . V_149 ;
}
F_96 ( V_196 -> V_5 -> V_77 . V_78 ) ;
F_97 ( V_125 -> V_77 . V_78 ) ;
if ( ! V_42 )
return 0 ;
return V_42 - V_62 ;
}
static enum V_304
F_118 ( struct V_253 * V_61 , T_4 V_260 ,
struct V_305 * V_306 )
{
enum V_304 V_182 ;
unsigned long V_181 ;
struct V_108 * V_4 , * V_307 = NULL , * V_308 = NULL ;
struct V_195 * V_196 = F_80 ( V_61 ) ;
unsigned int V_309 , V_310 = 0 ;
V_182 = F_119 ( V_61 , V_260 , V_306 ) ;
if ( ! V_306 )
return V_182 ;
if ( V_182 == V_311 )
goto V_312;
F_50 ( & V_196 -> V_189 , V_181 ) ;
F_89 ( & V_196 -> V_259 -> V_5 -> V_189 ) ;
if ( V_196 -> V_259 -> V_112 != - 1 )
V_307 = V_196 -> V_259 -> V_3 [ V_196 -> V_259 -> V_112 ] . V_4 ;
V_308 = V_196 -> V_259 -> V_3 [ V_196 -> V_259 -> V_111 ] . V_4 ;
F_84 (desc, &pch->work_list, node) {
if ( V_4 -> V_198 == V_199 )
V_309 = V_4 -> V_313 ;
else if ( V_307 && V_4 == V_307 )
V_309 =
F_115 ( V_196 , V_4 ) ;
else if ( V_4 -> V_198 == V_258 )
if ( V_4 == V_308 )
V_309 = 0 ;
else
V_309 = V_4 -> V_313 ;
else
V_309 = 0 ;
V_310 += V_4 -> V_313 - V_309 ;
if ( V_4 -> V_257 . V_260 == V_260 ) {
switch ( V_4 -> V_198 ) {
case V_199 :
V_182 = V_311 ;
break;
case V_269 :
case V_258 :
V_182 = V_314 ;
break;
default:
F_120 ( 1 ) ;
}
break;
}
if ( V_4 -> V_315 )
V_310 = 0 ;
}
F_90 ( & V_196 -> V_259 -> V_5 -> V_189 ) ;
F_51 ( & V_196 -> V_189 , V_181 ) ;
V_312:
F_121 ( V_306 , V_310 ) ;
return V_182 ;
}
static void F_122 ( struct V_253 * V_61 )
{
struct V_195 * V_196 = F_80 ( V_61 ) ;
unsigned long V_181 ;
F_50 ( & V_196 -> V_189 , V_181 ) ;
if ( F_88 ( & V_196 -> V_266 ) ) {
F_120 ( F_88 ( & V_196 -> V_303 ) ) ;
V_196 -> V_217 = true ;
F_111 ( V_196 -> V_5 -> V_77 . V_78 ) ;
}
F_112 ( & V_196 -> V_303 , & V_196 -> V_266 ) ;
F_51 ( & V_196 -> V_189 , V_181 ) ;
F_85 ( ( unsigned long ) V_196 ) ;
}
static T_4 F_123 ( struct V_255 * V_256 )
{
struct V_108 * V_4 , * V_315 = F_82 ( V_256 ) ;
struct V_195 * V_196 = F_80 ( V_256 -> V_61 ) ;
T_4 V_260 ;
unsigned long V_181 ;
F_50 ( & V_196 -> V_189 , V_181 ) ;
while ( ! F_88 ( & V_315 -> V_264 ) ) {
V_4 = F_124 ( V_315 -> V_264 . V_316 , struct V_108 , V_264 ) ;
if ( V_196 -> V_263 ) {
V_4 -> V_257 . V_317 = V_315 -> V_257 . V_317 ;
V_4 -> V_257 . V_318 = V_315 -> V_257 . V_318 ;
}
V_4 -> V_315 = false ;
F_125 ( & V_4 -> V_257 ) ;
F_87 ( & V_4 -> V_264 , & V_196 -> V_303 ) ;
}
V_315 -> V_315 = true ;
V_260 = F_125 ( & V_315 -> V_257 ) ;
F_57 ( & V_315 -> V_264 , & V_196 -> V_303 ) ;
F_51 ( & V_196 -> V_189 , V_181 ) ;
return V_260 ;
}
static inline void F_126 ( struct V_108 * V_4 )
{
V_4 -> V_113 . V_178 = V_319 ;
V_4 -> V_113 . V_174 = V_320 ;
V_4 -> V_113 . V_176 = V_320 ;
V_4 -> V_257 . V_321 = F_123 ;
F_74 ( & V_4 -> V_264 ) ;
}
static int F_127 ( struct V_124 * V_125 , T_5 V_322 , int V_275 )
{
struct V_108 * V_4 ;
unsigned long V_181 ;
int V_202 ;
V_4 = F_128 ( V_275 , sizeof( * V_4 ) , V_322 ) ;
if ( ! V_4 )
return 0 ;
F_50 ( & V_125 -> V_323 , V_181 ) ;
for ( V_202 = 0 ; V_202 < V_275 ; V_202 ++ ) {
F_126 ( & V_4 [ V_202 ] ) ;
F_57 ( & V_4 [ V_202 ] . V_264 , & V_125 -> V_270 ) ;
}
F_51 ( & V_125 -> V_323 , V_181 ) ;
return V_275 ;
}
static struct V_108 * F_129 ( struct V_124 * V_125 )
{
struct V_108 * V_4 = NULL ;
unsigned long V_181 ;
F_50 ( & V_125 -> V_323 , V_181 ) ;
if ( ! F_88 ( & V_125 -> V_270 ) ) {
V_4 = F_124 ( V_125 -> V_270 . V_316 ,
struct V_108 , V_264 ) ;
F_130 ( & V_4 -> V_264 ) ;
V_4 -> V_198 = V_269 ;
V_4 -> V_257 . V_317 = NULL ;
}
F_51 ( & V_125 -> V_323 , V_181 ) ;
return V_4 ;
}
static struct V_108 * F_131 ( struct V_195 * V_196 )
{
struct V_124 * V_125 = V_196 -> V_5 ;
T_2 * V_324 = V_196 -> V_61 . V_325 ;
struct V_108 * V_4 ;
V_4 = F_129 ( V_125 ) ;
if ( ! V_4 ) {
if ( ! F_127 ( V_125 , V_326 , 1 ) )
return NULL ;
V_4 = F_129 ( V_125 ) ;
if ( ! V_4 ) {
F_28 ( V_196 -> V_5 -> V_77 . V_78 ,
L_32 , V_115 , __LINE__ ) ;
return NULL ;
}
}
V_4 -> V_197 = V_196 ;
V_4 -> V_257 . V_260 = 0 ;
F_132 ( & V_4 -> V_257 ) ;
V_4 -> V_17 = V_324 ? V_196 -> V_61 . V_278 : 0 ;
V_4 -> V_113 . V_7 = & V_196 -> V_5 -> V_7 ;
F_133 ( & V_4 -> V_257 , & V_196 -> V_61 ) ;
return V_4 ;
}
static inline void F_134 ( struct V_142 * V_144 ,
T_6 V_41 , T_6 V_327 , T_7 V_328 )
{
V_144 -> V_147 = V_328 ;
V_144 -> V_149 = V_41 ;
V_144 -> V_148 = V_327 ;
}
static struct V_108 *
F_135 ( struct V_195 * V_196 , T_6 V_41 ,
T_6 V_327 , T_7 V_328 )
{
struct V_108 * V_4 = F_131 ( V_196 ) ;
if ( ! V_4 ) {
F_28 ( V_196 -> V_5 -> V_77 . V_78 , L_33 ,
V_115 , __LINE__ ) ;
return NULL ;
}
F_134 ( & V_4 -> V_144 , V_41 , V_327 , V_328 ) ;
return V_4 ;
}
static inline int F_136 ( struct V_108 * V_4 , T_7 V_328 )
{
struct V_195 * V_196 = V_4 -> V_197 ;
struct V_124 * V_125 = V_196 -> V_5 ;
int V_299 ;
V_299 = V_125 -> V_7 . V_229 / 8 ;
V_299 *= V_125 -> V_7 . V_232 / V_125 -> V_7 . V_205 ;
V_299 >>= V_4 -> V_113 . V_171 ;
if ( V_299 > 16 )
V_299 = 16 ;
while ( V_299 > 1 ) {
if ( ! ( V_328 % ( V_299 << V_4 -> V_113 . V_171 ) ) )
break;
V_299 -- ;
}
return V_299 ;
}
static struct V_255 * F_137 (
struct V_253 * V_61 , T_6 V_329 , T_7 V_328 ,
T_7 V_330 , enum V_282 V_296 ,
unsigned long V_181 )
{
struct V_108 * V_4 = NULL , * V_331 = NULL ;
struct V_195 * V_196 = F_80 ( V_61 ) ;
struct V_124 * V_125 = V_196 -> V_5 ;
unsigned int V_202 ;
T_6 V_41 ;
T_6 V_327 ;
if ( V_328 % V_330 != 0 )
return NULL ;
if ( ! F_138 ( V_296 ) ) {
F_28 ( V_196 -> V_5 -> V_77 . V_78 , L_34 ,
V_115 , __LINE__ ) ;
return NULL ;
}
if ( ! F_105 ( V_196 , V_296 ) )
return NULL ;
for ( V_202 = 0 ; V_202 < V_328 / V_330 ; V_202 ++ ) {
V_4 = F_131 ( V_196 ) ;
if ( ! V_4 ) {
F_28 ( V_196 -> V_5 -> V_77 . V_78 , L_33 ,
V_115 , __LINE__ ) ;
if ( ! V_331 )
return NULL ;
F_50 ( & V_125 -> V_323 , V_181 ) ;
while ( ! F_88 ( & V_331 -> V_264 ) ) {
V_4 = F_124 ( V_331 -> V_264 . V_316 ,
struct V_108 , V_264 ) ;
F_87 ( & V_4 -> V_264 , & V_125 -> V_270 ) ;
}
F_87 ( & V_331 -> V_264 , & V_125 -> V_270 ) ;
F_51 ( & V_125 -> V_323 , V_181 ) ;
return NULL ;
}
switch ( V_296 ) {
case V_129 :
V_4 -> V_113 . V_156 = 1 ;
V_4 -> V_113 . V_158 = 0 ;
V_327 = V_329 ;
V_41 = V_196 -> V_290 ;
break;
case V_130 :
V_4 -> V_113 . V_156 = 0 ;
V_4 -> V_113 . V_158 = 1 ;
V_327 = V_196 -> V_290 ;
V_41 = V_329 ;
break;
default:
break;
}
V_4 -> V_128 = V_296 ;
V_4 -> V_113 . V_171 = V_196 -> V_291 ;
V_4 -> V_113 . V_168 = 1 ;
V_4 -> V_313 = V_330 ;
F_134 ( & V_4 -> V_144 , V_41 , V_327 , V_330 ) ;
if ( ! V_331 )
V_331 = V_4 ;
else
F_57 ( & V_4 -> V_264 , & V_331 -> V_264 ) ;
V_329 += V_330 ;
}
if ( ! V_4 )
return NULL ;
V_196 -> V_263 = true ;
V_4 -> V_257 . V_181 = V_181 ;
return & V_4 -> V_257 ;
}
static struct V_255 *
F_139 ( struct V_253 * V_61 , T_6 V_41 ,
T_6 V_327 , T_7 V_328 , unsigned long V_181 )
{
struct V_108 * V_4 ;
struct V_195 * V_196 = F_80 ( V_61 ) ;
struct V_124 * V_125 ;
int V_332 ;
if ( F_140 ( ! V_196 || ! V_328 ) )
return NULL ;
V_125 = V_196 -> V_5 ;
V_4 = F_135 ( V_196 , V_41 , V_327 , V_328 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_113 . V_156 = 1 ;
V_4 -> V_113 . V_158 = 1 ;
V_4 -> V_128 = V_131 ;
V_332 = V_125 -> V_7 . V_229 / 8 ;
while ( ( V_327 | V_41 | V_328 ) & ( V_332 - 1 ) )
V_332 /= 2 ;
V_4 -> V_113 . V_171 = 0 ;
while ( V_332 != ( 1 << V_4 -> V_113 . V_171 ) )
V_4 -> V_113 . V_171 ++ ;
if ( V_4 -> V_113 . V_171 * 8 < V_125 -> V_7 . V_229 )
V_4 -> V_113 . V_168 = 1 ;
V_4 -> V_113 . V_168 = F_136 ( V_4 , V_328 ) ;
V_4 -> V_313 = V_328 ;
V_4 -> V_257 . V_181 = V_181 ;
return & V_4 -> V_257 ;
}
static void F_141 ( struct V_124 * V_125 ,
struct V_108 * V_331 )
{
unsigned long V_181 ;
struct V_108 * V_4 ;
if ( ! V_331 )
return;
F_50 ( & V_125 -> V_323 , V_181 ) ;
while ( ! F_88 ( & V_331 -> V_264 ) ) {
V_4 = F_124 ( V_331 -> V_264 . V_316 ,
struct V_108 , V_264 ) ;
F_87 ( & V_4 -> V_264 , & V_125 -> V_270 ) ;
}
F_87 ( & V_331 -> V_264 , & V_125 -> V_270 ) ;
F_51 ( & V_125 -> V_323 , V_181 ) ;
}
static struct V_255 *
F_142 ( struct V_253 * V_61 , struct V_333 * V_334 ,
unsigned int V_335 , enum V_282 V_296 ,
unsigned long V_322 , void * V_336 )
{
struct V_108 * V_331 , * V_4 = NULL ;
struct V_195 * V_196 = F_80 ( V_61 ) ;
struct V_333 * V_337 ;
int V_202 ;
if ( F_140 ( ! V_196 || ! V_334 || ! V_335 ) )
return NULL ;
if ( ! F_105 ( V_196 , V_296 ) )
return NULL ;
V_331 = NULL ;
F_143 (sgl, sg, sg_len, i) {
V_4 = F_131 ( V_196 ) ;
if ( ! V_4 ) {
struct V_124 * V_125 = V_196 -> V_5 ;
F_28 ( V_196 -> V_5 -> V_77 . V_78 ,
L_33 ,
V_115 , __LINE__ ) ;
F_141 ( V_125 , V_331 ) ;
return NULL ;
}
if ( ! V_331 )
V_331 = V_4 ;
else
F_57 ( & V_4 -> V_264 , & V_331 -> V_264 ) ;
if ( V_296 == V_129 ) {
V_4 -> V_113 . V_156 = 1 ;
V_4 -> V_113 . V_158 = 0 ;
F_134 ( & V_4 -> V_144 , V_196 -> V_290 , F_144 ( V_337 ) ,
F_145 ( V_337 ) ) ;
} else {
V_4 -> V_113 . V_156 = 0 ;
V_4 -> V_113 . V_158 = 1 ;
F_134 ( & V_4 -> V_144 , F_144 ( V_337 ) , V_196 -> V_290 ,
F_145 ( V_337 ) ) ;
}
V_4 -> V_113 . V_171 = V_196 -> V_291 ;
V_4 -> V_113 . V_168 = 1 ;
V_4 -> V_128 = V_296 ;
V_4 -> V_313 = F_145 ( V_337 ) ;
}
V_4 -> V_257 . V_181 = V_322 ;
return & V_4 -> V_257 ;
}
static T_8 F_146 ( int V_338 , void * V_201 )
{
if ( F_55 ( V_201 ) )
return V_339 ;
else
return V_340 ;
}
static int T_9 F_147 ( struct V_289 * V_78 )
{
struct V_341 * V_342 = F_148 ( V_78 ) ;
F_149 ( V_78 ) ;
if ( ! F_150 ( V_78 ) ) {
F_151 ( V_342 ) ;
}
F_152 ( V_342 ) ;
return 0 ;
}
static int T_9 F_153 ( struct V_289 * V_78 )
{
struct V_341 * V_342 = F_148 ( V_78 ) ;
int V_182 ;
V_182 = F_154 ( V_342 ) ;
if ( V_182 )
return V_182 ;
if ( ! F_150 ( V_78 ) )
V_182 = F_155 ( V_342 ) ;
F_156 ( V_78 ) ;
return V_182 ;
}
static int
F_157 ( struct V_341 * V_343 , const struct V_344 * V_73 )
{
struct V_121 * V_7 ;
struct V_124 * V_125 ;
struct V_195 * V_196 , * V_345 ;
struct V_346 * V_347 ;
struct V_348 * V_349 ;
int V_202 , V_182 , V_338 ;
int V_205 ;
struct V_350 * V_351 = V_343 -> V_78 . V_352 ;
V_182 = F_158 ( & V_343 -> V_78 , F_159 ( 32 ) ) ;
if ( V_182 )
return V_182 ;
V_125 = F_160 ( & V_343 -> V_78 , sizeof( * V_125 ) , V_247 ) ;
if ( ! V_125 )
return - V_192 ;
V_347 = & V_125 -> V_77 ;
V_347 -> V_78 = & V_343 -> V_78 ;
V_125 -> V_191 = 0 ;
for ( V_202 = 0 ; V_202 < F_161 ( V_353 ) ; V_202 ++ )
if ( F_162 ( V_351 , V_353 [ V_202 ] . V_354 ) )
V_125 -> V_126 |= V_353 [ V_202 ] . V_73 ;
V_349 = & V_343 -> V_349 ;
V_125 -> V_67 = F_163 ( & V_343 -> V_78 , V_349 ) ;
if ( F_164 ( V_125 -> V_67 ) )
return F_165 ( V_125 -> V_67 ) ;
F_166 ( V_343 , V_125 ) ;
for ( V_202 = 0 ; V_202 < V_355 ; V_202 ++ ) {
V_338 = V_343 -> V_338 [ V_202 ] ;
if ( V_338 ) {
V_182 = F_167 ( & V_343 -> V_78 , V_338 ,
F_146 , 0 ,
F_168 ( & V_343 -> V_78 ) , V_125 ) ;
if ( V_182 )
return V_182 ;
} else {
break;
}
}
V_7 = & V_125 -> V_7 ;
V_7 -> V_10 = V_343 -> V_356 ;
V_182 = F_72 ( V_125 ) ;
if ( V_182 )
return V_182 ;
F_74 ( & V_125 -> V_270 ) ;
F_73 ( & V_125 -> V_323 ) ;
if ( ! F_127 ( V_125 , V_247 , V_357 ) )
F_169 ( & V_343 -> V_78 , L_35 ) ;
F_74 ( & V_347 -> V_206 ) ;
V_205 = F_170 ( int , V_7 -> V_188 , V_7 -> V_205 ) ;
V_125 -> V_279 = V_205 ;
V_125 -> V_280 = F_68 ( V_205 * sizeof( * V_196 ) , V_247 ) ;
if ( ! V_125 -> V_280 ) {
V_182 = - V_192 ;
goto V_358;
}
for ( V_202 = 0 ; V_202 < V_205 ; V_202 ++ ) {
V_196 = & V_125 -> V_280 [ V_202 ] ;
V_196 -> V_61 . V_325 = V_343 -> V_78 . V_352 ;
F_74 ( & V_196 -> V_303 ) ;
F_74 ( & V_196 -> V_266 ) ;
F_74 ( & V_196 -> V_265 ) ;
F_73 ( & V_196 -> V_189 ) ;
V_196 -> V_259 = NULL ;
V_196 -> V_61 . V_289 = V_347 ;
V_196 -> V_5 = V_125 ;
V_196 -> V_283 = V_288 ;
F_57 ( & V_196 -> V_61 . V_350 , & V_347 -> V_206 ) ;
}
F_171 ( V_359 , V_347 -> V_360 ) ;
if ( V_7 -> V_188 ) {
F_171 ( V_361 , V_347 -> V_360 ) ;
F_171 ( V_362 , V_347 -> V_360 ) ;
F_171 ( V_363 , V_347 -> V_360 ) ;
}
V_347 -> V_364 = F_100 ;
V_347 -> V_365 = F_114 ;
V_347 -> V_366 = F_139 ;
V_347 -> V_367 = F_137 ;
V_347 -> V_368 = F_118 ;
V_347 -> V_369 = F_142 ;
V_347 -> V_370 = V_121 ;
V_347 -> V_371 = F_113 ;
V_347 -> V_372 = F_109 ;
V_347 -> V_373 = F_122 ;
V_347 -> V_374 = V_375 ;
V_347 -> V_376 = V_375 ;
V_347 -> V_377 = F_172 ( V_130 ) | F_172 ( V_129 ) ;
V_347 -> V_378 = V_379 ;
V_347 -> V_380 = ( ( V_125 -> V_126 & V_127 ) ?
1 : V_381 ) ;
V_182 = F_173 ( V_347 ) ;
if ( V_182 ) {
F_28 ( & V_343 -> V_78 , L_36 ) ;
goto V_382;
}
if ( V_343 -> V_78 . V_352 ) {
V_182 = F_174 ( V_343 -> V_78 . V_352 ,
F_98 , V_125 ) ;
if ( V_182 ) {
F_28 ( & V_343 -> V_78 ,
L_37 ) ;
}
}
V_343 -> V_78 . V_383 = & V_125 -> V_383 ;
V_182 = F_175 ( & V_343 -> V_78 , 1900800 ) ;
if ( V_182 )
F_28 ( & V_343 -> V_78 , L_38 ) ;
F_34 ( & V_343 -> V_78 ,
L_39 , V_343 -> V_356 ) ;
F_34 ( & V_343 -> V_78 ,
L_40 ,
V_7 -> V_232 , V_7 -> V_229 / 8 , V_7 -> V_205 ,
V_7 -> V_188 , V_7 -> V_214 ) ;
F_176 ( & V_343 -> V_78 ) ;
F_177 ( & V_343 -> V_78 ) ;
F_178 ( & V_343 -> V_78 , V_384 ) ;
F_96 ( & V_343 -> V_78 ) ;
F_97 ( & V_343 -> V_78 ) ;
return 0 ;
V_382:
F_58 (pch, _p, &pl330->ddma.channels,
chan.device_node) {
F_59 ( & V_196 -> V_61 . V_350 ) ;
if ( V_196 -> V_259 ) {
F_109 ( & V_196 -> V_61 ) ;
F_114 ( & V_196 -> V_61 ) ;
}
}
V_358:
F_78 ( V_125 ) ;
return V_182 ;
}
static int F_179 ( struct V_341 * V_343 )
{
struct V_124 * V_125 = F_180 ( V_343 ) ;
struct V_195 * V_196 , * V_345 ;
int V_202 , V_338 ;
F_181 ( V_125 -> V_77 . V_78 ) ;
if ( V_343 -> V_78 . V_352 )
F_182 ( V_343 -> V_78 . V_352 ) ;
for ( V_202 = 0 ; V_202 < V_355 ; V_202 ++ ) {
V_338 = V_343 -> V_338 [ V_202 ] ;
if ( V_338 )
F_183 ( & V_343 -> V_78 , V_338 , V_125 ) ;
}
F_184 ( & V_125 -> V_77 ) ;
F_58 (pch, _p, &pl330->ddma.channels,
chan.device_node) {
F_59 ( & V_196 -> V_61 . V_350 ) ;
if ( V_196 -> V_259 ) {
F_109 ( & V_196 -> V_61 ) ;
F_114 ( & V_196 -> V_61 ) ;
}
}
F_78 ( V_125 ) ;
return 0 ;
}
