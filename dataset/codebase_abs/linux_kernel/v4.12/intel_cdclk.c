static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = 133333 ;
}
static void F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = 200000 ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = 266667 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = 333333 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = 400000 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = 450000 ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_8 . V_7 ;
T_1 V_9 = 0 ;
if ( V_7 -> V_10 == 0x1 ) {
V_4 -> V_5 = 133333 ;
return;
}
F_8 ( V_7 -> V_11 ,
F_9 ( 0 , 3 ) , V_12 , & V_9 ) ;
switch ( V_9 & V_13 ) {
case V_14 :
case V_15 :
case V_16 :
V_4 -> V_5 = 200000 ;
break;
case V_17 :
V_4 -> V_5 = 250000 ;
break;
case V_18 :
V_4 -> V_5 = 133333 ;
break;
case V_19 :
case V_20 :
case V_21 :
V_4 -> V_5 = 266667 ;
break;
}
}
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_8 . V_7 ;
T_1 V_22 = 0 ;
F_11 ( V_7 , V_23 , & V_22 ) ;
if ( V_22 & V_24 ) {
V_4 -> V_5 = 133333 ;
return;
}
switch ( V_22 & V_25 ) {
case V_26 :
V_4 -> V_5 = 333333 ;
break;
default:
case V_27 :
V_4 -> V_5 = 190000 ;
break;
}
}
static void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_8 . V_7 ;
T_1 V_22 = 0 ;
F_11 ( V_7 , V_23 , & V_22 ) ;
if ( V_22 & V_24 ) {
V_4 -> V_5 = 133333 ;
return;
}
switch ( V_22 & V_25 ) {
case V_26 :
V_4 -> V_5 = 320000 ;
break;
default:
case V_27 :
V_4 -> V_5 = 200000 ;
break;
}
}
static unsigned int F_13 ( struct V_1 * V_2 )
{
static const unsigned int V_28 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
[ 4 ] = 6400000 ,
} ;
static const unsigned int V_29 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
[ 4 ] = 2666667 ,
} ;
static const unsigned int V_30 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 6400000 ,
[ 4 ] = 3333333 ,
[ 5 ] = 3566667 ,
[ 6 ] = 4266667 ,
} ;
static const unsigned int V_31 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
} ;
static const unsigned int V_32 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 6400000 ,
[ 4 ] = 2666667 ,
[ 5 ] = 4266667 ,
} ;
const unsigned int * V_33 ;
unsigned int V_34 ;
T_2 V_35 = 0 ;
if ( F_14 ( V_2 ) )
V_33 = V_32 ;
else if ( F_15 ( V_2 ) )
V_33 = V_31 ;
else if ( F_16 ( V_2 ) )
V_33 = V_30 ;
else if ( F_17 ( V_2 ) )
V_33 = V_29 ;
else if ( F_18 ( V_2 ) )
V_33 = V_28 ;
else
return 0 ;
V_35 = F_19 ( F_20 ( V_2 ) ? V_36 : V_37 ) ;
V_34 = V_33 [ V_35 & 0x7 ] ;
if ( V_34 == 0 )
F_21 ( L_1 , V_35 ) ;
else
F_22 ( L_2 , V_34 ) ;
return V_34 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_8 . V_7 ;
static const T_2 V_38 [] = { 12 , 10 , 8 , 7 , 5 , 16 } ;
static const T_2 V_39 [] = { 14 , 12 , 10 , 8 , 6 , 20 } ;
static const T_2 V_40 [] = { 20 , 14 , 12 , 10 , 8 , 24 } ;
static const T_2 V_41 [] = { 20 , 16 , 12 , 12 , 8 , 28 } ;
const T_2 * V_42 ;
unsigned int V_43 ;
T_3 V_35 = 0 ;
V_4 -> V_34 = F_13 ( V_2 ) ;
F_11 ( V_7 , V_23 , & V_35 ) ;
V_43 = ( V_35 >> 4 ) & 0x7 ;
if ( V_43 >= F_24 ( V_38 ) )
goto V_44;
switch ( V_4 -> V_34 ) {
case 3200000 :
V_42 = V_38 ;
break;
case 4000000 :
V_42 = V_39 ;
break;
case 4800000 :
V_42 = V_40 ;
break;
case 5333333 :
V_42 = V_41 ;
break;
default:
goto V_44;
}
V_4 -> V_5 = F_25 ( V_4 -> V_34 ,
V_42 [ V_43 ] ) ;
return;
V_44:
F_21 ( L_3 ,
V_4 -> V_34 , V_35 ) ;
V_4 -> V_5 = 190476 ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_8 . V_7 ;
T_1 V_22 = 0 ;
F_11 ( V_7 , V_23 , & V_22 ) ;
switch ( V_22 & V_25 ) {
case V_45 :
V_4 -> V_5 = 266667 ;
break;
case V_46 :
V_4 -> V_5 = 333333 ;
break;
case V_47 :
V_4 -> V_5 = 444444 ;
break;
case V_48 :
V_4 -> V_5 = 200000 ;
break;
default:
F_21 ( L_4 , V_22 ) ;
case V_49 :
V_4 -> V_5 = 133333 ;
break;
case V_50 :
V_4 -> V_5 = 166667 ;
break;
}
}
static void F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_8 . V_7 ;
static const T_2 V_38 [] = { 16 , 10 , 8 } ;
static const T_2 V_39 [] = { 20 , 12 , 10 } ;
static const T_2 V_41 [] = { 24 , 16 , 14 } ;
const T_2 * V_42 ;
unsigned int V_43 ;
T_3 V_35 = 0 ;
V_4 -> V_34 = F_13 ( V_2 ) ;
F_11 ( V_7 , V_23 , & V_35 ) ;
V_43 = ( ( V_35 >> 8 ) & 0x1f ) - 1 ;
if ( V_43 >= F_24 ( V_38 ) )
goto V_44;
switch ( V_4 -> V_34 ) {
case 3200000 :
V_42 = V_38 ;
break;
case 4000000 :
V_42 = V_39 ;
break;
case 5333333 :
V_42 = V_41 ;
break;
default:
goto V_44;
}
V_4 -> V_5 = F_25 ( V_4 -> V_34 ,
V_42 [ V_43 ] ) ;
return;
V_44:
F_21 ( L_5 ,
V_4 -> V_34 , V_35 ) ;
V_4 -> V_5 = 200000 ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_8 . V_7 ;
unsigned int V_43 ;
T_3 V_35 = 0 ;
V_4 -> V_34 = F_13 ( V_2 ) ;
F_11 ( V_7 , V_23 , & V_35 ) ;
V_43 = ( V_35 >> 12 ) & 0x1 ;
switch ( V_4 -> V_34 ) {
case 2666667 :
case 4000000 :
case 5333333 :
V_4 -> V_5 = V_43 ? 333333 : 222222 ;
break;
case 3200000 :
V_4 -> V_5 = V_43 ? 320000 : 228571 ;
break;
default:
F_21 ( L_6 ,
V_4 -> V_34 , V_35 ) ;
V_4 -> V_5 = 222222 ;
break;
}
}
static void F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_4 V_51 = F_19 ( V_52 ) ;
T_4 V_53 = V_51 & V_54 ;
if ( V_51 & V_55 )
V_4 -> V_5 = 800000 ;
else if ( F_19 ( V_56 ) & V_57 )
V_4 -> V_5 = 450000 ;
else if ( V_53 == V_58 )
V_4 -> V_5 = 450000 ;
else if ( F_30 ( V_2 ) )
V_4 -> V_5 = 337500 ;
else
V_4 -> V_5 = 540000 ;
}
static int F_31 ( struct V_1 * V_2 ,
int V_59 )
{
int V_60 = ( V_2 -> V_61 << 1 ) % 320000 != 0 ?
333333 : 320000 ;
int V_62 = F_32 ( V_2 ) ? 95 : 90 ;
if ( ! F_32 ( V_2 ) &&
V_59 > V_60 * V_62 / 100 )
return 400000 ;
else if ( V_59 > 266667 * V_62 / 100 )
return V_60 ;
else if ( V_59 > 0 )
return 266667 ;
else
return 200000 ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_34 = F_34 ( V_2 ) ;
V_4 -> V_5 = F_35 ( V_2 , L_7 ,
V_63 ,
V_4 -> V_34 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
unsigned int V_64 , V_65 ;
if ( F_32 ( V_2 ) )
V_65 = F_37 ( 12 ) ;
else
V_65 = F_37 ( 8 ) ;
if ( V_2 -> V_5 . V_66 . V_5 >= V_2 -> V_67 ) {
if ( F_32 ( V_2 ) )
V_64 = V_68 ;
else
V_64 = F_37 ( 15 ) ;
} else {
V_64 = V_65 ;
}
F_38 ( V_69 , V_70 |
V_65 ) ;
F_38 ( V_69 , V_70 |
V_64 | V_71 ) ;
F_39 ( F_19 ( V_69 ) & V_71 ) ;
}
static void F_40 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 = V_4 -> V_5 ;
T_5 V_72 , V_73 ;
if ( V_5 >= 320000 )
V_73 = 2 ;
else if ( V_5 == 266667 )
V_73 = 1 ;
else
V_73 = 0 ;
F_41 ( & V_2 -> V_74 . V_75 ) ;
V_72 = F_42 ( V_2 , V_76 ) ;
V_72 &= ~ V_77 ;
V_72 |= ( V_73 << V_78 ) ;
F_43 ( V_2 , V_76 , V_72 ) ;
if ( F_44 ( ( F_42 ( V_2 , V_76 ) &
V_79 ) == ( V_73 << V_80 ) ,
50 ) ) {
F_21 ( L_8 ) ;
}
F_45 ( & V_2 -> V_74 . V_75 ) ;
F_41 ( & V_2 -> V_81 ) ;
if ( V_5 == 400000 ) {
T_5 V_82 ;
V_82 = F_25 ( V_2 -> V_61 << 1 ,
V_5 ) - 1 ;
V_72 = F_46 ( V_2 , V_63 ) ;
V_72 &= ~ V_83 ;
V_72 |= V_82 ;
F_47 ( V_2 , V_63 , V_72 ) ;
if ( F_44 ( ( F_46 ( V_2 , V_63 ) &
V_84 ) == ( V_82 << V_85 ) ,
50 ) )
F_21 ( L_8 ) ;
}
V_72 = F_48 ( V_2 , V_86 ) ;
V_72 &= ~ 0x7f ;
if ( V_5 == 400000 )
V_72 |= 4500 / 250 ;
else
V_72 |= 3000 / 250 ;
F_49 ( V_2 , V_86 , V_72 ) ;
F_45 ( & V_2 -> V_81 ) ;
F_50 ( V_2 ) ;
F_36 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 = V_4 -> V_5 ;
T_5 V_72 , V_73 ;
switch ( V_5 ) {
case 333333 :
case 320000 :
case 266667 :
case 200000 :
break;
default:
F_52 ( V_5 ) ;
return;
}
V_73 = F_25 ( V_2 -> V_61 << 1 , V_5 ) - 1 ;
F_41 ( & V_2 -> V_74 . V_75 ) ;
V_72 = F_42 ( V_2 , V_76 ) ;
V_72 &= ~ V_87 ;
V_72 |= ( V_73 << V_88 ) ;
F_43 ( V_2 , V_76 , V_72 ) ;
if ( F_44 ( ( F_42 ( V_2 , V_76 ) &
V_89 ) == ( V_73 << V_90 ) ,
50 ) ) {
F_21 ( L_8 ) ;
}
F_45 ( & V_2 -> V_74 . V_75 ) ;
F_50 ( V_2 ) ;
F_36 ( V_2 ) ;
}
static int F_53 ( int V_59 )
{
if ( V_59 > 540000 )
return 675000 ;
else if ( V_59 > 450000 )
return 540000 ;
else if ( V_59 > 337500 )
return 450000 ;
else
return 337500 ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_4 V_51 = F_19 ( V_52 ) ;
T_4 V_53 = V_51 & V_54 ;
if ( V_51 & V_55 )
V_4 -> V_5 = 800000 ;
else if ( F_19 ( V_56 ) & V_57 )
V_4 -> V_5 = 450000 ;
else if ( V_53 == V_58 )
V_4 -> V_5 = 450000 ;
else if ( V_53 == V_91 )
V_4 -> V_5 = 540000 ;
else if ( V_53 == V_92 )
V_4 -> V_5 = 337500 ;
else
V_4 -> V_5 = 675000 ;
}
static void F_55 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 = V_4 -> V_5 ;
T_4 V_72 , V_93 ;
int V_94 ;
if ( F_56 ( ( F_19 ( V_52 ) &
( V_95 | V_96 |
V_97 | V_98 |
V_99 | V_100 |
V_55 ) ) != V_96 ,
L_9 ) )
return;
F_41 ( & V_2 -> V_74 . V_75 ) ;
V_94 = F_57 ( V_2 ,
V_101 , 0x0 ) ;
F_45 ( & V_2 -> V_74 . V_75 ) ;
if ( V_94 ) {
F_21 ( L_10 ) ;
return;
}
V_72 = F_19 ( V_52 ) ;
V_72 |= V_55 ;
F_38 ( V_52 , V_72 ) ;
if ( F_58 ( F_19 ( V_52 ) &
V_102 , 1 ) )
F_21 ( L_11 ) ;
V_72 = F_19 ( V_52 ) ;
V_72 &= ~ V_54 ;
switch ( V_5 ) {
case 450000 :
V_72 |= V_58 ;
V_93 = 0 ;
break;
case 540000 :
V_72 |= V_91 ;
V_93 = 1 ;
break;
case 337500 :
V_72 |= V_92 ;
V_93 = 2 ;
break;
case 675000 :
V_72 |= V_103 ;
V_93 = 3 ;
break;
default:
F_56 ( 1 , L_12 ) ;
return;
}
F_38 ( V_52 , V_72 ) ;
V_72 = F_19 ( V_52 ) ;
V_72 &= ~ V_55 ;
F_38 ( V_52 , V_72 ) ;
if ( F_58 ( ( F_19 ( V_52 ) &
V_102 ) == 0 , 1 ) )
F_21 ( L_13 ) ;
F_41 ( & V_2 -> V_74 . V_75 ) ;
F_57 ( V_2 , V_104 , V_93 ) ;
F_45 ( & V_2 -> V_74 . V_75 ) ;
F_38 ( V_105 , F_25 ( V_5 , 1000 ) - 1 ) ;
F_50 ( V_2 ) ;
F_56 ( V_5 != V_2 -> V_5 . V_66 . V_5 ,
L_14 ,
V_5 , V_2 -> V_5 . V_66 . V_5 ) ;
}
static int F_59 ( int V_59 , int V_34 )
{
if ( V_34 == 8640000 ) {
if ( V_59 > 540000 )
return 617143 ;
else if ( V_59 > 432000 )
return 540000 ;
else if ( V_59 > 308571 )
return 432000 ;
else
return 308571 ;
} else {
if ( V_59 > 540000 )
return 675000 ;
else if ( V_59 > 450000 )
return 540000 ;
else if ( V_59 > 337500 )
return 450000 ;
else
return 337500 ;
}
}
static void F_60 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_5 V_72 ;
V_4 -> V_106 = 24000 ;
V_4 -> V_34 = 0 ;
V_72 = F_19 ( V_107 ) ;
if ( ( V_72 & V_108 ) == 0 )
return;
if ( F_39 ( ( V_72 & V_96 ) == 0 ) )
return;
V_72 = F_19 ( V_109 ) ;
if ( F_39 ( ( V_72 & ( F_61 ( V_110 ) |
F_62 ( V_110 ) |
F_63 ( V_110 ) ) ) !=
F_63 ( V_110 ) ) )
return;
switch ( V_72 & F_64 ( V_110 ) ) {
case F_65 ( V_111 , V_110 ) :
case F_65 ( V_112 , V_110 ) :
case F_65 ( V_113 , V_110 ) :
case F_65 ( V_114 , V_110 ) :
V_4 -> V_34 = 8100000 ;
break;
case F_65 ( V_115 , V_110 ) :
case F_65 ( V_116 , V_110 ) :
V_4 -> V_34 = 8640000 ;
break;
default:
F_52 ( V_72 & F_64 ( V_110 ) ) ;
break;
}
}
static void F_66 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_5 V_117 ;
F_60 ( V_2 , V_4 ) ;
V_4 -> V_5 = V_4 -> V_106 ;
if ( V_4 -> V_34 == 0 )
return;
V_117 = F_19 ( V_118 ) ;
if ( V_4 -> V_34 == 8640000 ) {
switch ( V_117 & V_119 ) {
case V_120 :
V_4 -> V_5 = 432000 ;
break;
case V_121 :
V_4 -> V_5 = 308571 ;
break;
case V_122 :
V_4 -> V_5 = 540000 ;
break;
case V_123 :
V_4 -> V_5 = 617143 ;
break;
default:
F_52 ( V_117 & V_119 ) ;
break;
}
} else {
switch ( V_117 & V_119 ) {
case V_120 :
V_4 -> V_5 = 450000 ;
break;
case V_121 :
V_4 -> V_5 = 337500 ;
break;
case V_122 :
V_4 -> V_5 = 540000 ;
break;
case V_123 :
V_4 -> V_5 = 675000 ;
break;
default:
F_52 ( V_117 & V_119 ) ;
break;
}
}
}
static int F_67 ( int V_5 )
{
return F_25 ( V_5 - 1000 , 500 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
int V_34 )
{
bool V_124 = V_2 -> V_125 != V_34 ;
V_2 -> V_125 = V_34 ;
if ( V_124 )
F_69 ( V_2 ) ;
}
static void F_70 ( struct V_1 * V_2 , int V_34 )
{
int V_126 = F_59 ( 0 , V_34 ) ;
T_5 V_72 ;
F_39 ( V_34 != 8100000 && V_34 != 8640000 ) ;
V_72 = V_121 | F_67 ( V_126 ) ;
F_38 ( V_118 , V_72 ) ;
F_71 ( V_118 ) ;
V_72 = F_19 ( V_109 ) ;
V_72 &= ~ ( F_61 ( V_110 ) | F_62 ( V_110 ) |
F_64 ( V_110 ) ) ;
V_72 |= F_63 ( V_110 ) ;
if ( V_34 == 8640000 )
V_72 |= F_65 ( V_115 ,
V_110 ) ;
else
V_72 |= F_65 ( V_111 ,
V_110 ) ;
F_38 ( V_109 , V_72 ) ;
F_71 ( V_109 ) ;
F_38 ( V_107 , F_19 ( V_107 ) | V_108 ) ;
if ( F_72 ( V_2 ,
V_107 , V_96 , V_96 ,
5 ) )
F_21 ( L_15 ) ;
V_2 -> V_5 . V_66 . V_34 = V_34 ;
F_68 ( V_2 , V_34 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
F_38 ( V_107 , F_19 ( V_107 ) & ~ V_108 ) ;
if ( F_72 ( V_2 ,
V_107 , V_96 , 0 ,
1 ) )
F_21 ( L_16 ) ;
V_2 -> V_5 . V_66 . V_34 = 0 ;
}
static void F_74 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 = V_4 -> V_5 ;
int V_34 = V_4 -> V_34 ;
T_5 V_127 , V_128 ;
int V_94 ;
F_39 ( ( V_5 == 24000 ) != ( V_34 == 0 ) ) ;
F_41 ( & V_2 -> V_74 . V_75 ) ;
V_94 = F_75 ( V_2 , V_129 ,
V_130 ,
V_131 ,
V_131 , 3 ) ;
F_45 ( & V_2 -> V_74 . V_75 ) ;
if ( V_94 ) {
F_21 ( L_17 ,
V_94 ) ;
return;
}
switch ( V_5 ) {
case 450000 :
case 432000 :
V_127 = V_120 ;
V_128 = 1 ;
break;
case 540000 :
V_127 = V_122 ;
V_128 = 2 ;
break;
case 308571 :
case 337500 :
default:
V_127 = V_121 ;
V_128 = 0 ;
break;
case 617143 :
case 675000 :
V_127 = V_123 ;
V_128 = 3 ;
break;
}
if ( V_2 -> V_5 . V_66 . V_34 != 0 &&
V_2 -> V_5 . V_66 . V_34 != V_34 )
F_73 ( V_2 ) ;
if ( V_2 -> V_5 . V_66 . V_34 != V_34 )
F_70 ( V_2 , V_34 ) ;
F_38 ( V_118 , V_127 | F_67 ( V_5 ) ) ;
F_71 ( V_118 ) ;
F_41 ( & V_2 -> V_74 . V_75 ) ;
F_57 ( V_2 , V_129 , V_128 ) ;
F_45 ( & V_2 -> V_74 . V_75 ) ;
F_50 ( V_2 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
T_4 V_117 , V_132 ;
if ( ( F_19 ( F_77 ( 0x18 ) ) & 0x00FFFFFF ) == 0 )
goto V_133;
F_50 ( V_2 ) ;
if ( V_2 -> V_5 . V_66 . V_34 == 0 ||
V_2 -> V_5 . V_66 . V_5 == V_2 -> V_5 . V_66 . V_106 )
goto V_133;
V_117 = F_19 ( V_118 ) ;
V_132 = ( V_117 & V_119 ) |
F_67 ( V_2 -> V_5 . V_66 . V_5 ) ;
if ( V_117 == V_132 )
return;
V_133:
F_22 ( L_18 ) ;
V_2 -> V_5 . V_66 . V_5 = 0 ;
V_2 -> V_5 . V_66 . V_34 = - 1 ;
}
void F_78 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_76 ( V_2 ) ;
if ( V_2 -> V_5 . V_66 . V_5 != 0 &&
V_2 -> V_5 . V_66 . V_34 != 0 ) {
if ( V_2 -> V_125 == 0 )
F_68 ( V_2 ,
V_2 -> V_5 . V_66 . V_34 ) ;
return;
}
V_4 = V_2 -> V_5 . V_66 ;
V_4 . V_34 = V_2 -> V_125 ;
if ( V_4 . V_34 == 0 )
V_4 . V_34 = 8100000 ;
V_4 . V_5 = F_59 ( 0 , V_4 . V_34 ) ;
F_74 ( V_2 , & V_4 ) ;
}
void F_79 ( struct V_1 * V_2 )
{
struct V_3 V_4 = V_2 -> V_5 . V_66 ;
V_4 . V_5 = V_4 . V_106 ;
V_4 . V_34 = 0 ;
F_74 ( V_2 , & V_4 ) ;
}
static int F_80 ( int V_59 )
{
if ( V_59 > 576000 )
return 624000 ;
else if ( V_59 > 384000 )
return 576000 ;
else if ( V_59 > 288000 )
return 384000 ;
else if ( V_59 > 144000 )
return 288000 ;
else
return 144000 ;
}
static int F_81 ( int V_59 )
{
if ( V_59 > 2 * 158400 )
return 316800 ;
else if ( V_59 > 2 * 79200 )
return 158400 ;
else
return 79200 ;
}
static int F_82 ( struct V_1 * V_2 , int V_5 )
{
int V_134 ;
if ( V_5 == V_2 -> V_5 . V_66 . V_106 )
return 0 ;
switch ( V_5 ) {
default:
F_52 ( V_5 ) ;
case 144000 :
case 288000 :
case 384000 :
case 576000 :
V_134 = 60 ;
break;
case 624000 :
V_134 = 65 ;
break;
}
return V_2 -> V_5 . V_66 . V_106 * V_134 ;
}
static int F_83 ( struct V_1 * V_2 , int V_5 )
{
int V_134 ;
if ( V_5 == V_2 -> V_5 . V_66 . V_106 )
return 0 ;
switch ( V_5 ) {
default:
F_52 ( V_5 ) ;
case 79200 :
case 158400 :
case 316800 :
V_134 = 33 ;
break;
}
return V_2 -> V_5 . V_66 . V_106 * V_134 ;
}
static void F_84 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_5 V_72 ;
V_4 -> V_106 = 19200 ;
V_4 -> V_34 = 0 ;
V_72 = F_19 ( V_135 ) ;
if ( ( V_72 & V_136 ) == 0 )
return;
if ( F_39 ( ( V_72 & V_137 ) == 0 ) )
return;
V_72 = F_19 ( V_138 ) ;
V_4 -> V_34 = ( V_72 & V_139 ) * V_4 -> V_106 ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_5 V_82 ;
int div ;
F_84 ( V_2 , V_4 ) ;
V_4 -> V_5 = V_4 -> V_106 ;
if ( V_4 -> V_34 == 0 )
return;
V_82 = F_19 ( V_118 ) & V_140 ;
switch ( V_82 ) {
case V_141 :
div = 2 ;
break;
case V_142 :
F_56 ( F_86 ( V_2 ) , L_19 ) ;
div = 3 ;
break;
case V_143 :
div = 4 ;
break;
case V_144 :
div = 8 ;
break;
default:
F_52 ( V_82 ) ;
return;
}
V_4 -> V_5 = F_25 ( V_4 -> V_34 , div ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
F_38 ( V_135 , 0 ) ;
if ( F_72 ( V_2 ,
V_135 , V_137 , 0 ,
1 ) )
F_21 ( L_20 ) ;
V_2 -> V_5 . V_66 . V_34 = 0 ;
}
static void F_88 ( struct V_1 * V_2 , int V_34 )
{
int V_134 = F_25 ( V_34 , V_2 -> V_5 . V_66 . V_106 ) ;
T_5 V_72 ;
V_72 = F_19 ( V_138 ) ;
V_72 &= ~ V_139 ;
V_72 |= F_89 ( V_134 ) ;
F_38 ( V_138 , V_72 ) ;
F_38 ( V_135 , V_136 ) ;
if ( F_72 ( V_2 ,
V_135 ,
V_137 ,
V_137 ,
1 ) )
F_21 ( L_21 ) ;
V_2 -> V_5 . V_66 . V_34 = V_34 ;
}
static void F_90 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 = V_4 -> V_5 ;
int V_34 = V_4 -> V_34 ;
T_5 V_72 , V_82 ;
int V_94 ;
switch ( F_25 ( V_34 , V_5 ) ) {
case 8 :
V_82 = V_144 ;
break;
case 4 :
V_82 = V_143 ;
break;
case 3 :
F_56 ( F_86 ( V_2 ) , L_19 ) ;
V_82 = V_142 ;
break;
case 2 :
V_82 = V_141 ;
break;
default:
F_39 ( V_5 != V_2 -> V_5 . V_66 . V_106 ) ;
F_39 ( V_34 != 0 ) ;
V_82 = V_141 ;
break;
}
F_41 ( & V_2 -> V_74 . V_75 ) ;
V_94 = F_57 ( V_2 , V_104 ,
0x80000000 ) ;
F_45 ( & V_2 -> V_74 . V_75 ) ;
if ( V_94 ) {
F_21 ( L_22 ,
V_94 , V_5 ) ;
return;
}
if ( V_2 -> V_5 . V_66 . V_34 != 0 &&
V_2 -> V_5 . V_66 . V_34 != V_34 )
F_87 ( V_2 ) ;
if ( V_2 -> V_5 . V_66 . V_34 != V_34 )
F_88 ( V_2 , V_34 ) ;
V_72 = V_82 | F_67 ( V_5 ) ;
V_72 |= V_145 ;
if ( V_5 >= 500000 )
V_72 |= V_146 ;
F_38 ( V_118 , V_72 ) ;
F_41 ( & V_2 -> V_74 . V_75 ) ;
V_94 = F_57 ( V_2 , V_104 ,
F_91 ( V_5 , 25000 ) ) ;
F_45 ( & V_2 -> V_74 . V_75 ) ;
if ( V_94 ) {
F_21 ( L_23 ,
V_94 , V_5 ) ;
return;
}
F_50 ( V_2 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
T_5 V_117 , V_132 ;
F_50 ( V_2 ) ;
if ( V_2 -> V_5 . V_66 . V_34 == 0 ||
V_2 -> V_5 . V_66 . V_5 == V_2 -> V_5 . V_66 . V_106 )
goto V_133;
V_117 = F_19 ( V_118 ) ;
V_117 &= ~ V_145 ;
V_132 = ( V_117 & V_140 ) |
F_67 ( V_2 -> V_5 . V_66 . V_5 ) ;
if ( V_2 -> V_5 . V_66 . V_5 >= 500000 )
V_132 |= V_146 ;
if ( V_117 == V_132 )
return;
V_133:
F_22 ( L_18 ) ;
V_2 -> V_5 . V_66 . V_5 = 0 ;
V_2 -> V_5 . V_66 . V_34 = - 1 ;
}
void F_93 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_92 ( V_2 ) ;
if ( V_2 -> V_5 . V_66 . V_5 != 0 &&
V_2 -> V_5 . V_66 . V_34 != 0 )
return;
V_4 = V_2 -> V_5 . V_66 ;
if ( F_86 ( V_2 ) ) {
V_4 . V_5 = F_81 ( 0 ) ;
V_4 . V_34 = F_83 ( V_2 , V_4 . V_5 ) ;
} else {
V_4 . V_5 = F_80 ( 0 ) ;
V_4 . V_34 = F_82 ( V_2 , V_4 . V_5 ) ;
}
F_90 ( V_2 , & V_4 ) ;
}
void F_94 ( struct V_1 * V_2 )
{
struct V_3 V_4 = V_2 -> V_5 . V_66 ;
V_4 . V_5 = V_4 . V_106 ;
V_4 . V_34 = 0 ;
F_90 ( V_2 , & V_4 ) ;
}
bool F_95 ( const struct V_3 * V_147 ,
const struct V_3 * V_148 )
{
return memcmp ( V_147 , V_148 , sizeof( * V_147 ) ) == 0 ;
}
void F_96 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( F_95 ( & V_2 -> V_5 . V_66 , V_4 ) )
return;
if ( F_97 ( ! V_2 -> V_149 . V_150 ) )
return;
F_98 ( L_24 ,
V_4 -> V_5 , V_4 -> V_34 ,
V_4 -> V_106 ) ;
V_2 -> V_149 . V_150 ( V_2 , V_4 ) ;
}
static int F_99 ( struct V_151 * V_152 ,
int V_153 )
{
struct V_1 * V_2 =
F_100 ( V_152 -> V_154 . V_155 -> V_156 ) ;
if ( F_101 ( V_2 ) && V_152 -> V_157 )
V_153 = F_91 ( V_153 * 100 , 95 ) ;
if ( F_102 ( V_152 ) &&
V_152 -> V_158 &&
V_152 -> V_159 >= 540000 &&
V_152 -> V_160 == 4 ) {
if ( F_86 ( V_2 ) )
V_153 = F_103 ( 2 * 316800 , V_153 ) ;
else
V_153 = F_103 ( 432000 , V_153 ) ;
}
if ( V_152 -> V_158 && F_104 ( V_2 ) >= 9 ) {
if ( F_86 ( V_2 ) )
V_153 = F_103 ( 2 * 2 * 96000 , V_153 ) ;
else
V_153 = F_103 ( 2 * 96000 , V_153 ) ;
}
return V_153 ;
}
static int F_105 ( struct V_161 * V_162 )
{
struct V_163 * V_164 = F_106 ( V_162 ) ;
struct V_1 * V_2 = F_100 ( V_162 -> V_156 ) ;
struct V_165 * V_155 ;
struct V_166 * V_167 ;
struct V_151 * V_152 ;
unsigned int V_168 = 0 , V_169 ;
enum V_170 V_170 ;
memcpy ( V_164 -> V_171 , V_2 -> V_171 ,
sizeof( V_164 -> V_171 ) ) ;
F_107 (state, crtc, cstate, i) {
int V_153 ;
V_152 = F_108 ( V_167 ) ;
if ( ! V_152 -> V_154 . V_172 ) {
V_164 -> V_171 [ V_169 ] = 0 ;
continue;
}
V_153 = V_152 -> V_153 ;
if ( F_101 ( V_2 ) || F_109 ( V_2 ) )
V_153 =
F_99 ( V_152 ,
V_153 ) ;
V_164 -> V_171 [ V_169 ] = V_153 ;
}
F_110 (dev_priv, pipe)
V_168 = F_103 ( V_164 -> V_171 [ V_170 ] ,
V_168 ) ;
return V_168 ;
}
static int F_111 ( struct V_161 * V_162 )
{
struct V_1 * V_2 = F_100 ( V_162 -> V_156 ) ;
int V_59 = F_105 ( V_162 ) ;
struct V_163 * V_164 =
F_106 ( V_162 ) ;
int V_5 ;
V_5 = F_31 ( V_2 , V_59 ) ;
if ( V_5 > V_2 -> V_173 ) {
F_22 ( L_25 ,
V_5 , V_2 -> V_173 ) ;
return - V_174 ;
}
V_164 -> V_5 . V_175 . V_5 = V_5 ;
if ( ! V_164 -> V_176 ) {
V_5 = F_31 ( V_2 , 0 ) ;
V_164 -> V_5 . V_177 . V_5 = V_5 ;
} else {
V_164 -> V_5 . V_177 =
V_164 -> V_5 . V_175 ;
}
return 0 ;
}
static int F_112 ( struct V_161 * V_162 )
{
struct V_1 * V_2 = F_100 ( V_162 -> V_156 ) ;
struct V_163 * V_164 = F_106 ( V_162 ) ;
int V_59 = F_105 ( V_162 ) ;
int V_5 ;
V_5 = F_53 ( V_59 ) ;
if ( V_5 > V_2 -> V_173 ) {
F_22 ( L_25 ,
V_5 , V_2 -> V_173 ) ;
return - V_174 ;
}
V_164 -> V_5 . V_175 . V_5 = V_5 ;
if ( ! V_164 -> V_176 ) {
V_5 = F_53 ( 0 ) ;
V_164 -> V_5 . V_177 . V_5 = V_5 ;
} else {
V_164 -> V_5 . V_177 =
V_164 -> V_5 . V_175 ;
}
return 0 ;
}
static int F_113 ( struct V_161 * V_162 )
{
struct V_163 * V_164 = F_106 ( V_162 ) ;
struct V_1 * V_2 = F_100 ( V_162 -> V_156 ) ;
const int V_59 = F_105 ( V_162 ) ;
int V_5 , V_34 ;
V_34 = V_164 -> V_5 . V_175 . V_34 ;
if ( ! V_34 )
V_34 = V_2 -> V_125 ;
V_5 = F_59 ( V_59 , V_34 ) ;
if ( V_5 > V_2 -> V_173 ) {
F_22 ( L_25 ,
V_5 , V_2 -> V_173 ) ;
return - V_174 ;
}
V_164 -> V_5 . V_175 . V_34 = V_34 ;
V_164 -> V_5 . V_175 . V_5 = V_5 ;
if ( ! V_164 -> V_176 ) {
V_5 = F_59 ( 0 , V_34 ) ;
V_164 -> V_5 . V_177 . V_34 = V_34 ;
V_164 -> V_5 . V_177 . V_5 = V_5 ;
} else {
V_164 -> V_5 . V_177 =
V_164 -> V_5 . V_175 ;
}
return 0 ;
}
static int F_114 ( struct V_161 * V_162 )
{
struct V_1 * V_2 = F_100 ( V_162 -> V_156 ) ;
int V_59 = F_105 ( V_162 ) ;
struct V_163 * V_164 =
F_106 ( V_162 ) ;
int V_5 , V_34 ;
if ( F_86 ( V_2 ) ) {
V_5 = F_81 ( V_59 ) ;
V_34 = F_83 ( V_2 , V_5 ) ;
} else {
V_5 = F_80 ( V_59 ) ;
V_34 = F_82 ( V_2 , V_5 ) ;
}
if ( V_5 > V_2 -> V_173 ) {
F_22 ( L_25 ,
V_5 , V_2 -> V_173 ) ;
return - V_174 ;
}
V_164 -> V_5 . V_175 . V_34 = V_34 ;
V_164 -> V_5 . V_175 . V_5 = V_5 ;
if ( ! V_164 -> V_176 ) {
if ( F_86 ( V_2 ) ) {
V_5 = F_81 ( 0 ) ;
V_34 = F_83 ( V_2 , V_5 ) ;
} else {
V_5 = F_80 ( 0 ) ;
V_34 = F_82 ( V_2 , V_5 ) ;
}
V_164 -> V_5 . V_177 . V_34 = V_34 ;
V_164 -> V_5 . V_177 . V_5 = V_5 ;
} else {
V_164 -> V_5 . V_177 =
V_164 -> V_5 . V_175 ;
}
return 0 ;
}
static int F_115 ( struct V_1 * V_2 )
{
int V_173 = V_2 -> V_173 ;
if ( F_86 ( V_2 ) )
return 2 * V_173 ;
else if ( F_116 ( V_2 ) -> V_178 >= 9 ||
F_117 ( V_2 ) || F_101 ( V_2 ) )
return V_173 ;
else if ( F_32 ( V_2 ) )
return V_173 * 95 / 100 ;
else if ( F_116 ( V_2 ) -> V_178 < 4 )
return 2 * V_173 * 90 / 100 ;
else
return V_173 * 90 / 100 ;
}
void F_69 ( struct V_1 * V_2 )
{
if ( F_118 ( V_2 ) ) {
T_5 V_62 = F_19 ( V_179 ) & V_180 ;
int V_181 , V_34 ;
V_34 = V_2 -> V_125 ;
F_39 ( V_34 != 8100000 && V_34 != 8640000 ) ;
if ( V_62 == V_182 )
V_181 = 617143 ;
else if ( V_62 == V_183 )
V_181 = 540000 ;
else if ( V_62 == V_184 )
V_181 = 432000 ;
else
V_181 = 308571 ;
V_2 -> V_173 = F_59 ( V_181 , V_34 ) ;
} else if ( F_86 ( V_2 ) ) {
V_2 -> V_173 = 316800 ;
} else if ( F_119 ( V_2 ) ) {
V_2 -> V_173 = 624000 ;
} else if ( F_101 ( V_2 ) ) {
if ( F_19 ( V_56 ) & V_57 )
V_2 -> V_173 = 450000 ;
else if ( F_120 ( V_2 ) )
V_2 -> V_173 = 450000 ;
else if ( F_121 ( V_2 ) )
V_2 -> V_173 = 540000 ;
else
V_2 -> V_173 = 675000 ;
} else if ( F_32 ( V_2 ) ) {
V_2 -> V_173 = 320000 ;
} else if ( F_122 ( V_2 ) ) {
V_2 -> V_173 = 400000 ;
} else {
V_2 -> V_173 = V_2 -> V_5 . V_66 . V_5 ;
}
V_2 -> V_185 = F_115 ( V_2 ) ;
F_98 ( L_26 ,
V_2 -> V_173 ) ;
F_98 ( L_27 ,
V_2 -> V_185 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
V_2 -> V_149 . V_186 ( V_2 , & V_2 -> V_5 . V_66 ) ;
F_98 ( L_28 ,
V_2 -> V_5 . V_66 . V_5 , V_2 -> V_5 . V_66 . V_34 ,
V_2 -> V_5 . V_66 . V_106 ) ;
if ( F_122 ( V_2 ) || F_32 ( V_2 ) )
F_38 ( V_187 ,
F_91 ( V_2 -> V_5 . V_66 . V_5 , 1000 ) ) ;
}
static int F_123 ( struct V_1 * V_2 )
{
return ( F_19 ( V_188 ) & V_189 ) * 1000 ;
}
static int F_124 ( struct V_1 * V_2 )
{
return F_125 ( V_2 , L_29 ,
V_190 ) ;
}
static int F_126 ( struct V_1 * V_2 )
{
T_4 V_191 ;
V_191 = F_19 ( V_192 ) ;
switch ( V_191 & V_193 ) {
case V_194 :
return 100000 ;
case V_195 :
return 133333 ;
case V_196 :
return 166667 ;
case V_197 :
return 200000 ;
case V_198 :
case V_199 :
return 266667 ;
case V_200 :
case V_201 :
return 333333 ;
default:
return 133333 ;
}
}
void F_127 ( struct V_1 * V_2 )
{
if ( F_128 ( V_2 ) )
V_2 -> V_202 = F_123 ( V_2 ) ;
else if ( F_122 ( V_2 ) || F_32 ( V_2 ) )
V_2 -> V_202 = F_124 ( V_2 ) ;
else if ( F_129 ( V_2 ) || F_17 ( V_2 ) )
V_2 -> V_202 = F_126 ( V_2 ) ;
else
return;
F_98 ( L_30 , V_2 -> V_202 ) ;
}
void F_130 ( struct V_1 * V_2 )
{
if ( F_32 ( V_2 ) ) {
V_2 -> V_149 . V_150 = F_51 ;
V_2 -> V_149 . V_203 =
F_111 ;
} else if ( F_122 ( V_2 ) ) {
V_2 -> V_149 . V_150 = F_40 ;
V_2 -> V_149 . V_203 =
F_111 ;
} else if ( F_101 ( V_2 ) ) {
V_2 -> V_149 . V_150 = F_55 ;
V_2 -> V_149 . V_203 =
F_112 ;
} else if ( F_131 ( V_2 ) ) {
V_2 -> V_149 . V_150 = F_90 ;
V_2 -> V_149 . V_203 =
F_114 ;
} else if ( F_118 ( V_2 ) ) {
V_2 -> V_149 . V_150 = F_74 ;
V_2 -> V_149 . V_203 =
F_113 ;
}
if ( F_118 ( V_2 ) )
V_2 -> V_149 . V_186 = F_66 ;
else if ( F_131 ( V_2 ) )
V_2 -> V_149 . V_186 = F_85 ;
else if ( F_101 ( V_2 ) )
V_2 -> V_149 . V_186 = F_54 ;
else if ( F_117 ( V_2 ) )
V_2 -> V_149 . V_186 = F_29 ;
else if ( F_122 ( V_2 ) || F_32 ( V_2 ) )
V_2 -> V_149 . V_186 = F_33 ;
else if ( F_132 ( V_2 ) || F_133 ( V_2 ) )
V_2 -> V_149 . V_186 = F_5 ;
else if ( F_134 ( V_2 ) )
V_2 -> V_149 . V_186 = F_6 ;
else if ( F_14 ( V_2 ) )
V_2 -> V_149 . V_186 = F_28 ;
else if ( F_15 ( V_2 ) )
V_2 -> V_149 . V_186 = F_23 ;
else if ( F_16 ( V_2 ) )
V_2 -> V_149 . V_186 = F_27 ;
else if ( F_135 ( V_2 ) )
V_2 -> V_149 . V_186 = F_5 ;
else if ( F_17 ( V_2 ) )
V_2 -> V_149 . V_186 = F_26 ;
else if ( F_18 ( V_2 ) )
V_2 -> V_149 . V_186 = F_23 ;
else if ( F_136 ( V_2 ) )
V_2 -> V_149 . V_186 = F_12 ;
else if ( F_137 ( V_2 ) )
V_2 -> V_149 . V_186 = F_5 ;
else if ( F_138 ( V_2 ) )
V_2 -> V_149 . V_186 = F_10 ;
else if ( F_139 ( V_2 ) )
V_2 -> V_149 . V_186 = F_4 ;
else if ( F_140 ( V_2 ) )
V_2 -> V_149 . V_186 = F_3 ;
else if ( F_141 ( V_2 ) )
V_2 -> V_149 . V_186 = F_7 ;
else if ( F_142 ( V_2 ) )
V_2 -> V_149 . V_186 = F_2 ;
else {
F_56 ( ! F_143 ( V_2 ) ,
L_31 ) ;
V_2 -> V_149 . V_186 = F_1 ;
}
}
