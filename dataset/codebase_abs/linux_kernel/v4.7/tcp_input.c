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
V_33 -> V_186 += V_172 ;
V_175 += V_172 ;
if ( ! F_66 ( V_33 ) && V_33 -> V_122 &&
F_48 ( V_149 , F_18 ( V_33 -> V_122 ) -> V_80 ) )
V_33 -> V_187 += V_172 ;
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
unsigned int V_172 , int V_188 , int V_69 ,
bool V_158 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_189 = F_88 ( V_2 , V_4 ) ;
T_1 V_149 = F_18 ( V_4 ) -> V_80 ;
T_1 V_95 = V_149 + V_188 ;
F_89 ( ! V_172 ) ;
F_84 ( V_2 , V_171 , F_18 ( V_4 ) -> V_145 ,
V_149 , V_95 , V_158 , V_172 ,
& V_4 -> V_173 ) ;
if ( V_4 == V_33 -> V_122 )
V_33 -> V_187 += V_172 ;
F_18 ( V_189 ) -> V_95 += V_188 ;
F_18 ( V_4 ) -> V_80 += V_188 ;
F_90 ( V_189 , V_172 ) ;
F_89 ( F_76 ( V_4 ) < V_172 ) ;
F_90 ( V_4 , - V_172 ) ;
if ( ! F_18 ( V_189 ) -> V_190 )
F_18 ( V_189 ) -> V_190 = V_69 ;
if ( F_76 ( V_4 ) <= 1 )
F_18 ( V_4 ) -> V_190 = 0 ;
F_18 ( V_189 ) -> V_145 |= ( F_18 ( V_4 ) -> V_145 & V_191 ) ;
if ( V_4 -> V_10 > 0 ) {
F_89 ( ! F_76 ( V_4 ) ) ;
F_70 ( F_71 ( V_2 ) , V_192 ) ;
return false ;
}
if ( V_4 == V_33 -> V_142 )
V_33 -> V_142 = V_189 ;
if ( V_4 == V_33 -> V_122 ) {
V_33 -> V_122 = V_189 ;
V_33 -> V_187 -= F_76 ( V_189 ) ;
}
F_18 ( V_189 ) -> V_193 |= F_18 ( V_4 ) -> V_193 ;
F_18 ( V_189 ) -> V_194 = F_18 ( V_4 ) -> V_194 ;
if ( F_18 ( V_4 ) -> V_193 & V_195 )
F_18 ( V_189 ) -> V_95 ++ ;
if ( V_4 == F_91 ( V_2 ) )
F_92 ( V_2 , V_4 ) ;
F_93 ( V_189 , V_4 ) ;
F_94 ( V_4 , V_2 ) ;
F_95 ( V_2 , V_4 ) ;
F_70 ( F_71 ( V_2 ) , V_196 ) ;
return true ;
}
static int F_96 ( const struct V_3 * V_4 )
{
return F_76 ( V_4 ) == 1 ? V_4 -> V_10 : F_82 ( V_4 ) ;
}
static int F_97 ( const struct V_3 * V_4 )
{
return ! F_98 ( V_4 ) && F_99 ( V_4 ) ;
}
static struct V_3 * F_100 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_170 * V_171 ,
T_1 V_149 , T_1 V_95 ,
bool V_158 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_189 ;
int V_69 ;
int V_172 = 0 ;
int V_10 ;
int V_165 ;
if ( ! F_101 ( V_2 ) )
goto V_197;
if ( ! V_158 &&
( F_18 ( V_4 ) -> V_145 & ( V_146 | V_177 ) ) == V_177 )
goto V_197;
if ( ! F_97 ( V_4 ) )
goto V_197;
if ( ! F_55 ( F_18 ( V_4 ) -> V_95 , V_33 -> V_108 ) )
goto V_197;
if ( F_102 ( V_4 == F_103 ( V_2 ) ) )
goto V_197;
V_189 = F_88 ( V_2 , V_4 ) ;
if ( ( F_18 ( V_189 ) -> V_145 & V_198 ) != V_147 )
goto V_197;
if ( ! F_104 ( V_189 ) )
goto V_197;
V_165 = ! F_55 ( V_149 , F_18 ( V_4 ) -> V_80 ) &&
! F_48 ( V_95 , F_18 ( V_4 ) -> V_95 ) ;
if ( V_165 ) {
V_10 = V_4 -> V_10 ;
V_172 = F_76 ( V_4 ) ;
V_69 = F_96 ( V_4 ) ;
if ( V_69 != F_96 ( V_189 ) )
goto V_197;
} else {
if ( ! F_55 ( F_18 ( V_4 ) -> V_95 , V_149 ) )
goto V_199;
if ( F_76 ( V_4 ) <= 1 )
goto V_199;
V_165 = ! F_55 ( V_149 , F_18 ( V_4 ) -> V_80 ) ;
if ( ! V_165 ) {
goto V_197;
}
V_10 = V_95 - F_18 ( V_4 ) -> V_80 ;
F_89 ( V_10 < 0 ) ;
F_89 ( V_10 > V_4 -> V_10 ) ;
V_69 = F_82 ( V_4 ) ;
if ( V_69 != F_96 ( V_189 ) )
goto V_197;
if ( V_10 == V_69 ) {
V_172 = 1 ;
} else if ( V_10 < V_69 ) {
goto V_199;
} else {
V_172 = V_10 / V_69 ;
V_10 = V_172 * V_69 ;
}
}
if ( ! F_55 ( F_18 ( V_4 ) -> V_80 + V_10 , V_33 -> V_108 ) )
goto V_197;
if ( ! F_105 ( V_189 , V_4 , V_10 ) )
goto V_197;
if ( ! F_87 ( V_2 , V_4 , V_171 , V_172 , V_10 , V_69 , V_158 ) )
goto V_200;
if ( V_189 == F_106 ( V_2 ) )
goto V_200;
V_4 = F_107 ( V_2 , V_189 ) ;
if ( ! F_97 ( V_4 ) ||
( V_4 == F_108 ( V_2 ) ) ||
( ( F_18 ( V_4 ) -> V_145 & V_198 ) != V_147 ) ||
( V_69 != F_96 ( V_4 ) ) )
goto V_200;
V_10 = V_4 -> V_10 ;
if ( F_105 ( V_189 , V_4 , V_10 ) ) {
V_172 += F_76 ( V_4 ) ;
F_87 ( V_2 , V_4 , V_171 , F_76 ( V_4 ) , V_10 , V_69 , 0 ) ;
}
V_200:
V_171 -> V_175 += V_172 ;
return V_189 ;
V_199:
return V_4 ;
V_197:
F_70 ( F_71 ( V_2 ) , V_201 ) ;
return NULL ;
}
static struct V_3 * F_109 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_202 * V_203 ,
struct V_170 * V_171 ,
T_1 V_149 , T_1 V_95 ,
bool V_204 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_205 ;
F_110 (skb, sk) {
int V_165 = 0 ;
bool V_158 = V_204 ;
if ( V_4 == F_108 ( V_2 ) )
break;
if ( ! F_48 ( F_18 ( V_4 ) -> V_80 , V_95 ) )
break;
if ( V_203 &&
F_48 ( F_18 ( V_4 ) -> V_80 , V_203 -> V_95 ) ) {
V_165 = F_81 ( V_2 , V_4 ,
V_203 -> V_149 ,
V_203 -> V_95 ) ;
if ( V_165 > 0 )
V_158 = true ;
}
if ( V_165 <= 0 ) {
V_205 = F_100 ( V_2 , V_4 , V_171 ,
V_149 , V_95 , V_158 ) ;
if ( V_205 ) {
if ( V_205 != V_4 ) {
V_4 = V_205 ;
continue;
}
V_165 = 0 ;
} else {
V_165 = F_81 ( V_2 , V_4 ,
V_149 ,
V_95 ) ;
}
}
if ( F_102 ( V_165 < 0 ) )
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
static struct V_3 * F_111 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_170 * V_171 ,
T_1 V_206 )
{
F_110 (skb, sk) {
if ( V_4 == F_108 ( V_2 ) )
break;
if ( F_55 ( F_18 ( V_4 ) -> V_95 , V_206 ) )
break;
V_171 -> V_175 += F_76 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_112 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_202 * V_203 ,
struct V_170 * V_171 ,
T_1 V_206 )
{
if ( ! V_203 )
return V_4 ;
if ( F_48 ( V_203 -> V_149 , V_206 ) ) {
V_4 = F_111 ( V_4 , V_2 , V_171 , V_203 -> V_149 ) ;
V_4 = F_109 ( V_4 , V_2 , NULL , V_171 ,
V_203 -> V_149 , V_203 -> V_95 ,
1 ) ;
}
return V_4 ;
}
static int F_113 ( const struct V_32 * V_33 , const struct V_202 * V_207 )
{
return V_207 < V_33 -> V_208 + F_114 ( V_33 -> V_208 ) ;
}
static int
F_115 ( struct V_1 * V_2 , const struct V_3 * V_151 ,
T_1 V_155 , struct V_170 * V_171 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
const unsigned char * V_209 = ( F_4 ( V_151 ) +
F_18 ( V_151 ) -> V_145 ) ;
struct V_152 * V_210 = (struct V_152 * ) ( V_209 + 2 ) ;
struct V_202 V_153 [ V_211 ] ;
struct V_202 * V_207 ;
struct V_3 * V_4 ;
int V_154 = F_9 ( V_211 , ( V_209 [ 1 ] - V_212 ) >> 3 ) ;
int V_213 ;
bool V_214 = false ;
int V_215 , V_216 ;
int V_217 ;
V_171 -> V_180 = 0 ;
V_171 -> V_141 = V_33 -> V_116 ;
if ( ! V_33 -> V_137 ) {
if ( F_116 ( V_33 -> V_136 ) )
V_33 -> V_136 = 0 ;
F_117 ( V_2 ) ;
}
V_214 = F_79 ( V_2 , V_151 , V_210 ,
V_154 , V_155 ) ;
if ( V_214 )
V_171 -> V_180 |= V_218 ;
if ( F_48 ( F_18 ( V_151 ) -> V_159 , V_155 - V_33 -> V_150 ) )
return 0 ;
if ( ! V_33 -> V_116 )
goto V_200;
V_213 = 0 ;
V_217 = 0 ;
for ( V_215 = 0 ; V_215 < V_154 ; V_215 ++ ) {
bool V_158 = ! V_215 && V_214 ;
V_153 [ V_213 ] . V_149 = F_80 ( & V_210 [ V_215 ] . V_149 ) ;
V_153 [ V_213 ] . V_95 = F_80 ( & V_210 [ V_215 ] . V_95 ) ;
if ( ! F_78 ( V_33 , V_158 ,
V_153 [ V_213 ] . V_149 ,
V_153 [ V_213 ] . V_95 ) ) {
int V_128 ;
if ( V_158 ) {
if ( ! V_33 -> V_138 )
V_128 = V_219 ;
else
V_128 = V_220 ;
} else {
if ( ( F_18 ( V_151 ) -> V_159 != V_33 -> V_108 ) &&
! F_55 ( V_153 [ V_213 ] . V_95 , V_33 -> V_108 ) )
continue;
V_128 = V_221 ;
}
F_70 ( F_71 ( V_2 ) , V_128 ) ;
if ( V_215 == 0 )
V_217 = - 1 ;
continue;
}
if ( ! F_55 ( V_153 [ V_213 ] . V_95 , V_155 ) )
continue;
V_213 ++ ;
}
for ( V_215 = V_213 - 1 ; V_215 > 0 ; V_215 -- ) {
for ( V_216 = 0 ; V_216 < V_215 ; V_216 ++ ) {
if ( F_55 ( V_153 [ V_216 ] . V_149 , V_153 [ V_216 + 1 ] . V_149 ) ) {
F_118 ( V_153 [ V_216 ] , V_153 [ V_216 + 1 ] ) ;
if ( V_216 == V_217 )
V_217 = V_216 + 1 ;
}
}
}
V_4 = F_103 ( V_2 ) ;
V_171 -> V_175 = 0 ;
V_215 = 0 ;
if ( ! V_33 -> V_137 ) {
V_207 = V_33 -> V_208 + F_114 ( V_33 -> V_208 ) ;
} else {
V_207 = V_33 -> V_208 ;
while ( F_113 ( V_33 , V_207 ) && ! V_207 -> V_149 &&
! V_207 -> V_95 )
V_207 ++ ;
}
while ( V_215 < V_213 ) {
T_1 V_149 = V_153 [ V_215 ] . V_149 ;
T_1 V_95 = V_153 [ V_215 ] . V_95 ;
bool V_158 = ( V_214 && ( V_215 == V_217 ) ) ;
struct V_202 * V_203 = NULL ;
if ( V_214 && ( ( V_215 + 1 ) == V_217 ) )
V_203 = & V_153 [ V_215 + 1 ] ;
while ( F_113 ( V_33 , V_207 ) &&
! F_48 ( V_149 , V_207 -> V_95 ) )
V_207 ++ ;
if ( F_113 ( V_33 , V_207 ) && ! V_158 &&
F_55 ( V_95 , V_207 -> V_149 ) ) {
if ( F_48 ( V_149 , V_207 -> V_149 ) ) {
V_4 = F_111 ( V_4 , V_2 , V_171 ,
V_149 ) ;
V_4 = F_109 ( V_4 , V_2 , V_203 ,
V_171 ,
V_149 ,
V_207 -> V_149 ,
V_158 ) ;
}
if ( ! F_55 ( V_95 , V_207 -> V_95 ) )
goto V_222;
V_4 = F_112 ( V_4 , V_2 , V_203 ,
V_171 ,
V_207 -> V_95 ) ;
if ( F_86 ( V_33 ) == V_207 -> V_95 ) {
V_4 = F_91 ( V_2 ) ;
if ( ! V_4 )
break;
V_171 -> V_175 = V_33 -> V_136 ;
V_207 ++ ;
goto V_223;
}
V_4 = F_111 ( V_4 , V_2 , V_171 , V_207 -> V_95 ) ;
V_207 ++ ;
continue;
}
if ( ! F_48 ( V_149 , F_86 ( V_33 ) ) ) {
V_4 = F_91 ( V_2 ) ;
if ( ! V_4 )
break;
V_171 -> V_175 = V_33 -> V_136 ;
}
V_4 = F_111 ( V_4 , V_2 , V_171 , V_149 ) ;
V_223:
V_4 = F_109 ( V_4 , V_2 , V_203 , V_171 ,
V_149 , V_95 , V_158 ) ;
V_222:
V_215 ++ ;
}
for ( V_215 = 0 ; V_215 < F_114 ( V_33 -> V_208 ) - V_213 ; V_215 ++ ) {
V_33 -> V_208 [ V_215 ] . V_149 = 0 ;
V_33 -> V_208 [ V_215 ] . V_95 = 0 ;
}
for ( V_216 = 0 ; V_216 < V_213 ; V_216 ++ )
V_33 -> V_208 [ V_215 ++ ] = V_153 [ V_216 ] ;
if ( ( V_171 -> V_141 < V_33 -> V_136 ) &&
( ( F_2 ( V_2 ) -> V_135 != V_224 ) || V_33 -> V_138 ) )
F_68 ( V_2 , V_33 -> V_136 - V_171 -> V_141 , 0 ) ;
F_119 ( V_33 ) ;
V_200:
#if V_134 > 0
F_116 ( ( int ) V_33 -> V_137 < 0 ) ;
F_116 ( ( int ) V_33 -> V_143 < 0 ) ;
F_116 ( ( int ) V_33 -> V_178 < 0 ) ;
F_116 ( ( int ) F_120 ( V_33 ) < 0 ) ;
#endif
return V_171 -> V_180 ;
}
static bool F_121 ( struct V_32 * V_33 )
{
T_1 V_225 ;
V_225 = F_39 ( V_33 -> V_143 , 1U ) ;
V_225 = F_9 ( V_225 , V_33 -> V_116 ) ;
if ( ( V_33 -> V_137 + V_225 ) > V_33 -> V_116 ) {
V_33 -> V_137 = V_33 -> V_116 - V_225 ;
return true ;
}
return false ;
}
static void F_122 ( struct V_1 * V_2 , const int V_226 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_121 ( V_33 ) )
F_68 ( V_2 , V_33 -> V_116 + V_226 , 0 ) ;
}
static void F_123 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_1 V_227 = V_33 -> V_137 ;
V_33 -> V_137 ++ ;
F_122 ( V_2 , 0 ) ;
if ( V_33 -> V_137 > V_227 )
V_33 -> V_186 ++ ;
F_119 ( V_33 ) ;
}
static void F_124 ( struct V_1 * V_2 , int V_228 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_228 > 0 ) {
V_33 -> V_186 += F_26 ( int , V_228 - V_33 -> V_137 , 1 ) ;
if ( V_228 - 1 >= V_33 -> V_137 )
V_33 -> V_137 = 0 ;
else
V_33 -> V_137 -= V_228 - 1 ;
}
F_122 ( V_2 , V_228 ) ;
F_119 ( V_33 ) ;
}
static inline void F_125 ( struct V_32 * V_33 )
{
V_33 -> V_137 = 0 ;
}
void F_126 ( struct V_32 * V_33 )
{
V_33 -> V_178 = 0 ;
V_33 -> V_143 = 0 ;
V_33 -> V_138 = 0 ;
V_33 -> V_139 = - 1 ;
V_33 -> V_136 = 0 ;
V_33 -> V_137 = 0 ;
}
static inline void F_127 ( struct V_32 * V_33 )
{
V_33 -> V_138 = V_33 -> V_108 ;
V_33 -> V_139 = V_33 -> V_178 ? : - 1 ;
}
void F_128 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_229 * V_229 = F_71 ( V_2 ) ;
struct V_3 * V_4 ;
bool V_230 = V_6 -> V_135 < V_231 ;
bool V_232 ;
if ( V_6 -> V_135 <= V_233 ||
! F_55 ( V_33 -> V_179 , V_33 -> V_108 ) ||
( V_6 -> V_135 == V_224 && ! V_6 -> V_234 ) ) {
V_33 -> V_235 = F_129 ( V_2 ) ;
V_33 -> V_113 = V_6 -> V_236 -> V_237 ( V_2 ) ;
F_20 ( V_2 , V_238 ) ;
F_127 ( V_33 ) ;
}
V_33 -> V_58 = 1 ;
V_33 -> V_239 = 0 ;
V_33 -> V_83 = V_79 ;
V_33 -> V_178 = 0 ;
V_33 -> V_143 = 0 ;
if ( F_69 ( V_33 ) )
F_125 ( V_33 ) ;
V_4 = F_103 ( V_2 ) ;
V_232 = V_4 && ( F_18 ( V_4 ) -> V_145 & V_147 ) ;
if ( V_232 ) {
F_70 ( F_71 ( V_2 ) , V_240 ) ;
V_33 -> V_137 = 0 ;
V_33 -> V_136 = 0 ;
}
F_130 ( V_33 ) ;
F_131 (skb, sk) {
if ( V_4 == F_108 ( V_2 ) )
break;
F_18 ( V_4 ) -> V_145 &= ( ~ V_198 ) | V_147 ;
if ( ! ( F_18 ( V_4 ) -> V_145 & V_147 ) || V_232 ) {
F_18 ( V_4 ) -> V_145 &= ~ V_147 ;
F_18 ( V_4 ) -> V_145 |= V_146 ;
V_33 -> V_143 += F_76 ( V_4 ) ;
V_33 -> V_144 = F_18 ( V_4 ) -> V_95 ;
}
}
F_119 ( V_33 ) ;
if ( V_6 -> V_135 <= V_233 &&
V_33 -> V_137 >= V_229 -> V_241 . V_242 )
V_33 -> V_59 = F_45 (unsigned int, tp->reordering,
net->ipv4.sysctl_tcp_reordering) ;
F_132 ( V_2 , V_224 ) ;
V_33 -> V_179 = V_33 -> V_110 ;
F_14 ( V_33 ) ;
V_33 -> V_243 = V_244 &&
( V_230 || V_6 -> V_234 ) &&
! F_2 ( V_2 ) -> V_245 . V_246 ;
}
static bool F_133 ( struct V_1 * V_2 , int V_180 )
{
if ( V_180 & V_247 ) {
struct V_32 * V_33 = F_7 ( V_2 ) ;
unsigned long V_248 = F_39 ( F_134 ( V_33 -> V_104 >> 4 ) ,
F_135 ( 10 ) ) ;
F_136 ( V_2 , V_249 ,
V_248 , V_250 ) ;
return true ;
}
return false ;
}
static inline int F_137 ( const struct V_32 * V_33 )
{
return F_69 ( V_33 ) ? V_33 -> V_137 + 1 : V_33 -> V_136 ;
}
static inline int F_138 ( const struct V_32 * V_33 )
{
return F_66 ( V_33 ) ? V_33 -> V_136 : V_33 -> V_137 + 1 ;
}
static bool F_139 ( struct V_1 * V_2 , int V_180 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
unsigned long V_248 ;
if ( V_251 < 2 || V_251 > 3 ||
( V_180 & V_252 ) || ! V_33 -> V_104 )
return false ;
V_248 = F_39 ( F_134 ( V_33 -> V_104 >> 5 ) ,
F_135 ( 2 ) ) ;
if ( ! F_140 ( F_2 ( V_2 ) -> V_253 , ( V_254 + V_248 ) ) )
return false ;
F_136 ( V_2 , V_255 , V_248 ,
V_250 ) ;
return true ;
}
static bool F_141 ( struct V_1 * V_2 , int V_180 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_3 V_116 ;
int V_256 = F_71 ( V_2 ) -> V_241 . V_242 ;
if ( V_33 -> V_143 )
return true ;
if ( F_138 ( V_33 ) > V_33 -> V_59 )
return true ;
V_116 = V_33 -> V_116 ;
if ( V_116 <= V_33 -> V_59 &&
V_33 -> V_137 >= F_26 ( T_3 , V_116 / 2 , V_256 ) &&
! F_142 ( V_2 ) ) {
return true ;
}
if ( ( V_33 -> V_257 || V_258 ) &&
F_143 ( V_33 ) && F_138 ( V_33 ) > 1 &&
F_144 ( V_33 ) && ! F_108 ( V_2 ) )
return true ;
if ( V_33 -> V_259 && ! V_33 -> V_178 && V_33 -> V_137 &&
( V_33 -> V_116 >= ( V_33 -> V_137 + 1 ) && V_33 -> V_116 < 4 ) &&
! F_142 ( V_2 ) )
return ! F_139 ( V_2 , V_180 ) ;
return false ;
}
static void F_145 ( struct V_1 * V_2 , int V_260 , int V_261 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_262 , V_263 , V_264 ;
unsigned int V_69 ;
const T_1 V_265 = F_144 ( V_33 ) ? V_33 -> V_110 : V_33 -> V_179 ;
F_116 ( V_260 > V_33 -> V_116 ) ;
if ( V_33 -> V_122 ) {
V_4 = V_33 -> V_122 ;
V_262 = V_33 -> V_187 ;
if ( V_261 && V_4 != F_103 ( V_2 ) )
return;
} else {
V_4 = F_103 ( V_2 ) ;
V_262 = 0 ;
}
F_110 (skb, sk) {
if ( V_4 == F_108 ( V_2 ) )
break;
V_33 -> V_122 = V_4 ;
V_33 -> V_187 = V_262 ;
if ( F_55 ( F_18 ( V_4 ) -> V_95 , V_265 ) )
break;
V_263 = V_262 ;
if ( F_66 ( V_33 ) || F_69 ( V_33 ) ||
( F_18 ( V_4 ) -> V_145 & V_147 ) )
V_262 += F_76 ( V_4 ) ;
if ( V_262 > V_260 ) {
if ( ( F_144 ( V_33 ) && ! F_66 ( V_33 ) ) ||
( F_18 ( V_4 ) -> V_145 & V_147 ) ||
( V_263 >= V_260 ) )
break;
V_69 = F_82 ( V_4 ) ;
V_264 = ( V_260 - V_263 ) * V_69 ;
if ( V_264 < V_4 -> V_10 &&
F_83 ( V_2 , V_4 , V_264 , V_69 , V_169 ) < 0 )
break;
V_262 = V_260 ;
}
F_75 ( V_33 , V_4 ) ;
if ( V_261 )
break;
}
F_119 ( V_33 ) ;
}
static void F_146 ( struct V_1 * V_2 , int V_266 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_69 ( V_33 ) ) {
F_145 ( V_2 , 1 , 1 ) ;
} else if ( F_66 ( V_33 ) ) {
int V_264 = V_33 -> V_136 - V_33 -> V_59 ;
if ( V_264 <= 0 )
V_264 = 1 ;
F_145 ( V_2 , V_264 , 0 ) ;
} else {
int V_267 = V_33 -> V_137 - V_33 -> V_59 ;
if ( V_267 >= 0 )
F_145 ( V_2 , V_267 , 0 ) ;
else if ( V_266 )
F_145 ( V_2 , 1 , 1 ) ;
}
}
static bool F_147 ( const struct V_32 * V_33 , T_1 V_268 )
{
return V_33 -> V_52 . V_269 && V_33 -> V_52 . V_94 &&
F_48 ( V_33 -> V_52 . V_94 , V_268 ) ;
}
static bool F_148 ( const struct V_32 * V_33 ,
const struct V_3 * V_4 )
{
return ( F_18 ( V_4 ) -> V_145 & V_176 ) &&
F_147 ( V_33 , F_149 ( V_4 ) ) ;
}
static inline bool F_150 ( const struct V_32 * V_33 )
{
return ! V_33 -> V_270 ||
F_147 ( V_33 , V_33 -> V_270 ) ;
}
static bool F_151 ( const struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_33 -> V_178 )
return true ;
V_4 = F_103 ( V_2 ) ;
if ( F_102 ( V_4 && F_18 ( V_4 ) -> V_145 & V_191 ) )
return true ;
return false ;
}
static void F_152 ( struct V_1 * V_2 , const char * V_271 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_272 * V_273 = F_153 ( V_2 ) ;
if ( V_2 -> V_274 == V_275 ) {
F_72 ( L_2 ,
V_271 ,
& V_273 -> V_276 , F_154 ( V_273 -> V_277 ) ,
V_33 -> V_58 , F_155 ( V_33 ) ,
V_33 -> V_113 , V_33 -> V_235 ,
V_33 -> V_116 ) ;
}
#if F_156 ( V_278 )
else if ( V_2 -> V_274 == V_279 ) {
struct V_280 * V_281 = F_157 ( V_2 ) ;
F_72 ( L_3 ,
V_271 ,
& V_281 -> V_282 , F_154 ( V_273 -> V_277 ) ,
V_33 -> V_58 , F_155 ( V_33 ) ,
V_33 -> V_113 , V_33 -> V_235 ,
V_33 -> V_116 ) ;
}
#endif
}
static void F_158 ( struct V_1 * V_2 , bool V_283 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_283 ) {
struct V_3 * V_4 ;
F_131 (skb, sk) {
if ( V_4 == F_108 ( V_2 ) )
break;
F_18 ( V_4 ) -> V_145 &= ~ V_146 ;
}
V_33 -> V_143 = 0 ;
F_130 ( V_33 ) ;
}
if ( V_33 -> V_235 ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_236 -> V_284 )
V_33 -> V_58 = V_6 -> V_236 -> V_284 ( V_2 ) ;
else
V_33 -> V_58 = F_39 ( V_33 -> V_58 , V_33 -> V_113 << 1 ) ;
if ( V_33 -> V_235 > V_33 -> V_113 ) {
V_33 -> V_113 = V_33 -> V_235 ;
F_16 ( V_33 ) ;
}
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
F_152 ( V_2 , F_2 ( V_2 ) -> V_135 == V_224 ? L_4 : L_5 ) ;
F_158 ( V_2 , false ) ;
if ( F_2 ( V_2 ) -> V_135 == V_224 )
V_128 = V_285 ;
else
V_128 = V_286 ;
F_70 ( F_71 ( V_2 ) , V_128 ) ;
}
if ( V_33 -> V_108 == V_33 -> V_179 && F_69 ( V_33 ) ) {
if ( ! F_151 ( V_2 ) )
V_33 -> V_270 = 0 ;
return true ;
}
F_132 ( V_2 , V_287 ) ;
return false ;
}
static bool F_161 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_33 -> V_138 && ! V_33 -> V_139 ) {
F_152 ( V_2 , L_6 ) ;
F_158 ( V_2 , false ) ;
F_70 ( F_71 ( V_2 ) , V_288 ) ;
return true ;
}
return false ;
}
static bool F_162 ( struct V_1 * V_2 , bool V_289 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_289 || F_159 ( V_33 ) ) {
F_158 ( V_2 , true ) ;
F_152 ( V_2 , L_7 ) ;
F_70 ( F_71 ( V_2 ) , V_285 ) ;
if ( V_289 )
F_70 ( F_71 ( V_2 ) ,
V_290 ) ;
F_2 ( V_2 ) -> V_234 = 0 ;
if ( V_289 || F_144 ( V_33 ) )
F_132 ( V_2 , V_287 ) ;
return true ;
}
return false ;
}
static void F_163 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
V_33 -> V_179 = V_33 -> V_110 ;
V_33 -> V_291 = 0 ;
V_33 -> V_239 = 0 ;
V_33 -> V_292 = V_33 -> V_58 ;
V_33 -> V_293 = 0 ;
V_33 -> V_294 = 0 ;
V_33 -> V_113 = F_2 ( V_2 ) -> V_236 -> V_237 ( V_2 ) ;
F_14 ( V_33 ) ;
}
static void F_164 ( struct V_1 * V_2 , int V_295 ,
int V_180 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_296 = 0 ;
int V_297 = V_33 -> V_113 - F_120 ( V_33 ) ;
if ( V_295 <= 0 || F_165 ( ! V_33 -> V_292 ) )
return;
V_33 -> V_293 += V_295 ;
if ( V_297 < 0 ) {
T_2 V_298 = ( T_2 ) V_33 -> V_113 * V_33 -> V_293 +
V_33 -> V_292 - 1 ;
V_296 = F_166 ( V_298 , V_33 -> V_292 ) - V_33 -> V_294 ;
} else if ( ( V_180 & V_299 ) &&
! ( V_180 & V_300 ) ) {
V_296 = F_45 ( int , V_297 ,
F_26 ( int , V_33 -> V_293 - V_33 -> V_294 ,
V_295 ) + 1 ) ;
} else {
V_296 = F_9 ( V_297 , V_295 ) ;
}
V_296 = F_39 ( V_296 , ( V_33 -> V_294 ? 0 : 1 ) ) ;
V_33 -> V_58 = F_120 ( V_33 ) + V_296 ;
}
static inline void F_167 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_135 == V_301 ||
( V_33 -> V_138 && V_33 -> V_113 < V_302 ) ) {
V_33 -> V_58 = V_33 -> V_113 ;
V_33 -> V_83 = V_79 ;
}
F_20 ( V_2 , V_303 ) ;
}
void F_168 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
V_33 -> V_235 = 0 ;
if ( F_2 ( V_2 ) -> V_135 < V_301 ) {
V_33 -> V_138 = 0 ;
F_163 ( V_2 ) ;
F_132 ( V_2 , V_301 ) ;
}
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_171 = V_287 ;
if ( F_155 ( V_33 ) || F_151 ( V_2 ) )
V_171 = V_233 ;
if ( F_2 ( V_2 ) -> V_135 != V_171 ) {
F_132 ( V_2 , V_171 ) ;
V_33 -> V_179 = V_33 -> V_110 ;
}
}
static void F_170 ( struct V_1 * V_2 , int V_180 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
F_119 ( V_33 ) ;
if ( ! F_151 ( V_2 ) )
V_33 -> V_270 = 0 ;
if ( V_180 & V_252 )
F_168 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_135 != V_301 ) {
F_169 ( V_2 ) ;
}
}
static void F_171 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_245 . V_304 = V_6 -> V_245 . V_246 - 1 ;
V_6 -> V_245 . V_246 = 0 ;
F_70 ( F_71 ( V_2 ) , V_305 ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_33 -> V_235 = F_129 ( V_2 ) ;
V_33 -> V_58 = V_33 -> V_58 *
F_173 ( V_2 , V_33 -> V_54 ) /
V_6 -> V_245 . V_246 ;
V_33 -> V_239 = 0 ;
V_33 -> V_83 = V_79 ;
V_33 -> V_113 = F_129 ( V_2 ) ;
V_6 -> V_245 . V_306 = V_6 -> V_245 . V_246 ;
V_6 -> V_245 . V_246 = 0 ;
F_174 ( V_2 , V_6 -> V_307 ) ;
F_70 ( F_71 ( V_2 ) , V_308 ) ;
}
void F_175 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_69 = F_176 ( V_2 ) ;
T_1 V_309 = V_33 -> V_143 ;
F_131 (skb, sk) {
if ( V_4 == F_108 ( V_2 ) )
break;
if ( F_96 ( V_4 ) > V_69 &&
! ( F_18 ( V_4 ) -> V_145 & V_147 ) ) {
if ( F_18 ( V_4 ) -> V_145 & V_177 ) {
F_18 ( V_4 ) -> V_145 &= ~ V_177 ;
V_33 -> V_178 -= F_76 ( V_4 ) ;
}
F_77 ( V_33 , V_4 ) ;
}
}
F_177 ( V_33 ) ;
if ( V_309 == V_33 -> V_143 )
return;
if ( F_69 ( V_33 ) )
F_121 ( V_33 ) ;
F_119 ( V_33 ) ;
if ( V_6 -> V_135 != V_224 ) {
V_33 -> V_179 = V_33 -> V_110 ;
V_33 -> V_113 = F_129 ( V_2 ) ;
V_33 -> V_235 = 0 ;
V_33 -> V_138 = 0 ;
F_132 ( V_2 , V_224 ) ;
}
F_178 ( V_2 ) ;
}
static void F_179 ( struct V_1 * V_2 , bool V_310 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_128 ;
if ( F_69 ( V_33 ) )
V_128 = V_311 ;
else
V_128 = V_312 ;
F_70 ( F_71 ( V_2 ) , V_128 ) ;
V_33 -> V_235 = 0 ;
F_127 ( V_33 ) ;
if ( ! F_180 ( V_2 ) ) {
if ( ! V_310 )
V_33 -> V_235 = F_129 ( V_2 ) ;
F_163 ( V_2 ) ;
}
F_132 ( V_2 , V_231 ) ;
}
static void F_181 ( struct V_1 * V_2 , int V_180 , bool V_313 ,
int * V_314 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
bool V_315 = ! F_48 ( V_33 -> V_108 , V_33 -> V_179 ) ;
if ( ( V_180 & V_316 ) &&
F_162 ( V_2 , false ) )
return;
if ( V_33 -> V_243 ) {
if ( ( V_180 & V_181 ) &&
F_162 ( V_2 , true ) )
return;
if ( F_55 ( V_33 -> V_110 , V_33 -> V_179 ) ) {
if ( V_180 & V_185 || V_313 )
V_33 -> V_243 = 0 ;
} else if ( V_180 & V_316 && ! V_315 ) {
V_33 -> V_179 = V_33 -> V_110 ;
if ( F_108 ( V_2 ) &&
F_55 ( F_182 ( V_33 ) , V_33 -> V_110 ) ) {
* V_314 = V_317 ;
return;
}
V_33 -> V_243 = 0 ;
}
}
if ( V_315 ) {
F_160 ( V_2 ) ;
return;
}
if ( F_69 ( V_33 ) ) {
if ( F_55 ( V_33 -> V_110 , V_33 -> V_179 ) && V_313 )
F_123 ( V_2 ) ;
else if ( V_180 & V_316 )
F_125 ( V_33 ) ;
}
* V_314 = V_318 ;
}
static bool F_183 ( struct V_1 * V_2 , const int V_228 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_33 -> V_138 && F_150 ( V_33 ) ) {
F_68 ( V_2 , F_137 ( V_33 ) + V_228 , 1 ) ;
if ( V_33 -> V_178 )
return true ;
if ( ! F_151 ( V_2 ) )
V_33 -> V_270 = 0 ;
F_152 ( V_2 , L_8 ) ;
F_158 ( V_2 , true ) ;
F_70 ( F_71 ( V_2 ) , V_319 ) ;
F_169 ( V_2 ) ;
return true ;
}
return false ;
}
static void F_184 ( struct V_1 * V_2 , const int V_228 ,
bool V_313 , int * V_320 , int * V_314 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_266 = 0 , V_180 = * V_320 ;
bool V_321 = V_313 || ( ( V_180 & V_185 ) &&
( F_137 ( V_33 ) > V_33 -> V_59 ) ) ;
if ( F_116 ( ! V_33 -> V_116 && V_33 -> V_137 ) )
V_33 -> V_137 = 0 ;
if ( F_116 ( ! V_33 -> V_137 && V_33 -> V_136 ) )
V_33 -> V_136 = 0 ;
if ( V_180 & V_252 )
V_33 -> V_235 = 0 ;
if ( F_133 ( V_2 , V_180 ) )
return;
F_119 ( V_33 ) ;
if ( V_6 -> V_135 == V_287 ) {
F_116 ( V_33 -> V_178 != 0 ) ;
V_33 -> V_270 = 0 ;
} else if ( ! F_48 ( V_33 -> V_108 , V_33 -> V_179 ) ) {
switch ( V_6 -> V_135 ) {
case V_301 :
if ( V_33 -> V_108 != V_33 -> V_179 ) {
F_167 ( V_2 ) ;
F_132 ( V_2 , V_287 ) ;
}
break;
case V_231 :
if ( F_69 ( V_33 ) )
F_125 ( V_33 ) ;
if ( F_160 ( V_2 ) )
return;
F_167 ( V_2 ) ;
break;
}
}
if ( V_322 & V_323 &&
F_185 ( V_2 ) ) {
V_180 |= V_300 ;
* V_320 |= V_300 ;
}
switch ( V_6 -> V_135 ) {
case V_231 :
if ( ! ( V_180 & V_316 ) ) {
if ( F_69 ( V_33 ) && V_313 )
F_123 ( V_2 ) ;
} else {
if ( F_183 ( V_2 , V_228 ) )
return;
V_321 = F_69 ( V_33 ) ||
F_137 ( V_33 ) > V_33 -> V_59 ;
}
if ( F_161 ( V_2 ) ) {
F_169 ( V_2 ) ;
return;
}
break;
case V_224 :
F_181 ( V_2 , V_180 , V_313 , V_314 ) ;
if ( V_6 -> V_135 != V_287 &&
! ( V_180 & V_300 ) )
return;
default:
if ( F_69 ( V_33 ) ) {
if ( V_180 & V_316 )
F_125 ( V_33 ) ;
if ( V_313 )
F_123 ( V_2 ) ;
}
if ( V_6 -> V_135 <= V_233 )
F_161 ( V_2 ) ;
if ( ! F_141 ( V_2 , V_180 ) ) {
F_170 ( V_2 , V_180 ) ;
return;
}
if ( V_6 -> V_135 < V_301 &&
V_6 -> V_245 . V_246 &&
V_33 -> V_108 == V_33 -> V_324 . V_325 ) {
F_171 ( V_2 ) ;
V_33 -> V_58 ++ ;
F_175 ( V_2 ) ;
return;
}
F_179 ( V_2 , ( V_180 & V_252 ) ) ;
V_266 = 1 ;
}
if ( V_321 )
F_146 ( V_2 , V_266 ) ;
* V_314 = V_318 ;
}
static void F_186 ( struct V_1 * V_2 , T_1 V_326 )
{
const T_1 V_99 = V_79 , V_327 = V_328 * V_329 ;
struct V_330 * V_91 = F_7 ( V_2 ) -> V_331 ;
struct V_330 V_332 = {
. V_90 = F_58 ( V_326 ) ? V_326 : F_187 ( 1 ) ,
. V_127 = V_99 ,
} ;
T_1 V_333 ;
if ( F_102 ( V_332 . V_90 <= V_91 [ 0 ] . V_90 ) )
V_91 [ 0 ] = V_91 [ 1 ] = V_91 [ 2 ] = V_332 ;
else if ( V_332 . V_90 <= V_91 [ 1 ] . V_90 )
V_91 [ 1 ] = V_91 [ 2 ] = V_332 ;
else if ( V_332 . V_90 <= V_91 [ 2 ] . V_90 )
V_91 [ 2 ] = V_332 ;
V_333 = V_99 - V_91 [ 0 ] . V_127 ;
if ( F_102 ( V_333 > V_327 ) ) {
V_91 [ 0 ] = V_91 [ 1 ] ;
V_91 [ 1 ] = V_91 [ 2 ] ;
V_91 [ 2 ] = V_332 ;
if ( V_99 - V_91 [ 0 ] . V_127 > V_327 ) {
V_91 [ 0 ] = V_91 [ 1 ] ;
V_91 [ 1 ] = V_332 ;
if ( V_99 - V_91 [ 0 ] . V_127 > V_327 )
V_91 [ 0 ] = V_332 ;
}
} else if ( V_91 [ 1 ] . V_127 == V_91 [ 0 ] . V_127 && V_333 > V_327 / 4 ) {
V_91 [ 2 ] = V_91 [ 1 ] = V_332 ;
} else if ( V_91 [ 2 ] . V_127 == V_91 [ 1 ] . V_127 && V_333 > V_327 / 2 ) {
V_91 [ 2 ] = V_332 ;
}
}
static inline bool F_188 ( struct V_1 * V_2 , const int V_180 ,
long V_334 , long V_335 ,
long V_336 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_334 < 0 )
V_334 = V_335 ;
if ( V_334 < 0 && V_33 -> V_52 . V_269 && V_33 -> V_52 . V_94 &&
V_180 & V_337 )
V_334 = V_336 = F_187 ( V_79 -
V_33 -> V_52 . V_94 ) ;
if ( V_334 < 0 )
return false ;
F_186 ( V_2 , V_336 ) ;
F_54 ( V_2 , V_334 ) ;
F_61 ( V_2 ) ;
F_2 ( V_2 ) -> V_338 = 0 ;
return true ;
}
void F_189 ( struct V_1 * V_2 , struct V_339 * V_340 )
{
long V_326 = - 1L ;
if ( V_340 && ! V_340 -> V_341 && F_190 ( V_340 ) -> V_342 . V_183 ) {
struct V_173 V_99 ;
F_191 ( & V_99 ) ;
V_326 = F_192 ( & V_99 , & F_190 ( V_340 ) -> V_342 ) ;
}
F_188 ( V_2 , V_343 , V_326 , - 1L , V_326 ) ;
}
static void F_193 ( struct V_1 * V_2 , T_1 V_344 , T_1 V_228 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_236 -> V_345 ( V_2 , V_344 , V_228 ) ;
F_7 ( V_2 ) -> V_83 = V_79 ;
}
void F_194 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_33 -> V_346 )
return;
if ( ! V_33 -> V_116 ) {
F_195 ( V_2 , V_249 ) ;
} else {
T_1 V_347 = F_2 ( V_2 ) -> V_101 ;
if ( V_6 -> V_348 == V_255 ||
V_6 -> V_348 == V_349 ) {
struct V_3 * V_4 = F_103 ( V_2 ) ;
const T_1 V_350 =
F_149 ( V_4 ) + V_347 ;
T_5 V_297 = ( T_5 ) ( V_350 - V_79 ) ;
if ( V_297 > 0 )
V_347 = V_297 ;
}
F_136 ( V_2 , V_249 , V_347 ,
V_250 ) ;
}
}
void F_196 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
F_194 ( V_2 ) ;
if ( ! V_33 -> V_259 )
return;
F_179 ( V_2 , false ) ;
F_146 ( V_2 , 1 ) ;
F_178 ( V_2 ) ;
}
static T_1 F_197 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_1 V_351 ;
F_89 ( ! F_55 ( F_18 ( V_4 ) -> V_95 , V_33 -> V_108 ) ) ;
V_351 = F_76 ( V_4 ) ;
if ( F_198 ( V_2 , V_4 , V_33 -> V_108 - F_18 ( V_4 ) -> V_80 ) )
return 0 ;
V_351 -= F_76 ( V_4 ) ;
if ( V_351 ) {
F_89 ( F_76 ( V_4 ) == 0 ) ;
F_89 ( ! F_48 ( F_18 ( V_4 ) -> V_80 , F_18 ( V_4 ) -> V_95 ) ) ;
}
return V_351 ;
}
static void F_199 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_155 )
{
const struct V_56 * V_352 ;
if ( F_58 ( ! F_18 ( V_4 ) -> V_353 ) )
return;
V_352 = F_3 ( V_4 ) ;
if ( ! F_48 ( V_352 -> V_354 , V_155 ) &&
F_48 ( V_352 -> V_354 , F_7 ( V_2 ) -> V_108 ) )
F_200 ( V_4 , NULL , V_2 , V_355 ) ;
}
static int F_201 ( struct V_1 * V_2 , int V_356 ,
T_1 V_155 , int * V_228 ,
struct V_170 * V_357 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_173 V_358 , V_359 , V_99 ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_1 V_227 = V_33 -> V_137 ;
T_1 V_141 = V_33 -> V_116 ;
bool V_360 = true ;
long V_335 = - 1L ;
long V_334 = - 1L ;
long V_336 = - 1L ;
struct V_3 * V_4 ;
T_1 V_361 = 0 ;
bool V_362 ;
int V_180 = 0 ;
V_358 . V_183 = 0 ;
while ( ( V_4 = F_103 ( V_2 ) ) && V_4 != F_108 ( V_2 ) ) {
struct V_363 * V_364 = F_18 ( V_4 ) ;
T_4 V_145 = V_364 -> V_145 ;
T_1 V_365 ;
F_199 ( V_2 , V_4 , V_155 ) ;
if ( F_55 ( V_364 -> V_95 , V_33 -> V_108 ) ) {
if ( F_76 ( V_4 ) == 1 ||
! F_55 ( V_33 -> V_108 , V_364 -> V_80 ) )
break;
V_365 = F_197 ( V_2 , V_4 ) ;
if ( ! V_365 )
break;
V_360 = false ;
} else {
F_202 ( V_4 -> V_366 ) ;
V_365 = F_76 ( V_4 ) ;
}
if ( F_102 ( V_145 & V_176 ) ) {
if ( V_145 & V_177 )
V_33 -> V_178 -= V_365 ;
V_180 |= V_299 ;
} else if ( ! ( V_145 & V_147 ) ) {
V_359 = V_4 -> V_173 ;
F_165 ( V_359 . V_183 == 0 ) ;
if ( ! V_358 . V_183 )
V_358 = V_359 ;
V_141 = F_9 ( V_361 , V_141 ) ;
if ( ! F_55 ( V_364 -> V_95 , V_33 -> V_179 ) )
V_180 |= V_181 ;
}
if ( V_145 & V_147 ) {
V_33 -> V_137 -= V_365 ;
} else if ( F_144 ( V_33 ) ) {
V_33 -> V_186 += V_365 ;
if ( ! F_148 ( V_33 , V_4 ) )
F_85 ( V_33 , & V_4 -> V_173 , V_145 ) ;
}
if ( V_145 & V_146 )
V_33 -> V_143 -= V_365 ;
V_33 -> V_116 -= V_365 ;
V_361 += V_365 ;
if ( F_58 ( ! ( V_364 -> V_193 & V_367 ) ) ) {
V_180 |= V_368 ;
} else {
V_180 |= V_343 ;
V_33 -> V_270 = 0 ;
}
if ( ! V_360 )
break;
F_94 ( V_4 , V_2 ) ;
F_95 ( V_2 , V_4 ) ;
if ( F_102 ( V_4 == V_33 -> V_142 ) )
V_33 -> V_142 = NULL ;
if ( F_102 ( V_4 == V_33 -> V_122 ) )
V_33 -> V_122 = NULL ;
}
if ( F_58 ( F_203 ( V_33 -> V_369 , V_155 , V_33 -> V_108 ) ) )
V_33 -> V_369 = V_33 -> V_108 ;
if ( V_4 && ( F_18 ( V_4 ) -> V_145 & V_147 ) )
V_180 |= V_247 ;
F_191 ( & V_99 ) ;
if ( F_58 ( V_358 . V_183 ) && ! ( V_180 & V_299 ) ) {
V_334 = F_192 ( & V_99 , & V_358 ) ;
V_336 = F_192 ( & V_99 , & V_359 ) ;
}
if ( V_357 -> V_182 . V_183 ) {
V_335 = F_192 ( & V_99 , & V_357 -> V_182 ) ;
V_336 = F_192 ( & V_99 , & V_357 -> V_184 ) ;
}
V_362 = F_188 ( V_2 , V_180 , V_334 , V_335 ,
V_336 ) ;
if ( V_180 & V_337 ) {
F_194 ( V_2 ) ;
if ( F_102 ( V_6 -> V_245 . V_246 &&
! F_55 ( V_33 -> V_324 . V_370 , V_33 -> V_108 ) ) ) {
F_172 ( V_2 ) ;
}
if ( F_69 ( V_33 ) ) {
F_124 ( V_2 , V_361 ) ;
} else {
int V_297 ;
if ( V_141 < V_356 )
F_68 ( V_2 , V_33 -> V_136 - V_141 , 0 ) ;
V_297 = F_66 ( V_33 ) ? V_361 :
V_227 - V_33 -> V_137 ;
V_33 -> V_187 -= F_9 ( V_33 -> V_187 , V_297 ) ;
}
V_33 -> V_136 -= F_9 ( V_361 , V_33 -> V_136 ) ;
} else if ( V_4 && V_362 && V_335 >= 0 &&
V_335 > F_192 ( & V_99 , & V_4 -> V_173 ) ) {
F_194 ( V_2 ) ;
}
if ( V_6 -> V_236 -> V_361 ) {
struct V_371 V_86 = { . V_361 = V_361 ,
. V_326 = V_336 } ;
V_6 -> V_236 -> V_361 ( V_2 , & V_86 ) ;
}
#if V_134 > 0
F_116 ( ( int ) V_33 -> V_137 < 0 ) ;
F_116 ( ( int ) V_33 -> V_143 < 0 ) ;
F_116 ( ( int ) V_33 -> V_178 < 0 ) ;
if ( ! V_33 -> V_116 && F_144 ( V_33 ) ) {
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
* V_228 = V_361 ;
return V_180 ;
}
static void F_204 ( struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_55 ( F_18 ( F_108 ( V_2 ) ) -> V_95 , F_182 ( V_33 ) ) ) {
V_6 -> V_338 = 0 ;
F_195 ( V_2 , V_372 ) ;
} else {
unsigned long V_268 = F_205 ( V_2 , V_250 ) ;
F_136 ( V_2 , V_372 ,
V_268 , V_250 ) ;
}
}
static inline bool F_206 ( const struct V_1 * V_2 , const int V_180 )
{
return ! ( V_180 & V_373 ) || ( V_180 & V_374 ) ||
F_2 ( V_2 ) -> V_135 != V_287 ;
}
static inline bool F_207 ( const struct V_1 * V_2 , const int V_180 )
{
if ( F_7 ( V_2 ) -> V_59 > F_71 ( V_2 ) -> V_241 . V_242 )
return V_180 & V_375 ;
return V_180 & V_368 ;
}
static void F_208 ( struct V_1 * V_2 , T_1 V_344 , T_1 V_376 ,
int V_180 )
{
if ( F_180 ( V_2 ) ) {
F_164 ( V_2 , V_376 , V_180 ) ;
} else if ( F_207 ( V_2 , V_180 ) ) {
F_193 ( V_2 , V_344 , V_376 ) ;
}
F_57 ( V_2 ) ;
}
static inline bool F_209 ( const struct V_32 * V_33 ,
const T_1 V_344 , const T_1 V_159 ,
const T_1 V_377 )
{
return F_55 ( V_344 , V_33 -> V_108 ) ||
F_55 ( V_159 , V_33 -> V_378 ) ||
( V_159 == V_33 -> V_378 && V_377 > V_33 -> V_379 ) ;
}
static void F_210 ( struct V_32 * V_33 , T_1 V_344 )
{
T_1 V_297 = V_344 - V_33 -> V_108 ;
F_211 ( (struct V_1 * ) V_33 ) ;
F_212 ( & V_33 -> V_380 ) ;
V_33 -> V_381 += V_297 ;
F_213 ( & V_33 -> V_380 ) ;
V_33 -> V_108 = V_344 ;
}
static void F_214 ( struct V_32 * V_33 , T_1 V_80 )
{
T_1 V_297 = V_80 - V_33 -> V_93 ;
F_211 ( (struct V_1 * ) V_33 ) ;
F_212 ( & V_33 -> V_380 ) ;
V_33 -> V_382 += V_297 ;
F_213 ( & V_33 -> V_380 ) ;
V_33 -> V_93 = V_80 ;
}
static int F_215 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_1 V_344 ,
T_1 V_159 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_180 = 0 ;
T_1 V_377 = F_154 ( F_6 ( V_4 ) -> V_63 ) ;
if ( F_58 ( ! F_6 ( V_4 ) -> V_48 ) )
V_377 <<= V_33 -> V_52 . V_383 ;
if ( F_209 ( V_33 , V_344 , V_159 , V_377 ) ) {
V_180 |= V_384 ;
F_216 ( V_33 , V_159 ) ;
if ( V_33 -> V_379 != V_377 ) {
V_33 -> V_379 = V_377 ;
V_33 -> V_385 = 0 ;
F_217 ( V_2 ) ;
if ( F_108 ( V_2 ) )
F_218 ( V_2 ) ;
if ( V_377 > V_33 -> V_150 ) {
V_33 -> V_150 = V_377 ;
F_174 ( V_2 , F_2 ( V_2 ) -> V_307 ) ;
}
}
}
F_210 ( V_33 , V_344 ) ;
return V_180 ;
}
static bool F_219 ( struct V_229 * V_229 , int V_128 ,
T_1 * V_386 )
{
if ( * V_386 ) {
T_5 V_333 = ( T_5 ) ( V_79 - * V_386 ) ;
if ( 0 <= V_333 && V_333 < V_387 ) {
F_70 ( V_229 , V_128 ) ;
return true ;
}
}
* V_386 = V_79 ;
return false ;
}
bool F_220 ( struct V_229 * V_229 , const struct V_3 * V_4 ,
int V_128 , T_1 * V_386 )
{
if ( ( F_18 ( V_4 ) -> V_80 != F_18 ( V_4 ) -> V_95 ) &&
! F_6 ( V_4 ) -> V_48 )
return false ;
return F_219 ( V_229 , V_128 , V_386 ) ;
}
static void F_221 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
static T_1 V_388 ;
static unsigned int V_389 ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_1 V_390 , V_99 ;
if ( F_219 ( F_71 ( V_2 ) ,
V_391 ,
& V_33 -> V_386 ) )
return;
V_99 = V_254 / V_329 ;
if ( V_99 != V_388 ) {
T_1 V_392 = ( V_393 + 1 ) >> 1 ;
V_388 = V_99 ;
F_222 ( V_389 , V_392 +
F_223 ( V_393 ) ) ;
}
V_390 = F_224 ( V_389 ) ;
if ( V_390 > 0 ) {
F_222 ( V_389 , V_390 - 1 ) ;
F_70 ( F_71 ( V_2 ) , V_394 ) ;
F_225 ( V_2 ) ;
}
}
static void F_226 ( struct V_32 * V_33 )
{
V_33 -> V_52 . V_395 = V_33 -> V_52 . V_396 ;
V_33 -> V_52 . V_397 = F_227 () ;
}
static void F_228 ( struct V_32 * V_33 , T_1 V_80 )
{
if ( V_33 -> V_52 . V_269 && ! F_55 ( V_80 , V_33 -> V_398 ) ) {
if ( F_229 ( & V_33 -> V_52 , 0 ) )
F_226 ( V_33 ) ;
}
}
static void F_230 ( struct V_1 * V_2 , T_1 V_344 , int V_180 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_48 ( V_344 , V_33 -> V_291 ) )
return;
if ( V_180 & V_218 ) {
V_33 -> V_291 = 0 ;
} else if ( F_55 ( V_344 , V_33 -> V_291 ) ) {
F_163 ( V_2 ) ;
F_132 ( V_2 , V_301 ) ;
F_167 ( V_2 ) ;
F_169 ( V_2 ) ;
F_70 ( F_71 ( V_2 ) ,
V_399 ) ;
} else if ( ! ( V_180 & ( V_316 |
V_373 | V_185 ) ) ) {
V_33 -> V_291 = 0 ;
}
}
static inline void F_231 ( struct V_1 * V_2 , T_1 V_400 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_236 -> V_401 )
V_6 -> V_236 -> V_401 ( V_2 , V_400 ) ;
}
static void F_232 ( struct V_1 * V_2 , int V_314 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_314 == V_402 )
return;
if ( F_102 ( V_314 == 2 ) ) {
F_233 ( V_2 , F_176 ( V_2 ) ,
V_403 ) ;
if ( F_55 ( V_33 -> V_110 , V_33 -> V_179 ) )
return;
V_33 -> V_243 = 0 ;
}
F_178 ( V_2 ) ;
}
static int F_234 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_180 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_170 V_404 ;
T_1 V_155 = V_33 -> V_108 ;
T_1 V_159 = F_18 ( V_4 ) -> V_80 ;
T_1 V_344 = F_18 ( V_4 ) -> V_159 ;
bool V_313 = false ;
T_1 V_356 ;
int V_405 = V_33 -> V_116 ;
T_1 V_406 = V_33 -> V_186 ;
int V_228 = 0 ;
int V_314 = V_402 ;
V_404 . V_182 . V_183 = 0 ;
F_202 ( V_2 -> V_407 . V_366 ) ;
if ( F_48 ( V_344 , V_155 ) ) {
if ( F_48 ( V_344 , V_155 - V_33 -> V_150 ) ) {
F_221 ( V_2 , V_4 ) ;
return - 1 ;
}
goto V_408;
}
if ( F_55 ( V_344 , V_33 -> V_110 ) )
goto V_409;
if ( V_6 -> V_348 == V_255 ||
V_6 -> V_348 == V_349 )
F_194 ( V_2 ) ;
if ( F_55 ( V_344 , V_155 ) ) {
V_180 |= V_316 ;
V_6 -> V_234 = 0 ;
}
V_356 = V_33 -> V_136 ;
if ( V_180 & V_410 )
F_228 ( V_33 , F_18 ( V_4 ) -> V_80 ) ;
if ( ! ( V_180 & V_411 ) && F_55 ( V_344 , V_155 ) ) {
F_216 ( V_33 , V_159 ) ;
F_210 ( V_33 , V_344 ) ;
V_180 |= V_384 ;
F_231 ( V_2 , V_412 ) ;
F_70 ( F_71 ( V_2 ) , V_413 ) ;
} else {
T_1 V_414 = V_415 ;
if ( V_159 != F_18 ( V_4 ) -> V_95 )
V_180 |= V_416 ;
else
F_70 ( F_71 ( V_2 ) , V_417 ) ;
V_180 |= F_215 ( V_2 , V_4 , V_344 , V_159 ) ;
if ( F_18 ( V_4 ) -> V_145 )
V_180 |= F_115 ( V_2 , V_4 , V_155 ,
& V_404 ) ;
if ( F_24 ( V_33 , F_6 ( V_4 ) ) ) {
V_180 |= V_252 ;
V_414 |= V_418 ;
}
if ( V_180 & V_384 )
V_414 |= V_412 ;
F_231 ( V_2 , V_414 ) ;
}
V_2 -> V_419 = 0 ;
V_6 -> V_420 = 0 ;
V_33 -> V_421 = V_79 ;
if ( ! V_405 )
goto V_422;
V_180 |= F_201 ( V_2 , V_356 , V_155 , & V_228 ,
& V_404 ) ;
if ( F_206 ( V_2 , V_180 ) ) {
V_313 = ! ( V_180 & ( V_316 | V_373 ) ) ;
F_184 ( V_2 , V_228 , V_313 , & V_180 , & V_314 ) ;
}
if ( V_33 -> V_291 )
F_230 ( V_2 , V_344 , V_180 ) ;
if ( ( V_180 & V_375 ) || ! ( V_180 & V_373 ) ) {
struct V_29 * V_30 = F_12 ( V_2 ) ;
if ( V_30 )
F_235 ( V_30 ) ;
}
if ( V_6 -> V_348 == V_249 )
F_236 ( V_2 ) ;
F_208 ( V_2 , V_344 , V_33 -> V_186 - V_406 , V_180 ) ;
F_232 ( V_2 , V_314 ) ;
return 1 ;
V_422:
if ( V_180 & V_218 )
F_184 ( V_2 , V_228 , V_313 , & V_180 , & V_314 ) ;
if ( F_108 ( V_2 ) )
F_204 ( V_2 ) ;
if ( V_33 -> V_291 )
F_230 ( V_2 , V_344 , V_180 ) ;
return 1 ;
V_409:
F_237 ( V_2 , L_12 , V_344 , V_33 -> V_108 , V_33 -> V_110 ) ;
return - 1 ;
V_408:
if ( F_18 ( V_4 ) -> V_145 ) {
V_180 |= F_115 ( V_2 , V_4 , V_155 ,
& V_404 ) ;
F_184 ( V_2 , V_228 , V_313 , & V_180 , & V_314 ) ;
F_232 ( V_2 , V_314 ) ;
}
F_237 ( V_2 , L_13 , V_344 , V_33 -> V_108 , V_33 -> V_110 ) ;
return 0 ;
}
static void F_238 ( int V_10 , const unsigned char * V_423 ,
bool V_48 , struct V_424 * V_425 ,
bool V_426 )
{
if ( ! V_425 || ! V_48 || V_10 < 0 || ( V_10 & 1 ) )
return;
if ( V_10 >= V_427 &&
V_10 <= V_428 )
memcpy ( V_425 -> V_429 , V_423 , V_10 ) ;
else if ( V_10 != 0 )
V_10 = - 1 ;
V_425 -> V_10 = V_10 ;
V_425 -> exp = V_426 ;
}
void F_239 ( const struct V_3 * V_4 ,
struct V_430 * V_431 , int V_432 ,
struct V_424 * V_425 )
{
const unsigned char * V_209 ;
const struct V_15 * V_46 = F_6 ( V_4 ) ;
int V_433 = ( V_46 -> V_434 * 4 ) - sizeof( struct V_15 ) ;
V_209 = ( const unsigned char * ) ( V_46 + 1 ) ;
V_431 -> V_269 = 0 ;
while ( V_433 > 0 ) {
int V_435 = * V_209 ++ ;
int V_436 ;
switch ( V_435 ) {
case V_437 :
return;
case V_438 :
V_433 -- ;
continue;
default:
V_436 = * V_209 ++ ;
if ( V_436 < 2 )
return;
if ( V_436 > V_433 )
return;
switch ( V_435 ) {
case V_439 :
if ( V_436 == V_440 && V_46 -> V_48 && ! V_432 ) {
T_6 V_441 = F_240 ( V_209 ) ;
if ( V_441 ) {
if ( V_431 -> V_442 &&
V_431 -> V_442 < V_441 )
V_441 = V_431 -> V_442 ;
V_431 -> V_53 = V_441 ;
}
}
break;
case V_443 :
if ( V_436 == V_444 && V_46 -> V_48 &&
! V_432 && V_445 ) {
T_7 V_383 = * ( T_7 * ) V_209 ;
V_431 -> V_446 = 1 ;
if ( V_383 > 14 ) {
F_241 ( L_14 ,
V_447 ,
V_383 ) ;
V_383 = 14 ;
}
V_431 -> V_383 = V_383 ;
}
break;
case V_448 :
if ( ( V_436 == V_449 ) &&
( ( V_432 && V_431 -> V_450 ) ||
( ! V_432 && V_451 ) ) ) {
V_431 -> V_269 = 1 ;
V_431 -> V_396 = F_80 ( V_209 ) ;
V_431 -> V_94 = F_80 ( V_209 + 4 ) ;
}
break;
case V_452 :
if ( V_436 == V_453 && V_46 -> V_48 &&
! V_432 && V_454 ) {
V_431 -> V_123 = V_455 ;
F_242 ( V_431 ) ;
}
break;
case V_456 :
if ( ( V_436 >= ( V_212 + V_457 ) ) &&
! ( ( V_436 - V_212 ) % V_457 ) &&
V_431 -> V_123 ) {
F_18 ( V_4 ) -> V_145 = ( V_209 - 2 ) - ( unsigned char * ) V_46 ;
}
break;
#ifdef F_243
case V_458 :
break;
#endif
case V_459 :
F_238 (
V_436 - V_460 ,
V_209 , V_46 -> V_48 , V_425 , false ) ;
break;
case V_461 :
if ( V_436 >= V_462 &&
F_240 ( V_209 ) ==
V_463 )
F_238 ( V_436 -
V_462 ,
V_209 + 2 , V_46 -> V_48 , V_425 , true ) ;
break;
}
V_209 += V_436 - 2 ;
V_433 -= V_436 ;
}
}
}
static bool F_244 ( struct V_32 * V_33 , const struct V_15 * V_46 )
{
const T_8 * V_209 = ( const T_8 * ) ( V_46 + 1 ) ;
if ( * V_209 == F_245 ( ( V_438 << 24 ) | ( V_438 << 16 )
| ( V_448 << 8 ) | V_449 ) ) {
V_33 -> V_52 . V_269 = 1 ;
++ V_209 ;
V_33 -> V_52 . V_396 = F_246 ( * V_209 ) ;
++ V_209 ;
if ( * V_209 )
V_33 -> V_52 . V_94 = F_246 ( * V_209 ) - V_33 -> V_464 ;
else
V_33 -> V_52 . V_94 = 0 ;
return true ;
}
return false ;
}
static bool F_247 ( const struct V_3 * V_4 ,
const struct V_15 * V_46 , struct V_32 * V_33 )
{
if ( V_46 -> V_434 == ( sizeof( * V_46 ) / 4 ) ) {
V_33 -> V_52 . V_269 = 0 ;
return false ;
} else if ( V_33 -> V_52 . V_450 &&
V_46 -> V_434 == ( ( sizeof( * V_46 ) + V_465 ) / 4 ) ) {
if ( F_244 ( V_33 , V_46 ) )
return true ;
}
F_239 ( V_4 , & V_33 -> V_52 , 1 , NULL ) ;
if ( V_33 -> V_52 . V_269 && V_33 -> V_52 . V_94 )
V_33 -> V_52 . V_94 -= V_33 -> V_464 ;
return true ;
}
const T_4 * F_248 ( const struct V_15 * V_46 )
{
int V_433 = ( V_46 -> V_434 << 2 ) - sizeof( * V_46 ) ;
const T_4 * V_209 = ( const T_4 * ) ( V_46 + 1 ) ;
if ( V_433 < V_466 )
return NULL ;
while ( V_433 > 0 ) {
int V_435 = * V_209 ++ ;
int V_436 ;
switch ( V_435 ) {
case V_437 :
return NULL ;
case V_438 :
V_433 -- ;
continue;
default:
V_436 = * V_209 ++ ;
if ( V_436 < 2 || V_436 > V_433 )
return NULL ;
if ( V_435 == V_458 )
return V_436 == V_466 ? V_209 : NULL ;
}
V_209 += V_436 - 2 ;
V_433 -= V_436 ;
}
return NULL ;
}
static int F_249 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
const struct V_15 * V_46 = F_6 ( V_4 ) ;
T_1 V_80 = F_18 ( V_4 ) -> V_80 ;
T_1 V_344 = F_18 ( V_4 ) -> V_159 ;
return (
( V_46 -> V_344 && V_80 == F_18 ( V_4 ) -> V_95 && V_80 == V_33 -> V_93 ) &&
V_344 == V_33 -> V_108 &&
! F_209 ( V_33 , V_344 , V_80 , F_154 ( V_46 -> V_63 ) << V_33 -> V_52 . V_383 ) &&
( T_5 ) ( V_33 -> V_52 . V_395 - V_33 -> V_52 . V_396 ) <= ( F_2 ( V_2 ) -> V_101 * 1024 ) / V_329 ) ;
}
static inline bool F_250 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
return ! F_229 ( & V_33 -> V_52 , V_467 ) &&
! F_249 ( V_2 , V_4 ) ;
}
static inline bool F_251 ( const struct V_32 * V_33 , T_1 V_80 , T_1 V_95 )
{
return ! F_48 ( V_95 , V_33 -> V_398 ) &&
! F_55 ( V_80 , V_33 -> V_93 + F_252 ( V_33 ) ) ;
}
void F_253 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_468 ) {
case V_469 :
V_2 -> V_470 = V_471 ;
break;
case V_472 :
V_2 -> V_470 = V_473 ;
break;
case V_474 :
return;
default:
V_2 -> V_470 = V_475 ;
}
F_254 () ;
if ( ! F_255 ( V_2 , V_476 ) )
V_2 -> V_477 ( V_2 ) ;
F_256 ( V_2 ) ;
}
void F_257 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
F_52 ( V_2 ) ;
V_2 -> V_478 |= V_479 ;
F_258 ( V_2 , V_480 ) ;
switch ( V_2 -> V_468 ) {
case V_481 :
case V_482 :
F_259 ( V_2 , V_472 ) ;
F_2 ( V_2 ) -> V_8 . V_26 = 1 ;
break;
case V_472 :
case V_483 :
break;
case V_484 :
break;
case V_485 :
F_225 ( V_2 ) ;
F_259 ( V_2 , V_483 ) ;
break;
case V_486 :
F_225 ( V_2 ) ;
F_260 ( V_2 , V_487 , 0 ) ;
break;
default:
F_261 ( L_15 ,
V_447 , V_2 -> V_468 ) ;
break;
}
F_262 ( & V_33 -> V_488 ) ;
if ( F_144 ( V_33 ) )
F_242 ( & V_33 -> V_52 ) ;
F_53 ( V_2 ) ;
if ( ! F_255 ( V_2 , V_476 ) ) {
V_2 -> V_489 ( V_2 ) ;
if ( V_2 -> V_478 == V_490 ||
V_2 -> V_468 == V_474 )
F_263 ( V_2 , V_491 , V_492 ) ;
else
F_263 ( V_2 , V_491 , V_493 ) ;
}
}
static inline bool F_264 ( struct V_202 * V_153 , T_1 V_80 ,
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
static void F_265 ( struct V_1 * V_2 , T_1 V_80 , T_1 V_95 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_144 ( V_33 ) && V_494 ) {
int V_128 ;
if ( F_48 ( V_80 , V_33 -> V_93 ) )
V_128 = V_495 ;
else
V_128 = V_496 ;
F_70 ( F_71 ( V_2 ) , V_128 ) ;
V_33 -> V_52 . V_497 = 1 ;
V_33 -> V_498 [ 0 ] . V_149 = V_80 ;
V_33 -> V_498 [ 0 ] . V_95 = V_95 ;
}
}
static void F_266 ( struct V_1 * V_2 , T_1 V_80 , T_1 V_95 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( ! V_33 -> V_52 . V_497 )
F_265 ( V_2 , V_80 , V_95 ) ;
else
F_264 ( V_33 -> V_498 , V_80 , V_95 ) ;
}
static void F_267 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_18 ( V_4 ) -> V_95 != F_18 ( V_4 ) -> V_80 &&
F_48 ( F_18 ( V_4 ) -> V_80 , V_33 -> V_93 ) ) {
F_70 ( F_71 ( V_2 ) , V_499 ) ;
F_10 ( V_2 ) ;
if ( F_144 ( V_33 ) && V_494 ) {
T_1 V_95 = F_18 ( V_4 ) -> V_95 ;
if ( F_55 ( F_18 ( V_4 ) -> V_95 , V_33 -> V_93 ) )
V_95 = V_33 -> V_93 ;
F_265 ( V_2 , F_18 ( V_4 ) -> V_80 , V_95 ) ;
}
}
F_225 ( V_2 ) ;
}
static void F_268 ( struct V_32 * V_33 )
{
int V_500 ;
struct V_202 * V_153 = & V_33 -> V_501 [ 0 ] ;
struct V_202 * V_502 = V_153 + 1 ;
for ( V_500 = 1 ; V_500 < V_33 -> V_52 . V_154 ; ) {
if ( F_264 ( V_153 , V_502 -> V_149 , V_502 -> V_95 ) ) {
int V_215 ;
V_33 -> V_52 . V_154 -- ;
for ( V_215 = V_500 ; V_215 < V_33 -> V_52 . V_154 ; V_215 ++ )
V_153 [ V_215 ] = V_153 [ V_215 + 1 ] ;
continue;
}
V_500 ++ , V_502 ++ ;
}
}
static void F_269 ( struct V_1 * V_2 , T_1 V_80 , T_1 V_95 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_202 * V_153 = & V_33 -> V_501 [ 0 ] ;
int V_503 = V_33 -> V_52 . V_154 ;
int V_500 ;
if ( ! V_503 )
goto V_504;
for ( V_500 = 0 ; V_500 < V_503 ; V_500 ++ , V_153 ++ ) {
if ( F_264 ( V_153 , V_80 , V_95 ) ) {
for (; V_500 > 0 ; V_500 -- , V_153 -- )
F_118 ( * V_153 , * ( V_153 - 1 ) ) ;
if ( V_503 > 1 )
F_268 ( V_33 ) ;
return;
}
}
if ( V_500 >= V_211 ) {
V_500 -- ;
V_33 -> V_52 . V_154 -- ;
V_153 -- ;
}
for (; V_500 > 0 ; V_500 -- , V_153 -- )
* V_153 = * ( V_153 - 1 ) ;
V_504:
V_153 -> V_149 = V_80 ;
V_153 -> V_95 = V_95 ;
V_33 -> V_52 . V_154 ++ ;
}
static void F_270 ( struct V_32 * V_33 )
{
struct V_202 * V_153 = & V_33 -> V_501 [ 0 ] ;
int V_154 = V_33 -> V_52 . V_154 ;
int V_500 ;
if ( F_271 ( & V_33 -> V_488 ) ) {
V_33 -> V_52 . V_154 = 0 ;
return;
}
for ( V_500 = 0 ; V_500 < V_154 ; ) {
if ( ! F_48 ( V_33 -> V_93 , V_153 -> V_149 ) ) {
int V_215 ;
F_116 ( F_48 ( V_33 -> V_93 , V_153 -> V_95 ) ) ;
for ( V_215 = V_500 + 1 ; V_215 < V_154 ; V_215 ++ )
V_33 -> V_501 [ V_215 - 1 ] = V_33 -> V_501 [ V_215 ] ;
V_154 -- ;
continue;
}
V_500 ++ ;
V_153 ++ ;
}
V_33 -> V_52 . V_154 = V_154 ;
}
static bool F_272 ( struct V_1 * V_2 ,
struct V_3 * V_505 ,
struct V_3 * V_506 ,
bool * V_507 )
{
int V_297 ;
* V_507 = false ;
if ( F_18 ( V_506 ) -> V_80 != F_18 ( V_505 ) -> V_95 )
return false ;
if ( ! F_273 ( V_505 , V_506 , V_507 , & V_297 ) )
return false ;
F_274 ( V_297 , & V_2 -> V_84 ) ;
F_275 ( V_2 , V_297 ) ;
F_70 ( F_71 ( V_2 ) , V_508 ) ;
F_18 ( V_505 ) -> V_95 = F_18 ( V_506 ) -> V_95 ;
F_18 ( V_505 ) -> V_159 = F_18 ( V_506 ) -> V_159 ;
F_18 ( V_505 ) -> V_193 |= F_18 ( V_506 ) -> V_193 ;
return true ;
}
static void F_276 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_277 ( V_2 , V_4 ) ;
F_278 ( V_4 ) ;
}
static void F_279 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_3 V_509 = V_33 -> V_93 ;
struct V_3 * V_4 , * V_510 ;
bool V_507 , V_511 ;
while ( ( V_4 = F_280 ( & V_33 -> V_488 ) ) != NULL ) {
if ( F_55 ( F_18 ( V_4 ) -> V_80 , V_33 -> V_93 ) )
break;
if ( F_48 ( F_18 ( V_4 ) -> V_80 , V_509 ) ) {
T_3 V_497 = V_509 ;
if ( F_48 ( F_18 ( V_4 ) -> V_95 , V_509 ) )
V_509 = F_18 ( V_4 ) -> V_95 ;
F_266 ( V_2 , F_18 ( V_4 ) -> V_80 , V_497 ) ;
}
F_281 ( V_4 , & V_33 -> V_488 ) ;
if ( ! F_55 ( F_18 ( V_4 ) -> V_95 , V_33 -> V_93 ) ) {
F_237 ( V_2 , L_16 ) ;
F_276 ( V_2 , V_4 ) ;
continue;
}
F_237 ( V_2 , L_17 ,
V_33 -> V_93 , F_18 ( V_4 ) -> V_80 ,
F_18 ( V_4 ) -> V_95 ) ;
V_510 = F_282 ( & V_2 -> V_512 ) ;
V_511 = V_510 && F_272 ( V_2 , V_510 , V_4 , & V_507 ) ;
F_214 ( V_33 , F_18 ( V_4 ) -> V_95 ) ;
if ( ! V_511 )
F_283 ( & V_2 -> V_512 , V_4 ) ;
if ( F_18 ( V_4 ) -> V_193 & V_195 )
F_257 ( V_2 ) ;
if ( V_511 )
F_284 ( V_4 , V_507 ) ;
}
}
static int F_285 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_513 )
{
if ( F_43 ( & V_2 -> V_84 ) > V_2 -> V_72 ||
! F_286 ( V_2 , V_4 , V_513 ) ) {
if ( F_287 ( V_2 ) < 0 )
return - 1 ;
if ( ! F_286 ( V_2 , V_4 , V_513 ) ) {
if ( ! F_288 ( V_2 ) )
return - 1 ;
if ( ! F_286 ( V_2 , V_4 , V_513 ) )
return - 1 ;
}
}
return 0 ;
}
static void F_289 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_514 ;
T_1 V_80 , V_95 ;
F_21 ( V_33 , V_4 ) ;
if ( F_102 ( F_285 ( V_2 , V_4 , V_4 -> V_62 ) ) ) {
F_70 ( F_71 ( V_2 ) , V_515 ) ;
F_276 ( V_2 , V_4 ) ;
return;
}
V_33 -> V_385 = 0 ;
F_52 ( V_2 ) ;
F_70 ( F_71 ( V_2 ) , V_516 ) ;
F_237 ( V_2 , L_18 ,
V_33 -> V_93 , F_18 ( V_4 ) -> V_80 , F_18 ( V_4 ) -> V_95 ) ;
V_514 = F_282 ( & V_33 -> V_488 ) ;
if ( ! V_514 ) {
if ( F_144 ( V_33 ) ) {
V_33 -> V_52 . V_154 = 1 ;
V_33 -> V_501 [ 0 ] . V_149 = F_18 ( V_4 ) -> V_80 ;
V_33 -> V_501 [ 0 ] . V_95 =
F_18 ( V_4 ) -> V_95 ;
}
F_290 ( & V_33 -> V_488 , V_4 ) ;
goto V_517;
}
V_80 = F_18 ( V_4 ) -> V_80 ;
V_95 = F_18 ( V_4 ) -> V_95 ;
if ( V_80 == F_18 ( V_514 ) -> V_95 ) {
bool V_507 ;
if ( ! F_272 ( V_2 , V_514 , V_4 , & V_507 ) ) {
F_291 ( & V_33 -> V_488 , V_514 , V_4 ) ;
} else {
F_31 ( V_2 , V_4 ) ;
F_284 ( V_4 , V_507 ) ;
V_4 = NULL ;
}
if ( ! V_33 -> V_52 . V_154 ||
V_33 -> V_501 [ 0 ] . V_95 != V_80 )
goto V_518;
V_33 -> V_501 [ 0 ] . V_95 = V_95 ;
goto V_517;
}
while ( 1 ) {
if ( ! F_55 ( F_18 ( V_514 ) -> V_80 , V_80 ) )
break;
if ( F_292 ( & V_33 -> V_488 , V_514 ) ) {
V_514 = NULL ;
break;
}
V_514 = F_293 ( & V_33 -> V_488 , V_514 ) ;
}
if ( V_514 && F_48 ( V_80 , F_18 ( V_514 ) -> V_95 ) ) {
if ( ! F_55 ( V_95 , F_18 ( V_514 ) -> V_95 ) ) {
F_70 ( F_71 ( V_2 ) , V_519 ) ;
F_276 ( V_2 , V_4 ) ;
V_4 = NULL ;
F_265 ( V_2 , V_80 , V_95 ) ;
goto V_518;
}
if ( F_55 ( V_80 , F_18 ( V_514 ) -> V_80 ) ) {
F_265 ( V_2 , V_80 ,
F_18 ( V_514 ) -> V_95 ) ;
} else {
if ( F_292 ( & V_33 -> V_488 ,
V_514 ) )
V_514 = NULL ;
else
V_514 = F_293 (
& V_33 -> V_488 ,
V_514 ) ;
}
}
if ( ! V_514 )
F_290 ( & V_33 -> V_488 , V_4 ) ;
else
F_291 ( & V_33 -> V_488 , V_514 , V_4 ) ;
while ( ! F_294 ( & V_33 -> V_488 , V_4 ) ) {
V_514 = F_295 ( & V_33 -> V_488 , V_4 ) ;
if ( ! F_55 ( V_95 , F_18 ( V_514 ) -> V_80 ) )
break;
if ( F_48 ( V_95 , F_18 ( V_514 ) -> V_95 ) ) {
F_266 ( V_2 , F_18 ( V_514 ) -> V_80 ,
V_95 ) ;
break;
}
F_281 ( V_514 , & V_33 -> V_488 ) ;
F_266 ( V_2 , F_18 ( V_514 ) -> V_80 ,
F_18 ( V_514 ) -> V_95 ) ;
F_70 ( F_71 ( V_2 ) , V_519 ) ;
F_276 ( V_2 , V_514 ) ;
}
V_518:
if ( F_144 ( V_33 ) )
F_269 ( V_2 , V_80 , V_95 ) ;
V_517:
if ( V_4 ) {
F_31 ( V_2 , V_4 ) ;
F_296 ( V_4 , V_2 ) ;
}
}
static int T_9 F_297 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_520 ,
bool * V_507 )
{
int V_511 ;
struct V_3 * V_510 = F_282 ( & V_2 -> V_512 ) ;
F_298 ( V_4 , V_520 ) ;
V_511 = ( V_510 &&
F_272 ( V_2 , V_510 , V_4 , V_507 ) ) ? 1 : 0 ;
F_214 ( F_7 ( V_2 ) , F_18 ( V_4 ) -> V_95 ) ;
if ( ! V_511 ) {
F_283 ( & V_2 -> V_512 , V_4 ) ;
F_296 ( V_4 , V_2 ) ;
}
return V_511 ;
}
int F_299 ( struct V_1 * V_2 , struct V_521 * V_271 , T_10 V_513 )
{
struct V_3 * V_4 ;
int V_164 = - V_522 ;
int V_523 = 0 ;
bool V_507 ;
if ( V_513 == 0 )
return 0 ;
if ( V_513 > V_524 ) {
int V_525 = F_45 ( T_10 , V_513 >> V_526 , V_527 ) ;
V_523 = V_525 << V_526 ;
V_513 = V_523 + ( V_513 & ~ V_528 ) ;
}
V_4 = F_300 ( V_513 - V_523 , V_523 ,
V_529 ,
& V_164 , V_2 -> V_530 ) ;
if ( ! V_4 )
goto V_164;
F_301 ( V_4 , V_513 - V_523 ) ;
V_4 -> V_523 = V_523 ;
V_4 -> V_10 = V_513 ;
if ( F_285 ( V_2 , V_4 , V_4 -> V_62 ) )
goto V_531;
V_164 = F_302 ( V_4 , 0 , & V_271 -> V_532 , V_513 ) ;
if ( V_164 )
goto V_531;
F_18 ( V_4 ) -> V_80 = F_7 ( V_2 ) -> V_93 ;
F_18 ( V_4 ) -> V_95 = F_18 ( V_4 ) -> V_80 + V_513 ;
F_18 ( V_4 ) -> V_159 = F_7 ( V_2 ) -> V_108 - 1 ;
if ( F_297 ( V_2 , V_4 , 0 , & V_507 ) ) {
F_165 ( V_507 ) ;
F_278 ( V_4 ) ;
}
return V_513 ;
V_531:
F_303 ( V_4 ) ;
V_164:
return V_164 ;
}
static void F_304 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
bool V_507 = false ;
int V_511 = - 1 ;
if ( F_18 ( V_4 ) -> V_80 == F_18 ( V_4 ) -> V_95 ) {
F_278 ( V_4 ) ;
return;
}
F_305 ( V_4 ) ;
F_298 ( V_4 , F_6 ( V_4 ) -> V_434 * 4 ) ;
F_15 ( V_33 , V_4 ) ;
V_33 -> V_52 . V_497 = 0 ;
if ( F_18 ( V_4 ) -> V_80 == V_33 -> V_93 ) {
if ( F_252 ( V_33 ) == 0 )
goto V_533;
if ( V_33 -> V_534 . V_535 == V_536 &&
V_33 -> V_81 == V_33 -> V_93 && V_33 -> V_534 . V_10 &&
F_306 ( V_2 ) && ! V_33 -> V_537 ) {
int V_538 = F_45 (unsigned int, skb->len,
tp->ucopy.len) ;
F_307 ( V_539 ) ;
if ( ! F_308 ( V_4 , 0 , V_33 -> V_534 . V_271 , V_538 ) ) {
V_33 -> V_534 . V_10 -= V_538 ;
V_33 -> V_81 += V_538 ;
V_511 = ( V_538 == V_4 -> V_10 ) ;
F_50 ( V_2 ) ;
}
}
if ( V_511 <= 0 ) {
V_540:
if ( V_511 < 0 ) {
if ( F_309 ( & V_2 -> V_512 ) == 0 )
F_310 ( V_2 , V_4 -> V_62 ) ;
else if ( F_285 ( V_2 , V_4 , V_4 -> V_62 ) )
goto V_541;
}
V_511 = F_297 ( V_2 , V_4 , 0 , & V_507 ) ;
}
F_214 ( V_33 , F_18 ( V_4 ) -> V_95 ) ;
if ( V_4 -> V_10 )
F_51 ( V_2 , V_4 ) ;
if ( F_18 ( V_4 ) -> V_193 & V_195 )
F_257 ( V_2 ) ;
if ( ! F_271 ( & V_33 -> V_488 ) ) {
F_279 ( V_2 ) ;
if ( F_271 ( & V_33 -> V_488 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 0 ;
}
if ( V_33 -> V_52 . V_154 )
F_270 ( V_33 ) ;
F_217 ( V_2 ) ;
if ( V_511 > 0 )
F_284 ( V_4 , V_507 ) ;
if ( ! F_255 ( V_2 , V_476 ) )
V_2 -> V_542 ( V_2 ) ;
return;
}
if ( ! F_55 ( F_18 ( V_4 ) -> V_95 , V_33 -> V_93 ) ) {
F_70 ( F_71 ( V_2 ) , V_499 ) ;
F_265 ( V_2 , F_18 ( V_4 ) -> V_80 , F_18 ( V_4 ) -> V_95 ) ;
V_533:
F_10 ( V_2 ) ;
F_52 ( V_2 ) ;
V_541:
F_276 ( V_2 , V_4 ) ;
return;
}
if ( ! F_48 ( F_18 ( V_4 ) -> V_80 , V_33 -> V_93 + F_252 ( V_33 ) ) )
goto V_533;
F_10 ( V_2 ) ;
if ( F_48 ( F_18 ( V_4 ) -> V_80 , V_33 -> V_93 ) ) {
F_237 ( V_2 , L_19 ,
V_33 -> V_93 , F_18 ( V_4 ) -> V_80 ,
F_18 ( V_4 ) -> V_95 ) ;
F_265 ( V_2 , F_18 ( V_4 ) -> V_80 , V_33 -> V_93 ) ;
if ( ! F_252 ( V_33 ) )
goto V_533;
goto V_540;
}
F_289 ( V_2 , V_4 ) ;
}
static struct V_3 * F_311 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_543 * V_544 )
{
struct V_3 * V_366 = NULL ;
if ( ! F_294 ( V_544 , V_4 ) )
V_366 = F_295 ( V_544 , V_4 ) ;
F_281 ( V_4 , V_544 ) ;
F_278 ( V_4 ) ;
F_70 ( F_71 ( V_2 ) , V_545 ) ;
return V_366 ;
}
static void
F_312 ( struct V_1 * V_2 , struct V_543 * V_544 ,
struct V_3 * V_546 , struct V_3 * V_510 ,
T_1 V_547 , T_1 V_517 )
{
struct V_3 * V_4 , * V_548 ;
bool V_549 ;
V_4 = V_546 ;
V_550:
V_549 = true ;
F_313 (list, skb, n) {
if ( V_4 == V_510 )
break;
if ( ! F_48 ( V_547 , F_18 ( V_4 ) -> V_95 ) ) {
V_4 = F_311 ( V_2 , V_4 , V_544 ) ;
if ( ! V_4 )
break;
goto V_550;
}
if ( ! ( F_18 ( V_4 ) -> V_193 & ( V_367 | V_195 ) ) &&
( F_30 ( V_4 -> V_62 ) > V_4 -> V_10 ||
F_48 ( F_18 ( V_4 ) -> V_80 , V_547 ) ) ) {
V_549 = false ;
break;
}
if ( ! F_294 ( V_544 , V_4 ) ) {
struct V_3 * V_366 = F_295 ( V_544 , V_4 ) ;
if ( V_366 != V_510 &&
F_18 ( V_4 ) -> V_95 != F_18 ( V_366 ) -> V_80 ) {
V_549 = false ;
break;
}
}
V_547 = F_18 ( V_4 ) -> V_95 ;
}
if ( V_549 ||
( F_18 ( V_4 ) -> V_193 & ( V_367 | V_195 ) ) )
return;
while ( F_48 ( V_547 , V_517 ) ) {
int V_551 = F_45 ( int , F_314 ( 0 , 0 ) , V_517 - V_547 ) ;
struct V_3 * V_552 ;
V_552 = F_315 ( V_551 , V_169 ) ;
if ( ! V_552 )
return;
memcpy ( V_552 -> V_553 , V_4 -> V_553 , sizeof( V_4 -> V_553 ) ) ;
F_18 ( V_552 ) -> V_80 = F_18 ( V_552 ) -> V_95 = V_547 ;
F_316 ( V_544 , V_4 , V_552 ) ;
F_296 ( V_552 , V_2 ) ;
while ( V_551 > 0 ) {
int V_554 = V_547 - F_18 ( V_4 ) -> V_80 ;
int V_513 = F_18 ( V_4 ) -> V_95 - V_547 ;
F_89 ( V_554 < 0 ) ;
if ( V_513 > 0 ) {
V_513 = F_9 ( V_551 , V_513 ) ;
if ( F_317 ( V_4 , V_554 , F_301 ( V_552 , V_513 ) , V_513 ) )
F_318 () ;
F_18 ( V_552 ) -> V_95 += V_513 ;
V_551 -= V_513 ;
V_547 += V_513 ;
}
if ( ! F_48 ( V_547 , F_18 ( V_4 ) -> V_95 ) ) {
V_4 = F_311 ( V_2 , V_4 , V_544 ) ;
if ( ! V_4 ||
V_4 == V_510 ||
( F_18 ( V_4 ) -> V_193 & ( V_367 | V_195 ) ) )
return;
}
}
}
}
static void F_319 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_280 ( & V_33 -> V_488 ) ;
struct V_3 * V_546 ;
T_1 V_547 , V_517 ;
if ( ! V_4 )
return;
V_547 = F_18 ( V_4 ) -> V_80 ;
V_517 = F_18 ( V_4 ) -> V_95 ;
V_546 = V_4 ;
for (; ; ) {
struct V_3 * V_366 = NULL ;
if ( ! F_294 ( & V_33 -> V_488 , V_4 ) )
V_366 = F_295 ( & V_33 -> V_488 , V_4 ) ;
V_4 = V_366 ;
if ( ! V_4 ||
F_55 ( F_18 ( V_4 ) -> V_80 , V_517 ) ||
F_48 ( F_18 ( V_4 ) -> V_95 , V_547 ) ) {
F_312 ( V_2 , & V_33 -> V_488 ,
V_546 , V_4 , V_547 , V_517 ) ;
V_546 = V_4 ;
if ( ! V_4 )
break;
V_547 = F_18 ( V_4 ) -> V_80 ;
V_517 = F_18 ( V_4 ) -> V_95 ;
} else {
if ( F_48 ( F_18 ( V_4 ) -> V_80 , V_547 ) )
V_547 = F_18 ( V_4 ) -> V_80 ;
if ( F_55 ( F_18 ( V_4 ) -> V_95 , V_517 ) )
V_517 = F_18 ( V_4 ) -> V_95 ;
}
}
}
static bool F_288 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
bool V_555 = false ;
if ( ! F_271 ( & V_33 -> V_488 ) ) {
F_70 ( F_71 ( V_2 ) , V_556 ) ;
F_262 ( & V_33 -> V_488 ) ;
if ( V_33 -> V_52 . V_123 )
F_242 ( & V_33 -> V_52 ) ;
F_53 ( V_2 ) ;
V_555 = true ;
}
return V_555 ;
}
static int F_287 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
F_237 ( V_2 , L_20 , V_33 -> V_81 ) ;
F_70 ( F_71 ( V_2 ) , V_557 ) ;
if ( F_43 ( & V_2 -> V_84 ) >= V_2 -> V_72 )
F_40 ( V_2 ) ;
else if ( F_33 ( V_2 ) )
V_33 -> V_65 = F_9 ( V_33 -> V_65 , 4U * V_33 -> V_68 ) ;
F_319 ( V_2 ) ;
if ( ! F_271 ( & V_2 -> V_512 ) )
F_312 ( V_2 , & V_2 -> V_512 ,
F_280 ( & V_2 -> V_512 ) ,
NULL ,
V_33 -> V_81 , V_33 -> V_93 ) ;
F_53 ( V_2 ) ;
if ( F_43 ( & V_2 -> V_84 ) <= V_2 -> V_72 )
return 0 ;
F_288 ( V_2 ) ;
if ( F_43 ( & V_2 -> V_84 ) <= V_2 -> V_72 )
return 0 ;
F_70 ( F_71 ( V_2 ) , V_558 ) ;
V_33 -> V_385 = 0 ;
return - 1 ;
}
static bool F_320 ( const struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_2 -> V_74 & V_76 )
return false ;
if ( F_33 ( V_2 ) )
return false ;
if ( F_41 ( V_2 ) >= F_42 ( V_2 , 0 ) )
return false ;
if ( F_120 ( V_33 ) >= V_33 -> V_58 )
return false ;
return true ;
}
static void F_321 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_320 ( V_2 ) ) {
F_25 ( V_2 ) ;
V_33 -> V_83 = V_79 ;
}
V_2 -> V_559 ( V_2 ) ;
}
static void F_322 ( struct V_1 * V_2 )
{
if ( F_255 ( V_2 , V_560 ) ) {
F_323 ( V_2 , V_560 ) ;
F_324 () ;
if ( V_2 -> V_561 &&
F_325 ( V_562 , & V_2 -> V_561 -> V_400 ) )
F_321 ( V_2 ) ;
}
}
static inline void F_326 ( struct V_1 * V_2 )
{
F_327 ( V_2 ) ;
F_322 ( V_2 ) ;
}
static void F_328 ( struct V_1 * V_2 , int V_563 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( ( ( V_33 -> V_93 - V_33 -> V_398 ) > F_2 ( V_2 ) -> V_8 . V_12 &&
F_329 ( V_2 ) >= V_33 -> V_23 ) ||
F_11 ( V_2 ) ||
( V_563 && F_280 ( & V_33 -> V_488 ) ) ) {
F_225 ( V_2 ) ;
} else {
F_330 ( V_2 ) ;
}
}
static inline void F_331 ( struct V_1 * V_2 )
{
if ( ! F_332 ( V_2 ) ) {
return;
}
F_328 ( V_2 , 1 ) ;
}
static void F_333 ( struct V_1 * V_2 , const struct V_15 * V_46 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_1 V_209 = F_154 ( V_46 -> V_564 ) ;
if ( V_209 && ! V_565 )
V_209 -- ;
V_209 += F_246 ( V_46 -> V_80 ) ;
if ( F_55 ( V_33 -> V_81 , V_209 ) )
return;
if ( F_48 ( V_209 , V_33 -> V_93 ) )
return;
if ( V_33 -> V_537 && ! F_55 ( V_209 , V_33 -> V_566 ) )
return;
F_334 ( V_2 ) ;
if ( V_33 -> V_566 == V_33 -> V_81 && V_33 -> V_537 &&
! F_255 ( V_2 , V_567 ) && V_33 -> V_81 != V_33 -> V_93 ) {
struct V_3 * V_4 = F_280 ( & V_2 -> V_512 ) ;
V_33 -> V_81 ++ ;
if ( V_4 && ! F_48 ( V_33 -> V_81 , F_18 ( V_4 ) -> V_95 ) ) {
F_281 ( V_4 , & V_2 -> V_512 ) ;
F_278 ( V_4 ) ;
}
}
V_33 -> V_537 = V_568 ;
V_33 -> V_566 = V_209 ;
V_33 -> V_385 = 0 ;
}
static void F_335 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_15 * V_46 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_46 -> V_569 )
F_333 ( V_2 , V_46 ) ;
if ( V_33 -> V_537 == V_568 ) {
T_1 V_209 = V_33 -> V_566 - F_246 ( V_46 -> V_80 ) + ( V_46 -> V_434 * 4 ) -
V_46 -> V_48 ;
if ( V_209 < V_4 -> V_10 ) {
T_4 V_205 ;
if ( F_317 ( V_4 , V_209 , & V_205 , 1 ) )
F_318 () ;
V_33 -> V_537 = V_570 | V_205 ;
if ( ! F_255 ( V_2 , V_476 ) )
V_2 -> V_542 ( V_2 ) ;
}
}
}
static int F_336 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_571 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_538 = V_4 -> V_10 - V_571 ;
int V_164 ;
if ( F_337 ( V_4 ) )
V_164 = F_308 ( V_4 , V_571 , V_33 -> V_534 . V_271 , V_538 ) ;
else
V_164 = F_338 ( V_4 , V_571 , V_33 -> V_534 . V_271 ) ;
if ( ! V_164 ) {
V_33 -> V_534 . V_10 -= V_538 ;
V_33 -> V_81 += V_538 ;
F_50 ( V_2 ) ;
}
return V_164 ;
}
static bool F_339 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_46 , int V_572 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_247 ( V_4 , V_46 , V_33 ) && V_33 -> V_52 . V_269 &&
F_250 ( V_2 , V_4 ) ) {
if ( ! V_46 -> V_573 ) {
F_70 ( F_71 ( V_2 ) , V_574 ) ;
if ( ! F_220 ( F_71 ( V_2 ) , V_4 ,
V_575 ,
& V_33 -> V_386 ) )
F_267 ( V_2 , V_4 ) ;
goto V_576;
}
}
if ( ! F_251 ( V_33 , F_18 ( V_4 ) -> V_80 , F_18 ( V_4 ) -> V_95 ) ) {
if ( ! V_46 -> V_573 ) {
if ( V_46 -> V_48 )
goto V_577;
if ( ! F_220 ( F_71 ( V_2 ) , V_4 ,
V_578 ,
& V_33 -> V_386 ) )
F_267 ( V_2 , V_4 ) ;
}
goto V_576;
}
if ( V_46 -> V_573 ) {
if ( F_18 ( V_4 ) -> V_80 == V_33 -> V_93 )
F_253 ( V_2 ) ;
else
F_221 ( V_2 , V_4 ) ;
goto V_576;
}
if ( V_46 -> V_48 ) {
V_577:
if ( V_572 )
F_340 ( F_71 ( V_2 ) , V_579 ) ;
F_70 ( F_71 ( V_2 ) , V_580 ) ;
F_221 ( V_2 , V_4 ) ;
goto V_576;
}
return true ;
V_576:
F_276 ( V_2 , V_4 ) ;
return false ;
}
void F_341 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_46 , unsigned int V_10 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_102 ( ! V_2 -> V_581 ) )
F_2 ( V_2 ) -> V_582 -> V_583 ( V_2 , V_4 ) ;
V_33 -> V_52 . V_269 = 0 ;
if ( ( F_5 ( V_46 ) & V_584 ) == V_33 -> V_385 &&
F_18 ( V_4 ) -> V_80 == V_33 -> V_93 &&
! F_55 ( F_18 ( V_4 ) -> V_159 , V_33 -> V_110 ) ) {
int V_18 = V_33 -> V_18 ;
if ( V_18 == sizeof( struct V_15 ) + V_465 ) {
if ( ! F_244 ( V_33 , V_46 ) )
goto V_585;
if ( ( T_5 ) ( V_33 -> V_52 . V_396 - V_33 -> V_52 . V_395 ) < 0 )
goto V_585;
}
if ( V_10 <= V_18 ) {
if ( V_10 == V_18 ) {
if ( V_18 ==
( sizeof( struct V_15 ) + V_465 ) &&
V_33 -> V_93 == V_33 -> V_398 )
F_226 ( V_33 ) ;
F_234 ( V_2 , V_4 , 0 ) ;
F_278 ( V_4 ) ;
F_326 ( V_2 ) ;
return;
} else {
F_340 ( F_71 ( V_2 ) , V_579 ) ;
goto V_576;
}
} else {
int V_511 = 0 ;
bool V_507 = false ;
if ( V_33 -> V_534 . V_535 == V_536 &&
V_33 -> V_81 == V_33 -> V_93 &&
V_10 - V_18 <= V_33 -> V_534 . V_10 &&
F_306 ( V_2 ) ) {
F_307 ( V_539 ) ;
if ( ! F_336 ( V_2 , V_4 , V_18 ) ) {
if ( V_18 ==
( sizeof( struct V_15 ) +
V_465 ) &&
V_33 -> V_93 == V_33 -> V_398 )
F_226 ( V_33 ) ;
F_49 ( V_2 , V_4 ) ;
F_298 ( V_4 , V_18 ) ;
F_214 ( V_33 , F_18 ( V_4 ) -> V_95 ) ;
F_70 ( F_71 ( V_2 ) ,
V_586 ) ;
V_511 = 1 ;
}
}
if ( ! V_511 ) {
if ( F_342 ( V_4 ) )
goto V_587;
if ( ( int ) V_4 -> V_62 > V_2 -> V_588 )
goto V_589;
if ( V_18 ==
( sizeof( struct V_15 ) + V_465 ) &&
V_33 -> V_93 == V_33 -> V_398 )
F_226 ( V_33 ) ;
F_49 ( V_2 , V_4 ) ;
F_70 ( F_71 ( V_2 ) , V_590 ) ;
V_511 = F_297 ( V_2 , V_4 , V_18 ,
& V_507 ) ;
}
F_51 ( V_2 , V_4 ) ;
if ( F_18 ( V_4 ) -> V_159 != V_33 -> V_108 ) {
F_234 ( V_2 , V_4 , V_416 ) ;
F_326 ( V_2 ) ;
if ( ! F_332 ( V_2 ) )
goto V_591;
}
F_328 ( V_2 , 0 ) ;
V_591:
if ( V_511 )
F_284 ( V_4 , V_507 ) ;
V_2 -> V_542 ( V_2 ) ;
return;
}
}
V_585:
if ( V_10 < ( V_46 -> V_434 << 2 ) || F_342 ( V_4 ) )
goto V_587;
if ( ! V_46 -> V_344 && ! V_46 -> V_573 && ! V_46 -> V_48 )
goto V_576;
if ( ! F_339 ( V_2 , V_4 , V_46 , 1 ) )
return;
V_589:
if ( F_234 ( V_2 , V_4 , V_411 | V_410 ) < 0 )
goto V_576;
F_49 ( V_2 , V_4 ) ;
F_335 ( V_2 , V_4 , V_46 ) ;
F_304 ( V_2 , V_4 ) ;
F_326 ( V_2 ) ;
F_331 ( V_2 ) ;
return;
V_587:
F_340 ( F_71 ( V_2 ) , V_592 ) ;
F_340 ( F_71 ( V_2 ) , V_579 ) ;
V_576:
F_276 ( V_2 , V_4 ) ;
}
void F_343 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_259 ( V_2 , V_482 ) ;
if ( V_4 ) {
V_6 -> V_582 -> V_583 ( V_2 , V_4 ) ;
F_344 ( V_2 , V_4 ) ;
}
V_6 -> V_582 -> V_593 ( V_2 ) ;
F_345 ( V_2 ) ;
F_346 ( V_2 ) ;
V_33 -> V_594 = V_79 ;
F_37 ( V_2 ) ;
if ( F_255 ( V_2 , V_595 ) )
F_347 ( V_2 , F_348 ( V_33 ) ) ;
if ( ! V_33 -> V_52 . V_383 )
F_349 ( V_33 , V_33 -> V_379 ) ;
else
V_33 -> V_385 = 0 ;
if ( ! F_255 ( V_2 , V_476 ) ) {
V_2 -> V_489 ( V_2 ) ;
F_263 ( V_2 , V_596 , V_597 ) ;
}
}
static bool F_350 ( struct V_1 * V_2 , struct V_3 * V_598 ,
struct V_424 * V_423 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_13 = V_33 -> V_599 ? F_103 ( V_2 ) : NULL ;
T_6 V_69 = V_33 -> V_52 . V_53 , V_600 = 0 ;
bool V_601 = false ;
if ( V_69 == V_33 -> V_52 . V_442 ) {
struct V_430 V_602 ;
F_351 ( & V_602 ) ;
V_602 . V_442 = V_602 . V_53 = 0 ;
F_239 ( V_598 , & V_602 , 0 , NULL ) ;
V_69 = V_602 . V_53 ;
}
if ( ! V_33 -> V_603 ) {
V_423 -> V_10 = - 1 ;
} else if ( V_33 -> V_604 ) {
V_601 = ( V_423 -> V_10 < 0 && V_13 ) ;
} else if ( V_423 -> V_10 < 0 && ! V_33 -> V_599 ) {
V_600 = V_33 -> V_605 ? 2 : 1 ;
}
F_352 ( V_2 , V_69 , V_423 , V_601 , V_600 ) ;
if ( V_13 ) {
F_110 (data, sk) {
if ( V_13 == F_108 ( V_2 ) ||
F_353 ( V_2 , V_13 , 1 ) )
break;
}
F_194 ( V_2 ) ;
F_70 ( F_71 ( V_2 ) ,
V_606 ) ;
return true ;
}
V_33 -> V_607 = V_33 -> V_599 ;
if ( V_33 -> V_607 )
F_70 ( F_71 ( V_2 ) ,
V_608 ) ;
F_354 ( V_2 , V_598 ) ;
return false ;
}
static int F_355 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_46 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_424 V_425 = { . V_10 = - 1 } ;
int V_609 = V_33 -> V_52 . V_53 ;
F_239 ( V_4 , & V_33 -> V_52 , 0 , & V_425 ) ;
if ( V_33 -> V_52 . V_269 && V_33 -> V_52 . V_94 )
V_33 -> V_52 . V_94 -= V_33 -> V_464 ;
if ( V_46 -> V_344 ) {
if ( ! F_55 ( F_18 ( V_4 ) -> V_159 , V_33 -> V_108 ) ||
F_55 ( F_18 ( V_4 ) -> V_159 , V_33 -> V_110 ) )
goto V_610;
if ( V_33 -> V_52 . V_269 && V_33 -> V_52 . V_94 &&
! F_203 ( V_33 -> V_52 . V_94 , V_33 -> V_270 ,
V_79 ) ) {
F_70 ( F_71 ( V_2 ) ,
V_611 ) ;
goto V_610;
}
if ( V_46 -> V_573 ) {
F_253 ( V_2 ) ;
goto V_576;
}
if ( ! V_46 -> V_48 )
goto V_612;
F_22 ( V_33 , V_46 ) ;
F_356 ( V_33 , F_18 ( V_4 ) -> V_80 ) ;
F_234 ( V_2 , V_4 , V_411 ) ;
V_33 -> V_93 = F_18 ( V_4 ) -> V_80 + 1 ;
V_33 -> V_398 = F_18 ( V_4 ) -> V_80 + 1 ;
V_33 -> V_379 = F_154 ( V_46 -> V_63 ) ;
if ( ! V_33 -> V_52 . V_446 ) {
V_33 -> V_52 . V_383 = V_33 -> V_52 . V_613 = 0 ;
V_33 -> V_66 = F_9 ( V_33 -> V_66 , 65535U ) ;
}
if ( V_33 -> V_52 . V_269 ) {
V_33 -> V_52 . V_450 = 1 ;
V_33 -> V_18 =
sizeof( struct V_15 ) + V_465 ;
V_33 -> V_68 -= V_465 ;
F_226 ( V_33 ) ;
} else {
V_33 -> V_18 = sizeof( struct V_15 ) ;
}
if ( F_144 ( V_33 ) && V_614 )
F_357 ( V_33 ) ;
F_358 ( V_2 ) ;
F_174 ( V_2 , V_6 -> V_307 ) ;
F_44 ( V_2 ) ;
V_33 -> V_81 = V_33 -> V_93 ;
F_359 () ;
F_343 ( V_2 , V_4 ) ;
if ( ( V_33 -> V_603 || V_33 -> V_599 ) &&
F_350 ( V_2 , V_4 , & V_425 ) )
return - 1 ;
if ( V_2 -> V_615 ||
V_6 -> V_616 . V_617 ||
V_6 -> V_8 . V_26 ) {
F_52 ( V_2 ) ;
V_6 -> V_8 . V_100 = V_79 ;
F_10 ( V_2 ) ;
F_136 ( V_2 , V_618 ,
V_619 , V_250 ) ;
V_576:
F_276 ( V_2 , V_4 ) ;
return 0 ;
} else {
F_225 ( V_2 ) ;
}
return - 1 ;
}
if ( V_46 -> V_573 ) {
goto V_612;
}
if ( V_33 -> V_52 . V_397 && V_33 -> V_52 . V_269 &&
F_360 ( & V_33 -> V_52 , 0 ) )
goto V_612;
if ( V_46 -> V_48 ) {
F_259 ( V_2 , V_481 ) ;
if ( V_33 -> V_52 . V_269 ) {
V_33 -> V_52 . V_450 = 1 ;
F_226 ( V_33 ) ;
V_33 -> V_18 =
sizeof( struct V_15 ) + V_465 ;
} else {
V_33 -> V_18 = sizeof( struct V_15 ) ;
}
V_33 -> V_93 = F_18 ( V_4 ) -> V_80 + 1 ;
V_33 -> V_81 = V_33 -> V_93 ;
V_33 -> V_398 = F_18 ( V_4 ) -> V_80 + 1 ;
V_33 -> V_379 = F_154 ( V_46 -> V_63 ) ;
V_33 -> V_378 = F_18 ( V_4 ) -> V_80 ;
V_33 -> V_150 = V_33 -> V_379 ;
F_23 ( V_33 , V_46 ) ;
F_358 ( V_2 ) ;
F_174 ( V_2 , V_6 -> V_307 ) ;
F_44 ( V_2 ) ;
F_361 ( V_2 ) ;
#if 0
return -1;
#else
goto V_576;
#endif
}
V_612:
F_351 ( & V_33 -> V_52 ) ;
V_33 -> V_52 . V_53 = V_609 ;
goto V_576;
V_610:
F_351 ( & V_33 -> V_52 ) ;
V_33 -> V_52 . V_53 = V_609 ;
return 1 ;
}
int F_362 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_15 * V_46 = F_6 ( V_4 ) ;
struct V_339 * V_340 ;
int V_620 = 0 ;
bool V_621 ;
switch ( V_2 -> V_468 ) {
case V_474 :
goto V_576;
case V_622 :
if ( V_46 -> V_344 )
return 1 ;
if ( V_46 -> V_573 )
goto V_576;
if ( V_46 -> V_48 ) {
if ( V_46 -> V_623 )
goto V_576;
if ( V_6 -> V_582 -> V_624 ( V_2 , V_4 ) < 0 )
return 1 ;
F_363 ( V_4 ) ;
return 0 ;
}
goto V_576;
case V_469 :
V_33 -> V_52 . V_269 = 0 ;
V_620 = F_355 ( V_2 , V_4 , V_46 ) ;
if ( V_620 >= 0 )
return V_620 ;
F_335 ( V_2 , V_4 , V_46 ) ;
F_278 ( V_4 ) ;
F_326 ( V_2 ) ;
return 0 ;
}
V_33 -> V_52 . V_269 = 0 ;
V_340 = V_33 -> V_346 ;
if ( V_340 ) {
F_165 ( V_2 -> V_468 != V_481 &&
V_2 -> V_468 != V_485 ) ;
if ( ! F_364 ( V_2 , V_4 , V_340 , true ) )
goto V_576;
}
if ( ! V_46 -> V_344 && ! V_46 -> V_573 && ! V_46 -> V_48 )
goto V_576;
if ( ! F_339 ( V_2 , V_4 , V_46 , 0 ) )
return 0 ;
V_621 = F_234 ( V_2 , V_4 , V_411 |
V_410 ) > 0 ;
switch ( V_2 -> V_468 ) {
case V_481 :
if ( ! V_621 )
return 1 ;
if ( ! V_33 -> V_104 )
F_189 ( V_2 , V_340 ) ;
if ( V_340 ) {
V_33 -> V_604 = V_340 -> V_341 ;
F_365 ( V_2 , V_340 , false ) ;
} else {
V_6 -> V_582 -> V_593 ( V_2 ) ;
F_346 ( V_2 ) ;
F_358 ( V_2 ) ;
V_33 -> V_81 = V_33 -> V_93 ;
F_37 ( V_2 ) ;
}
F_359 () ;
F_259 ( V_2 , V_482 ) ;
V_2 -> V_489 ( V_2 ) ;
if ( V_2 -> V_561 )
F_263 ( V_2 , V_596 , V_597 ) ;
V_33 -> V_108 = F_18 ( V_4 ) -> V_159 ;
V_33 -> V_379 = F_154 ( V_46 -> V_63 ) << V_33 -> V_52 . V_383 ;
F_356 ( V_33 , F_18 ( V_4 ) -> V_80 ) ;
if ( V_33 -> V_52 . V_450 )
V_33 -> V_68 -= V_465 ;
if ( V_340 ) {
F_194 ( V_2 ) ;
} else
F_345 ( V_2 ) ;
F_57 ( V_2 ) ;
V_33 -> V_594 = V_79 ;
F_44 ( V_2 ) ;
F_366 ( V_33 ) ;
break;
case V_485 : {
struct V_29 * V_30 ;
int V_625 ;
if ( V_340 ) {
if ( ! V_621 )
return 1 ;
F_365 ( V_2 , V_340 , false ) ;
F_194 ( V_2 ) ;
}
if ( V_33 -> V_108 != V_33 -> V_626 )
break;
F_259 ( V_2 , V_486 ) ;
V_2 -> V_478 |= V_627 ;
V_30 = F_12 ( V_2 ) ;
if ( V_30 )
F_235 ( V_30 ) ;
if ( ! F_255 ( V_2 , V_476 ) ) {
V_2 -> V_489 ( V_2 ) ;
break;
}
if ( V_33 -> V_628 < 0 ||
( F_18 ( V_4 ) -> V_95 != F_18 ( V_4 ) -> V_80 &&
F_55 ( F_18 ( V_4 ) -> V_95 - V_46 -> V_623 , V_33 -> V_93 ) ) ) {
F_256 ( V_2 ) ;
F_70 ( F_71 ( V_2 ) , V_629 ) ;
return 1 ;
}
V_625 = F_367 ( V_2 ) ;
if ( V_625 > V_630 ) {
F_347 ( V_2 , V_625 - V_630 ) ;
} else if ( V_46 -> V_623 || F_306 ( V_2 ) ) {
F_347 ( V_2 , V_625 ) ;
} else {
F_260 ( V_2 , V_486 , V_625 ) ;
goto V_576;
}
break;
}
case V_483 :
if ( V_33 -> V_108 == V_33 -> V_626 ) {
F_260 ( V_2 , V_487 , 0 ) ;
goto V_576;
}
break;
case V_484 :
if ( V_33 -> V_108 == V_33 -> V_626 ) {
F_368 ( V_2 ) ;
F_256 ( V_2 ) ;
goto V_576;
}
break;
}
F_335 ( V_2 , V_4 , V_46 ) ;
switch ( V_2 -> V_468 ) {
case V_472 :
case V_483 :
case V_484 :
if ( ! F_48 ( F_18 ( V_4 ) -> V_80 , V_33 -> V_93 ) )
break;
case V_485 :
case V_486 :
if ( V_2 -> V_478 & V_479 ) {
if ( F_18 ( V_4 ) -> V_95 != F_18 ( V_4 ) -> V_80 &&
F_55 ( F_18 ( V_4 ) -> V_95 - V_46 -> V_623 , V_33 -> V_93 ) ) {
F_70 ( F_71 ( V_2 ) , V_629 ) ;
F_253 ( V_2 ) ;
return 1 ;
}
}
case V_482 :
F_304 ( V_2 , V_4 ) ;
V_620 = 1 ;
break;
}
if ( V_2 -> V_468 != V_474 ) {
F_326 ( V_2 ) ;
F_331 ( V_2 ) ;
}
if ( ! V_620 ) {
V_576:
F_276 ( V_2 , V_4 ) ;
}
return 0 ;
}
static inline void F_369 ( struct V_339 * V_340 , T_11 V_631 , int V_632 )
{
struct V_633 * V_634 = F_370 ( V_340 ) ;
if ( V_632 == V_275 )
F_371 ( L_21 ,
& V_634 -> V_635 , V_631 ) ;
#if F_156 ( V_278 )
else if ( V_632 == V_279 )
F_371 ( L_22 ,
& V_634 -> V_636 , V_631 ) ;
#endif
}
static void F_372 ( struct V_339 * V_340 ,
const struct V_3 * V_4 ,
const struct V_1 * V_637 ,
const struct V_29 * V_30 )
{
const struct V_15 * V_46 = F_6 ( V_4 ) ;
const struct V_229 * V_229 = F_71 ( V_637 ) ;
bool V_638 = V_46 -> V_47 && V_46 -> V_37 ;
bool V_639 , V_640 ;
T_1 V_641 ;
if ( ! V_638 )
return;
V_639 = ! F_373 ( F_18 ( V_4 ) -> V_39 ) ;
V_641 = F_374 ( V_30 , V_642 ) ;
V_640 = V_229 -> V_241 . V_643 || V_641 ;
if ( ( ! V_639 && V_640 ) || F_19 ( V_637 ) ||
( V_641 & V_644 ) )
F_370 ( V_340 ) -> V_640 = 1 ;
}
static void F_375 ( struct V_339 * V_340 ,
const struct V_430 * V_52 ,
struct V_3 * V_4 , const struct V_1 * V_2 )
{
struct V_633 * V_634 = F_370 ( V_340 ) ;
V_340 -> V_645 = 0 ;
V_340 -> V_646 = 0 ;
F_190 ( V_340 ) -> V_647 = F_18 ( V_4 ) -> V_80 ;
F_190 ( V_340 ) -> V_93 = F_18 ( V_4 ) -> V_80 + 1 ;
F_191 ( & F_190 ( V_340 ) -> V_342 ) ;
F_190 ( V_340 ) -> V_386 = 0 ;
V_340 -> V_69 = V_52 -> V_53 ;
V_340 -> V_395 = V_52 -> V_269 ? V_52 -> V_396 : 0 ;
V_634 -> V_450 = V_52 -> V_450 ;
V_634 -> V_123 = V_52 -> V_123 ;
V_634 -> V_383 = V_52 -> V_383 ;
V_634 -> V_446 = V_52 -> V_446 ;
V_634 -> V_228 = 0 ;
V_634 -> V_640 = 0 ;
V_634 -> V_648 = F_6 ( V_4 ) -> V_649 ;
V_634 -> V_650 = F_154 ( F_6 ( V_4 ) -> V_651 ) ;
V_634 -> V_652 = F_376 ( V_2 , V_4 ) ;
}
struct V_339 * F_377 ( const struct V_653 * V_654 ,
struct V_1 * V_655 ,
bool V_656 )
{
struct V_339 * V_340 = F_378 ( V_654 , V_655 ,
V_656 ) ;
if ( V_340 ) {
struct V_633 * V_634 = F_370 ( V_340 ) ;
F_379 ( V_634 , V_400 ) ;
V_634 -> V_602 = NULL ;
F_380 ( & V_634 -> V_657 , 0 ) ;
V_634 -> V_658 = V_659 ;
F_381 ( & V_634 -> V_660 , F_71 ( V_655 ) ) ;
V_634 -> V_661 = V_655 -> V_274 ;
}
return V_340 ;
}
static bool F_382 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const char * V_662 )
{
struct V_663 * V_664 = & F_2 ( V_2 ) -> V_616 ;
const char * V_271 = L_23 ;
bool V_665 = false ;
struct V_229 * V_229 = F_71 ( V_2 ) ;
#ifdef F_383
if ( V_229 -> V_241 . V_666 ) {
V_271 = L_24 ;
V_665 = true ;
F_384 ( F_71 ( V_2 ) , V_667 ) ;
} else
#endif
F_384 ( F_71 ( V_2 ) , V_668 ) ;
if ( ! V_664 -> V_669 &&
V_229 -> V_241 . V_666 != 2 &&
F_385 ( & V_664 -> V_669 , 1 ) == 0 )
F_386 ( L_25 ,
V_662 , F_154 ( F_6 ( V_4 ) -> V_651 ) , V_271 ) ;
return V_665 ;
}
static void F_387 ( const struct V_1 * V_2 ,
struct V_339 * V_340 ,
const struct V_3 * V_4 )
{
if ( F_7 ( V_2 ) -> V_670 ) {
T_1 V_10 = F_388 ( V_4 ) + F_389 ( V_4 ) ;
T_1 * V_551 ;
V_551 = F_390 ( V_10 + sizeof( T_1 ) , V_169 ) ;
if ( V_551 ) {
V_551 [ 0 ] = V_10 ;
memcpy ( & V_551 [ 1 ] , F_391 ( V_4 ) , V_10 ) ;
V_340 -> V_671 = V_551 ;
}
}
}
int F_392 ( struct V_653 * V_672 ,
const struct V_673 * V_674 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_424 V_425 = { . V_10 = - 1 } ;
T_3 V_675 = F_18 ( V_4 ) -> V_676 ;
struct V_430 V_677 ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_229 * V_229 = F_71 ( V_2 ) ;
struct V_1 * V_678 = NULL ;
struct V_29 * V_30 = NULL ;
struct V_339 * V_340 ;
bool V_665 = false ;
struct V_679 V_680 ;
if ( ( V_229 -> V_241 . V_666 == 2 ||
F_393 ( V_2 ) ) && ! V_675 ) {
V_665 = F_382 ( V_2 , V_4 , V_672 -> V_681 ) ;
if ( ! V_665 )
goto V_541;
}
if ( F_394 ( V_2 ) && F_395 ( V_2 ) > 1 ) {
F_70 ( F_71 ( V_2 ) , V_682 ) ;
goto V_541;
}
V_340 = F_377 ( V_672 , V_2 , ! V_665 ) ;
if ( ! V_340 )
goto V_541;
F_190 ( V_340 ) -> V_683 = V_674 ;
F_351 ( & V_677 ) ;
V_677 . V_53 = V_674 -> V_53 ;
V_677 . V_442 = V_33 -> V_52 . V_442 ;
F_239 ( V_4 , & V_677 , 0 , V_665 ? NULL : & V_425 ) ;
if ( V_665 && ! V_677 . V_269 )
F_351 ( & V_677 ) ;
V_677 . V_450 = V_677 . V_269 ;
F_375 ( V_340 , & V_677 , V_4 , V_2 ) ;
F_370 ( V_340 ) -> V_684 = F_396 ( V_2 , V_4 ) ;
V_674 -> V_685 ( V_340 , V_2 , V_4 ) ;
if ( F_397 ( V_2 , V_4 , V_340 ) )
goto V_686;
if ( ! V_665 && ! V_675 ) {
if ( V_687 . V_688 ) {
bool V_689 ;
V_30 = V_674 -> V_690 ( V_2 , & V_680 , V_340 , & V_689 ) ;
if ( V_30 && V_689 &&
! F_398 ( V_340 , V_30 , true ,
V_677 . V_269 ) ) {
F_70 ( F_71 ( V_2 ) , V_691 ) ;
goto V_692;
}
}
else if ( ! V_229 -> V_241 . V_666 &&
( V_693 - F_399 ( V_2 ) <
( V_693 >> 2 ) ) &&
! F_398 ( V_340 , V_30 , false ,
V_677 . V_269 ) ) {
F_369 ( V_340 , F_154 ( F_6 ( V_4 ) -> V_649 ) ,
V_672 -> V_632 ) ;
goto V_692;
}
V_675 = V_674 -> V_694 ( V_4 ) ;
}
if ( ! V_30 ) {
V_30 = V_674 -> V_690 ( V_2 , & V_680 , V_340 , NULL ) ;
if ( ! V_30 )
goto V_686;
}
F_372 ( V_340 , V_4 , V_2 , V_30 ) ;
if ( V_665 ) {
V_675 = F_400 ( V_674 , V_2 , V_4 , & V_340 -> V_69 ) ;
V_340 -> V_646 = V_677 . V_450 ;
if ( ! V_677 . V_450 )
F_370 ( V_340 ) -> V_640 = 0 ;
}
F_190 ( V_340 ) -> V_695 = V_675 ;
F_190 ( V_340 ) -> V_696 = F_401 () ;
F_402 ( V_340 , V_2 , V_30 ) ;
if ( ! V_665 ) {
F_387 ( V_2 , V_340 , V_4 ) ;
V_678 = F_403 ( V_2 , V_4 , V_340 , & V_425 , V_30 ) ;
}
if ( V_678 ) {
V_674 -> V_697 ( V_678 , V_30 , & V_680 , V_340 ,
& V_425 , V_698 ) ;
F_404 ( V_2 , V_340 , V_678 ) ;
V_2 -> V_542 ( V_2 ) ;
F_405 ( V_678 ) ;
F_406 ( V_678 ) ;
} else {
F_190 ( V_340 ) -> V_699 = false ;
if ( ! V_665 )
F_407 ( V_2 , V_340 , V_700 ) ;
V_674 -> V_697 ( V_2 , V_30 , & V_680 , V_340 , & V_425 ,
! V_665 ? V_701 :
V_702 ) ;
if ( V_665 ) {
F_408 ( V_340 ) ;
return 0 ;
}
}
F_409 ( V_340 ) ;
return 0 ;
V_692:
F_410 ( V_30 ) ;
V_686:
F_408 ( V_340 ) ;
V_541:
F_411 ( V_2 ) ;
return 0 ;
}
