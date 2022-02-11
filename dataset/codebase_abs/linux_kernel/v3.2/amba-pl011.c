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
V_53 ) ;
V_77 = V_2 -> V_77 ;
V_2 -> V_77 = V_77 & ~ V_80 ;
F_33 ( V_2 -> V_77 , V_2 -> V_8 . V_9 + V_81 ) ;
if ( ! ( V_77 & V_80 ) || F_34 ( & V_2 -> V_8 ) ||
F_35 ( & V_2 -> V_8 . V_82 -> V_83 ) ) {
V_2 -> V_60 . V_79 = false ;
F_36 ( & V_2 -> V_8 . V_78 , V_76 ) ;
return;
}
if ( F_37 ( V_2 ) <= 0 ) {
V_2 -> V_84 |= V_85 ;
F_33 ( V_2 -> V_84 , V_2 -> V_8 . V_9 + V_86 ) ;
}
F_36 ( & V_2 -> V_8 . V_78 , V_76 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_75 * V_60 = & V_2 -> V_60 ;
struct V_30 * V_31 = V_60 -> V_31 ;
struct V_87 * V_88 = V_31 -> V_40 ;
struct V_89 * V_90 ;
struct V_91 * V_83 = & V_2 -> V_8 . V_82 -> V_83 ;
unsigned int V_92 ;
V_92 = F_38 ( V_83 ) ;
if ( V_92 < ( V_2 -> V_55 >> 1 ) ) {
V_2 -> V_60 . V_79 = false ;
return 0 ;
}
V_92 -= 1 ;
if ( V_92 > V_37 )
V_92 = V_37 ;
if ( V_83 -> V_93 < V_83 -> V_94 )
memcpy ( & V_60 -> V_36 [ 0 ] , & V_83 -> V_36 [ V_83 -> V_93 ] , V_92 ) ;
else {
T_4 V_95 = V_96 - V_83 -> V_93 ;
T_4 V_97 = V_83 -> V_94 ;
memcpy ( & V_60 -> V_36 [ 0 ] , & V_83 -> V_36 [ V_83 -> V_93 ] , V_95 ) ;
if ( V_97 )
memcpy ( & V_60 -> V_36 [ V_95 ] , & V_83 -> V_36 [ 0 ] , V_97 ) ;
}
V_60 -> V_33 . V_98 = V_92 ;
if ( F_10 ( V_88 -> V_41 , & V_60 -> V_33 , 1 , V_53 ) != 1 ) {
V_2 -> V_60 . V_79 = false ;
F_39 ( V_2 -> V_8 . V_41 , L_6 ) ;
return - V_99 ;
}
V_90 = V_88 -> V_100 ( V_31 , & V_60 -> V_33 , 1 , V_53 ,
V_101 | V_102 ) ;
if ( ! V_90 ) {
F_13 ( V_88 -> V_41 , & V_60 -> V_33 , 1 , V_53 ) ;
V_2 -> V_60 . V_79 = false ;
F_39 ( V_2 -> V_8 . V_41 , L_7 ) ;
return - V_99 ;
}
V_90 -> V_103 = F_31 ;
V_90 -> V_104 = V_2 ;
F_40 ( V_90 ) ;
V_88 -> V_105 ( V_31 ) ;
V_2 -> V_77 |= V_80 ;
F_33 ( V_2 -> V_77 , V_2 -> V_8 . V_9 + V_81 ) ;
V_2 -> V_60 . V_79 = true ;
V_83 -> V_93 = ( V_83 -> V_93 + V_92 ) & ( V_96 - 1 ) ;
V_2 -> V_8 . V_15 . V_106 += V_92 ;
if ( F_38 ( V_83 ) < V_107 )
F_41 ( & V_2 -> V_8 ) ;
return 1 ;
}
static bool F_42 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_108 )
return false ;
if ( V_2 -> V_60 . V_79 ) {
V_2 -> V_77 |= V_80 ;
F_33 ( V_2 -> V_77 , V_2 -> V_8 . V_9 + V_81 ) ;
V_2 -> V_84 &= ~ V_85 ;
F_33 ( V_2 -> V_84 , V_2 -> V_8 . V_9 + V_86 ) ;
return true ;
}
if ( F_37 ( V_2 ) > 0 ) {
V_2 -> V_84 &= ~ V_85 ;
F_33 ( V_2 -> V_84 , V_2 -> V_8 . V_9 + V_86 ) ;
return true ;
}
return false ;
}
static inline void F_43 ( struct V_1 * V_2 )
{
if ( V_2 -> V_60 . V_79 ) {
V_2 -> V_77 &= ~ V_80 ;
F_33 ( V_2 -> V_77 , V_2 -> V_8 . V_9 + V_81 ) ;
}
}
static inline bool F_44 ( struct V_1 * V_2 )
{
T_1 V_77 ;
if ( ! V_2 -> V_108 )
return false ;
if ( ! V_2 -> V_8 . V_109 ) {
bool V_110 = true ;
if ( ! V_2 -> V_60 . V_79 ) {
if ( F_37 ( V_2 ) > 0 ) {
V_2 -> V_84 &= ~ V_85 ;
V_110 = true ;
} else {
V_2 -> V_84 |= V_85 ;
V_110 = false ;
}
F_33 ( V_2 -> V_84 , V_2 -> V_8 . V_9 + V_86 ) ;
} else if ( ! ( V_2 -> V_77 & V_80 ) ) {
V_2 -> V_77 |= V_80 ;
F_33 ( V_2 -> V_77 ,
V_2 -> V_8 . V_9 + V_81 ) ;
}
return V_110 ;
}
V_77 = V_2 -> V_77 ;
V_2 -> V_77 &= ~ V_80 ;
F_33 ( V_2 -> V_77 , V_2 -> V_8 . V_9 + V_81 ) ;
if ( F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_111 ) {
return false ;
}
F_33 ( V_2 -> V_8 . V_109 , V_2 -> V_8 . V_9 + V_12 ) ;
V_2 -> V_8 . V_15 . V_106 ++ ;
V_2 -> V_8 . V_109 = 0 ;
V_2 -> V_77 = V_77 ;
F_33 ( V_77 , V_2 -> V_8 . V_9 + V_81 ) ;
return true ;
}
static void F_45 ( struct V_112 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
if ( ! V_2 -> V_108 )
return;
F_46 ( & V_2 -> V_8 . V_78 ) ;
F_47 ( V_2 -> V_60 . V_31 ) ;
F_48 ( & V_2 -> V_8 . V_78 ) ;
if ( V_2 -> V_60 . V_79 ) {
F_13 ( V_2 -> V_60 . V_31 -> V_40 -> V_41 , & V_2 -> V_60 . V_33 , 1 ,
V_53 ) ;
V_2 -> V_60 . V_79 = false ;
V_2 -> V_77 &= ~ V_80 ;
F_33 ( V_2 -> V_77 , V_2 -> V_8 . V_9 + V_81 ) ;
}
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_30 * V_113 = V_2 -> V_67 . V_31 ;
struct V_87 * V_88 ;
struct V_114 * V_67 = & V_2 -> V_67 ;
struct V_89 * V_90 ;
struct V_32 * V_115 ;
if ( ! V_113 )
return - V_116 ;
V_115 = V_2 -> V_67 . V_117 ?
& V_2 -> V_67 . V_118 : & V_2 -> V_67 . V_119 ;
V_88 = V_113 -> V_40 ;
V_90 = V_113 -> V_40 -> V_100 ( V_113 , & V_115 -> V_33 , 1 ,
V_65 ,
V_101 | V_102 ) ;
if ( ! V_90 ) {
V_2 -> V_67 . V_120 = false ;
F_47 ( V_113 ) ;
return - V_99 ;
}
V_90 -> V_103 = V_121 ;
V_90 -> V_104 = V_2 ;
V_67 -> V_122 = F_40 ( V_90 ) ;
F_50 ( V_113 ) ;
V_2 -> V_77 |= V_123 ;
F_33 ( V_2 -> V_77 , V_2 -> V_8 . V_9 + V_81 ) ;
V_2 -> V_67 . V_120 = true ;
V_2 -> V_84 &= ~ V_124 ;
F_33 ( V_2 -> V_84 , V_2 -> V_8 . V_9 + V_86 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 ,
T_5 V_125 , bool V_117 ,
bool V_126 )
{
struct V_127 * V_128 = V_2 -> V_8 . V_82 -> V_8 . V_128 ;
struct V_32 * V_115 = V_117 ?
& V_2 -> V_67 . V_118 : & V_2 -> V_67 . V_119 ;
struct V_40 * V_41 = V_2 -> V_67 . V_31 -> V_40 -> V_41 ;
int V_129 = 0 ;
T_5 V_7 = 0 ;
if ( V_125 ) {
F_52 ( V_41 , & V_115 -> V_33 , 1 , V_65 ) ;
V_129 = F_53 ( V_2 -> V_8 . V_82 -> V_8 . V_128 ,
V_115 -> V_36 , V_125 ) ;
F_54 ( V_41 , & V_115 -> V_33 , 1 , V_65 ) ;
V_2 -> V_8 . V_15 . V_16 += V_129 ;
if ( V_129 < V_125 )
F_55 ( V_2 -> V_8 . V_41 ,
L_8 ) ;
}
if ( V_129 == V_125 && V_126 ) {
F_33 ( V_130 | V_131 | V_132 | V_133 ,
V_2 -> V_8 . V_9 + V_134 ) ;
V_7 = F_1 ( V_2 ) ;
}
F_46 ( & V_2 -> V_8 . V_78 ) ;
F_56 ( V_2 -> V_8 . V_41 ,
L_9 ,
V_129 , V_7 ) ;
F_57 ( V_128 ) ;
F_48 ( & V_2 -> V_8 . V_78 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_114 * V_67 = & V_2 -> V_67 ;
struct V_30 * V_113 = V_67 -> V_31 ;
struct V_32 * V_115 = V_67 -> V_117 ?
& V_67 -> V_118 : & V_67 -> V_119 ;
T_4 V_125 ;
struct V_135 V_82 ;
enum V_136 V_137 ;
if ( F_59 ( V_113 ) )
F_19 ( V_2 -> V_8 . V_41 , L_10 ) ;
V_137 = V_113 -> V_40 -> V_138 ( V_113 ,
V_67 -> V_122 , & V_82 ) ;
if ( V_137 != V_139 )
F_19 ( V_2 -> V_8 . V_41 , L_10 ) ;
V_2 -> V_77 &= ~ V_123 ;
F_33 ( V_2 -> V_77 , V_2 -> V_8 . V_9 + V_81 ) ;
V_2 -> V_67 . V_120 = false ;
V_125 = V_115 -> V_33 . V_98 - V_82 . V_140 ;
F_60 ( V_125 > V_37 ) ;
F_47 ( V_113 ) ;
F_51 ( V_2 , V_125 , V_67 -> V_117 , true ) ;
V_67 -> V_117 = ! V_67 -> V_117 ;
if ( F_49 ( V_2 ) ) {
F_39 ( V_2 -> V_8 . V_41 , L_11
L_12 ) ;
V_2 -> V_84 |= V_124 ;
F_33 ( V_2 -> V_84 , V_2 -> V_8 . V_9 + V_86 ) ;
}
}
static void V_121 ( void * V_74 )
{
struct V_1 * V_2 = V_74 ;
struct V_114 * V_67 = & V_2 -> V_67 ;
bool V_141 = V_67 -> V_117 ;
int V_110 ;
F_61 ( & V_2 -> V_8 . V_78 ) ;
V_2 -> V_67 . V_120 = false ;
V_67 -> V_117 = ! V_141 ;
V_110 = F_49 ( V_2 ) ;
F_51 ( V_2 , V_37 , V_141 , false ) ;
F_62 ( & V_2 -> V_8 . V_78 ) ;
if ( V_110 ) {
F_39 ( V_2 -> V_8 . V_41 , L_11
L_12 ) ;
V_2 -> V_84 |= V_124 ;
F_33 ( V_2 -> V_84 , V_2 -> V_8 . V_9 + V_86 ) ;
}
}
static inline void F_63 ( struct V_1 * V_2 )
{
V_2 -> V_77 &= ~ V_123 ;
F_33 ( V_2 -> V_77 , V_2 -> V_8 . V_9 + V_81 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
int V_110 ;
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
V_2 -> V_108 = true ;
if ( ! V_2 -> V_67 . V_31 )
goto V_142;
V_110 = F_7 ( V_2 -> V_67 . V_31 , & V_2 -> V_67 . V_119 ,
V_65 ) ;
if ( V_110 ) {
F_19 ( V_2 -> V_8 . V_41 , L_14 ,
L_15 , V_110 ) ;
goto V_142;
}
V_110 = F_7 ( V_2 -> V_67 . V_31 , & V_2 -> V_67 . V_118 ,
V_65 ) ;
if ( V_110 ) {
F_19 ( V_2 -> V_8 . V_41 , L_14 ,
L_16 , V_110 ) ;
F_12 ( V_2 -> V_67 . V_31 , & V_2 -> V_67 . V_119 ,
V_65 ) ;
goto V_142;
}
V_2 -> V_143 = true ;
V_142:
V_2 -> V_77 |= V_144 ;
F_33 ( V_2 -> V_77 , V_2 -> V_8 . V_9 + V_81 ) ;
if ( V_2 -> V_145 -> V_146 )
F_33 ( V_147 | V_148 ,
V_2 -> V_8 . V_9 + V_149 ) ;
if ( V_2 -> V_143 ) {
if ( F_49 ( V_2 ) )
F_39 ( V_2 -> V_8 . V_41 , L_17
L_18 ) ;
}
}
static void F_65 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_108 || V_2 -> V_143 ) )
return;
while ( F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_150 )
F_66 () ;
F_61 ( & V_2 -> V_8 . V_78 ) ;
V_2 -> V_77 &= ~ ( V_144 | V_123 | V_80 ) ;
F_33 ( V_2 -> V_77 , V_2 -> V_8 . V_9 + V_81 ) ;
F_62 ( & V_2 -> V_8 . V_78 ) ;
if ( V_2 -> V_108 ) {
F_47 ( V_2 -> V_60 . V_31 ) ;
if ( V_2 -> V_60 . V_79 ) {
F_13 ( V_2 -> V_60 . V_31 -> V_40 -> V_41 , & V_2 -> V_60 . V_33 , 1 ,
V_53 ) ;
V_2 -> V_60 . V_79 = false ;
}
F_11 ( V_2 -> V_60 . V_36 ) ;
V_2 -> V_108 = false ;
}
if ( V_2 -> V_143 ) {
F_47 ( V_2 -> V_67 . V_31 ) ;
F_12 ( V_2 -> V_67 . V_31 , & V_2 -> V_67 . V_119 , V_65 ) ;
F_12 ( V_2 -> V_67 . V_31 , & V_2 -> V_67 . V_118 , V_65 ) ;
V_2 -> V_143 = false ;
}
}
static inline bool F_67 ( struct V_1 * V_2 )
{
return V_2 -> V_143 ;
}
static inline bool F_68 ( struct V_1 * V_2 )
{
return V_2 -> V_143 && V_2 -> V_67 . V_120 ;
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
return - V_116 ;
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
struct V_1 * V_2 = V_151 [ 0 ] ;
void T_6 * V_152 = V_2 -> V_8 . V_9 ;
struct V_91 * V_83 = & V_2 -> V_8 . V_82 -> V_83 ;
struct V_127 * V_128 = V_2 -> V_8 . V_82 -> V_8 . V_128 ;
int V_153 = 200 ;
int V_154 ;
V_128 -> V_155 = 1 ;
while ( ! F_35 ( V_83 ) ) {
if ( V_153 -- == 0 )
break;
F_70 ( 100 ) ;
}
for ( V_154 = 0 ; V_154 < V_156 ; V_154 ++ )
V_157 [ V_154 ] = F_71 ( V_152 + V_158 [ V_154 ] ) ;
F_33 ( 0x00 , V_2 -> V_8 . V_9 + V_159 ) ;
if ( V_2 -> V_8 . V_41 -> V_45 ) {
struct V_43 * V_44 ;
V_44 = V_2 -> V_8 . V_41 -> V_45 ;
if ( V_44 -> V_160 )
V_44 -> V_160 () ;
}
for ( V_154 = 0 ; V_154 < V_156 ; V_154 ++ )
F_33 ( V_157 [ V_154 ] ,
V_2 -> V_8 . V_9 + V_158 [ V_154 ] ) ;
V_2 -> V_161 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) &
V_162 ;
if ( F_71 ( V_152 + V_163 ) & 0x2 )
F_72 ( V_164 L_19 ) ;
V_128 -> V_155 = 0 ;
}
static void F_73 ( struct V_112 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
V_2 -> V_84 &= ~ V_85 ;
F_33 ( V_2 -> V_84 , V_2 -> V_8 . V_9 + V_86 ) ;
F_43 ( V_2 ) ;
}
static void F_74 ( struct V_112 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
if ( ! F_44 ( V_2 ) ) {
V_2 -> V_84 |= V_85 ;
F_33 ( V_2 -> V_84 , V_2 -> V_8 . V_9 + V_86 ) ;
}
}
static void F_75 ( struct V_112 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
V_2 -> V_84 &= ~ ( V_124 | V_165 | V_166 |
V_167 | V_168 | V_169 ) ;
F_33 ( V_2 -> V_84 , V_2 -> V_8 . V_9 + V_86 ) ;
F_63 ( V_2 ) ;
}
static void F_76 ( struct V_112 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
V_2 -> V_84 |= V_170 | V_171 | V_172 | V_173 ;
F_33 ( V_2 -> V_84 , V_2 -> V_8 . V_9 + V_86 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_127 * V_128 = V_2 -> V_8 . V_82 -> V_8 . V_128 ;
F_1 ( V_2 ) ;
F_46 ( & V_2 -> V_8 . V_78 ) ;
F_57 ( V_128 ) ;
if ( F_67 ( V_2 ) ) {
if ( F_49 ( V_2 ) ) {
F_39 ( V_2 -> V_8 . V_41 , L_20
L_21 ) ;
V_2 -> V_84 |= V_124 ;
} else
V_2 -> V_84 &= ~ V_124 ;
F_33 ( V_2 -> V_84 , V_2 -> V_8 . V_9 + V_86 ) ;
}
F_48 ( & V_2 -> V_8 . V_78 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_91 * V_83 = & V_2 -> V_8 . V_82 -> V_83 ;
int V_92 ;
if ( V_2 -> V_8 . V_109 ) {
F_33 ( V_2 -> V_8 . V_109 , V_2 -> V_8 . V_9 + V_12 ) ;
V_2 -> V_8 . V_15 . V_106 ++ ;
V_2 -> V_8 . V_109 = 0 ;
return;
}
if ( F_35 ( V_83 ) || F_34 ( & V_2 -> V_8 ) ) {
F_73 ( & V_2 -> V_8 ) ;
return;
}
if ( F_42 ( V_2 ) )
return;
V_92 = V_2 -> V_55 >> 1 ;
do {
F_33 ( V_83 -> V_36 [ V_83 -> V_93 ] , V_2 -> V_8 . V_9 + V_12 ) ;
V_83 -> V_93 = ( V_83 -> V_93 + 1 ) & ( V_96 - 1 ) ;
V_2 -> V_8 . V_15 . V_106 ++ ;
if ( F_35 ( V_83 ) )
break;
} while ( -- V_92 > 0 );
if ( F_38 ( V_83 ) < V_107 )
F_41 ( & V_2 -> V_8 ) ;
if ( F_35 ( V_83 ) )
F_73 ( & V_2 -> V_8 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_174 ;
V_3 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_162 ;
V_174 = V_3 ^ V_2 -> V_161 ;
V_2 -> V_161 = V_3 ;
if ( ! V_174 )
return;
if ( V_174 & V_175 )
F_80 ( & V_2 -> V_8 , V_3 & V_175 ) ;
if ( V_174 & V_176 )
V_2 -> V_8 . V_15 . V_177 ++ ;
if ( V_174 & V_178 )
F_81 ( & V_2 -> V_8 , V_3 & V_178 ) ;
F_82 ( & V_2 -> V_8 . V_82 -> V_8 . V_179 ) ;
}
static T_7 F_83 ( int V_180 , void * V_181 )
{
struct V_1 * V_2 = V_181 ;
unsigned long V_76 ;
unsigned int V_3 , V_182 = V_183 ;
int V_184 = 0 ;
F_32 ( & V_2 -> V_8 . V_78 , V_76 ) ;
V_3 = F_2 ( V_2 -> V_8 . V_9 + V_163 ) ;
if ( V_3 ) {
do {
F_33 ( V_3 & ~ ( V_185 | V_186 |
V_187 ) ,
V_2 -> V_8 . V_9 + V_134 ) ;
if ( V_3 & ( V_186 | V_187 ) ) {
if ( F_68 ( V_2 ) )
F_58 ( V_2 ) ;
else
F_77 ( V_2 ) ;
}
if ( V_3 & ( V_188 | V_189 |
V_190 | V_191 ) )
F_79 ( V_2 ) ;
if ( V_3 & V_185 )
F_78 ( V_2 ) ;
if ( V_182 -- == 0 ) {
if ( V_2 -> V_192 )
F_84 ( & V_193 ) ;
break;
}
V_3 = F_2 ( V_2 -> V_8 . V_9 + V_163 ) ;
} while ( V_3 != 0 );
V_184 = 1 ;
}
F_36 ( & V_2 -> V_8 . V_78 , V_76 ) ;
return F_85 ( V_184 ) ;
}
static unsigned int F_86 ( struct V_112 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_3 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) ;
return V_3 & ( V_150 | V_111 ) ? 0 : V_194 ;
}
static unsigned int F_87 ( struct V_112 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_195 = 0 ;
unsigned int V_3 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) ;
#define F_88 ( T_8 , T_9 ) \
if (status & uartbit) \
result |= tiocmbit
F_88 ( V_175 , V_196 ) ;
F_88 ( V_176 , V_197 ) ;
F_88 ( V_178 , V_198 ) ;
F_88 ( V_199 , V_200 ) ;
#undef F_88
return V_195 ;
}
static void F_89 ( struct V_112 * V_8 , unsigned int V_201 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_202 ;
V_202 = F_2 ( V_2 -> V_8 . V_9 + V_159 ) ;
#define F_88 ( T_9 , T_8 ) \
if (mctrl & tiocmbit) \
cr |= uartbit; \
else \
cr &= ~uartbit
F_88 ( V_203 , V_204 ) ;
F_88 ( V_205 , V_206 ) ;
F_88 ( V_207 , V_208 ) ;
F_88 ( V_209 , V_210 ) ;
F_88 ( V_211 , V_212 ) ;
if ( V_2 -> V_213 ) {
F_88 ( V_203 , V_214 ) ;
}
#undef F_88
F_33 ( V_202 , V_2 -> V_8 . V_9 + V_159 ) ;
}
static void F_90 ( struct V_112 * V_8 , int V_215 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned long V_76 ;
unsigned int V_216 ;
F_32 ( & V_2 -> V_8 . V_78 , V_76 ) ;
V_216 = F_2 ( V_2 -> V_8 . V_9 + V_2 -> V_217 ) ;
if ( V_215 == - 1 )
V_216 |= V_218 ;
else
V_216 &= ~ V_218 ;
F_33 ( V_216 , V_2 -> V_8 . V_9 + V_2 -> V_217 ) ;
F_36 ( & V_2 -> V_8 . V_78 , V_76 ) ;
}
static int F_91 ( struct V_112 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_3 ;
V_3 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) ;
if ( V_3 & V_11 )
return V_219 ;
return F_2 ( V_2 -> V_8 . V_9 + V_12 ) ;
}
static void F_92 ( struct V_112 * V_8 ,
unsigned char V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
while ( F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_111 )
F_66 () ;
F_33 ( V_4 , V_2 -> V_8 . V_9 + V_12 ) ;
}
static int F_93 ( struct V_112 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_202 ;
int V_220 ;
V_220 = F_94 ( V_2 -> V_221 ) ;
if ( V_220 )
goto V_222;
V_220 = F_95 ( V_2 -> V_221 ) ;
if ( V_220 )
goto V_223;
V_2 -> V_8 . V_224 = F_96 ( V_2 -> V_221 ) ;
V_220 = F_97 ( V_2 -> V_8 . V_180 , F_83 , 0 , L_22 , V_2 ) ;
if ( V_220 )
goto V_225;
F_33 ( V_2 -> V_145 -> V_226 , V_2 -> V_8 . V_9 + V_227 ) ;
V_202 = V_228 | V_229 | V_212 ;
F_33 ( V_202 , V_2 -> V_8 . V_9 + V_159 ) ;
F_33 ( 0 , V_2 -> V_8 . V_9 + V_230 ) ;
F_33 ( 1 , V_2 -> V_8 . V_9 + V_231 ) ;
F_33 ( 0 , V_2 -> V_8 . V_9 + V_2 -> V_232 ) ;
if ( V_2 -> V_217 != V_2 -> V_232 ) {
int V_233 ;
for ( V_233 = 0 ; V_233 < 10 ; ++ V_233 )
F_33 ( 0xff , V_2 -> V_8 . V_9 + V_163 ) ;
F_33 ( 0 , V_2 -> V_8 . V_9 + V_2 -> V_217 ) ;
}
F_33 ( 0 , V_2 -> V_8 . V_9 + V_12 ) ;
while ( F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_150 )
F_66 () ;
V_202 = V_228 | V_234 | V_229 ;
F_33 ( V_202 , V_2 -> V_8 . V_9 + V_159 ) ;
F_33 ( V_130 | V_131 | V_132 | V_133 ,
V_2 -> V_8 . V_9 + V_134 ) ;
V_2 -> V_161 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_162 ;
F_64 ( V_2 ) ;
F_61 ( & V_2 -> V_8 . V_78 ) ;
V_2 -> V_84 = V_165 ;
if ( ! F_68 ( V_2 ) )
V_2 -> V_84 |= V_124 ;
F_33 ( V_2 -> V_84 , V_2 -> V_8 . V_9 + V_86 ) ;
F_62 ( & V_2 -> V_8 . V_78 ) ;
if ( V_2 -> V_8 . V_41 -> V_45 ) {
struct V_43 * V_44 ;
V_44 = V_2 -> V_8 . V_41 -> V_45 ;
if ( V_44 -> V_235 )
V_44 -> V_235 () ;
}
return 0 ;
V_225:
F_98 ( V_2 -> V_221 ) ;
V_223:
F_99 ( V_2 -> V_221 ) ;
V_222:
return V_220 ;
}
static void F_100 ( struct V_1 * V_2 ,
unsigned int V_236 )
{
unsigned long V_237 ;
V_237 = F_2 ( V_2 -> V_8 . V_9 + V_236 ) ;
V_237 &= ~ ( V_218 | V_238 ) ;
F_33 ( V_237 , V_2 -> V_8 . V_9 + V_236 ) ;
}
static void F_101 ( struct V_112 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
F_61 ( & V_2 -> V_8 . V_78 ) ;
V_2 -> V_84 = 0 ;
F_33 ( V_2 -> V_84 , V_2 -> V_8 . V_9 + V_86 ) ;
F_33 ( 0xffff , V_2 -> V_8 . V_9 + V_134 ) ;
F_62 ( & V_2 -> V_8 . V_78 ) ;
F_65 ( V_2 ) ;
F_102 ( V_2 -> V_8 . V_180 , V_2 ) ;
V_2 -> V_213 = false ;
F_33 ( V_228 | V_229 , V_2 -> V_8 . V_9 + V_159 ) ;
F_100 ( V_2 , V_2 -> V_232 ) ;
if ( V_2 -> V_232 != V_2 -> V_217 )
F_100 ( V_2 , V_2 -> V_217 ) ;
F_98 ( V_2 -> V_221 ) ;
F_99 ( V_2 -> V_221 ) ;
if ( V_2 -> V_8 . V_41 -> V_45 ) {
struct V_43 * V_44 ;
V_44 = V_2 -> V_8 . V_41 -> V_45 ;
if ( V_44 -> exit )
V_44 -> exit () ;
}
}
static void
F_103 ( struct V_112 * V_8 , struct V_239 * V_240 ,
struct V_239 * V_241 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
unsigned int V_216 , V_242 ;
unsigned long V_76 ;
unsigned int V_243 , V_244 , V_245 ;
if ( V_2 -> V_145 -> V_246 )
V_245 = 8 ;
else
V_245 = 16 ;
V_243 = F_104 ( V_8 , V_240 , V_241 , 0 ,
V_8 -> V_224 / V_245 ) ;
if ( V_243 > V_8 -> V_224 / 16 )
V_244 = F_105 ( V_8 -> V_224 * 8 , V_243 ) ;
else
V_244 = F_105 ( V_8 -> V_224 * 4 , V_243 ) ;
switch ( V_240 -> V_247 & V_248 ) {
case V_249 :
V_216 = V_250 ;
break;
case V_251 :
V_216 = V_252 ;
break;
case V_253 :
V_216 = V_254 ;
break;
default:
V_216 = V_255 ;
break;
}
if ( V_240 -> V_247 & V_256 )
V_216 |= V_257 ;
if ( V_240 -> V_247 & V_258 ) {
V_216 |= V_259 ;
if ( ! ( V_240 -> V_247 & V_260 ) )
V_216 |= V_261 ;
}
if ( V_2 -> V_55 > 1 )
V_216 |= V_238 ;
F_32 ( & V_8 -> V_78 , V_76 ) ;
F_106 ( V_8 , V_240 -> V_247 , V_243 ) ;
V_8 -> V_26 = V_24 | 255 ;
if ( V_240 -> V_262 & V_263 )
V_8 -> V_26 |= V_19 | V_20 ;
if ( V_240 -> V_262 & ( V_264 | V_265 ) )
V_8 -> V_26 |= V_18 ;
V_8 -> V_266 = 0 ;
if ( V_240 -> V_262 & V_267 )
V_8 -> V_266 |= V_19 | V_20 ;
if ( V_240 -> V_262 & V_268 ) {
V_8 -> V_266 |= V_18 ;
if ( V_240 -> V_262 & V_267 )
V_8 -> V_266 |= V_24 ;
}
if ( ( V_240 -> V_247 & V_269 ) == 0 )
V_8 -> V_266 |= V_13 ;
if ( F_107 ( V_8 , V_240 -> V_247 ) )
F_76 ( V_8 ) ;
V_242 = F_2 ( V_8 -> V_9 + V_159 ) ;
F_33 ( 0 , V_8 -> V_9 + V_159 ) ;
if ( V_240 -> V_247 & V_270 ) {
if ( V_242 & V_204 )
V_242 |= V_214 ;
V_242 |= V_271 ;
V_2 -> V_213 = true ;
} else {
V_242 &= ~ ( V_271 | V_214 ) ;
V_2 -> V_213 = false ;
}
if ( V_2 -> V_145 -> V_246 ) {
if ( V_243 > V_8 -> V_224 / 16 )
V_242 |= V_272 ;
else
V_242 &= ~ V_272 ;
}
F_33 ( V_244 & 0x3f , V_8 -> V_9 + V_230 ) ;
F_33 ( V_244 >> 6 , V_8 -> V_9 + V_231 ) ;
F_33 ( V_216 , V_8 -> V_9 + V_2 -> V_232 ) ;
if ( V_2 -> V_232 != V_2 -> V_217 ) {
int V_233 ;
for ( V_233 = 0 ; V_233 < 10 ; ++ V_233 )
F_33 ( 0xff , V_2 -> V_8 . V_9 + V_163 ) ;
F_33 ( V_216 , V_8 -> V_9 + V_2 -> V_217 ) ;
}
F_33 ( V_242 , V_8 -> V_9 + V_159 ) ;
F_36 ( & V_8 -> V_78 , V_76 ) ;
}
static const char * F_108 ( struct V_112 * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
return V_2 -> V_8 . type == V_273 ? V_2 -> type : NULL ;
}
static void F_109 ( struct V_112 * V_8 )
{
F_110 ( V_8 -> V_49 , V_274 ) ;
}
static int F_111 ( struct V_112 * V_8 )
{
return F_112 ( V_8 -> V_49 , V_274 , L_22 )
!= NULL ? 0 : - V_99 ;
}
static void F_113 ( struct V_112 * V_8 , int V_76 )
{
if ( V_76 & V_275 ) {
V_8 -> type = V_273 ;
F_111 ( V_8 ) ;
}
}
static int F_114 ( struct V_112 * V_8 , struct V_276 * V_277 )
{
int V_110 = 0 ;
if ( V_277 -> type != V_278 && V_277 -> type != V_273 )
V_110 = - V_42 ;
if ( V_277 -> V_180 < 0 || V_277 -> V_180 >= V_279 )
V_110 = - V_42 ;
if ( V_277 -> V_280 < 9600 )
V_110 = - V_42 ;
return V_110 ;
}
static void F_115 ( struct V_112 * V_8 , int V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
while ( F_2 ( V_2 -> V_8 . V_9 + V_10 ) & V_111 )
F_66 () ;
F_33 ( V_4 , V_2 -> V_8 . V_9 + V_12 ) ;
}
static void
F_116 ( struct V_281 * V_282 , const char * V_283 , unsigned int V_92 )
{
struct V_1 * V_2 = V_151 [ V_282 -> V_284 ] ;
unsigned int V_3 , V_242 , V_285 ;
F_95 ( V_2 -> V_221 ) ;
V_242 = F_2 ( V_2 -> V_8 . V_9 + V_159 ) ;
V_285 = V_242 & ~ V_271 ;
V_285 |= V_228 | V_229 ;
F_33 ( V_285 , V_2 -> V_8 . V_9 + V_159 ) ;
F_117 ( & V_2 -> V_8 , V_283 , V_92 , F_115 ) ;
do {
V_3 = F_2 ( V_2 -> V_8 . V_9 + V_10 ) ;
} while ( V_3 & V_150 );
F_33 ( V_242 , V_2 -> V_8 . V_9 + V_159 ) ;
F_98 ( V_2 -> V_221 ) ;
}
static void T_3
F_118 ( struct V_1 * V_2 , int * V_243 ,
int * V_22 , int * V_286 )
{
if ( F_2 ( V_2 -> V_8 . V_9 + V_159 ) & V_228 ) {
unsigned int V_216 , V_287 , V_288 ;
V_216 = F_2 ( V_2 -> V_8 . V_9 + V_2 -> V_217 ) ;
* V_22 = 'n' ;
if ( V_216 & V_259 ) {
if ( V_216 & V_261 )
* V_22 = 'e' ;
else
* V_22 = 'o' ;
}
if ( ( V_216 & 0x60 ) == V_254 )
* V_286 = 7 ;
else
* V_286 = 8 ;
V_287 = F_2 ( V_2 -> V_8 . V_9 + V_231 ) ;
V_288 = F_2 ( V_2 -> V_8 . V_9 + V_230 ) ;
* V_243 = V_2 -> V_8 . V_224 * 4 / ( 64 * V_287 + V_288 ) ;
if ( V_2 -> V_145 -> V_246 ) {
if ( F_2 ( V_2 -> V_8 . V_9 + V_159 )
& V_272 )
* V_243 *= 2 ;
}
}
}
static int T_3 F_119 ( struct V_281 * V_282 , char * V_289 )
{
struct V_1 * V_2 ;
int V_243 = 38400 ;
int V_286 = 8 ;
int V_22 = 'n' ;
int V_290 = 'n' ;
int V_110 ;
if ( V_282 -> V_284 >= V_291 )
V_282 -> V_284 = 0 ;
V_2 = V_151 [ V_282 -> V_284 ] ;
if ( ! V_2 )
return - V_292 ;
V_110 = F_94 ( V_2 -> V_221 ) ;
if ( V_110 )
return V_110 ;
if ( V_2 -> V_8 . V_41 -> V_45 ) {
struct V_43 * V_44 ;
V_44 = V_2 -> V_8 . V_41 -> V_45 ;
if ( V_44 -> V_235 )
V_44 -> V_235 () ;
}
V_2 -> V_8 . V_224 = F_96 ( V_2 -> V_221 ) ;
if ( V_289 )
F_120 ( V_289 , & V_243 , & V_22 , & V_286 , & V_290 ) ;
else
F_118 ( V_2 , & V_243 , & V_22 , & V_286 ) ;
return F_121 ( & V_2 -> V_8 , V_282 , V_243 , V_22 , V_286 , V_290 ) ;
}
static int F_122 ( struct V_293 * V_41 , const struct V_294 * V_295 )
{
struct V_1 * V_2 ;
struct V_296 * V_145 = V_295 -> V_74 ;
void T_6 * V_152 ;
int V_233 , V_110 ;
for ( V_233 = 0 ; V_233 < F_123 ( V_151 ) ; V_233 ++ )
if ( V_151 [ V_233 ] == NULL )
break;
if ( V_233 == F_123 ( V_151 ) ) {
V_110 = - V_99 ;
goto V_222;
}
V_2 = F_27 ( sizeof( struct V_1 ) , V_38 ) ;
if ( V_2 == NULL ) {
V_110 = - V_39 ;
goto V_222;
}
V_152 = F_124 ( V_41 -> V_297 . V_298 , F_125 ( & V_41 -> V_297 ) ) ;
if ( ! V_152 ) {
V_110 = - V_39 ;
goto free;
}
V_2 -> V_221 = F_126 ( & V_41 -> V_41 , NULL ) ;
if ( F_127 ( V_2 -> V_221 ) ) {
V_110 = F_128 ( V_2 -> V_221 ) ;
goto V_299;
}
V_2 -> V_145 = V_145 ;
V_2 -> V_232 = V_145 -> V_232 ;
V_2 -> V_217 = V_145 -> V_217 ;
V_2 -> V_55 = V_145 -> V_55 ;
V_2 -> V_192 = V_145 -> V_192 ;
V_2 -> V_8 . V_41 = & V_41 -> V_41 ;
V_2 -> V_8 . V_49 = V_41 -> V_297 . V_298 ;
V_2 -> V_8 . V_9 = V_152 ;
V_2 -> V_8 . V_300 = V_301 ;
V_2 -> V_8 . V_180 = V_41 -> V_180 [ 0 ] ;
V_2 -> V_8 . V_55 = V_2 -> V_55 ;
V_2 -> V_8 . V_302 = & V_303 ;
V_2 -> V_8 . V_76 = V_304 ;
V_2 -> V_8 . line = V_233 ;
F_26 ( V_2 ) ;
snprintf ( V_2 -> type , sizeof( V_2 -> type ) , L_23 , F_129 ( V_41 ) ) ;
V_151 [ V_233 ] = V_2 ;
F_130 ( V_41 , V_2 ) ;
V_110 = F_131 ( & V_305 , & V_2 -> V_8 ) ;
if ( V_110 ) {
F_130 ( V_41 , NULL ) ;
V_151 [ V_233 ] = NULL ;
F_29 ( V_2 ) ;
F_132 ( V_2 -> V_221 ) ;
V_299:
F_133 ( V_152 ) ;
free:
F_11 ( V_2 ) ;
}
V_222:
return V_110 ;
}
static int F_134 ( struct V_293 * V_41 )
{
struct V_1 * V_2 = F_135 ( V_41 ) ;
int V_233 ;
F_130 ( V_41 , NULL ) ;
F_136 ( & V_305 , & V_2 -> V_8 ) ;
for ( V_233 = 0 ; V_233 < F_123 ( V_151 ) ; V_233 ++ )
if ( V_151 [ V_233 ] == V_2 )
V_151 [ V_233 ] = NULL ;
F_29 ( V_2 ) ;
F_133 ( V_2 -> V_8 . V_9 ) ;
F_132 ( V_2 -> V_221 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_137 ( struct V_293 * V_41 , T_10 V_82 )
{
struct V_1 * V_2 = F_135 ( V_41 ) ;
if ( ! V_2 )
return - V_42 ;
return F_138 ( & V_305 , & V_2 -> V_8 ) ;
}
static int F_139 ( struct V_293 * V_41 )
{
struct V_1 * V_2 = F_135 ( V_41 ) ;
if ( ! V_2 )
return - V_42 ;
return F_140 ( & V_305 , & V_2 -> V_8 ) ;
}
static int T_3 F_141 ( void )
{
int V_110 ;
F_72 ( V_306 L_24 ) ;
V_110 = F_142 ( & V_305 ) ;
if ( V_110 == 0 ) {
V_110 = F_143 ( & V_307 ) ;
if ( V_110 )
F_144 ( & V_305 ) ;
}
return V_110 ;
}
static void T_11 F_145 ( void )
{
F_146 ( & V_307 ) ;
F_144 ( & V_305 ) ;
}
