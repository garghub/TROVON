static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
V_3 = F_3 ( V_5 , F_4 ( V_5 , 0 ) ,
0x01 , 0x02 , 0x0000 , 0x0081 ,
NULL , 0 , V_7 ) ;
F_5 ( & V_2 -> V_6 -> V_8 ,
L_1 ,
V_9 , V_3 ) ;
return V_3 ;
}
static int F_6 ( struct V_1 * V_8 , unsigned char * V_10 )
{
int V_11 = ( V_10 [ 0 ] << 8 ) | V_10 [ 1 ] ;
V_8 -> V_12 = ( V_10 [ 2 ] << 8 ) | V_10 [ 3 ] ;
V_8 -> V_13 = ( V_10 [ 4 ] << 8 ) | V_10 [ 5 ] ;
V_11 = V_11 - 0xA000 ;
V_8 -> V_14 = ( V_11 > 0 ) ;
V_8 -> V_15 = ( V_11 > 0 ? V_11 : 0 ) ;
return 1 ;
}
static int F_7 ( struct V_1 * V_8 , unsigned char * V_10 )
{
if ( ( V_10 [ 0 ] & V_16 ) != V_17 )
return 0 ;
V_8 -> V_12 = ( ( V_10 [ 3 ] & 0x0F ) << 7 ) | ( V_10 [ 4 ] & 0x7F ) ;
V_8 -> V_13 = ( ( V_10 [ 1 ] & 0x0F ) << 7 ) | ( V_10 [ 2 ] & 0x7F ) ;
V_8 -> V_14 = V_10 [ 0 ] & 0x01 ;
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
static int F_9 ( struct V_1 * V_8 , unsigned char * V_10 )
{
if ( ( V_10 [ 0 ] & V_21 ) != V_22 &&
( V_10 [ 0 ] & V_21 ) != V_23 )
return 0 ;
V_8 -> V_12 = ( ( V_10 [ 1 ] & 0x1F ) << 7 ) | ( V_10 [ 2 ] & 0x7F ) ;
V_8 -> V_13 = ( ( V_10 [ 3 ] & 0x1F ) << 7 ) | ( V_10 [ 4 ] & 0x7F ) ;
V_8 -> V_14 = V_10 [ 0 ] & 0x01 ;
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
static int F_11 ( struct V_1 * V_8 , unsigned char * V_10 )
{
V_8 -> V_12 = ( ( V_10 [ 2 ] & 0x0F ) << 8 ) | V_10 [ 1 ] ;
V_8 -> V_13 = ( ( V_10 [ 4 ] & 0x0F ) << 8 ) | V_10 [ 3 ] ;
V_8 -> V_14 = V_10 [ 0 ] & 0x01 ;
return 1 ;
}
static int F_12 ( struct V_1 * V_8 , unsigned char * V_10 )
{
if ( V_25 ) {
V_8 -> V_12 = ( V_10 [ 4 ] << 8 ) | V_10 [ 3 ] ;
V_8 -> V_13 = 0xffff - ( ( V_10 [ 6 ] << 8 ) | V_10 [ 5 ] ) ;
} else {
V_8 -> V_12 = ( V_10 [ 8 ] << 8 ) | V_10 [ 7 ] ;
V_8 -> V_13 = ( V_10 [ 10 ] << 8 ) | V_10 [ 9 ] ;
}
V_8 -> V_14 = ( V_10 [ 2 ] & 0x40 ) ? 1 : 0 ;
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
F_5 ( & V_2 -> V_6 -> V_8 ,
L_2 ,
V_9 , V_3 ) ;
if ( V_3 < 0 )
return V_3 ;
F_14 ( 150 ) ;
for ( V_26 = 0 ; V_26 < 3 ; V_26 ++ ) {
V_3 = F_3 ( V_5 , F_4 ( V_5 , 0 ) ,
V_31 ,
V_28 | V_29 | V_30 ,
1 , 1 , NULL , 0 , V_7 ) ;
F_5 ( & V_2 -> V_6 -> V_8 ,
L_3 ,
V_9 , V_3 ) ;
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
static int F_16 ( struct V_1 * V_8 , unsigned char * V_10 )
{
int V_14 ;
V_8 -> V_15 = ( ( V_10 [ 2 ] & 0x01 ) << 7 ) | ( V_10 [ 5 ] & 0x7F ) ;
V_14 = ~ V_10 [ 7 ] & 0x20 ;
if ( ! V_14 ) {
if ( V_8 -> V_14 ) {
V_8 -> V_14 = 0 ;
return 1 ;
}
return 0 ;
}
V_8 -> V_12 = ( ( V_10 [ 0 ] & 0x1F ) << 7 ) | ( V_10 [ 3 ] & 0x7F ) ;
V_8 -> V_13 = ( ( V_10 [ 1 ] & 0x1F ) << 7 ) | ( V_10 [ 4 ] & 0x7F ) ;
V_8 -> V_14 = V_14 ;
return 1 ;
}
static int F_17 ( struct V_1 * V_8 , unsigned char * V_10 )
{
unsigned int V_36 ;
if ( ! ( V_10 [ 0 ] & 0x80 ) )
return 0 ;
V_36 = ( 6 - ( V_10 [ 0 ] & 0x03 ) ) ;
V_8 -> V_12 = ( ( V_10 [ 3 ] << 7 ) | V_10 [ 4 ] ) >> V_36 ;
V_8 -> V_13 = ( ( V_10 [ 1 ] << 7 ) | V_10 [ 2 ] ) >> V_36 ;
V_8 -> V_14 = ( V_10 [ 0 ] & 0x10 ) ? 1 : 0 ;
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
static int F_19 ( struct V_1 * V_8 , unsigned char * V_10 )
{
if ( ! ( V_10 [ 0 ] & 0x80 ) || ( ( V_10 [ 1 ] | V_10 [ 2 ] | V_10 [ 3 ] ) & 0x80 ) )
return 0 ;
V_8 -> V_12 = ( ( V_10 [ 0 ] & 0x1F ) << 7 ) | ( V_10 [ 2 ] & 0x7F ) ;
V_8 -> V_13 = ( ( V_10 [ 1 ] & 0x1F ) << 7 ) | ( V_10 [ 3 ] & 0x7F ) ;
V_8 -> V_14 = V_10 [ 0 ] & 0x20 ;
return 1 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_4 * V_8 = F_2 ( V_2 -> V_6 ) ;
int V_3 = - V_37 ;
unsigned char * V_18 ;
V_18 = F_21 ( 2 , V_38 ) ;
if ( ! V_18 )
goto V_39;
V_18 [ 0 ] = V_18 [ 1 ] = 0xFF ;
V_3 = F_3 ( V_8 , F_4 ( V_8 , 0 ) ,
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
V_3 = F_3 ( V_8 , F_4 ( V_8 , 0 ) ,
V_44 ,
V_41 | V_29 | V_30 ,
V_45 , 0 , V_18 , 2 , V_7 ) ;
if ( V_3 < 0 )
goto V_42;
if ( ( V_18 [ 0 ] != 0x06 ) && ( V_18 [ 0 ] != 0x15 || V_18 [ 1 ] != 0x01 ) ) {
V_3 = - V_43 ;
goto V_42;
}
V_3 = F_3 ( V_8 , F_4 ( V_8 , 0 ) ,
V_46 ,
V_28 | V_29 | V_30 ,
0 , 0 , NULL , 0 , V_7 ) ;
V_42:
F_22 ( V_18 ) ;
V_39:
return V_3 ;
}
static int F_23 ( struct V_1 * V_8 , unsigned char * V_10 )
{
V_8 -> V_12 = ( ( V_10 [ 2 ] & 0x03 ) << 8 ) | V_10 [ 1 ] ;
V_8 -> V_13 = ( ( V_10 [ 4 ] & 0x03 ) << 8 ) | V_10 [ 3 ] ;
V_8 -> V_14 = V_10 [ 0 ] & 0x01 ;
return 1 ;
}
static int F_24 ( struct V_1 * V_8 , unsigned char * V_10 )
{
V_8 -> V_12 = ( V_10 [ 3 ] << 8 ) | V_10 [ 2 ] ;
V_8 -> V_13 = ( V_10 [ 5 ] << 8 ) | V_10 [ 4 ] ;
V_8 -> V_14 = ( V_10 [ 1 ] & 0x03 ) ? 1 : 0 ;
return 1 ;
}
static int F_25 ( struct V_1 * V_8 , unsigned char * V_10 )
{
V_8 -> V_12 = ( ( V_10 [ 2 ] & 0x0F ) << 8 ) | V_10 [ 1 ] ;
V_8 -> V_13 = ( ( V_10 [ 4 ] & 0x0F ) << 8 ) | V_10 [ 3 ] ;
V_8 -> V_14 = V_10 [ 0 ] & 0x01 ;
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
static int F_27 ( struct V_1 * V_8 , unsigned char * V_10 )
{
switch ( V_10 [ 0 ] & 0x98 ) {
case 0x88 :
V_8 -> V_12 = ( V_10 [ 1 ] << 5 ) | ( V_10 [ 2 ] >> 2 ) ;
V_8 -> V_13 = ( V_10 [ 3 ] << 5 ) | ( V_10 [ 4 ] >> 2 ) ;
V_8 -> V_14 = ( V_10 [ 0 ] & 0x40 ) ? 1 : 0 ;
return 1 ;
case 0x98 :
V_8 -> V_12 = ( V_10 [ 2 ] << 5 ) | ( V_10 [ 1 ] >> 2 ) ;
V_8 -> V_13 = ( V_10 [ 4 ] << 5 ) | ( V_10 [ 3 ] >> 2 ) ;
V_8 -> V_14 = ( V_10 [ 0 ] & 0x40 ) ? 1 : 0 ;
return 1 ;
default:
return 0 ;
}
}
static int F_28 ( struct V_1 * V_8 , unsigned char * V_10 )
{
V_8 -> V_12 = ( V_10 [ 2 ] << 8 ) | V_10 [ 1 ] ;
V_8 -> V_13 = ( V_10 [ 4 ] << 8 ) | V_10 [ 3 ] ;
V_8 -> V_15 = V_10 [ 5 ] & 0xff ;
V_8 -> V_14 = V_10 [ 0 ] & 0x01 ;
return 1 ;
}
static int F_29 ( struct V_1 * V_8 , unsigned char * V_10 )
{
V_8 -> V_12 = ( ( V_10 [ 1 ] & 0x38 ) << 4 ) | V_10 [ 2 ] ;
V_8 -> V_13 = ( ( V_10 [ 1 ] & 0x07 ) << 7 ) | V_10 [ 3 ] ;
V_8 -> V_14 = V_10 [ 0 ] & 0x01 ;
return 1 ;
}
static int F_30 ( struct V_1 * V_8 , unsigned char * V_10 )
{
V_8 -> V_12 = ( ( V_10 [ 0 ] & 0x3f ) << 6 ) | ( V_10 [ 2 ] & 0x3f ) ;
V_8 -> V_13 = ( ( V_10 [ 1 ] & 0x3f ) << 6 ) | ( V_10 [ 3 ] & 0x3f ) ;
V_8 -> V_14 = ( V_10 [ 0 ] & 0x40 ) >> 6 ;
return 1 ;
}
static int F_31 ( struct V_1 * V_8 , unsigned char * V_10 )
{
struct V_47 * V_48 = V_8 -> V_6 ;
switch ( V_10 [ 0 ] ) {
case 0x3A :
F_5 ( & V_48 -> V_8 , L_4 , V_9 , V_10 [ 1 ] ) ;
break;
case 0xC0 :
V_8 -> V_12 = ( V_10 [ 1 ] & 0x7f ) | ( ( V_10 [ 2 ] & 0x07 ) << 7 ) ;
V_8 -> V_13 = ( V_10 [ 3 ] & 0x7f ) | ( ( V_10 [ 4 ] & 0x07 ) << 7 ) ;
V_8 -> V_14 = 1 ;
F_5 ( & V_48 -> V_8 , L_5 , V_9 , V_8 -> V_12 , V_8 -> V_13 ) ;
return 1 ;
case 0x80 :
V_8 -> V_12 = ( V_10 [ 1 ] & 0x7f ) | ( ( V_10 [ 2 ] & 0x07 ) << 7 ) ;
V_8 -> V_13 = ( V_10 [ 3 ] & 0x7f ) | ( ( V_10 [ 4 ] & 0x07 ) << 7 ) ;
V_8 -> V_14 = 0 ;
F_5 ( & V_48 -> V_8 , L_6 , V_9 , V_8 -> V_12 , V_8 -> V_13 ) ;
return 1 ;
default:
F_5 ( & V_48 -> V_8 , L_7 , V_9 , V_10 [ 0 ] ) ;
break;
}
return 0 ;
}
static void F_32 ( struct V_49 * V_49 )
{
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_50 * V_51 ;
int V_3 = - V_37 ;
V_2 -> V_51 = F_21 ( sizeof( struct V_50 ) , V_52 ) ;
if ( ! V_2 -> V_51 )
goto V_53;
V_51 = V_2 -> V_51 ;
V_51 -> V_54 = F_34 ( V_55 , sizeof( V_55 ) ,
V_52 ) ;
if ( ! V_51 -> V_54 )
goto V_56;
V_51 -> V_57 = F_35 ( 0 , V_52 ) ;
if ( ! V_51 -> V_57 ) {
F_5 ( & V_2 -> V_6 -> V_8 ,
L_8 , V_9 ) ;
goto V_58;
}
return 0 ;
V_58:
F_22 ( V_51 -> V_54 ) ;
V_56:
F_22 ( V_51 ) ;
V_53:
return V_3 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_4 * V_8 = F_2 ( V_2 -> V_6 ) ;
struct V_59 * V_6 = V_2 -> V_6 -> V_60 ;
struct V_50 * V_51 = V_2 -> V_51 ;
int V_3 = - V_37 ;
int V_61 , V_26 ;
unsigned char * V_18 ;
char * V_62 = NULL , * V_63 = NULL ;
int V_64 = 0 , V_65 = 0 ;
for ( V_26 = 0 ; V_26 < V_6 -> V_66 . V_67 ; V_26 ++ ) {
if ( ! V_64 &&
F_37 ( & V_6 -> V_68 [ V_26 ] . V_66 ) )
V_64 = V_6 -> V_68 [ V_26 ] . V_66 . V_69 ;
if ( ! V_65 &&
F_38 ( & V_6 -> V_68 [ V_26 ] . V_66 ) )
V_65 = V_6 -> V_68 [ V_26 ] . V_66 . V_69 ;
}
if ( ! V_64 || ! V_65 )
return - V_70 ;
V_18 = F_21 ( V_71 , V_38 ) ;
if ( ! V_18 )
goto V_53;
for ( V_26 = 0 ; V_26 < 2 ; V_26 ++ ) {
V_3 = F_39 ( V_8 , F_40 ( V_8 , V_64 ) ,
V_18 , V_71 , & V_61 ,
V_72 ) ;
if ( V_3 < 0 )
goto V_53;
}
memcpy ( V_18 , V_73 , sizeof( V_73 ) ) ;
V_3 = F_39 ( V_8 , F_41 ( V_8 , V_65 ) ,
V_18 , sizeof( V_73 ) , & V_61 ,
V_72 ) ;
if ( V_3 < 0 )
goto V_53;
for ( V_26 = 0 ; V_26 < 3 ; V_26 ++ ) {
memset ( V_18 , 0 , V_71 ) ;
V_3 = F_39 ( V_8 , F_40 ( V_8 , V_64 ) ,
V_18 , V_71 , & V_61 ,
V_72 ) ;
if ( V_3 < 0 || V_61 < 1 || V_18 [ 1 ] != V_61 )
continue;
switch ( V_18 [ 0 ] ) {
case 0x83 :
if ( ! V_62 )
V_62 = F_42 ( & V_18 [ 2 ] , V_38 ) ;
break;
case 0x84 :
if ( ! V_63 )
V_63 = F_42 ( & V_18 [ 2 ] , V_38 ) ;
break;
}
}
F_43 ( V_74 L_9 ,
V_63 , V_62 ) ;
F_22 ( V_62 ) ;
F_22 ( V_63 ) ;
F_44 ( V_51 -> V_57 , V_8 , F_41 ( V_8 , V_65 ) ,
V_51 -> V_54 , sizeof( V_55 ) ,
F_32 , V_2 ) ;
V_3 = 0 ;
V_53:
F_22 ( V_18 ) ;
return V_3 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = V_2 -> V_51 ;
F_46 ( V_51 -> V_57 ) ;
F_47 ( V_51 -> V_57 ) ;
F_22 ( V_51 -> V_54 ) ;
F_22 ( V_51 ) ;
}
static int F_48 ( struct V_1 * V_2 , unsigned char * V_10 )
{
struct V_75 * V_76 = ( void * ) V_10 ;
struct V_50 * V_51 = V_2 -> V_51 ;
unsigned int V_77 = F_49 ( V_76 -> V_77 ) ;
unsigned int V_78 = F_49 ( V_76 -> V_78 ) ;
unsigned int V_79 = F_49 ( V_76 -> V_79 ) ;
int V_12 , V_13 , V_80 , V_81 , V_82 , V_83 , V_84 , V_85 , V_3 ;
if ( ( V_10 [ 0 ] & 0xe0 ) != 0xe0 )
return 0 ;
if ( V_77 > 0xff )
V_77 -= 0x100 ;
if ( V_78 > 0xff )
V_78 -= 0x80 ;
V_3 = F_50 ( V_51 -> V_57 , V_86 ) ;
if ( ! V_2 -> type -> V_87 ) {
V_2 -> type -> V_87 = 2 * V_78 ;
F_15 ( V_2 -> V_33 , V_34 ,
0 , V_2 -> type -> V_87 , 0 , 0 ) ;
V_2 -> type -> V_88 = 2 * V_79 ;
F_15 ( V_2 -> V_33 , V_35 ,
0 , V_2 -> type -> V_88 , 0 , 0 ) ;
}
V_80 = V_82 = V_81 = V_83 = - 1 ;
for ( V_12 = 0 ; V_12 < V_78 ; V_12 ++ ) {
if ( V_80 == - 1 && V_76 -> V_89 [ V_12 ] > V_90 ) {
V_80 = V_12 ;
continue;
}
if ( V_82 == - 1 && V_80 != - 1 && V_76 -> V_89 [ V_12 ] < V_90 ) {
V_82 = V_12 - 1 ;
for ( V_13 = V_78 ; V_13 < V_77 ; V_13 ++ ) {
if ( V_81 == - 1 && V_76 -> V_89 [ V_13 ] > V_90 ) {
V_81 = V_13 - V_78 ;
continue;
}
if ( V_83 == - 1 &&
V_81 != - 1 && V_76 -> V_89 [ V_13 ] < V_90 ) {
V_83 = V_13 - 1 - V_78 ;
V_84 = V_82 - V_80 ;
V_85 = V_83 - V_81 ;
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
V_2 -> V_12 = 2 * V_80 + V_84 ;
V_2 -> V_13 = 2 * V_81 + V_85 ;
V_2 -> V_14 = V_76 -> V_91 & 0x01 ;
V_81 = V_83 = - 1 ;
return 1 ;
}
}
V_80 = V_82 = - 1 ;
}
}
return 0 ;
}
static int F_51 ( struct V_1 * V_8 , unsigned char * V_10 )
{
V_8 -> V_12 = ( V_10 [ 3 ] << 8 ) | V_10 [ 2 ] ;
V_8 -> V_13 = ( V_10 [ 5 ] << 8 ) | V_10 [ 4 ] ;
V_8 -> V_14 = V_10 [ 6 ] > 0 ;
V_8 -> V_15 = V_10 [ 6 ] ;
return 1 ;
}
static void F_52 ( struct V_1 * V_2 ,
unsigned char * V_10 , int V_19 )
{
struct V_92 * type = V_2 -> type ;
if ( ! type -> V_93 ( V_2 , V_10 ) )
return;
F_53 ( V_2 -> V_33 , V_94 , V_2 -> V_14 ) ;
if ( V_95 ) {
F_54 ( V_2 -> V_33 , V_34 , V_2 -> V_13 ) ;
F_54 ( V_2 -> V_33 , V_35 , V_2 -> V_12 ) ;
} else {
F_54 ( V_2 -> V_33 , V_34 , V_2 -> V_12 ) ;
F_54 ( V_2 -> V_33 , V_35 , V_2 -> V_13 ) ;
}
if ( type -> V_96 )
F_54 ( V_2 -> V_33 , V_97 , V_2 -> V_15 ) ;
F_55 ( V_2 -> V_33 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
unsigned char * V_10 , int V_19 )
{
unsigned char * V_98 ;
int V_99 , V_100 , V_101 , V_11 ;
if ( F_57 ( V_2 -> V_101 ) ) {
V_99 = V_2 -> type -> V_102 (
V_2 -> V_98 , V_2 -> V_101 ) ;
if ( F_57 ( ! V_99 ) )
goto V_103;
if ( F_57 ( V_99 < 0 ) ) {
int V_104 = - V_99 ;
if ( F_57 ( V_104 > V_19 ) )
V_104 = V_19 ;
if ( V_2 -> V_101 + V_104 >= V_2 -> type -> V_105 )
goto V_103;
memcpy ( V_2 -> V_98 + V_2 -> V_101 , V_10 , V_104 ) ;
V_2 -> V_101 += V_104 ;
V_99 = V_2 -> type -> V_102 (
V_2 -> V_98 , V_2 -> V_101 ) ;
if ( V_99 < 0 )
return;
}
V_11 = V_99 - V_2 -> V_101 ;
if ( V_2 -> V_101 + V_11 >= V_2 -> type -> V_105 )
goto V_103;
memcpy ( V_2 -> V_98 + V_2 -> V_101 , V_10 , V_11 ) ;
F_52 ( V_2 , V_2 -> V_98 , V_99 ) ;
V_98 = V_10 + V_11 ;
V_101 = V_19 - V_11 ;
} else {
V_98 = V_10 ;
V_101 = V_19 ;
}
V_100 = 0 ;
while ( V_100 < V_101 ) {
V_99 = V_2 -> type -> V_102 ( V_98 + V_100 ,
V_101 - V_100 ) ;
if ( F_57 ( ! V_99 ) ) {
V_100 ++ ;
continue;
}
if ( F_58 ( ( V_99 > 0 ) && ( V_99 <= V_101 - V_100 ) ) ) {
F_52 ( V_2 , V_98 + V_100 , V_99 ) ;
} else {
memcpy ( V_2 -> V_98 , V_98 + V_100 , V_101 - V_100 ) ;
V_2 -> V_101 = V_101 - V_100 ;
return;
}
V_100 += V_99 ;
}
V_103:
V_2 -> V_101 = 0 ;
return;
}
static void F_59 ( struct V_49 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_106 ;
struct V_107 * V_8 = & V_2 -> V_6 -> V_8 ;
int V_108 ;
switch ( V_49 -> V_109 ) {
case 0 :
break;
case - V_110 :
F_5 ( V_8 ,
L_10 ,
V_9 ) ;
return;
case - V_111 :
case - V_112 :
case - V_113 :
case - V_32 :
F_5 ( V_8 , L_11 ,
V_9 , V_49 -> V_109 ) ;
return;
default:
F_5 ( V_8 , L_12 ,
V_9 , V_49 -> V_109 ) ;
goto exit;
}
V_2 -> type -> V_114 ( V_2 , V_2 -> V_89 , V_49 -> V_115 ) ;
exit:
F_60 ( F_2 ( V_2 -> V_6 ) ) ;
V_108 = F_50 ( V_49 , V_86 ) ;
if ( V_108 )
F_61 ( V_8 , L_13 ,
V_9 , V_108 ) ;
}
static int F_62 ( struct V_116 * V_33 )
{
struct V_1 * V_2 = F_63 ( V_33 ) ;
int V_117 ;
V_2 -> V_118 -> V_8 = F_2 ( V_2 -> V_6 ) ;
V_117 = F_64 ( V_2 -> V_6 ) ? - V_119 : 0 ;
if ( V_117 < 0 )
goto V_120;
if ( ! V_2 -> type -> V_121 ) {
if ( F_50 ( V_2 -> V_118 , V_52 ) ) {
V_117 = - V_119 ;
goto V_122;
}
}
V_2 -> V_6 -> V_123 = 1 ;
V_122:
F_65 ( V_2 -> V_6 ) ;
V_120:
return V_117 ;
}
static void F_66 ( struct V_116 * V_33 )
{
struct V_1 * V_2 = F_63 ( V_33 ) ;
int V_117 ;
if ( ! V_2 -> type -> V_121 )
F_46 ( V_2 -> V_118 ) ;
V_117 = F_64 ( V_2 -> V_6 ) ;
V_2 -> V_6 -> V_123 = 0 ;
if ( ! V_117 )
F_65 ( V_2 -> V_6 ) ;
}
static int F_67
( struct V_47 * V_48 , T_1 V_124 )
{
struct V_1 * V_2 = F_68 ( V_48 ) ;
F_46 ( V_2 -> V_118 ) ;
return 0 ;
}
static int F_69 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_68 ( V_48 ) ;
struct V_116 * V_33 = V_2 -> V_33 ;
int V_125 = 0 ;
F_70 ( & V_33 -> V_126 ) ;
if ( V_33 -> V_127 || V_2 -> type -> V_121 )
V_125 = F_50 ( V_2 -> V_118 , V_38 ) ;
F_71 ( & V_33 -> V_126 ) ;
return V_125 ;
}
static int F_72 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_68 ( V_48 ) ;
struct V_116 * V_33 = V_2 -> V_33 ;
int V_128 = 0 ;
if ( V_2 -> type -> V_129 ) {
V_128 = V_2 -> type -> V_129 ( V_2 ) ;
if ( V_128 ) {
F_5 ( & V_48 -> V_8 ,
L_14 ,
V_9 , V_128 ) ;
return V_128 ;
}
}
F_70 ( & V_33 -> V_126 ) ;
if ( V_33 -> V_127 )
V_128 = F_50 ( V_2 -> V_118 , V_38 ) ;
F_71 ( & V_33 -> V_126 ) ;
return V_128 ;
}
static void F_73 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
F_74 ( V_5 , V_2 -> type -> V_105 ,
V_2 -> V_89 , V_2 -> V_130 ) ;
F_22 ( V_2 -> V_98 ) ;
}
static struct V_131 *
F_75 ( struct V_59 * V_6 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_6 -> V_66 . V_67 ; V_26 ++ )
if ( F_37 ( & V_6 -> V_68 [ V_26 ] . V_66 ) )
return & V_6 -> V_68 [ V_26 ] . V_66 ;
return NULL ;
}
static int F_76 ( struct V_47 * V_48 ,
const struct V_132 * V_133 )
{
struct V_1 * V_2 ;
struct V_116 * V_116 ;
struct V_131 * V_68 ;
struct V_4 * V_5 = F_2 ( V_48 ) ;
struct V_92 * type ;
int V_128 = - V_37 ;
if ( V_133 -> V_134 == V_135 )
return - V_43 ;
V_68 = F_75 ( V_48 -> V_60 ) ;
if ( ! V_68 )
return - V_70 ;
V_2 = F_77 ( sizeof( struct V_1 ) , V_52 ) ;
V_116 = F_78 () ;
if ( ! V_2 || ! V_116 )
goto V_136;
type = & V_137 [ V_133 -> V_134 ] ;
V_2 -> type = type ;
if ( ! type -> V_114 )
type -> V_114 = F_52 ;
V_2 -> V_89 = F_79 ( V_5 , type -> V_105 ,
V_52 , & V_2 -> V_130 ) ;
if ( ! V_2 -> V_89 )
goto V_136;
if ( type -> V_102 ) {
V_2 -> V_98 = F_21 ( type -> V_105 , V_52 ) ;
if ( ! V_2 -> V_98 )
goto V_138;
}
V_2 -> V_118 = F_35 ( 0 , V_52 ) ;
if ( ! V_2 -> V_118 ) {
F_5 ( & V_48 -> V_8 ,
L_15 , V_9 ) ;
goto V_138;
}
V_2 -> V_6 = V_48 ;
V_2 -> V_33 = V_116 ;
if ( V_5 -> V_139 )
F_80 ( V_2 -> V_140 , V_5 -> V_139 , sizeof( V_2 -> V_140 ) ) ;
if ( V_5 -> V_141 ) {
if ( V_5 -> V_139 )
F_81 ( V_2 -> V_140 , L_16 , sizeof( V_2 -> V_140 ) ) ;
F_81 ( V_2 -> V_140 , V_5 -> V_141 , sizeof( V_2 -> V_140 ) ) ;
}
if ( ! strlen ( V_2 -> V_140 ) )
snprintf ( V_2 -> V_140 , sizeof( V_2 -> V_140 ) ,
L_17 ,
F_82 ( V_5 -> V_142 . V_143 ) ,
F_82 ( V_5 -> V_142 . V_144 ) ) ;
F_83 ( V_5 , V_2 -> V_145 , sizeof( V_2 -> V_145 ) ) ;
F_81 ( V_2 -> V_145 , L_18 , sizeof( V_2 -> V_145 ) ) ;
V_116 -> V_140 = V_2 -> V_140 ;
V_116 -> V_145 = V_2 -> V_145 ;
F_84 ( V_5 , & V_116 -> V_133 ) ;
V_116 -> V_8 . V_146 = & V_48 -> V_8 ;
F_85 ( V_116 , V_2 ) ;
V_116 -> V_147 = F_62 ;
V_116 -> V_148 = F_66 ;
V_116 -> V_149 [ 0 ] = F_86 ( V_150 ) | F_86 ( V_151 ) ;
V_116 -> V_152 [ F_87 ( V_94 ) ] = F_86 ( V_94 ) ;
F_15 ( V_116 , V_34 , type -> V_153 , type -> V_87 , 0 , 0 ) ;
F_15 ( V_116 , V_35 , type -> V_154 , type -> V_88 , 0 , 0 ) ;
if ( type -> V_96 )
F_15 ( V_116 , V_97 , type -> V_155 ,
type -> V_96 , 0 , 0 ) ;
if ( F_88 ( V_68 ) == V_156 )
F_89 ( V_2 -> V_118 , V_5 ,
F_90 ( V_5 , V_68 -> V_69 ) ,
V_2 -> V_89 , type -> V_105 ,
F_59 , V_2 , V_68 -> V_157 ) ;
else
F_44 ( V_2 -> V_118 , V_5 ,
F_40 ( V_5 , V_68 -> V_69 ) ,
V_2 -> V_89 , type -> V_105 ,
F_59 , V_2 ) ;
V_2 -> V_118 -> V_8 = V_5 ;
V_2 -> V_118 -> V_158 = V_2 -> V_130 ;
V_2 -> V_118 -> V_159 |= V_160 ;
if ( type -> V_161 ) {
V_128 = type -> V_161 ( V_2 ) ;
if ( V_128 ) {
F_5 ( & V_48 -> V_8 ,
L_19 ,
V_9 , V_128 ) ;
goto V_162;
}
}
if ( type -> V_129 ) {
V_128 = type -> V_129 ( V_2 ) ;
if ( V_128 ) {
F_5 ( & V_48 -> V_8 ,
L_14 ,
V_9 , V_128 ) ;
goto V_163;
}
}
V_128 = F_91 ( V_2 -> V_33 ) ;
if ( V_128 ) {
F_5 ( & V_48 -> V_8 ,
L_20 ,
V_9 , V_128 ) ;
goto V_163;
}
F_92 ( V_48 , V_2 ) ;
if ( V_2 -> type -> V_121 ) {
F_64 ( V_48 ) ;
V_128 = F_50 ( V_2 -> V_118 , V_52 ) ;
if ( V_128 ) {
F_65 ( V_48 ) ;
F_61 ( & V_48 -> V_8 ,
L_13 ,
V_9 , V_128 ) ;
goto V_164;
}
}
return 0 ;
V_164:
F_93 ( V_116 ) ;
V_116 = NULL ;
V_163:
if ( type -> exit )
type -> exit ( V_2 ) ;
V_162:
F_47 ( V_2 -> V_118 ) ;
V_138:
F_73 ( V_5 , V_2 ) ;
V_136:
F_94 ( V_116 ) ;
F_22 ( V_2 ) ;
return V_128 ;
}
static void F_95 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_68 ( V_48 ) ;
if ( ! V_2 )
return;
F_5 ( & V_48 -> V_8 ,
L_21 , V_9 ) ;
F_92 ( V_48 , NULL ) ;
F_93 ( V_2 -> V_33 ) ;
F_47 ( V_2 -> V_118 ) ;
if ( V_2 -> type -> exit )
V_2 -> type -> exit ( V_2 ) ;
F_73 ( F_2 ( V_48 ) , V_2 ) ;
F_22 ( V_2 ) ;
}
