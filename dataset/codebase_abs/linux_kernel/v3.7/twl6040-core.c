static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 && V_2 -> V_5 )
return true ;
#ifdef F_2
if ( F_3 ( V_4 , L_1 ) )
return true ;
#endif
return false ;
}
int F_4 ( struct V_6 * V_6 , unsigned int V_7 )
{
int V_8 ;
unsigned int V_9 ;
if ( F_5 ( V_7 == V_10 ||
V_7 == V_11 ) ) {
V_9 = V_6 -> V_12 [ F_6 ( V_7 ) ] ;
} else {
V_8 = F_7 ( V_6 -> V_13 , V_7 , & V_9 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return V_9 ;
}
int F_8 ( struct V_6 * V_6 , unsigned int V_7 , T_1 V_9 )
{
int V_8 ;
V_8 = F_9 ( V_6 -> V_13 , V_7 , V_9 ) ;
if ( V_7 == V_10 || V_7 == V_11 )
V_6 -> V_12 [ F_6 ( V_7 ) ] = V_9 ;
return V_8 ;
}
int F_10 ( struct V_6 * V_6 , unsigned int V_7 , T_1 V_14 )
{
return F_11 ( V_6 -> V_13 , V_7 , V_14 , V_14 ) ;
}
int F_12 ( struct V_6 * V_6 , unsigned int V_7 , T_1 V_14 )
{
return F_11 ( V_6 -> V_13 , V_7 , V_14 , 0 ) ;
}
static int F_13 ( struct V_6 * V_6 )
{
T_1 V_15 , V_16 , V_17 ;
int V_8 ;
V_15 = V_18 | V_19 | V_20 ;
V_8 = F_8 ( V_6 , V_21 , V_15 ) ;
if ( V_8 )
return V_8 ;
F_14 ( 10000 , 10500 ) ;
V_16 = V_22 ;
V_8 = F_8 ( V_6 , V_23 , V_16 ) ;
if ( V_8 )
goto V_24;
F_14 ( 1000 , 1500 ) ;
V_15 |= V_25 ;
V_8 = F_8 ( V_6 , V_21 , V_15 ) ;
if ( V_8 )
goto V_26;
F_14 ( 1000 , 1500 ) ;
V_17 = V_27 ;
V_8 = F_8 ( V_6 , V_28 , V_17 ) ;
if ( V_8 )
goto V_29;
F_14 ( 5000 , 5500 ) ;
V_15 &= ~ V_20 ;
V_8 = F_8 ( V_6 , V_21 , V_15 ) ;
if ( V_8 )
goto V_30;
return 0 ;
V_30:
V_17 &= ~ V_27 ;
F_8 ( V_6 , V_28 , V_17 ) ;
V_29:
V_15 &= ~ V_25 ;
F_8 ( V_6 , V_21 , V_15 ) ;
V_26:
V_16 &= ~ V_22 ;
F_8 ( V_6 , V_23 , V_16 ) ;
V_24:
V_15 &= ~ ( V_18 | V_19 | V_20 ) ;
F_8 ( V_6 , V_21 , V_15 ) ;
return V_8 ;
}
static void F_15 ( struct V_6 * V_6 )
{
T_1 V_16 , V_15 , V_17 ;
V_16 = F_4 ( V_6 , V_23 ) ;
V_15 = F_4 ( V_6 , V_21 ) ;
V_17 = F_4 ( V_6 , V_28 ) ;
V_15 |= V_20 ;
F_8 ( V_6 , V_21 , V_15 ) ;
F_14 ( 1000 , 1500 ) ;
V_17 &= ~ V_27 ;
F_8 ( V_6 , V_28 , V_17 ) ;
V_15 &= ~ V_25 ;
F_8 ( V_6 , V_21 , V_15 ) ;
V_16 &= ~ V_22 ;
F_8 ( V_6 , V_23 , V_16 ) ;
V_15 &= ~ ( V_18 | V_19 | V_20 ) ;
F_8 ( V_6 , V_21 , V_15 ) ;
}
static T_2 F_16 ( int V_31 , void * V_32 )
{
struct V_6 * V_6 = V_32 ;
T_1 V_33 , V_34 ;
V_33 = F_4 ( V_6 , V_35 ) ;
if ( V_33 & V_36 )
F_17 ( & V_6 -> V_37 ) ;
if ( V_33 & V_38 ) {
V_34 = F_4 ( V_6 , V_39 ) ;
if ( V_34 & V_40 ) {
F_18 ( V_6 -> V_41 ,
L_2 ) ;
F_19 ( V_6 , 0 ) ;
} else {
F_18 ( V_6 -> V_41 ,
L_3 ) ;
F_19 ( V_6 , 1 ) ;
}
}
return V_42 ;
}
static int F_20 ( struct V_6 * V_6 ,
int V_43 )
{
int V_44 ;
T_1 V_33 ;
V_44 = F_21 ( & V_6 -> V_37 ,
F_22 ( 144 ) ) ;
if ( ! V_44 ) {
V_33 = F_4 ( V_6 , V_35 ) ;
if ( ! ( V_33 & V_36 ) ) {
F_23 ( V_6 -> V_41 ,
L_4 ) ;
return - V_45 ;
}
}
return 0 ;
}
int F_19 ( struct V_6 * V_6 , int V_46 )
{
int V_47 = V_6 -> V_47 ;
int V_43 = V_6 -> V_31 ;
int V_8 = 0 ;
F_24 ( & V_6 -> V_48 ) ;
if ( V_46 ) {
if ( V_6 -> V_49 ++ )
goto V_50;
if ( F_25 ( V_47 ) ) {
F_26 ( V_47 , 1 ) ;
V_8 = F_20 ( V_6 , V_43 ) ;
if ( V_8 ) {
F_23 ( V_6 -> V_41 ,
L_5 ) ;
V_6 -> V_49 = 0 ;
goto V_50;
}
} else {
V_8 = F_13 ( V_6 ) ;
if ( V_8 ) {
F_23 ( V_6 -> V_41 ,
L_6 ) ;
V_6 -> V_49 = 0 ;
goto V_50;
}
}
V_6 -> V_51 = V_52 ;
V_6 -> V_53 = 19200000 ;
V_6 -> V_54 = 32768 ;
} else {
if ( ! V_6 -> V_49 ) {
F_23 ( V_6 -> V_41 ,
L_7 ) ;
V_8 = - V_55 ;
goto V_50;
}
if ( -- V_6 -> V_49 )
goto V_50;
if ( F_25 ( V_47 ) ) {
F_26 ( V_47 , 0 ) ;
F_14 ( 500 , 700 ) ;
} else {
F_15 ( V_6 ) ;
}
V_6 -> V_53 = 0 ;
V_6 -> V_54 = 0 ;
}
V_50:
F_27 ( & V_6 -> V_48 ) ;
return V_8 ;
}
int F_28 ( struct V_6 * V_6 , int V_56 ,
unsigned int V_57 , unsigned int V_58 )
{
T_1 V_59 , V_17 ;
int V_8 = 0 ;
F_24 ( & V_6 -> V_48 ) ;
V_59 = F_4 ( V_6 , V_60 ) ;
V_17 = F_4 ( V_6 , V_28 ) ;
if ( V_56 != V_6 -> V_51 ) {
V_6 -> V_53 = 0 ;
V_6 -> V_54 = 0 ;
}
switch ( V_56 ) {
case V_52 :
if ( V_6 -> V_53 != V_58 ) {
switch ( V_58 ) {
case 17640000 :
V_17 |= V_61 ;
break;
case 19200000 :
V_17 &= ~ V_61 ;
break;
default:
F_23 ( V_6 -> V_41 ,
L_8 ,
V_58 ) ;
V_8 = - V_62 ;
goto V_63;
}
F_8 ( V_6 , V_28 ,
V_17 ) ;
}
if ( V_6 -> V_51 == V_56 )
break;
switch ( V_57 ) {
case 32768 :
V_17 |= V_27 ;
F_8 ( V_6 , V_28 ,
V_17 ) ;
F_29 ( 5 ) ;
V_17 &= ~ V_64 ;
F_8 ( V_6 , V_28 ,
V_17 ) ;
V_59 &= ~ V_65 ;
F_8 ( V_6 , V_60 ,
V_59 ) ;
break;
default:
F_23 ( V_6 -> V_41 ,
L_9 , V_57 ) ;
V_8 = - V_62 ;
goto V_63;
}
break;
case V_66 :
if ( V_58 != 19200000 ) {
F_23 ( V_6 -> V_41 ,
L_8 , V_58 ) ;
V_8 = - V_62 ;
goto V_63;
}
if ( V_6 -> V_54 != V_57 ) {
V_59 &= ~ V_67 ;
switch ( V_57 ) {
case 12000000 :
V_59 |= V_68 |
V_65 ;
break;
case 19200000 :
V_59 |= V_69 ;
break;
case 26000000 :
V_59 |= V_70 |
V_65 ;
break;
case 38400000 :
V_59 |= V_71 |
V_65 ;
break;
default:
F_23 ( V_6 -> V_41 ,
L_9 , V_57 ) ;
V_8 = - V_62 ;
goto V_63;
}
V_59 |= V_72 ;
F_8 ( V_6 , V_60 ,
V_59 ) ;
F_14 ( 500 , 700 ) ;
V_17 |= V_64 ;
F_8 ( V_6 , V_28 ,
V_17 ) ;
V_17 &= ~ V_27 ;
F_8 ( V_6 , V_28 ,
V_17 ) ;
}
break;
default:
F_23 ( V_6 -> V_41 , L_10 , V_56 ) ;
V_8 = - V_62 ;
goto V_63;
}
V_6 -> V_53 = V_58 ;
V_6 -> V_54 = V_57 ;
V_6 -> V_51 = V_56 ;
V_63:
F_27 ( & V_6 -> V_48 ) ;
return V_8 ;
}
int F_30 ( struct V_6 * V_6 )
{
if ( V_6 -> V_49 )
return V_6 -> V_51 ;
else
return - V_73 ;
}
unsigned int F_31 ( struct V_6 * V_6 )
{
return V_6 -> V_53 ;
}
int F_32 ( struct V_6 * V_6 )
{
T_1 V_34 ;
V_34 = V_6 -> V_12 [ 0 ] | V_6 -> V_12 [ 1 ] ;
V_34 &= ( V_74 | V_75 ) ;
return V_34 ;
}
static bool F_33 ( struct V_76 * V_41 , unsigned int V_7 )
{
if ( ! V_7 )
return false ;
return true ;
}
static int T_3 F_34 ( struct V_77 * V_78 ,
const struct V_79 * V_80 )
{
struct V_1 * V_2 = V_78 -> V_41 . V_81 ;
struct V_3 * V_4 = V_78 -> V_41 . V_82 ;
struct V_6 * V_6 ;
struct V_83 * V_84 = NULL ;
int V_31 , V_8 , V_85 = 0 ;
if ( ! V_2 && ! V_4 ) {
F_23 ( & V_78 -> V_41 , L_11 ) ;
return - V_62 ;
}
if ( ! V_78 -> V_31 ) {
F_23 ( & V_78 -> V_41 , L_12 ) ;
return - V_62 ;
}
V_6 = F_35 ( & V_78 -> V_41 , sizeof( struct V_6 ) ,
V_86 ) ;
if ( ! V_6 ) {
V_8 = - V_87 ;
goto V_88;
}
V_6 -> V_13 = F_36 ( V_78 , & V_89 ) ;
if ( F_37 ( V_6 -> V_13 ) ) {
V_8 = F_38 ( V_6 -> V_13 ) ;
goto V_88;
}
F_39 ( V_78 , V_6 ) ;
V_6 -> V_90 [ 0 ] . V_91 = L_13 ;
V_6 -> V_90 [ 1 ] . V_91 = L_14 ;
V_8 = F_40 ( & V_78 -> V_41 , V_92 ,
V_6 -> V_90 ) ;
if ( V_8 != 0 ) {
F_23 ( & V_78 -> V_41 , L_15 , V_8 ) ;
goto V_93;
}
V_8 = F_41 ( V_92 , V_6 -> V_90 ) ;
if ( V_8 != 0 ) {
F_23 ( & V_78 -> V_41 , L_16 , V_8 ) ;
goto V_94;
}
V_6 -> V_41 = & V_78 -> V_41 ;
V_6 -> V_31 = V_78 -> V_31 ;
F_42 ( & V_6 -> V_48 ) ;
F_43 ( & V_6 -> V_37 ) ;
V_6 -> V_95 = F_4 ( V_6 , V_96 ) ;
if ( F_44 ( V_6 ) > V_97 ) {
if ( V_2 )
V_6 -> V_47 = V_2 -> V_98 ;
else
V_6 -> V_47 = F_45 ( V_4 ,
L_17 , 0 ) ;
} else
V_6 -> V_47 = - V_62 ;
if ( F_25 ( V_6 -> V_47 ) ) {
V_8 = F_46 ( V_6 -> V_47 , V_99 ,
L_18 ) ;
if ( V_8 )
goto V_100;
}
V_8 = F_47 ( V_6 ) ;
if ( V_8 )
goto V_101;
V_8 = F_48 ( V_6 -> V_102 + V_103 ,
NULL , F_16 , V_104 ,
L_19 , V_6 ) ;
if ( V_8 ) {
F_23 ( V_6 -> V_41 , L_20 ,
V_8 ) ;
goto V_105;
}
F_10 ( V_6 , V_106 , V_107 ) ;
V_31 = V_6 -> V_102 + V_108 ;
V_84 = & V_6 -> V_109 [ V_85 ] ;
V_84 -> V_110 = L_21 ;
V_111 [ 0 ] . V_112 = V_31 ;
V_111 [ 0 ] . V_113 = V_31 ;
V_84 -> V_114 = V_111 ;
V_84 -> V_115 = F_49 ( V_111 ) ;
if ( V_2 && V_2 -> V_116 ) {
V_84 -> V_81 = V_2 -> V_116 ;
V_84 -> V_117 = sizeof( * V_2 -> V_116 ) ;
}
V_85 ++ ;
if ( F_1 ( V_2 , V_4 ) ) {
V_31 = V_6 -> V_102 + V_118 ;
V_84 = & V_6 -> V_109 [ V_85 ] ;
V_84 -> V_110 = L_22 ;
V_119 [ 0 ] . V_112 = V_31 ;
V_119 [ 0 ] . V_113 = V_31 ;
V_84 -> V_114 = V_119 ;
V_84 -> V_115 = F_49 ( V_119 ) ;
if ( V_2 && V_2 -> V_5 ) {
V_84 -> V_81 = V_2 -> V_5 ;
V_84 -> V_117 = sizeof( * V_2 -> V_5 ) ;
}
V_85 ++ ;
}
if ( ! V_2 || ( V_2 && V_2 -> V_120 ) ) {
V_84 = & V_6 -> V_109 [ V_85 ] ;
V_84 -> V_110 = L_23 ;
if ( V_2 ) {
V_84 -> V_81 = V_2 -> V_120 ;
V_84 -> V_117 = sizeof( * V_2 -> V_120 ) ;
}
V_85 ++ ;
}
V_8 = F_50 ( & V_78 -> V_41 , - 1 , V_6 -> V_109 , V_85 ,
NULL , 0 , NULL ) ;
if ( V_8 )
goto V_121;
return 0 ;
V_121:
F_51 ( V_6 -> V_102 + V_103 , V_6 ) ;
V_105:
F_52 ( V_6 ) ;
V_101:
if ( F_25 ( V_6 -> V_47 ) )
F_53 ( V_6 -> V_47 ) ;
V_100:
F_54 ( V_92 , V_6 -> V_90 ) ;
V_94:
F_55 ( V_92 , V_6 -> V_90 ) ;
V_93:
F_39 ( V_78 , NULL ) ;
V_88:
return V_8 ;
}
static int T_4 F_56 ( struct V_77 * V_78 )
{
struct V_6 * V_6 = F_57 ( V_78 ) ;
if ( V_6 -> V_49 )
F_19 ( V_6 , 0 ) ;
if ( F_25 ( V_6 -> V_47 ) )
F_53 ( V_6 -> V_47 ) ;
F_51 ( V_6 -> V_102 + V_103 , V_6 ) ;
F_52 ( V_6 ) ;
F_58 ( & V_78 -> V_41 ) ;
F_39 ( V_78 , NULL ) ;
F_54 ( V_92 , V_6 -> V_90 ) ;
F_55 ( V_92 , V_6 -> V_90 ) ;
return 0 ;
}
