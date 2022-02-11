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
V_9 = F_5 ( V_9 * 725 , 2180 ) ;
break;
}
break;
case V_18 :
V_9 = F_4 ( V_2 , 0 , V_19 ) ;
break;
case V_20 :
V_9 = F_4 ( V_2 , 0 , V_21 ) ;
break;
case V_22 :
V_9 = F_4 ( V_2 , 0 ,
V_23 ) ;
break;
case V_24 :
V_9 = F_4 ( V_2 , 0 ,
V_25 ) ;
break;
case V_26 :
V_9 = F_4 ( V_2 , 0 , V_27 ) ;
break;
case V_28 :
V_9 = F_4 ( V_2 , 0 , V_29 ) ;
break;
case V_30 :
V_9 = F_4 ( V_2 , 0 , V_31 ) ;
break;
case V_32 :
V_9 = F_4 ( V_2 , 0 , V_33 ) ;
break;
case V_34 :
V_9 = F_4 ( V_2 , 0 , V_35 ) ;
break;
case V_36 :
V_9 = 0 ;
break;
default:
V_9 = - V_37 ;
break;
}
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_9 ;
switch ( V_4 ) {
case V_38 :
V_9 = F_4 ( V_2 , 0 , V_39 ) ;
break;
case V_40 :
V_9 = F_4 ( V_2 , 0 , V_41 ) ;
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
case V_42 :
V_9 = F_4 ( V_2 , 0 ,
V_43 ) ;
if ( V_9 < 0 )
break;
V_9 = F_5 ( V_9 * 293 , 6140 ) ;
break;
case V_44 :
V_9 = F_4 ( V_2 , 0 ,
V_45 ) ;
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
int V_9 , V_46 ;
switch ( V_4 ) {
case V_47 :
V_9 = F_9 ( V_2 , 0 ,
V_48 ) ;
if ( V_9 < 0 )
break;
V_46 = 0 ;
if ( V_9 & V_49 )
V_46 |= V_50 ;
if ( V_9 & V_51 )
V_46 |= V_52 ;
V_9 = V_46 ;
break;
default:
V_9 = - V_37 ;
break;
}
return V_9 ;
}
static int F_10 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 V_53 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 ;
switch ( V_4 ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
V_53 = ( ( V_64 ) V_53 < 0 ) ? 0 : F_11 ( V_53 , 0 , V_8 -> V_65 ) ;
V_9 = F_12 ( V_2 , 0 , V_4 , V_53 ) ;
F_13 ( V_2 ) ;
break;
case V_22 :
V_53 = ( ( V_64 ) V_53 < 0 ) ? 0 : F_11 ( V_53 , 0 , V_8 -> V_65 ) ;
V_9 = F_12 ( V_2 , 0 ,
V_23 ,
V_53 ) ;
F_13 ( V_2 ) ;
break;
case V_24 :
V_53 = ( ( V_64 ) V_53 < 0 ) ? 0 : F_11 ( V_53 , 0 , V_8 -> V_65 ) ;
V_9 = F_12 ( V_2 , 0 ,
V_25 ,
V_53 ) ;
F_13 ( V_2 ) ;
break;
case V_42 :
V_53 = F_5 ( ( int ) V_53 * 6140 , 293 ) ;
V_53 = ( ( V_64 ) V_53 < 0 ) ? 0 : F_11 ( V_53 , 0 , V_8 -> V_65 ) ;
V_9 = F_12 ( V_2 , 0 ,
V_43 , V_53 ) ;
F_13 ( V_2 ) ;
break;
case V_44 :
V_53 = F_5 ( ( int ) V_53 * 6140 , 293 ) ;
V_53 = ( ( V_64 ) V_53 < 0 ) ? 0 : F_11 ( V_53 , 0 , V_8 -> V_65 ) ;
V_9 = F_12 ( V_2 , 0 ,
V_45 , V_53 ) ;
F_13 ( V_2 ) ;
break;
case V_36 :
V_9 = F_14 ( V_2 , 0 , V_66 ) ;
break;
default:
V_9 = - V_37 ;
break;
}
return V_9 ;
}
static int F_15 ( struct V_1 * V_2 ,
const struct V_67 * V_12 )
{
int V_68 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_69 * V_70 ;
if ( ! F_16 ( V_2 -> V_71 ,
V_72 ) )
return - V_73 ;
V_8 = F_17 ( & V_2 -> V_74 , sizeof( struct V_7 ) ,
V_75 ) ;
if ( ! V_8 )
return - V_76 ;
V_68 = F_18 ( V_2 , V_77 ) ;
if ( V_68 < 0 )
return V_68 ;
V_8 -> V_12 = V_12 -> V_78 ;
V_6 = & V_8 -> V_6 ;
V_6 -> V_79 = 1 ;
V_6 -> V_80 [ V_81 ] = V_82 ;
V_6 -> V_80 [ V_83 ] = V_82 ;
V_6 -> V_80 [ V_84 ] = V_82 ;
V_6 -> V_80 [ V_85 ] = V_82 ;
V_6 -> V_80 [ V_86 ] = V_82 ;
V_6 -> V_87 [ 0 ] = V_88 | V_89
| V_90 | V_91 | V_92
| V_93 | V_94 ;
if ( V_8 -> V_12 == V_13 ) {
V_6 -> V_87 [ 0 ] |= V_95 ;
V_6 -> V_96 = F_7 ;
V_6 -> V_97 = F_8 ;
V_8 -> V_65 = 0x0fff ;
} else if ( V_8 -> V_12 == V_14 ) {
V_6 -> V_87 [ 0 ] |= V_98 | V_99
| V_100 ;
V_6 -> V_96 = F_6 ;
V_8 -> V_65 = 0xffff ;
} else {
V_6 -> V_87 [ 0 ] |= V_98 | V_99 ;
V_6 -> V_96 = F_1 ;
V_8 -> V_65 = 0x0fff ;
}
V_6 -> V_101 = F_10 ;
V_70 = & V_102 [ V_8 -> V_12 ] [ 0 ] ;
V_6 -> V_103 [ V_85 ] = V_70 [ V_85 ] . V_103 ;
V_6 -> V_104 [ V_85 ] = V_70 [ V_85 ] . V_104 ;
V_6 -> V_105 [ V_85 ] = V_70 [ V_85 ] . V_105 ;
V_6 -> V_103 [ V_81 ] = V_70 [ V_81 ] . V_103 ;
V_6 -> V_104 [ V_81 ] = V_70 [ V_81 ] . V_104 ;
V_6 -> V_105 [ V_81 ] = V_70 [ V_81 ] . V_105 ;
V_6 -> V_103 [ V_83 ] = V_70 [ V_83 ] . V_103 ;
V_6 -> V_104 [ V_83 ] = V_70 [ V_83 ] . V_104 ;
V_6 -> V_105 [ V_83 ] = V_70 [ V_83 ] . V_105 ;
V_6 -> V_104 [ V_84 ] = V_70 [ V_84 ] . V_104 ;
V_6 -> V_105 [ V_84 ] = V_70 [ V_84 ] . V_105 ;
V_6 -> V_104 [ V_86 ] = V_70 [ V_86 ] . V_104 ;
V_6 -> V_105 [ V_86 ] = V_70 [ V_86 ] . V_105 ;
if ( V_68 & V_106 ) {
V_6 -> V_103 [ V_84 ] = V_70 [ V_107 ] . V_103 ;
V_6 -> V_103 [ V_86 ] = V_70 [ V_108 ] . V_103 ;
} else {
V_6 -> V_103 [ V_84 ] = V_70 [ V_84 ] . V_103 ;
V_6 -> V_103 [ V_86 ] = V_70 [ V_86 ] . V_103 ;
}
return F_19 ( V_2 , V_12 , V_6 ) ;
}
