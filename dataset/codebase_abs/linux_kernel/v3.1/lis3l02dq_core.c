static T_1 F_1 ( int V_1 , void * V_2 )
{
return V_3 ;
}
int F_2 ( struct V_4 * V_5 ,
T_2 V_6 , T_2 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_5 ) ;
struct V_10 V_11 ;
int V_12 ;
struct V_13 V_14 = {
. V_15 = V_9 -> V_16 ,
. V_17 = V_9 -> V_18 ,
. V_19 = 8 ,
. V_20 = 2 ,
} ;
F_4 ( & V_9 -> V_21 ) ;
V_9 -> V_16 [ 0 ] = F_5 ( V_6 ) ;
V_9 -> V_16 [ 1 ] = 0 ;
F_6 ( & V_11 ) ;
F_7 ( & V_14 , & V_11 ) ;
V_12 = F_8 ( V_9 -> V_22 , & V_11 ) ;
* V_7 = V_9 -> V_18 [ 1 ] ;
F_9 ( & V_9 -> V_21 ) ;
return V_12 ;
}
int F_10 ( struct V_4 * V_5 ,
T_2 V_6 ,
T_2 V_7 )
{
int V_12 ;
struct V_8 * V_9 = F_3 ( V_5 ) ;
F_4 ( & V_9 -> V_21 ) ;
V_9 -> V_16 [ 0 ] = F_11 ( V_6 ) ;
V_9 -> V_16 [ 1 ] = V_7 ;
V_12 = F_12 ( V_9 -> V_22 , V_9 -> V_16 , 2 ) ;
F_9 ( & V_9 -> V_21 ) ;
return V_12 ;
}
static int F_13 ( struct V_4 * V_5 ,
T_2 V_23 ,
T_3 V_24 )
{
int V_12 ;
struct V_10 V_11 ;
struct V_8 * V_9 = F_3 ( V_5 ) ;
struct V_13 V_25 [] = { {
. V_15 = V_9 -> V_16 ,
. V_19 = 8 ,
. V_20 = 2 ,
. V_26 = 1 ,
} , {
. V_15 = V_9 -> V_16 + 2 ,
. V_19 = 8 ,
. V_20 = 2 ,
} ,
} ;
F_4 ( & V_9 -> V_21 ) ;
V_9 -> V_16 [ 0 ] = F_11 ( V_23 ) ;
V_9 -> V_16 [ 1 ] = V_24 & 0xFF ;
V_9 -> V_16 [ 2 ] = F_11 ( V_23 + 1 ) ;
V_9 -> V_16 [ 3 ] = ( V_24 >> 8 ) & 0xFF ;
F_6 ( & V_11 ) ;
F_7 ( & V_25 [ 0 ] , & V_11 ) ;
F_7 ( & V_25 [ 1 ] , & V_11 ) ;
V_12 = F_8 ( V_9 -> V_22 , & V_11 ) ;
F_9 ( & V_9 -> V_21 ) ;
return V_12 ;
}
static int F_14 ( struct V_4 * V_5 ,
T_2 V_23 ,
int * V_7 )
{
struct V_8 * V_9 = F_3 ( V_5 ) ;
struct V_10 V_11 ;
int V_12 ;
T_3 V_27 ;
struct V_13 V_25 [] = { {
. V_15 = V_9 -> V_16 ,
. V_17 = V_9 -> V_18 ,
. V_19 = 8 ,
. V_20 = 2 ,
. V_26 = 1 ,
} , {
. V_15 = V_9 -> V_16 + 2 ,
. V_17 = V_9 -> V_18 + 2 ,
. V_19 = 8 ,
. V_20 = 2 ,
} ,
} ;
F_4 ( & V_9 -> V_21 ) ;
V_9 -> V_16 [ 0 ] = F_5 ( V_23 ) ;
V_9 -> V_16 [ 1 ] = 0 ;
V_9 -> V_16 [ 2 ] = F_5 ( V_23 + 1 ) ;
V_9 -> V_16 [ 3 ] = 0 ;
F_6 ( & V_11 ) ;
F_7 ( & V_25 [ 0 ] , & V_11 ) ;
F_7 ( & V_25 [ 1 ] , & V_11 ) ;
V_12 = F_8 ( V_9 -> V_22 , & V_11 ) ;
if ( V_12 ) {
F_15 ( & V_9 -> V_22 -> V_28 , L_1 ) ;
goto V_29;
}
V_27 = ( T_3 ) ( V_9 -> V_18 [ 1 ] ) | ( ( T_3 ) ( V_9 -> V_18 [ 3 ] ) << 8 ) ;
* V_7 = V_27 ;
V_29:
F_9 ( & V_9 -> V_21 ) ;
return V_12 ;
}
static int F_16 ( struct V_4 * V_5 ,
int V_30 ,
int * V_7 )
{
return F_14 ( V_5 , V_31 , V_7 ) ;
}
static int F_17 ( struct V_4 * V_5 ,
int V_32 ,
int V_7 )
{
T_4 V_24 = V_7 ;
return F_13 ( V_5 ,
V_31 ,
V_24 ) ;
}
static int F_18 ( struct V_4 * V_5 ,
struct V_33 const * V_34 ,
int V_7 ,
int V_35 ,
long V_36 )
{
int V_12 = - V_37 , V_38 ;
T_2 V_39 ;
T_5 V_40 ;
switch ( V_36 ) {
case ( 1 << V_41 ) :
if ( V_7 > 255 || V_7 < - 256 )
return - V_37 ;
V_40 = V_7 ;
V_38 = V_42 [ V_43 ] [ V_34 -> V_44 ] ;
V_12 = F_10 ( V_5 , V_38 , V_40 ) ;
break;
case ( 1 << V_45 ) :
if ( V_7 & ~ 0xFF )
return - V_37 ;
V_39 = V_7 ;
V_38 = V_42 [ V_46 ] [ V_34 -> V_44 ] ;
V_12 = F_10 ( V_5 , V_38 , V_39 ) ;
break;
}
return V_12 ;
}
static int F_19 ( struct V_4 * V_5 ,
struct V_33 const * V_34 ,
int * V_7 ,
int * V_35 ,
long V_36 )
{
T_2 V_47 ;
T_5 V_48 ;
T_6 V_12 = 0 ;
T_2 V_38 ;
switch ( V_36 ) {
case 0 :
F_4 ( & V_5 -> V_49 ) ;
if ( V_5 -> V_50 == V_51 )
V_12 = F_20 ( V_5 -> V_52 ,
V_34 -> V_53 ,
V_7 ) ;
else {
V_38 = V_42
[ V_54 ] [ V_34 -> V_44 ] ;
V_12 = F_14 ( V_5 , V_38 , V_7 ) ;
}
F_9 ( & V_5 -> V_49 ) ;
return V_55 ;
case ( 1 << V_56 ) :
* V_7 = 0 ;
* V_35 = 9580 ;
return V_57 ;
case ( 1 << V_45 ) :
V_38 = V_42 [ V_46 ] [ V_34 -> V_44 ] ;
V_12 = F_2 ( V_5 , V_38 , & V_47 ) ;
if ( V_12 )
goto V_29;
* V_7 = V_47 ;
return V_55 ;
case ( 1 << V_41 ) :
V_38 = V_42 [ V_43 ] [ V_34 -> V_44 ] ;
V_12 = F_2 ( V_5 , V_38 , ( T_2 * ) & V_48 ) ;
* V_7 = V_48 ;
return V_55 ;
}
V_29:
return V_12 ;
}
static T_6 F_21 ( struct V_58 * V_28 ,
struct V_59 * V_60 ,
char * V_61 )
{
struct V_4 * V_5 = F_22 ( V_28 ) ;
int V_12 , V_20 = 0 ;
T_5 V_62 ;
V_12 = F_2 ( V_5 ,
V_63 ,
( T_2 * ) & V_62 ) ;
if ( V_12 )
return V_12 ;
V_62 &= V_64 ;
switch ( V_62 ) {
case V_65 :
V_20 = sprintf ( V_61 , L_2 ) ;
break;
case V_66 :
V_20 = sprintf ( V_61 , L_3 ) ;
break;
case V_67 :
V_20 = sprintf ( V_61 , L_4 ) ;
break;
case V_68 :
V_20 = sprintf ( V_61 , L_5 ) ;
break;
}
return V_20 ;
}
static T_6 F_23 ( struct V_58 * V_28 ,
struct V_59 * V_60 ,
const char * V_61 ,
T_7 V_20 )
{
struct V_4 * V_5 = F_22 ( V_28 ) ;
long V_7 ;
int V_12 ;
T_2 V_62 ;
V_12 = F_24 ( V_61 , 10 , & V_7 ) ;
if ( V_12 )
return V_12 ;
F_4 ( & V_5 -> V_49 ) ;
V_12 = F_2 ( V_5 ,
V_63 ,
& V_62 ) ;
if ( V_12 )
goto V_69;
V_62 &= ~ V_64 ;
switch ( V_7 ) {
case 280 :
V_62 |= V_65 ;
break;
case 560 :
V_62 |= V_66 ;
break;
case 1120 :
V_62 |= V_67 ;
break;
case 4480 :
V_62 |= V_68 ;
break;
default:
V_12 = - V_37 ;
goto V_69;
}
V_12 = F_10 ( V_5 ,
V_63 ,
V_62 ) ;
V_69:
F_9 ( & V_5 -> V_49 ) ;
return V_12 ? V_12 : V_20 ;
}
static int F_25 ( struct V_4 * V_5 )
{
struct V_8 * V_9 = F_3 ( V_5 ) ;
int V_12 ;
T_2 V_7 , V_70 ;
V_9 -> V_22 -> V_71 = V_72 ;
F_26 ( V_9 -> V_22 ) ;
V_7 = V_73 ;
V_12 = F_10 ( V_5 ,
V_63 ,
V_7 ) ;
if ( V_12 ) {
F_15 ( & V_9 -> V_22 -> V_28 , L_6 ) ;
goto V_74;
}
V_12 = F_10 ( V_5 ,
V_63 ,
V_7 ) ;
if ( V_12 ) {
F_15 ( & V_9 -> V_22 -> V_28 , L_6 ) ;
goto V_74;
}
V_12 = F_2 ( V_5 ,
V_63 ,
& V_70 ) ;
if ( V_12 || ( V_70 != V_7 ) ) {
F_15 ( & V_5 -> V_28 ,
L_7 , V_70 , V_7 ) ;
V_12 = - V_37 ;
goto V_74;
}
V_7 = V_75 ;
V_12 = F_10 ( V_5 ,
V_76 ,
V_7 ) ;
if ( V_12 ) {
F_15 ( & V_9 -> V_22 -> V_28 , L_8 ) ;
goto V_74;
}
V_7 = V_77 ;
V_12 = F_10 ( V_5 ,
V_78 ,
V_7 ) ;
if ( V_12 )
F_15 ( & V_9 -> V_22 -> V_28 , L_9 ) ;
V_74:
return V_12 ;
}
static T_1 F_27 ( int V_1 , void * V_2 )
{
struct V_4 * V_5 = V_2 ;
T_2 V_62 ;
T_8 V_79 = F_28 () ;
F_2 ( V_5 ,
V_80 ,
& V_62 ) ;
if ( V_62 & V_81 )
F_29 ( V_5 , 0 ,
F_30 ( V_82 ,
0 ,
V_83 ,
V_84 ,
V_85 ) ,
V_79 ) ;
if ( V_62 & V_86 )
F_29 ( V_5 , 0 ,
F_30 ( V_82 ,
0 ,
V_83 ,
V_84 ,
V_87 ) ,
V_79 ) ;
if ( V_62 & V_88 )
F_29 ( V_5 , 0 ,
F_30 ( V_82 ,
0 ,
V_89 ,
V_84 ,
V_85 ) ,
V_79 ) ;
if ( V_62 & V_90 )
F_29 ( V_5 , 0 ,
F_30 ( V_82 ,
0 ,
V_89 ,
V_84 ,
V_87 ) ,
V_79 ) ;
if ( V_62 & V_91 )
F_29 ( V_5 , 0 ,
F_30 ( V_82 ,
0 ,
V_92 ,
V_84 ,
V_85 ) ,
V_79 ) ;
if ( V_62 & V_93 )
F_29 ( V_5 , 0 ,
F_30 ( V_82 ,
0 ,
V_92 ,
V_84 ,
V_87 ) ,
V_79 ) ;
F_2 ( V_5 ,
V_94 ,
& V_62 ) ;
return V_95 ;
}
static T_6 F_31 ( struct V_4 * V_5 ,
int V_32 )
{
T_2 V_7 ;
int V_12 ;
T_2 V_36 = ( 1 << ( F_32 ( V_32 ) * 2 +
( F_33 ( V_32 ) ==
V_85 ) ) ) ;
V_12 = F_2 ( V_5 ,
V_78 ,
& V_7 ) ;
if ( V_12 < 0 )
return V_12 ;
return ! ! ( V_7 & V_36 ) ;
}
int F_34 ( struct V_4 * V_5 )
{
int V_12 ;
T_2 V_96 , V_7 ;
V_12 = F_2 ( V_5 ,
V_76 ,
& V_96 ) ;
V_96 &= ~ V_97 ;
V_12 = F_10 ( V_5 ,
V_76 ,
V_96 ) ;
if ( V_12 )
goto V_29;
V_12 = F_2 ( V_5 ,
V_78 ,
& V_7 ) ;
if ( V_12 )
goto V_29;
V_7 &= ~ 0x3f ;
V_12 = F_10 ( V_5 ,
V_78 ,
V_7 ) ;
if ( V_12 )
goto V_29;
V_12 = V_96 ;
V_29:
return V_12 ;
}
static int F_35 ( struct V_4 * V_5 ,
int V_32 ,
int V_98 )
{
int V_12 = 0 ;
T_2 V_7 , V_96 ;
T_2 V_99 ;
bool V_100 = false ;
T_2 V_36 = ( 1 << ( F_32 ( V_32 ) * 2 +
( F_33 ( V_32 ) ==
V_85 ) ) ) ;
F_4 ( & V_5 -> V_49 ) ;
V_12 = F_2 ( V_5 ,
V_76 ,
& V_96 ) ;
if ( V_12 )
goto V_29;
V_12 = F_2 ( V_5 ,
V_78 ,
& V_7 ) ;
if ( V_12 < 0 )
goto V_29;
V_99 = V_7 & V_36 ;
if ( ! V_99 && V_98 ) {
V_100 = true ;
V_7 |= V_36 ;
} else if ( V_99 && ! V_98 ) {
V_100 = true ;
V_7 &= ~ V_36 ;
}
if ( V_100 ) {
V_12 = F_10 ( V_5 ,
V_78 ,
V_7 ) ;
if ( V_12 )
goto V_29;
V_96 = V_7 & 0x3f ?
( V_96 | V_97 ) :
( V_96 & ~ V_97 ) ;
V_12 = F_10 ( V_5 ,
V_76 ,
V_96 ) ;
if ( V_12 )
goto V_29;
}
V_29:
F_9 ( & V_5 -> V_49 ) ;
return V_12 ;
}
static int T_9 F_36 ( struct V_101 * V_102 )
{
int V_12 , V_103 = 0 ;
struct V_8 * V_9 ;
struct V_4 * V_5 ;
V_5 = F_37 ( sizeof *V_9 ) ;
if ( V_5 == NULL ) {
V_12 = - V_104 ;
goto V_29;
}
V_9 = F_3 ( V_5 ) ;
F_38 ( V_102 , V_5 ) ;
V_9 -> V_22 = V_102 ;
F_39 ( & V_9 -> V_21 ) ;
V_5 -> V_105 = V_102 -> V_28 . V_106 -> V_105 ;
V_5 -> V_28 . V_107 = & V_102 -> V_28 ;
V_5 -> V_108 = & V_109 ;
V_5 -> V_110 = V_111 ;
V_5 -> V_112 = F_40 ( V_111 ) ;
V_5 -> V_113 = V_114 ;
V_12 = F_41 ( V_5 ) ;
if ( V_12 )
goto V_115;
V_12 = F_42 ( V_5 ) ;
if ( V_12 )
goto V_116;
V_103 = 1 ;
V_12 = F_43 ( V_5 -> V_52 , 0 ,
V_111 ,
F_40 ( V_111 ) ) ;
if ( V_12 ) {
F_44 ( V_117 L_10 ) ;
goto V_116;
}
if ( V_102 -> V_1 && F_45 ( F_46 ( V_102 -> V_1 ) ) > 0 ) {
V_12 = F_47 ( V_9 -> V_22 -> V_1 ,
& V_118 ,
& F_27 ,
V_119 ,
L_11 ,
V_5 ) ;
if ( V_12 )
goto V_120;
V_12 = F_48 ( V_5 ) ;
if ( V_12 )
goto V_121;
}
V_12 = F_25 ( V_5 ) ;
if ( V_12 )
goto V_122;
return 0 ;
V_122:
if ( V_5 -> V_113 & V_51 )
F_49 ( V_5 ) ;
V_121:
if ( V_102 -> V_1 && F_45 ( F_46 ( V_102 -> V_1 ) ) > 0 )
F_50 ( V_9 -> V_22 -> V_1 , V_5 ) ;
V_120:
F_51 ( V_5 -> V_52 ) ;
V_116:
F_52 ( V_5 ) ;
V_115:
if ( V_103 )
F_53 ( V_5 ) ;
else
F_54 ( V_5 ) ;
V_29:
return V_12 ;
}
static int F_55 ( struct V_4 * V_5 )
{
int V_12 ;
struct V_8 * V_9 = F_3 ( V_5 ) ;
T_2 V_7 = 0 ;
F_4 ( & V_5 -> V_49 ) ;
V_12 = F_10 ( V_5 ,
V_63 ,
V_7 ) ;
if ( V_12 ) {
F_15 ( & V_9 -> V_22 -> V_28 , L_12 ) ;
goto V_74;
}
V_12 = F_10 ( V_5 ,
V_76 ,
V_7 ) ;
if ( V_12 )
F_15 ( & V_9 -> V_22 -> V_28 , L_13 ) ;
V_74:
F_9 ( & V_5 -> V_49 ) ;
return V_12 ;
}
static int F_56 ( struct V_101 * V_102 )
{
int V_12 ;
struct V_4 * V_5 = F_57 ( V_102 ) ;
struct V_8 * V_9 = F_3 ( V_5 ) ;
V_12 = F_34 ( V_5 ) ;
if ( V_12 )
goto V_74;
V_12 = F_55 ( V_5 ) ;
if ( V_12 )
goto V_74;
if ( V_102 -> V_1 && F_45 ( F_46 ( V_102 -> V_1 ) ) > 0 )
F_50 ( V_9 -> V_22 -> V_1 , V_5 ) ;
F_49 ( V_5 ) ;
F_51 ( V_5 -> V_52 ) ;
F_52 ( V_5 ) ;
F_53 ( V_5 ) ;
return 0 ;
V_74:
return V_12 ;
}
static T_10 int F_58 ( void )
{
return F_59 ( & V_123 ) ;
}
static T_11 void F_60 ( void )
{
F_61 ( & V_123 ) ;
}
