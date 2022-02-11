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
if ( ! F_7 ( V_5 -> V_10 . V_11 ) ) {
V_7 = F_8 ( V_5 , V_5 -> V_10 . V_11 , V_9 -> V_12 ) ;
if ( V_7 )
return V_7 ;
}
if ( ! F_7 ( V_5 -> V_10 . V_13 ) && ! V_4 -> V_14 ) {
V_7 = F_9 ( V_5 -> V_10 . V_13 ) ;
if ( V_7 ) {
F_10 ( F_11 ( V_5 ) , L_1 ) ;
goto V_15;
}
V_4 -> V_14 = 1 ;
}
return 0 ;
V_15:
if ( ! F_7 ( V_5 -> V_10 . V_11 ) )
F_8 ( V_5 , V_5 -> V_10 . V_11 , 0 ) ;
return V_7 ;
}
static int F_12 ( struct V_6 * V_5 )
{
int V_7 ;
int V_16 ;
struct V_3 * V_4 = F_6 ( V_5 ) ;
if ( ! F_7 ( V_5 -> V_10 . V_13 ) && V_4 -> V_14 ) {
V_7 = F_13 ( V_5 -> V_10 . V_13 ) ;
if ( V_7 ) {
F_10 ( F_11 ( V_5 ) , L_2 ) ;
return V_7 ;
}
V_4 -> V_14 = 0 ;
}
if ( ! F_7 ( V_5 -> V_10 . V_11 ) ) {
V_7 = F_8 ( V_5 , V_5 -> V_10 . V_11 , 0 ) ;
if ( V_7 )
goto V_17;
}
return 0 ;
V_17:
if ( ! F_7 ( V_5 -> V_10 . V_13 ) ) {
V_16 = F_9 ( V_5 -> V_10 . V_13 ) ;
if ( V_16 )
F_10 ( F_11 ( V_5 ) , L_3 ) ;
}
return V_7 ;
}
static int F_14 ( struct V_3 * V_4 , bool V_18 ,
int V_12 )
{
int V_7 ;
if ( F_7 ( V_4 -> V_19 ) )
return 0 ;
if ( V_18 ) {
if ( V_12 <= V_20 )
V_7 = F_15 ( V_4 -> V_19 , V_21 ,
V_21 ) ;
else
V_7 = F_15 ( V_4 -> V_19 , V_22 ,
V_22 ) ;
if ( V_7 < 0 ) {
F_10 ( V_4 -> V_2 , L_4 ) ;
return V_7 ;
}
if ( V_4 -> V_23 == 0 ) {
V_7 = F_9 ( V_4 -> V_19 ) ;
if ( V_7 ) {
F_10 ( V_4 -> V_2 , L_5 ) ;
return V_7 ;
}
V_4 -> V_23 = 1 ;
}
} else {
if ( V_4 -> V_23 == 1 ) {
V_7 = F_13 ( V_4 -> V_19 ) ;
if ( V_7 ) {
F_10 ( V_4 -> V_2 , L_6 ) ;
return V_7 ;
}
V_4 -> V_23 = 0 ;
}
}
return 0 ;
}
static int F_16 ( struct V_3 * V_4 , int V_18 ,
int V_12 )
{
struct V_6 * V_5 = V_4 -> V_5 ;
int V_7 = 0 ;
if ( F_7 ( V_5 -> V_10 . V_11 ) )
return 0 ;
V_7 = F_14 ( V_4 , false , 0 ) ;
if ( V_7 )
return V_7 ;
if ( V_18 ) {
V_7 = F_5 ( V_5 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_14 ( V_4 , true , V_12 ) ;
if ( V_7 )
goto V_24;
} else {
V_7 = F_12 ( V_5 ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
V_24:
F_12 ( V_5 ) ;
return V_7 ;
}
static int F_17 ( struct V_25 * V_26 )
{
int V_7 ;
if ( F_7 ( V_26 ) )
return 0 ;
if ( F_18 ( V_26 ) ) {
V_7 = F_9 ( V_26 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_13 ( V_26 ) ;
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
F_10 ( V_4 -> V_2 , L_7 ) ;
return V_7 ;
}
V_7 = F_17 ( V_5 -> V_10 . V_13 ) ;
if ( V_7 ) {
F_10 ( V_4 -> V_2 ,
L_8 ) ;
return V_7 ;
}
V_7 = F_17 ( V_4 -> V_19 ) ;
if ( V_7 ) {
F_10 ( V_4 -> V_2 ,
L_9 ) ;
return V_7 ;
}
return 0 ;
}
static int F_20 ( struct V_3 * V_4 )
{
int V_7 ;
struct V_6 * V_5 = V_4 -> V_5 ;
V_7 = F_21 ( V_5 ) ;
if ( V_7 == - V_27 )
return V_7 ;
if ( F_7 ( V_5 -> V_10 . V_13 ) ) {
V_5 -> V_10 . V_13 = F_22 ( V_4 -> V_2 ,
L_10 ) ;
if ( F_7 ( V_5 -> V_10 . V_13 ) ) {
V_7 = F_23 ( V_5 -> V_10 . V_13 ) ;
if ( ( V_7 != - V_28 ) && V_4 -> V_2 -> V_29 )
return V_7 ;
F_24 ( V_4 -> V_2 , L_11 ,
F_23 ( V_5 -> V_10 . V_13 ) ) ;
}
}
V_4 -> V_19 = F_22 ( V_4 -> V_2 , L_12 ) ;
if ( F_7 ( V_4 -> V_19 ) ) {
V_7 = F_23 ( V_4 -> V_19 ) ;
if ( ( V_7 != - V_28 ) && V_4 -> V_2 -> V_29 ) {
F_10 ( V_4 -> V_2 ,
L_13 ) ;
return V_7 ;
}
F_24 ( V_4 -> V_2 , L_14 ,
F_23 ( V_4 -> V_19 ) ) ;
}
if ( F_25 ( V_4 ) -> V_30 )
return 0 ;
V_7 = F_19 ( V_4 ) ;
if ( V_7 )
return V_7 ;
return 0 ;
}
static int F_26 ( struct V_6 * V_5 ,
struct V_3 * V_4 ,
struct V_31 * V_32 )
{
int V_7 ;
if ( F_27 ( V_32 -> V_33 ) ) {
V_7 = F_28 ( V_5 , V_32 -> V_33 , 0 ) ;
if ( V_7 )
return V_7 ;
V_4 -> V_34 = F_4 ;
F_29 ( V_5 , V_35 ) ;
} else if ( F_27 ( V_32 -> V_36 ) ) {
V_7 = F_28 ( V_5 , V_32 -> V_36 , 0 ) ;
if ( V_7 )
return V_7 ;
V_4 -> V_37 = F_1 ;
}
if ( F_27 ( V_32 -> V_38 ) ) {
V_7 = F_30 ( V_5 , V_32 -> V_38 ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
}
static void F_31 ( struct V_3 * V_4 )
{
F_32 ( V_4 -> V_39 , V_40 ,
F_33 ( V_4 -> V_39 , V_40 ) | V_41 ) ;
}
static void F_34 ( struct V_3 * V_4 )
{
F_32 ( V_4 -> V_39 , V_40 ,
F_33 ( V_4 -> V_39 , V_40 ) & ~ V_41 ) ;
if ( ( F_33 ( V_4 -> V_39 , V_40 ) & V_41 ) != 0x0 )
F_24 ( F_11 ( V_4 -> V_5 ) , L_15 ) ;
}
static void F_35 ( struct V_3 * V_4 ,
struct V_42 * V_43 )
{
T_1 V_44 = V_45 ;
unsigned long V_46 ;
if ( V_4 -> V_47 )
V_44 &= ~ ( V_48 | V_49 ) ;
if ( V_43 -> V_50 == V_51 )
V_44 &= ~ V_52 ;
F_36 ( & V_4 -> V_53 , V_46 ) ;
F_32 ( V_4 -> V_39 , V_54 , V_55 ) ;
F_32 ( V_4 -> V_39 , V_56 , V_44 ) ;
if ( V_4 -> V_46 & V_57 )
V_44 |= V_58 ;
F_32 ( V_4 -> V_39 , V_59 , V_44 ) ;
F_37 ( & V_4 -> V_53 , V_46 ) ;
}
static void F_38 ( struct V_3 * V_4 )
{
T_1 V_44 = 0 ;
unsigned long V_46 ;
F_36 ( & V_4 -> V_53 , V_46 ) ;
if ( V_4 -> V_46 & V_57 )
V_44 |= V_58 ;
F_32 ( V_4 -> V_39 , V_56 , V_44 ) ;
F_32 ( V_4 -> V_39 , V_59 , V_44 ) ;
F_32 ( V_4 -> V_39 , V_54 , V_55 ) ;
F_37 ( & V_4 -> V_53 , V_46 ) ;
}
static T_2 F_39 ( struct V_3 * V_4 , struct V_8 * V_9 )
{
T_2 V_60 = 0 ;
if ( V_9 -> clock ) {
V_60 = F_40 ( F_41 ( V_4 -> V_61 ) , V_9 -> clock ) ;
if ( V_60 > V_62 )
V_60 = V_62 ;
}
return V_60 ;
}
static void F_42 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_5 -> V_9 ;
unsigned long V_63 ;
unsigned long V_64 ;
unsigned long V_65 ;
F_43 ( F_11 ( V_4 -> V_5 ) , L_16 , V_9 -> clock ) ;
F_34 ( V_4 ) ;
V_63 = F_33 ( V_4 -> V_39 , V_40 ) ;
V_63 = V_63 & ~ ( V_66 | V_67 ) ;
V_65 = F_39 ( V_4 , V_9 ) ;
V_63 = V_63 | ( V_65 << 6 ) | ( V_68 << 16 ) ;
F_32 ( V_4 -> V_39 , V_40 , V_63 ) ;
F_32 ( V_4 -> V_39 , V_40 ,
F_33 ( V_4 -> V_39 , V_40 ) | V_69 ) ;
V_64 = V_70 + F_44 ( V_71 ) ;
while ( ( F_33 ( V_4 -> V_39 , V_40 ) & V_72 ) != V_72
&& F_45 ( V_70 , V_64 ) )
F_46 () ;
if ( ( F_25 ( V_4 ) -> V_73 & V_74 ) &&
( V_9 -> V_75 != V_76 ) &&
( V_9 -> V_75 != V_77 ) &&
( ( F_33 ( V_4 -> V_39 , V_78 ) & V_79 ) == V_79 ) ) {
V_63 = F_33 ( V_4 -> V_39 , V_80 ) ;
if ( V_65 && ( F_41 ( V_4 -> V_61 ) / V_65 ) > 25000000 )
V_63 |= V_81 ;
else
V_63 &= ~ V_81 ;
F_32 ( V_4 -> V_39 , V_80 , V_63 ) ;
}
F_31 ( V_4 ) ;
}
static void F_47 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_5 -> V_9 ;
T_1 V_82 ;
V_82 = F_33 ( V_4 -> V_39 , V_83 ) ;
if ( V_9 -> V_75 == V_76 ||
V_9 -> V_75 == V_77 )
V_82 |= V_84 ;
else
V_82 &= ~ V_84 ;
switch ( V_9 -> V_85 ) {
case V_86 :
F_32 ( V_4 -> V_39 , V_83 , V_82 | V_87 ) ;
break;
case V_88 :
F_32 ( V_4 -> V_39 , V_83 , V_82 & ~ V_87 ) ;
F_32 ( V_4 -> V_39 , V_80 ,
F_33 ( V_4 -> V_39 , V_80 ) | V_89 ) ;
break;
case V_90 :
F_32 ( V_4 -> V_39 , V_83 , V_82 & ~ V_87 ) ;
F_32 ( V_4 -> V_39 , V_80 ,
F_33 ( V_4 -> V_39 , V_80 ) & ~ V_89 ) ;
break;
}
}
static void F_48 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_5 -> V_9 ;
T_1 V_82 ;
V_82 = F_33 ( V_4 -> V_39 , V_83 ) ;
if ( V_9 -> V_91 == V_92 )
F_32 ( V_4 -> V_39 , V_83 , V_82 | V_93 ) ;
else
F_32 ( V_4 -> V_39 , V_83 , V_82 & ~ V_93 ) ;
}
static int F_49 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_5 -> V_9 ;
T_1 V_94 , V_95 ;
unsigned long V_64 ;
if ( V_4 -> V_82 == F_33 ( V_4 -> V_39 , V_83 ) &&
V_4 -> V_94 == F_33 ( V_4 -> V_39 , V_80 ) &&
V_4 -> V_96 == F_33 ( V_4 -> V_39 , V_40 ) &&
V_4 -> V_95 == F_33 ( V_4 -> V_39 , V_78 ) )
return 0 ;
V_4 -> V_97 ++ ;
if ( V_4 -> V_32 -> V_98 & V_99 ) {
if ( V_4 -> V_100 != V_101 &&
( 1 << V_9 -> V_12 ) <= V_102 )
V_94 = V_103 ;
else
V_94 = V_104 ;
V_95 = V_105 | V_106 ;
} else {
V_94 = V_103 ;
V_95 = V_106 ;
}
if ( V_4 -> V_5 -> V_107 & V_108 )
V_94 |= V_109 ;
F_32 ( V_4 -> V_39 , V_80 ,
F_33 ( V_4 -> V_39 , V_80 ) | V_94 ) ;
F_32 ( V_4 -> V_39 , V_78 ,
F_33 ( V_4 -> V_39 , V_78 ) | V_95 ) ;
F_32 ( V_4 -> V_39 , V_80 ,
F_33 ( V_4 -> V_39 , V_80 ) | V_110 ) ;
V_64 = V_70 + F_44 ( V_71 ) ;
while ( ( F_33 ( V_4 -> V_39 , V_80 ) & V_110 ) != V_110
&& F_45 ( V_70 , V_64 ) )
;
F_32 ( V_4 -> V_39 , V_56 , 0 ) ;
F_32 ( V_4 -> V_39 , V_59 , 0 ) ;
F_32 ( V_4 -> V_39 , V_54 , V_55 ) ;
if ( V_4 -> V_100 == V_101 )
goto V_111;
F_47 ( V_4 ) ;
F_42 ( V_4 ) ;
F_48 ( V_4 ) ;
V_111:
F_24 ( F_11 ( V_4 -> V_5 ) , L_17 ,
V_4 -> V_97 ) ;
return 0 ;
}
static void F_50 ( struct V_3 * V_4 )
{
V_4 -> V_82 = F_33 ( V_4 -> V_39 , V_83 ) ;
V_4 -> V_94 = F_33 ( V_4 -> V_39 , V_80 ) ;
V_4 -> V_96 = F_33 ( V_4 -> V_39 , V_40 ) ;
V_4 -> V_95 = F_33 ( V_4 -> V_39 , V_78 ) ;
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
int V_26 = 0 ;
unsigned long V_64 ;
if ( V_4 -> V_112 )
return;
F_52 ( V_4 -> V_113 ) ;
F_32 ( V_4 -> V_39 , V_59 , V_45 ) ;
F_32 ( V_4 -> V_39 , V_83 ,
F_33 ( V_4 -> V_39 , V_83 ) | V_114 ) ;
F_32 ( V_4 -> V_39 , V_115 , V_116 ) ;
V_64 = V_70 + F_44 ( V_71 ) ;
while ( ( V_26 != V_117 ) && F_45 ( V_70 , V_64 ) )
V_26 = F_33 ( V_4 -> V_39 , V_54 ) & V_117 ;
F_32 ( V_4 -> V_39 , V_83 ,
F_33 ( V_4 -> V_39 , V_83 ) & ~ V_114 ) ;
F_32 ( V_4 -> V_39 , V_54 , V_55 ) ;
F_33 ( V_4 -> V_39 , V_54 ) ;
F_53 ( V_4 -> V_113 ) ;
}
static inline
int F_54 ( struct V_3 * V_4 )
{
int V_118 = 1 ;
if ( V_4 -> V_34 )
V_118 = V_4 -> V_34 ( V_4 -> V_2 ) ;
return V_118 ;
}
static T_3
F_55 ( struct V_1 * V_2 , struct V_119 * V_120 ,
char * V_121 )
{
struct V_6 * V_5 = F_56 ( V_2 , struct V_6 , V_122 ) ;
struct V_3 * V_4 = F_6 ( V_5 ) ;
return sprintf ( V_121 , L_18 ,
F_54 ( V_4 ) ? L_19 : L_20 ) ;
}
static T_3
F_57 ( struct V_1 * V_2 , struct V_119 * V_120 ,
char * V_121 )
{
struct V_6 * V_5 = F_56 ( V_2 , struct V_6 , V_122 ) ;
struct V_3 * V_4 = F_6 ( V_5 ) ;
return sprintf ( V_121 , L_18 , F_25 ( V_4 ) -> V_123 ) ;
}
static void
F_58 ( struct V_3 * V_4 , struct V_42 * V_43 ,
struct V_124 * V_125 )
{
int V_126 = 0 , V_127 = 0 , V_128 = 0 ;
F_43 ( F_11 ( V_4 -> V_5 ) , L_21 ,
F_59 ( V_4 -> V_5 ) , V_43 -> V_50 , V_43 -> V_129 ) ;
V_4 -> V_43 = V_43 ;
F_35 ( V_4 , V_43 ) ;
V_4 -> V_130 = 0 ;
if ( V_43 -> V_46 & V_131 ) {
if ( V_43 -> V_46 & V_132 )
V_127 = 1 ;
else if ( V_43 -> V_46 & V_133 ) {
V_127 = 3 ;
V_4 -> V_130 = 1 ;
} else
V_127 = 2 ;
}
if ( V_43 == V_4 -> V_134 -> V_135 )
V_128 = 0x3 ;
V_126 = ( V_43 -> V_50 << 24 ) | ( V_127 << 16 ) | ( V_128 << 22 ) ;
if ( ( V_4 -> V_46 & V_136 ) && F_60 ( V_43 -> V_50 ) &&
V_4 -> V_134 -> V_137 ) {
V_126 |= V_138 ;
F_32 ( V_4 -> V_39 , V_139 , V_4 -> V_134 -> V_137 -> V_129 ) ;
}
if ( V_125 ) {
V_126 |= V_140 | V_141 | V_142 ;
if ( V_125 -> V_46 & V_143 )
V_126 |= V_144 ;
else
V_126 &= ~ ( V_144 ) ;
}
if ( V_4 -> V_47 )
V_126 |= V_145 ;
V_4 -> V_146 = 1 ;
F_32 ( V_4 -> V_39 , V_147 , V_43 -> V_129 ) ;
F_32 ( V_4 -> V_39 , V_115 , V_126 ) ;
}
static struct V_148 * F_61 ( struct V_3 * V_4 ,
struct V_124 * V_125 )
{
return V_125 -> V_46 & V_149 ? V_4 -> V_150 : V_4 -> V_151 ;
}
static void F_62 ( struct V_3 * V_4 , struct V_152 * V_134 )
{
int V_153 ;
unsigned long V_46 ;
F_36 ( & V_4 -> V_53 , V_46 ) ;
V_4 -> V_146 = 0 ;
V_153 = V_4 -> V_153 ;
F_37 ( & V_4 -> V_53 , V_46 ) ;
F_38 ( V_4 ) ;
if ( V_134 -> V_125 && V_4 -> V_47 && V_153 != - 1 )
return;
V_4 -> V_134 = NULL ;
F_63 ( V_4 -> V_5 , V_134 ) ;
}
static void
F_64 ( struct V_3 * V_4 , struct V_124 * V_125 )
{
if ( ! V_125 ) {
struct V_152 * V_134 = V_4 -> V_134 ;
if ( V_4 -> V_43 && V_4 -> V_43 -> V_50 == 6 &&
V_4 -> V_130 ) {
V_4 -> V_130 = 0 ;
return;
}
F_62 ( V_4 , V_134 ) ;
return;
}
V_4 -> V_125 = NULL ;
if ( ! V_125 -> error )
V_125 -> V_154 += V_125 -> V_155 * ( V_125 -> V_156 ) ;
else
V_125 -> V_154 = 0 ;
if ( V_125 -> V_135 && ( V_125 -> error || ! V_4 -> V_134 -> V_137 ) )
F_58 ( V_4 , V_125 -> V_135 , NULL ) ;
else
F_62 ( V_4 , V_125 -> V_134 ) ;
}
static void
F_65 ( struct V_3 * V_4 , struct V_42 * V_43 )
{
if ( V_4 -> V_134 -> V_137 && ( V_4 -> V_43 == V_4 -> V_134 -> V_137 ) &&
! V_4 -> V_134 -> V_137 -> error && ! ( V_4 -> V_46 & V_136 ) ) {
V_4 -> V_43 = NULL ;
F_66 ( V_4 ) ;
F_58 ( V_4 , V_4 -> V_134 -> V_43 ,
V_4 -> V_134 -> V_125 ) ;
return;
}
V_4 -> V_43 = NULL ;
if ( V_43 -> V_46 & V_131 ) {
if ( V_43 -> V_46 & V_132 ) {
V_43 -> V_157 [ 3 ] = F_33 ( V_4 -> V_39 , V_158 ) ;
V_43 -> V_157 [ 2 ] = F_33 ( V_4 -> V_39 , V_159 ) ;
V_43 -> V_157 [ 1 ] = F_33 ( V_4 -> V_39 , V_160 ) ;
V_43 -> V_157 [ 0 ] = F_33 ( V_4 -> V_39 , V_161 ) ;
} else {
V_43 -> V_157 [ 0 ] = F_33 ( V_4 -> V_39 , V_158 ) ;
}
}
if ( ( V_4 -> V_125 == NULL && ! V_4 -> V_130 ) || V_43 -> error )
F_62 ( V_4 , V_4 -> V_134 ) ;
}
static void F_67 ( struct V_3 * V_4 , int V_162 )
{
int V_153 ;
unsigned long V_46 ;
V_4 -> V_125 -> error = V_162 ;
F_36 ( & V_4 -> V_53 , V_46 ) ;
V_153 = V_4 -> V_153 ;
V_4 -> V_153 = - 1 ;
F_37 ( & V_4 -> V_53 , V_46 ) ;
if ( V_4 -> V_47 && V_153 != - 1 ) {
struct V_148 * V_163 = F_61 ( V_4 , V_4 -> V_125 ) ;
F_68 ( V_163 ) ;
F_69 ( V_163 -> V_1 -> V_2 ,
V_4 -> V_125 -> V_164 , V_4 -> V_125 -> V_165 ,
F_70 ( V_4 -> V_125 ) ) ;
V_4 -> V_125 -> V_166 = 0 ;
}
V_4 -> V_125 = NULL ;
}
static void F_71 ( struct V_3 * V_4 , T_1 V_16 )
{
static const char * V_167 [] = {
L_22 , L_23 , L_24 , L_25 , L_26 , L_27 , L_25 , L_25 ,
L_28 , L_29 , L_25 , L_25 , L_25 , L_25 , L_25 , L_30 ,
L_31 , L_32 , L_33 , L_34 , L_35 , L_36 , L_37 , L_25 ,
L_38 , L_25 , L_25 , L_25 , L_39 , L_40 , L_25 , L_25
} ;
char V_168 [ 256 ] ;
char * V_121 = V_168 ;
int V_169 , V_170 ;
V_169 = sprintf ( V_121 , L_41 , V_16 ) ;
V_121 += V_169 ;
for ( V_170 = 0 ; V_170 < F_72 ( V_167 ) ; V_170 ++ )
if ( V_16 & ( 1 << V_170 ) ) {
V_169 = sprintf ( V_121 , L_42 , V_167 [ V_170 ] ) ;
V_121 += V_169 ;
}
F_43 ( F_11 ( V_4 -> V_5 ) , L_18 , V_168 ) ;
}
static inline void F_71 ( struct V_3 * V_4 ,
T_1 V_16 )
{
}
static inline void F_73 ( struct V_3 * V_4 ,
unsigned long V_171 )
{
unsigned long V_170 = 0 ;
unsigned long V_172 = V_173 ;
F_32 ( V_4 -> V_39 , V_40 ,
F_33 ( V_4 -> V_39 , V_40 ) | V_171 ) ;
if ( F_25 ( V_4 ) -> V_73 & V_174 ) {
while ( ( ! ( F_33 ( V_4 -> V_39 , V_40 ) & V_171 ) )
&& ( V_170 ++ < V_172 ) )
F_74 ( 1 ) ;
}
V_170 = 0 ;
while ( ( F_33 ( V_4 -> V_39 , V_40 ) & V_171 ) &&
( V_170 ++ < V_172 ) )
F_74 ( 1 ) ;
if ( F_33 ( V_4 -> V_39 , V_40 ) & V_171 )
F_10 ( F_11 ( V_4 -> V_5 ) ,
L_43 ,
V_175 ) ;
}
static void F_75 ( struct V_3 * V_4 ,
int V_176 , int V_177 )
{
if ( V_177 ) {
F_73 ( V_4 , V_178 ) ;
if ( V_4 -> V_43 )
V_4 -> V_43 -> error = V_176 ;
}
if ( V_4 -> V_125 ) {
F_73 ( V_4 , V_179 ) ;
F_67 ( V_4 , V_176 ) ;
} else if ( V_4 -> V_134 && V_4 -> V_134 -> V_43 )
V_4 -> V_134 -> V_43 -> error = V_176 ;
}
static void F_76 ( struct V_3 * V_4 , int V_16 )
{
struct V_124 * V_125 ;
int V_177 = 0 , V_180 = 0 ;
int error = 0 ;
V_125 = V_4 -> V_125 ;
F_43 ( F_11 ( V_4 -> V_5 ) , L_44 , V_16 ) ;
if ( V_16 & V_181 ) {
F_71 ( V_4 , V_16 ) ;
if ( V_16 & ( V_182 | V_183 | V_184 ) )
V_177 = 1 ;
if ( V_4 -> V_125 || V_4 -> V_130 ) {
V_180 = ! V_177 ;
V_4 -> V_130 = 0 ;
}
if ( V_16 & ( V_182 | V_52 ) )
F_75 ( V_4 , - V_185 , V_177 ) ;
else if ( V_16 & ( V_183 | V_186 | V_187 | V_184 |
V_188 ) )
F_75 ( V_4 , - V_189 , V_177 ) ;
if ( V_16 & V_190 ) {
T_1 V_191 ;
V_191 = F_33 ( V_4 -> V_39 , V_192 ) ;
if ( ! ( V_191 & V_193 ) && V_4 -> V_134 -> V_137 ) {
V_177 = 1 ;
if ( V_191 & V_194 )
error = - V_185 ;
else if ( V_191 & ( V_195 | V_196 | V_197 ) )
error = - V_189 ;
V_4 -> V_134 -> V_137 -> error = error ;
F_75 ( V_4 , error , V_177 ) ;
}
F_24 ( F_11 ( V_4 -> V_5 ) , L_45 , V_191 ) ;
}
}
F_32 ( V_4 -> V_39 , V_54 , V_16 ) ;
if ( V_177 || ( ( V_16 & V_117 ) && V_4 -> V_43 ) )
F_65 ( V_4 , V_4 -> V_43 ) ;
if ( ( V_180 || ( V_16 & V_198 ) ) && V_4 -> V_134 )
F_64 ( V_4 , V_125 ) ;
}
static T_4 F_77 ( int V_113 , void * V_199 )
{
struct V_3 * V_4 = V_199 ;
int V_16 ;
V_16 = F_33 ( V_4 -> V_39 , V_54 ) ;
while ( V_16 & ( V_45 | V_58 ) ) {
if ( V_4 -> V_146 )
F_76 ( V_4 , V_16 ) ;
if ( V_16 & V_58 )
F_78 ( V_4 -> V_5 ) ;
V_16 = F_33 ( V_4 -> V_39 , V_54 ) ;
}
return V_200 ;
}
static void F_79 ( struct V_3 * V_4 )
{
unsigned long V_170 ;
F_32 ( V_4 -> V_39 , V_80 ,
F_33 ( V_4 -> V_39 , V_80 ) | V_110 ) ;
for ( V_170 = 0 ; V_170 < V_201 ; V_170 ++ ) {
if ( F_33 ( V_4 -> V_39 , V_80 ) & V_110 )
break;
F_46 () ;
}
}
static int F_80 ( struct V_3 * V_4 , int V_12 )
{
T_1 V_202 = 0 ;
int V_7 ;
if ( V_4 -> V_203 )
F_81 ( V_4 -> V_203 ) ;
V_7 = F_16 ( V_4 , 0 , 0 ) ;
if ( ! V_7 )
V_7 = F_16 ( V_4 , 1 , V_12 ) ;
if ( V_4 -> V_203 )
F_82 ( V_4 -> V_203 ) ;
if ( V_7 != 0 )
goto V_176;
F_32 ( V_4 -> V_39 , V_80 ,
F_33 ( V_4 -> V_39 , V_80 ) & V_204 ) ;
V_202 = F_33 ( V_4 -> V_39 , V_80 ) ;
if ( ( 1 << V_12 ) <= V_102 )
V_202 |= V_103 ;
else
V_202 |= V_104 ;
F_32 ( V_4 -> V_39 , V_80 , V_202 ) ;
F_79 ( V_4 ) ;
return 0 ;
V_176:
F_10 ( F_11 ( V_4 -> V_5 ) , L_46 ) ;
return V_7 ;
}
static void F_83 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_34 )
return;
V_4 -> V_205 = 0 ;
if ( V_4 -> V_34 ( V_4 -> V_2 ) ) {
if ( V_4 -> V_112 ) {
F_84 ( V_4 -> V_2 , L_47
L_48 ,
F_59 ( V_4 -> V_5 ) ) ;
V_4 -> V_112 = 0 ;
}
} else {
if ( ! V_4 -> V_112 ) {
F_84 ( V_4 -> V_2 , L_49
L_50 ,
F_59 ( V_4 -> V_5 ) ) ;
V_4 -> V_112 = 1 ;
}
}
}
static T_4 V_35 ( int V_113 , void * V_199 )
{
struct V_3 * V_4 = V_199 ;
F_85 ( & V_4 -> V_5 -> V_122 . V_206 , NULL , L_51 ) ;
F_83 ( V_4 ) ;
F_86 ( V_4 -> V_5 , ( V_207 * 200 ) / 1000 ) ;
return V_200 ;
}
static void F_87 ( void * V_208 )
{
struct V_3 * V_4 = V_208 ;
struct V_148 * V_163 ;
struct V_124 * V_125 ;
int V_146 ;
F_88 ( & V_4 -> V_53 ) ;
if ( V_4 -> V_153 < 0 ) {
F_89 ( & V_4 -> V_53 ) ;
return;
}
V_125 = V_4 -> V_134 -> V_125 ;
V_163 = F_61 ( V_4 , V_125 ) ;
if ( ! V_125 -> V_166 )
F_69 ( V_163 -> V_1 -> V_2 ,
V_125 -> V_164 , V_125 -> V_165 ,
F_70 ( V_125 ) ) ;
V_146 = V_4 -> V_146 ;
V_4 -> V_153 = - 1 ;
F_89 ( & V_4 -> V_53 ) ;
if ( ! V_146 ) {
struct V_152 * V_134 = V_4 -> V_134 ;
V_4 -> V_134 = NULL ;
F_63 ( V_4 -> V_5 , V_134 ) ;
}
}
static int F_90 ( struct V_3 * V_4 ,
struct V_124 * V_125 ,
struct V_209 * V_210 ,
struct V_148 * V_163 )
{
int V_211 ;
if ( ! V_210 && V_125 -> V_166 &&
V_125 -> V_166 != V_4 -> V_212 . V_213 ) {
F_91 ( V_4 -> V_2 , L_52
L_53 ,
V_175 , V_125 -> V_166 , V_4 -> V_212 . V_213 ) ;
V_125 -> V_166 = 0 ;
}
if ( V_210 || V_125 -> V_166 != V_4 -> V_212 . V_213 ) {
V_211 = F_92 ( V_163 -> V_1 -> V_2 , V_125 -> V_164 , V_125 -> V_165 ,
F_70 ( V_125 ) ) ;
} else {
V_211 = V_4 -> V_212 . V_211 ;
V_4 -> V_212 . V_211 = 0 ;
}
if ( V_211 == 0 )
return - V_214 ;
if ( V_210 ) {
V_210 -> V_211 = V_211 ;
V_125 -> V_166 = ++ V_210 -> V_213 < 0 ? 1 : V_210 -> V_213 ;
} else
V_4 -> V_211 = V_211 ;
return 0 ;
}
static int F_93 ( struct V_3 * V_4 ,
struct V_152 * V_215 )
{
struct V_216 * V_217 ;
int V_7 = 0 , V_170 ;
struct V_124 * V_125 = V_215 -> V_125 ;
struct V_148 * V_163 ;
struct V_218 V_219 = {
. V_220 = V_4 -> V_221 + V_222 ,
. V_223 = V_4 -> V_221 + V_222 ,
. V_224 = V_225 ,
. V_226 = V_225 ,
. V_227 = V_125 -> V_156 / 4 ,
. V_228 = V_125 -> V_156 / 4 ,
} ;
for ( V_170 = 0 ; V_170 < V_125 -> V_165 ; V_170 ++ ) {
struct V_229 * V_230 ;
V_230 = V_125 -> V_164 + V_170 ;
if ( V_230 -> V_231 % V_125 -> V_156 )
return - V_214 ;
}
if ( ( V_125 -> V_156 % 4 ) != 0 )
return - V_214 ;
F_94 ( V_4 -> V_153 != - 1 ) ;
V_163 = F_61 ( V_4 , V_125 ) ;
V_7 = F_95 ( V_163 , & V_219 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_90 ( V_4 , V_125 , NULL , V_163 ) ;
if ( V_7 )
return V_7 ;
V_217 = F_96 ( V_163 , V_125 -> V_164 , V_125 -> V_165 ,
V_125 -> V_46 & V_149 ? V_232 : V_233 ,
V_234 | V_235 ) ;
if ( ! V_217 ) {
F_10 ( F_11 ( V_4 -> V_5 ) , L_54 ) ;
return - 1 ;
}
V_217 -> V_236 = F_87 ;
V_217 -> V_237 = V_4 ;
F_97 ( V_217 ) ;
V_4 -> V_153 = 1 ;
return 0 ;
}
static void F_98 ( struct V_3 * V_4 ,
unsigned long long V_238 ,
unsigned int V_239 )
{
unsigned long long V_64 = V_238 ;
unsigned int V_240 ;
T_5 V_26 , V_241 , V_242 = 0 ;
V_26 = F_33 ( V_4 -> V_39 , V_40 ) ;
V_241 = ( V_26 & V_66 ) >> V_243 ;
if ( V_241 == 0 )
V_241 = 1 ;
V_240 = 1000000000 / ( V_4 -> V_244 / V_241 ) ;
F_99 ( V_64 , V_240 ) ;
V_64 += V_239 ;
if ( V_64 ) {
while ( ( V_64 & 0x80000000 ) == 0 ) {
V_242 += 1 ;
V_64 <<= 1 ;
}
V_242 = 31 - V_242 ;
V_64 <<= 1 ;
if ( V_64 && V_242 )
V_242 += 1 ;
if ( V_242 >= 13 )
V_242 -= 13 ;
else
V_242 = 0 ;
if ( V_242 > 14 )
V_242 = 14 ;
}
V_26 &= ~ V_67 ;
V_26 |= V_242 << V_245 ;
F_32 ( V_4 -> V_39 , V_40 , V_26 ) ;
}
static void F_66 ( struct V_3 * V_4 )
{
struct V_152 * V_215 = V_4 -> V_134 ;
struct V_148 * V_163 ;
if ( ! V_215 -> V_125 )
return;
F_32 ( V_4 -> V_39 , V_246 , ( V_215 -> V_125 -> V_156 )
| ( V_215 -> V_125 -> V_155 << 16 ) ) ;
F_98 ( V_4 , V_215 -> V_125 -> V_238 ,
V_215 -> V_125 -> V_239 ) ;
V_163 = F_61 ( V_4 , V_215 -> V_125 ) ;
F_100 ( V_163 ) ;
}
static int
F_101 ( struct V_3 * V_4 , struct V_152 * V_215 )
{
int V_7 ;
unsigned long long V_64 ;
V_4 -> V_125 = V_215 -> V_125 ;
if ( V_215 -> V_125 == NULL ) {
F_32 ( V_4 -> V_39 , V_246 , 0 ) ;
if ( V_215 -> V_43 -> V_46 & V_133 ) {
V_64 = V_215 -> V_43 -> V_247 * V_248 ;
if ( ! V_64 )
V_64 = 100000000U ;
F_98 ( V_4 , V_64 , 0 ) ;
}
return 0 ;
}
if ( V_4 -> V_47 ) {
V_7 = F_93 ( V_4 , V_215 ) ;
if ( V_7 != 0 ) {
F_10 ( F_11 ( V_4 -> V_5 ) , L_55 ) ;
return V_7 ;
}
}
return 0 ;
}
static void F_102 ( struct V_6 * V_5 , struct V_152 * V_134 ,
int V_176 )
{
struct V_3 * V_4 = F_6 ( V_5 ) ;
struct V_124 * V_125 = V_134 -> V_125 ;
if ( V_4 -> V_47 && V_125 -> V_166 ) {
struct V_148 * V_249 = F_61 ( V_4 , V_125 ) ;
F_69 ( V_249 -> V_1 -> V_2 , V_125 -> V_164 , V_125 -> V_165 ,
F_70 ( V_125 ) ) ;
V_125 -> V_166 = 0 ;
}
}
static void F_103 ( struct V_6 * V_5 , struct V_152 * V_134 )
{
struct V_3 * V_4 = F_6 ( V_5 ) ;
if ( V_134 -> V_125 -> V_166 ) {
V_134 -> V_125 -> V_166 = 0 ;
return ;
}
if ( V_4 -> V_47 ) {
struct V_148 * V_249 = F_61 ( V_4 , V_134 -> V_125 ) ;
if ( F_90 ( V_4 , V_134 -> V_125 ,
& V_4 -> V_212 , V_249 ) )
V_134 -> V_125 -> V_166 = 0 ;
}
}
static void F_104 ( struct V_6 * V_5 , struct V_152 * V_215 )
{
struct V_3 * V_4 = F_6 ( V_5 ) ;
int V_176 ;
F_94 ( V_4 -> V_146 ) ;
F_94 ( V_4 -> V_153 != - 1 ) ;
if ( V_4 -> V_112 ) {
if ( V_4 -> V_205 < 3 ) {
F_73 ( V_4 , V_179 ) ;
F_73 ( V_4 , V_178 ) ;
V_4 -> V_205 += 1 ;
}
V_215 -> V_43 -> error = - V_250 ;
if ( V_215 -> V_125 )
V_215 -> V_125 -> error = - V_250 ;
V_215 -> V_43 -> V_251 = 0 ;
F_63 ( V_5 , V_215 ) ;
return;
} else if ( V_4 -> V_205 )
V_4 -> V_205 = 0 ;
F_105 ( V_4 -> V_134 != NULL ) ;
V_4 -> V_134 = V_215 ;
V_4 -> V_244 = F_41 ( V_4 -> V_61 ) ;
V_176 = F_101 ( V_4 , V_215 ) ;
if ( V_176 ) {
V_215 -> V_43 -> error = V_176 ;
if ( V_215 -> V_125 )
V_215 -> V_125 -> error = V_176 ;
V_4 -> V_134 = NULL ;
F_63 ( V_5 , V_215 ) ;
return;
}
if ( V_215 -> V_137 && ! ( V_4 -> V_46 & V_136 ) ) {
F_58 ( V_4 , V_215 -> V_137 , NULL ) ;
return;
}
F_66 ( V_4 ) ;
F_58 ( V_4 , V_215 -> V_43 , V_215 -> V_125 ) ;
}
static void F_106 ( struct V_6 * V_5 , struct V_8 * V_9 )
{
struct V_3 * V_4 = F_6 ( V_5 ) ;
int V_252 = 0 ;
if ( V_9 -> V_100 != V_4 -> V_100 ) {
switch ( V_9 -> V_100 ) {
case V_101 :
F_16 ( V_4 , 0 , 0 ) ;
break;
case V_253 :
F_16 ( V_4 , 1 , V_9 -> V_12 ) ;
break;
case V_254 :
V_252 = 1 ;
break;
}
V_4 -> V_100 = V_9 -> V_100 ;
}
F_47 ( V_4 ) ;
if ( V_4 -> V_32 -> V_98 & V_99 ) {
if ( ( F_33 ( V_4 -> V_39 , V_80 ) & V_255 ) &&
( V_9 -> V_12 == V_256 ) ) {
if ( F_80 ( V_4 , V_9 -> V_12 ) != 0 )
F_24 ( F_11 ( V_4 -> V_5 ) ,
L_56 ) ;
}
}
F_42 ( V_4 ) ;
if ( V_252 )
F_51 ( V_4 ) ;
F_48 ( V_4 ) ;
}
static int F_107 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = F_6 ( V_5 ) ;
if ( ! V_4 -> V_37 )
return - V_257 ;
return V_4 -> V_37 ( V_4 -> V_2 ) ;
}
static void F_108 ( struct V_6 * V_5 , struct V_258 * V_259 )
{
struct V_3 * V_4 = F_6 ( V_5 ) ;
if ( F_25 ( V_4 ) -> V_260 )
F_25 ( V_4 ) -> V_260 ( V_259 ) ;
}
static void F_109 ( struct V_6 * V_5 , int V_261 )
{
struct V_3 * V_4 = F_6 ( V_5 ) ;
T_1 V_44 , V_82 ;
unsigned long V_46 ;
F_36 ( & V_4 -> V_53 , V_46 ) ;
V_82 = F_33 ( V_4 -> V_39 , V_83 ) ;
V_44 = F_33 ( V_4 -> V_39 , V_56 ) ;
if ( V_261 ) {
V_4 -> V_46 |= V_57 ;
V_44 |= V_58 ;
V_82 |= V_262 | V_263 ;
} else {
V_4 -> V_46 &= ~ V_57 ;
V_44 &= ~ V_58 ;
V_82 &= ~ ( V_262 | V_263 ) ;
}
F_32 ( V_4 -> V_39 , V_83 , V_82 ) ;
F_32 ( V_4 -> V_39 , V_59 , V_44 ) ;
if ( ! V_4 -> V_146 || ! V_261 )
F_32 ( V_4 -> V_39 , V_56 , V_44 ) ;
F_33 ( V_4 -> V_39 , V_59 ) ;
F_37 ( & V_4 -> V_53 , V_46 ) ;
}
static int F_110 ( struct V_3 * V_4 )
{
int V_7 ;
if ( ! V_4 -> V_2 -> V_29 || ! V_4 -> V_264 )
return - V_28 ;
V_7 = F_111 ( V_4 -> V_2 , V_4 -> V_264 ) ;
if ( V_7 ) {
F_10 ( F_11 ( V_4 -> V_5 ) , L_57 ) ;
goto V_176;
}
if ( V_4 -> V_32 -> V_98 & V_265 ) {
struct V_266 * V_267 = F_112 ( V_4 -> V_2 ) ;
if ( F_7 ( V_267 ) ) {
V_7 = F_23 ( V_267 ) ;
goto V_268;
}
if ( F_7 ( F_113 ( V_267 , V_269 ) ) ) {
F_84 ( V_4 -> V_2 , L_58 ) ;
F_114 ( V_267 ) ;
V_7 = - V_214 ;
goto V_268;
}
if ( F_7 ( F_113 ( V_267 , V_270 ) ) ) {
F_84 ( V_4 -> V_2 , L_59 ) ;
F_114 ( V_267 ) ;
V_7 = - V_214 ;
goto V_268;
}
F_114 ( V_267 ) ;
}
F_32 ( V_4 -> V_39 , V_80 ,
F_33 ( V_4 -> V_39 , V_80 ) | V_109 ) ;
return 0 ;
V_268:
F_115 ( V_4 -> V_2 ) ;
V_176:
F_91 ( V_4 -> V_2 , L_60 ) ;
V_4 -> V_264 = 0 ;
return V_7 ;
}
static void F_116 ( struct V_3 * V_4 )
{
T_1 V_94 , V_95 , V_271 ;
if ( V_4 -> V_32 -> V_98 & V_99 ) {
V_94 = V_104 ;
V_95 = V_105 | V_106 ;
} else {
V_94 = V_103 ;
V_95 = V_106 ;
}
V_271 = F_33 ( V_4 -> V_39 , V_80 ) & ~ V_272 ;
F_32 ( V_4 -> V_39 , V_80 , V_271 | V_94 ) ;
V_271 = F_33 ( V_4 -> V_39 , V_78 ) ;
F_32 ( V_4 -> V_39 , V_78 , V_271 | V_95 ) ;
F_79 ( V_4 ) ;
}
static int F_117 ( struct V_258 * V_259 ,
unsigned int V_273 , int V_274 )
{
if ( V_273 == V_143 )
return 1 ;
return V_274 ;
}
static int F_118 ( struct V_275 * V_276 , void * V_125 )
{
struct V_6 * V_5 = V_276 -> V_277 ;
struct V_3 * V_4 = F_6 ( V_5 ) ;
F_119 ( V_276 , L_61 , V_5 -> V_278 ) ;
F_119 ( V_276 , L_62 ,
( V_5 -> V_107 & V_108 ) ? L_63 : L_64 ) ;
if ( V_5 -> V_107 & V_108 ) {
F_119 ( V_276 , L_65 ,
( V_4 -> V_46 & V_57 ) ? L_66
: L_67 ) ;
}
F_119 ( V_276 , L_68 , V_4 -> V_97 ) ;
F_120 ( V_4 -> V_2 ) ;
F_121 ( V_276 , L_69 ) ;
F_119 ( V_276 , L_70 ,
F_33 ( V_4 -> V_39 , V_83 ) ) ;
F_119 ( V_276 , L_71 ,
F_33 ( V_4 -> V_39 , V_279 ) ) ;
F_119 ( V_276 , L_72 ,
F_33 ( V_4 -> V_39 , V_80 ) ) ;
F_119 ( V_276 , L_73 ,
F_33 ( V_4 -> V_39 , V_40 ) ) ;
F_119 ( V_276 , L_74 ,
F_33 ( V_4 -> V_39 , V_59 ) ) ;
F_119 ( V_276 , L_75 ,
F_33 ( V_4 -> V_39 , V_56 ) ) ;
F_119 ( V_276 , L_76 ,
F_33 ( V_4 -> V_39 , V_78 ) ) ;
F_122 ( V_4 -> V_2 ) ;
F_123 ( V_4 -> V_2 ) ;
return 0 ;
}
static int F_124 ( struct V_280 * V_280 , struct V_281 * V_281 )
{
return F_125 ( V_281 , F_118 , V_280 -> V_282 ) ;
}
static void F_126 ( struct V_6 * V_5 )
{
if ( V_5 -> V_283 )
F_127 ( L_77 , V_284 , V_5 -> V_283 ,
V_5 , & V_285 ) ;
}
static void F_126 ( struct V_6 * V_5 )
{
}
static struct V_31 * F_128 ( struct V_1 * V_2 )
{
struct V_31 * V_32 , * V_286 ;
struct V_287 * V_288 = V_2 -> V_29 ;
V_32 = F_129 ( V_2 , sizeof( * V_32 ) , V_289 ) ;
if ( ! V_32 )
return F_130 ( - V_290 ) ;
V_286 = F_131 ( V_2 ) ;
if ( V_286 && V_286 -> V_123 )
V_32 -> V_123 = V_286 -> V_123 ;
if ( F_132 ( V_288 , L_78 , NULL ) )
V_32 -> V_98 |= V_99 ;
V_32 -> V_36 = - V_214 ;
V_32 -> V_33 = - V_214 ;
V_32 -> V_38 = - V_214 ;
if ( F_132 ( V_288 , L_79 , NULL ) ) {
V_32 -> V_291 = true ;
V_32 -> V_30 = true ;
}
if ( F_132 ( V_288 , L_80 , NULL ) )
V_32 -> V_73 |= V_174 ;
if ( F_132 ( V_288 , L_81 , NULL ) )
V_32 -> V_73 |= V_74 ;
return V_32 ;
}
static inline struct V_31
* F_128 ( struct V_1 * V_2 )
{
return F_130 ( - V_214 ) ;
}
static int F_133 ( struct V_292 * V_293 )
{
struct V_31 * V_32 = V_293 -> V_2 . V_294 ;
struct V_6 * V_5 ;
struct V_3 * V_4 = NULL ;
struct V_295 * V_168 ;
int V_7 , V_113 ;
const struct V_296 * V_297 ;
const struct V_298 * V_125 ;
void T_6 * V_39 ;
V_297 = F_134 ( F_135 ( V_299 ) , & V_293 -> V_2 ) ;
if ( V_297 ) {
V_32 = F_128 ( & V_293 -> V_2 ) ;
if ( F_7 ( V_32 ) )
return F_23 ( V_32 ) ;
if ( V_297 -> V_125 ) {
V_125 = V_297 -> V_125 ;
V_32 -> V_300 = V_125 -> V_300 ;
V_32 -> V_98 |= V_125 -> V_98 ;
}
}
if ( V_32 == NULL ) {
F_10 ( & V_293 -> V_2 , L_82 ) ;
return - V_301 ;
}
V_168 = F_136 ( V_293 , V_302 , 0 ) ;
V_113 = F_137 ( V_293 , 0 ) ;
if ( V_168 == NULL || V_113 < 0 )
return - V_301 ;
V_39 = F_138 ( & V_293 -> V_2 , V_168 ) ;
if ( F_7 ( V_39 ) )
return F_23 ( V_39 ) ;
V_5 = F_139 ( sizeof( struct V_3 ) , & V_293 -> V_2 ) ;
if ( ! V_5 ) {
V_7 = - V_290 ;
goto V_176;
}
V_7 = F_140 ( V_5 ) ;
if ( V_7 )
goto V_303;
V_4 = F_6 ( V_5 ) ;
V_4 -> V_5 = V_5 ;
V_4 -> V_32 = V_32 ;
V_4 -> V_2 = & V_293 -> V_2 ;
V_4 -> V_47 = 1 ;
V_4 -> V_153 = - 1 ;
V_4 -> V_113 = V_113 ;
V_4 -> V_221 = V_168 -> V_304 + V_32 -> V_300 ;
V_4 -> V_39 = V_39 + V_32 -> V_300 ;
V_4 -> V_100 = V_101 ;
V_4 -> V_212 . V_213 = 1 ;
V_4 -> V_23 = 0 ;
V_4 -> V_14 = 0 ;
V_7 = F_26 ( V_5 , V_4 , V_32 ) ;
if ( V_7 )
goto V_305;
F_141 ( V_293 , V_4 ) ;
if ( V_293 -> V_2 . V_29 )
V_4 -> V_264 = F_142 ( V_293 -> V_2 . V_29 , 1 ) ;
V_5 -> V_306 = & V_307 ;
V_5 -> V_308 = V_309 ;
if ( V_32 -> V_310 > 0 )
V_5 -> V_311 = V_32 -> V_310 ;
else if ( V_5 -> V_311 == 0 )
V_5 -> V_311 = V_312 ;
F_143 ( & V_4 -> V_53 ) ;
V_4 -> V_61 = F_144 ( & V_293 -> V_2 , L_83 ) ;
if ( F_7 ( V_4 -> V_61 ) ) {
V_7 = F_23 ( V_4 -> V_61 ) ;
V_4 -> V_61 = NULL ;
goto V_303;
}
if ( V_4 -> V_32 -> V_98 & V_313 ) {
F_84 ( & V_293 -> V_2 , L_84 ) ;
V_307 . V_314 = F_117 ;
}
F_145 ( & V_293 -> V_2 , true ) ;
F_146 ( V_4 -> V_2 ) ;
F_120 ( V_4 -> V_2 ) ;
F_147 ( V_4 -> V_2 , V_315 ) ;
F_148 ( V_4 -> V_2 ) ;
F_50 ( V_4 ) ;
V_4 -> V_203 = F_144 ( & V_293 -> V_2 , L_85 ) ;
if ( F_7 ( V_4 -> V_203 ) ) {
V_4 -> V_203 = NULL ;
} else if ( F_82 ( V_4 -> V_203 ) != 0 ) {
F_91 ( F_11 ( V_4 -> V_5 ) , L_86 ) ;
V_4 -> V_203 = NULL ;
}
V_5 -> V_316 = 1024 ;
V_5 -> V_317 = 512 ;
V_5 -> V_318 = 0xFFFF ;
V_5 -> V_319 = V_5 -> V_317 * V_5 -> V_318 ;
V_5 -> V_320 = V_5 -> V_319 ;
V_5 -> V_107 |= V_321 | V_322 |
V_323 | V_324 | V_325 ;
V_5 -> V_107 |= F_25 ( V_4 ) -> V_107 ;
if ( V_5 -> V_107 & V_326 )
V_5 -> V_107 |= V_327 ;
if ( F_25 ( V_4 ) -> V_291 )
V_5 -> V_107 |= V_328 ;
V_5 -> V_329 |= F_25 ( V_4 ) -> V_329 ;
F_116 ( V_4 ) ;
V_4 -> V_151 = F_149 ( & V_293 -> V_2 , L_87 ) ;
if ( F_7 ( V_4 -> V_151 ) ) {
F_10 ( F_11 ( V_4 -> V_5 ) , L_88 ) ;
V_7 = F_23 ( V_4 -> V_151 ) ;
goto V_330;
}
V_4 -> V_150 = F_149 ( & V_293 -> V_2 , L_89 ) ;
if ( F_7 ( V_4 -> V_150 ) ) {
F_10 ( F_11 ( V_4 -> V_5 ) , L_90 ) ;
V_7 = F_23 ( V_4 -> V_150 ) ;
goto V_330;
}
V_7 = F_150 ( & V_293 -> V_2 , V_4 -> V_113 , F_77 , 0 ,
F_59 ( V_5 ) , V_4 ) ;
if ( V_7 ) {
F_10 ( F_11 ( V_4 -> V_5 ) , L_91 ) ;
goto V_330;
}
V_7 = F_20 ( V_4 ) ;
if ( V_7 )
goto V_330;
if ( ! V_5 -> V_331 )
V_5 -> V_331 = F_25 ( V_4 ) -> V_332 ;
F_38 ( V_4 ) ;
V_7 = F_110 ( V_4 ) ;
if ( ! V_7 )
V_5 -> V_107 |= V_108 ;
F_83 ( V_4 ) ;
F_151 ( V_5 ) ;
if ( F_25 ( V_4 ) -> V_123 != NULL ) {
V_7 = F_152 ( & V_5 -> V_122 , & V_333 ) ;
if ( V_7 < 0 )
goto V_334;
}
if ( V_4 -> V_34 ) {
V_7 = F_152 ( & V_5 -> V_122 ,
& V_335 ) ;
if ( V_7 < 0 )
goto V_334;
}
F_126 ( V_5 ) ;
F_122 ( V_4 -> V_2 ) ;
F_123 ( V_4 -> V_2 ) ;
return 0 ;
V_334:
F_153 ( V_5 ) ;
V_330:
F_145 ( & V_293 -> V_2 , false ) ;
if ( ! F_154 ( V_4 -> V_150 ) )
F_155 ( V_4 -> V_150 ) ;
if ( ! F_154 ( V_4 -> V_151 ) )
F_155 ( V_4 -> V_151 ) ;
F_156 ( V_4 -> V_2 ) ;
F_157 ( V_4 -> V_2 ) ;
F_158 ( V_4 -> V_2 ) ;
if ( V_4 -> V_203 )
F_81 ( V_4 -> V_203 ) ;
V_303:
V_305:
F_159 ( V_5 ) ;
V_176:
return V_7 ;
}
static int F_160 ( struct V_292 * V_293 )
{
struct V_3 * V_4 = F_161 ( V_293 ) ;
F_120 ( V_4 -> V_2 ) ;
F_153 ( V_4 -> V_5 ) ;
F_155 ( V_4 -> V_150 ) ;
F_155 ( V_4 -> V_151 ) ;
F_156 ( V_4 -> V_2 ) ;
F_157 ( V_4 -> V_2 ) ;
F_158 ( V_4 -> V_2 ) ;
F_145 ( & V_293 -> V_2 , false ) ;
if ( V_4 -> V_203 )
F_81 ( V_4 -> V_203 ) ;
F_159 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_162 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 )
return 0 ;
F_120 ( V_4 -> V_2 ) ;
if ( ! ( V_4 -> V_5 -> V_336 & V_337 ) ) {
F_32 ( V_4 -> V_39 , V_56 , 0 ) ;
F_32 ( V_4 -> V_39 , V_59 , 0 ) ;
F_32 ( V_4 -> V_39 , V_54 , V_55 ) ;
F_32 ( V_4 -> V_39 , V_80 ,
F_33 ( V_4 -> V_39 , V_80 ) & ~ V_110 ) ;
}
if ( V_4 -> V_203 )
F_81 ( V_4 -> V_203 ) ;
F_157 ( V_4 -> V_2 ) ;
return 0 ;
}
static int F_163 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 )
return 0 ;
F_120 ( V_4 -> V_2 ) ;
if ( V_4 -> V_203 )
F_82 ( V_4 -> V_203 ) ;
if ( ! ( V_4 -> V_5 -> V_336 & V_337 ) )
F_116 ( V_4 ) ;
F_83 ( V_4 ) ;
F_122 ( V_4 -> V_2 ) ;
F_123 ( V_4 -> V_2 ) ;
return 0 ;
}
static int F_164 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_46 ;
int V_7 = 0 ;
V_4 = F_161 ( F_165 ( V_2 ) ) ;
F_50 ( V_4 ) ;
F_24 ( V_2 , L_92 ) ;
F_36 ( & V_4 -> V_53 , V_46 ) ;
if ( ( V_4 -> V_5 -> V_107 & V_108 ) &&
( V_4 -> V_46 & V_57 ) ) {
F_32 ( V_4 -> V_39 , V_56 , 0 ) ;
F_32 ( V_4 -> V_39 , V_59 , 0 ) ;
if ( ! ( F_33 ( V_4 -> V_39 , V_279 ) & F_166 ( 1 ) ) ) {
F_24 ( V_2 , L_93 ) ;
F_32 ( V_4 -> V_39 , V_54 , V_55 ) ;
F_32 ( V_4 -> V_39 , V_56 , V_58 ) ;
F_32 ( V_4 -> V_39 , V_59 , V_58 ) ;
F_122 ( V_2 ) ;
V_7 = - V_338 ;
goto abort;
}
F_167 ( V_2 ) ;
} else {
F_167 ( V_2 ) ;
}
abort:
F_37 ( & V_4 -> V_53 , V_46 ) ;
return V_7 ;
}
static int F_168 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_46 ;
V_4 = F_161 ( F_165 ( V_2 ) ) ;
F_49 ( V_4 ) ;
F_24 ( V_2 , L_94 ) ;
F_36 ( & V_4 -> V_53 , V_46 ) ;
if ( ( V_4 -> V_5 -> V_107 & V_108 ) &&
( V_4 -> V_46 & V_57 ) ) {
F_169 ( V_4 -> V_2 ) ;
F_32 ( V_4 -> V_39 , V_54 , V_55 ) ;
F_32 ( V_4 -> V_39 , V_56 , V_58 ) ;
F_32 ( V_4 -> V_39 , V_59 , V_58 ) ;
} else {
F_169 ( V_4 -> V_2 ) ;
}
F_37 ( & V_4 -> V_53 , V_46 ) ;
return 0 ;
}
