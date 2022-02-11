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
F_61 ( V_4 -> V_91 -> V_4 . V_118 ) ;
F_62 ( & V_4 -> V_12 ) ;
}
static void F_63 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_119 * V_118 = V_4 -> V_91 -> V_4 . V_118 ;
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
F_68 ( V_118 , V_105 -> V_78 + V_105 -> V_108 , V_107 ) ;
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
F_61 ( V_118 ) ;
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
struct V_119 * V_118 = V_4 -> V_91 -> V_4 . V_118 ;
int V_131 ;
F_7 ( V_4 , - 1 ) ;
V_131 = F_76 ( V_4 -> V_98 , F_47 , V_132 ,
V_118 ? V_118 -> V_133 : L_3 , V_4 ) ;
if ( V_131 ) {
F_77 ( L_4 ) ;
return V_131 ;
}
if ( F_3 ( V_4 ) ) {
int V_134 ;
for ( V_134 = 0 ; V_134 < 2 ; V_134 ++ ) {
struct V_104 * V_105 = & V_5 -> V_123 [ V_134 ] ;
V_105 -> V_78 = F_78 ( V_135 , V_136 ) ;
if ( V_105 -> V_78 == NULL ) {
if ( V_134 != 0 ) {
F_79 ( V_4 -> V_17 ,
V_5 -> V_123 [ 0 ] . V_109 ,
V_135 ,
V_124 ) ;
F_80 ( V_5 -> V_123 [ 0 ] . V_78 ) ;
}
F_81 ( V_4 -> V_98 , V_4 ) ;
return - V_137 ;
}
V_105 -> V_109 = F_82 ( V_4 -> V_17 ,
V_105 -> V_78 ,
V_135 ,
V_124 ) ;
V_105 -> V_110 = V_135 ;
V_105 -> V_108 = 0 ;
}
V_5 -> V_121 = 0 ;
F_83 ( V_4 , V_5 -> V_123 [ 0 ] . V_109 ) ;
F_84 ( V_4 , V_135 ) ;
F_69 ( V_4 , V_5 -> V_123 [ 1 ] . V_109 ) ;
F_70 ( V_4 , V_135 ) ;
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
if ( V_138 ) {
V_131 = V_138 ( V_4 ) ;
if ( V_131 ) {
F_81 ( V_4 -> V_98 , V_4 ) ;
return V_131 ;
}
}
V_5 -> V_127 = F_15 ( V_4 ) ;
V_5 -> V_97 = V_5 -> V_127 ;
F_20 ( V_4 , V_53 | V_139 ) ;
F_20 ( V_4 , V_140 | V_54 ) ;
if ( F_3 ( V_4 ) ) {
F_85 ( V_4 , V_141 ) ;
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
int V_134 ;
for ( V_134 = 0 ; V_134 < 2 ; V_134 ++ ) {
struct V_104 * V_105 = & V_5 -> V_123 [ V_134 ] ;
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
if ( V_142 )
V_142 ( V_4 ) ;
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
unsigned int V_143 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
switch ( V_91 ) {
case 0 :
F_89 ( V_5 -> V_144 ) ;
F_12 ( V_4 , V_5 -> V_145 ) ;
break;
case 3 :
V_5 -> V_145 = F_48 ( V_4 ) ;
F_7 ( V_4 , - 1 ) ;
F_90 ( V_5 -> V_144 ) ;
break;
default:
F_77 ( V_146 L_5 , V_91 ) ;
}
}
static void F_91 ( struct V_2 * V_4 , struct V_147 * V_148 ,
struct V_147 * V_149 )
{
unsigned long V_11 ;
unsigned int V_10 , V_150 , V_151 , V_152 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
V_10 = F_8 ( V_4 ) & ~ ( V_153 | V_154
| V_155 | V_156
| V_14 ) ;
V_152 = F_92 ( V_4 , V_148 , V_149 , 0 , V_4 -> V_157 / 16 ) ;
V_151 = F_93 ( V_4 , V_152 ) ;
if ( V_151 > 65535 ) {
V_151 /= 8 ;
V_10 |= V_158 ;
}
switch ( V_148 -> V_159 & V_160 ) {
case V_161 :
V_10 |= V_162 ;
break;
case V_163 :
V_10 |= V_164 ;
break;
case V_165 :
V_10 |= V_166 ;
break;
default:
V_10 |= V_167 ;
break;
}
if ( V_148 -> V_159 & V_168 )
V_10 |= V_169 ;
if ( V_148 -> V_159 & V_170 ) {
if ( V_148 -> V_159 & V_171 ) {
if ( V_148 -> V_159 & V_172 )
V_10 |= V_173 ;
else
V_10 |= V_174 ;
} else if ( V_148 -> V_159 & V_172 )
V_10 |= V_175 ;
else
V_10 |= V_176 ;
} else
V_10 |= V_177 ;
if ( V_148 -> V_159 & V_178 )
V_10 |= V_179 ;
else
V_10 |= V_180 ;
F_6 ( & V_4 -> V_12 , V_11 ) ;
V_4 -> V_57 = V_86 ;
if ( V_148 -> V_181 & V_182 )
V_4 -> V_57 |= ( V_81 | V_80 ) ;
if ( V_148 -> V_181 & ( V_183 | V_184 ) )
V_4 -> V_57 |= V_79 ;
if ( F_3 ( V_4 ) )
F_12 ( V_4 , V_4 -> V_57 ) ;
V_4 -> V_185 = 0 ;
if ( V_148 -> V_181 & V_186 )
V_4 -> V_185 |= ( V_81 | V_80 ) ;
if ( V_148 -> V_181 & V_187 ) {
V_4 -> V_185 |= V_79 ;
if ( V_148 -> V_181 & V_186 )
V_4 -> V_185 |= V_86 ;
}
F_94 ( V_4 , V_148 -> V_159 , V_152 ) ;
V_150 = F_48 ( V_4 ) ;
F_7 ( V_4 , - 1 ) ;
F_20 ( V_4 , V_188 | V_60 ) ;
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
F_95 ( V_4 , V_151 ) ;
F_20 ( V_4 , V_53 | V_139 ) ;
F_20 ( V_4 , V_140 | V_54 ) ;
F_12 ( V_4 , V_150 ) ;
if ( F_96 ( V_4 , V_148 -> V_159 ) )
V_4 -> V_189 -> V_190 ( V_4 ) ;
F_13 ( & V_4 -> V_12 , V_11 ) ;
}
static void F_97 ( struct V_2 * V_4 , int V_191 )
{
if ( V_191 == V_192 ) {
V_4 -> V_11 |= V_193 ;
F_28 ( V_4 ) ;
} else {
V_4 -> V_11 &= ~ V_193 ;
}
}
static const char * F_98 ( struct V_2 * V_4 )
{
return ( V_4 -> type == V_194 ) ? L_6 : NULL ;
}
static void F_99 ( struct V_2 * V_4 )
{
struct V_195 * V_196 = F_100 ( V_4 -> V_17 ) ;
int V_197 = V_196 -> V_198 [ 0 ] . V_199 - V_196 -> V_198 [ 0 ] . V_200 + 1 ;
F_101 ( V_4 -> V_27 , V_197 ) ;
if ( V_4 -> V_11 & V_201 ) {
F_102 ( V_4 -> V_202 ) ;
V_4 -> V_202 = NULL ;
}
}
static int F_103 ( struct V_2 * V_4 )
{
struct V_195 * V_196 = F_100 ( V_4 -> V_17 ) ;
int V_197 = V_196 -> V_198 [ 0 ] . V_199 - V_196 -> V_198 [ 0 ] . V_200 + 1 ;
if ( ! F_104 ( V_4 -> V_27 , V_197 , L_3 ) )
return - V_203 ;
if ( V_4 -> V_11 & V_201 ) {
V_4 -> V_202 = F_105 ( V_4 -> V_27 , V_197 ) ;
if ( V_4 -> V_202 == NULL ) {
F_101 ( V_4 -> V_27 , V_197 ) ;
return - V_137 ;
}
}
return 0 ;
}
static void F_106 ( struct V_2 * V_4 , int V_11 )
{
if ( V_11 & V_204 ) {
V_4 -> type = V_194 ;
F_103 ( V_4 ) ;
}
}
static int F_107 ( struct V_2 * V_4 , struct V_205 * V_206 )
{
int V_41 = 0 ;
if ( V_206 -> type != V_207 && V_206 -> type != V_194 )
V_41 = - V_208 ;
if ( V_4 -> V_98 != V_206 -> V_98 )
V_41 = - V_208 ;
if ( V_206 -> V_209 != V_210 )
V_41 = - V_208 ;
if ( V_4 -> V_157 / 16 != V_206 -> V_211 )
V_41 = - V_208 ;
if ( ( void * ) V_4 -> V_27 != V_206 -> V_212 )
V_41 = - V_208 ;
if ( V_4 -> V_213 != V_206 -> V_4 )
V_41 = - V_208 ;
if ( V_206 -> V_214 != 0 )
V_41 = - V_208 ;
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
F_111 ( struct V_2 * V_4 , unsigned int V_215 , unsigned long V_216 )
{
struct V_8 V_9 ;
switch ( V_215 ) {
case V_217 :
if ( F_112 ( & V_9 , (struct V_8 * ) V_216 ,
sizeof( V_9 ) ) )
return - V_218 ;
F_5 ( V_4 , & V_9 ) ;
break;
case V_219 :
if ( F_113 ( (struct V_8 * ) V_216 ,
& ( F_1 ( V_4 ) -> V_15 ) ,
sizeof( V_9 ) ) )
return - V_218 ;
break;
default:
return - V_220 ;
}
return 0 ;
}
static void F_114 ( struct V_1 * V_5 ,
struct V_221 * V_222 )
{
T_3 V_223 [ 2 ] ;
if ( F_115 ( V_222 , L_7 , NULL ) )
V_5 -> V_6 = 1 ;
else
V_5 -> V_6 = 0 ;
if ( F_115 ( V_222 , L_8 , NULL ) )
V_5 -> V_7 = 1 ;
else
V_5 -> V_7 = 0 ;
if ( F_116 ( V_222 , L_9 ,
V_223 , 2 ) == 0 ) {
struct V_8 * V_9 = & V_5 -> V_15 ;
V_9 -> V_224 = V_223 [ 0 ] ;
V_9 -> V_19 = V_223 [ 1 ] ;
V_9 -> V_11 = 0 ;
if ( F_115 ( V_222 , L_10 , NULL ) )
V_9 -> V_11 |= V_51 ;
if ( F_115 ( V_222 , L_11 , NULL ) )
V_9 -> V_11 |= V_16 ;
}
}
static void F_117 ( struct V_1 * V_5 ,
struct V_195 * V_196 )
{
struct V_2 * V_4 = & V_5 -> V_3 ;
struct V_225 * V_226 = V_196 -> V_17 . V_227 ;
if ( V_196 -> V_17 . V_228 ) {
F_114 ( V_5 , V_196 -> V_17 . V_228 ) ;
} else {
V_5 -> V_6 = V_226 -> V_6 ;
V_5 -> V_7 = V_226 -> V_7 ;
V_5 -> V_15 = V_226 -> V_15 ;
}
V_4 -> V_229 = V_230 ;
V_4 -> V_11 = V_231 ;
V_4 -> V_189 = & V_232 ;
V_4 -> V_233 = 1 ;
V_4 -> V_17 = & V_196 -> V_17 ;
V_4 -> V_27 = V_196 -> V_198 [ 0 ] . V_200 ;
V_4 -> V_98 = V_196 -> V_198 [ 1 ] . V_200 ;
F_118 ( & V_5 -> V_89 , F_71 ,
( unsigned long ) V_4 ) ;
memset ( & V_5 -> V_72 , 0 , sizeof( V_5 -> V_72 ) ) ;
if ( V_226 && V_226 -> V_234 ) {
V_4 -> V_202 = V_226 -> V_234 ;
} else {
V_4 -> V_11 |= V_201 ;
V_4 -> V_202 = NULL ;
}
if ( ! V_5 -> V_144 ) {
V_5 -> V_144 = F_119 ( & V_196 -> V_17 , L_12 ) ;
F_89 ( V_5 -> V_144 ) ;
V_4 -> V_157 = F_120 ( V_5 -> V_144 ) ;
F_90 ( V_5 -> V_144 ) ;
}
if ( V_5 -> V_15 . V_11 & V_16 )
V_5 -> V_13 = V_18 ;
else if ( F_4 ( V_4 ) ) {
V_4 -> V_233 = V_135 ;
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
static void F_122 ( struct V_235 * V_236 , const char * V_237 , T_1 V_107 )
{
struct V_2 * V_4 = & V_238 [ V_236 -> V_239 ] . V_3 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_40 , V_150 ;
unsigned int V_106 ;
V_150 = F_48 ( V_4 ) ;
F_7 ( V_4 , V_59 | V_5 -> V_13 ) ;
V_106 = F_26 ( V_4 ) & V_52 ;
F_23 ( V_4 , V_50 ) ;
F_123 ( V_4 , V_237 , V_107 , F_121 ) ;
do {
V_40 = F_15 ( V_4 ) ;
} while ( ! ( V_40 & V_23 ) );
if ( V_106 )
F_23 ( V_4 , V_52 ) ;
F_12 ( V_4 , V_150 ) ;
}
static void T_4 F_124 ( struct V_2 * V_4 , int * V_152 ,
int * V_84 , int * V_240 )
{
unsigned int V_241 , V_151 ;
V_151 = F_125 ( V_4 ) & V_242 ;
if ( ! V_151 )
return;
V_241 = F_8 ( V_4 ) & V_154 ;
if ( V_241 == V_167 )
* V_240 = 8 ;
else
* V_240 = 7 ;
V_241 = F_8 ( V_4 ) & V_156 ;
if ( V_241 == V_176 )
* V_84 = 'e' ;
else if ( V_241 == V_175 )
* V_84 = 'o' ;
* V_152 = V_4 -> V_157 / ( 16 * ( V_151 - 1 ) ) ;
}
static int T_4 F_126 ( struct V_235 * V_236 , char * V_243 )
{
struct V_2 * V_4 = & V_238 [ V_236 -> V_239 ] . V_3 ;
int V_152 = 115200 ;
int V_240 = 8 ;
int V_84 = 'n' ;
int V_244 = 'n' ;
if ( V_4 -> V_202 == NULL ) {
return - V_245 ;
}
F_89 ( V_238 [ V_236 -> V_239 ] . V_144 ) ;
F_7 ( V_4 , - 1 ) ;
F_20 ( V_4 , V_53 | V_139 ) ;
F_20 ( V_4 , V_140 | V_54 ) ;
if ( V_243 )
F_127 ( V_243 , & V_152 , & V_84 , & V_240 , & V_244 ) ;
else
F_124 ( V_4 , & V_152 , & V_84 , & V_240 ) ;
return F_128 ( V_4 , V_236 , V_152 , V_84 , V_240 , V_244 ) ;
}
static int T_4 F_129 ( void )
{
if ( V_246 ) {
struct V_225 * V_226 =
V_246 -> V_17 . V_227 ;
int V_247 = V_226 -> V_248 ;
struct V_1 * V_4 = & V_238 [ V_247 ] ;
V_4 -> V_145 = 0 ;
V_4 -> V_3 . line = V_247 ;
F_130 ( V_249 , V_247 , NULL ) ;
F_117 ( V_4 , V_246 ) ;
F_131 ( & V_250 ) ;
}
return 0 ;
}
static int T_4 F_132 ( void )
{
if ( V_246
&& ! ( V_250 . V_11 & V_251 ) )
F_131 ( & V_250 ) ;
return 0 ;
}
static inline bool F_133 ( struct V_2 * V_4 )
{
return V_4 -> V_252 && V_4 -> V_252 -> V_239 == V_4 -> line ;
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
static int F_137 ( struct V_195 * V_196 ,
T_5 V_91 )
{
struct V_2 * V_4 = F_138 ( V_196 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_133 ( V_4 ) && V_253 ) {
while ( ! ( F_15 ( V_4 ) & V_18 ) )
F_109 () ;
}
V_5 -> V_254 = F_139 ( & V_196 -> V_17 ) ;
if ( F_134 () )
F_140 ( & V_196 -> V_17 , 0 ) ;
F_141 ( & V_255 , V_4 ) ;
return 0 ;
}
static int F_142 ( struct V_195 * V_196 )
{
struct V_2 * V_4 = F_138 ( V_196 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_143 ( & V_255 , V_4 ) ;
F_140 ( & V_196 -> V_17 , V_5 -> V_254 ) ;
return 0 ;
}
static int F_144 ( struct V_195 * V_196 )
{
struct V_1 * V_4 ;
struct V_221 * V_222 = V_196 -> V_17 . V_228 ;
struct V_225 * V_226 = V_196 -> V_17 . V_227 ;
void * V_125 ;
int V_41 = - V_245 ;
struct V_256 * V_256 ;
F_145 ( V_77 & ( V_77 - 1 ) ) ;
if ( V_222 )
V_41 = F_146 ( V_222 , L_13 ) ;
else
if ( V_226 )
V_41 = V_226 -> V_248 ;
if ( V_41 < 0 )
V_41 = F_147 ( & V_257 ,
sizeof( V_257 ) ) ;
if ( V_41 > V_258 ) {
V_41 = - V_245 ;
goto V_259;
}
if ( F_148 ( V_41 , & V_257 ) ) {
V_41 = - V_203 ;
goto V_259;
}
V_4 = & V_238 [ V_41 ] ;
V_4 -> V_145 = 0 ;
V_4 -> V_3 . line = V_41 ;
F_117 ( V_4 , V_196 ) ;
V_256 = F_149 ( & V_196 -> V_17 ) ;
if ( F_150 ( V_256 ) ) {
V_41 = F_151 ( V_256 ) ;
goto V_259;
}
if ( ! F_3 ( & V_4 -> V_3 ) ) {
V_41 = - V_137 ;
V_125 = F_78 ( sizeof( struct V_73 )
* V_77 , V_136 ) ;
if ( ! V_125 )
goto V_260;
V_4 -> V_72 . V_78 = V_125 ;
}
V_41 = F_152 ( & V_255 , & V_4 -> V_3 ) ;
if ( V_41 )
goto V_261;
#ifdef F_153
if ( F_133 ( & V_4 -> V_3 )
&& V_262 -> V_11 & V_251 ) {
F_90 ( V_4 -> V_144 ) ;
}
#endif
F_154 ( & V_196 -> V_17 , 1 ) ;
F_155 ( V_196 , V_4 ) ;
if ( V_4 -> V_15 . V_11 & V_16 ) {
F_11 ( & V_4 -> V_3 , V_180 ) ;
F_20 ( & V_4 -> V_3 , V_31 ) ;
}
return 0 ;
V_261:
F_80 ( V_4 -> V_72 . V_78 ) ;
V_4 -> V_72 . V_78 = NULL ;
V_260:
if ( ! F_133 ( & V_4 -> V_3 ) ) {
F_156 ( V_4 -> V_144 ) ;
V_4 -> V_144 = NULL ;
}
V_259:
return V_41 ;
}
static int F_157 ( struct V_195 * V_196 )
{
struct V_2 * V_4 = F_138 ( V_196 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_41 = 0 ;
F_154 ( & V_196 -> V_17 , 0 ) ;
F_155 ( V_196 , NULL ) ;
V_41 = F_158 ( & V_255 , V_4 ) ;
F_159 ( & V_5 -> V_89 ) ;
F_80 ( V_5 -> V_72 . V_78 ) ;
F_160 ( V_4 -> line , & V_257 ) ;
F_156 ( V_5 -> V_144 ) ;
return V_41 ;
}
static int T_4 F_161 ( void )
{
int V_41 ;
V_41 = F_162 ( & V_255 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_163 ( & V_263 ) ;
if ( V_41 )
F_164 ( & V_255 ) ;
return V_41 ;
}
static void T_6 F_165 ( void )
{
F_166 ( & V_263 ) ;
F_164 ( & V_255 ) ;
}
