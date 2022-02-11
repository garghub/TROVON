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
if ( V_2 -> V_17 && ! V_14 )
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
if ( V_55 > 250 )
V_55 = 250 ;
}
return V_55 ;
}
static void F_46 ( struct V_4 * V_5 )
{
struct V_53 * V_54 = & V_5 -> V_7 -> V_54 ;
unsigned long V_57 ;
unsigned long V_58 ;
unsigned long V_59 ;
F_47 ( F_40 ( V_5 -> V_7 ) , L_8 , V_54 -> clock ) ;
F_38 ( V_5 ) ;
V_57 = F_37 ( V_5 -> V_36 , V_37 ) ;
V_57 = V_57 & ~ ( V_60 | V_61 ) ;
V_59 = F_43 ( V_5 , V_54 ) ;
V_57 = V_57 | ( V_59 << 6 ) | ( V_62 << 16 ) ;
F_36 ( V_5 -> V_36 , V_37 , V_57 ) ;
F_36 ( V_5 -> V_36 , V_37 ,
F_37 ( V_5 -> V_36 , V_37 ) | V_63 ) ;
V_58 = V_64 + F_48 ( V_65 ) ;
while ( ( F_37 ( V_5 -> V_36 , V_37 ) & V_66 ) != V_66
&& F_49 ( V_64 , V_58 ) )
F_50 () ;
if ( ( F_13 ( V_5 ) . V_67 & V_68 ) &&
( V_54 -> V_69 != V_70 ) &&
( ( F_37 ( V_5 -> V_36 , V_71 ) & V_72 ) == V_72 ) ) {
V_57 = F_37 ( V_5 -> V_36 , V_73 ) ;
if ( V_59 && ( F_45 ( V_5 -> V_56 ) / V_59 ) > 25000000 )
V_57 |= V_74 ;
else
V_57 &= ~ V_74 ;
F_36 ( V_5 -> V_36 , V_73 , V_57 ) ;
}
F_35 ( V_5 ) ;
}
static void F_51 ( struct V_4 * V_5 )
{
struct V_53 * V_54 = & V_5 -> V_7 -> V_54 ;
T_2 V_75 ;
V_75 = F_37 ( V_5 -> V_36 , V_76 ) ;
if ( V_54 -> V_69 == V_70 )
V_75 |= V_77 ;
else
V_75 &= ~ V_77 ;
switch ( V_54 -> V_78 ) {
case V_79 :
F_36 ( V_5 -> V_36 , V_76 , V_75 | V_80 ) ;
break;
case V_81 :
F_36 ( V_5 -> V_36 , V_76 , V_75 & ~ V_80 ) ;
F_36 ( V_5 -> V_36 , V_73 ,
F_37 ( V_5 -> V_36 , V_73 ) | V_82 ) ;
break;
case V_83 :
F_36 ( V_5 -> V_36 , V_76 , V_75 & ~ V_80 ) ;
F_36 ( V_5 -> V_36 , V_73 ,
F_37 ( V_5 -> V_36 , V_73 ) & ~ V_82 ) ;
break;
}
}
static void F_52 ( struct V_4 * V_5 )
{
struct V_53 * V_54 = & V_5 -> V_7 -> V_54 ;
T_2 V_75 ;
V_75 = F_37 ( V_5 -> V_36 , V_76 ) ;
if ( V_54 -> V_84 == V_85 )
F_36 ( V_5 -> V_36 , V_76 , V_75 | V_86 ) ;
else
F_36 ( V_5 -> V_36 , V_76 , V_75 & ~ V_86 ) ;
}
static int F_53 ( struct V_4 * V_5 )
{
struct V_53 * V_54 = & V_5 -> V_7 -> V_54 ;
struct V_6 * V_8 = V_5 -> V_8 ;
int V_87 = 0 ;
T_2 V_88 , V_89 ;
unsigned long V_58 ;
if ( V_8 -> V_90 ) {
V_87 = V_8 -> V_90 ( V_5 -> V_2 ) ;
if ( V_87 < 0 )
return 1 ;
}
F_39 ( F_40 ( V_5 -> V_7 ) , L_9 ,
V_87 == V_5 -> V_87 ? L_10 : L_11 ) ;
if ( V_5 -> V_87 == V_87 )
return 1 ;
if ( ! F_37 ( V_5 -> V_36 , V_91 ) & V_92 )
return 1 ;
if ( V_5 -> V_8 -> V_93 & V_94 ) {
if ( V_5 -> V_95 != V_96 &&
( 1 << V_54 -> V_14 ) <= V_97 )
V_88 = V_98 ;
else
V_88 = V_99 ;
V_89 = V_100 | V_101 ;
} else {
V_88 = V_98 ;
V_89 = V_101 ;
}
F_36 ( V_5 -> V_36 , V_73 ,
F_37 ( V_5 -> V_36 , V_73 ) | V_88 ) ;
F_36 ( V_5 -> V_36 , V_71 ,
F_37 ( V_5 -> V_36 , V_71 ) | V_89 ) ;
F_36 ( V_5 -> V_36 , V_73 ,
F_37 ( V_5 -> V_36 , V_73 ) | V_102 ) ;
V_58 = V_64 + F_48 ( V_65 ) ;
while ( ( F_37 ( V_5 -> V_36 , V_73 ) & V_102 ) != V_102
&& F_49 ( V_64 , V_58 ) )
;
F_42 ( V_5 ) ;
if ( V_5 -> V_95 == V_96 )
goto V_103;
F_51 ( V_5 ) ;
F_46 ( V_5 ) ;
F_52 ( V_5 ) ;
V_103:
V_5 -> V_87 = V_87 ;
F_39 ( F_40 ( V_5 -> V_7 ) , L_12 ) ;
return 0 ;
}
static void F_54 ( struct V_4 * V_5 )
{
struct V_6 * V_8 = V_5 -> V_8 ;
int V_87 ;
if ( V_8 -> V_90 ) {
V_87 = V_8 -> V_90 ( V_5 -> V_2 ) ;
if ( V_87 < 0 )
return;
V_5 -> V_87 = V_87 ;
}
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
unsigned long V_58 ;
if ( V_5 -> V_104 )
return;
F_7 ( V_5 -> V_105 ) ;
F_36 ( V_5 -> V_36 , V_52 , V_43 ) ;
F_36 ( V_5 -> V_36 , V_76 ,
F_37 ( V_5 -> V_36 , V_76 ) | V_106 ) ;
F_36 ( V_5 -> V_36 , V_107 , V_108 ) ;
V_58 = V_64 + F_48 ( V_65 ) ;
while ( ( V_22 != V_109 ) && F_49 ( V_64 , V_58 ) )
V_22 = F_37 ( V_5 -> V_36 , V_49 ) & V_109 ;
F_36 ( V_5 -> V_36 , V_76 ,
F_37 ( V_5 -> V_36 , V_76 ) & ~ V_106 ) ;
F_36 ( V_5 -> V_36 , V_49 , V_50 ) ;
F_37 ( V_5 -> V_36 , V_49 ) ;
F_9 ( V_5 -> V_105 ) ;
}
static inline
int F_56 ( struct V_4 * V_5 )
{
int V_110 = 1 ;
if ( F_13 ( V_5 ) . V_30 )
V_110 = F_13 ( V_5 ) . V_30 ( V_5 -> V_2 , V_5 -> V_28 ) ;
return V_110 ;
}
static T_3
F_57 ( struct V_1 * V_2 , struct V_111 * V_112 ,
char * V_113 )
{
struct V_114 * V_7 = F_58 ( V_2 , struct V_114 , V_115 ) ;
struct V_4 * V_5 = F_59 ( V_7 ) ;
return sprintf ( V_113 , L_13 ,
F_56 ( V_5 ) ? L_14 : L_15 ) ;
}
static T_3
F_60 ( struct V_1 * V_2 , struct V_111 * V_112 ,
char * V_113 )
{
struct V_114 * V_7 = F_58 ( V_2 , struct V_114 , V_115 ) ;
struct V_4 * V_5 = F_59 ( V_7 ) ;
return sprintf ( V_113 , L_13 , F_13 ( V_5 ) . V_116 ) ;
}
static void
F_61 ( struct V_4 * V_5 , struct V_39 * V_40 ,
struct V_117 * V_118 )
{
int V_119 = 0 , V_120 = 0 , V_121 = 0 ;
F_47 ( F_40 ( V_5 -> V_7 ) , L_16 ,
F_62 ( V_5 -> V_7 ) , V_40 -> V_46 , V_40 -> V_122 ) ;
V_5 -> V_40 = V_40 ;
F_41 ( V_5 , V_40 ) ;
V_5 -> V_123 = 0 ;
if ( V_40 -> V_124 & V_125 ) {
if ( V_40 -> V_124 & V_126 )
V_120 = 1 ;
else if ( V_40 -> V_124 & V_127 ) {
V_120 = 3 ;
V_5 -> V_123 = 1 ;
} else
V_120 = 2 ;
}
if ( V_40 == V_5 -> V_128 -> V_129 )
V_121 = 0x3 ;
V_119 = ( V_40 -> V_46 << 24 ) | ( V_120 << 16 ) | ( V_121 << 22 ) ;
if ( V_118 ) {
V_119 |= V_130 | V_131 | V_132 ;
if ( V_118 -> V_124 & V_133 )
V_119 |= V_134 ;
else
V_119 &= ~ ( V_134 ) ;
}
if ( V_5 -> V_42 )
V_119 |= V_135 ;
V_5 -> V_136 = 1 ;
F_36 ( V_5 -> V_36 , V_137 , V_40 -> V_122 ) ;
F_36 ( V_5 -> V_36 , V_107 , V_119 ) ;
}
static int
F_63 ( struct V_4 * V_5 , struct V_117 * V_118 )
{
if ( V_118 -> V_124 & V_138 )
return V_139 ;
else
return V_140 ;
}
static struct V_141 * F_64 ( struct V_4 * V_5 ,
struct V_117 * V_118 )
{
return V_118 -> V_124 & V_138 ? V_5 -> V_142 : V_5 -> V_143 ;
}
static void F_65 ( struct V_4 * V_5 , struct V_144 * V_128 )
{
int V_145 ;
unsigned long V_124 ;
F_66 ( & V_5 -> V_146 , V_124 ) ;
V_5 -> V_136 = 0 ;
V_145 = V_5 -> V_145 ;
F_67 ( & V_5 -> V_146 , V_124 ) ;
F_42 ( V_5 ) ;
if ( V_128 -> V_118 && V_5 -> V_42 && V_145 != - 1 )
return;
V_5 -> V_128 = NULL ;
F_68 ( V_5 -> V_7 , V_128 ) ;
}
static void
F_69 ( struct V_4 * V_5 , struct V_117 * V_118 )
{
if ( ! V_118 ) {
struct V_144 * V_128 = V_5 -> V_128 ;
if ( V_5 -> V_40 && V_5 -> V_40 -> V_46 == 6 &&
V_5 -> V_123 ) {
V_5 -> V_123 = 0 ;
return;
}
F_65 ( V_5 , V_128 ) ;
return;
}
V_5 -> V_118 = NULL ;
if ( ! V_118 -> error )
V_118 -> V_147 += V_118 -> V_148 * ( V_118 -> V_149 ) ;
else
V_118 -> V_147 = 0 ;
if ( ! V_118 -> V_129 ) {
F_65 ( V_5 , V_118 -> V_128 ) ;
return;
}
F_61 ( V_5 , V_118 -> V_129 , NULL ) ;
}
static void
F_70 ( struct V_4 * V_5 , struct V_39 * V_40 )
{
V_5 -> V_40 = NULL ;
if ( V_40 -> V_124 & V_125 ) {
if ( V_40 -> V_124 & V_126 ) {
V_40 -> V_150 [ 3 ] = F_37 ( V_5 -> V_36 , V_151 ) ;
V_40 -> V_150 [ 2 ] = F_37 ( V_5 -> V_36 , V_152 ) ;
V_40 -> V_150 [ 1 ] = F_37 ( V_5 -> V_36 , V_153 ) ;
V_40 -> V_150 [ 0 ] = F_37 ( V_5 -> V_36 , V_154 ) ;
} else {
V_40 -> V_150 [ 0 ] = F_37 ( V_5 -> V_36 , V_151 ) ;
}
}
if ( ( V_5 -> V_118 == NULL && ! V_5 -> V_123 ) || V_40 -> error )
F_65 ( V_5 , V_40 -> V_128 ) ;
}
static void F_71 ( struct V_4 * V_5 , int V_155 )
{
int V_145 ;
unsigned long V_124 ;
V_5 -> V_118 -> error = V_155 ;
F_66 ( & V_5 -> V_146 , V_124 ) ;
V_145 = V_5 -> V_145 ;
V_5 -> V_145 = - 1 ;
F_67 ( & V_5 -> V_146 , V_124 ) ;
if ( V_5 -> V_42 && V_145 != - 1 ) {
struct V_141 * V_156 = F_64 ( V_5 , V_5 -> V_118 ) ;
F_72 ( V_156 ) ;
F_73 ( V_156 -> V_1 -> V_2 ,
V_5 -> V_118 -> V_157 , V_5 -> V_118 -> V_158 ,
F_63 ( V_5 , V_5 -> V_118 ) ) ;
V_5 -> V_118 -> V_159 = 0 ;
}
V_5 -> V_118 = NULL ;
}
static void F_74 ( struct V_4 * V_5 , T_2 V_160 )
{
static const char * V_161 [] = {
L_17 , L_18 , L_19 , L_20 , L_21 , L_22 , L_20 , L_20 ,
L_23 , L_24 , L_20 , L_20 , L_20 , L_20 , L_20 , L_25 ,
L_26 , L_27 , L_28 , L_29 , L_30 , L_31 , L_32 , L_20 ,
L_33 , L_20 , L_20 , L_20 , L_34 , L_35 , L_20 , L_20
} ;
char V_162 [ 256 ] ;
char * V_113 = V_162 ;
int V_163 , V_164 ;
V_163 = sprintf ( V_113 , L_36 , V_160 ) ;
V_113 += V_163 ;
for ( V_164 = 0 ; V_164 < F_75 ( V_161 ) ; V_164 ++ )
if ( V_160 & ( 1 << V_164 ) ) {
V_163 = sprintf ( V_113 , L_37 , V_161 [ V_164 ] ) ;
V_113 += V_163 ;
}
F_47 ( F_40 ( V_5 -> V_7 ) , L_13 , V_162 ) ;
}
static inline void F_74 ( struct V_4 * V_5 ,
T_2 V_160 )
{
}
static inline void F_76 ( struct V_4 * V_5 ,
unsigned long V_165 )
{
unsigned long V_164 = 0 ;
unsigned long V_166 = ( V_167 *
F_48 ( V_65 ) ) ;
F_36 ( V_5 -> V_36 , V_37 ,
F_37 ( V_5 -> V_36 , V_37 ) | V_165 ) ;
if ( F_13 ( V_5 ) . V_67 & V_168 ) {
while ( ( ! ( F_37 ( V_5 -> V_36 , V_37 ) & V_165 ) )
&& ( V_164 ++ < V_166 ) )
F_50 () ;
}
V_164 = 0 ;
while ( ( F_37 ( V_5 -> V_36 , V_37 ) & V_165 ) &&
( V_164 ++ < V_166 ) )
F_50 () ;
if ( F_37 ( V_5 -> V_36 , V_37 ) & V_165 )
F_20 ( F_40 ( V_5 -> V_7 ) ,
L_38 ,
V_169 ) ;
}
static void F_77 ( struct V_4 * V_5 ,
int V_170 , int V_171 )
{
if ( V_171 ) {
F_76 ( V_5 , V_172 ) ;
if ( V_5 -> V_40 )
V_5 -> V_40 -> error = V_170 ;
}
if ( V_5 -> V_118 ) {
F_76 ( V_5 , V_173 ) ;
F_71 ( V_5 , V_170 ) ;
} else if ( V_5 -> V_128 && V_5 -> V_128 -> V_40 )
V_5 -> V_128 -> V_40 -> error = V_170 ;
}
static void F_78 ( struct V_4 * V_5 , int V_160 )
{
struct V_117 * V_118 ;
int V_171 = 0 , V_174 = 0 ;
V_118 = V_5 -> V_118 ;
F_47 ( F_40 ( V_5 -> V_7 ) , L_39 , V_160 ) ;
if ( V_160 & V_175 ) {
F_74 ( V_5 , V_160 ) ;
if ( V_160 & ( V_176 | V_177 ) )
V_171 = 1 ;
if ( V_160 & ( V_176 | V_48 ) )
F_77 ( V_5 , - V_178 , V_171 ) ;
else if ( V_160 & ( V_177 | V_179 ) )
F_77 ( V_5 , - V_180 , V_171 ) ;
if ( V_5 -> V_118 || V_5 -> V_123 ) {
V_174 = ! V_171 ;
V_5 -> V_123 = 0 ;
}
}
if ( V_171 || ( ( V_160 & V_109 ) && V_5 -> V_40 ) )
F_70 ( V_5 , V_5 -> V_40 ) ;
if ( ( V_174 || ( V_160 & V_181 ) ) && V_5 -> V_128 )
F_69 ( V_5 , V_118 ) ;
}
static T_4 F_79 ( int V_105 , void * V_182 )
{
struct V_4 * V_5 = V_182 ;
int V_160 ;
V_160 = F_37 ( V_5 -> V_36 , V_49 ) ;
while ( V_160 & V_43 && V_5 -> V_136 ) {
F_78 ( V_5 , V_160 ) ;
F_36 ( V_5 -> V_36 , V_49 , V_160 ) ;
V_160 = F_37 ( V_5 -> V_36 , V_49 ) ;
}
return V_183 ;
}
static void F_80 ( struct V_4 * V_5 )
{
unsigned long V_164 ;
F_36 ( V_5 -> V_36 , V_73 ,
F_37 ( V_5 -> V_36 , V_73 ) | V_102 ) ;
for ( V_164 = 0 ; V_164 < V_167 ; V_164 ++ ) {
if ( F_37 ( V_5 -> V_36 , V_73 ) & V_102 )
break;
F_50 () ;
}
}
static int F_81 ( struct V_4 * V_5 , int V_14 )
{
T_2 V_184 = 0 ;
int V_15 ;
F_82 ( V_5 -> V_2 ) ;
if ( V_5 -> V_185 )
F_83 ( V_5 -> V_185 ) ;
V_15 = F_13 ( V_5 ) . V_24 ( V_5 -> V_2 , V_5 -> V_28 , 0 , 0 ) ;
if ( ! V_15 )
V_15 = F_13 ( V_5 ) . V_24 ( V_5 -> V_2 , V_5 -> V_28 , 1 ,
V_14 ) ;
F_84 ( V_5 -> V_2 ) ;
if ( V_5 -> V_185 )
F_85 ( V_5 -> V_185 ) ;
if ( V_15 != 0 )
goto V_170;
F_36 ( V_5 -> V_36 , V_73 ,
F_37 ( V_5 -> V_36 , V_73 ) & V_186 ) ;
V_184 = F_37 ( V_5 -> V_36 , V_73 ) ;
if ( ( 1 << V_14 ) <= V_97 )
V_184 |= V_98 ;
else
V_184 |= V_99 ;
F_36 ( V_5 -> V_36 , V_73 , V_184 ) ;
F_80 ( V_5 ) ;
return 0 ;
V_170:
F_20 ( F_40 ( V_5 -> V_7 ) , L_40 ) ;
return V_15 ;
}
static void F_86 ( struct V_4 * V_5 )
{
if ( ! F_13 ( V_5 ) . V_30 )
return;
V_5 -> V_187 = 0 ;
if ( F_13 ( V_5 ) . V_30 ( V_5 -> V_2 , V_5 -> V_28 ) ) {
if ( V_5 -> V_104 ) {
F_87 ( V_5 -> V_2 , L_41
L_42 ,
F_62 ( V_5 -> V_7 ) ) ;
V_5 -> V_104 = 0 ;
}
} else {
if ( ! V_5 -> V_104 ) {
F_87 ( V_5 -> V_2 , L_43
L_44 ,
F_62 ( V_5 -> V_7 ) ) ;
V_5 -> V_104 = 1 ;
}
}
}
static T_4 F_88 ( int V_105 , void * V_182 )
{
struct V_4 * V_5 = V_182 ;
struct V_188 * V_3 = & F_13 ( V_5 ) ;
int V_189 ;
if ( V_5 -> V_190 )
return V_183 ;
F_89 ( & V_5 -> V_7 -> V_115 . V_191 , NULL , L_45 ) ;
if ( V_3 -> V_31 )
V_189 = V_3 -> V_31 ( V_5 -> V_2 , V_5 -> V_28 ) ;
else {
F_86 ( V_5 ) ;
V_189 = - V_192 ;
}
if ( V_189 )
F_90 ( V_5 -> V_7 , ( V_193 * 200 ) / 1000 ) ;
else
F_90 ( V_5 -> V_7 , ( V_193 * 50 ) / 1000 ) ;
return V_183 ;
}
static void F_91 ( void * V_194 )
{
struct V_4 * V_5 = V_194 ;
struct V_141 * V_156 ;
struct V_117 * V_118 ;
int V_136 ;
F_92 ( & V_5 -> V_146 ) ;
if ( V_5 -> V_145 < 0 ) {
F_93 ( & V_5 -> V_146 ) ;
return;
}
V_118 = V_5 -> V_128 -> V_118 ;
V_156 = F_64 ( V_5 , V_118 ) ;
if ( ! V_118 -> V_159 )
F_73 ( V_156 -> V_1 -> V_2 ,
V_118 -> V_157 , V_118 -> V_158 ,
F_63 ( V_5 , V_118 ) ) ;
V_136 = V_5 -> V_136 ;
V_5 -> V_145 = - 1 ;
F_93 ( & V_5 -> V_146 ) ;
if ( ! V_136 ) {
struct V_144 * V_128 = V_5 -> V_128 ;
V_5 -> V_128 = NULL ;
F_68 ( V_5 -> V_7 , V_128 ) ;
}
}
static int F_94 ( struct V_4 * V_5 ,
struct V_117 * V_118 ,
struct V_195 * V_196 ,
struct V_141 * V_156 )
{
int V_197 ;
if ( ! V_196 && V_118 -> V_159 &&
V_118 -> V_159 != V_5 -> V_198 . V_199 ) {
F_95 ( V_5 -> V_2 , L_46
L_47 ,
V_169 , V_118 -> V_159 , V_5 -> V_198 . V_199 ) ;
V_118 -> V_159 = 0 ;
}
if ( V_196 ||
( ! V_196 && V_118 -> V_159 != V_5 -> V_198 . V_199 ) ) {
V_197 = F_96 ( V_156 -> V_1 -> V_2 , V_118 -> V_157 , V_118 -> V_158 ,
F_63 ( V_5 , V_118 ) ) ;
} else {
V_197 = V_5 -> V_198 . V_197 ;
V_5 -> V_198 . V_197 = 0 ;
}
if ( V_197 == 0 )
return - V_26 ;
if ( V_196 ) {
V_196 -> V_197 = V_197 ;
V_118 -> V_159 = ++ V_196 -> V_199 < 0 ? 1 : V_196 -> V_199 ;
} else
V_5 -> V_197 = V_197 ;
return 0 ;
}
static int F_97 ( struct V_4 * V_5 ,
struct V_144 * V_200 )
{
struct V_201 V_202 ;
struct V_203 * V_204 ;
int V_15 = 0 , V_164 ;
struct V_117 * V_118 = V_200 -> V_118 ;
struct V_141 * V_156 ;
for ( V_164 = 0 ; V_164 < V_118 -> V_158 ; V_164 ++ ) {
struct V_205 * V_206 ;
V_206 = V_118 -> V_157 + V_164 ;
if ( V_206 -> V_207 % V_118 -> V_149 )
return - V_26 ;
}
if ( ( V_118 -> V_149 % 4 ) != 0 )
return - V_26 ;
F_98 ( V_5 -> V_145 != - 1 ) ;
V_156 = F_64 ( V_5 , V_118 ) ;
V_202 . V_208 = V_5 -> V_209 + V_210 ;
V_202 . V_211 = V_5 -> V_209 + V_210 ;
V_202 . V_212 = V_213 ;
V_202 . V_214 = V_213 ;
V_202 . V_215 = V_118 -> V_149 / 4 ;
V_202 . V_216 = V_118 -> V_149 / 4 ;
V_15 = F_99 ( V_156 , & V_202 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_94 ( V_5 , V_118 , NULL , V_156 ) ;
if ( V_15 )
return V_15 ;
V_204 = F_100 ( V_156 , V_118 -> V_157 , V_118 -> V_158 ,
V_118 -> V_124 & V_138 ? V_217 : V_218 ,
V_219 | V_220 ) ;
if ( ! V_204 ) {
F_20 ( F_40 ( V_5 -> V_7 ) , L_48 ) ;
return - 1 ;
}
V_204 -> V_221 = F_91 ;
V_204 -> V_222 = V_5 ;
F_101 ( V_204 ) ;
V_5 -> V_145 = 1 ;
F_102 ( V_156 ) ;
return 0 ;
}
static void F_103 ( struct V_4 * V_5 ,
unsigned int V_223 ,
unsigned int V_224 )
{
unsigned int V_58 , V_225 ;
T_5 V_22 , V_226 , V_227 = 0 ;
V_22 = F_37 ( V_5 -> V_36 , V_37 ) ;
V_226 = ( V_22 & V_60 ) >> V_228 ;
if ( V_226 == 0 )
V_226 = 1 ;
V_225 = 1000000000 / ( F_45 ( V_5 -> V_56 ) / V_226 ) ;
V_58 = V_223 / V_225 ;
V_58 += V_224 ;
if ( V_58 ) {
while ( ( V_58 & 0x80000000 ) == 0 ) {
V_227 += 1 ;
V_58 <<= 1 ;
}
V_227 = 31 - V_227 ;
V_58 <<= 1 ;
if ( V_58 && V_227 )
V_227 += 1 ;
if ( V_227 >= 13 )
V_227 -= 13 ;
else
V_227 = 0 ;
if ( V_227 > 14 )
V_227 = 14 ;
}
V_22 &= ~ V_61 ;
V_22 |= V_227 << V_229 ;
F_36 ( V_5 -> V_36 , V_37 , V_22 ) ;
}
static int
F_104 ( struct V_4 * V_5 , struct V_144 * V_200 )
{
int V_15 ;
V_5 -> V_118 = V_200 -> V_118 ;
if ( V_200 -> V_118 == NULL ) {
F_36 ( V_5 -> V_36 , V_230 , 0 ) ;
if ( V_200 -> V_40 -> V_124 & V_127 )
F_103 ( V_5 , 100000000U , 0 ) ;
return 0 ;
}
F_36 ( V_5 -> V_36 , V_230 , ( V_200 -> V_118 -> V_149 )
| ( V_200 -> V_118 -> V_148 << 16 ) ) ;
F_103 ( V_5 , V_200 -> V_118 -> V_223 , V_200 -> V_118 -> V_224 ) ;
if ( V_5 -> V_42 ) {
V_15 = F_97 ( V_5 , V_200 ) ;
if ( V_15 != 0 ) {
F_20 ( F_40 ( V_5 -> V_7 ) , L_49 ) ;
return V_15 ;
}
}
return 0 ;
}
static void F_105 ( struct V_114 * V_7 , struct V_144 * V_128 ,
int V_170 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
struct V_117 * V_118 = V_128 -> V_118 ;
if ( V_5 -> V_42 && V_118 -> V_159 ) {
struct V_141 * V_231 = F_64 ( V_5 , V_118 ) ;
F_73 ( V_231 -> V_1 -> V_2 , V_118 -> V_157 , V_118 -> V_158 ,
F_63 ( V_5 , V_118 ) ) ;
V_118 -> V_159 = 0 ;
}
}
static void F_106 ( struct V_114 * V_7 , struct V_144 * V_128 ,
bool V_232 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
if ( V_128 -> V_118 -> V_159 ) {
V_128 -> V_118 -> V_159 = 0 ;
return ;
}
if ( V_5 -> V_42 ) {
struct V_141 * V_231 = F_64 ( V_5 , V_128 -> V_118 ) ;
if ( F_94 ( V_5 , V_128 -> V_118 ,
& V_5 -> V_198 , V_231 ) )
V_128 -> V_118 -> V_159 = 0 ;
}
}
static void F_107 ( struct V_114 * V_7 , struct V_144 * V_200 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
int V_170 ;
F_98 ( V_5 -> V_136 ) ;
F_98 ( V_5 -> V_145 != - 1 ) ;
if ( V_5 -> V_104 ) {
if ( V_5 -> V_187 < 3 ) {
F_76 ( V_5 , V_173 ) ;
F_76 ( V_5 , V_172 ) ;
V_5 -> V_187 += 1 ;
}
V_200 -> V_40 -> error = - V_233 ;
if ( V_200 -> V_118 )
V_200 -> V_118 -> error = - V_233 ;
V_200 -> V_40 -> V_234 = 0 ;
F_68 ( V_7 , V_200 ) ;
return;
} else if ( V_5 -> V_187 )
V_5 -> V_187 = 0 ;
F_108 ( V_5 -> V_128 != NULL ) ;
V_5 -> V_128 = V_200 ;
V_170 = F_104 ( V_5 , V_200 ) ;
if ( V_170 ) {
V_200 -> V_40 -> error = V_170 ;
if ( V_200 -> V_118 )
V_200 -> V_118 -> error = V_170 ;
V_5 -> V_128 = NULL ;
F_68 ( V_7 , V_200 ) ;
return;
}
F_61 ( V_5 , V_200 -> V_40 , V_200 -> V_118 ) ;
}
static void F_109 ( struct V_114 * V_7 , struct V_53 * V_54 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
int V_235 = 0 ;
F_84 ( V_5 -> V_2 ) ;
if ( V_54 -> V_95 != V_5 -> V_95 ) {
switch ( V_54 -> V_95 ) {
case V_96 :
F_13 ( V_5 ) . V_24 ( V_5 -> V_2 , V_5 -> V_28 ,
0 , 0 ) ;
break;
case V_236 :
F_13 ( V_5 ) . V_24 ( V_5 -> V_2 , V_5 -> V_28 ,
1 , V_54 -> V_14 ) ;
break;
case V_237 :
V_235 = 1 ;
break;
}
V_5 -> V_95 = V_54 -> V_95 ;
}
F_51 ( V_5 ) ;
if ( V_5 -> V_8 -> V_93 & V_94 ) {
if ( ( F_37 ( V_5 -> V_36 , V_73 ) & V_238 ) &&
( V_54 -> V_14 == V_239 ) &&
! V_5 -> V_2 -> V_17 ) {
if ( F_81 ( V_5 , V_54 -> V_14 ) != 0 )
F_39 ( F_40 ( V_5 -> V_7 ) ,
L_50 ) ;
}
}
F_46 ( V_5 ) ;
if ( V_235 )
F_55 ( V_5 ) ;
F_52 ( V_5 ) ;
F_110 ( V_5 -> V_2 ) ;
}
static int F_111 ( struct V_114 * V_7 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
if ( ! F_13 ( V_5 ) . V_31 )
return - V_192 ;
return F_13 ( V_5 ) . V_31 ( V_5 -> V_2 , V_5 -> V_28 ) ;
}
static int F_112 ( struct V_114 * V_7 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
if ( ! F_13 ( V_5 ) . V_33 )
return - V_192 ;
return F_13 ( V_5 ) . V_33 ( V_5 -> V_2 , 0 ) ;
}
static void F_113 ( struct V_114 * V_7 , struct V_240 * V_241 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
if ( F_13 ( V_5 ) . V_242 )
F_13 ( V_5 ) . V_242 ( V_241 ) ;
}
static void F_114 ( struct V_4 * V_5 )
{
T_2 V_88 , V_89 , V_243 ;
if ( V_5 -> V_8 -> V_93 & V_94 ) {
V_88 = V_99 ;
V_89 = V_100 | V_101 ;
} else {
V_88 = V_98 ;
V_89 = V_101 ;
}
V_243 = F_37 ( V_5 -> V_36 , V_73 ) & ~ V_244 ;
F_36 ( V_5 -> V_36 , V_73 , V_243 | V_88 ) ;
V_243 = F_37 ( V_5 -> V_36 , V_71 ) ;
F_36 ( V_5 -> V_36 , V_71 , V_243 | V_89 ) ;
F_80 ( V_5 ) ;
}
static int F_115 ( struct V_114 * V_7 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
F_84 ( V_5 -> V_2 ) ;
return 0 ;
}
static int F_116 ( struct V_114 * V_7 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
F_117 ( V_5 -> V_2 ) ;
F_110 ( V_5 -> V_2 ) ;
return 0 ;
}
static int F_118 ( struct V_245 * V_246 , void * V_118 )
{
struct V_114 * V_7 = V_246 -> V_247 ;
struct V_4 * V_5 = F_59 ( V_7 ) ;
int V_87 = 0 ;
if ( V_5 -> V_8 -> V_90 )
V_87 = V_5 -> V_8 -> V_90 ( V_5 -> V_2 ) ;
F_119 ( V_246 , L_51 ,
V_7 -> V_248 , V_5 -> V_87 , V_87 ) ;
if ( V_5 -> V_190 ) {
F_119 ( V_246 , L_52 ) ;
return 0 ;
}
F_84 ( V_5 -> V_2 ) ;
F_119 ( V_246 , L_53 ,
F_37 ( V_5 -> V_36 , V_76 ) ) ;
F_119 ( V_246 , L_54 ,
F_37 ( V_5 -> V_36 , V_73 ) ) ;
F_119 ( V_246 , L_55 ,
F_37 ( V_5 -> V_36 , V_37 ) ) ;
F_119 ( V_246 , L_56 ,
F_37 ( V_5 -> V_36 , V_52 ) ) ;
F_119 ( V_246 , L_57 ,
F_37 ( V_5 -> V_36 , V_51 ) ) ;
F_119 ( V_246 , L_58 ,
F_37 ( V_5 -> V_36 , V_71 ) ) ;
F_117 ( V_5 -> V_2 ) ;
F_110 ( V_5 -> V_2 ) ;
return 0 ;
}
static int F_120 ( struct V_249 * V_249 , struct V_250 * V_250 )
{
return F_121 ( V_250 , F_118 , V_249 -> V_251 ) ;
}
static void F_122 ( struct V_114 * V_7 )
{
if ( V_7 -> V_252 )
F_123 ( L_59 , V_253 , V_7 -> V_252 ,
V_7 , & V_254 ) ;
}
static void F_122 ( struct V_114 * V_7 )
{
}
static struct V_6 * F_124 ( struct V_1 * V_2 )
{
struct V_6 * V_8 ;
struct V_255 * V_256 = V_2 -> V_17 ;
T_2 V_78 , V_257 ;
V_8 = F_125 ( V_2 , sizeof( * V_8 ) , V_258 ) ;
if ( ! V_8 )
return NULL ;
if ( F_126 ( V_256 , L_60 , NULL ) )
V_8 -> V_93 |= V_94 ;
V_8 -> V_259 = 1 ;
V_8 -> V_9 [ 0 ] . V_10 = F_127 ( V_256 , L_61 , 0 ) ;
V_8 -> V_9 [ 0 ] . V_11 = F_127 ( V_256 , L_62 , 0 ) ;
if ( F_126 ( V_256 , L_63 , NULL ) ) {
V_8 -> V_9 [ 0 ] . V_260 = true ;
V_8 -> V_9 [ 0 ] . V_27 = true ;
}
F_128 ( V_256 , L_64 , & V_78 ) ;
if ( V_78 == 4 )
V_8 -> V_9 [ 0 ] . V_261 |= V_262 ;
else if ( V_78 == 8 )
V_8 -> V_9 [ 0 ] . V_261 |= V_263 ;
if ( F_126 ( V_256 , L_65 , NULL ) )
V_8 -> V_9 [ 0 ] . V_67 |= V_168 ;
if ( ! F_128 ( V_256 , L_66 , & V_257 ) )
V_8 -> V_257 = V_257 ;
if ( F_126 ( V_256 , L_67 , NULL ) )
V_8 -> V_9 [ 0 ] . V_67 |= V_68 ;
return V_8 ;
}
static inline struct V_6
* F_124 ( struct V_1 * V_2 )
{
return NULL ;
}
static int F_129 ( struct V_264 * V_265 )
{
struct V_6 * V_8 = V_265 -> V_2 . V_266 ;
struct V_114 * V_7 ;
struct V_4 * V_5 = NULL ;
struct V_267 * V_162 ;
int V_15 , V_105 ;
const struct V_268 * V_269 ;
T_6 V_270 ;
unsigned V_271 , V_272 ;
struct V_273 * V_273 ;
V_269 = F_130 ( F_131 ( V_274 ) , & V_265 -> V_2 ) ;
if ( V_269 ) {
V_8 = F_124 ( & V_265 -> V_2 ) ;
if ( V_269 -> V_118 ) {
const T_1 * V_275 = V_269 -> V_118 ;
V_8 -> V_276 = * V_275 ;
}
}
if ( V_8 == NULL ) {
F_20 ( & V_265 -> V_2 , L_68 ) ;
return - V_277 ;
}
if ( V_8 -> V_259 == 0 ) {
F_20 ( & V_265 -> V_2 , L_69 ) ;
return - V_277 ;
}
V_162 = F_132 ( V_265 , V_278 , 0 ) ;
V_105 = F_133 ( V_265 , 0 ) ;
if ( V_162 == NULL || V_105 < 0 )
return - V_277 ;
V_162 = F_134 ( V_162 -> V_279 , F_135 ( V_162 ) , V_265 -> V_116 ) ;
if ( V_162 == NULL )
return - V_280 ;
V_15 = F_28 ( V_8 ) ;
if ( V_15 )
goto V_170;
V_7 = F_136 ( sizeof( struct V_4 ) , & V_265 -> V_2 ) ;
if ( ! V_7 ) {
V_15 = - V_281 ;
goto V_282;
}
V_5 = F_59 ( V_7 ) ;
V_5 -> V_7 = V_7 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_2 = & V_265 -> V_2 ;
V_5 -> V_42 = 1 ;
V_5 -> V_145 = - 1 ;
V_5 -> V_105 = V_105 ;
V_5 -> V_28 = 0 ;
V_5 -> V_209 = V_162 -> V_279 + V_8 -> V_276 ;
V_5 -> V_36 = F_137 ( V_5 -> V_209 , V_283 ) ;
V_5 -> V_95 = V_96 ;
V_5 -> V_198 . V_199 = 1 ;
F_138 ( V_265 , V_5 ) ;
V_7 -> V_284 = & V_285 ;
if ( F_13 ( V_5 ) . V_286 )
F_13 ( V_5 ) . V_287 = 1 ;
V_7 -> V_288 = V_289 ;
if ( V_8 -> V_257 > 0 )
V_7 -> V_290 = V_8 -> V_257 ;
else
V_7 -> V_290 = V_291 ;
F_139 ( & V_5 -> V_146 ) ;
V_5 -> V_56 = F_140 ( & V_265 -> V_2 , L_70 ) ;
if ( F_19 ( V_5 -> V_56 ) ) {
V_15 = F_21 ( V_5 -> V_56 ) ;
V_5 -> V_56 = NULL ;
goto V_292;
}
if ( V_5 -> V_8 -> V_93 & V_293 ) {
F_87 ( & V_265 -> V_2 , L_71 ) ;
V_7 -> V_294 |= V_295 ;
}
F_141 ( V_5 -> V_2 ) ;
F_84 ( V_5 -> V_2 ) ;
F_142 ( V_5 -> V_2 , V_296 ) ;
F_143 ( V_5 -> V_2 ) ;
F_54 ( V_5 ) ;
V_5 -> V_185 = F_140 ( & V_265 -> V_2 , L_72 ) ;
if ( F_19 ( V_5 -> V_185 ) ) {
V_5 -> V_185 = NULL ;
} else if ( F_85 ( V_5 -> V_185 ) != 0 ) {
F_95 ( F_40 ( V_5 -> V_7 ) , L_73 ) ;
F_144 ( V_5 -> V_185 ) ;
V_5 -> V_185 = NULL ;
}
V_7 -> V_297 = 1024 ;
V_7 -> V_298 = 512 ;
V_7 -> V_299 = 0xFFFF ;
V_7 -> V_300 = V_7 -> V_298 * V_7 -> V_299 ;
V_7 -> V_301 = V_7 -> V_300 ;
V_7 -> V_261 |= V_302 | V_303 |
V_304 | V_305 ;
V_7 -> V_261 |= F_13 ( V_5 ) . V_261 ;
if ( V_7 -> V_261 & V_263 )
V_7 -> V_261 |= V_262 ;
if ( F_13 ( V_5 ) . V_260 )
V_7 -> V_261 |= V_306 ;
V_7 -> V_307 = F_13 ( V_5 ) . V_307 ;
F_114 ( V_5 ) ;
V_162 = F_145 ( V_265 , V_308 , L_74 ) ;
if ( ! V_162 ) {
F_20 ( F_40 ( V_5 -> V_7 ) , L_75 ) ;
V_15 = - V_277 ;
goto V_309;
}
V_271 = V_162 -> V_279 ;
V_162 = F_145 ( V_265 , V_308 , L_76 ) ;
if ( ! V_162 ) {
F_20 ( F_40 ( V_5 -> V_7 ) , L_77 ) ;
V_15 = - V_277 ;
goto V_309;
}
V_272 = V_162 -> V_279 ;
F_146 ( V_270 ) ;
F_147 ( V_310 , V_270 ) ;
V_5 -> V_143 = F_148 ( V_270 , V_311 , & V_272 ) ;
if ( ! V_5 -> V_143 ) {
F_20 ( F_40 ( V_5 -> V_7 ) , L_78 , V_272 ) ;
V_15 = - V_277 ;
goto V_309;
}
V_5 -> V_142 = F_148 ( V_270 , V_311 , & V_271 ) ;
if ( ! V_5 -> V_142 ) {
F_20 ( F_40 ( V_5 -> V_7 ) , L_79 , V_271 ) ;
V_15 = - V_277 ;
goto V_309;
}
V_15 = F_149 ( V_5 -> V_105 , F_79 , 0 ,
F_62 ( V_7 ) , V_5 ) ;
if ( V_15 ) {
F_20 ( F_40 ( V_5 -> V_7 ) , L_80 ) ;
goto V_309;
}
if ( V_8 -> V_312 != NULL ) {
if ( V_8 -> V_312 ( & V_265 -> V_2 ) != 0 ) {
F_20 ( F_40 ( V_5 -> V_7 ) ,
L_81 ) ;
goto V_313;
}
}
if ( F_27 () && ! F_13 ( V_5 ) . V_24 ) {
V_15 = F_17 ( V_5 ) ;
if ( V_15 )
goto V_314;
V_5 -> V_315 = 1 ;
}
V_7 -> V_316 = F_13 ( V_5 ) . V_25 ;
if ( ( F_13 ( V_5 ) . V_12 ) ) {
V_15 = F_150 ( F_13 ( V_5 ) . V_12 ,
NULL ,
F_88 ,
V_317 | V_318 | V_319 ,
F_62 ( V_7 ) , V_5 ) ;
if ( V_15 ) {
F_20 ( F_40 ( V_5 -> V_7 ) ,
L_82 ) ;
goto V_320;
}
V_8 -> V_321 = F_6 ;
V_8 -> V_322 = F_8 ;
}
F_42 ( V_5 ) ;
V_273 = F_151 ( & V_265 -> V_2 ) ;
if ( F_19 ( V_273 ) )
F_95 ( & V_265 -> V_2 ,
L_83 ) ;
F_86 ( V_5 ) ;
F_152 ( V_7 ) ;
if ( F_13 ( V_5 ) . V_116 != NULL ) {
V_15 = F_153 ( & V_7 -> V_115 , & V_323 ) ;
if ( V_15 < 0 )
goto V_324;
}
if ( F_13 ( V_5 ) . V_12 && F_13 ( V_5 ) . V_30 ) {
V_15 = F_153 ( & V_7 -> V_115 ,
& V_325 ) ;
if ( V_15 < 0 )
goto V_324;
}
F_122 ( V_7 ) ;
F_117 ( V_5 -> V_2 ) ;
F_110 ( V_5 -> V_2 ) ;
return 0 ;
V_324:
F_154 ( V_7 ) ;
F_155 ( F_13 ( V_5 ) . V_12 , V_5 ) ;
V_320:
if ( V_5 -> V_315 )
F_25 ( V_5 ) ;
V_314:
if ( V_5 -> V_8 -> V_326 )
V_5 -> V_8 -> V_326 ( & V_265 -> V_2 ) ;
V_313:
F_155 ( V_5 -> V_105 , V_5 ) ;
V_309:
if ( V_5 -> V_142 )
F_156 ( V_5 -> V_142 ) ;
if ( V_5 -> V_143 )
F_156 ( V_5 -> V_143 ) ;
F_82 ( V_5 -> V_2 ) ;
F_157 ( V_5 -> V_2 ) ;
F_144 ( V_5 -> V_56 ) ;
if ( V_5 -> V_185 ) {
F_83 ( V_5 -> V_185 ) ;
F_144 ( V_5 -> V_185 ) ;
}
V_292:
F_158 ( V_5 -> V_36 ) ;
F_138 ( V_265 , NULL ) ;
F_159 ( V_7 ) ;
V_282:
F_34 ( V_8 ) ;
V_170:
V_162 = F_132 ( V_265 , V_278 , 0 ) ;
if ( V_162 )
F_160 ( V_162 -> V_279 , F_135 ( V_162 ) ) ;
return V_15 ;
}
static int F_161 ( struct V_264 * V_265 )
{
struct V_4 * V_5 = F_11 ( V_265 ) ;
struct V_267 * V_162 ;
F_84 ( V_5 -> V_2 ) ;
F_154 ( V_5 -> V_7 ) ;
if ( V_5 -> V_315 )
F_25 ( V_5 ) ;
if ( V_5 -> V_8 -> V_326 )
V_5 -> V_8 -> V_326 ( & V_265 -> V_2 ) ;
F_155 ( V_5 -> V_105 , V_5 ) ;
if ( F_13 ( V_5 ) . V_12 )
F_155 ( F_13 ( V_5 ) . V_12 , V_5 ) ;
if ( V_5 -> V_142 )
F_156 ( V_5 -> V_142 ) ;
if ( V_5 -> V_143 )
F_156 ( V_5 -> V_143 ) ;
F_82 ( V_5 -> V_2 ) ;
F_157 ( V_5 -> V_2 ) ;
F_144 ( V_5 -> V_56 ) ;
if ( V_5 -> V_185 ) {
F_83 ( V_5 -> V_185 ) ;
F_144 ( V_5 -> V_185 ) ;
}
F_34 ( V_5 -> V_8 ) ;
F_158 ( V_5 -> V_36 ) ;
F_159 ( V_5 -> V_7 ) ;
V_162 = F_132 ( V_265 , V_278 , 0 ) ;
if ( V_162 )
F_160 ( V_162 -> V_279 , F_135 ( V_162 ) ) ;
F_138 ( V_265 , NULL ) ;
return 0 ;
}
static int F_162 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_8 -> V_321 )
return V_5 -> V_8 -> V_321 ( V_2 , V_5 -> V_28 ) ;
return 0 ;
}
static void F_163 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_8 -> V_322 )
V_5 -> V_8 -> V_322 ( V_2 , V_5 -> V_28 ) ;
}
static int F_164 ( struct V_1 * V_2 )
{
int V_15 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 )
return 0 ;
if ( V_5 && V_5 -> V_190 )
return 0 ;
F_84 ( V_5 -> V_2 ) ;
V_5 -> V_190 = 1 ;
V_15 = F_165 ( V_5 -> V_7 ) ;
if ( V_15 ) {
V_5 -> V_190 = 0 ;
goto V_170;
}
if ( ! ( V_5 -> V_7 -> V_327 & V_328 ) ) {
F_42 ( V_5 ) ;
F_36 ( V_5 -> V_36 , V_73 ,
F_37 ( V_5 -> V_36 , V_73 ) & ~ V_102 ) ;
}
if ( V_5 -> V_185 )
F_83 ( V_5 -> V_185 ) ;
V_170:
F_82 ( V_5 -> V_2 ) ;
return V_15 ;
}
static int F_166 ( struct V_1 * V_2 )
{
int V_15 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 )
return 0 ;
if ( V_5 && ! V_5 -> V_190 )
return 0 ;
F_84 ( V_5 -> V_2 ) ;
if ( V_5 -> V_185 )
F_85 ( V_5 -> V_185 ) ;
if ( ! ( V_5 -> V_7 -> V_327 & V_328 ) )
F_114 ( V_5 ) ;
F_86 ( V_5 ) ;
V_15 = F_167 ( V_5 -> V_7 ) ;
if ( V_15 == 0 )
V_5 -> V_190 = 0 ;
F_117 ( V_5 -> V_2 ) ;
F_110 ( V_5 -> V_2 ) ;
return V_15 ;
}
static int F_168 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
V_5 = F_11 ( F_12 ( V_2 ) ) ;
F_54 ( V_5 ) ;
F_39 ( V_2 , L_84 ) ;
return 0 ;
}
static int F_169 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
V_5 = F_11 ( F_12 ( V_2 ) ) ;
F_53 ( V_5 ) ;
F_39 ( V_2 , L_85 ) ;
return 0 ;
}
