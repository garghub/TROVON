static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = V_2 -> V_6 == V_7 ;
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_5 ) {
F_2 ( V_9 , V_10 , V_11 , V_11 ) ;
F_2 ( V_9 , V_12 , V_13 , V_13 ) ;
F_3 ( V_9 , V_14 , 0x91 ) ;
F_3 ( V_9 , V_15 , 0x91 ) ;
F_2 ( V_9 , V_16 , V_17 | V_18 | V_19 ,
V_17 | V_18 | V_19 ) ;
F_2 ( V_9 , V_20 , V_21 , V_22 ) ;
F_2 ( V_9 , V_20 , V_23 , V_23 ) ;
} else {
F_3 ( V_9 , V_24 , V_25 | V_26 ) ;
F_3 ( V_9 , V_27 , F_4 ( 0x3 ) | F_5 ( 0x3 ) ) ;
F_3 ( V_9 , V_28 , V_29 | V_30 ) ;
F_2 ( V_9 , V_16 , V_17 | V_31 ,
V_17 | V_31 ) ;
F_2 ( V_9 , V_32 , V_33 , V_33 ) ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = V_2 -> V_6 == V_7 ;
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_5 ) {
F_2 ( V_9 , V_20 , V_23 , 0 ) ;
F_2 ( V_9 , V_20 , V_21 , 0 ) ;
F_2 ( V_9 , V_16 , V_18 | V_19 , 0 ) ;
F_2 ( V_9 , V_12 , V_13 , 0 ) ;
F_2 ( V_9 , V_10 , V_11 , 0 ) ;
} else {
F_2 ( V_9 , V_16 , V_31 , 0 ) ;
F_2 ( V_9 , V_32 , V_33 , 0 ) ;
F_2 ( V_9 , V_28 , V_29 , 0 ) ;
}
}
static int F_7 ( struct V_3 * V_34 ,
int V_35 , unsigned int V_36 , int V_37 )
{
struct V_8 * V_9 = V_34 -> V_9 ;
T_1 V_38 ;
switch ( V_36 ) {
case 11289600 :
V_38 = V_39 ;
break;
case 12288000 :
V_38 = V_39 | V_40 ;
break;
case 12000000 :
V_38 = V_39 | V_41 ;
break;
case 24000000 :
V_38 = V_39 | V_41 | V_40 ;
break;
case 13500000 :
V_38 = V_42 | V_39 ;
break;
case 27000000 :
V_38 = V_42 | V_39 | V_40 ;
break;
default:
return - V_43 ;
}
F_2 ( V_9 , V_44 , V_45 , V_38 ) ;
return 0 ;
}
static int F_8 ( struct V_3 * V_4 , unsigned int V_46 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
T_1 V_47 ;
T_1 V_48 ;
V_47 = V_49 | V_50 ;
V_48 = 0 ;
switch ( V_46 & V_51 ) {
case V_52 :
V_47 |= V_53 ;
V_48 = V_54 ;
break;
case V_55 :
break;
default:
return - V_43 ;
}
F_2 ( V_9 , V_20 , V_53 | V_49 | V_50 , V_47 ) ;
F_2 ( V_9 , V_44 , V_56 , V_48 ) ;
V_47 = 0 ;
switch ( V_46 & V_57 ) {
case V_58 :
V_47 = V_59 ;
break;
case V_60 :
V_47 = V_61 ;
break;
default:
return - V_43 ;
break;
}
F_2 ( V_9 , V_44 , V_62 , V_47 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_63 * V_64 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
T_1 V_65 ;
switch ( F_10 ( V_64 ) ) {
case 7350 :
V_65 = V_66 ;
break;
case 8000 :
V_65 = 0 ;
break;
case 11025 :
V_65 = V_66 | V_67 ;
break;
case 12000 :
V_65 = V_67 ;
break;
case 14700 :
V_65 = V_66 | V_68 ;
break;
case 16000 :
V_65 = V_68 ;
break;
case 22050 :
V_65 = V_66 | V_68 | V_67 ;
break;
case 24000 :
V_65 = V_68 | V_67 ;
break;
case 29400 :
V_65 = V_69 | V_66 | V_68 ;
break;
case 32000 :
V_65 = V_69 | V_68 ;
break;
case 44100 :
V_65 = V_69 | V_66 | V_68 | V_67 ;
break;
case 48000 :
V_65 = V_69 | V_68 | V_67 ;
break;
default:
return - V_43 ;
break;
}
F_2 ( V_9 , V_70 , V_71 , V_65 ) ;
return 0 ;
}
static int F_11 ( struct V_8 * V_9 )
{
F_12 ( V_9 ) ;
return 0 ;
}
static int F_13 ( struct V_8 * V_9 )
{
struct V_72 * V_73 = F_14 ( V_9 ) ;
int V_74 ;
F_15 ( V_9 -> V_75 , L_1 , V_76 ) ;
V_74 = F_16 ( V_9 , 8 , 8 , V_73 -> V_77 ) ;
if ( V_74 < 0 ) {
F_17 ( V_9 -> V_75 , L_2 , V_74 ) ;
return V_74 ;
}
F_18 ( V_9 , V_78 ,
F_19 ( V_78 ) ) ;
return 0 ;
}
static T_2 int F_20 ( struct V_79 * V_80 ,
const struct V_81 * V_82 )
{
struct V_72 * V_73 ;
int V_74 ;
V_73 = F_21 ( sizeof( struct V_72 ) , V_83 ) ;
if ( ! V_73 )
return - V_84 ;
F_22 ( V_80 , V_73 ) ;
V_73 -> V_77 = V_85 ;
V_74 = F_23 ( & V_80 -> V_75 ,
& V_86 , & V_87 , 1 ) ;
if ( V_74 < 0 )
F_24 ( V_73 ) ;
return V_74 ;
}
static T_3 int F_25 ( struct V_79 * V_88 )
{
F_26 ( & V_88 -> V_75 ) ;
F_24 ( F_27 ( V_88 ) ) ;
return 0 ;
}
static int T_4 F_28 ( void )
{
int V_74 = 0 ;
#if F_29 ( V_89 ) || F_29 ( V_90 )
V_74 = F_30 ( & V_91 ) ;
#endif
return V_74 ;
}
static void T_5 F_31 ( void )
{
#if F_29 ( V_89 ) || F_29 ( V_90 )
F_32 ( & V_91 ) ;
#endif
}
