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
static void F_16 ( struct V_1 * V_10 ,
struct V_16 * V_17 )
{
if ( ! F_17 ( & V_10 -> V_18 ) )
F_18 ( V_17 ) ;
}
static unsigned int F_19 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_19 , V_20 = 0 ;
V_19 = F_3 ( V_4 , V_21 ) ;
F_20 ( V_10 -> V_22 , & V_20 ) ;
if ( ! F_21 ( F_22 ( V_10 -> V_22 ,
V_23 ) ) ) {
if ( V_20 & V_24 )
V_19 &= ~ V_25 ;
else
V_19 |= V_25 ;
}
if ( ! F_21 ( F_22 ( V_10 -> V_22 ,
V_26 ) ) ) {
if ( V_20 & V_27 )
V_19 &= ~ V_28 ;
else
V_19 |= V_28 ;
}
if ( ! F_21 ( F_22 ( V_10 -> V_22 ,
V_29 ) ) ) {
if ( V_20 & V_30 )
V_19 &= ~ V_31 ;
else
V_19 |= V_31 ;
}
if ( ! F_21 ( F_22 ( V_10 -> V_22 ,
V_32 ) ) ) {
if ( V_20 & V_33 )
V_19 &= ~ V_34 ;
else
V_19 |= V_34 ;
}
return V_19 ;
}
static int F_23 ( struct V_2 * V_4 ,
struct V_35 * V_36 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_37 ;
F_5 ( V_4 , V_38 , V_10 -> V_39 ) ;
V_37 = F_3 ( V_4 , V_40 ) ;
V_37 &= ~ V_41 ;
V_4 -> V_42 = * V_36 ;
if ( V_36 -> V_43 & V_44 ) {
F_24 ( V_4 -> V_45 , L_1 ) ;
V_10 -> V_39 = V_46 ;
F_5 ( V_4 , V_47 ,
V_36 -> V_48 ) ;
V_37 |= V_49 ;
} else {
F_24 ( V_4 -> V_45 , L_2 ) ;
if ( F_12 ( V_4 ) )
V_10 -> V_39 = V_50 |
V_51 ;
else
V_10 -> V_39 = V_52 ;
}
F_5 ( V_4 , V_40 , V_37 ) ;
F_5 ( V_4 , V_53 , V_10 -> V_39 ) ;
return 0 ;
}
static T_3 F_25 ( struct V_2 * V_4 )
{
return ( F_3 ( V_4 , V_21 ) & V_46 ) ?
V_54 :
0 ;
}
static void F_26 ( struct V_2 * V_4 , T_3 V_55 )
{
unsigned int V_56 = 0 ;
unsigned int V_37 = F_3 ( V_4 , V_40 ) ;
unsigned int V_57 , V_58 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( V_4 -> V_42 . V_43 & V_44 ) {
F_5 ( V_4 , V_47 ,
V_4 -> V_42 . V_48 ) ;
V_37 &= ~ V_41 ;
V_37 |= V_49 ;
}
if ( ( V_37 & V_41 ) == V_59 ) {
V_57 = V_60 ;
V_58 = V_61 ;
} else {
V_57 = V_61 ;
V_58 = V_60 ;
}
if ( V_55 & V_62 )
V_56 |= V_58 ;
else
V_56 |= V_57 ;
if ( V_55 & V_63 )
V_56 |= V_64 ;
else
V_56 |= V_65 ;
F_5 ( V_4 , V_66 , V_56 ) ;
F_27 ( V_10 -> V_22 , V_55 ) ;
V_37 &= ~ V_67 ;
if ( V_55 & V_68 )
V_37 |= V_69 ;
else
V_37 |= V_70 ;
F_5 ( V_4 , V_40 , V_37 ) ;
}
static T_3 F_28 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_20 = 0 , V_19 ;
V_19 = F_3 ( V_4 , V_21 ) ;
if ( ! ( V_19 & V_34 ) )
V_20 |= V_33 ;
if ( ! ( V_19 & V_25 ) )
V_20 |= V_24 ;
if ( ! ( V_19 & V_28 ) )
V_20 |= V_27 ;
if ( ! ( V_19 & V_31 ) )
V_20 |= V_30 ;
return F_20 ( V_10 -> V_22 , & V_20 ) ;
}
static void F_29 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_12 ( V_4 ) ) {
F_5 ( V_4 , V_71 , V_72 ) ;
}
F_5 ( V_4 , V_38 , V_10 -> V_39 ) ;
if ( ( V_4 -> V_42 . V_43 & V_44 ) &&
! ( V_4 -> V_42 . V_43 & V_73 ) )
F_30 ( V_4 ) ;
}
static void F_31 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_12 ( V_4 ) && ( F_3 ( V_4 , V_74 )
& V_75 ) )
return;
if ( F_12 ( V_4 ) || F_13 ( V_4 ) )
if ( ( V_4 -> V_42 . V_43 & V_44 ) &&
! ( V_4 -> V_42 . V_43 & V_73 ) )
F_32 ( V_4 ) ;
if ( F_12 ( V_4 ) )
F_5 ( V_4 , V_71 , V_75 ) ;
F_5 ( V_4 , V_53 , V_10 -> V_39 ) ;
}
static void F_30 ( struct V_2 * V_4 )
{
F_5 ( V_4 , V_66 , V_76 ) ;
F_5 ( V_4 , V_66 , V_77 ) ;
if ( F_11 ( V_4 ) ) {
F_5 ( V_4 , V_53 ,
V_78 | V_79 |
V_4 -> V_80 ) ;
F_5 ( V_4 , V_71 , V_81 ) ;
} else {
F_5 ( V_4 , V_53 , V_82 ) ;
}
}
static void F_32 ( struct V_2 * V_4 )
{
F_5 ( V_4 , V_66 , V_83 ) ;
if ( F_11 ( V_4 ) ) {
F_5 ( V_4 , V_71 , V_84 ) ;
F_5 ( V_4 , V_38 ,
V_78 | V_79 |
V_4 -> V_80 ) ;
} else {
F_5 ( V_4 , V_38 , V_82 ) ;
}
}
static void F_33 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
T_4 V_85 = 0 ;
if ( V_10 -> V_86 )
return;
V_10 -> V_86 = true ;
if ( ! F_22 ( V_10 -> V_22 , V_23 ) )
V_85 |= V_87 ;
if ( ! F_22 ( V_10 -> V_22 , V_26 ) )
V_85 |= V_88 ;
if ( ! F_22 ( V_10 -> V_22 , V_29 ) )
V_85 |= V_89 ;
if ( ! F_22 ( V_10 -> V_22 , V_32 ) )
V_85 |= V_90 ;
F_5 ( V_4 , V_53 , V_85 ) ;
F_34 ( V_10 -> V_22 ) ;
}
static void F_35 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
T_4 V_91 = 0 ;
if ( ! V_10 -> V_86 )
return;
V_10 -> V_86 = false ;
F_36 ( V_10 -> V_22 ) ;
if ( ! F_22 ( V_10 -> V_22 , V_23 ) )
V_91 |= V_87 ;
if ( ! F_22 ( V_10 -> V_22 , V_26 ) )
V_91 |= V_88 ;
if ( ! F_22 ( V_10 -> V_22 , V_29 ) )
V_91 |= V_89 ;
if ( ! F_22 ( V_10 -> V_22 , V_32 ) )
V_91 |= V_90 ;
F_5 ( V_4 , V_38 , V_91 ) ;
}
static void F_37 ( struct V_2 * V_4 , int V_92 )
{
if ( V_92 != 0 )
F_5 ( V_4 , V_66 , V_93 ) ;
else
F_5 ( V_4 , V_66 , V_94 ) ;
}
static void
F_38 ( struct V_2 * V_4 , unsigned int V_19 ,
unsigned int V_95 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_96 * V_97 = & V_10 -> V_98 ;
struct V_99 * V_100 ;
if ( ! F_39 ( V_97 -> V_101 , V_97 -> V_102 , V_103 ) )
return;
V_100 = & ( (struct V_99 * ) V_97 -> V_104 ) [ V_97 -> V_101 ] ;
V_100 -> V_19 = V_19 ;
V_100 -> V_95 = V_95 ;
F_40 () ;
V_97 -> V_101 = ( V_97 -> V_101 + 1 ) & ( V_103 - 1 ) ;
}
static void F_41 ( struct V_2 * V_4 , unsigned int V_19 )
{
F_5 ( V_4 , V_66 , V_76 ) ;
if ( V_19 & V_105 ) {
V_19 &= ~ ( V_106 | V_107 ) ;
V_4 -> V_108 . V_109 ++ ;
}
if ( V_19 & V_106 )
V_4 -> V_108 . V_110 ++ ;
if ( V_19 & V_107 )
V_4 -> V_108 . V_111 ++ ;
if ( V_19 & V_112 )
V_4 -> V_108 . V_113 ++ ;
}
static void F_42 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_19 , V_95 ;
V_19 = F_3 ( V_4 , V_21 ) ;
while ( V_19 & V_82 ) {
V_95 = F_7 ( V_4 ) ;
if ( F_43 ( V_19 & ( V_106 | V_107
| V_112 | V_105 )
|| V_10 -> V_114 ) ) {
F_5 ( V_4 , V_66 , V_76 ) ;
if ( V_19 & V_105
&& ! V_10 -> V_114 ) {
V_10 -> V_114 = 1 ;
F_5 ( V_4 , V_53 ,
V_105 ) ;
} else {
F_5 ( V_4 , V_38 ,
V_105 ) ;
V_19 &= ~ V_105 ;
V_10 -> V_114 = 0 ;
}
}
F_38 ( V_4 , V_19 , V_95 ) ;
V_19 = F_3 ( V_4 , V_21 ) ;
}
F_16 ( V_10 , & V_10 -> V_115 ) ;
}
static void F_44 ( struct V_2 * V_4 )
{
struct V_96 * V_116 = & V_4 -> V_117 -> V_116 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( V_4 -> V_118 &&
( F_3 ( V_4 , V_21 ) & V_10 -> V_39 ) ) {
F_8 ( V_4 , V_4 -> V_118 ) ;
V_4 -> V_108 . V_119 ++ ;
V_4 -> V_118 = 0 ;
}
if ( F_45 ( V_116 ) || F_46 ( V_4 ) )
return;
while ( F_3 ( V_4 , V_21 ) &
V_10 -> V_39 ) {
F_8 ( V_4 , V_116 -> V_104 [ V_116 -> V_102 ] ) ;
V_116 -> V_102 = ( V_116 -> V_102 + 1 ) & ( V_120 - 1 ) ;
V_4 -> V_108 . V_119 ++ ;
if ( F_45 ( V_116 ) )
break;
}
if ( F_47 ( V_116 ) < V_121 )
F_48 ( V_4 ) ;
if ( ! F_45 ( V_116 ) )
F_5 ( V_4 , V_53 ,
V_10 -> V_39 ) ;
}
static void F_49 ( void * V_122 )
{
struct V_1 * V_10 = V_122 ;
struct V_2 * V_4 = & V_10 -> V_3 ;
struct V_96 * V_116 = & V_4 -> V_117 -> V_116 ;
struct V_123 * V_124 = V_10 -> V_125 ;
unsigned long V_43 ;
F_50 ( & V_4 -> V_126 , V_43 ) ;
if ( V_124 )
F_51 ( V_124 ) ;
V_116 -> V_102 += V_10 -> V_127 ;
V_116 -> V_102 &= V_120 - 1 ;
V_4 -> V_108 . V_119 += V_10 -> V_127 ;
F_52 ( & V_10 -> V_128 ) ;
F_53 ( V_10 -> V_129 ) ;
V_10 -> V_130 = - V_131 ;
V_10 -> V_129 = NULL ;
F_54 ( & V_10 -> V_128 ) ;
if ( F_47 ( V_116 ) < V_121 )
F_48 ( V_4 ) ;
if ( ! F_45 ( V_116 ) )
F_16 ( V_10 , & V_10 -> V_132 ) ;
F_55 ( & V_4 -> V_126 , V_43 ) ;
}
static void F_56 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_123 * V_124 = V_10 -> V_125 ;
if ( V_124 ) {
F_51 ( V_124 ) ;
F_57 ( V_124 ) ;
F_58 ( V_4 -> V_45 , & V_10 -> V_133 , 1 ,
V_134 ) ;
}
V_10 -> V_129 = NULL ;
V_10 -> V_125 = NULL ;
V_10 -> V_130 = - V_131 ;
}
static void F_59 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_96 * V_116 = & V_4 -> V_117 -> V_116 ;
struct V_123 * V_124 = V_10 -> V_125 ;
struct V_135 * V_136 ;
struct V_137 V_138 [ 2 ] , * V_139 , * V_133 = & V_10 -> V_133 ;
unsigned int V_127 , V_140 , V_141 , V_142 ;
T_5 V_143 ;
if ( V_10 -> V_129 != NULL )
return;
if ( ! F_45 ( V_116 ) && ! F_46 ( V_4 ) ) {
V_127 = F_60 ( V_116 -> V_101 ,
V_116 -> V_102 ,
V_120 ) ;
if ( V_10 -> V_15 ) {
V_140 = ( V_127 & ~ 0x3 ) ;
V_141 = ( V_127 & 0x3 ) ;
} else {
V_140 = 0 ;
V_141 = V_127 ;
}
F_61 ( V_138 , 2 ) ;
V_142 = 0 ;
V_143 = F_62 ( V_133 ) + V_116 -> V_102 ;
if ( V_140 ) {
V_139 = & V_138 [ V_142 ++ ] ;
F_62 ( V_139 ) = V_143 ;
F_63 ( V_139 ) = V_140 ;
V_143 += V_140 ;
}
if ( V_141 ) {
V_139 = & V_138 [ V_142 ++ ] ;
F_62 ( V_139 ) = V_143 ;
F_63 ( V_139 ) = V_141 ;
}
V_10 -> V_127 = V_127 ;
V_136 = F_64 ( V_124 ,
V_138 ,
V_142 ,
V_144 ,
V_145 |
V_146 ) ;
if ( ! V_136 ) {
F_65 ( V_4 -> V_45 , L_3 ) ;
return;
}
F_66 ( V_4 -> V_45 , V_133 , 1 , V_134 ) ;
V_10 -> V_129 = V_136 ;
V_136 -> V_147 = F_49 ;
V_136 -> V_148 = V_10 ;
V_10 -> V_130 = F_67 ( V_136 ) ;
} else {
if ( V_4 -> V_42 . V_43 & V_44 ) {
F_30 ( V_4 ) ;
}
}
if ( F_47 ( V_116 ) < V_121 )
F_48 ( V_4 ) ;
}
static int F_68 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
T_6 V_149 ;
struct V_150 V_151 ;
int V_20 , V_152 ;
F_69 ( V_149 ) ;
F_70 ( V_153 , V_149 ) ;
V_10 -> V_125 = F_71 ( V_4 -> V_45 , L_4 ) ;
if ( V_10 -> V_125 == NULL )
goto V_154;
F_72 ( V_4 -> V_45 , L_5 ,
F_73 ( V_10 -> V_125 ) ) ;
F_74 ( & V_10 -> V_128 ) ;
F_61 ( & V_10 -> V_133 , 1 ) ;
F_75 ( ! F_76 ( V_4 -> V_117 -> V_116 . V_104 ) ) ;
F_77 ( & V_10 -> V_133 ,
F_78 ( V_4 -> V_117 -> V_116 . V_104 ) ,
V_120 ,
( unsigned long ) V_4 -> V_117 -> V_116 . V_104 & ~ V_155 ) ;
V_152 = F_79 ( V_4 -> V_45 ,
& V_10 -> V_133 ,
1 ,
V_134 ) ;
if ( ! V_152 ) {
F_24 ( V_4 -> V_45 , L_6 ) ;
goto V_154;
} else {
F_24 ( V_4 -> V_45 , L_7 , V_156 ,
F_63 ( & V_10 -> V_133 ) ,
V_4 -> V_117 -> V_116 . V_104 ,
& F_62 ( & V_10 -> V_133 ) ) ;
}
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
V_151 . V_157 = V_144 ;
V_151 . V_158 = ( V_10 -> V_15 ) ?
V_159 :
V_160 ;
V_151 . V_161 = V_4 -> V_162 + V_9 ;
V_151 . V_163 = 1 ;
V_20 = F_80 ( V_10 -> V_125 ,
& V_151 ) ;
if ( V_20 ) {
F_65 ( V_4 -> V_45 , L_8 ) ;
goto V_154;
}
return 0 ;
V_154:
F_65 ( V_4 -> V_45 , L_9 ) ;
V_10 -> V_13 = 0 ;
if ( V_10 -> V_125 )
F_56 ( V_4 ) ;
return - V_131 ;
}
static void F_81 ( void * V_122 )
{
struct V_2 * V_4 = V_122 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_16 ( V_10 , & V_10 -> V_115 ) ;
}
static void F_82 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_123 * V_124 = V_10 -> V_164 ;
if ( V_124 ) {
F_51 ( V_124 ) ;
F_57 ( V_124 ) ;
F_58 ( V_4 -> V_45 , & V_10 -> V_165 , 1 ,
V_166 ) ;
}
V_10 -> V_167 = NULL ;
V_10 -> V_164 = NULL ;
V_10 -> V_168 = - V_131 ;
}
static void F_83 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_169 * V_170 = & V_4 -> V_117 -> V_4 ;
struct V_96 * V_97 = & V_10 -> V_98 ;
struct V_123 * V_124 = V_10 -> V_164 ;
struct V_171 V_117 ;
enum V_172 V_173 ;
T_7 V_174 ;
F_5 ( V_4 , V_66 , V_175 ) ;
V_173 = F_84 ( V_124 ,
V_10 -> V_168 ,
& V_117 ) ;
if ( V_173 == V_176 ) {
F_24 ( V_4 -> V_45 , L_10 ) ;
F_5 ( V_4 , V_53 , V_79 ) ;
F_16 ( V_10 , & V_10 -> V_115 ) ;
return;
}
F_85 ( V_4 -> V_45 ,
& V_10 -> V_165 ,
1 ,
V_166 ) ;
V_97 -> V_101 = F_63 ( & V_10 -> V_165 ) - V_117 . V_177 ;
F_75 ( V_97 -> V_101 > F_63 ( & V_10 -> V_165 ) ) ;
if ( V_97 -> V_101 < V_97 -> V_102 ) {
V_174 = F_63 ( & V_10 -> V_165 ) - V_97 -> V_102 ;
F_86 ( V_170 , V_97 -> V_104 + V_97 -> V_102 , V_174 ) ;
V_97 -> V_102 = 0 ;
V_4 -> V_108 . V_178 += V_174 ;
}
if ( V_97 -> V_102 < V_97 -> V_101 ) {
V_174 = V_97 -> V_101 - V_97 -> V_102 ;
F_86 ( V_170 , V_97 -> V_104 + V_97 -> V_102 , V_174 ) ;
if ( V_97 -> V_101 >= F_63 ( & V_10 -> V_165 ) )
V_97 -> V_101 = 0 ;
V_97 -> V_102 = V_97 -> V_101 ;
V_4 -> V_108 . V_178 += V_174 ;
}
F_66 ( V_4 -> V_45 ,
& V_10 -> V_165 ,
1 ,
V_166 ) ;
F_87 ( & V_4 -> V_126 ) ;
F_88 ( V_170 ) ;
F_89 ( & V_4 -> V_126 ) ;
F_5 ( V_4 , V_53 , V_79 ) ;
}
static int F_90 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_135 * V_136 ;
T_6 V_149 ;
struct V_150 V_151 ;
struct V_96 * V_97 ;
int V_20 , V_152 ;
V_97 = & V_10 -> V_98 ;
F_69 ( V_149 ) ;
F_70 ( V_179 , V_149 ) ;
V_10 -> V_164 = F_71 ( V_4 -> V_45 , L_11 ) ;
if ( V_10 -> V_164 == NULL )
goto V_154;
F_72 ( V_4 -> V_45 , L_12 ,
F_73 ( V_10 -> V_164 ) ) ;
F_74 ( & V_10 -> V_180 ) ;
F_61 ( & V_10 -> V_165 , 1 ) ;
F_75 ( ! F_76 ( V_97 -> V_104 ) ) ;
F_77 ( & V_10 -> V_165 ,
F_78 ( V_97 -> V_104 ) ,
sizeof( struct V_99 ) * V_103 ,
( unsigned long ) V_97 -> V_104 & ~ V_155 ) ;
V_152 = F_79 ( V_4 -> V_45 ,
& V_10 -> V_165 ,
1 ,
V_166 ) ;
if ( ! V_152 ) {
F_24 ( V_4 -> V_45 , L_6 ) ;
goto V_154;
} else {
F_24 ( V_4 -> V_45 , L_7 , V_156 ,
F_63 ( & V_10 -> V_165 ) ,
V_97 -> V_104 ,
& F_62 ( & V_10 -> V_165 ) ) ;
}
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
V_151 . V_157 = V_181 ;
V_151 . V_182 = V_160 ;
V_151 . V_183 = V_4 -> V_162 + V_8 ;
V_151 . V_184 = 1 ;
V_20 = F_80 ( V_10 -> V_164 ,
& V_151 ) ;
if ( V_20 ) {
F_65 ( V_4 -> V_45 , L_13 ) ;
goto V_154;
}
V_136 = F_91 ( V_10 -> V_164 ,
F_62 ( & V_10 -> V_165 ) ,
F_63 ( & V_10 -> V_165 ) ,
F_63 ( & V_10 -> V_165 ) / 2 ,
V_181 ,
V_145 ) ;
V_136 -> V_147 = F_81 ;
V_136 -> V_148 = V_4 ;
V_10 -> V_167 = V_136 ;
V_10 -> V_168 = F_67 ( V_136 ) ;
return 0 ;
V_154:
F_65 ( V_4 -> V_45 , L_14 ) ;
V_10 -> V_14 = 0 ;
if ( V_10 -> V_164 )
F_82 ( V_4 ) ;
return - V_131 ;
}
static void F_92 ( unsigned long V_185 )
{
struct V_2 * V_4 = ( void * ) V_185 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( ! F_17 ( & V_10 -> V_18 ) ) {
F_18 ( & V_10 -> V_115 ) ;
F_93 ( & V_10 -> V_186 ,
V_187 + F_94 ( V_4 ) ) ;
}
}
static void
F_95 ( struct V_2 * V_4 , unsigned int V_188 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_11 ( V_4 ) ) {
if ( V_188 & ( V_78 | V_79 ) ) {
F_5 ( V_4 , V_38 ,
( V_78 | V_79 ) ) ;
F_16 ( V_10 ,
& V_10 -> V_115 ) ;
}
if ( V_188 & ( V_105 | V_112 |
V_107 | V_106 ) )
F_41 ( V_4 , V_188 ) ;
}
if ( F_14 ( V_4 ) ) {
if ( V_188 & V_79 ) {
F_5 ( V_4 , V_38 ,
V_79 ) ;
F_16 ( V_10 ,
& V_10 -> V_115 ) ;
}
}
if ( V_188 & V_82 )
F_42 ( V_4 ) ;
else if ( V_188 & V_105 ) {
F_5 ( V_4 , V_66 , V_76 ) ;
F_5 ( V_4 , V_38 , V_105 ) ;
V_10 -> V_114 = 0 ;
}
}
static void
F_96 ( struct V_2 * V_4 , unsigned int V_188 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( V_188 & V_10 -> V_39 ) {
F_5 ( V_4 , V_38 ,
V_10 -> V_39 ) ;
F_16 ( V_10 , & V_10 -> V_132 ) ;
}
}
static void
F_97 ( struct V_2 * V_4 , unsigned int V_188 ,
unsigned int V_19 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_189 ;
if ( V_188 & ( V_89 | V_88 | V_90
| V_87 ) ) {
V_189 = V_19 ^ V_10 -> V_190 ;
V_10 -> V_190 = V_19 ;
if ( V_189 & ( V_31 | V_28
| V_34 | V_25 ) ) {
if ( V_189 & V_31 )
V_4 -> V_108 . V_191 ++ ;
if ( V_189 & V_28 )
V_4 -> V_108 . V_192 ++ ;
if ( V_189 & V_34 )
F_98 ( V_4 , ! ( V_19 & V_34 ) ) ;
if ( V_189 & V_25 )
F_99 ( V_4 , ! ( V_19 & V_25 ) ) ;
F_100 ( & V_4 -> V_117 -> V_4 . V_193 ) ;
}
}
}
static T_8 F_101 ( int V_194 , void * V_195 )
{
struct V_2 * V_4 = V_195 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_19 , V_188 , V_149 , V_196 = 0 ;
F_89 ( & V_10 -> V_197 ) ;
do {
V_19 = F_19 ( V_4 ) ;
V_149 = F_3 ( V_4 , V_198 ) ;
V_188 = V_19 & V_149 ;
if ( ! V_188 )
break;
if ( V_10 -> V_199 ) {
V_10 -> V_188 |= V_188 ;
V_10 -> V_200 = V_19 ;
F_5 ( V_4 , V_38 , V_149 ) ;
F_102 () ;
break;
}
F_95 ( V_4 , V_188 ) ;
F_97 ( V_4 , V_188 , V_19 ) ;
F_96 ( V_4 , V_188 ) ;
} while ( V_196 ++ < V_201 );
F_87 ( & V_10 -> V_197 ) ;
return V_196 ? V_202 : V_203 ;
}
static void F_103 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_204 * V_205 = & V_10 -> V_206 ;
F_104 ( V_4 -> V_45 ,
V_205 -> V_207 ,
V_205 -> V_208 ,
V_134 ) ;
}
static void F_105 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_96 * V_116 = & V_4 -> V_117 -> V_116 ;
struct V_204 * V_205 = & V_10 -> V_206 ;
int V_174 ;
if ( F_3 ( V_4 , V_209 ) )
return;
V_116 -> V_102 += V_205 -> V_210 ;
V_116 -> V_102 &= V_120 - 1 ;
V_4 -> V_108 . V_119 += V_205 -> V_210 ;
V_205 -> V_210 = 0 ;
F_5 ( V_4 , V_71 , V_72 ) ;
if ( ! F_45 ( V_116 ) && ! F_46 ( V_4 ) ) {
F_106 ( V_4 -> V_45 ,
V_205 -> V_207 ,
V_205 -> V_208 ,
V_134 ) ;
V_174 = F_60 ( V_116 -> V_101 , V_116 -> V_102 , V_120 ) ;
V_205 -> V_210 = V_174 ;
F_5 ( V_4 , V_211 ,
V_205 -> V_207 + V_116 -> V_102 ) ;
F_5 ( V_4 , V_209 , V_174 ) ;
F_5 ( V_4 , V_71 , V_75 ) ;
F_5 ( V_4 , V_53 ,
V_10 -> V_39 ) ;
} else {
if ( ( V_4 -> V_42 . V_43 & V_44 ) &&
! ( V_4 -> V_42 . V_43 & V_73 ) ) {
F_30 ( V_4 ) ;
}
}
if ( F_47 ( V_116 ) < V_121 )
F_48 ( V_4 ) ;
}
static int F_107 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_204 * V_205 = & V_10 -> V_206 ;
struct V_96 * V_116 = & V_4 -> V_117 -> V_116 ;
V_205 -> V_104 = V_116 -> V_104 ;
V_205 -> V_207 = F_108 ( V_4 -> V_45 ,
V_205 -> V_104 ,
V_120 ,
V_134 ) ;
V_205 -> V_208 = V_120 ;
V_205 -> V_210 = 0 ;
return 0 ;
}
static void F_109 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_96 * V_97 = & V_10 -> V_98 ;
unsigned int V_212 ;
unsigned int V_19 ;
while ( V_97 -> V_101 != V_97 -> V_102 ) {
struct V_99 V_100 ;
F_110 () ;
V_100 = ( (struct V_99 * ) V_97 -> V_104 ) [ V_97 -> V_102 ] ;
V_97 -> V_102 = ( V_97 -> V_102 + 1 ) & ( V_103 - 1 ) ;
V_4 -> V_108 . V_178 ++ ;
V_19 = V_100 . V_19 ;
V_212 = V_213 ;
if ( F_43 ( V_19 & ( V_106 | V_107
| V_112 | V_105 ) ) ) {
if ( V_19 & V_105 ) {
V_19 &= ~ ( V_106 | V_107 ) ;
V_4 -> V_108 . V_109 ++ ;
if ( F_111 ( V_4 ) )
continue;
}
if ( V_19 & V_106 )
V_4 -> V_108 . V_110 ++ ;
if ( V_19 & V_107 )
V_4 -> V_108 . V_111 ++ ;
if ( V_19 & V_112 )
V_4 -> V_108 . V_113 ++ ;
V_19 &= V_4 -> V_80 ;
if ( V_19 & V_105 )
V_212 = V_214 ;
else if ( V_19 & V_106 )
V_212 = V_215 ;
else if ( V_19 & V_107 )
V_212 = V_216 ;
}
if ( F_112 ( V_4 , V_100 . V_95 ) )
continue;
F_113 ( V_4 , V_19 , V_112 , V_100 . V_95 , V_212 ) ;
}
F_87 ( & V_4 -> V_126 ) ;
F_88 ( & V_4 -> V_117 -> V_4 ) ;
F_89 ( & V_4 -> V_126 ) ;
}
static void F_114 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_217 ;
for ( V_217 = 0 ; V_217 < 2 ; V_217 ++ ) {
struct V_204 * V_205 = & V_10 -> V_218 [ V_217 ] ;
F_104 ( V_4 -> V_45 ,
V_205 -> V_207 ,
V_205 -> V_208 ,
V_166 ) ;
F_115 ( V_205 -> V_104 ) ;
}
}
static void F_116 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_169 * V_170 = & V_4 -> V_117 -> V_4 ;
struct V_204 * V_205 ;
int V_219 = V_10 -> V_220 ;
unsigned int V_101 ;
unsigned int V_102 ;
unsigned int V_174 ;
do {
F_5 ( V_4 , V_66 , V_175 ) ;
V_205 = & V_10 -> V_218 [ V_219 ] ;
V_101 = F_3 ( V_4 , V_221 ) - V_205 -> V_207 ;
V_102 = V_205 -> V_210 ;
V_101 = F_117 ( V_101 , V_205 -> V_208 ) ;
if ( F_118 ( V_101 != V_102 ) ) {
F_119 ( V_4 -> V_45 , V_205 -> V_207 ,
V_205 -> V_208 , V_166 ) ;
V_174 = V_101 - V_102 ;
F_86 ( V_170 , V_205 -> V_104 + V_205 -> V_210 ,
V_174 ) ;
F_106 ( V_4 -> V_45 , V_205 -> V_207 ,
V_205 -> V_208 , V_166 ) ;
V_4 -> V_108 . V_178 += V_174 ;
V_205 -> V_210 = V_101 ;
}
if ( V_101 >= V_205 -> V_208 ) {
V_205 -> V_210 = 0 ;
F_5 ( V_4 , V_222 , V_205 -> V_207 ) ;
F_5 ( V_4 , V_223 , V_205 -> V_208 ) ;
V_219 = ! V_219 ;
V_10 -> V_220 = V_219 ;
}
} while ( V_101 >= V_205 -> V_208 );
F_87 ( & V_4 -> V_126 ) ;
F_88 ( V_170 ) ;
F_89 ( & V_4 -> V_126 ) ;
F_5 ( V_4 , V_53 ,
V_78 | V_79 ) ;
}
static int F_120 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_217 ;
for ( V_217 = 0 ; V_217 < 2 ; V_217 ++ ) {
struct V_204 * V_205 = & V_10 -> V_218 [ V_217 ] ;
V_205 -> V_104 = F_121 ( V_224 , V_225 ) ;
if ( V_205 -> V_104 == NULL ) {
if ( V_217 != 0 ) {
F_104 ( V_4 -> V_45 ,
V_10 -> V_218 [ 0 ] . V_207 ,
V_224 ,
V_166 ) ;
F_115 ( V_10 -> V_218 [ 0 ] . V_104 ) ;
}
V_10 -> V_11 = 0 ;
return - V_226 ;
}
V_205 -> V_207 = F_108 ( V_4 -> V_45 ,
V_205 -> V_104 ,
V_224 ,
V_166 ) ;
V_205 -> V_208 = V_224 ;
V_205 -> V_210 = 0 ;
}
V_10 -> V_220 = 0 ;
F_5 ( V_4 , V_221 , V_10 -> V_218 [ 0 ] . V_207 ) ;
F_5 ( V_4 , V_227 , V_224 ) ;
F_5 ( V_4 , V_222 ,
V_10 -> V_218 [ 1 ] . V_207 ) ;
F_5 ( V_4 , V_223 , V_224 ) ;
return 0 ;
}
static void F_122 ( unsigned long V_185 )
{
struct V_2 * V_4 = (struct V_2 * ) V_185 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_89 ( & V_4 -> V_126 ) ;
V_10 -> V_228 ( V_4 ) ;
F_87 ( & V_4 -> V_126 ) ;
}
static void F_123 ( unsigned long V_185 )
{
struct V_2 * V_4 = (struct V_2 * ) V_185 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_89 ( & V_4 -> V_126 ) ;
V_10 -> V_229 ( V_4 ) ;
F_87 ( & V_4 -> V_126 ) ;
}
static void F_124 ( struct V_1 * V_10 ,
struct V_230 * V_231 )
{
struct V_232 * V_233 = V_231 -> V_45 . V_234 ;
struct V_235 * V_236 = F_125 ( & V_231 -> V_45 ) ;
if ( V_233 ) {
if ( F_126 ( V_233 , L_15 ) ) {
if ( F_126 ( V_233 , L_16 ) ) {
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
if ( F_126 ( V_233 , L_17 ) ) {
if ( F_126 ( V_233 , L_16 ) ) {
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
V_10 -> V_11 = V_236 -> V_14 ;
V_10 -> V_12 = V_236 -> V_13 ;
V_10 -> V_14 = false ;
V_10 -> V_13 = false ;
}
}
static void F_127 ( struct V_2 * V_4 ,
struct V_230 * V_231 )
{
struct V_232 * V_233 = V_231 -> V_45 . V_234 ;
struct V_235 * V_236 = F_125 ( & V_231 -> V_45 ) ;
if ( V_233 ) {
struct V_35 * V_36 = & V_4 -> V_42 ;
T_1 V_237 [ 2 ] ;
if ( F_128 ( V_233 , L_18 ,
V_237 , 2 ) == 0 ) {
V_36 -> V_238 = V_237 [ 0 ] ;
V_36 -> V_48 = V_237 [ 1 ] ;
V_36 -> V_43 = 0 ;
}
if ( F_129 ( V_233 , L_19 , NULL ) )
V_36 -> V_43 |= V_73 ;
if ( F_129 ( V_233 , L_20 ,
NULL ) )
V_36 -> V_43 |= V_44 ;
} else {
V_4 -> V_42 = V_236 -> V_42 ;
}
}
static void F_130 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_14 ( V_4 ) ) {
V_10 -> V_239 = & F_90 ;
V_10 -> V_228 = & F_83 ;
V_10 -> V_240 = & F_82 ;
} else if ( F_11 ( V_4 ) ) {
V_10 -> V_239 = & F_120 ;
V_10 -> V_228 = & F_116 ;
V_10 -> V_240 = & F_114 ;
} else {
V_10 -> V_239 = NULL ;
V_10 -> V_228 = & F_109 ;
V_10 -> V_240 = NULL ;
}
if ( F_13 ( V_4 ) ) {
V_10 -> V_241 = & F_68 ;
V_10 -> V_229 = & F_59 ;
V_10 -> V_242 = & F_56 ;
} else if ( F_12 ( V_4 ) ) {
V_10 -> V_241 = & F_107 ;
V_10 -> V_229 = & F_105 ;
V_10 -> V_242 = & F_103 ;
} else {
V_10 -> V_241 = NULL ;
V_10 -> V_229 = & F_44 ;
V_10 -> V_242 = NULL ;
}
}
static void F_131 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_243 = F_3 ( V_4 , V_244 ) ;
T_1 V_245 ;
T_1 V_246 , V_247 , V_248 ;
V_246 = 0x55534152 ;
V_247 = 0x44424755 ;
V_248 = 0x55415254 ;
V_10 -> V_249 = false ;
V_10 -> V_250 = false ;
if ( V_243 == V_248 ) {
F_24 ( V_4 -> V_45 , L_21 ) ;
V_10 -> V_250 = true ;
V_10 -> V_251 = V_252 ;
} else if ( V_243 == V_246 ) {
F_24 ( V_4 -> V_45 , L_22 ) ;
V_10 -> V_249 = true ;
V_10 -> V_250 = true ;
V_10 -> V_251 = V_253 ;
} else if ( V_243 == V_247 ) {
F_24 ( V_4 -> V_45 , L_23 ) ;
} else {
V_245 = F_3 ( V_4 , V_254 ) ;
switch ( V_245 ) {
case 0x302 :
case 0x10213 :
F_24 ( V_4 -> V_45 , L_24 ) ;
V_10 -> V_249 = true ;
V_10 -> V_250 = true ;
V_10 -> V_251 = V_253 ;
break;
case 0x203 :
case 0x10202 :
F_24 ( V_4 -> V_45 , L_25 ) ;
break;
default:
F_65 ( V_4 -> V_45 , L_26 ) ;
}
}
}
static int F_132 ( struct V_2 * V_4 )
{
struct V_230 * V_231 = F_133 ( V_4 -> V_45 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_255 * V_256 = V_4 -> V_117 -> V_4 . V_256 ;
int V_257 ;
F_5 ( V_4 , V_38 , - 1 ) ;
V_10 -> V_86 = false ;
V_257 = F_134 ( V_4 -> V_194 , F_101 ,
V_258 | V_259 ,
V_256 ? V_256 -> V_243 : L_27 , V_4 ) ;
if ( V_257 ) {
F_65 ( V_4 -> V_45 , L_28 ) ;
return V_257 ;
}
F_135 ( & V_10 -> V_18 , 0 ) ;
F_136 ( & V_10 -> V_115 , F_122 ,
( unsigned long ) V_4 ) ;
F_136 ( & V_10 -> V_132 , F_123 ,
( unsigned long ) V_4 ) ;
F_124 ( V_10 , V_231 ) ;
F_130 ( V_4 ) ;
if ( V_10 -> V_239 ) {
V_257 = V_10 -> V_239 ( V_4 ) ;
if ( V_257 < 0 )
F_130 ( V_4 ) ;
}
if ( V_10 -> V_241 ) {
V_257 = V_10 -> V_241 ( V_4 ) ;
if ( V_257 < 0 )
F_130 ( V_4 ) ;
}
if ( V_10 -> V_15 ) {
unsigned int V_260 = V_261 ;
unsigned int V_262 = V_261 ;
unsigned int V_263 ;
F_5 ( V_4 , V_66 ,
V_264 |
V_265 |
V_266 ) ;
if ( F_13 ( V_4 ) )
V_260 = V_267 ;
V_263 = F_137 ( V_260 ) | F_138 ( V_262 ) ;
if ( V_10 -> V_268 &&
V_10 -> V_269 )
V_263 |= V_270 |
F_139 ( V_10 -> V_268 ) |
F_140 ( V_10 -> V_269 ) ;
F_5 ( V_4 , V_271 , V_263 ) ;
}
V_10 -> V_190 = F_19 ( V_4 ) ;
F_5 ( V_4 , V_66 , V_76 | V_272 ) ;
F_5 ( V_4 , V_66 , V_273 | V_77 ) ;
F_141 ( & V_10 -> V_186 ,
F_92 ,
( unsigned long ) V_4 ) ;
if ( F_11 ( V_4 ) ) {
if ( ! V_10 -> V_250 ) {
F_93 ( & V_10 -> V_186 ,
V_187 + F_94 ( V_4 ) ) ;
} else {
F_5 ( V_4 , V_10 -> V_251 ,
V_274 ) ;
F_5 ( V_4 , V_66 , V_175 ) ;
F_5 ( V_4 , V_53 ,
V_78 | V_79 ) ;
}
F_5 ( V_4 , V_71 , V_81 ) ;
} else if ( F_14 ( V_4 ) ) {
if ( ! V_10 -> V_250 ) {
F_93 ( & V_10 -> V_186 ,
V_187 + F_94 ( V_4 ) ) ;
} else {
F_5 ( V_4 , V_10 -> V_251 ,
V_274 ) ;
F_5 ( V_4 , V_66 , V_175 ) ;
F_5 ( V_4 , V_53 ,
V_79 ) ;
}
} else {
F_5 ( V_4 , V_53 , V_82 ) ;
}
return 0 ;
}
static void F_142 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_12 ( V_4 ) ) {
F_5 ( V_4 , V_209 , 0 ) ;
V_10 -> V_206 . V_210 = 0 ;
}
}
static void F_143 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_35 ( V_4 ) ;
F_5 ( V_4 , V_38 , - 1 ) ;
F_144 ( & V_10 -> V_18 ) ;
F_145 ( & V_10 -> V_186 ) ;
F_146 ( V_4 -> V_194 ) ;
F_147 ( & V_10 -> V_115 ) ;
F_147 ( & V_10 -> V_132 ) ;
F_32 ( V_4 ) ;
F_29 ( V_4 ) ;
F_5 ( V_4 , V_66 , V_76 ) ;
if ( V_10 -> V_240 )
V_10 -> V_240 ( V_4 ) ;
if ( V_10 -> V_242 )
V_10 -> V_242 ( V_4 ) ;
V_10 -> V_98 . V_101 = 0 ;
V_10 -> V_98 . V_102 = 0 ;
F_148 ( V_4 -> V_194 , V_4 ) ;
F_142 ( V_4 ) ;
}
static void F_149 ( struct V_2 * V_4 , unsigned int V_117 ,
unsigned int V_275 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
switch ( V_117 ) {
case 0 :
F_150 ( V_10 -> V_276 ) ;
F_5 ( V_4 , V_53 , V_10 -> V_277 ) ;
break;
case 3 :
V_10 -> V_277 = F_3 ( V_4 , V_198 ) ;
F_5 ( V_4 , V_38 , - 1 ) ;
F_151 ( V_10 -> V_276 ) ;
break;
default:
F_65 ( V_4 -> V_45 , L_29 , V_117 ) ;
}
}
static void F_152 ( struct V_2 * V_4 , struct V_278 * V_279 ,
struct V_278 * V_280 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned long V_43 ;
unsigned int V_281 , V_37 , V_282 , V_283 , V_284 , div , V_285 , V_286 = 0 ;
V_37 = V_281 = F_3 ( V_4 , V_40 ) ;
V_37 &= ~ ( V_287 | V_288 | V_289 |
V_290 | V_41 ) ;
V_284 = F_153 ( V_4 , V_279 , V_280 , 0 , V_4 -> V_291 / 16 ) ;
switch ( V_279 -> V_292 & V_293 ) {
case V_294 :
V_37 |= V_295 ;
break;
case V_296 :
V_37 |= V_297 ;
break;
case V_298 :
V_37 |= V_299 ;
break;
default:
V_37 |= V_300 ;
break;
}
if ( V_279 -> V_292 & V_301 )
V_37 |= V_302 ;
if ( V_279 -> V_292 & V_303 ) {
if ( V_279 -> V_292 & V_304 ) {
if ( V_279 -> V_292 & V_305 )
V_37 |= V_306 ;
else
V_37 |= V_307 ;
} else if ( V_279 -> V_292 & V_305 )
V_37 |= V_308 ;
else
V_37 |= V_309 ;
} else
V_37 |= V_310 ;
F_50 ( & V_4 -> V_126 , V_43 ) ;
V_4 -> V_80 = V_112 ;
if ( V_279 -> V_311 & V_312 )
V_4 -> V_80 |= ( V_107 | V_106 ) ;
if ( V_279 -> V_311 & ( V_313 | V_314 | V_315 ) )
V_4 -> V_80 |= V_105 ;
if ( F_11 ( V_4 ) )
F_5 ( V_4 , V_53 , V_4 -> V_80 ) ;
V_4 -> V_316 = 0 ;
if ( V_279 -> V_311 & V_317 )
V_4 -> V_316 |= ( V_107 | V_106 ) ;
if ( V_279 -> V_311 & V_313 ) {
V_4 -> V_316 |= V_105 ;
if ( V_279 -> V_311 & V_317 )
V_4 -> V_316 |= V_112 ;
}
F_154 ( V_4 , V_279 -> V_292 , V_284 ) ;
V_282 = F_3 ( V_4 , V_198 ) ;
F_5 ( V_4 , V_38 , - 1 ) ;
F_5 ( V_4 , V_66 , V_318 | V_83 ) ;
if ( V_4 -> V_42 . V_43 & V_44 ) {
F_5 ( V_4 , V_47 ,
V_4 -> V_42 . V_48 ) ;
V_37 |= V_49 ;
} else if ( V_279 -> V_292 & V_319 ) {
if ( F_15 ( V_4 ) &&
! F_22 ( V_10 -> V_22 , V_23 ) ) {
V_37 |= V_59 ;
} else {
V_37 |= V_320 ;
}
} else {
V_37 |= V_320 ;
}
F_5 ( V_4 , V_40 , V_37 ) ;
if ( ( V_281 & V_41 ) != ( V_37 & V_41 ) ) {
unsigned int V_321 ;
if ( ( V_37 & V_41 ) == V_59 ) {
V_321 = V_61 ;
} else {
V_321 = V_60 ;
}
F_5 ( V_4 , V_66 , V_321 ) ;
}
if ( V_10 -> V_249 &&
( V_37 & V_41 ) == V_320 ) {
div = F_155 ( V_4 -> V_291 , V_284 * 2 ) ;
V_285 = div >> 3 ;
V_286 = div & V_322 ;
} else {
V_285 = F_156 ( V_4 , V_284 ) ;
}
if ( V_285 > 65535 ) {
V_285 /= 8 ;
V_37 |= V_323 ;
}
V_283 = V_285 | V_286 << V_324 ;
F_5 ( V_4 , V_325 , V_283 ) ;
F_5 ( V_4 , V_66 , V_76 | V_272 ) ;
F_5 ( V_4 , V_66 , V_273 | V_77 ) ;
F_5 ( V_4 , V_53 , V_282 ) ;
if ( F_157 ( V_4 , V_279 -> V_292 ) )
F_33 ( V_4 ) ;
else
F_35 ( V_4 ) ;
F_55 ( & V_4 -> V_126 , V_43 ) ;
}
static void F_158 ( struct V_2 * V_4 , struct V_278 * V_279 )
{
if ( V_279 -> V_326 == V_327 ) {
V_4 -> V_43 |= V_328 ;
F_52 ( & V_4 -> V_126 ) ;
F_33 ( V_4 ) ;
F_54 ( & V_4 -> V_126 ) ;
} else {
V_4 -> V_43 &= ~ V_328 ;
if ( ! F_157 ( V_4 , V_279 -> V_292 ) ) {
F_52 ( & V_4 -> V_126 ) ;
F_35 ( V_4 ) ;
F_54 ( & V_4 -> V_126 ) ;
}
}
}
static const char * F_159 ( struct V_2 * V_4 )
{
return ( V_4 -> type == V_329 ) ? L_30 : NULL ;
}
static void F_160 ( struct V_2 * V_4 )
{
struct V_230 * V_231 = F_133 ( V_4 -> V_45 ) ;
int V_330 = V_231 -> V_331 [ 0 ] . V_332 - V_231 -> V_331 [ 0 ] . V_333 + 1 ;
F_161 ( V_4 -> V_162 , V_330 ) ;
if ( V_4 -> V_43 & V_334 ) {
F_162 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
}
static int F_163 ( struct V_2 * V_4 )
{
struct V_230 * V_231 = F_133 ( V_4 -> V_45 ) ;
int V_330 = V_231 -> V_331 [ 0 ] . V_332 - V_231 -> V_331 [ 0 ] . V_333 + 1 ;
if ( ! F_164 ( V_4 -> V_162 , V_330 , L_27 ) )
return - V_335 ;
if ( V_4 -> V_43 & V_334 ) {
V_4 -> V_6 = F_165 ( V_4 -> V_162 , V_330 ) ;
if ( V_4 -> V_6 == NULL ) {
F_161 ( V_4 -> V_162 , V_330 ) ;
return - V_226 ;
}
}
return 0 ;
}
static void F_166 ( struct V_2 * V_4 , int V_43 )
{
if ( V_43 & V_336 ) {
V_4 -> type = V_329 ;
F_163 ( V_4 ) ;
}
}
static int F_167 ( struct V_2 * V_4 , struct V_337 * V_338 )
{
int V_20 = 0 ;
if ( V_338 -> type != V_339 && V_338 -> type != V_329 )
V_20 = - V_131 ;
if ( V_4 -> V_194 != V_338 -> V_194 )
V_20 = - V_131 ;
if ( V_338 -> V_340 != V_341 )
V_20 = - V_131 ;
if ( V_4 -> V_291 / 16 != V_338 -> V_342 )
V_20 = - V_131 ;
if ( V_4 -> V_162 != ( unsigned long ) V_338 -> V_343 )
V_20 = - V_131 ;
if ( V_4 -> V_344 != V_338 -> V_4 )
V_20 = - V_131 ;
if ( V_338 -> V_345 != 0 )
V_20 = - V_131 ;
return V_20 ;
}
static int F_168 ( struct V_2 * V_4 )
{
while ( ! ( F_3 ( V_4 , V_21 ) & V_82 ) )
F_169 () ;
return F_7 ( V_4 ) ;
}
static void F_170 ( struct V_2 * V_4 , unsigned char V_95 )
{
while ( ! ( F_3 ( V_4 , V_21 ) & V_52 ) )
F_169 () ;
F_8 ( V_4 , V_95 ) ;
}
static int F_171 ( struct V_1 * V_10 ,
struct V_230 * V_231 )
{
int V_20 ;
struct V_2 * V_4 = & V_10 -> V_3 ;
struct V_235 * V_236 = F_125 ( & V_231 -> V_45 ) ;
F_124 ( V_10 , V_231 ) ;
F_130 ( V_4 ) ;
F_127 ( V_4 , V_231 ) ;
V_4 -> V_346 = V_347 ;
V_4 -> V_43 = V_348 ;
V_4 -> V_349 = & V_350 ;
V_4 -> V_351 = 1 ;
V_4 -> V_45 = & V_231 -> V_45 ;
V_4 -> V_162 = V_231 -> V_331 [ 0 ] . V_333 ;
V_4 -> V_194 = V_231 -> V_331 [ 1 ] . V_333 ;
V_4 -> V_352 = F_23 ;
memset ( & V_10 -> V_98 , 0 , sizeof( V_10 -> V_98 ) ) ;
if ( V_236 && V_236 -> V_353 ) {
V_4 -> V_6 = V_236 -> V_353 ;
} else {
V_4 -> V_43 |= V_334 ;
V_4 -> V_6 = NULL ;
}
if ( ! V_10 -> V_276 ) {
V_10 -> V_276 = F_172 ( & V_231 -> V_45 , L_31 ) ;
if ( F_173 ( V_10 -> V_276 ) ) {
V_20 = F_174 ( V_10 -> V_276 ) ;
V_10 -> V_276 = NULL ;
return V_20 ;
}
V_20 = F_150 ( V_10 -> V_276 ) ;
if ( V_20 ) {
F_175 ( V_10 -> V_276 ) ;
V_10 -> V_276 = NULL ;
return V_20 ;
}
V_4 -> V_291 = F_176 ( V_10 -> V_276 ) ;
F_151 ( V_10 -> V_276 ) ;
}
if ( V_4 -> V_42 . V_43 & V_44 )
V_10 -> V_39 = V_46 ;
else if ( F_12 ( V_4 ) ) {
V_4 -> V_351 = V_224 ;
V_10 -> V_39 = V_50 | V_51 ;
} else {
V_10 -> V_39 = V_52 ;
}
return 0 ;
}
static void F_177 ( struct V_2 * V_4 , int V_95 )
{
while ( ! ( F_3 ( V_4 , V_21 ) & V_52 ) )
F_169 () ;
F_8 ( V_4 , V_95 ) ;
}
static void F_178 ( struct V_354 * V_355 , const char * V_356 , T_3 V_174 )
{
struct V_2 * V_4 = & V_357 [ V_355 -> V_358 ] . V_3 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_19 , V_282 ;
unsigned int V_206 ;
V_282 = F_3 ( V_4 , V_198 ) ;
F_5 ( V_4 , V_38 ,
V_82 | V_10 -> V_39 ) ;
V_206 = F_3 ( V_4 , V_74 ) & V_75 ;
F_5 ( V_4 , V_71 , V_72 ) ;
F_179 ( V_4 , V_356 , V_174 , F_177 ) ;
do {
V_19 = F_3 ( V_4 , V_21 ) ;
} while ( ! ( V_19 & V_52 ) );
if ( V_206 )
F_5 ( V_4 , V_71 , V_75 ) ;
F_5 ( V_4 , V_53 , V_282 ) ;
}
static void T_9 F_180 ( struct V_2 * V_4 , int * V_284 ,
int * V_110 , int * V_359 )
{
unsigned int V_360 , V_283 ;
V_283 = F_3 ( V_4 , V_325 ) & V_361 ;
if ( ! V_283 )
return;
V_360 = F_3 ( V_4 , V_40 ) & V_288 ;
if ( V_360 == V_300 )
* V_359 = 8 ;
else
* V_359 = 7 ;
V_360 = F_3 ( V_4 , V_40 ) & V_290 ;
if ( V_360 == V_309 )
* V_110 = 'e' ;
else if ( V_360 == V_308 )
* V_110 = 'o' ;
* V_284 = V_4 -> V_291 / ( 16 * ( V_283 - 1 ) ) ;
}
static int T_9 F_181 ( struct V_354 * V_355 , char * V_362 )
{
int V_20 ;
struct V_2 * V_4 = & V_357 [ V_355 -> V_358 ] . V_3 ;
int V_284 = 115200 ;
int V_359 = 8 ;
int V_110 = 'n' ;
int V_363 = 'n' ;
if ( V_4 -> V_6 == NULL ) {
return - V_364 ;
}
V_20 = F_150 ( V_357 [ V_355 -> V_358 ] . V_276 ) ;
if ( V_20 )
return V_20 ;
F_5 ( V_4 , V_38 , - 1 ) ;
F_5 ( V_4 , V_66 , V_76 | V_272 ) ;
F_5 ( V_4 , V_66 , V_273 | V_77 ) ;
if ( V_362 )
F_182 ( V_362 , & V_284 , & V_110 , & V_359 , & V_363 ) ;
else
F_180 ( V_4 , & V_284 , & V_110 , & V_359 ) ;
return F_183 ( V_4 , V_355 , V_284 , V_110 , V_359 , V_363 ) ;
}
static int T_9 F_184 ( void )
{
int V_20 ;
if ( V_365 ) {
struct V_235 * V_236 =
F_125 ( & V_365 -> V_45 ) ;
int V_366 = V_236 -> V_367 ;
struct V_1 * V_10 = & V_357 [ V_366 ] ;
V_10 -> V_277 = 0 ;
V_10 -> V_3 . line = V_366 ;
F_185 ( V_368 , V_366 , NULL ) ;
V_20 = F_171 ( V_10 , V_365 ) ;
if ( V_20 )
return V_20 ;
F_186 ( & V_369 ) ;
}
return 0 ;
}
static int T_9 F_187 ( void )
{
if ( V_365
&& ! ( V_369 . V_43 & V_370 ) )
F_186 ( & V_369 ) ;
return 0 ;
}
static inline bool F_188 ( struct V_2 * V_4 )
{
return V_4 -> V_371 && V_4 -> V_371 -> V_358 == V_4 -> line ;
}
static inline bool F_188 ( struct V_2 * V_4 )
{
return false ;
}
static bool F_189 ( void )
{
#ifdef F_190
return F_191 () ;
#else
return false ;
#endif
}
static int F_192 ( struct V_230 * V_231 ,
T_10 V_117 )
{
struct V_2 * V_4 = F_193 ( V_231 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_188 ( V_4 ) && V_372 ) {
while ( ! ( F_3 ( V_4 , V_21 ) &
V_46 ) )
F_169 () ;
}
V_10 -> V_373 = F_194 ( & V_231 -> V_45 ) ;
if ( F_189 () ) {
unsigned long V_43 ;
F_50 ( & V_10 -> V_197 , V_43 ) ;
V_10 -> V_199 = true ;
F_55 ( & V_10 -> V_197 , V_43 ) ;
F_195 ( & V_231 -> V_45 , 0 ) ;
}
F_196 ( & V_374 , V_4 ) ;
return 0 ;
}
static int F_197 ( struct V_230 * V_231 )
{
struct V_2 * V_4 = F_193 ( V_231 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned long V_43 ;
F_50 ( & V_10 -> V_197 , V_43 ) ;
if ( V_10 -> V_188 ) {
F_95 ( V_4 , V_10 -> V_188 ) ;
F_97 ( V_4 , V_10 -> V_188 ,
V_10 -> V_200 ) ;
F_96 ( V_4 , V_10 -> V_188 ) ;
V_10 -> V_188 = 0 ;
}
V_10 -> V_199 = false ;
F_55 ( & V_10 -> V_197 , V_43 ) ;
F_198 ( & V_374 , V_4 ) ;
F_195 ( & V_231 -> V_45 , V_10 -> V_373 ) ;
return 0 ;
}
static void F_199 ( struct V_1 * V_10 ,
struct V_230 * V_231 )
{
V_10 -> V_15 = 0 ;
V_10 -> V_269 = 0 ;
V_10 -> V_268 = 0 ;
if ( F_200 ( V_231 -> V_45 . V_234 ,
L_32 ,
& V_10 -> V_15 ) )
return;
if ( ! V_10 -> V_15 )
return;
if ( V_10 -> V_15 < V_375 ) {
V_10 -> V_15 = 0 ;
F_65 ( & V_231 -> V_45 , L_33 ) ;
return;
}
V_10 -> V_268 = F_201 ( int , V_10 -> V_15 >> 1 ,
V_10 -> V_15 - V_376 ) ;
V_10 -> V_269 = F_201 ( int , V_10 -> V_15 >> 2 ,
V_10 -> V_15 - V_377 ) ;
F_72 ( & V_231 -> V_45 , L_34 ,
V_10 -> V_15 ) ;
F_24 ( & V_231 -> V_45 , L_35 ,
V_10 -> V_268 ) ;
F_24 ( & V_231 -> V_45 , L_36 ,
V_10 -> V_269 ) ;
}
static int F_202 ( struct V_230 * V_231 )
{
struct V_1 * V_10 ;
struct V_232 * V_233 = V_231 -> V_45 . V_234 ;
struct V_235 * V_236 = F_125 ( & V_231 -> V_45 ) ;
void * V_185 ;
int V_20 = - V_364 ;
bool V_378 ;
F_203 ( V_103 & ( V_103 - 1 ) ) ;
if ( V_233 )
V_20 = F_204 ( V_233 , L_37 ) ;
else
if ( V_236 )
V_20 = V_236 -> V_367 ;
if ( V_20 < 0 )
V_20 = F_205 ( V_379 , V_380 ) ;
if ( V_20 >= V_380 ) {
V_20 = - V_364 ;
goto V_381;
}
if ( F_206 ( V_20 , V_379 ) ) {
V_20 = - V_335 ;
goto V_381;
}
V_10 = & V_357 [ V_20 ] ;
V_10 -> V_277 = 0 ;
V_10 -> V_3 . line = V_20 ;
F_199 ( V_10 , V_231 ) ;
F_135 ( & V_10 -> V_18 , 0 ) ;
F_74 ( & V_10 -> V_197 ) ;
V_20 = F_171 ( V_10 , V_231 ) ;
if ( V_20 )
goto V_382;
V_10 -> V_22 = F_207 ( & V_10 -> V_3 , 0 ) ;
if ( F_173 ( V_10 -> V_22 ) ) {
V_20 = F_174 ( V_10 -> V_22 ) ;
goto V_382;
}
if ( ! F_11 ( & V_10 -> V_3 ) ) {
V_20 = - V_226 ;
V_185 = F_121 ( sizeof( struct V_99 )
* V_103 , V_225 ) ;
if ( ! V_185 )
goto V_383;
V_10 -> V_98 . V_104 = V_185 ;
}
V_378 = V_10 -> V_3 . V_42 . V_43 & V_44 ;
V_20 = F_208 ( & V_374 , & V_10 -> V_3 ) ;
if ( V_20 )
goto V_384;
#ifdef F_209
if ( F_188 ( & V_10 -> V_3 )
&& V_385 -> V_43 & V_370 ) {
F_151 ( V_10 -> V_276 ) ;
}
#endif
F_210 ( & V_231 -> V_45 , 1 ) ;
F_211 ( V_231 , V_10 ) ;
F_150 ( V_10 -> V_276 ) ;
if ( V_378 ) {
F_5 ( & V_10 -> V_3 , V_40 ,
V_320 ) ;
F_5 ( & V_10 -> V_3 , V_66 ,
V_60 ) ;
}
F_131 ( & V_10 -> V_3 ) ;
F_151 ( V_10 -> V_276 ) ;
return 0 ;
V_384:
F_115 ( V_10 -> V_98 . V_104 ) ;
V_10 -> V_98 . V_104 = NULL ;
V_383:
if ( ! F_188 ( & V_10 -> V_3 ) ) {
F_175 ( V_10 -> V_276 ) ;
V_10 -> V_276 = NULL ;
}
V_382:
F_212 ( V_10 -> V_3 . line , V_379 ) ;
V_381:
return V_20 ;
}
static int F_213 ( struct V_230 * V_231 )
{
struct V_2 * V_4 = F_193 ( V_231 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_20 = 0 ;
F_147 ( & V_10 -> V_115 ) ;
F_147 ( & V_10 -> V_132 ) ;
F_210 ( & V_231 -> V_45 , 0 ) ;
V_20 = F_214 ( & V_374 , V_4 ) ;
F_115 ( V_10 -> V_98 . V_104 ) ;
F_212 ( V_4 -> line , V_379 ) ;
F_175 ( V_10 -> V_276 ) ;
V_10 -> V_276 = NULL ;
return V_20 ;
}
static int T_9 F_215 ( void )
{
int V_20 ;
V_20 = F_216 ( & V_374 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_217 ( & V_386 ) ;
if ( V_20 )
F_218 ( & V_374 ) ;
return V_20 ;
}
