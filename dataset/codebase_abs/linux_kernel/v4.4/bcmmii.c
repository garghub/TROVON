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
if ( ! F_14 ( V_8 ) )
return;
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
V_10 |= V_55 | V_56 | V_57 ;
F_9 ( V_8 , V_10 , V_53 ) ;
F_18 ( 1 ) ;
V_10 |= V_54 ;
}
F_9 ( V_8 , V_10 , V_53 ) ;
F_19 ( 60 ) ;
}
static void F_20 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
T_1 V_10 ;
F_17 ( V_7 , true ) ;
V_10 = F_8 ( V_8 , V_58 ) ;
V_10 |= V_59 ;
F_9 ( V_8 , V_10 , V_58 ) ;
F_13 ( V_7 ) ;
}
static void F_21 ( struct V_9 * V_8 )
{
T_1 V_10 ;
V_10 = F_22 ( V_8 , V_60 ) ;
V_10 |= V_61 ;
F_23 ( V_8 , V_10 , V_60 ) ;
if ( V_8 -> V_62 -> V_63 & V_64 )
F_24 ( V_8 -> V_24 ,
F_12 ) ;
}
int F_25 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
struct V_23 * V_24 = V_8 -> V_24 ;
struct V_65 * V_66 = & V_8 -> V_67 -> V_7 ;
const char * V_68 = NULL ;
T_1 V_69 = 0 ;
T_1 V_70 ;
T_1 V_10 ;
V_8 -> V_71 = ! V_8 -> V_72 &&
( V_8 -> V_73 != V_74 ) ;
if ( V_8 -> V_72 )
V_8 -> V_73 = V_75 ;
switch ( V_8 -> V_73 ) {
case V_75 :
case V_74 :
if ( F_14 ( V_8 ) )
V_70 = V_76 ;
else
V_70 = V_77 ;
F_23 ( V_8 , V_70 , V_60 ) ;
if ( V_8 -> V_72 ) {
V_68 = L_1 ;
F_20 ( V_7 ) ;
} else if ( V_8 -> V_73 == V_74 ) {
V_68 = L_2 ;
F_21 ( V_8 ) ;
}
break;
case V_78 :
V_68 = L_3 ;
V_24 -> V_79 &= V_80 ;
F_23 ( V_8 ,
V_81 , V_60 ) ;
break;
case V_82 :
V_68 = L_4 ;
if ( ( V_8 -> V_24 -> V_79 & V_80 ) ==
V_80 )
V_70 = V_83 ;
else
V_70 = V_84 ;
F_23 ( V_8 , V_70 , V_60 ) ;
break;
case V_85 :
V_69 = F_26 ( 16 ) ;
case V_86 :
if ( V_69 )
V_68 = L_5 ;
else
V_68 = L_6 ;
F_23 ( V_8 ,
V_87 , V_60 ) ;
break;
default:
F_27 ( V_66 , L_7 , V_8 -> V_73 ) ;
return - V_88 ;
}
if ( V_8 -> V_71 ) {
V_10 = F_8 ( V_8 , V_45 ) ;
V_10 |= V_89 | V_69 ;
F_9 ( V_8 , V_10 , V_45 ) ;
}
F_28 ( V_66 , L_8 , V_68 ) ;
return 0 ;
}
int F_29 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
struct V_90 * V_91 = V_8 -> V_67 -> V_7 . V_92 ;
struct V_23 * V_24 ;
T_1 V_93 ;
int V_5 ;
V_93 = V_8 -> V_94 ;
V_8 -> V_27 = - 1 ;
V_8 -> V_29 = - 1 ;
V_8 -> V_31 = - 1 ;
V_8 -> V_33 = - 1 ;
if ( V_91 ) {
V_24 = F_30 ( V_7 , V_8 -> V_95 , F_7 ,
V_93 , V_8 -> V_73 ) ;
if ( ! V_24 ) {
F_31 ( L_9 ) ;
return - V_96 ;
}
} else {
V_24 = V_8 -> V_24 ;
V_24 -> V_97 = V_93 ;
V_5 = F_32 ( V_7 , V_24 , F_7 ,
V_8 -> V_73 ) ;
if ( V_5 ) {
F_31 ( L_9 ) ;
return - V_96 ;
}
}
V_8 -> V_24 = V_24 ;
V_5 = F_25 ( V_7 ) ;
if ( V_5 ) {
F_33 ( V_8 -> V_24 ) ;
return V_5 ;
}
V_24 -> V_98 = V_24 -> V_79 ;
if ( V_8 -> V_72 )
V_8 -> V_1 -> V_99 [ V_24 -> V_100 ] = V_101 ;
else
V_8 -> V_1 -> V_99 [ V_24 -> V_100 ] = V_102 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_8 = F_2 ( V_7 ) ;
struct V_90 * V_103 = V_8 -> V_104 ;
struct V_90 * V_105 = NULL ;
T_1 V_106 = 0 ;
int V_100 = 0 ;
if ( ! V_103 ) {
V_106 = 1 << V_8 -> V_107 ;
} else {
F_35 (np, child) {
V_100 = F_36 ( & V_7 -> V_7 , V_105 ) ;
if ( V_100 < 0 )
continue;
V_106 |= 1 << V_100 ;
}
}
for ( V_100 = 0 ; V_100 < V_108 ; V_100 ++ ) {
if ( V_106 & 1 << V_100 ) {
F_37 ( & V_7 -> V_7 , L_10 , V_100 ) ;
F_38 ( V_2 , V_100 , V_109 ) ;
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
return - V_110 ;
}
V_2 = V_8 -> V_1 ;
V_2 -> V_8 = V_8 -> V_7 ;
V_2 -> V_111 = L_12 ;
V_2 -> V_112 = & V_8 -> V_67 -> V_7 ;
V_2 -> V_113 = F_1 ;
V_2 -> V_114 = F_6 ;
V_2 -> V_115 = F_34 ;
snprintf ( V_2 -> V_116 , V_117 , L_13 ,
V_8 -> V_67 -> V_111 , V_8 -> V_67 -> V_116 ) ;
V_2 -> V_99 = F_41 ( V_108 , sizeof( int ) , V_118 ) ;
if ( ! V_2 -> V_99 ) {
F_42 ( V_8 -> V_1 ) ;
return - V_110 ;
}
return 0 ;
}
static int F_43 ( struct V_9 * V_8 )
{
struct V_90 * V_91 = V_8 -> V_67 -> V_7 . V_92 ;
struct V_65 * V_66 = & V_8 -> V_67 -> V_7 ;
const char * V_119 = NULL ;
struct V_23 * V_24 = NULL ;
char * V_120 ;
int V_121 ;
int V_5 ;
V_120 = F_44 ( V_118 , L_14 , V_8 -> V_122 ) ;
if ( ! V_120 )
return - V_110 ;
V_8 -> V_104 = F_45 ( V_91 , NULL , V_120 ) ;
F_46 ( V_120 ) ;
if ( ! V_8 -> V_104 ) {
F_27 ( V_66 , L_15 ) ;
return - V_96 ;
}
V_5 = F_47 ( V_8 -> V_1 , V_8 -> V_104 ) ;
if ( V_5 ) {
F_27 ( V_66 , L_16 ) ;
return V_5 ;
}
V_8 -> V_95 = F_48 ( V_91 , L_17 , 0 ) ;
if ( ! V_8 -> V_95 && F_49 ( V_91 ) ) {
V_5 = F_50 ( V_91 ) ;
if ( V_5 )
return V_5 ;
V_8 -> V_95 = F_51 ( V_91 ) ;
}
V_121 = F_52 ( V_91 ) ;
V_8 -> V_73 = V_121 ;
if ( V_121 < 0 ) {
V_5 = F_53 ( V_91 , L_18 , & V_119 ) ;
if ( V_5 < 0 ) {
F_27 ( V_66 , L_19 ) ;
return V_5 ;
}
V_8 -> V_73 = V_75 ;
if ( ! strcasecmp ( V_119 , L_20 ) )
V_8 -> V_72 = true ;
}
if ( V_121 == V_74 ) {
V_24 = F_54 ( V_91 ) ;
if ( V_24 )
V_24 -> V_28 = 0 ;
}
return 0 ;
}
static int F_55 ( struct V_9 * V_8 )
{
struct V_65 * V_66 = & V_8 -> V_67 -> V_7 ;
struct V_123 * V_124 = V_66 -> V_125 ;
struct V_1 * V_126 = V_8 -> V_1 ;
struct V_23 * V_24 ;
int V_5 ;
if ( V_124 -> V_73 != V_74 && V_124 -> V_127 ) {
if ( V_124 -> V_128 >= 0 && V_124 -> V_128 < V_108 )
V_126 -> V_129 = ~ ( 1 << V_124 -> V_128 ) ;
else
V_126 -> V_129 = 0 ;
V_5 = F_56 ( V_126 ) ;
if ( V_5 ) {
F_27 ( V_66 , L_16 ) ;
return V_5 ;
}
if ( V_124 -> V_128 >= 0 && V_124 -> V_128 < V_108 )
V_24 = V_126 -> V_130 [ V_124 -> V_128 ] ;
else
V_24 = F_57 ( V_126 ) ;
if ( ! V_24 ) {
F_27 ( V_66 , L_21 ) ;
F_58 ( V_126 ) ;
return - V_96 ;
}
} else {
struct V_50 V_131 = {
. V_28 = 1 ,
. V_30 = V_124 -> V_132 ,
. V_32 = V_124 -> V_133 ,
. V_34 = 0 ,
. V_134 = 0 ,
} ;
V_24 = F_59 ( V_102 , & V_131 , - 1 , NULL ) ;
if ( ! V_24 || F_60 ( V_24 ) ) {
F_27 ( V_66 , L_22 ) ;
return - V_96 ;
}
V_24 -> V_28 = 0 ;
}
V_8 -> V_24 = V_24 ;
V_8 -> V_73 = V_124 -> V_73 ;
return 0 ;
}
static int F_61 ( struct V_9 * V_8 )
{
struct V_90 * V_91 = V_8 -> V_67 -> V_7 . V_92 ;
if ( V_91 )
return F_43 ( V_8 ) ;
else
return F_55 ( V_8 ) ;
}
int F_62 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
int V_5 ;
V_5 = F_39 ( V_8 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_61 ( V_8 ) ;
if ( V_5 )
goto V_135;
return 0 ;
V_135:
F_63 ( V_8 -> V_95 ) ;
F_58 ( V_8 -> V_1 ) ;
F_46 ( V_8 -> V_1 -> V_99 ) ;
F_42 ( V_8 -> V_1 ) ;
return V_5 ;
}
void F_64 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
F_63 ( V_8 -> V_95 ) ;
F_58 ( V_8 -> V_1 ) ;
F_46 ( V_8 -> V_1 -> V_99 ) ;
F_42 ( V_8 -> V_1 ) ;
}
