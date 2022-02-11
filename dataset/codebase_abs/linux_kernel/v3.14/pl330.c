static inline void F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
if ( V_2 && V_2 -> V_5 )
V_2 -> V_5 ( V_2 -> V_6 , V_4 ) ;
}
static inline bool F_2 ( struct V_7 * V_8 )
{
return ( F_3 ( & V_8 -> V_9 [ 0 ] ) && F_3 ( & V_8 -> V_9 [ 1 ] ) )
? true : false ;
}
static inline bool F_4 ( struct V_7 * V_8 )
{
return ( F_3 ( & V_8 -> V_9 [ 0 ] ) || F_3 ( & V_8 -> V_9 [ 1 ] ) )
? false : true ;
}
static inline bool F_5 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
if ( V_8 -> V_13 == V_11 -> V_14 -> V_15 . V_16 )
return true ;
else
return false ;
}
static inline bool F_6 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
return ( V_11 -> V_14 -> V_15 . V_17 & V_18 ) ? true : false ;
}
static inline T_1 F_7 ( T_1 V_19 )
{
return ( V_19 >> V_20 ) & V_21 ;
}
static inline T_1 F_8 ( unsigned V_22 , T_2 V_23 [] ,
enum V_24 V_25 , T_3 V_26 )
{
if ( V_22 )
return V_27 ;
V_23 [ 0 ] = V_28 ;
V_23 [ 0 ] |= ( V_25 << 1 ) ;
* ( ( T_3 * ) & V_23 [ 1 ] ) = V_26 ;
F_9 ( V_27 , L_1 ,
V_25 == 1 ? L_2 : L_3 , V_26 ) ;
return V_27 ;
}
static inline T_1 F_10 ( unsigned V_22 , T_2 V_23 [] )
{
if ( V_22 )
return V_29 ;
V_23 [ 0 ] = V_30 ;
F_9 ( V_29 , L_4 ) ;
return V_29 ;
}
static inline T_1 F_11 ( unsigned V_22 , T_2 V_23 [] , T_2 V_31 )
{
if ( V_22 )
return V_32 ;
V_23 [ 0 ] = V_33 ;
V_31 &= 0x1f ;
V_31 <<= 3 ;
V_23 [ 1 ] = V_31 ;
F_9 ( V_32 , L_5 , V_31 >> 3 ) ;
return V_32 ;
}
static inline T_1 F_12 ( unsigned V_22 , T_2 V_23 [] , enum V_34 V_35 )
{
if ( V_22 )
return V_36 ;
V_23 [ 0 ] = V_37 ;
if ( V_35 == V_38 )
V_23 [ 0 ] |= ( 0 << 1 ) | ( 1 << 0 ) ;
else if ( V_35 == V_39 )
V_23 [ 0 ] |= ( 1 << 1 ) | ( 1 << 0 ) ;
F_9 ( V_36 , L_6 ,
V_35 == V_38 ? 'S' : ( V_35 == V_39 ? 'B' : 'A' ) ) ;
return V_36 ;
}
static inline T_1 F_13 ( unsigned V_22 , T_2 V_23 [] ,
enum V_34 V_35 , T_2 V_31 )
{
if ( V_22 )
return V_40 ;
V_23 [ 0 ] = V_41 ;
if ( V_35 == V_39 )
V_23 [ 0 ] |= ( 1 << 1 ) ;
V_31 &= 0x1f ;
V_31 <<= 3 ;
V_23 [ 1 ] = V_31 ;
F_9 ( V_40 , L_7 ,
V_35 == V_38 ? 'S' : 'B' , V_31 >> 3 ) ;
return V_40 ;
}
static inline T_1 F_14 ( unsigned V_22 , T_2 V_23 [] ,
unsigned V_42 , T_2 V_43 )
{
if ( V_22 )
return V_44 ;
V_23 [ 0 ] = V_45 ;
if ( V_42 )
V_23 [ 0 ] |= ( 1 << 1 ) ;
V_43 -- ;
V_23 [ 1 ] = V_43 ;
F_9 ( V_44 , L_8 , V_42 ? '1' : '0' , V_43 ) ;
return V_44 ;
}
static inline T_1 F_15 ( unsigned V_22 , T_2 V_23 [] ,
const struct V_46 * V_47 )
{
enum V_34 V_35 = V_47 -> V_35 ;
bool V_48 = V_47 -> V_48 ;
unsigned V_42 = V_47 -> V_42 ;
T_2 V_49 = V_47 -> V_49 ;
if ( V_22 )
return V_50 ;
V_23 [ 0 ] = V_51 ;
if ( V_42 )
V_23 [ 0 ] |= ( 1 << 2 ) ;
if ( ! V_48 )
V_23 [ 0 ] |= ( 1 << 4 ) ;
if ( V_35 == V_38 )
V_23 [ 0 ] |= ( 0 << 1 ) | ( 1 << 0 ) ;
else if ( V_35 == V_39 )
V_23 [ 0 ] |= ( 1 << 1 ) | ( 1 << 0 ) ;
V_23 [ 1 ] = V_49 ;
F_9 ( V_50 , L_9 ,
V_48 ? L_10 : L_11 ,
V_35 == V_38 ? 'S' : ( V_35 == V_39 ? 'B' : 'A' ) ,
V_42 ? '1' : '0' ,
V_49 ) ;
return V_50 ;
}
static inline T_1 F_16 ( unsigned V_22 , T_2 V_23 [] )
{
if ( V_22 )
return V_52 ;
V_23 [ 0 ] = V_53 ;
return V_52 ;
}
static inline T_1 F_17 ( unsigned V_22 , T_2 V_23 [] ,
enum V_54 V_55 , T_1 V_26 )
{
if ( V_22 )
return V_56 ;
V_23 [ 0 ] = V_57 ;
V_23 [ 1 ] = V_55 ;
* ( ( T_1 * ) & V_23 [ 2 ] ) = V_26 ;
F_9 ( V_56 , L_12 ,
V_55 == V_58 ? L_13 : ( V_55 == V_59 ? L_14 : L_15 ) , V_26 ) ;
return V_56 ;
}
static inline T_1 F_18 ( unsigned V_22 , T_2 V_23 [] )
{
if ( V_22 )
return V_60 ;
V_23 [ 0 ] = V_61 ;
F_9 ( V_60 , L_16 ) ;
return V_60 ;
}
static inline T_1 F_19 ( unsigned V_22 , T_2 V_23 [] )
{
if ( V_22 )
return V_62 ;
V_23 [ 0 ] = V_63 ;
F_9 ( V_62 , L_17 ) ;
return V_62 ;
}
static inline T_1 F_20 ( unsigned V_22 , T_2 V_23 [] , T_2 V_64 )
{
if ( V_22 )
return V_65 ;
V_23 [ 0 ] = V_66 ;
V_64 &= 0x1f ;
V_64 <<= 3 ;
V_23 [ 1 ] = V_64 ;
F_9 ( V_65 , L_18 , V_64 >> 3 ) ;
return V_65 ;
}
static inline T_1 F_21 ( unsigned V_22 , T_2 V_23 [] , enum V_34 V_35 )
{
if ( V_22 )
return V_67 ;
V_23 [ 0 ] = V_68 ;
if ( V_35 == V_38 )
V_23 [ 0 ] |= ( 0 << 1 ) | ( 1 << 0 ) ;
else if ( V_35 == V_39 )
V_23 [ 0 ] |= ( 1 << 1 ) | ( 1 << 0 ) ;
F_9 ( V_67 , L_19 ,
V_35 == V_38 ? 'S' : ( V_35 == V_39 ? 'B' : 'A' ) ) ;
return V_67 ;
}
static inline T_1 F_22 ( unsigned V_22 , T_2 V_23 [] ,
enum V_34 V_35 , T_2 V_31 )
{
if ( V_22 )
return V_69 ;
V_23 [ 0 ] = V_70 ;
if ( V_35 == V_39 )
V_23 [ 0 ] |= ( 1 << 1 ) ;
V_31 &= 0x1f ;
V_31 <<= 3 ;
V_23 [ 1 ] = V_31 ;
F_9 ( V_69 , L_20 ,
V_35 == V_38 ? 'S' : 'B' , V_31 >> 3 ) ;
return V_69 ;
}
static inline T_1 F_23 ( unsigned V_22 , T_2 V_23 [] )
{
if ( V_22 )
return V_71 ;
V_23 [ 0 ] = V_72 ;
F_9 ( V_71 , L_21 ) ;
return V_71 ;
}
static inline T_1 F_24 ( unsigned V_22 , T_2 V_23 [] , T_2 V_64 ,
unsigned V_73 )
{
if ( V_22 )
return V_74 ;
V_23 [ 0 ] = V_75 ;
V_64 &= 0x1f ;
V_64 <<= 3 ;
V_23 [ 1 ] = V_64 ;
if ( V_73 )
V_23 [ 1 ] |= ( 1 << 1 ) ;
F_9 ( V_74 , L_22 ,
V_64 >> 3 , V_73 ? L_23 : L_24 ) ;
return V_74 ;
}
static inline T_1 F_25 ( unsigned V_22 , T_2 V_23 [] ,
enum V_34 V_35 , T_2 V_31 )
{
if ( V_22 )
return V_76 ;
V_23 [ 0 ] = V_77 ;
if ( V_35 == V_38 )
V_23 [ 0 ] |= ( 0 << 1 ) | ( 0 << 0 ) ;
else if ( V_35 == V_39 )
V_23 [ 0 ] |= ( 1 << 1 ) | ( 0 << 0 ) ;
else
V_23 [ 0 ] |= ( 0 << 1 ) | ( 1 << 0 ) ;
V_31 &= 0x1f ;
V_31 <<= 3 ;
V_23 [ 1 ] = V_31 ;
F_9 ( V_76 , L_25 ,
V_35 == V_38 ? 'S' : ( V_35 == V_39 ? 'B' : 'P' ) , V_31 >> 3 ) ;
return V_76 ;
}
static inline T_1 F_26 ( unsigned V_22 , T_2 V_23 [] )
{
if ( V_22 )
return V_78 ;
V_23 [ 0 ] = V_79 ;
F_9 ( V_78 , L_26 ) ;
return V_78 ;
}
static inline T_1 F_27 ( unsigned V_22 , T_2 V_23 [] ,
const struct V_80 * V_47 )
{
T_2 V_81 = V_47 -> V_81 ;
T_1 V_82 = V_47 -> V_82 ;
unsigned V_83 = V_47 -> V_83 ;
if ( V_22 )
return V_84 ;
V_23 [ 0 ] = V_85 ;
V_23 [ 0 ] |= ( V_83 << 1 ) ;
V_23 [ 1 ] = V_81 & 0x7 ;
* ( ( T_1 * ) & V_23 [ 2 ] ) = V_82 ;
return V_84 ;
}
static bool F_28 ( struct V_7 * V_8 )
{
void T_4 * V_86 = V_8 -> V_12 -> V_14 -> V_87 ;
unsigned long V_88 = F_29 ( 5 ) ;
do {
if ( ! ( F_30 ( V_86 + V_89 ) & V_90 ) )
break;
F_31 () ;
} while ( -- V_88 );
if ( ! V_88 )
return true ;
return false ;
}
static inline void F_32 ( struct V_7 * V_8 ,
T_2 V_91 [] , bool V_92 )
{
void T_4 * V_86 = V_8 -> V_12 -> V_14 -> V_87 ;
T_1 V_26 ;
V_26 = ( V_91 [ 0 ] << 16 ) | ( V_91 [ 1 ] << 24 ) ;
if ( ! V_92 ) {
V_26 |= ( 1 << 0 ) ;
V_26 |= ( V_8 -> V_13 << 8 ) ;
}
F_33 ( V_26 , V_86 + V_93 ) ;
V_26 = * ( ( T_1 * ) & V_91 [ 2 ] ) ;
F_33 ( V_26 , V_86 + V_94 ) ;
if ( F_28 ( V_8 ) ) {
F_34 ( V_8 -> V_12 -> V_14 -> V_95 , L_27 ) ;
return;
}
F_33 ( 0 , V_86 + V_96 ) ;
}
static void F_35 ( struct V_7 * V_8 , int V_97 )
{
struct V_98 * V_9 = & V_8 -> V_9 [ V_97 ] ;
F_10 ( 0 , V_9 -> V_99 ) ;
V_9 -> V_100 = 0 ;
V_8 -> V_101 = - 1 ;
}
static inline T_1 F_36 ( struct V_7 * V_8 )
{
void T_4 * V_86 = V_8 -> V_12 -> V_14 -> V_87 ;
T_1 V_26 ;
if ( F_5 ( V_8 ) )
V_26 = F_30 ( V_86 + V_102 ) & 0xf ;
else
V_26 = F_30 ( V_86 + F_37 ( V_8 -> V_13 ) ) & 0xf ;
switch ( V_26 ) {
case V_103 :
return V_104 ;
case V_105 :
return V_106 ;
case V_107 :
return V_108 ;
case V_109 :
return V_110 ;
case V_111 :
return V_112 ;
case V_113 :
return V_114 ;
case V_115 :
if ( F_5 ( V_8 ) )
return V_116 ;
else
return V_117 ;
case V_118 :
if ( F_5 ( V_8 ) )
return V_116 ;
else
return V_119 ;
case V_120 :
if ( F_5 ( V_8 ) )
return V_116 ;
else
return V_121 ;
case V_122 :
if ( F_5 ( V_8 ) )
return V_116 ;
else
return V_123 ;
case V_124 :
if ( F_5 ( V_8 ) )
return V_116 ;
else
return V_125 ;
case V_126 :
if ( F_5 ( V_8 ) )
return V_116 ;
else
return V_127 ;
default:
return V_116 ;
}
}
static void F_38 ( struct V_7 * V_8 )
{
void T_4 * V_86 = V_8 -> V_12 -> V_14 -> V_87 ;
T_2 V_91 [ 6 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
if ( F_36 ( V_8 ) == V_127 )
F_39 ( V_8 , V_114 | V_123 ) ;
if ( F_36 ( V_8 ) == V_125
|| F_36 ( V_8 ) == V_123
|| F_36 ( V_8 ) == V_104 )
return;
F_16 ( 0 , V_91 ) ;
F_33 ( F_30 ( V_86 + V_128 ) & ~ ( 1 << V_8 -> V_64 ) , V_86 + V_128 ) ;
F_32 ( V_8 , V_91 , F_5 ( V_8 ) ) ;
}
static bool F_40 ( struct V_7 * V_8 )
{
void T_4 * V_86 = V_8 -> V_12 -> V_14 -> V_87 ;
struct V_98 * V_9 ;
struct V_1 * V_2 ;
struct V_80 V_129 ;
unsigned V_83 ;
T_2 V_91 [ 6 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_97 ;
if ( F_36 ( V_8 ) != V_104 )
return true ;
V_97 = 1 - V_8 -> V_130 ;
if ( ! F_3 ( & V_8 -> V_9 [ V_97 ] ) )
V_9 = & V_8 -> V_9 [ V_97 ] ;
else {
V_97 = V_8 -> V_130 ;
if ( ! F_3 ( & V_8 -> V_9 [ V_97 ] ) )
V_9 = & V_8 -> V_9 [ V_97 ] ;
else
V_9 = NULL ;
}
if ( ! V_9 || ! V_9 -> V_2 )
return true ;
V_2 = V_9 -> V_2 ;
if ( V_2 -> V_131 )
V_83 = V_2 -> V_131 -> V_132 ? 1 : 0 ;
else if ( F_30 ( V_86 + F_37 ( V_8 -> V_13 ) ) & V_133 )
V_83 = 1 ;
else
V_83 = 0 ;
if ( F_6 ( V_8 ) && ! V_83 )
F_41 ( V_8 -> V_12 -> V_14 -> V_95 , L_28 ,
V_134 , __LINE__ ) ;
V_129 . V_81 = V_8 -> V_13 ;
V_129 . V_82 = V_9 -> V_135 ;
V_129 . V_83 = V_83 ;
F_27 ( 0 , V_91 , & V_129 ) ;
F_33 ( F_30 ( V_86 + V_128 ) | ( 1 << V_8 -> V_64 ) , V_86 + V_128 ) ;
F_32 ( V_8 , V_91 , true ) ;
V_8 -> V_101 = V_97 ;
return true ;
}
static bool F_42 ( struct V_7 * V_8 )
{
switch ( F_36 ( V_8 ) ) {
case V_127 :
F_39 ( V_8 , V_114 | V_123 ) ;
if ( F_36 ( V_8 ) == V_123 )
F_39 (thrd, PL330_STATE_STOPPED)
case V_114 :
F_38 ( V_8 ) ;
case V_123 :
case V_125 :
F_39 (thrd, PL330_STATE_STOPPED)
case V_104 :
return F_40 ( V_8 ) ;
case V_121 :
case V_119 :
case V_117 :
case V_110 :
case V_108 :
case V_106 :
return true ;
case V_112 :
default:
return false ;
}
}
static inline int F_43 ( unsigned V_22 , T_2 V_23 [] ,
const struct V_136 * V_137 , int V_138 )
{
int V_139 = 0 ;
struct V_140 * V_15 = V_137 -> V_2 -> V_131 -> V_15 ;
if ( F_7 ( V_15 -> V_19 ) >= V_141 ) {
while ( V_138 -- ) {
V_139 += F_12 ( V_22 , & V_23 [ V_139 ] , V_142 ) ;
V_139 += F_21 ( V_22 , & V_23 [ V_139 ] , V_142 ) ;
}
} else {
while ( V_138 -- ) {
V_139 += F_12 ( V_22 , & V_23 [ V_139 ] , V_142 ) ;
V_139 += F_19 ( V_22 , & V_23 [ V_139 ] ) ;
V_139 += F_21 ( V_22 , & V_23 [ V_139 ] , V_142 ) ;
V_139 += F_26 ( V_22 , & V_23 [ V_139 ] ) ;
}
}
return V_139 ;
}
static inline int F_44 ( unsigned V_22 , T_2 V_23 [] ,
const struct V_136 * V_137 , int V_138 )
{
int V_139 = 0 ;
while ( V_138 -- ) {
V_139 += F_25 ( V_22 , & V_23 [ V_139 ] , V_38 , V_137 -> V_2 -> V_31 ) ;
V_139 += F_13 ( V_22 , & V_23 [ V_139 ] , V_38 , V_137 -> V_2 -> V_31 ) ;
V_139 += F_21 ( V_22 , & V_23 [ V_139 ] , V_142 ) ;
V_139 += F_11 ( V_22 , & V_23 [ V_139 ] , V_137 -> V_2 -> V_31 ) ;
}
return V_139 ;
}
static inline int F_45 ( unsigned V_22 , T_2 V_23 [] ,
const struct V_136 * V_137 , int V_138 )
{
int V_139 = 0 ;
while ( V_138 -- ) {
V_139 += F_25 ( V_22 , & V_23 [ V_139 ] , V_38 , V_137 -> V_2 -> V_31 ) ;
V_139 += F_12 ( V_22 , & V_23 [ V_139 ] , V_142 ) ;
V_139 += F_22 ( V_22 , & V_23 [ V_139 ] , V_38 , V_137 -> V_2 -> V_31 ) ;
V_139 += F_11 ( V_22 , & V_23 [ V_139 ] , V_137 -> V_2 -> V_31 ) ;
}
return V_139 ;
}
static int F_46 ( unsigned V_22 , T_2 V_23 [] ,
const struct V_136 * V_137 , int V_138 )
{
int V_139 = 0 ;
switch ( V_137 -> V_2 -> V_143 ) {
case V_144 :
V_139 += F_45 ( V_22 , & V_23 [ V_139 ] , V_137 , V_138 ) ;
break;
case V_145 :
V_139 += F_44 ( V_22 , & V_23 [ V_139 ] , V_137 , V_138 ) ;
break;
case V_146 :
V_139 += F_43 ( V_22 , & V_23 [ V_139 ] , V_137 , V_138 ) ;
break;
default:
V_139 += 0x40000000 ;
break;
}
return V_139 ;
}
static inline int F_47 ( unsigned V_22 , T_2 V_23 [] ,
unsigned long * V_147 , const struct V_136 * V_137 )
{
int V_138 , V_148 , V_149 , V_150 , V_151 , V_139 ;
unsigned V_152 , V_153 , V_154 , V_155 ;
struct V_46 V_156 ;
if ( * V_147 >= 256 * 256 ) {
V_153 = 256 ;
V_152 = 256 ;
V_138 = * V_147 / V_153 / V_152 ;
} else if ( * V_147 > 256 ) {
V_153 = 256 ;
V_152 = * V_147 / V_153 ;
V_138 = 1 ;
} else {
V_153 = * V_147 ;
V_152 = 0 ;
V_138 = 1 ;
}
V_149 = F_14 ( 1 , V_23 , 0 , 0 ) ;
V_151 = F_46 ( 1 , V_23 , V_137 , 1 ) ;
V_156 . V_35 = V_142 ;
V_156 . V_48 = false ;
V_156 . V_42 = 0 ;
V_156 . V_49 = 0 ;
V_150 = F_15 ( 1 , V_23 , & V_156 ) ;
if ( V_152 ) {
V_149 *= 2 ;
V_150 *= 2 ;
}
V_148 = ( 255 - ( V_149 + V_150 ) ) / V_151 ;
V_138 = ( V_148 < V_138 ) ? V_148 : V_138 ;
V_139 = 0 ;
if ( V_152 ) {
V_139 += F_14 ( V_22 , & V_23 [ V_139 ] , 0 , V_152 ) ;
V_154 = V_139 ;
}
V_139 += F_14 ( V_22 , & V_23 [ V_139 ] , 1 , V_153 ) ;
V_155 = V_139 ;
V_139 += F_46 ( V_22 , & V_23 [ V_139 ] , V_137 , V_138 ) ;
V_156 . V_35 = V_142 ;
V_156 . V_48 = false ;
V_156 . V_42 = 1 ;
V_156 . V_49 = V_139 - V_155 ;
V_139 += F_15 ( V_22 , & V_23 [ V_139 ] , & V_156 ) ;
if ( V_152 ) {
V_156 . V_35 = V_142 ;
V_156 . V_48 = false ;
V_156 . V_42 = 0 ;
V_156 . V_49 = V_139 - V_154 ;
V_139 += F_15 ( V_22 , & V_23 [ V_139 ] , & V_156 ) ;
}
* V_147 = V_153 * V_138 ;
if ( V_152 )
* V_147 *= V_152 ;
return V_139 ;
}
static inline int F_48 ( unsigned V_22 , T_2 V_23 [] ,
const struct V_136 * V_137 )
{
struct V_157 * V_158 = V_137 -> V_158 ;
T_1 V_159 = V_137 -> V_159 ;
unsigned long V_160 , V_147 = F_49 ( V_158 -> V_161 , V_159 ) ;
int V_139 = 0 ;
while ( V_147 ) {
V_160 = V_147 ;
V_139 += F_47 ( V_22 , & V_23 [ V_139 ] , & V_160 , V_137 ) ;
V_147 -= V_160 ;
}
return V_139 ;
}
static inline int F_50 ( unsigned V_22 , T_2 V_23 [] ,
const struct V_136 * V_137 )
{
struct V_157 * V_158 = V_137 -> V_158 ;
int V_139 = 0 ;
V_139 += F_17 ( V_22 , & V_23 [ V_139 ] , V_58 , V_158 -> V_162 ) ;
V_139 += F_17 ( V_22 , & V_23 [ V_139 ] , V_59 , V_158 -> V_163 ) ;
V_139 += F_48 ( V_22 , & V_23 [ V_139 ] , V_137 ) ;
return V_139 ;
}
static int F_51 ( unsigned V_22 , struct V_7 * V_8 ,
unsigned V_164 , struct V_136 * V_137 )
{
struct V_98 * V_9 = & V_8 -> V_9 [ V_164 ] ;
struct V_157 * V_158 ;
T_2 * V_23 = V_9 -> V_99 ;
int V_139 = 0 ;
F_52 ( V_9 -> V_135 ) ;
V_139 += F_17 ( V_22 , & V_23 [ V_139 ] , V_165 , V_137 -> V_159 ) ;
V_158 = V_137 -> V_2 -> V_158 ;
do {
if ( V_158 -> V_161 % ( F_53 ( V_137 -> V_159 ) * F_54 ( V_137 -> V_159 ) ) )
return - V_166 ;
V_137 -> V_158 = V_158 ;
V_139 += F_50 ( V_22 , & V_23 [ V_139 ] , V_137 ) ;
V_158 = V_158 -> V_167 ;
} while ( V_158 );
V_139 += F_20 ( V_22 , & V_23 [ V_139 ] , V_8 -> V_64 ) ;
V_139 += F_10 ( V_22 , & V_23 [ V_139 ] ) ;
return V_139 ;
}
static inline T_1 F_55 ( const struct V_168 * V_169 )
{
T_1 V_159 = 0 ;
if ( V_169 -> V_170 )
V_159 |= V_171 ;
if ( V_169 -> V_172 )
V_159 |= V_173 ;
if ( V_169 -> V_174 )
V_159 |= V_175 | V_176 ;
if ( V_169 -> V_132 )
V_159 |= V_177 | V_178 ;
if ( V_169 -> V_179 )
V_159 |= V_180 | V_181 ;
V_159 |= ( ( ( V_169 -> V_182 - 1 ) & 0xf ) << V_183 ) ;
V_159 |= ( ( ( V_169 -> V_182 - 1 ) & 0xf ) << V_184 ) ;
V_159 |= ( V_169 -> V_185 << V_186 ) ;
V_159 |= ( V_169 -> V_185 << V_187 ) ;
V_159 |= ( V_169 -> V_188 << V_189 ) ;
V_159 |= ( V_169 -> V_190 << V_191 ) ;
V_159 |= ( V_169 -> V_192 << V_193 ) ;
return V_159 ;
}
static inline bool F_56 ( T_1 V_159 )
{
enum V_194 V_190 ;
enum V_195 V_188 ;
V_190 = ( V_159 >> V_191 ) & V_196 ;
V_188 = ( V_159 >> V_189 ) & V_197 ;
if ( V_190 == V_198 || V_190 == V_199
|| V_188 == V_200 || V_188 == V_201 )
return false ;
else
return true ;
}
static int F_57 ( void * V_202 , struct V_1 * V_2 )
{
struct V_7 * V_8 = V_202 ;
struct V_10 * V_11 ;
struct V_203 * V_204 ;
struct V_136 V_205 ;
unsigned long V_206 ;
void T_4 * V_86 ;
unsigned V_97 ;
T_1 V_159 ;
int V_207 = 0 ;
if ( ! V_2 || ! V_8 || V_8 -> free )
return - V_166 ;
V_11 = V_8 -> V_12 ;
V_204 = V_11 -> V_14 ;
V_86 = V_204 -> V_87 ;
if ( V_11 -> V_208 == V_209
|| V_11 -> V_210 . V_211 & ( 1 << V_8 -> V_13 ) ) {
F_41 ( V_8 -> V_12 -> V_14 -> V_95 , L_29 ,
V_134 , __LINE__ ) ;
return - V_212 ;
}
if ( V_2 -> V_143 != V_146 && V_2 -> V_31 >= V_204 -> V_15 . V_213 ) {
F_41 ( V_8 -> V_12 -> V_14 -> V_95 ,
L_30 ,
V_134 , __LINE__ , V_2 -> V_31 ) ;
return - V_166 ;
}
F_58 ( & V_11 -> V_214 , V_206 ) ;
if ( F_4 ( V_8 ) ) {
V_207 = - V_212 ;
goto V_215;
}
if ( V_2 -> V_131 ) {
if ( ! F_6 ( V_8 ) )
V_2 -> V_131 -> V_132 = 0 ;
else
V_2 -> V_131 -> V_132 = 1 ;
V_159 = F_55 ( V_2 -> V_131 ) ;
} else {
V_159 = F_30 ( V_86 + F_59 ( V_8 -> V_13 ) ) ;
}
if ( ! F_56 ( V_159 ) ) {
V_207 = - V_166 ;
F_41 ( V_8 -> V_12 -> V_14 -> V_95 , L_31 ,
V_134 , __LINE__ , V_159 ) ;
goto V_215;
}
V_97 = F_3 ( & V_8 -> V_9 [ 0 ] ) ? 0 : 1 ;
V_205 . V_159 = V_159 ;
V_205 . V_2 = V_2 ;
V_207 = F_51 ( 1 , V_8 , V_97 , & V_205 ) ;
if ( V_207 < 0 )
goto V_215;
if ( V_207 > V_204 -> V_216 / 2 ) {
F_41 ( V_8 -> V_12 -> V_14 -> V_95 ,
L_32 ,
V_134 , __LINE__ ) ;
V_207 = - V_217 ;
goto V_215;
}
V_8 -> V_130 = V_97 ;
V_8 -> V_9 [ V_97 ] . V_100 = F_51 ( 0 , V_8 , V_97 , & V_205 ) ;
V_8 -> V_9 [ V_97 ] . V_2 = V_2 ;
V_207 = 0 ;
V_215:
F_60 ( & V_11 -> V_214 , V_206 ) ;
return V_207 ;
}
static void F_61 ( unsigned long V_218 )
{
struct V_10 * V_11 = (struct V_10 * ) V_218 ;
struct V_203 * V_204 = V_11 -> V_14 ;
unsigned long V_206 ;
int V_219 ;
F_58 ( & V_11 -> V_214 , V_206 ) ;
if ( V_11 -> V_210 . V_220 ) {
V_11 -> V_208 = V_209 ;
V_11 -> V_210 . V_221 = true ;
V_11 -> V_210 . V_220 = false ;
}
if ( V_11 -> V_210 . V_221 ) {
F_38 ( V_11 -> V_222 ) ;
V_11 -> V_210 . V_211 = ( 1 << V_204 -> V_15 . V_16 ) - 1 ;
V_11 -> V_210 . V_221 = false ;
}
for ( V_219 = 0 ; V_219 < V_204 -> V_15 . V_16 ; V_219 ++ ) {
if ( V_11 -> V_210 . V_211 & ( 1 << V_219 ) ) {
struct V_7 * V_8 = & V_11 -> V_223 [ V_219 ] ;
void T_4 * V_86 = V_204 -> V_87 ;
enum V_3 V_4 ;
F_38 ( V_8 ) ;
if ( F_30 ( V_86 + V_224 ) & ( 1 << V_8 -> V_13 ) )
V_4 = V_225 ;
else
V_4 = V_226 ;
F_60 ( & V_11 -> V_214 , V_206 ) ;
F_1 ( V_8 -> V_9 [ 1 - V_8 -> V_130 ] . V_2 , V_4 ) ;
F_1 ( V_8 -> V_9 [ V_8 -> V_130 ] . V_2 , V_4 ) ;
F_58 ( & V_11 -> V_214 , V_206 ) ;
V_8 -> V_9 [ 0 ] . V_2 = NULL ;
V_8 -> V_9 [ 1 ] . V_2 = NULL ;
F_35 ( V_8 , 0 ) ;
F_35 ( V_8 , 1 ) ;
V_11 -> V_210 . V_211 &= ~ ( 1 << V_219 ) ;
}
}
F_60 ( & V_11 -> V_214 , V_206 ) ;
return;
}
static int F_62 ( const struct V_203 * V_204 )
{
struct V_1 * V_227 , * V_228 ;
struct V_10 * V_11 ;
unsigned long V_206 ;
void T_4 * V_86 ;
T_1 V_26 ;
int V_13 , V_64 , V_207 = 0 ;
if ( ! V_204 || ! V_204 -> V_229 )
return 0 ;
V_86 = V_204 -> V_87 ;
V_11 = V_204 -> V_229 ;
F_58 ( & V_11 -> V_214 , V_206 ) ;
V_26 = F_30 ( V_86 + V_230 ) & 0x1 ;
if ( V_26 )
V_11 -> V_210 . V_221 = true ;
else
V_11 -> V_210 . V_221 = false ;
V_26 = F_30 ( V_86 + V_224 ) & ( ( 1 << V_204 -> V_15 . V_16 ) - 1 ) ;
V_11 -> V_210 . V_211 |= V_26 ;
if ( V_26 ) {
int V_219 = 0 ;
while ( V_219 < V_204 -> V_15 . V_16 ) {
if ( V_26 & ( 1 << V_219 ) ) {
F_41 ( V_204 -> V_95 ,
L_33 ,
V_219 , F_30 ( V_86 + F_37 ( V_219 ) ) ,
F_30 ( V_86 + F_63 ( V_219 ) ) ) ;
F_38 ( & V_11 -> V_223 [ V_219 ] ) ;
}
V_219 ++ ;
}
}
V_26 = F_30 ( V_86 + V_231 ) ;
if ( V_204 -> V_15 . V_232 < 32
&& V_26 & ~ ( ( 1 << V_204 -> V_15 . V_232 ) - 1 ) ) {
V_11 -> V_210 . V_220 = true ;
F_34 ( V_204 -> V_95 , L_34 , V_134 , __LINE__ ) ;
V_207 = 1 ;
goto V_233;
}
for ( V_64 = 0 ; V_64 < V_204 -> V_15 . V_232 ; V_64 ++ ) {
if ( V_26 & ( 1 << V_64 ) ) {
struct V_7 * V_8 ;
T_1 V_234 = F_30 ( V_86 + V_128 ) ;
int V_235 ;
if ( V_234 & ( 1 << V_64 ) )
F_33 ( 1 << V_64 , V_86 + V_236 ) ;
V_207 = 1 ;
V_13 = V_11 -> V_237 [ V_64 ] ;
V_8 = & V_11 -> V_223 [ V_13 ] ;
V_235 = V_8 -> V_101 ;
if ( V_235 == - 1 )
continue;
V_227 = V_8 -> V_9 [ V_235 ] . V_2 ;
V_8 -> V_9 [ V_235 ] . V_2 = NULL ;
F_35 ( V_8 , V_235 ) ;
F_42 ( V_8 ) ;
F_64 ( & V_227 -> V_238 , & V_11 -> V_239 ) ;
}
}
F_65 (rqdone, tmp, &pl330->req_done, rqd) {
F_66 ( & V_227 -> V_238 ) ;
F_60 ( & V_11 -> V_214 , V_206 ) ;
F_1 ( V_227 , V_240 ) ;
F_58 ( & V_11 -> V_214 , V_206 ) ;
}
V_233:
F_60 ( & V_11 -> V_214 , V_206 ) ;
if ( V_11 -> V_210 . V_220
|| V_11 -> V_210 . V_221
|| V_11 -> V_210 . V_211 ) {
V_207 = 1 ;
F_67 ( & V_11 -> V_241 ) ;
}
return V_207 ;
}
static int F_68 ( void * V_202 , enum V_242 V_243 )
{
struct V_7 * V_8 = V_202 ;
struct V_10 * V_11 ;
unsigned long V_206 ;
int V_207 = 0 , V_235 ;
if ( ! V_8 || V_8 -> free || V_8 -> V_12 -> V_208 == V_209 )
return - V_166 ;
V_11 = V_8 -> V_12 ;
V_235 = V_8 -> V_101 ;
F_58 ( & V_11 -> V_214 , V_206 ) ;
switch ( V_243 ) {
case V_244 :
F_38 ( V_8 ) ;
V_8 -> V_9 [ 0 ] . V_2 = NULL ;
V_8 -> V_9 [ 1 ] . V_2 = NULL ;
F_35 ( V_8 , 0 ) ;
F_35 ( V_8 , 1 ) ;
break;
case V_245 :
F_38 ( V_8 ) ;
if ( V_235 == - 1 )
break;
V_8 -> V_9 [ V_235 ] . V_2 = NULL ;
F_35 ( V_8 , V_235 ) ;
case V_246 :
if ( ( V_235 == - 1 ) && ! F_42 ( V_8 ) )
V_207 = - V_247 ;
break;
default:
V_207 = - V_166 ;
}
F_60 ( & V_11 -> V_214 , V_206 ) ;
return V_207 ;
}
static inline int F_69 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_203 * V_204 = V_11 -> V_14 ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_204 -> V_15 . V_232 ; V_64 ++ )
if ( V_11 -> V_237 [ V_64 ] == - 1 ) {
V_11 -> V_237 [ V_64 ] = V_8 -> V_13 ;
return V_64 ;
}
return - 1 ;
}
static bool F_70 ( const struct V_203 * V_204 , int V_219 )
{
return V_204 -> V_15 . V_248 & ( 1 << V_219 ) ;
}
static void * F_71 ( const struct V_203 * V_204 )
{
struct V_7 * V_8 = NULL ;
struct V_10 * V_11 ;
unsigned long V_206 ;
int V_249 , V_219 ;
if ( ! V_204 || ! V_204 -> V_229 )
return NULL ;
V_11 = V_204 -> V_229 ;
if ( V_11 -> V_208 == V_209 )
return NULL ;
V_249 = V_204 -> V_15 . V_16 ;
F_58 ( & V_11 -> V_214 , V_206 ) ;
for ( V_219 = 0 ; V_219 < V_249 ; V_219 ++ ) {
V_8 = & V_11 -> V_223 [ V_219 ] ;
if ( ( V_8 -> free ) && ( ! F_6 ( V_8 ) ||
F_70 ( V_204 , V_219 ) ) ) {
V_8 -> V_64 = F_69 ( V_8 ) ;
if ( V_8 -> V_64 >= 0 ) {
V_8 -> free = false ;
V_8 -> V_130 = 1 ;
V_8 -> V_9 [ 0 ] . V_2 = NULL ;
F_35 ( V_8 , 0 ) ;
V_8 -> V_9 [ 1 ] . V_2 = NULL ;
F_35 ( V_8 , 1 ) ;
break;
}
}
V_8 = NULL ;
}
F_60 ( & V_11 -> V_214 , V_206 ) ;
return V_8 ;
}
static inline void F_72 ( struct V_7 * V_8 , int V_64 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_203 * V_204 = V_11 -> V_14 ;
if ( V_64 >= 0 && V_64 < V_204 -> V_15 . V_232
&& V_11 -> V_237 [ V_64 ] == V_8 -> V_13 )
V_11 -> V_237 [ V_64 ] = - 1 ;
}
static void F_73 ( void * V_202 )
{
struct V_7 * V_8 = V_202 ;
struct V_10 * V_11 ;
unsigned long V_206 ;
if ( ! V_8 || V_8 -> free )
return;
F_38 ( V_8 ) ;
F_1 ( V_8 -> V_9 [ 1 - V_8 -> V_130 ] . V_2 , V_226 ) ;
F_1 ( V_8 -> V_9 [ V_8 -> V_130 ] . V_2 , V_226 ) ;
V_11 = V_8 -> V_12 ;
F_58 ( & V_11 -> V_214 , V_206 ) ;
F_72 ( V_8 , V_8 -> V_64 ) ;
V_8 -> free = true ;
F_60 ( & V_11 -> V_214 , V_206 ) ;
}
static void F_74 ( struct V_203 * V_204 )
{
void T_4 * V_86 = V_204 -> V_87 ;
T_1 V_26 ;
V_26 = F_30 ( V_86 + V_250 ) >> V_251 ;
V_26 &= V_252 ;
V_204 -> V_15 . V_253 = 8 * ( 1 << V_26 ) ;
V_26 = F_30 ( V_86 + V_250 ) >> V_254 ;
V_26 &= V_255 ;
V_204 -> V_15 . V_256 = V_26 + 1 ;
V_26 = F_30 ( V_86 + V_257 ) >> V_258 ;
V_26 &= V_259 ;
V_26 += 1 ;
V_204 -> V_15 . V_16 = V_26 ;
V_26 = F_30 ( V_86 + V_257 ) ;
if ( V_26 & V_260 ) {
V_26 = ( V_26 >> V_261 ) & V_262 ;
V_26 += 1 ;
V_204 -> V_15 . V_213 = V_26 ;
V_204 -> V_15 . V_263 = F_30 ( V_86 + V_264 ) ;
} else {
V_204 -> V_15 . V_213 = 0 ;
}
V_26 = F_30 ( V_86 + V_257 ) ;
if ( V_26 & V_265 )
V_204 -> V_15 . V_17 |= V_18 ;
else
V_204 -> V_15 . V_17 &= ~ V_18 ;
V_26 = F_30 ( V_86 + V_257 ) >> V_266 ;
V_26 &= V_267 ;
V_26 += 1 ;
V_204 -> V_15 . V_232 = V_26 ;
V_204 -> V_15 . V_248 = F_30 ( V_86 + V_268 ) ;
}
static inline void F_75 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_203 * V_204 = V_11 -> V_14 ;
V_8 -> V_9 [ 0 ] . V_99 = V_11 -> V_269
+ ( V_8 -> V_13 * V_204 -> V_216 ) ;
V_8 -> V_9 [ 0 ] . V_135 = V_11 -> V_270
+ ( V_8 -> V_13 * V_204 -> V_216 ) ;
V_8 -> V_9 [ 0 ] . V_2 = NULL ;
F_35 ( V_8 , 0 ) ;
V_8 -> V_9 [ 1 ] . V_99 = V_8 -> V_9 [ 0 ] . V_99
+ V_204 -> V_216 / 2 ;
V_8 -> V_9 [ 1 ] . V_135 = V_8 -> V_9 [ 0 ] . V_135
+ V_204 -> V_216 / 2 ;
V_8 -> V_9 [ 1 ] . V_2 = NULL ;
F_35 ( V_8 , 1 ) ;
}
static int F_76 ( struct V_10 * V_11 )
{
struct V_203 * V_204 = V_11 -> V_14 ;
int V_249 = V_204 -> V_15 . V_16 ;
struct V_7 * V_8 ;
int V_219 ;
V_11 -> V_223 = F_77 ( ( 1 + V_249 ) * sizeof( * V_8 ) ,
V_271 ) ;
if ( ! V_11 -> V_223 )
return - V_217 ;
for ( V_219 = 0 ; V_219 < V_249 ; V_219 ++ ) {
V_8 = & V_11 -> V_223 [ V_219 ] ;
V_8 -> V_13 = V_219 ;
V_8 -> V_12 = V_11 ;
F_75 ( V_8 ) ;
V_8 -> free = true ;
}
V_8 = & V_11 -> V_223 [ V_249 ] ;
V_8 -> V_13 = V_249 ;
V_8 -> V_12 = V_11 ;
V_8 -> free = false ;
V_11 -> V_222 = V_8 ;
return 0 ;
}
static int F_78 ( struct V_10 * V_11 )
{
struct V_203 * V_204 = V_11 -> V_14 ;
int V_249 = V_204 -> V_15 . V_16 ;
int V_207 ;
V_11 -> V_269 = F_79 ( V_204 -> V_95 ,
V_249 * V_204 -> V_216 ,
& V_11 -> V_270 , V_271 ) ;
if ( ! V_11 -> V_269 ) {
F_34 ( V_204 -> V_95 , L_35 ,
V_134 , __LINE__ ) ;
return - V_217 ;
}
V_207 = F_76 ( V_11 ) ;
if ( V_207 ) {
F_34 ( V_204 -> V_95 , L_36 ,
V_134 , __LINE__ ) ;
F_80 ( V_204 -> V_95 ,
V_249 * V_204 -> V_216 ,
V_11 -> V_269 , V_11 -> V_270 ) ;
return V_207 ;
}
return 0 ;
}
static int F_81 ( struct V_203 * V_204 )
{
struct V_10 * V_11 ;
void T_4 * V_86 ;
int V_219 , V_207 ;
if ( ! V_204 || ! V_204 -> V_95 )
return - V_166 ;
if ( V_204 -> V_229 )
return - V_166 ;
if ( V_204 -> V_272 )
V_204 -> V_272 ( V_204 ) ;
V_86 = V_204 -> V_87 ;
if ( ( V_204 -> V_15 . V_19 & 0xfffff ) != V_273 ) {
F_34 ( V_204 -> V_95 , L_37 , V_204 -> V_15 . V_19 ) ;
return - V_166 ;
}
F_74 ( V_204 ) ;
if ( V_204 -> V_15 . V_232 == 0 ) {
F_34 ( V_204 -> V_95 , L_38 ,
V_134 , __LINE__ ) ;
return - V_166 ;
}
V_11 = F_77 ( sizeof( * V_11 ) , V_271 ) ;
if ( ! V_11 ) {
F_34 ( V_204 -> V_95 , L_35 ,
V_134 , __LINE__ ) ;
return - V_217 ;
}
V_11 -> V_14 = V_204 ;
V_204 -> V_229 = V_11 ;
F_82 ( & V_11 -> V_214 ) ;
F_83 ( & V_11 -> V_239 ) ;
if ( ! V_204 -> V_216 )
V_204 -> V_216 = V_274 * 2 ;
for ( V_219 = 0 ; V_219 < V_204 -> V_15 . V_232 ; V_219 ++ )
V_11 -> V_237 [ V_219 ] = - 1 ;
V_207 = F_78 ( V_11 ) ;
if ( V_207 ) {
F_34 ( V_204 -> V_95 , L_39 ) ;
F_84 ( V_11 ) ;
return V_207 ;
}
F_85 ( & V_11 -> V_241 , F_61 , ( unsigned long ) V_11 ) ;
V_11 -> V_208 = V_275 ;
return 0 ;
}
static int F_86 ( struct V_10 * V_11 )
{
struct V_203 * V_204 = V_11 -> V_14 ;
int V_249 = V_204 -> V_15 . V_16 ;
struct V_7 * V_8 ;
int V_219 ;
for ( V_219 = 0 ; V_219 < V_249 ; V_219 ++ ) {
V_8 = & V_11 -> V_223 [ V_219 ] ;
F_73 ( ( void * ) V_8 ) ;
}
F_84 ( V_11 -> V_223 ) ;
return 0 ;
}
static void F_87 ( struct V_10 * V_11 )
{
struct V_203 * V_204 = V_11 -> V_14 ;
int V_249 = V_204 -> V_15 . V_16 ;
F_86 ( V_11 ) ;
F_80 ( V_204 -> V_95 , V_249 * V_204 -> V_216 ,
V_11 -> V_269 , V_11 -> V_270 ) ;
}
static void F_88 ( struct V_203 * V_204 )
{
struct V_10 * V_11 ;
if ( ! V_204 || ! V_204 -> V_229 )
return;
V_11 = V_204 -> V_229 ;
V_11 -> V_208 = V_276 ;
F_89 ( & V_11 -> V_241 ) ;
F_87 ( V_11 ) ;
F_84 ( V_11 ) ;
V_204 -> V_229 = NULL ;
}
static inline struct V_277 *
F_90 ( struct V_278 * V_279 )
{
if ( ! V_279 )
return NULL ;
return F_91 ( V_279 , struct V_277 , V_81 ) ;
}
static inline struct V_280 *
F_92 ( struct V_281 * V_282 )
{
return F_91 ( V_282 , struct V_280 , V_283 ) ;
}
static inline void F_93 ( struct V_277 * V_284 )
{
struct V_280 * V_285 ;
int V_207 ;
F_94 (desc, &pch->work_list, node) {
if ( V_285 -> V_286 == V_287 )
continue;
V_207 = F_57 ( V_284 -> V_288 ,
& V_285 -> V_9 ) ;
if ( ! V_207 ) {
V_285 -> V_286 = V_287 ;
} else if ( V_207 == - V_212 ) {
break;
} else {
V_285 -> V_286 = V_289 ;
F_34 ( V_284 -> V_12 -> V_290 . V_95 , L_40 ,
V_134 , __LINE__ , V_285 -> V_283 . V_291 ) ;
F_67 ( & V_284 -> V_292 ) ;
}
}
}
static void F_95 ( unsigned long V_218 )
{
struct V_277 * V_284 = (struct V_277 * ) V_218 ;
struct V_280 * V_285 , * V_293 ;
unsigned long V_206 ;
F_58 ( & V_284 -> V_214 , V_206 ) ;
F_65 (desc, _dt, &pch->work_list, node)
if ( V_285 -> V_286 == V_289 ) {
if ( ! V_284 -> V_294 )
F_96 ( & V_285 -> V_283 ) ;
F_97 ( & V_285 -> V_295 , & V_284 -> V_296 ) ;
}
F_93 ( V_284 ) ;
F_68 ( V_284 -> V_288 , V_246 ) ;
while ( ! F_98 ( & V_284 -> V_296 ) ) {
T_5 V_297 ;
void * V_298 ;
V_285 = F_99 ( & V_284 -> V_296 ,
struct V_280 , V_295 ) ;
V_297 = V_285 -> V_283 . V_297 ;
V_298 = V_285 -> V_283 . V_298 ;
if ( V_284 -> V_294 ) {
V_285 -> V_286 = V_299 ;
F_97 ( & V_285 -> V_295 , & V_284 -> V_300 ) ;
} else {
V_285 -> V_286 = FREE ;
F_97 ( & V_285 -> V_295 , & V_284 -> V_12 -> V_301 ) ;
}
F_100 ( & V_285 -> V_283 ) ;
if ( V_297 ) {
F_60 ( & V_284 -> V_214 , V_206 ) ;
V_297 ( V_298 ) ;
F_58 ( & V_284 -> V_214 , V_206 ) ;
}
}
F_60 ( & V_284 -> V_214 , V_206 ) ;
}
static void F_101 ( void * V_6 , enum V_3 V_4 )
{
struct V_280 * V_285 = V_6 ;
struct V_277 * V_284 = V_285 -> V_302 ;
unsigned long V_206 ;
if ( ! V_284 )
return;
F_58 ( & V_284 -> V_214 , V_206 ) ;
V_285 -> V_286 = V_289 ;
F_60 ( & V_284 -> V_214 , V_206 ) ;
F_67 ( & V_284 -> V_292 ) ;
}
bool F_102 ( struct V_278 * V_81 , void * V_303 )
{
T_2 * V_304 ;
if ( V_81 -> V_305 -> V_95 -> V_306 != & V_307 . V_308 )
return false ;
V_304 = V_81 -> V_309 ;
return * V_304 == ( unsigned long ) V_303 ;
}
static struct V_278 * F_103 ( struct V_310 * V_311 ,
struct V_312 * V_313 )
{
int V_314 = V_311 -> V_315 ;
struct V_316 * V_317 = V_313 -> V_318 ;
unsigned int V_319 ;
if ( V_314 != 1 )
return NULL ;
V_319 = V_311 -> args [ 0 ] ;
if ( V_319 >= V_317 -> V_320 )
return NULL ;
return F_104 ( & V_317 -> V_321 [ V_319 ] . V_81 ) ;
}
static int F_105 ( struct V_278 * V_81 )
{
struct V_277 * V_284 = F_90 ( V_81 ) ;
struct V_316 * V_317 = V_284 -> V_12 ;
unsigned long V_206 ;
F_58 ( & V_284 -> V_214 , V_206 ) ;
F_106 ( V_81 ) ;
V_284 -> V_294 = false ;
V_284 -> V_288 = F_71 ( & V_317 -> V_290 ) ;
if ( ! V_284 -> V_288 ) {
F_60 ( & V_284 -> V_214 , V_206 ) ;
return - V_217 ;
}
F_85 ( & V_284 -> V_292 , F_95 , ( unsigned long ) V_284 ) ;
F_60 ( & V_284 -> V_214 , V_206 ) ;
return 1 ;
}
static int F_107 ( struct V_278 * V_81 , enum V_322 V_323 , unsigned long V_47 )
{
struct V_277 * V_284 = F_90 ( V_81 ) ;
struct V_280 * V_285 ;
unsigned long V_206 ;
struct V_316 * V_317 = V_284 -> V_12 ;
struct V_324 * V_325 ;
F_108 ( V_326 ) ;
switch ( V_323 ) {
case V_327 :
F_58 ( & V_284 -> V_214 , V_206 ) ;
F_68 ( V_284 -> V_288 , V_244 ) ;
F_94 (desc, &pch->submitted_list, node) {
V_285 -> V_286 = FREE ;
F_96 ( & V_285 -> V_283 ) ;
}
F_94 (desc, &pch->work_list , node) {
V_285 -> V_286 = FREE ;
F_96 ( & V_285 -> V_283 ) ;
}
F_94 (desc, &pch->completed_list , node) {
V_285 -> V_286 = FREE ;
F_96 ( & V_285 -> V_283 ) ;
}
F_109 ( & V_284 -> V_328 , & V_317 -> V_301 ) ;
F_109 ( & V_284 -> V_300 , & V_317 -> V_301 ) ;
F_109 ( & V_284 -> V_296 , & V_317 -> V_301 ) ;
F_60 ( & V_284 -> V_214 , V_206 ) ;
break;
case V_329 :
V_325 = (struct V_324 * ) V_47 ;
if ( V_325 -> V_330 == V_331 ) {
if ( V_325 -> V_163 )
V_284 -> V_332 = V_325 -> V_163 ;
if ( V_325 -> V_333 )
V_284 -> V_334 = F_110 ( V_325 -> V_333 ) ;
if ( V_325 -> V_335 )
V_284 -> V_336 = V_325 -> V_335 ;
} else if ( V_325 -> V_330 == V_337 ) {
if ( V_325 -> V_162 )
V_284 -> V_332 = V_325 -> V_162 ;
if ( V_325 -> V_338 )
V_284 -> V_334 = F_110 ( V_325 -> V_338 ) ;
if ( V_325 -> V_339 )
V_284 -> V_336 = V_325 -> V_339 ;
}
break;
default:
F_34 ( V_284 -> V_12 -> V_290 . V_95 , L_41 ) ;
return - V_340 ;
}
return 0 ;
}
static void F_111 ( struct V_278 * V_81 )
{
struct V_277 * V_284 = F_90 ( V_81 ) ;
unsigned long V_206 ;
F_89 ( & V_284 -> V_292 ) ;
F_58 ( & V_284 -> V_214 , V_206 ) ;
F_73 ( V_284 -> V_288 ) ;
V_284 -> V_288 = NULL ;
if ( V_284 -> V_294 )
F_109 ( & V_284 -> V_300 , & V_284 -> V_12 -> V_301 ) ;
F_60 ( & V_284 -> V_214 , V_206 ) ;
}
static enum V_341
F_112 ( struct V_278 * V_81 , T_6 V_291 ,
struct V_342 * V_343 )
{
return F_113 ( V_81 , V_291 , V_343 ) ;
}
static void F_114 ( struct V_278 * V_81 )
{
struct V_277 * V_284 = F_90 ( V_81 ) ;
unsigned long V_206 ;
F_58 ( & V_284 -> V_214 , V_206 ) ;
F_109 ( & V_284 -> V_328 , & V_284 -> V_300 ) ;
F_60 ( & V_284 -> V_214 , V_206 ) ;
F_95 ( ( unsigned long ) V_284 ) ;
}
static T_6 F_115 ( struct V_281 * V_282 )
{
struct V_280 * V_285 , * V_344 = F_92 ( V_282 ) ;
struct V_277 * V_284 = F_90 ( V_282 -> V_81 ) ;
T_6 V_291 ;
unsigned long V_206 ;
F_58 ( & V_284 -> V_214 , V_206 ) ;
while ( ! F_98 ( & V_344 -> V_295 ) ) {
V_285 = F_116 ( V_344 -> V_295 . V_167 , struct V_280 , V_295 ) ;
if ( V_284 -> V_294 ) {
V_285 -> V_283 . V_297 = V_344 -> V_283 . V_297 ;
V_285 -> V_283 . V_298 = V_344 -> V_283 . V_298 ;
}
F_117 ( & V_285 -> V_283 ) ;
F_97 ( & V_285 -> V_295 , & V_284 -> V_328 ) ;
}
V_291 = F_117 ( & V_344 -> V_283 ) ;
F_64 ( & V_344 -> V_295 , & V_284 -> V_328 ) ;
F_60 ( & V_284 -> V_214 , V_206 ) ;
return V_291 ;
}
static inline void F_118 ( struct V_280 * V_285 )
{
V_285 -> V_9 . V_158 = & V_285 -> V_345 ;
V_285 -> V_9 . V_6 = V_285 ;
V_285 -> V_346 . V_192 = V_347 ;
V_285 -> V_346 . V_188 = V_348 ;
V_285 -> V_346 . V_190 = V_349 ;
V_285 -> V_9 . V_131 = & V_285 -> V_346 ;
V_285 -> V_9 . V_5 = F_101 ;
V_285 -> V_283 . V_350 = F_115 ;
F_83 ( & V_285 -> V_295 ) ;
}
static int F_119 ( struct V_316 * V_317 , T_7 V_351 , int V_314 )
{
struct V_280 * V_285 ;
unsigned long V_206 ;
int V_219 ;
if ( ! V_317 )
return 0 ;
V_285 = F_120 ( V_314 , sizeof( * V_285 ) , V_351 ) ;
if ( ! V_285 )
return 0 ;
F_58 ( & V_317 -> V_352 , V_206 ) ;
for ( V_219 = 0 ; V_219 < V_314 ; V_219 ++ ) {
F_118 ( & V_285 [ V_219 ] ) ;
F_64 ( & V_285 [ V_219 ] . V_295 , & V_317 -> V_301 ) ;
}
F_60 ( & V_317 -> V_352 , V_206 ) ;
return V_314 ;
}
static struct V_280 *
F_121 ( struct V_316 * V_317 )
{
struct V_280 * V_285 = NULL ;
unsigned long V_206 ;
if ( ! V_317 )
return NULL ;
F_58 ( & V_317 -> V_352 , V_206 ) ;
if ( ! F_98 ( & V_317 -> V_301 ) ) {
V_285 = F_116 ( V_317 -> V_301 . V_167 ,
struct V_280 , V_295 ) ;
F_122 ( & V_285 -> V_295 ) ;
V_285 -> V_286 = V_299 ;
V_285 -> V_283 . V_297 = NULL ;
}
F_60 ( & V_317 -> V_352 , V_206 ) ;
return V_285 ;
}
static struct V_280 * F_123 ( struct V_277 * V_284 )
{
struct V_316 * V_317 = V_284 -> V_12 ;
T_2 * V_304 = V_284 -> V_81 . V_309 ;
struct V_280 * V_285 ;
V_285 = F_121 ( V_317 ) ;
if ( ! V_285 ) {
if ( ! F_119 ( V_317 , V_353 , 1 ) )
return NULL ;
V_285 = F_121 ( V_317 ) ;
if ( ! V_285 ) {
F_34 ( V_284 -> V_12 -> V_290 . V_95 ,
L_42 , V_134 , __LINE__ ) ;
return NULL ;
}
}
V_285 -> V_302 = V_284 ;
V_285 -> V_283 . V_291 = 0 ;
F_124 ( & V_285 -> V_283 ) ;
V_285 -> V_9 . V_31 = V_304 ? V_284 -> V_81 . V_319 : 0 ;
V_285 -> V_346 . V_15 = & V_284 -> V_12 -> V_290 . V_15 ;
F_125 ( & V_285 -> V_283 , & V_284 -> V_81 ) ;
return V_285 ;
}
static inline void F_126 ( struct V_157 * V_345 ,
T_8 V_55 , T_8 V_354 , T_9 V_355 )
{
V_345 -> V_167 = NULL ;
V_345 -> V_161 = V_355 ;
V_345 -> V_163 = V_55 ;
V_345 -> V_162 = V_354 ;
}
static struct V_280 *
F_127 ( struct V_277 * V_284 , T_8 V_55 ,
T_8 V_354 , T_9 V_355 )
{
struct V_280 * V_285 = F_123 ( V_284 ) ;
if ( ! V_285 ) {
F_34 ( V_284 -> V_12 -> V_290 . V_95 , L_43 ,
V_134 , __LINE__ ) ;
return NULL ;
}
F_126 ( & V_285 -> V_345 , V_55 , V_354 , V_355 ) ;
return V_285 ;
}
static inline int F_128 ( struct V_280 * V_285 , T_9 V_355 )
{
struct V_277 * V_284 = V_285 -> V_302 ;
struct V_203 * V_204 = & V_284 -> V_12 -> V_290 ;
int V_336 ;
V_336 = V_204 -> V_15 . V_253 / 8 ;
V_336 *= V_204 -> V_15 . V_256 ;
V_336 >>= V_285 -> V_346 . V_185 ;
if ( V_336 > 16 )
V_336 = 16 ;
while ( V_336 > 1 ) {
if ( ! ( V_355 % ( V_336 << V_285 -> V_346 . V_185 ) ) )
break;
V_336 -- ;
}
return V_336 ;
}
static struct V_281 * F_129 (
struct V_278 * V_81 , T_8 V_356 , T_9 V_355 ,
T_9 V_357 , enum V_358 V_330 ,
unsigned long V_206 , void * V_359 )
{
struct V_280 * V_285 = NULL , * V_360 = NULL ;
struct V_277 * V_284 = F_90 ( V_81 ) ;
struct V_316 * V_317 = V_284 -> V_12 ;
unsigned int V_219 ;
T_8 V_55 ;
T_8 V_354 ;
if ( V_355 % V_357 != 0 )
return NULL ;
if ( ! F_130 ( V_330 ) ) {
F_34 ( V_284 -> V_12 -> V_290 . V_95 , L_44 ,
V_134 , __LINE__ ) ;
return NULL ;
}
for ( V_219 = 0 ; V_219 < V_355 / V_357 ; V_219 ++ ) {
V_285 = F_123 ( V_284 ) ;
if ( ! V_285 ) {
F_34 ( V_284 -> V_12 -> V_290 . V_95 , L_43 ,
V_134 , __LINE__ ) ;
if ( ! V_360 )
return NULL ;
F_58 ( & V_317 -> V_352 , V_206 ) ;
while ( ! F_98 ( & V_360 -> V_295 ) ) {
V_285 = F_116 ( V_360 -> V_295 . V_167 ,
struct V_280 , V_295 ) ;
F_97 ( & V_285 -> V_295 , & V_317 -> V_301 ) ;
}
F_97 ( & V_360 -> V_295 , & V_317 -> V_301 ) ;
F_60 ( & V_317 -> V_352 , V_206 ) ;
return NULL ;
}
switch ( V_330 ) {
case V_331 :
V_285 -> V_346 . V_170 = 1 ;
V_285 -> V_346 . V_172 = 0 ;
V_285 -> V_9 . V_143 = V_144 ;
V_354 = V_356 ;
V_55 = V_284 -> V_332 ;
break;
case V_337 :
V_285 -> V_346 . V_170 = 0 ;
V_285 -> V_346 . V_172 = 1 ;
V_285 -> V_9 . V_143 = V_145 ;
V_354 = V_284 -> V_332 ;
V_55 = V_356 ;
break;
default:
break;
}
V_285 -> V_346 . V_185 = V_284 -> V_334 ;
V_285 -> V_346 . V_182 = 1 ;
F_126 ( & V_285 -> V_345 , V_55 , V_354 , V_357 ) ;
if ( ! V_360 )
V_360 = V_285 ;
else
F_64 ( & V_285 -> V_295 , & V_360 -> V_295 ) ;
V_356 += V_357 ;
}
if ( ! V_285 )
return NULL ;
V_284 -> V_294 = true ;
V_285 -> V_283 . V_206 = V_206 ;
return & V_285 -> V_283 ;
}
static struct V_281 *
F_131 ( struct V_278 * V_81 , T_8 V_55 ,
T_8 V_354 , T_9 V_355 , unsigned long V_206 )
{
struct V_280 * V_285 ;
struct V_277 * V_284 = F_90 ( V_81 ) ;
struct V_203 * V_204 ;
int V_361 ;
if ( F_132 ( ! V_284 || ! V_355 ) )
return NULL ;
V_204 = & V_284 -> V_12 -> V_290 ;
V_285 = F_127 ( V_284 , V_55 , V_354 , V_355 ) ;
if ( ! V_285 )
return NULL ;
V_285 -> V_346 . V_170 = 1 ;
V_285 -> V_346 . V_172 = 1 ;
V_285 -> V_9 . V_143 = V_146 ;
V_361 = V_204 -> V_15 . V_253 / 8 ;
while ( V_361 > 1 ) {
if ( ! ( V_355 % V_361 ) )
break;
V_361 /= 2 ;
}
V_285 -> V_346 . V_185 = 0 ;
while ( V_361 != ( 1 << V_285 -> V_346 . V_185 ) )
V_285 -> V_346 . V_185 ++ ;
V_285 -> V_346 . V_182 = F_128 ( V_285 , V_355 ) ;
V_285 -> V_283 . V_206 = V_206 ;
return & V_285 -> V_283 ;
}
static void F_133 ( struct V_316 * V_317 ,
struct V_280 * V_360 )
{
unsigned long V_206 ;
struct V_280 * V_285 ;
if ( ! V_360 )
return;
F_58 ( & V_317 -> V_352 , V_206 ) ;
while ( ! F_98 ( & V_360 -> V_295 ) ) {
V_285 = F_116 ( V_360 -> V_295 . V_167 ,
struct V_280 , V_295 ) ;
F_97 ( & V_285 -> V_295 , & V_317 -> V_301 ) ;
}
F_97 ( & V_360 -> V_295 , & V_317 -> V_301 ) ;
F_60 ( & V_317 -> V_352 , V_206 ) ;
}
static struct V_281 *
F_134 ( struct V_278 * V_81 , struct V_362 * V_363 ,
unsigned int V_364 , enum V_358 V_330 ,
unsigned long V_351 , void * V_359 )
{
struct V_280 * V_360 , * V_285 = NULL ;
struct V_277 * V_284 = F_90 ( V_81 ) ;
struct V_362 * V_365 ;
int V_219 ;
T_8 V_82 ;
if ( F_132 ( ! V_284 || ! V_363 || ! V_364 ) )
return NULL ;
V_82 = V_284 -> V_332 ;
V_360 = NULL ;
F_135 (sgl, sg, sg_len, i) {
V_285 = F_123 ( V_284 ) ;
if ( ! V_285 ) {
struct V_316 * V_317 = V_284 -> V_12 ;
F_34 ( V_284 -> V_12 -> V_290 . V_95 ,
L_43 ,
V_134 , __LINE__ ) ;
F_133 ( V_317 , V_360 ) ;
return NULL ;
}
if ( ! V_360 )
V_360 = V_285 ;
else
F_64 ( & V_285 -> V_295 , & V_360 -> V_295 ) ;
if ( V_330 == V_331 ) {
V_285 -> V_346 . V_170 = 1 ;
V_285 -> V_346 . V_172 = 0 ;
V_285 -> V_9 . V_143 = V_144 ;
F_126 ( & V_285 -> V_345 ,
V_82 , F_136 ( V_365 ) , F_137 ( V_365 ) ) ;
} else {
V_285 -> V_346 . V_170 = 0 ;
V_285 -> V_346 . V_172 = 1 ;
V_285 -> V_9 . V_143 = V_145 ;
F_126 ( & V_285 -> V_345 ,
F_136 ( V_365 ) , V_82 , F_137 ( V_365 ) ) ;
}
V_285 -> V_346 . V_185 = V_284 -> V_334 ;
V_285 -> V_346 . V_182 = 1 ;
}
V_285 -> V_283 . V_206 = V_351 ;
return & V_285 -> V_283 ;
}
static T_10 F_138 ( int V_366 , void * V_218 )
{
if ( F_62 ( V_218 ) )
return V_367 ;
else
return V_368 ;
}
static int F_139 ( struct V_278 * V_369 ,
struct V_370 * V_371 )
{
V_371 -> V_372 = V_373 ;
V_371 -> V_374 = V_373 ;
V_371 -> V_375 = F_140 ( V_337 ) | F_140 ( V_331 ) ;
V_371 -> V_376 = false ;
V_371 -> V_377 = true ;
V_371 -> V_378 = V_379 ;
return 0 ;
}
static int
F_141 ( struct V_380 * V_381 , const struct V_382 * V_13 )
{
struct V_383 * V_384 ;
struct V_316 * V_317 ;
struct V_277 * V_284 , * V_385 ;
struct V_203 * V_204 ;
struct V_386 * V_387 ;
struct V_388 * V_389 ;
int V_219 , V_207 , V_366 ;
int V_16 ;
V_384 = F_142 ( & V_381 -> V_95 ) ;
V_207 = F_143 ( & V_381 -> V_95 , F_144 ( 32 ) ) ;
if ( V_207 )
return V_207 ;
V_317 = F_145 ( & V_381 -> V_95 , sizeof( * V_317 ) , V_271 ) ;
if ( ! V_317 ) {
F_34 ( & V_381 -> V_95 , L_45 ) ;
return - V_217 ;
}
V_204 = & V_317 -> V_290 ;
V_204 -> V_95 = & V_381 -> V_95 ;
V_204 -> V_229 = NULL ;
V_204 -> V_216 = V_384 ? V_384 -> V_390 : 0 ;
V_389 = & V_381 -> V_389 ;
V_204 -> V_87 = F_146 ( & V_381 -> V_95 , V_389 ) ;
if ( F_147 ( V_204 -> V_87 ) )
return F_148 ( V_204 -> V_87 ) ;
F_149 ( V_381 , V_317 ) ;
for ( V_219 = 0 ; V_219 < V_391 ; V_219 ++ ) {
V_366 = V_381 -> V_366 [ V_219 ] ;
if ( V_366 ) {
V_207 = F_150 ( & V_381 -> V_95 , V_366 ,
F_138 , 0 ,
F_151 ( & V_381 -> V_95 ) , V_204 ) ;
if ( V_207 )
return V_207 ;
} else {
break;
}
}
V_204 -> V_15 . V_19 = V_381 -> V_392 ;
V_207 = F_81 ( V_204 ) ;
if ( V_207 )
return V_207 ;
F_83 ( & V_317 -> V_301 ) ;
F_82 ( & V_317 -> V_352 ) ;
if ( ! F_119 ( V_317 , V_271 , V_393 ) )
F_152 ( & V_381 -> V_95 , L_46 ) ;
V_387 = & V_317 -> V_394 ;
F_83 ( & V_387 -> V_223 ) ;
if ( V_384 )
V_16 = F_153 ( int , V_384 -> V_395 , V_204 -> V_15 . V_16 ) ;
else
V_16 = F_153 ( int , V_204 -> V_15 . V_213 , V_204 -> V_15 . V_16 ) ;
V_317 -> V_320 = V_16 ;
V_317 -> V_321 = F_77 ( V_16 * sizeof( * V_284 ) , V_271 ) ;
if ( ! V_317 -> V_321 ) {
V_207 = - V_217 ;
F_34 ( & V_381 -> V_95 , L_47 ) ;
goto V_396;
}
for ( V_219 = 0 ; V_219 < V_16 ; V_219 ++ ) {
V_284 = & V_317 -> V_321 [ V_219 ] ;
if ( ! V_381 -> V_95 . V_397 )
V_284 -> V_81 . V_309 = V_384 ? & V_384 -> V_304 [ V_219 ] : NULL ;
else
V_284 -> V_81 . V_309 = V_381 -> V_95 . V_397 ;
F_83 ( & V_284 -> V_328 ) ;
F_83 ( & V_284 -> V_300 ) ;
F_83 ( & V_284 -> V_296 ) ;
F_82 ( & V_284 -> V_214 ) ;
V_284 -> V_288 = NULL ;
V_284 -> V_81 . V_305 = V_387 ;
V_284 -> V_12 = V_317 ;
F_64 ( & V_284 -> V_81 . V_398 , & V_387 -> V_223 ) ;
}
V_387 -> V_95 = & V_381 -> V_95 ;
if ( V_384 ) {
V_387 -> V_399 = V_384 -> V_399 ;
} else {
F_154 ( V_400 , V_387 -> V_399 ) ;
if ( V_204 -> V_15 . V_213 ) {
F_154 ( V_401 , V_387 -> V_399 ) ;
F_154 ( V_402 , V_387 -> V_399 ) ;
F_154 ( V_403 , V_387 -> V_399 ) ;
}
}
V_387 -> V_404 = F_105 ;
V_387 -> V_405 = F_111 ;
V_387 -> V_406 = F_131 ;
V_387 -> V_407 = F_129 ;
V_387 -> V_408 = F_112 ;
V_387 -> V_409 = F_134 ;
V_387 -> V_410 = F_107 ;
V_387 -> V_411 = F_114 ;
V_387 -> V_412 = F_139 ;
V_207 = F_155 ( V_387 ) ;
if ( V_207 ) {
F_34 ( & V_381 -> V_95 , L_48 ) ;
goto V_413;
}
if ( V_381 -> V_95 . V_397 ) {
V_207 = F_156 ( V_381 -> V_95 . V_397 ,
F_103 , V_317 ) ;
if ( V_207 ) {
F_34 ( & V_381 -> V_95 ,
L_49 ) ;
}
}
V_381 -> V_95 . V_414 = & V_317 -> V_414 ;
V_207 = F_157 ( & V_381 -> V_95 , 1900800 ) ;
if ( V_207 )
F_34 ( & V_381 -> V_95 , L_50 ) ;
F_41 ( & V_381 -> V_95 ,
L_51 , V_381 -> V_392 ) ;
F_41 ( & V_381 -> V_95 ,
L_52 ,
V_204 -> V_15 . V_256 ,
V_204 -> V_15 . V_253 / 8 , V_204 -> V_15 . V_16 ,
V_204 -> V_15 . V_213 , V_204 -> V_15 . V_232 ) ;
return 0 ;
V_413:
F_65 (pch, _p, &pdmac->ddma.channels,
chan.device_node) {
F_66 ( & V_284 -> V_81 . V_398 ) ;
F_107 ( & V_284 -> V_81 , V_327 , 0 ) ;
F_111 ( & V_284 -> V_81 ) ;
}
V_396:
F_88 ( V_204 ) ;
return V_207 ;
}
static int F_158 ( struct V_380 * V_381 )
{
struct V_316 * V_317 = F_159 ( V_381 ) ;
struct V_277 * V_284 , * V_385 ;
struct V_203 * V_204 ;
if ( ! V_317 )
return 0 ;
if ( V_381 -> V_95 . V_397 )
F_160 ( V_381 -> V_95 . V_397 ) ;
F_161 ( & V_317 -> V_394 ) ;
F_65 (pch, _p, &pdmac->ddma.channels,
chan.device_node) {
F_66 ( & V_284 -> V_81 . V_398 ) ;
F_107 ( & V_284 -> V_81 , V_327 , 0 ) ;
F_111 ( & V_284 -> V_81 ) ;
}
V_204 = & V_317 -> V_290 ;
F_88 ( V_204 ) ;
return 0 ;
}
