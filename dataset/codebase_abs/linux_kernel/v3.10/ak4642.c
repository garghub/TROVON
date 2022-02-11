static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = V_2 -> V_6 == V_7 ;
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_5 ) {
F_2 ( V_9 , V_10 , 0x91 ) ;
F_2 ( V_9 , V_11 , 0x91 ) ;
} else {
F_2 ( V_9 , V_12 , V_13 | V_14 ) ;
F_2 ( V_9 , V_15 , F_3 ( 0x3 ) | F_4 ( 0x3 ) ) ;
F_2 ( V_9 , V_16 , V_17 | V_18 ) ;
F_5 ( V_9 , V_19 , V_20 , V_20 ) ;
F_5 ( V_9 , V_21 , V_22 , V_22 ) ;
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
F_5 ( V_9 , V_19 , V_20 , 0 ) ;
F_5 ( V_9 , V_21 , V_22 , 0 ) ;
F_5 ( V_9 , V_16 , V_17 , 0 ) ;
}
}
static int F_7 ( struct V_3 * V_23 ,
int V_24 , unsigned int V_25 , int V_26 )
{
struct V_8 * V_9 = V_23 -> V_9 ;
T_1 V_27 ;
switch ( V_25 ) {
case 11289600 :
V_27 = V_28 ;
break;
case 12288000 :
V_27 = V_28 | V_29 ;
break;
case 12000000 :
V_27 = V_28 | V_30 ;
break;
case 24000000 :
V_27 = V_28 | V_30 | V_29 ;
break;
case 13500000 :
V_27 = V_31 | V_28 ;
break;
case 27000000 :
V_27 = V_31 | V_28 | V_29 ;
break;
default:
return - V_32 ;
}
F_5 ( V_9 , V_33 , V_34 , V_27 ) ;
return 0 ;
}
static int F_8 ( struct V_3 * V_4 , unsigned int V_35 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
T_1 V_36 ;
T_1 V_37 ;
V_36 = V_38 | V_39 ;
V_37 = 0 ;
switch ( V_35 & V_40 ) {
case V_41 :
V_36 |= V_42 ;
V_37 = V_43 ;
break;
case V_44 :
break;
default:
return - V_32 ;
}
F_5 ( V_9 , V_45 , V_42 | V_38 | V_39 , V_36 ) ;
F_5 ( V_9 , V_33 , V_46 , V_37 ) ;
V_36 = 0 ;
switch ( V_35 & V_47 ) {
case V_48 :
V_36 = V_49 ;
break;
case V_50 :
V_36 = V_51 ;
break;
default:
return - V_32 ;
break;
}
F_5 ( V_9 , V_33 , V_52 , V_36 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_53 * V_54 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
T_1 V_55 ;
switch ( F_10 ( V_54 ) ) {
case 7350 :
V_55 = V_56 ;
break;
case 8000 :
V_55 = 0 ;
break;
case 11025 :
V_55 = V_56 | V_57 ;
break;
case 12000 :
V_55 = V_57 ;
break;
case 14700 :
V_55 = V_56 | V_58 ;
break;
case 16000 :
V_55 = V_58 ;
break;
case 22050 :
V_55 = V_56 | V_58 | V_57 ;
break;
case 24000 :
V_55 = V_58 | V_57 ;
break;
case 29400 :
V_55 = V_59 | V_56 | V_58 ;
break;
case 32000 :
V_55 = V_59 | V_58 ;
break;
case 44100 :
V_55 = V_59 | V_56 | V_58 | V_57 ;
break;
case 48000 :
V_55 = V_59 | V_58 | V_57 ;
break;
default:
return - V_32 ;
break;
}
F_5 ( V_9 , V_60 , V_61 , V_55 ) ;
return 0 ;
}
static int F_11 ( struct V_8 * V_9 ,
enum V_62 V_63 )
{
switch ( V_63 ) {
case V_64 :
F_2 ( V_9 , V_19 , 0x00 ) ;
break;
default:
F_5 ( V_9 , V_19 , V_65 , V_65 ) ;
break;
}
V_9 -> V_66 . V_67 = V_63 ;
return 0 ;
}
static int F_12 ( struct V_8 * V_9 )
{
F_13 ( V_9 ) ;
return 0 ;
}
static int F_14 ( struct V_8 * V_9 )
{
int V_68 ;
V_68 = F_15 ( V_9 , 8 , 8 , V_69 ) ;
if ( V_68 < 0 ) {
F_16 ( V_9 -> V_70 , L_1 , V_68 ) ;
return V_68 ;
}
F_17 ( V_9 , V_71 ,
F_18 ( V_71 ) ) ;
F_11 ( V_9 , V_72 ) ;
return 0 ;
}
static int F_19 ( struct V_8 * V_9 )
{
F_11 ( V_9 , V_64 ) ;
return 0 ;
}
static int F_20 ( struct V_73 * V_74 ,
const struct V_75 * V_76 )
{
struct V_77 * V_78 = V_74 -> V_70 . V_79 ;
const struct V_80 * V_81 ;
V_81 = NULL ;
if ( V_78 ) {
const struct V_82 * V_83 ;
V_83 = F_21 ( V_84 , & V_74 -> V_70 ) ;
if ( V_83 )
V_81 = V_83 -> V_36 ;
} else {
V_81 = (struct V_80 * ) V_76 -> V_85 ;
}
if ( ! V_81 ) {
F_16 ( & V_74 -> V_70 , L_2 ) ;
return - V_32 ;
}
return F_22 ( & V_74 -> V_70 ,
V_81 , & V_86 , 1 ) ;
}
static int F_23 ( struct V_73 * V_87 )
{
F_24 ( & V_87 -> V_70 ) ;
return 0 ;
}
static int T_2 F_25 ( void )
{
int V_68 = 0 ;
#if F_26 ( V_88 ) || F_26 ( V_89 )
V_68 = F_27 ( & V_90 ) ;
#endif
return V_68 ;
}
static void T_3 F_28 ( void )
{
#if F_26 ( V_88 ) || F_26 ( V_89 )
F_29 ( & V_90 ) ;
#endif
}
