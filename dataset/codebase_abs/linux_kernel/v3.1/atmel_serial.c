static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static bool F_3 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
return V_5 -> V_6 ;
}
static bool F_4 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
return V_5 -> V_7 ;
}
static bool F_3 ( struct V_2 * V_4 )
{
return false ;
}
static bool F_4 ( struct V_2 * V_4 )
{
return false ;
}
void F_5 ( struct V_2 * V_4 , struct V_8 * V_9 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_10 ;
F_6 ( & V_4 -> V_11 ) ;
F_7 ( V_4 , V_5 -> V_12 ) ;
V_10 = F_8 ( V_4 ) ;
V_10 &= ~ V_13 ;
V_5 -> V_14 = * V_9 ;
if ( V_9 -> V_15 & V_16 ) {
F_9 ( V_4 -> V_17 , L_1 ) ;
V_5 -> V_12 = V_18 ;
if ( V_9 -> V_15 & V_19 )
F_10 ( V_4 , V_9 -> V_20 ) ;
V_10 |= V_21 ;
} else {
F_9 ( V_4 -> V_17 , L_2 ) ;
if ( F_4 ( V_4 ) )
V_5 -> V_12 = V_22 |
V_23 ;
else
V_5 -> V_12 = V_24 ;
}
F_11 ( V_4 , V_10 ) ;
F_12 ( V_4 , V_5 -> V_12 ) ;
F_13 ( & V_4 -> V_11 ) ;
}
static T_1 F_14 ( struct V_2 * V_4 )
{
return ( F_15 ( V_4 ) & V_18 ) ? V_25 : 0 ;
}
static void F_16 ( struct V_2 * V_4 , T_1 V_26 )
{
unsigned int V_27 = 0 ;
unsigned int V_10 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
#ifdef F_17
if ( F_18 () ) {
if ( V_4 -> V_28 == V_29 ) {
if ( V_26 & V_30 )
F_19 ( V_31 , 0 ) ;
else
F_19 ( V_31 , 1 ) ;
}
}
#endif
if ( V_26 & V_30 )
V_27 |= V_32 ;
else
V_27 |= V_33 ;
if ( V_26 & V_34 )
V_27 |= V_35 ;
else
V_27 |= V_36 ;
F_20 ( V_4 , V_27 ) ;
V_10 = F_8 ( V_4 ) & ~ V_37 ;
if ( V_26 & V_38 )
V_10 |= V_39 ;
else
V_10 |= V_40 ;
V_10 &= ~ V_13 ;
if ( V_5 -> V_14 . V_15 & V_16 ) {
F_9 ( V_4 -> V_17 , L_1 ) ;
if ( V_5 -> V_14 . V_15 & V_19 )
F_10 ( V_4 ,
V_5 -> V_14 . V_20 ) ;
V_10 |= V_21 ;
} else {
F_9 ( V_4 -> V_17 , L_2 ) ;
}
F_11 ( V_4 , V_10 ) ;
}
static T_1 F_21 ( struct V_2 * V_4 )
{
unsigned int V_41 , V_42 = 0 ;
V_41 = F_15 ( V_4 ) ;
if ( ! ( V_41 & V_43 ) )
V_42 |= V_44 ;
if ( ! ( V_41 & V_45 ) )
V_42 |= V_46 ;
if ( ! ( V_41 & V_47 ) )
V_42 |= V_48 ;
if ( ! ( V_41 & V_49 ) )
V_42 |= V_50 ;
return V_42 ;
}
static void F_22 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
F_23 ( V_4 , V_51 ) ;
}
F_7 ( V_4 , V_5 -> V_12 ) ;
if ( V_5 -> V_14 . V_15 & V_16 )
F_24 ( V_4 ) ;
}
static void F_25 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
if ( F_26 ( V_4 ) & V_52 )
return;
if ( V_5 -> V_14 . V_15 & V_16 )
F_27 ( V_4 ) ;
F_23 ( V_4 , V_52 ) ;
}
F_12 ( V_4 , V_5 -> V_12 ) ;
}
static void F_24 ( struct V_2 * V_4 )
{
F_20 ( V_4 , V_53 ) ;
if ( F_3 ( V_4 ) ) {
F_12 ( V_4 , V_54 | V_55 |
V_4 -> V_56 ) ;
F_23 ( V_4 , V_57 ) ;
} else {
F_12 ( V_4 , V_58 ) ;
}
}
static void F_27 ( struct V_2 * V_4 )
{
if ( F_3 ( V_4 ) ) {
F_23 ( V_4 , V_59 ) ;
F_7 ( V_4 , V_54 | V_55 |
V_4 -> V_56 ) ;
} else {
F_7 ( V_4 , V_58 ) ;
}
}
static void F_28 ( struct V_2 * V_4 )
{
F_12 ( V_4 , V_60 | V_61
| V_62 | V_63 ) ;
}
static void F_29 ( struct V_2 * V_4 , int V_64 )
{
if ( V_64 != 0 )
F_20 ( V_4 , V_65 ) ;
else
F_20 ( V_4 , V_66 ) ;
}
static void
F_30 ( struct V_2 * V_4 , unsigned int V_41 ,
unsigned int V_67 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_68 * V_69 = & V_5 -> V_70 ;
struct V_71 * V_72 ;
if ( ! F_31 ( V_69 -> V_73 , V_69 -> V_74 , V_75 ) )
return;
V_72 = & ( (struct V_71 * ) V_69 -> V_76 ) [ V_69 -> V_73 ] ;
V_72 -> V_41 = V_41 ;
V_72 -> V_67 = V_67 ;
F_32 () ;
V_69 -> V_73 = ( V_69 -> V_73 + 1 ) & ( V_75 - 1 ) ;
}
static void F_33 ( struct V_2 * V_4 , unsigned int V_41 )
{
F_20 ( V_4 , V_53 ) ;
if ( V_41 & V_77 ) {
V_41 &= ~ ( V_78 | V_79 ) ;
V_4 -> V_80 . V_81 ++ ;
}
if ( V_41 & V_78 )
V_4 -> V_80 . V_82 ++ ;
if ( V_41 & V_79 )
V_4 -> V_80 . V_83 ++ ;
if ( V_41 & V_84 )
V_4 -> V_80 . V_85 ++ ;
}
static void F_34 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_41 , V_67 ;
V_41 = F_15 ( V_4 ) ;
while ( V_41 & V_58 ) {
V_67 = F_35 ( V_4 ) ;
if ( F_36 ( V_41 & ( V_78 | V_79
| V_84 | V_77 )
|| V_5 -> V_86 ) ) {
F_20 ( V_4 , V_53 ) ;
if ( V_41 & V_77
&& ! V_5 -> V_86 ) {
V_5 -> V_86 = 1 ;
F_12 ( V_4 , V_77 ) ;
} else {
F_7 ( V_4 , V_77 ) ;
V_41 &= ~ V_77 ;
V_5 -> V_86 = 0 ;
}
}
F_30 ( V_4 , V_41 , V_67 ) ;
V_41 = F_15 ( V_4 ) ;
}
F_37 ( & V_5 -> V_87 ) ;
}
static void F_38 ( struct V_2 * V_4 )
{
struct V_68 * V_88 = & V_4 -> V_89 -> V_88 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_4 -> V_90 && F_15 ( V_4 ) & V_5 -> V_12 ) {
F_39 ( V_4 , V_4 -> V_90 ) ;
V_4 -> V_80 . V_91 ++ ;
V_4 -> V_90 = 0 ;
}
if ( F_40 ( V_88 ) || F_41 ( V_4 ) )
return;
while ( F_15 ( V_4 ) & V_5 -> V_12 ) {
F_39 ( V_4 , V_88 -> V_76 [ V_88 -> V_74 ] ) ;
V_88 -> V_74 = ( V_88 -> V_74 + 1 ) & ( V_92 - 1 ) ;
V_4 -> V_80 . V_91 ++ ;
if ( F_40 ( V_88 ) )
break;
}
if ( F_42 ( V_88 ) < V_93 )
F_43 ( V_4 ) ;
if ( ! F_40 ( V_88 ) )
F_12 ( V_4 , V_5 -> V_12 ) ;
}
static void
F_44 ( struct V_2 * V_4 , unsigned int V_94 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_3 ( V_4 ) ) {
if ( V_94 & ( V_54 | V_55 ) ) {
F_7 ( V_4 , ( V_54
| V_55 ) ) ;
F_37 ( & V_5 -> V_87 ) ;
}
if ( V_94 & ( V_77 | V_84 |
V_79 | V_78 ) )
F_33 ( V_4 , V_94 ) ;
}
if ( V_94 & V_58 )
F_34 ( V_4 ) ;
else if ( V_94 & V_77 ) {
F_20 ( V_4 , V_53 ) ;
F_7 ( V_4 , V_77 ) ;
V_5 -> V_86 = 0 ;
}
}
static void
F_45 ( struct V_2 * V_4 , unsigned int V_94 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_94 & V_5 -> V_12 ) {
F_7 ( V_4 , V_5 -> V_12 ) ;
F_37 ( & V_5 -> V_87 ) ;
}
}
static void
F_46 ( struct V_2 * V_4 , unsigned int V_94 ,
unsigned int V_41 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_94 & ( V_60 | V_61 | V_62
| V_63 ) ) {
V_5 -> V_95 = V_41 ;
F_37 ( & V_5 -> V_87 ) ;
}
}
static T_2 F_47 ( int V_96 , void * V_97 )
{
struct V_2 * V_4 = V_97 ;
unsigned int V_41 , V_94 , V_98 = 0 ;
do {
V_41 = F_15 ( V_4 ) ;
V_94 = V_41 & F_48 ( V_4 ) ;
if ( ! V_94 )
break;
F_44 ( V_4 , V_94 ) ;
F_46 ( V_4 , V_94 , V_41 ) ;
F_45 ( V_4 , V_94 ) ;
} while ( V_98 ++ < V_99 );
return V_98 ? V_100 : V_101 ;
}
static void F_49 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_68 * V_88 = & V_4 -> V_89 -> V_88 ;
struct V_102 * V_103 = & V_5 -> V_104 ;
int V_105 ;
if ( F_50 ( V_4 ) )
return;
V_88 -> V_74 += V_103 -> V_106 ;
V_88 -> V_74 &= V_92 - 1 ;
V_4 -> V_80 . V_91 += V_103 -> V_106 ;
V_103 -> V_106 = 0 ;
F_23 ( V_4 , V_51 ) ;
if ( ! F_40 ( V_88 ) && ! F_41 ( V_4 ) ) {
F_51 ( V_4 -> V_17 ,
V_103 -> V_107 ,
V_103 -> V_108 ,
V_109 ) ;
V_105 = F_52 ( V_88 -> V_73 , V_88 -> V_74 , V_92 ) ;
V_103 -> V_106 = V_105 ;
F_53 ( V_4 , V_103 -> V_107 + V_88 -> V_74 ) ;
F_54 ( V_4 , V_105 ) ;
F_23 ( V_4 , V_52 ) ;
F_12 ( V_4 , V_5 -> V_12 ) ;
} else {
if ( V_5 -> V_14 . V_15 & V_16 ) {
F_24 ( V_4 ) ;
}
}
if ( F_42 ( V_88 ) < V_93 )
F_43 ( V_4 ) ;
}
static void F_55 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_68 * V_69 = & V_5 -> V_70 ;
unsigned int V_110 ;
unsigned int V_41 ;
while ( V_69 -> V_73 != V_69 -> V_74 ) {
struct V_71 V_72 ;
F_56 () ;
V_72 = ( (struct V_71 * ) V_69 -> V_76 ) [ V_69 -> V_74 ] ;
V_69 -> V_74 = ( V_69 -> V_74 + 1 ) & ( V_75 - 1 ) ;
V_4 -> V_80 . V_111 ++ ;
V_41 = V_72 . V_41 ;
V_110 = V_112 ;
if ( F_36 ( V_41 & ( V_78 | V_79
| V_84 | V_77 ) ) ) {
if ( V_41 & V_77 ) {
V_41 &= ~ ( V_78 | V_79 ) ;
V_4 -> V_80 . V_81 ++ ;
if ( F_57 ( V_4 ) )
continue;
}
if ( V_41 & V_78 )
V_4 -> V_80 . V_82 ++ ;
if ( V_41 & V_79 )
V_4 -> V_80 . V_83 ++ ;
if ( V_41 & V_84 )
V_4 -> V_80 . V_85 ++ ;
V_41 &= V_4 -> V_56 ;
if ( V_41 & V_77 )
V_110 = V_113 ;
else if ( V_41 & V_78 )
V_110 = V_114 ;
else if ( V_41 & V_79 )
V_110 = V_115 ;
}
if ( F_58 ( V_4 , V_72 . V_67 ) )
continue;
F_59 ( V_4 , V_41 , V_84 , V_72 . V_67 , V_110 ) ;
}
F_13 ( & V_4 -> V_11 ) ;
F_60 ( V_4 -> V_89 -> V_4 . V_116 ) ;
F_6 ( & V_4 -> V_11 ) ;
}
static void F_61 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_117 * V_116 = V_4 -> V_89 -> V_4 . V_116 ;
struct V_102 * V_103 ;
int V_118 = V_5 -> V_119 ;
unsigned int V_73 ;
unsigned int V_74 ;
unsigned int V_105 ;
do {
F_20 ( V_4 , V_120 ) ;
V_103 = & V_5 -> V_121 [ V_118 ] ;
V_73 = F_62 ( V_4 ) - V_103 -> V_107 ;
V_74 = V_103 -> V_106 ;
V_73 = F_63 ( V_73 , V_103 -> V_108 ) ;
if ( F_64 ( V_73 != V_74 ) ) {
F_65 ( V_4 -> V_17 , V_103 -> V_107 ,
V_103 -> V_108 , V_122 ) ;
V_105 = V_73 - V_74 ;
F_66 ( V_116 , V_103 -> V_76 + V_103 -> V_106 , V_105 ) ;
F_51 ( V_4 -> V_17 , V_103 -> V_107 ,
V_103 -> V_108 , V_122 ) ;
V_4 -> V_80 . V_111 += V_105 ;
V_103 -> V_106 = V_73 ;
}
if ( V_73 >= V_103 -> V_108 ) {
V_103 -> V_106 = 0 ;
F_67 ( V_4 , V_103 -> V_107 ) ;
F_68 ( V_4 , V_103 -> V_108 ) ;
V_118 = ! V_118 ;
V_5 -> V_119 = V_118 ;
}
} while ( V_73 >= V_103 -> V_108 );
F_13 ( & V_4 -> V_11 ) ;
F_60 ( V_116 ) ;
F_6 ( & V_4 -> V_11 ) ;
F_12 ( V_4 , V_54 | V_55 ) ;
}
static void F_69 ( unsigned long V_123 )
{
struct V_2 * V_4 = (struct V_2 * ) V_123 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_41 ;
unsigned int V_124 ;
F_6 ( & V_4 -> V_11 ) ;
if ( F_4 ( V_4 ) )
F_49 ( V_4 ) ;
else
F_38 ( V_4 ) ;
V_41 = V_5 -> V_95 ;
V_124 = V_41 ^ V_5 -> V_125 ;
if ( V_124 & ( V_49 | V_47
| V_43 | V_45 ) ) {
if ( V_124 & V_49 )
V_4 -> V_80 . V_126 ++ ;
if ( V_124 & V_47 )
V_4 -> V_80 . V_127 ++ ;
if ( V_124 & V_43 )
F_70 ( V_4 , ! ( V_41 & V_43 ) ) ;
if ( V_124 & V_45 )
F_71 ( V_4 , ! ( V_41 & V_45 ) ) ;
F_72 ( & V_4 -> V_89 -> V_4 . V_128 ) ;
V_5 -> V_125 = V_41 ;
}
if ( F_3 ( V_4 ) )
F_61 ( V_4 ) ;
else
F_55 ( V_4 ) ;
F_13 ( & V_4 -> V_11 ) ;
}
static int F_73 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_117 * V_116 = V_4 -> V_89 -> V_4 . V_116 ;
int V_129 ;
F_7 ( V_4 , - 1 ) ;
V_129 = F_74 ( V_4 -> V_96 , F_47 , V_130 ,
V_116 ? V_116 -> V_131 : L_3 , V_4 ) ;
if ( V_129 ) {
F_75 ( L_4 ) ;
return V_129 ;
}
if ( F_3 ( V_4 ) ) {
int V_132 ;
for ( V_132 = 0 ; V_132 < 2 ; V_132 ++ ) {
struct V_102 * V_103 = & V_5 -> V_121 [ V_132 ] ;
V_103 -> V_76 = F_76 ( V_133 , V_134 ) ;
if ( V_103 -> V_76 == NULL ) {
if ( V_132 != 0 ) {
F_77 ( V_4 -> V_17 ,
V_5 -> V_121 [ 0 ] . V_107 ,
V_133 ,
V_122 ) ;
F_78 ( V_5 -> V_121 [ 0 ] . V_76 ) ;
}
F_79 ( V_4 -> V_96 , V_4 ) ;
return - V_135 ;
}
V_103 -> V_107 = F_80 ( V_4 -> V_17 ,
V_103 -> V_76 ,
V_133 ,
V_122 ) ;
V_103 -> V_108 = V_133 ;
V_103 -> V_106 = 0 ;
}
V_5 -> V_119 = 0 ;
F_81 ( V_4 , V_5 -> V_121 [ 0 ] . V_107 ) ;
F_82 ( V_4 , V_133 ) ;
F_67 ( V_4 , V_5 -> V_121 [ 1 ] . V_107 ) ;
F_68 ( V_4 , V_133 ) ;
}
if ( F_4 ( V_4 ) ) {
struct V_102 * V_103 = & V_5 -> V_104 ;
struct V_68 * V_88 = & V_4 -> V_89 -> V_88 ;
V_103 -> V_76 = V_88 -> V_76 ;
V_103 -> V_107 = F_80 ( V_4 -> V_17 ,
V_103 -> V_76 ,
V_92 ,
V_109 ) ;
V_103 -> V_108 = V_92 ;
V_103 -> V_106 = 0 ;
}
if ( V_136 ) {
V_129 = V_136 ( V_4 ) ;
if ( V_129 ) {
F_79 ( V_4 -> V_96 , V_4 ) ;
return V_129 ;
}
}
V_5 -> V_125 = F_15 ( V_4 ) ;
V_5 -> V_95 = V_5 -> V_125 ;
F_20 ( V_4 , V_53 | V_137 ) ;
F_20 ( V_4 , V_138 | V_139 ) ;
if ( F_3 ( V_4 ) ) {
F_83 ( V_4 , V_140 ) ;
F_20 ( V_4 , V_120 ) ;
F_12 ( V_4 , V_54 | V_55 ) ;
F_23 ( V_4 , V_57 ) ;
} else {
F_12 ( V_4 , V_58 ) ;
}
return 0 ;
}
static void F_84 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_27 ( V_4 ) ;
F_22 ( V_4 ) ;
if ( F_3 ( V_4 ) ) {
int V_132 ;
for ( V_132 = 0 ; V_132 < 2 ; V_132 ++ ) {
struct V_102 * V_103 = & V_5 -> V_121 [ V_132 ] ;
F_77 ( V_4 -> V_17 ,
V_103 -> V_107 ,
V_103 -> V_108 ,
V_122 ) ;
F_78 ( V_103 -> V_76 ) ;
}
}
if ( F_4 ( V_4 ) ) {
struct V_102 * V_103 = & V_5 -> V_104 ;
F_77 ( V_4 -> V_17 ,
V_103 -> V_107 ,
V_103 -> V_108 ,
V_109 ) ;
}
F_20 ( V_4 , V_53 ) ;
F_7 ( V_4 , - 1 ) ;
F_79 ( V_4 -> V_96 , V_4 ) ;
if ( V_141 )
V_141 ( V_4 ) ;
}
static void F_85 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
F_54 ( V_4 , 0 ) ;
V_5 -> V_104 . V_106 = 0 ;
}
}
static void F_86 ( struct V_2 * V_4 , unsigned int V_89 ,
unsigned int V_142 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
switch ( V_89 ) {
case 0 :
F_87 ( V_5 -> V_143 ) ;
F_12 ( V_4 , V_5 -> V_144 ) ;
break;
case 3 :
V_5 -> V_144 = F_48 ( V_4 ) ;
F_7 ( V_4 , - 1 ) ;
F_88 ( V_5 -> V_143 ) ;
break;
default:
F_75 ( V_145 L_5 , V_89 ) ;
}
}
static void F_89 ( struct V_2 * V_4 , struct V_146 * V_147 ,
struct V_146 * V_148 )
{
unsigned long V_15 ;
unsigned int V_10 , V_149 , V_150 , V_151 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
V_10 = F_8 ( V_4 ) & ~ ( V_152 | V_153
| V_154 | V_155
| V_13 ) ;
V_151 = F_90 ( V_4 , V_147 , V_148 , 0 , V_4 -> V_156 / 16 ) ;
V_150 = F_91 ( V_4 , V_151 ) ;
if ( V_150 > 65535 ) {
V_150 /= 8 ;
V_10 |= V_157 ;
}
switch ( V_147 -> V_158 & V_159 ) {
case V_160 :
V_10 |= V_161 ;
break;
case V_162 :
V_10 |= V_163 ;
break;
case V_164 :
V_10 |= V_165 ;
break;
default:
V_10 |= V_166 ;
break;
}
if ( V_147 -> V_158 & V_167 )
V_10 |= V_168 ;
if ( V_147 -> V_158 & V_169 ) {
if ( V_147 -> V_158 & V_170 ) {
if ( V_147 -> V_158 & V_171 )
V_10 |= V_172 ;
else
V_10 |= V_173 ;
} else if ( V_147 -> V_158 & V_171 )
V_10 |= V_174 ;
else
V_10 |= V_175 ;
} else
V_10 |= V_176 ;
if ( V_147 -> V_158 & V_177 )
V_10 |= V_178 ;
else
V_10 |= V_179 ;
F_92 ( & V_4 -> V_11 , V_15 ) ;
V_4 -> V_56 = V_84 ;
if ( V_147 -> V_180 & V_181 )
V_4 -> V_56 |= ( V_79 | V_78 ) ;
if ( V_147 -> V_180 & ( V_182 | V_183 ) )
V_4 -> V_56 |= V_77 ;
if ( F_3 ( V_4 ) )
F_12 ( V_4 , V_4 -> V_56 ) ;
V_4 -> V_184 = 0 ;
if ( V_147 -> V_180 & V_185 )
V_4 -> V_184 |= ( V_79 | V_78 ) ;
if ( V_147 -> V_180 & V_186 ) {
V_4 -> V_184 |= V_77 ;
if ( V_147 -> V_180 & V_185 )
V_4 -> V_184 |= V_84 ;
}
F_93 ( V_4 , V_147 -> V_158 , V_151 ) ;
V_149 = F_48 ( V_4 ) ;
F_7 ( V_4 , - 1 ) ;
F_20 ( V_4 , V_187 | V_188 ) ;
V_10 &= ~ V_13 ;
if ( V_5 -> V_14 . V_15 & V_16 ) {
F_9 ( V_4 -> V_17 , L_1 ) ;
if ( V_5 -> V_14 . V_15 & V_19 )
F_10 ( V_4 ,
V_5 -> V_14 . V_20 ) ;
V_10 |= V_21 ;
} else {
F_9 ( V_4 -> V_17 , L_2 ) ;
}
F_11 ( V_4 , V_10 ) ;
F_94 ( V_4 , V_150 ) ;
F_20 ( V_4 , V_53 | V_137 ) ;
F_20 ( V_4 , V_138 | V_139 ) ;
F_12 ( V_4 , V_149 ) ;
if ( F_95 ( V_4 , V_147 -> V_158 ) )
V_4 -> V_189 -> V_190 ( V_4 ) ;
F_96 ( & V_4 -> V_11 , V_15 ) ;
}
static void F_97 ( struct V_2 * V_4 , int V_191 )
{
int line = V_4 -> line ;
if ( line >= V_4 -> V_89 -> V_4 . V_116 -> V_192 -> V_193 )
return;
if ( V_4 -> V_89 -> V_4 . V_116 -> V_194 -> V_189 -> V_193 == V_195 ) {
V_4 -> V_15 |= V_196 ;
F_28 ( V_4 ) ;
} else {
V_4 -> V_15 &= ~ V_196 ;
}
}
static const char * F_98 ( struct V_2 * V_4 )
{
return ( V_4 -> type == V_197 ) ? L_6 : NULL ;
}
static void F_99 ( struct V_2 * V_4 )
{
struct V_198 * V_199 = F_100 ( V_4 -> V_17 ) ;
int V_200 = V_199 -> V_201 [ 0 ] . V_202 - V_199 -> V_201 [ 0 ] . V_203 + 1 ;
F_101 ( V_4 -> V_28 , V_200 ) ;
if ( V_4 -> V_15 & V_204 ) {
F_102 ( V_4 -> V_205 ) ;
V_4 -> V_205 = NULL ;
}
}
static int F_103 ( struct V_2 * V_4 )
{
struct V_198 * V_199 = F_100 ( V_4 -> V_17 ) ;
int V_200 = V_199 -> V_201 [ 0 ] . V_202 - V_199 -> V_201 [ 0 ] . V_203 + 1 ;
if ( ! F_104 ( V_4 -> V_28 , V_200 , L_3 ) )
return - V_206 ;
if ( V_4 -> V_15 & V_204 ) {
V_4 -> V_205 = F_105 ( V_4 -> V_28 , V_200 ) ;
if ( V_4 -> V_205 == NULL ) {
F_101 ( V_4 -> V_28 , V_200 ) ;
return - V_135 ;
}
}
return 0 ;
}
static void F_106 ( struct V_2 * V_4 , int V_15 )
{
if ( V_15 & V_207 ) {
V_4 -> type = V_197 ;
F_103 ( V_4 ) ;
}
}
static int F_107 ( struct V_2 * V_4 , struct V_208 * V_209 )
{
int V_42 = 0 ;
if ( V_209 -> type != V_210 && V_209 -> type != V_197 )
V_42 = - V_211 ;
if ( V_4 -> V_96 != V_209 -> V_96 )
V_42 = - V_211 ;
if ( V_209 -> V_212 != V_213 )
V_42 = - V_211 ;
if ( V_4 -> V_156 / 16 != V_209 -> V_214 )
V_42 = - V_211 ;
if ( ( void * ) V_4 -> V_28 != V_209 -> V_215 )
V_42 = - V_211 ;
if ( V_4 -> V_216 != V_209 -> V_4 )
V_42 = - V_211 ;
if ( V_209 -> V_217 != 0 )
V_42 = - V_211 ;
return V_42 ;
}
static int F_108 ( struct V_2 * V_4 )
{
while ( ! ( F_15 ( V_4 ) & V_58 ) )
F_109 () ;
return F_35 ( V_4 ) ;
}
static void F_110 ( struct V_2 * V_4 , unsigned char V_67 )
{
while ( ! ( F_15 ( V_4 ) & V_24 ) )
F_109 () ;
F_39 ( V_4 , V_67 ) ;
}
static int
F_111 ( struct V_2 * V_4 , unsigned int V_218 , unsigned long V_219 )
{
struct V_8 V_9 ;
switch ( V_218 ) {
case V_220 :
if ( F_112 ( & V_9 , (struct V_8 * ) V_219 ,
sizeof( V_9 ) ) )
return - V_221 ;
F_5 ( V_4 , & V_9 ) ;
break;
case V_222 :
if ( F_113 ( (struct V_8 * ) V_219 ,
& ( F_1 ( V_4 ) -> V_14 ) ,
sizeof( V_9 ) ) )
return - V_221 ;
break;
default:
return - V_223 ;
}
return 0 ;
}
static void T_3 F_114 ( struct V_1 * V_5 ,
struct V_198 * V_199 )
{
struct V_2 * V_4 = & V_5 -> V_3 ;
struct V_224 * V_123 = V_199 -> V_17 . V_225 ;
V_4 -> V_226 = V_227 ;
V_4 -> V_15 = V_228 ;
V_4 -> V_189 = & V_229 ;
V_4 -> V_230 = 1 ;
V_4 -> line = V_123 -> V_193 ;
V_4 -> V_17 = & V_199 -> V_17 ;
V_4 -> V_28 = V_199 -> V_201 [ 0 ] . V_203 ;
V_4 -> V_96 = V_199 -> V_201 [ 1 ] . V_203 ;
F_115 ( & V_5 -> V_87 , F_69 ,
( unsigned long ) V_4 ) ;
memset ( & V_5 -> V_70 , 0 , sizeof( V_5 -> V_70 ) ) ;
if ( V_123 -> V_231 )
V_4 -> V_205 = V_123 -> V_231 ;
else {
V_4 -> V_15 |= V_204 ;
V_4 -> V_205 = NULL ;
}
if ( ! V_5 -> V_143 ) {
V_5 -> V_143 = F_116 ( & V_199 -> V_17 , L_7 ) ;
F_87 ( V_5 -> V_143 ) ;
V_4 -> V_156 = F_117 ( V_5 -> V_143 ) ;
F_88 ( V_5 -> V_143 ) ;
}
V_5 -> V_6 = V_123 -> V_6 ;
V_5 -> V_7 = V_123 -> V_7 ;
V_5 -> V_14 = V_123 -> V_14 ;
if ( V_5 -> V_14 . V_15 & V_16 )
V_5 -> V_12 = V_18 ;
else if ( F_4 ( V_4 ) ) {
V_4 -> V_230 = V_133 ;
V_5 -> V_12 = V_22 | V_23 ;
} else {
V_5 -> V_12 = V_24 ;
}
}
void T_4 F_118 ( struct V_232 * V_233 )
{
if ( V_233 -> V_190 )
V_229 . V_190 = V_233 -> V_190 ;
if ( V_233 -> V_234 )
V_229 . V_234 = V_233 -> V_234 ;
if ( V_233 -> V_235 )
V_229 . V_235 = V_233 -> V_235 ;
V_136 = V_233 -> V_236 ;
V_141 = V_233 -> V_237 ;
V_229 . V_238 = V_233 -> V_238 ;
V_229 . V_239 = V_233 -> V_239 ;
}
static void F_119 ( struct V_2 * V_4 , int V_67 )
{
while ( ! ( F_15 ( V_4 ) & V_24 ) )
F_109 () ;
F_39 ( V_4 , V_67 ) ;
}
static void F_120 ( struct V_240 * V_241 , const char * V_242 , T_1 V_105 )
{
struct V_2 * V_4 = & V_243 [ V_241 -> V_244 ] . V_3 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_41 , V_149 ;
unsigned int V_104 ;
V_149 = F_48 ( V_4 ) ;
F_7 ( V_4 , V_58 | V_5 -> V_12 ) ;
V_104 = F_26 ( V_4 ) & V_52 ;
F_23 ( V_4 , V_51 ) ;
F_121 ( V_4 , V_242 , V_105 , F_119 ) ;
do {
V_41 = F_15 ( V_4 ) ;
} while ( ! ( V_41 & V_24 ) );
if ( V_104 )
F_23 ( V_4 , V_52 ) ;
F_12 ( V_4 , V_149 ) ;
}
static void T_4 F_122 ( struct V_2 * V_4 , int * V_151 ,
int * V_82 , int * V_245 )
{
unsigned int V_246 , V_150 ;
V_150 = F_123 ( V_4 ) & V_247 ;
if ( ! V_150 )
return;
V_246 = F_8 ( V_4 ) & V_153 ;
if ( V_246 == V_166 )
* V_245 = 8 ;
else
* V_245 = 7 ;
V_246 = F_8 ( V_4 ) & V_155 ;
if ( V_246 == V_175 )
* V_82 = 'e' ;
else if ( V_246 == V_174 )
* V_82 = 'o' ;
* V_151 = V_4 -> V_156 / ( 16 * ( V_150 - 1 ) ) ;
}
static int T_4 F_124 ( struct V_240 * V_241 , char * V_248 )
{
struct V_2 * V_4 = & V_243 [ V_241 -> V_244 ] . V_3 ;
int V_151 = 115200 ;
int V_245 = 8 ;
int V_82 = 'n' ;
int V_249 = 'n' ;
if ( V_4 -> V_205 == NULL ) {
return - V_250 ;
}
F_87 ( V_243 [ V_241 -> V_244 ] . V_143 ) ;
F_7 ( V_4 , - 1 ) ;
F_20 ( V_4 , V_53 | V_137 ) ;
F_20 ( V_4 , V_138 | V_139 ) ;
if ( V_248 )
F_125 ( V_248 , & V_151 , & V_82 , & V_245 , & V_249 ) ;
else
F_122 ( V_4 , & V_151 , & V_82 , & V_245 ) ;
return F_126 ( V_4 , V_241 , V_151 , V_82 , V_245 , V_249 ) ;
}
static int T_4 F_127 ( void )
{
if ( V_251 ) {
struct V_224 * V_252 =
V_251 -> V_17 . V_225 ;
F_128 ( V_253 , V_252 -> V_193 , NULL ) ;
F_114 ( & V_243 [ V_252 -> V_193 ] ,
V_251 ) ;
F_129 ( & V_254 ) ;
}
return 0 ;
}
static int T_4 F_130 ( void )
{
if ( V_251
&& ! ( V_254 . V_15 & V_255 ) )
F_129 ( & V_254 ) ;
return 0 ;
}
static inline bool F_131 ( struct V_2 * V_4 )
{
return V_4 -> V_256 && V_4 -> V_256 -> V_244 == V_4 -> line ;
}
static inline bool F_131 ( struct V_2 * V_4 )
{
return false ;
}
static bool F_132 ( void )
{
#ifdef F_133
return F_134 () ;
#else
return false ;
#endif
}
static int F_135 ( struct V_198 * V_199 ,
T_5 V_89 )
{
struct V_2 * V_4 = F_136 ( V_199 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_131 ( V_4 ) && V_257 ) {
while ( ! ( F_15 ( V_4 ) & V_18 ) )
F_109 () ;
}
V_5 -> V_258 = F_137 ( & V_199 -> V_17 ) ;
if ( F_132 () )
F_138 ( & V_199 -> V_17 , 0 ) ;
F_139 ( & V_259 , V_4 ) ;
return 0 ;
}
static int F_140 ( struct V_198 * V_199 )
{
struct V_2 * V_4 = F_136 ( V_199 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_141 ( & V_259 , V_4 ) ;
F_138 ( & V_199 -> V_17 , V_5 -> V_258 ) ;
return 0 ;
}
static int T_3 F_142 ( struct V_198 * V_199 )
{
struct V_1 * V_4 ;
struct V_224 * V_252 = V_199 -> V_17 . V_225 ;
void * V_123 ;
int V_42 ;
F_143 ( V_75 & ( V_75 - 1 ) ) ;
V_4 = & V_243 [ V_252 -> V_193 ] ;
V_4 -> V_144 = 0 ;
F_114 ( V_4 , V_199 ) ;
if ( ! F_3 ( & V_4 -> V_3 ) ) {
V_42 = - V_135 ;
V_123 = F_76 ( sizeof( struct V_71 )
* V_75 , V_134 ) ;
if ( ! V_123 )
goto V_260;
V_4 -> V_70 . V_76 = V_123 ;
}
V_42 = F_144 ( & V_259 , & V_4 -> V_3 ) ;
if ( V_42 )
goto V_261;
#ifdef F_145
if ( F_131 ( & V_4 -> V_3 )
&& V_262 -> V_15 & V_255 ) {
F_88 ( V_4 -> V_143 ) ;
}
#endif
F_146 ( & V_199 -> V_17 , 1 ) ;
F_147 ( V_199 , V_4 ) ;
if ( V_4 -> V_14 . V_15 & V_16 ) {
F_11 ( & V_4 -> V_3 , V_179 ) ;
F_20 ( & V_4 -> V_3 , V_32 ) ;
}
return 0 ;
V_261:
F_78 ( V_4 -> V_70 . V_76 ) ;
V_4 -> V_70 . V_76 = NULL ;
V_260:
if ( ! F_131 ( & V_4 -> V_3 ) ) {
F_148 ( V_4 -> V_143 ) ;
V_4 -> V_143 = NULL ;
}
return V_42 ;
}
static int T_6 F_149 ( struct V_198 * V_199 )
{
struct V_2 * V_4 = F_136 ( V_199 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_42 = 0 ;
F_146 ( & V_199 -> V_17 , 0 ) ;
F_147 ( V_199 , NULL ) ;
V_42 = F_150 ( & V_259 , V_4 ) ;
F_151 ( & V_5 -> V_87 ) ;
F_78 ( V_5 -> V_70 . V_76 ) ;
F_148 ( V_5 -> V_143 ) ;
return V_42 ;
}
static int T_4 F_152 ( void )
{
int V_42 ;
V_42 = F_153 ( & V_259 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_154 ( & V_263 ) ;
if ( V_42 )
F_155 ( & V_259 ) ;
return V_42 ;
}
static void T_7 F_156 ( void )
{
F_157 ( & V_263 ) ;
F_155 ( & V_259 ) ;
}
