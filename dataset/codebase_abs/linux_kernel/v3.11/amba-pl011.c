static unsigned int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) < 3 ? 16 : 32 ;
}
static unsigned int F_3 ( struct V_1 * V_2 )
{
return 64 ;
}
static int F_4 ( struct V_3 * V_4 )
{
T_1 V_5 , V_6 ;
unsigned int V_7 , V_8 = 256 ;
int V_9 = 0 ;
while ( V_8 -- ) {
V_5 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) ;
if ( V_5 & V_13 )
break;
V_6 = F_5 ( V_4 -> V_10 . V_11 + V_14 ) |
V_15 ;
V_7 = V_16 ;
V_4 -> V_10 . V_17 . V_18 ++ ;
V_9 ++ ;
if ( F_6 ( V_6 & V_19 ) ) {
if ( V_6 & V_20 ) {
V_6 &= ~ ( V_21 | V_22 ) ;
V_4 -> V_10 . V_17 . V_23 ++ ;
if ( F_7 ( & V_4 -> V_10 ) )
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
if ( F_8 ( & V_4 -> V_10 , V_6 & 255 ) )
continue;
F_9 ( & V_4 -> V_10 , V_6 , V_26 , V_6 , V_7 ) ;
}
return V_9 ;
}
static int F_10 ( struct V_32 * V_33 , struct V_34 * V_35 ,
enum V_36 V_37 )
{
T_2 V_38 ;
V_35 -> V_39 = F_11 ( V_33 -> V_40 -> V_2 ,
V_41 , & V_38 , V_42 ) ;
if ( ! V_35 -> V_39 )
return - V_43 ;
F_12 ( & V_35 -> V_35 , 1 ) ;
F_13 ( & V_35 -> V_35 , F_14 ( V_38 ) ,
V_41 , F_15 ( V_38 ) ) ;
F_16 ( & V_35 -> V_35 ) = V_38 ;
return 0 ;
}
static void F_17 ( struct V_32 * V_33 , struct V_34 * V_35 ,
enum V_36 V_37 )
{
if ( V_35 -> V_39 ) {
F_18 ( V_33 -> V_40 -> V_2 ,
V_41 , V_35 -> V_39 ,
F_16 ( & V_35 -> V_35 ) ) ;
}
}
static void F_19 ( struct V_40 * V_2 , struct V_3 * V_4 )
{
struct V_44 * V_45 = V_4 -> V_10 . V_2 -> V_46 ;
struct V_47 V_48 = {
. V_49 = V_4 -> V_10 . V_50 + V_14 ,
. V_51 = V_52 ,
. V_53 = V_54 ,
. V_55 = V_4 -> V_56 >> 1 ,
. V_57 = false ,
} ;
struct V_32 * V_33 ;
T_3 V_58 ;
V_33 = F_20 ( V_2 , L_1 ) ;
if ( ! V_33 ) {
if ( ! V_45 || ! V_45 -> V_59 ) {
F_21 ( V_4 -> V_10 . V_2 , L_2 ) ;
return;
}
F_22 ( V_58 ) ;
F_23 ( V_60 , V_58 ) ;
V_33 = F_24 ( V_58 , V_45 -> V_59 ,
V_45 -> V_61 ) ;
if ( ! V_33 ) {
F_25 ( V_4 -> V_10 . V_2 , L_3 ) ;
return;
}
}
F_26 ( V_33 , & V_48 ) ;
V_4 -> V_62 . V_33 = V_33 ;
F_21 ( V_4 -> V_10 . V_2 , L_4 ,
F_27 ( V_4 -> V_62 . V_33 ) ) ;
V_33 = F_20 ( V_2 , L_5 ) ;
if ( ! V_33 && V_45 -> V_63 ) {
V_33 = F_24 ( V_58 , V_45 -> V_59 , V_45 -> V_63 ) ;
if ( ! V_33 ) {
F_25 ( V_4 -> V_10 . V_2 , L_6 ) ;
return;
}
}
if ( V_33 ) {
struct V_47 V_64 = {
. V_65 = V_4 -> V_10 . V_50 + V_14 ,
. V_66 = V_52 ,
. V_53 = V_67 ,
. V_68 = V_4 -> V_56 >> 1 ,
. V_57 = false ,
} ;
F_26 ( V_33 , & V_64 ) ;
V_4 -> V_69 . V_33 = V_33 ;
if ( V_45 && V_45 -> V_70 ) {
if ( V_45 -> V_71 ) {
V_4 -> V_69 . V_72 = false ;
V_4 -> V_69 . V_73 = V_45 -> V_71 ;
} else {
V_4 -> V_69 . V_72 = true ;
V_4 -> V_69 . V_73 = 100 ;
}
if ( V_45 -> V_74 )
V_4 -> V_69 . V_75 =
V_45 -> V_74 ;
else
V_4 -> V_69 . V_75 = 3000 ;
} else
V_4 -> V_69 . V_72 = false ;
F_21 ( V_4 -> V_10 . V_2 , L_7 ,
F_27 ( V_4 -> V_69 . V_33 ) ) ;
}
}
static int T_4 F_28 ( void )
{
struct V_76 * V_77 , * V_78 ;
F_29 (node, tmp, &pl011_dma_uarts) {
struct V_79 * V_80 = F_30 ( V_77 , struct V_79 , V_77 ) ;
F_19 ( V_80 -> V_2 , V_80 -> V_4 ) ;
F_31 ( V_77 ) ;
F_32 ( V_80 ) ;
}
return 0 ;
}
static void F_33 ( struct V_40 * V_2 , struct V_3 * V_4 )
{
struct V_79 * V_80 = F_34 ( sizeof( struct V_79 ) , V_42 ) ;
if ( V_80 ) {
V_80 -> V_4 = V_4 ;
V_80 -> V_2 = V_2 ;
F_35 ( & V_80 -> V_77 , & V_81 ) ;
}
}
static void F_33 ( struct V_40 * V_2 , struct V_3 * V_4 )
{
F_19 ( V_2 , V_4 ) ;
}
static void F_36 ( struct V_3 * V_4 )
{
if ( V_4 -> V_62 . V_33 )
F_37 ( V_4 -> V_62 . V_33 ) ;
if ( V_4 -> V_69 . V_33 )
F_37 ( V_4 -> V_69 . V_33 ) ;
}
static void F_38 ( void * V_82 )
{
struct V_3 * V_4 = V_82 ;
struct V_83 * V_62 = & V_4 -> V_62 ;
unsigned long V_84 ;
T_1 V_85 ;
F_39 ( & V_4 -> V_10 . V_86 , V_84 ) ;
if ( V_4 -> V_62 . V_87 )
F_40 ( V_62 -> V_33 -> V_40 -> V_2 , & V_62 -> V_35 , 1 ,
V_88 ) ;
V_85 = V_4 -> V_85 ;
V_4 -> V_85 = V_85 & ~ V_89 ;
F_41 ( V_4 -> V_85 , V_4 -> V_10 . V_11 + V_90 ) ;
if ( ! ( V_85 & V_89 ) || F_42 ( & V_4 -> V_10 ) ||
F_43 ( & V_4 -> V_10 . V_91 -> V_92 ) ) {
V_4 -> V_62 . V_87 = false ;
F_44 ( & V_4 -> V_10 . V_86 , V_84 ) ;
return;
}
if ( F_45 ( V_4 ) <= 0 ) {
V_4 -> V_93 |= V_94 ;
F_41 ( V_4 -> V_93 , V_4 -> V_10 . V_11 + V_95 ) ;
}
F_44 ( & V_4 -> V_10 . V_86 , V_84 ) ;
}
static int F_45 ( struct V_3 * V_4 )
{
struct V_83 * V_62 = & V_4 -> V_62 ;
struct V_32 * V_33 = V_62 -> V_33 ;
struct V_96 * V_97 = V_33 -> V_40 ;
struct V_98 * V_99 ;
struct V_100 * V_92 = & V_4 -> V_10 . V_91 -> V_92 ;
unsigned int V_101 ;
V_101 = F_46 ( V_92 ) ;
if ( V_101 < ( V_4 -> V_56 >> 1 ) ) {
V_4 -> V_62 . V_87 = false ;
return 0 ;
}
V_101 -= 1 ;
if ( V_101 > V_41 )
V_101 = V_41 ;
if ( V_92 -> V_102 < V_92 -> V_103 )
memcpy ( & V_62 -> V_39 [ 0 ] , & V_92 -> V_39 [ V_92 -> V_102 ] , V_101 ) ;
else {
T_5 V_104 = V_105 - V_92 -> V_102 ;
T_5 V_106 = V_92 -> V_103 ;
memcpy ( & V_62 -> V_39 [ 0 ] , & V_92 -> V_39 [ V_92 -> V_102 ] , V_104 ) ;
if ( V_106 )
memcpy ( & V_62 -> V_39 [ V_104 ] , & V_92 -> V_39 [ 0 ] , V_106 ) ;
}
V_62 -> V_35 . V_107 = V_101 ;
if ( F_47 ( V_97 -> V_2 , & V_62 -> V_35 , 1 , V_88 ) != 1 ) {
V_4 -> V_62 . V_87 = false ;
F_48 ( V_4 -> V_10 . V_2 , L_8 ) ;
return - V_108 ;
}
V_99 = F_49 ( V_33 , & V_62 -> V_35 , 1 , V_54 ,
V_109 | V_110 ) ;
if ( ! V_99 ) {
F_40 ( V_97 -> V_2 , & V_62 -> V_35 , 1 , V_88 ) ;
V_4 -> V_62 . V_87 = false ;
F_48 ( V_4 -> V_10 . V_2 , L_9 ) ;
return - V_108 ;
}
V_99 -> V_111 = F_38 ;
V_99 -> V_112 = V_4 ;
F_50 ( V_99 ) ;
V_97 -> V_113 ( V_33 ) ;
V_4 -> V_85 |= V_89 ;
F_41 ( V_4 -> V_85 , V_4 -> V_10 . V_11 + V_90 ) ;
V_4 -> V_62 . V_87 = true ;
V_92 -> V_102 = ( V_92 -> V_102 + V_101 ) & ( V_105 - 1 ) ;
V_4 -> V_10 . V_17 . V_114 += V_101 ;
if ( F_46 ( V_92 ) < V_115 )
F_51 ( & V_4 -> V_10 ) ;
return 1 ;
}
static bool F_52 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_116 )
return false ;
if ( V_4 -> V_62 . V_87 ) {
V_4 -> V_85 |= V_89 ;
F_41 ( V_4 -> V_85 , V_4 -> V_10 . V_11 + V_90 ) ;
V_4 -> V_93 &= ~ V_94 ;
F_41 ( V_4 -> V_93 , V_4 -> V_10 . V_11 + V_95 ) ;
return true ;
}
if ( F_45 ( V_4 ) > 0 ) {
V_4 -> V_93 &= ~ V_94 ;
F_41 ( V_4 -> V_93 , V_4 -> V_10 . V_11 + V_95 ) ;
return true ;
}
return false ;
}
static inline void F_53 ( struct V_3 * V_4 )
{
if ( V_4 -> V_62 . V_87 ) {
V_4 -> V_85 &= ~ V_89 ;
F_41 ( V_4 -> V_85 , V_4 -> V_10 . V_11 + V_90 ) ;
}
}
static inline bool F_54 ( struct V_3 * V_4 )
{
T_1 V_85 ;
if ( ! V_4 -> V_116 )
return false ;
if ( ! V_4 -> V_10 . V_117 ) {
bool V_118 = true ;
if ( ! V_4 -> V_62 . V_87 ) {
if ( F_45 ( V_4 ) > 0 ) {
V_4 -> V_93 &= ~ V_94 ;
V_118 = true ;
} else {
V_4 -> V_93 |= V_94 ;
V_118 = false ;
}
F_41 ( V_4 -> V_93 , V_4 -> V_10 . V_11 + V_95 ) ;
} else if ( ! ( V_4 -> V_85 & V_89 ) ) {
V_4 -> V_85 |= V_89 ;
F_41 ( V_4 -> V_85 ,
V_4 -> V_10 . V_11 + V_90 ) ;
}
return V_118 ;
}
V_85 = V_4 -> V_85 ;
V_4 -> V_85 &= ~ V_89 ;
F_41 ( V_4 -> V_85 , V_4 -> V_10 . V_11 + V_90 ) ;
if ( F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_119 ) {
return false ;
}
F_41 ( V_4 -> V_10 . V_117 , V_4 -> V_10 . V_11 + V_14 ) ;
V_4 -> V_10 . V_17 . V_114 ++ ;
V_4 -> V_10 . V_117 = 0 ;
V_4 -> V_85 = V_85 ;
F_41 ( V_85 , V_4 -> V_10 . V_11 + V_90 ) ;
return true ;
}
static void F_55 ( struct V_120 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
if ( ! V_4 -> V_116 )
return;
F_56 ( & V_4 -> V_10 . V_86 ) ;
F_57 ( V_4 -> V_62 . V_33 ) ;
F_58 ( & V_4 -> V_10 . V_86 ) ;
if ( V_4 -> V_62 . V_87 ) {
F_40 ( V_4 -> V_62 . V_33 -> V_40 -> V_2 , & V_4 -> V_62 . V_35 , 1 ,
V_88 ) ;
V_4 -> V_62 . V_87 = false ;
V_4 -> V_85 &= ~ V_89 ;
F_41 ( V_4 -> V_85 , V_4 -> V_10 . V_11 + V_90 ) ;
}
}
static int F_59 ( struct V_3 * V_4 )
{
struct V_32 * V_121 = V_4 -> V_69 . V_33 ;
struct V_122 * V_69 = & V_4 -> V_69 ;
struct V_98 * V_99 ;
struct V_34 * V_123 ;
if ( ! V_121 )
return - V_124 ;
V_123 = V_4 -> V_69 . V_125 ?
& V_4 -> V_69 . V_126 : & V_4 -> V_69 . V_127 ;
V_99 = F_49 ( V_121 , & V_123 -> V_35 , 1 ,
V_67 ,
V_109 | V_110 ) ;
if ( ! V_99 ) {
V_4 -> V_69 . V_128 = false ;
F_57 ( V_121 ) ;
return - V_108 ;
}
V_99 -> V_111 = V_129 ;
V_99 -> V_112 = V_4 ;
V_69 -> V_130 = F_50 ( V_99 ) ;
F_60 ( V_121 ) ;
V_4 -> V_85 |= V_131 ;
F_41 ( V_4 -> V_85 , V_4 -> V_10 . V_11 + V_90 ) ;
V_4 -> V_69 . V_128 = true ;
V_4 -> V_93 &= ~ V_132 ;
F_41 ( V_4 -> V_93 , V_4 -> V_10 . V_11 + V_95 ) ;
return 0 ;
}
static void F_61 ( struct V_3 * V_4 ,
T_6 V_133 , bool V_125 ,
bool V_134 )
{
struct V_135 * V_10 = & V_4 -> V_10 . V_91 -> V_10 ;
struct V_34 * V_123 = V_125 ?
& V_4 -> V_69 . V_126 : & V_4 -> V_69 . V_127 ;
int V_136 = 0 ;
T_6 V_9 = 0 ;
struct V_122 * V_69 = & V_4 -> V_69 ;
int V_137 = 0 ;
if ( V_4 -> V_69 . V_73 ) {
V_137 = V_123 -> V_35 . V_107 - V_69 -> V_138 ;
if ( V_133 >= V_137 )
V_133 -= V_137 ;
}
if ( V_133 ) {
V_136 = F_62 ( V_10 , V_123 -> V_39 + V_137 ,
V_133 ) ;
V_4 -> V_10 . V_17 . V_18 += V_136 ;
if ( V_136 < V_133 )
F_63 ( V_4 -> V_10 . V_2 ,
L_10 ) ;
}
if ( V_4 -> V_69 . V_73 )
V_69 -> V_138 = V_123 -> V_35 . V_107 ;
if ( V_136 == V_133 && V_134 ) {
F_41 ( V_139 | V_140 | V_141 | V_142 ,
V_4 -> V_10 . V_11 + V_143 ) ;
V_9 = F_4 ( V_4 ) ;
}
F_56 ( & V_4 -> V_10 . V_86 ) ;
F_64 ( V_4 -> V_10 . V_2 ,
L_11 ,
V_136 , V_9 ) ;
F_65 ( V_10 ) ;
F_58 ( & V_4 -> V_10 . V_86 ) ;
}
static void F_66 ( struct V_3 * V_4 )
{
struct V_122 * V_69 = & V_4 -> V_69 ;
struct V_32 * V_121 = V_69 -> V_33 ;
struct V_34 * V_123 = V_69 -> V_125 ?
& V_69 -> V_126 : & V_69 -> V_127 ;
T_5 V_133 ;
struct V_144 V_91 ;
enum V_145 V_146 ;
if ( F_67 ( V_121 ) )
F_25 ( V_4 -> V_10 . V_2 , L_12 ) ;
V_146 = V_121 -> V_40 -> V_147 ( V_121 ,
V_69 -> V_130 , & V_91 ) ;
if ( V_146 != V_148 )
F_25 ( V_4 -> V_10 . V_2 , L_12 ) ;
V_4 -> V_85 &= ~ V_131 ;
F_41 ( V_4 -> V_85 , V_4 -> V_10 . V_11 + V_90 ) ;
V_4 -> V_69 . V_128 = false ;
V_133 = V_123 -> V_35 . V_107 - V_91 . V_149 ;
F_68 ( V_133 > V_41 ) ;
F_57 ( V_121 ) ;
F_61 ( V_4 , V_133 , V_69 -> V_125 , true ) ;
V_69 -> V_125 = ! V_69 -> V_125 ;
if ( F_59 ( V_4 ) ) {
F_48 ( V_4 -> V_10 . V_2 , L_13
L_14 ) ;
V_4 -> V_93 |= V_132 ;
F_41 ( V_4 -> V_93 , V_4 -> V_10 . V_11 + V_95 ) ;
}
}
static void V_129 ( void * V_82 )
{
struct V_3 * V_4 = V_82 ;
struct V_122 * V_69 = & V_4 -> V_69 ;
struct V_32 * V_121 = V_69 -> V_33 ;
bool V_150 = V_69 -> V_125 ;
struct V_34 * V_123 = V_69 -> V_125 ?
& V_69 -> V_126 : & V_69 -> V_127 ;
T_5 V_133 ;
struct V_144 V_91 ;
int V_118 ;
F_69 ( & V_4 -> V_10 . V_86 ) ;
V_121 -> V_40 -> V_147 ( V_121 , V_69 -> V_130 , & V_91 ) ;
V_133 = V_123 -> V_35 . V_107 - V_91 . V_149 ;
F_68 ( V_133 > V_41 ) ;
F_57 ( V_121 ) ;
V_4 -> V_69 . V_128 = false ;
V_69 -> V_125 = ! V_150 ;
V_118 = F_59 ( V_4 ) ;
F_61 ( V_4 , V_133 , V_150 , false ) ;
F_70 ( & V_4 -> V_10 . V_86 ) ;
if ( V_118 ) {
F_48 ( V_4 -> V_10 . V_2 , L_13
L_14 ) ;
V_4 -> V_93 |= V_132 ;
F_41 ( V_4 -> V_93 , V_4 -> V_10 . V_11 + V_95 ) ;
}
}
static inline void F_71 ( struct V_3 * V_4 )
{
V_4 -> V_85 &= ~ V_131 ;
F_41 ( V_4 -> V_85 , V_4 -> V_10 . V_11 + V_90 ) ;
}
static void F_72 ( unsigned long args )
{
struct V_3 * V_4 = (struct V_3 * ) args ;
struct V_135 * V_10 = & V_4 -> V_10 . V_91 -> V_10 ;
struct V_122 * V_69 = & V_4 -> V_69 ;
struct V_32 * V_121 = V_4 -> V_69 . V_33 ;
unsigned long V_84 = 0 ;
unsigned int V_137 = 0 ;
unsigned int V_151 = 0 ;
struct V_34 * V_123 ;
int V_136 ;
struct V_144 V_91 ;
V_123 = V_69 -> V_125 ? & V_4 -> V_69 . V_126 : & V_4 -> V_69 . V_127 ;
V_121 -> V_40 -> V_147 ( V_121 , V_69 -> V_130 , & V_91 ) ;
if ( F_73 ( V_91 . V_149 < V_69 -> V_138 ) ) {
V_137 = V_123 -> V_35 . V_107 - V_69 -> V_138 ;
V_151 = V_69 -> V_138 - V_91 . V_149 ;
V_136 = F_62 ( V_10 , V_123 -> V_39 + V_137 ,
V_151 ) ;
if ( V_136 == V_151 )
V_69 -> V_138 = V_91 . V_149 ;
V_69 -> V_152 = V_153 ;
}
F_65 ( V_10 ) ;
if ( F_74 ( V_153 - V_69 -> V_152 )
> V_4 -> V_69 . V_75 ) {
F_39 ( & V_4 -> V_10 . V_86 , V_84 ) ;
F_71 ( V_4 ) ;
F_44 ( & V_4 -> V_10 . V_86 , V_84 ) ;
V_4 -> V_69 . V_128 = false ;
F_57 ( V_121 ) ;
F_75 ( & V_4 -> V_69 . V_154 ) ;
} else {
F_76 ( & V_4 -> V_69 . V_154 ,
V_153 + F_77 ( V_4 -> V_69 . V_73 ) ) ;
}
}
static void F_78 ( struct V_3 * V_4 )
{
int V_118 ;
if ( ! V_4 -> V_62 . V_33 )
return;
V_4 -> V_62 . V_39 = F_79 ( V_41 , V_42 ) ;
if ( ! V_4 -> V_62 . V_39 ) {
F_25 ( V_4 -> V_10 . V_2 , L_15 ) ;
V_4 -> V_10 . V_56 = V_4 -> V_56 ;
return;
}
F_80 ( & V_4 -> V_62 . V_35 , V_4 -> V_62 . V_39 , V_41 ) ;
V_4 -> V_10 . V_56 = V_41 ;
V_4 -> V_116 = true ;
if ( ! V_4 -> V_69 . V_33 )
goto V_155;
V_118 = F_10 ( V_4 -> V_69 . V_33 , & V_4 -> V_69 . V_127 ,
V_156 ) ;
if ( V_118 ) {
F_25 ( V_4 -> V_10 . V_2 , L_16 ,
L_17 , V_118 ) ;
goto V_155;
}
V_118 = F_10 ( V_4 -> V_69 . V_33 , & V_4 -> V_69 . V_126 ,
V_156 ) ;
if ( V_118 ) {
F_25 ( V_4 -> V_10 . V_2 , L_16 ,
L_18 , V_118 ) ;
F_17 ( V_4 -> V_69 . V_33 , & V_4 -> V_69 . V_127 ,
V_156 ) ;
goto V_155;
}
V_4 -> V_157 = true ;
V_155:
V_4 -> V_85 |= V_158 ;
F_41 ( V_4 -> V_85 , V_4 -> V_10 . V_11 + V_90 ) ;
if ( V_4 -> V_159 -> V_160 )
F_41 ( V_161 | V_162 ,
V_4 -> V_10 . V_11 + V_163 ) ;
if ( V_4 -> V_157 ) {
if ( F_59 ( V_4 ) )
F_48 ( V_4 -> V_10 . V_2 , L_19
L_20 ) ;
if ( V_4 -> V_69 . V_73 ) {
F_81 ( & ( V_4 -> V_69 . V_154 ) ) ;
V_4 -> V_69 . V_154 . V_164 = F_72 ;
V_4 -> V_69 . V_154 . V_82 = ( unsigned long ) V_4 ;
F_76 ( & V_4 -> V_69 . V_154 ,
V_153 +
F_77 ( V_4 -> V_69 . V_73 ) ) ;
V_4 -> V_69 . V_138 = V_41 ;
V_4 -> V_69 . V_152 = V_153 ;
}
}
}
static void F_82 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_116 || V_4 -> V_157 ) )
return;
while ( F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_165 )
F_83 () ;
F_69 ( & V_4 -> V_10 . V_86 ) ;
V_4 -> V_85 &= ~ ( V_158 | V_131 | V_89 ) ;
F_41 ( V_4 -> V_85 , V_4 -> V_10 . V_11 + V_90 ) ;
F_70 ( & V_4 -> V_10 . V_86 ) ;
if ( V_4 -> V_116 ) {
F_57 ( V_4 -> V_62 . V_33 ) ;
if ( V_4 -> V_62 . V_87 ) {
F_40 ( V_4 -> V_62 . V_33 -> V_40 -> V_2 , & V_4 -> V_62 . V_35 , 1 ,
V_88 ) ;
V_4 -> V_62 . V_87 = false ;
}
F_32 ( V_4 -> V_62 . V_39 ) ;
V_4 -> V_116 = false ;
}
if ( V_4 -> V_157 ) {
F_57 ( V_4 -> V_69 . V_33 ) ;
F_17 ( V_4 -> V_69 . V_33 , & V_4 -> V_69 . V_127 , V_156 ) ;
F_17 ( V_4 -> V_69 . V_33 , & V_4 -> V_69 . V_126 , V_156 ) ;
if ( V_4 -> V_69 . V_73 )
F_84 ( & V_4 -> V_69 . V_154 ) ;
V_4 -> V_157 = false ;
}
}
static inline bool F_85 ( struct V_3 * V_4 )
{
return V_4 -> V_157 ;
}
static inline bool F_86 ( struct V_3 * V_4 )
{
return V_4 -> V_157 && V_4 -> V_69 . V_128 ;
}
static inline void F_33 ( struct V_40 * V_2 , struct V_3 * V_4 )
{
}
static inline void F_36 ( struct V_3 * V_4 )
{
}
static inline void F_78 ( struct V_3 * V_4 )
{
}
static inline void F_82 ( struct V_3 * V_4 )
{
}
static inline bool F_52 ( struct V_3 * V_4 )
{
return false ;
}
static inline void F_53 ( struct V_3 * V_4 )
{
}
static inline bool F_54 ( struct V_3 * V_4 )
{
return false ;
}
static inline void F_66 ( struct V_3 * V_4 )
{
}
static inline void F_71 ( struct V_3 * V_4 )
{
}
static inline int F_59 ( struct V_3 * V_4 )
{
return - V_124 ;
}
static inline bool F_85 ( struct V_3 * V_4 )
{
return false ;
}
static inline bool F_86 ( struct V_3 * V_4 )
{
return false ;
}
static void F_87 ( struct V_120 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
V_4 -> V_93 &= ~ V_94 ;
F_41 ( V_4 -> V_93 , V_4 -> V_10 . V_11 + V_95 ) ;
F_53 ( V_4 ) ;
}
static void F_88 ( struct V_120 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
if ( ! F_54 ( V_4 ) ) {
V_4 -> V_93 |= V_94 ;
F_41 ( V_4 -> V_93 , V_4 -> V_10 . V_11 + V_95 ) ;
}
}
static void F_89 ( struct V_120 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
V_4 -> V_93 &= ~ ( V_132 | V_166 | V_167 |
V_168 | V_169 | V_170 ) ;
F_41 ( V_4 -> V_93 , V_4 -> V_10 . V_11 + V_95 ) ;
F_71 ( V_4 ) ;
}
static void F_90 ( struct V_120 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
V_4 -> V_93 |= V_171 | V_172 | V_173 | V_174 ;
F_41 ( V_4 -> V_93 , V_4 -> V_10 . V_11 + V_95 ) ;
}
static void F_91 ( struct V_3 * V_4 )
{
F_4 ( V_4 ) ;
F_56 ( & V_4 -> V_10 . V_86 ) ;
F_65 ( & V_4 -> V_10 . V_91 -> V_10 ) ;
if ( F_85 ( V_4 ) ) {
if ( F_59 ( V_4 ) ) {
F_48 ( V_4 -> V_10 . V_2 , L_21
L_22 ) ;
V_4 -> V_93 |= V_132 ;
} else {
V_4 -> V_93 &= ~ V_132 ;
#ifdef F_92
if ( V_4 -> V_69 . V_73 ) {
V_4 -> V_69 . V_152 = V_153 ;
V_4 -> V_69 . V_138 = V_41 ;
F_76 ( & V_4 -> V_69 . V_154 ,
V_153 +
F_77 ( V_4 -> V_69 . V_73 ) ) ;
}
#endif
}
F_41 ( V_4 -> V_93 , V_4 -> V_10 . V_11 + V_95 ) ;
}
F_58 ( & V_4 -> V_10 . V_86 ) ;
}
static void F_93 ( struct V_3 * V_4 )
{
struct V_100 * V_92 = & V_4 -> V_10 . V_91 -> V_92 ;
int V_101 ;
if ( V_4 -> V_10 . V_117 ) {
F_41 ( V_4 -> V_10 . V_117 , V_4 -> V_10 . V_11 + V_14 ) ;
V_4 -> V_10 . V_17 . V_114 ++ ;
V_4 -> V_10 . V_117 = 0 ;
return;
}
if ( F_43 ( V_92 ) || F_42 ( & V_4 -> V_10 ) ) {
F_87 ( & V_4 -> V_10 ) ;
return;
}
if ( F_52 ( V_4 ) )
return;
V_101 = V_4 -> V_56 >> 1 ;
do {
F_41 ( V_92 -> V_39 [ V_92 -> V_102 ] , V_4 -> V_10 . V_11 + V_14 ) ;
V_92 -> V_102 = ( V_92 -> V_102 + 1 ) & ( V_105 - 1 ) ;
V_4 -> V_10 . V_17 . V_114 ++ ;
if ( F_43 ( V_92 ) )
break;
} while ( -- V_101 > 0 );
if ( F_46 ( V_92 ) < V_115 )
F_51 ( & V_4 -> V_10 ) ;
if ( F_43 ( V_92 ) )
F_87 ( & V_4 -> V_10 ) ;
}
static void F_94 ( struct V_3 * V_4 )
{
unsigned int V_5 , V_175 ;
V_5 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_176 ;
V_175 = V_5 ^ V_4 -> V_177 ;
V_4 -> V_177 = V_5 ;
if ( ! V_175 )
return;
if ( V_175 & V_178 )
F_95 ( & V_4 -> V_10 , V_5 & V_178 ) ;
if ( V_175 & V_179 )
V_4 -> V_10 . V_17 . V_180 ++ ;
if ( V_175 & V_181 )
F_96 ( & V_4 -> V_10 , V_5 & V_181 ) ;
F_97 ( & V_4 -> V_10 . V_91 -> V_10 . V_182 ) ;
}
static T_7 F_98 ( int V_183 , void * V_184 )
{
struct V_3 * V_4 = V_184 ;
unsigned long V_84 ;
unsigned int V_5 , V_185 = V_186 ;
int V_187 = 0 ;
unsigned int V_188 ;
F_39 ( & V_4 -> V_10 . V_86 , V_84 ) ;
V_5 = F_5 ( V_4 -> V_10 . V_11 + V_189 ) ;
if ( V_5 ) {
do {
if ( V_4 -> V_159 -> V_190 ) {
F_41 ( 0x00 , V_4 -> V_10 . V_11 + V_143 ) ;
V_188 = F_5 ( V_4 -> V_10 . V_11 + V_143 ) ;
V_188 = F_5 ( V_4 -> V_10 . V_11 + V_143 ) ;
}
F_41 ( V_5 & ~ ( V_191 | V_192 |
V_193 ) ,
V_4 -> V_10 . V_11 + V_143 ) ;
if ( V_5 & ( V_192 | V_193 ) ) {
if ( F_86 ( V_4 ) )
F_66 ( V_4 ) ;
else
F_91 ( V_4 ) ;
}
if ( V_5 & ( V_194 | V_195 |
V_196 | V_197 ) )
F_94 ( V_4 ) ;
if ( V_5 & V_191 )
F_93 ( V_4 ) ;
if ( V_185 -- == 0 )
break;
V_5 = F_5 ( V_4 -> V_10 . V_11 + V_189 ) ;
} while ( V_5 != 0 );
V_187 = 1 ;
}
F_44 ( & V_4 -> V_10 . V_86 , V_84 ) ;
return F_99 ( V_187 ) ;
}
static unsigned int F_100 ( struct V_120 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned int V_5 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) ;
return V_5 & ( V_165 | V_119 ) ? 0 : V_198 ;
}
static unsigned int F_101 ( struct V_120 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned int V_199 = 0 ;
unsigned int V_5 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) ;
#define F_102 ( T_8 , T_9 ) \
if (status & uartbit) \
result |= tiocmbit
F_102 ( V_178 , V_200 ) ;
F_102 ( V_179 , V_201 ) ;
F_102 ( V_181 , V_202 ) ;
F_102 ( V_203 , V_204 ) ;
#undef F_102
return V_199 ;
}
static void F_103 ( struct V_120 * V_10 , unsigned int V_205 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned int V_206 ;
V_206 = F_5 ( V_4 -> V_10 . V_11 + V_207 ) ;
#define F_102 ( T_9 , T_8 ) \
if (mctrl & tiocmbit) \
cr |= uartbit; \
else \
cr &= ~uartbit
F_102 ( V_208 , V_209 ) ;
F_102 ( V_210 , V_211 ) ;
F_102 ( V_212 , V_213 ) ;
F_102 ( V_214 , V_215 ) ;
F_102 ( V_216 , V_217 ) ;
if ( V_4 -> V_218 ) {
F_102 ( V_208 , V_219 ) ;
}
#undef F_102
F_41 ( V_206 , V_4 -> V_10 . V_11 + V_207 ) ;
}
static void F_104 ( struct V_120 * V_10 , int V_220 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned long V_84 ;
unsigned int V_221 ;
F_39 ( & V_4 -> V_10 . V_86 , V_84 ) ;
V_221 = F_5 ( V_4 -> V_10 . V_11 + V_4 -> V_222 ) ;
if ( V_220 == - 1 )
V_221 |= V_223 ;
else
V_221 &= ~ V_223 ;
F_41 ( V_221 , V_4 -> V_10 . V_11 + V_4 -> V_222 ) ;
F_44 ( & V_4 -> V_10 . V_86 , V_84 ) ;
}
static void F_105 ( struct V_120 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned char T_10 * V_224 = V_4 -> V_10 . V_11 ;
F_41 ( F_5 ( V_224 + V_189 ) , V_224 + V_143 ) ;
F_41 ( F_5 ( V_224 + V_95 ) & ~ V_94 , V_224 + V_95 ) ;
}
static int F_106 ( struct V_120 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned int V_5 ;
F_105 ( V_10 ) ;
V_5 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) ;
if ( V_5 & V_13 )
return V_225 ;
return F_5 ( V_4 -> V_10 . V_11 + V_14 ) ;
}
static void F_107 ( struct V_120 * V_10 ,
unsigned char V_6 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
while ( F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_119 )
F_83 () ;
F_41 ( V_6 , V_4 -> V_10 . V_11 + V_14 ) ;
}
static int F_108 ( struct V_120 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
int V_226 ;
F_109 ( V_10 -> V_2 ) ;
V_226 = F_110 ( V_4 -> V_227 ) ;
if ( V_226 )
goto V_228;
V_4 -> V_10 . V_229 = F_111 ( V_4 -> V_227 ) ;
F_41 ( V_139 | V_140 | V_141 | V_142 |
V_192 | V_193 , V_4 -> V_10 . V_11 + V_143 ) ;
V_4 -> V_93 = F_5 ( V_4 -> V_10 . V_11 + V_95 ) ;
F_41 ( V_166 | V_132 , V_4 -> V_10 . V_11 + V_95 ) ;
if ( V_4 -> V_10 . V_2 -> V_46 ) {
struct V_44 * V_45 ;
V_45 = V_4 -> V_10 . V_2 -> V_46 ;
if ( V_45 -> V_230 )
V_45 -> V_230 () ;
}
return 0 ;
V_228:
return V_226 ;
}
static int F_112 ( struct V_120 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned int V_206 ;
int V_226 ;
V_226 = F_108 ( V_10 ) ;
if ( V_226 )
goto V_231;
F_41 ( V_4 -> V_93 , V_4 -> V_10 . V_11 + V_95 ) ;
V_226 = F_113 ( V_4 -> V_10 . V_183 , F_98 , 0 , L_23 , V_4 ) ;
if ( V_226 )
goto V_231;
F_41 ( V_4 -> V_159 -> V_232 , V_4 -> V_10 . V_11 + V_233 ) ;
V_206 = V_234 | V_235 | V_217 ;
F_41 ( V_206 , V_4 -> V_10 . V_11 + V_207 ) ;
F_41 ( 0 , V_4 -> V_10 . V_11 + V_236 ) ;
F_41 ( 1 , V_4 -> V_10 . V_11 + V_237 ) ;
F_41 ( 0 , V_4 -> V_10 . V_11 + V_4 -> V_238 ) ;
if ( V_4 -> V_222 != V_4 -> V_238 ) {
int V_239 ;
for ( V_239 = 0 ; V_239 < 10 ; ++ V_239 )
F_41 ( 0xff , V_4 -> V_10 . V_11 + V_189 ) ;
F_41 ( 0 , V_4 -> V_10 . V_11 + V_4 -> V_222 ) ;
}
F_41 ( 0 , V_4 -> V_10 . V_11 + V_14 ) ;
while ( F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_165 )
F_83 () ;
V_206 = V_4 -> V_240 & ( V_209 | V_211 ) ;
V_206 |= V_234 | V_241 | V_235 ;
F_41 ( V_206 , V_4 -> V_10 . V_11 + V_207 ) ;
V_4 -> V_177 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_176 ;
F_78 ( V_4 ) ;
F_69 ( & V_4 -> V_10 . V_86 ) ;
F_41 ( V_192 | V_193 ,
V_4 -> V_10 . V_11 + V_143 ) ;
V_4 -> V_93 = V_166 ;
if ( ! F_86 ( V_4 ) )
V_4 -> V_93 |= V_132 ;
F_41 ( V_4 -> V_93 , V_4 -> V_10 . V_11 + V_95 ) ;
F_70 ( & V_4 -> V_10 . V_86 ) ;
return 0 ;
V_231:
F_114 ( V_4 -> V_227 ) ;
return V_226 ;
}
static void F_115 ( struct V_3 * V_4 ,
unsigned int V_242 )
{
unsigned long V_243 ;
V_243 = F_5 ( V_4 -> V_10 . V_11 + V_242 ) ;
V_243 &= ~ ( V_223 | V_244 ) ;
F_41 ( V_243 , V_4 -> V_10 . V_11 + V_242 ) ;
}
static void F_116 ( struct V_120 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned int V_206 ;
F_69 ( & V_4 -> V_10 . V_86 ) ;
V_4 -> V_93 = 0 ;
F_41 ( V_4 -> V_93 , V_4 -> V_10 . V_11 + V_95 ) ;
F_41 ( 0xffff , V_4 -> V_10 . V_11 + V_143 ) ;
F_70 ( & V_4 -> V_10 . V_86 ) ;
F_82 ( V_4 ) ;
F_117 ( V_4 -> V_10 . V_183 , V_4 ) ;
V_4 -> V_218 = false ;
V_206 = F_5 ( V_4 -> V_10 . V_11 + V_207 ) ;
V_4 -> V_240 = V_206 ;
V_206 &= V_209 | V_211 ;
V_206 |= V_234 | V_235 ;
F_41 ( V_206 , V_4 -> V_10 . V_11 + V_207 ) ;
F_115 ( V_4 , V_4 -> V_238 ) ;
if ( V_4 -> V_238 != V_4 -> V_222 )
F_115 ( V_4 , V_4 -> V_222 ) ;
F_114 ( V_4 -> V_227 ) ;
F_118 ( V_10 -> V_2 ) ;
if ( V_4 -> V_10 . V_2 -> V_46 ) {
struct V_44 * V_45 ;
V_45 = V_4 -> V_10 . V_2 -> V_46 ;
if ( V_45 -> exit )
V_45 -> exit () ;
}
}
static void
F_119 ( struct V_120 * V_10 , struct V_245 * V_246 ,
struct V_245 * V_247 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned int V_221 , V_240 ;
unsigned long V_84 ;
unsigned int V_248 , V_249 , V_250 ;
if ( V_4 -> V_159 -> V_251 )
V_250 = 8 ;
else
V_250 = 16 ;
V_248 = F_120 ( V_10 , V_246 , V_247 , 0 ,
V_10 -> V_229 / V_250 ) ;
#ifdef F_92
if ( V_4 -> V_69 . V_72 )
V_4 -> V_69 . V_73 = F_121 ( 10000000 , V_248 ) ;
#endif
if ( V_248 > V_10 -> V_229 / 16 )
V_249 = F_122 ( V_10 -> V_229 * 8 , V_248 ) ;
else
V_249 = F_122 ( V_10 -> V_229 * 4 , V_248 ) ;
switch ( V_246 -> V_252 & V_253 ) {
case V_254 :
V_221 = V_255 ;
break;
case V_256 :
V_221 = V_257 ;
break;
case V_258 :
V_221 = V_259 ;
break;
default:
V_221 = V_260 ;
break;
}
if ( V_246 -> V_252 & V_261 )
V_221 |= V_262 ;
if ( V_246 -> V_252 & V_263 ) {
V_221 |= V_264 ;
if ( ! ( V_246 -> V_252 & V_265 ) )
V_221 |= V_266 ;
}
if ( V_4 -> V_56 > 1 )
V_221 |= V_244 ;
F_39 ( & V_10 -> V_86 , V_84 ) ;
F_123 ( V_10 , V_246 -> V_252 , V_248 ) ;
V_10 -> V_28 = V_26 | 255 ;
if ( V_246 -> V_267 & V_268 )
V_10 -> V_28 |= V_21 | V_22 ;
if ( V_246 -> V_267 & ( V_269 | V_270 ) )
V_10 -> V_28 |= V_20 ;
V_10 -> V_271 = 0 ;
if ( V_246 -> V_267 & V_272 )
V_10 -> V_271 |= V_21 | V_22 ;
if ( V_246 -> V_267 & V_273 ) {
V_10 -> V_271 |= V_20 ;
if ( V_246 -> V_267 & V_272 )
V_10 -> V_271 |= V_26 ;
}
if ( ( V_246 -> V_252 & V_274 ) == 0 )
V_10 -> V_271 |= V_15 ;
if ( F_124 ( V_10 , V_246 -> V_252 ) )
F_90 ( V_10 ) ;
V_240 = F_5 ( V_10 -> V_11 + V_207 ) ;
F_41 ( 0 , V_10 -> V_11 + V_207 ) ;
if ( V_246 -> V_252 & V_275 ) {
if ( V_240 & V_209 )
V_240 |= V_219 ;
V_240 |= V_276 ;
V_4 -> V_218 = true ;
} else {
V_240 &= ~ ( V_276 | V_219 ) ;
V_4 -> V_218 = false ;
}
if ( V_4 -> V_159 -> V_251 ) {
if ( V_248 > V_10 -> V_229 / 16 )
V_240 |= V_277 ;
else
V_240 &= ~ V_277 ;
}
if ( V_4 -> V_159 -> V_251 ) {
if ( ( V_248 >= 3000000 ) && ( V_248 < 3250000 ) && ( V_249 > 1 ) )
V_249 -= 1 ;
else if ( ( V_248 > 3250000 ) && ( V_249 > 2 ) )
V_249 -= 2 ;
}
F_41 ( V_249 & 0x3f , V_10 -> V_11 + V_236 ) ;
F_41 ( V_249 >> 6 , V_10 -> V_11 + V_237 ) ;
F_41 ( V_221 , V_10 -> V_11 + V_4 -> V_238 ) ;
if ( V_4 -> V_238 != V_4 -> V_222 ) {
int V_239 ;
for ( V_239 = 0 ; V_239 < 10 ; ++ V_239 )
F_41 ( 0xff , V_4 -> V_10 . V_11 + V_189 ) ;
F_41 ( V_221 , V_10 -> V_11 + V_4 -> V_222 ) ;
}
F_41 ( V_240 , V_10 -> V_11 + V_207 ) ;
F_44 ( & V_10 -> V_86 , V_84 ) ;
}
static const char * F_125 ( struct V_120 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
return V_4 -> V_10 . type == V_278 ? V_4 -> type : NULL ;
}
static void F_126 ( struct V_120 * V_10 )
{
F_127 ( V_10 -> V_50 , V_279 ) ;
}
static int F_128 ( struct V_120 * V_10 )
{
return F_129 ( V_10 -> V_50 , V_279 , L_23 )
!= NULL ? 0 : - V_108 ;
}
static void F_130 ( struct V_120 * V_10 , int V_84 )
{
if ( V_84 & V_280 ) {
V_10 -> type = V_278 ;
F_128 ( V_10 ) ;
}
}
static int F_131 ( struct V_120 * V_10 , struct V_281 * V_282 )
{
int V_118 = 0 ;
if ( V_282 -> type != V_283 && V_282 -> type != V_278 )
V_118 = - V_284 ;
if ( V_282 -> V_183 < 0 || V_282 -> V_183 >= V_285 )
V_118 = - V_284 ;
if ( V_282 -> V_286 < 9600 )
V_118 = - V_284 ;
return V_118 ;
}
static void F_132 ( struct V_120 * V_10 , int V_6 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
while ( F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_119 )
F_83 () ;
F_41 ( V_6 , V_4 -> V_10 . V_11 + V_14 ) ;
}
static void
F_133 ( struct V_287 * V_288 , const char * V_289 , unsigned int V_101 )
{
struct V_3 * V_4 = V_290 [ V_288 -> V_291 ] ;
unsigned int V_5 , V_240 , V_292 ;
unsigned long V_84 ;
int V_293 = 1 ;
F_134 ( V_4 -> V_227 ) ;
F_135 ( V_84 ) ;
if ( V_4 -> V_10 . V_294 )
V_293 = 0 ;
else if ( V_295 )
V_293 = F_136 ( & V_4 -> V_10 . V_86 ) ;
else
F_58 ( & V_4 -> V_10 . V_86 ) ;
V_240 = F_5 ( V_4 -> V_10 . V_11 + V_207 ) ;
V_292 = V_240 & ~ V_276 ;
V_292 |= V_234 | V_235 ;
F_41 ( V_292 , V_4 -> V_10 . V_11 + V_207 ) ;
F_137 ( & V_4 -> V_10 , V_289 , V_101 , F_132 ) ;
do {
V_5 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) ;
} while ( V_5 & V_165 );
F_41 ( V_240 , V_4 -> V_10 . V_11 + V_207 ) ;
if ( V_293 )
F_56 ( & V_4 -> V_10 . V_86 ) ;
F_138 ( V_84 ) ;
F_139 ( V_4 -> V_227 ) ;
}
static void T_4
F_140 ( struct V_3 * V_4 , int * V_248 ,
int * V_24 , int * V_296 )
{
if ( F_5 ( V_4 -> V_10 . V_11 + V_207 ) & V_234 ) {
unsigned int V_221 , V_297 , V_298 ;
V_221 = F_5 ( V_4 -> V_10 . V_11 + V_4 -> V_222 ) ;
* V_24 = 'n' ;
if ( V_221 & V_264 ) {
if ( V_221 & V_266 )
* V_24 = 'e' ;
else
* V_24 = 'o' ;
}
if ( ( V_221 & 0x60 ) == V_259 )
* V_296 = 7 ;
else
* V_296 = 8 ;
V_297 = F_5 ( V_4 -> V_10 . V_11 + V_237 ) ;
V_298 = F_5 ( V_4 -> V_10 . V_11 + V_236 ) ;
* V_248 = V_4 -> V_10 . V_229 * 4 / ( 64 * V_297 + V_298 ) ;
if ( V_4 -> V_159 -> V_251 ) {
if ( F_5 ( V_4 -> V_10 . V_11 + V_207 )
& V_277 )
* V_248 *= 2 ;
}
}
}
static int T_4 F_141 ( struct V_287 * V_288 , char * V_299 )
{
struct V_3 * V_4 ;
int V_248 = 38400 ;
int V_296 = 8 ;
int V_24 = 'n' ;
int V_300 = 'n' ;
int V_118 ;
if ( V_288 -> V_291 >= V_301 )
V_288 -> V_291 = 0 ;
V_4 = V_290 [ V_288 -> V_291 ] ;
if ( ! V_4 )
return - V_302 ;
F_109 ( V_4 -> V_10 . V_2 ) ;
V_118 = F_142 ( V_4 -> V_227 ) ;
if ( V_118 )
return V_118 ;
if ( V_4 -> V_10 . V_2 -> V_46 ) {
struct V_44 * V_45 ;
V_45 = V_4 -> V_10 . V_2 -> V_46 ;
if ( V_45 -> V_230 )
V_45 -> V_230 () ;
}
V_4 -> V_10 . V_229 = F_111 ( V_4 -> V_227 ) ;
if ( V_299 )
F_143 ( V_299 , & V_248 , & V_24 , & V_296 , & V_300 ) ;
else
F_140 ( V_4 , & V_248 , & V_24 , & V_296 ) ;
return F_144 ( & V_4 -> V_10 , V_288 , V_248 , V_24 , V_296 , V_300 ) ;
}
static int F_145 ( int V_291 , struct V_40 * V_2 )
{
struct V_303 * V_304 ;
static bool V_305 = false ;
static bool V_306 = false ;
int V_118 = V_291 ;
if ( ! F_146 ( V_307 ) )
return V_118 ;
V_304 = V_2 -> V_308 ;
if ( ! V_304 )
return V_118 ;
V_118 = F_147 ( V_304 , L_24 ) ;
if ( F_148 ( V_118 ) ) {
V_306 = true ;
V_118 = V_291 ;
} else {
V_305 = true ;
if ( V_118 >= F_149 ( V_290 ) || V_290 [ V_118 ] != NULL ) {
F_63 ( V_2 , L_25 , V_118 ) ;
V_118 = V_291 ;
}
}
if ( V_305 && V_306 )
F_63 ( V_2 , L_26 ) ;
return V_118 ;
}
static int F_150 ( struct V_1 * V_2 , const struct V_309 * V_310 )
{
struct V_3 * V_4 ;
struct V_311 * V_159 = V_310 -> V_82 ;
void T_10 * V_312 ;
int V_239 , V_118 ;
for ( V_239 = 0 ; V_239 < F_149 ( V_290 ) ; V_239 ++ )
if ( V_290 [ V_239 ] == NULL )
break;
if ( V_239 == F_149 ( V_290 ) ) {
V_118 = - V_108 ;
goto V_228;
}
V_4 = F_151 ( & V_2 -> V_2 , sizeof( struct V_3 ) ,
V_42 ) ;
if ( V_4 == NULL ) {
V_118 = - V_43 ;
goto V_228;
}
V_239 = F_145 ( V_239 , & V_2 -> V_2 ) ;
V_312 = F_152 ( & V_2 -> V_2 , V_2 -> V_313 . V_314 ,
F_153 ( & V_2 -> V_313 ) ) ;
if ( ! V_312 ) {
V_118 = - V_43 ;
goto V_228;
}
V_4 -> V_227 = F_154 ( & V_2 -> V_2 , NULL ) ;
if ( F_155 ( V_4 -> V_227 ) ) {
V_118 = F_156 ( V_4 -> V_227 ) ;
goto V_228;
}
V_4 -> V_159 = V_159 ;
V_4 -> V_238 = V_159 -> V_238 ;
V_4 -> V_222 = V_159 -> V_222 ;
V_4 -> V_240 = 0 ;
V_4 -> V_56 = V_159 -> V_315 ( V_2 ) ;
V_4 -> V_10 . V_2 = & V_2 -> V_2 ;
V_4 -> V_10 . V_50 = V_2 -> V_313 . V_314 ;
V_4 -> V_10 . V_11 = V_312 ;
V_4 -> V_10 . V_316 = V_317 ;
V_4 -> V_10 . V_183 = V_2 -> V_183 [ 0 ] ;
V_4 -> V_10 . V_56 = V_4 -> V_56 ;
V_4 -> V_10 . V_318 = & V_319 ;
V_4 -> V_10 . V_84 = V_320 ;
V_4 -> V_10 . line = V_239 ;
F_33 ( & V_2 -> V_2 , V_4 ) ;
F_41 ( 0 , V_4 -> V_10 . V_11 + V_95 ) ;
F_41 ( 0xffff , V_4 -> V_10 . V_11 + V_143 ) ;
snprintf ( V_4 -> type , sizeof( V_4 -> type ) , L_27 , F_2 ( V_2 ) ) ;
V_290 [ V_239 ] = V_4 ;
F_157 ( V_2 , V_4 ) ;
V_118 = F_158 ( & V_321 , & V_4 -> V_10 ) ;
if ( V_118 ) {
F_157 ( V_2 , NULL ) ;
V_290 [ V_239 ] = NULL ;
F_36 ( V_4 ) ;
}
V_228:
return V_118 ;
}
static int F_159 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_160 ( V_2 ) ;
int V_239 ;
F_157 ( V_2 , NULL ) ;
F_161 ( & V_321 , & V_4 -> V_10 ) ;
for ( V_239 = 0 ; V_239 < F_149 ( V_290 ) ; V_239 ++ )
if ( V_290 [ V_239 ] == V_4 )
V_290 [ V_239 ] = NULL ;
F_36 ( V_4 ) ;
return 0 ;
}
static int F_162 ( struct V_1 * V_2 , T_11 V_91 )
{
struct V_3 * V_4 = F_160 ( V_2 ) ;
if ( ! V_4 )
return - V_284 ;
return F_163 ( & V_321 , & V_4 -> V_10 ) ;
}
static int F_164 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_160 ( V_2 ) ;
if ( ! V_4 )
return - V_284 ;
return F_165 ( & V_321 , & V_4 -> V_10 ) ;
}
static int T_4 F_166 ( void )
{
int V_118 ;
F_167 ( V_322 L_28 ) ;
V_118 = F_168 ( & V_321 ) ;
if ( V_118 == 0 ) {
V_118 = F_169 ( & V_323 ) ;
if ( V_118 )
F_170 ( & V_321 ) ;
}
return V_118 ;
}
static void T_12 F_171 ( void )
{
F_172 ( & V_323 ) ;
F_170 ( & V_321 ) ;
}
