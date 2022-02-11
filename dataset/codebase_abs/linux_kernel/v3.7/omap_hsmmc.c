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
F_23 ( V_5 -> V_2 , L_3 ,
F_13 ( V_5 ) . V_25 ) ;
F_13 ( V_5 ) . V_25 = 0 ;
return - V_26 ;
}
}
V_22 = F_18 ( V_5 -> V_2 , L_4 ) ;
V_5 -> V_19 = F_19 ( V_22 ) ? NULL : V_22 ;
if ( F_13 ( V_5 ) . V_27 )
return 0 ;
if ( F_24 ( V_5 -> V_16 ) > 0 ||
( V_5 -> V_19 && F_24 ( V_5 -> V_19 ) ) ) {
int V_14 = F_25 ( F_13 ( V_5 ) . V_25 ) - 1 ;
F_13 ( V_5 ) . V_24 ( V_5 -> V_2 , V_5 -> V_28 ,
1 , V_14 ) ;
F_13 ( V_5 ) . V_24 ( V_5 -> V_2 , V_5 -> V_28 ,
0 , 0 ) ;
}
}
return 0 ;
}
static void F_26 ( struct V_4 * V_5 )
{
F_27 ( V_5 -> V_16 ) ;
F_27 ( V_5 -> V_19 ) ;
F_13 ( V_5 ) . V_24 = NULL ;
}
static inline int F_28 ( void )
{
return 1 ;
}
static inline int F_17 ( struct V_4 * V_5 )
{
return - V_26 ;
}
static inline void F_26 ( struct V_4 * V_5 )
{
}
static inline int F_28 ( void )
{
return 0 ;
}
static int F_29 ( struct V_6 * V_8 )
{
int V_15 ;
if ( F_30 ( V_8 -> V_9 [ 0 ] . V_10 ) ) {
if ( V_8 -> V_9 [ 0 ] . V_29 )
V_8 -> V_9 [ 0 ] . V_30 =
F_5 ;
else
V_8 -> V_9 [ 0 ] . V_31 = F_1 ;
V_8 -> V_9 [ 0 ] . V_12 =
F_31 ( V_8 -> V_9 [ 0 ] . V_10 ) ;
V_15 = F_32 ( V_8 -> V_9 [ 0 ] . V_10 , L_5 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_33 ( V_8 -> V_9 [ 0 ] . V_10 ) ;
if ( V_15 )
goto V_32;
} else
V_8 -> V_9 [ 0 ] . V_10 = - V_26 ;
if ( F_30 ( V_8 -> V_9 [ 0 ] . V_11 ) ) {
V_8 -> V_9 [ 0 ] . V_33 = F_4 ;
V_15 = F_32 ( V_8 -> V_9 [ 0 ] . V_11 , L_6 ) ;
if ( V_15 )
goto V_34;
V_15 = F_33 ( V_8 -> V_9 [ 0 ] . V_11 ) ;
if ( V_15 )
goto V_35;
} else
V_8 -> V_9 [ 0 ] . V_11 = - V_26 ;
return 0 ;
V_35:
F_34 ( V_8 -> V_9 [ 0 ] . V_11 ) ;
V_34:
if ( F_30 ( V_8 -> V_9 [ 0 ] . V_10 ) )
V_32:
F_34 ( V_8 -> V_9 [ 0 ] . V_10 ) ;
return V_15 ;
}
static void F_35 ( struct V_6 * V_8 )
{
if ( F_30 ( V_8 -> V_9 [ 0 ] . V_11 ) )
F_34 ( V_8 -> V_9 [ 0 ] . V_11 ) ;
if ( F_30 ( V_8 -> V_9 [ 0 ] . V_10 ) )
F_34 ( V_8 -> V_9 [ 0 ] . V_10 ) ;
}
static void F_36 ( struct V_4 * V_5 )
{
F_37 ( V_5 -> V_36 , V_37 ,
F_38 ( V_5 -> V_36 , V_37 ) | V_38 ) ;
}
static void F_39 ( struct V_4 * V_5 )
{
F_37 ( V_5 -> V_36 , V_37 ,
F_38 ( V_5 -> V_36 , V_37 ) & ~ V_38 ) ;
if ( ( F_38 ( V_5 -> V_36 , V_37 ) & V_38 ) != 0x0 )
F_20 ( F_40 ( V_5 -> V_7 ) , L_7 ) ;
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
F_37 ( V_5 -> V_36 , V_49 , V_50 ) ;
F_37 ( V_5 -> V_36 , V_51 , V_41 ) ;
F_37 ( V_5 -> V_36 , V_52 , V_41 ) ;
}
static void F_42 ( struct V_4 * V_5 )
{
F_37 ( V_5 -> V_36 , V_51 , 0 ) ;
F_37 ( V_5 -> V_36 , V_52 , 0 ) ;
F_37 ( V_5 -> V_36 , V_49 , V_50 ) ;
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
F_47 ( F_40 ( V_5 -> V_7 ) , L_8 , V_54 -> clock ) ;
F_39 ( V_5 ) ;
V_57 = F_38 ( V_5 -> V_36 , V_37 ) ;
V_57 = V_57 & ~ ( V_59 | V_60 ) ;
V_57 = V_57 | ( F_43 ( V_5 , V_54 ) << 6 ) | ( V_61 << 16 ) ;
F_37 ( V_5 -> V_36 , V_37 , V_57 ) ;
F_37 ( V_5 -> V_36 , V_37 ,
F_38 ( V_5 -> V_36 , V_37 ) | V_62 ) ;
V_58 = V_63 + F_48 ( V_64 ) ;
while ( ( F_38 ( V_5 -> V_36 , V_37 ) & V_65 ) != V_65
&& F_49 ( V_63 , V_58 ) )
F_50 () ;
F_36 ( V_5 ) ;
}
static void F_51 ( struct V_4 * V_5 )
{
struct V_53 * V_54 = & V_5 -> V_7 -> V_54 ;
T_2 V_66 ;
V_66 = F_38 ( V_5 -> V_36 , V_67 ) ;
if ( V_54 -> V_68 == V_69 )
V_66 |= V_70 ;
else
V_66 &= ~ V_70 ;
switch ( V_54 -> V_71 ) {
case V_72 :
F_37 ( V_5 -> V_36 , V_67 , V_66 | V_73 ) ;
break;
case V_74 :
F_37 ( V_5 -> V_36 , V_67 , V_66 & ~ V_73 ) ;
F_37 ( V_5 -> V_36 , V_75 ,
F_38 ( V_5 -> V_36 , V_75 ) | V_76 ) ;
break;
case V_77 :
F_37 ( V_5 -> V_36 , V_67 , V_66 & ~ V_73 ) ;
F_37 ( V_5 -> V_36 , V_75 ,
F_38 ( V_5 -> V_36 , V_75 ) & ~ V_76 ) ;
break;
}
}
static void F_52 ( struct V_4 * V_5 )
{
struct V_53 * V_54 = & V_5 -> V_7 -> V_54 ;
T_2 V_66 ;
V_66 = F_38 ( V_5 -> V_36 , V_67 ) ;
if ( V_54 -> V_78 == V_79 )
F_37 ( V_5 -> V_36 , V_67 , V_66 | V_80 ) ;
else
F_37 ( V_5 -> V_36 , V_67 , V_66 & ~ V_80 ) ;
}
static int F_53 ( struct V_4 * V_5 )
{
struct V_53 * V_54 = & V_5 -> V_7 -> V_54 ;
struct V_6 * V_8 = V_5 -> V_8 ;
int V_81 = 0 ;
T_2 V_82 , V_83 ;
unsigned long V_58 ;
if ( V_8 -> V_84 ) {
V_81 = V_8 -> V_84 ( V_5 -> V_2 ) ;
if ( V_81 < 0 )
return 1 ;
}
F_20 ( F_40 ( V_5 -> V_7 ) , L_9 ,
V_81 == V_5 -> V_81 ? L_10 : L_11 ) ;
if ( V_5 -> V_81 == V_81 )
return 1 ;
if ( ! F_38 ( V_5 -> V_36 , V_85 ) & V_86 )
return 1 ;
if ( V_5 -> V_8 -> V_87 & V_88 ) {
if ( V_5 -> V_89 != V_90 &&
( 1 << V_54 -> V_14 ) <= V_91 )
V_82 = V_92 ;
else
V_82 = V_93 ;
V_83 = V_94 | V_95 ;
} else {
V_82 = V_92 ;
V_83 = V_95 ;
}
F_37 ( V_5 -> V_36 , V_75 ,
F_38 ( V_5 -> V_36 , V_75 ) | V_82 ) ;
F_37 ( V_5 -> V_36 , V_96 ,
F_38 ( V_5 -> V_36 , V_96 ) | V_83 ) ;
F_37 ( V_5 -> V_36 , V_75 ,
F_38 ( V_5 -> V_36 , V_75 ) | V_97 ) ;
V_58 = V_63 + F_48 ( V_64 ) ;
while ( ( F_38 ( V_5 -> V_36 , V_75 ) & V_97 ) != V_97
&& F_49 ( V_63 , V_58 ) )
;
F_42 ( V_5 ) ;
if ( V_5 -> V_89 == V_90 )
goto V_98;
F_51 ( V_5 ) ;
F_46 ( V_5 ) ;
F_52 ( V_5 ) ;
V_98:
V_5 -> V_81 = V_81 ;
F_20 ( F_40 ( V_5 -> V_7 ) , L_12 ) ;
return 0 ;
}
static void F_54 ( struct V_4 * V_5 )
{
struct V_6 * V_8 = V_5 -> V_8 ;
int V_81 ;
if ( V_8 -> V_84 ) {
V_81 = V_8 -> V_84 ( V_5 -> V_2 ) ;
if ( V_81 < 0 )
return;
V_5 -> V_81 = V_81 ;
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
if ( V_5 -> V_99 )
return;
F_7 ( V_5 -> V_100 ) ;
F_37 ( V_5 -> V_36 , V_52 , V_43 ) ;
F_37 ( V_5 -> V_36 , V_67 ,
F_38 ( V_5 -> V_36 , V_67 ) | V_101 ) ;
F_37 ( V_5 -> V_36 , V_102 , V_103 ) ;
V_58 = V_63 + F_48 ( V_64 ) ;
while ( ( V_22 != V_104 ) && F_49 ( V_63 , V_58 ) )
V_22 = F_38 ( V_5 -> V_36 , V_49 ) & V_104 ;
F_37 ( V_5 -> V_36 , V_67 ,
F_38 ( V_5 -> V_36 , V_67 ) & ~ V_101 ) ;
F_37 ( V_5 -> V_36 , V_49 , V_50 ) ;
F_38 ( V_5 -> V_36 , V_49 ) ;
F_9 ( V_5 -> V_100 ) ;
}
static inline
int F_56 ( struct V_4 * V_5 )
{
int V_105 = 1 ;
if ( F_13 ( V_5 ) . V_30 )
V_105 = F_13 ( V_5 ) . V_30 ( V_5 -> V_2 , V_5 -> V_28 ) ;
return V_105 ;
}
static T_3
F_57 ( struct V_1 * V_2 , struct V_106 * V_107 ,
char * V_108 )
{
struct V_109 * V_7 = F_58 ( V_2 , struct V_109 , V_110 ) ;
struct V_4 * V_5 = F_59 ( V_7 ) ;
return sprintf ( V_108 , L_13 ,
F_56 ( V_5 ) ? L_14 : L_15 ) ;
}
static T_3
F_60 ( struct V_1 * V_2 , struct V_106 * V_107 ,
char * V_108 )
{
struct V_109 * V_7 = F_58 ( V_2 , struct V_109 , V_110 ) ;
struct V_4 * V_5 = F_59 ( V_7 ) ;
return sprintf ( V_108 , L_13 , F_13 ( V_5 ) . V_111 ) ;
}
static void
F_61 ( struct V_4 * V_5 , struct V_39 * V_40 ,
struct V_112 * V_113 )
{
int V_114 = 0 , V_115 = 0 , V_116 = 0 ;
F_47 ( F_40 ( V_5 -> V_7 ) , L_16 ,
F_62 ( V_5 -> V_7 ) , V_40 -> V_46 , V_40 -> V_117 ) ;
V_5 -> V_40 = V_40 ;
F_41 ( V_5 , V_40 ) ;
V_5 -> V_118 = 0 ;
if ( V_40 -> V_119 & V_120 ) {
if ( V_40 -> V_119 & V_121 )
V_115 = 1 ;
else if ( V_40 -> V_119 & V_122 ) {
V_115 = 3 ;
V_5 -> V_118 = 1 ;
} else
V_115 = 2 ;
}
if ( V_40 == V_5 -> V_123 -> V_124 )
V_116 = 0x3 ;
V_114 = ( V_40 -> V_46 << 24 ) | ( V_115 << 16 ) | ( V_116 << 22 ) ;
if ( V_113 ) {
V_114 |= V_125 | V_126 | V_127 ;
if ( V_113 -> V_119 & V_128 )
V_114 |= V_129 ;
else
V_114 &= ~ ( V_129 ) ;
}
if ( V_5 -> V_42 )
V_114 |= V_130 ;
V_5 -> V_131 = 1 ;
F_37 ( V_5 -> V_36 , V_132 , V_40 -> V_117 ) ;
F_37 ( V_5 -> V_36 , V_102 , V_114 ) ;
}
static int
F_63 ( struct V_4 * V_5 , struct V_112 * V_113 )
{
if ( V_113 -> V_119 & V_133 )
return V_134 ;
else
return V_135 ;
}
static struct V_136 * F_64 ( struct V_4 * V_5 ,
struct V_112 * V_113 )
{
return V_113 -> V_119 & V_133 ? V_5 -> V_137 : V_5 -> V_138 ;
}
static void F_65 ( struct V_4 * V_5 , struct V_139 * V_123 )
{
int V_140 ;
unsigned long V_119 ;
F_66 ( & V_5 -> V_141 , V_119 ) ;
V_5 -> V_131 = 0 ;
V_140 = V_5 -> V_140 ;
F_67 ( & V_5 -> V_141 , V_119 ) ;
F_42 ( V_5 ) ;
if ( V_123 -> V_113 && V_5 -> V_42 && V_140 != - 1 )
return;
V_5 -> V_123 = NULL ;
F_68 ( V_5 -> V_7 , V_123 ) ;
}
static void
F_69 ( struct V_4 * V_5 , struct V_112 * V_113 )
{
if ( ! V_113 ) {
struct V_139 * V_123 = V_5 -> V_123 ;
if ( V_5 -> V_40 && V_5 -> V_40 -> V_46 == 6 &&
V_5 -> V_118 ) {
V_5 -> V_118 = 0 ;
return;
}
F_65 ( V_5 , V_123 ) ;
return;
}
V_5 -> V_113 = NULL ;
if ( ! V_113 -> error )
V_113 -> V_142 += V_113 -> V_143 * ( V_113 -> V_144 ) ;
else
V_113 -> V_142 = 0 ;
if ( ! V_113 -> V_124 ) {
F_65 ( V_5 , V_113 -> V_123 ) ;
return;
}
F_61 ( V_5 , V_113 -> V_124 , NULL ) ;
}
static void
F_70 ( struct V_4 * V_5 , struct V_39 * V_40 )
{
V_5 -> V_40 = NULL ;
if ( V_40 -> V_119 & V_120 ) {
if ( V_40 -> V_119 & V_121 ) {
V_40 -> V_145 [ 3 ] = F_38 ( V_5 -> V_36 , V_146 ) ;
V_40 -> V_145 [ 2 ] = F_38 ( V_5 -> V_36 , V_147 ) ;
V_40 -> V_145 [ 1 ] = F_38 ( V_5 -> V_36 , V_148 ) ;
V_40 -> V_145 [ 0 ] = F_38 ( V_5 -> V_36 , V_149 ) ;
} else {
V_40 -> V_145 [ 0 ] = F_38 ( V_5 -> V_36 , V_146 ) ;
}
}
if ( ( V_5 -> V_113 == NULL && ! V_5 -> V_118 ) || V_40 -> error )
F_65 ( V_5 , V_40 -> V_123 ) ;
}
static void F_71 ( struct V_4 * V_5 , int V_150 )
{
int V_140 ;
unsigned long V_119 ;
V_5 -> V_113 -> error = V_150 ;
F_66 ( & V_5 -> V_141 , V_119 ) ;
V_140 = V_5 -> V_140 ;
V_5 -> V_140 = - 1 ;
F_67 ( & V_5 -> V_141 , V_119 ) ;
if ( V_5 -> V_42 && V_140 != - 1 ) {
struct V_136 * V_151 = F_64 ( V_5 , V_5 -> V_113 ) ;
F_72 ( V_151 ) ;
F_73 ( V_151 -> V_1 -> V_2 ,
V_5 -> V_113 -> V_152 , V_5 -> V_113 -> V_153 ,
F_63 ( V_5 , V_5 -> V_113 ) ) ;
V_5 -> V_113 -> V_154 = 0 ;
}
V_5 -> V_113 = NULL ;
}
static void F_74 ( struct V_4 * V_5 , T_2 V_155 )
{
static const char * V_156 [] = {
L_17 , L_18 , L_19 , L_20 , L_21 , L_22 , L_20 , L_20 ,
L_23 , L_24 , L_20 , L_20 , L_20 , L_20 , L_20 , L_25 ,
L_26 , L_27 , L_28 , L_29 , L_30 , L_31 , L_32 , L_20 ,
L_33 , L_20 , L_20 , L_20 , L_34 , L_35 , L_20 , L_20
} ;
char V_157 [ 256 ] ;
char * V_108 = V_157 ;
int V_158 , V_159 ;
V_158 = sprintf ( V_108 , L_36 , V_155 ) ;
V_108 += V_158 ;
for ( V_159 = 0 ; V_159 < F_75 ( V_156 ) ; V_159 ++ )
if ( V_155 & ( 1 << V_159 ) ) {
V_158 = sprintf ( V_108 , L_37 , V_156 [ V_159 ] ) ;
V_108 += V_158 ;
}
F_47 ( F_40 ( V_5 -> V_7 ) , L_13 , V_157 ) ;
}
static inline void F_74 ( struct V_4 * V_5 ,
T_2 V_155 )
{
}
static inline void F_76 ( struct V_4 * V_5 ,
unsigned long V_160 )
{
unsigned long V_159 = 0 ;
unsigned long V_161 = ( V_162 *
F_48 ( V_64 ) ) ;
F_37 ( V_5 -> V_36 , V_37 ,
F_38 ( V_5 -> V_36 , V_37 ) | V_160 ) ;
if ( F_13 ( V_5 ) . V_163 & V_164 ) {
while ( ( ! ( F_38 ( V_5 -> V_36 , V_37 ) & V_160 ) )
&& ( V_159 ++ < V_161 ) )
F_50 () ;
}
V_159 = 0 ;
while ( ( F_38 ( V_5 -> V_36 , V_37 ) & V_160 ) &&
( V_159 ++ < V_161 ) )
F_50 () ;
if ( F_38 ( V_5 -> V_36 , V_37 ) & V_160 )
F_23 ( F_40 ( V_5 -> V_7 ) ,
L_38 ,
V_165 ) ;
}
static void F_77 ( struct V_4 * V_5 , int V_166 )
{
F_76 ( V_5 , V_167 ) ;
V_5 -> V_40 -> error = V_166 ;
if ( V_5 -> V_113 ) {
F_76 ( V_5 , V_168 ) ;
F_71 ( V_5 , V_166 ) ;
}
}
static void F_78 ( struct V_4 * V_5 , int V_155 )
{
struct V_112 * V_113 ;
int V_169 = 0 , V_170 = 0 ;
V_113 = V_5 -> V_113 ;
F_47 ( F_40 ( V_5 -> V_7 ) , L_39 , V_155 ) ;
if ( V_155 & V_171 ) {
F_74 ( V_5 , V_155 ) ;
if ( V_155 & ( V_172 | V_173 ) )
F_77 ( V_5 , - V_174 ) ;
else if ( V_155 & ( V_175 | V_176 ) )
F_77 ( V_5 , - V_177 ) ;
V_169 = 1 ;
if ( V_5 -> V_113 || V_5 -> V_118 ) {
V_170 = 1 ;
V_5 -> V_118 = 0 ;
}
}
if ( V_169 || ( ( V_155 & V_104 ) && V_5 -> V_40 ) )
F_70 ( V_5 , V_5 -> V_40 ) ;
if ( ( V_170 || ( V_155 & V_178 ) ) && V_5 -> V_123 )
F_69 ( V_5 , V_113 ) ;
}
static T_4 F_79 ( int V_100 , void * V_179 )
{
struct V_4 * V_5 = V_179 ;
int V_155 ;
V_155 = F_38 ( V_5 -> V_36 , V_49 ) ;
while ( V_155 & V_43 && V_5 -> V_131 ) {
F_78 ( V_5 , V_155 ) ;
F_37 ( V_5 -> V_36 , V_49 , V_155 ) ;
V_155 = F_38 ( V_5 -> V_36 , V_49 ) ;
}
return V_180 ;
}
static void F_80 ( struct V_4 * V_5 )
{
unsigned long V_159 ;
F_37 ( V_5 -> V_36 , V_75 ,
F_38 ( V_5 -> V_36 , V_75 ) | V_97 ) ;
for ( V_159 = 0 ; V_159 < V_162 ; V_159 ++ ) {
if ( F_38 ( V_5 -> V_36 , V_75 ) & V_97 )
break;
F_50 () ;
}
}
static int F_81 ( struct V_4 * V_5 , int V_14 )
{
T_2 V_181 = 0 ;
int V_15 ;
F_82 ( V_5 -> V_2 ) ;
if ( V_5 -> V_182 )
F_83 ( V_5 -> V_182 ) ;
V_15 = F_13 ( V_5 ) . V_24 ( V_5 -> V_2 , V_5 -> V_28 , 0 , 0 ) ;
if ( ! V_15 )
V_15 = F_13 ( V_5 ) . V_24 ( V_5 -> V_2 , V_5 -> V_28 , 1 ,
V_14 ) ;
F_84 ( V_5 -> V_2 ) ;
if ( V_5 -> V_182 )
F_85 ( V_5 -> V_182 ) ;
if ( V_15 != 0 )
goto V_166;
F_37 ( V_5 -> V_36 , V_75 ,
F_38 ( V_5 -> V_36 , V_75 ) & V_183 ) ;
V_181 = F_38 ( V_5 -> V_36 , V_75 ) ;
if ( ( 1 << V_14 ) <= V_91 )
V_181 |= V_92 ;
else
V_181 |= V_93 ;
F_37 ( V_5 -> V_36 , V_75 , V_181 ) ;
F_80 ( V_5 ) ;
return 0 ;
V_166:
F_20 ( F_40 ( V_5 -> V_7 ) , L_40 ) ;
return V_15 ;
}
static void F_86 ( struct V_4 * V_5 )
{
if ( ! F_13 ( V_5 ) . V_30 )
return;
V_5 -> V_184 = 0 ;
if ( F_13 ( V_5 ) . V_30 ( V_5 -> V_2 , V_5 -> V_28 ) ) {
if ( V_5 -> V_99 ) {
F_87 ( V_5 -> V_2 , L_41
L_42 ,
F_62 ( V_5 -> V_7 ) ) ;
V_5 -> V_99 = 0 ;
}
} else {
if ( ! V_5 -> V_99 ) {
F_87 ( V_5 -> V_2 , L_43
L_44 ,
F_62 ( V_5 -> V_7 ) ) ;
V_5 -> V_99 = 1 ;
}
}
}
static T_4 F_88 ( int V_100 , void * V_179 )
{
struct V_4 * V_5 = V_179 ;
struct V_185 * V_3 = & F_13 ( V_5 ) ;
int V_186 ;
if ( V_5 -> V_187 )
return V_180 ;
F_89 ( & V_5 -> V_7 -> V_110 . V_188 , NULL , L_45 ) ;
if ( V_3 -> V_31 )
V_186 = V_3 -> V_31 ( V_5 -> V_2 , V_5 -> V_28 ) ;
else {
F_86 ( V_5 ) ;
V_186 = - V_189 ;
}
if ( V_186 )
F_90 ( V_5 -> V_7 , ( V_190 * 200 ) / 1000 ) ;
else
F_90 ( V_5 -> V_7 , ( V_190 * 50 ) / 1000 ) ;
return V_180 ;
}
static void F_91 ( void * V_191 )
{
struct V_4 * V_5 = V_191 ;
struct V_136 * V_151 ;
struct V_112 * V_113 ;
int V_131 ;
F_92 ( & V_5 -> V_141 ) ;
if ( V_5 -> V_140 < 0 ) {
F_93 ( & V_5 -> V_141 ) ;
return;
}
V_113 = V_5 -> V_123 -> V_113 ;
V_151 = F_64 ( V_5 , V_113 ) ;
if ( ! V_113 -> V_154 )
F_73 ( V_151 -> V_1 -> V_2 ,
V_113 -> V_152 , V_113 -> V_153 ,
F_63 ( V_5 , V_113 ) ) ;
V_131 = V_5 -> V_131 ;
V_5 -> V_140 = - 1 ;
F_93 ( & V_5 -> V_141 ) ;
if ( ! V_131 ) {
struct V_139 * V_123 = V_5 -> V_123 ;
V_5 -> V_123 = NULL ;
F_68 ( V_5 -> V_7 , V_123 ) ;
}
}
static int F_94 ( struct V_4 * V_5 ,
struct V_112 * V_113 ,
struct V_192 * V_193 ,
struct V_136 * V_151 )
{
int V_194 ;
if ( ! V_193 && V_113 -> V_154 &&
V_113 -> V_154 != V_5 -> V_195 . V_196 ) {
F_95 ( V_5 -> V_2 , L_46
L_47 ,
V_165 , V_113 -> V_154 , V_5 -> V_195 . V_196 ) ;
V_113 -> V_154 = 0 ;
}
if ( V_193 ||
( ! V_193 && V_113 -> V_154 != V_5 -> V_195 . V_196 ) ) {
V_194 = F_96 ( V_151 -> V_1 -> V_2 , V_113 -> V_152 , V_113 -> V_153 ,
F_63 ( V_5 , V_113 ) ) ;
} else {
V_194 = V_5 -> V_195 . V_194 ;
V_5 -> V_195 . V_194 = 0 ;
}
if ( V_194 == 0 )
return - V_26 ;
if ( V_193 ) {
V_193 -> V_194 = V_194 ;
V_113 -> V_154 = ++ V_193 -> V_196 < 0 ? 1 : V_193 -> V_196 ;
} else
V_5 -> V_194 = V_194 ;
return 0 ;
}
static int F_97 ( struct V_4 * V_5 ,
struct V_139 * V_197 )
{
struct V_198 V_199 ;
struct V_200 * V_201 ;
int V_15 = 0 , V_159 ;
struct V_112 * V_113 = V_197 -> V_113 ;
struct V_136 * V_151 ;
for ( V_159 = 0 ; V_159 < V_113 -> V_153 ; V_159 ++ ) {
struct V_202 * V_203 ;
V_203 = V_113 -> V_152 + V_159 ;
if ( V_203 -> V_204 % V_113 -> V_144 )
return - V_26 ;
}
if ( ( V_113 -> V_144 % 4 ) != 0 )
return - V_26 ;
F_98 ( V_5 -> V_140 != - 1 ) ;
V_151 = F_64 ( V_5 , V_113 ) ;
V_199 . V_205 = V_5 -> V_206 + V_207 ;
V_199 . V_208 = V_5 -> V_206 + V_207 ;
V_199 . V_209 = V_210 ;
V_199 . V_211 = V_210 ;
V_199 . V_212 = V_113 -> V_144 / 4 ;
V_199 . V_213 = V_113 -> V_144 / 4 ;
V_15 = F_99 ( V_151 , & V_199 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_94 ( V_5 , V_113 , NULL , V_151 ) ;
if ( V_15 )
return V_15 ;
V_201 = F_100 ( V_151 , V_113 -> V_152 , V_113 -> V_153 ,
V_113 -> V_119 & V_133 ? V_214 : V_215 ,
V_216 | V_217 ) ;
if ( ! V_201 ) {
F_23 ( F_40 ( V_5 -> V_7 ) , L_48 ) ;
return - 1 ;
}
V_201 -> V_218 = F_91 ;
V_201 -> V_219 = V_5 ;
F_101 ( V_201 ) ;
V_5 -> V_140 = 1 ;
F_102 ( V_151 ) ;
return 0 ;
}
static void F_103 ( struct V_4 * V_5 ,
unsigned int V_220 ,
unsigned int V_221 )
{
unsigned int V_58 , V_222 ;
T_5 V_22 , V_223 , V_224 = 0 ;
V_22 = F_38 ( V_5 -> V_36 , V_37 ) ;
V_223 = ( V_22 & V_59 ) >> V_225 ;
if ( V_223 == 0 )
V_223 = 1 ;
V_222 = 1000000000 / ( F_45 ( V_5 -> V_56 ) / V_223 ) ;
V_58 = V_220 / V_222 ;
V_58 += V_221 ;
if ( V_58 ) {
while ( ( V_58 & 0x80000000 ) == 0 ) {
V_224 += 1 ;
V_58 <<= 1 ;
}
V_224 = 31 - V_224 ;
V_58 <<= 1 ;
if ( V_58 && V_224 )
V_224 += 1 ;
if ( V_224 >= 13 )
V_224 -= 13 ;
else
V_224 = 0 ;
if ( V_224 > 14 )
V_224 = 14 ;
}
V_22 &= ~ V_60 ;
V_22 |= V_224 << V_226 ;
F_37 ( V_5 -> V_36 , V_37 , V_22 ) ;
}
static int
F_104 ( struct V_4 * V_5 , struct V_139 * V_197 )
{
int V_15 ;
V_5 -> V_113 = V_197 -> V_113 ;
if ( V_197 -> V_113 == NULL ) {
F_37 ( V_5 -> V_36 , V_227 , 0 ) ;
if ( V_197 -> V_40 -> V_119 & V_122 )
F_103 ( V_5 , 100000000U , 0 ) ;
return 0 ;
}
F_37 ( V_5 -> V_36 , V_227 , ( V_197 -> V_113 -> V_144 )
| ( V_197 -> V_113 -> V_143 << 16 ) ) ;
F_103 ( V_5 , V_197 -> V_113 -> V_220 , V_197 -> V_113 -> V_221 ) ;
if ( V_5 -> V_42 ) {
V_15 = F_97 ( V_5 , V_197 ) ;
if ( V_15 != 0 ) {
F_20 ( F_40 ( V_5 -> V_7 ) , L_49 ) ;
return V_15 ;
}
}
return 0 ;
}
static void F_105 ( struct V_109 * V_7 , struct V_139 * V_123 ,
int V_166 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
struct V_112 * V_113 = V_123 -> V_113 ;
if ( V_5 -> V_42 && V_113 -> V_154 ) {
struct V_136 * V_228 = F_64 ( V_5 , V_113 ) ;
F_73 ( V_228 -> V_1 -> V_2 , V_113 -> V_152 , V_113 -> V_153 ,
F_63 ( V_5 , V_113 ) ) ;
V_113 -> V_154 = 0 ;
}
}
static void F_106 ( struct V_109 * V_7 , struct V_139 * V_123 ,
bool V_229 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
if ( V_123 -> V_113 -> V_154 ) {
V_123 -> V_113 -> V_154 = 0 ;
return ;
}
if ( V_5 -> V_42 ) {
struct V_136 * V_228 = F_64 ( V_5 , V_123 -> V_113 ) ;
if ( F_94 ( V_5 , V_123 -> V_113 ,
& V_5 -> V_195 , V_228 ) )
V_123 -> V_113 -> V_154 = 0 ;
}
}
static void F_107 ( struct V_109 * V_7 , struct V_139 * V_197 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
int V_166 ;
F_98 ( V_5 -> V_131 ) ;
F_98 ( V_5 -> V_140 != - 1 ) ;
if ( V_5 -> V_99 ) {
if ( V_5 -> V_184 < 3 ) {
F_76 ( V_5 , V_168 ) ;
F_76 ( V_5 , V_167 ) ;
V_5 -> V_184 += 1 ;
}
V_197 -> V_40 -> error = - V_230 ;
if ( V_197 -> V_113 )
V_197 -> V_113 -> error = - V_230 ;
V_197 -> V_40 -> V_231 = 0 ;
F_68 ( V_7 , V_197 ) ;
return;
} else if ( V_5 -> V_184 )
V_5 -> V_184 = 0 ;
F_108 ( V_5 -> V_123 != NULL ) ;
V_5 -> V_123 = V_197 ;
V_166 = F_104 ( V_5 , V_197 ) ;
if ( V_166 ) {
V_197 -> V_40 -> error = V_166 ;
if ( V_197 -> V_113 )
V_197 -> V_113 -> error = V_166 ;
V_5 -> V_123 = NULL ;
F_68 ( V_7 , V_197 ) ;
return;
}
F_61 ( V_5 , V_197 -> V_40 , V_197 -> V_113 ) ;
}
static void F_109 ( struct V_109 * V_7 , struct V_53 * V_54 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
int V_232 = 0 ;
F_84 ( V_5 -> V_2 ) ;
if ( V_54 -> V_89 != V_5 -> V_89 ) {
switch ( V_54 -> V_89 ) {
case V_90 :
F_13 ( V_5 ) . V_24 ( V_5 -> V_2 , V_5 -> V_28 ,
0 , 0 ) ;
break;
case V_233 :
F_13 ( V_5 ) . V_24 ( V_5 -> V_2 , V_5 -> V_28 ,
1 , V_54 -> V_14 ) ;
break;
case V_234 :
V_232 = 1 ;
break;
}
V_5 -> V_89 = V_54 -> V_89 ;
}
F_51 ( V_5 ) ;
if ( V_5 -> V_8 -> V_87 & V_88 ) {
if ( ( F_38 ( V_5 -> V_36 , V_75 ) & V_235 ) &&
( V_54 -> V_14 == V_236 ) &&
! V_5 -> V_2 -> V_17 ) {
if ( F_81 ( V_5 , V_54 -> V_14 ) != 0 )
F_20 ( F_40 ( V_5 -> V_7 ) ,
L_50 ) ;
}
}
F_46 ( V_5 ) ;
if ( V_232 )
F_55 ( V_5 ) ;
F_52 ( V_5 ) ;
F_110 ( V_5 -> V_2 ) ;
}
static int F_111 ( struct V_109 * V_7 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
if ( ! F_13 ( V_5 ) . V_31 )
return - V_189 ;
return F_13 ( V_5 ) . V_31 ( V_5 -> V_2 , V_5 -> V_28 ) ;
}
static int F_112 ( struct V_109 * V_7 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
if ( ! F_13 ( V_5 ) . V_33 )
return - V_189 ;
return F_13 ( V_5 ) . V_33 ( V_5 -> V_2 , 0 ) ;
}
static void F_113 ( struct V_109 * V_7 , struct V_237 * V_238 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
if ( F_13 ( V_5 ) . V_239 )
F_13 ( V_5 ) . V_239 ( V_238 ) ;
}
static void F_114 ( struct V_4 * V_5 )
{
T_2 V_82 , V_83 , V_240 ;
if ( V_5 -> V_8 -> V_87 & V_88 ) {
V_82 = V_93 ;
V_83 = V_94 | V_95 ;
} else {
V_82 = V_92 ;
V_83 = V_95 ;
}
V_240 = F_38 ( V_5 -> V_36 , V_75 ) & ~ V_241 ;
F_37 ( V_5 -> V_36 , V_75 , V_240 | V_82 ) ;
V_240 = F_38 ( V_5 -> V_36 , V_96 ) ;
F_37 ( V_5 -> V_36 , V_96 , V_240 | V_83 ) ;
F_80 ( V_5 ) ;
}
static int F_115 ( struct V_109 * V_7 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
F_84 ( V_5 -> V_2 ) ;
return 0 ;
}
static int F_116 ( struct V_109 * V_7 )
{
struct V_4 * V_5 = F_59 ( V_7 ) ;
F_117 ( V_5 -> V_2 ) ;
F_110 ( V_5 -> V_2 ) ;
return 0 ;
}
static int F_118 ( struct V_242 * V_243 , void * V_113 )
{
struct V_109 * V_7 = V_243 -> V_244 ;
struct V_4 * V_5 = F_59 ( V_7 ) ;
int V_81 = 0 ;
if ( V_5 -> V_8 -> V_84 )
V_81 = V_5 -> V_8 -> V_84 ( V_5 -> V_2 ) ;
F_119 ( V_243 , L_51 ,
V_7 -> V_245 , V_5 -> V_81 , V_81 ) ;
if ( V_5 -> V_187 ) {
F_119 ( V_243 , L_52 ) ;
return 0 ;
}
F_84 ( V_5 -> V_2 ) ;
F_119 ( V_243 , L_53 ,
F_38 ( V_5 -> V_36 , V_67 ) ) ;
F_119 ( V_243 , L_54 ,
F_38 ( V_5 -> V_36 , V_75 ) ) ;
F_119 ( V_243 , L_55 ,
F_38 ( V_5 -> V_36 , V_37 ) ) ;
F_119 ( V_243 , L_56 ,
F_38 ( V_5 -> V_36 , V_52 ) ) ;
F_119 ( V_243 , L_57 ,
F_38 ( V_5 -> V_36 , V_51 ) ) ;
F_119 ( V_243 , L_58 ,
F_38 ( V_5 -> V_36 , V_96 ) ) ;
F_117 ( V_5 -> V_2 ) ;
F_110 ( V_5 -> V_2 ) ;
return 0 ;
}
static int F_120 ( struct V_246 * V_246 , struct V_247 * V_247 )
{
return F_121 ( V_247 , F_118 , V_246 -> V_248 ) ;
}
static void F_122 ( struct V_109 * V_7 )
{
if ( V_7 -> V_249 )
F_123 ( L_59 , V_250 , V_7 -> V_249 ,
V_7 , & V_251 ) ;
}
static void F_122 ( struct V_109 * V_7 )
{
}
static struct V_6 * F_124 ( struct V_1 * V_2 )
{
struct V_6 * V_8 ;
struct V_252 * V_253 = V_2 -> V_17 ;
T_2 V_71 ;
V_8 = F_125 ( V_2 , sizeof( * V_8 ) , V_254 ) ;
if ( ! V_8 )
return NULL ;
if ( F_126 ( V_253 , L_60 , NULL ) )
V_8 -> V_87 |= V_88 ;
V_8 -> V_255 = 1 ;
V_8 -> V_9 [ 0 ] . V_10 = F_127 ( V_253 , L_61 , 0 ) ;
V_8 -> V_9 [ 0 ] . V_11 = F_127 ( V_253 , L_62 , 0 ) ;
if ( F_126 ( V_253 , L_63 , NULL ) ) {
V_8 -> V_9 [ 0 ] . V_256 = true ;
V_8 -> V_9 [ 0 ] . V_27 = true ;
}
F_128 ( V_253 , L_64 , & V_71 ) ;
if ( V_71 == 4 )
V_8 -> V_9 [ 0 ] . V_257 |= V_258 ;
else if ( V_71 == 8 )
V_8 -> V_9 [ 0 ] . V_257 |= V_259 ;
if ( F_126 ( V_253 , L_65 , NULL ) )
V_8 -> V_9 [ 0 ] . V_163 |= V_164 ;
return V_8 ;
}
static inline struct V_6
* F_124 ( struct V_1 * V_2 )
{
return NULL ;
}
static int T_6 F_129 ( struct V_260 * V_261 )
{
struct V_6 * V_8 = V_261 -> V_2 . V_262 ;
struct V_109 * V_7 ;
struct V_4 * V_5 = NULL ;
struct V_263 * V_157 ;
int V_15 , V_100 ;
const struct V_264 * V_265 ;
T_7 V_266 ;
unsigned V_267 , V_268 ;
V_265 = F_130 ( F_131 ( V_269 ) , & V_261 -> V_2 ) ;
if ( V_265 ) {
V_8 = F_124 ( & V_261 -> V_2 ) ;
if ( V_265 -> V_113 ) {
const T_1 * V_270 = V_265 -> V_113 ;
V_8 -> V_271 = * V_270 ;
}
}
if ( V_8 == NULL ) {
F_23 ( & V_261 -> V_2 , L_66 ) ;
return - V_272 ;
}
if ( V_8 -> V_255 == 0 ) {
F_23 ( & V_261 -> V_2 , L_67 ) ;
return - V_272 ;
}
V_157 = F_132 ( V_261 , V_273 , 0 ) ;
V_100 = F_133 ( V_261 , 0 ) ;
if ( V_157 == NULL || V_100 < 0 )
return - V_272 ;
V_157 = F_134 ( V_157 -> V_274 , F_135 ( V_157 ) , V_261 -> V_111 ) ;
if ( V_157 == NULL )
return - V_275 ;
V_15 = F_29 ( V_8 ) ;
if ( V_15 )
goto V_166;
V_7 = F_136 ( sizeof( struct V_4 ) , & V_261 -> V_2 ) ;
if ( ! V_7 ) {
V_15 = - V_276 ;
goto V_277;
}
V_5 = F_59 ( V_7 ) ;
V_5 -> V_7 = V_7 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_2 = & V_261 -> V_2 ;
V_5 -> V_42 = 1 ;
V_5 -> V_140 = - 1 ;
V_5 -> V_100 = V_100 ;
V_5 -> V_28 = 0 ;
V_5 -> V_206 = V_157 -> V_274 + V_8 -> V_271 ;
V_5 -> V_36 = F_137 ( V_5 -> V_206 , V_278 ) ;
V_5 -> V_89 = V_90 ;
V_5 -> V_195 . V_196 = 1 ;
F_138 ( V_261 , V_5 ) ;
V_7 -> V_279 = & V_280 ;
if ( F_13 ( V_5 ) . V_281 )
F_13 ( V_5 ) . V_282 = 1 ;
V_7 -> V_283 = V_284 ;
if ( V_8 -> V_285 > 0 )
V_7 -> V_286 = V_8 -> V_285 ;
else
V_7 -> V_286 = V_287 ;
F_139 ( & V_5 -> V_141 ) ;
V_5 -> V_56 = F_140 ( & V_261 -> V_2 , L_68 ) ;
if ( F_19 ( V_5 -> V_56 ) ) {
V_15 = F_21 ( V_5 -> V_56 ) ;
V_5 -> V_56 = NULL ;
goto V_288;
}
if ( V_5 -> V_8 -> V_87 & V_289 ) {
F_87 ( & V_261 -> V_2 , L_69 ) ;
V_7 -> V_290 |= V_291 ;
}
F_141 ( V_5 -> V_2 ) ;
F_84 ( V_5 -> V_2 ) ;
F_142 ( V_5 -> V_2 , V_292 ) ;
F_143 ( V_5 -> V_2 ) ;
F_54 ( V_5 ) ;
V_5 -> V_182 = F_140 ( & V_261 -> V_2 , L_70 ) ;
if ( F_19 ( V_5 -> V_182 ) ) {
F_95 ( F_40 ( V_5 -> V_7 ) , L_71 ) ;
V_5 -> V_182 = NULL ;
} else if ( F_85 ( V_5 -> V_182 ) != 0 ) {
F_95 ( F_40 ( V_5 -> V_7 ) , L_72 ) ;
F_144 ( V_5 -> V_182 ) ;
V_5 -> V_182 = NULL ;
}
V_7 -> V_293 = 1024 ;
V_7 -> V_294 = 512 ;
V_7 -> V_295 = 0xFFFF ;
V_7 -> V_296 = V_7 -> V_294 * V_7 -> V_295 ;
V_7 -> V_297 = V_7 -> V_296 ;
V_7 -> V_257 |= V_298 | V_299 |
V_300 | V_301 ;
V_7 -> V_257 |= F_13 ( V_5 ) . V_257 ;
if ( V_7 -> V_257 & V_259 )
V_7 -> V_257 |= V_258 ;
if ( F_13 ( V_5 ) . V_256 )
V_7 -> V_257 |= V_302 ;
V_7 -> V_303 = F_13 ( V_5 ) . V_303 ;
F_114 ( V_5 ) ;
V_157 = F_145 ( V_261 , V_304 , L_73 ) ;
if ( ! V_157 ) {
F_23 ( F_40 ( V_5 -> V_7 ) , L_74 ) ;
V_15 = - V_272 ;
goto V_305;
}
V_267 = V_157 -> V_274 ;
V_157 = F_145 ( V_261 , V_304 , L_75 ) ;
if ( ! V_157 ) {
F_23 ( F_40 ( V_5 -> V_7 ) , L_76 ) ;
V_15 = - V_272 ;
goto V_305;
}
V_268 = V_157 -> V_274 ;
F_146 ( V_266 ) ;
F_147 ( V_306 , V_266 ) ;
V_5 -> V_138 = F_148 ( V_266 , V_307 , & V_268 ) ;
if ( ! V_5 -> V_138 ) {
F_23 ( F_40 ( V_5 -> V_7 ) , L_77 , V_268 ) ;
V_15 = - V_272 ;
goto V_305;
}
V_5 -> V_137 = F_148 ( V_266 , V_307 , & V_267 ) ;
if ( ! V_5 -> V_137 ) {
F_23 ( F_40 ( V_5 -> V_7 ) , L_78 , V_267 ) ;
V_15 = - V_272 ;
goto V_305;
}
V_15 = F_149 ( V_5 -> V_100 , F_79 , 0 ,
F_62 ( V_7 ) , V_5 ) ;
if ( V_15 ) {
F_20 ( F_40 ( V_5 -> V_7 ) , L_79 ) ;
goto V_305;
}
if ( V_8 -> V_308 != NULL ) {
if ( V_8 -> V_308 ( & V_261 -> V_2 ) != 0 ) {
F_20 ( F_40 ( V_5 -> V_7 ) ,
L_80 ) ;
goto V_309;
}
}
if ( F_28 () && ! F_13 ( V_5 ) . V_24 ) {
V_15 = F_17 ( V_5 ) ;
if ( V_15 )
goto V_310;
V_5 -> V_311 = 1 ;
}
V_7 -> V_312 = F_13 ( V_5 ) . V_25 ;
if ( ( F_13 ( V_5 ) . V_12 ) ) {
V_15 = F_150 ( F_13 ( V_5 ) . V_12 ,
NULL ,
F_88 ,
V_313 | V_314 | V_315 ,
F_62 ( V_7 ) , V_5 ) ;
if ( V_15 ) {
F_20 ( F_40 ( V_5 -> V_7 ) ,
L_81 ) ;
goto V_316;
}
V_8 -> V_317 = F_6 ;
V_8 -> V_318 = F_8 ;
}
F_42 ( V_5 ) ;
F_86 ( V_5 ) ;
F_151 ( V_7 ) ;
if ( F_13 ( V_5 ) . V_111 != NULL ) {
V_15 = F_152 ( & V_7 -> V_110 , & V_319 ) ;
if ( V_15 < 0 )
goto V_320;
}
if ( F_13 ( V_5 ) . V_12 && F_13 ( V_5 ) . V_30 ) {
V_15 = F_152 ( & V_7 -> V_110 ,
& V_321 ) ;
if ( V_15 < 0 )
goto V_320;
}
F_122 ( V_7 ) ;
F_117 ( V_5 -> V_2 ) ;
F_110 ( V_5 -> V_2 ) ;
return 0 ;
V_320:
F_153 ( V_7 ) ;
F_154 ( F_13 ( V_5 ) . V_12 , V_5 ) ;
V_316:
if ( V_5 -> V_311 )
F_26 ( V_5 ) ;
V_310:
if ( V_5 -> V_8 -> V_322 )
V_5 -> V_8 -> V_322 ( & V_261 -> V_2 ) ;
V_309:
F_154 ( V_5 -> V_100 , V_5 ) ;
V_305:
if ( V_5 -> V_137 )
F_155 ( V_5 -> V_137 ) ;
if ( V_5 -> V_138 )
F_155 ( V_5 -> V_138 ) ;
F_82 ( V_5 -> V_2 ) ;
F_156 ( V_5 -> V_2 ) ;
F_144 ( V_5 -> V_56 ) ;
if ( V_5 -> V_182 ) {
F_83 ( V_5 -> V_182 ) ;
F_144 ( V_5 -> V_182 ) ;
}
V_288:
F_157 ( V_5 -> V_36 ) ;
F_138 ( V_261 , NULL ) ;
F_158 ( V_7 ) ;
V_277:
F_35 ( V_8 ) ;
V_166:
V_157 = F_132 ( V_261 , V_273 , 0 ) ;
if ( V_157 )
F_159 ( V_157 -> V_274 , F_135 ( V_157 ) ) ;
return V_15 ;
}
static int T_8 F_160 ( struct V_260 * V_261 )
{
struct V_4 * V_5 = F_11 ( V_261 ) ;
struct V_263 * V_157 ;
F_84 ( V_5 -> V_2 ) ;
F_153 ( V_5 -> V_7 ) ;
if ( V_5 -> V_311 )
F_26 ( V_5 ) ;
if ( V_5 -> V_8 -> V_322 )
V_5 -> V_8 -> V_322 ( & V_261 -> V_2 ) ;
F_154 ( V_5 -> V_100 , V_5 ) ;
if ( F_13 ( V_5 ) . V_12 )
F_154 ( F_13 ( V_5 ) . V_12 , V_5 ) ;
if ( V_5 -> V_137 )
F_155 ( V_5 -> V_137 ) ;
if ( V_5 -> V_138 )
F_155 ( V_5 -> V_138 ) ;
F_82 ( V_5 -> V_2 ) ;
F_156 ( V_5 -> V_2 ) ;
F_144 ( V_5 -> V_56 ) ;
if ( V_5 -> V_182 ) {
F_83 ( V_5 -> V_182 ) ;
F_144 ( V_5 -> V_182 ) ;
}
F_35 ( V_5 -> V_8 ) ;
F_157 ( V_5 -> V_36 ) ;
F_158 ( V_5 -> V_7 ) ;
V_157 = F_132 ( V_261 , V_273 , 0 ) ;
if ( V_157 )
F_159 ( V_157 -> V_274 , F_135 ( V_157 ) ) ;
F_138 ( V_261 , NULL ) ;
return 0 ;
}
static int F_161 ( struct V_1 * V_2 )
{
int V_15 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 )
return 0 ;
if ( V_5 && V_5 -> V_187 )
return 0 ;
F_84 ( V_5 -> V_2 ) ;
V_5 -> V_187 = 1 ;
if ( V_5 -> V_8 -> V_317 ) {
V_15 = V_5 -> V_8 -> V_317 ( V_2 , V_5 -> V_28 ) ;
if ( V_15 ) {
F_20 ( V_2 , L_82
L_83 ) ;
V_5 -> V_187 = 0 ;
return V_15 ;
}
}
V_15 = F_162 ( V_5 -> V_7 ) ;
if ( V_15 ) {
V_5 -> V_187 = 0 ;
if ( V_5 -> V_8 -> V_318 ) {
if ( V_5 -> V_8 -> V_318 ( V_2 , V_5 -> V_28 ) )
F_20 ( V_2 , L_84 ) ;
}
goto V_166;
}
if ( ! ( V_5 -> V_7 -> V_323 & V_324 ) ) {
F_42 ( V_5 ) ;
F_37 ( V_5 -> V_36 , V_75 ,
F_38 ( V_5 -> V_36 , V_75 ) & ~ V_97 ) ;
}
if ( V_5 -> V_182 )
F_83 ( V_5 -> V_182 ) ;
V_166:
F_82 ( V_5 -> V_2 ) ;
return V_15 ;
}
static int F_163 ( struct V_1 * V_2 )
{
int V_15 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 )
return 0 ;
if ( V_5 && ! V_5 -> V_187 )
return 0 ;
F_84 ( V_5 -> V_2 ) ;
if ( V_5 -> V_182 )
F_85 ( V_5 -> V_182 ) ;
if ( ! ( V_5 -> V_7 -> V_323 & V_324 ) )
F_114 ( V_5 ) ;
if ( V_5 -> V_8 -> V_318 ) {
V_15 = V_5 -> V_8 -> V_318 ( V_2 , V_5 -> V_28 ) ;
if ( V_15 )
F_20 ( V_2 , L_84 ) ;
}
F_86 ( V_5 ) ;
V_15 = F_164 ( V_5 -> V_7 ) ;
if ( V_15 == 0 )
V_5 -> V_187 = 0 ;
F_117 ( V_5 -> V_2 ) ;
F_110 ( V_5 -> V_2 ) ;
return V_15 ;
}
static int F_165 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
V_5 = F_11 ( F_12 ( V_2 ) ) ;
F_54 ( V_5 ) ;
F_20 ( V_2 , L_85 ) ;
return 0 ;
}
static int F_166 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
V_5 = F_11 ( F_12 ( V_2 ) ) ;
F_53 ( V_5 ) ;
F_20 ( V_2 , L_86 ) ;
return 0 ;
}
