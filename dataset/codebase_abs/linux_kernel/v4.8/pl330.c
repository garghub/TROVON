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
static inline int F_44 ( struct V_136 * V_137 , unsigned V_13 ,
T_2 V_14 [] , const struct V_129 * V_130 ,
int V_131 )
{
int V_132 = 0 ;
enum V_26 V_27 ;
if ( V_137 -> V_138 & V_139 )
V_27 = V_31 ;
else
V_27 = V_30 ;
while ( V_131 -- ) {
V_132 += F_25 ( V_13 , & V_14 [ V_132 ] , V_27 , V_130 -> V_4 -> V_23 ) ;
V_132 += F_12 ( V_13 , & V_14 [ V_132 ] , V_27 , V_130 -> V_4 -> V_23 ) ;
V_132 += F_21 ( V_13 , & V_14 [ V_132 ] , V_135 ) ;
if ( ! ( V_137 -> V_138 & V_139 ) )
V_132 += F_10 ( V_13 , & V_14 [ V_132 ] ,
V_130 -> V_4 -> V_23 ) ;
}
return V_132 ;
}
static inline int F_45 ( struct V_136 * V_137 ,
unsigned V_13 , T_2 V_14 [] ,
const struct V_129 * V_130 , int V_131 )
{
int V_132 = 0 ;
enum V_26 V_27 ;
if ( V_137 -> V_138 & V_139 )
V_27 = V_31 ;
else
V_27 = V_30 ;
while ( V_131 -- ) {
V_132 += F_25 ( V_13 , & V_14 [ V_132 ] , V_27 , V_130 -> V_4 -> V_23 ) ;
V_132 += F_11 ( V_13 , & V_14 [ V_132 ] , V_135 ) ;
V_132 += F_22 ( V_13 , & V_14 [ V_132 ] , V_27 , V_130 -> V_4 -> V_23 ) ;
if ( ! ( V_137 -> V_138 & V_139 ) )
V_132 += F_10 ( V_13 , & V_14 [ V_132 ] ,
V_130 -> V_4 -> V_23 ) ;
}
return V_132 ;
}
static int F_46 ( struct V_136 * V_137 , unsigned V_13 , T_2 V_14 [] ,
const struct V_129 * V_130 , int V_131 )
{
int V_132 = 0 ;
switch ( V_130 -> V_4 -> V_140 ) {
case V_141 :
V_132 += F_45 ( V_137 , V_13 , & V_14 [ V_132 ] , V_130 , V_131 ) ;
break;
case V_142 :
V_132 += F_44 ( V_137 , V_13 , & V_14 [ V_132 ] , V_130 , V_131 ) ;
break;
case V_143 :
V_132 += F_43 ( V_13 , & V_14 [ V_132 ] , V_130 , V_131 ) ;
break;
default:
V_132 += 0x40000000 ;
break;
}
return V_132 ;
}
static inline int F_47 ( struct V_136 * V_137 , unsigned V_13 , T_2 V_14 [] ,
unsigned long * V_144 , const struct V_129 * V_130 )
{
int V_131 , V_145 , V_146 , V_147 , V_148 , V_132 ;
unsigned V_149 , V_150 , V_151 , V_152 ;
struct V_38 V_153 ;
if ( * V_144 == 1 )
return F_46 ( V_137 , V_13 , V_14 , V_130 , 1 ) ;
if ( * V_144 >= 256 * 256 ) {
V_150 = 256 ;
V_149 = 256 ;
V_131 = * V_144 / V_150 / V_149 ;
} else if ( * V_144 > 256 ) {
V_150 = 256 ;
V_149 = * V_144 / V_150 ;
V_131 = 1 ;
} else {
V_150 = * V_144 ;
V_149 = 0 ;
V_131 = 1 ;
}
V_146 = F_13 ( 1 , V_14 , 0 , 0 ) ;
V_148 = F_46 ( V_137 , 1 , V_14 , V_130 , 1 ) ;
V_153 . V_27 = V_135 ;
V_153 . V_40 = false ;
V_153 . V_34 = 0 ;
V_153 . V_41 = 0 ;
V_147 = F_14 ( 1 , V_14 , & V_153 ) ;
if ( V_149 ) {
V_146 *= 2 ;
V_147 *= 2 ;
}
V_145 = ( 255 - ( V_146 + V_147 ) ) / V_148 ;
V_131 = ( V_145 < V_131 ) ? V_145 : V_131 ;
V_132 = 0 ;
if ( V_149 ) {
V_132 += F_13 ( V_13 , & V_14 [ V_132 ] , 0 , V_149 ) ;
V_151 = V_132 ;
}
V_132 += F_13 ( V_13 , & V_14 [ V_132 ] , 1 , V_150 ) ;
V_152 = V_132 ;
V_132 += F_46 ( V_137 , V_13 , & V_14 [ V_132 ] , V_130 , V_131 ) ;
V_153 . V_27 = V_135 ;
V_153 . V_40 = false ;
V_153 . V_34 = 1 ;
V_153 . V_41 = V_132 - V_152 ;
V_132 += F_14 ( V_13 , & V_14 [ V_132 ] , & V_153 ) ;
if ( V_149 ) {
V_153 . V_27 = V_135 ;
V_153 . V_40 = false ;
V_153 . V_34 = 0 ;
V_153 . V_41 = V_132 - V_151 ;
V_132 += F_14 ( V_13 , & V_14 [ V_132 ] , & V_153 ) ;
}
* V_144 = V_150 * V_131 ;
if ( V_149 )
* V_144 *= V_149 ;
return V_132 ;
}
static inline int F_48 ( struct V_136 * V_137 ,
unsigned V_13 , T_2 V_14 [] ,
const struct V_129 * V_130 )
{
struct V_154 * V_155 = & V_130 -> V_4 -> V_156 ;
T_1 V_157 = V_130 -> V_157 ;
unsigned long V_158 , V_144 = F_49 ( V_155 -> V_159 , V_157 ) ;
int V_132 = 0 ;
while ( V_144 ) {
V_158 = V_144 ;
V_132 += F_47 ( V_137 , V_13 , & V_14 [ V_132 ] , & V_158 , V_130 ) ;
V_144 -= V_158 ;
}
return V_132 ;
}
static inline int F_50 ( struct V_136 * V_137 ,
unsigned V_13 , T_2 V_14 [] ,
const struct V_129 * V_130 )
{
struct V_154 * V_155 = & V_130 -> V_4 -> V_156 ;
int V_132 = 0 ;
V_132 += F_16 ( V_13 , & V_14 [ V_132 ] , V_51 , V_155 -> V_160 ) ;
V_132 += F_16 ( V_13 , & V_14 [ V_132 ] , V_52 , V_155 -> V_161 ) ;
V_132 += F_48 ( V_137 , V_13 , & V_14 [ V_132 ] , V_130 ) ;
return V_132 ;
}
static int F_51 ( struct V_136 * V_137 , unsigned V_13 ,
struct V_1 * V_2 , unsigned V_162 ,
struct V_129 * V_130 )
{
struct V_119 * V_3 = & V_2 -> V_3 [ V_162 ] ;
struct V_154 * V_155 ;
T_2 * V_14 = V_3 -> V_163 ;
int V_132 = 0 ;
F_52 ( V_3 -> V_128 ) ;
V_132 += F_16 ( V_13 , & V_14 [ V_132 ] , V_164 , V_130 -> V_157 ) ;
V_155 = & V_130 -> V_4 -> V_156 ;
if ( V_155 -> V_159 % ( F_53 ( V_130 -> V_157 ) * F_54 ( V_130 -> V_157 ) ) )
return - V_165 ;
V_132 += F_50 ( V_137 , V_13 , & V_14 [ V_132 ] , V_130 ) ;
V_132 += F_20 ( V_13 , & V_14 [ V_132 ] , V_2 -> V_57 ) ;
V_132 += F_9 ( V_13 , & V_14 [ V_132 ] ) ;
return V_132 ;
}
static inline T_1 F_55 ( const struct V_166 * V_167 )
{
T_1 V_157 = 0 ;
if ( V_167 -> V_168 )
V_157 |= V_169 ;
if ( V_167 -> V_170 )
V_157 |= V_171 ;
if ( V_167 -> V_172 )
V_157 |= V_173 | V_174 ;
if ( V_167 -> V_126 )
V_157 |= V_175 | V_176 ;
if ( V_167 -> V_177 )
V_157 |= V_178 | V_179 ;
V_157 |= ( ( ( V_167 -> V_180 - 1 ) & 0xf ) << V_181 ) ;
V_157 |= ( ( ( V_167 -> V_180 - 1 ) & 0xf ) << V_182 ) ;
V_157 |= ( V_167 -> V_183 << V_184 ) ;
V_157 |= ( V_167 -> V_183 << V_185 ) ;
V_157 |= ( V_167 -> V_186 << V_187 ) ;
V_157 |= ( V_167 -> V_188 << V_189 ) ;
V_157 |= ( V_167 -> V_190 << V_191 ) ;
return V_157 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_120 * V_4 )
{
struct V_136 * V_137 = V_2 -> V_5 ;
struct V_129 V_192 ;
unsigned long V_193 ;
unsigned V_122 ;
T_1 V_157 ;
int V_194 = 0 ;
if ( V_137 -> V_195 == V_196
|| V_137 -> V_197 . V_198 & ( 1 << V_2 -> V_86 ) ) {
F_41 ( V_2 -> V_5 -> V_89 . V_90 , L_29 ,
V_127 , __LINE__ ) ;
return - V_199 ;
}
if ( V_4 -> V_140 != V_143 &&
V_4 -> V_23 >= V_137 -> V_7 . V_200 ) {
F_41 ( V_2 -> V_5 -> V_89 . V_90 ,
L_30 ,
V_127 , __LINE__ , V_4 -> V_23 ) ;
return - V_165 ;
}
F_57 ( & V_137 -> V_201 , V_193 ) ;
if ( F_2 ( V_2 ) ) {
V_194 = - V_199 ;
goto V_202;
}
if ( ! F_4 ( V_2 ) )
V_4 -> V_125 . V_126 = 0 ;
else
V_4 -> V_125 . V_126 = 1 ;
V_157 = F_55 ( & V_4 -> V_125 ) ;
V_122 = V_2 -> V_3 [ 0 ] . V_4 == NULL ? 0 : 1 ;
V_192 . V_157 = V_157 ;
V_192 . V_4 = V_4 ;
V_194 = F_51 ( V_137 , 1 , V_2 , V_122 , & V_192 ) ;
if ( V_194 < 0 )
goto V_202;
if ( V_194 > V_137 -> V_203 / 2 ) {
F_41 ( V_137 -> V_89 . V_90 , L_31 ,
V_127 , __LINE__ , V_194 , V_137 -> V_203 / 2 ) ;
V_194 = - V_204 ;
goto V_202;
}
V_2 -> V_123 = V_122 ;
V_2 -> V_3 [ V_122 ] . V_4 = V_4 ;
F_51 ( V_137 , 0 , V_2 , V_122 , & V_192 ) ;
V_194 = 0 ;
V_202:
F_58 ( & V_137 -> V_201 , V_193 ) ;
return V_194 ;
}
static void F_59 ( struct V_120 * V_4 , enum V_205 V_206 )
{
struct V_207 * V_208 ;
unsigned long V_193 ;
if ( ! V_4 )
return;
V_208 = V_4 -> V_209 ;
if ( ! V_208 )
return;
F_57 ( & V_208 -> V_201 , V_193 ) ;
V_4 -> V_210 = V_211 ;
F_58 ( & V_208 -> V_201 , V_193 ) ;
F_60 ( & V_208 -> V_212 ) ;
}
static void F_61 ( unsigned long V_213 )
{
struct V_136 * V_137 = (struct V_136 * ) V_213 ;
unsigned long V_193 ;
int V_214 ;
F_57 ( & V_137 -> V_201 , V_193 ) ;
if ( V_137 -> V_197 . V_215 ) {
V_137 -> V_195 = V_196 ;
V_137 -> V_197 . V_216 = true ;
V_137 -> V_197 . V_215 = false ;
}
if ( V_137 -> V_197 . V_216 ) {
F_38 ( V_137 -> V_6 ) ;
V_137 -> V_197 . V_198 = ( 1 << V_137 -> V_7 . V_217 ) - 1 ;
V_137 -> V_197 . V_216 = false ;
}
for ( V_214 = 0 ; V_214 < V_137 -> V_7 . V_217 ; V_214 ++ ) {
if ( V_137 -> V_197 . V_198 & ( 1 << V_214 ) ) {
struct V_1 * V_2 = & V_137 -> V_218 [ V_214 ] ;
void T_4 * V_79 = V_137 -> V_80 ;
enum V_205 V_206 ;
F_38 ( V_2 ) ;
if ( F_30 ( V_79 + V_219 ) & ( 1 << V_2 -> V_86 ) )
V_206 = V_220 ;
else
V_206 = V_221 ;
F_58 ( & V_137 -> V_201 , V_193 ) ;
F_59 ( V_2 -> V_3 [ 1 - V_2 -> V_123 ] . V_4 , V_206 ) ;
F_59 ( V_2 -> V_3 [ V_2 -> V_123 ] . V_4 , V_206 ) ;
F_57 ( & V_137 -> V_201 , V_193 ) ;
V_2 -> V_3 [ 0 ] . V_4 = NULL ;
V_2 -> V_3 [ 1 ] . V_4 = NULL ;
V_2 -> V_124 = - 1 ;
V_137 -> V_197 . V_198 &= ~ ( 1 << V_214 ) ;
}
}
F_58 ( & V_137 -> V_201 , V_193 ) ;
return;
}
static int F_62 ( struct V_136 * V_137 )
{
struct V_120 * V_222 , * V_223 ;
unsigned long V_193 ;
void T_4 * V_79 ;
T_1 V_17 ;
int V_86 , V_57 , V_194 = 0 ;
V_79 = V_137 -> V_80 ;
F_57 ( & V_137 -> V_201 , V_193 ) ;
V_17 = F_30 ( V_79 + V_224 ) & 0x1 ;
if ( V_17 )
V_137 -> V_197 . V_216 = true ;
else
V_137 -> V_197 . V_216 = false ;
V_17 = F_30 ( V_79 + V_219 ) & ( ( 1 << V_137 -> V_7 . V_217 ) - 1 ) ;
V_137 -> V_197 . V_198 |= V_17 ;
if ( V_17 ) {
int V_214 = 0 ;
while ( V_214 < V_137 -> V_7 . V_217 ) {
if ( V_17 & ( 1 << V_214 ) ) {
F_41 ( V_137 -> V_89 . V_90 ,
L_32 ,
V_214 , F_30 ( V_79 + F_37 ( V_214 ) ) ,
F_30 ( V_79 + F_63 ( V_214 ) ) ) ;
F_38 ( & V_137 -> V_218 [ V_214 ] ) ;
}
V_214 ++ ;
}
}
V_17 = F_30 ( V_79 + V_225 ) ;
if ( V_137 -> V_7 . V_226 < 32
&& V_17 & ~ ( ( 1 << V_137 -> V_7 . V_226 ) - 1 ) ) {
V_137 -> V_197 . V_215 = true ;
F_35 ( V_137 -> V_89 . V_90 , L_33 , V_127 ,
__LINE__ ) ;
V_194 = 1 ;
goto V_227;
}
for ( V_57 = 0 ; V_57 < V_137 -> V_7 . V_226 ; V_57 ++ ) {
if ( V_17 & ( 1 << V_57 ) ) {
struct V_1 * V_2 ;
T_1 V_228 = F_30 ( V_79 + V_118 ) ;
int V_229 ;
if ( V_228 & ( 1 << V_57 ) )
F_33 ( 1 << V_57 , V_79 + V_230 ) ;
V_194 = 1 ;
V_86 = V_137 -> V_231 [ V_57 ] ;
V_2 = & V_137 -> V_218 [ V_86 ] ;
V_229 = V_2 -> V_124 ;
if ( V_229 == - 1 )
continue;
V_222 = V_2 -> V_3 [ V_229 ] . V_4 ;
V_2 -> V_3 [ V_229 ] . V_4 = NULL ;
V_2 -> V_124 = - 1 ;
F_42 ( V_2 ) ;
F_64 ( & V_222 -> V_232 , & V_137 -> V_233 ) ;
}
}
F_65 (descdone, tmp, &pl330->req_done, rqd) {
F_66 ( & V_222 -> V_232 ) ;
F_58 ( & V_137 -> V_201 , V_193 ) ;
F_59 ( V_222 , V_234 ) ;
F_57 ( & V_137 -> V_201 , V_193 ) ;
}
V_227:
F_58 ( & V_137 -> V_201 , V_193 ) ;
if ( V_137 -> V_197 . V_215
|| V_137 -> V_197 . V_216
|| V_137 -> V_197 . V_198 ) {
V_194 = 1 ;
F_60 ( & V_137 -> V_235 ) ;
}
return V_194 ;
}
static inline int F_67 ( struct V_1 * V_2 )
{
struct V_136 * V_137 = V_2 -> V_5 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_137 -> V_7 . V_226 ; V_57 ++ )
if ( V_137 -> V_231 [ V_57 ] == - 1 ) {
V_137 -> V_231 [ V_57 ] = V_2 -> V_86 ;
return V_57 ;
}
return - 1 ;
}
static bool F_68 ( const struct V_136 * V_137 , int V_214 )
{
return V_137 -> V_7 . V_236 & ( 1 << V_214 ) ;
}
static struct V_1 * F_69 ( struct V_136 * V_137 )
{
struct V_1 * V_2 = NULL ;
unsigned long V_193 ;
int V_237 , V_214 ;
if ( V_137 -> V_195 == V_196 )
return NULL ;
V_237 = V_137 -> V_7 . V_217 ;
F_57 ( & V_137 -> V_201 , V_193 ) ;
for ( V_214 = 0 ; V_214 < V_237 ; V_214 ++ ) {
V_2 = & V_137 -> V_218 [ V_214 ] ;
if ( ( V_2 -> free ) && ( ! F_4 ( V_2 ) ||
F_68 ( V_137 , V_214 ) ) ) {
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
F_58 ( & V_137 -> V_201 , V_193 ) ;
return V_2 ;
}
static inline void F_70 ( struct V_1 * V_2 , int V_57 )
{
struct V_136 * V_137 = V_2 -> V_5 ;
if ( V_57 >= 0 && V_57 < V_137 -> V_7 . V_226
&& V_137 -> V_231 [ V_57 ] == V_2 -> V_86 )
V_137 -> V_231 [ V_57 ] = - 1 ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_136 * V_137 ;
unsigned long V_193 ;
if ( ! V_2 || V_2 -> free )
return;
F_38 ( V_2 ) ;
F_59 ( V_2 -> V_3 [ 1 - V_2 -> V_123 ] . V_4 , V_221 ) ;
F_59 ( V_2 -> V_3 [ V_2 -> V_123 ] . V_4 , V_221 ) ;
V_137 = V_2 -> V_5 ;
F_57 ( & V_137 -> V_201 , V_193 ) ;
F_70 ( V_2 , V_2 -> V_57 ) ;
V_2 -> free = true ;
F_58 ( & V_137 -> V_201 , V_193 ) ;
}
static void F_72 ( struct V_136 * V_137 )
{
void T_4 * V_79 = V_137 -> V_80 ;
T_1 V_17 ;
V_17 = F_30 ( V_79 + V_238 ) >> V_239 ;
V_17 &= V_240 ;
V_137 -> V_7 . V_241 = 8 * ( 1 << V_17 ) ;
V_17 = F_30 ( V_79 + V_238 ) >> V_242 ;
V_17 &= V_243 ;
V_137 -> V_7 . V_244 = V_17 + 1 ;
V_17 = F_30 ( V_79 + V_245 ) >> V_246 ;
V_17 &= V_247 ;
V_17 += 1 ;
V_137 -> V_7 . V_217 = V_17 ;
V_17 = F_30 ( V_79 + V_245 ) ;
if ( V_17 & V_248 ) {
V_17 = ( V_17 >> V_249 ) & V_250 ;
V_17 += 1 ;
V_137 -> V_7 . V_200 = V_17 ;
V_137 -> V_7 . V_251 = F_30 ( V_79 + V_252 ) ;
} else {
V_137 -> V_7 . V_200 = 0 ;
}
V_17 = F_30 ( V_79 + V_245 ) ;
if ( V_17 & V_253 )
V_137 -> V_7 . V_8 |= V_9 ;
else
V_137 -> V_7 . V_8 &= ~ V_9 ;
V_17 = F_30 ( V_79 + V_245 ) >> V_254 ;
V_17 &= V_255 ;
V_17 += 1 ;
V_137 -> V_7 . V_226 = V_17 ;
V_137 -> V_7 . V_236 = F_30 ( V_79 + V_256 ) ;
}
static inline void F_73 ( struct V_1 * V_2 )
{
struct V_136 * V_137 = V_2 -> V_5 ;
V_2 -> V_3 [ 0 ] . V_163 = V_137 -> V_257
+ ( V_2 -> V_86 * V_137 -> V_203 ) ;
V_2 -> V_3 [ 0 ] . V_128 = V_137 -> V_258
+ ( V_2 -> V_86 * V_137 -> V_203 ) ;
V_2 -> V_3 [ 0 ] . V_4 = NULL ;
V_2 -> V_3 [ 1 ] . V_163 = V_2 -> V_3 [ 0 ] . V_163
+ V_137 -> V_203 / 2 ;
V_2 -> V_3 [ 1 ] . V_128 = V_2 -> V_3 [ 0 ] . V_128
+ V_137 -> V_203 / 2 ;
V_2 -> V_3 [ 1 ] . V_4 = NULL ;
V_2 -> V_124 = - 1 ;
}
static int F_74 ( struct V_136 * V_137 )
{
int V_237 = V_137 -> V_7 . V_217 ;
struct V_1 * V_2 ;
int V_214 ;
V_137 -> V_218 = F_75 ( ( 1 + V_237 ) * sizeof( * V_2 ) ,
V_259 ) ;
if ( ! V_137 -> V_218 )
return - V_204 ;
for ( V_214 = 0 ; V_214 < V_237 ; V_214 ++ ) {
V_2 = & V_137 -> V_218 [ V_214 ] ;
V_2 -> V_86 = V_214 ;
V_2 -> V_5 = V_137 ;
F_73 ( V_2 ) ;
V_2 -> free = true ;
}
V_2 = & V_137 -> V_218 [ V_237 ] ;
V_2 -> V_86 = V_237 ;
V_2 -> V_5 = V_137 ;
V_2 -> free = false ;
V_137 -> V_6 = V_2 ;
return 0 ;
}
static int F_76 ( struct V_136 * V_137 )
{
int V_237 = V_137 -> V_7 . V_217 ;
int V_194 ;
V_137 -> V_257 = F_77 ( V_137 -> V_89 . V_90 ,
V_237 * V_137 -> V_203 ,
& V_137 -> V_258 , V_259 ) ;
if ( ! V_137 -> V_257 ) {
F_35 ( V_137 -> V_89 . V_90 , L_34 ,
V_127 , __LINE__ ) ;
return - V_204 ;
}
V_194 = F_74 ( V_137 ) ;
if ( V_194 ) {
F_35 ( V_137 -> V_89 . V_90 , L_35 ,
V_127 , __LINE__ ) ;
F_78 ( V_137 -> V_89 . V_90 ,
V_237 * V_137 -> V_203 ,
V_137 -> V_257 , V_137 -> V_258 ) ;
return V_194 ;
}
return 0 ;
}
static int F_79 ( struct V_136 * V_137 )
{
void T_4 * V_79 ;
int V_214 , V_194 ;
V_79 = V_137 -> V_80 ;
if ( ( V_137 -> V_7 . V_10 & 0xfffff ) != V_260 ) {
F_35 ( V_137 -> V_89 . V_90 , L_36 ,
V_137 -> V_7 . V_10 ) ;
return - V_165 ;
}
F_72 ( V_137 ) ;
if ( V_137 -> V_7 . V_226 == 0 ) {
F_35 ( V_137 -> V_89 . V_90 , L_37 ,
V_127 , __LINE__ ) ;
return - V_165 ;
}
F_80 ( & V_137 -> V_201 ) ;
F_81 ( & V_137 -> V_233 ) ;
if ( ! V_137 -> V_203 )
V_137 -> V_203 = V_261 * 2 ;
for ( V_214 = 0 ; V_214 < V_137 -> V_7 . V_226 ; V_214 ++ )
V_137 -> V_231 [ V_214 ] = - 1 ;
V_194 = F_76 ( V_137 ) ;
if ( V_194 ) {
F_35 ( V_137 -> V_89 . V_90 , L_38 ) ;
return V_194 ;
}
F_82 ( & V_137 -> V_235 , F_61 , ( unsigned long ) V_137 ) ;
V_137 -> V_195 = V_262 ;
return 0 ;
}
static int F_83 ( struct V_136 * V_137 )
{
struct V_1 * V_2 ;
int V_214 ;
for ( V_214 = 0 ; V_214 < V_137 -> V_7 . V_217 ; V_214 ++ ) {
V_2 = & V_137 -> V_218 [ V_214 ] ;
F_71 ( V_2 ) ;
}
F_84 ( V_137 -> V_218 ) ;
return 0 ;
}
static void F_85 ( struct V_136 * V_137 )
{
V_137 -> V_195 = V_263 ;
F_86 ( & V_137 -> V_235 ) ;
F_83 ( V_137 ) ;
F_78 ( V_137 -> V_89 . V_90 ,
V_137 -> V_7 . V_217 * V_137 -> V_203 , V_137 -> V_257 ,
V_137 -> V_258 ) ;
}
static inline struct V_207 *
F_87 ( struct V_264 * V_265 )
{
if ( ! V_265 )
return NULL ;
return F_88 ( V_265 , struct V_207 , V_74 ) ;
}
static inline struct V_120 *
F_89 ( struct V_266 * V_267 )
{
return F_88 ( V_267 , struct V_120 , V_268 ) ;
}
static inline void F_90 ( struct V_207 * V_208 )
{
struct V_120 * V_4 ;
int V_194 ;
F_91 (desc, &pch->work_list, node) {
if ( V_4 -> V_210 == V_269 )
continue;
V_194 = F_56 ( V_208 -> V_270 , V_4 ) ;
if ( ! V_194 ) {
V_4 -> V_210 = V_269 ;
} else if ( V_194 == - V_199 ) {
break;
} else {
V_4 -> V_210 = V_211 ;
F_35 ( V_208 -> V_5 -> V_89 . V_90 , L_39 ,
V_127 , __LINE__ , V_4 -> V_268 . V_271 ) ;
F_60 ( & V_208 -> V_212 ) ;
}
}
}
static void F_92 ( unsigned long V_213 )
{
struct V_207 * V_208 = (struct V_207 * ) V_213 ;
struct V_120 * V_4 , * V_272 ;
unsigned long V_193 ;
bool V_273 = false ;
F_57 ( & V_208 -> V_201 , V_193 ) ;
F_65 (desc, _dt, &pch->work_list, node)
if ( V_4 -> V_210 == V_211 ) {
if ( ! V_208 -> V_274 )
F_93 ( & V_4 -> V_268 ) ;
F_94 ( & V_4 -> V_275 , & V_208 -> V_276 ) ;
}
F_90 ( V_208 ) ;
if ( F_95 ( & V_208 -> V_277 ) ) {
F_96 ( & V_208 -> V_270 -> V_5 -> V_201 ) ;
F_38 ( V_208 -> V_270 ) ;
F_97 ( & V_208 -> V_270 -> V_5 -> V_201 ) ;
V_273 = true ;
} else {
F_96 ( & V_208 -> V_270 -> V_5 -> V_201 ) ;
F_42 ( V_208 -> V_270 ) ;
F_97 ( & V_208 -> V_270 -> V_5 -> V_201 ) ;
}
while ( ! F_95 ( & V_208 -> V_276 ) ) {
T_5 V_278 ;
void * V_279 ;
V_4 = F_98 ( & V_208 -> V_276 ,
struct V_120 , V_275 ) ;
V_278 = V_4 -> V_268 . V_278 ;
V_279 = V_4 -> V_268 . V_279 ;
if ( V_208 -> V_274 ) {
V_4 -> V_210 = V_280 ;
F_94 ( & V_4 -> V_275 , & V_208 -> V_277 ) ;
if ( V_273 ) {
F_96 ( & V_208 -> V_270 -> V_5 -> V_201 ) ;
F_42 ( V_208 -> V_270 ) ;
F_97 ( & V_208 -> V_270 -> V_5 -> V_201 ) ;
V_273 = false ;
}
} else {
V_4 -> V_210 = FREE ;
F_94 ( & V_4 -> V_275 , & V_208 -> V_5 -> V_281 ) ;
}
F_99 ( & V_4 -> V_268 ) ;
if ( V_278 ) {
F_58 ( & V_208 -> V_201 , V_193 ) ;
V_278 ( V_279 ) ;
F_57 ( & V_208 -> V_201 , V_193 ) ;
}
}
F_58 ( & V_208 -> V_201 , V_193 ) ;
if ( V_273 ) {
F_100 ( V_208 -> V_5 -> V_89 . V_90 ) ;
F_101 ( V_208 -> V_5 -> V_89 . V_90 ) ;
}
}
bool F_102 ( struct V_264 * V_74 , void * V_282 )
{
T_2 * V_283 ;
if ( V_74 -> V_284 -> V_90 -> V_285 != & V_286 . V_287 )
return false ;
V_283 = V_74 -> V_288 ;
return * V_283 == ( unsigned long ) V_282 ;
}
static struct V_264 * F_103 ( struct V_289 * V_290 ,
struct V_291 * V_292 )
{
int V_293 = V_290 -> V_294 ;
struct V_136 * V_137 = V_292 -> V_295 ;
unsigned int V_296 ;
if ( ! V_137 )
return NULL ;
if ( V_293 != 1 )
return NULL ;
V_296 = V_290 -> args [ 0 ] ;
if ( V_296 >= V_137 -> V_297 )
return NULL ;
return F_104 ( & V_137 -> V_298 [ V_296 ] . V_74 ) ;
}
static int F_105 ( struct V_264 * V_74 )
{
struct V_207 * V_208 = F_87 ( V_74 ) ;
struct V_136 * V_137 = V_208 -> V_5 ;
unsigned long V_193 ;
F_57 ( & V_208 -> V_201 , V_193 ) ;
F_106 ( V_74 ) ;
V_208 -> V_274 = false ;
V_208 -> V_270 = F_69 ( V_137 ) ;
if ( ! V_208 -> V_270 ) {
F_58 ( & V_208 -> V_201 , V_193 ) ;
return - V_204 ;
}
F_82 ( & V_208 -> V_212 , F_92 , ( unsigned long ) V_208 ) ;
F_58 ( & V_208 -> V_201 , V_193 ) ;
return 1 ;
}
static int V_133 ( struct V_264 * V_74 ,
struct V_299 * V_300 )
{
struct V_207 * V_208 = F_87 ( V_74 ) ;
if ( V_300 -> V_301 == V_141 ) {
if ( V_300 -> V_161 )
V_208 -> V_302 = V_300 -> V_161 ;
if ( V_300 -> V_303 )
V_208 -> V_304 = F_107 ( V_300 -> V_303 ) ;
if ( V_300 -> V_305 )
V_208 -> V_306 = V_300 -> V_305 ;
} else if ( V_300 -> V_301 == V_142 ) {
if ( V_300 -> V_160 )
V_208 -> V_302 = V_300 -> V_160 ;
if ( V_300 -> V_307 )
V_208 -> V_304 = F_107 ( V_300 -> V_307 ) ;
if ( V_300 -> V_308 )
V_208 -> V_306 = V_300 -> V_308 ;
}
return 0 ;
}
static int F_108 ( struct V_264 * V_74 )
{
struct V_207 * V_208 = F_87 ( V_74 ) ;
struct V_120 * V_4 ;
unsigned long V_193 ;
struct V_136 * V_137 = V_208 -> V_5 ;
F_109 ( V_309 ) ;
F_110 ( V_137 -> V_89 . V_90 ) ;
F_57 ( & V_208 -> V_201 , V_193 ) ;
F_96 ( & V_137 -> V_201 ) ;
F_38 ( V_208 -> V_270 ) ;
F_97 ( & V_137 -> V_201 ) ;
V_208 -> V_270 -> V_3 [ 0 ] . V_4 = NULL ;
V_208 -> V_270 -> V_3 [ 1 ] . V_4 = NULL ;
V_208 -> V_270 -> V_124 = - 1 ;
F_91 (desc, &pch->submitted_list, node) {
V_4 -> V_210 = FREE ;
F_93 ( & V_4 -> V_268 ) ;
}
F_91 (desc, &pch->work_list , node) {
V_4 -> V_210 = FREE ;
F_93 ( & V_4 -> V_268 ) ;
}
F_111 ( & V_208 -> V_310 , & V_137 -> V_281 ) ;
F_111 ( & V_208 -> V_277 , & V_137 -> V_281 ) ;
F_111 ( & V_208 -> V_276 , & V_137 -> V_281 ) ;
F_58 ( & V_208 -> V_201 , V_193 ) ;
F_100 ( V_137 -> V_89 . V_90 ) ;
F_101 ( V_137 -> V_89 . V_90 ) ;
return 0 ;
}
static int F_112 ( struct V_264 * V_74 )
{
struct V_207 * V_208 = F_87 ( V_74 ) ;
struct V_136 * V_137 = V_208 -> V_5 ;
unsigned long V_193 ;
F_110 ( V_137 -> V_89 . V_90 ) ;
F_57 ( & V_208 -> V_201 , V_193 ) ;
F_96 ( & V_137 -> V_201 ) ;
F_38 ( V_208 -> V_270 ) ;
F_97 ( & V_137 -> V_201 ) ;
F_58 ( & V_208 -> V_201 , V_193 ) ;
F_100 ( V_137 -> V_89 . V_90 ) ;
F_101 ( V_137 -> V_89 . V_90 ) ;
return 0 ;
}
static void F_113 ( struct V_264 * V_74 )
{
struct V_207 * V_208 = F_87 ( V_74 ) ;
unsigned long V_193 ;
F_86 ( & V_208 -> V_212 ) ;
F_110 ( V_208 -> V_5 -> V_89 . V_90 ) ;
F_57 ( & V_208 -> V_201 , V_193 ) ;
F_71 ( V_208 -> V_270 ) ;
V_208 -> V_270 = NULL ;
if ( V_208 -> V_274 )
F_111 ( & V_208 -> V_277 , & V_208 -> V_5 -> V_281 ) ;
F_58 ( & V_208 -> V_201 , V_193 ) ;
F_100 ( V_208 -> V_5 -> V_89 . V_90 ) ;
F_101 ( V_208 -> V_5 -> V_89 . V_90 ) ;
}
static int F_114 ( struct V_207 * V_208 ,
struct V_120 * V_4 )
{
struct V_1 * V_2 = V_208 -> V_270 ;
struct V_136 * V_137 = V_208 -> V_5 ;
void T_4 * V_79 = V_2 -> V_5 -> V_80 ;
T_1 V_17 , V_75 ;
F_110 ( V_137 -> V_89 . V_90 ) ;
V_17 = V_75 = 0 ;
if ( V_4 -> V_125 . V_168 ) {
V_17 = F_30 ( V_79 + F_115 ( V_2 -> V_86 ) ) ;
V_75 = V_4 -> V_156 . V_160 ;
} else {
V_17 = F_30 ( V_79 + F_116 ( V_2 -> V_86 ) ) ;
V_75 = V_4 -> V_156 . V_161 ;
}
F_100 ( V_208 -> V_5 -> V_89 . V_90 ) ;
F_101 ( V_137 -> V_89 . V_90 ) ;
return V_17 - V_75 ;
}
static enum V_311
F_117 ( struct V_264 * V_74 , T_6 V_271 ,
struct V_312 * V_313 )
{
enum V_311 V_194 ;
unsigned long V_193 ;
struct V_120 * V_4 , * V_314 = NULL ;
struct V_207 * V_208 = F_87 ( V_74 ) ;
unsigned int V_315 , V_316 = 0 ;
V_194 = F_118 ( V_74 , V_271 , V_313 ) ;
if ( ! V_313 )
return V_194 ;
if ( V_194 == V_317 )
goto V_318;
F_57 ( & V_208 -> V_201 , V_193 ) ;
if ( V_208 -> V_270 -> V_124 != - 1 )
V_314 = V_208 -> V_270 -> V_3 [ V_208 -> V_270 -> V_124 ] . V_4 ;
F_91 (desc, &pch->work_list, node) {
if ( V_4 -> V_210 == V_211 )
V_315 = V_4 -> V_319 ;
else if ( V_314 && V_4 == V_314 )
V_315 =
F_114 ( V_208 , V_4 ) ;
else
V_315 = 0 ;
V_316 += V_4 -> V_319 - V_315 ;
if ( V_4 -> V_268 . V_271 == V_271 ) {
switch ( V_4 -> V_210 ) {
case V_211 :
V_194 = V_317 ;
break;
case V_280 :
case V_269 :
V_194 = V_320 ;
break;
default:
F_119 ( 1 ) ;
}
break;
}
if ( V_4 -> V_321 )
V_316 = 0 ;
}
F_58 ( & V_208 -> V_201 , V_193 ) ;
V_318:
F_120 ( V_313 , V_316 ) ;
return V_194 ;
}
static void F_121 ( struct V_264 * V_74 )
{
struct V_207 * V_208 = F_87 ( V_74 ) ;
unsigned long V_193 ;
F_57 ( & V_208 -> V_201 , V_193 ) ;
if ( F_95 ( & V_208 -> V_277 ) ) {
F_119 ( F_95 ( & V_208 -> V_310 ) ) ;
F_110 ( V_208 -> V_5 -> V_89 . V_90 ) ;
}
F_111 ( & V_208 -> V_310 , & V_208 -> V_277 ) ;
F_58 ( & V_208 -> V_201 , V_193 ) ;
F_92 ( ( unsigned long ) V_208 ) ;
}
static T_6 F_122 ( struct V_266 * V_267 )
{
struct V_120 * V_4 , * V_321 = F_89 ( V_267 ) ;
struct V_207 * V_208 = F_87 ( V_267 -> V_74 ) ;
T_6 V_271 ;
unsigned long V_193 ;
F_57 ( & V_208 -> V_201 , V_193 ) ;
while ( ! F_95 ( & V_321 -> V_275 ) ) {
V_4 = F_123 ( V_321 -> V_275 . V_322 , struct V_120 , V_275 ) ;
if ( V_208 -> V_274 ) {
V_4 -> V_268 . V_278 = V_321 -> V_268 . V_278 ;
V_4 -> V_268 . V_279 = V_321 -> V_268 . V_279 ;
}
V_4 -> V_321 = false ;
F_124 ( & V_4 -> V_268 ) ;
F_94 ( & V_4 -> V_275 , & V_208 -> V_310 ) ;
}
V_321 -> V_321 = true ;
V_271 = F_124 ( & V_321 -> V_268 ) ;
F_64 ( & V_321 -> V_275 , & V_208 -> V_310 ) ;
F_58 ( & V_208 -> V_201 , V_193 ) ;
return V_271 ;
}
static inline void F_125 ( struct V_120 * V_4 )
{
V_4 -> V_125 . V_190 = V_323 ;
V_4 -> V_125 . V_186 = V_324 ;
V_4 -> V_125 . V_188 = V_324 ;
V_4 -> V_268 . V_325 = F_122 ;
F_81 ( & V_4 -> V_275 ) ;
}
static int F_126 ( struct V_136 * V_137 , T_7 V_326 , int V_293 )
{
struct V_120 * V_4 ;
unsigned long V_193 ;
int V_214 ;
V_4 = F_127 ( V_293 , sizeof( * V_4 ) , V_326 ) ;
if ( ! V_4 )
return 0 ;
F_57 ( & V_137 -> V_327 , V_193 ) ;
for ( V_214 = 0 ; V_214 < V_293 ; V_214 ++ ) {
F_125 ( & V_4 [ V_214 ] ) ;
F_64 ( & V_4 [ V_214 ] . V_275 , & V_137 -> V_281 ) ;
}
F_58 ( & V_137 -> V_327 , V_193 ) ;
return V_293 ;
}
static struct V_120 * F_128 ( struct V_136 * V_137 )
{
struct V_120 * V_4 = NULL ;
unsigned long V_193 ;
F_57 ( & V_137 -> V_327 , V_193 ) ;
if ( ! F_95 ( & V_137 -> V_281 ) ) {
V_4 = F_123 ( V_137 -> V_281 . V_322 ,
struct V_120 , V_275 ) ;
F_129 ( & V_4 -> V_275 ) ;
V_4 -> V_210 = V_280 ;
V_4 -> V_268 . V_278 = NULL ;
}
F_58 ( & V_137 -> V_327 , V_193 ) ;
return V_4 ;
}
static struct V_120 * F_130 ( struct V_207 * V_208 )
{
struct V_136 * V_137 = V_208 -> V_5 ;
T_2 * V_283 = V_208 -> V_74 . V_288 ;
struct V_120 * V_4 ;
V_4 = F_128 ( V_137 ) ;
if ( ! V_4 ) {
if ( ! F_126 ( V_137 , V_328 , 1 ) )
return NULL ;
V_4 = F_128 ( V_137 ) ;
if ( ! V_4 ) {
F_35 ( V_208 -> V_5 -> V_89 . V_90 ,
L_40 , V_127 , __LINE__ ) ;
return NULL ;
}
}
V_4 -> V_209 = V_208 ;
V_4 -> V_268 . V_271 = 0 ;
F_131 ( & V_4 -> V_268 ) ;
V_4 -> V_23 = V_283 ? V_208 -> V_74 . V_296 : 0 ;
V_4 -> V_125 . V_7 = & V_208 -> V_5 -> V_7 ;
F_132 ( & V_4 -> V_268 , & V_208 -> V_74 ) ;
return V_4 ;
}
static inline void F_133 ( struct V_154 * V_156 ,
T_8 V_47 , T_8 V_329 , T_9 V_330 )
{
V_156 -> V_159 = V_330 ;
V_156 -> V_161 = V_47 ;
V_156 -> V_160 = V_329 ;
}
static struct V_120 *
F_134 ( struct V_207 * V_208 , T_8 V_47 ,
T_8 V_329 , T_9 V_330 )
{
struct V_120 * V_4 = F_130 ( V_208 ) ;
if ( ! V_4 ) {
F_35 ( V_208 -> V_5 -> V_89 . V_90 , L_41 ,
V_127 , __LINE__ ) ;
return NULL ;
}
F_133 ( & V_4 -> V_156 , V_47 , V_329 , V_330 ) ;
return V_4 ;
}
static inline int F_135 ( struct V_120 * V_4 , T_9 V_330 )
{
struct V_207 * V_208 = V_4 -> V_209 ;
struct V_136 * V_137 = V_208 -> V_5 ;
int V_306 ;
V_306 = V_137 -> V_7 . V_241 / 8 ;
V_306 *= V_137 -> V_7 . V_244 / V_137 -> V_7 . V_217 ;
V_306 >>= V_4 -> V_125 . V_183 ;
if ( V_306 > 16 )
V_306 = 16 ;
while ( V_306 > 1 ) {
if ( ! ( V_330 % ( V_306 << V_4 -> V_125 . V_183 ) ) )
break;
V_306 -- ;
}
return V_306 ;
}
static struct V_266 * F_136 (
struct V_264 * V_74 , T_8 V_331 , T_9 V_330 ,
T_9 V_332 , enum V_333 V_301 ,
unsigned long V_193 )
{
struct V_120 * V_4 = NULL , * V_334 = NULL ;
struct V_207 * V_208 = F_87 ( V_74 ) ;
struct V_136 * V_137 = V_208 -> V_5 ;
unsigned int V_214 ;
T_8 V_47 ;
T_8 V_329 ;
if ( V_330 % V_332 != 0 )
return NULL ;
if ( ! F_137 ( V_301 ) ) {
F_35 ( V_208 -> V_5 -> V_89 . V_90 , L_42 ,
V_127 , __LINE__ ) ;
return NULL ;
}
for ( V_214 = 0 ; V_214 < V_330 / V_332 ; V_214 ++ ) {
V_4 = F_130 ( V_208 ) ;
if ( ! V_4 ) {
F_35 ( V_208 -> V_5 -> V_89 . V_90 , L_41 ,
V_127 , __LINE__ ) ;
if ( ! V_334 )
return NULL ;
F_57 ( & V_137 -> V_327 , V_193 ) ;
while ( ! F_95 ( & V_334 -> V_275 ) ) {
V_4 = F_123 ( V_334 -> V_275 . V_322 ,
struct V_120 , V_275 ) ;
F_94 ( & V_4 -> V_275 , & V_137 -> V_281 ) ;
}
F_94 ( & V_334 -> V_275 , & V_137 -> V_281 ) ;
F_58 ( & V_137 -> V_327 , V_193 ) ;
return NULL ;
}
switch ( V_301 ) {
case V_141 :
V_4 -> V_125 . V_168 = 1 ;
V_4 -> V_125 . V_170 = 0 ;
V_329 = V_331 ;
V_47 = V_208 -> V_302 ;
break;
case V_142 :
V_4 -> V_125 . V_168 = 0 ;
V_4 -> V_125 . V_170 = 1 ;
V_329 = V_208 -> V_302 ;
V_47 = V_331 ;
break;
default:
break;
}
V_4 -> V_140 = V_301 ;
V_4 -> V_125 . V_183 = V_208 -> V_304 ;
V_4 -> V_125 . V_180 = 1 ;
V_4 -> V_319 = V_332 ;
F_133 ( & V_4 -> V_156 , V_47 , V_329 , V_332 ) ;
if ( ! V_334 )
V_334 = V_4 ;
else
F_64 ( & V_4 -> V_275 , & V_334 -> V_275 ) ;
V_331 += V_332 ;
}
if ( ! V_4 )
return NULL ;
V_208 -> V_274 = true ;
V_4 -> V_268 . V_193 = V_193 ;
return & V_4 -> V_268 ;
}
static struct V_266 *
F_138 ( struct V_264 * V_74 , T_8 V_47 ,
T_8 V_329 , T_9 V_330 , unsigned long V_193 )
{
struct V_120 * V_4 ;
struct V_207 * V_208 = F_87 ( V_74 ) ;
struct V_136 * V_137 ;
int V_335 ;
if ( F_139 ( ! V_208 || ! V_330 ) )
return NULL ;
V_137 = V_208 -> V_5 ;
V_4 = F_134 ( V_208 , V_47 , V_329 , V_330 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_125 . V_168 = 1 ;
V_4 -> V_125 . V_170 = 1 ;
V_4 -> V_140 = V_143 ;
V_335 = V_137 -> V_7 . V_241 / 8 ;
while ( ( V_329 | V_47 | V_330 ) & ( V_335 - 1 ) )
V_335 /= 2 ;
V_4 -> V_125 . V_183 = 0 ;
while ( V_335 != ( 1 << V_4 -> V_125 . V_183 ) )
V_4 -> V_125 . V_183 ++ ;
if ( V_4 -> V_125 . V_183 * 8 < V_137 -> V_7 . V_241 )
V_4 -> V_125 . V_180 = 1 ;
V_4 -> V_125 . V_180 = F_135 ( V_4 , V_330 ) ;
V_4 -> V_319 = V_330 ;
V_4 -> V_268 . V_193 = V_193 ;
return & V_4 -> V_268 ;
}
static void F_140 ( struct V_136 * V_137 ,
struct V_120 * V_334 )
{
unsigned long V_193 ;
struct V_120 * V_4 ;
if ( ! V_334 )
return;
F_57 ( & V_137 -> V_327 , V_193 ) ;
while ( ! F_95 ( & V_334 -> V_275 ) ) {
V_4 = F_123 ( V_334 -> V_275 . V_322 ,
struct V_120 , V_275 ) ;
F_94 ( & V_4 -> V_275 , & V_137 -> V_281 ) ;
}
F_94 ( & V_334 -> V_275 , & V_137 -> V_281 ) ;
F_58 ( & V_137 -> V_327 , V_193 ) ;
}
static struct V_266 *
F_141 ( struct V_264 * V_74 , struct V_336 * V_337 ,
unsigned int V_338 , enum V_333 V_301 ,
unsigned long V_326 , void * V_339 )
{
struct V_120 * V_334 , * V_4 = NULL ;
struct V_207 * V_208 = F_87 ( V_74 ) ;
struct V_336 * V_340 ;
int V_214 ;
T_8 V_75 ;
if ( F_139 ( ! V_208 || ! V_337 || ! V_338 ) )
return NULL ;
V_75 = V_208 -> V_302 ;
V_334 = NULL ;
F_142 (sgl, sg, sg_len, i) {
V_4 = F_130 ( V_208 ) ;
if ( ! V_4 ) {
struct V_136 * V_137 = V_208 -> V_5 ;
F_35 ( V_208 -> V_5 -> V_89 . V_90 ,
L_41 ,
V_127 , __LINE__ ) ;
F_140 ( V_137 , V_334 ) ;
return NULL ;
}
if ( ! V_334 )
V_334 = V_4 ;
else
F_64 ( & V_4 -> V_275 , & V_334 -> V_275 ) ;
if ( V_301 == V_141 ) {
V_4 -> V_125 . V_168 = 1 ;
V_4 -> V_125 . V_170 = 0 ;
F_133 ( & V_4 -> V_156 ,
V_75 , F_143 ( V_340 ) , F_144 ( V_340 ) ) ;
} else {
V_4 -> V_125 . V_168 = 0 ;
V_4 -> V_125 . V_170 = 1 ;
F_133 ( & V_4 -> V_156 ,
F_143 ( V_340 ) , V_75 , F_144 ( V_340 ) ) ;
}
V_4 -> V_125 . V_183 = V_208 -> V_304 ;
V_4 -> V_125 . V_180 = 1 ;
V_4 -> V_140 = V_301 ;
V_4 -> V_319 = F_144 ( V_340 ) ;
}
V_4 -> V_268 . V_193 = V_326 ;
return & V_4 -> V_268 ;
}
static T_10 F_145 ( int V_341 , void * V_213 )
{
if ( F_62 ( V_213 ) )
return V_342 ;
else
return V_343 ;
}
static int T_11 F_146 ( struct V_284 * V_90 )
{
struct V_344 * V_345 = F_147 ( V_90 ) ;
F_148 ( V_90 ) ;
if ( ! F_149 ( V_90 ) ) {
F_150 ( V_345 ) ;
}
F_151 ( V_345 ) ;
return 0 ;
}
static int T_11 F_152 ( struct V_284 * V_90 )
{
struct V_344 * V_345 = F_147 ( V_90 ) ;
int V_194 ;
V_194 = F_153 ( V_345 ) ;
if ( V_194 )
return V_194 ;
if ( ! F_149 ( V_90 ) )
V_194 = F_154 ( V_345 ) ;
F_155 ( V_90 ) ;
return V_194 ;
}
static int
F_156 ( struct V_344 * V_346 , const struct V_347 * V_86 )
{
struct V_348 * V_349 ;
struct V_133 * V_7 ;
struct V_136 * V_137 ;
struct V_207 * V_208 , * V_350 ;
struct V_351 * V_352 ;
struct V_353 * V_354 ;
int V_214 , V_194 , V_341 ;
int V_217 ;
struct V_355 * V_356 = V_346 -> V_90 . V_357 ;
V_349 = F_157 ( & V_346 -> V_90 ) ;
V_194 = F_158 ( & V_346 -> V_90 , F_159 ( 32 ) ) ;
if ( V_194 )
return V_194 ;
V_137 = F_160 ( & V_346 -> V_90 , sizeof( * V_137 ) , V_259 ) ;
if ( ! V_137 )
return - V_204 ;
V_352 = & V_137 -> V_89 ;
V_352 -> V_90 = & V_346 -> V_90 ;
V_137 -> V_203 = V_349 ? V_349 -> V_358 : 0 ;
for ( V_214 = 0 ; V_214 < F_161 ( V_359 ) ; V_214 ++ )
if ( F_162 ( V_356 , V_359 [ V_214 ] . V_360 ) )
V_137 -> V_138 |= V_359 [ V_214 ] . V_86 ;
V_354 = & V_346 -> V_354 ;
V_137 -> V_80 = F_163 ( & V_346 -> V_90 , V_354 ) ;
if ( F_164 ( V_137 -> V_80 ) )
return F_165 ( V_137 -> V_80 ) ;
F_166 ( V_346 , V_137 ) ;
for ( V_214 = 0 ; V_214 < V_361 ; V_214 ++ ) {
V_341 = V_346 -> V_341 [ V_214 ] ;
if ( V_341 ) {
V_194 = F_167 ( & V_346 -> V_90 , V_341 ,
F_145 , 0 ,
F_168 ( & V_346 -> V_90 ) , V_137 ) ;
if ( V_194 )
return V_194 ;
} else {
break;
}
}
V_7 = & V_137 -> V_7 ;
V_7 -> V_10 = V_346 -> V_362 ;
V_194 = F_79 ( V_137 ) ;
if ( V_194 )
return V_194 ;
F_81 ( & V_137 -> V_281 ) ;
F_80 ( & V_137 -> V_327 ) ;
if ( ! F_126 ( V_137 , V_259 , V_363 ) )
F_169 ( & V_346 -> V_90 , L_43 ) ;
F_81 ( & V_352 -> V_218 ) ;
if ( V_349 )
V_217 = F_170 ( int , V_349 -> V_364 , V_7 -> V_217 ) ;
else
V_217 = F_170 ( int , V_7 -> V_200 , V_7 -> V_217 ) ;
V_137 -> V_297 = V_217 ;
V_137 -> V_298 = F_75 ( V_217 * sizeof( * V_208 ) , V_259 ) ;
if ( ! V_137 -> V_298 ) {
V_194 = - V_204 ;
goto V_365;
}
for ( V_214 = 0 ; V_214 < V_217 ; V_214 ++ ) {
V_208 = & V_137 -> V_298 [ V_214 ] ;
if ( ! V_346 -> V_90 . V_357 )
V_208 -> V_74 . V_288 = V_349 ? & V_349 -> V_283 [ V_214 ] : NULL ;
else
V_208 -> V_74 . V_288 = V_346 -> V_90 . V_357 ;
F_81 ( & V_208 -> V_310 ) ;
F_81 ( & V_208 -> V_277 ) ;
F_81 ( & V_208 -> V_276 ) ;
F_80 ( & V_208 -> V_201 ) ;
V_208 -> V_270 = NULL ;
V_208 -> V_74 . V_284 = V_352 ;
V_208 -> V_5 = V_137 ;
F_64 ( & V_208 -> V_74 . V_355 , & V_352 -> V_218 ) ;
}
if ( V_349 ) {
V_352 -> V_366 = V_349 -> V_366 ;
} else {
F_171 ( V_367 , V_352 -> V_366 ) ;
if ( V_7 -> V_200 ) {
F_171 ( V_368 , V_352 -> V_366 ) ;
F_171 ( V_369 , V_352 -> V_366 ) ;
F_171 ( V_370 , V_352 -> V_366 ) ;
}
}
V_352 -> V_371 = F_105 ;
V_352 -> V_372 = F_113 ;
V_352 -> V_373 = F_138 ;
V_352 -> V_374 = F_136 ;
V_352 -> V_375 = F_117 ;
V_352 -> V_376 = F_141 ;
V_352 -> V_377 = V_133 ;
V_352 -> V_378 = F_112 ;
V_352 -> V_379 = F_108 ;
V_352 -> V_380 = F_121 ;
V_352 -> V_381 = V_382 ;
V_352 -> V_383 = V_382 ;
V_352 -> V_384 = F_172 ( V_142 ) | F_172 ( V_141 ) ;
V_352 -> V_385 = V_386 ;
V_352 -> V_387 = ( ( V_137 -> V_138 & V_139 ) ?
1 : V_388 ) ;
V_194 = F_173 ( V_352 ) ;
if ( V_194 ) {
F_35 ( & V_346 -> V_90 , L_44 ) ;
goto V_389;
}
if ( V_346 -> V_90 . V_357 ) {
V_194 = F_174 ( V_346 -> V_90 . V_357 ,
F_103 , V_137 ) ;
if ( V_194 ) {
F_35 ( & V_346 -> V_90 ,
L_45 ) ;
}
}
V_346 -> V_90 . V_390 = & V_137 -> V_390 ;
V_194 = F_175 ( & V_346 -> V_90 , 1900800 ) ;
if ( V_194 )
F_35 ( & V_346 -> V_90 , L_46 ) ;
F_41 ( & V_346 -> V_90 ,
L_47 , V_346 -> V_362 ) ;
F_41 ( & V_346 -> V_90 ,
L_48 ,
V_7 -> V_244 , V_7 -> V_241 / 8 , V_7 -> V_217 ,
V_7 -> V_200 , V_7 -> V_226 ) ;
F_176 ( & V_346 -> V_90 ) ;
F_177 ( & V_346 -> V_90 ) ;
F_178 ( & V_346 -> V_90 , V_391 ) ;
F_100 ( & V_346 -> V_90 ) ;
F_101 ( & V_346 -> V_90 ) ;
return 0 ;
V_389:
F_65 (pch, _p, &pl330->ddma.channels,
chan.device_node) {
F_66 ( & V_208 -> V_74 . V_355 ) ;
if ( V_208 -> V_270 ) {
F_108 ( & V_208 -> V_74 ) ;
F_113 ( & V_208 -> V_74 ) ;
}
}
V_365:
F_85 ( V_137 ) ;
return V_194 ;
}
static int F_179 ( struct V_344 * V_346 )
{
struct V_136 * V_137 = F_180 ( V_346 ) ;
struct V_207 * V_208 , * V_350 ;
int V_214 , V_341 ;
F_181 ( V_137 -> V_89 . V_90 ) ;
if ( V_346 -> V_90 . V_357 )
F_182 ( V_346 -> V_90 . V_357 ) ;
for ( V_214 = 0 ; V_214 < V_361 ; V_214 ++ ) {
V_341 = V_346 -> V_341 [ V_214 ] ;
F_183 ( & V_346 -> V_90 , V_341 , V_137 ) ;
}
F_184 ( & V_137 -> V_89 ) ;
F_65 (pch, _p, &pl330->ddma.channels,
chan.device_node) {
F_66 ( & V_208 -> V_74 . V_355 ) ;
if ( V_208 -> V_270 ) {
F_108 ( & V_208 -> V_74 ) ;
F_113 ( & V_208 -> V_74 ) ;
}
}
F_85 ( V_137 ) ;
return 0 ;
}
