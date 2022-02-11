int F_1 ( struct V_1 * V_1 , unsigned int V_2 )
{
int V_3 ;
unsigned int V_4 ;
F_2 ( & V_1 -> V_5 ) ;
if ( F_3 ( V_2 == V_6 ||
V_2 == V_7 ) ) {
V_4 = V_1 -> V_8 [ F_4 ( V_2 ) ] ;
} else {
V_3 = F_5 ( V_1 -> V_9 , V_2 , & V_4 ) ;
if ( V_3 < 0 ) {
F_6 ( & V_1 -> V_5 ) ;
return V_3 ;
}
}
F_6 ( & V_1 -> V_5 ) ;
return V_4 ;
}
int F_7 ( struct V_1 * V_1 , unsigned int V_2 , T_1 V_4 )
{
int V_3 ;
F_2 ( & V_1 -> V_5 ) ;
V_3 = F_8 ( V_1 -> V_9 , V_2 , V_4 ) ;
if ( V_2 == V_6 || V_2 == V_7 )
V_1 -> V_8 [ F_4 ( V_2 ) ] = V_4 ;
F_6 ( & V_1 -> V_5 ) ;
return V_3 ;
}
int F_9 ( struct V_1 * V_1 , unsigned int V_2 , T_1 V_10 )
{
int V_3 ;
F_2 ( & V_1 -> V_5 ) ;
V_3 = F_10 ( V_1 -> V_9 , V_2 , V_10 , V_10 ) ;
F_6 ( & V_1 -> V_5 ) ;
return V_3 ;
}
int F_11 ( struct V_1 * V_1 , unsigned int V_2 , T_1 V_10 )
{
int V_3 ;
F_2 ( & V_1 -> V_5 ) ;
V_3 = F_10 ( V_1 -> V_9 , V_2 , V_10 , 0 ) ;
F_6 ( & V_1 -> V_5 ) ;
return V_3 ;
}
static int F_12 ( struct V_1 * V_1 )
{
T_1 V_11 , V_12 , V_13 ;
int V_3 ;
V_11 = V_14 | V_15 | V_16 ;
V_3 = F_7 ( V_1 , V_17 , V_11 ) ;
if ( V_3 )
return V_3 ;
F_13 ( 10000 , 10500 ) ;
V_12 = V_18 ;
V_3 = F_7 ( V_1 , V_19 , V_12 ) ;
if ( V_3 )
goto V_20;
F_13 ( 1000 , 1500 ) ;
V_11 |= V_21 ;
V_3 = F_7 ( V_1 , V_17 , V_11 ) ;
if ( V_3 )
goto V_22;
F_13 ( 1000 , 1500 ) ;
V_13 = V_23 ;
V_3 = F_7 ( V_1 , V_24 , V_13 ) ;
if ( V_3 )
goto V_25;
F_13 ( 5000 , 5500 ) ;
V_11 &= ~ V_16 ;
V_3 = F_7 ( V_1 , V_17 , V_11 ) ;
if ( V_3 )
goto V_26;
return 0 ;
V_26:
V_13 &= ~ V_23 ;
F_7 ( V_1 , V_24 , V_13 ) ;
V_25:
V_11 &= ~ V_21 ;
F_7 ( V_1 , V_17 , V_11 ) ;
V_22:
V_12 &= ~ V_18 ;
F_7 ( V_1 , V_19 , V_12 ) ;
V_20:
V_11 &= ~ ( V_14 | V_15 | V_16 ) ;
F_7 ( V_1 , V_17 , V_11 ) ;
return V_3 ;
}
static void F_14 ( struct V_1 * V_1 )
{
T_1 V_12 , V_11 , V_13 ;
V_12 = F_1 ( V_1 , V_19 ) ;
V_11 = F_1 ( V_1 , V_17 ) ;
V_13 = F_1 ( V_1 , V_24 ) ;
V_11 |= V_16 ;
F_7 ( V_1 , V_17 , V_11 ) ;
F_13 ( 1000 , 1500 ) ;
V_13 &= ~ V_23 ;
F_7 ( V_1 , V_24 , V_13 ) ;
V_11 &= ~ V_21 ;
F_7 ( V_1 , V_17 , V_11 ) ;
V_12 &= ~ V_18 ;
F_7 ( V_1 , V_19 , V_12 ) ;
V_11 &= ~ ( V_14 | V_15 | V_16 ) ;
F_7 ( V_1 , V_17 , V_11 ) ;
}
static T_2 F_15 ( int V_27 , void * V_28 )
{
struct V_1 * V_1 = V_28 ;
T_1 V_29 , V_30 ;
V_29 = F_1 ( V_1 , V_31 ) ;
if ( V_29 & V_32 )
F_16 ( & V_1 -> V_33 ) ;
if ( V_29 & V_34 ) {
V_30 = F_1 ( V_1 , V_35 ) ;
if ( V_30 & V_36 ) {
F_17 ( V_1 -> V_37 ,
L_1 ) ;
F_18 ( V_1 , 0 ) ;
} else {
F_17 ( V_1 -> V_37 ,
L_2 ) ;
F_18 ( V_1 , 1 ) ;
}
}
return V_38 ;
}
static int F_19 ( struct V_1 * V_1 ,
int V_39 )
{
int V_40 ;
T_1 V_29 ;
V_40 = F_20 ( & V_1 -> V_33 ,
F_21 ( 144 ) ) ;
if ( ! V_40 ) {
V_29 = F_1 ( V_1 , V_31 ) ;
if ( ! ( V_29 & V_32 ) ) {
F_22 ( V_1 -> V_37 ,
L_3 ) ;
return - V_41 ;
}
}
return 0 ;
}
int F_18 ( struct V_1 * V_1 , int V_42 )
{
int V_43 = V_1 -> V_43 ;
int V_39 = V_1 -> V_27 ;
int V_3 = 0 ;
F_2 ( & V_1 -> V_44 ) ;
if ( V_42 ) {
if ( V_1 -> V_45 ++ )
goto V_46;
if ( F_23 ( V_43 ) ) {
F_24 ( V_43 , 1 ) ;
V_3 = F_19 ( V_1 , V_39 ) ;
if ( V_3 ) {
F_22 ( V_1 -> V_37 ,
L_4 ) ;
V_1 -> V_45 = 0 ;
goto V_46;
}
} else {
V_3 = F_12 ( V_1 ) ;
if ( V_3 ) {
F_22 ( V_1 -> V_37 ,
L_5 ) ;
V_1 -> V_45 = 0 ;
goto V_46;
}
}
V_1 -> V_47 = V_48 ;
V_1 -> V_49 = 19200000 ;
V_1 -> V_50 = 32768 ;
} else {
if ( ! V_1 -> V_45 ) {
F_22 ( V_1 -> V_37 ,
L_6 ) ;
V_3 = - V_51 ;
goto V_46;
}
if ( -- V_1 -> V_45 )
goto V_46;
if ( F_23 ( V_43 ) ) {
F_24 ( V_43 , 0 ) ;
F_13 ( 500 , 700 ) ;
} else {
F_14 ( V_1 ) ;
}
V_1 -> V_49 = 0 ;
V_1 -> V_50 = 0 ;
}
V_46:
F_6 ( & V_1 -> V_44 ) ;
return V_3 ;
}
int F_25 ( struct V_1 * V_1 , int V_52 ,
unsigned int V_53 , unsigned int V_54 )
{
T_1 V_55 , V_13 ;
int V_3 = 0 ;
F_2 ( & V_1 -> V_44 ) ;
V_55 = F_1 ( V_1 , V_56 ) ;
V_13 = F_1 ( V_1 , V_24 ) ;
if ( V_52 != V_1 -> V_47 ) {
V_1 -> V_49 = 0 ;
V_1 -> V_50 = 0 ;
}
switch ( V_52 ) {
case V_48 :
if ( V_1 -> V_49 != V_54 ) {
switch ( V_54 ) {
case 17640000 :
V_13 |= V_57 ;
break;
case 19200000 :
V_13 &= ~ V_57 ;
break;
default:
F_22 ( V_1 -> V_37 ,
L_7 ,
V_54 ) ;
V_3 = - V_58 ;
goto V_59;
}
F_7 ( V_1 , V_24 ,
V_13 ) ;
}
if ( V_1 -> V_47 == V_52 )
break;
switch ( V_53 ) {
case 32768 :
V_13 |= V_23 ;
F_7 ( V_1 , V_24 ,
V_13 ) ;
F_26 ( 5 ) ;
V_13 &= ~ V_60 ;
F_7 ( V_1 , V_24 ,
V_13 ) ;
V_55 &= ~ V_61 ;
F_7 ( V_1 , V_56 ,
V_55 ) ;
break;
default:
F_22 ( V_1 -> V_37 ,
L_8 , V_53 ) ;
V_3 = - V_58 ;
goto V_59;
}
break;
case V_62 :
if ( V_54 != 19200000 ) {
F_22 ( V_1 -> V_37 ,
L_7 , V_54 ) ;
V_3 = - V_58 ;
goto V_59;
}
if ( V_1 -> V_50 != V_53 ) {
V_55 &= ~ V_63 ;
switch ( V_53 ) {
case 12000000 :
V_55 |= V_64 |
V_61 ;
break;
case 19200000 :
V_55 |= V_65 ;
break;
case 26000000 :
V_55 |= V_66 |
V_61 ;
break;
case 38400000 :
V_55 |= V_67 |
V_61 ;
break;
default:
F_22 ( V_1 -> V_37 ,
L_8 , V_53 ) ;
V_3 = - V_58 ;
goto V_59;
}
V_55 |= V_68 ;
F_7 ( V_1 , V_56 ,
V_55 ) ;
F_13 ( 500 , 700 ) ;
V_13 |= V_60 ;
F_7 ( V_1 , V_24 ,
V_13 ) ;
V_13 &= ~ V_23 ;
F_7 ( V_1 , V_24 ,
V_13 ) ;
}
break;
default:
F_22 ( V_1 -> V_37 , L_9 , V_52 ) ;
V_3 = - V_58 ;
goto V_59;
}
V_1 -> V_49 = V_54 ;
V_1 -> V_50 = V_53 ;
V_1 -> V_47 = V_52 ;
V_59:
F_6 ( & V_1 -> V_44 ) ;
return V_3 ;
}
int F_27 ( struct V_1 * V_1 )
{
if ( V_1 -> V_45 )
return V_1 -> V_47 ;
else
return - V_69 ;
}
unsigned int F_28 ( struct V_1 * V_1 )
{
return V_1 -> V_49 ;
}
int F_29 ( struct V_1 * V_1 )
{
T_1 V_30 ;
V_30 = V_1 -> V_8 [ 0 ] | V_1 -> V_8 [ 1 ] ;
V_30 &= ( V_70 | V_71 ) ;
return V_30 ;
}
static bool F_30 ( struct V_72 * V_37 , unsigned int V_2 )
{
if ( ! V_2 )
return false ;
return true ;
}
static int T_3 F_31 ( struct V_73 * V_74 ,
const struct V_75 * V_76 )
{
struct V_77 * V_78 = V_74 -> V_37 . V_79 ;
struct V_1 * V_1 ;
struct V_80 * V_81 = NULL ;
int V_3 , V_82 = 0 ;
if ( ! V_78 ) {
F_22 ( & V_74 -> V_37 , L_10 ) ;
return - V_58 ;
}
if ( ! V_74 -> V_27 || ! V_78 -> V_83 ) {
F_22 ( & V_74 -> V_37 , L_11 ) ;
return - V_58 ;
}
V_1 = F_32 ( & V_74 -> V_37 , sizeof( struct V_1 ) ,
V_84 ) ;
if ( ! V_1 ) {
V_3 = - V_85 ;
goto V_86;
}
V_1 -> V_9 = F_33 ( V_74 , & V_87 ) ;
if ( F_34 ( V_1 -> V_9 ) ) {
V_3 = F_35 ( V_1 -> V_9 ) ;
goto V_86;
}
F_36 ( V_74 , V_1 ) ;
V_1 -> V_37 = & V_74 -> V_37 ;
V_1 -> V_27 = V_74 -> V_27 ;
V_1 -> V_83 = V_78 -> V_83 ;
F_37 ( & V_1 -> V_44 ) ;
F_37 ( & V_1 -> V_5 ) ;
F_38 ( & V_1 -> V_33 ) ;
V_1 -> V_88 = F_1 ( V_1 , V_89 ) ;
if ( F_39 ( V_1 ) > V_90 )
V_1 -> V_43 = V_78 -> V_91 ;
else
V_1 -> V_43 = - V_58 ;
if ( F_23 ( V_1 -> V_43 ) ) {
V_3 = F_40 ( V_1 -> V_43 , V_92 ,
L_12 ) ;
if ( V_3 )
goto V_93;
}
V_3 = F_41 ( V_1 ) ;
if ( V_3 )
goto V_94;
V_3 = F_42 ( V_1 -> V_83 + V_95 ,
NULL , F_15 , 0 ,
L_13 , V_1 ) ;
if ( V_3 ) {
F_22 ( V_1 -> V_37 , L_14 ,
V_3 ) ;
goto V_96;
}
F_9 ( V_1 , V_97 , V_98 ) ;
if ( V_78 -> V_99 ) {
int V_27 = V_1 -> V_83 + V_100 ;
V_81 = & V_1 -> V_101 [ V_82 ] ;
V_81 -> V_102 = L_15 ;
V_103 [ 0 ] . V_104 = V_27 ;
V_103 [ 0 ] . V_105 = V_27 ;
V_81 -> V_106 = V_103 ;
V_81 -> V_107 = F_43 ( V_103 ) ;
V_81 -> V_79 = V_78 -> V_99 ;
V_81 -> V_108 = sizeof( * V_78 -> V_99 ) ;
V_82 ++ ;
}
if ( V_78 -> V_109 ) {
int V_27 = V_1 -> V_83 + V_110 ;
V_81 = & V_1 -> V_101 [ V_82 ] ;
V_81 -> V_102 = L_16 ;
V_111 [ 0 ] . V_104 = V_27 ;
V_111 [ 0 ] . V_105 = V_27 ;
V_81 -> V_106 = V_111 ;
V_81 -> V_107 = F_43 ( V_111 ) ;
V_81 -> V_79 = V_78 -> V_109 ;
V_81 -> V_108 = sizeof( * V_78 -> V_109 ) ;
V_82 ++ ;
}
if ( V_82 ) {
V_3 = F_44 ( & V_74 -> V_37 , - 1 , V_1 -> V_101 ,
V_82 , NULL , 0 ) ;
if ( V_3 )
goto V_112;
} else {
F_22 ( & V_74 -> V_37 , L_17 ) ;
V_3 = - V_69 ;
goto V_112;
}
return 0 ;
V_112:
F_45 ( V_1 -> V_83 + V_95 , V_1 ) ;
V_96:
F_46 ( V_1 ) ;
V_94:
if ( F_23 ( V_1 -> V_43 ) )
F_47 ( V_1 -> V_43 ) ;
V_93:
F_36 ( V_74 , NULL ) ;
F_48 ( V_1 -> V_9 ) ;
V_86:
return V_3 ;
}
static int T_4 F_49 ( struct V_73 * V_74 )
{
struct V_1 * V_1 = F_50 ( V_74 ) ;
if ( V_1 -> V_45 )
F_18 ( V_1 , 0 ) ;
if ( F_23 ( V_1 -> V_43 ) )
F_47 ( V_1 -> V_43 ) ;
F_45 ( V_1 -> V_83 + V_95 , V_1 ) ;
F_46 ( V_1 ) ;
F_51 ( & V_74 -> V_37 ) ;
F_36 ( V_74 , NULL ) ;
F_48 ( V_1 -> V_9 ) ;
return 0 ;
}
