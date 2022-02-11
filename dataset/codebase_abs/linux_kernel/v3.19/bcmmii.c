static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_8 = F_2 ( V_7 ) ;
T_1 V_10 ;
F_3 ( V_8 , ( V_11 | ( V_3 << V_12 ) |
( V_4 << V_13 ) ) , V_14 ) ;
V_10 = F_4 ( V_8 , V_14 ) ;
V_10 |= V_15 ;
F_3 ( V_8 , V_10 , V_14 ) ;
F_5 ( V_8 -> V_16 ,
! ( F_4 ( V_8 , V_14 )
& V_15 ) ,
V_17 / 100 ) ;
V_5 = F_4 ( V_8 , V_14 ) ;
if ( V_5 & V_18 )
return - V_19 ;
return V_5 & 0xffff ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 ,
int V_4 , T_2 V_20 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_8 = F_2 ( V_7 ) ;
T_1 V_10 ;
F_3 ( V_8 , ( V_21 | ( V_3 << V_12 ) |
( V_4 << V_13 ) | ( 0xffff & V_20 ) ) ,
V_14 ) ;
V_10 = F_4 ( V_8 , V_14 ) ;
V_10 |= V_15 ;
F_3 ( V_8 , V_10 , V_14 ) ;
F_5 ( V_8 -> V_16 ,
! ( F_4 ( V_8 , V_14 ) &
V_15 ) ,
V_17 / 100 ) ;
return 0 ;
}
void F_7 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
struct V_22 * V_23 = V_8 -> V_23 ;
T_1 V_10 , V_24 = 0 ;
bool V_25 = false ;
if ( V_8 -> V_26 != V_23 -> V_27 ) {
V_25 = true ;
V_8 -> V_26 = V_23 -> V_27 ;
}
if ( V_23 -> V_27 ) {
if ( V_8 -> V_28 != V_23 -> V_29 ) {
V_25 = true ;
V_8 -> V_28 = V_23 -> V_29 ;
}
if ( V_8 -> V_30 != V_23 -> V_31 ) {
V_25 = true ;
V_8 -> V_30 = V_23 -> V_31 ;
}
if ( V_8 -> V_32 != V_23 -> V_33 ) {
V_25 = true ;
V_8 -> V_32 = V_23 -> V_33 ;
}
if ( ! V_25 )
return;
if ( V_23 -> V_29 == V_34 )
V_24 = V_35 ;
else if ( V_23 -> V_29 == V_36 )
V_24 = V_37 ;
else
V_24 = V_38 ;
V_24 <<= V_39 ;
if ( V_23 -> V_31 != V_40 )
V_24 |= V_41 ;
if ( ! V_23 -> V_33 )
V_24 |= V_42 | V_43 ;
V_10 = F_8 ( V_8 , V_44 ) ;
V_10 &= ~ V_45 ;
V_10 |= V_46 ;
F_9 ( V_8 , V_10 , V_44 ) ;
V_10 = F_4 ( V_8 , V_47 ) ;
V_10 &= ~ ( ( V_48 << V_39 ) |
V_41 |
V_42 | V_43 ) ;
V_10 |= V_24 ;
F_3 ( V_8 , V_10 , V_47 ) ;
} else {
if ( ! V_25 )
return;
F_10 ( V_7 ) ;
}
F_11 ( V_23 ) ;
}
void F_12 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
if ( V_8 -> V_23 ) {
F_13 ( V_8 -> V_23 ) ;
F_14 ( V_8 -> V_23 ) ;
}
}
static void F_15 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
T_1 V_10 = 0 ;
if ( ! F_16 ( V_8 ) )
return;
V_10 = F_8 ( V_8 , V_49 ) ;
V_10 &= ~ ( V_50 | V_51 ) ;
V_10 |= V_52 ;
F_9 ( V_8 , V_10 , V_49 ) ;
F_17 ( 2 ) ;
V_10 &= ~ V_52 ;
F_9 ( V_8 , V_10 , V_49 ) ;
F_18 ( 20 ) ;
}
static void F_19 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
T_1 V_10 ;
F_15 ( V_7 ) ;
V_10 = F_8 ( V_8 , V_53 ) ;
V_10 |= V_54 ;
F_9 ( V_8 , V_10 , V_53 ) ;
F_12 ( V_7 ) ;
}
static void F_20 ( struct V_9 * V_8 )
{
T_1 V_10 ;
V_10 = F_21 ( V_8 , V_55 ) ;
V_10 |= V_56 ;
F_22 ( V_8 , V_10 , V_55 ) ;
}
int F_23 ( struct V_6 * V_7 , bool V_57 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
struct V_22 * V_23 = V_8 -> V_23 ;
struct V_58 * V_59 = & V_8 -> V_60 -> V_7 ;
const char * V_61 = NULL ;
T_1 V_62 = 0 ;
T_1 V_63 ;
T_1 V_10 ;
V_8 -> V_64 = ! F_24 ( V_8 -> V_23 ) &&
( V_8 -> V_65 != V_66 ) ;
if ( F_24 ( V_8 -> V_23 ) )
V_8 -> V_65 = V_67 ;
switch ( V_8 -> V_65 ) {
case V_67 :
case V_66 :
if ( F_16 ( V_8 ) )
V_63 = V_68 ;
else
V_63 = V_69 ;
F_22 ( V_8 , V_63 , V_55 ) ;
if ( F_24 ( V_8 -> V_23 ) ) {
V_61 = L_1 ;
F_19 ( V_7 ) ;
} else if ( V_8 -> V_65 == V_66 ) {
V_61 = L_2 ;
F_20 ( V_8 ) ;
}
break;
case V_70 :
V_61 = L_3 ;
V_23 -> V_71 &= V_72 ;
F_22 ( V_8 ,
V_73 , V_55 ) ;
break;
case V_74 :
V_61 = L_4 ;
if ( ( V_8 -> V_23 -> V_71 & V_72 ) ==
V_72 )
V_63 = V_75 ;
else
V_63 = V_76 ;
F_22 ( V_8 , V_63 , V_55 ) ;
break;
case V_77 :
V_62 = F_25 ( 16 ) ;
case V_78 :
if ( V_62 )
V_61 = L_5 ;
else
V_61 = L_6 ;
V_10 = F_8 ( V_8 , V_44 ) ;
V_10 |= V_79 | V_62 ;
F_9 ( V_8 , V_10 , V_44 ) ;
F_22 ( V_8 ,
V_80 , V_55 ) ;
break;
default:
F_26 ( V_59 , L_7 , V_8 -> V_65 ) ;
return - V_81 ;
}
if ( V_57 )
F_27 ( V_59 , L_8 , V_61 ) ;
return 0 ;
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
struct V_82 * V_83 = V_8 -> V_60 -> V_7 . V_84 ;
struct V_22 * V_23 ;
T_1 V_85 ;
int V_5 ;
V_85 = V_8 -> V_86 ;
V_8 -> V_26 = - 1 ;
V_8 -> V_28 = - 1 ;
V_8 -> V_30 = - 1 ;
V_8 -> V_32 = - 1 ;
if ( V_83 ) {
if ( V_8 -> V_23 ) {
F_29 ( L_9 ) ;
return 0 ;
}
if ( ! V_8 -> V_87 && F_30 ( V_83 ) ) {
V_5 = F_31 ( V_83 ) ;
if ( V_5 )
return V_5 ;
V_8 -> V_87 = F_32 ( V_83 ) ;
}
V_23 = F_33 ( V_7 , V_8 -> V_87 , F_7 ,
V_85 , V_8 -> V_65 ) ;
if ( ! V_23 ) {
F_34 ( L_10 ) ;
return - V_88 ;
}
} else {
V_23 = V_8 -> V_23 ;
V_23 -> V_89 = V_85 ;
V_5 = F_35 ( V_7 , V_23 , F_7 ,
V_8 -> V_65 ) ;
if ( V_5 ) {
F_34 ( L_10 ) ;
return - V_88 ;
}
}
V_8 -> V_23 = V_23 ;
V_5 = F_23 ( V_7 , true ) ;
if ( V_5 ) {
F_36 ( V_8 -> V_23 ) ;
return V_5 ;
}
V_23 -> V_90 = V_23 -> V_71 ;
if ( F_24 ( V_8 -> V_23 ) )
V_8 -> V_1 -> V_91 [ V_23 -> V_92 ] = V_93 ;
else
V_8 -> V_1 -> V_91 [ V_23 -> V_92 ] = V_94 ;
F_29 ( L_11 ,
V_23 -> V_92 , V_23 -> V_95 -> V_96 ) ;
return 0 ;
}
static int F_37 ( struct V_9 * V_8 )
{
struct V_1 * V_2 ;
if ( V_8 -> V_1 )
return 0 ;
V_8 -> V_1 = F_38 () ;
if ( ! V_8 -> V_1 ) {
F_34 ( L_12 ) ;
return - V_97 ;
}
V_2 = V_8 -> V_1 ;
V_2 -> V_8 = V_8 -> V_7 ;
V_2 -> V_96 = L_13 ;
V_2 -> V_98 = & V_8 -> V_60 -> V_7 ;
V_2 -> V_99 = F_1 ;
V_2 -> V_100 = F_6 ;
snprintf ( V_2 -> V_101 , V_102 , L_14 ,
V_8 -> V_60 -> V_96 , V_8 -> V_60 -> V_101 ) ;
V_2 -> V_91 = F_39 ( V_103 , sizeof( int ) , V_104 ) ;
if ( ! V_2 -> V_91 ) {
F_40 ( V_8 -> V_1 ) ;
return - V_97 ;
}
return 0 ;
}
static int F_41 ( struct V_9 * V_8 )
{
struct V_82 * V_83 = V_8 -> V_60 -> V_7 . V_84 ;
struct V_58 * V_59 = & V_8 -> V_60 -> V_7 ;
struct V_82 * V_105 ;
char * V_106 ;
int V_5 ;
V_106 = F_42 ( V_104 , L_15 , V_8 -> V_107 ) ;
if ( ! V_106 )
return - V_97 ;
V_105 = F_43 ( V_83 , NULL , V_106 ) ;
F_44 ( V_106 ) ;
if ( ! V_105 ) {
F_26 ( V_59 , L_16 ) ;
return - V_88 ;
}
V_5 = F_45 ( V_8 -> V_1 , V_105 ) ;
if ( V_5 ) {
F_26 ( V_59 , L_17 ) ;
return V_5 ;
}
V_8 -> V_87 = F_46 ( V_83 , L_18 , 0 ) ;
V_8 -> V_65 = F_47 ( V_83 ) ;
return 0 ;
}
static int F_48 ( struct V_9 * V_8 )
{
struct V_58 * V_59 = & V_8 -> V_60 -> V_7 ;
struct V_108 * V_109 = V_59 -> V_110 ;
struct V_1 * V_111 = V_8 -> V_1 ;
struct V_22 * V_23 ;
int V_5 ;
if ( V_109 -> V_65 != V_66 && V_109 -> V_112 ) {
if ( V_109 -> V_113 >= 0 && V_109 -> V_113 < V_103 )
V_111 -> V_114 = ~ ( 1 << V_109 -> V_113 ) ;
else
V_111 -> V_114 = 0 ;
V_5 = F_49 ( V_111 ) ;
if ( V_5 ) {
F_26 ( V_59 , L_17 ) ;
return V_5 ;
}
if ( V_109 -> V_113 >= 0 && V_109 -> V_113 < V_103 )
V_23 = V_111 -> V_115 [ V_109 -> V_113 ] ;
else
V_23 = F_50 ( V_111 ) ;
if ( ! V_23 ) {
F_26 ( V_59 , L_19 ) ;
F_51 ( V_111 ) ;
return - V_88 ;
}
} else {
struct V_116 V_117 = {
. V_27 = 1 ,
. V_29 = V_109 -> V_118 ,
. V_31 = V_109 -> V_119 ,
. V_33 = 0 ,
. V_120 = 0 ,
} ;
V_23 = F_52 ( V_94 , & V_117 , NULL ) ;
if ( ! V_23 || F_53 ( V_23 ) ) {
F_26 ( V_59 , L_20 ) ;
return - V_88 ;
}
}
V_8 -> V_23 = V_23 ;
V_8 -> V_65 = V_109 -> V_65 ;
return 0 ;
}
static int F_54 ( struct V_9 * V_8 )
{
struct V_82 * V_83 = V_8 -> V_60 -> V_7 . V_84 ;
if ( V_83 )
return F_41 ( V_8 ) ;
else
return F_48 ( V_8 ) ;
}
int F_55 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
int V_5 ;
V_5 = F_37 ( V_8 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_54 ( V_8 ) ;
if ( V_5 )
goto V_121;
V_5 = F_28 ( V_7 ) ;
if ( V_5 )
goto V_122;
return 0 ;
V_122:
F_56 ( V_8 -> V_87 ) ;
F_51 ( V_8 -> V_1 ) ;
V_121:
F_44 ( V_8 -> V_1 -> V_91 ) ;
F_40 ( V_8 -> V_1 ) ;
return V_5 ;
}
void F_57 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
F_56 ( V_8 -> V_87 ) ;
F_51 ( V_8 -> V_1 ) ;
F_44 ( V_8 -> V_1 -> V_91 ) ;
F_40 ( V_8 -> V_1 ) ;
}
