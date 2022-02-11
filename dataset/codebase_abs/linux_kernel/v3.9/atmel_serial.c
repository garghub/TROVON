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
unsigned long V_11 ;
F_6 ( & V_4 -> V_12 , V_11 ) ;
F_7 ( V_4 , V_5 -> V_13 ) ;
V_10 = F_8 ( V_4 ) ;
V_10 &= ~ V_14 ;
V_5 -> V_15 = * V_9 ;
if ( V_9 -> V_11 & V_16 ) {
F_9 ( V_4 -> V_17 , L_1 ) ;
V_5 -> V_13 = V_18 ;
if ( ( V_9 -> V_19 ) > 0 )
F_10 ( V_4 , V_9 -> V_19 ) ;
V_10 |= V_20 ;
} else {
F_9 ( V_4 -> V_17 , L_2 ) ;
if ( F_4 ( V_4 ) )
V_5 -> V_13 = V_21 |
V_22 ;
else
V_5 -> V_13 = V_23 ;
}
F_11 ( V_4 , V_10 ) ;
F_12 ( V_4 , V_5 -> V_13 ) ;
F_13 ( & V_4 -> V_12 , V_11 ) ;
}
static T_1 F_14 ( struct V_2 * V_4 )
{
return ( F_15 ( V_4 ) & V_18 ) ? V_24 : 0 ;
}
static void F_16 ( struct V_2 * V_4 , T_1 V_25 )
{
unsigned int V_26 = 0 ;
unsigned int V_10 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
#ifdef F_17
if ( F_18 () ) {
if ( V_4 -> V_27 == V_28 ) {
if ( V_25 & V_29 )
F_19 ( V_30 , 0 ) ;
else
F_19 ( V_30 , 1 ) ;
}
}
#endif
if ( V_25 & V_29 )
V_26 |= V_31 ;
else
V_26 |= V_32 ;
if ( V_25 & V_33 )
V_26 |= V_34 ;
else
V_26 |= V_35 ;
F_20 ( V_4 , V_26 ) ;
V_10 = F_8 ( V_4 ) & ~ V_36 ;
if ( V_25 & V_37 )
V_10 |= V_38 ;
else
V_10 |= V_39 ;
V_10 &= ~ V_14 ;
if ( V_5 -> V_15 . V_11 & V_16 ) {
F_9 ( V_4 -> V_17 , L_1 ) ;
if ( ( V_5 -> V_15 . V_19 ) > 0 )
F_10 ( V_4 ,
V_5 -> V_15 . V_19 ) ;
V_10 |= V_20 ;
} else {
F_9 ( V_4 -> V_17 , L_2 ) ;
}
F_11 ( V_4 , V_10 ) ;
}
static T_1 F_21 ( struct V_2 * V_4 )
{
unsigned int V_40 , V_41 = 0 ;
V_40 = F_15 ( V_4 ) ;
if ( ! ( V_40 & V_42 ) )
V_41 |= V_43 ;
if ( ! ( V_40 & V_44 ) )
V_41 |= V_45 ;
if ( ! ( V_40 & V_46 ) )
V_41 |= V_47 ;
if ( ! ( V_40 & V_48 ) )
V_41 |= V_49 ;
return V_41 ;
}
static void F_22 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
F_23 ( V_4 , V_50 ) ;
}
F_7 ( V_4 , V_5 -> V_13 ) ;
if ( ( V_5 -> V_15 . V_11 & V_16 ) &&
! ( V_5 -> V_15 . V_11 & V_51 ) )
F_24 ( V_4 ) ;
}
static void F_25 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
if ( F_26 ( V_4 ) & V_52 )
return;
if ( ( V_5 -> V_15 . V_11 & V_16 ) &&
! ( V_5 -> V_15 . V_11 & V_51 ) )
F_27 ( V_4 ) ;
F_23 ( V_4 , V_52 ) ;
}
F_12 ( V_4 , V_5 -> V_13 ) ;
}
static void F_24 ( struct V_2 * V_4 )
{
F_20 ( V_4 , V_53 ) ;
F_20 ( V_4 , V_54 ) ;
if ( F_3 ( V_4 ) ) {
F_12 ( V_4 , V_55 | V_56 |
V_4 -> V_57 ) ;
F_23 ( V_4 , V_58 ) ;
} else {
F_12 ( V_4 , V_59 ) ;
}
}
static void F_27 ( struct V_2 * V_4 )
{
F_20 ( V_4 , V_60 ) ;
if ( F_3 ( V_4 ) ) {
F_23 ( V_4 , V_61 ) ;
F_7 ( V_4 , V_55 | V_56 |
V_4 -> V_57 ) ;
} else {
F_7 ( V_4 , V_59 ) ;
}
}
static void F_28 ( struct V_2 * V_4 )
{
F_12 ( V_4 , V_62 | V_63
| V_64 | V_65 ) ;
}
static void F_29 ( struct V_2 * V_4 , int V_66 )
{
if ( V_66 != 0 )
F_20 ( V_4 , V_67 ) ;
else
F_20 ( V_4 , V_68 ) ;
}
static void
F_30 ( struct V_2 * V_4 , unsigned int V_40 ,
unsigned int V_69 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_70 * V_71 = & V_5 -> V_72 ;
struct V_73 * V_74 ;
if ( ! F_31 ( V_71 -> V_75 , V_71 -> V_76 , V_77 ) )
return;
V_74 = & ( (struct V_73 * ) V_71 -> V_78 ) [ V_71 -> V_75 ] ;
V_74 -> V_40 = V_40 ;
V_74 -> V_69 = V_69 ;
F_32 () ;
V_71 -> V_75 = ( V_71 -> V_75 + 1 ) & ( V_77 - 1 ) ;
}
static void F_33 ( struct V_2 * V_4 , unsigned int V_40 )
{
F_20 ( V_4 , V_53 ) ;
if ( V_40 & V_79 ) {
V_40 &= ~ ( V_80 | V_81 ) ;
V_4 -> V_82 . V_83 ++ ;
}
if ( V_40 & V_80 )
V_4 -> V_82 . V_84 ++ ;
if ( V_40 & V_81 )
V_4 -> V_82 . V_85 ++ ;
if ( V_40 & V_86 )
V_4 -> V_82 . V_87 ++ ;
}
static void F_34 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_40 , V_69 ;
V_40 = F_15 ( V_4 ) ;
while ( V_40 & V_59 ) {
V_69 = F_35 ( V_4 ) ;
if ( F_36 ( V_40 & ( V_80 | V_81
| V_86 | V_79 )
|| V_5 -> V_88 ) ) {
F_20 ( V_4 , V_53 ) ;
if ( V_40 & V_79
&& ! V_5 -> V_88 ) {
V_5 -> V_88 = 1 ;
F_12 ( V_4 , V_79 ) ;
} else {
F_7 ( V_4 , V_79 ) ;
V_40 &= ~ V_79 ;
V_5 -> V_88 = 0 ;
}
}
F_30 ( V_4 , V_40 , V_69 ) ;
V_40 = F_15 ( V_4 ) ;
}
F_37 ( & V_5 -> V_89 ) ;
}
static void F_38 ( struct V_2 * V_4 )
{
struct V_70 * V_90 = & V_4 -> V_91 -> V_90 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_4 -> V_92 && F_15 ( V_4 ) & V_5 -> V_13 ) {
F_39 ( V_4 , V_4 -> V_92 ) ;
V_4 -> V_82 . V_93 ++ ;
V_4 -> V_92 = 0 ;
}
if ( F_40 ( V_90 ) || F_41 ( V_4 ) )
return;
while ( F_15 ( V_4 ) & V_5 -> V_13 ) {
F_39 ( V_4 , V_90 -> V_78 [ V_90 -> V_76 ] ) ;
V_90 -> V_76 = ( V_90 -> V_76 + 1 ) & ( V_94 - 1 ) ;
V_4 -> V_82 . V_93 ++ ;
if ( F_40 ( V_90 ) )
break;
}
if ( F_42 ( V_90 ) < V_95 )
F_43 ( V_4 ) ;
if ( ! F_40 ( V_90 ) )
F_12 ( V_4 , V_5 -> V_13 ) ;
}
static void
F_44 ( struct V_2 * V_4 , unsigned int V_96 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_3 ( V_4 ) ) {
if ( V_96 & ( V_55 | V_56 ) ) {
F_7 ( V_4 , ( V_55
| V_56 ) ) ;
F_37 ( & V_5 -> V_89 ) ;
}
if ( V_96 & ( V_79 | V_86 |
V_81 | V_80 ) )
F_33 ( V_4 , V_96 ) ;
}
if ( V_96 & V_59 )
F_34 ( V_4 ) ;
else if ( V_96 & V_79 ) {
F_20 ( V_4 , V_53 ) ;
F_7 ( V_4 , V_79 ) ;
V_5 -> V_88 = 0 ;
}
}
static void
F_45 ( struct V_2 * V_4 , unsigned int V_96 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_96 & V_5 -> V_13 ) {
F_7 ( V_4 , V_5 -> V_13 ) ;
F_37 ( & V_5 -> V_89 ) ;
}
}
static void
F_46 ( struct V_2 * V_4 , unsigned int V_96 ,
unsigned int V_40 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_96 & ( V_62 | V_63 | V_64
| V_65 ) ) {
V_5 -> V_97 = V_40 ;
F_37 ( & V_5 -> V_89 ) ;
}
}
static T_2 F_47 ( int V_98 , void * V_99 )
{
struct V_2 * V_4 = V_99 ;
unsigned int V_40 , V_96 , V_100 = 0 ;
do {
V_40 = F_15 ( V_4 ) ;
V_96 = V_40 & F_48 ( V_4 ) ;
if ( ! V_96 )
break;
F_44 ( V_4 , V_96 ) ;
F_46 ( V_4 , V_96 , V_40 ) ;
F_45 ( V_4 , V_96 ) ;
} while ( V_100 ++ < V_101 );
return V_100 ? V_102 : V_103 ;
}
static void F_49 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_70 * V_90 = & V_4 -> V_91 -> V_90 ;
struct V_104 * V_105 = & V_5 -> V_106 ;
int V_107 ;
if ( F_50 ( V_4 ) )
return;
V_90 -> V_76 += V_105 -> V_108 ;
V_90 -> V_76 &= V_94 - 1 ;
V_4 -> V_82 . V_93 += V_105 -> V_108 ;
V_105 -> V_108 = 0 ;
F_23 ( V_4 , V_50 ) ;
if ( ! F_40 ( V_90 ) && ! F_41 ( V_4 ) ) {
F_51 ( V_4 -> V_17 ,
V_105 -> V_109 ,
V_105 -> V_110 ,
V_111 ) ;
V_107 = F_52 ( V_90 -> V_75 , V_90 -> V_76 , V_94 ) ;
V_105 -> V_108 = V_107 ;
F_53 ( V_4 , V_105 -> V_109 + V_90 -> V_76 ) ;
F_54 ( V_4 , V_107 ) ;
F_23 ( V_4 , V_52 ) ;
F_12 ( V_4 , V_5 -> V_13 ) ;
} else {
if ( ( V_5 -> V_15 . V_11 & V_16 ) &&
! ( V_5 -> V_15 . V_11 & V_51 ) ) {
F_24 ( V_4 ) ;
}
}
if ( F_42 ( V_90 ) < V_95 )
F_43 ( V_4 ) ;
}
static void F_55 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_70 * V_71 = & V_5 -> V_72 ;
unsigned int V_112 ;
unsigned int V_40 ;
while ( V_71 -> V_75 != V_71 -> V_76 ) {
struct V_73 V_74 ;
F_56 () ;
V_74 = ( (struct V_73 * ) V_71 -> V_78 ) [ V_71 -> V_76 ] ;
V_71 -> V_76 = ( V_71 -> V_76 + 1 ) & ( V_77 - 1 ) ;
V_4 -> V_82 . V_113 ++ ;
V_40 = V_74 . V_40 ;
V_112 = V_114 ;
if ( F_36 ( V_40 & ( V_80 | V_81
| V_86 | V_79 ) ) ) {
if ( V_40 & V_79 ) {
V_40 &= ~ ( V_80 | V_81 ) ;
V_4 -> V_82 . V_83 ++ ;
if ( F_57 ( V_4 ) )
continue;
}
if ( V_40 & V_80 )
V_4 -> V_82 . V_84 ++ ;
if ( V_40 & V_81 )
V_4 -> V_82 . V_85 ++ ;
if ( V_40 & V_86 )
V_4 -> V_82 . V_87 ++ ;
V_40 &= V_4 -> V_57 ;
if ( V_40 & V_79 )
V_112 = V_115 ;
else if ( V_40 & V_80 )
V_112 = V_116 ;
else if ( V_40 & V_81 )
V_112 = V_117 ;
}
if ( F_58 ( V_4 , V_74 . V_69 ) )
continue;
F_59 ( V_4 , V_40 , V_86 , V_74 . V_69 , V_112 ) ;
}
F_60 ( & V_4 -> V_12 ) ;
F_61 ( & V_4 -> V_91 -> V_4 ) ;
F_62 ( & V_4 -> V_12 ) ;
}
static void F_63 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_118 * V_119 = & V_4 -> V_91 -> V_4 ;
struct V_104 * V_105 ;
int V_120 = V_5 -> V_121 ;
unsigned int V_75 ;
unsigned int V_76 ;
unsigned int V_107 ;
do {
F_20 ( V_4 , V_122 ) ;
V_105 = & V_5 -> V_123 [ V_120 ] ;
V_75 = F_64 ( V_4 ) - V_105 -> V_109 ;
V_76 = V_105 -> V_108 ;
V_75 = F_65 ( V_75 , V_105 -> V_110 ) ;
if ( F_66 ( V_75 != V_76 ) ) {
F_67 ( V_4 -> V_17 , V_105 -> V_109 ,
V_105 -> V_110 , V_124 ) ;
V_107 = V_75 - V_76 ;
F_68 ( V_119 , V_105 -> V_78 + V_105 -> V_108 ,
V_107 ) ;
F_51 ( V_4 -> V_17 , V_105 -> V_109 ,
V_105 -> V_110 , V_124 ) ;
V_4 -> V_82 . V_113 += V_107 ;
V_105 -> V_108 = V_75 ;
}
if ( V_75 >= V_105 -> V_110 ) {
V_105 -> V_108 = 0 ;
F_69 ( V_4 , V_105 -> V_109 ) ;
F_70 ( V_4 , V_105 -> V_110 ) ;
V_120 = ! V_120 ;
V_5 -> V_121 = V_120 ;
}
} while ( V_75 >= V_105 -> V_110 );
F_60 ( & V_4 -> V_12 ) ;
F_61 ( V_119 ) ;
F_62 ( & V_4 -> V_12 ) ;
F_12 ( V_4 , V_55 | V_56 ) ;
}
static void F_71 ( unsigned long V_125 )
{
struct V_2 * V_4 = (struct V_2 * ) V_125 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_40 ;
unsigned int V_126 ;
F_62 ( & V_4 -> V_12 ) ;
if ( F_4 ( V_4 ) )
F_49 ( V_4 ) ;
else
F_38 ( V_4 ) ;
V_40 = V_5 -> V_97 ;
V_126 = V_40 ^ V_5 -> V_127 ;
if ( V_126 & ( V_48 | V_46
| V_42 | V_44 ) ) {
if ( V_126 & V_48 )
V_4 -> V_82 . V_128 ++ ;
if ( V_126 & V_46 )
V_4 -> V_82 . V_129 ++ ;
if ( V_126 & V_42 )
F_72 ( V_4 , ! ( V_40 & V_42 ) ) ;
if ( V_126 & V_44 )
F_73 ( V_4 , ! ( V_40 & V_44 ) ) ;
F_74 ( & V_4 -> V_91 -> V_4 . V_130 ) ;
V_5 -> V_127 = V_40 ;
}
if ( F_3 ( V_4 ) )
F_63 ( V_4 ) ;
else
F_55 ( V_4 ) ;
F_60 ( & V_4 -> V_12 ) ;
}
static int F_75 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_131 * V_132 = V_4 -> V_91 -> V_4 . V_132 ;
int V_133 ;
F_7 ( V_4 , - 1 ) ;
V_133 = F_76 ( V_4 -> V_98 , F_47 , V_134 ,
V_132 ? V_132 -> V_135 : L_3 , V_4 ) ;
if ( V_133 ) {
F_77 ( L_4 ) ;
return V_133 ;
}
if ( F_3 ( V_4 ) ) {
int V_136 ;
for ( V_136 = 0 ; V_136 < 2 ; V_136 ++ ) {
struct V_104 * V_105 = & V_5 -> V_123 [ V_136 ] ;
V_105 -> V_78 = F_78 ( V_137 , V_138 ) ;
if ( V_105 -> V_78 == NULL ) {
if ( V_136 != 0 ) {
F_79 ( V_4 -> V_17 ,
V_5 -> V_123 [ 0 ] . V_109 ,
V_137 ,
V_124 ) ;
F_80 ( V_5 -> V_123 [ 0 ] . V_78 ) ;
}
F_81 ( V_4 -> V_98 , V_4 ) ;
return - V_139 ;
}
V_105 -> V_109 = F_82 ( V_4 -> V_17 ,
V_105 -> V_78 ,
V_137 ,
V_124 ) ;
V_105 -> V_110 = V_137 ;
V_105 -> V_108 = 0 ;
}
V_5 -> V_121 = 0 ;
F_83 ( V_4 , V_5 -> V_123 [ 0 ] . V_109 ) ;
F_84 ( V_4 , V_137 ) ;
F_69 ( V_4 , V_5 -> V_123 [ 1 ] . V_109 ) ;
F_70 ( V_4 , V_137 ) ;
}
if ( F_4 ( V_4 ) ) {
struct V_104 * V_105 = & V_5 -> V_106 ;
struct V_70 * V_90 = & V_4 -> V_91 -> V_90 ;
V_105 -> V_78 = V_90 -> V_78 ;
V_105 -> V_109 = F_82 ( V_4 -> V_17 ,
V_105 -> V_78 ,
V_94 ,
V_111 ) ;
V_105 -> V_110 = V_94 ;
V_105 -> V_108 = 0 ;
}
if ( V_140 ) {
V_133 = V_140 ( V_4 ) ;
if ( V_133 ) {
F_81 ( V_4 -> V_98 , V_4 ) ;
return V_133 ;
}
}
V_5 -> V_127 = F_15 ( V_4 ) ;
V_5 -> V_97 = V_5 -> V_127 ;
F_20 ( V_4 , V_53 | V_141 ) ;
F_20 ( V_4 , V_142 | V_54 ) ;
if ( F_3 ( V_4 ) ) {
F_85 ( V_4 , V_143 ) ;
F_20 ( V_4 , V_122 ) ;
F_12 ( V_4 , V_55 | V_56 ) ;
F_23 ( V_4 , V_58 ) ;
} else {
F_12 ( V_4 , V_59 ) ;
}
return 0 ;
}
static void F_86 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_27 ( V_4 ) ;
F_22 ( V_4 ) ;
if ( F_3 ( V_4 ) ) {
int V_136 ;
for ( V_136 = 0 ; V_136 < 2 ; V_136 ++ ) {
struct V_104 * V_105 = & V_5 -> V_123 [ V_136 ] ;
F_79 ( V_4 -> V_17 ,
V_105 -> V_109 ,
V_105 -> V_110 ,
V_124 ) ;
F_80 ( V_105 -> V_78 ) ;
}
}
if ( F_4 ( V_4 ) ) {
struct V_104 * V_105 = & V_5 -> V_106 ;
F_79 ( V_4 -> V_17 ,
V_105 -> V_109 ,
V_105 -> V_110 ,
V_111 ) ;
}
F_20 ( V_4 , V_53 ) ;
F_7 ( V_4 , - 1 ) ;
F_81 ( V_4 -> V_98 , V_4 ) ;
if ( V_144 )
V_144 ( V_4 ) ;
}
static void F_87 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
F_54 ( V_4 , 0 ) ;
V_5 -> V_106 . V_108 = 0 ;
}
}
static void F_88 ( struct V_2 * V_4 , unsigned int V_91 ,
unsigned int V_145 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
switch ( V_91 ) {
case 0 :
F_89 ( V_5 -> V_146 ) ;
F_12 ( V_4 , V_5 -> V_147 ) ;
break;
case 3 :
V_5 -> V_147 = F_48 ( V_4 ) ;
F_7 ( V_4 , - 1 ) ;
F_90 ( V_5 -> V_146 ) ;
break;
default:
F_77 ( V_148 L_5 , V_91 ) ;
}
}
static void F_91 ( struct V_2 * V_4 , struct V_149 * V_150 ,
struct V_149 * V_151 )
{
unsigned long V_11 ;
unsigned int V_10 , V_152 , V_153 , V_154 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
V_10 = F_8 ( V_4 ) & ~ ( V_155 | V_156
| V_157 | V_158
| V_14 ) ;
V_154 = F_92 ( V_4 , V_150 , V_151 , 0 , V_4 -> V_159 / 16 ) ;
V_153 = F_93 ( V_4 , V_154 ) ;
if ( V_153 > 65535 ) {
V_153 /= 8 ;
V_10 |= V_160 ;
}
switch ( V_150 -> V_161 & V_162 ) {
case V_163 :
V_10 |= V_164 ;
break;
case V_165 :
V_10 |= V_166 ;
break;
case V_167 :
V_10 |= V_168 ;
break;
default:
V_10 |= V_169 ;
break;
}
if ( V_150 -> V_161 & V_170 )
V_10 |= V_171 ;
if ( V_150 -> V_161 & V_172 ) {
if ( V_150 -> V_161 & V_173 ) {
if ( V_150 -> V_161 & V_174 )
V_10 |= V_175 ;
else
V_10 |= V_176 ;
} else if ( V_150 -> V_161 & V_174 )
V_10 |= V_177 ;
else
V_10 |= V_178 ;
} else
V_10 |= V_179 ;
if ( V_150 -> V_161 & V_180 )
V_10 |= V_181 ;
else
V_10 |= V_182 ;
F_6 ( & V_4 -> V_12 , V_11 ) ;
V_4 -> V_57 = V_86 ;
if ( V_150 -> V_183 & V_184 )
V_4 -> V_57 |= ( V_81 | V_80 ) ;
if ( V_150 -> V_183 & ( V_185 | V_186 ) )
V_4 -> V_57 |= V_79 ;
if ( F_3 ( V_4 ) )
F_12 ( V_4 , V_4 -> V_57 ) ;
V_4 -> V_187 = 0 ;
if ( V_150 -> V_183 & V_188 )
V_4 -> V_187 |= ( V_81 | V_80 ) ;
if ( V_150 -> V_183 & V_189 ) {
V_4 -> V_187 |= V_79 ;
if ( V_150 -> V_183 & V_188 )
V_4 -> V_187 |= V_86 ;
}
F_94 ( V_4 , V_150 -> V_161 , V_154 ) ;
V_152 = F_48 ( V_4 ) ;
F_7 ( V_4 , - 1 ) ;
F_20 ( V_4 , V_190 | V_60 ) ;
V_10 &= ~ V_14 ;
if ( V_5 -> V_15 . V_11 & V_16 ) {
F_9 ( V_4 -> V_17 , L_1 ) ;
if ( ( V_5 -> V_15 . V_19 ) > 0 )
F_10 ( V_4 ,
V_5 -> V_15 . V_19 ) ;
V_10 |= V_20 ;
} else {
F_9 ( V_4 -> V_17 , L_2 ) ;
}
F_11 ( V_4 , V_10 ) ;
F_95 ( V_4 , V_153 ) ;
F_20 ( V_4 , V_53 | V_141 ) ;
F_20 ( V_4 , V_142 | V_54 ) ;
F_12 ( V_4 , V_152 ) ;
if ( F_96 ( V_4 , V_150 -> V_161 ) )
V_4 -> V_191 -> V_192 ( V_4 ) ;
F_13 ( & V_4 -> V_12 , V_11 ) ;
}
static void F_97 ( struct V_2 * V_4 , int V_193 )
{
if ( V_193 == V_194 ) {
V_4 -> V_11 |= V_195 ;
F_28 ( V_4 ) ;
} else {
V_4 -> V_11 &= ~ V_195 ;
}
}
static const char * F_98 ( struct V_2 * V_4 )
{
return ( V_4 -> type == V_196 ) ? L_6 : NULL ;
}
static void F_99 ( struct V_2 * V_4 )
{
struct V_197 * V_198 = F_100 ( V_4 -> V_17 ) ;
int V_199 = V_198 -> V_200 [ 0 ] . V_201 - V_198 -> V_200 [ 0 ] . V_202 + 1 ;
F_101 ( V_4 -> V_27 , V_199 ) ;
if ( V_4 -> V_11 & V_203 ) {
F_102 ( V_4 -> V_204 ) ;
V_4 -> V_204 = NULL ;
}
}
static int F_103 ( struct V_2 * V_4 )
{
struct V_197 * V_198 = F_100 ( V_4 -> V_17 ) ;
int V_199 = V_198 -> V_200 [ 0 ] . V_201 - V_198 -> V_200 [ 0 ] . V_202 + 1 ;
if ( ! F_104 ( V_4 -> V_27 , V_199 , L_3 ) )
return - V_205 ;
if ( V_4 -> V_11 & V_203 ) {
V_4 -> V_204 = F_105 ( V_4 -> V_27 , V_199 ) ;
if ( V_4 -> V_204 == NULL ) {
F_101 ( V_4 -> V_27 , V_199 ) ;
return - V_139 ;
}
}
return 0 ;
}
static void F_106 ( struct V_2 * V_4 , int V_11 )
{
if ( V_11 & V_206 ) {
V_4 -> type = V_196 ;
F_103 ( V_4 ) ;
}
}
static int F_107 ( struct V_2 * V_4 , struct V_207 * V_208 )
{
int V_41 = 0 ;
if ( V_208 -> type != V_209 && V_208 -> type != V_196 )
V_41 = - V_210 ;
if ( V_4 -> V_98 != V_208 -> V_98 )
V_41 = - V_210 ;
if ( V_208 -> V_211 != V_212 )
V_41 = - V_210 ;
if ( V_4 -> V_159 / 16 != V_208 -> V_213 )
V_41 = - V_210 ;
if ( ( void * ) V_4 -> V_27 != V_208 -> V_214 )
V_41 = - V_210 ;
if ( V_4 -> V_215 != V_208 -> V_4 )
V_41 = - V_210 ;
if ( V_208 -> V_216 != 0 )
V_41 = - V_210 ;
return V_41 ;
}
static int F_108 ( struct V_2 * V_4 )
{
while ( ! ( F_15 ( V_4 ) & V_59 ) )
F_109 () ;
return F_35 ( V_4 ) ;
}
static void F_110 ( struct V_2 * V_4 , unsigned char V_69 )
{
while ( ! ( F_15 ( V_4 ) & V_23 ) )
F_109 () ;
F_39 ( V_4 , V_69 ) ;
}
static int
F_111 ( struct V_2 * V_4 , unsigned int V_217 , unsigned long V_218 )
{
struct V_8 V_9 ;
switch ( V_217 ) {
case V_219 :
if ( F_112 ( & V_9 , (struct V_8 * ) V_218 ,
sizeof( V_9 ) ) )
return - V_220 ;
F_5 ( V_4 , & V_9 ) ;
break;
case V_221 :
if ( F_113 ( (struct V_8 * ) V_218 ,
& ( F_1 ( V_4 ) -> V_15 ) ,
sizeof( V_9 ) ) )
return - V_220 ;
break;
default:
return - V_222 ;
}
return 0 ;
}
static void F_114 ( struct V_1 * V_5 ,
struct V_223 * V_224 )
{
T_3 V_225 [ 2 ] ;
if ( F_115 ( V_224 , L_7 , NULL ) )
V_5 -> V_6 = 1 ;
else
V_5 -> V_6 = 0 ;
if ( F_115 ( V_224 , L_8 , NULL ) )
V_5 -> V_7 = 1 ;
else
V_5 -> V_7 = 0 ;
if ( F_116 ( V_224 , L_9 ,
V_225 , 2 ) == 0 ) {
struct V_8 * V_9 = & V_5 -> V_15 ;
V_9 -> V_226 = V_225 [ 0 ] ;
V_9 -> V_19 = V_225 [ 1 ] ;
V_9 -> V_11 = 0 ;
if ( F_115 ( V_224 , L_10 , NULL ) )
V_9 -> V_11 |= V_51 ;
if ( F_115 ( V_224 , L_11 , NULL ) )
V_9 -> V_11 |= V_16 ;
}
}
static void F_117 ( struct V_1 * V_5 ,
struct V_197 * V_198 )
{
struct V_2 * V_4 = & V_5 -> V_3 ;
struct V_227 * V_228 = V_198 -> V_17 . V_229 ;
if ( V_198 -> V_17 . V_230 ) {
F_114 ( V_5 , V_198 -> V_17 . V_230 ) ;
} else {
V_5 -> V_6 = V_228 -> V_6 ;
V_5 -> V_7 = V_228 -> V_7 ;
V_5 -> V_15 = V_228 -> V_15 ;
}
V_4 -> V_231 = V_232 ;
V_4 -> V_11 = V_233 ;
V_4 -> V_191 = & V_234 ;
V_4 -> V_235 = 1 ;
V_4 -> V_17 = & V_198 -> V_17 ;
V_4 -> V_27 = V_198 -> V_200 [ 0 ] . V_202 ;
V_4 -> V_98 = V_198 -> V_200 [ 1 ] . V_202 ;
F_118 ( & V_5 -> V_89 , F_71 ,
( unsigned long ) V_4 ) ;
memset ( & V_5 -> V_72 , 0 , sizeof( V_5 -> V_72 ) ) ;
if ( V_228 && V_228 -> V_236 ) {
V_4 -> V_204 = V_228 -> V_236 ;
} else {
V_4 -> V_11 |= V_203 ;
V_4 -> V_204 = NULL ;
}
if ( ! V_5 -> V_146 ) {
V_5 -> V_146 = F_119 ( & V_198 -> V_17 , L_12 ) ;
F_89 ( V_5 -> V_146 ) ;
V_4 -> V_159 = F_120 ( V_5 -> V_146 ) ;
F_90 ( V_5 -> V_146 ) ;
}
if ( V_5 -> V_15 . V_11 & V_16 )
V_5 -> V_13 = V_18 ;
else if ( F_4 ( V_4 ) ) {
V_4 -> V_235 = V_137 ;
V_5 -> V_13 = V_21 | V_22 ;
} else {
V_5 -> V_13 = V_23 ;
}
}
static void F_121 ( struct V_2 * V_4 , int V_69 )
{
while ( ! ( F_15 ( V_4 ) & V_23 ) )
F_109 () ;
F_39 ( V_4 , V_69 ) ;
}
static void F_122 ( struct V_237 * V_238 , const char * V_239 , T_1 V_107 )
{
struct V_2 * V_4 = & V_240 [ V_238 -> V_241 ] . V_3 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_40 , V_152 ;
unsigned int V_106 ;
V_152 = F_48 ( V_4 ) ;
F_7 ( V_4 , V_59 | V_5 -> V_13 ) ;
V_106 = F_26 ( V_4 ) & V_52 ;
F_23 ( V_4 , V_50 ) ;
F_123 ( V_4 , V_239 , V_107 , F_121 ) ;
do {
V_40 = F_15 ( V_4 ) ;
} while ( ! ( V_40 & V_23 ) );
if ( V_106 )
F_23 ( V_4 , V_52 ) ;
F_12 ( V_4 , V_152 ) ;
}
static void T_4 F_124 ( struct V_2 * V_4 , int * V_154 ,
int * V_84 , int * V_242 )
{
unsigned int V_243 , V_153 ;
V_153 = F_125 ( V_4 ) & V_244 ;
if ( ! V_153 )
return;
V_243 = F_8 ( V_4 ) & V_156 ;
if ( V_243 == V_169 )
* V_242 = 8 ;
else
* V_242 = 7 ;
V_243 = F_8 ( V_4 ) & V_158 ;
if ( V_243 == V_178 )
* V_84 = 'e' ;
else if ( V_243 == V_177 )
* V_84 = 'o' ;
* V_154 = V_4 -> V_159 / ( 16 * ( V_153 - 1 ) ) ;
}
static int T_4 F_126 ( struct V_237 * V_238 , char * V_245 )
{
struct V_2 * V_4 = & V_240 [ V_238 -> V_241 ] . V_3 ;
int V_154 = 115200 ;
int V_242 = 8 ;
int V_84 = 'n' ;
int V_246 = 'n' ;
if ( V_4 -> V_204 == NULL ) {
return - V_247 ;
}
F_89 ( V_240 [ V_238 -> V_241 ] . V_146 ) ;
F_7 ( V_4 , - 1 ) ;
F_20 ( V_4 , V_53 | V_141 ) ;
F_20 ( V_4 , V_142 | V_54 ) ;
if ( V_245 )
F_127 ( V_245 , & V_154 , & V_84 , & V_242 , & V_246 ) ;
else
F_124 ( V_4 , & V_154 , & V_84 , & V_242 ) ;
return F_128 ( V_4 , V_238 , V_154 , V_84 , V_242 , V_246 ) ;
}
static int T_4 F_129 ( void )
{
if ( V_248 ) {
struct V_227 * V_228 =
V_248 -> V_17 . V_229 ;
int V_249 = V_228 -> V_250 ;
struct V_1 * V_4 = & V_240 [ V_249 ] ;
V_4 -> V_147 = 0 ;
V_4 -> V_3 . line = V_249 ;
F_130 ( V_251 , V_249 , NULL ) ;
F_117 ( V_4 , V_248 ) ;
F_131 ( & V_252 ) ;
}
return 0 ;
}
static int T_4 F_132 ( void )
{
if ( V_248
&& ! ( V_252 . V_11 & V_253 ) )
F_131 ( & V_252 ) ;
return 0 ;
}
static inline bool F_133 ( struct V_2 * V_4 )
{
return V_4 -> V_254 && V_4 -> V_254 -> V_241 == V_4 -> line ;
}
static inline bool F_133 ( struct V_2 * V_4 )
{
return false ;
}
static bool F_134 ( void )
{
#ifdef F_135
return F_136 () ;
#else
return false ;
#endif
}
static int F_137 ( struct V_197 * V_198 ,
T_5 V_91 )
{
struct V_2 * V_4 = F_138 ( V_198 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_133 ( V_4 ) && V_255 ) {
while ( ! ( F_15 ( V_4 ) & V_18 ) )
F_109 () ;
}
V_5 -> V_256 = F_139 ( & V_198 -> V_17 ) ;
if ( F_134 () )
F_140 ( & V_198 -> V_17 , 0 ) ;
F_141 ( & V_257 , V_4 ) ;
return 0 ;
}
static int F_142 ( struct V_197 * V_198 )
{
struct V_2 * V_4 = F_138 ( V_198 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_143 ( & V_257 , V_4 ) ;
F_140 ( & V_198 -> V_17 , V_5 -> V_256 ) ;
return 0 ;
}
static int F_144 ( struct V_197 * V_198 )
{
struct V_1 * V_4 ;
struct V_223 * V_224 = V_198 -> V_17 . V_230 ;
struct V_227 * V_228 = V_198 -> V_17 . V_229 ;
void * V_125 ;
int V_41 = - V_247 ;
struct V_258 * V_258 ;
F_145 ( V_77 & ( V_77 - 1 ) ) ;
if ( V_224 )
V_41 = F_146 ( V_224 , L_13 ) ;
else
if ( V_228 )
V_41 = V_228 -> V_250 ;
if ( V_41 < 0 )
V_41 = F_147 ( V_259 , V_260 ) ;
if ( V_41 >= V_260 ) {
V_41 = - V_247 ;
goto V_261;
}
if ( F_148 ( V_41 , V_259 ) ) {
V_41 = - V_205 ;
goto V_261;
}
V_4 = & V_240 [ V_41 ] ;
V_4 -> V_147 = 0 ;
V_4 -> V_3 . line = V_41 ;
F_117 ( V_4 , V_198 ) ;
V_258 = F_149 ( & V_198 -> V_17 ) ;
if ( F_150 ( V_258 ) ) {
V_41 = F_151 ( V_258 ) ;
goto V_261;
}
if ( ! F_3 ( & V_4 -> V_3 ) ) {
V_41 = - V_139 ;
V_125 = F_78 ( sizeof( struct V_73 )
* V_77 , V_138 ) ;
if ( ! V_125 )
goto V_262;
V_4 -> V_72 . V_78 = V_125 ;
}
V_41 = F_152 ( & V_257 , & V_4 -> V_3 ) ;
if ( V_41 )
goto V_263;
#ifdef F_153
if ( F_133 ( & V_4 -> V_3 )
&& V_264 -> V_11 & V_253 ) {
F_90 ( V_4 -> V_146 ) ;
}
#endif
F_154 ( & V_198 -> V_17 , 1 ) ;
F_155 ( V_198 , V_4 ) ;
if ( V_4 -> V_15 . V_11 & V_16 ) {
F_11 ( & V_4 -> V_3 , V_182 ) ;
F_20 ( & V_4 -> V_3 , V_31 ) ;
}
return 0 ;
V_263:
F_80 ( V_4 -> V_72 . V_78 ) ;
V_4 -> V_72 . V_78 = NULL ;
V_262:
if ( ! F_133 ( & V_4 -> V_3 ) ) {
F_156 ( V_4 -> V_146 ) ;
V_4 -> V_146 = NULL ;
}
V_261:
return V_41 ;
}
static int F_157 ( struct V_197 * V_198 )
{
struct V_2 * V_4 = F_138 ( V_198 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_41 = 0 ;
F_154 ( & V_198 -> V_17 , 0 ) ;
F_155 ( V_198 , NULL ) ;
V_41 = F_158 ( & V_257 , V_4 ) ;
F_159 ( & V_5 -> V_89 ) ;
F_80 ( V_5 -> V_72 . V_78 ) ;
F_160 ( V_4 -> line , V_259 ) ;
F_156 ( V_5 -> V_146 ) ;
return V_41 ;
}
static int T_4 F_161 ( void )
{
int V_41 ;
V_41 = F_162 ( & V_257 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_163 ( & V_265 ) ;
if ( V_41 )
F_164 ( & V_257 ) ;
return V_41 ;
}
static void T_6 F_165 ( void )
{
F_166 ( & V_265 ) ;
F_164 ( & V_257 ) ;
}
