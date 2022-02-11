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
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_5 = F_1 ( V_2 ,
V_26 ,
V_27 ) ;
if ( V_5 )
F_13 ( & V_7 -> V_10 -> V_24 , L_2 ) ;
return V_5 ;
}
static T_3 F_15 ( struct V_28 * V_24 ,
struct V_29 * V_30 ,
const char * V_31 , T_4 V_19 )
{
int V_5 ;
bool V_32 ;
if ( V_19 < 1 )
return - V_33 ;
V_5 = F_16 ( V_31 , & V_32 ) ;
if ( V_5 || ! V_32 )
return V_5 ;
return F_14 ( F_17 ( V_24 ) ) ;
}
int F_18 ( struct V_1 * V_2 , bool V_34 )
{
int V_5 = 0 ;
T_2 V_35 ;
V_5 = F_11 ( V_2 , V_36 , & V_35 ) ;
if ( V_5 )
goto V_25;
V_35 |= V_37 ;
V_35 &= ~ V_38 ;
if ( V_34 )
V_35 |= V_39 ;
else
V_35 &= ~ V_39 ;
V_5 = F_7 ( V_2 , V_36 , V_35 ) ;
V_25:
return V_5 ;
}
static int F_19 ( struct V_1 * V_2 )
{
T_2 V_40 ;
int V_5 ;
V_5 = F_11 ( V_2 ,
V_41 , & V_40 ) ;
if ( V_5 < 0 ) {
F_13 ( & V_2 -> V_24 , L_3 ) ;
goto V_25;
}
V_5 = V_40 & 0xF ;
if ( V_5 )
V_5 = - V_42 ;
if ( V_40 & V_43 )
F_13 ( & V_2 -> V_24 , L_4 ) ;
if ( V_40 & V_44 )
F_13 ( & V_2 -> V_24 , L_5 ) ;
if ( V_40 & V_45 )
F_13 ( & V_2 -> V_24 , L_6 ) ;
if ( V_40 & V_46 )
F_13 ( & V_2 -> V_24 , L_7 ) ;
V_25:
return V_5 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_7 ( V_2 ,
V_36 ,
V_47 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_24 , L_8 ) ;
goto V_48;
}
V_5 = F_19 ( V_2 ) ;
V_48:
return V_5 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_28 * V_24 = & V_2 -> V_24 ;
V_5 = F_18 ( V_2 , false ) ;
if ( V_5 ) {
F_13 ( V_24 , L_9 ) ;
goto V_48;
}
V_5 = F_20 ( V_2 ) ;
if ( V_5 ) {
F_13 ( V_24 , L_10 ) ;
goto V_48;
}
V_5 = F_19 ( V_2 ) ;
if ( V_5 ) {
F_14 ( V_2 ) ;
F_13 ( V_24 , L_11 ) ;
F_22 ( V_49 ) ;
V_5 = F_19 ( V_2 ) ;
if ( V_5 ) {
F_13 ( V_24 , L_12 ) ;
goto V_48;
}
}
V_48:
return V_5 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_50 const * V_51 ,
int * V_4 , int * V_52 ,
long V_53 )
{
int V_5 ;
int V_54 ;
T_1 V_55 ;
T_5 V_56 ;
switch ( V_53 ) {
case 0 :
F_3 ( & V_2 -> V_57 ) ;
V_55 = V_58 [ V_51 -> V_59 ] [ 0 ] ;
V_5 = F_11 ( V_2 , V_55 , & V_56 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_57 ) ;
return V_5 ;
}
if ( V_56 & V_60 ) {
V_5 = F_19 ( V_2 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_57 ) ;
return V_5 ;
}
}
V_56 = V_56 & ( ( 1 << V_51 -> V_61 . V_62 ) - 1 ) ;
if ( V_51 -> V_61 . V_63 == 's' )
V_56 = ( T_5 ) ( V_56 <<
( 16 - V_51 -> V_61 . V_62 ) ) >>
( 16 - V_51 -> V_61 . V_62 ) ;
* V_4 = V_56 ;
F_6 ( & V_2 -> V_57 ) ;
return V_64 ;
case ( 1 << V_65 ) :
case ( 1 << V_66 ) :
switch ( V_51 -> type ) {
case V_67 :
* V_4 = 0 ;
if ( V_51 -> V_68 == 0 )
* V_52 = 1220 ;
else
* V_52 = 610 ;
return V_69 ;
case V_70 :
* V_4 = 0 ;
* V_52 = - 470000 ;
return V_69 ;
case V_71 :
* V_4 = 0 ;
* V_52 = 462500 ;
return V_69 ;
case V_72 :
* V_4 = 0 ;
* V_52 = 100000 ;
return V_69 ;
default:
return - V_33 ;
}
break;
case ( 1 << V_73 ) :
* V_4 = 25 ;
return V_64 ;
case ( 1 << V_74 ) :
switch ( V_51 -> type ) {
case V_71 :
V_54 = 12 ;
break;
case V_72 :
V_54 = 9 ;
break;
default:
return - V_33 ;
} ;
F_3 ( & V_2 -> V_57 ) ;
V_55 = V_58 [ V_51 -> V_59 ] [ 1 ] ;
V_5 = F_11 ( V_2 , V_55 , & V_56 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_57 ) ;
return V_5 ;
}
V_56 &= ( 1 << V_54 ) - 1 ;
V_56 = ( T_5 ) ( V_56 << ( 16 - V_54 ) ) >> ( 16 - V_54 ) ;
* V_4 = V_56 ;
F_6 ( & V_2 -> V_57 ) ;
return V_64 ;
}
return - V_33 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_50 const * V_51 ,
int V_4 ,
int V_52 ,
long V_53 )
{
int V_54 ;
T_5 V_56 ;
T_1 V_55 ;
switch ( V_53 ) {
case ( 1 << V_74 ) :
switch ( V_51 -> type ) {
case V_71 :
V_54 = 12 ;
break;
case V_72 :
V_54 = 9 ;
break;
default:
return - V_33 ;
} ;
V_56 = V_4 & ( ( 1 << V_54 ) - 1 ) ;
V_55 = V_58 [ V_51 -> V_59 ] [ 1 ] ;
return F_7 ( V_2 , V_55 , V_56 ) ;
}
return - V_33 ;
}
static int T_6 F_25 ( struct V_75 * V_76 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_2 = F_26 ( sizeof( * V_7 ) ) ;
if ( V_2 == NULL ) {
V_5 = - V_77 ;
goto V_25;
}
V_7 = F_2 ( V_2 ) ;
F_27 ( V_76 , V_2 ) ;
V_7 -> V_10 = V_76 ;
F_28 ( & V_7 -> V_8 ) ;
V_2 -> V_78 = V_76 -> V_24 . V_79 -> V_78 ;
V_2 -> V_24 . V_80 = & V_76 -> V_24 ;
V_2 -> V_81 = & V_82 ;
V_2 -> V_83 = V_84 ;
V_2 -> V_85 = F_29 ( V_84 ) ;
V_2 -> V_86 = V_87 ;
V_5 = F_30 ( V_2 ) ;
if ( V_5 )
goto V_88;
V_5 = F_31 ( V_2 ,
V_84 ,
F_29 ( V_84 ) ) ;
if ( V_5 ) {
F_32 ( V_89 L_13 ) ;
goto V_90;
}
if ( V_76 -> V_91 ) {
V_5 = F_33 ( V_2 ) ;
if ( V_5 )
goto V_92;
}
V_5 = F_21 ( V_2 ) ;
if ( V_5 )
goto V_93;
V_5 = F_34 ( V_2 ) ;
if ( V_5 < 0 )
goto V_93;
return 0 ;
V_93:
F_35 ( V_2 ) ;
V_92:
F_36 ( V_2 ) ;
V_90:
F_37 ( V_2 ) ;
V_88:
F_38 ( V_2 ) ;
V_25:
return V_5 ;
}
static int F_39 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = F_40 ( V_76 ) ;
F_41 ( V_2 ) ;
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
return 0 ;
}
static T_7 int F_42 ( void )
{
return F_43 ( & V_94 ) ;
}
static T_8 void F_44 ( void )
{
F_45 ( & V_94 ) ;
}
