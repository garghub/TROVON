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
}
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned long * * V_9 , int * V_10 )
{
switch ( V_2 -> V_26 ) {
case V_27 :
return F_1 ( V_2 , V_4 , V_6 ,
V_8 , V_9 , V_10 ) ;
case V_28 :
case V_29 :
return F_4 ( V_2 , V_4 , V_6 ,
V_8 , V_9 , V_10 ) ;
default:
return 0 ;
}
}
static int F_6 ( struct V_1 * V_2 ,
unsigned char V_30 , unsigned char V_31 )
{
int V_32 ;
unsigned char V_33 [] = { 0x18 , V_30 , V_31 } ;
switch ( V_2 -> V_26 ) {
case V_28 :
V_32 = F_7 ( V_2 , 0x13 , V_33 , sizeof( V_33 ) ,
V_34 , V_35 ) ;
break;
case V_29 :
V_32 = F_8 ( V_2 , V_33 , sizeof( V_33 ) ) ;
break;
default:
V_32 = - V_36 ;
break;
}
return V_32 < 0 ? V_32 : 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_32 ;
struct V_37 * V_38 = F_10 ( V_2 ) ;
V_32 = F_6 ( V_2 , 0x05 , V_38 -> V_39 ) ;
if ( V_32 )
F_11 ( V_2 , L_1 , V_32 ) ;
}
static T_1 F_12 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
char * V_33 )
{
struct V_1 * V_2 = F_13 ( V_41 , struct V_1 , V_41 ) ;
struct V_37 * V_38 = F_10 ( V_2 ) ;
return snprintf ( V_33 , V_44 , L_2 , V_38 -> V_39 ) ;
}
static T_1 F_14 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
const char * V_33 ,
T_2 V_45 )
{
struct V_1 * V_2 = F_13 ( V_41 , struct V_1 , V_41 ) ;
struct V_37 * V_38 = F_10 ( V_2 ) ;
int V_46 ;
if ( F_15 ( V_33 , 10 , & V_46 ) )
return - V_36 ;
if ( V_46 < 0 || V_46 > 1 )
return - V_36 ;
V_38 -> V_39 = ! ! V_46 ;
F_9 ( V_2 ) ;
return V_45 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_47 * V_48 , T_3 * V_49 , int V_50 )
{
if ( F_17 ( V_2 -> V_26 == V_28
&& V_50 == 3
&& V_49 [ 0 ] == 0x15
&& V_49 [ 1 ] == 0x94
&& V_49 [ 2 ] == 0x01 ) ) {
V_49 [ 1 ] = 0x00 ;
V_49 [ 2 ] = 0x01 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_47 * V_48 ;
struct V_51 * V_52 = F_10 ( V_2 ) ;
V_48 = V_2 -> V_53 [ V_34 ] . V_54 [ 4 ] ;
V_48 -> V_6 [ 0 ] -> V_46 [ 0 ] = V_52 -> V_55 ? 0x01 : 0x02 ;
V_48 -> V_6 [ 0 ] -> V_46 [ 0 ] |= V_52 -> V_56 ? 0x04 : 0x08 ;
V_48 -> V_6 [ 0 ] -> V_46 [ 0 ] |= V_52 -> V_57 ? 0x10 : 0x20 ;
V_48 -> V_6 [ 0 ] -> V_46 [ 0 ] |= V_52 -> V_58 ? 0x80 : 0x40 ;
V_48 -> V_6 [ 1 ] -> V_46 [ 0 ] = 0x03 ;
V_48 -> V_6 [ 2 ] -> V_46 [ 0 ] = V_52 -> V_59 ;
V_48 -> V_6 [ 3 ] -> V_46 [ 0 ] = V_52 -> V_60 ;
F_19 ( V_2 , V_48 , V_35 ) ;
return 0 ;
}
static T_1 F_20 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
char * V_33 )
{
struct V_1 * V_2 = F_13 ( V_41 , struct V_1 , V_41 ) ;
struct V_51 * V_52 = F_10 ( V_2 ) ;
return snprintf ( V_33 , V_44 , L_2 , V_52 -> V_55 ) ;
}
static T_1 F_21 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
const char * V_33 ,
T_2 V_45 )
{
struct V_1 * V_2 = F_13 ( V_41 , struct V_1 , V_41 ) ;
struct V_51 * V_52 = F_10 ( V_2 ) ;
int V_46 ;
if ( F_15 ( V_33 , 10 , & V_46 ) )
return - V_36 ;
if ( V_46 < 0 || V_46 > 1 )
return - V_36 ;
V_52 -> V_55 = V_46 ;
F_18 ( V_2 ) ;
return V_45 ;
}
static T_1 F_22 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
char * V_33 )
{
struct V_1 * V_2 = F_13 ( V_41 , struct V_1 , V_41 ) ;
struct V_51 * V_52 = F_10 ( V_2 ) ;
return snprintf ( V_33 , V_44 , L_2 , V_52 -> V_56 ) ;
}
static T_1 F_23 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
const char * V_33 ,
T_2 V_45 )
{
struct V_1 * V_2 = F_13 ( V_41 , struct V_1 , V_41 ) ;
struct V_51 * V_52 = F_10 ( V_2 ) ;
int V_46 ;
if ( F_15 ( V_33 , 10 , & V_46 ) )
return - V_36 ;
if ( V_46 < 0 || V_46 > 1 )
return - V_36 ;
V_52 -> V_56 = V_46 ;
F_18 ( V_2 ) ;
return V_45 ;
}
static T_1 F_24 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
char * V_33 )
{
struct V_1 * V_2 = F_13 ( V_41 , struct V_1 , V_41 ) ;
struct V_51 * V_52 = F_10 ( V_2 ) ;
return snprintf ( V_33 , V_44 , L_2 , V_52 -> V_57 ) ;
}
static T_1 F_25 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
const char * V_33 ,
T_2 V_45 )
{
struct V_1 * V_2 = F_13 ( V_41 , struct V_1 , V_41 ) ;
struct V_51 * V_52 = F_10 ( V_2 ) ;
int V_46 ;
if ( F_15 ( V_33 , 10 , & V_46 ) )
return - V_36 ;
if ( V_46 < 0 || V_46 > 1 )
return - V_36 ;
V_52 -> V_57 = V_46 ;
F_18 ( V_2 ) ;
return V_45 ;
}
static T_1 F_26 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
char * V_33 )
{
struct V_1 * V_2 = F_13 ( V_41 , struct V_1 , V_41 ) ;
struct V_51 * V_52 = F_10 ( V_2 ) ;
return snprintf ( V_33 , V_44 , L_2 , V_52 -> V_58 ) ;
}
static T_1 F_27 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
const char * V_33 ,
T_2 V_45 )
{
struct V_1 * V_2 = F_13 ( V_41 , struct V_1 , V_41 ) ;
struct V_51 * V_52 = F_10 ( V_2 ) ;
int V_46 ;
if ( F_15 ( V_33 , 10 , & V_46 ) )
return - V_36 ;
if ( V_46 < 0 || V_46 > 1 )
return - V_36 ;
V_52 -> V_58 = V_46 ;
F_18 ( V_2 ) ;
return V_45 ;
}
static T_1 F_28 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
char * V_33 )
{
struct V_1 * V_2 = F_13 ( V_41 , struct V_1 , V_41 ) ;
struct V_51 * V_52 = F_10 ( V_2 ) ;
return snprintf ( V_33 , V_44 , L_2 ,
V_52 -> V_59 ) ;
}
static T_1 F_29 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
const char * V_33 ,
T_2 V_45 )
{
struct V_1 * V_2 = F_13 ( V_41 , struct V_1 , V_41 ) ;
struct V_51 * V_52 = F_10 ( V_2 ) ;
int V_46 ;
if ( F_15 ( V_33 , 10 , & V_46 ) || V_46 < 1 || V_46 > 255 )
return - V_36 ;
V_52 -> V_59 = V_46 ;
F_18 ( V_2 ) ;
return V_45 ;
}
static T_1 F_30 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
char * V_33 )
{
struct V_1 * V_2 = F_13 ( V_41 , struct V_1 , V_41 ) ;
struct V_51 * V_52 = F_10 ( V_2 ) ;
return snprintf ( V_33 , V_44 , L_2 ,
V_52 -> V_60 ) ;
}
static T_1 F_31 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
const char * V_33 ,
T_2 V_45 )
{
struct V_1 * V_2 = F_13 ( V_41 , struct V_1 , V_41 ) ;
struct V_51 * V_52 = F_10 ( V_2 ) ;
int V_46 ;
if ( F_15 ( V_33 , 10 , & V_46 ) || V_46 < 1 || V_46 > 255 )
return - V_36 ;
V_52 -> V_60 = V_46 ;
F_18 ( V_2 ) ;
return V_45 ;
}
static enum V_61 F_32 (
struct V_62 * V_63 )
{
struct V_40 * V_41 = V_63 -> V_41 -> V_64 ;
struct V_1 * V_2 = F_13 ( V_41 , struct V_1 , V_41 ) ;
struct V_51 * V_52 = F_10 ( V_2 ) ;
int V_65 = 0 ;
if ( V_63 == & V_52 -> V_66 )
V_65 = 1 ;
return V_52 -> V_67 & ( 1 << V_65 )
? V_68
: V_69 ;
}
static void F_33 ( struct V_62 * V_63 ,
enum V_61 V_46 )
{
struct V_40 * V_41 = V_63 -> V_41 -> V_64 ;
struct V_1 * V_2 = F_13 ( V_41 , struct V_1 , V_41 ) ;
struct V_51 * V_52 = F_10 ( V_2 ) ;
struct V_47 * V_48 ;
int V_65 = 0 ;
if ( V_63 == & V_52 -> V_66 )
V_65 = 1 ;
if ( V_46 == V_69 )
V_52 -> V_67 &= ~ ( 1 << V_65 ) ;
else
V_52 -> V_67 |= 1 << V_65 ;
V_48 = V_2 -> V_53 [ V_70 ] . V_54 [ 3 ] ;
V_48 -> V_6 [ 0 ] -> V_46 [ 0 ] = ( V_52 -> V_67 >> 0 ) & 1 ;
V_48 -> V_6 [ 0 ] -> V_46 [ 1 ] = ( V_52 -> V_67 >> 1 ) & 1 ;
F_19 ( V_2 , V_48 , V_35 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = & V_2 -> V_41 ;
struct V_51 * V_52 ;
T_2 V_71 = strlen ( F_35 ( V_41 ) ) + 16 ;
char * V_72 , * V_73 ;
int V_74 ;
int V_32 ;
if ( ! F_10 ( V_2 ) )
return 0 ;
F_2 ( V_2 , NULL ) ;
for ( V_74 = 0 ; V_74 < 4 ; V_74 ++ ) {
if ( ! F_36 ( V_2 , V_34 , 4 , V_74 , 1 ) )
return - V_75 ;
}
if ( ! F_36 ( V_2 , V_70 , 3 , 0 , 2 ) )
return - V_75 ;
V_32 = F_37 ( & V_2 -> V_41 . V_76 , & V_77 ) ;
if ( V_32 )
F_38 ( V_2 , L_3 , V_32 ) ;
V_52 = F_39 ( & V_2 -> V_41 ,
sizeof( struct V_51 ) ,
V_78 ) ;
if ( V_52 == NULL ) {
F_11 ( V_2 , L_4 ) ;
return - V_79 ;
}
V_52 -> V_59 = 0xa0 ;
V_52 -> V_60 = 0x38 ;
V_72 = F_39 ( & V_2 -> V_41 , V_71 , V_78 ) ;
V_73 = F_39 ( & V_2 -> V_41 , V_71 , V_78 ) ;
if ( V_72 == NULL || V_73 == NULL ) {
F_11 ( V_2 , L_5 ) ;
return - V_79 ;
}
snprintf ( V_72 , V_71 , L_6 , F_35 ( V_41 ) ) ;
snprintf ( V_73 , V_71 , L_7 , F_35 ( V_41 ) ) ;
F_2 ( V_2 , V_52 ) ;
V_52 -> V_80 . V_81 = V_72 ;
V_52 -> V_80 . V_82 = F_32 ;
V_52 -> V_80 . V_83 = F_33 ;
V_52 -> V_80 . V_41 = V_41 ;
F_40 ( V_41 , & V_52 -> V_80 ) ;
V_52 -> V_66 . V_81 = V_73 ;
V_52 -> V_66 . V_82 =
F_32 ;
V_52 -> V_66 . V_83 =
F_33 ;
V_52 -> V_66 . V_41 = V_41 ;
F_40 ( V_41 , & V_52 -> V_66 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_32 ;
struct V_37 * V_38 ;
if ( V_2 -> V_26 == V_28
&& V_2 -> type != V_84 ) {
F_42 ( V_2 , L_8 ) ;
return 0 ;
}
V_38 = F_39 ( & V_2 -> V_41 ,
sizeof( * V_38 ) ,
V_78 ) ;
if ( V_38 == NULL ) {
F_11 ( V_2 , L_9 ) ;
return - V_79 ;
}
F_2 ( V_2 , V_38 ) ;
V_32 = F_6 ( V_2 , 0x01 , 0x03 ) ;
if ( V_32 )
F_38 ( V_2 , L_10 , V_32 ) ;
V_38 -> V_39 = true ;
F_9 ( V_2 ) ;
V_32 = F_37 ( & V_2 -> V_41 . V_76 , & V_85 ) ;
if ( V_32 )
F_38 ( V_2 , L_3 , V_32 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
const struct V_86 * V_87 )
{
int V_32 ;
V_32 = F_44 ( V_2 ) ;
if ( V_32 ) {
F_11 ( V_2 , L_11 ) ;
goto V_88;
}
V_32 = F_45 ( V_2 , V_89 ) ;
if ( V_32 ) {
F_11 ( V_2 , L_12 ) ;
goto V_88;
}
switch ( V_2 -> V_26 ) {
case V_27 :
V_32 = F_34 ( V_2 ) ;
break;
case V_28 :
case V_29 :
V_32 = F_41 ( V_2 ) ;
break;
default:
V_32 = 0 ;
break;
}
if ( V_32 )
goto V_90;
return 0 ;
V_90:
F_46 ( V_2 ) ;
V_88:
return V_32 ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_51 * V_52 = F_10 ( V_2 ) ;
if ( V_52 == NULL )
return;
F_48 ( & V_2 -> V_41 . V_76 ,
& V_77 ) ;
F_49 ( & V_52 -> V_66 ) ;
F_49 ( & V_52 -> V_80 ) ;
F_2 ( V_2 , NULL ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_48 ( & V_2 -> V_41 . V_76 ,
& V_85 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_26 ) {
case V_27 :
F_47 ( V_2 ) ;
break;
case V_28 :
case V_29 :
F_50 ( V_2 ) ;
break;
}
F_46 ( V_2 ) ;
}
