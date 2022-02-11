static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , true ) ;
F_4 ( V_4 -> V_6 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
V_7 = F_6 ( V_4 -> V_6 ) ;
if ( V_7 ) {
F_7 ( V_2 , L_1 , V_7 ) ;
return V_7 ;
}
F_3 ( V_4 -> V_5 , false ) ;
return 0 ;
}
int F_8 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = F_9 ( V_11 ) ;
int V_7 ;
if ( V_9 -> V_12 == V_13 ) {
V_7 = F_10 ( & V_4 -> V_14 ,
& V_4 -> V_15 . V_16 ,
& V_4 -> V_15 . V_17 ) ;
V_4 -> V_15 . V_18 = 4 ;
V_4 -> V_15 . V_19 = 32 ;
F_11 ( V_4 -> V_20 ,
V_4 -> V_14 ) ;
} else {
V_7 = F_12 ( & V_4 -> V_21 ,
& V_4 -> V_22 . V_16 ,
& V_4 -> V_22 . V_17 ) ;
V_4 -> V_22 . V_18 = 4 ;
V_4 -> V_22 . V_19 = 32 ;
F_11 ( V_4 -> V_21 ,
V_4 -> V_23 ) ;
}
return V_7 ;
}
void F_13 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = F_9 ( V_11 ) ;
if ( V_9 -> V_12 == V_13 ) {
F_14 ( V_4 -> V_20 ) ;
F_15 ( V_4 -> V_14 ) ;
} else {
F_14 ( V_4 -> V_21 ) ;
F_16 ( V_4 -> V_21 ) ;
}
}
static int F_17 ( struct V_10 * V_11 ,
unsigned int V_24 )
{
struct V_3 * V_4 = F_9 ( V_11 ) ;
unsigned int V_25 , V_26 ;
switch ( V_24 & V_27 ) {
case V_28 :
break;
default:
return - V_29 ;
}
V_25 = V_30 ;
switch ( V_24 & V_31 ) {
case V_32 :
V_26 = V_30 ;
break;
case V_33 :
break;
default:
return - V_29 ;
}
V_25 |= V_34 |
V_35 ;
switch ( V_24 & V_36 ) {
case V_37 :
V_26 |= V_38 ;
V_26 |= V_39 ;
break;
case V_40 :
V_26 |= V_38 ;
V_26 |= V_41 ;
break;
case V_42 :
V_26 |= V_43 ;
V_26 |= V_39 ;
break;
case V_44 :
V_26 |= V_43 ;
V_26 |= V_39 ;
break;
case V_45 :
V_26 |= V_43 ;
V_26 |= V_39 ;
break;
default:
return - V_29 ;
}
F_18 ( V_11 -> V_2 ) ;
F_19 ( V_4 -> V_5 , V_46 , V_25 , V_26 ) ;
F_20 ( V_11 -> V_2 ) ;
return 0 ;
}
static int F_21 ( struct V_8 * V_9 ,
struct V_47 * V_48 ,
struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = F_9 ( V_11 ) ;
unsigned int V_25 , V_26 , V_49 ;
int V_7 , V_50 , V_51 , V_52 , V_53 ;
if ( F_22 ( V_48 ) != 2 )
return - V_29 ;
V_25 = V_54 ;
switch ( F_23 ( V_48 ) ) {
case V_55 :
V_26 = V_56 ;
V_50 = 16 ;
break;
default:
return - V_29 ;
}
F_19 ( V_4 -> V_5 , V_46 , V_25 , V_26 ) ;
V_51 = F_24 ( V_48 ) ;
V_52 = V_51 * F_22 ( V_48 ) * V_50 * 2 ;
V_53 = ( V_52 / ( 2 * V_51 ) ) - 1 ;
if ( V_53 < 0 || V_53 > V_57 )
return - V_29 ;
V_7 = F_25 ( V_4 -> V_6 , V_52 ) ;
if ( V_7 ) {
F_7 ( V_2 , L_2 , V_7 ) ;
return V_7 ;
}
V_26 = V_53 << V_58 ;
if ( V_52 % ( 2 * V_51 ) )
V_26 |= V_59 ;
F_26 ( V_4 -> V_5 , V_60 , V_26 ) ;
V_26 = ( 0 << V_61 ) |
( 1 << V_62 ) |
( 1 << V_63 ) |
V_64 |
V_65 ;
if ( V_9 -> V_12 == V_13 ) {
V_26 |= V_66 ;
V_49 = V_67 ;
} else {
V_26 |= V_68 ;
V_49 = V_67 ;
}
F_26 ( V_4 -> V_5 , V_49 , V_26 ) ;
V_26 = ( 1 << V_69 ) |
( 1 << V_70 ) ;
F_26 ( V_4 -> V_5 , V_71 , V_26 ) ;
return 0 ;
}
static void F_27 ( struct V_3 * V_4 )
{
F_28 ( V_4 -> V_14 ) ;
F_19 ( V_4 -> V_5 , V_46 ,
V_72 ,
V_72 ) ;
}
static void F_29 ( struct V_3 * V_4 )
{
F_30 ( V_4 -> V_14 ) ;
F_19 ( V_4 -> V_5 , V_46 ,
V_72 , 0 ) ;
}
static void F_31 ( struct V_3 * V_4 )
{
F_32 ( V_4 -> V_21 ) ;
F_19 ( V_4 -> V_5 , V_46 ,
V_73 ,
V_73 ) ;
}
static void F_33 ( struct V_3 * V_4 )
{
F_34 ( V_4 -> V_21 ) ;
F_19 ( V_4 -> V_5 , V_46 ,
V_73 , 0 ) ;
}
static int F_35 ( struct V_8 * V_9 , int V_74 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = F_9 ( V_11 ) ;
switch ( V_74 ) {
case V_75 :
case V_76 :
case V_77 :
if ( V_9 -> V_12 == V_13 )
F_27 ( V_4 ) ;
else
F_31 ( V_4 ) ;
break;
case V_78 :
case V_79 :
case V_80 :
if ( V_9 -> V_12 == V_13 )
F_29 ( V_4 ) ;
else
F_33 ( V_4 ) ;
break;
default:
return - V_29 ;
}
return 0 ;
}
static int F_36 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = F_9 ( V_11 ) ;
V_11 -> V_22 = & V_4 -> V_22 ;
V_11 -> V_15 = & V_4 -> V_15 ;
return 0 ;
}
static bool F_37 ( struct V_1 * V_2 , unsigned int V_49 )
{
switch ( V_49 ) {
case V_46 :
case V_60 :
case V_71 :
case V_81 :
case V_82 :
case V_67 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
return true ;
default:
return false ;
} ;
}
static bool F_38 ( struct V_1 * V_2 , unsigned int V_49 )
{
switch ( V_49 ) {
case V_86 :
case V_87 :
case V_88 :
case V_89 :
return true ;
default:
return false ;
} ;
}
static T_1 int F_39 ( struct V_99 * V_100 )
{
struct V_3 * V_4 ;
T_2 V_101 [ 2 ] ;
struct V_102 * V_103 , * V_104 ;
void T_3 * V_105 ;
int V_7 ;
V_4 = F_40 ( & V_100 -> V_2 , sizeof( struct V_3 ) , V_106 ) ;
if ( ! V_4 ) {
F_7 ( & V_100 -> V_2 , L_3 ) ;
V_7 = - V_107 ;
goto V_108;
}
F_41 ( & V_100 -> V_2 , V_4 ) ;
V_4 -> V_11 = V_109 ;
V_4 -> V_11 . V_110 = F_42 ( & V_100 -> V_2 ) ;
V_7 = F_43 ( V_100 -> V_2 . V_111 ,
L_4 , V_101 ,
F_44 ( V_101 ) ) ;
if ( V_7 < 0 )
goto V_108;
V_4 -> V_20 = V_101 [ 0 ] ;
V_4 -> V_23 = V_101 [ 1 ] ;
V_4 -> V_6 = F_45 ( & V_100 -> V_2 , NULL ) ;
if ( F_46 ( V_4 -> V_6 ) ) {
F_7 ( & V_100 -> V_2 , L_5 ) ;
V_7 = F_47 ( V_4 -> V_6 ) ;
goto V_108;
}
V_103 = F_48 ( V_100 , V_112 , 0 ) ;
if ( ! V_103 ) {
F_7 ( & V_100 -> V_2 , L_6 ) ;
V_7 = - V_113 ;
goto V_114;
}
V_104 = F_49 ( & V_100 -> V_2 , V_103 -> V_115 ,
F_50 ( V_103 ) , V_116 ) ;
if ( ! V_104 ) {
F_7 ( & V_100 -> V_2 , L_7 ) ;
V_7 = - V_117 ;
goto V_114;
}
V_105 = F_51 ( & V_100 -> V_2 , V_103 -> V_115 , F_50 ( V_103 ) ) ;
if ( ! V_105 ) {
F_7 ( & V_100 -> V_2 , L_8 ) ;
V_7 = - V_107 ;
goto V_114;
}
V_4 -> V_5 = F_52 ( & V_100 -> V_2 , V_105 ,
& V_118 ) ;
if ( F_46 ( V_4 -> V_5 ) ) {
F_7 ( & V_100 -> V_2 , L_9 ) ;
V_7 = F_47 ( V_4 -> V_5 ) ;
goto V_114;
}
F_3 ( V_4 -> V_5 , true ) ;
F_53 ( & V_100 -> V_2 ) ;
if ( ! F_54 ( & V_100 -> V_2 ) ) {
V_7 = F_5 ( & V_100 -> V_2 ) ;
if ( V_7 )
goto V_119;
}
V_7 = F_55 ( & V_100 -> V_2 , & V_4 -> V_11 ) ;
if ( V_7 ) {
F_7 ( & V_100 -> V_2 , L_10 , V_7 ) ;
V_7 = - V_107 ;
goto V_120;
}
V_7 = F_56 ( & V_100 -> V_2 ) ;
if ( V_7 ) {
F_7 ( & V_100 -> V_2 , L_11 , V_7 ) ;
goto V_121;
}
return 0 ;
V_121:
F_57 ( & V_100 -> V_2 ) ;
V_120:
if ( ! F_58 ( & V_100 -> V_2 ) )
F_1 ( & V_100 -> V_2 ) ;
V_119:
F_59 ( & V_100 -> V_2 ) ;
V_114:
F_60 ( V_4 -> V_6 ) ;
V_108:
return V_7 ;
}
static int T_4 F_61 ( struct V_99 * V_100 )
{
struct V_3 * V_4 = F_2 ( & V_100 -> V_2 ) ;
F_59 ( & V_100 -> V_2 ) ;
if ( ! F_58 ( & V_100 -> V_2 ) )
F_1 ( & V_100 -> V_2 ) ;
F_62 ( & V_100 -> V_2 ) ;
F_57 ( & V_100 -> V_2 ) ;
F_60 ( V_4 -> V_6 ) ;
return 0 ;
}
