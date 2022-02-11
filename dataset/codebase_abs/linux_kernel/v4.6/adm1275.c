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
if ( ! V_8 -> V_40 )
return - V_10 ;
V_9 = F_4 ( V_2 , 0 , V_41 ) ;
break;
case V_42 :
case V_43 :
case V_44 :
break;
case V_45 :
if ( ! V_8 -> V_37 )
return - V_10 ;
break;
case V_46 :
if ( ! V_8 -> V_40 )
return - V_10 ;
break;
default:
V_9 = - V_18 ;
break;
}
return V_9 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 V_47 )
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
V_47 ) ;
break;
case V_42 :
V_9 = F_6 ( V_2 , 0 , V_28 , 0 ) ;
if ( ! V_9 && V_8 -> V_25 )
V_9 = F_6 ( V_2 , 0 ,
V_26 , 0 ) ;
break;
case V_43 :
V_9 = F_6 ( V_2 , 0 , V_30 , 0 ) ;
break;
case V_44 :
V_9 = F_6 ( V_2 , 0 , V_32 , 0 ) ;
break;
case V_45 :
V_9 = F_6 ( V_2 , 0 , V_38 , 0 ) ;
if ( ! V_9 && V_8 -> V_34 )
V_9 = F_6 ( V_2 , 0 ,
V_35 , 0 ) ;
break;
case V_46 :
V_9 = F_6 ( V_2 , 0 , V_41 , 0 ) ;
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
int V_48 , V_9 ;
if ( V_3 > 0 )
return - V_10 ;
switch ( V_4 ) {
case V_49 :
V_9 = F_8 ( V_2 , V_3 , V_49 ) ;
if ( V_9 < 0 )
break;
if ( ! V_8 -> V_15 && ! V_8 -> V_12 )
break;
V_48 = F_8 ( V_2 , V_3 ,
V_50 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_48 & V_51 ) {
V_9 |= V_8 -> V_15 ?
V_52 : V_53 ;
}
break;
case V_54 :
if ( V_8 -> V_17 )
return - V_18 ;
V_9 = 0 ;
if ( V_8 -> V_55 ) {
V_48 = F_8 ( V_2 , 0 ,
V_56 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_48 & V_57 )
V_9 |= V_58 ;
if ( V_48 & V_59 )
V_9 |= V_60 ;
} else if ( V_8 -> V_61 ) {
V_48 = F_8 ( V_2 , V_3 ,
V_50 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_48 & V_62 )
V_9 |= V_58 ;
if ( V_48 & V_63 )
V_9 |= V_60 ;
}
break;
default:
V_9 = - V_18 ;
break;
}
return V_9 ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_64 * V_65 )
{
T_2 V_66 [ V_67 + 1 ] ;
int V_68 , V_69 ;
int V_9 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
const struct V_64 * V_70 ;
const struct V_71 * V_71 ;
int V_72 = - 1 , V_73 = - 1 , V_74 = - 1 , V_75 = - 1 ;
int V_76 = - 1 ;
if ( ! F_10 ( V_2 -> V_77 ,
V_78
| V_79 ) )
return - V_80 ;
V_9 = F_11 ( V_2 , V_81 , V_66 ) ;
if ( V_9 < 0 ) {
F_12 ( & V_2 -> V_82 , L_1 ) ;
return V_9 ;
}
if ( V_9 != 3 || strncmp ( V_66 , L_2 , 3 ) ) {
F_12 ( & V_2 -> V_82 , L_3 ) ;
return - V_80 ;
}
V_9 = F_11 ( V_2 , V_83 , V_66 ) ;
if ( V_9 < 0 ) {
F_12 ( & V_2 -> V_82 , L_4 ) ;
return V_9 ;
}
for ( V_70 = V_84 ; V_70 -> V_85 [ 0 ] ; V_70 ++ ) {
if ( ! strncasecmp ( V_70 -> V_85 , V_66 , strlen ( V_70 -> V_85 ) ) )
break;
}
if ( ! V_70 -> V_85 [ 0 ] ) {
F_12 ( & V_2 -> V_82 , L_5 ) ;
return - V_80 ;
}
if ( V_65 -> V_86 != V_70 -> V_86 )
F_13 ( & V_2 -> V_82 ,
L_6 ,
V_65 -> V_85 , V_70 -> V_85 ) ;
V_68 = F_14 ( V_2 , V_87 ) ;
if ( V_68 < 0 )
return V_68 ;
V_69 = F_14 ( V_2 , V_88 ) ;
if ( V_69 < 0 )
return V_69 ;
V_8 = F_15 ( & V_2 -> V_82 , sizeof( struct V_7 ) ,
V_89 ) ;
if ( ! V_8 )
return - V_90 ;
V_8 -> V_65 = V_70 -> V_86 ;
V_6 = & V_8 -> V_6 ;
V_6 -> V_91 = 1 ;
V_6 -> V_92 [ V_93 ] = V_94 ;
V_6 -> V_92 [ V_95 ] = V_94 ;
V_6 -> V_92 [ V_96 ] = V_94 ;
V_6 -> V_92 [ V_97 ] = V_94 ;
V_6 -> V_92 [ V_98 ] = V_94 ;
V_6 -> V_99 [ 0 ] = V_100 | V_101 ;
V_6 -> V_102 = F_1 ;
V_6 -> V_103 = F_7 ;
V_6 -> V_104 = F_5 ;
switch ( V_8 -> V_65 ) {
case V_105 :
if ( V_69 & V_106 )
V_8 -> V_15 = true ;
else
V_8 -> V_12 = true ;
V_8 -> V_37 = true ;
V_8 -> V_55 = true ;
V_71 = V_107 ;
V_72 = 0 ;
switch ( V_68 & V_108 ) {
case V_109 :
V_74 = 1 ;
V_75 = 3 ;
break;
case V_110 :
V_74 = 2 ;
V_75 = 4 ;
break;
default:
F_12 ( & V_2 -> V_82 , L_7 ) ;
break;
}
V_6 -> V_99 [ 0 ] |= V_111 | V_112
| V_113 ;
if ( V_68 & V_114 )
V_6 -> V_99 [ 0 ] |=
V_115 | V_116 ;
break;
case V_117 :
if ( V_69 & V_106 )
V_8 -> V_15 = true ;
else
V_8 -> V_12 = true ;
V_8 -> V_17 = true ;
V_71 = V_118 ;
V_72 = ( V_68 & V_119 ) ? 0 : 1 ;
V_74 = 2 ;
if ( V_68 & V_114 )
V_6 -> V_99 [ 0 ] |=
V_115 | V_116 ;
else
V_6 -> V_99 [ 0 ] |=
V_111 | V_113 ;
break;
case V_120 :
if ( V_69 & V_106 )
V_8 -> V_15 = true ;
else
V_8 -> V_12 = true ;
V_8 -> V_17 = true ;
V_8 -> V_37 = true ;
V_71 = V_121 ;
V_72 = ( V_68 & V_119 ) ? 0 : 1 ;
V_74 = 2 ;
V_75 = ( V_68 & V_119 ) ? 3 : 4 ;
V_6 -> V_99 [ 0 ] |= V_111 | V_112
| V_113 ;
if ( V_68 & V_114 )
V_6 -> V_99 [ 0 ] |=
V_115 | V_116 ;
break;
case V_122 :
V_8 -> V_17 = true ;
V_8 -> V_37 = true ;
V_8 -> V_40 = true ;
V_71 = V_123 ;
V_72 = 0 ;
V_74 = 1 ;
V_75 = 2 ;
V_76 = 3 ;
V_6 -> V_99 [ 0 ] |= V_112 | V_113 ;
if ( V_68 & V_124 )
V_6 -> V_99 [ 0 ] |=
V_125 | V_126 ;
if ( V_68 & V_127 )
V_6 -> V_99 [ 0 ] |= V_111 ;
if ( V_68 & V_128 )
V_6 -> V_99 [ 0 ] |=
V_115 | V_116 ;
break;
case V_129 :
case V_130 :
V_8 -> V_25 = true ;
V_8 -> V_34 = true ;
V_8 -> V_37 = true ;
V_8 -> V_61 = true ;
V_71 = V_131 ;
V_73 = 0 ;
switch ( V_68 & V_132 ) {
case V_133 :
V_72 = 0 ;
break;
case V_134 :
V_72 = 1 ;
break;
case V_135 :
V_72 = 2 ;
break;
default:
break;
}
switch ( V_68 & V_136 ) {
case V_137 :
V_74 = 3 ;
break;
case V_138 :
V_74 = 4 ;
break;
case V_139 :
V_74 = 5 ;
break;
case V_140 :
V_74 = 6 ;
break;
}
if ( V_72 >= 0 )
V_75 = 7 + V_72 * 4 + ( V_74 - 3 ) ;
if ( V_68 & V_141 )
V_6 -> V_99 [ 0 ] |=
V_115 | V_116 ;
V_6 -> V_99 [ 0 ] |= V_112 |
V_111 | V_113 ;
break;
default:
F_12 ( & V_2 -> V_82 , L_5 ) ;
return - V_80 ;
}
if ( V_73 < 0 )
V_73 = V_72 ;
if ( V_72 >= 0 ) {
V_6 -> V_142 [ V_93 ] = V_71 [ V_72 ] . V_142 ;
V_6 -> V_143 [ V_93 ] = V_71 [ V_72 ] . V_143 ;
V_6 -> V_144 [ V_93 ] = V_71 [ V_72 ] . V_144 ;
}
if ( V_73 >= 0 ) {
V_6 -> V_142 [ V_95 ] = V_71 [ V_73 ] . V_142 ;
V_6 -> V_143 [ V_95 ] = V_71 [ V_73 ] . V_143 ;
V_6 -> V_144 [ V_95 ] = V_71 [ V_73 ] . V_144 ;
}
if ( V_74 >= 0 ) {
V_6 -> V_142 [ V_96 ] = V_71 [ V_74 ] . V_142 ;
V_6 -> V_143 [ V_96 ] = V_71 [ V_74 ] . V_143 ;
V_6 -> V_144 [ V_96 ] = V_71 [ V_74 ] . V_144 ;
}
if ( V_75 >= 0 ) {
V_6 -> V_142 [ V_97 ] = V_71 [ V_75 ] . V_142 ;
V_6 -> V_143 [ V_97 ] = V_71 [ V_75 ] . V_143 ;
V_6 -> V_144 [ V_97 ] = V_71 [ V_75 ] . V_144 ;
}
if ( V_76 >= 0 ) {
V_6 -> V_142 [ V_98 ] = V_71 [ V_76 ] . V_142 ;
V_6 -> V_143 [ V_98 ] = V_71 [ V_76 ] . V_143 ;
V_6 -> V_144 [ V_98 ] = V_71 [ V_76 ] . V_144 ;
}
return F_16 ( V_2 , V_65 , V_6 ) ;
}
