struct V_1 * F_1 ( char * V_2 )
{
struct V_1 * V_3 ;
F_2 (gpadc, &ab8500_gpadc_list, node) {
if ( ! strcmp ( V_2 , F_3 ( V_3 -> V_4 ) ) )
return V_3 ;
}
return F_4 ( - V_5 ) ;
}
int F_5 ( struct V_1 * V_3 , T_1 V_6 ,
int V_7 )
{
int V_8 ;
switch ( V_6 ) {
case V_9 :
if ( ! V_3 -> V_10 [ V_11 ] . V_12 ) {
V_8 = V_13 + ( V_14 -
V_13 ) * V_7 /
V_15 ;
break;
}
V_8 = ( int ) ( V_7 * V_3 -> V_10 [ V_11 ] . V_12 +
V_3 -> V_10 [ V_11 ] . V_16 ) / V_17 ;
break;
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
if ( ! V_3 -> V_10 [ V_23 ] . V_12 ) {
V_8 = V_24 + ( V_25 -
V_24 ) * V_7 /
V_15 ;
break;
}
V_8 = ( int ) ( V_7 * V_3 -> V_10 [ V_23 ] . V_12 +
V_3 -> V_10 [ V_23 ] . V_16 ) / V_17 ;
break;
case V_26 :
if ( ! V_3 -> V_10 [ V_27 ] . V_12 ) {
V_8 = V_28 + ( V_29 -
V_28 ) * V_7 /
V_15 ;
break;
}
V_8 = ( int ) ( V_7 * V_3 -> V_10 [ V_27 ] . V_12 +
V_3 -> V_10 [ V_27 ] . V_16 ) / V_17 ;
break;
case V_30 :
V_8 = V_31 +
( V_32 - V_31 ) * V_7 /
V_15 ;
break;
case V_33 :
V_8 = V_34 +
( V_35 - V_34 ) * V_7 /
V_15 ;
break;
case V_36 :
V_8 = V_13 +
( V_14 - V_13 ) * V_7 /
V_15 ;
break;
case V_37 :
case V_38 :
V_8 = V_39 +
( V_40 - V_39 ) * V_7 /
V_15 ;
break;
case V_41 :
V_8 = V_42 +
( V_43 - V_42 ) * V_7 /
V_15 ;
break;
default:
F_6 ( V_3 -> V_4 ,
L_1 ) ;
V_8 = - V_44 ;
break;
}
return V_8 ;
}
int F_7 ( struct V_1 * V_3 , T_1 V_6 )
{
int V_7 ;
int V_45 ;
V_7 = F_8 ( V_3 , V_6 ) ;
if ( V_7 < 0 ) {
F_6 ( V_3 -> V_4 , L_2 , V_6 ) ;
return V_7 ;
}
V_45 = F_5 ( V_3 , V_6 , V_7 ) ;
if ( V_45 < 0 )
F_6 ( V_3 -> V_4 , L_3
L_4 , V_6 , V_7 ) ;
return V_45 ;
}
int F_8 ( struct V_1 * V_3 , T_1 V_6 )
{
int V_46 ;
int V_47 = 0 ;
T_1 V_48 , V_49 , V_50 ;
if ( ! V_3 )
return - V_51 ;
F_9 ( & V_3 -> V_52 ) ;
F_10 ( V_3 -> V_4 ) ;
do {
V_46 = F_11 ( V_3 -> V_4 ,
V_53 , V_54 , & V_48 ) ;
if ( V_46 < 0 )
goto V_55;
if ( ! ( V_48 & V_56 ) )
break;
F_12 ( 10 ) ;
} while ( ++ V_47 < 10 );
if ( V_47 >= 10 && ( V_48 & V_56 ) ) {
F_6 ( V_3 -> V_4 , L_5 ) ;
V_46 = - V_44 ;
goto V_55;
}
V_46 = F_13 ( V_3 -> V_4 ,
V_53 , V_57 , V_58 , V_58 ) ;
if ( V_46 < 0 ) {
F_6 ( V_3 -> V_4 , L_6 ) ;
goto V_55;
}
V_46 = F_14 ( V_3 -> V_4 , V_53 ,
V_59 , ( V_6 | V_60 ) ) ;
if ( V_46 < 0 ) {
F_6 ( V_3 -> V_4 ,
L_7 ) ;
goto V_55;
}
switch ( V_6 ) {
case V_37 :
case V_38 :
V_46 = F_13 ( V_3 -> V_4 ,
V_53 , V_57 ,
V_61 | V_62 ,
V_61 | V_62 ) ;
break;
case V_19 :
if ( ! F_15 ( V_3 -> V_63 ) ) {
V_46 = F_13 (
V_3 -> V_4 ,
V_53 , V_57 ,
V_61 | V_64 ,
V_61 | V_64 ) ;
F_16 ( 1000 , 1000 ) ;
break;
}
default:
V_46 = F_13 ( V_3 -> V_4 ,
V_53 , V_57 , V_61 , V_61 ) ;
break;
}
if ( V_46 < 0 ) {
F_6 ( V_3 -> V_4 ,
L_8 ) ;
goto V_55;
}
V_46 = F_13 ( V_3 -> V_4 ,
V_53 , V_57 , V_65 , V_65 ) ;
if ( V_46 < 0 ) {
F_6 ( V_3 -> V_4 ,
L_9 ) ;
goto V_55;
}
if ( ! F_17 ( & V_3 -> V_66 ,
F_18 ( V_67 ) ) ) {
F_6 ( V_3 -> V_4 ,
L_10 ) ;
V_46 = - V_44 ;
goto V_55;
}
V_46 = F_11 ( V_3 -> V_4 , V_53 ,
V_68 , & V_49 ) ;
if ( V_46 < 0 ) {
F_6 ( V_3 -> V_4 , L_11 ) ;
goto V_55;
}
V_46 = F_11 ( V_3 -> V_4 , V_53 ,
V_69 , & V_50 ) ;
if ( V_46 < 0 ) {
F_6 ( V_3 -> V_4 ,
L_12 ) ;
goto V_55;
}
V_46 = F_14 ( V_3 -> V_4 , V_53 ,
V_57 , V_70 ) ;
if ( V_46 < 0 ) {
F_6 ( V_3 -> V_4 , L_13 ) ;
goto V_55;
}
F_19 ( V_3 -> V_4 ) ;
F_20 ( V_3 -> V_4 ) ;
F_21 ( & V_3 -> V_52 ) ;
return ( V_50 << 8 ) | V_49 ;
V_55:
( void ) F_14 ( V_3 -> V_4 , V_53 ,
V_57 , V_70 ) ;
F_22 ( V_3 -> V_4 ) ;
F_21 ( & V_3 -> V_52 ) ;
F_6 ( V_3 -> V_4 ,
L_14 , V_6 ) ;
return V_46 ;
}
static T_2 F_23 ( int V_71 , void * V_72 )
{
struct V_1 * V_3 = V_72 ;
F_24 ( & V_3 -> V_66 ) ;
return V_73 ;
}
static void F_25 ( struct V_1 * V_3 )
{
int V_74 ;
int V_46 [ F_26 ( V_75 ) ] ;
T_1 V_76 [ F_26 ( V_75 ) ] ;
int V_77 , V_78 ;
int V_79 , V_80 ;
int V_81 , V_82 ;
for ( V_74 = 0 ; V_74 < F_26 ( V_75 ) ; V_74 ++ ) {
V_46 [ V_74 ] = F_11 ( V_3 -> V_4 ,
V_83 , V_75 [ V_74 ] , & V_76 [ V_74 ] ) ;
if ( V_46 [ V_74 ] < 0 )
F_6 ( V_3 -> V_4 , L_15 ,
V_84 , V_75 [ V_74 ] ) ;
}
if ( ! ( V_46 [ 0 ] < 0 || V_46 [ 1 ] < 0 || V_46 [ 2 ] < 0 ) ) {
V_77 = ( ( ( V_76 [ 0 ] & 0x03 ) << 8 ) |
( ( V_76 [ 1 ] & 0x3F ) << 2 ) |
( ( V_76 [ 2 ] & 0xC0 ) >> 6 ) ) ;
V_78 = ( ( V_76 [ 2 ] & 0x3E ) >> 1 ) ;
V_3 -> V_10 [ V_11 ] . V_12 = V_17 *
( 19500 - 315 ) / ( V_77 - V_78 ) ;
V_3 -> V_10 [ V_11 ] . V_16 = V_17 * 19500 -
( V_17 * ( 19500 - 315 ) /
( V_77 - V_78 ) ) * V_77 ;
} else {
V_3 -> V_10 [ V_11 ] . V_12 = 0 ;
}
if ( ! ( V_46 [ 2 ] < 0 || V_46 [ 3 ] < 0 || V_46 [ 4 ] < 0 ) ) {
V_79 = ( ( ( V_76 [ 2 ] & 0x01 ) << 9 ) |
( V_76 [ 3 ] << 1 ) |
( ( V_76 [ 4 ] & 0x80 ) >> 7 ) ) ;
V_80 = ( ( V_76 [ 4 ] & 0x7C ) >> 2 ) ;
V_3 -> V_10 [ V_23 ] . V_12 =
V_17 * ( 1300 - 21 ) / ( V_79 - V_80 ) ;
V_3 -> V_10 [ V_23 ] . V_16 = V_17 * 1300 -
( V_17 * ( 1300 - 21 ) /
( V_79 - V_80 ) ) * V_79 ;
} else {
V_3 -> V_10 [ V_23 ] . V_12 = 0 ;
}
if ( ! ( V_46 [ 4 ] < 0 || V_46 [ 5 ] < 0 || V_46 [ 6 ] < 0 ) ) {
V_81 = ( ( ( V_76 [ 4 ] & 0x03 ) << 8 ) | V_76 [ 5 ] ) ;
V_82 = ( ( V_76 [ 6 ] & 0xFC ) >> 2 ) ;
V_3 -> V_10 [ V_27 ] . V_12 = V_17 *
( 4700 - 2380 ) / ( V_81 - V_82 ) ;
V_3 -> V_10 [ V_27 ] . V_16 = V_17 * 4700 -
( V_17 * ( 4700 - 2380 ) /
( V_81 - V_82 ) ) * V_81 ;
} else {
V_3 -> V_10 [ V_27 ] . V_12 = 0 ;
}
F_27 ( V_3 -> V_4 , L_16 ,
V_3 -> V_10 [ V_11 ] . V_12 ,
V_3 -> V_10 [ V_11 ] . V_16 ) ;
F_27 ( V_3 -> V_4 , L_17 ,
V_3 -> V_10 [ V_23 ] . V_12 ,
V_3 -> V_10 [ V_23 ] . V_16 ) ;
F_27 ( V_3 -> V_4 , L_18 ,
V_3 -> V_10 [ V_27 ] . V_12 ,
V_3 -> V_10 [ V_27 ] . V_16 ) ;
}
static int F_28 ( struct V_85 * V_4 )
{
struct V_1 * V_3 = F_29 ( V_4 ) ;
F_30 ( V_3 -> V_86 ) ;
return 0 ;
}
static int F_31 ( struct V_85 * V_4 )
{
struct V_1 * V_3 = F_29 ( V_4 ) ;
int V_46 ;
V_46 = F_32 ( V_3 -> V_86 ) ;
if ( V_46 )
F_6 ( V_4 , L_19 , V_46 ) ;
return V_46 ;
}
static int F_33 ( struct V_85 * V_4 )
{
F_34 ( V_4 ) ;
return 0 ;
}
static int F_35 ( struct V_87 * V_88 )
{
int V_46 = 0 ;
struct V_1 * V_3 ;
V_3 = F_36 ( sizeof( struct V_1 ) , V_89 ) ;
if ( ! V_3 ) {
F_6 ( & V_88 -> V_4 , L_20 ) ;
return - V_90 ;
}
V_3 -> V_71 = F_37 ( V_88 , L_21 ) ;
if ( V_3 -> V_71 < 0 ) {
F_6 ( & V_88 -> V_4 , L_22 ,
V_3 -> V_71 ) ;
V_46 = V_3 -> V_71 ;
goto V_91;
}
V_3 -> V_4 = & V_88 -> V_4 ;
V_3 -> V_63 = F_29 ( V_88 -> V_4 . V_63 ) ;
F_38 ( & V_3 -> V_52 ) ;
F_39 ( & V_3 -> V_66 ) ;
V_46 = F_40 ( V_3 -> V_71 , NULL ,
F_23 ,
V_92 | V_93 | V_94 ,
L_23 , V_3 ) ;
if ( V_46 < 0 ) {
F_6 ( V_3 -> V_4 , L_24 ,
V_3 -> V_71 ) ;
goto V_91;
}
V_3 -> V_86 = F_41 ( & V_88 -> V_4 , L_25 ) ;
if ( F_42 ( V_3 -> V_86 ) ) {
V_46 = F_43 ( V_3 -> V_86 ) ;
F_6 ( V_3 -> V_4 , L_26 ) ;
goto V_95;
}
F_44 ( V_88 , V_3 ) ;
V_46 = F_32 ( V_3 -> V_86 ) ;
if ( V_46 ) {
F_6 ( V_3 -> V_4 , L_19 , V_46 ) ;
goto V_96;
}
F_45 ( V_3 -> V_4 , V_97 ) ;
F_46 ( V_3 -> V_4 ) ;
F_47 ( V_3 -> V_4 ) ;
F_48 ( V_3 -> V_4 ) ;
F_25 ( V_3 ) ;
F_49 ( & V_3 -> V_98 , & V_99 ) ;
F_27 ( V_3 -> V_4 , L_27 ) ;
return 0 ;
V_96:
V_95:
F_50 ( V_3 -> V_71 , V_3 ) ;
V_91:
F_51 ( V_3 ) ;
V_3 = NULL ;
return V_46 ;
}
static int F_52 ( struct V_87 * V_88 )
{
struct V_1 * V_3 = F_53 ( V_88 ) ;
F_54 ( & V_3 -> V_98 ) ;
F_50 ( V_3 -> V_71 , V_3 ) ;
F_10 ( V_3 -> V_4 ) ;
F_55 ( V_3 -> V_4 ) ;
F_30 ( V_3 -> V_86 ) ;
F_56 ( V_3 -> V_4 ) ;
F_57 ( V_3 -> V_4 ) ;
F_51 ( V_3 ) ;
V_3 = NULL ;
return 0 ;
}
static int T_3 F_58 ( void )
{
return F_59 ( & V_100 ) ;
}
static void T_4 F_60 ( void )
{
F_61 ( & V_100 ) ;
}
