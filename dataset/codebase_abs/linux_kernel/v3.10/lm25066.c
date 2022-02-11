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
V_9 = F_5 ( V_9 * 2832 , 45400 ) ;
break;
case V_15 :
V_9 = F_5 ( V_9 * 70 , 453 ) ;
break;
case V_16 :
V_9 = F_5 ( V_9 * 725 , 2180 ) ;
break;
}
break;
case V_17 :
V_9 = F_4 ( V_2 , 0 , V_18 ) ;
break;
case V_19 :
V_9 = F_4 ( V_2 , 0 , V_20 ) ;
break;
case V_21 :
V_9 = F_4 ( V_2 , 0 ,
V_22 ) ;
break;
case V_23 :
V_9 = F_4 ( V_2 , 0 ,
V_24 ) ;
break;
case V_25 :
V_9 = F_4 ( V_2 , 0 , V_26 ) ;
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
V_9 = 0 ;
break;
default:
V_9 = - V_36 ;
break;
}
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_9 ;
switch ( V_4 ) {
case V_37 :
V_9 = F_4 ( V_2 , 0 ,
V_38 ) ;
if ( V_9 < 0 )
break;
V_9 = F_5 ( V_9 * 293 , 6140 ) ;
break;
case V_39 :
V_9 = F_4 ( V_2 , 0 ,
V_40 ) ;
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
static int F_7 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_9 , V_41 ;
switch ( V_4 ) {
case V_42 :
V_9 = F_8 ( V_2 , 0 ,
V_43 ) ;
if ( V_9 < 0 )
break;
V_41 = 0 ;
if ( V_9 & V_44 )
V_41 |= V_45 ;
if ( V_9 & V_46 )
V_41 |= V_47 ;
V_9 = V_41 ;
break;
default:
V_9 = - V_36 ;
break;
}
return V_9 ;
}
static int F_9 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 V_48 )
{
int V_9 ;
switch ( V_4 ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
V_48 = ( ( V_54 ) V_48 < 0 ) ? 0 : F_10 ( V_48 , 0 , 0x0fff ) ;
V_9 = F_11 ( V_2 , 0 , V_4 , V_48 ) ;
F_12 ( V_2 ) ;
break;
case V_21 :
V_48 = ( ( V_54 ) V_48 < 0 ) ? 0 : F_10 ( V_48 , 0 , 0x0fff ) ;
V_9 = F_11 ( V_2 , 0 ,
V_22 ,
V_48 ) ;
F_12 ( V_2 ) ;
break;
case V_23 :
V_48 = ( ( V_54 ) V_48 < 0 ) ? 0 : F_10 ( V_48 , 0 , 0x0fff ) ;
V_9 = F_11 ( V_2 , 0 ,
V_24 ,
V_48 ) ;
F_12 ( V_2 ) ;
break;
case V_37 :
V_48 = F_5 ( ( int ) V_48 * 6140 , 293 ) ;
V_48 = ( ( V_54 ) V_48 < 0 ) ? 0 : F_10 ( V_48 , 0 , 0x0fff ) ;
V_9 = F_11 ( V_2 , 0 ,
V_38 , V_48 ) ;
F_12 ( V_2 ) ;
break;
case V_39 :
V_48 = F_5 ( ( int ) V_48 * 6140 , 293 ) ;
V_48 = ( ( V_54 ) V_48 < 0 ) ? 0 : F_10 ( V_48 , 0 , 0x0fff ) ;
V_9 = F_11 ( V_2 , 0 ,
V_40 , V_48 ) ;
F_12 ( V_2 ) ;
break;
case V_35 :
V_9 = F_13 ( V_2 , 0 , V_55 ) ;
break;
default:
V_9 = - V_36 ;
break;
}
return V_9 ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_56 * V_12 )
{
int V_57 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_58 * V_59 ;
if ( ! F_15 ( V_2 -> V_60 ,
V_61 ) )
return - V_62 ;
V_8 = F_16 ( & V_2 -> V_63 , sizeof( struct V_7 ) ,
V_64 ) ;
if ( ! V_8 )
return - V_65 ;
V_57 = F_17 ( V_2 , V_66 ) ;
if ( V_57 < 0 )
return V_57 ;
V_8 -> V_12 = V_12 -> V_67 ;
V_6 = & V_8 -> V_6 ;
V_6 -> V_68 = 1 ;
V_6 -> V_69 [ V_70 ] = V_71 ;
V_6 -> V_69 [ V_72 ] = V_71 ;
V_6 -> V_69 [ V_73 ] = V_71 ;
V_6 -> V_69 [ V_74 ] = V_71 ;
V_6 -> V_69 [ V_75 ] = V_71 ;
V_6 -> V_76 [ 0 ] = V_77 | V_78
| V_79 | V_80 | V_81
| V_82 | V_83 ;
if ( V_8 -> V_12 == V_13 ) {
V_6 -> V_76 [ 0 ] |= V_84 ;
V_6 -> V_85 = F_6 ;
V_6 -> V_86 = F_7 ;
} else {
V_6 -> V_76 [ 0 ] |= V_87 | V_88 ;
V_6 -> V_85 = F_1 ;
}
V_6 -> V_89 = F_9 ;
V_59 = & V_90 [ V_8 -> V_12 ] [ 0 ] ;
V_6 -> V_91 [ V_74 ] = V_59 [ V_74 ] . V_91 ;
V_6 -> V_92 [ V_74 ] = V_59 [ V_74 ] . V_92 ;
V_6 -> V_93 [ V_74 ] = V_59 [ V_74 ] . V_93 ;
V_6 -> V_91 [ V_70 ] = V_59 [ V_70 ] . V_91 ;
V_6 -> V_92 [ V_70 ] = V_59 [ V_70 ] . V_92 ;
V_6 -> V_93 [ V_70 ] = V_59 [ V_70 ] . V_93 ;
V_6 -> V_91 [ V_72 ] = V_59 [ V_72 ] . V_91 ;
V_6 -> V_92 [ V_72 ] = V_59 [ V_72 ] . V_92 ;
V_6 -> V_93 [ V_72 ] = V_59 [ V_72 ] . V_93 ;
V_6 -> V_92 [ V_73 ] = V_59 [ V_73 ] . V_92 ;
V_6 -> V_93 [ V_73 ] = V_59 [ V_73 ] . V_93 ;
V_6 -> V_92 [ V_75 ] = V_59 [ V_75 ] . V_92 ;
V_6 -> V_93 [ V_75 ] = V_59 [ V_75 ] . V_93 ;
if ( V_57 & V_94 ) {
V_6 -> V_91 [ V_73 ] = V_59 [ V_95 ] . V_91 ;
V_6 -> V_91 [ V_75 ] = V_59 [ V_96 ] . V_91 ;
} else {
V_6 -> V_91 [ V_73 ] = V_59 [ V_73 ] . V_91 ;
V_6 -> V_91 [ V_75 ] = V_59 [ V_75 ] . V_91 ;
}
return F_18 ( V_2 , V_12 , V_6 ) ;
}
