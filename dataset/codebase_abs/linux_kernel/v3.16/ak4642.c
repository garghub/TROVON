static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = V_2 -> V_6 == V_7 ;
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_5 ) {
F_2 ( V_9 , V_10 , 0x91 ) ;
F_2 ( V_9 , V_11 , 0x91 ) ;
} else {
F_3 ( V_9 , V_12 , V_13 | V_14 , V_13 | V_14 ) ;
F_2 ( V_9 , V_15 , F_4 ( 0x3 ) | F_5 ( 0x3 ) ) ;
F_2 ( V_9 , V_16 , V_17 | V_18 ) ;
F_3 ( V_9 , V_19 , V_20 , V_20 ) ;
F_3 ( V_9 , V_21 , V_22 , V_22 ) ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = V_2 -> V_6 == V_7 ;
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_5 ) {
} else {
F_3 ( V_9 , V_19 , V_20 , 0 ) ;
F_3 ( V_9 , V_21 , V_22 , 0 ) ;
F_3 ( V_9 , V_16 , V_17 , 0 ) ;
}
}
static int F_7 ( struct V_3 * V_23 ,
int V_24 , unsigned int V_25 , int V_26 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
struct V_27 * V_28 = F_8 ( V_9 ) ;
T_1 V_29 ;
int V_30 = 0 ;
switch ( V_25 ) {
case 11289600 :
V_29 = V_31 ;
break;
case 12288000 :
V_29 = V_31 | V_32 ;
break;
case 12000000 :
V_29 = V_31 | V_33 ;
break;
case 24000000 :
V_29 = V_31 | V_33 | V_32 ;
break;
case 13500000 :
V_29 = V_34 | V_31 ;
break;
case 27000000 :
V_29 = V_34 | V_31 | V_32 ;
break;
case 19200000 :
V_29 = V_34 ;
V_30 = 1 ;
break;
case 13000000 :
V_29 = V_34 | V_31 | V_33 ;
V_30 = 1 ;
break;
case 26000000 :
V_29 = V_34 | V_31 | V_33 | V_32 ;
V_30 = 1 ;
break;
default:
return - V_35 ;
}
if ( V_30 && ! V_28 -> V_36 -> V_37 )
return - V_35 ;
F_3 ( V_9 , V_38 , V_39 , V_29 ) ;
return 0 ;
}
static int F_9 ( struct V_3 * V_4 , unsigned int V_40 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
T_1 V_41 ;
T_1 V_42 ;
V_41 = V_43 | V_44 ;
V_42 = 0 ;
switch ( V_40 & V_45 ) {
case V_46 :
V_41 |= V_47 ;
V_42 = V_48 ;
break;
case V_49 :
break;
default:
return - V_35 ;
}
F_3 ( V_9 , V_50 , V_47 | V_43 | V_44 , V_41 ) ;
F_3 ( V_9 , V_38 , V_51 , V_42 ) ;
V_41 = 0 ;
switch ( V_40 & V_52 ) {
case V_53 :
V_41 = V_54 ;
break;
case V_55 :
V_41 = V_56 ;
break;
default:
return - V_35 ;
}
F_3 ( V_9 , V_38 , V_57 , V_41 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_58 * V_59 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
T_1 V_60 ;
switch ( F_11 ( V_59 ) ) {
case 7350 :
V_60 = V_61 ;
break;
case 8000 :
V_60 = 0 ;
break;
case 11025 :
V_60 = V_61 | V_62 ;
break;
case 12000 :
V_60 = V_62 ;
break;
case 14700 :
V_60 = V_61 | V_63 ;
break;
case 16000 :
V_60 = V_63 ;
break;
case 22050 :
V_60 = V_61 | V_63 | V_62 ;
break;
case 24000 :
V_60 = V_63 | V_62 ;
break;
case 29400 :
V_60 = V_64 | V_61 | V_63 ;
break;
case 32000 :
V_60 = V_64 | V_63 ;
break;
case 44100 :
V_60 = V_64 | V_61 | V_63 | V_62 ;
break;
case 48000 :
V_60 = V_64 | V_63 | V_62 ;
break;
default:
return - V_35 ;
}
F_3 ( V_9 , V_65 , V_66 , V_60 ) ;
return 0 ;
}
static int F_12 ( struct V_8 * V_9 ,
enum V_67 V_68 )
{
switch ( V_68 ) {
case V_69 :
F_2 ( V_9 , V_19 , 0x00 ) ;
break;
default:
F_3 ( V_9 , V_19 , V_70 , V_70 ) ;
break;
}
V_9 -> V_71 . V_72 = V_68 ;
return 0 ;
}
static int F_13 ( struct V_8 * V_9 )
{
struct V_73 * V_73 = F_14 ( V_9 -> V_74 , NULL ) ;
F_15 ( V_73 ) ;
F_16 ( V_73 ) ;
return 0 ;
}
static int F_17 ( struct V_8 * V_9 )
{
F_12 ( V_9 , V_75 ) ;
return 0 ;
}
static int F_18 ( struct V_8 * V_9 )
{
F_12 ( V_9 , V_69 ) ;
return 0 ;
}
static int F_19 ( struct V_76 * V_77 ,
const struct V_78 * V_79 )
{
struct V_80 * V_81 = V_77 -> V_74 . V_82 ;
const struct V_83 * V_36 = NULL ;
struct V_73 * V_73 ;
struct V_27 * V_28 ;
if ( V_81 ) {
const struct V_84 * V_85 ;
V_85 = F_20 ( V_86 , & V_77 -> V_74 ) ;
if ( V_85 )
V_36 = V_85 -> V_41 ;
} else {
V_36 = ( const struct V_83 * ) V_79 -> V_87 ;
}
if ( ! V_36 ) {
F_21 ( & V_77 -> V_74 , L_1 ) ;
return - V_35 ;
}
V_28 = F_22 ( & V_77 -> V_74 , sizeof( * V_28 ) , V_88 ) ;
if ( ! V_28 )
return - V_89 ;
V_28 -> V_36 = V_36 ;
F_23 ( V_77 , V_28 ) ;
V_73 = F_24 ( V_77 , V_36 -> V_90 ) ;
if ( F_25 ( V_73 ) )
return F_26 ( V_73 ) ;
return F_27 ( & V_77 -> V_74 ,
& V_91 , & V_92 , 1 ) ;
}
static int F_28 ( struct V_76 * V_93 )
{
F_29 ( & V_93 -> V_74 ) ;
return 0 ;
}
