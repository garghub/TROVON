static inline unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_2 -> V_4 == V_5 ) {
V_3 /= V_6 ;
} else {
V_3 = F_2 ( V_5 * ( unsigned long long ) V_3 ,
V_6 * ( unsigned long long ) V_2 -> V_4 ) ;
}
return V_3 - ( V_3 % V_2 -> V_7 ) ;
}
static inline unsigned int F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_2 -> V_4 == V_5 ) {
return V_3 * V_6 ;
} else {
V_3 = F_2 ( V_2 -> V_4 * ( unsigned long long ) V_3 * V_6 ,
V_5 ) ;
}
return V_3 ;
}
static inline struct V_8 * F_4 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_10 -> V_11 -> V_12 -> V_9 ;
if ( V_2 -> V_10 -> V_13 == V_14 )
V_9 ^= 1 ;
return & V_2 -> V_15 -> V_16 [ V_2 -> V_10 -> V_17 ] [ V_9 ] ;
}
static inline unsigned int F_5 ( struct V_1 * V_2 )
{
return F_4 ( V_2 ) -> V_18 ;
}
static inline unsigned int F_6 ( struct V_1 * V_2 )
{
return F_4 ( V_2 ) -> V_19 ;
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned long V_20 ;
unsigned int V_19 = F_6 ( V_2 ) ;
if ( V_19 != V_2 -> V_4 ) {
V_2 -> V_4 = V_19 ;
V_2 -> V_21 = F_3 ( V_2 , V_2 -> V_22 ) ;
}
if ( V_2 -> V_21 <= V_2 -> V_23 ) {
V_2 -> V_23 %= V_2 -> V_21 ;
V_2 -> V_24 = 1 ;
}
V_20 = V_2 -> V_21 - V_2 -> V_23 ;
V_20 = ( V_20 + V_2 -> V_25 - 1 ) / V_2 -> V_25 ;
V_2 -> V_26 . V_27 = V_28 + V_20 ;
F_8 ( & V_2 -> V_26 ) ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_26 ) ;
V_2 -> V_26 . V_27 = 0 ;
}
static int F_11 ( struct V_29 * V_30 , int V_13 )
{
struct V_31 * V_32 , * V_33 ;
struct V_8 * V_16 ;
struct V_34 * V_35 ;
int V_36 ;
if ( V_30 -> V_37 != V_38 ) {
if ( V_13 == V_14 )
goto V_39;
return 0 ;
}
V_32 = V_30 -> V_40 [ V_14 ] ->
V_10 -> V_32 ;
V_33 = V_30 -> V_40 [ V_41 ] ->
V_10 -> V_32 ;
V_36 = V_32 -> V_42 != V_33 -> V_42 ||
V_32 -> V_43 != V_33 -> V_43 ||
V_32 -> V_44 != V_33 -> V_44 ;
if ( ! V_36 )
return 0 ;
if ( V_13 == V_41 ) {
return - V_45 ;
} else {
F_12 ( V_30 -> V_40 [ V_41 ] ->
V_10 , V_46 ) ;
V_39:
V_32 = V_30 -> V_40 [ V_14 ] ->
V_10 -> V_32 ;
V_16 = F_4 ( V_30 -> V_40 [ V_14 ] ) ;
V_35 = V_30 -> V_40 [ V_14 ] -> V_15 -> V_35 ;
if ( V_16 -> V_42 != V_32 -> V_42 ) {
F_13 ( V_35 , V_47 ,
& V_16 -> V_48 ) ;
V_16 -> V_42 = V_32 -> V_42 ;
}
if ( V_16 -> V_43 != V_32 -> V_43 ) {
F_13 ( V_35 , V_47 ,
& V_16 -> V_49 ) ;
V_16 -> V_43 = V_32 -> V_43 ;
}
if ( V_16 -> V_44 != V_32 -> V_44 ) {
F_13 ( V_35 , V_47 ,
& V_16 -> V_50 ) ;
V_16 -> V_44 = V_32 -> V_44 ;
}
}
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_15 -> V_35 ,
V_47 ,
& F_4 ( V_2 ) -> V_51 ) ;
}
static int F_15 ( struct V_52 * V_10 , int V_53 )
{
struct V_31 * V_32 = V_10 -> V_32 ;
struct V_1 * V_2 = V_32 -> V_54 ;
struct V_29 * V_30 = V_2 -> V_30 ;
int V_55 , V_13 = 1 << V_10 -> V_13 ;
switch ( V_53 ) {
case V_56 :
V_55 = F_11 ( V_30 , V_10 -> V_13 ) ;
if ( V_55 < 0 )
return V_55 ;
V_2 -> V_57 = V_28 ;
V_2 -> V_4 = 0 ;
F_16 ( & V_30 -> V_58 ) ;
V_30 -> V_59 |= V_13 ;
V_30 -> V_60 &= ~ V_13 ;
F_17 ( & V_30 -> V_58 ) ;
F_7 ( V_2 ) ;
if ( V_10 -> V_13 == V_14 )
F_14 ( V_2 ) ;
break;
case V_61 :
F_16 ( & V_30 -> V_58 ) ;
V_30 -> V_59 &= ~ V_13 ;
V_30 -> V_60 &= ~ V_13 ;
F_17 ( & V_30 -> V_58 ) ;
F_9 ( V_2 ) ;
if ( V_10 -> V_13 == V_14 )
F_14 ( V_2 ) ;
break;
case V_62 :
F_16 ( & V_30 -> V_58 ) ;
V_30 -> V_60 |= V_13 ;
F_17 ( & V_30 -> V_58 ) ;
F_9 ( V_2 ) ;
break;
case V_63 :
F_16 ( & V_30 -> V_58 ) ;
V_2 -> V_57 = V_28 ;
V_30 -> V_60 &= ~ V_13 ;
F_17 ( & V_30 -> V_58 ) ;
F_7 ( V_2 ) ;
break;
default:
return - V_64 ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_31 * V_65 ;
if ( V_2 == NULL || V_2 -> V_10 == NULL )
return;
V_65 = V_2 -> V_10 -> V_32 ;
if ( V_65 == NULL )
return;
V_65 -> V_66 = V_2 -> V_30 -> V_66 ;
}
static void F_19 ( struct V_52 * V_10 )
{
struct V_31 * V_32 = V_10 -> V_32 ;
struct V_1 * V_2 = V_32 -> V_54 ;
struct V_29 * V_30 = V_2 -> V_30 ;
V_30 -> V_66 . V_67 = ( 1ULL << V_32 -> V_42 ) ;
V_30 -> V_66 . V_68 = V_32 -> V_43 ;
V_30 -> V_66 . V_69 = V_32 -> V_43 ;
V_30 -> V_66 . V_70 = V_32 -> V_44 ;
V_30 -> V_66 . V_71 = V_32 -> V_44 ;
F_18 ( V_30 -> V_40 [ V_14 ] ,
V_32 ) ;
F_18 ( V_30 -> V_40 [ V_41 ] ,
V_32 ) ;
}
static int F_20 ( struct V_52 * V_10 )
{
struct V_31 * V_32 = V_10 -> V_32 ;
struct V_1 * V_2 = V_32 -> V_54 ;
struct V_29 * V_30 = V_2 -> V_30 ;
int V_72 , V_73 ;
V_73 = ( F_21 ( V_32 -> V_42 ) *
V_32 -> V_44 ) / 8 ;
V_72 = V_73 * V_32 -> V_43 ;
if ( V_72 <= 0 || V_73 <= 0 )
return - V_64 ;
V_2 -> V_74 = 0 ;
V_2 -> V_75 = F_22 ( V_32 , V_32 -> V_76 ) ;
if ( V_10 -> V_13 == V_41 ) {
V_2 -> V_77 = V_2 -> V_75 ;
F_23 ( V_32 -> V_42 , V_32 -> V_78 ,
V_32 -> V_76 * V_32 -> V_44 ) ;
}
V_2 -> V_23 = 0 ;
V_2 -> V_24 = 0 ;
V_2 -> V_25 = V_72 ;
V_2 -> V_7 = V_73 ;
V_2 -> V_22 = F_22 ( V_32 , V_32 -> V_79 ) ;
F_24 ( & V_2 -> V_15 -> V_80 ) ;
if ( ! ( V_30 -> V_37 & ~ ( 1 << V_10 -> V_13 ) ) ||
( F_4 ( V_2 ) -> V_18 &&
V_10 -> V_13 == V_14 ) )
F_19 ( V_10 ) ;
V_30 -> V_37 |= 1 << V_10 -> V_13 ;
F_25 ( & V_2 -> V_15 -> V_80 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 , unsigned int V_81 )
{
struct V_31 * V_32 = V_2 -> V_10 -> V_32 ;
char * V_82 = V_32 -> V_78 ;
unsigned int V_83 = V_2 -> V_74 ;
if ( V_2 -> V_77 >= V_2 -> V_75 )
return;
if ( V_2 -> V_77 + V_81 > V_2 -> V_75 )
V_81 = V_2 -> V_75 - V_2 -> V_77 ;
for (; ; ) {
unsigned int V_84 = V_81 ;
if ( V_83 + V_84 > V_2 -> V_75 )
V_84 = V_2 -> V_75 - V_83 ;
F_23 ( V_32 -> V_42 , V_82 + V_83 ,
F_27 ( V_32 , V_84 ) *
V_32 -> V_44 ) ;
V_2 -> V_77 += V_84 ;
V_81 -= V_84 ;
if ( ! V_81 )
break;
V_83 = 0 ;
}
}
static void F_28 ( struct V_1 * V_85 ,
struct V_1 * V_86 ,
unsigned int V_81 )
{
struct V_31 * V_32 = V_85 -> V_10 -> V_32 ;
char * V_87 = V_32 -> V_78 ;
char * V_82 = V_86 -> V_10 -> V_32 -> V_78 ;
unsigned int V_88 = V_85 -> V_74 ;
unsigned int V_83 = V_86 -> V_74 ;
unsigned int V_89 = 0 ;
if ( V_32 -> V_90 -> V_91 == V_46 &&
F_29 ( V_32 ) < V_32 -> V_76 ) {
T_1 V_92 , V_93 , V_94 ;
V_92 = V_93 = V_32 -> V_95 -> V_92 ;
V_93 -= V_93 % V_32 -> V_76 ;
V_93 += V_85 -> V_74 / V_85 -> V_7 ;
if ( V_92 < V_93 )
V_93 -= V_32 -> V_76 ;
V_94 = ( V_92 - V_93 ) * V_85 -> V_7 ;
if ( V_94 < V_81 ) {
V_89 = V_81 - V_94 ;
V_81 = V_94 ;
}
}
for (; ; ) {
unsigned int V_84 = V_81 ;
if ( V_88 + V_84 > V_85 -> V_75 )
V_84 = V_85 -> V_75 - V_88 ;
if ( V_83 + V_84 > V_86 -> V_75 )
V_84 = V_86 -> V_75 - V_83 ;
memcpy ( V_82 + V_83 , V_87 + V_88 , V_84 ) ;
V_86 -> V_77 = 0 ;
V_81 -= V_84 ;
if ( ! V_81 )
break;
V_88 = ( V_88 + V_84 ) % V_85 -> V_75 ;
V_83 = ( V_83 + V_84 ) % V_86 -> V_75 ;
}
if ( V_89 > 0 ) {
F_26 ( V_86 , V_89 ) ;
V_86 -> V_77 = 0 ;
}
}
static void F_30 ( struct V_1 * V_2 ,
unsigned int V_96 ,
unsigned int V_53 )
{
unsigned int V_97 ;
unsigned long V_98 ;
V_98 = F_1 ( V_2 , V_2 -> V_23 ) ;
V_2 -> V_23 += V_96 * V_2 -> V_25 ;
V_97 = F_1 ( V_2 , V_2 -> V_23 ) - V_98 ;
if ( ! V_97 )
return;
if ( V_53 == V_99 )
F_26 ( V_2 , V_97 ) ;
else if ( V_53 == V_100 )
F_28 ( V_2 -> V_30 -> V_40 [ V_14 ] ,
V_2 -> V_30 -> V_40 [ V_41 ] ,
V_97 ) ;
V_2 -> V_74 += V_97 ;
V_2 -> V_74 %= V_2 -> V_75 ;
if ( V_2 -> V_23 >= V_2 -> V_21 ) {
V_2 -> V_23 %= V_2 -> V_21 ;
V_2 -> V_24 = 1 ;
}
}
static unsigned int F_31 ( struct V_29 * V_30 )
{
struct V_1 * V_101 =
V_30 -> V_40 [ V_14 ] ;
struct V_1 * V_102 =
V_30 -> V_40 [ V_41 ] ;
unsigned long V_103 = 0 , V_104 = 0 ;
unsigned int V_59 ;
unsigned long V_105 ;
F_32 ( & V_30 -> V_58 , V_105 ) ;
V_59 = V_30 -> V_59 ^ V_30 -> V_60 ;
if ( V_59 & ( 1 << V_14 ) ) {
V_103 = V_28 - V_101 -> V_57 ;
V_101 -> V_57 += V_103 ;
}
if ( V_59 & ( 1 << V_41 ) ) {
V_104 = V_28 - V_102 -> V_57 ;
V_102 -> V_57 += V_104 ;
}
if ( V_103 == 0 && V_104 == 0 )
goto V_106;
if ( V_103 > V_104 ) {
F_30 ( V_101 , V_103 - V_104 ,
V_107 ) ;
V_103 = V_104 ;
} else if ( V_103 < V_104 ) {
F_30 ( V_102 , V_104 - V_103 ,
V_99 ) ;
V_104 = V_103 ;
}
if ( V_103 == 0 && V_104 == 0 )
goto V_106;
F_30 ( V_102 , V_104 , V_100 ) ;
F_30 ( V_101 , V_103 , V_107 ) ;
V_106:
F_33 ( & V_30 -> V_58 , V_105 ) ;
return V_59 ;
}
static void F_34 ( unsigned long V_108 )
{
struct V_1 * V_2 = (struct V_1 * ) V_108 ;
unsigned int V_59 ;
V_59 = F_31 ( V_2 -> V_30 ) ;
if ( V_59 & ( 1 << V_2 -> V_10 -> V_13 ) ) {
F_7 ( V_2 ) ;
if ( V_2 -> V_24 ) {
V_2 -> V_24 = 0 ;
F_35 ( V_2 -> V_10 ) ;
}
}
}
static T_1 F_36 ( struct V_52 * V_10 )
{
struct V_31 * V_32 = V_10 -> V_32 ;
struct V_1 * V_2 = V_32 -> V_54 ;
F_31 ( V_2 -> V_30 ) ;
return F_27 ( V_32 , V_2 -> V_74 ) ;
}
static void F_37 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_54 ;
F_38 ( V_2 ) ;
}
static int F_39 ( struct V_52 * V_10 ,
struct V_109 * V_110 )
{
return F_40 ( V_10 ,
F_41 ( V_110 ) ) ;
}
static int F_42 ( struct V_52 * V_10 )
{
struct V_31 * V_32 = V_10 -> V_32 ;
struct V_1 * V_2 = V_32 -> V_54 ;
struct V_29 * V_30 = V_2 -> V_30 ;
F_24 ( & V_2 -> V_15 -> V_80 ) ;
V_30 -> V_37 &= ~ ( 1 << V_10 -> V_13 ) ;
F_25 ( & V_2 -> V_15 -> V_80 ) ;
return F_43 ( V_10 ) ;
}
static unsigned int F_44 ( struct V_52 * V_10 )
{
if ( ! V_10 -> V_12 -> V_9 )
return V_10 -> V_13 ;
else
return ! V_10 -> V_13 ;
}
static int F_45 ( struct V_109 * V_110 ,
struct V_111 * V_112 )
{
struct V_113 * V_66 = V_112 -> V_114 ;
struct V_115 * V_116 = F_46 ( V_110 , V_112 -> V_117 ) ;
V_116 -> V_118 [ 0 ] &= ( V_119 ) V_66 -> V_67 ;
V_116 -> V_118 [ 1 ] &= ( V_119 ) ( V_66 -> V_67 >> 32 ) ;
memset ( V_116 -> V_118 + 2 , 0 , ( V_120 - 64 ) / 8 ) ;
if ( ! V_116 -> V_118 [ 0 ] && ! V_116 -> V_118 [ 1 ] )
return - V_64 ;
return 0 ;
}
static int F_47 ( struct V_109 * V_110 ,
struct V_111 * V_112 )
{
struct V_113 * V_66 = V_112 -> V_114 ;
struct V_121 V_122 ;
V_122 . V_123 = V_66 -> V_68 ;
V_122 . V_124 = V_66 -> V_69 ;
V_122 . V_125 = V_122 . V_126 = 0 ;
V_122 . integer = 0 ;
return F_48 ( F_49 ( V_110 , V_112 -> V_117 ) , & V_122 ) ;
}
static int F_50 ( struct V_109 * V_110 ,
struct V_111 * V_112 )
{
struct V_113 * V_66 = V_112 -> V_114 ;
struct V_121 V_122 ;
V_122 . V_123 = V_66 -> V_70 ;
V_122 . V_124 = V_66 -> V_71 ;
V_122 . V_125 = V_122 . V_126 = 0 ;
V_122 . integer = 0 ;
return F_48 ( F_49 ( V_110 , V_112 -> V_117 ) , & V_122 ) ;
}
static int F_51 ( struct V_52 * V_10 )
{
struct V_31 * V_32 = V_10 -> V_32 ;
struct V_15 * V_15 = V_10 -> V_54 ;
struct V_1 * V_2 ;
struct V_29 * V_30 ;
int V_55 = 0 ;
int V_127 = F_44 ( V_10 ) ;
F_24 ( & V_15 -> V_80 ) ;
V_2 = F_52 ( sizeof( * V_2 ) , V_128 ) ;
if ( ! V_2 ) {
V_55 = - V_129 ;
goto V_106;
}
V_2 -> V_15 = V_15 ;
V_2 -> V_10 = V_10 ;
F_53 ( & V_2 -> V_26 , F_34 ,
( unsigned long ) V_2 ) ;
V_30 = V_15 -> V_130 [ V_10 -> V_17 ] [ V_127 ] ;
if ( ! V_30 ) {
V_30 = F_52 ( sizeof( * V_30 ) , V_128 ) ;
if ( ! V_30 ) {
F_38 ( V_2 ) ;
V_55 = - V_129 ;
goto V_106;
}
F_54 ( & V_30 -> V_58 ) ;
V_30 -> V_66 = V_131 ;
V_15 -> V_130 [ V_10 -> V_17 ] [ V_127 ] = V_30 ;
}
V_2 -> V_30 = V_30 ;
V_30 -> V_40 [ V_10 -> V_13 ] = V_2 ;
F_55 ( V_32 , V_132 ) ;
V_55 = F_56 ( V_32 , 0 ,
V_133 ,
F_45 , & V_32 -> V_66 ,
V_133 , - 1 ) ;
if ( V_55 < 0 )
goto V_106;
V_55 = F_56 ( V_32 , 0 ,
V_134 ,
F_47 , & V_32 -> V_66 ,
V_134 , - 1 ) ;
if ( V_55 < 0 )
goto V_106;
V_55 = F_56 ( V_32 , 0 ,
V_135 ,
F_50 , & V_32 -> V_66 ,
V_135 , - 1 ) ;
if ( V_55 < 0 )
goto V_106;
V_32 -> V_54 = V_2 ;
V_32 -> V_136 = F_37 ;
if ( F_5 ( V_2 ) )
V_32 -> V_66 = V_131 ;
else
V_32 -> V_66 = V_30 -> V_66 ;
V_106:
F_25 ( & V_15 -> V_80 ) ;
return V_55 ;
}
static int F_57 ( struct V_52 * V_10 )
{
struct V_15 * V_15 = V_10 -> V_54 ;
struct V_1 * V_2 = V_10 -> V_32 -> V_54 ;
struct V_29 * V_30 ;
int V_127 = F_44 ( V_10 ) ;
F_9 ( V_2 ) ;
F_24 ( & V_15 -> V_80 ) ;
V_30 = V_15 -> V_130 [ V_10 -> V_17 ] [ V_127 ] ;
if ( V_30 -> V_40 [ ! V_10 -> V_13 ] ) {
V_30 -> V_40 [ V_10 -> V_13 ] = NULL ;
} else {
V_15 -> V_130 [ V_10 -> V_17 ] [ V_127 ] = NULL ;
F_38 ( V_30 ) ;
}
F_25 ( & V_15 -> V_80 ) ;
return 0 ;
}
static int T_2 F_58 ( struct V_15 * V_15 ,
int V_9 , int V_137 )
{
struct V_138 * V_12 ;
int V_55 ;
V_55 = F_59 ( V_15 -> V_35 , L_1 , V_9 ,
V_137 , V_137 , & V_12 ) ;
if ( V_55 < 0 )
return V_55 ;
F_60 ( V_12 , V_14 , & V_139 ) ;
F_60 ( V_12 , V_41 , & V_140 ) ;
V_12 -> V_54 = V_15 ;
V_12 -> V_141 = 0 ;
strcpy ( V_12 -> V_142 , L_1 ) ;
V_15 -> V_12 [ V_9 ] = V_12 ;
return 0 ;
}
static int F_61 ( struct V_143 * V_144 ,
struct V_145 * V_146 )
{
V_146 -> type = V_147 ;
V_146 -> V_97 = 1 ;
V_146 -> V_148 . integer . V_123 = 80000 ;
V_146 -> V_148 . integer . V_124 = 120000 ;
V_146 -> V_148 . integer . V_149 = 1 ;
return 0 ;
}
static int F_62 ( struct V_143 * V_144 ,
struct V_150 * V_151 )
{
struct V_15 * V_15 = F_63 ( V_144 ) ;
V_151 -> V_148 . integer . V_148 [ 0 ] =
V_15 -> V_16 [ V_144 -> V_152 . V_153 ]
[ V_144 -> V_152 . V_9 ] . V_19 ;
return 0 ;
}
static int F_64 ( struct V_143 * V_144 ,
struct V_150 * V_151 )
{
struct V_15 * V_15 = F_63 ( V_144 ) ;
unsigned int V_154 ;
int V_155 = 0 ;
V_154 = V_151 -> V_148 . integer . V_148 [ 0 ] ;
if ( V_154 < 80000 )
V_154 = 80000 ;
if ( V_154 > 120000 )
V_154 = 120000 ;
F_24 ( & V_15 -> V_80 ) ;
if ( V_154 != V_15 -> V_16 [ V_144 -> V_152 . V_153 ]
[ V_144 -> V_152 . V_9 ] . V_19 ) {
V_15 -> V_16 [ V_144 -> V_152 . V_153 ]
[ V_144 -> V_152 . V_9 ] . V_19 = V_154 ;
V_155 = 1 ;
}
F_25 ( & V_15 -> V_80 ) ;
return V_155 ;
}
static int F_65 ( struct V_143 * V_144 ,
struct V_150 * V_151 )
{
struct V_15 * V_15 = F_63 ( V_144 ) ;
V_151 -> V_148 . integer . V_148 [ 0 ] =
V_15 -> V_16 [ V_144 -> V_152 . V_153 ]
[ V_144 -> V_152 . V_9 ] . V_18 ;
return 0 ;
}
static int F_66 ( struct V_143 * V_144 ,
struct V_150 * V_151 )
{
struct V_15 * V_15 = F_63 ( V_144 ) ;
unsigned int V_154 ;
int V_155 = 0 ;
V_154 = V_151 -> V_148 . integer . V_148 [ 0 ] ? 1 : 0 ;
if ( V_154 != V_15 -> V_16 [ V_144 -> V_152 . V_153 ]
[ V_144 -> V_152 . V_9 ] . V_18 ) {
V_15 -> V_16 [ V_144 -> V_152 . V_153 ]
[ V_144 -> V_152 . V_9 ] . V_18 = V_154 ;
V_155 = 1 ;
}
return V_155 ;
}
static int F_67 ( struct V_143 * V_144 ,
struct V_150 * V_151 )
{
struct V_15 * V_15 = F_63 ( V_144 ) ;
struct V_29 * V_30 = V_15 -> V_130
[ V_144 -> V_152 . V_153 ] [ V_144 -> V_152 . V_9 ^ 1 ] ;
unsigned int V_154 = 0 ;
if ( V_30 != NULL )
V_154 = ( V_30 -> V_59 & ( 1 << V_14 ) ) ?
1 : 0 ;
V_151 -> V_148 . integer . V_148 [ 0 ] = V_154 ;
return 0 ;
}
static int F_68 ( struct V_143 * V_144 ,
struct V_145 * V_146 )
{
V_146 -> type = V_147 ;
V_146 -> V_97 = 1 ;
V_146 -> V_148 . integer . V_123 = 0 ;
V_146 -> V_148 . integer . V_124 = V_156 ;
V_146 -> V_148 . integer . V_149 = 1 ;
return 0 ;
}
static int F_69 ( struct V_143 * V_144 ,
struct V_150 * V_151 )
{
struct V_15 * V_15 = F_63 ( V_144 ) ;
V_151 -> V_148 . integer . V_148 [ 0 ] =
V_15 -> V_16 [ V_144 -> V_152 . V_153 ]
[ V_144 -> V_152 . V_9 ] . V_42 ;
return 0 ;
}
static int F_70 ( struct V_143 * V_144 ,
struct V_145 * V_146 )
{
V_146 -> type = V_147 ;
V_146 -> V_97 = 1 ;
V_146 -> V_148 . integer . V_123 = 0 ;
V_146 -> V_148 . integer . V_124 = 192000 ;
V_146 -> V_148 . integer . V_149 = 1 ;
return 0 ;
}
static int F_71 ( struct V_143 * V_144 ,
struct V_150 * V_151 )
{
struct V_15 * V_15 = F_63 ( V_144 ) ;
V_151 -> V_148 . integer . V_148 [ 0 ] =
V_15 -> V_16 [ V_144 -> V_152 . V_153 ]
[ V_144 -> V_152 . V_9 ] . V_43 ;
return 0 ;
}
static int F_72 ( struct V_143 * V_144 ,
struct V_145 * V_146 )
{
V_146 -> type = V_147 ;
V_146 -> V_97 = 1 ;
V_146 -> V_148 . integer . V_123 = 1 ;
V_146 -> V_148 . integer . V_124 = 1024 ;
V_146 -> V_148 . integer . V_149 = 1 ;
return 0 ;
}
static int F_73 ( struct V_143 * V_144 ,
struct V_150 * V_151 )
{
struct V_15 * V_15 = F_63 ( V_144 ) ;
V_151 -> V_148 . integer . V_148 [ 0 ] =
V_15 -> V_16 [ V_144 -> V_152 . V_153 ]
[ V_144 -> V_152 . V_9 ] . V_44 ;
return 0 ;
}
static int T_2 F_74 ( struct V_15 * V_15 , int V_18 )
{
struct V_34 * V_35 = V_15 -> V_35 ;
struct V_138 * V_12 ;
struct V_143 * V_157 ;
struct V_8 * V_16 ;
int V_55 , V_127 , V_158 , V_159 , V_160 ;
strcpy ( V_35 -> V_161 , L_2 ) ;
for ( V_127 = 0 ; V_127 < 2 ; V_127 ++ ) {
V_12 = V_15 -> V_12 [ V_127 ] ;
V_159 =
V_12 -> V_40 [ V_41 ] . V_162 ;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
V_16 = & V_15 -> V_16 [ V_158 ] [ V_127 ] ;
V_16 -> V_18 = V_18 ;
V_16 -> V_19 = V_5 ;
V_16 -> V_42 = V_163 ;
V_16 -> V_43 = 48000 ;
V_16 -> V_44 = 2 ;
for ( V_160 = 0 ; V_160 < F_75 ( V_164 ) ;
V_160 ++ ) {
V_157 = F_76 ( & V_164 [ V_160 ] ,
V_15 ) ;
if ( ! V_157 )
return - V_129 ;
V_157 -> V_152 . V_9 = V_127 ;
V_157 -> V_152 . V_153 = V_158 ;
switch ( V_160 ) {
case V_165 :
V_16 -> V_51 = V_157 -> V_152 ;
break;
case V_166 :
V_16 -> V_48 = V_157 -> V_152 ;
break;
case V_167 :
V_16 -> V_49 = V_157 -> V_152 ;
break;
case V_168 :
V_16 -> V_50 = V_157 -> V_152 ;
break;
default:
break;
}
V_55 = F_77 ( V_35 , V_157 ) ;
if ( V_55 < 0 )
return V_55 ;
}
}
}
return 0 ;
}
static void F_78 ( struct V_169 * V_170 ,
struct V_1 * V_2 ,
const char * V_152 )
{
F_79 ( V_170 , L_3 , V_152 ) ;
if ( V_2 == NULL ) {
F_79 ( V_170 , L_4 ) ;
return;
}
F_79 ( V_170 , L_5 , V_2 -> V_75 ) ;
F_79 ( V_170 , L_6 , V_2 -> V_74 ) ;
F_79 ( V_170 , L_7 , V_2 -> V_77 ) ;
F_79 ( V_170 , L_8 , V_2 -> V_22 ) ;
F_79 ( V_170 , L_9 , V_2 -> V_25 ) ;
F_79 ( V_170 , L_10 , V_2 -> V_7 ) ;
F_79 ( V_170 , L_11 , V_2 -> V_4 ) ;
F_79 ( V_170 , L_12 ,
V_2 -> V_24 ) ;
F_79 ( V_170 , L_13 , V_2 -> V_23 ) ;
F_79 ( V_170 , L_14 , V_2 -> V_21 ) ;
F_79 ( V_170 , L_15 ,
V_2 -> V_57 , V_28 ) ;
F_79 ( V_170 , L_16 , V_2 -> V_26 . V_27 ) ;
}
static void F_80 ( struct V_169 * V_170 ,
struct V_15 * V_15 ,
int V_171 ,
int V_172 )
{
struct V_29 * V_30 = V_15 -> V_130 [ V_171 ] [ V_172 ] ;
F_79 ( V_170 , L_17 , V_172 , V_171 ) ;
if ( V_30 == NULL ) {
F_79 ( V_170 , L_18 ) ;
return;
}
F_79 ( V_170 , L_19 , V_30 -> V_37 ) ;
F_79 ( V_170 , L_20 , V_30 -> V_59 ) ;
F_79 ( V_170 , L_21 , V_30 -> V_60 ) ;
F_78 ( V_170 , V_30 -> V_40 [ 0 ] , L_22 ) ;
F_78 ( V_170 , V_30 -> V_40 [ 1 ] , L_23 ) ;
}
static void F_81 ( struct V_173 * V_174 ,
struct V_169 * V_170 )
{
struct V_15 * V_15 = V_174 -> V_54 ;
int V_171 , V_172 ;
F_24 ( & V_15 -> V_80 ) ;
V_172 = V_174 -> V_142 [ strlen ( V_174 -> V_142 ) - 1 ] ;
V_172 = V_172 == '0' ? 0 : 1 ;
for ( V_171 = 0 ; V_171 < V_175 ; V_171 ++ )
F_80 ( V_170 , V_15 , V_171 , V_172 ) ;
F_25 ( & V_15 -> V_80 ) ;
}
static int T_2 F_82 ( struct V_15 * V_15 , int V_176 )
{
char V_142 [ 32 ] ;
struct V_173 * V_174 ;
int V_55 ;
snprintf ( V_142 , sizeof( V_142 ) , L_24 , V_176 ) ;
V_55 = F_83 ( V_15 -> V_35 , V_142 , & V_174 ) ;
if ( V_55 < 0 )
return V_55 ;
F_84 ( V_174 , V_15 , F_81 ) ;
return 0 ;
}
static int T_2 F_85 ( struct V_177 * V_178 )
{
struct V_34 * V_35 ;
struct V_15 * V_15 ;
int V_127 = V_178 -> V_152 ;
int V_55 ;
V_55 = F_86 ( V_179 [ V_127 ] , V_152 [ V_127 ] , V_180 ,
sizeof( struct V_15 ) , & V_35 ) ;
if ( V_55 < 0 )
return V_55 ;
V_15 = V_35 -> V_54 ;
if ( V_181 [ V_127 ] < 1 )
V_181 [ V_127 ] = 1 ;
if ( V_181 [ V_127 ] > V_175 )
V_181 [ V_127 ] = V_175 ;
V_15 -> V_35 = V_35 ;
F_87 ( & V_15 -> V_80 ) ;
V_55 = F_58 ( V_15 , 0 , V_181 [ V_127 ] ) ;
if ( V_55 < 0 )
goto V_182;
V_55 = F_58 ( V_15 , 1 , V_181 [ V_127 ] ) ;
if ( V_55 < 0 )
goto V_182;
V_55 = F_74 ( V_15 , V_183 [ V_127 ] ? 1 : 0 ) ;
if ( V_55 < 0 )
goto V_182;
F_82 ( V_15 , 0 ) ;
F_82 ( V_15 , 1 ) ;
strcpy ( V_35 -> V_184 , L_25 ) ;
strcpy ( V_35 -> V_185 , L_25 ) ;
sprintf ( V_35 -> V_186 , L_26 , V_127 + 1 ) ;
V_55 = F_88 ( V_35 ) ;
if ( ! V_55 ) {
F_89 ( V_178 , V_35 ) ;
return 0 ;
}
V_182:
F_90 ( V_35 ) ;
return V_55 ;
}
static int T_3 F_91 ( struct V_177 * V_178 )
{
F_90 ( F_92 ( V_178 ) ) ;
F_89 ( V_178 , NULL ) ;
return 0 ;
}
static int F_93 ( struct V_177 * V_187 ,
T_4 V_91 )
{
struct V_34 * V_35 = F_92 ( V_187 ) ;
struct V_15 * V_15 = V_35 -> V_54 ;
F_94 ( V_35 , V_188 ) ;
F_95 ( V_15 -> V_12 [ 0 ] ) ;
F_95 ( V_15 -> V_12 [ 1 ] ) ;
return 0 ;
}
static int F_96 ( struct V_177 * V_187 )
{
struct V_34 * V_35 = F_92 ( V_187 ) ;
F_94 ( V_35 , V_189 ) ;
return 0 ;
}
static void F_97 ( void )
{
int V_190 ;
for ( V_190 = 0 ; V_190 < F_75 ( V_191 ) ; ++ V_190 )
F_98 ( V_191 [ V_190 ] ) ;
F_99 ( & V_192 ) ;
}
static int T_5 F_100 ( void )
{
int V_190 , V_55 , V_193 ;
V_55 = F_101 ( & V_192 ) ;
if ( V_55 < 0 )
return V_55 ;
V_193 = 0 ;
for ( V_190 = 0 ; V_190 < V_194 ; V_190 ++ ) {
struct V_177 * V_9 ;
if ( ! V_195 [ V_190 ] )
continue;
V_9 = F_102 ( V_196 ,
V_190 , NULL , 0 ) ;
if ( F_103 ( V_9 ) )
continue;
if ( ! F_92 ( V_9 ) ) {
F_98 ( V_9 ) ;
continue;
}
V_191 [ V_190 ] = V_9 ;
V_193 ++ ;
}
if ( ! V_193 ) {
#ifdef F_104
F_105 ( V_197 L_27 ) ;
#endif
F_97 () ;
return - V_198 ;
}
return 0 ;
}
static void T_6 F_106 ( void )
{
F_97 () ;
}
