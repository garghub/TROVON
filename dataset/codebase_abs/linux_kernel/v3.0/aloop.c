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
return F_40 ( V_10 , F_41 ( V_110 ) ) ;
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
F_61 ( V_12 , V_143 ,
F_62 ( V_128 ) ,
0 , 2 * 1024 * 1024 ) ;
return 0 ;
}
static int F_63 ( struct V_144 * V_145 ,
struct V_146 * V_147 )
{
V_147 -> type = V_148 ;
V_147 -> V_97 = 1 ;
V_147 -> V_149 . integer . V_123 = 80000 ;
V_147 -> V_149 . integer . V_124 = 120000 ;
V_147 -> V_149 . integer . V_150 = 1 ;
return 0 ;
}
static int F_64 ( struct V_144 * V_145 ,
struct V_151 * V_152 )
{
struct V_15 * V_15 = F_65 ( V_145 ) ;
V_152 -> V_149 . integer . V_149 [ 0 ] =
V_15 -> V_16 [ V_145 -> V_153 . V_154 ]
[ V_145 -> V_153 . V_9 ] . V_19 ;
return 0 ;
}
static int F_66 ( struct V_144 * V_145 ,
struct V_151 * V_152 )
{
struct V_15 * V_15 = F_65 ( V_145 ) ;
unsigned int V_155 ;
int V_156 = 0 ;
V_155 = V_152 -> V_149 . integer . V_149 [ 0 ] ;
if ( V_155 < 80000 )
V_155 = 80000 ;
if ( V_155 > 120000 )
V_155 = 120000 ;
F_24 ( & V_15 -> V_80 ) ;
if ( V_155 != V_15 -> V_16 [ V_145 -> V_153 . V_154 ]
[ V_145 -> V_153 . V_9 ] . V_19 ) {
V_15 -> V_16 [ V_145 -> V_153 . V_154 ]
[ V_145 -> V_153 . V_9 ] . V_19 = V_155 ;
V_156 = 1 ;
}
F_25 ( & V_15 -> V_80 ) ;
return V_156 ;
}
static int F_67 ( struct V_144 * V_145 ,
struct V_151 * V_152 )
{
struct V_15 * V_15 = F_65 ( V_145 ) ;
V_152 -> V_149 . integer . V_149 [ 0 ] =
V_15 -> V_16 [ V_145 -> V_153 . V_154 ]
[ V_145 -> V_153 . V_9 ] . V_18 ;
return 0 ;
}
static int F_68 ( struct V_144 * V_145 ,
struct V_151 * V_152 )
{
struct V_15 * V_15 = F_65 ( V_145 ) ;
unsigned int V_155 ;
int V_156 = 0 ;
V_155 = V_152 -> V_149 . integer . V_149 [ 0 ] ? 1 : 0 ;
if ( V_155 != V_15 -> V_16 [ V_145 -> V_153 . V_154 ]
[ V_145 -> V_153 . V_9 ] . V_18 ) {
V_15 -> V_16 [ V_145 -> V_153 . V_154 ]
[ V_145 -> V_153 . V_9 ] . V_18 = V_155 ;
V_156 = 1 ;
}
return V_156 ;
}
static int F_69 ( struct V_144 * V_145 ,
struct V_151 * V_152 )
{
struct V_15 * V_15 = F_65 ( V_145 ) ;
struct V_29 * V_30 = V_15 -> V_130
[ V_145 -> V_153 . V_154 ] [ V_145 -> V_153 . V_9 ^ 1 ] ;
unsigned int V_155 = 0 ;
if ( V_30 != NULL )
V_155 = ( V_30 -> V_59 & ( 1 << V_14 ) ) ?
1 : 0 ;
V_152 -> V_149 . integer . V_149 [ 0 ] = V_155 ;
return 0 ;
}
static int F_70 ( struct V_144 * V_145 ,
struct V_146 * V_147 )
{
V_147 -> type = V_148 ;
V_147 -> V_97 = 1 ;
V_147 -> V_149 . integer . V_123 = 0 ;
V_147 -> V_149 . integer . V_124 = V_157 ;
V_147 -> V_149 . integer . V_150 = 1 ;
return 0 ;
}
static int F_71 ( struct V_144 * V_145 ,
struct V_151 * V_152 )
{
struct V_15 * V_15 = F_65 ( V_145 ) ;
V_152 -> V_149 . integer . V_149 [ 0 ] =
V_15 -> V_16 [ V_145 -> V_153 . V_154 ]
[ V_145 -> V_153 . V_9 ] . V_42 ;
return 0 ;
}
static int F_72 ( struct V_144 * V_145 ,
struct V_146 * V_147 )
{
V_147 -> type = V_148 ;
V_147 -> V_97 = 1 ;
V_147 -> V_149 . integer . V_123 = 0 ;
V_147 -> V_149 . integer . V_124 = 192000 ;
V_147 -> V_149 . integer . V_150 = 1 ;
return 0 ;
}
static int F_73 ( struct V_144 * V_145 ,
struct V_151 * V_152 )
{
struct V_15 * V_15 = F_65 ( V_145 ) ;
V_152 -> V_149 . integer . V_149 [ 0 ] =
V_15 -> V_16 [ V_145 -> V_153 . V_154 ]
[ V_145 -> V_153 . V_9 ] . V_43 ;
return 0 ;
}
static int F_74 ( struct V_144 * V_145 ,
struct V_146 * V_147 )
{
V_147 -> type = V_148 ;
V_147 -> V_97 = 1 ;
V_147 -> V_149 . integer . V_123 = 1 ;
V_147 -> V_149 . integer . V_124 = 1024 ;
V_147 -> V_149 . integer . V_150 = 1 ;
return 0 ;
}
static int F_75 ( struct V_144 * V_145 ,
struct V_151 * V_152 )
{
struct V_15 * V_15 = F_65 ( V_145 ) ;
V_152 -> V_149 . integer . V_149 [ 0 ] =
V_15 -> V_16 [ V_145 -> V_153 . V_154 ]
[ V_145 -> V_153 . V_9 ] . V_44 ;
return 0 ;
}
static int T_2 F_76 ( struct V_15 * V_15 , int V_18 )
{
struct V_34 * V_35 = V_15 -> V_35 ;
struct V_138 * V_12 ;
struct V_144 * V_158 ;
struct V_8 * V_16 ;
int V_55 , V_127 , V_159 , V_160 , V_161 ;
strcpy ( V_35 -> V_162 , L_2 ) ;
for ( V_127 = 0 ; V_127 < 2 ; V_127 ++ ) {
V_12 = V_15 -> V_12 [ V_127 ] ;
V_160 =
V_12 -> V_40 [ V_41 ] . V_163 ;
for ( V_159 = 0 ; V_159 < V_160 ; V_159 ++ ) {
V_16 = & V_15 -> V_16 [ V_159 ] [ V_127 ] ;
V_16 -> V_18 = V_18 ;
V_16 -> V_19 = V_5 ;
V_16 -> V_42 = V_164 ;
V_16 -> V_43 = 48000 ;
V_16 -> V_44 = 2 ;
for ( V_161 = 0 ; V_161 < F_77 ( V_165 ) ;
V_161 ++ ) {
V_158 = F_78 ( & V_165 [ V_161 ] ,
V_15 ) ;
if ( ! V_158 )
return - V_129 ;
V_158 -> V_153 . V_9 = V_127 ;
V_158 -> V_153 . V_154 = V_159 ;
switch ( V_161 ) {
case V_166 :
V_16 -> V_51 = V_158 -> V_153 ;
break;
case V_167 :
V_16 -> V_48 = V_158 -> V_153 ;
break;
case V_168 :
V_16 -> V_49 = V_158 -> V_153 ;
break;
case V_169 :
V_16 -> V_50 = V_158 -> V_153 ;
break;
default:
break;
}
V_55 = F_79 ( V_35 , V_158 ) ;
if ( V_55 < 0 )
return V_55 ;
}
}
}
return 0 ;
}
static void F_80 ( struct V_170 * V_171 ,
struct V_1 * V_2 ,
const char * V_153 )
{
F_81 ( V_171 , L_3 , V_153 ) ;
if ( V_2 == NULL ) {
F_81 ( V_171 , L_4 ) ;
return;
}
F_81 ( V_171 , L_5 , V_2 -> V_75 ) ;
F_81 ( V_171 , L_6 , V_2 -> V_74 ) ;
F_81 ( V_171 , L_7 , V_2 -> V_77 ) ;
F_81 ( V_171 , L_8 , V_2 -> V_22 ) ;
F_81 ( V_171 , L_9 , V_2 -> V_25 ) ;
F_81 ( V_171 , L_10 , V_2 -> V_7 ) ;
F_81 ( V_171 , L_11 , V_2 -> V_4 ) ;
F_81 ( V_171 , L_12 ,
V_2 -> V_24 ) ;
F_81 ( V_171 , L_13 , V_2 -> V_23 ) ;
F_81 ( V_171 , L_14 , V_2 -> V_21 ) ;
F_81 ( V_171 , L_15 ,
V_2 -> V_57 , V_28 ) ;
F_81 ( V_171 , L_16 , V_2 -> V_26 . V_27 ) ;
}
static void F_82 ( struct V_170 * V_171 ,
struct V_15 * V_15 ,
int V_172 ,
int V_173 )
{
struct V_29 * V_30 = V_15 -> V_130 [ V_172 ] [ V_173 ] ;
F_81 ( V_171 , L_17 , V_173 , V_172 ) ;
if ( V_30 == NULL ) {
F_81 ( V_171 , L_18 ) ;
return;
}
F_81 ( V_171 , L_19 , V_30 -> V_37 ) ;
F_81 ( V_171 , L_20 , V_30 -> V_59 ) ;
F_81 ( V_171 , L_21 , V_30 -> V_60 ) ;
F_80 ( V_171 , V_30 -> V_40 [ 0 ] , L_22 ) ;
F_80 ( V_171 , V_30 -> V_40 [ 1 ] , L_23 ) ;
}
static void F_83 ( struct V_174 * V_175 ,
struct V_170 * V_171 )
{
struct V_15 * V_15 = V_175 -> V_54 ;
int V_172 , V_173 ;
F_24 ( & V_15 -> V_80 ) ;
V_173 = V_175 -> V_142 [ strlen ( V_175 -> V_142 ) - 1 ] ;
V_173 = V_173 == '0' ? 0 : 1 ;
for ( V_172 = 0 ; V_172 < V_176 ; V_172 ++ )
F_82 ( V_171 , V_15 , V_172 , V_173 ) ;
F_25 ( & V_15 -> V_80 ) ;
}
static int T_2 F_84 ( struct V_15 * V_15 , int V_177 )
{
char V_142 [ 32 ] ;
struct V_174 * V_175 ;
int V_55 ;
snprintf ( V_142 , sizeof( V_142 ) , L_24 , V_177 ) ;
V_55 = F_85 ( V_15 -> V_35 , V_142 , & V_175 ) ;
if ( V_55 < 0 )
return V_55 ;
F_86 ( V_175 , V_15 , F_83 ) ;
return 0 ;
}
static int T_2 F_87 ( struct V_178 * V_179 )
{
struct V_34 * V_35 ;
struct V_15 * V_15 ;
int V_127 = V_179 -> V_153 ;
int V_55 ;
V_55 = F_88 ( V_180 [ V_127 ] , V_153 [ V_127 ] , V_181 ,
sizeof( struct V_15 ) , & V_35 ) ;
if ( V_55 < 0 )
return V_55 ;
V_15 = V_35 -> V_54 ;
if ( V_182 [ V_127 ] < 1 )
V_182 [ V_127 ] = 1 ;
if ( V_182 [ V_127 ] > V_176 )
V_182 [ V_127 ] = V_176 ;
V_15 -> V_35 = V_35 ;
F_89 ( & V_15 -> V_80 ) ;
V_55 = F_58 ( V_15 , 0 , V_182 [ V_127 ] ) ;
if ( V_55 < 0 )
goto V_183;
V_55 = F_58 ( V_15 , 1 , V_182 [ V_127 ] ) ;
if ( V_55 < 0 )
goto V_183;
V_55 = F_76 ( V_15 , V_184 [ V_127 ] ? 1 : 0 ) ;
if ( V_55 < 0 )
goto V_183;
F_84 ( V_15 , 0 ) ;
F_84 ( V_15 , 1 ) ;
strcpy ( V_35 -> V_185 , L_25 ) ;
strcpy ( V_35 -> V_186 , L_25 ) ;
sprintf ( V_35 -> V_187 , L_26 , V_127 + 1 ) ;
V_55 = F_90 ( V_35 ) ;
if ( ! V_55 ) {
F_91 ( V_179 , V_35 ) ;
return 0 ;
}
V_183:
F_92 ( V_35 ) ;
return V_55 ;
}
static int T_3 F_93 ( struct V_178 * V_179 )
{
F_92 ( F_94 ( V_179 ) ) ;
F_91 ( V_179 , NULL ) ;
return 0 ;
}
static int F_95 ( struct V_178 * V_188 ,
T_4 V_91 )
{
struct V_34 * V_35 = F_94 ( V_188 ) ;
struct V_15 * V_15 = V_35 -> V_54 ;
F_96 ( V_35 , V_189 ) ;
F_97 ( V_15 -> V_12 [ 0 ] ) ;
F_97 ( V_15 -> V_12 [ 1 ] ) ;
return 0 ;
}
static int F_98 ( struct V_178 * V_188 )
{
struct V_34 * V_35 = F_94 ( V_188 ) ;
F_96 ( V_35 , V_190 ) ;
return 0 ;
}
static void F_99 ( void )
{
int V_191 ;
for ( V_191 = 0 ; V_191 < F_77 ( V_192 ) ; ++ V_191 )
F_100 ( V_192 [ V_191 ] ) ;
F_101 ( & V_193 ) ;
}
static int T_5 F_102 ( void )
{
int V_191 , V_55 , V_194 ;
V_55 = F_103 ( & V_193 ) ;
if ( V_55 < 0 )
return V_55 ;
V_194 = 0 ;
for ( V_191 = 0 ; V_191 < V_195 ; V_191 ++ ) {
struct V_178 * V_9 ;
if ( ! V_196 [ V_191 ] )
continue;
V_9 = F_104 ( V_197 ,
V_191 , NULL , 0 ) ;
if ( F_105 ( V_9 ) )
continue;
if ( ! F_94 ( V_9 ) ) {
F_100 ( V_9 ) ;
continue;
}
V_192 [ V_191 ] = V_9 ;
V_194 ++ ;
}
if ( ! V_194 ) {
#ifdef F_106
F_107 ( V_198 L_27 ) ;
#endif
F_99 () ;
return - V_199 ;
}
return 0 ;
}
static void T_6 F_108 ( void )
{
F_99 () ;
}
