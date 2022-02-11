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
F_30 ( struct V_2 * V_4 , unsigned int V_40 ,
unsigned int V_67 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_68 * V_69 = & V_5 -> V_70 ;
struct V_71 * V_72 ;
if ( ! F_31 ( V_69 -> V_73 , V_69 -> V_74 , V_75 ) )
return;
V_72 = & ( (struct V_71 * ) V_69 -> V_76 ) [ V_69 -> V_73 ] ;
V_72 -> V_40 = V_40 ;
V_72 -> V_67 = V_67 ;
F_32 () ;
V_69 -> V_73 = ( V_69 -> V_73 + 1 ) & ( V_75 - 1 ) ;
}
static void F_33 ( struct V_2 * V_4 , unsigned int V_40 )
{
F_20 ( V_4 , V_53 ) ;
if ( V_40 & V_77 ) {
V_40 &= ~ ( V_78 | V_79 ) ;
V_4 -> V_80 . V_81 ++ ;
}
if ( V_40 & V_78 )
V_4 -> V_80 . V_82 ++ ;
if ( V_40 & V_79 )
V_4 -> V_80 . V_83 ++ ;
if ( V_40 & V_84 )
V_4 -> V_80 . V_85 ++ ;
}
static void F_34 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_40 , V_67 ;
V_40 = F_15 ( V_4 ) ;
while ( V_40 & V_58 ) {
V_67 = F_35 ( V_4 ) ;
if ( F_36 ( V_40 & ( V_78 | V_79
| V_84 | V_77 )
|| V_5 -> V_86 ) ) {
F_20 ( V_4 , V_53 ) ;
if ( V_40 & V_77
&& ! V_5 -> V_86 ) {
V_5 -> V_86 = 1 ;
F_12 ( V_4 , V_77 ) ;
} else {
F_7 ( V_4 , V_77 ) ;
V_40 &= ~ V_77 ;
V_5 -> V_86 = 0 ;
}
}
F_30 ( V_4 , V_40 , V_67 ) ;
V_40 = F_15 ( V_4 ) ;
}
F_37 ( & V_5 -> V_87 ) ;
}
static void F_38 ( struct V_2 * V_4 )
{
struct V_68 * V_88 = & V_4 -> V_89 -> V_88 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_4 -> V_90 && F_15 ( V_4 ) & V_5 -> V_13 ) {
F_39 ( V_4 , V_4 -> V_90 ) ;
V_4 -> V_80 . V_91 ++ ;
V_4 -> V_90 = 0 ;
}
if ( F_40 ( V_88 ) || F_41 ( V_4 ) )
return;
while ( F_15 ( V_4 ) & V_5 -> V_13 ) {
F_39 ( V_4 , V_88 -> V_76 [ V_88 -> V_74 ] ) ;
V_88 -> V_74 = ( V_88 -> V_74 + 1 ) & ( V_92 - 1 ) ;
V_4 -> V_80 . V_91 ++ ;
if ( F_40 ( V_88 ) )
break;
}
if ( F_42 ( V_88 ) < V_93 )
F_43 ( V_4 ) ;
if ( ! F_40 ( V_88 ) )
F_12 ( V_4 , V_5 -> V_13 ) ;
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
if ( V_94 & V_5 -> V_13 ) {
F_7 ( V_4 , V_5 -> V_13 ) ;
F_37 ( & V_5 -> V_87 ) ;
}
}
static void
F_46 ( struct V_2 * V_4 , unsigned int V_94 ,
unsigned int V_40 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( V_94 & ( V_60 | V_61 | V_62
| V_63 ) ) {
V_5 -> V_95 = V_40 ;
F_37 ( & V_5 -> V_87 ) ;
}
}
static T_2 F_47 ( int V_96 , void * V_97 )
{
struct V_2 * V_4 = V_97 ;
unsigned int V_40 , V_94 , V_98 = 0 ;
do {
V_40 = F_15 ( V_4 ) ;
V_94 = V_40 & F_48 ( V_4 ) ;
if ( ! V_94 )
break;
F_44 ( V_4 , V_94 ) ;
F_46 ( V_4 , V_94 , V_40 ) ;
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
F_23 ( V_4 , V_50 ) ;
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
F_12 ( V_4 , V_5 -> V_13 ) ;
} else {
if ( ( V_5 -> V_15 . V_11 & V_16 ) &&
! ( V_5 -> V_15 . V_11 & V_51 ) ) {
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
unsigned int V_40 ;
while ( V_69 -> V_73 != V_69 -> V_74 ) {
struct V_71 V_72 ;
F_56 () ;
V_72 = ( (struct V_71 * ) V_69 -> V_76 ) [ V_69 -> V_74 ] ;
V_69 -> V_74 = ( V_69 -> V_74 + 1 ) & ( V_75 - 1 ) ;
V_4 -> V_80 . V_111 ++ ;
V_40 = V_72 . V_40 ;
V_110 = V_112 ;
if ( F_36 ( V_40 & ( V_78 | V_79
| V_84 | V_77 ) ) ) {
if ( V_40 & V_77 ) {
V_40 &= ~ ( V_78 | V_79 ) ;
V_4 -> V_80 . V_81 ++ ;
if ( F_57 ( V_4 ) )
continue;
}
if ( V_40 & V_78 )
V_4 -> V_80 . V_82 ++ ;
if ( V_40 & V_79 )
V_4 -> V_80 . V_83 ++ ;
if ( V_40 & V_84 )
V_4 -> V_80 . V_85 ++ ;
V_40 &= V_4 -> V_56 ;
if ( V_40 & V_77 )
V_110 = V_113 ;
else if ( V_40 & V_78 )
V_110 = V_114 ;
else if ( V_40 & V_79 )
V_110 = V_115 ;
}
if ( F_58 ( V_4 , V_72 . V_67 ) )
continue;
F_59 ( V_4 , V_40 , V_84 , V_72 . V_67 , V_110 ) ;
}
F_60 ( & V_4 -> V_12 ) ;
F_61 ( V_4 -> V_89 -> V_4 . V_116 ) ;
F_62 ( & V_4 -> V_12 ) ;
}
static void F_63 ( struct V_2 * V_4 )
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
V_73 = F_64 ( V_4 ) - V_103 -> V_107 ;
V_74 = V_103 -> V_106 ;
V_73 = F_65 ( V_73 , V_103 -> V_108 ) ;
if ( F_66 ( V_73 != V_74 ) ) {
F_67 ( V_4 -> V_17 , V_103 -> V_107 ,
V_103 -> V_108 , V_122 ) ;
V_105 = V_73 - V_74 ;
F_68 ( V_116 , V_103 -> V_76 + V_103 -> V_106 , V_105 ) ;
F_51 ( V_4 -> V_17 , V_103 -> V_107 ,
V_103 -> V_108 , V_122 ) ;
V_4 -> V_80 . V_111 += V_105 ;
V_103 -> V_106 = V_73 ;
}
if ( V_73 >= V_103 -> V_108 ) {
V_103 -> V_106 = 0 ;
F_69 ( V_4 , V_103 -> V_107 ) ;
F_70 ( V_4 , V_103 -> V_108 ) ;
V_118 = ! V_118 ;
V_5 -> V_119 = V_118 ;
}
} while ( V_73 >= V_103 -> V_108 );
F_60 ( & V_4 -> V_12 ) ;
F_61 ( V_116 ) ;
F_62 ( & V_4 -> V_12 ) ;
F_12 ( V_4 , V_54 | V_55 ) ;
}
static void F_71 ( unsigned long V_123 )
{
struct V_2 * V_4 = (struct V_2 * ) V_123 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_40 ;
unsigned int V_124 ;
F_62 ( & V_4 -> V_12 ) ;
if ( F_4 ( V_4 ) )
F_49 ( V_4 ) ;
else
F_38 ( V_4 ) ;
V_40 = V_5 -> V_95 ;
V_124 = V_40 ^ V_5 -> V_125 ;
if ( V_124 & ( V_48 | V_46
| V_42 | V_44 ) ) {
if ( V_124 & V_48 )
V_4 -> V_80 . V_126 ++ ;
if ( V_124 & V_46 )
V_4 -> V_80 . V_127 ++ ;
if ( V_124 & V_42 )
F_72 ( V_4 , ! ( V_40 & V_42 ) ) ;
if ( V_124 & V_44 )
F_73 ( V_4 , ! ( V_40 & V_44 ) ) ;
F_74 ( & V_4 -> V_89 -> V_4 . V_128 ) ;
V_5 -> V_125 = V_40 ;
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
struct V_117 * V_116 = V_4 -> V_89 -> V_4 . V_116 ;
int V_129 ;
F_7 ( V_4 , - 1 ) ;
V_129 = F_76 ( V_4 -> V_96 , F_47 , V_130 ,
V_116 ? V_116 -> V_131 : L_3 , V_4 ) ;
if ( V_129 ) {
F_77 ( L_4 ) ;
return V_129 ;
}
if ( F_3 ( V_4 ) ) {
int V_132 ;
for ( V_132 = 0 ; V_132 < 2 ; V_132 ++ ) {
struct V_102 * V_103 = & V_5 -> V_121 [ V_132 ] ;
V_103 -> V_76 = F_78 ( V_133 , V_134 ) ;
if ( V_103 -> V_76 == NULL ) {
if ( V_132 != 0 ) {
F_79 ( V_4 -> V_17 ,
V_5 -> V_121 [ 0 ] . V_107 ,
V_133 ,
V_122 ) ;
F_80 ( V_5 -> V_121 [ 0 ] . V_76 ) ;
}
F_81 ( V_4 -> V_96 , V_4 ) ;
return - V_135 ;
}
V_103 -> V_107 = F_82 ( V_4 -> V_17 ,
V_103 -> V_76 ,
V_133 ,
V_122 ) ;
V_103 -> V_108 = V_133 ;
V_103 -> V_106 = 0 ;
}
V_5 -> V_119 = 0 ;
F_83 ( V_4 , V_5 -> V_121 [ 0 ] . V_107 ) ;
F_84 ( V_4 , V_133 ) ;
F_69 ( V_4 , V_5 -> V_121 [ 1 ] . V_107 ) ;
F_70 ( V_4 , V_133 ) ;
}
if ( F_4 ( V_4 ) ) {
struct V_102 * V_103 = & V_5 -> V_104 ;
struct V_68 * V_88 = & V_4 -> V_89 -> V_88 ;
V_103 -> V_76 = V_88 -> V_76 ;
V_103 -> V_107 = F_82 ( V_4 -> V_17 ,
V_103 -> V_76 ,
V_92 ,
V_109 ) ;
V_103 -> V_108 = V_92 ;
V_103 -> V_106 = 0 ;
}
if ( V_136 ) {
V_129 = V_136 ( V_4 ) ;
if ( V_129 ) {
F_81 ( V_4 -> V_96 , V_4 ) ;
return V_129 ;
}
}
V_5 -> V_125 = F_15 ( V_4 ) ;
V_5 -> V_95 = V_5 -> V_125 ;
F_20 ( V_4 , V_53 | V_137 ) ;
F_20 ( V_4 , V_138 | V_139 ) ;
if ( F_3 ( V_4 ) ) {
F_85 ( V_4 , V_140 ) ;
F_20 ( V_4 , V_120 ) ;
F_12 ( V_4 , V_54 | V_55 ) ;
F_23 ( V_4 , V_57 ) ;
} else {
F_12 ( V_4 , V_58 ) ;
}
return 0 ;
}
static void F_86 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_27 ( V_4 ) ;
F_22 ( V_4 ) ;
if ( F_3 ( V_4 ) ) {
int V_132 ;
for ( V_132 = 0 ; V_132 < 2 ; V_132 ++ ) {
struct V_102 * V_103 = & V_5 -> V_121 [ V_132 ] ;
F_79 ( V_4 -> V_17 ,
V_103 -> V_107 ,
V_103 -> V_108 ,
V_122 ) ;
F_80 ( V_103 -> V_76 ) ;
}
}
if ( F_4 ( V_4 ) ) {
struct V_102 * V_103 = & V_5 -> V_104 ;
F_79 ( V_4 -> V_17 ,
V_103 -> V_107 ,
V_103 -> V_108 ,
V_109 ) ;
}
F_20 ( V_4 , V_53 ) ;
F_7 ( V_4 , - 1 ) ;
F_81 ( V_4 -> V_96 , V_4 ) ;
if ( V_141 )
V_141 ( V_4 ) ;
}
static void F_87 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
F_54 ( V_4 , 0 ) ;
V_5 -> V_104 . V_106 = 0 ;
}
}
static void F_88 ( struct V_2 * V_4 , unsigned int V_89 ,
unsigned int V_142 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
switch ( V_89 ) {
case 0 :
F_89 ( V_5 -> V_143 ) ;
F_12 ( V_4 , V_5 -> V_144 ) ;
break;
case 3 :
V_5 -> V_144 = F_48 ( V_4 ) ;
F_7 ( V_4 , - 1 ) ;
F_90 ( V_5 -> V_143 ) ;
break;
default:
F_77 ( V_145 L_5 , V_89 ) ;
}
}
static void F_91 ( struct V_2 * V_4 , struct V_146 * V_147 ,
struct V_146 * V_148 )
{
unsigned long V_11 ;
unsigned int V_10 , V_149 , V_150 , V_151 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
V_10 = F_8 ( V_4 ) & ~ ( V_152 | V_153
| V_154 | V_155
| V_14 ) ;
V_151 = F_92 ( V_4 , V_147 , V_148 , 0 , V_4 -> V_156 / 16 ) ;
V_150 = F_93 ( V_4 , V_151 ) ;
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
F_6 ( & V_4 -> V_12 , V_11 ) ;
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
F_94 ( V_4 , V_147 -> V_158 , V_151 ) ;
V_149 = F_48 ( V_4 ) ;
F_7 ( V_4 , - 1 ) ;
F_20 ( V_4 , V_187 | V_188 ) ;
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
F_95 ( V_4 , V_150 ) ;
F_20 ( V_4 , V_53 | V_137 ) ;
F_20 ( V_4 , V_138 | V_139 ) ;
F_12 ( V_4 , V_149 ) ;
if ( F_96 ( V_4 , V_147 -> V_158 ) )
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
return - V_135 ;
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
if ( V_4 -> V_96 != V_206 -> V_96 )
V_41 = - V_208 ;
if ( V_206 -> V_209 != V_210 )
V_41 = - V_208 ;
if ( V_4 -> V_156 / 16 != V_206 -> V_211 )
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
while ( ! ( F_15 ( V_4 ) & V_58 ) )
F_109 () ;
return F_35 ( V_4 ) ;
}
static void F_110 ( struct V_2 * V_4 , unsigned char V_67 )
{
while ( ! ( F_15 ( V_4 ) & V_23 ) )
F_109 () ;
F_39 ( V_4 , V_67 ) ;
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
static void T_3 F_114 ( struct V_1 * V_5 ,
struct V_221 * V_222 )
{
T_4 V_223 [ 2 ] ;
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
static void T_3 F_117 ( struct V_1 * V_5 ,
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
V_4 -> V_96 = V_196 -> V_198 [ 1 ] . V_200 ;
F_118 ( & V_5 -> V_87 , F_71 ,
( unsigned long ) V_4 ) ;
memset ( & V_5 -> V_70 , 0 , sizeof( V_5 -> V_70 ) ) ;
if ( V_226 && V_226 -> V_234 ) {
V_4 -> V_202 = V_226 -> V_234 ;
} else {
V_4 -> V_11 |= V_201 ;
V_4 -> V_202 = NULL ;
}
if ( ! V_5 -> V_143 ) {
V_5 -> V_143 = F_119 ( & V_196 -> V_17 , L_12 ) ;
F_89 ( V_5 -> V_143 ) ;
V_4 -> V_156 = F_120 ( V_5 -> V_143 ) ;
F_90 ( V_5 -> V_143 ) ;
}
if ( V_5 -> V_15 . V_11 & V_16 )
V_5 -> V_13 = V_18 ;
else if ( F_4 ( V_4 ) ) {
V_4 -> V_233 = V_133 ;
V_5 -> V_13 = V_21 | V_22 ;
} else {
V_5 -> V_13 = V_23 ;
}
}
void T_5 F_121 ( struct V_235 * V_236 )
{
if ( V_236 -> V_190 )
V_232 . V_190 = V_236 -> V_190 ;
if ( V_236 -> V_237 )
V_232 . V_237 = V_236 -> V_237 ;
if ( V_236 -> V_238 )
V_232 . V_238 = V_236 -> V_238 ;
V_136 = V_236 -> V_239 ;
V_141 = V_236 -> V_240 ;
V_232 . V_241 = V_236 -> V_241 ;
V_232 . V_242 = V_236 -> V_242 ;
}
static void F_122 ( struct V_2 * V_4 , int V_67 )
{
while ( ! ( F_15 ( V_4 ) & V_23 ) )
F_109 () ;
F_39 ( V_4 , V_67 ) ;
}
static void F_123 ( struct V_243 * V_244 , const char * V_245 , T_1 V_105 )
{
struct V_2 * V_4 = & V_246 [ V_244 -> V_247 ] . V_3 ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_40 , V_149 ;
unsigned int V_104 ;
V_149 = F_48 ( V_4 ) ;
F_7 ( V_4 , V_58 | V_5 -> V_13 ) ;
V_104 = F_26 ( V_4 ) & V_52 ;
F_23 ( V_4 , V_50 ) ;
F_124 ( V_4 , V_245 , V_105 , F_122 ) ;
do {
V_40 = F_15 ( V_4 ) ;
} while ( ! ( V_40 & V_23 ) );
if ( V_104 )
F_23 ( V_4 , V_52 ) ;
F_12 ( V_4 , V_149 ) ;
}
static void T_5 F_125 ( struct V_2 * V_4 , int * V_151 ,
int * V_82 , int * V_248 )
{
unsigned int V_249 , V_150 ;
V_150 = F_126 ( V_4 ) & V_250 ;
if ( ! V_150 )
return;
V_249 = F_8 ( V_4 ) & V_153 ;
if ( V_249 == V_166 )
* V_248 = 8 ;
else
* V_248 = 7 ;
V_249 = F_8 ( V_4 ) & V_155 ;
if ( V_249 == V_175 )
* V_82 = 'e' ;
else if ( V_249 == V_174 )
* V_82 = 'o' ;
* V_151 = V_4 -> V_156 / ( 16 * ( V_150 - 1 ) ) ;
}
static int T_5 F_127 ( struct V_243 * V_244 , char * V_251 )
{
struct V_2 * V_4 = & V_246 [ V_244 -> V_247 ] . V_3 ;
int V_151 = 115200 ;
int V_248 = 8 ;
int V_82 = 'n' ;
int V_252 = 'n' ;
if ( V_4 -> V_202 == NULL ) {
return - V_253 ;
}
F_89 ( V_246 [ V_244 -> V_247 ] . V_143 ) ;
F_7 ( V_4 , - 1 ) ;
F_20 ( V_4 , V_53 | V_137 ) ;
F_20 ( V_4 , V_138 | V_139 ) ;
if ( V_251 )
F_128 ( V_251 , & V_151 , & V_82 , & V_248 , & V_252 ) ;
else
F_125 ( V_4 , & V_151 , & V_82 , & V_248 ) ;
return F_129 ( V_4 , V_244 , V_151 , V_82 , V_248 , V_252 ) ;
}
static int T_5 F_130 ( void )
{
if ( V_254 ) {
struct V_225 * V_226 =
V_254 -> V_17 . V_227 ;
int V_255 = V_226 -> V_256 ;
struct V_1 * V_4 = & V_246 [ V_255 ] ;
V_4 -> V_144 = 0 ;
V_4 -> V_3 . line = V_255 ;
F_131 ( V_257 , V_255 , NULL ) ;
F_117 ( V_4 , V_254 ) ;
F_132 ( & V_258 ) ;
}
return 0 ;
}
static int T_5 F_133 ( void )
{
if ( V_254
&& ! ( V_258 . V_11 & V_259 ) )
F_132 ( & V_258 ) ;
return 0 ;
}
static inline bool F_134 ( struct V_2 * V_4 )
{
return V_4 -> V_260 && V_4 -> V_260 -> V_247 == V_4 -> line ;
}
static inline bool F_134 ( struct V_2 * V_4 )
{
return false ;
}
static bool F_135 ( void )
{
#ifdef F_136
return F_137 () ;
#else
return false ;
#endif
}
static int F_138 ( struct V_195 * V_196 ,
T_6 V_89 )
{
struct V_2 * V_4 = F_139 ( V_196 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
if ( F_134 ( V_4 ) && V_261 ) {
while ( ! ( F_15 ( V_4 ) & V_18 ) )
F_109 () ;
}
V_5 -> V_262 = F_140 ( & V_196 -> V_17 ) ;
if ( F_135 () )
F_141 ( & V_196 -> V_17 , 0 ) ;
F_142 ( & V_263 , V_4 ) ;
return 0 ;
}
static int F_143 ( struct V_195 * V_196 )
{
struct V_2 * V_4 = F_139 ( V_196 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_144 ( & V_263 , V_4 ) ;
F_141 ( & V_196 -> V_17 , V_5 -> V_262 ) ;
return 0 ;
}
static int T_3 F_145 ( struct V_195 * V_196 )
{
struct V_1 * V_4 ;
struct V_221 * V_222 = V_196 -> V_17 . V_228 ;
struct V_225 * V_226 = V_196 -> V_17 . V_227 ;
void * V_123 ;
int V_41 = - V_253 ;
F_146 ( V_75 & ( V_75 - 1 ) ) ;
if ( V_222 )
V_41 = F_147 ( V_222 , L_13 ) ;
else
if ( V_226 )
V_41 = V_226 -> V_256 ;
if ( V_41 < 0 )
V_41 = F_148 ( & V_264 ,
sizeof( V_264 ) ) ;
if ( V_41 > V_265 ) {
V_41 = - V_253 ;
goto V_266;
}
if ( F_149 ( V_41 , & V_264 ) ) {
V_41 = - V_203 ;
goto V_266;
}
V_4 = & V_246 [ V_41 ] ;
V_4 -> V_144 = 0 ;
V_4 -> V_3 . line = V_41 ;
F_117 ( V_4 , V_196 ) ;
if ( ! F_3 ( & V_4 -> V_3 ) ) {
V_41 = - V_135 ;
V_123 = F_78 ( sizeof( struct V_71 )
* V_75 , V_134 ) ;
if ( ! V_123 )
goto V_267;
V_4 -> V_70 . V_76 = V_123 ;
}
V_41 = F_150 ( & V_263 , & V_4 -> V_3 ) ;
if ( V_41 )
goto V_268;
#ifdef F_151
if ( F_134 ( & V_4 -> V_3 )
&& V_269 -> V_11 & V_259 ) {
F_90 ( V_4 -> V_143 ) ;
}
#endif
F_152 ( & V_196 -> V_17 , 1 ) ;
F_153 ( V_196 , V_4 ) ;
if ( V_4 -> V_15 . V_11 & V_16 ) {
F_11 ( & V_4 -> V_3 , V_179 ) ;
F_20 ( & V_4 -> V_3 , V_31 ) ;
}
return 0 ;
V_268:
F_80 ( V_4 -> V_70 . V_76 ) ;
V_4 -> V_70 . V_76 = NULL ;
V_267:
if ( ! F_134 ( & V_4 -> V_3 ) ) {
F_154 ( V_4 -> V_143 ) ;
V_4 -> V_143 = NULL ;
}
V_266:
return V_41 ;
}
static int T_7 F_155 ( struct V_195 * V_196 )
{
struct V_2 * V_4 = F_139 ( V_196 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_41 = 0 ;
F_152 ( & V_196 -> V_17 , 0 ) ;
F_153 ( V_196 , NULL ) ;
V_41 = F_156 ( & V_263 , V_4 ) ;
F_157 ( & V_5 -> V_87 ) ;
F_80 ( V_5 -> V_70 . V_76 ) ;
F_158 ( V_4 -> line , & V_264 ) ;
F_154 ( V_5 -> V_143 ) ;
return V_41 ;
}
static int T_5 F_159 ( void )
{
int V_41 ;
V_41 = F_160 ( & V_263 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_161 ( & V_270 ) ;
if ( V_41 )
F_162 ( & V_263 ) ;
return V_41 ;
}
static void T_8 F_163 ( void )
{
F_164 ( & V_270 ) ;
F_162 ( & V_263 ) ;
}
