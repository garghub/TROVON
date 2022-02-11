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
if ( V_4 -> V_7 . V_21 == NULL || ! V_4 -> V_26 )
return - V_22 ;
signal = F_3 ( F_1 ( V_2 ) ) ;
* V_25 = signal ;
F_8 ( L_2 , signal ) ;
return 0 ;
}
static inline char * F_10 ( enum V_27 type )
{
char * V_28 ;
switch ( type ) {
case V_29 :
V_28 = L_3 ;
break;
case V_30 :
V_28 = L_4 ;
break;
case V_31 :
V_28 = L_5 ;
break;
case V_32 :
V_28 = L_6 ;
break;
case V_33 :
V_28 = L_7 ;
break;
default:
V_28 = L_8 ;
break;
}
return V_28 ;
}
static struct V_34 * F_11 ( struct V_1 * V_2 ,
enum V_27 V_35 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_36 * V_37 = V_4 -> V_37 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_37 -> V_39 ; V_38 ++ )
if ( V_35 == V_37 -> V_40 [ V_38 ] . type )
break;
if ( V_38 == V_37 -> V_39 ) {
F_8 ( L_9 ,
F_10 ( V_35 ) , V_4 -> type ) ;
V_38 = 0 ;
}
F_8 ( L_10 , V_38 ,
F_10 ( V_37 -> V_40 [ V_38 ] . type ) ) ;
return & V_37 -> V_40 [ V_38 ] ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_34 * V_41 ,
unsigned * V_42 , T_3 * V_43 , T_3 * V_44 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_41 -> V_39 ; V_38 ++ ) {
if ( * V_42 > V_41 -> V_45 [ V_38 ] . V_46 )
continue;
break;
}
if ( V_38 == V_41 -> V_39 ) {
F_8 ( L_11 ,
* V_42 , V_41 -> V_45 [ V_38 - 1 ] . V_46 ) ;
* V_42 = V_41 -> V_45 [ -- V_38 ] . V_46 ;
}
* V_43 = V_41 -> V_45 [ V_38 ] . V_43 ;
* V_44 = V_41 -> V_45 [ V_38 ] . V_44 ;
F_8 ( L_12
L_13 ,
* V_42 / 16 , * V_42 % 16 * 100 / 16 , * V_42 ,
V_38 , * V_43 , * V_44 ) ;
return V_38 ;
}
static void F_13 ( struct V_1 * V_2 ,
T_3 * V_43 , T_3 * V_44 , unsigned int V_47 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
switch ( V_4 -> type ) {
case V_48 :
switch ( V_47 ) {
case 1 :
* V_44 |= 0x08 ;
break;
default:
* V_44 &= ~ 0x08 ;
break;
}
break;
case V_49 :
switch ( V_47 ) {
case 1 :
* V_44 |= 0x01 ;
break;
default:
* V_44 &= ~ 0x01 ;
break;
}
break;
default:
break;
}
}
static int F_14 ( struct V_1 * V_2 ,
struct V_50 * V_40 ,
T_3 * V_43 , T_3 * V_44 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_51 ;
switch ( V_4 -> type ) {
case V_52 :
* V_44 &= ~ 0x03 ;
if ( V_40 -> V_53 & V_54 )
* V_44 |= V_55 ;
else if ( V_40 -> V_53 & V_56 )
* V_44 |= V_57 ;
else
* V_44 |= V_58 ;
break;
case V_59 :
* V_44 &= ~ 0x0f ;
if ( V_40 -> V_53 & V_60 ) {
* V_44 |= V_61 ;
} else if ( V_40 -> V_53 & V_62 ) {
* V_44 |= V_63 ;
} else if ( V_40 -> V_53 & V_64 ) {
* V_44 |= V_65 ;
} else if ( V_40 -> V_53 & V_54 ) {
* V_44 |= V_66 ;
}
break;
case V_67 :
* V_44 &= ~ 0x0f ;
if ( V_40 -> V_53 & ( V_60 | V_64 ) ) {
* V_44 |= V_68 ;
} else if ( V_40 -> V_53 & V_62 ) {
* V_44 |= V_69 ;
} else if ( V_40 -> V_53 & V_54 ) {
* V_44 |= V_70 ;
}
break;
case V_49 :
* V_44 &= ~ 0x03 ;
if ( ! ( V_40 -> V_53 & V_71 ) )
* V_44 |= 2 ;
break;
case V_72 :
* V_43 |= V_73 ;
break;
case V_48 :
{
struct V_74 V_75 = V_4 -> V_7 ;
T_3 V_76 [ 4 ] = { 0x14 , 0x00 , 0x17 , 0x00 } ;
* V_44 &= ~ 0x40 ;
if ( V_40 -> V_53 & V_71 ) {
* V_44 |= 0x40 ;
V_76 [ 1 ] = 0x04 ;
}
V_75 . V_77 = 0x0a ;
V_51 = F_15 ( & V_75 , & V_76 [ 0 ] , 2 ) ;
if ( 2 != V_51 )
F_16 ( L_14
L_15 , V_51 ) ;
V_51 = F_15 ( & V_75 , & V_76 [ 2 ] , 2 ) ;
if ( 2 != V_51 )
F_16 ( L_14
L_15 , V_51 ) ;
break;
}
}
if ( V_78 [ V_4 -> V_79 ] )
F_13 ( V_2 , V_43 , V_44 , V_78 [ V_4 -> V_79 ] ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_3 V_43 , T_3 V_80 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_51 ;
T_3 V_76 [ 2 ] ;
V_76 [ 0 ] = ( V_43 & ~ 0x38 ) | 0x18 ;
V_76 [ 1 ] = V_80 ;
F_8 ( L_16 , V_76 [ 0 ] , V_76 [ 1 ] ) ;
V_51 = F_15 ( & V_4 -> V_7 , V_76 , 2 ) ;
if ( 2 != V_51 )
F_16 ( L_17 , V_51 ) ;
return V_51 == 2 ? 0 : V_51 ;
}
static int F_18 ( struct V_1 * V_2 , T_3 * V_76 ,
T_2 div , T_3 V_43 , T_3 V_44 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_51 ;
switch ( V_4 -> type ) {
case V_81 :
F_17 ( V_2 , V_43 , 0x20 ) ;
break;
case V_82 :
F_17 ( V_2 , V_43 , 0x60 ) ;
break;
case V_72 :
{
unsigned long V_83 = V_84 + F_19 ( 1 ) ;
T_3 V_85 = 0 ;
for (; ; ) {
if ( F_20 ( V_84 , V_83 ) )
return 0 ;
V_51 = F_2 ( & V_4 -> V_7 ,
& V_85 , 1 ) ;
if ( 1 != V_51 ) {
F_16 ( L_18
L_19 , V_51 ) ;
break;
}
if ( V_85 & V_86 )
break;
F_21 ( 10 ) ;
}
V_43 &= ~ V_73 ;
V_76 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_76 [ 1 ] = div & 0xff ;
V_76 [ 2 ] = V_43 ;
V_76 [ 3 ] = V_44 ;
F_8 ( L_20 ,
V_76 [ 0 ] , V_76 [ 1 ] , V_76 [ 2 ] , V_76 [ 3 ] ) ;
V_51 = F_15 ( & V_4 -> V_7 , V_76 , 4 ) ;
if ( 4 != V_51 )
F_16 ( L_14
L_21 , V_51 ) ;
break;
}
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , T_3 * V_76 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
switch ( V_4 -> type ) {
case V_87 :
case V_88 :
F_8 ( L_22
L_23 ) ;
return 0 ;
case V_10 :
case V_11 :
case V_89 :
case V_90 :
case V_13 :
case V_12 :
case V_14 :
V_76 [ 3 ] = 0x19 ;
break;
case V_16 :
V_76 [ 2 ] = 0x88 ;
V_76 [ 3 ] = 0x09 ;
break;
case V_91 :
V_76 [ 3 ] = 0x11 ;
break;
case V_92 :
V_76 [ 3 ] = 0xa5 ;
break;
case V_93 :
V_76 [ 3 ] = 0x39 ;
break;
case V_82 :
case V_94 :
F_23 ( L_24 ) ;
V_76 [ 3 ] = 0x01 ;
break;
case V_95 :
default:
V_76 [ 3 ] = 0xa4 ;
break;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_50 * V_40 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_43 , V_44 ;
T_2 div ;
T_3 V_76 [ 4 ] ;
int V_51 , V_96 , V_38 ;
enum V_27 V_35 ;
struct V_34 * V_41 ;
if ( V_40 -> V_53 == V_97 ) {
V_96 = 940 ;
V_35 = V_32 ;
} else if ( ( V_40 -> V_53 & V_98 ) &&
! ( V_40 -> V_53 & ~ V_98 ) ) {
V_96 = 732 ;
V_35 = V_32 ;
} else if ( V_40 -> V_53 == V_56 ) {
V_96 = 543 ;
V_35 = V_31 ;
} else {
V_96 = 623 ;
V_35 = V_30 ;
}
V_41 = F_11 ( V_2 , V_35 ) ;
V_38 = F_12 ( V_2 , V_41 , & V_40 -> V_42 ,
& V_43 , & V_44 ) ;
div = V_40 -> V_42 + V_96 + V_99 ;
F_8 ( L_25
L_26 ,
V_40 -> V_42 / 16 , V_40 -> V_42 % 16 * 100 / 16 ,
V_96 / 16 , V_96 % 16 * 100 / 16 ,
V_99 / 16 , V_99 % 16 * 100 / 16 , div ) ;
F_14 ( V_2 , V_40 , & V_43 , & V_44 ) ;
if ( V_41 -> V_100 && div < V_4 -> V_101 ) {
V_76 [ 0 ] = V_43 ;
V_76 [ 1 ] = V_44 ;
V_76 [ 2 ] = ( div >> 8 ) & 0x7f ;
V_76 [ 3 ] = div & 0xff ;
} else {
V_76 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_76 [ 1 ] = div & 0xff ;
V_76 [ 2 ] = V_43 ;
V_76 [ 3 ] = V_44 ;
}
V_4 -> V_101 = div ;
if ( V_41 -> V_102 ) {
struct V_103 V_104 ;
int V_105 = 0 ;
int V_106 = ( V_40 -> V_53 & ( V_54 |
V_56 ) ) &&
! ( V_40 -> V_53 & ~ ( V_54 |
V_56 ) ) ;
V_104 . V_107 = V_108 ;
V_104 . V_4 = & V_105 ;
if ( V_40 -> V_53 == V_56 ) {
if ( V_41 -> V_109 ^ V_41 -> V_110 )
V_105 |= V_111 ;
if ( V_41 -> V_112 ^ V_41 -> V_113 )
V_105 |= V_114 ;
} else {
if ( V_41 -> V_109 )
V_105 |= V_111 ;
if ( V_41 -> V_112 )
V_105 |= V_114 ;
}
if ( V_41 -> V_115 )
V_105 |= V_116 ;
if ( V_106 ) {
if ( V_38 == 0 && V_41 -> V_117 )
V_105 |= F_25 ( V_41 -> V_117 ) ;
else if ( V_38 == 1 && V_41 -> V_118 )
V_105 |= F_25 ( V_41 -> V_118 ) ;
else if ( V_41 -> V_119 )
V_105 |= F_25 ( V_41 -> V_119 ) ;
} else {
if ( V_38 == 0 && V_41 -> V_120 )
V_105 |= F_25 ( V_41 -> V_120 ) ;
else if ( V_38 == 1 && V_41 -> V_121 )
V_105 |= F_25 ( V_41 -> V_121 ) ;
else if ( V_41 -> V_122 )
V_105 |= F_25 ( V_41 -> V_122 ) ;
}
if ( V_41 -> V_123 )
V_105 |= V_124 ;
F_26 ( V_4 -> V_7 . V_21 , V_125 ,
& V_104 ) ;
}
F_8 ( L_20 ,
V_76 [ 0 ] , V_76 [ 1 ] , V_76 [ 2 ] , V_76 [ 3 ] ) ;
V_51 = F_15 ( & V_4 -> V_7 , V_76 , 4 ) ;
if ( 4 != V_51 )
F_16 ( L_27 , V_51 ) ;
F_18 ( V_2 , & V_76 [ 0 ] , div , V_43 , V_44 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_50 * V_40 )
{
struct V_36 * V_37 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_76 [ 4 ] ;
T_2 div ;
int V_51 , V_126 ;
struct V_34 * V_41 ;
unsigned int V_127 = V_40 -> V_42 ;
V_37 = V_4 -> V_37 ;
for ( V_126 = V_37 -> V_39 - 1 ; V_126 > 0 ; V_126 -- )
if ( V_37 -> V_40 [ V_126 ] . type == V_29 )
break;
V_41 = & V_37 -> V_40 [ V_126 ] ;
switch ( V_41 -> V_128 ) {
case 0 :
V_127 += ( unsigned int ) ( 10.7 * 16000 ) ;
break;
case 1 :
V_127 += ( unsigned int ) ( 33.3 * 16000 ) ;
break;
case 2 :
V_127 += ( unsigned int ) ( 41.3 * 16000 ) ;
break;
default:
F_16 ( L_28 ,
V_41 -> V_128 ) ;
return 0 ;
}
V_76 [ 2 ] = ( V_41 -> V_45 [ 0 ] . V_43 & ~ V_129 ) |
V_130 ;
F_22 ( V_2 , & V_76 [ 0 ] ) ;
div = ( V_127 + 400 ) / 800 ;
if ( V_41 -> V_100 && div < V_4 -> V_101 ) {
V_76 [ 0 ] = V_76 [ 2 ] ;
V_76 [ 1 ] = V_76 [ 3 ] ;
V_76 [ 2 ] = ( div >> 8 ) & 0x7f ;
V_76 [ 3 ] = div & 0xff ;
} else {
V_76 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_76 [ 1 ] = div & 0xff ;
}
F_8 ( L_29 ,
V_76 [ 0 ] , V_76 [ 1 ] , V_76 [ 2 ] , V_76 [ 3 ] ) ;
V_4 -> V_101 = div ;
if ( V_41 -> V_102 ) {
int V_43 = 0 ;
struct V_103 V_104 ;
V_104 . V_107 = V_108 ;
V_104 . V_4 = & V_43 ;
if ( V_41 -> V_109 &&
! V_41 -> V_131 )
V_43 |= V_111 ;
if ( V_41 -> V_112 &&
! V_41 -> V_132 )
V_43 |= V_114 ;
if ( V_41 -> V_115 )
V_43 |= V_116 ;
if ( V_41 -> V_133 )
V_43 |= V_134 ;
if ( V_41 -> V_128 == 2 )
V_43 |= V_135 ;
F_26 ( V_4 -> V_7 . V_21 , V_125 ,
& V_104 ) ;
}
V_51 = F_15 ( & V_4 -> V_7 , V_76 , 4 ) ;
if ( 4 != V_51 )
F_16 ( L_27 , V_51 ) ;
switch ( V_4 -> type ) {
case V_10 :
V_76 [ 2 ] = 0x98 ;
V_76 [ 3 ] = 0x20 ;
V_51 = F_15 ( & V_4 -> V_7 , V_76 , 4 ) ;
if ( 4 != V_51 )
F_16 ( L_27 , V_51 ) ;
break;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_50 * V_40 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_136 = - V_22 ;
if ( V_4 -> V_7 . V_21 == NULL )
return - V_22 ;
switch ( V_40 -> V_137 ) {
case V_138 :
V_4 -> V_26 = true ;
V_136 = F_27 ( V_2 , V_40 ) ;
V_4 -> V_42 = V_40 -> V_42 * 125 / 2 ;
break;
case V_139 :
case V_140 :
V_4 -> V_26 = false ;
V_136 = F_24 ( V_2 , V_40 ) ;
V_4 -> V_42 = V_40 -> V_42 * 62500 ;
break;
}
V_4 -> V_141 = 0 ;
return V_136 ;
}
static void F_29 ( struct V_1 * V_2 , T_3 * V_142 ,
const T_1 V_143 ,
const T_1 V_42 ,
const T_1 V_141 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
switch ( V_4 -> type ) {
case V_89 :
case V_90 :
if ( V_141 == 8000000 &&
V_42 >= 158870000 )
V_142 [ 3 ] |= 0x08 ;
break;
case V_144 :
V_142 [ 3 ] |= ( V_42 < 161000000 ) ? 1 :
( V_42 < 444000000 ) ? 2 : 4 ;
if ( V_141 == 8000000 )
V_142 [ 3 ] |= 1 << 3 ;
break;
case V_48 :
case V_49 :
{
unsigned int V_145 ;
if ( V_146 [ V_4 -> V_79 ] )
V_145 = V_146 [ V_4 -> V_79 ] ;
else
switch ( V_143 ) {
case V_147 :
V_145 = 1 ;
break;
case V_148 :
default:
V_145 = 0 ;
break;
}
F_13 ( V_2 , & V_142 [ 2 ] , & V_142 [ 3 ] , V_145 ) ;
break;
}
default:
break;
}
}
static T_1 F_30 ( struct V_1 * V_2 , T_3 * V_142 ,
const T_1 V_143 ,
const T_1 V_127 ,
const T_1 V_149 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_36 * V_37 = V_4 -> V_37 ;
static struct V_34 * V_41 ;
T_3 V_43 , V_44 ;
T_1 div ;
int V_136 ;
T_1 V_42 = V_127 / 62500 ;
if ( ! V_37 -> V_150 ) {
F_23 ( L_30
L_31 ,
V_4 -> type , V_4 -> V_37 -> V_28 ) ;
return 0 ;
}
V_41 = F_11 ( V_2 , V_33 ) ;
V_136 = F_12 ( V_2 , V_41 , & V_42 , & V_43 , & V_44 ) ;
if ( V_136 < 0 )
return 0 ;
div = ( ( V_42 + V_41 -> V_151 ) * 62500 + V_99 +
V_37 -> V_150 / 2 ) / V_37 -> V_150 ;
V_142 [ 0 ] = div >> 8 ;
V_142 [ 1 ] = div & 0xff ;
V_142 [ 2 ] = V_43 ;
V_142 [ 3 ] = V_44 ;
F_29 ( V_2 , V_142 , V_143 , V_127 , V_149 ) ;
F_8 ( L_32 ,
V_37 -> V_28 , div , V_142 [ 0 ] , V_142 [ 1 ] , V_142 [ 2 ] , V_142 [ 3 ] ) ;
return ( div * V_37 -> V_150 ) - V_41 -> V_151 ;
}
static int F_31 ( struct V_1 * V_2 ,
T_3 * V_142 , int V_152 )
{
struct V_153 * V_154 = & V_2 -> V_155 ;
T_1 V_143 = V_154 -> V_156 ;
T_1 V_149 = V_154 -> V_157 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_42 ;
if ( V_152 < 5 )
return - V_22 ;
V_42 = F_30 ( V_2 , V_142 + 1 , V_143 , V_154 -> V_42 , V_149 ) ;
if ( V_42 == 0 )
return - V_22 ;
V_142 [ 0 ] = V_4 -> V_7 . V_77 ;
V_4 -> V_42 = V_42 ;
V_4 -> V_141 = V_154 -> V_157 ;
return 5 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_153 * V_154 = & V_2 -> V_155 ;
T_1 V_143 = V_154 -> V_156 ;
T_1 V_149 = V_154 -> V_157 ;
T_1 V_127 = V_154 -> V_42 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_42 ;
T_1 V_158 , V_159 ;
int V_136 ;
T_3 V_142 [ 5 ] ;
if ( V_4 -> V_7 . V_21 == NULL )
return - V_22 ;
V_158 = V_4 -> V_42 ;
V_159 = V_4 -> V_141 ;
V_42 = F_30 ( V_2 , V_142 + 1 , V_143 , V_127 , V_149 ) ;
if ( V_42 == 0 )
return - V_22 ;
V_142 [ 0 ] = V_4 -> V_7 . V_77 ;
V_4 -> V_42 = V_42 ;
V_4 -> V_141 = V_149 ;
if ( V_2 -> V_160 . V_161 . V_162 )
V_2 -> V_160 . V_161 . V_162 ( V_2 ) ;
if ( V_2 -> V_160 . V_163 )
V_2 -> V_160 . V_163 ( V_2 , 1 ) ;
V_136 = F_15 ( & V_4 -> V_7 , V_142 + 1 , 4 ) ;
if ( V_136 != 4 )
goto V_164;
return 0 ;
V_164:
V_4 -> V_42 = V_158 ;
V_4 -> V_141 = V_159 ;
return V_136 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_7 . V_21 == NULL )
return - V_22 ;
if ( V_4 -> V_37 -> V_165 ) {
int V_136 ;
if ( V_2 -> V_160 . V_163 )
V_2 -> V_160 . V_163 ( V_2 , 1 ) ;
V_136 = F_15 ( & V_4 -> V_7 ,
V_4 -> V_37 -> V_165 + 1 ,
V_4 -> V_37 -> V_165 [ 0 ] ) ;
if ( V_136 != V_4 -> V_37 -> V_165 [ 0 ] )
return V_136 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_7 . V_21 == NULL )
return - V_22 ;
if ( V_4 -> V_37 -> V_166 ) {
int V_136 ;
if ( V_2 -> V_160 . V_163 )
V_2 -> V_160 . V_163 ( V_2 , 1 ) ;
V_136 = F_15 ( & V_4 -> V_7 ,
V_4 -> V_37 -> V_166 + 1 ,
V_4 -> V_37 -> V_166 [ 0 ] ) ;
if ( V_136 != V_4 -> V_37 -> V_166 [ 0 ] )
return V_136 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_36 ( & V_167 ) ;
if ( V_4 )
F_37 ( V_4 ) ;
F_38 ( & V_167 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , T_1 * V_42 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
* V_42 = V_4 -> V_42 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , T_1 * V_141 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
* V_141 = V_4 -> V_141 ;
return 0 ;
}
struct V_1 * F_41 ( struct V_1 * V_2 ,
struct V_168 * V_169 ,
T_3 V_170 ,
unsigned int type )
{
struct V_3 * V_4 = NULL ;
int V_171 ;
if ( type >= V_172 ) {
F_42 ( V_173 L_33 ,
V_174 , type , V_172 - 1 ) ;
return NULL ;
}
if ( V_169 != NULL ) {
T_3 V_175 [ 1 ] ;
struct V_176 V_177 = {
. V_77 = V_170 , . V_178 = V_179 ,
. V_142 = V_175 , . V_180 = 1 ,
} ;
if ( V_2 -> V_160 . V_163 )
V_2 -> V_160 . V_163 ( V_2 , 1 ) ;
if ( 1 != F_43 ( V_169 , & V_177 , 1 ) )
F_42 ( V_173 L_34
L_35 ,
F_44 ( V_169 ) , V_170 ,
V_181 [ type ] . V_28 ) ;
if ( V_2 -> V_160 . V_163 )
V_2 -> V_160 . V_163 ( V_2 , 0 ) ;
}
F_36 ( & V_167 ) ;
V_171 = F_45 ( struct V_3 , V_4 ,
V_182 ,
V_169 , V_170 ,
L_36 ) ;
switch ( V_171 ) {
case 0 :
F_38 ( & V_167 ) ;
return NULL ;
case 1 :
V_2 -> V_5 = V_4 ;
V_4 -> type = type ;
V_4 -> V_37 = & V_181 [ type ] ;
V_4 -> V_79 = V_183 ++ ;
break;
default:
V_2 -> V_5 = V_4 ;
break;
}
F_38 ( & V_167 ) ;
memcpy ( & V_2 -> V_160 . V_184 , & V_185 ,
sizeof( struct V_186 ) ) ;
if ( type != V_4 -> type )
F_16 ( L_37 ,
type , V_4 -> type , V_4 -> V_37 -> V_28 ) ;
else
F_46 ( L_38 ,
V_4 -> type , V_4 -> V_37 -> V_28 ) ;
if ( ( V_187 ) || ( ( V_78 [ V_4 -> V_79 ] > 0 ) ||
( V_146 [ V_4 -> V_79 ] > 0 ) ) ) {
if ( 0 == V_78 [ V_4 -> V_79 ] )
F_46 ( L_39
L_40 , V_4 -> V_79 ) ;
else
F_46 ( L_39
L_41 ,
V_4 -> V_79 , V_78 [ V_4 -> V_79 ] ) ;
if ( 0 == V_146 [ V_4 -> V_79 ] )
F_46 ( L_42
L_40 , V_4 -> V_79 ) ;
else
F_46 ( L_42
L_41 ,
V_4 -> V_79 , V_146 [ V_4 -> V_79 ] ) ;
}
F_47 ( V_2 -> V_160 . V_184 . V_188 . V_28 , V_4 -> V_37 -> V_28 ,
sizeof( V_2 -> V_160 . V_184 . V_188 . V_28 ) ) ;
return V_2 ;
}
