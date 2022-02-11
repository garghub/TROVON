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
V_2 -> V_58 = 0 ;
F_16 ( & V_30 -> V_59 ) ;
V_30 -> V_60 |= V_13 ;
V_30 -> V_61 &= ~ V_13 ;
F_7 ( V_2 ) ;
F_17 ( & V_30 -> V_59 ) ;
if ( V_10 -> V_13 == V_14 )
F_14 ( V_2 ) ;
break;
case V_62 :
F_16 ( & V_30 -> V_59 ) ;
V_30 -> V_60 &= ~ V_13 ;
V_30 -> V_61 &= ~ V_13 ;
F_9 ( V_2 ) ;
F_17 ( & V_30 -> V_59 ) ;
if ( V_10 -> V_13 == V_14 )
F_14 ( V_2 ) ;
break;
case V_63 :
F_16 ( & V_30 -> V_59 ) ;
V_30 -> V_61 |= V_13 ;
F_9 ( V_2 ) ;
F_17 ( & V_30 -> V_59 ) ;
break;
case V_64 :
F_16 ( & V_30 -> V_59 ) ;
V_2 -> V_57 = V_28 ;
V_30 -> V_61 &= ~ V_13 ;
F_7 ( V_2 ) ;
F_17 ( & V_30 -> V_59 ) ;
break;
default:
return - V_65 ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_31 * V_66 ;
if ( V_2 == NULL || V_2 -> V_10 == NULL )
return;
V_66 = V_2 -> V_10 -> V_32 ;
if ( V_66 == NULL )
return;
V_66 -> V_67 = V_2 -> V_30 -> V_67 ;
}
static void F_19 ( struct V_52 * V_10 )
{
struct V_31 * V_32 = V_10 -> V_32 ;
struct V_1 * V_2 = V_32 -> V_54 ;
struct V_29 * V_30 = V_2 -> V_30 ;
V_30 -> V_67 . V_68 = ( 1ULL << V_32 -> V_42 ) ;
V_30 -> V_67 . V_69 = V_32 -> V_43 ;
V_30 -> V_67 . V_70 = V_32 -> V_43 ;
V_30 -> V_67 . V_71 = V_32 -> V_44 ;
V_30 -> V_67 . V_72 = V_32 -> V_44 ;
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
int V_73 , V_74 ;
V_74 = ( F_21 ( V_32 -> V_42 ) *
V_32 -> V_44 ) / 8 ;
V_73 = V_74 * V_32 -> V_43 ;
if ( V_73 <= 0 || V_74 <= 0 )
return - V_65 ;
V_2 -> V_75 = 0 ;
V_2 -> V_76 = F_22 ( V_32 , V_32 -> V_77 ) ;
if ( V_10 -> V_13 == V_41 ) {
V_2 -> V_78 = V_2 -> V_76 ;
F_23 ( V_32 -> V_42 , V_32 -> V_79 ,
V_32 -> V_77 * V_32 -> V_44 ) ;
}
V_2 -> V_23 = 0 ;
V_2 -> V_24 = 0 ;
V_2 -> V_25 = V_73 ;
V_2 -> V_7 = V_74 ;
V_2 -> V_22 = F_22 ( V_32 , V_32 -> V_80 ) ;
F_24 ( & V_2 -> V_15 -> V_81 ) ;
if ( ! ( V_30 -> V_37 & ~ ( 1 << V_10 -> V_13 ) ) ||
( F_4 ( V_2 ) -> V_18 &&
V_10 -> V_13 == V_14 ) )
F_19 ( V_10 ) ;
V_30 -> V_37 |= 1 << V_10 -> V_13 ;
F_25 ( & V_2 -> V_15 -> V_81 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 , unsigned int V_82 )
{
struct V_31 * V_32 = V_2 -> V_10 -> V_32 ;
char * V_83 = V_32 -> V_79 ;
unsigned int V_84 = V_2 -> V_75 ;
if ( V_2 -> V_78 >= V_2 -> V_76 )
return;
if ( V_2 -> V_78 + V_82 > V_2 -> V_76 )
V_82 = V_2 -> V_76 - V_2 -> V_78 ;
for (; ; ) {
unsigned int V_85 = V_82 ;
if ( V_84 + V_85 > V_2 -> V_76 )
V_85 = V_2 -> V_76 - V_84 ;
F_23 ( V_32 -> V_42 , V_83 + V_84 ,
F_27 ( V_32 , V_85 ) *
V_32 -> V_44 ) ;
V_2 -> V_78 += V_85 ;
V_82 -= V_85 ;
if ( ! V_82 )
break;
V_84 = 0 ;
}
}
static void F_28 ( struct V_1 * V_86 ,
struct V_1 * V_87 ,
unsigned int V_82 )
{
struct V_31 * V_32 = V_86 -> V_10 -> V_32 ;
char * V_88 = V_32 -> V_79 ;
char * V_83 = V_87 -> V_10 -> V_32 -> V_79 ;
unsigned int V_89 = V_86 -> V_75 ;
unsigned int V_84 = V_87 -> V_75 ;
unsigned int V_90 = 0 ;
if ( V_32 -> V_91 -> V_92 == V_46 &&
F_29 ( V_32 ) < V_32 -> V_77 ) {
T_1 V_93 , V_94 , V_95 ;
V_93 = V_94 = V_32 -> V_96 -> V_93 ;
V_94 -= V_94 % V_32 -> V_77 ;
V_94 += V_86 -> V_75 / V_86 -> V_7 ;
if ( V_93 < V_94 )
V_94 -= V_32 -> V_77 ;
V_95 = ( V_93 - V_94 ) * V_86 -> V_7 ;
if ( V_95 < V_82 ) {
V_90 = V_82 - V_95 ;
V_82 = V_95 ;
}
}
for (; ; ) {
unsigned int V_85 = V_82 ;
if ( V_89 + V_85 > V_86 -> V_76 )
V_85 = V_86 -> V_76 - V_89 ;
if ( V_84 + V_85 > V_87 -> V_76 )
V_85 = V_87 -> V_76 - V_84 ;
memcpy ( V_83 + V_84 , V_88 + V_89 , V_85 ) ;
V_87 -> V_78 = 0 ;
V_82 -= V_85 ;
if ( ! V_82 )
break;
V_89 = ( V_89 + V_85 ) % V_86 -> V_76 ;
V_84 = ( V_84 + V_85 ) % V_87 -> V_76 ;
}
if ( V_90 > 0 ) {
F_26 ( V_87 , V_90 ) ;
V_87 -> V_78 = 0 ;
}
}
static inline unsigned int F_30 ( struct V_1 * V_2 ,
unsigned int V_97 )
{
unsigned long V_98 ;
unsigned int V_99 ;
V_98 = F_1 ( V_2 , V_2 -> V_23 ) ;
V_2 -> V_23 += V_97 * V_2 -> V_25 ;
V_99 = F_1 ( V_2 , V_2 -> V_23 ) - V_98 ;
if ( V_99 >= V_2 -> V_58 )
V_99 -= V_2 -> V_58 ;
V_2 -> V_58 = 0 ;
if ( V_2 -> V_23 >= V_2 -> V_21 ) {
V_2 -> V_23 %= V_2 -> V_21 ;
V_2 -> V_24 = 1 ;
}
return V_99 ;
}
static inline void F_31 ( struct V_1 * V_2 ,
unsigned int V_99 )
{
V_2 -> V_75 += V_99 ;
V_2 -> V_75 %= V_2 -> V_76 ;
}
static unsigned int F_32 ( struct V_29 * V_30 )
{
struct V_1 * V_100 =
V_30 -> V_40 [ V_14 ] ;
struct V_1 * V_101 =
V_30 -> V_40 [ V_41 ] ;
unsigned long V_102 = 0 , V_103 = 0 ;
unsigned int V_60 , V_104 , V_105 ;
V_60 = V_30 -> V_60 ^ V_30 -> V_61 ;
if ( V_60 & ( 1 << V_14 ) ) {
V_102 = V_28 - V_100 -> V_57 ;
V_100 -> V_57 += V_102 ;
}
if ( V_60 & ( 1 << V_41 ) ) {
V_103 = V_28 - V_101 -> V_57 ;
V_101 -> V_57 += V_103 ;
}
if ( V_102 == 0 && V_103 == 0 )
goto V_106;
if ( V_102 > V_103 ) {
V_104 = F_30 ( V_100 , V_102 - V_103 ) ;
F_31 ( V_100 , V_104 ) ;
V_102 = V_103 ;
} else if ( V_102 < V_103 ) {
V_104 = F_30 ( V_101 , V_103 - V_102 ) ;
F_26 ( V_101 , V_104 ) ;
F_31 ( V_101 , V_104 ) ;
V_103 = V_102 ;
}
if ( V_102 == 0 && V_103 == 0 )
goto V_106;
V_104 = F_30 ( V_100 , V_102 ) ;
V_105 = F_30 ( V_101 , V_103 ) ;
if ( V_104 < V_105 ) {
V_101 -> V_58 = V_105 - V_104 ;
V_104 = V_105 ;
} else if ( V_104 > V_105 ) {
V_100 -> V_58 = V_104 - V_105 ;
}
F_28 ( V_100 , V_101 , V_104 ) ;
F_31 ( V_100 , V_104 ) ;
F_31 ( V_101 , V_104 ) ;
V_106:
return V_60 ;
}
static void F_33 ( unsigned long V_107 )
{
struct V_1 * V_2 = (struct V_1 * ) V_107 ;
unsigned long V_108 ;
F_34 ( & V_2 -> V_30 -> V_59 , V_108 ) ;
if ( F_32 ( V_2 -> V_30 ) & ( 1 << V_2 -> V_10 -> V_13 ) ) {
F_7 ( V_2 ) ;
if ( V_2 -> V_24 ) {
V_2 -> V_24 = 0 ;
F_35 ( & V_2 -> V_30 -> V_59 , V_108 ) ;
F_36 ( V_2 -> V_10 ) ;
return;
}
}
F_35 ( & V_2 -> V_30 -> V_59 , V_108 ) ;
}
static T_1 F_37 ( struct V_52 * V_10 )
{
struct V_31 * V_32 = V_10 -> V_32 ;
struct V_1 * V_2 = V_32 -> V_54 ;
T_1 V_109 ;
F_16 ( & V_2 -> V_30 -> V_59 ) ;
F_32 ( V_2 -> V_30 ) ;
V_109 = V_2 -> V_75 ;
F_17 ( & V_2 -> V_30 -> V_59 ) ;
return F_27 ( V_32 , V_109 ) ;
}
static void F_38 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_54 ;
F_39 ( V_2 ) ;
}
static int F_40 ( struct V_52 * V_10 ,
struct V_110 * V_111 )
{
return F_41 ( V_10 ,
F_42 ( V_111 ) ) ;
}
static int F_43 ( struct V_52 * V_10 )
{
struct V_31 * V_32 = V_10 -> V_32 ;
struct V_1 * V_2 = V_32 -> V_54 ;
struct V_29 * V_30 = V_2 -> V_30 ;
F_24 ( & V_2 -> V_15 -> V_81 ) ;
V_30 -> V_37 &= ~ ( 1 << V_10 -> V_13 ) ;
F_25 ( & V_2 -> V_15 -> V_81 ) ;
return F_44 ( V_10 ) ;
}
static unsigned int F_45 ( struct V_52 * V_10 )
{
if ( ! V_10 -> V_12 -> V_9 )
return V_10 -> V_13 ;
else
return ! V_10 -> V_13 ;
}
static int F_46 ( struct V_110 * V_111 ,
struct V_112 * V_113 )
{
struct V_114 * V_67 = V_113 -> V_115 ;
struct V_116 * V_117 = F_47 ( V_111 , V_113 -> V_118 ) ;
V_117 -> V_119 [ 0 ] &= ( V_120 ) V_67 -> V_68 ;
V_117 -> V_119 [ 1 ] &= ( V_120 ) ( V_67 -> V_68 >> 32 ) ;
memset ( V_117 -> V_119 + 2 , 0 , ( V_121 - 64 ) / 8 ) ;
if ( ! V_117 -> V_119 [ 0 ] && ! V_117 -> V_119 [ 1 ] )
return - V_65 ;
return 0 ;
}
static int F_48 ( struct V_110 * V_111 ,
struct V_112 * V_113 )
{
struct V_114 * V_67 = V_113 -> V_115 ;
struct V_122 V_123 ;
V_123 . V_124 = V_67 -> V_69 ;
V_123 . V_125 = V_67 -> V_70 ;
V_123 . V_126 = V_123 . V_127 = 0 ;
V_123 . integer = 0 ;
return F_49 ( F_50 ( V_111 , V_113 -> V_118 ) , & V_123 ) ;
}
static int F_51 ( struct V_110 * V_111 ,
struct V_112 * V_113 )
{
struct V_114 * V_67 = V_113 -> V_115 ;
struct V_122 V_123 ;
V_123 . V_124 = V_67 -> V_71 ;
V_123 . V_125 = V_67 -> V_72 ;
V_123 . V_126 = V_123 . V_127 = 0 ;
V_123 . integer = 0 ;
return F_49 ( F_50 ( V_111 , V_113 -> V_118 ) , & V_123 ) ;
}
static int F_52 ( struct V_52 * V_10 )
{
struct V_31 * V_32 = V_10 -> V_32 ;
struct V_15 * V_15 = V_10 -> V_54 ;
struct V_1 * V_2 ;
struct V_29 * V_30 ;
int V_55 = 0 ;
int V_128 = F_45 ( V_10 ) ;
F_24 ( & V_15 -> V_81 ) ;
V_2 = F_53 ( sizeof( * V_2 ) , V_129 ) ;
if ( ! V_2 ) {
V_55 = - V_130 ;
goto V_106;
}
V_2 -> V_15 = V_15 ;
V_2 -> V_10 = V_10 ;
F_54 ( & V_2 -> V_26 , F_33 ,
( unsigned long ) V_2 ) ;
V_30 = V_15 -> V_131 [ V_10 -> V_17 ] [ V_128 ] ;
if ( ! V_30 ) {
V_30 = F_53 ( sizeof( * V_30 ) , V_129 ) ;
if ( ! V_30 ) {
F_39 ( V_2 ) ;
V_55 = - V_130 ;
goto V_106;
}
F_55 ( & V_30 -> V_59 ) ;
V_30 -> V_67 = V_132 ;
V_15 -> V_131 [ V_10 -> V_17 ] [ V_128 ] = V_30 ;
}
V_2 -> V_30 = V_30 ;
V_30 -> V_40 [ V_10 -> V_13 ] = V_2 ;
F_56 ( V_32 , V_133 ) ;
V_55 = F_57 ( V_32 , 0 ,
V_134 ,
F_46 , & V_32 -> V_67 ,
V_134 , - 1 ) ;
if ( V_55 < 0 )
goto V_106;
V_55 = F_57 ( V_32 , 0 ,
V_135 ,
F_48 , & V_32 -> V_67 ,
V_135 , - 1 ) ;
if ( V_55 < 0 )
goto V_106;
V_55 = F_57 ( V_32 , 0 ,
V_136 ,
F_51 , & V_32 -> V_67 ,
V_136 , - 1 ) ;
if ( V_55 < 0 )
goto V_106;
V_32 -> V_54 = V_2 ;
V_32 -> V_137 = F_38 ;
if ( F_5 ( V_2 ) )
V_32 -> V_67 = V_132 ;
else
V_32 -> V_67 = V_30 -> V_67 ;
V_106:
F_25 ( & V_15 -> V_81 ) ;
return V_55 ;
}
static int F_58 ( struct V_52 * V_10 )
{
struct V_15 * V_15 = V_10 -> V_54 ;
struct V_1 * V_2 = V_10 -> V_32 -> V_54 ;
struct V_29 * V_30 ;
int V_128 = F_45 ( V_10 ) ;
F_9 ( V_2 ) ;
F_24 ( & V_15 -> V_81 ) ;
V_30 = V_15 -> V_131 [ V_10 -> V_17 ] [ V_128 ] ;
if ( V_30 -> V_40 [ ! V_10 -> V_13 ] ) {
V_30 -> V_40 [ V_10 -> V_13 ] = NULL ;
} else {
V_15 -> V_131 [ V_10 -> V_17 ] [ V_128 ] = NULL ;
F_39 ( V_30 ) ;
}
F_25 ( & V_15 -> V_81 ) ;
return 0 ;
}
static int F_59 ( struct V_15 * V_15 ,
int V_9 , int V_138 )
{
struct V_139 * V_12 ;
int V_55 ;
V_55 = F_60 ( V_15 -> V_35 , L_1 , V_9 ,
V_138 , V_138 , & V_12 ) ;
if ( V_55 < 0 )
return V_55 ;
F_61 ( V_12 , V_14 , & V_140 ) ;
F_61 ( V_12 , V_41 , & V_141 ) ;
V_12 -> V_54 = V_15 ;
V_12 -> V_142 = 0 ;
strcpy ( V_12 -> V_143 , L_1 ) ;
V_15 -> V_12 [ V_9 ] = V_12 ;
return 0 ;
}
static int F_62 ( struct V_144 * V_145 ,
struct V_146 * V_147 )
{
V_147 -> type = V_148 ;
V_147 -> V_149 = 1 ;
V_147 -> V_150 . integer . V_124 = 80000 ;
V_147 -> V_150 . integer . V_125 = 120000 ;
V_147 -> V_150 . integer . V_151 = 1 ;
return 0 ;
}
static int F_63 ( struct V_144 * V_145 ,
struct V_152 * V_153 )
{
struct V_15 * V_15 = F_64 ( V_145 ) ;
V_153 -> V_150 . integer . V_150 [ 0 ] =
V_15 -> V_16 [ V_145 -> V_154 . V_155 ]
[ V_145 -> V_154 . V_9 ] . V_19 ;
return 0 ;
}
static int F_65 ( struct V_144 * V_145 ,
struct V_152 * V_153 )
{
struct V_15 * V_15 = F_64 ( V_145 ) ;
unsigned int V_156 ;
int V_157 = 0 ;
V_156 = V_153 -> V_150 . integer . V_150 [ 0 ] ;
if ( V_156 < 80000 )
V_156 = 80000 ;
if ( V_156 > 120000 )
V_156 = 120000 ;
F_24 ( & V_15 -> V_81 ) ;
if ( V_156 != V_15 -> V_16 [ V_145 -> V_154 . V_155 ]
[ V_145 -> V_154 . V_9 ] . V_19 ) {
V_15 -> V_16 [ V_145 -> V_154 . V_155 ]
[ V_145 -> V_154 . V_9 ] . V_19 = V_156 ;
V_157 = 1 ;
}
F_25 ( & V_15 -> V_81 ) ;
return V_157 ;
}
static int F_66 ( struct V_144 * V_145 ,
struct V_152 * V_153 )
{
struct V_15 * V_15 = F_64 ( V_145 ) ;
V_153 -> V_150 . integer . V_150 [ 0 ] =
V_15 -> V_16 [ V_145 -> V_154 . V_155 ]
[ V_145 -> V_154 . V_9 ] . V_18 ;
return 0 ;
}
static int F_67 ( struct V_144 * V_145 ,
struct V_152 * V_153 )
{
struct V_15 * V_15 = F_64 ( V_145 ) ;
unsigned int V_156 ;
int V_157 = 0 ;
V_156 = V_153 -> V_150 . integer . V_150 [ 0 ] ? 1 : 0 ;
if ( V_156 != V_15 -> V_16 [ V_145 -> V_154 . V_155 ]
[ V_145 -> V_154 . V_9 ] . V_18 ) {
V_15 -> V_16 [ V_145 -> V_154 . V_155 ]
[ V_145 -> V_154 . V_9 ] . V_18 = V_156 ;
V_157 = 1 ;
}
return V_157 ;
}
static int F_68 ( struct V_144 * V_145 ,
struct V_152 * V_153 )
{
struct V_15 * V_15 = F_64 ( V_145 ) ;
struct V_29 * V_30 = V_15 -> V_131
[ V_145 -> V_154 . V_155 ] [ V_145 -> V_154 . V_9 ^ 1 ] ;
unsigned int V_156 = 0 ;
if ( V_30 != NULL )
V_156 = ( V_30 -> V_60 & ( 1 << V_14 ) ) ?
1 : 0 ;
V_153 -> V_150 . integer . V_150 [ 0 ] = V_156 ;
return 0 ;
}
static int F_69 ( struct V_144 * V_145 ,
struct V_146 * V_147 )
{
V_147 -> type = V_148 ;
V_147 -> V_149 = 1 ;
V_147 -> V_150 . integer . V_124 = 0 ;
V_147 -> V_150 . integer . V_125 = V_158 ;
V_147 -> V_150 . integer . V_151 = 1 ;
return 0 ;
}
static int F_70 ( struct V_144 * V_145 ,
struct V_152 * V_153 )
{
struct V_15 * V_15 = F_64 ( V_145 ) ;
V_153 -> V_150 . integer . V_150 [ 0 ] =
V_15 -> V_16 [ V_145 -> V_154 . V_155 ]
[ V_145 -> V_154 . V_9 ] . V_42 ;
return 0 ;
}
static int F_71 ( struct V_144 * V_145 ,
struct V_146 * V_147 )
{
V_147 -> type = V_148 ;
V_147 -> V_149 = 1 ;
V_147 -> V_150 . integer . V_124 = 0 ;
V_147 -> V_150 . integer . V_125 = 192000 ;
V_147 -> V_150 . integer . V_151 = 1 ;
return 0 ;
}
static int F_72 ( struct V_144 * V_145 ,
struct V_152 * V_153 )
{
struct V_15 * V_15 = F_64 ( V_145 ) ;
V_153 -> V_150 . integer . V_150 [ 0 ] =
V_15 -> V_16 [ V_145 -> V_154 . V_155 ]
[ V_145 -> V_154 . V_9 ] . V_43 ;
return 0 ;
}
static int F_73 ( struct V_144 * V_145 ,
struct V_146 * V_147 )
{
V_147 -> type = V_148 ;
V_147 -> V_149 = 1 ;
V_147 -> V_150 . integer . V_124 = 1 ;
V_147 -> V_150 . integer . V_125 = 1024 ;
V_147 -> V_150 . integer . V_151 = 1 ;
return 0 ;
}
static int F_74 ( struct V_144 * V_145 ,
struct V_152 * V_153 )
{
struct V_15 * V_15 = F_64 ( V_145 ) ;
V_153 -> V_150 . integer . V_150 [ 0 ] =
V_15 -> V_16 [ V_145 -> V_154 . V_155 ]
[ V_145 -> V_154 . V_9 ] . V_44 ;
return 0 ;
}
static int F_75 ( struct V_15 * V_15 , int V_18 )
{
struct V_34 * V_35 = V_15 -> V_35 ;
struct V_139 * V_12 ;
struct V_144 * V_159 ;
struct V_8 * V_16 ;
int V_55 , V_128 , V_160 , V_161 , V_162 ;
strcpy ( V_35 -> V_163 , L_2 ) ;
for ( V_128 = 0 ; V_128 < 2 ; V_128 ++ ) {
V_12 = V_15 -> V_12 [ V_128 ] ;
V_161 =
V_12 -> V_40 [ V_41 ] . V_164 ;
for ( V_160 = 0 ; V_160 < V_161 ; V_160 ++ ) {
V_16 = & V_15 -> V_16 [ V_160 ] [ V_128 ] ;
V_16 -> V_18 = V_18 ;
V_16 -> V_19 = V_5 ;
V_16 -> V_42 = V_165 ;
V_16 -> V_43 = 48000 ;
V_16 -> V_44 = 2 ;
for ( V_162 = 0 ; V_162 < F_76 ( V_166 ) ;
V_162 ++ ) {
V_159 = F_77 ( & V_166 [ V_162 ] ,
V_15 ) ;
if ( ! V_159 )
return - V_130 ;
V_159 -> V_154 . V_9 = V_128 ;
V_159 -> V_154 . V_155 = V_160 ;
switch ( V_162 ) {
case V_167 :
V_16 -> V_51 = V_159 -> V_154 ;
break;
case V_168 :
V_16 -> V_48 = V_159 -> V_154 ;
break;
case V_169 :
V_16 -> V_49 = V_159 -> V_154 ;
break;
case V_170 :
V_16 -> V_50 = V_159 -> V_154 ;
break;
default:
break;
}
V_55 = F_78 ( V_35 , V_159 ) ;
if ( V_55 < 0 )
return V_55 ;
}
}
}
return 0 ;
}
static void F_79 ( struct V_171 * V_172 ,
struct V_1 * V_2 ,
const char * V_154 )
{
F_80 ( V_172 , L_3 , V_154 ) ;
if ( V_2 == NULL ) {
F_80 ( V_172 , L_4 ) ;
return;
}
F_80 ( V_172 , L_5 , V_2 -> V_76 ) ;
F_80 ( V_172 , L_6 , V_2 -> V_75 ) ;
F_80 ( V_172 , L_7 , V_2 -> V_78 ) ;
F_80 ( V_172 , L_8 , V_2 -> V_22 ) ;
F_80 ( V_172 , L_9 , V_2 -> V_25 ) ;
F_80 ( V_172 , L_10 , V_2 -> V_7 ) ;
F_80 ( V_172 , L_11 , V_2 -> V_4 ) ;
F_80 ( V_172 , L_12 ,
V_2 -> V_24 ) ;
F_80 ( V_172 , L_13 , V_2 -> V_23 ) ;
F_80 ( V_172 , L_14 , V_2 -> V_21 ) ;
F_80 ( V_172 , L_15 ,
V_2 -> V_57 , V_28 ) ;
F_80 ( V_172 , L_16 , V_2 -> V_26 . V_27 ) ;
}
static void F_81 ( struct V_171 * V_172 ,
struct V_15 * V_15 ,
int V_173 ,
int V_174 )
{
struct V_29 * V_30 = V_15 -> V_131 [ V_173 ] [ V_174 ] ;
F_80 ( V_172 , L_17 , V_174 , V_173 ) ;
if ( V_30 == NULL ) {
F_80 ( V_172 , L_18 ) ;
return;
}
F_80 ( V_172 , L_19 , V_30 -> V_37 ) ;
F_80 ( V_172 , L_20 , V_30 -> V_60 ) ;
F_80 ( V_172 , L_21 , V_30 -> V_61 ) ;
F_79 ( V_172 , V_30 -> V_40 [ 0 ] , L_22 ) ;
F_79 ( V_172 , V_30 -> V_40 [ 1 ] , L_23 ) ;
}
static void F_82 ( struct V_175 * V_176 ,
struct V_171 * V_172 )
{
struct V_15 * V_15 = V_176 -> V_54 ;
int V_173 , V_174 ;
F_24 ( & V_15 -> V_81 ) ;
V_174 = V_176 -> V_143 [ strlen ( V_176 -> V_143 ) - 1 ] ;
V_174 = V_174 == '0' ? 0 : 1 ;
for ( V_173 = 0 ; V_173 < V_177 ; V_173 ++ )
F_81 ( V_172 , V_15 , V_173 , V_174 ) ;
F_25 ( & V_15 -> V_81 ) ;
}
static int F_83 ( struct V_15 * V_15 , int V_178 )
{
char V_143 [ 32 ] ;
struct V_175 * V_176 ;
int V_55 ;
snprintf ( V_143 , sizeof( V_143 ) , L_24 , V_178 ) ;
V_55 = F_84 ( V_15 -> V_35 , V_143 , & V_176 ) ;
if ( V_55 < 0 )
return V_55 ;
F_85 ( V_176 , V_15 , F_82 ) ;
return 0 ;
}
static int F_86 ( struct V_179 * V_180 )
{
struct V_34 * V_35 ;
struct V_15 * V_15 ;
int V_128 = V_180 -> V_154 ;
int V_55 ;
V_55 = F_87 ( V_181 [ V_128 ] , V_154 [ V_128 ] , V_182 ,
sizeof( struct V_15 ) , & V_35 ) ;
if ( V_55 < 0 )
return V_55 ;
V_15 = V_35 -> V_54 ;
if ( V_183 [ V_128 ] < 1 )
V_183 [ V_128 ] = 1 ;
if ( V_183 [ V_128 ] > V_177 )
V_183 [ V_128 ] = V_177 ;
V_15 -> V_35 = V_35 ;
F_88 ( & V_15 -> V_81 ) ;
V_55 = F_59 ( V_15 , 0 , V_183 [ V_128 ] ) ;
if ( V_55 < 0 )
goto V_184;
V_55 = F_59 ( V_15 , 1 , V_183 [ V_128 ] ) ;
if ( V_55 < 0 )
goto V_184;
V_55 = F_75 ( V_15 , V_185 [ V_128 ] ? 1 : 0 ) ;
if ( V_55 < 0 )
goto V_184;
F_83 ( V_15 , 0 ) ;
F_83 ( V_15 , 1 ) ;
strcpy ( V_35 -> V_186 , L_25 ) ;
strcpy ( V_35 -> V_187 , L_25 ) ;
sprintf ( V_35 -> V_188 , L_26 , V_128 + 1 ) ;
V_55 = F_89 ( V_35 ) ;
if ( ! V_55 ) {
F_90 ( V_180 , V_35 ) ;
return 0 ;
}
V_184:
F_91 ( V_35 ) ;
return V_55 ;
}
static int F_92 ( struct V_179 * V_180 )
{
F_91 ( F_93 ( V_180 ) ) ;
F_90 ( V_180 , NULL ) ;
return 0 ;
}
static int F_94 ( struct V_9 * V_189 )
{
struct V_34 * V_35 = F_95 ( V_189 ) ;
struct V_15 * V_15 = V_35 -> V_54 ;
F_96 ( V_35 , V_190 ) ;
F_97 ( V_15 -> V_12 [ 0 ] ) ;
F_97 ( V_15 -> V_12 [ 1 ] ) ;
return 0 ;
}
static int F_98 ( struct V_9 * V_189 )
{
struct V_34 * V_35 = F_95 ( V_189 ) ;
F_96 ( V_35 , V_191 ) ;
return 0 ;
}
static void F_99 ( void )
{
int V_192 ;
for ( V_192 = 0 ; V_192 < F_76 ( V_193 ) ; ++ V_192 )
F_100 ( V_193 [ V_192 ] ) ;
F_101 ( & V_194 ) ;
}
static int T_2 F_102 ( void )
{
int V_192 , V_55 , V_195 ;
V_55 = F_103 ( & V_194 ) ;
if ( V_55 < 0 )
return V_55 ;
V_195 = 0 ;
for ( V_192 = 0 ; V_192 < V_196 ; V_192 ++ ) {
struct V_179 * V_9 ;
if ( ! V_197 [ V_192 ] )
continue;
V_9 = F_104 ( V_198 ,
V_192 , NULL , 0 ) ;
if ( F_105 ( V_9 ) )
continue;
if ( ! F_93 ( V_9 ) ) {
F_100 ( V_9 ) ;
continue;
}
V_193 [ V_192 ] = V_9 ;
V_195 ++ ;
}
if ( ! V_195 ) {
#ifdef F_106
F_107 ( V_199 L_27 ) ;
#endif
F_99 () ;
return - V_200 ;
}
return 0 ;
}
static void T_3 F_108 ( void )
{
F_99 () ;
}
