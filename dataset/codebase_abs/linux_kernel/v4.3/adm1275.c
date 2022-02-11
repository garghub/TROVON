static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 = 0 ;
if ( V_3 )
return - V_10 ;
switch ( V_4 ) {
case V_11 :
if ( ! V_8 -> V_12 )
return - V_10 ;
V_9 = F_4 ( V_2 , 0 , V_13 ) ;
break;
case V_14 :
if ( ! V_8 -> V_15 )
return - V_10 ;
V_9 = F_4 ( V_2 , 0 , V_13 ) ;
break;
case V_16 :
if ( V_8 -> V_17 )
return - V_18 ;
V_9 = F_4 ( V_2 , 0 ,
V_19 ) ;
break;
case V_20 :
if ( V_8 -> V_17 )
return - V_18 ;
V_9 = F_4 ( V_2 , 0 ,
V_21 ) ;
break;
case V_22 :
if ( V_8 -> V_17 )
return - V_18 ;
V_9 = F_4 ( V_2 , 0 , V_23 ) ;
break;
case V_24 :
if ( ! V_8 -> V_25 )
return - V_10 ;
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
if ( ! V_8 -> V_34 )
return - V_10 ;
V_9 = F_4 ( V_2 , 0 , V_35 ) ;
break;
case V_36 :
if ( ! V_8 -> V_37 )
return - V_10 ;
V_9 = F_4 ( V_2 , 0 , V_38 ) ;
break;
case V_39 :
case V_40 :
case V_41 :
break;
case V_42 :
if ( ! V_8 -> V_37 )
return - V_10 ;
break;
default:
V_9 = - V_18 ;
break;
}
return V_9 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 V_43 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 ;
if ( V_3 )
return - V_10 ;
switch ( V_4 ) {
case V_11 :
case V_14 :
V_9 = F_6 ( V_2 , 0 , V_13 ,
V_43 ) ;
break;
case V_39 :
V_9 = F_6 ( V_2 , 0 , V_28 , 0 ) ;
if ( ! V_9 && V_8 -> V_25 )
V_9 = F_6 ( V_2 , 0 ,
V_26 , 0 ) ;
break;
case V_40 :
V_9 = F_6 ( V_2 , 0 , V_30 , 0 ) ;
break;
case V_41 :
V_9 = F_6 ( V_2 , 0 , V_32 , 0 ) ;
break;
case V_42 :
V_9 = F_6 ( V_2 , 0 , V_38 , 0 ) ;
if ( ! V_9 && V_8 -> V_34 )
V_9 = F_6 ( V_2 , 0 ,
V_35 , 0 ) ;
break;
default:
V_9 = - V_18 ;
break;
}
return V_9 ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_44 , V_9 ;
if ( V_3 > 0 )
return - V_10 ;
switch ( V_4 ) {
case V_45 :
V_9 = F_8 ( V_2 , V_3 , V_45 ) ;
if ( V_9 < 0 )
break;
if ( ! V_8 -> V_15 && ! V_8 -> V_12 )
break;
V_44 = F_8 ( V_2 , V_3 ,
V_46 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_44 & V_47 ) {
V_9 |= V_8 -> V_15 ?
V_48 : V_49 ;
}
break;
case V_50 :
if ( V_8 -> V_17 )
return - V_18 ;
V_9 = 0 ;
if ( V_8 -> V_51 ) {
V_44 = F_8 ( V_2 , 0 ,
V_52 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_44 & V_53 )
V_9 |= V_54 ;
if ( V_44 & V_55 )
V_9 |= V_56 ;
} else if ( V_8 -> V_57 ) {
V_44 = F_8 ( V_2 , V_3 ,
V_46 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_44 & V_58 )
V_9 |= V_54 ;
if ( V_44 & V_59 )
V_9 |= V_56 ;
}
break;
default:
V_9 = - V_18 ;
break;
}
return V_9 ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_60 * V_61 )
{
T_2 V_62 [ V_63 + 1 ] ;
int V_64 , V_65 ;
int V_9 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
const struct V_60 * V_66 ;
const struct V_67 * V_67 ;
int V_68 = - 1 , V_69 = - 1 , V_70 = - 1 , V_71 = - 1 ;
if ( ! F_10 ( V_2 -> V_72 ,
V_73
| V_74 ) )
return - V_75 ;
V_9 = F_11 ( V_2 , V_76 , V_62 ) ;
if ( V_9 < 0 ) {
F_12 ( & V_2 -> V_77 , L_1 ) ;
return V_9 ;
}
if ( V_9 != 3 || strncmp ( V_62 , L_2 , 3 ) ) {
F_12 ( & V_2 -> V_77 , L_3 ) ;
return - V_75 ;
}
V_9 = F_11 ( V_2 , V_78 , V_62 ) ;
if ( V_9 < 0 ) {
F_12 ( & V_2 -> V_77 , L_4 ) ;
return V_9 ;
}
for ( V_66 = V_79 ; V_66 -> V_80 [ 0 ] ; V_66 ++ ) {
if ( ! strncasecmp ( V_66 -> V_80 , V_62 , strlen ( V_66 -> V_80 ) ) )
break;
}
if ( ! V_66 -> V_80 [ 0 ] ) {
F_12 ( & V_2 -> V_77 , L_5 ) ;
return - V_75 ;
}
if ( V_61 -> V_81 != V_66 -> V_81 )
F_13 ( & V_2 -> V_77 ,
L_6 ,
V_61 -> V_80 , V_66 -> V_80 ) ;
V_64 = F_14 ( V_2 , V_82 ) ;
if ( V_64 < 0 )
return V_64 ;
V_65 = F_14 ( V_2 , V_83 ) ;
if ( V_65 < 0 )
return V_65 ;
V_8 = F_15 ( & V_2 -> V_77 , sizeof( struct V_7 ) ,
V_84 ) ;
if ( ! V_8 )
return - V_85 ;
V_8 -> V_61 = V_66 -> V_81 ;
V_6 = & V_8 -> V_6 ;
V_6 -> V_86 = 1 ;
V_6 -> V_87 [ V_88 ] = V_89 ;
V_6 -> V_87 [ V_90 ] = V_89 ;
V_6 -> V_87 [ V_91 ] = V_89 ;
V_6 -> V_87 [ V_92 ] = V_89 ;
V_6 -> V_93 [ 0 ] = V_94 | V_95 ;
V_6 -> V_96 = F_1 ;
V_6 -> V_97 = F_7 ;
V_6 -> V_98 = F_5 ;
switch ( V_8 -> V_61 ) {
case V_99 :
if ( V_65 & V_100 )
V_8 -> V_15 = true ;
else
V_8 -> V_12 = true ;
V_8 -> V_37 = true ;
V_8 -> V_51 = true ;
V_67 = V_101 ;
V_68 = 0 ;
switch ( V_64 & V_102 ) {
case V_103 :
V_70 = 1 ;
V_71 = 3 ;
break;
case V_104 :
V_70 = 2 ;
V_71 = 4 ;
break;
default:
F_12 ( & V_2 -> V_77 , L_7 ) ;
break;
}
V_6 -> V_93 [ 0 ] |= V_105 | V_106
| V_107 ;
if ( V_64 & V_108 )
V_6 -> V_93 [ 0 ] |=
V_109 | V_110 ;
break;
case V_111 :
if ( V_65 & V_100 )
V_8 -> V_15 = true ;
else
V_8 -> V_12 = true ;
V_8 -> V_17 = true ;
V_67 = V_112 ;
V_68 = ( V_64 & V_113 ) ? 0 : 1 ;
V_70 = 2 ;
if ( V_64 & V_108 )
V_6 -> V_93 [ 0 ] |=
V_109 | V_110 ;
else
V_6 -> V_93 [ 0 ] |=
V_105 | V_107 ;
break;
case V_114 :
if ( V_65 & V_100 )
V_8 -> V_15 = true ;
else
V_8 -> V_12 = true ;
V_8 -> V_17 = true ;
V_8 -> V_37 = true ;
V_67 = V_115 ;
V_68 = ( V_64 & V_113 ) ? 0 : 1 ;
V_70 = 2 ;
V_71 = ( V_64 & V_113 ) ? 3 : 4 ;
V_6 -> V_93 [ 0 ] |= V_105 | V_106
| V_107 ;
if ( V_64 & V_108 )
V_6 -> V_93 [ 0 ] |=
V_109 | V_110 ;
break;
case V_116 :
case V_117 :
V_8 -> V_25 = true ;
V_8 -> V_34 = true ;
V_8 -> V_37 = true ;
V_8 -> V_57 = true ;
V_67 = V_118 ;
V_69 = 0 ;
switch ( V_64 & V_119 ) {
case V_120 :
V_68 = 0 ;
break;
case V_121 :
V_68 = 1 ;
break;
case V_122 :
V_68 = 2 ;
break;
default:
break;
}
switch ( V_64 & V_123 ) {
case V_124 :
V_70 = 3 ;
break;
case V_125 :
V_70 = 4 ;
break;
case V_126 :
V_70 = 5 ;
break;
case V_127 :
V_70 = 6 ;
break;
}
if ( V_68 >= 0 )
V_71 = 7 + V_68 * 4 + ( V_70 - 3 ) ;
if ( V_64 & V_128 )
V_6 -> V_93 [ 0 ] |=
V_109 | V_110 ;
V_6 -> V_93 [ 0 ] |= V_106 |
V_105 | V_107 ;
break;
default:
F_12 ( & V_2 -> V_77 , L_5 ) ;
return - V_75 ;
}
if ( V_69 < 0 )
V_69 = V_68 ;
if ( V_68 >= 0 ) {
V_6 -> V_129 [ V_88 ] = V_67 [ V_68 ] . V_129 ;
V_6 -> V_130 [ V_88 ] = V_67 [ V_68 ] . V_130 ;
V_6 -> V_131 [ V_88 ] = V_67 [ V_68 ] . V_131 ;
}
if ( V_69 >= 0 ) {
V_6 -> V_129 [ V_90 ] = V_67 [ V_69 ] . V_129 ;
V_6 -> V_130 [ V_90 ] = V_67 [ V_69 ] . V_130 ;
V_6 -> V_131 [ V_90 ] = V_67 [ V_69 ] . V_131 ;
}
if ( V_70 >= 0 ) {
V_6 -> V_129 [ V_91 ] = V_67 [ V_70 ] . V_129 ;
V_6 -> V_130 [ V_91 ] = V_67 [ V_70 ] . V_130 ;
V_6 -> V_131 [ V_91 ] = V_67 [ V_70 ] . V_131 ;
}
if ( V_71 >= 0 ) {
V_6 -> V_129 [ V_92 ] = V_67 [ V_71 ] . V_129 ;
V_6 -> V_130 [ V_92 ] = V_67 [ V_71 ] . V_130 ;
V_6 -> V_131 [ V_92 ] = V_67 [ V_71 ] . V_131 ;
}
return F_16 ( V_2 , V_61 , V_6 ) ;
}
