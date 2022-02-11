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
struct V_1 * V_227 , * V_228 ;
struct V_10 * V_11 ;
unsigned long V_206 ;
void T_2 * V_22 ;
T_1 V_31 ;
int V_13 , V_69 , V_207 = 0 ;
if ( ! V_20 || ! V_20 -> V_229 )
return 0 ;
V_22 = V_20 -> V_23 ;
V_11 = V_20 -> V_229 ;
F_60 ( & V_11 -> V_214 , V_206 ) ;
V_31 = F_32 ( V_22 + V_230 ) & 0x1 ;
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
V_31 = F_32 ( V_22 + V_231 ) ;
if ( V_20 -> V_15 . V_232 < 32
&& V_31 & ~ ( ( 1 << V_20 -> V_15 . V_232 ) - 1 ) ) {
V_11 -> V_210 . V_220 = true ;
F_36 ( V_20 -> V_98 , L_34 , V_137 , __LINE__ ) ;
V_207 = 1 ;
goto V_233;
}
for ( V_69 = 0 ; V_69 < V_20 -> V_15 . V_232 ; V_69 ++ ) {
if ( V_31 & ( 1 << V_69 ) ) {
struct V_7 * V_8 ;
T_1 V_234 = F_32 ( V_22 + V_131 ) ;
int V_235 ;
if ( V_234 & ( 1 << V_69 ) )
F_35 ( 1 << V_69 , V_22 + V_236 ) ;
V_207 = 1 ;
V_13 = V_11 -> V_237 [ V_69 ] ;
V_8 = & V_11 -> V_223 [ V_13 ] ;
V_235 = V_8 -> V_104 ;
if ( V_235 == - 1 )
continue;
V_227 = V_8 -> V_9 [ V_235 ] . V_2 ;
V_8 -> V_9 [ V_235 ] . V_2 = NULL ;
F_37 ( V_8 , V_235 ) ;
F_44 ( V_8 ) ;
F_66 ( & V_227 -> V_238 , & V_11 -> V_239 ) ;
}
}
F_67 (rqdone, tmp, &pl330->req_done, rqd) {
F_68 ( & V_227 -> V_238 ) ;
F_62 ( & V_11 -> V_214 , V_206 ) ;
F_1 ( V_227 , V_240 ) ;
F_60 ( & V_11 -> V_214 , V_206 ) ;
}
V_233:
F_62 ( & V_11 -> V_214 , V_206 ) ;
if ( V_11 -> V_210 . V_220
|| V_11 -> V_210 . V_221
|| V_11 -> V_210 . V_211 ) {
V_207 = 1 ;
F_69 ( & V_11 -> V_241 ) ;
}
return V_207 ;
}
static int F_70 ( void * V_204 , enum V_242 V_243 )
{
struct V_7 * V_8 = V_204 ;
struct V_10 * V_11 ;
unsigned long V_206 ;
int V_207 = 0 , V_235 ;
if ( ! V_8 || V_8 -> free || V_8 -> V_12 -> V_208 == V_209 )
return - V_168 ;
V_11 = V_8 -> V_12 ;
V_235 = V_8 -> V_104 ;
F_60 ( & V_11 -> V_214 , V_206 ) ;
switch ( V_243 ) {
case V_244 :
F_40 ( V_8 ) ;
V_8 -> V_9 [ 0 ] . V_2 = NULL ;
V_8 -> V_9 [ 1 ] . V_2 = NULL ;
F_37 ( V_8 , 0 ) ;
F_37 ( V_8 , 1 ) ;
break;
case V_245 :
F_40 ( V_8 ) ;
if ( V_235 == - 1 )
break;
V_8 -> V_9 [ V_235 ] . V_2 = NULL ;
F_37 ( V_8 , V_235 ) ;
case V_246 :
if ( ( V_235 == - 1 ) && ! F_44 ( V_8 ) )
V_207 = - V_247 ;
break;
default:
V_207 = - V_168 ;
}
F_62 ( & V_11 -> V_214 , V_206 ) ;
return V_207 ;
}
static inline int F_71 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_19 * V_20 = V_11 -> V_14 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_20 -> V_15 . V_232 ; V_69 ++ )
if ( V_11 -> V_237 [ V_69 ] == - 1 ) {
V_11 -> V_237 [ V_69 ] = V_8 -> V_13 ;
return V_69 ;
}
return - 1 ;
}
static bool F_72 ( const struct V_19 * V_20 , int V_219 )
{
return V_20 -> V_15 . V_248 & ( 1 << V_219 ) ;
}
static void * F_73 ( const struct V_19 * V_20 )
{
struct V_7 * V_8 = NULL ;
struct V_10 * V_11 ;
unsigned long V_206 ;
int V_249 , V_219 ;
if ( ! V_20 || ! V_20 -> V_229 )
return NULL ;
V_11 = V_20 -> V_229 ;
if ( V_11 -> V_208 == V_209 )
return NULL ;
V_249 = V_20 -> V_15 . V_16 ;
F_60 ( & V_11 -> V_214 , V_206 ) ;
for ( V_219 = 0 ; V_219 < V_249 ; V_219 ++ ) {
V_8 = & V_11 -> V_223 [ V_219 ] ;
if ( ( V_8 -> free ) && ( ! F_6 ( V_8 ) ||
F_72 ( V_20 , V_219 ) ) ) {
V_8 -> V_69 = F_71 ( V_8 ) ;
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
static inline void F_74 ( struct V_7 * V_8 , int V_69 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_19 * V_20 = V_11 -> V_14 ;
if ( V_69 >= 0 && V_69 < V_20 -> V_15 . V_232
&& V_11 -> V_237 [ V_69 ] == V_8 -> V_13 )
V_11 -> V_237 [ V_69 ] = - 1 ;
}
static void F_75 ( void * V_204 )
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
F_74 ( V_8 , V_8 -> V_69 ) ;
V_8 -> free = true ;
F_62 ( & V_11 -> V_214 , V_206 ) ;
}
static void F_76 ( struct V_19 * V_20 )
{
void T_2 * V_22 = V_20 -> V_23 ;
T_1 V_31 ;
V_31 = F_32 ( V_22 + V_250 ) >> V_251 ;
V_31 &= V_252 ;
V_20 -> V_15 . V_253 = 8 * ( 1 << V_31 ) ;
V_31 = F_32 ( V_22 + V_250 ) >> V_254 ;
V_31 &= V_255 ;
V_20 -> V_15 . V_256 = V_31 + 1 ;
V_31 = F_32 ( V_22 + V_257 ) >> V_258 ;
V_31 &= V_259 ;
V_31 += 1 ;
V_20 -> V_15 . V_16 = V_31 ;
V_31 = F_32 ( V_22 + V_257 ) ;
if ( V_31 & V_260 ) {
V_31 = ( V_31 >> V_261 ) & V_262 ;
V_31 += 1 ;
V_20 -> V_15 . V_213 = V_31 ;
V_20 -> V_15 . V_263 = F_32 ( V_22 + V_264 ) ;
} else {
V_20 -> V_15 . V_213 = 0 ;
}
V_31 = F_32 ( V_22 + V_257 ) ;
if ( V_31 & V_265 )
V_20 -> V_15 . V_17 |= V_18 ;
else
V_20 -> V_15 . V_17 &= ~ V_18 ;
V_31 = F_32 ( V_22 + V_257 ) >> V_266 ;
V_31 &= V_267 ;
V_31 += 1 ;
V_20 -> V_15 . V_232 = V_31 ;
V_20 -> V_15 . V_248 = F_32 ( V_22 + V_268 ) ;
V_20 -> V_15 . V_24 = F_7 ( V_20 , V_269 ) ;
V_20 -> V_15 . V_270 = F_7 ( V_20 , V_271 ) ;
}
static inline void F_77 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_19 * V_20 = V_11 -> V_14 ;
V_8 -> V_9 [ 0 ] . V_102 = V_11 -> V_272
+ ( V_8 -> V_13 * V_20 -> V_216 ) ;
V_8 -> V_9 [ 0 ] . V_138 = V_11 -> V_273
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
static int F_78 ( struct V_10 * V_11 )
{
struct V_19 * V_20 = V_11 -> V_14 ;
int V_249 = V_20 -> V_15 . V_16 ;
struct V_7 * V_8 ;
int V_219 ;
V_11 -> V_223 = F_79 ( ( 1 + V_249 ) * sizeof( * V_8 ) ,
V_274 ) ;
if ( ! V_11 -> V_223 )
return - V_217 ;
for ( V_219 = 0 ; V_219 < V_249 ; V_219 ++ ) {
V_8 = & V_11 -> V_223 [ V_219 ] ;
V_8 -> V_13 = V_219 ;
V_8 -> V_12 = V_11 ;
F_77 ( V_8 ) ;
V_8 -> free = true ;
}
V_8 = & V_11 -> V_223 [ V_249 ] ;
V_8 -> V_13 = V_249 ;
V_8 -> V_12 = V_11 ;
V_8 -> free = false ;
V_11 -> V_222 = V_8 ;
return 0 ;
}
static int F_80 ( struct V_10 * V_11 )
{
struct V_19 * V_20 = V_11 -> V_14 ;
int V_249 = V_20 -> V_15 . V_16 ;
int V_207 ;
V_11 -> V_272 = F_81 ( V_20 -> V_98 ,
V_249 * V_20 -> V_216 ,
& V_11 -> V_273 , V_274 ) ;
if ( ! V_11 -> V_272 ) {
F_36 ( V_20 -> V_98 , L_35 ,
V_137 , __LINE__ ) ;
return - V_217 ;
}
V_207 = F_78 ( V_11 ) ;
if ( V_207 ) {
F_36 ( V_20 -> V_98 , L_36 ,
V_137 , __LINE__ ) ;
F_82 ( V_20 -> V_98 ,
V_249 * V_20 -> V_216 ,
V_11 -> V_272 , V_11 -> V_273 ) ;
return V_207 ;
}
return 0 ;
}
static int F_83 ( struct V_19 * V_20 )
{
struct V_10 * V_11 ;
void T_2 * V_22 ;
int V_219 , V_207 ;
if ( ! V_20 || ! V_20 -> V_98 )
return - V_168 ;
if ( V_20 -> V_229 )
return - V_168 ;
if ( V_20 -> V_275 )
V_20 -> V_275 ( V_20 ) ;
V_22 = V_20 -> V_23 ;
if ( ( F_7 ( V_20 , V_269 ) & 0xfffff ) != V_276
|| F_7 ( V_20 , V_271 ) != V_277 ) {
F_36 ( V_20 -> V_98 , L_37 ,
F_7 ( V_20 , V_269 ) , F_7 ( V_20 , V_271 ) ) ;
return - V_168 ;
}
F_76 ( V_20 ) ;
if ( V_20 -> V_15 . V_232 == 0 ) {
F_36 ( V_20 -> V_98 , L_38 ,
V_137 , __LINE__ ) ;
return - V_168 ;
}
V_11 = F_79 ( sizeof( * V_11 ) , V_274 ) ;
if ( ! V_11 ) {
F_36 ( V_20 -> V_98 , L_35 ,
V_137 , __LINE__ ) ;
return - V_217 ;
}
V_11 -> V_14 = V_20 ;
V_20 -> V_229 = V_11 ;
F_84 ( & V_11 -> V_214 ) ;
F_85 ( & V_11 -> V_239 ) ;
if ( ! V_20 -> V_216 )
V_20 -> V_216 = V_278 * 2 ;
for ( V_219 = 0 ; V_219 < V_20 -> V_15 . V_232 ; V_219 ++ )
V_11 -> V_237 [ V_219 ] = - 1 ;
V_207 = F_80 ( V_11 ) ;
if ( V_207 ) {
F_36 ( V_20 -> V_98 , L_39 ) ;
F_86 ( V_11 ) ;
return V_207 ;
}
F_87 ( & V_11 -> V_241 , F_63 , ( unsigned long ) V_11 ) ;
V_11 -> V_208 = V_279 ;
return 0 ;
}
static int F_88 ( struct V_10 * V_11 )
{
struct V_19 * V_20 = V_11 -> V_14 ;
int V_249 = V_20 -> V_15 . V_16 ;
struct V_7 * V_8 ;
int V_219 ;
for ( V_219 = 0 ; V_219 < V_249 ; V_219 ++ ) {
V_8 = & V_11 -> V_223 [ V_219 ] ;
F_75 ( ( void * ) V_8 ) ;
}
F_86 ( V_11 -> V_223 ) ;
return 0 ;
}
static void F_89 ( struct V_10 * V_11 )
{
struct V_19 * V_20 = V_11 -> V_14 ;
int V_249 = V_20 -> V_15 . V_16 ;
F_88 ( V_11 ) ;
F_82 ( V_20 -> V_98 , V_249 * V_20 -> V_216 ,
V_11 -> V_272 , V_11 -> V_273 ) ;
}
static void F_90 ( struct V_19 * V_20 )
{
struct V_10 * V_11 ;
if ( ! V_20 || ! V_20 -> V_229 )
return;
V_11 = V_20 -> V_229 ;
V_11 -> V_208 = V_280 ;
F_91 ( & V_11 -> V_241 ) ;
F_89 ( V_11 ) ;
F_86 ( V_11 ) ;
V_20 -> V_229 = NULL ;
}
static inline struct V_281 *
F_92 ( struct V_282 * V_283 )
{
if ( ! V_283 )
return NULL ;
return F_93 ( V_283 , struct V_281 , V_86 ) ;
}
static inline struct V_284 *
F_94 ( struct V_285 * V_286 )
{
return F_93 ( V_286 , struct V_284 , V_287 ) ;
}
static inline void F_95 ( struct V_288 * V_289 )
{
struct V_290 * V_291 ;
struct V_284 * V_292 ;
struct V_281 * V_293 = NULL ;
unsigned long V_206 ;
F_96 (desc, list, node) {
T_5 V_294 ;
void * V_295 ;
V_293 = V_292 -> V_296 ;
V_294 = V_292 -> V_287 . V_294 ;
V_295 = V_292 -> V_287 . V_297 ;
if ( V_294 )
V_294 ( V_295 ) ;
V_292 -> V_296 = NULL ;
}
if ( ! V_293 )
return;
V_291 = V_293 -> V_12 ;
F_60 ( & V_291 -> V_298 , V_206 ) ;
F_97 ( V_289 , & V_291 -> V_299 ) ;
F_62 ( & V_291 -> V_298 , V_206 ) ;
}
static inline void F_98 ( struct V_288 * V_289 )
{
struct V_284 * V_292 ;
struct V_281 * V_293 = NULL ;
unsigned long V_206 ;
F_96 (desc, list, node) {
T_5 V_294 ;
V_292 -> V_300 = V_301 ;
V_293 = V_292 -> V_296 ;
V_294 = V_292 -> V_287 . V_294 ;
if ( V_294 )
V_294 ( V_292 -> V_287 . V_297 ) ;
}
if ( ! V_293 )
return;
F_60 ( & V_293 -> V_214 , V_206 ) ;
F_97 ( V_289 , & V_293 -> V_302 ) ;
F_62 ( & V_293 -> V_214 , V_206 ) ;
}
static inline void F_99 ( struct V_281 * V_293 )
{
struct V_284 * V_292 ;
int V_207 ;
F_96 (desc, &pch->work_list, node) {
if ( V_292 -> V_300 == V_303 )
break;
V_207 = F_59 ( V_293 -> V_304 ,
& V_292 -> V_9 ) ;
if ( ! V_207 ) {
V_292 -> V_300 = V_303 ;
break;
} else if ( V_207 == - V_212 ) {
break;
} else {
V_292 -> V_300 = V_305 ;
F_36 ( V_293 -> V_12 -> V_306 . V_98 , L_40 ,
V_137 , __LINE__ , V_292 -> V_287 . V_307 ) ;
F_69 ( & V_293 -> V_308 ) ;
}
}
}
static void F_100 ( unsigned long V_218 )
{
struct V_281 * V_293 = (struct V_281 * ) V_218 ;
struct V_284 * V_292 , * V_309 ;
unsigned long V_206 ;
F_101 ( V_289 ) ;
F_60 ( & V_293 -> V_214 , V_206 ) ;
F_67 (desc, _dt, &pch->work_list, node)
if ( V_292 -> V_300 == V_305 ) {
if ( ! V_293 -> V_310 )
F_102 ( & V_292 -> V_287 ) ;
F_103 ( & V_292 -> V_311 , & V_289 ) ;
}
F_99 ( V_293 ) ;
F_70 ( V_293 -> V_304 , V_246 ) ;
F_62 ( & V_293 -> V_214 , V_206 ) ;
if ( V_293 -> V_310 )
F_98 ( & V_289 ) ;
else
F_95 ( & V_289 ) ;
}
static void F_104 ( void * V_6 , enum V_3 V_4 )
{
struct V_284 * V_292 = V_6 ;
struct V_281 * V_293 = V_292 -> V_296 ;
unsigned long V_206 ;
if ( ! V_293 )
return;
F_60 ( & V_293 -> V_214 , V_206 ) ;
V_292 -> V_300 = V_305 ;
F_62 ( & V_293 -> V_214 , V_206 ) ;
F_69 ( & V_293 -> V_308 ) ;
}
bool F_105 ( struct V_282 * V_86 , void * V_295 )
{
T_3 * V_312 ;
if ( V_86 -> V_313 -> V_98 -> V_314 != & V_315 . V_316 )
return false ;
#ifdef F_106
if ( V_86 -> V_313 -> V_98 -> V_317 ) {
const T_6 * V_318 ;
T_7 T_7 ;
struct V_319 * V_311 ;
V_318 = ( (struct V_320 * ) V_295 ) -> V_321 ;
T_7 = F_107 ( V_318 ++ ) ;
V_311 = F_108 ( T_7 ) ;
return ( ( V_86 -> V_322 == V_311 ) &&
( V_86 -> V_323 == F_107 ( V_318 ) ) ) ;
}
#endif
V_312 = V_86 -> V_322 ;
return * V_312 == ( unsigned ) V_295 ;
}
static int F_109 ( struct V_282 * V_86 )
{
struct V_281 * V_293 = F_92 ( V_86 ) ;
struct V_290 * V_291 = V_293 -> V_12 ;
unsigned long V_206 ;
F_60 ( & V_293 -> V_214 , V_206 ) ;
F_110 ( V_86 ) ;
V_293 -> V_310 = false ;
V_293 -> V_304 = F_73 ( & V_291 -> V_306 ) ;
if ( ! V_293 -> V_304 ) {
F_62 ( & V_293 -> V_214 , V_206 ) ;
return 0 ;
}
F_87 ( & V_293 -> V_308 , F_100 , ( unsigned long ) V_293 ) ;
F_62 ( & V_293 -> V_214 , V_206 ) ;
return 1 ;
}
static int F_111 ( struct V_282 * V_86 , enum V_324 V_325 , unsigned long V_52 )
{
struct V_281 * V_293 = F_92 ( V_86 ) ;
struct V_284 * V_292 , * V_309 ;
unsigned long V_206 ;
struct V_290 * V_291 = V_293 -> V_12 ;
struct V_326 * V_327 ;
F_101 ( V_289 ) ;
switch ( V_325 ) {
case V_328 :
F_60 ( & V_293 -> V_214 , V_206 ) ;
F_70 ( V_293 -> V_304 , V_244 ) ;
F_67 (desc, _dt, &pch->work_list , node) {
V_292 -> V_300 = V_305 ;
F_103 ( & V_292 -> V_311 , & V_289 ) ;
}
F_97 ( & V_289 , & V_291 -> V_299 ) ;
F_62 ( & V_293 -> V_214 , V_206 ) ;
break;
case V_329 :
V_327 = (struct V_326 * ) V_52 ;
if ( V_327 -> V_330 == V_331 ) {
if ( V_327 -> V_165 )
V_293 -> V_332 = V_327 -> V_165 ;
if ( V_327 -> V_333 )
V_293 -> V_334 = F_112 ( V_327 -> V_333 ) ;
if ( V_327 -> V_335 )
V_293 -> V_336 = V_327 -> V_335 ;
} else if ( V_327 -> V_330 == V_337 ) {
if ( V_327 -> V_164 )
V_293 -> V_332 = V_327 -> V_164 ;
if ( V_327 -> V_338 )
V_293 -> V_334 = F_112 ( V_327 -> V_338 ) ;
if ( V_327 -> V_339 )
V_293 -> V_336 = V_327 -> V_339 ;
}
break;
default:
F_36 ( V_293 -> V_12 -> V_306 . V_98 , L_41 ) ;
return - V_340 ;
}
return 0 ;
}
static void F_113 ( struct V_282 * V_86 )
{
struct V_281 * V_293 = F_92 ( V_86 ) ;
unsigned long V_206 ;
F_60 ( & V_293 -> V_214 , V_206 ) ;
F_91 ( & V_293 -> V_308 ) ;
F_75 ( V_293 -> V_304 ) ;
V_293 -> V_304 = NULL ;
if ( V_293 -> V_310 )
F_97 ( & V_293 -> V_302 , & V_293 -> V_12 -> V_299 ) ;
F_62 ( & V_293 -> V_214 , V_206 ) ;
}
static enum V_341
F_114 ( struct V_282 * V_86 , T_8 V_307 ,
struct V_342 * V_343 )
{
return F_115 ( V_86 , V_307 , V_343 ) ;
}
static void F_116 ( struct V_282 * V_86 )
{
F_100 ( ( unsigned long ) F_92 ( V_86 ) ) ;
}
static T_8 F_117 ( struct V_285 * V_286 )
{
struct V_284 * V_292 , * V_344 = F_94 ( V_286 ) ;
struct V_281 * V_293 = F_92 ( V_286 -> V_86 ) ;
T_8 V_307 ;
unsigned long V_206 ;
F_60 ( & V_293 -> V_214 , V_206 ) ;
while ( ! F_118 ( & V_344 -> V_311 ) ) {
V_292 = F_119 ( V_344 -> V_311 . V_169 , struct V_284 , V_311 ) ;
F_120 ( & V_292 -> V_287 ) ;
F_103 ( & V_292 -> V_311 , & V_293 -> V_302 ) ;
}
V_307 = F_120 ( & V_344 -> V_287 ) ;
F_66 ( & V_344 -> V_311 , & V_293 -> V_302 ) ;
F_62 ( & V_293 -> V_214 , V_206 ) ;
return V_307 ;
}
static inline void F_121 ( struct V_284 * V_292 )
{
V_292 -> V_296 = NULL ;
V_292 -> V_9 . V_160 = & V_292 -> V_345 ;
V_292 -> V_9 . V_6 = V_292 ;
V_292 -> V_346 . V_194 = V_347 ;
V_292 -> V_346 . V_176 = 0 ;
V_292 -> V_346 . V_181 = 0 ;
V_292 -> V_346 . V_190 = V_348 ;
V_292 -> V_346 . V_192 = V_349 ;
V_292 -> V_9 . V_134 = & V_292 -> V_346 ;
V_292 -> V_9 . V_5 = F_104 ;
V_292 -> V_287 . V_350 = F_117 ;
F_85 ( & V_292 -> V_311 ) ;
}
static int F_122 ( struct V_290 * V_291 , T_9 V_351 , int V_352 )
{
struct V_284 * V_292 ;
unsigned long V_206 ;
int V_219 ;
if ( ! V_291 )
return 0 ;
V_292 = F_123 ( V_352 * sizeof( * V_292 ) , V_351 ) ;
if ( ! V_292 )
return 0 ;
F_60 ( & V_291 -> V_298 , V_206 ) ;
for ( V_219 = 0 ; V_219 < V_352 ; V_219 ++ ) {
F_121 ( & V_292 [ V_219 ] ) ;
F_66 ( & V_292 [ V_219 ] . V_311 , & V_291 -> V_299 ) ;
}
F_62 ( & V_291 -> V_298 , V_206 ) ;
return V_352 ;
}
static struct V_284 *
F_124 ( struct V_290 * V_291 )
{
struct V_284 * V_292 = NULL ;
unsigned long V_206 ;
if ( ! V_291 )
return NULL ;
F_60 ( & V_291 -> V_298 , V_206 ) ;
if ( ! F_118 ( & V_291 -> V_299 ) ) {
V_292 = F_119 ( V_291 -> V_299 . V_169 ,
struct V_284 , V_311 ) ;
F_125 ( & V_292 -> V_311 ) ;
V_292 -> V_300 = V_301 ;
V_292 -> V_287 . V_294 = NULL ;
}
F_62 ( & V_291 -> V_298 , V_206 ) ;
return V_292 ;
}
static struct V_284 * F_126 ( struct V_281 * V_293 )
{
struct V_290 * V_291 = V_293 -> V_12 ;
T_3 * V_312 = V_293 -> V_86 . V_322 ;
struct V_284 * V_292 ;
V_292 = F_124 ( V_291 ) ;
if ( ! V_292 ) {
if ( ! F_122 ( V_291 , V_353 , 1 ) )
return NULL ;
V_292 = F_124 ( V_291 ) ;
if ( ! V_292 ) {
F_36 ( V_293 -> V_12 -> V_306 . V_98 ,
L_42 , V_137 , __LINE__ ) ;
return NULL ;
}
}
V_292 -> V_296 = V_293 ;
V_292 -> V_287 . V_307 = 0 ;
F_127 ( & V_292 -> V_287 ) ;
V_292 -> V_9 . V_36 = V_312 ? V_293 -> V_86 . V_323 : 0 ;
V_292 -> V_346 . V_15 = & V_293 -> V_12 -> V_306 . V_15 ;
F_128 ( & V_292 -> V_287 , & V_293 -> V_86 ) ;
return V_292 ;
}
static inline void F_129 ( struct V_159 * V_345 ,
T_10 V_60 , T_10 V_354 , T_11 V_355 )
{
V_345 -> V_169 = NULL ;
V_345 -> V_163 = V_355 ;
V_345 -> V_165 = V_60 ;
V_345 -> V_164 = V_354 ;
}
static struct V_284 *
F_130 ( struct V_281 * V_293 , T_10 V_60 ,
T_10 V_354 , T_11 V_355 )
{
struct V_284 * V_292 = F_126 ( V_293 ) ;
if ( ! V_292 ) {
F_36 ( V_293 -> V_12 -> V_306 . V_98 , L_43 ,
V_137 , __LINE__ ) ;
return NULL ;
}
F_129 ( & V_292 -> V_345 , V_60 , V_354 , V_355 ) ;
return V_292 ;
}
static inline int F_131 ( struct V_284 * V_292 , T_11 V_355 )
{
struct V_281 * V_293 = V_292 -> V_296 ;
struct V_19 * V_20 = & V_293 -> V_12 -> V_306 ;
int V_336 ;
V_336 = V_20 -> V_15 . V_253 / 8 ;
V_336 *= V_20 -> V_15 . V_256 ;
V_336 >>= V_292 -> V_346 . V_187 ;
if ( V_336 > 16 )
V_336 = 16 ;
while ( V_336 > 1 ) {
if ( ! ( V_355 % ( V_336 << V_292 -> V_346 . V_187 ) ) )
break;
V_336 -- ;
}
return V_336 ;
}
static struct V_285 * F_132 (
struct V_282 * V_86 , T_10 V_356 , T_11 V_355 ,
T_11 V_357 , enum V_358 V_330 ,
void * V_359 )
{
struct V_284 * V_292 ;
struct V_281 * V_293 = F_92 ( V_86 ) ;
T_10 V_60 ;
T_10 V_354 ;
V_292 = F_126 ( V_293 ) ;
if ( ! V_292 ) {
F_36 ( V_293 -> V_12 -> V_306 . V_98 , L_43 ,
V_137 , __LINE__ ) ;
return NULL ;
}
switch ( V_330 ) {
case V_331 :
V_292 -> V_346 . V_172 = 1 ;
V_292 -> V_346 . V_174 = 0 ;
V_292 -> V_9 . V_145 = V_146 ;
V_354 = V_356 ;
V_60 = V_293 -> V_332 ;
break;
case V_337 :
V_292 -> V_346 . V_172 = 0 ;
V_292 -> V_346 . V_174 = 1 ;
V_292 -> V_9 . V_145 = V_147 ;
V_354 = V_293 -> V_332 ;
V_60 = V_356 ;
break;
default:
F_36 ( V_293 -> V_12 -> V_306 . V_98 , L_44 ,
V_137 , __LINE__ ) ;
return NULL ;
}
V_292 -> V_346 . V_187 = V_293 -> V_334 ;
V_292 -> V_346 . V_184 = 1 ;
V_293 -> V_310 = true ;
F_129 ( & V_292 -> V_345 , V_60 , V_354 , V_357 ) ;
return & V_292 -> V_287 ;
}
static struct V_285 *
F_133 ( struct V_282 * V_86 , T_10 V_60 ,
T_10 V_354 , T_11 V_355 , unsigned long V_206 )
{
struct V_284 * V_292 ;
struct V_281 * V_293 = F_92 ( V_86 ) ;
struct V_19 * V_20 ;
int V_360 ;
if ( F_134 ( ! V_293 || ! V_355 ) )
return NULL ;
V_20 = & V_293 -> V_12 -> V_306 ;
V_292 = F_130 ( V_293 , V_60 , V_354 , V_355 ) ;
if ( ! V_292 )
return NULL ;
V_292 -> V_346 . V_172 = 1 ;
V_292 -> V_346 . V_174 = 1 ;
V_292 -> V_9 . V_145 = V_148 ;
V_360 = V_20 -> V_15 . V_253 / 8 ;
while ( V_360 > 1 ) {
if ( ! ( V_355 % V_360 ) )
break;
V_360 /= 2 ;
}
V_292 -> V_346 . V_187 = 0 ;
while ( V_360 != ( 1 << V_292 -> V_346 . V_187 ) )
V_292 -> V_346 . V_187 ++ ;
V_292 -> V_346 . V_184 = F_131 ( V_292 , V_355 ) ;
V_292 -> V_287 . V_206 = V_206 ;
return & V_292 -> V_287 ;
}
static struct V_285 *
F_135 ( struct V_282 * V_86 , struct V_361 * V_362 ,
unsigned int V_363 , enum V_358 V_330 ,
unsigned long V_351 , void * V_359 )
{
struct V_284 * V_364 , * V_292 = NULL ;
struct V_281 * V_293 = F_92 ( V_86 ) ;
struct V_361 * V_365 ;
unsigned long V_206 ;
int V_219 ;
T_10 V_87 ;
if ( F_134 ( ! V_293 || ! V_362 || ! V_363 ) )
return NULL ;
V_87 = V_293 -> V_332 ;
V_364 = NULL ;
F_136 (sgl, sg, sg_len, i) {
V_292 = F_126 ( V_293 ) ;
if ( ! V_292 ) {
struct V_290 * V_291 = V_293 -> V_12 ;
F_36 ( V_293 -> V_12 -> V_306 . V_98 ,
L_43 ,
V_137 , __LINE__ ) ;
if ( ! V_364 )
return NULL ;
F_60 ( & V_291 -> V_298 , V_206 ) ;
while ( ! F_118 ( & V_364 -> V_311 ) ) {
V_292 = F_119 ( V_364 -> V_311 . V_169 ,
struct V_284 , V_311 ) ;
F_103 ( & V_292 -> V_311 , & V_291 -> V_299 ) ;
}
F_103 ( & V_364 -> V_311 , & V_291 -> V_299 ) ;
F_62 ( & V_291 -> V_298 , V_206 ) ;
return NULL ;
}
if ( ! V_364 )
V_364 = V_292 ;
else
F_66 ( & V_292 -> V_311 , & V_364 -> V_311 ) ;
if ( V_330 == V_331 ) {
V_292 -> V_346 . V_172 = 1 ;
V_292 -> V_346 . V_174 = 0 ;
V_292 -> V_9 . V_145 = V_146 ;
F_129 ( & V_292 -> V_345 ,
V_87 , F_137 ( V_365 ) , F_138 ( V_365 ) ) ;
} else {
V_292 -> V_346 . V_172 = 0 ;
V_292 -> V_346 . V_174 = 1 ;
V_292 -> V_9 . V_145 = V_147 ;
F_129 ( & V_292 -> V_345 ,
F_137 ( V_365 ) , V_87 , F_138 ( V_365 ) ) ;
}
V_292 -> V_346 . V_187 = V_293 -> V_334 ;
V_292 -> V_346 . V_184 = 1 ;
}
V_292 -> V_287 . V_206 = V_351 ;
return & V_292 -> V_287 ;
}
static T_12 F_139 ( int V_366 , void * V_218 )
{
if ( F_64 ( V_218 ) )
return V_367 ;
else
return V_368 ;
}
static int T_13
F_140 ( struct V_369 * V_370 , const struct V_371 * V_13 )
{
struct V_372 * V_373 ;
struct V_290 * V_291 ;
struct V_281 * V_293 ;
struct V_19 * V_20 ;
struct V_374 * V_375 ;
struct V_376 * V_377 ;
int V_219 , V_207 , V_366 ;
int V_16 ;
V_373 = V_370 -> V_98 . V_378 ;
V_291 = F_79 ( sizeof( * V_291 ) , V_274 ) ;
if ( ! V_291 ) {
F_36 ( & V_370 -> V_98 , L_45 ) ;
return - V_217 ;
}
V_20 = & V_291 -> V_306 ;
V_20 -> V_98 = & V_370 -> V_98 ;
V_20 -> V_229 = NULL ;
V_20 -> V_216 = V_373 ? V_373 -> V_379 : 0 ;
V_377 = & V_370 -> V_377 ;
F_141 ( V_377 -> V_380 , F_142 ( V_377 ) , L_46 ) ;
V_20 -> V_23 = F_143 ( V_377 -> V_380 , F_142 ( V_377 ) ) ;
if ( ! V_20 -> V_23 ) {
V_207 = - V_340 ;
goto V_381;
}
V_291 -> V_382 = F_144 ( & V_370 -> V_98 , L_47 ) ;
if ( F_145 ( V_291 -> V_382 ) ) {
F_36 ( & V_370 -> V_98 , L_48 ) ;
V_207 = - V_168 ;
goto V_383;
}
F_146 ( V_370 , V_291 ) ;
#ifndef F_147
F_148 ( V_291 -> V_382 ) ;
#endif
V_366 = V_370 -> V_366 [ 0 ] ;
V_207 = F_149 ( V_366 , F_139 , 0 ,
F_150 ( & V_370 -> V_98 ) , V_20 ) ;
if ( V_207 )
goto V_384;
V_207 = F_83 ( V_20 ) ;
if ( V_207 )
goto V_385;
F_85 ( & V_291 -> V_299 ) ;
F_84 ( & V_291 -> V_298 ) ;
if ( ! F_122 ( V_291 , V_274 , V_386 ) )
F_151 ( & V_370 -> V_98 , L_49 ) ;
V_375 = & V_291 -> V_387 ;
F_85 ( & V_375 -> V_223 ) ;
if ( V_373 )
V_16 = F_152 ( int , V_373 -> V_388 , V_20 -> V_15 . V_16 ) ;
else
V_16 = F_152 ( int , V_20 -> V_15 . V_213 , V_20 -> V_15 . V_16 ) ;
V_291 -> V_389 = F_79 ( V_16 * sizeof( * V_293 ) , V_274 ) ;
for ( V_219 = 0 ; V_219 < V_16 ; V_219 ++ ) {
V_293 = & V_291 -> V_389 [ V_219 ] ;
if ( ! V_370 -> V_98 . V_317 )
V_293 -> V_86 . V_322 = V_373 ? & V_373 -> V_312 [ V_219 ] : NULL ;
else
V_293 -> V_86 . V_322 = V_370 -> V_98 . V_317 ;
F_85 ( & V_293 -> V_302 ) ;
F_84 ( & V_293 -> V_214 ) ;
V_293 -> V_304 = NULL ;
V_293 -> V_86 . V_313 = V_375 ;
V_293 -> V_12 = V_291 ;
F_66 ( & V_293 -> V_86 . V_319 , & V_375 -> V_223 ) ;
}
V_375 -> V_98 = & V_370 -> V_98 ;
if ( V_373 ) {
V_375 -> V_390 = V_373 -> V_390 ;
} else {
F_153 ( V_391 , V_375 -> V_390 ) ;
if ( V_20 -> V_15 . V_213 ) {
F_153 ( V_392 , V_375 -> V_390 ) ;
F_153 ( V_393 , V_375 -> V_390 ) ;
}
}
V_375 -> V_394 = F_109 ;
V_375 -> V_395 = F_113 ;
V_375 -> V_396 = F_133 ;
V_375 -> V_397 = F_132 ;
V_375 -> V_398 = F_114 ;
V_375 -> V_399 = F_135 ;
V_375 -> V_400 = F_111 ;
V_375 -> V_401 = F_116 ;
V_207 = F_154 ( V_375 ) ;
if ( V_207 ) {
F_36 ( & V_370 -> V_98 , L_50 ) ;
goto V_402;
}
F_43 ( & V_370 -> V_98 ,
L_51 , V_370 -> V_403 ) ;
F_43 ( & V_370 -> V_98 ,
L_52 ,
V_20 -> V_15 . V_256 ,
V_20 -> V_15 . V_253 / 8 , V_20 -> V_15 . V_16 ,
V_20 -> V_15 . V_213 , V_20 -> V_15 . V_232 ) ;
return 0 ;
V_402:
F_90 ( V_20 ) ;
V_385:
F_155 ( V_366 , V_20 ) ;
V_384:
#ifndef F_147
F_156 ( V_291 -> V_382 ) ;
#endif
F_157 ( V_291 -> V_382 ) ;
V_383:
F_158 ( V_20 -> V_23 ) ;
V_381:
F_159 ( V_377 -> V_380 , F_142 ( V_377 ) ) ;
F_86 ( V_291 ) ;
return V_207 ;
}
static int T_14 F_160 ( struct V_369 * V_370 )
{
struct V_290 * V_291 = F_161 ( V_370 ) ;
struct V_281 * V_293 , * V_404 ;
struct V_19 * V_20 ;
struct V_376 * V_377 ;
int V_366 ;
if ( ! V_291 )
return 0 ;
F_146 ( V_370 , NULL ) ;
F_67 (pch, _p, &pdmac->ddma.channels,
chan.device_node) {
F_68 ( & V_293 -> V_86 . V_319 ) ;
F_111 ( & V_293 -> V_86 , V_328 , 0 ) ;
F_113 ( & V_293 -> V_86 ) ;
}
V_20 = & V_291 -> V_306 ;
F_90 ( V_20 ) ;
V_366 = V_370 -> V_366 [ 0 ] ;
F_155 ( V_366 , V_20 ) ;
F_158 ( V_20 -> V_23 ) ;
V_377 = & V_370 -> V_377 ;
F_159 ( V_377 -> V_380 , F_142 ( V_377 ) ) ;
#ifndef F_147
F_156 ( V_291 -> V_382 ) ;
#endif
F_86 ( V_291 ) ;
return 0 ;
}
static int F_162 ( struct V_313 * V_98 )
{
struct V_290 * V_291 = F_163 ( V_98 ) ;
if ( ! V_291 ) {
F_36 ( V_98 , L_53 ) ;
return - V_405 ;
}
F_156 ( V_291 -> V_382 ) ;
return 0 ;
}
static int F_164 ( struct V_313 * V_98 )
{
struct V_290 * V_291 = F_163 ( V_98 ) ;
if ( ! V_291 ) {
F_36 ( V_98 , L_53 ) ;
return - V_405 ;
}
F_148 ( V_291 -> V_382 ) ;
return 0 ;
}
