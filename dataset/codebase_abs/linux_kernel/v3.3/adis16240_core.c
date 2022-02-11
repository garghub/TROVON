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
. V_21 = 35 ,
} , {
. V_17 = V_7 -> V_9 + 2 ,
. V_18 = 8 ,
. V_19 = 2 ,
. V_21 = 35 ,
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
. V_21 = 35 ,
} , {
. V_22 = V_7 -> V_23 ,
. V_18 = 8 ,
. V_19 = 2 ,
. V_20 = 1 ,
. V_21 = 35 ,
} ,
} ;
F_3 ( & V_7 -> V_8 ) ;
V_7 -> V_9 [ 0 ] = F_12 ( V_11 ) ;
V_7 -> V_9 [ 1 ] = 0 ;
V_7 -> V_9 [ 2 ] = 0 ;
V_7 -> V_9 [ 3 ] = 0 ;
F_8 ( & V_14 ) ;
F_9 ( & V_16 [ 0 ] , & V_14 ) ;
F_9 ( & V_16 [ 1 ] , & V_14 ) ;
V_5 = F_10 ( V_7 -> V_10 , & V_14 ) ;
if ( V_5 ) {
F_13 ( & V_7 -> V_10 -> V_24 ,
L_1 ,
V_11 ) ;
goto V_25;
}
* V_4 = ( V_7 -> V_23 [ 0 ] << 8 ) | V_7 -> V_23 [ 1 ] ;
V_25:
F_6 ( & V_7 -> V_8 ) ;
return V_5 ;
}
static T_3 F_14 ( struct V_26 * V_24 ,
struct V_27 * V_28 ,
char * V_29 ,
unsigned V_30 )
{
struct V_1 * V_2 = F_15 ( V_24 ) ;
int V_5 ;
T_4 V_4 = 0 ;
unsigned V_31 = 16 - V_30 ;
struct V_32 * V_33 = F_16 ( V_28 ) ;
V_5 = F_11 ( V_2 ,
V_33 -> V_34 , ( T_2 * ) & V_4 ) ;
if ( V_5 )
return V_5 ;
if ( V_4 & V_35 )
F_17 ( V_2 ) ;
V_4 = ( ( T_4 ) ( V_4 << V_31 ) >> V_31 ) ;
return sprintf ( V_29 , L_2 , V_4 ) ;
}
static T_3 F_18 ( struct V_26 * V_24 ,
struct V_27 * V_28 ,
char * V_29 )
{
T_3 V_5 ;
struct V_1 * V_2 = F_15 ( V_24 ) ;
F_3 ( & V_2 -> V_36 ) ;
V_5 = F_14 ( V_24 , V_28 , V_29 , 12 ) ;
F_6 ( & V_2 -> V_36 ) ;
return V_5 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_1 ( V_2 ,
V_37 ,
V_38 ) ;
if ( V_5 )
F_13 ( & V_2 -> V_24 , L_3 ) ;
return V_5 ;
}
static T_3 F_20 ( struct V_26 * V_24 ,
struct V_27 * V_28 ,
const char * V_29 , T_5 V_19 )
{
struct V_1 * V_2 = F_15 ( V_24 ) ;
if ( V_19 < 1 )
return - V_39 ;
switch ( V_29 [ 0 ] ) {
case '1' :
case 'y' :
case 'Y' :
return F_19 ( V_2 ) ;
}
return - V_39 ;
}
int F_21 ( struct V_1 * V_2 , bool V_40 )
{
int V_5 = 0 ;
T_2 V_41 ;
V_5 = F_11 ( V_2 ,
V_42 , & V_41 ) ;
if ( V_5 )
goto V_25;
V_41 |= V_43 ;
V_41 &= ~ V_44 ;
if ( V_40 )
V_41 |= V_45 ;
else
V_41 &= ~ V_45 ;
V_5 = F_7 ( V_2 ,
V_42 , V_41 ) ;
V_25:
return V_5 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_7 ( V_2 ,
V_42 ,
V_46 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_24 , L_4 ) ;
goto V_47;
}
F_23 ( V_48 ) ;
F_17 ( V_2 ) ;
V_47:
return V_5 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_2 V_49 ;
int V_5 ;
struct V_26 * V_24 = & V_2 -> V_24 ;
V_5 = F_11 ( V_2 ,
V_50 , & V_49 ) ;
if ( V_5 < 0 ) {
F_13 ( V_24 , L_5 ) ;
goto V_25;
}
V_5 = V_49 & 0x2F ;
if ( V_49 & V_51 )
F_13 ( V_24 , L_6 ) ;
if ( V_49 & V_52 )
F_13 ( V_24 , L_7 ) ;
if ( V_49 & V_53 )
F_13 ( V_24 , L_8 ) ;
if ( V_49 & V_54 )
F_13 ( V_24 , L_9 ) ;
if ( V_49 & V_55 )
F_13 ( V_24 , L_10 ) ;
V_25:
return V_5 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_26 * V_24 = & V_2 -> V_24 ;
V_5 = F_21 ( V_2 , false ) ;
if ( V_5 ) {
F_13 ( V_24 , L_11 ) ;
goto V_47;
}
V_5 = F_22 ( V_2 ) ;
if ( V_5 ) {
F_13 ( V_24 , L_12 ) ;
goto V_47;
}
V_5 = F_17 ( V_2 ) ;
if ( V_5 ) {
F_19 ( V_2 ) ;
F_13 ( V_24 , L_13 ) ;
F_23 ( V_48 ) ;
V_5 = F_17 ( V_2 ) ;
if ( V_5 ) {
F_13 ( V_24 , L_14 ) ;
goto V_47;
}
}
V_47:
return V_5 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_56 const * V_57 ,
int * V_4 , int * V_58 ,
long V_59 )
{
int V_5 ;
int V_30 ;
T_1 V_60 ;
T_4 V_61 ;
switch ( V_59 ) {
case 0 :
F_3 ( & V_2 -> V_36 ) ;
V_60 = V_62 [ V_57 -> V_34 ] [ 0 ] ;
V_5 = F_11 ( V_2 , V_60 , & V_61 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_36 ) ;
return V_5 ;
}
if ( V_61 & V_35 ) {
V_5 = F_17 ( V_2 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_36 ) ;
return V_5 ;
}
}
V_61 = V_61 & ( ( 1 << V_57 -> V_63 . V_64 ) - 1 ) ;
if ( V_57 -> V_63 . V_65 == 's' )
V_61 = ( T_4 ) ( V_61 <<
( 16 - V_57 -> V_63 . V_64 ) ) >>
( 16 - V_57 -> V_63 . V_64 ) ;
* V_4 = V_61 ;
F_6 ( & V_2 -> V_36 ) ;
return V_66 ;
case V_67 :
switch ( V_57 -> type ) {
case V_68 :
* V_4 = 0 ;
if ( V_57 -> V_69 == 0 )
* V_58 = 4880 ;
else
return - V_39 ;
return V_70 ;
case V_71 :
* V_4 = 0 ;
* V_58 = 244000 ;
return V_70 ;
case V_72 :
* V_4 = 0 ;
* V_58 = 504062 ;
return V_70 ;
default:
return - V_39 ;
}
break;
case V_73 :
* V_4 = 6 ;
* V_58 = 629295 ;
return V_70 ;
case V_74 :
* V_4 = 25 ;
return V_66 ;
case V_75 :
V_30 = 10 ;
F_3 ( & V_2 -> V_36 ) ;
V_60 = V_62 [ V_57 -> V_34 ] [ 1 ] ;
V_5 = F_11 ( V_2 , V_60 , & V_61 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_36 ) ;
return V_5 ;
}
V_61 &= ( 1 << V_30 ) - 1 ;
V_61 = ( T_4 ) ( V_61 << ( 16 - V_30 ) ) >> ( 16 - V_30 ) ;
* V_4 = V_61 ;
F_6 ( & V_2 -> V_36 ) ;
return V_66 ;
case V_76 :
V_30 = 10 ;
F_3 ( & V_2 -> V_36 ) ;
V_60 = V_62 [ V_57 -> V_34 ] [ 2 ] ;
V_5 = F_11 ( V_2 , V_60 , & V_61 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_36 ) ;
return V_5 ;
}
V_61 &= ( 1 << V_30 ) - 1 ;
V_61 = ( T_4 ) ( V_61 << ( 16 - V_30 ) ) >> ( 16 - V_30 ) ;
* V_4 = V_61 ;
F_6 ( & V_2 -> V_36 ) ;
return V_66 ;
}
return - V_39 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_56 const * V_57 ,
int V_4 ,
int V_58 ,
long V_59 )
{
int V_30 = 10 ;
T_4 V_61 ;
T_1 V_60 ;
switch ( V_59 ) {
case V_75 :
V_61 = V_4 & ( ( 1 << V_30 ) - 1 ) ;
V_60 = V_62 [ V_57 -> V_34 ] [ 1 ] ;
return F_7 ( V_2 , V_60 , V_61 ) ;
}
return - V_39 ;
}
static int T_6 F_27 ( struct V_77 * V_78 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_2 = F_28 ( sizeof( * V_7 ) ) ;
if ( V_2 == NULL ) {
V_5 = - V_79 ;
goto V_25;
}
V_7 = F_2 ( V_2 ) ;
F_29 ( V_78 , V_2 ) ;
V_7 -> V_10 = V_78 ;
F_30 ( & V_7 -> V_8 ) ;
V_2 -> V_80 = V_78 -> V_24 . V_81 -> V_80 ;
V_2 -> V_24 . V_82 = & V_78 -> V_24 ;
V_2 -> V_83 = & V_84 ;
V_2 -> V_85 = V_86 ;
V_2 -> V_87 = F_31 ( V_86 ) ;
V_2 -> V_88 = V_89 ;
V_5 = F_32 ( V_2 ) ;
if ( V_5 )
goto V_90;
V_5 = F_33 ( V_2 ,
V_86 ,
F_31 ( V_86 ) ) ;
if ( V_5 ) {
F_34 ( V_91 L_15 ) ;
goto V_92;
}
if ( V_78 -> V_93 ) {
V_5 = F_35 ( V_2 ) ;
if ( V_5 )
goto V_94;
}
V_5 = F_24 ( V_2 ) ;
if ( V_5 )
goto V_95;
V_5 = F_36 ( V_2 ) ;
if ( V_5 )
goto V_95;
return 0 ;
V_95:
F_37 ( V_2 ) ;
V_94:
F_38 ( V_2 ) ;
V_92:
F_39 ( V_2 ) ;
V_90:
F_40 ( V_2 ) ;
V_25:
return V_5 ;
}
static int F_41 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_42 ( V_78 ) ;
F_43 () ;
F_44 ( V_2 ) ;
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
