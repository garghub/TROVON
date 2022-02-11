static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 ,
T_1 V_4 , T_1 V_5 )
{
V_5 &= V_4 ;
V_5 |= F_2 ( V_2 , V_3 ) & ~ V_4 ;
F_3 ( V_2 , V_3 , V_5 ) ;
return V_5 ;
}
void F_4 ( struct V_1 * V_2 ,
enum V_6 V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 ;
T_1 V_13 ;
if ( ! V_9 )
return;
V_12 = V_9 -> V_12 ;
if ( V_9 -> V_14 . V_15 >= 10 && V_7 == V_16 )
V_7 = V_17 ;
if ( V_2 -> V_18 & V_19 )
return;
F_5 ( V_9 -> V_14 . V_15 >= 20 ) ;
if ( V_9 -> V_14 . V_15 < 6 )
return;
if ( V_9 -> V_14 . V_15 >= 10 )
return;
if ( ! ( V_2 -> V_18 & V_20 ) )
return;
switch ( V_7 ) {
case V_16 :
V_13 = F_2 ( V_2 , V_21 ) ;
V_13 |= V_22 ;
F_3 ( V_2 , V_21 , V_13 ) ;
break;
case V_23 :
if ( V_9 -> V_14 . V_15 < 10 ) {
F_6 ( V_12 , V_24 , 1 ) ;
V_13 = F_2 ( V_2 , V_21 ) ;
V_13 &= ~ V_22 ;
V_13 |= V_25 ;
F_3 ( V_2 , V_21 , V_13 ) ;
} else {
F_3 ( V_2 , V_26 ,
( F_2 ( V_2 , V_26 ) |
V_27 ) ) ;
}
break;
case V_17 :
if ( V_9 -> V_14 . V_15 < 10 ) {
V_13 = F_2 ( V_2 , V_21 ) ;
V_13 &= ~ V_22 ;
V_13 &= ~ V_25 ;
V_13 &= ~ V_28 ;
if ( ( V_13 & V_29 ) !=
V_30 )
V_13 |= V_28 ;
F_3 ( V_2 , V_21 , V_13 ) ;
if ( V_13 & V_28 )
F_6 ( V_12 , V_24 , 0 ) ;
} else {
F_3 ( V_2 , V_26 ,
( F_2 ( V_2 , V_26 ) &
~ V_27 ) ) ;
}
break;
default:
F_5 ( 1 ) ;
}
}
static enum V_31 F_7 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_10 -> V_12 ;
T_1 V_32 ( V_13 ) ;
if ( V_2 -> V_10 -> V_14 . V_15 < 6 ) {
if ( V_12 -> V_33 == V_34 ||
V_12 -> V_33 == V_35 )
return V_36 ;
if ( V_12 -> V_33 == V_37 ) {
F_8 ( V_12 -> V_38 , V_39 , & V_13 ) ;
if ( V_13 & 0x10 )
return V_40 ;
return V_36 ;
}
}
if ( V_2 -> V_10 -> V_14 . V_15 < 10 ) {
V_13 = F_2 ( V_2 , V_21 ) ;
V_13 &= 0x7 ;
if ( V_13 == 0 )
return V_41 ;
if ( V_13 == 1 )
return V_36 ;
if ( V_13 == 2 )
return V_40 ;
}
return V_36 ;
}
static int F_9 ( struct V_1 * V_2 , int V_42 )
{
int V_32 ( V_43 ) ;
enum V_31 V_44 ;
int V_45 = 1 ;
T_1 V_13 ;
V_44 = F_7 ( V_2 ) ;
if ( V_2 -> V_10 -> V_14 . V_15 < 6 ) {
switch ( V_44 ) {
case V_40 :
V_45 = 64 ;
break;
case V_36 :
V_45 = 32 ;
break;
default:
F_5 ( 1 ) ;
}
} else if ( V_2 -> V_10 -> V_14 . V_15 < 10 ) {
switch ( V_44 ) {
case V_41 :
break;
case V_36 :
case V_40 :
V_13 = F_2 ( V_2 , V_21 ) ;
V_45 = ( V_13 >> 16 ) + 1 ;
V_45 *= 4 ;
break;
}
} else {
V_13 = F_2 ( V_2 , V_26 ) ;
V_45 = ( V_13 >> 16 ) + 1 ;
V_45 *= 4 ;
}
switch ( V_44 ) {
case V_41 :
if ( V_42 )
V_43 = 43000 ;
else
V_43 = 25000 ;
break;
case V_36 :
if ( V_42 )
V_43 = 20200000 ;
else
V_43 = 19800000 ;
break;
case V_40 :
if ( V_42 )
V_43 = 34000000 ;
else
V_43 = 25000000 ;
break;
}
V_43 /= V_45 ;
return V_43 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_10 -> V_12 ;
if ( V_12 -> V_46 == 0x4321 ) {
if ( V_12 -> V_47 == 0 )
F_3 ( V_2 , V_48 , 0x3A4 ) ;
else if ( V_12 -> V_47 == 1 )
F_3 ( V_2 , V_48 , 0xA4 ) ;
}
if ( ! ( V_2 -> V_18 & V_20 ) )
return;
if ( V_2 -> V_10 -> V_14 . V_15 >= 10 ) {
F_3 ( V_2 , V_26 ,
( F_2 ( V_2 , V_26 ) &
0x0000FFFF ) | 0x00040000 ) ;
} else {
int V_49 ;
V_49 = F_9 ( V_2 , 1 ) ;
F_3 ( V_2 , V_50 ,
( V_49 * 150 + 999999 ) / 1000000 ) ;
F_3 ( V_2 , V_51 ,
( V_49 * 15 + 999999 ) / 1000000 ) ;
}
}
static T_2 F_11 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_10 -> V_12 ;
switch ( V_12 -> V_46 ) {
case 0x4312 :
case 0x4322 :
case 0x4328 :
return 7000 ;
case 0x4325 :
default:
return 15000 ;
}
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_10 -> V_12 ;
int V_52 ;
unsigned int V_13 ;
T_1 V_53 ;
if ( V_12 -> V_33 != V_37 )
return;
if ( V_2 -> V_18 & V_19 ) {
V_2 -> V_54 = F_11 ( V_2 ) ;
return;
}
if ( ! ( V_2 -> V_18 & V_20 ) )
return;
V_52 = F_9 ( V_2 , 0 ) ;
V_53 = F_2 ( V_2 , V_50 ) ;
V_13 = ( ( ( V_53 + 2 ) * 1000000 ) + ( V_52 - 1 ) ) / V_52 ;
F_5 ( V_13 & ~ 0xFFFF ) ;
V_2 -> V_54 = V_13 ;
}
static T_1 F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_18 & V_19 )
return F_14 ( V_2 ) ;
return 20000000 ;
}
static T_1 F_15 ( struct V_1 * V_2 )
{
T_1 V_55 ;
if ( V_2 -> V_18 & V_19 ) {
if ( V_2 -> V_10 -> V_14 . V_15 < 26 )
V_55 = 16 ;
else
V_55 = ( V_2 -> V_10 -> V_14 . V_15 >= 37 ) ? 32 : 24 ;
} else {
V_55 = 28 ;
}
if ( V_55 == 32 )
return 0xffffffff ;
else
return ( 1 << V_55 ) - 1 ;
}
T_1 F_16 ( struct V_56 * V_57 , T_1 V_58 )
{
struct V_1 * V_2 = F_17 ( V_57 ) ;
if ( V_2 -> V_10 -> V_12 -> V_33 != V_34 )
return 0 ;
return F_18 ( V_2 , V_58 ) ;
}
T_1 F_19 ( struct V_56 * V_57 , T_1 V_59 )
{
struct V_1 * V_2 = F_17 ( V_57 ) ;
T_1 V_58 ;
if ( V_2 -> V_10 -> V_12 -> V_33 != V_34 )
return 0 ;
V_58 = F_18 ( V_2 , V_2 -> V_60 * V_59 ) ;
return V_58 / V_2 -> V_60 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_10 -> V_12 ;
if ( V_2 -> V_18 & V_19 ) {
return 32 ;
} else {
if ( V_2 -> V_10 -> V_14 . V_15 < 18 )
return F_21 ( V_12 ) / 1000 ;
else
return F_13 ( V_2 ) / 1000 ;
}
}
void F_22 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_10 )
return;
F_23 ( & V_2 -> V_61 ) ;
if ( V_2 -> V_10 -> V_14 . V_15 >= 11 )
V_2 -> V_62 = F_2 ( V_2 , V_63 ) ;
F_24 ( L_1 , V_2 -> V_62 ) ;
if ( V_2 -> V_10 -> V_14 . V_15 >= 20 ) {
F_3 ( V_2 , V_64 , 0 ) ;
F_3 ( V_2 , V_65 , 0 ) ;
}
F_25 ( V_2 ) ;
F_10 ( V_2 ) ;
F_4 ( V_2 , V_23 ) ;
F_12 ( V_2 ) ;
if ( V_2 -> V_10 -> V_12 -> V_33 == V_34 ) {
V_2 -> V_60 = F_20 ( V_2 ) ;
V_2 -> V_66 = F_15 ( V_2 ) / V_2 -> V_60 ;
}
}
void F_26 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_10 )
return;
F_4 ( V_2 , V_16 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_10 )
return;
F_10 ( V_2 ) ;
F_4 ( V_2 , V_23 ) ;
}
void F_28 ( struct V_1 * V_2 ,
T_1 * V_67 , T_1 * V_68 , T_1 * V_69 )
{
* V_68 = F_2 ( V_2 , V_70 ) ;
* V_67 = ( V_2 -> V_18 & V_71 ) ;
switch ( * V_67 ) {
case V_72 :
case V_73 :
case V_74 :
case V_75 :
* V_69 = F_2 ( V_2 , V_76 ) ;
break;
case V_77 :
* V_69 = F_2 ( V_2 , V_78 ) ;
break;
default:
* V_69 = F_2 ( V_2 , V_79 ) ;
break;
}
}
void F_29 ( struct V_1 * V_2 ,
T_1 * V_67 , T_1 * V_68 , T_1 * V_69 )
{
* V_68 = F_2 ( V_2 , V_70 ) ;
* V_67 = ( V_2 -> V_18 & V_71 ) ;
switch ( * V_67 ) {
case V_74 :
* V_69 = F_2 ( V_2 , V_76 ) ;
break;
case V_77 :
if ( V_2 -> V_10 -> V_12 -> V_46 != 0x5365 ) {
* V_69 = F_2 ( V_2 , V_78 ) ;
break;
}
default:
* V_69 = F_2 ( V_2 , V_79 ) ;
}
}
void F_30 ( struct V_1 * V_2 ,
unsigned long V_80 )
{
struct V_8 * V_10 = V_2 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_12 ;
T_1 V_13 ;
F_3 ( V_2 , V_81 , 0x11 ) ;
V_13 = F_31 ( 10 , V_80 ) << V_82 ;
V_13 |= F_31 ( 40 , V_80 ) << V_83 ;
V_13 |= F_31 ( 240 , V_80 ) ;
F_3 ( V_2 , V_84 , V_13 ) ;
V_13 = F_31 ( 10 , V_80 ) << V_85 ;
V_13 |= F_31 ( 10 , V_80 ) << V_86 ;
V_13 |= F_31 ( 120 , V_80 ) ;
if ( ( V_12 -> V_46 == 0x5365 ) ||
( V_10 -> V_14 . V_15 < 9 ) )
F_3 ( V_2 , V_87 , V_13 ) ;
if ( ( V_12 -> V_46 == 0x5365 ) ||
( V_10 -> V_14 . V_15 < 9 ) ||
( ( V_12 -> V_46 == 0x5350 ) && ( V_12 -> V_47 == 0 ) ) )
F_3 ( V_2 , V_88 , V_13 ) ;
if ( V_12 -> V_46 == 0x5350 ) {
V_13 = F_31 ( 10 , V_80 ) << V_82 ;
V_13 |= F_31 ( 20 , V_80 ) << V_89 ;
V_13 |= F_31 ( 100 , V_80 ) << V_83 ;
V_13 |= F_31 ( 120 , V_80 ) ;
F_3 ( V_2 , V_84 , V_13 ) ;
}
}
T_1 F_18 ( struct V_1 * V_2 , T_1 V_58 )
{
T_1 V_90 ;
enum V_6 V_91 ;
V_90 = F_15 ( V_2 ) ;
if ( V_2 -> V_18 & V_19 ) {
if ( V_58 == 1 )
V_58 = 2 ;
else if ( V_58 > V_90 )
V_58 = V_90 ;
F_3 ( V_2 , V_92 , V_58 ) ;
} else {
V_91 = V_58 ? V_23 : V_17 ;
F_4 ( V_2 , V_91 ) ;
if ( V_58 > V_90 )
V_58 = V_90 ;
F_3 ( V_2 , V_93 , V_58 ) ;
}
return V_58 ;
}
void F_32 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
F_1 ( V_2 , V_94 , V_4 , V_5 ) ;
}
T_1 F_33 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_2 ( V_2 , V_95 ) & V_4 ;
}
T_1 F_34 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_2 ( V_2 , V_96 ) & V_4 ;
}
T_1 F_35 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
unsigned long V_97 ;
T_1 V_98 = 0 ;
F_36 ( & V_2 -> V_61 , V_97 ) ;
V_98 = F_1 ( V_2 , V_99 , V_4 , V_5 ) ;
F_37 ( & V_2 -> V_61 , V_97 ) ;
return V_98 ;
}
T_1 F_38 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
unsigned long V_97 ;
T_1 V_98 = 0 ;
F_36 ( & V_2 -> V_61 , V_97 ) ;
V_98 = F_1 ( V_2 , V_100 , V_4 , V_5 ) ;
F_37 ( & V_2 -> V_61 , V_97 ) ;
return V_98 ;
}
T_1 F_39 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
unsigned long V_97 ;
T_1 V_98 = 0 ;
F_36 ( & V_2 -> V_61 , V_97 ) ;
V_98 = F_1 ( V_2 , V_101 , V_4 , V_5 ) ;
F_37 ( & V_2 -> V_61 , V_97 ) ;
return V_98 ;
}
T_1 F_40 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
unsigned long V_97 ;
T_1 V_98 = 0 ;
F_36 ( & V_2 -> V_61 , V_97 ) ;
V_98 = F_1 ( V_2 , V_102 , V_4 , V_5 ) ;
F_37 ( & V_2 -> V_61 , V_97 ) ;
return V_98 ;
}
T_1 F_41 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
unsigned long V_97 ;
T_1 V_98 = 0 ;
F_36 ( & V_2 -> V_61 , V_97 ) ;
V_98 = F_1 ( V_2 , V_103 , V_4 , V_5 ) ;
F_37 ( & V_2 -> V_61 , V_97 ) ;
return V_98 ;
}
T_1 F_42 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
unsigned long V_97 ;
T_1 V_98 = 0 ;
if ( V_2 -> V_10 -> V_14 . V_15 < 20 )
return 0xffffffff ;
F_36 ( & V_2 -> V_61 , V_97 ) ;
V_98 = F_1 ( V_2 , V_64 , V_4 , V_5 ) ;
F_37 ( & V_2 -> V_61 , V_97 ) ;
return V_98 ;
}
T_1 F_43 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
unsigned long V_97 ;
T_1 V_98 = 0 ;
if ( V_2 -> V_10 -> V_14 . V_15 < 20 )
return 0xffffffff ;
F_36 ( & V_2 -> V_61 , V_97 ) ;
V_98 = F_1 ( V_2 , V_65 , V_4 , V_5 ) ;
F_37 ( & V_2 -> V_61 , V_97 ) ;
return V_98 ;
}
int F_44 ( struct V_1 * V_2 ,
struct V_104 * V_105 )
{
struct V_11 * V_12 = V_2 -> V_10 -> V_12 ;
int V_106 = 0 ;
T_1 V_67 ;
unsigned int V_107 ;
T_1 V_108 , div ;
T_1 V_109 , V_68 ;
unsigned int V_110 = V_2 -> V_10 -> V_14 . V_15 ;
V_67 = ( V_2 -> V_18 & V_71 ) ;
V_107 = F_45 ( V_2 -> V_10 ) ;
if ( V_67 == V_111 ) {
V_108 = F_46 ( V_67 ,
F_2 ( V_2 , V_70 ) ,
F_2 ( V_2 , V_78 ) ) ;
div = 1 ;
} else {
if ( V_110 == 20 ) {
V_108 = 25000000 ;
div = 48 ;
F_3 ( V_2 , V_112 ,
F_2 ( V_2 , V_112 )
| V_113 ) ;
} else if ( ( V_110 >= 11 ) && ( V_110 != 15 ) ) {
V_108 = F_13 ( V_2 ) ;
div = 1 ;
if ( V_110 >= 21 ) {
F_3 ( V_2 , V_112 ,
F_2 ( V_2 , V_112 )
& ~ V_114 ) ;
}
F_3 ( V_2 , V_112 ,
F_2 ( V_2 , V_112 )
| V_113 ) ;
if ( V_110 >= 21 ) {
F_3 ( V_2 , V_112 ,
F_2 ( V_2 , V_112 )
| V_114 ) ;
}
} else if ( V_110 >= 3 ) {
V_108 = F_21 ( V_12 ) ;
div = F_2 ( V_2 , V_115 )
& V_116 ;
} else {
V_108 = 88000000 ;
div = 48 ;
}
if ( ( V_110 > 0 ) &&
! ( F_2 ( V_2 , V_112 ) & V_113 ) ) {
if ( ( V_2 -> V_18 & V_117 ) ==
V_118 ) {
V_108 /= div ;
} else {
V_108 = 1843200 ;
}
}
}
V_68 = ( V_2 -> V_18 & V_119 ) ;
for ( V_109 = 0 ; V_109 < V_68 ; V_109 ++ ) {
void T_3 * V_120 ;
void T_3 * V_121 ;
V_120 = V_2 -> V_10 -> V_12 -> V_122 + ( V_2 -> V_10 -> V_123 * V_124 ) ;
V_121 = V_120 + V_125 ;
if ( V_110 == 0 )
V_121 += ( V_109 * 8 ) ;
else
V_121 += ( V_109 * 256 ) ;
V_106 ++ ;
V_105 [ V_109 ] . V_126 = V_121 ;
V_105 [ V_109 ] . V_107 = V_107 ;
V_105 [ V_109 ] . V_108 = V_108 ;
V_105 [ V_109 ] . V_127 = 0 ;
}
return V_106 ;
}
