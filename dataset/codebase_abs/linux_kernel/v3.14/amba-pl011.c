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
struct V_44 * V_45 = F_20 ( V_4 -> V_10 . V_2 ) ;
struct V_46 V_47 = {
. V_48 = V_4 -> V_10 . V_49 + V_14 ,
. V_50 = V_51 ,
. V_52 = V_53 ,
. V_54 = V_4 -> V_55 >> 1 ,
. V_56 = false ,
} ;
struct V_32 * V_33 ;
T_3 V_57 ;
V_33 = F_21 ( V_2 , L_1 ) ;
if ( ! V_33 ) {
if ( ! V_45 || ! V_45 -> V_58 ) {
F_22 ( V_4 -> V_10 . V_2 , L_2 ) ;
return;
}
F_23 ( V_57 ) ;
F_24 ( V_59 , V_57 ) ;
V_33 = F_25 ( V_57 , V_45 -> V_58 ,
V_45 -> V_60 ) ;
if ( ! V_33 ) {
F_26 ( V_4 -> V_10 . V_2 , L_3 ) ;
return;
}
}
F_27 ( V_33 , & V_47 ) ;
V_4 -> V_61 . V_33 = V_33 ;
F_22 ( V_4 -> V_10 . V_2 , L_4 ,
F_28 ( V_4 -> V_61 . V_33 ) ) ;
V_33 = F_21 ( V_2 , L_5 ) ;
if ( ! V_33 && V_45 -> V_62 ) {
V_33 = F_25 ( V_57 , V_45 -> V_58 , V_45 -> V_62 ) ;
if ( ! V_33 ) {
F_26 ( V_4 -> V_10 . V_2 , L_6 ) ;
return;
}
}
if ( V_33 ) {
struct V_46 V_63 = {
. V_64 = V_4 -> V_10 . V_49 + V_14 ,
. V_65 = V_51 ,
. V_52 = V_66 ,
. V_67 = V_4 -> V_55 >> 1 ,
. V_56 = false ,
} ;
F_27 ( V_33 , & V_63 ) ;
V_4 -> V_68 . V_33 = V_33 ;
if ( V_45 && V_45 -> V_69 ) {
if ( V_45 -> V_70 ) {
V_4 -> V_68 . V_71 = false ;
V_4 -> V_68 . V_72 = V_45 -> V_70 ;
} else {
V_4 -> V_68 . V_71 = true ;
V_4 -> V_68 . V_72 = 100 ;
}
if ( V_45 -> V_73 )
V_4 -> V_68 . V_74 =
V_45 -> V_73 ;
else
V_4 -> V_68 . V_74 = 3000 ;
} else
V_4 -> V_68 . V_71 = false ;
F_22 ( V_4 -> V_10 . V_2 , L_7 ,
F_28 ( V_4 -> V_68 . V_33 ) ) ;
}
}
static int T_4 F_29 ( void )
{
struct V_75 * V_76 , * V_77 ;
F_30 (node, tmp, &pl011_dma_uarts) {
struct V_78 * V_79 = F_31 ( V_76 , struct V_78 , V_76 ) ;
F_19 ( V_79 -> V_2 , V_79 -> V_4 ) ;
F_32 ( V_76 ) ;
F_33 ( V_79 ) ;
}
return 0 ;
}
static void F_34 ( struct V_40 * V_2 , struct V_3 * V_4 )
{
struct V_78 * V_79 = F_35 ( sizeof( struct V_78 ) , V_42 ) ;
if ( V_79 ) {
V_79 -> V_4 = V_4 ;
V_79 -> V_2 = V_2 ;
F_36 ( & V_79 -> V_76 , & V_80 ) ;
}
}
static void F_34 ( struct V_40 * V_2 , struct V_3 * V_4 )
{
F_19 ( V_2 , V_4 ) ;
}
static void F_37 ( struct V_3 * V_4 )
{
if ( V_4 -> V_61 . V_33 )
F_38 ( V_4 -> V_61 . V_33 ) ;
if ( V_4 -> V_68 . V_33 )
F_38 ( V_4 -> V_68 . V_33 ) ;
}
static void F_39 ( void * V_81 )
{
struct V_3 * V_4 = V_81 ;
struct V_82 * V_61 = & V_4 -> V_61 ;
unsigned long V_83 ;
T_1 V_84 ;
F_40 ( & V_4 -> V_10 . V_85 , V_83 ) ;
if ( V_4 -> V_61 . V_86 )
F_41 ( V_61 -> V_33 -> V_40 -> V_2 , & V_61 -> V_35 , 1 ,
V_87 ) ;
V_84 = V_4 -> V_84 ;
V_4 -> V_84 = V_84 & ~ V_88 ;
F_42 ( V_4 -> V_84 , V_4 -> V_10 . V_11 + V_89 ) ;
if ( ! ( V_84 & V_88 ) || F_43 ( & V_4 -> V_10 ) ||
F_44 ( & V_4 -> V_10 . V_90 -> V_91 ) ) {
V_4 -> V_61 . V_86 = false ;
F_45 ( & V_4 -> V_10 . V_85 , V_83 ) ;
return;
}
if ( F_46 ( V_4 ) <= 0 ) {
V_4 -> V_92 |= V_93 ;
F_42 ( V_4 -> V_92 , V_4 -> V_10 . V_11 + V_94 ) ;
}
F_45 ( & V_4 -> V_10 . V_85 , V_83 ) ;
}
static int F_46 ( struct V_3 * V_4 )
{
struct V_82 * V_61 = & V_4 -> V_61 ;
struct V_32 * V_33 = V_61 -> V_33 ;
struct V_95 * V_96 = V_33 -> V_40 ;
struct V_97 * V_98 ;
struct V_99 * V_91 = & V_4 -> V_10 . V_90 -> V_91 ;
unsigned int V_100 ;
V_100 = F_47 ( V_91 ) ;
if ( V_100 < ( V_4 -> V_55 >> 1 ) ) {
V_4 -> V_61 . V_86 = false ;
return 0 ;
}
V_100 -= 1 ;
if ( V_100 > V_41 )
V_100 = V_41 ;
if ( V_91 -> V_101 < V_91 -> V_102 )
memcpy ( & V_61 -> V_39 [ 0 ] , & V_91 -> V_39 [ V_91 -> V_101 ] , V_100 ) ;
else {
T_5 V_103 = V_104 - V_91 -> V_101 ;
T_5 V_105 = V_91 -> V_102 ;
memcpy ( & V_61 -> V_39 [ 0 ] , & V_91 -> V_39 [ V_91 -> V_101 ] , V_103 ) ;
if ( V_105 )
memcpy ( & V_61 -> V_39 [ V_103 ] , & V_91 -> V_39 [ 0 ] , V_105 ) ;
}
V_61 -> V_35 . V_106 = V_100 ;
if ( F_48 ( V_96 -> V_2 , & V_61 -> V_35 , 1 , V_87 ) != 1 ) {
V_4 -> V_61 . V_86 = false ;
F_49 ( V_4 -> V_10 . V_2 , L_8 ) ;
return - V_107 ;
}
V_98 = F_50 ( V_33 , & V_61 -> V_35 , 1 , V_53 ,
V_108 | V_109 ) ;
if ( ! V_98 ) {
F_41 ( V_96 -> V_2 , & V_61 -> V_35 , 1 , V_87 ) ;
V_4 -> V_61 . V_86 = false ;
F_49 ( V_4 -> V_10 . V_2 , L_9 ) ;
return - V_107 ;
}
V_98 -> V_110 = F_39 ;
V_98 -> V_111 = V_4 ;
F_51 ( V_98 ) ;
V_96 -> V_112 ( V_33 ) ;
V_4 -> V_84 |= V_88 ;
F_42 ( V_4 -> V_84 , V_4 -> V_10 . V_11 + V_89 ) ;
V_4 -> V_61 . V_86 = true ;
V_91 -> V_101 = ( V_91 -> V_101 + V_100 ) & ( V_104 - 1 ) ;
V_4 -> V_10 . V_17 . V_113 += V_100 ;
if ( F_47 ( V_91 ) < V_114 )
F_52 ( & V_4 -> V_10 ) ;
return 1 ;
}
static bool F_53 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_115 )
return false ;
if ( V_4 -> V_61 . V_86 ) {
V_4 -> V_84 |= V_88 ;
F_42 ( V_4 -> V_84 , V_4 -> V_10 . V_11 + V_89 ) ;
V_4 -> V_92 &= ~ V_93 ;
F_42 ( V_4 -> V_92 , V_4 -> V_10 . V_11 + V_94 ) ;
return true ;
}
if ( F_46 ( V_4 ) > 0 ) {
V_4 -> V_92 &= ~ V_93 ;
F_42 ( V_4 -> V_92 , V_4 -> V_10 . V_11 + V_94 ) ;
return true ;
}
return false ;
}
static inline void F_54 ( struct V_3 * V_4 )
{
if ( V_4 -> V_61 . V_86 ) {
V_4 -> V_84 &= ~ V_88 ;
F_42 ( V_4 -> V_84 , V_4 -> V_10 . V_11 + V_89 ) ;
}
}
static inline bool F_55 ( struct V_3 * V_4 )
{
T_1 V_84 ;
if ( ! V_4 -> V_115 )
return false ;
if ( ! V_4 -> V_10 . V_116 ) {
bool V_117 = true ;
if ( ! V_4 -> V_61 . V_86 ) {
if ( F_46 ( V_4 ) > 0 ) {
V_4 -> V_92 &= ~ V_93 ;
V_117 = true ;
} else {
V_4 -> V_92 |= V_93 ;
V_117 = false ;
}
F_42 ( V_4 -> V_92 , V_4 -> V_10 . V_11 + V_94 ) ;
} else if ( ! ( V_4 -> V_84 & V_88 ) ) {
V_4 -> V_84 |= V_88 ;
F_42 ( V_4 -> V_84 ,
V_4 -> V_10 . V_11 + V_89 ) ;
}
return V_117 ;
}
V_84 = V_4 -> V_84 ;
V_4 -> V_84 &= ~ V_88 ;
F_42 ( V_4 -> V_84 , V_4 -> V_10 . V_11 + V_89 ) ;
if ( F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_118 ) {
return false ;
}
F_42 ( V_4 -> V_10 . V_116 , V_4 -> V_10 . V_11 + V_14 ) ;
V_4 -> V_10 . V_17 . V_113 ++ ;
V_4 -> V_10 . V_116 = 0 ;
V_4 -> V_84 = V_84 ;
F_42 ( V_84 , V_4 -> V_10 . V_11 + V_89 ) ;
return true ;
}
static void F_56 ( struct V_119 * V_10 )
__releases( &uap->port.lock
static int F_57 ( struct V_3 * V_4 )
{
struct V_32 * V_120 = V_4 -> V_68 . V_33 ;
struct V_121 * V_68 = & V_4 -> V_68 ;
struct V_97 * V_98 ;
struct V_34 * V_122 ;
if ( ! V_120 )
return - V_123 ;
V_122 = V_4 -> V_68 . V_124 ?
& V_4 -> V_68 . V_125 : & V_4 -> V_68 . V_126 ;
V_98 = F_50 ( V_120 , & V_122 -> V_35 , 1 ,
V_66 ,
V_108 | V_109 ) ;
if ( ! V_98 ) {
V_4 -> V_68 . V_127 = false ;
F_58 ( V_120 ) ;
return - V_107 ;
}
V_98 -> V_110 = V_128 ;
V_98 -> V_111 = V_4 ;
V_68 -> V_129 = F_51 ( V_98 ) ;
F_59 ( V_120 ) ;
V_4 -> V_84 |= V_130 ;
F_42 ( V_4 -> V_84 , V_4 -> V_10 . V_11 + V_89 ) ;
V_4 -> V_68 . V_127 = true ;
V_4 -> V_92 &= ~ V_131 ;
F_42 ( V_4 -> V_92 , V_4 -> V_10 . V_11 + V_94 ) ;
return 0 ;
}
static void F_60 ( struct V_3 * V_4 ,
T_6 V_132 , bool V_124 ,
bool V_133 )
{
struct V_134 * V_10 = & V_4 -> V_10 . V_90 -> V_10 ;
struct V_34 * V_122 = V_124 ?
& V_4 -> V_68 . V_125 : & V_4 -> V_68 . V_126 ;
int V_135 = 0 ;
T_6 V_9 = 0 ;
struct V_121 * V_68 = & V_4 -> V_68 ;
int V_136 = 0 ;
if ( V_4 -> V_68 . V_72 ) {
V_136 = V_122 -> V_35 . V_106 - V_68 -> V_137 ;
if ( V_132 >= V_136 )
V_132 -= V_136 ;
}
if ( V_132 ) {
V_135 = F_61 ( V_10 , V_122 -> V_39 + V_136 ,
V_132 ) ;
V_4 -> V_10 . V_17 . V_18 += V_135 ;
if ( V_135 < V_132 )
F_62 ( V_4 -> V_10 . V_2 ,
L_10 ) ;
}
if ( V_4 -> V_68 . V_72 )
V_68 -> V_137 = V_122 -> V_35 . V_106 ;
if ( V_135 == V_132 && V_133 ) {
F_42 ( V_138 | V_139 | V_140 | V_141 ,
V_4 -> V_10 . V_11 + V_142 ) ;
V_9 = F_4 ( V_4 ) ;
}
F_63 ( & V_4 -> V_10 . V_85 ) ;
F_64 ( V_4 -> V_10 . V_2 ,
L_11 ,
V_135 , V_9 ) ;
F_65 ( V_10 ) ;
F_66 ( & V_4 -> V_10 . V_85 ) ;
}
static void F_67 ( struct V_3 * V_4 )
{
struct V_121 * V_68 = & V_4 -> V_68 ;
struct V_32 * V_120 = V_68 -> V_33 ;
struct V_34 * V_122 = V_68 -> V_124 ?
& V_68 -> V_125 : & V_68 -> V_126 ;
T_5 V_132 ;
struct V_143 V_90 ;
enum V_144 V_145 ;
if ( F_68 ( V_120 ) )
F_26 ( V_4 -> V_10 . V_2 , L_12 ) ;
V_145 = V_120 -> V_40 -> V_146 ( V_120 ,
V_68 -> V_129 , & V_90 ) ;
if ( V_145 != V_147 )
F_26 ( V_4 -> V_10 . V_2 , L_12 ) ;
V_4 -> V_84 &= ~ V_130 ;
F_42 ( V_4 -> V_84 , V_4 -> V_10 . V_11 + V_89 ) ;
V_4 -> V_68 . V_127 = false ;
V_132 = V_122 -> V_35 . V_106 - V_90 . V_148 ;
F_69 ( V_132 > V_41 ) ;
F_58 ( V_120 ) ;
F_60 ( V_4 , V_132 , V_68 -> V_124 , true ) ;
V_68 -> V_124 = ! V_68 -> V_124 ;
if ( F_57 ( V_4 ) ) {
F_49 ( V_4 -> V_10 . V_2 , L_13
L_14 ) ;
V_4 -> V_92 |= V_131 ;
F_42 ( V_4 -> V_92 , V_4 -> V_10 . V_11 + V_94 ) ;
}
}
static void V_128 ( void * V_81 )
{
struct V_3 * V_4 = V_81 ;
struct V_121 * V_68 = & V_4 -> V_68 ;
struct V_32 * V_120 = V_68 -> V_33 ;
bool V_149 = V_68 -> V_124 ;
struct V_34 * V_122 = V_68 -> V_124 ?
& V_68 -> V_125 : & V_68 -> V_126 ;
T_5 V_132 ;
struct V_143 V_90 ;
int V_117 ;
F_70 ( & V_4 -> V_10 . V_85 ) ;
V_120 -> V_40 -> V_146 ( V_120 , V_68 -> V_129 , & V_90 ) ;
V_132 = V_122 -> V_35 . V_106 - V_90 . V_148 ;
F_69 ( V_132 > V_41 ) ;
F_58 ( V_120 ) ;
V_4 -> V_68 . V_127 = false ;
V_68 -> V_124 = ! V_149 ;
V_117 = F_57 ( V_4 ) ;
F_60 ( V_4 , V_132 , V_149 , false ) ;
F_71 ( & V_4 -> V_10 . V_85 ) ;
if ( V_117 ) {
F_49 ( V_4 -> V_10 . V_2 , L_13
L_14 ) ;
V_4 -> V_92 |= V_131 ;
F_42 ( V_4 -> V_92 , V_4 -> V_10 . V_11 + V_94 ) ;
}
}
static inline void F_72 ( struct V_3 * V_4 )
{
V_4 -> V_84 &= ~ V_130 ;
F_42 ( V_4 -> V_84 , V_4 -> V_10 . V_11 + V_89 ) ;
}
static void F_73 ( unsigned long args )
{
struct V_3 * V_4 = (struct V_3 * ) args ;
struct V_134 * V_10 = & V_4 -> V_10 . V_90 -> V_10 ;
struct V_121 * V_68 = & V_4 -> V_68 ;
struct V_32 * V_120 = V_4 -> V_68 . V_33 ;
unsigned long V_83 = 0 ;
unsigned int V_136 = 0 ;
unsigned int V_150 = 0 ;
struct V_34 * V_122 ;
int V_135 ;
struct V_143 V_90 ;
V_122 = V_68 -> V_124 ? & V_4 -> V_68 . V_125 : & V_4 -> V_68 . V_126 ;
V_120 -> V_40 -> V_146 ( V_120 , V_68 -> V_129 , & V_90 ) ;
if ( F_74 ( V_90 . V_148 < V_68 -> V_137 ) ) {
V_136 = V_122 -> V_35 . V_106 - V_68 -> V_137 ;
V_150 = V_68 -> V_137 - V_90 . V_148 ;
V_135 = F_61 ( V_10 , V_122 -> V_39 + V_136 ,
V_150 ) ;
if ( V_135 == V_150 )
V_68 -> V_137 = V_90 . V_148 ;
V_68 -> V_151 = V_152 ;
}
F_65 ( V_10 ) ;
if ( F_75 ( V_152 - V_68 -> V_151 )
> V_4 -> V_68 . V_74 ) {
F_40 ( & V_4 -> V_10 . V_85 , V_83 ) ;
F_72 ( V_4 ) ;
V_4 -> V_92 |= V_131 ;
F_42 ( V_4 -> V_92 , V_4 -> V_10 . V_11 + V_94 ) ;
F_45 ( & V_4 -> V_10 . V_85 , V_83 ) ;
V_4 -> V_68 . V_127 = false ;
F_58 ( V_120 ) ;
F_76 ( & V_4 -> V_68 . V_153 ) ;
} else {
F_77 ( & V_4 -> V_68 . V_153 ,
V_152 + F_78 ( V_4 -> V_68 . V_72 ) ) ;
}
}
static void F_79 ( struct V_3 * V_4 )
{
int V_117 ;
if ( ! V_4 -> V_61 . V_33 )
return;
V_4 -> V_61 . V_39 = F_80 ( V_41 , V_42 ) ;
if ( ! V_4 -> V_61 . V_39 ) {
F_26 ( V_4 -> V_10 . V_2 , L_15 ) ;
V_4 -> V_10 . V_55 = V_4 -> V_55 ;
return;
}
F_81 ( & V_4 -> V_61 . V_35 , V_4 -> V_61 . V_39 , V_41 ) ;
V_4 -> V_10 . V_55 = V_41 ;
V_4 -> V_115 = true ;
if ( ! V_4 -> V_68 . V_33 )
goto V_154;
V_117 = F_10 ( V_4 -> V_68 . V_33 , & V_4 -> V_68 . V_126 ,
V_155 ) ;
if ( V_117 ) {
F_26 ( V_4 -> V_10 . V_2 , L_16 ,
L_17 , V_117 ) ;
goto V_154;
}
V_117 = F_10 ( V_4 -> V_68 . V_33 , & V_4 -> V_68 . V_125 ,
V_155 ) ;
if ( V_117 ) {
F_26 ( V_4 -> V_10 . V_2 , L_16 ,
L_18 , V_117 ) ;
F_17 ( V_4 -> V_68 . V_33 , & V_4 -> V_68 . V_126 ,
V_155 ) ;
goto V_154;
}
V_4 -> V_156 = true ;
V_154:
V_4 -> V_84 |= V_157 ;
F_42 ( V_4 -> V_84 , V_4 -> V_10 . V_11 + V_89 ) ;
if ( V_4 -> V_158 -> V_159 )
F_42 ( V_160 | V_161 ,
V_4 -> V_10 . V_11 + V_162 ) ;
if ( V_4 -> V_156 ) {
if ( F_57 ( V_4 ) )
F_49 ( V_4 -> V_10 . V_2 , L_19
L_20 ) ;
if ( V_4 -> V_68 . V_72 ) {
F_82 ( & ( V_4 -> V_68 . V_153 ) ) ;
V_4 -> V_68 . V_153 . V_163 = F_73 ;
V_4 -> V_68 . V_153 . V_81 = ( unsigned long ) V_4 ;
F_77 ( & V_4 -> V_68 . V_153 ,
V_152 +
F_78 ( V_4 -> V_68 . V_72 ) ) ;
V_4 -> V_68 . V_137 = V_41 ;
V_4 -> V_68 . V_151 = V_152 ;
}
}
}
static void F_83 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_115 || V_4 -> V_156 ) )
return;
while ( F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_164 )
F_84 () ;
F_70 ( & V_4 -> V_10 . V_85 ) ;
V_4 -> V_84 &= ~ ( V_157 | V_130 | V_88 ) ;
F_42 ( V_4 -> V_84 , V_4 -> V_10 . V_11 + V_89 ) ;
F_71 ( & V_4 -> V_10 . V_85 ) ;
if ( V_4 -> V_115 ) {
F_58 ( V_4 -> V_61 . V_33 ) ;
if ( V_4 -> V_61 . V_86 ) {
F_41 ( V_4 -> V_61 . V_33 -> V_40 -> V_2 , & V_4 -> V_61 . V_35 , 1 ,
V_87 ) ;
V_4 -> V_61 . V_86 = false ;
}
F_33 ( V_4 -> V_61 . V_39 ) ;
V_4 -> V_115 = false ;
}
if ( V_4 -> V_156 ) {
F_58 ( V_4 -> V_68 . V_33 ) ;
F_17 ( V_4 -> V_68 . V_33 , & V_4 -> V_68 . V_126 , V_155 ) ;
F_17 ( V_4 -> V_68 . V_33 , & V_4 -> V_68 . V_125 , V_155 ) ;
if ( V_4 -> V_68 . V_72 )
F_85 ( & V_4 -> V_68 . V_153 ) ;
V_4 -> V_156 = false ;
}
}
static inline bool F_86 ( struct V_3 * V_4 )
{
return V_4 -> V_156 ;
}
static inline bool F_87 ( struct V_3 * V_4 )
{
return V_4 -> V_156 && V_4 -> V_68 . V_127 ;
}
static inline void F_34 ( struct V_40 * V_2 , struct V_3 * V_4 )
{
}
static inline void F_37 ( struct V_3 * V_4 )
{
}
static inline void F_79 ( struct V_3 * V_4 )
{
}
static inline void F_83 ( struct V_3 * V_4 )
{
}
static inline bool F_53 ( struct V_3 * V_4 )
{
return false ;
}
static inline void F_54 ( struct V_3 * V_4 )
{
}
static inline bool F_55 ( struct V_3 * V_4 )
{
return false ;
}
static inline void F_67 ( struct V_3 * V_4 )
{
}
static inline void F_72 ( struct V_3 * V_4 )
{
}
static inline int F_57 ( struct V_3 * V_4 )
{
return - V_123 ;
}
static inline bool F_86 ( struct V_3 * V_4 )
{
return false ;
}
static inline bool F_87 ( struct V_3 * V_4 )
{
return false ;
}
static void F_88 ( struct V_119 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
V_4 -> V_92 &= ~ V_93 ;
F_42 ( V_4 -> V_92 , V_4 -> V_10 . V_11 + V_94 ) ;
F_54 ( V_4 ) ;
}
static void F_89 ( struct V_119 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
if ( ! F_55 ( V_4 ) ) {
V_4 -> V_92 |= V_93 ;
F_42 ( V_4 -> V_92 , V_4 -> V_10 . V_11 + V_94 ) ;
}
}
static void F_90 ( struct V_119 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
V_4 -> V_92 &= ~ ( V_131 | V_165 | V_166 |
V_167 | V_168 | V_169 ) ;
F_42 ( V_4 -> V_92 , V_4 -> V_10 . V_11 + V_94 ) ;
F_72 ( V_4 ) ;
}
static void F_91 ( struct V_119 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
V_4 -> V_92 |= V_170 | V_171 | V_172 | V_173 ;
F_42 ( V_4 -> V_92 , V_4 -> V_10 . V_11 + V_94 ) ;
}
static void F_92 ( struct V_3 * V_4 )
__releases( &uap->port.lock
static void F_93 ( struct V_3 * V_4 )
{
struct V_99 * V_91 = & V_4 -> V_10 . V_90 -> V_91 ;
int V_100 ;
if ( V_4 -> V_10 . V_116 ) {
F_42 ( V_4 -> V_10 . V_116 , V_4 -> V_10 . V_11 + V_14 ) ;
V_4 -> V_10 . V_17 . V_113 ++ ;
V_4 -> V_10 . V_116 = 0 ;
return;
}
if ( F_44 ( V_91 ) || F_43 ( & V_4 -> V_10 ) ) {
F_88 ( & V_4 -> V_10 ) ;
return;
}
if ( F_53 ( V_4 ) )
return;
V_100 = V_4 -> V_55 >> 1 ;
do {
F_42 ( V_91 -> V_39 [ V_91 -> V_101 ] , V_4 -> V_10 . V_11 + V_14 ) ;
V_91 -> V_101 = ( V_91 -> V_101 + 1 ) & ( V_104 - 1 ) ;
V_4 -> V_10 . V_17 . V_113 ++ ;
if ( F_44 ( V_91 ) )
break;
} while ( -- V_100 > 0 );
if ( F_47 ( V_91 ) < V_114 )
F_52 ( & V_4 -> V_10 ) ;
if ( F_44 ( V_91 ) )
F_88 ( & V_4 -> V_10 ) ;
}
static void F_94 ( struct V_3 * V_4 )
{
unsigned int V_5 , V_174 ;
V_5 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_175 ;
V_174 = V_5 ^ V_4 -> V_176 ;
V_4 -> V_176 = V_5 ;
if ( ! V_174 )
return;
if ( V_174 & V_177 )
F_95 ( & V_4 -> V_10 , V_5 & V_177 ) ;
if ( V_174 & V_178 )
V_4 -> V_10 . V_17 . V_179 ++ ;
if ( V_174 & V_180 )
F_96 ( & V_4 -> V_10 , V_5 & V_180 ) ;
F_97 ( & V_4 -> V_10 . V_90 -> V_10 . V_181 ) ;
}
static T_7 F_98 ( int V_182 , void * V_183 )
{
struct V_3 * V_4 = V_183 ;
unsigned long V_83 ;
unsigned int V_5 , V_184 = V_185 ;
int V_186 = 0 ;
unsigned int V_187 ;
F_40 ( & V_4 -> V_10 . V_85 , V_83 ) ;
V_5 = F_5 ( V_4 -> V_10 . V_11 + V_188 ) ;
if ( V_5 ) {
do {
if ( V_4 -> V_158 -> V_189 ) {
F_42 ( 0x00 , V_4 -> V_10 . V_11 + V_142 ) ;
V_187 = F_5 ( V_4 -> V_10 . V_11 + V_142 ) ;
V_187 = F_5 ( V_4 -> V_10 . V_11 + V_142 ) ;
}
F_42 ( V_5 & ~ ( V_190 | V_191 |
V_192 ) ,
V_4 -> V_10 . V_11 + V_142 ) ;
if ( V_5 & ( V_191 | V_192 ) ) {
if ( F_87 ( V_4 ) )
F_67 ( V_4 ) ;
else
F_92 ( V_4 ) ;
}
if ( V_5 & ( V_193 | V_194 |
V_195 | V_196 ) )
F_94 ( V_4 ) ;
if ( V_5 & V_190 )
F_93 ( V_4 ) ;
if ( V_184 -- == 0 )
break;
V_5 = F_5 ( V_4 -> V_10 . V_11 + V_188 ) ;
} while ( V_5 != 0 );
V_186 = 1 ;
}
F_45 ( & V_4 -> V_10 . V_85 , V_83 ) ;
return F_99 ( V_186 ) ;
}
static unsigned int F_100 ( struct V_119 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned int V_5 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) ;
return V_5 & ( V_164 | V_118 ) ? 0 : V_197 ;
}
static unsigned int F_101 ( struct V_119 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned int V_198 = 0 ;
unsigned int V_5 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) ;
#define F_102 ( T_8 , T_9 ) \
if (status & uartbit) \
result |= tiocmbit
F_102 ( V_177 , V_199 ) ;
F_102 ( V_178 , V_200 ) ;
F_102 ( V_180 , V_201 ) ;
F_102 ( V_202 , V_203 ) ;
#undef F_102
return V_198 ;
}
static void F_103 ( struct V_119 * V_10 , unsigned int V_204 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned int V_205 ;
V_205 = F_5 ( V_4 -> V_10 . V_11 + V_206 ) ;
#define F_102 ( T_9 , T_8 ) \
if (mctrl & tiocmbit) \
cr |= uartbit; \
else \
cr &= ~uartbit
F_102 ( V_207 , V_208 ) ;
F_102 ( V_209 , V_210 ) ;
F_102 ( V_211 , V_212 ) ;
F_102 ( V_213 , V_214 ) ;
F_102 ( V_215 , V_216 ) ;
if ( V_4 -> V_217 ) {
F_102 ( V_207 , V_218 ) ;
}
#undef F_102
F_42 ( V_205 , V_4 -> V_10 . V_11 + V_206 ) ;
}
static void F_104 ( struct V_119 * V_10 , int V_219 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned long V_83 ;
unsigned int V_220 ;
F_40 ( & V_4 -> V_10 . V_85 , V_83 ) ;
V_220 = F_5 ( V_4 -> V_10 . V_11 + V_4 -> V_221 ) ;
if ( V_219 == - 1 )
V_220 |= V_222 ;
else
V_220 &= ~ V_222 ;
F_42 ( V_220 , V_4 -> V_10 . V_11 + V_4 -> V_221 ) ;
F_45 ( & V_4 -> V_10 . V_85 , V_83 ) ;
}
static void F_105 ( struct V_119 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned char T_10 * V_223 = V_4 -> V_10 . V_11 ;
F_42 ( F_5 ( V_223 + V_188 ) , V_223 + V_142 ) ;
F_42 ( F_5 ( V_223 + V_94 ) & ~ V_93 , V_223 + V_94 ) ;
}
static int F_106 ( struct V_119 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned int V_5 ;
F_105 ( V_10 ) ;
V_5 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) ;
if ( V_5 & V_13 )
return V_224 ;
return F_5 ( V_4 -> V_10 . V_11 + V_14 ) ;
}
static void F_107 ( struct V_119 * V_10 ,
unsigned char V_6 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
while ( F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_118 )
F_84 () ;
F_42 ( V_6 , V_4 -> V_10 . V_11 + V_14 ) ;
}
static int F_108 ( struct V_119 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
int V_225 ;
F_109 ( V_10 -> V_2 ) ;
V_225 = F_110 ( V_4 -> V_226 ) ;
if ( V_225 )
goto V_227;
V_4 -> V_10 . V_228 = F_111 ( V_4 -> V_226 ) ;
F_42 ( V_138 | V_139 | V_140 | V_141 |
V_191 | V_192 , V_4 -> V_10 . V_11 + V_142 ) ;
V_4 -> V_92 = F_5 ( V_4 -> V_10 . V_11 + V_94 ) ;
F_42 ( V_165 | V_131 , V_4 -> V_10 . V_11 + V_94 ) ;
if ( F_20 ( V_4 -> V_10 . V_2 ) ) {
struct V_44 * V_45 ;
V_45 = F_20 ( V_4 -> V_10 . V_2 ) ;
if ( V_45 -> V_229 )
V_45 -> V_229 () ;
}
return 0 ;
V_227:
return V_225 ;
}
static void F_112 ( struct V_3 * V_4 , unsigned int V_220 )
{
F_42 ( V_220 , V_4 -> V_10 . V_11 + V_4 -> V_230 ) ;
if ( V_4 -> V_230 != V_4 -> V_221 ) {
int V_231 ;
for ( V_231 = 0 ; V_231 < 10 ; ++ V_231 )
F_42 ( 0xff , V_4 -> V_10 . V_11 + V_188 ) ;
F_42 ( V_220 , V_4 -> V_10 . V_11 + V_4 -> V_221 ) ;
}
}
static int F_113 ( struct V_119 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned int V_205 , V_220 , V_232 , V_233 ;
int V_225 ;
V_225 = F_108 ( V_10 ) ;
if ( V_225 )
goto V_234;
F_42 ( V_4 -> V_92 , V_4 -> V_10 . V_11 + V_94 ) ;
V_225 = F_114 ( V_4 -> V_10 . V_182 , F_98 , 0 , L_21 , V_4 ) ;
if ( V_225 )
goto V_234;
F_42 ( V_4 -> V_158 -> V_235 , V_4 -> V_10 . V_11 + V_236 ) ;
F_70 ( & V_4 -> V_10 . V_85 ) ;
V_232 = F_5 ( V_4 -> V_10 . V_11 + V_237 ) ;
V_233 = F_5 ( V_4 -> V_10 . V_11 + V_238 ) ;
V_220 = F_5 ( V_4 -> V_10 . V_11 + V_4 -> V_230 ) ;
V_205 = V_239 | V_240 | V_216 ;
F_42 ( V_205 , V_4 -> V_10 . V_11 + V_206 ) ;
F_42 ( 0 , V_4 -> V_10 . V_11 + V_237 ) ;
F_42 ( 1 , V_4 -> V_10 . V_11 + V_238 ) ;
F_112 ( V_4 , 0 ) ;
F_42 ( 0 , V_4 -> V_10 . V_11 + V_14 ) ;
while ( F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_164 )
F_84 () ;
F_42 ( V_232 , V_4 -> V_10 . V_11 + V_237 ) ;
F_42 ( V_233 , V_4 -> V_10 . V_11 + V_238 ) ;
F_112 ( V_4 , V_220 ) ;
V_205 = V_4 -> V_241 & ( V_208 | V_210 ) ;
V_205 |= V_239 | V_242 | V_240 ;
F_42 ( V_205 , V_4 -> V_10 . V_11 + V_206 ) ;
F_71 ( & V_4 -> V_10 . V_85 ) ;
V_4 -> V_176 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_175 ;
F_79 ( V_4 ) ;
F_70 ( & V_4 -> V_10 . V_85 ) ;
F_42 ( V_191 | V_192 ,
V_4 -> V_10 . V_11 + V_142 ) ;
V_4 -> V_92 = V_165 ;
if ( ! F_87 ( V_4 ) )
V_4 -> V_92 |= V_131 ;
F_42 ( V_4 -> V_92 , V_4 -> V_10 . V_11 + V_94 ) ;
F_71 ( & V_4 -> V_10 . V_85 ) ;
return 0 ;
V_234:
F_115 ( V_4 -> V_226 ) ;
return V_225 ;
}
static void F_116 ( struct V_3 * V_4 ,
unsigned int V_243 )
{
unsigned long V_244 ;
V_244 = F_5 ( V_4 -> V_10 . V_11 + V_243 ) ;
V_244 &= ~ ( V_222 | V_245 ) ;
F_42 ( V_244 , V_4 -> V_10 . V_11 + V_243 ) ;
}
static void F_117 ( struct V_119 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned int V_205 ;
F_70 ( & V_4 -> V_10 . V_85 ) ;
V_4 -> V_92 = 0 ;
F_42 ( V_4 -> V_92 , V_4 -> V_10 . V_11 + V_94 ) ;
F_42 ( 0xffff , V_4 -> V_10 . V_11 + V_142 ) ;
F_71 ( & V_4 -> V_10 . V_85 ) ;
F_83 ( V_4 ) ;
F_118 ( V_4 -> V_10 . V_182 , V_4 ) ;
V_4 -> V_217 = false ;
F_70 ( & V_4 -> V_10 . V_85 ) ;
V_205 = F_5 ( V_4 -> V_10 . V_11 + V_206 ) ;
V_4 -> V_241 = V_205 ;
V_205 &= V_208 | V_210 ;
V_205 |= V_239 | V_240 ;
F_42 ( V_205 , V_4 -> V_10 . V_11 + V_206 ) ;
F_71 ( & V_4 -> V_10 . V_85 ) ;
F_116 ( V_4 , V_4 -> V_230 ) ;
if ( V_4 -> V_230 != V_4 -> V_221 )
F_116 ( V_4 , V_4 -> V_221 ) ;
F_115 ( V_4 -> V_226 ) ;
F_119 ( V_10 -> V_2 ) ;
if ( F_20 ( V_4 -> V_10 . V_2 ) ) {
struct V_44 * V_45 ;
V_45 = F_20 ( V_4 -> V_10 . V_2 ) ;
if ( V_45 -> exit )
V_45 -> exit () ;
}
}
static void
F_120 ( struct V_119 * V_10 , struct V_246 * V_247 ,
struct V_246 * V_248 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
unsigned int V_220 , V_241 ;
unsigned long V_83 ;
unsigned int V_249 , V_250 , V_251 ;
if ( V_4 -> V_158 -> V_252 )
V_251 = 8 ;
else
V_251 = 16 ;
V_249 = F_121 ( V_10 , V_247 , V_248 , 0 ,
V_10 -> V_228 / V_251 ) ;
#ifdef F_122
if ( V_4 -> V_68 . V_71 )
V_4 -> V_68 . V_72 = F_123 ( 10000000 , V_249 ) ;
#endif
if ( V_249 > V_10 -> V_228 / 16 )
V_250 = F_124 ( V_10 -> V_228 * 8 , V_249 ) ;
else
V_250 = F_124 ( V_10 -> V_228 * 4 , V_249 ) ;
switch ( V_247 -> V_253 & V_254 ) {
case V_255 :
V_220 = V_256 ;
break;
case V_257 :
V_220 = V_258 ;
break;
case V_259 :
V_220 = V_260 ;
break;
default:
V_220 = V_261 ;
break;
}
if ( V_247 -> V_253 & V_262 )
V_220 |= V_263 ;
if ( V_247 -> V_253 & V_264 ) {
V_220 |= V_265 ;
if ( ! ( V_247 -> V_253 & V_266 ) )
V_220 |= V_267 ;
}
if ( V_4 -> V_55 > 1 )
V_220 |= V_245 ;
F_40 ( & V_10 -> V_85 , V_83 ) ;
F_125 ( V_10 , V_247 -> V_253 , V_249 ) ;
V_10 -> V_28 = V_26 | 255 ;
if ( V_247 -> V_268 & V_269 )
V_10 -> V_28 |= V_21 | V_22 ;
if ( V_247 -> V_268 & ( V_270 | V_271 ) )
V_10 -> V_28 |= V_20 ;
V_10 -> V_272 = 0 ;
if ( V_247 -> V_268 & V_273 )
V_10 -> V_272 |= V_21 | V_22 ;
if ( V_247 -> V_268 & V_274 ) {
V_10 -> V_272 |= V_20 ;
if ( V_247 -> V_268 & V_273 )
V_10 -> V_272 |= V_26 ;
}
if ( ( V_247 -> V_253 & V_275 ) == 0 )
V_10 -> V_272 |= V_15 ;
if ( F_126 ( V_10 , V_247 -> V_253 ) )
F_91 ( V_10 ) ;
V_241 = F_5 ( V_10 -> V_11 + V_206 ) ;
F_42 ( 0 , V_10 -> V_11 + V_206 ) ;
if ( V_247 -> V_253 & V_276 ) {
if ( V_241 & V_208 )
V_241 |= V_218 ;
V_241 |= V_277 ;
V_4 -> V_217 = true ;
} else {
V_241 &= ~ ( V_277 | V_218 ) ;
V_4 -> V_217 = false ;
}
if ( V_4 -> V_158 -> V_252 ) {
if ( V_249 > V_10 -> V_228 / 16 )
V_241 |= V_278 ;
else
V_241 &= ~ V_278 ;
}
if ( V_4 -> V_158 -> V_252 ) {
if ( ( V_249 >= 3000000 ) && ( V_249 < 3250000 ) && ( V_250 > 1 ) )
V_250 -= 1 ;
else if ( ( V_249 > 3250000 ) && ( V_250 > 2 ) )
V_250 -= 2 ;
}
F_42 ( V_250 & 0x3f , V_10 -> V_11 + V_237 ) ;
F_42 ( V_250 >> 6 , V_10 -> V_11 + V_238 ) ;
F_112 ( V_4 , V_220 ) ;
F_42 ( V_241 , V_10 -> V_11 + V_206 ) ;
F_45 ( & V_10 -> V_85 , V_83 ) ;
}
static const char * F_127 ( struct V_119 * V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
return V_4 -> V_10 . type == V_279 ? V_4 -> type : NULL ;
}
static void F_128 ( struct V_119 * V_10 )
{
F_129 ( V_10 -> V_49 , V_280 ) ;
}
static int F_130 ( struct V_119 * V_10 )
{
return F_131 ( V_10 -> V_49 , V_280 , L_21 )
!= NULL ? 0 : - V_107 ;
}
static void F_132 ( struct V_119 * V_10 , int V_83 )
{
if ( V_83 & V_281 ) {
V_10 -> type = V_279 ;
F_130 ( V_10 ) ;
}
}
static int F_133 ( struct V_119 * V_10 , struct V_282 * V_283 )
{
int V_117 = 0 ;
if ( V_283 -> type != V_284 && V_283 -> type != V_279 )
V_117 = - V_285 ;
if ( V_283 -> V_182 < 0 || V_283 -> V_182 >= V_286 )
V_117 = - V_285 ;
if ( V_283 -> V_287 < 9600 )
V_117 = - V_285 ;
return V_117 ;
}
static void F_134 ( struct V_119 * V_10 , int V_6 )
{
struct V_3 * V_4 = (struct V_3 * ) V_10 ;
while ( F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_118 )
F_84 () ;
F_42 ( V_6 , V_4 -> V_10 . V_11 + V_14 ) ;
}
static void
F_135 ( struct V_288 * V_289 , const char * V_290 , unsigned int V_100 )
{
struct V_3 * V_4 = V_291 [ V_289 -> V_292 ] ;
unsigned int V_5 , V_241 , V_293 ;
unsigned long V_83 ;
int V_294 = 1 ;
F_136 ( V_4 -> V_226 ) ;
F_137 ( V_83 ) ;
if ( V_4 -> V_10 . V_295 )
V_294 = 0 ;
else if ( V_296 )
V_294 = F_138 ( & V_4 -> V_10 . V_85 ) ;
else
F_66 ( & V_4 -> V_10 . V_85 ) ;
V_241 = F_5 ( V_4 -> V_10 . V_11 + V_206 ) ;
V_293 = V_241 & ~ V_277 ;
V_293 |= V_239 | V_240 ;
F_42 ( V_293 , V_4 -> V_10 . V_11 + V_206 ) ;
F_139 ( & V_4 -> V_10 , V_290 , V_100 , F_134 ) ;
do {
V_5 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) ;
} while ( V_5 & V_164 );
F_42 ( V_241 , V_4 -> V_10 . V_11 + V_206 ) ;
if ( V_294 )
F_63 ( & V_4 -> V_10 . V_85 ) ;
F_140 ( V_83 ) ;
F_141 ( V_4 -> V_226 ) ;
}
static void T_4
F_142 ( struct V_3 * V_4 , int * V_249 ,
int * V_24 , int * V_297 )
{
if ( F_5 ( V_4 -> V_10 . V_11 + V_206 ) & V_239 ) {
unsigned int V_220 , V_233 , V_232 ;
V_220 = F_5 ( V_4 -> V_10 . V_11 + V_4 -> V_221 ) ;
* V_24 = 'n' ;
if ( V_220 & V_265 ) {
if ( V_220 & V_267 )
* V_24 = 'e' ;
else
* V_24 = 'o' ;
}
if ( ( V_220 & 0x60 ) == V_260 )
* V_297 = 7 ;
else
* V_297 = 8 ;
V_233 = F_5 ( V_4 -> V_10 . V_11 + V_238 ) ;
V_232 = F_5 ( V_4 -> V_10 . V_11 + V_237 ) ;
* V_249 = V_4 -> V_10 . V_228 * 4 / ( 64 * V_233 + V_232 ) ;
if ( V_4 -> V_158 -> V_252 ) {
if ( F_5 ( V_4 -> V_10 . V_11 + V_206 )
& V_278 )
* V_249 *= 2 ;
}
}
}
static int T_4 F_143 ( struct V_288 * V_289 , char * V_298 )
{
struct V_3 * V_4 ;
int V_249 = 38400 ;
int V_297 = 8 ;
int V_24 = 'n' ;
int V_299 = 'n' ;
int V_117 ;
if ( V_289 -> V_292 >= V_300 )
V_289 -> V_292 = 0 ;
V_4 = V_291 [ V_289 -> V_292 ] ;
if ( ! V_4 )
return - V_301 ;
F_109 ( V_4 -> V_10 . V_2 ) ;
V_117 = F_144 ( V_4 -> V_226 ) ;
if ( V_117 )
return V_117 ;
if ( F_20 ( V_4 -> V_10 . V_2 ) ) {
struct V_44 * V_45 ;
V_45 = F_20 ( V_4 -> V_10 . V_2 ) ;
if ( V_45 -> V_229 )
V_45 -> V_229 () ;
}
V_4 -> V_10 . V_228 = F_111 ( V_4 -> V_226 ) ;
if ( V_298 )
F_145 ( V_298 , & V_249 , & V_24 , & V_297 , & V_299 ) ;
else
F_142 ( V_4 , & V_249 , & V_24 , & V_297 ) ;
return F_146 ( & V_4 -> V_10 , V_289 , V_249 , V_24 , V_297 , V_299 ) ;
}
static int F_147 ( int V_292 , struct V_40 * V_2 )
{
struct V_302 * V_303 ;
static bool V_304 = false ;
static bool V_305 = false ;
int V_117 = V_292 ;
if ( ! F_148 ( V_306 ) )
return V_117 ;
V_303 = V_2 -> V_307 ;
if ( ! V_303 )
return V_117 ;
V_117 = F_149 ( V_303 , L_22 ) ;
if ( F_150 ( V_117 ) ) {
V_305 = true ;
V_117 = V_292 ;
} else {
V_304 = true ;
if ( V_117 >= F_151 ( V_291 ) || V_291 [ V_117 ] != NULL ) {
F_62 ( V_2 , L_23 , V_117 ) ;
V_117 = V_292 ;
}
}
if ( V_304 && V_305 )
F_62 ( V_2 , L_24 ) ;
return V_117 ;
}
static int F_152 ( struct V_1 * V_2 , const struct V_308 * V_309 )
{
struct V_3 * V_4 ;
struct V_310 * V_158 = V_309 -> V_81 ;
void T_10 * V_311 ;
int V_231 , V_117 ;
for ( V_231 = 0 ; V_231 < F_151 ( V_291 ) ; V_231 ++ )
if ( V_291 [ V_231 ] == NULL )
break;
if ( V_231 == F_151 ( V_291 ) ) {
V_117 = - V_107 ;
goto V_227;
}
V_4 = F_153 ( & V_2 -> V_2 , sizeof( struct V_3 ) ,
V_42 ) ;
if ( V_4 == NULL ) {
V_117 = - V_43 ;
goto V_227;
}
V_231 = F_147 ( V_231 , & V_2 -> V_2 ) ;
V_311 = F_154 ( & V_2 -> V_2 , V_2 -> V_312 . V_313 ,
F_155 ( & V_2 -> V_312 ) ) ;
if ( ! V_311 ) {
V_117 = - V_43 ;
goto V_227;
}
V_4 -> V_226 = F_156 ( & V_2 -> V_2 , NULL ) ;
if ( F_157 ( V_4 -> V_226 ) ) {
V_117 = F_158 ( V_4 -> V_226 ) ;
goto V_227;
}
V_4 -> V_158 = V_158 ;
V_4 -> V_230 = V_158 -> V_230 ;
V_4 -> V_221 = V_158 -> V_221 ;
V_4 -> V_241 = 0 ;
V_4 -> V_55 = V_158 -> V_314 ( V_2 ) ;
V_4 -> V_10 . V_2 = & V_2 -> V_2 ;
V_4 -> V_10 . V_49 = V_2 -> V_312 . V_313 ;
V_4 -> V_10 . V_11 = V_311 ;
V_4 -> V_10 . V_315 = V_316 ;
V_4 -> V_10 . V_182 = V_2 -> V_182 [ 0 ] ;
V_4 -> V_10 . V_55 = V_4 -> V_55 ;
V_4 -> V_10 . V_317 = & V_318 ;
V_4 -> V_10 . V_83 = V_319 ;
V_4 -> V_10 . line = V_231 ;
F_34 ( & V_2 -> V_2 , V_4 ) ;
F_42 ( 0 , V_4 -> V_10 . V_11 + V_94 ) ;
F_42 ( 0xffff , V_4 -> V_10 . V_11 + V_142 ) ;
snprintf ( V_4 -> type , sizeof( V_4 -> type ) , L_25 , F_2 ( V_2 ) ) ;
V_291 [ V_231 ] = V_4 ;
F_159 ( V_2 , V_4 ) ;
V_117 = F_160 ( & V_320 , & V_4 -> V_10 ) ;
if ( V_117 ) {
V_291 [ V_231 ] = NULL ;
F_37 ( V_4 ) ;
}
V_227:
return V_117 ;
}
static int F_161 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_162 ( V_2 ) ;
int V_231 ;
F_163 ( & V_320 , & V_4 -> V_10 ) ;
for ( V_231 = 0 ; V_231 < F_151 ( V_291 ) ; V_231 ++ )
if ( V_291 [ V_231 ] == V_4 )
V_291 [ V_231 ] = NULL ;
F_37 ( V_4 ) ;
return 0 ;
}
static int F_164 ( struct V_40 * V_2 )
{
struct V_3 * V_4 = F_165 ( V_2 ) ;
if ( ! V_4 )
return - V_285 ;
return F_166 ( & V_320 , & V_4 -> V_10 ) ;
}
static int F_167 ( struct V_40 * V_2 )
{
struct V_3 * V_4 = F_165 ( V_2 ) ;
if ( ! V_4 )
return - V_285 ;
return F_168 ( & V_320 , & V_4 -> V_10 ) ;
}
static int T_4 F_169 ( void )
{
int V_117 ;
F_170 ( V_321 L_26 ) ;
V_117 = F_171 ( & V_320 ) ;
if ( V_117 == 0 ) {
V_117 = F_172 ( & V_322 ) ;
if ( V_117 )
F_173 ( & V_320 ) ;
}
return V_117 ;
}
static void T_11 F_174 ( void )
{
F_175 ( & V_322 ) ;
F_173 ( & V_320 ) ;
}
