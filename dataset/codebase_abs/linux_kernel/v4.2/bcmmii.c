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
if ( ! ( V_2 -> V_18 & 1 << V_3 ) && ( V_5 & V_19 ) )
return - V_20 ;
return V_5 & 0xffff ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 ,
int V_4 , T_2 V_21 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_8 = F_2 ( V_7 ) ;
T_1 V_10 ;
F_3 ( V_8 , ( V_22 | ( V_3 << V_12 ) |
( V_4 << V_13 ) | ( 0xffff & V_21 ) ) ,
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
struct V_23 * V_24 = V_8 -> V_24 ;
T_1 V_10 , V_25 = 0 ;
bool V_26 = false ;
if ( V_8 -> V_27 != V_24 -> V_28 ) {
V_26 = true ;
V_8 -> V_27 = V_24 -> V_28 ;
}
if ( V_24 -> V_28 ) {
if ( V_8 -> V_29 != V_24 -> V_30 ) {
V_26 = true ;
V_8 -> V_29 = V_24 -> V_30 ;
}
if ( V_8 -> V_31 != V_24 -> V_32 ) {
V_26 = true ;
V_8 -> V_31 = V_24 -> V_32 ;
}
if ( V_8 -> V_33 != V_24 -> V_34 ) {
V_26 = true ;
V_8 -> V_33 = V_24 -> V_34 ;
}
if ( ! V_26 )
return;
if ( V_24 -> V_30 == V_35 )
V_25 = V_36 ;
else if ( V_24 -> V_30 == V_37 )
V_25 = V_38 ;
else
V_25 = V_39 ;
V_25 <<= V_40 ;
if ( V_24 -> V_32 != V_41 )
V_25 |= V_42 ;
if ( ! V_24 -> V_34 )
V_25 |= V_43 | V_44 ;
V_10 = F_8 ( V_8 , V_45 ) ;
V_10 &= ~ V_46 ;
V_10 |= V_47 ;
F_9 ( V_8 , V_10 , V_45 ) ;
V_10 = F_4 ( V_8 , V_48 ) ;
V_10 &= ~ ( ( V_49 << V_40 ) |
V_42 |
V_43 | V_44 ) ;
V_10 |= V_25 ;
F_3 ( V_8 , V_10 , V_48 ) ;
} else {
if ( ! V_26 )
return;
F_10 ( V_7 ) ;
}
F_11 ( V_24 ) ;
}
void F_12 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
if ( V_8 -> V_24 ) {
F_13 ( V_8 -> V_24 ) ;
F_14 ( V_8 -> V_24 ) ;
}
}
void F_15 ( struct V_6 * V_7 , bool V_50 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
T_1 V_10 = 0 ;
if ( ! F_16 ( V_8 ) )
return;
V_10 = F_8 ( V_8 , V_51 ) ;
if ( V_50 ) {
V_10 &= ~ V_52 ;
F_9 ( V_8 , V_10 , V_51 ) ;
F_17 ( 1 ) ;
V_10 &= ~ ( V_53 | V_54 ) ;
V_10 |= V_55 ;
F_9 ( V_8 , V_10 , V_51 ) ;
F_17 ( 1 ) ;
V_10 &= ~ V_55 ;
} else {
V_10 |= V_53 | V_54 | V_55 ;
F_9 ( V_8 , V_10 , V_51 ) ;
F_17 ( 1 ) ;
V_10 |= V_52 ;
}
F_9 ( V_8 , V_10 , V_51 ) ;
F_18 ( 60 ) ;
}
static void F_19 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
T_1 V_10 ;
F_15 ( V_7 , true ) ;
V_10 = F_8 ( V_8 , V_56 ) ;
V_10 |= V_57 ;
F_9 ( V_8 , V_10 , V_56 ) ;
F_12 ( V_7 ) ;
}
static void F_20 ( struct V_9 * V_8 )
{
T_1 V_10 ;
V_10 = F_21 ( V_8 , V_58 ) ;
V_10 |= V_59 ;
F_22 ( V_8 , V_10 , V_58 ) ;
}
int F_23 ( struct V_6 * V_7 , bool V_60 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
struct V_23 * V_24 = V_8 -> V_24 ;
struct V_61 * V_62 = & V_8 -> V_63 -> V_7 ;
const char * V_64 = NULL ;
T_1 V_65 = 0 ;
T_1 V_66 ;
T_1 V_10 ;
V_8 -> V_67 = ! F_24 ( V_8 -> V_24 ) &&
( V_8 -> V_68 != V_69 ) ;
if ( F_24 ( V_8 -> V_24 ) )
V_8 -> V_68 = V_70 ;
switch ( V_8 -> V_68 ) {
case V_70 :
case V_69 :
if ( F_16 ( V_8 ) )
V_66 = V_71 ;
else
V_66 = V_72 ;
F_22 ( V_8 , V_66 , V_58 ) ;
if ( F_24 ( V_8 -> V_24 ) ) {
V_64 = L_1 ;
F_19 ( V_7 ) ;
} else if ( V_8 -> V_68 == V_69 ) {
V_64 = L_2 ;
F_20 ( V_8 ) ;
}
break;
case V_73 :
V_64 = L_3 ;
V_24 -> V_74 &= V_75 ;
F_22 ( V_8 ,
V_76 , V_58 ) ;
break;
case V_77 :
V_64 = L_4 ;
if ( ( V_8 -> V_24 -> V_74 & V_75 ) ==
V_75 )
V_66 = V_78 ;
else
V_66 = V_79 ;
F_22 ( V_8 , V_66 , V_58 ) ;
break;
case V_80 :
V_65 = F_25 ( 16 ) ;
case V_81 :
if ( V_65 )
V_64 = L_5 ;
else
V_64 = L_6 ;
F_22 ( V_8 ,
V_82 , V_58 ) ;
break;
default:
F_26 ( V_62 , L_7 , V_8 -> V_68 ) ;
return - V_83 ;
}
if ( V_8 -> V_67 ) {
V_10 = F_8 ( V_8 , V_45 ) ;
V_10 |= V_84 | V_65 ;
F_9 ( V_8 , V_10 , V_45 ) ;
}
if ( V_60 )
F_27 ( V_62 , L_8 , V_64 ) ;
return 0 ;
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
struct V_85 * V_86 = V_8 -> V_63 -> V_7 . V_87 ;
struct V_23 * V_24 ;
T_1 V_88 ;
int V_5 ;
V_88 = V_8 -> V_89 ;
V_8 -> V_27 = - 1 ;
V_8 -> V_29 = - 1 ;
V_8 -> V_31 = - 1 ;
V_8 -> V_33 = - 1 ;
if ( V_86 ) {
if ( V_8 -> V_24 ) {
F_29 ( L_9 ) ;
return 0 ;
}
if ( ! V_8 -> V_90 && F_30 ( V_86 ) ) {
V_5 = F_31 ( V_86 ) ;
if ( V_5 )
return V_5 ;
V_8 -> V_90 = F_32 ( V_86 ) ;
}
V_24 = F_33 ( V_7 , V_8 -> V_90 , F_7 ,
V_88 , V_8 -> V_68 ) ;
if ( ! V_24 ) {
F_34 ( L_10 ) ;
return - V_91 ;
}
} else {
V_24 = V_8 -> V_24 ;
V_24 -> V_92 = V_88 ;
V_5 = F_35 ( V_7 , V_24 , F_7 ,
V_8 -> V_68 ) ;
if ( V_5 ) {
F_34 ( L_10 ) ;
return - V_91 ;
}
}
V_8 -> V_24 = V_24 ;
V_5 = F_23 ( V_7 , true ) ;
if ( V_5 ) {
F_36 ( V_8 -> V_24 ) ;
return V_5 ;
}
V_24 -> V_93 = V_24 -> V_74 ;
if ( F_24 ( V_8 -> V_24 ) )
V_8 -> V_1 -> V_94 [ V_24 -> V_95 ] = V_96 ;
else
V_8 -> V_1 -> V_94 [ V_24 -> V_95 ] = V_97 ;
F_29 ( L_11 ,
V_24 -> V_95 , V_24 -> V_98 -> V_99 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_8 = F_2 ( V_7 ) ;
struct V_85 * V_100 = V_8 -> V_101 ;
struct V_85 * V_102 = NULL ;
T_1 V_103 = 0 ;
int V_95 = 0 ;
if ( ! V_100 ) {
V_103 = 1 << V_8 -> V_104 ;
} else {
F_38 (np, child) {
V_95 = F_39 ( & V_7 -> V_7 , V_102 ) ;
if ( V_95 < 0 )
continue;
V_103 |= 1 << V_95 ;
}
}
for ( V_95 = 0 ; V_95 < V_105 ; V_95 ++ ) {
if ( V_103 & 1 << V_95 ) {
F_40 ( & V_7 -> V_7 , L_12 , V_95 ) ;
F_41 ( V_2 , V_95 , V_106 ) ;
}
}
return 0 ;
}
static int F_42 ( struct V_9 * V_8 )
{
struct V_1 * V_2 ;
if ( V_8 -> V_1 )
return 0 ;
V_8 -> V_1 = F_43 () ;
if ( ! V_8 -> V_1 ) {
F_34 ( L_13 ) ;
return - V_107 ;
}
V_2 = V_8 -> V_1 ;
V_2 -> V_8 = V_8 -> V_7 ;
V_2 -> V_99 = L_14 ;
V_2 -> V_108 = & V_8 -> V_63 -> V_7 ;
V_2 -> V_109 = F_1 ;
V_2 -> V_110 = F_6 ;
V_2 -> V_111 = F_37 ;
snprintf ( V_2 -> V_112 , V_113 , L_15 ,
V_8 -> V_63 -> V_99 , V_8 -> V_63 -> V_112 ) ;
V_2 -> V_94 = F_44 ( V_105 , sizeof( int ) , V_114 ) ;
if ( ! V_2 -> V_94 ) {
F_45 ( V_8 -> V_1 ) ;
return - V_107 ;
}
return 0 ;
}
static int F_46 ( struct V_9 * V_8 )
{
struct V_85 * V_86 = V_8 -> V_63 -> V_7 . V_87 ;
struct V_61 * V_62 = & V_8 -> V_63 -> V_7 ;
char * V_115 ;
int V_5 ;
V_115 = F_47 ( V_114 , L_16 , V_8 -> V_116 ) ;
if ( ! V_115 )
return - V_107 ;
V_8 -> V_101 = F_48 ( V_86 , NULL , V_115 ) ;
F_49 ( V_115 ) ;
if ( ! V_8 -> V_101 ) {
F_26 ( V_62 , L_17 ) ;
return - V_91 ;
}
V_5 = F_50 ( V_8 -> V_1 , V_8 -> V_101 ) ;
if ( V_5 ) {
F_26 ( V_62 , L_18 ) ;
return V_5 ;
}
V_8 -> V_90 = F_51 ( V_86 , L_19 , 0 ) ;
V_8 -> V_68 = F_52 ( V_86 ) ;
return 0 ;
}
static int F_53 ( struct V_6 * V_7 ,
struct V_117 * V_118 )
{
if ( V_7 && V_7 -> V_24 && V_118 )
V_118 -> V_28 = V_7 -> V_24 -> V_28 ;
return 0 ;
}
static int F_54 ( struct V_9 * V_8 )
{
struct V_61 * V_62 = & V_8 -> V_63 -> V_7 ;
struct V_119 * V_120 = V_62 -> V_121 ;
struct V_1 * V_122 = V_8 -> V_1 ;
struct V_23 * V_24 ;
int V_5 ;
if ( V_120 -> V_68 != V_69 && V_120 -> V_123 ) {
if ( V_120 -> V_124 >= 0 && V_120 -> V_124 < V_105 )
V_122 -> V_125 = ~ ( 1 << V_120 -> V_124 ) ;
else
V_122 -> V_125 = 0 ;
V_5 = F_55 ( V_122 ) ;
if ( V_5 ) {
F_26 ( V_62 , L_18 ) ;
return V_5 ;
}
if ( V_120 -> V_124 >= 0 && V_120 -> V_124 < V_105 )
V_24 = V_122 -> V_126 [ V_120 -> V_124 ] ;
else
V_24 = F_56 ( V_122 ) ;
if ( ! V_24 ) {
F_26 ( V_62 , L_20 ) ;
F_57 ( V_122 ) ;
return - V_91 ;
}
} else {
struct V_117 V_127 = {
. V_28 = 1 ,
. V_30 = V_120 -> V_128 ,
. V_32 = V_120 -> V_129 ,
. V_34 = 0 ,
. V_130 = 0 ,
} ;
V_24 = F_58 ( V_97 , & V_127 , NULL ) ;
if ( ! V_24 || F_59 ( V_24 ) ) {
F_26 ( V_62 , L_21 ) ;
return - V_91 ;
}
if ( V_8 -> V_131 -> V_132 & V_133 ) {
V_5 = F_60 (
V_24 , F_53 ) ;
if ( ! V_5 )
V_24 -> V_28 = 0 ;
}
}
V_8 -> V_24 = V_24 ;
V_8 -> V_68 = V_120 -> V_68 ;
return 0 ;
}
static int F_61 ( struct V_9 * V_8 )
{
struct V_85 * V_86 = V_8 -> V_63 -> V_7 . V_87 ;
if ( V_86 )
return F_46 ( V_8 ) ;
else
return F_54 ( V_8 ) ;
}
int F_62 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
int V_5 ;
V_5 = F_42 ( V_8 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_61 ( V_8 ) ;
if ( V_5 )
goto V_134;
V_5 = F_28 ( V_7 ) ;
if ( V_5 )
goto V_135;
return 0 ;
V_135:
F_63 ( V_8 -> V_90 ) ;
F_57 ( V_8 -> V_1 ) ;
V_134:
F_49 ( V_8 -> V_1 -> V_94 ) ;
F_45 ( V_8 -> V_1 ) ;
return V_5 ;
}
void F_64 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
F_63 ( V_8 -> V_90 ) ;
F_57 ( V_8 -> V_1 ) ;
F_49 ( V_8 -> V_1 -> V_94 ) ;
F_45 ( V_8 -> V_1 ) ;
}
