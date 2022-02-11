static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 ;
switch ( V_4 ) {
case V_10 :
V_9 = F_4 ( V_2 , 0 , V_11 ) ;
if ( V_9 < 0 )
break;
switch ( V_8 -> V_12 ) {
case V_13 :
V_9 = F_5 ( V_9 * 293 , 6140 ) ;
break;
case V_14 :
V_9 = F_5 ( V_9 * 20 , 625 ) ;
break;
case V_15 :
V_9 = F_5 ( V_9 * 2832 , 45400 ) ;
break;
case V_16 :
V_9 = F_5 ( V_9 * 70 , 453 ) ;
break;
case V_17 :
case V_18 :
V_9 = F_5 ( V_9 * 725 , 2180 ) ;
break;
}
break;
case V_19 :
V_9 = F_4 ( V_2 , 0 , V_20 ) ;
break;
case V_21 :
V_9 = F_4 ( V_2 , 0 , V_22 ) ;
break;
case V_23 :
V_9 = F_4 ( V_2 , 0 ,
V_24 ) ;
break;
case V_25 :
V_9 = F_4 ( V_2 , 0 ,
V_26 ) ;
break;
case V_27 :
V_9 = F_4 ( V_2 , 0 , V_28 ) ;
break;
case V_29 :
V_9 = F_4 ( V_2 , 0 , V_30 ) ;
break;
case V_31 :
V_9 = F_4 ( V_2 , 0 , V_32 ) ;
break;
case V_33 :
V_9 = F_4 ( V_2 , 0 , V_34 ) ;
break;
case V_35 :
V_9 = F_4 ( V_2 , 0 , V_36 ) ;
break;
case V_37 :
V_9 = 0 ;
break;
default:
V_9 = - V_38 ;
break;
}
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_9 ;
switch ( V_4 ) {
case V_39 :
V_9 = F_4 ( V_2 , 0 , V_40 ) ;
break;
case V_41 :
V_9 = F_4 ( V_2 , 0 , V_42 ) ;
break;
default:
V_9 = F_1 ( V_2 , V_3 , V_4 ) ;
break;
}
return V_9 ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_9 ;
switch ( V_4 ) {
case V_43 :
V_9 = F_4 ( V_2 , 0 ,
V_44 ) ;
if ( V_9 < 0 )
break;
V_9 = F_5 ( V_9 * 293 , 6140 ) ;
break;
case V_45 :
V_9 = F_4 ( V_2 , 0 ,
V_46 ) ;
if ( V_9 < 0 )
break;
V_9 = F_5 ( V_9 * 293 , 6140 ) ;
break;
default:
V_9 = F_1 ( V_2 , V_3 , V_4 ) ;
break;
}
return V_9 ;
}
static int F_8 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_9 , V_47 ;
switch ( V_4 ) {
case V_48 :
V_9 = F_9 ( V_2 , 0 ,
V_49 ) ;
if ( V_9 < 0 )
break;
V_47 = 0 ;
if ( V_9 & V_50 )
V_47 |= V_51 ;
if ( V_9 & V_52 )
V_47 |= V_53 ;
V_9 = V_47 ;
break;
default:
V_9 = - V_38 ;
break;
}
return V_9 ;
}
static int F_10 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 V_54 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 ;
switch ( V_4 ) {
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
V_54 = ( ( V_65 ) V_54 < 0 ) ? 0 : F_11 ( V_54 , 0 , V_8 -> V_66 ) ;
V_9 = F_12 ( V_2 , 0 , V_4 , V_54 ) ;
F_13 ( V_2 ) ;
break;
case V_23 :
V_54 = ( ( V_65 ) V_54 < 0 ) ? 0 : F_11 ( V_54 , 0 , V_8 -> V_66 ) ;
V_9 = F_12 ( V_2 , 0 ,
V_24 ,
V_54 ) ;
F_13 ( V_2 ) ;
break;
case V_25 :
V_54 = ( ( V_65 ) V_54 < 0 ) ? 0 : F_11 ( V_54 , 0 , V_8 -> V_66 ) ;
V_9 = F_12 ( V_2 , 0 ,
V_26 ,
V_54 ) ;
F_13 ( V_2 ) ;
break;
case V_43 :
V_54 = F_5 ( ( int ) V_54 * 6140 , 293 ) ;
V_54 = ( ( V_65 ) V_54 < 0 ) ? 0 : F_11 ( V_54 , 0 , V_8 -> V_66 ) ;
V_9 = F_12 ( V_2 , 0 ,
V_44 , V_54 ) ;
F_13 ( V_2 ) ;
break;
case V_45 :
V_54 = F_5 ( ( int ) V_54 * 6140 , 293 ) ;
V_54 = ( ( V_65 ) V_54 < 0 ) ? 0 : F_11 ( V_54 , 0 , V_8 -> V_66 ) ;
V_9 = F_12 ( V_2 , 0 ,
V_46 , V_54 ) ;
F_13 ( V_2 ) ;
break;
case V_37 :
V_9 = F_14 ( V_2 , 0 , V_67 ) ;
break;
default:
V_9 = - V_38 ;
break;
}
return V_9 ;
}
static int F_15 ( struct V_1 * V_2 ,
const struct V_68 * V_12 )
{
int V_69 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_70 * V_71 ;
if ( ! F_16 ( V_2 -> V_72 ,
V_73 ) )
return - V_74 ;
V_8 = F_17 ( & V_2 -> V_75 , sizeof( struct V_7 ) ,
V_76 ) ;
if ( ! V_8 )
return - V_77 ;
V_69 = F_18 ( V_2 , V_78 ) ;
if ( V_69 < 0 )
return V_69 ;
V_8 -> V_12 = V_12 -> V_79 ;
V_6 = & V_8 -> V_6 ;
V_6 -> V_80 = 1 ;
V_6 -> V_81 [ V_82 ] = V_83 ;
V_6 -> V_81 [ V_84 ] = V_83 ;
V_6 -> V_81 [ V_85 ] = V_83 ;
V_6 -> V_81 [ V_86 ] = V_83 ;
V_6 -> V_81 [ V_87 ] = V_83 ;
V_6 -> V_88 [ 0 ] = V_89 | V_90
| V_91 | V_92 | V_93
| V_94 | V_95 ;
if ( V_8 -> V_12 == V_13 ) {
V_6 -> V_88 [ 0 ] |= V_96 ;
V_6 -> V_97 = F_7 ;
V_6 -> V_98 = F_8 ;
V_8 -> V_66 = 0x0fff ;
} else if ( V_8 -> V_12 == V_14 ) {
V_6 -> V_88 [ 0 ] |= V_99 | V_100
| V_101 ;
V_6 -> V_97 = F_6 ;
V_8 -> V_66 = 0xffff ;
} else {
V_6 -> V_88 [ 0 ] |= V_99 | V_100 ;
V_6 -> V_97 = F_1 ;
V_8 -> V_66 = 0x0fff ;
}
V_6 -> V_102 = F_10 ;
V_71 = & V_103 [ V_8 -> V_12 ] [ 0 ] ;
V_6 -> V_104 [ V_86 ] = V_71 [ V_86 ] . V_104 ;
V_6 -> V_105 [ V_86 ] = V_71 [ V_86 ] . V_105 ;
V_6 -> V_106 [ V_86 ] = V_71 [ V_86 ] . V_106 ;
V_6 -> V_104 [ V_82 ] = V_71 [ V_82 ] . V_104 ;
V_6 -> V_105 [ V_82 ] = V_71 [ V_82 ] . V_105 ;
V_6 -> V_106 [ V_82 ] = V_71 [ V_82 ] . V_106 ;
V_6 -> V_104 [ V_84 ] = V_71 [ V_84 ] . V_104 ;
V_6 -> V_105 [ V_84 ] = V_71 [ V_84 ] . V_105 ;
V_6 -> V_106 [ V_84 ] = V_71 [ V_84 ] . V_106 ;
V_6 -> V_106 [ V_85 ] = V_71 [ V_85 ] . V_106 ;
V_6 -> V_106 [ V_87 ] = V_71 [ V_87 ] . V_106 ;
if ( V_69 & V_107 ) {
V_6 -> V_104 [ V_85 ] = V_71 [ V_108 ] . V_104 ;
V_6 -> V_105 [ V_85 ] = V_71 [ V_108 ] . V_105 ;
V_6 -> V_104 [ V_87 ] = V_71 [ V_109 ] . V_104 ;
V_6 -> V_105 [ V_87 ] = V_71 [ V_109 ] . V_105 ;
} else {
V_6 -> V_104 [ V_85 ] = V_71 [ V_85 ] . V_104 ;
V_6 -> V_105 [ V_85 ] = V_71 [ V_85 ] . V_105 ;
V_6 -> V_104 [ V_87 ] = V_71 [ V_87 ] . V_104 ;
V_6 -> V_105 [ V_87 ] = V_71 [ V_87 ] . V_105 ;
}
return F_19 ( V_2 , V_12 , V_6 ) ;
}
