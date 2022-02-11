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
if ( ! F_18 ( V_10 -> V_18 , V_19 ) )
V_81 |= V_83 ;
if ( ! F_18 ( V_10 -> V_18 , V_22 ) )
V_81 |= V_84 ;
if ( ! F_18 ( V_10 -> V_18 , V_25 ) )
V_81 |= V_85 ;
if ( ! F_18 ( V_10 -> V_18 , V_28 ) )
V_81 |= V_86 ;
F_5 ( V_4 , V_49 , V_81 ) ;
F_30 ( V_10 -> V_18 ) ;
}
static void F_31 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
T_4 V_87 = 0 ;
if ( ! V_10 -> V_82 )
return;
V_10 -> V_82 = false ;
F_32 ( V_10 -> V_18 ) ;
if ( ! F_18 ( V_10 -> V_18 , V_19 ) )
V_87 |= V_83 ;
if ( ! F_18 ( V_10 -> V_18 , V_22 ) )
V_87 |= V_84 ;
if ( ! F_18 ( V_10 -> V_18 , V_25 ) )
V_87 |= V_85 ;
if ( ! F_18 ( V_10 -> V_18 , V_28 ) )
V_87 |= V_86 ;
F_5 ( V_4 , V_34 , V_87 ) ;
}
static void F_33 ( struct V_2 * V_4 , int V_88 )
{
if ( V_88 != 0 )
F_5 ( V_4 , V_62 , V_89 ) ;
else
F_5 ( V_4 , V_62 , V_90 ) ;
}
static void
F_34 ( struct V_2 * V_4 , unsigned int V_15 ,
unsigned int V_91 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_92 * V_93 = & V_10 -> V_94 ;
struct V_95 * V_96 ;
if ( ! F_35 ( V_93 -> V_97 , V_93 -> V_98 , V_99 ) )
return;
V_96 = & ( (struct V_95 * ) V_93 -> V_100 ) [ V_93 -> V_97 ] ;
V_96 -> V_15 = V_15 ;
V_96 -> V_91 = V_91 ;
F_36 () ;
V_93 -> V_97 = ( V_93 -> V_97 + 1 ) & ( V_99 - 1 ) ;
}
static void F_37 ( struct V_2 * V_4 , unsigned int V_15 )
{
F_5 ( V_4 , V_62 , V_72 ) ;
if ( V_15 & V_101 ) {
V_15 &= ~ ( V_102 | V_103 ) ;
V_4 -> V_104 . V_105 ++ ;
}
if ( V_15 & V_102 )
V_4 -> V_104 . V_106 ++ ;
if ( V_15 & V_103 )
V_4 -> V_104 . V_107 ++ ;
if ( V_15 & V_108 )
V_4 -> V_104 . V_109 ++ ;
}
static void F_38 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_15 , V_91 ;
V_15 = F_3 ( V_4 , V_17 ) ;
while ( V_15 & V_78 ) {
V_91 = F_7 ( V_4 ) ;
if ( F_39 ( V_15 & ( V_102 | V_103
| V_108 | V_101 )
|| V_10 -> V_110 ) ) {
F_5 ( V_4 , V_62 , V_72 ) ;
if ( V_15 & V_101
&& ! V_10 -> V_110 ) {
V_10 -> V_110 = 1 ;
F_5 ( V_4 , V_49 ,
V_101 ) ;
} else {
F_5 ( V_4 , V_34 ,
V_101 ) ;
V_15 &= ~ V_101 ;
V_10 -> V_110 = 0 ;
}
}
F_34 ( V_4 , V_15 , V_91 ) ;
V_15 = F_3 ( V_4 , V_17 ) ;
}
F_40 ( & V_10 -> V_111 ) ;
}
static void F_41 ( struct V_2 * V_4 )
{
struct V_92 * V_112 = & V_4 -> V_113 -> V_112 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( V_4 -> V_114 &&
( F_3 ( V_4 , V_17 ) & V_10 -> V_35 ) ) {
F_8 ( V_4 , V_4 -> V_114 ) ;
V_4 -> V_104 . V_115 ++ ;
V_4 -> V_114 = 0 ;
}
if ( F_42 ( V_112 ) || F_43 ( V_4 ) )
return;
while ( F_3 ( V_4 , V_17 ) &
V_10 -> V_35 ) {
F_8 ( V_4 , V_112 -> V_100 [ V_112 -> V_98 ] ) ;
V_112 -> V_98 = ( V_112 -> V_98 + 1 ) & ( V_116 - 1 ) ;
V_4 -> V_104 . V_115 ++ ;
if ( F_42 ( V_112 ) )
break;
}
if ( F_44 ( V_112 ) < V_117 )
F_45 ( V_4 ) ;
if ( ! F_42 ( V_112 ) )
F_5 ( V_4 , V_49 ,
V_10 -> V_35 ) ;
}
static void F_46 ( void * V_118 )
{
struct V_1 * V_10 = V_118 ;
struct V_2 * V_4 = & V_10 -> V_3 ;
struct V_92 * V_112 = & V_4 -> V_113 -> V_112 ;
struct V_119 * V_120 = V_10 -> V_121 ;
unsigned long V_39 ;
F_47 ( & V_4 -> V_122 , V_39 ) ;
if ( V_120 )
F_48 ( V_120 ) ;
V_112 -> V_98 += V_10 -> V_123 ;
V_112 -> V_98 &= V_116 - 1 ;
V_4 -> V_104 . V_115 += V_10 -> V_123 ;
F_49 ( & V_10 -> V_124 ) ;
F_50 ( V_10 -> V_125 ) ;
V_10 -> V_126 = - V_127 ;
V_10 -> V_125 = NULL ;
F_51 ( & V_10 -> V_124 ) ;
if ( F_44 ( V_112 ) < V_117 )
F_45 ( V_4 ) ;
if ( ! F_42 ( V_112 ) )
F_40 ( & V_10 -> V_111 ) ;
F_52 ( & V_4 -> V_122 , V_39 ) ;
}
static void F_53 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_119 * V_120 = V_10 -> V_121 ;
if ( V_120 ) {
F_48 ( V_120 ) ;
F_54 ( V_120 ) ;
F_55 ( V_4 -> V_41 , & V_10 -> V_128 , 1 ,
V_129 ) ;
}
V_10 -> V_125 = NULL ;
V_10 -> V_121 = NULL ;
V_10 -> V_126 = - V_127 ;
}
static void F_56 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_92 * V_112 = & V_4 -> V_113 -> V_112 ;
struct V_119 * V_120 = V_10 -> V_121 ;
struct V_130 * V_131 ;
struct V_132 V_133 [ 2 ] , * V_134 , * V_128 = & V_10 -> V_128 ;
unsigned int V_123 , V_135 , V_136 , V_137 ;
T_5 V_138 ;
if ( V_10 -> V_125 != NULL )
return;
if ( ! F_42 ( V_112 ) && ! F_43 ( V_4 ) ) {
V_123 = F_57 ( V_112 -> V_97 ,
V_112 -> V_98 ,
V_116 ) ;
if ( V_10 -> V_139 ) {
V_135 = ( V_123 & ~ 0x3 ) ;
V_136 = ( V_123 & 0x3 ) ;
} else {
V_135 = 0 ;
V_136 = V_123 ;
}
F_58 ( V_133 , 2 ) ;
V_137 = 0 ;
V_138 = F_59 ( V_128 ) + V_112 -> V_98 ;
if ( V_135 ) {
V_134 = & V_133 [ V_137 ++ ] ;
F_59 ( V_134 ) = V_138 ;
F_60 ( V_134 ) = V_135 ;
V_138 += V_135 ;
}
if ( V_136 ) {
V_134 = & V_133 [ V_137 ++ ] ;
F_59 ( V_134 ) = V_138 ;
F_60 ( V_134 ) = V_136 ;
}
V_10 -> V_123 = V_123 ;
V_131 = F_61 ( V_120 ,
V_133 ,
V_137 ,
V_140 ,
V_141 |
V_142 ) ;
if ( ! V_131 ) {
F_62 ( V_4 -> V_41 , L_3 ) ;
return;
}
F_63 ( V_4 -> V_41 , V_128 , 1 , V_129 ) ;
V_10 -> V_125 = V_131 ;
V_131 -> V_143 = F_46 ;
V_131 -> V_144 = V_10 ;
V_10 -> V_126 = F_64 ( V_131 ) ;
} else {
if ( V_4 -> V_38 . V_39 & V_40 ) {
F_26 ( V_4 ) ;
}
}
if ( F_44 ( V_112 ) < V_117 )
F_45 ( V_4 ) ;
}
static int F_65 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
T_6 V_145 ;
struct V_146 V_147 ;
int V_16 , V_148 ;
F_66 ( V_145 ) ;
F_67 ( V_149 , V_145 ) ;
V_10 -> V_121 = F_68 ( V_4 -> V_41 , L_4 ) ;
if ( V_10 -> V_121 == NULL )
goto V_150;
F_69 ( V_4 -> V_41 , L_5 ,
F_70 ( V_10 -> V_121 ) ) ;
F_71 ( & V_10 -> V_124 ) ;
F_58 ( & V_10 -> V_128 , 1 ) ;
F_72 ( ! F_73 ( V_4 -> V_113 -> V_112 . V_100 ) ) ;
F_74 ( & V_10 -> V_128 ,
F_75 ( V_4 -> V_113 -> V_112 . V_100 ) ,
V_116 ,
( unsigned long ) V_4 -> V_113 -> V_112 . V_100 & ~ V_151 ) ;
V_148 = F_76 ( V_4 -> V_41 ,
& V_10 -> V_128 ,
1 ,
V_129 ) ;
if ( ! V_148 ) {
F_20 ( V_4 -> V_41 , L_6 ) ;
goto V_150;
} else {
F_20 ( V_4 -> V_41 , L_7 , V_152 ,
F_60 ( & V_10 -> V_128 ) ,
V_4 -> V_113 -> V_112 . V_100 ,
& F_59 ( & V_10 -> V_128 ) ) ;
}
memset ( & V_147 , 0 , sizeof( V_147 ) ) ;
V_147 . V_153 = V_140 ;
V_147 . V_154 = ( V_10 -> V_139 ) ?
V_155 :
V_156 ;
V_147 . V_157 = V_4 -> V_158 + V_9 ;
V_147 . V_159 = 1 ;
V_16 = F_77 ( V_10 -> V_121 ,
& V_147 ) ;
if ( V_16 ) {
F_62 ( V_4 -> V_41 , L_8 ) ;
goto V_150;
}
return 0 ;
V_150:
F_62 ( V_4 -> V_41 , L_9 ) ;
V_10 -> V_13 = 0 ;
if ( V_10 -> V_121 )
F_53 ( V_4 ) ;
return - V_127 ;
}
static void F_78 ( void * V_118 )
{
struct V_2 * V_4 = V_118 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_40 ( & V_10 -> V_111 ) ;
}
static void F_79 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_119 * V_120 = V_10 -> V_160 ;
if ( V_120 ) {
F_48 ( V_120 ) ;
F_54 ( V_120 ) ;
F_55 ( V_4 -> V_41 , & V_10 -> V_161 , 1 ,
V_162 ) ;
}
V_10 -> V_163 = NULL ;
V_10 -> V_160 = NULL ;
V_10 -> V_164 = - V_127 ;
}
static void F_80 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_165 * V_166 = & V_4 -> V_113 -> V_4 ;
struct V_92 * V_93 = & V_10 -> V_94 ;
struct V_119 * V_120 = V_10 -> V_160 ;
struct V_167 V_113 ;
enum V_168 V_169 ;
T_7 V_170 ;
F_5 ( V_4 , V_62 , V_171 ) ;
V_169 = F_81 ( V_120 ,
V_10 -> V_164 ,
& V_113 ) ;
if ( V_169 == V_172 ) {
F_20 ( V_4 -> V_41 , L_10 ) ;
F_5 ( V_4 , V_49 , V_75 ) ;
F_40 ( & V_10 -> V_111 ) ;
return;
}
F_82 ( V_4 -> V_41 ,
& V_10 -> V_161 ,
1 ,
V_162 ) ;
V_93 -> V_97 = F_60 ( & V_10 -> V_161 ) - V_113 . V_173 ;
F_72 ( V_93 -> V_97 > F_60 ( & V_10 -> V_161 ) ) ;
if ( V_93 -> V_97 < V_93 -> V_98 ) {
V_170 = F_60 ( & V_10 -> V_161 ) - V_93 -> V_98 ;
F_83 ( V_166 , V_93 -> V_100 + V_93 -> V_98 , V_170 ) ;
V_93 -> V_98 = 0 ;
V_4 -> V_104 . V_174 += V_170 ;
}
if ( V_93 -> V_98 < V_93 -> V_97 ) {
V_170 = V_93 -> V_97 - V_93 -> V_98 ;
F_83 ( V_166 , V_93 -> V_100 + V_93 -> V_98 , V_170 ) ;
if ( V_93 -> V_97 >= F_60 ( & V_10 -> V_161 ) )
V_93 -> V_97 = 0 ;
V_93 -> V_98 = V_93 -> V_97 ;
V_4 -> V_104 . V_174 += V_170 ;
}
F_63 ( V_4 -> V_41 ,
& V_10 -> V_161 ,
1 ,
V_162 ) ;
F_84 ( & V_4 -> V_122 ) ;
F_85 ( V_166 ) ;
F_86 ( & V_4 -> V_122 ) ;
F_5 ( V_4 , V_49 , V_75 ) ;
}
static int F_87 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_130 * V_131 ;
T_6 V_145 ;
struct V_146 V_147 ;
struct V_92 * V_93 ;
int V_16 , V_148 ;
V_93 = & V_10 -> V_94 ;
F_66 ( V_145 ) ;
F_67 ( V_175 , V_145 ) ;
V_10 -> V_160 = F_68 ( V_4 -> V_41 , L_11 ) ;
if ( V_10 -> V_160 == NULL )
goto V_150;
F_69 ( V_4 -> V_41 , L_12 ,
F_70 ( V_10 -> V_160 ) ) ;
F_71 ( & V_10 -> V_176 ) ;
F_58 ( & V_10 -> V_161 , 1 ) ;
F_72 ( ! F_73 ( V_93 -> V_100 ) ) ;
F_74 ( & V_10 -> V_161 ,
F_75 ( V_93 -> V_100 ) ,
sizeof( struct V_95 ) * V_99 ,
( unsigned long ) V_93 -> V_100 & ~ V_151 ) ;
V_148 = F_76 ( V_4 -> V_41 ,
& V_10 -> V_161 ,
1 ,
V_162 ) ;
if ( ! V_148 ) {
F_20 ( V_4 -> V_41 , L_6 ) ;
goto V_150;
} else {
F_20 ( V_4 -> V_41 , L_7 , V_152 ,
F_60 ( & V_10 -> V_161 ) ,
V_93 -> V_100 ,
& F_59 ( & V_10 -> V_161 ) ) ;
}
memset ( & V_147 , 0 , sizeof( V_147 ) ) ;
V_147 . V_153 = V_177 ;
V_147 . V_178 = V_156 ;
V_147 . V_179 = V_4 -> V_158 + V_8 ;
V_147 . V_180 = 1 ;
V_16 = F_77 ( V_10 -> V_160 ,
& V_147 ) ;
if ( V_16 ) {
F_62 ( V_4 -> V_41 , L_13 ) ;
goto V_150;
}
V_131 = F_88 ( V_10 -> V_160 ,
F_59 ( & V_10 -> V_161 ) ,
F_60 ( & V_10 -> V_161 ) ,
F_60 ( & V_10 -> V_161 ) / 2 ,
V_177 ,
V_141 ) ;
V_131 -> V_143 = F_78 ;
V_131 -> V_144 = V_4 ;
V_10 -> V_163 = V_131 ;
V_10 -> V_164 = F_64 ( V_131 ) ;
return 0 ;
V_150:
F_62 ( V_4 -> V_41 , L_14 ) ;
V_10 -> V_14 = 0 ;
if ( V_10 -> V_160 )
F_79 ( V_4 ) ;
return - V_127 ;
}
static void F_89 ( unsigned long V_181 )
{
struct V_2 * V_4 = ( void * ) V_181 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_40 ( & V_10 -> V_111 ) ;
F_90 ( & V_10 -> V_182 , V_183 + F_91 ( V_4 ) ) ;
}
static void
F_92 ( struct V_2 * V_4 , unsigned int V_184 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_11 ( V_4 ) ) {
if ( V_184 & ( V_74 | V_75 ) ) {
F_5 ( V_4 , V_34 ,
( V_74 | V_75 ) ) ;
F_40 ( & V_10 -> V_111 ) ;
}
if ( V_184 & ( V_101 | V_108 |
V_103 | V_102 ) )
F_37 ( V_4 , V_184 ) ;
}
if ( F_14 ( V_4 ) ) {
if ( V_184 & V_75 ) {
F_5 ( V_4 , V_34 ,
V_75 ) ;
F_40 ( & V_10 -> V_111 ) ;
}
}
if ( V_184 & V_78 )
F_38 ( V_4 ) ;
else if ( V_184 & V_101 ) {
F_5 ( V_4 , V_62 , V_72 ) ;
F_5 ( V_4 , V_34 , V_101 ) ;
V_10 -> V_110 = 0 ;
}
}
static void
F_93 ( struct V_2 * V_4 , unsigned int V_184 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( V_184 & V_10 -> V_35 ) {
F_5 ( V_4 , V_34 ,
V_10 -> V_35 ) ;
F_40 ( & V_10 -> V_111 ) ;
}
}
static void
F_94 ( struct V_2 * V_4 , unsigned int V_184 ,
unsigned int V_15 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( V_184 & ( V_85 | V_84 | V_86
| V_83 ) ) {
V_10 -> V_185 = V_15 ;
V_10 -> V_186 = V_10 -> V_185 ^
V_10 -> V_187 ;
V_10 -> V_187 = V_15 ;
F_40 ( & V_10 -> V_111 ) ;
}
}
static T_8 F_95 ( int V_188 , void * V_189 )
{
struct V_2 * V_4 = V_189 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_15 , V_184 , V_145 , V_190 = 0 ;
F_86 ( & V_10 -> V_191 ) ;
do {
V_15 = F_15 ( V_4 ) ;
V_145 = F_3 ( V_4 , V_192 ) ;
V_184 = V_15 & V_145 ;
if ( ! V_184 )
break;
if ( V_10 -> V_193 ) {
V_10 -> V_184 |= V_184 ;
V_10 -> V_194 = V_15 ;
F_5 ( V_4 , V_34 , V_145 ) ;
F_96 () ;
break;
}
F_92 ( V_4 , V_184 ) ;
F_94 ( V_4 , V_184 , V_15 ) ;
F_93 ( V_4 , V_184 ) ;
} while ( V_190 ++ < V_195 );
F_84 ( & V_10 -> V_191 ) ;
return V_190 ? V_196 : V_197 ;
}
static void F_97 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_198 * V_199 = & V_10 -> V_200 ;
F_98 ( V_4 -> V_41 ,
V_199 -> V_201 ,
V_199 -> V_202 ,
V_129 ) ;
}
static void F_99 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_92 * V_112 = & V_4 -> V_113 -> V_112 ;
struct V_198 * V_199 = & V_10 -> V_200 ;
int V_170 ;
if ( F_3 ( V_4 , V_203 ) )
return;
V_112 -> V_98 += V_199 -> V_204 ;
V_112 -> V_98 &= V_116 - 1 ;
V_4 -> V_104 . V_115 += V_199 -> V_204 ;
V_199 -> V_204 = 0 ;
F_5 ( V_4 , V_67 , V_68 ) ;
if ( ! F_42 ( V_112 ) && ! F_43 ( V_4 ) ) {
F_100 ( V_4 -> V_41 ,
V_199 -> V_201 ,
V_199 -> V_202 ,
V_129 ) ;
V_170 = F_57 ( V_112 -> V_97 , V_112 -> V_98 , V_116 ) ;
V_199 -> V_204 = V_170 ;
F_5 ( V_4 , V_205 ,
V_199 -> V_201 + V_112 -> V_98 ) ;
F_5 ( V_4 , V_203 , V_170 ) ;
F_5 ( V_4 , V_67 , V_71 ) ;
F_5 ( V_4 , V_49 ,
V_10 -> V_35 ) ;
} else {
if ( ( V_4 -> V_38 . V_39 & V_40 ) &&
! ( V_4 -> V_38 . V_39 & V_69 ) ) {
F_26 ( V_4 ) ;
}
}
if ( F_44 ( V_112 ) < V_117 )
F_45 ( V_4 ) ;
}
static int F_101 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_198 * V_199 = & V_10 -> V_200 ;
struct V_92 * V_112 = & V_4 -> V_113 -> V_112 ;
V_199 -> V_100 = V_112 -> V_100 ;
V_199 -> V_201 = F_102 ( V_4 -> V_41 ,
V_199 -> V_100 ,
V_116 ,
V_129 ) ;
V_199 -> V_202 = V_116 ;
V_199 -> V_204 = 0 ;
return 0 ;
}
static void F_103 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_92 * V_93 = & V_10 -> V_94 ;
unsigned int V_206 ;
unsigned int V_15 ;
while ( V_93 -> V_97 != V_93 -> V_98 ) {
struct V_95 V_96 ;
F_104 () ;
V_96 = ( (struct V_95 * ) V_93 -> V_100 ) [ V_93 -> V_98 ] ;
V_93 -> V_98 = ( V_93 -> V_98 + 1 ) & ( V_99 - 1 ) ;
V_4 -> V_104 . V_174 ++ ;
V_15 = V_96 . V_15 ;
V_206 = V_207 ;
if ( F_39 ( V_15 & ( V_102 | V_103
| V_108 | V_101 ) ) ) {
if ( V_15 & V_101 ) {
V_15 &= ~ ( V_102 | V_103 ) ;
V_4 -> V_104 . V_105 ++ ;
if ( F_105 ( V_4 ) )
continue;
}
if ( V_15 & V_102 )
V_4 -> V_104 . V_106 ++ ;
if ( V_15 & V_103 )
V_4 -> V_104 . V_107 ++ ;
if ( V_15 & V_108 )
V_4 -> V_104 . V_109 ++ ;
V_15 &= V_4 -> V_76 ;
if ( V_15 & V_101 )
V_206 = V_208 ;
else if ( V_15 & V_102 )
V_206 = V_209 ;
else if ( V_15 & V_103 )
V_206 = V_210 ;
}
if ( F_106 ( V_4 , V_96 . V_91 ) )
continue;
F_107 ( V_4 , V_15 , V_108 , V_96 . V_91 , V_206 ) ;
}
F_84 ( & V_4 -> V_122 ) ;
F_85 ( & V_4 -> V_113 -> V_4 ) ;
F_86 ( & V_4 -> V_122 ) ;
}
static void F_108 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_211 ;
for ( V_211 = 0 ; V_211 < 2 ; V_211 ++ ) {
struct V_198 * V_199 = & V_10 -> V_212 [ V_211 ] ;
F_98 ( V_4 -> V_41 ,
V_199 -> V_201 ,
V_199 -> V_202 ,
V_162 ) ;
F_109 ( V_199 -> V_100 ) ;
}
}
static void F_110 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_165 * V_166 = & V_4 -> V_113 -> V_4 ;
struct V_198 * V_199 ;
int V_213 = V_10 -> V_214 ;
unsigned int V_97 ;
unsigned int V_98 ;
unsigned int V_170 ;
do {
F_5 ( V_4 , V_62 , V_171 ) ;
V_199 = & V_10 -> V_212 [ V_213 ] ;
V_97 = F_3 ( V_4 , V_215 ) - V_199 -> V_201 ;
V_98 = V_199 -> V_204 ;
V_97 = F_111 ( V_97 , V_199 -> V_202 ) ;
if ( F_112 ( V_97 != V_98 ) ) {
F_113 ( V_4 -> V_41 , V_199 -> V_201 ,
V_199 -> V_202 , V_162 ) ;
V_170 = V_97 - V_98 ;
F_83 ( V_166 , V_199 -> V_100 + V_199 -> V_204 ,
V_170 ) ;
F_100 ( V_4 -> V_41 , V_199 -> V_201 ,
V_199 -> V_202 , V_162 ) ;
V_4 -> V_104 . V_174 += V_170 ;
V_199 -> V_204 = V_97 ;
}
if ( V_97 >= V_199 -> V_202 ) {
V_199 -> V_204 = 0 ;
F_5 ( V_4 , V_216 , V_199 -> V_201 ) ;
F_5 ( V_4 , V_217 , V_199 -> V_202 ) ;
V_213 = ! V_213 ;
V_10 -> V_214 = V_213 ;
}
} while ( V_97 >= V_199 -> V_202 );
F_84 ( & V_4 -> V_122 ) ;
F_85 ( V_166 ) ;
F_86 ( & V_4 -> V_122 ) ;
F_5 ( V_4 , V_49 ,
V_74 | V_75 ) ;
}
static int F_114 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_211 ;
for ( V_211 = 0 ; V_211 < 2 ; V_211 ++ ) {
struct V_198 * V_199 = & V_10 -> V_212 [ V_211 ] ;
V_199 -> V_100 = F_115 ( V_218 , V_219 ) ;
if ( V_199 -> V_100 == NULL ) {
if ( V_211 != 0 ) {
F_98 ( V_4 -> V_41 ,
V_10 -> V_212 [ 0 ] . V_201 ,
V_218 ,
V_162 ) ;
F_109 ( V_10 -> V_212 [ 0 ] . V_100 ) ;
}
V_10 -> V_11 = 0 ;
return - V_220 ;
}
V_199 -> V_201 = F_102 ( V_4 -> V_41 ,
V_199 -> V_100 ,
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
static void F_116 ( unsigned long V_181 )
{
struct V_2 * V_4 = (struct V_2 * ) V_181 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_15 = V_10 -> V_185 ;
unsigned int V_186 = V_10 -> V_186 ;
F_86 ( & V_4 -> V_122 ) ;
V_10 -> V_222 ( V_4 ) ;
if ( V_186 & ( V_27 | V_24
| V_30 | V_21 ) ) {
if ( V_186 & V_27 )
V_4 -> V_104 . V_223 ++ ;
if ( V_186 & V_24 )
V_4 -> V_104 . V_224 ++ ;
if ( V_186 & V_30 )
F_117 ( V_4 , ! ( V_15 & V_30 ) ) ;
if ( V_186 & V_21 )
F_118 ( V_4 , ! ( V_15 & V_21 ) ) ;
F_119 ( & V_4 -> V_113 -> V_4 . V_225 ) ;
V_10 -> V_186 = 0 ;
}
V_10 -> V_226 ( V_4 ) ;
F_84 ( & V_4 -> V_122 ) ;
}
static void F_120 ( struct V_1 * V_10 ,
struct V_227 * V_228 )
{
struct V_229 * V_230 = V_228 -> V_41 . V_231 ;
struct V_232 * V_233 = F_121 ( & V_228 -> V_41 ) ;
if ( V_230 ) {
if ( F_122 ( V_230 , L_15 , NULL ) ) {
if ( F_122 ( V_230 , L_16 , NULL ) ) {
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
if ( F_122 ( V_230 , L_17 , NULL ) ) {
if ( F_122 ( V_230 , L_16 , NULL ) ) {
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
static void F_123 ( struct V_2 * V_4 ,
struct V_227 * V_228 )
{
struct V_229 * V_230 = V_228 -> V_41 . V_231 ;
struct V_232 * V_233 = F_121 ( & V_228 -> V_41 ) ;
if ( V_230 ) {
struct V_31 * V_32 = & V_4 -> V_38 ;
T_1 V_234 [ 2 ] ;
if ( F_124 ( V_230 , L_18 ,
V_234 , 2 ) == 0 ) {
V_32 -> V_235 = V_234 [ 0 ] ;
V_32 -> V_44 = V_234 [ 1 ] ;
V_32 -> V_39 = 0 ;
}
if ( F_122 ( V_230 , L_19 , NULL ) )
V_32 -> V_39 |= V_69 ;
if ( F_122 ( V_230 , L_20 ,
NULL ) )
V_32 -> V_39 |= V_40 ;
} else {
V_4 -> V_38 = V_233 -> V_38 ;
}
}
static void F_125 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_14 ( V_4 ) ) {
V_10 -> V_236 = & F_87 ;
V_10 -> V_226 = & F_80 ;
V_10 -> V_237 = & F_79 ;
} else if ( F_11 ( V_4 ) ) {
V_10 -> V_236 = & F_114 ;
V_10 -> V_226 = & F_110 ;
V_10 -> V_237 = & F_108 ;
} else {
V_10 -> V_236 = NULL ;
V_10 -> V_226 = & F_103 ;
V_10 -> V_237 = NULL ;
}
if ( F_13 ( V_4 ) ) {
V_10 -> V_238 = & F_65 ;
V_10 -> V_222 = & F_56 ;
V_10 -> V_239 = & F_53 ;
} else if ( F_12 ( V_4 ) ) {
V_10 -> V_238 = & F_101 ;
V_10 -> V_222 = & F_99 ;
V_10 -> V_239 = & F_97 ;
} else {
V_10 -> V_238 = NULL ;
V_10 -> V_222 = & F_41 ;
V_10 -> V_239 = NULL ;
}
}
static void F_126 ( struct V_2 * V_4 )
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
F_20 ( V_4 -> V_41 , L_21 ) ;
V_10 -> V_246 = true ;
V_10 -> V_247 = V_248 ;
} else if ( V_240 == V_243 ) {
F_20 ( V_4 -> V_41 , L_22 ) ;
V_10 -> V_246 = true ;
V_10 -> V_247 = V_249 ;
} else if ( V_240 == V_244 ) {
F_20 ( V_4 -> V_41 , L_23 ) ;
} else {
V_242 = F_3 ( V_4 , V_250 ) ;
switch ( V_242 ) {
case 0x302 :
case 0x10213 :
F_20 ( V_4 -> V_41 , L_24 ) ;
V_10 -> V_246 = true ;
V_10 -> V_247 = V_249 ;
break;
case 0x203 :
case 0x10202 :
F_20 ( V_4 -> V_41 , L_25 ) ;
break;
default:
F_62 ( V_4 -> V_41 , L_26 ) ;
}
}
}
static int F_127 ( struct V_2 * V_4 )
{
struct V_227 * V_228 = F_128 ( V_4 -> V_41 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
struct V_251 * V_252 = V_4 -> V_113 -> V_4 . V_252 ;
int V_253 ;
F_5 ( V_4 , V_34 , - 1 ) ;
V_10 -> V_82 = false ;
V_253 = F_129 ( V_4 -> V_188 , F_95 ,
V_254 | V_255 ,
V_252 ? V_252 -> V_240 : L_27 , V_4 ) ;
if ( V_253 ) {
F_62 ( V_4 -> V_41 , L_28 ) ;
return V_253 ;
}
F_130 ( & V_10 -> V_111 ) ;
F_120 ( V_10 , V_228 ) ;
F_125 ( V_4 ) ;
if ( V_10 -> V_236 ) {
V_253 = V_10 -> V_236 ( V_4 ) ;
if ( V_253 < 0 )
F_125 ( V_4 ) ;
}
if ( V_10 -> V_238 ) {
V_253 = V_10 -> V_238 ( V_4 ) ;
if ( V_253 < 0 )
F_125 ( V_4 ) ;
}
if ( V_10 -> V_139 ) {
unsigned int V_256 = V_257 ;
unsigned int V_258 = V_257 ;
unsigned int V_259 ;
F_5 ( V_4 , V_62 ,
V_260 |
V_261 |
V_262 ) ;
if ( F_13 ( V_4 ) )
V_256 = V_263 ;
V_259 = F_131 ( V_256 ) | F_132 ( V_258 ) ;
if ( V_10 -> V_264 &&
V_10 -> V_265 )
V_259 |= V_266 |
F_133 ( V_10 -> V_264 ) |
F_134 ( V_10 -> V_265 ) ;
F_5 ( V_4 , V_267 , V_259 ) ;
}
V_10 -> V_187 = F_15 ( V_4 ) ;
V_10 -> V_185 = V_10 -> V_187 ;
F_5 ( V_4 , V_62 , V_72 | V_268 ) ;
F_5 ( V_4 , V_62 , V_269 | V_73 ) ;
F_135 ( & V_10 -> V_182 ,
F_89 ,
( unsigned long ) V_4 ) ;
if ( F_11 ( V_4 ) ) {
if ( ! V_10 -> V_246 ) {
F_90 ( & V_10 -> V_182 ,
V_183 + F_91 ( V_4 ) ) ;
} else {
F_5 ( V_4 , V_10 -> V_247 ,
V_270 ) ;
F_5 ( V_4 , V_62 , V_171 ) ;
F_5 ( V_4 , V_49 ,
V_74 | V_75 ) ;
}
F_5 ( V_4 , V_67 , V_77 ) ;
} else if ( F_14 ( V_4 ) ) {
if ( ! V_10 -> V_246 ) {
F_90 ( & V_10 -> V_182 ,
V_183 + F_91 ( V_4 ) ) ;
} else {
F_5 ( V_4 , V_10 -> V_247 ,
V_270 ) ;
F_5 ( V_4 , V_62 , V_171 ) ;
F_5 ( V_4 , V_49 ,
V_75 ) ;
}
} else {
F_5 ( V_4 , V_49 , V_78 ) ;
}
return 0 ;
}
static void F_136 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_12 ( V_4 ) ) {
F_5 ( V_4 , V_203 , 0 ) ;
V_10 -> V_200 . V_204 = 0 ;
}
}
static void F_137 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_138 ( & V_10 -> V_182 ) ;
F_139 ( & V_10 -> V_111 ) ;
F_140 ( & V_10 -> V_111 ) ;
F_28 ( V_4 ) ;
F_25 ( V_4 ) ;
F_5 ( V_4 , V_62 , V_72 ) ;
F_5 ( V_4 , V_34 , - 1 ) ;
if ( V_10 -> V_237 )
V_10 -> V_237 ( V_4 ) ;
if ( V_10 -> V_239 )
V_10 -> V_239 ( V_4 ) ;
V_10 -> V_94 . V_97 = 0 ;
V_10 -> V_94 . V_98 = 0 ;
F_141 ( V_4 -> V_188 , V_4 ) ;
V_10 -> V_82 = false ;
F_136 ( V_4 ) ;
}
static void F_142 ( struct V_2 * V_4 , unsigned int V_113 ,
unsigned int V_271 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
switch ( V_113 ) {
case 0 :
F_143 ( V_10 -> V_272 ) ;
F_5 ( V_4 , V_49 , V_10 -> V_273 ) ;
break;
case 3 :
V_10 -> V_273 = F_3 ( V_4 , V_192 ) ;
F_5 ( V_4 , V_34 , - 1 ) ;
F_144 ( V_10 -> V_272 ) ;
break;
default:
F_62 ( V_4 -> V_41 , L_29 , V_113 ) ;
}
}
static void F_145 ( struct V_2 * V_4 , struct V_274 * V_275 ,
struct V_274 * V_276 )
{
unsigned long V_39 ;
unsigned int V_277 , V_33 , V_278 , V_279 , V_280 ;
V_33 = V_277 = F_3 ( V_4 , V_36 ) ;
V_33 &= ~ ( V_281 | V_282 | V_283 |
V_284 | V_37 ) ;
V_280 = F_146 ( V_4 , V_275 , V_276 , 0 , V_4 -> V_285 / 16 ) ;
V_279 = F_147 ( V_4 , V_280 ) ;
if ( V_279 > 65535 ) {
V_279 /= 8 ;
V_33 |= V_286 ;
}
switch ( V_275 -> V_287 & V_288 ) {
case V_289 :
V_33 |= V_290 ;
break;
case V_291 :
V_33 |= V_292 ;
break;
case V_293 :
V_33 |= V_294 ;
break;
default:
V_33 |= V_295 ;
break;
}
if ( V_275 -> V_287 & V_296 )
V_33 |= V_297 ;
if ( V_275 -> V_287 & V_298 ) {
if ( V_275 -> V_287 & V_299 ) {
if ( V_275 -> V_287 & V_300 )
V_33 |= V_301 ;
else
V_33 |= V_302 ;
} else if ( V_275 -> V_287 & V_300 )
V_33 |= V_303 ;
else
V_33 |= V_304 ;
} else
V_33 |= V_305 ;
F_47 ( & V_4 -> V_122 , V_39 ) ;
V_4 -> V_76 = V_108 ;
if ( V_275 -> V_306 & V_307 )
V_4 -> V_76 |= ( V_103 | V_102 ) ;
if ( V_275 -> V_306 & ( V_308 | V_309 | V_310 ) )
V_4 -> V_76 |= V_101 ;
if ( F_11 ( V_4 ) )
F_5 ( V_4 , V_49 , V_4 -> V_76 ) ;
V_4 -> V_311 = 0 ;
if ( V_275 -> V_306 & V_312 )
V_4 -> V_311 |= ( V_103 | V_102 ) ;
if ( V_275 -> V_306 & V_308 ) {
V_4 -> V_311 |= V_101 ;
if ( V_275 -> V_306 & V_312 )
V_4 -> V_311 |= V_108 ;
}
F_148 ( V_4 , V_275 -> V_287 , V_280 ) ;
V_278 = F_3 ( V_4 , V_192 ) ;
F_5 ( V_4 , V_34 , - 1 ) ;
F_5 ( V_4 , V_62 , V_313 | V_79 ) ;
if ( V_4 -> V_38 . V_39 & V_40 ) {
F_5 ( V_4 , V_43 ,
V_4 -> V_38 . V_44 ) ;
V_33 |= V_45 ;
} else if ( V_275 -> V_287 & V_314 ) {
V_33 |= V_55 ;
} else {
V_33 |= V_315 ;
}
F_5 ( V_4 , V_36 , V_33 ) ;
if ( ( V_277 & V_37 ) != ( V_33 & V_37 ) ) {
unsigned int V_316 ;
if ( ( V_33 & V_37 ) == V_55 ) {
V_316 = V_57 ;
} else {
V_316 = V_56 ;
}
F_5 ( V_4 , V_62 , V_316 ) ;
}
F_5 ( V_4 , V_317 , V_279 ) ;
F_5 ( V_4 , V_62 , V_72 | V_268 ) ;
F_5 ( V_4 , V_62 , V_269 | V_73 ) ;
F_5 ( V_4 , V_49 , V_278 ) ;
if ( F_149 ( V_4 , V_275 -> V_287 ) )
F_29 ( V_4 ) ;
else
F_31 ( V_4 ) ;
F_52 ( & V_4 -> V_122 , V_39 ) ;
}
static void F_150 ( struct V_2 * V_4 , struct V_274 * V_275 )
{
if ( V_275 -> V_318 == V_319 ) {
V_4 -> V_39 |= V_320 ;
F_49 ( & V_4 -> V_122 ) ;
F_29 ( V_4 ) ;
F_51 ( & V_4 -> V_122 ) ;
} else {
V_4 -> V_39 &= ~ V_320 ;
if ( ! F_149 ( V_4 , V_275 -> V_287 ) ) {
F_49 ( & V_4 -> V_122 ) ;
F_31 ( V_4 ) ;
F_51 ( & V_4 -> V_122 ) ;
}
}
}
static const char * F_151 ( struct V_2 * V_4 )
{
return ( V_4 -> type == V_321 ) ? L_30 : NULL ;
}
static void F_152 ( struct V_2 * V_4 )
{
struct V_227 * V_228 = F_128 ( V_4 -> V_41 ) ;
int V_322 = V_228 -> V_323 [ 0 ] . V_324 - V_228 -> V_323 [ 0 ] . V_325 + 1 ;
F_153 ( V_4 -> V_158 , V_322 ) ;
if ( V_4 -> V_39 & V_326 ) {
F_154 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
}
static int F_155 ( struct V_2 * V_4 )
{
struct V_227 * V_228 = F_128 ( V_4 -> V_41 ) ;
int V_322 = V_228 -> V_323 [ 0 ] . V_324 - V_228 -> V_323 [ 0 ] . V_325 + 1 ;
if ( ! F_156 ( V_4 -> V_158 , V_322 , L_27 ) )
return - V_327 ;
if ( V_4 -> V_39 & V_326 ) {
V_4 -> V_6 = F_157 ( V_4 -> V_158 , V_322 ) ;
if ( V_4 -> V_6 == NULL ) {
F_153 ( V_4 -> V_158 , V_322 ) ;
return - V_220 ;
}
}
return 0 ;
}
static void F_158 ( struct V_2 * V_4 , int V_39 )
{
if ( V_39 & V_328 ) {
V_4 -> type = V_321 ;
F_155 ( V_4 ) ;
}
}
static int F_159 ( struct V_2 * V_4 , struct V_329 * V_330 )
{
int V_16 = 0 ;
if ( V_330 -> type != V_331 && V_330 -> type != V_321 )
V_16 = - V_127 ;
if ( V_4 -> V_188 != V_330 -> V_188 )
V_16 = - V_127 ;
if ( V_330 -> V_332 != V_333 )
V_16 = - V_127 ;
if ( V_4 -> V_285 / 16 != V_330 -> V_334 )
V_16 = - V_127 ;
if ( V_4 -> V_158 != ( unsigned long ) V_330 -> V_335 )
V_16 = - V_127 ;
if ( V_4 -> V_336 != V_330 -> V_4 )
V_16 = - V_127 ;
if ( V_330 -> V_337 != 0 )
V_16 = - V_127 ;
return V_16 ;
}
static int F_160 ( struct V_2 * V_4 )
{
while ( ! ( F_3 ( V_4 , V_17 ) & V_78 ) )
F_161 () ;
return F_7 ( V_4 ) ;
}
static void F_162 ( struct V_2 * V_4 , unsigned char V_91 )
{
while ( ! ( F_3 ( V_4 , V_17 ) & V_48 ) )
F_161 () ;
F_8 ( V_4 , V_91 ) ;
}
static int F_163 ( struct V_1 * V_10 ,
struct V_227 * V_228 )
{
int V_16 ;
struct V_2 * V_4 = & V_10 -> V_3 ;
struct V_232 * V_233 = F_121 ( & V_228 -> V_41 ) ;
F_120 ( V_10 , V_228 ) ;
F_125 ( V_4 ) ;
F_123 ( V_4 , V_228 ) ;
V_4 -> V_338 = V_339 ;
V_4 -> V_39 = V_340 ;
V_4 -> V_341 = & V_342 ;
V_4 -> V_343 = 1 ;
V_4 -> V_41 = & V_228 -> V_41 ;
V_4 -> V_158 = V_228 -> V_323 [ 0 ] . V_325 ;
V_4 -> V_188 = V_228 -> V_323 [ 1 ] . V_325 ;
V_4 -> V_344 = F_19 ;
F_164 ( & V_10 -> V_111 , F_116 ,
( unsigned long ) V_4 ) ;
F_139 ( & V_10 -> V_111 ) ;
memset ( & V_10 -> V_94 , 0 , sizeof( V_10 -> V_94 ) ) ;
if ( V_233 && V_233 -> V_345 ) {
V_4 -> V_6 = V_233 -> V_345 ;
} else {
V_4 -> V_39 |= V_326 ;
V_4 -> V_6 = NULL ;
}
if ( ! V_10 -> V_272 ) {
V_10 -> V_272 = F_165 ( & V_228 -> V_41 , L_31 ) ;
if ( F_166 ( V_10 -> V_272 ) ) {
V_16 = F_167 ( V_10 -> V_272 ) ;
V_10 -> V_272 = NULL ;
return V_16 ;
}
V_16 = F_143 ( V_10 -> V_272 ) ;
if ( V_16 ) {
F_168 ( V_10 -> V_272 ) ;
V_10 -> V_272 = NULL ;
return V_16 ;
}
V_4 -> V_285 = F_169 ( V_10 -> V_272 ) ;
F_144 ( V_10 -> V_272 ) ;
}
if ( V_4 -> V_38 . V_39 & V_40 )
V_10 -> V_35 = V_42 ;
else if ( F_12 ( V_4 ) ) {
V_4 -> V_343 = V_218 ;
V_10 -> V_35 = V_46 | V_47 ;
} else {
V_10 -> V_35 = V_48 ;
}
return 0 ;
}
static void F_170 ( struct V_2 * V_4 , int V_91 )
{
while ( ! ( F_3 ( V_4 , V_17 ) & V_48 ) )
F_161 () ;
F_8 ( V_4 , V_91 ) ;
}
static void F_171 ( struct V_346 * V_347 , const char * V_348 , T_3 V_170 )
{
struct V_2 * V_4 = & V_349 [ V_347 -> V_350 ] . V_3 ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned int V_15 , V_278 ;
unsigned int V_200 ;
V_278 = F_3 ( V_4 , V_192 ) ;
F_5 ( V_4 , V_34 ,
V_78 | V_10 -> V_35 ) ;
V_200 = F_3 ( V_4 , V_70 ) & V_71 ;
F_5 ( V_4 , V_67 , V_68 ) ;
F_172 ( V_4 , V_348 , V_170 , F_170 ) ;
do {
V_15 = F_3 ( V_4 , V_17 ) ;
} while ( ! ( V_15 & V_48 ) );
if ( V_200 )
F_5 ( V_4 , V_67 , V_71 ) ;
F_5 ( V_4 , V_49 , V_278 ) ;
}
static void T_9 F_173 ( struct V_2 * V_4 , int * V_280 ,
int * V_106 , int * V_351 )
{
unsigned int V_352 , V_279 ;
V_279 = F_3 ( V_4 , V_317 ) & V_353 ;
if ( ! V_279 )
return;
V_352 = F_3 ( V_4 , V_36 ) & V_282 ;
if ( V_352 == V_295 )
* V_351 = 8 ;
else
* V_351 = 7 ;
V_352 = F_3 ( V_4 , V_36 ) & V_284 ;
if ( V_352 == V_304 )
* V_106 = 'e' ;
else if ( V_352 == V_303 )
* V_106 = 'o' ;
* V_280 = V_4 -> V_285 / ( 16 * ( V_279 - 1 ) ) ;
}
static int T_9 F_174 ( struct V_346 * V_347 , char * V_354 )
{
int V_16 ;
struct V_2 * V_4 = & V_349 [ V_347 -> V_350 ] . V_3 ;
int V_280 = 115200 ;
int V_351 = 8 ;
int V_106 = 'n' ;
int V_355 = 'n' ;
if ( V_4 -> V_6 == NULL ) {
return - V_356 ;
}
V_16 = F_143 ( V_349 [ V_347 -> V_350 ] . V_272 ) ;
if ( V_16 )
return V_16 ;
F_5 ( V_4 , V_34 , - 1 ) ;
F_5 ( V_4 , V_62 , V_72 | V_268 ) ;
F_5 ( V_4 , V_62 , V_269 | V_73 ) ;
if ( V_354 )
F_175 ( V_354 , & V_280 , & V_106 , & V_351 , & V_355 ) ;
else
F_173 ( V_4 , & V_280 , & V_106 , & V_351 ) ;
return F_176 ( V_4 , V_347 , V_280 , V_106 , V_351 , V_355 ) ;
}
static int T_9 F_177 ( void )
{
int V_16 ;
if ( V_357 ) {
struct V_232 * V_233 =
F_121 ( & V_357 -> V_41 ) ;
int V_358 = V_233 -> V_359 ;
struct V_1 * V_10 = & V_349 [ V_358 ] ;
V_10 -> V_273 = 0 ;
V_10 -> V_3 . line = V_358 ;
F_178 ( V_360 , V_358 , NULL ) ;
V_16 = F_163 ( V_10 , V_357 ) ;
if ( V_16 )
return V_16 ;
F_179 ( & V_361 ) ;
}
return 0 ;
}
static int T_9 F_180 ( void )
{
if ( V_357
&& ! ( V_361 . V_39 & V_362 ) )
F_179 ( & V_361 ) ;
return 0 ;
}
static inline bool F_181 ( struct V_2 * V_4 )
{
return V_4 -> V_363 && V_4 -> V_363 -> V_350 == V_4 -> line ;
}
static inline bool F_181 ( struct V_2 * V_4 )
{
return false ;
}
static bool F_182 ( void )
{
#ifdef F_183
return F_184 () ;
#else
return false ;
#endif
}
static int F_185 ( struct V_227 * V_228 ,
T_10 V_113 )
{
struct V_2 * V_4 = F_186 ( V_228 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( F_181 ( V_4 ) && V_364 ) {
while ( ! ( F_3 ( V_4 , V_17 ) &
V_42 ) )
F_161 () ;
}
V_10 -> V_365 = F_187 ( & V_228 -> V_41 ) ;
if ( F_182 () ) {
unsigned long V_39 ;
F_47 ( & V_10 -> V_191 , V_39 ) ;
V_10 -> V_193 = true ;
F_52 ( & V_10 -> V_191 , V_39 ) ;
F_188 ( & V_228 -> V_41 , 0 ) ;
}
F_189 ( & V_366 , V_4 ) ;
return 0 ;
}
static int F_190 ( struct V_227 * V_228 )
{
struct V_2 * V_4 = F_186 ( V_228 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned long V_39 ;
F_47 ( & V_10 -> V_191 , V_39 ) ;
if ( V_10 -> V_184 ) {
F_92 ( V_4 , V_10 -> V_184 ) ;
F_94 ( V_4 , V_10 -> V_184 ,
V_10 -> V_194 ) ;
F_93 ( V_4 , V_10 -> V_184 ) ;
V_10 -> V_184 = 0 ;
}
V_10 -> V_193 = false ;
F_52 ( & V_10 -> V_191 , V_39 ) ;
F_191 ( & V_366 , V_4 ) ;
F_188 ( & V_228 -> V_41 , V_10 -> V_365 ) ;
return 0 ;
}
static void F_192 ( struct V_1 * V_10 ,
struct V_227 * V_228 )
{
V_10 -> V_139 = 0 ;
V_10 -> V_265 = 0 ;
V_10 -> V_264 = 0 ;
if ( F_193 ( V_228 -> V_41 . V_231 ,
L_32 ,
& V_10 -> V_139 ) )
return;
if ( ! V_10 -> V_139 )
return;
if ( V_10 -> V_139 < V_367 ) {
V_10 -> V_139 = 0 ;
F_62 ( & V_228 -> V_41 , L_33 ) ;
return;
}
V_10 -> V_264 = F_194 ( int , V_10 -> V_139 >> 1 ,
V_10 -> V_139 - V_368 ) ;
V_10 -> V_265 = F_194 ( int , V_10 -> V_139 >> 2 ,
V_10 -> V_139 - V_369 ) ;
F_69 ( & V_228 -> V_41 , L_34 ,
V_10 -> V_139 ) ;
F_20 ( & V_228 -> V_41 , L_35 ,
V_10 -> V_264 ) ;
F_20 ( & V_228 -> V_41 , L_36 ,
V_10 -> V_265 ) ;
}
static int F_195 ( struct V_227 * V_228 )
{
struct V_1 * V_10 ;
struct V_229 * V_230 = V_228 -> V_41 . V_231 ;
struct V_232 * V_233 = F_121 ( & V_228 -> V_41 ) ;
void * V_181 ;
int V_16 = - V_356 ;
bool V_370 ;
F_196 ( V_99 & ( V_99 - 1 ) ) ;
if ( V_230 )
V_16 = F_197 ( V_230 , L_37 ) ;
else
if ( V_233 )
V_16 = V_233 -> V_359 ;
if ( V_16 < 0 )
V_16 = F_198 ( V_371 , V_372 ) ;
if ( V_16 >= V_372 ) {
V_16 = - V_356 ;
goto V_373;
}
if ( F_199 ( V_16 , V_371 ) ) {
V_16 = - V_327 ;
goto V_373;
}
V_10 = & V_349 [ V_16 ] ;
V_10 -> V_273 = 0 ;
V_10 -> V_3 . line = V_16 ;
F_192 ( V_10 , V_228 ) ;
F_71 ( & V_10 -> V_191 ) ;
V_16 = F_163 ( V_10 , V_228 ) ;
if ( V_16 )
goto V_374;
V_10 -> V_18 = F_200 ( & V_10 -> V_3 , 0 ) ;
if ( F_166 ( V_10 -> V_18 ) ) {
V_16 = F_167 ( V_10 -> V_18 ) ;
goto V_374;
}
if ( ! F_11 ( & V_10 -> V_3 ) ) {
V_16 = - V_220 ;
V_181 = F_115 ( sizeof( struct V_95 )
* V_99 , V_219 ) ;
if ( ! V_181 )
goto V_375;
V_10 -> V_94 . V_100 = V_181 ;
}
V_370 = V_10 -> V_3 . V_38 . V_39 & V_40 ;
V_16 = F_201 ( & V_366 , & V_10 -> V_3 ) ;
if ( V_16 )
goto V_376;
#ifdef F_202
if ( F_181 ( & V_10 -> V_3 )
&& V_377 -> V_39 & V_362 ) {
F_144 ( V_10 -> V_272 ) ;
}
#endif
F_203 ( & V_228 -> V_41 , 1 ) ;
F_204 ( V_228 , V_10 ) ;
F_143 ( V_10 -> V_272 ) ;
if ( V_370 ) {
F_5 ( & V_10 -> V_3 , V_36 ,
V_315 ) ;
F_5 ( & V_10 -> V_3 , V_62 ,
V_56 ) ;
}
F_126 ( & V_10 -> V_3 ) ;
F_144 ( V_10 -> V_272 ) ;
return 0 ;
V_376:
F_109 ( V_10 -> V_94 . V_100 ) ;
V_10 -> V_94 . V_100 = NULL ;
V_375:
if ( ! F_181 ( & V_10 -> V_3 ) ) {
F_168 ( V_10 -> V_272 ) ;
V_10 -> V_272 = NULL ;
}
V_374:
F_205 ( V_10 -> V_3 . line , V_371 ) ;
V_373:
return V_16 ;
}
static int F_206 ( struct V_227 * V_228 )
{
struct V_2 * V_4 = F_186 ( V_228 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_16 = 0 ;
F_140 ( & V_10 -> V_111 ) ;
F_203 ( & V_228 -> V_41 , 0 ) ;
V_16 = F_207 ( & V_366 , V_4 ) ;
F_109 ( V_10 -> V_94 . V_100 ) ;
F_205 ( V_4 -> line , V_371 ) ;
F_168 ( V_10 -> V_272 ) ;
V_10 -> V_272 = NULL ;
return V_16 ;
}
static int T_9 F_208 ( void )
{
int V_16 ;
V_16 = F_209 ( & V_366 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_210 ( & V_378 ) ;
if ( V_16 )
F_211 ( & V_366 ) ;
return V_16 ;
}
