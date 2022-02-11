static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
F_3 ( F_4 ( V_2 -> V_6 ) , L_1 , V_7 ,
V_2 -> V_5 , V_3 , V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
F_6 ( V_4 , V_2 -> V_5 + V_3 ) ;
F_3 ( F_4 ( V_2 -> V_6 ) , L_1 , V_7 ,
V_2 -> V_5 , V_3 , V_4 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = F_8 ( V_2 -> V_5 + V_3 ) ;
F_3 ( F_4 ( V_2 -> V_6 ) , L_1 , V_7 ,
V_2 -> V_5 , V_3 , V_4 ) ;
return V_4 ;
}
static T_2 F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 = F_10 ( V_2 -> V_5 + V_3 ) ;
F_3 ( F_4 ( V_2 -> V_6 ) , L_1 , V_7 ,
V_2 -> V_5 , V_3 , V_4 ) ;
return V_4 ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_8 , T_1 V_9 )
{
V_2 -> V_10 = V_11 & ~ V_8 ;
V_2 -> V_12 = V_13 & ~ V_9 ;
F_1 ( V_2 , V_14 , V_2 -> V_10 ) ;
F_1 ( V_2 , V_15 , V_2 -> V_12 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_16 |
V_17 | V_18 ,
V_19 ) ;
}
static void F_13 ( struct V_1 * V_2 , bool V_20 )
{
F_11 ( V_2 , V_17 |
V_18 , V_19 |
( V_20 ? V_21 : V_22 ) ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_18 , 0 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_11 ( V_2 , 0 , 0 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_1 V_23 ;
F_1 ( V_2 , V_24 , V_25 ) ;
if ( V_2 -> V_26 &
( V_27 | V_28 ) ) {
T_1 V_29 = F_7 ( V_2 , V_30 ) ;
int V_31 = V_2 -> V_32 ? V_2 -> V_32 -> V_33 -> V_34 : - 1 ;
V_23 = F_7 ( V_2 , V_35 ) ;
if ( V_2 -> V_36 == V_37 )
F_17 ( F_4 ( V_2 -> V_6 ) ,
L_2 ,
V_23 , V_29 , V_2 -> V_36 , V_31 ) ;
else
F_18 ( F_4 ( V_2 -> V_6 ) ,
L_2 ,
V_23 , V_29 , V_2 -> V_36 , V_31 ) ;
return - V_38 ;
}
V_23 = F_7 ( V_2 , V_39 ) ;
if ( V_23 != V_40 )
F_18 ( F_4 ( V_2 -> V_6 ) , L_3 ,
V_23 , V_2 -> V_36 , V_2 -> V_32 ? V_2 -> V_32 -> V_33 -> V_34 : - 1 ) ;
if ( V_2 -> V_26 & V_41 )
return - V_42 ;
return - V_43 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
struct V_46 * V_4 = V_2 -> V_32 -> V_4 ;
T_3 V_47 = V_2 -> V_48 ;
F_17 ( F_4 ( V_2 -> V_6 ) , L_4 ,
V_7 , V_2 -> V_32 -> V_33 -> V_34 , V_4 -> V_49 ,
V_4 -> V_50 , V_4 -> V_51 , V_45 -> V_52 ) ;
V_2 -> V_53 . V_54 = V_2 -> V_55 . V_54 ;
V_2 -> V_53 . V_56 = V_2 -> V_55 . V_56 ;
V_2 -> V_55 . V_54 = F_20 ( V_2 -> V_55 . V_54 , 1 ) ;
V_2 -> V_55 . V_56 = F_21 ( V_2 -> V_55 . V_54 ) ;
V_2 -> V_57 = V_2 -> V_58 ;
V_2 -> V_52 = 0 ;
if ( V_4 -> V_59 & V_60 )
return;
memcpy ( V_2 -> V_58 , V_2 -> V_53 . V_56 + V_61 - V_47 ,
V_47 ) ;
memcpy ( V_2 -> V_58 + V_47 , V_2 -> V_55 . V_56 ,
V_4 -> V_50 - V_47 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_62 * V_32 = V_2 -> V_32 ;
struct V_46 * V_4 = V_32 -> V_4 ;
F_1 ( V_2 , V_63 , V_4 -> V_51 ) ;
V_2 -> V_45 = V_4 -> V_45 ;
V_2 -> V_52 = V_2 -> V_45 -> V_52 ;
}
static void * F_23 ( struct V_1 * V_2 )
{
struct V_46 * V_4 = V_2 -> V_32 -> V_4 ;
struct V_44 * V_45 = V_4 -> V_49 > 1 ? V_2 -> V_45 : V_4 -> V_45 ;
T_3 V_64 = V_61 - V_45 -> V_52 ;
T_3 V_47 = V_64 % V_4 -> V_50 ;
F_24 ( V_2 -> V_55 . V_54 , L_5 , V_2 -> V_55 . V_54 ) ;
if ( F_24 ( F_25 ( V_45 ) % V_4 -> V_50 ,
L_6 ,
F_25 ( V_45 ) , V_4 -> V_50 ) )
return NULL ;
V_2 -> V_55 . V_54 = F_26 ( V_45 ) ;
V_2 -> V_55 . V_56 = F_21 ( V_2 -> V_55 . V_54 ) ;
V_2 -> V_52 = V_45 -> V_52 ;
V_2 -> V_48 = V_47 ;
if ( V_64 < V_4 -> V_50 )
F_19 ( V_2 , V_45 ) ;
else
V_2 -> V_57 = V_2 -> V_55 . V_56 ;
F_17 ( F_4 ( V_2 -> V_6 ) , L_7 ,
V_2 -> V_55 . V_54 , F_27 ( V_2 -> V_55 . V_54 ) , V_2 -> V_55 . V_56 ,
V_45 -> V_52 , V_2 -> V_32 -> V_33 -> V_34 , V_2 -> V_32 ) ;
return V_2 -> V_57 + V_2 -> V_52 ;
}
static void F_28 ( struct V_1 * V_2 , bool V_65 )
{
struct V_46 * V_4 = V_2 -> V_32 -> V_4 ;
struct V_54 * V_54 = V_2 -> V_53 . V_54 ;
if ( V_54 ) {
struct V_44 * V_45 = V_4 -> V_49 > 1 ?
V_2 -> V_45 : V_4 -> V_45 ;
T_3 V_47 = V_2 -> V_48 ;
if ( ! V_4 -> error && V_4 -> V_59 & V_60 ) {
memcpy ( V_2 -> V_53 . V_56 + V_61 - V_47 ,
V_2 -> V_58 , V_47 ) ;
memcpy ( V_2 -> V_55 . V_56 , V_2 -> V_58 + V_47 ,
V_4 -> V_50 - V_47 ) ;
}
F_29 ( V_54 ) ;
F_30 ( V_54 ) ;
V_2 -> V_53 . V_54 = NULL ;
if ( ! V_65 && F_25 ( V_45 ) + V_45 -> V_52 >
( V_2 -> V_66 << V_67 ) + V_4 -> V_50 - V_47 )
return;
}
V_54 = V_2 -> V_55 . V_54 ;
if ( ! V_54 )
return;
F_29 ( V_54 ) ;
F_30 ( V_54 ) ;
V_2 -> V_55 . V_54 = NULL ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_46 * V_4 = V_2 -> V_32 -> V_4 ;
T_3 V_68 , V_69 ;
if ( V_2 -> V_53 . V_54 ) {
V_2 -> V_66 ++ ;
V_2 -> V_52 = V_4 -> V_50 - V_2 -> V_48 ;
V_2 -> V_57 = V_2 -> V_55 . V_56 ;
F_28 ( V_2 , false ) ;
} else {
V_2 -> V_52 += V_4 -> V_50 ;
if ( V_2 -> V_52 == V_61 ) {
V_2 -> V_52 = 0 ;
V_2 -> V_66 ++ ;
}
}
V_68 = ( V_2 -> V_66 << V_67 ) + V_2 -> V_52 ;
V_69 = V_2 -> V_45 -> V_52 + F_25 ( V_2 -> V_45 ) ;
F_17 ( F_4 ( V_2 -> V_6 ) , L_8 , V_7 ,
V_68 , V_69 , V_2 -> V_52 ) ;
if ( V_68 < V_69 && V_2 -> V_52 ) {
if ( V_2 -> V_52 + V_4 -> V_50 > V_61 )
F_19 ( V_2 , V_2 -> V_45 ) ;
return;
}
F_28 ( V_2 , false ) ;
if ( V_68 == V_69 ) {
struct V_44 * V_70 = F_32 ( V_2 -> V_45 ) ;
V_2 -> V_66 = 0 ;
if ( ! V_70 )
V_2 -> V_36 = V_71 ;
V_2 -> V_45 = V_70 ;
if ( F_24 ( V_70 && F_25 ( V_70 ) % V_4 -> V_50 ,
L_6 ,
F_25 ( V_70 ) , V_4 -> V_50 ) )
V_4 -> error = - V_72 ;
return;
}
V_2 -> V_55 . V_54 = F_20 ( F_26 ( V_2 -> V_45 ) , V_2 -> V_66 ) ;
V_2 -> V_55 . V_56 = F_21 ( V_2 -> V_55 . V_54 ) ;
V_2 -> V_57 = V_2 -> V_55 . V_56 ;
F_17 ( F_4 ( V_2 -> V_6 ) , L_9 ,
V_2 -> V_55 . V_54 , F_27 ( V_2 -> V_55 . V_54 ) , V_2 -> V_55 . V_56 ,
V_2 -> V_32 -> V_33 -> V_34 , V_2 -> V_32 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
V_2 -> V_73 = false ;
if ( V_2 -> V_74 ) {
struct V_75 * V_76 = V_2 -> V_74 ;
V_2 -> V_74 = NULL ;
F_34 ( V_76 ) ;
}
if ( V_2 -> V_77 ) {
struct V_75 * V_76 = V_2 -> V_77 ;
V_2 -> V_77 = NULL ;
F_34 ( V_76 ) ;
}
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_46 * V_4 = V_2 -> V_32 -> V_4 ;
if ( ! V_2 -> V_73 )
return;
F_1 ( V_2 , V_78 , 0 ) ;
V_2 -> V_73 = false ;
if ( V_4 -> V_59 & V_60 )
F_36 ( V_2 -> V_77 -> V_79 -> V_80 , V_4 -> V_45 ,
V_4 -> V_49 , V_81 ) ;
else
F_36 ( V_2 -> V_74 -> V_79 -> V_80 , V_4 -> V_45 ,
V_4 -> V_49 , V_82 ) ;
}
static void F_37 ( void * V_83 )
{
struct V_1 * V_2 = V_83 ;
struct V_62 * V_32 = V_2 -> V_32 ;
if ( F_24 ( ! V_32 || ! V_32 -> V_4 , L_10 ,
F_38 ( F_4 ( V_2 -> V_6 ) ) , V_32 ) )
return;
F_17 ( F_4 ( V_2 -> V_6 ) , L_11 , V_7 ,
V_32 -> V_33 -> V_34 ) ;
F_35 ( V_2 ) ;
F_13 ( V_2 , V_32 -> V_4 -> V_59 & V_60 ) ;
}
static int F_39 ( struct V_1 * V_2 , struct V_75 * V_76 ,
enum V_84 V_85 )
{
struct V_46 * V_4 = V_2 -> V_32 -> V_4 ;
struct V_44 * V_45 = V_4 -> V_45 ;
struct V_86 * V_87 = NULL ;
T_4 V_88 = - V_72 ;
enum V_89 V_90 ;
int V_91 ;
switch ( V_85 ) {
case V_92 :
V_90 = V_82 ;
break;
case V_93 :
V_90 = V_81 ;
break;
default:
return - V_72 ;
}
V_91 = F_40 ( V_76 -> V_79 -> V_80 , V_45 , V_4 -> V_49 , V_90 ) ;
if ( V_91 > 0 ) {
V_2 -> V_73 = true ;
V_87 = F_41 ( V_76 , V_45 , V_91 , V_85 ,
V_94 | V_95 ) ;
}
if ( V_87 ) {
V_87 -> V_96 = F_37 ;
V_87 -> V_97 = V_2 ;
V_88 = F_42 ( V_87 ) ;
}
F_17 ( F_4 ( V_2 -> V_6 ) , L_12 ,
V_7 , V_4 -> V_49 , V_91 , V_88 , V_87 ) ;
if ( V_88 < 0 ) {
if ( V_91 >= 0 )
V_91 = V_88 ;
F_33 ( V_2 ) ;
F_18 ( F_4 ( V_2 -> V_6 ) ,
L_13 , V_91 ) ;
}
return V_88 ;
}
static int F_43 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_77 || ! V_2 -> V_74 )
return - V_98 ;
if ( V_2 -> V_32 -> V_4 -> V_59 & V_60 )
return F_39 ( V_2 , V_2 -> V_77 , V_93 ) ;
return F_39 ( V_2 , V_2 -> V_74 , V_92 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_46 * V_4 = V_2 -> V_32 -> V_4 ;
F_17 ( F_4 ( V_2 -> V_6 ) , L_14 ,
V_7 , V_4 -> V_49 , V_4 -> V_51 , V_4 -> V_50 ) ;
if ( V_4 -> V_59 & V_60 )
F_45 ( V_2 -> V_77 ) ;
else
F_45 ( V_2 -> V_74 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_46 * V_4 = V_2 -> V_32 -> V_4 ;
F_17 ( F_4 ( V_2 -> V_6 ) , L_15 ,
V_7 , V_2 -> V_26 , F_7 ( V_2 , V_99 ) ) ;
if ( V_2 -> V_26 ) {
V_4 -> error = F_16 ( V_2 ) ;
V_4 -> V_100 = 0 ;
F_44 ( V_2 ) ;
F_33 ( V_2 ) ;
F_18 ( F_4 ( V_2 -> V_6 ) ,
L_13 , V_4 -> error ) ;
return;
}
if ( V_2 -> V_101 & V_16 )
F_18 ( F_4 ( V_2 -> V_6 ) , L_16 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_32 -> V_4 -> V_59 & V_60 )
F_48 ( V_2 -> V_77 ) ;
else
F_48 ( V_2 -> V_74 ) ;
}
static void F_49 ( struct V_1 * V_2 , T_5 V_102 )
{
struct V_103 V_104 = {
. V_105 = V_106 ,
. V_107 = V_106 ,
} ;
int V_91 ;
V_2 -> V_74 = F_50 ( F_4 ( V_2 -> V_6 ) , L_17 ) ;
F_17 ( F_4 ( V_2 -> V_6 ) , L_18 , V_7 ,
V_2 -> V_74 ) ;
if ( ! V_2 -> V_74 )
return;
V_104 . V_108 = V_92 ;
V_104 . V_109 = V_102 + V_110 ;
V_104 . V_111 = 128 ;
V_104 . V_112 = 0 ;
V_91 = F_51 ( V_2 -> V_74 , & V_104 ) ;
if ( V_91 < 0 )
goto V_113;
V_2 -> V_77 = F_50 ( F_4 ( V_2 -> V_6 ) , L_19 ) ;
F_17 ( F_4 ( V_2 -> V_6 ) , L_20 , V_7 ,
V_2 -> V_77 ) ;
if ( ! V_2 -> V_77 )
goto V_113;
V_104 . V_108 = V_93 ;
V_104 . V_112 = V_104 . V_109 ;
V_104 . V_114 = 128 ;
V_104 . V_109 = 0 ;
V_91 = F_51 ( V_2 -> V_77 , & V_104 ) ;
if ( V_91 < 0 )
goto V_115;
return;
V_115:
F_34 ( V_2 -> V_77 ) ;
V_2 -> V_77 = NULL ;
V_113:
F_34 ( V_2 -> V_74 ) ;
V_2 -> V_74 = NULL ;
}
static void F_52 ( struct V_1 * V_2 , struct V_116 * V_117 )
{
unsigned long V_118 = V_117 -> clock ;
T_1 V_119 ;
unsigned int V_120 ;
for ( V_120 = 1000 ; V_120 ; V_120 -- ) {
if ( F_7 ( V_2 , V_121 ) & V_122 )
break;
F_53 ( 10 , 100 ) ;
}
if ( ! V_120 ) {
F_54 ( F_4 ( V_2 -> V_6 ) , L_21 ) ;
return;
}
V_119 = F_7 ( V_2 , V_123 ) & ~ V_124 ;
if ( V_118 ) {
unsigned long V_125 ;
if ( V_2 -> V_126 <= V_118 ) {
if ( V_117 -> V_127 != V_128 ) {
V_125 = V_2 -> V_126 ;
V_119 |= 0xff ;
} else {
V_125 = V_2 -> V_126 / 2 ;
}
} else {
unsigned long div =
F_55 ( F_56 ( V_2 -> V_126 , V_118 ) ) ;
V_119 |= div >> 2 ;
V_125 = V_2 -> V_126 / div ;
}
if ( V_2 -> V_118 == V_125 )
return;
V_2 -> V_118 = V_125 ;
F_17 ( F_4 ( V_2 -> V_6 ) , L_22 ,
V_118 , ( V_119 & 0xff ) << 2 , V_125 ) ;
}
if ( V_2 -> V_126 == V_118 || V_2 -> V_126 == V_2 -> V_118 || ! V_118 )
F_1 ( V_2 , V_123 ,
V_119 & ~ V_129 ) ;
if ( ! V_118 ) {
V_2 -> V_118 = 0 ;
return;
}
F_1 ( V_2 , V_123 , V_119 ) ;
if ( V_2 -> V_126 == V_118 || V_2 -> V_126 == V_2 -> V_118 ||
! ( V_119 & V_129 ) )
F_1 ( V_2 , V_123 ,
V_119 | V_129 ) ;
}
static void F_57 ( struct V_1 * V_2 , struct V_116 * V_117 )
{
struct V_130 * V_6 = V_2 -> V_6 ;
if ( ! F_58 ( V_6 -> V_131 . V_132 ) )
F_59 ( V_6 , V_6 -> V_131 . V_132 ,
V_117 -> V_133 ? V_117 -> V_134 : 0 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_120 ;
F_1 ( V_2 , V_135 , V_136 ) ;
F_61 () ;
F_1 ( V_2 , V_135 , V_136 | V_137 ) ;
for ( V_120 = 1000 ; V_120 ; V_120 -- )
if ( F_7 ( V_2 , V_135 ) & V_137 )
break;
return V_120 ? 0 : - V_38 ;
}
static void F_62 ( struct V_130 * V_6 , struct V_116 * V_117 )
{
struct V_1 * V_2 = F_63 ( V_6 ) ;
T_1 V_138 , V_139 ;
int V_91 ;
F_17 ( F_4 ( V_6 ) , L_23 ,
V_117 -> clock , V_117 -> V_134 , V_117 -> V_133 , V_117 -> V_140 , V_117 -> V_127 ) ;
switch ( V_117 -> V_133 ) {
case V_141 :
F_57 ( V_2 , V_117 ) ;
F_14 ( V_2 ) ;
break;
case V_142 :
V_91 = F_60 ( V_2 ) ;
if ( V_91 < 0 ) {
F_54 ( F_4 ( V_6 ) , L_24 ) ;
} else {
F_57 ( V_2 , V_117 ) ;
F_14 ( V_2 ) ;
}
break;
case V_143 :
V_138 = F_7 ( V_2 , V_144 ) ;
if ( V_117 -> V_140 == V_145 ) {
if ( V_117 -> V_127 == V_128 )
F_54 ( F_4 ( V_6 ) ,
L_25 ) ;
V_138 |= V_146 ;
V_139 = 0 ;
} else {
V_138 &= ~ V_146 ;
V_139 = V_117 -> V_127 == V_128 ;
}
F_1 ( V_2 , V_144 , V_138 ) ;
F_1 ( V_2 , V_147 , V_139 ) ;
break;
}
if ( V_2 -> V_118 != V_117 -> clock )
F_52 ( V_2 , V_117 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_62 * V_32 = V_2 -> V_32 ;
T_1 V_119 ;
unsigned long V_148 ;
if ( ! V_32 -> V_4 )
V_148 = V_2 -> V_118 / 1000 * V_32 -> V_33 -> V_149 ;
else
V_148 = V_2 -> V_118 / 1000000 * ( V_32 -> V_4 -> V_150 / 1000 ) +
V_32 -> V_4 -> V_151 ;
if ( ! V_148 || V_148 > 1 << 27 )
V_119 = 14 ;
else if ( V_148 < 1 << 13 )
V_119 = 0 ;
else
V_119 = F_65 ( V_148 ) - 13 ;
F_17 ( F_4 ( V_2 -> V_6 ) , L_26 ,
V_32 -> V_4 ? L_27 : L_28 , V_148 , V_2 -> V_118 ) ;
F_1 ( V_2 , V_144 , ( V_119 << V_152 ) |
( F_7 ( V_2 , V_144 ) & ~ V_153 ) ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_62 * V_32 = V_2 -> V_32 ;
struct V_46 * V_4 = V_32 -> V_4 ;
if ( F_24 ( V_2 -> V_55 . V_54 || V_2 -> V_53 . V_54 ,
L_29 ,
V_2 -> V_55 . V_54 , V_2 -> V_53 . V_54 , V_2 -> V_36 , V_32 -> V_33 -> V_34 ,
V_4 ? ( V_4 -> V_59 & V_60 ? 'R' : 'W' ) : '-' ,
V_4 ? V_2 -> V_52 : 0 , V_4 ? V_4 -> V_51 : 0 ,
V_4 ? V_4 -> V_50 : 0 , V_4 ? V_4 -> V_49 : 0 ) )
F_28 ( V_2 , true ) ;
if ( V_32 -> V_33 -> error ||
( V_4 && V_4 -> error ) ||
( V_32 -> V_154 && V_32 -> V_154 -> error ) )
F_17 ( F_4 ( V_2 -> V_6 ) , L_30 ,
V_7 , V_32 -> V_33 -> V_34 , V_4 ? V_4 -> V_51 : 0 ,
V_4 ? V_4 -> V_50 : 0 ,
V_32 -> V_33 -> error ,
V_4 ? V_4 -> error : 1 ,
V_32 -> V_154 ? V_32 -> V_154 -> error : 1 ) ;
F_1 ( V_2 , V_78 , 0 ) ;
V_2 -> V_36 = V_155 ;
V_2 -> V_32 = NULL ;
F_67 ( V_2 -> V_6 , V_32 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_62 * V_32 = V_2 -> V_32 ;
struct V_156 * V_33 = V_32 -> V_33 ;
T_2 V_31 = V_33 -> V_34 ;
if ( V_2 -> V_157 ) {
V_2 -> V_157 = false ;
V_31 |= V_158 ;
}
if ( V_32 -> V_4 ) {
V_31 |= V_159 ;
if ( V_32 -> V_4 -> V_59 & V_60 )
V_31 |= V_160 ;
if ( V_33 -> V_34 == V_161 ||
V_33 -> V_34 == V_162 ||
( V_33 -> V_34 == V_163 &&
V_32 -> V_4 -> V_51 > 1 ) ) {
V_31 |= V_164 ;
if ( ! V_32 -> V_154 )
V_31 |= V_165 ;
}
switch ( F_69 ( V_33 ) ) {
case V_166 :
V_31 |= V_167 ;
break;
case V_168 :
V_31 |= V_169 ;
break;
case V_170 :
V_31 |= V_171 ;
break;
case V_172 :
V_31 |= V_173 ;
break;
case V_174 :
V_31 |= V_175 ;
break;
default:
F_18 ( F_4 ( V_2 -> V_6 ) ,
L_31 ,
F_69 ( V_33 ) ) ;
return - V_72 ;
}
}
return V_31 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_62 * V_32 = V_2 -> V_32 ;
struct V_156 * V_33 = V_32 -> V_33 ;
struct V_46 * V_4 = V_32 -> V_4 ;
int V_31 = F_68 ( V_2 ) ;
int V_120 ;
if ( V_31 < 0 )
return V_31 ;
for ( V_120 = 1000 ; V_120 ; V_120 -- ) {
if ( ! ( F_7 ( V_2 , V_121 ) & V_176 ) )
break;
F_53 ( 10 , 100 ) ;
}
if ( ! V_120 ) {
F_17 ( F_4 ( V_2 -> V_6 ) , L_32 ) ;
return - V_177 ;
}
if ( V_4 ) {
bool V_178 ;
int V_91 = 0 ;
V_2 -> V_66 = 0 ;
if ( V_33 -> V_34 == V_163 && V_4 -> V_51 > 1 ) {
switch ( V_4 -> V_50 ) {
case 512 :
break;
case 32 :
case 64 :
case 128 :
case 256 :
if ( V_32 -> V_154 )
V_91 = - V_72 ;
break;
default:
V_91 = - V_72 ;
}
} else if ( ( V_33 -> V_34 == V_161 ||
V_33 -> V_34 == V_162 ) &&
V_4 -> V_50 != 512 ) {
V_91 = - V_72 ;
}
if ( V_91 < 0 ) {
F_18 ( F_4 ( V_2 -> V_6 ) , L_33 ,
V_7 , V_4 -> V_51 , V_4 -> V_50 ) ;
return - V_72 ;
}
if ( V_33 -> V_34 == V_161 ||
V_33 -> V_34 == V_162 ||
( V_33 -> V_34 == V_163 &&
V_4 -> V_51 > 1 ) )
F_22 ( V_2 ) ;
F_1 ( V_2 , V_179 , V_4 -> V_50 ) ;
if ( ( V_4 -> V_50 >= V_180 ||
V_4 -> V_51 > 1 ) &&
( V_4 -> V_50 % 4 ||
V_4 -> V_45 -> V_52 % 4 ) )
F_17 ( F_4 ( V_2 -> V_6 ) ,
L_34 , V_4 -> V_49 ,
V_4 -> V_50 , V_4 -> V_51 , V_4 -> V_45 -> V_52 ) ;
V_178 = V_4 -> V_50 >= V_180 &&
! ( V_4 -> V_50 % 4 ) &&
F_43 ( V_2 ) >= V_181 ;
if ( V_178 )
F_1 ( V_2 , V_78 , V_182 ) ;
F_17 ( F_4 ( V_2 -> V_6 ) ,
L_35 ,
V_7 , V_33 -> V_34 , V_4 -> V_51 , V_4 -> V_50 ,
V_4 -> V_49 , V_178 ? L_36 : L_37 ,
V_4 -> V_59 & V_60 ? L_38 : L_39 ,
V_4 -> V_45 -> V_52 , V_32 -> V_154 ? L_40 : L_41 ) ;
} else {
F_17 ( F_4 ( V_2 -> V_6 ) , L_42 ,
V_7 , V_33 -> V_34 ) ;
}
F_12 ( V_2 ) ;
V_2 -> V_36 = V_37 ;
F_71 ( & V_2 -> V_183 , V_2 -> V_184 ) ;
F_1 ( V_2 , V_24 ,
V_4 && V_4 -> V_51 > 1 ? V_185 : 0 ) ;
F_1 ( V_2 , V_186 , V_33 -> V_83 ) ;
F_1 ( V_2 , V_187 , V_31 ) ;
return 0 ;
}
static void F_72 ( struct V_130 * V_6 , struct V_62 * V_32 )
{
struct V_1 * V_2 = F_63 ( V_6 ) ;
int V_91 ;
F_73 ( & V_2 -> V_183 ) ;
V_2 -> V_32 = V_32 ;
V_2 -> V_45 = NULL ;
F_64 ( V_2 ) ;
V_91 = F_70 ( V_2 ) ;
if ( V_91 < 0 ) {
V_32 -> V_33 -> error = V_91 ;
F_66 ( V_2 ) ;
}
}
static int F_74 ( struct V_130 * V_6 )
{
struct V_1 * V_2 = F_63 ( V_6 ) ;
T_1 V_188 = F_7 ( V_2 , V_99 ) & V_189 ;
return ! V_188 ^ ! ( V_6 -> V_190 & V_191 ) ;
}
static int F_75 ( struct V_130 * V_6 )
{
struct V_1 * V_2 = F_63 ( V_6 ) ;
T_1 V_188 = F_7 ( V_2 , V_99 ) & V_192 ;
return ! V_188 ^ ! ( V_6 -> V_190 & V_193 ) ;
}
static void F_76 ( struct V_130 * V_6 , int V_194 )
{
struct V_1 * V_2 = F_63 ( V_6 ) ;
F_17 ( F_4 ( V_6 ) , L_43 , V_7 , V_194 ? L_44 : L_45 ) ;
if ( V_194 ) {
V_2 -> V_195 = V_196 & ~ V_197 ;
F_1 ( V_2 , V_198 , V_2 -> V_195 ) ;
F_1 ( V_2 , V_199 , 1 ) ;
} else {
F_1 ( V_2 , V_199 , 0 ) ;
F_1 ( V_2 , V_198 , V_196 ) ;
V_2 -> V_195 = V_196 ;
}
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_156 * V_33 = V_2 -> V_32 -> V_154 ;
V_33 -> V_200 [ 0 ] = F_7 ( V_2 , V_201 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_156 * V_33 = V_2 -> V_32 -> V_33 ;
T_1 * V_202 = V_33 -> V_200 , V_203 = 0 ;
int V_120 ;
if ( F_69 ( V_33 ) == V_166 )
return;
if ( ! ( V_2 -> V_101 & V_16 ) ) {
F_54 ( F_4 ( V_2 -> V_6 ) ,
L_46 , V_33 -> V_34 ) ;
return;
}
if ( F_69 ( V_33 ) & V_204 )
for ( V_120 = 0 ; V_120 < 4 ; V_120 ++ ) {
if ( V_120 )
V_202 [ 3 - V_120 ] = V_203 >> 24 ;
V_203 = F_7 ( V_2 , V_201 + V_120 * 8 ) ;
V_202 [ 3 - V_120 ] |= V_203 << 8 ;
}
else if ( V_33 -> V_34 == V_161 ||
V_33 -> V_34 == V_162 )
V_202 [ 0 ] = F_7 ( V_2 , V_30 ) ;
else
V_202 [ 0 ] = F_7 ( V_2 , V_201 ) ;
F_17 ( F_4 ( V_2 -> V_6 ) , L_47 , V_202 [ 0 ] ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_46 * V_4 = V_2 -> V_32 -> V_4 ;
T_1 * V_205 ;
int V_120 , V_206 ;
if ( V_2 -> V_26 ) {
V_4 -> error = F_16 ( V_2 ) ;
goto error;
}
if ( V_2 -> V_55 . V_54 ) {
V_205 = V_2 -> V_57 + V_2 -> V_52 ;
} else {
V_205 = F_23 ( V_2 ) ;
if ( ! V_205 ) {
V_4 -> error = - V_207 ;
goto error;
}
}
for ( V_120 = 0 ; V_120 < V_4 -> V_50 / 4 ; V_120 ++ , V_205 ++ )
* V_205 = F_7 ( V_2 , V_110 ) ;
V_206 = V_4 -> V_50 % 4 ;
for ( V_120 = 0 ; V_120 < ( V_206 + 1 ) / 2 ; V_120 ++ ) {
T_2 V_208 = F_9 ( V_2 , V_110 ) ;
( ( V_209 * ) V_205 ) [ 2 * V_120 ] = ( ( V_209 * ) & V_208 ) [ 0 ] ;
if ( V_206 > 1 && ! V_120 )
( ( V_209 * ) V_205 ) [ 2 * V_120 + 1 ] = ( ( V_209 * ) & V_208 ) [ 1 ] ;
}
return 0 ;
error:
F_17 ( F_4 ( V_2 -> V_6 ) , L_48 , V_7 , V_4 -> error ) ;
V_2 -> V_36 = V_155 ;
return V_4 -> error ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_46 * V_4 = V_2 -> V_32 -> V_4 ;
T_1 * V_205 ;
int V_120 , V_206 ;
if ( V_2 -> V_26 ) {
V_4 -> error = F_16 ( V_2 ) ;
goto error;
}
if ( V_2 -> V_55 . V_54 ) {
V_205 = V_2 -> V_57 + V_2 -> V_52 ;
} else {
V_205 = F_23 ( V_2 ) ;
if ( ! V_205 ) {
V_4 -> error = - V_207 ;
goto error;
}
}
for ( V_120 = 0 ; V_120 < V_4 -> V_50 / 4 ; V_120 ++ , V_205 ++ )
F_1 ( V_2 , V_110 , * V_205 ) ;
V_206 = V_4 -> V_50 % 4 ;
for ( V_120 = 0 ; V_120 < ( V_206 + 1 ) / 2 ; V_120 ++ ) {
T_2 V_208 ;
( ( V_209 * ) & V_208 ) [ 0 ] = ( ( V_209 * ) V_205 ) [ 2 * V_120 ] ;
if ( V_206 > 1 && ! V_120 )
( ( V_209 * ) & V_208 ) [ 1 ] = ( ( V_209 * ) V_205 ) [ 2 * V_120 + 1 ] ;
else
( ( V_209 * ) & V_208 ) [ 1 ] = 0 ;
F_5 ( V_2 , V_110 , V_208 ) ;
}
return 0 ;
error:
F_17 ( F_4 ( V_2 -> V_6 ) , L_48 , V_7 , V_4 -> error ) ;
V_2 -> V_36 = V_155 ;
return V_4 -> error ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_62 * V_32 = V_2 -> V_32 ;
switch ( V_32 -> V_33 -> V_34 ) {
case V_161 :
case V_162 :
if ( V_32 -> V_154 -> V_34 == V_210 ) {
V_2 -> V_36 = V_211 ;
return 0 ;
}
default:
F_54 ( F_4 ( V_2 -> V_6 ) ,
L_49 ,
V_32 -> V_154 -> V_34 , V_32 -> V_33 -> V_34 ) ;
V_32 -> V_154 -> error = - V_212 ;
}
return - V_212 ;
}
static bool F_82 ( struct V_1 * V_2 )
{
struct V_62 * V_32 = V_2 -> V_32 ;
struct V_156 * V_33 = V_32 -> V_33 ;
if ( V_2 -> V_26 ) {
V_33 -> error = F_16 ( V_2 ) ;
return false ;
}
F_78 ( V_2 ) ;
if ( ! V_32 -> V_4 )
return false ;
if ( V_2 -> V_73 ) {
F_47 ( V_2 ) ;
if ( ! V_32 -> V_154 )
V_2 -> V_36 = V_213 ;
else if ( F_81 ( V_2 ) < 0 )
return false ;
} else if ( V_32 -> V_4 -> V_59 & V_60 ) {
if ( V_33 -> V_34 == V_161 ||
( V_33 -> V_34 == V_163 &&
V_32 -> V_4 -> V_51 > 1 ) )
V_2 -> V_36 = V_214 ;
else
V_2 -> V_36 = V_215 ;
} else {
if ( V_33 -> V_34 == V_162 ||
( V_33 -> V_34 == V_163 &&
V_32 -> V_4 -> V_51 > 1 ) )
V_2 -> V_36 = V_216 ;
else
V_2 -> V_36 = V_217 ;
}
return true ;
}
static bool F_83 ( struct V_1 * V_2 )
{
int V_91 = F_79 ( V_2 ) ;
F_28 ( V_2 , true ) ;
if ( V_91 < 0 )
return false ;
V_2 -> V_36 = V_71 ;
return true ;
}
static bool F_84 ( struct V_1 * V_2 )
{
int V_91 = F_79 ( V_2 ) ;
if ( V_91 < 0 )
return false ;
F_31 ( V_2 ) ;
return ! V_2 -> V_32 -> V_4 -> error &&
( V_2 -> V_36 != V_71 || ! V_2 -> V_32 -> V_154 ) ;
}
static bool F_85 ( struct V_1 * V_2 )
{
int V_91 = F_80 ( V_2 ) ;
F_28 ( V_2 , true ) ;
if ( V_91 < 0 )
return false ;
V_2 -> V_36 = V_71 ;
return true ;
}
static bool F_86 ( struct V_1 * V_2 )
{
int V_91 = F_80 ( V_2 ) ;
if ( V_91 < 0 )
return false ;
F_31 ( V_2 ) ;
return ! V_2 -> V_32 -> V_4 -> error &&
( V_2 -> V_36 != V_71 || ! V_2 -> V_32 -> V_154 ) ;
}
static T_6 F_87 ( int V_218 , void * V_219 )
{
struct V_1 * V_2 = V_219 ;
struct V_62 * V_32 ;
struct V_156 * V_33 ;
struct V_46 * V_4 ;
bool V_220 = false ;
F_73 ( & V_2 -> V_183 ) ;
V_32 = V_2 -> V_32 ;
if ( ! V_32 )
return V_221 ;
V_33 = V_32 -> V_33 ;
V_4 = V_32 -> V_4 ;
switch ( V_2 -> V_36 ) {
case V_155 :
return V_221 ;
case V_37 :
V_220 = F_82 ( V_2 ) ;
break;
case V_214 :
V_220 = F_84 ( V_2 ) ;
break;
case V_215 :
V_220 = F_83 ( V_2 ) ;
break;
case V_216 :
V_220 = F_86 ( V_2 ) ;
break;
case V_217 :
V_220 = F_85 ( V_2 ) ;
break;
case V_213 :
F_46 ( V_2 ) ;
break;
case V_211 :
F_1 ( V_2 , V_24 , 0 ) ;
if ( V_2 -> V_26 ) {
int V_91 = F_16 ( V_2 ) ;
if ( V_32 -> V_154 )
V_32 -> V_154 -> error = V_91 ;
else
V_32 -> V_4 -> error = V_91 ;
F_18 ( F_4 ( V_2 -> V_6 ) , L_48 , V_7 , V_91 ) ;
break;
}
F_77 ( V_2 ) ;
V_32 -> V_154 -> error = 0 ;
break;
case V_71 :
if ( V_2 -> V_26 ) {
V_32 -> V_4 -> error = F_16 ( V_2 ) ;
F_18 ( F_4 ( V_2 -> V_6 ) , L_48 , V_7 ,
V_32 -> V_4 -> error ) ;
}
break;
default:
V_33 -> error = - V_222 ;
F_54 ( F_4 ( V_2 -> V_6 ) , L_50 , V_2 -> V_36 ) ;
F_66 ( V_2 ) ;
return V_221 ;
}
if ( V_220 ) {
F_71 ( & V_2 -> V_183 , V_2 -> V_184 ) ;
if ( ! V_2 -> V_73 )
F_13 ( V_2 , V_32 -> V_4 -> V_59 & V_60 ) ;
return V_221 ;
}
if ( ! V_33 -> error ) {
if ( V_4 ) {
if ( ! V_4 -> error ) {
if ( V_2 -> V_36 != V_211 &&
V_2 -> V_32 -> V_154 &&
! V_2 -> V_32 -> V_154 -> error &&
! F_81 ( V_2 ) ) {
F_12 ( V_2 ) ;
F_71 ( & V_2 -> V_183 ,
V_2 -> V_184 ) ;
return V_221 ;
}
V_4 -> V_100 = V_4 -> V_51 * V_4 -> V_50 ;
} else {
F_18 ( F_4 ( V_2 -> V_6 ) , L_51 ,
V_7 , V_4 -> error ) ;
F_28 ( V_2 , true ) ;
}
} else if ( V_33 -> V_34 == V_223 ) {
V_2 -> V_157 = true ;
}
}
F_66 ( V_2 ) ;
return V_221 ;
}
static T_6 F_88 ( int V_218 , void * V_219 )
{
struct V_1 * V_2 = V_219 ;
T_2 V_188 , V_224 , error ;
V_188 = F_7 ( V_2 , V_99 ) & ~ V_2 -> V_10 &
~ V_225 ;
V_224 = F_7 ( V_2 , V_121 ) & ~ V_2 -> V_12 ;
F_14 ( V_2 ) ;
F_17 ( F_4 ( V_2 -> V_6 ) ,
L_52 , V_188 , V_224 ) ;
if ( ! V_188 && ! V_224 )
return V_226 ;
error = V_224 & V_19 ;
if ( V_11 & V_188 )
F_1 ( V_2 , V_99 ,
0xffff & ~ ( V_11 & V_188 ) ) ;
if ( V_13 & V_224 ) {
if ( error )
V_224 |= V_22 | V_21 ;
F_1 ( V_2 , V_121 ,
0xffff & ~ ( V_13 & V_224 ) ) ;
}
V_2 -> V_26 = error ;
V_2 -> V_101 = V_188 ;
if ( error ) {
if ( V_2 -> V_36 != V_37 ||
error != V_27 )
F_18 ( F_4 ( V_2 -> V_6 ) ,
L_53 ,
V_7 , error ) ;
else
F_17 ( F_4 ( V_2 -> V_6 ) ,
L_53 ,
V_7 , error ) ;
}
return V_227 ;
}
static T_6 F_89 ( int V_218 , void * V_219 )
{
struct V_1 * V_2 = V_219 ;
T_1 V_188 = F_7 ( V_2 , V_228 ) & ~ V_2 -> V_195 ;
F_17 ( F_4 ( V_2 -> V_6 ) , L_54 , V_7 , V_188 ) ;
if ( ! V_188 )
return V_226 ;
F_1 ( V_2 , V_228 , ~ V_188 ) ;
F_90 ( V_2 -> V_6 ) ;
return V_221 ;
}
static T_6 F_91 ( int V_218 , void * V_219 )
{
struct V_1 * V_2 = V_219 ;
struct V_130 * V_6 = V_2 -> V_6 ;
T_2 V_188 ;
V_188 = F_7 ( V_2 , V_99 ) & ~ V_2 -> V_10 &
V_225 ;
if ( ! V_188 )
return V_226 ;
F_1 ( V_2 , V_99 , ~ V_188 ) ;
if ( ! F_92 ( & V_6 -> V_229 . V_230 ) &&
( ( ( V_188 & V_231 ) &&
! V_6 -> V_232 ) ||
( ( V_188 & V_233 ) &&
V_6 -> V_232 ) ) )
F_93 ( V_6 , F_94 ( 100 ) ) ;
return V_221 ;
}
static void F_95 ( struct V_234 * V_230 )
{
struct V_235 * V_208 = F_96 ( V_230 ) ;
struct V_1 * V_2 = F_97 ( V_208 , struct V_1 , V_183 ) ;
struct V_62 * V_32 = V_2 -> V_32 ;
struct V_46 * V_4 = V_32 ? V_32 -> V_4 : NULL ;
struct V_44 * V_45 ;
F_18 ( F_4 ( V_2 -> V_6 ) ,
L_55 ,
V_2 -> V_73 ? L_36 : L_37 ,
V_2 -> V_36 , V_32 ? V_32 -> V_33 -> V_34 : - 1 ,
F_7 ( V_2 , V_99 ) ,
F_7 ( V_2 , V_121 ) , V_2 -> V_101 ) ;
if ( V_2 -> V_73 ) {
F_44 ( V_2 ) ;
F_35 ( V_2 ) ;
}
switch ( V_2 -> V_36 ) {
default:
F_54 ( F_4 ( V_2 -> V_6 ) , L_50 , V_2 -> V_36 ) ;
case V_37 :
F_16 ( V_2 ) ;
if ( V_32 )
V_32 -> V_33 -> error = - V_38 ;
break;
case V_211 :
F_16 ( V_2 ) ;
V_32 -> V_154 -> error = - V_38 ;
break;
case V_213 :
case V_214 :
case V_216 :
case V_215 :
case V_217 :
V_45 = V_2 -> V_45 ? : V_4 -> V_45 ;
F_17 ( F_4 ( V_2 -> V_6 ) ,
L_56 ,
V_4 -> V_59 & V_60 ? 'R' : 'W' , V_2 -> V_66 ,
V_2 -> V_52 , V_4 -> V_51 , V_4 -> V_50 , V_4 -> V_49 ,
F_25 ( V_45 ) , V_45 -> V_52 ) ;
F_28 ( V_2 , true ) ;
case V_71 :
F_16 ( V_2 ) ;
V_4 -> error = - V_38 ;
}
if ( V_32 )
F_66 ( V_2 ) ;
}
static int F_98 ( struct V_236 * V_237 )
{
struct V_79 * V_80 = & V_237 -> V_80 ;
struct V_130 * V_6 ;
struct V_1 * V_2 ;
struct V_238 * V_239 ;
int V_240 , V_241 , V_242 ;
T_1 V_243 ;
int V_91 ;
if ( ! V_80 -> V_244 )
return - V_98 ;
V_240 = F_99 ( V_237 , L_57 ) ;
V_241 = F_99 ( V_237 , L_27 ) ;
V_242 = F_99 ( V_237 , L_58 ) ;
if ( V_241 < 0 || V_242 < 0 )
return - V_98 ;
V_6 = F_100 ( sizeof( struct V_1 ) , V_80 ) ;
if ( ! V_6 )
return - V_207 ;
V_91 = F_101 ( V_6 ) ;
if ( V_91 == - V_245 )
goto V_246;
V_91 = F_102 ( V_6 ) ;
if ( V_91 < 0 )
goto V_246;
V_2 = F_63 ( V_6 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_36 = V_155 ;
V_2 -> V_184 = F_94 ( 4000 ) ;
V_239 = F_103 ( V_237 , V_247 , 0 ) ;
V_2 -> V_5 = F_104 ( V_80 , V_239 ) ;
if ( F_58 ( V_2 -> V_5 ) ) {
V_91 = F_105 ( V_2 -> V_5 ) ;
goto V_246;
}
V_2 -> V_248 = F_106 ( V_80 , NULL ) ;
if ( F_58 ( V_2 -> V_248 ) ) {
V_91 = F_105 ( V_2 -> V_248 ) ;
goto V_246;
}
V_2 -> V_126 = F_107 ( V_2 -> V_248 ) ;
V_91 = F_108 ( V_2 -> V_248 ) ;
if ( V_91 < 0 )
goto V_246;
V_243 = F_7 ( V_2 , V_249 ) ;
if ( ( V_243 & 0xfff ) != 0xa0d ) {
F_54 ( V_80 , L_59 , V_243 ) ;
goto V_250;
}
F_109 ( V_80 , L_60 ,
F_7 ( V_2 , V_251 ) >> V_252 ) ;
F_15 ( V_2 ) ;
if ( V_240 >= 0 ) {
V_91 = F_110 ( V_80 , V_240 , F_91 , 0 ,
F_38 ( V_80 ) , V_2 ) ;
if ( V_91 < 0 )
goto V_250;
} else {
V_6 -> V_253 |= V_254 ;
}
V_91 = F_111 ( V_80 , V_241 , F_88 , F_87 , 0 ,
F_38 ( V_80 ) , V_2 ) ;
if ( V_91 < 0 )
goto V_250;
V_91 = F_110 ( V_80 , V_242 , F_89 , 0 ,
F_38 ( V_80 ) , V_2 ) ;
if ( V_91 < 0 )
goto V_250;
F_112 ( & V_2 -> V_183 , F_95 ) ;
F_49 ( V_2 , V_239 -> V_102 ) ;
V_6 -> V_255 = & V_256 ;
V_6 -> V_253 |= V_257 | V_258 |
V_259 | V_260 | V_261 ;
V_6 -> V_262 = 32 ;
V_6 -> V_263 = 512 ;
V_6 -> V_264 = V_61 * V_6 -> V_262 ;
V_6 -> V_265 = V_6 -> V_264 / V_6 -> V_263 ;
V_6 -> V_266 = V_6 -> V_264 ;
if ( ! V_6 -> V_267 )
V_6 -> V_267 = V_2 -> V_126 ;
V_6 -> V_268 = V_2 -> V_126 / 512 ;
F_113 ( V_237 , V_2 ) ;
V_91 = F_114 ( V_6 ) ;
if ( V_91 < 0 )
goto V_250;
return 0 ;
V_250:
F_115 ( V_2 -> V_248 ) ;
V_246:
F_116 ( V_6 ) ;
return V_91 ;
}
static int F_117 ( struct V_236 * V_237 )
{
struct V_1 * V_2 = F_118 ( V_237 ) ;
F_119 ( V_2 -> V_6 ) ;
F_15 ( V_2 ) ;
F_73 ( & V_2 -> V_183 ) ;
F_33 ( V_2 ) ;
F_115 ( V_2 -> V_248 ) ;
F_116 ( V_2 -> V_6 ) ;
return 0 ;
}
