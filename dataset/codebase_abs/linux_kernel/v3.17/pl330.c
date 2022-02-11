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
* ( ( T_3 * ) & V_14 [ 1 ] ) = V_17 ;
F_7 ( V_18 , L_1 ,
V_16 == 1 ? L_2 : L_3 , V_17 ) ;
return V_18 ;
}
static inline T_1 F_8 ( unsigned V_13 , T_2 V_14 [] )
{
if ( V_13 )
return V_20 ;
V_14 [ 0 ] = V_21 ;
F_7 ( V_20 , L_4 ) ;
return V_20 ;
}
static inline T_1 F_9 ( unsigned V_13 , T_2 V_14 [] , T_2 V_22 )
{
if ( V_13 )
return V_23 ;
V_14 [ 0 ] = V_24 ;
V_22 &= 0x1f ;
V_22 <<= 3 ;
V_14 [ 1 ] = V_22 ;
F_7 ( V_23 , L_5 , V_22 >> 3 ) ;
return V_23 ;
}
static inline T_1 F_10 ( unsigned V_13 , T_2 V_14 [] , enum V_25 V_26 )
{
if ( V_13 )
return V_27 ;
V_14 [ 0 ] = V_28 ;
if ( V_26 == V_29 )
V_14 [ 0 ] |= ( 0 << 1 ) | ( 1 << 0 ) ;
else if ( V_26 == V_30 )
V_14 [ 0 ] |= ( 1 << 1 ) | ( 1 << 0 ) ;
F_7 ( V_27 , L_6 ,
V_26 == V_29 ? 'S' : ( V_26 == V_30 ? 'B' : 'A' ) ) ;
return V_27 ;
}
static inline T_1 F_11 ( unsigned V_13 , T_2 V_14 [] ,
enum V_25 V_26 , T_2 V_22 )
{
if ( V_13 )
return V_31 ;
V_14 [ 0 ] = V_32 ;
if ( V_26 == V_30 )
V_14 [ 0 ] |= ( 1 << 1 ) ;
V_22 &= 0x1f ;
V_22 <<= 3 ;
V_14 [ 1 ] = V_22 ;
F_7 ( V_31 , L_7 ,
V_26 == V_29 ? 'S' : 'B' , V_22 >> 3 ) ;
return V_31 ;
}
static inline T_1 F_12 ( unsigned V_13 , T_2 V_14 [] ,
unsigned V_33 , T_2 V_34 )
{
if ( V_13 )
return V_35 ;
V_14 [ 0 ] = V_36 ;
if ( V_33 )
V_14 [ 0 ] |= ( 1 << 1 ) ;
V_34 -- ;
V_14 [ 1 ] = V_34 ;
F_7 ( V_35 , L_8 , V_33 ? '1' : '0' , V_34 ) ;
return V_35 ;
}
static inline T_1 F_13 ( unsigned V_13 , T_2 V_14 [] ,
const struct V_37 * V_38 )
{
enum V_25 V_26 = V_38 -> V_26 ;
bool V_39 = V_38 -> V_39 ;
unsigned V_33 = V_38 -> V_33 ;
T_2 V_40 = V_38 -> V_40 ;
if ( V_13 )
return V_41 ;
V_14 [ 0 ] = V_42 ;
if ( V_33 )
V_14 [ 0 ] |= ( 1 << 2 ) ;
if ( ! V_39 )
V_14 [ 0 ] |= ( 1 << 4 ) ;
if ( V_26 == V_29 )
V_14 [ 0 ] |= ( 0 << 1 ) | ( 1 << 0 ) ;
else if ( V_26 == V_30 )
V_14 [ 0 ] |= ( 1 << 1 ) | ( 1 << 0 ) ;
V_14 [ 1 ] = V_40 ;
F_7 ( V_41 , L_9 ,
V_39 ? L_10 : L_11 ,
V_26 == V_29 ? 'S' : ( V_26 == V_30 ? 'B' : 'A' ) ,
V_33 ? '1' : '0' ,
V_40 ) ;
return V_41 ;
}
static inline T_1 F_14 ( unsigned V_13 , T_2 V_14 [] )
{
if ( V_13 )
return V_43 ;
V_14 [ 0 ] = V_44 ;
return V_43 ;
}
static inline T_1 F_15 ( unsigned V_13 , T_2 V_14 [] ,
enum V_45 V_46 , T_1 V_17 )
{
if ( V_13 )
return V_47 ;
V_14 [ 0 ] = V_48 ;
V_14 [ 1 ] = V_46 ;
* ( ( T_1 * ) & V_14 [ 2 ] ) = V_17 ;
F_7 ( V_47 , L_12 ,
V_46 == V_49 ? L_13 : ( V_46 == V_50 ? L_14 : L_15 ) , V_17 ) ;
return V_47 ;
}
static inline T_1 F_16 ( unsigned V_13 , T_2 V_14 [] )
{
if ( V_13 )
return V_51 ;
V_14 [ 0 ] = V_52 ;
F_7 ( V_51 , L_16 ) ;
return V_51 ;
}
static inline T_1 F_17 ( unsigned V_13 , T_2 V_14 [] )
{
if ( V_13 )
return V_53 ;
V_14 [ 0 ] = V_54 ;
F_7 ( V_53 , L_17 ) ;
return V_53 ;
}
static inline T_1 F_18 ( unsigned V_13 , T_2 V_14 [] , T_2 V_55 )
{
if ( V_13 )
return V_56 ;
V_14 [ 0 ] = V_57 ;
V_55 &= 0x1f ;
V_55 <<= 3 ;
V_14 [ 1 ] = V_55 ;
F_7 ( V_56 , L_18 , V_55 >> 3 ) ;
return V_56 ;
}
static inline T_1 F_19 ( unsigned V_13 , T_2 V_14 [] , enum V_25 V_26 )
{
if ( V_13 )
return V_58 ;
V_14 [ 0 ] = V_59 ;
if ( V_26 == V_29 )
V_14 [ 0 ] |= ( 0 << 1 ) | ( 1 << 0 ) ;
else if ( V_26 == V_30 )
V_14 [ 0 ] |= ( 1 << 1 ) | ( 1 << 0 ) ;
F_7 ( V_58 , L_19 ,
V_26 == V_29 ? 'S' : ( V_26 == V_30 ? 'B' : 'A' ) ) ;
return V_58 ;
}
static inline T_1 F_20 ( unsigned V_13 , T_2 V_14 [] ,
enum V_25 V_26 , T_2 V_22 )
{
if ( V_13 )
return V_60 ;
V_14 [ 0 ] = V_61 ;
if ( V_26 == V_30 )
V_14 [ 0 ] |= ( 1 << 1 ) ;
V_22 &= 0x1f ;
V_22 <<= 3 ;
V_14 [ 1 ] = V_22 ;
F_7 ( V_60 , L_20 ,
V_26 == V_29 ? 'S' : 'B' , V_22 >> 3 ) ;
return V_60 ;
}
static inline T_1 F_21 ( unsigned V_13 , T_2 V_14 [] )
{
if ( V_13 )
return V_62 ;
V_14 [ 0 ] = V_63 ;
F_7 ( V_62 , L_21 ) ;
return V_62 ;
}
static inline T_1 F_22 ( unsigned V_13 , T_2 V_14 [] , T_2 V_55 ,
unsigned V_64 )
{
if ( V_13 )
return V_65 ;
V_14 [ 0 ] = V_66 ;
V_55 &= 0x1f ;
V_55 <<= 3 ;
V_14 [ 1 ] = V_55 ;
if ( V_64 )
V_14 [ 1 ] |= ( 1 << 1 ) ;
F_7 ( V_65 , L_22 ,
V_55 >> 3 , V_64 ? L_23 : L_24 ) ;
return V_65 ;
}
static inline T_1 F_23 ( unsigned V_13 , T_2 V_14 [] ,
enum V_25 V_26 , T_2 V_22 )
{
if ( V_13 )
return V_67 ;
V_14 [ 0 ] = V_68 ;
if ( V_26 == V_29 )
V_14 [ 0 ] |= ( 0 << 1 ) | ( 0 << 0 ) ;
else if ( V_26 == V_30 )
V_14 [ 0 ] |= ( 1 << 1 ) | ( 0 << 0 ) ;
else
V_14 [ 0 ] |= ( 0 << 1 ) | ( 1 << 0 ) ;
V_22 &= 0x1f ;
V_22 <<= 3 ;
V_14 [ 1 ] = V_22 ;
F_7 ( V_67 , L_25 ,
V_26 == V_29 ? 'S' : ( V_26 == V_30 ? 'B' : 'P' ) , V_22 >> 3 ) ;
return V_67 ;
}
static inline T_1 F_24 ( unsigned V_13 , T_2 V_14 [] )
{
if ( V_13 )
return V_69 ;
V_14 [ 0 ] = V_70 ;
F_7 ( V_69 , L_26 ) ;
return V_69 ;
}
static inline T_1 F_25 ( unsigned V_13 , T_2 V_14 [] ,
const struct V_71 * V_38 )
{
T_2 V_72 = V_38 -> V_72 ;
T_1 V_73 = V_38 -> V_73 ;
unsigned V_74 = V_38 -> V_74 ;
if ( V_13 )
return V_75 ;
V_14 [ 0 ] = V_76 ;
V_14 [ 0 ] |= ( V_74 << 1 ) ;
V_14 [ 1 ] = V_72 & 0x7 ;
* ( ( T_1 * ) & V_14 [ 2 ] ) = V_73 ;
return V_75 ;
}
static bool F_26 ( struct V_1 * V_2 )
{
void T_4 * V_77 = V_2 -> V_5 -> V_78 ;
unsigned long V_79 = F_27 ( 5 ) ;
do {
if ( ! ( F_28 ( V_77 + V_80 ) & V_81 ) )
break;
F_29 () ;
} while ( -- V_79 );
if ( ! V_79 )
return true ;
return false ;
}
static inline void F_30 ( struct V_1 * V_2 ,
T_2 V_82 [] , bool V_83 )
{
void T_4 * V_77 = V_2 -> V_5 -> V_78 ;
T_1 V_17 ;
V_17 = ( V_82 [ 0 ] << 16 ) | ( V_82 [ 1 ] << 24 ) ;
if ( ! V_83 ) {
V_17 |= ( 1 << 0 ) ;
V_17 |= ( V_2 -> V_84 << 8 ) ;
}
F_31 ( V_17 , V_77 + V_85 ) ;
V_17 = * ( ( T_1 * ) & V_82 [ 2 ] ) ;
F_31 ( V_17 , V_77 + V_86 ) ;
if ( F_26 ( V_2 ) ) {
F_32 ( V_2 -> V_5 -> V_87 . V_88 , L_27 ) ;
return;
}
F_31 ( 0 , V_77 + V_89 ) ;
}
static inline T_1 F_33 ( struct V_1 * V_2 )
{
void T_4 * V_77 = V_2 -> V_5 -> V_78 ;
T_1 V_17 ;
if ( F_3 ( V_2 ) )
V_17 = F_28 ( V_77 + V_90 ) & 0xf ;
else
V_17 = F_28 ( V_77 + F_34 ( V_2 -> V_84 ) ) & 0xf ;
switch ( V_17 ) {
case V_91 :
return V_92 ;
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
if ( F_3 ( V_2 ) )
return V_104 ;
else
return V_105 ;
case V_106 :
if ( F_3 ( V_2 ) )
return V_104 ;
else
return V_107 ;
case V_108 :
if ( F_3 ( V_2 ) )
return V_104 ;
else
return V_109 ;
case V_110 :
if ( F_3 ( V_2 ) )
return V_104 ;
else
return V_111 ;
case V_112 :
if ( F_3 ( V_2 ) )
return V_104 ;
else
return V_113 ;
case V_114 :
if ( F_3 ( V_2 ) )
return V_104 ;
else
return V_115 ;
default:
return V_104 ;
}
}
static void F_35 ( struct V_1 * V_2 )
{
void T_4 * V_77 = V_2 -> V_5 -> V_78 ;
T_2 V_82 [ 6 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
if ( F_33 ( V_2 ) == V_115 )
F_36 ( V_2 , V_102 | V_111 ) ;
if ( F_33 ( V_2 ) == V_113
|| F_33 ( V_2 ) == V_111
|| F_33 ( V_2 ) == V_92 )
return;
F_14 ( 0 , V_82 ) ;
F_31 ( F_28 ( V_77 + V_116 ) & ~ ( 1 << V_2 -> V_55 ) , V_77 + V_116 ) ;
F_30 ( V_2 , V_82 , F_3 ( V_2 ) ) ;
}
static bool F_37 ( struct V_1 * V_2 )
{
void T_4 * V_77 = V_2 -> V_5 -> V_78 ;
struct V_117 * V_3 ;
struct V_118 * V_4 ;
struct V_71 V_119 ;
unsigned V_74 ;
T_2 V_82 [ 6 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_120 ;
if ( F_33 ( V_2 ) != V_92 )
return true ;
V_120 = 1 - V_2 -> V_121 ;
if ( V_2 -> V_3 [ V_120 ] . V_4 != NULL ) {
V_3 = & V_2 -> V_3 [ V_120 ] ;
} else {
V_120 = V_2 -> V_121 ;
if ( V_2 -> V_3 [ V_120 ] . V_4 != NULL )
V_3 = & V_2 -> V_3 [ V_120 ] ;
else
V_3 = NULL ;
}
if ( ! V_3 )
return true ;
V_4 = V_3 -> V_4 ;
V_74 = V_4 -> V_122 . V_123 ? 1 : 0 ;
if ( F_4 ( V_2 ) && ! V_74 )
F_38 ( V_2 -> V_5 -> V_87 . V_88 , L_28 ,
V_124 , __LINE__ ) ;
V_119 . V_72 = V_2 -> V_84 ;
V_119 . V_73 = V_3 -> V_125 ;
V_119 . V_74 = V_74 ;
F_25 ( 0 , V_82 , & V_119 ) ;
F_31 ( F_28 ( V_77 + V_116 ) | ( 1 << V_2 -> V_55 ) , V_77 + V_116 ) ;
F_30 ( V_2 , V_82 , true ) ;
V_2 -> V_126 = V_120 ;
return true ;
}
static bool F_39 ( struct V_1 * V_2 )
{
switch ( F_33 ( V_2 ) ) {
case V_115 :
F_36 ( V_2 , V_102 | V_111 ) ;
if ( F_33 ( V_2 ) == V_111 )
F_36 (thrd, PL330_STATE_STOPPED)
case V_102 :
F_35 ( V_2 ) ;
case V_111 :
case V_113 :
F_36 (thrd, PL330_STATE_STOPPED)
case V_92 :
return F_37 ( V_2 ) ;
case V_109 :
case V_107 :
case V_105 :
case V_98 :
case V_96 :
case V_94 :
return true ;
case V_100 :
default:
return false ;
}
}
static inline int F_40 ( unsigned V_13 , T_2 V_14 [] ,
const struct V_127 * V_128 , int V_129 )
{
int V_130 = 0 ;
struct V_131 * V_7 = V_128 -> V_4 -> V_122 . V_7 ;
if ( F_5 ( V_7 -> V_10 ) >= V_132 ) {
while ( V_129 -- ) {
V_130 += F_10 ( V_13 , & V_14 [ V_130 ] , V_133 ) ;
V_130 += F_19 ( V_13 , & V_14 [ V_130 ] , V_133 ) ;
}
} else {
while ( V_129 -- ) {
V_130 += F_10 ( V_13 , & V_14 [ V_130 ] , V_133 ) ;
V_130 += F_17 ( V_13 , & V_14 [ V_130 ] ) ;
V_130 += F_19 ( V_13 , & V_14 [ V_130 ] , V_133 ) ;
V_130 += F_24 ( V_13 , & V_14 [ V_130 ] ) ;
}
}
return V_130 ;
}
static inline int F_41 ( unsigned V_13 , T_2 V_14 [] ,
const struct V_127 * V_128 , int V_129 )
{
int V_130 = 0 ;
while ( V_129 -- ) {
V_130 += F_23 ( V_13 , & V_14 [ V_130 ] , V_29 , V_128 -> V_4 -> V_22 ) ;
V_130 += F_11 ( V_13 , & V_14 [ V_130 ] , V_29 , V_128 -> V_4 -> V_22 ) ;
V_130 += F_19 ( V_13 , & V_14 [ V_130 ] , V_133 ) ;
V_130 += F_9 ( V_13 , & V_14 [ V_130 ] , V_128 -> V_4 -> V_22 ) ;
}
return V_130 ;
}
static inline int F_42 ( unsigned V_13 , T_2 V_14 [] ,
const struct V_127 * V_128 , int V_129 )
{
int V_130 = 0 ;
while ( V_129 -- ) {
V_130 += F_23 ( V_13 , & V_14 [ V_130 ] , V_29 , V_128 -> V_4 -> V_22 ) ;
V_130 += F_10 ( V_13 , & V_14 [ V_130 ] , V_133 ) ;
V_130 += F_20 ( V_13 , & V_14 [ V_130 ] , V_29 , V_128 -> V_4 -> V_22 ) ;
V_130 += F_9 ( V_13 , & V_14 [ V_130 ] , V_128 -> V_4 -> V_22 ) ;
}
return V_130 ;
}
static int F_43 ( unsigned V_13 , T_2 V_14 [] ,
const struct V_127 * V_128 , int V_129 )
{
int V_130 = 0 ;
switch ( V_128 -> V_4 -> V_134 ) {
case V_135 :
V_130 += F_42 ( V_13 , & V_14 [ V_130 ] , V_128 , V_129 ) ;
break;
case V_136 :
V_130 += F_41 ( V_13 , & V_14 [ V_130 ] , V_128 , V_129 ) ;
break;
case V_137 :
V_130 += F_40 ( V_13 , & V_14 [ V_130 ] , V_128 , V_129 ) ;
break;
default:
V_130 += 0x40000000 ;
break;
}
return V_130 ;
}
static inline int F_44 ( unsigned V_13 , T_2 V_14 [] ,
unsigned long * V_138 , const struct V_127 * V_128 )
{
int V_129 , V_139 , V_140 , V_141 , V_142 , V_130 ;
unsigned V_143 , V_144 , V_145 , V_146 ;
struct V_37 V_147 ;
if ( * V_138 >= 256 * 256 ) {
V_144 = 256 ;
V_143 = 256 ;
V_129 = * V_138 / V_144 / V_143 ;
} else if ( * V_138 > 256 ) {
V_144 = 256 ;
V_143 = * V_138 / V_144 ;
V_129 = 1 ;
} else {
V_144 = * V_138 ;
V_143 = 0 ;
V_129 = 1 ;
}
V_140 = F_12 ( 1 , V_14 , 0 , 0 ) ;
V_142 = F_43 ( 1 , V_14 , V_128 , 1 ) ;
V_147 . V_26 = V_133 ;
V_147 . V_39 = false ;
V_147 . V_33 = 0 ;
V_147 . V_40 = 0 ;
V_141 = F_13 ( 1 , V_14 , & V_147 ) ;
if ( V_143 ) {
V_140 *= 2 ;
V_141 *= 2 ;
}
V_139 = ( 255 - ( V_140 + V_141 ) ) / V_142 ;
V_129 = ( V_139 < V_129 ) ? V_139 : V_129 ;
V_130 = 0 ;
if ( V_143 ) {
V_130 += F_12 ( V_13 , & V_14 [ V_130 ] , 0 , V_143 ) ;
V_145 = V_130 ;
}
V_130 += F_12 ( V_13 , & V_14 [ V_130 ] , 1 , V_144 ) ;
V_146 = V_130 ;
V_130 += F_43 ( V_13 , & V_14 [ V_130 ] , V_128 , V_129 ) ;
V_147 . V_26 = V_133 ;
V_147 . V_39 = false ;
V_147 . V_33 = 1 ;
V_147 . V_40 = V_130 - V_146 ;
V_130 += F_13 ( V_13 , & V_14 [ V_130 ] , & V_147 ) ;
if ( V_143 ) {
V_147 . V_26 = V_133 ;
V_147 . V_39 = false ;
V_147 . V_33 = 0 ;
V_147 . V_40 = V_130 - V_145 ;
V_130 += F_13 ( V_13 , & V_14 [ V_130 ] , & V_147 ) ;
}
* V_138 = V_144 * V_129 ;
if ( V_143 )
* V_138 *= V_143 ;
return V_130 ;
}
static inline int F_45 ( unsigned V_13 , T_2 V_14 [] ,
const struct V_127 * V_128 )
{
struct V_148 * V_149 = & V_128 -> V_4 -> V_150 ;
T_1 V_151 = V_128 -> V_151 ;
unsigned long V_152 , V_138 = F_46 ( V_149 -> V_153 , V_151 ) ;
int V_130 = 0 ;
while ( V_138 ) {
V_152 = V_138 ;
V_130 += F_44 ( V_13 , & V_14 [ V_130 ] , & V_152 , V_128 ) ;
V_138 -= V_152 ;
}
return V_130 ;
}
static inline int F_47 ( unsigned V_13 , T_2 V_14 [] ,
const struct V_127 * V_128 )
{
struct V_148 * V_149 = & V_128 -> V_4 -> V_150 ;
int V_130 = 0 ;
V_130 += F_15 ( V_13 , & V_14 [ V_130 ] , V_49 , V_149 -> V_154 ) ;
V_130 += F_15 ( V_13 , & V_14 [ V_130 ] , V_50 , V_149 -> V_155 ) ;
V_130 += F_45 ( V_13 , & V_14 [ V_130 ] , V_128 ) ;
return V_130 ;
}
static int F_48 ( unsigned V_13 , struct V_1 * V_2 ,
unsigned V_156 , struct V_127 * V_128 )
{
struct V_117 * V_3 = & V_2 -> V_3 [ V_156 ] ;
struct V_148 * V_149 ;
T_2 * V_14 = V_3 -> V_157 ;
int V_130 = 0 ;
F_49 ( V_3 -> V_125 ) ;
V_130 += F_15 ( V_13 , & V_14 [ V_130 ] , V_158 , V_128 -> V_151 ) ;
V_149 = & V_128 -> V_4 -> V_150 ;
if ( V_149 -> V_153 % ( F_50 ( V_128 -> V_151 ) * F_51 ( V_128 -> V_151 ) ) )
return - V_159 ;
V_130 += F_47 ( V_13 , & V_14 [ V_130 ] , V_128 ) ;
V_130 += F_18 ( V_13 , & V_14 [ V_130 ] , V_2 -> V_55 ) ;
V_130 += F_8 ( V_13 , & V_14 [ V_130 ] ) ;
return V_130 ;
}
static inline T_1 F_52 ( const struct V_160 * V_161 )
{
T_1 V_151 = 0 ;
if ( V_161 -> V_162 )
V_151 |= V_163 ;
if ( V_161 -> V_164 )
V_151 |= V_165 ;
if ( V_161 -> V_166 )
V_151 |= V_167 | V_168 ;
if ( V_161 -> V_123 )
V_151 |= V_169 | V_170 ;
if ( V_161 -> V_171 )
V_151 |= V_172 | V_173 ;
V_151 |= ( ( ( V_161 -> V_174 - 1 ) & 0xf ) << V_175 ) ;
V_151 |= ( ( ( V_161 -> V_174 - 1 ) & 0xf ) << V_176 ) ;
V_151 |= ( V_161 -> V_177 << V_178 ) ;
V_151 |= ( V_161 -> V_177 << V_179 ) ;
V_151 |= ( V_161 -> V_180 << V_181 ) ;
V_151 |= ( V_161 -> V_182 << V_183 ) ;
V_151 |= ( V_161 -> V_184 << V_185 ) ;
return V_151 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_118 * V_4 )
{
struct V_186 * V_187 = V_2 -> V_5 ;
struct V_127 V_188 ;
unsigned long V_189 ;
void T_4 * V_77 ;
unsigned V_120 ;
T_1 V_151 ;
int V_190 = 0 ;
if ( ! V_4 || ! V_2 || V_2 -> free )
return - V_159 ;
V_77 = V_2 -> V_5 -> V_78 ;
if ( V_187 -> V_191 == V_192
|| V_187 -> V_193 . V_194 & ( 1 << V_2 -> V_84 ) ) {
F_38 ( V_2 -> V_5 -> V_87 . V_88 , L_29 ,
V_124 , __LINE__ ) ;
return - V_195 ;
}
if ( V_4 -> V_134 != V_137 &&
V_4 -> V_22 >= V_187 -> V_7 . V_196 ) {
F_38 ( V_2 -> V_5 -> V_87 . V_88 ,
L_30 ,
V_124 , __LINE__ , V_4 -> V_22 ) ;
return - V_159 ;
}
F_54 ( & V_187 -> V_197 , V_189 ) ;
if ( F_2 ( V_2 ) ) {
V_190 = - V_195 ;
goto V_198;
}
if ( ! F_4 ( V_2 ) )
V_4 -> V_122 . V_123 = 0 ;
else
V_4 -> V_122 . V_123 = 1 ;
V_151 = F_52 ( & V_4 -> V_122 ) ;
V_120 = V_2 -> V_3 [ 0 ] . V_4 == NULL ? 0 : 1 ;
V_188 . V_151 = V_151 ;
V_188 . V_4 = V_4 ;
V_190 = F_48 ( 1 , V_2 , V_120 , & V_188 ) ;
if ( V_190 < 0 )
goto V_198;
if ( V_190 > V_187 -> V_199 / 2 ) {
F_38 ( V_187 -> V_87 . V_88 , L_31 ,
V_124 , __LINE__ ) ;
V_190 = - V_200 ;
goto V_198;
}
V_2 -> V_121 = V_120 ;
V_2 -> V_3 [ V_120 ] . V_4 = V_4 ;
F_48 ( 0 , V_2 , V_120 , & V_188 ) ;
V_190 = 0 ;
V_198:
F_55 ( & V_187 -> V_197 , V_189 ) ;
return V_190 ;
}
static void F_56 ( struct V_118 * V_4 , enum V_201 V_202 )
{
struct V_203 * V_204 ;
unsigned long V_189 ;
if ( ! V_4 )
return;
V_204 = V_4 -> V_205 ;
if ( ! V_204 )
return;
F_54 ( & V_204 -> V_197 , V_189 ) ;
V_4 -> V_206 = V_207 ;
F_55 ( & V_204 -> V_197 , V_189 ) ;
F_57 ( & V_204 -> V_208 ) ;
}
static void F_58 ( unsigned long V_209 )
{
struct V_186 * V_187 = (struct V_186 * ) V_209 ;
unsigned long V_189 ;
int V_210 ;
F_54 ( & V_187 -> V_197 , V_189 ) ;
if ( V_187 -> V_193 . V_211 ) {
V_187 -> V_191 = V_192 ;
V_187 -> V_193 . V_212 = true ;
V_187 -> V_193 . V_211 = false ;
}
if ( V_187 -> V_193 . V_212 ) {
F_35 ( V_187 -> V_6 ) ;
V_187 -> V_193 . V_194 = ( 1 << V_187 -> V_7 . V_213 ) - 1 ;
V_187 -> V_193 . V_212 = false ;
}
for ( V_210 = 0 ; V_210 < V_187 -> V_7 . V_213 ; V_210 ++ ) {
if ( V_187 -> V_193 . V_194 & ( 1 << V_210 ) ) {
struct V_1 * V_2 = & V_187 -> V_214 [ V_210 ] ;
void T_4 * V_77 = V_187 -> V_78 ;
enum V_201 V_202 ;
F_35 ( V_2 ) ;
if ( F_28 ( V_77 + V_215 ) & ( 1 << V_2 -> V_84 ) )
V_202 = V_216 ;
else
V_202 = V_217 ;
F_55 ( & V_187 -> V_197 , V_189 ) ;
F_56 ( V_2 -> V_3 [ 1 - V_2 -> V_121 ] . V_4 , V_202 ) ;
F_56 ( V_2 -> V_3 [ V_2 -> V_121 ] . V_4 , V_202 ) ;
F_54 ( & V_187 -> V_197 , V_189 ) ;
V_2 -> V_3 [ 0 ] . V_4 = NULL ;
V_2 -> V_3 [ 1 ] . V_4 = NULL ;
V_2 -> V_126 = - 1 ;
V_187 -> V_193 . V_194 &= ~ ( 1 << V_210 ) ;
}
}
F_55 ( & V_187 -> V_197 , V_189 ) ;
return;
}
static int F_59 ( struct V_186 * V_187 )
{
struct V_118 * V_218 , * V_219 ;
unsigned long V_189 ;
void T_4 * V_77 ;
T_1 V_17 ;
int V_84 , V_55 , V_190 = 0 ;
V_77 = V_187 -> V_78 ;
F_54 ( & V_187 -> V_197 , V_189 ) ;
V_17 = F_28 ( V_77 + V_220 ) & 0x1 ;
if ( V_17 )
V_187 -> V_193 . V_212 = true ;
else
V_187 -> V_193 . V_212 = false ;
V_17 = F_28 ( V_77 + V_215 ) & ( ( 1 << V_187 -> V_7 . V_213 ) - 1 ) ;
V_187 -> V_193 . V_194 |= V_17 ;
if ( V_17 ) {
int V_210 = 0 ;
while ( V_210 < V_187 -> V_7 . V_213 ) {
if ( V_17 & ( 1 << V_210 ) ) {
F_38 ( V_187 -> V_87 . V_88 ,
L_32 ,
V_210 , F_28 ( V_77 + F_34 ( V_210 ) ) ,
F_28 ( V_77 + F_60 ( V_210 ) ) ) ;
F_35 ( & V_187 -> V_214 [ V_210 ] ) ;
}
V_210 ++ ;
}
}
V_17 = F_28 ( V_77 + V_221 ) ;
if ( V_187 -> V_7 . V_222 < 32
&& V_17 & ~ ( ( 1 << V_187 -> V_7 . V_222 ) - 1 ) ) {
V_187 -> V_193 . V_211 = true ;
F_32 ( V_187 -> V_87 . V_88 , L_33 , V_124 ,
__LINE__ ) ;
V_190 = 1 ;
goto V_223;
}
for ( V_55 = 0 ; V_55 < V_187 -> V_7 . V_222 ; V_55 ++ ) {
if ( V_17 & ( 1 << V_55 ) ) {
struct V_1 * V_2 ;
T_1 V_224 = F_28 ( V_77 + V_116 ) ;
int V_225 ;
if ( V_224 & ( 1 << V_55 ) )
F_31 ( 1 << V_55 , V_77 + V_226 ) ;
V_190 = 1 ;
V_84 = V_187 -> V_227 [ V_55 ] ;
V_2 = & V_187 -> V_214 [ V_84 ] ;
V_225 = V_2 -> V_126 ;
if ( V_225 == - 1 )
continue;
V_218 = V_2 -> V_3 [ V_225 ] . V_4 ;
V_2 -> V_3 [ V_225 ] . V_4 = NULL ;
F_39 ( V_2 ) ;
F_61 ( & V_218 -> V_228 , & V_187 -> V_229 ) ;
}
}
F_62 (descdone, tmp, &pl330->req_done, rqd) {
F_63 ( & V_218 -> V_228 ) ;
F_55 ( & V_187 -> V_197 , V_189 ) ;
F_56 ( V_218 , V_230 ) ;
F_54 ( & V_187 -> V_197 , V_189 ) ;
}
V_223:
F_55 ( & V_187 -> V_197 , V_189 ) ;
if ( V_187 -> V_193 . V_211
|| V_187 -> V_193 . V_212
|| V_187 -> V_193 . V_194 ) {
V_190 = 1 ;
F_57 ( & V_187 -> V_231 ) ;
}
return V_190 ;
}
static inline int F_64 ( struct V_1 * V_2 )
{
struct V_186 * V_187 = V_2 -> V_5 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_187 -> V_7 . V_222 ; V_55 ++ )
if ( V_187 -> V_227 [ V_55 ] == - 1 ) {
V_187 -> V_227 [ V_55 ] = V_2 -> V_84 ;
return V_55 ;
}
return - 1 ;
}
static bool F_65 ( const struct V_186 * V_187 , int V_210 )
{
return V_187 -> V_7 . V_232 & ( 1 << V_210 ) ;
}
static struct V_1 * F_66 ( struct V_186 * V_187 )
{
struct V_1 * V_2 = NULL ;
unsigned long V_189 ;
int V_233 , V_210 ;
if ( V_187 -> V_191 == V_192 )
return NULL ;
V_233 = V_187 -> V_7 . V_213 ;
F_54 ( & V_187 -> V_197 , V_189 ) ;
for ( V_210 = 0 ; V_210 < V_233 ; V_210 ++ ) {
V_2 = & V_187 -> V_214 [ V_210 ] ;
if ( ( V_2 -> free ) && ( ! F_4 ( V_2 ) ||
F_65 ( V_187 , V_210 ) ) ) {
V_2 -> V_55 = F_64 ( V_2 ) ;
if ( V_2 -> V_55 >= 0 ) {
V_2 -> free = false ;
V_2 -> V_121 = 1 ;
V_2 -> V_3 [ 0 ] . V_4 = NULL ;
V_2 -> V_3 [ 1 ] . V_4 = NULL ;
V_2 -> V_126 = - 1 ;
break;
}
}
V_2 = NULL ;
}
F_55 ( & V_187 -> V_197 , V_189 ) ;
return V_2 ;
}
static inline void F_67 ( struct V_1 * V_2 , int V_55 )
{
struct V_186 * V_187 = V_2 -> V_5 ;
if ( V_55 >= 0 && V_55 < V_187 -> V_7 . V_222
&& V_187 -> V_227 [ V_55 ] == V_2 -> V_84 )
V_187 -> V_227 [ V_55 ] = - 1 ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_186 * V_187 ;
unsigned long V_189 ;
if ( ! V_2 || V_2 -> free )
return;
F_35 ( V_2 ) ;
F_56 ( V_2 -> V_3 [ 1 - V_2 -> V_121 ] . V_4 , V_217 ) ;
F_56 ( V_2 -> V_3 [ V_2 -> V_121 ] . V_4 , V_217 ) ;
V_187 = V_2 -> V_5 ;
F_54 ( & V_187 -> V_197 , V_189 ) ;
F_67 ( V_2 , V_2 -> V_55 ) ;
V_2 -> free = true ;
F_55 ( & V_187 -> V_197 , V_189 ) ;
}
static void F_69 ( struct V_186 * V_187 )
{
void T_4 * V_77 = V_187 -> V_78 ;
T_1 V_17 ;
V_17 = F_28 ( V_77 + V_234 ) >> V_235 ;
V_17 &= V_236 ;
V_187 -> V_7 . V_237 = 8 * ( 1 << V_17 ) ;
V_17 = F_28 ( V_77 + V_234 ) >> V_238 ;
V_17 &= V_239 ;
V_187 -> V_7 . V_240 = V_17 + 1 ;
V_17 = F_28 ( V_77 + V_241 ) >> V_242 ;
V_17 &= V_243 ;
V_17 += 1 ;
V_187 -> V_7 . V_213 = V_17 ;
V_17 = F_28 ( V_77 + V_241 ) ;
if ( V_17 & V_244 ) {
V_17 = ( V_17 >> V_245 ) & V_246 ;
V_17 += 1 ;
V_187 -> V_7 . V_196 = V_17 ;
V_187 -> V_7 . V_247 = F_28 ( V_77 + V_248 ) ;
} else {
V_187 -> V_7 . V_196 = 0 ;
}
V_17 = F_28 ( V_77 + V_241 ) ;
if ( V_17 & V_249 )
V_187 -> V_7 . V_8 |= V_9 ;
else
V_187 -> V_7 . V_8 &= ~ V_9 ;
V_17 = F_28 ( V_77 + V_241 ) >> V_250 ;
V_17 &= V_251 ;
V_17 += 1 ;
V_187 -> V_7 . V_222 = V_17 ;
V_187 -> V_7 . V_232 = F_28 ( V_77 + V_252 ) ;
}
static inline void F_70 ( struct V_1 * V_2 )
{
struct V_186 * V_187 = V_2 -> V_5 ;
V_2 -> V_3 [ 0 ] . V_157 = V_187 -> V_253
+ ( V_2 -> V_84 * V_187 -> V_199 ) ;
V_2 -> V_3 [ 0 ] . V_125 = V_187 -> V_254
+ ( V_2 -> V_84 * V_187 -> V_199 ) ;
V_2 -> V_3 [ 0 ] . V_4 = NULL ;
V_2 -> V_3 [ 1 ] . V_157 = V_2 -> V_3 [ 0 ] . V_157
+ V_187 -> V_199 / 2 ;
V_2 -> V_3 [ 1 ] . V_125 = V_2 -> V_3 [ 0 ] . V_125
+ V_187 -> V_199 / 2 ;
V_2 -> V_3 [ 1 ] . V_4 = NULL ;
V_2 -> V_126 = - 1 ;
}
static int F_71 ( struct V_186 * V_187 )
{
int V_233 = V_187 -> V_7 . V_213 ;
struct V_1 * V_2 ;
int V_210 ;
V_187 -> V_214 = F_72 ( ( 1 + V_233 ) * sizeof( * V_2 ) ,
V_255 ) ;
if ( ! V_187 -> V_214 )
return - V_200 ;
for ( V_210 = 0 ; V_210 < V_233 ; V_210 ++ ) {
V_2 = & V_187 -> V_214 [ V_210 ] ;
V_2 -> V_84 = V_210 ;
V_2 -> V_5 = V_187 ;
F_70 ( V_2 ) ;
V_2 -> free = true ;
}
V_2 = & V_187 -> V_214 [ V_233 ] ;
V_2 -> V_84 = V_233 ;
V_2 -> V_5 = V_187 ;
V_2 -> free = false ;
V_187 -> V_6 = V_2 ;
return 0 ;
}
static int F_73 ( struct V_186 * V_187 )
{
int V_233 = V_187 -> V_7 . V_213 ;
int V_190 ;
V_187 -> V_253 = F_74 ( V_187 -> V_87 . V_88 ,
V_233 * V_187 -> V_199 ,
& V_187 -> V_254 , V_255 ) ;
if ( ! V_187 -> V_253 ) {
F_32 ( V_187 -> V_87 . V_88 , L_34 ,
V_124 , __LINE__ ) ;
return - V_200 ;
}
V_190 = F_71 ( V_187 ) ;
if ( V_190 ) {
F_32 ( V_187 -> V_87 . V_88 , L_35 ,
V_124 , __LINE__ ) ;
F_75 ( V_187 -> V_87 . V_88 ,
V_233 * V_187 -> V_199 ,
V_187 -> V_253 , V_187 -> V_254 ) ;
return V_190 ;
}
return 0 ;
}
static int F_76 ( struct V_186 * V_187 )
{
void T_4 * V_77 ;
int V_210 , V_190 ;
V_77 = V_187 -> V_78 ;
if ( ( V_187 -> V_7 . V_10 & 0xfffff ) != V_256 ) {
F_32 ( V_187 -> V_87 . V_88 , L_36 ,
V_187 -> V_7 . V_10 ) ;
return - V_159 ;
}
F_69 ( V_187 ) ;
if ( V_187 -> V_7 . V_222 == 0 ) {
F_32 ( V_187 -> V_87 . V_88 , L_37 ,
V_124 , __LINE__ ) ;
return - V_159 ;
}
F_77 ( & V_187 -> V_197 ) ;
F_78 ( & V_187 -> V_229 ) ;
if ( ! V_187 -> V_199 )
V_187 -> V_199 = V_257 * 2 ;
for ( V_210 = 0 ; V_210 < V_187 -> V_7 . V_222 ; V_210 ++ )
V_187 -> V_227 [ V_210 ] = - 1 ;
V_190 = F_73 ( V_187 ) ;
if ( V_190 ) {
F_32 ( V_187 -> V_87 . V_88 , L_38 ) ;
return V_190 ;
}
F_79 ( & V_187 -> V_231 , F_58 , ( unsigned long ) V_187 ) ;
V_187 -> V_191 = V_258 ;
return 0 ;
}
static int F_80 ( struct V_186 * V_187 )
{
struct V_1 * V_2 ;
int V_210 ;
for ( V_210 = 0 ; V_210 < V_187 -> V_7 . V_213 ; V_210 ++ ) {
V_2 = & V_187 -> V_214 [ V_210 ] ;
F_68 ( V_2 ) ;
}
F_81 ( V_187 -> V_214 ) ;
return 0 ;
}
static void F_82 ( struct V_186 * V_187 )
{
V_187 -> V_191 = V_259 ;
F_83 ( & V_187 -> V_231 ) ;
F_80 ( V_187 ) ;
F_75 ( V_187 -> V_87 . V_88 ,
V_187 -> V_7 . V_213 * V_187 -> V_199 , V_187 -> V_253 ,
V_187 -> V_254 ) ;
}
static inline struct V_203 *
F_84 ( struct V_260 * V_261 )
{
if ( ! V_261 )
return NULL ;
return F_85 ( V_261 , struct V_203 , V_72 ) ;
}
static inline struct V_118 *
F_86 ( struct V_262 * V_263 )
{
return F_85 ( V_263 , struct V_118 , V_264 ) ;
}
static inline void F_87 ( struct V_203 * V_204 )
{
struct V_118 * V_4 ;
int V_190 ;
F_88 (desc, &pch->work_list, node) {
if ( V_4 -> V_206 == V_265 )
continue;
V_190 = F_53 ( V_204 -> V_266 , V_4 ) ;
if ( ! V_190 ) {
V_4 -> V_206 = V_265 ;
} else if ( V_190 == - V_195 ) {
break;
} else {
V_4 -> V_206 = V_207 ;
F_32 ( V_204 -> V_5 -> V_87 . V_88 , L_39 ,
V_124 , __LINE__ , V_4 -> V_264 . V_267 ) ;
F_57 ( & V_204 -> V_208 ) ;
}
}
}
static void F_89 ( unsigned long V_209 )
{
struct V_203 * V_204 = (struct V_203 * ) V_209 ;
struct V_118 * V_4 , * V_268 ;
unsigned long V_189 ;
F_54 ( & V_204 -> V_197 , V_189 ) ;
F_62 (desc, _dt, &pch->work_list, node)
if ( V_4 -> V_206 == V_207 ) {
if ( ! V_204 -> V_269 )
F_90 ( & V_4 -> V_264 ) ;
F_91 ( & V_4 -> V_270 , & V_204 -> V_271 ) ;
}
F_87 ( V_204 ) ;
F_92 ( & V_204 -> V_266 -> V_5 -> V_197 ) ;
F_39 ( V_204 -> V_266 ) ;
F_93 ( & V_204 -> V_266 -> V_5 -> V_197 ) ;
while ( ! F_94 ( & V_204 -> V_271 ) ) {
T_5 V_272 ;
void * V_273 ;
V_4 = F_95 ( & V_204 -> V_271 ,
struct V_118 , V_270 ) ;
V_272 = V_4 -> V_264 . V_272 ;
V_273 = V_4 -> V_264 . V_273 ;
if ( V_204 -> V_269 ) {
V_4 -> V_206 = V_274 ;
F_91 ( & V_4 -> V_270 , & V_204 -> V_275 ) ;
} else {
V_4 -> V_206 = FREE ;
F_91 ( & V_4 -> V_270 , & V_204 -> V_5 -> V_276 ) ;
}
F_96 ( & V_4 -> V_264 ) ;
if ( V_272 ) {
F_55 ( & V_204 -> V_197 , V_189 ) ;
V_272 ( V_273 ) ;
F_54 ( & V_204 -> V_197 , V_189 ) ;
}
}
F_55 ( & V_204 -> V_197 , V_189 ) ;
}
bool F_97 ( struct V_260 * V_72 , void * V_277 )
{
T_2 * V_278 ;
if ( V_72 -> V_279 -> V_88 -> V_280 != & V_281 . V_282 )
return false ;
V_278 = V_72 -> V_283 ;
return * V_278 == ( unsigned long ) V_277 ;
}
static struct V_260 * F_98 ( struct V_284 * V_285 ,
struct V_286 * V_287 )
{
int V_288 = V_285 -> V_289 ;
struct V_186 * V_187 = V_287 -> V_290 ;
unsigned int V_291 ;
if ( ! V_187 )
return NULL ;
if ( V_288 != 1 )
return NULL ;
V_291 = V_285 -> args [ 0 ] ;
if ( V_291 >= V_187 -> V_292 )
return NULL ;
return F_99 ( & V_187 -> V_293 [ V_291 ] . V_72 ) ;
}
static int F_100 ( struct V_260 * V_72 )
{
struct V_203 * V_204 = F_84 ( V_72 ) ;
struct V_186 * V_187 = V_204 -> V_5 ;
unsigned long V_189 ;
F_54 ( & V_204 -> V_197 , V_189 ) ;
F_101 ( V_72 ) ;
V_204 -> V_269 = false ;
V_204 -> V_266 = F_66 ( V_187 ) ;
if ( ! V_204 -> V_266 ) {
F_55 ( & V_204 -> V_197 , V_189 ) ;
return - V_200 ;
}
F_79 ( & V_204 -> V_208 , F_89 , ( unsigned long ) V_204 ) ;
F_55 ( & V_204 -> V_197 , V_189 ) ;
return 1 ;
}
static int F_102 ( struct V_260 * V_72 , enum V_294 V_295 , unsigned long V_38 )
{
struct V_203 * V_204 = F_84 ( V_72 ) ;
struct V_118 * V_4 ;
unsigned long V_189 ;
struct V_186 * V_187 = V_204 -> V_5 ;
struct V_296 * V_297 ;
F_103 ( V_298 ) ;
switch ( V_295 ) {
case V_299 :
F_54 ( & V_204 -> V_197 , V_189 ) ;
F_92 ( & V_187 -> V_197 ) ;
F_35 ( V_204 -> V_266 ) ;
F_93 ( & V_187 -> V_197 ) ;
V_204 -> V_266 -> V_3 [ 0 ] . V_4 = NULL ;
V_204 -> V_266 -> V_3 [ 1 ] . V_4 = NULL ;
V_204 -> V_266 -> V_126 = - 1 ;
F_88 (desc, &pch->submitted_list, node) {
V_4 -> V_206 = FREE ;
F_90 ( & V_4 -> V_264 ) ;
}
F_88 (desc, &pch->work_list , node) {
V_4 -> V_206 = FREE ;
F_90 ( & V_4 -> V_264 ) ;
}
F_88 (desc, &pch->completed_list , node) {
V_4 -> V_206 = FREE ;
F_90 ( & V_4 -> V_264 ) ;
}
F_104 ( & V_204 -> V_300 , & V_187 -> V_276 ) ;
F_104 ( & V_204 -> V_275 , & V_187 -> V_276 ) ;
F_104 ( & V_204 -> V_271 , & V_187 -> V_276 ) ;
F_55 ( & V_204 -> V_197 , V_189 ) ;
break;
case V_301 :
V_297 = (struct V_296 * ) V_38 ;
if ( V_297 -> V_302 == V_135 ) {
if ( V_297 -> V_155 )
V_204 -> V_303 = V_297 -> V_155 ;
if ( V_297 -> V_304 )
V_204 -> V_305 = F_105 ( V_297 -> V_304 ) ;
if ( V_297 -> V_306 )
V_204 -> V_307 = V_297 -> V_306 ;
} else if ( V_297 -> V_302 == V_136 ) {
if ( V_297 -> V_154 )
V_204 -> V_303 = V_297 -> V_154 ;
if ( V_297 -> V_308 )
V_204 -> V_305 = F_105 ( V_297 -> V_308 ) ;
if ( V_297 -> V_309 )
V_204 -> V_307 = V_297 -> V_309 ;
}
break;
default:
F_32 ( V_204 -> V_5 -> V_87 . V_88 , L_40 ) ;
return - V_310 ;
}
return 0 ;
}
static void F_106 ( struct V_260 * V_72 )
{
struct V_203 * V_204 = F_84 ( V_72 ) ;
unsigned long V_189 ;
F_83 ( & V_204 -> V_208 ) ;
F_54 ( & V_204 -> V_197 , V_189 ) ;
F_68 ( V_204 -> V_266 ) ;
V_204 -> V_266 = NULL ;
if ( V_204 -> V_269 )
F_104 ( & V_204 -> V_275 , & V_204 -> V_5 -> V_276 ) ;
F_55 ( & V_204 -> V_197 , V_189 ) ;
}
static enum V_311
F_107 ( struct V_260 * V_72 , T_6 V_267 ,
struct V_312 * V_313 )
{
return F_108 ( V_72 , V_267 , V_313 ) ;
}
static void F_109 ( struct V_260 * V_72 )
{
struct V_203 * V_204 = F_84 ( V_72 ) ;
unsigned long V_189 ;
F_54 ( & V_204 -> V_197 , V_189 ) ;
F_104 ( & V_204 -> V_300 , & V_204 -> V_275 ) ;
F_55 ( & V_204 -> V_197 , V_189 ) ;
F_89 ( ( unsigned long ) V_204 ) ;
}
static T_6 F_110 ( struct V_262 * V_263 )
{
struct V_118 * V_4 , * V_314 = F_86 ( V_263 ) ;
struct V_203 * V_204 = F_84 ( V_263 -> V_72 ) ;
T_6 V_267 ;
unsigned long V_189 ;
F_54 ( & V_204 -> V_197 , V_189 ) ;
while ( ! F_94 ( & V_314 -> V_270 ) ) {
V_4 = F_111 ( V_314 -> V_270 . V_315 , struct V_118 , V_270 ) ;
if ( V_204 -> V_269 ) {
V_4 -> V_264 . V_272 = V_314 -> V_264 . V_272 ;
V_4 -> V_264 . V_273 = V_314 -> V_264 . V_273 ;
}
F_112 ( & V_4 -> V_264 ) ;
F_91 ( & V_4 -> V_270 , & V_204 -> V_300 ) ;
}
V_267 = F_112 ( & V_314 -> V_264 ) ;
F_61 ( & V_314 -> V_270 , & V_204 -> V_300 ) ;
F_55 ( & V_204 -> V_197 , V_189 ) ;
return V_267 ;
}
static inline void F_113 ( struct V_118 * V_4 )
{
V_4 -> V_122 . V_184 = V_316 ;
V_4 -> V_122 . V_180 = V_317 ;
V_4 -> V_122 . V_182 = V_317 ;
V_4 -> V_264 . V_318 = F_110 ;
F_78 ( & V_4 -> V_270 ) ;
}
static int F_114 ( struct V_186 * V_187 , T_7 V_319 , int V_288 )
{
struct V_118 * V_4 ;
unsigned long V_189 ;
int V_210 ;
V_4 = F_115 ( V_288 , sizeof( * V_4 ) , V_319 ) ;
if ( ! V_4 )
return 0 ;
F_54 ( & V_187 -> V_320 , V_189 ) ;
for ( V_210 = 0 ; V_210 < V_288 ; V_210 ++ ) {
F_113 ( & V_4 [ V_210 ] ) ;
F_61 ( & V_4 [ V_210 ] . V_270 , & V_187 -> V_276 ) ;
}
F_55 ( & V_187 -> V_320 , V_189 ) ;
return V_288 ;
}
static struct V_118 * F_116 ( struct V_186 * V_187 )
{
struct V_118 * V_4 = NULL ;
unsigned long V_189 ;
F_54 ( & V_187 -> V_320 , V_189 ) ;
if ( ! F_94 ( & V_187 -> V_276 ) ) {
V_4 = F_111 ( V_187 -> V_276 . V_315 ,
struct V_118 , V_270 ) ;
F_117 ( & V_4 -> V_270 ) ;
V_4 -> V_206 = V_274 ;
V_4 -> V_264 . V_272 = NULL ;
}
F_55 ( & V_187 -> V_320 , V_189 ) ;
return V_4 ;
}
static struct V_118 * F_118 ( struct V_203 * V_204 )
{
struct V_186 * V_187 = V_204 -> V_5 ;
T_2 * V_278 = V_204 -> V_72 . V_283 ;
struct V_118 * V_4 ;
V_4 = F_116 ( V_187 ) ;
if ( ! V_4 ) {
if ( ! F_114 ( V_187 , V_321 , 1 ) )
return NULL ;
V_4 = F_116 ( V_187 ) ;
if ( ! V_4 ) {
F_32 ( V_204 -> V_5 -> V_87 . V_88 ,
L_41 , V_124 , __LINE__ ) ;
return NULL ;
}
}
V_4 -> V_205 = V_204 ;
V_4 -> V_264 . V_267 = 0 ;
F_119 ( & V_4 -> V_264 ) ;
V_4 -> V_22 = V_278 ? V_204 -> V_72 . V_291 : 0 ;
V_4 -> V_122 . V_7 = & V_204 -> V_5 -> V_7 ;
F_120 ( & V_4 -> V_264 , & V_204 -> V_72 ) ;
return V_4 ;
}
static inline void F_121 ( struct V_148 * V_150 ,
T_8 V_46 , T_8 V_322 , T_9 V_323 )
{
V_150 -> V_153 = V_323 ;
V_150 -> V_155 = V_46 ;
V_150 -> V_154 = V_322 ;
}
static struct V_118 *
F_122 ( struct V_203 * V_204 , T_8 V_46 ,
T_8 V_322 , T_9 V_323 )
{
struct V_118 * V_4 = F_118 ( V_204 ) ;
if ( ! V_4 ) {
F_32 ( V_204 -> V_5 -> V_87 . V_88 , L_42 ,
V_124 , __LINE__ ) ;
return NULL ;
}
F_121 ( & V_4 -> V_150 , V_46 , V_322 , V_323 ) ;
return V_4 ;
}
static inline int F_123 ( struct V_118 * V_4 , T_9 V_323 )
{
struct V_203 * V_204 = V_4 -> V_205 ;
struct V_186 * V_187 = V_204 -> V_5 ;
int V_307 ;
V_307 = V_187 -> V_7 . V_237 / 8 ;
V_307 *= V_187 -> V_7 . V_240 ;
V_307 >>= V_4 -> V_122 . V_177 ;
if ( V_307 > 16 )
V_307 = 16 ;
while ( V_307 > 1 ) {
if ( ! ( V_323 % ( V_307 << V_4 -> V_122 . V_177 ) ) )
break;
V_307 -- ;
}
return V_307 ;
}
static struct V_262 * F_124 (
struct V_260 * V_72 , T_8 V_324 , T_9 V_323 ,
T_9 V_325 , enum V_326 V_302 ,
unsigned long V_189 )
{
struct V_118 * V_4 = NULL , * V_327 = NULL ;
struct V_203 * V_204 = F_84 ( V_72 ) ;
struct V_186 * V_187 = V_204 -> V_5 ;
unsigned int V_210 ;
T_8 V_46 ;
T_8 V_322 ;
if ( V_323 % V_325 != 0 )
return NULL ;
if ( ! F_125 ( V_302 ) ) {
F_32 ( V_204 -> V_5 -> V_87 . V_88 , L_43 ,
V_124 , __LINE__ ) ;
return NULL ;
}
for ( V_210 = 0 ; V_210 < V_323 / V_325 ; V_210 ++ ) {
V_4 = F_118 ( V_204 ) ;
if ( ! V_4 ) {
F_32 ( V_204 -> V_5 -> V_87 . V_88 , L_42 ,
V_124 , __LINE__ ) ;
if ( ! V_327 )
return NULL ;
F_54 ( & V_187 -> V_320 , V_189 ) ;
while ( ! F_94 ( & V_327 -> V_270 ) ) {
V_4 = F_111 ( V_327 -> V_270 . V_315 ,
struct V_118 , V_270 ) ;
F_91 ( & V_4 -> V_270 , & V_187 -> V_276 ) ;
}
F_91 ( & V_327 -> V_270 , & V_187 -> V_276 ) ;
F_55 ( & V_187 -> V_320 , V_189 ) ;
return NULL ;
}
switch ( V_302 ) {
case V_135 :
V_4 -> V_122 . V_162 = 1 ;
V_4 -> V_122 . V_164 = 0 ;
V_322 = V_324 ;
V_46 = V_204 -> V_303 ;
break;
case V_136 :
V_4 -> V_122 . V_162 = 0 ;
V_4 -> V_122 . V_164 = 1 ;
V_322 = V_204 -> V_303 ;
V_46 = V_324 ;
break;
default:
break;
}
V_4 -> V_134 = V_302 ;
V_4 -> V_122 . V_177 = V_204 -> V_305 ;
V_4 -> V_122 . V_174 = 1 ;
F_121 ( & V_4 -> V_150 , V_46 , V_322 , V_325 ) ;
if ( ! V_327 )
V_327 = V_4 ;
else
F_61 ( & V_4 -> V_270 , & V_327 -> V_270 ) ;
V_324 += V_325 ;
}
if ( ! V_4 )
return NULL ;
V_204 -> V_269 = true ;
V_4 -> V_264 . V_189 = V_189 ;
return & V_4 -> V_264 ;
}
static struct V_262 *
F_126 ( struct V_260 * V_72 , T_8 V_46 ,
T_8 V_322 , T_9 V_323 , unsigned long V_189 )
{
struct V_118 * V_4 ;
struct V_203 * V_204 = F_84 ( V_72 ) ;
struct V_186 * V_187 = V_204 -> V_5 ;
int V_328 ;
if ( F_127 ( ! V_204 || ! V_323 ) )
return NULL ;
V_4 = F_122 ( V_204 , V_46 , V_322 , V_323 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_122 . V_162 = 1 ;
V_4 -> V_122 . V_164 = 1 ;
V_4 -> V_134 = V_137 ;
V_328 = V_187 -> V_7 . V_237 / 8 ;
while ( V_328 > 1 ) {
if ( ! ( V_323 % V_328 ) )
break;
V_328 /= 2 ;
}
V_4 -> V_122 . V_177 = 0 ;
while ( V_328 != ( 1 << V_4 -> V_122 . V_177 ) )
V_4 -> V_122 . V_177 ++ ;
V_4 -> V_122 . V_174 = F_123 ( V_4 , V_323 ) ;
V_4 -> V_264 . V_189 = V_189 ;
return & V_4 -> V_264 ;
}
static void F_128 ( struct V_186 * V_187 ,
struct V_118 * V_327 )
{
unsigned long V_189 ;
struct V_118 * V_4 ;
if ( ! V_327 )
return;
F_54 ( & V_187 -> V_320 , V_189 ) ;
while ( ! F_94 ( & V_327 -> V_270 ) ) {
V_4 = F_111 ( V_327 -> V_270 . V_315 ,
struct V_118 , V_270 ) ;
F_91 ( & V_4 -> V_270 , & V_187 -> V_276 ) ;
}
F_91 ( & V_327 -> V_270 , & V_187 -> V_276 ) ;
F_55 ( & V_187 -> V_320 , V_189 ) ;
}
static struct V_262 *
F_129 ( struct V_260 * V_72 , struct V_329 * V_330 ,
unsigned int V_331 , enum V_326 V_302 ,
unsigned long V_319 , void * V_332 )
{
struct V_118 * V_327 , * V_4 = NULL ;
struct V_203 * V_204 = F_84 ( V_72 ) ;
struct V_329 * V_333 ;
int V_210 ;
T_8 V_73 ;
if ( F_127 ( ! V_204 || ! V_330 || ! V_331 ) )
return NULL ;
V_73 = V_204 -> V_303 ;
V_327 = NULL ;
F_130 (sgl, sg, sg_len, i) {
V_4 = F_118 ( V_204 ) ;
if ( ! V_4 ) {
struct V_186 * V_187 = V_204 -> V_5 ;
F_32 ( V_204 -> V_5 -> V_87 . V_88 ,
L_42 ,
V_124 , __LINE__ ) ;
F_128 ( V_187 , V_327 ) ;
return NULL ;
}
if ( ! V_327 )
V_327 = V_4 ;
else
F_61 ( & V_4 -> V_270 , & V_327 -> V_270 ) ;
if ( V_302 == V_135 ) {
V_4 -> V_122 . V_162 = 1 ;
V_4 -> V_122 . V_164 = 0 ;
F_121 ( & V_4 -> V_150 ,
V_73 , F_131 ( V_333 ) , F_132 ( V_333 ) ) ;
} else {
V_4 -> V_122 . V_162 = 0 ;
V_4 -> V_122 . V_164 = 1 ;
F_121 ( & V_4 -> V_150 ,
F_131 ( V_333 ) , V_73 , F_132 ( V_333 ) ) ;
}
V_4 -> V_122 . V_177 = V_204 -> V_305 ;
V_4 -> V_122 . V_174 = 1 ;
V_4 -> V_134 = V_302 ;
}
V_4 -> V_264 . V_189 = V_319 ;
return & V_4 -> V_264 ;
}
static T_10 F_133 ( int V_334 , void * V_209 )
{
if ( F_59 ( V_209 ) )
return V_335 ;
else
return V_336 ;
}
static int F_134 ( struct V_260 * V_337 ,
struct V_338 * V_339 )
{
V_339 -> V_340 = V_341 ;
V_339 -> V_342 = V_341 ;
V_339 -> V_343 = F_135 ( V_136 ) | F_135 ( V_135 ) ;
V_339 -> V_344 = false ;
V_339 -> V_345 = true ;
V_339 -> V_346 = V_347 ;
return 0 ;
}
static int
F_136 ( struct V_348 * V_349 , const struct V_350 * V_84 )
{
struct V_351 * V_352 ;
struct V_131 * V_7 ;
struct V_186 * V_187 ;
struct V_203 * V_204 , * V_353 ;
struct V_354 * V_355 ;
struct V_356 * V_357 ;
int V_210 , V_190 , V_334 ;
int V_213 ;
V_352 = F_137 ( & V_349 -> V_88 ) ;
V_190 = F_138 ( & V_349 -> V_88 , F_139 ( 32 ) ) ;
if ( V_190 )
return V_190 ;
V_187 = F_140 ( & V_349 -> V_88 , sizeof( * V_187 ) , V_255 ) ;
if ( ! V_187 ) {
F_32 ( & V_349 -> V_88 , L_44 ) ;
return - V_200 ;
}
V_187 -> V_199 = V_352 ? V_352 -> V_358 : 0 ;
V_357 = & V_349 -> V_357 ;
V_187 -> V_78 = F_141 ( & V_349 -> V_88 , V_357 ) ;
if ( F_142 ( V_187 -> V_78 ) )
return F_143 ( V_187 -> V_78 ) ;
F_144 ( V_349 , V_187 ) ;
for ( V_210 = 0 ; V_210 < V_359 ; V_210 ++ ) {
V_334 = V_349 -> V_334 [ V_210 ] ;
if ( V_334 ) {
V_190 = F_145 ( & V_349 -> V_88 , V_334 ,
F_133 , 0 ,
F_146 ( & V_349 -> V_88 ) , V_187 ) ;
if ( V_190 )
return V_190 ;
} else {
break;
}
}
V_7 = & V_187 -> V_7 ;
V_7 -> V_10 = V_349 -> V_360 ;
V_190 = F_76 ( V_187 ) ;
if ( V_190 )
return V_190 ;
F_78 ( & V_187 -> V_276 ) ;
F_77 ( & V_187 -> V_320 ) ;
if ( ! F_114 ( V_187 , V_255 , V_361 ) )
F_147 ( & V_349 -> V_88 , L_45 ) ;
V_355 = & V_187 -> V_87 ;
F_78 ( & V_355 -> V_214 ) ;
if ( V_352 )
V_213 = F_148 ( int , V_352 -> V_362 , V_7 -> V_213 ) ;
else
V_213 = F_148 ( int , V_7 -> V_196 , V_7 -> V_213 ) ;
V_187 -> V_292 = V_213 ;
V_187 -> V_293 = F_72 ( V_213 * sizeof( * V_204 ) , V_255 ) ;
if ( ! V_187 -> V_293 ) {
V_190 = - V_200 ;
F_32 ( & V_349 -> V_88 , L_46 ) ;
goto V_363;
}
for ( V_210 = 0 ; V_210 < V_213 ; V_210 ++ ) {
V_204 = & V_187 -> V_293 [ V_210 ] ;
if ( ! V_349 -> V_88 . V_364 )
V_204 -> V_72 . V_283 = V_352 ? & V_352 -> V_278 [ V_210 ] : NULL ;
else
V_204 -> V_72 . V_283 = V_349 -> V_88 . V_364 ;
F_78 ( & V_204 -> V_300 ) ;
F_78 ( & V_204 -> V_275 ) ;
F_78 ( & V_204 -> V_271 ) ;
F_77 ( & V_204 -> V_197 ) ;
V_204 -> V_266 = NULL ;
V_204 -> V_72 . V_279 = V_355 ;
V_204 -> V_5 = V_187 ;
F_61 ( & V_204 -> V_72 . V_365 , & V_355 -> V_214 ) ;
}
V_355 -> V_88 = & V_349 -> V_88 ;
if ( V_352 ) {
V_355 -> V_366 = V_352 -> V_366 ;
} else {
F_149 ( V_367 , V_355 -> V_366 ) ;
if ( V_7 -> V_196 ) {
F_149 ( V_368 , V_355 -> V_366 ) ;
F_149 ( V_369 , V_355 -> V_366 ) ;
F_149 ( V_370 , V_355 -> V_366 ) ;
}
}
V_355 -> V_371 = F_100 ;
V_355 -> V_372 = F_106 ;
V_355 -> V_373 = F_126 ;
V_355 -> V_374 = F_124 ;
V_355 -> V_375 = F_107 ;
V_355 -> V_376 = F_129 ;
V_355 -> V_377 = F_102 ;
V_355 -> V_378 = F_109 ;
V_355 -> V_379 = F_134 ;
V_190 = F_150 ( V_355 ) ;
if ( V_190 ) {
F_32 ( & V_349 -> V_88 , L_47 ) ;
goto V_380;
}
if ( V_349 -> V_88 . V_364 ) {
V_190 = F_151 ( V_349 -> V_88 . V_364 ,
F_98 , V_187 ) ;
if ( V_190 ) {
F_32 ( & V_349 -> V_88 ,
L_48 ) ;
}
}
V_349 -> V_88 . V_381 = & V_187 -> V_381 ;
V_190 = F_152 ( & V_349 -> V_88 , 1900800 ) ;
if ( V_190 )
F_32 ( & V_349 -> V_88 , L_49 ) ;
F_38 ( & V_349 -> V_88 ,
L_50 , V_349 -> V_360 ) ;
F_38 ( & V_349 -> V_88 ,
L_51 ,
V_7 -> V_240 , V_7 -> V_237 / 8 , V_7 -> V_213 ,
V_7 -> V_196 , V_7 -> V_222 ) ;
return 0 ;
V_380:
F_62 (pch, _p, &pl330->ddma.channels,
chan.device_node) {
F_63 ( & V_204 -> V_72 . V_365 ) ;
F_102 ( & V_204 -> V_72 , V_299 , 0 ) ;
F_106 ( & V_204 -> V_72 ) ;
}
V_363:
F_82 ( V_187 ) ;
return V_190 ;
}
static int F_153 ( struct V_348 * V_349 )
{
struct V_186 * V_187 = F_154 ( V_349 ) ;
struct V_203 * V_204 , * V_353 ;
if ( V_349 -> V_88 . V_364 )
F_155 ( V_349 -> V_88 . V_364 ) ;
F_156 ( & V_187 -> V_87 ) ;
F_62 (pch, _p, &pl330->ddma.channels,
chan.device_node) {
F_63 ( & V_204 -> V_72 . V_365 ) ;
F_102 ( & V_204 -> V_72 , V_299 , 0 ) ;
F_106 ( & V_204 -> V_72 ) ;
}
F_82 ( V_187 ) ;
return 0 ;
}
