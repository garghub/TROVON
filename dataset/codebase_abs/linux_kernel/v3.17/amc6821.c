static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = V_8 ;
T_1 V_9 ;
int V_10 ;
F_3 ( & V_4 -> V_11 ) ;
if ( F_4 ( V_12 , V_4 -> V_13 + V_7 ) ||
! V_4 -> V_14 ) {
for ( V_10 = 0 ; V_10 < V_15 ; V_10 ++ )
V_4 -> V_16 [ V_10 ] = F_5 ( V_6 ,
V_17 [ V_10 ] ) ;
V_4 -> V_18 = F_5 ( V_6 ,
V_19 ) ;
V_4 -> V_20 = F_5 ( V_6 ,
V_21 ) ;
V_4 -> V_22 = F_5 ( V_6 ,
V_23 ) ;
for ( V_10 = 0 ; V_10 < V_24 ; V_10 ++ ) {
V_4 -> V_25 [ V_10 ] = F_5 (
V_6 ,
V_26 [ V_10 ] ) ;
V_4 -> V_25 [ V_10 ] += F_5 (
V_6 ,
V_27 [ V_10 ] ) << 8 ;
}
V_4 -> V_28 = F_5 ( V_6 ,
V_29 ) ;
V_4 -> V_28 = V_4 -> V_28 & V_30 ? 4 : 2 ;
V_4 -> V_31 [ 0 ] = 0 ;
V_4 -> V_31 [ 2 ] = 255 ;
V_4 -> V_31 [ 1 ] = F_5 ( V_6 ,
V_32 ) ;
V_4 -> V_33 [ 0 ] =
F_5 ( V_6 ,
V_34 ) ;
V_4 -> V_35 [ 0 ] =
V_4 -> V_33 [ 0 ] ;
V_9 = F_5 ( V_6 ,
V_36 ) ;
V_4 -> V_33 [ 1 ] = ( V_9 & 0xF8 ) >> 1 ;
V_9 &= 0x07 ;
V_9 = 0x20 >> V_9 ;
if ( V_9 > 0 )
V_4 -> V_33 [ 2 ] =
V_4 -> V_33 [ 1 ] +
( V_4 -> V_31 [ 2 ] -
V_4 -> V_31 [ 1 ] ) / V_9 ;
else
V_4 -> V_33 [ 2 ] = 255 ;
V_9 = F_5 ( V_6 ,
V_37 ) ;
V_4 -> V_35 [ 1 ] = ( V_9 & 0xF8 ) >> 1 ;
V_9 &= 0x07 ;
V_9 = 0x20 >> V_9 ;
if ( V_9 > 0 )
V_4 -> V_35 [ 2 ] =
V_4 -> V_35 [ 1 ] +
( V_4 -> V_31 [ 2 ] -
V_4 -> V_31 [ 1 ] ) / V_9 ;
else
V_4 -> V_35 [ 2 ] = 255 ;
V_9 = F_5 ( V_6 , V_38 ) ;
V_9 = ( V_9 >> 5 ) & 0x3 ;
switch ( V_9 ) {
case 0 :
V_4 -> V_39 = 0 ;
V_4 -> V_40 = 1 ;
break;
case 2 :
V_4 -> V_39 = 2 ;
V_4 -> V_40 = 2 ;
break;
case 3 :
V_4 -> V_39 = 3 ;
V_4 -> V_40 = 3 ;
break;
case 1 :
V_4 -> V_39 = 0 ;
V_4 -> V_40 = 0 ;
break;
}
V_4 -> V_13 = V_12 ;
V_4 -> V_14 = 1 ;
}
F_6 ( & V_4 -> V_11 ) ;
return V_4 ;
}
static T_2 F_7 (
struct V_2 * V_3 ,
struct V_41 * V_42 ,
char * V_43 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_44 = F_8 ( V_42 ) -> V_45 ;
return sprintf ( V_43 , L_1 , V_4 -> V_16 [ V_44 ] * 1000 ) ;
}
static T_2 F_9 (
struct V_2 * V_3 ,
struct V_41 * V_46 ,
const char * V_43 ,
T_3 V_47 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_44 = F_8 ( V_46 ) -> V_45 ;
long V_48 ;
int V_49 = F_10 ( V_43 , 10 , & V_48 ) ;
if ( V_49 )
return V_49 ;
V_48 = F_11 ( V_48 / 1000 , - 128 , 127 ) ;
F_3 ( & V_4 -> V_11 ) ;
V_4 -> V_16 [ V_44 ] = V_48 ;
if ( F_12 ( V_6 , V_17 [ V_44 ] , V_4 -> V_16 [ V_44 ] ) ) {
F_13 ( & V_6 -> V_3 , L_2 ) ;
V_47 = - V_50 ;
}
F_6 ( & V_4 -> V_11 ) ;
return V_47 ;
}
static T_2 F_14 (
struct V_2 * V_3 ,
struct V_41 * V_42 ,
char * V_43 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_44 = F_8 ( V_42 ) -> V_45 ;
T_1 V_51 ;
switch ( V_44 ) {
case V_52 :
V_51 = V_4 -> V_18 & V_53 ;
break;
case V_54 :
V_51 = V_4 -> V_18 & V_55 ;
break;
case V_56 :
V_51 = V_4 -> V_20 & V_57 ;
break;
case V_58 :
V_51 = V_4 -> V_18 & V_59 ;
break;
case V_60 :
V_51 = V_4 -> V_18 & V_61 ;
break;
case V_62 :
V_51 = V_4 -> V_20 & V_63 ;
break;
default:
F_15 ( V_3 , L_3 , V_44 ) ;
return - V_64 ;
}
if ( V_51 )
return sprintf ( V_43 , L_4 ) ;
else
return sprintf ( V_43 , L_5 ) ;
}
static T_2 F_16 (
struct V_2 * V_3 ,
struct V_41 * V_42 ,
char * V_43 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_18 & V_65 )
return sprintf ( V_43 , L_4 ) ;
else
return sprintf ( V_43 , L_5 ) ;
}
static T_2 F_17 (
struct V_2 * V_3 ,
struct V_41 * V_42 ,
char * V_43 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_43 , L_1 , V_4 -> V_22 ) ;
}
static T_2 F_18 (
struct V_2 * V_3 ,
struct V_41 * V_42 ,
const char * V_43 ,
T_3 V_47 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
long V_48 ;
int V_49 = F_10 ( V_43 , 10 , & V_48 ) ;
if ( V_49 )
return V_49 ;
F_3 ( & V_4 -> V_11 ) ;
V_4 -> V_22 = F_11 ( V_48 , 0 , 255 ) ;
F_12 ( V_6 , V_23 , V_4 -> V_22 ) ;
F_6 ( & V_4 -> V_11 ) ;
return V_47 ;
}
static T_2 F_19 (
struct V_2 * V_3 ,
struct V_41 * V_42 ,
char * V_43 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_43 , L_1 , V_4 -> V_40 ) ;
}
static T_2 F_20 (
struct V_2 * V_3 ,
struct V_41 * V_46 ,
const char * V_43 ,
T_3 V_47 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
long V_48 ;
int V_66 = F_10 ( V_43 , 10 , & V_48 ) ;
if ( V_66 )
return V_66 ;
F_3 ( & V_4 -> V_11 ) ;
V_66 = F_5 ( V_6 , V_38 ) ;
if ( V_66 < 0 ) {
F_13 ( & V_6 -> V_3 ,
L_6 ) ;
V_47 = V_66 ;
goto V_67;
}
switch ( V_48 ) {
case 1 :
V_66 &= ~ V_68 ;
V_66 &= ~ V_69 ;
break;
case 2 :
V_66 &= ~ V_68 ;
V_66 |= V_69 ;
break;
case 3 :
V_66 |= V_68 ;
V_66 |= V_69 ;
break;
default:
V_47 = - V_64 ;
goto V_67;
}
if ( F_12 ( V_6 , V_38 , V_66 ) ) {
F_13 ( & V_6 -> V_3 ,
L_7 ) ;
V_47 = - V_50 ;
}
V_67:
F_6 ( & V_4 -> V_11 ) ;
return V_47 ;
}
static T_2 F_21 (
struct V_2 * V_3 ,
struct V_41 * V_42 ,
char * V_43 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_43 , L_1 , V_4 -> V_39 ) ;
}
static T_2 F_22 (
struct V_2 * V_3 ,
struct V_41 * V_42 ,
char * V_43 )
{
int V_44 = F_23 ( V_42 ) -> V_45 ;
int V_70 = F_23 ( V_42 ) -> V_70 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
switch ( V_70 ) {
case 1 :
return sprintf ( V_43 , L_1 ,
V_4 -> V_33 [ V_44 ] * 1000 ) ;
case 2 :
return sprintf ( V_43 , L_1 ,
V_4 -> V_35 [ V_44 ] * 1000 ) ;
default:
F_15 ( V_3 , L_8 , V_70 ) ;
return - V_64 ;
}
}
static T_2 F_24 (
struct V_2 * V_3 ,
struct V_41 * V_42 ,
char * V_43 )
{
int V_44 = F_8 ( V_42 ) -> V_45 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_43 , L_1 , V_4 -> V_31 [ V_44 ] ) ;
}
static inline T_2 F_25 ( struct V_5 * V_6 ,
T_1 V_9 ,
T_1 V_71 ,
T_1 * V_72 )
{
int V_73 ;
T_1 V_74 ;
V_73 = V_72 [ 2 ] - V_72 [ 1 ] ;
for ( V_74 = 4 ; V_74 > 0 ; V_74 -- ) {
if ( V_73 * ( 0x20 >> V_74 ) >= V_71 )
break;
}
V_74 |= ( V_72 [ 1 ] & 0x7C ) << 1 ;
if ( F_12 ( V_6 ,
V_9 , V_74 ) ) {
F_13 ( & V_6 -> V_3 , L_2 ) ;
return - V_50 ;
}
return 0 ;
}
static T_2 F_26 (
struct V_2 * V_3 ,
struct V_41 * V_46 ,
const char * V_43 ,
T_3 V_47 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_44 = F_23 ( V_46 ) -> V_45 ;
int V_70 = F_23 ( V_46 ) -> V_70 ;
T_1 * V_72 ;
T_1 V_9 ;
int V_71 ;
long V_48 ;
int V_49 = F_10 ( V_43 , 10 , & V_48 ) ;
if ( V_49 )
return V_49 ;
switch ( V_70 ) {
case 1 :
V_72 = V_4 -> V_33 ;
V_9 = V_36 ;
break;
case 2 :
V_72 = V_4 -> V_35 ;
V_9 = V_37 ;
break;
default:
F_15 ( V_3 , L_8 , V_70 ) ;
return - V_64 ;
}
F_3 ( & V_4 -> V_11 ) ;
V_4 -> V_14 = 0 ;
switch ( V_44 ) {
case 0 :
V_72 [ 0 ] = F_11 ( V_48 / 1000 , 0 ,
V_4 -> V_33 [ 1 ] ) ;
V_72 [ 0 ] = F_11 ( V_72 [ 0 ] , 0 ,
V_4 -> V_35 [ 1 ] ) ;
V_72 [ 0 ] = F_11 ( V_72 [ 0 ] , 0 , 63 ) ;
if ( F_12 (
V_6 ,
V_34 ,
V_72 [ 0 ] ) ) {
F_13 ( & V_6 -> V_3 ,
L_2 ) ;
V_47 = - V_50 ;
}
goto EXIT;
case 1 :
V_72 [ 1 ] = F_11 ( V_48 / 1000 , ( V_72 [ 0 ] & 0x7C ) + 4 , 124 ) ;
V_72 [ 1 ] &= 0x7C ;
V_72 [ 2 ] = F_11 ( V_72 [ 2 ] , V_72 [ 1 ] + 1 , 255 ) ;
break;
case 2 :
V_72 [ 2 ] = F_11 ( V_48 / 1000 , V_72 [ 1 ] + 1 , 255 ) ;
break;
default:
F_15 ( V_3 , L_3 , V_44 ) ;
V_47 = - V_64 ;
goto EXIT;
}
V_71 = V_4 -> V_31 [ 2 ] - V_4 -> V_31 [ 1 ] ;
if ( F_25 ( V_6 , V_9 , V_71 , V_72 ) )
V_47 = - V_50 ;
EXIT:
F_6 ( & V_4 -> V_11 ) ;
return V_47 ;
}
static T_2 F_27 (
struct V_2 * V_3 ,
struct V_41 * V_46 ,
const char * V_43 ,
T_3 V_47 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_71 ;
long V_48 ;
int V_49 = F_10 ( V_43 , 10 , & V_48 ) ;
if ( V_49 )
return V_49 ;
F_3 ( & V_4 -> V_11 ) ;
V_4 -> V_31 [ 1 ] = F_11 ( V_48 , 0 , 254 ) ;
if ( F_12 ( V_6 , V_32 ,
V_4 -> V_31 [ 1 ] ) ) {
F_13 ( & V_6 -> V_3 , L_2 ) ;
V_47 = - V_50 ;
goto EXIT;
}
V_71 = V_4 -> V_31 [ 2 ] - V_4 -> V_31 [ 1 ] ;
if ( F_25 ( V_6 , V_36 , V_71 ,
V_4 -> V_33 ) ) {
V_47 = - V_50 ;
goto EXIT;
}
if ( F_25 ( V_6 , V_37 , V_71 ,
V_4 -> V_35 ) ) {
V_47 = - V_50 ;
goto EXIT;
}
EXIT:
V_4 -> V_14 = 0 ;
F_6 ( & V_4 -> V_11 ) ;
return V_47 ;
}
static T_2 F_28 (
struct V_2 * V_3 ,
struct V_41 * V_42 ,
char * V_43 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_44 = F_8 ( V_42 ) -> V_45 ;
if ( 0 == V_4 -> V_25 [ V_44 ] )
return sprintf ( V_43 , L_5 ) ;
return sprintf ( V_43 , L_1 , ( int ) ( 6000000 / V_4 -> V_25 [ V_44 ] ) ) ;
}
static T_2 F_29 (
struct V_2 * V_3 ,
struct V_41 * V_42 ,
char * V_43 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_18 & V_75 )
return sprintf ( V_43 , L_4 ) ;
else
return sprintf ( V_43 , L_5 ) ;
}
static T_2 F_30 (
struct V_2 * V_3 ,
struct V_41 * V_46 ,
const char * V_43 , T_3 V_47 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
long V_48 ;
int V_44 = F_8 ( V_46 ) -> V_45 ;
int V_49 = F_10 ( V_43 , 10 , & V_48 ) ;
if ( V_49 )
return V_49 ;
V_48 = 1 > V_48 ? 0xFFFF : 6000000 / V_48 ;
F_3 ( & V_4 -> V_11 ) ;
V_4 -> V_25 [ V_44 ] = ( V_76 ) F_11 ( V_48 , 1 , 0xFFFF ) ;
if ( F_12 ( V_6 , V_26 [ V_44 ] ,
V_4 -> V_25 [ V_44 ] & 0xFF ) ) {
F_13 ( & V_6 -> V_3 , L_2 ) ;
V_47 = - V_50 ;
goto EXIT;
}
if ( F_12 ( V_6 ,
V_27 [ V_44 ] , V_4 -> V_25 [ V_44 ] >> 8 ) ) {
F_13 ( & V_6 -> V_3 , L_2 ) ;
V_47 = - V_50 ;
}
EXIT:
F_6 ( & V_4 -> V_11 ) ;
return V_47 ;
}
static T_2 F_31 (
struct V_2 * V_3 ,
struct V_41 * V_42 ,
char * V_43 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_43 , L_1 , V_4 -> V_28 ) ;
}
static T_2 F_32 (
struct V_2 * V_3 ,
struct V_41 * V_46 ,
const char * V_43 , T_3 V_47 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
long V_48 ;
int V_66 = F_10 ( V_43 , 10 , & V_48 ) ;
if ( V_66 )
return V_66 ;
F_3 ( & V_4 -> V_11 ) ;
V_66 = F_5 ( V_6 , V_29 ) ;
if ( V_66 < 0 ) {
F_13 ( & V_6 -> V_3 ,
L_6 ) ;
V_47 = V_66 ;
goto EXIT;
}
switch ( V_48 ) {
case 2 :
V_66 &= ~ V_30 ;
V_4 -> V_28 = 2 ;
break;
case 4 :
V_66 |= V_30 ;
V_4 -> V_28 = 4 ;
break;
default:
V_47 = - V_64 ;
goto EXIT;
}
if ( F_12 ( V_6 , V_29 , V_66 ) ) {
F_13 ( & V_6 -> V_3 ,
L_7 ) ;
V_47 = - V_50 ;
}
EXIT:
F_6 ( & V_4 -> V_11 ) ;
return V_47 ;
}
static int F_33 (
struct V_5 * V_6 ,
struct V_77 * V_78 )
{
struct V_79 * V_80 = V_6 -> V_80 ;
int V_81 = V_6 -> V_82 ;
int V_83 , V_84 ;
F_15 ( & V_80 -> V_3 , L_9 ) ;
if ( ! F_34 ( V_80 , V_85 ) ) {
F_15 ( & V_80 -> V_3 ,
L_10
L_11 ) ;
return - V_86 ;
}
V_83 = F_5 ( V_6 , V_87 ) ;
V_84 = F_5 ( V_6 , V_88 ) ;
if ( V_83 != 0x21 || V_84 != 0x49 ) {
F_15 ( & V_80 -> V_3 ,
L_12 ,
V_81 ) ;
return - V_86 ;
}
V_83 = F_5 ( V_6 , 0x80 | V_87 ) ;
V_84 = F_5 ( V_6 , 0x80 | V_88 ) ;
if ( V_83 != 0x21 || V_84 != 0x49 ) {
F_15 ( & V_80 -> V_3 ,
L_12 ,
V_81 ) ;
return - V_86 ;
}
F_35 ( & V_80 -> V_3 , L_13 , V_81 ) ;
F_36 ( V_78 -> type , L_14 , V_89 ) ;
return 0 ;
}
static int F_37 ( struct V_5 * V_6 )
{
int V_66 ;
int V_90 = - V_50 ;
if ( V_91 ) {
V_66 = F_5 ( V_6 , V_29 ) ;
if ( V_66 < 0 ) {
F_13 ( & V_6 -> V_3 ,
L_6 ) ;
return V_90 ;
}
V_66 |= V_92 ;
if ( F_12 ( V_6 , V_29 ,
V_66 ) ) {
F_13 ( & V_6 -> V_3 ,
L_7 ) ;
return V_90 ;
}
V_66 = F_5 ( V_6 , V_93 ) ;
if ( V_66 < 0 ) {
F_13 ( & V_6 -> V_3 ,
L_6 ) ;
return V_90 ;
}
F_35 ( & V_6 -> V_3 , L_15 , V_66 & 0x0f ) ;
V_66 &= ~ V_94 ;
if ( F_12 ( V_6 , V_93 ,
V_66 ) ) {
F_13 ( & V_6 -> V_3 ,
L_7 ) ;
return V_90 ;
}
V_66 = F_5 ( V_6 , V_95 ) ;
if ( V_66 < 0 ) {
F_13 ( & V_6 -> V_3 ,
L_6 ) ;
return V_90 ;
}
V_66 &= ~ V_96 ;
V_66 &= ~ V_97 ;
V_66 &= ~ V_98 ;
if ( F_12 ( V_6 ,
V_95 , V_66 ) ) {
F_13 ( & V_6 -> V_3 ,
L_7 ) ;
return V_90 ;
}
V_66 = F_5 ( V_6 , V_38 ) ;
if ( V_66 < 0 ) {
F_13 ( & V_6 -> V_3 ,
L_6 ) ;
return V_90 ;
}
V_66 &= ~ V_99 ;
V_66 &= ~ V_100 ;
V_66 |= V_101 ;
if ( V_102 )
V_66 |= V_103 ;
else
V_66 &= ~ V_103 ;
if ( F_12 (
V_6 , V_38 , V_66 ) ) {
F_13 ( & V_6 -> V_3 ,
L_7 ) ;
return V_90 ;
}
}
return 0 ;
}
static int F_38 ( struct V_5 * V_6 ,
const struct V_104 * V_105 )
{
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_1 * V_4 ;
struct V_2 * V_106 ;
int V_90 ;
V_4 = F_39 ( V_3 , sizeof( struct V_1 ) , V_107 ) ;
if ( ! V_4 )
return - V_108 ;
V_4 -> V_6 = V_6 ;
F_40 ( & V_4 -> V_11 ) ;
V_90 = F_37 ( V_6 ) ;
if ( V_90 )
return V_90 ;
V_106 = F_41 ( V_3 , V_6 -> V_109 ,
V_4 ,
V_110 ) ;
return F_42 ( V_106 ) ;
}
