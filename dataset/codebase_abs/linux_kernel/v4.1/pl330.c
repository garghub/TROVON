static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 [ 0 ] . V_4 == NULL && V_2 -> V_3 [ 1 ] . V_4 == NULL ;
}
static inline bool F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 [ 0 ] . V_4 != NULL && V_2 -> V_3 [ 1 ] . V_4 != NULL ;
}
static inline bool F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_5 -> V_6 == V_2 ;
}
static inline bool F_4 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 -> V_7 . V_8 & V_9 ) ? true : false ;
}
static inline T_1 F_5 ( T_1 V_10 )
{
return ( V_10 >> V_11 ) & V_12 ;
}
static inline T_1 F_6 ( unsigned V_13 , T_2 V_14 [] ,
enum V_15 V_16 , T_3 V_17 )
{
if ( V_13 )
return V_18 ;
V_14 [ 0 ] = V_19 ;
V_14 [ 0 ] |= ( V_16 << 1 ) ;
* ( ( V_20 * ) & V_14 [ 1 ] ) = F_7 ( V_17 ) ;
F_8 ( V_18 , L_1 ,
V_16 == 1 ? L_2 : L_3 , V_17 ) ;
return V_18 ;
}
static inline T_1 F_9 ( unsigned V_13 , T_2 V_14 [] )
{
if ( V_13 )
return V_21 ;
V_14 [ 0 ] = V_22 ;
F_8 ( V_21 , L_4 ) ;
return V_21 ;
}
static inline T_1 F_10 ( unsigned V_13 , T_2 V_14 [] , T_2 V_23 )
{
if ( V_13 )
return V_24 ;
V_14 [ 0 ] = V_25 ;
V_23 &= 0x1f ;
V_23 <<= 3 ;
V_14 [ 1 ] = V_23 ;
F_8 ( V_24 , L_5 , V_23 >> 3 ) ;
return V_24 ;
}
static inline T_1 F_11 ( unsigned V_13 , T_2 V_14 [] , enum V_26 V_27 )
{
if ( V_13 )
return V_28 ;
V_14 [ 0 ] = V_29 ;
if ( V_27 == V_30 )
V_14 [ 0 ] |= ( 0 << 1 ) | ( 1 << 0 ) ;
else if ( V_27 == V_31 )
V_14 [ 0 ] |= ( 1 << 1 ) | ( 1 << 0 ) ;
F_8 ( V_28 , L_6 ,
V_27 == V_30 ? 'S' : ( V_27 == V_31 ? 'B' : 'A' ) ) ;
return V_28 ;
}
static inline T_1 F_12 ( unsigned V_13 , T_2 V_14 [] ,
enum V_26 V_27 , T_2 V_23 )
{
if ( V_13 )
return V_32 ;
V_14 [ 0 ] = V_33 ;
if ( V_27 == V_31 )
V_14 [ 0 ] |= ( 1 << 1 ) ;
V_23 &= 0x1f ;
V_23 <<= 3 ;
V_14 [ 1 ] = V_23 ;
F_8 ( V_32 , L_7 ,
V_27 == V_30 ? 'S' : 'B' , V_23 >> 3 ) ;
return V_32 ;
}
static inline T_1 F_13 ( unsigned V_13 , T_2 V_14 [] ,
unsigned V_34 , T_2 V_35 )
{
if ( V_13 )
return V_36 ;
V_14 [ 0 ] = V_37 ;
if ( V_34 )
V_14 [ 0 ] |= ( 1 << 1 ) ;
V_35 -- ;
V_14 [ 1 ] = V_35 ;
F_8 ( V_36 , L_8 , V_34 ? '1' : '0' , V_35 ) ;
return V_36 ;
}
static inline T_1 F_14 ( unsigned V_13 , T_2 V_14 [] ,
const struct V_38 * V_39 )
{
enum V_26 V_27 = V_39 -> V_27 ;
bool V_40 = V_39 -> V_40 ;
unsigned V_34 = V_39 -> V_34 ;
T_2 V_41 = V_39 -> V_41 ;
if ( V_13 )
return V_42 ;
V_14 [ 0 ] = V_43 ;
if ( V_34 )
V_14 [ 0 ] |= ( 1 << 2 ) ;
if ( ! V_40 )
V_14 [ 0 ] |= ( 1 << 4 ) ;
if ( V_27 == V_30 )
V_14 [ 0 ] |= ( 0 << 1 ) | ( 1 << 0 ) ;
else if ( V_27 == V_31 )
V_14 [ 0 ] |= ( 1 << 1 ) | ( 1 << 0 ) ;
V_14 [ 1 ] = V_41 ;
F_8 ( V_42 , L_9 ,
V_40 ? L_10 : L_11 ,
V_27 == V_30 ? 'S' : ( V_27 == V_31 ? 'B' : 'A' ) ,
V_34 ? '1' : '0' ,
V_41 ) ;
return V_42 ;
}
static inline T_1 F_15 ( unsigned V_13 , T_2 V_14 [] )
{
if ( V_13 )
return V_44 ;
V_14 [ 0 ] = V_45 ;
return V_44 ;
}
static inline T_1 F_16 ( unsigned V_13 , T_2 V_14 [] ,
enum V_46 V_47 , T_1 V_17 )
{
if ( V_13 )
return V_48 ;
V_14 [ 0 ] = V_49 ;
V_14 [ 1 ] = V_47 ;
* ( ( V_50 * ) & V_14 [ 2 ] ) = F_17 ( V_17 ) ;
F_8 ( V_48 , L_12 ,
V_47 == V_51 ? L_13 : ( V_47 == V_52 ? L_14 : L_15 ) , V_17 ) ;
return V_48 ;
}
static inline T_1 F_18 ( unsigned V_13 , T_2 V_14 [] )
{
if ( V_13 )
return V_53 ;
V_14 [ 0 ] = V_54 ;
F_8 ( V_53 , L_16 ) ;
return V_53 ;
}
static inline T_1 F_19 ( unsigned V_13 , T_2 V_14 [] )
{
if ( V_13 )
return V_55 ;
V_14 [ 0 ] = V_56 ;
F_8 ( V_55 , L_17 ) ;
return V_55 ;
}
static inline T_1 F_20 ( unsigned V_13 , T_2 V_14 [] , T_2 V_57 )
{
if ( V_13 )
return V_58 ;
V_14 [ 0 ] = V_59 ;
V_57 &= 0x1f ;
V_57 <<= 3 ;
V_14 [ 1 ] = V_57 ;
F_8 ( V_58 , L_18 , V_57 >> 3 ) ;
return V_58 ;
}
static inline T_1 F_21 ( unsigned V_13 , T_2 V_14 [] , enum V_26 V_27 )
{
if ( V_13 )
return V_60 ;
V_14 [ 0 ] = V_61 ;
if ( V_27 == V_30 )
V_14 [ 0 ] |= ( 0 << 1 ) | ( 1 << 0 ) ;
else if ( V_27 == V_31 )
V_14 [ 0 ] |= ( 1 << 1 ) | ( 1 << 0 ) ;
F_8 ( V_60 , L_19 ,
V_27 == V_30 ? 'S' : ( V_27 == V_31 ? 'B' : 'A' ) ) ;
return V_60 ;
}
static inline T_1 F_22 ( unsigned V_13 , T_2 V_14 [] ,
enum V_26 V_27 , T_2 V_23 )
{
if ( V_13 )
return V_62 ;
V_14 [ 0 ] = V_63 ;
if ( V_27 == V_31 )
V_14 [ 0 ] |= ( 1 << 1 ) ;
V_23 &= 0x1f ;
V_23 <<= 3 ;
V_14 [ 1 ] = V_23 ;
F_8 ( V_62 , L_20 ,
V_27 == V_30 ? 'S' : 'B' , V_23 >> 3 ) ;
return V_62 ;
}
static inline T_1 F_23 ( unsigned V_13 , T_2 V_14 [] )
{
if ( V_13 )
return V_64 ;
V_14 [ 0 ] = V_65 ;
F_8 ( V_64 , L_21 ) ;
return V_64 ;
}
static inline T_1 F_24 ( unsigned V_13 , T_2 V_14 [] , T_2 V_57 ,
unsigned V_66 )
{
if ( V_13 )
return V_67 ;
V_14 [ 0 ] = V_68 ;
V_57 &= 0x1f ;
V_57 <<= 3 ;
V_14 [ 1 ] = V_57 ;
if ( V_66 )
V_14 [ 1 ] |= ( 1 << 1 ) ;
F_8 ( V_67 , L_22 ,
V_57 >> 3 , V_66 ? L_23 : L_24 ) ;
return V_67 ;
}
static inline T_1 F_25 ( unsigned V_13 , T_2 V_14 [] ,
enum V_26 V_27 , T_2 V_23 )
{
if ( V_13 )
return V_69 ;
V_14 [ 0 ] = V_70 ;
if ( V_27 == V_30 )
V_14 [ 0 ] |= ( 0 << 1 ) | ( 0 << 0 ) ;
else if ( V_27 == V_31 )
V_14 [ 0 ] |= ( 1 << 1 ) | ( 0 << 0 ) ;
else
V_14 [ 0 ] |= ( 0 << 1 ) | ( 1 << 0 ) ;
V_23 &= 0x1f ;
V_23 <<= 3 ;
V_14 [ 1 ] = V_23 ;
F_8 ( V_69 , L_25 ,
V_27 == V_30 ? 'S' : ( V_27 == V_31 ? 'B' : 'P' ) , V_23 >> 3 ) ;
return V_69 ;
}
static inline T_1 F_26 ( unsigned V_13 , T_2 V_14 [] )
{
if ( V_13 )
return V_71 ;
V_14 [ 0 ] = V_72 ;
F_8 ( V_71 , L_26 ) ;
return V_71 ;
}
static inline T_1 F_27 ( unsigned V_13 , T_2 V_14 [] ,
const struct V_73 * V_39 )
{
T_2 V_74 = V_39 -> V_74 ;
T_1 V_75 = V_39 -> V_75 ;
unsigned V_76 = V_39 -> V_76 ;
if ( V_13 )
return V_77 ;
V_14 [ 0 ] = V_78 ;
V_14 [ 0 ] |= ( V_76 << 1 ) ;
V_14 [ 1 ] = V_74 & 0x7 ;
* ( ( V_50 * ) & V_14 [ 2 ] ) = F_17 ( V_75 ) ;
return V_77 ;
}
static bool F_28 ( struct V_1 * V_2 )
{
void T_4 * V_79 = V_2 -> V_5 -> V_80 ;
unsigned long V_81 = F_29 ( 5 ) ;
do {
if ( ! ( F_30 ( V_79 + V_82 ) & V_83 ) )
break;
F_31 () ;
} while ( -- V_81 );
if ( ! V_81 )
return true ;
return false ;
}
static inline void F_32 ( struct V_1 * V_2 ,
T_2 V_84 [] , bool V_85 )
{
void T_4 * V_79 = V_2 -> V_5 -> V_80 ;
T_1 V_17 ;
V_17 = ( V_84 [ 0 ] << 16 ) | ( V_84 [ 1 ] << 24 ) ;
if ( ! V_85 ) {
V_17 |= ( 1 << 0 ) ;
V_17 |= ( V_2 -> V_86 << 8 ) ;
}
F_33 ( V_17 , V_79 + V_87 ) ;
V_17 = F_34 ( * ( ( V_50 * ) & V_84 [ 2 ] ) ) ;
F_33 ( V_17 , V_79 + V_88 ) ;
if ( F_28 ( V_2 ) ) {
F_35 ( V_2 -> V_5 -> V_89 . V_90 , L_27 ) ;
return;
}
F_33 ( 0 , V_79 + V_91 ) ;
}
static inline T_1 F_36 ( struct V_1 * V_2 )
{
void T_4 * V_79 = V_2 -> V_5 -> V_80 ;
T_1 V_17 ;
if ( F_3 ( V_2 ) )
V_17 = F_30 ( V_79 + V_92 ) & 0xf ;
else
V_17 = F_30 ( V_79 + F_37 ( V_2 -> V_86 ) ) & 0xf ;
switch ( V_17 ) {
case V_93 :
return V_94 ;
case V_95 :
return V_96 ;
case V_97 :
return V_98 ;
case V_99 :
return V_100 ;
case V_101 :
return V_102 ;
case V_103 :
return V_104 ;
case V_105 :
if ( F_3 ( V_2 ) )
return V_106 ;
else
return V_107 ;
case V_108 :
if ( F_3 ( V_2 ) )
return V_106 ;
else
return V_109 ;
case V_110 :
if ( F_3 ( V_2 ) )
return V_106 ;
else
return V_111 ;
case V_112 :
if ( F_3 ( V_2 ) )
return V_106 ;
else
return V_113 ;
case V_114 :
if ( F_3 ( V_2 ) )
return V_106 ;
else
return V_115 ;
case V_116 :
if ( F_3 ( V_2 ) )
return V_106 ;
else
return V_117 ;
default:
return V_106 ;
}
}
static void F_38 ( struct V_1 * V_2 )
{
void T_4 * V_79 = V_2 -> V_5 -> V_80 ;
T_2 V_84 [ 6 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
if ( F_36 ( V_2 ) == V_117 )
F_39 ( V_2 , V_104 | V_113 ) ;
if ( F_36 ( V_2 ) == V_115
|| F_36 ( V_2 ) == V_113
|| F_36 ( V_2 ) == V_94 )
return;
F_15 ( 0 , V_84 ) ;
F_33 ( F_30 ( V_79 + V_118 ) & ~ ( 1 << V_2 -> V_57 ) , V_79 + V_118 ) ;
F_32 ( V_2 , V_84 , F_3 ( V_2 ) ) ;
}
static bool F_40 ( struct V_1 * V_2 )
{
void T_4 * V_79 = V_2 -> V_5 -> V_80 ;
struct V_119 * V_3 ;
struct V_120 * V_4 ;
struct V_73 V_121 ;
unsigned V_76 ;
T_2 V_84 [ 6 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_122 ;
if ( F_36 ( V_2 ) != V_94 )
return true ;
V_122 = 1 - V_2 -> V_123 ;
if ( V_2 -> V_3 [ V_122 ] . V_4 != NULL ) {
V_3 = & V_2 -> V_3 [ V_122 ] ;
} else {
V_122 = V_2 -> V_123 ;
if ( V_2 -> V_3 [ V_122 ] . V_4 != NULL )
V_3 = & V_2 -> V_3 [ V_122 ] ;
else
V_3 = NULL ;
}
if ( ! V_3 )
return true ;
if ( V_122 == V_2 -> V_124 )
return true ;
V_4 = V_3 -> V_4 ;
V_76 = V_4 -> V_125 . V_126 ? 1 : 0 ;
if ( F_4 ( V_2 ) && ! V_76 )
F_41 ( V_2 -> V_5 -> V_89 . V_90 , L_28 ,
V_127 , __LINE__ ) ;
V_121 . V_74 = V_2 -> V_86 ;
V_121 . V_75 = V_3 -> V_128 ;
V_121 . V_76 = V_76 ;
F_27 ( 0 , V_84 , & V_121 ) ;
F_33 ( F_30 ( V_79 + V_118 ) | ( 1 << V_2 -> V_57 ) , V_79 + V_118 ) ;
F_32 ( V_2 , V_84 , true ) ;
V_2 -> V_124 = V_122 ;
return true ;
}
static bool F_42 ( struct V_1 * V_2 )
{
switch ( F_36 ( V_2 ) ) {
case V_117 :
F_39 ( V_2 , V_104 | V_113 ) ;
if ( F_36 ( V_2 ) == V_113 )
F_39 (thrd, PL330_STATE_STOPPED)
case V_104 :
F_38 ( V_2 ) ;
case V_113 :
case V_115 :
F_39 (thrd, PL330_STATE_STOPPED)
case V_94 :
return F_40 ( V_2 ) ;
case V_111 :
case V_109 :
case V_107 :
case V_100 :
case V_98 :
case V_96 :
return true ;
case V_102 :
default:
return false ;
}
}
static inline int F_43 ( unsigned V_13 , T_2 V_14 [] ,
const struct V_129 * V_130 , int V_131 )
{
int V_132 = 0 ;
struct V_133 * V_7 = V_130 -> V_4 -> V_125 . V_7 ;
if ( F_5 ( V_7 -> V_10 ) >= V_134 ) {
while ( V_131 -- ) {
V_132 += F_11 ( V_13 , & V_14 [ V_132 ] , V_135 ) ;
V_132 += F_21 ( V_13 , & V_14 [ V_132 ] , V_135 ) ;
}
} else {
while ( V_131 -- ) {
V_132 += F_11 ( V_13 , & V_14 [ V_132 ] , V_135 ) ;
V_132 += F_19 ( V_13 , & V_14 [ V_132 ] ) ;
V_132 += F_21 ( V_13 , & V_14 [ V_132 ] , V_135 ) ;
V_132 += F_26 ( V_13 , & V_14 [ V_132 ] ) ;
}
}
return V_132 ;
}
static inline int F_44 ( unsigned V_13 , T_2 V_14 [] ,
const struct V_129 * V_130 , int V_131 )
{
int V_132 = 0 ;
while ( V_131 -- ) {
V_132 += F_25 ( V_13 , & V_14 [ V_132 ] , V_30 , V_130 -> V_4 -> V_23 ) ;
V_132 += F_12 ( V_13 , & V_14 [ V_132 ] , V_30 , V_130 -> V_4 -> V_23 ) ;
V_132 += F_21 ( V_13 , & V_14 [ V_132 ] , V_135 ) ;
V_132 += F_10 ( V_13 , & V_14 [ V_132 ] , V_130 -> V_4 -> V_23 ) ;
}
return V_132 ;
}
static inline int F_45 ( unsigned V_13 , T_2 V_14 [] ,
const struct V_129 * V_130 , int V_131 )
{
int V_132 = 0 ;
while ( V_131 -- ) {
V_132 += F_25 ( V_13 , & V_14 [ V_132 ] , V_30 , V_130 -> V_4 -> V_23 ) ;
V_132 += F_11 ( V_13 , & V_14 [ V_132 ] , V_135 ) ;
V_132 += F_22 ( V_13 , & V_14 [ V_132 ] , V_30 , V_130 -> V_4 -> V_23 ) ;
V_132 += F_10 ( V_13 , & V_14 [ V_132 ] , V_130 -> V_4 -> V_23 ) ;
}
return V_132 ;
}
static int F_46 ( unsigned V_13 , T_2 V_14 [] ,
const struct V_129 * V_130 , int V_131 )
{
int V_132 = 0 ;
switch ( V_130 -> V_4 -> V_136 ) {
case V_137 :
V_132 += F_45 ( V_13 , & V_14 [ V_132 ] , V_130 , V_131 ) ;
break;
case V_138 :
V_132 += F_44 ( V_13 , & V_14 [ V_132 ] , V_130 , V_131 ) ;
break;
case V_139 :
V_132 += F_43 ( V_13 , & V_14 [ V_132 ] , V_130 , V_131 ) ;
break;
default:
V_132 += 0x40000000 ;
break;
}
return V_132 ;
}
static inline int F_47 ( unsigned V_13 , T_2 V_14 [] ,
unsigned long * V_140 , const struct V_129 * V_130 )
{
int V_131 , V_141 , V_142 , V_143 , V_144 , V_132 ;
unsigned V_145 , V_146 , V_147 , V_148 ;
struct V_38 V_149 ;
if ( * V_140 >= 256 * 256 ) {
V_146 = 256 ;
V_145 = 256 ;
V_131 = * V_140 / V_146 / V_145 ;
} else if ( * V_140 > 256 ) {
V_146 = 256 ;
V_145 = * V_140 / V_146 ;
V_131 = 1 ;
} else {
V_146 = * V_140 ;
V_145 = 0 ;
V_131 = 1 ;
}
V_142 = F_13 ( 1 , V_14 , 0 , 0 ) ;
V_144 = F_46 ( 1 , V_14 , V_130 , 1 ) ;
V_149 . V_27 = V_135 ;
V_149 . V_40 = false ;
V_149 . V_34 = 0 ;
V_149 . V_41 = 0 ;
V_143 = F_14 ( 1 , V_14 , & V_149 ) ;
if ( V_145 ) {
V_142 *= 2 ;
V_143 *= 2 ;
}
V_141 = ( 255 - ( V_142 + V_143 ) ) / V_144 ;
V_131 = ( V_141 < V_131 ) ? V_141 : V_131 ;
V_132 = 0 ;
if ( V_145 ) {
V_132 += F_13 ( V_13 , & V_14 [ V_132 ] , 0 , V_145 ) ;
V_147 = V_132 ;
}
V_132 += F_13 ( V_13 , & V_14 [ V_132 ] , 1 , V_146 ) ;
V_148 = V_132 ;
V_132 += F_46 ( V_13 , & V_14 [ V_132 ] , V_130 , V_131 ) ;
V_149 . V_27 = V_135 ;
V_149 . V_40 = false ;
V_149 . V_34 = 1 ;
V_149 . V_41 = V_132 - V_148 ;
V_132 += F_14 ( V_13 , & V_14 [ V_132 ] , & V_149 ) ;
if ( V_145 ) {
V_149 . V_27 = V_135 ;
V_149 . V_40 = false ;
V_149 . V_34 = 0 ;
V_149 . V_41 = V_132 - V_147 ;
V_132 += F_14 ( V_13 , & V_14 [ V_132 ] , & V_149 ) ;
}
* V_140 = V_146 * V_131 ;
if ( V_145 )
* V_140 *= V_145 ;
return V_132 ;
}
static inline int F_48 ( unsigned V_13 , T_2 V_14 [] ,
const struct V_129 * V_130 )
{
struct V_150 * V_151 = & V_130 -> V_4 -> V_152 ;
T_1 V_153 = V_130 -> V_153 ;
unsigned long V_154 , V_140 = F_49 ( V_151 -> V_155 , V_153 ) ;
int V_132 = 0 ;
while ( V_140 ) {
V_154 = V_140 ;
V_132 += F_47 ( V_13 , & V_14 [ V_132 ] , & V_154 , V_130 ) ;
V_140 -= V_154 ;
}
return V_132 ;
}
static inline int F_50 ( unsigned V_13 , T_2 V_14 [] ,
const struct V_129 * V_130 )
{
struct V_150 * V_151 = & V_130 -> V_4 -> V_152 ;
int V_132 = 0 ;
V_132 += F_16 ( V_13 , & V_14 [ V_132 ] , V_51 , V_151 -> V_156 ) ;
V_132 += F_16 ( V_13 , & V_14 [ V_132 ] , V_52 , V_151 -> V_157 ) ;
V_132 += F_48 ( V_13 , & V_14 [ V_132 ] , V_130 ) ;
return V_132 ;
}
static int F_51 ( unsigned V_13 , struct V_1 * V_2 ,
unsigned V_158 , struct V_129 * V_130 )
{
struct V_119 * V_3 = & V_2 -> V_3 [ V_158 ] ;
struct V_150 * V_151 ;
T_2 * V_14 = V_3 -> V_159 ;
int V_132 = 0 ;
F_52 ( V_3 -> V_128 ) ;
V_132 += F_16 ( V_13 , & V_14 [ V_132 ] , V_160 , V_130 -> V_153 ) ;
V_151 = & V_130 -> V_4 -> V_152 ;
if ( V_151 -> V_155 % ( F_53 ( V_130 -> V_153 ) * F_54 ( V_130 -> V_153 ) ) )
return - V_161 ;
V_132 += F_50 ( V_13 , & V_14 [ V_132 ] , V_130 ) ;
V_132 += F_20 ( V_13 , & V_14 [ V_132 ] , V_2 -> V_57 ) ;
V_132 += F_9 ( V_13 , & V_14 [ V_132 ] ) ;
return V_132 ;
}
static inline T_1 F_55 ( const struct V_162 * V_163 )
{
T_1 V_153 = 0 ;
if ( V_163 -> V_164 )
V_153 |= V_165 ;
if ( V_163 -> V_166 )
V_153 |= V_167 ;
if ( V_163 -> V_168 )
V_153 |= V_169 | V_170 ;
if ( V_163 -> V_126 )
V_153 |= V_171 | V_172 ;
if ( V_163 -> V_173 )
V_153 |= V_174 | V_175 ;
V_153 |= ( ( ( V_163 -> V_176 - 1 ) & 0xf ) << V_177 ) ;
V_153 |= ( ( ( V_163 -> V_176 - 1 ) & 0xf ) << V_178 ) ;
V_153 |= ( V_163 -> V_179 << V_180 ) ;
V_153 |= ( V_163 -> V_179 << V_181 ) ;
V_153 |= ( V_163 -> V_182 << V_183 ) ;
V_153 |= ( V_163 -> V_184 << V_185 ) ;
V_153 |= ( V_163 -> V_186 << V_187 ) ;
return V_153 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_120 * V_4 )
{
struct V_188 * V_189 = V_2 -> V_5 ;
struct V_129 V_190 ;
unsigned long V_191 ;
unsigned V_122 ;
T_1 V_153 ;
int V_192 = 0 ;
if ( V_189 -> V_193 == V_194
|| V_189 -> V_195 . V_196 & ( 1 << V_2 -> V_86 ) ) {
F_41 ( V_2 -> V_5 -> V_89 . V_90 , L_29 ,
V_127 , __LINE__ ) ;
return - V_197 ;
}
if ( V_4 -> V_136 != V_139 &&
V_4 -> V_23 >= V_189 -> V_7 . V_198 ) {
F_41 ( V_2 -> V_5 -> V_89 . V_90 ,
L_30 ,
V_127 , __LINE__ , V_4 -> V_23 ) ;
return - V_161 ;
}
F_57 ( & V_189 -> V_199 , V_191 ) ;
if ( F_2 ( V_2 ) ) {
V_192 = - V_197 ;
goto V_200;
}
if ( ! F_4 ( V_2 ) )
V_4 -> V_125 . V_126 = 0 ;
else
V_4 -> V_125 . V_126 = 1 ;
V_153 = F_55 ( & V_4 -> V_125 ) ;
V_122 = V_2 -> V_3 [ 0 ] . V_4 == NULL ? 0 : 1 ;
V_190 . V_153 = V_153 ;
V_190 . V_4 = V_4 ;
V_192 = F_51 ( 1 , V_2 , V_122 , & V_190 ) ;
if ( V_192 < 0 )
goto V_200;
if ( V_192 > V_189 -> V_201 / 2 ) {
F_41 ( V_189 -> V_89 . V_90 , L_31 ,
V_127 , __LINE__ ) ;
V_192 = - V_202 ;
goto V_200;
}
V_2 -> V_123 = V_122 ;
V_2 -> V_3 [ V_122 ] . V_4 = V_4 ;
F_51 ( 0 , V_2 , V_122 , & V_190 ) ;
V_192 = 0 ;
V_200:
F_58 ( & V_189 -> V_199 , V_191 ) ;
return V_192 ;
}
static void F_59 ( struct V_120 * V_4 , enum V_203 V_204 )
{
struct V_205 * V_206 ;
unsigned long V_191 ;
if ( ! V_4 )
return;
V_206 = V_4 -> V_207 ;
if ( ! V_206 )
return;
F_57 ( & V_206 -> V_199 , V_191 ) ;
V_4 -> V_208 = V_209 ;
F_58 ( & V_206 -> V_199 , V_191 ) ;
F_60 ( & V_206 -> V_210 ) ;
}
static void F_61 ( unsigned long V_211 )
{
struct V_188 * V_189 = (struct V_188 * ) V_211 ;
unsigned long V_191 ;
int V_212 ;
F_57 ( & V_189 -> V_199 , V_191 ) ;
if ( V_189 -> V_195 . V_213 ) {
V_189 -> V_193 = V_194 ;
V_189 -> V_195 . V_214 = true ;
V_189 -> V_195 . V_213 = false ;
}
if ( V_189 -> V_195 . V_214 ) {
F_38 ( V_189 -> V_6 ) ;
V_189 -> V_195 . V_196 = ( 1 << V_189 -> V_7 . V_215 ) - 1 ;
V_189 -> V_195 . V_214 = false ;
}
for ( V_212 = 0 ; V_212 < V_189 -> V_7 . V_215 ; V_212 ++ ) {
if ( V_189 -> V_195 . V_196 & ( 1 << V_212 ) ) {
struct V_1 * V_2 = & V_189 -> V_216 [ V_212 ] ;
void T_4 * V_79 = V_189 -> V_80 ;
enum V_203 V_204 ;
F_38 ( V_2 ) ;
if ( F_30 ( V_79 + V_217 ) & ( 1 << V_2 -> V_86 ) )
V_204 = V_218 ;
else
V_204 = V_219 ;
F_58 ( & V_189 -> V_199 , V_191 ) ;
F_59 ( V_2 -> V_3 [ 1 - V_2 -> V_123 ] . V_4 , V_204 ) ;
F_59 ( V_2 -> V_3 [ V_2 -> V_123 ] . V_4 , V_204 ) ;
F_57 ( & V_189 -> V_199 , V_191 ) ;
V_2 -> V_3 [ 0 ] . V_4 = NULL ;
V_2 -> V_3 [ 1 ] . V_4 = NULL ;
V_2 -> V_124 = - 1 ;
V_189 -> V_195 . V_196 &= ~ ( 1 << V_212 ) ;
}
}
F_58 ( & V_189 -> V_199 , V_191 ) ;
return;
}
static int F_62 ( struct V_188 * V_189 )
{
struct V_120 * V_220 , * V_221 ;
unsigned long V_191 ;
void T_4 * V_79 ;
T_1 V_17 ;
int V_86 , V_57 , V_192 = 0 ;
V_79 = V_189 -> V_80 ;
F_57 ( & V_189 -> V_199 , V_191 ) ;
V_17 = F_30 ( V_79 + V_222 ) & 0x1 ;
if ( V_17 )
V_189 -> V_195 . V_214 = true ;
else
V_189 -> V_195 . V_214 = false ;
V_17 = F_30 ( V_79 + V_217 ) & ( ( 1 << V_189 -> V_7 . V_215 ) - 1 ) ;
V_189 -> V_195 . V_196 |= V_17 ;
if ( V_17 ) {
int V_212 = 0 ;
while ( V_212 < V_189 -> V_7 . V_215 ) {
if ( V_17 & ( 1 << V_212 ) ) {
F_41 ( V_189 -> V_89 . V_90 ,
L_32 ,
V_212 , F_30 ( V_79 + F_37 ( V_212 ) ) ,
F_30 ( V_79 + F_63 ( V_212 ) ) ) ;
F_38 ( & V_189 -> V_216 [ V_212 ] ) ;
}
V_212 ++ ;
}
}
V_17 = F_30 ( V_79 + V_223 ) ;
if ( V_189 -> V_7 . V_224 < 32
&& V_17 & ~ ( ( 1 << V_189 -> V_7 . V_224 ) - 1 ) ) {
V_189 -> V_195 . V_213 = true ;
F_35 ( V_189 -> V_89 . V_90 , L_33 , V_127 ,
__LINE__ ) ;
V_192 = 1 ;
goto V_225;
}
for ( V_57 = 0 ; V_57 < V_189 -> V_7 . V_224 ; V_57 ++ ) {
if ( V_17 & ( 1 << V_57 ) ) {
struct V_1 * V_2 ;
T_1 V_226 = F_30 ( V_79 + V_118 ) ;
int V_227 ;
if ( V_226 & ( 1 << V_57 ) )
F_33 ( 1 << V_57 , V_79 + V_228 ) ;
V_192 = 1 ;
V_86 = V_189 -> V_229 [ V_57 ] ;
V_2 = & V_189 -> V_216 [ V_86 ] ;
V_227 = V_2 -> V_124 ;
if ( V_227 == - 1 )
continue;
V_220 = V_2 -> V_3 [ V_227 ] . V_4 ;
V_2 -> V_3 [ V_227 ] . V_4 = NULL ;
V_2 -> V_124 = - 1 ;
F_42 ( V_2 ) ;
F_64 ( & V_220 -> V_230 , & V_189 -> V_231 ) ;
}
}
F_65 (descdone, tmp, &pl330->req_done, rqd) {
F_66 ( & V_220 -> V_230 ) ;
F_58 ( & V_189 -> V_199 , V_191 ) ;
F_59 ( V_220 , V_232 ) ;
F_57 ( & V_189 -> V_199 , V_191 ) ;
}
V_225:
F_58 ( & V_189 -> V_199 , V_191 ) ;
if ( V_189 -> V_195 . V_213
|| V_189 -> V_195 . V_214
|| V_189 -> V_195 . V_196 ) {
V_192 = 1 ;
F_60 ( & V_189 -> V_233 ) ;
}
return V_192 ;
}
static inline int F_67 ( struct V_1 * V_2 )
{
struct V_188 * V_189 = V_2 -> V_5 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_189 -> V_7 . V_224 ; V_57 ++ )
if ( V_189 -> V_229 [ V_57 ] == - 1 ) {
V_189 -> V_229 [ V_57 ] = V_2 -> V_86 ;
return V_57 ;
}
return - 1 ;
}
static bool F_68 ( const struct V_188 * V_189 , int V_212 )
{
return V_189 -> V_7 . V_234 & ( 1 << V_212 ) ;
}
static struct V_1 * F_69 ( struct V_188 * V_189 )
{
struct V_1 * V_2 = NULL ;
unsigned long V_191 ;
int V_235 , V_212 ;
if ( V_189 -> V_193 == V_194 )
return NULL ;
V_235 = V_189 -> V_7 . V_215 ;
F_57 ( & V_189 -> V_199 , V_191 ) ;
for ( V_212 = 0 ; V_212 < V_235 ; V_212 ++ ) {
V_2 = & V_189 -> V_216 [ V_212 ] ;
if ( ( V_2 -> free ) && ( ! F_4 ( V_2 ) ||
F_68 ( V_189 , V_212 ) ) ) {
V_2 -> V_57 = F_67 ( V_2 ) ;
if ( V_2 -> V_57 >= 0 ) {
V_2 -> free = false ;
V_2 -> V_123 = 1 ;
V_2 -> V_3 [ 0 ] . V_4 = NULL ;
V_2 -> V_3 [ 1 ] . V_4 = NULL ;
V_2 -> V_124 = - 1 ;
break;
}
}
V_2 = NULL ;
}
F_58 ( & V_189 -> V_199 , V_191 ) ;
return V_2 ;
}
static inline void F_70 ( struct V_1 * V_2 , int V_57 )
{
struct V_188 * V_189 = V_2 -> V_5 ;
if ( V_57 >= 0 && V_57 < V_189 -> V_7 . V_224
&& V_189 -> V_229 [ V_57 ] == V_2 -> V_86 )
V_189 -> V_229 [ V_57 ] = - 1 ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_188 * V_189 ;
unsigned long V_191 ;
if ( ! V_2 || V_2 -> free )
return;
F_38 ( V_2 ) ;
F_59 ( V_2 -> V_3 [ 1 - V_2 -> V_123 ] . V_4 , V_219 ) ;
F_59 ( V_2 -> V_3 [ V_2 -> V_123 ] . V_4 , V_219 ) ;
V_189 = V_2 -> V_5 ;
F_57 ( & V_189 -> V_199 , V_191 ) ;
F_70 ( V_2 , V_2 -> V_57 ) ;
V_2 -> free = true ;
F_58 ( & V_189 -> V_199 , V_191 ) ;
}
static void F_72 ( struct V_188 * V_189 )
{
void T_4 * V_79 = V_189 -> V_80 ;
T_1 V_17 ;
V_17 = F_30 ( V_79 + V_236 ) >> V_237 ;
V_17 &= V_238 ;
V_189 -> V_7 . V_239 = 8 * ( 1 << V_17 ) ;
V_17 = F_30 ( V_79 + V_236 ) >> V_240 ;
V_17 &= V_241 ;
V_189 -> V_7 . V_242 = V_17 + 1 ;
V_17 = F_30 ( V_79 + V_243 ) >> V_244 ;
V_17 &= V_245 ;
V_17 += 1 ;
V_189 -> V_7 . V_215 = V_17 ;
V_17 = F_30 ( V_79 + V_243 ) ;
if ( V_17 & V_246 ) {
V_17 = ( V_17 >> V_247 ) & V_248 ;
V_17 += 1 ;
V_189 -> V_7 . V_198 = V_17 ;
V_189 -> V_7 . V_249 = F_30 ( V_79 + V_250 ) ;
} else {
V_189 -> V_7 . V_198 = 0 ;
}
V_17 = F_30 ( V_79 + V_243 ) ;
if ( V_17 & V_251 )
V_189 -> V_7 . V_8 |= V_9 ;
else
V_189 -> V_7 . V_8 &= ~ V_9 ;
V_17 = F_30 ( V_79 + V_243 ) >> V_252 ;
V_17 &= V_253 ;
V_17 += 1 ;
V_189 -> V_7 . V_224 = V_17 ;
V_189 -> V_7 . V_234 = F_30 ( V_79 + V_254 ) ;
}
static inline void F_73 ( struct V_1 * V_2 )
{
struct V_188 * V_189 = V_2 -> V_5 ;
V_2 -> V_3 [ 0 ] . V_159 = V_189 -> V_255
+ ( V_2 -> V_86 * V_189 -> V_201 ) ;
V_2 -> V_3 [ 0 ] . V_128 = V_189 -> V_256
+ ( V_2 -> V_86 * V_189 -> V_201 ) ;
V_2 -> V_3 [ 0 ] . V_4 = NULL ;
V_2 -> V_3 [ 1 ] . V_159 = V_2 -> V_3 [ 0 ] . V_159
+ V_189 -> V_201 / 2 ;
V_2 -> V_3 [ 1 ] . V_128 = V_2 -> V_3 [ 0 ] . V_128
+ V_189 -> V_201 / 2 ;
V_2 -> V_3 [ 1 ] . V_4 = NULL ;
V_2 -> V_124 = - 1 ;
}
static int F_74 ( struct V_188 * V_189 )
{
int V_235 = V_189 -> V_7 . V_215 ;
struct V_1 * V_2 ;
int V_212 ;
V_189 -> V_216 = F_75 ( ( 1 + V_235 ) * sizeof( * V_2 ) ,
V_257 ) ;
if ( ! V_189 -> V_216 )
return - V_202 ;
for ( V_212 = 0 ; V_212 < V_235 ; V_212 ++ ) {
V_2 = & V_189 -> V_216 [ V_212 ] ;
V_2 -> V_86 = V_212 ;
V_2 -> V_5 = V_189 ;
F_73 ( V_2 ) ;
V_2 -> free = true ;
}
V_2 = & V_189 -> V_216 [ V_235 ] ;
V_2 -> V_86 = V_235 ;
V_2 -> V_5 = V_189 ;
V_2 -> free = false ;
V_189 -> V_6 = V_2 ;
return 0 ;
}
static int F_76 ( struct V_188 * V_189 )
{
int V_235 = V_189 -> V_7 . V_215 ;
int V_192 ;
V_189 -> V_255 = F_77 ( V_189 -> V_89 . V_90 ,
V_235 * V_189 -> V_201 ,
& V_189 -> V_256 , V_257 ) ;
if ( ! V_189 -> V_255 ) {
F_35 ( V_189 -> V_89 . V_90 , L_34 ,
V_127 , __LINE__ ) ;
return - V_202 ;
}
V_192 = F_74 ( V_189 ) ;
if ( V_192 ) {
F_35 ( V_189 -> V_89 . V_90 , L_35 ,
V_127 , __LINE__ ) ;
F_78 ( V_189 -> V_89 . V_90 ,
V_235 * V_189 -> V_201 ,
V_189 -> V_255 , V_189 -> V_256 ) ;
return V_192 ;
}
return 0 ;
}
static int F_79 ( struct V_188 * V_189 )
{
void T_4 * V_79 ;
int V_212 , V_192 ;
V_79 = V_189 -> V_80 ;
if ( ( V_189 -> V_7 . V_10 & 0xfffff ) != V_258 ) {
F_35 ( V_189 -> V_89 . V_90 , L_36 ,
V_189 -> V_7 . V_10 ) ;
return - V_161 ;
}
F_72 ( V_189 ) ;
if ( V_189 -> V_7 . V_224 == 0 ) {
F_35 ( V_189 -> V_89 . V_90 , L_37 ,
V_127 , __LINE__ ) ;
return - V_161 ;
}
F_80 ( & V_189 -> V_199 ) ;
F_81 ( & V_189 -> V_231 ) ;
if ( ! V_189 -> V_201 )
V_189 -> V_201 = V_259 * 2 ;
for ( V_212 = 0 ; V_212 < V_189 -> V_7 . V_224 ; V_212 ++ )
V_189 -> V_229 [ V_212 ] = - 1 ;
V_192 = F_76 ( V_189 ) ;
if ( V_192 ) {
F_35 ( V_189 -> V_89 . V_90 , L_38 ) ;
return V_192 ;
}
F_82 ( & V_189 -> V_233 , F_61 , ( unsigned long ) V_189 ) ;
V_189 -> V_193 = V_260 ;
return 0 ;
}
static int F_83 ( struct V_188 * V_189 )
{
struct V_1 * V_2 ;
int V_212 ;
for ( V_212 = 0 ; V_212 < V_189 -> V_7 . V_215 ; V_212 ++ ) {
V_2 = & V_189 -> V_216 [ V_212 ] ;
F_71 ( V_2 ) ;
}
F_84 ( V_189 -> V_216 ) ;
return 0 ;
}
static void F_85 ( struct V_188 * V_189 )
{
V_189 -> V_193 = V_261 ;
F_86 ( & V_189 -> V_233 ) ;
F_83 ( V_189 ) ;
F_78 ( V_189 -> V_89 . V_90 ,
V_189 -> V_7 . V_215 * V_189 -> V_201 , V_189 -> V_255 ,
V_189 -> V_256 ) ;
}
static inline struct V_205 *
F_87 ( struct V_262 * V_263 )
{
if ( ! V_263 )
return NULL ;
return F_88 ( V_263 , struct V_205 , V_74 ) ;
}
static inline struct V_120 *
F_89 ( struct V_264 * V_265 )
{
return F_88 ( V_265 , struct V_120 , V_266 ) ;
}
static inline void F_90 ( struct V_205 * V_206 )
{
struct V_120 * V_4 ;
int V_192 ;
F_91 (desc, &pch->work_list, node) {
if ( V_4 -> V_208 == V_267 )
continue;
V_192 = F_56 ( V_206 -> V_268 , V_4 ) ;
if ( ! V_192 ) {
V_4 -> V_208 = V_267 ;
} else if ( V_192 == - V_197 ) {
break;
} else {
V_4 -> V_208 = V_209 ;
F_35 ( V_206 -> V_5 -> V_89 . V_90 , L_39 ,
V_127 , __LINE__ , V_4 -> V_266 . V_269 ) ;
F_60 ( & V_206 -> V_210 ) ;
}
}
}
static void F_92 ( unsigned long V_211 )
{
struct V_205 * V_206 = (struct V_205 * ) V_211 ;
struct V_120 * V_4 , * V_270 ;
unsigned long V_191 ;
bool V_271 = false ;
F_57 ( & V_206 -> V_199 , V_191 ) ;
F_65 (desc, _dt, &pch->work_list, node)
if ( V_4 -> V_208 == V_209 ) {
if ( ! V_206 -> V_272 )
F_93 ( & V_4 -> V_266 ) ;
F_94 ( & V_4 -> V_273 , & V_206 -> V_274 ) ;
}
F_90 ( V_206 ) ;
if ( F_95 ( & V_206 -> V_275 ) ) {
F_96 ( & V_206 -> V_268 -> V_5 -> V_199 ) ;
F_38 ( V_206 -> V_268 ) ;
F_97 ( & V_206 -> V_268 -> V_5 -> V_199 ) ;
V_271 = true ;
} else {
F_96 ( & V_206 -> V_268 -> V_5 -> V_199 ) ;
F_42 ( V_206 -> V_268 ) ;
F_97 ( & V_206 -> V_268 -> V_5 -> V_199 ) ;
}
while ( ! F_95 ( & V_206 -> V_274 ) ) {
T_5 V_276 ;
void * V_277 ;
V_4 = F_98 ( & V_206 -> V_274 ,
struct V_120 , V_273 ) ;
V_276 = V_4 -> V_266 . V_276 ;
V_277 = V_4 -> V_266 . V_277 ;
if ( V_206 -> V_272 ) {
V_4 -> V_208 = V_278 ;
F_94 ( & V_4 -> V_273 , & V_206 -> V_275 ) ;
if ( V_271 ) {
F_96 ( & V_206 -> V_268 -> V_5 -> V_199 ) ;
F_42 ( V_206 -> V_268 ) ;
F_97 ( & V_206 -> V_268 -> V_5 -> V_199 ) ;
V_271 = false ;
}
} else {
V_4 -> V_208 = FREE ;
F_94 ( & V_4 -> V_273 , & V_206 -> V_5 -> V_279 ) ;
}
F_99 ( & V_4 -> V_266 ) ;
if ( V_276 ) {
F_58 ( & V_206 -> V_199 , V_191 ) ;
V_276 ( V_277 ) ;
F_57 ( & V_206 -> V_199 , V_191 ) ;
}
}
F_58 ( & V_206 -> V_199 , V_191 ) ;
if ( V_271 ) {
F_100 ( V_206 -> V_5 -> V_89 . V_90 ) ;
F_101 ( V_206 -> V_5 -> V_89 . V_90 ) ;
}
}
bool F_102 ( struct V_262 * V_74 , void * V_280 )
{
T_2 * V_281 ;
if ( V_74 -> V_282 -> V_90 -> V_283 != & V_284 . V_285 )
return false ;
V_281 = V_74 -> V_286 ;
return * V_281 == ( unsigned long ) V_280 ;
}
static struct V_262 * F_103 ( struct V_287 * V_288 ,
struct V_289 * V_290 )
{
int V_291 = V_288 -> V_292 ;
struct V_188 * V_189 = V_290 -> V_293 ;
unsigned int V_294 ;
if ( ! V_189 )
return NULL ;
if ( V_291 != 1 )
return NULL ;
V_294 = V_288 -> args [ 0 ] ;
if ( V_294 >= V_189 -> V_295 )
return NULL ;
return F_104 ( & V_189 -> V_296 [ V_294 ] . V_74 ) ;
}
static int F_105 ( struct V_262 * V_74 )
{
struct V_205 * V_206 = F_87 ( V_74 ) ;
struct V_188 * V_189 = V_206 -> V_5 ;
unsigned long V_191 ;
F_57 ( & V_206 -> V_199 , V_191 ) ;
F_106 ( V_74 ) ;
V_206 -> V_272 = false ;
V_206 -> V_268 = F_69 ( V_189 ) ;
if ( ! V_206 -> V_268 ) {
F_58 ( & V_206 -> V_199 , V_191 ) ;
return - V_202 ;
}
F_82 ( & V_206 -> V_210 , F_92 , ( unsigned long ) V_206 ) ;
F_58 ( & V_206 -> V_199 , V_191 ) ;
return 1 ;
}
static int V_133 ( struct V_262 * V_74 ,
struct V_297 * V_298 )
{
struct V_205 * V_206 = F_87 ( V_74 ) ;
if ( V_298 -> V_299 == V_137 ) {
if ( V_298 -> V_157 )
V_206 -> V_300 = V_298 -> V_157 ;
if ( V_298 -> V_301 )
V_206 -> V_302 = F_107 ( V_298 -> V_301 ) ;
if ( V_298 -> V_303 )
V_206 -> V_304 = V_298 -> V_303 ;
} else if ( V_298 -> V_299 == V_138 ) {
if ( V_298 -> V_156 )
V_206 -> V_300 = V_298 -> V_156 ;
if ( V_298 -> V_305 )
V_206 -> V_302 = F_107 ( V_298 -> V_305 ) ;
if ( V_298 -> V_306 )
V_206 -> V_304 = V_298 -> V_306 ;
}
return 0 ;
}
static int F_108 ( struct V_262 * V_74 )
{
struct V_205 * V_206 = F_87 ( V_74 ) ;
struct V_120 * V_4 ;
unsigned long V_191 ;
struct V_188 * V_189 = V_206 -> V_5 ;
F_109 ( V_307 ) ;
F_110 ( V_189 -> V_89 . V_90 ) ;
F_57 ( & V_206 -> V_199 , V_191 ) ;
F_96 ( & V_189 -> V_199 ) ;
F_38 ( V_206 -> V_268 ) ;
F_97 ( & V_189 -> V_199 ) ;
V_206 -> V_268 -> V_3 [ 0 ] . V_4 = NULL ;
V_206 -> V_268 -> V_3 [ 1 ] . V_4 = NULL ;
V_206 -> V_268 -> V_124 = - 1 ;
F_91 (desc, &pch->submitted_list, node) {
V_4 -> V_208 = FREE ;
F_93 ( & V_4 -> V_266 ) ;
}
F_91 (desc, &pch->work_list , node) {
V_4 -> V_208 = FREE ;
F_93 ( & V_4 -> V_266 ) ;
}
F_111 ( & V_206 -> V_308 , & V_189 -> V_279 ) ;
F_111 ( & V_206 -> V_275 , & V_189 -> V_279 ) ;
F_111 ( & V_206 -> V_274 , & V_189 -> V_279 ) ;
F_58 ( & V_206 -> V_199 , V_191 ) ;
F_100 ( V_189 -> V_89 . V_90 ) ;
F_101 ( V_189 -> V_89 . V_90 ) ;
return 0 ;
}
static int F_112 ( struct V_262 * V_74 )
{
struct V_205 * V_206 = F_87 ( V_74 ) ;
struct V_188 * V_189 = V_206 -> V_5 ;
unsigned long V_191 ;
F_110 ( V_189 -> V_89 . V_90 ) ;
F_57 ( & V_206 -> V_199 , V_191 ) ;
F_96 ( & V_189 -> V_199 ) ;
F_38 ( V_206 -> V_268 ) ;
F_97 ( & V_189 -> V_199 ) ;
F_58 ( & V_206 -> V_199 , V_191 ) ;
F_100 ( V_189 -> V_89 . V_90 ) ;
F_101 ( V_189 -> V_89 . V_90 ) ;
return 0 ;
}
static void F_113 ( struct V_262 * V_74 )
{
struct V_205 * V_206 = F_87 ( V_74 ) ;
unsigned long V_191 ;
F_86 ( & V_206 -> V_210 ) ;
F_110 ( V_206 -> V_5 -> V_89 . V_90 ) ;
F_57 ( & V_206 -> V_199 , V_191 ) ;
F_71 ( V_206 -> V_268 ) ;
V_206 -> V_268 = NULL ;
if ( V_206 -> V_272 )
F_111 ( & V_206 -> V_275 , & V_206 -> V_5 -> V_279 ) ;
F_58 ( & V_206 -> V_199 , V_191 ) ;
F_100 ( V_206 -> V_5 -> V_89 . V_90 ) ;
F_101 ( V_206 -> V_5 -> V_89 . V_90 ) ;
}
static int F_114 ( struct V_205 * V_206 ,
struct V_120 * V_4 )
{
struct V_1 * V_2 = V_206 -> V_268 ;
struct V_188 * V_189 = V_206 -> V_5 ;
void T_4 * V_79 = V_2 -> V_5 -> V_80 ;
T_1 V_17 , V_75 ;
F_110 ( V_189 -> V_89 . V_90 ) ;
V_17 = V_75 = 0 ;
if ( V_4 -> V_125 . V_164 ) {
V_17 = F_30 ( V_79 + F_115 ( V_2 -> V_86 ) ) ;
V_75 = V_4 -> V_152 . V_156 ;
} else {
V_17 = F_30 ( V_79 + F_116 ( V_2 -> V_86 ) ) ;
V_75 = V_4 -> V_152 . V_157 ;
}
F_100 ( V_206 -> V_5 -> V_89 . V_90 ) ;
F_101 ( V_189 -> V_89 . V_90 ) ;
return V_17 - V_75 ;
}
static enum V_309
F_117 ( struct V_262 * V_74 , T_6 V_269 ,
struct V_310 * V_311 )
{
enum V_309 V_192 ;
unsigned long V_191 ;
struct V_120 * V_4 , * V_312 = NULL ;
struct V_205 * V_206 = F_87 ( V_74 ) ;
unsigned int V_313 , V_314 = 0 ;
V_192 = F_118 ( V_74 , V_269 , V_311 ) ;
if ( ! V_311 )
return V_192 ;
if ( V_192 == V_315 )
goto V_316;
F_57 ( & V_206 -> V_199 , V_191 ) ;
if ( V_206 -> V_268 -> V_124 != - 1 )
V_312 = V_206 -> V_268 -> V_3 [ V_206 -> V_268 -> V_124 ] . V_4 ;
F_91 (desc, &pch->work_list, node) {
if ( V_4 -> V_208 == V_209 )
V_313 = V_4 -> V_317 ;
else if ( V_312 && V_4 == V_312 )
V_313 =
F_114 ( V_206 , V_4 ) ;
else
V_313 = 0 ;
V_314 += V_4 -> V_317 - V_313 ;
if ( V_4 -> V_266 . V_269 == V_269 ) {
switch ( V_4 -> V_208 ) {
case V_209 :
V_192 = V_315 ;
break;
case V_278 :
case V_267 :
V_192 = V_318 ;
break;
default:
F_119 ( 1 ) ;
}
break;
}
if ( V_4 -> V_319 )
V_314 = 0 ;
}
F_58 ( & V_206 -> V_199 , V_191 ) ;
V_316:
F_120 ( V_311 , V_314 ) ;
return V_192 ;
}
static void F_121 ( struct V_262 * V_74 )
{
struct V_205 * V_206 = F_87 ( V_74 ) ;
unsigned long V_191 ;
F_57 ( & V_206 -> V_199 , V_191 ) ;
if ( F_95 ( & V_206 -> V_275 ) ) {
F_119 ( F_95 ( & V_206 -> V_308 ) ) ;
F_110 ( V_206 -> V_5 -> V_89 . V_90 ) ;
}
F_111 ( & V_206 -> V_308 , & V_206 -> V_275 ) ;
F_58 ( & V_206 -> V_199 , V_191 ) ;
F_92 ( ( unsigned long ) V_206 ) ;
}
static T_6 F_122 ( struct V_264 * V_265 )
{
struct V_120 * V_4 , * V_319 = F_89 ( V_265 ) ;
struct V_205 * V_206 = F_87 ( V_265 -> V_74 ) ;
T_6 V_269 ;
unsigned long V_191 ;
F_57 ( & V_206 -> V_199 , V_191 ) ;
while ( ! F_95 ( & V_319 -> V_273 ) ) {
V_4 = F_123 ( V_319 -> V_273 . V_320 , struct V_120 , V_273 ) ;
if ( V_206 -> V_272 ) {
V_4 -> V_266 . V_276 = V_319 -> V_266 . V_276 ;
V_4 -> V_266 . V_277 = V_319 -> V_266 . V_277 ;
}
V_319 -> V_319 = false ;
F_124 ( & V_4 -> V_266 ) ;
F_94 ( & V_4 -> V_273 , & V_206 -> V_308 ) ;
}
V_319 -> V_319 = true ;
V_269 = F_124 ( & V_319 -> V_266 ) ;
F_64 ( & V_319 -> V_273 , & V_206 -> V_308 ) ;
F_58 ( & V_206 -> V_199 , V_191 ) ;
return V_269 ;
}
static inline void F_125 ( struct V_120 * V_4 )
{
V_4 -> V_125 . V_186 = V_321 ;
V_4 -> V_125 . V_182 = V_322 ;
V_4 -> V_125 . V_184 = V_322 ;
V_4 -> V_266 . V_323 = F_122 ;
F_81 ( & V_4 -> V_273 ) ;
}
static int F_126 ( struct V_188 * V_189 , T_7 V_324 , int V_291 )
{
struct V_120 * V_4 ;
unsigned long V_191 ;
int V_212 ;
V_4 = F_127 ( V_291 , sizeof( * V_4 ) , V_324 ) ;
if ( ! V_4 )
return 0 ;
F_57 ( & V_189 -> V_325 , V_191 ) ;
for ( V_212 = 0 ; V_212 < V_291 ; V_212 ++ ) {
F_125 ( & V_4 [ V_212 ] ) ;
F_64 ( & V_4 [ V_212 ] . V_273 , & V_189 -> V_279 ) ;
}
F_58 ( & V_189 -> V_325 , V_191 ) ;
return V_291 ;
}
static struct V_120 * F_128 ( struct V_188 * V_189 )
{
struct V_120 * V_4 = NULL ;
unsigned long V_191 ;
F_57 ( & V_189 -> V_325 , V_191 ) ;
if ( ! F_95 ( & V_189 -> V_279 ) ) {
V_4 = F_123 ( V_189 -> V_279 . V_320 ,
struct V_120 , V_273 ) ;
F_129 ( & V_4 -> V_273 ) ;
V_4 -> V_208 = V_278 ;
V_4 -> V_266 . V_276 = NULL ;
}
F_58 ( & V_189 -> V_325 , V_191 ) ;
return V_4 ;
}
static struct V_120 * F_130 ( struct V_205 * V_206 )
{
struct V_188 * V_189 = V_206 -> V_5 ;
T_2 * V_281 = V_206 -> V_74 . V_286 ;
struct V_120 * V_4 ;
V_4 = F_128 ( V_189 ) ;
if ( ! V_4 ) {
if ( ! F_126 ( V_189 , V_326 , 1 ) )
return NULL ;
V_4 = F_128 ( V_189 ) ;
if ( ! V_4 ) {
F_35 ( V_206 -> V_5 -> V_89 . V_90 ,
L_40 , V_127 , __LINE__ ) ;
return NULL ;
}
}
V_4 -> V_207 = V_206 ;
V_4 -> V_266 . V_269 = 0 ;
F_131 ( & V_4 -> V_266 ) ;
V_4 -> V_23 = V_281 ? V_206 -> V_74 . V_294 : 0 ;
V_4 -> V_125 . V_7 = & V_206 -> V_5 -> V_7 ;
F_132 ( & V_4 -> V_266 , & V_206 -> V_74 ) ;
return V_4 ;
}
static inline void F_133 ( struct V_150 * V_152 ,
T_8 V_47 , T_8 V_327 , T_9 V_328 )
{
V_152 -> V_155 = V_328 ;
V_152 -> V_157 = V_47 ;
V_152 -> V_156 = V_327 ;
}
static struct V_120 *
F_134 ( struct V_205 * V_206 , T_8 V_47 ,
T_8 V_327 , T_9 V_328 )
{
struct V_120 * V_4 = F_130 ( V_206 ) ;
if ( ! V_4 ) {
F_35 ( V_206 -> V_5 -> V_89 . V_90 , L_41 ,
V_127 , __LINE__ ) ;
return NULL ;
}
F_133 ( & V_4 -> V_152 , V_47 , V_327 , V_328 ) ;
return V_4 ;
}
static inline int F_135 ( struct V_120 * V_4 , T_9 V_328 )
{
struct V_205 * V_206 = V_4 -> V_207 ;
struct V_188 * V_189 = V_206 -> V_5 ;
int V_304 ;
V_304 = V_189 -> V_7 . V_239 / 8 ;
V_304 *= V_189 -> V_7 . V_242 / V_189 -> V_7 . V_215 ;
V_304 >>= V_4 -> V_125 . V_179 ;
if ( V_304 > 16 )
V_304 = 16 ;
while ( V_304 > 1 ) {
if ( ! ( V_328 % ( V_304 << V_4 -> V_125 . V_179 ) ) )
break;
V_304 -- ;
}
return V_304 ;
}
static struct V_264 * F_136 (
struct V_262 * V_74 , T_8 V_329 , T_9 V_328 ,
T_9 V_330 , enum V_331 V_299 ,
unsigned long V_191 )
{
struct V_120 * V_4 = NULL , * V_332 = NULL ;
struct V_205 * V_206 = F_87 ( V_74 ) ;
struct V_188 * V_189 = V_206 -> V_5 ;
unsigned int V_212 ;
T_8 V_47 ;
T_8 V_327 ;
if ( V_328 % V_330 != 0 )
return NULL ;
if ( ! F_137 ( V_299 ) ) {
F_35 ( V_206 -> V_5 -> V_89 . V_90 , L_42 ,
V_127 , __LINE__ ) ;
return NULL ;
}
for ( V_212 = 0 ; V_212 < V_328 / V_330 ; V_212 ++ ) {
V_4 = F_130 ( V_206 ) ;
if ( ! V_4 ) {
F_35 ( V_206 -> V_5 -> V_89 . V_90 , L_41 ,
V_127 , __LINE__ ) ;
if ( ! V_332 )
return NULL ;
F_57 ( & V_189 -> V_325 , V_191 ) ;
while ( ! F_95 ( & V_332 -> V_273 ) ) {
V_4 = F_123 ( V_332 -> V_273 . V_320 ,
struct V_120 , V_273 ) ;
F_94 ( & V_4 -> V_273 , & V_189 -> V_279 ) ;
}
F_94 ( & V_332 -> V_273 , & V_189 -> V_279 ) ;
F_58 ( & V_189 -> V_325 , V_191 ) ;
return NULL ;
}
switch ( V_299 ) {
case V_137 :
V_4 -> V_125 . V_164 = 1 ;
V_4 -> V_125 . V_166 = 0 ;
V_327 = V_329 ;
V_47 = V_206 -> V_300 ;
break;
case V_138 :
V_4 -> V_125 . V_164 = 0 ;
V_4 -> V_125 . V_166 = 1 ;
V_327 = V_206 -> V_300 ;
V_47 = V_329 ;
break;
default:
break;
}
V_4 -> V_136 = V_299 ;
V_4 -> V_125 . V_179 = V_206 -> V_302 ;
V_4 -> V_125 . V_176 = 1 ;
V_4 -> V_317 = V_330 ;
F_133 ( & V_4 -> V_152 , V_47 , V_327 , V_330 ) ;
if ( ! V_332 )
V_332 = V_4 ;
else
F_64 ( & V_4 -> V_273 , & V_332 -> V_273 ) ;
V_329 += V_330 ;
}
if ( ! V_4 )
return NULL ;
V_206 -> V_272 = true ;
V_4 -> V_266 . V_191 = V_191 ;
return & V_4 -> V_266 ;
}
static struct V_264 *
F_138 ( struct V_262 * V_74 , T_8 V_47 ,
T_8 V_327 , T_9 V_328 , unsigned long V_191 )
{
struct V_120 * V_4 ;
struct V_205 * V_206 = F_87 ( V_74 ) ;
struct V_188 * V_189 = V_206 -> V_5 ;
int V_333 ;
if ( F_139 ( ! V_206 || ! V_328 ) )
return NULL ;
V_4 = F_134 ( V_206 , V_47 , V_327 , V_328 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_125 . V_164 = 1 ;
V_4 -> V_125 . V_166 = 1 ;
V_4 -> V_136 = V_139 ;
V_333 = V_189 -> V_7 . V_239 / 8 ;
while ( ( V_327 | V_47 | V_328 ) & ( V_333 - 1 ) )
V_333 /= 2 ;
V_4 -> V_125 . V_179 = 0 ;
while ( V_333 != ( 1 << V_4 -> V_125 . V_179 ) )
V_4 -> V_125 . V_179 ++ ;
if ( V_4 -> V_125 . V_179 * 8 < V_189 -> V_7 . V_239 )
V_4 -> V_125 . V_176 = 1 ;
V_4 -> V_125 . V_176 = F_135 ( V_4 , V_328 ) ;
V_4 -> V_266 . V_191 = V_191 ;
return & V_4 -> V_266 ;
}
static void F_140 ( struct V_188 * V_189 ,
struct V_120 * V_332 )
{
unsigned long V_191 ;
struct V_120 * V_4 ;
if ( ! V_332 )
return;
F_57 ( & V_189 -> V_325 , V_191 ) ;
while ( ! F_95 ( & V_332 -> V_273 ) ) {
V_4 = F_123 ( V_332 -> V_273 . V_320 ,
struct V_120 , V_273 ) ;
F_94 ( & V_4 -> V_273 , & V_189 -> V_279 ) ;
}
F_94 ( & V_332 -> V_273 , & V_189 -> V_279 ) ;
F_58 ( & V_189 -> V_325 , V_191 ) ;
}
static struct V_264 *
F_141 ( struct V_262 * V_74 , struct V_334 * V_335 ,
unsigned int V_336 , enum V_331 V_299 ,
unsigned long V_324 , void * V_337 )
{
struct V_120 * V_332 , * V_4 = NULL ;
struct V_205 * V_206 = F_87 ( V_74 ) ;
struct V_334 * V_338 ;
int V_212 ;
T_8 V_75 ;
if ( F_139 ( ! V_206 || ! V_335 || ! V_336 ) )
return NULL ;
V_75 = V_206 -> V_300 ;
V_332 = NULL ;
F_142 (sgl, sg, sg_len, i) {
V_4 = F_130 ( V_206 ) ;
if ( ! V_4 ) {
struct V_188 * V_189 = V_206 -> V_5 ;
F_35 ( V_206 -> V_5 -> V_89 . V_90 ,
L_41 ,
V_127 , __LINE__ ) ;
F_140 ( V_189 , V_332 ) ;
return NULL ;
}
if ( ! V_332 )
V_332 = V_4 ;
else
F_64 ( & V_4 -> V_273 , & V_332 -> V_273 ) ;
if ( V_299 == V_137 ) {
V_4 -> V_125 . V_164 = 1 ;
V_4 -> V_125 . V_166 = 0 ;
F_133 ( & V_4 -> V_152 ,
V_75 , F_143 ( V_338 ) , F_144 ( V_338 ) ) ;
} else {
V_4 -> V_125 . V_164 = 0 ;
V_4 -> V_125 . V_166 = 1 ;
F_133 ( & V_4 -> V_152 ,
F_143 ( V_338 ) , V_75 , F_144 ( V_338 ) ) ;
}
V_4 -> V_125 . V_179 = V_206 -> V_302 ;
V_4 -> V_125 . V_176 = 1 ;
V_4 -> V_136 = V_299 ;
V_4 -> V_317 = F_144 ( V_338 ) ;
}
V_4 -> V_266 . V_191 = V_324 ;
return & V_4 -> V_266 ;
}
static T_10 F_145 ( int V_339 , void * V_211 )
{
if ( F_62 ( V_211 ) )
return V_340 ;
else
return V_341 ;
}
static int T_11 F_146 ( struct V_282 * V_90 )
{
struct V_342 * V_343 = F_147 ( V_90 ) ;
F_148 ( V_90 ) ;
if ( ! F_149 ( V_90 ) ) {
F_150 ( V_343 ) ;
}
F_151 ( V_343 ) ;
return 0 ;
}
static int T_11 F_152 ( struct V_282 * V_90 )
{
struct V_342 * V_343 = F_147 ( V_90 ) ;
int V_192 ;
V_192 = F_153 ( V_343 ) ;
if ( V_192 )
return V_192 ;
if ( ! F_149 ( V_90 ) )
V_192 = F_154 ( V_343 ) ;
F_155 ( V_90 ) ;
return V_192 ;
}
static int
F_156 ( struct V_342 * V_344 , const struct V_345 * V_86 )
{
struct V_346 * V_347 ;
struct V_133 * V_7 ;
struct V_188 * V_189 ;
struct V_205 * V_206 , * V_348 ;
struct V_349 * V_350 ;
struct V_351 * V_352 ;
int V_212 , V_192 , V_339 ;
int V_215 ;
V_347 = F_157 ( & V_344 -> V_90 ) ;
V_192 = F_158 ( & V_344 -> V_90 , F_159 ( 32 ) ) ;
if ( V_192 )
return V_192 ;
V_189 = F_160 ( & V_344 -> V_90 , sizeof( * V_189 ) , V_257 ) ;
if ( ! V_189 ) {
F_35 ( & V_344 -> V_90 , L_43 ) ;
return - V_202 ;
}
V_350 = & V_189 -> V_89 ;
V_350 -> V_90 = & V_344 -> V_90 ;
V_189 -> V_201 = V_347 ? V_347 -> V_353 : 0 ;
V_352 = & V_344 -> V_352 ;
V_189 -> V_80 = F_161 ( & V_344 -> V_90 , V_352 ) ;
if ( F_162 ( V_189 -> V_80 ) )
return F_163 ( V_189 -> V_80 ) ;
F_164 ( V_344 , V_189 ) ;
for ( V_212 = 0 ; V_212 < V_354 ; V_212 ++ ) {
V_339 = V_344 -> V_339 [ V_212 ] ;
if ( V_339 ) {
V_192 = F_165 ( & V_344 -> V_90 , V_339 ,
F_145 , 0 ,
F_166 ( & V_344 -> V_90 ) , V_189 ) ;
if ( V_192 )
return V_192 ;
} else {
break;
}
}
V_7 = & V_189 -> V_7 ;
V_7 -> V_10 = V_344 -> V_355 ;
V_192 = F_79 ( V_189 ) ;
if ( V_192 )
return V_192 ;
F_81 ( & V_189 -> V_279 ) ;
F_80 ( & V_189 -> V_325 ) ;
if ( ! F_126 ( V_189 , V_257 , V_356 ) )
F_167 ( & V_344 -> V_90 , L_44 ) ;
F_81 ( & V_350 -> V_216 ) ;
if ( V_347 )
V_215 = F_168 ( int , V_347 -> V_357 , V_7 -> V_215 ) ;
else
V_215 = F_168 ( int , V_7 -> V_198 , V_7 -> V_215 ) ;
V_189 -> V_295 = V_215 ;
V_189 -> V_296 = F_75 ( V_215 * sizeof( * V_206 ) , V_257 ) ;
if ( ! V_189 -> V_296 ) {
V_192 = - V_202 ;
F_35 ( & V_344 -> V_90 , L_45 ) ;
goto V_358;
}
for ( V_212 = 0 ; V_212 < V_215 ; V_212 ++ ) {
V_206 = & V_189 -> V_296 [ V_212 ] ;
if ( ! V_344 -> V_90 . V_359 )
V_206 -> V_74 . V_286 = V_347 ? & V_347 -> V_281 [ V_212 ] : NULL ;
else
V_206 -> V_74 . V_286 = V_344 -> V_90 . V_359 ;
F_81 ( & V_206 -> V_308 ) ;
F_81 ( & V_206 -> V_275 ) ;
F_81 ( & V_206 -> V_274 ) ;
F_80 ( & V_206 -> V_199 ) ;
V_206 -> V_268 = NULL ;
V_206 -> V_74 . V_282 = V_350 ;
V_206 -> V_5 = V_189 ;
F_64 ( & V_206 -> V_74 . V_360 , & V_350 -> V_216 ) ;
}
if ( V_347 ) {
V_350 -> V_361 = V_347 -> V_361 ;
} else {
F_169 ( V_362 , V_350 -> V_361 ) ;
if ( V_7 -> V_198 ) {
F_169 ( V_363 , V_350 -> V_361 ) ;
F_169 ( V_364 , V_350 -> V_361 ) ;
F_169 ( V_365 , V_350 -> V_361 ) ;
}
}
V_350 -> V_366 = F_105 ;
V_350 -> V_367 = F_113 ;
V_350 -> V_368 = F_138 ;
V_350 -> V_369 = F_136 ;
V_350 -> V_370 = F_117 ;
V_350 -> V_371 = F_141 ;
V_350 -> V_372 = V_133 ;
V_350 -> V_373 = F_112 ;
V_350 -> V_374 = F_108 ;
V_350 -> V_375 = F_121 ;
V_350 -> V_376 = V_377 ;
V_350 -> V_378 = V_377 ;
V_350 -> V_379 = F_170 ( V_138 ) | F_170 ( V_137 ) ;
V_350 -> V_380 = V_381 ;
V_192 = F_171 ( V_350 ) ;
if ( V_192 ) {
F_35 ( & V_344 -> V_90 , L_46 ) ;
goto V_382;
}
if ( V_344 -> V_90 . V_359 ) {
V_192 = F_172 ( V_344 -> V_90 . V_359 ,
F_103 , V_189 ) ;
if ( V_192 ) {
F_35 ( & V_344 -> V_90 ,
L_47 ) ;
}
}
V_344 -> V_90 . V_383 = & V_189 -> V_383 ;
V_192 = F_173 ( & V_344 -> V_90 , 1900800 ) ;
if ( V_192 )
F_35 ( & V_344 -> V_90 , L_48 ) ;
F_41 ( & V_344 -> V_90 ,
L_49 , V_344 -> V_355 ) ;
F_41 ( & V_344 -> V_90 ,
L_50 ,
V_7 -> V_242 , V_7 -> V_239 / 8 , V_7 -> V_215 ,
V_7 -> V_198 , V_7 -> V_224 ) ;
F_174 ( & V_344 -> V_90 ) ;
F_175 ( & V_344 -> V_90 ) ;
F_176 ( & V_344 -> V_90 , V_384 ) ;
F_100 ( & V_344 -> V_90 ) ;
F_101 ( & V_344 -> V_90 ) ;
return 0 ;
V_382:
F_65 (pch, _p, &pl330->ddma.channels,
chan.device_node) {
F_66 ( & V_206 -> V_74 . V_360 ) ;
if ( V_206 -> V_268 ) {
F_108 ( & V_206 -> V_74 ) ;
F_113 ( & V_206 -> V_74 ) ;
}
}
V_358:
F_85 ( V_189 ) ;
return V_192 ;
}
static int F_177 ( struct V_342 * V_344 )
{
struct V_188 * V_189 = F_178 ( V_344 ) ;
struct V_205 * V_206 , * V_348 ;
F_179 ( V_189 -> V_89 . V_90 ) ;
if ( V_344 -> V_90 . V_359 )
F_180 ( V_344 -> V_90 . V_359 ) ;
F_181 ( & V_189 -> V_89 ) ;
F_65 (pch, _p, &pl330->ddma.channels,
chan.device_node) {
F_66 ( & V_206 -> V_74 . V_360 ) ;
if ( V_206 -> V_268 ) {
F_108 ( & V_206 -> V_74 ) ;
F_113 ( & V_206 -> V_74 ) ;
}
}
F_85 ( V_189 ) ;
return 0 ;
}
