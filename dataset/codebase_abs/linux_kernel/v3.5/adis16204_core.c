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
. V_20 = 1 ,
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
V_27 , & V_26 ) ;
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
static T_3 F_15 ( struct V_33 * V_24 ,
struct V_34 * V_35 ,
char * V_36 )
{
struct V_1 * V_2 = F_16 ( V_24 ) ;
struct V_37 * V_38 = F_17 ( V_35 ) ;
T_4 V_4 = 0 ;
T_3 V_5 ;
F_3 ( & V_2 -> V_39 ) ;
V_5 = F_11 ( V_2 ,
V_38 -> V_40 , ( T_2 * ) & V_4 ) ;
if ( ! V_5 ) {
if ( V_4 & V_41 )
F_14 ( V_2 ) ;
V_4 = ( ( T_4 ) ( V_4 << 2 ) >> 2 ) ;
V_5 = sprintf ( V_36 , L_8 , V_4 ) ;
}
F_6 ( & V_2 -> V_39 ) ;
return V_5 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_1 ( V_2 ,
V_42 ,
V_43 ) ;
if ( V_5 )
F_13 ( & V_2 -> V_24 , L_9 ) ;
return V_5 ;
}
static T_3 F_19 ( struct V_33 * V_24 ,
struct V_34 * V_35 ,
const char * V_36 , T_5 V_19 )
{
struct V_1 * V_2 = F_16 ( V_24 ) ;
if ( V_19 < 1 )
return - V_44 ;
switch ( V_36 [ 0 ] ) {
case '1' :
case 'y' :
case 'Y' :
return F_18 ( V_2 ) ;
}
return - V_44 ;
}
int F_20 ( struct V_1 * V_2 , bool V_45 )
{
int V_5 = 0 ;
T_2 V_46 ;
V_5 = F_11 ( V_2 , V_47 , & V_46 ) ;
if ( V_5 )
goto V_25;
V_46 |= V_48 ;
V_46 &= ~ V_49 ;
if ( V_45 )
V_46 |= V_50 ;
else
V_46 &= ~ V_50 ;
V_5 = F_7 ( V_2 , V_47 , V_46 ) ;
V_25:
return V_5 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_7 ( V_2 ,
V_47 ,
V_51 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_24 , L_10 ) ;
goto V_52;
}
F_14 ( V_2 ) ;
V_52:
return V_5 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_20 ( V_2 , false ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_24 , L_11 ) ;
goto V_52;
}
V_5 = F_21 ( V_2 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_24 , L_12 ) ;
goto V_52;
}
V_5 = F_14 ( V_2 ) ;
if ( V_5 ) {
F_18 ( V_2 ) ;
F_13 ( & V_2 -> V_24 , L_13 ) ;
F_23 ( V_53 ) ;
V_5 = F_14 ( V_2 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_24 , L_14 ) ;
goto V_52;
}
}
V_52:
return V_5 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_54 const * V_55 ,
int * V_4 , int * V_56 ,
long V_57 )
{
int V_5 ;
int V_58 ;
T_1 V_59 ;
T_4 V_60 ;
int V_61 ;
switch ( V_57 ) {
case V_62 :
F_3 ( & V_2 -> V_39 ) ;
V_59 = V_63 [ V_55 -> V_40 ] [ 0 ] ;
V_5 = F_11 ( V_2 , V_59 , & V_60 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_39 ) ;
return V_5 ;
}
if ( V_60 & V_41 ) {
V_5 = F_14 ( V_2 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_39 ) ;
return V_5 ;
}
}
V_60 = V_60 & ( ( 1 << V_55 -> V_64 . V_65 ) - 1 ) ;
if ( V_55 -> V_64 . V_66 == 's' )
V_60 = ( T_4 ) ( V_60 <<
( 16 - V_55 -> V_64 . V_65 ) ) >>
( 16 - V_55 -> V_64 . V_65 ) ;
* V_4 = V_60 ;
F_6 ( & V_2 -> V_39 ) ;
return V_67 ;
case V_68 :
switch ( V_55 -> type ) {
case V_69 :
* V_4 = 0 ;
if ( V_55 -> V_70 == 0 )
* V_56 = 1220 ;
else
* V_56 = 610 ;
return V_71 ;
case V_72 :
* V_4 = 0 ;
* V_56 = - 470000 ;
return V_71 ;
case V_73 :
* V_4 = 0 ;
if ( V_55 -> V_70 == 'x' )
* V_56 = 17125 ;
else
* V_56 = 8407 ;
return V_71 ;
default:
return - V_44 ;
}
break;
case V_74 :
* V_4 = 25 ;
return V_67 ;
case V_75 :
case V_76 :
if ( V_57 == V_75 ) {
V_58 = 12 ;
V_61 = 1 ;
} else {
V_58 = 14 ;
V_61 = 2 ;
}
F_3 ( & V_2 -> V_39 ) ;
V_59 = V_63 [ V_55 -> V_40 ] [ V_61 ] ;
V_5 = F_11 ( V_2 , V_59 , & V_60 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_39 ) ;
return V_5 ;
}
V_60 &= ( 1 << V_58 ) - 1 ;
V_60 = ( T_4 ) ( V_60 << ( 16 - V_58 ) ) >> ( 16 - V_58 ) ;
* V_4 = V_60 ;
F_6 ( & V_2 -> V_39 ) ;
return V_67 ;
}
return - V_44 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_54 const * V_55 ,
int V_4 ,
int V_56 ,
long V_57 )
{
int V_58 ;
T_4 V_60 ;
T_1 V_59 ;
switch ( V_57 ) {
case V_75 :
switch ( V_55 -> type ) {
case V_73 :
V_58 = 12 ;
break;
default:
return - V_44 ;
} ;
V_60 = V_4 & ( ( 1 << V_58 ) - 1 ) ;
V_59 = V_63 [ V_55 -> V_40 ] [ 1 ] ;
return F_7 ( V_2 , V_59 , V_60 ) ;
}
return - V_44 ;
}
static int T_6 F_26 ( struct V_77 * V_78 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_2 = F_27 ( sizeof( * V_7 ) ) ;
if ( V_2 == NULL ) {
V_5 = - V_79 ;
goto V_25;
}
V_7 = F_2 ( V_2 ) ;
F_28 ( V_78 , V_2 ) ;
V_7 -> V_10 = V_78 ;
F_29 ( & V_7 -> V_8 ) ;
V_2 -> V_80 = V_78 -> V_24 . V_81 -> V_80 ;
V_2 -> V_24 . V_82 = & V_78 -> V_24 ;
V_2 -> V_83 = & V_84 ;
V_2 -> V_85 = V_86 ;
V_2 -> V_87 = F_30 ( V_86 ) ;
V_2 -> V_88 = V_89 ;
V_5 = F_31 ( V_2 ) ;
if ( V_5 )
goto V_90;
V_5 = F_32 ( V_2 ,
V_86 ,
F_30 ( V_86 ) ) ;
if ( V_5 ) {
F_33 ( V_91 L_15 ) ;
goto V_92;
}
if ( V_78 -> V_93 ) {
V_5 = F_34 ( V_2 ) ;
if ( V_5 )
goto V_94;
}
V_5 = F_22 ( V_2 ) ;
if ( V_5 )
goto V_95;
V_5 = F_35 ( V_2 ) ;
if ( V_5 )
goto V_95;
return 0 ;
V_95:
F_36 ( V_2 ) ;
V_94:
F_37 ( V_2 ) ;
V_92:
F_38 ( V_2 ) ;
V_90:
F_39 ( V_2 ) ;
V_25:
return V_5 ;
}
static int F_40 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_41 ( V_78 ) ;
F_42 ( V_2 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
return 0 ;
}
