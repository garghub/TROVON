static unsigned int F_1 ( unsigned int V_1 )
{
unsigned int V_2 = ( V_1 >> 20 ) & 0xf ;
return V_2 < 3 ? 16 : 32 ;
}
static unsigned int F_2 ( unsigned int V_1 )
{
return 64 ;
}
static int F_3 ( struct V_3 * V_4 )
{
T_1 V_5 , V_6 ;
unsigned int V_7 , V_8 = 256 ;
int V_9 = 0 ;
while ( V_8 -- ) {
V_5 = F_4 ( V_4 -> V_10 . V_11 + V_12 ) ;
if ( V_5 & V_13 )
break;
V_6 = F_4 ( V_4 -> V_10 . V_11 + V_14 ) |
V_15 ;
V_7 = V_16 ;
V_4 -> V_10 . V_17 . V_18 ++ ;
V_9 ++ ;
if ( F_5 ( V_6 & V_19 ) ) {
if ( V_6 & V_20 ) {
V_6 &= ~ ( V_21 | V_22 ) ;
V_4 -> V_10 . V_17 . V_23 ++ ;
if ( F_6 ( & V_4 -> V_10 ) )
continue;
} else if ( V_6 & V_22 )
V_4 -> V_10 . V_17 . V_24 ++ ;
else if ( V_6 & V_21 )
V_4 -> V_10 . V_17 . V_25 ++ ;
if ( V_6 & V_26 )
V_4 -> V_10 . V_17 . V_27 ++ ;
V_6 &= V_4 -> V_10 . V_28 ;
if ( V_6 & V_20 )
V_7 = V_29 ;
else if ( V_6 & V_22 )
V_7 = V_30 ;
else if ( V_6 & V_21 )
V_7 = V_31 ;
}
if ( F_7 ( & V_4 -> V_10 , V_6 & 255 ) )
continue;
F_8 ( & V_4 -> V_10 , V_6 , V_26 , V_6 , V_7 ) ;
}
return V_9 ;
}
static int F_9 ( struct V_32 * V_33 , struct V_34 * V_35 ,
enum V_36 V_37 )
{
T_2 V_38 ;
V_35 -> V_39 = F_10 ( V_33 -> V_40 -> V_41 ,
V_42 , & V_38 , V_43 ) ;
if ( ! V_35 -> V_39 )
return - V_44 ;
F_11 ( & V_35 -> V_35 , 1 ) ;
F_12 ( & V_35 -> V_35 , F_13 ( V_38 ) ,
V_42 , F_14 ( V_38 ) ) ;
F_15 ( & V_35 -> V_35 ) = V_38 ;
return 0 ;
}
static void F_16 ( struct V_32 * V_33 , struct V_34 * V_35 ,
enum V_36 V_37 )
{
if ( V_35 -> V_39 ) {
F_17 ( V_33 -> V_40 -> V_41 ,
V_42 , V_35 -> V_39 ,
F_15 ( & V_35 -> V_35 ) ) ;
}
}
static void F_18 ( struct V_40 * V_41 , struct V_3 * V_4 )
{
struct V_45 * V_46 = V_4 -> V_10 . V_41 -> V_47 ;
struct V_48 V_49 = {
. V_50 = V_4 -> V_10 . V_51 + V_14 ,
. V_52 = V_53 ,
. V_54 = V_55 ,
. V_56 = V_4 -> V_57 >> 1 ,
. V_58 = false ,
} ;
struct V_32 * V_33 ;
T_3 V_59 ;
V_33 = F_19 ( V_41 , L_1 ) ;
if ( ! V_33 ) {
if ( ! V_46 || ! V_46 -> V_60 ) {
F_20 ( V_4 -> V_10 . V_41 , L_2 ) ;
return;
}
F_21 ( V_59 ) ;
F_22 ( V_61 , V_59 ) ;
V_33 = F_23 ( V_59 , V_46 -> V_60 ,
V_46 -> V_62 ) ;
if ( ! V_33 ) {
F_24 ( V_4 -> V_10 . V_41 , L_3 ) ;
return;
}
}
F_25 ( V_33 , & V_49 ) ;
V_4 -> V_63 . V_33 = V_33 ;
F_20 ( V_4 -> V_10 . V_41 , L_4 ,
F_26 ( V_4 -> V_63 . V_33 ) ) ;
V_33 = F_19 ( V_41 , L_5 ) ;
if ( ! V_33 && V_46 -> V_64 ) {
V_33 = F_23 ( V_59 , V_46 -> V_60 , V_46 -> V_64 ) ;
if ( ! V_33 ) {
F_24 ( V_4 -> V_10 . V_41 , L_6 ) ;
return;
}
}
if ( V_33 ) {
struct V_48 V_65 = {
. V_66 = V_4 -> V_10 . V_51 + V_14 ,
. V_67 = V_53 ,
. V_54 = V_68 ,
. V_69 = V_4 -> V_57 >> 1 ,
. V_58 = false ,
} ;
F_25 ( V_33 , & V_65 ) ;
V_4 -> V_70 . V_33 = V_33 ;
if ( V_46 && V_46 -> V_71 ) {
if ( V_46 -> V_72 ) {
V_4 -> V_70 . V_73 = false ;
V_4 -> V_70 . V_74 = V_46 -> V_72 ;
} else {
V_4 -> V_70 . V_73 = true ;
V_4 -> V_70 . V_74 = 100 ;
}
if ( V_46 -> V_75 )
V_4 -> V_70 . V_76 =
V_46 -> V_75 ;
else
V_4 -> V_70 . V_76 = 3000 ;
} else
V_4 -> V_70 . V_73 = false ;
F_20 ( V_4 -> V_10 . V_41 , L_7 ,
F_26 ( V_4 -> V_70 . V_33 ) ) ;
}
}
static int T_4 F_27 ( void )
{
struct V_77 * V_78 , * V_79 ;
F_28 (node, tmp, &pl011_dma_uarts) {
struct V_80 * V_81 = F_29 ( V_78 , struct V_80 , V_78 ) ;
F_18 ( V_81 -> V_41 , V_81 -> V_4 ) ;
F_30 ( V_78 ) ;
F_31 ( V_81 ) ;
}
return 0 ;
}
static void F_32 ( struct V_40 * V_41 , struct V_3 * V_4 )
{
struct V_80 * V_81 = F_33 ( sizeof( struct V_80 ) , V_43 ) ;
if ( V_81 ) {
V_81 -> V_4 = V_4 ;
V_81 -> V_41 = V_41 ;
F_34 ( & V_81 -> V_78 , & V_82 ) ;
}
}
static void F_32 ( struct V_40 * V_41 , struct V_3 * V_4 )
{
F_18 ( V_41 , V_4 ) ;
}
static void F_35 ( struct V_3 * V_4 )
{
if ( V_4 -> V_63 . V_33 )
F_36 ( V_4 -> V_63 . V_33 ) ;
if ( V_4 -> V_70 . V_33 )
F_36 ( V_4 -> V_70 . V_33 ) ;
}
static void F_37 ( void * V_83 )
{
struct V_3 * V_4 = V_83 ;
struct V_84 * V_63 = & V_4 -> V_63 ;
unsigned long V_85 ;
T_1 V_86 ;
F_38 ( & V_4 -> V_10 . V_87 , V_85 ) ;
if ( V_4 -> V_63 . V_88 )
F_39 ( V_63 -> V_33 -> V_40 -> V_41 , & V_63 -> V_35 , 1 ,
V_89 ) ;
V_86 = V_4 -> V_86 ;
V_4 -> V_86 = V_86 & ~ V_90 ;
F_40 ( V_4 -> V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
if ( ! ( V_86 & V_90 ) || F_41 ( & V_4 -> V_10 ) ||
F_42 ( & V_4 -> V_10 . V_92 -> V_93 ) ) {
V_4 -> V_63 . V_88 = false ;
F_43 ( & V_4 -> V_10 . V_87 , V_85 ) ;
return;
}
if ( F_44 ( V_4 ) <= 0 ) {
V_4 -> V_94 |= V_95 ;
F_40 ( V_4 -> V_94 , V_4 -> V_10 . V_11 + V_96 ) ;
}
F_43 ( & V_4 -> V_10 . V_87 , V_85 ) ;
}
static int F_44 ( struct V_3 * V_4 )
{
struct V_84 * V_63 = & V_4 -> V_63 ;
struct V_32 * V_33 = V_63 -> V_33 ;
struct V_97 * V_98 = V_33 -> V_40 ;
struct V_99 * V_100 ;
struct V_101 * V_93 = & V_4 -> V_10 . V_92 -> V_93 ;
unsigned int V_102 ;
V_102 = F_45 ( V_93 ) ;
if ( V_102 < ( V_4 -> V_57 >> 1 ) ) {
V_4 -> V_63 . V_88 = false ;
return 0 ;
}
V_102 -= 1 ;
if ( V_102 > V_42 )
V_102 = V_42 ;
if ( V_93 -> V_103 < V_93 -> V_104 )
memcpy ( & V_63 -> V_39 [ 0 ] , & V_93 -> V_39 [ V_93 -> V_103 ] , V_102 ) ;
else {
T_5 V_105 = V_106 - V_93 -> V_103 ;
T_5 V_107 = V_93 -> V_104 ;
memcpy ( & V_63 -> V_39 [ 0 ] , & V_93 -> V_39 [ V_93 -> V_103 ] , V_105 ) ;
if ( V_107 )
memcpy ( & V_63 -> V_39 [ V_105 ] , & V_93 -> V_39 [ 0 ] , V_107 ) ;
}
V_63 -> V_35 . V_108 = V_102 ;
if ( F_46 ( V_98 -> V_41 , & V_63 -> V_35 , 1 , V_89 ) != 1 ) {
V_4 -> V_63 . V_88 = false ;
F_47 ( V_4 -> V_10 . V_41 , L_8 ) ;
return - V_109 ;
}
V_100 = F_48 ( V_33 , & V_63 -> V_35 , 1 , V_55 ,
V_110 | V_111 ) ;
if ( ! V_100 ) {
F_39 ( V_98 -> V_41 , & V_63 -> V_35 , 1 , V_89 ) ;
V_4 -> V_63 . V_88 = false ;
F_47 ( V_4 -> V_10 . V_41 , L_9 ) ;
return - V_109 ;
}
V_100 -> V_112 = F_37 ;
V_100 -> V_113 = V_4 ;
F_49 ( V_100 ) ;
V_98 -> V_114 ( V_33 ) ;
V_4 -> V_86 |= V_90 ;
F_40 ( V_4 -> V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
V_4 -> V_63 . V_88 = true ;
V_93 -> V_103 = ( V_93 -> V_103 + V_102 ) & ( V_106 - 1 ) ;
V_4 -> V_10 . V_17 . V_115 += V_102 ;
if ( F_45 ( V_93 ) < V_116 )
F_50 ( & V_4 -> V_10 ) ;
return 1 ;
}
static bool F_51 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_117 )
return false ;
if ( V_4 -> V_63 . V_88 ) {
V_4 -> V_86 |= V_90 ;
F_40 ( V_4 -> V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
V_4 -> V_94 &= ~ V_95 ;
F_40 ( V_4 -> V_94 , V_4 -> V_10 . V_11 + V_96 ) ;
return true ;
}
if ( F_44 ( V_4 ) > 0 ) {
V_4 -> V_94 &= ~ V_95 ;
F_40 ( V_4 -> V_94 , V_4 -> V_10 . V_11 + V_96 ) ;
return true ;
}
return false ;
}
static inline void F_52 ( struct V_3 * V_4 )
{
if ( V_4 -> V_63 . V_88 ) {
V_4 -> V_86 &= ~ V_90 ;
F_40 ( V_4 -> V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
}
}
static inline bool F_53 ( struct V_3 * V_4 )
{
T_1 V_86 ;
if ( ! V_4 -> V_117 )
return false ;
if ( ! V_4 -> V_10 . V_118 ) {
bool V_119 = true ;
if ( ! V_4 -> V_63 . V_88 ) {
if ( F_44 ( V_4 ) > 0 ) {
V_4 -> V_94 &= ~ V_95 ;
V_119 = true ;
} else {
V_4 -> V_94 |= V_95 ;
V_119 = false ;
}
F_40 ( V_4 -> V_94 , V_4 -> V_10 . V_11 + V_96 ) ;
} else if ( ! ( V_4 -> V_86 & V_90 ) ) {
V_4 -> V_86 |= V_90 ;
F_40 ( V_4 -> V_86 ,
V_4 -> V_10 . V_11 + V_91 ) ;
}
return V_119 ;
}
V_86 = V_4 -> V_86 ;
V_4 -> V_86 &= ~ V_90 ;
F_40 ( V_4 -> V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
if ( F_4 ( V_4 -> V_10 . V_11 + V_12 ) & V_120 ) {
return false ;
}
F_40 ( V_4 -> V_10 . V_118 , V_4 -> V_10 . V_11 + V_14 ) ;
V_4 -> V_10 . V_17 . V_115 ++ ;
V_4 -> V_10 . V_118 = 0 ;
V_4 -> V_86 = V_86 ;
F_40 ( V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
return true ;
}
static void F_54 ( struct V_121 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
if ( ! V_4 -> V_117 )
return;
F_55 ( & V_4 -> V_10 . V_87 ) ;
F_56 ( V_4 -> V_63 . V_33 ) ;
F_57 ( & V_4 -> V_10 . V_87 ) ;
if ( V_4 -> V_63 . V_88 ) {
F_39 ( V_4 -> V_63 . V_33 -> V_40 -> V_41 , & V_4 -> V_63 . V_35 , 1 ,
V_89 ) ;
V_4 -> V_63 . V_88 = false ;
V_4 -> V_86 &= ~ V_90 ;
F_40 ( V_4 -> V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
}
}
static int F_58 ( struct V_3 * V_4 )
{
struct V_32 * V_122 = V_4 -> V_70 . V_33 ;
struct V_123 * V_70 = & V_4 -> V_70 ;
struct V_99 * V_100 ;
struct V_34 * V_124 ;
if ( ! V_122 )
return - V_125 ;
V_124 = V_4 -> V_70 . V_126 ?
& V_4 -> V_70 . V_127 : & V_4 -> V_70 . V_128 ;
V_100 = F_48 ( V_122 , & V_124 -> V_35 , 1 ,
V_68 ,
V_110 | V_111 ) ;
if ( ! V_100 ) {
V_4 -> V_70 . V_129 = false ;
F_56 ( V_122 ) ;
return - V_109 ;
}
V_100 -> V_112 = V_130 ;
V_100 -> V_113 = V_4 ;
V_70 -> V_131 = F_49 ( V_100 ) ;
F_59 ( V_122 ) ;
V_4 -> V_86 |= V_132 ;
F_40 ( V_4 -> V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
V_4 -> V_70 . V_129 = true ;
V_4 -> V_94 &= ~ V_133 ;
F_40 ( V_4 -> V_94 , V_4 -> V_10 . V_11 + V_96 ) ;
return 0 ;
}
static void F_60 ( struct V_3 * V_4 ,
T_6 V_134 , bool V_126 ,
bool V_135 )
{
struct V_136 * V_10 = & V_4 -> V_10 . V_92 -> V_10 ;
struct V_34 * V_124 = V_126 ?
& V_4 -> V_70 . V_127 : & V_4 -> V_70 . V_128 ;
int V_137 = 0 ;
T_6 V_9 = 0 ;
struct V_123 * V_70 = & V_4 -> V_70 ;
int V_138 = 0 ;
if ( V_4 -> V_70 . V_74 ) {
V_138 = V_124 -> V_35 . V_108 - V_70 -> V_139 ;
if ( V_134 >= V_138 )
V_134 -= V_138 ;
}
if ( V_134 ) {
V_137 = F_61 ( V_10 , V_124 -> V_39 + V_138 ,
V_134 ) ;
V_4 -> V_10 . V_17 . V_18 += V_137 ;
if ( V_137 < V_134 )
F_62 ( V_4 -> V_10 . V_41 ,
L_10 ) ;
}
if ( V_4 -> V_70 . V_74 )
V_70 -> V_139 = V_124 -> V_35 . V_108 ;
if ( V_137 == V_134 && V_135 ) {
F_40 ( V_140 | V_141 | V_142 | V_143 ,
V_4 -> V_10 . V_11 + V_144 ) ;
V_9 = F_3 ( V_4 ) ;
}
F_55 ( & V_4 -> V_10 . V_87 ) ;
F_63 ( V_4 -> V_10 . V_41 ,
L_11 ,
V_137 , V_9 ) ;
F_64 ( V_10 ) ;
F_57 ( & V_4 -> V_10 . V_87 ) ;
}
static void F_65 ( struct V_3 * V_4 )
{
struct V_123 * V_70 = & V_4 -> V_70 ;
struct V_32 * V_122 = V_70 -> V_33 ;
struct V_34 * V_124 = V_70 -> V_126 ?
& V_70 -> V_127 : & V_70 -> V_128 ;
T_5 V_134 ;
struct V_145 V_92 ;
enum V_146 V_147 ;
if ( F_66 ( V_122 ) )
F_24 ( V_4 -> V_10 . V_41 , L_12 ) ;
V_147 = V_122 -> V_40 -> V_148 ( V_122 ,
V_70 -> V_131 , & V_92 ) ;
if ( V_147 != V_149 )
F_24 ( V_4 -> V_10 . V_41 , L_12 ) ;
V_4 -> V_86 &= ~ V_132 ;
F_40 ( V_4 -> V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
V_4 -> V_70 . V_129 = false ;
V_134 = V_124 -> V_35 . V_108 - V_92 . V_150 ;
F_67 ( V_134 > V_42 ) ;
F_56 ( V_122 ) ;
F_60 ( V_4 , V_134 , V_70 -> V_126 , true ) ;
V_70 -> V_126 = ! V_70 -> V_126 ;
if ( F_58 ( V_4 ) ) {
F_47 ( V_4 -> V_10 . V_41 , L_13
L_14 ) ;
V_4 -> V_94 |= V_133 ;
F_40 ( V_4 -> V_94 , V_4 -> V_10 . V_11 + V_96 ) ;
}
}
static void V_130 ( void * V_83 )
{
struct V_3 * V_4 = V_83 ;
struct V_123 * V_70 = & V_4 -> V_70 ;
struct V_32 * V_122 = V_70 -> V_33 ;
bool V_151 = V_70 -> V_126 ;
struct V_34 * V_124 = V_70 -> V_126 ?
& V_70 -> V_127 : & V_70 -> V_128 ;
T_5 V_134 ;
struct V_145 V_92 ;
int V_119 ;
F_68 ( & V_4 -> V_10 . V_87 ) ;
V_122 -> V_40 -> V_148 ( V_122 , V_70 -> V_131 , & V_92 ) ;
V_134 = V_124 -> V_35 . V_108 - V_92 . V_150 ;
F_67 ( V_134 > V_42 ) ;
F_56 ( V_122 ) ;
V_4 -> V_70 . V_129 = false ;
V_70 -> V_126 = ! V_151 ;
V_119 = F_58 ( V_4 ) ;
F_60 ( V_4 , V_134 , V_151 , false ) ;
F_69 ( & V_4 -> V_10 . V_87 ) ;
if ( V_119 ) {
F_47 ( V_4 -> V_10 . V_41 , L_13
L_14 ) ;
V_4 -> V_94 |= V_133 ;
F_40 ( V_4 -> V_94 , V_4 -> V_10 . V_11 + V_96 ) ;
}
}
static inline void F_70 ( struct V_3 * V_4 )
{
V_4 -> V_86 &= ~ V_132 ;
F_40 ( V_4 -> V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
}
static void F_71 ( unsigned long args )
{
struct V_3 * V_4 = (struct V_3 * ) args ;
struct V_136 * V_10 = & V_4 -> V_10 . V_92 -> V_10 ;
struct V_123 * V_70 = & V_4 -> V_70 ;
struct V_32 * V_122 = V_4 -> V_70 . V_33 ;
unsigned long V_85 = 0 ;
unsigned int V_138 = 0 ;
unsigned int V_152 = 0 ;
struct V_34 * V_124 ;
int V_137 ;
struct V_145 V_92 ;
V_124 = V_70 -> V_126 ? & V_4 -> V_70 . V_127 : & V_4 -> V_70 . V_128 ;
V_122 -> V_40 -> V_148 ( V_122 , V_70 -> V_131 , & V_92 ) ;
if ( F_72 ( V_92 . V_150 < V_70 -> V_139 ) ) {
V_138 = V_124 -> V_35 . V_108 - V_70 -> V_139 ;
V_152 = V_70 -> V_139 - V_92 . V_150 ;
V_137 = F_61 ( V_10 , V_124 -> V_39 + V_138 ,
V_152 ) ;
if ( V_137 == V_152 )
V_70 -> V_139 = V_92 . V_150 ;
V_70 -> V_153 = V_154 ;
}
F_64 ( V_10 ) ;
if ( F_73 ( V_154 - V_70 -> V_153 )
> V_4 -> V_70 . V_76 ) {
F_38 ( & V_4 -> V_10 . V_87 , V_85 ) ;
F_70 ( V_4 ) ;
F_43 ( & V_4 -> V_10 . V_87 , V_85 ) ;
V_4 -> V_70 . V_129 = false ;
F_56 ( V_122 ) ;
F_74 ( & V_4 -> V_70 . V_155 ) ;
} else {
F_75 ( & V_4 -> V_70 . V_155 ,
V_154 + F_76 ( V_4 -> V_70 . V_74 ) ) ;
}
}
static void F_77 ( struct V_3 * V_4 )
{
int V_119 ;
if ( ! V_4 -> V_63 . V_33 )
return;
V_4 -> V_63 . V_39 = F_78 ( V_42 , V_43 ) ;
if ( ! V_4 -> V_63 . V_39 ) {
F_24 ( V_4 -> V_10 . V_41 , L_15 ) ;
V_4 -> V_10 . V_57 = V_4 -> V_57 ;
return;
}
F_79 ( & V_4 -> V_63 . V_35 , V_4 -> V_63 . V_39 , V_42 ) ;
V_4 -> V_10 . V_57 = V_42 ;
V_4 -> V_117 = true ;
if ( ! V_4 -> V_70 . V_33 )
goto V_156;
V_119 = F_9 ( V_4 -> V_70 . V_33 , & V_4 -> V_70 . V_128 ,
V_157 ) ;
if ( V_119 ) {
F_24 ( V_4 -> V_10 . V_41 , L_16 ,
L_17 , V_119 ) ;
goto V_156;
}
V_119 = F_9 ( V_4 -> V_70 . V_33 , & V_4 -> V_70 . V_127 ,
V_157 ) ;
if ( V_119 ) {
F_24 ( V_4 -> V_10 . V_41 , L_16 ,
L_18 , V_119 ) ;
F_16 ( V_4 -> V_70 . V_33 , & V_4 -> V_70 . V_128 ,
V_157 ) ;
goto V_156;
}
V_4 -> V_158 = true ;
V_156:
V_4 -> V_86 |= V_159 ;
F_40 ( V_4 -> V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
if ( V_4 -> V_160 -> V_161 )
F_40 ( V_162 | V_163 ,
V_4 -> V_10 . V_11 + V_164 ) ;
if ( V_4 -> V_158 ) {
if ( F_58 ( V_4 ) )
F_47 ( V_4 -> V_10 . V_41 , L_19
L_20 ) ;
if ( V_4 -> V_70 . V_74 ) {
F_80 ( & ( V_4 -> V_70 . V_155 ) ) ;
V_4 -> V_70 . V_155 . V_165 = F_71 ;
V_4 -> V_70 . V_155 . V_83 = ( unsigned long ) V_4 ;
F_75 ( & V_4 -> V_70 . V_155 ,
V_154 +
F_76 ( V_4 -> V_70 . V_74 ) ) ;
V_4 -> V_70 . V_139 = V_42 ;
V_4 -> V_70 . V_153 = V_154 ;
}
}
}
static void F_81 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_117 || V_4 -> V_158 ) )
return;
while ( F_4 ( V_4 -> V_10 . V_11 + V_12 ) & V_166 )
F_82 () ;
F_68 ( & V_4 -> V_10 . V_87 ) ;
V_4 -> V_86 &= ~ ( V_159 | V_132 | V_90 ) ;
F_40 ( V_4 -> V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
F_69 ( & V_4 -> V_10 . V_87 ) ;
if ( V_4 -> V_117 ) {
F_56 ( V_4 -> V_63 . V_33 ) ;
if ( V_4 -> V_63 . V_88 ) {
F_39 ( V_4 -> V_63 . V_33 -> V_40 -> V_41 , & V_4 -> V_63 . V_35 , 1 ,
V_89 ) ;
V_4 -> V_63 . V_88 = false ;
}
F_31 ( V_4 -> V_63 . V_39 ) ;
V_4 -> V_117 = false ;
}
if ( V_4 -> V_158 ) {
F_56 ( V_4 -> V_70 . V_33 ) ;
F_16 ( V_4 -> V_70 . V_33 , & V_4 -> V_70 . V_128 , V_157 ) ;
F_16 ( V_4 -> V_70 . V_33 , & V_4 -> V_70 . V_127 , V_157 ) ;
if ( V_4 -> V_70 . V_74 )
F_83 ( & V_4 -> V_70 . V_155 ) ;
V_4 -> V_158 = false ;
}
}
static inline bool F_84 ( struct V_3 * V_4 )
{
return V_4 -> V_158 ;
}
static inline bool F_85 ( struct V_3 * V_4 )
{
return V_4 -> V_158 && V_4 -> V_70 . V_129 ;
}
static inline void F_32 ( struct V_40 * V_41 , struct V_3 * V_4 )
{
}
static inline void F_35 ( struct V_3 * V_4 )
{
}
static inline void F_77 ( struct V_3 * V_4 )
{
}
static inline void F_81 ( struct V_3 * V_4 )
{
}
static inline bool F_51 ( struct V_3 * V_4 )
{
return false ;
}
static inline void F_52 ( struct V_3 * V_4 )
{
}
static inline bool F_53 ( struct V_3 * V_4 )
{
return false ;
}
static inline void F_65 ( struct V_3 * V_4 )
{
}
static inline void F_70 ( struct V_3 * V_4 )
{
}
static inline int F_58 ( struct V_3 * V_4 )
{
return - V_125 ;
}
static inline bool F_84 ( struct V_3 * V_4 )
{
return false ;
}
static inline bool F_85 ( struct V_3 * V_4 )
{
return false ;
}
static void F_86 ( struct V_121 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
V_4 -> V_94 &= ~ V_95 ;
F_40 ( V_4 -> V_94 , V_4 -> V_10 . V_11 + V_96 ) ;
F_52 ( V_4 ) ;
}
static void F_87 ( struct V_121 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
if ( ! F_53 ( V_4 ) ) {
V_4 -> V_94 |= V_95 ;
F_40 ( V_4 -> V_94 , V_4 -> V_10 . V_11 + V_96 ) ;
}
}
static void F_88 ( struct V_121 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
V_4 -> V_94 &= ~ ( V_133 | V_167 | V_168 |
V_169 | V_170 | V_171 ) ;
F_40 ( V_4 -> V_94 , V_4 -> V_10 . V_11 + V_96 ) ;
F_70 ( V_4 ) ;
}
static void F_89 ( struct V_121 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
V_4 -> V_94 |= V_172 | V_173 | V_174 | V_175 ;
F_40 ( V_4 -> V_94 , V_4 -> V_10 . V_11 + V_96 ) ;
}
static void F_90 ( struct V_3 * V_4 )
{
F_3 ( V_4 ) ;
F_55 ( & V_4 -> V_10 . V_87 ) ;
F_64 ( & V_4 -> V_10 . V_92 -> V_10 ) ;
if ( F_84 ( V_4 ) ) {
if ( F_58 ( V_4 ) ) {
F_47 ( V_4 -> V_10 . V_41 , L_21
L_22 ) ;
V_4 -> V_94 |= V_133 ;
} else {
V_4 -> V_94 &= ~ V_133 ;
#ifdef F_91
if ( V_4 -> V_70 . V_74 ) {
V_4 -> V_70 . V_153 = V_154 ;
V_4 -> V_70 . V_139 = V_42 ;
F_75 ( & V_4 -> V_70 . V_155 ,
V_154 +
F_76 ( V_4 -> V_70 . V_74 ) ) ;
}
#endif
}
F_40 ( V_4 -> V_94 , V_4 -> V_10 . V_11 + V_96 ) ;
}
F_57 ( & V_4 -> V_10 . V_87 ) ;
}
static void F_92 ( struct V_3 * V_4 )
{
struct V_101 * V_93 = & V_4 -> V_10 . V_92 -> V_93 ;
int V_102 ;
if ( V_4 -> V_10 . V_118 ) {
F_40 ( V_4 -> V_10 . V_118 , V_4 -> V_10 . V_11 + V_14 ) ;
V_4 -> V_10 . V_17 . V_115 ++ ;
V_4 -> V_10 . V_118 = 0 ;
return;
}
if ( F_42 ( V_93 ) || F_41 ( & V_4 -> V_10 ) ) {
F_86 ( & V_4 -> V_10 ) ;
return;
}
if ( F_51 ( V_4 ) )
return;
V_102 = V_4 -> V_57 >> 1 ;
do {
F_40 ( V_93 -> V_39 [ V_93 -> V_103 ] , V_4 -> V_10 . V_11 + V_14 ) ;
V_93 -> V_103 = ( V_93 -> V_103 + 1 ) & ( V_106 - 1 ) ;
V_4 -> V_10 . V_17 . V_115 ++ ;
if ( F_42 ( V_93 ) )
break;
} while ( -- V_102 > 0 );
if ( F_45 ( V_93 ) < V_116 )
F_50 ( & V_4 -> V_10 ) ;
if ( F_42 ( V_93 ) )
F_86 ( & V_4 -> V_10 ) ;
}
static void F_93 ( struct V_3 * V_4 )
{
unsigned int V_5 , V_176 ;
V_5 = F_4 ( V_4 -> V_10 . V_11 + V_12 ) & V_177 ;
V_176 = V_5 ^ V_4 -> V_178 ;
V_4 -> V_178 = V_5 ;
if ( ! V_176 )
return;
if ( V_176 & V_179 )
F_94 ( & V_4 -> V_10 , V_5 & V_179 ) ;
if ( V_176 & V_180 )
V_4 -> V_10 . V_17 . V_181 ++ ;
if ( V_176 & V_182 )
F_95 ( & V_4 -> V_10 , V_5 & V_182 ) ;
F_96 ( & V_4 -> V_10 . V_92 -> V_10 . V_183 ) ;
}
static T_7 F_97 ( int V_184 , void * V_185 )
{
struct V_3 * V_4 = V_185 ;
unsigned long V_85 ;
unsigned int V_5 , V_186 = V_187 ;
int V_188 = 0 ;
unsigned int V_189 ;
F_38 ( & V_4 -> V_10 . V_87 , V_85 ) ;
V_5 = F_4 ( V_4 -> V_10 . V_11 + V_190 ) ;
if ( V_5 ) {
do {
if ( V_4 -> V_160 -> V_191 ) {
F_40 ( 0x00 , V_4 -> V_10 . V_11 + V_144 ) ;
V_189 = F_4 ( V_4 -> V_10 . V_11 + V_144 ) ;
V_189 = F_4 ( V_4 -> V_10 . V_11 + V_144 ) ;
}
F_40 ( V_5 & ~ ( V_192 | V_193 |
V_194 ) ,
V_4 -> V_10 . V_11 + V_144 ) ;
if ( V_5 & ( V_193 | V_194 ) ) {
if ( F_85 ( V_4 ) )
F_65 ( V_4 ) ;
else
F_90 ( V_4 ) ;
}
if ( V_5 & ( V_195 | V_196 |
V_197 | V_198 ) )
F_93 ( V_4 ) ;
if ( V_5 & V_192 )
F_92 ( V_4 ) ;
if ( V_186 -- == 0 )
break;
V_5 = F_4 ( V_4 -> V_10 . V_11 + V_190 ) ;
} while ( V_5 != 0 );
V_188 = 1 ;
}
F_43 ( & V_4 -> V_10 . V_87 , V_85 ) ;
return F_98 ( V_188 ) ;
}
static unsigned int F_99 ( struct V_121 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned int V_5 = F_4 ( V_4 -> V_10 . V_11 + V_12 ) ;
return V_5 & ( V_166 | V_120 ) ? 0 : V_199 ;
}
static unsigned int F_100 ( struct V_121 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned int V_200 = 0 ;
unsigned int V_5 = F_4 ( V_4 -> V_10 . V_11 + V_12 ) ;
#define F_101 ( T_8 , T_9 ) \
if (status & uartbit) \
result |= tiocmbit
F_101 ( V_179 , V_201 ) ;
F_101 ( V_180 , V_202 ) ;
F_101 ( V_182 , V_203 ) ;
F_101 ( V_204 , V_205 ) ;
#undef F_101
return V_200 ;
}
static void F_102 ( struct V_121 * V_10 , unsigned int V_206 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned int V_207 ;
V_207 = F_4 ( V_4 -> V_10 . V_11 + V_208 ) ;
#define F_101 ( T_9 , T_8 ) \
if (mctrl & tiocmbit) \
cr |= uartbit; \
else \
cr &= ~uartbit
F_101 ( V_209 , V_210 ) ;
F_101 ( V_211 , V_212 ) ;
F_101 ( V_213 , V_214 ) ;
F_101 ( V_215 , V_216 ) ;
F_101 ( V_217 , V_218 ) ;
if ( V_4 -> V_219 ) {
F_101 ( V_209 , V_220 ) ;
}
#undef F_101
F_40 ( V_207 , V_4 -> V_10 . V_11 + V_208 ) ;
}
static void F_103 ( struct V_121 * V_10 , int V_221 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned long V_85 ;
unsigned int V_222 ;
F_38 ( & V_4 -> V_10 . V_87 , V_85 ) ;
V_222 = F_4 ( V_4 -> V_10 . V_11 + V_4 -> V_223 ) ;
if ( V_221 == - 1 )
V_222 |= V_224 ;
else
V_222 &= ~ V_224 ;
F_40 ( V_222 , V_4 -> V_10 . V_11 + V_4 -> V_223 ) ;
F_43 ( & V_4 -> V_10 . V_87 , V_85 ) ;
}
static void F_104 ( struct V_121 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned char T_10 * V_225 = V_4 -> V_10 . V_11 ;
F_40 ( F_4 ( V_225 + V_190 ) , V_225 + V_144 ) ;
F_40 ( F_4 ( V_225 + V_96 ) & ~ V_95 , V_225 + V_96 ) ;
}
static int F_105 ( struct V_121 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned int V_5 ;
F_104 ( V_10 ) ;
V_5 = F_4 ( V_4 -> V_10 . V_11 + V_12 ) ;
if ( V_5 & V_13 )
return V_226 ;
return F_4 ( V_4 -> V_10 . V_11 + V_14 ) ;
}
static void F_106 ( struct V_121 * V_10 ,
unsigned char V_6 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
while ( F_4 ( V_4 -> V_10 . V_11 + V_12 ) & V_120 )
F_82 () ;
F_40 ( V_6 , V_4 -> V_10 . V_11 + V_14 ) ;
}
static int F_107 ( struct V_121 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
int V_227 ;
if ( ! F_108 ( V_4 -> V_228 ) ) {
V_227 = F_109 ( V_4 -> V_229 , V_4 -> V_228 ) ;
if ( V_227 )
F_24 ( V_10 -> V_41 ,
L_23 ) ;
}
V_227 = F_110 ( V_4 -> V_230 ) ;
if ( V_227 )
goto V_231;
V_4 -> V_10 . V_232 = F_111 ( V_4 -> V_230 ) ;
F_40 ( V_140 | V_141 | V_142 | V_143 |
V_193 | V_194 , V_4 -> V_10 . V_11 + V_144 ) ;
V_4 -> V_94 = F_4 ( V_4 -> V_10 . V_11 + V_96 ) ;
F_40 ( V_167 | V_133 , V_4 -> V_10 . V_11 + V_96 ) ;
if ( V_4 -> V_10 . V_41 -> V_47 ) {
struct V_45 * V_46 ;
V_46 = V_4 -> V_10 . V_41 -> V_47 ;
if ( V_46 -> V_233 )
V_46 -> V_233 () ;
}
return 0 ;
V_231:
return V_227 ;
}
static int F_112 ( struct V_121 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned int V_207 ;
int V_227 ;
V_227 = F_107 ( V_10 ) ;
if ( V_227 )
goto V_234;
F_40 ( V_4 -> V_94 , V_4 -> V_10 . V_11 + V_96 ) ;
V_227 = F_113 ( V_4 -> V_10 . V_184 , F_97 , 0 , L_24 , V_4 ) ;
if ( V_227 )
goto V_234;
F_40 ( V_4 -> V_160 -> V_235 , V_4 -> V_10 . V_11 + V_236 ) ;
V_207 = V_237 | V_238 | V_218 ;
F_40 ( V_207 , V_4 -> V_10 . V_11 + V_208 ) ;
F_40 ( 0 , V_4 -> V_10 . V_11 + V_239 ) ;
F_40 ( 1 , V_4 -> V_10 . V_11 + V_240 ) ;
F_40 ( 0 , V_4 -> V_10 . V_11 + V_4 -> V_241 ) ;
if ( V_4 -> V_223 != V_4 -> V_241 ) {
int V_242 ;
for ( V_242 = 0 ; V_242 < 10 ; ++ V_242 )
F_40 ( 0xff , V_4 -> V_10 . V_11 + V_190 ) ;
F_40 ( 0 , V_4 -> V_10 . V_11 + V_4 -> V_223 ) ;
}
F_40 ( 0 , V_4 -> V_10 . V_11 + V_14 ) ;
while ( F_4 ( V_4 -> V_10 . V_11 + V_12 ) & V_166 )
F_82 () ;
V_207 = V_4 -> V_243 & ( V_210 | V_212 ) ;
V_207 |= V_237 | V_244 | V_238 ;
F_40 ( V_207 , V_4 -> V_10 . V_11 + V_208 ) ;
V_4 -> V_178 = F_4 ( V_4 -> V_10 . V_11 + V_12 ) & V_177 ;
F_77 ( V_4 ) ;
F_68 ( & V_4 -> V_10 . V_87 ) ;
F_40 ( V_193 | V_194 ,
V_4 -> V_10 . V_11 + V_144 ) ;
V_4 -> V_94 = V_167 ;
if ( ! F_85 ( V_4 ) )
V_4 -> V_94 |= V_133 ;
F_40 ( V_4 -> V_94 , V_4 -> V_10 . V_11 + V_96 ) ;
F_69 ( & V_4 -> V_10 . V_87 ) ;
return 0 ;
V_234:
F_114 ( V_4 -> V_230 ) ;
return V_227 ;
}
static void F_115 ( struct V_3 * V_4 ,
unsigned int V_245 )
{
unsigned long V_246 ;
V_246 = F_4 ( V_4 -> V_10 . V_11 + V_245 ) ;
V_246 &= ~ ( V_224 | V_247 ) ;
F_40 ( V_246 , V_4 -> V_10 . V_11 + V_245 ) ;
}
static void F_116 ( struct V_121 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned int V_207 ;
int V_227 ;
F_68 ( & V_4 -> V_10 . V_87 ) ;
V_4 -> V_94 = 0 ;
F_40 ( V_4 -> V_94 , V_4 -> V_10 . V_11 + V_96 ) ;
F_40 ( 0xffff , V_4 -> V_10 . V_11 + V_144 ) ;
F_69 ( & V_4 -> V_10 . V_87 ) ;
F_81 ( V_4 ) ;
F_117 ( V_4 -> V_10 . V_184 , V_4 ) ;
V_4 -> V_219 = false ;
V_207 = F_4 ( V_4 -> V_10 . V_11 + V_208 ) ;
V_4 -> V_243 = V_207 ;
V_207 &= V_210 | V_212 ;
V_207 |= V_237 | V_238 ;
F_40 ( V_207 , V_4 -> V_10 . V_11 + V_208 ) ;
F_115 ( V_4 , V_4 -> V_241 ) ;
if ( V_4 -> V_241 != V_4 -> V_223 )
F_115 ( V_4 , V_4 -> V_223 ) ;
F_114 ( V_4 -> V_230 ) ;
if ( ! F_108 ( V_4 -> V_248 ) ) {
V_227 = F_109 ( V_4 -> V_229 , V_4 -> V_248 ) ;
if ( V_227 )
F_24 ( V_10 -> V_41 ,
L_25 ) ;
}
if ( V_4 -> V_10 . V_41 -> V_47 ) {
struct V_45 * V_46 ;
V_46 = V_4 -> V_10 . V_41 -> V_47 ;
if ( V_46 -> exit )
V_46 -> exit () ;
}
}
static void
F_118 ( struct V_121 * V_10 , struct V_249 * V_250 ,
struct V_249 * V_251 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned int V_222 , V_243 ;
unsigned long V_85 ;
unsigned int V_252 , V_253 , V_254 ;
if ( V_4 -> V_160 -> V_255 )
V_254 = 8 ;
else
V_254 = 16 ;
V_252 = F_119 ( V_10 , V_250 , V_251 , 0 ,
V_10 -> V_232 / V_254 ) ;
#ifdef F_91
if ( V_4 -> V_70 . V_73 )
V_4 -> V_70 . V_74 = F_120 ( 10000000 , V_252 ) ;
#endif
if ( V_252 > V_10 -> V_232 / 16 )
V_253 = F_121 ( V_10 -> V_232 * 8 , V_252 ) ;
else
V_253 = F_121 ( V_10 -> V_232 * 4 , V_252 ) ;
switch ( V_250 -> V_256 & V_257 ) {
case V_258 :
V_222 = V_259 ;
break;
case V_260 :
V_222 = V_261 ;
break;
case V_262 :
V_222 = V_263 ;
break;
default:
V_222 = V_264 ;
break;
}
if ( V_250 -> V_256 & V_265 )
V_222 |= V_266 ;
if ( V_250 -> V_256 & V_267 ) {
V_222 |= V_268 ;
if ( ! ( V_250 -> V_256 & V_269 ) )
V_222 |= V_270 ;
}
if ( V_4 -> V_57 > 1 )
V_222 |= V_247 ;
F_38 ( & V_10 -> V_87 , V_85 ) ;
F_122 ( V_10 , V_250 -> V_256 , V_252 ) ;
V_10 -> V_28 = V_26 | 255 ;
if ( V_250 -> V_271 & V_272 )
V_10 -> V_28 |= V_21 | V_22 ;
if ( V_250 -> V_271 & ( V_273 | V_274 ) )
V_10 -> V_28 |= V_20 ;
V_10 -> V_275 = 0 ;
if ( V_250 -> V_271 & V_276 )
V_10 -> V_275 |= V_21 | V_22 ;
if ( V_250 -> V_271 & V_277 ) {
V_10 -> V_275 |= V_20 ;
if ( V_250 -> V_271 & V_276 )
V_10 -> V_275 |= V_26 ;
}
if ( ( V_250 -> V_256 & V_278 ) == 0 )
V_10 -> V_275 |= V_15 ;
if ( F_123 ( V_10 , V_250 -> V_256 ) )
F_89 ( V_10 ) ;
V_243 = F_4 ( V_10 -> V_11 + V_208 ) ;
F_40 ( 0 , V_10 -> V_11 + V_208 ) ;
if ( V_250 -> V_256 & V_279 ) {
if ( V_243 & V_210 )
V_243 |= V_220 ;
V_243 |= V_280 ;
V_4 -> V_219 = true ;
} else {
V_243 &= ~ ( V_280 | V_220 ) ;
V_4 -> V_219 = false ;
}
if ( V_4 -> V_160 -> V_255 ) {
if ( V_252 > V_10 -> V_232 / 16 )
V_243 |= V_281 ;
else
V_243 &= ~ V_281 ;
}
if ( V_4 -> V_160 -> V_255 ) {
if ( ( V_252 >= 3000000 ) && ( V_252 < 3250000 ) && ( V_253 > 1 ) )
V_253 -= 1 ;
else if ( ( V_252 > 3250000 ) && ( V_253 > 2 ) )
V_253 -= 2 ;
}
F_40 ( V_253 & 0x3f , V_10 -> V_11 + V_239 ) ;
F_40 ( V_253 >> 6 , V_10 -> V_11 + V_240 ) ;
F_40 ( V_222 , V_10 -> V_11 + V_4 -> V_241 ) ;
if ( V_4 -> V_241 != V_4 -> V_223 ) {
int V_242 ;
for ( V_242 = 0 ; V_242 < 10 ; ++ V_242 )
F_40 ( 0xff , V_4 -> V_10 . V_11 + V_190 ) ;
F_40 ( V_222 , V_10 -> V_11 + V_4 -> V_223 ) ;
}
F_40 ( V_243 , V_10 -> V_11 + V_208 ) ;
F_43 ( & V_10 -> V_87 , V_85 ) ;
}
static const char * F_124 ( struct V_121 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
return V_4 -> V_10 . type == V_282 ? V_4 -> type : NULL ;
}
static void F_125 ( struct V_121 * V_10 )
{
F_126 ( V_10 -> V_51 , V_283 ) ;
}
static int F_127 ( struct V_121 * V_10 )
{
return F_128 ( V_10 -> V_51 , V_283 , L_24 )
!= NULL ? 0 : - V_109 ;
}
static void F_129 ( struct V_121 * V_10 , int V_85 )
{
if ( V_85 & V_284 ) {
V_10 -> type = V_282 ;
F_127 ( V_10 ) ;
}
}
static int F_130 ( struct V_121 * V_10 , struct V_285 * V_286 )
{
int V_119 = 0 ;
if ( V_286 -> type != V_287 && V_286 -> type != V_282 )
V_119 = - V_288 ;
if ( V_286 -> V_184 < 0 || V_286 -> V_184 >= V_289 )
V_119 = - V_288 ;
if ( V_286 -> V_290 < 9600 )
V_119 = - V_288 ;
return V_119 ;
}
static void F_131 ( struct V_121 * V_10 , int V_6 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
while ( F_4 ( V_4 -> V_10 . V_11 + V_12 ) & V_120 )
F_82 () ;
F_40 ( V_6 , V_4 -> V_10 . V_11 + V_14 ) ;
}
static void
F_132 ( struct V_291 * V_292 , const char * V_293 , unsigned int V_102 )
{
struct V_3 * V_4 = V_294 [ V_292 -> V_295 ] ;
unsigned int V_5 , V_243 , V_296 ;
unsigned long V_85 ;
int V_297 = 1 ;
F_133 ( V_4 -> V_230 ) ;
F_134 ( V_85 ) ;
if ( V_4 -> V_10 . V_298 )
V_297 = 0 ;
else if ( V_299 )
V_297 = F_135 ( & V_4 -> V_10 . V_87 ) ;
else
F_57 ( & V_4 -> V_10 . V_87 ) ;
V_243 = F_4 ( V_4 -> V_10 . V_11 + V_208 ) ;
V_296 = V_243 & ~ V_280 ;
V_296 |= V_237 | V_238 ;
F_40 ( V_296 , V_4 -> V_10 . V_11 + V_208 ) ;
F_136 ( & V_4 -> V_10 , V_293 , V_102 , F_131 ) ;
do {
V_5 = F_4 ( V_4 -> V_10 . V_11 + V_12 ) ;
} while ( V_5 & V_166 );
F_40 ( V_243 , V_4 -> V_10 . V_11 + V_208 ) ;
if ( V_297 )
F_55 ( & V_4 -> V_10 . V_87 ) ;
F_137 ( V_85 ) ;
F_138 ( V_4 -> V_230 ) ;
}
static void T_4
F_139 ( struct V_3 * V_4 , int * V_252 ,
int * V_24 , int * V_300 )
{
if ( F_4 ( V_4 -> V_10 . V_11 + V_208 ) & V_237 ) {
unsigned int V_222 , V_301 , V_302 ;
V_222 = F_4 ( V_4 -> V_10 . V_11 + V_4 -> V_223 ) ;
* V_24 = 'n' ;
if ( V_222 & V_268 ) {
if ( V_222 & V_270 )
* V_24 = 'e' ;
else
* V_24 = 'o' ;
}
if ( ( V_222 & 0x60 ) == V_263 )
* V_300 = 7 ;
else
* V_300 = 8 ;
V_301 = F_4 ( V_4 -> V_10 . V_11 + V_240 ) ;
V_302 = F_4 ( V_4 -> V_10 . V_11 + V_239 ) ;
* V_252 = V_4 -> V_10 . V_232 * 4 / ( 64 * V_301 + V_302 ) ;
if ( V_4 -> V_160 -> V_255 ) {
if ( F_4 ( V_4 -> V_10 . V_11 + V_208 )
& V_281 )
* V_252 *= 2 ;
}
}
}
static int T_4 F_140 ( struct V_291 * V_292 , char * V_303 )
{
struct V_3 * V_4 ;
int V_252 = 38400 ;
int V_300 = 8 ;
int V_24 = 'n' ;
int V_304 = 'n' ;
int V_119 ;
if ( V_292 -> V_295 >= V_305 )
V_292 -> V_295 = 0 ;
V_4 = V_294 [ V_292 -> V_295 ] ;
if ( ! V_4 )
return - V_306 ;
if ( ! F_108 ( V_4 -> V_228 ) ) {
V_119 = F_109 ( V_4 -> V_229 , V_4 -> V_228 ) ;
if ( V_119 )
F_24 ( V_4 -> V_10 . V_41 ,
L_23 ) ;
}
V_119 = F_141 ( V_4 -> V_230 ) ;
if ( V_119 )
return V_119 ;
if ( V_4 -> V_10 . V_41 -> V_47 ) {
struct V_45 * V_46 ;
V_46 = V_4 -> V_10 . V_41 -> V_47 ;
if ( V_46 -> V_233 )
V_46 -> V_233 () ;
}
V_4 -> V_10 . V_232 = F_111 ( V_4 -> V_230 ) ;
if ( V_303 )
F_142 ( V_303 , & V_252 , & V_24 , & V_300 , & V_304 ) ;
else
F_139 ( V_4 , & V_252 , & V_24 , & V_300 ) ;
return F_143 ( & V_4 -> V_10 , V_292 , V_252 , V_24 , V_300 , V_304 ) ;
}
static int F_144 ( int V_295 , struct V_40 * V_41 )
{
struct V_307 * V_308 ;
static bool V_309 = false ;
static bool V_310 = false ;
int V_119 = V_295 ;
if ( ! F_145 ( V_311 ) )
return V_119 ;
V_308 = V_41 -> V_312 ;
if ( ! V_308 )
return V_119 ;
V_119 = F_146 ( V_308 , L_26 ) ;
if ( F_147 ( V_119 ) ) {
V_310 = true ;
V_119 = V_295 ;
} else {
V_309 = true ;
if ( V_119 >= F_148 ( V_294 ) || V_294 [ V_119 ] != NULL ) {
F_62 ( V_41 , L_27 , V_119 ) ;
V_119 = V_295 ;
}
}
if ( V_309 && V_310 )
F_62 ( V_41 , L_28 ) ;
return V_119 ;
}
static int F_149 ( struct V_313 * V_41 , const struct V_314 * V_315 )
{
struct V_3 * V_4 ;
struct V_316 * V_160 = V_315 -> V_83 ;
void T_10 * V_317 ;
int V_242 , V_119 ;
for ( V_242 = 0 ; V_242 < F_148 ( V_294 ) ; V_242 ++ )
if ( V_294 [ V_242 ] == NULL )
break;
if ( V_242 == F_148 ( V_294 ) ) {
V_119 = - V_109 ;
goto V_231;
}
V_4 = F_150 ( & V_41 -> V_41 , sizeof( struct V_3 ) ,
V_43 ) ;
if ( V_4 == NULL ) {
V_119 = - V_44 ;
goto V_231;
}
V_242 = F_144 ( V_242 , & V_41 -> V_41 ) ;
V_317 = F_151 ( & V_41 -> V_41 , V_41 -> V_318 . V_319 ,
F_152 ( & V_41 -> V_318 ) ) ;
if ( ! V_317 ) {
V_119 = - V_44 ;
goto V_231;
}
V_4 -> V_229 = F_153 ( & V_41 -> V_41 ) ;
if ( F_108 ( V_4 -> V_229 ) ) {
V_119 = F_154 ( V_4 -> V_229 ) ;
goto V_231;
}
V_4 -> V_228 = F_155 ( V_4 -> V_229 ,
V_320 ) ;
if ( F_108 ( V_4 -> V_228 ) )
F_24 ( & V_41 -> V_41 , L_29 ) ;
V_4 -> V_248 = F_155 ( V_4 -> V_229 ,
V_321 ) ;
if ( F_108 ( V_4 -> V_248 ) )
F_47 ( & V_41 -> V_41 , L_30 ) ;
V_4 -> V_230 = F_156 ( & V_41 -> V_41 , NULL ) ;
if ( F_108 ( V_4 -> V_230 ) ) {
V_119 = F_154 ( V_4 -> V_230 ) ;
goto V_231;
}
V_4 -> V_160 = V_160 ;
V_4 -> V_241 = V_160 -> V_241 ;
V_4 -> V_223 = V_160 -> V_223 ;
V_4 -> V_243 = 0 ;
V_4 -> V_57 = V_160 -> V_322 ( V_41 -> V_1 ) ;
V_4 -> V_10 . V_41 = & V_41 -> V_41 ;
V_4 -> V_10 . V_51 = V_41 -> V_318 . V_319 ;
V_4 -> V_10 . V_11 = V_317 ;
V_4 -> V_10 . V_323 = V_324 ;
V_4 -> V_10 . V_184 = V_41 -> V_184 [ 0 ] ;
V_4 -> V_10 . V_57 = V_4 -> V_57 ;
V_4 -> V_10 . V_325 = & V_326 ;
V_4 -> V_10 . V_85 = V_327 ;
V_4 -> V_10 . line = V_242 ;
F_32 ( & V_41 -> V_41 , V_4 ) ;
F_40 ( 0 , V_4 -> V_10 . V_11 + V_96 ) ;
F_40 ( 0xffff , V_4 -> V_10 . V_11 + V_144 ) ;
snprintf ( V_4 -> type , sizeof( V_4 -> type ) , L_31 , F_157 ( V_41 ) ) ;
V_294 [ V_242 ] = V_4 ;
F_158 ( V_41 , V_4 ) ;
V_119 = F_159 ( & V_328 , & V_4 -> V_10 ) ;
if ( V_119 ) {
F_158 ( V_41 , NULL ) ;
V_294 [ V_242 ] = NULL ;
F_35 ( V_4 ) ;
}
V_231:
return V_119 ;
}
static int F_160 ( struct V_313 * V_41 )
{
struct V_3 * V_4 = F_161 ( V_41 ) ;
int V_242 ;
F_158 ( V_41 , NULL ) ;
F_162 ( & V_328 , & V_4 -> V_10 ) ;
for ( V_242 = 0 ; V_242 < F_148 ( V_294 ) ; V_242 ++ )
if ( V_294 [ V_242 ] == V_4 )
V_294 [ V_242 ] = NULL ;
F_35 ( V_4 ) ;
return 0 ;
}
static int F_163 ( struct V_313 * V_41 , T_11 V_92 )
{
struct V_3 * V_4 = F_161 ( V_41 ) ;
if ( ! V_4 )
return - V_288 ;
return F_164 ( & V_328 , & V_4 -> V_10 ) ;
}
static int F_165 ( struct V_313 * V_41 )
{
struct V_3 * V_4 = F_161 ( V_41 ) ;
if ( ! V_4 )
return - V_288 ;
return F_166 ( & V_328 , & V_4 -> V_10 ) ;
}
static int T_4 F_167 ( void )
{
int V_119 ;
F_168 ( V_329 L_32 ) ;
V_119 = F_169 ( & V_328 ) ;
if ( V_119 == 0 ) {
V_119 = F_170 ( & V_330 ) ;
if ( V_119 )
F_171 ( & V_328 ) ;
}
return V_119 ;
}
static void T_12 F_172 ( void )
{
F_173 ( & V_330 ) ;
F_171 ( & V_328 ) ;
}
