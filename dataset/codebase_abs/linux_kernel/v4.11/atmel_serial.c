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
F_5 ( V_4 , V_66 , V_73 ) ;
F_5 ( V_4 , V_38 , V_10 -> V_39 ) ;
if ( ( V_4 -> V_42 . V_43 & V_44 ) &&
! ( V_4 -> V_42 . V_43 & V_74 ) )
F_30 ( V_4 ) ;
}
static void F_31 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_12 ( V_4 ) && ( F_3 ( V_4 , V_75 )
& V_76 ) )
return;
if ( F_12 ( V_4 ) || F_13 ( V_4 ) )
if ( ( V_4 -> V_42 . V_43 & V_44 ) &&
! ( V_4 -> V_42 . V_43 & V_74 ) )
F_32 ( V_4 ) ;
if ( F_12 ( V_4 ) )
F_5 ( V_4 , V_71 , V_76 ) ;
F_5 ( V_4 , V_53 , V_10 -> V_39 ) ;
F_5 ( V_4 , V_66 , V_77 ) ;
}
static void F_30 ( struct V_2 * V_4 )
{
F_5 ( V_4 , V_66 , V_78 ) ;
F_5 ( V_4 , V_66 , V_79 ) ;
if ( F_11 ( V_4 ) ) {
F_5 ( V_4 , V_53 ,
V_80 | V_81 |
V_4 -> V_82 ) ;
F_5 ( V_4 , V_71 , V_83 ) ;
} else {
F_5 ( V_4 , V_53 , V_84 ) ;
}
}
static void F_32 ( struct V_2 * V_4 )
{
F_5 ( V_4 , V_66 , V_85 ) ;
if ( F_11 ( V_4 ) ) {
F_5 ( V_4 , V_71 , V_86 ) ;
F_5 ( V_4 , V_38 ,
V_80 | V_81 |
V_4 -> V_82 ) ;
} else {
F_5 ( V_4 , V_38 , V_84 ) ;
}
}
static void F_33 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
T_4 V_87 = 0 ;
if ( V_10 -> V_88 )
return;
V_10 -> V_88 = true ;
if ( ! F_22 ( V_10 -> V_22 , V_23 ) )
V_87 |= V_89 ;
if ( ! F_22 ( V_10 -> V_22 , V_26 ) )
V_87 |= V_90 ;
if ( ! F_22 ( V_10 -> V_22 , V_29 ) )
V_87 |= V_91 ;
if ( ! F_22 ( V_10 -> V_22 , V_32 ) )
V_87 |= V_92 ;
F_5 ( V_4 , V_53 , V_87 ) ;
F_34 ( V_10 -> V_22 ) ;
}
static void F_35 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
T_4 V_93 = 0 ;
if ( ! V_10 -> V_88 )
return;
V_10 -> V_88 = false ;
F_36 ( V_10 -> V_22 ) ;
if ( ! F_22 ( V_10 -> V_22 , V_23 ) )
V_93 |= V_89 ;
if ( ! F_22 ( V_10 -> V_22 , V_26 ) )
V_93 |= V_90 ;
if ( ! F_22 ( V_10 -> V_22 , V_29 ) )
V_93 |= V_91 ;
if ( ! F_22 ( V_10 -> V_22 , V_32 ) )
V_93 |= V_92 ;
F_5 ( V_4 , V_38 , V_93 ) ;
}
static void F_37 ( struct V_2 * V_4 , int V_94 )
{
if ( V_94 != 0 )
F_5 ( V_4 , V_66 , V_95 ) ;
else
F_5 ( V_4 , V_66 , V_96 ) ;
}
static void
F_38 ( struct V_2 * V_4 , unsigned int V_19 ,
unsigned int V_97 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_98 * V_99 = & V_10 -> V_100 ;
struct V_101 * V_102 ;
if ( ! F_39 ( V_99 -> V_103 , V_99 -> V_104 , V_105 ) )
return;
V_102 = & ( (struct V_101 * ) V_99 -> V_106 ) [ V_99 -> V_103 ] ;
V_102 -> V_19 = V_19 ;
V_102 -> V_97 = V_97 ;
F_40 () ;
V_99 -> V_103 = ( V_99 -> V_103 + 1 ) & ( V_105 - 1 ) ;
}
static void F_41 ( struct V_2 * V_4 , unsigned int V_19 )
{
F_5 ( V_4 , V_66 , V_78 ) ;
if ( V_19 & V_107 ) {
V_19 &= ~ ( V_108 | V_109 ) ;
V_4 -> V_110 . V_111 ++ ;
}
if ( V_19 & V_108 )
V_4 -> V_110 . V_112 ++ ;
if ( V_19 & V_109 )
V_4 -> V_110 . V_113 ++ ;
if ( V_19 & V_114 )
V_4 -> V_110 . V_115 ++ ;
}
static void F_42 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_19 , V_97 ;
V_19 = F_3 ( V_4 , V_21 ) ;
while ( V_19 & V_84 ) {
V_97 = F_7 ( V_4 ) ;
if ( F_43 ( V_19 & ( V_108 | V_109
| V_114 | V_107 )
|| V_10 -> V_116 ) ) {
F_5 ( V_4 , V_66 , V_78 ) ;
if ( V_19 & V_107
&& ! V_10 -> V_116 ) {
V_10 -> V_116 = 1 ;
F_5 ( V_4 , V_53 ,
V_107 ) ;
} else {
F_5 ( V_4 , V_38 ,
V_107 ) ;
V_19 &= ~ V_107 ;
V_10 -> V_116 = 0 ;
}
}
F_38 ( V_4 , V_19 , V_97 ) ;
V_19 = F_3 ( V_4 , V_21 ) ;
}
F_16 ( V_10 , & V_10 -> V_117 ) ;
}
static void F_44 ( struct V_2 * V_4 )
{
struct V_98 * V_118 = & V_4 -> V_119 -> V_118 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( V_4 -> V_120 &&
( F_3 ( V_4 , V_21 ) & V_10 -> V_39 ) ) {
F_8 ( V_4 , V_4 -> V_120 ) ;
V_4 -> V_110 . V_121 ++ ;
V_4 -> V_120 = 0 ;
}
if ( F_45 ( V_118 ) || F_46 ( V_4 ) )
return;
while ( F_3 ( V_4 , V_21 ) &
V_10 -> V_39 ) {
F_8 ( V_4 , V_118 -> V_106 [ V_118 -> V_104 ] ) ;
V_118 -> V_104 = ( V_118 -> V_104 + 1 ) & ( V_122 - 1 ) ;
V_4 -> V_110 . V_121 ++ ;
if ( F_45 ( V_118 ) )
break;
}
if ( F_47 ( V_118 ) < V_123 )
F_48 ( V_4 ) ;
if ( ! F_45 ( V_118 ) )
F_5 ( V_4 , V_53 ,
V_10 -> V_39 ) ;
}
static void F_49 ( void * V_124 )
{
struct V_1 * V_10 = V_124 ;
struct V_2 * V_4 = & V_10 -> V_3 ;
struct V_98 * V_118 = & V_4 -> V_119 -> V_118 ;
struct V_125 * V_126 = V_10 -> V_127 ;
unsigned long V_43 ;
F_50 ( & V_4 -> V_128 , V_43 ) ;
if ( V_126 )
F_51 ( V_126 ) ;
V_118 -> V_104 += V_10 -> V_129 ;
V_118 -> V_104 &= V_122 - 1 ;
V_4 -> V_110 . V_121 += V_10 -> V_129 ;
F_52 ( & V_10 -> V_130 ) ;
F_53 ( V_10 -> V_131 ) ;
V_10 -> V_132 = - V_133 ;
V_10 -> V_131 = NULL ;
F_54 ( & V_10 -> V_130 ) ;
if ( F_47 ( V_118 ) < V_123 )
F_48 ( V_4 ) ;
if ( ! F_45 ( V_118 ) )
F_16 ( V_10 , & V_10 -> V_134 ) ;
else if ( ( V_4 -> V_42 . V_43 & V_44 ) &&
! ( V_4 -> V_42 . V_43 & V_74 ) ) {
F_30 ( V_4 ) ;
}
F_55 ( & V_4 -> V_128 , V_43 ) ;
}
static void F_56 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_125 * V_126 = V_10 -> V_127 ;
if ( V_126 ) {
F_51 ( V_126 ) ;
F_57 ( V_126 ) ;
F_58 ( V_4 -> V_45 , & V_10 -> V_135 , 1 ,
V_136 ) ;
}
V_10 -> V_131 = NULL ;
V_10 -> V_127 = NULL ;
V_10 -> V_132 = - V_133 ;
}
static void F_59 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_98 * V_118 = & V_4 -> V_119 -> V_118 ;
struct V_125 * V_126 = V_10 -> V_127 ;
struct V_137 * V_138 ;
struct V_139 V_140 [ 2 ] , * V_141 , * V_135 = & V_10 -> V_135 ;
unsigned int V_129 , V_142 , V_143 , V_144 ;
T_5 V_145 ;
if ( V_10 -> V_131 != NULL )
return;
if ( ! F_45 ( V_118 ) && ! F_46 ( V_4 ) ) {
V_129 = F_60 ( V_118 -> V_103 ,
V_118 -> V_104 ,
V_122 ) ;
if ( V_10 -> V_15 ) {
V_142 = ( V_129 & ~ 0x3 ) ;
V_143 = ( V_129 & 0x3 ) ;
} else {
V_142 = 0 ;
V_143 = V_129 ;
}
F_61 ( V_140 , 2 ) ;
V_144 = 0 ;
V_145 = F_62 ( V_135 ) + V_118 -> V_104 ;
if ( V_142 ) {
V_141 = & V_140 [ V_144 ++ ] ;
F_62 ( V_141 ) = V_145 ;
F_63 ( V_141 ) = V_142 ;
V_145 += V_142 ;
}
if ( V_143 ) {
V_141 = & V_140 [ V_144 ++ ] ;
F_62 ( V_141 ) = V_145 ;
F_63 ( V_141 ) = V_143 ;
}
V_10 -> V_129 = V_129 ;
V_138 = F_64 ( V_126 ,
V_140 ,
V_144 ,
V_146 ,
V_147 |
V_148 ) ;
if ( ! V_138 ) {
F_65 ( V_4 -> V_45 , L_3 ) ;
return;
}
F_66 ( V_4 -> V_45 , V_135 , 1 , V_136 ) ;
V_10 -> V_131 = V_138 ;
V_138 -> V_149 = F_49 ;
V_138 -> V_150 = V_10 ;
V_10 -> V_132 = F_67 ( V_138 ) ;
}
if ( F_47 ( V_118 ) < V_123 )
F_48 ( V_4 ) ;
}
static int F_68 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
T_6 V_151 ;
struct V_152 V_153 ;
int V_20 , V_154 ;
F_69 ( V_151 ) ;
F_70 ( V_155 , V_151 ) ;
V_10 -> V_127 = F_71 ( V_4 -> V_45 , L_4 ) ;
if ( V_10 -> V_127 == NULL )
goto V_156;
F_72 ( V_4 -> V_45 , L_5 ,
F_73 ( V_10 -> V_127 ) ) ;
F_74 ( & V_10 -> V_130 ) ;
F_61 ( & V_10 -> V_135 , 1 ) ;
F_75 ( ! F_76 ( V_4 -> V_119 -> V_118 . V_106 ) ) ;
F_77 ( & V_10 -> V_135 ,
F_78 ( V_4 -> V_119 -> V_118 . V_106 ) ,
V_122 ,
( unsigned long ) V_4 -> V_119 -> V_118 . V_106 & ~ V_157 ) ;
V_154 = F_79 ( V_4 -> V_45 ,
& V_10 -> V_135 ,
1 ,
V_136 ) ;
if ( ! V_154 ) {
F_24 ( V_4 -> V_45 , L_6 ) ;
goto V_156;
} else {
F_24 ( V_4 -> V_45 , L_7 , V_158 ,
F_63 ( & V_10 -> V_135 ) ,
V_4 -> V_119 -> V_118 . V_106 ,
& F_62 ( & V_10 -> V_135 ) ) ;
}
memset ( & V_153 , 0 , sizeof( V_153 ) ) ;
V_153 . V_159 = V_146 ;
V_153 . V_160 = ( V_10 -> V_15 ) ?
V_161 :
V_162 ;
V_153 . V_163 = V_4 -> V_164 + V_9 ;
V_153 . V_165 = 1 ;
V_20 = F_80 ( V_10 -> V_127 ,
& V_153 ) ;
if ( V_20 ) {
F_65 ( V_4 -> V_45 , L_8 ) ;
goto V_156;
}
return 0 ;
V_156:
F_65 ( V_4 -> V_45 , L_9 ) ;
V_10 -> V_13 = 0 ;
if ( V_10 -> V_127 )
F_56 ( V_4 ) ;
return - V_133 ;
}
static void F_81 ( void * V_124 )
{
struct V_2 * V_4 = V_124 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_16 ( V_10 , & V_10 -> V_117 ) ;
}
static void F_82 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_125 * V_126 = V_10 -> V_166 ;
if ( V_126 ) {
F_51 ( V_126 ) ;
F_57 ( V_126 ) ;
F_58 ( V_4 -> V_45 , & V_10 -> V_167 , 1 ,
V_168 ) ;
}
V_10 -> V_169 = NULL ;
V_10 -> V_166 = NULL ;
V_10 -> V_170 = - V_133 ;
}
static void F_83 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_171 * V_172 = & V_4 -> V_119 -> V_4 ;
struct V_98 * V_99 = & V_10 -> V_100 ;
struct V_125 * V_126 = V_10 -> V_166 ;
struct V_173 V_119 ;
enum V_174 V_175 ;
T_7 V_176 ;
F_5 ( V_4 , V_66 , V_177 ) ;
V_175 = F_84 ( V_126 ,
V_10 -> V_170 ,
& V_119 ) ;
if ( V_175 == V_178 ) {
F_24 ( V_4 -> V_45 , L_10 ) ;
F_5 ( V_4 , V_53 , V_81 ) ;
F_16 ( V_10 , & V_10 -> V_117 ) ;
return;
}
F_85 ( V_4 -> V_45 ,
& V_10 -> V_167 ,
1 ,
V_168 ) ;
V_99 -> V_103 = F_63 ( & V_10 -> V_167 ) - V_119 . V_179 ;
F_75 ( V_99 -> V_103 > F_63 ( & V_10 -> V_167 ) ) ;
if ( V_99 -> V_103 < V_99 -> V_104 ) {
V_176 = F_63 ( & V_10 -> V_167 ) - V_99 -> V_104 ;
F_86 ( V_172 , V_99 -> V_106 + V_99 -> V_104 , V_176 ) ;
V_99 -> V_104 = 0 ;
V_4 -> V_110 . V_180 += V_176 ;
}
if ( V_99 -> V_104 < V_99 -> V_103 ) {
V_176 = V_99 -> V_103 - V_99 -> V_104 ;
F_86 ( V_172 , V_99 -> V_106 + V_99 -> V_104 , V_176 ) ;
if ( V_99 -> V_103 >= F_63 ( & V_10 -> V_167 ) )
V_99 -> V_103 = 0 ;
V_99 -> V_104 = V_99 -> V_103 ;
V_4 -> V_110 . V_180 += V_176 ;
}
F_66 ( V_4 -> V_45 ,
& V_10 -> V_167 ,
1 ,
V_168 ) ;
F_87 ( & V_4 -> V_128 ) ;
F_88 ( V_172 ) ;
F_89 ( & V_4 -> V_128 ) ;
F_5 ( V_4 , V_53 , V_81 ) ;
}
static int F_90 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_137 * V_138 ;
T_6 V_151 ;
struct V_152 V_153 ;
struct V_98 * V_99 ;
int V_20 , V_154 ;
V_99 = & V_10 -> V_100 ;
F_69 ( V_151 ) ;
F_70 ( V_181 , V_151 ) ;
V_10 -> V_166 = F_71 ( V_4 -> V_45 , L_11 ) ;
if ( V_10 -> V_166 == NULL )
goto V_156;
F_72 ( V_4 -> V_45 , L_12 ,
F_73 ( V_10 -> V_166 ) ) ;
F_74 ( & V_10 -> V_182 ) ;
F_61 ( & V_10 -> V_167 , 1 ) ;
F_75 ( ! F_76 ( V_99 -> V_106 ) ) ;
F_77 ( & V_10 -> V_167 ,
F_78 ( V_99 -> V_106 ) ,
sizeof( struct V_101 ) * V_105 ,
( unsigned long ) V_99 -> V_106 & ~ V_157 ) ;
V_154 = F_79 ( V_4 -> V_45 ,
& V_10 -> V_167 ,
1 ,
V_168 ) ;
if ( ! V_154 ) {
F_24 ( V_4 -> V_45 , L_6 ) ;
goto V_156;
} else {
F_24 ( V_4 -> V_45 , L_7 , V_158 ,
F_63 ( & V_10 -> V_167 ) ,
V_99 -> V_106 ,
& F_62 ( & V_10 -> V_167 ) ) ;
}
memset ( & V_153 , 0 , sizeof( V_153 ) ) ;
V_153 . V_159 = V_183 ;
V_153 . V_184 = V_162 ;
V_153 . V_185 = V_4 -> V_164 + V_8 ;
V_153 . V_186 = 1 ;
V_20 = F_80 ( V_10 -> V_166 ,
& V_153 ) ;
if ( V_20 ) {
F_65 ( V_4 -> V_45 , L_13 ) ;
goto V_156;
}
V_138 = F_91 ( V_10 -> V_166 ,
F_62 ( & V_10 -> V_167 ) ,
F_63 ( & V_10 -> V_167 ) ,
F_63 ( & V_10 -> V_167 ) / 2 ,
V_183 ,
V_147 ) ;
V_138 -> V_149 = F_81 ;
V_138 -> V_150 = V_4 ;
V_10 -> V_169 = V_138 ;
V_10 -> V_170 = F_67 ( V_138 ) ;
return 0 ;
V_156:
F_65 ( V_4 -> V_45 , L_14 ) ;
V_10 -> V_14 = 0 ;
if ( V_10 -> V_166 )
F_82 ( V_4 ) ;
return - V_133 ;
}
static void F_92 ( unsigned long V_187 )
{
struct V_2 * V_4 = ( void * ) V_187 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( ! F_17 ( & V_10 -> V_18 ) ) {
F_18 ( & V_10 -> V_117 ) ;
F_93 ( & V_10 -> V_188 ,
V_189 + F_94 ( V_4 ) ) ;
}
}
static void
F_95 ( struct V_2 * V_4 , unsigned int V_190 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_11 ( V_4 ) ) {
if ( V_190 & ( V_80 | V_81 ) ) {
F_5 ( V_4 , V_38 ,
( V_80 | V_81 ) ) ;
F_16 ( V_10 ,
& V_10 -> V_117 ) ;
}
if ( V_190 & ( V_107 | V_114 |
V_109 | V_108 ) )
F_41 ( V_4 , V_190 ) ;
}
if ( F_14 ( V_4 ) ) {
if ( V_190 & V_81 ) {
F_5 ( V_4 , V_38 ,
V_81 ) ;
F_16 ( V_10 ,
& V_10 -> V_117 ) ;
}
}
if ( V_190 & V_84 )
F_42 ( V_4 ) ;
else if ( V_190 & V_107 ) {
F_5 ( V_4 , V_66 , V_78 ) ;
F_5 ( V_4 , V_38 , V_107 ) ;
V_10 -> V_116 = 0 ;
}
}
static void
F_96 ( struct V_2 * V_4 , unsigned int V_190 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( V_190 & V_10 -> V_39 ) {
F_5 ( V_4 , V_38 ,
V_10 -> V_39 ) ;
F_16 ( V_10 , & V_10 -> V_134 ) ;
}
}
static void
F_97 ( struct V_2 * V_4 , unsigned int V_190 ,
unsigned int V_19 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_191 ;
if ( V_190 & ( V_91 | V_90 | V_92
| V_89 ) ) {
V_191 = V_19 ^ V_10 -> V_192 ;
V_10 -> V_192 = V_19 ;
if ( V_191 & ( V_31 | V_28
| V_34 | V_25 ) ) {
if ( V_191 & V_31 )
V_4 -> V_110 . V_193 ++ ;
if ( V_191 & V_28 )
V_4 -> V_110 . V_194 ++ ;
if ( V_191 & V_34 )
F_98 ( V_4 , ! ( V_19 & V_34 ) ) ;
if ( V_191 & V_25 )
F_99 ( V_4 , ! ( V_19 & V_25 ) ) ;
F_100 ( & V_4 -> V_119 -> V_4 . V_195 ) ;
}
}
}
static T_8 F_101 ( int V_196 , void * V_197 )
{
struct V_2 * V_4 = V_197 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_19 , V_190 , V_151 , V_198 = 0 ;
F_89 ( & V_10 -> V_199 ) ;
do {
V_19 = F_19 ( V_4 ) ;
V_151 = F_3 ( V_4 , V_200 ) ;
V_190 = V_19 & V_151 ;
if ( ! V_190 )
break;
if ( V_10 -> V_201 ) {
V_10 -> V_190 |= V_190 ;
V_10 -> V_202 = V_19 ;
F_5 ( V_4 , V_38 , V_151 ) ;
F_102 () ;
break;
}
F_95 ( V_4 , V_190 ) ;
F_97 ( V_4 , V_190 , V_19 ) ;
F_96 ( V_4 , V_190 ) ;
} while ( V_198 ++ < V_203 );
F_87 ( & V_10 -> V_199 ) ;
return V_198 ? V_204 : V_205 ;
}
static void F_103 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_206 * V_207 = & V_10 -> V_208 ;
F_104 ( V_4 -> V_45 ,
V_207 -> V_209 ,
V_207 -> V_210 ,
V_136 ) ;
}
static void F_105 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_98 * V_118 = & V_4 -> V_119 -> V_118 ;
struct V_206 * V_207 = & V_10 -> V_208 ;
int V_176 ;
if ( F_3 ( V_4 , V_211 ) )
return;
V_118 -> V_104 += V_207 -> V_212 ;
V_118 -> V_104 &= V_122 - 1 ;
V_4 -> V_110 . V_121 += V_207 -> V_212 ;
V_207 -> V_212 = 0 ;
F_5 ( V_4 , V_71 , V_72 ) ;
if ( ! F_45 ( V_118 ) && ! F_46 ( V_4 ) ) {
F_106 ( V_4 -> V_45 ,
V_207 -> V_209 ,
V_207 -> V_210 ,
V_136 ) ;
V_176 = F_60 ( V_118 -> V_103 , V_118 -> V_104 , V_122 ) ;
V_207 -> V_212 = V_176 ;
F_5 ( V_4 , V_213 ,
V_207 -> V_209 + V_118 -> V_104 ) ;
F_5 ( V_4 , V_211 , V_176 ) ;
F_5 ( V_4 , V_71 , V_76 ) ;
F_5 ( V_4 , V_53 ,
V_10 -> V_39 ) ;
} else {
if ( ( V_4 -> V_42 . V_43 & V_44 ) &&
! ( V_4 -> V_42 . V_43 & V_74 ) ) {
F_30 ( V_4 ) ;
}
}
if ( F_47 ( V_118 ) < V_123 )
F_48 ( V_4 ) ;
}
static int F_107 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_206 * V_207 = & V_10 -> V_208 ;
struct V_98 * V_118 = & V_4 -> V_119 -> V_118 ;
V_207 -> V_106 = V_118 -> V_106 ;
V_207 -> V_209 = F_108 ( V_4 -> V_45 ,
V_207 -> V_106 ,
V_122 ,
V_136 ) ;
V_207 -> V_210 = V_122 ;
V_207 -> V_212 = 0 ;
return 0 ;
}
static void F_109 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_98 * V_99 = & V_10 -> V_100 ;
unsigned int V_214 ;
unsigned int V_19 ;
while ( V_99 -> V_103 != V_99 -> V_104 ) {
struct V_101 V_102 ;
F_110 () ;
V_102 = ( (struct V_101 * ) V_99 -> V_106 ) [ V_99 -> V_104 ] ;
V_99 -> V_104 = ( V_99 -> V_104 + 1 ) & ( V_105 - 1 ) ;
V_4 -> V_110 . V_180 ++ ;
V_19 = V_102 . V_19 ;
V_214 = V_215 ;
if ( F_43 ( V_19 & ( V_108 | V_109
| V_114 | V_107 ) ) ) {
if ( V_19 & V_107 ) {
V_19 &= ~ ( V_108 | V_109 ) ;
V_4 -> V_110 . V_111 ++ ;
if ( F_111 ( V_4 ) )
continue;
}
if ( V_19 & V_108 )
V_4 -> V_110 . V_112 ++ ;
if ( V_19 & V_109 )
V_4 -> V_110 . V_113 ++ ;
if ( V_19 & V_114 )
V_4 -> V_110 . V_115 ++ ;
V_19 &= V_4 -> V_82 ;
if ( V_19 & V_107 )
V_214 = V_216 ;
else if ( V_19 & V_108 )
V_214 = V_217 ;
else if ( V_19 & V_109 )
V_214 = V_218 ;
}
if ( F_112 ( V_4 , V_102 . V_97 ) )
continue;
F_113 ( V_4 , V_19 , V_114 , V_102 . V_97 , V_214 ) ;
}
F_87 ( & V_4 -> V_128 ) ;
F_88 ( & V_4 -> V_119 -> V_4 ) ;
F_89 ( & V_4 -> V_128 ) ;
}
static void F_114 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_219 ;
for ( V_219 = 0 ; V_219 < 2 ; V_219 ++ ) {
struct V_206 * V_207 = & V_10 -> V_220 [ V_219 ] ;
F_104 ( V_4 -> V_45 ,
V_207 -> V_209 ,
V_207 -> V_210 ,
V_168 ) ;
F_115 ( V_207 -> V_106 ) ;
}
}
static void F_116 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_171 * V_172 = & V_4 -> V_119 -> V_4 ;
struct V_206 * V_207 ;
int V_221 = V_10 -> V_222 ;
unsigned int V_103 ;
unsigned int V_104 ;
unsigned int V_176 ;
do {
F_5 ( V_4 , V_66 , V_177 ) ;
V_207 = & V_10 -> V_220 [ V_221 ] ;
V_103 = F_3 ( V_4 , V_223 ) - V_207 -> V_209 ;
V_104 = V_207 -> V_212 ;
V_103 = F_117 ( V_103 , V_207 -> V_210 ) ;
if ( F_118 ( V_103 != V_104 ) ) {
F_119 ( V_4 -> V_45 , V_207 -> V_209 ,
V_207 -> V_210 , V_168 ) ;
V_176 = V_103 - V_104 ;
F_86 ( V_172 , V_207 -> V_106 + V_207 -> V_212 ,
V_176 ) ;
F_106 ( V_4 -> V_45 , V_207 -> V_209 ,
V_207 -> V_210 , V_168 ) ;
V_4 -> V_110 . V_180 += V_176 ;
V_207 -> V_212 = V_103 ;
}
if ( V_103 >= V_207 -> V_210 ) {
V_207 -> V_212 = 0 ;
F_5 ( V_4 , V_224 , V_207 -> V_209 ) ;
F_5 ( V_4 , V_225 , V_207 -> V_210 ) ;
V_221 = ! V_221 ;
V_10 -> V_222 = V_221 ;
}
} while ( V_103 >= V_207 -> V_210 );
F_87 ( & V_4 -> V_128 ) ;
F_88 ( V_172 ) ;
F_89 ( & V_4 -> V_128 ) ;
F_5 ( V_4 , V_53 ,
V_80 | V_81 ) ;
}
static int F_120 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_219 ;
for ( V_219 = 0 ; V_219 < 2 ; V_219 ++ ) {
struct V_206 * V_207 = & V_10 -> V_220 [ V_219 ] ;
V_207 -> V_106 = F_121 ( V_226 , V_227 ) ;
if ( V_207 -> V_106 == NULL ) {
if ( V_219 != 0 ) {
F_104 ( V_4 -> V_45 ,
V_10 -> V_220 [ 0 ] . V_209 ,
V_226 ,
V_168 ) ;
F_115 ( V_10 -> V_220 [ 0 ] . V_106 ) ;
}
V_10 -> V_11 = 0 ;
return - V_228 ;
}
V_207 -> V_209 = F_108 ( V_4 -> V_45 ,
V_207 -> V_106 ,
V_226 ,
V_168 ) ;
V_207 -> V_210 = V_226 ;
V_207 -> V_212 = 0 ;
}
V_10 -> V_222 = 0 ;
F_5 ( V_4 , V_223 , V_10 -> V_220 [ 0 ] . V_209 ) ;
F_5 ( V_4 , V_229 , V_226 ) ;
F_5 ( V_4 , V_224 ,
V_10 -> V_220 [ 1 ] . V_209 ) ;
F_5 ( V_4 , V_225 , V_226 ) ;
return 0 ;
}
static void F_122 ( unsigned long V_187 )
{
struct V_2 * V_4 = (struct V_2 * ) V_187 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_89 ( & V_4 -> V_128 ) ;
V_10 -> V_230 ( V_4 ) ;
F_87 ( & V_4 -> V_128 ) ;
}
static void F_123 ( unsigned long V_187 )
{
struct V_2 * V_4 = (struct V_2 * ) V_187 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_89 ( & V_4 -> V_128 ) ;
V_10 -> V_231 ( V_4 ) ;
F_87 ( & V_4 -> V_128 ) ;
}
static void F_124 ( struct V_1 * V_10 ,
struct V_232 * V_233 )
{
struct V_234 * V_235 = V_233 -> V_45 . V_236 ;
struct V_237 * V_238 = F_125 ( & V_233 -> V_45 ) ;
if ( V_235 ) {
if ( F_126 ( V_235 , L_15 ) ) {
if ( F_126 ( V_235 , L_16 ) ) {
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
if ( F_126 ( V_235 , L_17 ) ) {
if ( F_126 ( V_235 , L_16 ) ) {
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
V_10 -> V_11 = V_238 -> V_14 ;
V_10 -> V_12 = V_238 -> V_13 ;
V_10 -> V_14 = false ;
V_10 -> V_13 = false ;
}
}
static void F_127 ( struct V_2 * V_4 ,
struct V_232 * V_233 )
{
struct V_234 * V_235 = V_233 -> V_45 . V_236 ;
struct V_237 * V_238 = F_125 ( & V_233 -> V_45 ) ;
if ( V_235 ) {
struct V_35 * V_36 = & V_4 -> V_42 ;
T_1 V_239 [ 2 ] ;
if ( F_128 ( V_235 , L_18 ,
V_239 , 2 ) == 0 ) {
V_36 -> V_240 = V_239 [ 0 ] ;
V_36 -> V_48 = V_239 [ 1 ] ;
V_36 -> V_43 = 0 ;
}
if ( F_129 ( V_235 , L_19 , NULL ) )
V_36 -> V_43 |= V_74 ;
if ( F_129 ( V_235 , L_20 ,
NULL ) )
V_36 -> V_43 |= V_44 ;
} else {
V_4 -> V_42 = V_238 -> V_42 ;
}
}
static void F_130 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_14 ( V_4 ) ) {
V_10 -> V_241 = & F_90 ;
V_10 -> V_230 = & F_83 ;
V_10 -> V_242 = & F_82 ;
} else if ( F_11 ( V_4 ) ) {
V_10 -> V_241 = & F_120 ;
V_10 -> V_230 = & F_116 ;
V_10 -> V_242 = & F_114 ;
} else {
V_10 -> V_241 = NULL ;
V_10 -> V_230 = & F_109 ;
V_10 -> V_242 = NULL ;
}
if ( F_13 ( V_4 ) ) {
V_10 -> V_243 = & F_68 ;
V_10 -> V_231 = & F_59 ;
V_10 -> V_244 = & F_56 ;
} else if ( F_12 ( V_4 ) ) {
V_10 -> V_243 = & F_107 ;
V_10 -> V_231 = & F_105 ;
V_10 -> V_244 = & F_103 ;
} else {
V_10 -> V_243 = NULL ;
V_10 -> V_231 = & F_44 ;
V_10 -> V_244 = NULL ;
}
}
static void F_131 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_245 = F_3 ( V_4 , V_246 ) ;
T_1 V_247 ;
T_1 V_248 , V_249 , V_250 ;
V_248 = 0x55534152 ;
V_249 = 0x44424755 ;
V_250 = 0x55415254 ;
V_10 -> V_251 = false ;
V_10 -> V_252 = false ;
if ( V_245 == V_250 ) {
F_24 ( V_4 -> V_45 , L_21 ) ;
V_10 -> V_252 = true ;
V_10 -> V_253 = V_254 ;
} else if ( V_245 == V_248 ) {
F_24 ( V_4 -> V_45 , L_22 ) ;
V_10 -> V_251 = true ;
V_10 -> V_252 = true ;
V_10 -> V_253 = V_255 ;
} else if ( V_245 == V_249 ) {
F_24 ( V_4 -> V_45 , L_23 ) ;
} else {
V_247 = F_3 ( V_4 , V_256 ) ;
switch ( V_247 ) {
case 0x302 :
case 0x10213 :
F_24 ( V_4 -> V_45 , L_24 ) ;
V_10 -> V_251 = true ;
V_10 -> V_252 = true ;
V_10 -> V_253 = V_255 ;
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
struct V_232 * V_233 = F_133 ( V_4 -> V_45 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_257 * V_258 = V_4 -> V_119 -> V_4 . V_258 ;
int V_259 ;
F_5 ( V_4 , V_38 , - 1 ) ;
V_10 -> V_88 = false ;
V_259 = F_134 ( V_4 -> V_196 , F_101 ,
V_260 | V_261 ,
V_258 ? V_258 -> V_245 : L_27 , V_4 ) ;
if ( V_259 ) {
F_65 ( V_4 -> V_45 , L_28 ) ;
return V_259 ;
}
F_135 ( & V_10 -> V_18 , 0 ) ;
F_136 ( & V_10 -> V_117 , F_122 ,
( unsigned long ) V_4 ) ;
F_136 ( & V_10 -> V_134 , F_123 ,
( unsigned long ) V_4 ) ;
F_124 ( V_10 , V_233 ) ;
F_130 ( V_4 ) ;
if ( V_10 -> V_241 ) {
V_259 = V_10 -> V_241 ( V_4 ) ;
if ( V_259 < 0 )
F_130 ( V_4 ) ;
}
if ( V_10 -> V_243 ) {
V_259 = V_10 -> V_243 ( V_4 ) ;
if ( V_259 < 0 )
F_130 ( V_4 ) ;
}
if ( V_10 -> V_15 ) {
unsigned int V_262 = V_263 ;
unsigned int V_264 = V_263 ;
unsigned int V_265 ;
F_5 ( V_4 , V_66 ,
V_266 |
V_267 |
V_268 ) ;
if ( F_13 ( V_4 ) )
V_262 = V_269 ;
V_265 = F_137 ( V_262 ) | F_138 ( V_264 ) ;
if ( V_10 -> V_270 &&
V_10 -> V_271 )
V_265 |= V_272 |
F_139 ( V_10 -> V_270 ) |
F_140 ( V_10 -> V_271 ) ;
F_5 ( V_4 , V_273 , V_265 ) ;
}
V_10 -> V_192 = F_19 ( V_4 ) ;
F_5 ( V_4 , V_66 , V_78 | V_274 ) ;
F_5 ( V_4 , V_66 , V_77 | V_79 ) ;
F_141 ( & V_10 -> V_188 ,
F_92 ,
( unsigned long ) V_4 ) ;
if ( F_11 ( V_4 ) ) {
if ( ! V_10 -> V_252 ) {
F_93 ( & V_10 -> V_188 ,
V_189 + F_94 ( V_4 ) ) ;
} else {
F_5 ( V_4 , V_10 -> V_253 ,
V_275 ) ;
F_5 ( V_4 , V_66 , V_177 ) ;
F_5 ( V_4 , V_53 ,
V_80 | V_81 ) ;
}
F_5 ( V_4 , V_71 , V_83 ) ;
} else if ( F_14 ( V_4 ) ) {
if ( ! V_10 -> V_252 ) {
F_93 ( & V_10 -> V_188 ,
V_189 + F_94 ( V_4 ) ) ;
} else {
F_5 ( V_4 , V_10 -> V_253 ,
V_275 ) ;
F_5 ( V_4 , V_66 , V_177 ) ;
F_5 ( V_4 , V_53 ,
V_81 ) ;
}
} else {
F_5 ( V_4 , V_53 , V_84 ) ;
}
return 0 ;
}
static void F_142 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_12 ( V_4 ) ) {
F_5 ( V_4 , V_211 , 0 ) ;
V_10 -> V_208 . V_212 = 0 ;
}
V_10 -> V_129 = 0 ;
}
static void F_143 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_35 ( V_4 ) ;
F_5 ( V_4 , V_38 , - 1 ) ;
F_144 ( & V_10 -> V_18 ) ;
F_145 ( & V_10 -> V_188 ) ;
F_146 ( V_4 -> V_196 ) ;
F_147 ( & V_10 -> V_117 ) ;
F_147 ( & V_10 -> V_134 ) ;
F_32 ( V_4 ) ;
F_29 ( V_4 ) ;
F_5 ( V_4 , V_66 , V_78 ) ;
if ( V_10 -> V_242 )
V_10 -> V_242 ( V_4 ) ;
if ( V_10 -> V_244 )
V_10 -> V_244 ( V_4 ) ;
V_10 -> V_100 . V_103 = 0 ;
V_10 -> V_100 . V_104 = 0 ;
F_148 ( V_4 -> V_196 , V_4 ) ;
F_142 ( V_4 ) ;
}
static void F_149 ( struct V_2 * V_4 , unsigned int V_119 ,
unsigned int V_276 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
switch ( V_119 ) {
case 0 :
F_150 ( V_10 -> V_277 ) ;
F_5 ( V_4 , V_53 , V_10 -> V_278 ) ;
break;
case 3 :
V_10 -> V_278 = F_3 ( V_4 , V_200 ) ;
F_5 ( V_4 , V_38 , - 1 ) ;
F_151 ( V_10 -> V_277 ) ;
break;
default:
F_65 ( V_4 -> V_45 , L_29 , V_119 ) ;
}
}
static void F_152 ( struct V_2 * V_4 , struct V_279 * V_280 ,
struct V_279 * V_281 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned long V_43 ;
unsigned int V_282 , V_37 , V_283 , V_284 , V_285 , div , V_286 , V_287 = 0 ;
V_37 = V_282 = F_3 ( V_4 , V_40 ) ;
V_37 &= ~ ( V_288 | V_289 | V_290 |
V_291 | V_41 ) ;
V_285 = F_153 ( V_4 , V_280 , V_281 , 0 , V_4 -> V_292 / 16 ) ;
switch ( V_280 -> V_293 & V_294 ) {
case V_295 :
V_37 |= V_296 ;
break;
case V_297 :
V_37 |= V_298 ;
break;
case V_299 :
V_37 |= V_300 ;
break;
default:
V_37 |= V_301 ;
break;
}
if ( V_280 -> V_293 & V_302 )
V_37 |= V_303 ;
if ( V_280 -> V_293 & V_304 ) {
if ( V_280 -> V_293 & V_305 ) {
if ( V_280 -> V_293 & V_306 )
V_37 |= V_307 ;
else
V_37 |= V_308 ;
} else if ( V_280 -> V_293 & V_306 )
V_37 |= V_309 ;
else
V_37 |= V_310 ;
} else
V_37 |= V_311 ;
F_50 ( & V_4 -> V_128 , V_43 ) ;
V_4 -> V_82 = V_114 ;
if ( V_280 -> V_312 & V_313 )
V_4 -> V_82 |= ( V_109 | V_108 ) ;
if ( V_280 -> V_312 & ( V_314 | V_315 | V_316 ) )
V_4 -> V_82 |= V_107 ;
if ( F_11 ( V_4 ) )
F_5 ( V_4 , V_53 , V_4 -> V_82 ) ;
V_4 -> V_317 = 0 ;
if ( V_280 -> V_312 & V_318 )
V_4 -> V_317 |= ( V_109 | V_108 ) ;
if ( V_280 -> V_312 & V_314 ) {
V_4 -> V_317 |= V_107 ;
if ( V_280 -> V_312 & V_318 )
V_4 -> V_317 |= V_114 ;
}
F_154 ( V_4 , V_280 -> V_293 , V_285 ) ;
V_283 = F_3 ( V_4 , V_200 ) ;
F_5 ( V_4 , V_38 , - 1 ) ;
F_5 ( V_4 , V_66 , V_73 | V_85 ) ;
if ( V_4 -> V_42 . V_43 & V_44 ) {
F_5 ( V_4 , V_47 ,
V_4 -> V_42 . V_48 ) ;
V_37 |= V_49 ;
} else if ( V_280 -> V_293 & V_319 ) {
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
if ( ( V_282 & V_41 ) != ( V_37 & V_41 ) ) {
unsigned int V_321 ;
if ( ( V_37 & V_41 ) == V_59 ) {
V_321 = V_61 ;
} else {
V_321 = V_60 ;
}
F_5 ( V_4 , V_66 , V_321 ) ;
}
if ( V_10 -> V_251 ) {
div = F_155 ( V_4 -> V_292 , V_285 * 2 ) ;
V_286 = div >> 3 ;
V_287 = div & V_322 ;
} else {
V_286 = F_156 ( V_4 , V_285 ) ;
}
if ( V_286 > 65535 ) {
V_286 /= 8 ;
V_37 |= V_323 ;
}
V_284 = V_286 | V_287 << V_324 ;
F_5 ( V_4 , V_325 , V_284 ) ;
F_5 ( V_4 , V_66 , V_78 | V_274 ) ;
F_5 ( V_4 , V_66 , V_77 | V_79 ) ;
F_5 ( V_4 , V_53 , V_283 ) ;
if ( F_157 ( V_4 , V_280 -> V_293 ) )
F_33 ( V_4 ) ;
else
F_35 ( V_4 ) ;
F_55 ( & V_4 -> V_128 , V_43 ) ;
}
static void F_158 ( struct V_2 * V_4 , struct V_279 * V_280 )
{
if ( V_280 -> V_326 == V_327 ) {
V_4 -> V_43 |= V_328 ;
F_52 ( & V_4 -> V_128 ) ;
F_33 ( V_4 ) ;
F_54 ( & V_4 -> V_128 ) ;
} else {
V_4 -> V_43 &= ~ V_328 ;
if ( ! F_157 ( V_4 , V_280 -> V_293 ) ) {
F_52 ( & V_4 -> V_128 ) ;
F_35 ( V_4 ) ;
F_54 ( & V_4 -> V_128 ) ;
}
}
}
static const char * F_159 ( struct V_2 * V_4 )
{
return ( V_4 -> type == V_329 ) ? L_30 : NULL ;
}
static void F_160 ( struct V_2 * V_4 )
{
struct V_232 * V_233 = F_133 ( V_4 -> V_45 ) ;
int V_330 = V_233 -> V_331 [ 0 ] . V_332 - V_233 -> V_331 [ 0 ] . V_333 + 1 ;
F_161 ( V_4 -> V_164 , V_330 ) ;
if ( V_4 -> V_43 & V_334 ) {
F_162 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
}
static int F_163 ( struct V_2 * V_4 )
{
struct V_232 * V_233 = F_133 ( V_4 -> V_45 ) ;
int V_330 = V_233 -> V_331 [ 0 ] . V_332 - V_233 -> V_331 [ 0 ] . V_333 + 1 ;
if ( ! F_164 ( V_4 -> V_164 , V_330 , L_27 ) )
return - V_335 ;
if ( V_4 -> V_43 & V_334 ) {
V_4 -> V_6 = F_165 ( V_4 -> V_164 , V_330 ) ;
if ( V_4 -> V_6 == NULL ) {
F_161 ( V_4 -> V_164 , V_330 ) ;
return - V_228 ;
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
V_20 = - V_133 ;
if ( V_4 -> V_196 != V_338 -> V_196 )
V_20 = - V_133 ;
if ( V_338 -> V_340 != V_341 )
V_20 = - V_133 ;
if ( V_4 -> V_292 / 16 != V_338 -> V_342 )
V_20 = - V_133 ;
if ( V_4 -> V_164 != ( unsigned long ) V_338 -> V_343 )
V_20 = - V_133 ;
if ( V_4 -> V_344 != V_338 -> V_4 )
V_20 = - V_133 ;
if ( V_338 -> V_345 != 0 )
V_20 = - V_133 ;
return V_20 ;
}
static int F_168 ( struct V_2 * V_4 )
{
while ( ! ( F_3 ( V_4 , V_21 ) & V_84 ) )
F_169 () ;
return F_7 ( V_4 ) ;
}
static void F_170 ( struct V_2 * V_4 , unsigned char V_97 )
{
while ( ! ( F_3 ( V_4 , V_21 ) & V_52 ) )
F_169 () ;
F_8 ( V_4 , V_97 ) ;
}
static int F_171 ( struct V_1 * V_10 ,
struct V_232 * V_233 )
{
int V_20 ;
struct V_2 * V_4 = & V_10 -> V_3 ;
struct V_237 * V_238 = F_125 ( & V_233 -> V_45 ) ;
F_124 ( V_10 , V_233 ) ;
F_130 ( V_4 ) ;
F_127 ( V_4 , V_233 ) ;
V_4 -> V_346 = V_347 ;
V_4 -> V_43 = V_348 ;
V_4 -> V_349 = & V_350 ;
V_4 -> V_351 = 1 ;
V_4 -> V_45 = & V_233 -> V_45 ;
V_4 -> V_164 = V_233 -> V_331 [ 0 ] . V_333 ;
V_4 -> V_196 = V_233 -> V_331 [ 1 ] . V_333 ;
V_4 -> V_352 = F_23 ;
memset ( & V_10 -> V_100 , 0 , sizeof( V_10 -> V_100 ) ) ;
if ( V_238 && V_238 -> V_353 ) {
V_4 -> V_6 = V_238 -> V_353 ;
} else {
V_4 -> V_43 |= V_334 ;
V_4 -> V_6 = NULL ;
}
if ( ! V_10 -> V_277 ) {
V_10 -> V_277 = F_172 ( & V_233 -> V_45 , L_31 ) ;
if ( F_173 ( V_10 -> V_277 ) ) {
V_20 = F_174 ( V_10 -> V_277 ) ;
V_10 -> V_277 = NULL ;
return V_20 ;
}
V_20 = F_150 ( V_10 -> V_277 ) ;
if ( V_20 ) {
F_175 ( V_10 -> V_277 ) ;
V_10 -> V_277 = NULL ;
return V_20 ;
}
V_4 -> V_292 = F_176 ( V_10 -> V_277 ) ;
F_151 ( V_10 -> V_277 ) ;
}
if ( V_4 -> V_42 . V_43 & V_44 )
V_10 -> V_39 = V_46 ;
else if ( F_12 ( V_4 ) ) {
V_4 -> V_351 = V_226 ;
V_10 -> V_39 = V_50 | V_51 ;
} else {
V_10 -> V_39 = V_52 ;
}
return 0 ;
}
static void F_177 ( struct V_2 * V_4 , int V_97 )
{
while ( ! ( F_3 ( V_4 , V_21 ) & V_52 ) )
F_169 () ;
F_8 ( V_4 , V_97 ) ;
}
static void F_178 ( struct V_354 * V_355 , const char * V_356 , T_3 V_176 )
{
struct V_2 * V_4 = & V_357 [ V_355 -> V_358 ] . V_3 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_19 , V_283 ;
unsigned int V_208 ;
V_283 = F_3 ( V_4 , V_200 ) ;
F_5 ( V_4 , V_38 ,
V_84 | V_10 -> V_39 ) ;
V_208 = F_3 ( V_4 , V_75 ) & V_76 ;
F_5 ( V_4 , V_71 , V_72 ) ;
F_5 ( V_4 , V_66 , V_77 ) ;
F_179 ( V_4 , V_356 , V_176 , F_177 ) ;
do {
V_19 = F_3 ( V_4 , V_21 ) ;
} while ( ! ( V_19 & V_52 ) );
if ( V_208 )
F_5 ( V_4 , V_71 , V_76 ) ;
F_5 ( V_4 , V_53 , V_283 ) ;
}
static void T_9 F_180 ( struct V_2 * V_4 , int * V_285 ,
int * V_112 , int * V_359 )
{
unsigned int V_360 , V_284 ;
V_284 = F_3 ( V_4 , V_325 ) & V_361 ;
if ( ! V_284 )
return;
V_360 = F_3 ( V_4 , V_40 ) & V_289 ;
if ( V_360 == V_301 )
* V_359 = 8 ;
else
* V_359 = 7 ;
V_360 = F_3 ( V_4 , V_40 ) & V_291 ;
if ( V_360 == V_310 )
* V_112 = 'e' ;
else if ( V_360 == V_309 )
* V_112 = 'o' ;
* V_285 = V_4 -> V_292 / ( 16 * ( V_284 - 1 ) ) ;
}
static int T_9 F_181 ( struct V_354 * V_355 , char * V_362 )
{
int V_20 ;
struct V_2 * V_4 = & V_357 [ V_355 -> V_358 ] . V_3 ;
int V_285 = 115200 ;
int V_359 = 8 ;
int V_112 = 'n' ;
int V_363 = 'n' ;
if ( V_4 -> V_6 == NULL ) {
return - V_364 ;
}
V_20 = F_150 ( V_357 [ V_355 -> V_358 ] . V_277 ) ;
if ( V_20 )
return V_20 ;
F_5 ( V_4 , V_38 , - 1 ) ;
F_5 ( V_4 , V_66 , V_78 | V_274 ) ;
F_5 ( V_4 , V_66 , V_77 | V_79 ) ;
if ( V_362 )
F_182 ( V_362 , & V_285 , & V_112 , & V_359 , & V_363 ) ;
else
F_180 ( V_4 , & V_285 , & V_112 , & V_359 ) ;
return F_183 ( V_4 , V_355 , V_285 , V_112 , V_359 , V_363 ) ;
}
static int T_9 F_184 ( void )
{
int V_20 ;
if ( V_365 ) {
struct V_237 * V_238 =
F_125 ( & V_365 -> V_45 ) ;
int V_366 = V_238 -> V_367 ;
struct V_1 * V_10 = & V_357 [ V_366 ] ;
V_10 -> V_278 = 0 ;
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
static int F_192 ( struct V_232 * V_233 ,
T_10 V_119 )
{
struct V_2 * V_4 = F_193 ( V_233 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_188 ( V_4 ) && V_372 ) {
while ( ! ( F_3 ( V_4 , V_21 ) &
V_46 ) )
F_169 () ;
}
if ( F_188 ( V_4 ) && ! V_372 ) {
V_10 -> V_373 . V_360 = F_3 ( V_4 , V_40 ) ;
V_10 -> V_373 . V_283 = F_3 ( V_4 , V_200 ) ;
V_10 -> V_373 . V_374 = F_3 ( V_4 , V_325 ) ;
V_10 -> V_373 . V_253 = F_3 ( V_4 ,
V_10 -> V_253 ) ;
V_10 -> V_373 . V_375 = F_3 ( V_4 , V_47 ) ;
V_10 -> V_373 . V_265 = F_3 ( V_4 , V_273 ) ;
V_10 -> V_373 . V_376 = F_3 ( V_4 , V_377 ) ;
}
V_10 -> V_378 = F_194 ( & V_233 -> V_45 ) ;
if ( F_189 () ) {
unsigned long V_43 ;
F_50 ( & V_10 -> V_199 , V_43 ) ;
V_10 -> V_201 = true ;
F_55 ( & V_10 -> V_199 , V_43 ) ;
F_195 ( & V_233 -> V_45 , 0 ) ;
}
F_196 ( & V_379 , V_4 ) ;
return 0 ;
}
static int F_197 ( struct V_232 * V_233 )
{
struct V_2 * V_4 = F_193 ( V_233 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned long V_43 ;
if ( F_188 ( V_4 ) && ! V_372 ) {
F_5 ( V_4 , V_40 , V_10 -> V_373 . V_360 ) ;
F_5 ( V_4 , V_53 , V_10 -> V_373 . V_283 ) ;
F_5 ( V_4 , V_325 , V_10 -> V_373 . V_374 ) ;
F_5 ( V_4 , V_10 -> V_253 ,
V_10 -> V_373 . V_253 ) ;
F_5 ( V_4 , V_47 , V_10 -> V_373 . V_375 ) ;
if ( V_10 -> V_15 ) {
F_5 ( V_4 , V_66 , V_266 |
V_267 | V_268 ) ;
F_5 ( V_4 , V_273 ,
V_10 -> V_373 . V_265 ) ;
F_5 ( V_4 , V_380 ,
V_10 -> V_373 . V_376 ) ;
}
F_30 ( V_4 ) ;
}
F_50 ( & V_10 -> V_199 , V_43 ) ;
if ( V_10 -> V_190 ) {
F_95 ( V_4 , V_10 -> V_190 ) ;
F_97 ( V_4 , V_10 -> V_190 ,
V_10 -> V_202 ) ;
F_96 ( V_4 , V_10 -> V_190 ) ;
V_10 -> V_190 = 0 ;
}
V_10 -> V_201 = false ;
F_55 ( & V_10 -> V_199 , V_43 ) ;
F_198 ( & V_379 , V_4 ) ;
F_195 ( & V_233 -> V_45 , V_10 -> V_378 ) ;
return 0 ;
}
static void F_199 ( struct V_1 * V_10 ,
struct V_232 * V_233 )
{
V_10 -> V_15 = 0 ;
V_10 -> V_271 = 0 ;
V_10 -> V_270 = 0 ;
if ( F_200 ( V_233 -> V_45 . V_236 ,
L_32 ,
& V_10 -> V_15 ) )
return;
if ( ! V_10 -> V_15 )
return;
if ( V_10 -> V_15 < V_381 ) {
V_10 -> V_15 = 0 ;
F_65 ( & V_233 -> V_45 , L_33 ) ;
return;
}
V_10 -> V_270 = F_201 ( int , V_10 -> V_15 >> 1 ,
V_10 -> V_15 - V_382 ) ;
V_10 -> V_271 = F_201 ( int , V_10 -> V_15 >> 2 ,
V_10 -> V_15 - V_383 ) ;
F_72 ( & V_233 -> V_45 , L_34 ,
V_10 -> V_15 ) ;
F_24 ( & V_233 -> V_45 , L_35 ,
V_10 -> V_270 ) ;
F_24 ( & V_233 -> V_45 , L_36 ,
V_10 -> V_271 ) ;
}
static int F_202 ( struct V_232 * V_233 )
{
struct V_1 * V_10 ;
struct V_234 * V_235 = V_233 -> V_45 . V_236 ;
struct V_237 * V_238 = F_125 ( & V_233 -> V_45 ) ;
void * V_187 ;
int V_20 = - V_364 ;
bool V_384 ;
F_203 ( V_105 & ( V_105 - 1 ) ) ;
if ( V_235 )
V_20 = F_204 ( V_235 , L_37 ) ;
else
if ( V_238 )
V_20 = V_238 -> V_367 ;
if ( V_20 < 0 )
V_20 = F_205 ( V_385 , V_386 ) ;
if ( V_20 >= V_386 ) {
V_20 = - V_364 ;
goto V_387;
}
if ( F_206 ( V_20 , V_385 ) ) {
V_20 = - V_335 ;
goto V_387;
}
V_10 = & V_357 [ V_20 ] ;
V_10 -> V_278 = 0 ;
V_10 -> V_3 . line = V_20 ;
F_199 ( V_10 , V_233 ) ;
F_135 ( & V_10 -> V_18 , 0 ) ;
F_74 ( & V_10 -> V_199 ) ;
V_20 = F_171 ( V_10 , V_233 ) ;
if ( V_20 )
goto V_388;
V_10 -> V_22 = F_207 ( & V_10 -> V_3 , 0 ) ;
if ( F_173 ( V_10 -> V_22 ) ) {
V_20 = F_174 ( V_10 -> V_22 ) ;
goto V_388;
}
if ( ! F_11 ( & V_10 -> V_3 ) ) {
V_20 = - V_228 ;
V_187 = F_121 ( sizeof( struct V_101 )
* V_105 , V_227 ) ;
if ( ! V_187 )
goto V_389;
V_10 -> V_100 . V_106 = V_187 ;
}
V_384 = V_10 -> V_3 . V_42 . V_43 & V_44 ;
V_20 = F_208 ( & V_379 , & V_10 -> V_3 ) ;
if ( V_20 )
goto V_390;
#ifdef F_209
if ( F_188 ( & V_10 -> V_3 )
&& V_391 -> V_43 & V_370 ) {
F_151 ( V_10 -> V_277 ) ;
}
#endif
F_210 ( & V_233 -> V_45 , 1 ) ;
F_211 ( V_233 , V_10 ) ;
F_150 ( V_10 -> V_277 ) ;
if ( V_384 ) {
F_5 ( & V_10 -> V_3 , V_40 ,
V_320 ) ;
F_5 ( & V_10 -> V_3 , V_66 ,
V_60 ) ;
}
F_131 ( & V_10 -> V_3 ) ;
F_151 ( V_10 -> V_277 ) ;
return 0 ;
V_390:
F_115 ( V_10 -> V_100 . V_106 ) ;
V_10 -> V_100 . V_106 = NULL ;
V_389:
if ( ! F_188 ( & V_10 -> V_3 ) ) {
F_175 ( V_10 -> V_277 ) ;
V_10 -> V_277 = NULL ;
}
V_388:
F_212 ( V_10 -> V_3 . line , V_385 ) ;
V_387:
return V_20 ;
}
static int F_213 ( struct V_232 * V_233 )
{
struct V_2 * V_4 = F_193 ( V_233 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_20 = 0 ;
F_147 ( & V_10 -> V_117 ) ;
F_147 ( & V_10 -> V_134 ) ;
F_210 ( & V_233 -> V_45 , 0 ) ;
V_20 = F_214 ( & V_379 , V_4 ) ;
F_115 ( V_10 -> V_100 . V_106 ) ;
F_212 ( V_4 -> line , V_385 ) ;
F_175 ( V_10 -> V_277 ) ;
V_10 -> V_277 = NULL ;
return V_20 ;
}
static int T_9 F_215 ( void )
{
int V_20 ;
V_20 = F_216 ( & V_379 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_217 ( & V_392 ) ;
if ( V_20 )
F_218 ( & V_379 ) ;
return V_20 ;
}
