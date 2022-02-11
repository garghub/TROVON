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
V_6 -> V_6 . V_14 = 256 ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
V_8 = F_9 ( V_6 ) ;
F_10 ( V_8 ) ;
return 0 ;
}
static int F_11 ( struct V_5 * V_6 , T_1 V_15 )
{
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_16 * V_17 = V_6 -> V_2 -> V_17 ;
int V_18 ;
if ( V_8 -> V_12 & V_19 )
return - V_20 ;
V_18 = F_12 ( V_17 , F_13 ( V_17 , 0 ) ,
V_21 , V_22 ,
V_15 , 0x04 , NULL , 0 , 100 ) ;
if ( V_18 != 0 ) {
F_14 ( & V_6 -> V_17 , L_1 ,
V_18 ) ;
}
return V_18 ;
}
static int F_15 ( struct V_5 * V_6 , T_1 * V_23 )
{
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_16 * V_17 = V_6 -> V_2 -> V_17 ;
T_1 * V_24 ;
int V_25 ;
if ( V_8 -> V_12 & V_19 )
return - V_20 ;
V_24 = F_5 ( 1 , V_9 ) ;
if ( ! V_24 )
return - V_10 ;
V_25 = F_12 ( V_17 , F_16 ( V_17 , 0 ) ,
V_26 , V_27 ,
0 , V_28 , V_24 , 1 , 100 ) ;
if ( V_25 < 0 )
F_14 ( & V_6 -> V_17 , L_2 , V_25 ) ;
F_17 ( & V_6 -> V_17 , L_3 , V_25 , * V_24 ) ;
* V_23 = * V_24 ;
F_10 ( V_24 ) ;
return V_25 ;
}
static void F_18 ( struct V_5 * V_6 , T_2 V_29 ,
T_2 V_30 )
{
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_16 * V_17 = V_6 -> V_2 -> V_17 ;
int V_25 ;
if ( V_8 -> V_12 & V_31 )
return;
V_25 = F_12 ( V_17 , F_13 ( V_17 , 0 ) ,
V_32 , V_33 ,
V_29 , V_30 , NULL , 0 , 100 ) ;
F_17 ( & V_6 -> V_17 , L_4 , V_29 , V_30 ) ;
if ( V_25 < 0 )
F_14 ( & V_6 -> V_17 , L_5 , V_25 ) ;
}
static int F_19 ( struct V_5 * V_6 )
{
T_1 V_34 ;
int V_25 ;
V_25 = F_15 ( V_6 , & V_34 ) ;
if ( V_25 || V_34 & V_35 )
return 1 ;
return 0 ;
}
static void F_20 ( struct V_5 * V_6 , int V_36 )
{
struct V_7 * V_8 = F_9 ( V_6 ) ;
unsigned long V_37 ;
T_1 V_38 ;
F_21 ( & V_8 -> V_11 , V_37 ) ;
if ( V_36 )
V_8 -> V_39 = V_40
| V_41 ;
else
V_8 -> V_39 &= ~ ( V_40
| V_41 ) ;
V_38 = V_8 -> V_39 ;
F_22 ( & V_8 -> V_11 , V_37 ) ;
F_11 ( V_6 , V_38 ) ;
}
static void F_23 ( struct V_42 * V_43 )
{
V_43 -> V_44 = V_45 ;
V_43 -> V_44 . V_46 = V_47 | V_48 | V_49 | V_50 | V_51 ;
V_43 -> V_44 . V_52 = 115200 ;
V_43 -> V_44 . V_53 = 115200 ;
}
static void F_24 ( struct V_42 * V_43 ,
struct V_5 * V_6 , struct V_54 * V_55 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
unsigned long V_37 ;
unsigned int V_56 = V_43 -> V_44 . V_46 ;
unsigned short V_57 ;
unsigned char V_24 [ 2 ] = { 0 , 0 } ;
int V_58 ;
int V_59 ;
T_1 V_38 ;
if ( V_55 && ! F_25 ( & V_43 -> V_44 , V_55 ) )
return;
F_21 ( & V_8 -> V_11 , V_37 ) ;
V_38 = V_8 -> V_39 ;
if ( V_55 && ( V_55 -> V_46 & V_60 ) == V_61 ) {
V_8 -> V_39 |= V_62 ;
if ( ! ( V_55 -> V_46 & V_63 ) )
V_8 -> V_39 |= V_64 ;
}
if ( V_38 != V_8 -> V_39 ) {
V_38 = V_8 -> V_39 ;
F_22 ( & V_8 -> V_11 , V_37 ) ;
F_11 ( V_6 , V_38 ) ;
} else {
F_22 ( & V_8 -> V_11 , V_37 ) ;
}
V_58 = F_26 ( V_43 ) ;
switch ( V_58 ) {
case 300 : V_24 [ 0 ] = 0x00 ; break;
case 600 : V_24 [ 0 ] = 0x01 ; break;
case 1200 : V_24 [ 0 ] = 0x02 ; break;
case 2400 : V_24 [ 0 ] = 0x03 ; break;
case 4800 : V_24 [ 0 ] = 0x04 ; break;
case 9600 : V_24 [ 0 ] = 0x05 ; break;
case 19200 : V_24 [ 0 ] = 0x07 ; break;
case 38400 : V_24 [ 0 ] = 0x09 ; break;
case 57600 : V_24 [ 0 ] = 0x0a ; break;
case 115200 : V_24 [ 0 ] = 0x0b ; break;
case 230400 : V_24 [ 0 ] = 0x0c ; break;
case 460800 : V_24 [ 0 ] = 0x0d ; break;
case 921600 : V_24 [ 0 ] = 0x0e ; break;
case 3000000 : V_24 [ 0 ] = 0x11 ; break;
case 0 :
case 1000000 :
V_24 [ 0 ] = 0x0b ; break;
default:
F_14 ( & V_6 -> V_17 , L_6 ) ;
}
switch ( V_56 & V_65 ) {
case V_66 :
V_24 [ 1 ] |= V_67 ;
break;
case V_68 :
V_24 [ 1 ] |= V_69 ;
break;
case V_70 :
V_24 [ 1 ] |= V_71 ;
break;
default:
case V_48 :
V_24 [ 1 ] |= V_72 ;
break;
}
V_24 [ 1 ] |= ( V_56 & V_73 ) ? V_74 :
V_75 ;
if ( V_56 & V_76 ) {
V_24 [ 1 ] |= ( V_56 & V_77 ) ?
V_78 : V_79 ;
} else {
V_24 [ 1 ] |= V_80 ;
}
V_57 = V_24 [ 0 ] | V_24 [ 1 ] << 8 ;
V_59 = F_12 ( V_2 -> V_17 , F_13 ( V_2 -> V_17 , 0 ) ,
V_81 , V_82 ,
V_57 , 0 , NULL , 0 , 100 ) ;
if ( V_59 < 0 )
F_14 ( & V_6 -> V_17 , L_7 ,
V_57 , V_59 ) ;
F_17 ( & V_6 -> V_17 , L_8 , V_59 ) ;
if ( V_56 & V_63 ) {
F_18 ( V_6 , 0x000a , V_83 ) ;
}
}
static int F_27 ( struct V_42 * V_43 , struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
int V_25 ;
F_28 ( V_2 -> V_17 , V_6 -> V_84 -> V_85 ) ;
F_28 ( V_2 -> V_17 , V_6 -> V_86 -> V_85 ) ;
V_25 = F_12 ( V_2 -> V_17 , F_13 ( V_2 -> V_17 , 0 ) ,
0x09 , 0x00 ,
0x01 , 0x00 , NULL , 0x00 , 100 ) ;
if ( V_25 )
return V_25 ;
F_11 ( V_6 , V_8 -> V_39 ) ;
if ( V_43 )
F_24 ( V_43 , V_6 , NULL ) ;
return F_29 ( V_43 , V_6 ) ;
}
static int F_30 ( struct V_42 * V_43 ,
unsigned int V_87 , unsigned int V_88 )
{
struct V_5 * V_6 = V_43 -> V_89 ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
unsigned long V_37 ;
T_1 V_38 ;
F_21 ( & V_8 -> V_11 , V_37 ) ;
if ( V_87 & V_90 )
V_8 -> V_39 |= V_64 ;
if ( V_87 & V_91 )
V_8 -> V_39 |= V_62 ;
if ( V_88 & V_90 )
V_8 -> V_39 &= ~ V_64 ;
if ( V_88 & V_91 )
V_8 -> V_39 &= ~ V_62 ;
V_38 = V_8 -> V_39 ;
F_22 ( & V_8 -> V_11 , V_37 ) ;
return F_11 ( V_6 , V_38 ) ;
}
static int F_31 ( struct V_42 * V_43 )
{
struct V_5 * V_6 = V_43 -> V_89 ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
unsigned long V_37 ;
unsigned int V_15 ;
T_1 V_23 ;
unsigned int V_92 ;
V_92 = F_15 ( V_6 , & V_23 ) ;
if ( V_92 )
return V_92 ;
F_21 ( & V_8 -> V_11 , V_37 ) ;
V_15 = V_8 -> V_39 ;
F_22 ( & V_8 -> V_11 , V_37 ) ;
V_92 = ( ( V_15 & V_62 ) ? V_91 : 0 )
| ( ( V_15 & V_64 ) ? V_90 : 0 )
| ( ( V_23 & V_93 ) ? V_94 : 0 )
| ( ( V_23 & V_95 ) ? V_96 : 0 )
| ( ( V_23 & V_97 ) ? V_98 : 0 )
| ( ( V_23 & V_35 ) ? V_99 : 0 ) ;
return V_92 ;
}
