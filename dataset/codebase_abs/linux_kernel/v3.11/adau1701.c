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
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
* V_13 |= V_23 [ V_16 ] << ( V_16 * 8 ) ;
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
T_2 V_43 )
{
struct V_34 * V_34 = F_10 ( V_32 ) ;
unsigned int V_44 = V_45 ;
unsigned int V_46 ;
switch ( V_43 ) {
case V_47 :
V_46 = V_48 ;
break;
case V_49 :
V_46 = V_50 ;
break;
case V_51 :
V_46 = V_52 ;
break;
default:
return - V_20 ;
}
if ( V_34 -> V_53 == V_54 ) {
switch ( V_43 ) {
case V_47 :
V_46 |= V_55 ;
break;
case V_49 :
V_46 |= V_56 ;
break;
case V_51 :
V_46 |= V_57 ;
break;
}
V_44 |= V_58 ;
}
F_22 ( V_34 -> V_40 , V_7 , V_44 , V_46 ) ;
return 0 ;
}
static int F_23 ( struct V_31 * V_32 ,
T_2 V_43 )
{
struct V_34 * V_34 = F_10 ( V_32 ) ;
unsigned int V_46 ;
if ( V_34 -> V_53 != V_54 )
return 0 ;
switch ( V_43 ) {
case V_47 :
V_46 = V_59 ;
break;
case V_49 :
V_46 = V_60 ;
break;
case V_51 :
V_46 = V_61 ;
break;
default:
return - V_20 ;
}
F_22 ( V_34 -> V_40 , V_11 ,
V_62 , V_46 ) ;
return 0 ;
}
static int F_24 ( struct V_63 * V_64 ,
struct V_65 * V_66 , struct V_67 * V_68 )
{
struct V_31 * V_32 = V_68 -> V_32 ;
struct V_34 * V_34 = F_10 ( V_32 ) ;
unsigned int V_33 = V_34 -> V_69 / F_25 ( V_66 ) ;
T_2 V_43 ;
unsigned int V_46 ;
int V_19 ;
if ( V_33 != V_34 -> V_37 ) {
V_19 = F_9 ( V_32 , V_33 ) ;
if ( V_19 < 0 )
return V_19 ;
}
switch ( F_25 ( V_66 ) ) {
case 192000 :
V_46 = V_70 ;
break;
case 96000 :
V_46 = V_71 ;
break;
case 48000 :
V_46 = V_72 ;
break;
default:
return - V_20 ;
}
F_22 ( V_34 -> V_40 , V_6 ,
V_73 , V_46 ) ;
V_43 = F_26 ( V_66 ) ;
if ( V_64 -> V_74 == V_75 )
return F_23 ( V_32 , V_43 ) ;
else
return F_21 ( V_32 , V_43 ) ;
}
static int F_27 ( struct V_67 * V_76 ,
unsigned int V_77 )
{
struct V_31 * V_32 = V_76 -> V_32 ;
struct V_34 * V_34 = F_10 ( V_32 ) ;
unsigned int V_78 = 0x00 , V_79 = 0x00 ;
bool V_80 ;
switch ( V_77 & V_81 ) {
case V_82 :
V_79 |= V_83 | V_84
| V_85 ;
break;
case V_86 :
break;
default:
return - V_20 ;
}
switch ( V_77 & V_87 ) {
case V_88 :
V_80 = false ;
break;
case V_89 :
V_80 = true ;
break;
case V_90 :
V_80 = false ;
V_78 |= V_91 ;
V_79 |= V_92 ;
break;
case V_93 :
V_80 = true ;
V_78 |= V_91 ;
V_79 |= V_92 ;
break;
default:
return - V_20 ;
}
switch ( V_77 & V_94 ) {
case V_95 :
break;
case V_96 :
V_78 |= V_97 ;
V_79 |= V_98 ;
V_80 = ! V_80 ;
break;
case V_54 :
V_78 |= V_61 ;
V_79 |= V_57 ;
V_80 = ! V_80 ;
break;
default:
return - V_20 ;
}
if ( V_80 ) {
V_79 |= V_99 ;
V_78 |= V_100 ;
}
V_34 -> V_53 = V_77 & V_94 ;
F_18 ( V_34 -> V_40 , V_11 , V_78 ) ;
F_22 ( V_34 -> V_40 , V_7 ,
~ V_45 , V_79 ) ;
return 0 ;
}
static int F_28 ( struct V_31 * V_32 ,
enum V_101 V_102 )
{
unsigned int V_44 = V_103 | V_104 ;
struct V_34 * V_34 = F_10 ( V_32 ) ;
switch ( V_102 ) {
case V_105 :
break;
case V_106 :
break;
case V_107 :
F_22 ( V_34 -> V_40 ,
V_8 , V_44 , 0x00 ) ;
break;
case V_108 :
F_22 ( V_34 -> V_40 ,
V_8 , V_44 , V_44 ) ;
break;
}
V_32 -> V_109 . V_110 = V_102 ;
return 0 ;
}
static int F_29 ( struct V_67 * V_68 , int V_111 )
{
struct V_31 * V_32 = V_68 -> V_32 ;
unsigned int V_44 = V_112 ;
struct V_34 * V_34 = F_10 ( V_32 ) ;
unsigned int V_46 ;
if ( V_111 )
V_46 = 0 ;
else
V_46 = V_44 ;
F_22 ( V_34 -> V_40 , V_6 , V_44 , V_46 ) ;
return 0 ;
}
static int F_30 ( struct V_31 * V_32 , int V_113 ,
int V_114 , unsigned int V_115 , int V_116 )
{
unsigned int V_46 ;
struct V_34 * V_34 = F_10 ( V_32 ) ;
switch ( V_113 ) {
case V_117 :
V_46 = 0x0 ;
break;
case V_118 :
V_46 = V_119 ;
break;
default:
return - V_20 ;
}
F_22 ( V_34 -> V_40 , V_9 ,
V_119 , V_46 ) ;
V_34 -> V_69 = V_115 ;
return 0 ;
}
static int F_31 ( struct V_31 * V_32 )
{
int V_16 , V_19 ;
unsigned int V_46 ;
struct V_34 * V_34 = F_10 ( V_32 ) ;
V_34 -> V_37 = V_35 ;
V_19 = F_9 ( V_32 , V_34 -> V_37 ) ;
if ( V_19 < 0 )
return V_19 ;
V_46 = 0 ;
for ( V_16 = 0 ; V_16 < 6 ; V_16 ++ )
V_46 |= V_34 -> V_120 [ V_16 ] << ( V_16 * 4 ) ;
F_18 ( V_34 -> V_40 , V_4 , V_46 ) ;
V_46 = 0 ;
for ( V_16 = 0 ; V_16 < 6 ; V_16 ++ )
V_46 |= V_34 -> V_120 [ V_16 + 6 ] << ( V_16 * 4 ) ;
F_18 ( V_34 -> V_40 , V_5 , V_46 ) ;
return 0 ;
}
static int F_32 ( struct V_14 * V_15 ,
const struct V_121 * V_122 )
{
struct V_34 * V_34 ;
struct V_1 * V_2 = & V_15 -> V_2 ;
int V_38 = - V_20 ;
int V_36 [ 2 ] = { - V_20 , - V_20 } ;
int V_19 ;
V_34 = F_33 ( V_2 , sizeof( * V_34 ) , V_123 ) ;
if ( ! V_34 )
return - V_124 ;
V_34 -> V_40 = F_34 ( V_2 , NULL , V_15 ,
& V_125 ) ;
if ( F_35 ( V_34 -> V_40 ) )
return F_36 ( V_34 -> V_40 ) ;
if ( V_2 -> V_126 ) {
V_38 = F_37 ( V_2 -> V_126 , L_3 , 0 ) ;
if ( V_38 < 0 && V_38 != - V_127 )
return V_38 ;
V_36 [ 0 ] = F_37 ( V_2 -> V_126 ,
L_4 , 0 ) ;
if ( V_36 [ 0 ] < 0 && V_36 [ 0 ] != - V_127 )
return V_36 [ 0 ] ;
V_36 [ 1 ] = F_37 ( V_2 -> V_126 ,
L_4 , 1 ) ;
if ( V_36 [ 1 ] < 0 && V_36 [ 1 ] != - V_127 )
return V_36 [ 1 ] ;
F_38 ( V_2 -> V_126 , L_5 ,
& V_34 -> V_37 ) ;
F_39 ( V_2 -> V_126 , L_6 ,
V_34 -> V_120 ,
F_8 ( V_34 -> V_120 ) ) ;
}
if ( F_12 ( V_38 ) ) {
V_19 = F_40 ( V_2 , V_38 , V_128 ,
L_7 ) ;
if ( V_19 < 0 )
return V_19 ;
}
if ( F_12 ( V_36 [ 0 ] ) &&
F_12 ( V_36 [ 1 ] ) ) {
V_19 = F_40 ( V_2 , V_36 [ 0 ] ,
V_128 ,
L_8 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_40 ( V_2 , V_36 [ 1 ] ,
V_128 ,
L_9 ) ;
if ( V_19 < 0 )
return V_19 ;
}
V_34 -> V_38 = V_38 ;
V_34 -> V_36 [ 0 ] = V_36 [ 0 ] ;
V_34 -> V_36 [ 1 ] = V_36 [ 1 ] ;
F_41 ( V_15 , V_34 ) ;
V_19 = F_42 ( & V_15 -> V_2 , & V_129 ,
& V_130 , 1 ) ;
return V_19 ;
}
static int F_43 ( struct V_14 * V_15 )
{
F_44 ( & V_15 -> V_2 ) ;
return 0 ;
}
