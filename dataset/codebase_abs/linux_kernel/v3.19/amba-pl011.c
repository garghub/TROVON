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
F_17 ( & V_35 -> V_35 ) = V_41 ;
return 0 ;
}
static void F_18 ( struct V_32 * V_33 , struct V_34 * V_35 ,
enum V_36 V_37 )
{
if ( V_35 -> V_39 ) {
F_19 ( V_33 -> V_40 -> V_2 ,
V_41 , V_35 -> V_39 ,
F_16 ( & V_35 -> V_35 ) ) ;
}
}
static void F_20 ( struct V_40 * V_2 , struct V_3 * V_4 )
{
struct V_44 * V_45 = F_21 ( V_4 -> V_10 . V_2 ) ;
struct V_46 V_47 = {
. V_48 = V_4 -> V_10 . V_49 + V_14 ,
. V_50 = V_51 ,
. V_52 = V_53 ,
. V_54 = V_4 -> V_55 >> 1 ,
. V_56 = false ,
} ;
struct V_32 * V_33 ;
T_3 V_57 ;
V_33 = F_22 ( V_2 , L_1 ) ;
if ( ! V_33 ) {
if ( ! V_45 || ! V_45 -> V_58 ) {
F_23 ( V_4 -> V_10 . V_2 , L_2 ) ;
return;
}
F_24 ( V_57 ) ;
F_25 ( V_59 , V_57 ) ;
V_33 = F_26 ( V_57 , V_45 -> V_58 ,
V_45 -> V_60 ) ;
if ( ! V_33 ) {
F_27 ( V_4 -> V_10 . V_2 , L_3 ) ;
return;
}
}
F_28 ( V_33 , & V_47 ) ;
V_4 -> V_61 . V_33 = V_33 ;
F_23 ( V_4 -> V_10 . V_2 , L_4 ,
F_29 ( V_4 -> V_61 . V_33 ) ) ;
V_33 = F_22 ( V_2 , L_5 ) ;
if ( ! V_33 && V_45 -> V_62 ) {
V_33 = F_26 ( V_57 , V_45 -> V_58 , V_45 -> V_62 ) ;
if ( ! V_33 ) {
F_27 ( V_4 -> V_10 . V_2 , L_6 ) ;
return;
}
}
if ( V_33 ) {
struct V_46 V_63 = {
. V_64 = V_4 -> V_10 . V_49 + V_14 ,
. V_65 = V_51 ,
. V_52 = V_66 ,
. V_67 = V_4 -> V_55 >> 2 ,
. V_56 = false ,
} ;
struct V_68 V_69 ;
if ( 0 == F_30 ( V_33 , & V_69 ) ) {
if ( V_69 . V_70 ==
V_71 ) {
F_31 ( V_33 ) ;
F_23 ( V_4 -> V_10 . V_2 ,
L_7 ) ;
return;
}
}
F_28 ( V_33 , & V_63 ) ;
V_4 -> V_72 . V_33 = V_33 ;
V_4 -> V_72 . V_73 = false ;
if ( V_45 && V_45 -> V_74 ) {
if ( V_45 -> V_75 ) {
V_4 -> V_72 . V_73 = false ;
V_4 -> V_72 . V_76 = V_45 -> V_75 ;
} else {
V_4 -> V_72 . V_73 = true ;
V_4 -> V_72 . V_76 = 100 ;
}
if ( V_45 -> V_77 )
V_4 -> V_72 . V_78 =
V_45 -> V_77 ;
else
V_4 -> V_72 . V_78 = 3000 ;
} else if ( ! V_45 && V_2 -> V_79 ) {
V_4 -> V_72 . V_73 = F_32 (
V_2 -> V_79 , L_8 ) ;
if ( V_4 -> V_72 . V_73 ) {
T_4 V_80 ;
if ( 0 == F_33 ( V_2 -> V_79 ,
L_9 , & V_80 ) )
V_4 -> V_72 . V_76 = V_80 ;
else
V_4 -> V_72 . V_76 = 100 ;
if ( 0 == F_33 ( V_2 -> V_79 ,
L_10 , & V_80 ) )
V_4 -> V_72 . V_78 = V_80 ;
else
V_4 -> V_72 . V_78 = 3000 ;
}
}
F_23 ( V_4 -> V_10 . V_2 , L_11 ,
F_29 ( V_4 -> V_72 . V_33 ) ) ;
}
}
static int T_5 F_34 ( void )
{
struct V_81 * V_82 , * V_83 ;
F_35 (node, tmp, &pl011_dma_uarts) {
struct V_84 * V_85 = F_36 ( V_82 , struct V_84 , V_82 ) ;
F_20 ( V_85 -> V_2 , V_85 -> V_4 ) ;
F_37 ( V_82 ) ;
F_38 ( V_85 ) ;
}
return 0 ;
}
static void F_39 ( struct V_40 * V_2 , struct V_3 * V_4 )
{
struct V_84 * V_85 = F_40 ( sizeof( struct V_84 ) , V_42 ) ;
if ( V_85 ) {
V_85 -> V_4 = V_4 ;
V_85 -> V_2 = V_2 ;
F_41 ( & V_85 -> V_82 , & V_86 ) ;
}
}
static void F_39 ( struct V_40 * V_2 , struct V_3 * V_4 )
{
F_20 ( V_2 , V_4 ) ;
}
static void F_42 ( struct V_3 * V_4 )
{
if ( V_4 -> V_61 . V_33 )
F_31 ( V_4 -> V_61 . V_33 ) ;
if ( V_4 -> V_72 . V_33 )
F_31 ( V_4 -> V_72 . V_33 ) ;
}
static void F_43 ( void * V_87 )
{
struct V_3 * V_4 = V_87 ;
struct V_88 * V_61 = & V_4 -> V_61 ;
unsigned long V_89 ;
T_1 V_90 ;
F_44 ( & V_4 -> V_10 . V_91 , V_89 ) ;
if ( V_4 -> V_61 . V_92 )
F_45 ( V_61 -> V_33 -> V_40 -> V_2 , & V_61 -> V_35 , 1 ,
V_93 ) ;
V_90 = V_4 -> V_90 ;
V_4 -> V_90 = V_90 & ~ V_94 ;
F_46 ( V_4 -> V_90 , V_4 -> V_10 . V_11 + V_95 ) ;
if ( ! ( V_90 & V_94 ) || F_47 ( & V_4 -> V_10 ) ||
F_48 ( & V_4 -> V_10 . V_96 -> V_97 ) ) {
V_4 -> V_61 . V_92 = false ;
F_49 ( & V_4 -> V_10 . V_91 , V_89 ) ;
return;
}
if ( F_50 ( V_4 ) <= 0 ) {
V_4 -> V_98 |= V_99 ;
F_46 ( V_4 -> V_98 , V_4 -> V_10 . V_11 + V_100 ) ;
}
F_49 ( & V_4 -> V_10 . V_91 , V_89 ) ;
}
static int F_50 ( struct V_3 * V_4 )
{
struct V_88 * V_61 = & V_4 -> V_61 ;
struct V_32 * V_33 = V_61 -> V_33 ;
struct V_101 * V_102 = V_33 -> V_40 ;
struct V_103 * V_104 ;
struct V_105 * V_97 = & V_4 -> V_10 . V_96 -> V_97 ;
unsigned int V_106 ;
V_106 = F_51 ( V_97 ) ;
if ( V_106 < ( V_4 -> V_55 >> 1 ) ) {
V_4 -> V_61 . V_92 = false ;
return 0 ;
}
V_106 -= 1 ;
if ( V_106 > V_41 )
V_106 = V_41 ;
if ( V_97 -> V_107 < V_97 -> V_108 )
memcpy ( & V_61 -> V_39 [ 0 ] , & V_97 -> V_39 [ V_97 -> V_107 ] , V_106 ) ;
else {
T_6 V_109 = V_110 - V_97 -> V_107 ;
T_6 V_111 ;
if ( V_109 > V_106 )
V_109 = V_106 ;
V_111 = V_106 - V_109 ;
memcpy ( & V_61 -> V_39 [ 0 ] , & V_97 -> V_39 [ V_97 -> V_107 ] , V_109 ) ;
if ( V_111 )
memcpy ( & V_61 -> V_39 [ V_109 ] , & V_97 -> V_39 [ 0 ] , V_111 ) ;
}
V_61 -> V_35 . V_112 = V_106 ;
if ( F_52 ( V_102 -> V_2 , & V_61 -> V_35 , 1 , V_93 ) != 1 ) {
V_4 -> V_61 . V_92 = false ;
F_53 ( V_4 -> V_10 . V_2 , L_12 ) ;
return - V_113 ;
}
V_104 = F_54 ( V_33 , & V_61 -> V_35 , 1 , V_53 ,
V_114 | V_115 ) ;
if ( ! V_104 ) {
F_45 ( V_102 -> V_2 , & V_61 -> V_35 , 1 , V_93 ) ;
V_4 -> V_61 . V_92 = false ;
F_53 ( V_4 -> V_10 . V_2 , L_13 ) ;
return - V_113 ;
}
V_104 -> V_116 = F_43 ;
V_104 -> V_117 = V_4 ;
F_55 ( V_104 ) ;
V_102 -> V_118 ( V_33 ) ;
V_4 -> V_90 |= V_94 ;
F_46 ( V_4 -> V_90 , V_4 -> V_10 . V_11 + V_95 ) ;
V_4 -> V_61 . V_92 = true ;
V_97 -> V_107 = ( V_97 -> V_107 + V_106 ) & ( V_110 - 1 ) ;
V_4 -> V_10 . V_17 . V_119 += V_106 ;
if ( F_51 ( V_97 ) < V_120 )
F_56 ( & V_4 -> V_10 ) ;
return 1 ;
}
static bool F_57 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_121 )
return false ;
if ( V_4 -> V_61 . V_92 ) {
V_4 -> V_90 |= V_94 ;
F_46 ( V_4 -> V_90 , V_4 -> V_10 . V_11 + V_95 ) ;
V_4 -> V_98 &= ~ V_99 ;
F_46 ( V_4 -> V_98 , V_4 -> V_10 . V_11 + V_100 ) ;
return true ;
}
if ( F_50 ( V_4 ) > 0 ) {
V_4 -> V_98 &= ~ V_99 ;
F_46 ( V_4 -> V_98 , V_4 -> V_10 . V_11 + V_100 ) ;
return true ;
}
return false ;
}
static inline void F_58 ( struct V_3 * V_4 )
{
if ( V_4 -> V_61 . V_92 ) {
V_4 -> V_90 &= ~ V_94 ;
F_46 ( V_4 -> V_90 , V_4 -> V_10 . V_11 + V_95 ) ;
}
}
static inline bool F_59 ( struct V_3 * V_4 )
{
T_1 V_90 ;
if ( ! V_4 -> V_121 )
return false ;
if ( ! V_4 -> V_10 . V_122 ) {
bool V_123 = true ;
if ( ! V_4 -> V_61 . V_92 ) {
if ( F_50 ( V_4 ) > 0 ) {
V_4 -> V_98 &= ~ V_99 ;
V_123 = true ;
} else {
V_4 -> V_98 |= V_99 ;
V_123 = false ;
}
F_46 ( V_4 -> V_98 , V_4 -> V_10 . V_11 + V_100 ) ;
} else if ( ! ( V_4 -> V_90 & V_94 ) ) {
V_4 -> V_90 |= V_94 ;
F_46 ( V_4 -> V_90 ,
V_4 -> V_10 . V_11 + V_95 ) ;
}
return V_123 ;
}
V_90 = V_4 -> V_90 ;
V_4 -> V_90 &= ~ V_94 ;
F_46 ( V_4 -> V_90 , V_4 -> V_10 . V_11 + V_95 ) ;
if ( F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_124 ) {
return false ;
}
F_46 ( V_4 -> V_10 . V_122 , V_4 -> V_10 . V_11 + V_14 ) ;
V_4 -> V_10 . V_17 . V_119 ++ ;
V_4 -> V_10 . V_122 = 0 ;
V_4 -> V_90 = V_90 ;
F_46 ( V_90 , V_4 -> V_10 . V_11 + V_95 ) ;
return true ;
}
static void F_60 ( struct V_125 * V_10 )
__releases( &uap->port.lock
static int F_61 ( struct V_3 * V_4 )
{
struct V_32 * V_126 = V_4 -> V_72 . V_33 ;
struct V_127 * V_72 = & V_4 -> V_72 ;
struct V_103 * V_104 ;
struct V_34 * V_128 ;
if ( ! V_126 )
return - V_129 ;
V_128 = V_4 -> V_72 . V_130 ?
& V_4 -> V_72 . V_131 : & V_4 -> V_72 . V_132 ;
V_104 = F_54 ( V_126 , & V_128 -> V_35 , 1 ,
V_66 ,
V_114 | V_115 ) ;
if ( ! V_104 ) {
V_4 -> V_72 . V_133 = false ;
F_62 ( V_126 ) ;
return - V_113 ;
}
V_104 -> V_116 = V_134 ;
V_104 -> V_117 = V_4 ;
V_72 -> V_135 = F_55 ( V_104 ) ;
F_63 ( V_126 ) ;
V_4 -> V_90 |= V_136 ;
F_46 ( V_4 -> V_90 , V_4 -> V_10 . V_11 + V_95 ) ;
V_4 -> V_72 . V_133 = true ;
V_4 -> V_98 &= ~ V_137 ;
F_46 ( V_4 -> V_98 , V_4 -> V_10 . V_11 + V_100 ) ;
return 0 ;
}
static void F_64 ( struct V_3 * V_4 ,
T_4 V_138 , bool V_130 ,
bool V_139 )
{
struct V_140 * V_10 = & V_4 -> V_10 . V_96 -> V_10 ;
struct V_34 * V_128 = V_130 ?
& V_4 -> V_72 . V_131 : & V_4 -> V_72 . V_132 ;
int V_141 = 0 ;
T_4 V_9 = 0 ;
struct V_127 * V_72 = & V_4 -> V_72 ;
int V_142 = 0 ;
if ( V_4 -> V_72 . V_76 ) {
V_142 = V_128 -> V_35 . V_112 - V_72 -> V_143 ;
if ( V_138 >= V_142 )
V_138 -= V_142 ;
}
if ( V_138 ) {
V_141 = F_65 ( V_10 , V_128 -> V_39 + V_142 ,
V_138 ) ;
V_4 -> V_10 . V_17 . V_18 += V_141 ;
if ( V_141 < V_138 )
F_66 ( V_4 -> V_10 . V_2 ,
L_14 ) ;
}
if ( V_4 -> V_72 . V_76 )
V_72 -> V_143 = V_128 -> V_35 . V_112 ;
if ( V_141 == V_138 && V_139 ) {
F_46 ( V_144 | V_145 | V_146 | V_147 ,
V_4 -> V_10 . V_11 + V_148 ) ;
V_9 = F_4 ( V_4 ) ;
}
F_67 ( & V_4 -> V_10 . V_91 ) ;
F_68 ( V_4 -> V_10 . V_2 ,
L_15 ,
V_141 , V_9 ) ;
F_69 ( V_10 ) ;
F_70 ( & V_4 -> V_10 . V_91 ) ;
}
static void F_71 ( struct V_3 * V_4 )
{
struct V_127 * V_72 = & V_4 -> V_72 ;
struct V_32 * V_126 = V_72 -> V_33 ;
struct V_34 * V_128 = V_72 -> V_130 ?
& V_72 -> V_131 : & V_72 -> V_132 ;
T_6 V_138 ;
struct V_149 V_96 ;
enum V_150 V_151 ;
if ( F_72 ( V_126 ) )
F_27 ( V_4 -> V_10 . V_2 , L_16 ) ;
V_151 = V_126 -> V_40 -> V_152 ( V_126 ,
V_72 -> V_135 , & V_96 ) ;
if ( V_151 != V_153 )
F_27 ( V_4 -> V_10 . V_2 , L_16 ) ;
V_4 -> V_90 &= ~ V_136 ;
F_46 ( V_4 -> V_90 , V_4 -> V_10 . V_11 + V_95 ) ;
V_4 -> V_72 . V_133 = false ;
V_138 = V_128 -> V_35 . V_112 - V_96 . V_154 ;
F_73 ( V_138 > V_41 ) ;
F_62 ( V_126 ) ;
F_64 ( V_4 , V_138 , V_72 -> V_130 , true ) ;
V_72 -> V_130 = ! V_72 -> V_130 ;
if ( F_61 ( V_4 ) ) {
F_53 ( V_4 -> V_10 . V_2 , L_17
L_18 ) ;
V_4 -> V_98 |= V_137 ;
F_46 ( V_4 -> V_98 , V_4 -> V_10 . V_11 + V_100 ) ;
}
}
static void V_134 ( void * V_87 )
{
struct V_3 * V_4 = V_87 ;
struct V_127 * V_72 = & V_4 -> V_72 ;
struct V_32 * V_126 = V_72 -> V_33 ;
bool V_155 = V_72 -> V_130 ;
struct V_34 * V_128 = V_72 -> V_130 ?
& V_72 -> V_131 : & V_72 -> V_132 ;
T_6 V_138 ;
struct V_149 V_96 ;
int V_123 ;
F_74 ( & V_4 -> V_10 . V_91 ) ;
V_126 -> V_40 -> V_152 ( V_126 , V_72 -> V_135 , & V_96 ) ;
V_138 = V_128 -> V_35 . V_112 - V_96 . V_154 ;
F_73 ( V_138 > V_41 ) ;
F_62 ( V_126 ) ;
V_4 -> V_72 . V_133 = false ;
V_72 -> V_130 = ! V_155 ;
V_123 = F_61 ( V_4 ) ;
F_64 ( V_4 , V_138 , V_155 , false ) ;
F_75 ( & V_4 -> V_10 . V_91 ) ;
if ( V_123 ) {
F_53 ( V_4 -> V_10 . V_2 , L_17
L_18 ) ;
V_4 -> V_98 |= V_137 ;
F_46 ( V_4 -> V_98 , V_4 -> V_10 . V_11 + V_100 ) ;
}
}
static inline void F_76 ( struct V_3 * V_4 )
{
V_4 -> V_90 &= ~ V_136 ;
F_46 ( V_4 -> V_90 , V_4 -> V_10 . V_11 + V_95 ) ;
}
static void F_77 ( unsigned long args )
{
struct V_3 * V_4 = (struct V_3 * ) args ;
struct V_140 * V_10 = & V_4 -> V_10 . V_96 -> V_10 ;
struct V_127 * V_72 = & V_4 -> V_72 ;
struct V_32 * V_126 = V_4 -> V_72 . V_33 ;
unsigned long V_89 = 0 ;
unsigned int V_142 = 0 ;
unsigned int V_156 = 0 ;
struct V_34 * V_128 ;
int V_141 ;
struct V_149 V_96 ;
V_128 = V_72 -> V_130 ? & V_4 -> V_72 . V_131 : & V_4 -> V_72 . V_132 ;
V_126 -> V_40 -> V_152 ( V_126 , V_72 -> V_135 , & V_96 ) ;
if ( F_78 ( V_96 . V_154 < V_72 -> V_143 ) ) {
V_142 = V_128 -> V_35 . V_112 - V_72 -> V_143 ;
V_156 = V_72 -> V_143 - V_96 . V_154 ;
V_141 = F_65 ( V_10 , V_128 -> V_39 + V_142 ,
V_156 ) ;
if ( V_141 == V_156 )
V_72 -> V_143 = V_96 . V_154 ;
V_72 -> V_157 = V_158 ;
}
F_69 ( V_10 ) ;
if ( F_79 ( V_158 - V_72 -> V_157 )
> V_4 -> V_72 . V_78 ) {
F_44 ( & V_4 -> V_10 . V_91 , V_89 ) ;
F_76 ( V_4 ) ;
V_4 -> V_98 |= V_137 ;
F_46 ( V_4 -> V_98 , V_4 -> V_10 . V_11 + V_100 ) ;
F_49 ( & V_4 -> V_10 . V_91 , V_89 ) ;
V_4 -> V_72 . V_133 = false ;
F_62 ( V_126 ) ;
F_80 ( & V_4 -> V_72 . V_159 ) ;
} else {
F_81 ( & V_4 -> V_72 . V_159 ,
V_158 + F_82 ( V_4 -> V_72 . V_76 ) ) ;
}
}
static void F_83 ( struct V_3 * V_4 )
{
int V_123 ;
if ( ! V_4 -> V_61 . V_33 )
return;
V_4 -> V_61 . V_39 = F_84 ( V_41 , V_42 | V_160 ) ;
if ( ! V_4 -> V_61 . V_39 ) {
F_27 ( V_4 -> V_10 . V_2 , L_19 ) ;
V_4 -> V_10 . V_55 = V_4 -> V_55 ;
return;
}
F_85 ( & V_4 -> V_61 . V_35 , V_4 -> V_61 . V_39 , V_41 ) ;
V_4 -> V_10 . V_55 = V_41 ;
V_4 -> V_121 = true ;
if ( ! V_4 -> V_72 . V_33 )
goto V_161;
V_123 = F_10 ( V_4 -> V_72 . V_33 , & V_4 -> V_72 . V_132 ,
V_162 ) ;
if ( V_123 ) {
F_27 ( V_4 -> V_10 . V_2 , L_20 ,
L_21 , V_123 ) ;
goto V_161;
}
V_123 = F_10 ( V_4 -> V_72 . V_33 , & V_4 -> V_72 . V_131 ,
V_162 ) ;
if ( V_123 ) {
F_27 ( V_4 -> V_10 . V_2 , L_20 ,
L_22 , V_123 ) ;
F_18 ( V_4 -> V_72 . V_33 , & V_4 -> V_72 . V_132 ,
V_162 ) ;
goto V_161;
}
V_4 -> V_163 = true ;
V_161:
V_4 -> V_90 |= V_164 ;
F_46 ( V_4 -> V_90 , V_4 -> V_10 . V_11 + V_95 ) ;
if ( V_4 -> V_165 -> V_166 )
F_46 ( V_167 | V_168 ,
V_4 -> V_10 . V_11 + V_169 ) ;
if ( V_4 -> V_163 ) {
if ( F_61 ( V_4 ) )
F_53 ( V_4 -> V_10 . V_2 , L_23
L_24 ) ;
if ( V_4 -> V_72 . V_76 ) {
F_86 ( & ( V_4 -> V_72 . V_159 ) ) ;
V_4 -> V_72 . V_159 . V_170 = F_77 ;
V_4 -> V_72 . V_159 . V_87 = ( unsigned long ) V_4 ;
F_81 ( & V_4 -> V_72 . V_159 ,
V_158 +
F_82 ( V_4 -> V_72 . V_76 ) ) ;
V_4 -> V_72 . V_143 = V_41 ;
V_4 -> V_72 . V_157 = V_158 ;
}
}
}
static void F_87 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_121 || V_4 -> V_163 ) )
return;
while ( F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_171 )
F_88 () ;
F_74 ( & V_4 -> V_10 . V_91 ) ;
V_4 -> V_90 &= ~ ( V_164 | V_136 | V_94 ) ;
F_46 ( V_4 -> V_90 , V_4 -> V_10 . V_11 + V_95 ) ;
F_75 ( & V_4 -> V_10 . V_91 ) ;
if ( V_4 -> V_121 ) {
F_62 ( V_4 -> V_61 . V_33 ) ;
if ( V_4 -> V_61 . V_92 ) {
F_45 ( V_4 -> V_61 . V_33 -> V_40 -> V_2 , & V_4 -> V_61 . V_35 , 1 ,
V_93 ) ;
V_4 -> V_61 . V_92 = false ;
}
F_38 ( V_4 -> V_61 . V_39 ) ;
V_4 -> V_121 = false ;
}
if ( V_4 -> V_163 ) {
F_62 ( V_4 -> V_72 . V_33 ) ;
F_18 ( V_4 -> V_72 . V_33 , & V_4 -> V_72 . V_132 , V_162 ) ;
F_18 ( V_4 -> V_72 . V_33 , & V_4 -> V_72 . V_131 , V_162 ) ;
if ( V_4 -> V_72 . V_76 )
F_89 ( & V_4 -> V_72 . V_159 ) ;
V_4 -> V_163 = false ;
}
}
static inline bool F_90 ( struct V_3 * V_4 )
{
return V_4 -> V_163 ;
}
static inline bool F_91 ( struct V_3 * V_4 )
{
return V_4 -> V_163 && V_4 -> V_72 . V_133 ;
}
static inline void F_39 ( struct V_40 * V_2 , struct V_3 * V_4 )
{
}
static inline void F_42 ( struct V_3 * V_4 )
{
}
static inline void F_83 ( struct V_3 * V_4 )
{
}
static inline void F_87 ( struct V_3 * V_4 )
{
}
static inline bool F_57 ( struct V_3 * V_4 )
{
return false ;
}
static inline void F_58 ( struct V_3 * V_4 )
{
}
static inline bool F_59 ( struct V_3 * V_4 )
{
return false ;
}
static inline void F_71 ( struct V_3 * V_4 )
{
}
static inline void F_76 ( struct V_3 * V_4 )
{
}
static inline int F_61 ( struct V_3 * V_4 )
{
return - V_129 ;
}
static inline bool F_90 ( struct V_3 * V_4 )
{
return false ;
}
static inline bool F_91 ( struct V_3 * V_4 )
{
return false ;
}
static void F_92 ( struct V_125 * V_10 )
{
struct V_3 * V_4 =
F_93 ( V_10 , struct V_3 , V_10 ) ;
V_4 -> V_98 &= ~ V_99 ;
F_46 ( V_4 -> V_98 , V_4 -> V_10 . V_11 + V_100 ) ;
F_58 ( V_4 ) ;
}
static void F_94 ( struct V_125 * V_10 )
{
struct V_3 * V_4 =
F_93 ( V_10 , struct V_3 , V_10 ) ;
if ( ! F_59 ( V_4 ) ) {
V_4 -> V_98 |= V_99 ;
F_46 ( V_4 -> V_98 , V_4 -> V_10 . V_11 + V_100 ) ;
}
}
static void F_95 ( struct V_125 * V_10 )
{
struct V_3 * V_4 =
F_93 ( V_10 , struct V_3 , V_10 ) ;
V_4 -> V_98 &= ~ ( V_137 | V_172 | V_173 |
V_174 | V_175 | V_176 ) ;
F_46 ( V_4 -> V_98 , V_4 -> V_10 . V_11 + V_100 ) ;
F_76 ( V_4 ) ;
}
static void F_96 ( struct V_125 * V_10 )
{
struct V_3 * V_4 =
F_93 ( V_10 , struct V_3 , V_10 ) ;
V_4 -> V_98 |= V_177 | V_178 | V_179 | V_180 ;
F_46 ( V_4 -> V_98 , V_4 -> V_10 . V_11 + V_100 ) ;
}
static void F_97 ( struct V_3 * V_4 )
__releases( &uap->port.lock
static void F_98 ( struct V_3 * V_4 )
{
struct V_105 * V_97 = & V_4 -> V_10 . V_96 -> V_97 ;
int V_106 ;
if ( V_4 -> V_10 . V_122 ) {
F_46 ( V_4 -> V_10 . V_122 , V_4 -> V_10 . V_11 + V_14 ) ;
V_4 -> V_10 . V_17 . V_119 ++ ;
V_4 -> V_10 . V_122 = 0 ;
return;
}
if ( F_48 ( V_97 ) || F_47 ( & V_4 -> V_10 ) ) {
F_92 ( & V_4 -> V_10 ) ;
return;
}
if ( F_57 ( V_4 ) )
return;
V_106 = V_4 -> V_55 >> 1 ;
do {
F_46 ( V_97 -> V_39 [ V_97 -> V_107 ] , V_4 -> V_10 . V_11 + V_14 ) ;
V_97 -> V_107 = ( V_97 -> V_107 + 1 ) & ( V_110 - 1 ) ;
V_4 -> V_10 . V_17 . V_119 ++ ;
if ( F_48 ( V_97 ) )
break;
} while ( -- V_106 > 0 );
if ( F_51 ( V_97 ) < V_120 )
F_56 ( & V_4 -> V_10 ) ;
if ( F_48 ( V_97 ) )
F_92 ( & V_4 -> V_10 ) ;
}
static void F_99 ( struct V_3 * V_4 )
{
unsigned int V_5 , V_181 ;
V_5 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_182 ;
V_181 = V_5 ^ V_4 -> V_183 ;
V_4 -> V_183 = V_5 ;
if ( ! V_181 )
return;
if ( V_181 & V_184 )
F_100 ( & V_4 -> V_10 , V_5 & V_184 ) ;
if ( V_181 & V_185 )
V_4 -> V_10 . V_17 . V_186 ++ ;
if ( V_181 & V_187 )
F_101 ( & V_4 -> V_10 , V_5 & V_187 ) ;
F_102 ( & V_4 -> V_10 . V_96 -> V_10 . V_188 ) ;
}
static T_7 F_103 ( int V_189 , void * V_190 )
{
struct V_3 * V_4 = V_190 ;
unsigned long V_89 ;
unsigned int V_5 , V_191 = V_192 ;
int V_193 = 0 ;
unsigned int V_194 ;
F_44 ( & V_4 -> V_10 . V_91 , V_89 ) ;
V_5 = F_5 ( V_4 -> V_10 . V_11 + V_195 ) ;
if ( V_5 ) {
do {
if ( V_4 -> V_165 -> V_196 ) {
F_46 ( 0x00 , V_4 -> V_10 . V_11 + V_148 ) ;
V_194 = F_5 ( V_4 -> V_10 . V_11 + V_148 ) ;
V_194 = F_5 ( V_4 -> V_10 . V_11 + V_148 ) ;
}
F_46 ( V_5 & ~ ( V_197 | V_198 |
V_199 ) ,
V_4 -> V_10 . V_11 + V_148 ) ;
if ( V_5 & ( V_198 | V_199 ) ) {
if ( F_91 ( V_4 ) )
F_71 ( V_4 ) ;
else
F_97 ( V_4 ) ;
}
if ( V_5 & ( V_200 | V_201 |
V_202 | V_203 ) )
F_99 ( V_4 ) ;
if ( V_5 & V_197 )
F_98 ( V_4 ) ;
if ( V_191 -- == 0 )
break;
V_5 = F_5 ( V_4 -> V_10 . V_11 + V_195 ) ;
} while ( V_5 != 0 );
V_193 = 1 ;
}
F_49 ( & V_4 -> V_10 . V_91 , V_89 ) ;
return F_104 ( V_193 ) ;
}
static unsigned int F_105 ( struct V_125 * V_10 )
{
struct V_3 * V_4 =
F_93 ( V_10 , struct V_3 , V_10 ) ;
unsigned int V_5 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) ;
return V_5 & ( V_171 | V_124 ) ? 0 : V_204 ;
}
static unsigned int F_106 ( struct V_125 * V_10 )
{
struct V_3 * V_4 =
F_93 ( V_10 , struct V_3 , V_10 ) ;
unsigned int V_205 = 0 ;
unsigned int V_5 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) ;
#define F_107 ( T_8 , T_9 ) \
if (status & uartbit) \
result |= tiocmbit
F_107 ( V_184 , V_206 ) ;
F_107 ( V_185 , V_207 ) ;
F_107 ( V_187 , V_208 ) ;
F_107 ( V_209 , V_210 ) ;
#undef F_107
return V_205 ;
}
static void F_108 ( struct V_125 * V_10 , unsigned int V_211 )
{
struct V_3 * V_4 =
F_93 ( V_10 , struct V_3 , V_10 ) ;
unsigned int V_212 ;
V_212 = F_5 ( V_4 -> V_10 . V_11 + V_213 ) ;
#define F_107 ( T_9 , T_8 ) \
if (mctrl & tiocmbit) \
cr |= uartbit; \
else \
cr &= ~uartbit
F_107 ( V_214 , V_215 ) ;
F_107 ( V_216 , V_217 ) ;
F_107 ( V_218 , V_219 ) ;
F_107 ( V_220 , V_221 ) ;
F_107 ( V_222 , V_223 ) ;
if ( V_4 -> V_224 ) {
F_107 ( V_214 , V_225 ) ;
}
#undef F_107
F_46 ( V_212 , V_4 -> V_10 . V_11 + V_213 ) ;
}
static void F_109 ( struct V_125 * V_10 , int V_226 )
{
struct V_3 * V_4 =
F_93 ( V_10 , struct V_3 , V_10 ) ;
unsigned long V_89 ;
unsigned int V_227 ;
F_44 ( & V_4 -> V_10 . V_91 , V_89 ) ;
V_227 = F_5 ( V_4 -> V_10 . V_11 + V_4 -> V_228 ) ;
if ( V_226 == - 1 )
V_227 |= V_229 ;
else
V_227 &= ~ V_229 ;
F_46 ( V_227 , V_4 -> V_10 . V_11 + V_4 -> V_228 ) ;
F_49 ( & V_4 -> V_10 . V_91 , V_89 ) ;
}
static void F_110 ( struct V_125 * V_10 )
{
struct V_3 * V_4 =
F_93 ( V_10 , struct V_3 , V_10 ) ;
unsigned char T_10 * V_230 = V_4 -> V_10 . V_11 ;
F_46 ( F_5 ( V_230 + V_195 ) , V_230 + V_148 ) ;
F_46 ( F_5 ( V_230 + V_100 ) & ~ V_99 , V_230 + V_100 ) ;
}
static int F_111 ( struct V_125 * V_10 )
{
struct V_3 * V_4 =
F_93 ( V_10 , struct V_3 , V_10 ) ;
unsigned int V_5 ;
F_110 ( V_10 ) ;
V_5 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) ;
if ( V_5 & V_13 )
return V_231 ;
return F_5 ( V_4 -> V_10 . V_11 + V_14 ) ;
}
static void F_112 ( struct V_125 * V_10 ,
unsigned char V_6 )
{
struct V_3 * V_4 =
F_93 ( V_10 , struct V_3 , V_10 ) ;
while ( F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_124 )
F_88 () ;
F_46 ( V_6 , V_4 -> V_10 . V_11 + V_14 ) ;
}
static int F_113 ( struct V_125 * V_10 )
{
struct V_3 * V_4 =
F_93 ( V_10 , struct V_3 , V_10 ) ;
int V_232 ;
F_114 ( V_10 -> V_2 ) ;
V_232 = F_115 ( V_4 -> V_233 ) ;
if ( V_232 )
return V_232 ;
V_4 -> V_10 . V_234 = F_116 ( V_4 -> V_233 ) ;
F_46 ( V_144 | V_145 | V_146 | V_147 |
V_198 | V_199 , V_4 -> V_10 . V_11 + V_148 ) ;
V_4 -> V_98 = F_5 ( V_4 -> V_10 . V_11 + V_100 ) ;
F_46 ( V_172 | V_137 , V_4 -> V_10 . V_11 + V_100 ) ;
if ( F_21 ( V_4 -> V_10 . V_2 ) ) {
struct V_44 * V_45 ;
V_45 = F_21 ( V_4 -> V_10 . V_2 ) ;
if ( V_45 -> V_235 )
V_45 -> V_235 () ;
}
return 0 ;
}
static void F_117 ( struct V_3 * V_4 , unsigned int V_227 )
{
F_46 ( V_227 , V_4 -> V_10 . V_11 + V_4 -> V_236 ) ;
if ( V_4 -> V_236 != V_4 -> V_228 ) {
int V_237 ;
for ( V_237 = 0 ; V_237 < 10 ; ++ V_237 )
F_46 ( 0xff , V_4 -> V_10 . V_11 + V_195 ) ;
F_46 ( V_227 , V_4 -> V_10 . V_11 + V_4 -> V_228 ) ;
}
}
static int F_118 ( struct V_125 * V_10 )
{
struct V_3 * V_4 =
F_93 ( V_10 , struct V_3 , V_10 ) ;
unsigned int V_212 , V_227 , V_238 , V_239 ;
int V_232 ;
V_232 = F_113 ( V_10 ) ;
if ( V_232 )
goto V_240;
F_46 ( V_4 -> V_98 , V_4 -> V_10 . V_11 + V_100 ) ;
V_232 = F_119 ( V_4 -> V_10 . V_189 , F_103 , 0 , L_25 , V_4 ) ;
if ( V_232 )
goto V_240;
F_46 ( V_4 -> V_165 -> V_241 , V_4 -> V_10 . V_11 + V_242 ) ;
F_74 ( & V_4 -> V_10 . V_91 ) ;
V_238 = F_5 ( V_4 -> V_10 . V_11 + V_243 ) ;
V_239 = F_5 ( V_4 -> V_10 . V_11 + V_244 ) ;
V_227 = F_5 ( V_4 -> V_10 . V_11 + V_4 -> V_236 ) ;
V_212 = V_245 | V_246 | V_223 ;
F_46 ( V_212 , V_4 -> V_10 . V_11 + V_213 ) ;
F_46 ( 0 , V_4 -> V_10 . V_11 + V_243 ) ;
F_46 ( 1 , V_4 -> V_10 . V_11 + V_244 ) ;
F_117 ( V_4 , 0 ) ;
F_46 ( 0 , V_4 -> V_10 . V_11 + V_14 ) ;
while ( F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_171 )
F_88 () ;
F_46 ( V_238 , V_4 -> V_10 . V_11 + V_243 ) ;
F_46 ( V_239 , V_4 -> V_10 . V_11 + V_244 ) ;
F_117 ( V_4 , V_227 ) ;
V_212 = V_4 -> V_247 & ( V_215 | V_217 ) ;
V_212 |= V_245 | V_248 | V_246 ;
F_46 ( V_212 , V_4 -> V_10 . V_11 + V_213 ) ;
F_75 ( & V_4 -> V_10 . V_91 ) ;
V_4 -> V_183 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_182 ;
F_83 ( V_4 ) ;
F_74 ( & V_4 -> V_10 . V_91 ) ;
F_46 ( V_198 | V_199 ,
V_4 -> V_10 . V_11 + V_148 ) ;
V_4 -> V_98 = V_172 ;
if ( ! F_91 ( V_4 ) )
V_4 -> V_98 |= V_137 ;
F_46 ( V_4 -> V_98 , V_4 -> V_10 . V_11 + V_100 ) ;
F_75 ( & V_4 -> V_10 . V_91 ) ;
return 0 ;
V_240:
F_120 ( V_4 -> V_233 ) ;
return V_232 ;
}
static void F_121 ( struct V_3 * V_4 ,
unsigned int V_249 )
{
unsigned long V_250 ;
V_250 = F_5 ( V_4 -> V_10 . V_11 + V_249 ) ;
V_250 &= ~ ( V_229 | V_251 ) ;
F_46 ( V_250 , V_4 -> V_10 . V_11 + V_249 ) ;
}
static void F_122 ( struct V_125 * V_10 )
{
struct V_3 * V_4 =
F_93 ( V_10 , struct V_3 , V_10 ) ;
unsigned int V_212 ;
F_74 ( & V_4 -> V_10 . V_91 ) ;
V_4 -> V_98 = 0 ;
F_46 ( V_4 -> V_98 , V_4 -> V_10 . V_11 + V_100 ) ;
F_46 ( 0xffff , V_4 -> V_10 . V_11 + V_148 ) ;
F_75 ( & V_4 -> V_10 . V_91 ) ;
F_87 ( V_4 ) ;
F_123 ( V_4 -> V_10 . V_189 , V_4 ) ;
V_4 -> V_224 = false ;
F_74 ( & V_4 -> V_10 . V_91 ) ;
V_212 = F_5 ( V_4 -> V_10 . V_11 + V_213 ) ;
V_4 -> V_247 = V_212 ;
V_212 &= V_215 | V_217 ;
V_212 |= V_245 | V_246 ;
F_46 ( V_212 , V_4 -> V_10 . V_11 + V_213 ) ;
F_75 ( & V_4 -> V_10 . V_91 ) ;
F_121 ( V_4 , V_4 -> V_236 ) ;
if ( V_4 -> V_236 != V_4 -> V_228 )
F_121 ( V_4 , V_4 -> V_228 ) ;
F_120 ( V_4 -> V_233 ) ;
F_124 ( V_10 -> V_2 ) ;
if ( F_21 ( V_4 -> V_10 . V_2 ) ) {
struct V_44 * V_45 ;
V_45 = F_21 ( V_4 -> V_10 . V_2 ) ;
if ( V_45 -> exit )
V_45 -> exit () ;
}
if ( V_4 -> V_10 . V_252 -> V_253 )
V_4 -> V_10 . V_252 -> V_253 ( V_10 ) ;
}
static void
F_125 ( struct V_125 * V_10 , struct V_254 * V_255 ,
struct V_254 * V_256 )
{
struct V_3 * V_4 =
F_93 ( V_10 , struct V_3 , V_10 ) ;
unsigned int V_227 , V_247 ;
unsigned long V_89 ;
unsigned int V_257 , V_258 , V_259 ;
if ( V_4 -> V_165 -> V_260 )
V_259 = 8 ;
else
V_259 = 16 ;
V_257 = F_126 ( V_10 , V_255 , V_256 , 0 ,
V_10 -> V_234 / V_259 ) ;
#ifdef F_127
if ( V_4 -> V_72 . V_73 )
V_4 -> V_72 . V_76 = F_128 ( 10000000 , V_257 ) ;
#endif
if ( V_257 > V_10 -> V_234 / 16 )
V_258 = F_129 ( V_10 -> V_234 * 8 , V_257 ) ;
else
V_258 = F_129 ( V_10 -> V_234 * 4 , V_257 ) ;
switch ( V_255 -> V_261 & V_262 ) {
case V_263 :
V_227 = V_264 ;
break;
case V_265 :
V_227 = V_266 ;
break;
case V_267 :
V_227 = V_268 ;
break;
default:
V_227 = V_269 ;
break;
}
if ( V_255 -> V_261 & V_270 )
V_227 |= V_271 ;
if ( V_255 -> V_261 & V_272 ) {
V_227 |= V_273 ;
if ( ! ( V_255 -> V_261 & V_274 ) )
V_227 |= V_275 ;
}
if ( V_4 -> V_55 > 1 )
V_227 |= V_251 ;
F_44 ( & V_10 -> V_91 , V_89 ) ;
F_130 ( V_10 , V_255 -> V_261 , V_257 ) ;
V_10 -> V_28 = V_26 | 255 ;
if ( V_255 -> V_276 & V_277 )
V_10 -> V_28 |= V_21 | V_22 ;
if ( V_255 -> V_276 & ( V_278 | V_279 | V_280 ) )
V_10 -> V_28 |= V_20 ;
V_10 -> V_281 = 0 ;
if ( V_255 -> V_276 & V_282 )
V_10 -> V_281 |= V_21 | V_22 ;
if ( V_255 -> V_276 & V_278 ) {
V_10 -> V_281 |= V_20 ;
if ( V_255 -> V_276 & V_282 )
V_10 -> V_281 |= V_26 ;
}
if ( ( V_255 -> V_261 & V_283 ) == 0 )
V_10 -> V_281 |= V_15 ;
if ( F_131 ( V_10 , V_255 -> V_261 ) )
F_96 ( V_10 ) ;
V_247 = F_5 ( V_10 -> V_11 + V_213 ) ;
F_46 ( 0 , V_10 -> V_11 + V_213 ) ;
if ( V_255 -> V_261 & V_284 ) {
if ( V_247 & V_215 )
V_247 |= V_225 ;
V_247 |= V_285 ;
V_4 -> V_224 = true ;
} else {
V_247 &= ~ ( V_285 | V_225 ) ;
V_4 -> V_224 = false ;
}
if ( V_4 -> V_165 -> V_260 ) {
if ( V_257 > V_10 -> V_234 / 16 )
V_247 |= V_286 ;
else
V_247 &= ~ V_286 ;
}
if ( V_4 -> V_165 -> V_260 ) {
if ( ( V_257 >= 3000000 ) && ( V_257 < 3250000 ) && ( V_258 > 1 ) )
V_258 -= 1 ;
else if ( ( V_257 > 3250000 ) && ( V_258 > 2 ) )
V_258 -= 2 ;
}
F_46 ( V_258 & 0x3f , V_10 -> V_11 + V_243 ) ;
F_46 ( V_258 >> 6 , V_10 -> V_11 + V_244 ) ;
F_117 ( V_4 , V_227 ) ;
F_46 ( V_247 , V_10 -> V_11 + V_213 ) ;
F_49 ( & V_10 -> V_91 , V_89 ) ;
}
static const char * F_132 ( struct V_125 * V_10 )
{
struct V_3 * V_4 =
F_93 ( V_10 , struct V_3 , V_10 ) ;
return V_4 -> V_10 . type == V_287 ? V_4 -> type : NULL ;
}
static void F_133 ( struct V_125 * V_10 )
{
F_134 ( V_10 -> V_49 , V_288 ) ;
}
static int F_135 ( struct V_125 * V_10 )
{
return F_136 ( V_10 -> V_49 , V_288 , L_25 )
!= NULL ? 0 : - V_113 ;
}
static void F_137 ( struct V_125 * V_10 , int V_89 )
{
if ( V_89 & V_289 ) {
V_10 -> type = V_287 ;
F_135 ( V_10 ) ;
}
}
static int F_138 ( struct V_125 * V_10 , struct V_290 * V_291 )
{
int V_123 = 0 ;
if ( V_291 -> type != V_292 && V_291 -> type != V_287 )
V_123 = - V_293 ;
if ( V_291 -> V_189 < 0 || V_291 -> V_189 >= V_294 )
V_123 = - V_293 ;
if ( V_291 -> V_295 < 9600 )
V_123 = - V_293 ;
return V_123 ;
}
static void F_139 ( struct V_125 * V_10 , int V_6 )
{
struct V_3 * V_4 =
F_93 ( V_10 , struct V_3 , V_10 ) ;
while ( F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_124 )
F_88 () ;
F_46 ( V_6 , V_4 -> V_10 . V_11 + V_14 ) ;
}
static void
F_140 ( struct V_296 * V_297 , const char * V_298 , unsigned int V_106 )
{
struct V_3 * V_4 = V_299 [ V_297 -> V_300 ] ;
unsigned int V_5 , V_247 , V_301 ;
unsigned long V_89 ;
int V_302 = 1 ;
F_141 ( V_4 -> V_233 ) ;
F_142 ( V_89 ) ;
if ( V_4 -> V_10 . V_303 )
V_302 = 0 ;
else if ( V_304 )
V_302 = F_143 ( & V_4 -> V_10 . V_91 ) ;
else
F_70 ( & V_4 -> V_10 . V_91 ) ;
V_247 = F_5 ( V_4 -> V_10 . V_11 + V_213 ) ;
V_301 = V_247 & ~ V_285 ;
V_301 |= V_245 | V_246 ;
F_46 ( V_301 , V_4 -> V_10 . V_11 + V_213 ) ;
F_144 ( & V_4 -> V_10 , V_298 , V_106 , F_139 ) ;
do {
V_5 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) ;
} while ( V_5 & V_171 );
F_46 ( V_247 , V_4 -> V_10 . V_11 + V_213 ) ;
if ( V_302 )
F_67 ( & V_4 -> V_10 . V_91 ) ;
F_145 ( V_89 ) ;
F_146 ( V_4 -> V_233 ) ;
}
static void T_5
F_147 ( struct V_3 * V_4 , int * V_257 ,
int * V_24 , int * V_305 )
{
if ( F_5 ( V_4 -> V_10 . V_11 + V_213 ) & V_245 ) {
unsigned int V_227 , V_239 , V_238 ;
V_227 = F_5 ( V_4 -> V_10 . V_11 + V_4 -> V_228 ) ;
* V_24 = 'n' ;
if ( V_227 & V_273 ) {
if ( V_227 & V_275 )
* V_24 = 'e' ;
else
* V_24 = 'o' ;
}
if ( ( V_227 & 0x60 ) == V_268 )
* V_305 = 7 ;
else
* V_305 = 8 ;
V_239 = F_5 ( V_4 -> V_10 . V_11 + V_244 ) ;
V_238 = F_5 ( V_4 -> V_10 . V_11 + V_243 ) ;
* V_257 = V_4 -> V_10 . V_234 * 4 / ( 64 * V_239 + V_238 ) ;
if ( V_4 -> V_165 -> V_260 ) {
if ( F_5 ( V_4 -> V_10 . V_11 + V_213 )
& V_286 )
* V_257 *= 2 ;
}
}
}
static int T_5 F_148 ( struct V_296 * V_297 , char * V_306 )
{
struct V_3 * V_4 ;
int V_257 = 38400 ;
int V_305 = 8 ;
int V_24 = 'n' ;
int V_307 = 'n' ;
int V_123 ;
if ( V_297 -> V_300 >= V_308 )
V_297 -> V_300 = 0 ;
V_4 = V_299 [ V_297 -> V_300 ] ;
if ( ! V_4 )
return - V_309 ;
F_114 ( V_4 -> V_10 . V_2 ) ;
V_123 = F_149 ( V_4 -> V_233 ) ;
if ( V_123 )
return V_123 ;
if ( F_21 ( V_4 -> V_10 . V_2 ) ) {
struct V_44 * V_45 ;
V_45 = F_21 ( V_4 -> V_10 . V_2 ) ;
if ( V_45 -> V_235 )
V_45 -> V_235 () ;
}
V_4 -> V_10 . V_234 = F_116 ( V_4 -> V_233 ) ;
if ( V_306 )
F_150 ( V_306 , & V_257 , & V_24 , & V_305 , & V_307 ) ;
else
F_147 ( V_4 , & V_257 , & V_24 , & V_305 ) ;
return F_151 ( & V_4 -> V_10 , V_297 , V_257 , V_24 , V_305 , V_307 ) ;
}
static void F_152 ( struct V_125 * V_10 , int V_310 )
{
while ( F_153 ( V_10 -> V_11 + V_12 ) & V_124 )
;
F_154 ( V_310 , V_10 -> V_11 + V_14 ) ;
while ( F_153 ( V_10 -> V_11 + V_12 ) & V_171 )
;
}
static void F_155 ( struct V_296 * V_311 , const char * V_298 , unsigned V_312 )
{
struct V_313 * V_2 = V_311 -> V_87 ;
F_144 ( & V_2 -> V_10 , V_298 , V_312 , F_152 ) ;
}
static int T_5 F_156 ( struct V_313 * V_40 ,
const char * V_314 )
{
if ( ! V_40 -> V_10 . V_11 )
return - V_309 ;
V_40 -> V_311 -> V_315 = F_155 ;
return 0 ;
}
static int F_157 ( int V_300 , struct V_40 * V_2 )
{
struct V_316 * V_317 ;
static bool V_318 = false ;
static bool V_319 = false ;
int V_123 = V_300 ;
if ( ! F_158 ( V_320 ) )
return V_123 ;
V_317 = V_2 -> V_79 ;
if ( ! V_317 )
return V_123 ;
V_123 = F_159 ( V_317 , L_26 ) ;
if ( F_160 ( V_123 ) ) {
V_319 = true ;
V_123 = V_300 ;
} else {
V_318 = true ;
if ( V_123 >= F_161 ( V_299 ) || V_299 [ V_123 ] != NULL ) {
F_66 ( V_2 , L_27 , V_123 ) ;
V_123 = V_300 ;
}
}
if ( V_318 && V_319 )
F_66 ( V_2 , L_28 ) ;
return V_123 ;
}
static int F_162 ( struct V_1 * V_2 , const struct V_321 * V_322 )
{
struct V_3 * V_4 ;
struct V_323 * V_165 = V_322 -> V_87 ;
void T_10 * V_324 ;
int V_237 , V_123 ;
for ( V_237 = 0 ; V_237 < F_161 ( V_299 ) ; V_237 ++ )
if ( V_299 [ V_237 ] == NULL )
break;
if ( V_237 == F_161 ( V_299 ) )
return - V_113 ;
V_4 = F_163 ( & V_2 -> V_2 , sizeof( struct V_3 ) ,
V_42 ) ;
if ( V_4 == NULL )
return - V_43 ;
V_237 = F_157 ( V_237 , & V_2 -> V_2 ) ;
V_324 = F_164 ( & V_2 -> V_2 , V_2 -> V_325 . V_326 ,
F_165 ( & V_2 -> V_325 ) ) ;
if ( ! V_324 )
return - V_43 ;
V_4 -> V_233 = F_166 ( & V_2 -> V_2 , NULL ) ;
if ( F_167 ( V_4 -> V_233 ) )
return F_168 ( V_4 -> V_233 ) ;
V_4 -> V_165 = V_165 ;
V_4 -> V_236 = V_165 -> V_236 ;
V_4 -> V_228 = V_165 -> V_228 ;
V_4 -> V_247 = 0 ;
V_4 -> V_55 = V_165 -> V_327 ( V_2 ) ;
V_4 -> V_10 . V_2 = & V_2 -> V_2 ;
V_4 -> V_10 . V_49 = V_2 -> V_325 . V_326 ;
V_4 -> V_10 . V_11 = V_324 ;
V_4 -> V_10 . V_328 = V_329 ;
V_4 -> V_10 . V_189 = V_2 -> V_189 [ 0 ] ;
V_4 -> V_10 . V_55 = V_4 -> V_55 ;
V_4 -> V_10 . V_252 = & V_330 ;
V_4 -> V_10 . V_89 = V_331 ;
V_4 -> V_10 . line = V_237 ;
F_39 ( & V_2 -> V_2 , V_4 ) ;
F_46 ( 0 , V_4 -> V_10 . V_11 + V_100 ) ;
F_46 ( 0xffff , V_4 -> V_10 . V_11 + V_148 ) ;
snprintf ( V_4 -> type , sizeof( V_4 -> type ) , L_29 , F_2 ( V_2 ) ) ;
V_299 [ V_237 ] = V_4 ;
F_169 ( V_2 , V_4 ) ;
if ( ! V_332 . V_96 ) {
V_123 = F_170 ( & V_332 ) ;
if ( V_123 < 0 ) {
F_171 ( L_30 ) ;
return V_123 ;
}
}
V_123 = F_172 ( & V_332 , & V_4 -> V_10 ) ;
if ( V_123 ) {
V_299 [ V_237 ] = NULL ;
F_173 ( & V_332 ) ;
F_42 ( V_4 ) ;
}
return V_123 ;
}
static int F_174 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_175 ( V_2 ) ;
bool V_333 = false ;
int V_237 ;
F_176 ( & V_332 , & V_4 -> V_10 ) ;
for ( V_237 = 0 ; V_237 < F_161 ( V_299 ) ; V_237 ++ )
if ( V_299 [ V_237 ] == V_4 )
V_299 [ V_237 ] = NULL ;
else if ( V_299 [ V_237 ] )
V_333 = true ;
F_42 ( V_4 ) ;
if ( ! V_333 )
F_173 ( & V_332 ) ;
return 0 ;
}
static int F_177 ( struct V_40 * V_2 )
{
struct V_3 * V_4 = F_178 ( V_2 ) ;
if ( ! V_4 )
return - V_293 ;
return F_179 ( & V_332 , & V_4 -> V_10 ) ;
}
static int F_180 ( struct V_40 * V_2 )
{
struct V_3 * V_4 = F_178 ( V_2 ) ;
if ( ! V_4 )
return - V_293 ;
return F_181 ( & V_332 , & V_4 -> V_10 ) ;
}
static int T_5 F_182 ( void )
{
F_183 ( V_334 L_31 ) ;
return F_184 ( & V_335 ) ;
}
static void T_11 F_185 ( void )
{
F_186 ( & V_335 ) ;
}
