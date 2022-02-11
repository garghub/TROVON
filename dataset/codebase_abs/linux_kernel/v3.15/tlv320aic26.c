static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_9 = F_2 ( V_8 ) ;
int V_10 , V_11 , V_12 , V_13 , V_14 , V_15 , V_16 ;
T_1 V_17 ;
F_3 ( & V_9 -> V_18 -> V_19 , L_1 ,
V_2 , V_4 ) ;
F_3 ( & V_9 -> V_18 -> V_19 , L_2 , F_4 ( V_4 ) ,
F_5 ( V_4 ) ) ;
switch ( F_4 ( V_4 ) ) {
case 8000 : V_10 = 48000 ; V_11 = V_20 ; break;
case 11025 : V_10 = 44100 ; V_11 = V_21 ; break;
case 12000 : V_10 = 48000 ; V_11 = V_21 ; break;
case 16000 : V_10 = 48000 ; V_11 = V_22 ; break;
case 22050 : V_10 = 44100 ; V_11 = V_23 ; break;
case 24000 : V_10 = 48000 ; V_11 = V_23 ; break;
case 32000 : V_10 = 48000 ; V_11 = V_24 ; break;
case 44100 : V_10 = 44100 ; V_11 = V_25 ; break;
case 48000 : V_10 = 48000 ; V_11 = V_25 ; break;
default:
F_3 ( & V_9 -> V_18 -> V_19 , L_3 ) ; return - V_26 ;
}
switch ( F_5 ( V_4 ) ) {
case V_27 : V_12 = V_28 ; break;
case V_29 : V_12 = V_28 ; break;
case V_30 : V_12 = V_31 ; break;
case V_32 : V_12 = V_33 ; break;
default:
F_3 ( & V_9 -> V_18 -> V_19 , L_4 ) ; return - V_26 ;
}
V_13 = 1 ;
V_14 = V_10 / ( V_9 -> V_34 / 2048 ) ;
V_15 = V_10 - ( V_14 * ( V_9 -> V_34 / 2048 ) ) ;
V_15 = ( 10000 * V_15 ) / ( V_9 -> V_34 / 2048 ) ;
F_3 ( & V_9 -> V_18 -> V_19 , L_5 , V_14 , V_15 ) ;
V_16 = 0 ;
V_17 = 0x8000 | V_16 << 11 | V_13 << 8 | V_14 << 2 ;
F_6 ( V_8 , V_35 , V_17 ) ;
V_17 = V_15 << 2 ;
F_6 ( V_8 , V_36 , V_17 ) ;
if ( V_9 -> V_37 )
V_17 = 0x0800 ;
if ( V_10 == 48000 )
V_17 = 0x2000 ;
F_7 ( V_8 , V_38 , 0xf800 , V_17 ) ;
V_17 = V_12 | V_9 -> V_39 | ( V_11 << 3 ) | V_11 ;
F_7 ( V_8 , V_40 , 0xfff , V_17 ) ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 , int V_41 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_9 = F_2 ( V_8 ) ;
T_1 V_17 ;
F_3 ( & V_9 -> V_18 -> V_19 , L_6 ,
V_6 , V_41 ) ;
if ( V_41 )
V_17 = 0x8080 ;
else
V_17 = 0 ;
F_7 ( V_8 , V_42 , 0x8000 , V_17 ) ;
return 0 ;
}
static int F_9 ( struct V_5 * V_43 ,
int V_44 , unsigned int V_45 , int V_46 )
{
struct V_7 * V_8 = V_43 -> V_8 ;
struct V_9 * V_9 = F_2 ( V_8 ) ;
F_3 ( & V_9 -> V_18 -> V_19 , L_7
L_8 ,
V_43 , V_44 , V_45 , V_46 ) ;
if ( ( V_45 < 2000000 ) || ( V_45 > 50000000 ) )
return - V_26 ;
V_9 -> V_34 = V_45 ;
return 0 ;
}
static int F_10 ( struct V_5 * V_43 , unsigned int V_47 )
{
struct V_7 * V_8 = V_43 -> V_8 ;
struct V_9 * V_9 = F_2 ( V_8 ) ;
F_3 ( & V_9 -> V_18 -> V_19 , L_9 ,
V_43 , V_47 ) ;
switch ( V_47 & V_48 ) {
case V_49 : V_9 -> V_37 = 1 ; break;
case V_50 : V_9 -> V_37 = 0 ; break;
default:
F_3 ( & V_9 -> V_18 -> V_19 , L_10 ) ; return - V_26 ;
}
switch ( V_47 & V_51 ) {
case V_52 : V_9 -> V_39 = V_53 ; break;
case V_54 : V_9 -> V_39 = V_55 ; break;
case V_56 : V_9 -> V_39 = V_57 ; break;
case V_58 : V_9 -> V_39 = V_59 ; break;
default:
F_3 ( & V_9 -> V_18 -> V_19 , L_4 ) ; return - V_26 ;
}
return 0 ;
}
static T_2 F_11 ( struct V_60 * V_19 ,
struct V_61 * V_62 , char * V_63 )
{
struct V_9 * V_9 = F_12 ( V_19 ) ;
int V_64 , V_65 , V_45 , V_66 ;
V_64 = F_13 ( V_9 -> V_8 , V_67 ) ;
V_65 = ( V_64 >> 12 ) & 0x7 ;
V_45 = ( 125 << ( ( V_64 >> 8 ) & 0x7 ) ) >> 1 ;
V_66 = 2 * ( 1 + ( ( V_64 >> 4 ) & 0xf ) ) ;
return sprintf ( V_63 , L_11 , V_65 , V_45 , V_66 ) ;
}
static T_2 F_14 ( struct V_60 * V_19 ,
struct V_61 * V_62 ,
const char * V_63 , T_3 V_68 )
{
struct V_9 * V_9 = F_12 ( V_19 ) ;
F_7 ( V_9 -> V_8 , V_67 ,
0x8000 , 0x800 ) ;
return V_68 ;
}
static int F_15 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_12 ( V_8 -> V_19 ) ;
int V_69 , V_17 ;
V_9 -> V_8 = V_8 ;
F_6 ( V_8 , V_70 , 0xBB00 ) ;
F_6 ( V_8 , V_71 , 0 ) ;
V_17 = F_13 ( V_8 , V_38 ) ;
V_17 &= ~ 0xf800 ;
V_17 |= 0x0800 ;
F_6 ( V_8 , V_38 , V_17 ) ;
V_69 = F_16 ( V_8 -> V_19 , & V_72 ) ;
if ( V_69 )
F_17 ( V_8 -> V_19 , L_12 ) ;
return 0 ;
}
static int F_18 ( struct V_73 * V_18 )
{
struct V_9 * V_9 ;
int V_69 ;
F_3 ( & V_18 -> V_19 , L_13 ) ;
V_9 = F_19 ( & V_18 -> V_19 , sizeof *V_9 , V_74 ) ;
if ( ! V_9 )
return - V_75 ;
V_9 -> V_76 = F_20 ( V_18 , & V_77 ) ;
if ( F_21 ( V_9 -> V_76 ) )
return F_22 ( V_9 -> V_76 ) ;
V_9 -> V_18 = V_18 ;
F_23 ( & V_18 -> V_19 , V_9 ) ;
V_9 -> V_37 = 1 ;
V_69 = F_24 ( & V_18 -> V_19 ,
& V_78 , & V_79 , 1 ) ;
return V_69 ;
}
static int F_25 ( struct V_73 * V_18 )
{
F_26 ( & V_18 -> V_19 ) ;
return 0 ;
}
