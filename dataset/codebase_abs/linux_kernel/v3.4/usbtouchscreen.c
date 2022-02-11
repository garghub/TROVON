static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
V_3 = F_3 ( V_5 , F_4 ( V_5 , 0 ) ,
0x01 , 0x02 , 0x0000 , 0x0081 ,
NULL , 0 , V_7 ) ;
F_5 ( L_1 ,
V_8 , V_3 ) ;
return V_3 ;
}
static int F_6 ( struct V_1 * V_9 , unsigned char * V_10 )
{
int V_11 = ( V_10 [ 0 ] << 8 ) | V_10 [ 1 ] ;
V_9 -> V_12 = ( V_10 [ 2 ] << 8 ) | V_10 [ 3 ] ;
V_9 -> V_13 = ( V_10 [ 4 ] << 8 ) | V_10 [ 5 ] ;
V_11 = V_11 - 0xA000 ;
V_9 -> V_14 = ( V_11 > 0 ) ;
V_9 -> V_15 = ( V_11 > 0 ? V_11 : 0 ) ;
return 1 ;
}
static int F_7 ( struct V_1 * V_9 , unsigned char * V_10 )
{
if ( ( V_10 [ 0 ] & V_16 ) != V_17 )
return 0 ;
V_9 -> V_12 = ( ( V_10 [ 3 ] & 0x0F ) << 7 ) | ( V_10 [ 4 ] & 0x7F ) ;
V_9 -> V_13 = ( ( V_10 [ 1 ] & 0x0F ) << 7 ) | ( V_10 [ 2 ] & 0x7F ) ;
V_9 -> V_14 = V_10 [ 0 ] & 0x01 ;
return 1 ;
}
static int F_8 ( unsigned char * V_18 , int V_19 )
{
switch ( V_18 [ 0 ] & V_16 ) {
case V_17 :
return 5 ;
case V_20 :
if ( V_19 < 2 )
return - 1 ;
return V_18 [ 1 ] + 2 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_9 , unsigned char * V_10 )
{
if ( ( V_10 [ 0 ] & V_21 ) != V_22 &&
( V_10 [ 0 ] & V_21 ) != V_23 )
return 0 ;
V_9 -> V_12 = ( ( V_10 [ 1 ] & 0x1F ) << 7 ) | ( V_10 [ 2 ] & 0x7F ) ;
V_9 -> V_13 = ( ( V_10 [ 3 ] & 0x1F ) << 7 ) | ( V_10 [ 4 ] & 0x7F ) ;
V_9 -> V_14 = V_10 [ 0 ] & 0x01 ;
return 1 ;
}
static int F_10 ( unsigned char * V_18 , int V_19 )
{
switch ( V_18 [ 0 ] & V_21 ) {
case V_22 :
case V_23 :
return 5 ;
case V_24 :
if ( V_19 < 2 )
return - 1 ;
return V_18 [ 1 ] + 2 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_9 , unsigned char * V_10 )
{
V_9 -> V_12 = ( ( V_10 [ 2 ] & 0x0F ) << 8 ) | V_10 [ 1 ] ;
V_9 -> V_13 = ( ( V_10 [ 4 ] & 0x0F ) << 8 ) | V_10 [ 3 ] ;
V_9 -> V_14 = V_10 [ 0 ] & 0x01 ;
return 1 ;
}
static int F_12 ( struct V_1 * V_9 , unsigned char * V_10 )
{
if ( V_25 ) {
V_9 -> V_12 = ( V_10 [ 4 ] << 8 ) | V_10 [ 3 ] ;
V_9 -> V_13 = 0xffff - ( ( V_10 [ 6 ] << 8 ) | V_10 [ 5 ] ) ;
} else {
V_9 -> V_12 = ( V_10 [ 8 ] << 8 ) | V_10 [ 7 ] ;
V_9 -> V_13 = ( V_10 [ 10 ] << 8 ) | V_10 [ 9 ] ;
}
V_9 -> V_14 = ( V_10 [ 2 ] & 0x40 ) ? 1 : 0 ;
return 1 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_3 , V_26 ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
V_3 = F_3 ( V_5 , F_4 ( V_5 , 0 ) ,
V_27 ,
V_28 | V_29 | V_30 ,
1 , 0 , NULL , 0 , V_7 ) ;
F_5 ( L_2 ,
V_8 , V_3 ) ;
if ( V_3 < 0 )
return V_3 ;
F_14 ( 150 ) ;
for ( V_26 = 0 ; V_26 < 3 ; V_26 ++ ) {
V_3 = F_3 ( V_5 , F_4 ( V_5 , 0 ) ,
V_31 ,
V_28 | V_29 | V_30 ,
1 , 1 , NULL , 0 , V_7 ) ;
F_5 ( L_3 ,
V_8 , V_3 ) ;
if ( V_3 >= 0 )
break;
if ( V_3 != - V_32 )
return V_3 ;
}
if ( V_25 ) {
F_15 ( V_2 -> V_33 , V_34 , 0 , 0xffff , 0 , 0 ) ;
F_15 ( V_2 -> V_33 , V_35 , 0 , 0xffff , 0 , 0 ) ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_9 , unsigned char * V_10 )
{
int V_14 ;
V_9 -> V_15 = ( ( V_10 [ 2 ] & 0x01 ) << 7 ) | ( V_10 [ 5 ] & 0x7F ) ;
V_14 = ~ V_10 [ 7 ] & 0x20 ;
if ( ! V_14 ) {
if ( V_9 -> V_14 ) {
V_9 -> V_14 = 0 ;
return 1 ;
}
return 0 ;
}
V_9 -> V_12 = ( ( V_10 [ 0 ] & 0x1F ) << 7 ) | ( V_10 [ 3 ] & 0x7F ) ;
V_9 -> V_13 = ( ( V_10 [ 1 ] & 0x1F ) << 7 ) | ( V_10 [ 4 ] & 0x7F ) ;
V_9 -> V_14 = V_14 ;
return 1 ;
}
static int F_17 ( struct V_1 * V_9 , unsigned char * V_10 )
{
unsigned int V_36 ;
if ( ! ( V_10 [ 0 ] & 0x80 ) )
return 0 ;
V_36 = ( 6 - ( V_10 [ 0 ] & 0x03 ) ) ;
V_9 -> V_12 = ( ( V_10 [ 3 ] << 7 ) | V_10 [ 4 ] ) >> V_36 ;
V_9 -> V_13 = ( ( V_10 [ 1 ] << 7 ) | V_10 [ 2 ] ) >> V_36 ;
V_9 -> V_14 = ( V_10 [ 0 ] & 0x10 ) ? 1 : 0 ;
return 1 ;
}
static int F_18 ( unsigned char * V_18 , int V_19 )
{
if ( V_18 [ 0 ] & 0x80 )
return 5 ;
if ( V_18 [ 0 ] == 0x01 )
return 3 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_9 , unsigned char * V_10 )
{
if ( ! ( V_10 [ 0 ] & 0x80 ) || ( ( V_10 [ 1 ] | V_10 [ 2 ] | V_10 [ 3 ] ) & 0x80 ) )
return 0 ;
V_9 -> V_12 = ( ( V_10 [ 0 ] & 0x1F ) << 7 ) | ( V_10 [ 2 ] & 0x7F ) ;
V_9 -> V_13 = ( ( V_10 [ 1 ] & 0x1F ) << 7 ) | ( V_10 [ 3 ] & 0x7F ) ;
V_9 -> V_14 = V_10 [ 0 ] & 0x20 ;
return 1 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_4 * V_9 = F_2 ( V_2 -> V_6 ) ;
int V_3 = - V_37 ;
unsigned char * V_18 ;
V_18 = F_21 ( 2 , V_38 ) ;
if ( ! V_18 )
goto V_39;
V_18 [ 0 ] = V_18 [ 1 ] = 0xFF ;
V_3 = F_3 ( V_9 , F_4 ( V_9 , 0 ) ,
V_40 ,
V_41 | V_29 | V_30 ,
0 , 0 , V_18 , 2 , V_7 ) ;
if ( V_3 < 0 )
goto V_42;
if ( V_18 [ 0 ] != 0x06 ) {
V_3 = - V_43 ;
goto V_42;
}
V_18 [ 0 ] = V_18 [ 1 ] = 0xFF ;
V_3 = F_3 ( V_9 , F_4 ( V_9 , 0 ) ,
V_44 ,
V_41 | V_29 | V_30 ,
V_45 , 0 , V_18 , 2 , V_7 ) ;
if ( V_3 < 0 )
goto V_42;
if ( ( V_18 [ 0 ] != 0x06 ) && ( V_18 [ 0 ] != 0x15 || V_18 [ 1 ] != 0x01 ) ) {
V_3 = - V_43 ;
goto V_42;
}
V_3 = F_3 ( V_9 , F_4 ( V_9 , 0 ) ,
V_46 ,
V_28 | V_29 | V_30 ,
0 , 0 , NULL , 0 , V_7 ) ;
V_42:
F_22 ( V_18 ) ;
V_39:
return V_3 ;
}
static int F_23 ( struct V_1 * V_9 , unsigned char * V_10 )
{
V_9 -> V_12 = ( ( V_10 [ 2 ] & 0x03 ) << 8 ) | V_10 [ 1 ] ;
V_9 -> V_13 = ( ( V_10 [ 4 ] & 0x03 ) << 8 ) | V_10 [ 3 ] ;
V_9 -> V_14 = V_10 [ 0 ] & 0x01 ;
return 1 ;
}
static int F_24 ( struct V_1 * V_9 , unsigned char * V_10 )
{
V_9 -> V_12 = ( V_10 [ 3 ] << 8 ) | V_10 [ 2 ] ;
V_9 -> V_13 = ( V_10 [ 5 ] << 8 ) | V_10 [ 4 ] ;
V_9 -> V_14 = ( V_10 [ 1 ] & 0x03 ) ? 1 : 0 ;
return 1 ;
}
static int F_25 ( struct V_1 * V_9 , unsigned char * V_10 )
{
V_9 -> V_12 = ( ( V_10 [ 2 ] & 0x0F ) << 8 ) | V_10 [ 1 ] ;
V_9 -> V_13 = ( ( V_10 [ 4 ] & 0x0F ) << 8 ) | V_10 [ 3 ] ;
V_9 -> V_14 = V_10 [ 0 ] & 0x01 ;
return 1 ;
}
static int F_26 ( unsigned char * V_18 , int V_19 )
{
if ( V_18 [ 0 ] & 0x80 )
return 5 ;
if ( V_18 [ 0 ] == 0x01 )
return V_19 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_9 , unsigned char * V_10 )
{
switch ( V_10 [ 0 ] & 0x98 ) {
case 0x88 :
V_9 -> V_12 = ( V_10 [ 1 ] << 5 ) | ( V_10 [ 2 ] >> 2 ) ;
V_9 -> V_13 = ( V_10 [ 3 ] << 5 ) | ( V_10 [ 4 ] >> 2 ) ;
V_9 -> V_14 = ( V_10 [ 0 ] & 0x40 ) ? 1 : 0 ;
return 1 ;
case 0x98 :
V_9 -> V_12 = ( V_10 [ 2 ] << 5 ) | ( V_10 [ 1 ] >> 2 ) ;
V_9 -> V_13 = ( V_10 [ 4 ] << 5 ) | ( V_10 [ 3 ] >> 2 ) ;
V_9 -> V_14 = ( V_10 [ 0 ] & 0x40 ) ? 1 : 0 ;
return 1 ;
default:
return 0 ;
}
}
static int F_28 ( struct V_1 * V_9 , unsigned char * V_10 )
{
V_9 -> V_12 = ( V_10 [ 2 ] << 8 ) | V_10 [ 1 ] ;
V_9 -> V_13 = ( V_10 [ 4 ] << 8 ) | V_10 [ 3 ] ;
V_9 -> V_15 = V_10 [ 5 ] & 0xff ;
V_9 -> V_14 = V_10 [ 0 ] & 0x01 ;
return 1 ;
}
static int F_29 ( struct V_1 * V_9 , unsigned char * V_10 )
{
V_9 -> V_12 = ( ( V_10 [ 1 ] & 0x38 ) << 4 ) | V_10 [ 2 ] ;
V_9 -> V_13 = ( ( V_10 [ 1 ] & 0x07 ) << 7 ) | V_10 [ 3 ] ;
V_9 -> V_14 = V_10 [ 0 ] & 0x01 ;
return 1 ;
}
static int F_30 ( struct V_1 * V_9 , unsigned char * V_10 )
{
V_9 -> V_12 = ( ( V_10 [ 0 ] & 0x3f ) << 6 ) | ( V_10 [ 2 ] & 0x3f ) ;
V_9 -> V_13 = ( ( V_10 [ 1 ] & 0x3f ) << 6 ) | ( V_10 [ 3 ] & 0x3f ) ;
V_9 -> V_14 = ( V_10 [ 0 ] & 0x40 ) >> 6 ;
return 1 ;
}
static int F_31 ( struct V_1 * V_9 , unsigned char * V_10 )
{
switch ( V_10 [ 0 ] ) {
case 0x3A :
F_5 ( L_4 , V_8 , V_10 [ 1 ] ) ;
break;
case 0xC0 :
V_9 -> V_12 = ( V_10 [ 1 ] & 0x7f ) | ( ( V_10 [ 2 ] & 0x07 ) << 7 ) ;
V_9 -> V_13 = ( V_10 [ 3 ] & 0x7f ) | ( ( V_10 [ 4 ] & 0x07 ) << 7 ) ;
V_9 -> V_14 = 1 ;
F_5 ( L_5 , V_8 , V_9 -> V_12 , V_9 -> V_13 ) ;
return 1 ;
case 0x80 :
V_9 -> V_12 = ( V_10 [ 1 ] & 0x7f ) | ( ( V_10 [ 2 ] & 0x07 ) << 7 ) ;
V_9 -> V_13 = ( V_10 [ 3 ] & 0x7f ) | ( ( V_10 [ 4 ] & 0x07 ) << 7 ) ;
V_9 -> V_14 = 0 ;
F_5 ( L_6 , V_8 , V_9 -> V_12 , V_9 -> V_13 ) ;
return 1 ;
default:
F_5 ( L_7 , V_8 , V_10 [ 0 ] ) ;
break;
}
return 0 ;
}
static void F_32 ( struct V_47 * V_47 )
{
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_48 * V_49 ;
int V_3 = - V_37 ;
V_2 -> V_49 = F_21 ( sizeof( struct V_48 ) , V_50 ) ;
if ( ! V_2 -> V_49 )
goto V_51;
V_49 = V_2 -> V_49 ;
V_49 -> V_52 = F_34 ( V_53 , sizeof( V_53 ) ,
V_50 ) ;
if ( ! V_49 -> V_52 )
goto V_54;
V_49 -> V_55 = F_35 ( 0 , V_50 ) ;
if ( ! V_49 -> V_55 ) {
F_5 ( L_8 , V_8 ) ;
goto V_56;
}
return 0 ;
V_56:
F_22 ( V_49 -> V_52 ) ;
V_54:
F_22 ( V_49 ) ;
V_51:
return V_3 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_4 * V_9 = F_2 ( V_2 -> V_6 ) ;
struct V_57 * V_6 = V_2 -> V_6 -> V_58 ;
struct V_48 * V_49 = V_2 -> V_49 ;
int V_3 = - V_37 ;
int V_59 , V_26 ;
unsigned char * V_18 ;
char * V_60 = NULL , * V_61 = NULL ;
int V_62 = 0 , V_63 = 0 ;
for ( V_26 = 0 ; V_26 < V_6 -> V_64 . V_65 ; V_26 ++ ) {
if ( ! V_62 &&
F_37 ( & V_6 -> V_66 [ V_26 ] . V_64 ) )
V_62 = V_6 -> V_66 [ V_26 ] . V_64 . V_67 ;
if ( ! V_63 &&
F_38 ( & V_6 -> V_66 [ V_26 ] . V_64 ) )
V_63 = V_6 -> V_66 [ V_26 ] . V_64 . V_67 ;
}
if ( ! V_62 || ! V_63 )
return - V_68 ;
V_18 = F_21 ( V_69 , V_38 ) ;
if ( ! V_18 )
goto V_51;
for ( V_26 = 0 ; V_26 < 2 ; V_26 ++ ) {
V_3 = F_39 ( V_9 , F_40 ( V_9 , V_62 ) ,
V_18 , V_69 , & V_59 ,
V_70 ) ;
if ( V_3 < 0 )
goto V_51;
}
memcpy ( V_18 , V_71 , sizeof( V_71 ) ) ;
V_3 = F_39 ( V_9 , F_41 ( V_9 , V_63 ) ,
V_18 , sizeof( V_71 ) , & V_59 ,
V_70 ) ;
if ( V_3 < 0 )
goto V_51;
for ( V_26 = 0 ; V_26 < 3 ; V_26 ++ ) {
memset ( V_18 , 0 , V_69 ) ;
V_3 = F_39 ( V_9 , F_40 ( V_9 , V_62 ) ,
V_18 , V_69 , & V_59 ,
V_70 ) ;
if ( V_3 < 0 || V_59 < 1 || V_18 [ 1 ] != V_59 )
continue;
switch ( V_18 [ 0 ] ) {
case 0x83 :
if ( ! V_60 )
V_60 = F_42 ( & V_18 [ 2 ] , V_38 ) ;
break;
case 0x84 :
if ( ! V_61 )
V_61 = F_42 ( & V_18 [ 2 ] , V_38 ) ;
break;
}
}
F_43 ( V_72 L_9 ,
V_61 , V_60 ) ;
F_22 ( V_60 ) ;
F_22 ( V_61 ) ;
F_44 ( V_49 -> V_55 , V_9 , F_41 ( V_9 , V_63 ) ,
V_49 -> V_52 , sizeof( V_53 ) ,
F_32 , V_2 ) ;
V_3 = 0 ;
V_51:
F_22 ( V_18 ) ;
return V_3 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = V_2 -> V_49 ;
F_46 ( V_49 -> V_55 ) ;
F_47 ( V_49 -> V_55 ) ;
F_22 ( V_49 -> V_52 ) ;
F_22 ( V_49 ) ;
}
static int F_48 ( struct V_1 * V_2 , unsigned char * V_10 )
{
struct V_73 * V_74 = ( void * ) V_10 ;
struct V_48 * V_49 = V_2 -> V_49 ;
unsigned int V_75 = F_49 ( V_74 -> V_75 ) ;
unsigned int V_76 = F_49 ( V_74 -> V_76 ) ;
unsigned int V_77 = F_49 ( V_74 -> V_77 ) ;
int V_12 , V_13 , V_78 , V_79 , V_80 , V_81 , V_82 , V_83 , V_3 ;
if ( ( V_10 [ 0 ] & 0xe0 ) != 0xe0 )
return 0 ;
if ( V_75 > 0xff )
V_75 -= 0x100 ;
if ( V_76 > 0xff )
V_76 -= 0x80 ;
V_3 = F_50 ( V_49 -> V_55 , V_84 ) ;
if ( ! V_2 -> type -> V_85 ) {
V_2 -> type -> V_85 = 2 * V_76 ;
F_15 ( V_2 -> V_33 , V_34 ,
0 , V_2 -> type -> V_85 , 0 , 0 ) ;
V_2 -> type -> V_86 = 2 * V_77 ;
F_15 ( V_2 -> V_33 , V_35 ,
0 , V_2 -> type -> V_86 , 0 , 0 ) ;
}
V_78 = V_80 = V_79 = V_81 = - 1 ;
for ( V_12 = 0 ; V_12 < V_76 ; V_12 ++ ) {
if ( V_78 == - 1 && V_74 -> V_87 [ V_12 ] > V_88 ) {
V_78 = V_12 ;
continue;
}
if ( V_80 == - 1 && V_78 != - 1 && V_74 -> V_87 [ V_12 ] < V_88 ) {
V_80 = V_12 - 1 ;
for ( V_13 = V_76 ; V_13 < V_75 ; V_13 ++ ) {
if ( V_79 == - 1 && V_74 -> V_87 [ V_13 ] > V_88 ) {
V_79 = V_13 - V_76 ;
continue;
}
if ( V_81 == - 1 &&
V_79 != - 1 && V_74 -> V_87 [ V_13 ] < V_88 ) {
V_81 = V_13 - 1 - V_76 ;
V_82 = V_80 - V_78 ;
V_83 = V_81 - V_79 ;
#if 0
input_report_abs(usbtouch->input,
ABS_MT_TOUCH_MAJOR, max(w,h));
input_report_abs(usbtouch->input,
ABS_MT_TOUCH_MINOR, min(x,h));
input_report_abs(usbtouch->input,
ABS_MT_POSITION_X, 2*begin_x+w);
input_report_abs(usbtouch->input,
ABS_MT_POSITION_Y, 2*begin_y+h);
input_report_abs(usbtouch->input,
ABS_MT_ORIENTATION, w > h);
input_mt_sync(usbtouch->input);
#endif
V_2 -> V_12 = 2 * V_78 + V_82 ;
V_2 -> V_13 = 2 * V_79 + V_83 ;
V_2 -> V_14 = V_74 -> V_89 & 0x01 ;
V_79 = V_81 = - 1 ;
return 1 ;
}
}
V_78 = V_80 = - 1 ;
}
}
return 0 ;
}
static int F_51 ( struct V_1 * V_9 , unsigned char * V_10 )
{
V_9 -> V_12 = ( V_10 [ 3 ] << 8 ) | V_10 [ 2 ] ;
V_9 -> V_13 = ( V_10 [ 5 ] << 8 ) | V_10 [ 4 ] ;
V_9 -> V_14 = V_10 [ 6 ] > 0 ;
V_9 -> V_15 = V_10 [ 6 ] ;
return 1 ;
}
static void F_52 ( struct V_1 * V_2 ,
unsigned char * V_10 , int V_19 )
{
struct V_90 * type = V_2 -> type ;
if ( ! type -> V_91 ( V_2 , V_10 ) )
return;
F_53 ( V_2 -> V_33 , V_92 , V_2 -> V_14 ) ;
if ( V_93 ) {
F_54 ( V_2 -> V_33 , V_34 , V_2 -> V_13 ) ;
F_54 ( V_2 -> V_33 , V_35 , V_2 -> V_12 ) ;
} else {
F_54 ( V_2 -> V_33 , V_34 , V_2 -> V_12 ) ;
F_54 ( V_2 -> V_33 , V_35 , V_2 -> V_13 ) ;
}
if ( type -> V_94 )
F_54 ( V_2 -> V_33 , V_95 , V_2 -> V_15 ) ;
F_55 ( V_2 -> V_33 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
unsigned char * V_10 , int V_19 )
{
unsigned char * V_96 ;
int V_97 , V_98 , V_99 , V_11 ;
if ( F_57 ( V_2 -> V_99 ) ) {
V_97 = V_2 -> type -> V_100 (
V_2 -> V_96 , V_2 -> V_99 ) ;
if ( F_57 ( ! V_97 ) )
goto V_101;
if ( F_57 ( V_97 < 0 ) ) {
int V_102 = - V_97 ;
if ( F_57 ( V_102 > V_19 ) )
V_102 = V_19 ;
if ( V_2 -> V_99 + V_102 >= V_2 -> type -> V_103 )
goto V_101;
memcpy ( V_2 -> V_96 + V_2 -> V_99 , V_10 , V_102 ) ;
V_2 -> V_99 += V_102 ;
V_97 = V_2 -> type -> V_100 (
V_2 -> V_96 , V_2 -> V_99 ) ;
if ( V_97 < 0 )
return;
}
V_11 = V_97 - V_2 -> V_99 ;
if ( V_2 -> V_99 + V_11 >= V_2 -> type -> V_103 )
goto V_101;
memcpy ( V_2 -> V_96 + V_2 -> V_99 , V_10 , V_11 ) ;
F_52 ( V_2 , V_2 -> V_96 , V_97 ) ;
V_96 = V_10 + V_11 ;
V_99 = V_19 - V_11 ;
} else {
V_96 = V_10 ;
V_99 = V_19 ;
}
V_98 = 0 ;
while ( V_98 < V_99 ) {
V_97 = V_2 -> type -> V_100 ( V_96 + V_98 ,
V_99 - V_98 ) ;
if ( F_57 ( ! V_97 ) ) {
V_98 ++ ;
continue;
}
if ( F_58 ( ( V_97 > 0 ) && ( V_97 <= V_99 - V_98 ) ) ) {
F_52 ( V_2 , V_96 + V_98 , V_97 ) ;
} else {
memcpy ( V_2 -> V_96 , V_96 + V_98 , V_99 - V_98 ) ;
V_2 -> V_99 = V_99 - V_98 ;
return;
}
V_98 += V_97 ;
}
V_101:
V_2 -> V_99 = 0 ;
return;
}
static void F_59 ( struct V_47 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_104 ;
int V_105 ;
switch ( V_47 -> V_106 ) {
case 0 :
break;
case - V_107 :
F_5 ( L_10 ,
V_8 ) ;
return;
case - V_108 :
case - V_109 :
case - V_110 :
case - V_32 :
F_5 ( L_11 ,
V_8 , V_47 -> V_106 ) ;
return;
default:
F_5 ( L_12 ,
V_8 , V_47 -> V_106 ) ;
goto exit;
}
V_2 -> type -> V_111 ( V_2 , V_2 -> V_87 , V_47 -> V_112 ) ;
exit:
F_60 ( F_2 ( V_2 -> V_6 ) ) ;
V_105 = F_50 ( V_47 , V_84 ) ;
if ( V_105 )
F_61 ( L_13 ,
V_8 , V_105 ) ;
}
static int F_62 ( struct V_113 * V_33 )
{
struct V_1 * V_2 = F_63 ( V_33 ) ;
int V_114 ;
V_2 -> V_115 -> V_9 = F_2 ( V_2 -> V_6 ) ;
V_114 = F_64 ( V_2 -> V_6 ) ? - V_116 : 0 ;
if ( V_114 < 0 )
goto V_117;
if ( ! V_2 -> type -> V_118 ) {
if ( F_50 ( V_2 -> V_115 , V_50 ) ) {
V_114 = - V_116 ;
goto V_119;
}
}
V_2 -> V_6 -> V_120 = 1 ;
V_119:
F_65 ( V_2 -> V_6 ) ;
V_117:
return V_114 ;
}
static void F_66 ( struct V_113 * V_33 )
{
struct V_1 * V_2 = F_63 ( V_33 ) ;
int V_114 ;
if ( ! V_2 -> type -> V_118 )
F_46 ( V_2 -> V_115 ) ;
V_114 = F_64 ( V_2 -> V_6 ) ;
V_2 -> V_6 -> V_120 = 0 ;
if ( ! V_114 )
F_65 ( V_2 -> V_6 ) ;
}
static int F_67
( struct V_121 * V_122 , T_1 V_123 )
{
struct V_1 * V_2 = F_68 ( V_122 ) ;
F_46 ( V_2 -> V_115 ) ;
return 0 ;
}
static int F_69 ( struct V_121 * V_122 )
{
struct V_1 * V_2 = F_68 ( V_122 ) ;
struct V_113 * V_33 = V_2 -> V_33 ;
int V_124 = 0 ;
F_70 ( & V_33 -> V_125 ) ;
if ( V_33 -> V_126 || V_2 -> type -> V_118 )
V_124 = F_50 ( V_2 -> V_115 , V_38 ) ;
F_71 ( & V_33 -> V_125 ) ;
return V_124 ;
}
static int F_72 ( struct V_121 * V_122 )
{
struct V_1 * V_2 = F_68 ( V_122 ) ;
struct V_113 * V_33 = V_2 -> V_33 ;
int F_61 = 0 ;
if ( V_2 -> type -> V_127 ) {
F_61 = V_2 -> type -> V_127 ( V_2 ) ;
if ( F_61 ) {
F_5 ( L_14 ,
V_8 , F_61 ) ;
return F_61 ;
}
}
F_70 ( & V_33 -> V_125 ) ;
if ( V_33 -> V_126 )
F_61 = F_50 ( V_2 -> V_115 , V_38 ) ;
F_71 ( & V_33 -> V_125 ) ;
return F_61 ;
}
static void F_73 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
F_74 ( V_5 , V_2 -> type -> V_103 ,
V_2 -> V_87 , V_2 -> V_128 ) ;
F_22 ( V_2 -> V_96 ) ;
}
static struct V_129 *
F_75 ( struct V_57 * V_6 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_6 -> V_64 . V_65 ; V_26 ++ )
if ( F_37 ( & V_6 -> V_66 [ V_26 ] . V_64 ) )
return & V_6 -> V_66 [ V_26 ] . V_64 ;
return NULL ;
}
static int F_76 ( struct V_121 * V_122 ,
const struct V_130 * V_131 )
{
struct V_1 * V_2 ;
struct V_113 * V_113 ;
struct V_129 * V_66 ;
struct V_4 * V_5 = F_2 ( V_122 ) ;
struct V_90 * type ;
int F_61 = - V_37 ;
if ( V_131 -> V_132 == V_133 )
return - V_43 ;
V_66 = F_75 ( V_122 -> V_58 ) ;
if ( ! V_66 )
return - V_68 ;
V_2 = F_77 ( sizeof( struct V_1 ) , V_50 ) ;
V_113 = F_78 () ;
if ( ! V_2 || ! V_113 )
goto V_134;
type = & V_135 [ V_131 -> V_132 ] ;
V_2 -> type = type ;
if ( ! type -> V_111 )
type -> V_111 = F_52 ;
V_2 -> V_87 = F_79 ( V_5 , type -> V_103 ,
V_50 , & V_2 -> V_128 ) ;
if ( ! V_2 -> V_87 )
goto V_134;
if ( type -> V_100 ) {
V_2 -> V_96 = F_21 ( type -> V_103 , V_50 ) ;
if ( ! V_2 -> V_96 )
goto V_136;
}
V_2 -> V_115 = F_35 ( 0 , V_50 ) ;
if ( ! V_2 -> V_115 ) {
F_5 ( L_15 , V_8 ) ;
goto V_136;
}
V_2 -> V_6 = V_122 ;
V_2 -> V_33 = V_113 ;
if ( V_5 -> V_137 )
F_80 ( V_2 -> V_138 , V_5 -> V_137 , sizeof( V_2 -> V_138 ) ) ;
if ( V_5 -> V_139 ) {
if ( V_5 -> V_137 )
F_81 ( V_2 -> V_138 , L_16 , sizeof( V_2 -> V_138 ) ) ;
F_81 ( V_2 -> V_138 , V_5 -> V_139 , sizeof( V_2 -> V_138 ) ) ;
}
if ( ! strlen ( V_2 -> V_138 ) )
snprintf ( V_2 -> V_138 , sizeof( V_2 -> V_138 ) ,
L_17 ,
F_82 ( V_5 -> V_140 . V_141 ) ,
F_82 ( V_5 -> V_140 . V_142 ) ) ;
F_83 ( V_5 , V_2 -> V_143 , sizeof( V_2 -> V_143 ) ) ;
F_81 ( V_2 -> V_143 , L_18 , sizeof( V_2 -> V_143 ) ) ;
V_113 -> V_138 = V_2 -> V_138 ;
V_113 -> V_143 = V_2 -> V_143 ;
F_84 ( V_5 , & V_113 -> V_131 ) ;
V_113 -> V_9 . V_144 = & V_122 -> V_9 ;
F_85 ( V_113 , V_2 ) ;
V_113 -> V_145 = F_62 ;
V_113 -> V_146 = F_66 ;
V_113 -> V_147 [ 0 ] = F_86 ( V_148 ) | F_86 ( V_149 ) ;
V_113 -> V_150 [ F_87 ( V_92 ) ] = F_86 ( V_92 ) ;
F_15 ( V_113 , V_34 , type -> V_151 , type -> V_85 , 0 , 0 ) ;
F_15 ( V_113 , V_35 , type -> V_152 , type -> V_86 , 0 , 0 ) ;
if ( type -> V_94 )
F_15 ( V_113 , V_95 , type -> V_153 ,
type -> V_94 , 0 , 0 ) ;
if ( F_88 ( V_66 ) == V_154 )
F_89 ( V_2 -> V_115 , V_5 ,
F_90 ( V_5 , V_66 -> V_67 ) ,
V_2 -> V_87 , type -> V_103 ,
F_59 , V_2 , V_66 -> V_155 ) ;
else
F_44 ( V_2 -> V_115 , V_5 ,
F_40 ( V_5 , V_66 -> V_67 ) ,
V_2 -> V_87 , type -> V_103 ,
F_59 , V_2 ) ;
V_2 -> V_115 -> V_9 = V_5 ;
V_2 -> V_115 -> V_156 = V_2 -> V_128 ;
V_2 -> V_115 -> V_157 |= V_158 ;
if ( type -> V_159 ) {
F_61 = type -> V_159 ( V_2 ) ;
if ( F_61 ) {
F_5 ( L_19 , V_8 , F_61 ) ;
goto V_160;
}
}
if ( type -> V_127 ) {
F_61 = type -> V_127 ( V_2 ) ;
if ( F_61 ) {
F_5 ( L_14 , V_8 , F_61 ) ;
goto V_161;
}
}
F_61 = F_91 ( V_2 -> V_33 ) ;
if ( F_61 ) {
F_5 ( L_20 , V_8 , F_61 ) ;
goto V_161;
}
F_92 ( V_122 , V_2 ) ;
if ( V_2 -> type -> V_118 ) {
F_64 ( V_122 ) ;
F_61 = F_50 ( V_2 -> V_115 , V_50 ) ;
if ( F_61 ) {
F_65 ( V_122 ) ;
F_61 ( L_13 ,
V_8 , F_61 ) ;
goto V_162;
}
}
return 0 ;
V_162:
F_93 ( V_113 ) ;
V_113 = NULL ;
V_161:
if ( type -> exit )
type -> exit ( V_2 ) ;
V_160:
F_47 ( V_2 -> V_115 ) ;
V_136:
F_73 ( V_5 , V_2 ) ;
V_134:
F_94 ( V_113 ) ;
F_22 ( V_2 ) ;
return F_61 ;
}
static void F_95 ( struct V_121 * V_122 )
{
struct V_1 * V_2 = F_68 ( V_122 ) ;
F_5 ( L_21 , V_8 ) ;
if ( ! V_2 )
return;
F_5 ( L_22 , V_8 ) ;
F_92 ( V_122 , NULL ) ;
F_93 ( V_2 -> V_33 ) ;
F_47 ( V_2 -> V_115 ) ;
if ( V_2 -> type -> exit )
V_2 -> type -> exit ( V_2 ) ;
F_73 ( F_2 ( V_122 ) , V_2 ) ;
F_22 ( V_2 ) ;
}
