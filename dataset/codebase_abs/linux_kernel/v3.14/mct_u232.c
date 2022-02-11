static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 )
{
* V_4 = V_3 ;
if ( F_2 ( V_2 -> V_5 -> V_6 . V_7 ) == V_8
|| F_2 ( V_2 -> V_5 -> V_6 . V_7 ) == V_9 ) {
switch ( V_3 ) {
case 300 :
return 0x01 ;
case 600 :
return 0x02 ;
case 1200 :
return 0x03 ;
case 2400 :
return 0x04 ;
case 4800 :
return 0x06 ;
case 9600 :
return 0x08 ;
case 19200 :
return 0x09 ;
case 38400 :
return 0x0a ;
case 57600 :
return 0x0b ;
case 115200 :
return 0x0c ;
default:
* V_4 = 9600 ;
return 0x08 ;
}
} else {
switch ( V_3 ) {
case 300 : break;
case 600 : break;
case 1200 : break;
case 2400 : break;
case 4800 : break;
case 9600 : break;
case 19200 : break;
case 38400 : break;
case 57600 : break;
case 115200 : break;
default:
V_3 = 9600 ;
* V_4 = 9600 ;
}
return 115200 / V_3 ;
}
}
static int F_3 ( struct V_10 * V_11 ,
struct V_1 * V_2 , struct V_12 * V_13 , T_1 V_3 )
{
unsigned int V_14 ;
int V_15 ;
unsigned char * V_16 ;
unsigned char V_17 = 0 ;
T_1 V_18 ;
V_16 = F_4 ( V_19 , V_20 ) ;
if ( V_16 == NULL )
return - V_21 ;
V_14 = F_1 ( V_2 , V_3 , & V_18 ) ;
F_5 ( F_6 ( V_14 ) , V_16 ) ;
V_15 = F_7 ( V_2 -> V_5 , F_8 ( V_2 -> V_5 , 0 ) ,
V_22 ,
V_23 ,
0 , 0 , V_16 , V_24 ,
V_25 ) ;
if ( V_15 < 0 )
F_9 ( & V_13 -> V_5 , L_1 ,
V_3 , V_15 ) ;
else
F_10 ( V_11 , V_18 , V_18 ) ;
F_11 ( & V_13 -> V_5 , L_2 , V_3 , V_14 ) ;
V_16 [ 0 ] = 0 ;
V_15 = F_7 ( V_2 -> V_5 , F_8 ( V_2 -> V_5 , 0 ) ,
V_26 ,
V_23 ,
0 , 0 , V_16 , V_27 ,
V_25 ) ;
if ( V_15 < 0 )
F_9 ( & V_13 -> V_5 , L_3
L_4 , V_26 ,
V_15 ) ;
if ( V_13 && F_12 ( V_11 ) )
V_17 = 1 ;
F_11 ( & V_13 -> V_5 , L_5 ,
V_17 ) ;
V_16 [ 0 ] = V_17 ;
V_15 = F_7 ( V_2 -> V_5 , F_8 ( V_2 -> V_5 , 0 ) ,
V_28 ,
V_23 ,
0 , 0 , V_16 , V_29 ,
V_25 ) ;
if ( V_15 < 0 )
F_9 ( & V_13 -> V_5 , L_3
L_4 , V_28 , V_15 ) ;
F_13 ( V_16 ) ;
return V_15 ;
}
static int F_14 ( struct V_12 * V_13 ,
unsigned char V_30 )
{
int V_15 ;
unsigned char * V_16 ;
V_16 = F_4 ( V_19 , V_20 ) ;
if ( V_16 == NULL )
return - V_21 ;
V_16 [ 0 ] = V_30 ;
V_15 = F_7 ( V_13 -> V_2 -> V_5 , F_8 ( V_13 -> V_2 -> V_5 , 0 ) ,
V_31 ,
V_23 ,
0 , 0 , V_16 , V_32 ,
V_25 ) ;
if ( V_15 < 0 )
F_9 ( & V_13 -> V_5 , L_6 , V_30 , V_15 ) ;
F_11 ( & V_13 -> V_5 , L_7 , V_30 ) ;
F_13 ( V_16 ) ;
return V_15 ;
}
static int F_15 ( struct V_12 * V_13 ,
unsigned int V_33 )
{
int V_15 ;
unsigned char V_34 ;
unsigned char * V_16 ;
V_16 = F_4 ( V_19 , V_20 ) ;
if ( V_16 == NULL )
return - V_21 ;
V_34 = V_35 ;
if ( V_33 & V_36 )
V_34 |= V_37 ;
if ( V_33 & V_38 )
V_34 |= V_39 ;
V_16 [ 0 ] = V_34 ;
V_15 = F_7 ( V_13 -> V_2 -> V_5 , F_8 ( V_13 -> V_2 -> V_5 , 0 ) ,
V_40 ,
V_23 ,
0 , 0 , V_16 , V_41 ,
V_25 ) ;
F_13 ( V_16 ) ;
F_11 ( & V_13 -> V_5 , L_8 , V_33 , V_34 ) ;
if ( V_15 < 0 ) {
F_9 ( & V_13 -> V_5 , L_9 , V_34 , V_15 ) ;
return V_15 ;
}
return 0 ;
}
static int F_16 ( struct V_12 * V_13 ,
unsigned char * V_42 )
{
int V_15 ;
unsigned char * V_16 ;
V_16 = F_4 ( V_19 , V_20 ) ;
if ( V_16 == NULL ) {
* V_42 = 0 ;
return - V_21 ;
}
V_15 = F_7 ( V_13 -> V_2 -> V_5 , F_17 ( V_13 -> V_2 -> V_5 , 0 ) ,
V_43 ,
V_44 ,
0 , 0 , V_16 , V_45 ,
V_25 ) ;
if ( V_15 < 0 ) {
F_9 ( & V_13 -> V_5 , L_10 , V_15 ) ;
* V_42 = 0 ;
} else {
* V_42 = V_16 [ 0 ] ;
}
F_11 ( & V_13 -> V_5 , L_11 , * V_42 ) ;
F_13 ( V_16 ) ;
return V_15 ;
}
static void F_18 ( struct V_46 * V_47 ,
unsigned char V_42 )
{
if ( V_42 & V_48 )
V_47 -> V_49 ++ ;
if ( V_42 & V_50 )
V_47 -> V_51 ++ ;
if ( V_42 & V_52 )
V_47 -> V_53 ++ ;
if ( V_42 & V_54 )
V_47 -> V_55 ++ ;
}
static void F_19 ( struct V_12 * V_13 ,
unsigned int * V_33 , unsigned char V_42 )
{
if ( V_42 & V_56 )
* V_33 |= V_57 ;
else
* V_33 &= ~ V_57 ;
if ( V_42 & V_58 )
* V_33 |= V_59 ;
else
* V_33 &= ~ V_59 ;
if ( V_42 & V_60 )
* V_33 |= V_61 ;
else
* V_33 &= ~ V_61 ;
if ( V_42 & V_62 )
* V_33 |= V_63 ;
else
* V_33 &= ~ V_63 ;
F_11 ( & V_13 -> V_5 , L_12 , V_42 , * V_33 ) ;
}
static int F_20 ( struct V_12 * V_13 )
{
struct V_64 * V_65 ;
V_65 = F_21 ( sizeof( * V_65 ) , V_20 ) ;
if ( ! V_65 )
return - V_21 ;
V_65 -> V_66 = V_13 -> V_2 -> V_13 [ 1 ] -> V_67 ;
V_65 -> V_66 -> V_68 = V_13 ;
F_22 ( & V_65 -> V_69 ) ;
F_23 ( V_13 , V_65 ) ;
return 0 ;
}
static int F_24 ( struct V_12 * V_13 )
{
struct V_64 * V_65 ;
V_65 = F_25 ( V_13 ) ;
F_13 ( V_65 ) ;
return 0 ;
}
static int F_26 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_64 * V_65 = F_25 ( V_13 ) ;
int V_70 = 0 ;
unsigned int V_33 ;
unsigned long V_71 ;
unsigned char V_72 ;
unsigned char V_73 ;
if ( F_2 ( V_2 -> V_5 -> V_6 . V_7 )
== V_8 )
V_13 -> V_74 = 16 ;
F_27 ( & V_65 -> V_69 , V_71 ) ;
if ( V_11 && ( V_11 -> V_75 . V_76 & V_77 ) )
V_65 -> V_33 = V_36 | V_38 ;
else
V_65 -> V_33 = 0 ;
V_65 -> V_72 = ( V_78 |
V_79 |
V_80 ) ;
V_33 = V_65 -> V_33 ;
V_72 = V_65 -> V_72 ;
F_28 ( & V_65 -> V_69 , V_71 ) ;
F_15 ( V_13 , V_33 ) ;
F_14 ( V_13 , V_72 ) ;
F_16 ( V_13 , & V_73 ) ;
F_27 ( & V_65 -> V_69 , V_71 ) ;
V_65 -> V_73 = V_73 ;
F_19 ( V_13 , & V_65 -> V_33 , V_65 -> V_73 ) ;
F_28 ( & V_65 -> V_69 , V_71 ) ;
V_70 = F_29 ( V_65 -> V_66 , V_20 ) ;
if ( V_70 ) {
F_9 ( & V_13 -> V_5 ,
L_13 ,
V_13 -> V_66 -> V_81 , V_70 ) ;
goto error;
}
V_70 = F_29 ( V_13 -> V_67 , V_20 ) ;
if ( V_70 ) {
F_30 ( V_65 -> V_66 ) ;
F_9 ( & V_13 -> V_5 ,
L_14 ,
V_13 -> V_67 -> V_81 , V_70 ) ;
goto error;
}
return 0 ;
error:
return V_70 ;
}
static void F_31 ( struct V_12 * V_13 , int V_82 )
{
unsigned int V_33 ;
struct V_64 * V_65 = F_25 ( V_13 ) ;
F_32 ( & V_65 -> V_69 ) ;
if ( V_82 )
V_65 -> V_33 |= V_36 | V_38 ;
else
V_65 -> V_33 &= ~ ( V_36 | V_38 ) ;
V_33 = V_65 -> V_33 ;
F_33 ( & V_65 -> V_69 ) ;
F_15 ( V_13 , V_33 ) ;
}
static void F_34 ( struct V_12 * V_13 )
{
struct V_64 * V_65 = F_25 ( V_13 ) ;
F_30 ( V_65 -> V_66 ) ;
F_30 ( V_13 -> V_67 ) ;
F_35 ( V_13 ) ;
}
static void F_36 ( struct V_83 * V_83 )
{
struct V_12 * V_13 = V_83 -> V_68 ;
struct V_64 * V_65 = F_25 ( V_13 ) ;
unsigned char * V_84 = V_83 -> V_85 ;
int V_70 ;
int V_86 = V_83 -> V_86 ;
unsigned long V_71 ;
switch ( V_86 ) {
case 0 :
break;
case - V_87 :
case - V_88 :
case - V_89 :
F_11 ( & V_13 -> V_5 , L_15 ,
V_90 , V_86 ) ;
return;
default:
F_11 ( & V_13 -> V_5 , L_16 ,
V_90 , V_86 ) ;
goto exit;
}
F_37 ( & V_13 -> V_5 , V_90 , V_83 -> V_91 , V_84 ) ;
if ( V_83 -> V_92 > 2 ) {
if ( V_83 -> V_91 ) {
F_38 ( & V_13 -> V_13 , V_84 ,
V_83 -> V_91 ) ;
F_39 ( & V_13 -> V_13 ) ;
}
goto exit;
}
F_27 ( & V_65 -> V_69 , V_71 ) ;
V_65 -> V_73 = V_84 [ V_93 ] ;
F_19 ( V_13 , & V_65 -> V_33 , V_65 -> V_73 ) ;
F_18 ( & V_13 -> V_47 , V_65 -> V_73 ) ;
#if 0
priv->last_lsr = data[MCT_U232_LSR_INDEX];
if (priv->last_lsr & MCT_U232_LSR_ERR) {
tty = tty_port_tty_get(&port->port);
if (priv->last_lsr & MCT_U232_LSR_OE) {
}
if (priv->last_lsr & MCT_U232_LSR_PE) {
}
if (priv->last_lsr & MCT_U232_LSR_FE) {
}
if (priv->last_lsr & MCT_U232_LSR_BI) {
}
tty_kref_put(tty);
}
#endif
F_40 ( & V_13 -> V_13 . V_94 ) ;
F_28 ( & V_65 -> V_69 , V_71 ) ;
exit:
V_70 = F_29 ( V_83 , V_95 ) ;
if ( V_70 )
F_9 ( & V_13 -> V_5 ,
L_17 ,
V_90 , V_70 ) ;
}
static void F_41 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_96 * V_97 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_64 * V_65 = F_25 ( V_13 ) ;
struct V_96 * V_75 = & V_11 -> V_75 ;
unsigned int V_98 = V_75 -> V_76 ;
unsigned int V_99 = V_97 -> V_76 ;
unsigned long V_71 ;
unsigned int V_33 ;
unsigned char V_72 ;
F_27 ( & V_65 -> V_69 , V_71 ) ;
V_33 = V_65 -> V_33 ;
F_28 ( & V_65 -> V_69 , V_71 ) ;
V_72 = 0 ;
if ( ( V_99 & V_77 ) == V_100 ) {
F_11 ( & V_13 -> V_5 , L_18 , V_90 ) ;
V_33 |= V_36 | V_38 ;
F_15 ( V_13 , V_33 ) ;
}
F_3 ( V_11 , V_2 , V_13 , F_42 ( V_11 ) ) ;
if ( ( V_98 & V_77 ) == V_100 ) {
F_11 ( & V_13 -> V_5 , L_19 , V_90 ) ;
V_33 &= ~ ( V_36 | V_38 ) ;
F_15 ( V_13 , V_33 ) ;
}
if ( V_98 & V_101 )
V_72 |= ( V_98 & V_102 ) ?
V_103 : V_104 ;
else
V_72 |= V_79 ;
switch ( V_98 & V_105 ) {
case V_106 :
V_72 |= V_107 ; break;
case V_108 :
V_72 |= V_109 ; break;
case V_110 :
V_72 |= V_111 ; break;
case V_112 :
V_72 |= V_78 ; break;
default:
F_9 ( & V_13 -> V_5 ,
L_20 ) ;
V_72 |= V_78 ;
break;
}
V_75 -> V_76 &= ~ V_113 ;
V_72 |= ( V_98 & V_114 ) ?
V_115 : V_80 ;
F_14 ( V_13 , V_72 ) ;
F_27 ( & V_65 -> V_69 , V_71 ) ;
V_65 -> V_33 = V_33 ;
V_65 -> V_72 = V_72 ;
F_28 ( & V_65 -> V_69 , V_71 ) ;
}
static void F_43 ( struct V_10 * V_11 , int V_116 )
{
struct V_12 * V_13 = V_11 -> V_117 ;
struct V_64 * V_65 = F_25 ( V_13 ) ;
unsigned char V_30 ;
unsigned long V_71 ;
F_27 ( & V_65 -> V_69 , V_71 ) ;
V_30 = V_65 -> V_72 ;
if ( V_116 )
V_30 |= V_118 ;
F_28 ( & V_65 -> V_69 , V_71 ) ;
F_14 ( V_13 , V_30 ) ;
}
static int F_44 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_117 ;
struct V_64 * V_65 = F_25 ( V_13 ) ;
unsigned int V_33 ;
unsigned long V_71 ;
F_27 ( & V_65 -> V_69 , V_71 ) ;
V_33 = V_65 -> V_33 ;
F_28 ( & V_65 -> V_69 , V_71 ) ;
return V_33 ;
}
static int F_45 ( struct V_10 * V_11 ,
unsigned int V_119 , unsigned int V_120 )
{
struct V_12 * V_13 = V_11 -> V_117 ;
struct V_64 * V_65 = F_25 ( V_13 ) ;
unsigned int V_33 ;
unsigned long V_71 ;
F_27 ( & V_65 -> V_69 , V_71 ) ;
V_33 = V_65 -> V_33 ;
if ( V_119 & V_38 )
V_33 |= V_38 ;
if ( V_119 & V_36 )
V_33 |= V_36 ;
if ( V_120 & V_38 )
V_33 &= ~ V_38 ;
if ( V_120 & V_36 )
V_33 &= ~ V_36 ;
V_65 -> V_33 = V_33 ;
F_28 ( & V_65 -> V_69 , V_71 ) ;
return F_15 ( V_13 , V_33 ) ;
}
static void F_46 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_117 ;
struct V_64 * V_65 = F_25 ( V_13 ) ;
unsigned int V_33 ;
F_32 ( & V_65 -> V_69 ) ;
V_65 -> V_121 |= V_122 ;
if ( F_12 ( V_11 ) ) {
V_65 -> V_33 &= ~ V_38 ;
V_33 = V_65 -> V_33 ;
F_33 ( & V_65 -> V_69 ) ;
F_15 ( V_13 , V_33 ) ;
} else {
F_33 ( & V_65 -> V_69 ) ;
}
}
static void F_47 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_117 ;
struct V_64 * V_65 = F_25 ( V_13 ) ;
unsigned int V_33 ;
F_32 ( & V_65 -> V_69 ) ;
if ( ( V_65 -> V_121 & V_122 ) && F_12 ( V_11 ) ) {
V_65 -> V_121 &= ~ V_122 ;
V_65 -> V_33 |= V_38 ;
V_33 = V_65 -> V_33 ;
F_33 ( & V_65 -> V_69 ) ;
F_15 ( V_13 , V_33 ) ;
} else {
F_33 ( & V_65 -> V_69 ) ;
}
}
