static unsigned int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) < 3 ? 16 : 32 ;
}
static unsigned int F_3 ( struct V_1 * V_2 )
{
return 64 ;
}
static unsigned int F_4 ( const struct V_3 * V_4 ,
unsigned int V_5 )
{
return V_4 -> V_6 [ V_5 ] ;
}
static unsigned int F_5 ( const struct V_3 * V_4 ,
unsigned int V_5 )
{
void T_1 * V_7 = V_4 -> V_8 . V_9 + F_4 ( V_4 , V_5 ) ;
return ( V_4 -> V_8 . V_10 == V_11 ) ?
F_6 ( V_7 ) : F_7 ( V_7 ) ;
}
static void F_8 ( unsigned int V_12 , const struct V_3 * V_4 ,
unsigned int V_5 )
{
void T_1 * V_7 = V_4 -> V_8 . V_9 + F_4 ( V_4 , V_5 ) ;
if ( V_4 -> V_8 . V_10 == V_11 )
F_9 ( V_12 , V_7 ) ;
else
F_10 ( V_12 , V_7 ) ;
}
static int F_11 ( struct V_3 * V_4 )
{
T_2 V_13 ;
unsigned int V_14 , V_15 , V_16 = 256 ;
int V_17 = 0 ;
while ( V_16 -- ) {
V_13 = F_5 ( V_4 , V_18 ) ;
if ( V_13 & V_19 )
break;
V_14 = F_5 ( V_4 , V_20 ) | V_21 ;
V_15 = V_22 ;
V_4 -> V_8 . V_23 . V_24 ++ ;
V_17 ++ ;
if ( F_12 ( V_14 & V_25 ) ) {
if ( V_14 & V_26 ) {
V_14 &= ~ ( V_27 | V_28 ) ;
V_4 -> V_8 . V_23 . V_29 ++ ;
if ( F_13 ( & V_4 -> V_8 ) )
continue;
} else if ( V_14 & V_28 )
V_4 -> V_8 . V_23 . V_30 ++ ;
else if ( V_14 & V_27 )
V_4 -> V_8 . V_23 . V_31 ++ ;
if ( V_14 & V_32 )
V_4 -> V_8 . V_23 . V_33 ++ ;
V_14 &= V_4 -> V_8 . V_34 ;
if ( V_14 & V_26 )
V_15 = V_35 ;
else if ( V_14 & V_28 )
V_15 = V_36 ;
else if ( V_14 & V_27 )
V_15 = V_37 ;
}
if ( F_14 ( & V_4 -> V_8 , V_14 & 255 ) )
continue;
F_15 ( & V_4 -> V_8 , V_14 , V_32 , V_14 , V_15 ) ;
}
return V_17 ;
}
static int F_16 ( struct V_38 * V_39 , struct V_40 * V_41 ,
enum V_42 V_43 )
{
T_3 V_44 ;
V_41 -> V_45 = F_17 ( V_39 -> V_46 -> V_2 ,
V_47 , & V_44 , V_48 ) ;
if ( ! V_41 -> V_45 )
return - V_49 ;
F_18 ( & V_41 -> V_41 , 1 ) ;
F_19 ( & V_41 -> V_41 , F_20 ( V_44 ) ,
V_47 , F_21 ( V_44 ) ) ;
F_22 ( & V_41 -> V_41 ) = V_44 ;
F_23 ( & V_41 -> V_41 ) = V_47 ;
return 0 ;
}
static void F_24 ( struct V_38 * V_39 , struct V_40 * V_41 ,
enum V_42 V_43 )
{
if ( V_41 -> V_45 ) {
F_25 ( V_39 -> V_46 -> V_2 ,
V_47 , V_41 -> V_45 ,
F_22 ( & V_41 -> V_41 ) ) ;
}
}
static void F_26 ( struct V_3 * V_4 )
{
struct V_50 * V_51 = F_27 ( V_4 -> V_8 . V_2 ) ;
struct V_46 * V_2 = V_4 -> V_8 . V_2 ;
struct V_52 V_53 = {
. V_54 = V_4 -> V_8 . V_55 +
F_4 ( V_4 , V_20 ) ,
. V_56 = V_57 ,
. V_58 = V_59 ,
. V_60 = V_4 -> V_61 >> 1 ,
. V_62 = false ,
} ;
struct V_38 * V_39 ;
T_4 V_63 ;
V_4 -> V_64 = true ;
V_39 = F_28 ( V_2 , L_1 ) ;
if ( F_29 ( V_39 ) ) {
if ( F_30 ( V_39 ) == - V_65 ) {
V_4 -> V_64 = false ;
return;
}
if ( ! V_51 || ! V_51 -> V_66 ) {
F_31 ( V_4 -> V_8 . V_2 , L_2 ) ;
return;
}
F_32 ( V_63 ) ;
F_33 ( V_67 , V_63 ) ;
V_39 = F_34 ( V_63 , V_51 -> V_66 ,
V_51 -> V_68 ) ;
if ( ! V_39 ) {
F_35 ( V_4 -> V_8 . V_2 , L_3 ) ;
return;
}
}
F_36 ( V_39 , & V_53 ) ;
V_4 -> V_69 . V_39 = V_39 ;
F_31 ( V_4 -> V_8 . V_2 , L_4 ,
F_37 ( V_4 -> V_69 . V_39 ) ) ;
V_39 = F_38 ( V_2 , L_5 ) ;
if ( ! V_39 && V_51 -> V_70 ) {
V_39 = F_34 ( V_63 , V_51 -> V_66 , V_51 -> V_70 ) ;
if ( ! V_39 ) {
F_35 ( V_4 -> V_8 . V_2 , L_6 ) ;
return;
}
}
if ( V_39 ) {
struct V_52 V_71 = {
. V_72 = V_4 -> V_8 . V_55 +
F_4 ( V_4 , V_20 ) ,
. V_73 = V_57 ,
. V_58 = V_74 ,
. V_75 = V_4 -> V_61 >> 2 ,
. V_62 = false ,
} ;
struct V_76 V_77 ;
if ( 0 == F_39 ( V_39 , & V_77 ) ) {
if ( V_77 . V_78 ==
V_79 ) {
F_40 ( V_39 ) ;
F_31 ( V_4 -> V_8 . V_2 ,
L_7 ) ;
return;
}
}
F_36 ( V_39 , & V_71 ) ;
V_4 -> V_80 . V_39 = V_39 ;
V_4 -> V_80 . V_81 = false ;
if ( V_51 && V_51 -> V_82 ) {
if ( V_51 -> V_83 ) {
V_4 -> V_80 . V_81 = false ;
V_4 -> V_80 . V_84 = V_51 -> V_83 ;
} else {
V_4 -> V_80 . V_81 = true ;
V_4 -> V_80 . V_84 = 100 ;
}
if ( V_51 -> V_85 )
V_4 -> V_80 . V_86 =
V_51 -> V_85 ;
else
V_4 -> V_80 . V_86 = 3000 ;
} else if ( ! V_51 && V_2 -> V_87 ) {
V_4 -> V_80 . V_81 = F_41 (
V_2 -> V_87 , L_8 ) ;
if ( V_4 -> V_80 . V_81 ) {
T_5 V_88 ;
if ( 0 == F_42 ( V_2 -> V_87 ,
L_9 , & V_88 ) )
V_4 -> V_80 . V_84 = V_88 ;
else
V_4 -> V_80 . V_84 = 100 ;
if ( 0 == F_42 ( V_2 -> V_87 ,
L_10 , & V_88 ) )
V_4 -> V_80 . V_86 = V_88 ;
else
V_4 -> V_80 . V_86 = 3000 ;
}
}
F_31 ( V_4 -> V_8 . V_2 , L_11 ,
F_37 ( V_4 -> V_80 . V_39 ) ) ;
}
}
static void F_43 ( struct V_3 * V_4 )
{
if ( V_4 -> V_69 . V_39 )
F_40 ( V_4 -> V_69 . V_39 ) ;
if ( V_4 -> V_80 . V_39 )
F_40 ( V_4 -> V_80 . V_39 ) ;
}
static void F_44 ( void * V_89 )
{
struct V_3 * V_4 = V_89 ;
struct V_90 * V_69 = & V_4 -> V_69 ;
unsigned long V_91 ;
T_2 V_92 ;
F_45 ( & V_4 -> V_8 . V_93 , V_91 ) ;
if ( V_4 -> V_69 . V_94 )
F_46 ( V_69 -> V_39 -> V_46 -> V_2 , & V_69 -> V_41 , 1 ,
V_95 ) ;
V_92 = V_4 -> V_92 ;
V_4 -> V_92 = V_92 & ~ V_96 ;
F_8 ( V_4 -> V_92 , V_4 , V_97 ) ;
if ( ! ( V_92 & V_96 ) || F_47 ( & V_4 -> V_8 ) ||
F_48 ( & V_4 -> V_8 . V_98 -> V_99 ) ) {
V_4 -> V_69 . V_94 = false ;
F_49 ( & V_4 -> V_8 . V_93 , V_91 ) ;
return;
}
if ( F_50 ( V_4 ) <= 0 )
F_51 ( V_4 ) ;
F_49 ( & V_4 -> V_8 . V_93 , V_91 ) ;
}
static int F_50 ( struct V_3 * V_4 )
{
struct V_90 * V_69 = & V_4 -> V_69 ;
struct V_38 * V_39 = V_69 -> V_39 ;
struct V_100 * V_101 = V_39 -> V_46 ;
struct V_102 * V_103 ;
struct V_104 * V_99 = & V_4 -> V_8 . V_98 -> V_99 ;
unsigned int V_105 ;
V_105 = F_52 ( V_99 ) ;
if ( V_105 < ( V_4 -> V_61 >> 1 ) ) {
V_4 -> V_69 . V_94 = false ;
return 0 ;
}
V_105 -= 1 ;
if ( V_105 > V_47 )
V_105 = V_47 ;
if ( V_99 -> V_106 < V_99 -> V_107 )
memcpy ( & V_69 -> V_45 [ 0 ] , & V_99 -> V_45 [ V_99 -> V_106 ] , V_105 ) ;
else {
T_6 V_108 = V_109 - V_99 -> V_106 ;
T_6 V_110 ;
if ( V_108 > V_105 )
V_108 = V_105 ;
V_110 = V_105 - V_108 ;
memcpy ( & V_69 -> V_45 [ 0 ] , & V_99 -> V_45 [ V_99 -> V_106 ] , V_108 ) ;
if ( V_110 )
memcpy ( & V_69 -> V_45 [ V_108 ] , & V_99 -> V_45 [ 0 ] , V_110 ) ;
}
V_69 -> V_41 . V_111 = V_105 ;
if ( F_53 ( V_101 -> V_2 , & V_69 -> V_41 , 1 , V_95 ) != 1 ) {
V_4 -> V_69 . V_94 = false ;
F_54 ( V_4 -> V_8 . V_2 , L_12 ) ;
return - V_112 ;
}
V_103 = F_55 ( V_39 , & V_69 -> V_41 , 1 , V_59 ,
V_113 | V_114 ) ;
if ( ! V_103 ) {
F_46 ( V_101 -> V_2 , & V_69 -> V_41 , 1 , V_95 ) ;
V_4 -> V_69 . V_94 = false ;
F_54 ( V_4 -> V_8 . V_2 , L_13 ) ;
return - V_112 ;
}
V_103 -> V_115 = F_44 ;
V_103 -> V_116 = V_4 ;
F_56 ( V_103 ) ;
V_101 -> V_117 ( V_39 ) ;
V_4 -> V_92 |= V_96 ;
F_8 ( V_4 -> V_92 , V_4 , V_97 ) ;
V_4 -> V_69 . V_94 = true ;
V_99 -> V_106 = ( V_99 -> V_106 + V_105 ) & ( V_109 - 1 ) ;
V_4 -> V_8 . V_23 . V_118 += V_105 ;
if ( F_52 ( V_99 ) < V_119 )
F_57 ( & V_4 -> V_8 ) ;
return 1 ;
}
static bool F_58 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_120 )
return false ;
if ( V_4 -> V_69 . V_94 ) {
V_4 -> V_92 |= V_96 ;
F_8 ( V_4 -> V_92 , V_4 , V_97 ) ;
V_4 -> V_121 &= ~ V_122 ;
F_8 ( V_4 -> V_121 , V_4 , V_123 ) ;
return true ;
}
if ( F_50 ( V_4 ) > 0 ) {
V_4 -> V_121 &= ~ V_122 ;
F_8 ( V_4 -> V_121 , V_4 , V_123 ) ;
return true ;
}
return false ;
}
static inline void F_59 ( struct V_3 * V_4 )
{
if ( V_4 -> V_69 . V_94 ) {
V_4 -> V_92 &= ~ V_96 ;
F_8 ( V_4 -> V_92 , V_4 , V_97 ) ;
}
}
static inline bool F_60 ( struct V_3 * V_4 )
{
T_2 V_92 ;
if ( ! V_4 -> V_120 )
return false ;
if ( ! V_4 -> V_8 . V_124 ) {
bool V_125 = true ;
if ( ! V_4 -> V_69 . V_94 ) {
if ( F_50 ( V_4 ) > 0 ) {
V_4 -> V_121 &= ~ V_122 ;
F_8 ( V_4 -> V_121 , V_4 , V_123 ) ;
} else
V_125 = false ;
} else if ( ! ( V_4 -> V_92 & V_96 ) ) {
V_4 -> V_92 |= V_96 ;
F_8 ( V_4 -> V_92 , V_4 , V_97 ) ;
}
return V_125 ;
}
V_92 = V_4 -> V_92 ;
V_4 -> V_92 &= ~ V_96 ;
F_8 ( V_4 -> V_92 , V_4 , V_97 ) ;
if ( F_5 ( V_4 , V_18 ) & V_126 ) {
return false ;
}
F_8 ( V_4 -> V_8 . V_124 , V_4 , V_20 ) ;
V_4 -> V_8 . V_23 . V_118 ++ ;
V_4 -> V_8 . V_124 = 0 ;
V_4 -> V_92 = V_92 ;
F_8 ( V_92 , V_4 , V_97 ) ;
return true ;
}
static void F_61 ( struct V_127 * V_8 )
__releases( &uap->port.lock
static int F_62 ( struct V_3 * V_4 )
{
struct V_38 * V_128 = V_4 -> V_80 . V_39 ;
struct V_129 * V_80 = & V_4 -> V_80 ;
struct V_102 * V_103 ;
struct V_40 * V_130 ;
if ( ! V_128 )
return - V_131 ;
V_130 = V_4 -> V_80 . V_132 ?
& V_4 -> V_80 . V_133 : & V_4 -> V_80 . V_134 ;
V_103 = F_55 ( V_128 , & V_130 -> V_41 , 1 ,
V_74 ,
V_113 | V_114 ) ;
if ( ! V_103 ) {
V_4 -> V_80 . V_135 = false ;
F_63 ( V_128 ) ;
return - V_112 ;
}
V_103 -> V_115 = V_136 ;
V_103 -> V_116 = V_4 ;
V_80 -> V_137 = F_56 ( V_103 ) ;
F_64 ( V_128 ) ;
V_4 -> V_92 |= V_138 ;
F_8 ( V_4 -> V_92 , V_4 , V_97 ) ;
V_4 -> V_80 . V_135 = true ;
V_4 -> V_121 &= ~ V_139 ;
F_8 ( V_4 -> V_121 , V_4 , V_123 ) ;
return 0 ;
}
static void F_65 ( struct V_3 * V_4 ,
T_5 V_140 , bool V_132 ,
bool V_141 )
{
struct V_142 * V_8 = & V_4 -> V_8 . V_98 -> V_8 ;
struct V_40 * V_130 = V_132 ?
& V_4 -> V_80 . V_133 : & V_4 -> V_80 . V_134 ;
int V_143 = 0 ;
T_5 V_17 = 0 ;
struct V_129 * V_80 = & V_4 -> V_80 ;
int V_144 = 0 ;
if ( V_4 -> V_80 . V_84 ) {
V_144 = V_130 -> V_41 . V_111 - V_80 -> V_145 ;
if ( V_140 >= V_144 )
V_140 -= V_144 ;
}
if ( V_140 ) {
V_143 = F_66 ( V_8 , V_130 -> V_45 + V_144 ,
V_140 ) ;
V_4 -> V_8 . V_23 . V_24 += V_143 ;
if ( V_143 < V_140 )
F_67 ( V_4 -> V_8 . V_2 ,
L_14 ) ;
}
if ( V_4 -> V_80 . V_84 )
V_80 -> V_145 = V_130 -> V_41 . V_111 ;
if ( V_143 == V_140 && V_141 ) {
F_8 ( V_146 | V_147 | V_148 |
V_149 , V_4 , V_150 ) ;
V_17 = F_11 ( V_4 ) ;
}
F_68 ( & V_4 -> V_8 . V_93 ) ;
F_69 ( V_4 -> V_8 . V_2 ,
L_15 ,
V_143 , V_17 ) ;
F_70 ( V_8 ) ;
F_71 ( & V_4 -> V_8 . V_93 ) ;
}
static void F_72 ( struct V_3 * V_4 )
{
struct V_129 * V_80 = & V_4 -> V_80 ;
struct V_38 * V_128 = V_80 -> V_39 ;
struct V_40 * V_130 = V_80 -> V_132 ?
& V_80 -> V_133 : & V_80 -> V_134 ;
T_6 V_140 ;
struct V_151 V_98 ;
enum V_152 V_153 ;
if ( F_73 ( V_128 ) )
F_35 ( V_4 -> V_8 . V_2 , L_16 ) ;
V_153 = V_128 -> V_46 -> V_154 ( V_128 ,
V_80 -> V_137 , & V_98 ) ;
if ( V_153 != V_155 )
F_35 ( V_4 -> V_8 . V_2 , L_16 ) ;
V_4 -> V_92 &= ~ V_138 ;
F_8 ( V_4 -> V_92 , V_4 , V_97 ) ;
V_4 -> V_80 . V_135 = false ;
V_140 = V_130 -> V_41 . V_111 - V_98 . V_156 ;
F_74 ( V_140 > V_47 ) ;
F_63 ( V_128 ) ;
F_65 ( V_4 , V_140 , V_80 -> V_132 , true ) ;
V_80 -> V_132 = ! V_80 -> V_132 ;
if ( F_62 ( V_4 ) ) {
F_54 ( V_4 -> V_8 . V_2 , L_17
L_18 ) ;
V_4 -> V_121 |= V_139 ;
F_8 ( V_4 -> V_121 , V_4 , V_123 ) ;
}
}
static void V_136 ( void * V_89 )
{
struct V_3 * V_4 = V_89 ;
struct V_129 * V_80 = & V_4 -> V_80 ;
struct V_38 * V_128 = V_80 -> V_39 ;
bool V_157 = V_80 -> V_132 ;
struct V_40 * V_130 = V_80 -> V_132 ?
& V_80 -> V_133 : & V_80 -> V_134 ;
T_6 V_140 ;
struct V_151 V_98 ;
int V_125 ;
F_75 ( & V_4 -> V_8 . V_93 ) ;
V_128 -> V_46 -> V_154 ( V_128 , V_80 -> V_137 , & V_98 ) ;
V_140 = V_130 -> V_41 . V_111 - V_98 . V_156 ;
F_74 ( V_140 > V_47 ) ;
F_63 ( V_128 ) ;
V_4 -> V_80 . V_135 = false ;
V_80 -> V_132 = ! V_157 ;
V_125 = F_62 ( V_4 ) ;
F_65 ( V_4 , V_140 , V_157 , false ) ;
F_76 ( & V_4 -> V_8 . V_93 ) ;
if ( V_125 ) {
F_54 ( V_4 -> V_8 . V_2 , L_17
L_18 ) ;
V_4 -> V_121 |= V_139 ;
F_8 ( V_4 -> V_121 , V_4 , V_123 ) ;
}
}
static inline void F_77 ( struct V_3 * V_4 )
{
V_4 -> V_92 &= ~ V_138 ;
F_8 ( V_4 -> V_92 , V_4 , V_97 ) ;
}
static void F_78 ( unsigned long args )
{
struct V_3 * V_4 = (struct V_3 * ) args ;
struct V_142 * V_8 = & V_4 -> V_8 . V_98 -> V_8 ;
struct V_129 * V_80 = & V_4 -> V_80 ;
struct V_38 * V_128 = V_4 -> V_80 . V_39 ;
unsigned long V_91 = 0 ;
unsigned int V_144 = 0 ;
unsigned int V_158 = 0 ;
struct V_40 * V_130 ;
int V_143 ;
struct V_151 V_98 ;
V_130 = V_80 -> V_132 ? & V_4 -> V_80 . V_133 : & V_4 -> V_80 . V_134 ;
V_128 -> V_46 -> V_154 ( V_128 , V_80 -> V_137 , & V_98 ) ;
if ( F_79 ( V_98 . V_156 < V_80 -> V_145 ) ) {
V_144 = V_130 -> V_41 . V_111 - V_80 -> V_145 ;
V_158 = V_80 -> V_145 - V_98 . V_156 ;
V_143 = F_66 ( V_8 , V_130 -> V_45 + V_144 ,
V_158 ) ;
if ( V_143 == V_158 )
V_80 -> V_145 = V_98 . V_156 ;
V_80 -> V_159 = V_160 ;
}
F_70 ( V_8 ) ;
if ( F_80 ( V_160 - V_80 -> V_159 )
> V_4 -> V_80 . V_86 ) {
F_45 ( & V_4 -> V_8 . V_93 , V_91 ) ;
F_77 ( V_4 ) ;
V_4 -> V_121 |= V_139 ;
F_8 ( V_4 -> V_121 , V_4 , V_123 ) ;
F_49 ( & V_4 -> V_8 . V_93 , V_91 ) ;
V_4 -> V_80 . V_135 = false ;
F_63 ( V_128 ) ;
F_81 ( & V_4 -> V_80 . V_161 ) ;
} else {
F_82 ( & V_4 -> V_80 . V_161 ,
V_160 + F_83 ( V_4 -> V_80 . V_84 ) ) ;
}
}
static void F_84 ( struct V_3 * V_4 )
{
int V_125 ;
if ( ! V_4 -> V_64 )
F_26 ( V_4 ) ;
if ( ! V_4 -> V_69 . V_39 )
return;
V_4 -> V_69 . V_45 = F_85 ( V_47 , V_48 | V_162 ) ;
if ( ! V_4 -> V_69 . V_45 ) {
F_35 ( V_4 -> V_8 . V_2 , L_19 ) ;
V_4 -> V_8 . V_61 = V_4 -> V_61 ;
return;
}
F_86 ( & V_4 -> V_69 . V_41 , V_4 -> V_69 . V_45 , V_47 ) ;
V_4 -> V_8 . V_61 = V_47 ;
V_4 -> V_120 = true ;
if ( ! V_4 -> V_80 . V_39 )
goto V_163;
V_125 = F_16 ( V_4 -> V_80 . V_39 , & V_4 -> V_80 . V_134 ,
V_164 ) ;
if ( V_125 ) {
F_35 ( V_4 -> V_8 . V_2 , L_20 ,
L_21 , V_125 ) ;
goto V_163;
}
V_125 = F_16 ( V_4 -> V_80 . V_39 , & V_4 -> V_80 . V_133 ,
V_164 ) ;
if ( V_125 ) {
F_35 ( V_4 -> V_8 . V_2 , L_20 ,
L_22 , V_125 ) ;
F_24 ( V_4 -> V_80 . V_39 , & V_4 -> V_80 . V_134 ,
V_164 ) ;
goto V_163;
}
V_4 -> V_165 = true ;
V_163:
V_4 -> V_92 |= V_166 ;
F_8 ( V_4 -> V_92 , V_4 , V_97 ) ;
if ( V_4 -> V_167 -> V_168 )
F_8 ( V_169 | V_170 ,
V_4 , V_171 ) ;
if ( V_4 -> V_165 ) {
if ( F_62 ( V_4 ) )
F_54 ( V_4 -> V_8 . V_2 , L_23
L_24 ) ;
if ( V_4 -> V_80 . V_84 ) {
F_87 ( & ( V_4 -> V_80 . V_161 ) ) ;
V_4 -> V_80 . V_161 . V_172 = F_78 ;
V_4 -> V_80 . V_161 . V_89 = ( unsigned long ) V_4 ;
F_82 ( & V_4 -> V_80 . V_161 ,
V_160 +
F_83 ( V_4 -> V_80 . V_84 ) ) ;
V_4 -> V_80 . V_145 = V_47 ;
V_4 -> V_80 . V_159 = V_160 ;
}
}
}
static void F_88 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_120 || V_4 -> V_165 ) )
return;
while ( F_5 ( V_4 , V_18 ) & V_173 )
F_89 () ;
F_75 ( & V_4 -> V_8 . V_93 ) ;
V_4 -> V_92 &= ~ ( V_166 | V_138 | V_96 ) ;
F_8 ( V_4 -> V_92 , V_4 , V_97 ) ;
F_76 ( & V_4 -> V_8 . V_93 ) ;
if ( V_4 -> V_120 ) {
F_63 ( V_4 -> V_69 . V_39 ) ;
if ( V_4 -> V_69 . V_94 ) {
F_46 ( V_4 -> V_69 . V_39 -> V_46 -> V_2 , & V_4 -> V_69 . V_41 , 1 ,
V_95 ) ;
V_4 -> V_69 . V_94 = false ;
}
F_90 ( V_4 -> V_69 . V_45 ) ;
V_4 -> V_120 = false ;
}
if ( V_4 -> V_165 ) {
F_63 ( V_4 -> V_80 . V_39 ) ;
F_24 ( V_4 -> V_80 . V_39 , & V_4 -> V_80 . V_134 , V_164 ) ;
F_24 ( V_4 -> V_80 . V_39 , & V_4 -> V_80 . V_133 , V_164 ) ;
if ( V_4 -> V_80 . V_84 )
F_91 ( & V_4 -> V_80 . V_161 ) ;
V_4 -> V_165 = false ;
}
}
static inline bool F_92 ( struct V_3 * V_4 )
{
return V_4 -> V_165 ;
}
static inline bool F_93 ( struct V_3 * V_4 )
{
return V_4 -> V_165 && V_4 -> V_80 . V_135 ;
}
static inline void F_26 ( struct V_3 * V_4 )
{
}
static inline void F_43 ( struct V_3 * V_4 )
{
}
static inline void F_84 ( struct V_3 * V_4 )
{
}
static inline void F_88 ( struct V_3 * V_4 )
{
}
static inline bool F_58 ( struct V_3 * V_4 )
{
return false ;
}
static inline void F_59 ( struct V_3 * V_4 )
{
}
static inline bool F_60 ( struct V_3 * V_4 )
{
return false ;
}
static inline void F_72 ( struct V_3 * V_4 )
{
}
static inline void F_77 ( struct V_3 * V_4 )
{
}
static inline int F_62 ( struct V_3 * V_4 )
{
return - V_131 ;
}
static inline bool F_92 ( struct V_3 * V_4 )
{
return false ;
}
static inline bool F_93 ( struct V_3 * V_4 )
{
return false ;
}
static void F_94 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_95 ( V_8 , struct V_3 , V_8 ) ;
V_4 -> V_121 &= ~ V_122 ;
F_8 ( V_4 -> V_121 , V_4 , V_123 ) ;
F_59 ( V_4 ) ;
}
static void F_51 ( struct V_3 * V_4 )
{
V_4 -> V_121 |= V_122 ;
F_8 ( V_4 -> V_121 , V_4 , V_123 ) ;
F_96 ( V_4 , false ) ;
}
static void F_97 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_95 ( V_8 , struct V_3 , V_8 ) ;
if ( ! F_60 ( V_4 ) )
F_51 ( V_4 ) ;
}
static void F_98 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_95 ( V_8 , struct V_3 , V_8 ) ;
V_4 -> V_121 &= ~ ( V_139 | V_174 | V_175 |
V_176 | V_177 | V_178 ) ;
F_8 ( V_4 -> V_121 , V_4 , V_123 ) ;
F_77 ( V_4 ) ;
}
static void F_99 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_95 ( V_8 , struct V_3 , V_8 ) ;
V_4 -> V_121 |= V_179 | V_180 | V_181 | V_182 ;
F_8 ( V_4 -> V_121 , V_4 , V_123 ) ;
}
static void F_100 ( struct V_3 * V_4 )
__releases( &uap->port.lock
static bool F_101 ( struct V_3 * V_4 , unsigned char V_183 ,
bool V_184 )
{
if ( F_12 ( ! V_184 ) &&
F_5 ( V_4 , V_18 ) & V_126 )
return false ;
F_8 ( V_183 , V_4 , V_20 ) ;
V_4 -> V_8 . V_23 . V_118 ++ ;
return true ;
}
static void F_96 ( struct V_3 * V_4 , bool V_184 )
{
struct V_104 * V_99 = & V_4 -> V_8 . V_98 -> V_99 ;
int V_105 = V_4 -> V_61 >> 1 ;
if ( V_4 -> V_8 . V_124 ) {
if ( ! F_101 ( V_4 , V_4 -> V_8 . V_124 , V_184 ) )
return;
V_4 -> V_8 . V_124 = 0 ;
-- V_105 ;
}
if ( F_48 ( V_99 ) || F_47 ( & V_4 -> V_8 ) ) {
F_94 ( & V_4 -> V_8 ) ;
return;
}
if ( F_58 ( V_4 ) )
return;
do {
if ( F_79 ( V_184 ) && V_105 -- == 0 )
break;
if ( ! F_101 ( V_4 , V_99 -> V_45 [ V_99 -> V_106 ] , V_184 ) )
break;
V_99 -> V_106 = ( V_99 -> V_106 + 1 ) & ( V_109 - 1 ) ;
} while ( ! F_48 ( V_99 ) );
if ( F_52 ( V_99 ) < V_119 )
F_57 ( & V_4 -> V_8 ) ;
if ( F_48 ( V_99 ) )
F_94 ( & V_4 -> V_8 ) ;
}
static void F_102 ( struct V_3 * V_4 )
{
unsigned int V_13 , V_185 ;
V_13 = F_5 ( V_4 , V_18 ) & V_186 ;
V_185 = V_13 ^ V_4 -> V_187 ;
V_4 -> V_187 = V_13 ;
if ( ! V_185 )
return;
if ( V_185 & V_188 )
F_103 ( & V_4 -> V_8 , V_13 & V_188 ) ;
if ( V_185 & V_189 )
V_4 -> V_8 . V_23 . V_190 ++ ;
if ( V_185 & V_191 )
F_104 ( & V_4 -> V_8 , V_13 & V_191 ) ;
F_105 ( & V_4 -> V_8 . V_98 -> V_8 . V_192 ) ;
}
static void F_106 ( struct V_3 * V_4 )
{
unsigned int V_193 ;
if ( ! V_4 -> V_167 -> V_194 )
return;
F_8 ( 0x00 , V_4 , V_150 ) ;
V_193 = F_5 ( V_4 , V_150 ) ;
V_193 = F_5 ( V_4 , V_150 ) ;
}
static T_7 F_107 ( int V_195 , void * V_196 )
{
struct V_3 * V_4 = V_196 ;
unsigned long V_91 ;
unsigned int V_13 , V_197 = V_198 ;
T_2 V_199 ;
int V_200 = 0 ;
F_45 ( & V_4 -> V_8 . V_93 , V_91 ) ;
V_199 = F_5 ( V_4 , V_123 ) ;
V_13 = F_5 ( V_4 , V_201 ) & V_199 ;
if ( V_13 ) {
do {
F_106 ( V_4 ) ;
F_8 ( V_13 & ~ ( V_202 | V_203 |
V_204 ) ,
V_4 , V_150 ) ;
if ( V_13 & ( V_203 | V_204 ) ) {
if ( F_93 ( V_4 ) )
F_72 ( V_4 ) ;
else
F_100 ( V_4 ) ;
}
if ( V_13 & ( V_205 | V_206 |
V_207 | V_208 ) )
F_102 ( V_4 ) ;
if ( V_13 & V_202 )
F_96 ( V_4 , true ) ;
if ( V_197 -- == 0 )
break;
V_13 = F_5 ( V_4 , V_201 ) & V_199 ;
} while ( V_13 != 0 );
V_200 = 1 ;
}
F_49 ( & V_4 -> V_8 . V_93 , V_91 ) ;
return F_108 ( V_200 ) ;
}
static unsigned int F_109 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_95 ( V_8 , struct V_3 , V_8 ) ;
unsigned int V_13 = F_5 ( V_4 , V_18 ) ;
return V_13 & ( V_173 | V_126 ) ? 0 : V_209 ;
}
static unsigned int F_110 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_95 ( V_8 , struct V_3 , V_8 ) ;
unsigned int V_210 = 0 ;
unsigned int V_13 = F_5 ( V_4 , V_18 ) ;
#define F_111 ( T_8 , T_9 ) \
if (status & uartbit) \
result |= tiocmbit
F_111 ( V_188 , V_211 ) ;
F_111 ( V_189 , V_212 ) ;
F_111 ( V_191 , V_213 ) ;
F_111 ( V_214 , V_215 ) ;
#undef F_111
return V_210 ;
}
static void F_112 ( struct V_127 * V_8 , unsigned int V_216 )
{
struct V_3 * V_4 =
F_95 ( V_8 , struct V_3 , V_8 ) ;
unsigned int V_217 ;
V_217 = F_5 ( V_4 , V_218 ) ;
#define F_111 ( T_9 , T_8 ) \
if (mctrl & tiocmbit) \
cr |= uartbit; \
else \
cr &= ~uartbit
F_111 ( V_219 , V_220 ) ;
F_111 ( V_221 , V_222 ) ;
F_111 ( V_223 , V_224 ) ;
F_111 ( V_225 , V_226 ) ;
F_111 ( V_227 , V_228 ) ;
if ( V_4 -> V_229 ) {
F_111 ( V_219 , V_230 ) ;
}
#undef F_111
F_8 ( V_217 , V_4 , V_218 ) ;
}
static void F_113 ( struct V_127 * V_8 , int V_231 )
{
struct V_3 * V_4 =
F_95 ( V_8 , struct V_3 , V_8 ) ;
unsigned long V_91 ;
unsigned int V_232 ;
F_45 ( & V_4 -> V_8 . V_93 , V_91 ) ;
V_232 = F_5 ( V_4 , V_233 ) ;
if ( V_231 == - 1 )
V_232 |= V_234 ;
else
V_232 &= ~ V_234 ;
F_8 ( V_232 , V_4 , V_233 ) ;
F_49 ( & V_4 -> V_8 . V_93 , V_91 ) ;
}
static void F_114 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_95 ( V_8 , struct V_3 , V_8 ) ;
F_8 ( F_5 ( V_4 , V_235 ) , V_4 , V_150 ) ;
F_8 ( F_5 ( V_4 , V_123 ) & ~ V_122 , V_4 ,
V_123 ) ;
}
static int F_115 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_95 ( V_8 , struct V_3 , V_8 ) ;
unsigned int V_13 ;
F_114 ( V_8 ) ;
V_13 = F_5 ( V_4 , V_18 ) ;
if ( V_13 & V_19 )
return V_236 ;
return F_5 ( V_4 , V_20 ) ;
}
static void F_116 ( struct V_127 * V_8 ,
unsigned char V_14 )
{
struct V_3 * V_4 =
F_95 ( V_8 , struct V_3 , V_8 ) ;
while ( F_5 ( V_4 , V_18 ) & V_126 )
F_89 () ;
F_8 ( V_14 , V_4 , V_20 ) ;
}
static int F_117 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_95 ( V_8 , struct V_3 , V_8 ) ;
int V_237 ;
F_118 ( V_8 -> V_2 ) ;
V_237 = F_119 ( V_4 -> V_238 ) ;
if ( V_237 )
return V_237 ;
V_4 -> V_8 . V_239 = F_120 ( V_4 -> V_238 ) ;
F_8 ( V_146 | V_147 | V_148 |
V_149 | V_203 | V_204 ,
V_4 , V_150 ) ;
V_4 -> V_121 = F_5 ( V_4 , V_123 ) ;
F_8 ( V_174 | V_139 , V_4 , V_123 ) ;
if ( F_27 ( V_4 -> V_8 . V_2 ) ) {
struct V_50 * V_51 ;
V_51 = F_27 ( V_4 -> V_8 . V_2 ) ;
if ( V_51 -> V_240 )
V_51 -> V_240 () ;
}
return 0 ;
}
static bool F_121 ( const struct V_3 * V_4 )
{
return F_4 ( V_4 , V_241 ) !=
F_4 ( V_4 , V_233 ) ;
}
static void F_122 ( struct V_3 * V_4 , unsigned int V_232 )
{
F_8 ( V_232 , V_4 , V_241 ) ;
if ( F_121 ( V_4 ) ) {
int V_242 ;
for ( V_242 = 0 ; V_242 < 10 ; ++ V_242 )
F_8 ( 0xff , V_4 , V_235 ) ;
F_8 ( V_232 , V_4 , V_233 ) ;
}
}
static int F_123 ( struct V_3 * V_4 )
{
F_8 ( V_4 -> V_121 , V_4 , V_123 ) ;
return F_124 ( V_4 -> V_8 . V_195 , F_107 , 0 , L_25 , V_4 ) ;
}
static void F_125 ( struct V_3 * V_4 )
{
F_75 ( & V_4 -> V_8 . V_93 ) ;
F_8 ( V_203 | V_204 , V_4 , V_150 ) ;
V_4 -> V_121 = V_174 ;
if ( ! F_93 ( V_4 ) )
V_4 -> V_121 |= V_139 ;
F_8 ( V_4 -> V_121 , V_4 , V_123 ) ;
F_76 ( & V_4 -> V_8 . V_93 ) ;
}
static int F_126 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_95 ( V_8 , struct V_3 , V_8 ) ;
unsigned int V_217 ;
int V_237 ;
V_237 = F_117 ( V_8 ) ;
if ( V_237 )
goto V_243;
V_237 = F_123 ( V_4 ) ;
if ( V_237 )
goto V_243;
F_8 ( V_4 -> V_167 -> V_244 , V_4 , V_245 ) ;
F_75 ( & V_4 -> V_8 . V_93 ) ;
V_217 = V_4 -> V_246 & ( V_220 | V_222 ) ;
V_217 |= V_247 | V_248 | V_249 ;
F_8 ( V_217 , V_4 , V_218 ) ;
F_76 ( & V_4 -> V_8 . V_93 ) ;
V_4 -> V_187 = F_5 ( V_4 , V_18 ) & V_186 ;
F_84 ( V_4 ) ;
F_125 ( V_4 ) ;
return 0 ;
V_243:
F_127 ( V_4 -> V_238 ) ;
return V_237 ;
}
static int F_128 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_95 ( V_8 , struct V_3 , V_8 ) ;
int V_237 ;
V_237 = F_117 ( V_8 ) ;
if ( V_237 )
return V_237 ;
V_237 = F_123 ( V_4 ) ;
if ( V_237 )
return V_237 ;
V_4 -> V_187 = 0 ;
F_125 ( V_4 ) ;
return 0 ;
}
static void F_129 ( struct V_3 * V_4 ,
unsigned int V_250 )
{
unsigned long V_12 ;
V_12 = F_5 ( V_4 , V_250 ) ;
V_12 &= ~ ( V_234 | V_251 ) ;
F_8 ( V_12 , V_4 , V_250 ) ;
}
static void F_130 ( struct V_3 * V_4 )
{
unsigned int V_217 ;
V_4 -> V_229 = false ;
F_75 ( & V_4 -> V_8 . V_93 ) ;
V_217 = F_5 ( V_4 , V_218 ) ;
V_4 -> V_246 = V_217 ;
V_217 &= V_220 | V_222 ;
V_217 |= V_247 | V_249 ;
F_8 ( V_217 , V_4 , V_218 ) ;
F_76 ( & V_4 -> V_8 . V_93 ) ;
F_129 ( V_4 , V_241 ) ;
if ( F_121 ( V_4 ) )
F_129 ( V_4 , V_233 ) ;
}
static void F_131 ( struct V_3 * V_4 )
{
F_75 ( & V_4 -> V_8 . V_93 ) ;
V_4 -> V_121 = 0 ;
F_8 ( V_4 -> V_121 , V_4 , V_123 ) ;
F_8 ( 0xffff , V_4 , V_150 ) ;
F_76 ( & V_4 -> V_8 . V_93 ) ;
}
static void F_132 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_95 ( V_8 , struct V_3 , V_8 ) ;
F_131 ( V_4 ) ;
F_88 ( V_4 ) ;
F_133 ( V_4 -> V_8 . V_195 , V_4 ) ;
F_130 ( V_4 ) ;
F_127 ( V_4 -> V_238 ) ;
F_134 ( V_8 -> V_2 ) ;
if ( F_27 ( V_4 -> V_8 . V_2 ) ) {
struct V_50 * V_51 ;
V_51 = F_27 ( V_4 -> V_8 . V_2 ) ;
if ( V_51 -> exit )
V_51 -> exit () ;
}
if ( V_4 -> V_8 . V_252 -> V_253 )
V_4 -> V_8 . V_252 -> V_253 ( V_8 ) ;
}
static void F_135 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_95 ( V_8 , struct V_3 , V_8 ) ;
F_131 ( V_4 ) ;
F_133 ( V_4 -> V_8 . V_195 , V_4 ) ;
if ( V_4 -> V_8 . V_252 -> V_253 )
V_4 -> V_8 . V_252 -> V_253 ( V_8 ) ;
}
static void
F_136 ( struct V_127 * V_8 , struct V_254 * V_255 )
{
V_8 -> V_34 = V_32 | 255 ;
if ( V_255 -> V_256 & V_257 )
V_8 -> V_34 |= V_27 | V_28 ;
if ( V_255 -> V_256 & ( V_258 | V_259 | V_260 ) )
V_8 -> V_34 |= V_26 ;
V_8 -> V_261 = 0 ;
if ( V_255 -> V_256 & V_262 )
V_8 -> V_261 |= V_27 | V_28 ;
if ( V_255 -> V_256 & V_258 ) {
V_8 -> V_261 |= V_26 ;
if ( V_255 -> V_256 & V_262 )
V_8 -> V_261 |= V_32 ;
}
if ( ( V_255 -> V_263 & V_264 ) == 0 )
V_8 -> V_261 |= V_21 ;
}
static void
F_137 ( struct V_127 * V_8 , struct V_254 * V_255 ,
struct V_254 * V_265 )
{
struct V_3 * V_4 =
F_95 ( V_8 , struct V_3 , V_8 ) ;
unsigned int V_232 , V_246 ;
unsigned long V_91 ;
unsigned int V_266 , V_267 , V_268 ;
if ( V_4 -> V_167 -> V_269 )
V_268 = 8 ;
else
V_268 = 16 ;
V_266 = F_138 ( V_8 , V_255 , V_265 , 0 ,
V_8 -> V_239 / V_268 ) ;
#ifdef F_139
if ( V_4 -> V_80 . V_81 )
V_4 -> V_80 . V_84 = F_140 ( 10000000 , V_266 ) ;
#endif
if ( V_266 > V_8 -> V_239 / 16 )
V_267 = F_141 ( V_8 -> V_239 * 8 , V_266 ) ;
else
V_267 = F_141 ( V_8 -> V_239 * 4 , V_266 ) ;
switch ( V_255 -> V_263 & V_270 ) {
case V_271 :
V_232 = V_272 ;
break;
case V_273 :
V_232 = V_274 ;
break;
case V_275 :
V_232 = V_276 ;
break;
default:
V_232 = V_277 ;
break;
}
if ( V_255 -> V_263 & V_278 )
V_232 |= V_279 ;
if ( V_255 -> V_263 & V_280 ) {
V_232 |= V_281 ;
if ( ! ( V_255 -> V_263 & V_282 ) )
V_232 |= V_283 ;
}
if ( V_4 -> V_61 > 1 )
V_232 |= V_251 ;
F_45 ( & V_8 -> V_93 , V_91 ) ;
F_142 ( V_8 , V_255 -> V_263 , V_266 ) ;
F_136 ( V_8 , V_255 ) ;
if ( F_143 ( V_8 , V_255 -> V_263 ) )
F_99 ( V_8 ) ;
V_246 = F_5 ( V_4 , V_218 ) ;
F_8 ( 0 , V_4 , V_218 ) ;
if ( V_255 -> V_263 & V_284 ) {
if ( V_246 & V_220 )
V_246 |= V_230 ;
V_246 |= V_285 ;
V_4 -> V_229 = true ;
} else {
V_246 &= ~ ( V_285 | V_230 ) ;
V_4 -> V_229 = false ;
}
if ( V_4 -> V_167 -> V_269 ) {
if ( V_266 > V_8 -> V_239 / 16 )
V_246 |= V_286 ;
else
V_246 &= ~ V_286 ;
}
if ( V_4 -> V_167 -> V_269 ) {
if ( ( V_266 >= 3000000 ) && ( V_266 < 3250000 ) && ( V_267 > 1 ) )
V_267 -= 1 ;
else if ( ( V_266 > 3250000 ) && ( V_267 > 2 ) )
V_267 -= 2 ;
}
F_8 ( V_267 & 0x3f , V_4 , V_287 ) ;
F_8 ( V_267 >> 6 , V_4 , V_288 ) ;
F_122 ( V_4 , V_232 ) ;
F_8 ( V_246 , V_4 , V_218 ) ;
F_49 ( & V_8 -> V_93 , V_91 ) ;
}
static void
F_144 ( struct V_127 * V_8 , struct V_254 * V_255 ,
struct V_254 * V_265 )
{
struct V_3 * V_4 =
F_95 ( V_8 , struct V_3 , V_8 ) ;
unsigned long V_91 ;
F_145 ( V_255 , V_4 -> V_289 , V_4 -> V_289 ) ;
V_255 -> V_263 &= ~ ( V_270 | V_278 | V_280 | V_282 ) ;
V_255 -> V_263 &= ~ ( V_290 | V_284 ) ;
V_255 -> V_263 |= V_291 | V_292 ;
F_45 ( & V_8 -> V_93 , V_91 ) ;
F_142 ( V_8 , V_291 , V_4 -> V_289 ) ;
F_136 ( V_8 , V_255 ) ;
F_49 ( & V_8 -> V_93 , V_91 ) ;
}
static const char * F_146 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_95 ( V_8 , struct V_3 , V_8 ) ;
return V_4 -> V_8 . type == V_293 ? V_4 -> type : NULL ;
}
static void F_147 ( struct V_127 * V_8 )
{
F_148 ( V_8 -> V_55 , V_294 ) ;
}
static int F_149 ( struct V_127 * V_8 )
{
return F_150 ( V_8 -> V_55 , V_294 , L_25 )
!= NULL ? 0 : - V_112 ;
}
static void F_151 ( struct V_127 * V_8 , int V_91 )
{
if ( V_91 & V_295 ) {
V_8 -> type = V_293 ;
F_149 ( V_8 ) ;
}
}
static int F_152 ( struct V_127 * V_8 , struct V_296 * V_297 )
{
int V_125 = 0 ;
if ( V_297 -> type != V_298 && V_297 -> type != V_293 )
V_125 = - V_299 ;
if ( V_297 -> V_195 < 0 || V_297 -> V_195 >= V_300 )
V_125 = - V_299 ;
if ( V_297 -> V_301 < 9600 )
V_125 = - V_299 ;
return V_125 ;
}
static void F_153 ( struct V_127 * V_8 , unsigned int V_216 )
{
}
static unsigned int F_154 ( struct V_127 * V_8 )
{
return 0 ;
}
static void F_155 ( struct V_127 * V_8 , int V_14 )
{
struct V_3 * V_4 =
F_95 ( V_8 , struct V_3 , V_8 ) ;
while ( F_5 ( V_4 , V_18 ) & V_126 )
F_89 () ;
F_8 ( V_14 , V_4 , V_20 ) ;
}
static void
F_156 ( struct V_302 * V_303 , const char * V_304 , unsigned int V_105 )
{
struct V_3 * V_4 = V_305 [ V_303 -> V_306 ] ;
unsigned int V_13 , V_246 = 0 , V_307 ;
unsigned long V_91 ;
int V_308 = 1 ;
F_157 ( V_4 -> V_238 ) ;
F_158 ( V_91 ) ;
if ( V_4 -> V_8 . V_309 )
V_308 = 0 ;
else if ( V_310 )
V_308 = F_159 ( & V_4 -> V_8 . V_93 ) ;
else
F_71 ( & V_4 -> V_8 . V_93 ) ;
if ( ! V_4 -> V_167 -> V_311 ) {
V_246 = F_5 ( V_4 , V_218 ) ;
V_307 = V_246 & ~ V_285 ;
V_307 |= V_247 | V_249 ;
F_8 ( V_307 , V_4 , V_218 ) ;
}
F_160 ( & V_4 -> V_8 , V_304 , V_105 , F_155 ) ;
do {
V_13 = F_5 ( V_4 , V_18 ) ;
} while ( V_13 & V_173 );
if ( ! V_4 -> V_167 -> V_311 )
F_8 ( V_246 , V_4 , V_218 ) ;
if ( V_308 )
F_68 ( & V_4 -> V_8 . V_93 ) ;
F_161 ( V_91 ) ;
F_162 ( V_4 -> V_238 ) ;
}
static void T_10
F_163 ( struct V_3 * V_4 , int * V_266 ,
int * V_30 , int * V_312 )
{
if ( F_5 ( V_4 , V_218 ) & V_247 ) {
unsigned int V_232 , V_313 , V_314 ;
V_232 = F_5 ( V_4 , V_233 ) ;
* V_30 = 'n' ;
if ( V_232 & V_281 ) {
if ( V_232 & V_283 )
* V_30 = 'e' ;
else
* V_30 = 'o' ;
}
if ( ( V_232 & 0x60 ) == V_276 )
* V_312 = 7 ;
else
* V_312 = 8 ;
V_313 = F_5 ( V_4 , V_288 ) ;
V_314 = F_5 ( V_4 , V_287 ) ;
* V_266 = V_4 -> V_8 . V_239 * 4 / ( 64 * V_313 + V_314 ) ;
if ( V_4 -> V_167 -> V_269 ) {
if ( F_5 ( V_4 , V_218 )
& V_286 )
* V_266 *= 2 ;
}
}
}
static int T_10 F_164 ( struct V_302 * V_303 , char * V_315 )
{
struct V_3 * V_4 ;
int V_266 = 38400 ;
int V_312 = 8 ;
int V_30 = 'n' ;
int V_316 = 'n' ;
int V_125 ;
if ( V_303 -> V_306 >= V_317 )
V_303 -> V_306 = 0 ;
V_4 = V_305 [ V_303 -> V_306 ] ;
if ( ! V_4 )
return - V_318 ;
F_118 ( V_4 -> V_8 . V_2 ) ;
V_125 = F_165 ( V_4 -> V_238 ) ;
if ( V_125 )
return V_125 ;
if ( F_27 ( V_4 -> V_8 . V_2 ) ) {
struct V_50 * V_51 ;
V_51 = F_27 ( V_4 -> V_8 . V_2 ) ;
if ( V_51 -> V_240 )
V_51 -> V_240 () ;
}
V_4 -> V_8 . V_239 = F_120 ( V_4 -> V_238 ) ;
if ( V_4 -> V_167 -> V_319 ) {
V_266 = V_4 -> V_289 ;
} else {
if ( V_315 )
F_166 ( V_315 ,
& V_266 , & V_30 , & V_312 , & V_316 ) ;
else
F_163 ( V_4 , & V_266 , & V_30 , & V_312 ) ;
}
return F_167 ( & V_4 -> V_8 , V_303 , V_266 , V_30 , V_312 , V_316 ) ;
}
static void F_168 ( struct V_127 * V_8 , int V_183 )
{
while ( F_169 ( V_8 -> V_9 + V_320 ) & V_126 )
;
if ( V_8 -> V_10 == V_11 )
F_170 ( V_183 , V_8 -> V_9 + V_321 ) ;
else
F_171 ( V_183 , V_8 -> V_9 + V_321 ) ;
while ( F_169 ( V_8 -> V_9 + V_320 ) & V_173 )
;
}
static void F_172 ( struct V_302 * V_322 , const char * V_304 , unsigned V_323 )
{
struct V_324 * V_2 = V_322 -> V_89 ;
F_160 ( & V_2 -> V_8 , V_304 , V_323 , F_168 ) ;
}
static int T_10 F_173 ( struct V_324 * V_46 ,
const char * V_325 )
{
if ( ! V_46 -> V_8 . V_9 )
return - V_318 ;
V_46 -> V_322 -> V_326 = F_172 ;
return 0 ;
}
static int F_174 ( int V_306 , struct V_46 * V_2 )
{
struct V_327 * V_328 ;
static bool V_329 = false ;
static bool V_330 = false ;
int V_125 = V_306 ;
if ( ! F_175 ( V_331 ) )
return V_125 ;
V_328 = V_2 -> V_87 ;
if ( ! V_328 )
return V_125 ;
V_125 = F_176 ( V_328 , L_26 ) ;
if ( F_177 ( V_125 ) ) {
V_330 = true ;
V_125 = V_306 ;
} else {
V_329 = true ;
if ( V_125 >= F_178 ( V_305 ) || V_305 [ V_125 ] != NULL ) {
F_67 ( V_2 , L_27 , V_125 ) ;
V_125 = V_306 ;
}
}
if ( V_329 && V_330 )
F_67 ( V_2 , L_28 ) ;
return V_125 ;
}
static void F_179 ( struct V_3 * V_4 )
{
int V_242 ;
bool V_332 = false ;
for ( V_242 = 0 ; V_242 < F_178 ( V_305 ) ; V_242 ++ ) {
if ( V_305 [ V_242 ] == V_4 )
V_305 [ V_242 ] = NULL ;
else if ( V_305 [ V_242 ] )
V_332 = true ;
}
F_43 ( V_4 ) ;
if ( ! V_332 )
F_180 ( & V_333 ) ;
}
static int F_181 ( void )
{
int V_242 ;
for ( V_242 = 0 ; V_242 < F_178 ( V_305 ) ; V_242 ++ )
if ( V_305 [ V_242 ] == NULL )
return V_242 ;
return - V_112 ;
}
static int F_182 ( struct V_46 * V_2 , struct V_3 * V_4 ,
struct V_334 * V_335 , int V_306 )
{
void T_1 * V_336 ;
V_336 = F_183 ( V_2 , V_335 ) ;
if ( F_29 ( V_336 ) )
return F_30 ( V_336 ) ;
V_306 = F_174 ( V_306 , V_2 ) ;
V_4 -> V_246 = 0 ;
V_4 -> V_8 . V_2 = V_2 ;
V_4 -> V_8 . V_55 = V_335 -> V_337 ;
V_4 -> V_8 . V_9 = V_336 ;
V_4 -> V_8 . V_61 = V_4 -> V_61 ;
V_4 -> V_8 . V_91 = V_338 ;
V_4 -> V_8 . line = V_306 ;
V_305 [ V_306 ] = V_4 ;
return 0 ;
}
static int F_184 ( struct V_3 * V_4 )
{
int V_125 ;
F_8 ( 0 , V_4 , V_123 ) ;
F_8 ( 0xffff , V_4 , V_150 ) ;
if ( ! V_333 . V_98 ) {
V_125 = F_185 ( & V_333 ) ;
if ( V_125 < 0 ) {
F_35 ( V_4 -> V_8 . V_2 ,
L_29 ) ;
return V_125 ;
}
}
V_125 = F_186 ( & V_333 , & V_4 -> V_8 ) ;
if ( V_125 )
F_179 ( V_4 ) ;
return V_125 ;
}
static int F_187 ( struct V_1 * V_2 , const struct V_339 * V_340 )
{
struct V_3 * V_4 ;
struct V_341 * V_167 = V_340 -> V_89 ;
int V_342 , V_125 ;
V_342 = F_181 () ;
if ( V_342 < 0 )
return V_342 ;
V_4 = F_188 ( & V_2 -> V_2 , sizeof( struct V_3 ) ,
V_48 ) ;
if ( ! V_4 )
return - V_49 ;
V_4 -> V_238 = F_189 ( & V_2 -> V_2 , NULL ) ;
if ( F_29 ( V_4 -> V_238 ) )
return F_30 ( V_4 -> V_238 ) ;
V_4 -> V_6 = V_167 -> V_6 ;
V_4 -> V_167 = V_167 ;
V_4 -> V_61 = V_167 -> V_343 ( V_2 ) ;
V_4 -> V_8 . V_10 = V_167 -> V_344 ? V_11 : V_345 ;
V_4 -> V_8 . V_195 = V_2 -> V_195 [ 0 ] ;
V_4 -> V_8 . V_252 = & V_346 ;
snprintf ( V_4 -> type , sizeof( V_4 -> type ) , L_30 , F_2 ( V_2 ) ) ;
V_125 = F_182 ( & V_2 -> V_2 , V_4 , & V_2 -> V_347 , V_342 ) ;
if ( V_125 )
return V_125 ;
F_190 ( V_2 , V_4 ) ;
return F_184 ( V_4 ) ;
}
static int F_191 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_192 ( V_2 ) ;
F_193 ( & V_333 , & V_4 -> V_8 ) ;
F_179 ( V_4 ) ;
return 0 ;
}
static int F_194 ( struct V_46 * V_2 )
{
struct V_3 * V_4 = F_195 ( V_2 ) ;
if ( ! V_4 )
return - V_299 ;
return F_196 ( & V_333 , & V_4 -> V_8 ) ;
}
static int F_197 ( struct V_46 * V_2 )
{
struct V_3 * V_4 = F_195 ( V_2 ) ;
if ( ! V_4 )
return - V_299 ;
return F_198 ( & V_333 , & V_4 -> V_8 ) ;
}
static int F_199 ( struct V_348 * V_349 )
{
struct V_3 * V_4 ;
struct V_334 * V_350 ;
int V_342 , V_125 ;
int V_351 ;
if ( V_349 -> V_2 . V_87 ) {
struct V_327 * V_328 = V_349 -> V_2 . V_87 ;
V_125 = F_42 ( V_328 , L_31 , & V_351 ) ;
if ( V_125 )
return V_125 ;
} else {
V_351 = 115200 ;
}
V_342 = F_181 () ;
if ( V_342 < 0 )
return V_342 ;
V_4 = F_188 ( & V_349 -> V_2 , sizeof( struct V_3 ) ,
V_48 ) ;
if ( ! V_4 )
return - V_49 ;
V_4 -> V_6 = V_352 . V_6 ;
V_4 -> V_167 = & V_352 ;
V_4 -> V_61 = 32 ;
V_4 -> V_8 . V_10 = V_352 . V_344 ? V_11 : V_345 ;
V_4 -> V_8 . V_195 = F_200 ( V_349 , 0 ) ;
V_4 -> V_8 . V_252 = & V_353 ;
V_4 -> V_289 = V_351 ;
snprintf ( V_4 -> type , sizeof( V_4 -> type ) , L_32 ) ;
V_350 = F_201 ( V_349 , V_354 , 0 ) ;
V_125 = F_182 ( & V_349 -> V_2 , V_4 , V_350 , V_342 ) ;
if ( V_125 )
return V_125 ;
F_202 ( V_349 , V_4 ) ;
return F_184 ( V_4 ) ;
}
static int F_203 ( struct V_348 * V_349 )
{
struct V_3 * V_4 = F_204 ( V_349 ) ;
F_193 ( & V_333 , & V_4 -> V_8 ) ;
F_179 ( V_4 ) ;
return 0 ;
}
static int T_10 F_205 ( void )
{
F_206 ( V_355 L_33 ) ;
if ( F_207 ( & V_356 ) )
F_208 ( L_34 ) ;
return F_209 ( & V_357 ) ;
}
static void T_11 F_210 ( void )
{
F_211 ( & V_356 ) ;
F_212 ( & V_357 ) ;
}
