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
void F_13 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_10 )
return;
if ( V_2 -> V_10 -> V_14 . V_15 >= 11 )
V_2 -> V_55 = F_2 ( V_2 , V_56 ) ;
F_14 (KERN_INFO PFX L_1 , cc->status) ;
if ( V_2 -> V_10 -> V_14 . V_15 >= 20 ) {
F_3 ( V_2 , V_57 , 0 ) ;
F_3 ( V_2 , V_58 , 0 ) ;
}
F_15 ( V_2 ) ;
F_10 ( V_2 ) ;
F_4 ( V_2 , V_23 ) ;
F_12 ( V_2 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_10 )
return;
F_4 ( V_2 , V_16 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_10 )
return;
F_10 ( V_2 ) ;
F_4 ( V_2 , V_23 ) ;
}
void F_18 ( struct V_1 * V_2 ,
T_1 * V_59 , T_1 * V_60 , T_1 * V_61 )
{
* V_60 = F_2 ( V_2 , V_62 ) ;
* V_59 = ( V_2 -> V_18 & V_63 ) ;
switch ( * V_59 ) {
case V_64 :
case V_65 :
case V_66 :
case V_67 :
* V_61 = F_2 ( V_2 , V_68 ) ;
break;
case V_69 :
* V_61 = F_2 ( V_2 , V_70 ) ;
break;
default:
* V_61 = F_2 ( V_2 , V_71 ) ;
break;
}
}
void F_19 ( struct V_1 * V_2 ,
T_1 * V_59 , T_1 * V_60 , T_1 * V_61 )
{
* V_60 = F_2 ( V_2 , V_62 ) ;
* V_59 = ( V_2 -> V_18 & V_63 ) ;
switch ( * V_59 ) {
case V_66 :
* V_61 = F_2 ( V_2 , V_68 ) ;
break;
case V_69 :
if ( V_2 -> V_10 -> V_12 -> V_46 != 0x5365 ) {
* V_61 = F_2 ( V_2 , V_70 ) ;
break;
}
default:
* V_61 = F_2 ( V_2 , V_71 ) ;
}
}
void F_20 ( struct V_1 * V_2 ,
unsigned long V_72 )
{
struct V_8 * V_10 = V_2 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_12 ;
T_1 V_13 ;
F_3 ( V_2 , V_73 , 0x11 ) ;
V_13 = F_21 ( 10 , V_72 ) << V_74 ;
V_13 |= F_21 ( 40 , V_72 ) << V_75 ;
V_13 |= F_21 ( 240 , V_72 ) ;
F_3 ( V_2 , V_76 , V_13 ) ;
V_13 = F_21 ( 10 , V_72 ) << V_77 ;
V_13 |= F_21 ( 10 , V_72 ) << V_78 ;
V_13 |= F_21 ( 120 , V_72 ) ;
if ( ( V_12 -> V_46 == 0x5365 ) ||
( V_10 -> V_14 . V_15 < 9 ) )
F_3 ( V_2 , V_79 , V_13 ) ;
if ( ( V_12 -> V_46 == 0x5365 ) ||
( V_10 -> V_14 . V_15 < 9 ) ||
( ( V_12 -> V_46 == 0x5350 ) && ( V_12 -> V_47 == 0 ) ) )
F_3 ( V_2 , V_80 , V_13 ) ;
if ( V_12 -> V_46 == 0x5350 ) {
V_13 = F_21 ( 10 , V_72 ) << V_74 ;
V_13 |= F_21 ( 20 , V_72 ) << V_81 ;
V_13 |= F_21 ( 100 , V_72 ) << V_75 ;
V_13 |= F_21 ( 120 , V_72 ) ;
F_3 ( V_2 , V_76 , V_13 ) ;
}
}
void F_22 ( struct V_1 * V_2 , T_1 V_82 )
{
F_3 ( V_2 , V_83 , V_82 ) ;
}
void F_23 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
F_1 ( V_2 , V_84 , V_4 , V_5 ) ;
}
T_1 F_24 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_2 ( V_2 , V_85 ) & V_4 ;
}
T_1 F_25 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_2 ( V_2 , V_86 ) & V_4 ;
}
T_1 F_26 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
return F_1 ( V_2 , V_87 , V_4 , V_5 ) ;
}
T_1 F_27 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
return F_1 ( V_2 , V_88 , V_4 , V_5 ) ;
}
T_1 F_28 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
return F_1 ( V_2 , V_89 , V_4 , V_5 ) ;
}
T_1 F_29 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
return F_1 ( V_2 , V_90 , V_4 , V_5 ) ;
}
T_1 F_30 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
return F_1 ( V_2 , V_91 , V_4 , V_5 ) ;
}
int F_31 ( struct V_1 * V_2 ,
struct V_92 * V_93 )
{
struct V_11 * V_12 = V_2 -> V_10 -> V_12 ;
int V_94 = 0 ;
T_1 V_59 ;
unsigned int V_95 ;
T_1 V_96 , div ;
T_1 V_97 , V_60 ;
unsigned int V_98 = V_2 -> V_10 -> V_14 . V_15 ;
V_59 = ( V_2 -> V_18 & V_63 ) ;
V_95 = F_32 ( V_2 -> V_10 ) ;
if ( V_59 == V_99 ) {
V_96 = F_33 ( V_59 ,
F_2 ( V_2 , V_62 ) ,
F_2 ( V_2 , V_70 ) ) ;
div = 1 ;
} else {
if ( V_98 == 20 ) {
V_96 = 25000000 ;
div = 48 ;
F_3 ( V_2 , V_100 ,
F_2 ( V_2 , V_100 )
| V_101 ) ;
} else if ( ( V_98 >= 11 ) && ( V_98 != 15 ) ) {
V_96 = 20000000 ;
if ( V_2 -> V_18 & V_19 ) {
F_5 ( 1 ) ;
}
div = 1 ;
if ( V_98 >= 21 ) {
F_3 ( V_2 , V_100 ,
F_2 ( V_2 , V_100 )
& ~ V_102 ) ;
}
F_3 ( V_2 , V_100 ,
F_2 ( V_2 , V_100 )
| V_101 ) ;
if ( V_98 >= 21 ) {
F_3 ( V_2 , V_100 ,
F_2 ( V_2 , V_100 )
| V_102 ) ;
}
} else if ( V_98 >= 3 ) {
V_96 = F_34 ( V_12 ) ;
div = F_2 ( V_2 , V_103 )
& V_104 ;
} else {
V_96 = 88000000 ;
div = 48 ;
}
if ( ( V_98 > 0 ) &&
! ( F_2 ( V_2 , V_100 ) & V_101 ) ) {
if ( ( V_2 -> V_18 & V_105 ) ==
V_106 ) {
V_96 /= div ;
} else {
V_96 = 1843200 ;
}
}
}
V_60 = ( V_2 -> V_18 & V_107 ) ;
for ( V_97 = 0 ; V_97 < V_60 ; V_97 ++ ) {
void T_3 * V_108 ;
void T_3 * V_109 ;
V_108 = V_2 -> V_10 -> V_12 -> V_110 + ( V_2 -> V_10 -> V_111 * V_112 ) ;
V_109 = V_108 + V_113 ;
if ( V_98 == 0 )
V_109 += ( V_97 * 8 ) ;
else
V_109 += ( V_97 * 256 ) ;
V_94 ++ ;
V_93 [ V_97 ] . V_114 = V_109 ;
V_93 [ V_97 ] . V_95 = V_95 ;
V_93 [ V_97 ] . V_96 = V_96 ;
V_93 [ V_97 ] . V_115 = 0 ;
}
return V_94 ;
}
