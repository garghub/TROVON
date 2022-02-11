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
int F_20 ( struct V_1 * V_2 , bool V_39 )
{
int V_5 = 0 ;
T_2 V_40 ;
V_5 = F_11 ( V_2 ,
V_41 , & V_40 ) ;
if ( V_5 )
goto V_25;
V_40 |= V_42 ;
V_40 &= ~ V_43 ;
if ( V_39 )
V_40 |= V_44 ;
else
V_40 &= ~ V_44 ;
V_5 = F_7 ( V_2 ,
V_41 , V_40 ) ;
V_25:
return V_5 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_7 ( V_2 ,
V_41 ,
V_45 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_24 , L_4 ) ;
goto V_46;
}
F_22 ( V_47 ) ;
F_17 ( V_2 ) ;
V_46:
return V_5 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_2 V_48 ;
int V_5 ;
struct V_26 * V_24 = & V_2 -> V_24 ;
V_5 = F_11 ( V_2 ,
V_49 , & V_48 ) ;
if ( V_5 < 0 ) {
F_13 ( V_24 , L_5 ) ;
goto V_25;
}
V_5 = V_48 & 0x2F ;
if ( V_48 & V_50 )
F_13 ( V_24 , L_6 ) ;
if ( V_48 & V_51 )
F_13 ( V_24 , L_7 ) ;
if ( V_48 & V_52 )
F_13 ( V_24 , L_8 ) ;
if ( V_48 & V_53 )
F_13 ( V_24 , L_9 ) ;
if ( V_48 & V_54 )
F_13 ( V_24 , L_10 ) ;
V_25:
return V_5 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_26 * V_24 = & V_2 -> V_24 ;
V_5 = F_20 ( V_2 , false ) ;
if ( V_5 ) {
F_13 ( V_24 , L_11 ) ;
goto V_46;
}
V_5 = F_21 ( V_2 ) ;
if ( V_5 ) {
F_13 ( V_24 , L_12 ) ;
goto V_46;
}
V_5 = F_17 ( V_2 ) ;
if ( V_5 ) {
F_19 ( V_2 ) ;
F_13 ( V_24 , L_13 ) ;
F_22 ( V_47 ) ;
V_5 = F_17 ( V_2 ) ;
if ( V_5 ) {
F_13 ( V_24 , L_14 ) ;
goto V_46;
}
}
V_46:
return V_5 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_55 const * V_56 ,
int * V_4 , int * V_57 ,
long V_58 )
{
int V_5 ;
int V_30 ;
T_1 V_59 ;
T_4 V_60 ;
switch ( V_58 ) {
case V_61 :
F_3 ( & V_2 -> V_36 ) ;
V_59 = V_62 [ V_56 -> V_34 ] [ 0 ] ;
V_5 = F_11 ( V_2 , V_59 , & V_60 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_36 ) ;
return V_5 ;
}
if ( V_60 & V_35 ) {
V_5 = F_17 ( V_2 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_36 ) ;
return V_5 ;
}
}
V_60 = V_60 & ( ( 1 << V_56 -> V_63 . V_64 ) - 1 ) ;
if ( V_56 -> V_63 . V_65 == 's' )
V_60 = ( T_4 ) ( V_60 <<
( 16 - V_56 -> V_63 . V_64 ) ) >>
( 16 - V_56 -> V_63 . V_64 ) ;
* V_4 = V_60 ;
F_6 ( & V_2 -> V_36 ) ;
return V_66 ;
case V_67 :
switch ( V_56 -> type ) {
case V_68 :
* V_4 = 0 ;
if ( V_56 -> V_69 == 0 )
* V_57 = 4880 ;
else
return - V_70 ;
return V_71 ;
case V_72 :
* V_4 = 0 ;
* V_57 = 244000 ;
return V_71 ;
case V_73 :
* V_4 = 0 ;
* V_57 = 504062 ;
return V_71 ;
default:
return - V_70 ;
}
break;
case V_74 :
* V_4 = 6 ;
* V_57 = 629295 ;
return V_71 ;
case V_75 :
* V_4 = 25 ;
return V_66 ;
case V_76 :
V_30 = 10 ;
F_3 ( & V_2 -> V_36 ) ;
V_59 = V_62 [ V_56 -> V_34 ] [ 1 ] ;
V_5 = F_11 ( V_2 , V_59 , & V_60 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_36 ) ;
return V_5 ;
}
V_60 &= ( 1 << V_30 ) - 1 ;
V_60 = ( T_4 ) ( V_60 << ( 16 - V_30 ) ) >> ( 16 - V_30 ) ;
* V_4 = V_60 ;
F_6 ( & V_2 -> V_36 ) ;
return V_66 ;
case V_77 :
V_30 = 10 ;
F_3 ( & V_2 -> V_36 ) ;
V_59 = V_62 [ V_56 -> V_34 ] [ 2 ] ;
V_5 = F_11 ( V_2 , V_59 , & V_60 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_36 ) ;
return V_5 ;
}
V_60 &= ( 1 << V_30 ) - 1 ;
V_60 = ( T_4 ) ( V_60 << ( 16 - V_30 ) ) >> ( 16 - V_30 ) ;
* V_4 = V_60 ;
F_6 ( & V_2 -> V_36 ) ;
return V_66 ;
}
return - V_70 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_55 const * V_56 ,
int V_4 ,
int V_57 ,
long V_58 )
{
int V_30 = 10 ;
T_4 V_60 ;
T_1 V_59 ;
switch ( V_58 ) {
case V_76 :
V_60 = V_4 & ( ( 1 << V_30 ) - 1 ) ;
V_59 = V_62 [ V_56 -> V_34 ] [ 1 ] ;
return F_7 ( V_2 , V_59 , V_60 ) ;
}
return - V_70 ;
}
static int T_5 F_26 ( struct V_78 * V_79 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_2 = F_27 ( sizeof( * V_7 ) ) ;
if ( V_2 == NULL ) {
V_5 = - V_80 ;
goto V_25;
}
V_7 = F_2 ( V_2 ) ;
F_28 ( V_79 , V_2 ) ;
V_7 -> V_10 = V_79 ;
F_29 ( & V_7 -> V_8 ) ;
V_2 -> V_81 = V_79 -> V_24 . V_82 -> V_81 ;
V_2 -> V_24 . V_83 = & V_79 -> V_24 ;
V_2 -> V_84 = & V_85 ;
V_2 -> V_86 = V_87 ;
V_2 -> V_88 = F_30 ( V_87 ) ;
V_2 -> V_89 = V_90 ;
V_5 = F_31 ( V_2 ) ;
if ( V_5 )
goto V_91;
V_5 = F_32 ( V_2 ,
V_87 ,
F_30 ( V_87 ) ) ;
if ( V_5 ) {
F_33 ( V_92 L_15 ) ;
goto V_93;
}
if ( V_79 -> V_94 ) {
V_5 = F_34 ( V_2 ) ;
if ( V_5 )
goto V_95;
}
V_5 = F_23 ( V_2 ) ;
if ( V_5 )
goto V_96;
V_5 = F_35 ( V_2 ) ;
if ( V_5 )
goto V_96;
return 0 ;
V_96:
F_36 ( V_2 ) ;
V_95:
F_37 ( V_2 ) ;
V_93:
F_38 ( V_2 ) ;
V_91:
F_39 ( V_2 ) ;
V_25:
return V_5 ;
}
static int F_40 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_41 ( V_79 ) ;
F_42 ( V_2 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
return 0 ;
}
