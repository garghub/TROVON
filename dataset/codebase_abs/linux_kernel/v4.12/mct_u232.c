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
F_5 ( V_14 , V_16 ) ;
V_15 = F_6 ( V_2 -> V_5 , F_7 ( V_2 -> V_5 , 0 ) ,
V_22 ,
V_23 ,
0 , 0 , V_16 , V_24 ,
V_25 ) ;
if ( V_15 < 0 )
F_8 ( & V_13 -> V_5 , L_1 ,
V_3 , V_15 ) ;
else
F_9 ( V_11 , V_18 , V_18 ) ;
F_10 ( & V_13 -> V_5 , L_2 , V_3 , V_14 ) ;
V_16 [ 0 ] = 0 ;
V_15 = F_6 ( V_2 -> V_5 , F_7 ( V_2 -> V_5 , 0 ) ,
V_26 ,
V_23 ,
0 , 0 , V_16 , V_27 ,
V_25 ) ;
if ( V_15 < 0 )
F_8 ( & V_13 -> V_5 , L_3
L_4 , V_26 ,
V_15 ) ;
if ( V_13 && F_11 ( V_11 ) )
V_17 = 1 ;
F_10 ( & V_13 -> V_5 , L_5 ,
V_17 ) ;
V_16 [ 0 ] = V_17 ;
V_15 = F_6 ( V_2 -> V_5 , F_7 ( V_2 -> V_5 , 0 ) ,
V_28 ,
V_23 ,
0 , 0 , V_16 , V_29 ,
V_25 ) ;
if ( V_15 < 0 )
F_8 ( & V_13 -> V_5 , L_3
L_4 , V_28 , V_15 ) ;
F_12 ( V_16 ) ;
return V_15 ;
}
static int F_13 ( struct V_12 * V_13 ,
unsigned char V_30 )
{
int V_15 ;
unsigned char * V_16 ;
V_16 = F_4 ( V_19 , V_20 ) ;
if ( V_16 == NULL )
return - V_21 ;
V_16 [ 0 ] = V_30 ;
V_15 = F_6 ( V_13 -> V_2 -> V_5 , F_7 ( V_13 -> V_2 -> V_5 , 0 ) ,
V_31 ,
V_23 ,
0 , 0 , V_16 , V_32 ,
V_25 ) ;
if ( V_15 < 0 )
F_8 ( & V_13 -> V_5 , L_6 , V_30 , V_15 ) ;
F_10 ( & V_13 -> V_5 , L_7 , V_30 ) ;
F_12 ( V_16 ) ;
return V_15 ;
}
static int F_14 ( struct V_12 * V_13 ,
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
V_15 = F_6 ( V_13 -> V_2 -> V_5 , F_7 ( V_13 -> V_2 -> V_5 , 0 ) ,
V_40 ,
V_23 ,
0 , 0 , V_16 , V_41 ,
V_25 ) ;
F_12 ( V_16 ) ;
F_10 ( & V_13 -> V_5 , L_8 , V_33 , V_34 ) ;
if ( V_15 < 0 ) {
F_8 ( & V_13 -> V_5 , L_9 , V_34 , V_15 ) ;
return V_15 ;
}
return 0 ;
}
static int F_15 ( struct V_12 * V_13 ,
unsigned char * V_42 )
{
int V_15 ;
unsigned char * V_16 ;
V_16 = F_4 ( V_19 , V_20 ) ;
if ( V_16 == NULL ) {
* V_42 = 0 ;
return - V_21 ;
}
V_15 = F_6 ( V_13 -> V_2 -> V_5 , F_16 ( V_13 -> V_2 -> V_5 , 0 ) ,
V_43 ,
V_44 ,
0 , 0 , V_16 , V_45 ,
V_25 ) ;
if ( V_15 < V_45 ) {
F_8 ( & V_13 -> V_5 , L_10 , V_15 ) ;
if ( V_15 >= 0 )
V_15 = - V_46 ;
* V_42 = 0 ;
} else {
* V_42 = V_16 [ 0 ] ;
}
F_10 ( & V_13 -> V_5 , L_11 , * V_42 ) ;
F_12 ( V_16 ) ;
return V_15 ;
}
static void F_17 ( struct V_47 * V_48 ,
unsigned char V_42 )
{
if ( V_42 & V_49 )
V_48 -> V_50 ++ ;
if ( V_42 & V_51 )
V_48 -> V_52 ++ ;
if ( V_42 & V_53 )
V_48 -> V_54 ++ ;
if ( V_42 & V_55 )
V_48 -> V_56 ++ ;
}
static void F_18 ( struct V_12 * V_13 ,
unsigned int * V_33 , unsigned char V_42 )
{
if ( V_42 & V_57 )
* V_33 |= V_58 ;
else
* V_33 &= ~ V_58 ;
if ( V_42 & V_59 )
* V_33 |= V_60 ;
else
* V_33 &= ~ V_60 ;
if ( V_42 & V_61 )
* V_33 |= V_62 ;
else
* V_33 &= ~ V_62 ;
if ( V_42 & V_63 )
* V_33 |= V_64 ;
else
* V_33 &= ~ V_64 ;
F_10 ( & V_13 -> V_5 , L_12 , V_42 , * V_33 ) ;
}
static int F_19 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_65 * V_66 ;
if ( ! V_2 -> V_13 [ 1 ] || ! V_2 -> V_13 [ 1 ] -> V_67 ) {
F_8 ( & V_13 -> V_5 , L_13 ) ;
return - V_68 ;
}
V_66 = F_20 ( sizeof( * V_66 ) , V_20 ) ;
if ( ! V_66 )
return - V_21 ;
V_66 -> V_69 = V_2 -> V_13 [ 1 ] -> V_67 ;
V_66 -> V_69 -> V_70 = V_13 ;
F_21 ( & V_66 -> V_71 ) ;
F_22 ( V_13 , V_66 ) ;
return 0 ;
}
static int F_23 ( struct V_12 * V_13 )
{
struct V_65 * V_66 ;
V_66 = F_24 ( V_13 ) ;
F_12 ( V_66 ) ;
return 0 ;
}
static int F_25 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_65 * V_66 = F_24 ( V_13 ) ;
int V_72 = 0 ;
unsigned int V_33 ;
unsigned long V_73 ;
unsigned char V_74 ;
unsigned char V_75 ;
if ( F_2 ( V_2 -> V_5 -> V_6 . V_7 )
== V_8 )
V_13 -> V_76 = 16 ;
F_26 ( & V_66 -> V_71 , V_73 ) ;
if ( V_11 && F_27 ( V_11 ) )
V_66 -> V_33 = V_36 | V_38 ;
else
V_66 -> V_33 = 0 ;
V_66 -> V_74 = ( V_77 |
V_78 |
V_79 ) ;
V_33 = V_66 -> V_33 ;
V_74 = V_66 -> V_74 ;
F_28 ( & V_66 -> V_71 , V_73 ) ;
F_14 ( V_13 , V_33 ) ;
F_13 ( V_13 , V_74 ) ;
F_15 ( V_13 , & V_75 ) ;
F_26 ( & V_66 -> V_71 , V_73 ) ;
V_66 -> V_75 = V_75 ;
F_18 ( V_13 , & V_66 -> V_33 , V_66 -> V_75 ) ;
F_28 ( & V_66 -> V_71 , V_73 ) ;
V_72 = F_29 ( V_66 -> V_69 , V_20 ) ;
if ( V_72 ) {
F_8 ( & V_13 -> V_5 ,
L_14 ,
V_13 -> V_69 -> V_80 , V_72 ) ;
goto error;
}
V_72 = F_29 ( V_13 -> V_67 , V_20 ) ;
if ( V_72 ) {
F_30 ( V_66 -> V_69 ) ;
F_8 ( & V_13 -> V_5 ,
L_15 ,
V_13 -> V_67 -> V_80 , V_72 ) ;
goto error;
}
return 0 ;
error:
return V_72 ;
}
static void F_31 ( struct V_12 * V_13 , int V_81 )
{
unsigned int V_33 ;
struct V_65 * V_66 = F_24 ( V_13 ) ;
F_32 ( & V_66 -> V_71 ) ;
if ( V_81 )
V_66 -> V_33 |= V_36 | V_38 ;
else
V_66 -> V_33 &= ~ ( V_36 | V_38 ) ;
V_33 = V_66 -> V_33 ;
F_33 ( & V_66 -> V_71 ) ;
F_14 ( V_13 , V_33 ) ;
}
static void F_34 ( struct V_12 * V_13 )
{
struct V_65 * V_66 = F_24 ( V_13 ) ;
F_30 ( V_66 -> V_69 ) ;
F_30 ( V_13 -> V_67 ) ;
F_35 ( V_13 ) ;
}
static void F_36 ( struct V_82 * V_82 )
{
struct V_12 * V_13 = V_82 -> V_70 ;
struct V_65 * V_66 = F_24 ( V_13 ) ;
unsigned char * V_83 = V_82 -> V_84 ;
int V_72 ;
int V_85 = V_82 -> V_85 ;
unsigned long V_73 ;
switch ( V_85 ) {
case 0 :
break;
case - V_86 :
case - V_87 :
case - V_88 :
F_10 ( & V_13 -> V_5 , L_16 ,
V_89 , V_85 ) ;
return;
default:
F_10 ( & V_13 -> V_5 , L_17 ,
V_89 , V_85 ) ;
goto exit;
}
F_37 ( & V_13 -> V_5 , V_89 , V_82 -> V_90 , V_83 ) ;
if ( V_82 -> V_91 > 2 ) {
if ( V_82 -> V_90 ) {
F_38 ( & V_13 -> V_13 , V_83 ,
V_82 -> V_90 ) ;
F_39 ( & V_13 -> V_13 ) ;
}
goto exit;
}
F_26 ( & V_66 -> V_71 , V_73 ) ;
V_66 -> V_75 = V_83 [ V_92 ] ;
F_18 ( V_13 , & V_66 -> V_33 , V_66 -> V_75 ) ;
F_17 ( & V_13 -> V_48 , V_66 -> V_75 ) ;
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
F_40 ( & V_13 -> V_13 . V_93 ) ;
F_28 ( & V_66 -> V_71 , V_73 ) ;
exit:
V_72 = F_29 ( V_82 , V_94 ) ;
if ( V_72 )
F_8 ( & V_13 -> V_5 ,
L_18 ,
V_89 , V_72 ) ;
}
static void F_41 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_65 * V_66 = F_24 ( V_13 ) ;
struct V_95 * V_97 = & V_11 -> V_97 ;
unsigned int V_98 = V_97 -> V_99 ;
unsigned int V_100 = V_96 -> V_99 ;
unsigned long V_73 ;
unsigned int V_33 ;
unsigned char V_74 ;
F_26 ( & V_66 -> V_71 , V_73 ) ;
V_33 = V_66 -> V_33 ;
F_28 ( & V_66 -> V_71 , V_73 ) ;
V_74 = 0 ;
if ( ( V_100 & V_101 ) == V_102 ) {
F_10 ( & V_13 -> V_5 , L_19 , V_89 ) ;
V_33 |= V_36 | V_38 ;
F_14 ( V_13 , V_33 ) ;
}
F_3 ( V_11 , V_2 , V_13 , F_42 ( V_11 ) ) ;
if ( ( V_98 & V_101 ) == V_102 ) {
F_10 ( & V_13 -> V_5 , L_20 , V_89 ) ;
V_33 &= ~ ( V_36 | V_38 ) ;
F_14 ( V_13 , V_33 ) ;
}
if ( V_98 & V_103 )
V_74 |= ( V_98 & V_104 ) ?
V_105 : V_106 ;
else
V_74 |= V_78 ;
switch ( V_98 & V_107 ) {
case V_108 :
V_74 |= V_109 ; break;
case V_110 :
V_74 |= V_111 ; break;
case V_112 :
V_74 |= V_113 ; break;
case V_114 :
V_74 |= V_77 ; break;
default:
F_8 ( & V_13 -> V_5 ,
L_21 ) ;
V_74 |= V_77 ;
break;
}
V_97 -> V_99 &= ~ V_115 ;
V_74 |= ( V_98 & V_116 ) ?
V_117 : V_79 ;
F_13 ( V_13 , V_74 ) ;
F_26 ( & V_66 -> V_71 , V_73 ) ;
V_66 -> V_33 = V_33 ;
V_66 -> V_74 = V_74 ;
F_28 ( & V_66 -> V_71 , V_73 ) ;
}
static void F_43 ( struct V_10 * V_11 , int V_118 )
{
struct V_12 * V_13 = V_11 -> V_119 ;
struct V_65 * V_66 = F_24 ( V_13 ) ;
unsigned char V_30 ;
unsigned long V_73 ;
F_26 ( & V_66 -> V_71 , V_73 ) ;
V_30 = V_66 -> V_74 ;
if ( V_118 )
V_30 |= V_120 ;
F_28 ( & V_66 -> V_71 , V_73 ) ;
F_13 ( V_13 , V_30 ) ;
}
static int F_44 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_119 ;
struct V_65 * V_66 = F_24 ( V_13 ) ;
unsigned int V_33 ;
unsigned long V_73 ;
F_26 ( & V_66 -> V_71 , V_73 ) ;
V_33 = V_66 -> V_33 ;
F_28 ( & V_66 -> V_71 , V_73 ) ;
return V_33 ;
}
static int F_45 ( struct V_10 * V_11 ,
unsigned int V_121 , unsigned int V_122 )
{
struct V_12 * V_13 = V_11 -> V_119 ;
struct V_65 * V_66 = F_24 ( V_13 ) ;
unsigned int V_33 ;
unsigned long V_73 ;
F_26 ( & V_66 -> V_71 , V_73 ) ;
V_33 = V_66 -> V_33 ;
if ( V_121 & V_38 )
V_33 |= V_38 ;
if ( V_121 & V_36 )
V_33 |= V_36 ;
if ( V_122 & V_38 )
V_33 &= ~ V_38 ;
if ( V_122 & V_36 )
V_33 &= ~ V_36 ;
V_66 -> V_33 = V_33 ;
F_28 ( & V_66 -> V_71 , V_73 ) ;
return F_14 ( V_13 , V_33 ) ;
}
static void F_46 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_119 ;
struct V_65 * V_66 = F_24 ( V_13 ) ;
unsigned int V_33 ;
F_32 ( & V_66 -> V_71 ) ;
V_66 -> V_123 |= V_124 ;
if ( F_11 ( V_11 ) ) {
V_66 -> V_33 &= ~ V_38 ;
V_33 = V_66 -> V_33 ;
F_33 ( & V_66 -> V_71 ) ;
F_14 ( V_13 , V_33 ) ;
} else {
F_33 ( & V_66 -> V_71 ) ;
}
}
static void F_47 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_119 ;
struct V_65 * V_66 = F_24 ( V_13 ) ;
unsigned int V_33 ;
F_32 ( & V_66 -> V_71 ) ;
if ( ( V_66 -> V_123 & V_124 ) && F_11 ( V_11 ) ) {
V_66 -> V_123 &= ~ V_124 ;
V_66 -> V_33 |= V_38 ;
V_33 = V_66 -> V_33 ;
F_33 ( & V_66 -> V_71 ) ;
F_14 ( V_13 , V_33 ) ;
} else {
F_33 ( & V_66 -> V_71 ) ;
}
}
