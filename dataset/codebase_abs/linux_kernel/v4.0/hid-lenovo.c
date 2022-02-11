static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned long * * V_9 , int * V_10 )
{
if ( V_8 -> V_11 == ( V_12 | 0x0010 ) ) {
F_2 ( V_2 , ( void * ) 1 ) ;
F_3 ( V_13 ) ;
return 1 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned long * * V_9 , int * V_10 )
{
if ( ( V_8 -> V_11 & V_14 ) == V_15 ||
( V_8 -> V_11 & V_14 ) == V_16 ) {
switch ( V_8 -> V_11 & V_17 ) {
case 0x00f1 :
F_3 ( V_13 ) ;
return 1 ;
case 0x00f2 :
F_3 ( V_18 ) ;
return 1 ;
case 0x00f3 :
F_3 ( V_19 ) ;
return 1 ;
case 0x00f4 :
F_3 ( V_20 ) ;
return 1 ;
case 0x00f5 :
F_3 ( V_21 ) ;
return 1 ;
case 0x00f6 :
F_3 ( V_22 ) ;
return 1 ;
case 0x00f8 :
F_3 ( V_23 ) ;
return 1 ;
case 0x00f9 :
F_3 ( V_24 ) ;
return 1 ;
case 0x00fa :
F_3 ( V_25 ) ;
return 1 ;
case 0x00fb :
F_3 ( V_26 ) ;
return 1 ;
}
}
if ( V_8 -> V_11 == V_27 )
return - 1 ;
if ( ( V_8 -> V_11 & V_14 ) == V_12 &&
( V_8 -> V_11 & V_17 ) == 0x003 )
return - 1 ;
if ( ( V_8 -> V_11 & V_14 ) == V_28 &&
( V_8 -> V_11 & V_17 ) == 0x238 )
return - 1 ;
if ( ( V_8 -> V_11 & V_14 ) == 0xff100000 ||
( V_8 -> V_11 & V_14 ) == 0xffa10000 ) {
V_6 -> V_29 |= V_30 | V_31 ;
V_6 -> V_32 = - 127 ;
V_6 -> V_33 = 127 ;
switch ( V_8 -> V_11 & V_17 ) {
case 0x0000 :
F_5 ( V_4 , V_8 , V_9 , V_10 , V_34 , 0x06 ) ;
return 1 ;
case 0x0001 :
F_5 ( V_4 , V_8 , V_9 , V_10 , V_34 , 0x08 ) ;
return 1 ;
default:
return - 1 ;
}
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned long * * V_9 , int * V_10 )
{
switch ( V_2 -> V_35 ) {
case V_36 :
return F_1 ( V_2 , V_4 , V_6 ,
V_8 , V_9 , V_10 ) ;
case V_37 :
case V_38 :
return F_4 ( V_2 , V_4 , V_6 ,
V_8 , V_9 , V_10 ) ;
default:
return 0 ;
}
}
static int F_7 ( struct V_1 * V_2 ,
unsigned char V_39 , unsigned char V_40 )
{
int V_41 ;
unsigned char V_42 [] = { 0x18 , V_39 , V_40 } ;
switch ( V_2 -> V_35 ) {
case V_37 :
V_41 = F_8 ( V_2 , 0x13 , V_42 , sizeof( V_42 ) ,
V_43 , V_44 ) ;
break;
case V_38 :
V_41 = F_9 ( V_2 , V_42 , sizeof( V_42 ) ) ;
break;
default:
V_41 = - V_45 ;
break;
}
return V_41 < 0 ? V_41 : 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
int V_41 ;
struct V_46 * V_47 = F_11 ( V_2 ) ;
V_41 = F_7 ( V_2 , 0x05 , V_47 -> V_48 ) ;
V_41 = F_7 ( V_2 , 0x02 , V_47 -> V_49 ) ;
if ( V_41 )
F_12 ( V_2 , L_1 , V_41 ) ;
}
static T_1 F_13 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
char * V_42 )
{
struct V_1 * V_2 = F_14 ( V_51 , struct V_1 , V_51 ) ;
struct V_46 * V_47 = F_11 ( V_2 ) ;
return snprintf ( V_42 , V_54 , L_2 , V_47 -> V_48 ) ;
}
static T_1 F_15 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
const char * V_42 ,
T_2 V_55 )
{
struct V_1 * V_2 = F_14 ( V_51 , struct V_1 , V_51 ) ;
struct V_46 * V_47 = F_11 ( V_2 ) ;
int V_56 ;
if ( F_16 ( V_42 , 10 , & V_56 ) )
return - V_45 ;
if ( V_56 < 0 || V_56 > 1 )
return - V_45 ;
V_47 -> V_48 = ! ! V_56 ;
F_10 ( V_2 ) ;
return V_55 ;
}
static T_1 F_17 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
char * V_42 )
{
struct V_1 * V_2 = F_14 ( V_51 , struct V_1 , V_51 ) ;
struct V_46 * V_47 = F_11 ( V_2 ) ;
return snprintf ( V_42 , V_54 , L_2 ,
V_47 -> V_49 ) ;
}
static T_1 F_18 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
const char * V_42 ,
T_2 V_55 )
{
struct V_1 * V_2 = F_14 ( V_51 , struct V_1 , V_51 ) ;
struct V_46 * V_47 = F_11 ( V_2 ) ;
int V_56 ;
if ( F_16 ( V_42 , 10 , & V_56 ) || V_56 < 1 || V_56 > 255 )
return - V_45 ;
V_47 -> V_49 = V_56 ;
F_10 ( V_2 ) ;
return V_55 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_57 * V_58 , T_3 * V_59 , int V_60 )
{
if ( F_20 ( V_2 -> V_35 == V_37
&& V_60 == 3
&& V_59 [ 0 ] == 0x15
&& V_59 [ 1 ] == 0x94
&& V_59 [ 2 ] == 0x01 ) ) {
V_59 [ 1 ] = 0x00 ;
V_59 [ 2 ] = 0x01 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_57 * V_58 ;
struct V_61 * V_62 = F_11 ( V_2 ) ;
V_58 = V_2 -> V_63 [ V_43 ] . V_64 [ 4 ] ;
V_58 -> V_6 [ 0 ] -> V_56 [ 0 ] = V_62 -> V_65 ? 0x01 : 0x02 ;
V_58 -> V_6 [ 0 ] -> V_56 [ 0 ] |= V_62 -> V_66 ? 0x04 : 0x08 ;
V_58 -> V_6 [ 0 ] -> V_56 [ 0 ] |= V_62 -> V_67 ? 0x10 : 0x20 ;
V_58 -> V_6 [ 0 ] -> V_56 [ 0 ] |= V_62 -> V_68 ? 0x80 : 0x40 ;
V_58 -> V_6 [ 1 ] -> V_56 [ 0 ] = 0x03 ;
V_58 -> V_6 [ 2 ] -> V_56 [ 0 ] = V_62 -> V_49 ;
V_58 -> V_6 [ 3 ] -> V_56 [ 0 ] = V_62 -> V_69 ;
F_22 ( V_2 , V_58 , V_44 ) ;
return 0 ;
}
static T_1 F_23 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
char * V_42 )
{
struct V_1 * V_2 = F_14 ( V_51 , struct V_1 , V_51 ) ;
struct V_61 * V_62 = F_11 ( V_2 ) ;
return snprintf ( V_42 , V_54 , L_2 , V_62 -> V_65 ) ;
}
static T_1 F_24 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
const char * V_42 ,
T_2 V_55 )
{
struct V_1 * V_2 = F_14 ( V_51 , struct V_1 , V_51 ) ;
struct V_61 * V_62 = F_11 ( V_2 ) ;
int V_56 ;
if ( F_16 ( V_42 , 10 , & V_56 ) )
return - V_45 ;
if ( V_56 < 0 || V_56 > 1 )
return - V_45 ;
V_62 -> V_65 = V_56 ;
F_21 ( V_2 ) ;
return V_55 ;
}
static T_1 F_25 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
char * V_42 )
{
struct V_1 * V_2 = F_14 ( V_51 , struct V_1 , V_51 ) ;
struct V_61 * V_62 = F_11 ( V_2 ) ;
return snprintf ( V_42 , V_54 , L_2 , V_62 -> V_66 ) ;
}
static T_1 F_26 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
const char * V_42 ,
T_2 V_55 )
{
struct V_1 * V_2 = F_14 ( V_51 , struct V_1 , V_51 ) ;
struct V_61 * V_62 = F_11 ( V_2 ) ;
int V_56 ;
if ( F_16 ( V_42 , 10 , & V_56 ) )
return - V_45 ;
if ( V_56 < 0 || V_56 > 1 )
return - V_45 ;
V_62 -> V_66 = V_56 ;
F_21 ( V_2 ) ;
return V_55 ;
}
static T_1 F_27 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
char * V_42 )
{
struct V_1 * V_2 = F_14 ( V_51 , struct V_1 , V_51 ) ;
struct V_61 * V_62 = F_11 ( V_2 ) ;
return snprintf ( V_42 , V_54 , L_2 , V_62 -> V_67 ) ;
}
static T_1 F_28 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
const char * V_42 ,
T_2 V_55 )
{
struct V_1 * V_2 = F_14 ( V_51 , struct V_1 , V_51 ) ;
struct V_61 * V_62 = F_11 ( V_2 ) ;
int V_56 ;
if ( F_16 ( V_42 , 10 , & V_56 ) )
return - V_45 ;
if ( V_56 < 0 || V_56 > 1 )
return - V_45 ;
V_62 -> V_67 = V_56 ;
F_21 ( V_2 ) ;
return V_55 ;
}
static T_1 F_29 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
char * V_42 )
{
struct V_1 * V_2 = F_14 ( V_51 , struct V_1 , V_51 ) ;
struct V_61 * V_62 = F_11 ( V_2 ) ;
return snprintf ( V_42 , V_54 , L_2 , V_62 -> V_68 ) ;
}
static T_1 F_30 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
const char * V_42 ,
T_2 V_55 )
{
struct V_1 * V_2 = F_14 ( V_51 , struct V_1 , V_51 ) ;
struct V_61 * V_62 = F_11 ( V_2 ) ;
int V_56 ;
if ( F_16 ( V_42 , 10 , & V_56 ) )
return - V_45 ;
if ( V_56 < 0 || V_56 > 1 )
return - V_45 ;
V_62 -> V_68 = V_56 ;
F_21 ( V_2 ) ;
return V_55 ;
}
static T_1 F_31 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
char * V_42 )
{
struct V_1 * V_2 = F_14 ( V_51 , struct V_1 , V_51 ) ;
struct V_61 * V_62 = F_11 ( V_2 ) ;
return snprintf ( V_42 , V_54 , L_2 ,
V_62 -> V_49 ) ;
}
static T_1 F_32 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
const char * V_42 ,
T_2 V_55 )
{
struct V_1 * V_2 = F_14 ( V_51 , struct V_1 , V_51 ) ;
struct V_61 * V_62 = F_11 ( V_2 ) ;
int V_56 ;
if ( F_16 ( V_42 , 10 , & V_56 ) || V_56 < 1 || V_56 > 255 )
return - V_45 ;
V_62 -> V_49 = V_56 ;
F_21 ( V_2 ) ;
return V_55 ;
}
static T_1 F_33 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
char * V_42 )
{
struct V_1 * V_2 = F_14 ( V_51 , struct V_1 , V_51 ) ;
struct V_61 * V_62 = F_11 ( V_2 ) ;
return snprintf ( V_42 , V_54 , L_2 ,
V_62 -> V_69 ) ;
}
static T_1 F_34 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
const char * V_42 ,
T_2 V_55 )
{
struct V_1 * V_2 = F_14 ( V_51 , struct V_1 , V_51 ) ;
struct V_61 * V_62 = F_11 ( V_2 ) ;
int V_56 ;
if ( F_16 ( V_42 , 10 , & V_56 ) || V_56 < 1 || V_56 > 255 )
return - V_45 ;
V_62 -> V_69 = V_56 ;
F_21 ( V_2 ) ;
return V_55 ;
}
static enum V_70 F_35 (
struct V_71 * V_72 )
{
struct V_50 * V_51 = V_72 -> V_51 -> V_73 ;
struct V_1 * V_2 = F_14 ( V_51 , struct V_1 , V_51 ) ;
struct V_61 * V_62 = F_11 ( V_2 ) ;
int V_74 = 0 ;
if ( V_72 == & V_62 -> V_75 )
V_74 = 1 ;
return V_62 -> V_76 & ( 1 << V_74 )
? V_77
: V_78 ;
}
static void F_36 ( struct V_71 * V_72 ,
enum V_70 V_56 )
{
struct V_50 * V_51 = V_72 -> V_51 -> V_73 ;
struct V_1 * V_2 = F_14 ( V_51 , struct V_1 , V_51 ) ;
struct V_61 * V_62 = F_11 ( V_2 ) ;
struct V_57 * V_58 ;
int V_74 = 0 ;
if ( V_72 == & V_62 -> V_75 )
V_74 = 1 ;
if ( V_56 == V_78 )
V_62 -> V_76 &= ~ ( 1 << V_74 ) ;
else
V_62 -> V_76 |= 1 << V_74 ;
V_58 = V_2 -> V_63 [ V_79 ] . V_64 [ 3 ] ;
V_58 -> V_6 [ 0 ] -> V_56 [ 0 ] = ( V_62 -> V_76 >> 0 ) & 1 ;
V_58 -> V_6 [ 0 ] -> V_56 [ 1 ] = ( V_62 -> V_76 >> 1 ) & 1 ;
F_22 ( V_2 , V_58 , V_44 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = & V_2 -> V_51 ;
struct V_61 * V_62 ;
T_2 V_80 = strlen ( F_38 ( V_51 ) ) + 16 ;
char * V_81 , * V_82 ;
int V_83 ;
int V_41 ;
if ( ! F_11 ( V_2 ) )
return 0 ;
F_2 ( V_2 , NULL ) ;
for ( V_83 = 0 ; V_83 < 4 ; V_83 ++ ) {
if ( ! F_39 ( V_2 , V_43 , 4 , V_83 , 1 ) )
return - V_84 ;
}
if ( ! F_39 ( V_2 , V_79 , 3 , 0 , 2 ) )
return - V_84 ;
V_41 = F_40 ( & V_2 -> V_51 . V_85 , & V_86 ) ;
if ( V_41 )
F_41 ( V_2 , L_3 , V_41 ) ;
V_62 = F_42 ( & V_2 -> V_51 ,
sizeof( struct V_61 ) ,
V_87 ) ;
if ( V_62 == NULL ) {
F_12 ( V_2 , L_4 ) ;
return - V_88 ;
}
V_62 -> V_49 = 0xa0 ;
V_62 -> V_69 = 0x38 ;
V_81 = F_42 ( & V_2 -> V_51 , V_80 , V_87 ) ;
V_82 = F_42 ( & V_2 -> V_51 , V_80 , V_87 ) ;
if ( V_81 == NULL || V_82 == NULL ) {
F_12 ( V_2 , L_5 ) ;
return - V_88 ;
}
snprintf ( V_81 , V_80 , L_6 , F_38 ( V_51 ) ) ;
snprintf ( V_82 , V_80 , L_7 , F_38 ( V_51 ) ) ;
F_2 ( V_2 , V_62 ) ;
V_62 -> V_89 . V_90 = V_81 ;
V_62 -> V_89 . V_91 = F_35 ;
V_62 -> V_89 . V_92 = F_36 ;
V_62 -> V_89 . V_51 = V_51 ;
F_43 ( V_51 , & V_62 -> V_89 ) ;
V_62 -> V_75 . V_90 = V_82 ;
V_62 -> V_75 . V_91 =
F_35 ;
V_62 -> V_75 . V_92 =
F_36 ;
V_62 -> V_75 . V_51 = V_51 ;
F_43 ( V_51 , & V_62 -> V_75 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_41 ;
struct V_46 * V_47 ;
if ( V_2 -> V_35 == V_37
&& V_2 -> type != V_93 ) {
F_45 ( V_2 , L_8 ) ;
return 0 ;
}
V_47 = F_42 ( & V_2 -> V_51 ,
sizeof( * V_47 ) ,
V_87 ) ;
if ( V_47 == NULL ) {
F_12 ( V_2 , L_9 ) ;
return - V_88 ;
}
F_2 ( V_2 , V_47 ) ;
V_41 = F_7 ( V_2 , 0x01 , 0x03 ) ;
if ( V_41 )
F_41 ( V_2 , L_10 , V_41 ) ;
V_41 = F_7 ( V_2 , 0x09 , 0x01 ) ;
if ( V_41 )
F_41 ( V_2 , L_11 , V_41 ) ;
V_47 -> V_48 = true ;
V_47 -> V_49 = 0x05 ;
F_10 ( V_2 ) ;
V_41 = F_40 ( & V_2 -> V_51 . V_85 , & V_94 ) ;
if ( V_41 )
F_41 ( V_2 , L_3 , V_41 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
const struct V_95 * V_96 )
{
int V_41 ;
V_41 = F_47 ( V_2 ) ;
if ( V_41 ) {
F_12 ( V_2 , L_12 ) ;
goto V_97;
}
V_41 = F_48 ( V_2 , V_98 ) ;
if ( V_41 ) {
F_12 ( V_2 , L_13 ) ;
goto V_97;
}
switch ( V_2 -> V_35 ) {
case V_36 :
V_41 = F_37 ( V_2 ) ;
break;
case V_37 :
case V_38 :
V_41 = F_44 ( V_2 ) ;
break;
default:
V_41 = 0 ;
break;
}
if ( V_41 )
goto V_99;
return 0 ;
V_99:
F_49 ( V_2 ) ;
V_97:
return V_41 ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = F_11 ( V_2 ) ;
if ( V_62 == NULL )
return;
F_51 ( & V_2 -> V_51 . V_85 ,
& V_86 ) ;
F_52 ( & V_62 -> V_75 ) ;
F_52 ( & V_62 -> V_89 ) ;
F_2 ( V_2 , NULL ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_51 ( & V_2 -> V_51 . V_85 ,
& V_94 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_35 ) {
case V_36 :
F_50 ( V_2 ) ;
break;
case V_37 :
case V_38 :
F_53 ( V_2 ) ;
break;
}
F_49 ( V_2 ) ;
}
