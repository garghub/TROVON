static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
F_2 ( V_2 , ( void * ) V_4 ) ;
return 0 ;
}
static int F_3 ( struct V_5 * V_6 )
{
const struct V_3 * V_4 = F_4 ( V_6 -> V_2 ) ;
struct V_7 * V_8 ;
V_8 = F_5 ( sizeof( * V_8 ) , V_9 ) ;
if ( ! V_8 )
return - V_10 ;
F_6 ( & V_8 -> V_11 ) ;
V_8 -> V_12 = V_4 -> V_13 ;
F_7 ( V_6 , V_8 ) ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
V_8 = F_9 ( V_6 ) ;
F_10 ( V_8 ) ;
return 0 ;
}
static int F_11 ( struct V_5 * V_6 , T_1 V_14 )
{
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_15 * V_16 = V_6 -> V_2 -> V_16 ;
int V_17 ;
if ( V_8 -> V_12 & V_18 )
return - V_19 ;
V_17 = F_12 ( V_16 , F_13 ( V_16 , 0 ) ,
V_20 , V_21 ,
V_14 , 0x04 , NULL , 0 , 100 ) ;
if ( V_17 != 0 ) {
F_14 ( & V_6 -> V_16 , L_1 ,
V_17 ) ;
}
return V_17 ;
}
static int F_15 ( struct V_5 * V_6 , T_1 * V_22 )
{
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_15 * V_16 = V_6 -> V_2 -> V_16 ;
T_1 * V_23 ;
int V_24 ;
if ( V_8 -> V_12 & V_18 )
return - V_19 ;
V_23 = F_5 ( 1 , V_9 ) ;
if ( ! V_23 )
return - V_10 ;
V_24 = F_12 ( V_16 , F_16 ( V_16 , 0 ) ,
V_25 , V_26 ,
0 , V_27 , V_23 , 1 , 100 ) ;
if ( V_24 < 0 )
F_14 ( & V_6 -> V_16 , L_2 , V_24 ) ;
F_17 ( & V_6 -> V_16 , L_3 , V_24 , * V_23 ) ;
* V_22 = * V_23 ;
F_10 ( V_23 ) ;
return V_24 ;
}
static void F_18 ( struct V_5 * V_6 , T_2 V_28 ,
T_2 V_29 )
{
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_15 * V_16 = V_6 -> V_2 -> V_16 ;
int V_24 ;
if ( V_8 -> V_12 & V_30 )
return;
V_24 = F_12 ( V_16 , F_13 ( V_16 , 0 ) ,
V_31 , V_32 ,
V_28 , V_29 , NULL , 0 , 100 ) ;
F_17 ( & V_6 -> V_16 , L_4 , V_28 , V_29 ) ;
if ( V_24 < 0 )
F_14 ( & V_6 -> V_16 , L_5 , V_24 ) ;
}
static int F_19 ( struct V_5 * V_6 )
{
T_1 V_33 ;
int V_24 ;
V_24 = F_15 ( V_6 , & V_33 ) ;
if ( V_24 || V_33 & V_34 )
return 1 ;
return 0 ;
}
static void F_20 ( struct V_5 * V_6 , int V_35 )
{
struct V_7 * V_8 = F_9 ( V_6 ) ;
unsigned long V_36 ;
T_1 V_37 ;
F_21 ( & V_8 -> V_11 , V_36 ) ;
if ( V_35 )
V_8 -> V_38 = V_39
| V_40 ;
else
V_8 -> V_38 &= ~ ( V_39
| V_40 ) ;
V_37 = V_8 -> V_38 ;
F_22 ( & V_8 -> V_11 , V_36 ) ;
F_11 ( V_6 , V_37 ) ;
}
static void F_23 ( struct V_41 * V_42 )
{
V_42 -> V_43 = V_44 ;
V_42 -> V_43 . V_45 = V_46 | V_47 | V_48 | V_49 | V_50 ;
V_42 -> V_43 . V_51 = 115200 ;
V_42 -> V_43 . V_52 = 115200 ;
}
static void F_24 ( struct V_41 * V_42 ,
struct V_5 * V_6 , struct V_53 * V_54 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
unsigned long V_36 ;
unsigned int V_55 = V_42 -> V_43 . V_45 ;
unsigned short V_56 ;
unsigned char V_23 [ 2 ] = { 0 , 0 } ;
int V_57 ;
int V_58 ;
T_1 V_37 ;
if ( V_54 && ! F_25 ( & V_42 -> V_43 , V_54 ) )
return;
F_21 ( & V_8 -> V_11 , V_36 ) ;
V_37 = V_8 -> V_38 ;
if ( V_54 && ( V_54 -> V_45 & V_59 ) == V_60 ) {
V_8 -> V_38 |= V_61 ;
if ( ! ( V_54 -> V_45 & V_62 ) )
V_8 -> V_38 |= V_63 ;
}
if ( V_37 != V_8 -> V_38 ) {
V_37 = V_8 -> V_38 ;
F_22 ( & V_8 -> V_11 , V_36 ) ;
F_11 ( V_6 , V_37 ) ;
} else {
F_22 ( & V_8 -> V_11 , V_36 ) ;
}
V_57 = F_26 ( V_42 ) ;
switch ( V_57 ) {
case 300 : V_23 [ 0 ] = 0x00 ; break;
case 600 : V_23 [ 0 ] = 0x01 ; break;
case 1200 : V_23 [ 0 ] = 0x02 ; break;
case 2400 : V_23 [ 0 ] = 0x03 ; break;
case 4800 : V_23 [ 0 ] = 0x04 ; break;
case 9600 : V_23 [ 0 ] = 0x05 ; break;
case 19200 : V_23 [ 0 ] = 0x07 ; break;
case 38400 : V_23 [ 0 ] = 0x09 ; break;
case 57600 : V_23 [ 0 ] = 0x0a ; break;
case 115200 : V_23 [ 0 ] = 0x0b ; break;
case 230400 : V_23 [ 0 ] = 0x0c ; break;
case 460800 : V_23 [ 0 ] = 0x0d ; break;
case 921600 : V_23 [ 0 ] = 0x0e ; break;
case 3000000 : V_23 [ 0 ] = 0x11 ; break;
case 0 :
case 1000000 :
V_23 [ 0 ] = 0x0b ; break;
default:
F_14 ( & V_6 -> V_16 , L_6
L_7 ) ;
}
if ( V_55 & V_64 ) {
switch ( V_55 & V_64 ) {
case V_65 :
V_23 [ 1 ] |= V_66 ;
break;
case V_67 :
V_23 [ 1 ] |= V_68 ;
break;
case V_69 :
V_23 [ 1 ] |= V_70 ;
break;
default:
case V_47 :
V_23 [ 1 ] |= V_71 ;
break;
}
}
V_23 [ 1 ] |= ( V_55 & V_72 ) ? V_73 :
V_74 ;
if ( V_55 & V_75 ) {
V_23 [ 1 ] |= ( V_55 & V_76 ) ?
V_77 : V_78 ;
} else {
V_23 [ 1 ] |= V_79 ;
}
V_56 = V_23 [ 0 ] | V_23 [ 1 ] << 8 ;
V_58 = F_12 ( V_2 -> V_16 , F_13 ( V_2 -> V_16 , 0 ) ,
V_80 , V_81 ,
V_56 , 0 , NULL , 0 , 100 ) ;
if ( V_58 < 0 )
F_14 ( & V_6 -> V_16 , L_8 ,
V_56 , V_58 ) ;
F_17 ( & V_6 -> V_16 , L_9 , V_58 ) ;
if ( V_55 & V_62 ) {
F_18 ( V_6 , 0x000a , V_82 ) ;
}
}
static int F_27 ( struct V_41 * V_42 , struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
int V_24 ;
F_28 ( V_2 -> V_16 , V_6 -> V_83 -> V_84 ) ;
F_28 ( V_2 -> V_16 , V_6 -> V_85 -> V_84 ) ;
V_24 = F_12 ( V_2 -> V_16 , F_13 ( V_2 -> V_16 , 0 ) ,
0x09 , 0x00 ,
0x01 , 0x00 , NULL , 0x00 , 100 ) ;
if ( V_24 )
return V_24 ;
F_11 ( V_6 , V_8 -> V_38 ) ;
if ( V_42 )
F_24 ( V_42 , V_6 , NULL ) ;
V_6 -> V_6 . V_86 = 256 ;
return F_29 ( V_42 , V_6 ) ;
}
static int F_30 ( struct V_41 * V_42 ,
unsigned int V_87 , unsigned int V_88 )
{
struct V_5 * V_6 = V_42 -> V_89 ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
unsigned long V_36 ;
T_1 V_37 ;
F_21 ( & V_8 -> V_11 , V_36 ) ;
if ( V_87 & V_90 )
V_8 -> V_38 |= V_63 ;
if ( V_87 & V_91 )
V_8 -> V_38 |= V_61 ;
if ( V_88 & V_90 )
V_8 -> V_38 &= ~ V_63 ;
if ( V_88 & V_91 )
V_8 -> V_38 &= ~ V_61 ;
V_37 = V_8 -> V_38 ;
F_22 ( & V_8 -> V_11 , V_36 ) ;
return F_11 ( V_6 , V_37 ) ;
}
static int F_31 ( struct V_41 * V_42 )
{
struct V_5 * V_6 = V_42 -> V_89 ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
unsigned long V_36 ;
unsigned int V_14 ;
T_1 V_22 ;
unsigned int V_92 ;
V_92 = F_15 ( V_6 , & V_22 ) ;
if ( V_92 )
return V_92 ;
F_21 ( & V_8 -> V_11 , V_36 ) ;
V_14 = V_8 -> V_38 ;
F_22 ( & V_8 -> V_11 , V_36 ) ;
V_92 = ( ( V_14 & V_61 ) ? V_91 : 0 )
| ( ( V_14 & V_63 ) ? V_90 : 0 )
| ( ( V_22 & V_93 ) ? V_94 : 0 )
| ( ( V_22 & V_95 ) ? V_96 : 0 )
| ( ( V_22 & V_97 ) ? V_98 : 0 )
| ( ( V_22 & V_34 ) ? V_99 : 0 ) ;
return V_92 ;
}
