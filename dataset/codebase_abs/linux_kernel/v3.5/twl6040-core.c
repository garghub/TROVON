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
F_5 ( & V_6 -> V_10 ) ;
if ( F_6 ( V_7 == V_11 ||
V_7 == V_12 ) ) {
V_9 = V_6 -> V_13 [ F_7 ( V_7 ) ] ;
} else {
V_8 = F_8 ( V_6 -> V_14 , V_7 , & V_9 ) ;
if ( V_8 < 0 ) {
F_9 ( & V_6 -> V_10 ) ;
return V_8 ;
}
}
F_9 ( & V_6 -> V_10 ) ;
return V_9 ;
}
int F_10 ( struct V_6 * V_6 , unsigned int V_7 , T_1 V_9 )
{
int V_8 ;
F_5 ( & V_6 -> V_10 ) ;
V_8 = F_11 ( V_6 -> V_14 , V_7 , V_9 ) ;
if ( V_7 == V_11 || V_7 == V_12 )
V_6 -> V_13 [ F_7 ( V_7 ) ] = V_9 ;
F_9 ( & V_6 -> V_10 ) ;
return V_8 ;
}
int F_12 ( struct V_6 * V_6 , unsigned int V_7 , T_1 V_15 )
{
int V_8 ;
F_5 ( & V_6 -> V_10 ) ;
V_8 = F_13 ( V_6 -> V_14 , V_7 , V_15 , V_15 ) ;
F_9 ( & V_6 -> V_10 ) ;
return V_8 ;
}
int F_14 ( struct V_6 * V_6 , unsigned int V_7 , T_1 V_15 )
{
int V_8 ;
F_5 ( & V_6 -> V_10 ) ;
V_8 = F_13 ( V_6 -> V_14 , V_7 , V_15 , 0 ) ;
F_9 ( & V_6 -> V_10 ) ;
return V_8 ;
}
static int F_15 ( struct V_6 * V_6 )
{
T_1 V_16 , V_17 , V_18 ;
int V_8 ;
V_16 = V_19 | V_20 | V_21 ;
V_8 = F_10 ( V_6 , V_22 , V_16 ) ;
if ( V_8 )
return V_8 ;
F_16 ( 10000 , 10500 ) ;
V_17 = V_23 ;
V_8 = F_10 ( V_6 , V_24 , V_17 ) ;
if ( V_8 )
goto V_25;
F_16 ( 1000 , 1500 ) ;
V_16 |= V_26 ;
V_8 = F_10 ( V_6 , V_22 , V_16 ) ;
if ( V_8 )
goto V_27;
F_16 ( 1000 , 1500 ) ;
V_18 = V_28 ;
V_8 = F_10 ( V_6 , V_29 , V_18 ) ;
if ( V_8 )
goto V_30;
F_16 ( 5000 , 5500 ) ;
V_16 &= ~ V_21 ;
V_8 = F_10 ( V_6 , V_22 , V_16 ) ;
if ( V_8 )
goto V_31;
return 0 ;
V_31:
V_18 &= ~ V_28 ;
F_10 ( V_6 , V_29 , V_18 ) ;
V_30:
V_16 &= ~ V_26 ;
F_10 ( V_6 , V_22 , V_16 ) ;
V_27:
V_17 &= ~ V_23 ;
F_10 ( V_6 , V_24 , V_17 ) ;
V_25:
V_16 &= ~ ( V_19 | V_20 | V_21 ) ;
F_10 ( V_6 , V_22 , V_16 ) ;
return V_8 ;
}
static void F_17 ( struct V_6 * V_6 )
{
T_1 V_17 , V_16 , V_18 ;
V_17 = F_4 ( V_6 , V_24 ) ;
V_16 = F_4 ( V_6 , V_22 ) ;
V_18 = F_4 ( V_6 , V_29 ) ;
V_16 |= V_21 ;
F_10 ( V_6 , V_22 , V_16 ) ;
F_16 ( 1000 , 1500 ) ;
V_18 &= ~ V_28 ;
F_10 ( V_6 , V_29 , V_18 ) ;
V_16 &= ~ V_26 ;
F_10 ( V_6 , V_22 , V_16 ) ;
V_17 &= ~ V_23 ;
F_10 ( V_6 , V_24 , V_17 ) ;
V_16 &= ~ ( V_19 | V_20 | V_21 ) ;
F_10 ( V_6 , V_22 , V_16 ) ;
}
static T_2 F_18 ( int V_32 , void * V_33 )
{
struct V_6 * V_6 = V_33 ;
T_1 V_34 , V_35 ;
V_34 = F_4 ( V_6 , V_36 ) ;
if ( V_34 & V_37 )
F_19 ( & V_6 -> V_38 ) ;
if ( V_34 & V_39 ) {
V_35 = F_4 ( V_6 , V_40 ) ;
if ( V_35 & V_41 ) {
F_20 ( V_6 -> V_42 ,
L_2 ) ;
F_21 ( V_6 , 0 ) ;
} else {
F_20 ( V_6 -> V_42 ,
L_3 ) ;
F_21 ( V_6 , 1 ) ;
}
}
return V_43 ;
}
static int F_22 ( struct V_6 * V_6 ,
int V_44 )
{
int V_45 ;
T_1 V_34 ;
V_45 = F_23 ( & V_6 -> V_38 ,
F_24 ( 144 ) ) ;
if ( ! V_45 ) {
V_34 = F_4 ( V_6 , V_36 ) ;
if ( ! ( V_34 & V_37 ) ) {
F_25 ( V_6 -> V_42 ,
L_4 ) ;
return - V_46 ;
}
}
return 0 ;
}
int F_21 ( struct V_6 * V_6 , int V_47 )
{
int V_48 = V_6 -> V_48 ;
int V_44 = V_6 -> V_32 ;
int V_8 = 0 ;
F_5 ( & V_6 -> V_49 ) ;
if ( V_47 ) {
if ( V_6 -> V_50 ++ )
goto V_51;
if ( F_26 ( V_48 ) ) {
F_27 ( V_48 , 1 ) ;
V_8 = F_22 ( V_6 , V_44 ) ;
if ( V_8 ) {
F_25 ( V_6 -> V_42 ,
L_5 ) ;
V_6 -> V_50 = 0 ;
goto V_51;
}
} else {
V_8 = F_15 ( V_6 ) ;
if ( V_8 ) {
F_25 ( V_6 -> V_42 ,
L_6 ) ;
V_6 -> V_50 = 0 ;
goto V_51;
}
}
V_6 -> V_52 = V_53 ;
V_6 -> V_54 = 19200000 ;
V_6 -> V_55 = 32768 ;
} else {
if ( ! V_6 -> V_50 ) {
F_25 ( V_6 -> V_42 ,
L_7 ) ;
V_8 = - V_56 ;
goto V_51;
}
if ( -- V_6 -> V_50 )
goto V_51;
if ( F_26 ( V_48 ) ) {
F_27 ( V_48 , 0 ) ;
F_16 ( 500 , 700 ) ;
} else {
F_17 ( V_6 ) ;
}
V_6 -> V_54 = 0 ;
V_6 -> V_55 = 0 ;
}
V_51:
F_9 ( & V_6 -> V_49 ) ;
return V_8 ;
}
int F_28 ( struct V_6 * V_6 , int V_57 ,
unsigned int V_58 , unsigned int V_59 )
{
T_1 V_60 , V_18 ;
int V_8 = 0 ;
F_5 ( & V_6 -> V_49 ) ;
V_60 = F_4 ( V_6 , V_61 ) ;
V_18 = F_4 ( V_6 , V_29 ) ;
if ( V_57 != V_6 -> V_52 ) {
V_6 -> V_54 = 0 ;
V_6 -> V_55 = 0 ;
}
switch ( V_57 ) {
case V_53 :
if ( V_6 -> V_54 != V_59 ) {
switch ( V_59 ) {
case 17640000 :
V_18 |= V_62 ;
break;
case 19200000 :
V_18 &= ~ V_62 ;
break;
default:
F_25 ( V_6 -> V_42 ,
L_8 ,
V_59 ) ;
V_8 = - V_63 ;
goto V_64;
}
F_10 ( V_6 , V_29 ,
V_18 ) ;
}
if ( V_6 -> V_52 == V_57 )
break;
switch ( V_58 ) {
case 32768 :
V_18 |= V_28 ;
F_10 ( V_6 , V_29 ,
V_18 ) ;
F_29 ( 5 ) ;
V_18 &= ~ V_65 ;
F_10 ( V_6 , V_29 ,
V_18 ) ;
V_60 &= ~ V_66 ;
F_10 ( V_6 , V_61 ,
V_60 ) ;
break;
default:
F_25 ( V_6 -> V_42 ,
L_9 , V_58 ) ;
V_8 = - V_63 ;
goto V_64;
}
break;
case V_67 :
if ( V_59 != 19200000 ) {
F_25 ( V_6 -> V_42 ,
L_8 , V_59 ) ;
V_8 = - V_63 ;
goto V_64;
}
if ( V_6 -> V_55 != V_58 ) {
V_60 &= ~ V_68 ;
switch ( V_58 ) {
case 12000000 :
V_60 |= V_69 |
V_66 ;
break;
case 19200000 :
V_60 |= V_70 ;
break;
case 26000000 :
V_60 |= V_71 |
V_66 ;
break;
case 38400000 :
V_60 |= V_72 |
V_66 ;
break;
default:
F_25 ( V_6 -> V_42 ,
L_9 , V_58 ) ;
V_8 = - V_63 ;
goto V_64;
}
V_60 |= V_73 ;
F_10 ( V_6 , V_61 ,
V_60 ) ;
F_16 ( 500 , 700 ) ;
V_18 |= V_65 ;
F_10 ( V_6 , V_29 ,
V_18 ) ;
V_18 &= ~ V_28 ;
F_10 ( V_6 , V_29 ,
V_18 ) ;
}
break;
default:
F_25 ( V_6 -> V_42 , L_10 , V_57 ) ;
V_8 = - V_63 ;
goto V_64;
}
V_6 -> V_54 = V_59 ;
V_6 -> V_55 = V_58 ;
V_6 -> V_52 = V_57 ;
V_64:
F_9 ( & V_6 -> V_49 ) ;
return V_8 ;
}
int F_30 ( struct V_6 * V_6 )
{
if ( V_6 -> V_50 )
return V_6 -> V_52 ;
else
return - V_74 ;
}
unsigned int F_31 ( struct V_6 * V_6 )
{
return V_6 -> V_54 ;
}
int F_32 ( struct V_6 * V_6 )
{
T_1 V_35 ;
V_35 = V_6 -> V_13 [ 0 ] | V_6 -> V_13 [ 1 ] ;
V_35 &= ( V_75 | V_76 ) ;
return V_35 ;
}
static bool F_33 ( struct V_77 * V_42 , unsigned int V_7 )
{
if ( ! V_7 )
return false ;
return true ;
}
static int T_3 F_34 ( struct V_78 * V_79 ,
const struct V_80 * V_81 )
{
struct V_1 * V_2 = V_79 -> V_42 . V_82 ;
struct V_3 * V_4 = V_79 -> V_42 . V_83 ;
struct V_6 * V_6 ;
struct V_84 * V_85 = NULL ;
int V_32 , V_8 , V_86 = 0 ;
if ( ! V_2 && ! V_4 ) {
F_25 ( & V_79 -> V_42 , L_11 ) ;
return - V_63 ;
}
if ( ! V_79 -> V_32 ) {
F_25 ( & V_79 -> V_42 , L_12 ) ;
return - V_63 ;
}
V_6 = F_35 ( & V_79 -> V_42 , sizeof( struct V_6 ) ,
V_87 ) ;
if ( ! V_6 ) {
V_8 = - V_88 ;
goto V_89;
}
V_6 -> V_14 = F_36 ( V_79 , & V_90 ) ;
if ( F_37 ( V_6 -> V_14 ) ) {
V_8 = F_38 ( V_6 -> V_14 ) ;
goto V_89;
}
F_39 ( V_79 , V_6 ) ;
V_6 -> V_91 [ 0 ] . V_92 = L_13 ;
V_6 -> V_91 [ 1 ] . V_92 = L_14 ;
V_8 = F_40 ( & V_79 -> V_42 , V_93 ,
V_6 -> V_91 ) ;
if ( V_8 != 0 ) {
F_25 ( & V_79 -> V_42 , L_15 , V_8 ) ;
goto V_94;
}
V_8 = F_41 ( V_93 , V_6 -> V_91 ) ;
if ( V_8 != 0 ) {
F_25 ( & V_79 -> V_42 , L_16 , V_8 ) ;
goto V_95;
}
V_6 -> V_42 = & V_79 -> V_42 ;
V_6 -> V_32 = V_79 -> V_32 ;
F_42 ( & V_6 -> V_49 ) ;
F_42 ( & V_6 -> V_10 ) ;
F_43 ( & V_6 -> V_38 ) ;
V_6 -> V_96 = F_4 ( V_6 , V_97 ) ;
if ( F_44 ( V_6 ) > V_98 ) {
if ( V_2 )
V_6 -> V_48 = V_2 -> V_99 ;
else
V_6 -> V_48 = F_45 ( V_4 ,
L_17 , 0 ) ;
} else
V_6 -> V_48 = - V_63 ;
if ( F_26 ( V_6 -> V_48 ) ) {
V_8 = F_46 ( V_6 -> V_48 , V_100 ,
L_18 ) ;
if ( V_8 )
goto V_101;
}
V_8 = F_47 ( V_6 ) ;
if ( V_8 )
goto V_102;
V_8 = F_48 ( V_6 -> V_103 + V_104 ,
NULL , F_18 , 0 ,
L_19 , V_6 ) ;
if ( V_8 ) {
F_25 ( V_6 -> V_42 , L_20 ,
V_8 ) ;
goto V_105;
}
F_12 ( V_6 , V_106 , V_107 ) ;
V_32 = V_6 -> V_103 + V_108 ;
V_85 = & V_6 -> V_109 [ V_86 ] ;
V_85 -> V_110 = L_21 ;
V_111 [ 0 ] . V_112 = V_32 ;
V_111 [ 0 ] . V_113 = V_32 ;
V_85 -> V_114 = V_111 ;
V_85 -> V_115 = F_49 ( V_111 ) ;
if ( V_2 && V_2 -> V_116 ) {
V_85 -> V_82 = V_2 -> V_116 ;
V_85 -> V_117 = sizeof( * V_2 -> V_116 ) ;
}
V_86 ++ ;
if ( F_1 ( V_2 , V_4 ) ) {
V_32 = V_6 -> V_103 + V_118 ;
V_85 = & V_6 -> V_109 [ V_86 ] ;
V_85 -> V_110 = L_22 ;
V_119 [ 0 ] . V_112 = V_32 ;
V_119 [ 0 ] . V_113 = V_32 ;
V_85 -> V_114 = V_119 ;
V_85 -> V_115 = F_49 ( V_119 ) ;
if ( V_2 && V_2 -> V_5 ) {
V_85 -> V_82 = V_2 -> V_5 ;
V_85 -> V_117 = sizeof( * V_2 -> V_5 ) ;
}
V_86 ++ ;
}
V_8 = F_50 ( & V_79 -> V_42 , - 1 , V_6 -> V_109 , V_86 ,
NULL , 0 ) ;
if ( V_8 )
goto V_120;
return 0 ;
V_120:
F_51 ( V_6 -> V_103 + V_104 , V_6 ) ;
V_105:
F_52 ( V_6 ) ;
V_102:
if ( F_26 ( V_6 -> V_48 ) )
F_53 ( V_6 -> V_48 ) ;
V_101:
F_54 ( V_93 , V_6 -> V_91 ) ;
V_95:
F_55 ( V_93 , V_6 -> V_91 ) ;
V_94:
F_39 ( V_79 , NULL ) ;
V_89:
return V_8 ;
}
static int T_4 F_56 ( struct V_78 * V_79 )
{
struct V_6 * V_6 = F_57 ( V_79 ) ;
if ( V_6 -> V_50 )
F_21 ( V_6 , 0 ) ;
if ( F_26 ( V_6 -> V_48 ) )
F_53 ( V_6 -> V_48 ) ;
F_51 ( V_6 -> V_103 + V_104 , V_6 ) ;
F_52 ( V_6 ) ;
F_58 ( & V_79 -> V_42 ) ;
F_39 ( V_79 , NULL ) ;
F_54 ( V_93 , V_6 -> V_91 ) ;
F_55 ( V_93 , V_6 -> V_91 ) ;
return 0 ;
}
