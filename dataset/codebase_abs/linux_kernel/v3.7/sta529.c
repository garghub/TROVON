static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
return true ;
default:
return false ;
}
}
static int F_2 ( struct V_16 * V_17 , enum
V_18 V_19 )
{
struct V_20 * V_20 = F_3 ( V_17 ) ;
switch ( V_19 ) {
case V_21 :
case V_22 :
F_4 ( V_17 , V_4 , V_23 ,
V_24 ) ;
F_4 ( V_17 , V_15 , V_25 ,
V_26 ) ;
break;
case V_27 :
if ( V_17 -> V_28 . V_29 == V_30 )
F_5 ( V_20 -> V_31 ) ;
F_4 ( V_17 , V_4 ,
V_23 , V_32 ) ;
F_4 ( V_17 , V_4 , V_33 ,
V_34 ) ;
F_4 ( V_17 , V_15 , V_25 ,
V_35 ) ;
break;
case V_30 :
break;
}
V_17 -> V_28 . V_29 = V_19 ;
return 0 ;
}
static int F_6 ( struct V_36 * V_37 ,
struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_37 -> V_44 ;
struct V_16 * V_17 = V_43 -> V_17 ;
int V_45 , V_46 , V_47 ;
int V_48 ;
switch ( F_7 ( V_39 ) ) {
case V_49 :
V_45 = 1 ;
V_48 = 0 ;
break;
case V_50 :
V_45 = 2 ;
V_48 = 1 ;
break;
case V_51 :
V_45 = 3 ;
V_48 = 2 ;
break;
default:
F_8 ( V_17 -> V_2 , L_1 ) ;
return - V_52 ;
}
switch ( F_9 ( V_39 ) ) {
case 8000 :
case 11025 :
V_46 = 0 ;
V_47 = 2 ;
break;
case 16000 :
case 22050 :
V_46 = 1 ;
V_47 = 0 ;
break;
case 32000 :
case 44100 :
case 48000 :
V_46 = 2 ;
V_47 = 0 ;
break;
default:
F_8 ( V_17 -> V_2 , L_2 ) ;
return - V_52 ;
}
if ( V_37 -> V_53 == V_54 ) {
F_4 ( V_17 , V_10 , V_55 ,
V_45 << 6 ) ;
F_4 ( V_17 , V_10 , V_56 ,
V_48 << 4 ) ;
F_4 ( V_17 , V_15 , V_57 ,
V_46 << 4 ) ;
} else {
F_4 ( V_17 , V_12 , V_55 ,
V_45 << 6 ) ;
F_4 ( V_17 , V_12 , V_56 ,
V_48 << 4 ) ;
F_4 ( V_17 , V_15 , V_58 ,
V_47 << 2 ) ;
}
return 0 ;
}
static int F_10 ( struct V_40 * V_41 , int V_59 )
{
T_1 V_60 = 0 ;
if ( V_59 )
V_60 |= V_61 ;
F_4 ( V_41 -> V_17 , V_4 , V_62 , V_60 ) ;
return 0 ;
}
static int F_11 ( struct V_40 * V_63 , T_2 V_64 )
{
struct V_16 * V_17 = V_63 -> V_17 ;
T_1 V_65 = 0 ;
switch ( V_64 & V_66 ) {
case V_67 :
V_65 = V_68 ;
break;
case V_69 :
V_65 = V_70 ;
break;
case V_71 :
V_65 = V_72 ;
break;
default:
return - V_52 ;
}
F_4 ( V_17 , V_9 , 0x0D , V_65 ) ;
return 0 ;
}
static int F_12 ( struct V_16 * V_17 )
{
struct V_20 * V_20 = F_3 ( V_17 ) ;
int V_73 ;
V_17 -> V_74 = V_20 -> V_31 ;
V_73 = F_13 ( V_17 , 8 , 8 , V_75 ) ;
if ( V_73 < 0 ) {
F_8 ( V_17 -> V_2 , L_3 , V_73 ) ;
return V_73 ;
}
F_2 ( V_17 , V_27 ) ;
return 0 ;
}
static int F_14 ( struct V_16 * V_17 )
{
F_2 ( V_17 , V_30 ) ;
return 0 ;
}
static int F_15 ( struct V_16 * V_17 )
{
F_2 ( V_17 , V_30 ) ;
return 0 ;
}
static int F_16 ( struct V_16 * V_17 )
{
F_2 ( V_17 , V_27 ) ;
return 0 ;
}
static T_3 int F_17 ( struct V_76 * V_77 ,
const struct V_78 * V_79 )
{
struct V_20 * V_20 ;
int V_73 ;
if ( ! F_18 ( V_77 -> V_80 , V_81 ) )
return - V_52 ;
V_20 = F_19 ( & V_77 -> V_2 , sizeof( struct V_20 ) , V_82 ) ;
if ( V_20 == NULL ) {
F_8 ( & V_77 -> V_2 , L_4 ) ;
return - V_83 ;
}
V_20 -> V_31 = F_20 ( V_77 , & V_84 ) ;
if ( F_21 ( V_20 -> V_31 ) ) {
V_73 = F_22 ( V_20 -> V_31 ) ;
F_8 ( & V_77 -> V_2 , L_5 , V_73 ) ;
return V_73 ;
}
F_23 ( V_77 , V_20 ) ;
V_73 = F_24 ( & V_77 -> V_2 ,
& V_85 , & V_86 , 1 ) ;
if ( V_73 != 0 )
F_8 ( & V_77 -> V_2 , L_6 , V_73 ) ;
return V_73 ;
}
static int T_4 F_25 ( struct V_76 * V_87 )
{
F_26 ( & V_87 -> V_2 ) ;
return 0 ;
}
