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
void F_15 ( struct V_6 * V_7 , bool V_49 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
T_1 V_10 = 0 ;
if ( ! F_16 ( V_8 ) )
return;
V_10 = F_8 ( V_8 , V_50 ) ;
if ( V_49 ) {
V_10 &= ~ V_51 ;
F_9 ( V_8 , V_10 , V_50 ) ;
F_17 ( 1 ) ;
V_10 &= ~ ( V_52 | V_53 ) ;
V_10 |= V_54 ;
F_9 ( V_8 , V_10 , V_50 ) ;
F_17 ( 1 ) ;
V_10 &= ~ V_54 ;
} else {
V_10 |= V_52 | V_53 | V_54 ;
F_9 ( V_8 , V_10 , V_50 ) ;
F_17 ( 1 ) ;
V_10 |= V_51 ;
}
F_9 ( V_8 , V_10 , V_50 ) ;
F_18 ( 60 ) ;
}
static void F_19 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
T_1 V_10 ;
F_15 ( V_7 , true ) ;
V_10 = F_8 ( V_8 , V_55 ) ;
V_10 |= V_56 ;
F_9 ( V_8 , V_10 , V_55 ) ;
F_12 ( V_7 ) ;
}
static void F_20 ( struct V_9 * V_8 )
{
T_1 V_10 ;
V_10 = F_21 ( V_8 , V_57 ) ;
V_10 |= V_58 ;
F_22 ( V_8 , V_10 , V_57 ) ;
}
int F_23 ( struct V_6 * V_7 , bool V_59 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
struct V_22 * V_23 = V_8 -> V_23 ;
struct V_60 * V_61 = & V_8 -> V_62 -> V_7 ;
const char * V_63 = NULL ;
T_1 V_64 = 0 ;
T_1 V_65 ;
T_1 V_10 ;
V_8 -> V_66 = ! F_24 ( V_8 -> V_23 ) &&
( V_8 -> V_67 != V_68 ) ;
if ( F_24 ( V_8 -> V_23 ) )
V_8 -> V_67 = V_69 ;
switch ( V_8 -> V_67 ) {
case V_69 :
case V_68 :
if ( F_16 ( V_8 ) )
V_65 = V_70 ;
else
V_65 = V_71 ;
F_22 ( V_8 , V_65 , V_57 ) ;
if ( F_24 ( V_8 -> V_23 ) ) {
V_63 = L_1 ;
F_19 ( V_7 ) ;
} else if ( V_8 -> V_67 == V_68 ) {
V_63 = L_2 ;
F_20 ( V_8 ) ;
}
break;
case V_72 :
V_63 = L_3 ;
V_23 -> V_73 &= V_74 ;
F_22 ( V_8 ,
V_75 , V_57 ) ;
break;
case V_76 :
V_63 = L_4 ;
if ( ( V_8 -> V_23 -> V_73 & V_74 ) ==
V_74 )
V_65 = V_77 ;
else
V_65 = V_78 ;
F_22 ( V_8 , V_65 , V_57 ) ;
break;
case V_79 :
V_64 = F_25 ( 16 ) ;
case V_80 :
if ( V_64 )
V_63 = L_5 ;
else
V_63 = L_6 ;
F_22 ( V_8 ,
V_81 , V_57 ) ;
break;
default:
F_26 ( V_61 , L_7 , V_8 -> V_67 ) ;
return - V_82 ;
}
if ( V_8 -> V_66 ) {
V_10 = F_8 ( V_8 , V_44 ) ;
V_10 |= V_83 | V_64 ;
F_9 ( V_8 , V_10 , V_44 ) ;
}
if ( V_59 )
F_27 ( V_61 , L_8 , V_63 ) ;
return 0 ;
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
struct V_84 * V_85 = V_8 -> V_62 -> V_7 . V_86 ;
struct V_22 * V_23 ;
T_1 V_87 ;
int V_5 ;
V_87 = V_8 -> V_88 ;
V_8 -> V_26 = - 1 ;
V_8 -> V_28 = - 1 ;
V_8 -> V_30 = - 1 ;
V_8 -> V_32 = - 1 ;
if ( V_85 ) {
if ( V_8 -> V_23 ) {
F_29 ( L_9 ) ;
return 0 ;
}
if ( ! V_8 -> V_89 && F_30 ( V_85 ) ) {
V_5 = F_31 ( V_85 ) ;
if ( V_5 )
return V_5 ;
V_8 -> V_89 = F_32 ( V_85 ) ;
}
V_23 = F_33 ( V_7 , V_8 -> V_89 , F_7 ,
V_87 , V_8 -> V_67 ) ;
if ( ! V_23 ) {
F_34 ( L_10 ) ;
return - V_90 ;
}
} else {
V_23 = V_8 -> V_23 ;
V_23 -> V_91 = V_87 ;
V_5 = F_35 ( V_7 , V_23 , F_7 ,
V_8 -> V_67 ) ;
if ( V_5 ) {
F_34 ( L_10 ) ;
return - V_90 ;
}
}
V_8 -> V_23 = V_23 ;
V_5 = F_23 ( V_7 , true ) ;
if ( V_5 ) {
F_36 ( V_8 -> V_23 ) ;
return V_5 ;
}
V_23 -> V_92 = V_23 -> V_73 ;
if ( F_24 ( V_8 -> V_23 ) )
V_8 -> V_1 -> V_93 [ V_23 -> V_94 ] = V_95 ;
else
V_8 -> V_1 -> V_93 [ V_23 -> V_94 ] = V_96 ;
F_29 ( L_11 ,
V_23 -> V_94 , V_23 -> V_97 -> V_98 ) ;
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
return - V_99 ;
}
V_2 = V_8 -> V_1 ;
V_2 -> V_8 = V_8 -> V_7 ;
V_2 -> V_98 = L_13 ;
V_2 -> V_100 = & V_8 -> V_62 -> V_7 ;
V_2 -> V_101 = F_1 ;
V_2 -> V_102 = F_6 ;
snprintf ( V_2 -> V_103 , V_104 , L_14 ,
V_8 -> V_62 -> V_98 , V_8 -> V_62 -> V_103 ) ;
V_2 -> V_93 = F_39 ( V_105 , sizeof( int ) , V_106 ) ;
if ( ! V_2 -> V_93 ) {
F_40 ( V_8 -> V_1 ) ;
return - V_99 ;
}
return 0 ;
}
static int F_41 ( struct V_9 * V_8 )
{
struct V_84 * V_85 = V_8 -> V_62 -> V_7 . V_86 ;
struct V_60 * V_61 = & V_8 -> V_62 -> V_7 ;
struct V_84 * V_107 ;
char * V_108 ;
int V_5 ;
V_108 = F_42 ( V_106 , L_15 , V_8 -> V_109 ) ;
if ( ! V_108 )
return - V_99 ;
V_107 = F_43 ( V_85 , NULL , V_108 ) ;
F_44 ( V_108 ) ;
if ( ! V_107 ) {
F_26 ( V_61 , L_16 ) ;
return - V_90 ;
}
V_5 = F_45 ( V_8 -> V_1 , V_107 ) ;
if ( V_5 ) {
F_26 ( V_61 , L_17 ) ;
return V_5 ;
}
V_8 -> V_89 = F_46 ( V_85 , L_18 , 0 ) ;
V_8 -> V_67 = F_47 ( V_85 ) ;
return 0 ;
}
static int F_48 ( struct V_6 * V_7 ,
struct V_110 * V_111 )
{
if ( V_7 && V_7 -> V_23 && V_111 )
V_111 -> V_27 = V_7 -> V_23 -> V_27 ;
return 0 ;
}
static int F_49 ( struct V_9 * V_8 )
{
struct V_60 * V_61 = & V_8 -> V_62 -> V_7 ;
struct V_112 * V_113 = V_61 -> V_114 ;
struct V_1 * V_115 = V_8 -> V_1 ;
struct V_22 * V_23 ;
int V_5 ;
if ( V_113 -> V_67 != V_68 && V_113 -> V_116 ) {
if ( V_113 -> V_117 >= 0 && V_113 -> V_117 < V_105 )
V_115 -> V_118 = ~ ( 1 << V_113 -> V_117 ) ;
else
V_115 -> V_118 = 0 ;
V_5 = F_50 ( V_115 ) ;
if ( V_5 ) {
F_26 ( V_61 , L_17 ) ;
return V_5 ;
}
if ( V_113 -> V_117 >= 0 && V_113 -> V_117 < V_105 )
V_23 = V_115 -> V_119 [ V_113 -> V_117 ] ;
else
V_23 = F_51 ( V_115 ) ;
if ( ! V_23 ) {
F_26 ( V_61 , L_19 ) ;
F_52 ( V_115 ) ;
return - V_90 ;
}
} else {
struct V_110 V_120 = {
. V_27 = 1 ,
. V_29 = V_113 -> V_121 ,
. V_31 = V_113 -> V_122 ,
. V_33 = 0 ,
. V_123 = 0 ,
} ;
V_23 = F_53 ( V_96 , & V_120 , NULL ) ;
if ( ! V_23 || F_54 ( V_23 ) ) {
F_26 ( V_61 , L_20 ) ;
return - V_90 ;
}
if ( V_8 -> V_124 -> V_125 & V_126 ) {
V_5 = F_55 (
V_23 , F_48 ) ;
if ( ! V_5 )
V_23 -> V_27 = 0 ;
}
}
V_8 -> V_23 = V_23 ;
V_8 -> V_67 = V_113 -> V_67 ;
return 0 ;
}
static int F_56 ( struct V_9 * V_8 )
{
struct V_84 * V_85 = V_8 -> V_62 -> V_7 . V_86 ;
if ( V_85 )
return F_41 ( V_8 ) ;
else
return F_49 ( V_8 ) ;
}
int F_57 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
int V_5 ;
V_5 = F_37 ( V_8 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_56 ( V_8 ) ;
if ( V_5 )
goto V_127;
V_5 = F_28 ( V_7 ) ;
if ( V_5 )
goto V_128;
return 0 ;
V_128:
F_58 ( V_8 -> V_89 ) ;
F_52 ( V_8 -> V_1 ) ;
V_127:
F_44 ( V_8 -> V_1 -> V_93 ) ;
F_40 ( V_8 -> V_1 ) ;
return V_5 ;
}
void F_59 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
F_58 ( V_8 -> V_89 ) ;
F_52 ( V_8 -> V_1 ) ;
F_44 ( V_8 -> V_1 -> V_93 ) ;
F_40 ( V_8 -> V_1 ) ;
}
