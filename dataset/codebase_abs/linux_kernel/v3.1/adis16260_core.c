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
. V_21 = 20 ,
} , {
. V_17 = V_7 -> V_9 + 2 ,
. V_18 = 8 ,
. V_19 = 2 ,
. V_21 = 20 ,
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
static T_3 F_14 ( struct V_26 * V_24 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_1 * V_2 = F_15 ( V_24 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( F_16 ( V_7 -> V_10 ) -> V_30 )
return sprintf ( V_29 , L_2 , L_3 ) ;
else
return sprintf ( V_29 , L_2 , L_4 ) ;
}
static T_3 F_17 ( struct V_26 * V_24 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_1 * V_2 = F_15 ( V_24 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_5 , V_19 = 0 ;
T_2 V_31 ;
int V_32 ;
V_5 = F_11 ( V_2 ,
V_33 ,
& V_31 ) ;
if ( V_5 )
return V_5 ;
if ( F_16 ( V_7 -> V_10 ) -> V_30 )
V_32 = ( V_31 & V_34 ) ? 8 : 256 ;
else
V_32 = ( V_31 & V_34 ) ? 66 : 2048 ;
V_32 /= ( V_31 & V_35 ) + 1 ;
V_19 = sprintf ( V_29 , L_5 , V_32 ) ;
return V_19 ;
}
static T_3 F_18 ( struct V_26 * V_24 ,
struct V_27 * V_28 ,
const char * V_29 ,
T_4 V_19 )
{
struct V_1 * V_2 = F_15 ( V_24 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
long V_4 ;
int V_5 ;
T_1 V_31 ;
V_5 = F_19 ( V_29 , 10 , & V_4 ) ;
if ( V_5 )
return V_5 ;
F_3 ( & V_2 -> V_36 ) ;
if ( F_16 ( V_7 -> V_10 ) ) {
V_31 = ( 256 / V_4 ) ;
if ( V_31 > 0 )
V_31 -- ;
V_31 &= V_35 ;
} else {
V_31 = ( 2048 / V_4 ) ;
if ( V_31 > 0 )
V_31 -- ;
V_31 &= V_35 ;
}
if ( ( V_31 & V_35 ) >= 0x0A )
V_7 -> V_10 -> V_37 = V_38 ;
else
V_7 -> V_10 -> V_37 = V_39 ;
V_5 = F_1 ( V_2 ,
V_33 ,
V_31 ) ;
F_6 ( & V_2 -> V_36 ) ;
return V_5 ? V_5 : V_19 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_1 ( V_2 ,
V_40 ,
V_41 ) ;
if ( V_5 )
F_13 ( & V_2 -> V_24 , L_6 ) ;
return V_5 ;
}
static T_3 F_21 ( struct V_26 * V_24 ,
struct V_27 * V_28 ,
const char * V_29 , T_4 V_19 )
{
struct V_1 * V_2 = F_15 ( V_24 ) ;
if ( V_19 < 1 )
return - V_42 ;
switch ( V_29 [ 0 ] ) {
case '1' :
case 'y' :
case 'Y' :
return F_20 ( V_2 ) ;
}
return - V_42 ;
}
int F_22 ( struct V_1 * V_2 , bool V_43 )
{
int V_5 ;
T_2 V_44 ;
V_5 = F_11 ( V_2 , V_45 , & V_44 ) ;
if ( V_5 )
goto V_25;
V_44 |= V_46 ;
if ( V_43 )
V_44 |= V_47 ;
else
V_44 &= ~ V_47 ;
V_5 = F_7 ( V_2 , V_45 , V_44 ) ;
if ( V_5 )
goto V_25;
V_25:
return V_5 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_5 ;
T_2 V_4 = V_48 ;
V_5 = F_7 ( V_2 , V_49 , V_4 ) ;
if ( V_5 )
F_13 ( & V_2 -> V_24 , L_7 ) ;
return V_5 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_7 ( V_2 ,
V_45 ,
V_50 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_24 , L_8 ) ;
goto V_51;
}
F_25 ( V_2 ) ;
V_51:
return V_5 ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_2 V_52 ;
int V_5 ;
struct V_26 * V_24 = & V_2 -> V_24 ;
V_5 = F_11 ( V_2 ,
V_53 ,
& V_52 ) ;
if ( V_5 < 0 ) {
F_13 ( V_24 , L_9 ) ;
goto V_25;
}
V_5 = V_52 & 0x7F ;
if ( V_52 & V_54 )
F_13 ( V_24 , L_10 ) ;
if ( V_52 & V_55 )
F_13 ( V_24 , L_11 ) ;
if ( V_52 & V_56 )
F_13 ( V_24 , L_12 ) ;
if ( V_52 & V_57 )
F_13 ( V_24 , L_13 ) ;
if ( V_52 & V_58 )
F_13 ( V_24 , L_14 ) ;
if ( V_52 & V_59 )
F_13 ( V_24 , L_15 ) ;
if ( V_52 & V_60 )
F_13 ( V_24 , L_16 ) ;
V_25:
return V_5 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_26 * V_24 = & V_2 -> V_24 ;
V_5 = F_22 ( V_2 , false ) ;
if ( V_5 ) {
F_13 ( V_24 , L_17 ) ;
goto V_51;
}
V_5 = F_24 ( V_2 ) ;
if ( V_5 ) {
F_13 ( V_24 , L_18 ) ;
goto V_51;
}
V_5 = F_25 ( V_2 ) ;
if ( V_5 ) {
F_20 ( V_2 ) ;
F_13 ( V_24 , L_19 ) ;
F_27 ( V_61 ) ;
V_5 = F_25 ( V_2 ) ;
if ( V_5 ) {
F_13 ( V_24 , L_20 ) ;
goto V_51;
}
}
V_51:
return V_5 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_62 const * V_63 ,
int * V_4 , int * V_64 ,
long V_65 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_5 ;
int V_66 ;
T_1 V_67 ;
T_5 V_68 ;
switch ( V_65 ) {
case 0 :
F_3 ( & V_2 -> V_36 ) ;
V_67 = V_69 [ V_63 -> V_70 ] [ 0 ] ;
V_5 = F_11 ( V_2 , V_67 , & V_68 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_36 ) ;
return V_5 ;
}
if ( V_68 & V_71 ) {
V_5 = F_25 ( V_2 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_36 ) ;
return V_5 ;
}
}
V_68 = V_68 & ( ( 1 << V_63 -> V_72 . V_73 ) - 1 ) ;
if ( V_63 -> V_72 . V_74 == 's' )
V_68 = ( T_5 ) ( V_68 <<
( 16 - V_63 -> V_72 . V_73 ) ) >>
( 16 - V_63 -> V_72 . V_73 ) ;
* V_4 = V_68 ;
F_6 ( & V_2 -> V_36 ) ;
return V_75 ;
case ( 1 << V_76 ) :
case ( 1 << V_77 ) :
switch ( V_63 -> type ) {
case V_78 :
* V_4 = 0 ;
if ( F_16 ( V_7 -> V_10 ) -> V_30 )
* V_64 = 320 ;
else
* V_64 = 1278 ;
return V_79 ;
case V_80 :
* V_4 = 0 ;
if ( V_63 -> V_81 == 0 )
* V_64 = 18315 ;
else
* V_64 = 610500 ;
return V_79 ;
case V_82 :
* V_4 = 0 ;
* V_64 = 145300 ;
return V_79 ;
default:
return - V_42 ;
}
break;
case ( 1 << V_83 ) :
* V_4 = 25 ;
return V_75 ;
case ( 1 << V_84 ) :
switch ( V_63 -> type ) {
case V_78 :
V_66 = 12 ;
break;
default:
return - V_42 ;
} ;
F_3 ( & V_2 -> V_36 ) ;
V_67 = V_69 [ V_63 -> V_70 ] [ 1 ] ;
V_5 = F_11 ( V_2 , V_67 , & V_68 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_36 ) ;
return V_5 ;
}
V_68 &= ( 1 << V_66 ) - 1 ;
V_68 = ( T_5 ) ( V_68 << ( 16 - V_66 ) ) >> ( 16 - V_66 ) ;
* V_4 = V_68 ;
F_6 ( & V_2 -> V_36 ) ;
return V_75 ;
case ( 1 << V_85 ) :
switch ( V_63 -> type ) {
case V_78 :
V_66 = 12 ;
break;
default:
return - V_42 ;
} ;
F_3 ( & V_2 -> V_36 ) ;
V_67 = V_69 [ V_63 -> V_70 ] [ 2 ] ;
V_5 = F_11 ( V_2 , V_67 , & V_68 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_36 ) ;
return V_5 ;
}
* V_4 = ( 1 << V_66 ) - 1 ;
F_6 ( & V_2 -> V_36 ) ;
return V_75 ;
}
return - V_42 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_62 const * V_63 ,
int V_4 ,
int V_64 ,
long V_65 )
{
int V_66 = 12 ;
T_5 V_68 ;
T_1 V_67 ;
switch ( V_65 ) {
case ( 1 << V_84 ) :
V_68 = V_4 & ( ( 1 << V_66 ) - 1 ) ;
V_67 = V_69 [ V_63 -> V_70 ] [ 1 ] ;
return F_7 ( V_2 , V_67 , V_68 ) ;
case ( 1 << V_85 ) :
V_68 = V_4 & ( ( 1 << V_66 ) - 1 ) ;
V_67 = V_69 [ V_63 -> V_70 ] [ 2 ] ;
return F_7 ( V_2 , V_67 , V_68 ) ;
}
return - V_42 ;
}
static int T_6 F_30 ( struct V_86 * V_87 )
{
int V_5 , V_88 = 0 ;
struct V_89 * V_90 = V_87 -> V_24 . V_91 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_2 = F_31 ( sizeof( * V_7 ) ) ;
if ( V_2 == NULL ) {
V_5 = - V_92 ;
goto V_25;
}
V_7 = F_2 ( V_2 ) ;
if ( V_90 )
V_7 -> V_93 = V_90 -> V_93 ;
F_32 ( V_87 , V_7 ) ;
V_7 -> V_10 = V_87 ;
F_33 ( & V_7 -> V_8 ) ;
V_2 -> V_94 = F_16 ( V_7 -> V_10 ) -> V_94 ;
V_2 -> V_24 . V_95 = & V_87 -> V_24 ;
V_2 -> V_96 = & V_97 ;
V_2 -> V_98
= F_34 ( V_99 ) ;
if ( V_90 && V_90 -> V_100 )
switch ( V_90 -> V_100 ) {
case 'x' :
V_2 -> V_101 = V_99 ;
break;
case 'y' :
V_2 -> V_101 = V_102 ;
break;
case 'z' :
V_2 -> V_101 = V_103 ;
break;
default:
return - V_42 ;
}
else
V_2 -> V_101 = V_99 ;
V_2 -> V_98 = F_34 ( V_99 ) ;
V_2 -> V_104 = V_105 ;
V_5 = F_35 ( V_2 ) ;
if ( V_5 )
goto V_106;
V_5 = F_36 ( V_2 ) ;
if ( V_5 )
goto V_107;
V_88 = 1 ;
V_5 = F_37 ( V_2 -> V_108 , 0 ,
V_2 -> V_101 ,
F_34 ( V_99 ) ) ;
if ( V_5 ) {
F_38 ( V_109 L_21 ) ;
goto V_107;
}
if ( V_87 -> V_110 ) {
V_5 = F_39 ( V_2 ) ;
if ( V_5 )
goto V_111;
}
V_5 = F_26 ( V_2 ) ;
if ( V_5 )
goto V_112;
return 0 ;
V_112:
F_40 ( V_2 ) ;
V_111:
F_41 ( V_2 -> V_108 ) ;
V_107:
F_42 ( V_2 ) ;
V_106:
if ( V_88 )
F_43 ( V_2 ) ;
else
F_44 ( V_2 ) ;
V_25:
return V_5 ;
}
static int F_45 ( struct V_86 * V_87 )
{
int V_5 ;
struct V_1 * V_2 = F_46 ( V_87 ) ;
V_5 = F_23 ( V_2 ) ;
if ( V_5 )
goto V_51;
F_47 () ;
F_40 ( V_2 ) ;
F_41 ( V_2 -> V_108 ) ;
F_43 ( V_2 ) ;
F_42 ( V_2 ) ;
V_51:
return V_5 ;
}
static T_7 int F_48 ( void )
{
return F_49 ( & V_113 ) ;
}
static T_8 void F_50 ( void )
{
F_51 ( & V_113 ) ;
}
