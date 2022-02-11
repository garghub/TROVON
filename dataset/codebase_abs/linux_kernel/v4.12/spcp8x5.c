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
if ( V_25 < 1 ) {
F_14 ( & V_6 -> V_17 , L_2 , V_25 ) ;
if ( V_25 >= 0 )
V_25 = - V_29 ;
goto V_30;
}
F_17 ( & V_6 -> V_17 , L_3 , V_25 , * V_24 ) ;
* V_23 = * V_24 ;
V_25 = 0 ;
V_30:
F_10 ( V_24 ) ;
return V_25 ;
}
static void F_18 ( struct V_5 * V_6 , T_2 V_31 ,
T_2 V_32 )
{
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_16 * V_17 = V_6 -> V_2 -> V_17 ;
int V_25 ;
if ( V_8 -> V_12 & V_33 )
return;
V_25 = F_12 ( V_17 , F_13 ( V_17 , 0 ) ,
V_34 , V_35 ,
V_31 , V_32 , NULL , 0 , 100 ) ;
F_17 ( & V_6 -> V_17 , L_4 , V_31 , V_32 ) ;
if ( V_25 < 0 )
F_14 ( & V_6 -> V_17 , L_5 , V_25 ) ;
}
static int F_19 ( struct V_5 * V_6 )
{
T_1 V_36 ;
int V_25 ;
V_25 = F_15 ( V_6 , & V_36 ) ;
if ( V_25 || V_36 & V_37 )
return 1 ;
return 0 ;
}
static void F_20 ( struct V_5 * V_6 , int V_38 )
{
struct V_7 * V_8 = F_9 ( V_6 ) ;
unsigned long V_39 ;
T_1 V_40 ;
F_21 ( & V_8 -> V_11 , V_39 ) ;
if ( V_38 )
V_8 -> V_41 = V_42
| V_43 ;
else
V_8 -> V_41 &= ~ ( V_42
| V_43 ) ;
V_40 = V_8 -> V_41 ;
F_22 ( & V_8 -> V_11 , V_39 ) ;
F_11 ( V_6 , V_40 ) ;
}
static void F_23 ( struct V_44 * V_45 )
{
V_45 -> V_46 = V_47 ;
V_45 -> V_46 . V_48 = V_49 | V_50 | V_51 | V_52 | V_53 ;
V_45 -> V_46 . V_54 = 115200 ;
V_45 -> V_46 . V_55 = 115200 ;
}
static void F_24 ( struct V_44 * V_45 ,
struct V_5 * V_6 , struct V_56 * V_57 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
unsigned long V_39 ;
unsigned int V_58 = V_45 -> V_46 . V_48 ;
unsigned short V_59 ;
unsigned char V_24 [ 2 ] = { 0 , 0 } ;
int V_60 ;
int V_61 ;
T_1 V_40 ;
if ( V_57 && ! F_25 ( & V_45 -> V_46 , V_57 ) )
return;
F_21 ( & V_8 -> V_11 , V_39 ) ;
V_40 = V_8 -> V_41 ;
if ( V_57 && ( V_57 -> V_48 & V_62 ) == V_63 ) {
V_8 -> V_41 |= V_64 ;
if ( ! ( V_57 -> V_48 & V_65 ) )
V_8 -> V_41 |= V_66 ;
}
if ( V_40 != V_8 -> V_41 ) {
V_40 = V_8 -> V_41 ;
F_22 ( & V_8 -> V_11 , V_39 ) ;
F_11 ( V_6 , V_40 ) ;
} else {
F_22 ( & V_8 -> V_11 , V_39 ) ;
}
V_60 = F_26 ( V_45 ) ;
switch ( V_60 ) {
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
switch ( V_58 & V_67 ) {
case V_68 :
V_24 [ 1 ] |= V_69 ;
break;
case V_70 :
V_24 [ 1 ] |= V_71 ;
break;
case V_72 :
V_24 [ 1 ] |= V_73 ;
break;
default:
case V_50 :
V_24 [ 1 ] |= V_74 ;
break;
}
V_24 [ 1 ] |= ( V_58 & V_75 ) ? V_76 :
V_77 ;
if ( V_58 & V_78 ) {
V_24 [ 1 ] |= ( V_58 & V_79 ) ?
V_80 : V_81 ;
} else {
V_24 [ 1 ] |= V_82 ;
}
V_59 = V_24 [ 0 ] | V_24 [ 1 ] << 8 ;
V_61 = F_12 ( V_2 -> V_17 , F_13 ( V_2 -> V_17 , 0 ) ,
V_83 , V_84 ,
V_59 , 0 , NULL , 0 , 100 ) ;
if ( V_61 < 0 )
F_14 ( & V_6 -> V_17 , L_7 ,
V_59 , V_61 ) ;
F_17 ( & V_6 -> V_17 , L_8 , V_61 ) ;
if ( V_58 & V_65 ) {
F_18 ( V_6 , 0x000a , V_85 ) ;
}
}
static int F_27 ( struct V_44 * V_45 , struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
int V_25 ;
F_28 ( V_2 -> V_17 , V_6 -> V_86 -> V_87 ) ;
F_28 ( V_2 -> V_17 , V_6 -> V_88 -> V_87 ) ;
V_25 = F_12 ( V_2 -> V_17 , F_13 ( V_2 -> V_17 , 0 ) ,
0x09 , 0x00 ,
0x01 , 0x00 , NULL , 0x00 , 100 ) ;
if ( V_25 )
return V_25 ;
F_11 ( V_6 , V_8 -> V_41 ) ;
if ( V_45 )
F_24 ( V_45 , V_6 , NULL ) ;
return F_29 ( V_45 , V_6 ) ;
}
static int F_30 ( struct V_44 * V_45 ,
unsigned int V_89 , unsigned int V_90 )
{
struct V_5 * V_6 = V_45 -> V_91 ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
unsigned long V_39 ;
T_1 V_40 ;
F_21 ( & V_8 -> V_11 , V_39 ) ;
if ( V_89 & V_92 )
V_8 -> V_41 |= V_66 ;
if ( V_89 & V_93 )
V_8 -> V_41 |= V_64 ;
if ( V_90 & V_92 )
V_8 -> V_41 &= ~ V_66 ;
if ( V_90 & V_93 )
V_8 -> V_41 &= ~ V_64 ;
V_40 = V_8 -> V_41 ;
F_22 ( & V_8 -> V_11 , V_39 ) ;
return F_11 ( V_6 , V_40 ) ;
}
static int F_31 ( struct V_44 * V_45 )
{
struct V_5 * V_6 = V_45 -> V_91 ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
unsigned long V_39 ;
unsigned int V_15 ;
T_1 V_23 ;
unsigned int V_94 ;
V_94 = F_15 ( V_6 , & V_23 ) ;
if ( V_94 )
return V_94 ;
F_21 ( & V_8 -> V_11 , V_39 ) ;
V_15 = V_8 -> V_41 ;
F_22 ( & V_8 -> V_11 , V_39 ) ;
V_94 = ( ( V_15 & V_64 ) ? V_93 : 0 )
| ( ( V_15 & V_66 ) ? V_92 : 0 )
| ( ( V_23 & V_95 ) ? V_96 : 0 )
| ( ( V_23 & V_97 ) ? V_98 : 0 )
| ( ( V_23 & V_99 ) ? V_100 : 0 )
| ( ( V_23 & V_37 ) ? V_101 : 0 ) ;
return V_94 ;
}
