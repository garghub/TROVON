static unsigned int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) < 3 ? 16 : 32 ;
}
static unsigned int F_3 ( struct V_1 * V_2 )
{
return 64 ;
}
static unsigned int F_4 ( struct V_1 * V_2 )
{
return 16 ;
}
static unsigned int F_5 ( const struct V_3 * V_4 ,
unsigned int V_5 )
{
return V_4 -> V_6 [ V_5 ] ;
}
static unsigned int F_6 ( const struct V_3 * V_4 ,
unsigned int V_5 )
{
void T_1 * V_7 = V_4 -> V_8 . V_9 + F_5 ( V_4 , V_5 ) ;
return ( V_4 -> V_8 . V_10 == V_11 ) ?
F_7 ( V_7 ) : F_8 ( V_7 ) ;
}
static void F_9 ( unsigned int V_12 , const struct V_3 * V_4 ,
unsigned int V_5 )
{
void T_1 * V_7 = V_4 -> V_8 . V_9 + F_5 ( V_4 , V_5 ) ;
if ( V_4 -> V_8 . V_10 == V_11 )
F_10 ( V_12 , V_7 ) ;
else
F_11 ( V_12 , V_7 ) ;
}
static int F_12 ( struct V_3 * V_4 )
{
T_2 V_13 ;
unsigned int V_14 , V_15 , V_16 = 256 ;
int V_17 = 0 ;
while ( V_16 -- ) {
V_13 = F_6 ( V_4 , V_18 ) ;
if ( V_13 & V_19 )
break;
V_14 = F_6 ( V_4 , V_20 ) | V_21 ;
V_15 = V_22 ;
V_4 -> V_8 . V_23 . V_24 ++ ;
V_17 ++ ;
if ( F_13 ( V_14 & V_25 ) ) {
if ( V_14 & V_26 ) {
V_14 &= ~ ( V_27 | V_28 ) ;
V_4 -> V_8 . V_23 . V_29 ++ ;
if ( F_14 ( & V_4 -> V_8 ) )
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
if ( F_15 ( & V_4 -> V_8 , V_14 & 255 ) )
continue;
F_16 ( & V_4 -> V_8 , V_14 , V_32 , V_14 , V_15 ) ;
}
return V_17 ;
}
static int F_17 ( struct V_38 * V_39 , struct V_40 * V_41 ,
enum V_42 V_43 )
{
T_3 V_44 ;
V_41 -> V_45 = F_18 ( V_39 -> V_46 -> V_2 ,
V_47 , & V_44 , V_48 ) ;
if ( ! V_41 -> V_45 )
return - V_49 ;
F_19 ( & V_41 -> V_41 , 1 ) ;
F_20 ( & V_41 -> V_41 , F_21 ( V_44 ) ,
V_47 , F_22 ( V_44 ) ) ;
F_23 ( & V_41 -> V_41 ) = V_44 ;
F_24 ( & V_41 -> V_41 ) = V_47 ;
return 0 ;
}
static void F_25 ( struct V_38 * V_39 , struct V_40 * V_41 ,
enum V_42 V_43 )
{
if ( V_41 -> V_45 ) {
F_26 ( V_39 -> V_46 -> V_2 ,
V_47 , V_41 -> V_45 ,
F_23 ( & V_41 -> V_41 ) ) ;
}
}
static void F_27 ( struct V_3 * V_4 )
{
struct V_50 * V_51 = F_28 ( V_4 -> V_8 . V_2 ) ;
struct V_46 * V_2 = V_4 -> V_8 . V_2 ;
struct V_52 V_53 = {
. V_54 = V_4 -> V_8 . V_55 +
F_5 ( V_4 , V_20 ) ,
. V_56 = V_57 ,
. V_58 = V_59 ,
. V_60 = V_4 -> V_61 >> 1 ,
. V_62 = false ,
} ;
struct V_38 * V_39 ;
T_4 V_63 ;
V_4 -> V_64 = true ;
V_39 = F_29 ( V_2 , L_1 ) ;
if ( F_30 ( V_39 ) ) {
if ( F_31 ( V_39 ) == - V_65 ) {
V_4 -> V_64 = false ;
return;
}
if ( ! V_51 || ! V_51 -> V_66 ) {
F_32 ( V_4 -> V_8 . V_2 , L_2 ) ;
return;
}
F_33 ( V_63 ) ;
F_34 ( V_67 , V_63 ) ;
V_39 = F_35 ( V_63 , V_51 -> V_66 ,
V_51 -> V_68 ) ;
if ( ! V_39 ) {
F_36 ( V_4 -> V_8 . V_2 , L_3 ) ;
return;
}
}
F_37 ( V_39 , & V_53 ) ;
V_4 -> V_69 . V_39 = V_39 ;
F_32 ( V_4 -> V_8 . V_2 , L_4 ,
F_38 ( V_4 -> V_69 . V_39 ) ) ;
V_39 = F_39 ( V_2 , L_5 ) ;
if ( ! V_39 && V_51 && V_51 -> V_70 ) {
V_39 = F_35 ( V_63 , V_51 -> V_66 , V_51 -> V_70 ) ;
if ( ! V_39 ) {
F_36 ( V_4 -> V_8 . V_2 , L_6 ) ;
return;
}
}
if ( V_39 ) {
struct V_52 V_71 = {
. V_72 = V_4 -> V_8 . V_55 +
F_5 ( V_4 , V_20 ) ,
. V_73 = V_57 ,
. V_58 = V_74 ,
. V_75 = V_4 -> V_61 >> 2 ,
. V_62 = false ,
} ;
struct V_76 V_77 ;
if ( 0 == F_40 ( V_39 , & V_77 ) ) {
if ( V_77 . V_78 ==
V_79 ) {
F_41 ( V_39 ) ;
F_32 ( V_4 -> V_8 . V_2 ,
L_7 ) ;
return;
}
}
F_37 ( V_39 , & V_71 ) ;
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
V_4 -> V_80 . V_81 = F_42 (
V_2 -> V_87 , L_8 ) ;
if ( V_4 -> V_80 . V_81 ) {
T_5 V_88 ;
if ( 0 == F_43 ( V_2 -> V_87 ,
L_9 , & V_88 ) )
V_4 -> V_80 . V_84 = V_88 ;
else
V_4 -> V_80 . V_84 = 100 ;
if ( 0 == F_43 ( V_2 -> V_87 ,
L_10 , & V_88 ) )
V_4 -> V_80 . V_86 = V_88 ;
else
V_4 -> V_80 . V_86 = 3000 ;
}
}
F_32 ( V_4 -> V_8 . V_2 , L_11 ,
F_38 ( V_4 -> V_80 . V_39 ) ) ;
}
}
static void F_44 ( struct V_3 * V_4 )
{
if ( V_4 -> V_69 . V_39 )
F_41 ( V_4 -> V_69 . V_39 ) ;
if ( V_4 -> V_80 . V_39 )
F_41 ( V_4 -> V_80 . V_39 ) ;
}
static void F_45 ( void * V_89 )
{
struct V_3 * V_4 = V_89 ;
struct V_90 * V_69 = & V_4 -> V_69 ;
unsigned long V_91 ;
T_2 V_92 ;
F_46 ( & V_4 -> V_8 . V_93 , V_91 ) ;
if ( V_4 -> V_69 . V_94 )
F_47 ( V_69 -> V_39 -> V_46 -> V_2 , & V_69 -> V_41 , 1 ,
V_95 ) ;
V_92 = V_4 -> V_92 ;
V_4 -> V_92 = V_92 & ~ V_96 ;
F_9 ( V_4 -> V_92 , V_4 , V_97 ) ;
if ( ! ( V_92 & V_96 ) || F_48 ( & V_4 -> V_8 ) ||
F_49 ( & V_4 -> V_8 . V_98 -> V_99 ) ) {
V_4 -> V_69 . V_94 = false ;
F_50 ( & V_4 -> V_8 . V_93 , V_91 ) ;
return;
}
if ( F_51 ( V_4 ) <= 0 )
F_52 ( V_4 ) ;
F_50 ( & V_4 -> V_8 . V_93 , V_91 ) ;
}
static int F_51 ( struct V_3 * V_4 )
{
struct V_90 * V_69 = & V_4 -> V_69 ;
struct V_38 * V_39 = V_69 -> V_39 ;
struct V_100 * V_101 = V_39 -> V_46 ;
struct V_102 * V_103 ;
struct V_104 * V_99 = & V_4 -> V_8 . V_98 -> V_99 ;
unsigned int V_105 ;
V_105 = F_53 ( V_99 ) ;
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
if ( F_54 ( V_101 -> V_2 , & V_69 -> V_41 , 1 , V_95 ) != 1 ) {
V_4 -> V_69 . V_94 = false ;
F_55 ( V_4 -> V_8 . V_2 , L_12 ) ;
return - V_112 ;
}
V_103 = F_56 ( V_39 , & V_69 -> V_41 , 1 , V_59 ,
V_113 | V_114 ) ;
if ( ! V_103 ) {
F_47 ( V_101 -> V_2 , & V_69 -> V_41 , 1 , V_95 ) ;
V_4 -> V_69 . V_94 = false ;
F_55 ( V_4 -> V_8 . V_2 , L_13 ) ;
return - V_112 ;
}
V_103 -> V_115 = F_45 ;
V_103 -> V_116 = V_4 ;
F_57 ( V_103 ) ;
V_101 -> V_117 ( V_39 ) ;
V_4 -> V_92 |= V_96 ;
F_9 ( V_4 -> V_92 , V_4 , V_97 ) ;
V_4 -> V_69 . V_94 = true ;
V_99 -> V_106 = ( V_99 -> V_106 + V_105 ) & ( V_109 - 1 ) ;
V_4 -> V_8 . V_23 . V_118 += V_105 ;
if ( F_53 ( V_99 ) < V_119 )
F_58 ( & V_4 -> V_8 ) ;
return 1 ;
}
static bool F_59 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_120 )
return false ;
if ( V_4 -> V_69 . V_94 ) {
V_4 -> V_92 |= V_96 ;
F_9 ( V_4 -> V_92 , V_4 , V_97 ) ;
V_4 -> V_121 &= ~ V_122 ;
F_9 ( V_4 -> V_121 , V_4 , V_123 ) ;
return true ;
}
if ( F_51 ( V_4 ) > 0 ) {
V_4 -> V_121 &= ~ V_122 ;
F_9 ( V_4 -> V_121 , V_4 , V_123 ) ;
return true ;
}
return false ;
}
static inline void F_60 ( struct V_3 * V_4 )
{
if ( V_4 -> V_69 . V_94 ) {
V_4 -> V_92 &= ~ V_96 ;
F_9 ( V_4 -> V_92 , V_4 , V_97 ) ;
}
}
static inline bool F_61 ( struct V_3 * V_4 )
{
T_2 V_92 ;
if ( ! V_4 -> V_120 )
return false ;
if ( ! V_4 -> V_8 . V_124 ) {
bool V_125 = true ;
if ( ! V_4 -> V_69 . V_94 ) {
if ( F_51 ( V_4 ) > 0 ) {
V_4 -> V_121 &= ~ V_122 ;
F_9 ( V_4 -> V_121 , V_4 , V_123 ) ;
} else
V_125 = false ;
} else if ( ! ( V_4 -> V_92 & V_96 ) ) {
V_4 -> V_92 |= V_96 ;
F_9 ( V_4 -> V_92 , V_4 , V_97 ) ;
}
return V_125 ;
}
V_92 = V_4 -> V_92 ;
V_4 -> V_92 &= ~ V_96 ;
F_9 ( V_4 -> V_92 , V_4 , V_97 ) ;
if ( F_6 ( V_4 , V_18 ) & V_126 ) {
return false ;
}
F_9 ( V_4 -> V_8 . V_124 , V_4 , V_20 ) ;
V_4 -> V_8 . V_23 . V_118 ++ ;
V_4 -> V_8 . V_124 = 0 ;
V_4 -> V_92 = V_92 ;
F_9 ( V_92 , V_4 , V_97 ) ;
return true ;
}
static void F_62 ( struct V_127 * V_8 )
__releases( &uap->port.lock
static int F_63 ( struct V_3 * V_4 )
{
struct V_38 * V_128 = V_4 -> V_80 . V_39 ;
struct V_129 * V_80 = & V_4 -> V_80 ;
struct V_102 * V_103 ;
struct V_40 * V_130 ;
if ( ! V_128 )
return - V_131 ;
V_130 = V_4 -> V_80 . V_132 ?
& V_4 -> V_80 . V_133 : & V_4 -> V_80 . V_134 ;
V_103 = F_56 ( V_128 , & V_130 -> V_41 , 1 ,
V_74 ,
V_113 | V_114 ) ;
if ( ! V_103 ) {
V_4 -> V_80 . V_135 = false ;
F_64 ( V_128 ) ;
return - V_112 ;
}
V_103 -> V_115 = V_136 ;
V_103 -> V_116 = V_4 ;
V_80 -> V_137 = F_57 ( V_103 ) ;
F_65 ( V_128 ) ;
V_4 -> V_92 |= V_138 ;
F_9 ( V_4 -> V_92 , V_4 , V_97 ) ;
V_4 -> V_80 . V_135 = true ;
V_4 -> V_121 &= ~ V_139 ;
F_9 ( V_4 -> V_121 , V_4 , V_123 ) ;
return 0 ;
}
static void F_66 ( struct V_3 * V_4 ,
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
V_143 = F_67 ( V_8 , V_130 -> V_45 + V_144 ,
V_140 ) ;
V_4 -> V_8 . V_23 . V_24 += V_143 ;
if ( V_143 < V_140 )
F_68 ( V_4 -> V_8 . V_2 ,
L_14 ) ;
}
if ( V_4 -> V_80 . V_84 )
V_80 -> V_145 = V_130 -> V_41 . V_111 ;
if ( V_143 == V_140 && V_141 ) {
F_9 ( V_146 | V_147 | V_148 |
V_149 , V_4 , V_150 ) ;
V_17 = F_12 ( V_4 ) ;
}
F_69 ( & V_4 -> V_8 . V_93 ) ;
F_70 ( V_4 -> V_8 . V_2 ,
L_15 ,
V_143 , V_17 ) ;
F_71 ( V_8 ) ;
F_72 ( & V_4 -> V_8 . V_93 ) ;
}
static void F_73 ( struct V_3 * V_4 )
{
struct V_129 * V_80 = & V_4 -> V_80 ;
struct V_38 * V_128 = V_80 -> V_39 ;
struct V_40 * V_130 = V_80 -> V_132 ?
& V_80 -> V_133 : & V_80 -> V_134 ;
T_6 V_140 ;
struct V_151 V_98 ;
enum V_152 V_153 ;
if ( F_74 ( V_128 ) )
F_36 ( V_4 -> V_8 . V_2 , L_16 ) ;
V_153 = V_128 -> V_46 -> V_154 ( V_128 ,
V_80 -> V_137 , & V_98 ) ;
if ( V_153 != V_155 )
F_36 ( V_4 -> V_8 . V_2 , L_16 ) ;
V_4 -> V_92 &= ~ V_138 ;
F_9 ( V_4 -> V_92 , V_4 , V_97 ) ;
V_4 -> V_80 . V_135 = false ;
V_140 = V_130 -> V_41 . V_111 - V_98 . V_156 ;
F_75 ( V_140 > V_47 ) ;
F_64 ( V_128 ) ;
F_66 ( V_4 , V_140 , V_80 -> V_132 , true ) ;
V_80 -> V_132 = ! V_80 -> V_132 ;
if ( F_63 ( V_4 ) ) {
F_55 ( V_4 -> V_8 . V_2 , L_17
L_18 ) ;
V_4 -> V_121 |= V_139 ;
F_9 ( V_4 -> V_121 , V_4 , V_123 ) ;
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
F_76 ( & V_4 -> V_8 . V_93 ) ;
V_128 -> V_46 -> V_154 ( V_128 , V_80 -> V_137 , & V_98 ) ;
V_140 = V_130 -> V_41 . V_111 - V_98 . V_156 ;
F_75 ( V_140 > V_47 ) ;
F_64 ( V_128 ) ;
V_4 -> V_80 . V_135 = false ;
V_80 -> V_132 = ! V_157 ;
V_125 = F_63 ( V_4 ) ;
F_66 ( V_4 , V_140 , V_157 , false ) ;
F_77 ( & V_4 -> V_8 . V_93 ) ;
if ( V_125 ) {
F_55 ( V_4 -> V_8 . V_2 , L_17
L_18 ) ;
V_4 -> V_121 |= V_139 ;
F_9 ( V_4 -> V_121 , V_4 , V_123 ) ;
}
}
static inline void F_78 ( struct V_3 * V_4 )
{
V_4 -> V_92 &= ~ V_138 ;
F_9 ( V_4 -> V_92 , V_4 , V_97 ) ;
}
static void F_79 ( unsigned long args )
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
if ( F_80 ( V_98 . V_156 < V_80 -> V_145 ) ) {
V_144 = V_130 -> V_41 . V_111 - V_80 -> V_145 ;
V_158 = V_80 -> V_145 - V_98 . V_156 ;
V_143 = F_67 ( V_8 , V_130 -> V_45 + V_144 ,
V_158 ) ;
if ( V_143 == V_158 )
V_80 -> V_145 = V_98 . V_156 ;
V_80 -> V_159 = V_160 ;
}
F_71 ( V_8 ) ;
if ( F_81 ( V_160 - V_80 -> V_159 )
> V_4 -> V_80 . V_86 ) {
F_46 ( & V_4 -> V_8 . V_93 , V_91 ) ;
F_78 ( V_4 ) ;
V_4 -> V_121 |= V_139 ;
F_9 ( V_4 -> V_121 , V_4 , V_123 ) ;
F_50 ( & V_4 -> V_8 . V_93 , V_91 ) ;
V_4 -> V_80 . V_135 = false ;
F_64 ( V_128 ) ;
F_82 ( & V_4 -> V_80 . V_161 ) ;
} else {
F_83 ( & V_4 -> V_80 . V_161 ,
V_160 + F_84 ( V_4 -> V_80 . V_84 ) ) ;
}
}
static void F_85 ( struct V_3 * V_4 )
{
int V_125 ;
if ( ! V_4 -> V_64 )
F_27 ( V_4 ) ;
if ( ! V_4 -> V_69 . V_39 )
return;
V_4 -> V_69 . V_45 = F_86 ( V_47 , V_48 | V_162 ) ;
if ( ! V_4 -> V_69 . V_45 ) {
F_36 ( V_4 -> V_8 . V_2 , L_19 ) ;
V_4 -> V_8 . V_61 = V_4 -> V_61 ;
return;
}
F_87 ( & V_4 -> V_69 . V_41 , V_4 -> V_69 . V_45 , V_47 ) ;
V_4 -> V_8 . V_61 = V_47 ;
V_4 -> V_120 = true ;
if ( ! V_4 -> V_80 . V_39 )
goto V_163;
V_125 = F_17 ( V_4 -> V_80 . V_39 , & V_4 -> V_80 . V_134 ,
V_164 ) ;
if ( V_125 ) {
F_36 ( V_4 -> V_8 . V_2 , L_20 ,
L_21 , V_125 ) ;
goto V_163;
}
V_125 = F_17 ( V_4 -> V_80 . V_39 , & V_4 -> V_80 . V_133 ,
V_164 ) ;
if ( V_125 ) {
F_36 ( V_4 -> V_8 . V_2 , L_20 ,
L_22 , V_125 ) ;
F_25 ( V_4 -> V_80 . V_39 , & V_4 -> V_80 . V_134 ,
V_164 ) ;
goto V_163;
}
V_4 -> V_165 = true ;
V_163:
V_4 -> V_92 |= V_166 ;
F_9 ( V_4 -> V_92 , V_4 , V_97 ) ;
if ( V_4 -> V_167 -> V_168 )
F_9 ( V_169 | V_170 ,
V_4 , V_171 ) ;
if ( V_4 -> V_165 ) {
if ( F_63 ( V_4 ) )
F_55 ( V_4 -> V_8 . V_2 , L_23
L_24 ) ;
if ( V_4 -> V_80 . V_84 ) {
F_88 ( & ( V_4 -> V_80 . V_161 ) ) ;
V_4 -> V_80 . V_161 . V_172 = F_79 ;
V_4 -> V_80 . V_161 . V_89 = ( unsigned long ) V_4 ;
F_83 ( & V_4 -> V_80 . V_161 ,
V_160 +
F_84 ( V_4 -> V_80 . V_84 ) ) ;
V_4 -> V_80 . V_145 = V_47 ;
V_4 -> V_80 . V_159 = V_160 ;
}
}
}
static void F_89 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_120 || V_4 -> V_165 ) )
return;
while ( F_6 ( V_4 , V_18 ) & V_4 -> V_167 -> V_173 )
F_90 () ;
F_76 ( & V_4 -> V_8 . V_93 ) ;
V_4 -> V_92 &= ~ ( V_166 | V_138 | V_96 ) ;
F_9 ( V_4 -> V_92 , V_4 , V_97 ) ;
F_77 ( & V_4 -> V_8 . V_93 ) ;
if ( V_4 -> V_120 ) {
F_64 ( V_4 -> V_69 . V_39 ) ;
if ( V_4 -> V_69 . V_94 ) {
F_47 ( V_4 -> V_69 . V_39 -> V_46 -> V_2 , & V_4 -> V_69 . V_41 , 1 ,
V_95 ) ;
V_4 -> V_69 . V_94 = false ;
}
F_91 ( V_4 -> V_69 . V_45 ) ;
V_4 -> V_120 = false ;
}
if ( V_4 -> V_165 ) {
F_64 ( V_4 -> V_80 . V_39 ) ;
F_25 ( V_4 -> V_80 . V_39 , & V_4 -> V_80 . V_134 , V_164 ) ;
F_25 ( V_4 -> V_80 . V_39 , & V_4 -> V_80 . V_133 , V_164 ) ;
if ( V_4 -> V_80 . V_84 )
F_92 ( & V_4 -> V_80 . V_161 ) ;
V_4 -> V_165 = false ;
}
}
static inline bool F_93 ( struct V_3 * V_4 )
{
return V_4 -> V_165 ;
}
static inline bool F_94 ( struct V_3 * V_4 )
{
return V_4 -> V_165 && V_4 -> V_80 . V_135 ;
}
static inline void F_27 ( struct V_3 * V_4 )
{
}
static inline void F_44 ( struct V_3 * V_4 )
{
}
static inline void F_85 ( struct V_3 * V_4 )
{
}
static inline void F_89 ( struct V_3 * V_4 )
{
}
static inline bool F_59 ( struct V_3 * V_4 )
{
return false ;
}
static inline void F_60 ( struct V_3 * V_4 )
{
}
static inline bool F_61 ( struct V_3 * V_4 )
{
return false ;
}
static inline void F_73 ( struct V_3 * V_4 )
{
}
static inline void F_78 ( struct V_3 * V_4 )
{
}
static inline int F_63 ( struct V_3 * V_4 )
{
return - V_131 ;
}
static inline bool F_93 ( struct V_3 * V_4 )
{
return false ;
}
static inline bool F_94 ( struct V_3 * V_4 )
{
return false ;
}
static void F_95 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_96 ( V_8 , struct V_3 , V_8 ) ;
V_4 -> V_121 &= ~ V_122 ;
F_9 ( V_4 -> V_121 , V_4 , V_123 ) ;
F_60 ( V_4 ) ;
}
static void F_52 ( struct V_3 * V_4 )
{
if ( F_97 ( V_4 , false ) ) {
V_4 -> V_121 |= V_122 ;
F_9 ( V_4 -> V_121 , V_4 , V_123 ) ;
}
}
static void F_98 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_96 ( V_8 , struct V_3 , V_8 ) ;
if ( ! F_61 ( V_4 ) )
F_52 ( V_4 ) ;
}
static void F_99 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_96 ( V_8 , struct V_3 , V_8 ) ;
V_4 -> V_121 &= ~ ( V_139 | V_174 | V_175 |
V_176 | V_177 | V_178 ) ;
F_9 ( V_4 -> V_121 , V_4 , V_123 ) ;
F_78 ( V_4 ) ;
}
static void F_100 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_96 ( V_8 , struct V_3 , V_8 ) ;
V_4 -> V_121 |= V_179 | V_180 | V_181 | V_182 ;
F_9 ( V_4 -> V_121 , V_4 , V_123 ) ;
}
static void F_101 ( struct V_3 * V_4 )
__releases( &uap->port.lock
static bool F_102 ( struct V_3 * V_4 , unsigned char V_183 ,
bool V_184 )
{
if ( F_13 ( ! V_184 ) &&
F_6 ( V_4 , V_18 ) & V_126 )
return false ;
F_9 ( V_183 , V_4 , V_20 ) ;
V_4 -> V_8 . V_23 . V_118 ++ ;
return true ;
}
static bool F_97 ( struct V_3 * V_4 , bool V_184 )
{
struct V_104 * V_99 = & V_4 -> V_8 . V_98 -> V_99 ;
int V_105 = V_4 -> V_61 >> 1 ;
if ( V_4 -> V_8 . V_124 ) {
if ( ! F_102 ( V_4 , V_4 -> V_8 . V_124 , V_184 ) )
return true ;
V_4 -> V_8 . V_124 = 0 ;
-- V_105 ;
}
if ( F_49 ( V_99 ) || F_48 ( & V_4 -> V_8 ) ) {
F_95 ( & V_4 -> V_8 ) ;
return false ;
}
if ( F_59 ( V_4 ) )
return true ;
do {
if ( F_80 ( V_184 ) && V_105 -- == 0 )
break;
if ( ! F_102 ( V_4 , V_99 -> V_45 [ V_99 -> V_106 ] , V_184 ) )
break;
V_99 -> V_106 = ( V_99 -> V_106 + 1 ) & ( V_109 - 1 ) ;
} while ( ! F_49 ( V_99 ) );
if ( F_53 ( V_99 ) < V_119 )
F_58 ( & V_4 -> V_8 ) ;
if ( F_49 ( V_99 ) ) {
F_95 ( & V_4 -> V_8 ) ;
return false ;
}
return true ;
}
static void F_103 ( struct V_3 * V_4 )
{
unsigned int V_13 , V_185 ;
V_13 = F_6 ( V_4 , V_18 ) & V_186 ;
V_185 = V_13 ^ V_4 -> V_187 ;
V_4 -> V_187 = V_13 ;
if ( ! V_185 )
return;
if ( V_185 & V_188 )
F_104 ( & V_4 -> V_8 , V_13 & V_188 ) ;
if ( V_185 & V_4 -> V_167 -> V_189 )
V_4 -> V_8 . V_23 . V_190 ++ ;
if ( V_185 & V_4 -> V_167 -> V_191 )
F_105 ( & V_4 -> V_8 ,
V_13 & V_4 -> V_167 -> V_191 ) ;
F_106 ( & V_4 -> V_8 . V_98 -> V_8 . V_192 ) ;
}
static void F_107 ( struct V_3 * V_4 )
{
unsigned int V_193 ;
if ( ! V_4 -> V_167 -> V_194 )
return;
F_9 ( 0x00 , V_4 , V_150 ) ;
V_193 = F_6 ( V_4 , V_150 ) ;
V_193 = F_6 ( V_4 , V_150 ) ;
}
static T_7 F_108 ( int V_195 , void * V_196 )
{
struct V_3 * V_4 = V_196 ;
unsigned long V_91 ;
unsigned int V_13 , V_197 = V_198 ;
T_2 V_199 ;
int V_200 = 0 ;
F_46 ( & V_4 -> V_8 . V_93 , V_91 ) ;
V_199 = F_6 ( V_4 , V_123 ) ;
V_13 = F_6 ( V_4 , V_201 ) & V_199 ;
if ( V_13 ) {
do {
F_107 ( V_4 ) ;
F_9 ( V_13 & ~ ( V_202 | V_203 |
V_204 ) ,
V_4 , V_150 ) ;
if ( V_13 & ( V_203 | V_204 ) ) {
if ( F_94 ( V_4 ) )
F_73 ( V_4 ) ;
else
F_101 ( V_4 ) ;
}
if ( V_13 & ( V_205 | V_206 |
V_207 | V_208 ) )
F_103 ( V_4 ) ;
if ( V_13 & V_202 )
F_97 ( V_4 , true ) ;
if ( V_197 -- == 0 )
break;
V_13 = F_6 ( V_4 , V_201 ) & V_199 ;
} while ( V_13 != 0 );
V_200 = 1 ;
}
F_50 ( & V_4 -> V_8 . V_93 , V_91 ) ;
return F_109 ( V_200 ) ;
}
static unsigned int F_110 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_96 ( V_8 , struct V_3 , V_8 ) ;
unsigned int V_13 = F_6 ( V_4 , V_18 ) ^ V_4 -> V_167 -> V_209 ;
return V_13 & ( V_4 -> V_167 -> V_173 | V_126 ) ?
0 : V_210 ;
}
static unsigned int F_111 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_96 ( V_8 , struct V_3 , V_8 ) ;
unsigned int V_211 = 0 ;
unsigned int V_13 = F_6 ( V_4 , V_18 ) ;
#define F_112 ( T_8 , T_9 ) \
if (status & uartbit) \
result |= tiocmbit
F_112 ( V_188 , V_212 ) ;
F_112 ( V_4 -> V_167 -> V_189 , V_213 ) ;
F_112 ( V_4 -> V_167 -> V_191 , V_214 ) ;
F_112 ( V_4 -> V_167 -> V_215 , V_216 ) ;
#undef F_112
return V_211 ;
}
static void F_113 ( struct V_127 * V_8 , unsigned int V_217 )
{
struct V_3 * V_4 =
F_96 ( V_8 , struct V_3 , V_8 ) ;
unsigned int V_218 ;
V_218 = F_6 ( V_4 , V_219 ) ;
#define F_112 ( T_9 , T_8 ) \
if (mctrl & tiocmbit) \
cr |= uartbit; \
else \
cr &= ~uartbit
F_112 ( V_220 , V_221 ) ;
F_112 ( V_222 , V_223 ) ;
F_112 ( V_224 , V_225 ) ;
F_112 ( V_226 , V_227 ) ;
F_112 ( V_228 , V_229 ) ;
if ( V_4 -> V_230 ) {
F_112 ( V_220 , V_231 ) ;
}
#undef F_112
F_9 ( V_218 , V_4 , V_219 ) ;
}
static void F_114 ( struct V_127 * V_8 , int V_232 )
{
struct V_3 * V_4 =
F_96 ( V_8 , struct V_3 , V_8 ) ;
unsigned long V_91 ;
unsigned int V_233 ;
F_46 ( & V_4 -> V_8 . V_93 , V_91 ) ;
V_233 = F_6 ( V_4 , V_234 ) ;
if ( V_232 == - 1 )
V_233 |= V_235 ;
else
V_233 &= ~ V_235 ;
F_9 ( V_233 , V_4 , V_234 ) ;
F_50 ( & V_4 -> V_8 . V_93 , V_91 ) ;
}
static void F_115 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_96 ( V_8 , struct V_3 , V_8 ) ;
F_9 ( F_6 ( V_4 , V_236 ) , V_4 , V_150 ) ;
F_9 ( F_6 ( V_4 , V_123 ) & ~ V_122 , V_4 ,
V_123 ) ;
}
static int F_116 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_96 ( V_8 , struct V_3 , V_8 ) ;
unsigned int V_13 ;
F_115 ( V_8 ) ;
V_13 = F_6 ( V_4 , V_18 ) ;
if ( V_13 & V_19 )
return V_237 ;
return F_6 ( V_4 , V_20 ) ;
}
static void F_117 ( struct V_127 * V_8 ,
unsigned char V_14 )
{
struct V_3 * V_4 =
F_96 ( V_8 , struct V_3 , V_8 ) ;
while ( F_6 ( V_4 , V_18 ) & V_126 )
F_90 () ;
F_9 ( V_14 , V_4 , V_20 ) ;
}
static int F_118 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_96 ( V_8 , struct V_3 , V_8 ) ;
int V_238 ;
F_119 ( V_8 -> V_2 ) ;
V_238 = F_120 ( V_4 -> V_239 ) ;
if ( V_238 )
return V_238 ;
V_4 -> V_8 . V_240 = F_121 ( V_4 -> V_239 ) ;
F_9 ( V_146 | V_147 | V_148 |
V_149 | V_203 | V_204 ,
V_4 , V_150 ) ;
V_4 -> V_121 = F_6 ( V_4 , V_123 ) ;
F_9 ( V_174 | V_139 , V_4 , V_123 ) ;
if ( F_28 ( V_4 -> V_8 . V_2 ) ) {
struct V_50 * V_51 ;
V_51 = F_28 ( V_4 -> V_8 . V_2 ) ;
if ( V_51 -> V_241 )
V_51 -> V_241 () ;
}
return 0 ;
}
static bool F_122 ( const struct V_3 * V_4 )
{
return F_5 ( V_4 , V_242 ) !=
F_5 ( V_4 , V_234 ) ;
}
static void F_123 ( struct V_3 * V_4 , unsigned int V_233 )
{
F_9 ( V_233 , V_4 , V_242 ) ;
if ( F_122 ( V_4 ) ) {
int V_243 ;
for ( V_243 = 0 ; V_243 < 10 ; ++ V_243 )
F_9 ( 0xff , V_4 , V_236 ) ;
F_9 ( V_233 , V_4 , V_234 ) ;
}
}
static int F_124 ( struct V_3 * V_4 )
{
F_9 ( V_4 -> V_121 , V_4 , V_123 ) ;
return F_125 ( V_4 -> V_8 . V_195 , F_108 , 0 , L_25 , V_4 ) ;
}
static void F_126 ( struct V_3 * V_4 )
{
F_76 ( & V_4 -> V_8 . V_93 ) ;
F_9 ( V_203 | V_204 , V_4 , V_150 ) ;
V_4 -> V_121 = V_174 ;
if ( ! F_94 ( V_4 ) )
V_4 -> V_121 |= V_139 ;
F_9 ( V_4 -> V_121 , V_4 , V_123 ) ;
F_77 ( & V_4 -> V_8 . V_93 ) ;
}
static int F_127 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_96 ( V_8 , struct V_3 , V_8 ) ;
unsigned int V_218 ;
int V_238 ;
V_238 = F_118 ( V_8 ) ;
if ( V_238 )
goto V_244;
V_238 = F_124 ( V_4 ) ;
if ( V_238 )
goto V_244;
F_9 ( V_4 -> V_167 -> V_245 , V_4 , V_246 ) ;
F_76 ( & V_4 -> V_8 . V_93 ) ;
V_218 = V_4 -> V_247 & ( V_221 | V_223 ) ;
V_218 |= V_248 | V_249 | V_250 ;
F_9 ( V_218 , V_4 , V_219 ) ;
F_77 ( & V_4 -> V_8 . V_93 ) ;
V_4 -> V_187 = F_6 ( V_4 , V_18 ) & V_186 ;
F_85 ( V_4 ) ;
F_126 ( V_4 ) ;
return 0 ;
V_244:
F_128 ( V_4 -> V_239 ) ;
return V_238 ;
}
static int F_129 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_96 ( V_8 , struct V_3 , V_8 ) ;
int V_238 ;
V_238 = F_118 ( V_8 ) ;
if ( V_238 )
return V_238 ;
V_238 = F_124 ( V_4 ) ;
if ( V_238 )
return V_238 ;
V_4 -> V_187 = 0 ;
F_126 ( V_4 ) ;
return 0 ;
}
static void F_130 ( struct V_3 * V_4 ,
unsigned int V_251 )
{
unsigned long V_12 ;
V_12 = F_6 ( V_4 , V_251 ) ;
V_12 &= ~ ( V_235 | V_252 ) ;
F_9 ( V_12 , V_4 , V_251 ) ;
}
static void F_131 ( struct V_3 * V_4 )
{
unsigned int V_218 ;
V_4 -> V_230 = false ;
F_76 ( & V_4 -> V_8 . V_93 ) ;
V_218 = F_6 ( V_4 , V_219 ) ;
V_4 -> V_247 = V_218 ;
V_218 &= V_221 | V_223 ;
V_218 |= V_248 | V_250 ;
F_9 ( V_218 , V_4 , V_219 ) ;
F_77 ( & V_4 -> V_8 . V_93 ) ;
F_130 ( V_4 , V_242 ) ;
if ( F_122 ( V_4 ) )
F_130 ( V_4 , V_234 ) ;
}
static void F_132 ( struct V_3 * V_4 )
{
F_76 ( & V_4 -> V_8 . V_93 ) ;
V_4 -> V_121 = 0 ;
F_9 ( V_4 -> V_121 , V_4 , V_123 ) ;
F_9 ( 0xffff , V_4 , V_150 ) ;
F_77 ( & V_4 -> V_8 . V_93 ) ;
}
static void F_133 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_96 ( V_8 , struct V_3 , V_8 ) ;
F_132 ( V_4 ) ;
F_89 ( V_4 ) ;
F_134 ( V_4 -> V_8 . V_195 , V_4 ) ;
F_131 ( V_4 ) ;
F_128 ( V_4 -> V_239 ) ;
F_135 ( V_8 -> V_2 ) ;
if ( F_28 ( V_4 -> V_8 . V_2 ) ) {
struct V_50 * V_51 ;
V_51 = F_28 ( V_4 -> V_8 . V_2 ) ;
if ( V_51 -> exit )
V_51 -> exit () ;
}
if ( V_4 -> V_8 . V_253 -> V_254 )
V_4 -> V_8 . V_253 -> V_254 ( V_8 ) ;
}
static void F_136 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_96 ( V_8 , struct V_3 , V_8 ) ;
F_132 ( V_4 ) ;
F_134 ( V_4 -> V_8 . V_195 , V_4 ) ;
if ( V_4 -> V_8 . V_253 -> V_254 )
V_4 -> V_8 . V_253 -> V_254 ( V_8 ) ;
}
static void
F_137 ( struct V_127 * V_8 , struct V_255 * V_256 )
{
V_8 -> V_34 = V_32 | 255 ;
if ( V_256 -> V_257 & V_258 )
V_8 -> V_34 |= V_27 | V_28 ;
if ( V_256 -> V_257 & ( V_259 | V_260 | V_261 ) )
V_8 -> V_34 |= V_26 ;
V_8 -> V_262 = 0 ;
if ( V_256 -> V_257 & V_263 )
V_8 -> V_262 |= V_27 | V_28 ;
if ( V_256 -> V_257 & V_259 ) {
V_8 -> V_262 |= V_26 ;
if ( V_256 -> V_257 & V_263 )
V_8 -> V_262 |= V_32 ;
}
if ( ( V_256 -> V_264 & V_265 ) == 0 )
V_8 -> V_262 |= V_21 ;
}
static void
F_138 ( struct V_127 * V_8 , struct V_255 * V_256 ,
struct V_255 * V_266 )
{
struct V_3 * V_4 =
F_96 ( V_8 , struct V_3 , V_8 ) ;
unsigned int V_233 , V_247 ;
unsigned long V_91 ;
unsigned int V_267 , V_268 , V_269 ;
if ( V_4 -> V_167 -> V_270 )
V_269 = 8 ;
else
V_269 = 16 ;
V_267 = F_139 ( V_8 , V_256 , V_266 , 0 ,
V_8 -> V_240 / V_269 ) ;
#ifdef F_140
if ( V_4 -> V_80 . V_81 )
V_4 -> V_80 . V_84 = F_141 ( 10000000 , V_267 ) ;
#endif
if ( V_267 > V_8 -> V_240 / 16 )
V_268 = F_142 ( V_8 -> V_240 * 8 , V_267 ) ;
else
V_268 = F_142 ( V_8 -> V_240 * 4 , V_267 ) ;
switch ( V_256 -> V_264 & V_271 ) {
case V_272 :
V_233 = V_273 ;
break;
case V_274 :
V_233 = V_275 ;
break;
case V_276 :
V_233 = V_277 ;
break;
default:
V_233 = V_278 ;
break;
}
if ( V_256 -> V_264 & V_279 )
V_233 |= V_280 ;
if ( V_256 -> V_264 & V_281 ) {
V_233 |= V_282 ;
if ( ! ( V_256 -> V_264 & V_283 ) )
V_233 |= V_284 ;
if ( V_256 -> V_264 & V_285 )
V_233 |= V_286 ;
}
if ( V_4 -> V_61 > 1 )
V_233 |= V_252 ;
F_46 ( & V_8 -> V_93 , V_91 ) ;
F_143 ( V_8 , V_256 -> V_264 , V_267 ) ;
F_137 ( V_8 , V_256 ) ;
if ( F_144 ( V_8 , V_256 -> V_264 ) )
F_100 ( V_8 ) ;
V_247 = F_6 ( V_4 , V_219 ) ;
F_9 ( 0 , V_4 , V_219 ) ;
if ( V_256 -> V_264 & V_287 ) {
if ( V_247 & V_221 )
V_247 |= V_231 ;
V_247 |= V_288 ;
V_4 -> V_230 = true ;
} else {
V_247 &= ~ ( V_288 | V_231 ) ;
V_4 -> V_230 = false ;
}
if ( V_4 -> V_167 -> V_270 ) {
if ( V_267 > V_8 -> V_240 / 16 )
V_247 |= V_289 ;
else
V_247 &= ~ V_289 ;
}
if ( V_4 -> V_167 -> V_270 ) {
if ( ( V_267 >= 3000000 ) && ( V_267 < 3250000 ) && ( V_268 > 1 ) )
V_268 -= 1 ;
else if ( ( V_267 > 3250000 ) && ( V_268 > 2 ) )
V_268 -= 2 ;
}
F_9 ( V_268 & 0x3f , V_4 , V_290 ) ;
F_9 ( V_268 >> 6 , V_4 , V_291 ) ;
F_123 ( V_4 , V_233 ) ;
F_9 ( V_247 , V_4 , V_219 ) ;
F_50 ( & V_8 -> V_93 , V_91 ) ;
}
static void
F_145 ( struct V_127 * V_8 , struct V_255 * V_256 ,
struct V_255 * V_266 )
{
struct V_3 * V_4 =
F_96 ( V_8 , struct V_3 , V_8 ) ;
unsigned long V_91 ;
F_146 ( V_256 , V_4 -> V_292 , V_4 -> V_292 ) ;
V_256 -> V_264 &= ~ ( V_271 | V_279 | V_281 | V_283 ) ;
V_256 -> V_264 &= ~ ( V_285 | V_287 ) ;
V_256 -> V_264 |= V_293 | V_294 ;
F_46 ( & V_8 -> V_93 , V_91 ) ;
F_143 ( V_8 , V_293 , V_4 -> V_292 ) ;
F_137 ( V_8 , V_256 ) ;
F_50 ( & V_8 -> V_93 , V_91 ) ;
}
static const char * F_147 ( struct V_127 * V_8 )
{
struct V_3 * V_4 =
F_96 ( V_8 , struct V_3 , V_8 ) ;
return V_4 -> V_8 . type == V_295 ? V_4 -> type : NULL ;
}
static void F_148 ( struct V_127 * V_8 )
{
F_149 ( V_8 -> V_55 , V_296 ) ;
}
static int F_150 ( struct V_127 * V_8 )
{
return F_151 ( V_8 -> V_55 , V_296 , L_25 )
!= NULL ? 0 : - V_112 ;
}
static void F_152 ( struct V_127 * V_8 , int V_91 )
{
if ( V_91 & V_297 ) {
V_8 -> type = V_295 ;
F_150 ( V_8 ) ;
}
}
static int F_153 ( struct V_127 * V_8 , struct V_298 * V_299 )
{
int V_125 = 0 ;
if ( V_299 -> type != V_300 && V_299 -> type != V_295 )
V_125 = - V_301 ;
if ( V_299 -> V_195 < 0 || V_299 -> V_195 >= V_302 )
V_125 = - V_301 ;
if ( V_299 -> V_303 < 9600 )
V_125 = - V_301 ;
return V_125 ;
}
static void F_154 ( struct V_127 * V_8 , unsigned int V_217 )
{
}
static unsigned int F_155 ( struct V_127 * V_8 )
{
return 0 ;
}
static void F_156 ( struct V_127 * V_8 , int V_14 )
{
struct V_3 * V_4 =
F_96 ( V_8 , struct V_3 , V_8 ) ;
while ( F_6 ( V_4 , V_18 ) & V_126 )
F_90 () ;
F_9 ( V_14 , V_4 , V_20 ) ;
}
static void
F_157 ( struct V_304 * V_305 , const char * V_306 , unsigned int V_105 )
{
struct V_3 * V_4 = V_307 [ V_305 -> V_308 ] ;
unsigned int V_247 = 0 , V_309 ;
unsigned long V_91 ;
int V_310 = 1 ;
F_158 ( V_4 -> V_239 ) ;
F_159 ( V_91 ) ;
if ( V_4 -> V_8 . V_311 )
V_310 = 0 ;
else if ( V_312 )
V_310 = F_160 ( & V_4 -> V_8 . V_93 ) ;
else
F_72 ( & V_4 -> V_8 . V_93 ) ;
if ( ! V_4 -> V_167 -> V_313 ) {
V_247 = F_6 ( V_4 , V_219 ) ;
V_309 = V_247 & ~ V_288 ;
V_309 |= V_248 | V_250 ;
F_9 ( V_309 , V_4 , V_219 ) ;
}
F_161 ( & V_4 -> V_8 , V_306 , V_105 , F_156 ) ;
while ( ( F_6 ( V_4 , V_18 ) ^ V_4 -> V_167 -> V_209 )
& V_4 -> V_167 -> V_173 )
F_90 () ;
if ( ! V_4 -> V_167 -> V_313 )
F_9 ( V_247 , V_4 , V_219 ) ;
if ( V_310 )
F_69 ( & V_4 -> V_8 . V_93 ) ;
F_162 ( V_91 ) ;
F_163 ( V_4 -> V_239 ) ;
}
static void T_10
F_164 ( struct V_3 * V_4 , int * V_267 ,
int * V_30 , int * V_314 )
{
if ( F_6 ( V_4 , V_219 ) & V_248 ) {
unsigned int V_233 , V_315 , V_316 ;
V_233 = F_6 ( V_4 , V_234 ) ;
* V_30 = 'n' ;
if ( V_233 & V_282 ) {
if ( V_233 & V_284 )
* V_30 = 'e' ;
else
* V_30 = 'o' ;
}
if ( ( V_233 & 0x60 ) == V_277 )
* V_314 = 7 ;
else
* V_314 = 8 ;
V_315 = F_6 ( V_4 , V_291 ) ;
V_316 = F_6 ( V_4 , V_290 ) ;
* V_267 = V_4 -> V_8 . V_240 * 4 / ( 64 * V_315 + V_316 ) ;
if ( V_4 -> V_167 -> V_270 ) {
if ( F_6 ( V_4 , V_219 )
& V_289 )
* V_267 *= 2 ;
}
}
}
static int T_10 F_165 ( struct V_304 * V_305 , char * V_317 )
{
struct V_3 * V_4 ;
int V_267 = 38400 ;
int V_314 = 8 ;
int V_30 = 'n' ;
int V_318 = 'n' ;
int V_125 ;
if ( V_305 -> V_308 >= V_319 )
V_305 -> V_308 = 0 ;
V_4 = V_307 [ V_305 -> V_308 ] ;
if ( ! V_4 )
return - V_320 ;
F_119 ( V_4 -> V_8 . V_2 ) ;
V_125 = F_166 ( V_4 -> V_239 ) ;
if ( V_125 )
return V_125 ;
if ( F_28 ( V_4 -> V_8 . V_2 ) ) {
struct V_50 * V_51 ;
V_51 = F_28 ( V_4 -> V_8 . V_2 ) ;
if ( V_51 -> V_241 )
V_51 -> V_241 () ;
}
V_4 -> V_8 . V_240 = F_121 ( V_4 -> V_239 ) ;
if ( V_4 -> V_167 -> V_321 ) {
V_267 = V_4 -> V_292 ;
} else {
if ( V_317 )
F_167 ( V_317 ,
& V_267 , & V_30 , & V_314 , & V_318 ) ;
else
F_164 ( V_4 , & V_267 , & V_30 , & V_314 ) ;
}
return F_168 ( & V_4 -> V_8 , V_305 , V_267 , V_30 , V_314 , V_318 ) ;
}
static int T_10 F_169 ( struct V_304 * V_305 , char * V_322 , int V_323 ,
char * V_317 )
{
unsigned char V_10 ;
T_11 V_7 ;
int V_243 ;
if ( strcmp ( V_322 , L_26 ) == 0 ) {
F_170 ( L_27 ) ;
V_324 = true ;
} else if ( strcmp ( V_322 , L_28 ) != 0 ) {
return - V_320 ;
}
if ( F_171 ( V_317 , & V_10 , & V_7 , & V_317 ) )
return - V_320 ;
if ( V_10 != V_325 && V_10 != V_11 )
return - V_320 ;
for ( V_243 = 0 ; V_243 < F_172 ( V_307 ) ; V_243 ++ ) {
struct V_127 * V_8 ;
if ( ! V_307 [ V_243 ] )
continue;
V_8 = & V_307 [ V_243 ] -> V_8 ;
if ( V_8 -> V_55 != V_7 )
continue;
V_305 -> V_308 = V_243 ;
V_8 -> V_326 = V_305 ;
return F_165 ( V_305 , V_317 ) ;
}
return - V_320 ;
}
static void F_173 ( struct V_127 * V_8 , int V_183 )
{
while ( F_174 ( V_8 -> V_9 + V_327 ) & V_126 )
F_90 () ;
F_175 ( V_183 , V_8 -> V_9 + V_328 ) ;
while ( ! ( F_174 ( V_8 -> V_9 + V_327 ) & V_329 ) )
F_90 () ;
}
static void F_176 ( struct V_304 * V_330 , const char * V_306 , unsigned V_331 )
{
struct V_332 * V_2 = V_330 -> V_89 ;
F_161 ( & V_2 -> V_8 , V_306 , V_331 , F_173 ) ;
}
static void F_177 ( struct V_127 * V_8 , int V_183 )
{
while ( F_174 ( V_8 -> V_9 + V_327 ) & V_126 )
F_90 () ;
if ( V_8 -> V_10 == V_11 )
F_175 ( V_183 , V_8 -> V_9 + V_328 ) ;
else
F_178 ( V_183 , V_8 -> V_9 + V_328 ) ;
while ( F_174 ( V_8 -> V_9 + V_327 ) & V_333 )
F_90 () ;
}
static void F_179 ( struct V_304 * V_330 , const char * V_306 , unsigned V_331 )
{
struct V_332 * V_2 = V_330 -> V_89 ;
F_161 ( & V_2 -> V_8 , V_306 , V_331 , F_177 ) ;
}
static int T_10 F_180 ( struct V_332 * V_46 ,
const char * V_334 )
{
if ( ! V_46 -> V_8 . V_9 )
return - V_320 ;
V_46 -> V_330 -> V_335 = F_179 ;
return 0 ;
}
static int T_10
F_181 ( struct V_332 * V_46 ,
const char * V_334 )
{
if ( ! V_46 -> V_8 . V_9 )
return - V_320 ;
V_46 -> V_330 -> V_335 = F_176 ;
return 0 ;
}
static int F_182 ( int V_308 , struct V_46 * V_2 )
{
struct V_336 * V_337 ;
static bool V_338 = false ;
static bool V_339 = false ;
int V_125 = V_308 ;
if ( ! F_183 ( V_340 ) )
return V_125 ;
V_337 = V_2 -> V_87 ;
if ( ! V_337 )
return V_125 ;
V_125 = F_184 ( V_337 , L_29 ) ;
if ( V_125 < 0 ) {
V_339 = true ;
V_125 = V_308 ;
} else {
V_338 = true ;
if ( V_125 >= F_172 ( V_307 ) || V_307 [ V_125 ] != NULL ) {
F_68 ( V_2 , L_30 , V_125 ) ;
V_125 = V_308 ;
}
}
if ( V_338 && V_339 )
F_68 ( V_2 , L_31 ) ;
return V_125 ;
}
static void F_185 ( struct V_3 * V_4 )
{
int V_243 ;
bool V_341 = false ;
for ( V_243 = 0 ; V_243 < F_172 ( V_307 ) ; V_243 ++ ) {
if ( V_307 [ V_243 ] == V_4 )
V_307 [ V_243 ] = NULL ;
else if ( V_307 [ V_243 ] )
V_341 = true ;
}
F_44 ( V_4 ) ;
if ( ! V_341 )
F_186 ( & V_342 ) ;
}
static int F_187 ( void )
{
int V_243 ;
for ( V_243 = 0 ; V_243 < F_172 ( V_307 ) ; V_243 ++ )
if ( V_307 [ V_243 ] == NULL )
return V_243 ;
return - V_112 ;
}
static int F_188 ( struct V_46 * V_2 , struct V_3 * V_4 ,
struct V_343 * V_344 , int V_308 )
{
void T_1 * V_345 ;
V_345 = F_189 ( V_2 , V_344 ) ;
if ( F_30 ( V_345 ) )
return F_31 ( V_345 ) ;
V_308 = F_182 ( V_308 , V_2 ) ;
V_4 -> V_247 = 0 ;
V_4 -> V_8 . V_2 = V_2 ;
V_4 -> V_8 . V_55 = V_344 -> V_346 ;
V_4 -> V_8 . V_9 = V_345 ;
V_4 -> V_8 . V_61 = V_4 -> V_61 ;
V_4 -> V_8 . V_91 = V_347 ;
V_4 -> V_8 . line = V_308 ;
V_307 [ V_308 ] = V_4 ;
return 0 ;
}
static int F_190 ( struct V_3 * V_4 )
{
int V_125 ;
F_9 ( 0 , V_4 , V_123 ) ;
F_9 ( 0xffff , V_4 , V_150 ) ;
if ( ! V_342 . V_98 ) {
V_125 = F_191 ( & V_342 ) ;
if ( V_125 < 0 ) {
F_36 ( V_4 -> V_8 . V_2 ,
L_32 ) ;
return V_125 ;
}
}
V_125 = F_192 ( & V_342 , & V_4 -> V_8 ) ;
if ( V_125 )
F_185 ( V_4 ) ;
return V_125 ;
}
static int F_193 ( struct V_1 * V_2 , const struct V_348 * V_349 )
{
struct V_3 * V_4 ;
struct V_350 * V_167 = V_349 -> V_89 ;
int V_351 , V_125 ;
V_351 = F_187 () ;
if ( V_351 < 0 )
return V_351 ;
V_4 = F_194 ( & V_2 -> V_2 , sizeof( struct V_3 ) ,
V_48 ) ;
if ( ! V_4 )
return - V_49 ;
V_4 -> V_239 = F_195 ( & V_2 -> V_2 , NULL ) ;
if ( F_30 ( V_4 -> V_239 ) )
return F_31 ( V_4 -> V_239 ) ;
V_4 -> V_6 = V_167 -> V_6 ;
V_4 -> V_167 = V_167 ;
V_4 -> V_61 = V_167 -> V_352 ( V_2 ) ;
V_4 -> V_8 . V_10 = V_167 -> V_353 ? V_11 : V_325 ;
V_4 -> V_8 . V_195 = V_2 -> V_195 [ 0 ] ;
V_4 -> V_8 . V_253 = & V_354 ;
snprintf ( V_4 -> type , sizeof( V_4 -> type ) , L_33 , F_2 ( V_2 ) ) ;
V_125 = F_188 ( & V_2 -> V_2 , V_4 , & V_2 -> V_355 , V_351 ) ;
if ( V_125 )
return V_125 ;
F_196 ( V_2 , V_4 ) ;
return F_190 ( V_4 ) ;
}
static int F_197 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_198 ( V_2 ) ;
F_199 ( & V_342 , & V_4 -> V_8 ) ;
F_185 ( V_4 ) ;
return 0 ;
}
static int F_200 ( struct V_46 * V_2 )
{
struct V_3 * V_4 = F_201 ( V_2 ) ;
if ( ! V_4 )
return - V_301 ;
return F_202 ( & V_342 , & V_4 -> V_8 ) ;
}
static int F_203 ( struct V_46 * V_2 )
{
struct V_3 * V_4 = F_201 ( V_2 ) ;
if ( ! V_4 )
return - V_301 ;
return F_204 ( & V_342 , & V_4 -> V_8 ) ;
}
static int F_205 ( struct V_356 * V_357 )
{
struct V_3 * V_4 ;
struct V_343 * V_358 ;
int V_351 , V_125 ;
int V_359 ;
if ( V_357 -> V_2 . V_87 ) {
struct V_336 * V_337 = V_357 -> V_2 . V_87 ;
V_125 = F_43 ( V_337 , L_34 , & V_359 ) ;
if ( V_125 )
return V_125 ;
} else {
V_359 = 115200 ;
}
V_351 = F_187 () ;
if ( V_351 < 0 )
return V_351 ;
V_4 = F_194 ( & V_357 -> V_2 , sizeof( struct V_3 ) ,
V_48 ) ;
if ( ! V_4 )
return - V_49 ;
V_125 = F_206 ( V_357 , 0 ) ;
if ( V_125 < 0 ) {
if ( V_125 != - V_65 )
F_36 ( & V_357 -> V_2 , L_35 ) ;
return V_125 ;
}
V_4 -> V_8 . V_195 = V_125 ;
V_4 -> V_6 = V_360 . V_6 ;
V_4 -> V_167 = V_324 ?
& V_361 : & V_360 ;
V_4 -> V_61 = 32 ;
V_4 -> V_8 . V_10 = V_360 . V_353 ? V_11 : V_325 ;
V_4 -> V_8 . V_253 = & V_362 ;
V_4 -> V_292 = V_359 ;
snprintf ( V_4 -> type , sizeof( V_4 -> type ) , L_36 ) ;
V_358 = F_207 ( V_357 , V_363 , 0 ) ;
V_125 = F_188 ( & V_357 -> V_2 , V_4 , V_358 , V_351 ) ;
if ( V_125 )
return V_125 ;
F_208 ( V_357 , V_4 ) ;
return F_190 ( V_4 ) ;
}
static int F_209 ( struct V_356 * V_357 )
{
struct V_3 * V_4 = F_210 ( V_357 ) ;
F_199 ( & V_342 , & V_4 -> V_8 ) ;
F_185 ( V_4 ) ;
return 0 ;
}
static int T_10 F_211 ( void )
{
F_212 ( V_364 L_37 ) ;
if ( F_213 ( & V_365 ) )
F_214 ( L_38 ) ;
return F_215 ( & V_366 ) ;
}
static void T_12 F_216 ( void )
{
F_217 ( & V_365 ) ;
F_218 ( & V_366 ) ;
}
