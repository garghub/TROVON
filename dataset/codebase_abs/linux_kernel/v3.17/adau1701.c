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
static int F_9 ( struct V_31 * V_32 , unsigned int V_33 )
{
struct V_34 * V_34 = F_10 ( V_32 ) ;
struct V_14 * V_15 = F_11 ( V_32 -> V_2 ) ;
int V_19 ;
if ( V_33 != V_35 &&
F_12 ( V_34 -> V_36 [ 0 ] ) &&
F_12 ( V_34 -> V_36 [ 1 ] ) ) {
switch ( V_33 ) {
case 64 :
F_13 ( V_34 -> V_36 [ 0 ] , 0 ) ;
F_13 ( V_34 -> V_36 [ 1 ] , 0 ) ;
break;
case 256 :
F_13 ( V_34 -> V_36 [ 0 ] , 0 ) ;
F_13 ( V_34 -> V_36 [ 1 ] , 1 ) ;
break;
case 384 :
F_13 ( V_34 -> V_36 [ 0 ] , 1 ) ;
F_13 ( V_34 -> V_36 [ 1 ] , 0 ) ;
break;
case 0 :
case 512 :
F_13 ( V_34 -> V_36 [ 0 ] , 1 ) ;
F_13 ( V_34 -> V_36 [ 1 ] , 1 ) ;
break;
}
}
V_34 -> V_37 = V_33 ;
if ( F_12 ( V_34 -> V_38 ) ) {
F_13 ( V_34 -> V_38 , 0 ) ;
F_14 ( 1 ) ;
F_13 ( V_34 -> V_38 , 1 ) ;
F_15 ( 85 ) ;
}
if ( V_33 != V_35 ) {
V_19 = F_16 ( V_15 , V_39 ) ;
if ( V_19 ) {
F_17 ( V_32 -> V_2 , L_2 ) ;
return V_19 ;
}
}
F_18 ( V_34 -> V_40 , V_10 , V_41 ) ;
F_18 ( V_34 -> V_40 , V_6 , V_42 ) ;
F_19 ( V_34 -> V_40 ) ;
F_20 ( V_34 -> V_40 ) ;
return 0 ;
}
static int F_21 ( struct V_31 * V_32 ,
struct V_43 * V_44 )
{
struct V_34 * V_34 = F_10 ( V_32 ) ;
unsigned int V_45 = V_46 ;
unsigned int V_47 ;
switch ( F_22 ( V_44 ) ) {
case 16 :
V_47 = V_48 ;
break;
case 20 :
V_47 = V_49 ;
break;
case 24 :
V_47 = V_50 ;
break;
default:
return - V_20 ;
}
if ( V_34 -> V_51 == V_52 ) {
switch ( F_22 ( V_44 ) ) {
case 16 :
V_47 |= V_53 ;
break;
case 20 :
V_47 |= V_54 ;
break;
case 24 :
V_47 |= V_55 ;
break;
}
V_45 |= V_56 ;
}
F_23 ( V_34 -> V_40 , V_7 , V_45 , V_47 ) ;
return 0 ;
}
static int F_24 ( struct V_31 * V_32 ,
struct V_43 * V_44 )
{
struct V_34 * V_34 = F_10 ( V_32 ) ;
unsigned int V_47 ;
if ( V_34 -> V_51 != V_52 )
return 0 ;
switch ( F_22 ( V_44 ) ) {
case 16 :
V_47 = V_57 ;
break;
case 20 :
V_47 = V_58 ;
break;
case 24 :
V_47 = V_59 ;
break;
default:
return - V_20 ;
}
F_23 ( V_34 -> V_40 , V_11 ,
V_60 , V_47 ) ;
return 0 ;
}
static int F_25 ( struct V_61 * V_62 ,
struct V_43 * V_44 , struct V_63 * V_64 )
{
struct V_31 * V_32 = V_64 -> V_32 ;
struct V_34 * V_34 = F_10 ( V_32 ) ;
unsigned int V_33 = V_34 -> V_65 / F_26 ( V_44 ) ;
unsigned int V_47 ;
int V_19 ;
if ( V_33 != V_34 -> V_37 ) {
V_19 = F_9 ( V_32 , V_33 ) ;
if ( V_19 < 0 )
return V_19 ;
}
switch ( F_26 ( V_44 ) ) {
case 192000 :
V_47 = V_66 ;
break;
case 96000 :
V_47 = V_67 ;
break;
case 48000 :
V_47 = V_68 ;
break;
default:
return - V_20 ;
}
F_23 ( V_34 -> V_40 , V_6 ,
V_69 , V_47 ) ;
if ( V_62 -> V_70 == V_71 )
return F_24 ( V_32 , V_44 ) ;
else
return F_21 ( V_32 , V_44 ) ;
}
static int F_27 ( struct V_63 * V_72 ,
unsigned int V_73 )
{
struct V_31 * V_32 = V_72 -> V_32 ;
struct V_34 * V_34 = F_10 ( V_32 ) ;
unsigned int V_74 = 0x00 , V_75 = 0x00 ;
bool V_76 ;
switch ( V_73 & V_77 ) {
case V_78 :
V_75 |= V_79 | V_80
| V_81 ;
break;
case V_82 :
break;
default:
return - V_20 ;
}
switch ( V_73 & V_83 ) {
case V_84 :
V_76 = false ;
break;
case V_85 :
V_76 = true ;
break;
case V_86 :
V_76 = false ;
V_74 |= V_87 ;
V_75 |= V_88 ;
break;
case V_89 :
V_76 = true ;
V_74 |= V_87 ;
V_75 |= V_88 ;
break;
default:
return - V_20 ;
}
switch ( V_73 & V_90 ) {
case V_91 :
break;
case V_92 :
V_74 |= V_93 ;
V_75 |= V_94 ;
V_76 = ! V_76 ;
break;
case V_52 :
V_74 |= V_59 ;
V_75 |= V_55 ;
V_76 = ! V_76 ;
break;
default:
return - V_20 ;
}
if ( V_76 ) {
V_75 |= V_95 ;
V_74 |= V_96 ;
}
V_34 -> V_51 = V_73 & V_90 ;
F_18 ( V_34 -> V_40 , V_11 , V_74 ) ;
F_23 ( V_34 -> V_40 , V_7 ,
~ V_46 , V_75 ) ;
return 0 ;
}
static int F_28 ( struct V_31 * V_32 ,
enum V_97 V_98 )
{
unsigned int V_45 = V_99 | V_100 ;
struct V_34 * V_34 = F_10 ( V_32 ) ;
switch ( V_98 ) {
case V_101 :
break;
case V_102 :
break;
case V_103 :
F_23 ( V_34 -> V_40 ,
V_8 , V_45 , 0x00 ) ;
break;
case V_104 :
F_23 ( V_34 -> V_40 ,
V_8 , V_45 , V_45 ) ;
break;
}
V_32 -> V_105 . V_106 = V_98 ;
return 0 ;
}
static int F_29 ( struct V_63 * V_64 , int V_107 )
{
struct V_31 * V_32 = V_64 -> V_32 ;
unsigned int V_45 = V_108 ;
struct V_34 * V_34 = F_10 ( V_32 ) ;
unsigned int V_47 ;
if ( V_107 )
V_47 = 0 ;
else
V_47 = V_45 ;
F_23 ( V_34 -> V_40 , V_6 , V_45 , V_47 ) ;
return 0 ;
}
static int F_30 ( struct V_31 * V_32 , int V_109 ,
int V_110 , unsigned int V_111 , int V_112 )
{
unsigned int V_47 ;
struct V_34 * V_34 = F_10 ( V_32 ) ;
switch ( V_109 ) {
case V_113 :
V_47 = 0x0 ;
break;
case V_114 :
V_47 = V_115 ;
break;
default:
return - V_20 ;
}
F_23 ( V_34 -> V_40 , V_9 ,
V_115 , V_47 ) ;
V_34 -> V_65 = V_111 ;
return 0 ;
}
static int F_31 ( struct V_31 * V_32 )
{
int V_16 , V_19 ;
unsigned int V_47 ;
struct V_34 * V_34 = F_10 ( V_32 ) ;
V_34 -> V_37 = V_35 ;
V_19 = F_9 ( V_32 , V_34 -> V_37 ) ;
if ( V_19 < 0 )
return V_19 ;
V_47 = 0 ;
for ( V_16 = 0 ; V_16 < 6 ; V_16 ++ )
V_47 |= V_34 -> V_116 [ V_16 ] << ( V_16 * 4 ) ;
F_18 ( V_34 -> V_40 , V_4 , V_47 ) ;
V_47 = 0 ;
for ( V_16 = 0 ; V_16 < 6 ; V_16 ++ )
V_47 |= V_34 -> V_116 [ V_16 + 6 ] << ( V_16 * 4 ) ;
F_18 ( V_34 -> V_40 , V_5 , V_47 ) ;
return 0 ;
}
static int F_32 ( struct V_14 * V_15 ,
const struct V_117 * V_118 )
{
struct V_34 * V_34 ;
struct V_1 * V_2 = & V_15 -> V_2 ;
int V_38 = - V_20 ;
int V_36 [ 2 ] = { - V_20 , - V_20 } ;
int V_19 ;
V_34 = F_33 ( V_2 , sizeof( * V_34 ) , V_119 ) ;
if ( ! V_34 )
return - V_120 ;
V_34 -> V_40 = F_34 ( V_2 , NULL , V_15 ,
& V_121 ) ;
if ( F_35 ( V_34 -> V_40 ) )
return F_36 ( V_34 -> V_40 ) ;
if ( V_2 -> V_122 ) {
V_38 = F_37 ( V_2 -> V_122 , L_3 , 0 ) ;
if ( V_38 < 0 && V_38 != - V_123 )
return V_38 ;
V_36 [ 0 ] = F_37 ( V_2 -> V_122 ,
L_4 , 0 ) ;
if ( V_36 [ 0 ] < 0 && V_36 [ 0 ] != - V_123 )
return V_36 [ 0 ] ;
V_36 [ 1 ] = F_37 ( V_2 -> V_122 ,
L_4 , 1 ) ;
if ( V_36 [ 1 ] < 0 && V_36 [ 1 ] != - V_123 )
return V_36 [ 1 ] ;
F_38 ( V_2 -> V_122 , L_5 ,
& V_34 -> V_37 ) ;
F_39 ( V_2 -> V_122 , L_6 ,
V_34 -> V_116 ,
F_8 ( V_34 -> V_116 ) ) ;
}
if ( F_12 ( V_38 ) ) {
V_19 = F_40 ( V_2 , V_38 , V_124 ,
L_7 ) ;
if ( V_19 < 0 )
return V_19 ;
}
if ( F_12 ( V_36 [ 0 ] ) &&
F_12 ( V_36 [ 1 ] ) ) {
V_19 = F_40 ( V_2 , V_36 [ 0 ] ,
V_124 ,
L_8 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_40 ( V_2 , V_36 [ 1 ] ,
V_124 ,
L_9 ) ;
if ( V_19 < 0 )
return V_19 ;
}
V_34 -> V_38 = V_38 ;
V_34 -> V_36 [ 0 ] = V_36 [ 0 ] ;
V_34 -> V_36 [ 1 ] = V_36 [ 1 ] ;
F_41 ( V_15 , V_34 ) ;
V_19 = F_42 ( & V_15 -> V_2 , & V_125 ,
& V_126 , 1 ) ;
return V_19 ;
}
static int F_43 ( struct V_14 * V_15 )
{
F_44 ( & V_15 -> V_2 ) ;
return 0 ;
}
