static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 ) ;
V_7 -> V_9 [ 0 ] = F_4 ( V_3 ) ;
V_7 -> V_9 [ 1 ] = V_4 ;
V_5 = F_5 ( V_7 -> V_10 , V_7 -> V_9 , 2 ) ;
F_6 ( & V_7 -> V_8 ) ;
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 ,
T_1 V_11 ,
T_2 V_12 )
{
int V_5 ;
struct V_13 V_14 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_15 V_16 [] = {
{
. V_17 = V_7 -> V_9 ,
. V_18 = 8 ,
. V_19 = 2 ,
. V_20 = 1 ,
} , {
. V_17 = V_7 -> V_9 + 2 ,
. V_18 = 8 ,
. V_19 = 2 ,
} ,
} ;
F_3 ( & V_7 -> V_8 ) ;
V_7 -> V_9 [ 0 ] = F_4 ( V_11 ) ;
V_7 -> V_9 [ 1 ] = V_12 & 0xFF ;
V_7 -> V_9 [ 2 ] = F_4 ( V_11 + 1 ) ;
V_7 -> V_9 [ 3 ] = ( V_12 >> 8 ) & 0xFF ;
F_8 ( & V_14 ) ;
F_9 ( & V_16 [ 0 ] , & V_14 ) ;
F_9 ( & V_16 [ 1 ] , & V_14 ) ;
V_5 = F_10 ( V_7 -> V_10 , & V_14 ) ;
F_6 ( & V_7 -> V_8 ) ;
return V_5 ;
}
static int F_11 ( struct V_1 * V_2 ,
T_1 V_11 ,
T_2 * V_4 )
{
struct V_13 V_14 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_5 ;
struct V_15 V_16 [] = {
{
. V_17 = V_7 -> V_9 ,
. V_18 = 8 ,
. V_19 = 2 ,
. V_20 = 1 ,
. V_21 = 20 ,
} , {
. V_22 = V_7 -> V_23 ,
. V_18 = 8 ,
. V_19 = 2 ,
. V_21 = 20 ,
} ,
} ;
F_3 ( & V_7 -> V_8 ) ;
V_7 -> V_9 [ 0 ] = F_12 ( V_11 ) ;
V_7 -> V_9 [ 1 ] = 0 ;
F_8 ( & V_14 ) ;
F_9 ( & V_16 [ 0 ] , & V_14 ) ;
F_9 ( & V_16 [ 1 ] , & V_14 ) ;
V_5 = F_10 ( V_7 -> V_10 , & V_14 ) ;
if ( V_5 ) {
F_13 ( & V_7 -> V_10 -> V_24 , L_1 ,
V_11 ) ;
goto V_25;
}
* V_4 = ( V_7 -> V_23 [ 0 ] << 8 ) | V_7 -> V_23 [ 1 ] ;
V_25:
F_6 ( & V_7 -> V_8 ) ;
return V_5 ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_2 V_26 ;
int V_5 ;
V_5 = F_11 ( V_2 ,
V_27 ,
& V_26 ) ;
if ( V_5 < 0 ) {
F_13 ( & V_2 -> V_24 , L_2 ) ;
goto V_25;
}
V_5 = V_26 & 0x1F ;
if ( V_26 & V_28 )
F_13 ( & V_2 -> V_24 , L_3 ) ;
if ( V_26 & V_29 )
F_13 ( & V_2 -> V_24 , L_4 ) ;
if ( V_26 & V_30 )
F_13 ( & V_2 -> V_24 , L_5 ) ;
if ( V_26 & V_31 )
F_13 ( & V_2 -> V_24 , L_6 ) ;
if ( V_26 & V_32 )
F_13 ( & V_2 -> V_24 , L_7 ) ;
V_25:
return V_5 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_1 ( V_2 ,
V_33 ,
V_34 ) ;
if ( V_5 )
F_13 ( & V_2 -> V_24 , L_8 ) ;
return V_5 ;
}
static T_3 F_16 ( struct V_35 * V_24 ,
struct V_36 * V_37 ,
const char * V_38 , T_4 V_19 )
{
struct V_1 * V_2 = F_17 ( V_24 ) ;
if ( V_19 < 1 )
return - V_39 ;
switch ( V_38 [ 0 ] ) {
case '1' :
case 'y' :
case 'Y' :
return F_15 ( V_2 ) ;
}
return - V_39 ;
}
int F_18 ( struct V_1 * V_2 , bool V_40 )
{
int V_5 = 0 ;
T_2 V_41 ;
V_5 = F_11 ( V_2 , V_42 , & V_41 ) ;
if ( V_5 )
goto V_25;
V_41 |= V_43 ;
V_41 &= ~ V_44 ;
if ( V_40 )
V_41 |= V_45 ;
else
V_41 &= ~ V_45 ;
V_5 = F_7 ( V_2 , V_42 , V_41 ) ;
V_25:
return V_5 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_7 ( V_2 ,
V_42 ,
V_46 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_24 , L_9 ) ;
goto V_47;
}
F_14 ( V_2 ) ;
V_47:
return V_5 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_18 ( V_2 , false ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_24 , L_10 ) ;
goto V_47;
}
V_5 = F_19 ( V_2 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_24 , L_11 ) ;
goto V_47;
}
V_5 = F_14 ( V_2 ) ;
if ( V_5 ) {
F_15 ( V_2 ) ;
F_13 ( & V_2 -> V_24 , L_12 ) ;
F_21 ( V_48 ) ;
V_5 = F_14 ( V_2 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_24 , L_13 ) ;
goto V_47;
}
}
V_47:
return V_5 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_49 const * V_50 ,
int V_4 ,
int V_51 ,
long V_52 )
{
T_1 V_53 = V_54 [ V_50 -> V_55 ] [ 1 ] ;
return F_7 ( V_2 , V_53 , V_4 & 0x3FFF ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_49 const * V_50 ,
int * V_4 , int * V_51 ,
long V_52 )
{
int V_5 ;
int V_56 ;
T_1 V_53 ;
T_5 V_57 ;
switch ( V_52 ) {
case 0 :
F_3 ( & V_2 -> V_58 ) ;
V_53 = V_54 [ V_50 -> V_55 ] [ 0 ] ;
V_5 = F_11 ( V_2 , V_53 , & V_57 ) ;
if ( V_5 )
return V_5 ;
if ( V_57 & V_59 ) {
V_5 = F_14 ( V_2 ) ;
if ( V_5 )
return V_5 ;
}
V_57 = V_57 & ( ( 1 << V_50 -> V_60 . V_61 ) - 1 ) ;
if ( V_50 -> V_60 . V_62 == 's' )
V_57 = ( T_5 ) ( V_57 <<
( 16 - V_50 -> V_60 . V_61 ) ) >>
( 16 - V_50 -> V_60 . V_61 ) ;
* V_4 = V_57 ;
F_6 ( & V_2 -> V_58 ) ;
return V_63 ;
case ( 1 << V_64 ) :
case ( 1 << V_65 ) :
switch ( V_50 -> type ) {
case V_66 :
* V_4 = 0 ;
if ( V_50 -> V_67 == 0 )
* V_51 = 1220 ;
else
* V_51 = 610 ;
return V_68 ;
case V_69 :
* V_4 = 0 ;
* V_51 = - 470000 ;
return V_68 ;
case V_70 :
* V_4 = 0 ;
* V_51 = 25000 ;
return V_68 ;
default:
return - V_39 ;
}
case ( 1 << V_71 ) :
* V_4 = 25 ;
return V_63 ;
case ( 1 << V_72 ) :
V_56 = 14 ;
F_3 ( & V_2 -> V_58 ) ;
V_53 = V_54 [ V_50 -> V_55 ] [ 1 ] ;
V_5 = F_11 ( V_2 , V_53 , & V_57 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_58 ) ;
return V_5 ;
}
V_57 &= ( 1 << V_56 ) - 1 ;
V_57 = ( T_5 ) ( V_57 << ( 16 - V_56 ) ) >> ( 16 - V_56 ) ;
* V_4 = V_57 ;
F_6 ( & V_2 -> V_58 ) ;
return V_63 ;
default:
return - V_39 ;
}
}
static int T_6 F_24 ( struct V_73 * V_74 )
{
int V_5 , V_75 = 0 ;
struct V_6 * V_7 = F_25 ( sizeof *V_7 , V_76 ) ;
if ( ! V_7 ) {
V_5 = - V_77 ;
goto V_25;
}
F_26 ( V_74 , V_7 ) ;
V_7 -> V_23 = F_25 ( sizeof( * V_7 -> V_23 ) * V_78 , V_76 ) ;
if ( V_7 -> V_23 == NULL ) {
V_5 = - V_77 ;
goto V_79;
}
V_7 -> V_9 = F_25 ( sizeof( * V_7 -> V_9 ) * V_80 , V_76 ) ;
if ( V_7 -> V_9 == NULL ) {
V_5 = - V_77 ;
goto V_81;
}
V_7 -> V_10 = V_74 ;
F_27 ( & V_7 -> V_8 ) ;
V_7 -> V_2 = F_28 ( 0 ) ;
if ( V_7 -> V_2 == NULL ) {
V_5 = - V_77 ;
goto V_82;
}
V_7 -> V_2 -> V_83 = V_74 -> V_24 . V_84 -> V_83 ;
V_7 -> V_2 -> V_24 . V_85 = & V_74 -> V_24 ;
V_7 -> V_2 -> V_86 = V_87 ;
V_7 -> V_2 -> V_88 = F_29 ( V_87 ) ;
V_7 -> V_2 -> V_89 = & V_90 ;
V_7 -> V_2 -> V_91 = ( void * ) ( V_7 ) ;
V_7 -> V_2 -> V_92 = V_93 ;
V_5 = F_30 ( V_7 -> V_2 ) ;
if ( V_5 )
goto V_94;
V_5 = F_31 ( V_7 -> V_2 ) ;
if ( V_5 )
goto V_95;
V_75 = 1 ;
V_5 = F_32 ( V_7 -> V_2 -> V_96 , 0 ,
V_87 ,
F_29 ( V_87 ) ) ;
if ( V_5 ) {
F_33 ( V_97 L_14 ) ;
goto V_95;
}
if ( V_74 -> V_98 ) {
V_5 = F_34 ( V_7 -> V_2 ) ;
if ( V_5 )
goto V_99;
}
V_5 = F_20 ( V_7 -> V_2 ) ;
if ( V_5 )
goto V_100;
return 0 ;
V_100:
F_35 ( V_7 -> V_2 ) ;
V_99:
F_36 ( V_7 -> V_2 -> V_96 ) ;
V_95:
F_37 ( V_7 -> V_2 ) ;
V_94:
if ( V_75 )
F_38 ( V_7 -> V_2 ) ;
else
F_39 ( V_7 -> V_2 ) ;
V_82:
F_40 ( V_7 -> V_9 ) ;
V_81:
F_40 ( V_7 -> V_23 ) ;
V_79:
F_40 ( V_7 ) ;
V_25:
return V_5 ;
}
static int F_41 ( struct V_73 * V_74 )
{
struct V_6 * V_7 = F_42 ( V_74 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_35 ( V_2 ) ;
F_36 ( V_2 -> V_96 ) ;
F_38 ( V_2 ) ;
F_37 ( V_2 ) ;
F_40 ( V_7 -> V_9 ) ;
F_40 ( V_7 -> V_23 ) ;
F_40 ( V_7 ) ;
return 0 ;
}
static T_7 int F_43 ( void )
{
return F_44 ( & V_101 ) ;
}
static T_8 void F_45 ( void )
{
F_46 ( & V_101 ) ;
}
