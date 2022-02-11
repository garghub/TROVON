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
int V_7 = 0 ;
switch ( F_8 ( V_18 ) ) {
case V_23 :
V_6 -> V_15 . V_24 = 16 ;
break;
case V_25 :
V_6 -> V_15 . V_24 = 32 ;
break;
default:
F_4 ( V_4 -> V_10 , L_3 ) ;
return - V_26 ;
}
memset ( V_20 -> V_27 , 0 , sizeof( V_20 -> V_27 ) ) ;
V_20 -> V_27 [ 0 ] &= ~ V_28 ;
V_20 -> V_27 [ 0 ] &= ~ V_29 ;
V_20 -> V_27 [ 0 ] |= V_30 ;
V_20 -> V_27 [ 0 ] |= V_31 ;
V_20 -> V_27 [ 0 ] |= V_32 ;
V_20 -> V_27 [ 1 ] = V_33 ;
V_20 -> V_27 [ 2 ] |= V_34 ;
V_20 -> V_27 [ 2 ] |= V_35 ;
switch ( F_9 ( V_18 ) ) {
case 32000 :
V_20 -> V_27 [ 3 ] |= V_36 ;
break;
case 44100 :
V_20 -> V_27 [ 3 ] |= V_37 ;
break;
case 48000 :
V_20 -> V_27 [ 3 ] |= V_38 ;
break;
case 88200 :
V_20 -> V_27 [ 3 ] |= V_39 ;
break;
case 96000 :
V_20 -> V_27 [ 3 ] |= V_40 ;
break;
case 176400 :
V_20 -> V_27 [ 3 ] |= V_41 ;
break;
case 192000 :
V_20 -> V_27 [ 3 ] |= V_42 ;
break;
default:
F_4 ( V_4 -> V_10 , L_4 ) ;
return - V_26 ;
}
V_20 -> V_27 [ 3 ] |= V_43 ;
switch ( F_8 ( V_18 ) ) {
case V_23 :
V_20 -> V_27 [ 4 ] |= V_44 ;
V_20 -> V_27 [ 4 ] &= ~ V_45 ;
break;
case V_25 :
V_20 -> V_27 [ 4 ] |= V_46 ;
V_20 -> V_27 [ 4 ] |= V_45 ;
break;
default:
F_4 ( V_4 -> V_10 , L_3 ) ;
return - V_26 ;
}
V_22 -> V_47 = ( F_10 ( V_18 ) - 1 )
& V_48 ;
V_22 -> V_47 |= V_49 ;
V_22 -> V_50 = V_51 ;
V_22 -> V_50 |= V_52 ;
V_22 -> V_53 = 0 ;
if ( F_10 ( V_18 ) == 2 )
V_22 -> V_54 = 0x0 ;
else
V_22 -> V_54 = 0x13 ;
V_22 -> V_55 = V_56 ;
V_22 -> V_55 |= ( 0 & V_57 ) ;
V_6 -> V_58 . V_20 = V_20 ;
V_6 -> V_58 . V_22 = V_22 ;
V_7 = V_6 -> V_11 -> V_12 -> V_59 ( V_6 -> V_11 ,
& V_6 -> V_58 ) ;
return V_7 ;
}
static int F_11 ( struct V_1 * V_2 , int V_60 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_7 = 0 ;
switch ( V_60 ) {
case V_61 :
case V_62 :
case V_63 :
V_7 = V_6 -> V_11 -> V_12 -> V_64 ( V_6 -> V_11 ) ;
break;
case V_65 :
case V_66 :
case V_67 :
V_6 -> V_11 -> V_12 -> V_68 ( V_6 -> V_11 ) ;
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
V_6 -> V_11 -> V_12 -> V_69 ( V_6 -> V_11 ) ;
}
static int F_13 ( struct V_70 * V_71 )
{
int V_72 ;
struct V_73 * V_74 ;
struct V_5 * V_75 ;
bool V_76 = false ;
V_75 = F_14 ( & V_71 -> V_10 , sizeof( * V_75 ) , V_77 ) ;
if ( V_75 == NULL ) {
F_4 ( & V_71 -> V_10 , L_5 ) ;
return - V_78 ;
}
V_74 = F_15 ( V_71 , V_79 , 0 ) ;
if ( ! V_74 ) {
F_4 ( & V_71 -> V_10 , L_6 ) ;
return - V_14 ;
}
V_75 -> V_15 . V_80 = V_74 -> V_81 + V_82 ;
V_74 = F_15 ( V_71 , V_83 , 0 ) ;
if ( ! V_74 ) {
F_4 ( & V_71 -> V_10 , L_7 ) ;
return - V_14 ;
}
V_75 -> V_84 = V_74 -> V_81 ;
V_75 -> V_15 . V_85 = & V_75 -> V_84 ;
V_75 -> V_15 . V_86 = V_87 ;
F_16 (hdmi_data->dssdev) {
F_17 ( V_75 -> V_11 ) ;
if ( ! V_75 -> V_11 -> V_12 ) {
F_18 ( V_75 -> V_11 ) ;
continue;
}
if ( V_75 -> V_11 -> type == V_88 ) {
V_76 = true ;
break;
}
}
if ( ! V_76 ) {
F_4 ( & V_71 -> V_10 , L_8 ) ;
return - V_14 ;
}
F_19 ( & V_71 -> V_10 , V_75 ) ;
V_72 = F_20 ( & V_71 -> V_10 , & V_89 ,
& V_90 , 1 ) ;
if ( V_72 )
return V_72 ;
return F_21 ( & V_71 -> V_10 ) ;
}
static int F_22 ( struct V_70 * V_71 )
{
struct V_5 * V_75 = F_23 ( & V_71 -> V_10 ) ;
F_24 ( & V_71 -> V_10 ) ;
if ( V_75 == NULL ) {
F_4 ( & V_71 -> V_10 , L_9 ) ;
return - V_14 ;
}
F_18 ( V_75 -> V_11 ) ;
return 0 ;
}
