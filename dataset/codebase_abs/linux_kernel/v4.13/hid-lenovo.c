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
unsigned char * V_48 ;
V_48 = F_9 ( 3 , V_49 ) ;
if ( ! V_48 )
return - V_50 ;
V_48 [ 0 ] = 0x18 ;
V_48 [ 1 ] = V_45 ;
V_48 [ 2 ] = V_46 ;
switch ( V_2 -> V_5 ) {
case V_43 :
V_47 = F_10 ( V_2 , 0x13 , V_48 , 3 ,
V_51 , V_52 ) ;
break;
case V_44 :
V_47 = F_11 ( V_2 , V_48 , 3 ) ;
break;
default:
V_47 = - V_53 ;
break;
}
F_12 ( V_48 ) ;
return V_47 < 0 ? V_47 : 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
int V_47 ;
struct V_54 * V_55 = F_14 ( V_2 ) ;
V_47 = F_8 ( V_2 , 0x05 , V_55 -> V_56 ) ;
if ( V_47 )
F_15 ( V_2 , L_1 , V_47 ) ;
V_47 = F_8 ( V_2 , 0x02 , V_55 -> V_57 ) ;
if ( V_47 )
F_15 ( V_2 , L_2 , V_47 ) ;
}
static T_2 F_16 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
char * V_48 )
{
struct V_1 * V_2 = F_17 ( V_59 ) ;
struct V_54 * V_55 = F_14 ( V_2 ) ;
return snprintf ( V_48 , V_62 , L_3 , V_55 -> V_56 ) ;
}
static T_2 F_18 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
const char * V_48 ,
T_3 V_63 )
{
struct V_1 * V_2 = F_17 ( V_59 ) ;
struct V_54 * V_55 = F_14 ( V_2 ) ;
int V_64 ;
if ( F_19 ( V_48 , 10 , & V_64 ) )
return - V_53 ;
if ( V_64 < 0 || V_64 > 1 )
return - V_53 ;
V_55 -> V_56 = ! ! V_64 ;
F_13 ( V_2 ) ;
return V_63 ;
}
static T_2 F_20 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
char * V_48 )
{
struct V_1 * V_2 = F_17 ( V_59 ) ;
struct V_54 * V_55 = F_14 ( V_2 ) ;
return snprintf ( V_48 , V_62 , L_3 ,
V_55 -> V_57 ) ;
}
static T_2 F_21 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
const char * V_48 ,
T_3 V_63 )
{
struct V_1 * V_2 = F_17 ( V_59 ) ;
struct V_54 * V_55 = F_14 ( V_2 ) ;
int V_64 ;
if ( F_19 ( V_48 , 10 , & V_64 ) || V_64 < 1 || V_64 > 255 )
return - V_53 ;
V_55 -> V_57 = V_64 ;
F_13 ( V_2 ) ;
return V_63 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_65 * V_66 , T_4 * V_67 , int V_68 )
{
if ( F_23 ( V_2 -> V_5 == V_43
&& V_68 == 3
&& V_67 [ 0 ] == 0x15
&& V_67 [ 1 ] == 0x94
&& V_67 [ 2 ] == 0x01 ) ) {
V_67 [ 1 ] = 0x00 ;
V_67 [ 2 ] = 0x01 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_10 * V_11 , struct V_12 * V_13 , T_5 V_64 )
{
struct V_54 * V_55 = F_14 ( V_2 ) ;
if ( V_13 -> type == V_39 && ( V_13 -> V_69 == V_41 ||
V_13 -> V_69 == V_40 ) ) {
V_55 -> V_70 = 2 ;
return 0 ;
}
if ( V_13 -> type == V_71 && V_13 -> V_69 == V_31 ) {
if ( V_64 == 1 ) {
V_55 -> V_70 = 1 ;
} else if ( V_64 == 0 ) {
if ( V_55 -> V_70 == 1 ) {
F_25 ( V_11 -> V_72 -> V_73 ,
V_71 , V_31 , 1 ) ;
F_26 ( V_11 -> V_72 -> V_73 ) ;
F_25 ( V_11 -> V_72 -> V_73 ,
V_71 , V_31 , 0 ) ;
F_26 ( V_11 -> V_72 -> V_73 ) ;
}
V_55 -> V_70 = 0 ;
}
return 1 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_12 * V_13 , T_5 V_64 )
{
switch ( V_2 -> V_5 ) {
case V_43 :
case V_44 :
return F_24 ( V_2 , V_11 , V_13 , V_64 ) ;
default:
return 0 ;
}
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_65 * V_66 ;
struct V_74 * V_75 = F_14 ( V_2 ) ;
V_66 = V_2 -> V_76 [ V_51 ] . V_77 [ 4 ] ;
V_66 -> V_11 [ 0 ] -> V_64 [ 0 ] = V_75 -> V_78 ? 0x01 : 0x02 ;
V_66 -> V_11 [ 0 ] -> V_64 [ 0 ] |= V_75 -> V_79 ? 0x04 : 0x08 ;
V_66 -> V_11 [ 0 ] -> V_64 [ 0 ] |= V_75 -> V_80 ? 0x10 : 0x20 ;
V_66 -> V_11 [ 0 ] -> V_64 [ 0 ] |= V_75 -> V_81 ? 0x80 : 0x40 ;
V_66 -> V_11 [ 1 ] -> V_64 [ 0 ] = 0x03 ;
V_66 -> V_11 [ 2 ] -> V_64 [ 0 ] = V_75 -> V_57 ;
V_66 -> V_11 [ 3 ] -> V_64 [ 0 ] = V_75 -> V_82 ;
F_29 ( V_2 , V_66 , V_52 ) ;
return 0 ;
}
static T_2 F_30 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
char * V_48 )
{
struct V_1 * V_2 = F_17 ( V_59 ) ;
struct V_74 * V_75 = F_14 ( V_2 ) ;
return snprintf ( V_48 , V_62 , L_3 , V_75 -> V_78 ) ;
}
static T_2 F_31 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
const char * V_48 ,
T_3 V_63 )
{
struct V_1 * V_2 = F_17 ( V_59 ) ;
struct V_74 * V_75 = F_14 ( V_2 ) ;
int V_64 ;
if ( F_19 ( V_48 , 10 , & V_64 ) )
return - V_53 ;
if ( V_64 < 0 || V_64 > 1 )
return - V_53 ;
V_75 -> V_78 = V_64 ;
F_28 ( V_2 ) ;
return V_63 ;
}
static T_2 F_32 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
char * V_48 )
{
struct V_1 * V_2 = F_17 ( V_59 ) ;
struct V_74 * V_75 = F_14 ( V_2 ) ;
return snprintf ( V_48 , V_62 , L_3 , V_75 -> V_79 ) ;
}
static T_2 F_33 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
const char * V_48 ,
T_3 V_63 )
{
struct V_1 * V_2 = F_17 ( V_59 ) ;
struct V_74 * V_75 = F_14 ( V_2 ) ;
int V_64 ;
if ( F_19 ( V_48 , 10 , & V_64 ) )
return - V_53 ;
if ( V_64 < 0 || V_64 > 1 )
return - V_53 ;
V_75 -> V_79 = V_64 ;
F_28 ( V_2 ) ;
return V_63 ;
}
static T_2 F_34 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
char * V_48 )
{
struct V_1 * V_2 = F_17 ( V_59 ) ;
struct V_74 * V_75 = F_14 ( V_2 ) ;
return snprintf ( V_48 , V_62 , L_3 , V_75 -> V_80 ) ;
}
static T_2 F_35 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
const char * V_48 ,
T_3 V_63 )
{
struct V_1 * V_2 = F_17 ( V_59 ) ;
struct V_74 * V_75 = F_14 ( V_2 ) ;
int V_64 ;
if ( F_19 ( V_48 , 10 , & V_64 ) )
return - V_53 ;
if ( V_64 < 0 || V_64 > 1 )
return - V_53 ;
V_75 -> V_80 = V_64 ;
F_28 ( V_2 ) ;
return V_63 ;
}
static T_2 F_36 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
char * V_48 )
{
struct V_1 * V_2 = F_17 ( V_59 ) ;
struct V_74 * V_75 = F_14 ( V_2 ) ;
return snprintf ( V_48 , V_62 , L_3 , V_75 -> V_81 ) ;
}
static T_2 F_37 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
const char * V_48 ,
T_3 V_63 )
{
struct V_1 * V_2 = F_17 ( V_59 ) ;
struct V_74 * V_75 = F_14 ( V_2 ) ;
int V_64 ;
if ( F_19 ( V_48 , 10 , & V_64 ) )
return - V_53 ;
if ( V_64 < 0 || V_64 > 1 )
return - V_53 ;
V_75 -> V_81 = V_64 ;
F_28 ( V_2 ) ;
return V_63 ;
}
static T_2 F_38 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
char * V_48 )
{
struct V_1 * V_2 = F_17 ( V_59 ) ;
struct V_74 * V_75 = F_14 ( V_2 ) ;
return snprintf ( V_48 , V_62 , L_3 ,
V_75 -> V_57 ) ;
}
static T_2 F_39 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
const char * V_48 ,
T_3 V_63 )
{
struct V_1 * V_2 = F_17 ( V_59 ) ;
struct V_74 * V_75 = F_14 ( V_2 ) ;
int V_64 ;
if ( F_19 ( V_48 , 10 , & V_64 ) || V_64 < 1 || V_64 > 255 )
return - V_53 ;
V_75 -> V_57 = V_64 ;
F_28 ( V_2 ) ;
return V_63 ;
}
static T_2 F_40 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
char * V_48 )
{
struct V_1 * V_2 = F_17 ( V_59 ) ;
struct V_74 * V_75 = F_14 ( V_2 ) ;
return snprintf ( V_48 , V_62 , L_3 ,
V_75 -> V_82 ) ;
}
static T_2 F_41 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
const char * V_48 ,
T_3 V_63 )
{
struct V_1 * V_2 = F_17 ( V_59 ) ;
struct V_74 * V_75 = F_14 ( V_2 ) ;
int V_64 ;
if ( F_19 ( V_48 , 10 , & V_64 ) || V_64 < 1 || V_64 > 255 )
return - V_53 ;
V_75 -> V_82 = V_64 ;
F_28 ( V_2 ) ;
return V_63 ;
}
static enum V_83 F_42 (
struct V_84 * V_85 )
{
struct V_58 * V_59 = V_85 -> V_59 -> V_86 ;
struct V_1 * V_2 = F_17 ( V_59 ) ;
struct V_74 * V_75 = F_14 ( V_2 ) ;
int V_87 = 0 ;
if ( V_85 == & V_75 -> V_88 )
V_87 = 1 ;
return V_75 -> V_89 & ( 1 << V_87 )
? V_90
: V_91 ;
}
static void F_43 ( struct V_84 * V_85 ,
enum V_83 V_64 )
{
struct V_58 * V_59 = V_85 -> V_59 -> V_86 ;
struct V_1 * V_2 = F_17 ( V_59 ) ;
struct V_74 * V_75 = F_14 ( V_2 ) ;
struct V_65 * V_66 ;
int V_87 = 0 ;
if ( V_85 == & V_75 -> V_88 )
V_87 = 1 ;
if ( V_64 == V_91 )
V_75 -> V_89 &= ~ ( 1 << V_87 ) ;
else
V_75 -> V_89 |= 1 << V_87 ;
V_66 = V_2 -> V_76 [ V_92 ] . V_77 [ 3 ] ;
V_66 -> V_11 [ 0 ] -> V_64 [ 0 ] = ( V_75 -> V_89 >> 0 ) & 1 ;
V_66 -> V_11 [ 0 ] -> V_64 [ 1 ] = ( V_75 -> V_89 >> 1 ) & 1 ;
F_29 ( V_2 , V_66 , V_52 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_58 * V_59 = & V_2 -> V_59 ;
struct V_74 * V_75 ;
T_3 V_93 = strlen ( F_45 ( V_59 ) ) + 16 ;
char * V_94 , * V_95 ;
int V_96 ;
int V_47 ;
if ( ! F_14 ( V_2 ) )
return 0 ;
F_3 ( V_2 , NULL ) ;
for ( V_96 = 0 ; V_96 < 4 ; V_96 ++ ) {
if ( ! F_46 ( V_2 , V_51 , 4 , V_96 , 1 ) )
return - V_97 ;
}
if ( ! F_46 ( V_2 , V_92 , 3 , 0 , 2 ) )
return - V_97 ;
V_47 = F_47 ( & V_2 -> V_59 . V_98 , & V_99 ) ;
if ( V_47 )
F_48 ( V_2 , L_4 , V_47 ) ;
V_75 = F_49 ( & V_2 -> V_59 ,
sizeof( struct V_74 ) ,
V_49 ) ;
if ( V_75 == NULL ) {
F_15 ( V_2 , L_5 ) ;
V_47 = - V_50 ;
goto V_100;
}
V_75 -> V_57 = 0xa0 ;
V_75 -> V_82 = 0x38 ;
V_94 = F_49 ( & V_2 -> V_59 , V_93 , V_49 ) ;
V_95 = F_49 ( & V_2 -> V_59 , V_93 , V_49 ) ;
if ( V_94 == NULL || V_95 == NULL ) {
F_15 ( V_2 , L_6 ) ;
V_47 = - V_50 ;
goto V_100;
}
snprintf ( V_94 , V_93 , L_7 , F_45 ( V_59 ) ) ;
snprintf ( V_95 , V_93 , L_8 , F_45 ( V_59 ) ) ;
F_3 ( V_2 , V_75 ) ;
V_75 -> V_101 . V_102 = V_94 ;
V_75 -> V_101 . V_103 = F_42 ;
V_75 -> V_101 . V_104 = F_43 ;
V_75 -> V_101 . V_59 = V_59 ;
F_50 ( V_59 , & V_75 -> V_101 ) ;
V_75 -> V_88 . V_102 = V_95 ;
V_75 -> V_88 . V_103 =
F_42 ;
V_75 -> V_88 . V_104 =
F_43 ;
V_75 -> V_88 . V_59 = V_59 ;
F_50 ( V_59 , & V_75 -> V_88 ) ;
F_28 ( V_2 ) ;
return 0 ;
V_100:
F_51 ( & V_2 -> V_59 . V_98 , & V_99 ) ;
return V_47 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_47 ;
struct V_54 * V_55 ;
if ( V_2 -> V_5 == V_43
&& V_2 -> type != V_105 ) {
F_53 ( V_2 , L_9 ) ;
return 0 ;
}
V_55 = F_49 ( & V_2 -> V_59 ,
sizeof( * V_55 ) ,
V_49 ) ;
if ( V_55 == NULL ) {
F_15 ( V_2 , L_10 ) ;
return - V_50 ;
}
F_3 ( V_2 , V_55 ) ;
V_47 = F_8 ( V_2 , 0x01 , 0x03 ) ;
if ( V_47 )
F_48 ( V_2 , L_11 , V_47 ) ;
V_47 = F_8 ( V_2 , 0x09 , 0x01 ) ;
if ( V_47 )
F_48 ( V_2 , L_12 , V_47 ) ;
V_55 -> V_70 = 0 ;
V_55 -> V_56 = true ;
V_55 -> V_57 = 0x05 ;
F_13 ( V_2 ) ;
V_47 = F_47 ( & V_2 -> V_59 . V_98 , & V_106 ) ;
if ( V_47 )
F_48 ( V_2 , L_4 , V_47 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
const struct V_107 * V_108 )
{
int V_47 ;
V_47 = F_55 ( V_2 ) ;
if ( V_47 ) {
F_15 ( V_2 , L_13 ) ;
goto V_100;
}
V_47 = F_56 ( V_2 , V_109 ) ;
if ( V_47 ) {
F_15 ( V_2 , L_14 ) ;
goto V_100;
}
switch ( V_2 -> V_5 ) {
case V_42 :
V_47 = F_44 ( V_2 ) ;
break;
case V_43 :
case V_44 :
V_47 = F_52 ( V_2 ) ;
break;
default:
V_47 = 0 ;
break;
}
if ( V_47 )
goto V_110;
return 0 ;
V_110:
F_57 ( V_2 ) ;
V_100:
return V_47 ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_74 * V_75 = F_14 ( V_2 ) ;
if ( V_75 == NULL )
return;
F_51 ( & V_2 -> V_59 . V_98 ,
& V_99 ) ;
F_59 ( & V_75 -> V_88 ) ;
F_59 ( & V_75 -> V_101 ) ;
F_3 ( V_2 , NULL ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
F_51 ( & V_2 -> V_59 . V_98 ,
& V_106 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_5 ) {
case V_42 :
F_58 ( V_2 ) ;
break;
case V_43 :
case V_44 :
F_60 ( V_2 ) ;
break;
}
F_57 ( V_2 ) ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
switch ( V_2 -> V_5 ) {
case V_42 :
case V_43 :
case V_44 :
if ( F_63 ( V_39 , V_9 -> V_73 -> V_111 ) ) {
F_64 ( V_112 , V_9 -> V_73 -> V_113 ) ;
F_64 ( V_114 ,
V_9 -> V_73 -> V_113 ) ;
}
break;
}
return 0 ;
}
