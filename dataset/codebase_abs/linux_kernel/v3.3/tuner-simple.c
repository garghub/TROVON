static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char V_6 ;
if ( 1 != F_2 ( & V_4 -> V_7 , & V_6 , 1 ) )
return 0 ;
return V_6 ;
}
static inline int F_3 ( const int V_8 )
{
return ( V_8 & V_9 ) << 13 ;
}
static inline int F_4 ( const int type , const int V_8 )
{
switch ( type ) {
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
return ( ( V_8 & V_9 ) == V_15 ) ;
case V_16 :
return V_8 | V_17 ;
default:
return V_8 & V_17 ;
}
}
static inline int F_5 ( const int V_8 )
{
return ( V_8 & V_18 ) ;
}
static inline int F_6 ( const int V_8 )
{
return ( V_8 & V_19 ) - 2 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 * V_8 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_20 ;
if ( V_4 -> V_7 . V_21 == NULL )
return - V_22 ;
V_20 = F_1 ( V_2 ) ;
* V_8 = 0 ;
if ( F_5 ( V_20 ) )
* V_8 = V_23 ;
if ( F_4 ( V_4 -> type , V_20 ) )
* V_8 |= V_24 ;
F_8 ( L_1 , F_6 ( V_20 ) ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 * V_25 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int signal ;
if ( V_4 -> V_7 . V_21 == NULL )
return - V_22 ;
signal = F_3 ( F_1 ( V_2 ) ) ;
* V_25 = signal ;
F_8 ( L_2 , signal ) ;
return 0 ;
}
static inline char * F_10 ( enum V_26 type )
{
char * V_27 ;
switch ( type ) {
case V_28 :
V_27 = L_3 ;
break;
case V_29 :
V_27 = L_4 ;
break;
case V_30 :
V_27 = L_5 ;
break;
case V_31 :
V_27 = L_6 ;
break;
case V_32 :
V_27 = L_7 ;
break;
default:
V_27 = L_8 ;
break;
}
return V_27 ;
}
static struct V_33 * F_11 ( struct V_1 * V_2 ,
enum V_26 V_34 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_36 -> V_38 ; V_37 ++ )
if ( V_34 == V_36 -> V_39 [ V_37 ] . type )
break;
if ( V_37 == V_36 -> V_38 ) {
F_8 ( L_9 ,
F_10 ( V_34 ) , V_4 -> type ) ;
V_37 = 0 ;
}
F_8 ( L_10 , V_37 ,
F_10 ( V_36 -> V_39 [ V_37 ] . type ) ) ;
return & V_36 -> V_39 [ V_37 ] ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_33 * V_40 ,
unsigned * V_41 , T_3 * V_42 , T_3 * V_43 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_40 -> V_38 ; V_37 ++ ) {
if ( * V_41 > V_40 -> V_44 [ V_37 ] . V_45 )
continue;
break;
}
if ( V_37 == V_40 -> V_38 ) {
F_8 ( L_11 ,
* V_41 , V_40 -> V_44 [ V_37 - 1 ] . V_45 ) ;
* V_41 = V_40 -> V_44 [ -- V_37 ] . V_45 ;
}
* V_42 = V_40 -> V_44 [ V_37 ] . V_42 ;
* V_43 = V_40 -> V_44 [ V_37 ] . V_43 ;
F_8 ( L_12
L_13 ,
* V_41 / 16 , * V_41 % 16 * 100 / 16 , * V_41 ,
V_37 , * V_42 , * V_43 ) ;
return V_37 ;
}
static void F_13 ( struct V_1 * V_2 ,
T_3 * V_42 , T_3 * V_43 , unsigned int V_46 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
switch ( V_4 -> type ) {
case V_47 :
switch ( V_46 ) {
case 1 :
* V_43 |= 0x08 ;
break;
default:
* V_43 &= ~ 0x08 ;
break;
}
break;
case V_48 :
switch ( V_46 ) {
case 1 :
* V_43 |= 0x01 ;
break;
default:
* V_43 &= ~ 0x01 ;
break;
}
break;
default:
break;
}
}
static int F_14 ( struct V_1 * V_2 ,
struct V_49 * V_39 ,
T_3 * V_42 , T_3 * V_43 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_50 ;
switch ( V_4 -> type ) {
case V_51 :
* V_43 &= ~ 0x03 ;
if ( V_39 -> V_52 & V_53 )
* V_43 |= V_54 ;
else if ( V_39 -> V_52 & V_55 )
* V_43 |= V_56 ;
else
* V_43 |= V_57 ;
break;
case V_58 :
* V_43 &= ~ 0x0f ;
if ( V_39 -> V_52 & V_59 ) {
* V_43 |= V_60 ;
} else if ( V_39 -> V_52 & V_61 ) {
* V_43 |= V_62 ;
} else if ( V_39 -> V_52 & V_63 ) {
* V_43 |= V_64 ;
} else if ( V_39 -> V_52 & V_53 ) {
* V_43 |= V_65 ;
}
break;
case V_66 :
* V_43 &= ~ 0x0f ;
if ( V_39 -> V_52 & ( V_59 | V_63 ) ) {
* V_43 |= V_67 ;
} else if ( V_39 -> V_52 & V_61 ) {
* V_43 |= V_68 ;
} else if ( V_39 -> V_52 & V_53 ) {
* V_43 |= V_69 ;
}
break;
case V_48 :
* V_43 &= ~ 0x03 ;
if ( ! ( V_39 -> V_52 & V_70 ) )
* V_43 |= 2 ;
break;
case V_71 :
* V_42 |= V_72 ;
break;
case V_47 :
{
struct V_73 V_74 = V_4 -> V_7 ;
T_3 V_75 [ 4 ] = { 0x14 , 0x00 , 0x17 , 0x00 } ;
* V_43 &= ~ 0x40 ;
if ( V_39 -> V_52 & V_70 ) {
* V_43 |= 0x40 ;
V_75 [ 1 ] = 0x04 ;
}
V_74 . V_76 = 0x0a ;
V_50 = F_15 ( & V_74 , & V_75 [ 0 ] , 2 ) ;
if ( 2 != V_50 )
F_16 ( L_14
L_15 , V_50 ) ;
V_50 = F_15 ( & V_74 , & V_75 [ 2 ] , 2 ) ;
if ( 2 != V_50 )
F_16 ( L_14
L_15 , V_50 ) ;
break;
}
}
if ( V_77 [ V_4 -> V_78 ] )
F_13 ( V_2 , V_42 , V_43 , V_77 [ V_4 -> V_78 ] ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_3 V_42 , T_3 V_79 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_50 ;
T_3 V_75 [ 2 ] ;
V_75 [ 0 ] = ( V_42 & ~ 0x38 ) | 0x18 ;
V_75 [ 1 ] = V_79 ;
F_8 ( L_16 , V_75 [ 0 ] , V_75 [ 1 ] ) ;
V_50 = F_15 ( & V_4 -> V_7 , V_75 , 2 ) ;
if ( 2 != V_50 )
F_16 ( L_17 , V_50 ) ;
return V_50 == 2 ? 0 : V_50 ;
}
static int F_18 ( struct V_1 * V_2 , T_3 * V_75 ,
T_2 div , T_3 V_42 , T_3 V_43 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_50 ;
switch ( V_4 -> type ) {
case V_80 :
F_17 ( V_2 , V_42 , 0x20 ) ;
break;
case V_81 :
F_17 ( V_2 , V_42 , 0x60 ) ;
break;
case V_71 :
{
unsigned long V_82 = V_83 + F_19 ( 1 ) ;
T_3 V_84 = 0 ;
for (; ; ) {
if ( F_20 ( V_83 , V_82 ) )
return 0 ;
V_50 = F_2 ( & V_4 -> V_7 ,
& V_84 , 1 ) ;
if ( 1 != V_50 ) {
F_16 ( L_18
L_19 , V_50 ) ;
break;
}
if ( V_84 & V_85 )
break;
F_21 ( 10 ) ;
}
V_42 &= ~ V_72 ;
V_75 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_75 [ 1 ] = div & 0xff ;
V_75 [ 2 ] = V_42 ;
V_75 [ 3 ] = V_43 ;
F_8 ( L_20 ,
V_75 [ 0 ] , V_75 [ 1 ] , V_75 [ 2 ] , V_75 [ 3 ] ) ;
V_50 = F_15 ( & V_4 -> V_7 , V_75 , 4 ) ;
if ( 4 != V_50 )
F_16 ( L_14
L_21 , V_50 ) ;
break;
}
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , T_3 * V_75 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
switch ( V_4 -> type ) {
case V_86 :
case V_87 :
F_8 ( L_22
L_23 ) ;
return 0 ;
case V_10 :
case V_11 :
case V_88 :
case V_89 :
case V_13 :
case V_12 :
case V_14 :
V_75 [ 3 ] = 0x19 ;
break;
case V_16 :
V_75 [ 2 ] = 0x88 ;
V_75 [ 3 ] = 0x09 ;
break;
case V_90 :
V_75 [ 3 ] = 0x11 ;
break;
case V_91 :
V_75 [ 3 ] = 0xa5 ;
break;
case V_92 :
V_75 [ 3 ] = 0x39 ;
break;
case V_81 :
case V_93 :
F_23 ( L_24 ) ;
V_75 [ 3 ] = 0x01 ;
break;
case V_94 :
default:
V_75 [ 3 ] = 0xa4 ;
break;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_49 * V_39 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_42 , V_43 ;
T_2 div ;
T_3 V_75 [ 4 ] ;
int V_50 , V_95 , V_37 ;
enum V_26 V_34 ;
struct V_33 * V_40 ;
if ( V_39 -> V_52 == V_96 ) {
V_95 = 940 ;
V_34 = V_31 ;
} else if ( ( V_39 -> V_52 & V_97 ) &&
! ( V_39 -> V_52 & ~ V_97 ) ) {
V_95 = 732 ;
V_34 = V_31 ;
} else if ( V_39 -> V_52 == V_55 ) {
V_95 = 543 ;
V_34 = V_30 ;
} else {
V_95 = 623 ;
V_34 = V_29 ;
}
V_40 = F_11 ( V_2 , V_34 ) ;
V_37 = F_12 ( V_2 , V_40 , & V_39 -> V_41 ,
& V_42 , & V_43 ) ;
div = V_39 -> V_41 + V_95 + V_98 ;
F_8 ( L_25
L_26 ,
V_39 -> V_41 / 16 , V_39 -> V_41 % 16 * 100 / 16 ,
V_95 / 16 , V_95 % 16 * 100 / 16 ,
V_98 / 16 , V_98 % 16 * 100 / 16 , div ) ;
F_14 ( V_2 , V_39 , & V_42 , & V_43 ) ;
if ( V_40 -> V_99 && div < V_4 -> V_100 ) {
V_75 [ 0 ] = V_42 ;
V_75 [ 1 ] = V_43 ;
V_75 [ 2 ] = ( div >> 8 ) & 0x7f ;
V_75 [ 3 ] = div & 0xff ;
} else {
V_75 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_75 [ 1 ] = div & 0xff ;
V_75 [ 2 ] = V_42 ;
V_75 [ 3 ] = V_43 ;
}
V_4 -> V_100 = div ;
if ( V_40 -> V_101 ) {
struct V_102 V_103 ;
int V_104 = 0 ;
int V_105 = ( V_39 -> V_52 & ( V_53 |
V_55 ) ) &&
! ( V_39 -> V_52 & ~ ( V_53 |
V_55 ) ) ;
V_103 . V_106 = V_107 ;
V_103 . V_4 = & V_104 ;
if ( V_39 -> V_52 == V_55 ) {
if ( V_40 -> V_108 ^ V_40 -> V_109 )
V_104 |= V_110 ;
if ( V_40 -> V_111 ^ V_40 -> V_112 )
V_104 |= V_113 ;
} else {
if ( V_40 -> V_108 )
V_104 |= V_110 ;
if ( V_40 -> V_111 )
V_104 |= V_113 ;
}
if ( V_40 -> V_114 )
V_104 |= V_115 ;
if ( V_105 ) {
if ( V_37 == 0 && V_40 -> V_116 )
V_104 |= F_25 ( V_40 -> V_116 ) ;
else if ( V_37 == 1 && V_40 -> V_117 )
V_104 |= F_25 ( V_40 -> V_117 ) ;
else if ( V_40 -> V_118 )
V_104 |= F_25 ( V_40 -> V_118 ) ;
} else {
if ( V_37 == 0 && V_40 -> V_119 )
V_104 |= F_25 ( V_40 -> V_119 ) ;
else if ( V_37 == 1 && V_40 -> V_120 )
V_104 |= F_25 ( V_40 -> V_120 ) ;
else if ( V_40 -> V_121 )
V_104 |= F_25 ( V_40 -> V_121 ) ;
}
if ( V_40 -> V_122 )
V_104 |= V_123 ;
F_26 ( V_4 -> V_7 . V_21 , V_124 ,
& V_103 ) ;
}
F_8 ( L_20 ,
V_75 [ 0 ] , V_75 [ 1 ] , V_75 [ 2 ] , V_75 [ 3 ] ) ;
V_50 = F_15 ( & V_4 -> V_7 , V_75 , 4 ) ;
if ( 4 != V_50 )
F_16 ( L_27 , V_50 ) ;
F_18 ( V_2 , & V_75 [ 0 ] , div , V_42 , V_43 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_49 * V_39 )
{
struct V_35 * V_36 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_75 [ 4 ] ;
T_2 div ;
int V_50 , V_125 ;
struct V_33 * V_40 ;
unsigned int V_126 = V_39 -> V_41 ;
V_36 = V_4 -> V_36 ;
for ( V_125 = V_36 -> V_38 - 1 ; V_125 > 0 ; V_125 -- )
if ( V_36 -> V_39 [ V_125 ] . type == V_28 )
break;
V_40 = & V_36 -> V_39 [ V_125 ] ;
switch ( V_40 -> V_127 ) {
case 0 :
V_126 += ( unsigned int ) ( 10.7 * 16000 ) ;
break;
case 1 :
V_126 += ( unsigned int ) ( 33.3 * 16000 ) ;
break;
case 2 :
V_126 += ( unsigned int ) ( 41.3 * 16000 ) ;
break;
default:
F_16 ( L_28 ,
V_40 -> V_127 ) ;
return 0 ;
}
V_75 [ 2 ] = ( V_40 -> V_44 [ 0 ] . V_42 & ~ V_128 ) |
V_129 ;
F_22 ( V_2 , & V_75 [ 0 ] ) ;
div = ( V_126 + 400 ) / 800 ;
if ( V_40 -> V_99 && div < V_4 -> V_100 ) {
V_75 [ 0 ] = V_75 [ 2 ] ;
V_75 [ 1 ] = V_75 [ 3 ] ;
V_75 [ 2 ] = ( div >> 8 ) & 0x7f ;
V_75 [ 3 ] = div & 0xff ;
} else {
V_75 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_75 [ 1 ] = div & 0xff ;
}
F_8 ( L_29 ,
V_75 [ 0 ] , V_75 [ 1 ] , V_75 [ 2 ] , V_75 [ 3 ] ) ;
V_4 -> V_100 = div ;
if ( V_40 -> V_101 ) {
int V_42 = 0 ;
struct V_102 V_103 ;
V_103 . V_106 = V_107 ;
V_103 . V_4 = & V_42 ;
if ( V_40 -> V_108 &&
! V_40 -> V_130 )
V_42 |= V_110 ;
if ( V_40 -> V_111 &&
! V_40 -> V_131 )
V_42 |= V_113 ;
if ( V_40 -> V_114 )
V_42 |= V_115 ;
if ( V_40 -> V_132 )
V_42 |= V_133 ;
if ( V_40 -> V_127 == 2 )
V_42 |= V_134 ;
F_26 ( V_4 -> V_7 . V_21 , V_124 ,
& V_103 ) ;
}
V_50 = F_15 ( & V_4 -> V_7 , V_75 , 4 ) ;
if ( 4 != V_50 )
F_16 ( L_27 , V_50 ) ;
switch ( V_4 -> type ) {
case V_10 :
V_75 [ 2 ] = 0x98 ;
V_75 [ 3 ] = 0x20 ;
V_50 = F_15 ( & V_4 -> V_7 , V_75 , 4 ) ;
if ( 4 != V_50 )
F_16 ( L_27 , V_50 ) ;
break;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_49 * V_39 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_135 = - V_22 ;
if ( V_4 -> V_7 . V_21 == NULL )
return - V_22 ;
switch ( V_39 -> V_136 ) {
case V_137 :
V_135 = F_27 ( V_2 , V_39 ) ;
V_4 -> V_41 = V_39 -> V_41 * 125 / 2 ;
break;
case V_138 :
case V_139 :
V_135 = F_24 ( V_2 , V_39 ) ;
V_4 -> V_41 = V_39 -> V_41 * 62500 ;
break;
}
V_4 -> V_140 = 0 ;
return V_135 ;
}
static void F_29 ( struct V_1 * V_2 , T_3 * V_141 ,
const T_1 V_142 ,
const T_1 V_41 ,
const T_1 V_140 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
switch ( V_4 -> type ) {
case V_88 :
case V_89 :
if ( V_140 == 8000000 &&
V_41 >= 158870000 )
V_141 [ 3 ] |= 0x08 ;
break;
case V_143 :
V_141 [ 3 ] |= ( V_41 < 161000000 ) ? 1 :
( V_41 < 444000000 ) ? 2 : 4 ;
if ( V_140 == 8000000 )
V_141 [ 3 ] |= 1 << 3 ;
break;
case V_47 :
case V_48 :
{
unsigned int V_144 ;
if ( V_145 [ V_4 -> V_78 ] )
V_144 = V_145 [ V_4 -> V_78 ] ;
else
switch ( V_142 ) {
case V_146 :
V_144 = 1 ;
break;
case V_147 :
default:
V_144 = 0 ;
break;
}
F_13 ( V_2 , & V_141 [ 2 ] , & V_141 [ 3 ] , V_144 ) ;
break;
}
default:
break;
}
}
static T_1 F_30 ( struct V_1 * V_2 , T_3 * V_141 ,
const T_1 V_142 ,
const T_1 V_126 ,
const T_1 V_148 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
static struct V_33 * V_40 ;
T_3 V_42 , V_43 ;
T_1 div ;
int V_135 ;
T_1 V_41 = V_126 / 62500 ;
if ( ! V_36 -> V_149 ) {
F_23 ( L_30
L_31 ,
V_4 -> type , V_4 -> V_36 -> V_27 ) ;
return 0 ;
}
V_40 = F_11 ( V_2 , V_32 ) ;
V_135 = F_12 ( V_2 , V_40 , & V_41 , & V_42 , & V_43 ) ;
if ( V_135 < 0 )
return 0 ;
div = ( ( V_41 + V_40 -> V_150 ) * 62500 + V_98 +
V_36 -> V_149 / 2 ) / V_36 -> V_149 ;
V_141 [ 0 ] = div >> 8 ;
V_141 [ 1 ] = div & 0xff ;
V_141 [ 2 ] = V_42 ;
V_141 [ 3 ] = V_43 ;
F_29 ( V_2 , V_141 , V_142 , V_126 , V_148 ) ;
F_8 ( L_32 ,
V_36 -> V_27 , div , V_141 [ 0 ] , V_141 [ 1 ] , V_141 [ 2 ] , V_141 [ 3 ] ) ;
return ( div * V_36 -> V_149 ) - V_40 -> V_150 ;
}
static int F_31 ( struct V_1 * V_2 ,
T_3 * V_141 , int V_151 )
{
struct V_152 * V_153 = & V_2 -> V_154 ;
T_1 V_142 = V_153 -> V_155 ;
T_1 V_148 = V_153 -> V_156 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_41 ;
if ( V_151 < 5 )
return - V_22 ;
V_41 = F_30 ( V_2 , V_141 + 1 , V_142 , V_153 -> V_41 , V_148 ) ;
if ( V_41 == 0 )
return - V_22 ;
V_141 [ 0 ] = V_4 -> V_7 . V_76 ;
V_4 -> V_41 = V_41 ;
V_4 -> V_140 = V_153 -> V_156 ;
return 5 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_152 * V_153 = & V_2 -> V_154 ;
T_1 V_142 = V_153 -> V_155 ;
T_1 V_148 = V_153 -> V_156 ;
T_1 V_126 = V_153 -> V_41 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_41 ;
T_1 V_157 , V_158 ;
int V_135 ;
T_3 V_141 [ 5 ] ;
if ( V_4 -> V_7 . V_21 == NULL )
return - V_22 ;
V_157 = V_4 -> V_41 ;
V_158 = V_4 -> V_140 ;
V_41 = F_30 ( V_2 , V_141 + 1 , V_142 , V_126 , V_148 ) ;
if ( V_41 == 0 )
return - V_22 ;
V_141 [ 0 ] = V_4 -> V_7 . V_76 ;
V_4 -> V_41 = V_41 ;
V_4 -> V_140 = V_148 ;
if ( V_2 -> V_159 . V_160 . V_161 )
V_2 -> V_159 . V_160 . V_161 ( V_2 ) ;
if ( V_2 -> V_159 . V_162 )
V_2 -> V_159 . V_162 ( V_2 , 1 ) ;
V_135 = F_15 ( & V_4 -> V_7 , V_141 + 1 , 4 ) ;
if ( V_135 != 4 )
goto V_163;
return 0 ;
V_163:
V_4 -> V_41 = V_157 ;
V_4 -> V_140 = V_158 ;
return V_135 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_7 . V_21 == NULL )
return - V_22 ;
if ( V_4 -> V_36 -> V_164 ) {
int V_135 ;
if ( V_2 -> V_159 . V_162 )
V_2 -> V_159 . V_162 ( V_2 , 1 ) ;
V_135 = F_15 ( & V_4 -> V_7 ,
V_4 -> V_36 -> V_164 + 1 ,
V_4 -> V_36 -> V_164 [ 0 ] ) ;
if ( V_135 != V_4 -> V_36 -> V_164 [ 0 ] )
return V_135 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_7 . V_21 == NULL )
return - V_22 ;
if ( V_4 -> V_36 -> V_165 ) {
int V_135 ;
if ( V_2 -> V_159 . V_162 )
V_2 -> V_159 . V_162 ( V_2 , 1 ) ;
V_135 = F_15 ( & V_4 -> V_7 ,
V_4 -> V_36 -> V_165 + 1 ,
V_4 -> V_36 -> V_165 [ 0 ] ) ;
if ( V_135 != V_4 -> V_36 -> V_165 [ 0 ] )
return V_135 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_36 ( & V_166 ) ;
if ( V_4 )
F_37 ( V_4 ) ;
F_38 ( & V_166 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , T_1 * V_41 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
* V_41 = V_4 -> V_41 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , T_1 * V_140 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
* V_140 = V_4 -> V_140 ;
return 0 ;
}
struct V_1 * F_41 ( struct V_1 * V_2 ,
struct V_167 * V_168 ,
T_3 V_169 ,
unsigned int type )
{
struct V_3 * V_4 = NULL ;
int V_170 ;
if ( type >= V_171 ) {
F_42 ( V_172 L_33 ,
V_173 , type , V_171 - 1 ) ;
return NULL ;
}
if ( V_168 != NULL ) {
T_3 V_174 [ 1 ] ;
struct V_175 V_176 = {
. V_76 = V_169 , . V_177 = V_178 ,
. V_141 = V_174 , . V_179 = 1 ,
} ;
if ( V_2 -> V_159 . V_162 )
V_2 -> V_159 . V_162 ( V_2 , 1 ) ;
if ( 1 != F_43 ( V_168 , & V_176 , 1 ) )
F_42 ( V_172 L_34
L_35 ,
F_44 ( V_168 ) , V_169 ,
V_180 [ type ] . V_27 ) ;
if ( V_2 -> V_159 . V_162 )
V_2 -> V_159 . V_162 ( V_2 , 0 ) ;
}
F_36 ( & V_166 ) ;
V_170 = F_45 ( struct V_3 , V_4 ,
V_181 ,
V_168 , V_169 ,
L_36 ) ;
switch ( V_170 ) {
case 0 :
F_38 ( & V_166 ) ;
return NULL ;
case 1 :
V_2 -> V_5 = V_4 ;
V_4 -> type = type ;
V_4 -> V_36 = & V_180 [ type ] ;
V_4 -> V_78 = V_182 ++ ;
break;
default:
V_2 -> V_5 = V_4 ;
break;
}
F_38 ( & V_166 ) ;
memcpy ( & V_2 -> V_159 . V_183 , & V_184 ,
sizeof( struct V_185 ) ) ;
if ( type != V_4 -> type )
F_16 ( L_37 ,
type , V_4 -> type , V_4 -> V_36 -> V_27 ) ;
else
F_46 ( L_38 ,
V_4 -> type , V_4 -> V_36 -> V_27 ) ;
if ( ( V_186 ) || ( ( V_77 [ V_4 -> V_78 ] > 0 ) ||
( V_145 [ V_4 -> V_78 ] > 0 ) ) ) {
if ( 0 == V_77 [ V_4 -> V_78 ] )
F_46 ( L_39
L_40 , V_4 -> V_78 ) ;
else
F_46 ( L_39
L_41 ,
V_4 -> V_78 , V_77 [ V_4 -> V_78 ] ) ;
if ( 0 == V_145 [ V_4 -> V_78 ] )
F_46 ( L_42
L_40 , V_4 -> V_78 ) ;
else
F_46 ( L_42
L_41 ,
V_4 -> V_78 , V_145 [ V_4 -> V_78 ] ) ;
}
F_47 ( V_2 -> V_159 . V_183 . V_187 . V_27 , V_4 -> V_36 -> V_27 ,
sizeof( V_2 -> V_159 . V_183 . V_187 . V_27 ) ) ;
return V_2 ;
}
