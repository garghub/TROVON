static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
F_2 ( V_2 , ( void * ) V_4 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
unsigned char V_5 = V_2 -> V_5 ;
if ( V_2 -> V_6 < V_5 ||
V_2 -> V_7 < V_5 ) {
F_4 ( & V_2 -> V_8 -> V_9 , L_1 ) ;
return - V_10 ;
}
return 0 ;
}
static int F_5 ( struct V_11 * V_12 )
{
const struct V_3 * V_4 = F_6 ( V_12 -> V_2 ) ;
struct V_13 * V_14 ;
V_14 = F_7 ( sizeof( * V_14 ) , V_15 ) ;
if ( ! V_14 )
return - V_16 ;
F_8 ( & V_14 -> V_17 ) ;
V_14 -> V_18 = V_4 -> V_19 ;
F_9 ( V_12 , V_14 ) ;
V_12 -> V_12 . V_20 = 256 ;
return 0 ;
}
static int F_10 ( struct V_11 * V_12 )
{
struct V_13 * V_14 ;
V_14 = F_11 ( V_12 ) ;
F_12 ( V_14 ) ;
return 0 ;
}
static int F_13 ( struct V_11 * V_12 , T_1 V_21 )
{
struct V_13 * V_14 = F_11 ( V_12 ) ;
struct V_22 * V_9 = V_12 -> V_2 -> V_9 ;
int V_23 ;
if ( V_14 -> V_18 & V_24 )
return - V_25 ;
V_23 = F_14 ( V_9 , F_15 ( V_9 , 0 ) ,
V_26 , V_27 ,
V_21 , 0x04 , NULL , 0 , 100 ) ;
if ( V_23 != 0 ) {
F_4 ( & V_12 -> V_9 , L_2 ,
V_23 ) ;
}
return V_23 ;
}
static int F_16 ( struct V_11 * V_12 , T_1 * V_28 )
{
struct V_13 * V_14 = F_11 ( V_12 ) ;
struct V_22 * V_9 = V_12 -> V_2 -> V_9 ;
T_1 * V_29 ;
int V_30 ;
if ( V_14 -> V_18 & V_24 )
return - V_25 ;
V_29 = F_7 ( 1 , V_15 ) ;
if ( ! V_29 )
return - V_16 ;
V_30 = F_14 ( V_9 , F_17 ( V_9 , 0 ) ,
V_31 , V_32 ,
0 , V_33 , V_29 , 1 , 100 ) ;
if ( V_30 < 1 ) {
F_4 ( & V_12 -> V_9 , L_3 , V_30 ) ;
if ( V_30 >= 0 )
V_30 = - V_34 ;
goto V_35;
}
F_18 ( & V_12 -> V_9 , L_4 , V_30 , * V_29 ) ;
* V_28 = * V_29 ;
V_30 = 0 ;
V_35:
F_12 ( V_29 ) ;
return V_30 ;
}
static void F_19 ( struct V_11 * V_12 , T_2 V_36 ,
T_2 V_37 )
{
struct V_13 * V_14 = F_11 ( V_12 ) ;
struct V_22 * V_9 = V_12 -> V_2 -> V_9 ;
int V_30 ;
if ( V_14 -> V_18 & V_38 )
return;
V_30 = F_14 ( V_9 , F_15 ( V_9 , 0 ) ,
V_39 , V_40 ,
V_36 , V_37 , NULL , 0 , 100 ) ;
F_18 ( & V_12 -> V_9 , L_5 , V_36 , V_37 ) ;
if ( V_30 < 0 )
F_4 ( & V_12 -> V_9 , L_6 , V_30 ) ;
}
static int F_20 ( struct V_11 * V_12 )
{
T_1 V_41 ;
int V_30 ;
V_30 = F_16 ( V_12 , & V_41 ) ;
if ( V_30 || V_41 & V_42 )
return 1 ;
return 0 ;
}
static void F_21 ( struct V_11 * V_12 , int V_43 )
{
struct V_13 * V_14 = F_11 ( V_12 ) ;
unsigned long V_44 ;
T_1 V_45 ;
F_22 ( & V_14 -> V_17 , V_44 ) ;
if ( V_43 )
V_14 -> V_46 = V_47
| V_48 ;
else
V_14 -> V_46 &= ~ ( V_47
| V_48 ) ;
V_45 = V_14 -> V_46 ;
F_23 ( & V_14 -> V_17 , V_44 ) ;
F_13 ( V_12 , V_45 ) ;
}
static void F_24 ( struct V_49 * V_50 )
{
V_50 -> V_51 = V_52 ;
V_50 -> V_51 . V_53 = V_54 | V_55 | V_56 | V_57 | V_58 ;
V_50 -> V_51 . V_59 = 115200 ;
V_50 -> V_51 . V_60 = 115200 ;
}
static void F_25 ( struct V_49 * V_50 ,
struct V_11 * V_12 , struct V_61 * V_62 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_13 * V_14 = F_11 ( V_12 ) ;
unsigned long V_44 ;
unsigned int V_63 = V_50 -> V_51 . V_53 ;
unsigned short V_64 ;
unsigned char V_29 [ 2 ] = { 0 , 0 } ;
int V_65 ;
int V_66 ;
T_1 V_45 ;
if ( V_62 && ! F_26 ( & V_50 -> V_51 , V_62 ) )
return;
F_22 ( & V_14 -> V_17 , V_44 ) ;
V_45 = V_14 -> V_46 ;
if ( V_62 && ( V_62 -> V_53 & V_67 ) == V_68 ) {
V_14 -> V_46 |= V_69 ;
if ( ! ( V_62 -> V_53 & V_70 ) )
V_14 -> V_46 |= V_71 ;
}
if ( V_45 != V_14 -> V_46 ) {
V_45 = V_14 -> V_46 ;
F_23 ( & V_14 -> V_17 , V_44 ) ;
F_13 ( V_12 , V_45 ) ;
} else {
F_23 ( & V_14 -> V_17 , V_44 ) ;
}
V_65 = F_27 ( V_50 ) ;
switch ( V_65 ) {
case 300 : V_29 [ 0 ] = 0x00 ; break;
case 600 : V_29 [ 0 ] = 0x01 ; break;
case 1200 : V_29 [ 0 ] = 0x02 ; break;
case 2400 : V_29 [ 0 ] = 0x03 ; break;
case 4800 : V_29 [ 0 ] = 0x04 ; break;
case 9600 : V_29 [ 0 ] = 0x05 ; break;
case 19200 : V_29 [ 0 ] = 0x07 ; break;
case 38400 : V_29 [ 0 ] = 0x09 ; break;
case 57600 : V_29 [ 0 ] = 0x0a ; break;
case 115200 : V_29 [ 0 ] = 0x0b ; break;
case 230400 : V_29 [ 0 ] = 0x0c ; break;
case 460800 : V_29 [ 0 ] = 0x0d ; break;
case 921600 : V_29 [ 0 ] = 0x0e ; break;
case 3000000 : V_29 [ 0 ] = 0x11 ; break;
case 0 :
case 1000000 :
V_29 [ 0 ] = 0x0b ; break;
default:
F_4 ( & V_12 -> V_9 , L_7 ) ;
}
switch ( V_63 & V_72 ) {
case V_73 :
V_29 [ 1 ] |= V_74 ;
break;
case V_75 :
V_29 [ 1 ] |= V_76 ;
break;
case V_77 :
V_29 [ 1 ] |= V_78 ;
break;
default:
case V_55 :
V_29 [ 1 ] |= V_79 ;
break;
}
V_29 [ 1 ] |= ( V_63 & V_80 ) ? V_81 :
V_82 ;
if ( V_63 & V_83 ) {
V_29 [ 1 ] |= ( V_63 & V_84 ) ?
V_85 : V_86 ;
} else {
V_29 [ 1 ] |= V_87 ;
}
V_64 = V_29 [ 0 ] | V_29 [ 1 ] << 8 ;
V_66 = F_14 ( V_2 -> V_9 , F_15 ( V_2 -> V_9 , 0 ) ,
V_88 , V_89 ,
V_64 , 0 , NULL , 0 , 100 ) ;
if ( V_66 < 0 )
F_4 ( & V_12 -> V_9 , L_8 ,
V_64 , V_66 ) ;
F_18 ( & V_12 -> V_9 , L_9 , V_66 ) ;
if ( V_63 & V_70 ) {
F_19 ( V_12 , 0x000a , V_90 ) ;
}
}
static int F_28 ( struct V_49 * V_50 , struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_13 * V_14 = F_11 ( V_12 ) ;
int V_30 ;
F_29 ( V_2 -> V_9 , V_12 -> V_91 -> V_92 ) ;
F_29 ( V_2 -> V_9 , V_12 -> V_93 -> V_92 ) ;
V_30 = F_14 ( V_2 -> V_9 , F_15 ( V_2 -> V_9 , 0 ) ,
0x09 , 0x00 ,
0x01 , 0x00 , NULL , 0x00 , 100 ) ;
if ( V_30 )
return V_30 ;
F_13 ( V_12 , V_14 -> V_46 ) ;
if ( V_50 )
F_25 ( V_50 , V_12 , NULL ) ;
return F_30 ( V_50 , V_12 ) ;
}
static int F_31 ( struct V_49 * V_50 ,
unsigned int V_94 , unsigned int V_95 )
{
struct V_11 * V_12 = V_50 -> V_96 ;
struct V_13 * V_14 = F_11 ( V_12 ) ;
unsigned long V_44 ;
T_1 V_45 ;
F_22 ( & V_14 -> V_17 , V_44 ) ;
if ( V_94 & V_97 )
V_14 -> V_46 |= V_71 ;
if ( V_94 & V_98 )
V_14 -> V_46 |= V_69 ;
if ( V_95 & V_97 )
V_14 -> V_46 &= ~ V_71 ;
if ( V_95 & V_98 )
V_14 -> V_46 &= ~ V_69 ;
V_45 = V_14 -> V_46 ;
F_23 ( & V_14 -> V_17 , V_44 ) ;
return F_13 ( V_12 , V_45 ) ;
}
static int F_32 ( struct V_49 * V_50 )
{
struct V_11 * V_12 = V_50 -> V_96 ;
struct V_13 * V_14 = F_11 ( V_12 ) ;
unsigned long V_44 ;
unsigned int V_21 ;
T_1 V_28 ;
unsigned int V_99 ;
V_99 = F_16 ( V_12 , & V_28 ) ;
if ( V_99 )
return V_99 ;
F_22 ( & V_14 -> V_17 , V_44 ) ;
V_21 = V_14 -> V_46 ;
F_23 ( & V_14 -> V_17 , V_44 ) ;
V_99 = ( ( V_21 & V_69 ) ? V_98 : 0 )
| ( ( V_21 & V_71 ) ? V_97 : 0 )
| ( ( V_28 & V_100 ) ? V_101 : 0 )
| ( ( V_28 & V_102 ) ? V_103 : 0 )
| ( ( V_28 & V_104 ) ? V_105 : 0 )
| ( ( V_28 & V_42 ) ? V_106 : 0 ) ;
return V_99 ;
}
