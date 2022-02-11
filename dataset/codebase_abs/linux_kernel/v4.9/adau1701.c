static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
return 3 ;
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
return 2 ;
case V_11 :
return 1 ;
}
F_2 ( V_2 , L_1 , V_3 ) ;
return 0 ;
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_10 :
case V_6 :
return true ;
default:
return false ;
}
}
static int F_4 ( void * V_12 , unsigned int V_3 ,
unsigned int V_13 )
{
struct V_14 * V_15 = V_12 ;
unsigned int V_16 ;
unsigned int V_17 ;
T_1 V_18 [ 5 ] ;
int V_19 ;
V_17 = F_1 ( & V_15 -> V_2 , V_3 ) ;
if ( V_17 == 0 )
return - V_20 ;
V_18 [ 0 ] = V_3 >> 8 ;
V_18 [ 1 ] = V_3 & 0xff ;
for ( V_16 = V_17 + 1 ; V_16 >= 2 ; -- V_16 ) {
V_18 [ V_16 ] = V_13 ;
V_13 >>= 8 ;
}
V_19 = F_5 ( V_15 , V_18 , V_17 + 2 ) ;
if ( V_19 == V_17 + 2 )
return 0 ;
else if ( V_19 < 0 )
return V_19 ;
else
return - V_21 ;
}
static int F_6 ( void * V_12 , unsigned int V_3 ,
unsigned int * V_13 )
{
int V_19 ;
unsigned int V_16 ;
unsigned int V_17 ;
T_1 V_22 [ 2 ] , V_23 [ 3 ] ;
struct V_14 * V_15 = V_12 ;
struct V_24 V_25 [ 2 ] ;
V_17 = F_1 ( & V_15 -> V_2 , V_3 ) ;
if ( V_17 == 0 )
return - V_20 ;
V_22 [ 0 ] = V_3 >> 8 ;
V_22 [ 1 ] = V_3 & 0xff ;
V_25 [ 0 ] . V_26 = V_15 -> V_26 ;
V_25 [ 0 ] . V_27 = sizeof( V_22 ) ;
V_25 [ 0 ] . V_18 = V_22 ;
V_25 [ 0 ] . V_28 = 0 ;
V_25 [ 1 ] . V_26 = V_15 -> V_26 ;
V_25 [ 1 ] . V_27 = V_17 ;
V_25 [ 1 ] . V_18 = V_23 ;
V_25 [ 1 ] . V_28 = V_29 ;
V_19 = F_7 ( V_15 -> V_30 , V_25 , F_8 ( V_25 ) ) ;
if ( V_19 < 0 )
return V_19 ;
else if ( V_19 != F_8 ( V_25 ) )
return - V_21 ;
* V_13 = 0 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
* V_13 <<= 8 ;
* V_13 |= V_23 [ V_16 ] ;
}
return 0 ;
}
static int F_9 ( struct V_31 * V_31 , unsigned int V_26 ,
const T_1 V_32 [] , T_2 V_27 )
{
struct V_14 * V_15 = F_10 ( V_31 -> V_2 ) ;
struct V_33 * V_33 = F_11 ( V_15 ) ;
unsigned int V_34 ;
unsigned int V_16 ;
T_1 V_18 [ 10 ] ;
int V_19 ;
V_19 = F_12 ( V_33 -> V_35 , V_6 , & V_34 ) ;
if ( V_19 )
return V_19 ;
if ( V_34 & V_36 )
F_13 ( 50 ) ;
for ( V_16 = 0 ; V_16 < V_27 / 4 ; V_16 ++ ) {
F_14 ( F_15 ( V_16 ) , V_18 ) ;
V_18 [ 2 ] = 0x00 ;
memcpy ( V_18 + 3 , V_32 + V_16 * 4 , 4 ) ;
V_19 = F_5 ( V_15 , V_18 , 7 ) ;
if ( V_19 < 0 )
return V_19 ;
else if ( V_19 != 7 )
return - V_21 ;
F_14 ( F_16 ( V_16 ) , V_18 ) ;
F_14 ( V_26 + V_16 , V_18 + 2 ) ;
V_19 = F_5 ( V_15 , V_18 , 4 ) ;
if ( V_19 < 0 )
return V_19 ;
else if ( V_19 != 4 )
return - V_21 ;
}
return F_17 ( V_33 -> V_35 , V_6 ,
V_36 , V_36 ) ;
}
static int F_18 ( struct V_37 * V_38 , unsigned int V_39 ,
unsigned int V_40 )
{
struct V_33 * V_33 = F_19 ( V_38 ) ;
int V_19 ;
F_20 ( V_33 -> V_31 ) ;
if ( V_39 != V_41 &&
F_21 ( V_33 -> V_42 [ 0 ] ) &&
F_21 ( V_33 -> V_42 [ 1 ] ) ) {
switch ( V_39 ) {
case 64 :
F_22 ( V_33 -> V_42 [ 0 ] , 0 ) ;
F_22 ( V_33 -> V_42 [ 1 ] , 0 ) ;
break;
case 256 :
F_22 ( V_33 -> V_42 [ 0 ] , 0 ) ;
F_22 ( V_33 -> V_42 [ 1 ] , 1 ) ;
break;
case 384 :
F_22 ( V_33 -> V_42 [ 0 ] , 1 ) ;
F_22 ( V_33 -> V_42 [ 1 ] , 0 ) ;
break;
case 0 :
case 512 :
F_22 ( V_33 -> V_42 [ 0 ] , 1 ) ;
F_22 ( V_33 -> V_42 [ 1 ] , 1 ) ;
break;
}
}
V_33 -> V_43 = V_39 ;
if ( F_21 ( V_33 -> V_44 ) ) {
F_22 ( V_33 -> V_44 , 0 ) ;
F_23 ( 1 ) ;
F_22 ( V_33 -> V_44 , 1 ) ;
F_24 ( 85 ) ;
}
if ( V_39 != V_41 ) {
V_19 = F_25 ( V_33 -> V_31 , V_40 ) ;
if ( V_19 ) {
F_26 ( V_38 -> V_2 , L_2 ) ;
return V_19 ;
}
}
F_27 ( V_33 -> V_35 , V_10 , V_45 ) ;
F_27 ( V_33 -> V_35 , V_6 , V_46 ) ;
F_28 ( V_33 -> V_35 ) ;
F_29 ( V_33 -> V_35 ) ;
return 0 ;
}
static int F_30 ( struct V_37 * V_38 ,
struct V_47 * V_48 )
{
struct V_33 * V_33 = F_19 ( V_38 ) ;
unsigned int V_49 = V_50 ;
unsigned int V_34 ;
switch ( F_31 ( V_48 ) ) {
case 16 :
V_34 = V_51 ;
break;
case 20 :
V_34 = V_52 ;
break;
case 24 :
V_34 = V_53 ;
break;
default:
return - V_20 ;
}
if ( V_33 -> V_54 == V_55 ) {
switch ( F_31 ( V_48 ) ) {
case 16 :
V_34 |= V_56 ;
break;
case 20 :
V_34 |= V_57 ;
break;
case 24 :
V_34 |= V_58 ;
break;
}
V_49 |= V_59 ;
}
F_17 ( V_33 -> V_35 , V_7 , V_49 , V_34 ) ;
return 0 ;
}
static int F_32 ( struct V_37 * V_38 ,
struct V_47 * V_48 )
{
struct V_33 * V_33 = F_19 ( V_38 ) ;
unsigned int V_34 ;
if ( V_33 -> V_54 != V_55 )
return 0 ;
switch ( F_31 ( V_48 ) ) {
case 16 :
V_34 = V_60 ;
break;
case 20 :
V_34 = V_61 ;
break;
case 24 :
V_34 = V_62 ;
break;
default:
return - V_20 ;
}
F_17 ( V_33 -> V_35 , V_11 ,
V_63 , V_34 ) ;
return 0 ;
}
static int F_33 ( struct V_64 * V_65 ,
struct V_47 * V_48 , struct V_66 * V_67 )
{
struct V_37 * V_38 = V_67 -> V_38 ;
struct V_33 * V_33 = F_19 ( V_38 ) ;
unsigned int V_39 = V_33 -> V_68 / F_34 ( V_48 ) ;
unsigned int V_34 ;
int V_19 ;
if ( V_39 != V_33 -> V_43 ) {
V_19 = F_18 ( V_38 , V_39 , F_34 ( V_48 ) ) ;
if ( V_19 < 0 )
return V_19 ;
}
switch ( F_34 ( V_48 ) ) {
case 192000 :
V_34 = V_69 ;
break;
case 96000 :
V_34 = V_70 ;
break;
case 48000 :
V_34 = V_71 ;
break;
default:
return - V_20 ;
}
F_17 ( V_33 -> V_35 , V_6 ,
V_72 , V_34 ) ;
if ( V_65 -> V_73 == V_74 )
return F_32 ( V_38 , V_48 ) ;
else
return F_30 ( V_38 , V_48 ) ;
}
static int F_35 ( struct V_66 * V_75 ,
unsigned int V_76 )
{
struct V_37 * V_38 = V_75 -> V_38 ;
struct V_33 * V_33 = F_19 ( V_38 ) ;
unsigned int V_77 = 0x00 , V_78 = 0x00 ;
bool V_79 ;
switch ( V_76 & V_80 ) {
case V_81 :
V_78 |= V_82 | V_83
| V_84 ;
break;
case V_85 :
break;
default:
return - V_20 ;
}
switch ( V_76 & V_86 ) {
case V_87 :
V_79 = false ;
break;
case V_88 :
V_79 = true ;
break;
case V_89 :
V_79 = false ;
V_77 |= V_90 ;
V_78 |= V_91 ;
break;
case V_92 :
V_79 = true ;
V_77 |= V_90 ;
V_78 |= V_91 ;
break;
default:
return - V_20 ;
}
switch ( V_76 & V_93 ) {
case V_94 :
break;
case V_95 :
V_77 |= V_96 ;
V_78 |= V_97 ;
V_79 = ! V_79 ;
break;
case V_55 :
V_77 |= V_62 ;
V_78 |= V_58 ;
V_79 = ! V_79 ;
break;
default:
return - V_20 ;
}
if ( V_79 ) {
V_78 |= V_98 ;
V_77 |= V_99 ;
}
V_33 -> V_54 = V_76 & V_93 ;
F_27 ( V_33 -> V_35 , V_11 , V_77 ) ;
F_17 ( V_33 -> V_35 , V_7 ,
~ V_50 , V_78 ) ;
return 0 ;
}
static int F_36 ( struct V_37 * V_38 ,
enum V_100 V_101 )
{
unsigned int V_49 = V_102 | V_103 ;
struct V_33 * V_33 = F_19 ( V_38 ) ;
switch ( V_101 ) {
case V_104 :
break;
case V_105 :
break;
case V_106 :
F_17 ( V_33 -> V_35 ,
V_8 , V_49 , 0x00 ) ;
break;
case V_107 :
F_17 ( V_33 -> V_35 ,
V_8 , V_49 , V_49 ) ;
break;
}
return 0 ;
}
static int F_37 ( struct V_66 * V_67 , int V_108 )
{
struct V_37 * V_38 = V_67 -> V_38 ;
unsigned int V_49 = V_109 ;
struct V_33 * V_33 = F_19 ( V_38 ) ;
unsigned int V_34 ;
if ( V_108 )
V_34 = 0 ;
else
V_34 = V_49 ;
F_17 ( V_33 -> V_35 , V_6 , V_49 , V_34 ) ;
return 0 ;
}
static int F_38 ( struct V_37 * V_38 , int V_110 ,
int V_111 , unsigned int V_112 , int V_113 )
{
unsigned int V_34 ;
struct V_33 * V_33 = F_19 ( V_38 ) ;
switch ( V_110 ) {
case V_114 :
V_34 = 0x0 ;
break;
case V_115 :
V_34 = V_116 ;
break;
default:
return - V_20 ;
}
F_17 ( V_33 -> V_35 , V_9 ,
V_116 , V_34 ) ;
V_33 -> V_68 = V_112 ;
return 0 ;
}
static int F_39 ( struct V_64 * V_65 ,
struct V_66 * V_67 )
{
struct V_33 * V_33 = F_19 ( V_67 -> V_38 ) ;
return F_40 ( V_33 -> V_31 , V_65 ) ;
}
static int F_41 ( struct V_37 * V_38 )
{
int V_16 , V_19 ;
unsigned int V_34 ;
struct V_33 * V_33 = F_19 ( V_38 ) ;
V_19 = F_42 ( V_33 -> V_31 , & V_38 -> V_117 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_43 ( F_8 ( V_33 -> V_118 ) ,
V_33 -> V_118 ) ;
if ( V_19 < 0 ) {
F_2 ( V_38 -> V_2 , L_3 , V_19 ) ;
return V_19 ;
}
V_33 -> V_43 = V_41 ;
V_19 = F_18 ( V_38 , V_33 -> V_43 , 0 ) ;
if ( V_19 < 0 )
goto V_119;
V_34 = 0 ;
for ( V_16 = 0 ; V_16 < 6 ; V_16 ++ )
V_34 |= V_33 -> V_120 [ V_16 ] << ( V_16 * 4 ) ;
F_27 ( V_33 -> V_35 , V_4 , V_34 ) ;
V_34 = 0 ;
for ( V_16 = 0 ; V_16 < 6 ; V_16 ++ )
V_34 |= V_33 -> V_120 [ V_16 + 6 ] << ( V_16 * 4 ) ;
F_27 ( V_33 -> V_35 , V_5 , V_34 ) ;
return 0 ;
V_119:
F_44 ( F_8 ( V_33 -> V_118 ) , V_33 -> V_118 ) ;
return V_19 ;
}
static int F_45 ( struct V_37 * V_38 )
{
struct V_33 * V_33 = F_19 ( V_38 ) ;
if ( F_21 ( V_33 -> V_44 ) )
F_22 ( V_33 -> V_44 , 0 ) ;
F_44 ( F_8 ( V_33 -> V_118 ) , V_33 -> V_118 ) ;
return 0 ;
}
static int F_46 ( struct V_37 * V_38 )
{
struct V_33 * V_33 = F_19 ( V_38 ) ;
F_44 ( F_8 ( V_33 -> V_118 ) ,
V_33 -> V_118 ) ;
return 0 ;
}
static int F_47 ( struct V_37 * V_38 )
{
struct V_33 * V_33 = F_19 ( V_38 ) ;
int V_19 ;
V_19 = F_43 ( F_8 ( V_33 -> V_118 ) ,
V_33 -> V_118 ) ;
if ( V_19 < 0 ) {
F_2 ( V_38 -> V_2 , L_3 , V_19 ) ;
return V_19 ;
}
return F_18 ( V_38 , V_33 -> V_43 , 0 ) ;
}
static int F_48 ( struct V_14 * V_15 ,
const struct V_121 * V_122 )
{
struct V_33 * V_33 ;
struct V_1 * V_2 = & V_15 -> V_2 ;
int V_44 = - V_20 ;
int V_42 [ 2 ] = { - V_20 , - V_20 } ;
int V_19 , V_16 ;
V_33 = F_49 ( V_2 , sizeof( * V_33 ) , V_123 ) ;
if ( ! V_33 )
return - V_124 ;
for ( V_16 = 0 ; V_16 < F_8 ( V_125 ) ; V_16 ++ )
V_33 -> V_118 [ V_16 ] . V_126 = V_125 [ V_16 ] ;
V_19 = F_50 ( V_2 , F_8 ( V_33 -> V_118 ) ,
V_33 -> V_118 ) ;
if ( V_19 < 0 ) {
F_2 ( V_2 , L_4 , V_19 ) ;
return V_19 ;
}
V_19 = F_43 ( F_8 ( V_33 -> V_118 ) ,
V_33 -> V_118 ) ;
if ( V_19 < 0 ) {
F_2 ( V_2 , L_3 , V_19 ) ;
return V_19 ;
}
V_33 -> V_15 = V_15 ;
V_33 -> V_35 = F_51 ( V_2 , NULL , V_15 ,
& V_127 ) ;
if ( F_52 ( V_33 -> V_35 ) ) {
V_19 = F_53 ( V_33 -> V_35 ) ;
goto V_119;
}
if ( V_2 -> V_128 ) {
V_44 = F_54 ( V_2 -> V_128 , L_5 , 0 ) ;
if ( V_44 < 0 && V_44 != - V_129 ) {
V_19 = V_44 ;
goto V_119;
}
V_42 [ 0 ] = F_54 ( V_2 -> V_128 ,
L_6 , 0 ) ;
if ( V_42 [ 0 ] < 0 && V_42 [ 0 ] != - V_129 ) {
V_19 = V_42 [ 0 ] ;
goto V_119;
}
V_42 [ 1 ] = F_54 ( V_2 -> V_128 ,
L_6 , 1 ) ;
if ( V_42 [ 1 ] < 0 && V_42 [ 1 ] != - V_129 ) {
V_19 = V_42 [ 1 ] ;
goto V_119;
}
F_55 ( V_2 -> V_128 , L_7 ,
& V_33 -> V_43 ) ;
F_56 ( V_2 -> V_128 , L_8 ,
V_33 -> V_120 ,
F_8 ( V_33 -> V_120 ) ) ;
}
if ( F_21 ( V_44 ) ) {
V_19 = F_57 ( V_2 , V_44 , V_130 ,
L_9 ) ;
if ( V_19 < 0 )
goto V_119;
}
if ( F_21 ( V_42 [ 0 ] ) &&
F_21 ( V_42 [ 1 ] ) ) {
V_19 = F_57 ( V_2 , V_42 [ 0 ] ,
V_130 ,
L_10 ) ;
if ( V_19 < 0 )
goto V_119;
V_19 = F_57 ( V_2 , V_42 [ 1 ] ,
V_130 ,
L_11 ) ;
if ( V_19 < 0 )
goto V_119;
}
V_33 -> V_44 = V_44 ;
V_33 -> V_42 [ 0 ] = V_42 [ 0 ] ;
V_33 -> V_42 [ 1 ] = V_42 [ 1 ] ;
F_58 ( V_15 , V_33 ) ;
V_33 -> V_31 = F_59 ( V_15 ,
& V_131 , V_132 ) ;
if ( F_52 ( V_33 -> V_31 ) ) {
V_19 = F_53 ( V_33 -> V_31 ) ;
goto V_119;
}
V_19 = F_60 ( & V_15 -> V_2 , & V_133 ,
& V_134 , 1 ) ;
V_119:
F_44 ( F_8 ( V_33 -> V_118 ) , V_33 -> V_118 ) ;
return V_19 ;
}
static int F_61 ( struct V_14 * V_15 )
{
F_62 ( & V_15 -> V_2 ) ;
return 0 ;
}
