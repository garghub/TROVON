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
int F_16 ( struct V_1 * V_2 , bool V_35 )
{
int V_5 = 0 ;
T_2 V_36 ;
V_5 = F_11 ( V_2 , V_37 , & V_36 ) ;
if ( V_5 )
goto V_25;
V_36 |= V_38 ;
V_36 &= ~ V_39 ;
if ( V_35 )
V_36 |= V_40 ;
else
V_36 &= ~ V_40 ;
V_5 = F_7 ( V_2 , V_37 , V_36 ) ;
V_25:
return V_5 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_7 ( V_2 ,
V_37 ,
V_41 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_24 , L_9 ) ;
goto V_42;
}
F_14 ( V_2 ) ;
V_42:
return V_5 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_16 ( V_2 , false ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_24 , L_10 ) ;
goto V_42;
}
V_5 = F_17 ( V_2 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_24 , L_11 ) ;
goto V_42;
}
V_5 = F_14 ( V_2 ) ;
if ( V_5 ) {
F_15 ( V_2 ) ;
F_13 ( & V_2 -> V_24 , L_12 ) ;
F_19 ( V_43 ) ;
V_5 = F_14 ( V_2 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_24 , L_13 ) ;
goto V_42;
}
}
V_42:
return V_5 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_44 const * V_45 ,
int V_4 ,
int V_46 ,
long V_47 )
{
T_1 V_48 = V_49 [ V_45 -> V_50 ] [ 1 ] ;
return F_7 ( V_2 , V_48 , V_4 & 0x3FFF ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_44 const * V_45 ,
int * V_4 , int * V_46 ,
long V_47 )
{
int V_5 ;
int V_51 ;
T_1 V_48 ;
T_3 V_52 ;
switch ( V_47 ) {
case V_53 :
F_3 ( & V_2 -> V_54 ) ;
V_48 = V_49 [ V_45 -> V_50 ] [ 0 ] ;
V_5 = F_11 ( V_2 , V_48 , & V_52 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_54 ) ;
return V_5 ;
}
if ( V_52 & V_55 ) {
V_5 = F_14 ( V_2 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_54 ) ;
return V_5 ;
}
}
V_52 = V_52 & ( ( 1 << V_45 -> V_56 . V_57 ) - 1 ) ;
if ( V_45 -> V_56 . V_58 == 's' )
V_52 = ( T_3 ) ( V_52 <<
( 16 - V_45 -> V_56 . V_57 ) ) >>
( 16 - V_45 -> V_56 . V_57 ) ;
* V_4 = V_52 ;
F_6 ( & V_2 -> V_54 ) ;
return V_59 ;
case V_60 :
switch ( V_45 -> type ) {
case V_61 :
if ( V_45 -> V_62 == 0 ) {
* V_4 = 1 ;
* V_46 = 220000 ;
} else {
* V_4 = 0 ;
* V_46 = 610000 ;
}
return V_63 ;
case V_64 :
* V_4 = - 470 ;
* V_46 = 0 ;
return V_63 ;
case V_65 :
* V_4 = 0 ;
* V_46 = 25000 ;
return V_63 ;
default:
return - V_66 ;
}
case V_67 :
* V_4 = 25000 / - 470 - 1278 ;
return V_59 ;
case V_68 :
V_51 = 14 ;
F_3 ( & V_2 -> V_54 ) ;
V_48 = V_49 [ V_45 -> V_50 ] [ 1 ] ;
V_5 = F_11 ( V_2 , V_48 , & V_52 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_54 ) ;
return V_5 ;
}
V_52 &= ( 1 << V_51 ) - 1 ;
V_52 = ( T_3 ) ( V_52 << ( 16 - V_51 ) ) >> ( 16 - V_51 ) ;
* V_4 = V_52 ;
F_6 ( & V_2 -> V_54 ) ;
return V_59 ;
default:
return - V_66 ;
}
}
static int T_4 F_22 ( struct V_69 * V_70 )
{
int V_5 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
V_2 = F_23 ( sizeof( * V_7 ) ) ;
if ( V_2 == NULL ) {
V_5 = - V_71 ;
goto V_25;
}
V_7 = F_2 ( V_2 ) ;
F_24 ( V_70 , V_2 ) ;
V_7 -> V_10 = V_70 ;
F_25 ( & V_7 -> V_8 ) ;
V_2 -> V_72 = V_70 -> V_24 . V_73 -> V_72 ;
V_2 -> V_24 . V_74 = & V_70 -> V_24 ;
V_2 -> V_75 = V_76 ;
V_2 -> V_77 = F_26 ( V_76 ) ;
V_2 -> V_78 = & V_79 ;
V_2 -> V_80 = V_81 ;
V_5 = F_27 ( V_2 ) ;
if ( V_5 )
goto V_82;
V_5 = F_28 ( V_2 ,
V_76 ,
F_26 ( V_76 ) ) ;
if ( V_5 ) {
F_29 ( V_83 L_14 ) ;
goto V_84;
}
if ( V_70 -> V_85 ) {
V_5 = F_30 ( V_2 ) ;
if ( V_5 )
goto V_86;
}
V_5 = F_18 ( V_2 ) ;
if ( V_5 )
goto V_87;
V_5 = F_31 ( V_2 ) ;
if ( V_5 )
goto V_87;
return 0 ;
V_87:
F_32 ( V_2 ) ;
V_86:
F_33 ( V_2 ) ;
V_84:
F_34 ( V_2 ) ;
V_82:
F_35 ( V_2 ) ;
V_25:
return V_5 ;
}
static int T_5 F_36 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_37 ( V_70 ) ;
F_38 ( V_2 ) ;
F_32 ( V_2 ) ;
F_33 ( V_2 ) ;
F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
