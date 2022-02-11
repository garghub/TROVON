static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
int V_5 = 0 ;
int V_6 = 0 ;
int V_7 = 0 ;
int V_8 , V_9 , V_10 ;
switch ( V_4 -> V_11 ) {
case V_12 :
V_5 = V_13 ;
V_6 = V_14 << V_15 ;
V_7 = ( V_4 -> V_16 >> 4 ) << V_15 ;
break;
case V_17 :
V_5 = V_13 ;
V_6 = V_14 << V_18 ;
V_7 = ( V_4 -> V_16 >> 4 ) << V_18 ;
break;
case V_19 :
V_5 = V_13 ;
V_6 = V_14 << V_20 ;
V_7 = ( V_4 -> V_16 >> 4 ) << V_20 ;
break;
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
V_9 = V_4 -> V_11 - V_21 ;
V_8 = V_9 / 3 ;
V_5 = V_30 + V_9 / 3 ;
V_10 = ( V_9 - V_8 * 3 ) * 5 + V_31 ;
V_7 = ( V_4 -> V_16 >> 3 ) << V_10 ;
V_6 = V_32 << V_10 ;
break;
}
F_3 ( V_4 -> V_33 ) ;
F_4 ( V_4 -> V_33 , V_5 , V_6 , V_7 ) ;
F_5 ( V_4 -> V_33 ) ;
}
static void F_6 ( struct V_34 * V_35 ,
enum V_36 V_7 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_35 , struct V_3 , V_37 ) ;
V_4 -> V_16 = V_7 ;
F_7 ( & V_4 -> V_2 ) ;
}
static int T_1 F_8 ( struct V_3 * V_4 , int V_38 )
{
int V_10 = 0 ;
int V_6 = 0 ;
int V_7 = 0 ;
int V_5 = 0 ;
int V_39 , V_8 ;
switch ( V_4 -> V_11 ) {
case V_12 :
V_10 = V_40 ;
V_6 = V_41 ;
V_7 = V_38 & V_41 ;
V_5 = V_13 ;
break;
case V_17 :
V_10 = V_42 ;
V_6 = V_41 ;
V_7 = V_38 & V_41 ;
V_5 = V_13 ;
break;
case V_19 :
V_10 = V_43 ;
V_6 = V_41 ;
V_7 = V_38 & V_41 ;
V_5 = V_13 ;
break;
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
V_8 = ( V_4 -> V_11 - V_21 ) / 3 ;
V_5 = V_30 + V_8 ;
V_10 = ( ( V_4 -> V_11 - V_21 ) - V_8 * 3 ) * 2 ;
V_6 = V_44 ;
V_7 = V_38 & V_44 ;
break;
}
F_3 ( V_4 -> V_33 ) ;
V_39 = F_4 ( V_4 -> V_33 , V_5 , V_6 << V_10 ,
V_7 << V_10 ) ;
F_5 ( V_4 -> V_33 ) ;
return V_39 ;
}
static int T_1 F_9 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_10 ( & V_46 -> V_49 ) ;
struct V_50 * V_49 = F_11 ( V_46 -> V_49 . V_51 ) ;
int V_39 = 0 ;
int V_5 = 0 ;
F_3 ( V_49 ) ;
if ( V_48 -> V_52 & V_53 )
V_5 |= V_54 ;
if ( V_48 -> V_52 & V_55 )
V_5 |= V_56 ;
V_39 = F_12 ( V_49 , V_57 , V_5 ) ;
if ( V_39 )
goto V_58;
V_5 = ( V_48 -> V_59 & V_60 ) <<
V_61 ;
if ( V_48 -> V_52 & V_62 )
V_5 |= V_56 ;
V_39 = F_12 ( V_49 , V_13 , V_5 ) ;
if ( V_39 )
goto V_58;
V_5 = ( V_48 -> V_63 & V_60 ) <<
V_61 ;
if ( V_48 -> V_52 & V_64 )
V_5 |= V_65 ;
V_39 = F_12 ( V_49 , V_30 , V_5 ) ;
if ( V_39 )
goto V_58;
V_5 = ( V_48 -> V_66 & V_60 ) <<
V_61 ;
if ( V_48 -> V_52 & V_67 )
V_5 |= V_65 ;
V_39 = F_12 ( V_49 , V_68 , V_5 ) ;
if ( V_39 )
goto V_58;
V_5 = ( V_48 -> V_69 & V_60 ) <<
V_61 ;
if ( V_48 -> V_52 & V_70 )
V_5 |= V_65 ;
V_39 = F_12 ( V_49 , V_71 , V_5 ) ;
if ( V_39 )
goto V_58;
V_5 = V_72 ;
if ( V_48 -> V_52 & V_73 )
V_5 |= V_74 ;
if ( V_48 -> V_52 & V_75 )
V_5 |= V_76 ;
if ( V_48 -> V_52 & V_77 )
V_5 |= V_78 ;
if ( V_48 -> V_52 & V_79 )
V_5 |= V_80 ;
V_5 |= ( V_48 -> V_81 & V_82 ) <<
V_83 ;
V_5 |= ( V_48 -> V_84 & V_85 ) <<
V_86 ;
V_39 = F_12 ( V_49 , V_87 , V_5 ) ;
V_58:
F_5 ( V_49 ) ;
return V_39 ;
}
static int T_1 F_13 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_10 ( & V_46 -> V_49 ) ;
struct V_88 * V_89 ;
struct V_3 * V_4 , * V_90 ;
int V_39 , V_91 ;
int V_92 = 0 ;
if ( V_48 == NULL ) {
F_14 ( & V_46 -> V_49 , L_1 ) ;
return - V_93 ;
}
if ( V_48 -> V_94 < 1 || V_48 -> V_94 > ( V_95 + 1 ) ) {
F_14 ( & V_46 -> V_49 , L_2 , V_48 -> V_94 ) ;
return - V_96 ;
}
V_4 = F_15 ( V_48 -> V_94 , sizeof( * V_4 ) , V_97 ) ;
if ( V_4 == NULL ) {
F_14 ( & V_46 -> V_49 , L_3 ) ;
return - V_98 ;
}
V_39 = F_9 ( V_46 ) ;
if ( V_39 ) {
F_14 ( & V_46 -> V_49 , L_4 ) ;
goto V_99;
}
for ( V_91 = 0 ; V_91 < V_48 -> V_94 ; V_91 ++ ) {
V_90 = & V_4 [ V_91 ] ;
V_89 = & V_48 -> V_4 [ V_91 ] ;
if ( V_89 -> V_11 > V_95 || V_89 -> V_11 < 0 ) {
F_14 ( & V_46 -> V_49 , L_5 , V_89 -> V_11 ) ;
V_39 = - V_96 ;
goto V_100;
}
if ( V_92 & ( 1 << V_89 -> V_11 ) ) {
F_14 ( & V_46 -> V_49 , L_6 ,
V_89 -> V_11 ) ;
V_39 = - V_96 ;
goto V_100;
}
V_92 |= 1 << V_89 -> V_11 ;
V_90 -> V_37 . V_101 = V_89 -> V_101 ;
V_90 -> V_37 . V_102 = V_89 -> V_102 ;
V_90 -> V_37 . V_103 = F_6 ;
V_90 -> V_37 . V_104 = V_105 ;
V_90 -> V_11 = V_89 -> V_11 ;
V_90 -> V_33 = F_11 ( V_46 -> V_49 . V_51 ) ;
F_16 ( & V_90 -> V_2 , F_1 ) ;
V_39 = F_17 ( V_46 -> V_49 . V_51 , & V_90 -> V_37 ) ;
if ( V_39 ) {
F_14 ( & V_46 -> V_49 , L_7 ,
V_90 -> V_11 ) ;
goto V_100;
}
V_39 = F_8 ( V_90 , V_89 -> V_38 ) ;
if ( V_39 ) {
F_14 ( & V_46 -> V_49 , L_8 ,
V_90 -> V_11 ) ;
V_91 ++ ;
goto V_100;
}
}
F_18 ( V_46 , V_4 ) ;
return 0 ;
V_100:
for ( V_91 = V_91 - 1 ; V_91 >= 0 ; V_91 -- ) {
F_19 ( & V_4 [ V_91 ] . V_37 ) ;
F_20 ( & V_4 [ V_91 ] . V_2 ) ;
}
V_99:
F_21 ( V_4 ) ;
return V_39 ;
}
static int T_2 F_22 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_10 ( & V_46 -> V_49 ) ;
struct V_3 * V_4 = F_23 ( V_46 ) ;
struct V_50 * V_49 = F_11 ( V_46 -> V_49 . V_51 ) ;
int V_91 ;
for ( V_91 = 0 ; V_91 < V_48 -> V_94 ; V_91 ++ ) {
F_19 ( & V_4 [ V_91 ] . V_37 ) ;
F_20 ( & V_4 [ V_91 ] . V_2 ) ;
}
F_3 ( V_49 ) ;
F_12 ( V_49 , V_87 , 0 ) ;
F_12 ( V_49 , V_57 , 0 ) ;
F_12 ( V_49 , V_13 , 0 ) ;
F_12 ( V_49 , V_30 , 0 ) ;
F_12 ( V_49 , V_68 , 0 ) ;
F_12 ( V_49 , V_71 , 0 ) ;
F_5 ( V_49 ) ;
F_21 ( V_4 ) ;
return 0 ;
}
