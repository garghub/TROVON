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
V_9 -> V_12 = ( ( V_10 [ 2 ] & 0x0F ) << 8 ) | V_10 [ 1 ] ;
V_9 -> V_13 = ( ( V_10 [ 4 ] & 0x0F ) << 8 ) | V_10 [ 3 ] ;
V_9 -> V_14 = V_10 [ 0 ] & 0x01 ;
return 1 ;
}
static int F_10 ( struct V_1 * V_9 , unsigned char * V_10 )
{
if ( V_21 ) {
V_9 -> V_12 = ( V_10 [ 4 ] << 8 ) | V_10 [ 3 ] ;
V_9 -> V_13 = 0xffff - ( ( V_10 [ 6 ] << 8 ) | V_10 [ 5 ] ) ;
} else {
V_9 -> V_12 = ( V_10 [ 8 ] << 8 ) | V_10 [ 7 ] ;
V_9 -> V_13 = ( V_10 [ 10 ] << 8 ) | V_10 [ 9 ] ;
}
V_9 -> V_14 = ( V_10 [ 2 ] & 0x40 ) ? 1 : 0 ;
return 1 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_3 , V_22 ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
V_3 = F_3 ( V_5 , F_4 ( V_5 , 0 ) ,
V_23 ,
V_24 | V_25 | V_26 ,
1 , 0 , NULL , 0 , V_7 ) ;
F_5 ( L_2 ,
V_8 , V_3 ) ;
if ( V_3 < 0 )
return V_3 ;
F_12 ( 150 ) ;
for ( V_22 = 0 ; V_22 < 3 ; V_22 ++ ) {
V_3 = F_3 ( V_5 , F_4 ( V_5 , 0 ) ,
V_27 ,
V_24 | V_25 | V_26 ,
1 , 1 , NULL , 0 , V_7 ) ;
F_5 ( L_3 ,
V_8 , V_3 ) ;
if ( V_3 >= 0 )
break;
if ( V_3 != - V_28 )
return V_3 ;
}
if ( V_21 ) {
F_13 ( V_2 -> V_29 , V_30 , 0 , 0xffff , 0 , 0 ) ;
F_13 ( V_2 -> V_29 , V_31 , 0 , 0xffff , 0 , 0 ) ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_9 , unsigned char * V_10 )
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
static int F_15 ( struct V_1 * V_9 , unsigned char * V_10 )
{
unsigned int V_32 ;
if ( ! ( V_10 [ 0 ] & 0x80 ) )
return 0 ;
V_32 = ( 6 - ( V_10 [ 0 ] & 0x03 ) ) ;
V_9 -> V_12 = ( ( V_10 [ 3 ] << 7 ) | V_10 [ 4 ] ) >> V_32 ;
V_9 -> V_13 = ( ( V_10 [ 1 ] << 7 ) | V_10 [ 2 ] ) >> V_32 ;
V_9 -> V_14 = ( V_10 [ 0 ] & 0x10 ) ? 1 : 0 ;
return 1 ;
}
static int F_16 ( unsigned char * V_18 , int V_19 )
{
if ( V_18 [ 0 ] & 0x80 )
return 5 ;
if ( V_18 [ 0 ] == 0x01 )
return 3 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_9 , unsigned char * V_10 )
{
if ( ! ( V_10 [ 0 ] & 0x80 ) || ( ( V_10 [ 1 ] | V_10 [ 2 ] | V_10 [ 3 ] ) & 0x80 ) )
return 0 ;
V_9 -> V_12 = ( ( V_10 [ 0 ] & 0x1F ) << 7 ) | ( V_10 [ 2 ] & 0x7F ) ;
V_9 -> V_13 = ( ( V_10 [ 1 ] & 0x1F ) << 7 ) | ( V_10 [ 3 ] & 0x7F ) ;
V_9 -> V_14 = V_10 [ 0 ] & 0x20 ;
return 1 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_9 = F_2 ( V_2 -> V_6 ) ;
int V_3 = - V_33 ;
unsigned char * V_18 ;
V_18 = F_19 ( 2 , V_34 ) ;
if ( ! V_18 )
goto V_35;
V_18 [ 0 ] = V_18 [ 1 ] = 0xFF ;
V_3 = F_3 ( V_9 , F_4 ( V_9 , 0 ) ,
V_36 ,
V_37 | V_25 | V_26 ,
0 , 0 , V_18 , 2 , V_7 ) ;
if ( V_3 < 0 )
goto V_38;
if ( V_18 [ 0 ] != 0x06 ) {
V_3 = - V_39 ;
goto V_38;
}
V_18 [ 0 ] = V_18 [ 1 ] = 0xFF ;
V_3 = F_3 ( V_9 , F_4 ( V_9 , 0 ) ,
V_40 ,
V_37 | V_25 | V_26 ,
V_41 , 0 , V_18 , 2 , V_7 ) ;
if ( V_3 < 0 )
goto V_38;
if ( ( V_18 [ 0 ] != 0x06 ) && ( V_18 [ 0 ] != 0x15 || V_18 [ 1 ] != 0x01 ) ) {
V_3 = - V_39 ;
goto V_38;
}
V_3 = F_3 ( V_9 , F_4 ( V_9 , 0 ) ,
V_42 ,
V_24 | V_25 | V_26 ,
0 , 0 , NULL , 0 , V_7 ) ;
V_38:
F_20 ( V_18 ) ;
V_35:
return V_3 ;
}
static int F_21 ( struct V_1 * V_9 , unsigned char * V_10 )
{
V_9 -> V_12 = ( ( V_10 [ 2 ] & 0x03 ) << 8 ) | V_10 [ 1 ] ;
V_9 -> V_13 = ( ( V_10 [ 4 ] & 0x03 ) << 8 ) | V_10 [ 3 ] ;
V_9 -> V_14 = V_10 [ 0 ] & 0x01 ;
return 1 ;
}
static int F_22 ( struct V_1 * V_9 , unsigned char * V_10 )
{
V_9 -> V_12 = ( V_10 [ 3 ] << 8 ) | V_10 [ 2 ] ;
V_9 -> V_13 = ( V_10 [ 5 ] << 8 ) | V_10 [ 4 ] ;
V_9 -> V_14 = ( V_10 [ 1 ] & 0x03 ) ? 1 : 0 ;
return 1 ;
}
static int F_23 ( struct V_1 * V_9 , unsigned char * V_10 )
{
V_9 -> V_12 = ( ( V_10 [ 2 ] & 0x0F ) << 8 ) | V_10 [ 1 ] ;
V_9 -> V_13 = ( ( V_10 [ 4 ] & 0x0F ) << 8 ) | V_10 [ 3 ] ;
V_9 -> V_14 = V_10 [ 0 ] & 0x01 ;
return 1 ;
}
static int F_24 ( unsigned char * V_18 , int V_19 )
{
if ( V_18 [ 0 ] & 0x80 )
return 5 ;
if ( V_18 [ 0 ] == 0x01 )
return V_19 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_9 , unsigned char * V_10 )
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
static int F_26 ( struct V_1 * V_9 , unsigned char * V_10 )
{
V_9 -> V_12 = ( V_10 [ 2 ] << 8 ) | V_10 [ 1 ] ;
V_9 -> V_13 = ( V_10 [ 4 ] << 8 ) | V_10 [ 3 ] ;
V_9 -> V_15 = V_10 [ 5 ] & 0xff ;
V_9 -> V_14 = V_10 [ 0 ] & 0x01 ;
return 1 ;
}
static int F_27 ( struct V_1 * V_9 , unsigned char * V_10 )
{
V_9 -> V_12 = ( ( V_10 [ 1 ] & 0x38 ) << 4 ) | V_10 [ 2 ] ;
V_9 -> V_13 = ( ( V_10 [ 1 ] & 0x07 ) << 7 ) | V_10 [ 3 ] ;
V_9 -> V_14 = V_10 [ 0 ] & 0x01 ;
return 1 ;
}
static int F_28 ( struct V_1 * V_9 , unsigned char * V_10 )
{
V_9 -> V_12 = ( ( V_10 [ 0 ] & 0x3f ) << 6 ) | ( V_10 [ 2 ] & 0x3f ) ;
V_9 -> V_13 = ( ( V_10 [ 1 ] & 0x3f ) << 6 ) | ( V_10 [ 3 ] & 0x3f ) ;
V_9 -> V_14 = ( V_10 [ 0 ] & 0x40 ) >> 6 ;
return 1 ;
}
static int F_29 ( struct V_1 * V_9 , unsigned char * V_10 )
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
static void F_30 ( struct V_43 * V_43 )
{
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_44 * V_45 ;
int V_3 = - V_33 ;
V_2 -> V_45 = F_19 ( sizeof( struct V_44 ) , V_46 ) ;
if ( ! V_2 -> V_45 )
goto V_47;
V_45 = V_2 -> V_45 ;
V_45 -> V_48 = F_32 ( V_49 , sizeof( V_49 ) ,
V_46 ) ;
if ( ! V_45 -> V_48 )
goto V_50;
V_45 -> V_51 = F_33 ( 0 , V_46 ) ;
if ( ! V_45 -> V_51 ) {
F_5 ( L_8 , V_8 ) ;
goto V_52;
}
return 0 ;
V_52:
F_20 ( V_45 -> V_48 ) ;
V_50:
F_20 ( V_45 ) ;
V_47:
return V_3 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_4 * V_9 = F_2 ( V_2 -> V_6 ) ;
struct V_53 * V_6 = V_2 -> V_6 -> V_54 ;
struct V_44 * V_45 = V_2 -> V_45 ;
int V_3 = - V_33 ;
int V_55 , V_22 ;
unsigned char * V_18 ;
char * V_56 = NULL , * V_57 = NULL ;
int V_58 = 0 , V_59 = 0 ;
for ( V_22 = 0 ; V_22 < V_6 -> V_60 . V_61 ; V_22 ++ ) {
if ( ! V_58 &&
F_35 ( & V_6 -> V_62 [ V_22 ] . V_60 ) )
V_58 = V_6 -> V_62 [ V_22 ] . V_60 . V_63 ;
if ( ! V_59 &&
F_36 ( & V_6 -> V_62 [ V_22 ] . V_60 ) )
V_59 = V_6 -> V_62 [ V_22 ] . V_60 . V_63 ;
}
if ( ! V_58 || ! V_59 )
return - V_64 ;
V_18 = F_19 ( V_65 , V_34 ) ;
if ( ! V_18 )
goto V_47;
for ( V_22 = 0 ; V_22 < 2 ; V_22 ++ ) {
V_3 = F_37 ( V_9 , F_38 ( V_9 , V_58 ) ,
V_18 , V_65 , & V_55 ,
V_66 ) ;
if ( V_3 < 0 )
goto V_47;
}
memcpy ( V_18 , V_67 , sizeof( V_67 ) ) ;
V_3 = F_37 ( V_9 , F_39 ( V_9 , V_59 ) ,
V_18 , sizeof( V_67 ) , & V_55 ,
V_66 ) ;
if ( V_3 < 0 )
goto V_47;
for ( V_22 = 0 ; V_22 < 3 ; V_22 ++ ) {
memset ( V_18 , 0 , V_65 ) ;
V_3 = F_37 ( V_9 , F_38 ( V_9 , V_58 ) ,
V_18 , V_65 , & V_55 ,
V_66 ) ;
if ( V_3 < 0 || V_55 < 1 || V_18 [ 1 ] != V_55 )
continue;
switch ( V_18 [ 0 ] ) {
case 0x83 :
if ( ! V_56 )
V_56 = F_40 ( & V_18 [ 2 ] , V_34 ) ;
break;
case 0x84 :
if ( ! V_57 )
V_57 = F_40 ( & V_18 [ 2 ] , V_34 ) ;
break;
}
}
F_41 ( V_68 L_9 ,
V_57 , V_56 ) ;
F_20 ( V_56 ) ;
F_20 ( V_57 ) ;
F_42 ( V_45 -> V_51 , V_9 , F_39 ( V_9 , V_59 ) ,
V_45 -> V_48 , sizeof( V_49 ) ,
F_30 , V_2 ) ;
V_3 = 0 ;
V_47:
F_20 ( V_18 ) ;
return V_3 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
F_44 ( V_45 -> V_51 ) ;
F_45 ( V_45 -> V_51 ) ;
F_20 ( V_45 -> V_48 ) ;
F_20 ( V_45 ) ;
}
static int F_46 ( struct V_1 * V_2 , unsigned char * V_10 )
{
struct V_69 * V_70 = ( void * ) V_10 ;
struct V_44 * V_45 = V_2 -> V_45 ;
unsigned int V_71 = F_47 ( V_70 -> V_71 ) ;
unsigned int V_72 = F_47 ( V_70 -> V_72 ) ;
unsigned int V_73 = F_47 ( V_70 -> V_73 ) ;
int V_12 , V_13 , V_74 , V_75 , V_76 , V_77 , V_78 , V_79 , V_3 ;
if ( ( V_10 [ 0 ] & 0xe0 ) != 0xe0 )
return 0 ;
if ( V_71 > 0xff )
V_71 -= 0x100 ;
if ( V_72 > 0xff )
V_72 -= 0x80 ;
V_3 = F_48 ( V_45 -> V_51 , V_80 ) ;
if ( ! V_2 -> type -> V_81 ) {
V_2 -> type -> V_81 = 2 * V_72 ;
F_13 ( V_2 -> V_29 , V_30 ,
0 , V_2 -> type -> V_81 , 0 , 0 ) ;
V_2 -> type -> V_82 = 2 * V_73 ;
F_13 ( V_2 -> V_29 , V_31 ,
0 , V_2 -> type -> V_82 , 0 , 0 ) ;
}
V_74 = V_76 = V_75 = V_77 = - 1 ;
for ( V_12 = 0 ; V_12 < V_72 ; V_12 ++ ) {
if ( V_74 == - 1 && V_70 -> V_83 [ V_12 ] > V_84 ) {
V_74 = V_12 ;
continue;
}
if ( V_76 == - 1 && V_74 != - 1 && V_70 -> V_83 [ V_12 ] < V_84 ) {
V_76 = V_12 - 1 ;
for ( V_13 = V_72 ; V_13 < V_71 ; V_13 ++ ) {
if ( V_75 == - 1 && V_70 -> V_83 [ V_13 ] > V_84 ) {
V_75 = V_13 - V_72 ;
continue;
}
if ( V_77 == - 1 &&
V_75 != - 1 && V_70 -> V_83 [ V_13 ] < V_84 ) {
V_77 = V_13 - 1 - V_72 ;
V_78 = V_76 - V_74 ;
V_79 = V_77 - V_75 ;
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
V_2 -> V_12 = 2 * V_74 + V_78 ;
V_2 -> V_13 = 2 * V_75 + V_79 ;
V_2 -> V_14 = V_70 -> V_85 & 0x01 ;
V_75 = V_77 = - 1 ;
return 1 ;
}
}
V_74 = V_76 = - 1 ;
}
}
return 0 ;
}
static int F_49 ( struct V_1 * V_9 , unsigned char * V_10 )
{
V_9 -> V_12 = ( V_10 [ 3 ] << 8 ) | V_10 [ 2 ] ;
V_9 -> V_13 = ( V_10 [ 5 ] << 8 ) | V_10 [ 4 ] ;
V_9 -> V_14 = V_10 [ 6 ] > 0 ;
V_9 -> V_15 = V_10 [ 6 ] ;
return 1 ;
}
static void F_50 ( struct V_1 * V_2 ,
unsigned char * V_10 , int V_19 )
{
struct V_86 * type = V_2 -> type ;
if ( ! type -> V_87 ( V_2 , V_10 ) )
return;
F_51 ( V_2 -> V_29 , V_88 , V_2 -> V_14 ) ;
if ( V_89 ) {
F_52 ( V_2 -> V_29 , V_30 , V_2 -> V_13 ) ;
F_52 ( V_2 -> V_29 , V_31 , V_2 -> V_12 ) ;
} else {
F_52 ( V_2 -> V_29 , V_30 , V_2 -> V_12 ) ;
F_52 ( V_2 -> V_29 , V_31 , V_2 -> V_13 ) ;
}
if ( type -> V_90 )
F_52 ( V_2 -> V_29 , V_91 , V_2 -> V_15 ) ;
F_53 ( V_2 -> V_29 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
unsigned char * V_10 , int V_19 )
{
unsigned char * V_92 ;
int V_93 , V_94 , V_95 , V_11 ;
if ( F_55 ( V_2 -> V_95 ) ) {
V_93 = V_2 -> type -> V_96 (
V_2 -> V_92 , V_2 -> V_95 ) ;
if ( F_55 ( ! V_93 ) )
goto V_97;
if ( F_55 ( V_93 < 0 ) ) {
int V_98 = - V_93 ;
if ( F_55 ( V_98 > V_19 ) )
V_98 = V_19 ;
if ( V_2 -> V_95 + V_98 >= V_2 -> type -> V_99 )
goto V_97;
memcpy ( V_2 -> V_92 + V_2 -> V_95 , V_10 , V_98 ) ;
V_2 -> V_95 += V_98 ;
V_93 = V_2 -> type -> V_96 (
V_2 -> V_92 , V_2 -> V_95 ) ;
if ( V_93 < 0 )
return;
}
V_11 = V_93 - V_2 -> V_95 ;
if ( V_2 -> V_95 + V_11 >= V_2 -> type -> V_99 )
goto V_97;
memcpy ( V_2 -> V_92 + V_2 -> V_95 , V_10 , V_11 ) ;
F_50 ( V_2 , V_2 -> V_92 , V_93 ) ;
V_92 = V_10 + V_11 ;
V_95 = V_19 - V_11 ;
} else {
V_92 = V_10 ;
V_95 = V_19 ;
}
V_94 = 0 ;
while ( V_94 < V_95 ) {
V_93 = V_2 -> type -> V_96 ( V_92 + V_94 ,
V_95 - V_94 ) ;
if ( F_55 ( ! V_93 ) ) {
V_94 ++ ;
continue;
}
if ( F_56 ( ( V_93 > 0 ) && ( V_93 <= V_95 - V_94 ) ) ) {
F_50 ( V_2 , V_92 + V_94 , V_93 ) ;
} else {
memcpy ( V_2 -> V_92 , V_92 + V_94 , V_95 - V_94 ) ;
V_2 -> V_95 = V_95 - V_94 ;
return;
}
V_94 += V_93 ;
}
V_97:
V_2 -> V_95 = 0 ;
return;
}
static void F_57 ( struct V_43 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_100 ;
int V_101 ;
switch ( V_43 -> V_102 ) {
case 0 :
break;
case - V_103 :
F_5 ( L_10 ,
V_8 ) ;
return;
case - V_104 :
case - V_105 :
case - V_106 :
case - V_28 :
F_5 ( L_11 ,
V_8 , V_43 -> V_102 ) ;
return;
default:
F_5 ( L_12 ,
V_8 , V_43 -> V_102 ) ;
goto exit;
}
V_2 -> type -> V_107 ( V_2 , V_2 -> V_83 , V_43 -> V_108 ) ;
exit:
F_58 ( F_2 ( V_2 -> V_6 ) ) ;
V_101 = F_48 ( V_43 , V_80 ) ;
if ( V_101 )
F_59 ( L_13 ,
V_8 , V_101 ) ;
}
static int F_60 ( struct V_109 * V_29 )
{
struct V_1 * V_2 = F_61 ( V_29 ) ;
int V_110 ;
V_2 -> V_111 -> V_9 = F_2 ( V_2 -> V_6 ) ;
V_110 = F_62 ( V_2 -> V_6 ) ? - V_112 : 0 ;
if ( V_110 < 0 )
goto V_113;
if ( ! V_2 -> type -> V_114 ) {
if ( F_48 ( V_2 -> V_111 , V_46 ) ) {
V_110 = - V_112 ;
goto V_115;
}
}
V_2 -> V_6 -> V_116 = 1 ;
V_115:
F_63 ( V_2 -> V_6 ) ;
V_113:
return V_110 ;
}
static void F_64 ( struct V_109 * V_29 )
{
struct V_1 * V_2 = F_61 ( V_29 ) ;
int V_110 ;
if ( ! V_2 -> type -> V_114 )
F_44 ( V_2 -> V_111 ) ;
V_110 = F_62 ( V_2 -> V_6 ) ;
V_2 -> V_6 -> V_116 = 0 ;
if ( ! V_110 )
F_63 ( V_2 -> V_6 ) ;
}
static int F_65
( struct V_117 * V_118 , T_1 V_119 )
{
struct V_1 * V_2 = F_66 ( V_118 ) ;
F_44 ( V_2 -> V_111 ) ;
return 0 ;
}
static int F_67 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = F_66 ( V_118 ) ;
struct V_109 * V_29 = V_2 -> V_29 ;
int V_120 = 0 ;
F_68 ( & V_29 -> V_121 ) ;
if ( V_29 -> V_122 || V_2 -> type -> V_114 )
V_120 = F_48 ( V_2 -> V_111 , V_34 ) ;
F_69 ( & V_29 -> V_121 ) ;
return V_120 ;
}
static int F_70 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = F_66 ( V_118 ) ;
struct V_109 * V_29 = V_2 -> V_29 ;
int F_59 = 0 ;
if ( V_2 -> type -> V_123 ) {
F_59 = V_2 -> type -> V_123 ( V_2 ) ;
if ( F_59 ) {
F_5 ( L_14 ,
V_8 , F_59 ) ;
return F_59 ;
}
}
F_68 ( & V_29 -> V_121 ) ;
if ( V_29 -> V_122 )
F_59 = F_48 ( V_2 -> V_111 , V_34 ) ;
F_69 ( & V_29 -> V_121 ) ;
return F_59 ;
}
static void F_71 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
F_72 ( V_5 , V_2 -> type -> V_99 ,
V_2 -> V_83 , V_2 -> V_124 ) ;
F_20 ( V_2 -> V_92 ) ;
}
static struct V_125 *
F_73 ( struct V_53 * V_6 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_6 -> V_60 . V_61 ; V_22 ++ )
if ( F_35 ( & V_6 -> V_62 [ V_22 ] . V_60 ) )
return & V_6 -> V_62 [ V_22 ] . V_60 ;
return NULL ;
}
static int F_74 ( struct V_117 * V_118 ,
const struct V_126 * V_127 )
{
struct V_1 * V_2 ;
struct V_109 * V_109 ;
struct V_125 * V_62 ;
struct V_4 * V_5 = F_2 ( V_118 ) ;
struct V_86 * type ;
int F_59 = - V_33 ;
if ( V_127 -> V_128 == V_129 )
return - V_39 ;
V_62 = F_73 ( V_118 -> V_54 ) ;
if ( ! V_62 )
return - V_64 ;
V_2 = F_75 ( sizeof( struct V_1 ) , V_46 ) ;
V_109 = F_76 () ;
if ( ! V_2 || ! V_109 )
goto V_130;
type = & V_131 [ V_127 -> V_128 ] ;
V_2 -> type = type ;
if ( ! type -> V_107 )
type -> V_107 = F_50 ;
V_2 -> V_83 = F_77 ( V_5 , type -> V_99 ,
V_46 , & V_2 -> V_124 ) ;
if ( ! V_2 -> V_83 )
goto V_130;
if ( type -> V_96 ) {
V_2 -> V_92 = F_19 ( type -> V_99 , V_46 ) ;
if ( ! V_2 -> V_92 )
goto V_132;
}
V_2 -> V_111 = F_33 ( 0 , V_46 ) ;
if ( ! V_2 -> V_111 ) {
F_5 ( L_15 , V_8 ) ;
goto V_132;
}
V_2 -> V_6 = V_118 ;
V_2 -> V_29 = V_109 ;
if ( V_5 -> V_133 )
F_78 ( V_2 -> V_134 , V_5 -> V_133 , sizeof( V_2 -> V_134 ) ) ;
if ( V_5 -> V_135 ) {
if ( V_5 -> V_133 )
F_79 ( V_2 -> V_134 , L_16 , sizeof( V_2 -> V_134 ) ) ;
F_79 ( V_2 -> V_134 , V_5 -> V_135 , sizeof( V_2 -> V_134 ) ) ;
}
if ( ! strlen ( V_2 -> V_134 ) )
snprintf ( V_2 -> V_134 , sizeof( V_2 -> V_134 ) ,
L_17 ,
F_80 ( V_5 -> V_136 . V_137 ) ,
F_80 ( V_5 -> V_136 . V_138 ) ) ;
F_81 ( V_5 , V_2 -> V_139 , sizeof( V_2 -> V_139 ) ) ;
F_79 ( V_2 -> V_139 , L_18 , sizeof( V_2 -> V_139 ) ) ;
V_109 -> V_134 = V_2 -> V_134 ;
V_109 -> V_139 = V_2 -> V_139 ;
F_82 ( V_5 , & V_109 -> V_127 ) ;
V_109 -> V_9 . V_140 = & V_118 -> V_9 ;
F_83 ( V_109 , V_2 ) ;
V_109 -> V_141 = F_60 ;
V_109 -> V_142 = F_64 ;
V_109 -> V_143 [ 0 ] = F_84 ( V_144 ) | F_84 ( V_145 ) ;
V_109 -> V_146 [ F_85 ( V_88 ) ] = F_84 ( V_88 ) ;
F_13 ( V_109 , V_30 , type -> V_147 , type -> V_81 , 0 , 0 ) ;
F_13 ( V_109 , V_31 , type -> V_148 , type -> V_82 , 0 , 0 ) ;
if ( type -> V_90 )
F_13 ( V_109 , V_91 , type -> V_149 ,
type -> V_90 , 0 , 0 ) ;
if ( F_86 ( V_62 ) == V_150 )
F_87 ( V_2 -> V_111 , V_5 ,
F_88 ( V_5 , V_62 -> V_63 ) ,
V_2 -> V_83 , type -> V_99 ,
F_57 , V_2 , V_62 -> V_151 ) ;
else
F_42 ( V_2 -> V_111 , V_5 ,
F_38 ( V_5 , V_62 -> V_63 ) ,
V_2 -> V_83 , type -> V_99 ,
F_57 , V_2 ) ;
V_2 -> V_111 -> V_9 = V_5 ;
V_2 -> V_111 -> V_152 = V_2 -> V_124 ;
V_2 -> V_111 -> V_153 |= V_154 ;
if ( type -> V_155 ) {
F_59 = type -> V_155 ( V_2 ) ;
if ( F_59 ) {
F_5 ( L_19 , V_8 , F_59 ) ;
goto V_156;
}
}
if ( type -> V_123 ) {
F_59 = type -> V_123 ( V_2 ) ;
if ( F_59 ) {
F_5 ( L_14 , V_8 , F_59 ) ;
goto V_157;
}
}
F_59 = F_89 ( V_2 -> V_29 ) ;
if ( F_59 ) {
F_5 ( L_20 , V_8 , F_59 ) ;
goto V_157;
}
F_90 ( V_118 , V_2 ) ;
if ( V_2 -> type -> V_114 ) {
F_62 ( V_118 ) ;
F_59 = F_48 ( V_2 -> V_111 , V_46 ) ;
if ( F_59 ) {
F_63 ( V_118 ) ;
F_59 ( L_13 ,
V_8 , F_59 ) ;
goto V_158;
}
}
return 0 ;
V_158:
F_91 ( V_109 ) ;
V_109 = NULL ;
V_157:
if ( type -> exit )
type -> exit ( V_2 ) ;
V_156:
F_45 ( V_2 -> V_111 ) ;
V_132:
F_71 ( V_5 , V_2 ) ;
V_130:
F_92 ( V_109 ) ;
F_20 ( V_2 ) ;
return F_59 ;
}
static void F_93 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = F_66 ( V_118 ) ;
F_5 ( L_21 , V_8 ) ;
if ( ! V_2 )
return;
F_5 ( L_22 , V_8 ) ;
F_90 ( V_118 , NULL ) ;
F_91 ( V_2 -> V_29 ) ;
F_45 ( V_2 -> V_111 ) ;
if ( V_2 -> type -> exit )
V_2 -> type -> exit ( V_2 ) ;
F_71 ( F_2 ( V_118 ) , V_2 ) ;
F_20 ( V_2 ) ;
}
