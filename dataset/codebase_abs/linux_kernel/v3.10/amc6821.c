static T_1 F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 = F_3 ( V_4 ) -> V_9 ;
return sprintf ( V_5 , L_1 , V_7 -> V_10 [ V_8 ] * 1000 ) ;
}
static T_1 F_4 (
struct V_1 * V_2 ,
struct V_3 * V_11 ,
const char * V_5 ,
T_2 V_12 )
{
struct V_13 * V_14 = F_5 ( V_2 ) ;
struct V_6 * V_7 = F_6 ( V_14 ) ;
int V_8 = F_3 ( V_11 ) -> V_9 ;
long V_15 ;
int V_16 = F_7 ( V_5 , 10 , & V_15 ) ;
if ( V_16 )
return V_16 ;
V_15 = F_8 ( V_15 / 1000 , - 128 , 127 ) ;
F_9 ( & V_7 -> V_17 ) ;
V_7 -> V_10 [ V_8 ] = V_15 ;
if ( F_10 ( V_14 , V_18 [ V_8 ] , V_7 -> V_10 [ V_8 ] ) ) {
F_11 ( & V_14 -> V_2 , L_2 ) ;
V_12 = - V_19 ;
}
F_12 ( & V_7 -> V_17 ) ;
return V_12 ;
}
static T_1 F_13 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 = F_3 ( V_4 ) -> V_9 ;
T_3 V_20 ;
switch ( V_8 ) {
case V_21 :
V_20 = V_7 -> V_22 & V_23 ;
break;
case V_24 :
V_20 = V_7 -> V_22 & V_25 ;
break;
case V_26 :
V_20 = V_7 -> V_27 & V_28 ;
break;
case V_29 :
V_20 = V_7 -> V_22 & V_30 ;
break;
case V_31 :
V_20 = V_7 -> V_22 & V_32 ;
break;
case V_33 :
V_20 = V_7 -> V_27 & V_34 ;
break;
default:
F_14 ( V_2 , L_3 , V_8 ) ;
return - V_35 ;
}
if ( V_20 )
return sprintf ( V_5 , L_4 ) ;
else
return sprintf ( V_5 , L_5 ) ;
}
static T_1 F_15 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_22 & V_36 )
return sprintf ( V_5 , L_4 ) ;
else
return sprintf ( V_5 , L_5 ) ;
}
static T_1 F_16 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_37 ) ;
}
static T_1 F_17 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_12 )
{
struct V_13 * V_14 = F_5 ( V_2 ) ;
struct V_6 * V_7 = F_6 ( V_14 ) ;
long V_15 ;
int V_16 = F_7 ( V_5 , 10 , & V_15 ) ;
if ( V_16 )
return V_16 ;
F_9 ( & V_7 -> V_17 ) ;
V_7 -> V_37 = F_8 ( V_15 , 0 , 255 ) ;
F_10 ( V_14 , V_38 , V_7 -> V_37 ) ;
F_12 ( & V_7 -> V_17 ) ;
return V_12 ;
}
static T_1 F_18 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_39 ) ;
}
static T_1 F_19 (
struct V_1 * V_2 ,
struct V_3 * V_11 ,
const char * V_5 ,
T_2 V_12 )
{
struct V_13 * V_14 = F_5 ( V_2 ) ;
struct V_6 * V_7 = F_6 ( V_14 ) ;
long V_15 ;
int V_40 = F_7 ( V_5 , 10 , & V_15 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_20 ( V_14 , V_41 ) ;
if ( V_40 < 0 ) {
F_11 ( & V_14 -> V_2 ,
L_6 ) ;
return - V_19 ;
}
switch ( V_15 ) {
case 1 :
V_40 &= ~ V_42 ;
V_40 &= ~ V_43 ;
break;
case 2 :
V_40 &= ~ V_42 ;
V_40 |= V_43 ;
break;
case 3 :
V_40 |= V_42 ;
V_40 |= V_43 ;
break;
default:
return - V_35 ;
}
F_9 ( & V_7 -> V_17 ) ;
if ( F_10 ( V_14 , V_41 , V_40 ) ) {
F_11 ( & V_14 -> V_2 ,
L_7 ) ;
V_12 = - V_19 ;
}
F_12 ( & V_7 -> V_17 ) ;
return V_12 ;
}
static T_1 F_21 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_44 ) ;
}
static T_1 F_22 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
int V_8 = F_23 ( V_4 ) -> V_9 ;
int V_45 = F_23 ( V_4 ) -> V_45 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
switch ( V_45 ) {
case 1 :
return sprintf ( V_5 , L_1 ,
V_7 -> V_46 [ V_8 ] * 1000 ) ;
break;
case 2 :
return sprintf ( V_5 , L_1 ,
V_7 -> V_47 [ V_8 ] * 1000 ) ;
break;
default:
F_14 ( V_2 , L_8 , V_45 ) ;
return - V_35 ;
}
}
static T_1 F_24 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
int V_8 = F_3 ( V_4 ) -> V_9 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_48 [ V_8 ] ) ;
}
static inline T_1 F_25 ( struct V_13 * V_14 ,
T_3 V_49 ,
T_3 V_50 ,
T_3 * V_51 )
{
int V_52 ;
T_3 V_53 ;
V_52 = V_51 [ 2 ] - V_51 [ 1 ] ;
for ( V_53 = 4 ; V_53 > 0 ; V_53 -- ) {
if ( V_52 * ( 0x20 >> V_53 ) >= V_50 )
break;
}
V_53 |= ( V_51 [ 1 ] & 0x7C ) << 1 ;
if ( F_10 ( V_14 ,
V_49 , V_53 ) ) {
F_11 ( & V_14 -> V_2 , L_2 ) ;
return - V_19 ;
}
return 0 ;
}
static T_1 F_26 (
struct V_1 * V_2 ,
struct V_3 * V_11 ,
const char * V_5 ,
T_2 V_12 )
{
struct V_13 * V_14 = F_5 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 = F_23 ( V_11 ) -> V_9 ;
int V_45 = F_23 ( V_11 ) -> V_45 ;
T_3 * V_51 ;
T_3 V_49 ;
int V_50 ;
long V_15 ;
int V_16 = F_7 ( V_5 , 10 , & V_15 ) ;
if ( V_16 )
return V_16 ;
switch ( V_45 ) {
case 1 :
V_51 = V_7 -> V_46 ;
V_49 = V_54 ;
break;
case 2 :
V_51 = V_7 -> V_47 ;
V_49 = V_55 ;
break;
default:
F_14 ( V_2 , L_8 , V_45 ) ;
return - V_35 ;
}
V_7 -> V_56 = 0 ;
F_9 ( & V_7 -> V_17 ) ;
switch ( V_8 ) {
case 0 :
V_51 [ 0 ] = F_8 ( V_15 / 1000 , 0 ,
V_7 -> V_46 [ 1 ] ) ;
V_51 [ 0 ] = F_8 ( V_51 [ 0 ] , 0 ,
V_7 -> V_47 [ 1 ] ) ;
V_51 [ 0 ] = F_8 ( V_51 [ 0 ] , 0 , 63 ) ;
if ( F_10 (
V_14 ,
V_57 ,
V_51 [ 0 ] ) ) {
F_11 ( & V_14 -> V_2 ,
L_2 ) ;
V_12 = - V_19 ;
}
goto EXIT;
break;
case 1 :
V_51 [ 1 ] = F_8 ( V_15 / 1000 , ( V_51 [ 0 ] & 0x7C ) + 4 , 124 ) ;
V_51 [ 1 ] &= 0x7C ;
V_51 [ 2 ] = F_8 ( V_51 [ 2 ] , V_51 [ 1 ] + 1 , 255 ) ;
break;
case 2 :
V_51 [ 2 ] = F_8 ( V_15 / 1000 , V_51 [ 1 ] + 1 , 255 ) ;
break;
default:
F_14 ( V_2 , L_3 , V_8 ) ;
V_12 = - V_35 ;
goto EXIT;
}
V_50 = V_7 -> V_48 [ 2 ] - V_7 -> V_48 [ 1 ] ;
if ( F_25 ( V_14 , V_49 , V_50 , V_51 ) )
V_12 = - V_19 ;
EXIT:
F_12 ( & V_7 -> V_17 ) ;
return V_12 ;
}
static T_1 F_27 (
struct V_1 * V_2 ,
struct V_3 * V_11 ,
const char * V_5 ,
T_2 V_12 )
{
struct V_13 * V_14 = F_5 ( V_2 ) ;
struct V_6 * V_7 = F_6 ( V_14 ) ;
int V_50 ;
long V_15 ;
int V_16 = F_7 ( V_5 , 10 , & V_15 ) ;
if ( V_16 )
return V_16 ;
F_9 ( & V_7 -> V_17 ) ;
V_7 -> V_48 [ 1 ] = F_8 ( V_15 , 0 , 254 ) ;
if ( F_10 ( V_14 , V_58 ,
V_7 -> V_48 [ 1 ] ) ) {
F_11 ( & V_14 -> V_2 , L_2 ) ;
V_12 = - V_19 ;
goto EXIT;
}
V_50 = V_7 -> V_48 [ 2 ] - V_7 -> V_48 [ 1 ] ;
if ( F_25 ( V_14 , V_54 , V_50 ,
V_7 -> V_46 ) ) {
V_12 = - V_19 ;
goto EXIT;
}
if ( F_25 ( V_14 , V_55 , V_50 ,
V_7 -> V_47 ) ) {
V_12 = - V_19 ;
goto EXIT;
}
EXIT:
V_7 -> V_56 = 0 ;
F_12 ( & V_7 -> V_17 ) ;
return V_12 ;
}
static T_1 F_28 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 = F_3 ( V_4 ) -> V_9 ;
if ( 0 == V_7 -> V_59 [ V_8 ] )
return sprintf ( V_5 , L_5 ) ;
return sprintf ( V_5 , L_1 , ( int ) ( 6000000 / V_7 -> V_59 [ V_8 ] ) ) ;
}
static T_1 F_29 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_22 & V_60 )
return sprintf ( V_5 , L_4 ) ;
else
return sprintf ( V_5 , L_5 ) ;
}
static T_1 F_30 (
struct V_1 * V_2 ,
struct V_3 * V_11 ,
const char * V_5 , T_2 V_12 )
{
struct V_13 * V_14 = F_5 ( V_2 ) ;
struct V_6 * V_7 = F_6 ( V_14 ) ;
long V_15 ;
int V_8 = F_3 ( V_11 ) -> V_9 ;
int V_16 = F_7 ( V_5 , 10 , & V_15 ) ;
if ( V_16 )
return V_16 ;
V_15 = 1 > V_15 ? 0xFFFF : 6000000 / V_15 ;
F_9 ( & V_7 -> V_17 ) ;
V_7 -> V_59 [ V_8 ] = ( V_61 ) F_8 ( V_15 , 1 , 0xFFFF ) ;
if ( F_10 ( V_14 , V_62 [ V_8 ] ,
V_7 -> V_59 [ V_8 ] & 0xFF ) ) {
F_11 ( & V_14 -> V_2 , L_2 ) ;
V_12 = - V_19 ;
goto EXIT;
}
if ( F_10 ( V_14 ,
V_63 [ V_8 ] , V_7 -> V_59 [ V_8 ] >> 8 ) ) {
F_11 ( & V_14 -> V_2 , L_2 ) ;
V_12 = - V_19 ;
}
EXIT:
F_12 ( & V_7 -> V_17 ) ;
return V_12 ;
}
static T_1 F_31 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_64 ) ;
}
static T_1 F_32 (
struct V_1 * V_2 ,
struct V_3 * V_11 ,
const char * V_5 , T_2 V_12 )
{
struct V_13 * V_14 = F_5 ( V_2 ) ;
struct V_6 * V_7 = F_6 ( V_14 ) ;
long V_15 ;
int V_40 = F_7 ( V_5 , 10 , & V_15 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_20 ( V_14 , V_65 ) ;
if ( V_40 < 0 ) {
F_11 ( & V_14 -> V_2 ,
L_6 ) ;
return - V_19 ;
}
F_9 ( & V_7 -> V_17 ) ;
switch ( V_15 ) {
case 2 :
V_40 &= ~ V_66 ;
V_7 -> V_64 = 2 ;
break;
case 4 :
V_40 |= V_66 ;
V_7 -> V_64 = 4 ;
break;
default:
V_12 = - V_35 ;
goto EXIT;
}
if ( F_10 ( V_14 , V_65 , V_40 ) ) {
F_11 ( & V_14 -> V_2 ,
L_7 ) ;
V_12 = - V_19 ;
}
EXIT:
F_12 ( & V_7 -> V_17 ) ;
return V_12 ;
}
static int F_33 (
struct V_13 * V_14 ,
struct V_67 * V_68 )
{
struct V_69 * V_70 = V_14 -> V_70 ;
int V_71 = V_14 -> V_72 ;
int V_73 , V_74 ;
F_14 ( & V_70 -> V_2 , L_9 ) ;
if ( ! F_34 ( V_70 , V_75 ) ) {
F_14 ( & V_70 -> V_2 ,
L_10
L_11 ) ;
return - V_76 ;
}
V_73 = F_20 ( V_14 , V_77 ) ;
V_74 = F_20 ( V_14 , V_78 ) ;
if ( V_73 != 0x21 || V_74 != 0x49 ) {
F_14 ( & V_70 -> V_2 ,
L_12 ,
V_71 ) ;
return - V_76 ;
}
V_73 = F_20 ( V_14 , 0x80 | V_77 ) ;
V_74 = F_20 ( V_14 , 0x80 | V_78 ) ;
if ( V_73 != 0x21 || V_74 != 0x49 ) {
F_14 ( & V_70 -> V_2 ,
L_12 ,
V_71 ) ;
return - V_76 ;
}
F_35 ( & V_70 -> V_2 , L_13 , V_71 ) ;
F_36 ( V_68 -> type , L_14 , V_79 ) ;
return 0 ;
}
static int F_37 (
struct V_13 * V_14 ,
const struct V_80 * V_81 )
{
struct V_6 * V_7 ;
int V_82 ;
V_7 = F_38 ( & V_14 -> V_2 , sizeof( struct V_6 ) ,
V_83 ) ;
if ( ! V_7 )
return - V_84 ;
F_39 ( V_14 , V_7 ) ;
F_40 ( & V_7 -> V_17 ) ;
V_82 = F_41 ( V_14 ) ;
if ( V_82 )
return V_82 ;
V_82 = F_42 ( & V_14 -> V_2 . V_85 , & V_86 ) ;
if ( V_82 )
return V_82 ;
V_7 -> V_87 = F_43 ( & V_14 -> V_2 ) ;
if ( ! F_44 ( V_7 -> V_87 ) )
return 0 ;
V_82 = F_45 ( V_7 -> V_87 ) ;
F_11 ( & V_14 -> V_2 , L_15 ) ;
F_46 ( & V_14 -> V_2 . V_85 , & V_86 ) ;
return V_82 ;
}
static int F_47 ( struct V_13 * V_14 )
{
struct V_6 * V_7 = F_6 ( V_14 ) ;
F_48 ( V_7 -> V_87 ) ;
F_46 ( & V_14 -> V_2 . V_85 , & V_86 ) ;
return 0 ;
}
static int F_41 ( struct V_13 * V_14 )
{
int V_40 ;
int V_82 = - V_19 ;
if ( V_88 ) {
V_40 = F_20 ( V_14 , V_65 ) ;
if ( V_40 < 0 ) {
F_11 ( & V_14 -> V_2 ,
L_6 ) ;
return V_82 ;
}
V_40 |= V_89 ;
if ( F_10 ( V_14 , V_65 ,
V_40 ) ) {
F_11 ( & V_14 -> V_2 ,
L_7 ) ;
return V_82 ;
}
V_40 = F_20 ( V_14 , V_90 ) ;
if ( V_40 < 0 ) {
F_11 ( & V_14 -> V_2 ,
L_6 ) ;
return V_82 ;
}
F_35 ( & V_14 -> V_2 , L_16 , V_40 & 0x0f ) ;
V_40 &= ~ V_91 ;
if ( F_10 ( V_14 , V_90 ,
V_40 ) ) {
F_11 ( & V_14 -> V_2 ,
L_7 ) ;
return V_82 ;
}
V_40 = F_20 ( V_14 , V_92 ) ;
if ( V_40 < 0 ) {
F_11 ( & V_14 -> V_2 ,
L_6 ) ;
return V_82 ;
}
V_40 &= ~ V_93 ;
V_40 &= ~ V_94 ;
V_40 &= ~ V_95 ;
if ( F_10 ( V_14 ,
V_92 , V_40 ) ) {
F_11 ( & V_14 -> V_2 ,
L_7 ) ;
return V_82 ;
}
V_40 = F_20 ( V_14 , V_41 ) ;
if ( V_40 < 0 ) {
F_11 ( & V_14 -> V_2 ,
L_6 ) ;
return V_82 ;
}
V_40 &= ~ V_96 ;
V_40 &= ~ V_97 ;
V_40 |= V_98 ;
if ( V_99 )
V_40 |= V_100 ;
else
V_40 &= ~ V_100 ;
if ( F_10 (
V_14 , V_41 , V_40 ) ) {
F_11 ( & V_14 -> V_2 ,
L_7 ) ;
return V_82 ;
}
}
return 0 ;
}
static struct V_6 * F_2 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_5 ( V_2 ) ;
struct V_6 * V_7 = F_6 ( V_14 ) ;
int V_101 = V_102 ;
T_3 V_49 ;
int V_103 ;
F_9 ( & V_7 -> V_17 ) ;
if ( F_49 ( V_104 , V_7 -> V_105 + V_101 ) ||
! V_7 -> V_56 ) {
for ( V_103 = 0 ; V_103 < V_106 ; V_103 ++ )
V_7 -> V_10 [ V_103 ] = F_20 ( V_14 ,
V_18 [ V_103 ] ) ;
V_7 -> V_22 = F_20 ( V_14 ,
V_107 ) ;
V_7 -> V_27 = F_20 ( V_14 ,
V_108 ) ;
V_7 -> V_37 = F_20 ( V_14 ,
V_38 ) ;
for ( V_103 = 0 ; V_103 < V_109 ; V_103 ++ ) {
V_7 -> V_59 [ V_103 ] = F_20 (
V_14 ,
V_62 [ V_103 ] ) ;
V_7 -> V_59 [ V_103 ] += F_20 (
V_14 ,
V_63 [ V_103 ] ) << 8 ;
}
V_7 -> V_64 = F_20 ( V_14 ,
V_65 ) ;
V_7 -> V_64 = V_7 -> V_64 & V_66 ? 4 : 2 ;
V_7 -> V_48 [ 0 ] = 0 ;
V_7 -> V_48 [ 2 ] = 255 ;
V_7 -> V_48 [ 1 ] = F_20 ( V_14 ,
V_58 ) ;
V_7 -> V_46 [ 0 ] =
F_20 ( V_14 ,
V_57 ) ;
V_7 -> V_47 [ 0 ] =
V_7 -> V_46 [ 0 ] ;
V_49 = F_20 ( V_14 ,
V_54 ) ;
V_7 -> V_46 [ 1 ] = ( V_49 & 0xF8 ) >> 1 ;
V_49 &= 0x07 ;
V_49 = 0x20 >> V_49 ;
if ( V_49 > 0 )
V_7 -> V_46 [ 2 ] =
V_7 -> V_46 [ 1 ] +
( V_7 -> V_48 [ 2 ] -
V_7 -> V_48 [ 1 ] ) / V_49 ;
else
V_7 -> V_46 [ 2 ] = 255 ;
V_49 = F_20 ( V_14 ,
V_55 ) ;
V_7 -> V_47 [ 1 ] = ( V_49 & 0xF8 ) >> 1 ;
V_49 &= 0x07 ;
V_49 = 0x20 >> V_49 ;
if ( V_49 > 0 )
V_7 -> V_47 [ 2 ] =
V_7 -> V_47 [ 1 ] +
( V_7 -> V_48 [ 2 ] -
V_7 -> V_48 [ 1 ] ) / V_49 ;
else
V_7 -> V_47 [ 2 ] = 255 ;
V_49 = F_20 ( V_14 , V_41 ) ;
V_49 = ( V_49 >> 5 ) & 0x3 ;
switch ( V_49 ) {
case 0 :
V_7 -> V_44 = 0 ;
V_7 -> V_39 = 1 ;
break;
case 2 :
V_7 -> V_44 = 2 ;
V_7 -> V_39 = 2 ;
break;
case 3 :
V_7 -> V_44 = 3 ;
V_7 -> V_39 = 3 ;
break;
case 1 :
V_7 -> V_44 = 0 ;
V_7 -> V_39 = 0 ;
break;
}
V_7 -> V_105 = V_104 ;
V_7 -> V_56 = 1 ;
}
F_12 ( & V_7 -> V_17 ) ;
return V_7 ;
}
