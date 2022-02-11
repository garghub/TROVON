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
F_6 ( V_9 , V_13 , V_14 , V_15 , V_39 , V_40 ) ;
return 1 ;
case 0x0001 :
F_6 ( V_9 , V_13 , V_14 , V_15 , V_39 , V_41 ) ;
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
case V_42 :
return F_2 ( V_2 , V_9 , V_11 ,
V_13 , V_14 , V_15 ) ;
case V_43 :
case V_44 :
return F_5 ( V_2 , V_9 , V_11 ,
V_13 , V_14 , V_15 ) ;
default:
return 0 ;
}
}
static int F_8 ( struct V_1 * V_2 ,
unsigned char V_45 , unsigned char V_46 )
{
int V_47 ;
unsigned char V_48 [] = { 0x18 , V_45 , V_46 } ;
switch ( V_2 -> V_5 ) {
case V_43 :
V_47 = F_9 ( V_2 , 0x13 , V_48 , sizeof( V_48 ) ,
V_49 , V_50 ) ;
break;
case V_44 :
V_47 = F_10 ( V_2 , V_48 , sizeof( V_48 ) ) ;
break;
default:
V_47 = - V_51 ;
break;
}
return V_47 < 0 ? V_47 : 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
int V_47 ;
struct V_52 * V_53 = F_12 ( V_2 ) ;
V_47 = F_8 ( V_2 , 0x05 , V_53 -> V_54 ) ;
if ( V_47 )
F_13 ( V_2 , L_1 , V_47 ) ;
V_47 = F_8 ( V_2 , 0x02 , V_53 -> V_55 ) ;
if ( V_47 )
F_13 ( V_2 , L_2 , V_47 ) ;
}
static T_2 F_14 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
char * V_48 )
{
struct V_1 * V_2 = F_15 ( V_57 , struct V_1 , V_57 ) ;
struct V_52 * V_53 = F_12 ( V_2 ) ;
return snprintf ( V_48 , V_60 , L_3 , V_53 -> V_54 ) ;
}
static T_2 F_16 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char * V_48 ,
T_3 V_61 )
{
struct V_1 * V_2 = F_15 ( V_57 , struct V_1 , V_57 ) ;
struct V_52 * V_53 = F_12 ( V_2 ) ;
int V_62 ;
if ( F_17 ( V_48 , 10 , & V_62 ) )
return - V_51 ;
if ( V_62 < 0 || V_62 > 1 )
return - V_51 ;
V_53 -> V_54 = ! ! V_62 ;
F_11 ( V_2 ) ;
return V_61 ;
}
static T_2 F_18 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
char * V_48 )
{
struct V_1 * V_2 = F_15 ( V_57 , struct V_1 , V_57 ) ;
struct V_52 * V_53 = F_12 ( V_2 ) ;
return snprintf ( V_48 , V_60 , L_3 ,
V_53 -> V_55 ) ;
}
static T_2 F_19 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char * V_48 ,
T_3 V_61 )
{
struct V_1 * V_2 = F_15 ( V_57 , struct V_1 , V_57 ) ;
struct V_52 * V_53 = F_12 ( V_2 ) ;
int V_62 ;
if ( F_17 ( V_48 , 10 , & V_62 ) || V_62 < 1 || V_62 > 255 )
return - V_51 ;
V_53 -> V_55 = V_62 ;
F_11 ( V_2 ) ;
return V_61 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_63 * V_64 , T_4 * V_65 , int V_66 )
{
if ( F_21 ( V_2 -> V_5 == V_43
&& V_66 == 3
&& V_65 [ 0 ] == 0x15
&& V_65 [ 1 ] == 0x94
&& V_65 [ 2 ] == 0x01 ) ) {
V_65 [ 1 ] = 0x00 ;
V_65 [ 2 ] = 0x01 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_10 * V_11 , struct V_12 * V_13 , T_5 V_62 )
{
struct V_52 * V_53 = F_12 ( V_2 ) ;
if ( V_13 -> type == V_39 && ( V_13 -> V_67 == V_41 ||
V_13 -> V_67 == V_40 ) ) {
V_53 -> V_68 = 2 ;
return 0 ;
}
if ( V_13 -> type == V_69 && V_13 -> V_67 == V_31 ) {
if ( V_62 == 1 ) {
V_53 -> V_68 = 1 ;
} else if ( V_62 == 0 ) {
if ( V_53 -> V_68 == 1 ) {
F_23 ( V_11 -> V_70 -> V_71 ,
V_69 , V_31 , 1 ) ;
F_24 ( V_11 -> V_70 -> V_71 ) ;
F_23 ( V_11 -> V_70 -> V_71 ,
V_69 , V_31 , 0 ) ;
F_24 ( V_11 -> V_70 -> V_71 ) ;
}
V_53 -> V_68 = 0 ;
}
return 1 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_12 * V_13 , T_5 V_62 )
{
switch ( V_2 -> V_5 ) {
case V_43 :
case V_44 :
return F_22 ( V_2 , V_11 , V_13 , V_62 ) ;
default:
return 0 ;
}
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_63 * V_64 ;
struct V_72 * V_73 = F_12 ( V_2 ) ;
V_64 = V_2 -> V_74 [ V_49 ] . V_75 [ 4 ] ;
V_64 -> V_11 [ 0 ] -> V_62 [ 0 ] = V_73 -> V_76 ? 0x01 : 0x02 ;
V_64 -> V_11 [ 0 ] -> V_62 [ 0 ] |= V_73 -> V_77 ? 0x04 : 0x08 ;
V_64 -> V_11 [ 0 ] -> V_62 [ 0 ] |= V_73 -> V_78 ? 0x10 : 0x20 ;
V_64 -> V_11 [ 0 ] -> V_62 [ 0 ] |= V_73 -> V_79 ? 0x80 : 0x40 ;
V_64 -> V_11 [ 1 ] -> V_62 [ 0 ] = 0x03 ;
V_64 -> V_11 [ 2 ] -> V_62 [ 0 ] = V_73 -> V_55 ;
V_64 -> V_11 [ 3 ] -> V_62 [ 0 ] = V_73 -> V_80 ;
F_27 ( V_2 , V_64 , V_50 ) ;
return 0 ;
}
static T_2 F_28 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
char * V_48 )
{
struct V_1 * V_2 = F_15 ( V_57 , struct V_1 , V_57 ) ;
struct V_72 * V_73 = F_12 ( V_2 ) ;
return snprintf ( V_48 , V_60 , L_3 , V_73 -> V_76 ) ;
}
static T_2 F_29 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char * V_48 ,
T_3 V_61 )
{
struct V_1 * V_2 = F_15 ( V_57 , struct V_1 , V_57 ) ;
struct V_72 * V_73 = F_12 ( V_2 ) ;
int V_62 ;
if ( F_17 ( V_48 , 10 , & V_62 ) )
return - V_51 ;
if ( V_62 < 0 || V_62 > 1 )
return - V_51 ;
V_73 -> V_76 = V_62 ;
F_26 ( V_2 ) ;
return V_61 ;
}
static T_2 F_30 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
char * V_48 )
{
struct V_1 * V_2 = F_15 ( V_57 , struct V_1 , V_57 ) ;
struct V_72 * V_73 = F_12 ( V_2 ) ;
return snprintf ( V_48 , V_60 , L_3 , V_73 -> V_77 ) ;
}
static T_2 F_31 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char * V_48 ,
T_3 V_61 )
{
struct V_1 * V_2 = F_15 ( V_57 , struct V_1 , V_57 ) ;
struct V_72 * V_73 = F_12 ( V_2 ) ;
int V_62 ;
if ( F_17 ( V_48 , 10 , & V_62 ) )
return - V_51 ;
if ( V_62 < 0 || V_62 > 1 )
return - V_51 ;
V_73 -> V_77 = V_62 ;
F_26 ( V_2 ) ;
return V_61 ;
}
static T_2 F_32 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
char * V_48 )
{
struct V_1 * V_2 = F_15 ( V_57 , struct V_1 , V_57 ) ;
struct V_72 * V_73 = F_12 ( V_2 ) ;
return snprintf ( V_48 , V_60 , L_3 , V_73 -> V_78 ) ;
}
static T_2 F_33 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char * V_48 ,
T_3 V_61 )
{
struct V_1 * V_2 = F_15 ( V_57 , struct V_1 , V_57 ) ;
struct V_72 * V_73 = F_12 ( V_2 ) ;
int V_62 ;
if ( F_17 ( V_48 , 10 , & V_62 ) )
return - V_51 ;
if ( V_62 < 0 || V_62 > 1 )
return - V_51 ;
V_73 -> V_78 = V_62 ;
F_26 ( V_2 ) ;
return V_61 ;
}
static T_2 F_34 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
char * V_48 )
{
struct V_1 * V_2 = F_15 ( V_57 , struct V_1 , V_57 ) ;
struct V_72 * V_73 = F_12 ( V_2 ) ;
return snprintf ( V_48 , V_60 , L_3 , V_73 -> V_79 ) ;
}
static T_2 F_35 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char * V_48 ,
T_3 V_61 )
{
struct V_1 * V_2 = F_15 ( V_57 , struct V_1 , V_57 ) ;
struct V_72 * V_73 = F_12 ( V_2 ) ;
int V_62 ;
if ( F_17 ( V_48 , 10 , & V_62 ) )
return - V_51 ;
if ( V_62 < 0 || V_62 > 1 )
return - V_51 ;
V_73 -> V_79 = V_62 ;
F_26 ( V_2 ) ;
return V_61 ;
}
static T_2 F_36 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
char * V_48 )
{
struct V_1 * V_2 = F_15 ( V_57 , struct V_1 , V_57 ) ;
struct V_72 * V_73 = F_12 ( V_2 ) ;
return snprintf ( V_48 , V_60 , L_3 ,
V_73 -> V_55 ) ;
}
static T_2 F_37 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char * V_48 ,
T_3 V_61 )
{
struct V_1 * V_2 = F_15 ( V_57 , struct V_1 , V_57 ) ;
struct V_72 * V_73 = F_12 ( V_2 ) ;
int V_62 ;
if ( F_17 ( V_48 , 10 , & V_62 ) || V_62 < 1 || V_62 > 255 )
return - V_51 ;
V_73 -> V_55 = V_62 ;
F_26 ( V_2 ) ;
return V_61 ;
}
static T_2 F_38 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
char * V_48 )
{
struct V_1 * V_2 = F_15 ( V_57 , struct V_1 , V_57 ) ;
struct V_72 * V_73 = F_12 ( V_2 ) ;
return snprintf ( V_48 , V_60 , L_3 ,
V_73 -> V_80 ) ;
}
static T_2 F_39 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char * V_48 ,
T_3 V_61 )
{
struct V_1 * V_2 = F_15 ( V_57 , struct V_1 , V_57 ) ;
struct V_72 * V_73 = F_12 ( V_2 ) ;
int V_62 ;
if ( F_17 ( V_48 , 10 , & V_62 ) || V_62 < 1 || V_62 > 255 )
return - V_51 ;
V_73 -> V_80 = V_62 ;
F_26 ( V_2 ) ;
return V_61 ;
}
static enum V_81 F_40 (
struct V_82 * V_83 )
{
struct V_56 * V_57 = V_83 -> V_57 -> V_84 ;
struct V_1 * V_2 = F_15 ( V_57 , struct V_1 , V_57 ) ;
struct V_72 * V_73 = F_12 ( V_2 ) ;
int V_85 = 0 ;
if ( V_83 == & V_73 -> V_86 )
V_85 = 1 ;
return V_73 -> V_87 & ( 1 << V_85 )
? V_88
: V_89 ;
}
static void F_41 ( struct V_82 * V_83 ,
enum V_81 V_62 )
{
struct V_56 * V_57 = V_83 -> V_57 -> V_84 ;
struct V_1 * V_2 = F_15 ( V_57 , struct V_1 , V_57 ) ;
struct V_72 * V_73 = F_12 ( V_2 ) ;
struct V_63 * V_64 ;
int V_85 = 0 ;
if ( V_83 == & V_73 -> V_86 )
V_85 = 1 ;
if ( V_62 == V_89 )
V_73 -> V_87 &= ~ ( 1 << V_85 ) ;
else
V_73 -> V_87 |= 1 << V_85 ;
V_64 = V_2 -> V_74 [ V_90 ] . V_75 [ 3 ] ;
V_64 -> V_11 [ 0 ] -> V_62 [ 0 ] = ( V_73 -> V_87 >> 0 ) & 1 ;
V_64 -> V_11 [ 0 ] -> V_62 [ 1 ] = ( V_73 -> V_87 >> 1 ) & 1 ;
F_27 ( V_2 , V_64 , V_50 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = & V_2 -> V_57 ;
struct V_72 * V_73 ;
T_3 V_91 = strlen ( F_43 ( V_57 ) ) + 16 ;
char * V_92 , * V_93 ;
int V_94 ;
int V_47 ;
if ( ! F_12 ( V_2 ) )
return 0 ;
F_3 ( V_2 , NULL ) ;
for ( V_94 = 0 ; V_94 < 4 ; V_94 ++ ) {
if ( ! F_44 ( V_2 , V_49 , 4 , V_94 , 1 ) )
return - V_95 ;
}
if ( ! F_44 ( V_2 , V_90 , 3 , 0 , 2 ) )
return - V_95 ;
V_47 = F_45 ( & V_2 -> V_57 . V_96 , & V_97 ) ;
if ( V_47 )
F_46 ( V_2 , L_4 , V_47 ) ;
V_73 = F_47 ( & V_2 -> V_57 ,
sizeof( struct V_72 ) ,
V_98 ) ;
if ( V_73 == NULL ) {
F_13 ( V_2 , L_5 ) ;
V_47 = - V_99 ;
goto V_100;
}
V_73 -> V_55 = 0xa0 ;
V_73 -> V_80 = 0x38 ;
V_92 = F_47 ( & V_2 -> V_57 , V_91 , V_98 ) ;
V_93 = F_47 ( & V_2 -> V_57 , V_91 , V_98 ) ;
if ( V_92 == NULL || V_93 == NULL ) {
F_13 ( V_2 , L_6 ) ;
V_47 = - V_99 ;
goto V_100;
}
snprintf ( V_92 , V_91 , L_7 , F_43 ( V_57 ) ) ;
snprintf ( V_93 , V_91 , L_8 , F_43 ( V_57 ) ) ;
F_3 ( V_2 , V_73 ) ;
V_73 -> V_101 . V_102 = V_92 ;
V_73 -> V_101 . V_103 = F_40 ;
V_73 -> V_101 . V_104 = F_41 ;
V_73 -> V_101 . V_57 = V_57 ;
F_48 ( V_57 , & V_73 -> V_101 ) ;
V_73 -> V_86 . V_102 = V_93 ;
V_73 -> V_86 . V_103 =
F_40 ;
V_73 -> V_86 . V_104 =
F_41 ;
V_73 -> V_86 . V_57 = V_57 ;
F_48 ( V_57 , & V_73 -> V_86 ) ;
F_26 ( V_2 ) ;
return 0 ;
V_100:
F_49 ( & V_2 -> V_57 . V_96 , & V_97 ) ;
return V_47 ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_47 ;
struct V_52 * V_53 ;
if ( V_2 -> V_5 == V_43
&& V_2 -> type != V_105 ) {
F_51 ( V_2 , L_9 ) ;
return 0 ;
}
V_53 = F_47 ( & V_2 -> V_57 ,
sizeof( * V_53 ) ,
V_98 ) ;
if ( V_53 == NULL ) {
F_13 ( V_2 , L_10 ) ;
return - V_99 ;
}
F_3 ( V_2 , V_53 ) ;
V_47 = F_8 ( V_2 , 0x01 , 0x03 ) ;
if ( V_47 )
F_46 ( V_2 , L_11 , V_47 ) ;
V_47 = F_8 ( V_2 , 0x09 , 0x01 ) ;
if ( V_47 )
F_46 ( V_2 , L_12 , V_47 ) ;
V_53 -> V_68 = 0 ;
V_53 -> V_54 = true ;
V_53 -> V_55 = 0x05 ;
F_11 ( V_2 ) ;
V_47 = F_45 ( & V_2 -> V_57 . V_96 , & V_106 ) ;
if ( V_47 )
F_46 ( V_2 , L_4 , V_47 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
const struct V_107 * V_108 )
{
int V_47 ;
V_47 = F_53 ( V_2 ) ;
if ( V_47 ) {
F_13 ( V_2 , L_13 ) ;
goto V_100;
}
V_47 = F_54 ( V_2 , V_109 ) ;
if ( V_47 ) {
F_13 ( V_2 , L_14 ) ;
goto V_100;
}
switch ( V_2 -> V_5 ) {
case V_42 :
V_47 = F_42 ( V_2 ) ;
break;
case V_43 :
case V_44 :
V_47 = F_50 ( V_2 ) ;
break;
default:
V_47 = 0 ;
break;
}
if ( V_47 )
goto V_110;
return 0 ;
V_110:
F_55 ( V_2 ) ;
V_100:
return V_47 ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_72 * V_73 = F_12 ( V_2 ) ;
if ( V_73 == NULL )
return;
F_49 ( & V_2 -> V_57 . V_96 ,
& V_97 ) ;
F_57 ( & V_73 -> V_86 ) ;
F_57 ( & V_73 -> V_101 ) ;
F_3 ( V_2 , NULL ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
F_49 ( & V_2 -> V_57 . V_96 ,
& V_106 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_5 ) {
case V_42 :
F_56 ( V_2 ) ;
break;
case V_43 :
case V_44 :
F_58 ( V_2 ) ;
break;
}
F_55 ( V_2 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
switch ( V_2 -> V_5 ) {
case V_42 :
case V_43 :
case V_44 :
if ( F_61 ( V_39 , V_9 -> V_71 -> V_111 ) ) {
F_62 ( V_112 , V_9 -> V_71 -> V_113 ) ;
F_62 ( V_114 ,
V_9 -> V_71 -> V_113 ) ;
}
break;
}
}
