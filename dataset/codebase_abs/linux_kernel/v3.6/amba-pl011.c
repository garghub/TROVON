static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
unsigned int V_5 , V_6 = 256 ;
int V_7 = 0 ;
while ( V_6 -- ) {
V_3 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) ;
if ( V_3 & V_11 )
break;
V_4 = F_2 ( V_2 -> V_8 . V_9 + V_12 ) |
V_13 ;
V_5 = V_14 ;
V_2 -> V_8 . V_15 . V_16 ++ ;
V_7 ++ ;
if ( F_3 ( V_4 & V_17 ) ) {
if ( V_4 & V_18 ) {
V_4 &= ~ ( V_19 | V_20 ) ;
V_2 -> V_8 . V_15 . V_21 ++ ;
if ( F_4 ( & V_2 -> V_8 ) )
continue;
} else if ( V_4 & V_20 )
V_2 -> V_8 . V_15 . V_22 ++ ;
else if ( V_4 & V_19 )
V_2 -> V_8 . V_15 . V_23 ++ ;
if ( V_4 & V_24 )
V_2 -> V_8 . V_15 . V_25 ++ ;
V_4 &= V_2 -> V_8 . V_26 ;
if ( V_4 & V_18 )
V_5 = V_27 ;
else if ( V_4 & V_20 )
V_5 = V_28 ;
else if ( V_4 & V_19 )
V_5 = V_29 ;
}
if ( F_5 ( & V_2 -> V_8 , V_4 & 255 ) )
continue;
F_6 ( & V_2 -> V_8 , V_4 , V_24 , V_4 , V_5 ) ;
}
return V_7 ;
}
static int F_7 ( struct V_30 * V_31 , struct V_32 * V_33 ,
enum V_34 V_35 )
{
V_33 -> V_36 = F_8 ( V_37 , V_38 ) ;
if ( ! V_33 -> V_36 )
return - V_39 ;
F_9 ( & V_33 -> V_33 , V_33 -> V_36 , V_37 ) ;
if ( F_10 ( V_31 -> V_40 -> V_41 , & V_33 -> V_33 , 1 , V_35 ) != 1 ) {
F_11 ( V_33 -> V_36 ) ;
return - V_42 ;
}
return 0 ;
}
static void F_12 ( struct V_30 * V_31 , struct V_32 * V_33 ,
enum V_34 V_35 )
{
if ( V_33 -> V_36 ) {
F_13 ( V_31 -> V_40 -> V_41 , & V_33 -> V_33 , 1 , V_35 ) ;
F_11 ( V_33 -> V_36 ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = V_2 -> V_8 . V_41 -> V_45 ;
struct V_46 V_47 = {
. V_48 = V_2 -> V_8 . V_49 + V_12 ,
. V_50 = V_51 ,
. V_52 = V_53 ,
. V_54 = V_2 -> V_55 >> 1 ,
. V_56 = false ,
} ;
struct V_30 * V_31 ;
T_2 V_57 ;
if ( ! V_44 || ! V_44 -> V_58 ) {
F_15 ( V_2 -> V_8 . V_41 , L_1 ) ;
return;
}
F_16 ( V_57 ) ;
F_17 ( V_59 , V_57 ) ;
V_31 = F_18 ( V_57 , V_44 -> V_58 , V_44 -> V_60 ) ;
if ( ! V_31 ) {
F_19 ( V_2 -> V_8 . V_41 , L_2 ) ;
return;
}
F_20 ( V_31 , & V_47 ) ;
V_2 -> V_61 . V_31 = V_31 ;
F_15 ( V_2 -> V_8 . V_41 , L_3 ,
F_21 ( V_2 -> V_61 . V_31 ) ) ;
if ( V_44 -> V_62 ) {
struct V_46 V_63 = {
. V_64 = V_2 -> V_8 . V_49 + V_12 ,
. V_65 = V_51 ,
. V_52 = V_66 ,
. V_67 = V_2 -> V_55 >> 1 ,
. V_56 = false ,
} ;
V_31 = F_18 ( V_57 , V_44 -> V_58 , V_44 -> V_62 ) ;
if ( ! V_31 ) {
F_19 ( V_2 -> V_8 . V_41 , L_4 ) ;
return;
}
F_20 ( V_31 , & V_63 ) ;
V_2 -> V_68 . V_31 = V_31 ;
F_15 ( V_2 -> V_8 . V_41 , L_5 ,
F_21 ( V_2 -> V_68 . V_31 ) ) ;
}
}
static int T_3 F_22 ( void )
{
struct V_69 * V_70 , * V_71 ;
F_23 (node, tmp, &pl011_dma_uarts) {
struct V_72 * V_73 = F_24 ( V_70 , struct V_72 , V_70 ) ;
F_14 ( V_73 -> V_2 ) ;
F_25 ( V_70 ) ;
F_11 ( V_73 ) ;
}
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_72 * V_73 = F_27 ( sizeof( struct V_72 ) , V_38 ) ;
if ( V_73 ) {
V_73 -> V_2 = V_2 ;
F_28 ( & V_73 -> V_70 , & V_74 ) ;
}
}
static void F_26 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_61 . V_31 )
F_30 ( V_2 -> V_61 . V_31 ) ;
if ( V_2 -> V_68 . V_31 )
F_30 ( V_2 -> V_68 . V_31 ) ;
}
static void F_31 ( void * V_75 )
{
struct V_1 * V_2 = V_75 ;
struct V_76 * V_61 = & V_2 -> V_61 ;
unsigned long V_77 ;
T_1 V_78 ;
F_32 ( & V_2 -> V_8 . V_79 , V_77 ) ;
if ( V_2 -> V_61 . V_80 )
F_13 ( V_61 -> V_31 -> V_40 -> V_41 , & V_61 -> V_33 , 1 ,
V_81 ) ;
V_78 = V_2 -> V_78 ;
V_2 -> V_78 = V_78 & ~ V_82 ;
F_33 ( V_2 -> V_78 , V_2 -> V_8 . V_9 + V_83 ) ;
if ( ! ( V_78 & V_82 ) || F_34 ( & V_2 -> V_8 ) ||
F_35 ( & V_2 -> V_8 . V_84 -> V_85 ) ) {
V_2 -> V_61 . V_80 = false ;
F_36 ( & V_2 -> V_8 . V_79 , V_77 ) ;
return;
}
if ( F_37 ( V_2 ) <= 0 ) {
V_2 -> V_86 |= V_87 ;
F_33 ( V_2 -> V_86 , V_2 -> V_8 . V_9 + V_88 ) ;
}
F_36 ( & V_2 -> V_8 . V_79 , V_77 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_76 * V_61 = & V_2 -> V_61 ;
struct V_30 * V_31 = V_61 -> V_31 ;
struct V_89 * V_90 = V_31 -> V_40 ;
struct V_91 * V_92 ;
struct V_93 * V_85 = & V_2 -> V_8 . V_84 -> V_85 ;
unsigned int V_94 ;
V_94 = F_38 ( V_85 ) ;
if ( V_94 < ( V_2 -> V_55 >> 1 ) ) {
V_2 -> V_61 . V_80 = false ;
return 0 ;
}
V_94 -= 1 ;
if ( V_94 > V_37 )
V_94 = V_37 ;
if ( V_85 -> V_95 < V_85 -> V_96 )
memcpy ( & V_61 -> V_36 [ 0 ] , & V_85 -> V_36 [ V_85 -> V_95 ] , V_94 ) ;
else {
T_4 V_97 = V_98 - V_85 -> V_95 ;
T_4 V_99 = V_85 -> V_96 ;
memcpy ( & V_61 -> V_36 [ 0 ] , & V_85 -> V_36 [ V_85 -> V_95 ] , V_97 ) ;
if ( V_99 )
memcpy ( & V_61 -> V_36 [ V_97 ] , & V_85 -> V_36 [ 0 ] , V_99 ) ;
}
V_61 -> V_33 . V_100 = V_94 ;
if ( F_10 ( V_90 -> V_41 , & V_61 -> V_33 , 1 , V_81 ) != 1 ) {
V_2 -> V_61 . V_80 = false ;
F_39 ( V_2 -> V_8 . V_41 , L_6 ) ;
return - V_101 ;
}
V_92 = F_40 ( V_31 , & V_61 -> V_33 , 1 , V_53 ,
V_102 | V_103 ) ;
if ( ! V_92 ) {
F_13 ( V_90 -> V_41 , & V_61 -> V_33 , 1 , V_81 ) ;
V_2 -> V_61 . V_80 = false ;
F_39 ( V_2 -> V_8 . V_41 , L_7 ) ;
return - V_101 ;
}
V_92 -> V_104 = F_31 ;
V_92 -> V_105 = V_2 ;
F_41 ( V_92 ) ;
V_90 -> V_106 ( V_31 ) ;
V_2 -> V_78 |= V_82 ;
F_33 ( V_2 -> V_78 , V_2 -> V_8 . V_9 + V_83 ) ;
V_2 -> V_61 . V_80 = true ;
V_85 -> V_95 = ( V_85 -> V_95 + V_94 ) & ( V_98 - 1 ) ;
V_2 -> V_8 . V_15 . V_107 += V_94 ;
if ( F_38 ( V_85 ) < V_108 )
F_42 ( & V_2 -> V_8 ) ;
return 1 ;
}
static bool F_43 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_109 )
return false ;
if ( V_2 -> V_61 . V_80 ) {
V_2 -> V_78 |= V_82 ;
F_33 ( V_2 -> V_78 , V_2 -> V_8 . V_9 + V_83 ) ;
V_2 -> V_86 &= ~ V_87 ;
F_33 ( V_2 -> V_86 , V_2 -> V_8 . V_9 + V_88 ) ;
return true ;
}
if ( F_37 ( V_2 ) > 0 ) {
V_2 -> V_86 &= ~ V_87 ;
F_33 ( V_2 -> V_86 , V_2 -> V_8 . V_9 + V_88 ) ;
return true ;
}
return false ;
}
static inline void F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_61 . V_80 ) {
V_2 -> V_78 &= ~ V_82 ;
F_33 ( V_2 -> V_78 , V_2 -> V_8 . V_9 + V_83 ) ;
}
}
static inline bool F_45 ( struct V_1 * V_2 )
{
T_1 V_78 ;
if ( ! V_2 -> V_109 )
return false ;
if ( ! V_2 -> V_8 . V_110 ) {
bool V_111 = true ;
if ( ! V_2 -> V_61 . V_80 ) {
if ( F_37 ( V_2 ) > 0 ) {
V_2 -> V_86 &= ~ V_87 ;
V_111 = true ;
} else {
V_2 -> V_86 |= V_87 ;
V_111 = false ;
}
F_33 ( V_2 -> V_86 , V_2 -> V_8 . V_9 + V_88 ) ;
} else if ( ! ( V_2 -> V_78 & V_82 ) ) {
V_2 -> V_78 |= V_82 ;
F_33 ( V_2 -> V_78 ,
V_2 -> V_8 . V_9 + V_83 ) ;
}
return V_111 ;
}
V_78 = V_2 -> V_78 ;
V_2 -> V_78 &= ~ V_82 ;
F_33 ( V_2 -> V_78 , V_2 -> V_8 . V_9 + V_83 ) ;
if ( F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_112 ) {
return false ;
}
F_33 ( V_2 -> V_8 . V_110 , V_2 -> V_8 . V_9 + V_12 ) ;
V_2 -> V_8 . V_15 . V_107 ++ ;
V_2 -> V_8 . V_110 = 0 ;
V_2 -> V_78 = V_78 ;
F_33 ( V_78 , V_2 -> V_8 . V_9 + V_83 ) ;
return true ;
}
static void F_46 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
if ( ! V_2 -> V_109 )
return;
F_47 ( & V_2 -> V_8 . V_79 ) ;
F_48 ( V_2 -> V_61 . V_31 ) ;
F_49 ( & V_2 -> V_8 . V_79 ) ;
if ( V_2 -> V_61 . V_80 ) {
F_13 ( V_2 -> V_61 . V_31 -> V_40 -> V_41 , & V_2 -> V_61 . V_33 , 1 ,
V_81 ) ;
V_2 -> V_61 . V_80 = false ;
V_2 -> V_78 &= ~ V_82 ;
F_33 ( V_2 -> V_78 , V_2 -> V_8 . V_9 + V_83 ) ;
}
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_30 * V_114 = V_2 -> V_68 . V_31 ;
struct V_115 * V_68 = & V_2 -> V_68 ;
struct V_91 * V_92 ;
struct V_32 * V_116 ;
if ( ! V_114 )
return - V_117 ;
V_116 = V_2 -> V_68 . V_118 ?
& V_2 -> V_68 . V_119 : & V_2 -> V_68 . V_120 ;
V_92 = F_40 ( V_114 , & V_116 -> V_33 , 1 ,
V_66 ,
V_102 | V_103 ) ;
if ( ! V_92 ) {
V_2 -> V_68 . V_121 = false ;
F_48 ( V_114 ) ;
return - V_101 ;
}
V_92 -> V_104 = V_122 ;
V_92 -> V_105 = V_2 ;
V_68 -> V_123 = F_41 ( V_92 ) ;
F_51 ( V_114 ) ;
V_2 -> V_78 |= V_124 ;
F_33 ( V_2 -> V_78 , V_2 -> V_8 . V_9 + V_83 ) ;
V_2 -> V_68 . V_121 = true ;
V_2 -> V_86 &= ~ V_125 ;
F_33 ( V_2 -> V_86 , V_2 -> V_8 . V_9 + V_88 ) ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 ,
T_5 V_126 , bool V_118 ,
bool V_127 )
{
struct V_128 * V_129 = V_2 -> V_8 . V_84 -> V_8 . V_129 ;
struct V_32 * V_116 = V_118 ?
& V_2 -> V_68 . V_119 : & V_2 -> V_68 . V_120 ;
struct V_40 * V_41 = V_2 -> V_68 . V_31 -> V_40 -> V_41 ;
int V_130 = 0 ;
T_5 V_7 = 0 ;
if ( V_126 ) {
F_53 ( V_41 , & V_116 -> V_33 , 1 , V_131 ) ;
V_130 = F_54 ( V_2 -> V_8 . V_84 -> V_8 . V_129 ,
V_116 -> V_36 , V_126 ) ;
F_55 ( V_41 , & V_116 -> V_33 , 1 , V_131 ) ;
V_2 -> V_8 . V_15 . V_16 += V_130 ;
if ( V_130 < V_126 )
F_56 ( V_2 -> V_8 . V_41 ,
L_8 ) ;
}
if ( V_130 == V_126 && V_127 ) {
F_33 ( V_132 | V_133 | V_134 | V_135 ,
V_2 -> V_8 . V_9 + V_136 ) ;
V_7 = F_1 ( V_2 ) ;
}
F_47 ( & V_2 -> V_8 . V_79 ) ;
F_57 ( V_2 -> V_8 . V_41 ,
L_9 ,
V_130 , V_7 ) ;
F_58 ( V_129 ) ;
F_49 ( & V_2 -> V_8 . V_79 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_115 * V_68 = & V_2 -> V_68 ;
struct V_30 * V_114 = V_68 -> V_31 ;
struct V_32 * V_116 = V_68 -> V_118 ?
& V_68 -> V_119 : & V_68 -> V_120 ;
T_4 V_126 ;
struct V_137 V_84 ;
enum V_138 V_139 ;
if ( F_60 ( V_114 ) )
F_19 ( V_2 -> V_8 . V_41 , L_10 ) ;
V_139 = V_114 -> V_40 -> V_140 ( V_114 ,
V_68 -> V_123 , & V_84 ) ;
if ( V_139 != V_141 )
F_19 ( V_2 -> V_8 . V_41 , L_10 ) ;
V_2 -> V_78 &= ~ V_124 ;
F_33 ( V_2 -> V_78 , V_2 -> V_8 . V_9 + V_83 ) ;
V_2 -> V_68 . V_121 = false ;
V_126 = V_116 -> V_33 . V_100 - V_84 . V_142 ;
F_61 ( V_126 > V_37 ) ;
F_48 ( V_114 ) ;
F_52 ( V_2 , V_126 , V_68 -> V_118 , true ) ;
V_68 -> V_118 = ! V_68 -> V_118 ;
if ( F_50 ( V_2 ) ) {
F_39 ( V_2 -> V_8 . V_41 , L_11
L_12 ) ;
V_2 -> V_86 |= V_125 ;
F_33 ( V_2 -> V_86 , V_2 -> V_8 . V_9 + V_88 ) ;
}
}
static void V_122 ( void * V_75 )
{
struct V_1 * V_2 = V_75 ;
struct V_115 * V_68 = & V_2 -> V_68 ;
struct V_30 * V_114 = V_68 -> V_31 ;
bool V_143 = V_68 -> V_118 ;
struct V_32 * V_116 = V_68 -> V_118 ?
& V_68 -> V_119 : & V_68 -> V_120 ;
T_4 V_126 ;
struct V_137 V_84 ;
int V_111 ;
F_62 ( & V_2 -> V_8 . V_79 ) ;
V_114 -> V_40 -> V_140 ( V_114 , V_68 -> V_123 , & V_84 ) ;
V_126 = V_116 -> V_33 . V_100 - V_84 . V_142 ;
F_61 ( V_126 > V_37 ) ;
F_48 ( V_114 ) ;
V_2 -> V_68 . V_121 = false ;
V_68 -> V_118 = ! V_143 ;
V_111 = F_50 ( V_2 ) ;
F_52 ( V_2 , V_126 , V_143 , false ) ;
F_63 ( & V_2 -> V_8 . V_79 ) ;
if ( V_111 ) {
F_39 ( V_2 -> V_8 . V_41 , L_11
L_12 ) ;
V_2 -> V_86 |= V_125 ;
F_33 ( V_2 -> V_86 , V_2 -> V_8 . V_9 + V_88 ) ;
}
}
static inline void F_64 ( struct V_1 * V_2 )
{
V_2 -> V_78 &= ~ V_124 ;
F_33 ( V_2 -> V_78 , V_2 -> V_8 . V_9 + V_83 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
int V_111 ;
if ( ! V_2 -> V_61 . V_31 )
return;
V_2 -> V_61 . V_36 = F_8 ( V_37 , V_38 ) ;
if ( ! V_2 -> V_61 . V_36 ) {
F_19 ( V_2 -> V_8 . V_41 , L_13 ) ;
V_2 -> V_8 . V_55 = V_2 -> V_55 ;
return;
}
F_9 ( & V_2 -> V_61 . V_33 , V_2 -> V_61 . V_36 , V_37 ) ;
V_2 -> V_8 . V_55 = V_37 ;
V_2 -> V_109 = true ;
if ( ! V_2 -> V_68 . V_31 )
goto V_144;
V_111 = F_7 ( V_2 -> V_68 . V_31 , & V_2 -> V_68 . V_120 ,
V_131 ) ;
if ( V_111 ) {
F_19 ( V_2 -> V_8 . V_41 , L_14 ,
L_15 , V_111 ) ;
goto V_144;
}
V_111 = F_7 ( V_2 -> V_68 . V_31 , & V_2 -> V_68 . V_119 ,
V_131 ) ;
if ( V_111 ) {
F_19 ( V_2 -> V_8 . V_41 , L_14 ,
L_16 , V_111 ) ;
F_12 ( V_2 -> V_68 . V_31 , & V_2 -> V_68 . V_120 ,
V_131 ) ;
goto V_144;
}
V_2 -> V_145 = true ;
V_144:
V_2 -> V_78 |= V_146 ;
F_33 ( V_2 -> V_78 , V_2 -> V_8 . V_9 + V_83 ) ;
if ( V_2 -> V_147 -> V_148 )
F_33 ( V_149 | V_150 ,
V_2 -> V_8 . V_9 + V_151 ) ;
if ( V_2 -> V_145 ) {
if ( F_50 ( V_2 ) )
F_39 ( V_2 -> V_8 . V_41 , L_17
L_18 ) ;
}
}
static void F_66 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_109 || V_2 -> V_145 ) )
return;
while ( F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_152 )
F_67 () ;
F_62 ( & V_2 -> V_8 . V_79 ) ;
V_2 -> V_78 &= ~ ( V_146 | V_124 | V_82 ) ;
F_33 ( V_2 -> V_78 , V_2 -> V_8 . V_9 + V_83 ) ;
F_63 ( & V_2 -> V_8 . V_79 ) ;
if ( V_2 -> V_109 ) {
F_48 ( V_2 -> V_61 . V_31 ) ;
if ( V_2 -> V_61 . V_80 ) {
F_13 ( V_2 -> V_61 . V_31 -> V_40 -> V_41 , & V_2 -> V_61 . V_33 , 1 ,
V_81 ) ;
V_2 -> V_61 . V_80 = false ;
}
F_11 ( V_2 -> V_61 . V_36 ) ;
V_2 -> V_109 = false ;
}
if ( V_2 -> V_145 ) {
F_48 ( V_2 -> V_68 . V_31 ) ;
F_12 ( V_2 -> V_68 . V_31 , & V_2 -> V_68 . V_120 , V_131 ) ;
F_12 ( V_2 -> V_68 . V_31 , & V_2 -> V_68 . V_119 , V_131 ) ;
V_2 -> V_145 = false ;
}
}
static inline bool F_68 ( struct V_1 * V_2 )
{
return V_2 -> V_145 ;
}
static inline bool F_69 ( struct V_1 * V_2 )
{
return V_2 -> V_145 && V_2 -> V_68 . V_121 ;
}
static inline void F_26 ( struct V_1 * V_2 )
{
}
static inline void F_29 ( struct V_1 * V_2 )
{
}
static inline void F_65 ( struct V_1 * V_2 )
{
}
static inline void F_66 ( struct V_1 * V_2 )
{
}
static inline bool F_43 ( struct V_1 * V_2 )
{
return false ;
}
static inline void F_44 ( struct V_1 * V_2 )
{
}
static inline bool F_45 ( struct V_1 * V_2 )
{
return false ;
}
static inline void F_59 ( struct V_1 * V_2 )
{
}
static inline void F_64 ( struct V_1 * V_2 )
{
}
static inline int F_50 ( struct V_1 * V_2 )
{
return - V_117 ;
}
static inline bool F_68 ( struct V_1 * V_2 )
{
return false ;
}
static inline bool F_69 ( struct V_1 * V_2 )
{
return false ;
}
static void F_70 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
V_2 -> V_86 &= ~ V_87 ;
F_33 ( V_2 -> V_86 , V_2 -> V_8 . V_9 + V_88 ) ;
F_44 ( V_2 ) ;
}
static void F_71 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
if ( ! F_45 ( V_2 ) ) {
V_2 -> V_86 |= V_87 ;
F_33 ( V_2 -> V_86 , V_2 -> V_8 . V_9 + V_88 ) ;
}
}
static void F_72 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
V_2 -> V_86 &= ~ ( V_125 | V_153 | V_154 |
V_155 | V_156 | V_157 ) ;
F_33 ( V_2 -> V_86 , V_2 -> V_8 . V_9 + V_88 ) ;
F_64 ( V_2 ) ;
}
static void F_73 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
V_2 -> V_86 |= V_158 | V_159 | V_160 | V_161 ;
F_33 ( V_2 -> V_86 , V_2 -> V_8 . V_9 + V_88 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_128 * V_129 = V_2 -> V_8 . V_84 -> V_8 . V_129 ;
F_1 ( V_2 ) ;
F_47 ( & V_2 -> V_8 . V_79 ) ;
F_58 ( V_129 ) ;
if ( F_68 ( V_2 ) ) {
if ( F_50 ( V_2 ) ) {
F_39 ( V_2 -> V_8 . V_41 , L_19
L_20 ) ;
V_2 -> V_86 |= V_125 ;
} else
V_2 -> V_86 &= ~ V_125 ;
F_33 ( V_2 -> V_86 , V_2 -> V_8 . V_9 + V_88 ) ;
}
F_49 ( & V_2 -> V_8 . V_79 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_93 * V_85 = & V_2 -> V_8 . V_84 -> V_85 ;
int V_94 ;
if ( V_2 -> V_8 . V_110 ) {
F_33 ( V_2 -> V_8 . V_110 , V_2 -> V_8 . V_9 + V_12 ) ;
V_2 -> V_8 . V_15 . V_107 ++ ;
V_2 -> V_8 . V_110 = 0 ;
return;
}
if ( F_35 ( V_85 ) || F_34 ( & V_2 -> V_8 ) ) {
F_70 ( & V_2 -> V_8 ) ;
return;
}
if ( F_43 ( V_2 ) )
return;
V_94 = V_2 -> V_55 >> 1 ;
do {
F_33 ( V_85 -> V_36 [ V_85 -> V_95 ] , V_2 -> V_8 . V_9 + V_12 ) ;
V_85 -> V_95 = ( V_85 -> V_95 + 1 ) & ( V_98 - 1 ) ;
V_2 -> V_8 . V_15 . V_107 ++ ;
if ( F_35 ( V_85 ) )
break;
} while ( -- V_94 > 0 );
if ( F_38 ( V_85 ) < V_108 )
F_42 ( & V_2 -> V_8 ) ;
if ( F_35 ( V_85 ) )
F_70 ( & V_2 -> V_8 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_162 ;
V_3 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_163 ;
V_162 = V_3 ^ V_2 -> V_164 ;
V_2 -> V_164 = V_3 ;
if ( ! V_162 )
return;
if ( V_162 & V_165 )
F_77 ( & V_2 -> V_8 , V_3 & V_165 ) ;
if ( V_162 & V_166 )
V_2 -> V_8 . V_15 . V_167 ++ ;
if ( V_162 & V_168 )
F_78 ( & V_2 -> V_8 , V_3 & V_168 ) ;
F_79 ( & V_2 -> V_8 . V_84 -> V_8 . V_169 ) ;
}
static T_6 F_80 ( int V_170 , void * V_171 )
{
struct V_1 * V_2 = V_171 ;
unsigned long V_77 ;
unsigned int V_3 , V_172 = V_173 ;
int V_174 = 0 ;
unsigned int V_175 ;
F_32 ( & V_2 -> V_8 . V_79 , V_77 ) ;
V_3 = F_2 ( V_2 -> V_8 . V_9 + V_176 ) ;
if ( V_3 ) {
do {
if ( V_2 -> V_147 -> V_177 ) {
F_33 ( 0x00 , V_2 -> V_8 . V_9 + V_136 ) ;
V_175 = F_2 ( V_2 -> V_8 . V_9 + V_136 ) ;
V_175 = F_2 ( V_2 -> V_8 . V_9 + V_136 ) ;
}
F_33 ( V_3 & ~ ( V_178 | V_179 |
V_180 ) ,
V_2 -> V_8 . V_9 + V_136 ) ;
if ( V_3 & ( V_179 | V_180 ) ) {
if ( F_69 ( V_2 ) )
F_59 ( V_2 ) ;
else
F_74 ( V_2 ) ;
}
if ( V_3 & ( V_181 | V_182 |
V_183 | V_184 ) )
F_76 ( V_2 ) ;
if ( V_3 & V_178 )
F_75 ( V_2 ) ;
if ( V_172 -- == 0 )
break;
V_3 = F_2 ( V_2 -> V_8 . V_9 + V_176 ) ;
} while ( V_3 != 0 );
V_174 = 1 ;
}
F_36 ( & V_2 -> V_8 . V_79 , V_77 ) ;
return F_81 ( V_174 ) ;
}
static unsigned int F_82 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_3 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) ;
return V_3 & ( V_152 | V_112 ) ? 0 : V_185 ;
}
static unsigned int F_83 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_186 = 0 ;
unsigned int V_3 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) ;
#define F_84 ( T_7 , T_8 ) \
if (status & uartbit) \
result |= tiocmbit
F_84 ( V_165 , V_187 ) ;
F_84 ( V_166 , V_188 ) ;
F_84 ( V_168 , V_189 ) ;
F_84 ( V_190 , V_191 ) ;
#undef F_84
return V_186 ;
}
static void F_85 ( struct V_113 * V_8 , unsigned int V_192 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_193 ;
V_193 = F_2 ( V_2 -> V_8 . V_9 + V_194 ) ;
#define F_84 ( T_8 , T_7 ) \
if (mctrl & tiocmbit) \
cr |= uartbit; \
else \
cr &= ~uartbit
F_84 ( V_195 , V_196 ) ;
F_84 ( V_197 , V_198 ) ;
F_84 ( V_199 , V_200 ) ;
F_84 ( V_201 , V_202 ) ;
F_84 ( V_203 , V_204 ) ;
if ( V_2 -> V_205 ) {
F_84 ( V_195 , V_206 ) ;
}
#undef F_84
F_33 ( V_193 , V_2 -> V_8 . V_9 + V_194 ) ;
}
static void F_86 ( struct V_113 * V_8 , int V_207 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_77 ;
unsigned int V_208 ;
F_32 ( & V_2 -> V_8 . V_79 , V_77 ) ;
V_208 = F_2 ( V_2 -> V_8 . V_9 + V_2 -> V_209 ) ;
if ( V_207 == - 1 )
V_208 |= V_210 ;
else
V_208 &= ~ V_210 ;
F_33 ( V_208 , V_2 -> V_8 . V_9 + V_2 -> V_209 ) ;
F_36 ( & V_2 -> V_8 . V_79 , V_77 ) ;
}
static int F_87 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_3 ;
V_3 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) ;
if ( V_3 & V_11 )
return V_211 ;
return F_2 ( V_2 -> V_8 . V_9 + V_12 ) ;
}
static void F_88 ( struct V_113 * V_8 ,
unsigned char V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
while ( F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_112 )
F_67 () ;
F_33 ( V_4 , V_2 -> V_8 . V_9 + V_12 ) ;
}
static int F_89 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_193 ;
int V_212 ;
if ( ! F_90 ( V_2 -> V_213 ) ) {
V_212 = F_91 ( V_2 -> V_214 , V_2 -> V_213 ) ;
if ( V_212 )
F_19 ( V_8 -> V_41 ,
L_21 ) ;
}
V_212 = F_92 ( V_2 -> V_215 ) ;
if ( V_212 )
goto V_216;
V_212 = F_93 ( V_2 -> V_215 ) ;
if ( V_212 )
goto V_217;
V_2 -> V_8 . V_218 = F_94 ( V_2 -> V_215 ) ;
F_33 ( V_132 | V_133 | V_134 | V_135 |
V_179 | V_180 , V_2 -> V_8 . V_9 + V_136 ) ;
V_212 = F_95 ( V_2 -> V_8 . V_170 , F_80 , 0 , L_22 , V_2 ) ;
if ( V_212 )
goto V_219;
F_33 ( V_2 -> V_147 -> V_220 , V_2 -> V_8 . V_9 + V_221 ) ;
V_193 = V_222 | V_223 | V_204 ;
F_33 ( V_193 , V_2 -> V_8 . V_9 + V_194 ) ;
F_33 ( 0 , V_2 -> V_8 . V_9 + V_224 ) ;
F_33 ( 1 , V_2 -> V_8 . V_9 + V_225 ) ;
F_33 ( 0 , V_2 -> V_8 . V_9 + V_2 -> V_226 ) ;
if ( V_2 -> V_209 != V_2 -> V_226 ) {
int V_227 ;
for ( V_227 = 0 ; V_227 < 10 ; ++ V_227 )
F_33 ( 0xff , V_2 -> V_8 . V_9 + V_176 ) ;
F_33 ( 0 , V_2 -> V_8 . V_9 + V_2 -> V_209 ) ;
}
F_33 ( 0 , V_2 -> V_8 . V_9 + V_12 ) ;
while ( F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_152 )
F_67 () ;
V_193 = V_2 -> V_228 & ( V_196 | V_198 ) ;
V_193 |= V_222 | V_229 | V_223 ;
F_33 ( V_193 , V_2 -> V_8 . V_9 + V_194 ) ;
V_2 -> V_164 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_163 ;
F_65 ( V_2 ) ;
F_62 ( & V_2 -> V_8 . V_79 ) ;
F_33 ( V_179 | V_180 ,
V_2 -> V_8 . V_9 + V_136 ) ;
V_2 -> V_86 = V_153 ;
if ( ! F_69 ( V_2 ) )
V_2 -> V_86 |= V_125 ;
F_33 ( V_2 -> V_86 , V_2 -> V_8 . V_9 + V_88 ) ;
F_63 ( & V_2 -> V_8 . V_79 ) ;
if ( V_2 -> V_8 . V_41 -> V_45 ) {
struct V_43 * V_44 ;
V_44 = V_2 -> V_8 . V_41 -> V_45 ;
if ( V_44 -> V_230 )
V_44 -> V_230 () ;
}
return 0 ;
V_219:
F_96 ( V_2 -> V_215 ) ;
V_217:
F_97 ( V_2 -> V_215 ) ;
V_216:
return V_212 ;
}
static void F_98 ( struct V_1 * V_2 ,
unsigned int V_231 )
{
unsigned long V_232 ;
V_232 = F_2 ( V_2 -> V_8 . V_9 + V_231 ) ;
V_232 &= ~ ( V_210 | V_233 ) ;
F_33 ( V_232 , V_2 -> V_8 . V_9 + V_231 ) ;
}
static void F_99 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_193 ;
int V_212 ;
F_62 ( & V_2 -> V_8 . V_79 ) ;
V_2 -> V_86 = 0 ;
F_33 ( V_2 -> V_86 , V_2 -> V_8 . V_9 + V_88 ) ;
F_33 ( 0xffff , V_2 -> V_8 . V_9 + V_136 ) ;
F_63 ( & V_2 -> V_8 . V_79 ) ;
F_66 ( V_2 ) ;
F_100 ( V_2 -> V_8 . V_170 , V_2 ) ;
V_2 -> V_205 = false ;
V_193 = F_2 ( V_2 -> V_8 . V_9 + V_194 ) ;
V_2 -> V_228 = V_193 ;
V_193 &= V_196 | V_198 ;
V_193 |= V_222 | V_223 ;
F_33 ( V_193 , V_2 -> V_8 . V_9 + V_194 ) ;
F_98 ( V_2 , V_2 -> V_226 ) ;
if ( V_2 -> V_226 != V_2 -> V_209 )
F_98 ( V_2 , V_2 -> V_209 ) ;
F_96 ( V_2 -> V_215 ) ;
F_97 ( V_2 -> V_215 ) ;
if ( ! F_90 ( V_2 -> V_234 ) ) {
V_212 = F_91 ( V_2 -> V_214 , V_2 -> V_234 ) ;
if ( V_212 )
F_19 ( V_8 -> V_41 ,
L_23 ) ;
}
if ( V_2 -> V_8 . V_41 -> V_45 ) {
struct V_43 * V_44 ;
V_44 = V_2 -> V_8 . V_41 -> V_45 ;
if ( V_44 -> exit )
V_44 -> exit () ;
}
}
static void
F_101 ( struct V_113 * V_8 , struct V_235 * V_236 ,
struct V_235 * V_237 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_208 , V_228 ;
unsigned long V_77 ;
unsigned int V_238 , V_239 , V_240 ;
if ( V_2 -> V_147 -> V_241 )
V_240 = 8 ;
else
V_240 = 16 ;
V_238 = F_102 ( V_8 , V_236 , V_237 , 0 ,
V_8 -> V_218 / V_240 ) ;
if ( V_238 > V_8 -> V_218 / 16 )
V_239 = F_103 ( V_8 -> V_218 * 8 , V_238 ) ;
else
V_239 = F_103 ( V_8 -> V_218 * 4 , V_238 ) ;
switch ( V_236 -> V_242 & V_243 ) {
case V_244 :
V_208 = V_245 ;
break;
case V_246 :
V_208 = V_247 ;
break;
case V_248 :
V_208 = V_249 ;
break;
default:
V_208 = V_250 ;
break;
}
if ( V_236 -> V_242 & V_251 )
V_208 |= V_252 ;
if ( V_236 -> V_242 & V_253 ) {
V_208 |= V_254 ;
if ( ! ( V_236 -> V_242 & V_255 ) )
V_208 |= V_256 ;
}
if ( V_2 -> V_55 > 1 )
V_208 |= V_233 ;
F_32 ( & V_8 -> V_79 , V_77 ) ;
F_104 ( V_8 , V_236 -> V_242 , V_238 ) ;
V_8 -> V_26 = V_24 | 255 ;
if ( V_236 -> V_257 & V_258 )
V_8 -> V_26 |= V_19 | V_20 ;
if ( V_236 -> V_257 & ( V_259 | V_260 ) )
V_8 -> V_26 |= V_18 ;
V_8 -> V_261 = 0 ;
if ( V_236 -> V_257 & V_262 )
V_8 -> V_261 |= V_19 | V_20 ;
if ( V_236 -> V_257 & V_263 ) {
V_8 -> V_261 |= V_18 ;
if ( V_236 -> V_257 & V_262 )
V_8 -> V_261 |= V_24 ;
}
if ( ( V_236 -> V_242 & V_264 ) == 0 )
V_8 -> V_261 |= V_13 ;
if ( F_105 ( V_8 , V_236 -> V_242 ) )
F_73 ( V_8 ) ;
V_228 = F_2 ( V_8 -> V_9 + V_194 ) ;
F_33 ( 0 , V_8 -> V_9 + V_194 ) ;
if ( V_236 -> V_242 & V_265 ) {
if ( V_228 & V_196 )
V_228 |= V_206 ;
V_228 |= V_266 ;
V_2 -> V_205 = true ;
} else {
V_228 &= ~ ( V_266 | V_206 ) ;
V_2 -> V_205 = false ;
}
if ( V_2 -> V_147 -> V_241 ) {
if ( V_238 > V_8 -> V_218 / 16 )
V_228 |= V_267 ;
else
V_228 &= ~ V_267 ;
}
F_33 ( V_239 & 0x3f , V_8 -> V_9 + V_224 ) ;
F_33 ( V_239 >> 6 , V_8 -> V_9 + V_225 ) ;
F_33 ( V_208 , V_8 -> V_9 + V_2 -> V_226 ) ;
if ( V_2 -> V_226 != V_2 -> V_209 ) {
int V_227 ;
for ( V_227 = 0 ; V_227 < 10 ; ++ V_227 )
F_33 ( 0xff , V_2 -> V_8 . V_9 + V_176 ) ;
F_33 ( V_208 , V_8 -> V_9 + V_2 -> V_209 ) ;
}
F_33 ( V_228 , V_8 -> V_9 + V_194 ) ;
F_36 ( & V_8 -> V_79 , V_77 ) ;
}
static const char * F_106 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
return V_2 -> V_8 . type == V_268 ? V_2 -> type : NULL ;
}
static void F_107 ( struct V_113 * V_8 )
{
F_108 ( V_8 -> V_49 , V_269 ) ;
}
static int F_109 ( struct V_113 * V_8 )
{
return F_110 ( V_8 -> V_49 , V_269 , L_22 )
!= NULL ? 0 : - V_101 ;
}
static void F_111 ( struct V_113 * V_8 , int V_77 )
{
if ( V_77 & V_270 ) {
V_8 -> type = V_268 ;
F_109 ( V_8 ) ;
}
}
static int F_112 ( struct V_113 * V_8 , struct V_271 * V_272 )
{
int V_111 = 0 ;
if ( V_272 -> type != V_273 && V_272 -> type != V_268 )
V_111 = - V_42 ;
if ( V_272 -> V_170 < 0 || V_272 -> V_170 >= V_274 )
V_111 = - V_42 ;
if ( V_272 -> V_275 < 9600 )
V_111 = - V_42 ;
return V_111 ;
}
static void F_113 ( struct V_113 * V_8 , int V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
while ( F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_112 )
F_67 () ;
F_33 ( V_4 , V_2 -> V_8 . V_9 + V_12 ) ;
}
static void
F_114 ( struct V_276 * V_277 , const char * V_278 , unsigned int V_94 )
{
struct V_1 * V_2 = V_279 [ V_277 -> V_280 ] ;
unsigned int V_3 , V_228 , V_281 ;
unsigned long V_77 ;
int V_282 = 1 ;
F_93 ( V_2 -> V_215 ) ;
F_115 ( V_77 ) ;
if ( V_2 -> V_8 . V_283 )
V_282 = 0 ;
else if ( V_284 )
V_282 = F_116 ( & V_2 -> V_8 . V_79 ) ;
else
F_49 ( & V_2 -> V_8 . V_79 ) ;
V_228 = F_2 ( V_2 -> V_8 . V_9 + V_194 ) ;
V_281 = V_228 & ~ V_266 ;
V_281 |= V_222 | V_223 ;
F_33 ( V_281 , V_2 -> V_8 . V_9 + V_194 ) ;
F_117 ( & V_2 -> V_8 , V_278 , V_94 , F_113 ) ;
do {
V_3 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) ;
} while ( V_3 & V_152 );
F_33 ( V_228 , V_2 -> V_8 . V_9 + V_194 ) ;
if ( V_282 )
F_47 ( & V_2 -> V_8 . V_79 ) ;
F_118 ( V_77 ) ;
F_96 ( V_2 -> V_215 ) ;
}
static void T_3
F_119 ( struct V_1 * V_2 , int * V_238 ,
int * V_22 , int * V_285 )
{
if ( F_2 ( V_2 -> V_8 . V_9 + V_194 ) & V_222 ) {
unsigned int V_208 , V_286 , V_287 ;
V_208 = F_2 ( V_2 -> V_8 . V_9 + V_2 -> V_209 ) ;
* V_22 = 'n' ;
if ( V_208 & V_254 ) {
if ( V_208 & V_256 )
* V_22 = 'e' ;
else
* V_22 = 'o' ;
}
if ( ( V_208 & 0x60 ) == V_249 )
* V_285 = 7 ;
else
* V_285 = 8 ;
V_286 = F_2 ( V_2 -> V_8 . V_9 + V_225 ) ;
V_287 = F_2 ( V_2 -> V_8 . V_9 + V_224 ) ;
* V_238 = V_2 -> V_8 . V_218 * 4 / ( 64 * V_286 + V_287 ) ;
if ( V_2 -> V_147 -> V_241 ) {
if ( F_2 ( V_2 -> V_8 . V_9 + V_194 )
& V_267 )
* V_238 *= 2 ;
}
}
}
static int T_3 F_120 ( struct V_276 * V_277 , char * V_288 )
{
struct V_1 * V_2 ;
int V_238 = 38400 ;
int V_285 = 8 ;
int V_22 = 'n' ;
int V_289 = 'n' ;
int V_111 ;
if ( V_277 -> V_280 >= V_290 )
V_277 -> V_280 = 0 ;
V_2 = V_279 [ V_277 -> V_280 ] ;
if ( ! V_2 )
return - V_291 ;
if ( ! F_90 ( V_2 -> V_213 ) ) {
V_111 = F_91 ( V_2 -> V_214 , V_2 -> V_213 ) ;
if ( V_111 )
F_19 ( V_2 -> V_8 . V_41 ,
L_21 ) ;
}
V_111 = F_92 ( V_2 -> V_215 ) ;
if ( V_111 )
return V_111 ;
if ( V_2 -> V_8 . V_41 -> V_45 ) {
struct V_43 * V_44 ;
V_44 = V_2 -> V_8 . V_41 -> V_45 ;
if ( V_44 -> V_230 )
V_44 -> V_230 () ;
}
V_2 -> V_8 . V_218 = F_94 ( V_2 -> V_215 ) ;
if ( V_288 )
F_121 ( V_288 , & V_238 , & V_22 , & V_285 , & V_289 ) ;
else
F_119 ( V_2 , & V_238 , & V_22 , & V_285 ) ;
return F_122 ( & V_2 -> V_8 , V_277 , V_238 , V_22 , V_285 , V_289 ) ;
}
static int F_123 ( struct V_292 * V_41 , const struct V_293 * V_294 )
{
struct V_1 * V_2 ;
struct V_295 * V_147 = V_294 -> V_75 ;
void T_9 * V_296 ;
int V_227 , V_111 ;
for ( V_227 = 0 ; V_227 < F_124 ( V_279 ) ; V_227 ++ )
if ( V_279 [ V_227 ] == NULL )
break;
if ( V_227 == F_124 ( V_279 ) ) {
V_111 = - V_101 ;
goto V_216;
}
V_2 = F_27 ( sizeof( struct V_1 ) , V_38 ) ;
if ( V_2 == NULL ) {
V_111 = - V_39 ;
goto V_216;
}
V_296 = F_125 ( V_41 -> V_297 . V_298 , F_126 ( & V_41 -> V_297 ) ) ;
if ( ! V_296 ) {
V_111 = - V_39 ;
goto free;
}
V_2 -> V_214 = F_127 ( & V_41 -> V_41 ) ;
if ( F_90 ( V_2 -> V_214 ) ) {
V_111 = F_128 ( V_2 -> V_214 ) ;
goto V_299;
}
V_2 -> V_213 = F_129 ( V_2 -> V_214 ,
V_300 ) ;
if ( F_90 ( V_2 -> V_213 ) )
F_19 ( & V_41 -> V_41 , L_24 ) ;
V_2 -> V_234 = F_129 ( V_2 -> V_214 ,
V_301 ) ;
if ( F_90 ( V_2 -> V_234 ) )
F_39 ( & V_41 -> V_41 , L_25 ) ;
V_2 -> V_215 = F_130 ( & V_41 -> V_41 , NULL ) ;
if ( F_90 ( V_2 -> V_215 ) ) {
V_111 = F_128 ( V_2 -> V_215 ) ;
goto V_299;
}
V_2 -> V_147 = V_147 ;
V_2 -> V_226 = V_147 -> V_226 ;
V_2 -> V_209 = V_147 -> V_209 ;
V_2 -> V_228 = 0 ;
V_2 -> V_55 = V_147 -> V_55 ;
V_2 -> V_302 = V_147 -> V_302 ;
V_2 -> V_8 . V_41 = & V_41 -> V_41 ;
V_2 -> V_8 . V_49 = V_41 -> V_297 . V_298 ;
V_2 -> V_8 . V_9 = V_296 ;
V_2 -> V_8 . V_303 = V_304 ;
V_2 -> V_8 . V_170 = V_41 -> V_170 [ 0 ] ;
V_2 -> V_8 . V_55 = V_2 -> V_55 ;
V_2 -> V_8 . V_305 = & V_306 ;
V_2 -> V_8 . V_77 = V_307 ;
V_2 -> V_8 . line = V_227 ;
F_26 ( V_2 ) ;
F_33 ( 0 , V_2 -> V_8 . V_9 + V_88 ) ;
F_33 ( 0xffff , V_2 -> V_8 . V_9 + V_136 ) ;
snprintf ( V_2 -> type , sizeof( V_2 -> type ) , L_26 , F_131 ( V_41 ) ) ;
V_279 [ V_227 ] = V_2 ;
F_132 ( V_41 , V_2 ) ;
V_111 = F_133 ( & V_308 , & V_2 -> V_8 ) ;
if ( V_111 ) {
F_132 ( V_41 , NULL ) ;
V_279 [ V_227 ] = NULL ;
F_29 ( V_2 ) ;
F_134 ( V_2 -> V_215 ) ;
V_299:
F_135 ( V_296 ) ;
free:
F_11 ( V_2 ) ;
}
V_216:
return V_111 ;
}
static int F_136 ( struct V_292 * V_41 )
{
struct V_1 * V_2 = F_137 ( V_41 ) ;
int V_227 ;
F_132 ( V_41 , NULL ) ;
F_138 ( & V_308 , & V_2 -> V_8 ) ;
for ( V_227 = 0 ; V_227 < F_124 ( V_279 ) ; V_227 ++ )
if ( V_279 [ V_227 ] == V_2 )
V_279 [ V_227 ] = NULL ;
F_29 ( V_2 ) ;
F_135 ( V_2 -> V_8 . V_9 ) ;
F_134 ( V_2 -> V_215 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_139 ( struct V_292 * V_41 , T_10 V_84 )
{
struct V_1 * V_2 = F_137 ( V_41 ) ;
if ( ! V_2 )
return - V_42 ;
return F_140 ( & V_308 , & V_2 -> V_8 ) ;
}
static int F_141 ( struct V_292 * V_41 )
{
struct V_1 * V_2 = F_137 ( V_41 ) ;
if ( ! V_2 )
return - V_42 ;
return F_142 ( & V_308 , & V_2 -> V_8 ) ;
}
static int T_3 F_143 ( void )
{
int V_111 ;
F_144 ( V_309 L_27 ) ;
V_111 = F_145 ( & V_308 ) ;
if ( V_111 == 0 ) {
V_111 = F_146 ( & V_310 ) ;
if ( V_111 )
F_147 ( & V_308 ) ;
}
return V_111 ;
}
static void T_11 F_148 ( void )
{
F_149 ( & V_310 ) ;
F_147 ( & V_308 ) ;
}
