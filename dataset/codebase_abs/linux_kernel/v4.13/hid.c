static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 , V_4 , NULL ,
0 , & V_2 -> V_5 , sizeof( V_2 -> V_5 ) ) ;
}
static int F_3 ( struct V_1 * V_2 , char * V_6 )
{
int V_7 ;
V_7 = F_4 ( V_2 -> V_8 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_2 ( V_2 -> V_3 , V_9 ,
NULL , 0 , V_6 ,
F_5 ( V_2 -> V_5 . V_10 ) ) ;
F_6 ( V_2 -> V_8 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 , int type )
{
int V_7 ;
V_7 = F_4 ( V_2 -> V_8 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_2 ( V_2 -> V_3 , type , NULL , 0 , NULL , 0 ) ;
F_6 ( V_2 -> V_8 ) ;
return V_7 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_11 , T_1 V_12 ,
unsigned char * V_13 , int V_14 )
{
struct V_15 V_16 ;
int V_7 ;
V_7 = F_4 ( V_2 -> V_8 ) ;
if ( V_7 )
return V_7 ;
V_16 . V_11 = V_11 ;
V_16 . V_12 = V_12 ;
V_7 = F_2 ( V_2 -> V_3 , V_17 ,
& V_16 , sizeof( V_16 ) , V_13 , V_14 ) ;
F_6 ( V_2 -> V_8 ) ;
return V_7 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_11 , T_1 V_12 ,
unsigned char * V_13 , int V_14 )
{
struct V_18 * V_16 ;
struct V_19 * V_20 ;
int V_7 , V_21 = sizeof( * V_16 ) + V_14 - 1 ;
V_7 = F_4 ( V_2 -> V_8 ) ;
if ( V_7 )
return V_7 ;
V_20 = F_10 ( V_2 -> V_3 ,
V_22 , V_21 , 0 ,
V_23 ) ;
if ( ! V_20 ) {
F_6 ( V_2 -> V_8 ) ;
return - V_24 ;
}
V_16 = V_20 -> V_16 -> V_25 ;
V_16 -> V_11 = V_11 ;
V_16 -> V_12 = V_12 ;
memcpy ( V_16 -> V_26 , V_13 , V_14 ) ;
V_7 = F_11 ( V_20 ) ;
if ( V_7 ) {
F_12 ( & V_20 -> V_3 -> V_8 -> V_27 ,
L_1 , V_7 ) ;
} else {
V_7 = V_14 ;
}
F_13 ( V_20 ) ;
F_6 ( V_2 -> V_8 ) ;
return V_7 ;
}
static int F_14 ( struct V_19 * V_28 )
{
struct V_29 * V_3 = V_28 -> V_3 ;
struct V_1 * V_2 = F_15 ( V_3 ) ;
struct V_30 * V_16 = V_28 -> V_16 -> V_25 ;
if ( V_28 -> type != V_31 ) {
F_12 ( & V_3 -> V_8 -> V_27 ,
L_2 ) ;
return - V_32 ;
}
if ( F_16 ( V_33 , & V_2 -> V_34 ) )
F_17 ( V_2 -> V_35 , V_36 ,
V_16 -> V_26 , V_28 -> V_16 -> V_37 , 1 ) ;
return 0 ;
}
static int F_18 ( struct V_38 * V_26 )
{
return ( ( V_26 -> V_21 - 1 ) >> 3 ) + 1 +
V_26 -> V_39 -> V_40 [ V_26 -> type ] . V_41 ;
}
static void F_19 ( struct V_42 * V_35 , unsigned int type ,
unsigned int * V_43 )
{
struct V_38 * V_26 ;
unsigned int V_21 ;
F_20 (report, &hid->report_enum[type].report_list, list) {
V_21 = F_18 ( V_26 ) ;
if ( * V_43 < V_21 )
* V_43 = V_21 ;
}
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_44 ) ;
V_2 -> V_44 = NULL ;
V_2 -> V_45 = 0 ;
}
static int F_23 ( struct V_1 * V_2 , T_2 V_45 )
{
V_2 -> V_44 = F_24 ( V_45 , V_23 ) ;
if ( ! V_2 -> V_44 )
return - V_24 ;
V_2 -> V_45 = V_45 ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 , struct V_38 * V_26 )
{
unsigned int V_21 ;
V_21 = F_18 ( V_26 ) ;
if ( F_8 ( V_2 , V_26 -> type , V_26 -> V_46 , V_2 -> V_44 ,
V_21 ) )
return;
F_26 ( V_2 -> V_35 , V_26 -> type , V_2 -> V_44 , V_21 , 1 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_42 * V_35 = V_2 -> V_35 ;
struct V_38 * V_26 ;
F_20 (report,
&hid->report_enum[HID_INPUT_REPORT].report_list, list)
F_25 ( V_2 , V_26 ) ;
F_20 (report,
&hid->report_enum[HID_FEATURE_REPORT].report_list, list)
F_25 ( V_2 , V_26 ) ;
}
static int F_28 ( struct V_42 * V_35 ,
unsigned char V_47 , T_3 * V_13 , T_2 V_48 ,
unsigned char V_11 )
{
struct V_1 * V_2 = V_35 -> V_49 ;
int V_7 ;
if ( V_11 == V_50 )
return - V_32 ;
V_7 = F_8 ( V_2 , V_11 , V_47 , V_13 , V_48 ) ;
if ( ! V_7 )
V_7 = V_48 ;
return V_7 ;
}
static int F_29 ( struct V_42 * V_35 , T_3 * V_13 ,
T_2 V_14 , unsigned char V_11 )
{
struct V_1 * V_2 = V_35 -> V_49 ;
int V_12 = V_13 [ 0 ] ;
int V_7 ;
if ( V_11 == V_36 )
return - V_32 ;
if ( V_12 ) {
V_13 ++ ;
V_14 -- ;
}
V_7 = F_9 ( V_2 , V_11 , V_12 , V_13 , V_14 ) ;
if ( V_12 && V_7 >= 0 )
V_7 ++ ;
return 0 ;
}
static int F_30 ( struct V_42 * V_35 , unsigned char V_51 ,
T_3 * V_13 , T_2 V_14 , unsigned char V_52 ,
int V_53 )
{
switch ( V_53 ) {
case V_54 :
return F_28 ( V_35 , V_51 , V_13 , V_14 , V_52 ) ;
case V_55 :
if ( V_13 [ 0 ] != V_51 )
return - V_32 ;
return F_29 ( V_35 , V_13 , V_14 , V_52 ) ;
default:
return - V_56 ;
}
}
static int F_31 ( struct V_42 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_49 ;
unsigned int V_57 ;
char * V_6 ;
int V_7 ;
V_57 = F_5 ( V_2 -> V_5 . V_10 ) ;
if ( ! V_57 || V_57 > V_58 ) {
F_32 ( L_3 , V_57 ) ;
return - V_32 ;
}
V_6 = F_24 ( V_57 , V_23 ) ;
if ( ! V_6 ) {
F_32 ( L_4 ) ;
return - V_24 ;
}
V_7 = F_3 ( V_2 , V_6 ) ;
if ( V_7 ) {
F_33 ( V_35 , L_5 ) ;
goto V_59;
}
V_7 = F_34 ( V_35 , V_6 , V_57 ) ;
if ( V_7 )
F_32 ( L_6 ) ;
V_59:
F_22 ( V_6 ) ;
return V_7 ;
}
static int F_35 ( struct V_42 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_49 ;
unsigned int V_45 = V_60 ;
int V_7 ;
F_19 ( V_35 , V_36 , & V_45 ) ;
F_19 ( V_35 , V_50 , & V_45 ) ;
F_19 ( V_35 , V_61 , & V_45 ) ;
if ( V_45 > V_62 )
V_45 = V_62 ;
V_7 = F_23 ( V_2 , V_45 ) ;
if ( V_7 )
return V_7 ;
if ( ! ( V_35 -> V_63 & V_64 ) )
F_27 ( V_2 ) ;
return 0 ;
}
static void F_36 ( struct V_42 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_49 ;
F_21 ( V_2 ) ;
}
static int F_37 ( struct V_42 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_49 ;
int V_7 ;
V_7 = F_7 ( V_2 , V_65 ) ;
if ( V_7 < 0 )
return V_7 ;
F_38 ( V_33 , & V_2 -> V_34 ) ;
return 0 ;
}
static void F_39 ( struct V_42 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_49 ;
int V_7 ;
F_40 ( V_33 , & V_2 -> V_34 ) ;
V_7 = F_7 ( V_2 , V_66 ) ;
if ( V_7 )
F_12 ( & V_2 -> V_3 -> V_8 -> V_27 ,
L_7 , V_7 ) ;
}
static int F_41 ( struct V_42 * V_35 , int V_67 )
{
struct V_1 * V_2 = V_35 -> V_49 ;
switch ( V_67 ) {
case V_68 :
return F_7 ( V_2 , V_65 ) ;
case V_69 :
return F_7 ( V_2 , V_66 ) ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_42 * V_35 = V_2 -> V_35 ;
int V_7 ;
V_7 = F_1 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_35 -> V_70 = F_5 ( V_2 -> V_5 . V_71 ) ;
V_35 -> V_72 = F_5 ( V_2 -> V_5 . V_73 ) ;
V_35 -> V_74 = F_5 ( V_2 -> V_5 . V_75 ) ;
V_35 -> V_76 = V_2 -> V_5 . V_77 ;
V_35 -> V_49 = V_2 ;
V_35 -> V_78 = & V_79 ;
V_35 -> V_27 . V_80 = & V_2 -> V_3 -> V_8 -> V_27 ;
snprintf ( V_35 -> V_81 , sizeof( V_35 -> V_81 ) , L_8 ,
F_43 ( & V_2 -> V_3 -> V_8 -> V_27 ) ,
V_35 -> V_72 , V_35 -> V_74 ) ;
return 0 ;
}
static int F_44 ( struct V_82 * V_8 ,
const struct V_83 * V_46 )
{
struct V_84 * V_85 ;
struct V_29 * V_3 ;
struct V_42 * V_35 ;
struct V_1 * V_2 ;
int V_7 ;
if ( V_8 -> V_86 != 1 )
return - V_87 ;
V_85 = & V_8 -> V_85 [ 0 ] ;
if ( V_85 -> V_88 != V_89 )
return - V_87 ;
V_2 = F_24 ( sizeof( * V_2 ) , V_23 ) ;
if ( ! V_2 )
return - V_24 ;
V_3 = F_45 ( V_8 , F_5 ( V_85 -> V_46 ) ,
F_14 ) ;
if ( F_46 ( V_3 ) ) {
V_7 = F_47 ( V_3 ) ;
goto V_90;
}
F_48 ( V_3 , V_2 ) ;
V_2 -> V_3 = V_3 ;
V_35 = F_49 () ;
if ( F_46 ( V_35 ) ) {
V_7 = F_47 ( V_35 ) ;
goto V_91;
}
V_2 -> V_35 = V_35 ;
V_2 -> V_8 = V_8 ;
F_50 ( V_8 , V_2 ) ;
V_7 = F_51 ( V_3 ) ;
if ( V_7 )
goto V_92;
V_7 = F_42 ( V_2 ) ;
if ( V_7 )
goto V_93;
V_7 = F_52 ( V_35 ) ;
if ( V_7 ) {
F_33 ( V_35 , L_9 , V_7 ) ;
goto V_93;
}
F_6 ( V_8 ) ;
return 0 ;
V_93:
F_53 ( V_3 ) ;
V_92:
F_54 ( V_35 ) ;
V_91:
F_55 ( V_3 ) ;
V_90:
F_22 ( V_2 ) ;
return V_7 ;
}
static void F_56 ( struct V_82 * V_8 )
{
struct V_1 * V_2 = F_57 ( V_8 ) ;
if ( F_4 ( V_8 ) )
F_58 ( V_8 ) ;
F_54 ( V_2 -> V_35 ) ;
F_53 ( V_2 -> V_3 ) ;
F_55 ( V_2 -> V_3 ) ;
F_22 ( V_2 ) ;
}
