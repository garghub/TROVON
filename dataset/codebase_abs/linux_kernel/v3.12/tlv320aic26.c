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
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
int V_22 , V_23 , V_24 , V_25 , V_26 , V_27 , V_28 ;
T_1 V_3 ;
F_12 ( & V_4 -> V_12 -> V_13 , L_2 ,
V_17 , V_19 ) ;
F_12 ( & V_4 -> V_12 -> V_13 , L_3 , F_13 ( V_19 ) ,
F_14 ( V_19 ) ) ;
switch ( F_13 ( V_19 ) ) {
case 8000 : V_22 = 48000 ; V_23 = V_29 ; break;
case 11025 : V_22 = 44100 ; V_23 = V_30 ; break;
case 12000 : V_22 = 48000 ; V_23 = V_30 ; break;
case 16000 : V_22 = 48000 ; V_23 = V_31 ; break;
case 22050 : V_22 = 44100 ; V_23 = V_32 ; break;
case 24000 : V_22 = 48000 ; V_23 = V_32 ; break;
case 32000 : V_22 = 48000 ; V_23 = V_33 ; break;
case 44100 : V_22 = 44100 ; V_23 = V_34 ; break;
case 48000 : V_22 = 48000 ; V_23 = V_34 ; break;
default:
F_12 ( & V_4 -> V_12 -> V_13 , L_4 ) ; return - V_15 ;
}
switch ( F_14 ( V_19 ) ) {
case V_35 : V_24 = V_36 ; break;
case V_37 : V_24 = V_36 ; break;
case V_38 : V_24 = V_39 ; break;
case V_40 : V_24 = V_41 ; break;
default:
F_12 ( & V_4 -> V_12 -> V_13 , L_5 ) ; return - V_15 ;
}
V_25 = 1 ;
V_26 = V_22 / ( V_4 -> V_42 / 2048 ) ;
V_27 = V_22 - ( V_26 * ( V_4 -> V_42 / 2048 ) ) ;
V_27 = ( 10000 * V_27 ) / ( V_4 -> V_42 / 2048 ) ;
F_12 ( & V_4 -> V_12 -> V_13 , L_6 , V_26 , V_27 ) ;
V_28 = 0 ;
V_3 = 0x8000 | V_28 << 11 | V_25 << 8 | V_26 << 2 ;
F_15 ( V_2 , V_43 , V_3 ) ;
V_3 = V_27 << 2 ;
F_15 ( V_2 , V_44 , V_3 ) ;
V_3 = F_7 ( V_2 , V_45 ) ;
V_3 &= ~ 0xf800 ;
if ( V_4 -> V_46 )
V_3 |= 0x0800 ;
if ( V_22 == 48000 )
V_3 |= 0x2000 ;
F_15 ( V_2 , V_45 , V_3 ) ;
V_3 = F_7 ( V_2 , V_47 ) ;
V_3 &= ~ 0x0fff ;
V_3 |= V_24 | V_4 -> V_48 | ( V_23 << 3 ) | V_23 ;
F_15 ( V_2 , V_47 , V_3 ) ;
return 0 ;
}
static int F_16 ( struct V_20 * V_21 , int V_49 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
T_1 V_3 = F_7 ( V_2 , V_50 ) ;
F_12 ( & V_4 -> V_12 -> V_13 , L_7 ,
V_21 , V_49 ) ;
if ( V_49 )
V_3 |= 0x8080 ;
else
V_3 &= ~ 0x8080 ;
F_15 ( V_2 , V_50 , V_3 ) ;
return 0 ;
}
static int F_17 ( struct V_20 * V_51 ,
int V_52 , unsigned int V_53 , int V_54 )
{
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_12 ( & V_4 -> V_12 -> V_13 , L_8
L_9 ,
V_51 , V_52 , V_53 , V_54 ) ;
if ( ( V_53 < 2000000 ) || ( V_53 > 50000000 ) )
return - V_15 ;
V_4 -> V_42 = V_53 ;
return 0 ;
}
static int F_18 ( struct V_20 * V_51 , unsigned int V_55 )
{
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_12 ( & V_4 -> V_12 -> V_13 , L_10 ,
V_51 , V_55 ) ;
switch ( V_55 & V_56 ) {
case V_57 : V_4 -> V_46 = 1 ; break;
case V_58 : V_4 -> V_46 = 0 ; break;
default:
F_12 ( & V_4 -> V_12 -> V_13 , L_11 ) ; return - V_15 ;
}
switch ( V_55 & V_59 ) {
case V_60 : V_4 -> V_48 = V_61 ; break;
case V_62 : V_4 -> V_48 = V_63 ; break;
case V_64 : V_4 -> V_48 = V_65 ; break;
case V_66 : V_4 -> V_48 = V_67 ; break;
default:
F_12 ( & V_4 -> V_12 -> V_13 , L_5 ) ; return - V_15 ;
}
return 0 ;
}
static T_3 F_19 ( struct V_68 * V_13 ,
struct V_69 * V_70 , char * V_71 )
{
struct V_4 * V_4 = F_20 ( V_13 ) ;
int V_72 , V_73 , V_53 , V_74 ;
V_72 = F_7 ( V_4 -> V_2 , V_75 ) ;
V_73 = ( V_72 >> 12 ) & 0x7 ;
V_53 = ( 125 << ( ( V_72 >> 8 ) & 0x7 ) ) >> 1 ;
V_74 = 2 * ( 1 + ( ( V_72 >> 4 ) & 0xf ) ) ;
return sprintf ( V_71 , L_12 , V_73 , V_53 , V_74 ) ;
}
static T_3 F_21 ( struct V_68 * V_13 ,
struct V_69 * V_70 ,
const char * V_71 , T_4 V_76 )
{
struct V_4 * V_4 = F_20 ( V_13 ) ;
int V_72 ;
V_72 = F_7 ( V_4 -> V_2 , V_75 ) ;
V_72 |= 0x8000 ;
F_15 ( V_4 -> V_2 , V_75 , V_72 ) ;
return V_76 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_20 ( V_2 -> V_13 ) ;
int V_77 , V_78 , V_79 , V_3 ;
V_4 -> V_2 = V_2 ;
F_15 ( V_2 , V_80 , 0xBB00 ) ;
F_15 ( V_2 , V_81 , 0 ) ;
V_3 = F_23 ( V_2 , V_45 ) ;
V_3 &= ~ 0xf800 ;
V_3 |= 0x0800 ;
F_15 ( V_2 , V_45 , V_3 ) ;
for ( V_79 = 0 ; V_79 < V_2 -> V_82 -> V_83 ; V_79 ++ )
F_23 ( V_2 , V_79 ) ;
V_77 = F_24 ( V_2 -> V_13 , & V_84 ) ;
if ( V_77 )
F_25 ( V_2 -> V_13 , L_13 ) ;
F_12 ( V_2 -> V_13 , L_14 ) ;
V_78 = F_26 ( V_2 , V_85 ,
F_27 ( V_85 ) ) ;
F_28 ( V_78 < 0 ) ;
return 0 ;
}
static int F_29 ( struct V_86 * V_12 )
{
struct V_4 * V_4 ;
int V_77 ;
F_12 ( & V_12 -> V_13 , L_15 ) ;
V_4 = F_30 ( & V_12 -> V_13 , sizeof *V_4 , V_87 ) ;
if ( ! V_4 )
return - V_88 ;
V_4 -> V_12 = V_12 ;
F_31 ( & V_12 -> V_13 , V_4 ) ;
V_4 -> V_46 = 1 ;
V_77 = F_32 ( & V_12 -> V_13 ,
& V_89 , & V_90 , 1 ) ;
return V_77 ;
}
static int F_33 ( struct V_86 * V_12 )
{
F_34 ( & V_12 -> V_13 ) ;
return 0 ;
}
