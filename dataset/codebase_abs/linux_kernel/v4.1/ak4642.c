static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
switch ( V_5 ) {
case V_9 :
case V_10 :
F_3 ( V_7 , V_11 , V_12 , V_12 ) ;
break;
case V_13 :
case V_14 :
F_4 ( 300 ) ;
F_3 ( V_7 , V_11 , V_12 , 0 ) ;
break;
}
return 0 ;
}
static int F_5 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
int V_19 = V_16 -> V_20 == V_21 ;
struct V_6 * V_7 = V_18 -> V_7 ;
if ( V_19 ) {
F_6 ( V_7 , V_22 , 0x91 ) ;
F_6 ( V_7 , V_23 , 0x91 ) ;
} else {
F_3 ( V_7 , V_24 , V_25 | V_26 , V_25 | V_26 ) ;
F_6 ( V_7 , V_27 , F_7 ( 0x3 ) | F_8 ( 0x3 ) ) ;
F_6 ( V_7 , V_28 , V_29 | V_30 ) ;
F_3 ( V_7 , V_31 , V_32 , V_32 ) ;
F_3 ( V_7 , V_33 , V_34 , V_34 ) ;
}
return 0 ;
}
static void F_9 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
int V_19 = V_16 -> V_20 == V_21 ;
struct V_6 * V_7 = V_18 -> V_7 ;
if ( V_19 ) {
} else {
F_3 ( V_7 , V_31 , V_32 , 0 ) ;
F_3 ( V_7 , V_33 , V_34 , 0 ) ;
F_3 ( V_7 , V_28 , V_29 , 0 ) ;
}
}
static int F_10 ( struct V_17 * V_35 ,
int V_36 , unsigned int V_37 , int V_38 )
{
struct V_6 * V_7 = V_35 -> V_7 ;
struct V_39 * V_40 = F_11 ( V_7 ) ;
T_1 V_41 ;
int V_42 = 0 ;
switch ( V_37 ) {
case 11289600 :
V_41 = V_43 ;
break;
case 12288000 :
V_41 = V_43 | V_44 ;
break;
case 12000000 :
V_41 = V_43 | V_45 ;
break;
case 24000000 :
V_41 = V_43 | V_45 | V_44 ;
break;
case 13500000 :
V_41 = V_46 | V_43 ;
break;
case 27000000 :
V_41 = V_46 | V_43 | V_44 ;
break;
case 19200000 :
V_41 = V_46 ;
V_42 = 1 ;
break;
case 13000000 :
V_41 = V_46 | V_43 | V_45 ;
V_42 = 1 ;
break;
case 26000000 :
V_41 = V_46 | V_43 | V_45 | V_44 ;
V_42 = 1 ;
break;
default:
return - V_47 ;
}
if ( V_42 && ! V_40 -> V_48 -> V_49 )
return - V_47 ;
F_3 ( V_7 , V_50 , V_51 , V_41 ) ;
return 0 ;
}
static int F_12 ( struct V_17 * V_18 , unsigned int V_52 )
{
struct V_6 * V_7 = V_18 -> V_7 ;
T_1 V_53 ;
T_1 V_54 ;
V_53 = V_55 | V_56 ;
V_54 = 0 ;
switch ( V_52 & V_57 ) {
case V_58 :
V_53 |= V_59 ;
V_54 = V_60 ;
break;
case V_61 :
break;
default:
return - V_47 ;
}
F_3 ( V_7 , V_62 , V_59 | V_55 | V_56 , V_53 ) ;
F_3 ( V_7 , V_50 , V_63 , V_54 ) ;
V_53 = 0 ;
switch ( V_52 & V_64 ) {
case V_65 :
V_53 = V_66 ;
break;
case V_67 :
V_53 = V_68 ;
break;
default:
return - V_47 ;
}
F_3 ( V_7 , V_50 , V_69 , V_53 ) ;
return 0 ;
}
static int F_13 ( struct V_15 * V_16 ,
struct V_70 * V_71 ,
struct V_17 * V_18 )
{
struct V_6 * V_7 = V_18 -> V_7 ;
T_1 V_72 ;
switch ( F_14 ( V_71 ) ) {
case 7350 :
V_72 = V_73 ;
break;
case 8000 :
V_72 = 0 ;
break;
case 11025 :
V_72 = V_73 | V_74 ;
break;
case 12000 :
V_72 = V_74 ;
break;
case 14700 :
V_72 = V_73 | V_75 ;
break;
case 16000 :
V_72 = V_75 ;
break;
case 22050 :
V_72 = V_73 | V_75 | V_74 ;
break;
case 24000 :
V_72 = V_75 | V_74 ;
break;
case 29400 :
V_72 = V_76 | V_73 | V_75 ;
break;
case 32000 :
V_72 = V_76 | V_75 ;
break;
case 44100 :
V_72 = V_76 | V_73 | V_75 | V_74 ;
break;
case 48000 :
V_72 = V_76 | V_75 | V_74 ;
break;
default:
return - V_47 ;
}
F_3 ( V_7 , V_77 , V_78 , V_72 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 ,
enum V_79 V_80 )
{
switch ( V_80 ) {
case V_81 :
F_6 ( V_7 , V_31 , 0x00 ) ;
break;
default:
F_3 ( V_7 , V_31 , V_82 , V_82 ) ;
break;
}
V_7 -> V_8 . V_83 = V_80 ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 )
{
struct V_84 * V_84 = F_17 ( V_7 -> V_85 , NULL ) ;
F_18 ( V_84 ) ;
F_19 ( V_84 ) ;
return 0 ;
}
static int F_20 ( struct V_86 * V_87 ,
const struct V_88 * V_89 )
{
struct V_90 * V_91 = V_87 -> V_85 . V_92 ;
const struct V_93 * V_48 = NULL ;
struct V_84 * V_84 ;
struct V_39 * V_40 ;
if ( V_91 ) {
const struct V_94 * V_95 ;
V_95 = F_21 ( V_96 , & V_87 -> V_85 ) ;
if ( V_95 )
V_48 = V_95 -> V_53 ;
} else {
V_48 = ( const struct V_93 * ) V_89 -> V_97 ;
}
if ( ! V_48 ) {
F_22 ( & V_87 -> V_85 , L_1 ) ;
return - V_47 ;
}
V_40 = F_23 ( & V_87 -> V_85 , sizeof( * V_40 ) , V_98 ) ;
if ( ! V_40 )
return - V_99 ;
V_40 -> V_48 = V_48 ;
F_24 ( V_87 , V_40 ) ;
V_84 = F_25 ( V_87 , V_48 -> V_100 ) ;
if ( F_26 ( V_84 ) )
return F_27 ( V_84 ) ;
return F_28 ( & V_87 -> V_85 ,
& V_101 , & V_102 , 1 ) ;
}
static int F_29 ( struct V_86 * V_103 )
{
F_30 ( & V_103 -> V_85 ) ;
return 0 ;
}
