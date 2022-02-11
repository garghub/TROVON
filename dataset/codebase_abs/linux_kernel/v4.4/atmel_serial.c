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
static unsigned int F_15 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_15 , V_16 = 0 ;
V_15 = F_3 ( V_4 , V_17 ) ;
F_16 ( V_10 -> V_18 , & V_16 ) ;
if ( ! F_17 ( F_18 ( V_10 -> V_18 ,
V_19 ) ) ) {
if ( V_16 & V_20 )
V_15 &= ~ V_21 ;
else
V_15 |= V_21 ;
}
if ( ! F_17 ( F_18 ( V_10 -> V_18 ,
V_22 ) ) ) {
if ( V_16 & V_23 )
V_15 &= ~ V_24 ;
else
V_15 |= V_24 ;
}
if ( ! F_17 ( F_18 ( V_10 -> V_18 ,
V_25 ) ) ) {
if ( V_16 & V_26 )
V_15 &= ~ V_27 ;
else
V_15 |= V_27 ;
}
if ( ! F_17 ( F_18 ( V_10 -> V_18 ,
V_28 ) ) ) {
if ( V_16 & V_29 )
V_15 &= ~ V_30 ;
else
V_15 |= V_30 ;
}
return V_15 ;
}
static int F_19 ( struct V_2 * V_4 ,
struct V_31 * V_32 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_33 ;
F_5 ( V_4 , V_34 , V_10 -> V_35 ) ;
V_33 = F_3 ( V_4 , V_36 ) ;
V_33 &= ~ V_37 ;
V_4 -> V_38 = * V_32 ;
if ( V_32 -> V_39 & V_40 ) {
F_20 ( V_4 -> V_41 , L_1 ) ;
V_10 -> V_35 = V_42 ;
F_5 ( V_4 , V_43 ,
V_32 -> V_44 ) ;
V_33 |= V_45 ;
} else {
F_20 ( V_4 -> V_41 , L_2 ) ;
if ( F_12 ( V_4 ) )
V_10 -> V_35 = V_46 |
V_47 ;
else
V_10 -> V_35 = V_48 ;
}
F_5 ( V_4 , V_36 , V_33 ) ;
F_5 ( V_4 , V_49 , V_10 -> V_35 ) ;
return 0 ;
}
static T_3 F_21 ( struct V_2 * V_4 )
{
return ( F_3 ( V_4 , V_17 ) & V_42 ) ?
V_50 :
0 ;
}
static void F_22 ( struct V_2 * V_4 , T_3 V_51 )
{
unsigned int V_52 = 0 ;
unsigned int V_33 = F_3 ( V_4 , V_36 ) ;
unsigned int V_53 , V_54 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( V_4 -> V_38 . V_39 & V_40 ) {
F_5 ( V_4 , V_43 ,
V_4 -> V_38 . V_44 ) ;
V_33 &= ~ V_37 ;
V_33 |= V_45 ;
}
if ( ( V_33 & V_37 ) == V_55 ) {
V_53 = V_56 ;
V_54 = V_57 ;
} else {
V_53 = V_57 ;
V_54 = V_56 ;
}
if ( V_51 & V_58 )
V_52 |= V_54 ;
else
V_52 |= V_53 ;
if ( V_51 & V_59 )
V_52 |= V_60 ;
else
V_52 |= V_61 ;
F_5 ( V_4 , V_62 , V_52 ) ;
F_23 ( V_10 -> V_18 , V_51 ) ;
V_33 &= ~ V_63 ;
if ( V_51 & V_64 )
V_33 |= V_65 ;
else
V_33 |= V_66 ;
F_5 ( V_4 , V_36 , V_33 ) ;
}
static T_3 F_24 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_16 = 0 , V_15 ;
V_15 = F_3 ( V_4 , V_17 ) ;
if ( ! ( V_15 & V_30 ) )
V_16 |= V_29 ;
if ( ! ( V_15 & V_21 ) )
V_16 |= V_20 ;
if ( ! ( V_15 & V_24 ) )
V_16 |= V_23 ;
if ( ! ( V_15 & V_27 ) )
V_16 |= V_26 ;
return F_16 ( V_10 -> V_18 , & V_16 ) ;
}
static void F_25 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_12 ( V_4 ) ) {
F_5 ( V_4 , V_67 , V_68 ) ;
}
F_5 ( V_4 , V_34 , V_10 -> V_35 ) ;
if ( ( V_4 -> V_38 . V_39 & V_40 ) &&
! ( V_4 -> V_38 . V_39 & V_69 ) )
F_26 ( V_4 ) ;
}
static void F_27 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_12 ( V_4 ) ) {
if ( F_3 ( V_4 , V_70 ) & V_71 )
return;
if ( ( V_4 -> V_38 . V_39 & V_40 ) &&
! ( V_4 -> V_38 . V_39 & V_69 ) )
F_28 ( V_4 ) ;
F_5 ( V_4 , V_67 , V_71 ) ;
}
F_5 ( V_4 , V_49 , V_10 -> V_35 ) ;
}
static void F_26 ( struct V_2 * V_4 )
{
F_5 ( V_4 , V_62 , V_72 ) ;
F_5 ( V_4 , V_62 , V_73 ) ;
if ( F_11 ( V_4 ) ) {
F_5 ( V_4 , V_49 ,
V_74 | V_75 |
V_4 -> V_76 ) ;
F_5 ( V_4 , V_67 , V_77 ) ;
} else {
F_5 ( V_4 , V_49 , V_78 ) ;
}
}
static void F_28 ( struct V_2 * V_4 )
{
F_5 ( V_4 , V_62 , V_79 ) ;
if ( F_11 ( V_4 ) ) {
F_5 ( V_4 , V_67 , V_80 ) ;
F_5 ( V_4 , V_34 ,
V_74 | V_75 |
V_4 -> V_76 ) ;
} else {
F_5 ( V_4 , V_34 , V_78 ) ;
}
}
static void F_29 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
T_4 V_81 = 0 ;
if ( V_10 -> V_82 )
return;
V_10 -> V_82 = true ;
if ( V_10 -> V_83 [ V_19 ] >= 0 )
F_30 ( V_10 -> V_83 [ V_19 ] ) ;
else
V_81 |= V_84 ;
if ( V_10 -> V_83 [ V_22 ] >= 0 )
F_30 ( V_10 -> V_83 [ V_22 ] ) ;
else
V_81 |= V_85 ;
if ( V_10 -> V_83 [ V_25 ] >= 0 )
F_30 ( V_10 -> V_83 [ V_25 ] ) ;
else
V_81 |= V_86 ;
if ( V_10 -> V_83 [ V_28 ] >= 0 )
F_30 ( V_10 -> V_83 [ V_28 ] ) ;
else
V_81 |= V_87 ;
F_5 ( V_4 , V_49 , V_81 ) ;
}
static void F_31 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
T_4 V_88 = 0 ;
if ( ! V_10 -> V_82 )
return;
V_10 -> V_82 = false ;
if ( V_10 -> V_83 [ V_19 ] >= 0 )
F_32 ( V_10 -> V_83 [ V_19 ] ) ;
else
V_88 |= V_84 ;
if ( V_10 -> V_83 [ V_22 ] >= 0 )
F_32 ( V_10 -> V_83 [ V_22 ] ) ;
else
V_88 |= V_85 ;
if ( V_10 -> V_83 [ V_25 ] >= 0 )
F_32 ( V_10 -> V_83 [ V_25 ] ) ;
else
V_88 |= V_86 ;
if ( V_10 -> V_83 [ V_28 ] >= 0 )
F_32 ( V_10 -> V_83 [ V_28 ] ) ;
else
V_88 |= V_87 ;
F_5 ( V_4 , V_34 , V_88 ) ;
}
static void F_33 ( struct V_2 * V_4 , int V_89 )
{
if ( V_89 != 0 )
F_5 ( V_4 , V_62 , V_90 ) ;
else
F_5 ( V_4 , V_62 , V_91 ) ;
}
static void
F_34 ( struct V_2 * V_4 , unsigned int V_15 ,
unsigned int V_92 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_93 * V_94 = & V_10 -> V_95 ;
struct V_96 * V_97 ;
if ( ! F_35 ( V_94 -> V_98 , V_94 -> V_99 , V_100 ) )
return;
V_97 = & ( (struct V_96 * ) V_94 -> V_101 ) [ V_94 -> V_98 ] ;
V_97 -> V_15 = V_15 ;
V_97 -> V_92 = V_92 ;
F_36 () ;
V_94 -> V_98 = ( V_94 -> V_98 + 1 ) & ( V_100 - 1 ) ;
}
static void F_37 ( struct V_2 * V_4 , unsigned int V_15 )
{
F_5 ( V_4 , V_62 , V_72 ) ;
if ( V_15 & V_102 ) {
V_15 &= ~ ( V_103 | V_104 ) ;
V_4 -> V_105 . V_106 ++ ;
}
if ( V_15 & V_103 )
V_4 -> V_105 . V_107 ++ ;
if ( V_15 & V_104 )
V_4 -> V_105 . V_108 ++ ;
if ( V_15 & V_109 )
V_4 -> V_105 . V_110 ++ ;
}
static void F_38 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_15 , V_92 ;
V_15 = F_3 ( V_4 , V_17 ) ;
while ( V_15 & V_78 ) {
V_92 = F_7 ( V_4 ) ;
if ( F_39 ( V_15 & ( V_103 | V_104
| V_109 | V_102 )
|| V_10 -> V_111 ) ) {
F_5 ( V_4 , V_62 , V_72 ) ;
if ( V_15 & V_102
&& ! V_10 -> V_111 ) {
V_10 -> V_111 = 1 ;
F_5 ( V_4 , V_49 ,
V_102 ) ;
} else {
F_5 ( V_4 , V_34 ,
V_102 ) ;
V_15 &= ~ V_102 ;
V_10 -> V_111 = 0 ;
}
}
F_34 ( V_4 , V_15 , V_92 ) ;
V_15 = F_3 ( V_4 , V_17 ) ;
}
F_40 ( & V_10 -> V_112 ) ;
}
static void F_41 ( struct V_2 * V_4 )
{
struct V_93 * V_113 = & V_4 -> V_114 -> V_113 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( V_4 -> V_115 &&
( F_3 ( V_4 , V_17 ) & V_10 -> V_35 ) ) {
F_8 ( V_4 , V_4 -> V_115 ) ;
V_4 -> V_105 . V_116 ++ ;
V_4 -> V_115 = 0 ;
}
if ( F_42 ( V_113 ) || F_43 ( V_4 ) )
return;
while ( F_3 ( V_4 , V_17 ) &
V_10 -> V_35 ) {
F_8 ( V_4 , V_113 -> V_101 [ V_113 -> V_99 ] ) ;
V_113 -> V_99 = ( V_113 -> V_99 + 1 ) & ( V_117 - 1 ) ;
V_4 -> V_105 . V_116 ++ ;
if ( F_42 ( V_113 ) )
break;
}
if ( F_44 ( V_113 ) < V_118 )
F_45 ( V_4 ) ;
if ( ! F_42 ( V_113 ) )
F_5 ( V_4 , V_49 ,
V_10 -> V_35 ) ;
}
static void F_46 ( void * V_119 )
{
struct V_1 * V_10 = V_119 ;
struct V_2 * V_4 = & V_10 -> V_3 ;
struct V_93 * V_113 = & V_4 -> V_114 -> V_113 ;
struct V_120 * V_121 = V_10 -> V_122 ;
unsigned long V_39 ;
F_47 ( & V_4 -> V_123 , V_39 ) ;
if ( V_121 )
F_48 ( V_121 ) ;
V_113 -> V_99 += V_10 -> V_124 ;
V_113 -> V_99 &= V_117 - 1 ;
V_4 -> V_105 . V_116 += V_10 -> V_124 ;
F_49 ( & V_10 -> V_125 ) ;
F_50 ( V_10 -> V_126 ) ;
V_10 -> V_127 = - V_128 ;
V_10 -> V_126 = NULL ;
F_51 ( & V_10 -> V_125 ) ;
if ( F_44 ( V_113 ) < V_118 )
F_45 ( V_4 ) ;
if ( ! F_42 ( V_113 ) )
F_40 ( & V_10 -> V_112 ) ;
F_52 ( & V_4 -> V_123 , V_39 ) ;
}
static void F_53 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_120 * V_121 = V_10 -> V_122 ;
if ( V_121 ) {
F_48 ( V_121 ) ;
F_54 ( V_121 ) ;
F_55 ( V_4 -> V_41 , & V_10 -> V_129 , 1 ,
V_130 ) ;
}
V_10 -> V_126 = NULL ;
V_10 -> V_122 = NULL ;
V_10 -> V_127 = - V_128 ;
}
static void F_56 ( struct V_2 * V_4 )
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
if ( ! F_42 ( V_113 ) && ! F_43 ( V_4 ) ) {
V_124 = F_57 ( V_113 -> V_98 ,
V_113 -> V_99 ,
V_117 ) ;
if ( V_10 -> V_140 ) {
V_136 = ( V_124 & ~ 0x3 ) ;
V_137 = ( V_124 & 0x3 ) ;
} else {
V_136 = 0 ;
V_137 = V_124 ;
}
F_58 ( V_134 , 2 ) ;
V_138 = 0 ;
V_139 = F_59 ( V_129 ) + V_113 -> V_99 ;
if ( V_136 ) {
V_135 = & V_134 [ V_138 ++ ] ;
F_59 ( V_135 ) = V_139 ;
F_60 ( V_135 ) = V_136 ;
V_139 += V_136 ;
}
if ( V_137 ) {
V_135 = & V_134 [ V_138 ++ ] ;
F_59 ( V_135 ) = V_139 ;
F_60 ( V_135 ) = V_137 ;
}
V_10 -> V_124 = V_124 ;
V_132 = F_61 ( V_121 ,
V_134 ,
V_138 ,
V_141 ,
V_142 |
V_143 ) ;
if ( ! V_132 ) {
F_62 ( V_4 -> V_41 , L_3 ) ;
return;
}
F_63 ( V_4 -> V_41 , V_129 , 1 , V_130 ) ;
V_10 -> V_126 = V_132 ;
V_132 -> V_144 = F_46 ;
V_132 -> V_145 = V_10 ;
V_10 -> V_127 = F_64 ( V_132 ) ;
} else {
if ( V_4 -> V_38 . V_39 & V_40 ) {
F_26 ( V_4 ) ;
}
}
if ( F_44 ( V_113 ) < V_118 )
F_45 ( V_4 ) ;
}
static int F_65 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
T_6 V_146 ;
struct V_147 V_148 ;
int V_16 , V_149 ;
F_66 ( V_146 ) ;
F_67 ( V_150 , V_146 ) ;
V_10 -> V_122 = F_68 ( V_4 -> V_41 , L_4 ) ;
if ( V_10 -> V_122 == NULL )
goto V_151;
F_69 ( V_4 -> V_41 , L_5 ,
F_70 ( V_10 -> V_122 ) ) ;
F_71 ( & V_10 -> V_125 ) ;
F_58 ( & V_10 -> V_129 , 1 ) ;
F_72 ( ! F_73 ( V_4 -> V_114 -> V_113 . V_101 ) ) ;
F_74 ( & V_10 -> V_129 ,
F_75 ( V_4 -> V_114 -> V_113 . V_101 ) ,
V_117 ,
( unsigned long ) V_4 -> V_114 -> V_113 . V_101 & ~ V_152 ) ;
V_149 = F_76 ( V_4 -> V_41 ,
& V_10 -> V_129 ,
1 ,
V_130 ) ;
if ( ! V_149 ) {
F_20 ( V_4 -> V_41 , L_6 ) ;
goto V_151;
} else {
F_20 ( V_4 -> V_41 , L_7 , V_153 ,
F_60 ( & V_10 -> V_129 ) ,
V_4 -> V_114 -> V_113 . V_101 ,
& F_59 ( & V_10 -> V_129 ) ) ;
}
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
V_148 . V_154 = V_141 ;
V_148 . V_155 = ( V_10 -> V_140 ) ?
V_156 :
V_157 ;
V_148 . V_158 = V_4 -> V_159 + V_9 ;
V_148 . V_160 = 1 ;
V_16 = F_77 ( V_10 -> V_122 ,
& V_148 ) ;
if ( V_16 ) {
F_62 ( V_4 -> V_41 , L_8 ) ;
goto V_151;
}
return 0 ;
V_151:
F_62 ( V_4 -> V_41 , L_9 ) ;
V_10 -> V_13 = 0 ;
if ( V_10 -> V_122 )
F_53 ( V_4 ) ;
return - V_128 ;
}
static void F_78 ( void * V_119 )
{
struct V_2 * V_4 = V_119 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_40 ( & V_10 -> V_112 ) ;
}
static void F_79 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_120 * V_121 = V_10 -> V_161 ;
if ( V_121 ) {
F_48 ( V_121 ) ;
F_54 ( V_121 ) ;
F_55 ( V_4 -> V_41 , & V_10 -> V_162 , 1 ,
V_163 ) ;
}
V_10 -> V_164 = NULL ;
V_10 -> V_161 = NULL ;
V_10 -> V_165 = - V_128 ;
}
static void F_80 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_166 * V_167 = & V_4 -> V_114 -> V_4 ;
struct V_93 * V_94 = & V_10 -> V_95 ;
struct V_120 * V_121 = V_10 -> V_161 ;
struct V_168 V_114 ;
enum V_169 V_170 ;
T_7 V_171 ;
F_5 ( V_4 , V_62 , V_172 ) ;
V_170 = F_81 ( V_121 ,
V_10 -> V_165 ,
& V_114 ) ;
if ( V_170 == V_173 ) {
F_20 ( V_4 -> V_41 , L_10 ) ;
F_5 ( V_4 , V_49 , V_75 ) ;
F_40 ( & V_10 -> V_112 ) ;
return;
}
F_82 ( V_4 -> V_41 ,
& V_10 -> V_162 ,
1 ,
V_163 ) ;
V_94 -> V_98 = F_60 ( & V_10 -> V_162 ) - V_114 . V_174 ;
F_72 ( V_94 -> V_98 > F_60 ( & V_10 -> V_162 ) ) ;
if ( V_94 -> V_98 < V_94 -> V_99 ) {
V_171 = F_60 ( & V_10 -> V_162 ) - V_94 -> V_99 ;
F_83 ( V_167 , V_94 -> V_101 + V_94 -> V_99 , V_171 ) ;
V_94 -> V_99 = 0 ;
V_4 -> V_105 . V_175 += V_171 ;
}
if ( V_94 -> V_99 < V_94 -> V_98 ) {
V_171 = V_94 -> V_98 - V_94 -> V_99 ;
F_83 ( V_167 , V_94 -> V_101 + V_94 -> V_99 , V_171 ) ;
if ( V_94 -> V_98 >= F_60 ( & V_10 -> V_162 ) )
V_94 -> V_98 = 0 ;
V_94 -> V_99 = V_94 -> V_98 ;
V_4 -> V_105 . V_175 += V_171 ;
}
F_63 ( V_4 -> V_41 ,
& V_10 -> V_162 ,
1 ,
V_163 ) ;
F_84 ( & V_4 -> V_123 ) ;
F_85 ( V_167 ) ;
F_86 ( & V_4 -> V_123 ) ;
F_5 ( V_4 , V_49 , V_75 ) ;
}
static int F_87 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_131 * V_132 ;
T_6 V_146 ;
struct V_147 V_148 ;
struct V_93 * V_94 ;
int V_16 , V_149 ;
V_94 = & V_10 -> V_95 ;
F_66 ( V_146 ) ;
F_67 ( V_176 , V_146 ) ;
V_10 -> V_161 = F_68 ( V_4 -> V_41 , L_11 ) ;
if ( V_10 -> V_161 == NULL )
goto V_151;
F_69 ( V_4 -> V_41 , L_12 ,
F_70 ( V_10 -> V_161 ) ) ;
F_71 ( & V_10 -> V_177 ) ;
F_58 ( & V_10 -> V_162 , 1 ) ;
F_72 ( ! F_73 ( V_94 -> V_101 ) ) ;
F_74 ( & V_10 -> V_162 ,
F_75 ( V_94 -> V_101 ) ,
sizeof( struct V_96 ) * V_100 ,
( unsigned long ) V_94 -> V_101 & ~ V_152 ) ;
V_149 = F_76 ( V_4 -> V_41 ,
& V_10 -> V_162 ,
1 ,
V_163 ) ;
if ( ! V_149 ) {
F_20 ( V_4 -> V_41 , L_6 ) ;
goto V_151;
} else {
F_20 ( V_4 -> V_41 , L_7 , V_153 ,
F_60 ( & V_10 -> V_162 ) ,
V_94 -> V_101 ,
& F_59 ( & V_10 -> V_162 ) ) ;
}
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
V_148 . V_154 = V_178 ;
V_148 . V_179 = V_157 ;
V_148 . V_180 = V_4 -> V_159 + V_8 ;
V_148 . V_181 = 1 ;
V_16 = F_77 ( V_10 -> V_161 ,
& V_148 ) ;
if ( V_16 ) {
F_62 ( V_4 -> V_41 , L_13 ) ;
goto V_151;
}
V_132 = F_88 ( V_10 -> V_161 ,
F_59 ( & V_10 -> V_162 ) ,
F_60 ( & V_10 -> V_162 ) ,
F_60 ( & V_10 -> V_162 ) / 2 ,
V_178 ,
V_142 ) ;
V_132 -> V_144 = F_78 ;
V_132 -> V_145 = V_4 ;
V_10 -> V_164 = V_132 ;
V_10 -> V_165 = F_64 ( V_132 ) ;
return 0 ;
V_151:
F_62 ( V_4 -> V_41 , L_14 ) ;
V_10 -> V_14 = 0 ;
if ( V_10 -> V_161 )
F_79 ( V_4 ) ;
return - V_128 ;
}
static void F_89 ( unsigned long V_182 )
{
struct V_2 * V_4 = ( void * ) V_182 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_40 ( & V_10 -> V_112 ) ;
F_90 ( & V_10 -> V_183 , V_184 + F_91 ( V_4 ) ) ;
}
static void
F_92 ( struct V_2 * V_4 , unsigned int V_185 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_11 ( V_4 ) ) {
if ( V_185 & ( V_74 | V_75 ) ) {
F_5 ( V_4 , V_34 ,
( V_74 | V_75 ) ) ;
F_40 ( & V_10 -> V_112 ) ;
}
if ( V_185 & ( V_102 | V_109 |
V_104 | V_103 ) )
F_37 ( V_4 , V_185 ) ;
}
if ( F_14 ( V_4 ) ) {
if ( V_185 & V_75 ) {
F_5 ( V_4 , V_34 ,
V_75 ) ;
F_40 ( & V_10 -> V_112 ) ;
}
}
if ( V_185 & V_78 )
F_38 ( V_4 ) ;
else if ( V_185 & V_102 ) {
F_5 ( V_4 , V_62 , V_72 ) ;
F_5 ( V_4 , V_34 , V_102 ) ;
V_10 -> V_111 = 0 ;
}
}
static void
F_93 ( struct V_2 * V_4 , unsigned int V_185 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( V_185 & V_10 -> V_35 ) {
F_5 ( V_4 , V_34 ,
V_10 -> V_35 ) ;
F_40 ( & V_10 -> V_112 ) ;
}
}
static void
F_94 ( struct V_2 * V_4 , unsigned int V_185 ,
unsigned int V_15 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( V_185 & ( V_86 | V_85 | V_87
| V_84 ) ) {
V_10 -> V_186 = V_15 ;
V_10 -> V_187 = V_10 -> V_186 ^
V_10 -> V_188 ;
V_10 -> V_188 = V_15 ;
F_40 ( & V_10 -> V_112 ) ;
}
}
static T_8 F_95 ( int V_189 , void * V_190 )
{
struct V_2 * V_4 = V_190 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_15 , V_185 , V_146 , V_191 = 0 ;
bool V_192 = false ;
F_86 ( & V_10 -> V_193 ) ;
do {
V_15 = F_15 ( V_4 ) ;
V_146 = F_3 ( V_4 , V_194 ) ;
V_185 = V_15 & V_146 ;
if ( ! V_192 ) {
if ( V_189 == V_10 -> V_83 [ V_19 ] )
V_185 |= V_84 ;
if ( V_189 == V_10 -> V_83 [ V_22 ] )
V_185 |= V_85 ;
if ( V_189 == V_10 -> V_83 [ V_25 ] )
V_185 |= V_86 ;
if ( V_189 == V_10 -> V_83 [ V_28 ] )
V_185 |= V_87 ;
V_192 = true ;
}
if ( ! V_185 )
break;
if ( V_10 -> V_195 ) {
V_10 -> V_185 |= V_185 ;
V_10 -> V_196 = V_15 ;
F_5 ( V_4 , V_34 , V_146 ) ;
F_96 () ;
break;
}
F_92 ( V_4 , V_185 ) ;
F_94 ( V_4 , V_185 , V_15 ) ;
F_93 ( V_4 , V_185 ) ;
} while ( V_191 ++ < V_197 );
F_84 ( & V_10 -> V_193 ) ;
return V_191 ? V_198 : V_199 ;
}
static void F_97 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_200 * V_201 = & V_10 -> V_202 ;
F_98 ( V_4 -> V_41 ,
V_201 -> V_203 ,
V_201 -> V_204 ,
V_130 ) ;
}
static void F_99 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_93 * V_113 = & V_4 -> V_114 -> V_113 ;
struct V_200 * V_201 = & V_10 -> V_202 ;
int V_171 ;
if ( F_3 ( V_4 , V_205 ) )
return;
V_113 -> V_99 += V_201 -> V_206 ;
V_113 -> V_99 &= V_117 - 1 ;
V_4 -> V_105 . V_116 += V_201 -> V_206 ;
V_201 -> V_206 = 0 ;
F_5 ( V_4 , V_67 , V_68 ) ;
if ( ! F_42 ( V_113 ) && ! F_43 ( V_4 ) ) {
F_100 ( V_4 -> V_41 ,
V_201 -> V_203 ,
V_201 -> V_204 ,
V_130 ) ;
V_171 = F_57 ( V_113 -> V_98 , V_113 -> V_99 , V_117 ) ;
V_201 -> V_206 = V_171 ;
F_5 ( V_4 , V_207 ,
V_201 -> V_203 + V_113 -> V_99 ) ;
F_5 ( V_4 , V_205 , V_171 ) ;
F_5 ( V_4 , V_67 , V_71 ) ;
F_5 ( V_4 , V_49 ,
V_10 -> V_35 ) ;
} else {
if ( ( V_4 -> V_38 . V_39 & V_40 ) &&
! ( V_4 -> V_38 . V_39 & V_69 ) ) {
F_26 ( V_4 ) ;
}
}
if ( F_44 ( V_113 ) < V_118 )
F_45 ( V_4 ) ;
}
static int F_101 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_200 * V_201 = & V_10 -> V_202 ;
struct V_93 * V_113 = & V_4 -> V_114 -> V_113 ;
V_201 -> V_101 = V_113 -> V_101 ;
V_201 -> V_203 = F_102 ( V_4 -> V_41 ,
V_201 -> V_101 ,
V_117 ,
V_130 ) ;
V_201 -> V_204 = V_117 ;
V_201 -> V_206 = 0 ;
return 0 ;
}
static void F_103 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_93 * V_94 = & V_10 -> V_95 ;
unsigned int V_208 ;
unsigned int V_15 ;
while ( V_94 -> V_98 != V_94 -> V_99 ) {
struct V_96 V_97 ;
F_104 () ;
V_97 = ( (struct V_96 * ) V_94 -> V_101 ) [ V_94 -> V_99 ] ;
V_94 -> V_99 = ( V_94 -> V_99 + 1 ) & ( V_100 - 1 ) ;
V_4 -> V_105 . V_175 ++ ;
V_15 = V_97 . V_15 ;
V_208 = V_209 ;
if ( F_39 ( V_15 & ( V_103 | V_104
| V_109 | V_102 ) ) ) {
if ( V_15 & V_102 ) {
V_15 &= ~ ( V_103 | V_104 ) ;
V_4 -> V_105 . V_106 ++ ;
if ( F_105 ( V_4 ) )
continue;
}
if ( V_15 & V_103 )
V_4 -> V_105 . V_107 ++ ;
if ( V_15 & V_104 )
V_4 -> V_105 . V_108 ++ ;
if ( V_15 & V_109 )
V_4 -> V_105 . V_110 ++ ;
V_15 &= V_4 -> V_76 ;
if ( V_15 & V_102 )
V_208 = V_210 ;
else if ( V_15 & V_103 )
V_208 = V_211 ;
else if ( V_15 & V_104 )
V_208 = V_212 ;
}
if ( F_106 ( V_4 , V_97 . V_92 ) )
continue;
F_107 ( V_4 , V_15 , V_109 , V_97 . V_92 , V_208 ) ;
}
F_84 ( & V_4 -> V_123 ) ;
F_85 ( & V_4 -> V_114 -> V_4 ) ;
F_86 ( & V_4 -> V_123 ) ;
}
static void F_108 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_213 ;
for ( V_213 = 0 ; V_213 < 2 ; V_213 ++ ) {
struct V_200 * V_201 = & V_10 -> V_214 [ V_213 ] ;
F_98 ( V_4 -> V_41 ,
V_201 -> V_203 ,
V_201 -> V_204 ,
V_163 ) ;
F_109 ( V_201 -> V_101 ) ;
}
}
static void F_110 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_166 * V_167 = & V_4 -> V_114 -> V_4 ;
struct V_200 * V_201 ;
int V_215 = V_10 -> V_216 ;
unsigned int V_98 ;
unsigned int V_99 ;
unsigned int V_171 ;
do {
F_5 ( V_4 , V_62 , V_172 ) ;
V_201 = & V_10 -> V_214 [ V_215 ] ;
V_98 = F_3 ( V_4 , V_217 ) - V_201 -> V_203 ;
V_99 = V_201 -> V_206 ;
V_98 = F_111 ( V_98 , V_201 -> V_204 ) ;
if ( F_112 ( V_98 != V_99 ) ) {
F_113 ( V_4 -> V_41 , V_201 -> V_203 ,
V_201 -> V_204 , V_163 ) ;
V_171 = V_98 - V_99 ;
F_83 ( V_167 , V_201 -> V_101 + V_201 -> V_206 ,
V_171 ) ;
F_100 ( V_4 -> V_41 , V_201 -> V_203 ,
V_201 -> V_204 , V_163 ) ;
V_4 -> V_105 . V_175 += V_171 ;
V_201 -> V_206 = V_98 ;
}
if ( V_98 >= V_201 -> V_204 ) {
V_201 -> V_206 = 0 ;
F_5 ( V_4 , V_218 , V_201 -> V_203 ) ;
F_5 ( V_4 , V_219 , V_201 -> V_204 ) ;
V_215 = ! V_215 ;
V_10 -> V_216 = V_215 ;
}
} while ( V_98 >= V_201 -> V_204 );
F_84 ( & V_4 -> V_123 ) ;
F_85 ( V_167 ) ;
F_86 ( & V_4 -> V_123 ) ;
F_5 ( V_4 , V_49 ,
V_74 | V_75 ) ;
}
static int F_114 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_213 ;
for ( V_213 = 0 ; V_213 < 2 ; V_213 ++ ) {
struct V_200 * V_201 = & V_10 -> V_214 [ V_213 ] ;
V_201 -> V_101 = F_115 ( V_220 , V_221 ) ;
if ( V_201 -> V_101 == NULL ) {
if ( V_213 != 0 ) {
F_98 ( V_4 -> V_41 ,
V_10 -> V_214 [ 0 ] . V_203 ,
V_220 ,
V_163 ) ;
F_109 ( V_10 -> V_214 [ 0 ] . V_101 ) ;
}
V_10 -> V_11 = 0 ;
return - V_222 ;
}
V_201 -> V_203 = F_102 ( V_4 -> V_41 ,
V_201 -> V_101 ,
V_220 ,
V_163 ) ;
V_201 -> V_204 = V_220 ;
V_201 -> V_206 = 0 ;
}
V_10 -> V_216 = 0 ;
F_5 ( V_4 , V_217 , V_10 -> V_214 [ 0 ] . V_203 ) ;
F_5 ( V_4 , V_223 , V_220 ) ;
F_5 ( V_4 , V_218 ,
V_10 -> V_214 [ 1 ] . V_203 ) ;
F_5 ( V_4 , V_219 , V_220 ) ;
return 0 ;
}
static void F_116 ( unsigned long V_182 )
{
struct V_2 * V_4 = (struct V_2 * ) V_182 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_15 = V_10 -> V_186 ;
unsigned int V_187 = V_10 -> V_187 ;
F_86 ( & V_4 -> V_123 ) ;
V_10 -> V_224 ( V_4 ) ;
if ( V_187 & ( V_27 | V_24
| V_30 | V_21 ) ) {
if ( V_187 & V_27 )
V_4 -> V_105 . V_225 ++ ;
if ( V_187 & V_24 )
V_4 -> V_105 . V_226 ++ ;
if ( V_187 & V_30 )
F_117 ( V_4 , ! ( V_15 & V_30 ) ) ;
if ( V_187 & V_21 )
F_118 ( V_4 , ! ( V_15 & V_21 ) ) ;
F_119 ( & V_4 -> V_114 -> V_4 . V_227 ) ;
V_10 -> V_187 = 0 ;
}
V_10 -> V_228 ( V_4 ) ;
F_84 ( & V_4 -> V_123 ) ;
}
static void F_120 ( struct V_1 * V_10 ,
struct V_229 * V_230 )
{
struct V_231 * V_232 = V_230 -> V_41 . V_233 ;
struct V_234 * V_235 = F_121 ( & V_230 -> V_41 ) ;
if ( V_232 ) {
if ( F_122 ( V_232 , L_15 , NULL ) ) {
if ( F_122 ( V_232 , L_16 , NULL ) ) {
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
if ( F_122 ( V_232 , L_17 , NULL ) ) {
if ( F_122 ( V_232 , L_16 , NULL ) ) {
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
V_10 -> V_11 = V_235 -> V_14 ;
V_10 -> V_12 = V_235 -> V_13 ;
V_10 -> V_14 = false ;
V_10 -> V_13 = false ;
}
}
static void F_123 ( struct V_2 * V_4 ,
struct V_229 * V_230 )
{
struct V_231 * V_232 = V_230 -> V_41 . V_233 ;
struct V_234 * V_235 = F_121 ( & V_230 -> V_41 ) ;
if ( V_232 ) {
struct V_31 * V_32 = & V_4 -> V_38 ;
T_1 V_236 [ 2 ] ;
if ( F_124 ( V_232 , L_18 ,
V_236 , 2 ) == 0 ) {
V_32 -> V_237 = V_236 [ 0 ] ;
V_32 -> V_44 = V_236 [ 1 ] ;
V_32 -> V_39 = 0 ;
}
if ( F_122 ( V_232 , L_19 , NULL ) )
V_32 -> V_39 |= V_69 ;
if ( F_122 ( V_232 , L_20 ,
NULL ) )
V_32 -> V_39 |= V_40 ;
} else {
V_4 -> V_38 = V_235 -> V_38 ;
}
}
static void F_125 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_14 ( V_4 ) ) {
V_10 -> V_238 = & F_87 ;
V_10 -> V_228 = & F_80 ;
V_10 -> V_239 = & F_79 ;
} else if ( F_11 ( V_4 ) ) {
V_10 -> V_238 = & F_114 ;
V_10 -> V_228 = & F_110 ;
V_10 -> V_239 = & F_108 ;
} else {
V_10 -> V_238 = NULL ;
V_10 -> V_228 = & F_103 ;
V_10 -> V_239 = NULL ;
}
if ( F_13 ( V_4 ) ) {
V_10 -> V_240 = & F_65 ;
V_10 -> V_224 = & F_56 ;
V_10 -> V_241 = & F_53 ;
} else if ( F_12 ( V_4 ) ) {
V_10 -> V_240 = & F_101 ;
V_10 -> V_224 = & F_99 ;
V_10 -> V_241 = & F_97 ;
} else {
V_10 -> V_240 = NULL ;
V_10 -> V_224 = & F_41 ;
V_10 -> V_241 = NULL ;
}
}
static void F_126 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_242 = F_3 ( V_4 , V_243 ) ;
T_1 V_244 ;
int V_245 , V_3 ;
V_245 = 0x55534152 ;
V_3 = 0x44424755 ;
V_10 -> V_246 = false ;
if ( V_242 == V_245 ) {
F_20 ( V_4 -> V_41 , L_21 ) ;
V_10 -> V_246 = true ;
} else if ( V_242 == V_3 ) {
F_20 ( V_4 -> V_41 , L_22 ) ;
V_10 -> V_246 = false ;
} else {
V_244 = F_3 ( V_4 , V_247 ) ;
switch ( V_244 ) {
case 0x302 :
case 0x10213 :
F_20 ( V_4 -> V_41 , L_23 ) ;
V_10 -> V_246 = true ;
break;
case 0x203 :
case 0x10202 :
F_20 ( V_4 -> V_41 , L_24 ) ;
V_10 -> V_246 = false ;
break;
default:
F_62 ( V_4 -> V_41 , L_25 ) ;
}
}
}
static void F_127 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
enum V_248 V_213 ;
for ( V_213 = 0 ; V_213 < V_249 ; V_213 ++ )
if ( V_10 -> V_83 [ V_213 ] >= 0 )
F_128 ( V_10 -> V_83 [ V_213 ] , V_4 ) ;
}
static int F_129 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
int * V_189 = V_10 -> V_83 ;
enum V_248 V_213 ;
int V_250 = 0 ;
for ( V_213 = 0 ; ( V_213 < V_249 ) && ! V_250 ; V_213 ++ ) {
if ( V_189 [ V_213 ] < 0 )
continue;
F_130 ( V_189 [ V_213 ] , V_251 ) ;
V_250 = F_131 ( V_189 [ V_213 ] , F_95 , V_252 ,
L_26 , V_4 ) ;
if ( V_250 )
F_62 ( V_4 -> V_41 , L_27 ,
V_189 [ V_213 ] ) ;
}
while ( V_250 && ( -- V_213 >= 0 ) )
if ( V_189 [ V_213 ] >= 0 )
F_128 ( V_189 [ V_213 ] , V_4 ) ;
return V_250 ;
}
static int F_132 ( struct V_2 * V_4 )
{
struct V_229 * V_230 = F_133 ( V_4 -> V_41 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_253 * V_254 = V_4 -> V_114 -> V_4 . V_254 ;
int V_255 ;
F_5 ( V_4 , V_34 , - 1 ) ;
V_10 -> V_82 = false ;
V_255 = F_131 ( V_4 -> V_189 , F_95 ,
V_256 | V_257 ,
V_254 ? V_254 -> V_242 : L_26 , V_4 ) ;
if ( V_255 ) {
F_62 ( V_4 -> V_41 , L_28 ) ;
return V_255 ;
}
V_255 = F_129 ( V_4 ) ;
if ( V_255 )
goto F_128;
F_134 ( & V_10 -> V_112 ) ;
F_120 ( V_10 , V_230 ) ;
F_125 ( V_4 ) ;
if ( V_10 -> V_238 ) {
V_255 = V_10 -> V_238 ( V_4 ) ;
if ( V_255 < 0 )
F_125 ( V_4 ) ;
}
if ( V_10 -> V_240 ) {
V_255 = V_10 -> V_240 ( V_4 ) ;
if ( V_255 < 0 )
F_125 ( V_4 ) ;
}
if ( V_10 -> V_140 ) {
unsigned int V_258 = V_259 ;
unsigned int V_260 = V_259 ;
unsigned int V_261 ;
F_5 ( V_4 , V_62 ,
V_262 |
V_263 |
V_264 ) ;
if ( F_13 ( V_4 ) )
V_258 = V_265 ;
V_261 = F_135 ( V_258 ) | F_136 ( V_260 ) ;
if ( V_10 -> V_266 &&
V_10 -> V_267 )
V_261 |= V_268 |
F_137 ( V_10 -> V_266 ) |
F_138 ( V_10 -> V_267 ) ;
F_5 ( V_4 , V_269 , V_261 ) ;
}
V_10 -> V_188 = F_15 ( V_4 ) ;
V_10 -> V_186 = V_10 -> V_188 ;
F_5 ( V_4 , V_62 , V_72 | V_270 ) ;
F_5 ( V_4 , V_62 , V_271 | V_73 ) ;
F_139 ( & V_10 -> V_183 ,
F_89 ,
( unsigned long ) V_4 ) ;
if ( F_11 ( V_4 ) ) {
if ( ! V_10 -> V_246 ) {
F_90 ( & V_10 -> V_183 ,
V_184 + F_91 ( V_4 ) ) ;
} else {
F_5 ( V_4 , V_272 , V_273 ) ;
F_5 ( V_4 , V_62 , V_172 ) ;
F_5 ( V_4 , V_49 ,
V_74 | V_75 ) ;
}
F_5 ( V_4 , V_67 , V_77 ) ;
} else if ( F_14 ( V_4 ) ) {
if ( ! V_10 -> V_246 ) {
F_90 ( & V_10 -> V_183 ,
V_184 + F_91 ( V_4 ) ) ;
} else {
F_5 ( V_4 , V_272 , V_273 ) ;
F_5 ( V_4 , V_62 , V_172 ) ;
F_5 ( V_4 , V_49 ,
V_75 ) ;
}
} else {
F_5 ( V_4 , V_49 , V_78 ) ;
}
return 0 ;
F_128:
F_128 ( V_4 -> V_189 , V_4 ) ;
return V_255 ;
}
static void F_140 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_12 ( V_4 ) ) {
F_5 ( V_4 , V_205 , 0 ) ;
V_10 -> V_202 . V_206 = 0 ;
}
}
static void F_141 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_142 ( & V_10 -> V_183 ) ;
F_143 ( & V_10 -> V_112 ) ;
F_144 ( & V_10 -> V_112 ) ;
F_28 ( V_4 ) ;
F_25 ( V_4 ) ;
F_5 ( V_4 , V_62 , V_72 ) ;
F_5 ( V_4 , V_34 , - 1 ) ;
if ( V_10 -> V_239 )
V_10 -> V_239 ( V_4 ) ;
if ( V_10 -> V_241 )
V_10 -> V_241 ( V_4 ) ;
V_10 -> V_95 . V_98 = 0 ;
V_10 -> V_95 . V_99 = 0 ;
F_128 ( V_4 -> V_189 , V_4 ) ;
F_127 ( V_4 ) ;
V_10 -> V_82 = false ;
F_140 ( V_4 ) ;
}
static void F_145 ( struct V_2 * V_4 , unsigned int V_114 ,
unsigned int V_274 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
switch ( V_114 ) {
case 0 :
F_146 ( V_10 -> V_275 ) ;
F_5 ( V_4 , V_49 , V_10 -> V_276 ) ;
break;
case 3 :
V_10 -> V_276 = F_3 ( V_4 , V_194 ) ;
F_5 ( V_4 , V_34 , - 1 ) ;
F_147 ( V_10 -> V_275 ) ;
break;
default:
F_62 ( V_4 -> V_41 , L_29 , V_114 ) ;
}
}
static void F_148 ( struct V_2 * V_4 , struct V_277 * V_278 ,
struct V_277 * V_279 )
{
unsigned long V_39 ;
unsigned int V_280 , V_33 , V_281 , V_282 , V_283 ;
V_33 = V_280 = F_3 ( V_4 , V_36 ) ;
V_33 &= ~ ( V_284 | V_285 | V_286 |
V_287 | V_37 ) ;
V_283 = F_149 ( V_4 , V_278 , V_279 , 0 , V_4 -> V_288 / 16 ) ;
V_282 = F_150 ( V_4 , V_283 ) ;
if ( V_282 > 65535 ) {
V_282 /= 8 ;
V_33 |= V_289 ;
}
switch ( V_278 -> V_290 & V_291 ) {
case V_292 :
V_33 |= V_293 ;
break;
case V_294 :
V_33 |= V_295 ;
break;
case V_296 :
V_33 |= V_297 ;
break;
default:
V_33 |= V_298 ;
break;
}
if ( V_278 -> V_290 & V_299 )
V_33 |= V_300 ;
if ( V_278 -> V_290 & V_301 ) {
if ( V_278 -> V_290 & V_302 ) {
if ( V_278 -> V_290 & V_303 )
V_33 |= V_304 ;
else
V_33 |= V_305 ;
} else if ( V_278 -> V_290 & V_303 )
V_33 |= V_306 ;
else
V_33 |= V_307 ;
} else
V_33 |= V_308 ;
F_47 ( & V_4 -> V_123 , V_39 ) ;
V_4 -> V_76 = V_109 ;
if ( V_278 -> V_309 & V_310 )
V_4 -> V_76 |= ( V_104 | V_103 ) ;
if ( V_278 -> V_309 & ( V_311 | V_312 | V_313 ) )
V_4 -> V_76 |= V_102 ;
if ( F_11 ( V_4 ) )
F_5 ( V_4 , V_49 , V_4 -> V_76 ) ;
V_4 -> V_314 = 0 ;
if ( V_278 -> V_309 & V_315 )
V_4 -> V_314 |= ( V_104 | V_103 ) ;
if ( V_278 -> V_309 & V_311 ) {
V_4 -> V_314 |= V_102 ;
if ( V_278 -> V_309 & V_315 )
V_4 -> V_314 |= V_109 ;
}
F_151 ( V_4 , V_278 -> V_290 , V_283 ) ;
V_281 = F_3 ( V_4 , V_194 ) ;
F_5 ( V_4 , V_34 , - 1 ) ;
F_5 ( V_4 , V_62 , V_316 | V_79 ) ;
if ( V_4 -> V_38 . V_39 & V_40 ) {
F_5 ( V_4 , V_43 ,
V_4 -> V_38 . V_44 ) ;
V_33 |= V_45 ;
} else if ( V_278 -> V_290 & V_317 ) {
V_33 |= V_55 ;
} else {
V_33 |= V_318 ;
}
F_5 ( V_4 , V_36 , V_33 ) ;
if ( ( V_280 & V_37 ) != ( V_33 & V_37 ) ) {
unsigned int V_319 ;
if ( ( V_33 & V_37 ) == V_55 ) {
V_319 = V_57 ;
} else {
V_319 = V_56 ;
}
F_5 ( V_4 , V_62 , V_319 ) ;
}
F_5 ( V_4 , V_320 , V_282 ) ;
F_5 ( V_4 , V_62 , V_72 | V_270 ) ;
F_5 ( V_4 , V_62 , V_271 | V_73 ) ;
F_5 ( V_4 , V_49 , V_281 ) ;
if ( F_152 ( V_4 , V_278 -> V_290 ) )
F_29 ( V_4 ) ;
else
F_31 ( V_4 ) ;
F_52 ( & V_4 -> V_123 , V_39 ) ;
}
static void F_153 ( struct V_2 * V_4 , struct V_277 * V_278 )
{
if ( V_278 -> V_321 == V_322 ) {
V_4 -> V_39 |= V_323 ;
F_49 ( & V_4 -> V_123 ) ;
F_29 ( V_4 ) ;
F_51 ( & V_4 -> V_123 ) ;
} else {
V_4 -> V_39 &= ~ V_323 ;
if ( ! F_152 ( V_4 , V_278 -> V_290 ) ) {
F_49 ( & V_4 -> V_123 ) ;
F_31 ( V_4 ) ;
F_51 ( & V_4 -> V_123 ) ;
}
}
}
static const char * F_154 ( struct V_2 * V_4 )
{
return ( V_4 -> type == V_324 ) ? L_30 : NULL ;
}
static void F_155 ( struct V_2 * V_4 )
{
struct V_229 * V_230 = F_133 ( V_4 -> V_41 ) ;
int V_325 = V_230 -> V_326 [ 0 ] . V_327 - V_230 -> V_326 [ 0 ] . V_328 + 1 ;
F_156 ( V_4 -> V_159 , V_325 ) ;
if ( V_4 -> V_39 & V_329 ) {
F_157 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
}
static int F_158 ( struct V_2 * V_4 )
{
struct V_229 * V_230 = F_133 ( V_4 -> V_41 ) ;
int V_325 = V_230 -> V_326 [ 0 ] . V_327 - V_230 -> V_326 [ 0 ] . V_328 + 1 ;
if ( ! F_159 ( V_4 -> V_159 , V_325 , L_26 ) )
return - V_330 ;
if ( V_4 -> V_39 & V_329 ) {
V_4 -> V_6 = F_160 ( V_4 -> V_159 , V_325 ) ;
if ( V_4 -> V_6 == NULL ) {
F_156 ( V_4 -> V_159 , V_325 ) ;
return - V_222 ;
}
}
return 0 ;
}
static void F_161 ( struct V_2 * V_4 , int V_39 )
{
if ( V_39 & V_331 ) {
V_4 -> type = V_324 ;
F_158 ( V_4 ) ;
}
}
static int F_162 ( struct V_2 * V_4 , struct V_332 * V_333 )
{
int V_16 = 0 ;
if ( V_333 -> type != V_334 && V_333 -> type != V_324 )
V_16 = - V_128 ;
if ( V_4 -> V_189 != V_333 -> V_189 )
V_16 = - V_128 ;
if ( V_333 -> V_335 != V_336 )
V_16 = - V_128 ;
if ( V_4 -> V_288 / 16 != V_333 -> V_337 )
V_16 = - V_128 ;
if ( V_4 -> V_159 != ( unsigned long ) V_333 -> V_338 )
V_16 = - V_128 ;
if ( V_4 -> V_339 != V_333 -> V_4 )
V_16 = - V_128 ;
if ( V_333 -> V_340 != 0 )
V_16 = - V_128 ;
return V_16 ;
}
static int F_163 ( struct V_2 * V_4 )
{
while ( ! ( F_3 ( V_4 , V_17 ) & V_78 ) )
F_164 () ;
return F_7 ( V_4 ) ;
}
static void F_165 ( struct V_2 * V_4 , unsigned char V_92 )
{
while ( ! ( F_3 ( V_4 , V_17 ) & V_48 ) )
F_164 () ;
F_8 ( V_4 , V_92 ) ;
}
static int F_166 ( struct V_1 * V_10 ,
struct V_229 * V_230 )
{
int V_16 ;
struct V_2 * V_4 = & V_10 -> V_3 ;
struct V_234 * V_235 = F_121 ( & V_230 -> V_41 ) ;
F_120 ( V_10 , V_230 ) ;
F_125 ( V_4 ) ;
F_123 ( V_4 , V_230 ) ;
V_4 -> V_341 = V_342 ;
V_4 -> V_39 = V_343 ;
V_4 -> V_344 = & V_345 ;
V_4 -> V_346 = 1 ;
V_4 -> V_41 = & V_230 -> V_41 ;
V_4 -> V_159 = V_230 -> V_326 [ 0 ] . V_328 ;
V_4 -> V_189 = V_230 -> V_326 [ 1 ] . V_328 ;
V_4 -> V_347 = F_19 ;
F_167 ( & V_10 -> V_112 , F_116 ,
( unsigned long ) V_4 ) ;
F_143 ( & V_10 -> V_112 ) ;
memset ( & V_10 -> V_95 , 0 , sizeof( V_10 -> V_95 ) ) ;
if ( V_235 && V_235 -> V_348 ) {
V_4 -> V_6 = V_235 -> V_348 ;
} else {
V_4 -> V_39 |= V_329 ;
V_4 -> V_6 = NULL ;
}
if ( ! V_10 -> V_275 ) {
V_10 -> V_275 = F_168 ( & V_230 -> V_41 , L_31 ) ;
if ( F_169 ( V_10 -> V_275 ) ) {
V_16 = F_170 ( V_10 -> V_275 ) ;
V_10 -> V_275 = NULL ;
return V_16 ;
}
V_16 = F_146 ( V_10 -> V_275 ) ;
if ( V_16 ) {
F_171 ( V_10 -> V_275 ) ;
V_10 -> V_275 = NULL ;
return V_16 ;
}
V_4 -> V_288 = F_172 ( V_10 -> V_275 ) ;
F_147 ( V_10 -> V_275 ) ;
}
if ( V_4 -> V_38 . V_39 & V_40 )
V_10 -> V_35 = V_42 ;
else if ( F_12 ( V_4 ) ) {
V_4 -> V_346 = V_220 ;
V_10 -> V_35 = V_46 | V_47 ;
} else {
V_10 -> V_35 = V_48 ;
}
return 0 ;
}
static void F_173 ( struct V_2 * V_4 , int V_92 )
{
while ( ! ( F_3 ( V_4 , V_17 ) & V_48 ) )
F_164 () ;
F_8 ( V_4 , V_92 ) ;
}
static void F_174 ( struct V_349 * V_350 , const char * V_351 , T_3 V_171 )
{
struct V_2 * V_4 = & V_352 [ V_350 -> V_353 ] . V_3 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_15 , V_281 ;
unsigned int V_202 ;
V_281 = F_3 ( V_4 , V_194 ) ;
F_5 ( V_4 , V_34 ,
V_78 | V_10 -> V_35 ) ;
V_202 = F_3 ( V_4 , V_70 ) & V_71 ;
F_5 ( V_4 , V_67 , V_68 ) ;
F_175 ( V_4 , V_351 , V_171 , F_173 ) ;
do {
V_15 = F_3 ( V_4 , V_17 ) ;
} while ( ! ( V_15 & V_48 ) );
if ( V_202 )
F_5 ( V_4 , V_67 , V_71 ) ;
F_5 ( V_4 , V_49 , V_281 ) ;
}
static void T_9 F_176 ( struct V_2 * V_4 , int * V_283 ,
int * V_107 , int * V_354 )
{
unsigned int V_355 , V_282 ;
V_282 = F_3 ( V_4 , V_320 ) & V_356 ;
if ( ! V_282 )
return;
V_355 = F_3 ( V_4 , V_36 ) & V_285 ;
if ( V_355 == V_298 )
* V_354 = 8 ;
else
* V_354 = 7 ;
V_355 = F_3 ( V_4 , V_36 ) & V_287 ;
if ( V_355 == V_307 )
* V_107 = 'e' ;
else if ( V_355 == V_306 )
* V_107 = 'o' ;
* V_283 = V_4 -> V_288 / ( 16 * ( V_282 - 1 ) ) ;
}
static int T_9 F_177 ( struct V_349 * V_350 , char * V_357 )
{
int V_16 ;
struct V_2 * V_4 = & V_352 [ V_350 -> V_353 ] . V_3 ;
int V_283 = 115200 ;
int V_354 = 8 ;
int V_107 = 'n' ;
int V_358 = 'n' ;
if ( V_4 -> V_6 == NULL ) {
return - V_359 ;
}
V_16 = F_146 ( V_352 [ V_350 -> V_353 ] . V_275 ) ;
if ( V_16 )
return V_16 ;
F_5 ( V_4 , V_34 , - 1 ) ;
F_5 ( V_4 , V_62 , V_72 | V_270 ) ;
F_5 ( V_4 , V_62 , V_271 | V_73 ) ;
if ( V_357 )
F_178 ( V_357 , & V_283 , & V_107 , & V_354 , & V_358 ) ;
else
F_176 ( V_4 , & V_283 , & V_107 , & V_354 ) ;
return F_179 ( V_4 , V_350 , V_283 , V_107 , V_354 , V_358 ) ;
}
static int T_9 F_180 ( void )
{
int V_16 ;
if ( V_360 ) {
struct V_234 * V_235 =
F_121 ( & V_360 -> V_41 ) ;
int V_361 = V_235 -> V_362 ;
struct V_1 * V_4 = & V_352 [ V_361 ] ;
V_4 -> V_276 = 0 ;
V_4 -> V_3 . line = V_361 ;
F_181 ( V_363 , V_361 , NULL ) ;
V_16 = F_166 ( V_4 , V_360 ) ;
if ( V_16 )
return V_16 ;
F_182 ( & V_364 ) ;
}
return 0 ;
}
static int T_9 F_183 ( void )
{
if ( V_360
&& ! ( V_364 . V_39 & V_365 ) )
F_182 ( & V_364 ) ;
return 0 ;
}
static inline bool F_184 ( struct V_2 * V_4 )
{
return V_4 -> V_366 && V_4 -> V_366 -> V_353 == V_4 -> line ;
}
static inline bool F_184 ( struct V_2 * V_4 )
{
return false ;
}
static bool F_185 ( void )
{
#ifdef F_186
return F_187 () ;
#else
return false ;
#endif
}
static int F_188 ( struct V_229 * V_230 ,
T_10 V_114 )
{
struct V_2 * V_4 = F_189 ( V_230 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_184 ( V_4 ) && V_367 ) {
while ( ! ( F_3 ( V_4 , V_17 ) &
V_42 ) )
F_164 () ;
}
V_10 -> V_368 = F_190 ( & V_230 -> V_41 ) ;
if ( F_185 () ) {
unsigned long V_39 ;
F_47 ( & V_10 -> V_193 , V_39 ) ;
V_10 -> V_195 = true ;
F_52 ( & V_10 -> V_193 , V_39 ) ;
F_191 ( & V_230 -> V_41 , 0 ) ;
}
F_192 ( & V_369 , V_4 ) ;
return 0 ;
}
static int F_193 ( struct V_229 * V_230 )
{
struct V_2 * V_4 = F_189 ( V_230 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned long V_39 ;
F_47 ( & V_10 -> V_193 , V_39 ) ;
if ( V_10 -> V_185 ) {
F_92 ( V_4 , V_10 -> V_185 ) ;
F_94 ( V_4 , V_10 -> V_185 ,
V_10 -> V_196 ) ;
F_93 ( V_4 , V_10 -> V_185 ) ;
V_10 -> V_185 = 0 ;
}
V_10 -> V_195 = false ;
F_52 ( & V_10 -> V_193 , V_39 ) ;
F_194 ( & V_369 , V_4 ) ;
F_191 ( & V_230 -> V_41 , V_10 -> V_368 ) ;
return 0 ;
}
static int F_195 ( struct V_1 * V_370 , struct V_371 * V_41 )
{
enum V_248 V_213 ;
struct V_372 * V_373 ;
V_370 -> V_18 = F_196 ( V_41 , 0 ) ;
if ( F_169 ( V_370 -> V_18 ) )
return F_170 ( V_370 -> V_18 ) ;
for ( V_213 = 0 ; V_213 < V_249 ; V_213 ++ ) {
V_373 = F_18 ( V_370 -> V_18 , V_213 ) ;
if ( V_373 && ( F_197 ( V_373 ) == V_374 ) )
V_370 -> V_83 [ V_213 ] = F_198 ( V_373 ) ;
else
V_370 -> V_83 [ V_213 ] = - V_128 ;
}
return 0 ;
}
static void F_199 ( struct V_1 * V_4 ,
struct V_229 * V_230 )
{
V_4 -> V_140 = 0 ;
V_4 -> V_267 = 0 ;
V_4 -> V_266 = 0 ;
if ( F_200 ( V_230 -> V_41 . V_233 ,
L_32 ,
& V_4 -> V_140 ) )
return;
if ( ! V_4 -> V_140 )
return;
if ( V_4 -> V_140 < V_375 ) {
V_4 -> V_140 = 0 ;
F_62 ( & V_230 -> V_41 , L_33 ) ;
return;
}
V_4 -> V_266 = F_201 ( int , V_4 -> V_140 >> 1 ,
V_4 -> V_140 - V_376 ) ;
V_4 -> V_267 = F_201 ( int , V_4 -> V_140 >> 2 ,
V_4 -> V_140 - V_377 ) ;
F_69 ( & V_230 -> V_41 , L_34 ,
V_4 -> V_140 ) ;
F_20 ( & V_230 -> V_41 , L_35 ,
V_4 -> V_266 ) ;
F_20 ( & V_230 -> V_41 , L_36 ,
V_4 -> V_267 ) ;
}
static int F_202 ( struct V_229 * V_230 )
{
struct V_1 * V_4 ;
struct V_231 * V_232 = V_230 -> V_41 . V_233 ;
struct V_234 * V_235 = F_121 ( & V_230 -> V_41 ) ;
void * V_182 ;
int V_16 = - V_359 ;
bool V_378 ;
F_203 ( V_100 & ( V_100 - 1 ) ) ;
if ( V_232 )
V_16 = F_204 ( V_232 , L_37 ) ;
else
if ( V_235 )
V_16 = V_235 -> V_362 ;
if ( V_16 < 0 )
V_16 = F_205 ( V_379 , V_380 ) ;
if ( V_16 >= V_380 ) {
V_16 = - V_359 ;
goto V_250;
}
if ( F_206 ( V_16 , V_379 ) ) {
V_16 = - V_330 ;
goto V_250;
}
V_4 = & V_352 [ V_16 ] ;
V_4 -> V_276 = 0 ;
V_4 -> V_3 . line = V_16 ;
F_199 ( V_4 , V_230 ) ;
F_71 ( & V_4 -> V_193 ) ;
V_16 = F_195 ( V_4 , & V_230 -> V_41 ) ;
if ( V_16 < 0 ) {
F_62 ( & V_230 -> V_41 , L_38 ) ;
goto V_381;
}
V_16 = F_166 ( V_4 , V_230 ) ;
if ( V_16 )
goto V_381;
if ( ! F_11 ( & V_4 -> V_3 ) ) {
V_16 = - V_222 ;
V_182 = F_115 ( sizeof( struct V_96 )
* V_100 , V_221 ) ;
if ( ! V_182 )
goto V_382;
V_4 -> V_95 . V_101 = V_182 ;
}
V_378 = V_4 -> V_3 . V_38 . V_39 & V_40 ;
V_16 = F_207 ( & V_369 , & V_4 -> V_3 ) ;
if ( V_16 )
goto V_383;
#ifdef F_208
if ( F_184 ( & V_4 -> V_3 )
&& V_384 -> V_39 & V_365 ) {
F_147 ( V_4 -> V_275 ) ;
}
#endif
F_209 ( & V_230 -> V_41 , 1 ) ;
F_210 ( V_230 , V_4 ) ;
F_146 ( V_4 -> V_275 ) ;
if ( V_378 ) {
F_5 ( & V_4 -> V_3 , V_36 ,
V_318 ) ;
F_5 ( & V_4 -> V_3 , V_62 , V_56 ) ;
}
F_126 ( & V_4 -> V_3 ) ;
F_147 ( V_4 -> V_275 ) ;
return 0 ;
V_383:
F_109 ( V_4 -> V_95 . V_101 ) ;
V_4 -> V_95 . V_101 = NULL ;
V_382:
if ( ! F_184 ( & V_4 -> V_3 ) ) {
F_171 ( V_4 -> V_275 ) ;
V_4 -> V_275 = NULL ;
}
V_381:
F_211 ( V_4 -> V_3 . line , V_379 ) ;
V_250:
return V_16 ;
}
static int F_212 ( struct V_229 * V_230 )
{
struct V_2 * V_4 = F_189 ( V_230 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_16 = 0 ;
F_144 ( & V_10 -> V_112 ) ;
F_209 ( & V_230 -> V_41 , 0 ) ;
V_16 = F_213 ( & V_369 , V_4 ) ;
F_109 ( V_10 -> V_95 . V_101 ) ;
F_211 ( V_4 -> line , V_379 ) ;
F_171 ( V_10 -> V_275 ) ;
return V_16 ;
}
static int T_9 F_214 ( void )
{
int V_16 ;
V_16 = F_215 ( & V_369 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_216 ( & V_385 ) ;
if ( V_16 )
F_217 ( & V_369 ) ;
return V_16 ;
}
static void T_11 F_218 ( void )
{
F_219 ( & V_385 ) ;
F_217 ( & V_369 ) ;
}
