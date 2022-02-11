static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
switch ( V_2 -> V_5 ) {
case V_6 :
if ( * V_4 >= 153 &&
memcmp ( & V_3 [ 140 ] , V_7 ,
sizeof( V_7 ) ) == 0 ) {
V_3 [ 151 ] = 0x01 ;
V_3 [ 152 ] = 0x00 ;
}
break;
}
return V_3 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_8 * V_9 , struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned long * * V_14 , int * V_15 )
{
if ( V_13 -> V_16 == ( V_17 | 0x0010 ) ) {
F_3 ( V_2 , ( void * ) 1 ) ;
F_4 ( V_18 ) ;
return 1 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_8 * V_9 , struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned long * * V_14 , int * V_15 )
{
if ( ( V_13 -> V_16 & V_19 ) == V_20 ||
( V_13 -> V_16 & V_19 ) == V_21 ) {
switch ( V_13 -> V_16 & V_22 ) {
case 0x00f1 :
F_4 ( V_18 ) ;
return 1 ;
case 0x00f2 :
F_4 ( V_23 ) ;
return 1 ;
case 0x00f3 :
F_4 ( V_24 ) ;
return 1 ;
case 0x00f4 :
F_4 ( V_25 ) ;
return 1 ;
case 0x00f5 :
F_4 ( V_26 ) ;
return 1 ;
case 0x00f6 :
F_4 ( V_27 ) ;
return 1 ;
case 0x00f8 :
F_4 ( V_28 ) ;
return 1 ;
case 0x00f9 :
F_4 ( V_29 ) ;
return 1 ;
case 0x00fa :
F_4 ( V_30 ) ;
return 1 ;
case 0x00fb :
F_4 ( V_31 ) ;
return 1 ;
}
}
if ( V_13 -> V_16 == V_32 )
return - 1 ;
if ( ( V_13 -> V_16 & V_19 ) == V_17 &&
( V_13 -> V_16 & V_22 ) == 0x003 )
return - 1 ;
if ( ( V_13 -> V_16 & V_19 ) == V_33 &&
( V_13 -> V_16 & V_22 ) == 0x238 )
return - 1 ;
if ( ( V_13 -> V_16 & V_19 ) == 0xff100000 ||
( V_13 -> V_16 & V_19 ) == 0xffa10000 ) {
V_11 -> V_34 |= V_35 | V_36 ;
V_11 -> V_37 = - 127 ;
V_11 -> V_38 = 127 ;
switch ( V_13 -> V_16 & V_22 ) {
case 0x0000 :
F_6 ( V_9 , V_13 , V_14 , V_15 , V_39 , 0x06 ) ;
return 1 ;
case 0x0001 :
F_6 ( V_9 , V_13 , V_14 , V_15 , V_39 , 0x08 ) ;
return 1 ;
default:
return - 1 ;
}
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_8 * V_9 , struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned long * * V_14 , int * V_15 )
{
switch ( V_2 -> V_5 ) {
case V_40 :
return F_2 ( V_2 , V_9 , V_11 ,
V_13 , V_14 , V_15 ) ;
case V_41 :
case V_42 :
return F_5 ( V_2 , V_9 , V_11 ,
V_13 , V_14 , V_15 ) ;
default:
return 0 ;
}
}
static int F_8 ( struct V_1 * V_2 ,
unsigned char V_43 , unsigned char V_44 )
{
int V_45 ;
unsigned char V_46 [] = { 0x18 , V_43 , V_44 } ;
switch ( V_2 -> V_5 ) {
case V_41 :
V_45 = F_9 ( V_2 , 0x13 , V_46 , sizeof( V_46 ) ,
V_47 , V_48 ) ;
break;
case V_42 :
V_45 = F_10 ( V_2 , V_46 , sizeof( V_46 ) ) ;
break;
default:
V_45 = - V_49 ;
break;
}
return V_45 < 0 ? V_45 : 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
int V_45 ;
struct V_50 * V_51 = F_12 ( V_2 ) ;
V_45 = F_8 ( V_2 , 0x05 , V_51 -> V_52 ) ;
V_45 = F_8 ( V_2 , 0x02 , V_51 -> V_53 ) ;
if ( V_45 )
F_13 ( V_2 , L_1 , V_45 ) ;
}
static T_2 F_14 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
char * V_46 )
{
struct V_1 * V_2 = F_15 ( V_55 , struct V_1 , V_55 ) ;
struct V_50 * V_51 = F_12 ( V_2 ) ;
return snprintf ( V_46 , V_58 , L_2 , V_51 -> V_52 ) ;
}
static T_2 F_16 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
const char * V_46 ,
T_3 V_59 )
{
struct V_1 * V_2 = F_15 ( V_55 , struct V_1 , V_55 ) ;
struct V_50 * V_51 = F_12 ( V_2 ) ;
int V_60 ;
if ( F_17 ( V_46 , 10 , & V_60 ) )
return - V_49 ;
if ( V_60 < 0 || V_60 > 1 )
return - V_49 ;
V_51 -> V_52 = ! ! V_60 ;
F_11 ( V_2 ) ;
return V_59 ;
}
static T_2 F_18 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
char * V_46 )
{
struct V_1 * V_2 = F_15 ( V_55 , struct V_1 , V_55 ) ;
struct V_50 * V_51 = F_12 ( V_2 ) ;
return snprintf ( V_46 , V_58 , L_2 ,
V_51 -> V_53 ) ;
}
static T_2 F_19 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
const char * V_46 ,
T_3 V_59 )
{
struct V_1 * V_2 = F_15 ( V_55 , struct V_1 , V_55 ) ;
struct V_50 * V_51 = F_12 ( V_2 ) ;
int V_60 ;
if ( F_17 ( V_46 , 10 , & V_60 ) || V_60 < 1 || V_60 > 255 )
return - V_49 ;
V_51 -> V_53 = V_60 ;
F_11 ( V_2 ) ;
return V_59 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_61 * V_62 , T_4 * V_63 , int V_64 )
{
if ( F_21 ( V_2 -> V_5 == V_41
&& V_64 == 3
&& V_63 [ 0 ] == 0x15
&& V_63 [ 1 ] == 0x94
&& V_63 [ 2 ] == 0x01 ) ) {
V_63 [ 1 ] = 0x00 ;
V_63 [ 2 ] = 0x01 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_61 * V_62 ;
struct V_65 * V_66 = F_12 ( V_2 ) ;
V_62 = V_2 -> V_67 [ V_47 ] . V_68 [ 4 ] ;
V_62 -> V_11 [ 0 ] -> V_60 [ 0 ] = V_66 -> V_69 ? 0x01 : 0x02 ;
V_62 -> V_11 [ 0 ] -> V_60 [ 0 ] |= V_66 -> V_70 ? 0x04 : 0x08 ;
V_62 -> V_11 [ 0 ] -> V_60 [ 0 ] |= V_66 -> V_71 ? 0x10 : 0x20 ;
V_62 -> V_11 [ 0 ] -> V_60 [ 0 ] |= V_66 -> V_72 ? 0x80 : 0x40 ;
V_62 -> V_11 [ 1 ] -> V_60 [ 0 ] = 0x03 ;
V_62 -> V_11 [ 2 ] -> V_60 [ 0 ] = V_66 -> V_53 ;
V_62 -> V_11 [ 3 ] -> V_60 [ 0 ] = V_66 -> V_73 ;
F_23 ( V_2 , V_62 , V_48 ) ;
return 0 ;
}
static T_2 F_24 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
char * V_46 )
{
struct V_1 * V_2 = F_15 ( V_55 , struct V_1 , V_55 ) ;
struct V_65 * V_66 = F_12 ( V_2 ) ;
return snprintf ( V_46 , V_58 , L_2 , V_66 -> V_69 ) ;
}
static T_2 F_25 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
const char * V_46 ,
T_3 V_59 )
{
struct V_1 * V_2 = F_15 ( V_55 , struct V_1 , V_55 ) ;
struct V_65 * V_66 = F_12 ( V_2 ) ;
int V_60 ;
if ( F_17 ( V_46 , 10 , & V_60 ) )
return - V_49 ;
if ( V_60 < 0 || V_60 > 1 )
return - V_49 ;
V_66 -> V_69 = V_60 ;
F_22 ( V_2 ) ;
return V_59 ;
}
static T_2 F_26 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
char * V_46 )
{
struct V_1 * V_2 = F_15 ( V_55 , struct V_1 , V_55 ) ;
struct V_65 * V_66 = F_12 ( V_2 ) ;
return snprintf ( V_46 , V_58 , L_2 , V_66 -> V_70 ) ;
}
static T_2 F_27 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
const char * V_46 ,
T_3 V_59 )
{
struct V_1 * V_2 = F_15 ( V_55 , struct V_1 , V_55 ) ;
struct V_65 * V_66 = F_12 ( V_2 ) ;
int V_60 ;
if ( F_17 ( V_46 , 10 , & V_60 ) )
return - V_49 ;
if ( V_60 < 0 || V_60 > 1 )
return - V_49 ;
V_66 -> V_70 = V_60 ;
F_22 ( V_2 ) ;
return V_59 ;
}
static T_2 F_28 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
char * V_46 )
{
struct V_1 * V_2 = F_15 ( V_55 , struct V_1 , V_55 ) ;
struct V_65 * V_66 = F_12 ( V_2 ) ;
return snprintf ( V_46 , V_58 , L_2 , V_66 -> V_71 ) ;
}
static T_2 F_29 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
const char * V_46 ,
T_3 V_59 )
{
struct V_1 * V_2 = F_15 ( V_55 , struct V_1 , V_55 ) ;
struct V_65 * V_66 = F_12 ( V_2 ) ;
int V_60 ;
if ( F_17 ( V_46 , 10 , & V_60 ) )
return - V_49 ;
if ( V_60 < 0 || V_60 > 1 )
return - V_49 ;
V_66 -> V_71 = V_60 ;
F_22 ( V_2 ) ;
return V_59 ;
}
static T_2 F_30 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
char * V_46 )
{
struct V_1 * V_2 = F_15 ( V_55 , struct V_1 , V_55 ) ;
struct V_65 * V_66 = F_12 ( V_2 ) ;
return snprintf ( V_46 , V_58 , L_2 , V_66 -> V_72 ) ;
}
static T_2 F_31 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
const char * V_46 ,
T_3 V_59 )
{
struct V_1 * V_2 = F_15 ( V_55 , struct V_1 , V_55 ) ;
struct V_65 * V_66 = F_12 ( V_2 ) ;
int V_60 ;
if ( F_17 ( V_46 , 10 , & V_60 ) )
return - V_49 ;
if ( V_60 < 0 || V_60 > 1 )
return - V_49 ;
V_66 -> V_72 = V_60 ;
F_22 ( V_2 ) ;
return V_59 ;
}
static T_2 F_32 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
char * V_46 )
{
struct V_1 * V_2 = F_15 ( V_55 , struct V_1 , V_55 ) ;
struct V_65 * V_66 = F_12 ( V_2 ) ;
return snprintf ( V_46 , V_58 , L_2 ,
V_66 -> V_53 ) ;
}
static T_2 F_33 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
const char * V_46 ,
T_3 V_59 )
{
struct V_1 * V_2 = F_15 ( V_55 , struct V_1 , V_55 ) ;
struct V_65 * V_66 = F_12 ( V_2 ) ;
int V_60 ;
if ( F_17 ( V_46 , 10 , & V_60 ) || V_60 < 1 || V_60 > 255 )
return - V_49 ;
V_66 -> V_53 = V_60 ;
F_22 ( V_2 ) ;
return V_59 ;
}
static T_2 F_34 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
char * V_46 )
{
struct V_1 * V_2 = F_15 ( V_55 , struct V_1 , V_55 ) ;
struct V_65 * V_66 = F_12 ( V_2 ) ;
return snprintf ( V_46 , V_58 , L_2 ,
V_66 -> V_73 ) ;
}
static T_2 F_35 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
const char * V_46 ,
T_3 V_59 )
{
struct V_1 * V_2 = F_15 ( V_55 , struct V_1 , V_55 ) ;
struct V_65 * V_66 = F_12 ( V_2 ) ;
int V_60 ;
if ( F_17 ( V_46 , 10 , & V_60 ) || V_60 < 1 || V_60 > 255 )
return - V_49 ;
V_66 -> V_73 = V_60 ;
F_22 ( V_2 ) ;
return V_59 ;
}
static enum V_74 F_36 (
struct V_75 * V_76 )
{
struct V_54 * V_55 = V_76 -> V_55 -> V_77 ;
struct V_1 * V_2 = F_15 ( V_55 , struct V_1 , V_55 ) ;
struct V_65 * V_66 = F_12 ( V_2 ) ;
int V_78 = 0 ;
if ( V_76 == & V_66 -> V_79 )
V_78 = 1 ;
return V_66 -> V_80 & ( 1 << V_78 )
? V_81
: V_82 ;
}
static void F_37 ( struct V_75 * V_76 ,
enum V_74 V_60 )
{
struct V_54 * V_55 = V_76 -> V_55 -> V_77 ;
struct V_1 * V_2 = F_15 ( V_55 , struct V_1 , V_55 ) ;
struct V_65 * V_66 = F_12 ( V_2 ) ;
struct V_61 * V_62 ;
int V_78 = 0 ;
if ( V_76 == & V_66 -> V_79 )
V_78 = 1 ;
if ( V_60 == V_82 )
V_66 -> V_80 &= ~ ( 1 << V_78 ) ;
else
V_66 -> V_80 |= 1 << V_78 ;
V_62 = V_2 -> V_67 [ V_83 ] . V_68 [ 3 ] ;
V_62 -> V_11 [ 0 ] -> V_60 [ 0 ] = ( V_66 -> V_80 >> 0 ) & 1 ;
V_62 -> V_11 [ 0 ] -> V_60 [ 1 ] = ( V_66 -> V_80 >> 1 ) & 1 ;
F_23 ( V_2 , V_62 , V_48 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = & V_2 -> V_55 ;
struct V_65 * V_66 ;
T_3 V_84 = strlen ( F_39 ( V_55 ) ) + 16 ;
char * V_85 , * V_86 ;
int V_87 ;
int V_45 ;
if ( ! F_12 ( V_2 ) )
return 0 ;
F_3 ( V_2 , NULL ) ;
for ( V_87 = 0 ; V_87 < 4 ; V_87 ++ ) {
if ( ! F_40 ( V_2 , V_47 , 4 , V_87 , 1 ) )
return - V_88 ;
}
if ( ! F_40 ( V_2 , V_83 , 3 , 0 , 2 ) )
return - V_88 ;
V_45 = F_41 ( & V_2 -> V_55 . V_89 , & V_90 ) ;
if ( V_45 )
F_42 ( V_2 , L_3 , V_45 ) ;
V_66 = F_43 ( & V_2 -> V_55 ,
sizeof( struct V_65 ) ,
V_91 ) ;
if ( V_66 == NULL ) {
F_13 ( V_2 , L_4 ) ;
V_45 = - V_92 ;
goto V_93;
}
V_66 -> V_53 = 0xa0 ;
V_66 -> V_73 = 0x38 ;
V_85 = F_43 ( & V_2 -> V_55 , V_84 , V_91 ) ;
V_86 = F_43 ( & V_2 -> V_55 , V_84 , V_91 ) ;
if ( V_85 == NULL || V_86 == NULL ) {
F_13 ( V_2 , L_5 ) ;
V_45 = - V_92 ;
goto V_93;
}
snprintf ( V_85 , V_84 , L_6 , F_39 ( V_55 ) ) ;
snprintf ( V_86 , V_84 , L_7 , F_39 ( V_55 ) ) ;
F_3 ( V_2 , V_66 ) ;
V_66 -> V_94 . V_95 = V_85 ;
V_66 -> V_94 . V_96 = F_36 ;
V_66 -> V_94 . V_97 = F_37 ;
V_66 -> V_94 . V_55 = V_55 ;
F_44 ( V_55 , & V_66 -> V_94 ) ;
V_66 -> V_79 . V_95 = V_86 ;
V_66 -> V_79 . V_96 =
F_36 ;
V_66 -> V_79 . V_97 =
F_37 ;
V_66 -> V_79 . V_55 = V_55 ;
F_44 ( V_55 , & V_66 -> V_79 ) ;
F_22 ( V_2 ) ;
return 0 ;
V_93:
F_45 ( & V_2 -> V_55 . V_89 , & V_90 ) ;
return V_45 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_45 ;
struct V_50 * V_51 ;
if ( V_2 -> V_5 == V_41
&& V_2 -> type != V_98 ) {
F_47 ( V_2 , L_8 ) ;
return 0 ;
}
V_51 = F_43 ( & V_2 -> V_55 ,
sizeof( * V_51 ) ,
V_91 ) ;
if ( V_51 == NULL ) {
F_13 ( V_2 , L_9 ) ;
return - V_92 ;
}
F_3 ( V_2 , V_51 ) ;
V_45 = F_8 ( V_2 , 0x01 , 0x03 ) ;
if ( V_45 )
F_42 ( V_2 , L_10 , V_45 ) ;
V_45 = F_8 ( V_2 , 0x09 , 0x01 ) ;
if ( V_45 )
F_42 ( V_2 , L_11 , V_45 ) ;
V_51 -> V_52 = true ;
V_51 -> V_53 = 0x05 ;
F_11 ( V_2 ) ;
V_45 = F_41 ( & V_2 -> V_55 . V_89 , & V_99 ) ;
if ( V_45 )
F_42 ( V_2 , L_3 , V_45 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
const struct V_100 * V_101 )
{
int V_45 ;
V_45 = F_49 ( V_2 ) ;
if ( V_45 ) {
F_13 ( V_2 , L_12 ) ;
goto V_93;
}
V_45 = F_50 ( V_2 , V_102 ) ;
if ( V_45 ) {
F_13 ( V_2 , L_13 ) ;
goto V_93;
}
switch ( V_2 -> V_5 ) {
case V_40 :
V_45 = F_38 ( V_2 ) ;
break;
case V_41 :
case V_42 :
V_45 = F_46 ( V_2 ) ;
break;
default:
V_45 = 0 ;
break;
}
if ( V_45 )
goto V_103;
return 0 ;
V_103:
F_51 ( V_2 ) ;
V_93:
return V_45 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = F_12 ( V_2 ) ;
if ( V_66 == NULL )
return;
F_45 ( & V_2 -> V_55 . V_89 ,
& V_90 ) ;
F_53 ( & V_66 -> V_79 ) ;
F_53 ( & V_66 -> V_94 ) ;
F_3 ( V_2 , NULL ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_45 ( & V_2 -> V_55 . V_89 ,
& V_99 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_5 ) {
case V_40 :
F_52 ( V_2 ) ;
break;
case V_41 :
case V_42 :
F_54 ( V_2 ) ;
break;
}
F_51 ( V_2 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
switch ( V_2 -> V_5 ) {
case V_40 :
case V_41 :
case V_42 :
if ( F_57 ( V_39 , V_9 -> V_104 -> V_105 ) ) {
F_58 ( V_106 , V_9 -> V_104 -> V_107 ) ;
F_58 ( V_108 ,
V_9 -> V_104 -> V_107 ) ;
}
break;
}
}
