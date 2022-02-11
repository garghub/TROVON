static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline T_1 F_3 ( struct V_2 * V_4 , T_1 V_5 )
{
return F_4 ( V_4 -> V_6 + V_5 ) ;
}
static inline void F_5 ( struct V_2 * V_4 , T_1 V_5 , T_1 V_7 )
{
F_6 ( V_7 , V_4 -> V_6 + V_5 ) ;
}
static inline T_2 F_7 ( struct V_2 * V_4 )
{
return F_4 ( V_4 -> V_6 + V_8 ) ;
}
static inline void F_8 ( struct V_2 * V_4 , T_2 V_7 )
{
F_6 ( V_7 , V_4 -> V_6 + V_9 ) ;
}
static inline T_2 F_7 ( struct V_2 * V_4 )
{
return F_9 ( V_4 -> V_6 + V_8 ) ;
}
static inline void F_8 ( struct V_2 * V_4 , T_2 V_7 )
{
F_10 ( V_7 , V_4 -> V_6 + V_9 ) ;
}
static bool F_11 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
return V_10 -> V_11 ;
}
static bool F_12 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
return V_10 -> V_12 ;
}
static bool F_11 ( struct V_2 * V_4 )
{
return false ;
}
static bool F_12 ( struct V_2 * V_4 )
{
return false ;
}
static bool F_13 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
return V_10 -> V_13 ;
}
static bool F_14 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
return V_10 -> V_14 ;
}
static bool F_15 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
return V_10 -> V_15 ;
}
static unsigned int F_16 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_16 , V_17 = 0 ;
V_16 = F_3 ( V_4 , V_18 ) ;
F_17 ( V_10 -> V_19 , & V_17 ) ;
if ( ! F_18 ( F_19 ( V_10 -> V_19 ,
V_20 ) ) ) {
if ( V_17 & V_21 )
V_16 &= ~ V_22 ;
else
V_16 |= V_22 ;
}
if ( ! F_18 ( F_19 ( V_10 -> V_19 ,
V_23 ) ) ) {
if ( V_17 & V_24 )
V_16 &= ~ V_25 ;
else
V_16 |= V_25 ;
}
if ( ! F_18 ( F_19 ( V_10 -> V_19 ,
V_26 ) ) ) {
if ( V_17 & V_27 )
V_16 &= ~ V_28 ;
else
V_16 |= V_28 ;
}
if ( ! F_18 ( F_19 ( V_10 -> V_19 ,
V_29 ) ) ) {
if ( V_17 & V_30 )
V_16 &= ~ V_31 ;
else
V_16 |= V_31 ;
}
return V_16 ;
}
static int F_20 ( struct V_2 * V_4 ,
struct V_32 * V_33 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_34 ;
F_5 ( V_4 , V_35 , V_10 -> V_36 ) ;
V_34 = F_3 ( V_4 , V_37 ) ;
V_34 &= ~ V_38 ;
V_4 -> V_39 = * V_33 ;
if ( V_33 -> V_40 & V_41 ) {
F_21 ( V_4 -> V_42 , L_1 ) ;
V_10 -> V_36 = V_43 ;
F_5 ( V_4 , V_44 ,
V_33 -> V_45 ) ;
V_34 |= V_46 ;
} else {
F_21 ( V_4 -> V_42 , L_2 ) ;
if ( F_12 ( V_4 ) )
V_10 -> V_36 = V_47 |
V_48 ;
else
V_10 -> V_36 = V_49 ;
}
F_5 ( V_4 , V_37 , V_34 ) ;
F_5 ( V_4 , V_50 , V_10 -> V_36 ) ;
return 0 ;
}
static T_3 F_22 ( struct V_2 * V_4 )
{
return ( F_3 ( V_4 , V_18 ) & V_43 ) ?
V_51 :
0 ;
}
static void F_23 ( struct V_2 * V_4 , T_3 V_52 )
{
unsigned int V_53 = 0 ;
unsigned int V_34 = F_3 ( V_4 , V_37 ) ;
unsigned int V_54 , V_55 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( V_4 -> V_39 . V_40 & V_41 ) {
F_5 ( V_4 , V_44 ,
V_4 -> V_39 . V_45 ) ;
V_34 &= ~ V_38 ;
V_34 |= V_46 ;
}
if ( ( V_34 & V_38 ) == V_56 ) {
V_54 = V_57 ;
V_55 = V_58 ;
} else {
V_54 = V_58 ;
V_55 = V_57 ;
}
if ( V_52 & V_59 )
V_53 |= V_55 ;
else
V_53 |= V_54 ;
if ( V_52 & V_60 )
V_53 |= V_61 ;
else
V_53 |= V_62 ;
F_5 ( V_4 , V_63 , V_53 ) ;
F_24 ( V_10 -> V_19 , V_52 ) ;
V_34 &= ~ V_64 ;
if ( V_52 & V_65 )
V_34 |= V_66 ;
else
V_34 |= V_67 ;
F_5 ( V_4 , V_37 , V_34 ) ;
}
static T_3 F_25 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_17 = 0 , V_16 ;
V_16 = F_3 ( V_4 , V_18 ) ;
if ( ! ( V_16 & V_31 ) )
V_17 |= V_30 ;
if ( ! ( V_16 & V_22 ) )
V_17 |= V_21 ;
if ( ! ( V_16 & V_25 ) )
V_17 |= V_24 ;
if ( ! ( V_16 & V_28 ) )
V_17 |= V_27 ;
return F_17 ( V_10 -> V_19 , & V_17 ) ;
}
static void F_26 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_12 ( V_4 ) ) {
F_5 ( V_4 , V_68 , V_69 ) ;
}
F_5 ( V_4 , V_35 , V_10 -> V_36 ) ;
if ( ( V_4 -> V_39 . V_40 & V_41 ) &&
! ( V_4 -> V_39 . V_40 & V_70 ) )
F_27 ( V_4 ) ;
}
static void F_28 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_12 ( V_4 ) ) {
if ( F_3 ( V_4 , V_71 ) & V_72 )
return;
if ( ( V_4 -> V_39 . V_40 & V_41 ) &&
! ( V_4 -> V_39 . V_40 & V_70 ) )
F_29 ( V_4 ) ;
F_5 ( V_4 , V_68 , V_72 ) ;
}
F_5 ( V_4 , V_50 , V_10 -> V_36 ) ;
}
static void F_27 ( struct V_2 * V_4 )
{
F_5 ( V_4 , V_63 , V_73 ) ;
F_5 ( V_4 , V_63 , V_74 ) ;
if ( F_11 ( V_4 ) ) {
F_5 ( V_4 , V_50 ,
V_75 | V_76 |
V_4 -> V_77 ) ;
F_5 ( V_4 , V_68 , V_78 ) ;
} else {
F_5 ( V_4 , V_50 , V_79 ) ;
}
}
static void F_29 ( struct V_2 * V_4 )
{
F_5 ( V_4 , V_63 , V_80 ) ;
if ( F_11 ( V_4 ) ) {
F_5 ( V_4 , V_68 , V_81 ) ;
F_5 ( V_4 , V_35 ,
V_75 | V_76 |
V_4 -> V_77 ) ;
} else {
F_5 ( V_4 , V_35 , V_79 ) ;
}
}
static void F_30 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
T_4 V_82 = 0 ;
if ( V_10 -> V_83 )
return;
V_10 -> V_83 = true ;
if ( ! F_19 ( V_10 -> V_19 , V_20 ) )
V_82 |= V_84 ;
if ( ! F_19 ( V_10 -> V_19 , V_23 ) )
V_82 |= V_85 ;
if ( ! F_19 ( V_10 -> V_19 , V_26 ) )
V_82 |= V_86 ;
if ( ! F_19 ( V_10 -> V_19 , V_29 ) )
V_82 |= V_87 ;
F_5 ( V_4 , V_50 , V_82 ) ;
F_31 ( V_10 -> V_19 ) ;
}
static void F_32 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
T_4 V_88 = 0 ;
if ( ! V_10 -> V_83 )
return;
V_10 -> V_83 = false ;
F_33 ( V_10 -> V_19 ) ;
if ( ! F_19 ( V_10 -> V_19 , V_20 ) )
V_88 |= V_84 ;
if ( ! F_19 ( V_10 -> V_19 , V_23 ) )
V_88 |= V_85 ;
if ( ! F_19 ( V_10 -> V_19 , V_26 ) )
V_88 |= V_86 ;
if ( ! F_19 ( V_10 -> V_19 , V_29 ) )
V_88 |= V_87 ;
F_5 ( V_4 , V_35 , V_88 ) ;
}
static void F_34 ( struct V_2 * V_4 , int V_89 )
{
if ( V_89 != 0 )
F_5 ( V_4 , V_63 , V_90 ) ;
else
F_5 ( V_4 , V_63 , V_91 ) ;
}
static void
F_35 ( struct V_2 * V_4 , unsigned int V_16 ,
unsigned int V_92 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_93 * V_94 = & V_10 -> V_95 ;
struct V_96 * V_97 ;
if ( ! F_36 ( V_94 -> V_98 , V_94 -> V_99 , V_100 ) )
return;
V_97 = & ( (struct V_96 * ) V_94 -> V_101 ) [ V_94 -> V_98 ] ;
V_97 -> V_16 = V_16 ;
V_97 -> V_92 = V_92 ;
F_37 () ;
V_94 -> V_98 = ( V_94 -> V_98 + 1 ) & ( V_100 - 1 ) ;
}
static void F_38 ( struct V_2 * V_4 , unsigned int V_16 )
{
F_5 ( V_4 , V_63 , V_73 ) ;
if ( V_16 & V_102 ) {
V_16 &= ~ ( V_103 | V_104 ) ;
V_4 -> V_105 . V_106 ++ ;
}
if ( V_16 & V_103 )
V_4 -> V_105 . V_107 ++ ;
if ( V_16 & V_104 )
V_4 -> V_105 . V_108 ++ ;
if ( V_16 & V_109 )
V_4 -> V_105 . V_110 ++ ;
}
static void F_39 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_16 , V_92 ;
V_16 = F_3 ( V_4 , V_18 ) ;
while ( V_16 & V_79 ) {
V_92 = F_7 ( V_4 ) ;
if ( F_40 ( V_16 & ( V_103 | V_104
| V_109 | V_102 )
|| V_10 -> V_111 ) ) {
F_5 ( V_4 , V_63 , V_73 ) ;
if ( V_16 & V_102
&& ! V_10 -> V_111 ) {
V_10 -> V_111 = 1 ;
F_5 ( V_4 , V_50 ,
V_102 ) ;
} else {
F_5 ( V_4 , V_35 ,
V_102 ) ;
V_16 &= ~ V_102 ;
V_10 -> V_111 = 0 ;
}
}
F_35 ( V_4 , V_16 , V_92 ) ;
V_16 = F_3 ( V_4 , V_18 ) ;
}
F_41 ( & V_10 -> V_112 ) ;
}
static void F_42 ( struct V_2 * V_4 )
{
struct V_93 * V_113 = & V_4 -> V_114 -> V_113 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( V_4 -> V_115 &&
( F_3 ( V_4 , V_18 ) & V_10 -> V_36 ) ) {
F_8 ( V_4 , V_4 -> V_115 ) ;
V_4 -> V_105 . V_116 ++ ;
V_4 -> V_115 = 0 ;
}
if ( F_43 ( V_113 ) || F_44 ( V_4 ) )
return;
while ( F_3 ( V_4 , V_18 ) &
V_10 -> V_36 ) {
F_8 ( V_4 , V_113 -> V_101 [ V_113 -> V_99 ] ) ;
V_113 -> V_99 = ( V_113 -> V_99 + 1 ) & ( V_117 - 1 ) ;
V_4 -> V_105 . V_116 ++ ;
if ( F_43 ( V_113 ) )
break;
}
if ( F_45 ( V_113 ) < V_118 )
F_46 ( V_4 ) ;
if ( ! F_43 ( V_113 ) )
F_5 ( V_4 , V_50 ,
V_10 -> V_36 ) ;
}
static void F_47 ( void * V_119 )
{
struct V_1 * V_10 = V_119 ;
struct V_2 * V_4 = & V_10 -> V_3 ;
struct V_93 * V_113 = & V_4 -> V_114 -> V_113 ;
struct V_120 * V_121 = V_10 -> V_122 ;
unsigned long V_40 ;
F_48 ( & V_4 -> V_123 , V_40 ) ;
if ( V_121 )
F_49 ( V_121 ) ;
V_113 -> V_99 += V_10 -> V_124 ;
V_113 -> V_99 &= V_117 - 1 ;
V_4 -> V_105 . V_116 += V_10 -> V_124 ;
F_50 ( & V_10 -> V_125 ) ;
F_51 ( V_10 -> V_126 ) ;
V_10 -> V_127 = - V_128 ;
V_10 -> V_126 = NULL ;
F_52 ( & V_10 -> V_125 ) ;
if ( F_45 ( V_113 ) < V_118 )
F_46 ( V_4 ) ;
if ( ! F_43 ( V_113 ) )
F_41 ( & V_10 -> V_112 ) ;
F_53 ( & V_4 -> V_123 , V_40 ) ;
}
static void F_54 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_120 * V_121 = V_10 -> V_122 ;
if ( V_121 ) {
F_49 ( V_121 ) ;
F_55 ( V_121 ) ;
F_56 ( V_4 -> V_42 , & V_10 -> V_129 , 1 ,
V_130 ) ;
}
V_10 -> V_126 = NULL ;
V_10 -> V_122 = NULL ;
V_10 -> V_127 = - V_128 ;
}
static void F_57 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_93 * V_113 = & V_4 -> V_114 -> V_113 ;
struct V_120 * V_121 = V_10 -> V_122 ;
struct V_131 * V_132 ;
struct V_133 V_134 [ 2 ] , * V_135 , * V_129 = & V_10 -> V_129 ;
unsigned int V_124 , V_136 , V_137 , V_138 ;
T_5 V_139 ;
if ( V_10 -> V_126 != NULL )
return;
if ( ! F_43 ( V_113 ) && ! F_44 ( V_4 ) ) {
V_124 = F_58 ( V_113 -> V_98 ,
V_113 -> V_99 ,
V_117 ) ;
if ( V_10 -> V_15 ) {
V_136 = ( V_124 & ~ 0x3 ) ;
V_137 = ( V_124 & 0x3 ) ;
} else {
V_136 = 0 ;
V_137 = V_124 ;
}
F_59 ( V_134 , 2 ) ;
V_138 = 0 ;
V_139 = F_60 ( V_129 ) + V_113 -> V_99 ;
if ( V_136 ) {
V_135 = & V_134 [ V_138 ++ ] ;
F_60 ( V_135 ) = V_139 ;
F_61 ( V_135 ) = V_136 ;
V_139 += V_136 ;
}
if ( V_137 ) {
V_135 = & V_134 [ V_138 ++ ] ;
F_60 ( V_135 ) = V_139 ;
F_61 ( V_135 ) = V_137 ;
}
V_10 -> V_124 = V_124 ;
V_132 = F_62 ( V_121 ,
V_134 ,
V_138 ,
V_140 ,
V_141 |
V_142 ) ;
if ( ! V_132 ) {
F_63 ( V_4 -> V_42 , L_3 ) ;
return;
}
F_64 ( V_4 -> V_42 , V_129 , 1 , V_130 ) ;
V_10 -> V_126 = V_132 ;
V_132 -> V_143 = F_47 ;
V_132 -> V_144 = V_10 ;
V_10 -> V_127 = F_65 ( V_132 ) ;
} else {
if ( V_4 -> V_39 . V_40 & V_41 ) {
F_27 ( V_4 ) ;
}
}
if ( F_45 ( V_113 ) < V_118 )
F_46 ( V_4 ) ;
}
static int F_66 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
T_6 V_145 ;
struct V_146 V_147 ;
int V_17 , V_148 ;
F_67 ( V_145 ) ;
F_68 ( V_149 , V_145 ) ;
V_10 -> V_122 = F_69 ( V_4 -> V_42 , L_4 ) ;
if ( V_10 -> V_122 == NULL )
goto V_150;
F_70 ( V_4 -> V_42 , L_5 ,
F_71 ( V_10 -> V_122 ) ) ;
F_72 ( & V_10 -> V_125 ) ;
F_59 ( & V_10 -> V_129 , 1 ) ;
F_73 ( ! F_74 ( V_4 -> V_114 -> V_113 . V_101 ) ) ;
F_75 ( & V_10 -> V_129 ,
F_76 ( V_4 -> V_114 -> V_113 . V_101 ) ,
V_117 ,
( unsigned long ) V_4 -> V_114 -> V_113 . V_101 & ~ V_151 ) ;
V_148 = F_77 ( V_4 -> V_42 ,
& V_10 -> V_129 ,
1 ,
V_130 ) ;
if ( ! V_148 ) {
F_21 ( V_4 -> V_42 , L_6 ) ;
goto V_150;
} else {
F_21 ( V_4 -> V_42 , L_7 , V_152 ,
F_61 ( & V_10 -> V_129 ) ,
V_4 -> V_114 -> V_113 . V_101 ,
& F_60 ( & V_10 -> V_129 ) ) ;
}
memset ( & V_147 , 0 , sizeof( V_147 ) ) ;
V_147 . V_153 = V_140 ;
V_147 . V_154 = ( V_10 -> V_15 ) ?
V_155 :
V_156 ;
V_147 . V_157 = V_4 -> V_158 + V_9 ;
V_147 . V_159 = 1 ;
V_17 = F_78 ( V_10 -> V_122 ,
& V_147 ) ;
if ( V_17 ) {
F_63 ( V_4 -> V_42 , L_8 ) ;
goto V_150;
}
return 0 ;
V_150:
F_63 ( V_4 -> V_42 , L_9 ) ;
V_10 -> V_13 = 0 ;
if ( V_10 -> V_122 )
F_54 ( V_4 ) ;
return - V_128 ;
}
static void F_79 ( void * V_119 )
{
struct V_2 * V_4 = V_119 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_41 ( & V_10 -> V_112 ) ;
}
static void F_80 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_120 * V_121 = V_10 -> V_160 ;
if ( V_121 ) {
F_49 ( V_121 ) ;
F_55 ( V_121 ) ;
F_56 ( V_4 -> V_42 , & V_10 -> V_161 , 1 ,
V_162 ) ;
}
V_10 -> V_163 = NULL ;
V_10 -> V_160 = NULL ;
V_10 -> V_164 = - V_128 ;
}
static void F_81 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_165 * V_166 = & V_4 -> V_114 -> V_4 ;
struct V_93 * V_94 = & V_10 -> V_95 ;
struct V_120 * V_121 = V_10 -> V_160 ;
struct V_167 V_114 ;
enum V_168 V_169 ;
T_7 V_170 ;
F_5 ( V_4 , V_63 , V_171 ) ;
V_169 = F_82 ( V_121 ,
V_10 -> V_164 ,
& V_114 ) ;
if ( V_169 == V_172 ) {
F_21 ( V_4 -> V_42 , L_10 ) ;
F_5 ( V_4 , V_50 , V_76 ) ;
F_41 ( & V_10 -> V_112 ) ;
return;
}
F_83 ( V_4 -> V_42 ,
& V_10 -> V_161 ,
1 ,
V_162 ) ;
V_94 -> V_98 = F_61 ( & V_10 -> V_161 ) - V_114 . V_173 ;
F_73 ( V_94 -> V_98 > F_61 ( & V_10 -> V_161 ) ) ;
if ( V_94 -> V_98 < V_94 -> V_99 ) {
V_170 = F_61 ( & V_10 -> V_161 ) - V_94 -> V_99 ;
F_84 ( V_166 , V_94 -> V_101 + V_94 -> V_99 , V_170 ) ;
V_94 -> V_99 = 0 ;
V_4 -> V_105 . V_174 += V_170 ;
}
if ( V_94 -> V_99 < V_94 -> V_98 ) {
V_170 = V_94 -> V_98 - V_94 -> V_99 ;
F_84 ( V_166 , V_94 -> V_101 + V_94 -> V_99 , V_170 ) ;
if ( V_94 -> V_98 >= F_61 ( & V_10 -> V_161 ) )
V_94 -> V_98 = 0 ;
V_94 -> V_99 = V_94 -> V_98 ;
V_4 -> V_105 . V_174 += V_170 ;
}
F_64 ( V_4 -> V_42 ,
& V_10 -> V_161 ,
1 ,
V_162 ) ;
F_85 ( & V_4 -> V_123 ) ;
F_86 ( V_166 ) ;
F_87 ( & V_4 -> V_123 ) ;
F_5 ( V_4 , V_50 , V_76 ) ;
}
static int F_88 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_131 * V_132 ;
T_6 V_145 ;
struct V_146 V_147 ;
struct V_93 * V_94 ;
int V_17 , V_148 ;
V_94 = & V_10 -> V_95 ;
F_67 ( V_145 ) ;
F_68 ( V_175 , V_145 ) ;
V_10 -> V_160 = F_69 ( V_4 -> V_42 , L_11 ) ;
if ( V_10 -> V_160 == NULL )
goto V_150;
F_70 ( V_4 -> V_42 , L_12 ,
F_71 ( V_10 -> V_160 ) ) ;
F_72 ( & V_10 -> V_176 ) ;
F_59 ( & V_10 -> V_161 , 1 ) ;
F_73 ( ! F_74 ( V_94 -> V_101 ) ) ;
F_75 ( & V_10 -> V_161 ,
F_76 ( V_94 -> V_101 ) ,
sizeof( struct V_96 ) * V_100 ,
( unsigned long ) V_94 -> V_101 & ~ V_151 ) ;
V_148 = F_77 ( V_4 -> V_42 ,
& V_10 -> V_161 ,
1 ,
V_162 ) ;
if ( ! V_148 ) {
F_21 ( V_4 -> V_42 , L_6 ) ;
goto V_150;
} else {
F_21 ( V_4 -> V_42 , L_7 , V_152 ,
F_61 ( & V_10 -> V_161 ) ,
V_94 -> V_101 ,
& F_60 ( & V_10 -> V_161 ) ) ;
}
memset ( & V_147 , 0 , sizeof( V_147 ) ) ;
V_147 . V_153 = V_177 ;
V_147 . V_178 = V_156 ;
V_147 . V_179 = V_4 -> V_158 + V_8 ;
V_147 . V_180 = 1 ;
V_17 = F_78 ( V_10 -> V_160 ,
& V_147 ) ;
if ( V_17 ) {
F_63 ( V_4 -> V_42 , L_13 ) ;
goto V_150;
}
V_132 = F_89 ( V_10 -> V_160 ,
F_60 ( & V_10 -> V_161 ) ,
F_61 ( & V_10 -> V_161 ) ,
F_61 ( & V_10 -> V_161 ) / 2 ,
V_177 ,
V_141 ) ;
V_132 -> V_143 = F_79 ;
V_132 -> V_144 = V_4 ;
V_10 -> V_163 = V_132 ;
V_10 -> V_164 = F_65 ( V_132 ) ;
return 0 ;
V_150:
F_63 ( V_4 -> V_42 , L_14 ) ;
V_10 -> V_14 = 0 ;
if ( V_10 -> V_160 )
F_80 ( V_4 ) ;
return - V_128 ;
}
static void F_90 ( unsigned long V_181 )
{
struct V_2 * V_4 = ( void * ) V_181 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_41 ( & V_10 -> V_112 ) ;
F_91 ( & V_10 -> V_182 , V_183 + F_92 ( V_4 ) ) ;
}
static void
F_93 ( struct V_2 * V_4 , unsigned int V_184 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_11 ( V_4 ) ) {
if ( V_184 & ( V_75 | V_76 ) ) {
F_5 ( V_4 , V_35 ,
( V_75 | V_76 ) ) ;
F_41 ( & V_10 -> V_112 ) ;
}
if ( V_184 & ( V_102 | V_109 |
V_104 | V_103 ) )
F_38 ( V_4 , V_184 ) ;
}
if ( F_14 ( V_4 ) ) {
if ( V_184 & V_76 ) {
F_5 ( V_4 , V_35 ,
V_76 ) ;
F_41 ( & V_10 -> V_112 ) ;
}
}
if ( V_184 & V_79 )
F_39 ( V_4 ) ;
else if ( V_184 & V_102 ) {
F_5 ( V_4 , V_63 , V_73 ) ;
F_5 ( V_4 , V_35 , V_102 ) ;
V_10 -> V_111 = 0 ;
}
}
static void
F_94 ( struct V_2 * V_4 , unsigned int V_184 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( V_184 & V_10 -> V_36 ) {
F_5 ( V_4 , V_35 ,
V_10 -> V_36 ) ;
F_41 ( & V_10 -> V_112 ) ;
}
}
static void
F_95 ( struct V_2 * V_4 , unsigned int V_184 ,
unsigned int V_16 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( V_184 & ( V_86 | V_85 | V_87
| V_84 ) ) {
V_10 -> V_185 = V_16 ;
V_10 -> V_186 = V_10 -> V_185 ^
V_10 -> V_187 ;
V_10 -> V_187 = V_16 ;
F_41 ( & V_10 -> V_112 ) ;
}
}
static T_8 F_96 ( int V_188 , void * V_189 )
{
struct V_2 * V_4 = V_189 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_16 , V_184 , V_145 , V_190 = 0 ;
F_87 ( & V_10 -> V_191 ) ;
do {
V_16 = F_16 ( V_4 ) ;
V_145 = F_3 ( V_4 , V_192 ) ;
V_184 = V_16 & V_145 ;
if ( ! V_184 )
break;
if ( V_10 -> V_193 ) {
V_10 -> V_184 |= V_184 ;
V_10 -> V_194 = V_16 ;
F_5 ( V_4 , V_35 , V_145 ) ;
F_97 () ;
break;
}
F_93 ( V_4 , V_184 ) ;
F_95 ( V_4 , V_184 , V_16 ) ;
F_94 ( V_4 , V_184 ) ;
} while ( V_190 ++ < V_195 );
F_85 ( & V_10 -> V_191 ) ;
return V_190 ? V_196 : V_197 ;
}
static void F_98 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_198 * V_199 = & V_10 -> V_200 ;
F_99 ( V_4 -> V_42 ,
V_199 -> V_201 ,
V_199 -> V_202 ,
V_130 ) ;
}
static void F_100 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_93 * V_113 = & V_4 -> V_114 -> V_113 ;
struct V_198 * V_199 = & V_10 -> V_200 ;
int V_170 ;
if ( F_3 ( V_4 , V_203 ) )
return;
V_113 -> V_99 += V_199 -> V_204 ;
V_113 -> V_99 &= V_117 - 1 ;
V_4 -> V_105 . V_116 += V_199 -> V_204 ;
V_199 -> V_204 = 0 ;
F_5 ( V_4 , V_68 , V_69 ) ;
if ( ! F_43 ( V_113 ) && ! F_44 ( V_4 ) ) {
F_101 ( V_4 -> V_42 ,
V_199 -> V_201 ,
V_199 -> V_202 ,
V_130 ) ;
V_170 = F_58 ( V_113 -> V_98 , V_113 -> V_99 , V_117 ) ;
V_199 -> V_204 = V_170 ;
F_5 ( V_4 , V_205 ,
V_199 -> V_201 + V_113 -> V_99 ) ;
F_5 ( V_4 , V_203 , V_170 ) ;
F_5 ( V_4 , V_68 , V_72 ) ;
F_5 ( V_4 , V_50 ,
V_10 -> V_36 ) ;
} else {
if ( ( V_4 -> V_39 . V_40 & V_41 ) &&
! ( V_4 -> V_39 . V_40 & V_70 ) ) {
F_27 ( V_4 ) ;
}
}
if ( F_45 ( V_113 ) < V_118 )
F_46 ( V_4 ) ;
}
static int F_102 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_198 * V_199 = & V_10 -> V_200 ;
struct V_93 * V_113 = & V_4 -> V_114 -> V_113 ;
V_199 -> V_101 = V_113 -> V_101 ;
V_199 -> V_201 = F_103 ( V_4 -> V_42 ,
V_199 -> V_101 ,
V_117 ,
V_130 ) ;
V_199 -> V_202 = V_117 ;
V_199 -> V_204 = 0 ;
return 0 ;
}
static void F_104 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_93 * V_94 = & V_10 -> V_95 ;
unsigned int V_206 ;
unsigned int V_16 ;
while ( V_94 -> V_98 != V_94 -> V_99 ) {
struct V_96 V_97 ;
F_105 () ;
V_97 = ( (struct V_96 * ) V_94 -> V_101 ) [ V_94 -> V_99 ] ;
V_94 -> V_99 = ( V_94 -> V_99 + 1 ) & ( V_100 - 1 ) ;
V_4 -> V_105 . V_174 ++ ;
V_16 = V_97 . V_16 ;
V_206 = V_207 ;
if ( F_40 ( V_16 & ( V_103 | V_104
| V_109 | V_102 ) ) ) {
if ( V_16 & V_102 ) {
V_16 &= ~ ( V_103 | V_104 ) ;
V_4 -> V_105 . V_106 ++ ;
if ( F_106 ( V_4 ) )
continue;
}
if ( V_16 & V_103 )
V_4 -> V_105 . V_107 ++ ;
if ( V_16 & V_104 )
V_4 -> V_105 . V_108 ++ ;
if ( V_16 & V_109 )
V_4 -> V_105 . V_110 ++ ;
V_16 &= V_4 -> V_77 ;
if ( V_16 & V_102 )
V_206 = V_208 ;
else if ( V_16 & V_103 )
V_206 = V_209 ;
else if ( V_16 & V_104 )
V_206 = V_210 ;
}
if ( F_107 ( V_4 , V_97 . V_92 ) )
continue;
F_108 ( V_4 , V_16 , V_109 , V_97 . V_92 , V_206 ) ;
}
F_85 ( & V_4 -> V_123 ) ;
F_86 ( & V_4 -> V_114 -> V_4 ) ;
F_87 ( & V_4 -> V_123 ) ;
}
static void F_109 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_211 ;
for ( V_211 = 0 ; V_211 < 2 ; V_211 ++ ) {
struct V_198 * V_199 = & V_10 -> V_212 [ V_211 ] ;
F_99 ( V_4 -> V_42 ,
V_199 -> V_201 ,
V_199 -> V_202 ,
V_162 ) ;
F_110 ( V_199 -> V_101 ) ;
}
}
static void F_111 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_165 * V_166 = & V_4 -> V_114 -> V_4 ;
struct V_198 * V_199 ;
int V_213 = V_10 -> V_214 ;
unsigned int V_98 ;
unsigned int V_99 ;
unsigned int V_170 ;
do {
F_5 ( V_4 , V_63 , V_171 ) ;
V_199 = & V_10 -> V_212 [ V_213 ] ;
V_98 = F_3 ( V_4 , V_215 ) - V_199 -> V_201 ;
V_99 = V_199 -> V_204 ;
V_98 = F_112 ( V_98 , V_199 -> V_202 ) ;
if ( F_113 ( V_98 != V_99 ) ) {
F_114 ( V_4 -> V_42 , V_199 -> V_201 ,
V_199 -> V_202 , V_162 ) ;
V_170 = V_98 - V_99 ;
F_84 ( V_166 , V_199 -> V_101 + V_199 -> V_204 ,
V_170 ) ;
F_101 ( V_4 -> V_42 , V_199 -> V_201 ,
V_199 -> V_202 , V_162 ) ;
V_4 -> V_105 . V_174 += V_170 ;
V_199 -> V_204 = V_98 ;
}
if ( V_98 >= V_199 -> V_202 ) {
V_199 -> V_204 = 0 ;
F_5 ( V_4 , V_216 , V_199 -> V_201 ) ;
F_5 ( V_4 , V_217 , V_199 -> V_202 ) ;
V_213 = ! V_213 ;
V_10 -> V_214 = V_213 ;
}
} while ( V_98 >= V_199 -> V_202 );
F_85 ( & V_4 -> V_123 ) ;
F_86 ( V_166 ) ;
F_87 ( & V_4 -> V_123 ) ;
F_5 ( V_4 , V_50 ,
V_75 | V_76 ) ;
}
static int F_115 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_211 ;
for ( V_211 = 0 ; V_211 < 2 ; V_211 ++ ) {
struct V_198 * V_199 = & V_10 -> V_212 [ V_211 ] ;
V_199 -> V_101 = F_116 ( V_218 , V_219 ) ;
if ( V_199 -> V_101 == NULL ) {
if ( V_211 != 0 ) {
F_99 ( V_4 -> V_42 ,
V_10 -> V_212 [ 0 ] . V_201 ,
V_218 ,
V_162 ) ;
F_110 ( V_10 -> V_212 [ 0 ] . V_101 ) ;
}
V_10 -> V_11 = 0 ;
return - V_220 ;
}
V_199 -> V_201 = F_103 ( V_4 -> V_42 ,
V_199 -> V_101 ,
V_218 ,
V_162 ) ;
V_199 -> V_202 = V_218 ;
V_199 -> V_204 = 0 ;
}
V_10 -> V_214 = 0 ;
F_5 ( V_4 , V_215 , V_10 -> V_212 [ 0 ] . V_201 ) ;
F_5 ( V_4 , V_221 , V_218 ) ;
F_5 ( V_4 , V_216 ,
V_10 -> V_212 [ 1 ] . V_201 ) ;
F_5 ( V_4 , V_217 , V_218 ) ;
return 0 ;
}
static void F_117 ( unsigned long V_181 )
{
struct V_2 * V_4 = (struct V_2 * ) V_181 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_16 = V_10 -> V_185 ;
unsigned int V_186 = V_10 -> V_186 ;
F_87 ( & V_4 -> V_123 ) ;
V_10 -> V_222 ( V_4 ) ;
if ( V_186 & ( V_28 | V_25
| V_31 | V_22 ) ) {
if ( V_186 & V_28 )
V_4 -> V_105 . V_223 ++ ;
if ( V_186 & V_25 )
V_4 -> V_105 . V_224 ++ ;
if ( V_186 & V_31 )
F_118 ( V_4 , ! ( V_16 & V_31 ) ) ;
if ( V_186 & V_22 )
F_119 ( V_4 , ! ( V_16 & V_22 ) ) ;
F_120 ( & V_4 -> V_114 -> V_4 . V_225 ) ;
V_10 -> V_186 = 0 ;
}
V_10 -> V_226 ( V_4 ) ;
F_85 ( & V_4 -> V_123 ) ;
}
static void F_121 ( struct V_1 * V_10 ,
struct V_227 * V_228 )
{
struct V_229 * V_230 = V_228 -> V_42 . V_231 ;
struct V_232 * V_233 = F_122 ( & V_228 -> V_42 ) ;
if ( V_230 ) {
if ( F_123 ( V_230 , L_15 , NULL ) ) {
if ( F_123 ( V_230 , L_16 , NULL ) ) {
V_10 -> V_14 = true ;
V_10 -> V_11 = false ;
} else {
V_10 -> V_14 = false ;
V_10 -> V_11 = true ;
}
} else {
V_10 -> V_14 = false ;
V_10 -> V_11 = false ;
}
if ( F_123 ( V_230 , L_17 , NULL ) ) {
if ( F_123 ( V_230 , L_16 , NULL ) ) {
V_10 -> V_13 = true ;
V_10 -> V_12 = false ;
} else {
V_10 -> V_13 = false ;
V_10 -> V_12 = true ;
}
} else {
V_10 -> V_13 = false ;
V_10 -> V_12 = false ;
}
} else {
V_10 -> V_11 = V_233 -> V_14 ;
V_10 -> V_12 = V_233 -> V_13 ;
V_10 -> V_14 = false ;
V_10 -> V_13 = false ;
}
}
static void F_124 ( struct V_2 * V_4 ,
struct V_227 * V_228 )
{
struct V_229 * V_230 = V_228 -> V_42 . V_231 ;
struct V_232 * V_233 = F_122 ( & V_228 -> V_42 ) ;
if ( V_230 ) {
struct V_32 * V_33 = & V_4 -> V_39 ;
T_1 V_234 [ 2 ] ;
if ( F_125 ( V_230 , L_18 ,
V_234 , 2 ) == 0 ) {
V_33 -> V_235 = V_234 [ 0 ] ;
V_33 -> V_45 = V_234 [ 1 ] ;
V_33 -> V_40 = 0 ;
}
if ( F_123 ( V_230 , L_19 , NULL ) )
V_33 -> V_40 |= V_70 ;
if ( F_123 ( V_230 , L_20 ,
NULL ) )
V_33 -> V_40 |= V_41 ;
} else {
V_4 -> V_39 = V_233 -> V_39 ;
}
}
static void F_126 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_14 ( V_4 ) ) {
V_10 -> V_236 = & F_88 ;
V_10 -> V_226 = & F_81 ;
V_10 -> V_237 = & F_80 ;
} else if ( F_11 ( V_4 ) ) {
V_10 -> V_236 = & F_115 ;
V_10 -> V_226 = & F_111 ;
V_10 -> V_237 = & F_109 ;
} else {
V_10 -> V_236 = NULL ;
V_10 -> V_226 = & F_104 ;
V_10 -> V_237 = NULL ;
}
if ( F_13 ( V_4 ) ) {
V_10 -> V_238 = & F_66 ;
V_10 -> V_222 = & F_57 ;
V_10 -> V_239 = & F_54 ;
} else if ( F_12 ( V_4 ) ) {
V_10 -> V_238 = & F_102 ;
V_10 -> V_222 = & F_100 ;
V_10 -> V_239 = & F_98 ;
} else {
V_10 -> V_238 = NULL ;
V_10 -> V_222 = & F_42 ;
V_10 -> V_239 = NULL ;
}
}
static void F_127 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_240 = F_3 ( V_4 , V_241 ) ;
T_1 V_242 ;
T_1 V_243 , V_244 , V_245 ;
V_243 = 0x55534152 ;
V_244 = 0x44424755 ;
V_245 = 0x55415254 ;
V_10 -> V_246 = false ;
if ( V_240 == V_245 ) {
F_21 ( V_4 -> V_42 , L_21 ) ;
V_10 -> V_246 = true ;
V_10 -> V_247 = V_248 ;
} else if ( V_240 == V_243 ) {
F_21 ( V_4 -> V_42 , L_22 ) ;
V_10 -> V_246 = true ;
V_10 -> V_247 = V_249 ;
} else if ( V_240 == V_244 ) {
F_21 ( V_4 -> V_42 , L_23 ) ;
} else {
V_242 = F_3 ( V_4 , V_250 ) ;
switch ( V_242 ) {
case 0x302 :
case 0x10213 :
F_21 ( V_4 -> V_42 , L_24 ) ;
V_10 -> V_246 = true ;
V_10 -> V_247 = V_249 ;
break;
case 0x203 :
case 0x10202 :
F_21 ( V_4 -> V_42 , L_25 ) ;
break;
default:
F_63 ( V_4 -> V_42 , L_26 ) ;
}
}
}
static int F_128 ( struct V_2 * V_4 )
{
struct V_227 * V_228 = F_129 ( V_4 -> V_42 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_251 * V_252 = V_4 -> V_114 -> V_4 . V_252 ;
int V_253 ;
F_5 ( V_4 , V_35 , - 1 ) ;
V_10 -> V_83 = false ;
V_253 = F_130 ( V_4 -> V_188 , F_96 ,
V_254 | V_255 ,
V_252 ? V_252 -> V_240 : L_27 , V_4 ) ;
if ( V_253 ) {
F_63 ( V_4 -> V_42 , L_28 ) ;
return V_253 ;
}
F_131 ( & V_10 -> V_112 ) ;
F_121 ( V_10 , V_228 ) ;
F_126 ( V_4 ) ;
if ( V_10 -> V_236 ) {
V_253 = V_10 -> V_236 ( V_4 ) ;
if ( V_253 < 0 )
F_126 ( V_4 ) ;
}
if ( V_10 -> V_238 ) {
V_253 = V_10 -> V_238 ( V_4 ) ;
if ( V_253 < 0 )
F_126 ( V_4 ) ;
}
if ( V_10 -> V_15 ) {
unsigned int V_256 = V_257 ;
unsigned int V_258 = V_257 ;
unsigned int V_259 ;
F_5 ( V_4 , V_63 ,
V_260 |
V_261 |
V_262 ) ;
if ( F_13 ( V_4 ) )
V_256 = V_263 ;
V_259 = F_132 ( V_256 ) | F_133 ( V_258 ) ;
if ( V_10 -> V_264 &&
V_10 -> V_265 )
V_259 |= V_266 |
F_134 ( V_10 -> V_264 ) |
F_135 ( V_10 -> V_265 ) ;
F_5 ( V_4 , V_267 , V_259 ) ;
}
V_10 -> V_187 = F_16 ( V_4 ) ;
V_10 -> V_185 = V_10 -> V_187 ;
F_5 ( V_4 , V_63 , V_73 | V_268 ) ;
F_5 ( V_4 , V_63 , V_269 | V_74 ) ;
F_136 ( & V_10 -> V_182 ,
F_90 ,
( unsigned long ) V_4 ) ;
if ( F_11 ( V_4 ) ) {
if ( ! V_10 -> V_246 ) {
F_91 ( & V_10 -> V_182 ,
V_183 + F_92 ( V_4 ) ) ;
} else {
F_5 ( V_4 , V_10 -> V_247 ,
V_270 ) ;
F_5 ( V_4 , V_63 , V_171 ) ;
F_5 ( V_4 , V_50 ,
V_75 | V_76 ) ;
}
F_5 ( V_4 , V_68 , V_78 ) ;
} else if ( F_14 ( V_4 ) ) {
if ( ! V_10 -> V_246 ) {
F_91 ( & V_10 -> V_182 ,
V_183 + F_92 ( V_4 ) ) ;
} else {
F_5 ( V_4 , V_10 -> V_247 ,
V_270 ) ;
F_5 ( V_4 , V_63 , V_171 ) ;
F_5 ( V_4 , V_50 ,
V_76 ) ;
}
} else {
F_5 ( V_4 , V_50 , V_79 ) ;
}
return 0 ;
}
static void F_137 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_12 ( V_4 ) ) {
F_5 ( V_4 , V_203 , 0 ) ;
V_10 -> V_200 . V_204 = 0 ;
}
}
static void F_138 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_139 ( & V_10 -> V_182 ) ;
F_140 ( & V_10 -> V_112 ) ;
F_141 ( & V_10 -> V_112 ) ;
F_29 ( V_4 ) ;
F_26 ( V_4 ) ;
F_5 ( V_4 , V_63 , V_73 ) ;
F_5 ( V_4 , V_35 , - 1 ) ;
if ( V_10 -> V_237 )
V_10 -> V_237 ( V_4 ) ;
if ( V_10 -> V_239 )
V_10 -> V_239 ( V_4 ) ;
V_10 -> V_95 . V_98 = 0 ;
V_10 -> V_95 . V_99 = 0 ;
F_142 ( V_4 -> V_188 , V_4 ) ;
V_10 -> V_83 = false ;
F_137 ( V_4 ) ;
}
static void F_143 ( struct V_2 * V_4 , unsigned int V_114 ,
unsigned int V_271 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
switch ( V_114 ) {
case 0 :
F_144 ( V_10 -> V_272 ) ;
F_5 ( V_4 , V_50 , V_10 -> V_273 ) ;
break;
case 3 :
V_10 -> V_273 = F_3 ( V_4 , V_192 ) ;
F_5 ( V_4 , V_35 , - 1 ) ;
F_145 ( V_10 -> V_272 ) ;
break;
default:
F_63 ( V_4 -> V_42 , L_29 , V_114 ) ;
}
}
static void F_146 ( struct V_2 * V_4 , struct V_274 * V_275 ,
struct V_274 * V_276 )
{
unsigned long V_40 ;
unsigned int V_277 , V_34 , V_278 , V_279 , V_280 ;
V_34 = V_277 = F_3 ( V_4 , V_37 ) ;
V_34 &= ~ ( V_281 | V_282 | V_283 |
V_284 | V_38 ) ;
V_280 = F_147 ( V_4 , V_275 , V_276 , 0 , V_4 -> V_285 / 16 ) ;
V_279 = F_148 ( V_4 , V_280 ) ;
if ( V_279 > 65535 ) {
V_279 /= 8 ;
V_34 |= V_286 ;
}
switch ( V_275 -> V_287 & V_288 ) {
case V_289 :
V_34 |= V_290 ;
break;
case V_291 :
V_34 |= V_292 ;
break;
case V_293 :
V_34 |= V_294 ;
break;
default:
V_34 |= V_295 ;
break;
}
if ( V_275 -> V_287 & V_296 )
V_34 |= V_297 ;
if ( V_275 -> V_287 & V_298 ) {
if ( V_275 -> V_287 & V_299 ) {
if ( V_275 -> V_287 & V_300 )
V_34 |= V_301 ;
else
V_34 |= V_302 ;
} else if ( V_275 -> V_287 & V_300 )
V_34 |= V_303 ;
else
V_34 |= V_304 ;
} else
V_34 |= V_305 ;
F_48 ( & V_4 -> V_123 , V_40 ) ;
V_4 -> V_77 = V_109 ;
if ( V_275 -> V_306 & V_307 )
V_4 -> V_77 |= ( V_104 | V_103 ) ;
if ( V_275 -> V_306 & ( V_308 | V_309 | V_310 ) )
V_4 -> V_77 |= V_102 ;
if ( F_11 ( V_4 ) )
F_5 ( V_4 , V_50 , V_4 -> V_77 ) ;
V_4 -> V_311 = 0 ;
if ( V_275 -> V_306 & V_312 )
V_4 -> V_311 |= ( V_104 | V_103 ) ;
if ( V_275 -> V_306 & V_308 ) {
V_4 -> V_311 |= V_102 ;
if ( V_275 -> V_306 & V_312 )
V_4 -> V_311 |= V_109 ;
}
F_149 ( V_4 , V_275 -> V_287 , V_280 ) ;
V_278 = F_3 ( V_4 , V_192 ) ;
F_5 ( V_4 , V_35 , - 1 ) ;
F_5 ( V_4 , V_63 , V_313 | V_80 ) ;
if ( V_4 -> V_39 . V_40 & V_41 ) {
F_5 ( V_4 , V_44 ,
V_4 -> V_39 . V_45 ) ;
V_34 |= V_46 ;
} else if ( V_275 -> V_287 & V_314 ) {
if ( F_14 ( V_4 ) && ! F_15 ( V_4 ) ) {
F_70 ( V_4 -> V_42 , L_30 ) ;
V_275 -> V_287 &= ~ V_314 ;
} else {
V_34 |= V_56 ;
}
} else {
V_34 |= V_315 ;
}
F_5 ( V_4 , V_37 , V_34 ) ;
if ( ( V_277 & V_38 ) != ( V_34 & V_38 ) ) {
unsigned int V_316 ;
if ( ( V_34 & V_38 ) == V_56 ) {
V_316 = V_58 ;
} else {
V_316 = V_57 ;
}
F_5 ( V_4 , V_63 , V_316 ) ;
}
F_5 ( V_4 , V_317 , V_279 ) ;
F_5 ( V_4 , V_63 , V_73 | V_268 ) ;
F_5 ( V_4 , V_63 , V_269 | V_74 ) ;
F_5 ( V_4 , V_50 , V_278 ) ;
if ( F_150 ( V_4 , V_275 -> V_287 ) )
F_30 ( V_4 ) ;
else
F_32 ( V_4 ) ;
F_53 ( & V_4 -> V_123 , V_40 ) ;
}
static void F_151 ( struct V_2 * V_4 , struct V_274 * V_275 )
{
if ( V_275 -> V_318 == V_319 ) {
V_4 -> V_40 |= V_320 ;
F_50 ( & V_4 -> V_123 ) ;
F_30 ( V_4 ) ;
F_52 ( & V_4 -> V_123 ) ;
} else {
V_4 -> V_40 &= ~ V_320 ;
if ( ! F_150 ( V_4 , V_275 -> V_287 ) ) {
F_50 ( & V_4 -> V_123 ) ;
F_32 ( V_4 ) ;
F_52 ( & V_4 -> V_123 ) ;
}
}
}
static const char * F_152 ( struct V_2 * V_4 )
{
return ( V_4 -> type == V_321 ) ? L_31 : NULL ;
}
static void F_153 ( struct V_2 * V_4 )
{
struct V_227 * V_228 = F_129 ( V_4 -> V_42 ) ;
int V_322 = V_228 -> V_323 [ 0 ] . V_324 - V_228 -> V_323 [ 0 ] . V_325 + 1 ;
F_154 ( V_4 -> V_158 , V_322 ) ;
if ( V_4 -> V_40 & V_326 ) {
F_155 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
}
static int F_156 ( struct V_2 * V_4 )
{
struct V_227 * V_228 = F_129 ( V_4 -> V_42 ) ;
int V_322 = V_228 -> V_323 [ 0 ] . V_324 - V_228 -> V_323 [ 0 ] . V_325 + 1 ;
if ( ! F_157 ( V_4 -> V_158 , V_322 , L_27 ) )
return - V_327 ;
if ( V_4 -> V_40 & V_326 ) {
V_4 -> V_6 = F_158 ( V_4 -> V_158 , V_322 ) ;
if ( V_4 -> V_6 == NULL ) {
F_154 ( V_4 -> V_158 , V_322 ) ;
return - V_220 ;
}
}
return 0 ;
}
static void F_159 ( struct V_2 * V_4 , int V_40 )
{
if ( V_40 & V_328 ) {
V_4 -> type = V_321 ;
F_156 ( V_4 ) ;
}
}
static int F_160 ( struct V_2 * V_4 , struct V_329 * V_330 )
{
int V_17 = 0 ;
if ( V_330 -> type != V_331 && V_330 -> type != V_321 )
V_17 = - V_128 ;
if ( V_4 -> V_188 != V_330 -> V_188 )
V_17 = - V_128 ;
if ( V_330 -> V_332 != V_333 )
V_17 = - V_128 ;
if ( V_4 -> V_285 / 16 != V_330 -> V_334 )
V_17 = - V_128 ;
if ( V_4 -> V_158 != ( unsigned long ) V_330 -> V_335 )
V_17 = - V_128 ;
if ( V_4 -> V_336 != V_330 -> V_4 )
V_17 = - V_128 ;
if ( V_330 -> V_337 != 0 )
V_17 = - V_128 ;
return V_17 ;
}
static int F_161 ( struct V_2 * V_4 )
{
while ( ! ( F_3 ( V_4 , V_18 ) & V_79 ) )
F_162 () ;
return F_7 ( V_4 ) ;
}
static void F_163 ( struct V_2 * V_4 , unsigned char V_92 )
{
while ( ! ( F_3 ( V_4 , V_18 ) & V_49 ) )
F_162 () ;
F_8 ( V_4 , V_92 ) ;
}
static int F_164 ( struct V_1 * V_10 ,
struct V_227 * V_228 )
{
int V_17 ;
struct V_2 * V_4 = & V_10 -> V_3 ;
struct V_232 * V_233 = F_122 ( & V_228 -> V_42 ) ;
F_121 ( V_10 , V_228 ) ;
F_126 ( V_4 ) ;
F_124 ( V_4 , V_228 ) ;
V_4 -> V_338 = V_339 ;
V_4 -> V_40 = V_340 ;
V_4 -> V_341 = & V_342 ;
V_4 -> V_343 = 1 ;
V_4 -> V_42 = & V_228 -> V_42 ;
V_4 -> V_158 = V_228 -> V_323 [ 0 ] . V_325 ;
V_4 -> V_188 = V_228 -> V_323 [ 1 ] . V_325 ;
V_4 -> V_344 = F_20 ;
F_165 ( & V_10 -> V_112 , F_117 ,
( unsigned long ) V_4 ) ;
F_140 ( & V_10 -> V_112 ) ;
memset ( & V_10 -> V_95 , 0 , sizeof( V_10 -> V_95 ) ) ;
if ( V_233 && V_233 -> V_345 ) {
V_4 -> V_6 = V_233 -> V_345 ;
} else {
V_4 -> V_40 |= V_326 ;
V_4 -> V_6 = NULL ;
}
if ( ! V_10 -> V_272 ) {
V_10 -> V_272 = F_166 ( & V_228 -> V_42 , L_32 ) ;
if ( F_167 ( V_10 -> V_272 ) ) {
V_17 = F_168 ( V_10 -> V_272 ) ;
V_10 -> V_272 = NULL ;
return V_17 ;
}
V_17 = F_144 ( V_10 -> V_272 ) ;
if ( V_17 ) {
F_169 ( V_10 -> V_272 ) ;
V_10 -> V_272 = NULL ;
return V_17 ;
}
V_4 -> V_285 = F_170 ( V_10 -> V_272 ) ;
F_145 ( V_10 -> V_272 ) ;
}
if ( V_4 -> V_39 . V_40 & V_41 )
V_10 -> V_36 = V_43 ;
else if ( F_12 ( V_4 ) ) {
V_4 -> V_343 = V_218 ;
V_10 -> V_36 = V_47 | V_48 ;
} else {
V_10 -> V_36 = V_49 ;
}
return 0 ;
}
static void F_171 ( struct V_2 * V_4 , int V_92 )
{
while ( ! ( F_3 ( V_4 , V_18 ) & V_49 ) )
F_162 () ;
F_8 ( V_4 , V_92 ) ;
}
static void F_172 ( struct V_346 * V_347 , const char * V_348 , T_3 V_170 )
{
struct V_2 * V_4 = & V_349 [ V_347 -> V_350 ] . V_3 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_16 , V_278 ;
unsigned int V_200 ;
V_278 = F_3 ( V_4 , V_192 ) ;
F_5 ( V_4 , V_35 ,
V_79 | V_10 -> V_36 ) ;
V_200 = F_3 ( V_4 , V_71 ) & V_72 ;
F_5 ( V_4 , V_68 , V_69 ) ;
F_173 ( V_4 , V_348 , V_170 , F_171 ) ;
do {
V_16 = F_3 ( V_4 , V_18 ) ;
} while ( ! ( V_16 & V_49 ) );
if ( V_200 )
F_5 ( V_4 , V_68 , V_72 ) ;
F_5 ( V_4 , V_50 , V_278 ) ;
}
static void T_9 F_174 ( struct V_2 * V_4 , int * V_280 ,
int * V_107 , int * V_351 )
{
unsigned int V_352 , V_279 ;
V_279 = F_3 ( V_4 , V_317 ) & V_353 ;
if ( ! V_279 )
return;
V_352 = F_3 ( V_4 , V_37 ) & V_282 ;
if ( V_352 == V_295 )
* V_351 = 8 ;
else
* V_351 = 7 ;
V_352 = F_3 ( V_4 , V_37 ) & V_284 ;
if ( V_352 == V_304 )
* V_107 = 'e' ;
else if ( V_352 == V_303 )
* V_107 = 'o' ;
* V_280 = V_4 -> V_285 / ( 16 * ( V_279 - 1 ) ) ;
}
static int T_9 F_175 ( struct V_346 * V_347 , char * V_354 )
{
int V_17 ;
struct V_2 * V_4 = & V_349 [ V_347 -> V_350 ] . V_3 ;
int V_280 = 115200 ;
int V_351 = 8 ;
int V_107 = 'n' ;
int V_355 = 'n' ;
if ( V_4 -> V_6 == NULL ) {
return - V_356 ;
}
V_17 = F_144 ( V_349 [ V_347 -> V_350 ] . V_272 ) ;
if ( V_17 )
return V_17 ;
F_5 ( V_4 , V_35 , - 1 ) ;
F_5 ( V_4 , V_63 , V_73 | V_268 ) ;
F_5 ( V_4 , V_63 , V_269 | V_74 ) ;
if ( V_354 )
F_176 ( V_354 , & V_280 , & V_107 , & V_351 , & V_355 ) ;
else
F_174 ( V_4 , & V_280 , & V_107 , & V_351 ) ;
return F_177 ( V_4 , V_347 , V_280 , V_107 , V_351 , V_355 ) ;
}
static int T_9 F_178 ( void )
{
int V_17 ;
if ( V_357 ) {
struct V_232 * V_233 =
F_122 ( & V_357 -> V_42 ) ;
int V_358 = V_233 -> V_359 ;
struct V_1 * V_10 = & V_349 [ V_358 ] ;
V_10 -> V_273 = 0 ;
V_10 -> V_3 . line = V_358 ;
F_179 ( V_360 , V_358 , NULL ) ;
V_17 = F_164 ( V_10 , V_357 ) ;
if ( V_17 )
return V_17 ;
F_180 ( & V_361 ) ;
}
return 0 ;
}
static int T_9 F_181 ( void )
{
if ( V_357
&& ! ( V_361 . V_40 & V_362 ) )
F_180 ( & V_361 ) ;
return 0 ;
}
static inline bool F_182 ( struct V_2 * V_4 )
{
return V_4 -> V_363 && V_4 -> V_363 -> V_350 == V_4 -> line ;
}
static inline bool F_182 ( struct V_2 * V_4 )
{
return false ;
}
static bool F_183 ( void )
{
#ifdef F_184
return F_185 () ;
#else
return false ;
#endif
}
static int F_186 ( struct V_227 * V_228 ,
T_10 V_114 )
{
struct V_2 * V_4 = F_187 ( V_228 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_182 ( V_4 ) && V_364 ) {
while ( ! ( F_3 ( V_4 , V_18 ) &
V_43 ) )
F_162 () ;
}
V_10 -> V_365 = F_188 ( & V_228 -> V_42 ) ;
if ( F_183 () ) {
unsigned long V_40 ;
F_48 ( & V_10 -> V_191 , V_40 ) ;
V_10 -> V_193 = true ;
F_53 ( & V_10 -> V_191 , V_40 ) ;
F_189 ( & V_228 -> V_42 , 0 ) ;
}
F_190 ( & V_366 , V_4 ) ;
return 0 ;
}
static int F_191 ( struct V_227 * V_228 )
{
struct V_2 * V_4 = F_187 ( V_228 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned long V_40 ;
F_48 ( & V_10 -> V_191 , V_40 ) ;
if ( V_10 -> V_184 ) {
F_93 ( V_4 , V_10 -> V_184 ) ;
F_95 ( V_4 , V_10 -> V_184 ,
V_10 -> V_194 ) ;
F_94 ( V_4 , V_10 -> V_184 ) ;
V_10 -> V_184 = 0 ;
}
V_10 -> V_193 = false ;
F_53 ( & V_10 -> V_191 , V_40 ) ;
F_192 ( & V_366 , V_4 ) ;
F_189 ( & V_228 -> V_42 , V_10 -> V_365 ) ;
return 0 ;
}
static void F_193 ( struct V_1 * V_10 ,
struct V_227 * V_228 )
{
V_10 -> V_15 = 0 ;
V_10 -> V_265 = 0 ;
V_10 -> V_264 = 0 ;
if ( F_194 ( V_228 -> V_42 . V_231 ,
L_33 ,
& V_10 -> V_15 ) )
return;
if ( ! V_10 -> V_15 )
return;
if ( V_10 -> V_15 < V_367 ) {
V_10 -> V_15 = 0 ;
F_63 ( & V_228 -> V_42 , L_34 ) ;
return;
}
V_10 -> V_264 = F_195 ( int , V_10 -> V_15 >> 1 ,
V_10 -> V_15 - V_368 ) ;
V_10 -> V_265 = F_195 ( int , V_10 -> V_15 >> 2 ,
V_10 -> V_15 - V_369 ) ;
F_70 ( & V_228 -> V_42 , L_35 ,
V_10 -> V_15 ) ;
F_21 ( & V_228 -> V_42 , L_36 ,
V_10 -> V_264 ) ;
F_21 ( & V_228 -> V_42 , L_37 ,
V_10 -> V_265 ) ;
}
static int F_196 ( struct V_227 * V_228 )
{
struct V_1 * V_10 ;
struct V_229 * V_230 = V_228 -> V_42 . V_231 ;
struct V_232 * V_233 = F_122 ( & V_228 -> V_42 ) ;
void * V_181 ;
int V_17 = - V_356 ;
bool V_370 ;
F_197 ( V_100 & ( V_100 - 1 ) ) ;
if ( V_230 )
V_17 = F_198 ( V_230 , L_38 ) ;
else
if ( V_233 )
V_17 = V_233 -> V_359 ;
if ( V_17 < 0 )
V_17 = F_199 ( V_371 , V_372 ) ;
if ( V_17 >= V_372 ) {
V_17 = - V_356 ;
goto V_373;
}
if ( F_200 ( V_17 , V_371 ) ) {
V_17 = - V_327 ;
goto V_373;
}
V_10 = & V_349 [ V_17 ] ;
V_10 -> V_273 = 0 ;
V_10 -> V_3 . line = V_17 ;
F_193 ( V_10 , V_228 ) ;
F_72 ( & V_10 -> V_191 ) ;
V_17 = F_164 ( V_10 , V_228 ) ;
if ( V_17 )
goto V_374;
V_10 -> V_19 = F_201 ( & V_10 -> V_3 , 0 ) ;
if ( F_167 ( V_10 -> V_19 ) ) {
V_17 = F_168 ( V_10 -> V_19 ) ;
goto V_374;
}
if ( ! F_11 ( & V_10 -> V_3 ) ) {
V_17 = - V_220 ;
V_181 = F_116 ( sizeof( struct V_96 )
* V_100 , V_219 ) ;
if ( ! V_181 )
goto V_375;
V_10 -> V_95 . V_101 = V_181 ;
}
V_370 = V_10 -> V_3 . V_39 . V_40 & V_41 ;
V_17 = F_202 ( & V_366 , & V_10 -> V_3 ) ;
if ( V_17 )
goto V_376;
#ifdef F_203
if ( F_182 ( & V_10 -> V_3 )
&& V_377 -> V_40 & V_362 ) {
F_145 ( V_10 -> V_272 ) ;
}
#endif
F_204 ( & V_228 -> V_42 , 1 ) ;
F_205 ( V_228 , V_10 ) ;
F_144 ( V_10 -> V_272 ) ;
if ( V_370 ) {
F_5 ( & V_10 -> V_3 , V_37 ,
V_315 ) ;
F_5 ( & V_10 -> V_3 , V_63 ,
V_57 ) ;
}
F_127 ( & V_10 -> V_3 ) ;
F_145 ( V_10 -> V_272 ) ;
return 0 ;
V_376:
F_110 ( V_10 -> V_95 . V_101 ) ;
V_10 -> V_95 . V_101 = NULL ;
V_375:
if ( ! F_182 ( & V_10 -> V_3 ) ) {
F_169 ( V_10 -> V_272 ) ;
V_10 -> V_272 = NULL ;
}
V_374:
F_206 ( V_10 -> V_3 . line , V_371 ) ;
V_373:
return V_17 ;
}
static int F_207 ( struct V_227 * V_228 )
{
struct V_2 * V_4 = F_187 ( V_228 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_17 = 0 ;
F_141 ( & V_10 -> V_112 ) ;
F_204 ( & V_228 -> V_42 , 0 ) ;
V_17 = F_208 ( & V_366 , V_4 ) ;
F_110 ( V_10 -> V_95 . V_101 ) ;
F_206 ( V_4 -> line , V_371 ) ;
F_169 ( V_10 -> V_272 ) ;
V_10 -> V_272 = NULL ;
return V_17 ;
}
static int T_9 F_209 ( void )
{
int V_17 ;
V_17 = F_210 ( & V_366 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_211 ( & V_378 ) ;
if ( V_17 )
F_212 ( & V_366 ) ;
return V_17 ;
}
