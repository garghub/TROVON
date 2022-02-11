static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_8 ;
switch ( V_5 ) {
case V_9 :
V_8 = F_2 ( V_7 , V_10 ) ;
V_8 |= V_11 ;
F_3 ( V_7 , V_10 , V_8 ) ;
break;
case V_12 :
V_8 = F_2 ( V_7 , V_10 ) ;
V_8 &= ~ V_11 ;
F_3 ( V_7 , V_10 , V_8 ) ;
break;
}
return 0 ;
}
static int F_4 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_6 * V_7 = V_18 -> V_7 ;
T_1 V_19 ;
V_19 = F_2 ( V_7 , V_20 ) ;
V_19 &= ~ V_21 ;
switch ( F_5 ( V_16 ) ) {
case 8000 :
V_19 |= V_22 ;
break;
case 12000 :
V_19 |= V_23 ;
break;
case 16000 :
V_19 |= V_24 ;
break;
case 24000 :
V_19 |= V_25 ;
break;
case 11025 :
V_19 |= V_26 ;
break;
case 22050 :
V_19 |= V_27 ;
break;
case 32000 :
V_19 |= V_28 ;
break;
case 44100 :
V_19 |= V_29 ;
break;
case 48000 :
V_19 |= V_30 ;
break;
default:
return - V_31 ;
}
F_3 ( V_7 , V_20 , V_19 ) ;
return 0 ;
}
static int F_6 ( struct V_17 * V_18 , int V_32 ,
unsigned int V_33 , int V_34 )
{
struct V_6 * V_7 = V_18 -> V_7 ;
T_1 V_35 ;
V_35 = F_2 ( V_7 , V_20 ) ;
V_35 &= ~ V_36 ;
switch ( V_33 ) {
case 11289600 :
V_35 |= V_37 ;
break;
case 12000000 :
V_35 |= V_38 ;
break;
case 12288000 :
V_35 |= V_39 ;
break;
case 13000000 :
V_35 |= V_40 ;
break;
case 13500000 :
V_35 |= V_41 ;
break;
case 19200000 :
V_35 |= V_42 ;
break;
case 24000000 :
V_35 |= V_43 ;
break;
case 26000000 :
V_35 |= V_44 ;
break;
case 27000000 :
V_35 |= V_45 ;
break;
default:
return - V_31 ;
}
F_3 ( V_7 , V_20 , V_35 ) ;
return 0 ;
}
static int F_7 ( struct V_17 * V_18 , unsigned int V_46 )
{
struct V_6 * V_7 = V_18 -> V_7 ;
T_1 V_47 ;
T_1 V_48 ;
V_47 = F_2 ( V_7 , V_49 ) ;
switch ( V_46 & V_50 ) {
case V_51 :
V_47 |= V_52 ;
break;
case V_53 :
V_47 &= ~ ( V_52 ) ;
break;
default:
return - V_31 ;
}
V_48 = F_2 ( V_7 , V_54 ) ;
V_48 &= ~ V_55 ;
switch ( V_46 & V_56 ) {
case V_57 :
V_48 |= V_58 ;
break;
case V_59 :
V_48 |= V_60 ;
break;
case V_61 :
V_48 |= V_62 ;
V_48 |= V_63 ;
V_48 |= V_64 ;
break;
default:
return - V_31 ;
}
F_3 ( V_7 , V_49 , V_47 ) ;
F_3 ( V_7 , V_54 , V_48 ) ;
return 0 ;
}
static int F_8 ( struct V_6 * V_7 ,
enum V_65 V_66 )
{
T_1 V_8 ;
switch ( V_66 ) {
case V_67 :
case V_68 :
case V_69 :
V_8 = F_2 ( V_7 , V_70 ) ;
F_3 ( V_7 , V_70 ,
V_8 | V_71 ) ;
break;
case V_72 :
F_3 ( V_7 , V_70 , 0x00 ) ;
break;
}
V_7 -> V_73 . V_74 = V_66 ;
return 0 ;
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_75 * V_76 = F_10 ( V_7 ) ;
int V_77 ;
V_7 -> V_78 = ( V_79 ) V_80 ;
V_77 = F_11 ( V_7 , 8 , 8 , V_76 -> V_81 ) ;
if ( V_77 < 0 ) {
F_12 ( V_7 -> V_82 , L_1 , V_77 ) ;
return V_77 ;
}
F_13 ( V_7 , V_83 ,
F_14 ( V_83 ) ) ;
F_8 ( V_7 , V_69 ) ;
return V_77 ;
}
static int F_15 ( struct V_6 * V_7 )
{
F_8 ( V_7 , V_72 ) ;
return 0 ;
}
static int T_2 F_16 ( struct V_84 * V_85 ,
const struct V_86 * V_87 )
{
struct V_75 * V_76 ;
int V_77 ;
V_76 = F_17 ( sizeof( struct V_75 ) , V_88 ) ;
if ( V_76 == NULL )
return - V_89 ;
F_18 ( V_85 , V_76 ) ;
V_76 -> V_90 = V_85 ;
V_76 -> V_81 = V_91 ;
V_77 = F_19 ( & V_85 -> V_82 ,
& V_92 , & V_93 , 1 ) ;
if ( V_77 < 0 )
F_20 ( V_76 ) ;
return V_77 ;
}
static T_3 int F_21 ( struct V_84 * V_85 )
{
F_22 ( & V_85 -> V_82 ) ;
F_20 ( F_23 ( V_85 ) ) ;
return 0 ;
}
static int T_4 F_24 ( void )
{
return F_25 ( & V_94 ) ;
}
static void T_5 F_26 ( void )
{
F_27 ( & V_94 ) ;
}
