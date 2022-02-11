static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = F_5 ( V_3 ) ;
V_9 -> V_11 [ 1 ] = V_4 ;
V_5 = F_6 ( V_9 -> V_12 , V_9 -> V_11 , 2 ) ;
F_7 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int F_8 ( struct V_6 * V_7 ,
T_1 V_13 ,
T_2 V_14 )
{
int V_5 ;
struct V_15 V_16 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_17 V_18 [] = {
{
. V_19 = V_9 -> V_11 ,
. V_20 = 8 ,
. V_21 = 2 ,
. V_22 = 1 ,
} , {
. V_19 = V_9 -> V_11 + 2 ,
. V_20 = 8 ,
. V_21 = 2 ,
} ,
} ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = F_5 ( V_13 ) ;
V_9 -> V_11 [ 1 ] = V_14 & 0xFF ;
V_9 -> V_11 [ 2 ] = F_5 ( V_13 + 1 ) ;
V_9 -> V_11 [ 3 ] = ( V_14 >> 8 ) & 0xFF ;
F_9 ( & V_16 ) ;
F_10 ( & V_18 [ 0 ] , & V_16 ) ;
F_10 ( & V_18 [ 1 ] , & V_16 ) ;
V_5 = F_11 ( V_9 -> V_12 , & V_16 ) ;
F_7 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int F_12 ( struct V_6 * V_7 ,
T_1 V_13 ,
T_2 * V_4 )
{
struct V_15 V_16 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_5 ;
struct V_17 V_18 [] = {
{
. V_19 = V_9 -> V_11 ,
. V_20 = 8 ,
. V_21 = 2 ,
. V_22 = 1 ,
. V_23 = 20 ,
} , {
. V_24 = V_9 -> V_25 ,
. V_20 = 8 ,
. V_21 = 2 ,
. V_23 = 20 ,
} ,
} ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = F_13 ( V_13 ) ;
V_9 -> V_11 [ 1 ] = 0 ;
F_9 ( & V_16 ) ;
F_10 ( & V_18 [ 0 ] , & V_16 ) ;
F_10 ( & V_18 [ 1 ] , & V_16 ) ;
V_5 = F_11 ( V_9 -> V_12 , & V_16 ) ;
if ( V_5 ) {
F_14 ( & V_9 -> V_12 -> V_2 , L_1 ,
V_13 ) ;
goto V_26;
}
* V_4 = ( V_9 -> V_25 [ 0 ] << 8 ) | V_9 -> V_25 [ 1 ] ;
V_26:
F_7 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_1 ( V_2 ,
V_27 ,
V_28 ) ;
if ( V_5 )
F_14 ( V_2 , L_2 ) ;
return V_5 ;
}
static T_3 F_16 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
const char * V_31 , T_4 V_21 )
{
if ( V_21 < 1 )
return - V_32 ;
switch ( V_31 [ 0 ] ) {
case '1' :
case 'y' :
case 'Y' :
return F_15 ( V_2 ) ;
}
return - V_32 ;
}
int F_17 ( struct V_6 * V_7 , bool V_33 )
{
int V_5 = 0 ;
T_2 V_34 ;
V_5 = F_12 ( V_7 , V_35 , & V_34 ) ;
if ( V_5 )
goto V_26;
V_34 |= V_36 ;
V_34 &= ~ V_37 ;
if ( V_33 )
V_34 |= V_38 ;
else
V_34 &= ~ V_38 ;
V_5 = F_8 ( V_7 , V_35 , V_34 ) ;
V_26:
return V_5 ;
}
static int F_18 ( struct V_6 * V_7 )
{
T_2 V_39 ;
int V_5 ;
V_5 = F_12 ( V_7 ,
V_40 , & V_39 ) ;
if ( V_5 < 0 ) {
F_14 ( & V_7 -> V_2 , L_3 ) ;
goto V_26;
}
V_5 = V_39 & 0xF ;
if ( V_5 )
V_5 = - V_41 ;
if ( V_39 & V_42 )
F_14 ( & V_7 -> V_2 , L_4 ) ;
if ( V_39 & V_43 )
F_14 ( & V_7 -> V_2 , L_5 ) ;
if ( V_39 & V_44 )
F_14 ( & V_7 -> V_2 , L_6 ) ;
if ( V_39 & V_45 )
F_14 ( & V_7 -> V_2 , L_7 ) ;
V_26:
return V_5 ;
}
static int F_19 ( struct V_6 * V_7 )
{
int V_5 ;
V_5 = F_8 ( V_7 ,
V_35 ,
V_46 ) ;
if ( V_5 ) {
F_14 ( & V_7 -> V_2 , L_8 ) ;
goto V_47;
}
V_5 = F_18 ( V_7 ) ;
V_47:
return V_5 ;
}
static int F_20 ( struct V_8 * V_9 )
{
int V_5 ;
struct V_1 * V_2 = & V_9 -> V_7 -> V_2 ;
V_5 = F_17 ( V_9 -> V_7 , false ) ;
if ( V_5 ) {
F_14 ( V_2 , L_9 ) ;
goto V_47;
}
V_5 = F_19 ( V_9 -> V_7 ) ;
if ( V_5 ) {
F_14 ( V_2 , L_10 ) ;
goto V_47;
}
V_5 = F_18 ( V_9 -> V_7 ) ;
if ( V_5 ) {
F_15 ( V_2 ) ;
F_14 ( V_2 , L_11 ) ;
F_21 ( V_48 ) ;
V_5 = F_18 ( V_9 -> V_7 ) ;
if ( V_5 ) {
F_14 ( V_2 , L_12 ) ;
goto V_47;
}
}
F_22 (KERN_INFO DRIVER_NAME L_13 ,
st->us->chip_select, st->us->irq) ;
V_47:
return V_5 ;
}
static int F_23 ( struct V_6 * V_7 ,
struct V_49 const * V_50 ,
int * V_4 , int * V_51 ,
long V_52 )
{
int V_5 ;
int V_53 ;
T_1 V_54 ;
T_5 V_55 ;
switch ( V_52 ) {
case 0 :
F_4 ( & V_7 -> V_56 ) ;
V_54 = V_57 [ V_50 -> V_58 ] [ 0 ] ;
V_5 = F_12 ( V_7 , V_54 , & V_55 ) ;
if ( V_5 )
return V_5 ;
if ( V_55 & V_59 ) {
V_5 = F_18 ( V_7 ) ;
if ( V_5 )
return V_5 ;
}
V_55 = V_55 & ( ( 1 << V_50 -> V_60 . V_61 ) - 1 ) ;
if ( V_50 -> V_60 . V_62 == 's' )
V_55 = ( T_5 ) ( V_55 <<
( 16 - V_50 -> V_60 . V_61 ) ) >>
( 16 - V_50 -> V_60 . V_61 ) ;
* V_4 = V_55 ;
F_7 ( & V_7 -> V_56 ) ;
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
* V_51 = 462500 ;
return V_68 ;
case V_71 :
* V_4 = 0 ;
* V_51 = 100000 ;
return V_68 ;
default:
return - V_32 ;
}
break;
case ( 1 << V_72 ) :
* V_4 = 25 ;
return V_63 ;
case ( 1 << V_73 ) :
switch ( V_50 -> type ) {
case V_70 :
V_53 = 12 ;
break;
case V_71 :
V_53 = 9 ;
break;
default:
return - V_32 ;
} ;
F_4 ( & V_7 -> V_56 ) ;
V_54 = V_57 [ V_50 -> V_58 ] [ 1 ] ;
V_5 = F_12 ( V_7 , V_54 , & V_55 ) ;
if ( V_5 ) {
F_7 ( & V_7 -> V_56 ) ;
return V_5 ;
}
V_55 &= ( 1 << V_53 ) - 1 ;
V_55 = ( T_5 ) ( V_55 << ( 16 - V_53 ) ) >> ( 16 - V_53 ) ;
* V_4 = V_55 ;
F_7 ( & V_7 -> V_56 ) ;
return V_63 ;
}
return - V_32 ;
}
static int F_24 ( struct V_6 * V_7 ,
struct V_49 const * V_50 ,
int V_4 ,
int V_51 ,
long V_52 )
{
int V_53 ;
T_5 V_55 ;
T_1 V_54 ;
switch ( V_52 ) {
case ( 1 << V_73 ) :
switch ( V_50 -> type ) {
case V_70 :
V_53 = 12 ;
break;
case V_71 :
V_53 = 9 ;
break;
default:
return - V_32 ;
} ;
V_55 = V_4 & ( ( 1 << V_53 ) - 1 ) ;
V_54 = V_57 [ V_50 -> V_58 ] [ 1 ] ;
return F_8 ( V_7 , V_54 , V_55 ) ;
}
return - V_32 ;
}
static int T_6 F_25 ( struct V_74 * V_75 )
{
int V_5 , V_76 = 0 ;
struct V_8 * V_9 = F_26 ( sizeof *V_9 , V_77 ) ;
if ( ! V_9 ) {
V_5 = - V_78 ;
goto V_26;
}
F_27 ( V_75 , V_9 ) ;
V_9 -> V_25 = F_26 ( sizeof( * V_9 -> V_25 ) * V_79 , V_77 ) ;
if ( V_9 -> V_25 == NULL ) {
V_5 = - V_78 ;
goto V_80;
}
V_9 -> V_11 = F_26 ( sizeof( * V_9 -> V_11 ) * V_81 , V_77 ) ;
if ( V_9 -> V_11 == NULL ) {
V_5 = - V_78 ;
goto V_82;
}
V_9 -> V_12 = V_75 ;
F_28 ( & V_9 -> V_10 ) ;
V_9 -> V_7 = F_29 ( 0 ) ;
if ( V_9 -> V_7 == NULL ) {
V_5 = - V_78 ;
goto V_83;
}
V_9 -> V_7 -> V_84 = V_75 -> V_2 . V_85 -> V_84 ;
V_9 -> V_7 -> V_2 . V_86 = & V_75 -> V_2 ;
V_9 -> V_7 -> V_87 = & V_88 ;
V_9 -> V_7 -> V_89 = V_90 ;
V_9 -> V_7 -> V_91 = F_30 ( V_90 ) ;
V_9 -> V_7 -> V_92 = ( void * ) ( V_9 ) ;
V_9 -> V_7 -> V_93 = V_94 ;
V_5 = F_31 ( V_9 -> V_7 ) ;
if ( V_5 )
goto V_95;
V_5 = F_32 ( V_9 -> V_7 ) ;
if ( V_5 )
goto V_96;
V_76 = 1 ;
V_5 = F_33 ( V_9 -> V_7 -> V_97 , 0 ,
V_90 ,
F_30 ( V_90 ) ) ;
if ( V_5 ) {
F_22 ( V_98 L_14 ) ;
goto V_96;
}
if ( V_75 -> V_99 ) {
V_5 = F_34 ( V_9 -> V_7 ) ;
if ( V_5 )
goto V_100;
}
V_5 = F_20 ( V_9 ) ;
if ( V_5 )
goto V_101;
return 0 ;
V_101:
F_35 ( V_9 -> V_7 ) ;
V_100:
F_36 ( V_9 -> V_7 -> V_97 ) ;
V_96:
F_37 ( V_9 -> V_7 ) ;
V_95:
if ( V_76 )
F_38 ( V_9 -> V_7 ) ;
else
F_39 ( V_9 -> V_7 ) ;
V_83:
F_40 ( V_9 -> V_11 ) ;
V_82:
F_40 ( V_9 -> V_25 ) ;
V_80:
F_40 ( V_9 ) ;
V_26:
return V_5 ;
}
static int F_41 ( struct V_74 * V_75 )
{
struct V_8 * V_9 = F_42 ( V_75 ) ;
struct V_6 * V_7 = V_9 -> V_7 ;
F_35 ( V_7 ) ;
F_36 ( V_7 -> V_97 ) ;
F_38 ( V_7 ) ;
F_37 ( V_7 ) ;
F_40 ( V_9 -> V_11 ) ;
F_40 ( V_9 -> V_25 ) ;
F_40 ( V_9 ) ;
return 0 ;
}
static T_7 int F_43 ( void )
{
return F_44 ( & V_102 ) ;
}
static T_8 void F_45 ( void )
{
F_46 ( & V_102 ) ;
}
