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
int * V_4 , int * V_46 ,
long V_47 )
{
int V_5 ;
int V_48 ;
T_1 V_49 ;
T_3 V_50 ;
int V_51 ;
switch ( V_47 ) {
case V_52 :
F_3 ( & V_2 -> V_53 ) ;
V_49 = V_54 [ V_45 -> V_55 ] [ 0 ] ;
V_5 = F_11 ( V_2 , V_49 , & V_50 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_53 ) ;
return V_5 ;
}
if ( V_50 & V_56 ) {
V_5 = F_14 ( V_2 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_53 ) ;
return V_5 ;
}
}
V_50 = V_50 & ( ( 1 << V_45 -> V_57 . V_58 ) - 1 ) ;
if ( V_45 -> V_57 . V_59 == 's' )
V_50 = ( T_3 ) ( V_50 <<
( 16 - V_45 -> V_57 . V_58 ) ) >>
( 16 - V_45 -> V_57 . V_58 ) ;
* V_4 = V_50 ;
F_6 ( & V_2 -> V_53 ) ;
return V_60 ;
case V_61 :
switch ( V_45 -> type ) {
case V_62 :
if ( V_45 -> V_63 == 0 ) {
* V_4 = 1 ;
* V_46 = 220000 ;
} else {
* V_4 = 0 ;
* V_46 = 610000 ;
}
return V_64 ;
case V_65 :
* V_4 = - 470 ;
* V_46 = 0 ;
return V_64 ;
case V_66 :
* V_4 = 0 ;
switch ( V_45 -> V_67 ) {
case V_68 :
case V_69 :
* V_46 = F_21 ( 17125 ) ;
break;
case V_70 :
case V_71 :
* V_46 = F_21 ( 8407 ) ;
break;
}
return V_64 ;
default:
return - V_72 ;
}
break;
case V_73 :
* V_4 = 25000 / - 470 - 1278 ;
return V_60 ;
case V_74 :
case V_75 :
if ( V_47 == V_74 ) {
V_48 = 12 ;
V_51 = 1 ;
} else {
V_48 = 14 ;
V_51 = 2 ;
}
F_3 ( & V_2 -> V_53 ) ;
V_49 = V_54 [ V_45 -> V_55 ] [ V_51 ] ;
V_5 = F_11 ( V_2 , V_49 , & V_50 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_53 ) ;
return V_5 ;
}
V_50 &= ( 1 << V_48 ) - 1 ;
V_50 = ( T_3 ) ( V_50 << ( 16 - V_48 ) ) >> ( 16 - V_48 ) ;
* V_4 = V_50 ;
F_6 ( & V_2 -> V_53 ) ;
return V_60 ;
}
return - V_72 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_44 const * V_45 ,
int V_4 ,
int V_46 ,
long V_47 )
{
int V_48 ;
T_3 V_50 ;
T_1 V_49 ;
switch ( V_47 ) {
case V_74 :
switch ( V_45 -> type ) {
case V_66 :
V_48 = 12 ;
break;
default:
return - V_72 ;
} ;
V_50 = V_4 & ( ( 1 << V_48 ) - 1 ) ;
V_49 = V_54 [ V_45 -> V_55 ] [ 1 ] ;
return F_7 ( V_2 , V_49 , V_50 ) ;
}
return - V_72 ;
}
static int T_4 F_23 ( struct V_76 * V_77 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_2 = F_24 ( sizeof( * V_7 ) ) ;
if ( V_2 == NULL ) {
V_5 = - V_78 ;
goto V_25;
}
V_7 = F_2 ( V_2 ) ;
F_25 ( V_77 , V_2 ) ;
V_7 -> V_10 = V_77 ;
F_26 ( & V_7 -> V_8 ) ;
V_2 -> V_79 = V_77 -> V_24 . V_80 -> V_79 ;
V_2 -> V_24 . V_81 = & V_77 -> V_24 ;
V_2 -> V_82 = & V_83 ;
V_2 -> V_84 = V_85 ;
V_2 -> V_86 = F_27 ( V_85 ) ;
V_2 -> V_87 = V_88 ;
V_5 = F_28 ( V_2 ) ;
if ( V_5 )
goto V_89;
V_5 = F_29 ( V_2 ,
V_85 ,
6 ) ;
if ( V_5 ) {
F_30 ( V_90 L_14 ) ;
goto V_91;
}
if ( V_77 -> V_92 ) {
V_5 = F_31 ( V_2 ) ;
if ( V_5 )
goto V_93;
}
V_5 = F_18 ( V_2 ) ;
if ( V_5 )
goto V_94;
V_5 = F_32 ( V_2 ) ;
if ( V_5 )
goto V_94;
return 0 ;
V_94:
F_33 ( V_2 ) ;
V_93:
F_34 ( V_2 ) ;
V_91:
F_35 ( V_2 ) ;
V_89:
F_36 ( V_2 ) ;
V_25:
return V_5 ;
}
static int T_5 F_37 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_38 ( V_77 ) ;
F_39 ( V_2 ) ;
F_33 ( V_2 ) ;
F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
