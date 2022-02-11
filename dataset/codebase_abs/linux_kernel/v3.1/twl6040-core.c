int F_1 ( struct V_1 * V_1 , unsigned int V_2 )
{
int V_3 ;
T_1 V_4 = 0 ;
F_2 ( & V_1 -> V_5 ) ;
V_3 = F_3 ( V_6 , & V_4 , V_2 ) ;
if ( V_3 < 0 ) {
F_4 ( & V_1 -> V_5 ) ;
return V_3 ;
}
F_4 ( & V_1 -> V_5 ) ;
return V_4 ;
}
int F_5 ( struct V_1 * V_1 , unsigned int V_2 , T_1 V_4 )
{
int V_3 ;
F_2 ( & V_1 -> V_5 ) ;
V_3 = F_6 ( V_6 , V_4 , V_2 ) ;
F_4 ( & V_1 -> V_5 ) ;
return V_3 ;
}
int F_7 ( struct V_1 * V_1 , unsigned int V_2 , T_1 V_7 )
{
int V_3 ;
T_1 V_4 ;
F_2 ( & V_1 -> V_5 ) ;
V_3 = F_3 ( V_6 , & V_4 , V_2 ) ;
if ( V_3 )
goto V_8;
V_4 |= V_7 ;
V_3 = F_6 ( V_6 , V_4 , V_2 ) ;
V_8:
F_4 ( & V_1 -> V_5 ) ;
return V_3 ;
}
int F_8 ( struct V_1 * V_1 , unsigned int V_2 , T_1 V_7 )
{
int V_3 ;
T_1 V_4 ;
F_2 ( & V_1 -> V_5 ) ;
V_3 = F_3 ( V_6 , & V_4 , V_2 ) ;
if ( V_3 )
goto V_8;
V_4 &= ~ V_7 ;
V_3 = F_6 ( V_6 , V_4 , V_2 ) ;
V_8:
F_4 ( & V_1 -> V_5 ) ;
return V_3 ;
}
static int F_9 ( struct V_1 * V_1 )
{
T_1 V_9 , V_10 , V_11 ;
int V_3 ;
V_9 = V_12 | V_13 | V_14 ;
V_3 = F_5 ( V_1 , V_15 , V_9 ) ;
if ( V_3 )
return V_3 ;
F_10 ( 10000 , 10500 ) ;
V_10 = V_16 ;
V_3 = F_5 ( V_1 , V_17 , V_10 ) ;
if ( V_3 )
goto V_18;
F_10 ( 1000 , 1500 ) ;
V_9 |= V_19 ;
V_3 = F_5 ( V_1 , V_15 , V_9 ) ;
if ( V_3 )
goto V_20;
F_10 ( 1000 , 1500 ) ;
V_11 = V_21 ;
V_3 = F_5 ( V_1 , V_22 , V_11 ) ;
if ( V_3 )
goto V_23;
F_10 ( 5000 , 5500 ) ;
V_9 &= ~ V_14 ;
V_3 = F_5 ( V_1 , V_15 , V_9 ) ;
if ( V_3 )
goto V_24;
return 0 ;
V_24:
V_11 &= ~ V_21 ;
F_5 ( V_1 , V_22 , V_11 ) ;
V_23:
V_9 &= ~ V_19 ;
F_5 ( V_1 , V_15 , V_9 ) ;
V_20:
V_10 &= ~ V_16 ;
F_5 ( V_1 , V_17 , V_10 ) ;
V_18:
V_9 &= ~ ( V_12 | V_13 | V_14 ) ;
F_5 ( V_1 , V_15 , V_9 ) ;
return V_3 ;
}
static void F_11 ( struct V_1 * V_1 )
{
T_1 V_10 , V_9 , V_11 ;
V_10 = F_1 ( V_1 , V_17 ) ;
V_9 = F_1 ( V_1 , V_15 ) ;
V_11 = F_1 ( V_1 , V_22 ) ;
V_9 |= V_14 ;
F_5 ( V_1 , V_15 , V_9 ) ;
F_10 ( 1000 , 1500 ) ;
V_11 &= ~ V_21 ;
F_5 ( V_1 , V_22 , V_11 ) ;
V_9 &= ~ V_19 ;
F_5 ( V_1 , V_15 , V_9 ) ;
V_10 &= ~ V_16 ;
F_5 ( V_1 , V_17 , V_10 ) ;
V_9 &= ~ ( V_12 | V_13 | V_14 ) ;
F_5 ( V_1 , V_15 , V_9 ) ;
}
static T_2 F_12 ( int V_25 , void * V_26 )
{
struct V_1 * V_1 = V_26 ;
T_1 V_27 , V_28 ;
V_27 = F_1 ( V_1 , V_29 ) ;
if ( V_27 & V_30 )
F_13 ( & V_1 -> V_31 ) ;
if ( V_27 & V_32 ) {
V_28 = F_1 ( V_1 , V_33 ) ;
if ( V_28 & V_34 ) {
F_14 ( & V_35 -> V_36 ,
L_1 ) ;
F_15 ( V_1 , 0 ) ;
} else {
F_14 ( & V_35 -> V_36 ,
L_2 ) ;
F_15 ( V_1 , 1 ) ;
}
}
return V_37 ;
}
static int F_16 ( struct V_1 * V_1 ,
int V_38 )
{
int V_39 ;
T_1 V_27 ;
V_39 = F_17 ( & V_1 -> V_31 ,
F_18 ( 144 ) ) ;
if ( ! V_39 ) {
V_27 = F_1 ( V_1 , V_29 ) ;
if ( ! ( V_27 & V_30 ) ) {
F_19 ( & V_35 -> V_36 ,
L_3 ) ;
return - V_40 ;
}
}
return 0 ;
}
int F_15 ( struct V_1 * V_1 , int V_41 )
{
int V_42 = V_1 -> V_42 ;
int V_38 = V_1 -> V_25 ;
int V_3 = 0 ;
F_2 ( & V_1 -> V_43 ) ;
if ( V_41 ) {
if ( V_1 -> V_44 ++ )
goto V_8;
if ( F_20 ( V_42 ) ) {
F_21 ( V_42 , 1 ) ;
V_3 = F_16 ( V_1 , V_38 ) ;
if ( V_3 ) {
F_19 ( & V_35 -> V_36 ,
L_4 ) ;
V_1 -> V_44 = 0 ;
goto V_8;
}
} else {
V_3 = F_9 ( V_1 ) ;
if ( V_3 ) {
F_19 ( & V_35 -> V_36 ,
L_5 ) ;
V_1 -> V_44 = 0 ;
goto V_8;
}
}
V_1 -> V_45 = V_46 ;
V_1 -> V_47 = 19200000 ;
} else {
if ( ! V_1 -> V_44 ) {
F_19 ( & V_35 -> V_36 ,
L_6 ) ;
V_3 = - V_48 ;
goto V_8;
}
if ( -- V_1 -> V_44 )
goto V_8;
if ( F_20 ( V_42 ) ) {
F_21 ( V_42 , 0 ) ;
F_10 ( 500 , 700 ) ;
} else {
F_11 ( V_1 ) ;
}
V_1 -> V_47 = 0 ;
}
V_8:
F_4 ( & V_1 -> V_43 ) ;
return V_3 ;
}
int F_22 ( struct V_1 * V_1 , int V_49 ,
unsigned int V_50 , unsigned int V_51 )
{
T_1 V_52 , V_11 ;
int V_3 = 0 ;
F_2 ( & V_1 -> V_43 ) ;
V_52 = F_1 ( V_1 , V_53 ) ;
V_11 = F_1 ( V_1 , V_22 ) ;
switch ( V_49 ) {
case V_46 :
switch ( V_51 ) {
case 17640000 :
V_11 |= V_54 ;
break;
case 19200000 :
V_11 &= ~ V_54 ;
break;
default:
F_19 ( & V_35 -> V_36 ,
L_7 , V_51 ) ;
V_3 = - V_55 ;
goto V_56;
}
F_5 ( V_1 , V_22 , V_11 ) ;
switch ( V_50 ) {
case 32768 :
V_11 |= V_21 ;
F_5 ( V_1 , V_22 ,
V_11 ) ;
F_23 ( 5 ) ;
V_11 &= ~ V_57 ;
F_5 ( V_1 , V_22 ,
V_11 ) ;
V_52 &= ~ V_58 ;
F_5 ( V_1 , V_53 ,
V_52 ) ;
break;
default:
F_19 ( & V_35 -> V_36 ,
L_8 , V_50 ) ;
V_3 = - V_55 ;
goto V_56;
}
break;
case V_59 :
if ( V_51 != 19200000 ) {
F_19 ( & V_35 -> V_36 ,
L_7 , V_51 ) ;
V_3 = - V_55 ;
goto V_56;
}
V_52 &= ~ V_60 ;
switch ( V_50 ) {
case 12000000 :
V_52 |= V_61 |
V_58 ;
break;
case 19200000 :
V_52 |= V_62 ;
break;
case 26000000 :
V_52 |= V_63 |
V_58 ;
break;
case 38400000 :
V_52 |= V_64 |
V_58 ;
break;
default:
F_19 ( & V_35 -> V_36 ,
L_8 , V_50 ) ;
V_3 = - V_55 ;
goto V_56;
}
V_52 |= V_65 ;
F_5 ( V_1 , V_53 , V_52 ) ;
F_10 ( 500 , 700 ) ;
V_11 |= V_57 ;
F_5 ( V_1 , V_22 , V_11 ) ;
V_11 &= ~ V_21 ;
F_5 ( V_1 , V_22 , V_11 ) ;
break;
default:
F_19 ( & V_35 -> V_36 , L_9 , V_49 ) ;
V_3 = - V_55 ;
goto V_56;
}
V_1 -> V_47 = V_51 ;
V_1 -> V_45 = V_49 ;
V_56:
F_4 ( & V_1 -> V_43 ) ;
return V_3 ;
}
int F_24 ( struct V_1 * V_1 )
{
if ( V_1 -> V_44 )
return V_1 -> V_45 ;
else
return - V_66 ;
}
unsigned int F_25 ( struct V_1 * V_1 )
{
return V_1 -> V_47 ;
}
static int T_3 F_26 ( struct V_67 * V_68 )
{
struct V_69 * V_70 = V_68 -> V_36 . V_71 ;
struct V_1 * V_1 ;
struct V_72 * V_73 = NULL ;
int V_3 , V_74 = 0 ;
if ( ! V_70 ) {
F_19 ( & V_68 -> V_36 , L_10 ) ;
return - V_55 ;
}
if ( ! V_70 -> V_75 || ! V_70 -> V_76 ) {
F_19 ( & V_68 -> V_36 , L_11 ) ;
return - V_55 ;
}
V_1 = F_27 ( sizeof( struct V_1 ) , V_77 ) ;
if ( ! V_1 )
return - V_78 ;
F_28 ( V_68 , V_1 ) ;
V_35 = V_68 ;
V_1 -> V_36 = & V_68 -> V_36 ;
V_1 -> V_42 = V_70 -> V_79 ;
V_1 -> V_25 = V_70 -> V_75 ;
V_1 -> V_76 = V_70 -> V_76 ;
F_29 ( & V_1 -> V_43 ) ;
F_29 ( & V_1 -> V_5 ) ;
F_30 ( & V_1 -> V_31 ) ;
V_1 -> V_80 = F_1 ( V_1 , V_81 ) ;
if ( F_20 ( V_1 -> V_42 ) ) {
V_3 = F_31 ( V_1 -> V_42 , L_12 ) ;
if ( V_3 )
goto V_82;
V_3 = F_32 ( V_1 -> V_42 , 0 ) ;
if ( V_3 )
goto V_83;
}
if ( V_1 -> V_80 == V_84 )
V_1 -> V_42 = - V_55 ;
V_3 = F_33 ( V_1 ) ;
if ( V_3 )
goto V_83;
V_3 = F_34 ( V_1 -> V_76 + V_85 ,
NULL , F_12 , 0 ,
L_13 , V_1 ) ;
if ( V_3 ) {
F_19 ( V_1 -> V_36 , L_14 ,
V_3 ) ;
goto V_86;
}
F_7 ( V_1 , V_87 , V_88 ) ;
if ( V_70 -> V_89 ) {
int V_25 = V_1 -> V_76 + V_90 ;
V_73 = & V_1 -> V_91 [ V_74 ] ;
V_73 -> V_92 = L_15 ;
V_93 [ 0 ] . V_94 = V_25 ;
V_93 [ 0 ] . V_95 = V_25 ;
V_73 -> V_96 = V_93 ;
V_73 -> V_97 = F_35 ( V_93 ) ;
V_73 -> V_71 = V_70 -> V_89 ;
V_73 -> V_98 = sizeof( * V_70 -> V_89 ) ;
V_74 ++ ;
}
if ( V_70 -> V_99 ) {
int V_25 = V_1 -> V_76 + V_100 ;
V_73 = & V_1 -> V_91 [ V_74 ] ;
V_73 -> V_92 = L_16 ;
V_101 [ 0 ] . V_94 = V_25 ;
V_101 [ 0 ] . V_95 = V_25 ;
V_73 -> V_96 = V_101 ;
V_73 -> V_97 = F_35 ( V_101 ) ;
V_73 -> V_71 = V_70 -> V_99 ;
V_73 -> V_98 = sizeof( * V_70 -> V_99 ) ;
V_74 ++ ;
}
if ( V_74 ) {
V_3 = F_36 ( & V_68 -> V_36 , V_68 -> V_102 , V_1 -> V_91 ,
V_74 , NULL , 0 ) ;
if ( V_3 )
goto V_103;
} else {
F_19 ( & V_68 -> V_36 , L_17 ) ;
V_3 = - V_66 ;
goto V_103;
}
return 0 ;
V_103:
F_37 ( V_1 -> V_76 + V_85 , V_1 ) ;
V_86:
F_38 ( V_1 ) ;
V_83:
if ( F_20 ( V_1 -> V_42 ) )
F_39 ( V_1 -> V_42 ) ;
V_82:
F_28 ( V_68 , NULL ) ;
F_40 ( V_1 ) ;
V_35 = NULL ;
return V_3 ;
}
static int T_4 F_41 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_42 ( V_68 ) ;
if ( V_1 -> V_44 )
F_15 ( V_1 , 0 ) ;
if ( F_20 ( V_1 -> V_42 ) )
F_39 ( V_1 -> V_42 ) ;
F_37 ( V_1 -> V_76 + V_85 , V_1 ) ;
F_38 ( V_1 ) ;
F_43 ( & V_68 -> V_36 ) ;
F_28 ( V_68 , NULL ) ;
F_40 ( V_1 ) ;
V_35 = NULL ;
return 0 ;
}
static int T_3 F_44 ( void )
{
return F_45 ( & V_104 ) ;
}
static void T_4 F_46 ( void )
{
F_47 ( & V_104 ) ;
}
