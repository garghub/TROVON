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
T_4 V_28 ,
int * V_7 )
{
return F_13 ( V_5 , V_29 , V_7 ) ;
}
static int F_16 ( struct V_4 * V_5 ,
T_4 V_30 ,
int V_7 )
{
T_5 V_22 = V_7 ;
return F_11 ( V_5 ,
V_29 ,
V_22 ) ;
}
static int F_17 ( struct V_4 * V_5 ,
struct V_31 const * V_32 ,
int V_7 ,
int V_33 ,
long V_34 )
{
int V_10 = - V_35 , V_36 ;
T_2 V_37 ;
T_6 V_38 ;
switch ( V_34 ) {
case V_39 :
if ( V_7 > 255 || V_7 < - 256 )
return - V_35 ;
V_38 = V_7 ;
V_36 = V_40 [ V_41 ] [ V_32 -> V_42 ] ;
V_10 = F_8 ( V_5 , V_36 , V_38 ) ;
break;
case V_43 :
if ( V_7 & ~ 0xFF )
return - V_35 ;
V_37 = V_7 ;
V_36 = V_40 [ V_44 ] [ V_32 -> V_42 ] ;
V_10 = F_8 ( V_5 , V_36 , V_37 ) ;
break;
}
return V_10 ;
}
static int F_18 ( struct V_4 * V_5 ,
struct V_31 const * V_32 ,
int * V_7 ,
int * V_33 ,
long V_34 )
{
T_2 V_45 ;
T_6 V_46 ;
T_7 V_10 = 0 ;
T_2 V_36 ;
switch ( V_34 ) {
case V_47 :
F_4 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_49 == V_50 ) {
V_10 = - V_51 ;
} else {
V_36 = V_40
[ V_52 ] [ V_32 -> V_42 ] ;
V_10 = F_13 ( V_5 , V_36 , V_7 ) ;
}
F_7 ( & V_5 -> V_48 ) ;
return V_53 ;
case V_54 :
* V_7 = 0 ;
* V_33 = 9580 ;
return V_55 ;
case V_43 :
V_36 = V_40 [ V_44 ] [ V_32 -> V_42 ] ;
V_10 = F_2 ( V_5 , V_36 , & V_45 ) ;
if ( V_10 )
goto V_27;
* V_7 = V_45 ;
return V_53 ;
case V_39 :
V_36 = V_40 [ V_41 ] [ V_32 -> V_42 ] ;
V_10 = F_2 ( V_5 , V_36 , ( T_2 * ) & V_46 ) ;
* V_7 = V_46 ;
return V_53 ;
}
V_27:
return V_10 ;
}
static T_7 F_19 ( struct V_56 * V_26 ,
struct V_57 * V_58 ,
char * V_59 )
{
struct V_4 * V_5 = F_20 ( V_26 ) ;
int V_10 , V_18 = 0 ;
T_6 V_60 ;
V_10 = F_2 ( V_5 ,
V_61 ,
( T_2 * ) & V_60 ) ;
if ( V_10 )
return V_10 ;
V_60 &= V_62 ;
switch ( V_60 ) {
case V_63 :
V_18 = sprintf ( V_59 , L_2 ) ;
break;
case V_64 :
V_18 = sprintf ( V_59 , L_3 ) ;
break;
case V_65 :
V_18 = sprintf ( V_59 , L_4 ) ;
break;
case V_66 :
V_18 = sprintf ( V_59 , L_5 ) ;
break;
}
return V_18 ;
}
static T_7 F_21 ( struct V_56 * V_26 ,
struct V_57 * V_58 ,
const char * V_59 ,
T_8 V_18 )
{
struct V_4 * V_5 = F_20 ( V_26 ) ;
unsigned long V_7 ;
int V_10 ;
T_2 V_60 ;
V_10 = F_22 ( V_59 , 10 , & V_7 ) ;
if ( V_10 )
return V_10 ;
F_4 ( & V_5 -> V_48 ) ;
V_10 = F_2 ( V_5 ,
V_61 ,
& V_60 ) ;
if ( V_10 )
goto V_67;
V_60 &= ~ V_62 ;
switch ( V_7 ) {
case 280 :
V_60 |= V_63 ;
break;
case 560 :
V_60 |= V_64 ;
break;
case 1120 :
V_60 |= V_65 ;
break;
case 4480 :
V_60 |= V_66 ;
break;
default:
V_10 = - V_35 ;
goto V_67;
}
V_10 = F_8 ( V_5 ,
V_61 ,
V_60 ) ;
V_67:
F_7 ( & V_5 -> V_48 ) ;
return V_10 ? V_10 : V_18 ;
}
static int F_23 ( struct V_4 * V_5 )
{
struct V_8 * V_9 = F_3 ( V_5 ) ;
int V_10 ;
T_2 V_7 , V_68 ;
V_9 -> V_20 -> V_69 = V_70 ;
F_24 ( V_9 -> V_20 ) ;
V_7 = V_71 ;
V_10 = F_8 ( V_5 ,
V_61 ,
V_7 ) ;
if ( V_10 ) {
F_14 ( & V_9 -> V_20 -> V_26 , L_6 ) ;
goto V_72;
}
V_10 = F_8 ( V_5 ,
V_61 ,
V_7 ) ;
if ( V_10 ) {
F_14 ( & V_9 -> V_20 -> V_26 , L_6 ) ;
goto V_72;
}
V_10 = F_2 ( V_5 ,
V_61 ,
& V_68 ) ;
if ( V_10 || ( V_68 != V_7 ) ) {
F_14 ( & V_5 -> V_26 ,
L_7 , V_68 , V_7 ) ;
V_10 = - V_35 ;
goto V_72;
}
V_7 = V_73 ;
V_10 = F_8 ( V_5 ,
V_74 ,
V_7 ) ;
if ( V_10 ) {
F_14 ( & V_9 -> V_20 -> V_26 , L_8 ) ;
goto V_72;
}
V_7 = V_75 ;
V_10 = F_8 ( V_5 ,
V_76 ,
V_7 ) ;
if ( V_10 )
F_14 ( & V_9 -> V_20 -> V_26 , L_9 ) ;
V_72:
return V_10 ;
}
static T_1 F_25 ( int V_1 , void * V_2 )
{
struct V_4 * V_5 = V_2 ;
T_2 V_60 ;
T_9 V_77 = F_26 () ;
F_2 ( V_5 ,
V_78 ,
& V_60 ) ;
if ( V_60 & V_79 )
F_27 ( V_5 ,
F_28 ( V_80 ,
0 ,
V_81 ,
V_82 ,
V_83 ) ,
V_77 ) ;
if ( V_60 & V_84 )
F_27 ( V_5 ,
F_28 ( V_80 ,
0 ,
V_81 ,
V_82 ,
V_85 ) ,
V_77 ) ;
if ( V_60 & V_86 )
F_27 ( V_5 ,
F_28 ( V_80 ,
0 ,
V_87 ,
V_82 ,
V_83 ) ,
V_77 ) ;
if ( V_60 & V_88 )
F_27 ( V_5 ,
F_28 ( V_80 ,
0 ,
V_87 ,
V_82 ,
V_85 ) ,
V_77 ) ;
if ( V_60 & V_89 )
F_27 ( V_5 ,
F_28 ( V_80 ,
0 ,
V_90 ,
V_82 ,
V_83 ) ,
V_77 ) ;
if ( V_60 & V_91 )
F_27 ( V_5 ,
F_28 ( V_80 ,
0 ,
V_90 ,
V_82 ,
V_85 ) ,
V_77 ) ;
F_2 ( V_5 ,
V_92 ,
& V_60 ) ;
return V_93 ;
}
static int F_29 ( struct V_4 * V_5 ,
T_4 V_30 )
{
T_2 V_7 ;
int V_10 ;
T_2 V_34 = ( 1 << ( F_30 ( V_30 ) * 2 +
( F_31 ( V_30 ) ==
V_83 ) ) ) ;
V_10 = F_2 ( V_5 ,
V_76 ,
& V_7 ) ;
if ( V_10 < 0 )
return V_10 ;
return ! ! ( V_7 & V_34 ) ;
}
int F_32 ( struct V_4 * V_5 )
{
int V_10 ;
T_2 V_94 , V_7 ;
V_10 = F_2 ( V_5 ,
V_74 ,
& V_94 ) ;
V_94 &= ~ V_95 ;
V_10 = F_8 ( V_5 ,
V_74 ,
V_94 ) ;
if ( V_10 )
goto V_27;
V_10 = F_2 ( V_5 ,
V_76 ,
& V_7 ) ;
if ( V_10 )
goto V_27;
V_7 &= ~ 0x3f ;
V_10 = F_8 ( V_5 ,
V_76 ,
V_7 ) ;
if ( V_10 )
goto V_27;
V_10 = V_94 ;
V_27:
return V_10 ;
}
static int F_33 ( struct V_4 * V_5 ,
T_4 V_30 ,
int V_96 )
{
int V_10 = 0 ;
T_2 V_7 , V_94 ;
T_2 V_97 ;
bool V_98 = false ;
T_2 V_34 = ( 1 << ( F_30 ( V_30 ) * 2 +
( F_31 ( V_30 ) ==
V_83 ) ) ) ;
F_4 ( & V_5 -> V_48 ) ;
V_10 = F_2 ( V_5 ,
V_74 ,
& V_94 ) ;
if ( V_10 )
goto V_27;
V_10 = F_2 ( V_5 ,
V_76 ,
& V_7 ) ;
if ( V_10 < 0 )
goto V_27;
V_97 = V_7 & V_34 ;
if ( ! V_97 && V_96 ) {
V_98 = true ;
V_7 |= V_34 ;
} else if ( V_97 && ! V_96 ) {
V_98 = true ;
V_7 &= ~ V_34 ;
}
if ( V_98 ) {
V_10 = F_8 ( V_5 ,
V_76 ,
V_7 ) ;
if ( V_10 )
goto V_27;
V_94 = V_7 & 0x3f ?
( V_94 | V_95 ) :
( V_94 & ~ V_95 ) ;
V_10 = F_8 ( V_5 ,
V_74 ,
V_94 ) ;
if ( V_10 )
goto V_27;
}
V_27:
F_7 ( & V_5 -> V_48 ) ;
return V_10 ;
}
static int F_34 ( struct V_99 * V_100 )
{
int V_10 ;
struct V_8 * V_9 ;
struct V_4 * V_5 ;
V_5 = F_35 ( sizeof *V_9 ) ;
if ( V_5 == NULL ) {
V_10 = - V_101 ;
goto V_27;
}
V_9 = F_3 ( V_5 ) ;
F_36 ( V_100 , V_5 ) ;
V_9 -> V_20 = V_100 ;
V_9 -> V_102 = F_37 ( V_100 -> V_26 . V_103 , 0 ) ;
F_38 ( & V_9 -> V_19 ) ;
V_5 -> V_104 = V_100 -> V_26 . V_105 -> V_104 ;
V_5 -> V_26 . V_106 = & V_100 -> V_26 ;
V_5 -> V_107 = & V_108 ;
V_5 -> V_109 = V_110 ;
V_5 -> V_111 = F_12 ( V_110 ) ;
V_5 -> V_112 = V_113 ;
V_10 = F_39 ( V_5 ) ;
if ( V_10 )
goto V_114;
V_10 = F_40 ( V_5 ,
V_110 ,
F_12 ( V_110 ) ) ;
if ( V_10 ) {
F_41 ( V_115 L_10 ) ;
goto V_116;
}
if ( V_100 -> V_1 ) {
V_10 = F_42 ( V_9 -> V_20 -> V_1 ,
& V_117 ,
& F_25 ,
V_118 ,
L_11 ,
V_5 ) ;
if ( V_10 )
goto V_119;
V_10 = F_43 ( V_5 ) ;
if ( V_10 )
goto V_120;
}
V_10 = F_23 ( V_5 ) ;
if ( V_10 )
goto V_121;
V_10 = F_44 ( V_5 ) ;
if ( V_10 )
goto V_121;
return 0 ;
V_121:
if ( V_100 -> V_1 )
F_45 ( V_5 ) ;
V_120:
if ( V_100 -> V_1 )
F_46 ( V_9 -> V_20 -> V_1 , V_5 ) ;
V_119:
F_47 ( V_5 ) ;
V_116:
F_48 ( V_5 ) ;
V_114:
F_49 ( V_5 ) ;
V_27:
return V_10 ;
}
static int F_50 ( struct V_4 * V_5 )
{
int V_10 ;
struct V_8 * V_9 = F_3 ( V_5 ) ;
T_2 V_7 = 0 ;
F_4 ( & V_5 -> V_48 ) ;
V_10 = F_8 ( V_5 ,
V_61 ,
V_7 ) ;
if ( V_10 ) {
F_14 ( & V_9 -> V_20 -> V_26 , L_12 ) ;
goto V_72;
}
V_10 = F_8 ( V_5 ,
V_74 ,
V_7 ) ;
if ( V_10 )
F_14 ( & V_9 -> V_20 -> V_26 , L_13 ) ;
V_72:
F_7 ( & V_5 -> V_48 ) ;
return V_10 ;
}
static int F_51 ( struct V_99 * V_100 )
{
struct V_4 * V_5 = F_52 ( V_100 ) ;
struct V_8 * V_9 = F_3 ( V_5 ) ;
F_53 ( V_5 ) ;
F_32 ( V_5 ) ;
F_50 ( V_5 ) ;
if ( V_100 -> V_1 )
F_46 ( V_9 -> V_20 -> V_1 , V_5 ) ;
F_45 ( V_5 ) ;
F_47 ( V_5 ) ;
F_48 ( V_5 ) ;
F_49 ( V_5 ) ;
return 0 ;
}
