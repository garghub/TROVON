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
if ( V_120 == V_2 -> V_122 )
return true ;
V_4 = V_3 -> V_4 ;
V_74 = V_4 -> V_123 . V_124 ? 1 : 0 ;
if ( F_4 ( V_2 ) && ! V_74 )
F_38 ( V_2 -> V_5 -> V_87 . V_88 , L_28 ,
V_125 , __LINE__ ) ;
V_119 . V_72 = V_2 -> V_84 ;
V_119 . V_73 = V_3 -> V_126 ;
V_119 . V_74 = V_74 ;
F_25 ( 0 , V_82 , & V_119 ) ;
F_31 ( F_28 ( V_77 + V_116 ) | ( 1 << V_2 -> V_55 ) , V_77 + V_116 ) ;
F_30 ( V_2 , V_82 , true ) ;
V_2 -> V_122 = V_120 ;
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
struct V_131 * V_7 = V_128 -> V_4 -> V_123 . V_7 ;
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
F_49 ( V_3 -> V_126 ) ;
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
if ( V_161 -> V_124 )
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
unsigned V_120 ;
T_1 V_151 ;
int V_190 = 0 ;
if ( V_187 -> V_191 == V_192
|| V_187 -> V_193 . V_194 & ( 1 << V_2 -> V_84 ) ) {
F_38 ( V_2 -> V_5 -> V_87 . V_88 , L_29 ,
V_125 , __LINE__ ) ;
return - V_195 ;
}
if ( V_4 -> V_134 != V_137 &&
V_4 -> V_22 >= V_187 -> V_7 . V_196 ) {
F_38 ( V_2 -> V_5 -> V_87 . V_88 ,
L_30 ,
V_125 , __LINE__ , V_4 -> V_22 ) ;
return - V_159 ;
}
F_54 ( & V_187 -> V_197 , V_189 ) ;
if ( F_2 ( V_2 ) ) {
V_190 = - V_195 ;
goto V_198;
}
if ( ! F_4 ( V_2 ) )
V_4 -> V_123 . V_124 = 0 ;
else
V_4 -> V_123 . V_124 = 1 ;
V_151 = F_52 ( & V_4 -> V_123 ) ;
V_120 = V_2 -> V_3 [ 0 ] . V_4 == NULL ? 0 : 1 ;
V_188 . V_151 = V_151 ;
V_188 . V_4 = V_4 ;
V_190 = F_48 ( 1 , V_2 , V_120 , & V_188 ) ;
if ( V_190 < 0 )
goto V_198;
if ( V_190 > V_187 -> V_199 / 2 ) {
F_38 ( V_187 -> V_87 . V_88 , L_31 ,
V_125 , __LINE__ ) ;
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
V_2 -> V_122 = - 1 ;
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
F_32 ( V_187 -> V_87 . V_88 , L_33 , V_125 ,
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
V_225 = V_2 -> V_122 ;
if ( V_225 == - 1 )
continue;
V_218 = V_2 -> V_3 [ V_225 ] . V_4 ;
V_2 -> V_3 [ V_225 ] . V_4 = NULL ;
V_2 -> V_122 = - 1 ;
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
V_2 -> V_122 = - 1 ;
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
V_2 -> V_3 [ 0 ] . V_126 = V_187 -> V_254
+ ( V_2 -> V_84 * V_187 -> V_199 ) ;
V_2 -> V_3 [ 0 ] . V_4 = NULL ;
V_2 -> V_3 [ 1 ] . V_157 = V_2 -> V_3 [ 0 ] . V_157
+ V_187 -> V_199 / 2 ;
V_2 -> V_3 [ 1 ] . V_126 = V_2 -> V_3 [ 0 ] . V_126
+ V_187 -> V_199 / 2 ;
V_2 -> V_3 [ 1 ] . V_4 = NULL ;
V_2 -> V_122 = - 1 ;
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
V_125 , __LINE__ ) ;
return - V_200 ;
}
V_190 = F_71 ( V_187 ) ;
if ( V_190 ) {
F_32 ( V_187 -> V_87 . V_88 , L_35 ,
V_125 , __LINE__ ) ;
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
V_125 , __LINE__ ) ;
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
V_125 , __LINE__ , V_4 -> V_264 . V_267 ) ;
F_57 ( & V_204 -> V_208 ) ;
}
}
}
static void F_89 ( unsigned long V_209 )
{
struct V_203 * V_204 = (struct V_203 * ) V_209 ;
struct V_118 * V_4 , * V_268 ;
unsigned long V_189 ;
bool V_269 = false ;
F_54 ( & V_204 -> V_197 , V_189 ) ;
F_62 (desc, _dt, &pch->work_list, node)
if ( V_4 -> V_206 == V_207 ) {
if ( ! V_204 -> V_270 )
F_90 ( & V_4 -> V_264 ) ;
F_91 ( & V_4 -> V_271 , & V_204 -> V_272 ) ;
}
F_87 ( V_204 ) ;
if ( F_92 ( & V_204 -> V_273 ) ) {
F_93 ( & V_204 -> V_266 -> V_5 -> V_197 ) ;
F_35 ( V_204 -> V_266 ) ;
F_94 ( & V_204 -> V_266 -> V_5 -> V_197 ) ;
V_269 = true ;
} else {
F_93 ( & V_204 -> V_266 -> V_5 -> V_197 ) ;
F_39 ( V_204 -> V_266 ) ;
F_94 ( & V_204 -> V_266 -> V_5 -> V_197 ) ;
}
while ( ! F_92 ( & V_204 -> V_272 ) ) {
T_5 V_274 ;
void * V_275 ;
V_4 = F_95 ( & V_204 -> V_272 ,
struct V_118 , V_271 ) ;
V_274 = V_4 -> V_264 . V_274 ;
V_275 = V_4 -> V_264 . V_275 ;
if ( V_204 -> V_270 ) {
V_4 -> V_206 = V_276 ;
F_91 ( & V_4 -> V_271 , & V_204 -> V_273 ) ;
if ( V_269 ) {
F_93 ( & V_204 -> V_266 -> V_5 -> V_197 ) ;
F_39 ( V_204 -> V_266 ) ;
F_94 ( & V_204 -> V_266 -> V_5 -> V_197 ) ;
V_269 = false ;
}
} else {
V_4 -> V_206 = FREE ;
F_91 ( & V_4 -> V_271 , & V_204 -> V_5 -> V_277 ) ;
}
F_96 ( & V_4 -> V_264 ) ;
if ( V_274 ) {
F_55 ( & V_204 -> V_197 , V_189 ) ;
V_274 ( V_275 ) ;
F_54 ( & V_204 -> V_197 , V_189 ) ;
}
}
F_55 ( & V_204 -> V_197 , V_189 ) ;
if ( V_269 ) {
F_97 ( V_204 -> V_5 -> V_87 . V_88 ) ;
F_98 ( V_204 -> V_5 -> V_87 . V_88 ) ;
}
}
bool F_99 ( struct V_260 * V_72 , void * V_278 )
{
T_2 * V_279 ;
if ( V_72 -> V_280 -> V_88 -> V_281 != & V_282 . V_283 )
return false ;
V_279 = V_72 -> V_284 ;
return * V_279 == ( unsigned long ) V_278 ;
}
static struct V_260 * F_100 ( struct V_285 * V_286 ,
struct V_287 * V_288 )
{
int V_289 = V_286 -> V_290 ;
struct V_186 * V_187 = V_288 -> V_291 ;
unsigned int V_292 ;
if ( ! V_187 )
return NULL ;
if ( V_289 != 1 )
return NULL ;
V_292 = V_286 -> args [ 0 ] ;
if ( V_292 >= V_187 -> V_293 )
return NULL ;
return F_101 ( & V_187 -> V_294 [ V_292 ] . V_72 ) ;
}
static int F_102 ( struct V_260 * V_72 )
{
struct V_203 * V_204 = F_84 ( V_72 ) ;
struct V_186 * V_187 = V_204 -> V_5 ;
unsigned long V_189 ;
F_54 ( & V_204 -> V_197 , V_189 ) ;
F_103 ( V_72 ) ;
V_204 -> V_270 = false ;
V_204 -> V_266 = F_66 ( V_187 ) ;
if ( ! V_204 -> V_266 ) {
F_55 ( & V_204 -> V_197 , V_189 ) ;
return - V_200 ;
}
F_79 ( & V_204 -> V_208 , F_89 , ( unsigned long ) V_204 ) ;
F_55 ( & V_204 -> V_197 , V_189 ) ;
return 1 ;
}
static int V_131 ( struct V_260 * V_72 ,
struct V_295 * V_296 )
{
struct V_203 * V_204 = F_84 ( V_72 ) ;
if ( V_296 -> V_297 == V_135 ) {
if ( V_296 -> V_155 )
V_204 -> V_298 = V_296 -> V_155 ;
if ( V_296 -> V_299 )
V_204 -> V_300 = F_104 ( V_296 -> V_299 ) ;
if ( V_296 -> V_301 )
V_204 -> V_302 = V_296 -> V_301 ;
} else if ( V_296 -> V_297 == V_136 ) {
if ( V_296 -> V_154 )
V_204 -> V_298 = V_296 -> V_154 ;
if ( V_296 -> V_303 )
V_204 -> V_300 = F_104 ( V_296 -> V_303 ) ;
if ( V_296 -> V_304 )
V_204 -> V_302 = V_296 -> V_304 ;
}
return 0 ;
}
static int F_105 ( struct V_260 * V_72 )
{
struct V_203 * V_204 = F_84 ( V_72 ) ;
struct V_118 * V_4 ;
unsigned long V_189 ;
struct V_186 * V_187 = V_204 -> V_5 ;
F_106 ( V_305 ) ;
F_54 ( & V_204 -> V_197 , V_189 ) ;
F_93 ( & V_187 -> V_197 ) ;
F_35 ( V_204 -> V_266 ) ;
F_94 ( & V_187 -> V_197 ) ;
V_204 -> V_266 -> V_3 [ 0 ] . V_4 = NULL ;
V_204 -> V_266 -> V_3 [ 1 ] . V_4 = NULL ;
V_204 -> V_266 -> V_122 = - 1 ;
F_88 (desc, &pch->submitted_list, node) {
V_4 -> V_206 = FREE ;
F_90 ( & V_4 -> V_264 ) ;
}
F_88 (desc, &pch->work_list , node) {
V_4 -> V_206 = FREE ;
F_90 ( & V_4 -> V_264 ) ;
}
F_107 ( & V_204 -> V_306 , & V_187 -> V_277 ) ;
F_107 ( & V_204 -> V_273 , & V_187 -> V_277 ) ;
F_107 ( & V_204 -> V_272 , & V_187 -> V_277 ) ;
F_55 ( & V_204 -> V_197 , V_189 ) ;
return 0 ;
}
int F_108 ( struct V_260 * V_72 )
{
struct V_203 * V_204 = F_84 ( V_72 ) ;
struct V_186 * V_187 = V_204 -> V_5 ;
unsigned long V_189 ;
F_109 ( V_187 -> V_87 . V_88 ) ;
F_54 ( & V_204 -> V_197 , V_189 ) ;
F_93 ( & V_187 -> V_197 ) ;
F_35 ( V_204 -> V_266 ) ;
F_94 ( & V_187 -> V_197 ) ;
F_55 ( & V_204 -> V_197 , V_189 ) ;
F_97 ( V_187 -> V_87 . V_88 ) ;
F_98 ( V_187 -> V_87 . V_88 ) ;
return 0 ;
}
static void F_110 ( struct V_260 * V_72 )
{
struct V_203 * V_204 = F_84 ( V_72 ) ;
unsigned long V_189 ;
F_83 ( & V_204 -> V_208 ) ;
F_109 ( V_204 -> V_5 -> V_87 . V_88 ) ;
F_54 ( & V_204 -> V_197 , V_189 ) ;
F_68 ( V_204 -> V_266 ) ;
V_204 -> V_266 = NULL ;
if ( V_204 -> V_270 )
F_107 ( & V_204 -> V_273 , & V_204 -> V_5 -> V_277 ) ;
F_55 ( & V_204 -> V_197 , V_189 ) ;
F_97 ( V_204 -> V_5 -> V_87 . V_88 ) ;
F_98 ( V_204 -> V_5 -> V_87 . V_88 ) ;
}
int F_111 ( struct V_203 * V_204 ,
struct V_118 * V_4 )
{
struct V_1 * V_2 = V_204 -> V_266 ;
struct V_186 * V_187 = V_204 -> V_5 ;
void T_4 * V_77 = V_2 -> V_5 -> V_78 ;
T_1 V_17 , V_73 ;
F_109 ( V_187 -> V_87 . V_88 ) ;
V_17 = V_73 = 0 ;
if ( V_4 -> V_123 . V_162 ) {
V_17 = F_28 ( V_77 + F_112 ( V_2 -> V_84 ) ) ;
V_73 = V_4 -> V_150 . V_154 ;
} else {
V_17 = F_28 ( V_77 + F_113 ( V_2 -> V_84 ) ) ;
V_73 = V_4 -> V_150 . V_155 ;
}
F_97 ( V_204 -> V_5 -> V_87 . V_88 ) ;
F_98 ( V_187 -> V_87 . V_88 ) ;
return V_17 - V_73 ;
}
static enum V_307
F_114 ( struct V_260 * V_72 , T_6 V_267 ,
struct V_308 * V_309 )
{
enum V_307 V_190 ;
unsigned long V_189 ;
struct V_118 * V_4 , * V_310 = NULL ;
struct V_203 * V_204 = F_84 ( V_72 ) ;
unsigned int V_311 , V_312 = 0 ;
V_190 = F_115 ( V_72 , V_267 , V_309 ) ;
if ( ! V_309 )
return V_190 ;
if ( V_190 == V_313 )
goto V_314;
F_54 ( & V_204 -> V_197 , V_189 ) ;
if ( V_204 -> V_266 -> V_122 != - 1 )
V_310 = V_204 -> V_266 -> V_3 [ V_204 -> V_266 -> V_122 ] . V_4 ;
F_88 (desc, &pch->work_list, node) {
if ( V_4 -> V_206 == V_207 )
V_311 = V_4 -> V_315 ;
else if ( V_310 && V_4 == V_310 )
V_311 =
F_111 ( V_204 , V_4 ) ;
else
V_311 = 0 ;
V_312 += V_4 -> V_315 - V_311 ;
if ( V_4 -> V_264 . V_267 == V_267 ) {
V_190 = V_4 -> V_206 ;
break;
}
if ( V_4 -> V_316 )
V_312 = 0 ;
}
F_55 ( & V_204 -> V_197 , V_189 ) ;
V_314:
F_116 ( V_309 , V_312 ) ;
return V_190 ;
}
static void F_117 ( struct V_260 * V_72 )
{
struct V_203 * V_204 = F_84 ( V_72 ) ;
unsigned long V_189 ;
F_54 ( & V_204 -> V_197 , V_189 ) ;
if ( F_92 ( & V_204 -> V_273 ) ) {
F_118 ( F_92 ( & V_204 -> V_306 ) ) ;
F_109 ( V_204 -> V_5 -> V_87 . V_88 ) ;
}
F_107 ( & V_204 -> V_306 , & V_204 -> V_273 ) ;
F_55 ( & V_204 -> V_197 , V_189 ) ;
F_89 ( ( unsigned long ) V_204 ) ;
}
static T_6 F_119 ( struct V_262 * V_263 )
{
struct V_118 * V_4 , * V_316 = F_86 ( V_263 ) ;
struct V_203 * V_204 = F_84 ( V_263 -> V_72 ) ;
T_6 V_267 ;
unsigned long V_189 ;
F_54 ( & V_204 -> V_197 , V_189 ) ;
while ( ! F_92 ( & V_316 -> V_271 ) ) {
V_4 = F_120 ( V_316 -> V_271 . V_317 , struct V_118 , V_271 ) ;
if ( V_204 -> V_270 ) {
V_4 -> V_264 . V_274 = V_316 -> V_264 . V_274 ;
V_4 -> V_264 . V_275 = V_316 -> V_264 . V_275 ;
}
V_316 -> V_316 = false ;
F_121 ( & V_4 -> V_264 ) ;
F_91 ( & V_4 -> V_271 , & V_204 -> V_306 ) ;
}
V_316 -> V_316 = true ;
V_267 = F_121 ( & V_316 -> V_264 ) ;
F_61 ( & V_316 -> V_271 , & V_204 -> V_306 ) ;
F_55 ( & V_204 -> V_197 , V_189 ) ;
return V_267 ;
}
static inline void F_122 ( struct V_118 * V_4 )
{
V_4 -> V_123 . V_184 = V_318 ;
V_4 -> V_123 . V_180 = V_319 ;
V_4 -> V_123 . V_182 = V_319 ;
V_4 -> V_264 . V_320 = F_119 ;
F_78 ( & V_4 -> V_271 ) ;
}
static int F_123 ( struct V_186 * V_187 , T_7 V_321 , int V_289 )
{
struct V_118 * V_4 ;
unsigned long V_189 ;
int V_210 ;
V_4 = F_124 ( V_289 , sizeof( * V_4 ) , V_321 ) ;
if ( ! V_4 )
return 0 ;
F_54 ( & V_187 -> V_322 , V_189 ) ;
for ( V_210 = 0 ; V_210 < V_289 ; V_210 ++ ) {
F_122 ( & V_4 [ V_210 ] ) ;
F_61 ( & V_4 [ V_210 ] . V_271 , & V_187 -> V_277 ) ;
}
F_55 ( & V_187 -> V_322 , V_189 ) ;
return V_289 ;
}
static struct V_118 * F_125 ( struct V_186 * V_187 )
{
struct V_118 * V_4 = NULL ;
unsigned long V_189 ;
F_54 ( & V_187 -> V_322 , V_189 ) ;
if ( ! F_92 ( & V_187 -> V_277 ) ) {
V_4 = F_120 ( V_187 -> V_277 . V_317 ,
struct V_118 , V_271 ) ;
F_126 ( & V_4 -> V_271 ) ;
V_4 -> V_206 = V_276 ;
V_4 -> V_264 . V_274 = NULL ;
}
F_55 ( & V_187 -> V_322 , V_189 ) ;
return V_4 ;
}
static struct V_118 * F_127 ( struct V_203 * V_204 )
{
struct V_186 * V_187 = V_204 -> V_5 ;
T_2 * V_279 = V_204 -> V_72 . V_284 ;
struct V_118 * V_4 ;
V_4 = F_125 ( V_187 ) ;
if ( ! V_4 ) {
if ( ! F_123 ( V_187 , V_323 , 1 ) )
return NULL ;
V_4 = F_125 ( V_187 ) ;
if ( ! V_4 ) {
F_32 ( V_204 -> V_5 -> V_87 . V_88 ,
L_40 , V_125 , __LINE__ ) ;
return NULL ;
}
}
V_4 -> V_205 = V_204 ;
V_4 -> V_264 . V_267 = 0 ;
F_128 ( & V_4 -> V_264 ) ;
V_4 -> V_22 = V_279 ? V_204 -> V_72 . V_292 : 0 ;
V_4 -> V_123 . V_7 = & V_204 -> V_5 -> V_7 ;
F_129 ( & V_4 -> V_264 , & V_204 -> V_72 ) ;
return V_4 ;
}
static inline void F_130 ( struct V_148 * V_150 ,
T_8 V_46 , T_8 V_324 , T_9 V_325 )
{
V_150 -> V_153 = V_325 ;
V_150 -> V_155 = V_46 ;
V_150 -> V_154 = V_324 ;
}
static struct V_118 *
F_131 ( struct V_203 * V_204 , T_8 V_46 ,
T_8 V_324 , T_9 V_325 )
{
struct V_118 * V_4 = F_127 ( V_204 ) ;
if ( ! V_4 ) {
F_32 ( V_204 -> V_5 -> V_87 . V_88 , L_41 ,
V_125 , __LINE__ ) ;
return NULL ;
}
F_130 ( & V_4 -> V_150 , V_46 , V_324 , V_325 ) ;
return V_4 ;
}
static inline int F_132 ( struct V_118 * V_4 , T_9 V_325 )
{
struct V_203 * V_204 = V_4 -> V_205 ;
struct V_186 * V_187 = V_204 -> V_5 ;
int V_302 ;
V_302 = V_187 -> V_7 . V_237 / 8 ;
V_302 *= V_187 -> V_7 . V_240 / V_187 -> V_7 . V_213 ;
V_302 >>= V_4 -> V_123 . V_177 ;
if ( V_302 > 16 )
V_302 = 16 ;
while ( V_302 > 1 ) {
if ( ! ( V_325 % ( V_302 << V_4 -> V_123 . V_177 ) ) )
break;
V_302 -- ;
}
return V_302 ;
}
static struct V_262 * F_133 (
struct V_260 * V_72 , T_8 V_326 , T_9 V_325 ,
T_9 V_327 , enum V_328 V_297 ,
unsigned long V_189 )
{
struct V_118 * V_4 = NULL , * V_329 = NULL ;
struct V_203 * V_204 = F_84 ( V_72 ) ;
struct V_186 * V_187 = V_204 -> V_5 ;
unsigned int V_210 ;
T_8 V_46 ;
T_8 V_324 ;
if ( V_325 % V_327 != 0 )
return NULL ;
if ( ! F_134 ( V_297 ) ) {
F_32 ( V_204 -> V_5 -> V_87 . V_88 , L_42 ,
V_125 , __LINE__ ) ;
return NULL ;
}
for ( V_210 = 0 ; V_210 < V_325 / V_327 ; V_210 ++ ) {
V_4 = F_127 ( V_204 ) ;
if ( ! V_4 ) {
F_32 ( V_204 -> V_5 -> V_87 . V_88 , L_41 ,
V_125 , __LINE__ ) ;
if ( ! V_329 )
return NULL ;
F_54 ( & V_187 -> V_322 , V_189 ) ;
while ( ! F_92 ( & V_329 -> V_271 ) ) {
V_4 = F_120 ( V_329 -> V_271 . V_317 ,
struct V_118 , V_271 ) ;
F_91 ( & V_4 -> V_271 , & V_187 -> V_277 ) ;
}
F_91 ( & V_329 -> V_271 , & V_187 -> V_277 ) ;
F_55 ( & V_187 -> V_322 , V_189 ) ;
return NULL ;
}
switch ( V_297 ) {
case V_135 :
V_4 -> V_123 . V_162 = 1 ;
V_4 -> V_123 . V_164 = 0 ;
V_324 = V_326 ;
V_46 = V_204 -> V_298 ;
break;
case V_136 :
V_4 -> V_123 . V_162 = 0 ;
V_4 -> V_123 . V_164 = 1 ;
V_324 = V_204 -> V_298 ;
V_46 = V_326 ;
break;
default:
break;
}
V_4 -> V_134 = V_297 ;
V_4 -> V_123 . V_177 = V_204 -> V_300 ;
V_4 -> V_123 . V_174 = 1 ;
V_4 -> V_315 = V_327 ;
F_130 ( & V_4 -> V_150 , V_46 , V_324 , V_327 ) ;
if ( ! V_329 )
V_329 = V_4 ;
else
F_61 ( & V_4 -> V_271 , & V_329 -> V_271 ) ;
V_326 += V_327 ;
}
if ( ! V_4 )
return NULL ;
V_204 -> V_270 = true ;
V_4 -> V_264 . V_189 = V_189 ;
return & V_4 -> V_264 ;
}
static struct V_262 *
F_135 ( struct V_260 * V_72 , T_8 V_46 ,
T_8 V_324 , T_9 V_325 , unsigned long V_189 )
{
struct V_118 * V_4 ;
struct V_203 * V_204 = F_84 ( V_72 ) ;
struct V_186 * V_187 = V_204 -> V_5 ;
int V_330 ;
if ( F_136 ( ! V_204 || ! V_325 ) )
return NULL ;
V_4 = F_131 ( V_204 , V_46 , V_324 , V_325 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_123 . V_162 = 1 ;
V_4 -> V_123 . V_164 = 1 ;
V_4 -> V_134 = V_137 ;
V_330 = V_187 -> V_7 . V_237 / 8 ;
while ( ( V_324 | V_46 | V_325 ) & ( V_330 - 1 ) )
V_330 /= 2 ;
V_4 -> V_123 . V_177 = 0 ;
while ( V_330 != ( 1 << V_4 -> V_123 . V_177 ) )
V_4 -> V_123 . V_177 ++ ;
if ( V_4 -> V_123 . V_177 * 8 < V_187 -> V_7 . V_237 )
V_4 -> V_123 . V_174 = 1 ;
V_4 -> V_123 . V_174 = F_132 ( V_4 , V_325 ) ;
V_4 -> V_264 . V_189 = V_189 ;
return & V_4 -> V_264 ;
}
static void F_137 ( struct V_186 * V_187 ,
struct V_118 * V_329 )
{
unsigned long V_189 ;
struct V_118 * V_4 ;
if ( ! V_329 )
return;
F_54 ( & V_187 -> V_322 , V_189 ) ;
while ( ! F_92 ( & V_329 -> V_271 ) ) {
V_4 = F_120 ( V_329 -> V_271 . V_317 ,
struct V_118 , V_271 ) ;
F_91 ( & V_4 -> V_271 , & V_187 -> V_277 ) ;
}
F_91 ( & V_329 -> V_271 , & V_187 -> V_277 ) ;
F_55 ( & V_187 -> V_322 , V_189 ) ;
}
static struct V_262 *
F_138 ( struct V_260 * V_72 , struct V_331 * V_332 ,
unsigned int V_333 , enum V_328 V_297 ,
unsigned long V_321 , void * V_334 )
{
struct V_118 * V_329 , * V_4 = NULL ;
struct V_203 * V_204 = F_84 ( V_72 ) ;
struct V_331 * V_335 ;
int V_210 ;
T_8 V_73 ;
if ( F_136 ( ! V_204 || ! V_332 || ! V_333 ) )
return NULL ;
V_73 = V_204 -> V_298 ;
V_329 = NULL ;
F_139 (sgl, sg, sg_len, i) {
V_4 = F_127 ( V_204 ) ;
if ( ! V_4 ) {
struct V_186 * V_187 = V_204 -> V_5 ;
F_32 ( V_204 -> V_5 -> V_87 . V_88 ,
L_41 ,
V_125 , __LINE__ ) ;
F_137 ( V_187 , V_329 ) ;
return NULL ;
}
if ( ! V_329 )
V_329 = V_4 ;
else
F_61 ( & V_4 -> V_271 , & V_329 -> V_271 ) ;
if ( V_297 == V_135 ) {
V_4 -> V_123 . V_162 = 1 ;
V_4 -> V_123 . V_164 = 0 ;
F_130 ( & V_4 -> V_150 ,
V_73 , F_140 ( V_335 ) , F_141 ( V_335 ) ) ;
} else {
V_4 -> V_123 . V_162 = 0 ;
V_4 -> V_123 . V_164 = 1 ;
F_130 ( & V_4 -> V_150 ,
F_140 ( V_335 ) , V_73 , F_141 ( V_335 ) ) ;
}
V_4 -> V_123 . V_177 = V_204 -> V_300 ;
V_4 -> V_123 . V_174 = 1 ;
V_4 -> V_134 = V_297 ;
V_4 -> V_315 = F_141 ( V_335 ) ;
}
V_4 -> V_264 . V_189 = V_321 ;
return & V_4 -> V_264 ;
}
static T_10 F_142 ( int V_336 , void * V_209 )
{
if ( F_59 ( V_209 ) )
return V_337 ;
else
return V_338 ;
}
static int T_11 F_143 ( struct V_280 * V_88 )
{
struct V_339 * V_340 = F_144 ( V_88 ) ;
F_145 ( V_88 ) ;
if ( ! F_146 ( V_88 ) ) {
F_147 ( V_340 ) ;
}
F_148 ( V_340 ) ;
return 0 ;
}
static int T_11 F_149 ( struct V_280 * V_88 )
{
struct V_339 * V_340 = F_144 ( V_88 ) ;
int V_190 ;
V_190 = F_150 ( V_340 ) ;
if ( V_190 )
return V_190 ;
if ( ! F_146 ( V_88 ) )
V_190 = F_151 ( V_340 ) ;
F_152 ( V_88 ) ;
return V_190 ;
}
static int
F_153 ( struct V_339 * V_341 , const struct V_342 * V_84 )
{
struct V_343 * V_344 ;
struct V_131 * V_7 ;
struct V_186 * V_187 ;
struct V_203 * V_204 , * V_345 ;
struct V_346 * V_347 ;
struct V_348 * V_349 ;
int V_210 , V_190 , V_336 ;
int V_213 ;
V_344 = F_154 ( & V_341 -> V_88 ) ;
V_190 = F_155 ( & V_341 -> V_88 , F_156 ( 32 ) ) ;
if ( V_190 )
return V_190 ;
V_187 = F_157 ( & V_341 -> V_88 , sizeof( * V_187 ) , V_255 ) ;
if ( ! V_187 ) {
F_32 ( & V_341 -> V_88 , L_43 ) ;
return - V_200 ;
}
V_347 = & V_187 -> V_87 ;
V_347 -> V_88 = & V_341 -> V_88 ;
V_187 -> V_199 = V_344 ? V_344 -> V_350 : 0 ;
V_349 = & V_341 -> V_349 ;
V_187 -> V_78 = F_158 ( & V_341 -> V_88 , V_349 ) ;
if ( F_159 ( V_187 -> V_78 ) )
return F_160 ( V_187 -> V_78 ) ;
F_161 ( V_341 , V_187 ) ;
for ( V_210 = 0 ; V_210 < V_351 ; V_210 ++ ) {
V_336 = V_341 -> V_336 [ V_210 ] ;
if ( V_336 ) {
V_190 = F_162 ( & V_341 -> V_88 , V_336 ,
F_142 , 0 ,
F_163 ( & V_341 -> V_88 ) , V_187 ) ;
if ( V_190 )
return V_190 ;
} else {
break;
}
}
V_7 = & V_187 -> V_7 ;
V_7 -> V_10 = V_341 -> V_352 ;
V_190 = F_76 ( V_187 ) ;
if ( V_190 )
return V_190 ;
F_78 ( & V_187 -> V_277 ) ;
F_77 ( & V_187 -> V_322 ) ;
if ( ! F_123 ( V_187 , V_255 , V_353 ) )
F_164 ( & V_341 -> V_88 , L_44 ) ;
F_78 ( & V_347 -> V_214 ) ;
if ( V_344 )
V_213 = F_165 ( int , V_344 -> V_354 , V_7 -> V_213 ) ;
else
V_213 = F_165 ( int , V_7 -> V_196 , V_7 -> V_213 ) ;
V_187 -> V_293 = V_213 ;
V_187 -> V_294 = F_72 ( V_213 * sizeof( * V_204 ) , V_255 ) ;
if ( ! V_187 -> V_294 ) {
V_190 = - V_200 ;
F_32 ( & V_341 -> V_88 , L_45 ) ;
goto V_355;
}
for ( V_210 = 0 ; V_210 < V_213 ; V_210 ++ ) {
V_204 = & V_187 -> V_294 [ V_210 ] ;
if ( ! V_341 -> V_88 . V_356 )
V_204 -> V_72 . V_284 = V_344 ? & V_344 -> V_279 [ V_210 ] : NULL ;
else
V_204 -> V_72 . V_284 = V_341 -> V_88 . V_356 ;
F_78 ( & V_204 -> V_306 ) ;
F_78 ( & V_204 -> V_273 ) ;
F_78 ( & V_204 -> V_272 ) ;
F_77 ( & V_204 -> V_197 ) ;
V_204 -> V_266 = NULL ;
V_204 -> V_72 . V_280 = V_347 ;
V_204 -> V_5 = V_187 ;
F_61 ( & V_204 -> V_72 . V_357 , & V_347 -> V_214 ) ;
}
if ( V_344 ) {
V_347 -> V_358 = V_344 -> V_358 ;
} else {
F_166 ( V_359 , V_347 -> V_358 ) ;
if ( V_7 -> V_196 ) {
F_166 ( V_360 , V_347 -> V_358 ) ;
F_166 ( V_361 , V_347 -> V_358 ) ;
F_166 ( V_362 , V_347 -> V_358 ) ;
}
}
V_347 -> V_363 = F_102 ;
V_347 -> V_364 = F_110 ;
V_347 -> V_365 = F_135 ;
V_347 -> V_366 = F_133 ;
V_347 -> V_367 = F_114 ;
V_347 -> V_368 = F_138 ;
V_347 -> V_369 = V_131 ;
V_347 -> V_370 = F_108 ;
V_347 -> V_371 = F_105 ;
V_347 -> V_372 = F_117 ;
V_347 -> V_373 = V_374 ;
V_347 -> V_375 = V_374 ;
V_347 -> V_376 = F_167 ( V_136 ) | F_167 ( V_135 ) ;
V_347 -> V_377 = V_378 ;
V_190 = F_168 ( V_347 ) ;
if ( V_190 ) {
F_32 ( & V_341 -> V_88 , L_46 ) ;
goto V_379;
}
if ( V_341 -> V_88 . V_356 ) {
V_190 = F_169 ( V_341 -> V_88 . V_356 ,
F_100 , V_187 ) ;
if ( V_190 ) {
F_32 ( & V_341 -> V_88 ,
L_47 ) ;
}
}
V_341 -> V_88 . V_380 = & V_187 -> V_380 ;
V_190 = F_170 ( & V_341 -> V_88 , 1900800 ) ;
if ( V_190 )
F_32 ( & V_341 -> V_88 , L_48 ) ;
F_38 ( & V_341 -> V_88 ,
L_49 , V_341 -> V_352 ) ;
F_38 ( & V_341 -> V_88 ,
L_50 ,
V_7 -> V_240 , V_7 -> V_237 / 8 , V_7 -> V_213 ,
V_7 -> V_196 , V_7 -> V_222 ) ;
F_171 ( & V_341 -> V_88 ) ;
F_172 ( & V_341 -> V_88 ) ;
F_173 ( & V_341 -> V_88 , V_381 ) ;
F_97 ( & V_341 -> V_88 ) ;
F_98 ( & V_341 -> V_88 ) ;
return 0 ;
V_379:
F_62 (pch, _p, &pl330->ddma.channels,
chan.device_node) {
F_63 ( & V_204 -> V_72 . V_357 ) ;
if ( V_204 -> V_266 ) {
F_105 ( & V_204 -> V_72 ) ;
F_110 ( & V_204 -> V_72 ) ;
}
}
V_355:
F_82 ( V_187 ) ;
return V_190 ;
}
static int F_174 ( struct V_339 * V_341 )
{
struct V_186 * V_187 = F_175 ( V_341 ) ;
struct V_203 * V_204 , * V_345 ;
F_176 ( V_187 -> V_87 . V_88 ) ;
if ( V_341 -> V_88 . V_356 )
F_177 ( V_341 -> V_88 . V_356 ) ;
F_178 ( & V_187 -> V_87 ) ;
F_62 (pch, _p, &pl330->ddma.channels,
chan.device_node) {
F_63 ( & V_204 -> V_72 . V_357 ) ;
if ( V_204 -> V_266 ) {
F_105 ( & V_204 -> V_72 ) ;
F_110 ( & V_204 -> V_72 ) ;
}
}
F_82 ( V_187 ) ;
return 0 ;
}
