static void F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const unsigned int V_7 = V_6 -> V_8 . V_9 ;
unsigned int V_10 ;
V_6 -> V_8 . V_9 = 0 ;
V_10 = F_3 ( V_4 ) -> V_11 ? : V_4 -> V_10 ;
if ( V_10 >= V_6 -> V_8 . V_12 ) {
V_6 -> V_8 . V_12 = V_10 ;
} else {
V_10 += V_4 -> V_13 - F_4 ( V_4 ) ;
if ( V_10 >= V_14 + sizeof( struct V_15 ) ||
( V_10 >= V_16 + sizeof( struct V_15 ) &&
! ( F_5 ( F_6 ( V_4 ) ) & V_17 ) ) ) {
V_10 -= F_7 ( V_2 ) -> V_18 ;
V_6 -> V_8 . V_9 = V_10 ;
if ( V_10 == V_7 ) {
V_6 -> V_8 . V_12 = V_10 ;
return;
}
}
if ( V_6 -> V_8 . V_19 & V_20 )
V_6 -> V_8 . V_19 |= V_21 ;
V_6 -> V_8 . V_19 |= V_20 ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_22 = F_7 ( V_2 ) -> V_23 / ( 2 * V_6 -> V_8 . V_12 ) ;
if ( V_22 == 0 )
V_22 = 2 ;
if ( V_22 > V_6 -> V_8 . V_24 )
V_6 -> V_8 . V_24 = F_9 ( V_22 , V_25 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_8 ( V_2 ) ;
V_6 -> V_8 . V_26 = 0 ;
V_6 -> V_8 . V_27 = V_28 ;
}
static bool F_11 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_29 * V_30 = F_12 ( V_2 ) ;
return ( V_30 && F_13 ( V_30 , V_31 ) ) ||
( V_6 -> V_8 . V_24 && ! V_6 -> V_8 . V_26 ) ;
}
static void F_14 ( struct V_32 * V_33 )
{
if ( V_33 -> V_34 & V_35 )
V_33 -> V_34 |= V_36 ;
}
static void F_15 ( struct V_32 * V_33 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) -> V_37 )
V_33 -> V_34 &= ~ V_38 ;
}
static void F_16 ( struct V_32 * V_33 )
{
V_33 -> V_34 &= ~ V_38 ;
}
static void F_17 ( struct V_32 * V_33 , const struct V_3 * V_4 )
{
switch ( F_18 ( V_4 ) -> V_39 & V_40 ) {
case V_41 :
if ( V_33 -> V_34 & V_42 )
F_10 ( (struct V_1 * ) V_33 ) ;
break;
case V_43 :
if ( F_19 ( (struct V_1 * ) V_33 ) )
F_20 ( (struct V_1 * ) V_33 , V_44 ) ;
if ( ! ( V_33 -> V_34 & V_38 ) ) {
F_10 ( (struct V_1 * ) V_33 ) ;
V_33 -> V_34 |= V_38 ;
}
V_33 -> V_34 |= V_42 ;
break;
default:
if ( F_19 ( (struct V_1 * ) V_33 ) )
F_20 ( (struct V_1 * ) V_33 , V_45 ) ;
V_33 -> V_34 |= V_42 ;
break;
}
}
static void F_21 ( struct V_32 * V_33 , const struct V_3 * V_4 )
{
if ( V_33 -> V_34 & V_35 )
F_17 ( V_33 , V_4 ) ;
}
static void F_22 ( struct V_32 * V_33 , const struct V_15 * V_46 )
{
if ( ( V_33 -> V_34 & V_35 ) && ( ! V_46 -> V_47 || V_46 -> V_37 ) )
V_33 -> V_34 &= ~ V_35 ;
}
static void F_23 ( struct V_32 * V_33 , const struct V_15 * V_46 )
{
if ( ( V_33 -> V_34 & V_35 ) && ( ! V_46 -> V_47 || ! V_46 -> V_37 ) )
V_33 -> V_34 &= ~ V_35 ;
}
static bool F_24 ( const struct V_32 * V_33 , const struct V_15 * V_46 )
{
if ( V_46 -> V_47 && ! V_46 -> V_48 && ( V_33 -> V_34 & V_35 ) )
return true ;
return false ;
}
static void F_25 ( struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_49 , V_50 ;
T_1 V_51 ;
V_50 = F_26 ( T_1 , V_33 -> V_52 . V_53 , V_33 -> V_54 ) +
V_55 +
F_27 ( sizeof( struct V_56 ) ) ;
V_50 = F_28 ( V_50 ) +
F_27 ( sizeof( struct V_3 ) ) ;
V_51 = F_26 ( T_1 , V_57 , V_33 -> V_58 ) ;
V_51 = F_26 ( T_1 , V_51 , V_33 -> V_59 + 1 ) ;
V_49 = 2 * V_51 * V_50 ;
if ( V_2 -> V_60 < V_49 )
V_2 -> V_60 = F_9 ( V_49 , V_61 [ 2 ] ) ;
}
static int F_29 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_62 = F_30 ( V_4 -> V_62 ) >> 1 ;
int V_63 = F_30 ( V_64 [ 2 ] ) >> 1 ;
while ( V_33 -> V_65 <= V_63 ) {
if ( V_62 <= V_4 -> V_10 )
return 2 * F_2 ( V_2 ) -> V_8 . V_12 ;
V_62 >>= 1 ;
V_63 >>= 1 ;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_33 -> V_65 < V_33 -> V_66 &&
( int ) V_33 -> V_65 < F_32 ( V_2 ) &&
! F_33 ( V_2 ) ) {
int V_67 ;
if ( F_30 ( V_4 -> V_62 ) <= V_4 -> V_10 )
V_67 = 2 * V_33 -> V_68 ;
else
V_67 = F_29 ( V_2 , V_4 ) ;
if ( V_67 ) {
V_67 = F_26 ( int , V_67 , 2 * V_4 -> V_10 ) ;
V_33 -> V_65 = F_9 ( V_33 -> V_65 + V_67 ,
V_33 -> V_66 ) ;
F_2 ( V_2 ) -> V_8 . V_24 |= 1 ;
}
}
}
static void F_34 ( struct V_1 * V_2 )
{
T_1 V_69 = F_7 ( V_2 ) -> V_68 ;
int V_70 ;
V_70 = 2 * F_35 ( V_69 + V_55 ) *
F_36 ( V_69 ) ;
if ( V_71 )
V_70 <<= 2 ;
if ( V_2 -> V_72 < V_70 )
V_2 -> V_72 = F_9 ( V_70 , V_64 [ 2 ] ) ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_73 ;
if ( ! ( V_2 -> V_74 & V_75 ) )
F_34 ( V_2 ) ;
if ( ! ( V_2 -> V_74 & V_76 ) )
F_25 ( V_2 ) ;
V_33 -> V_77 . V_78 = V_33 -> V_23 ;
V_33 -> V_77 . time = V_79 ;
V_33 -> V_77 . V_80 = V_33 -> V_81 ;
V_73 = F_38 ( V_2 ) ;
if ( V_33 -> V_66 >= V_73 ) {
V_33 -> V_66 = V_73 ;
if ( V_82 && V_73 > 4 * V_33 -> V_68 )
V_33 -> V_66 = F_39 ( V_73 -
( V_73 >> V_82 ) ,
4 * V_33 -> V_68 ) ;
}
if ( V_82 &&
V_33 -> V_66 > 2 * V_33 -> V_68 &&
V_33 -> V_66 + V_33 -> V_68 > V_73 )
V_33 -> V_66 = F_39 ( 2 * V_33 -> V_68 , V_73 - V_33 -> V_68 ) ;
V_33 -> V_65 = F_9 ( V_33 -> V_65 , V_33 -> V_66 ) ;
V_33 -> V_83 = V_79 ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_8 . V_24 = 0 ;
if ( V_2 -> V_72 < V_64 [ 2 ] &&
! ( V_2 -> V_74 & V_75 ) &&
! F_33 ( V_2 ) &&
F_41 ( V_2 ) < F_42 ( V_2 , 0 ) ) {
V_2 -> V_72 = F_9 ( F_43 ( & V_2 -> V_84 ) ,
V_64 [ 2 ] ) ;
}
if ( F_43 ( & V_2 -> V_84 ) > V_2 -> V_72 )
V_33 -> V_65 = F_9 ( V_33 -> V_66 , 2U * V_33 -> V_68 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
unsigned int V_85 = F_45 (unsigned int, tp->advmss, tp->mss_cache) ;
V_85 = F_9 ( V_85 , V_33 -> V_23 / 2 ) ;
V_85 = F_9 ( V_85 , V_14 ) ;
V_85 = F_39 ( V_85 , V_16 ) ;
F_2 ( V_2 ) -> V_8 . V_12 = V_85 ;
}
static void F_46 ( struct V_32 * V_33 , T_1 V_86 , int V_87 )
{
T_1 V_88 = V_33 -> V_89 . V_90 ;
long V_91 = V_86 ;
if ( V_91 == 0 )
V_91 = 1 ;
if ( V_88 != 0 ) {
if ( ! V_87 ) {
V_91 -= ( V_88 >> 3 ) ;
V_88 += V_91 ;
} else {
V_91 <<= 3 ;
if ( V_91 < V_88 )
V_88 = V_91 ;
}
} else {
V_88 = V_91 << 3 ;
}
if ( V_33 -> V_89 . V_90 != V_88 )
V_33 -> V_89 . V_90 = V_88 ;
}
static inline void F_47 ( struct V_32 * V_33 )
{
if ( V_33 -> V_89 . time == 0 )
goto V_92;
if ( F_48 ( V_33 -> V_93 , V_33 -> V_89 . V_80 ) )
return;
F_46 ( V_33 , V_79 - V_33 -> V_89 . time , 1 ) ;
V_92:
V_33 -> V_89 . V_80 = V_33 -> V_93 + V_33 -> V_23 ;
V_33 -> V_89 . time = V_79 ;
}
static inline void F_49 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_33 -> V_52 . V_94 &&
( F_18 ( V_4 ) -> V_95 -
F_18 ( V_4 ) -> V_80 >= F_2 ( V_2 ) -> V_8 . V_12 ) )
F_46 ( V_33 , V_79 - V_33 -> V_52 . V_94 , 0 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int time ;
int V_96 ;
time = V_79 - V_33 -> V_77 . time ;
if ( time < ( V_33 -> V_89 . V_90 >> 3 ) || V_33 -> V_89 . V_90 == 0 )
return;
V_96 = V_33 -> V_81 - V_33 -> V_77 . V_80 ;
if ( V_96 <= V_33 -> V_77 . V_78 )
goto V_92;
if ( V_71 &&
! ( V_2 -> V_74 & V_75 ) ) {
int V_97 , V_70 , V_98 ;
V_97 = ( V_96 << 1 ) + 16 * V_33 -> V_68 ;
if ( V_96 >=
V_33 -> V_77 . V_78 + ( V_33 -> V_77 . V_78 >> 2 ) ) {
if ( V_96 >=
V_33 -> V_77 . V_78 + ( V_33 -> V_77 . V_78 >> 1 ) )
V_97 <<= 1 ;
else
V_97 += ( V_97 >> 1 ) ;
}
V_70 = F_35 ( V_33 -> V_68 + V_55 ) ;
while ( F_30 ( V_70 ) < V_33 -> V_68 )
V_70 += 128 ;
V_98 = F_9 ( V_97 / V_33 -> V_68 * V_70 , V_64 [ 2 ] ) ;
if ( V_98 > V_2 -> V_72 ) {
V_2 -> V_72 = V_98 ;
V_33 -> V_66 = V_97 ;
}
}
V_33 -> V_77 . V_78 = V_96 ;
V_92:
V_33 -> V_77 . V_80 = V_33 -> V_81 ;
V_33 -> V_77 . time = V_79 ;
}
static void F_51 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_99 ;
F_52 ( V_2 ) ;
F_1 ( V_2 , V_4 ) ;
F_47 ( V_33 ) ;
V_99 = V_79 ;
if ( ! V_6 -> V_8 . V_27 ) {
F_8 ( V_2 ) ;
V_6 -> V_8 . V_27 = V_28 ;
} else {
int V_91 = V_99 - V_6 -> V_8 . V_100 ;
if ( V_91 <= V_28 / 2 ) {
V_6 -> V_8 . V_27 = ( V_6 -> V_8 . V_27 >> 1 ) + V_28 / 2 ;
} else if ( V_91 < V_6 -> V_8 . V_27 ) {
V_6 -> V_8 . V_27 = ( V_6 -> V_8 . V_27 >> 1 ) + V_91 ;
if ( V_6 -> V_8 . V_27 > V_6 -> V_101 )
V_6 -> V_8 . V_27 = V_6 -> V_101 ;
} else if ( V_91 > V_6 -> V_101 ) {
F_8 ( V_2 ) ;
F_53 ( V_2 ) ;
}
}
V_6 -> V_8 . V_100 = V_99 ;
F_21 ( V_33 , V_4 ) ;
if ( V_4 -> V_10 >= 128 )
F_31 ( V_2 , V_4 ) ;
}
static void F_54 ( struct V_1 * V_2 , long V_102 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
long V_91 = V_102 ;
T_1 V_103 = V_33 -> V_104 ;
if ( V_103 != 0 ) {
V_91 -= ( V_103 >> 3 ) ;
V_103 += V_91 ;
if ( V_91 < 0 ) {
V_91 = - V_91 ;
V_91 -= ( V_33 -> V_105 >> 2 ) ;
if ( V_91 > 0 )
V_91 >>= 3 ;
} else {
V_91 -= ( V_33 -> V_105 >> 2 ) ;
}
V_33 -> V_105 += V_91 ;
if ( V_33 -> V_105 > V_33 -> V_106 ) {
V_33 -> V_106 = V_33 -> V_105 ;
if ( V_33 -> V_106 > V_33 -> V_107 )
V_33 -> V_107 = V_33 -> V_106 ;
}
if ( F_55 ( V_33 -> V_108 , V_33 -> V_109 ) ) {
if ( V_33 -> V_106 < V_33 -> V_107 )
V_33 -> V_107 -= ( V_33 -> V_107 - V_33 -> V_106 ) >> 2 ;
V_33 -> V_109 = V_33 -> V_110 ;
V_33 -> V_106 = F_56 ( V_2 ) ;
}
} else {
V_103 = V_91 << 3 ;
V_33 -> V_105 = V_91 << 1 ;
V_33 -> V_107 = F_39 ( V_33 -> V_105 , F_56 ( V_2 ) ) ;
V_33 -> V_106 = V_33 -> V_107 ;
V_33 -> V_109 = V_33 -> V_110 ;
}
V_33 -> V_104 = F_39 ( 1U , V_103 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
T_2 V_111 ;
V_111 = ( T_2 ) V_33 -> V_54 * ( ( V_112 / 100 ) << 3 ) ;
if ( V_33 -> V_58 < V_33 -> V_113 / 2 )
V_111 *= V_114 ;
else
V_111 *= V_115 ;
V_111 *= F_39 ( V_33 -> V_58 , V_33 -> V_116 ) ;
if ( F_58 ( V_33 -> V_104 ) )
F_59 ( V_111 , V_33 -> V_104 ) ;
F_60 ( V_2 -> V_117 ) = F_45 ( T_2 , V_111 ,
V_2 -> V_118 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
F_2 ( V_2 ) -> V_101 = F_62 ( V_33 ) ;
F_63 ( V_2 ) ;
}
T_3 F_64 ( const struct V_32 * V_33 , const struct V_29 * V_30 )
{
T_3 V_119 = ( V_30 ? F_13 ( V_30 , V_120 ) : 0 ) ;
if ( ! V_119 )
V_119 = V_57 ;
return F_45 ( T_3 , V_119 , V_33 -> V_121 ) ;
}
void F_65 ( struct V_32 * V_33 )
{
if ( F_66 ( V_33 ) )
V_33 -> V_122 = NULL ;
V_33 -> V_52 . V_123 &= ~ V_124 ;
}
static void F_67 ( struct V_32 * V_33 )
{
V_33 -> V_52 . V_123 |= V_125 ;
}
static void F_68 ( struct V_1 * V_2 , const int V_126 ,
const int V_127 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_126 > V_33 -> V_59 ) {
int V_128 ;
V_33 -> V_59 = F_9 ( V_129 , V_126 ) ;
if ( V_127 )
V_128 = V_130 ;
else if ( F_69 ( V_33 ) )
V_128 = V_131 ;
else if ( F_66 ( V_33 ) )
V_128 = V_132 ;
else
V_128 = V_133 ;
F_70 ( F_71 ( V_2 ) , V_128 ) ;
#if V_134 > 1
F_72 ( L_1 ,
V_33 -> V_52 . V_123 , F_2 ( V_2 ) -> V_135 ,
V_33 -> V_59 ,
V_33 -> V_136 ,
V_33 -> V_137 ,
V_33 -> V_138 ? V_33 -> V_139 : 0 ) ;
#endif
F_65 ( V_33 ) ;
}
if ( V_126 > 0 )
F_73 ( V_33 ) ;
V_33 -> V_140 . V_141 = 1 ;
}
static void F_74 ( struct V_32 * V_33 , struct V_3 * V_4 )
{
if ( ! V_33 -> V_142 ||
F_48 ( F_18 ( V_4 ) -> V_80 ,
F_18 ( V_33 -> V_142 ) -> V_80 ) )
V_33 -> V_142 = V_4 ;
if ( ! V_33 -> V_143 ||
F_55 ( F_18 ( V_4 ) -> V_95 , V_33 -> V_144 ) )
V_33 -> V_144 = F_18 ( V_4 ) -> V_95 ;
}
static void F_75 ( struct V_32 * V_33 , struct V_3 * V_4 )
{
if ( ! ( F_18 ( V_4 ) -> V_145 & ( V_146 | V_147 ) ) ) {
F_74 ( V_33 , V_4 ) ;
V_33 -> V_143 += F_76 ( V_4 ) ;
F_18 ( V_4 ) -> V_145 |= V_146 ;
}
}
void F_77 ( struct V_32 * V_33 , struct V_3 * V_4 )
{
F_74 ( V_33 , V_4 ) ;
if ( ! ( F_18 ( V_4 ) -> V_145 & ( V_146 | V_147 ) ) ) {
V_33 -> V_143 += F_76 ( V_4 ) ;
F_18 ( V_4 ) -> V_145 |= V_146 ;
}
}
static bool F_78 ( struct V_32 * V_33 , bool V_148 ,
T_1 V_149 , T_1 V_95 )
{
if ( F_55 ( V_95 , V_33 -> V_110 ) || ! F_48 ( V_149 , V_95 ) )
return false ;
if ( ! F_48 ( V_149 , V_33 -> V_110 ) )
return false ;
if ( F_55 ( V_149 , V_33 -> V_108 ) )
return true ;
if ( ! V_148 || ! V_33 -> V_138 )
return false ;
if ( F_55 ( V_95 , V_33 -> V_108 ) )
return false ;
if ( ! F_48 ( V_149 , V_33 -> V_138 ) )
return true ;
if ( ! F_55 ( V_95 , V_33 -> V_138 ) )
return false ;
return ! F_48 ( V_149 , V_95 - V_33 -> V_150 ) ;
}
static bool F_79 ( struct V_1 * V_2 , const struct V_3 * V_151 ,
struct V_152 * V_153 , int V_154 ,
T_1 V_155 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_1 V_156 = F_80 ( & V_153 [ 0 ] . V_149 ) ;
T_1 V_157 = F_80 ( & V_153 [ 0 ] . V_95 ) ;
bool V_158 = false ;
if ( F_48 ( V_156 , F_18 ( V_151 ) -> V_159 ) ) {
V_158 = true ;
F_67 ( V_33 ) ;
F_70 ( F_71 ( V_2 ) , V_160 ) ;
} else if ( V_154 > 1 ) {
T_1 V_161 = F_80 ( & V_153 [ 1 ] . V_95 ) ;
T_1 V_162 = F_80 ( & V_153 [ 1 ] . V_149 ) ;
if ( ! F_55 ( V_157 , V_161 ) &&
! F_48 ( V_156 , V_162 ) ) {
V_158 = true ;
F_67 ( V_33 ) ;
F_70 ( F_71 ( V_2 ) ,
V_163 ) ;
}
}
if ( V_158 && V_33 -> V_138 && V_33 -> V_139 > 0 &&
! F_55 ( V_157 , V_155 ) &&
F_55 ( V_157 , V_33 -> V_138 ) )
V_33 -> V_139 -- ;
return V_158 ;
}
static int F_81 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_149 , T_1 V_95 )
{
int V_164 ;
bool V_165 ;
unsigned int V_166 ;
unsigned int V_69 ;
V_165 = ! F_55 ( V_149 , F_18 ( V_4 ) -> V_80 ) &&
! F_48 ( V_95 , F_18 ( V_4 ) -> V_95 ) ;
if ( F_76 ( V_4 ) > 1 && ! V_165 &&
F_55 ( F_18 ( V_4 ) -> V_95 , V_149 ) ) {
V_69 = F_82 ( V_4 ) ;
V_165 = ! F_55 ( V_149 , F_18 ( V_4 ) -> V_80 ) ;
if ( ! V_165 ) {
V_166 = V_149 - F_18 ( V_4 ) -> V_80 ;
if ( V_166 < V_69 )
V_166 = V_69 ;
} else {
V_166 = V_95 - F_18 ( V_4 ) -> V_80 ;
if ( V_166 < V_69 )
return - V_167 ;
}
if ( V_166 > V_69 ) {
unsigned int V_168 = ( V_166 / V_69 ) * V_69 ;
if ( ! V_165 && V_168 < V_166 ) {
V_168 += V_69 ;
if ( V_168 >= V_4 -> V_10 )
return 0 ;
}
V_166 = V_168 ;
}
V_164 = F_83 ( V_2 , V_4 , V_166 , V_69 , V_169 ) ;
if ( V_164 < 0 )
return V_164 ;
}
return V_165 ;
}
static T_4 F_84 ( struct V_1 * V_2 ,
struct V_170 * V_171 , T_4 V_145 ,
T_1 V_149 , T_1 V_95 ,
int V_158 , int V_172 ,
const struct V_173 * V_174 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_175 = V_171 -> V_175 ;
if ( V_158 && ( V_145 & V_176 ) ) {
if ( V_33 -> V_138 && V_33 -> V_139 > 0 &&
F_55 ( V_95 , V_33 -> V_138 ) )
V_33 -> V_139 -- ;
if ( V_145 & V_147 )
V_171 -> V_141 = F_9 ( V_175 , V_171 -> V_141 ) ;
}
if ( ! F_55 ( V_95 , V_33 -> V_108 ) )
return V_145 ;
if ( ! ( V_145 & V_147 ) ) {
F_85 ( V_33 , V_174 , V_145 ) ;
if ( V_145 & V_177 ) {
if ( V_145 & V_146 ) {
V_145 &= ~ ( V_146 | V_177 ) ;
V_33 -> V_143 -= V_172 ;
V_33 -> V_178 -= V_172 ;
}
} else {
if ( ! ( V_145 & V_176 ) ) {
if ( F_48 ( V_149 ,
F_86 ( V_33 ) ) )
V_171 -> V_141 = F_9 ( V_175 ,
V_171 -> V_141 ) ;
if ( ! F_55 ( V_95 , V_33 -> V_179 ) )
V_171 -> V_180 |= V_181 ;
if ( V_171 -> V_182 . V_183 == 0 )
V_171 -> V_182 = * V_174 ;
V_171 -> V_184 = * V_174 ;
}
if ( V_145 & V_146 ) {
V_145 &= ~ V_146 ;
V_33 -> V_143 -= V_172 ;
}
}
V_145 |= V_147 ;
V_171 -> V_180 |= V_185 ;
V_33 -> V_137 += V_172 ;
V_175 += V_172 ;
if ( ! F_66 ( V_33 ) && V_33 -> V_122 &&
F_48 ( V_149 , F_18 ( V_33 -> V_122 ) -> V_80 ) )
V_33 -> V_186 += V_172 ;
if ( V_175 > V_33 -> V_136 )
V_33 -> V_136 = V_175 ;
}
if ( V_158 && ( V_145 & V_177 ) ) {
V_145 &= ~ V_177 ;
V_33 -> V_178 -= V_172 ;
}
return V_145 ;
}
static bool F_87 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_170 * V_171 ,
unsigned int V_172 , int V_187 , int V_69 ,
bool V_158 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_188 = F_88 ( V_2 , V_4 ) ;
T_1 V_149 = F_18 ( V_4 ) -> V_80 ;
T_1 V_95 = V_149 + V_187 ;
F_89 ( ! V_172 ) ;
F_84 ( V_2 , V_171 , F_18 ( V_4 ) -> V_145 ,
V_149 , V_95 , V_158 , V_172 ,
& V_4 -> V_173 ) ;
if ( V_4 == V_33 -> V_122 )
V_33 -> V_186 += V_172 ;
F_18 ( V_188 ) -> V_95 += V_187 ;
F_18 ( V_4 ) -> V_80 += V_187 ;
F_90 ( V_188 , V_172 ) ;
F_89 ( F_76 ( V_4 ) < V_172 ) ;
F_90 ( V_4 , - V_172 ) ;
if ( ! F_18 ( V_188 ) -> V_189 )
F_18 ( V_188 ) -> V_189 = V_69 ;
if ( F_76 ( V_4 ) <= 1 )
F_18 ( V_4 ) -> V_189 = 0 ;
F_18 ( V_188 ) -> V_145 |= ( F_18 ( V_4 ) -> V_145 & V_190 ) ;
if ( V_4 -> V_10 > 0 ) {
F_89 ( ! F_76 ( V_4 ) ) ;
F_70 ( F_71 ( V_2 ) , V_191 ) ;
return false ;
}
if ( V_4 == V_33 -> V_142 )
V_33 -> V_142 = V_188 ;
if ( V_4 == V_33 -> V_122 ) {
V_33 -> V_122 = V_188 ;
V_33 -> V_186 -= F_76 ( V_188 ) ;
}
F_18 ( V_188 ) -> V_192 |= F_18 ( V_4 ) -> V_192 ;
if ( F_18 ( V_4 ) -> V_192 & V_193 )
F_18 ( V_188 ) -> V_95 ++ ;
if ( V_4 == F_91 ( V_2 ) )
F_92 ( V_2 , V_4 ) ;
F_93 ( V_4 , V_2 ) ;
F_94 ( V_2 , V_4 ) ;
F_70 ( F_71 ( V_2 ) , V_194 ) ;
return true ;
}
static int F_95 ( const struct V_3 * V_4 )
{
return F_76 ( V_4 ) == 1 ? V_4 -> V_10 : F_82 ( V_4 ) ;
}
static int F_96 ( const struct V_3 * V_4 )
{
return ! F_97 ( V_4 ) && F_98 ( V_4 ) ;
}
static struct V_3 * F_99 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_170 * V_171 ,
T_1 V_149 , T_1 V_95 ,
bool V_158 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_188 ;
int V_69 ;
int V_172 = 0 ;
int V_10 ;
int V_165 ;
if ( ! F_100 ( V_2 ) )
goto V_195;
if ( ! V_158 &&
( F_18 ( V_4 ) -> V_145 & ( V_146 | V_177 ) ) == V_177 )
goto V_195;
if ( ! F_96 ( V_4 ) )
goto V_195;
if ( ! F_55 ( F_18 ( V_4 ) -> V_95 , V_33 -> V_108 ) )
goto V_195;
if ( F_101 ( V_4 == F_102 ( V_2 ) ) )
goto V_195;
V_188 = F_88 ( V_2 , V_4 ) ;
if ( ( F_18 ( V_188 ) -> V_145 & V_196 ) != V_147 )
goto V_195;
V_165 = ! F_55 ( V_149 , F_18 ( V_4 ) -> V_80 ) &&
! F_48 ( V_95 , F_18 ( V_4 ) -> V_95 ) ;
if ( V_165 ) {
V_10 = V_4 -> V_10 ;
V_172 = F_76 ( V_4 ) ;
V_69 = F_95 ( V_4 ) ;
if ( V_69 != F_95 ( V_188 ) )
goto V_195;
} else {
if ( ! F_55 ( F_18 ( V_4 ) -> V_95 , V_149 ) )
goto V_197;
if ( F_76 ( V_4 ) <= 1 )
goto V_197;
V_165 = ! F_55 ( V_149 , F_18 ( V_4 ) -> V_80 ) ;
if ( ! V_165 ) {
goto V_195;
}
V_10 = V_95 - F_18 ( V_4 ) -> V_80 ;
F_89 ( V_10 < 0 ) ;
F_89 ( V_10 > V_4 -> V_10 ) ;
V_69 = F_82 ( V_4 ) ;
if ( V_69 != F_95 ( V_188 ) )
goto V_195;
if ( V_10 == V_69 ) {
V_172 = 1 ;
} else if ( V_10 < V_69 ) {
goto V_197;
} else {
V_172 = V_10 / V_69 ;
V_10 = V_172 * V_69 ;
}
}
if ( ! F_55 ( F_18 ( V_4 ) -> V_80 + V_10 , V_33 -> V_108 ) )
goto V_195;
if ( ! F_103 ( V_188 , V_4 , V_10 ) )
goto V_195;
if ( ! F_87 ( V_2 , V_4 , V_171 , V_172 , V_10 , V_69 , V_158 ) )
goto V_198;
if ( V_188 == F_104 ( V_2 ) )
goto V_198;
V_4 = F_105 ( V_2 , V_188 ) ;
if ( ! F_96 ( V_4 ) ||
( V_4 == F_106 ( V_2 ) ) ||
( ( F_18 ( V_4 ) -> V_145 & V_196 ) != V_147 ) ||
( V_69 != F_95 ( V_4 ) ) )
goto V_198;
V_10 = V_4 -> V_10 ;
if ( F_103 ( V_188 , V_4 , V_10 ) ) {
V_172 += F_76 ( V_4 ) ;
F_87 ( V_2 , V_4 , V_171 , F_76 ( V_4 ) , V_10 , V_69 , 0 ) ;
}
V_198:
V_171 -> V_175 += V_172 ;
return V_188 ;
V_197:
return V_4 ;
V_195:
F_70 ( F_71 ( V_2 ) , V_199 ) ;
return NULL ;
}
static struct V_3 * F_107 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_200 * V_201 ,
struct V_170 * V_171 ,
T_1 V_149 , T_1 V_95 ,
bool V_202 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_203 ;
F_108 (skb, sk) {
int V_165 = 0 ;
bool V_158 = V_202 ;
if ( V_4 == F_106 ( V_2 ) )
break;
if ( ! F_48 ( F_18 ( V_4 ) -> V_80 , V_95 ) )
break;
if ( V_201 &&
F_48 ( F_18 ( V_4 ) -> V_80 , V_201 -> V_95 ) ) {
V_165 = F_81 ( V_2 , V_4 ,
V_201 -> V_149 ,
V_201 -> V_95 ) ;
if ( V_165 > 0 )
V_158 = true ;
}
if ( V_165 <= 0 ) {
V_203 = F_99 ( V_2 , V_4 , V_171 ,
V_149 , V_95 , V_158 ) ;
if ( V_203 ) {
if ( V_203 != V_4 ) {
V_4 = V_203 ;
continue;
}
V_165 = 0 ;
} else {
V_165 = F_81 ( V_2 , V_4 ,
V_149 ,
V_95 ) ;
}
}
if ( F_101 ( V_165 < 0 ) )
break;
if ( V_165 ) {
F_18 ( V_4 ) -> V_145 =
F_84 ( V_2 ,
V_171 ,
F_18 ( V_4 ) -> V_145 ,
F_18 ( V_4 ) -> V_80 ,
F_18 ( V_4 ) -> V_95 ,
V_158 ,
F_76 ( V_4 ) ,
& V_4 -> V_173 ) ;
if ( ! F_48 ( F_18 ( V_4 ) -> V_80 ,
F_86 ( V_33 ) ) )
F_92 ( V_2 , V_4 ) ;
}
V_171 -> V_175 += F_76 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_109 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_170 * V_171 ,
T_1 V_204 )
{
F_108 (skb, sk) {
if ( V_4 == F_106 ( V_2 ) )
break;
if ( F_55 ( F_18 ( V_4 ) -> V_95 , V_204 ) )
break;
V_171 -> V_175 += F_76 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_110 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_200 * V_201 ,
struct V_170 * V_171 ,
T_1 V_204 )
{
if ( ! V_201 )
return V_4 ;
if ( F_48 ( V_201 -> V_149 , V_204 ) ) {
V_4 = F_109 ( V_4 , V_2 , V_171 , V_201 -> V_149 ) ;
V_4 = F_107 ( V_4 , V_2 , NULL , V_171 ,
V_201 -> V_149 , V_201 -> V_95 ,
1 ) ;
}
return V_4 ;
}
static int F_111 ( const struct V_32 * V_33 , const struct V_200 * V_205 )
{
return V_205 < V_33 -> V_206 + F_112 ( V_33 -> V_206 ) ;
}
static int
F_113 ( struct V_1 * V_2 , const struct V_3 * V_151 ,
T_1 V_155 , struct V_170 * V_171 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
const unsigned char * V_207 = ( F_4 ( V_151 ) +
F_18 ( V_151 ) -> V_145 ) ;
struct V_152 * V_208 = (struct V_152 * ) ( V_207 + 2 ) ;
struct V_200 V_153 [ V_209 ] ;
struct V_200 * V_205 ;
struct V_3 * V_4 ;
int V_154 = F_9 ( V_209 , ( V_207 [ 1 ] - V_210 ) >> 3 ) ;
int V_211 ;
bool V_212 = false ;
int V_213 , V_214 ;
int V_215 ;
V_171 -> V_180 = 0 ;
V_171 -> V_141 = V_33 -> V_116 ;
if ( ! V_33 -> V_137 ) {
if ( F_114 ( V_33 -> V_136 ) )
V_33 -> V_136 = 0 ;
F_115 ( V_2 ) ;
}
V_212 = F_79 ( V_2 , V_151 , V_208 ,
V_154 , V_155 ) ;
if ( V_212 )
V_171 -> V_180 |= V_216 ;
if ( F_48 ( F_18 ( V_151 ) -> V_159 , V_155 - V_33 -> V_150 ) )
return 0 ;
if ( ! V_33 -> V_116 )
goto V_198;
V_211 = 0 ;
V_215 = 0 ;
for ( V_213 = 0 ; V_213 < V_154 ; V_213 ++ ) {
bool V_158 = ! V_213 && V_212 ;
V_153 [ V_211 ] . V_149 = F_80 ( & V_208 [ V_213 ] . V_149 ) ;
V_153 [ V_211 ] . V_95 = F_80 ( & V_208 [ V_213 ] . V_95 ) ;
if ( ! F_78 ( V_33 , V_158 ,
V_153 [ V_211 ] . V_149 ,
V_153 [ V_211 ] . V_95 ) ) {
int V_128 ;
if ( V_158 ) {
if ( ! V_33 -> V_138 )
V_128 = V_217 ;
else
V_128 = V_218 ;
} else {
if ( ( F_18 ( V_151 ) -> V_159 != V_33 -> V_108 ) &&
! F_55 ( V_153 [ V_211 ] . V_95 , V_33 -> V_108 ) )
continue;
V_128 = V_219 ;
}
F_70 ( F_71 ( V_2 ) , V_128 ) ;
if ( V_213 == 0 )
V_215 = - 1 ;
continue;
}
if ( ! F_55 ( V_153 [ V_211 ] . V_95 , V_155 ) )
continue;
V_211 ++ ;
}
for ( V_213 = V_211 - 1 ; V_213 > 0 ; V_213 -- ) {
for ( V_214 = 0 ; V_214 < V_213 ; V_214 ++ ) {
if ( F_55 ( V_153 [ V_214 ] . V_149 , V_153 [ V_214 + 1 ] . V_149 ) ) {
F_116 ( V_153 [ V_214 ] , V_153 [ V_214 + 1 ] ) ;
if ( V_214 == V_215 )
V_215 = V_214 + 1 ;
}
}
}
V_4 = F_102 ( V_2 ) ;
V_171 -> V_175 = 0 ;
V_213 = 0 ;
if ( ! V_33 -> V_137 ) {
V_205 = V_33 -> V_206 + F_112 ( V_33 -> V_206 ) ;
} else {
V_205 = V_33 -> V_206 ;
while ( F_111 ( V_33 , V_205 ) && ! V_205 -> V_149 &&
! V_205 -> V_95 )
V_205 ++ ;
}
while ( V_213 < V_211 ) {
T_1 V_149 = V_153 [ V_213 ] . V_149 ;
T_1 V_95 = V_153 [ V_213 ] . V_95 ;
bool V_158 = ( V_212 && ( V_213 == V_215 ) ) ;
struct V_200 * V_201 = NULL ;
if ( V_212 && ( ( V_213 + 1 ) == V_215 ) )
V_201 = & V_153 [ V_213 + 1 ] ;
while ( F_111 ( V_33 , V_205 ) &&
! F_48 ( V_149 , V_205 -> V_95 ) )
V_205 ++ ;
if ( F_111 ( V_33 , V_205 ) && ! V_158 &&
F_55 ( V_95 , V_205 -> V_149 ) ) {
if ( F_48 ( V_149 , V_205 -> V_149 ) ) {
V_4 = F_109 ( V_4 , V_2 , V_171 ,
V_149 ) ;
V_4 = F_107 ( V_4 , V_2 , V_201 ,
V_171 ,
V_149 ,
V_205 -> V_149 ,
V_158 ) ;
}
if ( ! F_55 ( V_95 , V_205 -> V_95 ) )
goto V_220;
V_4 = F_110 ( V_4 , V_2 , V_201 ,
V_171 ,
V_205 -> V_95 ) ;
if ( F_86 ( V_33 ) == V_205 -> V_95 ) {
V_4 = F_91 ( V_2 ) ;
if ( ! V_4 )
break;
V_171 -> V_175 = V_33 -> V_136 ;
V_205 ++ ;
goto V_221;
}
V_4 = F_109 ( V_4 , V_2 , V_171 , V_205 -> V_95 ) ;
V_205 ++ ;
continue;
}
if ( ! F_48 ( V_149 , F_86 ( V_33 ) ) ) {
V_4 = F_91 ( V_2 ) ;
if ( ! V_4 )
break;
V_171 -> V_175 = V_33 -> V_136 ;
}
V_4 = F_109 ( V_4 , V_2 , V_171 , V_149 ) ;
V_221:
V_4 = F_107 ( V_4 , V_2 , V_201 , V_171 ,
V_149 , V_95 , V_158 ) ;
V_220:
V_213 ++ ;
}
for ( V_213 = 0 ; V_213 < F_112 ( V_33 -> V_206 ) - V_211 ; V_213 ++ ) {
V_33 -> V_206 [ V_213 ] . V_149 = 0 ;
V_33 -> V_206 [ V_213 ] . V_95 = 0 ;
}
for ( V_214 = 0 ; V_214 < V_211 ; V_214 ++ )
V_33 -> V_206 [ V_213 ++ ] = V_153 [ V_214 ] ;
if ( ( V_171 -> V_141 < V_33 -> V_136 ) &&
( ( F_2 ( V_2 ) -> V_135 != V_222 ) || V_33 -> V_138 ) )
F_68 ( V_2 , V_33 -> V_136 - V_171 -> V_141 , 0 ) ;
F_117 ( V_33 ) ;
V_198:
#if V_134 > 0
F_114 ( ( int ) V_33 -> V_137 < 0 ) ;
F_114 ( ( int ) V_33 -> V_143 < 0 ) ;
F_114 ( ( int ) V_33 -> V_178 < 0 ) ;
F_114 ( ( int ) F_118 ( V_33 ) < 0 ) ;
#endif
return V_171 -> V_180 ;
}
static bool F_119 ( struct V_32 * V_33 )
{
T_1 V_223 ;
V_223 = F_39 ( V_33 -> V_143 , 1U ) ;
V_223 = F_9 ( V_223 , V_33 -> V_116 ) ;
if ( ( V_33 -> V_137 + V_223 ) > V_33 -> V_116 ) {
V_33 -> V_137 = V_33 -> V_116 - V_223 ;
return true ;
}
return false ;
}
static void F_120 ( struct V_1 * V_2 , const int V_224 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_119 ( V_33 ) )
F_68 ( V_2 , V_33 -> V_116 + V_224 , 0 ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
V_33 -> V_137 ++ ;
F_120 ( V_2 , 0 ) ;
F_117 ( V_33 ) ;
}
static void F_122 ( struct V_1 * V_2 , int V_225 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_225 > 0 ) {
if ( V_225 - 1 >= V_33 -> V_137 )
V_33 -> V_137 = 0 ;
else
V_33 -> V_137 -= V_225 - 1 ;
}
F_120 ( V_2 , V_225 ) ;
F_117 ( V_33 ) ;
}
static inline void F_123 ( struct V_32 * V_33 )
{
V_33 -> V_137 = 0 ;
}
void F_124 ( struct V_32 * V_33 )
{
V_33 -> V_178 = 0 ;
V_33 -> V_143 = 0 ;
V_33 -> V_138 = 0 ;
V_33 -> V_139 = - 1 ;
V_33 -> V_136 = 0 ;
V_33 -> V_137 = 0 ;
}
static inline void F_125 ( struct V_32 * V_33 )
{
V_33 -> V_138 = V_33 -> V_108 ;
V_33 -> V_139 = V_33 -> V_178 ? : - 1 ;
}
void F_126 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
bool V_226 = V_6 -> V_135 < V_227 ;
bool V_228 ;
if ( V_6 -> V_135 <= V_229 ||
! F_55 ( V_33 -> V_179 , V_33 -> V_108 ) ||
( V_6 -> V_135 == V_222 && ! V_6 -> V_230 ) ) {
V_33 -> V_231 = F_127 ( V_2 ) ;
V_33 -> V_113 = V_6 -> V_232 -> V_233 ( V_2 ) ;
F_20 ( V_2 , V_234 ) ;
F_125 ( V_33 ) ;
}
V_33 -> V_58 = 1 ;
V_33 -> V_235 = 0 ;
V_33 -> V_83 = V_79 ;
V_33 -> V_178 = 0 ;
V_33 -> V_143 = 0 ;
if ( F_69 ( V_33 ) )
F_123 ( V_33 ) ;
V_4 = F_102 ( V_2 ) ;
V_228 = V_4 && ( F_18 ( V_4 ) -> V_145 & V_147 ) ;
if ( V_228 ) {
F_70 ( F_71 ( V_2 ) , V_236 ) ;
V_33 -> V_137 = 0 ;
V_33 -> V_136 = 0 ;
}
F_128 ( V_33 ) ;
F_129 (skb, sk) {
if ( V_4 == F_106 ( V_2 ) )
break;
F_18 ( V_4 ) -> V_145 &= ( ~ V_196 ) | V_147 ;
if ( ! ( F_18 ( V_4 ) -> V_145 & V_147 ) || V_228 ) {
F_18 ( V_4 ) -> V_145 &= ~ V_147 ;
F_18 ( V_4 ) -> V_145 |= V_146 ;
V_33 -> V_143 += F_76 ( V_4 ) ;
V_33 -> V_144 = F_18 ( V_4 ) -> V_95 ;
}
}
F_117 ( V_33 ) ;
if ( V_6 -> V_135 <= V_229 &&
V_33 -> V_137 >= V_237 )
V_33 -> V_59 = F_45 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_130 ( V_2 , V_222 ) ;
V_33 -> V_179 = V_33 -> V_110 ;
F_14 ( V_33 ) ;
V_33 -> V_238 = V_239 &&
( V_226 || V_6 -> V_230 ) &&
! F_2 ( V_2 ) -> V_240 . V_241 ;
}
static bool F_131 ( struct V_1 * V_2 , int V_180 )
{
if ( V_180 & V_242 ) {
struct V_32 * V_33 = F_7 ( V_2 ) ;
unsigned long V_243 = F_39 ( F_132 ( V_33 -> V_104 >> 4 ) ,
F_133 ( 10 ) ) ;
F_134 ( V_2 , V_244 ,
V_243 , V_245 ) ;
return true ;
}
return false ;
}
static inline int F_135 ( const struct V_32 * V_33 )
{
return F_69 ( V_33 ) ? V_33 -> V_137 + 1 : V_33 -> V_136 ;
}
static inline int F_136 ( const struct V_32 * V_33 )
{
return F_66 ( V_33 ) ? V_33 -> V_136 : V_33 -> V_137 + 1 ;
}
static bool F_137 ( struct V_1 * V_2 , int V_180 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
unsigned long V_243 ;
if ( V_246 < 2 || V_246 > 3 ||
( V_180 & V_247 ) || ! V_33 -> V_104 )
return false ;
V_243 = F_39 ( F_132 ( V_33 -> V_104 >> 5 ) ,
F_133 ( 2 ) ) ;
if ( ! F_138 ( F_2 ( V_2 ) -> V_248 , ( V_249 + V_243 ) ) )
return false ;
F_134 ( V_2 , V_250 , V_243 ,
V_245 ) ;
return true ;
}
static bool F_139 ( struct V_1 * V_2 , int V_180 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_3 V_116 ;
if ( V_33 -> V_143 )
return true ;
if ( F_136 ( V_33 ) > V_33 -> V_59 )
return true ;
V_116 = V_33 -> V_116 ;
if ( V_116 <= V_33 -> V_59 &&
V_33 -> V_137 >= F_26 ( T_3 , V_116 / 2 , V_237 ) &&
! F_140 ( V_2 ) ) {
return true ;
}
if ( ( V_33 -> V_251 || V_252 ) &&
F_141 ( V_33 ) && F_136 ( V_33 ) > 1 &&
F_142 ( V_33 ) && ! F_106 ( V_2 ) )
return true ;
if ( V_33 -> V_253 && ! V_33 -> V_178 && V_33 -> V_137 &&
( V_33 -> V_116 >= ( V_33 -> V_137 + 1 ) && V_33 -> V_116 < 4 ) &&
! F_140 ( V_2 ) )
return ! F_137 ( V_2 , V_180 ) ;
return false ;
}
static void F_143 ( struct V_1 * V_2 , int V_254 , int V_255 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_256 , V_257 ;
int V_164 ;
unsigned int V_69 ;
const T_1 V_258 = F_142 ( V_33 ) ? V_33 -> V_110 : V_33 -> V_179 ;
F_114 ( V_254 > V_33 -> V_116 ) ;
if ( V_33 -> V_122 ) {
V_4 = V_33 -> V_122 ;
V_256 = V_33 -> V_186 ;
if ( V_255 && V_4 != F_102 ( V_2 ) )
return;
} else {
V_4 = F_102 ( V_2 ) ;
V_256 = 0 ;
}
F_108 (skb, sk) {
if ( V_4 == F_106 ( V_2 ) )
break;
V_33 -> V_122 = V_4 ;
V_33 -> V_186 = V_256 ;
if ( F_55 ( F_18 ( V_4 ) -> V_95 , V_258 ) )
break;
V_257 = V_256 ;
if ( F_66 ( V_33 ) || F_69 ( V_33 ) ||
( F_18 ( V_4 ) -> V_145 & V_147 ) )
V_256 += F_76 ( V_4 ) ;
if ( V_256 > V_254 ) {
if ( ( F_142 ( V_33 ) && ! F_66 ( V_33 ) ) ||
( F_18 ( V_4 ) -> V_145 & V_147 ) ||
( V_257 >= V_254 ) )
break;
V_69 = F_82 ( V_4 ) ;
V_164 = F_83 ( V_2 , V_4 , ( V_254 - V_257 ) * V_69 ,
V_69 , V_169 ) ;
if ( V_164 < 0 )
break;
V_256 = V_254 ;
}
F_75 ( V_33 , V_4 ) ;
if ( V_255 )
break;
}
F_117 ( V_33 ) ;
}
static void F_144 ( struct V_1 * V_2 , int V_259 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_69 ( V_33 ) ) {
F_143 ( V_2 , 1 , 1 ) ;
} else if ( F_66 ( V_33 ) ) {
int V_260 = V_33 -> V_136 - V_33 -> V_59 ;
if ( V_260 <= 0 )
V_260 = 1 ;
F_143 ( V_2 , V_260 , 0 ) ;
} else {
int V_261 = V_33 -> V_137 - V_33 -> V_59 ;
if ( V_261 >= 0 )
F_143 ( V_2 , V_261 , 0 ) ;
else if ( V_259 )
F_143 ( V_2 , 1 , 1 ) ;
}
}
static inline void F_145 ( struct V_32 * V_33 )
{
V_33 -> V_58 = F_9 ( V_33 -> V_58 ,
F_118 ( V_33 ) + F_146 ( V_33 ) ) ;
V_33 -> V_83 = V_79 ;
}
static bool F_147 ( const struct V_32 * V_33 , T_1 V_262 )
{
return V_33 -> V_52 . V_263 && V_33 -> V_52 . V_94 &&
F_48 ( V_33 -> V_52 . V_94 , V_262 ) ;
}
static bool F_148 ( const struct V_32 * V_33 ,
const struct V_3 * V_4 )
{
return ( F_18 ( V_4 ) -> V_145 & V_176 ) &&
F_147 ( V_33 , F_149 ( V_4 ) ) ;
}
static inline bool F_150 ( const struct V_32 * V_33 )
{
return ! V_33 -> V_264 ||
F_147 ( V_33 , V_33 -> V_264 ) ;
}
static bool F_151 ( const struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_33 -> V_178 )
return true ;
V_4 = F_102 ( V_2 ) ;
if ( F_101 ( V_4 && F_18 ( V_4 ) -> V_145 & V_190 ) )
return true ;
return false ;
}
static void F_152 ( struct V_1 * V_2 , const char * V_265 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_266 * V_267 = F_153 ( V_2 ) ;
if ( V_2 -> V_268 == V_269 ) {
F_72 ( L_2 ,
V_265 ,
& V_267 -> V_270 , F_154 ( V_267 -> V_271 ) ,
V_33 -> V_58 , F_155 ( V_33 ) ,
V_33 -> V_113 , V_33 -> V_231 ,
V_33 -> V_116 ) ;
}
#if F_156 ( V_272 )
else if ( V_2 -> V_268 == V_273 ) {
struct V_274 * V_275 = F_157 ( V_2 ) ;
F_72 ( L_3 ,
V_265 ,
& V_275 -> V_276 , F_154 ( V_267 -> V_271 ) ,
V_33 -> V_58 , F_155 ( V_33 ) ,
V_33 -> V_113 , V_33 -> V_231 ,
V_33 -> V_116 ) ;
}
#endif
}
static void F_158 ( struct V_1 * V_2 , bool V_277 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_277 ) {
struct V_3 * V_4 ;
F_129 (skb, sk) {
if ( V_4 == F_106 ( V_2 ) )
break;
F_18 ( V_4 ) -> V_145 &= ~ V_146 ;
}
V_33 -> V_143 = 0 ;
F_128 ( V_33 ) ;
}
if ( V_33 -> V_231 ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_232 -> V_278 )
V_33 -> V_58 = V_6 -> V_232 -> V_278 ( V_2 ) ;
else
V_33 -> V_58 = F_39 ( V_33 -> V_58 , V_33 -> V_113 << 1 ) ;
if ( V_33 -> V_231 > V_33 -> V_113 ) {
V_33 -> V_113 = V_33 -> V_231 ;
F_16 ( V_33 ) ;
}
} else {
V_33 -> V_58 = F_39 ( V_33 -> V_58 , V_33 -> V_113 ) ;
}
V_33 -> V_83 = V_79 ;
V_33 -> V_138 = 0 ;
}
static inline bool F_159 ( const struct V_32 * V_33 )
{
return V_33 -> V_138 && ( ! V_33 -> V_139 || F_150 ( V_33 ) ) ;
}
static bool F_160 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_159 ( V_33 ) ) {
int V_128 ;
F_152 ( V_2 , F_2 ( V_2 ) -> V_135 == V_222 ? L_4 : L_5 ) ;
F_158 ( V_2 , false ) ;
if ( F_2 ( V_2 ) -> V_135 == V_222 )
V_128 = V_279 ;
else
V_128 = V_280 ;
F_70 ( F_71 ( V_2 ) , V_128 ) ;
}
if ( V_33 -> V_108 == V_33 -> V_179 && F_69 ( V_33 ) ) {
F_145 ( V_33 ) ;
if ( ! F_151 ( V_2 ) )
V_33 -> V_264 = 0 ;
return true ;
}
F_130 ( V_2 , V_281 ) ;
return false ;
}
static bool F_161 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_33 -> V_138 && ! V_33 -> V_139 ) {
F_152 ( V_2 , L_6 ) ;
F_158 ( V_2 , false ) ;
F_70 ( F_71 ( V_2 ) , V_282 ) ;
return true ;
}
return false ;
}
static bool F_162 ( struct V_1 * V_2 , bool V_283 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_283 || F_159 ( V_33 ) ) {
F_158 ( V_2 , true ) ;
F_152 ( V_2 , L_7 ) ;
F_70 ( F_71 ( V_2 ) , V_279 ) ;
if ( V_283 )
F_70 ( F_71 ( V_2 ) ,
V_284 ) ;
F_2 ( V_2 ) -> V_230 = 0 ;
if ( V_283 || F_142 ( V_33 ) )
F_130 ( V_2 , V_281 ) ;
return true ;
}
return false ;
}
static void F_163 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
V_33 -> V_179 = V_33 -> V_110 ;
V_33 -> V_285 = 0 ;
V_33 -> V_235 = 0 ;
V_33 -> V_286 = V_33 -> V_58 ;
V_33 -> V_287 = 0 ;
V_33 -> V_288 = 0 ;
V_33 -> V_113 = F_2 ( V_2 ) -> V_232 -> V_233 ( V_2 ) ;
F_14 ( V_33 ) ;
}
static void F_164 ( struct V_1 * V_2 , const int V_289 ,
int V_259 , int V_180 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_290 = 0 ;
int V_291 = V_33 -> V_113 - F_118 ( V_33 ) ;
int V_292 = V_289 -
( V_33 -> V_116 - V_33 -> V_137 ) ;
if ( V_292 <= 0 || F_165 ( ! V_33 -> V_286 ) )
return;
V_33 -> V_287 += V_292 ;
if ( V_291 < 0 ) {
T_2 V_293 = ( T_2 ) V_33 -> V_113 * V_33 -> V_287 +
V_33 -> V_286 - 1 ;
V_290 = F_166 ( V_293 , V_33 -> V_286 ) - V_33 -> V_288 ;
} else if ( ( V_180 & V_294 ) &&
! ( V_180 & V_295 ) ) {
V_290 = F_45 ( int , V_291 ,
F_26 ( int , V_33 -> V_287 - V_33 -> V_288 ,
V_292 ) + 1 ) ;
} else {
V_290 = F_9 ( V_291 , V_292 ) ;
}
V_290 = F_39 ( V_290 , ( V_259 ? 1 : 0 ) ) ;
V_33 -> V_58 = F_118 ( V_33 ) + V_290 ;
}
static inline void F_167 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_135 == V_296 ||
( V_33 -> V_138 && V_33 -> V_113 < V_297 ) ) {
V_33 -> V_58 = V_33 -> V_113 ;
V_33 -> V_83 = V_79 ;
}
F_20 ( V_2 , V_298 ) ;
}
void F_168 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
V_33 -> V_231 = 0 ;
if ( F_2 ( V_2 ) -> V_135 < V_296 ) {
V_33 -> V_138 = 0 ;
F_163 ( V_2 ) ;
F_130 ( V_2 , V_296 ) ;
}
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_171 = V_281 ;
if ( F_155 ( V_33 ) || F_151 ( V_2 ) )
V_171 = V_229 ;
if ( F_2 ( V_2 ) -> V_135 != V_171 ) {
F_130 ( V_2 , V_171 ) ;
V_33 -> V_179 = V_33 -> V_110 ;
}
}
static void F_170 ( struct V_1 * V_2 , int V_180 , const int V_289 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
F_117 ( V_33 ) ;
if ( ! F_151 ( V_2 ) )
V_33 -> V_264 = 0 ;
if ( V_180 & V_247 )
F_168 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_135 != V_296 ) {
F_169 ( V_2 ) ;
} else {
F_164 ( V_2 , V_289 , 0 , V_180 ) ;
}
}
static void F_171 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_240 . V_299 = V_6 -> V_240 . V_241 - 1 ;
V_6 -> V_240 . V_241 = 0 ;
F_70 ( F_71 ( V_2 ) , V_300 ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_33 -> V_231 = F_127 ( V_2 ) ;
V_33 -> V_58 = V_33 -> V_58 *
F_173 ( V_2 , V_33 -> V_54 ) /
V_6 -> V_240 . V_241 ;
V_33 -> V_235 = 0 ;
V_33 -> V_83 = V_79 ;
V_33 -> V_113 = F_127 ( V_2 ) ;
V_6 -> V_240 . V_301 = V_6 -> V_240 . V_241 ;
V_6 -> V_240 . V_241 = 0 ;
F_174 ( V_2 , V_6 -> V_302 ) ;
F_70 ( F_71 ( V_2 ) , V_303 ) ;
}
void F_175 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_69 = F_176 ( V_2 ) ;
T_1 V_304 = V_33 -> V_143 ;
F_129 (skb, sk) {
if ( V_4 == F_106 ( V_2 ) )
break;
if ( F_95 ( V_4 ) > V_69 &&
! ( F_18 ( V_4 ) -> V_145 & V_147 ) ) {
if ( F_18 ( V_4 ) -> V_145 & V_177 ) {
F_18 ( V_4 ) -> V_145 &= ~ V_177 ;
V_33 -> V_178 -= F_76 ( V_4 ) ;
}
F_77 ( V_33 , V_4 ) ;
}
}
F_177 ( V_33 ) ;
if ( V_304 == V_33 -> V_143 )
return;
if ( F_69 ( V_33 ) )
F_119 ( V_33 ) ;
F_117 ( V_33 ) ;
if ( V_6 -> V_135 != V_222 ) {
V_33 -> V_179 = V_33 -> V_110 ;
V_33 -> V_113 = F_127 ( V_2 ) ;
V_33 -> V_231 = 0 ;
V_33 -> V_138 = 0 ;
F_130 ( V_2 , V_222 ) ;
}
F_178 ( V_2 ) ;
}
static void F_179 ( struct V_1 * V_2 , bool V_305 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_128 ;
if ( F_69 ( V_33 ) )
V_128 = V_306 ;
else
V_128 = V_307 ;
F_70 ( F_71 ( V_2 ) , V_128 ) ;
V_33 -> V_231 = 0 ;
F_125 ( V_33 ) ;
if ( ! F_180 ( V_2 ) ) {
if ( ! V_305 )
V_33 -> V_231 = F_127 ( V_2 ) ;
F_163 ( V_2 ) ;
}
F_130 ( V_2 , V_227 ) ;
}
static void F_181 ( struct V_1 * V_2 , int V_180 , bool V_308 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
bool V_309 = ! F_48 ( V_33 -> V_108 , V_33 -> V_179 ) ;
if ( ( V_180 & V_310 ) &&
F_162 ( V_2 , false ) )
return;
if ( V_33 -> V_238 ) {
if ( ( V_180 & V_181 ) &&
F_162 ( V_2 , true ) )
return;
if ( F_55 ( V_33 -> V_110 , V_33 -> V_179 ) ) {
if ( V_180 & V_185 || V_308 )
V_33 -> V_238 = 0 ;
} else if ( V_180 & V_310 && ! V_309 ) {
V_33 -> V_179 = V_33 -> V_110 ;
F_182 ( V_2 , F_176 ( V_2 ) ,
V_311 ) ;
if ( F_55 ( V_33 -> V_110 , V_33 -> V_179 ) )
return;
V_33 -> V_238 = 0 ;
}
}
if ( V_309 ) {
F_160 ( V_2 ) ;
return;
}
if ( F_69 ( V_33 ) ) {
if ( F_55 ( V_33 -> V_110 , V_33 -> V_179 ) && V_308 )
F_121 ( V_2 ) ;
else if ( V_180 & V_310 )
F_123 ( V_33 ) ;
}
F_178 ( V_2 ) ;
}
static bool F_183 ( struct V_1 * V_2 , const int V_225 ,
const int V_289 , int V_180 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_33 -> V_138 && F_150 ( V_33 ) ) {
F_68 ( V_2 , F_135 ( V_33 ) + V_225 , 1 ) ;
if ( V_33 -> V_178 ) {
F_164 ( V_2 , V_289 , 0 , V_180 ) ;
return true ;
}
if ( ! F_151 ( V_2 ) )
V_33 -> V_264 = 0 ;
F_152 ( V_2 , L_8 ) ;
F_158 ( V_2 , true ) ;
F_70 ( F_71 ( V_2 ) , V_312 ) ;
F_169 ( V_2 ) ;
return true ;
}
return false ;
}
static void F_184 ( struct V_1 * V_2 , const int V_225 ,
const int V_289 ,
bool V_308 , int V_180 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
bool V_313 = V_308 || ( ( V_180 & V_185 ) &&
( F_135 ( V_33 ) > V_33 -> V_59 ) ) ;
int V_259 = 0 ;
if ( F_114 ( ! V_33 -> V_116 && V_33 -> V_137 ) )
V_33 -> V_137 = 0 ;
if ( F_114 ( ! V_33 -> V_137 && V_33 -> V_136 ) )
V_33 -> V_136 = 0 ;
if ( V_180 & V_247 )
V_33 -> V_231 = 0 ;
if ( F_131 ( V_2 , V_180 ) )
return;
F_117 ( V_33 ) ;
if ( V_6 -> V_135 == V_281 ) {
F_114 ( V_33 -> V_178 != 0 ) ;
V_33 -> V_264 = 0 ;
} else if ( ! F_48 ( V_33 -> V_108 , V_33 -> V_179 ) ) {
switch ( V_6 -> V_135 ) {
case V_296 :
if ( V_33 -> V_108 != V_33 -> V_179 ) {
F_167 ( V_2 ) ;
F_130 ( V_2 , V_281 ) ;
}
break;
case V_227 :
if ( F_69 ( V_33 ) )
F_123 ( V_33 ) ;
if ( F_160 ( V_2 ) )
return;
F_167 ( V_2 ) ;
break;
}
}
if ( V_314 & V_315 &&
F_185 ( V_2 ) )
V_180 |= V_295 ;
switch ( V_6 -> V_135 ) {
case V_227 :
if ( ! ( V_180 & V_310 ) ) {
if ( F_69 ( V_33 ) && V_308 )
F_121 ( V_2 ) ;
} else {
if ( F_183 ( V_2 , V_225 , V_289 , V_180 ) )
return;
V_313 = F_69 ( V_33 ) ||
F_135 ( V_33 ) > V_33 -> V_59 ;
}
if ( F_161 ( V_2 ) ) {
F_169 ( V_2 ) ;
return;
}
break;
case V_222 :
F_181 ( V_2 , V_180 , V_308 ) ;
if ( V_6 -> V_135 != V_281 &&
! ( V_180 & V_295 ) )
return;
default:
if ( F_69 ( V_33 ) ) {
if ( V_180 & V_310 )
F_123 ( V_33 ) ;
if ( V_308 )
F_121 ( V_2 ) ;
}
if ( V_6 -> V_135 <= V_229 )
F_161 ( V_2 ) ;
if ( ! F_139 ( V_2 , V_180 ) ) {
F_170 ( V_2 , V_180 , V_289 ) ;
return;
}
if ( V_6 -> V_135 < V_296 &&
V_6 -> V_240 . V_241 &&
V_33 -> V_108 == V_33 -> V_316 . V_317 ) {
F_171 ( V_2 ) ;
V_33 -> V_58 ++ ;
F_175 ( V_2 ) ;
return;
}
F_179 ( V_2 , ( V_180 & V_247 ) ) ;
V_259 = 1 ;
}
if ( V_313 )
F_144 ( V_2 , V_259 ) ;
F_164 ( V_2 , V_289 , V_259 , V_180 ) ;
F_178 ( V_2 ) ;
}
static void F_186 ( struct V_1 * V_2 , T_1 V_318 )
{
const T_1 V_99 = V_79 , V_319 = V_320 * V_321 ;
struct V_322 * V_91 = F_7 ( V_2 ) -> V_323 ;
struct V_322 V_324 = { . V_90 = ( V_318 ? : 1 ) , . V_127 = V_99 } ;
T_1 V_325 ;
if ( F_101 ( V_324 . V_90 <= V_91 [ 0 ] . V_90 ) )
V_91 [ 0 ] = V_91 [ 1 ] = V_91 [ 2 ] = V_324 ;
else if ( V_324 . V_90 <= V_91 [ 1 ] . V_90 )
V_91 [ 1 ] = V_91 [ 2 ] = V_324 ;
else if ( V_324 . V_90 <= V_91 [ 2 ] . V_90 )
V_91 [ 2 ] = V_324 ;
V_325 = V_99 - V_91 [ 0 ] . V_127 ;
if ( F_101 ( V_325 > V_319 ) ) {
V_91 [ 0 ] = V_91 [ 1 ] ;
V_91 [ 1 ] = V_91 [ 2 ] ;
V_91 [ 2 ] = V_324 ;
if ( V_99 - V_91 [ 0 ] . V_127 > V_319 ) {
V_91 [ 0 ] = V_91 [ 1 ] ;
V_91 [ 1 ] = V_324 ;
if ( V_99 - V_91 [ 0 ] . V_127 > V_319 )
V_91 [ 0 ] = V_324 ;
}
} else if ( V_91 [ 1 ] . V_127 == V_91 [ 0 ] . V_127 && V_325 > V_319 / 4 ) {
V_91 [ 2 ] = V_91 [ 1 ] = V_324 ;
} else if ( V_91 [ 2 ] . V_127 == V_91 [ 1 ] . V_127 && V_325 > V_319 / 2 ) {
V_91 [ 2 ] = V_324 ;
}
}
static inline bool F_187 ( struct V_1 * V_2 , const int V_180 ,
long V_326 , long V_327 ,
long V_328 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_326 < 0 )
V_326 = V_327 ;
if ( V_326 < 0 && V_33 -> V_52 . V_263 && V_33 -> V_52 . V_94 &&
V_180 & V_329 )
V_326 = V_328 = F_188 ( V_79 -
V_33 -> V_52 . V_94 ) ;
if ( V_326 < 0 )
return false ;
F_186 ( V_2 , V_328 ) ;
F_54 ( V_2 , V_326 ) ;
F_61 ( V_2 ) ;
F_2 ( V_2 ) -> V_330 = 0 ;
return true ;
}
void F_189 ( struct V_1 * V_2 , struct V_331 * V_332 )
{
long V_318 = - 1L ;
if ( V_332 && ! V_332 -> V_333 && F_190 ( V_332 ) -> V_334 . V_183 ) {
struct V_173 V_99 ;
F_191 ( & V_99 ) ;
V_318 = F_192 ( & V_99 , & F_190 ( V_332 ) -> V_334 ) ;
}
F_187 ( V_2 , V_335 , V_318 , - 1L , V_318 ) ;
}
static void F_193 ( struct V_1 * V_2 , T_1 V_336 , T_1 V_225 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_232 -> V_337 ( V_2 , V_336 , V_225 ) ;
F_7 ( V_2 ) -> V_83 = V_79 ;
}
void F_194 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_33 -> V_338 )
return;
if ( ! V_33 -> V_116 ) {
F_195 ( V_2 , V_244 ) ;
} else {
T_1 V_339 = F_2 ( V_2 ) -> V_101 ;
if ( V_6 -> V_340 == V_250 ||
V_6 -> V_340 == V_341 ) {
struct V_3 * V_4 = F_102 ( V_2 ) ;
const T_1 V_342 =
F_149 ( V_4 ) + V_339 ;
T_5 V_291 = ( T_5 ) ( V_342 - V_79 ) ;
if ( V_291 > 0 )
V_339 = V_291 ;
}
F_134 ( V_2 , V_244 , V_339 ,
V_245 ) ;
}
}
void F_196 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
F_194 ( V_2 ) ;
if ( ! V_33 -> V_253 )
return;
F_179 ( V_2 , false ) ;
F_144 ( V_2 , 1 ) ;
F_178 ( V_2 ) ;
}
static T_1 F_197 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_1 V_343 ;
F_89 ( ! F_55 ( F_18 ( V_4 ) -> V_95 , V_33 -> V_108 ) ) ;
V_343 = F_76 ( V_4 ) ;
if ( F_198 ( V_2 , V_4 , V_33 -> V_108 - F_18 ( V_4 ) -> V_80 ) )
return 0 ;
V_343 -= F_76 ( V_4 ) ;
if ( V_343 ) {
F_89 ( F_76 ( V_4 ) == 0 ) ;
F_89 ( ! F_48 ( F_18 ( V_4 ) -> V_80 , F_18 ( V_4 ) -> V_95 ) ) ;
}
return V_343 ;
}
static void F_199 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_155 )
{
const struct V_56 * V_344 ;
if ( F_58 ( ! ( V_2 -> V_345 & V_346 ) ) )
return;
V_344 = F_3 ( V_4 ) ;
if ( ( V_344 -> V_347 & V_348 ) &&
F_200 ( V_344 -> V_349 , V_155 , F_7 ( V_2 ) -> V_108 - 1 ) )
F_201 ( V_4 , NULL , V_2 , V_350 ) ;
}
static int F_202 ( struct V_1 * V_2 , int V_351 ,
T_1 V_155 ,
struct V_170 * V_352 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_173 V_353 , V_354 , V_99 ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_1 V_355 = V_33 -> V_137 ;
T_1 V_141 = V_33 -> V_116 ;
bool V_356 = true ;
long V_327 = - 1L ;
long V_326 = - 1L ;
long V_328 = - 1L ;
struct V_3 * V_4 ;
T_1 V_357 = 0 ;
bool V_358 ;
int V_180 = 0 ;
V_353 . V_183 = 0 ;
while ( ( V_4 = F_102 ( V_2 ) ) && V_4 != F_106 ( V_2 ) ) {
struct V_359 * V_360 = F_18 ( V_4 ) ;
T_4 V_145 = V_360 -> V_145 ;
T_1 V_361 ;
F_199 ( V_2 , V_4 , V_155 ) ;
if ( F_55 ( V_360 -> V_95 , V_33 -> V_108 ) ) {
if ( F_76 ( V_4 ) == 1 ||
! F_55 ( V_33 -> V_108 , V_360 -> V_80 ) )
break;
V_361 = F_197 ( V_2 , V_4 ) ;
if ( ! V_361 )
break;
V_356 = false ;
} else {
F_203 ( V_4 -> V_362 ) ;
V_361 = F_76 ( V_4 ) ;
}
if ( F_101 ( V_145 & V_176 ) ) {
if ( V_145 & V_177 )
V_33 -> V_178 -= V_361 ;
V_180 |= V_294 ;
} else if ( ! ( V_145 & V_147 ) ) {
V_354 = V_4 -> V_173 ;
F_165 ( V_354 . V_183 == 0 ) ;
if ( ! V_353 . V_183 )
V_353 = V_354 ;
V_141 = F_9 ( V_357 , V_141 ) ;
if ( ! F_55 ( V_360 -> V_95 , V_33 -> V_179 ) )
V_180 |= V_181 ;
}
if ( V_145 & V_147 )
V_33 -> V_137 -= V_361 ;
else if ( F_142 ( V_33 ) && ! F_148 ( V_33 , V_4 ) )
F_85 ( V_33 , & V_4 -> V_173 , V_145 ) ;
if ( V_145 & V_146 )
V_33 -> V_143 -= V_361 ;
V_33 -> V_116 -= V_361 ;
V_357 += V_361 ;
if ( F_58 ( ! ( V_360 -> V_192 & V_363 ) ) ) {
V_180 |= V_364 ;
} else {
V_180 |= V_335 ;
V_33 -> V_264 = 0 ;
}
if ( ! V_356 )
break;
F_93 ( V_4 , V_2 ) ;
F_94 ( V_2 , V_4 ) ;
if ( F_101 ( V_4 == V_33 -> V_142 ) )
V_33 -> V_142 = NULL ;
if ( F_101 ( V_4 == V_33 -> V_122 ) )
V_33 -> V_122 = NULL ;
}
if ( F_58 ( F_200 ( V_33 -> V_365 , V_155 , V_33 -> V_108 ) ) )
V_33 -> V_365 = V_33 -> V_108 ;
if ( V_4 && ( F_18 ( V_4 ) -> V_145 & V_147 ) )
V_180 |= V_242 ;
F_191 ( & V_99 ) ;
if ( F_58 ( V_353 . V_183 ) && ! ( V_180 & V_294 ) ) {
V_326 = F_192 ( & V_99 , & V_353 ) ;
V_328 = F_192 ( & V_99 , & V_354 ) ;
}
if ( V_352 -> V_182 . V_183 ) {
V_327 = F_192 ( & V_99 , & V_352 -> V_182 ) ;
V_328 = F_192 ( & V_99 , & V_352 -> V_184 ) ;
}
V_358 = F_187 ( V_2 , V_180 , V_326 , V_327 ,
V_328 ) ;
if ( V_180 & V_329 ) {
F_194 ( V_2 ) ;
if ( F_101 ( V_6 -> V_240 . V_241 &&
! F_55 ( V_33 -> V_316 . V_366 , V_33 -> V_108 ) ) ) {
F_172 ( V_2 ) ;
}
if ( F_69 ( V_33 ) ) {
F_122 ( V_2 , V_357 ) ;
} else {
int V_291 ;
if ( V_141 < V_351 )
F_68 ( V_2 , V_33 -> V_136 - V_141 , 0 ) ;
V_291 = F_66 ( V_33 ) ? V_357 :
V_355 - V_33 -> V_137 ;
V_33 -> V_186 -= F_9 ( V_33 -> V_186 , V_291 ) ;
}
V_33 -> V_136 -= F_9 ( V_357 , V_33 -> V_136 ) ;
} else if ( V_4 && V_358 && V_327 >= 0 &&
V_327 > F_192 ( & V_99 , & V_4 -> V_173 ) ) {
F_194 ( V_2 ) ;
}
if ( V_6 -> V_232 -> V_357 )
V_6 -> V_232 -> V_357 ( V_2 , V_357 , V_328 ) ;
#if V_134 > 0
F_114 ( ( int ) V_33 -> V_137 < 0 ) ;
F_114 ( ( int ) V_33 -> V_143 < 0 ) ;
F_114 ( ( int ) V_33 -> V_178 < 0 ) ;
if ( ! V_33 -> V_116 && F_142 ( V_33 ) ) {
V_6 = F_2 ( V_2 ) ;
if ( V_33 -> V_143 ) {
F_72 ( L_9 ,
V_33 -> V_143 , V_6 -> V_135 ) ;
V_33 -> V_143 = 0 ;
}
if ( V_33 -> V_137 ) {
F_72 ( L_10 ,
V_33 -> V_137 , V_6 -> V_135 ) ;
V_33 -> V_137 = 0 ;
}
if ( V_33 -> V_178 ) {
F_72 ( L_11 ,
V_33 -> V_178 , V_6 -> V_135 ) ;
V_33 -> V_178 = 0 ;
}
}
#endif
return V_180 ;
}
static void F_204 ( struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_55 ( F_18 ( F_106 ( V_2 ) ) -> V_95 , F_205 ( V_33 ) ) ) {
V_6 -> V_330 = 0 ;
F_195 ( V_2 , V_367 ) ;
} else {
unsigned long V_262 = F_206 ( V_2 , V_245 ) ;
F_134 ( V_2 , V_367 ,
V_262 , V_245 ) ;
}
}
static inline bool F_207 ( const struct V_1 * V_2 , const int V_180 )
{
return ! ( V_180 & V_368 ) || ( V_180 & V_369 ) ||
F_2 ( V_2 ) -> V_135 != V_281 ;
}
static inline bool F_208 ( const struct V_1 * V_2 , const int V_180 )
{
if ( F_180 ( V_2 ) )
return false ;
if ( F_7 ( V_2 ) -> V_59 > V_237 )
return V_180 & V_370 ;
return V_180 & V_364 ;
}
static inline bool F_209 ( const struct V_32 * V_33 ,
const T_1 V_336 , const T_1 V_159 ,
const T_1 V_371 )
{
return F_55 ( V_336 , V_33 -> V_108 ) ||
F_55 ( V_159 , V_33 -> V_372 ) ||
( V_159 == V_33 -> V_372 && V_371 > V_33 -> V_373 ) ;
}
static void F_210 ( struct V_32 * V_33 , T_1 V_336 )
{
T_1 V_291 = V_336 - V_33 -> V_108 ;
F_211 ( & V_33 -> V_374 ) ;
V_33 -> V_375 += V_291 ;
F_212 ( & V_33 -> V_374 ) ;
V_33 -> V_108 = V_336 ;
}
static void F_213 ( struct V_32 * V_33 , T_1 V_80 )
{
T_1 V_291 = V_80 - V_33 -> V_93 ;
F_211 ( & V_33 -> V_374 ) ;
V_33 -> V_376 += V_291 ;
F_212 ( & V_33 -> V_374 ) ;
V_33 -> V_93 = V_80 ;
}
static int F_214 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_1 V_336 ,
T_1 V_159 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_180 = 0 ;
T_1 V_371 = F_154 ( F_6 ( V_4 ) -> V_63 ) ;
if ( F_58 ( ! F_6 ( V_4 ) -> V_48 ) )
V_371 <<= V_33 -> V_52 . V_377 ;
if ( F_209 ( V_33 , V_336 , V_159 , V_371 ) ) {
V_180 |= V_378 ;
F_215 ( V_33 , V_159 ) ;
if ( V_33 -> V_373 != V_371 ) {
V_33 -> V_373 = V_371 ;
V_33 -> V_379 = 0 ;
F_216 ( V_2 ) ;
if ( F_106 ( V_2 ) )
F_217 ( V_2 ) ;
if ( V_371 > V_33 -> V_150 ) {
V_33 -> V_150 = V_371 ;
F_174 ( V_2 , F_2 ( V_2 ) -> V_302 ) ;
}
}
}
F_210 ( V_33 , V_336 ) ;
return V_180 ;
}
bool F_218 ( struct V_380 * V_380 , const struct V_3 * V_4 ,
int V_128 , T_1 * V_381 )
{
if ( ( F_18 ( V_4 ) -> V_80 != F_18 ( V_4 ) -> V_95 ) &&
! F_6 ( V_4 ) -> V_48 )
goto V_382;
if ( * V_381 ) {
T_5 V_325 = ( T_5 ) ( V_79 - * V_381 ) ;
if ( 0 <= V_325 && V_325 < V_383 ) {
F_70 ( V_380 , V_128 ) ;
return true ;
}
}
* V_381 = V_79 ;
V_382:
return false ;
}
static void F_219 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
static T_1 V_384 ;
static unsigned int V_385 ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_1 V_99 ;
if ( F_218 ( F_71 ( V_2 ) , V_4 ,
V_386 ,
& V_33 -> V_381 ) )
return;
V_99 = V_249 / V_321 ;
if ( V_99 != V_384 ) {
V_384 = V_99 ;
V_385 = 0 ;
}
if ( ++ V_385 <= V_387 ) {
F_70 ( F_71 ( V_2 ) , V_388 ) ;
F_220 ( V_2 ) ;
}
}
static void F_221 ( struct V_32 * V_33 )
{
V_33 -> V_52 . V_389 = V_33 -> V_52 . V_390 ;
V_33 -> V_52 . V_391 = F_222 () ;
}
static void F_223 ( struct V_32 * V_33 , T_1 V_80 )
{
if ( V_33 -> V_52 . V_263 && ! F_55 ( V_80 , V_33 -> V_392 ) ) {
if ( F_224 ( & V_33 -> V_52 , 0 ) )
F_221 ( V_33 ) ;
}
}
static void F_225 ( struct V_1 * V_2 , T_1 V_336 , int V_180 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_48 ( V_336 , V_33 -> V_285 ) )
return;
if ( V_180 & V_216 ) {
V_33 -> V_285 = 0 ;
} else if ( F_55 ( V_336 , V_33 -> V_285 ) ) {
F_163 ( V_2 ) ;
F_130 ( V_2 , V_296 ) ;
F_167 ( V_2 ) ;
F_169 ( V_2 ) ;
F_70 ( F_71 ( V_2 ) ,
V_393 ) ;
} else if ( ! ( V_180 & ( V_310 |
V_368 | V_185 ) ) ) {
V_33 -> V_285 = 0 ;
}
}
static inline void F_226 ( struct V_1 * V_2 , T_1 V_394 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_232 -> V_395 )
V_6 -> V_232 -> V_395 ( V_2 , V_394 ) ;
}
static int F_227 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_180 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_170 V_396 ;
T_1 V_155 = V_33 -> V_108 ;
T_1 V_159 = F_18 ( V_4 ) -> V_80 ;
T_1 V_336 = F_18 ( V_4 ) -> V_159 ;
bool V_308 = false ;
T_1 V_351 ;
int V_397 = V_33 -> V_116 ;
const int V_289 = V_33 -> V_116 - V_33 -> V_137 ;
int V_225 = 0 ;
V_396 . V_182 . V_183 = 0 ;
F_203 ( V_2 -> V_398 . V_362 ) ;
if ( F_48 ( V_336 , V_155 ) ) {
if ( F_48 ( V_336 , V_155 - V_33 -> V_150 ) ) {
F_219 ( V_2 , V_4 ) ;
return - 1 ;
}
goto V_399;
}
if ( F_55 ( V_336 , V_33 -> V_110 ) )
goto V_400;
if ( V_6 -> V_340 == V_250 ||
V_6 -> V_340 == V_341 )
F_194 ( V_2 ) ;
if ( F_55 ( V_336 , V_155 ) ) {
V_180 |= V_310 ;
V_6 -> V_230 = 0 ;
}
V_351 = V_33 -> V_136 ;
if ( V_180 & V_401 )
F_223 ( V_33 , F_18 ( V_4 ) -> V_80 ) ;
if ( ! ( V_180 & V_402 ) && F_55 ( V_336 , V_155 ) ) {
F_215 ( V_33 , V_159 ) ;
F_210 ( V_33 , V_336 ) ;
V_180 |= V_378 ;
F_226 ( V_2 , V_403 ) ;
F_70 ( F_71 ( V_2 ) , V_404 ) ;
} else {
T_1 V_405 = V_406 ;
if ( V_159 != F_18 ( V_4 ) -> V_95 )
V_180 |= V_407 ;
else
F_70 ( F_71 ( V_2 ) , V_408 ) ;
V_180 |= F_214 ( V_2 , V_4 , V_336 , V_159 ) ;
if ( F_18 ( V_4 ) -> V_145 )
V_180 |= F_113 ( V_2 , V_4 , V_155 ,
& V_396 ) ;
if ( F_24 ( V_33 , F_6 ( V_4 ) ) ) {
V_180 |= V_247 ;
V_405 |= V_409 ;
}
if ( V_180 & V_378 )
V_405 |= V_403 ;
F_226 ( V_2 , V_405 ) ;
}
V_2 -> V_410 = 0 ;
V_6 -> V_411 = 0 ;
V_33 -> V_412 = V_79 ;
if ( ! V_397 )
goto V_413;
V_225 = V_33 -> V_116 ;
V_180 |= F_202 ( V_2 , V_351 , V_155 ,
& V_396 ) ;
V_225 -= V_33 -> V_116 ;
if ( F_207 ( V_2 , V_180 ) ) {
V_308 = ! ( V_180 & ( V_310 | V_368 ) ) ;
F_184 ( V_2 , V_225 , V_289 ,
V_308 , V_180 ) ;
}
if ( V_33 -> V_285 )
F_225 ( V_2 , V_336 , V_180 ) ;
if ( F_208 ( V_2 , V_180 ) )
F_193 ( V_2 , V_336 , V_225 ) ;
if ( ( V_180 & V_370 ) || ! ( V_180 & V_368 ) ) {
struct V_29 * V_30 = F_12 ( V_2 ) ;
if ( V_30 )
F_228 ( V_30 ) ;
}
if ( V_6 -> V_340 == V_244 )
F_229 ( V_2 ) ;
F_57 ( V_2 ) ;
return 1 ;
V_413:
if ( V_180 & V_216 )
F_184 ( V_2 , V_225 , V_289 ,
V_308 , V_180 ) ;
if ( F_106 ( V_2 ) )
F_204 ( V_2 ) ;
if ( V_33 -> V_285 )
F_225 ( V_2 , V_336 , V_180 ) ;
return 1 ;
V_400:
F_230 ( V_2 , L_12 , V_336 , V_33 -> V_108 , V_33 -> V_110 ) ;
return - 1 ;
V_399:
if ( F_18 ( V_4 ) -> V_145 ) {
V_180 |= F_113 ( V_2 , V_4 , V_155 ,
& V_396 ) ;
F_184 ( V_2 , V_225 , V_289 ,
V_308 , V_180 ) ;
}
F_230 ( V_2 , L_13 , V_336 , V_33 -> V_108 , V_33 -> V_110 ) ;
return 0 ;
}
static void F_231 ( int V_10 , const unsigned char * V_414 ,
bool V_48 , struct V_415 * V_416 ,
bool V_417 )
{
if ( ! V_416 || ! V_48 || V_10 < 0 || ( V_10 & 1 ) )
return;
if ( V_10 >= V_418 &&
V_10 <= V_419 )
memcpy ( V_416 -> V_420 , V_414 , V_10 ) ;
else if ( V_10 != 0 )
V_10 = - 1 ;
V_416 -> V_10 = V_10 ;
V_416 -> exp = V_417 ;
}
void F_232 ( const struct V_3 * V_4 ,
struct V_421 * V_422 , int V_423 ,
struct V_415 * V_416 )
{
const unsigned char * V_207 ;
const struct V_15 * V_46 = F_6 ( V_4 ) ;
int V_424 = ( V_46 -> V_425 * 4 ) - sizeof( struct V_15 ) ;
V_207 = ( const unsigned char * ) ( V_46 + 1 ) ;
V_422 -> V_263 = 0 ;
while ( V_424 > 0 ) {
int V_426 = * V_207 ++ ;
int V_427 ;
switch ( V_426 ) {
case V_428 :
return;
case V_429 :
V_424 -- ;
continue;
default:
V_427 = * V_207 ++ ;
if ( V_427 < 2 )
return;
if ( V_427 > V_424 )
return;
switch ( V_426 ) {
case V_430 :
if ( V_427 == V_431 && V_46 -> V_48 && ! V_423 ) {
T_6 V_432 = F_233 ( V_207 ) ;
if ( V_432 ) {
if ( V_422 -> V_433 &&
V_422 -> V_433 < V_432 )
V_432 = V_422 -> V_433 ;
V_422 -> V_53 = V_432 ;
}
}
break;
case V_434 :
if ( V_427 == V_435 && V_46 -> V_48 &&
! V_423 && V_436 ) {
T_7 V_377 = * ( T_7 * ) V_207 ;
V_422 -> V_437 = 1 ;
if ( V_377 > 14 ) {
F_234 ( L_14 ,
V_438 ,
V_377 ) ;
V_377 = 14 ;
}
V_422 -> V_377 = V_377 ;
}
break;
case V_439 :
if ( ( V_427 == V_440 ) &&
( ( V_423 && V_422 -> V_441 ) ||
( ! V_423 && V_442 ) ) ) {
V_422 -> V_263 = 1 ;
V_422 -> V_390 = F_80 ( V_207 ) ;
V_422 -> V_94 = F_80 ( V_207 + 4 ) ;
}
break;
case V_443 :
if ( V_427 == V_444 && V_46 -> V_48 &&
! V_423 && V_445 ) {
V_422 -> V_123 = V_446 ;
F_235 ( V_422 ) ;
}
break;
case V_447 :
if ( ( V_427 >= ( V_210 + V_448 ) ) &&
! ( ( V_427 - V_210 ) % V_448 ) &&
V_422 -> V_123 ) {
F_18 ( V_4 ) -> V_145 = ( V_207 - 2 ) - ( unsigned char * ) V_46 ;
}
break;
#ifdef F_236
case V_449 :
break;
#endif
case V_450 :
F_231 (
V_427 - V_451 ,
V_207 , V_46 -> V_48 , V_416 , false ) ;
break;
case V_452 :
if ( V_427 >= V_453 &&
F_233 ( V_207 ) ==
V_454 )
F_231 ( V_427 -
V_453 ,
V_207 + 2 , V_46 -> V_48 , V_416 , true ) ;
break;
}
V_207 += V_427 - 2 ;
V_424 -= V_427 ;
}
}
}
static bool F_237 ( struct V_32 * V_33 , const struct V_15 * V_46 )
{
const T_8 * V_207 = ( const T_8 * ) ( V_46 + 1 ) ;
if ( * V_207 == F_238 ( ( V_429 << 24 ) | ( V_429 << 16 )
| ( V_439 << 8 ) | V_440 ) ) {
V_33 -> V_52 . V_263 = 1 ;
++ V_207 ;
V_33 -> V_52 . V_390 = F_239 ( * V_207 ) ;
++ V_207 ;
if ( * V_207 )
V_33 -> V_52 . V_94 = F_239 ( * V_207 ) - V_33 -> V_455 ;
else
V_33 -> V_52 . V_94 = 0 ;
return true ;
}
return false ;
}
static bool F_240 ( const struct V_3 * V_4 ,
const struct V_15 * V_46 , struct V_32 * V_33 )
{
if ( V_46 -> V_425 == ( sizeof( * V_46 ) / 4 ) ) {
V_33 -> V_52 . V_263 = 0 ;
return false ;
} else if ( V_33 -> V_52 . V_441 &&
V_46 -> V_425 == ( ( sizeof( * V_46 ) + V_456 ) / 4 ) ) {
if ( F_237 ( V_33 , V_46 ) )
return true ;
}
F_232 ( V_4 , & V_33 -> V_52 , 1 , NULL ) ;
if ( V_33 -> V_52 . V_263 && V_33 -> V_52 . V_94 )
V_33 -> V_52 . V_94 -= V_33 -> V_455 ;
return true ;
}
const T_4 * F_241 ( const struct V_15 * V_46 )
{
int V_424 = ( V_46 -> V_425 << 2 ) - sizeof( * V_46 ) ;
const T_4 * V_207 = ( const T_4 * ) ( V_46 + 1 ) ;
if ( V_424 < V_457 )
return NULL ;
while ( V_424 > 0 ) {
int V_426 = * V_207 ++ ;
int V_427 ;
switch ( V_426 ) {
case V_428 :
return NULL ;
case V_429 :
V_424 -- ;
continue;
default:
V_427 = * V_207 ++ ;
if ( V_427 < 2 || V_427 > V_424 )
return NULL ;
if ( V_426 == V_449 )
return V_427 == V_457 ? V_207 : NULL ;
}
V_207 += V_427 - 2 ;
V_424 -= V_427 ;
}
return NULL ;
}
static int F_242 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
const struct V_15 * V_46 = F_6 ( V_4 ) ;
T_1 V_80 = F_18 ( V_4 ) -> V_80 ;
T_1 V_336 = F_18 ( V_4 ) -> V_159 ;
return (
( V_46 -> V_336 && V_80 == F_18 ( V_4 ) -> V_95 && V_80 == V_33 -> V_93 ) &&
V_336 == V_33 -> V_108 &&
! F_209 ( V_33 , V_336 , V_80 , F_154 ( V_46 -> V_63 ) << V_33 -> V_52 . V_377 ) &&
( T_5 ) ( V_33 -> V_52 . V_389 - V_33 -> V_52 . V_390 ) <= ( F_2 ( V_2 ) -> V_101 * 1024 ) / V_321 ) ;
}
static inline bool F_243 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
return ! F_224 ( & V_33 -> V_52 , V_458 ) &&
! F_242 ( V_2 , V_4 ) ;
}
static inline bool F_244 ( const struct V_32 * V_33 , T_1 V_80 , T_1 V_95 )
{
return ! F_48 ( V_95 , V_33 -> V_392 ) &&
! F_55 ( V_80 , V_33 -> V_93 + F_245 ( V_33 ) ) ;
}
void F_246 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_459 ) {
case V_460 :
V_2 -> V_461 = V_462 ;
break;
case V_463 :
V_2 -> V_461 = V_464 ;
break;
case V_465 :
return;
default:
V_2 -> V_461 = V_466 ;
}
F_247 () ;
if ( ! F_248 ( V_2 , V_467 ) )
V_2 -> V_468 ( V_2 ) ;
F_249 ( V_2 ) ;
}
static void F_250 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
F_52 ( V_2 ) ;
V_2 -> V_469 |= V_470 ;
F_251 ( V_2 , V_471 ) ;
switch ( V_2 -> V_459 ) {
case V_472 :
case V_473 :
F_252 ( V_2 , V_463 ) ;
F_2 ( V_2 ) -> V_8 . V_26 = 1 ;
break;
case V_463 :
case V_474 :
break;
case V_475 :
break;
case V_476 :
F_220 ( V_2 ) ;
F_252 ( V_2 , V_474 ) ;
break;
case V_477 :
F_220 ( V_2 ) ;
F_253 ( V_2 , V_478 , 0 ) ;
break;
default:
F_254 ( L_15 ,
V_438 , V_2 -> V_459 ) ;
break;
}
F_255 ( & V_33 -> V_479 ) ;
if ( F_142 ( V_33 ) )
F_235 ( & V_33 -> V_52 ) ;
F_53 ( V_2 ) ;
if ( ! F_248 ( V_2 , V_467 ) ) {
V_2 -> V_480 ( V_2 ) ;
if ( V_2 -> V_469 == V_481 ||
V_2 -> V_459 == V_465 )
F_256 ( V_2 , V_482 , V_483 ) ;
else
F_256 ( V_2 , V_482 , V_484 ) ;
}
}
static inline bool F_257 ( struct V_200 * V_153 , T_1 V_80 ,
T_1 V_95 )
{
if ( ! F_55 ( V_80 , V_153 -> V_95 ) && ! F_55 ( V_153 -> V_149 , V_95 ) ) {
if ( F_48 ( V_80 , V_153 -> V_149 ) )
V_153 -> V_149 = V_80 ;
if ( F_55 ( V_95 , V_153 -> V_95 ) )
V_153 -> V_95 = V_95 ;
return true ;
}
return false ;
}
static void F_258 ( struct V_1 * V_2 , T_1 V_80 , T_1 V_95 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_142 ( V_33 ) && V_485 ) {
int V_128 ;
if ( F_48 ( V_80 , V_33 -> V_93 ) )
V_128 = V_486 ;
else
V_128 = V_487 ;
F_70 ( F_71 ( V_2 ) , V_128 ) ;
V_33 -> V_52 . V_488 = 1 ;
V_33 -> V_489 [ 0 ] . V_149 = V_80 ;
V_33 -> V_489 [ 0 ] . V_95 = V_95 ;
}
}
static void F_259 ( struct V_1 * V_2 , T_1 V_80 , T_1 V_95 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( ! V_33 -> V_52 . V_488 )
F_258 ( V_2 , V_80 , V_95 ) ;
else
F_257 ( V_33 -> V_489 , V_80 , V_95 ) ;
}
static void F_260 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_18 ( V_4 ) -> V_95 != F_18 ( V_4 ) -> V_80 &&
F_48 ( F_18 ( V_4 ) -> V_80 , V_33 -> V_93 ) ) {
F_70 ( F_71 ( V_2 ) , V_490 ) ;
F_10 ( V_2 ) ;
if ( F_142 ( V_33 ) && V_485 ) {
T_1 V_95 = F_18 ( V_4 ) -> V_95 ;
if ( F_55 ( F_18 ( V_4 ) -> V_95 , V_33 -> V_93 ) )
V_95 = V_33 -> V_93 ;
F_258 ( V_2 , F_18 ( V_4 ) -> V_80 , V_95 ) ;
}
}
F_220 ( V_2 ) ;
}
static void F_261 ( struct V_32 * V_33 )
{
int V_491 ;
struct V_200 * V_153 = & V_33 -> V_492 [ 0 ] ;
struct V_200 * V_493 = V_153 + 1 ;
for ( V_491 = 1 ; V_491 < V_33 -> V_52 . V_154 ; ) {
if ( F_257 ( V_153 , V_493 -> V_149 , V_493 -> V_95 ) ) {
int V_213 ;
V_33 -> V_52 . V_154 -- ;
for ( V_213 = V_491 ; V_213 < V_33 -> V_52 . V_154 ; V_213 ++ )
V_153 [ V_213 ] = V_153 [ V_213 + 1 ] ;
continue;
}
V_491 ++ , V_493 ++ ;
}
}
static void F_262 ( struct V_1 * V_2 , T_1 V_80 , T_1 V_95 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_200 * V_153 = & V_33 -> V_492 [ 0 ] ;
int V_494 = V_33 -> V_52 . V_154 ;
int V_491 ;
if ( ! V_494 )
goto V_495;
for ( V_491 = 0 ; V_491 < V_494 ; V_491 ++ , V_153 ++ ) {
if ( F_257 ( V_153 , V_80 , V_95 ) ) {
for (; V_491 > 0 ; V_491 -- , V_153 -- )
F_116 ( * V_153 , * ( V_153 - 1 ) ) ;
if ( V_494 > 1 )
F_261 ( V_33 ) ;
return;
}
}
if ( V_491 >= V_209 ) {
V_491 -- ;
V_33 -> V_52 . V_154 -- ;
V_153 -- ;
}
for (; V_491 > 0 ; V_491 -- , V_153 -- )
* V_153 = * ( V_153 - 1 ) ;
V_495:
V_153 -> V_149 = V_80 ;
V_153 -> V_95 = V_95 ;
V_33 -> V_52 . V_154 ++ ;
}
static void F_263 ( struct V_32 * V_33 )
{
struct V_200 * V_153 = & V_33 -> V_492 [ 0 ] ;
int V_154 = V_33 -> V_52 . V_154 ;
int V_491 ;
if ( F_264 ( & V_33 -> V_479 ) ) {
V_33 -> V_52 . V_154 = 0 ;
return;
}
for ( V_491 = 0 ; V_491 < V_154 ; ) {
if ( ! F_48 ( V_33 -> V_93 , V_153 -> V_149 ) ) {
int V_213 ;
F_114 ( F_48 ( V_33 -> V_93 , V_153 -> V_95 ) ) ;
for ( V_213 = V_491 + 1 ; V_213 < V_154 ; V_213 ++ )
V_33 -> V_492 [ V_213 - 1 ] = V_33 -> V_492 [ V_213 ] ;
V_154 -- ;
continue;
}
V_491 ++ ;
V_153 ++ ;
}
V_33 -> V_52 . V_154 = V_154 ;
}
static bool F_265 ( struct V_1 * V_2 ,
struct V_3 * V_496 ,
struct V_3 * V_497 ,
bool * V_498 )
{
int V_291 ;
* V_498 = false ;
if ( F_18 ( V_497 ) -> V_80 != F_18 ( V_496 ) -> V_95 )
return false ;
if ( ! F_266 ( V_496 , V_497 , V_498 , & V_291 ) )
return false ;
F_267 ( V_291 , & V_2 -> V_84 ) ;
F_268 ( V_2 , V_291 ) ;
F_70 ( F_71 ( V_2 ) , V_499 ) ;
F_18 ( V_496 ) -> V_95 = F_18 ( V_497 ) -> V_95 ;
F_18 ( V_496 ) -> V_159 = F_18 ( V_497 ) -> V_159 ;
F_18 ( V_496 ) -> V_192 |= F_18 ( V_497 ) -> V_192 ;
return true ;
}
static void F_269 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_3 V_500 = V_33 -> V_93 ;
struct V_3 * V_4 , * V_501 ;
bool V_498 , V_502 ;
while ( ( V_4 = F_270 ( & V_33 -> V_479 ) ) != NULL ) {
if ( F_55 ( F_18 ( V_4 ) -> V_80 , V_33 -> V_93 ) )
break;
if ( F_48 ( F_18 ( V_4 ) -> V_80 , V_500 ) ) {
T_3 V_488 = V_500 ;
if ( F_48 ( F_18 ( V_4 ) -> V_95 , V_500 ) )
V_500 = F_18 ( V_4 ) -> V_95 ;
F_259 ( V_2 , F_18 ( V_4 ) -> V_80 , V_488 ) ;
}
F_271 ( V_4 , & V_33 -> V_479 ) ;
if ( ! F_55 ( F_18 ( V_4 ) -> V_95 , V_33 -> V_93 ) ) {
F_230 ( V_2 , L_16 ) ;
F_272 ( V_4 ) ;
continue;
}
F_230 ( V_2 , L_17 ,
V_33 -> V_93 , F_18 ( V_4 ) -> V_80 ,
F_18 ( V_4 ) -> V_95 ) ;
V_501 = F_273 ( & V_2 -> V_503 ) ;
V_502 = V_501 && F_265 ( V_2 , V_501 , V_4 , & V_498 ) ;
F_213 ( V_33 , F_18 ( V_4 ) -> V_95 ) ;
if ( ! V_502 )
F_274 ( & V_2 -> V_503 , V_4 ) ;
if ( F_18 ( V_4 ) -> V_192 & V_193 )
F_250 ( V_2 ) ;
if ( V_502 )
F_275 ( V_4 , V_498 ) ;
}
}
static int F_276 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_504 )
{
if ( F_43 ( & V_2 -> V_84 ) > V_2 -> V_72 ||
! F_277 ( V_2 , V_4 , V_504 ) ) {
if ( F_278 ( V_2 ) < 0 )
return - 1 ;
if ( ! F_277 ( V_2 , V_4 , V_504 ) ) {
if ( ! F_279 ( V_2 ) )
return - 1 ;
if ( ! F_277 ( V_2 , V_4 , V_504 ) )
return - 1 ;
}
}
return 0 ;
}
static void F_280 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_505 ;
T_1 V_80 , V_95 ;
F_21 ( V_33 , V_4 ) ;
if ( F_101 ( F_276 ( V_2 , V_4 , V_4 -> V_62 ) ) ) {
F_70 ( F_71 ( V_2 ) , V_506 ) ;
F_272 ( V_4 ) ;
return;
}
V_33 -> V_379 = 0 ;
F_52 ( V_2 ) ;
F_70 ( F_71 ( V_2 ) , V_507 ) ;
F_230 ( V_2 , L_18 ,
V_33 -> V_93 , F_18 ( V_4 ) -> V_80 , F_18 ( V_4 ) -> V_95 ) ;
V_505 = F_273 ( & V_33 -> V_479 ) ;
if ( ! V_505 ) {
if ( F_142 ( V_33 ) ) {
V_33 -> V_52 . V_154 = 1 ;
V_33 -> V_492 [ 0 ] . V_149 = F_18 ( V_4 ) -> V_80 ;
V_33 -> V_492 [ 0 ] . V_95 =
F_18 ( V_4 ) -> V_95 ;
}
F_281 ( & V_33 -> V_479 , V_4 ) ;
goto V_508;
}
V_80 = F_18 ( V_4 ) -> V_80 ;
V_95 = F_18 ( V_4 ) -> V_95 ;
if ( V_80 == F_18 ( V_505 ) -> V_95 ) {
bool V_498 ;
if ( ! F_265 ( V_2 , V_505 , V_4 , & V_498 ) ) {
F_282 ( & V_33 -> V_479 , V_505 , V_4 ) ;
} else {
F_31 ( V_2 , V_4 ) ;
F_275 ( V_4 , V_498 ) ;
V_4 = NULL ;
}
if ( ! V_33 -> V_52 . V_154 ||
V_33 -> V_492 [ 0 ] . V_95 != V_80 )
goto V_509;
V_33 -> V_492 [ 0 ] . V_95 = V_95 ;
goto V_508;
}
while ( 1 ) {
if ( ! F_55 ( F_18 ( V_505 ) -> V_80 , V_80 ) )
break;
if ( F_283 ( & V_33 -> V_479 , V_505 ) ) {
V_505 = NULL ;
break;
}
V_505 = F_284 ( & V_33 -> V_479 , V_505 ) ;
}
if ( V_505 && F_48 ( V_80 , F_18 ( V_505 ) -> V_95 ) ) {
if ( ! F_55 ( V_95 , F_18 ( V_505 ) -> V_95 ) ) {
F_70 ( F_71 ( V_2 ) , V_510 ) ;
F_272 ( V_4 ) ;
V_4 = NULL ;
F_258 ( V_2 , V_80 , V_95 ) ;
goto V_509;
}
if ( F_55 ( V_80 , F_18 ( V_505 ) -> V_80 ) ) {
F_258 ( V_2 , V_80 ,
F_18 ( V_505 ) -> V_95 ) ;
} else {
if ( F_283 ( & V_33 -> V_479 ,
V_505 ) )
V_505 = NULL ;
else
V_505 = F_284 (
& V_33 -> V_479 ,
V_505 ) ;
}
}
if ( ! V_505 )
F_281 ( & V_33 -> V_479 , V_4 ) ;
else
F_282 ( & V_33 -> V_479 , V_505 , V_4 ) ;
while ( ! F_285 ( & V_33 -> V_479 , V_4 ) ) {
V_505 = F_286 ( & V_33 -> V_479 , V_4 ) ;
if ( ! F_55 ( V_95 , F_18 ( V_505 ) -> V_80 ) )
break;
if ( F_48 ( V_95 , F_18 ( V_505 ) -> V_95 ) ) {
F_259 ( V_2 , F_18 ( V_505 ) -> V_80 ,
V_95 ) ;
break;
}
F_271 ( V_505 , & V_33 -> V_479 ) ;
F_259 ( V_2 , F_18 ( V_505 ) -> V_80 ,
F_18 ( V_505 ) -> V_95 ) ;
F_70 ( F_71 ( V_2 ) , V_510 ) ;
F_272 ( V_505 ) ;
}
V_509:
if ( F_142 ( V_33 ) )
F_262 ( V_2 , V_80 , V_95 ) ;
V_508:
if ( V_4 ) {
F_31 ( V_2 , V_4 ) ;
F_287 ( V_4 , V_2 ) ;
}
}
static int T_9 F_288 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_511 ,
bool * V_498 )
{
int V_502 ;
struct V_3 * V_501 = F_273 ( & V_2 -> V_503 ) ;
F_289 ( V_4 , V_511 ) ;
V_502 = ( V_501 &&
F_265 ( V_2 , V_501 , V_4 , V_498 ) ) ? 1 : 0 ;
F_213 ( F_7 ( V_2 ) , F_18 ( V_4 ) -> V_95 ) ;
if ( ! V_502 ) {
F_274 ( & V_2 -> V_503 , V_4 ) ;
F_287 ( V_4 , V_2 ) ;
}
return V_502 ;
}
int F_290 ( struct V_1 * V_2 , struct V_512 * V_265 , T_10 V_504 )
{
struct V_3 * V_4 ;
int V_164 = - V_513 ;
int V_514 = 0 ;
bool V_498 ;
if ( V_504 == 0 )
return 0 ;
if ( V_504 > V_515 ) {
int V_516 = F_45 ( T_10 , V_504 >> V_517 , V_518 ) ;
V_514 = V_516 << V_517 ;
V_504 = V_514 + ( V_504 & ~ V_519 ) ;
}
V_4 = F_291 ( V_504 - V_514 , V_514 ,
V_520 ,
& V_164 , V_2 -> V_521 ) ;
if ( ! V_4 )
goto V_164;
F_292 ( V_4 , V_504 - V_514 ) ;
V_4 -> V_514 = V_514 ;
V_4 -> V_10 = V_504 ;
if ( F_276 ( V_2 , V_4 , V_4 -> V_62 ) )
goto V_522;
V_164 = F_293 ( V_4 , 0 , & V_265 -> V_523 , V_504 ) ;
if ( V_164 )
goto V_522;
F_18 ( V_4 ) -> V_80 = F_7 ( V_2 ) -> V_93 ;
F_18 ( V_4 ) -> V_95 = F_18 ( V_4 ) -> V_80 + V_504 ;
F_18 ( V_4 ) -> V_159 = F_7 ( V_2 ) -> V_108 - 1 ;
if ( F_288 ( V_2 , V_4 , 0 , & V_498 ) ) {
F_165 ( V_498 ) ;
F_272 ( V_4 ) ;
}
return V_504 ;
V_522:
F_294 ( V_4 ) ;
V_164:
return V_164 ;
}
static void F_295 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_502 = - 1 ;
bool V_498 = false ;
if ( F_18 ( V_4 ) -> V_80 == F_18 ( V_4 ) -> V_95 )
goto V_524;
F_296 ( V_4 ) ;
F_289 ( V_4 , F_6 ( V_4 ) -> V_425 * 4 ) ;
F_15 ( V_33 , V_4 ) ;
V_33 -> V_52 . V_488 = 0 ;
if ( F_18 ( V_4 ) -> V_80 == V_33 -> V_93 ) {
if ( F_245 ( V_33 ) == 0 )
goto V_525;
if ( V_33 -> V_526 . V_527 == V_528 &&
V_33 -> V_81 == V_33 -> V_93 && V_33 -> V_526 . V_10 &&
F_297 ( V_2 ) && ! V_33 -> V_529 ) {
int V_530 = F_45 (unsigned int, skb->len,
tp->ucopy.len) ;
F_298 ( V_531 ) ;
F_299 () ;
if ( ! F_300 ( V_4 , 0 , V_33 -> V_526 . V_265 , V_530 ) ) {
V_33 -> V_526 . V_10 -= V_530 ;
V_33 -> V_81 += V_530 ;
V_502 = ( V_530 == V_4 -> V_10 ) ;
F_50 ( V_2 ) ;
}
F_301 () ;
}
if ( V_502 <= 0 ) {
V_532:
if ( V_502 < 0 ) {
if ( F_302 ( & V_2 -> V_503 ) == 0 )
F_303 ( V_2 , V_4 -> V_62 ) ;
else if ( F_276 ( V_2 , V_4 , V_4 -> V_62 ) )
goto V_524;
}
V_502 = F_288 ( V_2 , V_4 , 0 , & V_498 ) ;
}
F_213 ( V_33 , F_18 ( V_4 ) -> V_95 ) ;
if ( V_4 -> V_10 )
F_51 ( V_2 , V_4 ) ;
if ( F_18 ( V_4 ) -> V_192 & V_193 )
F_250 ( V_2 ) ;
if ( ! F_264 ( & V_33 -> V_479 ) ) {
F_269 ( V_2 ) ;
if ( F_264 ( & V_33 -> V_479 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 0 ;
}
if ( V_33 -> V_52 . V_154 )
F_263 ( V_33 ) ;
F_216 ( V_2 ) ;
if ( V_502 > 0 )
F_275 ( V_4 , V_498 ) ;
if ( ! F_248 ( V_2 , V_467 ) )
V_2 -> V_533 ( V_2 ) ;
return;
}
if ( ! F_55 ( F_18 ( V_4 ) -> V_95 , V_33 -> V_93 ) ) {
F_70 ( F_71 ( V_2 ) , V_490 ) ;
F_258 ( V_2 , F_18 ( V_4 ) -> V_80 , F_18 ( V_4 ) -> V_95 ) ;
V_525:
F_10 ( V_2 ) ;
F_52 ( V_2 ) ;
V_524:
F_272 ( V_4 ) ;
return;
}
if ( ! F_48 ( F_18 ( V_4 ) -> V_80 , V_33 -> V_93 + F_245 ( V_33 ) ) )
goto V_525;
F_10 ( V_2 ) ;
if ( F_48 ( F_18 ( V_4 ) -> V_80 , V_33 -> V_93 ) ) {
F_230 ( V_2 , L_19 ,
V_33 -> V_93 , F_18 ( V_4 ) -> V_80 ,
F_18 ( V_4 ) -> V_95 ) ;
F_258 ( V_2 , F_18 ( V_4 ) -> V_80 , V_33 -> V_93 ) ;
if ( ! F_245 ( V_33 ) )
goto V_525;
goto V_532;
}
F_280 ( V_2 , V_4 ) ;
}
static struct V_3 * F_304 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_534 * V_535 )
{
struct V_3 * V_362 = NULL ;
if ( ! F_285 ( V_535 , V_4 ) )
V_362 = F_286 ( V_535 , V_4 ) ;
F_271 ( V_4 , V_535 ) ;
F_272 ( V_4 ) ;
F_70 ( F_71 ( V_2 ) , V_536 ) ;
return V_362 ;
}
static void
F_305 ( struct V_1 * V_2 , struct V_534 * V_535 ,
struct V_3 * V_537 , struct V_3 * V_501 ,
T_1 V_538 , T_1 V_508 )
{
struct V_3 * V_4 , * V_539 ;
bool V_540 ;
V_4 = V_537 ;
V_541:
V_540 = true ;
F_306 (list, skb, n) {
if ( V_4 == V_501 )
break;
if ( ! F_48 ( V_538 , F_18 ( V_4 ) -> V_95 ) ) {
V_4 = F_304 ( V_2 , V_4 , V_535 ) ;
if ( ! V_4 )
break;
goto V_541;
}
if ( ! ( F_18 ( V_4 ) -> V_192 & ( V_363 | V_193 ) ) &&
( F_30 ( V_4 -> V_62 ) > V_4 -> V_10 ||
F_48 ( F_18 ( V_4 ) -> V_80 , V_538 ) ) ) {
V_540 = false ;
break;
}
if ( ! F_285 ( V_535 , V_4 ) ) {
struct V_3 * V_362 = F_286 ( V_535 , V_4 ) ;
if ( V_362 != V_501 &&
F_18 ( V_4 ) -> V_95 != F_18 ( V_362 ) -> V_80 ) {
V_540 = false ;
break;
}
}
V_538 = F_18 ( V_4 ) -> V_95 ;
}
if ( V_540 ||
( F_18 ( V_4 ) -> V_192 & ( V_363 | V_193 ) ) )
return;
while ( F_48 ( V_538 , V_508 ) ) {
int V_542 = F_45 ( int , F_307 ( 0 , 0 ) , V_508 - V_538 ) ;
struct V_3 * V_543 ;
V_543 = F_308 ( V_542 , V_169 ) ;
if ( ! V_543 )
return;
memcpy ( V_543 -> V_544 , V_4 -> V_544 , sizeof( V_4 -> V_544 ) ) ;
F_18 ( V_543 ) -> V_80 = F_18 ( V_543 ) -> V_95 = V_538 ;
F_309 ( V_535 , V_4 , V_543 ) ;
F_287 ( V_543 , V_2 ) ;
while ( V_542 > 0 ) {
int V_545 = V_538 - F_18 ( V_4 ) -> V_80 ;
int V_504 = F_18 ( V_4 ) -> V_95 - V_538 ;
F_89 ( V_545 < 0 ) ;
if ( V_504 > 0 ) {
V_504 = F_9 ( V_542 , V_504 ) ;
if ( F_310 ( V_4 , V_545 , F_292 ( V_543 , V_504 ) , V_504 ) )
F_311 () ;
F_18 ( V_543 ) -> V_95 += V_504 ;
V_542 -= V_504 ;
V_538 += V_504 ;
}
if ( ! F_48 ( V_538 , F_18 ( V_4 ) -> V_95 ) ) {
V_4 = F_304 ( V_2 , V_4 , V_535 ) ;
if ( ! V_4 ||
V_4 == V_501 ||
( F_18 ( V_4 ) -> V_192 & ( V_363 | V_193 ) ) )
return;
}
}
}
}
static void F_312 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_270 ( & V_33 -> V_479 ) ;
struct V_3 * V_537 ;
T_1 V_538 , V_508 ;
if ( ! V_4 )
return;
V_538 = F_18 ( V_4 ) -> V_80 ;
V_508 = F_18 ( V_4 ) -> V_95 ;
V_537 = V_4 ;
for (; ; ) {
struct V_3 * V_362 = NULL ;
if ( ! F_285 ( & V_33 -> V_479 , V_4 ) )
V_362 = F_286 ( & V_33 -> V_479 , V_4 ) ;
V_4 = V_362 ;
if ( ! V_4 ||
F_55 ( F_18 ( V_4 ) -> V_80 , V_508 ) ||
F_48 ( F_18 ( V_4 ) -> V_95 , V_538 ) ) {
F_305 ( V_2 , & V_33 -> V_479 ,
V_537 , V_4 , V_538 , V_508 ) ;
V_537 = V_4 ;
if ( ! V_4 )
break;
V_538 = F_18 ( V_4 ) -> V_80 ;
V_508 = F_18 ( V_4 ) -> V_95 ;
} else {
if ( F_48 ( F_18 ( V_4 ) -> V_80 , V_538 ) )
V_538 = F_18 ( V_4 ) -> V_80 ;
if ( F_55 ( F_18 ( V_4 ) -> V_95 , V_508 ) )
V_508 = F_18 ( V_4 ) -> V_95 ;
}
}
}
static bool F_279 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
bool V_546 = false ;
if ( ! F_264 ( & V_33 -> V_479 ) ) {
F_70 ( F_71 ( V_2 ) , V_547 ) ;
F_255 ( & V_33 -> V_479 ) ;
if ( V_33 -> V_52 . V_123 )
F_235 ( & V_33 -> V_52 ) ;
F_53 ( V_2 ) ;
V_546 = true ;
}
return V_546 ;
}
static int F_278 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
F_230 ( V_2 , L_20 , V_33 -> V_81 ) ;
F_70 ( F_71 ( V_2 ) , V_548 ) ;
if ( F_43 ( & V_2 -> V_84 ) >= V_2 -> V_72 )
F_40 ( V_2 ) ;
else if ( F_33 ( V_2 ) )
V_33 -> V_65 = F_9 ( V_33 -> V_65 , 4U * V_33 -> V_68 ) ;
F_312 ( V_2 ) ;
if ( ! F_264 ( & V_2 -> V_503 ) )
F_305 ( V_2 , & V_2 -> V_503 ,
F_270 ( & V_2 -> V_503 ) ,
NULL ,
V_33 -> V_81 , V_33 -> V_93 ) ;
F_53 ( V_2 ) ;
if ( F_43 ( & V_2 -> V_84 ) <= V_2 -> V_72 )
return 0 ;
F_279 ( V_2 ) ;
if ( F_43 ( & V_2 -> V_84 ) <= V_2 -> V_72 )
return 0 ;
F_70 ( F_71 ( V_2 ) , V_549 ) ;
V_33 -> V_379 = 0 ;
return - 1 ;
}
static bool F_313 ( const struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_2 -> V_74 & V_76 )
return false ;
if ( F_33 ( V_2 ) )
return false ;
if ( F_41 ( V_2 ) >= F_42 ( V_2 , 0 ) )
return false ;
if ( F_118 ( V_33 ) >= V_33 -> V_58 )
return false ;
return true ;
}
static void F_314 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_313 ( V_2 ) ) {
F_25 ( V_2 ) ;
V_33 -> V_83 = V_79 ;
}
V_2 -> V_550 ( V_2 ) ;
}
static void F_315 ( struct V_1 * V_2 )
{
if ( F_248 ( V_2 , V_551 ) ) {
F_316 ( V_2 , V_551 ) ;
F_317 () ;
if ( V_2 -> V_552 &&
F_318 ( V_553 , & V_2 -> V_552 -> V_394 ) )
F_314 ( V_2 ) ;
}
}
static inline void F_319 ( struct V_1 * V_2 )
{
F_320 ( V_2 ) ;
F_315 ( V_2 ) ;
}
static void F_321 ( struct V_1 * V_2 , int V_554 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( ( ( V_33 -> V_93 - V_33 -> V_392 ) > F_2 ( V_2 ) -> V_8 . V_12 &&
F_322 ( V_2 ) >= V_33 -> V_23 ) ||
F_11 ( V_2 ) ||
( V_554 && F_270 ( & V_33 -> V_479 ) ) ) {
F_220 ( V_2 ) ;
} else {
F_323 ( V_2 ) ;
}
}
static inline void F_324 ( struct V_1 * V_2 )
{
if ( ! F_325 ( V_2 ) ) {
return;
}
F_321 ( V_2 , 1 ) ;
}
static void F_326 ( struct V_1 * V_2 , const struct V_15 * V_46 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_1 V_207 = F_154 ( V_46 -> V_555 ) ;
if ( V_207 && ! V_556 )
V_207 -- ;
V_207 += F_239 ( V_46 -> V_80 ) ;
if ( F_55 ( V_33 -> V_81 , V_207 ) )
return;
if ( F_48 ( V_207 , V_33 -> V_93 ) )
return;
if ( V_33 -> V_529 && ! F_55 ( V_207 , V_33 -> V_557 ) )
return;
F_327 ( V_2 ) ;
if ( V_33 -> V_557 == V_33 -> V_81 && V_33 -> V_529 &&
! F_248 ( V_2 , V_558 ) && V_33 -> V_81 != V_33 -> V_93 ) {
struct V_3 * V_4 = F_270 ( & V_2 -> V_503 ) ;
V_33 -> V_81 ++ ;
if ( V_4 && ! F_48 ( V_33 -> V_81 , F_18 ( V_4 ) -> V_95 ) ) {
F_271 ( V_4 , & V_2 -> V_503 ) ;
F_272 ( V_4 ) ;
}
}
V_33 -> V_529 = V_559 ;
V_33 -> V_557 = V_207 ;
V_33 -> V_379 = 0 ;
}
static void F_328 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_15 * V_46 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_46 -> V_560 )
F_326 ( V_2 , V_46 ) ;
if ( V_33 -> V_529 == V_559 ) {
T_1 V_207 = V_33 -> V_557 - F_239 ( V_46 -> V_80 ) + ( V_46 -> V_425 * 4 ) -
V_46 -> V_48 ;
if ( V_207 < V_4 -> V_10 ) {
T_4 V_203 ;
if ( F_310 ( V_4 , V_207 , & V_203 , 1 ) )
F_311 () ;
V_33 -> V_529 = V_561 | V_203 ;
if ( ! F_248 ( V_2 , V_467 ) )
V_2 -> V_533 ( V_2 ) ;
}
}
}
static int F_329 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_562 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_530 = V_4 -> V_10 - V_562 ;
int V_164 ;
F_299 () ;
if ( F_330 ( V_4 ) )
V_164 = F_300 ( V_4 , V_562 , V_33 -> V_526 . V_265 , V_530 ) ;
else
V_164 = F_331 ( V_4 , V_562 , V_33 -> V_526 . V_265 ) ;
if ( ! V_164 ) {
V_33 -> V_526 . V_10 -= V_530 ;
V_33 -> V_81 += V_530 ;
F_50 ( V_2 ) ;
}
F_301 () ;
return V_164 ;
}
static T_11 F_332 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_11 V_563 ;
if ( F_297 ( V_2 ) ) {
F_299 () ;
V_563 = F_333 ( V_4 ) ;
F_301 () ;
} else {
V_563 = F_333 ( V_4 ) ;
}
return V_563 ;
}
static inline bool F_334 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ! F_330 ( V_4 ) &&
F_332 ( V_2 , V_4 ) ;
}
static bool F_335 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_46 , int V_564 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_240 ( V_4 , V_46 , V_33 ) && V_33 -> V_52 . V_263 &&
F_243 ( V_2 , V_4 ) ) {
if ( ! V_46 -> V_565 ) {
F_70 ( F_71 ( V_2 ) , V_566 ) ;
if ( ! F_218 ( F_71 ( V_2 ) , V_4 ,
V_567 ,
& V_33 -> V_381 ) )
F_260 ( V_2 , V_4 ) ;
goto V_568;
}
}
if ( ! F_244 ( V_33 , F_18 ( V_4 ) -> V_80 , F_18 ( V_4 ) -> V_95 ) ) {
if ( ! V_46 -> V_565 ) {
if ( V_46 -> V_48 )
goto V_569;
if ( ! F_218 ( F_71 ( V_2 ) , V_4 ,
V_570 ,
& V_33 -> V_381 ) )
F_260 ( V_2 , V_4 ) ;
}
goto V_568;
}
if ( V_46 -> V_565 ) {
if ( F_18 ( V_4 ) -> V_80 == V_33 -> V_93 )
F_246 ( V_2 ) ;
else
F_219 ( V_2 , V_4 ) ;
goto V_568;
}
if ( V_46 -> V_48 ) {
V_569:
if ( V_564 )
F_336 ( F_71 ( V_2 ) , V_571 ) ;
F_70 ( F_71 ( V_2 ) , V_572 ) ;
F_219 ( V_2 , V_4 ) ;
goto V_568;
}
return true ;
V_568:
F_272 ( V_4 ) ;
return false ;
}
void F_337 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_46 , unsigned int V_10 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_101 ( ! V_2 -> V_573 ) )
F_2 ( V_2 ) -> V_574 -> V_575 ( V_2 , V_4 ) ;
V_33 -> V_52 . V_263 = 0 ;
if ( ( F_5 ( V_46 ) & V_576 ) == V_33 -> V_379 &&
F_18 ( V_4 ) -> V_80 == V_33 -> V_93 &&
! F_55 ( F_18 ( V_4 ) -> V_159 , V_33 -> V_110 ) ) {
int V_18 = V_33 -> V_18 ;
if ( V_18 == sizeof( struct V_15 ) + V_456 ) {
if ( ! F_237 ( V_33 , V_46 ) )
goto V_577;
if ( ( T_5 ) ( V_33 -> V_52 . V_390 - V_33 -> V_52 . V_389 ) < 0 )
goto V_577;
}
if ( V_10 <= V_18 ) {
if ( V_10 == V_18 ) {
if ( V_18 ==
( sizeof( struct V_15 ) + V_456 ) &&
V_33 -> V_93 == V_33 -> V_392 )
F_221 ( V_33 ) ;
F_227 ( V_2 , V_4 , 0 ) ;
F_272 ( V_4 ) ;
F_319 ( V_2 ) ;
return;
} else {
F_336 ( F_71 ( V_2 ) , V_571 ) ;
goto V_568;
}
} else {
int V_502 = 0 ;
bool V_498 = false ;
if ( V_33 -> V_526 . V_527 == V_528 &&
V_33 -> V_81 == V_33 -> V_93 &&
V_10 - V_18 <= V_33 -> V_526 . V_10 &&
F_297 ( V_2 ) ) {
F_298 ( V_531 ) ;
if ( ! F_329 ( V_2 , V_4 , V_18 ) ) {
if ( V_18 ==
( sizeof( struct V_15 ) +
V_456 ) &&
V_33 -> V_93 == V_33 -> V_392 )
F_221 ( V_33 ) ;
F_49 ( V_2 , V_4 ) ;
F_289 ( V_4 , V_18 ) ;
F_213 ( V_33 , F_18 ( V_4 ) -> V_95 ) ;
F_70 ( F_71 ( V_2 ) , V_578 ) ;
V_502 = 1 ;
}
}
if ( ! V_502 ) {
if ( F_334 ( V_2 , V_4 ) )
goto V_579;
if ( ( int ) V_4 -> V_62 > V_2 -> V_580 )
goto V_581;
if ( V_18 ==
( sizeof( struct V_15 ) + V_456 ) &&
V_33 -> V_93 == V_33 -> V_392 )
F_221 ( V_33 ) ;
F_49 ( V_2 , V_4 ) ;
F_70 ( F_71 ( V_2 ) , V_582 ) ;
V_502 = F_288 ( V_2 , V_4 , V_18 ,
& V_498 ) ;
}
F_51 ( V_2 , V_4 ) ;
if ( F_18 ( V_4 ) -> V_159 != V_33 -> V_108 ) {
F_227 ( V_2 , V_4 , V_407 ) ;
F_319 ( V_2 ) ;
if ( ! F_325 ( V_2 ) )
goto V_583;
}
F_321 ( V_2 , 0 ) ;
V_583:
if ( V_502 )
F_275 ( V_4 , V_498 ) ;
V_2 -> V_533 ( V_2 ) ;
return;
}
}
V_577:
if ( V_10 < ( V_46 -> V_425 << 2 ) || F_334 ( V_2 , V_4 ) )
goto V_579;
if ( ! V_46 -> V_336 && ! V_46 -> V_565 && ! V_46 -> V_48 )
goto V_568;
if ( ! F_335 ( V_2 , V_4 , V_46 , 1 ) )
return;
V_581:
if ( F_227 ( V_2 , V_4 , V_402 | V_401 ) < 0 )
goto V_568;
F_49 ( V_2 , V_4 ) ;
F_328 ( V_2 , V_4 , V_46 ) ;
F_295 ( V_2 , V_4 ) ;
F_319 ( V_2 ) ;
F_324 ( V_2 ) ;
return;
V_579:
F_336 ( F_71 ( V_2 ) , V_584 ) ;
F_336 ( F_71 ( V_2 ) , V_571 ) ;
V_568:
F_272 ( V_4 ) ;
}
void F_338 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_252 ( V_2 , V_473 ) ;
if ( V_4 ) {
V_6 -> V_574 -> V_575 ( V_2 , V_4 ) ;
F_339 ( V_2 , V_4 ) ;
}
V_6 -> V_574 -> V_585 ( V_2 ) ;
F_340 ( V_2 ) ;
F_341 ( V_2 ) ;
V_33 -> V_586 = V_79 ;
F_37 ( V_2 ) ;
if ( F_248 ( V_2 , V_587 ) )
F_342 ( V_2 , F_343 ( V_33 ) ) ;
if ( ! V_33 -> V_52 . V_377 )
F_344 ( V_33 , V_33 -> V_373 ) ;
else
V_33 -> V_379 = 0 ;
if ( ! F_248 ( V_2 , V_467 ) ) {
V_2 -> V_480 ( V_2 ) ;
F_256 ( V_2 , V_588 , V_589 ) ;
}
}
static bool F_345 ( struct V_1 * V_2 , struct V_3 * V_590 ,
struct V_415 * V_414 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_13 = V_33 -> V_591 ? F_102 ( V_2 ) : NULL ;
T_6 V_69 = V_33 -> V_52 . V_53 , V_592 = 0 ;
bool V_593 = false ;
if ( V_69 == V_33 -> V_52 . V_433 ) {
struct V_421 V_594 ;
F_346 ( & V_594 ) ;
V_594 . V_433 = V_594 . V_53 = 0 ;
F_232 ( V_590 , & V_594 , 0 , NULL ) ;
V_69 = V_594 . V_53 ;
}
if ( ! V_33 -> V_595 ) {
V_414 -> V_10 = - 1 ;
} else if ( V_33 -> V_596 ) {
V_593 = ( V_414 -> V_10 < 0 && V_13 ) ;
} else if ( V_414 -> V_10 < 0 && ! V_33 -> V_591 ) {
V_592 = V_33 -> V_597 ? 2 : 1 ;
}
F_347 ( V_2 , V_69 , V_414 , V_593 , V_592 ) ;
if ( V_13 ) {
F_108 (data, sk) {
if ( V_13 == F_106 ( V_2 ) ||
F_348 ( V_2 , V_13 ) )
break;
}
F_194 ( V_2 ) ;
F_70 ( F_71 ( V_2 ) , V_598 ) ;
return true ;
}
V_33 -> V_599 = V_33 -> V_591 ;
if ( V_33 -> V_599 )
F_70 ( F_71 ( V_2 ) , V_600 ) ;
return false ;
}
static int F_349 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_46 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_415 V_416 = { . V_10 = - 1 } ;
int V_601 = V_33 -> V_52 . V_53 ;
F_232 ( V_4 , & V_33 -> V_52 , 0 , & V_416 ) ;
if ( V_33 -> V_52 . V_263 && V_33 -> V_52 . V_94 )
V_33 -> V_52 . V_94 -= V_33 -> V_455 ;
if ( V_46 -> V_336 ) {
if ( ! F_55 ( F_18 ( V_4 ) -> V_159 , V_33 -> V_108 ) ||
F_55 ( F_18 ( V_4 ) -> V_159 , V_33 -> V_110 ) )
goto V_602;
if ( V_33 -> V_52 . V_263 && V_33 -> V_52 . V_94 &&
! F_200 ( V_33 -> V_52 . V_94 , V_33 -> V_264 ,
V_79 ) ) {
F_70 ( F_71 ( V_2 ) , V_603 ) ;
goto V_602;
}
if ( V_46 -> V_565 ) {
F_246 ( V_2 ) ;
goto V_568;
}
if ( ! V_46 -> V_48 )
goto V_604;
F_22 ( V_33 , V_46 ) ;
F_350 ( V_33 , F_18 ( V_4 ) -> V_80 ) ;
F_227 ( V_2 , V_4 , V_402 ) ;
V_33 -> V_93 = F_18 ( V_4 ) -> V_80 + 1 ;
V_33 -> V_392 = F_18 ( V_4 ) -> V_80 + 1 ;
V_33 -> V_373 = F_154 ( V_46 -> V_63 ) ;
if ( ! V_33 -> V_52 . V_437 ) {
V_33 -> V_52 . V_377 = V_33 -> V_52 . V_605 = 0 ;
V_33 -> V_66 = F_9 ( V_33 -> V_66 , 65535U ) ;
}
if ( V_33 -> V_52 . V_263 ) {
V_33 -> V_52 . V_441 = 1 ;
V_33 -> V_18 =
sizeof( struct V_15 ) + V_456 ;
V_33 -> V_68 -= V_456 ;
F_221 ( V_33 ) ;
} else {
V_33 -> V_18 = sizeof( struct V_15 ) ;
}
if ( F_142 ( V_33 ) && V_606 )
F_351 ( V_33 ) ;
F_352 ( V_2 ) ;
F_174 ( V_2 , V_6 -> V_302 ) ;
F_44 ( V_2 ) ;
V_33 -> V_81 = V_33 -> V_93 ;
F_353 () ;
F_338 ( V_2 , V_4 ) ;
if ( ( V_33 -> V_595 || V_33 -> V_591 ) &&
F_345 ( V_2 , V_4 , & V_416 ) )
return - 1 ;
if ( V_2 -> V_607 ||
V_6 -> V_608 . V_609 ||
V_6 -> V_8 . V_26 ) {
F_52 ( V_2 ) ;
V_6 -> V_8 . V_100 = V_79 ;
F_10 ( V_2 ) ;
F_134 ( V_2 , V_610 ,
V_611 , V_245 ) ;
V_568:
F_272 ( V_4 ) ;
return 0 ;
} else {
F_220 ( V_2 ) ;
}
return - 1 ;
}
if ( V_46 -> V_565 ) {
goto V_604;
}
if ( V_33 -> V_52 . V_391 && V_33 -> V_52 . V_263 &&
F_354 ( & V_33 -> V_52 , 0 ) )
goto V_604;
if ( V_46 -> V_48 ) {
F_252 ( V_2 , V_472 ) ;
if ( V_33 -> V_52 . V_263 ) {
V_33 -> V_52 . V_441 = 1 ;
F_221 ( V_33 ) ;
V_33 -> V_18 =
sizeof( struct V_15 ) + V_456 ;
} else {
V_33 -> V_18 = sizeof( struct V_15 ) ;
}
V_33 -> V_93 = F_18 ( V_4 ) -> V_80 + 1 ;
V_33 -> V_81 = V_33 -> V_93 ;
V_33 -> V_392 = F_18 ( V_4 ) -> V_80 + 1 ;
V_33 -> V_373 = F_154 ( V_46 -> V_63 ) ;
V_33 -> V_372 = F_18 ( V_4 ) -> V_80 ;
V_33 -> V_150 = V_33 -> V_373 ;
F_23 ( V_33 , V_46 ) ;
F_352 ( V_2 ) ;
F_174 ( V_2 , V_6 -> V_302 ) ;
F_44 ( V_2 ) ;
F_355 ( V_2 ) ;
#if 0
return -1;
#else
goto V_568;
#endif
}
V_604:
F_346 ( & V_33 -> V_52 ) ;
V_33 -> V_52 . V_53 = V_601 ;
goto V_568;
V_602:
F_346 ( & V_33 -> V_52 ) ;
V_33 -> V_52 . V_53 = V_601 ;
return 1 ;
}
int F_356 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_15 * V_46 = F_6 ( V_4 ) ;
struct V_331 * V_332 ;
int V_612 = 0 ;
bool V_613 ;
V_33 -> V_52 . V_263 = 0 ;
switch ( V_2 -> V_459 ) {
case V_465 :
goto V_568;
case V_614 :
if ( V_46 -> V_336 )
return 1 ;
if ( V_46 -> V_565 )
goto V_568;
if ( V_46 -> V_48 ) {
if ( V_46 -> V_615 )
goto V_568;
if ( V_6 -> V_574 -> V_616 ( V_2 , V_4 ) < 0 )
return 1 ;
F_294 ( V_4 ) ;
return 0 ;
}
goto V_568;
case V_460 :
V_612 = F_349 ( V_2 , V_4 , V_46 ) ;
if ( V_612 >= 0 )
return V_612 ;
F_328 ( V_2 , V_4 , V_46 ) ;
F_272 ( V_4 ) ;
F_319 ( V_2 ) ;
return 0 ;
}
V_332 = V_33 -> V_338 ;
if ( V_332 ) {
F_165 ( V_2 -> V_459 != V_472 &&
V_2 -> V_459 != V_476 ) ;
if ( ! F_357 ( V_2 , V_4 , V_332 , true ) )
goto V_568;
}
if ( ! V_46 -> V_336 && ! V_46 -> V_565 && ! V_46 -> V_48 )
goto V_568;
if ( ! F_335 ( V_2 , V_4 , V_46 , 0 ) )
return 0 ;
V_613 = F_227 ( V_2 , V_4 , V_402 |
V_401 ) > 0 ;
switch ( V_2 -> V_459 ) {
case V_472 :
if ( ! V_613 )
return 1 ;
if ( ! V_33 -> V_104 )
F_189 ( V_2 , V_332 ) ;
if ( V_332 ) {
V_33 -> V_596 = V_332 -> V_333 ;
F_358 ( V_2 , V_332 , false ) ;
} else {
V_6 -> V_574 -> V_585 ( V_2 ) ;
F_341 ( V_2 ) ;
F_352 ( V_2 ) ;
V_33 -> V_81 = V_33 -> V_93 ;
F_37 ( V_2 ) ;
}
F_353 () ;
F_252 ( V_2 , V_473 ) ;
V_2 -> V_480 ( V_2 ) ;
if ( V_2 -> V_552 )
F_256 ( V_2 , V_588 , V_589 ) ;
V_33 -> V_108 = F_18 ( V_4 ) -> V_159 ;
V_33 -> V_373 = F_154 ( V_46 -> V_63 ) << V_33 -> V_52 . V_377 ;
F_350 ( V_33 , F_18 ( V_4 ) -> V_80 ) ;
if ( V_33 -> V_52 . V_441 )
V_33 -> V_68 -= V_456 ;
if ( V_332 ) {
F_194 ( V_2 ) ;
} else
F_340 ( V_2 ) ;
F_57 ( V_2 ) ;
V_33 -> V_586 = V_79 ;
F_44 ( V_2 ) ;
F_359 ( V_33 ) ;
break;
case V_476 : {
struct V_29 * V_30 ;
int V_617 ;
if ( V_332 ) {
if ( ! V_613 )
return 1 ;
F_358 ( V_2 , V_332 , false ) ;
F_194 ( V_2 ) ;
}
if ( V_33 -> V_108 != V_33 -> V_618 )
break;
F_252 ( V_2 , V_477 ) ;
V_2 -> V_469 |= V_619 ;
V_30 = F_12 ( V_2 ) ;
if ( V_30 )
F_228 ( V_30 ) ;
if ( ! F_248 ( V_2 , V_467 ) ) {
V_2 -> V_480 ( V_2 ) ;
break;
}
if ( V_33 -> V_620 < 0 ||
( F_18 ( V_4 ) -> V_95 != F_18 ( V_4 ) -> V_80 &&
F_55 ( F_18 ( V_4 ) -> V_95 - V_46 -> V_615 , V_33 -> V_93 ) ) ) {
F_249 ( V_2 ) ;
F_70 ( F_71 ( V_2 ) , V_621 ) ;
return 1 ;
}
V_617 = F_360 ( V_2 ) ;
if ( V_617 > V_622 ) {
F_342 ( V_2 , V_617 - V_622 ) ;
} else if ( V_46 -> V_615 || F_297 ( V_2 ) ) {
F_342 ( V_2 , V_617 ) ;
} else {
F_253 ( V_2 , V_477 , V_617 ) ;
goto V_568;
}
break;
}
case V_474 :
if ( V_33 -> V_108 == V_33 -> V_618 ) {
F_253 ( V_2 , V_478 , 0 ) ;
goto V_568;
}
break;
case V_475 :
if ( V_33 -> V_108 == V_33 -> V_618 ) {
F_361 ( V_2 ) ;
F_249 ( V_2 ) ;
goto V_568;
}
break;
}
F_328 ( V_2 , V_4 , V_46 ) ;
switch ( V_2 -> V_459 ) {
case V_463 :
case V_474 :
case V_475 :
if ( ! F_48 ( F_18 ( V_4 ) -> V_80 , V_33 -> V_93 ) )
break;
case V_476 :
case V_477 :
if ( V_2 -> V_469 & V_470 ) {
if ( F_18 ( V_4 ) -> V_95 != F_18 ( V_4 ) -> V_80 &&
F_55 ( F_18 ( V_4 ) -> V_95 - V_46 -> V_615 , V_33 -> V_93 ) ) {
F_70 ( F_71 ( V_2 ) , V_621 ) ;
F_246 ( V_2 ) ;
return 1 ;
}
}
case V_473 :
F_295 ( V_2 , V_4 ) ;
V_612 = 1 ;
break;
}
if ( V_2 -> V_459 != V_465 ) {
F_319 ( V_2 ) ;
F_324 ( V_2 ) ;
}
if ( ! V_612 ) {
V_568:
F_272 ( V_4 ) ;
}
return 0 ;
}
static inline void F_362 ( struct V_331 * V_332 , T_12 V_623 , int V_624 )
{
struct V_625 * V_626 = F_363 ( V_332 ) ;
if ( V_624 == V_269 )
F_364 ( L_21 ,
& V_626 -> V_627 , V_623 ) ;
#if F_156 ( V_272 )
else if ( V_624 == V_273 )
F_364 ( L_22 ,
& V_626 -> V_628 , V_623 ) ;
#endif
}
static void F_365 ( struct V_331 * V_332 ,
const struct V_3 * V_4 ,
const struct V_1 * V_629 ,
const struct V_29 * V_30 )
{
const struct V_15 * V_46 = F_6 ( V_4 ) ;
const struct V_380 * V_380 = F_71 ( V_629 ) ;
bool V_630 = V_46 -> V_47 && V_46 -> V_37 ;
bool V_631 , V_632 ;
T_1 V_633 ;
if ( ! V_630 )
return;
V_631 = ! F_366 ( F_18 ( V_4 ) -> V_39 ) ;
V_633 = F_367 ( V_30 , V_634 ) ;
V_632 = V_380 -> V_635 . V_636 || V_633 ;
if ( ( ! V_631 && V_632 ) || F_19 ( V_629 ) ||
( V_633 & V_637 ) )
F_363 ( V_332 ) -> V_632 = 1 ;
}
static void F_368 ( struct V_331 * V_332 ,
const struct V_421 * V_52 ,
struct V_3 * V_4 , const struct V_1 * V_2 )
{
struct V_625 * V_626 = F_363 ( V_332 ) ;
V_332 -> V_638 = 0 ;
V_332 -> V_639 = 0 ;
F_190 ( V_332 ) -> V_640 = F_18 ( V_4 ) -> V_80 ;
F_190 ( V_332 ) -> V_93 = F_18 ( V_4 ) -> V_80 + 1 ;
F_191 ( & F_190 ( V_332 ) -> V_334 ) ;
F_190 ( V_332 ) -> V_381 = 0 ;
V_332 -> V_69 = V_52 -> V_53 ;
V_332 -> V_389 = V_52 -> V_263 ? V_52 -> V_390 : 0 ;
V_626 -> V_441 = V_52 -> V_441 ;
V_626 -> V_123 = V_52 -> V_123 ;
V_626 -> V_377 = V_52 -> V_377 ;
V_626 -> V_437 = V_52 -> V_437 ;
V_626 -> V_225 = 0 ;
V_626 -> V_632 = 0 ;
V_626 -> V_641 = F_6 ( V_4 ) -> V_642 ;
V_626 -> V_643 = F_154 ( F_6 ( V_4 ) -> V_644 ) ;
V_626 -> V_645 = F_369 ( V_2 , V_4 ) ;
}
struct V_331 * F_370 ( const struct V_646 * V_647 ,
struct V_1 * V_648 ,
bool V_649 )
{
struct V_331 * V_332 = F_371 ( V_647 , V_648 ,
V_649 ) ;
if ( V_332 ) {
struct V_625 * V_626 = F_363 ( V_332 ) ;
F_372 ( V_626 , V_394 ) ;
V_626 -> V_594 = NULL ;
F_373 ( & V_626 -> V_650 , 0 ) ;
V_626 -> V_651 = V_652 ;
F_374 ( & V_626 -> V_653 , F_71 ( V_648 ) ) ;
V_626 -> V_654 = V_648 -> V_268 ;
}
return V_332 ;
}
static bool F_375 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const char * V_655 )
{
struct V_656 * V_657 = & F_2 ( V_2 ) -> V_608 ;
const char * V_265 = L_23 ;
bool V_658 = false ;
#ifdef F_376
if ( V_659 ) {
V_265 = L_24 ;
V_658 = true ;
F_70 ( F_71 ( V_2 ) , V_660 ) ;
} else
#endif
F_70 ( F_71 ( V_2 ) , V_661 ) ;
if ( ! V_657 -> V_662 &&
V_659 != 2 &&
F_377 ( & V_657 -> V_662 , 1 ) == 0 )
F_378 ( L_25 ,
V_655 , F_154 ( F_6 ( V_4 ) -> V_644 ) , V_265 ) ;
return V_658 ;
}
static void F_379 ( const struct V_1 * V_2 ,
struct V_331 * V_332 ,
const struct V_3 * V_4 )
{
if ( F_7 ( V_2 ) -> V_663 ) {
T_1 V_10 = F_380 ( V_4 ) + F_381 ( V_4 ) ;
T_1 * V_542 ;
V_542 = F_382 ( V_10 + sizeof( T_1 ) , V_169 ) ;
if ( V_542 ) {
V_542 [ 0 ] = V_10 ;
memcpy ( & V_542 [ 1 ] , F_383 ( V_4 ) , V_10 ) ;
V_332 -> V_664 = V_542 ;
}
}
}
int F_384 ( struct V_646 * V_665 ,
const struct V_666 * V_667 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_415 V_416 = { . V_10 = - 1 } ;
T_3 V_668 = F_18 ( V_4 ) -> V_669 ;
struct V_421 V_670 ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_1 * V_671 = NULL ;
struct V_29 * V_30 = NULL ;
struct V_331 * V_332 ;
bool V_658 = false ;
struct V_672 V_673 ;
if ( ( V_659 == 2 ||
F_385 ( V_2 ) ) && ! V_668 ) {
V_658 = F_375 ( V_2 , V_4 , V_665 -> V_674 ) ;
if ( ! V_658 )
goto V_524;
}
if ( F_386 ( V_2 ) && F_387 ( V_2 ) > 1 ) {
F_70 ( F_71 ( V_2 ) , V_675 ) ;
goto V_524;
}
V_332 = F_370 ( V_665 , V_2 , ! V_658 ) ;
if ( ! V_332 )
goto V_524;
F_190 ( V_332 ) -> V_676 = V_667 ;
F_346 ( & V_670 ) ;
V_670 . V_53 = V_667 -> V_53 ;
V_670 . V_433 = V_33 -> V_52 . V_433 ;
F_232 ( V_4 , & V_670 , 0 , V_658 ? NULL : & V_416 ) ;
if ( V_658 && ! V_670 . V_263 )
F_346 ( & V_670 ) ;
V_670 . V_441 = V_670 . V_263 ;
F_368 ( V_332 , & V_670 , V_4 , V_2 ) ;
F_363 ( V_332 ) -> V_677 = V_2 -> V_678 ;
V_667 -> V_679 ( V_332 , V_2 , V_4 ) ;
if ( F_388 ( V_2 , V_4 , V_332 ) )
goto V_680;
if ( ! V_658 && ! V_668 ) {
if ( V_681 . V_682 ) {
bool V_683 ;
V_30 = V_667 -> V_684 ( V_2 , & V_673 , V_332 , & V_683 ) ;
if ( V_30 && V_683 &&
! F_389 ( V_332 , V_30 , true ,
V_670 . V_263 ) ) {
F_70 ( F_71 ( V_2 ) , V_685 ) ;
goto V_686;
}
}
else if ( ! V_659 &&
( V_687 - F_390 ( V_2 ) <
( V_687 >> 2 ) ) &&
! F_389 ( V_332 , V_30 , false ,
V_670 . V_263 ) ) {
F_362 ( V_332 , F_154 ( F_6 ( V_4 ) -> V_642 ) ,
V_665 -> V_624 ) ;
goto V_686;
}
V_668 = V_667 -> V_688 ( V_4 ) ;
}
if ( ! V_30 ) {
V_30 = V_667 -> V_684 ( V_2 , & V_673 , V_332 , NULL ) ;
if ( ! V_30 )
goto V_680;
}
F_365 ( V_332 , V_4 , V_2 , V_30 ) ;
if ( V_658 ) {
V_668 = F_391 ( V_667 , V_2 , V_4 , & V_332 -> V_69 ) ;
V_332 -> V_639 = V_670 . V_441 ;
if ( ! V_670 . V_441 )
F_363 ( V_332 ) -> V_632 = 0 ;
}
F_190 ( V_332 ) -> V_689 = V_668 ;
F_190 ( V_332 ) -> V_690 = F_392 () ;
F_393 ( V_332 , V_2 , V_30 ) ;
if ( ! V_658 ) {
F_379 ( V_2 , V_332 , V_4 ) ;
V_671 = F_394 ( V_2 , V_4 , V_332 , & V_416 , V_30 ) ;
}
if ( V_671 ) {
V_667 -> V_691 ( V_671 , V_30 , & V_673 , V_332 ,
& V_416 , false ) ;
F_395 ( V_2 , V_332 , V_671 ) ;
V_2 -> V_533 ( V_2 ) ;
F_396 ( V_671 ) ;
F_397 ( V_671 ) ;
} else {
F_190 ( V_332 ) -> V_692 = false ;
if ( ! V_658 )
F_398 ( V_2 , V_332 , V_693 ) ;
V_667 -> V_691 ( V_2 , V_30 , & V_673 , V_332 ,
& V_416 , ! V_658 ) ;
if ( V_658 )
goto V_680;
}
F_399 ( V_332 ) ;
return 0 ;
V_686:
F_400 ( V_30 ) ;
V_680:
F_401 ( V_332 ) ;
V_524:
F_70 ( F_71 ( V_2 ) , V_694 ) ;
return 0 ;
}
