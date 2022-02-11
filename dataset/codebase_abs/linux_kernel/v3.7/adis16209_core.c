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
. V_21 = 30 ,
} , {
. V_17 = V_7 -> V_9 + 2 ,
. V_18 = 8 ,
. V_19 = 2 ,
. V_21 = 30 ,
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
. V_21 = 30 ,
} , {
. V_22 = V_7 -> V_23 ,
. V_18 = 8 ,
. V_19 = 2 ,
. V_21 = 30 ,
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
static int F_14 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_1 ( V_2 ,
V_26 ,
V_27 ) ;
if ( V_5 )
F_13 ( & V_2 -> V_24 , L_2 ) ;
return V_5 ;
}
int F_15 ( struct V_1 * V_2 , bool V_28 )
{
int V_5 = 0 ;
T_2 V_29 ;
V_5 = F_11 ( V_2 , V_30 , & V_29 ) ;
if ( V_5 )
goto V_25;
V_29 |= V_31 ;
V_29 &= ~ V_32 ;
if ( V_28 )
V_29 |= V_33 ;
else
V_29 &= ~ V_33 ;
V_5 = F_7 ( V_2 , V_30 , V_29 ) ;
V_25:
return V_5 ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_2 V_34 ;
int V_5 ;
V_5 = F_11 ( V_2 ,
V_35 , & V_34 ) ;
if ( V_5 < 0 ) {
F_13 ( & V_2 -> V_24 , L_3 ) ;
goto V_25;
}
V_5 = V_34 & 0x1F ;
if ( V_34 & V_36 )
F_13 ( & V_2 -> V_24 , L_4 ) ;
if ( V_34 & V_37 )
F_13 ( & V_2 -> V_24 , L_5 ) ;
if ( V_34 & V_38 )
F_13 ( & V_2 -> V_24 , L_6 ) ;
if ( V_34 & V_39 )
F_13 ( & V_2 -> V_24 , L_7 ) ;
if ( V_34 & V_40 )
F_13 ( & V_2 -> V_24 , L_8 ) ;
V_25:
return V_5 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_7 ( V_2 ,
V_30 ,
V_41 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_24 , L_9 ) ;
goto V_42;
}
F_16 ( V_2 ) ;
V_42:
return V_5 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_15 ( V_2 , false ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_24 , L_10 ) ;
goto V_42;
}
V_5 = F_17 ( V_2 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_24 , L_11 ) ;
goto V_42;
}
V_5 = F_16 ( V_2 ) ;
if ( V_5 ) {
F_14 ( V_2 ) ;
F_13 ( & V_2 -> V_24 , L_12 ) ;
F_19 ( V_43 ) ;
V_5 = F_16 ( V_2 ) ;
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
int V_48 ;
T_3 V_49 ;
T_1 V_50 ;
switch ( V_47 ) {
case V_51 :
switch ( V_45 -> type ) {
case V_52 :
case V_53 :
V_48 = 14 ;
break;
default:
return - V_54 ;
} ;
V_49 = V_4 & ( ( 1 << V_48 ) - 1 ) ;
V_50 = V_55 [ V_45 -> V_56 ] [ 1 ] ;
return F_7 ( V_2 , V_50 , V_49 ) ;
}
return - V_54 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_44 const * V_45 ,
int * V_4 , int * V_46 ,
long V_47 )
{
int V_5 ;
int V_48 ;
T_1 V_50 ;
T_3 V_49 ;
switch ( V_47 ) {
case V_57 :
F_3 ( & V_2 -> V_58 ) ;
V_50 = V_55 [ V_45 -> V_56 ] [ 0 ] ;
V_5 = F_11 ( V_2 , V_50 , & V_49 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_58 ) ;
return V_5 ;
}
if ( V_49 & V_59 ) {
V_5 = F_16 ( V_2 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_58 ) ;
return V_5 ;
}
}
V_49 = V_49 & ( ( 1 << V_45 -> V_60 . V_61 ) - 1 ) ;
if ( V_45 -> V_60 . V_62 == 's' )
V_49 = ( T_3 ) ( V_49 <<
( 16 - V_45 -> V_60 . V_61 ) ) >>
( 16 - V_45 -> V_60 . V_61 ) ;
* V_4 = V_49 ;
F_6 ( & V_2 -> V_58 ) ;
return V_63 ;
case V_64 :
switch ( V_45 -> type ) {
case V_65 :
* V_4 = 0 ;
if ( V_45 -> V_66 == 0 )
* V_46 = 305180 ;
else
* V_46 = 610500 ;
return V_67 ;
case V_68 :
* V_4 = - 470 ;
* V_46 = 0 ;
return V_67 ;
case V_52 :
* V_4 = 0 ;
* V_46 = F_22 ( 244140 ) ;
return V_69 ;
case V_53 :
case V_70 :
* V_4 = 0 ;
* V_46 = 25000 ;
return V_67 ;
default:
return - V_54 ;
}
break;
case V_71 :
* V_4 = 25000 / - 470 - 0x4FE ;
return V_63 ;
case V_51 :
switch ( V_45 -> type ) {
case V_52 :
V_48 = 14 ;
break;
default:
return - V_54 ;
} ;
F_3 ( & V_2 -> V_58 ) ;
V_50 = V_55 [ V_45 -> V_56 ] [ 1 ] ;
V_5 = F_11 ( V_2 , V_50 , & V_49 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_58 ) ;
return V_5 ;
}
V_49 &= ( 1 << V_48 ) - 1 ;
V_49 = ( T_3 ) ( V_49 << ( 16 - V_48 ) ) >> ( 16 - V_48 ) ;
* V_4 = V_49 ;
F_6 ( & V_2 -> V_58 ) ;
return V_63 ;
}
return - V_54 ;
}
static int T_4 F_23 ( struct V_72 * V_73 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_2 = F_24 ( sizeof( * V_7 ) ) ;
if ( V_2 == NULL ) {
V_5 = - V_74 ;
goto V_25;
}
V_7 = F_2 ( V_2 ) ;
F_25 ( V_73 , V_2 ) ;
V_7 -> V_10 = V_73 ;
F_26 ( & V_7 -> V_8 ) ;
V_2 -> V_75 = V_73 -> V_24 . V_76 -> V_75 ;
V_2 -> V_24 . V_77 = & V_73 -> V_24 ;
V_2 -> V_78 = & V_79 ;
V_2 -> V_80 = V_81 ;
V_2 -> V_82 = F_27 ( V_81 ) ;
V_2 -> V_83 = V_84 ;
V_5 = F_28 ( V_2 ) ;
if ( V_5 )
goto V_85;
V_5 = F_29 ( V_2 ,
V_81 ,
F_27 ( V_81 ) ) ;
if ( V_5 ) {
F_30 ( V_86 L_14 ) ;
goto V_87;
}
if ( V_73 -> V_88 ) {
V_5 = F_31 ( V_2 ) ;
if ( V_5 )
goto V_89;
}
V_5 = F_18 ( V_2 ) ;
if ( V_5 )
goto V_90;
V_5 = F_32 ( V_2 ) ;
if ( V_5 )
goto V_90;
return 0 ;
V_90:
F_33 ( V_2 ) ;
V_89:
F_34 ( V_2 ) ;
V_87:
F_35 ( V_2 ) ;
V_85:
F_36 ( V_2 ) ;
V_25:
return V_5 ;
}
static int T_5 F_37 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_38 ( V_73 ) ;
F_39 ( V_2 ) ;
F_33 ( V_2 ) ;
F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
