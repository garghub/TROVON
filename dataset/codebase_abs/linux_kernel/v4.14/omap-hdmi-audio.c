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
F_7 ( V_17 -> V_9 , L_2 ,
V_18 ) ;
return V_18 ;
}
V_18 = F_13 ( V_15 -> V_13 , 0 ,
V_20 , 128 ) ;
if ( V_18 < 0 ) {
F_7 ( V_17 -> V_9 , L_3 ,
V_18 ) ;
return V_18 ;
}
F_14 ( V_17 , V_15 , & V_10 -> V_21 ) ;
F_5 ( & V_10 -> V_11 ) ;
V_10 -> V_12 = V_15 ;
F_11 ( & V_10 -> V_11 ) ;
V_18 = V_10 -> V_22 -> V_23 ( V_10 -> V_24 , F_3 ) ;
if ( V_18 ) {
F_5 ( & V_10 -> V_11 ) ;
V_10 -> V_12 = NULL ;
F_11 ( & V_10 -> V_11 ) ;
}
return V_18 ;
}
static int F_15 ( struct V_2 * V_15 ,
struct V_25 * V_26 ,
struct V_16 * V_17 )
{
struct V_1 * V_10 = F_1 ( V_15 ) ;
struct V_27 * V_28 = & V_10 -> V_28 ;
struct V_29 * V_30 = & V_10 -> V_30 ;
F_16 ( V_10 -> V_12 != V_15 ) ;
switch ( F_17 ( V_26 ) ) {
case V_31 :
V_10 -> V_21 . V_32 = 16 ;
break;
case V_33 :
V_10 -> V_21 . V_32 = 32 ;
break;
default:
F_7 ( V_17 -> V_9 , L_4 ) ;
return - V_34 ;
}
V_10 -> V_35 . V_28 = V_28 ;
V_10 -> V_35 . V_30 = V_30 ;
memset ( V_28 -> V_36 , 0 , sizeof( V_28 -> V_36 ) ) ;
V_28 -> V_36 [ 0 ] &= ~ V_37 ;
V_28 -> V_36 [ 0 ] &= ~ V_38 ;
V_28 -> V_36 [ 0 ] |= V_39 ;
V_28 -> V_36 [ 0 ] |= V_40 ;
V_28 -> V_36 [ 1 ] = V_41 ;
V_28 -> V_36 [ 2 ] |= V_42 ;
V_28 -> V_36 [ 2 ] |= V_43 ;
switch ( F_18 ( V_26 ) ) {
case 32000 :
V_28 -> V_36 [ 3 ] |= V_44 ;
break;
case 44100 :
V_28 -> V_36 [ 3 ] |= V_45 ;
break;
case 48000 :
V_28 -> V_36 [ 3 ] |= V_46 ;
break;
case 88200 :
V_28 -> V_36 [ 3 ] |= V_47 ;
break;
case 96000 :
V_28 -> V_36 [ 3 ] |= V_48 ;
break;
case 176400 :
V_28 -> V_36 [ 3 ] |= V_49 ;
break;
case 192000 :
V_28 -> V_36 [ 3 ] |= V_50 ;
break;
default:
F_7 ( V_17 -> V_9 , L_5 ) ;
return - V_34 ;
}
V_28 -> V_36 [ 3 ] |= V_51 ;
switch ( F_17 ( V_26 ) ) {
case V_31 :
V_28 -> V_36 [ 4 ] |= V_52 ;
V_28 -> V_36 [ 4 ] &= ~ V_53 ;
break;
case V_33 :
V_28 -> V_36 [ 4 ] |= V_54 ;
V_28 -> V_36 [ 4 ] |= V_53 ;
break;
default:
F_7 ( V_17 -> V_9 , L_4 ) ;
return - V_34 ;
}
V_30 -> V_55 = ( F_19 ( V_26 ) - 1 )
& V_56 ;
V_30 -> V_55 |= V_57 ;
V_30 -> V_58 = V_59 ;
V_30 -> V_58 |= V_60 ;
V_30 -> V_61 = 0 ;
if ( F_19 ( V_26 ) == 2 )
V_30 -> V_62 = 0x0 ;
else if ( F_19 ( V_26 ) == 6 )
V_30 -> V_62 = 0xb ;
else
V_30 -> V_62 = 0x13 ;
if ( V_30 -> V_62 == 0x00 )
V_30 -> V_63 = V_64 ;
else
V_30 -> V_63 = V_65 ;
V_30 -> V_63 |= ( 0 & V_66 ) ;
return V_10 -> V_22 -> V_67 ( V_10 -> V_24 , & V_10 -> V_35 ) ;
}
static int F_20 ( struct V_2 * V_15 , int V_68 ,
struct V_16 * V_17 )
{
struct V_1 * V_10 = F_1 ( V_15 ) ;
int V_69 = 0 ;
F_16 ( V_10 -> V_12 != V_15 ) ;
switch ( V_68 ) {
case V_70 :
case V_71 :
case V_72 :
V_69 = V_10 -> V_22 -> V_73 ( V_10 -> V_24 ) ;
break;
case V_74 :
case V_75 :
case V_76 :
V_10 -> V_22 -> V_77 ( V_10 -> V_24 ) ;
break;
default:
V_69 = - V_34 ;
}
return V_69 ;
}
static void F_21 ( struct V_2 * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_10 = F_1 ( V_15 ) ;
F_16 ( V_10 -> V_12 != V_15 ) ;
V_10 -> V_22 -> V_78 ( V_10 -> V_24 ) ;
F_5 ( & V_10 -> V_11 ) ;
V_10 -> V_12 = NULL ;
F_11 ( & V_10 -> V_11 ) ;
}
static int F_22 ( struct V_79 * V_80 )
{
struct V_81 * V_82 = V_80 -> V_9 . V_83 ;
struct V_8 * V_9 = & V_80 -> V_9 ;
struct V_1 * V_10 ;
struct V_84 * V_85 ;
struct V_86 * V_7 ;
int V_18 ;
if ( ! V_82 ) {
F_7 ( V_9 , L_6 ) ;
return - V_34 ;
}
V_10 = F_23 ( V_9 , sizeof( * V_10 ) , V_87 ) ;
if ( ! V_10 )
return - V_88 ;
V_10 -> V_24 = V_82 -> V_9 ;
V_10 -> V_22 = V_82 -> V_22 ;
V_10 -> V_21 . V_89 = V_82 -> V_90 ;
V_10 -> V_21 . V_91 = L_7 ;
V_10 -> V_21 . V_92 = V_93 ;
F_24 ( & V_10 -> V_11 ) ;
switch ( V_82 -> V_94 ) {
case 4 :
V_85 = & V_95 ;
break;
case 5 :
V_85 = & V_96 ;
break;
default:
return - V_34 ;
}
V_18 = F_25 ( V_10 -> V_24 , & V_97 ,
V_85 , 1 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_26 ( V_10 -> V_24 ) ;
if ( V_18 )
return V_18 ;
V_7 = F_23 ( V_9 , sizeof( * V_7 ) , V_87 ) ;
if ( ! V_7 )
return - V_88 ;
V_7 -> V_98 = F_27 ( V_9 , V_87 ,
L_8 , F_28 ( V_10 -> V_24 ) ) ;
V_7 -> V_99 = V_100 ;
V_7 -> V_101 =
F_23 ( V_9 , sizeof( * ( V_7 -> V_101 ) ) , V_87 ) ;
if ( ! V_7 -> V_101 )
return - V_88 ;
V_7 -> V_101 -> V_98 = V_7 -> V_98 ;
V_7 -> V_101 -> V_102 = V_7 -> V_98 ;
V_7 -> V_101 -> V_103 = F_28 ( V_10 -> V_24 ) ;
V_7 -> V_101 -> V_104 = F_28 ( V_10 -> V_24 ) ;
V_7 -> V_101 -> V_105 = L_9 ;
V_7 -> V_101 -> V_106 = L_10 ;
V_7 -> V_107 = 1 ;
V_7 -> V_9 = V_9 ;
V_18 = F_29 ( V_7 ) ;
if ( V_18 ) {
F_7 ( V_9 , L_11 , V_18 ) ;
F_30 ( V_10 -> V_24 ) ;
return V_18 ;
}
V_10 -> V_7 = V_7 ;
F_31 ( V_7 , V_10 ) ;
F_32 ( V_9 , V_10 ) ;
return 0 ;
}
static int F_33 ( struct V_79 * V_80 )
{
struct V_1 * V_10 = F_34 ( V_80 ) ;
F_35 ( V_10 -> V_7 ) ;
F_30 ( V_10 -> V_24 ) ;
return 0 ;
}
