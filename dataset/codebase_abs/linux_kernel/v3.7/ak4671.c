static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
switch ( V_5 ) {
case V_8 :
F_2 ( V_7 , V_9 ,
V_10 , V_10 ) ;
break;
case V_11 :
F_2 ( V_7 , V_9 ,
V_10 , 0 ) ;
break;
}
return 0 ;
}
static int F_3 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_6 * V_7 = V_17 -> V_7 ;
T_1 V_18 ;
V_18 = F_4 ( V_7 , V_19 ) ;
V_18 &= ~ V_20 ;
switch ( F_5 ( V_15 ) ) {
case 8000 :
V_18 |= V_21 ;
break;
case 12000 :
V_18 |= V_22 ;
break;
case 16000 :
V_18 |= V_23 ;
break;
case 24000 :
V_18 |= V_24 ;
break;
case 11025 :
V_18 |= V_25 ;
break;
case 22050 :
V_18 |= V_26 ;
break;
case 32000 :
V_18 |= V_27 ;
break;
case 44100 :
V_18 |= V_28 ;
break;
case 48000 :
V_18 |= V_29 ;
break;
default:
return - V_30 ;
}
F_6 ( V_7 , V_19 , V_18 ) ;
return 0 ;
}
static int F_7 ( struct V_16 * V_17 , int V_31 ,
unsigned int V_32 , int V_33 )
{
struct V_6 * V_7 = V_17 -> V_7 ;
T_1 V_34 ;
V_34 = F_4 ( V_7 , V_19 ) ;
V_34 &= ~ V_35 ;
switch ( V_32 ) {
case 11289600 :
V_34 |= V_36 ;
break;
case 12000000 :
V_34 |= V_37 ;
break;
case 12288000 :
V_34 |= V_38 ;
break;
case 13000000 :
V_34 |= V_39 ;
break;
case 13500000 :
V_34 |= V_40 ;
break;
case 19200000 :
V_34 |= V_41 ;
break;
case 24000000 :
V_34 |= V_42 ;
break;
case 26000000 :
V_34 |= V_43 ;
break;
case 27000000 :
V_34 |= V_44 ;
break;
default:
return - V_30 ;
}
F_6 ( V_7 , V_19 , V_34 ) ;
return 0 ;
}
static int F_8 ( struct V_16 * V_17 , unsigned int V_45 )
{
struct V_6 * V_7 = V_17 -> V_7 ;
T_1 V_46 ;
T_1 V_47 ;
V_46 = F_4 ( V_7 , V_48 ) ;
switch ( V_45 & V_49 ) {
case V_50 :
V_46 |= V_51 ;
break;
case V_52 :
V_46 &= ~ ( V_51 ) ;
break;
default:
return - V_30 ;
}
V_47 = F_4 ( V_7 , V_53 ) ;
V_47 &= ~ V_54 ;
switch ( V_45 & V_55 ) {
case V_56 :
V_47 |= V_57 ;
break;
case V_58 :
V_47 |= V_59 ;
break;
case V_60 :
V_47 |= V_61 ;
V_47 |= V_62 ;
V_47 |= V_63 ;
break;
default:
return - V_30 ;
}
F_6 ( V_7 , V_48 , V_46 ) ;
F_6 ( V_7 , V_53 , V_47 ) ;
return 0 ;
}
static int F_9 ( struct V_6 * V_7 ,
enum V_64 V_65 )
{
switch ( V_65 ) {
case V_66 :
case V_67 :
case V_68 :
F_2 ( V_7 , V_69 ,
V_70 , V_70 ) ;
break;
case V_71 :
F_6 ( V_7 , V_69 , 0x00 ) ;
break;
}
V_7 -> V_72 . V_73 = V_65 ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 )
{
struct V_74 * V_75 = F_11 ( V_7 ) ;
int V_76 ;
V_76 = F_12 ( V_7 , 8 , 8 , V_75 -> V_77 ) ;
if ( V_76 < 0 ) {
F_13 ( V_7 -> V_78 , L_1 , V_76 ) ;
return V_76 ;
}
F_14 ( V_7 , V_79 ,
F_15 ( V_79 ) ) ;
F_9 ( V_7 , V_68 ) ;
return V_76 ;
}
static int F_16 ( struct V_6 * V_7 )
{
F_9 ( V_7 , V_71 ) ;
return 0 ;
}
static int T_2 F_17 ( struct V_80 * V_81 ,
const struct V_82 * V_83 )
{
struct V_74 * V_75 ;
int V_76 ;
V_75 = F_18 ( & V_81 -> V_78 , sizeof( struct V_74 ) ,
V_84 ) ;
if ( V_75 == NULL )
return - V_85 ;
F_19 ( V_81 , V_75 ) ;
V_75 -> V_77 = V_86 ;
V_76 = F_20 ( & V_81 -> V_78 ,
& V_87 , & V_88 , 1 ) ;
return V_76 ;
}
static T_3 int F_21 ( struct V_80 * V_81 )
{
F_22 ( & V_81 -> V_78 ) ;
return 0 ;
}
