static T_1 F_1 ( int V_1 , void * V_2 )
{
return V_3 ;
}
int F_2 ( struct V_4 * V_5 ,
T_2 V_6 , T_2 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_5 ) ;
int V_10 ;
struct V_11 V_12 = {
. V_13 = V_9 -> V_14 ,
. V_15 = V_9 -> V_16 ,
. V_17 = 8 ,
. V_18 = 2 ,
} ;
F_4 ( & V_9 -> V_19 ) ;
V_9 -> V_14 [ 0 ] = F_5 ( V_6 ) ;
V_9 -> V_14 [ 1 ] = 0 ;
V_10 = F_6 ( V_9 -> V_20 , & V_12 , 1 ) ;
* V_7 = V_9 -> V_16 [ 1 ] ;
F_7 ( & V_9 -> V_19 ) ;
return V_10 ;
}
int F_8 ( struct V_4 * V_5 ,
T_2 V_6 ,
T_2 V_7 )
{
int V_10 ;
struct V_8 * V_9 = F_3 ( V_5 ) ;
F_4 ( & V_9 -> V_19 ) ;
V_9 -> V_14 [ 0 ] = F_9 ( V_6 ) ;
V_9 -> V_14 [ 1 ] = V_7 ;
V_10 = F_10 ( V_9 -> V_20 , V_9 -> V_14 , 2 ) ;
F_7 ( & V_9 -> V_19 ) ;
return V_10 ;
}
static int F_11 ( struct V_4 * V_5 ,
T_2 V_21 ,
T_3 V_22 )
{
int V_10 ;
struct V_8 * V_9 = F_3 ( V_5 ) ;
struct V_11 V_23 [] = { {
. V_13 = V_9 -> V_14 ,
. V_17 = 8 ,
. V_18 = 2 ,
. V_24 = 1 ,
} , {
. V_13 = V_9 -> V_14 + 2 ,
. V_17 = 8 ,
. V_18 = 2 ,
} ,
} ;
F_4 ( & V_9 -> V_19 ) ;
V_9 -> V_14 [ 0 ] = F_9 ( V_21 ) ;
V_9 -> V_14 [ 1 ] = V_22 & 0xFF ;
V_9 -> V_14 [ 2 ] = F_9 ( V_21 + 1 ) ;
V_9 -> V_14 [ 3 ] = ( V_22 >> 8 ) & 0xFF ;
V_10 = F_6 ( V_9 -> V_20 , V_23 , F_12 ( V_23 ) ) ;
F_7 ( & V_9 -> V_19 ) ;
return V_10 ;
}
static int F_13 ( struct V_4 * V_5 ,
T_2 V_21 ,
int * V_7 )
{
struct V_8 * V_9 = F_3 ( V_5 ) ;
int V_10 ;
T_3 V_25 ;
struct V_11 V_23 [] = { {
. V_13 = V_9 -> V_14 ,
. V_15 = V_9 -> V_16 ,
. V_17 = 8 ,
. V_18 = 2 ,
. V_24 = 1 ,
} , {
. V_13 = V_9 -> V_14 + 2 ,
. V_15 = V_9 -> V_16 + 2 ,
. V_17 = 8 ,
. V_18 = 2 ,
} ,
} ;
F_4 ( & V_9 -> V_19 ) ;
V_9 -> V_14 [ 0 ] = F_5 ( V_21 ) ;
V_9 -> V_14 [ 1 ] = 0 ;
V_9 -> V_14 [ 2 ] = F_5 ( V_21 + 1 ) ;
V_9 -> V_14 [ 3 ] = 0 ;
V_10 = F_6 ( V_9 -> V_20 , V_23 , F_12 ( V_23 ) ) ;
if ( V_10 ) {
F_14 ( & V_9 -> V_20 -> V_26 , L_1 ) ;
goto V_27;
}
V_25 = ( T_3 ) ( V_9 -> V_16 [ 1 ] ) | ( ( T_3 ) ( V_9 -> V_16 [ 3 ] ) << 8 ) ;
* V_7 = V_25 ;
V_27:
F_7 ( & V_9 -> V_19 ) ;
return V_10 ;
}
static int F_15 ( struct V_4 * V_5 ,
const struct V_28 * V_29 ,
enum V_30 type ,
enum V_31 V_32 ,
enum V_33 V_34 ,
int * V_7 , int * V_35 )
{
int V_10 ;
V_10 = F_13 ( V_5 , V_36 , V_7 ) ;
if ( V_10 )
return V_10 ;
return V_37 ;
}
static int F_16 ( struct V_4 * V_5 ,
const struct V_28 * V_29 ,
enum V_30 type ,
enum V_31 V_32 ,
enum V_33 V_34 ,
int V_7 , int V_35 )
{
T_4 V_22 = V_7 ;
return F_11 ( V_5 ,
V_36 ,
V_22 ) ;
}
static int F_17 ( struct V_4 * V_5 ,
struct V_28 const * V_29 ,
int V_7 ,
int V_35 ,
long V_38 )
{
int V_10 = - V_39 , V_40 ;
T_2 V_41 ;
T_5 V_42 ;
switch ( V_38 ) {
case V_43 :
if ( V_7 > 255 || V_7 < - 256 )
return - V_39 ;
V_42 = V_7 ;
V_40 = V_44 [ V_45 ] [ V_29 -> V_46 ] ;
V_10 = F_8 ( V_5 , V_40 , V_42 ) ;
break;
case V_47 :
if ( V_7 & ~ 0xFF )
return - V_39 ;
V_41 = V_7 ;
V_40 = V_44 [ V_48 ] [ V_29 -> V_46 ] ;
V_10 = F_8 ( V_5 , V_40 , V_41 ) ;
break;
}
return V_10 ;
}
static int F_18 ( struct V_4 * V_5 ,
struct V_28 const * V_29 ,
int * V_7 ,
int * V_35 ,
long V_38 )
{
T_2 V_49 ;
T_5 V_50 ;
T_6 V_10 = 0 ;
T_2 V_40 ;
switch ( V_38 ) {
case V_51 :
F_4 ( & V_5 -> V_52 ) ;
if ( V_5 -> V_53 == V_54 ) {
V_10 = - V_55 ;
} else {
V_40 = V_44
[ V_56 ] [ V_29 -> V_46 ] ;
V_10 = F_13 ( V_5 , V_40 , V_7 ) ;
}
F_7 ( & V_5 -> V_52 ) ;
if ( V_10 < 0 )
goto V_27;
return V_37 ;
case V_57 :
* V_7 = 0 ;
* V_35 = 9580 ;
return V_58 ;
case V_47 :
V_40 = V_44 [ V_48 ] [ V_29 -> V_46 ] ;
V_10 = F_2 ( V_5 , V_40 , & V_49 ) ;
if ( V_10 )
goto V_27;
* V_7 = V_49 ;
return V_37 ;
case V_43 :
V_40 = V_44 [ V_45 ] [ V_29 -> V_46 ] ;
V_10 = F_2 ( V_5 , V_40 , ( T_2 * ) & V_50 ) ;
* V_7 = V_50 ;
return V_37 ;
}
V_27:
return V_10 ;
}
static T_6 F_19 ( struct V_59 * V_26 ,
struct V_60 * V_61 ,
char * V_62 )
{
struct V_4 * V_5 = F_20 ( V_26 ) ;
int V_10 , V_18 = 0 ;
T_5 V_63 ;
V_10 = F_2 ( V_5 ,
V_64 ,
( T_2 * ) & V_63 ) ;
if ( V_10 )
return V_10 ;
V_63 &= V_65 ;
switch ( V_63 ) {
case V_66 :
V_18 = sprintf ( V_62 , L_2 ) ;
break;
case V_67 :
V_18 = sprintf ( V_62 , L_3 ) ;
break;
case V_68 :
V_18 = sprintf ( V_62 , L_4 ) ;
break;
case V_69 :
V_18 = sprintf ( V_62 , L_5 ) ;
break;
}
return V_18 ;
}
static T_6 F_21 ( struct V_59 * V_26 ,
struct V_60 * V_61 ,
const char * V_62 ,
T_7 V_18 )
{
struct V_4 * V_5 = F_20 ( V_26 ) ;
unsigned long V_7 ;
int V_10 ;
T_2 V_63 ;
V_10 = F_22 ( V_62 , 10 , & V_7 ) ;
if ( V_10 )
return V_10 ;
F_4 ( & V_5 -> V_52 ) ;
V_10 = F_2 ( V_5 ,
V_64 ,
& V_63 ) ;
if ( V_10 )
goto V_70;
V_63 &= ~ V_65 ;
switch ( V_7 ) {
case 280 :
V_63 |= V_66 ;
break;
case 560 :
V_63 |= V_67 ;
break;
case 1120 :
V_63 |= V_68 ;
break;
case 4480 :
V_63 |= V_69 ;
break;
default:
V_10 = - V_39 ;
goto V_70;
}
V_10 = F_8 ( V_5 ,
V_64 ,
V_63 ) ;
V_70:
F_7 ( & V_5 -> V_52 ) ;
return V_10 ? V_10 : V_18 ;
}
static int F_23 ( struct V_4 * V_5 )
{
struct V_8 * V_9 = F_3 ( V_5 ) ;
int V_10 ;
T_2 V_7 , V_71 ;
V_9 -> V_20 -> V_72 = V_73 ;
F_24 ( V_9 -> V_20 ) ;
V_7 = V_74 ;
V_10 = F_8 ( V_5 ,
V_64 ,
V_7 ) ;
if ( V_10 ) {
F_14 ( & V_9 -> V_20 -> V_26 , L_6 ) ;
goto V_75;
}
V_10 = F_8 ( V_5 ,
V_64 ,
V_7 ) ;
if ( V_10 ) {
F_14 ( & V_9 -> V_20 -> V_26 , L_6 ) ;
goto V_75;
}
V_10 = F_2 ( V_5 ,
V_64 ,
& V_71 ) ;
if ( V_10 || ( V_71 != V_7 ) ) {
F_14 ( & V_5 -> V_26 ,
L_7 , V_71 , V_7 ) ;
V_10 = - V_39 ;
goto V_75;
}
V_7 = V_76 ;
V_10 = F_8 ( V_5 ,
V_77 ,
V_7 ) ;
if ( V_10 ) {
F_14 ( & V_9 -> V_20 -> V_26 , L_8 ) ;
goto V_75;
}
V_7 = V_78 ;
V_10 = F_8 ( V_5 ,
V_79 ,
V_7 ) ;
if ( V_10 )
F_14 ( & V_9 -> V_20 -> V_26 , L_9 ) ;
V_75:
return V_10 ;
}
static T_1 F_25 ( int V_1 , void * V_2 )
{
struct V_4 * V_5 = V_2 ;
T_2 V_63 ;
T_8 V_80 = F_26 () ;
F_2 ( V_5 ,
V_81 ,
& V_63 ) ;
if ( V_63 & V_82 )
F_27 ( V_5 ,
F_28 ( V_83 ,
0 ,
V_84 ,
V_85 ,
V_86 ) ,
V_80 ) ;
if ( V_63 & V_87 )
F_27 ( V_5 ,
F_28 ( V_83 ,
0 ,
V_84 ,
V_85 ,
V_88 ) ,
V_80 ) ;
if ( V_63 & V_89 )
F_27 ( V_5 ,
F_28 ( V_83 ,
0 ,
V_90 ,
V_85 ,
V_86 ) ,
V_80 ) ;
if ( V_63 & V_91 )
F_27 ( V_5 ,
F_28 ( V_83 ,
0 ,
V_90 ,
V_85 ,
V_88 ) ,
V_80 ) ;
if ( V_63 & V_92 )
F_27 ( V_5 ,
F_28 ( V_83 ,
0 ,
V_93 ,
V_85 ,
V_86 ) ,
V_80 ) ;
if ( V_63 & V_94 )
F_27 ( V_5 ,
F_28 ( V_83 ,
0 ,
V_93 ,
V_85 ,
V_88 ) ,
V_80 ) ;
F_2 ( V_5 ,
V_95 ,
& V_63 ) ;
return V_96 ;
}
static int F_29 ( struct V_4 * V_5 ,
const struct V_28 * V_29 ,
enum V_30 type ,
enum V_31 V_32 )
{
T_2 V_7 ;
int V_10 ;
T_2 V_38 = ( 1 << ( V_29 -> V_97 * 2 + ( V_32 == V_86 ) ) ) ;
V_10 = F_2 ( V_5 ,
V_79 ,
& V_7 ) ;
if ( V_10 < 0 )
return V_10 ;
return ! ! ( V_7 & V_38 ) ;
}
int F_30 ( struct V_4 * V_5 )
{
int V_10 ;
T_2 V_98 , V_7 ;
V_10 = F_2 ( V_5 ,
V_77 ,
& V_98 ) ;
V_98 &= ~ V_99 ;
V_10 = F_8 ( V_5 ,
V_77 ,
V_98 ) ;
if ( V_10 )
goto V_27;
V_10 = F_2 ( V_5 ,
V_79 ,
& V_7 ) ;
if ( V_10 )
goto V_27;
V_7 &= ~ 0x3f ;
V_10 = F_8 ( V_5 ,
V_79 ,
V_7 ) ;
if ( V_10 )
goto V_27;
V_10 = V_98 ;
V_27:
return V_10 ;
}
static int F_31 ( struct V_4 * V_5 ,
const struct V_28 * V_29 ,
enum V_30 type ,
enum V_31 V_32 ,
int V_100 )
{
int V_10 = 0 ;
T_2 V_7 , V_98 ;
T_2 V_101 ;
bool V_102 = false ;
T_2 V_38 = ( 1 << ( V_29 -> V_97 * 2 + ( V_32 == V_86 ) ) ) ;
F_4 ( & V_5 -> V_52 ) ;
V_10 = F_2 ( V_5 ,
V_77 ,
& V_98 ) ;
if ( V_10 )
goto V_27;
V_10 = F_2 ( V_5 ,
V_79 ,
& V_7 ) ;
if ( V_10 < 0 )
goto V_27;
V_101 = V_7 & V_38 ;
if ( ! V_101 && V_100 ) {
V_102 = true ;
V_7 |= V_38 ;
} else if ( V_101 && ! V_100 ) {
V_102 = true ;
V_7 &= ~ V_38 ;
}
if ( V_102 ) {
V_10 = F_8 ( V_5 ,
V_79 ,
V_7 ) ;
if ( V_10 )
goto V_27;
V_98 = V_7 & 0x3f ?
( V_98 | V_99 ) :
( V_98 & ~ V_99 ) ;
V_10 = F_8 ( V_5 ,
V_77 ,
V_98 ) ;
if ( V_10 )
goto V_27;
}
V_27:
F_7 ( & V_5 -> V_52 ) ;
return V_10 ;
}
static int F_32 ( struct V_103 * V_104 )
{
int V_10 ;
struct V_8 * V_9 ;
struct V_4 * V_5 ;
V_5 = F_33 ( & V_104 -> V_26 , sizeof( * V_9 ) ) ;
if ( ! V_5 )
return - V_105 ;
V_9 = F_3 ( V_5 ) ;
F_34 ( V_104 , V_5 ) ;
V_9 -> V_20 = V_104 ;
V_9 -> V_106 = F_35 ( V_104 -> V_26 . V_107 , 0 ) ;
F_36 ( & V_9 -> V_19 ) ;
V_5 -> V_108 = V_104 -> V_26 . V_109 -> V_108 ;
V_5 -> V_26 . V_110 = & V_104 -> V_26 ;
V_5 -> V_34 = & V_111 ;
V_5 -> V_112 = V_113 ;
V_5 -> V_114 = F_12 ( V_113 ) ;
V_5 -> V_115 = V_116 ;
V_10 = F_37 ( V_5 ) ;
if ( V_10 )
return V_10 ;
if ( V_104 -> V_1 ) {
V_10 = F_38 ( V_9 -> V_20 -> V_1 ,
& V_117 ,
& F_25 ,
V_118 ,
L_10 ,
V_5 ) ;
if ( V_10 )
goto V_119;
V_10 = F_39 ( V_5 ) ;
if ( V_10 )
goto V_120;
}
V_10 = F_23 ( V_5 ) ;
if ( V_10 )
goto V_121;
V_10 = F_40 ( V_5 ) ;
if ( V_10 )
goto V_121;
return 0 ;
V_121:
if ( V_104 -> V_1 )
F_41 ( V_5 ) ;
V_120:
if ( V_104 -> V_1 )
F_42 ( V_9 -> V_20 -> V_1 , V_5 ) ;
V_119:
F_43 ( V_5 ) ;
return V_10 ;
}
static int F_44 ( struct V_4 * V_5 )
{
int V_10 ;
struct V_8 * V_9 = F_3 ( V_5 ) ;
T_2 V_7 = 0 ;
F_4 ( & V_5 -> V_52 ) ;
V_10 = F_8 ( V_5 ,
V_64 ,
V_7 ) ;
if ( V_10 ) {
F_14 ( & V_9 -> V_20 -> V_26 , L_11 ) ;
goto V_75;
}
V_10 = F_8 ( V_5 ,
V_77 ,
V_7 ) ;
if ( V_10 )
F_14 ( & V_9 -> V_20 -> V_26 , L_12 ) ;
V_75:
F_7 ( & V_5 -> V_52 ) ;
return V_10 ;
}
static int F_45 ( struct V_103 * V_104 )
{
struct V_4 * V_5 = F_46 ( V_104 ) ;
struct V_8 * V_9 = F_3 ( V_5 ) ;
F_47 ( V_5 ) ;
F_30 ( V_5 ) ;
F_44 ( V_5 ) ;
if ( V_104 -> V_1 )
F_42 ( V_9 -> V_20 -> V_1 , V_5 ) ;
F_41 ( V_5 ) ;
F_43 ( V_5 ) ;
return 0 ;
}
