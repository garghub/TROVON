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
F_41 ( V_2 , V_74 ) ;
if ( V_5 >= 320000 )
V_73 = 2 ;
else if ( V_5 == 266667 )
V_73 = 1 ;
else
V_73 = 0 ;
F_42 ( & V_2 -> V_75 . V_76 ) ;
V_72 = F_43 ( V_2 , V_77 ) ;
V_72 &= ~ V_78 ;
V_72 |= ( V_73 << V_79 ) ;
F_44 ( V_2 , V_77 , V_72 ) ;
if ( F_45 ( ( F_43 ( V_2 , V_77 ) &
V_80 ) == ( V_73 << V_81 ) ,
50 ) ) {
F_21 ( L_8 ) ;
}
F_46 ( & V_2 -> V_75 . V_76 ) ;
F_42 ( & V_2 -> V_82 ) ;
if ( V_5 == 400000 ) {
T_5 V_83 ;
V_83 = F_25 ( V_2 -> V_61 << 1 ,
V_5 ) - 1 ;
V_72 = F_47 ( V_2 , V_63 ) ;
V_72 &= ~ V_84 ;
V_72 |= V_83 ;
F_48 ( V_2 , V_63 , V_72 ) ;
if ( F_45 ( ( F_47 ( V_2 , V_63 ) &
V_85 ) == ( V_83 << V_86 ) ,
50 ) )
F_21 ( L_8 ) ;
}
V_72 = F_49 ( V_2 , V_87 ) ;
V_72 &= ~ 0x7f ;
if ( V_5 == 400000 )
V_72 |= 4500 / 250 ;
else
V_72 |= 3000 / 250 ;
F_50 ( V_2 , V_87 , V_72 ) ;
F_46 ( & V_2 -> V_82 ) ;
F_51 ( V_2 ) ;
F_36 ( V_2 ) ;
F_52 ( V_2 , V_74 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
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
F_54 ( V_5 ) ;
return;
}
F_41 ( V_2 , V_74 ) ;
V_73 = F_25 ( V_2 -> V_61 << 1 , V_5 ) - 1 ;
F_42 ( & V_2 -> V_75 . V_76 ) ;
V_72 = F_43 ( V_2 , V_77 ) ;
V_72 &= ~ V_88 ;
V_72 |= ( V_73 << V_89 ) ;
F_44 ( V_2 , V_77 , V_72 ) ;
if ( F_45 ( ( F_43 ( V_2 , V_77 ) &
V_90 ) == ( V_73 << V_91 ) ,
50 ) ) {
F_21 ( L_8 ) ;
}
F_46 ( & V_2 -> V_75 . V_76 ) ;
F_51 ( V_2 ) ;
F_36 ( V_2 ) ;
F_52 ( V_2 , V_74 ) ;
}
static int F_55 ( int V_59 )
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
static void F_56 ( struct V_1 * V_2 ,
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
else if ( V_53 == V_92 )
V_4 -> V_5 = 540000 ;
else if ( V_53 == V_93 )
V_4 -> V_5 = 337500 ;
else
V_4 -> V_5 = 675000 ;
}
static void F_57 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 = V_4 -> V_5 ;
T_4 V_72 , V_94 ;
int V_95 ;
if ( F_58 ( ( F_19 ( V_52 ) &
( V_96 | V_97 |
V_98 | V_99 |
V_100 | V_101 |
V_55 ) ) != V_97 ,
L_9 ) )
return;
F_42 ( & V_2 -> V_75 . V_76 ) ;
V_95 = F_59 ( V_2 ,
V_102 , 0x0 ) ;
F_46 ( & V_2 -> V_75 . V_76 ) ;
if ( V_95 ) {
F_21 ( L_10 ) ;
return;
}
V_72 = F_19 ( V_52 ) ;
V_72 |= V_55 ;
F_38 ( V_52 , V_72 ) ;
if ( F_60 ( F_19 ( V_52 ) &
V_103 , 1 ) )
F_21 ( L_11 ) ;
V_72 = F_19 ( V_52 ) ;
V_72 &= ~ V_54 ;
switch ( V_5 ) {
case 450000 :
V_72 |= V_58 ;
V_94 = 0 ;
break;
case 540000 :
V_72 |= V_92 ;
V_94 = 1 ;
break;
case 337500 :
V_72 |= V_93 ;
V_94 = 2 ;
break;
case 675000 :
V_72 |= V_104 ;
V_94 = 3 ;
break;
default:
F_58 ( 1 , L_12 ) ;
return;
}
F_38 ( V_52 , V_72 ) ;
V_72 = F_19 ( V_52 ) ;
V_72 &= ~ V_55 ;
F_38 ( V_52 , V_72 ) ;
if ( F_60 ( ( F_19 ( V_52 ) &
V_103 ) == 0 , 1 ) )
F_21 ( L_13 ) ;
F_42 ( & V_2 -> V_75 . V_76 ) ;
F_59 ( V_2 , V_105 , V_94 ) ;
F_46 ( & V_2 -> V_75 . V_76 ) ;
F_38 ( V_106 , F_25 ( V_5 , 1000 ) - 1 ) ;
F_51 ( V_2 ) ;
F_58 ( V_5 != V_2 -> V_5 . V_66 . V_5 ,
L_14 ,
V_5 , V_2 -> V_5 . V_66 . V_5 ) ;
}
static int F_61 ( int V_59 , int V_34 )
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
static void F_62 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_5 V_72 ;
V_4 -> V_107 = 24000 ;
V_4 -> V_34 = 0 ;
V_72 = F_19 ( V_108 ) ;
if ( ( V_72 & V_109 ) == 0 )
return;
if ( F_39 ( ( V_72 & V_97 ) == 0 ) )
return;
V_72 = F_19 ( V_110 ) ;
if ( F_39 ( ( V_72 & ( F_63 ( V_111 ) |
F_64 ( V_111 ) |
F_65 ( V_111 ) ) ) !=
F_65 ( V_111 ) ) )
return;
switch ( V_72 & F_66 ( V_111 ) ) {
case F_67 ( V_112 , V_111 ) :
case F_67 ( V_113 , V_111 ) :
case F_67 ( V_114 , V_111 ) :
case F_67 ( V_115 , V_111 ) :
V_4 -> V_34 = 8100000 ;
break;
case F_67 ( V_116 , V_111 ) :
case F_67 ( V_117 , V_111 ) :
V_4 -> V_34 = 8640000 ;
break;
default:
F_54 ( V_72 & F_66 ( V_111 ) ) ;
break;
}
}
static void F_68 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_5 V_118 ;
F_62 ( V_2 , V_4 ) ;
V_4 -> V_5 = V_4 -> V_107 ;
if ( V_4 -> V_34 == 0 )
return;
V_118 = F_19 ( V_119 ) ;
if ( V_4 -> V_34 == 8640000 ) {
switch ( V_118 & V_120 ) {
case V_121 :
V_4 -> V_5 = 432000 ;
break;
case V_122 :
V_4 -> V_5 = 308571 ;
break;
case V_123 :
V_4 -> V_5 = 540000 ;
break;
case V_124 :
V_4 -> V_5 = 617143 ;
break;
default:
F_54 ( V_118 & V_120 ) ;
break;
}
} else {
switch ( V_118 & V_120 ) {
case V_121 :
V_4 -> V_5 = 450000 ;
break;
case V_122 :
V_4 -> V_5 = 337500 ;
break;
case V_123 :
V_4 -> V_5 = 540000 ;
break;
case V_124 :
V_4 -> V_5 = 675000 ;
break;
default:
F_54 ( V_118 & V_120 ) ;
break;
}
}
}
static int F_69 ( int V_5 )
{
return F_25 ( V_5 - 1000 , 500 ) ;
}
static void F_70 ( struct V_1 * V_2 ,
int V_34 )
{
bool V_125 = V_2 -> V_126 != V_34 ;
V_2 -> V_126 = V_34 ;
if ( V_125 )
F_71 ( V_2 ) ;
}
static void F_72 ( struct V_1 * V_2 , int V_34 )
{
int V_127 = F_61 ( 0 , V_34 ) ;
T_5 V_72 ;
F_39 ( V_34 != 8100000 && V_34 != 8640000 ) ;
V_72 = V_122 | F_69 ( V_127 ) ;
F_38 ( V_119 , V_72 ) ;
F_73 ( V_119 ) ;
V_72 = F_19 ( V_110 ) ;
V_72 &= ~ ( F_63 ( V_111 ) | F_64 ( V_111 ) |
F_66 ( V_111 ) ) ;
V_72 |= F_65 ( V_111 ) ;
if ( V_34 == 8640000 )
V_72 |= F_67 ( V_116 ,
V_111 ) ;
else
V_72 |= F_67 ( V_112 ,
V_111 ) ;
F_38 ( V_110 , V_72 ) ;
F_73 ( V_110 ) ;
F_38 ( V_108 , F_19 ( V_108 ) | V_109 ) ;
if ( F_74 ( V_2 ,
V_108 , V_97 , V_97 ,
5 ) )
F_21 ( L_15 ) ;
V_2 -> V_5 . V_66 . V_34 = V_34 ;
F_70 ( V_2 , V_34 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
F_38 ( V_108 , F_19 ( V_108 ) & ~ V_109 ) ;
if ( F_74 ( V_2 ,
V_108 , V_97 , 0 ,
1 ) )
F_21 ( L_16 ) ;
V_2 -> V_5 . V_66 . V_34 = 0 ;
}
static void F_76 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 = V_4 -> V_5 ;
int V_34 = V_4 -> V_34 ;
T_5 V_128 , V_129 ;
int V_95 ;
F_39 ( ( V_5 == 24000 ) != ( V_34 == 0 ) ) ;
F_42 ( & V_2 -> V_75 . V_76 ) ;
V_95 = F_77 ( V_2 , V_130 ,
V_131 ,
V_132 ,
V_132 , 3 ) ;
F_46 ( & V_2 -> V_75 . V_76 ) ;
if ( V_95 ) {
F_21 ( L_17 ,
V_95 ) ;
return;
}
switch ( V_5 ) {
case 450000 :
case 432000 :
V_128 = V_121 ;
V_129 = 1 ;
break;
case 540000 :
V_128 = V_123 ;
V_129 = 2 ;
break;
case 308571 :
case 337500 :
default:
V_128 = V_122 ;
V_129 = 0 ;
break;
case 617143 :
case 675000 :
V_128 = V_124 ;
V_129 = 3 ;
break;
}
if ( V_2 -> V_5 . V_66 . V_34 != 0 &&
V_2 -> V_5 . V_66 . V_34 != V_34 )
F_75 ( V_2 ) ;
if ( V_2 -> V_5 . V_66 . V_34 != V_34 )
F_72 ( V_2 , V_34 ) ;
F_38 ( V_119 , V_128 | F_69 ( V_5 ) ) ;
F_73 ( V_119 ) ;
F_42 ( & V_2 -> V_75 . V_76 ) ;
F_59 ( V_2 , V_130 , V_129 ) ;
F_46 ( & V_2 -> V_75 . V_76 ) ;
F_51 ( V_2 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
T_4 V_118 , V_133 ;
if ( ( F_19 ( F_79 ( 0x18 ) ) & 0x00FFFFFF ) == 0 )
goto V_134;
F_51 ( V_2 ) ;
if ( V_2 -> V_5 . V_66 . V_34 == 0 ||
V_2 -> V_5 . V_66 . V_5 == V_2 -> V_5 . V_66 . V_107 )
goto V_134;
V_118 = F_19 ( V_119 ) ;
V_133 = ( V_118 & V_120 ) |
F_69 ( V_2 -> V_5 . V_66 . V_5 ) ;
if ( V_118 == V_133 )
return;
V_134:
F_22 ( L_18 ) ;
V_2 -> V_5 . V_66 . V_5 = 0 ;
V_2 -> V_5 . V_66 . V_34 = - 1 ;
}
void F_80 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_78 ( V_2 ) ;
if ( V_2 -> V_5 . V_66 . V_5 != 0 &&
V_2 -> V_5 . V_66 . V_34 != 0 ) {
if ( V_2 -> V_126 == 0 )
F_70 ( V_2 ,
V_2 -> V_5 . V_66 . V_34 ) ;
return;
}
V_4 = V_2 -> V_5 . V_66 ;
V_4 . V_34 = V_2 -> V_126 ;
if ( V_4 . V_34 == 0 )
V_4 . V_34 = 8100000 ;
V_4 . V_5 = F_61 ( 0 , V_4 . V_34 ) ;
F_76 ( V_2 , & V_4 ) ;
}
void F_81 ( struct V_1 * V_2 )
{
struct V_3 V_4 = V_2 -> V_5 . V_66 ;
V_4 . V_5 = V_4 . V_107 ;
V_4 . V_34 = 0 ;
F_76 ( V_2 , & V_4 ) ;
}
static int F_82 ( int V_59 )
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
static int F_83 ( int V_59 )
{
if ( V_59 > F_84 ( 2 * 158400 * 99 , 100 ) )
return 316800 ;
else if ( V_59 > F_84 ( 2 * 79200 * 99 , 100 ) )
return 158400 ;
else
return 79200 ;
}
static int F_85 ( struct V_1 * V_2 , int V_5 )
{
int V_135 ;
if ( V_5 == V_2 -> V_5 . V_66 . V_107 )
return 0 ;
switch ( V_5 ) {
default:
F_54 ( V_5 ) ;
case 144000 :
case 288000 :
case 384000 :
case 576000 :
V_135 = 60 ;
break;
case 624000 :
V_135 = 65 ;
break;
}
return V_2 -> V_5 . V_66 . V_107 * V_135 ;
}
static int F_86 ( struct V_1 * V_2 , int V_5 )
{
int V_135 ;
if ( V_5 == V_2 -> V_5 . V_66 . V_107 )
return 0 ;
switch ( V_5 ) {
default:
F_54 ( V_5 ) ;
case 79200 :
case 158400 :
case 316800 :
V_135 = 33 ;
break;
}
return V_2 -> V_5 . V_66 . V_107 * V_135 ;
}
static void F_87 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_5 V_72 ;
V_4 -> V_107 = 19200 ;
V_4 -> V_34 = 0 ;
V_72 = F_19 ( V_136 ) ;
if ( ( V_72 & V_137 ) == 0 )
return;
if ( F_39 ( ( V_72 & V_138 ) == 0 ) )
return;
V_72 = F_19 ( V_139 ) ;
V_4 -> V_34 = ( V_72 & V_140 ) * V_4 -> V_107 ;
}
static void F_88 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_5 V_83 ;
int div ;
F_87 ( V_2 , V_4 ) ;
V_4 -> V_5 = V_4 -> V_107 ;
if ( V_4 -> V_34 == 0 )
return;
V_83 = F_19 ( V_119 ) & V_141 ;
switch ( V_83 ) {
case V_142 :
div = 2 ;
break;
case V_143 :
F_58 ( F_89 ( V_2 ) , L_19 ) ;
div = 3 ;
break;
case V_144 :
div = 4 ;
break;
case V_145 :
div = 8 ;
break;
default:
F_54 ( V_83 ) ;
return;
}
V_4 -> V_5 = F_25 ( V_4 -> V_34 , div ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
F_38 ( V_136 , 0 ) ;
if ( F_74 ( V_2 ,
V_136 , V_138 , 0 ,
1 ) )
F_21 ( L_20 ) ;
V_2 -> V_5 . V_66 . V_34 = 0 ;
}
static void F_91 ( struct V_1 * V_2 , int V_34 )
{
int V_135 = F_25 ( V_34 , V_2 -> V_5 . V_66 . V_107 ) ;
T_5 V_72 ;
V_72 = F_19 ( V_139 ) ;
V_72 &= ~ V_140 ;
V_72 |= F_92 ( V_135 ) ;
F_38 ( V_139 , V_72 ) ;
F_38 ( V_136 , V_137 ) ;
if ( F_74 ( V_2 ,
V_136 ,
V_138 ,
V_138 ,
1 ) )
F_21 ( L_21 ) ;
V_2 -> V_5 . V_66 . V_34 = V_34 ;
}
static void F_93 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 = V_4 -> V_5 ;
int V_34 = V_4 -> V_34 ;
T_5 V_72 , V_83 ;
int V_95 ;
switch ( F_25 ( V_34 , V_5 ) ) {
case 8 :
V_83 = V_145 ;
break;
case 4 :
V_83 = V_144 ;
break;
case 3 :
F_58 ( F_89 ( V_2 ) , L_19 ) ;
V_83 = V_143 ;
break;
case 2 :
V_83 = V_142 ;
break;
default:
F_39 ( V_5 != V_2 -> V_5 . V_66 . V_107 ) ;
F_39 ( V_34 != 0 ) ;
V_83 = V_142 ;
break;
}
F_42 ( & V_2 -> V_75 . V_76 ) ;
V_95 = F_59 ( V_2 , V_105 ,
0x80000000 ) ;
F_46 ( & V_2 -> V_75 . V_76 ) ;
if ( V_95 ) {
F_21 ( L_22 ,
V_95 , V_5 ) ;
return;
}
if ( V_2 -> V_5 . V_66 . V_34 != 0 &&
V_2 -> V_5 . V_66 . V_34 != V_34 )
F_90 ( V_2 ) ;
if ( V_2 -> V_5 . V_66 . V_34 != V_34 )
F_91 ( V_2 , V_34 ) ;
V_72 = V_83 | F_69 ( V_5 ) ;
V_72 |= V_146 ;
if ( V_5 >= 500000 )
V_72 |= V_147 ;
F_38 ( V_119 , V_72 ) ;
F_42 ( & V_2 -> V_75 . V_76 ) ;
V_95 = F_59 ( V_2 , V_105 ,
F_84 ( V_5 , 25000 ) ) ;
F_46 ( & V_2 -> V_75 . V_76 ) ;
if ( V_95 ) {
F_21 ( L_23 ,
V_95 , V_5 ) ;
return;
}
F_51 ( V_2 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
T_5 V_118 , V_133 ;
F_51 ( V_2 ) ;
if ( V_2 -> V_5 . V_66 . V_34 == 0 ||
V_2 -> V_5 . V_66 . V_5 == V_2 -> V_5 . V_66 . V_107 )
goto V_134;
V_118 = F_19 ( V_119 ) ;
V_118 &= ~ V_146 ;
V_133 = ( V_118 & V_141 ) |
F_69 ( V_2 -> V_5 . V_66 . V_5 ) ;
if ( V_2 -> V_5 . V_66 . V_5 >= 500000 )
V_133 |= V_147 ;
if ( V_118 == V_133 )
return;
V_134:
F_22 ( L_18 ) ;
V_2 -> V_5 . V_66 . V_5 = 0 ;
V_2 -> V_5 . V_66 . V_34 = - 1 ;
}
void F_95 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_94 ( V_2 ) ;
if ( V_2 -> V_5 . V_66 . V_5 != 0 &&
V_2 -> V_5 . V_66 . V_34 != 0 )
return;
V_4 = V_2 -> V_5 . V_66 ;
if ( F_89 ( V_2 ) ) {
V_4 . V_5 = F_83 ( 0 ) ;
V_4 . V_34 = F_86 ( V_2 , V_4 . V_5 ) ;
} else {
V_4 . V_5 = F_82 ( 0 ) ;
V_4 . V_34 = F_85 ( V_2 , V_4 . V_5 ) ;
}
F_93 ( V_2 , & V_4 ) ;
}
void F_96 ( struct V_1 * V_2 )
{
struct V_3 V_4 = V_2 -> V_5 . V_66 ;
V_4 . V_5 = V_4 . V_107 ;
V_4 . V_34 = 0 ;
F_93 ( V_2 , & V_4 ) ;
}
static int F_97 ( int V_59 )
{
if ( V_59 > 336000 )
return 528000 ;
else if ( V_59 > 168000 )
return 336000 ;
else
return 168000 ;
}
static void F_98 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_5 V_72 ;
if ( F_19 ( V_148 ) & V_149 )
V_4 -> V_107 = 24000 ;
else
V_4 -> V_107 = 19200 ;
V_4 -> V_34 = 0 ;
V_72 = F_19 ( V_136 ) ;
if ( ( V_72 & V_137 ) == 0 )
return;
if ( F_39 ( ( V_72 & V_138 ) == 0 ) )
return;
V_4 -> V_34 = ( V_72 & V_150 ) * V_4 -> V_107 ;
}
static void F_99 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_5 V_83 ;
int div ;
F_98 ( V_2 , V_4 ) ;
V_4 -> V_5 = V_4 -> V_107 ;
if ( V_4 -> V_34 == 0 )
return;
V_83 = F_19 ( V_119 ) & V_141 ;
switch ( V_83 ) {
case V_142 :
div = 2 ;
break;
case V_144 :
div = 4 ;
break;
default:
F_54 ( V_83 ) ;
return;
}
V_4 -> V_5 = F_25 ( V_4 -> V_34 , div ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
T_5 V_72 ;
V_72 = F_19 ( V_136 ) ;
V_72 &= ~ V_137 ;
F_38 ( V_136 , V_72 ) ;
if ( F_45 ( ( F_19 ( V_136 ) & V_138 ) == 0 , 1 ) )
F_21 ( L_24 ) ;
V_2 -> V_5 . V_66 . V_34 = 0 ;
}
static void F_101 ( struct V_1 * V_2 , int V_34 )
{
int V_135 = F_25 ( V_34 , V_2 -> V_5 . V_66 . V_107 ) ;
T_5 V_72 ;
V_72 = F_102 ( V_135 ) ;
F_38 ( V_136 , V_72 ) ;
V_72 |= V_137 ;
F_38 ( V_136 , V_72 ) ;
if ( F_45 ( ( F_19 ( V_136 ) & V_138 ) != 0 , 1 ) )
F_21 ( L_25 ) ;
V_2 -> V_5 . V_66 . V_34 = V_34 ;
}
static void F_103 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 = V_4 -> V_5 ;
int V_34 = V_4 -> V_34 ;
T_5 V_72 , V_83 , V_129 ;
int V_95 ;
F_42 ( & V_2 -> V_75 . V_76 ) ;
V_95 = F_77 ( V_2 , V_130 ,
V_131 ,
V_132 ,
V_132 , 3 ) ;
F_46 ( & V_2 -> V_75 . V_76 ) ;
if ( V_95 ) {
F_21 ( L_17 ,
V_95 ) ;
return;
}
switch ( F_25 ( V_34 , V_5 ) ) {
case 4 :
V_83 = V_144 ;
break;
case 2 :
V_83 = V_142 ;
break;
default:
F_39 ( V_5 != V_2 -> V_5 . V_66 . V_107 ) ;
F_39 ( V_34 != 0 ) ;
V_83 = V_142 ;
break;
}
switch ( V_5 ) {
case 528000 :
V_129 = 2 ;
break;
case 336000 :
V_129 = 1 ;
break;
case 168000 :
default:
V_129 = 0 ;
break;
}
if ( V_2 -> V_5 . V_66 . V_34 != 0 &&
V_2 -> V_5 . V_66 . V_34 != V_34 )
F_100 ( V_2 ) ;
if ( V_2 -> V_5 . V_66 . V_34 != V_34 )
F_101 ( V_2 , V_34 ) ;
V_72 = V_83 | F_69 ( V_5 ) ;
V_72 |= V_146 ;
F_38 ( V_119 , V_72 ) ;
F_42 ( & V_2 -> V_75 . V_76 ) ;
F_59 ( V_2 , V_130 , V_129 ) ;
F_46 ( & V_2 -> V_75 . V_76 ) ;
F_51 ( V_2 ) ;
}
static int F_104 ( struct V_1 * V_2 , int V_5 )
{
int V_135 ;
if ( V_5 == V_2 -> V_5 . V_66 . V_107 )
return 0 ;
switch ( V_5 ) {
default:
F_54 ( V_5 ) ;
case 168000 :
case 336000 :
V_135 = V_2 -> V_5 . V_66 . V_107 == 19200 ? 35 : 28 ;
break;
case 528000 :
V_135 = V_2 -> V_5 . V_66 . V_107 == 19200 ? 55 : 44 ;
break;
}
return V_2 -> V_5 . V_66 . V_107 * V_135 ;
}
static void F_105 ( struct V_1 * V_2 )
{
T_5 V_118 , V_133 ;
F_51 ( V_2 ) ;
if ( V_2 -> V_5 . V_66 . V_34 == 0 ||
V_2 -> V_5 . V_66 . V_5 == V_2 -> V_5 . V_66 . V_107 )
goto V_134;
V_118 = F_19 ( V_119 ) ;
V_118 &= ~ V_146 ;
V_133 = ( V_118 & V_141 ) |
F_69 ( V_2 -> V_5 . V_66 . V_5 ) ;
if ( V_118 == V_133 )
return;
V_134:
F_22 ( L_18 ) ;
V_2 -> V_5 . V_66 . V_5 = 0 ;
V_2 -> V_5 . V_66 . V_34 = - 1 ;
}
void F_106 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_105 ( V_2 ) ;
if ( V_2 -> V_5 . V_66 . V_5 != 0 &&
V_2 -> V_5 . V_66 . V_34 != 0 )
return;
V_4 = V_2 -> V_5 . V_66 ;
V_4 . V_5 = F_97 ( 0 ) ;
V_4 . V_34 = F_104 ( V_2 , V_4 . V_5 ) ;
F_103 ( V_2 , & V_4 ) ;
}
void F_107 ( struct V_1 * V_2 )
{
struct V_3 V_4 = V_2 -> V_5 . V_66 ;
V_4 . V_5 = V_4 . V_107 ;
V_4 . V_34 = 0 ;
F_103 ( V_2 , & V_4 ) ;
}
bool F_108 ( const struct V_3 * V_151 ,
const struct V_3 * V_152 )
{
return memcmp ( V_151 , V_152 , sizeof( * V_151 ) ) == 0 ;
}
void F_109 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( F_108 ( & V_2 -> V_5 . V_66 , V_4 ) )
return;
if ( F_110 ( ! V_2 -> V_153 . V_154 ) )
return;
F_111 ( L_26 ,
V_4 -> V_5 , V_4 -> V_34 ,
V_4 -> V_107 ) ;
V_2 -> V_153 . V_154 ( V_2 , V_4 ) ;
}
static int F_112 ( struct V_155 * V_156 ,
int V_157 )
{
struct V_1 * V_2 =
F_113 ( V_156 -> V_158 . V_159 -> V_160 ) ;
if ( F_114 ( V_2 ) && V_156 -> V_161 )
V_157 = F_84 ( V_157 * 100 , 95 ) ;
if ( F_115 ( V_156 ) &&
V_156 -> V_162 &&
V_156 -> V_163 >= 540000 &&
V_156 -> V_164 == 4 ) {
if ( F_116 ( V_2 ) )
V_157 = F_117 ( 316800 , V_157 ) ;
else if ( F_89 ( V_2 ) )
V_157 = F_117 ( 2 * 316800 , V_157 ) ;
else
V_157 = F_117 ( 432000 , V_157 ) ;
}
if ( V_156 -> V_162 && F_118 ( V_2 ) >= 9 ) {
if ( F_89 ( V_2 ) )
V_157 = F_117 ( 2 * 2 * 96000 , V_157 ) ;
else
V_157 = F_117 ( 2 * 96000 , V_157 ) ;
}
return V_157 ;
}
static int F_119 ( struct V_165 * V_166 )
{
struct V_167 * V_168 = F_120 ( V_166 ) ;
struct V_1 * V_2 = F_113 ( V_166 -> V_160 ) ;
struct V_169 * V_159 ;
struct V_170 * V_171 ;
struct V_155 * V_156 ;
unsigned int V_172 = 0 , V_173 ;
enum V_174 V_174 ;
memcpy ( V_168 -> V_175 , V_2 -> V_175 ,
sizeof( V_168 -> V_175 ) ) ;
F_121 (state, crtc, cstate, i) {
int V_157 ;
V_156 = F_122 ( V_171 ) ;
if ( ! V_156 -> V_158 . V_176 ) {
V_168 -> V_175 [ V_173 ] = 0 ;
continue;
}
V_157 = V_156 -> V_157 ;
if ( F_114 ( V_2 ) || F_118 ( V_2 ) >= 9 )
V_157 =
F_112 ( V_156 ,
V_157 ) ;
V_168 -> V_175 [ V_173 ] = V_157 ;
}
F_123 (dev_priv, pipe)
V_172 = F_117 ( V_168 -> V_175 [ V_174 ] ,
V_172 ) ;
return V_172 ;
}
static int F_124 ( struct V_165 * V_166 )
{
struct V_1 * V_2 = F_113 ( V_166 -> V_160 ) ;
int V_59 = F_119 ( V_166 ) ;
struct V_167 * V_168 =
F_120 ( V_166 ) ;
int V_5 ;
V_5 = F_31 ( V_2 , V_59 ) ;
if ( V_5 > V_2 -> V_177 ) {
F_22 ( L_27 ,
V_5 , V_2 -> V_177 ) ;
return - V_178 ;
}
V_168 -> V_5 . V_179 . V_5 = V_5 ;
if ( ! V_168 -> V_180 ) {
V_5 = F_31 ( V_2 , 0 ) ;
V_168 -> V_5 . V_181 . V_5 = V_5 ;
} else {
V_168 -> V_5 . V_181 =
V_168 -> V_5 . V_179 ;
}
return 0 ;
}
static int F_125 ( struct V_165 * V_166 )
{
struct V_1 * V_2 = F_113 ( V_166 -> V_160 ) ;
struct V_167 * V_168 = F_120 ( V_166 ) ;
int V_59 = F_119 ( V_166 ) ;
int V_5 ;
V_5 = F_55 ( V_59 ) ;
if ( V_5 > V_2 -> V_177 ) {
F_22 ( L_27 ,
V_5 , V_2 -> V_177 ) ;
return - V_178 ;
}
V_168 -> V_5 . V_179 . V_5 = V_5 ;
if ( ! V_168 -> V_180 ) {
V_5 = F_55 ( 0 ) ;
V_168 -> V_5 . V_181 . V_5 = V_5 ;
} else {
V_168 -> V_5 . V_181 =
V_168 -> V_5 . V_179 ;
}
return 0 ;
}
static int F_126 ( struct V_165 * V_166 )
{
struct V_167 * V_168 = F_120 ( V_166 ) ;
struct V_1 * V_2 = F_113 ( V_166 -> V_160 ) ;
const int V_59 = F_119 ( V_166 ) ;
int V_5 , V_34 ;
V_34 = V_168 -> V_5 . V_179 . V_34 ;
if ( ! V_34 )
V_34 = V_2 -> V_126 ;
V_5 = F_61 ( V_59 , V_34 ) ;
if ( V_5 > V_2 -> V_177 ) {
F_22 ( L_27 ,
V_5 , V_2 -> V_177 ) ;
return - V_178 ;
}
V_168 -> V_5 . V_179 . V_34 = V_34 ;
V_168 -> V_5 . V_179 . V_5 = V_5 ;
if ( ! V_168 -> V_180 ) {
V_5 = F_61 ( 0 , V_34 ) ;
V_168 -> V_5 . V_181 . V_34 = V_34 ;
V_168 -> V_5 . V_181 . V_5 = V_5 ;
} else {
V_168 -> V_5 . V_181 =
V_168 -> V_5 . V_179 ;
}
return 0 ;
}
static int F_127 ( struct V_165 * V_166 )
{
struct V_1 * V_2 = F_113 ( V_166 -> V_160 ) ;
int V_59 = F_119 ( V_166 ) ;
struct V_167 * V_168 =
F_120 ( V_166 ) ;
int V_5 , V_34 ;
if ( F_89 ( V_2 ) ) {
V_5 = F_83 ( V_59 ) ;
V_34 = F_86 ( V_2 , V_5 ) ;
} else {
V_5 = F_82 ( V_59 ) ;
V_34 = F_85 ( V_2 , V_5 ) ;
}
if ( V_5 > V_2 -> V_177 ) {
F_22 ( L_27 ,
V_5 , V_2 -> V_177 ) ;
return - V_178 ;
}
V_168 -> V_5 . V_179 . V_34 = V_34 ;
V_168 -> V_5 . V_179 . V_5 = V_5 ;
if ( ! V_168 -> V_180 ) {
if ( F_89 ( V_2 ) ) {
V_5 = F_83 ( 0 ) ;
V_34 = F_86 ( V_2 , V_5 ) ;
} else {
V_5 = F_82 ( 0 ) ;
V_34 = F_85 ( V_2 , V_5 ) ;
}
V_168 -> V_5 . V_181 . V_34 = V_34 ;
V_168 -> V_5 . V_181 . V_5 = V_5 ;
} else {
V_168 -> V_5 . V_181 =
V_168 -> V_5 . V_179 ;
}
return 0 ;
}
static int F_128 ( struct V_165 * V_166 )
{
struct V_1 * V_2 = F_113 ( V_166 -> V_160 ) ;
struct V_167 * V_168 =
F_120 ( V_166 ) ;
int V_59 = F_119 ( V_166 ) ;
int V_5 , V_34 ;
V_5 = F_97 ( V_59 ) ;
V_34 = F_104 ( V_2 , V_5 ) ;
if ( V_5 > V_2 -> V_177 ) {
F_22 ( L_27 ,
V_5 , V_2 -> V_177 ) ;
return - V_178 ;
}
V_168 -> V_5 . V_179 . V_34 = V_34 ;
V_168 -> V_5 . V_179 . V_5 = V_5 ;
if ( ! V_168 -> V_180 ) {
V_5 = F_97 ( 0 ) ;
V_34 = F_104 ( V_2 , V_5 ) ;
V_168 -> V_5 . V_181 . V_34 = V_34 ;
V_168 -> V_5 . V_181 . V_5 = V_5 ;
} else {
V_168 -> V_5 . V_181 =
V_168 -> V_5 . V_179 ;
}
return 0 ;
}
static int F_129 ( struct V_1 * V_2 )
{
int V_177 = V_2 -> V_177 ;
if ( F_89 ( V_2 ) )
return 2 * V_177 * 99 / 100 ;
else if ( F_130 ( V_2 ) -> V_182 >= 9 ||
F_131 ( V_2 ) || F_114 ( V_2 ) )
return V_177 ;
else if ( F_32 ( V_2 ) )
return V_177 * 95 / 100 ;
else if ( F_130 ( V_2 ) -> V_182 < 4 )
return 2 * V_177 * 90 / 100 ;
else
return V_177 * 90 / 100 ;
}
void F_71 ( struct V_1 * V_2 )
{
if ( F_116 ( V_2 ) ) {
V_2 -> V_177 = 528000 ;
} else if ( F_132 ( V_2 ) ) {
T_5 V_62 = F_19 ( V_183 ) & V_184 ;
int V_185 , V_34 ;
V_34 = V_2 -> V_126 ;
F_39 ( V_34 != 8100000 && V_34 != 8640000 ) ;
if ( V_62 == V_186 )
V_185 = 617143 ;
else if ( V_62 == V_187 )
V_185 = 540000 ;
else if ( V_62 == V_188 )
V_185 = 432000 ;
else
V_185 = 308571 ;
V_2 -> V_177 = F_61 ( V_185 , V_34 ) ;
} else if ( F_89 ( V_2 ) ) {
V_2 -> V_177 = 316800 ;
} else if ( F_133 ( V_2 ) ) {
V_2 -> V_177 = 624000 ;
} else if ( F_114 ( V_2 ) ) {
if ( F_19 ( V_56 ) & V_57 )
V_2 -> V_177 = 450000 ;
else if ( F_134 ( V_2 ) )
V_2 -> V_177 = 450000 ;
else if ( F_135 ( V_2 ) )
V_2 -> V_177 = 540000 ;
else
V_2 -> V_177 = 675000 ;
} else if ( F_32 ( V_2 ) ) {
V_2 -> V_177 = 320000 ;
} else if ( F_136 ( V_2 ) ) {
V_2 -> V_177 = 400000 ;
} else {
V_2 -> V_177 = V_2 -> V_5 . V_66 . V_5 ;
}
V_2 -> V_189 = F_129 ( V_2 ) ;
F_111 ( L_28 ,
V_2 -> V_177 ) ;
F_111 ( L_29 ,
V_2 -> V_189 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
V_2 -> V_153 . V_190 ( V_2 , & V_2 -> V_5 . V_66 ) ;
F_111 ( L_30 ,
V_2 -> V_5 . V_66 . V_5 , V_2 -> V_5 . V_66 . V_34 ,
V_2 -> V_5 . V_66 . V_107 ) ;
if ( F_136 ( V_2 ) || F_32 ( V_2 ) )
F_38 ( V_191 ,
F_84 ( V_2 -> V_5 . V_66 . V_5 , 1000 ) ) ;
}
static int F_137 ( struct V_1 * V_2 )
{
T_5 V_192 ;
int V_83 , V_193 ;
if ( F_19 ( V_194 ) & V_195 ) {
V_83 = 24000 ;
V_193 = 0 ;
} else {
V_83 = 19000 ;
V_193 = 200 ;
}
V_192 = F_138 ( ( V_83 / 1000 ) - 1 ) ;
if ( V_193 )
V_192 |= F_139 ( F_25 ( 1000 ,
V_193 ) - 1 ) ;
F_38 ( V_196 , V_192 ) ;
return V_83 + V_193 ;
}
static int F_140 ( struct V_1 * V_2 )
{
return ( F_19 ( V_196 ) & V_197 ) * 1000 ;
}
static int F_141 ( struct V_1 * V_2 )
{
return F_142 ( V_2 , L_31 ,
V_198 ) ;
}
static int F_143 ( struct V_1 * V_2 )
{
T_4 V_199 ;
V_199 = F_19 ( V_200 ) ;
switch ( V_199 & V_201 ) {
case V_202 :
return 100000 ;
case V_203 :
return 133333 ;
case V_204 :
return 166667 ;
case V_205 :
return 200000 ;
case V_206 :
case V_207 :
return 266667 ;
case V_208 :
case V_209 :
return 333333 ;
default:
return 133333 ;
}
}
void F_144 ( struct V_1 * V_2 )
{
if ( F_145 ( V_2 ) )
V_2 -> V_210 = F_137 ( V_2 ) ;
else if ( F_146 ( V_2 ) )
V_2 -> V_210 = F_140 ( V_2 ) ;
else if ( F_136 ( V_2 ) || F_32 ( V_2 ) )
V_2 -> V_210 = F_141 ( V_2 ) ;
else if ( F_147 ( V_2 ) || F_17 ( V_2 ) )
V_2 -> V_210 = F_143 ( V_2 ) ;
else
return;
F_111 ( L_32 , V_2 -> V_210 ) ;
}
void F_148 ( struct V_1 * V_2 )
{
if ( F_32 ( V_2 ) ) {
V_2 -> V_153 . V_154 = F_53 ;
V_2 -> V_153 . V_211 =
F_124 ;
} else if ( F_136 ( V_2 ) ) {
V_2 -> V_153 . V_154 = F_40 ;
V_2 -> V_153 . V_211 =
F_124 ;
} else if ( F_114 ( V_2 ) ) {
V_2 -> V_153 . V_154 = F_57 ;
V_2 -> V_153 . V_211 =
F_125 ;
} else if ( F_149 ( V_2 ) ) {
V_2 -> V_153 . V_154 = F_93 ;
V_2 -> V_153 . V_211 =
F_127 ;
} else if ( F_132 ( V_2 ) ) {
V_2 -> V_153 . V_154 = F_76 ;
V_2 -> V_153 . V_211 =
F_126 ;
} else if ( F_116 ( V_2 ) ) {
V_2 -> V_153 . V_154 = F_103 ;
V_2 -> V_153 . V_211 =
F_128 ;
}
if ( F_116 ( V_2 ) )
V_2 -> V_153 . V_190 = F_99 ;
else if ( F_132 ( V_2 ) )
V_2 -> V_153 . V_190 = F_68 ;
else if ( F_149 ( V_2 ) )
V_2 -> V_153 . V_190 = F_88 ;
else if ( F_114 ( V_2 ) )
V_2 -> V_153 . V_190 = F_56 ;
else if ( F_131 ( V_2 ) )
V_2 -> V_153 . V_190 = F_29 ;
else if ( F_136 ( V_2 ) || F_32 ( V_2 ) )
V_2 -> V_153 . V_190 = F_33 ;
else if ( F_150 ( V_2 ) || F_151 ( V_2 ) )
V_2 -> V_153 . V_190 = F_5 ;
else if ( F_152 ( V_2 ) )
V_2 -> V_153 . V_190 = F_6 ;
else if ( F_14 ( V_2 ) )
V_2 -> V_153 . V_190 = F_28 ;
else if ( F_15 ( V_2 ) )
V_2 -> V_153 . V_190 = F_23 ;
else if ( F_16 ( V_2 ) )
V_2 -> V_153 . V_190 = F_27 ;
else if ( F_153 ( V_2 ) )
V_2 -> V_153 . V_190 = F_5 ;
else if ( F_17 ( V_2 ) )
V_2 -> V_153 . V_190 = F_26 ;
else if ( F_18 ( V_2 ) )
V_2 -> V_153 . V_190 = F_23 ;
else if ( F_154 ( V_2 ) )
V_2 -> V_153 . V_190 = F_12 ;
else if ( F_155 ( V_2 ) )
V_2 -> V_153 . V_190 = F_5 ;
else if ( F_156 ( V_2 ) )
V_2 -> V_153 . V_190 = F_10 ;
else if ( F_157 ( V_2 ) )
V_2 -> V_153 . V_190 = F_4 ;
else if ( F_158 ( V_2 ) )
V_2 -> V_153 . V_190 = F_3 ;
else if ( F_159 ( V_2 ) )
V_2 -> V_153 . V_190 = F_7 ;
else if ( F_160 ( V_2 ) )
V_2 -> V_153 . V_190 = F_2 ;
else {
F_58 ( ! F_161 ( V_2 ) ,
L_33 ) ;
V_2 -> V_153 . V_190 = F_1 ;
}
}
