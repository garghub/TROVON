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
static void F_20 ( struct V_3 * V_4 )
{
struct V_44 * V_45 = F_21 ( V_4 -> V_10 . V_2 ) ;
struct V_40 * V_2 = V_4 -> V_10 . V_2 ;
struct V_46 V_47 = {
. V_48 = V_4 -> V_10 . V_49 + V_14 ,
. V_50 = V_51 ,
. V_52 = V_53 ,
. V_54 = V_4 -> V_55 >> 1 ,
. V_56 = false ,
} ;
struct V_32 * V_33 ;
T_3 V_57 ;
V_4 -> V_58 = true ;
V_33 = F_22 ( V_2 , L_1 ) ;
if ( F_23 ( V_33 ) ) {
if ( F_24 ( V_33 ) == - V_59 ) {
V_4 -> V_58 = false ;
return;
}
if ( ! V_45 || ! V_45 -> V_60 ) {
F_25 ( V_4 -> V_10 . V_2 , L_2 ) ;
return;
}
F_26 ( V_57 ) ;
F_27 ( V_61 , V_57 ) ;
V_33 = F_28 ( V_57 , V_45 -> V_60 ,
V_45 -> V_62 ) ;
if ( ! V_33 ) {
F_29 ( V_4 -> V_10 . V_2 , L_3 ) ;
return;
}
}
F_30 ( V_33 , & V_47 ) ;
V_4 -> V_63 . V_33 = V_33 ;
F_25 ( V_4 -> V_10 . V_2 , L_4 ,
F_31 ( V_4 -> V_63 . V_33 ) ) ;
V_33 = F_32 ( V_2 , L_5 ) ;
if ( ! V_33 && V_45 -> V_64 ) {
V_33 = F_28 ( V_57 , V_45 -> V_60 , V_45 -> V_64 ) ;
if ( ! V_33 ) {
F_29 ( V_4 -> V_10 . V_2 , L_6 ) ;
return;
}
}
if ( V_33 ) {
struct V_46 V_65 = {
. V_66 = V_4 -> V_10 . V_49 + V_14 ,
. V_67 = V_51 ,
. V_52 = V_68 ,
. V_69 = V_4 -> V_55 >> 2 ,
. V_56 = false ,
} ;
struct V_70 V_71 ;
if ( 0 == F_33 ( V_33 , & V_71 ) ) {
if ( V_71 . V_72 ==
V_73 ) {
F_34 ( V_33 ) ;
F_25 ( V_4 -> V_10 . V_2 ,
L_7 ) ;
return;
}
}
F_30 ( V_33 , & V_65 ) ;
V_4 -> V_74 . V_33 = V_33 ;
V_4 -> V_74 . V_75 = false ;
if ( V_45 && V_45 -> V_76 ) {
if ( V_45 -> V_77 ) {
V_4 -> V_74 . V_75 = false ;
V_4 -> V_74 . V_78 = V_45 -> V_77 ;
} else {
V_4 -> V_74 . V_75 = true ;
V_4 -> V_74 . V_78 = 100 ;
}
if ( V_45 -> V_79 )
V_4 -> V_74 . V_80 =
V_45 -> V_79 ;
else
V_4 -> V_74 . V_80 = 3000 ;
} else if ( ! V_45 && V_2 -> V_81 ) {
V_4 -> V_74 . V_75 = F_35 (
V_2 -> V_81 , L_8 ) ;
if ( V_4 -> V_74 . V_75 ) {
T_4 V_82 ;
if ( 0 == F_36 ( V_2 -> V_81 ,
L_9 , & V_82 ) )
V_4 -> V_74 . V_78 = V_82 ;
else
V_4 -> V_74 . V_78 = 100 ;
if ( 0 == F_36 ( V_2 -> V_81 ,
L_10 , & V_82 ) )
V_4 -> V_74 . V_80 = V_82 ;
else
V_4 -> V_74 . V_80 = 3000 ;
}
}
F_25 ( V_4 -> V_10 . V_2 , L_11 ,
F_31 ( V_4 -> V_74 . V_33 ) ) ;
}
}
static void F_37 ( struct V_3 * V_4 )
{
if ( V_4 -> V_63 . V_33 )
F_34 ( V_4 -> V_63 . V_33 ) ;
if ( V_4 -> V_74 . V_33 )
F_34 ( V_4 -> V_74 . V_33 ) ;
}
static void F_38 ( void * V_83 )
{
struct V_3 * V_4 = V_83 ;
struct V_84 * V_63 = & V_4 -> V_63 ;
unsigned long V_85 ;
T_1 V_86 ;
F_39 ( & V_4 -> V_10 . V_87 , V_85 ) ;
if ( V_4 -> V_63 . V_88 )
F_40 ( V_63 -> V_33 -> V_40 -> V_2 , & V_63 -> V_35 , 1 ,
V_89 ) ;
V_86 = V_4 -> V_86 ;
V_4 -> V_86 = V_86 & ~ V_90 ;
F_41 ( V_4 -> V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
if ( ! ( V_86 & V_90 ) || F_42 ( & V_4 -> V_10 ) ||
F_43 ( & V_4 -> V_10 . V_92 -> V_93 ) ) {
V_4 -> V_63 . V_88 = false ;
F_44 ( & V_4 -> V_10 . V_87 , V_85 ) ;
return;
}
if ( F_45 ( V_4 ) <= 0 )
F_46 ( V_4 ) ;
F_44 ( & V_4 -> V_10 . V_87 , V_85 ) ;
}
static int F_45 ( struct V_3 * V_4 )
{
struct V_84 * V_63 = & V_4 -> V_63 ;
struct V_32 * V_33 = V_63 -> V_33 ;
struct V_94 * V_95 = V_33 -> V_40 ;
struct V_96 * V_97 ;
struct V_98 * V_93 = & V_4 -> V_10 . V_92 -> V_93 ;
unsigned int V_99 ;
V_99 = F_47 ( V_93 ) ;
if ( V_99 < ( V_4 -> V_55 >> 1 ) ) {
V_4 -> V_63 . V_88 = false ;
return 0 ;
}
V_99 -= 1 ;
if ( V_99 > V_41 )
V_99 = V_41 ;
if ( V_93 -> V_100 < V_93 -> V_101 )
memcpy ( & V_63 -> V_39 [ 0 ] , & V_93 -> V_39 [ V_93 -> V_100 ] , V_99 ) ;
else {
T_5 V_102 = V_103 - V_93 -> V_100 ;
T_5 V_104 ;
if ( V_102 > V_99 )
V_102 = V_99 ;
V_104 = V_99 - V_102 ;
memcpy ( & V_63 -> V_39 [ 0 ] , & V_93 -> V_39 [ V_93 -> V_100 ] , V_102 ) ;
if ( V_104 )
memcpy ( & V_63 -> V_39 [ V_102 ] , & V_93 -> V_39 [ 0 ] , V_104 ) ;
}
V_63 -> V_35 . V_105 = V_99 ;
if ( F_48 ( V_95 -> V_2 , & V_63 -> V_35 , 1 , V_89 ) != 1 ) {
V_4 -> V_63 . V_88 = false ;
F_49 ( V_4 -> V_10 . V_2 , L_12 ) ;
return - V_106 ;
}
V_97 = F_50 ( V_33 , & V_63 -> V_35 , 1 , V_53 ,
V_107 | V_108 ) ;
if ( ! V_97 ) {
F_40 ( V_95 -> V_2 , & V_63 -> V_35 , 1 , V_89 ) ;
V_4 -> V_63 . V_88 = false ;
F_49 ( V_4 -> V_10 . V_2 , L_13 ) ;
return - V_106 ;
}
V_97 -> V_109 = F_38 ;
V_97 -> V_110 = V_4 ;
F_51 ( V_97 ) ;
V_95 -> V_111 ( V_33 ) ;
V_4 -> V_86 |= V_90 ;
F_41 ( V_4 -> V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
V_4 -> V_63 . V_88 = true ;
V_93 -> V_100 = ( V_93 -> V_100 + V_99 ) & ( V_103 - 1 ) ;
V_4 -> V_10 . V_17 . V_112 += V_99 ;
if ( F_47 ( V_93 ) < V_113 )
F_52 ( & V_4 -> V_10 ) ;
return 1 ;
}
static bool F_53 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_114 )
return false ;
if ( V_4 -> V_63 . V_88 ) {
V_4 -> V_86 |= V_90 ;
F_41 ( V_4 -> V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
V_4 -> V_115 &= ~ V_116 ;
F_41 ( V_4 -> V_115 , V_4 -> V_10 . V_11 + V_117 ) ;
return true ;
}
if ( F_45 ( V_4 ) > 0 ) {
V_4 -> V_115 &= ~ V_116 ;
F_41 ( V_4 -> V_115 , V_4 -> V_10 . V_11 + V_117 ) ;
return true ;
}
return false ;
}
static inline void F_54 ( struct V_3 * V_4 )
{
if ( V_4 -> V_63 . V_88 ) {
V_4 -> V_86 &= ~ V_90 ;
F_41 ( V_4 -> V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
}
}
static inline bool F_55 ( struct V_3 * V_4 )
{
T_1 V_86 ;
if ( ! V_4 -> V_114 )
return false ;
if ( ! V_4 -> V_10 . V_118 ) {
bool V_119 = true ;
if ( ! V_4 -> V_63 . V_88 ) {
if ( F_45 ( V_4 ) > 0 ) {
V_4 -> V_115 &= ~ V_116 ;
F_41 ( V_4 -> V_115 , V_4 -> V_10 . V_11 +
V_117 ) ;
} else
V_119 = false ;
} else if ( ! ( V_4 -> V_86 & V_90 ) ) {
V_4 -> V_86 |= V_90 ;
F_41 ( V_4 -> V_86 ,
V_4 -> V_10 . V_11 + V_91 ) ;
}
return V_119 ;
}
V_86 = V_4 -> V_86 ;
V_4 -> V_86 &= ~ V_90 ;
F_41 ( V_4 -> V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
if ( F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_120 ) {
return false ;
}
F_41 ( V_4 -> V_10 . V_118 , V_4 -> V_10 . V_11 + V_14 ) ;
V_4 -> V_10 . V_17 . V_112 ++ ;
V_4 -> V_10 . V_118 = 0 ;
V_4 -> V_86 = V_86 ;
F_41 ( V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
return true ;
}
static void F_56 ( struct V_121 * V_10 )
__releases( &uap->port.lock
static int F_57 ( struct V_3 * V_4 )
{
struct V_32 * V_122 = V_4 -> V_74 . V_33 ;
struct V_123 * V_74 = & V_4 -> V_74 ;
struct V_96 * V_97 ;
struct V_34 * V_124 ;
if ( ! V_122 )
return - V_125 ;
V_124 = V_4 -> V_74 . V_126 ?
& V_4 -> V_74 . V_127 : & V_4 -> V_74 . V_128 ;
V_97 = F_50 ( V_122 , & V_124 -> V_35 , 1 ,
V_68 ,
V_107 | V_108 ) ;
if ( ! V_97 ) {
V_4 -> V_74 . V_129 = false ;
F_58 ( V_122 ) ;
return - V_106 ;
}
V_97 -> V_109 = V_130 ;
V_97 -> V_110 = V_4 ;
V_74 -> V_131 = F_51 ( V_97 ) ;
F_59 ( V_122 ) ;
V_4 -> V_86 |= V_132 ;
F_41 ( V_4 -> V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
V_4 -> V_74 . V_129 = true ;
V_4 -> V_115 &= ~ V_133 ;
F_41 ( V_4 -> V_115 , V_4 -> V_10 . V_11 + V_117 ) ;
return 0 ;
}
static void F_60 ( struct V_3 * V_4 ,
T_4 V_134 , bool V_126 ,
bool V_135 )
{
struct V_136 * V_10 = & V_4 -> V_10 . V_92 -> V_10 ;
struct V_34 * V_124 = V_126 ?
& V_4 -> V_74 . V_127 : & V_4 -> V_74 . V_128 ;
int V_137 = 0 ;
T_4 V_9 = 0 ;
struct V_123 * V_74 = & V_4 -> V_74 ;
int V_138 = 0 ;
if ( V_4 -> V_74 . V_78 ) {
V_138 = V_124 -> V_35 . V_105 - V_74 -> V_139 ;
if ( V_134 >= V_138 )
V_134 -= V_138 ;
}
if ( V_134 ) {
V_137 = F_61 ( V_10 , V_124 -> V_39 + V_138 ,
V_134 ) ;
V_4 -> V_10 . V_17 . V_18 += V_137 ;
if ( V_137 < V_134 )
F_62 ( V_4 -> V_10 . V_2 ,
L_14 ) ;
}
if ( V_4 -> V_74 . V_78 )
V_74 -> V_139 = V_124 -> V_35 . V_105 ;
if ( V_137 == V_134 && V_135 ) {
F_41 ( V_140 | V_141 | V_142 | V_143 ,
V_4 -> V_10 . V_11 + V_144 ) ;
V_9 = F_4 ( V_4 ) ;
}
F_63 ( & V_4 -> V_10 . V_87 ) ;
F_64 ( V_4 -> V_10 . V_2 ,
L_15 ,
V_137 , V_9 ) ;
F_65 ( V_10 ) ;
F_66 ( & V_4 -> V_10 . V_87 ) ;
}
static void F_67 ( struct V_3 * V_4 )
{
struct V_123 * V_74 = & V_4 -> V_74 ;
struct V_32 * V_122 = V_74 -> V_33 ;
struct V_34 * V_124 = V_74 -> V_126 ?
& V_74 -> V_127 : & V_74 -> V_128 ;
T_5 V_134 ;
struct V_145 V_92 ;
enum V_146 V_147 ;
if ( F_68 ( V_122 ) )
F_29 ( V_4 -> V_10 . V_2 , L_16 ) ;
V_147 = V_122 -> V_40 -> V_148 ( V_122 ,
V_74 -> V_131 , & V_92 ) ;
if ( V_147 != V_149 )
F_29 ( V_4 -> V_10 . V_2 , L_16 ) ;
V_4 -> V_86 &= ~ V_132 ;
F_41 ( V_4 -> V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
V_4 -> V_74 . V_129 = false ;
V_134 = V_124 -> V_35 . V_105 - V_92 . V_150 ;
F_69 ( V_134 > V_41 ) ;
F_58 ( V_122 ) ;
F_60 ( V_4 , V_134 , V_74 -> V_126 , true ) ;
V_74 -> V_126 = ! V_74 -> V_126 ;
if ( F_57 ( V_4 ) ) {
F_49 ( V_4 -> V_10 . V_2 , L_17
L_18 ) ;
V_4 -> V_115 |= V_133 ;
F_41 ( V_4 -> V_115 , V_4 -> V_10 . V_11 + V_117 ) ;
}
}
static void V_130 ( void * V_83 )
{
struct V_3 * V_4 = V_83 ;
struct V_123 * V_74 = & V_4 -> V_74 ;
struct V_32 * V_122 = V_74 -> V_33 ;
bool V_151 = V_74 -> V_126 ;
struct V_34 * V_124 = V_74 -> V_126 ?
& V_74 -> V_127 : & V_74 -> V_128 ;
T_5 V_134 ;
struct V_145 V_92 ;
int V_119 ;
F_70 ( & V_4 -> V_10 . V_87 ) ;
V_122 -> V_40 -> V_148 ( V_122 , V_74 -> V_131 , & V_92 ) ;
V_134 = V_124 -> V_35 . V_105 - V_92 . V_150 ;
F_69 ( V_134 > V_41 ) ;
F_58 ( V_122 ) ;
V_4 -> V_74 . V_129 = false ;
V_74 -> V_126 = ! V_151 ;
V_119 = F_57 ( V_4 ) ;
F_60 ( V_4 , V_134 , V_151 , false ) ;
F_71 ( & V_4 -> V_10 . V_87 ) ;
if ( V_119 ) {
F_49 ( V_4 -> V_10 . V_2 , L_17
L_18 ) ;
V_4 -> V_115 |= V_133 ;
F_41 ( V_4 -> V_115 , V_4 -> V_10 . V_11 + V_117 ) ;
}
}
static inline void F_72 ( struct V_3 * V_4 )
{
V_4 -> V_86 &= ~ V_132 ;
F_41 ( V_4 -> V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
}
static void F_73 ( unsigned long args )
{
struct V_3 * V_4 = (struct V_3 * ) args ;
struct V_136 * V_10 = & V_4 -> V_10 . V_92 -> V_10 ;
struct V_123 * V_74 = & V_4 -> V_74 ;
struct V_32 * V_122 = V_4 -> V_74 . V_33 ;
unsigned long V_85 = 0 ;
unsigned int V_138 = 0 ;
unsigned int V_152 = 0 ;
struct V_34 * V_124 ;
int V_137 ;
struct V_145 V_92 ;
V_124 = V_74 -> V_126 ? & V_4 -> V_74 . V_127 : & V_4 -> V_74 . V_128 ;
V_122 -> V_40 -> V_148 ( V_122 , V_74 -> V_131 , & V_92 ) ;
if ( F_74 ( V_92 . V_150 < V_74 -> V_139 ) ) {
V_138 = V_124 -> V_35 . V_105 - V_74 -> V_139 ;
V_152 = V_74 -> V_139 - V_92 . V_150 ;
V_137 = F_61 ( V_10 , V_124 -> V_39 + V_138 ,
V_152 ) ;
if ( V_137 == V_152 )
V_74 -> V_139 = V_92 . V_150 ;
V_74 -> V_153 = V_154 ;
}
F_65 ( V_10 ) ;
if ( F_75 ( V_154 - V_74 -> V_153 )
> V_4 -> V_74 . V_80 ) {
F_39 ( & V_4 -> V_10 . V_87 , V_85 ) ;
F_72 ( V_4 ) ;
V_4 -> V_115 |= V_133 ;
F_41 ( V_4 -> V_115 , V_4 -> V_10 . V_11 + V_117 ) ;
F_44 ( & V_4 -> V_10 . V_87 , V_85 ) ;
V_4 -> V_74 . V_129 = false ;
F_58 ( V_122 ) ;
F_76 ( & V_4 -> V_74 . V_155 ) ;
} else {
F_77 ( & V_4 -> V_74 . V_155 ,
V_154 + F_78 ( V_4 -> V_74 . V_78 ) ) ;
}
}
static void F_79 ( struct V_3 * V_4 )
{
int V_119 ;
if ( ! V_4 -> V_58 )
F_20 ( V_4 ) ;
if ( ! V_4 -> V_63 . V_33 )
return;
V_4 -> V_63 . V_39 = F_80 ( V_41 , V_42 | V_156 ) ;
if ( ! V_4 -> V_63 . V_39 ) {
F_29 ( V_4 -> V_10 . V_2 , L_19 ) ;
V_4 -> V_10 . V_55 = V_4 -> V_55 ;
return;
}
F_81 ( & V_4 -> V_63 . V_35 , V_4 -> V_63 . V_39 , V_41 ) ;
V_4 -> V_10 . V_55 = V_41 ;
V_4 -> V_114 = true ;
if ( ! V_4 -> V_74 . V_33 )
goto V_157;
V_119 = F_10 ( V_4 -> V_74 . V_33 , & V_4 -> V_74 . V_128 ,
V_158 ) ;
if ( V_119 ) {
F_29 ( V_4 -> V_10 . V_2 , L_20 ,
L_21 , V_119 ) ;
goto V_157;
}
V_119 = F_10 ( V_4 -> V_74 . V_33 , & V_4 -> V_74 . V_127 ,
V_158 ) ;
if ( V_119 ) {
F_29 ( V_4 -> V_10 . V_2 , L_20 ,
L_22 , V_119 ) ;
F_18 ( V_4 -> V_74 . V_33 , & V_4 -> V_74 . V_128 ,
V_158 ) ;
goto V_157;
}
V_4 -> V_159 = true ;
V_157:
V_4 -> V_86 |= V_160 ;
F_41 ( V_4 -> V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
if ( V_4 -> V_161 -> V_162 )
F_41 ( V_163 | V_164 ,
V_4 -> V_10 . V_11 + V_165 ) ;
if ( V_4 -> V_159 ) {
if ( F_57 ( V_4 ) )
F_49 ( V_4 -> V_10 . V_2 , L_23
L_24 ) ;
if ( V_4 -> V_74 . V_78 ) {
F_82 ( & ( V_4 -> V_74 . V_155 ) ) ;
V_4 -> V_74 . V_155 . V_166 = F_73 ;
V_4 -> V_74 . V_155 . V_83 = ( unsigned long ) V_4 ;
F_77 ( & V_4 -> V_74 . V_155 ,
V_154 +
F_78 ( V_4 -> V_74 . V_78 ) ) ;
V_4 -> V_74 . V_139 = V_41 ;
V_4 -> V_74 . V_153 = V_154 ;
}
}
}
static void F_83 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_114 || V_4 -> V_159 ) )
return;
while ( F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_167 )
F_84 () ;
F_70 ( & V_4 -> V_10 . V_87 ) ;
V_4 -> V_86 &= ~ ( V_160 | V_132 | V_90 ) ;
F_41 ( V_4 -> V_86 , V_4 -> V_10 . V_11 + V_91 ) ;
F_71 ( & V_4 -> V_10 . V_87 ) ;
if ( V_4 -> V_114 ) {
F_58 ( V_4 -> V_63 . V_33 ) ;
if ( V_4 -> V_63 . V_88 ) {
F_40 ( V_4 -> V_63 . V_33 -> V_40 -> V_2 , & V_4 -> V_63 . V_35 , 1 ,
V_89 ) ;
V_4 -> V_63 . V_88 = false ;
}
F_85 ( V_4 -> V_63 . V_39 ) ;
V_4 -> V_114 = false ;
}
if ( V_4 -> V_159 ) {
F_58 ( V_4 -> V_74 . V_33 ) ;
F_18 ( V_4 -> V_74 . V_33 , & V_4 -> V_74 . V_128 , V_158 ) ;
F_18 ( V_4 -> V_74 . V_33 , & V_4 -> V_74 . V_127 , V_158 ) ;
if ( V_4 -> V_74 . V_78 )
F_86 ( & V_4 -> V_74 . V_155 ) ;
V_4 -> V_159 = false ;
}
}
static inline bool F_87 ( struct V_3 * V_4 )
{
return V_4 -> V_159 ;
}
static inline bool F_88 ( struct V_3 * V_4 )
{
return V_4 -> V_159 && V_4 -> V_74 . V_129 ;
}
static inline void F_20 ( struct V_3 * V_4 )
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
return - V_125 ;
}
static inline bool F_87 ( struct V_3 * V_4 )
{
return false ;
}
static inline bool F_88 ( struct V_3 * V_4 )
{
return false ;
}
static void F_89 ( struct V_121 * V_10 )
{
struct V_3 * V_4 =
F_90 ( V_10 , struct V_3 , V_10 ) ;
V_4 -> V_115 &= ~ V_116 ;
F_41 ( V_4 -> V_115 , V_4 -> V_10 . V_11 + V_117 ) ;
F_54 ( V_4 ) ;
}
static void F_46 ( struct V_3 * V_4 )
{
V_4 -> V_115 |= V_116 ;
F_41 ( V_4 -> V_115 , V_4 -> V_10 . V_11 + V_117 ) ;
F_91 ( V_4 , false ) ;
}
static void F_92 ( struct V_121 * V_10 )
{
struct V_3 * V_4 =
F_90 ( V_10 , struct V_3 , V_10 ) ;
if ( ! F_55 ( V_4 ) )
F_46 ( V_4 ) ;
}
static void F_93 ( struct V_121 * V_10 )
{
struct V_3 * V_4 =
F_90 ( V_10 , struct V_3 , V_10 ) ;
V_4 -> V_115 &= ~ ( V_133 | V_168 | V_169 |
V_170 | V_171 | V_172 ) ;
F_41 ( V_4 -> V_115 , V_4 -> V_10 . V_11 + V_117 ) ;
F_72 ( V_4 ) ;
}
static void F_94 ( struct V_121 * V_10 )
{
struct V_3 * V_4 =
F_90 ( V_10 , struct V_3 , V_10 ) ;
V_4 -> V_115 |= V_173 | V_174 | V_175 | V_176 ;
F_41 ( V_4 -> V_115 , V_4 -> V_10 . V_11 + V_117 ) ;
}
static void F_95 ( struct V_3 * V_4 )
__releases( &uap->port.lock
static bool F_96 ( struct V_3 * V_4 , unsigned char V_177 ,
bool V_178 )
{
if ( F_6 ( ! V_178 ) &&
F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_120 )
return false ;
F_41 ( V_177 , V_4 -> V_10 . V_11 + V_14 ) ;
V_4 -> V_10 . V_17 . V_112 ++ ;
return true ;
}
static void F_91 ( struct V_3 * V_4 , bool V_178 )
{
struct V_98 * V_93 = & V_4 -> V_10 . V_92 -> V_93 ;
int V_99 = V_4 -> V_55 >> 1 ;
if ( V_4 -> V_10 . V_118 ) {
if ( ! F_96 ( V_4 , V_4 -> V_10 . V_118 , V_178 ) )
return;
V_4 -> V_10 . V_118 = 0 ;
-- V_99 ;
}
if ( F_43 ( V_93 ) || F_42 ( & V_4 -> V_10 ) ) {
F_89 ( & V_4 -> V_10 ) ;
return;
}
if ( F_53 ( V_4 ) )
return;
do {
if ( F_74 ( V_178 ) && V_99 -- == 0 )
break;
if ( ! F_96 ( V_4 , V_93 -> V_39 [ V_93 -> V_100 ] , V_178 ) )
break;
V_93 -> V_100 = ( V_93 -> V_100 + 1 ) & ( V_103 - 1 ) ;
} while ( ! F_43 ( V_93 ) );
if ( F_47 ( V_93 ) < V_113 )
F_52 ( & V_4 -> V_10 ) ;
if ( F_43 ( V_93 ) )
F_89 ( & V_4 -> V_10 ) ;
}
static void F_97 ( struct V_3 * V_4 )
{
unsigned int V_5 , V_179 ;
V_5 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_180 ;
V_179 = V_5 ^ V_4 -> V_181 ;
V_4 -> V_181 = V_5 ;
if ( ! V_179 )
return;
if ( V_179 & V_182 )
F_98 ( & V_4 -> V_10 , V_5 & V_182 ) ;
if ( V_179 & V_183 )
V_4 -> V_10 . V_17 . V_184 ++ ;
if ( V_179 & V_185 )
F_99 ( & V_4 -> V_10 , V_5 & V_185 ) ;
F_100 ( & V_4 -> V_10 . V_92 -> V_10 . V_186 ) ;
}
static void F_101 ( struct V_3 * V_4 )
{
unsigned int V_187 ;
if ( ! V_4 -> V_161 -> V_188 )
return;
F_41 ( 0x00 , V_4 -> V_10 . V_11 + V_144 ) ;
V_187 = F_5 ( V_4 -> V_10 . V_11 + V_144 ) ;
V_187 = F_5 ( V_4 -> V_10 . V_11 + V_144 ) ;
}
static T_6 F_102 ( int V_189 , void * V_190 )
{
struct V_3 * V_4 = V_190 ;
unsigned long V_85 ;
unsigned int V_5 , V_191 = V_192 ;
T_1 V_193 ;
int V_194 = 0 ;
F_39 ( & V_4 -> V_10 . V_87 , V_85 ) ;
V_193 = F_5 ( V_4 -> V_10 . V_11 + V_117 ) ;
V_5 = F_5 ( V_4 -> V_10 . V_11 + V_195 ) & V_193 ;
if ( V_5 ) {
do {
F_101 ( V_4 ) ;
F_41 ( V_5 & ~ ( V_196 | V_197 |
V_198 ) ,
V_4 -> V_10 . V_11 + V_144 ) ;
if ( V_5 & ( V_197 | V_198 ) ) {
if ( F_88 ( V_4 ) )
F_67 ( V_4 ) ;
else
F_95 ( V_4 ) ;
}
if ( V_5 & ( V_199 | V_200 |
V_201 | V_202 ) )
F_97 ( V_4 ) ;
if ( V_5 & V_196 )
F_91 ( V_4 , true ) ;
if ( V_191 -- == 0 )
break;
V_5 = F_5 ( V_4 -> V_10 . V_11 + V_195 ) & V_193 ;
} while ( V_5 != 0 );
V_194 = 1 ;
}
F_44 ( & V_4 -> V_10 . V_87 , V_85 ) ;
return F_103 ( V_194 ) ;
}
static unsigned int F_104 ( struct V_121 * V_10 )
{
struct V_3 * V_4 =
F_90 ( V_10 , struct V_3 , V_10 ) ;
unsigned int V_5 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) ;
return V_5 & ( V_167 | V_120 ) ? 0 : V_203 ;
}
static unsigned int F_105 ( struct V_121 * V_10 )
{
struct V_3 * V_4 =
F_90 ( V_10 , struct V_3 , V_10 ) ;
unsigned int V_204 = 0 ;
unsigned int V_5 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) ;
#define F_106 ( T_7 , T_8 ) \
if (status & uartbit) \
result |= tiocmbit
F_106 ( V_182 , V_205 ) ;
F_106 ( V_183 , V_206 ) ;
F_106 ( V_185 , V_207 ) ;
F_106 ( V_208 , V_209 ) ;
#undef F_106
return V_204 ;
}
static void F_107 ( struct V_121 * V_10 , unsigned int V_210 )
{
struct V_3 * V_4 =
F_90 ( V_10 , struct V_3 , V_10 ) ;
unsigned int V_211 ;
V_211 = F_5 ( V_4 -> V_10 . V_11 + V_212 ) ;
#define F_106 ( T_8 , T_7 ) \
if (mctrl & tiocmbit) \
cr |= uartbit; \
else \
cr &= ~uartbit
F_106 ( V_213 , V_214 ) ;
F_106 ( V_215 , V_216 ) ;
F_106 ( V_217 , V_218 ) ;
F_106 ( V_219 , V_220 ) ;
F_106 ( V_221 , V_222 ) ;
if ( V_4 -> V_223 ) {
F_106 ( V_213 , V_224 ) ;
}
#undef F_106
F_41 ( V_211 , V_4 -> V_10 . V_11 + V_212 ) ;
}
static void F_108 ( struct V_121 * V_10 , int V_225 )
{
struct V_3 * V_4 =
F_90 ( V_10 , struct V_3 , V_10 ) ;
unsigned long V_85 ;
unsigned int V_226 ;
F_39 ( & V_4 -> V_10 . V_87 , V_85 ) ;
V_226 = F_5 ( V_4 -> V_10 . V_11 + V_4 -> V_227 ) ;
if ( V_225 == - 1 )
V_226 |= V_228 ;
else
V_226 &= ~ V_228 ;
F_41 ( V_226 , V_4 -> V_10 . V_11 + V_4 -> V_227 ) ;
F_44 ( & V_4 -> V_10 . V_87 , V_85 ) ;
}
static void F_109 ( struct V_121 * V_10 )
{
struct V_3 * V_4 =
F_90 ( V_10 , struct V_3 , V_10 ) ;
unsigned char T_9 * V_229 = V_4 -> V_10 . V_11 ;
F_41 ( F_5 ( V_229 + V_230 ) , V_229 + V_144 ) ;
F_41 ( F_5 ( V_229 + V_117 ) & ~ V_116 , V_229 + V_117 ) ;
}
static int F_110 ( struct V_121 * V_10 )
{
struct V_3 * V_4 =
F_90 ( V_10 , struct V_3 , V_10 ) ;
unsigned int V_5 ;
F_109 ( V_10 ) ;
V_5 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) ;
if ( V_5 & V_13 )
return V_231 ;
return F_5 ( V_4 -> V_10 . V_11 + V_14 ) ;
}
static void F_111 ( struct V_121 * V_10 ,
unsigned char V_6 )
{
struct V_3 * V_4 =
F_90 ( V_10 , struct V_3 , V_10 ) ;
while ( F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_120 )
F_84 () ;
F_41 ( V_6 , V_4 -> V_10 . V_11 + V_14 ) ;
}
static int F_112 ( struct V_121 * V_10 )
{
struct V_3 * V_4 =
F_90 ( V_10 , struct V_3 , V_10 ) ;
int V_232 ;
F_113 ( V_10 -> V_2 ) ;
V_232 = F_114 ( V_4 -> V_233 ) ;
if ( V_232 )
return V_232 ;
V_4 -> V_10 . V_234 = F_115 ( V_4 -> V_233 ) ;
F_41 ( V_140 | V_141 | V_142 | V_143 |
V_197 | V_198 , V_4 -> V_10 . V_11 + V_144 ) ;
V_4 -> V_115 = F_5 ( V_4 -> V_10 . V_11 + V_117 ) ;
F_41 ( V_168 | V_133 , V_4 -> V_10 . V_11 + V_117 ) ;
if ( F_21 ( V_4 -> V_10 . V_2 ) ) {
struct V_44 * V_45 ;
V_45 = F_21 ( V_4 -> V_10 . V_2 ) ;
if ( V_45 -> V_235 )
V_45 -> V_235 () ;
}
return 0 ;
}
static void F_116 ( struct V_3 * V_4 , unsigned int V_226 )
{
F_41 ( V_226 , V_4 -> V_10 . V_11 + V_4 -> V_236 ) ;
if ( V_4 -> V_236 != V_4 -> V_227 ) {
int V_237 ;
for ( V_237 = 0 ; V_237 < 10 ; ++ V_237 )
F_41 ( 0xff , V_4 -> V_10 . V_11 + V_230 ) ;
F_41 ( V_226 , V_4 -> V_10 . V_11 + V_4 -> V_227 ) ;
}
}
static int F_117 ( struct V_3 * V_4 )
{
F_41 ( V_4 -> V_115 , V_4 -> V_10 . V_11 + V_117 ) ;
return F_118 ( V_4 -> V_10 . V_189 , F_102 , 0 , L_25 , V_4 ) ;
}
static void F_119 ( struct V_3 * V_4 )
{
F_70 ( & V_4 -> V_10 . V_87 ) ;
F_41 ( V_197 | V_198 ,
V_4 -> V_10 . V_11 + V_144 ) ;
V_4 -> V_115 = V_168 ;
if ( ! F_88 ( V_4 ) )
V_4 -> V_115 |= V_133 ;
F_41 ( V_4 -> V_115 , V_4 -> V_10 . V_11 + V_117 ) ;
F_71 ( & V_4 -> V_10 . V_87 ) ;
}
static int F_120 ( struct V_121 * V_10 )
{
struct V_3 * V_4 =
F_90 ( V_10 , struct V_3 , V_10 ) ;
unsigned int V_211 ;
int V_232 ;
V_232 = F_112 ( V_10 ) ;
if ( V_232 )
goto V_238;
V_232 = F_117 ( V_4 ) ;
if ( V_232 )
goto V_238;
F_41 ( V_4 -> V_161 -> V_239 , V_4 -> V_10 . V_11 + V_240 ) ;
F_70 ( & V_4 -> V_10 . V_87 ) ;
V_211 = V_4 -> V_241 & ( V_214 | V_216 ) ;
V_211 |= V_242 | V_243 | V_244 ;
F_41 ( V_211 , V_4 -> V_10 . V_11 + V_212 ) ;
F_71 ( & V_4 -> V_10 . V_87 ) ;
V_4 -> V_181 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_180 ;
F_79 ( V_4 ) ;
F_119 ( V_4 ) ;
return 0 ;
V_238:
F_121 ( V_4 -> V_233 ) ;
return V_232 ;
}
static int F_122 ( struct V_121 * V_10 )
{
struct V_3 * V_4 =
F_90 ( V_10 , struct V_3 , V_10 ) ;
int V_232 ;
V_232 = F_112 ( V_10 ) ;
if ( V_232 )
return V_232 ;
V_232 = F_117 ( V_4 ) ;
if ( V_232 )
return V_232 ;
V_4 -> V_181 = 0 ;
F_119 ( V_4 ) ;
return 0 ;
}
static void F_123 ( struct V_3 * V_4 ,
unsigned int V_245 )
{
unsigned long V_246 ;
V_246 = F_5 ( V_4 -> V_10 . V_11 + V_245 ) ;
V_246 &= ~ ( V_228 | V_247 ) ;
F_41 ( V_246 , V_4 -> V_10 . V_11 + V_245 ) ;
}
static void F_124 ( struct V_3 * V_4 )
{
unsigned int V_211 ;
V_4 -> V_223 = false ;
F_70 ( & V_4 -> V_10 . V_87 ) ;
V_211 = F_5 ( V_4 -> V_10 . V_11 + V_212 ) ;
V_4 -> V_241 = V_211 ;
V_211 &= V_214 | V_216 ;
V_211 |= V_242 | V_244 ;
F_41 ( V_211 , V_4 -> V_10 . V_11 + V_212 ) ;
F_71 ( & V_4 -> V_10 . V_87 ) ;
F_123 ( V_4 , V_4 -> V_236 ) ;
if ( V_4 -> V_236 != V_4 -> V_227 )
F_123 ( V_4 , V_4 -> V_227 ) ;
}
static void F_125 ( struct V_3 * V_4 )
{
F_70 ( & V_4 -> V_10 . V_87 ) ;
V_4 -> V_115 = 0 ;
F_41 ( V_4 -> V_115 , V_4 -> V_10 . V_11 + V_117 ) ;
F_41 ( 0xffff , V_4 -> V_10 . V_11 + V_144 ) ;
F_71 ( & V_4 -> V_10 . V_87 ) ;
}
static void F_126 ( struct V_121 * V_10 )
{
struct V_3 * V_4 =
F_90 ( V_10 , struct V_3 , V_10 ) ;
F_125 ( V_4 ) ;
F_83 ( V_4 ) ;
F_127 ( V_4 -> V_10 . V_189 , V_4 ) ;
F_124 ( V_4 ) ;
F_121 ( V_4 -> V_233 ) ;
F_128 ( V_10 -> V_2 ) ;
if ( F_21 ( V_4 -> V_10 . V_2 ) ) {
struct V_44 * V_45 ;
V_45 = F_21 ( V_4 -> V_10 . V_2 ) ;
if ( V_45 -> exit )
V_45 -> exit () ;
}
if ( V_4 -> V_10 . V_248 -> V_249 )
V_4 -> V_10 . V_248 -> V_249 ( V_10 ) ;
}
static void F_129 ( struct V_121 * V_10 )
{
struct V_3 * V_4 =
F_90 ( V_10 , struct V_3 , V_10 ) ;
F_125 ( V_4 ) ;
F_127 ( V_4 -> V_10 . V_189 , V_4 ) ;
if ( V_4 -> V_10 . V_248 -> V_249 )
V_4 -> V_10 . V_248 -> V_249 ( V_10 ) ;
}
static void
F_130 ( struct V_121 * V_10 , struct V_250 * V_251 )
{
V_10 -> V_28 = V_26 | 255 ;
if ( V_251 -> V_252 & V_253 )
V_10 -> V_28 |= V_21 | V_22 ;
if ( V_251 -> V_252 & ( V_254 | V_255 | V_256 ) )
V_10 -> V_28 |= V_20 ;
V_10 -> V_257 = 0 ;
if ( V_251 -> V_252 & V_258 )
V_10 -> V_257 |= V_21 | V_22 ;
if ( V_251 -> V_252 & V_254 ) {
V_10 -> V_257 |= V_20 ;
if ( V_251 -> V_252 & V_258 )
V_10 -> V_257 |= V_26 ;
}
if ( ( V_251 -> V_259 & V_260 ) == 0 )
V_10 -> V_257 |= V_15 ;
}
static void
F_131 ( struct V_121 * V_10 , struct V_250 * V_251 ,
struct V_250 * V_261 )
{
struct V_3 * V_4 =
F_90 ( V_10 , struct V_3 , V_10 ) ;
unsigned int V_226 , V_241 ;
unsigned long V_85 ;
unsigned int V_262 , V_263 , V_264 ;
if ( V_4 -> V_161 -> V_265 )
V_264 = 8 ;
else
V_264 = 16 ;
V_262 = F_132 ( V_10 , V_251 , V_261 , 0 ,
V_10 -> V_234 / V_264 ) ;
#ifdef F_133
if ( V_4 -> V_74 . V_75 )
V_4 -> V_74 . V_78 = F_134 ( 10000000 , V_262 ) ;
#endif
if ( V_262 > V_10 -> V_234 / 16 )
V_263 = F_135 ( V_10 -> V_234 * 8 , V_262 ) ;
else
V_263 = F_135 ( V_10 -> V_234 * 4 , V_262 ) ;
switch ( V_251 -> V_259 & V_266 ) {
case V_267 :
V_226 = V_268 ;
break;
case V_269 :
V_226 = V_270 ;
break;
case V_271 :
V_226 = V_272 ;
break;
default:
V_226 = V_273 ;
break;
}
if ( V_251 -> V_259 & V_274 )
V_226 |= V_275 ;
if ( V_251 -> V_259 & V_276 ) {
V_226 |= V_277 ;
if ( ! ( V_251 -> V_259 & V_278 ) )
V_226 |= V_279 ;
}
if ( V_4 -> V_55 > 1 )
V_226 |= V_247 ;
F_39 ( & V_10 -> V_87 , V_85 ) ;
F_136 ( V_10 , V_251 -> V_259 , V_262 ) ;
F_130 ( V_10 , V_251 ) ;
if ( F_137 ( V_10 , V_251 -> V_259 ) )
F_94 ( V_10 ) ;
V_241 = F_5 ( V_10 -> V_11 + V_212 ) ;
F_41 ( 0 , V_10 -> V_11 + V_212 ) ;
if ( V_251 -> V_259 & V_280 ) {
if ( V_241 & V_214 )
V_241 |= V_224 ;
V_241 |= V_281 ;
V_4 -> V_223 = true ;
} else {
V_241 &= ~ ( V_281 | V_224 ) ;
V_4 -> V_223 = false ;
}
if ( V_4 -> V_161 -> V_265 ) {
if ( V_262 > V_10 -> V_234 / 16 )
V_241 |= V_282 ;
else
V_241 &= ~ V_282 ;
}
if ( V_4 -> V_161 -> V_265 ) {
if ( ( V_262 >= 3000000 ) && ( V_262 < 3250000 ) && ( V_263 > 1 ) )
V_263 -= 1 ;
else if ( ( V_262 > 3250000 ) && ( V_263 > 2 ) )
V_263 -= 2 ;
}
F_41 ( V_263 & 0x3f , V_10 -> V_11 + V_283 ) ;
F_41 ( V_263 >> 6 , V_10 -> V_11 + V_284 ) ;
F_116 ( V_4 , V_226 ) ;
F_41 ( V_241 , V_10 -> V_11 + V_212 ) ;
F_44 ( & V_10 -> V_87 , V_85 ) ;
}
static void
F_138 ( struct V_121 * V_10 , struct V_250 * V_251 ,
struct V_250 * V_261 )
{
struct V_3 * V_4 =
F_90 ( V_10 , struct V_3 , V_10 ) ;
unsigned long V_85 ;
F_139 ( V_251 , V_4 -> V_285 , V_4 -> V_285 ) ;
V_251 -> V_259 &= ~ ( V_266 | V_274 | V_276 | V_278 ) ;
V_251 -> V_259 &= ~ ( V_286 | V_280 ) ;
V_251 -> V_259 |= V_287 | V_288 ;
F_39 ( & V_10 -> V_87 , V_85 ) ;
F_136 ( V_10 , V_287 , V_4 -> V_285 ) ;
F_130 ( V_10 , V_251 ) ;
F_44 ( & V_10 -> V_87 , V_85 ) ;
}
static const char * F_140 ( struct V_121 * V_10 )
{
struct V_3 * V_4 =
F_90 ( V_10 , struct V_3 , V_10 ) ;
return V_4 -> V_10 . type == V_289 ? V_4 -> type : NULL ;
}
static void F_141 ( struct V_121 * V_10 )
{
F_142 ( V_10 -> V_49 , V_290 ) ;
}
static int F_143 ( struct V_121 * V_10 )
{
return F_144 ( V_10 -> V_49 , V_290 , L_25 )
!= NULL ? 0 : - V_106 ;
}
static void F_145 ( struct V_121 * V_10 , int V_85 )
{
if ( V_85 & V_291 ) {
V_10 -> type = V_289 ;
F_143 ( V_10 ) ;
}
}
static int F_146 ( struct V_121 * V_10 , struct V_292 * V_293 )
{
int V_119 = 0 ;
if ( V_293 -> type != V_294 && V_293 -> type != V_289 )
V_119 = - V_295 ;
if ( V_293 -> V_189 < 0 || V_293 -> V_189 >= V_296 )
V_119 = - V_295 ;
if ( V_293 -> V_297 < 9600 )
V_119 = - V_295 ;
return V_119 ;
}
static void F_147 ( struct V_121 * V_10 , unsigned int V_210 )
{
}
static unsigned int F_148 ( struct V_121 * V_10 )
{
return 0 ;
}
static void F_149 ( struct V_121 * V_10 , int V_6 )
{
struct V_3 * V_4 =
F_90 ( V_10 , struct V_3 , V_10 ) ;
while ( F_5 ( V_4 -> V_10 . V_11 + V_12 ) & V_120 )
F_84 () ;
F_41 ( V_6 , V_4 -> V_10 . V_11 + V_14 ) ;
}
static void
F_150 ( struct V_298 * V_299 , const char * V_300 , unsigned int V_99 )
{
struct V_3 * V_4 = V_301 [ V_299 -> V_302 ] ;
unsigned int V_5 , V_241 = 0 , V_303 ;
unsigned long V_85 ;
int V_304 = 1 ;
F_151 ( V_4 -> V_233 ) ;
F_152 ( V_85 ) ;
if ( V_4 -> V_10 . V_305 )
V_304 = 0 ;
else if ( V_306 )
V_304 = F_153 ( & V_4 -> V_10 . V_87 ) ;
else
F_66 ( & V_4 -> V_10 . V_87 ) ;
if ( ! V_4 -> V_161 -> V_307 ) {
V_241 = F_5 ( V_4 -> V_10 . V_11 + V_212 ) ;
V_303 = V_241 & ~ V_281 ;
V_303 |= V_242 | V_244 ;
F_41 ( V_303 , V_4 -> V_10 . V_11 + V_212 ) ;
}
F_154 ( & V_4 -> V_10 , V_300 , V_99 , F_149 ) ;
do {
V_5 = F_5 ( V_4 -> V_10 . V_11 + V_12 ) ;
} while ( V_5 & V_167 );
if ( ! V_4 -> V_161 -> V_307 )
F_41 ( V_241 , V_4 -> V_10 . V_11 + V_212 ) ;
if ( V_304 )
F_63 ( & V_4 -> V_10 . V_87 ) ;
F_155 ( V_85 ) ;
F_156 ( V_4 -> V_233 ) ;
}
static void T_10
F_157 ( struct V_3 * V_4 , int * V_262 ,
int * V_24 , int * V_308 )
{
if ( F_5 ( V_4 -> V_10 . V_11 + V_212 ) & V_242 ) {
unsigned int V_226 , V_309 , V_310 ;
V_226 = F_5 ( V_4 -> V_10 . V_11 + V_4 -> V_227 ) ;
* V_24 = 'n' ;
if ( V_226 & V_277 ) {
if ( V_226 & V_279 )
* V_24 = 'e' ;
else
* V_24 = 'o' ;
}
if ( ( V_226 & 0x60 ) == V_272 )
* V_308 = 7 ;
else
* V_308 = 8 ;
V_309 = F_5 ( V_4 -> V_10 . V_11 + V_284 ) ;
V_310 = F_5 ( V_4 -> V_10 . V_11 + V_283 ) ;
* V_262 = V_4 -> V_10 . V_234 * 4 / ( 64 * V_309 + V_310 ) ;
if ( V_4 -> V_161 -> V_265 ) {
if ( F_5 ( V_4 -> V_10 . V_11 + V_212 )
& V_282 )
* V_262 *= 2 ;
}
}
}
static int T_10 F_158 ( struct V_298 * V_299 , char * V_311 )
{
struct V_3 * V_4 ;
int V_262 = 38400 ;
int V_308 = 8 ;
int V_24 = 'n' ;
int V_312 = 'n' ;
int V_119 ;
if ( V_299 -> V_302 >= V_313 )
V_299 -> V_302 = 0 ;
V_4 = V_301 [ V_299 -> V_302 ] ;
if ( ! V_4 )
return - V_314 ;
F_113 ( V_4 -> V_10 . V_2 ) ;
V_119 = F_159 ( V_4 -> V_233 ) ;
if ( V_119 )
return V_119 ;
if ( F_21 ( V_4 -> V_10 . V_2 ) ) {
struct V_44 * V_45 ;
V_45 = F_21 ( V_4 -> V_10 . V_2 ) ;
if ( V_45 -> V_235 )
V_45 -> V_235 () ;
}
V_4 -> V_10 . V_234 = F_115 ( V_4 -> V_233 ) ;
if ( V_4 -> V_161 -> V_315 ) {
V_262 = V_4 -> V_285 ;
} else {
if ( V_311 )
F_160 ( V_311 ,
& V_262 , & V_24 , & V_308 , & V_312 ) ;
else
F_157 ( V_4 , & V_262 , & V_24 , & V_308 ) ;
}
return F_161 ( & V_4 -> V_10 , V_299 , V_262 , V_24 , V_308 , V_312 ) ;
}
static void F_162 ( struct V_121 * V_10 , int V_177 )
{
while ( F_163 ( V_10 -> V_11 + V_12 ) & V_120 )
;
F_164 ( V_177 , V_10 -> V_11 + V_14 ) ;
while ( F_163 ( V_10 -> V_11 + V_12 ) & V_167 )
;
}
static void F_165 ( struct V_298 * V_316 , const char * V_300 , unsigned V_317 )
{
struct V_318 * V_2 = V_316 -> V_83 ;
F_154 ( & V_2 -> V_10 , V_300 , V_317 , F_162 ) ;
}
static int T_10 F_166 ( struct V_318 * V_40 ,
const char * V_319 )
{
if ( ! V_40 -> V_10 . V_11 )
return - V_314 ;
V_40 -> V_316 -> V_320 = F_165 ;
return 0 ;
}
static int F_167 ( int V_302 , struct V_40 * V_2 )
{
struct V_321 * V_322 ;
static bool V_323 = false ;
static bool V_324 = false ;
int V_119 = V_302 ;
if ( ! F_168 ( V_325 ) )
return V_119 ;
V_322 = V_2 -> V_81 ;
if ( ! V_322 )
return V_119 ;
V_119 = F_169 ( V_322 , L_26 ) ;
if ( F_170 ( V_119 ) ) {
V_324 = true ;
V_119 = V_302 ;
} else {
V_323 = true ;
if ( V_119 >= F_171 ( V_301 ) || V_301 [ V_119 ] != NULL ) {
F_62 ( V_2 , L_27 , V_119 ) ;
V_119 = V_302 ;
}
}
if ( V_323 && V_324 )
F_62 ( V_2 , L_28 ) ;
return V_119 ;
}
static void F_172 ( struct V_3 * V_4 )
{
int V_237 ;
bool V_326 = false ;
for ( V_237 = 0 ; V_237 < F_171 ( V_301 ) ; V_237 ++ ) {
if ( V_301 [ V_237 ] == V_4 )
V_301 [ V_237 ] = NULL ;
else if ( V_301 [ V_237 ] )
V_326 = true ;
}
F_37 ( V_4 ) ;
if ( ! V_326 )
F_173 ( & V_327 ) ;
}
static int F_174 ( void )
{
int V_237 ;
for ( V_237 = 0 ; V_237 < F_171 ( V_301 ) ; V_237 ++ )
if ( V_301 [ V_237 ] == NULL )
return V_237 ;
return - V_106 ;
}
static int F_175 ( struct V_40 * V_2 , struct V_3 * V_4 ,
struct V_328 * V_329 , int V_302 )
{
void T_9 * V_330 ;
V_330 = F_176 ( V_2 , V_329 ) ;
if ( F_23 ( V_330 ) )
return F_24 ( V_330 ) ;
V_302 = F_167 ( V_302 , V_2 ) ;
V_4 -> V_241 = 0 ;
V_4 -> V_10 . V_2 = V_2 ;
V_4 -> V_10 . V_49 = V_329 -> V_331 ;
V_4 -> V_10 . V_11 = V_330 ;
V_4 -> V_10 . V_332 = V_333 ;
V_4 -> V_10 . V_55 = V_4 -> V_55 ;
V_4 -> V_10 . V_85 = V_334 ;
V_4 -> V_10 . line = V_302 ;
V_301 [ V_302 ] = V_4 ;
return 0 ;
}
static int F_177 ( struct V_3 * V_4 )
{
int V_119 ;
F_41 ( 0 , V_4 -> V_10 . V_11 + V_117 ) ;
F_41 ( 0xffff , V_4 -> V_10 . V_11 + V_144 ) ;
if ( ! V_327 . V_92 ) {
V_119 = F_178 ( & V_327 ) ;
if ( V_119 < 0 ) {
F_29 ( V_4 -> V_10 . V_2 ,
L_29 ) ;
return V_119 ;
}
}
V_119 = F_179 ( & V_327 , & V_4 -> V_10 ) ;
if ( V_119 )
F_172 ( V_4 ) ;
return V_119 ;
}
static int F_180 ( struct V_1 * V_2 , const struct V_335 * V_336 )
{
struct V_3 * V_4 ;
struct V_337 * V_161 = V_336 -> V_83 ;
int V_338 , V_119 ;
V_338 = F_174 () ;
if ( V_338 < 0 )
return V_338 ;
V_4 = F_181 ( & V_2 -> V_2 , sizeof( struct V_3 ) ,
V_42 ) ;
if ( ! V_4 )
return - V_43 ;
V_4 -> V_233 = F_182 ( & V_2 -> V_2 , NULL ) ;
if ( F_23 ( V_4 -> V_233 ) )
return F_24 ( V_4 -> V_233 ) ;
V_4 -> V_161 = V_161 ;
V_4 -> V_236 = V_161 -> V_236 ;
V_4 -> V_227 = V_161 -> V_227 ;
V_4 -> V_55 = V_161 -> V_339 ( V_2 ) ;
V_4 -> V_10 . V_189 = V_2 -> V_189 [ 0 ] ;
V_4 -> V_10 . V_248 = & V_340 ;
snprintf ( V_4 -> type , sizeof( V_4 -> type ) , L_30 , F_2 ( V_2 ) ) ;
V_119 = F_175 ( & V_2 -> V_2 , V_4 , & V_2 -> V_341 , V_338 ) ;
if ( V_119 )
return V_119 ;
F_183 ( V_2 , V_4 ) ;
return F_177 ( V_4 ) ;
}
static int F_184 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_185 ( V_2 ) ;
F_186 ( & V_327 , & V_4 -> V_10 ) ;
F_172 ( V_4 ) ;
return 0 ;
}
static int F_187 ( struct V_40 * V_2 )
{
struct V_3 * V_4 = F_188 ( V_2 ) ;
if ( ! V_4 )
return - V_295 ;
return F_189 ( & V_327 , & V_4 -> V_10 ) ;
}
static int F_190 ( struct V_40 * V_2 )
{
struct V_3 * V_4 = F_188 ( V_2 ) ;
if ( ! V_4 )
return - V_295 ;
return F_191 ( & V_327 , & V_4 -> V_10 ) ;
}
static int F_192 ( struct V_342 * V_343 )
{
struct V_3 * V_4 ;
struct V_328 * V_344 ;
int V_338 , V_119 ;
int V_345 ;
if ( V_343 -> V_2 . V_81 ) {
struct V_321 * V_322 = V_343 -> V_2 . V_81 ;
V_119 = F_36 ( V_322 , L_31 , & V_345 ) ;
if ( V_119 )
return V_119 ;
} else {
V_345 = 115200 ;
}
V_338 = F_174 () ;
if ( V_338 < 0 )
return V_338 ;
V_4 = F_181 ( & V_343 -> V_2 , sizeof( struct V_3 ) ,
V_42 ) ;
if ( ! V_4 )
return - V_43 ;
V_4 -> V_161 = & V_346 ;
V_4 -> V_55 = 32 ;
V_4 -> V_10 . V_189 = F_193 ( V_343 , 0 ) ;
V_4 -> V_10 . V_248 = & V_347 ;
V_4 -> V_285 = V_345 ;
snprintf ( V_4 -> type , sizeof( V_4 -> type ) , L_32 ) ;
V_344 = F_194 ( V_343 , V_348 , 0 ) ;
V_119 = F_175 ( & V_343 -> V_2 , V_4 , V_344 , V_338 ) ;
if ( V_119 )
return V_119 ;
F_195 ( V_343 , V_4 ) ;
return F_177 ( V_4 ) ;
}
static int F_196 ( struct V_342 * V_343 )
{
struct V_3 * V_4 = F_197 ( V_343 ) ;
F_186 ( & V_327 , & V_4 -> V_10 ) ;
F_172 ( V_4 ) ;
return 0 ;
}
static int T_10 F_198 ( void )
{
F_199 ( V_349 L_33 ) ;
if ( F_200 ( & V_350 ) )
F_201 ( L_34 ) ;
return F_202 ( & V_351 ) ;
}
static void T_11 F_203 ( void )
{
F_204 ( & V_350 ) ;
F_205 ( & V_351 ) ;
}
