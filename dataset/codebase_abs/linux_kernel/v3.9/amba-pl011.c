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
struct V_128 * V_8 = & V_2 -> V_8 . V_84 -> V_8 ;
struct V_32 * V_116 = V_118 ?
& V_2 -> V_68 . V_119 : & V_2 -> V_68 . V_120 ;
struct V_40 * V_41 = V_2 -> V_68 . V_31 -> V_40 -> V_41 ;
int V_129 = 0 ;
T_5 V_7 = 0 ;
if ( V_126 ) {
F_53 ( V_41 , & V_116 -> V_33 , 1 , V_130 ) ;
V_129 = F_54 ( V_8 , V_116 -> V_36 , V_126 ) ;
F_55 ( V_41 , & V_116 -> V_33 , 1 , V_130 ) ;
V_2 -> V_8 . V_15 . V_16 += V_129 ;
if ( V_129 < V_126 )
F_56 ( V_2 -> V_8 . V_41 ,
L_8 ) ;
}
if ( V_129 == V_126 && V_127 ) {
F_33 ( V_131 | V_132 | V_133 | V_134 ,
V_2 -> V_8 . V_9 + V_135 ) ;
V_7 = F_1 ( V_2 ) ;
}
F_47 ( & V_2 -> V_8 . V_79 ) ;
F_57 ( V_2 -> V_8 . V_41 ,
L_9 ,
V_129 , V_7 ) ;
F_58 ( V_8 ) ;
F_49 ( & V_2 -> V_8 . V_79 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_115 * V_68 = & V_2 -> V_68 ;
struct V_30 * V_114 = V_68 -> V_31 ;
struct V_32 * V_116 = V_68 -> V_118 ?
& V_68 -> V_119 : & V_68 -> V_120 ;
T_4 V_126 ;
struct V_136 V_84 ;
enum V_137 V_138 ;
if ( F_60 ( V_114 ) )
F_19 ( V_2 -> V_8 . V_41 , L_10 ) ;
V_138 = V_114 -> V_40 -> V_139 ( V_114 ,
V_68 -> V_123 , & V_84 ) ;
if ( V_138 != V_140 )
F_19 ( V_2 -> V_8 . V_41 , L_10 ) ;
V_2 -> V_78 &= ~ V_124 ;
F_33 ( V_2 -> V_78 , V_2 -> V_8 . V_9 + V_83 ) ;
V_2 -> V_68 . V_121 = false ;
V_126 = V_116 -> V_33 . V_100 - V_84 . V_141 ;
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
bool V_142 = V_68 -> V_118 ;
struct V_32 * V_116 = V_68 -> V_118 ?
& V_68 -> V_119 : & V_68 -> V_120 ;
T_4 V_126 ;
struct V_136 V_84 ;
int V_111 ;
F_62 ( & V_2 -> V_8 . V_79 ) ;
V_114 -> V_40 -> V_139 ( V_114 , V_68 -> V_123 , & V_84 ) ;
V_126 = V_116 -> V_33 . V_100 - V_84 . V_141 ;
F_61 ( V_126 > V_37 ) ;
F_48 ( V_114 ) ;
V_2 -> V_68 . V_121 = false ;
V_68 -> V_118 = ! V_142 ;
V_111 = F_50 ( V_2 ) ;
F_52 ( V_2 , V_126 , V_142 , false ) ;
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
goto V_143;
V_111 = F_7 ( V_2 -> V_68 . V_31 , & V_2 -> V_68 . V_120 ,
V_130 ) ;
if ( V_111 ) {
F_19 ( V_2 -> V_8 . V_41 , L_14 ,
L_15 , V_111 ) ;
goto V_143;
}
V_111 = F_7 ( V_2 -> V_68 . V_31 , & V_2 -> V_68 . V_119 ,
V_130 ) ;
if ( V_111 ) {
F_19 ( V_2 -> V_8 . V_41 , L_14 ,
L_16 , V_111 ) ;
F_12 ( V_2 -> V_68 . V_31 , & V_2 -> V_68 . V_120 ,
V_130 ) ;
goto V_143;
}
V_2 -> V_144 = true ;
V_143:
V_2 -> V_78 |= V_145 ;
F_33 ( V_2 -> V_78 , V_2 -> V_8 . V_9 + V_83 ) ;
if ( V_2 -> V_146 -> V_147 )
F_33 ( V_148 | V_149 ,
V_2 -> V_8 . V_9 + V_150 ) ;
if ( V_2 -> V_144 ) {
if ( F_50 ( V_2 ) )
F_39 ( V_2 -> V_8 . V_41 , L_17
L_18 ) ;
}
}
static void F_66 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_109 || V_2 -> V_144 ) )
return;
while ( F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_151 )
F_67 () ;
F_62 ( & V_2 -> V_8 . V_79 ) ;
V_2 -> V_78 &= ~ ( V_145 | V_124 | V_82 ) ;
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
if ( V_2 -> V_144 ) {
F_48 ( V_2 -> V_68 . V_31 ) ;
F_12 ( V_2 -> V_68 . V_31 , & V_2 -> V_68 . V_120 , V_130 ) ;
F_12 ( V_2 -> V_68 . V_31 , & V_2 -> V_68 . V_119 , V_130 ) ;
V_2 -> V_144 = false ;
}
}
static inline bool F_68 ( struct V_1 * V_2 )
{
return V_2 -> V_144 ;
}
static inline bool F_69 ( struct V_1 * V_2 )
{
return V_2 -> V_144 && V_2 -> V_68 . V_121 ;
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
V_2 -> V_86 &= ~ ( V_125 | V_152 | V_153 |
V_154 | V_155 | V_156 ) ;
F_33 ( V_2 -> V_86 , V_2 -> V_8 . V_9 + V_88 ) ;
F_64 ( V_2 ) ;
}
static void F_73 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
V_2 -> V_86 |= V_157 | V_158 | V_159 | V_160 ;
F_33 ( V_2 -> V_86 , V_2 -> V_8 . V_9 + V_88 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_47 ( & V_2 -> V_8 . V_79 ) ;
F_58 ( & V_2 -> V_8 . V_84 -> V_8 ) ;
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
unsigned int V_3 , V_161 ;
V_3 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_162 ;
V_161 = V_3 ^ V_2 -> V_163 ;
V_2 -> V_163 = V_3 ;
if ( ! V_161 )
return;
if ( V_161 & V_164 )
F_77 ( & V_2 -> V_8 , V_3 & V_164 ) ;
if ( V_161 & V_165 )
V_2 -> V_8 . V_15 . V_166 ++ ;
if ( V_161 & V_167 )
F_78 ( & V_2 -> V_8 , V_3 & V_167 ) ;
F_79 ( & V_2 -> V_8 . V_84 -> V_8 . V_168 ) ;
}
static T_6 F_80 ( int V_169 , void * V_170 )
{
struct V_1 * V_2 = V_170 ;
unsigned long V_77 ;
unsigned int V_3 , V_171 = V_172 ;
int V_173 = 0 ;
unsigned int V_174 ;
F_32 ( & V_2 -> V_8 . V_79 , V_77 ) ;
V_3 = F_2 ( V_2 -> V_8 . V_9 + V_175 ) ;
if ( V_3 ) {
do {
if ( V_2 -> V_146 -> V_176 ) {
F_33 ( 0x00 , V_2 -> V_8 . V_9 + V_135 ) ;
V_174 = F_2 ( V_2 -> V_8 . V_9 + V_135 ) ;
V_174 = F_2 ( V_2 -> V_8 . V_9 + V_135 ) ;
}
F_33 ( V_3 & ~ ( V_177 | V_178 |
V_179 ) ,
V_2 -> V_8 . V_9 + V_135 ) ;
if ( V_3 & ( V_178 | V_179 ) ) {
if ( F_69 ( V_2 ) )
F_59 ( V_2 ) ;
else
F_74 ( V_2 ) ;
}
if ( V_3 & ( V_180 | V_181 |
V_182 | V_183 ) )
F_76 ( V_2 ) ;
if ( V_3 & V_177 )
F_75 ( V_2 ) ;
if ( V_171 -- == 0 )
break;
V_3 = F_2 ( V_2 -> V_8 . V_9 + V_175 ) ;
} while ( V_3 != 0 );
V_173 = 1 ;
}
F_36 ( & V_2 -> V_8 . V_79 , V_77 ) ;
return F_81 ( V_173 ) ;
}
static unsigned int F_82 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_3 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) ;
return V_3 & ( V_151 | V_112 ) ? 0 : V_184 ;
}
static unsigned int F_83 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_185 = 0 ;
unsigned int V_3 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) ;
#define F_84 ( T_7 , T_8 ) \
if (status & uartbit) \
result |= tiocmbit
F_84 ( V_164 , V_186 ) ;
F_84 ( V_165 , V_187 ) ;
F_84 ( V_167 , V_188 ) ;
F_84 ( V_189 , V_190 ) ;
#undef F_84
return V_185 ;
}
static void F_85 ( struct V_113 * V_8 , unsigned int V_191 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_192 ;
V_192 = F_2 ( V_2 -> V_8 . V_9 + V_193 ) ;
#define F_84 ( T_8 , T_7 ) \
if (mctrl & tiocmbit) \
cr |= uartbit; \
else \
cr &= ~uartbit
F_84 ( V_194 , V_195 ) ;
F_84 ( V_196 , V_197 ) ;
F_84 ( V_198 , V_199 ) ;
F_84 ( V_200 , V_201 ) ;
F_84 ( V_202 , V_203 ) ;
if ( V_2 -> V_204 ) {
F_84 ( V_194 , V_205 ) ;
}
#undef F_84
F_33 ( V_192 , V_2 -> V_8 . V_9 + V_193 ) ;
}
static void F_86 ( struct V_113 * V_8 , int V_206 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_77 ;
unsigned int V_207 ;
F_32 ( & V_2 -> V_8 . V_79 , V_77 ) ;
V_207 = F_2 ( V_2 -> V_8 . V_9 + V_2 -> V_208 ) ;
if ( V_206 == - 1 )
V_207 |= V_209 ;
else
V_207 &= ~ V_209 ;
F_33 ( V_207 , V_2 -> V_8 . V_9 + V_2 -> V_208 ) ;
F_36 ( & V_2 -> V_8 . V_79 , V_77 ) ;
}
static void F_87 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned char T_9 * V_210 = V_2 -> V_8 . V_9 ;
F_33 ( F_2 ( V_210 + V_175 ) , V_210 + V_135 ) ;
F_33 ( F_2 ( V_210 + V_88 ) & ~ V_87 , V_210 + V_88 ) ;
}
static int F_88 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_3 ;
F_87 ( V_8 ) ;
V_3 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) ;
if ( V_3 & V_11 )
return V_211 ;
return F_2 ( V_2 -> V_8 . V_9 + V_12 ) ;
}
static void F_89 ( struct V_113 * V_8 ,
unsigned char V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
while ( F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_112 )
F_67 () ;
F_33 ( V_4 , V_2 -> V_8 . V_9 + V_12 ) ;
}
static int F_90 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
int V_212 ;
if ( ! F_91 ( V_2 -> V_213 ) ) {
V_212 = F_92 ( V_2 -> V_214 , V_2 -> V_213 ) ;
if ( V_212 )
F_19 ( V_8 -> V_41 ,
L_21 ) ;
}
V_212 = F_93 ( V_2 -> V_215 ) ;
if ( V_212 )
goto V_216;
V_2 -> V_8 . V_217 = F_94 ( V_2 -> V_215 ) ;
F_33 ( V_131 | V_132 | V_133 | V_134 |
V_178 | V_179 , V_2 -> V_8 . V_9 + V_135 ) ;
V_2 -> V_86 = F_2 ( V_2 -> V_8 . V_9 + V_88 ) ;
F_33 ( V_152 | V_125 , V_2 -> V_8 . V_9 + V_88 ) ;
if ( V_2 -> V_8 . V_41 -> V_45 ) {
struct V_43 * V_44 ;
V_44 = V_2 -> V_8 . V_41 -> V_45 ;
if ( V_44 -> V_218 )
V_44 -> V_218 () ;
}
return 0 ;
V_216:
return V_212 ;
}
static int F_95 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_192 ;
int V_212 ;
V_212 = F_90 ( V_8 ) ;
if ( V_212 )
goto V_219;
F_33 ( V_2 -> V_86 , V_2 -> V_8 . V_9 + V_88 ) ;
V_212 = F_96 ( V_2 -> V_8 . V_169 , F_80 , 0 , L_22 , V_2 ) ;
if ( V_212 )
goto V_219;
F_33 ( V_2 -> V_146 -> V_220 , V_2 -> V_8 . V_9 + V_221 ) ;
V_192 = V_222 | V_223 | V_203 ;
F_33 ( V_192 , V_2 -> V_8 . V_9 + V_193 ) ;
F_33 ( 0 , V_2 -> V_8 . V_9 + V_224 ) ;
F_33 ( 1 , V_2 -> V_8 . V_9 + V_225 ) ;
F_33 ( 0 , V_2 -> V_8 . V_9 + V_2 -> V_226 ) ;
if ( V_2 -> V_208 != V_2 -> V_226 ) {
int V_227 ;
for ( V_227 = 0 ; V_227 < 10 ; ++ V_227 )
F_33 ( 0xff , V_2 -> V_8 . V_9 + V_175 ) ;
F_33 ( 0 , V_2 -> V_8 . V_9 + V_2 -> V_208 ) ;
}
F_33 ( 0 , V_2 -> V_8 . V_9 + V_12 ) ;
while ( F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_151 )
F_67 () ;
V_192 = V_2 -> V_228 & ( V_195 | V_197 ) ;
V_192 |= V_222 | V_229 | V_223 ;
F_33 ( V_192 , V_2 -> V_8 . V_9 + V_193 ) ;
V_2 -> V_163 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_162 ;
F_65 ( V_2 ) ;
F_62 ( & V_2 -> V_8 . V_79 ) ;
F_33 ( V_178 | V_179 ,
V_2 -> V_8 . V_9 + V_135 ) ;
V_2 -> V_86 = V_152 ;
if ( ! F_69 ( V_2 ) )
V_2 -> V_86 |= V_125 ;
F_33 ( V_2 -> V_86 , V_2 -> V_8 . V_9 + V_88 ) ;
F_63 ( & V_2 -> V_8 . V_79 ) ;
return 0 ;
V_219:
F_97 ( V_2 -> V_215 ) ;
return V_212 ;
}
static void F_98 ( struct V_1 * V_2 ,
unsigned int V_230 )
{
unsigned long V_231 ;
V_231 = F_2 ( V_2 -> V_8 . V_9 + V_230 ) ;
V_231 &= ~ ( V_209 | V_232 ) ;
F_33 ( V_231 , V_2 -> V_8 . V_9 + V_230 ) ;
}
static void F_99 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_192 ;
int V_212 ;
F_62 ( & V_2 -> V_8 . V_79 ) ;
V_2 -> V_86 = 0 ;
F_33 ( V_2 -> V_86 , V_2 -> V_8 . V_9 + V_88 ) ;
F_33 ( 0xffff , V_2 -> V_8 . V_9 + V_135 ) ;
F_63 ( & V_2 -> V_8 . V_79 ) ;
F_66 ( V_2 ) ;
F_100 ( V_2 -> V_8 . V_169 , V_2 ) ;
V_2 -> V_204 = false ;
V_192 = F_2 ( V_2 -> V_8 . V_9 + V_193 ) ;
V_2 -> V_228 = V_192 ;
V_192 &= V_195 | V_197 ;
V_192 |= V_222 | V_223 ;
F_33 ( V_192 , V_2 -> V_8 . V_9 + V_193 ) ;
F_98 ( V_2 , V_2 -> V_226 ) ;
if ( V_2 -> V_226 != V_2 -> V_208 )
F_98 ( V_2 , V_2 -> V_208 ) ;
F_97 ( V_2 -> V_215 ) ;
if ( ! F_91 ( V_2 -> V_233 ) ) {
V_212 = F_92 ( V_2 -> V_214 , V_2 -> V_233 ) ;
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
F_101 ( struct V_113 * V_8 , struct V_234 * V_235 ,
struct V_234 * V_236 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_207 , V_228 ;
unsigned long V_77 ;
unsigned int V_237 , V_238 , V_239 ;
if ( V_2 -> V_146 -> V_240 )
V_239 = 8 ;
else
V_239 = 16 ;
V_237 = F_102 ( V_8 , V_235 , V_236 , 0 ,
V_8 -> V_217 / V_239 ) ;
if ( V_237 > V_8 -> V_217 / 16 )
V_238 = F_103 ( V_8 -> V_217 * 8 , V_237 ) ;
else
V_238 = F_103 ( V_8 -> V_217 * 4 , V_237 ) ;
switch ( V_235 -> V_241 & V_242 ) {
case V_243 :
V_207 = V_244 ;
break;
case V_245 :
V_207 = V_246 ;
break;
case V_247 :
V_207 = V_248 ;
break;
default:
V_207 = V_249 ;
break;
}
if ( V_235 -> V_241 & V_250 )
V_207 |= V_251 ;
if ( V_235 -> V_241 & V_252 ) {
V_207 |= V_253 ;
if ( ! ( V_235 -> V_241 & V_254 ) )
V_207 |= V_255 ;
}
if ( V_2 -> V_55 > 1 )
V_207 |= V_232 ;
F_32 ( & V_8 -> V_79 , V_77 ) ;
F_104 ( V_8 , V_235 -> V_241 , V_237 ) ;
V_8 -> V_26 = V_24 | 255 ;
if ( V_235 -> V_256 & V_257 )
V_8 -> V_26 |= V_19 | V_20 ;
if ( V_235 -> V_256 & ( V_258 | V_259 ) )
V_8 -> V_26 |= V_18 ;
V_8 -> V_260 = 0 ;
if ( V_235 -> V_256 & V_261 )
V_8 -> V_260 |= V_19 | V_20 ;
if ( V_235 -> V_256 & V_262 ) {
V_8 -> V_260 |= V_18 ;
if ( V_235 -> V_256 & V_261 )
V_8 -> V_260 |= V_24 ;
}
if ( ( V_235 -> V_241 & V_263 ) == 0 )
V_8 -> V_260 |= V_13 ;
if ( F_105 ( V_8 , V_235 -> V_241 ) )
F_73 ( V_8 ) ;
V_228 = F_2 ( V_8 -> V_9 + V_193 ) ;
F_33 ( 0 , V_8 -> V_9 + V_193 ) ;
if ( V_235 -> V_241 & V_264 ) {
if ( V_228 & V_195 )
V_228 |= V_205 ;
V_228 |= V_265 ;
V_2 -> V_204 = true ;
} else {
V_228 &= ~ ( V_265 | V_205 ) ;
V_2 -> V_204 = false ;
}
if ( V_2 -> V_146 -> V_240 ) {
if ( V_237 > V_8 -> V_217 / 16 )
V_228 |= V_266 ;
else
V_228 &= ~ V_266 ;
}
if ( V_2 -> V_146 -> V_240 ) {
if ( ( V_237 >= 3000000 ) && ( V_237 < 3250000 ) && ( V_238 > 1 ) )
V_238 -= 1 ;
else if ( ( V_237 > 3250000 ) && ( V_238 > 2 ) )
V_238 -= 2 ;
}
F_33 ( V_238 & 0x3f , V_8 -> V_9 + V_224 ) ;
F_33 ( V_238 >> 6 , V_8 -> V_9 + V_225 ) ;
F_33 ( V_207 , V_8 -> V_9 + V_2 -> V_226 ) ;
if ( V_2 -> V_226 != V_2 -> V_208 ) {
int V_227 ;
for ( V_227 = 0 ; V_227 < 10 ; ++ V_227 )
F_33 ( 0xff , V_2 -> V_8 . V_9 + V_175 ) ;
F_33 ( V_207 , V_8 -> V_9 + V_2 -> V_208 ) ;
}
F_33 ( V_228 , V_8 -> V_9 + V_193 ) ;
F_36 ( & V_8 -> V_79 , V_77 ) ;
}
static const char * F_106 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
return V_2 -> V_8 . type == V_267 ? V_2 -> type : NULL ;
}
static void F_107 ( struct V_113 * V_8 )
{
F_108 ( V_8 -> V_49 , V_268 ) ;
}
static int F_109 ( struct V_113 * V_8 )
{
return F_110 ( V_8 -> V_49 , V_268 , L_22 )
!= NULL ? 0 : - V_101 ;
}
static void F_111 ( struct V_113 * V_8 , int V_77 )
{
if ( V_77 & V_269 ) {
V_8 -> type = V_267 ;
F_109 ( V_8 ) ;
}
}
static int F_112 ( struct V_113 * V_8 , struct V_270 * V_271 )
{
int V_111 = 0 ;
if ( V_271 -> type != V_272 && V_271 -> type != V_267 )
V_111 = - V_42 ;
if ( V_271 -> V_169 < 0 || V_271 -> V_169 >= V_273 )
V_111 = - V_42 ;
if ( V_271 -> V_274 < 9600 )
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
F_114 ( struct V_275 * V_276 , const char * V_277 , unsigned int V_94 )
{
struct V_1 * V_2 = V_278 [ V_276 -> V_279 ] ;
unsigned int V_3 , V_228 , V_280 ;
unsigned long V_77 ;
int V_281 = 1 ;
F_115 ( V_2 -> V_215 ) ;
F_116 ( V_77 ) ;
if ( V_2 -> V_8 . V_282 )
V_281 = 0 ;
else if ( V_283 )
V_281 = F_117 ( & V_2 -> V_8 . V_79 ) ;
else
F_49 ( & V_2 -> V_8 . V_79 ) ;
V_228 = F_2 ( V_2 -> V_8 . V_9 + V_193 ) ;
V_280 = V_228 & ~ V_265 ;
V_280 |= V_222 | V_223 ;
F_33 ( V_280 , V_2 -> V_8 . V_9 + V_193 ) ;
F_118 ( & V_2 -> V_8 , V_277 , V_94 , F_113 ) ;
do {
V_3 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) ;
} while ( V_3 & V_151 );
F_33 ( V_228 , V_2 -> V_8 . V_9 + V_193 ) ;
if ( V_281 )
F_47 ( & V_2 -> V_8 . V_79 ) ;
F_119 ( V_77 ) ;
F_120 ( V_2 -> V_215 ) ;
}
static void T_3
F_121 ( struct V_1 * V_2 , int * V_237 ,
int * V_22 , int * V_284 )
{
if ( F_2 ( V_2 -> V_8 . V_9 + V_193 ) & V_222 ) {
unsigned int V_207 , V_285 , V_286 ;
V_207 = F_2 ( V_2 -> V_8 . V_9 + V_2 -> V_208 ) ;
* V_22 = 'n' ;
if ( V_207 & V_253 ) {
if ( V_207 & V_255 )
* V_22 = 'e' ;
else
* V_22 = 'o' ;
}
if ( ( V_207 & 0x60 ) == V_248 )
* V_284 = 7 ;
else
* V_284 = 8 ;
V_285 = F_2 ( V_2 -> V_8 . V_9 + V_225 ) ;
V_286 = F_2 ( V_2 -> V_8 . V_9 + V_224 ) ;
* V_237 = V_2 -> V_8 . V_217 * 4 / ( 64 * V_285 + V_286 ) ;
if ( V_2 -> V_146 -> V_240 ) {
if ( F_2 ( V_2 -> V_8 . V_9 + V_193 )
& V_266 )
* V_237 *= 2 ;
}
}
}
static int T_3 F_122 ( struct V_275 * V_276 , char * V_287 )
{
struct V_1 * V_2 ;
int V_237 = 38400 ;
int V_284 = 8 ;
int V_22 = 'n' ;
int V_288 = 'n' ;
int V_111 ;
if ( V_276 -> V_279 >= V_289 )
V_276 -> V_279 = 0 ;
V_2 = V_278 [ V_276 -> V_279 ] ;
if ( ! V_2 )
return - V_290 ;
if ( ! F_91 ( V_2 -> V_213 ) ) {
V_111 = F_92 ( V_2 -> V_214 , V_2 -> V_213 ) ;
if ( V_111 )
F_19 ( V_2 -> V_8 . V_41 ,
L_21 ) ;
}
V_111 = F_123 ( V_2 -> V_215 ) ;
if ( V_111 )
return V_111 ;
if ( V_2 -> V_8 . V_41 -> V_45 ) {
struct V_43 * V_44 ;
V_44 = V_2 -> V_8 . V_41 -> V_45 ;
if ( V_44 -> V_218 )
V_44 -> V_218 () ;
}
V_2 -> V_8 . V_217 = F_94 ( V_2 -> V_215 ) ;
if ( V_287 )
F_124 ( V_287 , & V_237 , & V_22 , & V_284 , & V_288 ) ;
else
F_121 ( V_2 , & V_237 , & V_22 , & V_284 ) ;
return F_125 ( & V_2 -> V_8 , V_276 , V_237 , V_22 , V_284 , V_288 ) ;
}
static int F_126 ( int V_279 , struct V_40 * V_41 )
{
struct V_291 * V_292 ;
static bool V_293 = false ;
static bool V_294 = false ;
int V_111 = V_279 ;
if ( ! F_127 ( V_295 ) )
return V_111 ;
V_292 = V_41 -> V_296 ;
if ( ! V_292 )
return V_111 ;
V_111 = F_128 ( V_292 , L_24 ) ;
if ( F_129 ( V_111 ) ) {
V_294 = true ;
V_111 = V_279 ;
} else {
V_293 = true ;
if ( V_111 >= F_130 ( V_278 ) || V_278 [ V_111 ] != NULL ) {
F_56 ( V_41 , L_25 , V_111 ) ;
V_111 = V_279 ;
}
}
if ( V_293 && V_294 )
F_56 ( V_41 , L_26 ) ;
return V_111 ;
}
static int F_131 ( struct V_297 * V_41 , const struct V_298 * V_299 )
{
struct V_1 * V_2 ;
struct V_300 * V_146 = V_299 -> V_75 ;
void T_9 * V_301 ;
int V_227 , V_111 ;
for ( V_227 = 0 ; V_227 < F_130 ( V_278 ) ; V_227 ++ )
if ( V_278 [ V_227 ] == NULL )
break;
if ( V_227 == F_130 ( V_278 ) ) {
V_111 = - V_101 ;
goto V_216;
}
V_2 = F_132 ( & V_41 -> V_41 , sizeof( struct V_1 ) ,
V_38 ) ;
if ( V_2 == NULL ) {
V_111 = - V_39 ;
goto V_216;
}
V_227 = F_126 ( V_227 , & V_41 -> V_41 ) ;
V_301 = F_133 ( & V_41 -> V_41 , V_41 -> V_302 . V_303 ,
F_134 ( & V_41 -> V_302 ) ) ;
if ( ! V_301 ) {
V_111 = - V_39 ;
goto V_216;
}
V_2 -> V_214 = F_135 ( & V_41 -> V_41 ) ;
if ( F_91 ( V_2 -> V_214 ) ) {
V_111 = F_136 ( V_2 -> V_214 ) ;
goto V_216;
}
V_2 -> V_213 = F_137 ( V_2 -> V_214 ,
V_304 ) ;
if ( F_91 ( V_2 -> V_213 ) )
F_19 ( & V_41 -> V_41 , L_27 ) ;
V_2 -> V_233 = F_137 ( V_2 -> V_214 ,
V_305 ) ;
if ( F_91 ( V_2 -> V_233 ) )
F_39 ( & V_41 -> V_41 , L_28 ) ;
V_2 -> V_215 = F_138 ( & V_41 -> V_41 , NULL ) ;
if ( F_91 ( V_2 -> V_215 ) ) {
V_111 = F_136 ( V_2 -> V_215 ) ;
goto V_216;
}
V_2 -> V_146 = V_146 ;
V_2 -> V_226 = V_146 -> V_226 ;
V_2 -> V_208 = V_146 -> V_208 ;
V_2 -> V_228 = 0 ;
V_2 -> V_55 = V_146 -> V_55 ;
V_2 -> V_8 . V_41 = & V_41 -> V_41 ;
V_2 -> V_8 . V_49 = V_41 -> V_302 . V_303 ;
V_2 -> V_8 . V_9 = V_301 ;
V_2 -> V_8 . V_306 = V_307 ;
V_2 -> V_8 . V_169 = V_41 -> V_169 [ 0 ] ;
V_2 -> V_8 . V_55 = V_2 -> V_55 ;
V_2 -> V_8 . V_308 = & V_309 ;
V_2 -> V_8 . V_77 = V_310 ;
V_2 -> V_8 . line = V_227 ;
F_26 ( V_2 ) ;
F_33 ( 0 , V_2 -> V_8 . V_9 + V_88 ) ;
F_33 ( 0xffff , V_2 -> V_8 . V_9 + V_135 ) ;
snprintf ( V_2 -> type , sizeof( V_2 -> type ) , L_29 , F_139 ( V_41 ) ) ;
V_278 [ V_227 ] = V_2 ;
F_140 ( V_41 , V_2 ) ;
V_111 = F_141 ( & V_311 , & V_2 -> V_8 ) ;
if ( V_111 ) {
F_140 ( V_41 , NULL ) ;
V_278 [ V_227 ] = NULL ;
F_29 ( V_2 ) ;
}
V_216:
return V_111 ;
}
static int F_142 ( struct V_297 * V_41 )
{
struct V_1 * V_2 = F_143 ( V_41 ) ;
int V_227 ;
F_140 ( V_41 , NULL ) ;
F_144 ( & V_311 , & V_2 -> V_8 ) ;
for ( V_227 = 0 ; V_227 < F_130 ( V_278 ) ; V_227 ++ )
if ( V_278 [ V_227 ] == V_2 )
V_278 [ V_227 ] = NULL ;
F_29 ( V_2 ) ;
return 0 ;
}
static int F_145 ( struct V_297 * V_41 , T_10 V_84 )
{
struct V_1 * V_2 = F_143 ( V_41 ) ;
if ( ! V_2 )
return - V_42 ;
return F_146 ( & V_311 , & V_2 -> V_8 ) ;
}
static int F_147 ( struct V_297 * V_41 )
{
struct V_1 * V_2 = F_143 ( V_41 ) ;
if ( ! V_2 )
return - V_42 ;
return F_148 ( & V_311 , & V_2 -> V_8 ) ;
}
static int T_3 F_149 ( void )
{
int V_111 ;
F_150 ( V_312 L_30 ) ;
V_111 = F_151 ( & V_311 ) ;
if ( V_111 == 0 ) {
V_111 = F_152 ( & V_313 ) ;
if ( V_111 )
F_153 ( & V_311 ) ;
}
return V_111 ;
}
static void T_11 F_154 ( void )
{
F_155 ( & V_313 ) ;
F_153 ( & V_311 ) ;
}
