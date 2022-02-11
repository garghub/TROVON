int F_1 ( struct V_1 * V_1 , unsigned int V_2 )
{
int V_3 ;
T_1 V_4 = 0 ;
F_2 ( & V_1 -> V_5 ) ;
if ( F_3 ( V_2 == V_6 ||
V_2 == V_7 ) ) {
V_4 = V_1 -> V_8 [ F_4 ( V_2 ) ] ;
} else {
V_3 = F_5 ( V_9 , & V_4 , V_2 ) ;
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
V_3 = F_8 ( V_9 , V_4 , V_2 ) ;
if ( V_2 == V_6 || V_2 == V_7 )
V_1 -> V_8 [ F_4 ( V_2 ) ] = V_4 ;
F_6 ( & V_1 -> V_5 ) ;
return V_3 ;
}
int F_9 ( struct V_1 * V_1 , unsigned int V_2 , T_1 V_10 )
{
int V_3 ;
T_1 V_4 ;
F_2 ( & V_1 -> V_5 ) ;
V_3 = F_5 ( V_9 , & V_4 , V_2 ) ;
if ( V_3 )
goto V_11;
V_4 |= V_10 ;
V_3 = F_8 ( V_9 , V_4 , V_2 ) ;
V_11:
F_6 ( & V_1 -> V_5 ) ;
return V_3 ;
}
int F_10 ( struct V_1 * V_1 , unsigned int V_2 , T_1 V_10 )
{
int V_3 ;
T_1 V_4 ;
F_2 ( & V_1 -> V_5 ) ;
V_3 = F_5 ( V_9 , & V_4 , V_2 ) ;
if ( V_3 )
goto V_11;
V_4 &= ~ V_10 ;
V_3 = F_8 ( V_9 , V_4 , V_2 ) ;
V_11:
F_6 ( & V_1 -> V_5 ) ;
return V_3 ;
}
static int F_11 ( struct V_1 * V_1 )
{
T_1 V_12 , V_13 , V_14 ;
int V_3 ;
V_12 = V_15 | V_16 | V_17 ;
V_3 = F_7 ( V_1 , V_18 , V_12 ) ;
if ( V_3 )
return V_3 ;
F_12 ( 10000 , 10500 ) ;
V_13 = V_19 ;
V_3 = F_7 ( V_1 , V_20 , V_13 ) ;
if ( V_3 )
goto V_21;
F_12 ( 1000 , 1500 ) ;
V_12 |= V_22 ;
V_3 = F_7 ( V_1 , V_18 , V_12 ) ;
if ( V_3 )
goto V_23;
F_12 ( 1000 , 1500 ) ;
V_14 = V_24 ;
V_3 = F_7 ( V_1 , V_25 , V_14 ) ;
if ( V_3 )
goto V_26;
F_12 ( 5000 , 5500 ) ;
V_12 &= ~ V_17 ;
V_3 = F_7 ( V_1 , V_18 , V_12 ) ;
if ( V_3 )
goto V_27;
return 0 ;
V_27:
V_14 &= ~ V_24 ;
F_7 ( V_1 , V_25 , V_14 ) ;
V_26:
V_12 &= ~ V_22 ;
F_7 ( V_1 , V_18 , V_12 ) ;
V_23:
V_13 &= ~ V_19 ;
F_7 ( V_1 , V_20 , V_13 ) ;
V_21:
V_12 &= ~ ( V_15 | V_16 | V_17 ) ;
F_7 ( V_1 , V_18 , V_12 ) ;
return V_3 ;
}
static void F_13 ( struct V_1 * V_1 )
{
T_1 V_13 , V_12 , V_14 ;
V_13 = F_1 ( V_1 , V_20 ) ;
V_12 = F_1 ( V_1 , V_18 ) ;
V_14 = F_1 ( V_1 , V_25 ) ;
V_12 |= V_17 ;
F_7 ( V_1 , V_18 , V_12 ) ;
F_12 ( 1000 , 1500 ) ;
V_14 &= ~ V_24 ;
F_7 ( V_1 , V_25 , V_14 ) ;
V_12 &= ~ V_22 ;
F_7 ( V_1 , V_18 , V_12 ) ;
V_13 &= ~ V_19 ;
F_7 ( V_1 , V_20 , V_13 ) ;
V_12 &= ~ ( V_15 | V_16 | V_17 ) ;
F_7 ( V_1 , V_18 , V_12 ) ;
}
static T_2 F_14 ( int V_28 , void * V_29 )
{
struct V_1 * V_1 = V_29 ;
T_1 V_30 , V_31 ;
V_30 = F_1 ( V_1 , V_32 ) ;
if ( V_30 & V_33 )
F_15 ( & V_1 -> V_34 ) ;
if ( V_30 & V_35 ) {
V_31 = F_1 ( V_1 , V_36 ) ;
if ( V_31 & V_37 ) {
F_16 ( V_1 -> V_38 ,
L_1 ) ;
F_17 ( V_1 , 0 ) ;
} else {
F_16 ( V_1 -> V_38 ,
L_2 ) ;
F_17 ( V_1 , 1 ) ;
}
}
return V_39 ;
}
static int F_18 ( struct V_1 * V_1 ,
int V_40 )
{
int V_41 ;
T_1 V_30 ;
V_41 = F_19 ( & V_1 -> V_34 ,
F_20 ( 144 ) ) ;
if ( ! V_41 ) {
V_30 = F_1 ( V_1 , V_32 ) ;
if ( ! ( V_30 & V_33 ) ) {
F_21 ( V_1 -> V_38 ,
L_3 ) ;
return - V_42 ;
}
}
return 0 ;
}
int F_17 ( struct V_1 * V_1 , int V_43 )
{
int V_44 = V_1 -> V_44 ;
int V_40 = V_1 -> V_28 ;
int V_3 = 0 ;
F_2 ( & V_1 -> V_45 ) ;
if ( V_43 ) {
if ( V_1 -> V_46 ++ )
goto V_11;
if ( F_22 ( V_44 ) ) {
F_23 ( V_44 , 1 ) ;
V_3 = F_18 ( V_1 , V_40 ) ;
if ( V_3 ) {
F_21 ( V_1 -> V_38 ,
L_4 ) ;
V_1 -> V_46 = 0 ;
goto V_11;
}
} else {
V_3 = F_11 ( V_1 ) ;
if ( V_3 ) {
F_21 ( V_1 -> V_38 ,
L_5 ) ;
V_1 -> V_46 = 0 ;
goto V_11;
}
}
V_1 -> V_47 = V_48 ;
V_1 -> V_49 = 19200000 ;
V_1 -> V_50 = 32768 ;
} else {
if ( ! V_1 -> V_46 ) {
F_21 ( V_1 -> V_38 ,
L_6 ) ;
V_3 = - V_51 ;
goto V_11;
}
if ( -- V_1 -> V_46 )
goto V_11;
if ( F_22 ( V_44 ) ) {
F_23 ( V_44 , 0 ) ;
F_12 ( 500 , 700 ) ;
} else {
F_13 ( V_1 ) ;
}
V_1 -> V_49 = 0 ;
V_1 -> V_50 = 0 ;
}
V_11:
F_6 ( & V_1 -> V_45 ) ;
return V_3 ;
}
int F_24 ( struct V_1 * V_1 , int V_52 ,
unsigned int V_53 , unsigned int V_54 )
{
T_1 V_55 , V_14 ;
int V_3 = 0 ;
F_2 ( & V_1 -> V_45 ) ;
V_55 = F_1 ( V_1 , V_56 ) ;
V_14 = F_1 ( V_1 , V_25 ) ;
if ( V_52 != V_1 -> V_47 ) {
V_1 -> V_49 = 0 ;
V_1 -> V_50 = 0 ;
}
switch ( V_52 ) {
case V_48 :
if ( V_1 -> V_49 != V_54 ) {
switch ( V_54 ) {
case 17640000 :
V_14 |= V_57 ;
break;
case 19200000 :
V_14 &= ~ V_57 ;
break;
default:
F_21 ( V_1 -> V_38 ,
L_7 ,
V_54 ) ;
V_3 = - V_58 ;
goto V_59;
}
F_7 ( V_1 , V_25 ,
V_14 ) ;
}
if ( V_1 -> V_47 == V_52 )
break;
switch ( V_53 ) {
case 32768 :
V_14 |= V_24 ;
F_7 ( V_1 , V_25 ,
V_14 ) ;
F_25 ( 5 ) ;
V_14 &= ~ V_60 ;
F_7 ( V_1 , V_25 ,
V_14 ) ;
V_55 &= ~ V_61 ;
F_7 ( V_1 , V_56 ,
V_55 ) ;
break;
default:
F_21 ( V_1 -> V_38 ,
L_8 , V_53 ) ;
V_3 = - V_58 ;
goto V_59;
}
break;
case V_62 :
if ( V_54 != 19200000 ) {
F_21 ( V_1 -> V_38 ,
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
F_21 ( V_1 -> V_38 ,
L_8 , V_53 ) ;
V_3 = - V_58 ;
goto V_59;
}
V_55 |= V_68 ;
F_7 ( V_1 , V_56 ,
V_55 ) ;
F_12 ( 500 , 700 ) ;
V_14 |= V_60 ;
F_7 ( V_1 , V_25 ,
V_14 ) ;
V_14 &= ~ V_24 ;
F_7 ( V_1 , V_25 ,
V_14 ) ;
}
break;
default:
F_21 ( V_1 -> V_38 , L_9 , V_52 ) ;
V_3 = - V_58 ;
goto V_59;
}
V_1 -> V_49 = V_54 ;
V_1 -> V_50 = V_53 ;
V_1 -> V_47 = V_52 ;
V_59:
F_6 ( & V_1 -> V_45 ) ;
return V_3 ;
}
int F_26 ( struct V_1 * V_1 )
{
if ( V_1 -> V_46 )
return V_1 -> V_47 ;
else
return - V_69 ;
}
unsigned int F_27 ( struct V_1 * V_1 )
{
return V_1 -> V_49 ;
}
int F_28 ( struct V_1 * V_1 )
{
T_1 V_31 ;
V_31 = V_1 -> V_8 [ 0 ] | V_1 -> V_8 [ 1 ] ;
V_31 &= ( V_70 | V_71 ) ;
return V_31 ;
}
static int T_3 F_29 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = V_73 -> V_38 . V_76 ;
struct V_1 * V_1 ;
struct V_77 * V_78 = NULL ;
int V_3 , V_79 = 0 ;
if ( ! V_75 ) {
F_21 ( & V_73 -> V_38 , L_10 ) ;
return - V_58 ;
}
if ( ! V_75 -> V_80 || ! V_75 -> V_81 ) {
F_21 ( & V_73 -> V_38 , L_11 ) ;
return - V_58 ;
}
V_1 = F_30 ( sizeof( struct V_1 ) , V_82 ) ;
if ( ! V_1 )
return - V_83 ;
F_31 ( V_73 , V_1 ) ;
V_1 -> V_38 = & V_73 -> V_38 ;
V_1 -> V_28 = V_75 -> V_80 ;
V_1 -> V_81 = V_75 -> V_81 ;
F_32 ( & V_1 -> V_45 ) ;
F_32 ( & V_1 -> V_5 ) ;
F_33 ( & V_1 -> V_34 ) ;
V_1 -> V_84 = F_1 ( V_1 , V_85 ) ;
if ( F_34 ( V_1 ) > V_86 )
V_1 -> V_44 = V_75 -> V_87 ;
else
V_1 -> V_44 = - V_58 ;
if ( F_22 ( V_1 -> V_44 ) ) {
V_3 = F_35 ( V_1 -> V_44 , V_88 ,
L_12 ) ;
if ( V_3 )
goto V_89;
}
V_3 = F_36 ( V_1 ) ;
if ( V_3 )
goto V_90;
V_3 = F_37 ( V_1 -> V_81 + V_91 ,
NULL , F_14 , 0 ,
L_13 , V_1 ) ;
if ( V_3 ) {
F_21 ( V_1 -> V_38 , L_14 ,
V_3 ) ;
goto V_92;
}
F_9 ( V_1 , V_93 , V_94 ) ;
if ( V_75 -> V_95 ) {
int V_28 = V_1 -> V_81 + V_96 ;
V_78 = & V_1 -> V_97 [ V_79 ] ;
V_78 -> V_98 = L_15 ;
V_99 [ 0 ] . V_100 = V_28 ;
V_99 [ 0 ] . V_101 = V_28 ;
V_78 -> V_102 = V_99 ;
V_78 -> V_103 = F_38 ( V_99 ) ;
V_78 -> V_76 = V_75 -> V_95 ;
V_78 -> V_104 = sizeof( * V_75 -> V_95 ) ;
V_79 ++ ;
}
if ( V_75 -> V_105 ) {
int V_28 = V_1 -> V_81 + V_106 ;
V_78 = & V_1 -> V_97 [ V_79 ] ;
V_78 -> V_98 = L_16 ;
V_107 [ 0 ] . V_100 = V_28 ;
V_107 [ 0 ] . V_101 = V_28 ;
V_78 -> V_102 = V_107 ;
V_78 -> V_103 = F_38 ( V_107 ) ;
V_78 -> V_76 = V_75 -> V_105 ;
V_78 -> V_104 = sizeof( * V_75 -> V_105 ) ;
V_79 ++ ;
}
if ( V_79 ) {
V_3 = F_39 ( & V_73 -> V_38 , V_73 -> V_108 , V_1 -> V_97 ,
V_79 , NULL , 0 ) ;
if ( V_3 )
goto V_109;
} else {
F_21 ( & V_73 -> V_38 , L_17 ) ;
V_3 = - V_69 ;
goto V_109;
}
return 0 ;
V_109:
F_40 ( V_1 -> V_81 + V_91 , V_1 ) ;
V_92:
F_41 ( V_1 ) ;
V_90:
if ( F_22 ( V_1 -> V_44 ) )
F_42 ( V_1 -> V_44 ) ;
V_89:
F_31 ( V_73 , NULL ) ;
F_43 ( V_1 ) ;
return V_3 ;
}
static int T_4 F_44 ( struct V_72 * V_73 )
{
struct V_1 * V_1 = F_45 ( V_73 ) ;
if ( V_1 -> V_46 )
F_17 ( V_1 , 0 ) ;
if ( F_22 ( V_1 -> V_44 ) )
F_42 ( V_1 -> V_44 ) ;
F_40 ( V_1 -> V_81 + V_91 , V_1 ) ;
F_41 ( V_1 ) ;
F_46 ( & V_73 -> V_38 ) ;
F_31 ( V_73 , NULL ) ;
F_43 ( V_1 ) ;
return 0 ;
}
