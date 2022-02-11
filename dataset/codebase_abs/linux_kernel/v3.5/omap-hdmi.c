static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_7 ;
V_7 = F_3 ( V_2 -> V_8 , 0 ,
V_9 , 128 ) ;
if ( V_7 < 0 ) {
F_4 ( V_4 -> V_10 , L_1 ) ;
return V_7 ;
}
if ( ! V_6 -> V_11 -> V_12 -> V_13 ( V_6 -> V_11 ) ) {
F_4 ( V_4 -> V_10 , L_2 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return V_6 -> V_11 -> V_12 -> V_15 ( V_6 -> V_11 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_18 * V_19 = & V_6 -> V_19 ;
struct V_20 * V_21 = & V_6 -> V_21 ;
int V_7 = 0 ;
switch ( F_7 ( V_17 ) ) {
case V_22 :
V_6 -> V_23 . V_24 = 16 ;
break;
case V_25 :
V_6 -> V_23 . V_24 = 32 ;
break;
default:
F_4 ( V_4 -> V_10 , L_3 ) ;
return - V_26 ;
}
V_6 -> V_23 . V_27 = V_28 ;
F_8 ( V_4 , V_2 ,
& V_6 -> V_23 ) ;
V_19 -> V_29 [ 0 ] &= ~ V_30 ;
V_19 -> V_29 [ 0 ] &= ~ V_31 ;
V_19 -> V_29 [ 0 ] |= V_32 ;
V_19 -> V_29 [ 0 ] |= V_33 ;
V_19 -> V_29 [ 0 ] |= V_34 ;
V_19 -> V_29 [ 1 ] = V_35 ;
V_19 -> V_29 [ 2 ] |= V_36 ;
V_19 -> V_29 [ 2 ] |= V_37 ;
switch ( F_9 ( V_17 ) ) {
case 32000 :
V_19 -> V_29 [ 3 ] |= V_38 ;
break;
case 44100 :
V_19 -> V_29 [ 3 ] |= V_39 ;
break;
case 48000 :
V_19 -> V_29 [ 3 ] |= V_40 ;
break;
case 88200 :
V_19 -> V_29 [ 3 ] |= V_41 ;
break;
case 96000 :
V_19 -> V_29 [ 3 ] |= V_42 ;
break;
case 176400 :
V_19 -> V_29 [ 3 ] |= V_43 ;
break;
case 192000 :
V_19 -> V_29 [ 3 ] |= V_44 ;
break;
default:
F_4 ( V_4 -> V_10 , L_4 ) ;
return - V_26 ;
}
V_19 -> V_29 [ 3 ] |= V_45 ;
switch ( F_7 ( V_17 ) ) {
case V_22 :
V_19 -> V_29 [ 4 ] |= V_46 ;
V_19 -> V_29 [ 4 ] &= ~ V_47 ;
break;
case V_25 :
V_19 -> V_29 [ 4 ] |= V_48 ;
V_19 -> V_29 [ 4 ] |= V_47 ;
break;
default:
F_4 ( V_4 -> V_10 , L_3 ) ;
return - V_26 ;
}
V_21 -> V_49 = ( F_10 ( V_17 ) - 1 )
& V_50 ;
V_21 -> V_49 |= V_51 ;
V_21 -> V_52 = V_53 ;
V_21 -> V_52 |= V_54 ;
V_21 -> V_55 = 0 ;
if ( F_10 ( V_17 ) == 2 )
V_21 -> V_56 = 0x0 ;
else
V_21 -> V_56 = 0x13 ;
V_21 -> V_57 = V_58 ;
V_21 -> V_57 |= ( 0 & V_59 ) ;
V_6 -> V_60 . V_19 = V_19 ;
V_6 -> V_60 . V_21 = V_21 ;
V_7 = V_6 -> V_11 -> V_12 -> V_61 ( V_6 -> V_11 ,
& V_6 -> V_60 ) ;
return V_7 ;
}
static int F_11 ( struct V_1 * V_2 , int V_62 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_7 = 0 ;
switch ( V_62 ) {
case V_63 :
case V_64 :
case V_65 :
V_7 = V_6 -> V_11 -> V_12 -> V_66 ( V_6 -> V_11 ) ;
break;
case V_67 :
case V_68 :
case V_69 :
V_6 -> V_11 -> V_12 -> V_70 ( V_6 -> V_11 ) ;
break;
default:
V_7 = - V_26 ;
}
return V_7 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
V_6 -> V_11 -> V_12 -> V_71 ( V_6 -> V_11 ) ;
}
static T_1 int F_13 ( struct V_72 * V_73 )
{
int V_74 ;
struct V_75 * V_76 ;
struct V_5 * V_77 ;
bool V_78 = false ;
V_77 = F_14 ( & V_73 -> V_10 , sizeof( * V_77 ) , V_79 ) ;
if ( V_77 == NULL ) {
F_4 ( & V_73 -> V_10 , L_5 ) ;
return - V_80 ;
}
V_76 = F_15 ( V_73 , V_81 , 0 ) ;
if ( ! V_76 ) {
F_4 ( & V_73 -> V_10 , L_6 ) ;
return - V_14 ;
}
V_77 -> V_23 . V_82 = V_76 -> V_83
+ V_84 ;
V_76 = F_15 ( V_73 , V_85 , 0 ) ;
if ( ! V_76 ) {
F_4 ( & V_73 -> V_10 , L_7 ) ;
return - V_14 ;
}
V_77 -> V_23 . V_86 = V_76 -> V_83 ;
V_77 -> V_23 . V_87 = L_8 ;
V_77 -> V_23 . V_88 = V_89 ;
F_16 (hdmi_data->dssdev) {
F_17 ( V_77 -> V_11 ) ;
if ( ! V_77 -> V_11 -> V_12 ) {
F_18 ( V_77 -> V_11 ) ;
continue;
}
if ( V_77 -> V_11 -> type == V_90 ) {
V_78 = true ;
break;
}
}
if ( ! V_78 ) {
F_4 ( & V_73 -> V_10 , L_9 ) ;
return - V_14 ;
}
F_19 ( & V_73 -> V_10 , V_77 ) ;
V_74 = F_20 ( & V_73 -> V_10 , & V_91 ) ;
return V_74 ;
}
static int T_2 F_21 ( struct V_72 * V_73 )
{
struct V_5 * V_77 = F_22 ( & V_73 -> V_10 ) ;
F_23 ( & V_73 -> V_10 ) ;
if ( V_77 == NULL ) {
F_4 ( & V_73 -> V_10 , L_10 ) ;
return - V_14 ;
}
F_18 ( V_77 -> V_11 ) ;
return 0 ;
}
