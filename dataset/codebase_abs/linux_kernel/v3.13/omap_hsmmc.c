static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
return ! F_3 ( V_7 -> V_9 [ 0 ] . V_10 ) ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
return F_3 ( V_7 -> V_9 [ 0 ] . V_11 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
return ! F_3 ( V_7 -> V_9 [ 0 ] . V_10 ) ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
F_7 ( V_7 -> V_9 [ 0 ] . V_12 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
F_9 ( V_7 -> V_9 [ 0 ] . V_12 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , int V_3 , int V_13 ,
int V_14 )
{
struct V_4 * V_5 =
F_11 ( F_12 ( V_2 ) ) ;
int V_15 = 0 ;
if ( ! V_5 -> V_16 )
return 0 ;
if ( V_5 -> V_17 && ! V_14 )
return 0 ;
if ( F_13 ( V_5 ) . V_18 )
F_13 ( V_5 ) . V_18 ( V_2 , V_3 , V_13 , V_14 ) ;
if ( V_13 ) {
V_15 = F_14 ( V_5 -> V_7 , V_5 -> V_16 , V_14 ) ;
if ( V_15 == 0 && V_5 -> V_19 ) {
V_15 = F_15 ( V_5 -> V_19 ) ;
if ( V_15 < 0 )
V_15 = F_14 ( V_5 -> V_7 ,
V_5 -> V_16 , 0 ) ;
}
} else {
if ( V_5 -> V_19 )
V_15 = F_16 ( V_5 -> V_19 ) ;
if ( ! V_15 ) {
V_15 = F_14 ( V_5 -> V_7 ,
V_5 -> V_16 , 0 ) ;
}
}
if ( F_13 ( V_5 ) . V_20 )
F_13 ( V_5 ) . V_20 ( V_2 , V_3 , V_13 , V_14 ) ;
return V_15 ;
}
static int F_17 ( struct V_4 * V_5 )
{
struct V_21 * V_22 ;
int V_23 = 0 ;
V_22 = F_18 ( V_5 -> V_2 , L_1 ) ;
if ( F_19 ( V_22 ) ) {
F_20 ( V_5 -> V_2 , L_2 ) ;
return F_21 ( V_22 ) ;
} else {
F_13 ( V_5 ) . V_24 = F_10 ;
V_5 -> V_16 = V_22 ;
V_23 = F_22 ( V_22 ) ;
if ( ! F_13 ( V_5 ) . V_25 ) {
F_13 ( V_5 ) . V_25 = V_23 ;
} else {
if ( ! ( F_13 ( V_5 ) . V_25 & V_23 ) ) {
F_20 ( V_5 -> V_2 , L_3 ,
F_13 ( V_5 ) . V_25 ) ;
F_13 ( V_5 ) . V_25 = 0 ;
return - V_26 ;
}
}
V_22 = F_18 ( V_5 -> V_2 , L_4 ) ;
V_5 -> V_19 = F_19 ( V_22 ) ? NULL : V_22 ;
if ( F_13 ( V_5 ) . V_27 )
return 0 ;
if ( F_23 ( V_5 -> V_16 ) > 0 ||
( V_5 -> V_19 && F_23 ( V_5 -> V_19 ) ) ) {
int V_14 = F_24 ( F_13 ( V_5 ) . V_25 ) - 1 ;
F_13 ( V_5 ) . V_24 ( V_5 -> V_2 , V_5 -> V_28 ,
1 , V_14 ) ;
F_13 ( V_5 ) . V_24 ( V_5 -> V_2 , V_5 -> V_28 ,
0 , 0 ) ;
}
}
return 0 ;
}
static void F_25 ( struct V_4 * V_5 )
{
F_26 ( V_5 -> V_16 ) ;
F_26 ( V_5 -> V_19 ) ;
F_13 ( V_5 ) . V_24 = NULL ;
}
static inline int F_27 ( void )
{
return 1 ;
}
static inline int F_17 ( struct V_4 * V_5 )
{
return - V_26 ;
}
static inline void F_25 ( struct V_4 * V_5 )
{
}
static inline int F_27 ( void )
{
return 0 ;
}
static int F_28 ( struct V_6 * V_8 )
{
int V_15 ;
if ( F_29 ( V_8 -> V_9 [ 0 ] . V_10 ) ) {
if ( V_8 -> V_9 [ 0 ] . V_29 )
V_8 -> V_9 [ 0 ] . V_30 =
F_5 ;
else
V_8 -> V_9 [ 0 ] . V_31 = F_1 ;
V_8 -> V_9 [ 0 ] . V_12 =
F_30 ( V_8 -> V_9 [ 0 ] . V_10 ) ;
V_15 = F_31 ( V_8 -> V_9 [ 0 ] . V_10 , L_5 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_32 ( V_8 -> V_9 [ 0 ] . V_10 ) ;
if ( V_15 )
goto V_32;
} else
V_8 -> V_9 [ 0 ] . V_10 = - V_26 ;
if ( F_29 ( V_8 -> V_9 [ 0 ] . V_11 ) ) {
V_8 -> V_9 [ 0 ] . V_33 = F_4 ;
V_15 = F_31 ( V_8 -> V_9 [ 0 ] . V_11 , L_6 ) ;
if ( V_15 )
goto V_34;
V_15 = F_32 ( V_8 -> V_9 [ 0 ] . V_11 ) ;
if ( V_15 )
goto V_35;
} else
V_8 -> V_9 [ 0 ] . V_11 = - V_26 ;
return 0 ;
V_35:
F_33 ( V_8 -> V_9 [ 0 ] . V_11 ) ;
V_34:
if ( F_29 ( V_8 -> V_9 [ 0 ] . V_10 ) )
V_32:
F_33 ( V_8 -> V_9 [ 0 ] . V_10 ) ;
return V_15 ;
}
static void F_34 ( struct V_6 * V_8 )
{
if ( F_29 ( V_8 -> V_9 [ 0 ] . V_11 ) )
F_33 ( V_8 -> V_9 [ 0 ] . V_11 ) ;
if ( F_29 ( V_8 -> V_9 [ 0 ] . V_10 ) )
F_33 ( V_8 -> V_9 [ 0 ] . V_10 ) ;
}
static void F_35 ( struct V_4 * V_5 )
{
F_36 ( V_5 -> V_36 , V_37 ,
F_37 ( V_5 -> V_36 , V_37 ) | V_38 ) ;
}
static void F_38 ( struct V_4 * V_5 )
{
F_36 ( V_5 -> V_36 , V_37 ,
F_37 ( V_5 -> V_36 , V_37 ) & ~ V_38 ) ;
if ( ( F_37 ( V_5 -> V_36 , V_37 ) & V_38 ) != 0x0 )
F_39 ( F_40 ( V_5 -> V_7 ) , L_7 ) ;
}
static void F_41 ( struct V_4 * V_5 ,
struct V_39 * V_40 )
{
unsigned int V_41 ;
if ( V_5 -> V_42 )
V_41 = V_43 & ~ ( V_44 | V_45 ) ;
else
V_41 = V_43 ;
if ( V_40 -> V_46 == V_47 )
V_41 &= ~ V_48 ;
F_36 ( V_5 -> V_36 , V_49 , V_50 ) ;
F_36 ( V_5 -> V_36 , V_51 , V_41 ) ;
F_36 ( V_5 -> V_36 , V_52 , V_41 ) ;
}
static void F_42 ( struct V_4 * V_5 )
{
F_36 ( V_5 -> V_36 , V_51 , 0 ) ;
F_36 ( V_5 -> V_36 , V_52 , 0 ) ;
F_36 ( V_5 -> V_36 , V_49 , V_50 ) ;
}
static T_1 F_43 ( struct V_4 * V_5 , struct V_53 * V_54 )
{
T_1 V_55 = 0 ;
if ( V_54 -> clock ) {
V_55 = F_44 ( F_45 ( V_5 -> V_56 ) , V_54 -> clock ) ;
if ( V_55 > V_57 )
V_55 = V_57 ;
}
return V_55 ;
}
static void F_46 ( struct V_4 * V_5 )
{
struct V_53 * V_54 = & V_5 -> V_7 -> V_54 ;
unsigned long V_58 ;
unsigned long V_59 ;
unsigned long V_60 ;
F_47 ( F_40 ( V_5 -> V_7 ) , L_8 , V_54 -> clock ) ;
F_38 ( V_5 ) ;
V_58 = F_37 ( V_5 -> V_36 , V_37 ) ;
V_58 = V_58 & ~ ( V_61 | V_62 ) ;
V_60 = F_43 ( V_5 , V_54 ) ;
V_58 = V_58 | ( V_60 << 6 ) | ( V_63 << 16 ) ;
F_36 ( V_5 -> V_36 , V_37 , V_58 ) ;
F_36 ( V_5 -> V_36 , V_37 ,
F_37 ( V_5 -> V_36 , V_37 ) | V_64 ) ;
V_59 = V_65 + F_48 ( V_66 ) ;
while ( ( F_37 ( V_5 -> V_36 , V_37 ) & V_67 ) != V_67
&& F_49 ( V_65 , V_59 ) )
F_50 () ;
if ( ( F_13 ( V_5 ) . V_68 & V_69 ) &&
( V_54 -> V_70 != V_71 ) &&
( ( F_37 ( V_5 -> V_36 , V_72 ) & V_73 ) == V_73 ) ) {
V_58 = F_37 ( V_5 -> V_36 , V_74 ) ;
if ( V_60 && ( F_45 ( V_5 -> V_56 ) / V_60 ) > 25000000 )
V_58 |= V_75 ;
else
V_58 &= ~ V_75 ;
F_36 ( V_5 -> V_36 , V_74 , V_58 ) ;
}
F_35 ( V_5 ) ;
}
static void F_51 ( struct V_4 * V_5 )
{
struct V_53 * V_54 = & V_5 -> V_7 -> V_54 ;
T_2 V_76 ;
V_76 = F_37 ( V_5 -> V_36 , V_77 ) ;
if ( V_54 -> V_70 == V_71 )
V_76 |= V_78 ;
else
V_76 &= ~ V_78 ;
switch ( V_54 -> V_79 ) {
case V_80 :
F_36 ( V_5 -> V_36 , V_77 , V_76 | V_81 ) ;
break;
case V_82 :
F_36 ( V_5 -> V_36 , V_77 , V_76 & ~ V_81 ) ;
F_36 ( V_5 -> V_36 , V_74 ,
F_37 ( V_5 -> V_36 , V_74 ) | V_83 ) ;
break;
case V_84 :
F_36 ( V_5 -> V_36 , V_77 , V_76 & ~ V_81 ) ;
F_36 ( V_5 -> V_36 , V_74 ,
F_37 ( V_5 -> V_36 , V_74 ) & ~ V_83 ) ;
break;
}
}
static void F_52 ( struct V_4 * V_5 )
{
struct V_53 * V_54 = & V_5 -> V_7 -> V_54 ;
T_2 V_76 ;
V_76 = F_37 ( V_5 -> V_36 , V_77 ) ;
if ( V_54 -> V_85 == V_86 )
F_36 ( V_5 -> V_36 , V_77 , V_76 | V_87 ) ;
else
F_36 ( V_5 -> V_36 , V_77 , V_76 & ~ V_87 ) ;
}
static int F_53 ( struct V_4 * V_5 )
{
struct V_53 * V_54 = & V_5 -> V_7 -> V_54 ;
T_2 V_88 , V_89 ;
unsigned long V_59 ;
if ( ! F_37 ( V_5 -> V_36 , V_90 ) & V_91 )
return 1 ;
if ( V_5 -> V_76 == F_37 ( V_5 -> V_36 , V_77 ) &&
V_5 -> V_88 == F_37 ( V_5 -> V_36 , V_74 ) &&
V_5 -> V_92 == F_37 ( V_5 -> V_36 , V_37 ) &&
V_5 -> V_89 == F_37 ( V_5 -> V_36 , V_72 ) )
return 0 ;
V_5 -> V_93 ++ ;
if ( V_5 -> V_8 -> V_94 & V_95 ) {
if ( V_5 -> V_96 != V_97 &&
( 1 << V_54 -> V_14 ) <= V_98 )
V_88 = V_99 ;
else
V_88 = V_100 ;
V_89 = V_101 | V_102 ;
} else {
V_88 = V_99 ;
V_89 = V_102 ;
}
F_36 ( V_5 -> V_36 , V_74 ,
F_37 ( V_5 -> V_36 , V_74 ) | V_88 ) ;
F_36 ( V_5 -> V_36 , V_72 ,
F_37 ( V_5 -> V_36 , V_72 ) | V_89 ) ;
F_36 ( V_5 -> V_36 , V_74 ,
F_37 ( V_5 -> V_36 , V_74 ) | V_103 ) ;
V_59 = V_65 + F_48 ( V_66 ) ;
while ( ( F_37 ( V_5 -> V_36 , V_74 ) & V_103 ) != V_103
&& F_49 ( V_65 , V_59 ) )
;
F_42 ( V_5 ) ;
if ( V_5 -> V_96 == V_97 )
goto V_104;
F_51 ( V_5 ) ;
F_46 ( V_5 ) ;
F_52 ( V_5 ) ;
V_104:
F_39 ( F_40 ( V_5 -> V_7 ) , L_9 ,
V_5 -> V_93 ) ;
return 0 ;
}
static void F_54 ( struct V_4 * V_5 )
{
V_5 -> V_76 = F_37 ( V_5 -> V_36 , V_77 ) ;
V_5 -> V_88 = F_37 ( V_5 -> V_36 , V_74 ) ;
V_5 -> V_92 = F_37 ( V_5 -> V_36 , V_37 ) ;
V_5 -> V_89 = F_37 ( V_5 -> V_36 , V_72 ) ;
}
static int F_53 ( struct V_4 * V_5 )
{
return 0 ;
}
static void F_54 ( struct V_4 * V_5 )
{
}
static void F_55 ( struct V_4 * V_5 )
{
int V_22 = 0 ;
unsigned long V_59 ;
if ( V_5 -> V_105 )
return;
F_7 ( V_5 -> V_106 ) ;
F_36 ( V_5 -> V_36 , V_52 , V_43 ) ;
F_36 ( V_5 -> V_36 , V_77 ,
F_37 ( V_5 -> V_36 , V_77 ) | V_107 ) ;
F_36 ( V_5 -> V_36 , V_108 , V_109 ) ;
V_59 = V_65 + F_48 ( V_66 ) ;
while ( ( V_22 != V_110 ) && F_49 ( V_65 , V_59 ) )
V_22 = F_37 ( V_5 -> V_36 , V_49 ) & V_110 ;
F_36 ( V_5 -> V_36 , V_77 ,
F_37 ( V_5 -> V_36 , V_77 ) & ~ V_107 ) ;
F_36 ( V_5 -> V_36 , V_49 , V_50 ) ;
F_37 ( V_5 -> V_36 , V_49 ) ;
F_9 ( V_5 -> V_106 ) ;
}
static inline
int F_56 ( struct V_4 * V_5 )
{
int V_111 = 1 ;
if ( F_13 ( V_5 ) . V_30 )
V_111 = F_13 ( V_5 ) . V_30 ( V_5 -> V_2 , V_5 -> V_28 ) ;
return V_111 ;
}
static T_3
F_57 ( struct V_1 * V_2 , struct V_112 * V_113 ,
char * V_114 )
{
struct V_115 * V_7 = F_58 ( V_2 , struct V_115 , V_116 ) ;
struct V_4 * V_5 = F_59 ( V_7 ) ;
return sprintf ( V_114 , L_10 ,
F_56 ( V_5 ) ? L_11 : L_12 ) ;
}
static T_3
F_60 ( struct V_1 * V_2 , struct V_112 * V_113 ,
char * V_114 )
{
struct V_115 * V_7 = F_58 ( V_2 , struct V_115 , V_116 ) ;
struct V_4 * V_5 = F_59 ( V_7 ) ;
return sprintf ( V_114 , L_10 , F_13 ( V_5 ) . V_117 ) ;
}
static void
F_61 ( struct V_4 * V_5 , struct V_39 * V_40 ,
struct V_118 * V_119 )
{
int V_120 = 0 , V_121 = 0 , V_122 = 0 ;
F_47 ( F_40 ( V_5 -> V_7 ) , L_13 ,
F_62 ( V_5 -> V_7 ) , V_40 -> V_46 , V_40 -> V_123 ) ;
V_5 -> V_40 = V_40 ;
F_41 ( V_5 , V_40 ) ;
V_5 -> V_124 = 0 ;
if ( V_40 -> V_125 & V_126 ) {
if ( V_40 -> V_125 & V_127 )
V_121 = 1 ;
else if ( V_40 -> V_125 & V_128 ) {
V_121 = 3 ;
V_5 -> V_124 = 1 ;
} else
V_121 = 2 ;
}
if ( V_40 == V_5 -> V_129 -> V_130 )
V_122 = 0x3 ;
V_120 = ( V_40 -> V_46 << 24 ) | ( V_121 << 16 ) | ( V_122 << 22 ) ;
if ( V_119 ) {
V_120 |= V_131 | V_132 | V_133 ;
if ( V_119 -> V_125 & V_134 )
V_120 |= V_135 ;
else
V_120 &= ~ ( V_135 ) ;
}
if ( V_5 -> V_42 )
V_120 |= V_136 ;
V_5 -> V_137 = 1 ;
F_36 ( V_5 -> V_36 , V_138 , V_40 -> V_123 ) ;
F_36 ( V_5 -> V_36 , V_108 , V_120 ) ;
}
static int
F_63 ( struct V_4 * V_5 , struct V_118 * V_119 )
{
if ( V_119 -> V_125 & V_139 )
return V_140 ;
else
return V_141 ;
}
static struct V_142 * F_64 ( struct V_4 * V_5 ,
struct V_118 * V_119 )
{
return V_119 -> V_125 & V_139 ? V_5 -> V_143 : V_5 -> V_144 ;
}
static void F_65 ( struct V_4 * V_5 , struct V_145 * V_129 )
{
int V_146 ;
unsigned long V_125 ;
F_66 ( & V_5 -> V_147 , V_125 ) ;
V_5 -> V_137 = 0 ;
V_146 = V_5 -> V_146 ;
F_67 ( & V_5 -> V_147 , V_125 ) ;
F_42 ( V_5 ) ;
if ( V_129 -> V_119 && V_5 -> V_42 && V_146 != - 1 )
return;
V_5 -> V_129 = NULL ;
F_68 ( V_5 -> V_7 , V_129 ) ;
}
static void
F_69 ( struct V_4 * V_5 , struct V_118 * V_119 )
{
if ( ! V_119 ) {
struct V_145 * V_129 = V_5 -> V_129 ;
if ( V_5 -> V_40 && V_5 -> V_40 -> V_46 == 6 &&
V_5 -> V_124 ) {
V_5 -> V_124 = 0 ;
return;
}
F_65 ( V_5 , V_129 ) ;
return;
}
V_5 -> V_119 = NULL ;
if ( ! V_119 -> error )
V_119 -> V_148 += V_119 -> V_149 * ( V_119 -> V_150 ) ;
else
V_119 -> V_148 = 0 ;
if ( ! V_119 -> V_130 ) {
F_65 ( V_5 , V_119 -> V_129 ) ;
return;
}
F_61 ( V_5 , V_119 -> V_130 , NULL ) ;
}
static void
F_70 ( struct V_4 * V_5 , struct V_39 * V_40 )
{
V_5 -> V_40 = NULL ;
if ( V_40 -> V_125 & V_126 ) {
if ( V_40 -> V_125 & V_127 ) {
V_40 -> V_151 [ 3 ] = F_37 ( V_5 -> V_36 , V_152 ) ;
V_40 -> V_151 [ 2 ] = F_37 ( V_5 -> V_36 , V_153 ) ;
V_40 -> V_151 [ 1 ] = F_37 ( V_5 -> V_36 , V_154 ) ;
V_40 -> V_151 [ 0 ] = F_37 ( V_5 -> V_36 , V_155 ) ;
} else {
V_40 -> V_151 [ 0 ] = F_37 ( V_5 -> V_36 , V_152 ) ;
}
}
if ( ( V_5 -> V_119 == NULL && ! V_5 -> V_124 ) || V_40 -> error )
F_65 ( V_5 , V_40 -> V_129 ) ;
}
static void F_71 ( struct V_4 * V_5 , int V_156 )
{
int V_146 ;
unsigned long V_125 ;
V_5 -> V_119 -> error = V_156 ;
F_66 ( & V_5 -> V_147 , V_125 ) ;
V_146 = V_5 -> V_146 ;
V_5 -> V_146 = - 1 ;
F_67 ( & V_5 -> V_147 , V_125 ) ;
if ( V_5 -> V_42 && V_146 != - 1 ) {
struct V_142 * V_157 = F_64 ( V_5 , V_5 -> V_119 ) ;
F_72 ( V_157 ) ;
F_73 ( V_157 -> V_1 -> V_2 ,
V_5 -> V_119 -> V_158 , V_5 -> V_119 -> V_159 ,
F_63 ( V_5 , V_5 -> V_119 ) ) ;
V_5 -> V_119 -> V_160 = 0 ;
}
V_5 -> V_119 = NULL ;
}
static void F_74 ( struct V_4 * V_5 , T_2 V_161 )
{
static const char * V_162 [] = {
L_14 , L_15 , L_16 , L_17 , L_18 , L_19 , L_17 , L_17 ,
L_20 , L_21 , L_17 , L_17 , L_17 , L_17 , L_17 , L_22 ,
L_23 , L_24 , L_25 , L_26 , L_27 , L_28 , L_29 , L_17 ,
L_30 , L_17 , L_17 , L_17 , L_31 , L_32 , L_17 , L_17
} ;
char V_163 [ 256 ] ;
char * V_114 = V_163 ;
int V_164 , V_165 ;
V_164 = sprintf ( V_114 , L_33 , V_161 ) ;
V_114 += V_164 ;
for ( V_165 = 0 ; V_165 < F_75 ( V_162 ) ; V_165 ++ )
if ( V_161 & ( 1 << V_165 ) ) {
V_164 = sprintf ( V_114 , L_34 , V_162 [ V_165 ] ) ;
V_114 += V_164 ;
}
F_47 ( F_40 ( V_5 -> V_7 ) , L_10 , V_163 ) ;
}
static inline void F_74 ( struct V_4 * V_5 ,
T_2 V_161 )
{
}
static inline void F_76 ( struct V_4 * V_5 ,
unsigned long V_166 )
{
unsigned long V_165 = 0 ;
unsigned long V_167 = V_168 ;
F_36 ( V_5 -> V_36 , V_37 ,
F_37 ( V_5 -> V_36 , V_37 ) | V_166 ) ;
if ( F_13 ( V_5 ) . V_68 & V_169 ) {
while ( ( ! ( F_37 ( V_5 -> V_36 , V_37 ) & V_166 ) )
&& ( V_165 ++ < V_167 ) )
F_77 ( 1 ) ;
}
V_165 = 0 ;
while ( ( F_37 ( V_5 -> V_36 , V_37 ) & V_166 ) &&
( V_165 ++ < V_167 ) )
F_77 ( 1 ) ;
if ( F_37 ( V_5 -> V_36 , V_37 ) & V_166 )
F_20 ( F_40 ( V_5 -> V_7 ) ,
L_35 ,
V_170 ) ;
}
static void F_78 ( struct V_4 * V_5 ,
int V_171 , int V_172 )
{
if ( V_172 ) {
F_76 ( V_5 , V_173 ) ;
if ( V_5 -> V_40 )
V_5 -> V_40 -> error = V_171 ;
}
if ( V_5 -> V_119 ) {
F_76 ( V_5 , V_174 ) ;
F_71 ( V_5 , V_171 ) ;
} else if ( V_5 -> V_129 && V_5 -> V_129 -> V_40 )
V_5 -> V_129 -> V_40 -> error = V_171 ;
}
static void F_79 ( struct V_4 * V_5 , int V_161 )
{
struct V_118 * V_119 ;
int V_172 = 0 , V_175 = 0 ;
V_119 = V_5 -> V_119 ;
F_47 ( F_40 ( V_5 -> V_7 ) , L_36 , V_161 ) ;
if ( V_161 & V_176 ) {
F_74 ( V_5 , V_161 ) ;
if ( V_161 & ( V_177 | V_178 ) )
V_172 = 1 ;
if ( V_161 & ( V_177 | V_48 ) )
F_78 ( V_5 , - V_179 , V_172 ) ;
else if ( V_161 & ( V_178 | V_180 ) )
F_78 ( V_5 , - V_181 , V_172 ) ;
if ( V_5 -> V_119 || V_5 -> V_124 ) {
V_175 = ! V_172 ;
V_5 -> V_124 = 0 ;
}
}
F_36 ( V_5 -> V_36 , V_49 , V_161 ) ;
if ( V_172 || ( ( V_161 & V_110 ) && V_5 -> V_40 ) )
F_70 ( V_5 , V_5 -> V_40 ) ;
if ( ( V_175 || ( V_161 & V_182 ) ) && V_5 -> V_129 )
F_69 ( V_5 , V_119 ) ;
}
static T_4 F_80 ( int V_106 , void * V_183 )
{
struct V_4 * V_5 = V_183 ;
int V_161 ;
V_161 = F_37 ( V_5 -> V_36 , V_49 ) ;
while ( V_161 & V_43 && V_5 -> V_137 ) {
F_79 ( V_5 , V_161 ) ;
V_161 = F_37 ( V_5 -> V_36 , V_49 ) ;
}
return V_184 ;
}
static void F_81 ( struct V_4 * V_5 )
{
unsigned long V_165 ;
F_36 ( V_5 -> V_36 , V_74 ,
F_37 ( V_5 -> V_36 , V_74 ) | V_103 ) ;
for ( V_165 = 0 ; V_165 < V_185 ; V_165 ++ ) {
if ( F_37 ( V_5 -> V_36 , V_74 ) & V_103 )
break;
F_50 () ;
}
}
static int F_82 ( struct V_4 * V_5 , int V_14 )
{
T_2 V_186 = 0 ;
int V_15 ;
F_83 ( V_5 -> V_2 ) ;
if ( V_5 -> V_187 )
F_84 ( V_5 -> V_187 ) ;
V_15 = F_13 ( V_5 ) . V_24 ( V_5 -> V_2 , V_5 -> V_28 , 0 , 0 ) ;
if ( ! V_15 )
V_15 = F_13 ( V_5 ) . V_24 ( V_5 -> V_2 , V_5 -> V_28 , 1 ,
V_14 ) ;
F_85 ( V_5 -> V_2 ) ;
if ( V_5 -> V_187 )
F_86 ( V_5 -> V_187 ) ;
if ( V_15 != 0 )
goto V_171;
F_36 ( V_5 -> V_36 , V_74 ,
F_37 ( V_5 -> V_36 , V_74 ) & V_188 ) ;
V_186 = F_37 ( V_5 -> V_36 , V_74 ) ;
if ( ( 1 << V_14 ) <= V_98 )
V_186 |= V_99 ;
else
V_186 |= V_100 ;
F_36 ( V_5 -> V_36 , V_74 , V_186 ) ;
F_81 ( V_5 ) ;
return 0 ;
V_171:
F_20 ( F_40 ( V_5 -> V_7 ) , L_37 ) ;
return V_15 ;
}
static void F_87 ( struct V_4 * V_5 )
{
if ( ! F_13 ( V_5 ) . V_30 )
return;
V_5 -> V_189 = 0 ;
if ( F_13 ( V_5 ) . V_30 ( V_5 -> V_2 , V_5 -> V_28 ) ) {
if ( V_5 -> V_105 ) {
F_88 ( V_5 -> V_2 , L_38
L_39 ,
F_62 ( V_5 -> V_7 ) ) ;
V_5 -> V_105 = 0 ;
}
} else {
if ( ! V_5 -> V_105 ) {
F_88 ( V_5 -> V_2 , L_40
L_41 ,
F_62 ( V_5 -> V_7 ) ) ;
V_5 -> V_105 = 1 ;
}
}
}
static T_4 F_89 ( int V_106 , void * V_183 )
{
struct V_4 * V_5 = V_183 ;
struct V_190 * V_3 = & F_13 ( V_5 ) ;
int V_191 ;
F_90 ( & V_5 -> V_7 -> V_116 . V_192 , NULL , L_42 ) ;
if ( V_3 -> V_31 )
V_191 = V_3 -> V_31 ( V_5 -> V_2 , V_5 -> V_28 ) ;
else {
F_87 ( V_5 ) ;
V_191 = - V_193 ;
}
if ( V_191 )
F_91 ( V_5 -> V_7 , ( V_194 * 200 ) / 1000 ) ;
else
F_91 ( V_5 -> V_7 , ( V_194 * 50 ) / 1000 ) ;
return V_184 ;
}
static void F_92 ( void * V_195 )
{
struct V_4 * V_5 = V_195 ;
struct V_142 * V_157 ;
struct V_118 * V_119 ;
int V_137 ;
F_93 ( & V_5 -> V_147 ) ;
if ( V_5 -> V_146 < 0 ) {
F_94 ( & V_5 -> V_147 ) ;
return;
}
V_119 = V_5 -> V_129 -> V_119 ;
V_157 = F_64 ( V_5 , V_119 ) ;
if ( ! V_119 -> V_160 )
F_73 ( V_157 -> V_1 -> V_2 ,
V_119 -> V_158 , V_119 -> V_159 ,
F_63 ( V_5 , V_119 ) ) ;
V_137 = V_5 -> V_137 ;
V_5 -> V_146 = - 1 ;
F_94 ( & V_5 -> V_147 ) ;
if ( ! V_137 ) {
struct V_145 * V_129 = V_5 -> V_129 ;
V_5 -> V_129 = NULL ;
F_68 ( V_5 -> V_7 , V_129 ) ;
}
}
static int F_95 ( struct V_4 * V_5 ,
struct V_118 * V_119 ,
struct V_196 * V_197 ,
struct V_142 * V_157 )
{
int V_198 ;
if ( ! V_197 && V_119 -> V_160 &&
V_119 -> V_160 != V_5 -> V_199 . V_200 ) {
F_96 ( V_5 -> V_2 , L_43
L_44 ,
V_170 , V_119 -> V_160 , V_5 -> V_199 . V_200 ) ;
V_119 -> V_160 = 0 ;
}
if ( V_197 ||
( ! V_197 && V_119 -> V_160 != V_5 -> V_199 . V_200 ) ) {
V_198 = F_97 ( V_157 -> V_1 -> V_2 , V_119 -> V_158 , V_119 -> V_159 ,
F_63 ( V_5 , V_119 ) ) ;
} else {
V_198 = V_5 -> V_199 . V_198 ;
V_5 -> V_199 . V_198 = 0 ;
}
if ( V_198 == 0 )
return - V_26 ;
if ( V_197 ) {
V_197 -> V_198 = V_198 ;
V_119 -> V_160 = ++ V_197 -> V_200 < 0 ? 1 : V_197 -> V_200 ;
} else
V_5 -> V_198 = V_198 ;
return 0 ;
}
static int F_98 ( struct V_4 * V_5 ,
struct V_145 * V_201 )
{
struct V_202 V_203 ;
struct V_204 * V_205 ;
int V_15 = 0 , V_165 ;
struct V_118 * V_119 = V_201 -> V_119 ;
struct V_142 * V_157 ;
for ( V_165 = 0 ; V_165 < V_119 -> V_159 ; V_165 ++ ) {
struct V_206 * V_207 ;
V_207 = V_119 -> V_158 + V_165 ;
if ( V_207 -> V_208 % V_119 -> V_150 )
return - V_26 ;
}
if ( ( V_119 -> V_150 % 4 ) != 0 )
return - V_26 ;
F_99 ( V_5 -> V_146 != - 1 ) ;
V_157 = F_64 ( V_5 , V_119 ) ;
V_203 . V_209 = V_5 -> V_210 + V_211 ;
V_203 . V_212 = V_5 -> V_210 + V_211 ;
V_203 . V_213 = V_214 ;
V_203 . V_215 = V_214 ;
V_203 . V_216 = V_119 -> V_150 / 4 ;
V_203 . V_217 = V_119 -> V_150 / 4 ;
V_15 = F_100 ( V_157 , & V_203 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_95 ( V_5 , V_119 , NULL , V_157 ) ;
if ( V_15 )
return V_15 ;
V_205 = F_101 ( V_157 , V_119 -> V_158 , V_119 -> V_159 ,
V_119 -> V_125 & V_139 ? V_218 : V_219 ,
V_220 | V_221 ) ;
if ( ! V_205 ) {
F_20 ( F_40 ( V_5 -> V_7 ) , L_45 ) ;
return - 1 ;
}
V_205 -> V_222 = F_92 ;
V_205 -> V_223 = V_5 ;
F_102 ( V_205 ) ;
V_5 -> V_146 = 1 ;
F_103 ( V_157 ) ;
return 0 ;
}
static void F_104 ( struct V_4 * V_5 ,
unsigned int V_224 ,
unsigned int V_225 )
{
unsigned int V_59 , V_226 ;
T_5 V_22 , V_227 , V_228 = 0 ;
V_22 = F_37 ( V_5 -> V_36 , V_37 ) ;
V_227 = ( V_22 & V_61 ) >> V_229 ;
if ( V_227 == 0 )
V_227 = 1 ;
V_226 = 1000000000 / ( F_45 ( V_5 -> V_56 ) / V_227 ) ;
V_59 = V_224 / V_226 ;
V_59 += V_225 ;
if ( V_59 ) {
while ( ( V_59 & 0x80000000 ) == 0 ) {
V_228 += 1 ;
V_59 <<= 1 ;
}
V_228 = 31 - V_228 ;
V_59 <<= 1 ;
if ( V_59 && V_228 )
V_228 += 1 ;
if ( V_228 >= 13 )
V_228 -= 13 ;
else
V_228 = 0 ;
if ( V_228 > 14 )
V_228 = 14 ;
}
V_22 &= ~ V_62 ;
V_22 |= V_228 << V_230 ;
F_36 ( V_5 -> V_36 , V_37 , V_22 ) ;
}
static int
F_105 ( struct V_4 * V_5 , struct V_145 * V_201 )
{
int V_15 ;
V_5 -> V_119 = V_201 -> V_119 ;
if ( V_201 -> V_119 == NULL ) {
F_36 ( V_5 -> V_36 , V_231 , 0 ) ;
if ( V_201 -> V_40 -> V_125 & V_128 )
F_104 ( V_5 , 100000000U , 0 ) ;
return 0 ;
}
F_36 ( V_5 -> V_36 , V_231 , ( V_201 -> V_119 -> V_150 )
| ( V_201 -> V_119 -> V_149 << 16 ) ) ;
F_104 ( V_5 , V_201 -> V_119 -> V_224 , V_201 -> V_119 -> V_225 ) ;
if ( V_5 -> V_42 ) {
V_15 = F_98 ( V_5 , V_201 ) ;
if ( V_15 != 0 ) {
F_20 ( F_40 ( V_5 -> V_7 ) , L_46 ) ;
return V_15 ;
}
}
return 0 ;
}
static void F_106 ( struct V_115 * V_7 , struct V_145 * V_129 ,
int V_171 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
struct V_118 * V_119 = V_129 -> V_119 ;
if ( V_5 -> V_42 && V_119 -> V_160 ) {
struct V_142 * V_232 = F_64 ( V_5 , V_119 ) ;
F_73 ( V_232 -> V_1 -> V_2 , V_119 -> V_158 , V_119 -> V_159 ,
F_63 ( V_5 , V_119 ) ) ;
V_119 -> V_160 = 0 ;
}
}
static void F_107 ( struct V_115 * V_7 , struct V_145 * V_129 ,
bool V_233 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
if ( V_129 -> V_119 -> V_160 ) {
V_129 -> V_119 -> V_160 = 0 ;
return ;
}
if ( V_5 -> V_42 ) {
struct V_142 * V_232 = F_64 ( V_5 , V_129 -> V_119 ) ;
if ( F_95 ( V_5 , V_129 -> V_119 ,
& V_5 -> V_199 , V_232 ) )
V_129 -> V_119 -> V_160 = 0 ;
}
}
static void F_108 ( struct V_115 * V_7 , struct V_145 * V_201 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
int V_171 ;
F_99 ( V_5 -> V_137 ) ;
F_99 ( V_5 -> V_146 != - 1 ) ;
if ( V_5 -> V_105 ) {
if ( V_5 -> V_189 < 3 ) {
F_76 ( V_5 , V_174 ) ;
F_76 ( V_5 , V_173 ) ;
V_5 -> V_189 += 1 ;
}
V_201 -> V_40 -> error = - V_234 ;
if ( V_201 -> V_119 )
V_201 -> V_119 -> error = - V_234 ;
V_201 -> V_40 -> V_235 = 0 ;
F_68 ( V_7 , V_201 ) ;
return;
} else if ( V_5 -> V_189 )
V_5 -> V_189 = 0 ;
F_109 ( V_5 -> V_129 != NULL ) ;
V_5 -> V_129 = V_201 ;
V_171 = F_105 ( V_5 , V_201 ) ;
if ( V_171 ) {
V_201 -> V_40 -> error = V_171 ;
if ( V_201 -> V_119 )
V_201 -> V_119 -> error = V_171 ;
V_5 -> V_129 = NULL ;
F_68 ( V_7 , V_201 ) ;
return;
}
F_61 ( V_5 , V_201 -> V_40 , V_201 -> V_119 ) ;
}
static void F_110 ( struct V_115 * V_7 , struct V_53 * V_54 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
int V_236 = 0 ;
F_85 ( V_5 -> V_2 ) ;
if ( V_54 -> V_96 != V_5 -> V_96 ) {
switch ( V_54 -> V_96 ) {
case V_97 :
F_13 ( V_5 ) . V_24 ( V_5 -> V_2 , V_5 -> V_28 ,
0 , 0 ) ;
break;
case V_237 :
F_13 ( V_5 ) . V_24 ( V_5 -> V_2 , V_5 -> V_28 ,
1 , V_54 -> V_14 ) ;
break;
case V_238 :
V_236 = 1 ;
break;
}
V_5 -> V_96 = V_54 -> V_96 ;
}
F_51 ( V_5 ) ;
if ( V_5 -> V_8 -> V_94 & V_95 ) {
if ( ( F_37 ( V_5 -> V_36 , V_74 ) & V_239 ) &&
( V_54 -> V_14 == V_240 ) &&
! V_5 -> V_17 ) {
if ( F_82 ( V_5 , V_54 -> V_14 ) != 0 )
F_39 ( F_40 ( V_5 -> V_7 ) ,
L_47 ) ;
}
}
F_46 ( V_5 ) ;
if ( V_236 )
F_55 ( V_5 ) ;
F_52 ( V_5 ) ;
F_111 ( V_5 -> V_2 ) ;
}
static int F_112 ( struct V_115 * V_7 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
if ( ! F_13 ( V_5 ) . V_31 )
return - V_193 ;
return F_13 ( V_5 ) . V_31 ( V_5 -> V_2 , V_5 -> V_28 ) ;
}
static int F_113 ( struct V_115 * V_7 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
if ( ! F_13 ( V_5 ) . V_33 )
return - V_193 ;
return F_13 ( V_5 ) . V_33 ( V_5 -> V_2 , 0 ) ;
}
static void F_114 ( struct V_115 * V_7 , struct V_241 * V_242 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
if ( F_13 ( V_5 ) . V_243 )
F_13 ( V_5 ) . V_243 ( V_242 ) ;
}
static void F_115 ( struct V_4 * V_5 )
{
T_2 V_88 , V_89 , V_244 ;
if ( V_5 -> V_8 -> V_94 & V_95 ) {
V_88 = V_100 ;
V_89 = V_101 | V_102 ;
} else {
V_88 = V_99 ;
V_89 = V_102 ;
}
V_244 = F_37 ( V_5 -> V_36 , V_74 ) & ~ V_245 ;
F_36 ( V_5 -> V_36 , V_74 , V_244 | V_88 ) ;
V_244 = F_37 ( V_5 -> V_36 , V_72 ) ;
F_36 ( V_5 -> V_36 , V_72 , V_244 | V_89 ) ;
F_81 ( V_5 ) ;
}
static int F_116 ( struct V_115 * V_7 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
F_85 ( V_5 -> V_2 ) ;
return 0 ;
}
static int F_117 ( struct V_115 * V_7 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
F_118 ( V_5 -> V_2 ) ;
F_111 ( V_5 -> V_2 ) ;
return 0 ;
}
static int F_119 ( struct V_246 * V_247 , void * V_119 )
{
struct V_115 * V_7 = V_247 -> V_248 ;
struct V_4 * V_5 = F_59 ( V_7 ) ;
F_120 ( V_247 , L_48 ,
V_7 -> V_249 , V_5 -> V_93 ) ;
F_85 ( V_5 -> V_2 ) ;
F_120 ( V_247 , L_49 ,
F_37 ( V_5 -> V_36 , V_77 ) ) ;
F_120 ( V_247 , L_50 ,
F_37 ( V_5 -> V_36 , V_74 ) ) ;
F_120 ( V_247 , L_51 ,
F_37 ( V_5 -> V_36 , V_37 ) ) ;
F_120 ( V_247 , L_52 ,
F_37 ( V_5 -> V_36 , V_52 ) ) ;
F_120 ( V_247 , L_53 ,
F_37 ( V_5 -> V_36 , V_51 ) ) ;
F_120 ( V_247 , L_54 ,
F_37 ( V_5 -> V_36 , V_72 ) ) ;
F_118 ( V_5 -> V_2 ) ;
F_111 ( V_5 -> V_2 ) ;
return 0 ;
}
static int F_121 ( struct V_250 * V_250 , struct V_251 * V_251 )
{
return F_122 ( V_251 , F_119 , V_250 -> V_252 ) ;
}
static void F_123 ( struct V_115 * V_7 )
{
if ( V_7 -> V_253 )
F_124 ( L_55 , V_254 , V_7 -> V_253 ,
V_7 , & V_255 ) ;
}
static void F_123 ( struct V_115 * V_7 )
{
}
static struct V_6 * F_125 ( struct V_1 * V_2 )
{
struct V_6 * V_8 ;
struct V_256 * V_257 = V_2 -> V_258 ;
T_2 V_79 , V_259 ;
int V_260 , V_261 ;
V_260 = F_126 ( V_257 , L_56 , 0 ) ;
V_261 = F_126 ( V_257 , L_57 , 0 ) ;
if ( V_260 == - V_262 || V_261 == - V_262 )
return F_127 ( - V_262 ) ;
V_8 = F_128 ( V_2 , sizeof( * V_8 ) , V_263 ) ;
if ( ! V_8 )
return NULL ;
if ( F_129 ( V_257 , L_58 , NULL ) )
V_8 -> V_94 |= V_95 ;
V_8 -> V_264 = 1 ;
V_8 -> V_9 [ 0 ] . V_10 = V_260 ;
V_8 -> V_9 [ 0 ] . V_11 = V_261 ;
if ( F_129 ( V_257 , L_59 , NULL ) ) {
V_8 -> V_9 [ 0 ] . V_265 = true ;
V_8 -> V_9 [ 0 ] . V_27 = true ;
}
F_130 ( V_257 , L_60 , & V_79 ) ;
if ( V_79 == 4 )
V_8 -> V_9 [ 0 ] . V_266 |= V_267 ;
else if ( V_79 == 8 )
V_8 -> V_9 [ 0 ] . V_266 |= V_268 ;
if ( F_129 ( V_257 , L_61 , NULL ) )
V_8 -> V_9 [ 0 ] . V_68 |= V_169 ;
if ( ! F_130 ( V_257 , L_62 , & V_259 ) )
V_8 -> V_259 = V_259 ;
if ( F_129 ( V_257 , L_63 , NULL ) )
V_8 -> V_9 [ 0 ] . V_68 |= V_69 ;
return V_8 ;
}
static inline struct V_6
* F_125 ( struct V_1 * V_2 )
{
return NULL ;
}
static int F_131 ( struct V_269 * V_270 )
{
struct V_6 * V_8 = V_270 -> V_2 . V_271 ;
struct V_115 * V_7 ;
struct V_4 * V_5 = NULL ;
struct V_272 * V_163 ;
int V_15 , V_106 ;
const struct V_273 * V_274 ;
T_6 V_275 ;
unsigned V_276 , V_277 ;
struct V_278 * V_278 ;
V_274 = F_132 ( F_133 ( V_279 ) , & V_270 -> V_2 ) ;
if ( V_274 ) {
V_8 = F_125 ( & V_270 -> V_2 ) ;
if ( F_19 ( V_8 ) )
return F_21 ( V_8 ) ;
if ( V_274 -> V_119 ) {
const T_1 * V_280 = V_274 -> V_119 ;
V_8 -> V_281 = * V_280 ;
}
}
if ( V_8 == NULL ) {
F_20 ( & V_270 -> V_2 , L_64 ) ;
return - V_282 ;
}
if ( V_8 -> V_264 == 0 ) {
F_20 ( & V_270 -> V_2 , L_65 ) ;
return - V_282 ;
}
V_163 = F_134 ( V_270 , V_283 , 0 ) ;
V_106 = F_135 ( V_270 , 0 ) ;
if ( V_163 == NULL || V_106 < 0 )
return - V_282 ;
V_163 = F_136 ( V_163 -> V_284 , F_137 ( V_163 ) , V_270 -> V_117 ) ;
if ( V_163 == NULL )
return - V_285 ;
V_15 = F_28 ( V_8 ) ;
if ( V_15 )
goto V_171;
V_7 = F_138 ( sizeof( struct V_4 ) , & V_270 -> V_2 ) ;
if ( ! V_7 ) {
V_15 = - V_286 ;
goto V_287;
}
V_5 = F_59 ( V_7 ) ;
V_5 -> V_7 = V_7 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_2 = & V_270 -> V_2 ;
V_5 -> V_42 = 1 ;
V_5 -> V_146 = - 1 ;
V_5 -> V_106 = V_106 ;
V_5 -> V_28 = 0 ;
V_5 -> V_210 = V_163 -> V_284 + V_8 -> V_281 ;
V_5 -> V_36 = F_139 ( V_5 -> V_210 , V_288 ) ;
V_5 -> V_96 = V_97 ;
V_5 -> V_199 . V_200 = 1 ;
F_140 ( V_270 , V_5 ) ;
V_7 -> V_289 = & V_290 ;
V_7 -> V_291 = V_292 ;
if ( V_8 -> V_259 > 0 )
V_7 -> V_293 = V_8 -> V_259 ;
else
V_7 -> V_293 = V_294 ;
F_141 ( & V_5 -> V_147 ) ;
V_5 -> V_56 = F_142 ( & V_270 -> V_2 , L_66 ) ;
if ( F_19 ( V_5 -> V_56 ) ) {
V_15 = F_21 ( V_5 -> V_56 ) ;
V_5 -> V_56 = NULL ;
goto V_295;
}
if ( V_5 -> V_8 -> V_94 & V_296 ) {
F_88 ( & V_270 -> V_2 , L_67 ) ;
V_7 -> V_297 |= V_298 ;
}
F_143 ( V_5 -> V_2 ) ;
F_85 ( V_5 -> V_2 ) ;
F_144 ( V_5 -> V_2 , V_299 ) ;
F_145 ( V_5 -> V_2 ) ;
F_54 ( V_5 ) ;
if ( V_5 -> V_2 -> V_258 && V_163 -> V_284 == 0x4809c000 )
V_5 -> V_17 = 1 ;
V_5 -> V_187 = F_142 ( & V_270 -> V_2 , L_68 ) ;
if ( F_19 ( V_5 -> V_187 ) ) {
V_5 -> V_187 = NULL ;
} else if ( F_86 ( V_5 -> V_187 ) != 0 ) {
F_96 ( F_40 ( V_5 -> V_7 ) , L_69 ) ;
F_146 ( V_5 -> V_187 ) ;
V_5 -> V_187 = NULL ;
}
V_7 -> V_300 = 1024 ;
V_7 -> V_301 = 512 ;
V_7 -> V_302 = 0xFFFF ;
V_7 -> V_303 = V_7 -> V_301 * V_7 -> V_302 ;
V_7 -> V_304 = V_7 -> V_303 ;
V_7 -> V_266 |= V_305 | V_306 |
V_307 | V_308 ;
V_7 -> V_266 |= F_13 ( V_5 ) . V_266 ;
if ( V_7 -> V_266 & V_268 )
V_7 -> V_266 |= V_267 ;
if ( F_13 ( V_5 ) . V_265 )
V_7 -> V_266 |= V_309 ;
V_7 -> V_310 = F_13 ( V_5 ) . V_310 ;
F_115 ( V_5 ) ;
if ( ! V_270 -> V_2 . V_258 ) {
V_163 = F_147 ( V_270 , V_311 , L_70 ) ;
if ( ! V_163 ) {
F_20 ( F_40 ( V_5 -> V_7 ) , L_71 ) ;
V_15 = - V_282 ;
goto V_312;
}
V_276 = V_163 -> V_284 ;
V_163 = F_147 ( V_270 , V_311 , L_72 ) ;
if ( ! V_163 ) {
F_20 ( F_40 ( V_5 -> V_7 ) , L_73 ) ;
V_15 = - V_282 ;
goto V_312;
}
V_277 = V_163 -> V_284 ;
}
F_148 ( V_275 ) ;
F_149 ( V_313 , V_275 ) ;
V_5 -> V_144 =
F_150 ( V_275 , V_314 ,
& V_277 , & V_270 -> V_2 , L_72 ) ;
if ( ! V_5 -> V_144 ) {
F_20 ( F_40 ( V_5 -> V_7 ) , L_74 , V_277 ) ;
V_15 = - V_282 ;
goto V_312;
}
V_5 -> V_143 =
F_150 ( V_275 , V_314 ,
& V_276 , & V_270 -> V_2 , L_70 ) ;
if ( ! V_5 -> V_143 ) {
F_20 ( F_40 ( V_5 -> V_7 ) , L_75 , V_276 ) ;
V_15 = - V_282 ;
goto V_312;
}
V_15 = F_151 ( V_5 -> V_106 , F_80 , 0 ,
F_62 ( V_7 ) , V_5 ) ;
if ( V_15 ) {
F_20 ( F_40 ( V_5 -> V_7 ) , L_76 ) ;
goto V_312;
}
if ( V_8 -> V_315 != NULL ) {
if ( V_8 -> V_315 ( & V_270 -> V_2 ) != 0 ) {
F_20 ( F_40 ( V_5 -> V_7 ) ,
L_77 ) ;
goto V_316;
}
}
if ( F_27 () && ! F_13 ( V_5 ) . V_24 ) {
V_15 = F_17 ( V_5 ) ;
if ( V_15 )
goto V_317;
V_5 -> V_318 = 1 ;
}
V_7 -> V_319 = F_13 ( V_5 ) . V_25 ;
if ( ( F_13 ( V_5 ) . V_12 ) ) {
V_15 = F_152 ( F_13 ( V_5 ) . V_12 ,
NULL ,
F_89 ,
V_320 | V_321 | V_322 ,
F_62 ( V_7 ) , V_5 ) ;
if ( V_15 ) {
F_20 ( F_40 ( V_5 -> V_7 ) ,
L_78 ) ;
goto V_323;
}
V_8 -> V_324 = F_6 ;
V_8 -> V_325 = F_8 ;
}
F_42 ( V_5 ) ;
V_278 = F_153 ( & V_270 -> V_2 ) ;
if ( F_19 ( V_278 ) )
F_96 ( & V_270 -> V_2 ,
L_79 ) ;
F_87 ( V_5 ) ;
F_154 ( V_7 ) ;
if ( F_13 ( V_5 ) . V_117 != NULL ) {
V_15 = F_155 ( & V_7 -> V_116 , & V_326 ) ;
if ( V_15 < 0 )
goto V_327;
}
if ( F_13 ( V_5 ) . V_12 && F_13 ( V_5 ) . V_30 ) {
V_15 = F_155 ( & V_7 -> V_116 ,
& V_328 ) ;
if ( V_15 < 0 )
goto V_327;
}
F_123 ( V_7 ) ;
F_118 ( V_5 -> V_2 ) ;
F_111 ( V_5 -> V_2 ) ;
return 0 ;
V_327:
F_156 ( V_7 ) ;
F_157 ( F_13 ( V_5 ) . V_12 , V_5 ) ;
V_323:
if ( V_5 -> V_318 )
F_25 ( V_5 ) ;
V_317:
if ( V_5 -> V_8 -> V_329 )
V_5 -> V_8 -> V_329 ( & V_270 -> V_2 ) ;
V_316:
F_157 ( V_5 -> V_106 , V_5 ) ;
V_312:
if ( V_5 -> V_143 )
F_158 ( V_5 -> V_143 ) ;
if ( V_5 -> V_144 )
F_158 ( V_5 -> V_144 ) ;
F_83 ( V_5 -> V_2 ) ;
F_159 ( V_5 -> V_2 ) ;
F_146 ( V_5 -> V_56 ) ;
if ( V_5 -> V_187 ) {
F_84 ( V_5 -> V_187 ) ;
F_146 ( V_5 -> V_187 ) ;
}
V_295:
F_160 ( V_5 -> V_36 ) ;
F_161 ( V_7 ) ;
V_287:
F_34 ( V_8 ) ;
V_171:
V_163 = F_134 ( V_270 , V_283 , 0 ) ;
if ( V_163 )
F_162 ( V_163 -> V_284 , F_137 ( V_163 ) ) ;
return V_15 ;
}
static int F_163 ( struct V_269 * V_270 )
{
struct V_4 * V_5 = F_11 ( V_270 ) ;
struct V_272 * V_163 ;
F_85 ( V_5 -> V_2 ) ;
F_156 ( V_5 -> V_7 ) ;
if ( V_5 -> V_318 )
F_25 ( V_5 ) ;
if ( V_5 -> V_8 -> V_329 )
V_5 -> V_8 -> V_329 ( & V_270 -> V_2 ) ;
F_157 ( V_5 -> V_106 , V_5 ) ;
if ( F_13 ( V_5 ) . V_12 )
F_157 ( F_13 ( V_5 ) . V_12 , V_5 ) ;
if ( V_5 -> V_143 )
F_158 ( V_5 -> V_143 ) ;
if ( V_5 -> V_144 )
F_158 ( V_5 -> V_144 ) ;
F_83 ( V_5 -> V_2 ) ;
F_159 ( V_5 -> V_2 ) ;
F_146 ( V_5 -> V_56 ) ;
if ( V_5 -> V_187 ) {
F_84 ( V_5 -> V_187 ) ;
F_146 ( V_5 -> V_187 ) ;
}
F_34 ( V_5 -> V_8 ) ;
F_160 ( V_5 -> V_36 ) ;
F_161 ( V_5 -> V_7 ) ;
V_163 = F_134 ( V_270 , V_283 , 0 ) ;
if ( V_163 )
F_162 ( V_163 -> V_284 , F_137 ( V_163 ) ) ;
return 0 ;
}
static int F_164 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_8 -> V_324 )
return V_5 -> V_8 -> V_324 ( V_2 , V_5 -> V_28 ) ;
return 0 ;
}
static void F_165 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_8 -> V_325 )
V_5 -> V_8 -> V_325 ( V_2 , V_5 -> V_28 ) ;
}
static int F_166 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 )
return 0 ;
F_85 ( V_5 -> V_2 ) ;
if ( ! ( V_5 -> V_7 -> V_330 & V_331 ) ) {
F_42 ( V_5 ) ;
F_36 ( V_5 -> V_36 , V_74 ,
F_37 ( V_5 -> V_36 , V_74 ) & ~ V_103 ) ;
}
if ( V_5 -> V_187 )
F_84 ( V_5 -> V_187 ) ;
F_83 ( V_5 -> V_2 ) ;
return 0 ;
}
static int F_167 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 )
return 0 ;
F_85 ( V_5 -> V_2 ) ;
if ( V_5 -> V_187 )
F_86 ( V_5 -> V_187 ) ;
if ( ! ( V_5 -> V_7 -> V_330 & V_331 ) )
F_115 ( V_5 ) ;
F_87 ( V_5 ) ;
F_118 ( V_5 -> V_2 ) ;
F_111 ( V_5 -> V_2 ) ;
return 0 ;
}
static int F_168 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
V_5 = F_11 ( F_12 ( V_2 ) ) ;
F_54 ( V_5 ) ;
F_39 ( V_2 , L_80 ) ;
return 0 ;
}
static int F_169 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
V_5 = F_11 ( F_12 ( V_2 ) ) ;
F_53 ( V_5 ) ;
F_39 ( V_2 , L_81 ) ;
return 0 ;
}
