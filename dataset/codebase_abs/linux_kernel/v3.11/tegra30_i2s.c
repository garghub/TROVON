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
static int F_8 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = F_9 ( V_11 ) ;
int V_7 ;
if ( V_9 -> V_12 == V_13 ) {
V_7 = F_10 ( & V_4 -> V_14 ,
& V_4 -> V_15 . V_16 ,
& V_4 -> V_15 . V_17 ) ;
V_4 -> V_15 . V_18 = V_19 ;
V_4 -> V_15 . V_20 = 4 ;
F_11 ( V_4 -> V_21 ,
V_4 -> V_14 ) ;
} else {
V_7 = F_12 ( & V_4 -> V_22 ,
& V_4 -> V_23 . V_16 ,
& V_4 -> V_23 . V_17 ) ;
V_4 -> V_23 . V_18 = V_19 ;
V_4 -> V_23 . V_20 = 4 ;
F_11 ( V_4 -> V_22 ,
V_4 -> V_24 ) ;
}
return V_7 ;
}
static void F_13 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = F_9 ( V_11 ) ;
if ( V_9 -> V_12 == V_13 ) {
F_14 ( V_4 -> V_21 ) ;
F_15 ( V_4 -> V_14 ) ;
} else {
F_14 ( V_4 -> V_22 ) ;
F_16 ( V_4 -> V_22 ) ;
}
}
static int F_17 ( struct V_10 * V_11 ,
unsigned int V_25 )
{
struct V_3 * V_4 = F_9 ( V_11 ) ;
unsigned int V_26 , V_27 ;
switch ( V_25 & V_28 ) {
case V_29 :
break;
default:
return - V_30 ;
}
V_26 = V_31 ;
switch ( V_25 & V_32 ) {
case V_33 :
V_27 = V_31 ;
break;
case V_34 :
break;
default:
return - V_30 ;
}
V_26 |= V_35 |
V_36 ;
switch ( V_25 & V_37 ) {
case V_38 :
V_27 |= V_39 ;
V_27 |= V_40 ;
break;
case V_41 :
V_27 |= V_39 ;
V_27 |= V_42 ;
break;
case V_43 :
V_27 |= V_44 ;
V_27 |= V_40 ;
break;
case V_45 :
V_27 |= V_44 ;
V_27 |= V_40 ;
break;
case V_46 :
V_27 |= V_44 ;
V_27 |= V_40 ;
break;
default:
return - V_30 ;
}
F_18 ( V_11 -> V_2 ) ;
F_19 ( V_4 -> V_5 , V_47 , V_26 , V_27 ) ;
F_20 ( V_11 -> V_2 ) ;
return 0 ;
}
static int F_21 ( struct V_8 * V_9 ,
struct V_48 * V_49 ,
struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = F_9 ( V_11 ) ;
unsigned int V_26 , V_27 , V_50 ;
int V_7 , V_51 , V_52 , V_53 , V_54 ;
if ( F_22 ( V_49 ) != 2 )
return - V_30 ;
V_26 = V_55 ;
switch ( F_23 ( V_49 ) ) {
case V_56 :
V_27 = V_57 ;
V_51 = 16 ;
break;
default:
return - V_30 ;
}
F_19 ( V_4 -> V_5 , V_47 , V_26 , V_27 ) ;
V_52 = F_24 ( V_49 ) ;
V_53 = V_52 * F_22 ( V_49 ) * V_51 * 2 ;
V_54 = ( V_53 / ( 2 * V_52 ) ) - 1 ;
if ( V_54 < 0 || V_54 > V_58 )
return - V_30 ;
V_7 = F_25 ( V_4 -> V_6 , V_53 ) ;
if ( V_7 ) {
F_7 ( V_2 , L_2 , V_7 ) ;
return V_7 ;
}
V_27 = V_54 << V_59 ;
if ( V_53 % ( 2 * V_52 ) )
V_27 |= V_60 ;
F_26 ( V_4 -> V_5 , V_61 , V_27 ) ;
V_27 = ( 0 << V_62 ) |
( 1 << V_63 ) |
( 1 << V_64 ) |
V_65 |
V_66 ;
if ( V_9 -> V_12 == V_13 ) {
V_27 |= V_67 ;
V_50 = V_68 ;
} else {
V_27 |= V_69 ;
V_50 = V_70 ;
}
F_26 ( V_4 -> V_5 , V_50 , V_27 ) ;
V_27 = ( 1 << V_71 ) |
( 1 << V_72 ) ;
F_26 ( V_4 -> V_5 , V_73 , V_27 ) ;
return 0 ;
}
static void F_27 ( struct V_3 * V_4 )
{
F_28 ( V_4 -> V_14 ) ;
F_19 ( V_4 -> V_5 , V_47 ,
V_74 ,
V_74 ) ;
}
static void F_29 ( struct V_3 * V_4 )
{
F_30 ( V_4 -> V_14 ) ;
F_19 ( V_4 -> V_5 , V_47 ,
V_74 , 0 ) ;
}
static void F_31 ( struct V_3 * V_4 )
{
F_32 ( V_4 -> V_22 ) ;
F_19 ( V_4 -> V_5 , V_47 ,
V_75 ,
V_75 ) ;
}
static void F_33 ( struct V_3 * V_4 )
{
F_34 ( V_4 -> V_22 ) ;
F_19 ( V_4 -> V_5 , V_47 ,
V_75 , 0 ) ;
}
static int F_35 ( struct V_8 * V_9 , int V_76 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = F_9 ( V_11 ) ;
switch ( V_76 ) {
case V_77 :
case V_78 :
case V_79 :
if ( V_9 -> V_12 == V_13 )
F_27 ( V_4 ) ;
else
F_31 ( V_4 ) ;
break;
case V_80 :
case V_81 :
case V_82 :
if ( V_9 -> V_12 == V_13 )
F_29 ( V_4 ) ;
else
F_33 ( V_4 ) ;
break;
default:
return - V_30 ;
}
return 0 ;
}
static int F_36 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = F_9 ( V_11 ) ;
V_11 -> V_23 = & V_4 -> V_23 ;
V_11 -> V_15 = & V_4 -> V_15 ;
return 0 ;
}
static bool F_37 ( struct V_1 * V_2 , unsigned int V_50 )
{
switch ( V_50 ) {
case V_47 :
case V_61 :
case V_73 :
case V_83 :
case V_84 :
case V_68 :
case V_70 :
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
case V_99 :
return true ;
default:
return false ;
} ;
}
static bool F_38 ( struct V_1 * V_2 , unsigned int V_50 )
{
switch ( V_50 ) {
case V_87 :
case V_88 :
case V_89 :
case V_90 :
return true ;
default:
return false ;
} ;
}
static int F_39 ( struct V_100 * V_101 )
{
struct V_3 * V_4 ;
T_1 V_102 [ 2 ] ;
struct V_103 * V_104 , * V_105 ;
void T_2 * V_106 ;
int V_7 ;
V_4 = F_40 ( & V_101 -> V_2 , sizeof( struct V_3 ) , V_107 ) ;
if ( ! V_4 ) {
F_7 ( & V_101 -> V_2 , L_3 ) ;
V_7 = - V_108 ;
goto V_109;
}
F_41 ( & V_101 -> V_2 , V_4 ) ;
V_4 -> V_11 = V_110 ;
V_4 -> V_11 . V_111 = F_42 ( & V_101 -> V_2 ) ;
V_7 = F_43 ( V_101 -> V_2 . V_112 ,
L_4 , V_102 ,
F_44 ( V_102 ) ) ;
if ( V_7 < 0 )
goto V_109;
V_4 -> V_21 = V_102 [ 0 ] ;
V_4 -> V_24 = V_102 [ 1 ] ;
V_4 -> V_6 = F_45 ( & V_101 -> V_2 , NULL ) ;
if ( F_46 ( V_4 -> V_6 ) ) {
F_7 ( & V_101 -> V_2 , L_5 ) ;
V_7 = F_47 ( V_4 -> V_6 ) ;
goto V_109;
}
V_104 = F_48 ( V_101 , V_113 , 0 ) ;
if ( ! V_104 ) {
F_7 ( & V_101 -> V_2 , L_6 ) ;
V_7 = - V_114 ;
goto V_115;
}
V_105 = F_49 ( & V_101 -> V_2 , V_104 -> V_116 ,
F_50 ( V_104 ) , V_117 ) ;
if ( ! V_105 ) {
F_7 ( & V_101 -> V_2 , L_7 ) ;
V_7 = - V_118 ;
goto V_115;
}
V_106 = F_51 ( & V_101 -> V_2 , V_104 -> V_116 , F_50 ( V_104 ) ) ;
if ( ! V_106 ) {
F_7 ( & V_101 -> V_2 , L_8 ) ;
V_7 = - V_108 ;
goto V_115;
}
V_4 -> V_5 = F_52 ( & V_101 -> V_2 , V_106 ,
& V_119 ) ;
if ( F_46 ( V_4 -> V_5 ) ) {
F_7 ( & V_101 -> V_2 , L_9 ) ;
V_7 = F_47 ( V_4 -> V_5 ) ;
goto V_115;
}
F_3 ( V_4 -> V_5 , true ) ;
F_53 ( & V_101 -> V_2 ) ;
if ( ! F_54 ( & V_101 -> V_2 ) ) {
V_7 = F_5 ( & V_101 -> V_2 ) ;
if ( V_7 )
goto V_120;
}
V_7 = F_55 ( & V_101 -> V_2 , & V_121 ,
& V_4 -> V_11 , 1 ) ;
if ( V_7 ) {
F_7 ( & V_101 -> V_2 , L_10 , V_7 ) ;
V_7 = - V_108 ;
goto V_122;
}
V_7 = F_56 ( & V_101 -> V_2 ) ;
if ( V_7 ) {
F_7 ( & V_101 -> V_2 , L_11 , V_7 ) ;
goto V_123;
}
return 0 ;
V_123:
F_57 ( & V_101 -> V_2 ) ;
V_122:
if ( ! F_58 ( & V_101 -> V_2 ) )
F_1 ( & V_101 -> V_2 ) ;
V_120:
F_59 ( & V_101 -> V_2 ) ;
V_115:
F_60 ( V_4 -> V_6 ) ;
V_109:
return V_7 ;
}
static int F_61 ( struct V_100 * V_101 )
{
struct V_3 * V_4 = F_2 ( & V_101 -> V_2 ) ;
F_59 ( & V_101 -> V_2 ) ;
if ( ! F_58 ( & V_101 -> V_2 ) )
F_1 ( & V_101 -> V_2 ) ;
F_62 ( & V_101 -> V_2 ) ;
F_57 ( & V_101 -> V_2 ) ;
F_60 ( V_4 -> V_6 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_64 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
V_7 = F_18 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_66 ( V_4 -> V_5 ) ;
F_20 ( V_2 ) ;
return V_7 ;
}
