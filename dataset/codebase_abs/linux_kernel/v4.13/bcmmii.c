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
static int F_12 ( struct V_6 * V_7 ,
struct V_50 * V_51 )
{
if ( V_7 && V_7 -> V_24 && V_51 )
V_51 -> V_28 = V_7 -> V_24 -> V_28 ;
return 0 ;
}
void F_13 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
if ( F_14 ( V_8 ) )
return;
if ( V_8 -> V_24 ) {
F_15 ( V_8 -> V_24 ) ;
F_16 ( V_8 -> V_24 ) ;
}
}
void F_17 ( struct V_6 * V_7 , bool V_52 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
T_1 V_10 = 0 ;
if ( F_14 ( V_8 ) ) {
V_10 = F_8 ( V_8 , V_53 ) ;
if ( V_52 ) {
V_10 &= ~ V_54 ;
F_9 ( V_8 , V_10 , V_53 ) ;
F_18 ( 1 ) ;
V_10 &= ~ ( V_55 | V_56 ) ;
V_10 |= V_57 ;
F_9 ( V_8 , V_10 , V_53 ) ;
F_18 ( 1 ) ;
V_10 &= ~ V_57 ;
} else {
V_10 |= V_55 | V_56 |
V_57 ;
F_9 ( V_8 , V_10 , V_53 ) ;
F_18 ( 1 ) ;
V_10 |= V_54 ;
}
F_9 ( V_8 , V_10 , V_53 ) ;
F_19 ( 60 ) ;
} else {
F_18 ( 1 ) ;
}
}
static void F_20 ( struct V_9 * V_8 )
{
T_1 V_10 ;
if ( ! F_21 ( V_8 ) ) {
V_10 = F_22 ( V_8 , V_58 ) ;
V_10 |= V_59 ;
F_23 ( V_8 , V_10 , V_58 ) ;
}
if ( V_8 -> V_60 -> V_61 & V_62 )
F_24 ( V_8 -> V_24 ,
F_12 ) ;
}
int F_25 ( struct V_6 * V_7 , bool V_63 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
struct V_23 * V_24 = V_8 -> V_24 ;
struct V_64 * V_65 = & V_8 -> V_66 -> V_7 ;
const char * V_67 = NULL ;
T_1 V_68 = 0 ;
T_1 V_69 ;
T_1 V_10 ;
V_8 -> V_70 = ! V_8 -> V_71 &&
( V_8 -> V_72 != V_73 ) ;
switch ( V_8 -> V_72 ) {
case V_74 :
case V_73 :
if ( F_14 ( V_8 ) )
V_69 = V_75 ;
else
V_69 = V_76 ;
F_23 ( V_8 , V_69 , V_58 ) ;
if ( V_8 -> V_71 ) {
V_67 = L_1 ;
} else if ( V_8 -> V_72 == V_73 ) {
V_67 = L_2 ;
F_20 ( V_8 ) ;
}
break;
case V_77 :
V_67 = L_3 ;
V_24 -> V_78 &= V_79 ;
F_23 ( V_8 ,
V_80 , V_58 ) ;
break;
case V_81 :
V_67 = L_4 ;
if ( ( V_8 -> V_24 -> V_78 & V_79 ) ==
V_79 )
V_69 = V_82 ;
else
V_69 = V_83 ;
F_23 ( V_8 , V_69 , V_58 ) ;
break;
case V_84 :
V_68 = F_26 ( 16 ) ;
case V_85 :
if ( V_68 )
V_67 = L_5 ;
else
V_67 = L_6 ;
F_23 ( V_8 ,
V_86 , V_58 ) ;
break;
default:
F_27 ( V_65 , L_7 , V_8 -> V_72 ) ;
return - V_87 ;
}
if ( V_8 -> V_70 ) {
V_10 = F_8 ( V_8 , V_45 ) ;
V_10 |= V_88 | V_68 ;
F_9 ( V_8 , V_10 , V_45 ) ;
}
if ( V_63 )
F_28 ( V_65 , L_8 , V_67 ) ;
return 0 ;
}
int F_29 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
struct V_89 * V_90 = V_8 -> V_66 -> V_7 . V_91 ;
struct V_23 * V_24 ;
T_1 V_92 ;
int V_5 ;
V_92 = V_8 -> V_93 ;
V_8 -> V_27 = - 1 ;
V_8 -> V_29 = - 1 ;
V_8 -> V_31 = - 1 ;
V_8 -> V_33 = - 1 ;
if ( V_90 ) {
V_24 = F_30 ( V_7 , V_8 -> V_94 , F_7 ,
V_92 , V_8 -> V_72 ) ;
if ( ! V_24 ) {
F_31 ( L_9 ) ;
return - V_95 ;
}
} else {
V_24 = V_8 -> V_24 ;
V_24 -> V_96 = V_92 ;
V_5 = F_32 ( V_7 , V_24 , F_7 ,
V_8 -> V_72 ) ;
if ( V_5 ) {
F_31 ( L_9 ) ;
return - V_95 ;
}
}
V_8 -> V_24 = V_24 ;
V_5 = F_25 ( V_7 , true ) ;
if ( V_5 ) {
F_33 ( V_8 -> V_24 ) ;
return V_5 ;
}
V_24 -> V_97 = V_24 -> V_78 ;
if ( V_8 -> V_71 )
V_8 -> V_24 -> V_98 = V_99 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_8 = F_2 ( V_7 ) ;
struct V_89 * V_100 = V_8 -> V_101 ;
struct V_89 * V_102 = NULL ;
T_1 V_103 = 0 ;
int V_104 = 0 ;
if ( ! V_100 ) {
V_103 = 1 << V_8 -> V_105 ;
} else {
F_35 (np, child) {
V_104 = F_36 ( & V_7 -> V_7 , V_102 ) ;
if ( V_104 < 0 )
continue;
V_103 |= 1 << V_104 ;
}
}
for ( V_104 = 0 ; V_104 < V_106 ; V_104 ++ ) {
if ( V_103 & 1 << V_104 ) {
F_37 ( & V_7 -> V_7 , L_10 , V_104 ) ;
F_38 ( V_2 , V_104 , V_107 ) ;
}
}
return 0 ;
}
static int F_39 ( struct V_9 * V_8 )
{
struct V_1 * V_2 ;
if ( V_8 -> V_1 )
return 0 ;
V_8 -> V_1 = F_40 () ;
if ( ! V_8 -> V_1 ) {
F_31 ( L_11 ) ;
return - V_108 ;
}
V_2 = V_8 -> V_1 ;
V_2 -> V_8 = V_8 -> V_7 ;
V_2 -> V_109 = L_12 ;
V_2 -> V_110 = & V_8 -> V_66 -> V_7 ;
V_2 -> V_111 = F_1 ;
V_2 -> V_112 = F_6 ;
V_2 -> V_113 = F_34 ;
snprintf ( V_2 -> V_114 , V_115 , L_13 ,
V_8 -> V_66 -> V_109 , V_8 -> V_66 -> V_114 ) ;
return 0 ;
}
static int F_41 ( struct V_9 * V_8 )
{
struct V_89 * V_90 = V_8 -> V_66 -> V_7 . V_91 ;
struct V_64 * V_65 = & V_8 -> V_66 -> V_7 ;
struct V_23 * V_24 = NULL ;
char * V_116 ;
int V_117 ;
int V_5 ;
V_116 = F_42 ( V_118 , L_14 , V_8 -> V_119 ) ;
if ( ! V_116 )
return - V_108 ;
V_8 -> V_101 = F_43 ( V_90 , NULL , V_116 ) ;
F_44 ( V_116 ) ;
if ( ! V_8 -> V_101 ) {
F_27 ( V_65 , L_15 ) ;
return - V_95 ;
}
V_5 = F_45 ( V_8 -> V_1 , V_8 -> V_101 ) ;
if ( V_5 ) {
F_27 ( V_65 , L_16 ) ;
return V_5 ;
}
V_8 -> V_94 = F_46 ( V_90 , L_17 , 0 ) ;
if ( ! V_8 -> V_94 && F_47 ( V_90 ) ) {
V_5 = F_48 ( V_90 ) ;
if ( V_5 )
return V_5 ;
V_8 -> V_94 = F_49 ( V_90 ) ;
}
V_117 = F_50 ( V_90 ) ;
if ( V_117 < 0 ) {
F_27 ( V_65 , L_18 ) ;
return V_117 ;
}
V_8 -> V_72 = V_117 ;
if ( V_8 -> V_72 == V_74 )
V_8 -> V_71 = true ;
if ( V_117 == V_73 ) {
V_24 = F_51 ( V_90 ) ;
if ( V_24 ) {
V_24 -> V_28 = 0 ;
F_52 ( & V_24 -> V_120 . V_7 ) ;
}
}
return 0 ;
}
static int F_53 ( struct V_9 * V_8 )
{
struct V_64 * V_65 = & V_8 -> V_66 -> V_7 ;
struct V_121 * V_122 = V_65 -> V_123 ;
struct V_1 * V_120 = V_8 -> V_1 ;
struct V_23 * V_24 ;
int V_5 ;
if ( V_122 -> V_72 != V_73 && V_122 -> V_124 ) {
if ( V_122 -> V_125 >= 0 && V_122 -> V_125 < V_106 )
V_120 -> V_126 = ~ ( 1 << V_122 -> V_125 ) ;
else
V_120 -> V_126 = 0 ;
V_5 = F_54 ( V_120 ) ;
if ( V_5 ) {
F_27 ( V_65 , L_16 ) ;
return V_5 ;
}
if ( V_122 -> V_125 >= 0 && V_122 -> V_125 < V_106 )
V_24 = F_55 ( V_120 , V_122 -> V_125 ) ;
else
V_24 = F_56 ( V_120 ) ;
if ( ! V_24 ) {
F_27 ( V_65 , L_19 ) ;
F_57 ( V_120 ) ;
return - V_95 ;
}
} else {
struct V_50 V_127 = {
. V_28 = 1 ,
. V_30 = V_122 -> V_128 ,
. V_32 = V_122 -> V_129 ,
. V_34 = 0 ,
. V_130 = 0 ,
} ;
V_24 = F_58 ( V_131 , & V_127 , - 1 , NULL ) ;
if ( ! V_24 || F_59 ( V_24 ) ) {
F_27 ( V_65 , L_20 ) ;
return - V_95 ;
}
V_24 -> V_28 = 0 ;
}
V_8 -> V_24 = V_24 ;
V_8 -> V_72 = V_122 -> V_72 ;
return 0 ;
}
static int F_60 ( struct V_9 * V_8 )
{
struct V_89 * V_90 = V_8 -> V_66 -> V_7 . V_91 ;
if ( V_90 )
return F_41 ( V_8 ) ;
else
return F_53 ( V_8 ) ;
}
int F_61 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
struct V_89 * V_90 = V_8 -> V_66 -> V_7 . V_91 ;
int V_5 ;
V_5 = F_39 ( V_8 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_60 ( V_8 ) ;
if ( V_5 )
goto V_132;
return 0 ;
V_132:
if ( F_47 ( V_90 ) )
F_62 ( V_90 ) ;
F_63 ( V_8 -> V_94 ) ;
F_57 ( V_8 -> V_1 ) ;
F_64 ( V_8 -> V_1 ) ;
return V_5 ;
}
void F_65 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
struct V_89 * V_90 = V_8 -> V_66 -> V_7 . V_91 ;
if ( F_47 ( V_90 ) )
F_62 ( V_90 ) ;
F_63 ( V_8 -> V_94 ) ;
F_57 ( V_8 -> V_1 ) ;
F_64 ( V_8 -> V_1 ) ;
}
