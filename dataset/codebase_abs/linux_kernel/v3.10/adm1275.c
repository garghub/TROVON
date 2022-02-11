static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 = 0 ;
if ( V_3 )
return - V_10 ;
switch ( V_4 ) {
case V_11 :
if ( V_8 -> V_12 ) {
V_9 = - V_10 ;
break;
}
V_9 = F_4 ( V_2 , 0 , V_13 ) ;
break;
case V_14 :
if ( ! V_8 -> V_12 ) {
V_9 = - V_10 ;
break;
}
V_9 = F_4 ( V_2 , 0 , V_13 ) ;
break;
case V_15 :
if ( V_8 -> V_16 != V_17 ) {
V_9 = - V_18 ;
break;
}
V_9 = F_4 ( V_2 , 0 ,
V_19 ) ;
break;
case V_20 :
if ( V_8 -> V_16 != V_17 ) {
V_9 = - V_18 ;
break;
}
V_9 = F_4 ( V_2 , 0 ,
V_21 ) ;
break;
case V_22 :
if ( V_8 -> V_16 != V_17 ) {
V_9 = - V_18 ;
break;
}
V_9 = F_4 ( V_2 , 0 , V_23 ) ;
break;
case V_24 :
V_9 = F_4 ( V_2 , 0 , V_25 ) ;
break;
case V_26 :
V_9 = F_4 ( V_2 , 0 , V_27 ) ;
break;
case V_28 :
V_9 = F_4 ( V_2 , 0 , V_29 ) ;
break;
case V_30 :
if ( V_8 -> V_16 == V_31 ) {
V_9 = - V_10 ;
break;
}
V_9 = F_4 ( V_2 , 0 , V_32 ) ;
break;
case V_33 :
case V_34 :
case V_35 :
break;
case V_36 :
if ( V_8 -> V_16 == V_31 )
V_9 = - V_10 ;
break;
default:
V_9 = - V_18 ;
break;
}
return V_9 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 V_37 )
{
int V_9 ;
if ( V_3 )
return - V_10 ;
switch ( V_4 ) {
case V_11 :
case V_14 :
V_9 = F_6 ( V_2 , 0 , V_13 ,
V_37 ) ;
break;
case V_33 :
V_9 = F_6 ( V_2 , 0 , V_25 , 0 ) ;
break;
case V_34 :
V_9 = F_6 ( V_2 , 0 , V_27 , 0 ) ;
break;
case V_35 :
V_9 = F_6 ( V_2 , 0 , V_29 , 0 ) ;
break;
case V_36 :
V_9 = F_6 ( V_2 , 0 , V_32 , 0 ) ;
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
int V_38 , V_9 ;
if ( V_3 > 0 )
return - V_10 ;
switch ( V_4 ) {
case V_39 :
V_9 = F_8 ( V_2 , V_3 , V_39 ) ;
if ( V_9 < 0 )
break;
V_38 = F_8 ( V_2 , V_3 ,
V_40 ) ;
if ( V_38 < 0 ) {
V_9 = V_38 ;
break;
}
if ( V_38 & V_41 ) {
V_9 |= V_8 -> V_12 ?
V_42 : V_43 ;
}
break;
case V_44 :
if ( V_8 -> V_16 != V_17 ) {
V_9 = - V_18 ;
break;
}
V_9 = 0 ;
V_38 = F_8 ( V_2 , 0 ,
V_45 ) ;
if ( V_38 & V_46 )
V_9 |= V_47 ;
if ( V_38 & V_48 )
V_9 |= V_49 ;
break;
default:
V_9 = - V_18 ;
break;
}
return V_9 ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_50 * V_16 )
{
T_2 V_51 [ V_52 + 1 ] ;
int V_53 , V_54 ;
int V_9 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
const struct V_50 * V_55 ;
if ( ! F_10 ( V_2 -> V_56 ,
V_57
| V_58 ) )
return - V_59 ;
V_9 = F_11 ( V_2 , V_60 , V_51 ) ;
if ( V_9 < 0 ) {
F_12 ( & V_2 -> V_61 , L_1 ) ;
return V_9 ;
}
if ( V_9 != 3 || strncmp ( V_51 , L_2 , 3 ) ) {
F_12 ( & V_2 -> V_61 , L_3 ) ;
return - V_59 ;
}
V_9 = F_11 ( V_2 , V_62 , V_51 ) ;
if ( V_9 < 0 ) {
F_12 ( & V_2 -> V_61 , L_4 ) ;
return V_9 ;
}
for ( V_55 = V_63 ; V_55 -> V_64 [ 0 ] ; V_55 ++ ) {
if ( ! strncasecmp ( V_55 -> V_64 , V_51 , strlen ( V_55 -> V_64 ) ) )
break;
}
if ( ! V_55 -> V_64 [ 0 ] ) {
F_12 ( & V_2 -> V_61 , L_5 ) ;
return - V_59 ;
}
if ( V_16 -> V_65 != V_55 -> V_65 )
F_13 ( & V_2 -> V_61 ,
L_6 ,
V_16 -> V_64 , V_55 -> V_64 ) ;
V_53 = F_14 ( V_2 , V_66 ) ;
if ( V_53 < 0 )
return V_53 ;
V_54 = F_14 ( V_2 , V_67 ) ;
if ( V_54 < 0 )
return V_54 ;
V_8 = F_15 ( & V_2 -> V_61 , sizeof( struct V_7 ) ,
V_68 ) ;
if ( ! V_8 )
return - V_69 ;
V_8 -> V_16 = V_55 -> V_65 ;
V_6 = & V_8 -> V_6 ;
V_6 -> V_70 = 1 ;
V_6 -> V_71 [ V_72 ] = V_73 ;
V_6 -> V_71 [ V_74 ] = V_73 ;
V_6 -> V_71 [ V_75 ] = V_73 ;
V_6 -> V_76 [ V_75 ] = 807 ;
V_6 -> V_77 [ V_75 ] = 20475 ;
V_6 -> V_78 [ V_75 ] = - 1 ;
V_6 -> V_79 [ 0 ] = V_80 | V_81 ;
V_6 -> V_82 = F_1 ;
V_6 -> V_83 = F_7 ;
V_6 -> V_84 = F_5 ;
if ( V_8 -> V_16 == V_17 ) {
V_6 -> V_76 [ V_72 ] = 27169 ;
V_6 -> V_77 [ V_72 ] = 0 ;
V_6 -> V_78 [ V_72 ] = - 1 ;
V_6 -> V_76 [ V_74 ] = 27169 ;
V_6 -> V_77 [ V_74 ] = 0 ;
V_6 -> V_78 [ V_74 ] = - 1 ;
} else if ( V_53 & V_85 ) {
V_6 -> V_76 [ V_72 ] = 19199 ;
V_6 -> V_77 [ V_72 ] = 0 ;
V_6 -> V_78 [ V_72 ] = - 2 ;
V_6 -> V_76 [ V_74 ] = 19199 ;
V_6 -> V_77 [ V_74 ] = 0 ;
V_6 -> V_78 [ V_74 ] = - 2 ;
} else {
V_6 -> V_76 [ V_72 ] = 6720 ;
V_6 -> V_77 [ V_72 ] = 0 ;
V_6 -> V_78 [ V_72 ] = - 1 ;
V_6 -> V_76 [ V_74 ] = 6720 ;
V_6 -> V_77 [ V_74 ] = 0 ;
V_6 -> V_78 [ V_74 ] = - 1 ;
}
if ( V_54 & V_86 )
V_8 -> V_12 = true ;
switch ( V_8 -> V_16 ) {
case V_17 :
V_6 -> V_71 [ V_87 ] = V_73 ;
V_6 -> V_77 [ V_87 ] = 0 ;
V_6 -> V_78 [ V_87 ] = - 1 ;
switch ( V_53 & V_88 ) {
case V_89 :
V_6 -> V_76 [ V_87 ] = 8549 ;
V_6 -> V_76 [ V_75 ] = 806 ;
break;
case V_90 :
V_6 -> V_76 [ V_87 ] = 4279 ;
V_6 -> V_76 [ V_75 ] = 404 ;
break;
default:
F_12 ( & V_2 -> V_61 , L_7 ) ;
V_6 -> V_76 [ V_87 ] = 0 ;
V_6 -> V_76 [ V_75 ] = 0 ;
break;
}
V_6 -> V_79 [ 0 ] |= V_91 | V_92
| V_93 ;
if ( V_53 & V_94 )
V_6 -> V_79 [ 0 ] |=
V_95 | V_96 ;
break;
case V_31 :
if ( V_53 & V_94 )
V_6 -> V_79 [ 0 ] |=
V_95 | V_96 ;
else
V_6 -> V_79 [ 0 ] |=
V_91 | V_93 ;
break;
case V_97 :
V_6 -> V_71 [ V_87 ] = V_73 ;
V_6 -> V_79 [ 0 ] |= V_91 | V_92
| V_93 ;
if ( V_53 & V_94 )
V_6 -> V_79 [ 0 ] |=
V_95 | V_96 ;
if ( V_53 & V_85 ) {
V_6 -> V_76 [ V_87 ] = 6043 ;
V_6 -> V_77 [ V_87 ] = 0 ;
V_6 -> V_78 [ V_87 ] = - 2 ;
} else {
V_6 -> V_76 [ V_87 ] = 2115 ;
V_6 -> V_77 [ V_87 ] = 0 ;
V_6 -> V_78 [ V_87 ] = - 1 ;
}
break;
}
return F_16 ( V_2 , V_16 , V_6 ) ;
}
