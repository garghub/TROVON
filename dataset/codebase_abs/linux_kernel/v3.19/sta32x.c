static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = V_2 -> V_6 >> 16 ;
V_4 -> type = V_7 ;
V_4 -> V_8 = 3 * V_5 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
int V_5 = V_2 -> V_6 >> 16 ;
int V_13 = V_2 -> V_6 & 0xffff ;
unsigned int V_14 ;
int V_15 ;
V_14 = F_4 ( V_12 , V_16 ) & 0xf0 ;
F_5 ( V_12 , V_16 , V_14 ) ;
F_5 ( V_12 , V_17 , V_13 ) ;
if ( V_5 == 1 )
F_5 ( V_12 , V_16 , V_14 | 0x04 ) ;
else if ( V_5 == 5 )
F_5 ( V_12 , V_16 , V_14 | 0x08 ) ;
else
return - V_18 ;
for ( V_15 = 0 ; V_15 < 3 * V_5 ; V_15 ++ )
V_10 -> V_19 . V_20 . V_21 [ V_15 ] =
F_4 ( V_12 , V_22 + V_15 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
struct V_23 * V_24 = F_7 ( V_12 ) ;
int V_5 = V_2 -> V_6 >> 16 ;
int V_13 = V_2 -> V_6 & 0xffff ;
unsigned int V_14 ;
int V_15 ;
V_14 = F_4 ( V_12 , V_16 ) & 0xf0 ;
F_5 ( V_12 , V_16 , V_14 ) ;
F_5 ( V_12 , V_17 , V_13 ) ;
for ( V_15 = 0 ; V_15 < V_5 && ( V_13 + V_15 < V_25 ) ; V_15 ++ )
V_24 -> V_26 [ V_13 + V_15 ] =
( V_10 -> V_19 . V_20 . V_21 [ 3 * V_15 ] << 16 )
| ( V_10 -> V_19 . V_20 . V_21 [ 3 * V_15 + 1 ] << 8 )
| ( V_10 -> V_19 . V_20 . V_21 [ 3 * V_15 + 2 ] ) ;
for ( V_15 = 0 ; V_15 < 3 * V_5 ; V_15 ++ )
F_5 ( V_12 , V_22 + V_15 ,
V_10 -> V_19 . V_20 . V_21 [ V_15 ] ) ;
if ( V_5 == 1 )
F_5 ( V_12 , V_16 , V_14 | 0x01 ) ;
else if ( V_5 == 5 )
F_5 ( V_12 , V_16 , V_14 | 0x02 ) ;
else
return - V_18 ;
return 0 ;
}
static int F_8 ( struct V_11 * V_12 )
{
struct V_23 * V_24 = F_7 ( V_12 ) ;
unsigned int V_14 ;
int V_15 ;
V_14 = F_4 ( V_12 , V_16 ) & 0xf0 ;
for ( V_15 = 0 ; V_15 < V_25 ; V_15 ++ ) {
F_5 ( V_12 , V_17 , V_15 ) ;
F_5 ( V_12 , V_22 ,
( V_24 -> V_26 [ V_15 ] >> 16 ) & 0xff ) ;
F_5 ( V_12 , V_27 ,
( V_24 -> V_26 [ V_15 ] >> 8 ) & 0xff ) ;
F_5 ( V_12 , V_28 ,
( V_24 -> V_26 [ V_15 ] ) & 0xff ) ;
F_5 ( V_12 , V_16 , V_14 ) ;
F_5 ( V_12 , V_16 , V_14 | 0x01 ) ;
}
return 0 ;
}
static int F_9 ( struct V_11 * V_12 )
{
struct V_23 * V_24 = F_7 ( V_12 ) ;
unsigned int V_29 ;
int V_30 ;
V_29 = F_4 ( V_12 , V_31 ) ;
F_5 ( V_12 , V_31 , V_29 | V_32 ) ;
F_8 ( V_12 ) ;
V_30 = F_10 ( V_24 -> V_33 ) ;
F_5 ( V_12 , V_31 , V_29 ) ;
return V_30 ;
}
static void F_11 ( struct V_34 * V_35 )
{
struct V_23 * V_24 = F_12 ( V_35 , struct V_23 ,
V_36 . V_35 ) ;
struct V_11 * V_12 = V_24 -> V_12 ;
unsigned int V_37 , V_38 ;
V_38 = F_4 ( V_12 , V_39 ) ;
F_13 ( V_24 -> V_33 , true ) ;
V_37 = F_4 ( V_12 , V_39 ) ;
F_13 ( V_24 -> V_33 , false ) ;
if ( V_37 != V_38 ) {
F_14 ( V_24 -> V_33 ) ;
F_9 ( V_12 ) ;
}
if ( ! V_24 -> V_40 )
F_15 ( V_41 ,
& V_24 -> V_36 ,
F_16 ( V_42 ) ) ;
}
static void F_17 ( struct V_23 * V_24 )
{
if ( V_24 -> V_43 -> V_44 ) {
V_24 -> V_40 = 0 ;
F_15 ( V_41 ,
& V_24 -> V_36 ,
F_16 ( V_42 ) ) ;
}
}
static void F_18 ( struct V_23 * V_24 )
{
if ( V_24 -> V_43 -> V_44 ) {
V_24 -> V_40 = 1 ;
F_19 ( & V_24 -> V_36 ) ;
}
}
static int F_20 ( struct V_45 * V_46 ,
int V_47 , unsigned int V_48 , int V_49 )
{
struct V_11 * V_12 = V_46 -> V_12 ;
struct V_23 * V_24 = F_7 ( V_12 ) ;
int V_15 , V_50 , V_51 , V_52 ;
unsigned int V_53 = 0 ;
unsigned int V_54 = - 1 ;
unsigned int V_55 = 0 ;
F_21 ( L_1 , V_48 ) ;
V_24 -> V_56 = V_48 ;
if ( V_24 -> V_56 ) {
for ( V_15 = 0 ; V_15 < F_22 ( V_57 ) ; V_15 ++ ) {
V_51 = V_57 [ V_15 ] . V_51 ;
V_52 = V_57 [ V_15 ] . V_52 ;
for ( V_50 = 0 ; V_58 [ V_51 ] [ V_50 ] . V_59 ; V_50 ++ ) {
if ( V_58 [ V_51 ] [ V_50 ] . V_59 * V_52 == V_48 ) {
V_53 |= F_23 ( V_52 ) ;
if ( V_52 < V_54 )
V_54 = V_52 ;
if ( V_52 > V_55 )
V_55 = V_52 ;
break;
}
}
}
V_53 &= ~ V_60 ;
if ( ! V_53 ) {
F_24 ( V_12 -> V_61 , L_2 ) ;
return - V_18 ;
}
} else {
V_53 = V_62 ;
V_54 = 32000 ;
V_55 = 192000 ;
}
V_46 -> V_63 -> V_64 . V_53 = V_53 ;
V_46 -> V_63 -> V_64 . V_54 = V_54 ;
V_46 -> V_63 -> V_64 . V_55 = V_55 ;
return 0 ;
}
static int F_25 ( struct V_45 * V_46 ,
unsigned int V_65 )
{
struct V_11 * V_12 = V_46 -> V_12 ;
struct V_23 * V_24 = F_7 ( V_12 ) ;
T_1 V_66 = F_4 ( V_12 , V_67 ) ;
F_21 ( L_3 ) ;
V_66 &= ~ ( V_68 | V_69 ) ;
switch ( V_65 & V_70 ) {
case V_71 :
break;
default:
return - V_18 ;
}
switch ( V_65 & V_72 ) {
case V_73 :
case V_74 :
case V_75 :
V_24 -> V_76 = V_65 & V_72 ;
break;
default:
return - V_18 ;
}
switch ( V_65 & V_77 ) {
case V_78 :
V_66 |= V_69 ;
break;
case V_79 :
V_66 |= V_68 ;
break;
default:
return - V_18 ;
}
F_5 ( V_12 , V_67 , V_66 ) ;
return 0 ;
}
static int F_26 ( struct V_80 * V_81 ,
struct V_82 * V_83 ,
struct V_45 * V_84 )
{
struct V_11 * V_12 = V_84 -> V_12 ;
struct V_23 * V_24 = F_7 ( V_12 ) ;
unsigned int V_85 ;
int V_15 , V_86 = - 1 , V_51 = - 1 ;
T_1 V_37 , V_66 ;
V_85 = F_27 ( V_83 ) ;
F_21 ( L_4 , V_85 ) ;
for ( V_15 = 0 ; V_15 < F_22 ( V_57 ) ; V_15 ++ )
if ( V_57 [ V_15 ] . V_52 == V_85 ) {
V_51 = V_57 [ V_15 ] . V_51 ;
break;
}
if ( V_51 < 0 )
return - V_18 ;
for ( V_15 = 0 ; V_58 [ V_51 ] [ V_15 ] . V_59 ; V_15 ++ )
if ( V_58 [ V_51 ] [ V_15 ] . V_59 * V_85 == V_24 -> V_56 ) {
V_86 = V_58 [ V_51 ] [ V_15 ] . V_86 ;
break;
}
if ( V_86 < 0 )
return - V_18 ;
V_37 = F_4 ( V_12 , V_39 ) ;
V_37 &= ~ ( V_87 | V_88 ) ;
V_37 |= ( V_51 << V_89 ) | ( V_86 << V_90 ) ;
V_66 = F_4 ( V_12 , V_67 ) ;
V_66 &= ~ ( V_91 | V_92 ) ;
switch ( F_28 ( V_83 ) ) {
case 24 :
F_21 ( L_5 ) ;
case 32 :
F_21 ( L_6 ) ;
switch ( V_24 -> V_76 ) {
case V_73 :
V_66 |= 0x0 ;
break;
case V_75 :
V_66 |= 0x1 ;
break;
case V_74 :
V_66 |= 0x2 ;
break;
}
break;
case 20 :
F_21 ( L_7 ) ;
switch ( V_24 -> V_76 ) {
case V_73 :
V_66 |= 0x4 ;
break;
case V_75 :
V_66 |= 0x5 ;
break;
case V_74 :
V_66 |= 0x6 ;
break;
}
break;
case 18 :
F_21 ( L_8 ) ;
switch ( V_24 -> V_76 ) {
case V_73 :
V_66 |= 0x8 ;
break;
case V_75 :
V_66 |= 0x9 ;
break;
case V_74 :
V_66 |= 0xa ;
break;
}
break;
case 16 :
F_21 ( L_9 ) ;
switch ( V_24 -> V_76 ) {
case V_73 :
V_66 |= 0x0 ;
break;
case V_75 :
V_66 |= 0xd ;
break;
case V_74 :
V_66 |= 0xe ;
break;
}
break;
default:
return - V_18 ;
}
F_5 ( V_12 , V_39 , V_37 ) ;
F_5 ( V_12 , V_67 , V_66 ) ;
return 0 ;
}
static int F_29 ( struct V_11 * V_12 ,
enum V_93 V_94 )
{
int V_95 ;
struct V_23 * V_24 = F_7 ( V_12 ) ;
F_21 ( L_10 , V_94 ) ;
switch ( V_94 ) {
case V_96 :
break;
case V_97 :
F_30 ( V_12 , V_98 ,
V_99 | V_100 ,
V_99 | V_100 ) ;
break;
case V_101 :
if ( V_12 -> V_102 . V_103 == V_104 ) {
V_95 = F_31 ( F_22 ( V_24 -> V_105 ) ,
V_24 -> V_105 ) ;
if ( V_95 != 0 ) {
F_24 ( V_12 -> V_61 ,
L_11 , V_95 ) ;
return V_95 ;
}
F_9 ( V_12 ) ;
F_17 ( V_24 ) ;
}
F_30 ( V_12 , V_98 ,
V_99 | V_100 ,
V_99 | V_100 ) ;
break;
case V_104 :
F_30 ( V_12 , V_98 ,
V_99 | V_100 ,
V_99 ) ;
F_32 ( 300 ) ;
F_18 ( V_24 ) ;
F_33 ( F_22 ( V_24 -> V_105 ) ,
V_24 -> V_105 ) ;
break;
}
V_12 -> V_102 . V_103 = V_94 ;
return 0 ;
}
static int F_34 ( struct V_11 * V_12 )
{
struct V_23 * V_24 = F_7 ( V_12 ) ;
int V_15 , V_95 = 0 , V_106 = 0 ;
V_24 -> V_12 = V_12 ;
V_24 -> V_43 = F_35 ( V_12 -> V_61 ) ;
V_95 = F_31 ( F_22 ( V_24 -> V_105 ) ,
V_24 -> V_105 ) ;
if ( V_95 != 0 ) {
F_24 ( V_12 -> V_61 , L_11 , V_95 ) ;
return V_95 ;
}
F_36 ( V_24 -> V_33 , true ) ;
F_5 ( V_12 , V_107 , 0xc2 ) ;
F_5 ( V_12 , V_108 , 0xc2 ) ;
F_5 ( V_12 , V_98 , 0x5c ) ;
F_5 ( V_12 , V_31 , 0x10 ) ;
F_5 ( V_12 , V_109 , 0x60 ) ;
F_5 ( V_12 , V_110 , 0x00 ) ;
F_5 ( V_12 , V_111 , 0x40 ) ;
F_36 ( V_24 -> V_33 , false ) ;
if ( ! ( V_24 -> V_43 -> V_112 & V_113 ) )
V_106 |= V_114 ;
if ( ! ( V_24 -> V_43 -> V_112 & V_115 ) )
V_106 |= V_116 ;
F_30 ( V_12 , V_39 ,
V_114 | V_116 ,
V_106 ) ;
F_30 ( V_12 , V_98 ,
V_117 ,
V_24 -> V_43 -> V_118
<< V_119 ) ;
F_30 ( V_12 , V_120 ,
V_121 ,
V_24 -> V_43 -> V_122
<< V_123 ) ;
F_30 ( V_12 , V_124 ,
V_121 ,
V_24 -> V_43 -> V_125
<< V_123 ) ;
F_30 ( V_12 , V_111 ,
V_121 ,
V_24 -> V_43 -> V_126
<< V_123 ) ;
for ( V_15 = 4 ; V_15 <= 49 ; V_15 += 5 )
V_24 -> V_26 [ V_15 ] = 0x400000 ;
for ( V_15 = 50 ; V_15 <= 54 ; V_15 ++ )
V_24 -> V_26 [ V_15 ] = 0x7fffff ;
V_24 -> V_26 [ 55 ] = 0x5a9df7 ;
V_24 -> V_26 [ 56 ] = 0x7fffff ;
V_24 -> V_26 [ 59 ] = 0x7fffff ;
V_24 -> V_26 [ 60 ] = 0x400000 ;
V_24 -> V_26 [ 61 ] = 0x400000 ;
if ( V_24 -> V_43 -> V_44 )
F_37 ( & V_24 -> V_36 , F_11 ) ;
F_29 ( V_12 , V_101 ) ;
F_33 ( F_22 ( V_24 -> V_105 ) , V_24 -> V_105 ) ;
return 0 ;
}
static int F_38 ( struct V_11 * V_12 )
{
struct V_23 * V_24 = F_7 ( V_12 ) ;
F_18 ( V_24 ) ;
F_33 ( F_22 ( V_24 -> V_105 ) , V_24 -> V_105 ) ;
return 0 ;
}
static bool F_39 ( struct V_127 * V_61 , unsigned int V_128 )
{
switch ( V_128 ) {
case V_39 ... V_129 :
case V_130 ... V_131 :
return 0 ;
}
return 1 ;
}
static int F_40 ( struct V_132 * V_133 ,
const struct V_134 * V_135 )
{
struct V_23 * V_24 ;
int V_95 , V_15 ;
V_24 = F_41 ( & V_133 -> V_61 , sizeof( struct V_23 ) ,
V_136 ) ;
if ( ! V_24 )
return - V_137 ;
for ( V_15 = 0 ; V_15 < F_22 ( V_24 -> V_105 ) ; V_15 ++ )
V_24 -> V_105 [ V_15 ] . V_138 = V_139 [ V_15 ] ;
V_95 = F_42 ( & V_133 -> V_61 , F_22 ( V_24 -> V_105 ) ,
V_24 -> V_105 ) ;
if ( V_95 != 0 ) {
F_24 ( & V_133 -> V_61 , L_12 , V_95 ) ;
return V_95 ;
}
V_24 -> V_33 = F_43 ( V_133 , & V_140 ) ;
if ( F_44 ( V_24 -> V_33 ) ) {
V_95 = F_45 ( V_24 -> V_33 ) ;
F_24 ( & V_133 -> V_61 , L_13 , V_95 ) ;
return V_95 ;
}
F_46 ( V_133 , V_24 ) ;
V_95 = F_47 ( & V_133 -> V_61 , & V_141 , & V_142 , 1 ) ;
if ( V_95 != 0 )
F_24 ( & V_133 -> V_61 , L_14 , V_95 ) ;
return V_95 ;
}
static int F_48 ( struct V_132 * V_143 )
{
F_49 ( & V_143 -> V_61 ) ;
return 0 ;
}
