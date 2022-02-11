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
case V_64 :
F_16 ( & V_30 -> V_59 ) ;
V_30 -> V_61 |= V_13 ;
F_9 ( V_2 ) ;
F_17 ( & V_30 -> V_59 ) ;
break;
case V_65 :
case V_66 :
F_16 ( & V_30 -> V_59 ) ;
V_2 -> V_57 = V_28 ;
V_30 -> V_61 &= ~ V_13 ;
F_7 ( V_2 ) ;
F_17 ( & V_30 -> V_59 ) ;
break;
default:
return - V_67 ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_31 * V_68 ;
if ( V_2 == NULL || V_2 -> V_10 == NULL )
return;
V_68 = V_2 -> V_10 -> V_32 ;
if ( V_68 == NULL )
return;
V_68 -> V_69 = V_2 -> V_30 -> V_69 ;
}
static void F_19 ( struct V_52 * V_10 )
{
struct V_31 * V_32 = V_10 -> V_32 ;
struct V_1 * V_2 = V_32 -> V_54 ;
struct V_29 * V_30 = V_2 -> V_30 ;
V_30 -> V_69 . V_70 = ( 1ULL << V_32 -> V_42 ) ;
V_30 -> V_69 . V_71 = V_32 -> V_43 ;
V_30 -> V_69 . V_72 = V_32 -> V_43 ;
V_30 -> V_69 . V_73 = V_32 -> V_44 ;
V_30 -> V_69 . V_74 = V_32 -> V_44 ;
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
int V_75 , V_76 ;
V_76 = ( F_21 ( V_32 -> V_42 ) *
V_32 -> V_44 ) / 8 ;
V_75 = V_76 * V_32 -> V_43 ;
if ( V_75 <= 0 || V_76 <= 0 )
return - V_67 ;
V_2 -> V_77 = 0 ;
V_2 -> V_78 = F_22 ( V_32 , V_32 -> V_79 ) ;
if ( V_10 -> V_13 == V_41 ) {
V_2 -> V_80 = V_2 -> V_78 ;
F_23 ( V_32 -> V_42 , V_32 -> V_81 ,
V_32 -> V_79 * V_32 -> V_44 ) ;
}
V_2 -> V_23 = 0 ;
V_2 -> V_24 = 0 ;
V_2 -> V_25 = V_75 ;
V_2 -> V_7 = V_76 ;
V_2 -> V_22 = F_22 ( V_32 , V_32 -> V_82 ) ;
F_24 ( & V_2 -> V_15 -> V_83 ) ;
if ( ! ( V_30 -> V_37 & ~ ( 1 << V_10 -> V_13 ) ) ||
( F_4 ( V_2 ) -> V_18 &&
V_10 -> V_13 == V_14 ) )
F_19 ( V_10 ) ;
V_30 -> V_37 |= 1 << V_10 -> V_13 ;
F_25 ( & V_2 -> V_15 -> V_83 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 , unsigned int V_84 )
{
struct V_31 * V_32 = V_2 -> V_10 -> V_32 ;
char * V_85 = V_32 -> V_81 ;
unsigned int V_86 = V_2 -> V_77 ;
if ( V_2 -> V_80 >= V_2 -> V_78 )
return;
if ( V_2 -> V_80 + V_84 > V_2 -> V_78 )
V_84 = V_2 -> V_78 - V_2 -> V_80 ;
for (; ; ) {
unsigned int V_87 = V_84 ;
if ( V_86 + V_87 > V_2 -> V_78 )
V_87 = V_2 -> V_78 - V_86 ;
F_23 ( V_32 -> V_42 , V_85 + V_86 ,
F_27 ( V_32 , V_87 ) *
V_32 -> V_44 ) ;
V_2 -> V_80 += V_87 ;
V_84 -= V_87 ;
if ( ! V_84 )
break;
V_86 = 0 ;
}
}
static void F_28 ( struct V_1 * V_88 ,
struct V_1 * V_89 ,
unsigned int V_84 )
{
struct V_31 * V_32 = V_88 -> V_10 -> V_32 ;
char * V_90 = V_32 -> V_81 ;
char * V_85 = V_89 -> V_10 -> V_32 -> V_81 ;
unsigned int V_91 = V_88 -> V_77 ;
unsigned int V_86 = V_89 -> V_77 ;
unsigned int V_92 = 0 ;
if ( V_32 -> V_93 -> V_94 == V_46 &&
F_29 ( V_32 ) < V_32 -> V_79 ) {
T_1 V_95 , V_96 , V_97 ;
V_95 = V_96 = V_32 -> V_98 -> V_95 ;
V_96 -= V_96 % V_32 -> V_79 ;
V_96 += V_88 -> V_77 / V_88 -> V_7 ;
if ( V_95 < V_96 )
V_96 -= V_32 -> V_79 ;
V_97 = ( V_95 - V_96 ) * V_88 -> V_7 ;
if ( V_97 < V_84 ) {
V_92 = V_84 - V_97 ;
V_84 = V_97 ;
}
}
for (; ; ) {
unsigned int V_87 = V_84 ;
if ( V_91 + V_87 > V_88 -> V_78 )
V_87 = V_88 -> V_78 - V_91 ;
if ( V_86 + V_87 > V_89 -> V_78 )
V_87 = V_89 -> V_78 - V_86 ;
memcpy ( V_85 + V_86 , V_90 + V_91 , V_87 ) ;
V_89 -> V_80 = 0 ;
V_84 -= V_87 ;
if ( ! V_84 )
break;
V_91 = ( V_91 + V_87 ) % V_88 -> V_78 ;
V_86 = ( V_86 + V_87 ) % V_89 -> V_78 ;
}
if ( V_92 > 0 ) {
F_26 ( V_89 , V_92 ) ;
V_89 -> V_80 = 0 ;
}
}
static inline unsigned int F_30 ( struct V_1 * V_2 ,
unsigned int V_99 )
{
unsigned long V_100 ;
unsigned int V_101 ;
V_100 = F_1 ( V_2 , V_2 -> V_23 ) ;
V_2 -> V_23 += V_99 * V_2 -> V_25 ;
V_101 = F_1 ( V_2 , V_2 -> V_23 ) - V_100 ;
if ( V_101 >= V_2 -> V_58 )
V_101 -= V_2 -> V_58 ;
V_2 -> V_58 = 0 ;
if ( V_2 -> V_23 >= V_2 -> V_21 ) {
V_2 -> V_23 %= V_2 -> V_21 ;
V_2 -> V_24 = 1 ;
}
return V_101 ;
}
static inline void F_31 ( struct V_1 * V_2 ,
unsigned int V_101 )
{
V_2 -> V_77 += V_101 ;
V_2 -> V_77 %= V_2 -> V_78 ;
}
static unsigned int F_32 ( struct V_29 * V_30 )
{
struct V_1 * V_102 =
V_30 -> V_40 [ V_14 ] ;
struct V_1 * V_103 =
V_30 -> V_40 [ V_41 ] ;
unsigned long V_104 = 0 , V_105 = 0 ;
unsigned int V_60 , V_106 , V_107 ;
V_60 = V_30 -> V_60 ^ V_30 -> V_61 ;
if ( V_60 & ( 1 << V_14 ) ) {
V_104 = V_28 - V_102 -> V_57 ;
V_102 -> V_57 += V_104 ;
}
if ( V_60 & ( 1 << V_41 ) ) {
V_105 = V_28 - V_103 -> V_57 ;
V_103 -> V_57 += V_105 ;
}
if ( V_104 == 0 && V_105 == 0 )
goto V_108;
if ( V_104 > V_105 ) {
V_106 = F_30 ( V_102 , V_104 - V_105 ) ;
F_31 ( V_102 , V_106 ) ;
V_104 = V_105 ;
} else if ( V_104 < V_105 ) {
V_106 = F_30 ( V_103 , V_105 - V_104 ) ;
F_26 ( V_103 , V_106 ) ;
F_31 ( V_103 , V_106 ) ;
V_105 = V_104 ;
}
if ( V_104 == 0 && V_105 == 0 )
goto V_108;
V_106 = F_30 ( V_102 , V_104 ) ;
V_107 = F_30 ( V_103 , V_105 ) ;
if ( V_106 < V_107 ) {
V_103 -> V_58 = V_107 - V_106 ;
V_106 = V_107 ;
} else if ( V_106 > V_107 ) {
V_102 -> V_58 = V_106 - V_107 ;
}
F_28 ( V_102 , V_103 , V_106 ) ;
F_31 ( V_102 , V_106 ) ;
F_31 ( V_103 , V_106 ) ;
V_108:
return V_60 ;
}
static void F_33 ( unsigned long V_109 )
{
struct V_1 * V_2 = (struct V_1 * ) V_109 ;
unsigned long V_110 ;
F_34 ( & V_2 -> V_30 -> V_59 , V_110 ) ;
if ( F_32 ( V_2 -> V_30 ) & ( 1 << V_2 -> V_10 -> V_13 ) ) {
F_7 ( V_2 ) ;
if ( V_2 -> V_24 ) {
V_2 -> V_24 = 0 ;
F_35 ( & V_2 -> V_30 -> V_59 , V_110 ) ;
F_36 ( V_2 -> V_10 ) ;
return;
}
}
F_35 ( & V_2 -> V_30 -> V_59 , V_110 ) ;
}
static T_1 F_37 ( struct V_52 * V_10 )
{
struct V_31 * V_32 = V_10 -> V_32 ;
struct V_1 * V_2 = V_32 -> V_54 ;
T_1 V_111 ;
F_16 ( & V_2 -> V_30 -> V_59 ) ;
F_32 ( V_2 -> V_30 ) ;
V_111 = V_2 -> V_77 ;
F_17 ( & V_2 -> V_30 -> V_59 ) ;
return F_27 ( V_32 , V_111 ) ;
}
static void F_38 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_54 ;
F_39 ( V_2 ) ;
}
static int F_40 ( struct V_52 * V_10 ,
struct V_112 * V_113 )
{
return F_41 ( V_10 ,
F_42 ( V_113 ) ) ;
}
static int F_43 ( struct V_52 * V_10 )
{
struct V_31 * V_32 = V_10 -> V_32 ;
struct V_1 * V_2 = V_32 -> V_54 ;
struct V_29 * V_30 = V_2 -> V_30 ;
F_24 ( & V_2 -> V_15 -> V_83 ) ;
V_30 -> V_37 &= ~ ( 1 << V_10 -> V_13 ) ;
F_25 ( & V_2 -> V_15 -> V_83 ) ;
return F_44 ( V_10 ) ;
}
static unsigned int F_45 ( struct V_52 * V_10 )
{
if ( ! V_10 -> V_12 -> V_9 )
return V_10 -> V_13 ;
else
return ! V_10 -> V_13 ;
}
static int F_46 ( struct V_112 * V_113 ,
struct V_114 * V_115 )
{
struct V_116 * V_69 = V_115 -> V_117 ;
struct V_118 * V_119 = F_47 ( V_113 , V_115 -> V_120 ) ;
V_119 -> V_121 [ 0 ] &= ( V_122 ) V_69 -> V_70 ;
V_119 -> V_121 [ 1 ] &= ( V_122 ) ( V_69 -> V_70 >> 32 ) ;
memset ( V_119 -> V_121 + 2 , 0 , ( V_123 - 64 ) / 8 ) ;
if ( ! V_119 -> V_121 [ 0 ] && ! V_119 -> V_121 [ 1 ] )
return - V_67 ;
return 0 ;
}
static int F_48 ( struct V_112 * V_113 ,
struct V_114 * V_115 )
{
struct V_116 * V_69 = V_115 -> V_117 ;
struct V_124 V_125 ;
V_125 . V_126 = V_69 -> V_71 ;
V_125 . V_127 = V_69 -> V_72 ;
V_125 . V_128 = V_125 . V_129 = 0 ;
V_125 . integer = 0 ;
return F_49 ( F_50 ( V_113 , V_115 -> V_120 ) , & V_125 ) ;
}
static int F_51 ( struct V_112 * V_113 ,
struct V_114 * V_115 )
{
struct V_116 * V_69 = V_115 -> V_117 ;
struct V_124 V_125 ;
V_125 . V_126 = V_69 -> V_73 ;
V_125 . V_127 = V_69 -> V_74 ;
V_125 . V_128 = V_125 . V_129 = 0 ;
V_125 . integer = 0 ;
return F_49 ( F_50 ( V_113 , V_115 -> V_120 ) , & V_125 ) ;
}
static int F_52 ( struct V_52 * V_10 )
{
struct V_31 * V_32 = V_10 -> V_32 ;
struct V_15 * V_15 = V_10 -> V_54 ;
struct V_1 * V_2 ;
struct V_29 * V_30 ;
int V_55 = 0 ;
int V_130 = F_45 ( V_10 ) ;
F_24 ( & V_15 -> V_83 ) ;
V_2 = F_53 ( sizeof( * V_2 ) , V_131 ) ;
if ( ! V_2 ) {
V_55 = - V_132 ;
goto V_108;
}
V_2 -> V_15 = V_15 ;
V_2 -> V_10 = V_10 ;
F_54 ( & V_2 -> V_26 , F_33 ,
( unsigned long ) V_2 ) ;
V_30 = V_15 -> V_133 [ V_10 -> V_17 ] [ V_130 ] ;
if ( ! V_30 ) {
V_30 = F_53 ( sizeof( * V_30 ) , V_131 ) ;
if ( ! V_30 ) {
F_39 ( V_2 ) ;
V_55 = - V_132 ;
goto V_108;
}
F_55 ( & V_30 -> V_59 ) ;
V_30 -> V_69 = V_134 ;
V_15 -> V_133 [ V_10 -> V_17 ] [ V_130 ] = V_30 ;
}
V_2 -> V_30 = V_30 ;
V_30 -> V_40 [ V_10 -> V_13 ] = V_2 ;
F_56 ( V_32 , V_135 ) ;
V_55 = F_57 ( V_32 , 0 ,
V_136 ,
F_46 , & V_32 -> V_69 ,
V_136 , - 1 ) ;
if ( V_55 < 0 )
goto V_108;
V_55 = F_57 ( V_32 , 0 ,
V_137 ,
F_48 , & V_32 -> V_69 ,
V_137 , - 1 ) ;
if ( V_55 < 0 )
goto V_108;
V_55 = F_57 ( V_32 , 0 ,
V_138 ,
F_51 , & V_32 -> V_69 ,
V_138 , - 1 ) ;
if ( V_55 < 0 )
goto V_108;
V_32 -> V_54 = V_2 ;
V_32 -> V_139 = F_38 ;
if ( F_5 ( V_2 ) )
V_32 -> V_69 = V_134 ;
else
V_32 -> V_69 = V_30 -> V_69 ;
V_108:
F_25 ( & V_15 -> V_83 ) ;
return V_55 ;
}
static int F_58 ( struct V_52 * V_10 )
{
struct V_15 * V_15 = V_10 -> V_54 ;
struct V_1 * V_2 = V_10 -> V_32 -> V_54 ;
struct V_29 * V_30 ;
int V_130 = F_45 ( V_10 ) ;
F_9 ( V_2 ) ;
F_24 ( & V_15 -> V_83 ) ;
V_30 = V_15 -> V_133 [ V_10 -> V_17 ] [ V_130 ] ;
if ( V_30 -> V_40 [ ! V_10 -> V_13 ] ) {
V_30 -> V_40 [ V_10 -> V_13 ] = NULL ;
} else {
V_15 -> V_133 [ V_10 -> V_17 ] [ V_130 ] = NULL ;
F_39 ( V_30 ) ;
}
F_25 ( & V_15 -> V_83 ) ;
return 0 ;
}
static int F_59 ( struct V_15 * V_15 ,
int V_9 , int V_140 )
{
struct V_141 * V_12 ;
int V_55 ;
V_55 = F_60 ( V_15 -> V_35 , L_1 , V_9 ,
V_140 , V_140 , & V_12 ) ;
if ( V_55 < 0 )
return V_55 ;
F_61 ( V_12 , V_14 , & V_142 ) ;
F_61 ( V_12 , V_41 , & V_143 ) ;
V_12 -> V_54 = V_15 ;
V_12 -> V_144 = 0 ;
strcpy ( V_12 -> V_145 , L_1 ) ;
V_15 -> V_12 [ V_9 ] = V_12 ;
return 0 ;
}
static int F_62 ( struct V_146 * V_147 ,
struct V_148 * V_149 )
{
V_149 -> type = V_150 ;
V_149 -> V_151 = 1 ;
V_149 -> V_152 . integer . V_126 = 80000 ;
V_149 -> V_152 . integer . V_127 = 120000 ;
V_149 -> V_152 . integer . V_153 = 1 ;
return 0 ;
}
static int F_63 ( struct V_146 * V_147 ,
struct V_154 * V_155 )
{
struct V_15 * V_15 = F_64 ( V_147 ) ;
V_155 -> V_152 . integer . V_152 [ 0 ] =
V_15 -> V_16 [ V_147 -> V_156 . V_157 ]
[ V_147 -> V_156 . V_9 ] . V_19 ;
return 0 ;
}
static int F_65 ( struct V_146 * V_147 ,
struct V_154 * V_155 )
{
struct V_15 * V_15 = F_64 ( V_147 ) ;
unsigned int V_158 ;
int V_159 = 0 ;
V_158 = V_155 -> V_152 . integer . V_152 [ 0 ] ;
if ( V_158 < 80000 )
V_158 = 80000 ;
if ( V_158 > 120000 )
V_158 = 120000 ;
F_24 ( & V_15 -> V_83 ) ;
if ( V_158 != V_15 -> V_16 [ V_147 -> V_156 . V_157 ]
[ V_147 -> V_156 . V_9 ] . V_19 ) {
V_15 -> V_16 [ V_147 -> V_156 . V_157 ]
[ V_147 -> V_156 . V_9 ] . V_19 = V_158 ;
V_159 = 1 ;
}
F_25 ( & V_15 -> V_83 ) ;
return V_159 ;
}
static int F_66 ( struct V_146 * V_147 ,
struct V_154 * V_155 )
{
struct V_15 * V_15 = F_64 ( V_147 ) ;
V_155 -> V_152 . integer . V_152 [ 0 ] =
V_15 -> V_16 [ V_147 -> V_156 . V_157 ]
[ V_147 -> V_156 . V_9 ] . V_18 ;
return 0 ;
}
static int F_67 ( struct V_146 * V_147 ,
struct V_154 * V_155 )
{
struct V_15 * V_15 = F_64 ( V_147 ) ;
unsigned int V_158 ;
int V_159 = 0 ;
V_158 = V_155 -> V_152 . integer . V_152 [ 0 ] ? 1 : 0 ;
if ( V_158 != V_15 -> V_16 [ V_147 -> V_156 . V_157 ]
[ V_147 -> V_156 . V_9 ] . V_18 ) {
V_15 -> V_16 [ V_147 -> V_156 . V_157 ]
[ V_147 -> V_156 . V_9 ] . V_18 = V_158 ;
V_159 = 1 ;
}
return V_159 ;
}
static int F_68 ( struct V_146 * V_147 ,
struct V_154 * V_155 )
{
struct V_15 * V_15 = F_64 ( V_147 ) ;
struct V_29 * V_30 = V_15 -> V_133
[ V_147 -> V_156 . V_157 ] [ V_147 -> V_156 . V_9 ^ 1 ] ;
unsigned int V_158 = 0 ;
if ( V_30 != NULL )
V_158 = ( V_30 -> V_60 & ( 1 << V_14 ) ) ?
1 : 0 ;
V_155 -> V_152 . integer . V_152 [ 0 ] = V_158 ;
return 0 ;
}
static int F_69 ( struct V_146 * V_147 ,
struct V_148 * V_149 )
{
V_149 -> type = V_150 ;
V_149 -> V_151 = 1 ;
V_149 -> V_152 . integer . V_126 = 0 ;
V_149 -> V_152 . integer . V_127 = V_160 ;
V_149 -> V_152 . integer . V_153 = 1 ;
return 0 ;
}
static int F_70 ( struct V_146 * V_147 ,
struct V_154 * V_155 )
{
struct V_15 * V_15 = F_64 ( V_147 ) ;
V_155 -> V_152 . integer . V_152 [ 0 ] =
V_15 -> V_16 [ V_147 -> V_156 . V_157 ]
[ V_147 -> V_156 . V_9 ] . V_42 ;
return 0 ;
}
static int F_71 ( struct V_146 * V_147 ,
struct V_148 * V_149 )
{
V_149 -> type = V_150 ;
V_149 -> V_151 = 1 ;
V_149 -> V_152 . integer . V_126 = 0 ;
V_149 -> V_152 . integer . V_127 = 192000 ;
V_149 -> V_152 . integer . V_153 = 1 ;
return 0 ;
}
static int F_72 ( struct V_146 * V_147 ,
struct V_154 * V_155 )
{
struct V_15 * V_15 = F_64 ( V_147 ) ;
V_155 -> V_152 . integer . V_152 [ 0 ] =
V_15 -> V_16 [ V_147 -> V_156 . V_157 ]
[ V_147 -> V_156 . V_9 ] . V_43 ;
return 0 ;
}
static int F_73 ( struct V_146 * V_147 ,
struct V_148 * V_149 )
{
V_149 -> type = V_150 ;
V_149 -> V_151 = 1 ;
V_149 -> V_152 . integer . V_126 = 1 ;
V_149 -> V_152 . integer . V_127 = 1024 ;
V_149 -> V_152 . integer . V_153 = 1 ;
return 0 ;
}
static int F_74 ( struct V_146 * V_147 ,
struct V_154 * V_155 )
{
struct V_15 * V_15 = F_64 ( V_147 ) ;
V_155 -> V_152 . integer . V_152 [ 0 ] =
V_15 -> V_16 [ V_147 -> V_156 . V_157 ]
[ V_147 -> V_156 . V_9 ] . V_44 ;
return 0 ;
}
static int F_75 ( struct V_15 * V_15 , int V_18 )
{
struct V_34 * V_35 = V_15 -> V_35 ;
struct V_141 * V_12 ;
struct V_146 * V_161 ;
struct V_8 * V_16 ;
int V_55 , V_130 , V_162 , V_163 , V_164 ;
strcpy ( V_35 -> V_165 , L_2 ) ;
for ( V_130 = 0 ; V_130 < 2 ; V_130 ++ ) {
V_12 = V_15 -> V_12 [ V_130 ] ;
V_163 =
V_12 -> V_40 [ V_41 ] . V_166 ;
for ( V_162 = 0 ; V_162 < V_163 ; V_162 ++ ) {
V_16 = & V_15 -> V_16 [ V_162 ] [ V_130 ] ;
V_16 -> V_18 = V_18 ;
V_16 -> V_19 = V_5 ;
V_16 -> V_42 = V_167 ;
V_16 -> V_43 = 48000 ;
V_16 -> V_44 = 2 ;
for ( V_164 = 0 ; V_164 < F_76 ( V_168 ) ;
V_164 ++ ) {
V_161 = F_77 ( & V_168 [ V_164 ] ,
V_15 ) ;
if ( ! V_161 )
return - V_132 ;
V_161 -> V_156 . V_9 = V_130 ;
V_161 -> V_156 . V_157 = V_162 ;
switch ( V_164 ) {
case V_169 :
V_16 -> V_51 = V_161 -> V_156 ;
break;
case V_170 :
V_16 -> V_48 = V_161 -> V_156 ;
break;
case V_171 :
V_16 -> V_49 = V_161 -> V_156 ;
break;
case V_172 :
V_16 -> V_50 = V_161 -> V_156 ;
break;
default:
break;
}
V_55 = F_78 ( V_35 , V_161 ) ;
if ( V_55 < 0 )
return V_55 ;
}
}
}
return 0 ;
}
static void F_79 ( struct V_173 * V_174 ,
struct V_1 * V_2 ,
const char * V_156 )
{
F_80 ( V_174 , L_3 , V_156 ) ;
if ( V_2 == NULL ) {
F_80 ( V_174 , L_4 ) ;
return;
}
F_80 ( V_174 , L_5 , V_2 -> V_78 ) ;
F_80 ( V_174 , L_6 , V_2 -> V_77 ) ;
F_80 ( V_174 , L_7 , V_2 -> V_80 ) ;
F_80 ( V_174 , L_8 , V_2 -> V_22 ) ;
F_80 ( V_174 , L_9 , V_2 -> V_25 ) ;
F_80 ( V_174 , L_10 , V_2 -> V_7 ) ;
F_80 ( V_174 , L_11 , V_2 -> V_4 ) ;
F_80 ( V_174 , L_12 ,
V_2 -> V_24 ) ;
F_80 ( V_174 , L_13 , V_2 -> V_23 ) ;
F_80 ( V_174 , L_14 , V_2 -> V_21 ) ;
F_80 ( V_174 , L_15 ,
V_2 -> V_57 , V_28 ) ;
F_80 ( V_174 , L_16 , V_2 -> V_26 . V_27 ) ;
}
static void F_81 ( struct V_173 * V_174 ,
struct V_15 * V_15 ,
int V_175 ,
int V_176 )
{
struct V_29 * V_30 = V_15 -> V_133 [ V_175 ] [ V_176 ] ;
F_80 ( V_174 , L_17 , V_176 , V_175 ) ;
if ( V_30 == NULL ) {
F_80 ( V_174 , L_18 ) ;
return;
}
F_80 ( V_174 , L_19 , V_30 -> V_37 ) ;
F_80 ( V_174 , L_20 , V_30 -> V_60 ) ;
F_80 ( V_174 , L_21 , V_30 -> V_61 ) ;
F_79 ( V_174 , V_30 -> V_40 [ 0 ] , L_22 ) ;
F_79 ( V_174 , V_30 -> V_40 [ 1 ] , L_23 ) ;
}
static void F_82 ( struct V_177 * V_178 ,
struct V_173 * V_174 )
{
struct V_15 * V_15 = V_178 -> V_54 ;
int V_175 , V_176 ;
F_24 ( & V_15 -> V_83 ) ;
V_176 = V_178 -> V_145 [ strlen ( V_178 -> V_145 ) - 1 ] ;
V_176 = V_176 == '0' ? 0 : 1 ;
for ( V_175 = 0 ; V_175 < V_179 ; V_175 ++ )
F_81 ( V_174 , V_15 , V_175 , V_176 ) ;
F_25 ( & V_15 -> V_83 ) ;
}
static int F_83 ( struct V_15 * V_15 , int V_180 )
{
char V_145 [ 32 ] ;
struct V_177 * V_178 ;
int V_55 ;
snprintf ( V_145 , sizeof( V_145 ) , L_24 , V_180 ) ;
V_55 = F_84 ( V_15 -> V_35 , V_145 , & V_178 ) ;
if ( V_55 < 0 )
return V_55 ;
F_85 ( V_178 , V_15 , F_82 ) ;
return 0 ;
}
static int F_86 ( struct V_181 * V_182 )
{
struct V_34 * V_35 ;
struct V_15 * V_15 ;
int V_130 = V_182 -> V_156 ;
int V_55 ;
V_55 = F_87 ( V_183 [ V_130 ] , V_156 [ V_130 ] , V_184 ,
sizeof( struct V_15 ) , & V_35 ) ;
if ( V_55 < 0 )
return V_55 ;
V_15 = V_35 -> V_54 ;
if ( V_185 [ V_130 ] < 1 )
V_185 [ V_130 ] = 1 ;
if ( V_185 [ V_130 ] > V_179 )
V_185 [ V_130 ] = V_179 ;
V_15 -> V_35 = V_35 ;
F_88 ( & V_15 -> V_83 ) ;
V_55 = F_59 ( V_15 , 0 , V_185 [ V_130 ] ) ;
if ( V_55 < 0 )
goto V_186;
V_55 = F_59 ( V_15 , 1 , V_185 [ V_130 ] ) ;
if ( V_55 < 0 )
goto V_186;
V_55 = F_75 ( V_15 , V_187 [ V_130 ] ? 1 : 0 ) ;
if ( V_55 < 0 )
goto V_186;
F_83 ( V_15 , 0 ) ;
F_83 ( V_15 , 1 ) ;
strcpy ( V_35 -> V_188 , L_25 ) ;
strcpy ( V_35 -> V_189 , L_25 ) ;
sprintf ( V_35 -> V_190 , L_26 , V_130 + 1 ) ;
V_55 = F_89 ( V_35 ) ;
if ( ! V_55 ) {
F_90 ( V_182 , V_35 ) ;
return 0 ;
}
V_186:
F_91 ( V_35 ) ;
return V_55 ;
}
static int F_92 ( struct V_181 * V_182 )
{
F_91 ( F_93 ( V_182 ) ) ;
F_90 ( V_182 , NULL ) ;
return 0 ;
}
static int F_94 ( struct V_9 * V_191 )
{
struct V_34 * V_35 = F_95 ( V_191 ) ;
struct V_15 * V_15 = V_35 -> V_54 ;
F_96 ( V_35 , V_192 ) ;
F_97 ( V_15 -> V_12 [ 0 ] ) ;
F_97 ( V_15 -> V_12 [ 1 ] ) ;
return 0 ;
}
static int F_98 ( struct V_9 * V_191 )
{
struct V_34 * V_35 = F_95 ( V_191 ) ;
F_96 ( V_35 , V_193 ) ;
return 0 ;
}
static void F_99 ( void )
{
int V_194 ;
for ( V_194 = 0 ; V_194 < F_76 ( V_195 ) ; ++ V_194 )
F_100 ( V_195 [ V_194 ] ) ;
F_101 ( & V_196 ) ;
}
static int T_2 F_102 ( void )
{
int V_194 , V_55 , V_197 ;
V_55 = F_103 ( & V_196 ) ;
if ( V_55 < 0 )
return V_55 ;
V_197 = 0 ;
for ( V_194 = 0 ; V_194 < V_198 ; V_194 ++ ) {
struct V_181 * V_9 ;
if ( ! V_199 [ V_194 ] )
continue;
V_9 = F_104 ( V_200 ,
V_194 , NULL , 0 ) ;
if ( F_105 ( V_9 ) )
continue;
if ( ! F_93 ( V_9 ) ) {
F_100 ( V_9 ) ;
continue;
}
V_195 [ V_194 ] = V_9 ;
V_197 ++ ;
}
if ( ! V_197 ) {
#ifdef F_106
F_107 ( V_201 L_27 ) ;
#endif
F_99 () ;
return - V_202 ;
}
return 0 ;
}
static void T_3 F_108 ( void )
{
F_99 () ;
}
