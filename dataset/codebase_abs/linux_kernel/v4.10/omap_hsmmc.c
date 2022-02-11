static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 -> V_5 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 -> V_5 ) ;
}
static int F_5 ( struct V_6 * V_5 )
{
int V_7 ;
struct V_3 * V_4 = F_6 ( V_5 ) ;
struct V_8 * V_9 = & V_5 -> V_9 ;
if ( V_5 -> V_10 . V_11 ) {
V_7 = F_7 ( V_5 , V_5 -> V_10 . V_11 , V_9 -> V_12 ) ;
if ( V_7 )
return V_7 ;
}
if ( V_5 -> V_10 . V_13 && ! V_4 -> V_14 ) {
V_7 = F_8 ( V_5 -> V_10 . V_13 ) ;
if ( V_7 ) {
F_9 ( F_10 ( V_5 ) , L_1 ) ;
goto V_15;
}
V_4 -> V_14 = 1 ;
}
return 0 ;
V_15:
if ( V_5 -> V_10 . V_11 )
F_7 ( V_5 , V_5 -> V_10 . V_11 , 0 ) ;
return V_7 ;
}
static int F_11 ( struct V_6 * V_5 )
{
int V_7 ;
int V_16 ;
struct V_3 * V_4 = F_6 ( V_5 ) ;
if ( V_5 -> V_10 . V_13 && V_4 -> V_14 ) {
V_7 = F_12 ( V_5 -> V_10 . V_13 ) ;
if ( V_7 ) {
F_9 ( F_10 ( V_5 ) , L_2 ) ;
return V_7 ;
}
V_4 -> V_14 = 0 ;
}
if ( V_5 -> V_10 . V_11 ) {
V_7 = F_7 ( V_5 , V_5 -> V_10 . V_11 , 0 ) ;
if ( V_7 )
goto V_17;
}
return 0 ;
V_17:
if ( V_5 -> V_10 . V_13 ) {
V_16 = F_8 ( V_5 -> V_10 . V_13 ) ;
if ( V_16 )
F_9 ( F_10 ( V_5 ) , L_3 ) ;
}
return V_7 ;
}
static int F_13 ( struct V_3 * V_4 , bool V_18 ,
int V_12 )
{
int V_7 ;
if ( ! V_4 -> V_19 )
return 0 ;
if ( V_18 ) {
if ( V_12 <= V_20 )
V_7 = F_14 ( V_4 -> V_19 , V_21 ,
V_21 ) ;
else
V_7 = F_14 ( V_4 -> V_19 , V_22 ,
V_22 ) ;
if ( V_7 < 0 ) {
F_9 ( V_4 -> V_2 , L_4 ) ;
return V_7 ;
}
if ( V_4 -> V_23 == 0 ) {
V_7 = F_8 ( V_4 -> V_19 ) ;
if ( V_7 ) {
F_9 ( V_4 -> V_2 , L_5 ) ;
return V_7 ;
}
V_4 -> V_23 = 1 ;
}
} else {
if ( V_4 -> V_23 == 1 ) {
V_7 = F_12 ( V_4 -> V_19 ) ;
if ( V_7 ) {
F_9 ( V_4 -> V_2 , L_6 ) ;
return V_7 ;
}
V_4 -> V_23 = 0 ;
}
}
return 0 ;
}
static int F_15 ( struct V_3 * V_4 , int V_18 ,
int V_12 )
{
struct V_6 * V_5 = V_4 -> V_5 ;
int V_7 = 0 ;
if ( F_16 ( V_4 ) -> V_24 )
return F_16 ( V_4 ) -> V_24 ( V_4 -> V_2 , V_18 , V_12 ) ;
if ( ! V_5 -> V_10 . V_11 )
return 0 ;
if ( F_16 ( V_4 ) -> V_25 )
F_16 ( V_4 ) -> V_25 ( V_4 -> V_2 , V_18 , V_12 ) ;
V_7 = F_13 ( V_4 , false , 0 ) ;
if ( V_7 )
return V_7 ;
if ( V_18 ) {
V_7 = F_5 ( V_5 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_13 ( V_4 , true , V_12 ) ;
if ( V_7 )
goto V_26;
} else {
V_7 = F_11 ( V_5 ) ;
if ( V_7 )
return V_7 ;
}
if ( F_16 ( V_4 ) -> V_27 )
F_16 ( V_4 ) -> V_27 ( V_4 -> V_2 , V_18 , V_12 ) ;
return 0 ;
V_26:
F_11 ( V_5 ) ;
return V_7 ;
}
static int F_17 ( struct V_28 * V_29 )
{
int V_7 ;
if ( ! V_29 )
return 0 ;
if ( F_18 ( V_29 ) ) {
V_7 = F_8 ( V_29 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_12 ( V_29 ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
}
static int F_19 ( struct V_3 * V_4 )
{
struct V_6 * V_5 = V_4 -> V_5 ;
int V_7 ;
V_7 = F_17 ( V_5 -> V_10 . V_11 ) ;
if ( V_7 ) {
F_9 ( V_4 -> V_2 , L_7 ) ;
return V_7 ;
}
V_7 = F_17 ( V_5 -> V_10 . V_13 ) ;
if ( V_7 ) {
F_9 ( V_4 -> V_2 ,
L_8 ) ;
return V_7 ;
}
V_7 = F_17 ( V_4 -> V_19 ) ;
if ( V_7 ) {
F_9 ( V_4 -> V_2 ,
L_9 ) ;
return V_7 ;
}
return 0 ;
}
static int F_20 ( struct V_3 * V_4 )
{
int V_30 = 0 ;
int V_7 ;
struct V_6 * V_5 = V_4 -> V_5 ;
if ( F_16 ( V_4 ) -> V_24 )
return 0 ;
V_5 -> V_10 . V_11 = F_21 ( V_4 -> V_2 , L_10 ) ;
if ( F_22 ( V_5 -> V_10 . V_11 ) ) {
V_7 = F_23 ( V_5 -> V_10 . V_11 ) ;
if ( ( V_7 != - V_31 ) && V_4 -> V_2 -> V_32 )
return V_7 ;
F_24 ( V_4 -> V_2 , L_11 ,
F_23 ( V_5 -> V_10 . V_11 ) ) ;
V_5 -> V_10 . V_11 = NULL ;
} else {
V_30 = F_25 ( V_5 -> V_10 . V_11 ) ;
if ( V_30 > 0 )
F_16 ( V_4 ) -> V_33 = V_30 ;
}
V_5 -> V_10 . V_13 = F_21 ( V_4 -> V_2 , L_12 ) ;
if ( F_22 ( V_5 -> V_10 . V_13 ) ) {
V_7 = F_23 ( V_5 -> V_10 . V_13 ) ;
if ( ( V_7 != - V_31 ) && V_4 -> V_2 -> V_32 )
return V_7 ;
F_24 ( V_4 -> V_2 , L_13 ,
F_23 ( V_5 -> V_10 . V_13 ) ) ;
V_5 -> V_10 . V_13 = NULL ;
}
V_4 -> V_19 = F_21 ( V_4 -> V_2 , L_14 ) ;
if ( F_22 ( V_4 -> V_19 ) ) {
V_7 = F_23 ( V_4 -> V_19 ) ;
if ( ( V_7 != - V_31 ) && V_4 -> V_2 -> V_32 ) {
F_9 ( V_4 -> V_2 ,
L_15 ) ;
return V_7 ;
}
F_24 ( V_4 -> V_2 , L_16 ,
F_23 ( V_4 -> V_19 ) ) ;
V_4 -> V_19 = NULL ;
}
if ( F_16 ( V_4 ) -> V_34 )
return 0 ;
V_7 = F_19 ( V_4 ) ;
if ( V_7 )
return V_7 ;
return 0 ;
}
static int F_26 ( struct V_6 * V_5 ,
struct V_3 * V_4 ,
struct V_35 * V_36 )
{
int V_7 ;
if ( F_27 ( V_36 -> V_37 ) ) {
V_7 = F_28 ( V_5 , V_36 -> V_37 , 0 ) ;
if ( V_7 )
return V_7 ;
V_4 -> V_38 = F_4 ;
F_29 ( V_5 , V_39 ) ;
} else if ( F_27 ( V_36 -> V_40 ) ) {
V_7 = F_28 ( V_5 , V_36 -> V_40 , 0 ) ;
if ( V_7 )
return V_7 ;
V_4 -> V_41 = F_1 ;
}
if ( F_27 ( V_36 -> V_42 ) ) {
V_7 = F_30 ( V_5 , V_36 -> V_42 ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
}
static void F_31 ( struct V_3 * V_4 )
{
F_32 ( V_4 -> V_43 , V_44 ,
F_33 ( V_4 -> V_43 , V_44 ) | V_45 ) ;
}
static void F_34 ( struct V_3 * V_4 )
{
F_32 ( V_4 -> V_43 , V_44 ,
F_33 ( V_4 -> V_43 , V_44 ) & ~ V_45 ) ;
if ( ( F_33 ( V_4 -> V_43 , V_44 ) & V_45 ) != 0x0 )
F_24 ( F_10 ( V_4 -> V_5 ) , L_17 ) ;
}
static void F_35 ( struct V_3 * V_4 ,
struct V_46 * V_47 )
{
T_1 V_48 = V_49 ;
unsigned long V_50 ;
if ( V_4 -> V_51 )
V_48 &= ~ ( V_52 | V_53 ) ;
if ( V_47 -> V_54 == V_55 )
V_48 &= ~ V_56 ;
F_36 ( & V_4 -> V_57 , V_50 ) ;
F_32 ( V_4 -> V_43 , V_58 , V_59 ) ;
F_32 ( V_4 -> V_43 , V_60 , V_48 ) ;
if ( V_4 -> V_50 & V_61 )
V_48 |= V_62 ;
F_32 ( V_4 -> V_43 , V_63 , V_48 ) ;
F_37 ( & V_4 -> V_57 , V_50 ) ;
}
static void F_38 ( struct V_3 * V_4 )
{
T_1 V_48 = 0 ;
unsigned long V_50 ;
F_36 ( & V_4 -> V_57 , V_50 ) ;
if ( V_4 -> V_50 & V_61 )
V_48 |= V_62 ;
F_32 ( V_4 -> V_43 , V_60 , V_48 ) ;
F_32 ( V_4 -> V_43 , V_63 , V_48 ) ;
F_32 ( V_4 -> V_43 , V_58 , V_59 ) ;
F_37 ( & V_4 -> V_57 , V_50 ) ;
}
static T_2 F_39 ( struct V_3 * V_4 , struct V_8 * V_9 )
{
T_2 V_64 = 0 ;
if ( V_9 -> clock ) {
V_64 = F_40 ( F_41 ( V_4 -> V_65 ) , V_9 -> clock ) ;
if ( V_64 > V_66 )
V_64 = V_66 ;
}
return V_64 ;
}
static void F_42 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_5 -> V_9 ;
unsigned long V_67 ;
unsigned long V_68 ;
unsigned long V_69 ;
F_43 ( F_10 ( V_4 -> V_5 ) , L_18 , V_9 -> clock ) ;
F_34 ( V_4 ) ;
V_67 = F_33 ( V_4 -> V_43 , V_44 ) ;
V_67 = V_67 & ~ ( V_70 | V_71 ) ;
V_69 = F_39 ( V_4 , V_9 ) ;
V_67 = V_67 | ( V_69 << 6 ) | ( V_72 << 16 ) ;
F_32 ( V_4 -> V_43 , V_44 , V_67 ) ;
F_32 ( V_4 -> V_43 , V_44 ,
F_33 ( V_4 -> V_43 , V_44 ) | V_73 ) ;
V_68 = V_74 + F_44 ( V_75 ) ;
while ( ( F_33 ( V_4 -> V_43 , V_44 ) & V_76 ) != V_76
&& F_45 ( V_74 , V_68 ) )
F_46 () ;
if ( ( F_16 ( V_4 ) -> V_77 & V_78 ) &&
( V_9 -> V_79 != V_80 ) &&
( V_9 -> V_79 != V_81 ) &&
( ( F_33 ( V_4 -> V_43 , V_82 ) & V_83 ) == V_83 ) ) {
V_67 = F_33 ( V_4 -> V_43 , V_84 ) ;
if ( V_69 && ( F_41 ( V_4 -> V_65 ) / V_69 ) > 25000000 )
V_67 |= V_85 ;
else
V_67 &= ~ V_85 ;
F_32 ( V_4 -> V_43 , V_84 , V_67 ) ;
}
F_31 ( V_4 ) ;
}
static void F_47 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_5 -> V_9 ;
T_1 V_86 ;
V_86 = F_33 ( V_4 -> V_43 , V_87 ) ;
if ( V_9 -> V_79 == V_80 ||
V_9 -> V_79 == V_81 )
V_86 |= V_88 ;
else
V_86 &= ~ V_88 ;
switch ( V_9 -> V_89 ) {
case V_90 :
F_32 ( V_4 -> V_43 , V_87 , V_86 | V_91 ) ;
break;
case V_92 :
F_32 ( V_4 -> V_43 , V_87 , V_86 & ~ V_91 ) ;
F_32 ( V_4 -> V_43 , V_84 ,
F_33 ( V_4 -> V_43 , V_84 ) | V_93 ) ;
break;
case V_94 :
F_32 ( V_4 -> V_43 , V_87 , V_86 & ~ V_91 ) ;
F_32 ( V_4 -> V_43 , V_84 ,
F_33 ( V_4 -> V_43 , V_84 ) & ~ V_93 ) ;
break;
}
}
static void F_48 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_5 -> V_9 ;
T_1 V_86 ;
V_86 = F_33 ( V_4 -> V_43 , V_87 ) ;
if ( V_9 -> V_95 == V_96 )
F_32 ( V_4 -> V_43 , V_87 , V_86 | V_97 ) ;
else
F_32 ( V_4 -> V_43 , V_87 , V_86 & ~ V_97 ) ;
}
static int F_49 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_5 -> V_9 ;
T_1 V_98 , V_99 ;
unsigned long V_68 ;
if ( V_4 -> V_86 == F_33 ( V_4 -> V_43 , V_87 ) &&
V_4 -> V_98 == F_33 ( V_4 -> V_43 , V_84 ) &&
V_4 -> V_100 == F_33 ( V_4 -> V_43 , V_44 ) &&
V_4 -> V_99 == F_33 ( V_4 -> V_43 , V_82 ) )
return 0 ;
V_4 -> V_101 ++ ;
if ( V_4 -> V_36 -> V_102 & V_103 ) {
if ( V_4 -> V_104 != V_105 &&
( 1 << V_9 -> V_12 ) <= V_106 )
V_98 = V_107 ;
else
V_98 = V_108 ;
V_99 = V_109 | V_110 ;
} else {
V_98 = V_107 ;
V_99 = V_110 ;
}
if ( V_4 -> V_5 -> V_111 & V_112 )
V_98 |= V_113 ;
F_32 ( V_4 -> V_43 , V_84 ,
F_33 ( V_4 -> V_43 , V_84 ) | V_98 ) ;
F_32 ( V_4 -> V_43 , V_82 ,
F_33 ( V_4 -> V_43 , V_82 ) | V_99 ) ;
F_32 ( V_4 -> V_43 , V_84 ,
F_33 ( V_4 -> V_43 , V_84 ) | V_114 ) ;
V_68 = V_74 + F_44 ( V_75 ) ;
while ( ( F_33 ( V_4 -> V_43 , V_84 ) & V_114 ) != V_114
&& F_45 ( V_74 , V_68 ) )
;
F_32 ( V_4 -> V_43 , V_60 , 0 ) ;
F_32 ( V_4 -> V_43 , V_63 , 0 ) ;
F_32 ( V_4 -> V_43 , V_58 , V_59 ) ;
if ( V_4 -> V_104 == V_105 )
goto V_115;
F_47 ( V_4 ) ;
F_42 ( V_4 ) ;
F_48 ( V_4 ) ;
V_115:
F_24 ( F_10 ( V_4 -> V_5 ) , L_19 ,
V_4 -> V_101 ) ;
return 0 ;
}
static void F_50 ( struct V_3 * V_4 )
{
V_4 -> V_86 = F_33 ( V_4 -> V_43 , V_87 ) ;
V_4 -> V_98 = F_33 ( V_4 -> V_43 , V_84 ) ;
V_4 -> V_100 = F_33 ( V_4 -> V_43 , V_44 ) ;
V_4 -> V_99 = F_33 ( V_4 -> V_43 , V_82 ) ;
}
static int F_49 ( struct V_3 * V_4 )
{
return 0 ;
}
static void F_50 ( struct V_3 * V_4 )
{
}
static void F_51 ( struct V_3 * V_4 )
{
int V_29 = 0 ;
unsigned long V_68 ;
if ( V_4 -> V_116 )
return;
F_52 ( V_4 -> V_117 ) ;
F_32 ( V_4 -> V_43 , V_63 , V_49 ) ;
F_32 ( V_4 -> V_43 , V_87 ,
F_33 ( V_4 -> V_43 , V_87 ) | V_118 ) ;
F_32 ( V_4 -> V_43 , V_119 , V_120 ) ;
V_68 = V_74 + F_44 ( V_75 ) ;
while ( ( V_29 != V_121 ) && F_45 ( V_74 , V_68 ) )
V_29 = F_33 ( V_4 -> V_43 , V_58 ) & V_121 ;
F_32 ( V_4 -> V_43 , V_87 ,
F_33 ( V_4 -> V_43 , V_87 ) & ~ V_118 ) ;
F_32 ( V_4 -> V_43 , V_58 , V_59 ) ;
F_33 ( V_4 -> V_43 , V_58 ) ;
F_53 ( V_4 -> V_117 ) ;
}
static inline
int F_54 ( struct V_3 * V_4 )
{
int V_122 = 1 ;
if ( V_4 -> V_38 )
V_122 = V_4 -> V_38 ( V_4 -> V_2 ) ;
return V_122 ;
}
static T_3
F_55 ( struct V_1 * V_2 , struct V_123 * V_124 ,
char * V_125 )
{
struct V_6 * V_5 = F_56 ( V_2 , struct V_6 , V_126 ) ;
struct V_3 * V_4 = F_6 ( V_5 ) ;
return sprintf ( V_125 , L_20 ,
F_54 ( V_4 ) ? L_21 : L_22 ) ;
}
static T_3
F_57 ( struct V_1 * V_2 , struct V_123 * V_124 ,
char * V_125 )
{
struct V_6 * V_5 = F_56 ( V_2 , struct V_6 , V_126 ) ;
struct V_3 * V_4 = F_6 ( V_5 ) ;
return sprintf ( V_125 , L_20 , F_16 ( V_4 ) -> V_127 ) ;
}
static void
F_58 ( struct V_3 * V_4 , struct V_46 * V_47 ,
struct V_128 * V_129 )
{
int V_130 = 0 , V_131 = 0 , V_132 = 0 ;
F_43 ( F_10 ( V_4 -> V_5 ) , L_23 ,
F_59 ( V_4 -> V_5 ) , V_47 -> V_54 , V_47 -> V_133 ) ;
V_4 -> V_47 = V_47 ;
F_35 ( V_4 , V_47 ) ;
V_4 -> V_134 = 0 ;
if ( V_47 -> V_50 & V_135 ) {
if ( V_47 -> V_50 & V_136 )
V_131 = 1 ;
else if ( V_47 -> V_50 & V_137 ) {
V_131 = 3 ;
V_4 -> V_134 = 1 ;
} else
V_131 = 2 ;
}
if ( V_47 == V_4 -> V_138 -> V_139 )
V_132 = 0x3 ;
V_130 = ( V_47 -> V_54 << 24 ) | ( V_131 << 16 ) | ( V_132 << 22 ) ;
if ( ( V_4 -> V_50 & V_140 ) && F_60 ( V_47 -> V_54 ) &&
V_4 -> V_138 -> V_141 ) {
V_130 |= V_142 ;
F_32 ( V_4 -> V_43 , V_143 , V_4 -> V_138 -> V_141 -> V_133 ) ;
}
if ( V_129 ) {
V_130 |= V_144 | V_145 | V_146 ;
if ( V_129 -> V_50 & V_147 )
V_130 |= V_148 ;
else
V_130 &= ~ ( V_148 ) ;
}
if ( V_4 -> V_51 )
V_130 |= V_149 ;
V_4 -> V_150 = 1 ;
F_32 ( V_4 -> V_43 , V_151 , V_47 -> V_133 ) ;
F_32 ( V_4 -> V_43 , V_119 , V_130 ) ;
}
static int
F_61 ( struct V_3 * V_4 , struct V_128 * V_129 )
{
if ( V_129 -> V_50 & V_152 )
return V_153 ;
else
return V_154 ;
}
static struct V_155 * F_62 ( struct V_3 * V_4 ,
struct V_128 * V_129 )
{
return V_129 -> V_50 & V_152 ? V_4 -> V_156 : V_4 -> V_157 ;
}
static void F_63 ( struct V_3 * V_4 , struct V_158 * V_138 )
{
int V_159 ;
unsigned long V_50 ;
F_36 ( & V_4 -> V_57 , V_50 ) ;
V_4 -> V_150 = 0 ;
V_159 = V_4 -> V_159 ;
F_37 ( & V_4 -> V_57 , V_50 ) ;
F_38 ( V_4 ) ;
if ( V_138 -> V_129 && V_4 -> V_51 && V_159 != - 1 )
return;
V_4 -> V_138 = NULL ;
F_64 ( V_4 -> V_5 , V_138 ) ;
}
static void
F_65 ( struct V_3 * V_4 , struct V_128 * V_129 )
{
if ( ! V_129 ) {
struct V_158 * V_138 = V_4 -> V_138 ;
if ( V_4 -> V_47 && V_4 -> V_47 -> V_54 == 6 &&
V_4 -> V_134 ) {
V_4 -> V_134 = 0 ;
return;
}
F_63 ( V_4 , V_138 ) ;
return;
}
V_4 -> V_129 = NULL ;
if ( ! V_129 -> error )
V_129 -> V_160 += V_129 -> V_161 * ( V_129 -> V_162 ) ;
else
V_129 -> V_160 = 0 ;
if ( V_129 -> V_139 && ( V_129 -> error || ! V_4 -> V_138 -> V_141 ) )
F_58 ( V_4 , V_129 -> V_139 , NULL ) ;
else
F_63 ( V_4 , V_129 -> V_138 ) ;
}
static void
F_66 ( struct V_3 * V_4 , struct V_46 * V_47 )
{
if ( V_4 -> V_138 -> V_141 && ( V_4 -> V_47 == V_4 -> V_138 -> V_141 ) &&
! V_4 -> V_138 -> V_141 -> error && ! ( V_4 -> V_50 & V_140 ) ) {
V_4 -> V_47 = NULL ;
F_67 ( V_4 ) ;
F_58 ( V_4 , V_4 -> V_138 -> V_47 ,
V_4 -> V_138 -> V_129 ) ;
return;
}
V_4 -> V_47 = NULL ;
if ( V_47 -> V_50 & V_135 ) {
if ( V_47 -> V_50 & V_136 ) {
V_47 -> V_163 [ 3 ] = F_33 ( V_4 -> V_43 , V_164 ) ;
V_47 -> V_163 [ 2 ] = F_33 ( V_4 -> V_43 , V_165 ) ;
V_47 -> V_163 [ 1 ] = F_33 ( V_4 -> V_43 , V_166 ) ;
V_47 -> V_163 [ 0 ] = F_33 ( V_4 -> V_43 , V_167 ) ;
} else {
V_47 -> V_163 [ 0 ] = F_33 ( V_4 -> V_43 , V_164 ) ;
}
}
if ( ( V_4 -> V_129 == NULL && ! V_4 -> V_134 ) || V_47 -> error )
F_63 ( V_4 , V_4 -> V_138 ) ;
}
static void F_68 ( struct V_3 * V_4 , int V_168 )
{
int V_159 ;
unsigned long V_50 ;
V_4 -> V_129 -> error = V_168 ;
F_36 ( & V_4 -> V_57 , V_50 ) ;
V_159 = V_4 -> V_159 ;
V_4 -> V_159 = - 1 ;
F_37 ( & V_4 -> V_57 , V_50 ) ;
if ( V_4 -> V_51 && V_159 != - 1 ) {
struct V_155 * V_169 = F_62 ( V_4 , V_4 -> V_129 ) ;
F_69 ( V_169 ) ;
F_70 ( V_169 -> V_1 -> V_2 ,
V_4 -> V_129 -> V_170 , V_4 -> V_129 -> V_171 ,
F_61 ( V_4 , V_4 -> V_129 ) ) ;
V_4 -> V_129 -> V_172 = 0 ;
}
V_4 -> V_129 = NULL ;
}
static void F_71 ( struct V_3 * V_4 , T_1 V_16 )
{
static const char * V_173 [] = {
L_24 , L_25 , L_26 , L_27 , L_28 , L_29 , L_27 , L_27 ,
L_30 , L_31 , L_27 , L_27 , L_27 , L_27 , L_27 , L_32 ,
L_33 , L_34 , L_35 , L_36 , L_37 , L_38 , L_39 , L_27 ,
L_40 , L_27 , L_27 , L_27 , L_41 , L_42 , L_27 , L_27
} ;
char V_174 [ 256 ] ;
char * V_125 = V_174 ;
int V_175 , V_176 ;
V_175 = sprintf ( V_125 , L_43 , V_16 ) ;
V_125 += V_175 ;
for ( V_176 = 0 ; V_176 < F_72 ( V_173 ) ; V_176 ++ )
if ( V_16 & ( 1 << V_176 ) ) {
V_175 = sprintf ( V_125 , L_44 , V_173 [ V_176 ] ) ;
V_125 += V_175 ;
}
F_43 ( F_10 ( V_4 -> V_5 ) , L_20 , V_174 ) ;
}
static inline void F_71 ( struct V_3 * V_4 ,
T_1 V_16 )
{
}
static inline void F_73 ( struct V_3 * V_4 ,
unsigned long V_177 )
{
unsigned long V_176 = 0 ;
unsigned long V_178 = V_179 ;
F_32 ( V_4 -> V_43 , V_44 ,
F_33 ( V_4 -> V_43 , V_44 ) | V_177 ) ;
if ( F_16 ( V_4 ) -> V_77 & V_180 ) {
while ( ( ! ( F_33 ( V_4 -> V_43 , V_44 ) & V_177 ) )
&& ( V_176 ++ < V_178 ) )
F_74 ( 1 ) ;
}
V_176 = 0 ;
while ( ( F_33 ( V_4 -> V_43 , V_44 ) & V_177 ) &&
( V_176 ++ < V_178 ) )
F_74 ( 1 ) ;
if ( F_33 ( V_4 -> V_43 , V_44 ) & V_177 )
F_9 ( F_10 ( V_4 -> V_5 ) ,
L_45 ,
V_181 ) ;
}
static void F_75 ( struct V_3 * V_4 ,
int V_182 , int V_183 )
{
if ( V_183 ) {
F_73 ( V_4 , V_184 ) ;
if ( V_4 -> V_47 )
V_4 -> V_47 -> error = V_182 ;
}
if ( V_4 -> V_129 ) {
F_73 ( V_4 , V_185 ) ;
F_68 ( V_4 , V_182 ) ;
} else if ( V_4 -> V_138 && V_4 -> V_138 -> V_47 )
V_4 -> V_138 -> V_47 -> error = V_182 ;
}
static void F_76 ( struct V_3 * V_4 , int V_16 )
{
struct V_128 * V_129 ;
int V_183 = 0 , V_186 = 0 ;
int error = 0 ;
V_129 = V_4 -> V_129 ;
F_43 ( F_10 ( V_4 -> V_5 ) , L_46 , V_16 ) ;
if ( V_16 & V_187 ) {
F_71 ( V_4 , V_16 ) ;
if ( V_16 & ( V_188 | V_189 ) )
V_183 = 1 ;
if ( V_4 -> V_129 || V_4 -> V_134 ) {
V_186 = ! V_183 ;
V_4 -> V_134 = 0 ;
}
if ( V_16 & ( V_188 | V_56 ) )
F_75 ( V_4 , - V_190 , V_183 ) ;
else if ( V_16 & ( V_189 | V_191 | V_192 | V_193 |
V_194 ) )
F_75 ( V_4 , - V_195 , V_183 ) ;
if ( V_16 & V_196 ) {
T_1 V_197 ;
V_197 = F_33 ( V_4 -> V_43 , V_198 ) ;
if ( ! ( V_197 & V_199 ) && V_4 -> V_138 -> V_141 ) {
V_183 = 1 ;
if ( V_197 & V_200 )
error = - V_190 ;
else if ( V_197 & ( V_201 | V_202 | V_203 ) )
error = - V_195 ;
V_4 -> V_138 -> V_141 -> error = error ;
F_75 ( V_4 , error , V_183 ) ;
}
F_24 ( F_10 ( V_4 -> V_5 ) , L_47 , V_197 ) ;
}
}
F_32 ( V_4 -> V_43 , V_58 , V_16 ) ;
if ( V_183 || ( ( V_16 & V_121 ) && V_4 -> V_47 ) )
F_66 ( V_4 , V_4 -> V_47 ) ;
if ( ( V_186 || ( V_16 & V_204 ) ) && V_4 -> V_138 )
F_65 ( V_4 , V_129 ) ;
}
static T_4 F_77 ( int V_117 , void * V_205 )
{
struct V_3 * V_4 = V_205 ;
int V_16 ;
V_16 = F_33 ( V_4 -> V_43 , V_58 ) ;
while ( V_16 & ( V_49 | V_62 ) ) {
if ( V_4 -> V_150 )
F_76 ( V_4 , V_16 ) ;
if ( V_16 & V_62 )
F_78 ( V_4 -> V_5 ) ;
V_16 = F_33 ( V_4 -> V_43 , V_58 ) ;
}
return V_206 ;
}
static void F_79 ( struct V_3 * V_4 )
{
unsigned long V_176 ;
F_32 ( V_4 -> V_43 , V_84 ,
F_33 ( V_4 -> V_43 , V_84 ) | V_114 ) ;
for ( V_176 = 0 ; V_176 < V_207 ; V_176 ++ ) {
if ( F_33 ( V_4 -> V_43 , V_84 ) & V_114 )
break;
F_46 () ;
}
}
static int F_80 ( struct V_3 * V_4 , int V_12 )
{
T_1 V_208 = 0 ;
int V_7 ;
if ( V_4 -> V_209 )
F_81 ( V_4 -> V_209 ) ;
V_7 = F_15 ( V_4 , 0 , 0 ) ;
if ( ! V_7 )
V_7 = F_15 ( V_4 , 1 , V_12 ) ;
if ( V_4 -> V_209 )
F_82 ( V_4 -> V_209 ) ;
if ( V_7 != 0 )
goto V_182;
F_32 ( V_4 -> V_43 , V_84 ,
F_33 ( V_4 -> V_43 , V_84 ) & V_210 ) ;
V_208 = F_33 ( V_4 -> V_43 , V_84 ) ;
if ( ( 1 << V_12 ) <= V_106 )
V_208 |= V_107 ;
else
V_208 |= V_108 ;
F_32 ( V_4 -> V_43 , V_84 , V_208 ) ;
F_79 ( V_4 ) ;
return 0 ;
V_182:
F_9 ( F_10 ( V_4 -> V_5 ) , L_48 ) ;
return V_7 ;
}
static void F_83 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_38 )
return;
V_4 -> V_211 = 0 ;
if ( V_4 -> V_38 ( V_4 -> V_2 ) ) {
if ( V_4 -> V_116 ) {
F_84 ( V_4 -> V_2 , L_49
L_50 ,
F_59 ( V_4 -> V_5 ) ) ;
V_4 -> V_116 = 0 ;
}
} else {
if ( ! V_4 -> V_116 ) {
F_84 ( V_4 -> V_2 , L_51
L_52 ,
F_59 ( V_4 -> V_5 ) ) ;
V_4 -> V_116 = 1 ;
}
}
}
static T_4 V_39 ( int V_117 , void * V_205 )
{
struct V_3 * V_4 = V_205 ;
F_85 ( & V_4 -> V_5 -> V_126 . V_212 , NULL , L_53 ) ;
F_83 ( V_4 ) ;
F_86 ( V_4 -> V_5 , ( V_213 * 200 ) / 1000 ) ;
return V_206 ;
}
static void F_87 ( void * V_214 )
{
struct V_3 * V_4 = V_214 ;
struct V_155 * V_169 ;
struct V_128 * V_129 ;
int V_150 ;
F_88 ( & V_4 -> V_57 ) ;
if ( V_4 -> V_159 < 0 ) {
F_89 ( & V_4 -> V_57 ) ;
return;
}
V_129 = V_4 -> V_138 -> V_129 ;
V_169 = F_62 ( V_4 , V_129 ) ;
if ( ! V_129 -> V_172 )
F_70 ( V_169 -> V_1 -> V_2 ,
V_129 -> V_170 , V_129 -> V_171 ,
F_61 ( V_4 , V_129 ) ) ;
V_150 = V_4 -> V_150 ;
V_4 -> V_159 = - 1 ;
F_89 ( & V_4 -> V_57 ) ;
if ( ! V_150 ) {
struct V_158 * V_138 = V_4 -> V_138 ;
V_4 -> V_138 = NULL ;
F_64 ( V_4 -> V_5 , V_138 ) ;
}
}
static int F_90 ( struct V_3 * V_4 ,
struct V_128 * V_129 ,
struct V_215 * V_216 ,
struct V_155 * V_169 )
{
int V_217 ;
if ( ! V_216 && V_129 -> V_172 &&
V_129 -> V_172 != V_4 -> V_218 . V_219 ) {
F_91 ( V_4 -> V_2 , L_54
L_55 ,
V_181 , V_129 -> V_172 , V_4 -> V_218 . V_219 ) ;
V_129 -> V_172 = 0 ;
}
if ( V_216 || V_129 -> V_172 != V_4 -> V_218 . V_219 ) {
V_217 = F_92 ( V_169 -> V_1 -> V_2 , V_129 -> V_170 , V_129 -> V_171 ,
F_61 ( V_4 , V_129 ) ) ;
} else {
V_217 = V_4 -> V_218 . V_217 ;
V_4 -> V_218 . V_217 = 0 ;
}
if ( V_217 == 0 )
return - V_220 ;
if ( V_216 ) {
V_216 -> V_217 = V_217 ;
V_129 -> V_172 = ++ V_216 -> V_219 < 0 ? 1 : V_216 -> V_219 ;
} else
V_4 -> V_217 = V_217 ;
return 0 ;
}
static int F_93 ( struct V_3 * V_4 ,
struct V_158 * V_221 )
{
struct V_222 * V_223 ;
int V_7 = 0 , V_176 ;
struct V_128 * V_129 = V_221 -> V_129 ;
struct V_155 * V_169 ;
struct V_224 V_225 = {
. V_226 = V_4 -> V_227 + V_228 ,
. V_229 = V_4 -> V_227 + V_228 ,
. V_230 = V_231 ,
. V_232 = V_231 ,
. V_233 = V_129 -> V_162 / 4 ,
. V_234 = V_129 -> V_162 / 4 ,
} ;
for ( V_176 = 0 ; V_176 < V_129 -> V_171 ; V_176 ++ ) {
struct V_235 * V_236 ;
V_236 = V_129 -> V_170 + V_176 ;
if ( V_236 -> V_237 % V_129 -> V_162 )
return - V_220 ;
}
if ( ( V_129 -> V_162 % 4 ) != 0 )
return - V_220 ;
F_94 ( V_4 -> V_159 != - 1 ) ;
V_169 = F_62 ( V_4 , V_129 ) ;
V_7 = F_95 ( V_169 , & V_225 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_90 ( V_4 , V_129 , NULL , V_169 ) ;
if ( V_7 )
return V_7 ;
V_223 = F_96 ( V_169 , V_129 -> V_170 , V_129 -> V_171 ,
V_129 -> V_50 & V_152 ? V_238 : V_239 ,
V_240 | V_241 ) ;
if ( ! V_223 ) {
F_9 ( F_10 ( V_4 -> V_5 ) , L_56 ) ;
return - 1 ;
}
V_223 -> V_242 = F_87 ;
V_223 -> V_243 = V_4 ;
F_97 ( V_223 ) ;
V_4 -> V_159 = 1 ;
return 0 ;
}
static void F_98 ( struct V_3 * V_4 ,
unsigned int V_244 ,
unsigned int V_245 )
{
unsigned int V_68 , V_246 ;
T_5 V_29 , V_247 , V_248 = 0 ;
V_29 = F_33 ( V_4 -> V_43 , V_44 ) ;
V_247 = ( V_29 & V_70 ) >> V_249 ;
if ( V_247 == 0 )
V_247 = 1 ;
V_246 = 1000000000 / ( V_4 -> V_250 / V_247 ) ;
V_68 = V_244 / V_246 ;
V_68 += V_245 ;
if ( V_68 ) {
while ( ( V_68 & 0x80000000 ) == 0 ) {
V_248 += 1 ;
V_68 <<= 1 ;
}
V_248 = 31 - V_248 ;
V_68 <<= 1 ;
if ( V_68 && V_248 )
V_248 += 1 ;
if ( V_248 >= 13 )
V_248 -= 13 ;
else
V_248 = 0 ;
if ( V_248 > 14 )
V_248 = 14 ;
}
V_29 &= ~ V_71 ;
V_29 |= V_248 << V_251 ;
F_32 ( V_4 -> V_43 , V_44 , V_29 ) ;
}
static void F_67 ( struct V_3 * V_4 )
{
struct V_158 * V_221 = V_4 -> V_138 ;
struct V_155 * V_169 ;
if ( ! V_221 -> V_129 )
return;
F_32 ( V_4 -> V_43 , V_252 , ( V_221 -> V_129 -> V_162 )
| ( V_221 -> V_129 -> V_161 << 16 ) ) ;
F_98 ( V_4 , V_221 -> V_129 -> V_244 ,
V_221 -> V_129 -> V_245 ) ;
V_169 = F_62 ( V_4 , V_221 -> V_129 ) ;
F_99 ( V_169 ) ;
}
static int
F_100 ( struct V_3 * V_4 , struct V_158 * V_221 )
{
int V_7 ;
V_4 -> V_129 = V_221 -> V_129 ;
if ( V_221 -> V_129 == NULL ) {
F_32 ( V_4 -> V_43 , V_252 , 0 ) ;
if ( V_221 -> V_47 -> V_50 & V_137 )
F_98 ( V_4 , 100000000U , 0 ) ;
return 0 ;
}
if ( V_4 -> V_51 ) {
V_7 = F_93 ( V_4 , V_221 ) ;
if ( V_7 != 0 ) {
F_9 ( F_10 ( V_4 -> V_5 ) , L_57 ) ;
return V_7 ;
}
}
return 0 ;
}
static void F_101 ( struct V_6 * V_5 , struct V_158 * V_138 ,
int V_182 )
{
struct V_3 * V_4 = F_6 ( V_5 ) ;
struct V_128 * V_129 = V_138 -> V_129 ;
if ( V_4 -> V_51 && V_129 -> V_172 ) {
struct V_155 * V_253 = F_62 ( V_4 , V_129 ) ;
F_70 ( V_253 -> V_1 -> V_2 , V_129 -> V_170 , V_129 -> V_171 ,
F_61 ( V_4 , V_129 ) ) ;
V_129 -> V_172 = 0 ;
}
}
static void F_102 ( struct V_6 * V_5 , struct V_158 * V_138 )
{
struct V_3 * V_4 = F_6 ( V_5 ) ;
if ( V_138 -> V_129 -> V_172 ) {
V_138 -> V_129 -> V_172 = 0 ;
return ;
}
if ( V_4 -> V_51 ) {
struct V_155 * V_253 = F_62 ( V_4 , V_138 -> V_129 ) ;
if ( F_90 ( V_4 , V_138 -> V_129 ,
& V_4 -> V_218 , V_253 ) )
V_138 -> V_129 -> V_172 = 0 ;
}
}
static void F_103 ( struct V_6 * V_5 , struct V_158 * V_221 )
{
struct V_3 * V_4 = F_6 ( V_5 ) ;
int V_182 ;
F_94 ( V_4 -> V_150 ) ;
F_94 ( V_4 -> V_159 != - 1 ) ;
if ( V_4 -> V_116 ) {
if ( V_4 -> V_211 < 3 ) {
F_73 ( V_4 , V_185 ) ;
F_73 ( V_4 , V_184 ) ;
V_4 -> V_211 += 1 ;
}
V_221 -> V_47 -> error = - V_254 ;
if ( V_221 -> V_129 )
V_221 -> V_129 -> error = - V_254 ;
V_221 -> V_47 -> V_255 = 0 ;
F_64 ( V_5 , V_221 ) ;
return;
} else if ( V_4 -> V_211 )
V_4 -> V_211 = 0 ;
F_104 ( V_4 -> V_138 != NULL ) ;
V_4 -> V_138 = V_221 ;
V_4 -> V_250 = F_41 ( V_4 -> V_65 ) ;
V_182 = F_100 ( V_4 , V_221 ) ;
if ( V_182 ) {
V_221 -> V_47 -> error = V_182 ;
if ( V_221 -> V_129 )
V_221 -> V_129 -> error = V_182 ;
V_4 -> V_138 = NULL ;
F_64 ( V_5 , V_221 ) ;
return;
}
if ( V_221 -> V_141 && ! ( V_4 -> V_50 & V_140 ) ) {
F_58 ( V_4 , V_221 -> V_141 , NULL ) ;
return;
}
F_67 ( V_4 ) ;
F_58 ( V_4 , V_221 -> V_47 , V_221 -> V_129 ) ;
}
static void F_105 ( struct V_6 * V_5 , struct V_8 * V_9 )
{
struct V_3 * V_4 = F_6 ( V_5 ) ;
int V_256 = 0 ;
if ( V_9 -> V_104 != V_4 -> V_104 ) {
switch ( V_9 -> V_104 ) {
case V_105 :
F_15 ( V_4 , 0 , 0 ) ;
break;
case V_257 :
F_15 ( V_4 , 1 , V_9 -> V_12 ) ;
break;
case V_258 :
V_256 = 1 ;
break;
}
V_4 -> V_104 = V_9 -> V_104 ;
}
F_47 ( V_4 ) ;
if ( V_4 -> V_36 -> V_102 & V_103 ) {
if ( ( F_33 ( V_4 -> V_43 , V_84 ) & V_259 ) &&
( V_9 -> V_12 == V_260 ) ) {
if ( F_80 ( V_4 , V_9 -> V_12 ) != 0 )
F_24 ( F_10 ( V_4 -> V_5 ) ,
L_58 ) ;
}
}
F_42 ( V_4 ) ;
if ( V_256 )
F_51 ( V_4 ) ;
F_48 ( V_4 ) ;
}
static int F_106 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = F_6 ( V_5 ) ;
if ( ! V_4 -> V_41 )
return - V_261 ;
return V_4 -> V_41 ( V_4 -> V_2 ) ;
}
static void F_107 ( struct V_6 * V_5 , struct V_262 * V_263 )
{
struct V_3 * V_4 = F_6 ( V_5 ) ;
if ( F_16 ( V_4 ) -> V_264 )
F_16 ( V_4 ) -> V_264 ( V_263 ) ;
}
static void F_108 ( struct V_6 * V_5 , int V_265 )
{
struct V_3 * V_4 = F_6 ( V_5 ) ;
T_1 V_48 , V_86 ;
unsigned long V_50 ;
F_36 ( & V_4 -> V_57 , V_50 ) ;
V_86 = F_33 ( V_4 -> V_43 , V_87 ) ;
V_48 = F_33 ( V_4 -> V_43 , V_60 ) ;
if ( V_265 ) {
V_4 -> V_50 |= V_61 ;
V_48 |= V_62 ;
V_86 |= V_266 | V_267 ;
} else {
V_4 -> V_50 &= ~ V_61 ;
V_48 &= ~ V_62 ;
V_86 &= ~ ( V_266 | V_267 ) ;
}
F_32 ( V_4 -> V_43 , V_87 , V_86 ) ;
F_32 ( V_4 -> V_43 , V_63 , V_48 ) ;
if ( ! V_4 -> V_150 || ! V_265 )
F_32 ( V_4 -> V_43 , V_60 , V_48 ) ;
F_33 ( V_4 -> V_43 , V_63 ) ;
F_37 ( & V_4 -> V_57 , V_50 ) ;
}
static int F_109 ( struct V_3 * V_4 )
{
int V_7 ;
if ( ! V_4 -> V_2 -> V_32 || ! V_4 -> V_268 )
return - V_31 ;
V_7 = F_110 ( V_4 -> V_2 , V_4 -> V_268 ) ;
if ( V_7 ) {
F_9 ( F_10 ( V_4 -> V_5 ) , L_59 ) ;
goto V_182;
}
if ( V_4 -> V_36 -> V_102 & V_269 ) {
struct V_270 * V_271 = F_111 ( V_4 -> V_2 ) ;
if ( ! V_271 ) {
V_7 = - V_31 ;
goto V_272;
}
if ( F_22 ( F_112 ( V_271 , V_273 ) ) ) {
F_84 ( V_4 -> V_2 , L_60 ) ;
F_113 ( V_271 ) ;
V_7 = - V_220 ;
goto V_272;
}
if ( F_22 ( F_112 ( V_271 , V_274 ) ) ) {
F_84 ( V_4 -> V_2 , L_61 ) ;
F_113 ( V_271 ) ;
V_7 = - V_220 ;
goto V_272;
}
F_113 ( V_271 ) ;
}
F_32 ( V_4 -> V_43 , V_84 ,
F_33 ( V_4 -> V_43 , V_84 ) | V_113 ) ;
return 0 ;
V_272:
F_114 ( V_4 -> V_2 ) ;
V_182:
F_91 ( V_4 -> V_2 , L_62 ) ;
V_4 -> V_268 = 0 ;
return V_7 ;
}
static void F_115 ( struct V_3 * V_4 )
{
T_1 V_98 , V_99 , V_275 ;
if ( V_4 -> V_36 -> V_102 & V_103 ) {
V_98 = V_108 ;
V_99 = V_109 | V_110 ;
} else {
V_98 = V_107 ;
V_99 = V_110 ;
}
V_275 = F_33 ( V_4 -> V_43 , V_84 ) & ~ V_276 ;
F_32 ( V_4 -> V_43 , V_84 , V_275 | V_98 ) ;
V_275 = F_33 ( V_4 -> V_43 , V_82 ) ;
F_32 ( V_4 -> V_43 , V_82 , V_275 | V_99 ) ;
F_79 ( V_4 ) ;
}
static int F_116 ( struct V_262 * V_263 ,
unsigned int V_277 , int V_278 )
{
if ( V_277 == V_147 )
return 1 ;
return V_278 ;
}
static int F_117 ( struct V_279 * V_280 , void * V_129 )
{
struct V_6 * V_5 = V_280 -> V_281 ;
struct V_3 * V_4 = F_6 ( V_5 ) ;
F_118 ( V_280 , L_63 , V_5 -> V_282 ) ;
F_118 ( V_280 , L_64 ,
( V_5 -> V_111 & V_112 ) ? L_65 : L_66 ) ;
if ( V_5 -> V_111 & V_112 ) {
F_118 ( V_280 , L_67 ,
( V_4 -> V_50 & V_61 ) ? L_68
: L_69 ) ;
}
F_118 ( V_280 , L_70 , V_4 -> V_101 ) ;
F_119 ( V_4 -> V_2 ) ;
F_120 ( V_280 , L_71 ) ;
F_118 ( V_280 , L_72 ,
F_33 ( V_4 -> V_43 , V_87 ) ) ;
F_118 ( V_280 , L_73 ,
F_33 ( V_4 -> V_43 , V_283 ) ) ;
F_118 ( V_280 , L_74 ,
F_33 ( V_4 -> V_43 , V_84 ) ) ;
F_118 ( V_280 , L_75 ,
F_33 ( V_4 -> V_43 , V_44 ) ) ;
F_118 ( V_280 , L_76 ,
F_33 ( V_4 -> V_43 , V_63 ) ) ;
F_118 ( V_280 , L_77 ,
F_33 ( V_4 -> V_43 , V_60 ) ) ;
F_118 ( V_280 , L_78 ,
F_33 ( V_4 -> V_43 , V_82 ) ) ;
F_121 ( V_4 -> V_2 ) ;
F_122 ( V_4 -> V_2 ) ;
return 0 ;
}
static int F_123 ( struct V_284 * V_284 , struct V_285 * V_285 )
{
return F_124 ( V_285 , F_117 , V_284 -> V_286 ) ;
}
static void F_125 ( struct V_6 * V_5 )
{
if ( V_5 -> V_287 )
F_126 ( L_79 , V_288 , V_5 -> V_287 ,
V_5 , & V_289 ) ;
}
static void F_125 ( struct V_6 * V_5 )
{
}
static struct V_35 * F_127 ( struct V_1 * V_2 )
{
struct V_35 * V_36 , * V_290 ;
struct V_291 * V_292 = V_2 -> V_32 ;
V_36 = F_128 ( V_2 , sizeof( * V_36 ) , V_293 ) ;
if ( ! V_36 )
return F_129 ( - V_294 ) ;
V_290 = F_130 ( V_2 ) ;
if ( V_290 && V_290 -> V_127 )
V_36 -> V_127 = V_290 -> V_127 ;
if ( F_131 ( V_292 , L_80 , NULL ) )
V_36 -> V_102 |= V_103 ;
V_36 -> V_40 = - V_220 ;
V_36 -> V_37 = - V_220 ;
V_36 -> V_42 = - V_220 ;
if ( F_131 ( V_292 , L_81 , NULL ) ) {
V_36 -> V_295 = true ;
V_36 -> V_34 = true ;
}
if ( F_131 ( V_292 , L_82 , NULL ) )
V_36 -> V_77 |= V_180 ;
if ( F_131 ( V_292 , L_83 , NULL ) )
V_36 -> V_77 |= V_78 ;
return V_36 ;
}
static inline struct V_35
* F_127 ( struct V_1 * V_2 )
{
return F_129 ( - V_220 ) ;
}
static int F_132 ( struct V_296 * V_297 )
{
struct V_35 * V_36 = V_297 -> V_2 . V_298 ;
struct V_6 * V_5 ;
struct V_3 * V_4 = NULL ;
struct V_299 * V_174 ;
int V_7 , V_117 ;
const struct V_300 * V_301 ;
const struct V_302 * V_129 ;
void T_6 * V_43 ;
V_301 = F_133 ( F_134 ( V_303 ) , & V_297 -> V_2 ) ;
if ( V_301 ) {
V_36 = F_127 ( & V_297 -> V_2 ) ;
if ( F_22 ( V_36 ) )
return F_23 ( V_36 ) ;
if ( V_301 -> V_129 ) {
V_129 = V_301 -> V_129 ;
V_36 -> V_304 = V_129 -> V_304 ;
V_36 -> V_102 |= V_129 -> V_102 ;
}
}
if ( V_36 == NULL ) {
F_9 ( & V_297 -> V_2 , L_84 ) ;
return - V_305 ;
}
V_174 = F_135 ( V_297 , V_306 , 0 ) ;
V_117 = F_136 ( V_297 , 0 ) ;
if ( V_174 == NULL || V_117 < 0 )
return - V_305 ;
V_43 = F_137 ( & V_297 -> V_2 , V_174 ) ;
if ( F_22 ( V_43 ) )
return F_23 ( V_43 ) ;
V_5 = F_138 ( sizeof( struct V_3 ) , & V_297 -> V_2 ) ;
if ( ! V_5 ) {
V_7 = - V_294 ;
goto V_182;
}
V_7 = F_139 ( V_5 ) ;
if ( V_7 )
goto V_307;
V_4 = F_6 ( V_5 ) ;
V_4 -> V_5 = V_5 ;
V_4 -> V_36 = V_36 ;
V_4 -> V_2 = & V_297 -> V_2 ;
V_4 -> V_51 = 1 ;
V_4 -> V_159 = - 1 ;
V_4 -> V_117 = V_117 ;
V_4 -> V_227 = V_174 -> V_308 + V_36 -> V_304 ;
V_4 -> V_43 = V_43 + V_36 -> V_304 ;
V_4 -> V_104 = V_105 ;
V_4 -> V_218 . V_219 = 1 ;
V_4 -> V_23 = 0 ;
V_4 -> V_14 = 0 ;
V_7 = F_26 ( V_5 , V_4 , V_36 ) ;
if ( V_7 )
goto V_309;
F_140 ( V_297 , V_4 ) ;
if ( V_297 -> V_2 . V_32 )
V_4 -> V_268 = F_141 ( V_297 -> V_2 . V_32 , 1 ) ;
V_5 -> V_310 = & V_311 ;
V_5 -> V_312 = V_313 ;
if ( V_36 -> V_314 > 0 )
V_5 -> V_315 = V_36 -> V_314 ;
else if ( V_5 -> V_315 == 0 )
V_5 -> V_315 = V_316 ;
F_142 ( & V_4 -> V_57 ) ;
V_4 -> V_65 = F_143 ( & V_297 -> V_2 , L_85 ) ;
if ( F_22 ( V_4 -> V_65 ) ) {
V_7 = F_23 ( V_4 -> V_65 ) ;
V_4 -> V_65 = NULL ;
goto V_307;
}
if ( V_4 -> V_36 -> V_102 & V_317 ) {
F_84 ( & V_297 -> V_2 , L_86 ) ;
V_311 . V_318 = F_116 ;
}
F_144 ( & V_297 -> V_2 , true ) ;
F_145 ( V_4 -> V_2 ) ;
F_119 ( V_4 -> V_2 ) ;
F_146 ( V_4 -> V_2 , V_319 ) ;
F_147 ( V_4 -> V_2 ) ;
F_50 ( V_4 ) ;
V_4 -> V_209 = F_143 ( & V_297 -> V_2 , L_87 ) ;
if ( F_22 ( V_4 -> V_209 ) ) {
V_4 -> V_209 = NULL ;
} else if ( F_82 ( V_4 -> V_209 ) != 0 ) {
F_91 ( F_10 ( V_4 -> V_5 ) , L_88 ) ;
V_4 -> V_209 = NULL ;
}
V_5 -> V_320 = 1024 ;
V_5 -> V_321 = 512 ;
V_5 -> V_322 = 0xFFFF ;
V_5 -> V_323 = V_5 -> V_321 * V_5 -> V_322 ;
V_5 -> V_324 = V_5 -> V_323 ;
V_5 -> V_111 |= V_325 | V_326 |
V_327 | V_328 ;
V_5 -> V_111 |= F_16 ( V_4 ) -> V_111 ;
if ( V_5 -> V_111 & V_329 )
V_5 -> V_111 |= V_330 ;
if ( F_16 ( V_4 ) -> V_295 )
V_5 -> V_111 |= V_331 ;
V_5 -> V_332 |= F_16 ( V_4 ) -> V_332 ;
F_115 ( V_4 ) ;
V_4 -> V_157 = F_148 ( & V_297 -> V_2 , L_89 ) ;
if ( F_22 ( V_4 -> V_157 ) ) {
F_9 ( F_10 ( V_4 -> V_5 ) , L_90 ) ;
V_7 = F_23 ( V_4 -> V_157 ) ;
goto V_333;
}
V_4 -> V_156 = F_148 ( & V_297 -> V_2 , L_91 ) ;
if ( F_22 ( V_4 -> V_156 ) ) {
F_9 ( F_10 ( V_4 -> V_5 ) , L_92 ) ;
V_7 = F_23 ( V_4 -> V_156 ) ;
goto V_333;
}
V_7 = F_149 ( & V_297 -> V_2 , V_4 -> V_117 , F_77 , 0 ,
F_59 ( V_5 ) , V_4 ) ;
if ( V_7 ) {
F_9 ( F_10 ( V_4 -> V_5 ) , L_93 ) ;
goto V_333;
}
V_7 = F_20 ( V_4 ) ;
if ( V_7 )
goto V_333;
V_5 -> V_334 = F_16 ( V_4 ) -> V_33 ;
F_38 ( V_4 ) ;
V_7 = F_109 ( V_4 ) ;
if ( ! V_7 )
V_5 -> V_111 |= V_112 ;
F_83 ( V_4 ) ;
F_150 ( V_5 ) ;
if ( F_16 ( V_4 ) -> V_127 != NULL ) {
V_7 = F_151 ( & V_5 -> V_126 , & V_335 ) ;
if ( V_7 < 0 )
goto V_336;
}
if ( V_4 -> V_38 ) {
V_7 = F_151 ( & V_5 -> V_126 ,
& V_337 ) ;
if ( V_7 < 0 )
goto V_336;
}
F_125 ( V_5 ) ;
F_121 ( V_4 -> V_2 ) ;
F_122 ( V_4 -> V_2 ) ;
return 0 ;
V_336:
F_152 ( V_5 ) ;
V_333:
F_144 ( & V_297 -> V_2 , false ) ;
if ( ! F_153 ( V_4 -> V_156 ) )
F_154 ( V_4 -> V_156 ) ;
if ( ! F_153 ( V_4 -> V_157 ) )
F_154 ( V_4 -> V_157 ) ;
F_155 ( V_4 -> V_2 ) ;
F_156 ( V_4 -> V_2 ) ;
F_157 ( V_4 -> V_2 ) ;
if ( V_4 -> V_209 )
F_81 ( V_4 -> V_209 ) ;
V_307:
V_309:
F_158 ( V_5 ) ;
V_182:
return V_7 ;
}
static int F_159 ( struct V_296 * V_297 )
{
struct V_3 * V_4 = F_160 ( V_297 ) ;
F_119 ( V_4 -> V_2 ) ;
F_152 ( V_4 -> V_5 ) ;
F_154 ( V_4 -> V_156 ) ;
F_154 ( V_4 -> V_157 ) ;
F_155 ( V_4 -> V_2 ) ;
F_156 ( V_4 -> V_2 ) ;
F_157 ( V_4 -> V_2 ) ;
F_144 ( & V_297 -> V_2 , false ) ;
if ( V_4 -> V_209 )
F_81 ( V_4 -> V_209 ) ;
F_158 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_161 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 )
return 0 ;
F_119 ( V_4 -> V_2 ) ;
if ( ! ( V_4 -> V_5 -> V_338 & V_339 ) ) {
F_32 ( V_4 -> V_43 , V_60 , 0 ) ;
F_32 ( V_4 -> V_43 , V_63 , 0 ) ;
F_32 ( V_4 -> V_43 , V_58 , V_59 ) ;
F_32 ( V_4 -> V_43 , V_84 ,
F_33 ( V_4 -> V_43 , V_84 ) & ~ V_114 ) ;
}
if ( V_4 -> V_209 )
F_81 ( V_4 -> V_209 ) ;
F_156 ( V_4 -> V_2 ) ;
return 0 ;
}
static int F_162 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 )
return 0 ;
F_119 ( V_4 -> V_2 ) ;
if ( V_4 -> V_209 )
F_82 ( V_4 -> V_209 ) ;
if ( ! ( V_4 -> V_5 -> V_338 & V_339 ) )
F_115 ( V_4 ) ;
F_83 ( V_4 ) ;
F_121 ( V_4 -> V_2 ) ;
F_122 ( V_4 -> V_2 ) ;
return 0 ;
}
static int F_163 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_50 ;
int V_7 = 0 ;
V_4 = F_160 ( F_164 ( V_2 ) ) ;
F_50 ( V_4 ) ;
F_24 ( V_2 , L_94 ) ;
F_36 ( & V_4 -> V_57 , V_50 ) ;
if ( ( V_4 -> V_5 -> V_111 & V_112 ) &&
( V_4 -> V_50 & V_61 ) ) {
F_32 ( V_4 -> V_43 , V_60 , 0 ) ;
F_32 ( V_4 -> V_43 , V_63 , 0 ) ;
if ( ! ( F_33 ( V_4 -> V_43 , V_283 ) & F_165 ( 1 ) ) ) {
F_24 ( V_2 , L_95 ) ;
F_32 ( V_4 -> V_43 , V_58 , V_59 ) ;
F_32 ( V_4 -> V_43 , V_60 , V_62 ) ;
F_32 ( V_4 -> V_43 , V_63 , V_62 ) ;
F_121 ( V_2 ) ;
V_7 = - V_340 ;
goto abort;
}
F_166 ( V_2 ) ;
} else {
F_166 ( V_2 ) ;
}
abort:
F_37 ( & V_4 -> V_57 , V_50 ) ;
return V_7 ;
}
static int F_167 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_50 ;
V_4 = F_160 ( F_164 ( V_2 ) ) ;
F_49 ( V_4 ) ;
F_24 ( V_2 , L_96 ) ;
F_36 ( & V_4 -> V_57 , V_50 ) ;
if ( ( V_4 -> V_5 -> V_111 & V_112 ) &&
( V_4 -> V_50 & V_61 ) ) {
F_168 ( V_4 -> V_2 ) ;
F_32 ( V_4 -> V_43 , V_58 , V_59 ) ;
F_32 ( V_4 -> V_43 , V_60 , V_62 ) ;
F_32 ( V_4 -> V_43 , V_63 , V_62 ) ;
} else {
F_168 ( V_4 -> V_2 ) ;
}
F_37 ( & V_4 -> V_57 , V_50 ) ;
return 0 ;
}
