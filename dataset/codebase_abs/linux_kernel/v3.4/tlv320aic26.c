static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
T_1 * V_5 = V_2 -> V_6 ;
T_1 V_7 , V_8 ;
T_2 V_9 [ 2 ] ;
int V_10 ;
if ( V_3 >= V_11 ) {
F_3 ( 1 ) ;
return 0 ;
}
V_7 = F_4 ( V_3 ) ;
V_9 [ 0 ] = ( V_7 >> 8 ) & 0xff ;
V_9 [ 1 ] = V_7 & 0xff ;
V_10 = F_5 ( V_4 -> V_12 , V_9 , 2 , V_9 , 2 ) ;
if ( V_10 ) {
F_6 ( & V_4 -> V_12 -> V_13 , L_1 ) ;
return - V_14 ;
}
V_8 = ( V_9 [ 0 ] << 8 ) | V_9 [ 1 ] ;
V_5 [ V_3 ] = V_8 ;
return V_8 ;
}
static unsigned int F_7 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_1 * V_5 = V_2 -> V_6 ;
if ( V_3 >= V_11 ) {
F_3 ( 1 ) ;
return 0 ;
}
return V_5 [ V_3 ] ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_8 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
T_1 * V_5 = V_2 -> V_6 ;
T_1 V_7 ;
T_2 V_9 [ 4 ] ;
int V_10 ;
if ( V_3 >= V_11 ) {
F_3 ( 1 ) ;
return - V_15 ;
}
V_7 = F_9 ( V_3 ) ;
V_9 [ 0 ] = ( V_7 >> 8 ) & 0xff ;
V_9 [ 1 ] = V_7 & 0xff ;
V_9 [ 2 ] = V_8 >> 8 ;
V_9 [ 3 ] = V_8 ;
V_10 = F_10 ( V_4 -> V_12 , V_9 , 4 ) ;
if ( V_10 ) {
F_6 ( & V_4 -> V_12 -> V_13 , L_1 ) ;
return - V_14 ;
}
V_5 [ V_3 ] = V_8 ;
return 0 ;
}
static int F_11 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = V_17 -> V_24 ;
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
int V_25 , V_26 , V_27 , V_28 , V_29 , V_30 , V_31 ;
T_1 V_3 ;
F_12 ( & V_4 -> V_12 -> V_13 , L_2 ,
V_17 , V_19 ) ;
F_12 ( & V_4 -> V_12 -> V_13 , L_3 , F_13 ( V_19 ) ,
F_14 ( V_19 ) ) ;
switch ( F_13 ( V_19 ) ) {
case 8000 : V_25 = 48000 ; V_26 = V_32 ; break;
case 11025 : V_25 = 44100 ; V_26 = V_33 ; break;
case 12000 : V_25 = 48000 ; V_26 = V_33 ; break;
case 16000 : V_25 = 48000 ; V_26 = V_34 ; break;
case 22050 : V_25 = 44100 ; V_26 = V_35 ; break;
case 24000 : V_25 = 48000 ; V_26 = V_35 ; break;
case 32000 : V_25 = 48000 ; V_26 = V_36 ; break;
case 44100 : V_25 = 44100 ; V_26 = V_37 ; break;
case 48000 : V_25 = 48000 ; V_26 = V_37 ; break;
default:
F_12 ( & V_4 -> V_12 -> V_13 , L_4 ) ; return - V_15 ;
}
switch ( F_14 ( V_19 ) ) {
case V_38 : V_27 = V_39 ; break;
case V_40 : V_27 = V_39 ; break;
case V_41 : V_27 = V_42 ; break;
case V_43 : V_27 = V_44 ; break;
default:
F_12 ( & V_4 -> V_12 -> V_13 , L_5 ) ; return - V_15 ;
}
V_28 = 1 ;
V_29 = V_25 / ( V_4 -> V_45 / 2048 ) ;
V_30 = V_25 - ( V_29 * ( V_4 -> V_45 / 2048 ) ) ;
V_30 = ( 10000 * V_30 ) / ( V_4 -> V_45 / 2048 ) ;
F_12 ( & V_4 -> V_12 -> V_13 , L_6 , V_29 , V_30 ) ;
V_31 = 0 ;
V_3 = 0x8000 | V_31 << 11 | V_28 << 8 | V_29 << 2 ;
F_8 ( V_2 , V_46 , V_3 ) ;
V_3 = V_30 << 2 ;
F_8 ( V_2 , V_47 , V_3 ) ;
V_3 = F_7 ( V_2 , V_48 ) ;
V_3 &= ~ 0xf800 ;
if ( V_4 -> V_49 )
V_3 |= 0x0800 ;
if ( V_25 == 48000 )
V_3 |= 0x2000 ;
F_8 ( V_2 , V_48 , V_3 ) ;
V_3 = F_7 ( V_2 , V_50 ) ;
V_3 &= ~ 0x0fff ;
V_3 |= V_27 | V_4 -> V_51 | ( V_26 << 3 ) | V_26 ;
F_8 ( V_2 , V_50 , V_3 ) ;
return 0 ;
}
static int F_15 ( struct V_20 * V_21 , int V_52 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
T_1 V_3 = F_7 ( V_2 , V_53 ) ;
F_12 ( & V_4 -> V_12 -> V_13 , L_7 ,
V_21 , V_52 ) ;
if ( V_52 )
V_3 |= 0x8080 ;
else
V_3 &= ~ 0x8080 ;
F_8 ( V_2 , V_53 , V_3 ) ;
return 0 ;
}
static int F_16 ( struct V_20 * V_54 ,
int V_55 , unsigned int V_56 , int V_57 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_12 ( & V_4 -> V_12 -> V_13 , L_8
L_9 ,
V_54 , V_55 , V_56 , V_57 ) ;
if ( ( V_56 < 2000000 ) || ( V_56 > 50000000 ) )
return - V_15 ;
V_4 -> V_45 = V_56 ;
return 0 ;
}
static int F_17 ( struct V_20 * V_54 , unsigned int V_58 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_12 ( & V_4 -> V_12 -> V_13 , L_10 ,
V_54 , V_58 ) ;
switch ( V_58 & V_59 ) {
case V_60 : V_4 -> V_49 = 1 ; break;
case V_61 : V_4 -> V_49 = 0 ; break;
default:
F_12 ( & V_4 -> V_12 -> V_13 , L_11 ) ; return - V_15 ;
}
switch ( V_58 & V_62 ) {
case V_63 : V_4 -> V_51 = V_64 ; break;
case V_65 : V_4 -> V_51 = V_66 ; break;
case V_67 : V_4 -> V_51 = V_68 ; break;
case V_69 : V_4 -> V_51 = V_70 ; break;
default:
F_12 ( & V_4 -> V_12 -> V_13 , L_5 ) ; return - V_15 ;
}
return 0 ;
}
static T_3 F_18 ( struct V_71 * V_13 ,
struct V_72 * V_73 , char * V_74 )
{
struct V_4 * V_4 = F_19 ( V_13 ) ;
int V_75 , V_76 , V_56 , V_77 ;
V_75 = F_7 ( & V_4 -> V_2 , V_78 ) ;
V_76 = ( V_75 >> 12 ) & 0x7 ;
V_56 = ( 125 << ( ( V_75 >> 8 ) & 0x7 ) ) >> 1 ;
V_77 = 2 * ( 1 + ( ( V_75 >> 4 ) & 0xf ) ) ;
return sprintf ( V_74 , L_12 , V_76 , V_56 , V_77 ) ;
}
static T_3 F_20 ( struct V_71 * V_13 ,
struct V_72 * V_73 ,
const char * V_74 , T_4 V_79 )
{
struct V_4 * V_4 = F_19 ( V_13 ) ;
int V_75 ;
V_75 = F_7 ( & V_4 -> V_2 , V_78 ) ;
V_75 |= 0x8000 ;
F_8 ( & V_4 -> V_2 , V_78 , V_75 ) ;
return V_79 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_80 , V_81 , V_82 , V_3 ;
F_22 ( V_2 -> V_13 , L_13 ) ;
F_8 ( V_2 , V_83 , 0xBB00 ) ;
F_8 ( V_2 , V_84 , 0 ) ;
V_3 = F_1 ( V_2 , V_48 ) ;
V_3 &= ~ 0xf800 ;
V_3 |= 0x0800 ;
F_8 ( V_2 , V_48 , V_3 ) ;
for ( V_82 = 0 ; V_82 < V_2 -> V_85 -> V_86 ; V_82 ++ )
F_1 ( V_2 , V_82 ) ;
V_80 = F_23 ( V_2 -> V_13 , & V_87 ) ;
if ( V_80 )
F_22 ( V_2 -> V_13 , L_14 ) ;
F_12 ( V_2 -> V_13 , L_15 ) ;
V_81 = F_24 ( V_2 , V_88 ,
F_25 ( V_88 ) ) ;
F_26 ( V_81 < 0 ) ;
return 0 ;
}
static int F_27 ( struct V_89 * V_12 )
{
struct V_4 * V_4 ;
int V_80 ;
F_12 ( & V_12 -> V_13 , L_16 ) ;
V_4 = F_28 ( & V_12 -> V_13 , sizeof *V_4 , V_90 ) ;
if ( ! V_4 )
return - V_91 ;
V_4 -> V_12 = V_12 ;
F_29 ( & V_12 -> V_13 , V_4 ) ;
V_4 -> V_49 = 1 ;
V_80 = F_30 ( & V_12 -> V_13 ,
& V_92 , & V_93 , 1 ) ;
return V_80 ;
}
static int F_31 ( struct V_89 * V_12 )
{
F_32 ( & V_12 -> V_13 ) ;
return 0 ;
}
static int T_5 F_33 ( void )
{
return F_34 ( & V_94 ) ;
}
static void T_6 F_35 ( void )
{
F_36 ( & V_94 ) ;
}
