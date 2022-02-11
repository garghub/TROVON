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
static inline T_1 F_7 ( struct V_19 * V_20 , T_1 V_21 )
{
void T_2 * V_22 = V_20 -> V_23 ;
T_1 V_13 = 0 ;
V_13 |= ( F_8 ( V_22 + V_21 + 0x0 ) << 0 ) ;
V_13 |= ( F_8 ( V_22 + V_21 + 0x4 ) << 8 ) ;
V_13 |= ( F_8 ( V_22 + V_21 + 0x8 ) << 16 ) ;
V_13 |= ( F_8 ( V_22 + V_21 + 0xc ) << 24 ) ;
return V_13 ;
}
static inline T_1 F_9 ( T_1 V_24 )
{
return ( V_24 >> V_25 ) & V_26 ;
}
static inline T_1 F_10 ( unsigned V_27 , T_3 V_28 [] ,
enum V_29 V_30 , T_4 V_31 )
{
if ( V_27 )
return V_32 ;
V_28 [ 0 ] = V_33 ;
V_28 [ 0 ] |= ( V_30 << 1 ) ;
* ( ( T_4 * ) & V_28 [ 1 ] ) = V_31 ;
F_11 ( V_32 , L_1 ,
V_30 == 1 ? L_2 : L_3 , V_31 ) ;
return V_32 ;
}
static inline T_1 F_12 ( unsigned V_27 , T_3 V_28 [] )
{
if ( V_27 )
return V_34 ;
V_28 [ 0 ] = V_35 ;
F_11 ( V_34 , L_4 ) ;
return V_34 ;
}
static inline T_1 F_13 ( unsigned V_27 , T_3 V_28 [] , T_3 V_36 )
{
if ( V_27 )
return V_37 ;
V_28 [ 0 ] = V_38 ;
V_36 &= 0x1f ;
V_36 <<= 3 ;
V_28 [ 1 ] = V_36 ;
F_11 ( V_37 , L_5 , V_36 >> 3 ) ;
return V_37 ;
}
static inline T_1 F_14 ( unsigned V_27 , T_3 V_28 [] , enum V_39 V_40 )
{
if ( V_27 )
return V_41 ;
V_28 [ 0 ] = V_42 ;
if ( V_40 == V_43 )
V_28 [ 0 ] |= ( 0 << 1 ) | ( 1 << 0 ) ;
else if ( V_40 == V_44 )
V_28 [ 0 ] |= ( 1 << 1 ) | ( 1 << 0 ) ;
F_11 ( V_41 , L_6 ,
V_40 == V_43 ? 'S' : ( V_40 == V_44 ? 'B' : 'A' ) ) ;
return V_41 ;
}
static inline T_1 F_15 ( unsigned V_27 , T_3 V_28 [] ,
enum V_39 V_40 , T_3 V_36 )
{
if ( V_27 )
return V_45 ;
V_28 [ 0 ] = V_46 ;
if ( V_40 == V_44 )
V_28 [ 0 ] |= ( 1 << 1 ) ;
V_36 &= 0x1f ;
V_36 <<= 3 ;
V_28 [ 1 ] = V_36 ;
F_11 ( V_45 , L_7 ,
V_40 == V_43 ? 'S' : 'B' , V_36 >> 3 ) ;
return V_45 ;
}
static inline T_1 F_16 ( unsigned V_27 , T_3 V_28 [] ,
unsigned V_47 , T_3 V_48 )
{
if ( V_27 )
return V_49 ;
V_28 [ 0 ] = V_50 ;
if ( V_47 )
V_28 [ 0 ] |= ( 1 << 1 ) ;
V_48 -- ;
V_28 [ 1 ] = V_48 ;
F_11 ( V_49 , L_8 , V_47 ? '1' : '0' , V_48 ) ;
return V_49 ;
}
static inline T_1 F_17 ( unsigned V_27 , T_3 V_28 [] ,
const struct V_51 * V_52 )
{
enum V_39 V_40 = V_52 -> V_40 ;
bool V_53 = V_52 -> V_53 ;
unsigned V_47 = V_52 -> V_47 ;
T_3 V_54 = V_52 -> V_54 ;
if ( V_27 )
return V_55 ;
V_28 [ 0 ] = V_56 ;
if ( V_47 )
V_28 [ 0 ] |= ( 1 << 2 ) ;
if ( ! V_53 )
V_28 [ 0 ] |= ( 1 << 4 ) ;
if ( V_40 == V_43 )
V_28 [ 0 ] |= ( 0 << 1 ) | ( 1 << 0 ) ;
else if ( V_40 == V_44 )
V_28 [ 0 ] |= ( 1 << 1 ) | ( 1 << 0 ) ;
V_28 [ 1 ] = V_54 ;
F_11 ( V_55 , L_9 ,
V_53 ? L_10 : L_11 ,
V_40 == V_43 ? 'S' : ( V_40 == V_44 ? 'B' : 'A' ) ,
V_47 ? '1' : '0' ,
V_54 ) ;
return V_55 ;
}
static inline T_1 F_18 ( unsigned V_27 , T_3 V_28 [] )
{
if ( V_27 )
return V_57 ;
V_28 [ 0 ] = V_58 ;
return V_57 ;
}
static inline T_1 F_19 ( unsigned V_27 , T_3 V_28 [] ,
enum V_59 V_60 , T_1 V_31 )
{
if ( V_27 )
return V_61 ;
V_28 [ 0 ] = V_62 ;
V_28 [ 1 ] = V_60 ;
* ( ( T_1 * ) & V_28 [ 2 ] ) = V_31 ;
F_11 ( V_61 , L_12 ,
V_60 == V_63 ? L_13 : ( V_60 == V_64 ? L_14 : L_15 ) , V_31 ) ;
return V_61 ;
}
static inline T_1 F_20 ( unsigned V_27 , T_3 V_28 [] )
{
if ( V_27 )
return V_65 ;
V_28 [ 0 ] = V_66 ;
F_11 ( V_65 , L_16 ) ;
return V_65 ;
}
static inline T_1 F_21 ( unsigned V_27 , T_3 V_28 [] )
{
if ( V_27 )
return V_67 ;
V_28 [ 0 ] = V_68 ;
F_11 ( V_67 , L_17 ) ;
return V_67 ;
}
static inline T_1 F_22 ( unsigned V_27 , T_3 V_28 [] , T_3 V_69 )
{
if ( V_27 )
return V_70 ;
V_28 [ 0 ] = V_71 ;
V_69 &= 0x1f ;
V_69 <<= 3 ;
V_28 [ 1 ] = V_69 ;
F_11 ( V_70 , L_18 , V_69 >> 3 ) ;
return V_70 ;
}
static inline T_1 F_23 ( unsigned V_27 , T_3 V_28 [] , enum V_39 V_40 )
{
if ( V_27 )
return V_72 ;
V_28 [ 0 ] = V_73 ;
if ( V_40 == V_43 )
V_28 [ 0 ] |= ( 0 << 1 ) | ( 1 << 0 ) ;
else if ( V_40 == V_44 )
V_28 [ 0 ] |= ( 1 << 1 ) | ( 1 << 0 ) ;
F_11 ( V_72 , L_19 ,
V_40 == V_43 ? 'S' : ( V_40 == V_44 ? 'B' : 'A' ) ) ;
return V_72 ;
}
static inline T_1 F_24 ( unsigned V_27 , T_3 V_28 [] ,
enum V_39 V_40 , T_3 V_36 )
{
if ( V_27 )
return V_74 ;
V_28 [ 0 ] = V_75 ;
if ( V_40 == V_44 )
V_28 [ 0 ] |= ( 1 << 1 ) ;
V_36 &= 0x1f ;
V_36 <<= 3 ;
V_28 [ 1 ] = V_36 ;
F_11 ( V_74 , L_20 ,
V_40 == V_43 ? 'S' : 'B' , V_36 >> 3 ) ;
return V_74 ;
}
static inline T_1 F_25 ( unsigned V_27 , T_3 V_28 [] )
{
if ( V_27 )
return V_76 ;
V_28 [ 0 ] = V_77 ;
F_11 ( V_76 , L_21 ) ;
return V_76 ;
}
static inline T_1 F_26 ( unsigned V_27 , T_3 V_28 [] , T_3 V_69 ,
unsigned V_78 )
{
if ( V_27 )
return V_79 ;
V_28 [ 0 ] = V_80 ;
V_69 &= 0x1f ;
V_69 <<= 3 ;
V_28 [ 1 ] = V_69 ;
if ( V_78 )
V_28 [ 1 ] |= ( 1 << 1 ) ;
F_11 ( V_79 , L_22 ,
V_69 >> 3 , V_78 ? L_23 : L_24 ) ;
return V_79 ;
}
static inline T_1 F_27 ( unsigned V_27 , T_3 V_28 [] ,
enum V_39 V_40 , T_3 V_36 )
{
if ( V_27 )
return V_81 ;
V_28 [ 0 ] = V_82 ;
if ( V_40 == V_43 )
V_28 [ 0 ] |= ( 0 << 1 ) | ( 0 << 0 ) ;
else if ( V_40 == V_44 )
V_28 [ 0 ] |= ( 1 << 1 ) | ( 0 << 0 ) ;
else
V_28 [ 0 ] |= ( 0 << 1 ) | ( 1 << 0 ) ;
V_36 &= 0x1f ;
V_36 <<= 3 ;
V_28 [ 1 ] = V_36 ;
F_11 ( V_81 , L_25 ,
V_40 == V_43 ? 'S' : ( V_40 == V_44 ? 'B' : 'P' ) , V_36 >> 3 ) ;
return V_81 ;
}
static inline T_1 F_28 ( unsigned V_27 , T_3 V_28 [] )
{
if ( V_27 )
return V_83 ;
V_28 [ 0 ] = V_84 ;
F_11 ( V_83 , L_26 ) ;
return V_83 ;
}
static inline T_1 F_29 ( unsigned V_27 , T_3 V_28 [] ,
const struct V_85 * V_52 )
{
T_3 V_86 = V_52 -> V_86 ;
T_1 V_87 = V_52 -> V_87 ;
unsigned V_88 = V_52 -> V_88 ;
if ( V_27 )
return V_89 ;
V_28 [ 0 ] = V_90 ;
V_28 [ 0 ] |= ( V_88 << 1 ) ;
V_28 [ 1 ] = V_86 & 0x7 ;
* ( ( T_1 * ) & V_28 [ 2 ] ) = V_87 ;
return V_89 ;
}
static bool F_30 ( struct V_7 * V_8 )
{
void T_2 * V_22 = V_8 -> V_12 -> V_14 -> V_23 ;
unsigned long V_91 = F_31 ( 5 ) ;
do {
if ( ! ( F_32 ( V_22 + V_92 ) & V_93 ) )
break;
F_33 () ;
} while ( -- V_91 );
if ( ! V_91 )
return true ;
return false ;
}
static inline void F_34 ( struct V_7 * V_8 ,
T_3 V_94 [] , bool V_95 )
{
void T_2 * V_22 = V_8 -> V_12 -> V_14 -> V_23 ;
T_1 V_31 ;
V_31 = ( V_94 [ 0 ] << 16 ) | ( V_94 [ 1 ] << 24 ) ;
if ( ! V_95 ) {
V_31 |= ( 1 << 0 ) ;
V_31 |= ( V_8 -> V_13 << 8 ) ;
}
F_35 ( V_31 , V_22 + V_96 ) ;
V_31 = * ( ( T_1 * ) & V_94 [ 2 ] ) ;
F_35 ( V_31 , V_22 + V_97 ) ;
if ( F_30 ( V_8 ) ) {
F_36 ( V_8 -> V_12 -> V_14 -> V_98 , L_27 ) ;
return;
}
F_35 ( 0 , V_22 + V_99 ) ;
}
static void F_37 ( struct V_7 * V_8 , int V_100 )
{
struct V_101 * V_9 = & V_8 -> V_9 [ V_100 ] ;
F_12 ( 0 , V_9 -> V_102 ) ;
V_9 -> V_103 = 0 ;
V_8 -> V_104 = - 1 ;
}
static inline T_1 F_38 ( struct V_7 * V_8 )
{
void T_2 * V_22 = V_8 -> V_12 -> V_14 -> V_23 ;
T_1 V_31 ;
if ( F_5 ( V_8 ) )
V_31 = F_32 ( V_22 + V_105 ) & 0xf ;
else
V_31 = F_32 ( V_22 + F_39 ( V_8 -> V_13 ) ) & 0xf ;
switch ( V_31 ) {
case V_106 :
return V_107 ;
case V_108 :
return V_109 ;
case V_110 :
return V_111 ;
case V_112 :
return V_113 ;
case V_114 :
return V_115 ;
case V_116 :
return V_117 ;
case V_118 :
if ( F_5 ( V_8 ) )
return V_119 ;
else
return V_120 ;
case V_121 :
if ( F_5 ( V_8 ) )
return V_119 ;
else
return V_122 ;
case V_123 :
if ( F_5 ( V_8 ) )
return V_119 ;
else
return V_124 ;
case V_125 :
if ( F_5 ( V_8 ) )
return V_119 ;
else
return V_126 ;
case V_127 :
if ( F_5 ( V_8 ) )
return V_119 ;
else
return V_128 ;
case V_129 :
if ( F_5 ( V_8 ) )
return V_119 ;
else
return V_130 ;
default:
return V_119 ;
}
}
static void F_40 ( struct V_7 * V_8 )
{
void T_2 * V_22 = V_8 -> V_12 -> V_14 -> V_23 ;
T_3 V_94 [ 6 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
if ( F_38 ( V_8 ) == V_130 )
F_41 ( V_8 , V_117 | V_126 ) ;
if ( F_38 ( V_8 ) == V_128
|| F_38 ( V_8 ) == V_126
|| F_38 ( V_8 ) == V_107 )
return;
F_18 ( 0 , V_94 ) ;
F_35 ( F_32 ( V_22 + V_131 ) & ~ ( 1 << V_8 -> V_69 ) , V_22 + V_131 ) ;
F_34 ( V_8 , V_94 , F_5 ( V_8 ) ) ;
}
static bool F_42 ( struct V_7 * V_8 )
{
void T_2 * V_22 = V_8 -> V_12 -> V_14 -> V_23 ;
struct V_101 * V_9 ;
struct V_1 * V_2 ;
struct V_85 V_132 ;
unsigned V_88 ;
T_3 V_94 [ 6 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_100 ;
if ( F_38 ( V_8 ) != V_107 )
return true ;
V_100 = 1 - V_8 -> V_133 ;
if ( ! F_3 ( & V_8 -> V_9 [ V_100 ] ) )
V_9 = & V_8 -> V_9 [ V_100 ] ;
else {
V_100 = V_8 -> V_133 ;
if ( ! F_3 ( & V_8 -> V_9 [ V_100 ] ) )
V_9 = & V_8 -> V_9 [ V_100 ] ;
else
V_9 = NULL ;
}
if ( ! V_9 || ! V_9 -> V_2 )
return true ;
V_2 = V_9 -> V_2 ;
if ( V_2 -> V_134 )
V_88 = V_2 -> V_134 -> V_135 ? 1 : 0 ;
else if ( F_32 ( V_22 + F_39 ( V_8 -> V_13 ) ) & V_136 )
V_88 = 1 ;
else
V_88 = 0 ;
if ( F_6 ( V_8 ) && ! V_88 )
F_43 ( V_8 -> V_12 -> V_14 -> V_98 , L_28 ,
V_137 , __LINE__ ) ;
V_132 . V_86 = V_8 -> V_13 ;
V_132 . V_87 = V_9 -> V_138 ;
V_132 . V_88 = V_88 ;
F_29 ( 0 , V_94 , & V_132 ) ;
F_35 ( F_32 ( V_22 + V_131 ) | ( 1 << V_8 -> V_69 ) , V_22 + V_131 ) ;
F_34 ( V_8 , V_94 , true ) ;
V_8 -> V_104 = V_100 ;
return true ;
}
static bool F_44 ( struct V_7 * V_8 )
{
switch ( F_38 ( V_8 ) ) {
case V_130 :
F_41 ( V_8 , V_117 | V_126 ) ;
if ( F_38 ( V_8 ) == V_126 )
F_41 (thrd, PL330_STATE_STOPPED)
case V_117 :
F_40 ( V_8 ) ;
case V_126 :
case V_128 :
F_41 (thrd, PL330_STATE_STOPPED)
case V_107 :
return F_42 ( V_8 ) ;
case V_124 :
case V_122 :
case V_120 :
case V_113 :
case V_111 :
case V_109 :
return true ;
case V_115 :
default:
return false ;
}
}
static inline int F_45 ( unsigned V_27 , T_3 V_28 [] ,
const struct V_139 * V_140 , int V_141 )
{
int V_21 = 0 ;
struct V_142 * V_15 = V_140 -> V_2 -> V_134 -> V_15 ;
if ( F_9 ( V_15 -> V_24 ) >= V_143 ) {
while ( V_141 -- ) {
V_21 += F_14 ( V_27 , & V_28 [ V_21 ] , V_144 ) ;
V_21 += F_23 ( V_27 , & V_28 [ V_21 ] , V_144 ) ;
}
} else {
while ( V_141 -- ) {
V_21 += F_14 ( V_27 , & V_28 [ V_21 ] , V_144 ) ;
V_21 += F_21 ( V_27 , & V_28 [ V_21 ] ) ;
V_21 += F_23 ( V_27 , & V_28 [ V_21 ] , V_144 ) ;
V_21 += F_28 ( V_27 , & V_28 [ V_21 ] ) ;
}
}
return V_21 ;
}
static inline int F_46 ( unsigned V_27 , T_3 V_28 [] ,
const struct V_139 * V_140 , int V_141 )
{
int V_21 = 0 ;
while ( V_141 -- ) {
V_21 += F_27 ( V_27 , & V_28 [ V_21 ] , V_43 , V_140 -> V_2 -> V_36 ) ;
V_21 += F_15 ( V_27 , & V_28 [ V_21 ] , V_43 , V_140 -> V_2 -> V_36 ) ;
V_21 += F_23 ( V_27 , & V_28 [ V_21 ] , V_144 ) ;
V_21 += F_13 ( V_27 , & V_28 [ V_21 ] , V_140 -> V_2 -> V_36 ) ;
}
return V_21 ;
}
static inline int F_47 ( unsigned V_27 , T_3 V_28 [] ,
const struct V_139 * V_140 , int V_141 )
{
int V_21 = 0 ;
while ( V_141 -- ) {
V_21 += F_27 ( V_27 , & V_28 [ V_21 ] , V_43 , V_140 -> V_2 -> V_36 ) ;
V_21 += F_14 ( V_27 , & V_28 [ V_21 ] , V_144 ) ;
V_21 += F_24 ( V_27 , & V_28 [ V_21 ] , V_43 , V_140 -> V_2 -> V_36 ) ;
V_21 += F_13 ( V_27 , & V_28 [ V_21 ] , V_140 -> V_2 -> V_36 ) ;
}
return V_21 ;
}
static int F_48 ( unsigned V_27 , T_3 V_28 [] ,
const struct V_139 * V_140 , int V_141 )
{
int V_21 = 0 ;
switch ( V_140 -> V_2 -> V_145 ) {
case V_146 :
V_21 += F_47 ( V_27 , & V_28 [ V_21 ] , V_140 , V_141 ) ;
break;
case V_147 :
V_21 += F_46 ( V_27 , & V_28 [ V_21 ] , V_140 , V_141 ) ;
break;
case V_148 :
V_21 += F_45 ( V_27 , & V_28 [ V_21 ] , V_140 , V_141 ) ;
break;
default:
V_21 += 0x40000000 ;
break;
}
return V_21 ;
}
static inline int F_49 ( unsigned V_27 , T_3 V_28 [] ,
unsigned long * V_149 , const struct V_139 * V_140 )
{
int V_141 , V_150 , V_151 , V_152 , V_153 , V_21 ;
unsigned V_154 , V_155 , V_156 , V_157 ;
struct V_51 V_158 ;
if ( * V_149 >= 256 * 256 ) {
V_155 = 256 ;
V_154 = 256 ;
V_141 = * V_149 / V_155 / V_154 ;
} else if ( * V_149 > 256 ) {
V_155 = 256 ;
V_154 = * V_149 / V_155 ;
V_141 = 1 ;
} else {
V_155 = * V_149 ;
V_154 = 0 ;
V_141 = 1 ;
}
V_151 = F_16 ( 1 , V_28 , 0 , 0 ) ;
V_153 = F_48 ( 1 , V_28 , V_140 , 1 ) ;
V_158 . V_40 = V_144 ;
V_158 . V_53 = false ;
V_158 . V_47 = 0 ;
V_158 . V_54 = 0 ;
V_152 = F_17 ( 1 , V_28 , & V_158 ) ;
if ( V_154 ) {
V_151 *= 2 ;
V_152 *= 2 ;
}
V_150 = ( 255 - ( V_151 + V_152 ) ) / V_153 ;
V_141 = ( V_150 < V_141 ) ? V_150 : V_141 ;
V_21 = 0 ;
if ( V_154 ) {
V_21 += F_16 ( V_27 , & V_28 [ V_21 ] , 0 , V_154 ) ;
V_156 = V_21 ;
}
V_21 += F_16 ( V_27 , & V_28 [ V_21 ] , 1 , V_155 ) ;
V_157 = V_21 ;
V_21 += F_48 ( V_27 , & V_28 [ V_21 ] , V_140 , V_141 ) ;
V_158 . V_40 = V_144 ;
V_158 . V_53 = false ;
V_158 . V_47 = 1 ;
V_158 . V_54 = V_21 - V_157 ;
V_21 += F_17 ( V_27 , & V_28 [ V_21 ] , & V_158 ) ;
if ( V_154 ) {
V_158 . V_40 = V_144 ;
V_158 . V_53 = false ;
V_158 . V_47 = 0 ;
V_158 . V_54 = V_21 - V_156 ;
V_21 += F_17 ( V_27 , & V_28 [ V_21 ] , & V_158 ) ;
}
* V_149 = V_155 * V_141 ;
if ( V_154 )
* V_149 *= V_154 ;
return V_21 ;
}
static inline int F_50 ( unsigned V_27 , T_3 V_28 [] ,
const struct V_139 * V_140 )
{
struct V_159 * V_160 = V_140 -> V_160 ;
T_1 V_161 = V_140 -> V_161 ;
unsigned long V_162 , V_149 = F_51 ( V_160 -> V_163 , V_161 ) ;
int V_21 = 0 ;
while ( V_149 ) {
V_162 = V_149 ;
V_21 += F_49 ( V_27 , & V_28 [ V_21 ] , & V_162 , V_140 ) ;
V_149 -= V_162 ;
}
return V_21 ;
}
static inline int F_52 ( unsigned V_27 , T_3 V_28 [] ,
const struct V_139 * V_140 )
{
struct V_159 * V_160 = V_140 -> V_160 ;
int V_21 = 0 ;
V_21 += F_19 ( V_27 , & V_28 [ V_21 ] , V_63 , V_160 -> V_164 ) ;
V_21 += F_19 ( V_27 , & V_28 [ V_21 ] , V_64 , V_160 -> V_165 ) ;
V_21 += F_50 ( V_27 , & V_28 [ V_21 ] , V_140 ) ;
return V_21 ;
}
static int F_53 ( unsigned V_27 , struct V_7 * V_8 ,
unsigned V_166 , struct V_139 * V_140 )
{
struct V_101 * V_9 = & V_8 -> V_9 [ V_166 ] ;
struct V_159 * V_160 ;
T_3 * V_28 = V_9 -> V_102 ;
int V_21 = 0 ;
F_54 ( V_9 -> V_138 ) ;
V_21 += F_19 ( V_27 , & V_28 [ V_21 ] , V_167 , V_140 -> V_161 ) ;
V_160 = V_140 -> V_2 -> V_160 ;
do {
if ( V_160 -> V_163 % ( F_55 ( V_140 -> V_161 ) * F_56 ( V_140 -> V_161 ) ) )
return - V_168 ;
V_140 -> V_160 = V_160 ;
V_21 += F_52 ( V_27 , & V_28 [ V_21 ] , V_140 ) ;
V_160 = V_160 -> V_169 ;
} while ( V_160 );
V_21 += F_22 ( V_27 , & V_28 [ V_21 ] , V_8 -> V_69 ) ;
V_21 += F_12 ( V_27 , & V_28 [ V_21 ] ) ;
return V_21 ;
}
static inline T_1 F_57 ( const struct V_170 * V_171 )
{
T_1 V_161 = 0 ;
if ( V_171 -> V_172 )
V_161 |= V_173 ;
if ( V_171 -> V_174 )
V_161 |= V_175 ;
if ( V_171 -> V_176 )
V_161 |= V_177 | V_178 ;
if ( V_171 -> V_135 )
V_161 |= V_179 | V_180 ;
if ( V_171 -> V_181 )
V_161 |= V_182 | V_183 ;
V_161 |= ( ( ( V_171 -> V_184 - 1 ) & 0xf ) << V_185 ) ;
V_161 |= ( ( ( V_171 -> V_184 - 1 ) & 0xf ) << V_186 ) ;
V_161 |= ( V_171 -> V_187 << V_188 ) ;
V_161 |= ( V_171 -> V_187 << V_189 ) ;
V_161 |= ( V_171 -> V_190 << V_191 ) ;
V_161 |= ( V_171 -> V_192 << V_193 ) ;
V_161 |= ( V_171 -> V_194 << V_195 ) ;
return V_161 ;
}
static inline bool F_58 ( T_1 V_161 )
{
enum V_196 V_192 ;
enum V_197 V_190 ;
V_192 = ( V_161 >> V_193 ) & V_198 ;
V_190 = ( V_161 >> V_191 ) & V_199 ;
if ( V_192 == V_200 || V_192 == V_201
|| V_190 == V_202 || V_190 == V_203 )
return false ;
else
return true ;
}
static int F_59 ( void * V_204 , struct V_1 * V_2 )
{
struct V_7 * V_8 = V_204 ;
struct V_10 * V_11 ;
struct V_19 * V_20 ;
struct V_139 V_205 ;
unsigned long V_206 ;
void T_2 * V_22 ;
unsigned V_100 ;
T_1 V_161 ;
int V_207 = 0 ;
if ( ! V_2 || ! V_8 || V_8 -> free )
return - V_168 ;
V_11 = V_8 -> V_12 ;
V_20 = V_11 -> V_14 ;
V_22 = V_20 -> V_23 ;
if ( V_11 -> V_208 == V_209
|| V_11 -> V_210 . V_211 & ( 1 << V_8 -> V_13 ) ) {
F_43 ( V_8 -> V_12 -> V_14 -> V_98 , L_29 ,
V_137 , __LINE__ ) ;
return - V_212 ;
}
if ( V_2 -> V_145 != V_148 && V_2 -> V_36 >= V_20 -> V_15 . V_213 ) {
F_43 ( V_8 -> V_12 -> V_14 -> V_98 ,
L_30 ,
V_137 , __LINE__ , V_2 -> V_36 ) ;
return - V_168 ;
}
F_60 ( & V_11 -> V_214 , V_206 ) ;
if ( F_4 ( V_8 ) ) {
V_207 = - V_212 ;
goto V_215;
}
if ( ! F_6 ( V_8 ) )
V_2 -> V_134 -> V_135 = 0 ;
else
V_2 -> V_134 -> V_135 = 1 ;
if ( V_2 -> V_134 )
V_161 = F_57 ( V_2 -> V_134 ) ;
else
V_161 = F_32 ( V_22 + F_61 ( V_8 -> V_13 ) ) ;
if ( ! F_58 ( V_161 ) ) {
V_207 = - V_168 ;
F_43 ( V_8 -> V_12 -> V_14 -> V_98 , L_31 ,
V_137 , __LINE__ , V_161 ) ;
goto V_215;
}
V_100 = F_3 ( & V_8 -> V_9 [ 0 ] ) ? 0 : 1 ;
V_205 . V_161 = V_161 ;
V_205 . V_2 = V_2 ;
V_207 = F_53 ( 1 , V_8 , V_100 , & V_205 ) ;
if ( V_207 < 0 )
goto V_215;
if ( V_207 > V_20 -> V_216 / 2 ) {
F_43 ( V_8 -> V_12 -> V_14 -> V_98 ,
L_32 ,
V_137 , __LINE__ ) ;
V_207 = - V_217 ;
goto V_215;
}
V_8 -> V_133 = V_100 ;
V_8 -> V_9 [ V_100 ] . V_103 = F_53 ( 0 , V_8 , V_100 , & V_205 ) ;
V_8 -> V_9 [ V_100 ] . V_2 = V_2 ;
V_207 = 0 ;
V_215:
F_62 ( & V_11 -> V_214 , V_206 ) ;
return V_207 ;
}
static void F_63 ( unsigned long V_218 )
{
struct V_10 * V_11 = (struct V_10 * ) V_218 ;
struct V_19 * V_20 = V_11 -> V_14 ;
unsigned long V_206 ;
int V_219 ;
F_60 ( & V_11 -> V_214 , V_206 ) ;
if ( V_11 -> V_210 . V_220 ) {
V_11 -> V_208 = V_209 ;
V_11 -> V_210 . V_221 = true ;
V_11 -> V_210 . V_220 = false ;
}
if ( V_11 -> V_210 . V_221 ) {
F_40 ( V_11 -> V_222 ) ;
V_11 -> V_210 . V_211 = ( 1 << V_20 -> V_15 . V_16 ) - 1 ;
V_11 -> V_210 . V_221 = false ;
}
for ( V_219 = 0 ; V_219 < V_20 -> V_15 . V_16 ; V_219 ++ ) {
if ( V_11 -> V_210 . V_211 & ( 1 << V_219 ) ) {
struct V_7 * V_8 = & V_11 -> V_223 [ V_219 ] ;
void T_2 * V_22 = V_20 -> V_23 ;
enum V_3 V_4 ;
F_40 ( V_8 ) ;
if ( F_32 ( V_22 + V_224 ) & ( 1 << V_8 -> V_13 ) )
V_4 = V_225 ;
else
V_4 = V_226 ;
F_62 ( & V_11 -> V_214 , V_206 ) ;
F_1 ( V_8 -> V_9 [ 1 - V_8 -> V_133 ] . V_2 , V_4 ) ;
F_1 ( V_8 -> V_9 [ V_8 -> V_133 ] . V_2 , V_4 ) ;
F_60 ( & V_11 -> V_214 , V_206 ) ;
V_8 -> V_9 [ 0 ] . V_2 = NULL ;
V_8 -> V_9 [ 1 ] . V_2 = NULL ;
F_37 ( V_8 , 0 ) ;
F_37 ( V_8 , 1 ) ;
V_11 -> V_210 . V_211 &= ~ ( 1 << V_219 ) ;
}
}
F_62 ( & V_11 -> V_214 , V_206 ) ;
return;
}
static int F_64 ( const struct V_19 * V_20 )
{
struct V_101 * V_227 ;
struct V_10 * V_11 ;
unsigned long V_206 ;
void T_2 * V_22 ;
T_1 V_31 ;
int V_13 , V_69 , V_207 = 0 ;
if ( ! V_20 || ! V_20 -> V_228 )
return 0 ;
V_22 = V_20 -> V_23 ;
V_11 = V_20 -> V_228 ;
F_60 ( & V_11 -> V_214 , V_206 ) ;
V_31 = F_32 ( V_22 + V_229 ) & 0x1 ;
if ( V_31 )
V_11 -> V_210 . V_221 = true ;
else
V_11 -> V_210 . V_221 = false ;
V_31 = F_32 ( V_22 + V_224 ) & ( ( 1 << V_20 -> V_15 . V_16 ) - 1 ) ;
V_11 -> V_210 . V_211 |= V_31 ;
if ( V_31 ) {
int V_219 = 0 ;
while ( V_219 < V_20 -> V_15 . V_16 ) {
if ( V_31 & ( 1 << V_219 ) ) {
F_43 ( V_20 -> V_98 ,
L_33 ,
V_219 , F_32 ( V_22 + F_39 ( V_219 ) ) ,
F_32 ( V_22 + F_65 ( V_219 ) ) ) ;
F_40 ( & V_11 -> V_223 [ V_219 ] ) ;
}
V_219 ++ ;
}
}
V_31 = F_32 ( V_22 + V_230 ) ;
if ( V_20 -> V_15 . V_231 < 32
&& V_31 & ~ ( ( 1 << V_20 -> V_15 . V_231 ) - 1 ) ) {
V_11 -> V_210 . V_220 = true ;
F_36 ( V_20 -> V_98 , L_34 , V_137 , __LINE__ ) ;
V_207 = 1 ;
goto V_232;
}
for ( V_69 = 0 ; V_69 < V_20 -> V_15 . V_231 ; V_69 ++ ) {
if ( V_31 & ( 1 << V_69 ) ) {
struct V_7 * V_8 ;
T_1 V_233 = F_32 ( V_22 + V_131 ) ;
int V_234 ;
if ( V_233 & ( 1 << V_69 ) )
F_35 ( 1 << V_69 , V_22 + V_235 ) ;
V_207 = 1 ;
V_13 = V_11 -> V_236 [ V_69 ] ;
V_8 = & V_11 -> V_223 [ V_13 ] ;
V_234 = V_8 -> V_104 ;
if ( V_234 == - 1 )
continue;
V_227 = & V_8 -> V_9 [ V_234 ] ;
F_37 ( V_8 , V_234 ) ;
F_44 ( V_8 ) ;
F_66 ( & V_227 -> V_237 , & V_11 -> V_238 ) ;
}
}
while ( ! F_67 ( & V_11 -> V_238 ) ) {
struct V_1 * V_2 ;
V_227 = F_68 ( V_11 -> V_238 . V_169 ,
struct V_101 , V_237 ) ;
F_69 ( & V_227 -> V_237 ) ;
V_2 = V_227 -> V_2 ;
V_227 -> V_2 = NULL ;
F_62 ( & V_11 -> V_214 , V_206 ) ;
F_1 ( V_2 , V_239 ) ;
F_60 ( & V_11 -> V_214 , V_206 ) ;
}
V_232:
F_62 ( & V_11 -> V_214 , V_206 ) ;
if ( V_11 -> V_210 . V_220
|| V_11 -> V_210 . V_221
|| V_11 -> V_210 . V_211 ) {
V_207 = 1 ;
F_70 ( & V_11 -> V_240 ) ;
}
return V_207 ;
}
static int F_71 ( void * V_204 , enum V_241 V_242 )
{
struct V_7 * V_8 = V_204 ;
struct V_10 * V_11 ;
unsigned long V_206 ;
int V_207 = 0 , V_234 ;
if ( ! V_8 || V_8 -> free || V_8 -> V_12 -> V_208 == V_209 )
return - V_168 ;
V_11 = V_8 -> V_12 ;
V_234 = V_8 -> V_104 ;
F_60 ( & V_11 -> V_214 , V_206 ) ;
switch ( V_242 ) {
case V_243 :
F_40 ( V_8 ) ;
V_8 -> V_9 [ 0 ] . V_2 = NULL ;
V_8 -> V_9 [ 1 ] . V_2 = NULL ;
F_37 ( V_8 , 0 ) ;
F_37 ( V_8 , 1 ) ;
break;
case V_244 :
F_40 ( V_8 ) ;
if ( V_234 == - 1 )
break;
V_8 -> V_9 [ V_234 ] . V_2 = NULL ;
F_37 ( V_8 , V_234 ) ;
case V_245 :
if ( ( V_234 == - 1 ) && ! F_44 ( V_8 ) )
V_207 = - V_246 ;
break;
default:
V_207 = - V_168 ;
}
F_62 ( & V_11 -> V_214 , V_206 ) ;
return V_207 ;
}
static inline int F_72 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_19 * V_20 = V_11 -> V_14 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_20 -> V_15 . V_231 ; V_69 ++ )
if ( V_11 -> V_236 [ V_69 ] == - 1 ) {
V_11 -> V_236 [ V_69 ] = V_8 -> V_13 ;
return V_69 ;
}
return - 1 ;
}
static bool F_73 ( const struct V_19 * V_20 , int V_219 )
{
return V_20 -> V_15 . V_247 & ( 1 << V_219 ) ;
}
static void * F_74 ( const struct V_19 * V_20 )
{
struct V_7 * V_8 = NULL ;
struct V_10 * V_11 ;
unsigned long V_206 ;
int V_248 , V_219 ;
if ( ! V_20 || ! V_20 -> V_228 )
return NULL ;
V_11 = V_20 -> V_228 ;
if ( V_11 -> V_208 == V_209 )
return NULL ;
V_248 = V_20 -> V_15 . V_16 ;
F_60 ( & V_11 -> V_214 , V_206 ) ;
for ( V_219 = 0 ; V_219 < V_248 ; V_219 ++ ) {
V_8 = & V_11 -> V_223 [ V_219 ] ;
if ( ( V_8 -> free ) && ( ! F_6 ( V_8 ) ||
F_73 ( V_20 , V_219 ) ) ) {
V_8 -> V_69 = F_72 ( V_8 ) ;
if ( V_8 -> V_69 >= 0 ) {
V_8 -> free = false ;
V_8 -> V_133 = 1 ;
V_8 -> V_9 [ 0 ] . V_2 = NULL ;
F_37 ( V_8 , 0 ) ;
V_8 -> V_9 [ 1 ] . V_2 = NULL ;
F_37 ( V_8 , 1 ) ;
break;
}
}
V_8 = NULL ;
}
F_62 ( & V_11 -> V_214 , V_206 ) ;
return V_8 ;
}
static inline void F_75 ( struct V_7 * V_8 , int V_69 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_19 * V_20 = V_11 -> V_14 ;
if ( V_69 >= 0 && V_69 < V_20 -> V_15 . V_231
&& V_11 -> V_236 [ V_69 ] == V_8 -> V_13 )
V_11 -> V_236 [ V_69 ] = - 1 ;
}
static void F_76 ( void * V_204 )
{
struct V_7 * V_8 = V_204 ;
struct V_10 * V_11 ;
unsigned long V_206 ;
if ( ! V_8 || V_8 -> free )
return;
F_40 ( V_8 ) ;
F_1 ( V_8 -> V_9 [ 1 - V_8 -> V_133 ] . V_2 , V_226 ) ;
F_1 ( V_8 -> V_9 [ V_8 -> V_133 ] . V_2 , V_226 ) ;
V_11 = V_8 -> V_12 ;
F_60 ( & V_11 -> V_214 , V_206 ) ;
F_75 ( V_8 , V_8 -> V_69 ) ;
V_8 -> free = true ;
F_62 ( & V_11 -> V_214 , V_206 ) ;
}
static void F_77 ( struct V_19 * V_20 )
{
void T_2 * V_22 = V_20 -> V_23 ;
T_1 V_31 ;
V_31 = F_32 ( V_22 + V_249 ) >> V_250 ;
V_31 &= V_251 ;
V_20 -> V_15 . V_252 = 8 * ( 1 << V_31 ) ;
V_31 = F_32 ( V_22 + V_249 ) >> V_253 ;
V_31 &= V_254 ;
V_20 -> V_15 . V_255 = V_31 + 1 ;
V_31 = F_32 ( V_22 + V_256 ) >> V_257 ;
V_31 &= V_258 ;
V_31 += 1 ;
V_20 -> V_15 . V_16 = V_31 ;
V_31 = F_32 ( V_22 + V_256 ) ;
if ( V_31 & V_259 ) {
V_31 = ( V_31 >> V_260 ) & V_261 ;
V_31 += 1 ;
V_20 -> V_15 . V_213 = V_31 ;
V_20 -> V_15 . V_262 = F_32 ( V_22 + V_263 ) ;
} else {
V_20 -> V_15 . V_213 = 0 ;
}
V_31 = F_32 ( V_22 + V_256 ) ;
if ( V_31 & V_264 )
V_20 -> V_15 . V_17 |= V_18 ;
else
V_20 -> V_15 . V_17 &= ~ V_18 ;
V_31 = F_32 ( V_22 + V_256 ) >> V_265 ;
V_31 &= V_266 ;
V_31 += 1 ;
V_20 -> V_15 . V_231 = V_31 ;
V_20 -> V_15 . V_247 = F_32 ( V_22 + V_267 ) ;
V_20 -> V_15 . V_24 = F_7 ( V_20 , V_268 ) ;
V_20 -> V_15 . V_269 = F_7 ( V_20 , V_270 ) ;
}
static inline void F_78 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_19 * V_20 = V_11 -> V_14 ;
V_8 -> V_9 [ 0 ] . V_102 = V_11 -> V_271
+ ( V_8 -> V_13 * V_20 -> V_216 ) ;
V_8 -> V_9 [ 0 ] . V_138 = V_11 -> V_272
+ ( V_8 -> V_13 * V_20 -> V_216 ) ;
V_8 -> V_9 [ 0 ] . V_2 = NULL ;
F_37 ( V_8 , 0 ) ;
V_8 -> V_9 [ 1 ] . V_102 = V_8 -> V_9 [ 0 ] . V_102
+ V_20 -> V_216 / 2 ;
V_8 -> V_9 [ 1 ] . V_138 = V_8 -> V_9 [ 0 ] . V_138
+ V_20 -> V_216 / 2 ;
V_8 -> V_9 [ 1 ] . V_2 = NULL ;
F_37 ( V_8 , 1 ) ;
}
static int F_79 ( struct V_10 * V_11 )
{
struct V_19 * V_20 = V_11 -> V_14 ;
int V_248 = V_20 -> V_15 . V_16 ;
struct V_7 * V_8 ;
int V_219 ;
V_11 -> V_223 = F_80 ( ( 1 + V_248 ) * sizeof( * V_8 ) ,
V_273 ) ;
if ( ! V_11 -> V_223 )
return - V_217 ;
for ( V_219 = 0 ; V_219 < V_248 ; V_219 ++ ) {
V_8 = & V_11 -> V_223 [ V_219 ] ;
V_8 -> V_13 = V_219 ;
V_8 -> V_12 = V_11 ;
F_78 ( V_8 ) ;
V_8 -> free = true ;
}
V_8 = & V_11 -> V_223 [ V_248 ] ;
V_8 -> V_13 = V_248 ;
V_8 -> V_12 = V_11 ;
V_8 -> free = false ;
V_11 -> V_222 = V_8 ;
return 0 ;
}
static int F_81 ( struct V_10 * V_11 )
{
struct V_19 * V_20 = V_11 -> V_14 ;
int V_248 = V_20 -> V_15 . V_16 ;
int V_207 ;
V_11 -> V_271 = F_82 ( V_20 -> V_98 ,
V_248 * V_20 -> V_216 ,
& V_11 -> V_272 , V_273 ) ;
if ( ! V_11 -> V_271 ) {
F_36 ( V_20 -> V_98 , L_35 ,
V_137 , __LINE__ ) ;
return - V_217 ;
}
V_207 = F_79 ( V_11 ) ;
if ( V_207 ) {
F_36 ( V_20 -> V_98 , L_36 ,
V_137 , __LINE__ ) ;
F_83 ( V_20 -> V_98 ,
V_248 * V_20 -> V_216 ,
V_11 -> V_271 , V_11 -> V_272 ) ;
return V_207 ;
}
return 0 ;
}
static int F_84 ( struct V_19 * V_20 )
{
struct V_10 * V_11 ;
void T_2 * V_22 ;
int V_219 , V_207 ;
if ( ! V_20 || ! V_20 -> V_98 )
return - V_168 ;
if ( V_20 -> V_228 )
return - V_168 ;
if ( V_20 -> V_274 )
V_20 -> V_274 ( V_20 ) ;
V_22 = V_20 -> V_23 ;
if ( ( F_7 ( V_20 , V_268 ) & 0xfffff ) != V_275
|| F_7 ( V_20 , V_270 ) != V_276 ) {
F_36 ( V_20 -> V_98 , L_37 ,
F_7 ( V_20 , V_268 ) , F_7 ( V_20 , V_270 ) ) ;
return - V_168 ;
}
F_77 ( V_20 ) ;
if ( V_20 -> V_15 . V_231 == 0 ) {
F_36 ( V_20 -> V_98 , L_38 ,
V_137 , __LINE__ ) ;
return - V_168 ;
}
V_11 = F_80 ( sizeof( * V_11 ) , V_273 ) ;
if ( ! V_11 ) {
F_36 ( V_20 -> V_98 , L_35 ,
V_137 , __LINE__ ) ;
return - V_217 ;
}
V_11 -> V_14 = V_20 ;
V_20 -> V_228 = V_11 ;
F_85 ( & V_11 -> V_214 ) ;
F_86 ( & V_11 -> V_238 ) ;
if ( ! V_20 -> V_216 )
V_20 -> V_216 = V_277 * 2 ;
for ( V_219 = 0 ; V_219 < V_20 -> V_15 . V_231 ; V_219 ++ )
V_11 -> V_236 [ V_219 ] = - 1 ;
V_207 = F_81 ( V_11 ) ;
if ( V_207 ) {
F_36 ( V_20 -> V_98 , L_39 ) ;
F_87 ( V_11 ) ;
return V_207 ;
}
F_88 ( & V_11 -> V_240 , F_63 , ( unsigned long ) V_11 ) ;
V_11 -> V_208 = V_278 ;
return 0 ;
}
static int F_89 ( struct V_10 * V_11 )
{
struct V_19 * V_20 = V_11 -> V_14 ;
int V_248 = V_20 -> V_15 . V_16 ;
struct V_7 * V_8 ;
int V_219 ;
for ( V_219 = 0 ; V_219 < V_248 ; V_219 ++ ) {
V_8 = & V_11 -> V_223 [ V_219 ] ;
F_76 ( ( void * ) V_8 ) ;
}
F_87 ( V_11 -> V_223 ) ;
return 0 ;
}
static void F_90 ( struct V_10 * V_11 )
{
struct V_19 * V_20 = V_11 -> V_14 ;
int V_248 = V_20 -> V_15 . V_16 ;
F_89 ( V_11 ) ;
F_83 ( V_20 -> V_98 , V_248 * V_20 -> V_216 ,
V_11 -> V_271 , V_11 -> V_272 ) ;
}
static void F_91 ( struct V_19 * V_20 )
{
struct V_10 * V_11 ;
if ( ! V_20 || ! V_20 -> V_228 )
return;
V_11 = V_20 -> V_228 ;
V_11 -> V_208 = V_279 ;
F_92 ( & V_11 -> V_240 ) ;
F_90 ( V_11 ) ;
F_87 ( V_11 ) ;
V_20 -> V_228 = NULL ;
}
static inline struct V_280 *
F_93 ( struct V_281 * V_282 )
{
if ( ! V_282 )
return NULL ;
return F_68 ( V_282 , struct V_280 , V_86 ) ;
}
static inline struct V_283 *
F_94 ( struct V_284 * V_285 )
{
return F_68 ( V_285 , struct V_283 , V_286 ) ;
}
static inline void F_95 ( struct V_287 * V_288 )
{
struct V_289 * V_290 ;
struct V_283 * V_291 ;
struct V_280 * V_292 = NULL ;
unsigned long V_206 ;
F_96 (desc, list, node) {
T_5 V_293 ;
void * V_294 ;
V_292 = V_291 -> V_295 ;
V_293 = V_291 -> V_286 . V_293 ;
V_294 = V_291 -> V_286 . V_296 ;
if ( V_293 )
V_293 ( V_294 ) ;
V_291 -> V_295 = NULL ;
}
if ( ! V_292 )
return;
V_290 = V_292 -> V_12 ;
F_60 ( & V_290 -> V_297 , V_206 ) ;
F_97 ( V_288 , & V_290 -> V_298 ) ;
F_62 ( & V_290 -> V_297 , V_206 ) ;
}
static inline void F_98 ( struct V_287 * V_288 )
{
struct V_283 * V_291 ;
struct V_280 * V_292 = NULL ;
unsigned long V_206 ;
F_96 (desc, list, node) {
T_5 V_293 ;
V_291 -> V_299 = V_300 ;
V_292 = V_291 -> V_295 ;
V_293 = V_291 -> V_286 . V_293 ;
if ( V_293 )
V_293 ( V_291 -> V_286 . V_296 ) ;
}
if ( ! V_292 )
return;
F_60 ( & V_292 -> V_214 , V_206 ) ;
F_97 ( V_288 , & V_292 -> V_301 ) ;
F_62 ( & V_292 -> V_214 , V_206 ) ;
}
static inline void F_99 ( struct V_280 * V_292 )
{
struct V_283 * V_291 ;
int V_207 ;
F_96 (desc, &pch->work_list, node) {
if ( V_291 -> V_299 == V_302 )
break;
V_207 = F_59 ( V_292 -> V_303 ,
& V_291 -> V_9 ) ;
if ( ! V_207 ) {
V_291 -> V_299 = V_302 ;
break;
} else if ( V_207 == - V_212 ) {
break;
} else {
V_291 -> V_299 = V_304 ;
F_36 ( V_292 -> V_12 -> V_305 . V_98 , L_40 ,
V_137 , __LINE__ , V_291 -> V_286 . V_306 ) ;
F_70 ( & V_292 -> V_307 ) ;
}
}
}
static void F_100 ( unsigned long V_218 )
{
struct V_280 * V_292 = (struct V_280 * ) V_218 ;
struct V_283 * V_291 , * V_308 ;
unsigned long V_206 ;
F_101 ( V_288 ) ;
F_60 ( & V_292 -> V_214 , V_206 ) ;
F_102 (desc, _dt, &pch->work_list, node)
if ( V_291 -> V_299 == V_304 ) {
if ( V_292 -> V_309 )
F_103 ( & V_291 -> V_286 ) ;
F_104 ( & V_291 -> V_310 , & V_288 ) ;
}
F_99 ( V_292 ) ;
F_71 ( V_292 -> V_303 , V_245 ) ;
F_62 ( & V_292 -> V_214 , V_206 ) ;
if ( V_292 -> V_309 )
F_98 ( & V_288 ) ;
else
F_95 ( & V_288 ) ;
}
static void F_105 ( void * V_6 , enum V_3 V_4 )
{
struct V_283 * V_291 = V_6 ;
struct V_280 * V_292 = V_291 -> V_295 ;
unsigned long V_206 ;
if ( ! V_292 )
return;
F_60 ( & V_292 -> V_214 , V_206 ) ;
V_291 -> V_299 = V_304 ;
F_62 ( & V_292 -> V_214 , V_206 ) ;
F_70 ( & V_292 -> V_307 ) ;
}
bool F_106 ( struct V_281 * V_86 , void * V_294 )
{
T_3 * V_311 ;
if ( V_86 -> V_312 -> V_98 -> V_313 != & V_314 . V_315 )
return false ;
#ifdef F_107
if ( V_86 -> V_312 -> V_98 -> V_316 ) {
const T_6 * V_317 ;
T_7 T_7 ;
struct V_318 * V_310 ;
V_317 = ( (struct V_319 * ) V_294 ) -> V_320 ;
T_7 = F_108 ( V_317 ++ ) ;
V_310 = F_109 ( T_7 ) ;
return ( ( V_86 -> V_321 == V_310 ) &&
( V_86 -> V_322 == F_108 ( V_317 ) ) ) ;
}
#endif
V_311 = V_86 -> V_321 ;
return * V_311 == ( unsigned ) V_294 ;
}
static int F_110 ( struct V_281 * V_86 )
{
struct V_280 * V_292 = F_93 ( V_86 ) ;
struct V_289 * V_290 = V_292 -> V_12 ;
unsigned long V_206 ;
F_60 ( & V_292 -> V_214 , V_206 ) ;
F_111 ( V_86 ) ;
V_292 -> V_309 = false ;
V_292 -> V_303 = F_74 ( & V_290 -> V_305 ) ;
if ( ! V_292 -> V_303 ) {
F_62 ( & V_292 -> V_214 , V_206 ) ;
return 0 ;
}
F_88 ( & V_292 -> V_307 , F_100 , ( unsigned long ) V_292 ) ;
F_62 ( & V_292 -> V_214 , V_206 ) ;
return 1 ;
}
static int F_112 ( struct V_281 * V_86 , enum V_323 V_324 , unsigned long V_52 )
{
struct V_280 * V_292 = F_93 ( V_86 ) ;
struct V_283 * V_291 , * V_308 ;
unsigned long V_206 ;
struct V_289 * V_290 = V_292 -> V_12 ;
struct V_325 * V_326 ;
F_101 ( V_288 ) ;
switch ( V_324 ) {
case V_327 :
F_60 ( & V_292 -> V_214 , V_206 ) ;
F_71 ( V_292 -> V_303 , V_243 ) ;
F_102 (desc, _dt, &pch->work_list , node) {
V_291 -> V_299 = V_304 ;
F_104 ( & V_291 -> V_310 , & V_288 ) ;
}
F_97 ( & V_288 , & V_290 -> V_298 ) ;
F_62 ( & V_292 -> V_214 , V_206 ) ;
break;
case V_328 :
V_326 = (struct V_325 * ) V_52 ;
if ( V_326 -> V_329 == V_330 ) {
if ( V_326 -> V_165 )
V_292 -> V_331 = V_326 -> V_165 ;
if ( V_326 -> V_332 )
V_292 -> V_333 = F_113 ( V_326 -> V_332 ) ;
if ( V_326 -> V_334 )
V_292 -> V_335 = V_326 -> V_334 ;
} else if ( V_326 -> V_329 == V_336 ) {
if ( V_326 -> V_164 )
V_292 -> V_331 = V_326 -> V_164 ;
if ( V_326 -> V_337 )
V_292 -> V_333 = F_113 ( V_326 -> V_337 ) ;
if ( V_326 -> V_338 )
V_292 -> V_335 = V_326 -> V_338 ;
}
break;
default:
F_36 ( V_292 -> V_12 -> V_305 . V_98 , L_41 ) ;
return - V_339 ;
}
return 0 ;
}
static void F_114 ( struct V_281 * V_86 )
{
struct V_280 * V_292 = F_93 ( V_86 ) ;
unsigned long V_206 ;
F_60 ( & V_292 -> V_214 , V_206 ) ;
F_92 ( & V_292 -> V_307 ) ;
F_76 ( V_292 -> V_303 ) ;
V_292 -> V_303 = NULL ;
if ( V_292 -> V_309 )
F_97 ( & V_292 -> V_301 , & V_292 -> V_12 -> V_298 ) ;
F_62 ( & V_292 -> V_214 , V_206 ) ;
}
static enum V_340
F_115 ( struct V_281 * V_86 , T_8 V_306 ,
struct V_341 * V_342 )
{
return F_116 ( V_86 , V_306 , V_342 ) ;
}
static void F_117 ( struct V_281 * V_86 )
{
F_100 ( ( unsigned long ) F_93 ( V_86 ) ) ;
}
static T_8 F_118 ( struct V_284 * V_285 )
{
struct V_283 * V_291 , * V_343 = F_94 ( V_285 ) ;
struct V_280 * V_292 = F_93 ( V_285 -> V_86 ) ;
T_8 V_306 ;
unsigned long V_206 ;
F_60 ( & V_292 -> V_214 , V_206 ) ;
while ( ! F_67 ( & V_343 -> V_310 ) ) {
V_291 = F_119 ( V_343 -> V_310 . V_169 , struct V_283 , V_310 ) ;
F_120 ( & V_291 -> V_286 ) ;
F_104 ( & V_291 -> V_310 , & V_292 -> V_301 ) ;
}
V_306 = F_120 ( & V_343 -> V_286 ) ;
F_66 ( & V_343 -> V_310 , & V_292 -> V_301 ) ;
F_62 ( & V_292 -> V_214 , V_206 ) ;
return V_306 ;
}
static inline void F_121 ( struct V_283 * V_291 )
{
V_291 -> V_295 = NULL ;
V_291 -> V_9 . V_160 = & V_291 -> V_344 ;
V_291 -> V_9 . V_6 = V_291 ;
V_291 -> V_345 . V_194 = V_346 ;
V_291 -> V_345 . V_176 = 0 ;
V_291 -> V_345 . V_181 = 0 ;
V_291 -> V_345 . V_190 = V_347 ;
V_291 -> V_345 . V_192 = V_348 ;
V_291 -> V_9 . V_134 = & V_291 -> V_345 ;
V_291 -> V_9 . V_5 = F_105 ;
V_291 -> V_286 . V_349 = F_118 ;
F_86 ( & V_291 -> V_310 ) ;
}
int F_122 ( struct V_289 * V_290 , T_9 V_350 , int V_351 )
{
struct V_283 * V_291 ;
unsigned long V_206 ;
int V_219 ;
if ( ! V_290 )
return 0 ;
V_291 = F_123 ( V_351 * sizeof( * V_291 ) , V_350 ) ;
if ( ! V_291 )
return 0 ;
F_60 ( & V_290 -> V_297 , V_206 ) ;
for ( V_219 = 0 ; V_219 < V_351 ; V_219 ++ ) {
F_121 ( & V_291 [ V_219 ] ) ;
F_66 ( & V_291 [ V_219 ] . V_310 , & V_290 -> V_298 ) ;
}
F_62 ( & V_290 -> V_297 , V_206 ) ;
return V_351 ;
}
static struct V_283 *
F_124 ( struct V_289 * V_290 )
{
struct V_283 * V_291 = NULL ;
unsigned long V_206 ;
if ( ! V_290 )
return NULL ;
F_60 ( & V_290 -> V_297 , V_206 ) ;
if ( ! F_67 ( & V_290 -> V_298 ) ) {
V_291 = F_119 ( V_290 -> V_298 . V_169 ,
struct V_283 , V_310 ) ;
F_69 ( & V_291 -> V_310 ) ;
V_291 -> V_299 = V_300 ;
V_291 -> V_286 . V_293 = NULL ;
}
F_62 ( & V_290 -> V_297 , V_206 ) ;
return V_291 ;
}
static struct V_283 * F_125 ( struct V_280 * V_292 )
{
struct V_289 * V_290 = V_292 -> V_12 ;
T_3 * V_311 = V_292 -> V_86 . V_321 ;
struct V_283 * V_291 ;
V_291 = F_124 ( V_290 ) ;
if ( ! V_291 ) {
if ( ! F_122 ( V_290 , V_352 , 1 ) )
return NULL ;
V_291 = F_124 ( V_290 ) ;
if ( ! V_291 ) {
F_36 ( V_292 -> V_12 -> V_305 . V_98 ,
L_42 , V_137 , __LINE__ ) ;
return NULL ;
}
}
V_291 -> V_295 = V_292 ;
V_291 -> V_286 . V_306 = 0 ;
F_126 ( & V_291 -> V_286 ) ;
V_291 -> V_9 . V_36 = V_311 ? V_292 -> V_86 . V_322 : 0 ;
V_291 -> V_345 . V_15 = & V_292 -> V_12 -> V_305 . V_15 ;
F_127 ( & V_291 -> V_286 , & V_292 -> V_86 ) ;
return V_291 ;
}
static inline void F_128 ( struct V_159 * V_344 ,
T_10 V_60 , T_10 V_353 , T_11 V_354 )
{
V_344 -> V_169 = NULL ;
V_344 -> V_163 = V_354 ;
V_344 -> V_165 = V_60 ;
V_344 -> V_164 = V_353 ;
}
static struct V_283 *
F_129 ( struct V_280 * V_292 , T_10 V_60 ,
T_10 V_353 , T_11 V_354 )
{
struct V_283 * V_291 = F_125 ( V_292 ) ;
if ( ! V_291 ) {
F_36 ( V_292 -> V_12 -> V_305 . V_98 , L_43 ,
V_137 , __LINE__ ) ;
return NULL ;
}
F_128 ( & V_291 -> V_344 , V_60 , V_353 , V_354 ) ;
return V_291 ;
}
static inline int F_130 ( struct V_283 * V_291 , T_11 V_354 )
{
struct V_280 * V_292 = V_291 -> V_295 ;
struct V_19 * V_20 = & V_292 -> V_12 -> V_305 ;
int V_335 ;
V_335 = V_20 -> V_15 . V_252 / 8 ;
V_335 *= V_20 -> V_15 . V_255 ;
V_335 >>= V_291 -> V_345 . V_187 ;
if ( V_335 > 16 )
V_335 = 16 ;
while ( V_335 > 1 ) {
if ( ! ( V_354 % ( V_335 << V_291 -> V_345 . V_187 ) ) )
break;
V_335 -- ;
}
return V_335 ;
}
static struct V_284 * F_131 (
struct V_281 * V_86 , T_10 V_355 , T_11 V_354 ,
T_11 V_356 , enum V_357 V_329 ,
void * V_358 )
{
struct V_283 * V_291 ;
struct V_280 * V_292 = F_93 ( V_86 ) ;
T_10 V_60 ;
T_10 V_353 ;
V_291 = F_125 ( V_292 ) ;
if ( ! V_291 ) {
F_36 ( V_292 -> V_12 -> V_305 . V_98 , L_43 ,
V_137 , __LINE__ ) ;
return NULL ;
}
switch ( V_329 ) {
case V_330 :
V_291 -> V_345 . V_172 = 1 ;
V_291 -> V_345 . V_174 = 0 ;
V_291 -> V_9 . V_145 = V_146 ;
V_353 = V_355 ;
V_60 = V_292 -> V_331 ;
break;
case V_336 :
V_291 -> V_345 . V_172 = 0 ;
V_291 -> V_345 . V_174 = 1 ;
V_291 -> V_9 . V_145 = V_147 ;
V_353 = V_292 -> V_331 ;
V_60 = V_355 ;
break;
default:
F_36 ( V_292 -> V_12 -> V_305 . V_98 , L_44 ,
V_137 , __LINE__ ) ;
return NULL ;
}
V_291 -> V_345 . V_187 = V_292 -> V_333 ;
V_291 -> V_345 . V_184 = 1 ;
V_292 -> V_309 = true ;
F_128 ( & V_291 -> V_344 , V_60 , V_353 , V_356 ) ;
return & V_291 -> V_286 ;
}
static struct V_284 *
F_132 ( struct V_281 * V_86 , T_10 V_60 ,
T_10 V_353 , T_11 V_354 , unsigned long V_206 )
{
struct V_283 * V_291 ;
struct V_280 * V_292 = F_93 ( V_86 ) ;
struct V_19 * V_20 ;
int V_359 ;
if ( F_133 ( ! V_292 || ! V_354 ) )
return NULL ;
V_20 = & V_292 -> V_12 -> V_305 ;
V_291 = F_129 ( V_292 , V_60 , V_353 , V_354 ) ;
if ( ! V_291 )
return NULL ;
V_291 -> V_345 . V_172 = 1 ;
V_291 -> V_345 . V_174 = 1 ;
V_291 -> V_9 . V_145 = V_148 ;
V_359 = V_20 -> V_15 . V_252 / 8 ;
while ( V_359 > 1 ) {
if ( ! ( V_354 % V_359 ) )
break;
V_359 /= 2 ;
}
V_291 -> V_345 . V_187 = 0 ;
while ( V_359 != ( 1 << V_291 -> V_345 . V_187 ) )
V_291 -> V_345 . V_187 ++ ;
V_291 -> V_345 . V_184 = F_130 ( V_291 , V_354 ) ;
V_291 -> V_286 . V_206 = V_206 ;
return & V_291 -> V_286 ;
}
static struct V_284 *
F_134 ( struct V_281 * V_86 , struct V_360 * V_361 ,
unsigned int V_362 , enum V_357 V_329 ,
unsigned long V_350 , void * V_358 )
{
struct V_283 * V_363 , * V_291 = NULL ;
struct V_280 * V_292 = F_93 ( V_86 ) ;
struct V_360 * V_364 ;
unsigned long V_206 ;
int V_219 ;
T_10 V_87 ;
if ( F_133 ( ! V_292 || ! V_361 || ! V_362 ) )
return NULL ;
V_87 = V_292 -> V_331 ;
V_363 = NULL ;
F_135 (sgl, sg, sg_len, i) {
V_291 = F_125 ( V_292 ) ;
if ( ! V_291 ) {
struct V_289 * V_290 = V_292 -> V_12 ;
F_36 ( V_292 -> V_12 -> V_305 . V_98 ,
L_43 ,
V_137 , __LINE__ ) ;
if ( ! V_363 )
return NULL ;
F_60 ( & V_290 -> V_297 , V_206 ) ;
while ( ! F_67 ( & V_363 -> V_310 ) ) {
V_291 = F_119 ( V_363 -> V_310 . V_169 ,
struct V_283 , V_310 ) ;
F_104 ( & V_291 -> V_310 , & V_290 -> V_298 ) ;
}
F_104 ( & V_363 -> V_310 , & V_290 -> V_298 ) ;
F_62 ( & V_290 -> V_297 , V_206 ) ;
return NULL ;
}
if ( ! V_363 )
V_363 = V_291 ;
else
F_66 ( & V_291 -> V_310 , & V_363 -> V_310 ) ;
if ( V_329 == V_330 ) {
V_291 -> V_345 . V_172 = 1 ;
V_291 -> V_345 . V_174 = 0 ;
V_291 -> V_9 . V_145 = V_146 ;
F_128 ( & V_291 -> V_344 ,
V_87 , F_136 ( V_364 ) , F_137 ( V_364 ) ) ;
} else {
V_291 -> V_345 . V_172 = 0 ;
V_291 -> V_345 . V_174 = 1 ;
V_291 -> V_9 . V_145 = V_147 ;
F_128 ( & V_291 -> V_344 ,
F_136 ( V_364 ) , V_87 , F_137 ( V_364 ) ) ;
}
V_291 -> V_345 . V_187 = V_292 -> V_333 ;
V_291 -> V_345 . V_184 = 1 ;
}
V_291 -> V_286 . V_206 = V_350 ;
return & V_291 -> V_286 ;
}
static T_12 F_138 ( int V_365 , void * V_218 )
{
if ( F_64 ( V_218 ) )
return V_366 ;
else
return V_367 ;
}
static int T_13
F_139 ( struct V_368 * V_369 , const struct V_370 * V_13 )
{
struct V_371 * V_372 ;
struct V_289 * V_290 ;
struct V_280 * V_292 ;
struct V_19 * V_20 ;
struct V_373 * V_374 ;
struct V_375 * V_376 ;
int V_219 , V_207 , V_365 ;
int V_16 ;
V_372 = V_369 -> V_98 . V_377 ;
V_290 = F_80 ( sizeof( * V_290 ) , V_273 ) ;
if ( ! V_290 ) {
F_36 ( & V_369 -> V_98 , L_45 ) ;
return - V_217 ;
}
V_20 = & V_290 -> V_305 ;
V_20 -> V_98 = & V_369 -> V_98 ;
V_20 -> V_228 = NULL ;
V_20 -> V_216 = V_372 ? V_372 -> V_378 : 0 ;
V_376 = & V_369 -> V_376 ;
F_140 ( V_376 -> V_379 , F_141 ( V_376 ) , L_46 ) ;
V_20 -> V_23 = F_142 ( V_376 -> V_379 , F_141 ( V_376 ) ) ;
if ( ! V_20 -> V_23 ) {
V_207 = - V_339 ;
goto V_380;
}
V_290 -> V_381 = F_143 ( & V_369 -> V_98 , L_47 ) ;
if ( F_144 ( V_290 -> V_381 ) ) {
F_36 ( & V_369 -> V_98 , L_48 ) ;
V_207 = - V_168 ;
goto V_382;
}
F_145 ( V_369 , V_290 ) ;
#ifndef F_146
F_147 ( V_290 -> V_381 ) ;
#endif
V_365 = V_369 -> V_365 [ 0 ] ;
V_207 = F_148 ( V_365 , F_138 , 0 ,
F_149 ( & V_369 -> V_98 ) , V_20 ) ;
if ( V_207 )
goto V_383;
V_207 = F_84 ( V_20 ) ;
if ( V_207 )
goto V_384;
F_86 ( & V_290 -> V_298 ) ;
F_85 ( & V_290 -> V_297 ) ;
if ( ! F_122 ( V_290 , V_273 , V_385 ) )
F_150 ( & V_369 -> V_98 , L_49 ) ;
V_374 = & V_290 -> V_386 ;
F_86 ( & V_374 -> V_223 ) ;
if ( V_372 )
V_16 = F_151 ( int , V_372 -> V_387 , V_20 -> V_15 . V_16 ) ;
else
V_16 = F_151 ( int , V_20 -> V_15 . V_213 , V_20 -> V_15 . V_16 ) ;
V_290 -> V_388 = F_80 ( V_16 * sizeof( * V_292 ) , V_273 ) ;
for ( V_219 = 0 ; V_219 < V_16 ; V_219 ++ ) {
V_292 = & V_290 -> V_388 [ V_219 ] ;
if ( ! V_369 -> V_98 . V_316 )
V_292 -> V_86 . V_321 = V_372 ? & V_372 -> V_311 [ V_219 ] : NULL ;
else
V_292 -> V_86 . V_321 = V_369 -> V_98 . V_316 ;
F_86 ( & V_292 -> V_301 ) ;
F_85 ( & V_292 -> V_214 ) ;
V_292 -> V_303 = NULL ;
V_292 -> V_86 . V_312 = V_374 ;
V_292 -> V_12 = V_290 ;
F_66 ( & V_292 -> V_86 . V_318 , & V_374 -> V_223 ) ;
}
V_374 -> V_98 = & V_369 -> V_98 ;
if ( V_372 ) {
V_374 -> V_389 = V_372 -> V_389 ;
} else {
F_152 ( V_390 , V_374 -> V_389 ) ;
if ( V_20 -> V_15 . V_213 ) {
F_152 ( V_391 , V_374 -> V_389 ) ;
F_152 ( V_392 , V_374 -> V_389 ) ;
}
}
V_374 -> V_393 = F_110 ;
V_374 -> V_394 = F_114 ;
V_374 -> V_395 = F_132 ;
V_374 -> V_396 = F_131 ;
V_374 -> V_397 = F_115 ;
V_374 -> V_398 = F_134 ;
V_374 -> V_399 = F_112 ;
V_374 -> V_400 = F_117 ;
V_207 = F_153 ( V_374 ) ;
if ( V_207 ) {
F_36 ( & V_369 -> V_98 , L_50 ) ;
goto V_401;
}
F_43 ( & V_369 -> V_98 ,
L_51 , V_369 -> V_402 ) ;
F_43 ( & V_369 -> V_98 ,
L_52 ,
V_20 -> V_15 . V_255 ,
V_20 -> V_15 . V_252 / 8 , V_20 -> V_15 . V_16 ,
V_20 -> V_15 . V_213 , V_20 -> V_15 . V_231 ) ;
return 0 ;
V_401:
F_91 ( V_20 ) ;
V_384:
F_154 ( V_365 , V_20 ) ;
V_383:
#ifndef F_146
F_155 ( V_290 -> V_381 ) ;
#endif
F_156 ( V_290 -> V_381 ) ;
V_382:
F_157 ( V_20 -> V_23 ) ;
V_380:
F_158 ( V_376 -> V_379 , F_141 ( V_376 ) ) ;
F_87 ( V_290 ) ;
return V_207 ;
}
static int T_14 F_159 ( struct V_368 * V_369 )
{
struct V_289 * V_290 = F_160 ( V_369 ) ;
struct V_280 * V_292 , * V_403 ;
struct V_19 * V_20 ;
struct V_375 * V_376 ;
int V_365 ;
if ( ! V_290 )
return 0 ;
F_145 ( V_369 , NULL ) ;
F_102 (pch, _p, &pdmac->ddma.channels,
chan.device_node) {
F_161 ( & V_292 -> V_86 . V_318 ) ;
F_112 ( & V_292 -> V_86 , V_327 , 0 ) ;
F_114 ( & V_292 -> V_86 ) ;
}
V_20 = & V_290 -> V_305 ;
F_91 ( V_20 ) ;
V_365 = V_369 -> V_365 [ 0 ] ;
F_154 ( V_365 , V_20 ) ;
F_157 ( V_20 -> V_23 ) ;
V_376 = & V_369 -> V_376 ;
F_158 ( V_376 -> V_379 , F_141 ( V_376 ) ) ;
#ifndef F_146
F_155 ( V_290 -> V_381 ) ;
#endif
F_87 ( V_290 ) ;
return 0 ;
}
static int F_162 ( struct V_312 * V_98 )
{
struct V_289 * V_290 = F_163 ( V_98 ) ;
if ( ! V_290 ) {
F_36 ( V_98 , L_53 ) ;
return - V_404 ;
}
F_155 ( V_290 -> V_381 ) ;
return 0 ;
}
static int F_164 ( struct V_312 * V_98 )
{
struct V_289 * V_290 = F_163 ( V_98 ) ;
if ( ! V_290 ) {
F_36 ( V_98 , L_53 ) ;
return - V_404 ;
}
F_147 ( V_290 -> V_381 ) ;
return 0 ;
}
