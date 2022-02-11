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
} else {
if ( ! V_1 -> V_46 ) {
F_21 ( V_1 -> V_38 ,
L_6 ) ;
V_3 = - V_50 ;
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
}
V_11:
F_6 ( & V_1 -> V_45 ) ;
return V_3 ;
}
int F_24 ( struct V_1 * V_1 , int V_51 ,
unsigned int V_52 , unsigned int V_53 )
{
T_1 V_54 , V_14 ;
int V_3 = 0 ;
F_2 ( & V_1 -> V_45 ) ;
V_54 = F_1 ( V_1 , V_55 ) ;
V_14 = F_1 ( V_1 , V_25 ) ;
switch ( V_51 ) {
case V_48 :
switch ( V_53 ) {
case 17640000 :
V_14 |= V_56 ;
break;
case 19200000 :
V_14 &= ~ V_56 ;
break;
default:
F_21 ( V_1 -> V_38 ,
L_7 , V_53 ) ;
V_3 = - V_57 ;
goto V_58;
}
F_7 ( V_1 , V_25 , V_14 ) ;
switch ( V_52 ) {
case 32768 :
V_14 |= V_24 ;
F_7 ( V_1 , V_25 ,
V_14 ) ;
F_25 ( 5 ) ;
V_14 &= ~ V_59 ;
F_7 ( V_1 , V_25 ,
V_14 ) ;
V_54 &= ~ V_60 ;
F_7 ( V_1 , V_55 ,
V_54 ) ;
break;
default:
F_21 ( V_1 -> V_38 ,
L_8 , V_52 ) ;
V_3 = - V_57 ;
goto V_58;
}
break;
case V_61 :
if ( V_53 != 19200000 ) {
F_21 ( V_1 -> V_38 ,
L_7 , V_53 ) ;
V_3 = - V_57 ;
goto V_58;
}
V_54 &= ~ V_62 ;
switch ( V_52 ) {
case 12000000 :
V_54 |= V_63 |
V_60 ;
break;
case 19200000 :
V_54 |= V_64 ;
break;
case 26000000 :
V_54 |= V_65 |
V_60 ;
break;
case 38400000 :
V_54 |= V_66 |
V_60 ;
break;
default:
F_21 ( V_1 -> V_38 ,
L_8 , V_52 ) ;
V_3 = - V_57 ;
goto V_58;
}
V_54 |= V_67 ;
F_7 ( V_1 , V_55 , V_54 ) ;
F_12 ( 500 , 700 ) ;
V_14 |= V_59 ;
F_7 ( V_1 , V_25 , V_14 ) ;
V_14 &= ~ V_24 ;
F_7 ( V_1 , V_25 , V_14 ) ;
break;
default:
F_21 ( V_1 -> V_38 , L_9 , V_51 ) ;
V_3 = - V_57 ;
goto V_58;
}
V_1 -> V_49 = V_53 ;
V_1 -> V_47 = V_51 ;
V_58:
F_6 ( & V_1 -> V_45 ) ;
return V_3 ;
}
int F_26 ( struct V_1 * V_1 )
{
if ( V_1 -> V_46 )
return V_1 -> V_47 ;
else
return - V_68 ;
}
unsigned int F_27 ( struct V_1 * V_1 )
{
return V_1 -> V_49 ;
}
int F_28 ( struct V_1 * V_1 )
{
T_1 V_31 ;
V_31 = V_1 -> V_8 [ 0 ] | V_1 -> V_8 [ 1 ] ;
V_31 &= ( V_69 | V_70 ) ;
return V_31 ;
}
static int T_3 F_29 ( struct V_71 * V_72 )
{
struct V_73 * V_74 = V_72 -> V_38 . V_75 ;
struct V_1 * V_1 ;
struct V_76 * V_77 = NULL ;
int V_3 , V_78 = 0 ;
if ( ! V_74 ) {
F_21 ( & V_72 -> V_38 , L_10 ) ;
return - V_57 ;
}
if ( ! V_74 -> V_79 || ! V_74 -> V_80 ) {
F_21 ( & V_72 -> V_38 , L_11 ) ;
return - V_57 ;
}
V_1 = F_30 ( sizeof( struct V_1 ) , V_81 ) ;
if ( ! V_1 )
return - V_82 ;
F_31 ( V_72 , V_1 ) ;
V_1 -> V_38 = & V_72 -> V_38 ;
V_1 -> V_28 = V_74 -> V_79 ;
V_1 -> V_80 = V_74 -> V_80 ;
F_32 ( & V_1 -> V_45 ) ;
F_32 ( & V_1 -> V_5 ) ;
F_33 ( & V_1 -> V_34 ) ;
V_1 -> V_83 = F_1 ( V_1 , V_84 ) ;
if ( F_34 ( V_1 ) > V_85 )
V_1 -> V_44 = V_74 -> V_86 ;
else
V_1 -> V_44 = - V_57 ;
if ( F_22 ( V_1 -> V_44 ) ) {
V_3 = F_35 ( V_1 -> V_44 , L_12 ) ;
if ( V_3 )
goto V_87;
V_3 = F_36 ( V_1 -> V_44 , 0 ) ;
if ( V_3 )
goto V_88;
}
V_3 = F_37 ( V_1 ) ;
if ( V_3 )
goto V_88;
V_3 = F_38 ( V_1 -> V_80 + V_89 ,
NULL , F_14 , 0 ,
L_13 , V_1 ) ;
if ( V_3 ) {
F_21 ( V_1 -> V_38 , L_14 ,
V_3 ) ;
goto V_90;
}
F_9 ( V_1 , V_91 , V_92 ) ;
if ( V_74 -> V_93 ) {
int V_28 = V_1 -> V_80 + V_94 ;
V_77 = & V_1 -> V_95 [ V_78 ] ;
V_77 -> V_96 = L_15 ;
V_97 [ 0 ] . V_98 = V_28 ;
V_97 [ 0 ] . V_99 = V_28 ;
V_77 -> V_100 = V_97 ;
V_77 -> V_101 = F_39 ( V_97 ) ;
V_77 -> V_75 = V_74 -> V_93 ;
V_77 -> V_102 = sizeof( * V_74 -> V_93 ) ;
V_78 ++ ;
}
if ( V_74 -> V_103 ) {
int V_28 = V_1 -> V_80 + V_104 ;
V_77 = & V_1 -> V_95 [ V_78 ] ;
V_77 -> V_96 = L_16 ;
V_105 [ 0 ] . V_98 = V_28 ;
V_105 [ 0 ] . V_99 = V_28 ;
V_77 -> V_100 = V_105 ;
V_77 -> V_101 = F_39 ( V_105 ) ;
V_77 -> V_75 = V_74 -> V_103 ;
V_77 -> V_102 = sizeof( * V_74 -> V_103 ) ;
V_78 ++ ;
}
if ( V_78 ) {
V_3 = F_40 ( & V_72 -> V_38 , V_72 -> V_106 , V_1 -> V_95 ,
V_78 , NULL , 0 ) ;
if ( V_3 )
goto V_107;
} else {
F_21 ( & V_72 -> V_38 , L_17 ) ;
V_3 = - V_68 ;
goto V_107;
}
return 0 ;
V_107:
F_41 ( V_1 -> V_80 + V_89 , V_1 ) ;
V_90:
F_42 ( V_1 ) ;
V_88:
if ( F_22 ( V_1 -> V_44 ) )
F_43 ( V_1 -> V_44 ) ;
V_87:
F_31 ( V_72 , NULL ) ;
F_44 ( V_1 ) ;
return V_3 ;
}
static int T_4 F_45 ( struct V_71 * V_72 )
{
struct V_1 * V_1 = F_46 ( V_72 ) ;
if ( V_1 -> V_46 )
F_17 ( V_1 , 0 ) ;
if ( F_22 ( V_1 -> V_44 ) )
F_43 ( V_1 -> V_44 ) ;
F_41 ( V_1 -> V_80 + V_89 , V_1 ) ;
F_42 ( V_1 ) ;
F_47 ( & V_72 -> V_38 ) ;
F_31 ( V_72 , NULL ) ;
F_44 ( V_1 ) ;
return 0 ;
}
static int T_3 F_48 ( void )
{
return F_49 ( & V_108 ) ;
}
static void T_4 F_50 ( void )
{
F_51 ( & V_108 ) ;
}
