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
F_5 ( V_4 , V_2 , & V_6 -> V_15 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return V_6 -> V_11 -> V_12 -> V_16 ( V_6 -> V_11 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_19 * V_20 = & V_6 -> V_20 ;
struct V_21 * V_22 = & V_6 -> V_22 ;
struct V_23 * V_24 ;
int V_7 = 0 ;
V_24 = F_8 ( V_4 , V_2 ) ;
switch ( F_9 ( V_18 ) ) {
case V_25 :
V_24 -> V_26 = 16 ;
break;
case V_27 :
V_24 -> V_26 = 32 ;
break;
default:
F_4 ( V_4 -> V_10 , L_3 ) ;
return - V_28 ;
}
V_24 -> V_29 = 32 ;
V_20 -> V_30 [ 0 ] &= ~ V_31 ;
V_20 -> V_30 [ 0 ] &= ~ V_32 ;
V_20 -> V_30 [ 0 ] |= V_33 ;
V_20 -> V_30 [ 0 ] |= V_34 ;
V_20 -> V_30 [ 0 ] |= V_35 ;
V_20 -> V_30 [ 1 ] = V_36 ;
V_20 -> V_30 [ 2 ] |= V_37 ;
V_20 -> V_30 [ 2 ] |= V_38 ;
switch ( F_10 ( V_18 ) ) {
case 32000 :
V_20 -> V_30 [ 3 ] |= V_39 ;
break;
case 44100 :
V_20 -> V_30 [ 3 ] |= V_40 ;
break;
case 48000 :
V_20 -> V_30 [ 3 ] |= V_41 ;
break;
case 88200 :
V_20 -> V_30 [ 3 ] |= V_42 ;
break;
case 96000 :
V_20 -> V_30 [ 3 ] |= V_43 ;
break;
case 176400 :
V_20 -> V_30 [ 3 ] |= V_44 ;
break;
case 192000 :
V_20 -> V_30 [ 3 ] |= V_45 ;
break;
default:
F_4 ( V_4 -> V_10 , L_4 ) ;
return - V_28 ;
}
V_20 -> V_30 [ 3 ] |= V_46 ;
switch ( F_9 ( V_18 ) ) {
case V_25 :
V_20 -> V_30 [ 4 ] |= V_47 ;
V_20 -> V_30 [ 4 ] &= ~ V_48 ;
break;
case V_27 :
V_20 -> V_30 [ 4 ] |= V_49 ;
V_20 -> V_30 [ 4 ] |= V_48 ;
break;
default:
F_4 ( V_4 -> V_10 , L_3 ) ;
return - V_28 ;
}
V_22 -> V_50 = ( F_11 ( V_18 ) - 1 )
& V_51 ;
V_22 -> V_50 |= V_52 ;
V_22 -> V_53 = V_54 ;
V_22 -> V_53 |= V_55 ;
V_22 -> V_56 = 0 ;
if ( F_11 ( V_18 ) == 2 )
V_22 -> V_57 = 0x0 ;
else
V_22 -> V_57 = 0x13 ;
V_22 -> V_58 = V_59 ;
V_22 -> V_58 |= ( 0 & V_60 ) ;
V_6 -> V_61 . V_20 = V_20 ;
V_6 -> V_61 . V_22 = V_22 ;
V_7 = V_6 -> V_11 -> V_12 -> V_62 ( V_6 -> V_11 ,
& V_6 -> V_61 ) ;
return V_7 ;
}
static int F_12 ( struct V_1 * V_2 , int V_63 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_7 = 0 ;
switch ( V_63 ) {
case V_64 :
case V_65 :
case V_66 :
V_7 = V_6 -> V_11 -> V_12 -> V_67 ( V_6 -> V_11 ) ;
break;
case V_68 :
case V_69 :
case V_70 :
V_6 -> V_11 -> V_12 -> V_71 ( V_6 -> V_11 ) ;
break;
default:
V_7 = - V_28 ;
}
return V_7 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
V_6 -> V_11 -> V_12 -> V_72 ( V_6 -> V_11 ) ;
}
static T_1 int F_14 ( struct V_73 * V_74 )
{
int V_75 ;
struct V_76 * V_77 ;
struct V_5 * V_78 ;
bool V_79 = false ;
V_78 = F_15 ( & V_74 -> V_10 , sizeof( * V_78 ) , V_80 ) ;
if ( V_78 == NULL ) {
F_4 ( & V_74 -> V_10 , L_5 ) ;
return - V_81 ;
}
V_77 = F_16 ( V_74 , V_82 , 0 ) ;
if ( ! V_77 ) {
F_4 ( & V_74 -> V_10 , L_6 ) ;
return - V_14 ;
}
V_78 -> V_15 . V_83 = V_77 -> V_84
+ V_85 ;
V_77 = F_16 ( V_74 , V_86 , 0 ) ;
if ( ! V_77 ) {
F_4 ( & V_74 -> V_10 , L_7 ) ;
return - V_14 ;
}
V_78 -> V_15 . V_87 = V_77 -> V_84 ;
V_78 -> V_15 . V_88 = L_8 ;
F_17 (hdmi_data->dssdev) {
F_18 ( V_78 -> V_11 ) ;
if ( ! V_78 -> V_11 -> V_12 ) {
F_19 ( V_78 -> V_11 ) ;
continue;
}
if ( V_78 -> V_11 -> type == V_89 ) {
V_79 = true ;
break;
}
}
if ( ! V_79 ) {
F_4 ( & V_74 -> V_10 , L_9 ) ;
return - V_14 ;
}
F_20 ( & V_74 -> V_10 , V_78 ) ;
V_75 = F_21 ( & V_74 -> V_10 , & V_90 ) ;
return V_75 ;
}
static int T_2 F_22 ( struct V_73 * V_74 )
{
struct V_5 * V_78 = F_23 ( & V_74 -> V_10 ) ;
F_24 ( & V_74 -> V_10 ) ;
if ( V_78 == NULL ) {
F_4 ( & V_74 -> V_10 , L_10 ) ;
return - V_14 ;
}
F_19 ( V_78 -> V_11 ) ;
return 0 ;
}
