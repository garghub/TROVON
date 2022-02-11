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
V_14 [ 1 ] = V_17 ;
V_14 [ 2 ] = V_17 >> 8 ;
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
V_14 [ 2 ] = V_17 ;
V_14 [ 3 ] = V_17 >> 8 ;
V_14 [ 4 ] = V_17 >> 16 ;
V_14 [ 5 ] = V_17 >> 24 ;
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
V_14 [ 2 ] = V_73 ;
V_14 [ 3 ] = V_73 >> 8 ;
V_14 [ 4 ] = V_73 >> 16 ;
V_14 [ 5 ] = V_73 >> 24 ;
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
V_17 = F_32 ( * ( ( V_86 * ) & V_82 [ 2 ] ) ) ;
F_31 ( V_17 , V_77 + V_87 ) ;
if ( F_26 ( V_2 ) ) {
F_33 ( V_2 -> V_5 -> V_88 . V_89 , L_27 ) ;
return;
}
F_31 ( 0 , V_77 + V_90 ) ;
}
static inline T_1 F_34 ( struct V_1 * V_2 )
{
void T_4 * V_77 = V_2 -> V_5 -> V_78 ;
T_1 V_17 ;
if ( F_3 ( V_2 ) )
V_17 = F_28 ( V_77 + V_91 ) & 0xf ;
else
V_17 = F_28 ( V_77 + F_35 ( V_2 -> V_84 ) ) & 0xf ;
switch ( V_17 ) {
case V_92 :
return V_93 ;
case V_94 :
return V_95 ;
case V_96 :
return V_97 ;
case V_98 :
return V_99 ;
case V_100 :
return V_101 ;
case V_102 :
return V_103 ;
case V_104 :
if ( F_3 ( V_2 ) )
return V_105 ;
else
return V_106 ;
case V_107 :
if ( F_3 ( V_2 ) )
return V_105 ;
else
return V_108 ;
case V_109 :
if ( F_3 ( V_2 ) )
return V_105 ;
else
return V_110 ;
case V_111 :
if ( F_3 ( V_2 ) )
return V_105 ;
else
return V_112 ;
case V_113 :
if ( F_3 ( V_2 ) )
return V_105 ;
else
return V_114 ;
case V_115 :
if ( F_3 ( V_2 ) )
return V_105 ;
else
return V_116 ;
default:
return V_105 ;
}
}
static void F_36 ( struct V_1 * V_2 )
{
void T_4 * V_77 = V_2 -> V_5 -> V_78 ;
T_2 V_82 [ 6 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
if ( F_34 ( V_2 ) == V_116 )
F_37 ( V_2 , V_103 | V_112 ) ;
if ( F_34 ( V_2 ) == V_114
|| F_34 ( V_2 ) == V_112
|| F_34 ( V_2 ) == V_93 )
return;
F_14 ( 0 , V_82 ) ;
F_31 ( F_28 ( V_77 + V_117 ) & ~ ( 1 << V_2 -> V_55 ) , V_77 + V_117 ) ;
F_30 ( V_2 , V_82 , F_3 ( V_2 ) ) ;
}
static bool F_38 ( struct V_1 * V_2 )
{
void T_4 * V_77 = V_2 -> V_5 -> V_78 ;
struct V_118 * V_3 ;
struct V_119 * V_4 ;
struct V_71 V_120 ;
unsigned V_74 ;
T_2 V_82 [ 6 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_121 ;
if ( F_34 ( V_2 ) != V_93 )
return true ;
V_121 = 1 - V_2 -> V_122 ;
if ( V_2 -> V_3 [ V_121 ] . V_4 != NULL ) {
V_3 = & V_2 -> V_3 [ V_121 ] ;
} else {
V_121 = V_2 -> V_122 ;
if ( V_2 -> V_3 [ V_121 ] . V_4 != NULL )
V_3 = & V_2 -> V_3 [ V_121 ] ;
else
V_3 = NULL ;
}
if ( ! V_3 )
return true ;
if ( V_121 == V_2 -> V_123 )
return true ;
V_4 = V_3 -> V_4 ;
V_74 = V_4 -> V_124 . V_125 ? 1 : 0 ;
if ( F_4 ( V_2 ) && ! V_74 )
F_39 ( V_2 -> V_5 -> V_88 . V_89 , L_28 ,
V_126 , __LINE__ ) ;
V_120 . V_72 = V_2 -> V_84 ;
V_120 . V_73 = V_3 -> V_127 ;
V_120 . V_74 = V_74 ;
F_25 ( 0 , V_82 , & V_120 ) ;
F_31 ( F_28 ( V_77 + V_117 ) | ( 1 << V_2 -> V_55 ) , V_77 + V_117 ) ;
F_30 ( V_2 , V_82 , true ) ;
V_2 -> V_123 = V_121 ;
return true ;
}
static bool F_40 ( struct V_1 * V_2 )
{
switch ( F_34 ( V_2 ) ) {
case V_116 :
F_37 ( V_2 , V_103 | V_112 ) ;
if ( F_34 ( V_2 ) == V_112 )
F_37 (thrd, PL330_STATE_STOPPED)
case V_103 :
F_36 ( V_2 ) ;
case V_112 :
case V_114 :
F_37 (thrd, PL330_STATE_STOPPED)
case V_93 :
return F_38 ( V_2 ) ;
case V_110 :
case V_108 :
case V_106 :
case V_99 :
case V_97 :
case V_95 :
return true ;
case V_101 :
default:
return false ;
}
}
static inline int F_41 ( unsigned V_13 , T_2 V_14 [] ,
const struct V_128 * V_129 , int V_130 )
{
int V_131 = 0 ;
struct V_132 * V_7 = V_129 -> V_4 -> V_124 . V_7 ;
if ( F_5 ( V_7 -> V_10 ) >= V_133 ) {
while ( V_130 -- ) {
V_131 += F_10 ( V_13 , & V_14 [ V_131 ] , V_134 ) ;
V_131 += F_19 ( V_13 , & V_14 [ V_131 ] , V_134 ) ;
}
} else {
while ( V_130 -- ) {
V_131 += F_10 ( V_13 , & V_14 [ V_131 ] , V_134 ) ;
V_131 += F_17 ( V_13 , & V_14 [ V_131 ] ) ;
V_131 += F_19 ( V_13 , & V_14 [ V_131 ] , V_134 ) ;
V_131 += F_24 ( V_13 , & V_14 [ V_131 ] ) ;
}
}
return V_131 ;
}
static inline int F_42 ( struct V_135 * V_136 , unsigned V_13 ,
T_2 V_14 [] , const struct V_128 * V_129 ,
int V_130 )
{
int V_131 = 0 ;
enum V_25 V_26 ;
if ( V_136 -> V_137 & V_138 )
V_26 = V_30 ;
else
V_26 = V_29 ;
while ( V_130 -- ) {
V_131 += F_23 ( V_13 , & V_14 [ V_131 ] , V_26 , V_129 -> V_4 -> V_22 ) ;
V_131 += F_11 ( V_13 , & V_14 [ V_131 ] , V_26 , V_129 -> V_4 -> V_22 ) ;
V_131 += F_19 ( V_13 , & V_14 [ V_131 ] , V_134 ) ;
if ( ! ( V_136 -> V_137 & V_138 ) )
V_131 += F_9 ( V_13 , & V_14 [ V_131 ] ,
V_129 -> V_4 -> V_22 ) ;
}
return V_131 ;
}
static inline int F_43 ( struct V_135 * V_136 ,
unsigned V_13 , T_2 V_14 [] ,
const struct V_128 * V_129 , int V_130 )
{
int V_131 = 0 ;
enum V_25 V_26 ;
if ( V_136 -> V_137 & V_138 )
V_26 = V_30 ;
else
V_26 = V_29 ;
while ( V_130 -- ) {
V_131 += F_23 ( V_13 , & V_14 [ V_131 ] , V_26 , V_129 -> V_4 -> V_22 ) ;
V_131 += F_10 ( V_13 , & V_14 [ V_131 ] , V_134 ) ;
V_131 += F_20 ( V_13 , & V_14 [ V_131 ] , V_26 , V_129 -> V_4 -> V_22 ) ;
if ( ! ( V_136 -> V_137 & V_138 ) )
V_131 += F_9 ( V_13 , & V_14 [ V_131 ] ,
V_129 -> V_4 -> V_22 ) ;
}
return V_131 ;
}
static int F_44 ( struct V_135 * V_136 , unsigned V_13 , T_2 V_14 [] ,
const struct V_128 * V_129 , int V_130 )
{
int V_131 = 0 ;
switch ( V_129 -> V_4 -> V_139 ) {
case V_140 :
V_131 += F_43 ( V_136 , V_13 , & V_14 [ V_131 ] , V_129 , V_130 ) ;
break;
case V_141 :
V_131 += F_42 ( V_136 , V_13 , & V_14 [ V_131 ] , V_129 , V_130 ) ;
break;
case V_142 :
V_131 += F_41 ( V_13 , & V_14 [ V_131 ] , V_129 , V_130 ) ;
break;
default:
V_131 += 0x40000000 ;
break;
}
return V_131 ;
}
static inline int F_45 ( struct V_135 * V_136 , unsigned V_13 , T_2 V_14 [] ,
unsigned long * V_143 , const struct V_128 * V_129 )
{
int V_130 , V_144 , V_145 , V_146 , V_147 , V_131 ;
unsigned V_148 , V_149 , V_150 , V_151 ;
struct V_37 V_152 ;
if ( * V_143 == 1 )
return F_44 ( V_136 , V_13 , V_14 , V_129 , 1 ) ;
if ( * V_143 >= 256 * 256 ) {
V_149 = 256 ;
V_148 = 256 ;
V_130 = * V_143 / V_149 / V_148 ;
} else if ( * V_143 > 256 ) {
V_149 = 256 ;
V_148 = * V_143 / V_149 ;
V_130 = 1 ;
} else {
V_149 = * V_143 ;
V_148 = 0 ;
V_130 = 1 ;
}
V_145 = F_12 ( 1 , V_14 , 0 , 0 ) ;
V_147 = F_44 ( V_136 , 1 , V_14 , V_129 , 1 ) ;
V_152 . V_26 = V_134 ;
V_152 . V_39 = false ;
V_152 . V_33 = 0 ;
V_152 . V_40 = 0 ;
V_146 = F_13 ( 1 , V_14 , & V_152 ) ;
if ( V_148 ) {
V_145 *= 2 ;
V_146 *= 2 ;
}
V_144 = ( 255 - ( V_145 + V_146 ) ) / V_147 ;
V_130 = ( V_144 < V_130 ) ? V_144 : V_130 ;
V_131 = 0 ;
if ( V_148 ) {
V_131 += F_12 ( V_13 , & V_14 [ V_131 ] , 0 , V_148 ) ;
V_150 = V_131 ;
}
V_131 += F_12 ( V_13 , & V_14 [ V_131 ] , 1 , V_149 ) ;
V_151 = V_131 ;
V_131 += F_44 ( V_136 , V_13 , & V_14 [ V_131 ] , V_129 , V_130 ) ;
V_152 . V_26 = V_134 ;
V_152 . V_39 = false ;
V_152 . V_33 = 1 ;
V_152 . V_40 = V_131 - V_151 ;
V_131 += F_13 ( V_13 , & V_14 [ V_131 ] , & V_152 ) ;
if ( V_148 ) {
V_152 . V_26 = V_134 ;
V_152 . V_39 = false ;
V_152 . V_33 = 0 ;
V_152 . V_40 = V_131 - V_150 ;
V_131 += F_13 ( V_13 , & V_14 [ V_131 ] , & V_152 ) ;
}
* V_143 = V_149 * V_130 ;
if ( V_148 )
* V_143 *= V_148 ;
return V_131 ;
}
static inline int F_46 ( struct V_135 * V_136 ,
unsigned V_13 , T_2 V_14 [] ,
const struct V_128 * V_129 )
{
struct V_153 * V_154 = & V_129 -> V_4 -> V_155 ;
T_1 V_156 = V_129 -> V_156 ;
unsigned long V_157 , V_143 = F_47 ( V_154 -> V_158 , V_156 ) ;
int V_131 = 0 ;
while ( V_143 ) {
V_157 = V_143 ;
V_131 += F_45 ( V_136 , V_13 , & V_14 [ V_131 ] , & V_157 , V_129 ) ;
V_143 -= V_157 ;
}
return V_131 ;
}
static inline int F_48 ( struct V_135 * V_136 ,
unsigned V_13 , T_2 V_14 [] ,
const struct V_128 * V_129 )
{
struct V_153 * V_154 = & V_129 -> V_4 -> V_155 ;
int V_131 = 0 ;
V_131 += F_15 ( V_13 , & V_14 [ V_131 ] , V_49 , V_154 -> V_159 ) ;
V_131 += F_15 ( V_13 , & V_14 [ V_131 ] , V_50 , V_154 -> V_160 ) ;
V_131 += F_46 ( V_136 , V_13 , & V_14 [ V_131 ] , V_129 ) ;
return V_131 ;
}
static int F_49 ( struct V_135 * V_136 , unsigned V_13 ,
struct V_1 * V_2 , unsigned V_161 ,
struct V_128 * V_129 )
{
struct V_118 * V_3 = & V_2 -> V_3 [ V_161 ] ;
struct V_153 * V_154 ;
T_2 * V_14 = V_3 -> V_162 ;
int V_131 = 0 ;
F_50 ( V_3 -> V_127 ) ;
V_131 += F_15 ( V_13 , & V_14 [ V_131 ] , V_163 , V_129 -> V_156 ) ;
V_154 = & V_129 -> V_4 -> V_155 ;
if ( V_154 -> V_158 % ( F_51 ( V_129 -> V_156 ) * F_52 ( V_129 -> V_156 ) ) )
return - V_164 ;
V_131 += F_48 ( V_136 , V_13 , & V_14 [ V_131 ] , V_129 ) ;
V_131 += F_18 ( V_13 , & V_14 [ V_131 ] , V_2 -> V_55 ) ;
V_131 += F_8 ( V_13 , & V_14 [ V_131 ] ) ;
return V_131 ;
}
static inline T_1 F_53 ( const struct V_165 * V_166 )
{
T_1 V_156 = 0 ;
if ( V_166 -> V_167 )
V_156 |= V_168 ;
if ( V_166 -> V_169 )
V_156 |= V_170 ;
if ( V_166 -> V_171 )
V_156 |= V_172 | V_173 ;
if ( V_166 -> V_125 )
V_156 |= V_174 | V_175 ;
if ( V_166 -> V_176 )
V_156 |= V_177 | V_178 ;
V_156 |= ( ( ( V_166 -> V_179 - 1 ) & 0xf ) << V_180 ) ;
V_156 |= ( ( ( V_166 -> V_179 - 1 ) & 0xf ) << V_181 ) ;
V_156 |= ( V_166 -> V_182 << V_183 ) ;
V_156 |= ( V_166 -> V_182 << V_184 ) ;
V_156 |= ( V_166 -> V_185 << V_186 ) ;
V_156 |= ( V_166 -> V_187 << V_188 ) ;
V_156 |= ( V_166 -> V_189 << V_190 ) ;
return V_156 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_119 * V_4 )
{
struct V_135 * V_136 = V_2 -> V_5 ;
struct V_128 V_191 ;
unsigned long V_192 ;
unsigned V_121 ;
T_1 V_156 ;
int V_193 = 0 ;
if ( V_136 -> V_194 == V_195
|| V_136 -> V_196 . V_197 & ( 1 << V_2 -> V_84 ) ) {
F_39 ( V_2 -> V_5 -> V_88 . V_89 , L_29 ,
V_126 , __LINE__ ) ;
return - V_198 ;
}
if ( V_4 -> V_139 != V_142 &&
V_4 -> V_22 >= V_136 -> V_7 . V_199 ) {
F_39 ( V_2 -> V_5 -> V_88 . V_89 ,
L_30 ,
V_126 , __LINE__ , V_4 -> V_22 ) ;
return - V_164 ;
}
F_55 ( & V_136 -> V_200 , V_192 ) ;
if ( F_2 ( V_2 ) ) {
V_193 = - V_198 ;
goto V_201;
}
if ( ! F_4 ( V_2 ) )
V_4 -> V_124 . V_125 = 0 ;
else
V_4 -> V_124 . V_125 = 1 ;
V_156 = F_53 ( & V_4 -> V_124 ) ;
V_121 = V_2 -> V_3 [ 0 ] . V_4 == NULL ? 0 : 1 ;
V_191 . V_156 = V_156 ;
V_191 . V_4 = V_4 ;
V_193 = F_49 ( V_136 , 1 , V_2 , V_121 , & V_191 ) ;
if ( V_193 < 0 )
goto V_201;
if ( V_193 > V_136 -> V_202 / 2 ) {
F_39 ( V_136 -> V_88 . V_89 , L_31 ,
V_126 , __LINE__ , V_193 , V_136 -> V_202 / 2 ) ;
V_193 = - V_203 ;
goto V_201;
}
V_2 -> V_122 = V_121 ;
V_2 -> V_3 [ V_121 ] . V_4 = V_4 ;
F_49 ( V_136 , 0 , V_2 , V_121 , & V_191 ) ;
V_193 = 0 ;
V_201:
F_56 ( & V_136 -> V_200 , V_192 ) ;
return V_193 ;
}
static void F_57 ( struct V_119 * V_4 , enum V_204 V_205 )
{
struct V_206 * V_207 ;
unsigned long V_192 ;
if ( ! V_4 )
return;
V_207 = V_4 -> V_208 ;
if ( ! V_207 )
return;
F_55 ( & V_207 -> V_200 , V_192 ) ;
V_4 -> V_209 = V_210 ;
F_56 ( & V_207 -> V_200 , V_192 ) ;
F_58 ( & V_207 -> V_211 ) ;
}
static void F_59 ( unsigned long V_212 )
{
struct V_135 * V_136 = (struct V_135 * ) V_212 ;
unsigned long V_192 ;
int V_213 ;
F_55 ( & V_136 -> V_200 , V_192 ) ;
if ( V_136 -> V_196 . V_214 ) {
V_136 -> V_194 = V_195 ;
V_136 -> V_196 . V_215 = true ;
V_136 -> V_196 . V_214 = false ;
}
if ( V_136 -> V_196 . V_215 ) {
F_36 ( V_136 -> V_6 ) ;
V_136 -> V_196 . V_197 = ( 1 << V_136 -> V_7 . V_216 ) - 1 ;
V_136 -> V_196 . V_215 = false ;
}
for ( V_213 = 0 ; V_213 < V_136 -> V_7 . V_216 ; V_213 ++ ) {
if ( V_136 -> V_196 . V_197 & ( 1 << V_213 ) ) {
struct V_1 * V_2 = & V_136 -> V_217 [ V_213 ] ;
void T_4 * V_77 = V_136 -> V_78 ;
enum V_204 V_205 ;
F_36 ( V_2 ) ;
if ( F_28 ( V_77 + V_218 ) & ( 1 << V_2 -> V_84 ) )
V_205 = V_219 ;
else
V_205 = V_220 ;
F_56 ( & V_136 -> V_200 , V_192 ) ;
F_57 ( V_2 -> V_3 [ 1 - V_2 -> V_122 ] . V_4 , V_205 ) ;
F_57 ( V_2 -> V_3 [ V_2 -> V_122 ] . V_4 , V_205 ) ;
F_55 ( & V_136 -> V_200 , V_192 ) ;
V_2 -> V_3 [ 0 ] . V_4 = NULL ;
V_2 -> V_3 [ 1 ] . V_4 = NULL ;
V_2 -> V_123 = - 1 ;
V_136 -> V_196 . V_197 &= ~ ( 1 << V_213 ) ;
}
}
F_56 ( & V_136 -> V_200 , V_192 ) ;
return;
}
static int F_60 ( struct V_135 * V_136 )
{
struct V_119 * V_221 , * V_222 ;
unsigned long V_192 ;
void T_4 * V_77 ;
T_1 V_17 ;
int V_84 , V_55 , V_193 = 0 ;
V_77 = V_136 -> V_78 ;
F_55 ( & V_136 -> V_200 , V_192 ) ;
V_17 = F_28 ( V_77 + V_223 ) & 0x1 ;
if ( V_17 )
V_136 -> V_196 . V_215 = true ;
else
V_136 -> V_196 . V_215 = false ;
V_17 = F_28 ( V_77 + V_218 ) & ( ( 1 << V_136 -> V_7 . V_216 ) - 1 ) ;
V_136 -> V_196 . V_197 |= V_17 ;
if ( V_17 ) {
int V_213 = 0 ;
while ( V_213 < V_136 -> V_7 . V_216 ) {
if ( V_17 & ( 1 << V_213 ) ) {
F_39 ( V_136 -> V_88 . V_89 ,
L_32 ,
V_213 , F_28 ( V_77 + F_35 ( V_213 ) ) ,
F_28 ( V_77 + F_61 ( V_213 ) ) ) ;
F_36 ( & V_136 -> V_217 [ V_213 ] ) ;
}
V_213 ++ ;
}
}
V_17 = F_28 ( V_77 + V_224 ) ;
if ( V_136 -> V_7 . V_225 < 32
&& V_17 & ~ ( ( 1 << V_136 -> V_7 . V_225 ) - 1 ) ) {
V_136 -> V_196 . V_214 = true ;
F_33 ( V_136 -> V_88 . V_89 , L_33 , V_126 ,
__LINE__ ) ;
V_193 = 1 ;
goto V_226;
}
for ( V_55 = 0 ; V_55 < V_136 -> V_7 . V_225 ; V_55 ++ ) {
if ( V_17 & ( 1 << V_55 ) ) {
struct V_1 * V_2 ;
T_1 V_227 = F_28 ( V_77 + V_117 ) ;
int V_228 ;
if ( V_227 & ( 1 << V_55 ) )
F_31 ( 1 << V_55 , V_77 + V_229 ) ;
V_193 = 1 ;
V_84 = V_136 -> V_230 [ V_55 ] ;
V_2 = & V_136 -> V_217 [ V_84 ] ;
V_228 = V_2 -> V_123 ;
if ( V_228 == - 1 )
continue;
V_221 = V_2 -> V_3 [ V_228 ] . V_4 ;
V_2 -> V_3 [ V_228 ] . V_4 = NULL ;
V_2 -> V_123 = - 1 ;
F_40 ( V_2 ) ;
F_62 ( & V_221 -> V_231 , & V_136 -> V_232 ) ;
}
}
F_63 (descdone, tmp, &pl330->req_done, rqd) {
F_64 ( & V_221 -> V_231 ) ;
F_56 ( & V_136 -> V_200 , V_192 ) ;
F_57 ( V_221 , V_233 ) ;
F_55 ( & V_136 -> V_200 , V_192 ) ;
}
V_226:
F_56 ( & V_136 -> V_200 , V_192 ) ;
if ( V_136 -> V_196 . V_214
|| V_136 -> V_196 . V_215
|| V_136 -> V_196 . V_197 ) {
V_193 = 1 ;
F_58 ( & V_136 -> V_234 ) ;
}
return V_193 ;
}
static inline int F_65 ( struct V_1 * V_2 )
{
struct V_135 * V_136 = V_2 -> V_5 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_136 -> V_7 . V_225 ; V_55 ++ )
if ( V_136 -> V_230 [ V_55 ] == - 1 ) {
V_136 -> V_230 [ V_55 ] = V_2 -> V_84 ;
return V_55 ;
}
return - 1 ;
}
static bool F_66 ( const struct V_135 * V_136 , int V_213 )
{
return V_136 -> V_7 . V_235 & ( 1 << V_213 ) ;
}
static struct V_1 * F_67 ( struct V_135 * V_136 )
{
struct V_1 * V_2 = NULL ;
int V_236 , V_213 ;
if ( V_136 -> V_194 == V_195 )
return NULL ;
V_236 = V_136 -> V_7 . V_216 ;
for ( V_213 = 0 ; V_213 < V_236 ; V_213 ++ ) {
V_2 = & V_136 -> V_217 [ V_213 ] ;
if ( ( V_2 -> free ) && ( ! F_4 ( V_2 ) ||
F_66 ( V_136 , V_213 ) ) ) {
V_2 -> V_55 = F_65 ( V_2 ) ;
if ( V_2 -> V_55 >= 0 ) {
V_2 -> free = false ;
V_2 -> V_122 = 1 ;
V_2 -> V_3 [ 0 ] . V_4 = NULL ;
V_2 -> V_3 [ 1 ] . V_4 = NULL ;
V_2 -> V_123 = - 1 ;
break;
}
}
V_2 = NULL ;
}
return V_2 ;
}
static inline void F_68 ( struct V_1 * V_2 , int V_55 )
{
struct V_135 * V_136 = V_2 -> V_5 ;
if ( V_55 >= 0 && V_55 < V_136 -> V_7 . V_225
&& V_136 -> V_230 [ V_55 ] == V_2 -> V_84 )
V_136 -> V_230 [ V_55 ] = - 1 ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_135 * V_136 ;
if ( ! V_2 || V_2 -> free )
return;
F_36 ( V_2 ) ;
F_57 ( V_2 -> V_3 [ 1 - V_2 -> V_122 ] . V_4 , V_220 ) ;
F_57 ( V_2 -> V_3 [ V_2 -> V_122 ] . V_4 , V_220 ) ;
V_136 = V_2 -> V_5 ;
F_68 ( V_2 , V_2 -> V_55 ) ;
V_2 -> free = true ;
}
static void F_70 ( struct V_135 * V_136 )
{
void T_4 * V_77 = V_136 -> V_78 ;
T_1 V_17 ;
V_17 = F_28 ( V_77 + V_237 ) >> V_238 ;
V_17 &= V_239 ;
V_136 -> V_7 . V_240 = 8 * ( 1 << V_17 ) ;
V_17 = F_28 ( V_77 + V_237 ) >> V_241 ;
V_17 &= V_242 ;
V_136 -> V_7 . V_243 = V_17 + 1 ;
V_17 = F_28 ( V_77 + V_244 ) >> V_245 ;
V_17 &= V_246 ;
V_17 += 1 ;
V_136 -> V_7 . V_216 = V_17 ;
V_17 = F_28 ( V_77 + V_244 ) ;
if ( V_17 & V_247 ) {
V_17 = ( V_17 >> V_248 ) & V_249 ;
V_17 += 1 ;
V_136 -> V_7 . V_199 = V_17 ;
V_136 -> V_7 . V_250 = F_28 ( V_77 + V_251 ) ;
} else {
V_136 -> V_7 . V_199 = 0 ;
}
V_17 = F_28 ( V_77 + V_244 ) ;
if ( V_17 & V_252 )
V_136 -> V_7 . V_8 |= V_9 ;
else
V_136 -> V_7 . V_8 &= ~ V_9 ;
V_17 = F_28 ( V_77 + V_244 ) >> V_253 ;
V_17 &= V_254 ;
V_17 += 1 ;
V_136 -> V_7 . V_225 = V_17 ;
V_136 -> V_7 . V_235 = F_28 ( V_77 + V_255 ) ;
}
static inline void F_71 ( struct V_1 * V_2 )
{
struct V_135 * V_136 = V_2 -> V_5 ;
V_2 -> V_3 [ 0 ] . V_162 = V_136 -> V_256
+ ( V_2 -> V_84 * V_136 -> V_202 ) ;
V_2 -> V_3 [ 0 ] . V_127 = V_136 -> V_257
+ ( V_2 -> V_84 * V_136 -> V_202 ) ;
V_2 -> V_3 [ 0 ] . V_4 = NULL ;
V_2 -> V_3 [ 1 ] . V_162 = V_2 -> V_3 [ 0 ] . V_162
+ V_136 -> V_202 / 2 ;
V_2 -> V_3 [ 1 ] . V_127 = V_2 -> V_3 [ 0 ] . V_127
+ V_136 -> V_202 / 2 ;
V_2 -> V_3 [ 1 ] . V_4 = NULL ;
V_2 -> V_123 = - 1 ;
}
static int F_72 ( struct V_135 * V_136 )
{
int V_236 = V_136 -> V_7 . V_216 ;
struct V_1 * V_2 ;
int V_213 ;
V_136 -> V_217 = F_73 ( ( 1 + V_236 ) * sizeof( * V_2 ) ,
V_258 ) ;
if ( ! V_136 -> V_217 )
return - V_203 ;
for ( V_213 = 0 ; V_213 < V_236 ; V_213 ++ ) {
V_2 = & V_136 -> V_217 [ V_213 ] ;
V_2 -> V_84 = V_213 ;
V_2 -> V_5 = V_136 ;
F_71 ( V_2 ) ;
V_2 -> free = true ;
}
V_2 = & V_136 -> V_217 [ V_236 ] ;
V_2 -> V_84 = V_236 ;
V_2 -> V_5 = V_136 ;
V_2 -> free = false ;
V_136 -> V_6 = V_2 ;
return 0 ;
}
static int F_74 ( struct V_135 * V_136 )
{
int V_236 = V_136 -> V_7 . V_216 ;
int V_193 ;
V_136 -> V_256 = F_75 ( V_136 -> V_88 . V_89 ,
V_236 * V_136 -> V_202 ,
& V_136 -> V_257 , V_258 ,
V_259 ) ;
if ( ! V_136 -> V_256 ) {
F_33 ( V_136 -> V_88 . V_89 , L_34 ,
V_126 , __LINE__ ) ;
return - V_203 ;
}
V_193 = F_72 ( V_136 ) ;
if ( V_193 ) {
F_33 ( V_136 -> V_88 . V_89 , L_35 ,
V_126 , __LINE__ ) ;
F_76 ( V_136 -> V_88 . V_89 ,
V_236 * V_136 -> V_202 ,
V_136 -> V_256 , V_136 -> V_257 ) ;
return V_193 ;
}
return 0 ;
}
static int F_77 ( struct V_135 * V_136 )
{
int V_213 , V_193 ;
if ( ( V_136 -> V_7 . V_10 & 0xfffff ) != V_260 ) {
F_33 ( V_136 -> V_88 . V_89 , L_36 ,
V_136 -> V_7 . V_10 ) ;
return - V_164 ;
}
F_70 ( V_136 ) ;
if ( V_136 -> V_7 . V_225 == 0 ) {
F_33 ( V_136 -> V_88 . V_89 , L_37 ,
V_126 , __LINE__ ) ;
return - V_164 ;
}
F_78 ( & V_136 -> V_200 ) ;
F_79 ( & V_136 -> V_232 ) ;
if ( ! V_136 -> V_202 )
V_136 -> V_202 = V_261 * 2 ;
for ( V_213 = 0 ; V_213 < V_136 -> V_7 . V_225 ; V_213 ++ )
V_136 -> V_230 [ V_213 ] = - 1 ;
V_193 = F_74 ( V_136 ) ;
if ( V_193 ) {
F_33 ( V_136 -> V_88 . V_89 , L_38 ) ;
return V_193 ;
}
F_80 ( & V_136 -> V_234 , F_59 , ( unsigned long ) V_136 ) ;
V_136 -> V_194 = V_262 ;
return 0 ;
}
static int F_81 ( struct V_135 * V_136 )
{
struct V_1 * V_2 ;
int V_213 ;
for ( V_213 = 0 ; V_213 < V_136 -> V_7 . V_216 ; V_213 ++ ) {
V_2 = & V_136 -> V_217 [ V_213 ] ;
F_69 ( V_2 ) ;
}
F_82 ( V_136 -> V_217 ) ;
return 0 ;
}
static void F_83 ( struct V_135 * V_136 )
{
V_136 -> V_194 = V_263 ;
F_84 ( & V_136 -> V_234 ) ;
F_81 ( V_136 ) ;
F_76 ( V_136 -> V_88 . V_89 ,
V_136 -> V_7 . V_216 * V_136 -> V_202 , V_136 -> V_256 ,
V_136 -> V_257 ) ;
}
static inline struct V_206 *
F_85 ( struct V_264 * V_265 )
{
if ( ! V_265 )
return NULL ;
return F_86 ( V_265 , struct V_206 , V_72 ) ;
}
static inline struct V_119 *
F_87 ( struct V_266 * V_267 )
{
return F_86 ( V_267 , struct V_119 , V_268 ) ;
}
static inline void F_88 ( struct V_206 * V_207 )
{
struct V_119 * V_4 ;
int V_193 ;
F_89 (desc, &pch->work_list, node) {
if ( V_4 -> V_209 == V_269 )
continue;
V_193 = F_54 ( V_207 -> V_270 , V_4 ) ;
if ( ! V_193 ) {
V_4 -> V_209 = V_269 ;
} else if ( V_193 == - V_198 ) {
break;
} else {
V_4 -> V_209 = V_210 ;
F_33 ( V_207 -> V_5 -> V_88 . V_89 , L_39 ,
V_126 , __LINE__ , V_4 -> V_268 . V_271 ) ;
F_58 ( & V_207 -> V_211 ) ;
}
}
}
static void F_90 ( unsigned long V_212 )
{
struct V_206 * V_207 = (struct V_206 * ) V_212 ;
struct V_119 * V_4 , * V_272 ;
unsigned long V_192 ;
bool V_273 = false ;
F_55 ( & V_207 -> V_200 , V_192 ) ;
F_63 (desc, _dt, &pch->work_list, node)
if ( V_4 -> V_209 == V_210 ) {
if ( ! V_207 -> V_274 )
F_91 ( & V_4 -> V_268 ) ;
F_92 ( & V_4 -> V_275 , & V_207 -> V_276 ) ;
}
F_88 ( V_207 ) ;
if ( F_93 ( & V_207 -> V_277 ) ) {
F_94 ( & V_207 -> V_270 -> V_5 -> V_200 ) ;
F_36 ( V_207 -> V_270 ) ;
F_95 ( & V_207 -> V_270 -> V_5 -> V_200 ) ;
V_273 = true ;
V_207 -> V_228 = false ;
} else {
F_94 ( & V_207 -> V_270 -> V_5 -> V_200 ) ;
F_40 ( V_207 -> V_270 ) ;
F_95 ( & V_207 -> V_270 -> V_5 -> V_200 ) ;
}
while ( ! F_93 ( & V_207 -> V_276 ) ) {
struct V_278 V_279 ;
V_4 = F_96 ( & V_207 -> V_276 ,
struct V_119 , V_275 ) ;
F_97 ( & V_4 -> V_268 , & V_279 ) ;
if ( V_207 -> V_274 ) {
V_4 -> V_209 = V_280 ;
F_92 ( & V_4 -> V_275 , & V_207 -> V_277 ) ;
if ( V_273 ) {
V_207 -> V_228 = true ;
F_94 ( & V_207 -> V_270 -> V_5 -> V_200 ) ;
F_40 ( V_207 -> V_270 ) ;
F_95 ( & V_207 -> V_270 -> V_5 -> V_200 ) ;
V_273 = false ;
}
} else {
V_4 -> V_209 = FREE ;
F_92 ( & V_4 -> V_275 , & V_207 -> V_5 -> V_281 ) ;
}
F_98 ( & V_4 -> V_268 ) ;
if ( F_99 ( & V_279 ) ) {
F_56 ( & V_207 -> V_200 , V_192 ) ;
F_100 ( & V_279 , NULL ) ;
F_55 ( & V_207 -> V_200 , V_192 ) ;
}
}
F_56 ( & V_207 -> V_200 , V_192 ) ;
if ( V_273 ) {
F_101 ( V_207 -> V_5 -> V_88 . V_89 ) ;
F_102 ( V_207 -> V_5 -> V_88 . V_89 ) ;
}
}
static struct V_264 * F_103 ( struct V_282 * V_283 ,
struct V_284 * V_285 )
{
int V_286 = V_283 -> V_287 ;
struct V_135 * V_136 = V_285 -> V_288 ;
unsigned int V_289 ;
if ( ! V_136 )
return NULL ;
if ( V_286 != 1 )
return NULL ;
V_289 = V_283 -> args [ 0 ] ;
if ( V_289 >= V_136 -> V_290 )
return NULL ;
return F_104 ( & V_136 -> V_291 [ V_289 ] . V_72 ) ;
}
static int F_105 ( struct V_264 * V_72 )
{
struct V_206 * V_207 = F_85 ( V_72 ) ;
struct V_135 * V_136 = V_207 -> V_5 ;
unsigned long V_192 ;
F_55 ( & V_136 -> V_200 , V_192 ) ;
F_106 ( V_72 ) ;
V_207 -> V_274 = false ;
V_207 -> V_270 = F_67 ( V_136 ) ;
if ( ! V_207 -> V_270 ) {
F_56 ( & V_136 -> V_200 , V_192 ) ;
return - V_203 ;
}
F_80 ( & V_207 -> V_211 , F_90 , ( unsigned long ) V_207 ) ;
F_56 ( & V_136 -> V_200 , V_192 ) ;
return 1 ;
}
static int V_132 ( struct V_264 * V_72 ,
struct V_292 * V_293 )
{
struct V_206 * V_207 = F_85 ( V_72 ) ;
if ( V_293 -> V_294 == V_140 ) {
if ( V_293 -> V_160 )
V_207 -> V_295 = V_293 -> V_160 ;
if ( V_293 -> V_296 )
V_207 -> V_297 = F_107 ( V_293 -> V_296 ) ;
if ( V_293 -> V_298 )
V_207 -> V_299 = V_293 -> V_298 ;
} else if ( V_293 -> V_294 == V_141 ) {
if ( V_293 -> V_159 )
V_207 -> V_295 = V_293 -> V_159 ;
if ( V_293 -> V_300 )
V_207 -> V_297 = F_107 ( V_293 -> V_300 ) ;
if ( V_293 -> V_301 )
V_207 -> V_299 = V_293 -> V_301 ;
}
return 0 ;
}
static int F_108 ( struct V_264 * V_72 )
{
struct V_206 * V_207 = F_85 ( V_72 ) ;
struct V_119 * V_4 ;
unsigned long V_192 ;
struct V_135 * V_136 = V_207 -> V_5 ;
F_109 ( V_302 ) ;
bool V_273 = false ;
F_110 ( V_136 -> V_88 . V_89 ) ;
F_55 ( & V_207 -> V_200 , V_192 ) ;
F_94 ( & V_136 -> V_200 ) ;
F_36 ( V_207 -> V_270 ) ;
F_95 ( & V_136 -> V_200 ) ;
V_207 -> V_270 -> V_3 [ 0 ] . V_4 = NULL ;
V_207 -> V_270 -> V_3 [ 1 ] . V_4 = NULL ;
V_207 -> V_270 -> V_123 = - 1 ;
V_273 = V_207 -> V_228 ;
V_207 -> V_228 = false ;
F_89 (desc, &pch->submitted_list, node) {
V_4 -> V_209 = FREE ;
F_91 ( & V_4 -> V_268 ) ;
}
F_89 (desc, &pch->work_list , node) {
V_4 -> V_209 = FREE ;
F_91 ( & V_4 -> V_268 ) ;
}
F_111 ( & V_207 -> V_303 , & V_136 -> V_281 ) ;
F_111 ( & V_207 -> V_277 , & V_136 -> V_281 ) ;
F_111 ( & V_207 -> V_276 , & V_136 -> V_281 ) ;
F_56 ( & V_207 -> V_200 , V_192 ) ;
F_101 ( V_136 -> V_88 . V_89 ) ;
if ( V_273 )
F_102 ( V_136 -> V_88 . V_89 ) ;
F_102 ( V_136 -> V_88 . V_89 ) ;
return 0 ;
}
static int F_112 ( struct V_264 * V_72 )
{
struct V_206 * V_207 = F_85 ( V_72 ) ;
struct V_135 * V_136 = V_207 -> V_5 ;
unsigned long V_192 ;
F_110 ( V_136 -> V_88 . V_89 ) ;
F_55 ( & V_207 -> V_200 , V_192 ) ;
F_94 ( & V_136 -> V_200 ) ;
F_36 ( V_207 -> V_270 ) ;
F_95 ( & V_136 -> V_200 ) ;
F_56 ( & V_207 -> V_200 , V_192 ) ;
F_101 ( V_136 -> V_88 . V_89 ) ;
F_102 ( V_136 -> V_88 . V_89 ) ;
return 0 ;
}
static void F_113 ( struct V_264 * V_72 )
{
struct V_206 * V_207 = F_85 ( V_72 ) ;
struct V_135 * V_136 = V_207 -> V_5 ;
unsigned long V_192 ;
F_84 ( & V_207 -> V_211 ) ;
F_110 ( V_207 -> V_5 -> V_88 . V_89 ) ;
F_55 ( & V_136 -> V_200 , V_192 ) ;
F_69 ( V_207 -> V_270 ) ;
V_207 -> V_270 = NULL ;
if ( V_207 -> V_274 )
F_111 ( & V_207 -> V_277 , & V_207 -> V_5 -> V_281 ) ;
F_56 ( & V_136 -> V_200 , V_192 ) ;
F_101 ( V_207 -> V_5 -> V_88 . V_89 ) ;
F_102 ( V_207 -> V_5 -> V_88 . V_89 ) ;
}
static int F_114 ( struct V_206 * V_207 ,
struct V_119 * V_4 )
{
struct V_1 * V_2 = V_207 -> V_270 ;
struct V_135 * V_136 = V_207 -> V_5 ;
void T_4 * V_77 = V_2 -> V_5 -> V_78 ;
T_1 V_17 , V_73 ;
F_110 ( V_136 -> V_88 . V_89 ) ;
V_17 = V_73 = 0 ;
if ( V_4 -> V_124 . V_167 ) {
V_17 = F_28 ( V_77 + F_115 ( V_2 -> V_84 ) ) ;
V_73 = V_4 -> V_155 . V_159 ;
} else {
V_17 = F_28 ( V_77 + F_116 ( V_2 -> V_84 ) ) ;
V_73 = V_4 -> V_155 . V_160 ;
}
F_101 ( V_207 -> V_5 -> V_88 . V_89 ) ;
F_102 ( V_136 -> V_88 . V_89 ) ;
if ( ! V_17 )
return 0 ;
return V_17 - V_73 ;
}
static enum V_304
F_117 ( struct V_264 * V_72 , T_5 V_271 ,
struct V_305 * V_306 )
{
enum V_304 V_193 ;
unsigned long V_192 ;
struct V_119 * V_4 , * V_307 = NULL , * V_308 = NULL ;
struct V_206 * V_207 = F_85 ( V_72 ) ;
unsigned int V_309 , V_310 = 0 ;
V_193 = F_118 ( V_72 , V_271 , V_306 ) ;
if ( ! V_306 )
return V_193 ;
if ( V_193 == V_311 )
goto V_312;
F_55 ( & V_207 -> V_200 , V_192 ) ;
F_94 ( & V_207 -> V_270 -> V_5 -> V_200 ) ;
if ( V_207 -> V_270 -> V_123 != - 1 )
V_307 = V_207 -> V_270 -> V_3 [ V_207 -> V_270 -> V_123 ] . V_4 ;
V_308 = V_207 -> V_270 -> V_3 [ V_207 -> V_270 -> V_122 ] . V_4 ;
F_89 (desc, &pch->work_list, node) {
if ( V_4 -> V_209 == V_210 )
V_309 = V_4 -> V_313 ;
else if ( V_307 && V_4 == V_307 )
V_309 =
F_114 ( V_207 , V_4 ) ;
else if ( V_4 -> V_209 == V_269 )
if ( V_4 == V_308 )
V_309 = 0 ;
else
V_309 = V_4 -> V_313 ;
else
V_309 = 0 ;
V_310 += V_4 -> V_313 - V_309 ;
if ( V_4 -> V_268 . V_271 == V_271 ) {
switch ( V_4 -> V_209 ) {
case V_210 :
V_193 = V_311 ;
break;
case V_280 :
case V_269 :
V_193 = V_314 ;
break;
default:
F_119 ( 1 ) ;
}
break;
}
if ( V_4 -> V_315 )
V_310 = 0 ;
}
F_95 ( & V_207 -> V_270 -> V_5 -> V_200 ) ;
F_56 ( & V_207 -> V_200 , V_192 ) ;
V_312:
F_120 ( V_306 , V_310 ) ;
return V_193 ;
}
static void F_121 ( struct V_264 * V_72 )
{
struct V_206 * V_207 = F_85 ( V_72 ) ;
unsigned long V_192 ;
F_55 ( & V_207 -> V_200 , V_192 ) ;
if ( F_93 ( & V_207 -> V_277 ) ) {
F_119 ( F_93 ( & V_207 -> V_303 ) ) ;
V_207 -> V_228 = true ;
F_110 ( V_207 -> V_5 -> V_88 . V_89 ) ;
}
F_111 ( & V_207 -> V_303 , & V_207 -> V_277 ) ;
F_56 ( & V_207 -> V_200 , V_192 ) ;
F_90 ( ( unsigned long ) V_207 ) ;
}
static T_5 F_122 ( struct V_266 * V_267 )
{
struct V_119 * V_4 , * V_315 = F_87 ( V_267 ) ;
struct V_206 * V_207 = F_85 ( V_267 -> V_72 ) ;
T_5 V_271 ;
unsigned long V_192 ;
F_55 ( & V_207 -> V_200 , V_192 ) ;
while ( ! F_93 ( & V_315 -> V_275 ) ) {
V_4 = F_123 ( V_315 -> V_275 . V_316 , struct V_119 , V_275 ) ;
if ( V_207 -> V_274 ) {
V_4 -> V_268 . V_317 = V_315 -> V_268 . V_317 ;
V_4 -> V_268 . V_318 = V_315 -> V_268 . V_318 ;
}
V_4 -> V_315 = false ;
F_124 ( & V_4 -> V_268 ) ;
F_92 ( & V_4 -> V_275 , & V_207 -> V_303 ) ;
}
V_315 -> V_315 = true ;
V_271 = F_124 ( & V_315 -> V_268 ) ;
F_62 ( & V_315 -> V_275 , & V_207 -> V_303 ) ;
F_56 ( & V_207 -> V_200 , V_192 ) ;
return V_271 ;
}
static inline void F_125 ( struct V_119 * V_4 )
{
V_4 -> V_124 . V_189 = V_319 ;
V_4 -> V_124 . V_185 = V_320 ;
V_4 -> V_124 . V_187 = V_320 ;
V_4 -> V_268 . V_321 = F_122 ;
F_79 ( & V_4 -> V_275 ) ;
}
static int F_126 ( struct V_135 * V_136 , T_6 V_322 , int V_286 )
{
struct V_119 * V_4 ;
unsigned long V_192 ;
int V_213 ;
V_4 = F_127 ( V_286 , sizeof( * V_4 ) , V_322 ) ;
if ( ! V_4 )
return 0 ;
F_55 ( & V_136 -> V_323 , V_192 ) ;
for ( V_213 = 0 ; V_213 < V_286 ; V_213 ++ ) {
F_125 ( & V_4 [ V_213 ] ) ;
F_62 ( & V_4 [ V_213 ] . V_275 , & V_136 -> V_281 ) ;
}
F_56 ( & V_136 -> V_323 , V_192 ) ;
return V_286 ;
}
static struct V_119 * F_128 ( struct V_135 * V_136 )
{
struct V_119 * V_4 = NULL ;
unsigned long V_192 ;
F_55 ( & V_136 -> V_323 , V_192 ) ;
if ( ! F_93 ( & V_136 -> V_281 ) ) {
V_4 = F_123 ( V_136 -> V_281 . V_316 ,
struct V_119 , V_275 ) ;
F_129 ( & V_4 -> V_275 ) ;
V_4 -> V_209 = V_280 ;
V_4 -> V_268 . V_317 = NULL ;
}
F_56 ( & V_136 -> V_323 , V_192 ) ;
return V_4 ;
}
static struct V_119 * F_130 ( struct V_206 * V_207 )
{
struct V_135 * V_136 = V_207 -> V_5 ;
T_2 * V_324 = V_207 -> V_72 . V_325 ;
struct V_119 * V_4 ;
V_4 = F_128 ( V_136 ) ;
if ( ! V_4 ) {
if ( ! F_126 ( V_136 , V_326 , 1 ) )
return NULL ;
V_4 = F_128 ( V_136 ) ;
if ( ! V_4 ) {
F_33 ( V_207 -> V_5 -> V_88 . V_89 ,
L_40 , V_126 , __LINE__ ) ;
return NULL ;
}
}
V_4 -> V_208 = V_207 ;
V_4 -> V_268 . V_271 = 0 ;
F_131 ( & V_4 -> V_268 ) ;
V_4 -> V_22 = V_324 ? V_207 -> V_72 . V_289 : 0 ;
V_4 -> V_124 . V_7 = & V_207 -> V_5 -> V_7 ;
F_132 ( & V_4 -> V_268 , & V_207 -> V_72 ) ;
return V_4 ;
}
static inline void F_133 ( struct V_153 * V_155 ,
T_7 V_46 , T_7 V_327 , T_8 V_328 )
{
V_155 -> V_158 = V_328 ;
V_155 -> V_160 = V_46 ;
V_155 -> V_159 = V_327 ;
}
static struct V_119 *
F_134 ( struct V_206 * V_207 , T_7 V_46 ,
T_7 V_327 , T_8 V_328 )
{
struct V_119 * V_4 = F_130 ( V_207 ) ;
if ( ! V_4 ) {
F_33 ( V_207 -> V_5 -> V_88 . V_89 , L_41 ,
V_126 , __LINE__ ) ;
return NULL ;
}
F_133 ( & V_4 -> V_155 , V_46 , V_327 , V_328 ) ;
return V_4 ;
}
static inline int F_135 ( struct V_119 * V_4 , T_8 V_328 )
{
struct V_206 * V_207 = V_4 -> V_208 ;
struct V_135 * V_136 = V_207 -> V_5 ;
int V_299 ;
V_299 = V_136 -> V_7 . V_240 / 8 ;
V_299 *= V_136 -> V_7 . V_243 / V_136 -> V_7 . V_216 ;
V_299 >>= V_4 -> V_124 . V_182 ;
if ( V_299 > 16 )
V_299 = 16 ;
while ( V_299 > 1 ) {
if ( ! ( V_328 % ( V_299 << V_4 -> V_124 . V_182 ) ) )
break;
V_299 -- ;
}
return V_299 ;
}
static struct V_266 * F_136 (
struct V_264 * V_72 , T_7 V_329 , T_8 V_328 ,
T_8 V_330 , enum V_331 V_294 ,
unsigned long V_192 )
{
struct V_119 * V_4 = NULL , * V_332 = NULL ;
struct V_206 * V_207 = F_85 ( V_72 ) ;
struct V_135 * V_136 = V_207 -> V_5 ;
unsigned int V_213 ;
T_7 V_46 ;
T_7 V_327 ;
if ( V_328 % V_330 != 0 )
return NULL ;
if ( ! F_137 ( V_294 ) ) {
F_33 ( V_207 -> V_5 -> V_88 . V_89 , L_42 ,
V_126 , __LINE__ ) ;
return NULL ;
}
for ( V_213 = 0 ; V_213 < V_328 / V_330 ; V_213 ++ ) {
V_4 = F_130 ( V_207 ) ;
if ( ! V_4 ) {
F_33 ( V_207 -> V_5 -> V_88 . V_89 , L_41 ,
V_126 , __LINE__ ) ;
if ( ! V_332 )
return NULL ;
F_55 ( & V_136 -> V_323 , V_192 ) ;
while ( ! F_93 ( & V_332 -> V_275 ) ) {
V_4 = F_123 ( V_332 -> V_275 . V_316 ,
struct V_119 , V_275 ) ;
F_92 ( & V_4 -> V_275 , & V_136 -> V_281 ) ;
}
F_92 ( & V_332 -> V_275 , & V_136 -> V_281 ) ;
F_56 ( & V_136 -> V_323 , V_192 ) ;
return NULL ;
}
switch ( V_294 ) {
case V_140 :
V_4 -> V_124 . V_167 = 1 ;
V_4 -> V_124 . V_169 = 0 ;
V_327 = V_329 ;
V_46 = V_207 -> V_295 ;
break;
case V_141 :
V_4 -> V_124 . V_167 = 0 ;
V_4 -> V_124 . V_169 = 1 ;
V_327 = V_207 -> V_295 ;
V_46 = V_329 ;
break;
default:
break;
}
V_4 -> V_139 = V_294 ;
V_4 -> V_124 . V_182 = V_207 -> V_297 ;
V_4 -> V_124 . V_179 = 1 ;
V_4 -> V_313 = V_330 ;
F_133 ( & V_4 -> V_155 , V_46 , V_327 , V_330 ) ;
if ( ! V_332 )
V_332 = V_4 ;
else
F_62 ( & V_4 -> V_275 , & V_332 -> V_275 ) ;
V_329 += V_330 ;
}
if ( ! V_4 )
return NULL ;
V_207 -> V_274 = true ;
V_4 -> V_268 . V_192 = V_192 ;
return & V_4 -> V_268 ;
}
static struct V_266 *
F_138 ( struct V_264 * V_72 , T_7 V_46 ,
T_7 V_327 , T_8 V_328 , unsigned long V_192 )
{
struct V_119 * V_4 ;
struct V_206 * V_207 = F_85 ( V_72 ) ;
struct V_135 * V_136 ;
int V_333 ;
if ( F_139 ( ! V_207 || ! V_328 ) )
return NULL ;
V_136 = V_207 -> V_5 ;
V_4 = F_134 ( V_207 , V_46 , V_327 , V_328 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_124 . V_167 = 1 ;
V_4 -> V_124 . V_169 = 1 ;
V_4 -> V_139 = V_142 ;
V_333 = V_136 -> V_7 . V_240 / 8 ;
while ( ( V_327 | V_46 | V_328 ) & ( V_333 - 1 ) )
V_333 /= 2 ;
V_4 -> V_124 . V_182 = 0 ;
while ( V_333 != ( 1 << V_4 -> V_124 . V_182 ) )
V_4 -> V_124 . V_182 ++ ;
if ( V_4 -> V_124 . V_182 * 8 < V_136 -> V_7 . V_240 )
V_4 -> V_124 . V_179 = 1 ;
V_4 -> V_124 . V_179 = F_135 ( V_4 , V_328 ) ;
V_4 -> V_313 = V_328 ;
V_4 -> V_268 . V_192 = V_192 ;
return & V_4 -> V_268 ;
}
static void F_140 ( struct V_135 * V_136 ,
struct V_119 * V_332 )
{
unsigned long V_192 ;
struct V_119 * V_4 ;
if ( ! V_332 )
return;
F_55 ( & V_136 -> V_323 , V_192 ) ;
while ( ! F_93 ( & V_332 -> V_275 ) ) {
V_4 = F_123 ( V_332 -> V_275 . V_316 ,
struct V_119 , V_275 ) ;
F_92 ( & V_4 -> V_275 , & V_136 -> V_281 ) ;
}
F_92 ( & V_332 -> V_275 , & V_136 -> V_281 ) ;
F_56 ( & V_136 -> V_323 , V_192 ) ;
}
static struct V_266 *
F_141 ( struct V_264 * V_72 , struct V_334 * V_335 ,
unsigned int V_336 , enum V_331 V_294 ,
unsigned long V_322 , void * V_337 )
{
struct V_119 * V_332 , * V_4 = NULL ;
struct V_206 * V_207 = F_85 ( V_72 ) ;
struct V_334 * V_338 ;
int V_213 ;
T_7 V_73 ;
if ( F_139 ( ! V_207 || ! V_335 || ! V_336 ) )
return NULL ;
V_73 = V_207 -> V_295 ;
V_332 = NULL ;
F_142 (sgl, sg, sg_len, i) {
V_4 = F_130 ( V_207 ) ;
if ( ! V_4 ) {
struct V_135 * V_136 = V_207 -> V_5 ;
F_33 ( V_207 -> V_5 -> V_88 . V_89 ,
L_41 ,
V_126 , __LINE__ ) ;
F_140 ( V_136 , V_332 ) ;
return NULL ;
}
if ( ! V_332 )
V_332 = V_4 ;
else
F_62 ( & V_4 -> V_275 , & V_332 -> V_275 ) ;
if ( V_294 == V_140 ) {
V_4 -> V_124 . V_167 = 1 ;
V_4 -> V_124 . V_169 = 0 ;
F_133 ( & V_4 -> V_155 ,
V_73 , F_143 ( V_338 ) , F_144 ( V_338 ) ) ;
} else {
V_4 -> V_124 . V_167 = 0 ;
V_4 -> V_124 . V_169 = 1 ;
F_133 ( & V_4 -> V_155 ,
F_143 ( V_338 ) , V_73 , F_144 ( V_338 ) ) ;
}
V_4 -> V_124 . V_182 = V_207 -> V_297 ;
V_4 -> V_124 . V_179 = 1 ;
V_4 -> V_139 = V_294 ;
V_4 -> V_313 = F_144 ( V_338 ) ;
}
V_4 -> V_268 . V_192 = V_322 ;
return & V_4 -> V_268 ;
}
static T_9 F_145 ( int V_339 , void * V_212 )
{
if ( F_60 ( V_212 ) )
return V_340 ;
else
return V_341 ;
}
static int T_10 F_146 ( struct V_342 * V_89 )
{
struct V_343 * V_344 = F_147 ( V_89 ) ;
F_148 ( V_89 ) ;
if ( ! F_149 ( V_89 ) ) {
F_150 ( V_344 ) ;
}
F_151 ( V_344 ) ;
return 0 ;
}
static int T_10 F_152 ( struct V_342 * V_89 )
{
struct V_343 * V_344 = F_147 ( V_89 ) ;
int V_193 ;
V_193 = F_153 ( V_344 ) ;
if ( V_193 )
return V_193 ;
if ( ! F_149 ( V_89 ) )
V_193 = F_154 ( V_344 ) ;
F_155 ( V_89 ) ;
return V_193 ;
}
static int
F_156 ( struct V_343 * V_345 , const struct V_346 * V_84 )
{
struct V_132 * V_7 ;
struct V_135 * V_136 ;
struct V_206 * V_207 , * V_347 ;
struct V_348 * V_349 ;
struct V_350 * V_351 ;
int V_213 , V_193 , V_339 ;
int V_216 ;
struct V_352 * V_353 = V_345 -> V_89 . V_354 ;
V_193 = F_157 ( & V_345 -> V_89 , F_158 ( 32 ) ) ;
if ( V_193 )
return V_193 ;
V_136 = F_159 ( & V_345 -> V_89 , sizeof( * V_136 ) , V_258 ) ;
if ( ! V_136 )
return - V_203 ;
V_349 = & V_136 -> V_88 ;
V_349 -> V_89 = & V_345 -> V_89 ;
V_136 -> V_202 = 0 ;
for ( V_213 = 0 ; V_213 < F_160 ( V_355 ) ; V_213 ++ )
if ( F_161 ( V_353 , V_355 [ V_213 ] . V_356 ) )
V_136 -> V_137 |= V_355 [ V_213 ] . V_84 ;
V_351 = & V_345 -> V_351 ;
V_136 -> V_78 = F_162 ( & V_345 -> V_89 , V_351 ) ;
if ( F_163 ( V_136 -> V_78 ) )
return F_164 ( V_136 -> V_78 ) ;
F_165 ( V_345 , V_136 ) ;
for ( V_213 = 0 ; V_213 < V_357 ; V_213 ++ ) {
V_339 = V_345 -> V_339 [ V_213 ] ;
if ( V_339 ) {
V_193 = F_166 ( & V_345 -> V_89 , V_339 ,
F_145 , 0 ,
F_167 ( & V_345 -> V_89 ) , V_136 ) ;
if ( V_193 )
return V_193 ;
} else {
break;
}
}
V_7 = & V_136 -> V_7 ;
V_7 -> V_10 = V_345 -> V_358 ;
V_193 = F_77 ( V_136 ) ;
if ( V_193 )
return V_193 ;
F_79 ( & V_136 -> V_281 ) ;
F_78 ( & V_136 -> V_323 ) ;
if ( ! F_126 ( V_136 , V_258 , V_359 ) )
F_168 ( & V_345 -> V_89 , L_43 ) ;
F_79 ( & V_349 -> V_217 ) ;
V_216 = F_169 ( int , V_7 -> V_199 , V_7 -> V_216 ) ;
V_136 -> V_290 = V_216 ;
V_136 -> V_291 = F_73 ( V_216 * sizeof( * V_207 ) , V_258 ) ;
if ( ! V_136 -> V_291 ) {
V_193 = - V_203 ;
goto V_360;
}
for ( V_213 = 0 ; V_213 < V_216 ; V_213 ++ ) {
V_207 = & V_136 -> V_291 [ V_213 ] ;
V_207 -> V_72 . V_325 = V_345 -> V_89 . V_354 ;
F_79 ( & V_207 -> V_303 ) ;
F_79 ( & V_207 -> V_277 ) ;
F_79 ( & V_207 -> V_276 ) ;
F_78 ( & V_207 -> V_200 ) ;
V_207 -> V_270 = NULL ;
V_207 -> V_72 . V_342 = V_349 ;
V_207 -> V_5 = V_136 ;
F_62 ( & V_207 -> V_72 . V_352 , & V_349 -> V_217 ) ;
}
F_170 ( V_361 , V_349 -> V_362 ) ;
if ( V_7 -> V_199 ) {
F_170 ( V_363 , V_349 -> V_362 ) ;
F_170 ( V_364 , V_349 -> V_362 ) ;
F_170 ( V_365 , V_349 -> V_362 ) ;
}
V_349 -> V_366 = F_105 ;
V_349 -> V_367 = F_113 ;
V_349 -> V_368 = F_138 ;
V_349 -> V_369 = F_136 ;
V_349 -> V_370 = F_117 ;
V_349 -> V_371 = F_141 ;
V_349 -> V_372 = V_132 ;
V_349 -> V_373 = F_112 ;
V_349 -> V_374 = F_108 ;
V_349 -> V_375 = F_121 ;
V_349 -> V_376 = V_377 ;
V_349 -> V_378 = V_377 ;
V_349 -> V_379 = F_171 ( V_141 ) | F_171 ( V_140 ) ;
V_349 -> V_380 = V_381 ;
V_349 -> V_382 = ( ( V_136 -> V_137 & V_138 ) ?
1 : V_383 ) ;
V_193 = F_172 ( V_349 ) ;
if ( V_193 ) {
F_33 ( & V_345 -> V_89 , L_44 ) ;
goto V_384;
}
if ( V_345 -> V_89 . V_354 ) {
V_193 = F_173 ( V_345 -> V_89 . V_354 ,
F_103 , V_136 ) ;
if ( V_193 ) {
F_33 ( & V_345 -> V_89 ,
L_45 ) ;
}
}
V_345 -> V_89 . V_385 = & V_136 -> V_385 ;
V_193 = F_174 ( & V_345 -> V_89 , 1900800 ) ;
if ( V_193 )
F_33 ( & V_345 -> V_89 , L_46 ) ;
F_39 ( & V_345 -> V_89 ,
L_47 , V_345 -> V_358 ) ;
F_39 ( & V_345 -> V_89 ,
L_48 ,
V_7 -> V_243 , V_7 -> V_240 / 8 , V_7 -> V_216 ,
V_7 -> V_199 , V_7 -> V_225 ) ;
F_175 ( & V_345 -> V_89 ) ;
F_176 ( & V_345 -> V_89 ) ;
F_177 ( & V_345 -> V_89 , V_386 ) ;
F_101 ( & V_345 -> V_89 ) ;
F_102 ( & V_345 -> V_89 ) ;
return 0 ;
V_384:
F_63 (pch, _p, &pl330->ddma.channels,
chan.device_node) {
F_64 ( & V_207 -> V_72 . V_352 ) ;
if ( V_207 -> V_270 ) {
F_108 ( & V_207 -> V_72 ) ;
F_113 ( & V_207 -> V_72 ) ;
}
}
V_360:
F_83 ( V_136 ) ;
return V_193 ;
}
static int F_178 ( struct V_343 * V_345 )
{
struct V_135 * V_136 = F_179 ( V_345 ) ;
struct V_206 * V_207 , * V_347 ;
int V_213 , V_339 ;
F_180 ( V_136 -> V_88 . V_89 ) ;
if ( V_345 -> V_89 . V_354 )
F_181 ( V_345 -> V_89 . V_354 ) ;
for ( V_213 = 0 ; V_213 < V_357 ; V_213 ++ ) {
V_339 = V_345 -> V_339 [ V_213 ] ;
if ( V_339 )
F_182 ( & V_345 -> V_89 , V_339 , V_136 ) ;
}
F_183 ( & V_136 -> V_88 ) ;
F_63 (pch, _p, &pl330->ddma.channels,
chan.device_node) {
F_64 ( & V_207 -> V_72 . V_352 ) ;
if ( V_207 -> V_270 ) {
F_108 ( & V_207 -> V_72 ) ;
F_113 ( & V_207 -> V_72 ) ;
}
}
F_83 ( V_136 ) ;
return 0 ;
}
