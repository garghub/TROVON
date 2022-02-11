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
} ;
struct V_30 * V_31 ;
T_2 V_56 ;
if ( ! V_44 || ! V_44 -> V_57 ) {
F_15 ( V_2 -> V_8 . V_41 , L_1 ) ;
return;
}
F_16 ( V_56 ) ;
F_17 ( V_58 , V_56 ) ;
V_31 = F_18 ( V_56 , V_44 -> V_57 , V_44 -> V_59 ) ;
if ( ! V_31 ) {
F_19 ( V_2 -> V_8 . V_41 , L_2 ) ;
return;
}
F_20 ( V_31 , & V_47 ) ;
V_2 -> V_60 . V_31 = V_31 ;
F_15 ( V_2 -> V_8 . V_41 , L_3 ,
F_21 ( V_2 -> V_60 . V_31 ) ) ;
if ( V_44 -> V_61 ) {
struct V_46 V_62 = {
. V_63 = V_2 -> V_8 . V_49 + V_12 ,
. V_64 = V_51 ,
. V_52 = V_65 ,
. V_66 = V_2 -> V_55 >> 1 ,
} ;
V_31 = F_18 ( V_56 , V_44 -> V_57 , V_44 -> V_61 ) ;
if ( ! V_31 ) {
F_19 ( V_2 -> V_8 . V_41 , L_4 ) ;
return;
}
F_20 ( V_31 , & V_62 ) ;
V_2 -> V_67 . V_31 = V_31 ;
F_15 ( V_2 -> V_8 . V_41 , L_5 ,
F_21 ( V_2 -> V_67 . V_31 ) ) ;
}
}
static int T_3 F_22 ( void )
{
struct V_68 * V_69 , * V_70 ;
F_23 (node, tmp, &pl011_dma_uarts) {
struct V_71 * V_72 = F_24 ( V_69 , struct V_71 , V_69 ) ;
F_14 ( V_72 -> V_2 ) ;
F_25 ( V_69 ) ;
F_11 ( V_72 ) ;
}
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_71 * V_72 = F_27 ( sizeof( struct V_71 ) , V_38 ) ;
if ( V_72 ) {
V_72 -> V_2 = V_2 ;
F_28 ( & V_72 -> V_69 , & V_73 ) ;
}
}
static void F_26 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_60 . V_31 )
F_30 ( V_2 -> V_60 . V_31 ) ;
if ( V_2 -> V_67 . V_31 )
F_30 ( V_2 -> V_67 . V_31 ) ;
}
static void F_31 ( void * V_74 )
{
struct V_1 * V_2 = V_74 ;
struct V_75 * V_60 = & V_2 -> V_60 ;
unsigned long V_76 ;
T_1 V_77 ;
F_32 ( & V_2 -> V_8 . V_78 , V_76 ) ;
if ( V_2 -> V_60 . V_79 )
F_13 ( V_60 -> V_31 -> V_40 -> V_41 , & V_60 -> V_33 , 1 ,
V_80 ) ;
V_77 = V_2 -> V_77 ;
V_2 -> V_77 = V_77 & ~ V_81 ;
F_33 ( V_2 -> V_77 , V_2 -> V_8 . V_9 + V_82 ) ;
if ( ! ( V_77 & V_81 ) || F_34 ( & V_2 -> V_8 ) ||
F_35 ( & V_2 -> V_8 . V_83 -> V_84 ) ) {
V_2 -> V_60 . V_79 = false ;
F_36 ( & V_2 -> V_8 . V_78 , V_76 ) ;
return;
}
if ( F_37 ( V_2 ) <= 0 ) {
V_2 -> V_85 |= V_86 ;
F_33 ( V_2 -> V_85 , V_2 -> V_8 . V_9 + V_87 ) ;
}
F_36 ( & V_2 -> V_8 . V_78 , V_76 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_75 * V_60 = & V_2 -> V_60 ;
struct V_30 * V_31 = V_60 -> V_31 ;
struct V_88 * V_89 = V_31 -> V_40 ;
struct V_90 * V_91 ;
struct V_92 * V_84 = & V_2 -> V_8 . V_83 -> V_84 ;
unsigned int V_93 ;
V_93 = F_38 ( V_84 ) ;
if ( V_93 < ( V_2 -> V_55 >> 1 ) ) {
V_2 -> V_60 . V_79 = false ;
return 0 ;
}
V_93 -= 1 ;
if ( V_93 > V_37 )
V_93 = V_37 ;
if ( V_84 -> V_94 < V_84 -> V_95 )
memcpy ( & V_60 -> V_36 [ 0 ] , & V_84 -> V_36 [ V_84 -> V_94 ] , V_93 ) ;
else {
T_4 V_96 = V_97 - V_84 -> V_94 ;
T_4 V_98 = V_84 -> V_95 ;
memcpy ( & V_60 -> V_36 [ 0 ] , & V_84 -> V_36 [ V_84 -> V_94 ] , V_96 ) ;
if ( V_98 )
memcpy ( & V_60 -> V_36 [ V_96 ] , & V_84 -> V_36 [ 0 ] , V_98 ) ;
}
V_60 -> V_33 . V_99 = V_93 ;
if ( F_10 ( V_89 -> V_41 , & V_60 -> V_33 , 1 , V_80 ) != 1 ) {
V_2 -> V_60 . V_79 = false ;
F_39 ( V_2 -> V_8 . V_41 , L_6 ) ;
return - V_100 ;
}
V_91 = V_89 -> V_101 ( V_31 , & V_60 -> V_33 , 1 , V_53 ,
V_102 | V_103 ) ;
if ( ! V_91 ) {
F_13 ( V_89 -> V_41 , & V_60 -> V_33 , 1 , V_80 ) ;
V_2 -> V_60 . V_79 = false ;
F_39 ( V_2 -> V_8 . V_41 , L_7 ) ;
return - V_100 ;
}
V_91 -> V_104 = F_31 ;
V_91 -> V_105 = V_2 ;
F_40 ( V_91 ) ;
V_89 -> V_106 ( V_31 ) ;
V_2 -> V_77 |= V_81 ;
F_33 ( V_2 -> V_77 , V_2 -> V_8 . V_9 + V_82 ) ;
V_2 -> V_60 . V_79 = true ;
V_84 -> V_94 = ( V_84 -> V_94 + V_93 ) & ( V_97 - 1 ) ;
V_2 -> V_8 . V_15 . V_107 += V_93 ;
if ( F_38 ( V_84 ) < V_108 )
F_41 ( & V_2 -> V_8 ) ;
return 1 ;
}
static bool F_42 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_109 )
return false ;
if ( V_2 -> V_60 . V_79 ) {
V_2 -> V_77 |= V_81 ;
F_33 ( V_2 -> V_77 , V_2 -> V_8 . V_9 + V_82 ) ;
V_2 -> V_85 &= ~ V_86 ;
F_33 ( V_2 -> V_85 , V_2 -> V_8 . V_9 + V_87 ) ;
return true ;
}
if ( F_37 ( V_2 ) > 0 ) {
V_2 -> V_85 &= ~ V_86 ;
F_33 ( V_2 -> V_85 , V_2 -> V_8 . V_9 + V_87 ) ;
return true ;
}
return false ;
}
static inline void F_43 ( struct V_1 * V_2 )
{
if ( V_2 -> V_60 . V_79 ) {
V_2 -> V_77 &= ~ V_81 ;
F_33 ( V_2 -> V_77 , V_2 -> V_8 . V_9 + V_82 ) ;
}
}
static inline bool F_44 ( struct V_1 * V_2 )
{
T_1 V_77 ;
if ( ! V_2 -> V_109 )
return false ;
if ( ! V_2 -> V_8 . V_110 ) {
bool V_111 = true ;
if ( ! V_2 -> V_60 . V_79 ) {
if ( F_37 ( V_2 ) > 0 ) {
V_2 -> V_85 &= ~ V_86 ;
V_111 = true ;
} else {
V_2 -> V_85 |= V_86 ;
V_111 = false ;
}
F_33 ( V_2 -> V_85 , V_2 -> V_8 . V_9 + V_87 ) ;
} else if ( ! ( V_2 -> V_77 & V_81 ) ) {
V_2 -> V_77 |= V_81 ;
F_33 ( V_2 -> V_77 ,
V_2 -> V_8 . V_9 + V_82 ) ;
}
return V_111 ;
}
V_77 = V_2 -> V_77 ;
V_2 -> V_77 &= ~ V_81 ;
F_33 ( V_2 -> V_77 , V_2 -> V_8 . V_9 + V_82 ) ;
if ( F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_112 ) {
return false ;
}
F_33 ( V_2 -> V_8 . V_110 , V_2 -> V_8 . V_9 + V_12 ) ;
V_2 -> V_8 . V_15 . V_107 ++ ;
V_2 -> V_8 . V_110 = 0 ;
V_2 -> V_77 = V_77 ;
F_33 ( V_77 , V_2 -> V_8 . V_9 + V_82 ) ;
return true ;
}
static void F_45 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
if ( ! V_2 -> V_109 )
return;
F_46 ( & V_2 -> V_8 . V_78 ) ;
F_47 ( V_2 -> V_60 . V_31 ) ;
F_48 ( & V_2 -> V_8 . V_78 ) ;
if ( V_2 -> V_60 . V_79 ) {
F_13 ( V_2 -> V_60 . V_31 -> V_40 -> V_41 , & V_2 -> V_60 . V_33 , 1 ,
V_80 ) ;
V_2 -> V_60 . V_79 = false ;
V_2 -> V_77 &= ~ V_81 ;
F_33 ( V_2 -> V_77 , V_2 -> V_8 . V_9 + V_82 ) ;
}
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_30 * V_114 = V_2 -> V_67 . V_31 ;
struct V_88 * V_89 ;
struct V_115 * V_67 = & V_2 -> V_67 ;
struct V_90 * V_91 ;
struct V_32 * V_116 ;
if ( ! V_114 )
return - V_117 ;
V_116 = V_2 -> V_67 . V_118 ?
& V_2 -> V_67 . V_119 : & V_2 -> V_67 . V_120 ;
V_89 = V_114 -> V_40 ;
V_91 = V_114 -> V_40 -> V_101 ( V_114 , & V_116 -> V_33 , 1 ,
V_65 ,
V_102 | V_103 ) ;
if ( ! V_91 ) {
V_2 -> V_67 . V_121 = false ;
F_47 ( V_114 ) ;
return - V_100 ;
}
V_91 -> V_104 = V_122 ;
V_91 -> V_105 = V_2 ;
V_67 -> V_123 = F_40 ( V_91 ) ;
F_50 ( V_114 ) ;
V_2 -> V_77 |= V_124 ;
F_33 ( V_2 -> V_77 , V_2 -> V_8 . V_9 + V_82 ) ;
V_2 -> V_67 . V_121 = true ;
V_2 -> V_85 &= ~ V_125 ;
F_33 ( V_2 -> V_85 , V_2 -> V_8 . V_9 + V_87 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 ,
T_5 V_126 , bool V_118 ,
bool V_127 )
{
struct V_128 * V_129 = V_2 -> V_8 . V_83 -> V_8 . V_129 ;
struct V_32 * V_116 = V_118 ?
& V_2 -> V_67 . V_119 : & V_2 -> V_67 . V_120 ;
struct V_40 * V_41 = V_2 -> V_67 . V_31 -> V_40 -> V_41 ;
int V_130 = 0 ;
T_5 V_7 = 0 ;
if ( V_126 ) {
F_52 ( V_41 , & V_116 -> V_33 , 1 , V_131 ) ;
V_130 = F_53 ( V_2 -> V_8 . V_83 -> V_8 . V_129 ,
V_116 -> V_36 , V_126 ) ;
F_54 ( V_41 , & V_116 -> V_33 , 1 , V_131 ) ;
V_2 -> V_8 . V_15 . V_16 += V_130 ;
if ( V_130 < V_126 )
F_55 ( V_2 -> V_8 . V_41 ,
L_8 ) ;
}
if ( V_130 == V_126 && V_127 ) {
F_33 ( V_132 | V_133 | V_134 | V_135 ,
V_2 -> V_8 . V_9 + V_136 ) ;
V_7 = F_1 ( V_2 ) ;
}
F_46 ( & V_2 -> V_8 . V_78 ) ;
F_56 ( V_2 -> V_8 . V_41 ,
L_9 ,
V_130 , V_7 ) ;
F_57 ( V_129 ) ;
F_48 ( & V_2 -> V_8 . V_78 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_115 * V_67 = & V_2 -> V_67 ;
struct V_30 * V_114 = V_67 -> V_31 ;
struct V_32 * V_116 = V_67 -> V_118 ?
& V_67 -> V_119 : & V_67 -> V_120 ;
T_4 V_126 ;
struct V_137 V_83 ;
enum V_138 V_139 ;
if ( F_59 ( V_114 ) )
F_19 ( V_2 -> V_8 . V_41 , L_10 ) ;
V_139 = V_114 -> V_40 -> V_140 ( V_114 ,
V_67 -> V_123 , & V_83 ) ;
if ( V_139 != V_141 )
F_19 ( V_2 -> V_8 . V_41 , L_10 ) ;
V_2 -> V_77 &= ~ V_124 ;
F_33 ( V_2 -> V_77 , V_2 -> V_8 . V_9 + V_82 ) ;
V_2 -> V_67 . V_121 = false ;
V_126 = V_116 -> V_33 . V_99 - V_83 . V_142 ;
F_60 ( V_126 > V_37 ) ;
F_47 ( V_114 ) ;
F_51 ( V_2 , V_126 , V_67 -> V_118 , true ) ;
V_67 -> V_118 = ! V_67 -> V_118 ;
if ( F_49 ( V_2 ) ) {
F_39 ( V_2 -> V_8 . V_41 , L_11
L_12 ) ;
V_2 -> V_85 |= V_125 ;
F_33 ( V_2 -> V_85 , V_2 -> V_8 . V_9 + V_87 ) ;
}
}
static void V_122 ( void * V_74 )
{
struct V_1 * V_2 = V_74 ;
struct V_115 * V_67 = & V_2 -> V_67 ;
bool V_143 = V_67 -> V_118 ;
int V_111 ;
F_61 ( & V_2 -> V_8 . V_78 ) ;
V_2 -> V_67 . V_121 = false ;
V_67 -> V_118 = ! V_143 ;
V_111 = F_49 ( V_2 ) ;
F_51 ( V_2 , V_37 , V_143 , false ) ;
F_62 ( & V_2 -> V_8 . V_78 ) ;
if ( V_111 ) {
F_39 ( V_2 -> V_8 . V_41 , L_11
L_12 ) ;
V_2 -> V_85 |= V_125 ;
F_33 ( V_2 -> V_85 , V_2 -> V_8 . V_9 + V_87 ) ;
}
}
static inline void F_63 ( struct V_1 * V_2 )
{
V_2 -> V_77 &= ~ V_124 ;
F_33 ( V_2 -> V_77 , V_2 -> V_8 . V_9 + V_82 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
int V_111 ;
if ( ! V_2 -> V_60 . V_31 )
return;
V_2 -> V_60 . V_36 = F_8 ( V_37 , V_38 ) ;
if ( ! V_2 -> V_60 . V_36 ) {
F_19 ( V_2 -> V_8 . V_41 , L_13 ) ;
V_2 -> V_8 . V_55 = V_2 -> V_55 ;
return;
}
F_9 ( & V_2 -> V_60 . V_33 , V_2 -> V_60 . V_36 , V_37 ) ;
V_2 -> V_8 . V_55 = V_37 ;
V_2 -> V_109 = true ;
if ( ! V_2 -> V_67 . V_31 )
goto V_144;
V_111 = F_7 ( V_2 -> V_67 . V_31 , & V_2 -> V_67 . V_120 ,
V_131 ) ;
if ( V_111 ) {
F_19 ( V_2 -> V_8 . V_41 , L_14 ,
L_15 , V_111 ) ;
goto V_144;
}
V_111 = F_7 ( V_2 -> V_67 . V_31 , & V_2 -> V_67 . V_119 ,
V_131 ) ;
if ( V_111 ) {
F_19 ( V_2 -> V_8 . V_41 , L_14 ,
L_16 , V_111 ) ;
F_12 ( V_2 -> V_67 . V_31 , & V_2 -> V_67 . V_120 ,
V_131 ) ;
goto V_144;
}
V_2 -> V_145 = true ;
V_144:
V_2 -> V_77 |= V_146 ;
F_33 ( V_2 -> V_77 , V_2 -> V_8 . V_9 + V_82 ) ;
if ( V_2 -> V_147 -> V_148 )
F_33 ( V_149 | V_150 ,
V_2 -> V_8 . V_9 + V_151 ) ;
if ( V_2 -> V_145 ) {
if ( F_49 ( V_2 ) )
F_39 ( V_2 -> V_8 . V_41 , L_17
L_18 ) ;
}
}
static void F_65 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_109 || V_2 -> V_145 ) )
return;
while ( F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_152 )
F_66 () ;
F_61 ( & V_2 -> V_8 . V_78 ) ;
V_2 -> V_77 &= ~ ( V_146 | V_124 | V_81 ) ;
F_33 ( V_2 -> V_77 , V_2 -> V_8 . V_9 + V_82 ) ;
F_62 ( & V_2 -> V_8 . V_78 ) ;
if ( V_2 -> V_109 ) {
F_47 ( V_2 -> V_60 . V_31 ) ;
if ( V_2 -> V_60 . V_79 ) {
F_13 ( V_2 -> V_60 . V_31 -> V_40 -> V_41 , & V_2 -> V_60 . V_33 , 1 ,
V_80 ) ;
V_2 -> V_60 . V_79 = false ;
}
F_11 ( V_2 -> V_60 . V_36 ) ;
V_2 -> V_109 = false ;
}
if ( V_2 -> V_145 ) {
F_47 ( V_2 -> V_67 . V_31 ) ;
F_12 ( V_2 -> V_67 . V_31 , & V_2 -> V_67 . V_120 , V_131 ) ;
F_12 ( V_2 -> V_67 . V_31 , & V_2 -> V_67 . V_119 , V_131 ) ;
V_2 -> V_145 = false ;
}
}
static inline bool F_67 ( struct V_1 * V_2 )
{
return V_2 -> V_145 ;
}
static inline bool F_68 ( struct V_1 * V_2 )
{
return V_2 -> V_145 && V_2 -> V_67 . V_121 ;
}
static inline void F_26 ( struct V_1 * V_2 )
{
}
static inline void F_29 ( struct V_1 * V_2 )
{
}
static inline void F_64 ( struct V_1 * V_2 )
{
}
static inline void F_65 ( struct V_1 * V_2 )
{
}
static inline bool F_42 ( struct V_1 * V_2 )
{
return false ;
}
static inline void F_43 ( struct V_1 * V_2 )
{
}
static inline bool F_44 ( struct V_1 * V_2 )
{
return false ;
}
static inline void F_58 ( struct V_1 * V_2 )
{
}
static inline void F_63 ( struct V_1 * V_2 )
{
}
static inline int F_49 ( struct V_1 * V_2 )
{
return - V_117 ;
}
static inline bool F_67 ( struct V_1 * V_2 )
{
return false ;
}
static inline bool F_68 ( struct V_1 * V_2 )
{
return false ;
}
static void F_69 ( unsigned long V_74 )
{
struct V_1 * V_2 = V_153 [ 0 ] ;
void T_6 * V_154 = V_2 -> V_8 . V_9 ;
struct V_92 * V_84 = & V_2 -> V_8 . V_83 -> V_84 ;
struct V_128 * V_129 = V_2 -> V_8 . V_83 -> V_8 . V_129 ;
int V_155 = 200 ;
int V_156 ;
V_129 -> V_157 = 1 ;
while ( ! F_35 ( V_84 ) ) {
if ( V_155 -- == 0 )
break;
F_70 ( 100 ) ;
}
for ( V_156 = 0 ; V_156 < V_158 ; V_156 ++ )
V_159 [ V_156 ] = F_71 ( V_154 + V_160 [ V_156 ] ) ;
F_33 ( 0x00 , V_2 -> V_8 . V_9 + V_161 ) ;
if ( V_2 -> V_8 . V_41 -> V_45 ) {
struct V_43 * V_44 ;
V_44 = V_2 -> V_8 . V_41 -> V_45 ;
if ( V_44 -> V_162 )
V_44 -> V_162 () ;
}
for ( V_156 = 0 ; V_156 < V_158 ; V_156 ++ )
F_33 ( V_159 [ V_156 ] ,
V_2 -> V_8 . V_9 + V_160 [ V_156 ] ) ;
V_2 -> V_163 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) &
V_164 ;
if ( F_71 ( V_154 + V_165 ) & 0x2 )
F_72 ( V_166 L_19 ) ;
V_129 -> V_157 = 0 ;
}
static void F_73 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
V_2 -> V_85 &= ~ V_86 ;
F_33 ( V_2 -> V_85 , V_2 -> V_8 . V_9 + V_87 ) ;
F_43 ( V_2 ) ;
}
static void F_74 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
if ( ! F_44 ( V_2 ) ) {
V_2 -> V_85 |= V_86 ;
F_33 ( V_2 -> V_85 , V_2 -> V_8 . V_9 + V_87 ) ;
}
}
static void F_75 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
V_2 -> V_85 &= ~ ( V_125 | V_167 | V_168 |
V_169 | V_170 | V_171 ) ;
F_33 ( V_2 -> V_85 , V_2 -> V_8 . V_9 + V_87 ) ;
F_63 ( V_2 ) ;
}
static void F_76 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
V_2 -> V_85 |= V_172 | V_173 | V_174 | V_175 ;
F_33 ( V_2 -> V_85 , V_2 -> V_8 . V_9 + V_87 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_128 * V_129 = V_2 -> V_8 . V_83 -> V_8 . V_129 ;
F_1 ( V_2 ) ;
F_46 ( & V_2 -> V_8 . V_78 ) ;
F_57 ( V_129 ) ;
if ( F_67 ( V_2 ) ) {
if ( F_49 ( V_2 ) ) {
F_39 ( V_2 -> V_8 . V_41 , L_20
L_21 ) ;
V_2 -> V_85 |= V_125 ;
} else
V_2 -> V_85 &= ~ V_125 ;
F_33 ( V_2 -> V_85 , V_2 -> V_8 . V_9 + V_87 ) ;
}
F_48 ( & V_2 -> V_8 . V_78 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_92 * V_84 = & V_2 -> V_8 . V_83 -> V_84 ;
int V_93 ;
if ( V_2 -> V_8 . V_110 ) {
F_33 ( V_2 -> V_8 . V_110 , V_2 -> V_8 . V_9 + V_12 ) ;
V_2 -> V_8 . V_15 . V_107 ++ ;
V_2 -> V_8 . V_110 = 0 ;
return;
}
if ( F_35 ( V_84 ) || F_34 ( & V_2 -> V_8 ) ) {
F_73 ( & V_2 -> V_8 ) ;
return;
}
if ( F_42 ( V_2 ) )
return;
V_93 = V_2 -> V_55 >> 1 ;
do {
F_33 ( V_84 -> V_36 [ V_84 -> V_94 ] , V_2 -> V_8 . V_9 + V_12 ) ;
V_84 -> V_94 = ( V_84 -> V_94 + 1 ) & ( V_97 - 1 ) ;
V_2 -> V_8 . V_15 . V_107 ++ ;
if ( F_35 ( V_84 ) )
break;
} while ( -- V_93 > 0 );
if ( F_38 ( V_84 ) < V_108 )
F_41 ( & V_2 -> V_8 ) ;
if ( F_35 ( V_84 ) )
F_73 ( & V_2 -> V_8 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_176 ;
V_3 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_164 ;
V_176 = V_3 ^ V_2 -> V_163 ;
V_2 -> V_163 = V_3 ;
if ( ! V_176 )
return;
if ( V_176 & V_177 )
F_80 ( & V_2 -> V_8 , V_3 & V_177 ) ;
if ( V_176 & V_178 )
V_2 -> V_8 . V_15 . V_179 ++ ;
if ( V_176 & V_180 )
F_81 ( & V_2 -> V_8 , V_3 & V_180 ) ;
F_82 ( & V_2 -> V_8 . V_83 -> V_8 . V_181 ) ;
}
static T_7 F_83 ( int V_182 , void * V_183 )
{
struct V_1 * V_2 = V_183 ;
unsigned long V_76 ;
unsigned int V_3 , V_184 = V_185 ;
int V_186 = 0 ;
F_32 ( & V_2 -> V_8 . V_78 , V_76 ) ;
V_3 = F_2 ( V_2 -> V_8 . V_9 + V_165 ) ;
if ( V_3 ) {
do {
F_33 ( V_3 & ~ ( V_187 | V_188 |
V_189 ) ,
V_2 -> V_8 . V_9 + V_136 ) ;
if ( V_3 & ( V_188 | V_189 ) ) {
if ( F_68 ( V_2 ) )
F_58 ( V_2 ) ;
else
F_77 ( V_2 ) ;
}
if ( V_3 & ( V_190 | V_191 |
V_192 | V_193 ) )
F_79 ( V_2 ) ;
if ( V_3 & V_187 )
F_78 ( V_2 ) ;
if ( V_184 -- == 0 ) {
if ( V_2 -> V_194 )
F_84 ( & V_195 ) ;
break;
}
V_3 = F_2 ( V_2 -> V_8 . V_9 + V_165 ) ;
} while ( V_3 != 0 );
V_186 = 1 ;
}
F_36 ( & V_2 -> V_8 . V_78 , V_76 ) ;
return F_85 ( V_186 ) ;
}
static unsigned int F_86 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_3 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) ;
return V_3 & ( V_152 | V_112 ) ? 0 : V_196 ;
}
static unsigned int F_87 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_197 = 0 ;
unsigned int V_3 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) ;
#define F_88 ( T_8 , T_9 ) \
if (status & uartbit) \
result |= tiocmbit
F_88 ( V_177 , V_198 ) ;
F_88 ( V_178 , V_199 ) ;
F_88 ( V_180 , V_200 ) ;
F_88 ( V_201 , V_202 ) ;
#undef F_88
return V_197 ;
}
static void F_89 ( struct V_113 * V_8 , unsigned int V_203 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_204 ;
V_204 = F_2 ( V_2 -> V_8 . V_9 + V_161 ) ;
#define F_88 ( T_9 , T_8 ) \
if (mctrl & tiocmbit) \
cr |= uartbit; \
else \
cr &= ~uartbit
F_88 ( V_205 , V_206 ) ;
F_88 ( V_207 , V_208 ) ;
F_88 ( V_209 , V_210 ) ;
F_88 ( V_211 , V_212 ) ;
F_88 ( V_213 , V_214 ) ;
if ( V_2 -> V_215 ) {
F_88 ( V_205 , V_216 ) ;
}
#undef F_88
F_33 ( V_204 , V_2 -> V_8 . V_9 + V_161 ) ;
}
static void F_90 ( struct V_113 * V_8 , int V_217 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_76 ;
unsigned int V_218 ;
F_32 ( & V_2 -> V_8 . V_78 , V_76 ) ;
V_218 = F_2 ( V_2 -> V_8 . V_9 + V_2 -> V_219 ) ;
if ( V_217 == - 1 )
V_218 |= V_220 ;
else
V_218 &= ~ V_220 ;
F_33 ( V_218 , V_2 -> V_8 . V_9 + V_2 -> V_219 ) ;
F_36 ( & V_2 -> V_8 . V_78 , V_76 ) ;
}
static int F_91 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_3 ;
V_3 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) ;
if ( V_3 & V_11 )
return V_221 ;
return F_2 ( V_2 -> V_8 . V_9 + V_12 ) ;
}
static void F_92 ( struct V_113 * V_8 ,
unsigned char V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
while ( F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_112 )
F_66 () ;
F_33 ( V_4 , V_2 -> V_8 . V_9 + V_12 ) ;
}
static int F_93 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_204 ;
int V_222 ;
V_222 = F_94 ( V_2 -> V_223 ) ;
if ( V_222 )
goto V_224;
V_222 = F_95 ( V_2 -> V_223 ) ;
if ( V_222 )
goto V_225;
V_2 -> V_8 . V_226 = F_96 ( V_2 -> V_223 ) ;
V_222 = F_97 ( V_2 -> V_8 . V_182 , F_83 , 0 , L_22 , V_2 ) ;
if ( V_222 )
goto V_227;
F_33 ( V_2 -> V_147 -> V_228 , V_2 -> V_8 . V_9 + V_229 ) ;
V_204 = V_230 | V_231 | V_214 ;
F_33 ( V_204 , V_2 -> V_8 . V_9 + V_161 ) ;
F_33 ( 0 , V_2 -> V_8 . V_9 + V_232 ) ;
F_33 ( 1 , V_2 -> V_8 . V_9 + V_233 ) ;
F_33 ( 0 , V_2 -> V_8 . V_9 + V_2 -> V_234 ) ;
if ( V_2 -> V_219 != V_2 -> V_234 ) {
int V_235 ;
for ( V_235 = 0 ; V_235 < 10 ; ++ V_235 )
F_33 ( 0xff , V_2 -> V_8 . V_9 + V_165 ) ;
F_33 ( 0 , V_2 -> V_8 . V_9 + V_2 -> V_219 ) ;
}
F_33 ( 0 , V_2 -> V_8 . V_9 + V_12 ) ;
while ( F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_152 )
F_66 () ;
V_204 = V_2 -> V_236 & ( V_206 | V_208 ) ;
V_204 |= V_230 | V_237 | V_231 ;
F_33 ( V_204 , V_2 -> V_8 . V_9 + V_161 ) ;
F_33 ( V_132 | V_133 | V_134 | V_135 ,
V_2 -> V_8 . V_9 + V_136 ) ;
V_2 -> V_163 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_164 ;
F_64 ( V_2 ) ;
F_61 ( & V_2 -> V_8 . V_78 ) ;
V_2 -> V_85 = V_167 ;
if ( ! F_68 ( V_2 ) )
V_2 -> V_85 |= V_125 ;
F_33 ( V_2 -> V_85 , V_2 -> V_8 . V_9 + V_87 ) ;
F_62 ( & V_2 -> V_8 . V_78 ) ;
if ( V_2 -> V_8 . V_41 -> V_45 ) {
struct V_43 * V_44 ;
V_44 = V_2 -> V_8 . V_41 -> V_45 ;
if ( V_44 -> V_238 )
V_44 -> V_238 () ;
}
return 0 ;
V_227:
F_98 ( V_2 -> V_223 ) ;
V_225:
F_99 ( V_2 -> V_223 ) ;
V_224:
return V_222 ;
}
static void F_100 ( struct V_1 * V_2 ,
unsigned int V_239 )
{
unsigned long V_240 ;
V_240 = F_2 ( V_2 -> V_8 . V_9 + V_239 ) ;
V_240 &= ~ ( V_220 | V_241 ) ;
F_33 ( V_240 , V_2 -> V_8 . V_9 + V_239 ) ;
}
static void F_101 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_204 ;
F_61 ( & V_2 -> V_8 . V_78 ) ;
V_2 -> V_85 = 0 ;
F_33 ( V_2 -> V_85 , V_2 -> V_8 . V_9 + V_87 ) ;
F_33 ( 0xffff , V_2 -> V_8 . V_9 + V_136 ) ;
F_62 ( & V_2 -> V_8 . V_78 ) ;
F_65 ( V_2 ) ;
F_102 ( V_2 -> V_8 . V_182 , V_2 ) ;
V_2 -> V_215 = false ;
V_204 = F_2 ( V_2 -> V_8 . V_9 + V_161 ) ;
V_2 -> V_236 = V_204 ;
V_204 &= V_206 | V_208 ;
V_204 |= V_230 | V_231 ;
F_33 ( V_204 , V_2 -> V_8 . V_9 + V_161 ) ;
F_100 ( V_2 , V_2 -> V_234 ) ;
if ( V_2 -> V_234 != V_2 -> V_219 )
F_100 ( V_2 , V_2 -> V_219 ) ;
F_98 ( V_2 -> V_223 ) ;
F_99 ( V_2 -> V_223 ) ;
if ( V_2 -> V_8 . V_41 -> V_45 ) {
struct V_43 * V_44 ;
V_44 = V_2 -> V_8 . V_41 -> V_45 ;
if ( V_44 -> exit )
V_44 -> exit () ;
}
}
static void
F_103 ( struct V_113 * V_8 , struct V_242 * V_243 ,
struct V_242 * V_244 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_218 , V_236 ;
unsigned long V_76 ;
unsigned int V_245 , V_246 , V_247 ;
if ( V_2 -> V_147 -> V_248 )
V_247 = 8 ;
else
V_247 = 16 ;
V_245 = F_104 ( V_8 , V_243 , V_244 , 0 ,
V_8 -> V_226 / V_247 ) ;
if ( V_245 > V_8 -> V_226 / 16 )
V_246 = F_105 ( V_8 -> V_226 * 8 , V_245 ) ;
else
V_246 = F_105 ( V_8 -> V_226 * 4 , V_245 ) ;
switch ( V_243 -> V_249 & V_250 ) {
case V_251 :
V_218 = V_252 ;
break;
case V_253 :
V_218 = V_254 ;
break;
case V_255 :
V_218 = V_256 ;
break;
default:
V_218 = V_257 ;
break;
}
if ( V_243 -> V_249 & V_258 )
V_218 |= V_259 ;
if ( V_243 -> V_249 & V_260 ) {
V_218 |= V_261 ;
if ( ! ( V_243 -> V_249 & V_262 ) )
V_218 |= V_263 ;
}
if ( V_2 -> V_55 > 1 )
V_218 |= V_241 ;
F_32 ( & V_8 -> V_78 , V_76 ) ;
F_106 ( V_8 , V_243 -> V_249 , V_245 ) ;
V_8 -> V_26 = V_24 | 255 ;
if ( V_243 -> V_264 & V_265 )
V_8 -> V_26 |= V_19 | V_20 ;
if ( V_243 -> V_264 & ( V_266 | V_267 ) )
V_8 -> V_26 |= V_18 ;
V_8 -> V_268 = 0 ;
if ( V_243 -> V_264 & V_269 )
V_8 -> V_268 |= V_19 | V_20 ;
if ( V_243 -> V_264 & V_270 ) {
V_8 -> V_268 |= V_18 ;
if ( V_243 -> V_264 & V_269 )
V_8 -> V_268 |= V_24 ;
}
if ( ( V_243 -> V_249 & V_271 ) == 0 )
V_8 -> V_268 |= V_13 ;
if ( F_107 ( V_8 , V_243 -> V_249 ) )
F_76 ( V_8 ) ;
V_236 = F_2 ( V_8 -> V_9 + V_161 ) ;
F_33 ( 0 , V_8 -> V_9 + V_161 ) ;
if ( V_243 -> V_249 & V_272 ) {
if ( V_236 & V_206 )
V_236 |= V_216 ;
V_236 |= V_273 ;
V_2 -> V_215 = true ;
} else {
V_236 &= ~ ( V_273 | V_216 ) ;
V_2 -> V_215 = false ;
}
if ( V_2 -> V_147 -> V_248 ) {
if ( V_245 > V_8 -> V_226 / 16 )
V_236 |= V_274 ;
else
V_236 &= ~ V_274 ;
}
F_33 ( V_246 & 0x3f , V_8 -> V_9 + V_232 ) ;
F_33 ( V_246 >> 6 , V_8 -> V_9 + V_233 ) ;
F_33 ( V_218 , V_8 -> V_9 + V_2 -> V_234 ) ;
if ( V_2 -> V_234 != V_2 -> V_219 ) {
int V_235 ;
for ( V_235 = 0 ; V_235 < 10 ; ++ V_235 )
F_33 ( 0xff , V_2 -> V_8 . V_9 + V_165 ) ;
F_33 ( V_218 , V_8 -> V_9 + V_2 -> V_219 ) ;
}
F_33 ( V_236 , V_8 -> V_9 + V_161 ) ;
F_36 ( & V_8 -> V_78 , V_76 ) ;
}
static const char * F_108 ( struct V_113 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
return V_2 -> V_8 . type == V_275 ? V_2 -> type : NULL ;
}
static void F_109 ( struct V_113 * V_8 )
{
F_110 ( V_8 -> V_49 , V_276 ) ;
}
static int F_111 ( struct V_113 * V_8 )
{
return F_112 ( V_8 -> V_49 , V_276 , L_22 )
!= NULL ? 0 : - V_100 ;
}
static void F_113 ( struct V_113 * V_8 , int V_76 )
{
if ( V_76 & V_277 ) {
V_8 -> type = V_275 ;
F_111 ( V_8 ) ;
}
}
static int F_114 ( struct V_113 * V_8 , struct V_278 * V_279 )
{
int V_111 = 0 ;
if ( V_279 -> type != V_280 && V_279 -> type != V_275 )
V_111 = - V_42 ;
if ( V_279 -> V_182 < 0 || V_279 -> V_182 >= V_281 )
V_111 = - V_42 ;
if ( V_279 -> V_282 < 9600 )
V_111 = - V_42 ;
return V_111 ;
}
static void F_115 ( struct V_113 * V_8 , int V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
while ( F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_112 )
F_66 () ;
F_33 ( V_4 , V_2 -> V_8 . V_9 + V_12 ) ;
}
static void
F_116 ( struct V_283 * V_284 , const char * V_285 , unsigned int V_93 )
{
struct V_1 * V_2 = V_153 [ V_284 -> V_286 ] ;
unsigned int V_3 , V_236 , V_287 ;
unsigned long V_76 ;
int V_288 = 1 ;
F_95 ( V_2 -> V_223 ) ;
F_117 ( V_76 ) ;
if ( V_2 -> V_8 . V_289 )
V_288 = 0 ;
else if ( V_290 )
V_288 = F_118 ( & V_2 -> V_8 . V_78 ) ;
else
F_48 ( & V_2 -> V_8 . V_78 ) ;
V_236 = F_2 ( V_2 -> V_8 . V_9 + V_161 ) ;
V_287 = V_236 & ~ V_273 ;
V_287 |= V_230 | V_231 ;
F_33 ( V_287 , V_2 -> V_8 . V_9 + V_161 ) ;
F_119 ( & V_2 -> V_8 , V_285 , V_93 , F_115 ) ;
do {
V_3 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) ;
} while ( V_3 & V_152 );
F_33 ( V_236 , V_2 -> V_8 . V_9 + V_161 ) ;
if ( V_288 )
F_46 ( & V_2 -> V_8 . V_78 ) ;
F_120 ( V_76 ) ;
F_98 ( V_2 -> V_223 ) ;
}
static void T_3
F_121 ( struct V_1 * V_2 , int * V_245 ,
int * V_22 , int * V_291 )
{
if ( F_2 ( V_2 -> V_8 . V_9 + V_161 ) & V_230 ) {
unsigned int V_218 , V_292 , V_293 ;
V_218 = F_2 ( V_2 -> V_8 . V_9 + V_2 -> V_219 ) ;
* V_22 = 'n' ;
if ( V_218 & V_261 ) {
if ( V_218 & V_263 )
* V_22 = 'e' ;
else
* V_22 = 'o' ;
}
if ( ( V_218 & 0x60 ) == V_256 )
* V_291 = 7 ;
else
* V_291 = 8 ;
V_292 = F_2 ( V_2 -> V_8 . V_9 + V_233 ) ;
V_293 = F_2 ( V_2 -> V_8 . V_9 + V_232 ) ;
* V_245 = V_2 -> V_8 . V_226 * 4 / ( 64 * V_292 + V_293 ) ;
if ( V_2 -> V_147 -> V_248 ) {
if ( F_2 ( V_2 -> V_8 . V_9 + V_161 )
& V_274 )
* V_245 *= 2 ;
}
}
}
static int T_3 F_122 ( struct V_283 * V_284 , char * V_294 )
{
struct V_1 * V_2 ;
int V_245 = 38400 ;
int V_291 = 8 ;
int V_22 = 'n' ;
int V_295 = 'n' ;
int V_111 ;
if ( V_284 -> V_286 >= V_296 )
V_284 -> V_286 = 0 ;
V_2 = V_153 [ V_284 -> V_286 ] ;
if ( ! V_2 )
return - V_297 ;
V_111 = F_94 ( V_2 -> V_223 ) ;
if ( V_111 )
return V_111 ;
if ( V_2 -> V_8 . V_41 -> V_45 ) {
struct V_43 * V_44 ;
V_44 = V_2 -> V_8 . V_41 -> V_45 ;
if ( V_44 -> V_238 )
V_44 -> V_238 () ;
}
V_2 -> V_8 . V_226 = F_96 ( V_2 -> V_223 ) ;
if ( V_294 )
F_123 ( V_294 , & V_245 , & V_22 , & V_291 , & V_295 ) ;
else
F_121 ( V_2 , & V_245 , & V_22 , & V_291 ) ;
return F_124 ( & V_2 -> V_8 , V_284 , V_245 , V_22 , V_291 , V_295 ) ;
}
static int F_125 ( struct V_298 * V_41 , const struct V_299 * V_300 )
{
struct V_1 * V_2 ;
struct V_301 * V_147 = V_300 -> V_74 ;
void T_6 * V_154 ;
int V_235 , V_111 ;
for ( V_235 = 0 ; V_235 < F_126 ( V_153 ) ; V_235 ++ )
if ( V_153 [ V_235 ] == NULL )
break;
if ( V_235 == F_126 ( V_153 ) ) {
V_111 = - V_100 ;
goto V_224;
}
V_2 = F_27 ( sizeof( struct V_1 ) , V_38 ) ;
if ( V_2 == NULL ) {
V_111 = - V_39 ;
goto V_224;
}
V_154 = F_127 ( V_41 -> V_302 . V_303 , F_128 ( & V_41 -> V_302 ) ) ;
if ( ! V_154 ) {
V_111 = - V_39 ;
goto free;
}
V_2 -> V_223 = F_129 ( & V_41 -> V_41 , NULL ) ;
if ( F_130 ( V_2 -> V_223 ) ) {
V_111 = F_131 ( V_2 -> V_223 ) ;
goto V_304;
}
V_2 -> V_147 = V_147 ;
V_2 -> V_234 = V_147 -> V_234 ;
V_2 -> V_219 = V_147 -> V_219 ;
V_2 -> V_236 = 0 ;
V_2 -> V_55 = V_147 -> V_55 ;
V_2 -> V_194 = V_147 -> V_194 ;
V_2 -> V_8 . V_41 = & V_41 -> V_41 ;
V_2 -> V_8 . V_49 = V_41 -> V_302 . V_303 ;
V_2 -> V_8 . V_9 = V_154 ;
V_2 -> V_8 . V_305 = V_306 ;
V_2 -> V_8 . V_182 = V_41 -> V_182 [ 0 ] ;
V_2 -> V_8 . V_55 = V_2 -> V_55 ;
V_2 -> V_8 . V_307 = & V_308 ;
V_2 -> V_8 . V_76 = V_309 ;
V_2 -> V_8 . line = V_235 ;
F_26 ( V_2 ) ;
snprintf ( V_2 -> type , sizeof( V_2 -> type ) , L_23 , F_132 ( V_41 ) ) ;
V_153 [ V_235 ] = V_2 ;
F_133 ( V_41 , V_2 ) ;
V_111 = F_134 ( & V_310 , & V_2 -> V_8 ) ;
if ( V_111 ) {
F_133 ( V_41 , NULL ) ;
V_153 [ V_235 ] = NULL ;
F_29 ( V_2 ) ;
F_135 ( V_2 -> V_223 ) ;
V_304:
F_136 ( V_154 ) ;
free:
F_11 ( V_2 ) ;
}
V_224:
return V_111 ;
}
static int F_137 ( struct V_298 * V_41 )
{
struct V_1 * V_2 = F_138 ( V_41 ) ;
int V_235 ;
F_133 ( V_41 , NULL ) ;
F_139 ( & V_310 , & V_2 -> V_8 ) ;
for ( V_235 = 0 ; V_235 < F_126 ( V_153 ) ; V_235 ++ )
if ( V_153 [ V_235 ] == V_2 )
V_153 [ V_235 ] = NULL ;
F_29 ( V_2 ) ;
F_136 ( V_2 -> V_8 . V_9 ) ;
F_135 ( V_2 -> V_223 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_140 ( struct V_298 * V_41 , T_10 V_83 )
{
struct V_1 * V_2 = F_138 ( V_41 ) ;
if ( ! V_2 )
return - V_42 ;
return F_141 ( & V_310 , & V_2 -> V_8 ) ;
}
static int F_142 ( struct V_298 * V_41 )
{
struct V_1 * V_2 = F_138 ( V_41 ) ;
if ( ! V_2 )
return - V_42 ;
return F_143 ( & V_310 , & V_2 -> V_8 ) ;
}
static int T_3 F_144 ( void )
{
int V_111 ;
F_72 ( V_311 L_24 ) ;
V_111 = F_145 ( & V_310 ) ;
if ( V_111 == 0 ) {
V_111 = F_146 ( & V_312 ) ;
if ( V_111 )
F_147 ( & V_310 ) ;
}
return V_111 ;
}
static void T_11 F_148 ( void )
{
F_149 ( & V_312 ) ;
F_147 ( & V_310 ) ;
}
