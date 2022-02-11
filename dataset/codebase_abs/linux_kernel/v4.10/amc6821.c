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
V_4 -> V_16 [ V_10 ] = ( V_17 ) F_5 (
V_6 , V_18 [ V_10 ] ) ;
V_4 -> V_19 = F_5 ( V_6 ,
V_20 ) ;
V_4 -> V_21 = F_5 ( V_6 ,
V_22 ) ;
V_4 -> V_23 = F_5 ( V_6 ,
V_24 ) ;
for ( V_10 = 0 ; V_10 < V_25 ; V_10 ++ ) {
V_4 -> V_26 [ V_10 ] = F_5 (
V_6 ,
V_27 [ V_10 ] ) ;
V_4 -> V_26 [ V_10 ] += F_5 (
V_6 ,
V_28 [ V_10 ] ) << 8 ;
}
V_4 -> V_29 = F_5 ( V_6 ,
V_30 ) ;
V_4 -> V_29 = V_4 -> V_29 & V_31 ? 4 : 2 ;
V_4 -> V_32 [ 0 ] = 0 ;
V_4 -> V_32 [ 2 ] = 255 ;
V_4 -> V_32 [ 1 ] = F_5 ( V_6 ,
V_33 ) ;
V_4 -> V_34 [ 0 ] =
F_5 ( V_6 ,
V_35 ) ;
V_4 -> V_36 [ 0 ] =
V_4 -> V_34 [ 0 ] ;
V_9 = F_5 ( V_6 ,
V_37 ) ;
V_4 -> V_34 [ 1 ] = ( V_9 & 0xF8 ) >> 1 ;
V_9 &= 0x07 ;
V_9 = 0x20 >> V_9 ;
if ( V_9 > 0 )
V_4 -> V_34 [ 2 ] =
V_4 -> V_34 [ 1 ] +
( V_4 -> V_32 [ 2 ] -
V_4 -> V_32 [ 1 ] ) / V_9 ;
else
V_4 -> V_34 [ 2 ] = 255 ;
V_9 = F_5 ( V_6 ,
V_38 ) ;
V_4 -> V_36 [ 1 ] = ( V_9 & 0xF8 ) >> 1 ;
V_9 &= 0x07 ;
V_9 = 0x20 >> V_9 ;
if ( V_9 > 0 )
V_4 -> V_36 [ 2 ] =
V_4 -> V_36 [ 1 ] +
( V_4 -> V_32 [ 2 ] -
V_4 -> V_32 [ 1 ] ) / V_9 ;
else
V_4 -> V_36 [ 2 ] = 255 ;
V_9 = F_5 ( V_6 , V_39 ) ;
V_9 = ( V_9 >> 5 ) & 0x3 ;
switch ( V_9 ) {
case 0 :
V_4 -> V_40 = 0 ;
V_4 -> V_41 = 1 ;
break;
case 2 :
V_4 -> V_40 = 2 ;
V_4 -> V_41 = 2 ;
break;
case 3 :
V_4 -> V_40 = 3 ;
V_4 -> V_41 = 3 ;
break;
case 1 :
V_4 -> V_40 = 0 ;
V_4 -> V_41 = 0 ;
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
struct V_42 * V_43 ,
char * V_44 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_45 = F_8 ( V_43 ) -> V_46 ;
return sprintf ( V_44 , L_1 , V_4 -> V_16 [ V_45 ] * 1000 ) ;
}
static T_2 F_9 (
struct V_2 * V_3 ,
struct V_42 * V_47 ,
const char * V_44 ,
T_3 V_48 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_45 = F_8 ( V_47 ) -> V_46 ;
long V_49 ;
int V_50 = F_10 ( V_44 , 10 , & V_49 ) ;
if ( V_50 )
return V_50 ;
V_49 = F_11 ( V_49 / 1000 , - 128 , 127 ) ;
F_3 ( & V_4 -> V_11 ) ;
V_4 -> V_16 [ V_45 ] = V_49 ;
if ( F_12 ( V_6 , V_18 [ V_45 ] , V_4 -> V_16 [ V_45 ] ) ) {
F_13 ( & V_6 -> V_3 , L_2 ) ;
V_48 = - V_51 ;
}
F_6 ( & V_4 -> V_11 ) ;
return V_48 ;
}
static T_2 F_14 (
struct V_2 * V_3 ,
struct V_42 * V_43 ,
char * V_44 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_45 = F_8 ( V_43 ) -> V_46 ;
T_1 V_52 ;
switch ( V_45 ) {
case V_53 :
V_52 = V_4 -> V_19 & V_54 ;
break;
case V_55 :
V_52 = V_4 -> V_19 & V_56 ;
break;
case V_57 :
V_52 = V_4 -> V_21 & V_58 ;
break;
case V_59 :
V_52 = V_4 -> V_19 & V_60 ;
break;
case V_61 :
V_52 = V_4 -> V_19 & V_62 ;
break;
case V_63 :
V_52 = V_4 -> V_21 & V_64 ;
break;
default:
F_15 ( V_3 , L_3 , V_45 ) ;
return - V_65 ;
}
if ( V_52 )
return sprintf ( V_44 , L_4 ) ;
else
return sprintf ( V_44 , L_5 ) ;
}
static T_2 F_16 (
struct V_2 * V_3 ,
struct V_42 * V_43 ,
char * V_44 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_19 & V_66 )
return sprintf ( V_44 , L_4 ) ;
else
return sprintf ( V_44 , L_5 ) ;
}
static T_2 F_17 (
struct V_2 * V_3 ,
struct V_42 * V_43 ,
char * V_44 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_44 , L_1 , V_4 -> V_23 ) ;
}
static T_2 F_18 (
struct V_2 * V_3 ,
struct V_42 * V_43 ,
const char * V_44 ,
T_3 V_48 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
long V_49 ;
int V_50 = F_10 ( V_44 , 10 , & V_49 ) ;
if ( V_50 )
return V_50 ;
F_3 ( & V_4 -> V_11 ) ;
V_4 -> V_23 = F_11 ( V_49 , 0 , 255 ) ;
F_12 ( V_6 , V_24 , V_4 -> V_23 ) ;
F_6 ( & V_4 -> V_11 ) ;
return V_48 ;
}
static T_2 F_19 (
struct V_2 * V_3 ,
struct V_42 * V_43 ,
char * V_44 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_44 , L_1 , V_4 -> V_41 ) ;
}
static T_2 F_20 (
struct V_2 * V_3 ,
struct V_42 * V_47 ,
const char * V_44 ,
T_3 V_48 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
long V_49 ;
int V_67 = F_10 ( V_44 , 10 , & V_49 ) ;
if ( V_67 )
return V_67 ;
F_3 ( & V_4 -> V_11 ) ;
V_67 = F_5 ( V_6 , V_39 ) ;
if ( V_67 < 0 ) {
F_13 ( & V_6 -> V_3 ,
L_6 ) ;
V_48 = V_67 ;
goto V_68;
}
switch ( V_49 ) {
case 1 :
V_67 &= ~ V_69 ;
V_67 &= ~ V_70 ;
break;
case 2 :
V_67 &= ~ V_69 ;
V_67 |= V_70 ;
break;
case 3 :
V_67 |= V_69 ;
V_67 |= V_70 ;
break;
default:
V_48 = - V_65 ;
goto V_68;
}
if ( F_12 ( V_6 , V_39 , V_67 ) ) {
F_13 ( & V_6 -> V_3 ,
L_7 ) ;
V_48 = - V_51 ;
}
V_68:
F_6 ( & V_4 -> V_11 ) ;
return V_48 ;
}
static T_2 F_21 (
struct V_2 * V_3 ,
struct V_42 * V_43 ,
char * V_44 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_44 , L_1 , V_4 -> V_40 ) ;
}
static T_2 F_22 (
struct V_2 * V_3 ,
struct V_42 * V_43 ,
char * V_44 )
{
int V_45 = F_23 ( V_43 ) -> V_46 ;
int V_71 = F_23 ( V_43 ) -> V_71 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
switch ( V_71 ) {
case 1 :
return sprintf ( V_44 , L_1 ,
V_4 -> V_34 [ V_45 ] * 1000 ) ;
case 2 :
return sprintf ( V_44 , L_1 ,
V_4 -> V_36 [ V_45 ] * 1000 ) ;
default:
F_15 ( V_3 , L_8 , V_71 ) ;
return - V_65 ;
}
}
static T_2 F_24 (
struct V_2 * V_3 ,
struct V_42 * V_43 ,
char * V_44 )
{
int V_45 = F_8 ( V_43 ) -> V_46 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_44 , L_1 , V_4 -> V_32 [ V_45 ] ) ;
}
static inline T_2 F_25 ( struct V_5 * V_6 ,
T_1 V_9 ,
T_1 V_72 ,
T_1 * V_73 )
{
int V_74 ;
T_1 V_75 ;
V_74 = V_73 [ 2 ] - V_73 [ 1 ] ;
for ( V_75 = 4 ; V_75 > 0 ; V_75 -- ) {
if ( V_74 * ( 0x20 >> V_75 ) >= V_72 )
break;
}
V_75 |= ( V_73 [ 1 ] & 0x7C ) << 1 ;
if ( F_12 ( V_6 ,
V_9 , V_75 ) ) {
F_13 ( & V_6 -> V_3 , L_2 ) ;
return - V_51 ;
}
return 0 ;
}
static T_2 F_26 (
struct V_2 * V_3 ,
struct V_42 * V_47 ,
const char * V_44 ,
T_3 V_48 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_45 = F_23 ( V_47 ) -> V_46 ;
int V_71 = F_23 ( V_47 ) -> V_71 ;
T_1 * V_73 ;
T_1 V_9 ;
int V_72 ;
long V_49 ;
int V_50 = F_10 ( V_44 , 10 , & V_49 ) ;
if ( V_50 )
return V_50 ;
switch ( V_71 ) {
case 1 :
V_73 = V_4 -> V_34 ;
V_9 = V_37 ;
break;
case 2 :
V_73 = V_4 -> V_36 ;
V_9 = V_38 ;
break;
default:
F_15 ( V_3 , L_8 , V_71 ) ;
return - V_65 ;
}
F_3 ( & V_4 -> V_11 ) ;
V_4 -> V_14 = 0 ;
switch ( V_45 ) {
case 0 :
V_73 [ 0 ] = F_11 ( V_49 / 1000 , 0 ,
V_4 -> V_34 [ 1 ] ) ;
V_73 [ 0 ] = F_11 ( V_73 [ 0 ] , 0 ,
V_4 -> V_36 [ 1 ] ) ;
V_73 [ 0 ] = F_11 ( V_73 [ 0 ] , 0 , 63 ) ;
if ( F_12 (
V_6 ,
V_35 ,
V_73 [ 0 ] ) ) {
F_13 ( & V_6 -> V_3 ,
L_2 ) ;
V_48 = - V_51 ;
}
goto EXIT;
case 1 :
V_73 [ 1 ] = F_11 ( V_49 / 1000 , ( V_73 [ 0 ] & 0x7C ) + 4 , 124 ) ;
V_73 [ 1 ] &= 0x7C ;
V_73 [ 2 ] = F_11 ( V_73 [ 2 ] , V_73 [ 1 ] + 1 , 255 ) ;
break;
case 2 :
V_73 [ 2 ] = F_11 ( V_49 / 1000 , V_73 [ 1 ] + 1 , 255 ) ;
break;
default:
F_15 ( V_3 , L_3 , V_45 ) ;
V_48 = - V_65 ;
goto EXIT;
}
V_72 = V_4 -> V_32 [ 2 ] - V_4 -> V_32 [ 1 ] ;
if ( F_25 ( V_6 , V_9 , V_72 , V_73 ) )
V_48 = - V_51 ;
EXIT:
F_6 ( & V_4 -> V_11 ) ;
return V_48 ;
}
static T_2 F_27 (
struct V_2 * V_3 ,
struct V_42 * V_47 ,
const char * V_44 ,
T_3 V_48 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_72 ;
long V_49 ;
int V_50 = F_10 ( V_44 , 10 , & V_49 ) ;
if ( V_50 )
return V_50 ;
F_3 ( & V_4 -> V_11 ) ;
V_4 -> V_32 [ 1 ] = F_11 ( V_49 , 0 , 254 ) ;
if ( F_12 ( V_6 , V_33 ,
V_4 -> V_32 [ 1 ] ) ) {
F_13 ( & V_6 -> V_3 , L_2 ) ;
V_48 = - V_51 ;
goto EXIT;
}
V_72 = V_4 -> V_32 [ 2 ] - V_4 -> V_32 [ 1 ] ;
if ( F_25 ( V_6 , V_37 , V_72 ,
V_4 -> V_34 ) ) {
V_48 = - V_51 ;
goto EXIT;
}
if ( F_25 ( V_6 , V_38 , V_72 ,
V_4 -> V_36 ) ) {
V_48 = - V_51 ;
goto EXIT;
}
EXIT:
V_4 -> V_14 = 0 ;
F_6 ( & V_4 -> V_11 ) ;
return V_48 ;
}
static T_2 F_28 (
struct V_2 * V_3 ,
struct V_42 * V_43 ,
char * V_44 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_45 = F_8 ( V_43 ) -> V_46 ;
if ( 0 == V_4 -> V_26 [ V_45 ] )
return sprintf ( V_44 , L_5 ) ;
return sprintf ( V_44 , L_1 , ( int ) ( 6000000 / V_4 -> V_26 [ V_45 ] ) ) ;
}
static T_2 F_29 (
struct V_2 * V_3 ,
struct V_42 * V_43 ,
char * V_44 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_19 & V_76 )
return sprintf ( V_44 , L_4 ) ;
else
return sprintf ( V_44 , L_5 ) ;
}
static T_2 F_30 (
struct V_2 * V_3 ,
struct V_42 * V_47 ,
const char * V_44 , T_3 V_48 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
long V_49 ;
int V_45 = F_8 ( V_47 ) -> V_46 ;
int V_50 = F_10 ( V_44 , 10 , & V_49 ) ;
if ( V_50 )
return V_50 ;
V_49 = 1 > V_49 ? 0xFFFF : 6000000 / V_49 ;
F_3 ( & V_4 -> V_11 ) ;
V_4 -> V_26 [ V_45 ] = ( V_77 ) F_11 ( V_49 , 1 , 0xFFFF ) ;
if ( F_12 ( V_6 , V_27 [ V_45 ] ,
V_4 -> V_26 [ V_45 ] & 0xFF ) ) {
F_13 ( & V_6 -> V_3 , L_2 ) ;
V_48 = - V_51 ;
goto EXIT;
}
if ( F_12 ( V_6 ,
V_28 [ V_45 ] , V_4 -> V_26 [ V_45 ] >> 8 ) ) {
F_13 ( & V_6 -> V_3 , L_2 ) ;
V_48 = - V_51 ;
}
EXIT:
F_6 ( & V_4 -> V_11 ) ;
return V_48 ;
}
static T_2 F_31 (
struct V_2 * V_3 ,
struct V_42 * V_43 ,
char * V_44 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_44 , L_1 , V_4 -> V_29 ) ;
}
static T_2 F_32 (
struct V_2 * V_3 ,
struct V_42 * V_47 ,
const char * V_44 , T_3 V_48 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
long V_49 ;
int V_67 = F_10 ( V_44 , 10 , & V_49 ) ;
if ( V_67 )
return V_67 ;
F_3 ( & V_4 -> V_11 ) ;
V_67 = F_5 ( V_6 , V_30 ) ;
if ( V_67 < 0 ) {
F_13 ( & V_6 -> V_3 ,
L_6 ) ;
V_48 = V_67 ;
goto EXIT;
}
switch ( V_49 ) {
case 2 :
V_67 &= ~ V_31 ;
V_4 -> V_29 = 2 ;
break;
case 4 :
V_67 |= V_31 ;
V_4 -> V_29 = 4 ;
break;
default:
V_48 = - V_65 ;
goto EXIT;
}
if ( F_12 ( V_6 , V_30 , V_67 ) ) {
F_13 ( & V_6 -> V_3 ,
L_7 ) ;
V_48 = - V_51 ;
}
EXIT:
F_6 ( & V_4 -> V_11 ) ;
return V_48 ;
}
static int F_33 (
struct V_5 * V_6 ,
struct V_78 * V_79 )
{
struct V_80 * V_81 = V_6 -> V_81 ;
int V_82 = V_6 -> V_83 ;
int V_84 , V_85 ;
F_15 ( & V_81 -> V_3 , L_9 ) ;
if ( ! F_34 ( V_81 , V_86 ) ) {
F_15 ( & V_81 -> V_3 ,
L_10
L_11 ) ;
return - V_87 ;
}
V_84 = F_5 ( V_6 , V_88 ) ;
V_85 = F_5 ( V_6 , V_89 ) ;
if ( V_84 != 0x21 || V_85 != 0x49 ) {
F_15 ( & V_81 -> V_3 ,
L_12 ,
V_82 ) ;
return - V_87 ;
}
V_84 = F_5 ( V_6 , 0x80 | V_88 ) ;
V_85 = F_5 ( V_6 , 0x80 | V_89 ) ;
if ( V_84 != 0x21 || V_85 != 0x49 ) {
F_15 ( & V_81 -> V_3 ,
L_12 ,
V_82 ) ;
return - V_87 ;
}
F_35 ( & V_81 -> V_3 , L_13 , V_82 ) ;
F_36 ( V_79 -> type , L_14 , V_90 ) ;
return 0 ;
}
static int F_37 ( struct V_5 * V_6 )
{
int V_67 ;
int V_91 = - V_51 ;
if ( V_92 ) {
V_67 = F_5 ( V_6 , V_30 ) ;
if ( V_67 < 0 ) {
F_13 ( & V_6 -> V_3 ,
L_6 ) ;
return V_91 ;
}
V_67 |= V_93 ;
if ( F_12 ( V_6 , V_30 ,
V_67 ) ) {
F_13 ( & V_6 -> V_3 ,
L_7 ) ;
return V_91 ;
}
V_67 = F_5 ( V_6 , V_94 ) ;
if ( V_67 < 0 ) {
F_13 ( & V_6 -> V_3 ,
L_6 ) ;
return V_91 ;
}
F_35 ( & V_6 -> V_3 , L_15 , V_67 & 0x0f ) ;
V_67 &= ~ V_95 ;
if ( F_12 ( V_6 , V_94 ,
V_67 ) ) {
F_13 ( & V_6 -> V_3 ,
L_7 ) ;
return V_91 ;
}
V_67 = F_5 ( V_6 , V_96 ) ;
if ( V_67 < 0 ) {
F_13 ( & V_6 -> V_3 ,
L_6 ) ;
return V_91 ;
}
V_67 &= ~ V_97 ;
V_67 &= ~ V_98 ;
V_67 &= ~ V_99 ;
if ( F_12 ( V_6 ,
V_96 , V_67 ) ) {
F_13 ( & V_6 -> V_3 ,
L_7 ) ;
return V_91 ;
}
V_67 = F_5 ( V_6 , V_39 ) ;
if ( V_67 < 0 ) {
F_13 ( & V_6 -> V_3 ,
L_6 ) ;
return V_91 ;
}
V_67 &= ~ V_100 ;
V_67 &= ~ V_101 ;
V_67 |= V_102 ;
if ( V_103 )
V_67 |= V_104 ;
else
V_67 &= ~ V_104 ;
if ( F_12 (
V_6 , V_39 , V_67 ) ) {
F_13 ( & V_6 -> V_3 ,
L_7 ) ;
return V_91 ;
}
}
return 0 ;
}
static int F_38 ( struct V_5 * V_6 ,
const struct V_105 * V_106 )
{
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_1 * V_4 ;
struct V_2 * V_107 ;
int V_91 ;
V_4 = F_39 ( V_3 , sizeof( struct V_1 ) , V_108 ) ;
if ( ! V_4 )
return - V_109 ;
V_4 -> V_6 = V_6 ;
F_40 ( & V_4 -> V_11 ) ;
V_91 = F_37 ( V_6 ) ;
if ( V_91 )
return V_91 ;
V_107 = F_41 ( V_3 , V_6 -> V_110 ,
V_4 ,
V_111 ) ;
return F_42 ( V_107 ) ;
}
