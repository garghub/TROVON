static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
V_6 = F_5 ( V_4 -> V_5 ) ;
if ( V_6 ) {
F_6 ( V_2 , L_1 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static int F_7 ( struct V_7 * V_8 ,
unsigned int V_9 )
{
struct V_3 * V_4 = F_8 ( V_8 ) ;
unsigned int V_10 , V_11 ;
switch ( V_9 & V_12 ) {
case V_13 :
break;
default:
return - V_14 ;
}
V_10 = V_15 ;
switch ( V_9 & V_16 ) {
case V_17 :
V_11 = V_15 ;
break;
case V_18 :
break;
default:
return - V_14 ;
}
V_10 |= V_19 |
V_20 ;
switch ( V_9 & V_21 ) {
case V_22 :
V_11 |= V_23 ;
V_11 |= V_24 ;
break;
case V_25 :
V_11 |= V_23 ;
V_11 |= V_26 ;
break;
case V_27 :
V_11 |= V_28 ;
V_11 |= V_24 ;
break;
case V_29 :
V_11 |= V_30 ;
V_11 |= V_24 ;
break;
case V_31 :
V_11 |= V_32 ;
V_11 |= V_24 ;
break;
default:
return - V_14 ;
}
F_9 ( V_4 -> V_33 , V_34 , V_10 , V_11 ) ;
return 0 ;
}
static int F_10 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_3 * V_4 = F_8 ( V_8 ) ;
unsigned int V_10 , V_11 ;
int V_6 , V_39 , V_40 , V_41 , V_42 ;
V_10 = V_43 ;
switch ( F_11 ( V_38 ) ) {
case V_44 :
V_11 = V_45 ;
V_39 = 16 ;
break;
case V_46 :
V_11 = V_47 ;
V_39 = 24 ;
break;
case V_48 :
V_11 = V_49 ;
V_39 = 32 ;
break;
default:
return - V_14 ;
}
V_10 |= V_50 ;
V_11 |= V_51 ;
F_9 ( V_4 -> V_33 , V_34 , V_10 , V_11 ) ;
V_40 = F_12 ( V_38 ) ;
V_41 = V_40 * F_13 ( V_38 ) * V_39 * 2 ;
V_6 = F_14 ( V_4 -> V_5 , V_41 ) ;
if ( V_6 ) {
F_6 ( V_2 , L_2 , V_6 ) ;
return V_6 ;
}
V_42 = ( V_41 / ( 2 * V_40 ) ) - 1 ;
if ( V_42 < 0 || V_42 > V_52 )
return - V_14 ;
V_11 = V_42 << V_53 ;
if ( V_41 % ( 2 * V_40 ) )
V_11 |= V_54 ;
F_15 ( V_4 -> V_33 , V_55 , V_11 ) ;
F_15 ( V_4 -> V_33 , V_56 ,
V_57 |
V_58 ) ;
return 0 ;
}
static void F_16 ( struct V_3 * V_4 )
{
F_9 ( V_4 -> V_33 , V_34 ,
V_59 ,
V_59 ) ;
}
static void F_17 ( struct V_3 * V_4 )
{
F_9 ( V_4 -> V_33 , V_34 ,
V_59 , 0 ) ;
}
static void F_18 ( struct V_3 * V_4 )
{
F_9 ( V_4 -> V_33 , V_34 ,
V_60 ,
V_60 ) ;
}
static void F_19 ( struct V_3 * V_4 )
{
F_9 ( V_4 -> V_33 , V_34 ,
V_60 , 0 ) ;
}
static int F_20 ( struct V_35 * V_36 , int V_61 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 = F_8 ( V_8 ) ;
switch ( V_61 ) {
case V_62 :
case V_63 :
case V_64 :
if ( V_36 -> V_65 == V_66 )
F_16 ( V_4 ) ;
else
F_18 ( V_4 ) ;
break;
case V_67 :
case V_68 :
case V_69 :
if ( V_36 -> V_65 == V_66 )
F_17 ( V_4 ) ;
else
F_19 ( V_4 ) ;
break;
default:
return - V_14 ;
}
return 0 ;
}
static int F_21 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_8 ( V_8 ) ;
V_8 -> V_70 = & V_4 -> V_70 ;
V_8 -> V_71 = & V_4 -> V_71 ;
return 0 ;
}
static bool F_22 ( struct V_1 * V_2 , unsigned int V_72 )
{
switch ( V_72 ) {
case V_34 :
case V_73 :
case V_55 :
case V_56 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
return true ;
default:
return false ;
} ;
}
static bool F_23 ( struct V_1 * V_2 , unsigned int V_72 )
{
switch ( V_72 ) {
case V_73 :
case V_56 :
case V_78 :
case V_79 :
return true ;
default:
return false ;
} ;
}
static bool F_24 ( struct V_1 * V_2 , unsigned int V_72 )
{
switch ( V_72 ) {
case V_78 :
case V_79 :
return true ;
default:
return false ;
} ;
}
static int F_25 ( struct V_80 * V_81 )
{
struct V_3 * V_4 ;
struct V_82 * V_83 , * V_84 , * V_85 ;
T_1 V_86 [ 2 ] ;
T_1 V_87 ;
void T_2 * V_88 ;
int V_6 ;
V_4 = F_26 ( & V_81 -> V_2 , sizeof( struct V_3 ) , V_89 ) ;
if ( ! V_4 ) {
F_6 ( & V_81 -> V_2 , L_3 ) ;
V_6 = - V_90 ;
goto V_91;
}
F_27 ( & V_81 -> V_2 , V_4 ) ;
V_4 -> V_8 = V_92 ;
V_4 -> V_8 . V_93 = F_28 ( & V_81 -> V_2 ) ;
V_4 -> V_5 = F_29 ( & V_81 -> V_2 , NULL ) ;
if ( F_30 ( V_4 -> V_5 ) ) {
F_6 ( & V_81 -> V_2 , L_4 ) ;
V_6 = F_31 ( V_4 -> V_5 ) ;
goto V_91;
}
V_83 = F_32 ( V_81 , V_94 , 0 ) ;
if ( ! V_83 ) {
F_6 ( & V_81 -> V_2 , L_5 ) ;
V_6 = - V_95 ;
goto V_96;
}
V_85 = F_32 ( V_81 , V_97 , 0 ) ;
if ( ! V_85 ) {
if ( F_33 ( V_81 -> V_2 . V_98 ,
L_6 ,
V_86 , 2 ) < 0 ) {
F_6 ( & V_81 -> V_2 , L_7 ) ;
V_6 = - V_95 ;
goto V_96;
}
V_87 = V_86 [ 1 ] ;
} else {
V_87 = V_85 -> V_99 ;
}
V_84 = F_34 ( & V_81 -> V_2 , V_83 -> V_99 ,
F_35 ( V_83 ) , V_100 ) ;
if ( ! V_84 ) {
F_6 ( & V_81 -> V_2 , L_8 ) ;
V_6 = - V_101 ;
goto V_96;
}
V_88 = F_36 ( & V_81 -> V_2 , V_83 -> V_99 , F_35 ( V_83 ) ) ;
if ( ! V_88 ) {
F_6 ( & V_81 -> V_2 , L_9 ) ;
V_6 = - V_90 ;
goto V_96;
}
V_4 -> V_33 = F_37 ( & V_81 -> V_2 , V_88 ,
& V_102 ) ;
if ( F_30 ( V_4 -> V_33 ) ) {
F_6 ( & V_81 -> V_2 , L_10 ) ;
V_6 = F_31 ( V_4 -> V_33 ) ;
goto V_96;
}
V_4 -> V_70 . V_103 = V_83 -> V_99 + V_79 ;
V_4 -> V_70 . V_104 = V_105 ;
V_4 -> V_70 . V_106 = 4 ;
V_4 -> V_70 . V_107 = V_87 ;
V_4 -> V_71 . V_103 = V_83 -> V_99 + V_78 ;
V_4 -> V_71 . V_104 = V_105 ;
V_4 -> V_71 . V_106 = 4 ;
V_4 -> V_71 . V_107 = V_87 ;
F_38 ( & V_81 -> V_2 ) ;
if ( ! F_39 ( & V_81 -> V_2 ) ) {
V_6 = F_4 ( & V_81 -> V_2 ) ;
if ( V_6 )
goto V_108;
}
V_6 = F_40 ( & V_81 -> V_2 , & V_109 ,
& V_4 -> V_8 , 1 ) ;
if ( V_6 ) {
F_6 ( & V_81 -> V_2 , L_11 , V_6 ) ;
V_6 = - V_90 ;
goto V_110;
}
V_6 = F_41 ( & V_81 -> V_2 ) ;
if ( V_6 ) {
F_6 ( & V_81 -> V_2 , L_12 , V_6 ) ;
goto V_111;
}
return 0 ;
V_111:
F_42 ( & V_81 -> V_2 ) ;
V_110:
if ( ! F_43 ( & V_81 -> V_2 ) )
F_1 ( & V_81 -> V_2 ) ;
V_108:
F_44 ( & V_81 -> V_2 ) ;
V_96:
F_45 ( V_4 -> V_5 ) ;
V_91:
return V_6 ;
}
static int F_46 ( struct V_80 * V_81 )
{
struct V_3 * V_4 = F_2 ( & V_81 -> V_2 ) ;
F_44 ( & V_81 -> V_2 ) ;
if ( ! F_43 ( & V_81 -> V_2 ) )
F_1 ( & V_81 -> V_2 ) ;
F_47 ( & V_81 -> V_2 ) ;
F_42 ( & V_81 -> V_2 ) ;
F_45 ( V_4 -> V_5 ) ;
return 0 ;
}
