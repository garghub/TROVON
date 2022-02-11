static
struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
return F_2 ( V_5 -> V_7 ) ;
}
static void F_3 ( struct V_8 * V_9 )
{
struct V_1 * V_10 = F_4 ( V_9 ) ;
F_5 ( & V_10 -> V_11 ) ;
if ( V_10 -> V_12 && V_10 -> V_12 -> V_13 &&
F_6 ( V_10 -> V_12 ) ) {
F_7 ( V_9 , L_1 ) ;
F_8 ( V_10 -> V_12 ) ;
F_9 ( V_10 -> V_12 , V_14 ) ;
F_10 ( V_10 -> V_12 ) ;
}
F_11 ( & V_10 -> V_11 ) ;
}
static int F_12 ( struct V_2 * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_10 = F_1 ( V_15 ) ;
int V_18 ;
V_18 = F_13 ( V_15 -> V_13 , 0 ,
V_19 , 128 ) ;
if ( V_18 < 0 ) {
F_7 ( V_17 -> V_9 , L_2 ) ;
return V_18 ;
}
F_14 ( V_17 , V_15 , & V_10 -> V_20 ) ;
F_5 ( & V_10 -> V_11 ) ;
V_10 -> V_12 = V_15 ;
F_11 ( & V_10 -> V_11 ) ;
V_18 = V_10 -> V_21 -> V_22 ( V_10 -> V_23 , F_3 ) ;
if ( V_18 ) {
F_5 ( & V_10 -> V_11 ) ;
V_10 -> V_12 = NULL ;
F_11 ( & V_10 -> V_11 ) ;
}
return V_18 ;
}
static int F_15 ( struct V_2 * V_15 ,
struct V_24 * V_25 ,
struct V_16 * V_17 )
{
struct V_1 * V_10 = F_1 ( V_15 ) ;
struct V_26 * V_27 = & V_10 -> V_27 ;
struct V_28 * V_29 = & V_10 -> V_29 ;
F_16 ( V_10 -> V_12 != V_15 ) ;
switch ( F_17 ( V_25 ) ) {
case V_30 :
V_10 -> V_20 . V_31 = 16 ;
break;
case V_32 :
V_10 -> V_20 . V_31 = 32 ;
break;
default:
F_7 ( V_17 -> V_9 , L_3 ) ;
return - V_33 ;
}
V_10 -> V_34 . V_27 = V_27 ;
V_10 -> V_34 . V_29 = V_29 ;
memset ( V_27 -> V_35 , 0 , sizeof( V_27 -> V_35 ) ) ;
V_27 -> V_35 [ 0 ] &= ~ V_36 ;
V_27 -> V_35 [ 0 ] &= ~ V_37 ;
V_27 -> V_35 [ 0 ] |= V_38 ;
V_27 -> V_35 [ 0 ] |= V_39 ;
V_27 -> V_35 [ 0 ] |= V_40 ;
V_27 -> V_35 [ 1 ] = V_41 ;
V_27 -> V_35 [ 2 ] |= V_42 ;
V_27 -> V_35 [ 2 ] |= V_43 ;
switch ( F_18 ( V_25 ) ) {
case 32000 :
V_27 -> V_35 [ 3 ] |= V_44 ;
break;
case 44100 :
V_27 -> V_35 [ 3 ] |= V_45 ;
break;
case 48000 :
V_27 -> V_35 [ 3 ] |= V_46 ;
break;
case 88200 :
V_27 -> V_35 [ 3 ] |= V_47 ;
break;
case 96000 :
V_27 -> V_35 [ 3 ] |= V_48 ;
break;
case 176400 :
V_27 -> V_35 [ 3 ] |= V_49 ;
break;
case 192000 :
V_27 -> V_35 [ 3 ] |= V_50 ;
break;
default:
F_7 ( V_17 -> V_9 , L_4 ) ;
return - V_33 ;
}
V_27 -> V_35 [ 3 ] |= V_51 ;
switch ( F_17 ( V_25 ) ) {
case V_30 :
V_27 -> V_35 [ 4 ] |= V_52 ;
V_27 -> V_35 [ 4 ] &= ~ V_53 ;
break;
case V_32 :
V_27 -> V_35 [ 4 ] |= V_54 ;
V_27 -> V_35 [ 4 ] |= V_53 ;
break;
default:
F_7 ( V_17 -> V_9 , L_3 ) ;
return - V_33 ;
}
V_29 -> V_55 = ( F_19 ( V_25 ) - 1 )
& V_56 ;
V_29 -> V_55 |= V_57 ;
V_29 -> V_58 = V_59 ;
V_29 -> V_58 |= V_60 ;
V_29 -> V_61 = 0 ;
if ( F_19 ( V_25 ) == 2 )
V_29 -> V_62 = 0x0 ;
else
V_29 -> V_62 = 0x13 ;
V_29 -> V_63 = V_64 ;
V_29 -> V_63 |= ( 0 & V_65 ) ;
return V_10 -> V_21 -> V_66 ( V_10 -> V_23 , & V_10 -> V_34 ) ;
}
static int F_20 ( struct V_2 * V_15 , int V_67 ,
struct V_16 * V_17 )
{
struct V_1 * V_10 = F_1 ( V_15 ) ;
int V_68 = 0 ;
F_16 ( V_10 -> V_12 != V_15 ) ;
switch ( V_67 ) {
case V_69 :
case V_70 :
case V_71 :
V_68 = V_10 -> V_21 -> V_72 ( V_10 -> V_23 ) ;
break;
case V_73 :
case V_74 :
case V_75 :
V_10 -> V_21 -> V_76 ( V_10 -> V_23 ) ;
break;
default:
V_68 = - V_33 ;
}
return V_68 ;
}
static void F_21 ( struct V_2 * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_10 = F_1 ( V_15 ) ;
F_16 ( V_10 -> V_12 != V_15 ) ;
V_10 -> V_21 -> V_77 ( V_10 -> V_23 ) ;
F_5 ( & V_10 -> V_11 ) ;
V_10 -> V_12 = NULL ;
F_11 ( & V_10 -> V_11 ) ;
}
static int F_22 ( struct V_78 * V_79 )
{
struct V_80 * V_81 = V_79 -> V_9 . V_82 ;
struct V_8 * V_9 = & V_79 -> V_9 ;
struct V_1 * V_10 ;
struct V_83 * V_84 ;
struct V_85 * V_7 ;
int V_18 ;
if ( ! V_81 ) {
F_7 ( V_9 , L_5 ) ;
return - V_33 ;
}
V_10 = F_23 ( V_9 , sizeof( * V_10 ) , V_86 ) ;
if ( ! V_10 )
return - V_87 ;
V_10 -> V_23 = V_81 -> V_9 ;
V_10 -> V_21 = V_81 -> V_21 ;
V_10 -> V_20 . V_88 = V_81 -> V_89 ;
V_10 -> V_20 . V_90 = L_6 ;
V_10 -> V_20 . V_91 = V_92 ;
F_24 ( & V_10 -> V_11 ) ;
switch ( V_81 -> V_93 ) {
case V_94 :
case V_95 :
case V_96 :
V_84 = & V_97 ;
break;
case V_98 :
V_84 = & V_99 ;
break;
default:
return - V_33 ;
}
V_18 = F_25 ( V_10 -> V_23 , & V_100 ,
V_84 , 1 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_26 ( V_10 -> V_23 ) ;
if ( V_18 )
return V_18 ;
V_7 = F_23 ( V_9 , sizeof( * V_7 ) , V_86 ) ;
V_7 -> V_101 = F_27 ( V_9 , V_86 ,
L_7 , F_28 ( V_10 -> V_23 ) ) ;
V_7 -> V_102 = V_103 ;
V_7 -> V_104 =
F_23 ( V_9 , sizeof( * ( V_7 -> V_104 ) ) , V_86 ) ;
V_7 -> V_104 -> V_101 = V_7 -> V_101 ;
V_7 -> V_104 -> V_105 = V_7 -> V_101 ;
V_7 -> V_104 -> V_106 = F_28 ( V_10 -> V_23 ) ;
V_7 -> V_104 -> V_107 = F_28 ( V_10 -> V_23 ) ;
V_7 -> V_104 -> V_108 = L_8 ;
V_7 -> V_104 -> V_109 = L_9 ;
V_7 -> V_110 = 1 ;
V_7 -> V_9 = V_9 ;
V_18 = F_29 ( V_7 ) ;
if ( V_18 ) {
F_7 ( V_9 , L_10 , V_18 ) ;
F_30 ( V_10 -> V_23 ) ;
return V_18 ;
}
V_10 -> V_7 = V_7 ;
F_31 ( V_7 , V_10 ) ;
F_32 ( V_9 , V_10 ) ;
return 0 ;
}
static int F_33 ( struct V_78 * V_79 )
{
struct V_1 * V_10 = F_34 ( V_79 ) ;
F_35 ( V_10 -> V_7 ) ;
F_30 ( V_10 -> V_23 ) ;
return 0 ;
}
