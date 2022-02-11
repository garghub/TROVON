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
F_5 ( V_17 , V_4 -> V_18 -> V_19 ) ;
switch ( V_8 -> V_11 & V_20 ) {
case 0x00f1 :
F_3 ( V_13 ) ;
return 1 ;
case 0x00f2 :
F_3 ( V_21 ) ;
return 1 ;
case 0x00f3 :
F_3 ( V_22 ) ;
return 1 ;
case 0x00f4 :
F_3 ( V_23 ) ;
return 1 ;
case 0x00f5 :
F_3 ( V_24 ) ;
return 1 ;
case 0x00f6 :
F_3 ( V_25 ) ;
return 1 ;
case 0x00f8 :
F_3 ( V_26 ) ;
return 1 ;
case 0x00fa :
F_3 ( V_27 ) ;
return 1 ;
case 0x00fb :
F_3 ( V_28 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned long * * V_9 , int * V_10 )
{
switch ( V_2 -> V_29 ) {
case V_30 :
return F_1 ( V_2 , V_4 , V_6 ,
V_8 , V_9 , V_10 ) ;
case V_31 :
case V_32 :
return F_4 ( V_2 , V_4 , V_6 ,
V_8 , V_9 , V_10 ) ;
default:
return 0 ;
}
}
static int F_7 ( struct V_1 * V_2 ,
unsigned char V_33 , unsigned char V_34 )
{
int V_35 ;
unsigned char V_36 [] = { 0x18 , V_33 , V_34 } ;
switch ( V_2 -> V_29 ) {
case V_31 :
V_35 = F_8 ( V_2 , 0x13 , V_36 , sizeof( V_36 ) ,
V_37 , V_38 ) ;
break;
case V_32 :
V_35 = F_9 ( V_2 , V_36 , sizeof( V_36 ) ) ;
break;
default:
V_35 = - V_39 ;
break;
}
return V_35 < 0 ? V_35 : 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
int V_35 ;
struct V_40 * V_41 = F_11 ( V_2 ) ;
V_35 = F_7 ( V_2 , 0x05 , V_41 -> V_42 ) ;
if ( V_35 )
F_12 ( V_2 , L_1 , V_35 ) ;
}
static T_1 F_13 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
char * V_36 )
{
struct V_1 * V_2 = F_14 ( V_44 , struct V_1 , V_44 ) ;
struct V_40 * V_41 = F_11 ( V_2 ) ;
return snprintf ( V_36 , V_47 , L_2 , V_41 -> V_42 ) ;
}
static T_1 F_15 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_36 ,
T_2 V_48 )
{
struct V_1 * V_2 = F_14 ( V_44 , struct V_1 , V_44 ) ;
struct V_40 * V_41 = F_11 ( V_2 ) ;
int V_49 ;
if ( F_16 ( V_36 , 10 , & V_49 ) )
return - V_39 ;
if ( V_49 < 0 || V_49 > 1 )
return - V_39 ;
V_41 -> V_42 = ! ! V_49 ;
F_10 ( V_2 ) ;
return V_48 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_50 * V_51 , T_3 * V_52 , int V_53 )
{
if ( F_18 ( V_2 -> V_29 == V_31
&& V_53 == 3
&& V_52 [ 0 ] == 0x15
&& V_52 [ 1 ] == 0x94
&& V_52 [ 2 ] == 0x01 ) ) {
V_52 [ 1 ] = 0x0 ;
V_52 [ 2 ] = 0x4 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_50 * V_51 ;
struct V_54 * V_55 = F_11 ( V_2 ) ;
V_51 = V_2 -> V_56 [ V_37 ] . V_57 [ 4 ] ;
V_51 -> V_6 [ 0 ] -> V_49 [ 0 ] = V_55 -> V_58 ? 0x01 : 0x02 ;
V_51 -> V_6 [ 0 ] -> V_49 [ 0 ] |= V_55 -> V_59 ? 0x04 : 0x08 ;
V_51 -> V_6 [ 0 ] -> V_49 [ 0 ] |= V_55 -> V_60 ? 0x10 : 0x20 ;
V_51 -> V_6 [ 0 ] -> V_49 [ 0 ] |= V_55 -> V_61 ? 0x80 : 0x40 ;
V_51 -> V_6 [ 1 ] -> V_49 [ 0 ] = 0x03 ;
V_51 -> V_6 [ 2 ] -> V_49 [ 0 ] = V_55 -> V_62 ;
V_51 -> V_6 [ 3 ] -> V_49 [ 0 ] = V_55 -> V_63 ;
F_20 ( V_2 , V_51 , V_38 ) ;
return 0 ;
}
static T_1 F_21 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
char * V_36 )
{
struct V_1 * V_2 = F_14 ( V_44 , struct V_1 , V_44 ) ;
struct V_54 * V_55 = F_11 ( V_2 ) ;
return snprintf ( V_36 , V_47 , L_2 , V_55 -> V_58 ) ;
}
static T_1 F_22 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_36 ,
T_2 V_48 )
{
struct V_1 * V_2 = F_14 ( V_44 , struct V_1 , V_44 ) ;
struct V_54 * V_55 = F_11 ( V_2 ) ;
int V_49 ;
if ( F_16 ( V_36 , 10 , & V_49 ) )
return - V_39 ;
if ( V_49 < 0 || V_49 > 1 )
return - V_39 ;
V_55 -> V_58 = V_49 ;
F_19 ( V_2 ) ;
return V_48 ;
}
static T_1 F_23 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
char * V_36 )
{
struct V_1 * V_2 = F_14 ( V_44 , struct V_1 , V_44 ) ;
struct V_54 * V_55 = F_11 ( V_2 ) ;
return snprintf ( V_36 , V_47 , L_2 , V_55 -> V_59 ) ;
}
static T_1 F_24 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_36 ,
T_2 V_48 )
{
struct V_1 * V_2 = F_14 ( V_44 , struct V_1 , V_44 ) ;
struct V_54 * V_55 = F_11 ( V_2 ) ;
int V_49 ;
if ( F_16 ( V_36 , 10 , & V_49 ) )
return - V_39 ;
if ( V_49 < 0 || V_49 > 1 )
return - V_39 ;
V_55 -> V_59 = V_49 ;
F_19 ( V_2 ) ;
return V_48 ;
}
static T_1 F_25 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
char * V_36 )
{
struct V_1 * V_2 = F_14 ( V_44 , struct V_1 , V_44 ) ;
struct V_54 * V_55 = F_11 ( V_2 ) ;
return snprintf ( V_36 , V_47 , L_2 , V_55 -> V_60 ) ;
}
static T_1 F_26 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_36 ,
T_2 V_48 )
{
struct V_1 * V_2 = F_14 ( V_44 , struct V_1 , V_44 ) ;
struct V_54 * V_55 = F_11 ( V_2 ) ;
int V_49 ;
if ( F_16 ( V_36 , 10 , & V_49 ) )
return - V_39 ;
if ( V_49 < 0 || V_49 > 1 )
return - V_39 ;
V_55 -> V_60 = V_49 ;
F_19 ( V_2 ) ;
return V_48 ;
}
static T_1 F_27 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
char * V_36 )
{
struct V_1 * V_2 = F_14 ( V_44 , struct V_1 , V_44 ) ;
struct V_54 * V_55 = F_11 ( V_2 ) ;
return snprintf ( V_36 , V_47 , L_2 , V_55 -> V_61 ) ;
}
static T_1 F_28 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_36 ,
T_2 V_48 )
{
struct V_1 * V_2 = F_14 ( V_44 , struct V_1 , V_44 ) ;
struct V_54 * V_55 = F_11 ( V_2 ) ;
int V_49 ;
if ( F_16 ( V_36 , 10 , & V_49 ) )
return - V_39 ;
if ( V_49 < 0 || V_49 > 1 )
return - V_39 ;
V_55 -> V_61 = V_49 ;
F_19 ( V_2 ) ;
return V_48 ;
}
static T_1 F_29 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
char * V_36 )
{
struct V_1 * V_2 = F_14 ( V_44 , struct V_1 , V_44 ) ;
struct V_54 * V_55 = F_11 ( V_2 ) ;
return snprintf ( V_36 , V_47 , L_2 ,
V_55 -> V_62 ) ;
}
static T_1 F_30 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_36 ,
T_2 V_48 )
{
struct V_1 * V_2 = F_14 ( V_44 , struct V_1 , V_44 ) ;
struct V_54 * V_55 = F_11 ( V_2 ) ;
int V_49 ;
if ( F_16 ( V_36 , 10 , & V_49 ) || V_49 < 1 || V_49 > 255 )
return - V_39 ;
V_55 -> V_62 = V_49 ;
F_19 ( V_2 ) ;
return V_48 ;
}
static T_1 F_31 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
char * V_36 )
{
struct V_1 * V_2 = F_14 ( V_44 , struct V_1 , V_44 ) ;
struct V_54 * V_55 = F_11 ( V_2 ) ;
return snprintf ( V_36 , V_47 , L_2 ,
V_55 -> V_63 ) ;
}
static T_1 F_32 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
const char * V_36 ,
T_2 V_48 )
{
struct V_1 * V_2 = F_14 ( V_44 , struct V_1 , V_44 ) ;
struct V_54 * V_55 = F_11 ( V_2 ) ;
int V_49 ;
if ( F_16 ( V_36 , 10 , & V_49 ) || V_49 < 1 || V_49 > 255 )
return - V_39 ;
V_55 -> V_63 = V_49 ;
F_19 ( V_2 ) ;
return V_48 ;
}
static enum V_64 F_33 (
struct V_65 * V_66 )
{
struct V_43 * V_44 = V_66 -> V_44 -> V_67 ;
struct V_1 * V_2 = F_14 ( V_44 , struct V_1 , V_44 ) ;
struct V_54 * V_55 = F_11 ( V_2 ) ;
int V_68 = 0 ;
if ( V_66 == & V_55 -> V_69 )
V_68 = 1 ;
return V_55 -> V_70 & ( 1 << V_68 )
? V_71
: V_72 ;
}
static void F_34 ( struct V_65 * V_66 ,
enum V_64 V_49 )
{
struct V_43 * V_44 = V_66 -> V_44 -> V_67 ;
struct V_1 * V_2 = F_14 ( V_44 , struct V_1 , V_44 ) ;
struct V_54 * V_55 = F_11 ( V_2 ) ;
struct V_50 * V_51 ;
int V_68 = 0 ;
if ( V_66 == & V_55 -> V_69 )
V_68 = 1 ;
if ( V_49 == V_72 )
V_55 -> V_70 &= ~ ( 1 << V_68 ) ;
else
V_55 -> V_70 |= 1 << V_68 ;
V_51 = V_2 -> V_56 [ V_73 ] . V_57 [ 3 ] ;
V_51 -> V_6 [ 0 ] -> V_49 [ 0 ] = ( V_55 -> V_70 >> 0 ) & 1 ;
V_51 -> V_6 [ 0 ] -> V_49 [ 1 ] = ( V_55 -> V_70 >> 1 ) & 1 ;
F_20 ( V_2 , V_51 , V_38 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = & V_2 -> V_44 ;
struct V_54 * V_55 ;
T_2 V_74 = strlen ( F_36 ( V_44 ) ) + 16 ;
char * V_75 , * V_76 ;
int V_77 ;
int V_35 ;
if ( ! F_11 ( V_2 ) )
return 0 ;
F_2 ( V_2 , NULL ) ;
for ( V_77 = 0 ; V_77 < 4 ; V_77 ++ ) {
if ( ! F_37 ( V_2 , V_37 , 4 , V_77 , 1 ) )
return - V_78 ;
}
if ( ! F_37 ( V_2 , V_73 , 3 , 0 , 2 ) )
return - V_78 ;
V_35 = F_38 ( & V_2 -> V_44 . V_79 , & V_80 ) ;
if ( V_35 )
F_39 ( V_2 , L_3 , V_35 ) ;
V_55 = F_40 ( & V_2 -> V_44 ,
sizeof( struct V_54 ) ,
V_81 ) ;
if ( V_55 == NULL ) {
F_12 ( V_2 , L_4 ) ;
return - V_82 ;
}
V_55 -> V_62 = 0xa0 ;
V_55 -> V_63 = 0x38 ;
V_75 = F_40 ( & V_2 -> V_44 , V_74 , V_81 ) ;
V_76 = F_40 ( & V_2 -> V_44 , V_74 , V_81 ) ;
if ( V_75 == NULL || V_76 == NULL ) {
F_12 ( V_2 , L_5 ) ;
return - V_82 ;
}
snprintf ( V_75 , V_74 , L_6 , F_36 ( V_44 ) ) ;
snprintf ( V_76 , V_74 , L_7 , F_36 ( V_44 ) ) ;
F_2 ( V_2 , V_55 ) ;
V_55 -> V_83 . V_84 = V_75 ;
V_55 -> V_83 . V_85 = F_33 ;
V_55 -> V_83 . V_86 = F_34 ;
V_55 -> V_83 . V_44 = V_44 ;
F_41 ( V_44 , & V_55 -> V_83 ) ;
V_55 -> V_69 . V_84 = V_76 ;
V_55 -> V_69 . V_85 =
F_33 ;
V_55 -> V_69 . V_86 =
F_34 ;
V_55 -> V_69 . V_44 = V_44 ;
F_41 ( V_44 , & V_55 -> V_69 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_35 ;
struct V_40 * V_41 ;
if ( V_2 -> V_29 == V_31
&& V_2 -> type != V_87 ) {
F_43 ( V_2 , L_8 ) ;
return 0 ;
}
V_41 = F_40 ( & V_2 -> V_44 ,
sizeof( * V_41 ) ,
V_81 ) ;
if ( V_41 == NULL ) {
F_12 ( V_2 , L_9 ) ;
return - V_82 ;
}
F_2 ( V_2 , V_41 ) ;
V_35 = F_7 ( V_2 , 0x01 , 0x03 ) ;
if ( V_35 )
F_39 ( V_2 , L_10 , V_35 ) ;
V_41 -> V_42 = true ;
F_10 ( V_2 ) ;
V_35 = F_38 ( & V_2 -> V_44 . V_79 , & V_88 ) ;
if ( V_35 )
F_39 ( V_2 , L_3 , V_35 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
const struct V_89 * V_90 )
{
int V_35 ;
V_35 = F_45 ( V_2 ) ;
if ( V_35 ) {
F_12 ( V_2 , L_11 ) ;
goto V_91;
}
V_35 = F_46 ( V_2 , V_92 ) ;
if ( V_35 ) {
F_12 ( V_2 , L_12 ) ;
goto V_91;
}
switch ( V_2 -> V_29 ) {
case V_30 :
V_35 = F_35 ( V_2 ) ;
break;
case V_31 :
case V_32 :
V_35 = F_42 ( V_2 ) ;
break;
default:
V_35 = 0 ;
break;
}
if ( V_35 )
goto V_93;
return 0 ;
V_93:
F_47 ( V_2 ) ;
V_91:
return V_35 ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = F_11 ( V_2 ) ;
if ( V_55 == NULL )
return;
F_49 ( & V_2 -> V_44 . V_79 ,
& V_80 ) ;
F_50 ( & V_55 -> V_69 ) ;
F_50 ( & V_55 -> V_83 ) ;
F_2 ( V_2 , NULL ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_49 ( & V_2 -> V_44 . V_79 ,
& V_88 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_29 ) {
case V_30 :
F_48 ( V_2 ) ;
break;
case V_31 :
case V_32 :
F_51 ( V_2 ) ;
break;
}
F_47 ( V_2 ) ;
}
