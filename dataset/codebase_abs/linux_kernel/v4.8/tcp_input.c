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
F_72 ( L_3 ,
V_271 ,
& V_2 -> V_280 , F_154 ( V_273 -> V_277 ) ,
V_33 -> V_58 , F_155 ( V_33 ) ,
V_33 -> V_113 , V_33 -> V_235 ,
V_33 -> V_116 ) ;
}
#endif
}
static void F_157 ( struct V_1 * V_2 , bool V_281 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_281 ) {
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
if ( V_6 -> V_236 -> V_282 )
V_33 -> V_58 = V_6 -> V_236 -> V_282 ( V_2 ) ;
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
static inline bool F_158 ( const struct V_32 * V_33 )
{
return V_33 -> V_138 && ( ! V_33 -> V_139 || F_150 ( V_33 ) ) ;
}
static bool F_159 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_158 ( V_33 ) ) {
int V_128 ;
F_152 ( V_2 , F_2 ( V_2 ) -> V_135 == V_224 ? L_4 : L_5 ) ;
F_157 ( V_2 , false ) ;
if ( F_2 ( V_2 ) -> V_135 == V_224 )
V_128 = V_283 ;
else
V_128 = V_284 ;
F_70 ( F_71 ( V_2 ) , V_128 ) ;
}
if ( V_33 -> V_108 == V_33 -> V_179 && F_69 ( V_33 ) ) {
if ( ! F_151 ( V_2 ) )
V_33 -> V_270 = 0 ;
return true ;
}
F_132 ( V_2 , V_285 ) ;
return false ;
}
static bool F_160 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_33 -> V_138 && ! V_33 -> V_139 ) {
F_152 ( V_2 , L_6 ) ;
F_157 ( V_2 , false ) ;
F_70 ( F_71 ( V_2 ) , V_286 ) ;
return true ;
}
return false ;
}
static bool F_161 ( struct V_1 * V_2 , bool V_287 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_287 || F_158 ( V_33 ) ) {
F_157 ( V_2 , true ) ;
F_152 ( V_2 , L_7 ) ;
F_70 ( F_71 ( V_2 ) , V_283 ) ;
if ( V_287 )
F_70 ( F_71 ( V_2 ) ,
V_288 ) ;
F_2 ( V_2 ) -> V_234 = 0 ;
if ( V_287 || F_144 ( V_33 ) )
F_132 ( V_2 , V_285 ) ;
return true ;
}
return false ;
}
static void F_162 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
V_33 -> V_179 = V_33 -> V_110 ;
V_33 -> V_289 = 0 ;
V_33 -> V_239 = 0 ;
V_33 -> V_290 = V_33 -> V_58 ;
V_33 -> V_291 = 0 ;
V_33 -> V_292 = 0 ;
V_33 -> V_113 = F_2 ( V_2 ) -> V_236 -> V_237 ( V_2 ) ;
F_14 ( V_33 ) ;
}
static void F_163 ( struct V_1 * V_2 , int V_293 ,
int V_180 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_294 = 0 ;
int V_295 = V_33 -> V_113 - F_120 ( V_33 ) ;
if ( V_293 <= 0 || F_164 ( ! V_33 -> V_290 ) )
return;
V_33 -> V_291 += V_293 ;
if ( V_295 < 0 ) {
T_2 V_296 = ( T_2 ) V_33 -> V_113 * V_33 -> V_291 +
V_33 -> V_290 - 1 ;
V_294 = F_165 ( V_296 , V_33 -> V_290 ) - V_33 -> V_292 ;
} else if ( ( V_180 & V_297 ) &&
! ( V_180 & V_298 ) ) {
V_294 = F_45 ( int , V_295 ,
F_26 ( int , V_33 -> V_291 - V_33 -> V_292 ,
V_293 ) + 1 ) ;
} else {
V_294 = F_9 ( V_295 , V_293 ) ;
}
V_294 = F_39 ( V_294 , ( V_33 -> V_292 ? 0 : 1 ) ) ;
V_33 -> V_58 = F_120 ( V_33 ) + V_294 ;
}
static inline void F_166 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_135 == V_299 ||
( V_33 -> V_138 && V_33 -> V_113 < V_300 ) ) {
V_33 -> V_58 = V_33 -> V_113 ;
V_33 -> V_83 = V_79 ;
}
F_20 ( V_2 , V_301 ) ;
}
void F_167 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
V_33 -> V_235 = 0 ;
if ( F_2 ( V_2 ) -> V_135 < V_299 ) {
V_33 -> V_138 = 0 ;
F_162 ( V_2 ) ;
F_132 ( V_2 , V_299 ) ;
}
}
static void F_168 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_171 = V_285 ;
if ( F_155 ( V_33 ) || F_151 ( V_2 ) )
V_171 = V_233 ;
if ( F_2 ( V_2 ) -> V_135 != V_171 ) {
F_132 ( V_2 , V_171 ) ;
V_33 -> V_179 = V_33 -> V_110 ;
}
}
static void F_169 ( struct V_1 * V_2 , int V_180 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
F_119 ( V_33 ) ;
if ( ! F_151 ( V_2 ) )
V_33 -> V_270 = 0 ;
if ( V_180 & V_252 )
F_167 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_135 != V_299 ) {
F_168 ( V_2 ) ;
}
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_245 . V_302 = V_6 -> V_245 . V_246 - 1 ;
V_6 -> V_245 . V_246 = 0 ;
F_70 ( F_71 ( V_2 ) , V_303 ) ;
}
static void F_171 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_33 -> V_235 = F_129 ( V_2 ) ;
V_33 -> V_58 = V_33 -> V_58 *
F_172 ( V_2 , V_33 -> V_54 ) /
V_6 -> V_245 . V_246 ;
V_33 -> V_239 = 0 ;
V_33 -> V_83 = V_79 ;
V_33 -> V_113 = F_129 ( V_2 ) ;
V_6 -> V_245 . V_304 = V_6 -> V_245 . V_246 ;
V_6 -> V_245 . V_246 = 0 ;
F_173 ( V_2 , V_6 -> V_305 ) ;
F_70 ( F_71 ( V_2 ) , V_306 ) ;
}
void F_174 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_69 = F_175 ( V_2 ) ;
T_1 V_307 = V_33 -> V_143 ;
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
F_176 ( V_33 ) ;
if ( V_307 == V_33 -> V_143 )
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
F_177 ( V_2 ) ;
}
static void F_178 ( struct V_1 * V_2 , bool V_308 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_128 ;
if ( F_69 ( V_33 ) )
V_128 = V_309 ;
else
V_128 = V_310 ;
F_70 ( F_71 ( V_2 ) , V_128 ) ;
V_33 -> V_235 = 0 ;
F_127 ( V_33 ) ;
if ( ! F_179 ( V_2 ) ) {
if ( ! V_308 )
V_33 -> V_235 = F_129 ( V_2 ) ;
F_162 ( V_2 ) ;
}
F_132 ( V_2 , V_231 ) ;
}
static void F_180 ( struct V_1 * V_2 , int V_180 , bool V_311 ,
int * V_312 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
bool V_313 = ! F_48 ( V_33 -> V_108 , V_33 -> V_179 ) ;
if ( ( V_180 & V_314 ) &&
F_161 ( V_2 , false ) )
return;
if ( V_33 -> V_243 ) {
if ( ( V_180 & V_181 ) &&
F_161 ( V_2 , true ) )
return;
if ( F_55 ( V_33 -> V_110 , V_33 -> V_179 ) ) {
if ( V_180 & V_185 || V_311 )
V_33 -> V_243 = 0 ;
} else if ( V_180 & V_314 && ! V_313 ) {
V_33 -> V_179 = V_33 -> V_110 ;
if ( F_108 ( V_2 ) &&
F_55 ( F_181 ( V_33 ) , V_33 -> V_110 ) ) {
* V_312 = V_315 ;
return;
}
V_33 -> V_243 = 0 ;
}
}
if ( V_313 ) {
F_159 ( V_2 ) ;
return;
}
if ( F_69 ( V_33 ) ) {
if ( F_55 ( V_33 -> V_110 , V_33 -> V_179 ) && V_311 )
F_123 ( V_2 ) ;
else if ( V_180 & V_314 )
F_125 ( V_33 ) ;
}
* V_312 = V_316 ;
}
static bool F_182 ( struct V_1 * V_2 , const int V_228 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_33 -> V_138 && F_150 ( V_33 ) ) {
F_68 ( V_2 , F_137 ( V_33 ) + V_228 , 1 ) ;
if ( V_33 -> V_178 )
return true ;
if ( ! F_151 ( V_2 ) )
V_33 -> V_270 = 0 ;
F_152 ( V_2 , L_8 ) ;
F_157 ( V_2 , true ) ;
F_70 ( F_71 ( V_2 ) , V_317 ) ;
F_168 ( V_2 ) ;
return true ;
}
return false ;
}
static void F_183 ( struct V_1 * V_2 , const int V_228 ,
bool V_311 , int * V_318 , int * V_312 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_266 = 0 , V_180 = * V_318 ;
bool V_319 = V_311 || ( ( V_180 & V_185 ) &&
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
if ( V_6 -> V_135 == V_285 ) {
F_116 ( V_33 -> V_178 != 0 ) ;
V_33 -> V_270 = 0 ;
} else if ( ! F_48 ( V_33 -> V_108 , V_33 -> V_179 ) ) {
switch ( V_6 -> V_135 ) {
case V_299 :
if ( V_33 -> V_108 != V_33 -> V_179 ) {
F_166 ( V_2 ) ;
F_132 ( V_2 , V_285 ) ;
}
break;
case V_231 :
if ( F_69 ( V_33 ) )
F_125 ( V_33 ) ;
if ( F_159 ( V_2 ) )
return;
F_166 ( V_2 ) ;
break;
}
}
if ( V_320 & V_321 &&
F_184 ( V_2 ) ) {
V_180 |= V_298 ;
* V_318 |= V_298 ;
}
switch ( V_6 -> V_135 ) {
case V_231 :
if ( ! ( V_180 & V_314 ) ) {
if ( F_69 ( V_33 ) && V_311 )
F_123 ( V_2 ) ;
} else {
if ( F_182 ( V_2 , V_228 ) )
return;
V_319 = F_69 ( V_33 ) ||
F_137 ( V_33 ) > V_33 -> V_59 ;
}
if ( F_160 ( V_2 ) ) {
F_168 ( V_2 ) ;
return;
}
break;
case V_224 :
F_180 ( V_2 , V_180 , V_311 , V_312 ) ;
if ( V_6 -> V_135 != V_285 &&
! ( V_180 & V_298 ) )
return;
default:
if ( F_69 ( V_33 ) ) {
if ( V_180 & V_314 )
F_125 ( V_33 ) ;
if ( V_311 )
F_123 ( V_2 ) ;
}
if ( V_6 -> V_135 <= V_233 )
F_160 ( V_2 ) ;
if ( ! F_141 ( V_2 , V_180 ) ) {
F_169 ( V_2 , V_180 ) ;
return;
}
if ( V_6 -> V_135 < V_299 &&
V_6 -> V_245 . V_246 &&
V_33 -> V_108 == V_33 -> V_322 . V_323 ) {
F_170 ( V_2 ) ;
V_33 -> V_58 ++ ;
F_174 ( V_2 ) ;
return;
}
F_178 ( V_2 , ( V_180 & V_252 ) ) ;
V_266 = 1 ;
}
if ( V_319 )
F_146 ( V_2 , V_266 ) ;
* V_312 = V_316 ;
}
static void F_185 ( struct V_1 * V_2 , T_1 V_324 )
{
const T_1 V_99 = V_79 , V_325 = V_326 * V_327 ;
struct V_328 * V_91 = F_7 ( V_2 ) -> V_329 ;
struct V_328 V_330 = {
. V_90 = F_58 ( V_324 ) ? V_324 : F_186 ( 1 ) ,
. V_127 = V_99 ,
} ;
T_1 V_331 ;
if ( F_102 ( V_330 . V_90 <= V_91 [ 0 ] . V_90 ) )
V_91 [ 0 ] = V_91 [ 1 ] = V_91 [ 2 ] = V_330 ;
else if ( V_330 . V_90 <= V_91 [ 1 ] . V_90 )
V_91 [ 1 ] = V_91 [ 2 ] = V_330 ;
else if ( V_330 . V_90 <= V_91 [ 2 ] . V_90 )
V_91 [ 2 ] = V_330 ;
V_331 = V_99 - V_91 [ 0 ] . V_127 ;
if ( F_102 ( V_331 > V_325 ) ) {
V_91 [ 0 ] = V_91 [ 1 ] ;
V_91 [ 1 ] = V_91 [ 2 ] ;
V_91 [ 2 ] = V_330 ;
if ( V_99 - V_91 [ 0 ] . V_127 > V_325 ) {
V_91 [ 0 ] = V_91 [ 1 ] ;
V_91 [ 1 ] = V_330 ;
if ( V_99 - V_91 [ 0 ] . V_127 > V_325 )
V_91 [ 0 ] = V_330 ;
}
} else if ( V_91 [ 1 ] . V_127 == V_91 [ 0 ] . V_127 && V_331 > V_325 / 4 ) {
V_91 [ 2 ] = V_91 [ 1 ] = V_330 ;
} else if ( V_91 [ 2 ] . V_127 == V_91 [ 1 ] . V_127 && V_331 > V_325 / 2 ) {
V_91 [ 2 ] = V_330 ;
}
}
static inline bool F_187 ( struct V_1 * V_2 , const int V_180 ,
long V_332 , long V_333 ,
long V_334 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_332 < 0 )
V_332 = V_333 ;
if ( V_332 < 0 && V_33 -> V_52 . V_269 && V_33 -> V_52 . V_94 &&
V_180 & V_335 )
V_332 = V_334 = F_186 ( V_79 -
V_33 -> V_52 . V_94 ) ;
if ( V_332 < 0 )
return false ;
F_185 ( V_2 , V_334 ) ;
F_54 ( V_2 , V_332 ) ;
F_61 ( V_2 ) ;
F_2 ( V_2 ) -> V_336 = 0 ;
return true ;
}
void F_188 ( struct V_1 * V_2 , struct V_337 * V_338 )
{
long V_324 = - 1L ;
if ( V_338 && ! V_338 -> V_339 && F_189 ( V_338 ) -> V_340 . V_183 ) {
struct V_173 V_99 ;
F_190 ( & V_99 ) ;
V_324 = F_191 ( & V_99 , & F_189 ( V_338 ) -> V_340 ) ;
}
F_187 ( V_2 , V_341 , V_324 , - 1L , V_324 ) ;
}
static void F_192 ( struct V_1 * V_2 , T_1 V_342 , T_1 V_228 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_236 -> V_343 ( V_2 , V_342 , V_228 ) ;
F_7 ( V_2 ) -> V_83 = V_79 ;
}
void F_193 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_33 -> V_344 )
return;
if ( ! V_33 -> V_116 ) {
F_194 ( V_2 , V_249 ) ;
} else {
T_1 V_345 = F_2 ( V_2 ) -> V_101 ;
if ( V_6 -> V_346 == V_255 ||
V_6 -> V_346 == V_347 ) {
struct V_3 * V_4 = F_103 ( V_2 ) ;
const T_1 V_348 =
F_149 ( V_4 ) + V_345 ;
T_5 V_295 = ( T_5 ) ( V_348 - V_79 ) ;
if ( V_295 > 0 )
V_345 = V_295 ;
}
F_136 ( V_2 , V_249 , V_345 ,
V_250 ) ;
}
}
void F_195 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
F_193 ( V_2 ) ;
if ( ! V_33 -> V_259 )
return;
F_178 ( V_2 , false ) ;
F_146 ( V_2 , 1 ) ;
F_177 ( V_2 ) ;
}
static T_1 F_196 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_1 V_349 ;
F_89 ( ! F_55 ( F_18 ( V_4 ) -> V_95 , V_33 -> V_108 ) ) ;
V_349 = F_76 ( V_4 ) ;
if ( F_197 ( V_2 , V_4 , V_33 -> V_108 - F_18 ( V_4 ) -> V_80 ) )
return 0 ;
V_349 -= F_76 ( V_4 ) ;
if ( V_349 ) {
F_89 ( F_76 ( V_4 ) == 0 ) ;
F_89 ( ! F_48 ( F_18 ( V_4 ) -> V_80 , F_18 ( V_4 ) -> V_95 ) ) ;
}
return V_349 ;
}
static void F_198 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_155 )
{
const struct V_56 * V_350 ;
if ( F_58 ( ! F_18 ( V_4 ) -> V_351 ) )
return;
V_350 = F_3 ( V_4 ) ;
if ( ! F_48 ( V_350 -> V_352 , V_155 ) &&
F_48 ( V_350 -> V_352 , F_7 ( V_2 ) -> V_108 ) )
F_199 ( V_4 , NULL , V_2 , V_353 ) ;
}
static int F_200 ( struct V_1 * V_2 , int V_354 ,
T_1 V_155 , int * V_228 ,
struct V_170 * V_355 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_173 V_356 , V_357 , V_99 ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_1 V_227 = V_33 -> V_137 ;
T_1 V_141 = V_33 -> V_116 ;
bool V_358 = true ;
long V_333 = - 1L ;
long V_332 = - 1L ;
long V_334 = - 1L ;
struct V_3 * V_4 ;
T_1 V_359 = 0 ;
T_1 V_360 = 0 ;
bool V_361 ;
int V_180 = 0 ;
V_356 . V_183 = 0 ;
while ( ( V_4 = F_103 ( V_2 ) ) && V_4 != F_108 ( V_2 ) ) {
struct V_362 * V_363 = F_18 ( V_4 ) ;
T_4 V_145 = V_363 -> V_145 ;
T_1 V_364 ;
F_198 ( V_2 , V_4 , V_155 ) ;
if ( F_55 ( V_363 -> V_95 , V_33 -> V_108 ) ) {
if ( F_76 ( V_4 ) == 1 ||
! F_55 ( V_33 -> V_108 , V_363 -> V_80 ) )
break;
V_364 = F_196 ( V_2 , V_4 ) ;
if ( ! V_364 )
break;
V_358 = false ;
} else {
F_201 ( V_4 -> V_365 ) ;
V_364 = F_76 ( V_4 ) ;
}
if ( F_102 ( V_145 & V_176 ) ) {
if ( V_145 & V_177 )
V_33 -> V_178 -= V_364 ;
V_180 |= V_297 ;
} else if ( ! ( V_145 & V_147 ) ) {
V_357 = V_4 -> V_173 ;
F_164 ( V_357 . V_183 == 0 ) ;
if ( ! V_356 . V_183 )
V_356 = V_357 ;
V_360 = F_18 ( V_4 ) -> V_366 . V_367 ;
V_141 = F_9 ( V_359 , V_141 ) ;
if ( ! F_55 ( V_363 -> V_95 , V_33 -> V_179 ) )
V_180 |= V_181 ;
}
if ( V_145 & V_147 ) {
V_33 -> V_137 -= V_364 ;
} else if ( F_144 ( V_33 ) ) {
V_33 -> V_186 += V_364 ;
if ( ! F_148 ( V_33 , V_4 ) )
F_85 ( V_33 , & V_4 -> V_173 , V_145 ) ;
}
if ( V_145 & V_146 )
V_33 -> V_143 -= V_364 ;
V_33 -> V_116 -= V_364 ;
V_359 += V_364 ;
if ( F_58 ( ! ( V_363 -> V_193 & V_368 ) ) ) {
V_180 |= V_369 ;
} else {
V_180 |= V_341 ;
V_33 -> V_270 = 0 ;
}
if ( ! V_358 )
break;
F_94 ( V_4 , V_2 ) ;
F_95 ( V_2 , V_4 ) ;
if ( F_102 ( V_4 == V_33 -> V_142 ) )
V_33 -> V_142 = NULL ;
if ( F_102 ( V_4 == V_33 -> V_122 ) )
V_33 -> V_122 = NULL ;
}
if ( F_58 ( F_202 ( V_33 -> V_370 , V_155 , V_33 -> V_108 ) ) )
V_33 -> V_370 = V_33 -> V_108 ;
if ( V_4 && ( F_18 ( V_4 ) -> V_145 & V_147 ) )
V_180 |= V_247 ;
F_190 ( & V_99 ) ;
if ( F_58 ( V_356 . V_183 ) && ! ( V_180 & V_297 ) ) {
V_332 = F_191 ( & V_99 , & V_356 ) ;
V_334 = F_191 ( & V_99 , & V_357 ) ;
}
if ( V_355 -> V_182 . V_183 ) {
V_333 = F_191 ( & V_99 , & V_355 -> V_182 ) ;
V_334 = F_191 ( & V_99 , & V_355 -> V_184 ) ;
}
V_361 = F_187 ( V_2 , V_180 , V_332 , V_333 ,
V_334 ) ;
if ( V_180 & V_335 ) {
F_193 ( V_2 ) ;
if ( F_102 ( V_6 -> V_245 . V_246 &&
! F_55 ( V_33 -> V_322 . V_371 , V_33 -> V_108 ) ) ) {
F_171 ( V_2 ) ;
}
if ( F_69 ( V_33 ) ) {
F_124 ( V_2 , V_359 ) ;
} else {
int V_295 ;
if ( V_141 < V_354 )
F_68 ( V_2 , V_33 -> V_136 - V_141 , 0 ) ;
V_295 = F_66 ( V_33 ) ? V_359 :
V_227 - V_33 -> V_137 ;
V_33 -> V_187 -= F_9 ( V_33 -> V_187 , V_295 ) ;
}
V_33 -> V_136 -= F_9 ( V_359 , V_33 -> V_136 ) ;
} else if ( V_4 && V_361 && V_333 >= 0 &&
V_333 > F_191 ( & V_99 , & V_4 -> V_173 ) ) {
F_193 ( V_2 ) ;
}
if ( V_6 -> V_236 -> V_359 ) {
struct V_372 V_86 = { . V_359 = V_359 ,
. V_324 = V_334 ,
. V_367 = V_360 } ;
V_6 -> V_236 -> V_359 ( V_2 , & V_86 ) ;
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
* V_228 = V_359 ;
return V_180 ;
}
static void F_203 ( struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_55 ( F_18 ( F_108 ( V_2 ) ) -> V_95 , F_181 ( V_33 ) ) ) {
V_6 -> V_336 = 0 ;
F_194 ( V_2 , V_373 ) ;
} else {
unsigned long V_268 = F_204 ( V_2 , V_250 ) ;
F_136 ( V_2 , V_373 ,
V_268 , V_250 ) ;
}
}
static inline bool F_205 ( const struct V_1 * V_2 , const int V_180 )
{
return ! ( V_180 & V_374 ) || ( V_180 & V_375 ) ||
F_2 ( V_2 ) -> V_135 != V_285 ;
}
static inline bool F_206 ( const struct V_1 * V_2 , const int V_180 )
{
if ( F_7 ( V_2 ) -> V_59 > F_71 ( V_2 ) -> V_241 . V_242 )
return V_180 & V_376 ;
return V_180 & V_369 ;
}
static void F_207 ( struct V_1 * V_2 , T_1 V_342 , T_1 V_377 ,
int V_180 )
{
if ( F_179 ( V_2 ) ) {
F_163 ( V_2 , V_377 , V_180 ) ;
} else if ( F_206 ( V_2 , V_180 ) ) {
F_192 ( V_2 , V_342 , V_377 ) ;
}
F_57 ( V_2 ) ;
}
static inline bool F_208 ( const struct V_32 * V_33 ,
const T_1 V_342 , const T_1 V_159 ,
const T_1 V_378 )
{
return F_55 ( V_342 , V_33 -> V_108 ) ||
F_55 ( V_159 , V_33 -> V_379 ) ||
( V_159 == V_33 -> V_379 && V_378 > V_33 -> V_380 ) ;
}
static void F_209 ( struct V_32 * V_33 , T_1 V_342 )
{
T_1 V_295 = V_342 - V_33 -> V_108 ;
F_210 ( (struct V_1 * ) V_33 ) ;
F_211 ( & V_33 -> V_381 ) ;
V_33 -> V_382 += V_295 ;
F_212 ( & V_33 -> V_381 ) ;
V_33 -> V_108 = V_342 ;
}
static void F_213 ( struct V_32 * V_33 , T_1 V_80 )
{
T_1 V_295 = V_80 - V_33 -> V_93 ;
F_210 ( (struct V_1 * ) V_33 ) ;
F_211 ( & V_33 -> V_381 ) ;
V_33 -> V_383 += V_295 ;
F_212 ( & V_33 -> V_381 ) ;
V_33 -> V_93 = V_80 ;
}
static int F_214 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_1 V_342 ,
T_1 V_159 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_180 = 0 ;
T_1 V_378 = F_154 ( F_6 ( V_4 ) -> V_63 ) ;
if ( F_58 ( ! F_6 ( V_4 ) -> V_48 ) )
V_378 <<= V_33 -> V_52 . V_384 ;
if ( F_208 ( V_33 , V_342 , V_159 , V_378 ) ) {
V_180 |= V_385 ;
F_215 ( V_33 , V_159 ) ;
if ( V_33 -> V_380 != V_378 ) {
V_33 -> V_380 = V_378 ;
V_33 -> V_386 = 0 ;
F_216 ( V_2 ) ;
if ( F_108 ( V_2 ) )
F_217 ( V_2 ) ;
if ( V_378 > V_33 -> V_150 ) {
V_33 -> V_150 = V_378 ;
F_173 ( V_2 , F_2 ( V_2 ) -> V_305 ) ;
}
}
}
F_209 ( V_33 , V_342 ) ;
return V_180 ;
}
static bool F_218 ( struct V_229 * V_229 , int V_128 ,
T_1 * V_387 )
{
if ( * V_387 ) {
T_5 V_331 = ( T_5 ) ( V_79 - * V_387 ) ;
if ( 0 <= V_331 && V_331 < V_388 ) {
F_70 ( V_229 , V_128 ) ;
return true ;
}
}
* V_387 = V_79 ;
return false ;
}
bool F_219 ( struct V_229 * V_229 , const struct V_3 * V_4 ,
int V_128 , T_1 * V_387 )
{
if ( ( F_18 ( V_4 ) -> V_80 != F_18 ( V_4 ) -> V_95 ) &&
! F_6 ( V_4 ) -> V_48 )
return false ;
return F_218 ( V_229 , V_128 , V_387 ) ;
}
static void F_220 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
static T_1 V_389 ;
static unsigned int V_390 ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_1 V_391 , V_99 ;
if ( F_218 ( F_71 ( V_2 ) ,
V_392 ,
& V_33 -> V_387 ) )
return;
V_99 = V_254 / V_327 ;
if ( V_99 != V_389 ) {
T_1 V_393 = ( V_394 + 1 ) >> 1 ;
V_389 = V_99 ;
F_221 ( V_390 , V_393 +
F_222 ( V_394 ) ) ;
}
V_391 = F_223 ( V_390 ) ;
if ( V_391 > 0 ) {
F_221 ( V_390 , V_391 - 1 ) ;
F_70 ( F_71 ( V_2 ) , V_395 ) ;
F_224 ( V_2 ) ;
}
}
static void F_225 ( struct V_32 * V_33 )
{
V_33 -> V_52 . V_396 = V_33 -> V_52 . V_397 ;
V_33 -> V_52 . V_398 = F_226 () ;
}
static void F_227 ( struct V_32 * V_33 , T_1 V_80 )
{
if ( V_33 -> V_52 . V_269 && ! F_55 ( V_80 , V_33 -> V_399 ) ) {
if ( F_228 ( & V_33 -> V_52 , 0 ) )
F_225 ( V_33 ) ;
}
}
static void F_229 ( struct V_1 * V_2 , T_1 V_342 , int V_180 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_48 ( V_342 , V_33 -> V_289 ) )
return;
if ( V_180 & V_218 ) {
V_33 -> V_289 = 0 ;
} else if ( F_55 ( V_342 , V_33 -> V_289 ) ) {
F_162 ( V_2 ) ;
F_132 ( V_2 , V_299 ) ;
F_166 ( V_2 ) ;
F_168 ( V_2 ) ;
F_70 ( F_71 ( V_2 ) ,
V_400 ) ;
} else if ( ! ( V_180 & ( V_314 |
V_374 | V_185 ) ) ) {
V_33 -> V_289 = 0 ;
}
}
static inline void F_230 ( struct V_1 * V_2 , T_1 V_401 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_236 -> V_402 )
V_6 -> V_236 -> V_402 ( V_2 , V_401 ) ;
}
static void F_231 ( struct V_1 * V_2 , int V_312 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_312 == V_403 )
return;
if ( F_102 ( V_312 == 2 ) ) {
F_232 ( V_2 , F_175 ( V_2 ) ,
V_404 ) ;
if ( F_55 ( V_33 -> V_110 , V_33 -> V_179 ) )
return;
V_33 -> V_243 = 0 ;
}
F_177 ( V_2 ) ;
}
static int F_233 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_180 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_170 V_405 ;
T_1 V_155 = V_33 -> V_108 ;
T_1 V_159 = F_18 ( V_4 ) -> V_80 ;
T_1 V_342 = F_18 ( V_4 ) -> V_159 ;
bool V_311 = false ;
T_1 V_354 ;
int V_406 = V_33 -> V_116 ;
T_1 V_407 = V_33 -> V_186 ;
int V_228 = 0 ;
int V_312 = V_403 ;
V_405 . V_182 . V_183 = 0 ;
F_201 ( V_2 -> V_408 . V_365 ) ;
if ( F_48 ( V_342 , V_155 ) ) {
if ( F_48 ( V_342 , V_155 - V_33 -> V_150 ) ) {
F_220 ( V_2 , V_4 ) ;
return - 1 ;
}
goto V_409;
}
if ( F_55 ( V_342 , V_33 -> V_110 ) )
goto V_410;
if ( V_6 -> V_346 == V_255 ||
V_6 -> V_346 == V_347 )
F_193 ( V_2 ) ;
if ( F_55 ( V_342 , V_155 ) ) {
V_180 |= V_314 ;
V_6 -> V_234 = 0 ;
}
V_354 = V_33 -> V_136 ;
if ( V_180 & V_411 )
F_227 ( V_33 , F_18 ( V_4 ) -> V_80 ) ;
if ( ! ( V_180 & V_412 ) && F_55 ( V_342 , V_155 ) ) {
F_215 ( V_33 , V_159 ) ;
F_209 ( V_33 , V_342 ) ;
V_180 |= V_385 ;
F_230 ( V_2 , V_413 ) ;
F_70 ( F_71 ( V_2 ) , V_414 ) ;
} else {
T_1 V_415 = V_416 ;
if ( V_159 != F_18 ( V_4 ) -> V_95 )
V_180 |= V_417 ;
else
F_70 ( F_71 ( V_2 ) , V_418 ) ;
V_180 |= F_214 ( V_2 , V_4 , V_342 , V_159 ) ;
if ( F_18 ( V_4 ) -> V_145 )
V_180 |= F_115 ( V_2 , V_4 , V_155 ,
& V_405 ) ;
if ( F_24 ( V_33 , F_6 ( V_4 ) ) ) {
V_180 |= V_252 ;
V_415 |= V_419 ;
}
if ( V_180 & V_385 )
V_415 |= V_413 ;
F_230 ( V_2 , V_415 ) ;
}
V_2 -> V_420 = 0 ;
V_6 -> V_421 = 0 ;
V_33 -> V_422 = V_79 ;
if ( ! V_406 )
goto V_423;
V_180 |= F_200 ( V_2 , V_354 , V_155 , & V_228 ,
& V_405 ) ;
if ( F_205 ( V_2 , V_180 ) ) {
V_311 = ! ( V_180 & ( V_314 | V_374 ) ) ;
F_183 ( V_2 , V_228 , V_311 , & V_180 , & V_312 ) ;
}
if ( V_33 -> V_289 )
F_229 ( V_2 , V_342 , V_180 ) ;
if ( ( V_180 & V_376 ) || ! ( V_180 & V_374 ) ) {
struct V_29 * V_30 = F_12 ( V_2 ) ;
if ( V_30 )
F_234 ( V_30 ) ;
}
if ( V_6 -> V_346 == V_249 )
F_235 ( V_2 ) ;
F_207 ( V_2 , V_342 , V_33 -> V_186 - V_407 , V_180 ) ;
F_231 ( V_2 , V_312 ) ;
return 1 ;
V_423:
if ( V_180 & V_218 )
F_183 ( V_2 , V_228 , V_311 , & V_180 , & V_312 ) ;
if ( F_108 ( V_2 ) )
F_203 ( V_2 ) ;
if ( V_33 -> V_289 )
F_229 ( V_2 , V_342 , V_180 ) ;
return 1 ;
V_410:
F_236 ( V_2 , L_12 , V_342 , V_33 -> V_108 , V_33 -> V_110 ) ;
return - 1 ;
V_409:
if ( F_18 ( V_4 ) -> V_145 ) {
V_180 |= F_115 ( V_2 , V_4 , V_155 ,
& V_405 ) ;
F_183 ( V_2 , V_228 , V_311 , & V_180 , & V_312 ) ;
F_231 ( V_2 , V_312 ) ;
}
F_236 ( V_2 , L_13 , V_342 , V_33 -> V_108 , V_33 -> V_110 ) ;
return 0 ;
}
static void F_237 ( int V_10 , const unsigned char * V_424 ,
bool V_48 , struct V_425 * V_426 ,
bool V_427 )
{
if ( ! V_426 || ! V_48 || V_10 < 0 || ( V_10 & 1 ) )
return;
if ( V_10 >= V_428 &&
V_10 <= V_429 )
memcpy ( V_426 -> V_430 , V_424 , V_10 ) ;
else if ( V_10 != 0 )
V_10 = - 1 ;
V_426 -> V_10 = V_10 ;
V_426 -> exp = V_427 ;
}
void F_238 ( const struct V_3 * V_4 ,
struct V_431 * V_432 , int V_433 ,
struct V_425 * V_426 )
{
const unsigned char * V_209 ;
const struct V_15 * V_46 = F_6 ( V_4 ) ;
int V_434 = ( V_46 -> V_435 * 4 ) - sizeof( struct V_15 ) ;
V_209 = ( const unsigned char * ) ( V_46 + 1 ) ;
V_432 -> V_269 = 0 ;
while ( V_434 > 0 ) {
int V_436 = * V_209 ++ ;
int V_437 ;
switch ( V_436 ) {
case V_438 :
return;
case V_439 :
V_434 -- ;
continue;
default:
V_437 = * V_209 ++ ;
if ( V_437 < 2 )
return;
if ( V_437 > V_434 )
return;
switch ( V_436 ) {
case V_440 :
if ( V_437 == V_441 && V_46 -> V_48 && ! V_433 ) {
T_6 V_442 = F_239 ( V_209 ) ;
if ( V_442 ) {
if ( V_432 -> V_443 &&
V_432 -> V_443 < V_442 )
V_442 = V_432 -> V_443 ;
V_432 -> V_53 = V_442 ;
}
}
break;
case V_444 :
if ( V_437 == V_445 && V_46 -> V_48 &&
! V_433 && V_446 ) {
T_7 V_384 = * ( T_7 * ) V_209 ;
V_432 -> V_447 = 1 ;
if ( V_384 > 14 ) {
F_240 ( L_14 ,
V_448 ,
V_384 ) ;
V_384 = 14 ;
}
V_432 -> V_384 = V_384 ;
}
break;
case V_449 :
if ( ( V_437 == V_450 ) &&
( ( V_433 && V_432 -> V_451 ) ||
( ! V_433 && V_452 ) ) ) {
V_432 -> V_269 = 1 ;
V_432 -> V_397 = F_80 ( V_209 ) ;
V_432 -> V_94 = F_80 ( V_209 + 4 ) ;
}
break;
case V_453 :
if ( V_437 == V_454 && V_46 -> V_48 &&
! V_433 && V_455 ) {
V_432 -> V_123 = V_456 ;
F_241 ( V_432 ) ;
}
break;
case V_457 :
if ( ( V_437 >= ( V_212 + V_458 ) ) &&
! ( ( V_437 - V_212 ) % V_458 ) &&
V_432 -> V_123 ) {
F_18 ( V_4 ) -> V_145 = ( V_209 - 2 ) - ( unsigned char * ) V_46 ;
}
break;
#ifdef F_242
case V_459 :
break;
#endif
case V_460 :
F_237 (
V_437 - V_461 ,
V_209 , V_46 -> V_48 , V_426 , false ) ;
break;
case V_462 :
if ( V_437 >= V_463 &&
F_239 ( V_209 ) ==
V_464 )
F_237 ( V_437 -
V_463 ,
V_209 + 2 , V_46 -> V_48 , V_426 , true ) ;
break;
}
V_209 += V_437 - 2 ;
V_434 -= V_437 ;
}
}
}
static bool F_243 ( struct V_32 * V_33 , const struct V_15 * V_46 )
{
const T_8 * V_209 = ( const T_8 * ) ( V_46 + 1 ) ;
if ( * V_209 == F_244 ( ( V_439 << 24 ) | ( V_439 << 16 )
| ( V_449 << 8 ) | V_450 ) ) {
V_33 -> V_52 . V_269 = 1 ;
++ V_209 ;
V_33 -> V_52 . V_397 = F_245 ( * V_209 ) ;
++ V_209 ;
if ( * V_209 )
V_33 -> V_52 . V_94 = F_245 ( * V_209 ) - V_33 -> V_465 ;
else
V_33 -> V_52 . V_94 = 0 ;
return true ;
}
return false ;
}
static bool F_246 ( const struct V_3 * V_4 ,
const struct V_15 * V_46 , struct V_32 * V_33 )
{
if ( V_46 -> V_435 == ( sizeof( * V_46 ) / 4 ) ) {
V_33 -> V_52 . V_269 = 0 ;
return false ;
} else if ( V_33 -> V_52 . V_451 &&
V_46 -> V_435 == ( ( sizeof( * V_46 ) + V_466 ) / 4 ) ) {
if ( F_243 ( V_33 , V_46 ) )
return true ;
}
F_238 ( V_4 , & V_33 -> V_52 , 1 , NULL ) ;
if ( V_33 -> V_52 . V_269 && V_33 -> V_52 . V_94 )
V_33 -> V_52 . V_94 -= V_33 -> V_465 ;
return true ;
}
const T_4 * F_247 ( const struct V_15 * V_46 )
{
int V_434 = ( V_46 -> V_435 << 2 ) - sizeof( * V_46 ) ;
const T_4 * V_209 = ( const T_4 * ) ( V_46 + 1 ) ;
if ( V_434 < V_467 )
return NULL ;
while ( V_434 > 0 ) {
int V_436 = * V_209 ++ ;
int V_437 ;
switch ( V_436 ) {
case V_438 :
return NULL ;
case V_439 :
V_434 -- ;
continue;
default:
V_437 = * V_209 ++ ;
if ( V_437 < 2 || V_437 > V_434 )
return NULL ;
if ( V_436 == V_459 )
return V_437 == V_467 ? V_209 : NULL ;
}
V_209 += V_437 - 2 ;
V_434 -= V_437 ;
}
return NULL ;
}
static int F_248 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
const struct V_15 * V_46 = F_6 ( V_4 ) ;
T_1 V_80 = F_18 ( V_4 ) -> V_80 ;
T_1 V_342 = F_18 ( V_4 ) -> V_159 ;
return (
( V_46 -> V_342 && V_80 == F_18 ( V_4 ) -> V_95 && V_80 == V_33 -> V_93 ) &&
V_342 == V_33 -> V_108 &&
! F_208 ( V_33 , V_342 , V_80 , F_154 ( V_46 -> V_63 ) << V_33 -> V_52 . V_384 ) &&
( T_5 ) ( V_33 -> V_52 . V_396 - V_33 -> V_52 . V_397 ) <= ( F_2 ( V_2 ) -> V_101 * 1024 ) / V_327 ) ;
}
static inline bool F_249 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
return ! F_228 ( & V_33 -> V_52 , V_468 ) &&
! F_248 ( V_2 , V_4 ) ;
}
static inline bool F_250 ( const struct V_32 * V_33 , T_1 V_80 , T_1 V_95 )
{
return ! F_48 ( V_95 , V_33 -> V_399 ) &&
! F_55 ( V_80 , V_33 -> V_93 + F_251 ( V_33 ) ) ;
}
void F_252 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_469 ) {
case V_470 :
V_2 -> V_471 = V_472 ;
break;
case V_473 :
V_2 -> V_471 = V_474 ;
break;
case V_475 :
return;
default:
V_2 -> V_471 = V_476 ;
}
F_253 () ;
if ( ! F_254 ( V_2 , V_477 ) )
V_2 -> V_478 ( V_2 ) ;
F_255 ( V_2 ) ;
}
void F_256 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
F_52 ( V_2 ) ;
V_2 -> V_479 |= V_480 ;
F_257 ( V_2 , V_481 ) ;
switch ( V_2 -> V_469 ) {
case V_482 :
case V_483 :
F_258 ( V_2 , V_473 ) ;
F_2 ( V_2 ) -> V_8 . V_26 = 1 ;
break;
case V_473 :
case V_484 :
break;
case V_485 :
break;
case V_486 :
F_224 ( V_2 ) ;
F_258 ( V_2 , V_484 ) ;
break;
case V_487 :
F_224 ( V_2 ) ;
F_259 ( V_2 , V_488 , 0 ) ;
break;
default:
F_260 ( L_15 ,
V_448 , V_2 -> V_469 ) ;
break;
}
F_261 ( & V_33 -> V_489 ) ;
if ( F_144 ( V_33 ) )
F_241 ( & V_33 -> V_52 ) ;
F_53 ( V_2 ) ;
if ( ! F_254 ( V_2 , V_477 ) ) {
V_2 -> V_490 ( V_2 ) ;
if ( V_2 -> V_479 == V_491 ||
V_2 -> V_469 == V_475 )
F_262 ( V_2 , V_492 , V_493 ) ;
else
F_262 ( V_2 , V_492 , V_494 ) ;
}
}
static inline bool F_263 ( struct V_202 * V_153 , T_1 V_80 ,
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
static void F_264 ( struct V_1 * V_2 , T_1 V_80 , T_1 V_95 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_144 ( V_33 ) && V_495 ) {
int V_128 ;
if ( F_48 ( V_80 , V_33 -> V_93 ) )
V_128 = V_496 ;
else
V_128 = V_497 ;
F_70 ( F_71 ( V_2 ) , V_128 ) ;
V_33 -> V_52 . V_498 = 1 ;
V_33 -> V_499 [ 0 ] . V_149 = V_80 ;
V_33 -> V_499 [ 0 ] . V_95 = V_95 ;
}
}
static void F_265 ( struct V_1 * V_2 , T_1 V_80 , T_1 V_95 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( ! V_33 -> V_52 . V_498 )
F_264 ( V_2 , V_80 , V_95 ) ;
else
F_263 ( V_33 -> V_499 , V_80 , V_95 ) ;
}
static void F_266 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_18 ( V_4 ) -> V_95 != F_18 ( V_4 ) -> V_80 &&
F_48 ( F_18 ( V_4 ) -> V_80 , V_33 -> V_93 ) ) {
F_70 ( F_71 ( V_2 ) , V_500 ) ;
F_10 ( V_2 ) ;
if ( F_144 ( V_33 ) && V_495 ) {
T_1 V_95 = F_18 ( V_4 ) -> V_95 ;
if ( F_55 ( F_18 ( V_4 ) -> V_95 , V_33 -> V_93 ) )
V_95 = V_33 -> V_93 ;
F_264 ( V_2 , F_18 ( V_4 ) -> V_80 , V_95 ) ;
}
}
F_224 ( V_2 ) ;
}
static void F_267 ( struct V_32 * V_33 )
{
int V_501 ;
struct V_202 * V_153 = & V_33 -> V_502 [ 0 ] ;
struct V_202 * V_503 = V_153 + 1 ;
for ( V_501 = 1 ; V_501 < V_33 -> V_52 . V_154 ; ) {
if ( F_263 ( V_153 , V_503 -> V_149 , V_503 -> V_95 ) ) {
int V_215 ;
V_33 -> V_52 . V_154 -- ;
for ( V_215 = V_501 ; V_215 < V_33 -> V_52 . V_154 ; V_215 ++ )
V_153 [ V_215 ] = V_153 [ V_215 + 1 ] ;
continue;
}
V_501 ++ , V_503 ++ ;
}
}
static void F_268 ( struct V_1 * V_2 , T_1 V_80 , T_1 V_95 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_202 * V_153 = & V_33 -> V_502 [ 0 ] ;
int V_504 = V_33 -> V_52 . V_154 ;
int V_501 ;
if ( ! V_504 )
goto V_505;
for ( V_501 = 0 ; V_501 < V_504 ; V_501 ++ , V_153 ++ ) {
if ( F_263 ( V_153 , V_80 , V_95 ) ) {
for (; V_501 > 0 ; V_501 -- , V_153 -- )
F_118 ( * V_153 , * ( V_153 - 1 ) ) ;
if ( V_504 > 1 )
F_267 ( V_33 ) ;
return;
}
}
if ( V_501 >= V_211 ) {
V_501 -- ;
V_33 -> V_52 . V_154 -- ;
V_153 -- ;
}
for (; V_501 > 0 ; V_501 -- , V_153 -- )
* V_153 = * ( V_153 - 1 ) ;
V_505:
V_153 -> V_149 = V_80 ;
V_153 -> V_95 = V_95 ;
V_33 -> V_52 . V_154 ++ ;
}
static void F_269 ( struct V_32 * V_33 )
{
struct V_202 * V_153 = & V_33 -> V_502 [ 0 ] ;
int V_154 = V_33 -> V_52 . V_154 ;
int V_501 ;
if ( F_270 ( & V_33 -> V_489 ) ) {
V_33 -> V_52 . V_154 = 0 ;
return;
}
for ( V_501 = 0 ; V_501 < V_154 ; ) {
if ( ! F_48 ( V_33 -> V_93 , V_153 -> V_149 ) ) {
int V_215 ;
F_116 ( F_48 ( V_33 -> V_93 , V_153 -> V_95 ) ) ;
for ( V_215 = V_501 + 1 ; V_215 < V_154 ; V_215 ++ )
V_33 -> V_502 [ V_215 - 1 ] = V_33 -> V_502 [ V_215 ] ;
V_154 -- ;
continue;
}
V_501 ++ ;
V_153 ++ ;
}
V_33 -> V_52 . V_154 = V_154 ;
}
static bool F_271 ( struct V_1 * V_2 ,
struct V_3 * V_506 ,
struct V_3 * V_507 ,
bool * V_508 )
{
int V_295 ;
* V_508 = false ;
if ( F_18 ( V_507 ) -> V_80 != F_18 ( V_506 ) -> V_95 )
return false ;
if ( ! F_272 ( V_506 , V_507 , V_508 , & V_295 ) )
return false ;
F_273 ( V_295 , & V_2 -> V_84 ) ;
F_274 ( V_2 , V_295 ) ;
F_70 ( F_71 ( V_2 ) , V_509 ) ;
F_18 ( V_506 ) -> V_95 = F_18 ( V_507 ) -> V_95 ;
F_18 ( V_506 ) -> V_159 = F_18 ( V_507 ) -> V_159 ;
F_18 ( V_506 ) -> V_193 |= F_18 ( V_507 ) -> V_193 ;
return true ;
}
static void F_275 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_276 ( V_2 , V_4 ) ;
F_277 ( V_4 ) ;
}
static void F_278 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_3 V_510 = V_33 -> V_93 ;
struct V_3 * V_4 , * V_511 ;
bool V_508 , V_512 ;
while ( ( V_4 = F_279 ( & V_33 -> V_489 ) ) != NULL ) {
if ( F_55 ( F_18 ( V_4 ) -> V_80 , V_33 -> V_93 ) )
break;
if ( F_48 ( F_18 ( V_4 ) -> V_80 , V_510 ) ) {
T_3 V_498 = V_510 ;
if ( F_48 ( F_18 ( V_4 ) -> V_95 , V_510 ) )
V_510 = F_18 ( V_4 ) -> V_95 ;
F_265 ( V_2 , F_18 ( V_4 ) -> V_80 , V_498 ) ;
}
F_280 ( V_4 , & V_33 -> V_489 ) ;
if ( ! F_55 ( F_18 ( V_4 ) -> V_95 , V_33 -> V_93 ) ) {
F_236 ( V_2 , L_16 ) ;
F_275 ( V_2 , V_4 ) ;
continue;
}
F_236 ( V_2 , L_17 ,
V_33 -> V_93 , F_18 ( V_4 ) -> V_80 ,
F_18 ( V_4 ) -> V_95 ) ;
V_511 = F_281 ( & V_2 -> V_513 ) ;
V_512 = V_511 && F_271 ( V_2 , V_511 , V_4 , & V_508 ) ;
F_213 ( V_33 , F_18 ( V_4 ) -> V_95 ) ;
if ( ! V_512 )
F_282 ( & V_2 -> V_513 , V_4 ) ;
if ( F_18 ( V_4 ) -> V_193 & V_195 )
F_256 ( V_2 ) ;
if ( V_512 )
F_283 ( V_4 , V_508 ) ;
}
}
static int F_284 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_514 )
{
if ( F_43 ( & V_2 -> V_84 ) > V_2 -> V_72 ||
! F_285 ( V_2 , V_4 , V_514 ) ) {
if ( F_286 ( V_2 ) < 0 )
return - 1 ;
if ( ! F_285 ( V_2 , V_4 , V_514 ) ) {
if ( ! F_287 ( V_2 ) )
return - 1 ;
if ( ! F_285 ( V_2 , V_4 , V_514 ) )
return - 1 ;
}
}
return 0 ;
}
static void F_288 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_515 ;
T_1 V_80 , V_95 ;
F_21 ( V_33 , V_4 ) ;
if ( F_102 ( F_284 ( V_2 , V_4 , V_4 -> V_62 ) ) ) {
F_70 ( F_71 ( V_2 ) , V_516 ) ;
F_275 ( V_2 , V_4 ) ;
return;
}
V_33 -> V_386 = 0 ;
F_52 ( V_2 ) ;
F_70 ( F_71 ( V_2 ) , V_517 ) ;
F_236 ( V_2 , L_18 ,
V_33 -> V_93 , F_18 ( V_4 ) -> V_80 , F_18 ( V_4 ) -> V_95 ) ;
V_515 = F_281 ( & V_33 -> V_489 ) ;
if ( ! V_515 ) {
if ( F_144 ( V_33 ) ) {
V_33 -> V_52 . V_154 = 1 ;
V_33 -> V_502 [ 0 ] . V_149 = F_18 ( V_4 ) -> V_80 ;
V_33 -> V_502 [ 0 ] . V_95 =
F_18 ( V_4 ) -> V_95 ;
}
F_289 ( & V_33 -> V_489 , V_4 ) ;
goto V_518;
}
V_80 = F_18 ( V_4 ) -> V_80 ;
V_95 = F_18 ( V_4 ) -> V_95 ;
if ( V_80 == F_18 ( V_515 ) -> V_95 ) {
bool V_508 ;
if ( ! F_271 ( V_2 , V_515 , V_4 , & V_508 ) ) {
F_290 ( & V_33 -> V_489 , V_515 , V_4 ) ;
} else {
F_31 ( V_2 , V_4 ) ;
F_283 ( V_4 , V_508 ) ;
V_4 = NULL ;
}
if ( ! V_33 -> V_52 . V_154 ||
V_33 -> V_502 [ 0 ] . V_95 != V_80 )
goto V_519;
V_33 -> V_502 [ 0 ] . V_95 = V_95 ;
goto V_518;
}
while ( 1 ) {
if ( ! F_55 ( F_18 ( V_515 ) -> V_80 , V_80 ) )
break;
if ( F_291 ( & V_33 -> V_489 , V_515 ) ) {
V_515 = NULL ;
break;
}
V_515 = F_292 ( & V_33 -> V_489 , V_515 ) ;
}
if ( V_515 && F_48 ( V_80 , F_18 ( V_515 ) -> V_95 ) ) {
if ( ! F_55 ( V_95 , F_18 ( V_515 ) -> V_95 ) ) {
F_70 ( F_71 ( V_2 ) , V_520 ) ;
F_275 ( V_2 , V_4 ) ;
V_4 = NULL ;
F_264 ( V_2 , V_80 , V_95 ) ;
goto V_519;
}
if ( F_55 ( V_80 , F_18 ( V_515 ) -> V_80 ) ) {
F_264 ( V_2 , V_80 ,
F_18 ( V_515 ) -> V_95 ) ;
} else {
if ( F_291 ( & V_33 -> V_489 ,
V_515 ) )
V_515 = NULL ;
else
V_515 = F_292 (
& V_33 -> V_489 ,
V_515 ) ;
}
}
if ( ! V_515 )
F_289 ( & V_33 -> V_489 , V_4 ) ;
else
F_290 ( & V_33 -> V_489 , V_515 , V_4 ) ;
while ( ! F_293 ( & V_33 -> V_489 , V_4 ) ) {
V_515 = F_294 ( & V_33 -> V_489 , V_4 ) ;
if ( ! F_55 ( V_95 , F_18 ( V_515 ) -> V_80 ) )
break;
if ( F_48 ( V_95 , F_18 ( V_515 ) -> V_95 ) ) {
F_265 ( V_2 , F_18 ( V_515 ) -> V_80 ,
V_95 ) ;
break;
}
F_280 ( V_515 , & V_33 -> V_489 ) ;
F_265 ( V_2 , F_18 ( V_515 ) -> V_80 ,
F_18 ( V_515 ) -> V_95 ) ;
F_70 ( F_71 ( V_2 ) , V_520 ) ;
F_275 ( V_2 , V_515 ) ;
}
V_519:
if ( F_144 ( V_33 ) )
F_268 ( V_2 , V_80 , V_95 ) ;
V_518:
if ( V_4 ) {
F_31 ( V_2 , V_4 ) ;
F_295 ( V_4 , V_2 ) ;
}
}
static int T_9 F_296 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_521 ,
bool * V_508 )
{
int V_512 ;
struct V_3 * V_511 = F_281 ( & V_2 -> V_513 ) ;
F_297 ( V_4 , V_521 ) ;
V_512 = ( V_511 &&
F_271 ( V_2 , V_511 , V_4 , V_508 ) ) ? 1 : 0 ;
F_213 ( F_7 ( V_2 ) , F_18 ( V_4 ) -> V_95 ) ;
if ( ! V_512 ) {
F_282 ( & V_2 -> V_513 , V_4 ) ;
F_295 ( V_4 , V_2 ) ;
}
return V_512 ;
}
int F_298 ( struct V_1 * V_2 , struct V_522 * V_271 , T_10 V_514 )
{
struct V_3 * V_4 ;
int V_164 = - V_523 ;
int V_524 = 0 ;
bool V_508 ;
if ( V_514 == 0 )
return 0 ;
if ( V_514 > V_525 ) {
int V_526 = F_45 ( T_10 , V_514 >> V_527 , V_528 ) ;
V_524 = V_526 << V_527 ;
V_514 = V_524 + ( V_514 & ~ V_529 ) ;
}
V_4 = F_299 ( V_514 - V_524 , V_524 ,
V_530 ,
& V_164 , V_2 -> V_531 ) ;
if ( ! V_4 )
goto V_164;
F_300 ( V_4 , V_514 - V_524 ) ;
V_4 -> V_524 = V_524 ;
V_4 -> V_10 = V_514 ;
if ( F_284 ( V_2 , V_4 , V_4 -> V_62 ) )
goto V_532;
V_164 = F_301 ( V_4 , 0 , & V_271 -> V_533 , V_514 ) ;
if ( V_164 )
goto V_532;
F_18 ( V_4 ) -> V_80 = F_7 ( V_2 ) -> V_93 ;
F_18 ( V_4 ) -> V_95 = F_18 ( V_4 ) -> V_80 + V_514 ;
F_18 ( V_4 ) -> V_159 = F_7 ( V_2 ) -> V_108 - 1 ;
if ( F_296 ( V_2 , V_4 , 0 , & V_508 ) ) {
F_164 ( V_508 ) ;
F_277 ( V_4 ) ;
}
return V_514 ;
V_532:
F_302 ( V_4 ) ;
V_164:
return V_164 ;
}
static void F_303 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
bool V_508 = false ;
int V_512 = - 1 ;
if ( F_18 ( V_4 ) -> V_80 == F_18 ( V_4 ) -> V_95 ) {
F_277 ( V_4 ) ;
return;
}
F_304 ( V_4 ) ;
F_297 ( V_4 , F_6 ( V_4 ) -> V_435 * 4 ) ;
F_15 ( V_33 , V_4 ) ;
V_33 -> V_52 . V_498 = 0 ;
if ( F_18 ( V_4 ) -> V_80 == V_33 -> V_93 ) {
if ( F_251 ( V_33 ) == 0 )
goto V_534;
if ( V_33 -> V_535 . V_536 == V_537 &&
V_33 -> V_81 == V_33 -> V_93 && V_33 -> V_535 . V_10 &&
F_305 ( V_2 ) && ! V_33 -> V_538 ) {
int V_539 = F_45 (unsigned int, skb->len,
tp->ucopy.len) ;
F_306 ( V_540 ) ;
if ( ! F_307 ( V_4 , 0 , V_33 -> V_535 . V_271 , V_539 ) ) {
V_33 -> V_535 . V_10 -= V_539 ;
V_33 -> V_81 += V_539 ;
V_512 = ( V_539 == V_4 -> V_10 ) ;
F_50 ( V_2 ) ;
}
}
if ( V_512 <= 0 ) {
V_541:
if ( V_512 < 0 ) {
if ( F_308 ( & V_2 -> V_513 ) == 0 )
F_309 ( V_2 , V_4 -> V_62 ) ;
else if ( F_284 ( V_2 , V_4 , V_4 -> V_62 ) )
goto V_542;
}
V_512 = F_296 ( V_2 , V_4 , 0 , & V_508 ) ;
}
F_213 ( V_33 , F_18 ( V_4 ) -> V_95 ) ;
if ( V_4 -> V_10 )
F_51 ( V_2 , V_4 ) ;
if ( F_18 ( V_4 ) -> V_193 & V_195 )
F_256 ( V_2 ) ;
if ( ! F_270 ( & V_33 -> V_489 ) ) {
F_278 ( V_2 ) ;
if ( F_270 ( & V_33 -> V_489 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 0 ;
}
if ( V_33 -> V_52 . V_154 )
F_269 ( V_33 ) ;
F_216 ( V_2 ) ;
if ( V_512 > 0 )
F_283 ( V_4 , V_508 ) ;
if ( ! F_254 ( V_2 , V_477 ) )
V_2 -> V_543 ( V_2 ) ;
return;
}
if ( ! F_55 ( F_18 ( V_4 ) -> V_95 , V_33 -> V_93 ) ) {
F_70 ( F_71 ( V_2 ) , V_500 ) ;
F_264 ( V_2 , F_18 ( V_4 ) -> V_80 , F_18 ( V_4 ) -> V_95 ) ;
V_534:
F_10 ( V_2 ) ;
F_52 ( V_2 ) ;
V_542:
F_275 ( V_2 , V_4 ) ;
return;
}
if ( ! F_48 ( F_18 ( V_4 ) -> V_80 , V_33 -> V_93 + F_251 ( V_33 ) ) )
goto V_534;
F_10 ( V_2 ) ;
if ( F_48 ( F_18 ( V_4 ) -> V_80 , V_33 -> V_93 ) ) {
F_236 ( V_2 , L_19 ,
V_33 -> V_93 , F_18 ( V_4 ) -> V_80 ,
F_18 ( V_4 ) -> V_95 ) ;
F_264 ( V_2 , F_18 ( V_4 ) -> V_80 , V_33 -> V_93 ) ;
if ( ! F_251 ( V_33 ) )
goto V_534;
goto V_541;
}
F_288 ( V_2 , V_4 ) ;
}
static struct V_3 * F_310 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_544 * V_545 )
{
struct V_3 * V_365 = NULL ;
if ( ! F_293 ( V_545 , V_4 ) )
V_365 = F_294 ( V_545 , V_4 ) ;
F_280 ( V_4 , V_545 ) ;
F_277 ( V_4 ) ;
F_70 ( F_71 ( V_2 ) , V_546 ) ;
return V_365 ;
}
static void
F_311 ( struct V_1 * V_2 , struct V_544 * V_545 ,
struct V_3 * V_547 , struct V_3 * V_511 ,
T_1 V_548 , T_1 V_518 )
{
struct V_3 * V_4 , * V_549 ;
bool V_550 ;
V_4 = V_547 ;
V_551:
V_550 = true ;
F_312 (list, skb, n) {
if ( V_4 == V_511 )
break;
if ( ! F_48 ( V_548 , F_18 ( V_4 ) -> V_95 ) ) {
V_4 = F_310 ( V_2 , V_4 , V_545 ) ;
if ( ! V_4 )
break;
goto V_551;
}
if ( ! ( F_18 ( V_4 ) -> V_193 & ( V_368 | V_195 ) ) &&
( F_30 ( V_4 -> V_62 ) > V_4 -> V_10 ||
F_48 ( F_18 ( V_4 ) -> V_80 , V_548 ) ) ) {
V_550 = false ;
break;
}
if ( ! F_293 ( V_545 , V_4 ) ) {
struct V_3 * V_365 = F_294 ( V_545 , V_4 ) ;
if ( V_365 != V_511 &&
F_18 ( V_4 ) -> V_95 != F_18 ( V_365 ) -> V_80 ) {
V_550 = false ;
break;
}
}
V_548 = F_18 ( V_4 ) -> V_95 ;
}
if ( V_550 ||
( F_18 ( V_4 ) -> V_193 & ( V_368 | V_195 ) ) )
return;
while ( F_48 ( V_548 , V_518 ) ) {
int V_552 = F_45 ( int , F_313 ( 0 , 0 ) , V_518 - V_548 ) ;
struct V_3 * V_553 ;
V_553 = F_314 ( V_552 , V_169 ) ;
if ( ! V_553 )
return;
memcpy ( V_553 -> V_554 , V_4 -> V_554 , sizeof( V_4 -> V_554 ) ) ;
F_18 ( V_553 ) -> V_80 = F_18 ( V_553 ) -> V_95 = V_548 ;
F_315 ( V_545 , V_4 , V_553 ) ;
F_295 ( V_553 , V_2 ) ;
while ( V_552 > 0 ) {
int V_555 = V_548 - F_18 ( V_4 ) -> V_80 ;
int V_514 = F_18 ( V_4 ) -> V_95 - V_548 ;
F_89 ( V_555 < 0 ) ;
if ( V_514 > 0 ) {
V_514 = F_9 ( V_552 , V_514 ) ;
if ( F_316 ( V_4 , V_555 , F_300 ( V_553 , V_514 ) , V_514 ) )
F_317 () ;
F_18 ( V_553 ) -> V_95 += V_514 ;
V_552 -= V_514 ;
V_548 += V_514 ;
}
if ( ! F_48 ( V_548 , F_18 ( V_4 ) -> V_95 ) ) {
V_4 = F_310 ( V_2 , V_4 , V_545 ) ;
if ( ! V_4 ||
V_4 == V_511 ||
( F_18 ( V_4 ) -> V_193 & ( V_368 | V_195 ) ) )
return;
}
}
}
}
static void F_318 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_279 ( & V_33 -> V_489 ) ;
struct V_3 * V_547 ;
T_1 V_548 , V_518 ;
if ( ! V_4 )
return;
V_548 = F_18 ( V_4 ) -> V_80 ;
V_518 = F_18 ( V_4 ) -> V_95 ;
V_547 = V_4 ;
for (; ; ) {
struct V_3 * V_365 = NULL ;
if ( ! F_293 ( & V_33 -> V_489 , V_4 ) )
V_365 = F_294 ( & V_33 -> V_489 , V_4 ) ;
V_4 = V_365 ;
if ( ! V_4 ||
F_55 ( F_18 ( V_4 ) -> V_80 , V_518 ) ||
F_48 ( F_18 ( V_4 ) -> V_95 , V_548 ) ) {
F_311 ( V_2 , & V_33 -> V_489 ,
V_547 , V_4 , V_548 , V_518 ) ;
V_547 = V_4 ;
if ( ! V_4 )
break;
V_548 = F_18 ( V_4 ) -> V_80 ;
V_518 = F_18 ( V_4 ) -> V_95 ;
} else {
if ( F_48 ( F_18 ( V_4 ) -> V_80 , V_548 ) )
V_548 = F_18 ( V_4 ) -> V_80 ;
if ( F_55 ( F_18 ( V_4 ) -> V_95 , V_518 ) )
V_518 = F_18 ( V_4 ) -> V_95 ;
}
}
}
static bool F_287 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
bool V_556 = false ;
if ( ! F_270 ( & V_33 -> V_489 ) ) {
F_70 ( F_71 ( V_2 ) , V_557 ) ;
F_261 ( & V_33 -> V_489 ) ;
if ( V_33 -> V_52 . V_123 )
F_241 ( & V_33 -> V_52 ) ;
F_53 ( V_2 ) ;
V_556 = true ;
}
return V_556 ;
}
static int F_286 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
F_236 ( V_2 , L_20 , V_33 -> V_81 ) ;
F_70 ( F_71 ( V_2 ) , V_558 ) ;
if ( F_43 ( & V_2 -> V_84 ) >= V_2 -> V_72 )
F_40 ( V_2 ) ;
else if ( F_33 ( V_2 ) )
V_33 -> V_65 = F_9 ( V_33 -> V_65 , 4U * V_33 -> V_68 ) ;
F_318 ( V_2 ) ;
if ( ! F_270 ( & V_2 -> V_513 ) )
F_311 ( V_2 , & V_2 -> V_513 ,
F_279 ( & V_2 -> V_513 ) ,
NULL ,
V_33 -> V_81 , V_33 -> V_93 ) ;
F_53 ( V_2 ) ;
if ( F_43 ( & V_2 -> V_84 ) <= V_2 -> V_72 )
return 0 ;
F_287 ( V_2 ) ;
if ( F_43 ( & V_2 -> V_84 ) <= V_2 -> V_72 )
return 0 ;
F_70 ( F_71 ( V_2 ) , V_559 ) ;
V_33 -> V_386 = 0 ;
return - 1 ;
}
static bool F_319 ( const struct V_1 * V_2 )
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
static void F_320 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_319 ( V_2 ) ) {
F_25 ( V_2 ) ;
V_33 -> V_83 = V_79 ;
}
V_2 -> V_560 ( V_2 ) ;
}
static void F_321 ( struct V_1 * V_2 )
{
if ( F_254 ( V_2 , V_561 ) ) {
F_322 ( V_2 , V_561 ) ;
F_323 () ;
if ( V_2 -> V_562 &&
F_324 ( V_563 , & V_2 -> V_562 -> V_401 ) )
F_320 ( V_2 ) ;
}
}
static inline void F_325 ( struct V_1 * V_2 )
{
F_326 ( V_2 ) ;
F_321 ( V_2 ) ;
}
static void F_327 ( struct V_1 * V_2 , int V_564 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( ( ( V_33 -> V_93 - V_33 -> V_399 ) > F_2 ( V_2 ) -> V_8 . V_12 &&
F_328 ( V_2 ) >= V_33 -> V_23 ) ||
F_11 ( V_2 ) ||
( V_564 && F_279 ( & V_33 -> V_489 ) ) ) {
F_224 ( V_2 ) ;
} else {
F_329 ( V_2 ) ;
}
}
static inline void F_330 ( struct V_1 * V_2 )
{
if ( ! F_331 ( V_2 ) ) {
return;
}
F_327 ( V_2 , 1 ) ;
}
static void F_332 ( struct V_1 * V_2 , const struct V_15 * V_46 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_1 V_209 = F_154 ( V_46 -> V_565 ) ;
if ( V_209 && ! V_566 )
V_209 -- ;
V_209 += F_245 ( V_46 -> V_80 ) ;
if ( F_55 ( V_33 -> V_81 , V_209 ) )
return;
if ( F_48 ( V_209 , V_33 -> V_93 ) )
return;
if ( V_33 -> V_538 && ! F_55 ( V_209 , V_33 -> V_567 ) )
return;
F_333 ( V_2 ) ;
if ( V_33 -> V_567 == V_33 -> V_81 && V_33 -> V_538 &&
! F_254 ( V_2 , V_568 ) && V_33 -> V_81 != V_33 -> V_93 ) {
struct V_3 * V_4 = F_279 ( & V_2 -> V_513 ) ;
V_33 -> V_81 ++ ;
if ( V_4 && ! F_48 ( V_33 -> V_81 , F_18 ( V_4 ) -> V_95 ) ) {
F_280 ( V_4 , & V_2 -> V_513 ) ;
F_277 ( V_4 ) ;
}
}
V_33 -> V_538 = V_569 ;
V_33 -> V_567 = V_209 ;
V_33 -> V_386 = 0 ;
}
static void F_334 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_15 * V_46 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_46 -> V_570 )
F_332 ( V_2 , V_46 ) ;
if ( V_33 -> V_538 == V_569 ) {
T_1 V_209 = V_33 -> V_567 - F_245 ( V_46 -> V_80 ) + ( V_46 -> V_435 * 4 ) -
V_46 -> V_48 ;
if ( V_209 < V_4 -> V_10 ) {
T_4 V_205 ;
if ( F_316 ( V_4 , V_209 , & V_205 , 1 ) )
F_317 () ;
V_33 -> V_538 = V_571 | V_205 ;
if ( ! F_254 ( V_2 , V_477 ) )
V_2 -> V_543 ( V_2 ) ;
}
}
}
static int F_335 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_572 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_539 = V_4 -> V_10 - V_572 ;
int V_164 ;
if ( F_336 ( V_4 ) )
V_164 = F_307 ( V_4 , V_572 , V_33 -> V_535 . V_271 , V_539 ) ;
else
V_164 = F_337 ( V_4 , V_572 , V_33 -> V_535 . V_271 ) ;
if ( ! V_164 ) {
V_33 -> V_535 . V_10 -= V_539 ;
V_33 -> V_81 += V_539 ;
F_50 ( V_2 ) ;
}
return V_164 ;
}
static bool F_338 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_46 , int V_573 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
bool V_574 = false ;
if ( F_246 ( V_4 , V_46 , V_33 ) && V_33 -> V_52 . V_269 &&
F_249 ( V_2 , V_4 ) ) {
if ( ! V_46 -> V_575 ) {
F_70 ( F_71 ( V_2 ) , V_576 ) ;
if ( ! F_219 ( F_71 ( V_2 ) , V_4 ,
V_577 ,
& V_33 -> V_387 ) )
F_266 ( V_2 , V_4 ) ;
goto V_578;
}
}
if ( ! F_250 ( V_33 , F_18 ( V_4 ) -> V_80 , F_18 ( V_4 ) -> V_95 ) ) {
if ( ! V_46 -> V_575 ) {
if ( V_46 -> V_48 )
goto V_579;
if ( ! F_219 ( F_71 ( V_2 ) , V_4 ,
V_580 ,
& V_33 -> V_387 ) )
F_266 ( V_2 , V_4 ) ;
}
goto V_578;
}
if ( V_46 -> V_575 ) {
if ( F_18 ( V_4 ) -> V_80 == V_33 -> V_93 ) {
V_574 = true ;
} else if ( F_144 ( V_33 ) && V_33 -> V_52 . V_154 > 0 ) {
struct V_202 * V_153 = & V_33 -> V_502 [ 0 ] ;
int V_581 = V_153 [ 0 ] . V_95 ;
int V_501 ;
for ( V_501 = 1 ; V_501 < V_33 -> V_52 . V_154 ;
++ V_501 ) {
V_581 = F_55 ( V_153 [ V_501 ] . V_95 ,
V_581 ) ?
V_153 [ V_501 ] . V_95 : V_581 ;
}
if ( F_18 ( V_4 ) -> V_80 == V_581 )
V_574 = true ;
}
if ( V_574 )
F_252 ( V_2 ) ;
else
F_220 ( V_2 , V_4 ) ;
goto V_578;
}
if ( V_46 -> V_48 ) {
V_579:
if ( V_573 )
F_339 ( F_71 ( V_2 ) , V_582 ) ;
F_70 ( F_71 ( V_2 ) , V_583 ) ;
F_220 ( V_2 , V_4 ) ;
goto V_578;
}
return true ;
V_578:
F_275 ( V_2 , V_4 ) ;
return false ;
}
void F_340 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_46 , unsigned int V_10 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_102 ( ! V_2 -> V_584 ) )
F_2 ( V_2 ) -> V_585 -> V_586 ( V_2 , V_4 ) ;
V_33 -> V_52 . V_269 = 0 ;
if ( ( F_5 ( V_46 ) & V_587 ) == V_33 -> V_386 &&
F_18 ( V_4 ) -> V_80 == V_33 -> V_93 &&
! F_55 ( F_18 ( V_4 ) -> V_159 , V_33 -> V_110 ) ) {
int V_18 = V_33 -> V_18 ;
if ( V_18 == sizeof( struct V_15 ) + V_466 ) {
if ( ! F_243 ( V_33 , V_46 ) )
goto V_588;
if ( ( T_5 ) ( V_33 -> V_52 . V_397 - V_33 -> V_52 . V_396 ) < 0 )
goto V_588;
}
if ( V_10 <= V_18 ) {
if ( V_10 == V_18 ) {
if ( V_18 ==
( sizeof( struct V_15 ) + V_466 ) &&
V_33 -> V_93 == V_33 -> V_399 )
F_225 ( V_33 ) ;
F_233 ( V_2 , V_4 , 0 ) ;
F_277 ( V_4 ) ;
F_325 ( V_2 ) ;
return;
} else {
F_339 ( F_71 ( V_2 ) , V_582 ) ;
goto V_578;
}
} else {
int V_512 = 0 ;
bool V_508 = false ;
if ( V_33 -> V_535 . V_536 == V_537 &&
V_33 -> V_81 == V_33 -> V_93 &&
V_10 - V_18 <= V_33 -> V_535 . V_10 &&
F_305 ( V_2 ) ) {
F_306 ( V_540 ) ;
if ( ! F_335 ( V_2 , V_4 , V_18 ) ) {
if ( V_18 ==
( sizeof( struct V_15 ) +
V_466 ) &&
V_33 -> V_93 == V_33 -> V_399 )
F_225 ( V_33 ) ;
F_49 ( V_2 , V_4 ) ;
F_297 ( V_4 , V_18 ) ;
F_213 ( V_33 , F_18 ( V_4 ) -> V_95 ) ;
F_70 ( F_71 ( V_2 ) ,
V_589 ) ;
V_512 = 1 ;
}
}
if ( ! V_512 ) {
if ( F_341 ( V_4 ) )
goto V_590;
if ( ( int ) V_4 -> V_62 > V_2 -> V_591 )
goto V_592;
if ( V_18 ==
( sizeof( struct V_15 ) + V_466 ) &&
V_33 -> V_93 == V_33 -> V_399 )
F_225 ( V_33 ) ;
F_49 ( V_2 , V_4 ) ;
F_70 ( F_71 ( V_2 ) , V_593 ) ;
V_512 = F_296 ( V_2 , V_4 , V_18 ,
& V_508 ) ;
}
F_51 ( V_2 , V_4 ) ;
if ( F_18 ( V_4 ) -> V_159 != V_33 -> V_108 ) {
F_233 ( V_2 , V_4 , V_417 ) ;
F_325 ( V_2 ) ;
if ( ! F_331 ( V_2 ) )
goto V_594;
}
F_327 ( V_2 , 0 ) ;
V_594:
if ( V_512 )
F_283 ( V_4 , V_508 ) ;
V_2 -> V_543 ( V_2 ) ;
return;
}
}
V_588:
if ( V_10 < ( V_46 -> V_435 << 2 ) || F_341 ( V_4 ) )
goto V_590;
if ( ! V_46 -> V_342 && ! V_46 -> V_575 && ! V_46 -> V_48 )
goto V_578;
if ( ! F_338 ( V_2 , V_4 , V_46 , 1 ) )
return;
V_592:
if ( F_233 ( V_2 , V_4 , V_412 | V_411 ) < 0 )
goto V_578;
F_49 ( V_2 , V_4 ) ;
F_334 ( V_2 , V_4 , V_46 ) ;
F_303 ( V_2 , V_4 ) ;
F_325 ( V_2 ) ;
F_330 ( V_2 ) ;
return;
V_590:
F_339 ( F_71 ( V_2 ) , V_595 ) ;
F_339 ( F_71 ( V_2 ) , V_582 ) ;
V_578:
F_275 ( V_2 , V_4 ) ;
}
void F_342 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_258 ( V_2 , V_483 ) ;
if ( V_4 ) {
V_6 -> V_585 -> V_586 ( V_2 , V_4 ) ;
F_343 ( V_2 , V_4 ) ;
}
V_6 -> V_585 -> V_596 ( V_2 ) ;
F_344 ( V_2 ) ;
F_345 ( V_2 ) ;
V_33 -> V_597 = V_79 ;
F_37 ( V_2 ) ;
if ( F_254 ( V_2 , V_598 ) )
F_346 ( V_2 , F_347 ( V_33 ) ) ;
if ( ! V_33 -> V_52 . V_384 )
F_348 ( V_33 , V_33 -> V_380 ) ;
else
V_33 -> V_386 = 0 ;
if ( ! F_254 ( V_2 , V_477 ) ) {
V_2 -> V_490 ( V_2 ) ;
F_262 ( V_2 , V_599 , V_600 ) ;
}
}
static bool F_349 ( struct V_1 * V_2 , struct V_3 * V_601 ,
struct V_425 * V_424 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_13 = V_33 -> V_602 ? F_103 ( V_2 ) : NULL ;
T_6 V_69 = V_33 -> V_52 . V_53 , V_603 = 0 ;
bool V_604 = false ;
if ( V_69 == V_33 -> V_52 . V_443 ) {
struct V_431 V_605 ;
F_350 ( & V_605 ) ;
V_605 . V_443 = V_605 . V_53 = 0 ;
F_238 ( V_601 , & V_605 , 0 , NULL ) ;
V_69 = V_605 . V_53 ;
}
if ( ! V_33 -> V_606 ) {
V_424 -> V_10 = - 1 ;
} else if ( V_33 -> V_607 ) {
V_604 = ( V_424 -> V_10 < 0 && V_13 ) ;
} else if ( V_424 -> V_10 < 0 && ! V_33 -> V_602 ) {
V_603 = V_33 -> V_608 ? 2 : 1 ;
}
F_351 ( V_2 , V_69 , V_424 , V_604 , V_603 ) ;
if ( V_13 ) {
F_110 (data, sk) {
if ( V_13 == F_108 ( V_2 ) ||
F_352 ( V_2 , V_13 , 1 ) )
break;
}
F_193 ( V_2 ) ;
F_70 ( F_71 ( V_2 ) ,
V_609 ) ;
return true ;
}
V_33 -> V_610 = V_33 -> V_602 ;
if ( V_33 -> V_610 )
F_70 ( F_71 ( V_2 ) ,
V_611 ) ;
F_353 ( V_2 , V_601 ) ;
return false ;
}
static int F_354 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_46 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_425 V_426 = { . V_10 = - 1 } ;
int V_612 = V_33 -> V_52 . V_53 ;
F_238 ( V_4 , & V_33 -> V_52 , 0 , & V_426 ) ;
if ( V_33 -> V_52 . V_269 && V_33 -> V_52 . V_94 )
V_33 -> V_52 . V_94 -= V_33 -> V_465 ;
if ( V_46 -> V_342 ) {
if ( ! F_55 ( F_18 ( V_4 ) -> V_159 , V_33 -> V_108 ) ||
F_55 ( F_18 ( V_4 ) -> V_159 , V_33 -> V_110 ) )
goto V_613;
if ( V_33 -> V_52 . V_269 && V_33 -> V_52 . V_94 &&
! F_202 ( V_33 -> V_52 . V_94 , V_33 -> V_270 ,
V_79 ) ) {
F_70 ( F_71 ( V_2 ) ,
V_614 ) ;
goto V_613;
}
if ( V_46 -> V_575 ) {
F_252 ( V_2 ) ;
goto V_578;
}
if ( ! V_46 -> V_48 )
goto V_615;
F_22 ( V_33 , V_46 ) ;
F_355 ( V_33 , F_18 ( V_4 ) -> V_80 ) ;
F_233 ( V_2 , V_4 , V_412 ) ;
V_33 -> V_93 = F_18 ( V_4 ) -> V_80 + 1 ;
V_33 -> V_399 = F_18 ( V_4 ) -> V_80 + 1 ;
V_33 -> V_380 = F_154 ( V_46 -> V_63 ) ;
if ( ! V_33 -> V_52 . V_447 ) {
V_33 -> V_52 . V_384 = V_33 -> V_52 . V_616 = 0 ;
V_33 -> V_66 = F_9 ( V_33 -> V_66 , 65535U ) ;
}
if ( V_33 -> V_52 . V_269 ) {
V_33 -> V_52 . V_451 = 1 ;
V_33 -> V_18 =
sizeof( struct V_15 ) + V_466 ;
V_33 -> V_68 -= V_466 ;
F_225 ( V_33 ) ;
} else {
V_33 -> V_18 = sizeof( struct V_15 ) ;
}
if ( F_144 ( V_33 ) && V_617 )
F_356 ( V_33 ) ;
F_357 ( V_2 ) ;
F_173 ( V_2 , V_6 -> V_305 ) ;
F_44 ( V_2 ) ;
V_33 -> V_81 = V_33 -> V_93 ;
F_358 () ;
F_342 ( V_2 , V_4 ) ;
if ( ( V_33 -> V_606 || V_33 -> V_602 ) &&
F_349 ( V_2 , V_4 , & V_426 ) )
return - 1 ;
if ( V_2 -> V_618 ||
V_6 -> V_619 . V_620 ||
V_6 -> V_8 . V_26 ) {
F_52 ( V_2 ) ;
V_6 -> V_8 . V_100 = V_79 ;
F_10 ( V_2 ) ;
F_136 ( V_2 , V_621 ,
V_622 , V_250 ) ;
V_578:
F_275 ( V_2 , V_4 ) ;
return 0 ;
} else {
F_224 ( V_2 ) ;
}
return - 1 ;
}
if ( V_46 -> V_575 ) {
goto V_615;
}
if ( V_33 -> V_52 . V_398 && V_33 -> V_52 . V_269 &&
F_359 ( & V_33 -> V_52 , 0 ) )
goto V_615;
if ( V_46 -> V_48 ) {
F_258 ( V_2 , V_482 ) ;
if ( V_33 -> V_52 . V_269 ) {
V_33 -> V_52 . V_451 = 1 ;
F_225 ( V_33 ) ;
V_33 -> V_18 =
sizeof( struct V_15 ) + V_466 ;
} else {
V_33 -> V_18 = sizeof( struct V_15 ) ;
}
V_33 -> V_93 = F_18 ( V_4 ) -> V_80 + 1 ;
V_33 -> V_81 = V_33 -> V_93 ;
V_33 -> V_399 = F_18 ( V_4 ) -> V_80 + 1 ;
V_33 -> V_380 = F_154 ( V_46 -> V_63 ) ;
V_33 -> V_379 = F_18 ( V_4 ) -> V_80 ;
V_33 -> V_150 = V_33 -> V_380 ;
F_23 ( V_33 , V_46 ) ;
F_357 ( V_2 ) ;
F_173 ( V_2 , V_6 -> V_305 ) ;
F_44 ( V_2 ) ;
F_360 ( V_2 ) ;
#if 0
return -1;
#else
goto V_578;
#endif
}
V_615:
F_350 ( & V_33 -> V_52 ) ;
V_33 -> V_52 . V_53 = V_612 ;
goto V_578;
V_613:
F_350 ( & V_33 -> V_52 ) ;
V_33 -> V_52 . V_53 = V_612 ;
return 1 ;
}
int F_361 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_15 * V_46 = F_6 ( V_4 ) ;
struct V_337 * V_338 ;
int V_623 = 0 ;
bool V_624 ;
switch ( V_2 -> V_469 ) {
case V_475 :
goto V_578;
case V_625 :
if ( V_46 -> V_342 )
return 1 ;
if ( V_46 -> V_575 )
goto V_578;
if ( V_46 -> V_48 ) {
if ( V_46 -> V_626 )
goto V_578;
if ( V_6 -> V_585 -> V_627 ( V_2 , V_4 ) < 0 )
return 1 ;
F_362 ( V_4 ) ;
return 0 ;
}
goto V_578;
case V_470 :
V_33 -> V_52 . V_269 = 0 ;
V_623 = F_354 ( V_2 , V_4 , V_46 ) ;
if ( V_623 >= 0 )
return V_623 ;
F_334 ( V_2 , V_4 , V_46 ) ;
F_277 ( V_4 ) ;
F_325 ( V_2 ) ;
return 0 ;
}
V_33 -> V_52 . V_269 = 0 ;
V_338 = V_33 -> V_344 ;
if ( V_338 ) {
F_164 ( V_2 -> V_469 != V_482 &&
V_2 -> V_469 != V_486 ) ;
if ( ! F_363 ( V_2 , V_4 , V_338 , true ) )
goto V_578;
}
if ( ! V_46 -> V_342 && ! V_46 -> V_575 && ! V_46 -> V_48 )
goto V_578;
if ( ! F_338 ( V_2 , V_4 , V_46 , 0 ) )
return 0 ;
V_624 = F_233 ( V_2 , V_4 , V_412 |
V_411 ) > 0 ;
switch ( V_2 -> V_469 ) {
case V_482 :
if ( ! V_624 )
return 1 ;
if ( ! V_33 -> V_104 )
F_188 ( V_2 , V_338 ) ;
if ( V_338 ) {
F_2 ( V_2 ) -> V_234 = 0 ;
F_364 ( V_2 , V_338 , false ) ;
} else {
V_6 -> V_585 -> V_596 ( V_2 ) ;
F_345 ( V_2 ) ;
F_357 ( V_2 ) ;
V_33 -> V_81 = V_33 -> V_93 ;
F_37 ( V_2 ) ;
}
F_358 () ;
F_258 ( V_2 , V_483 ) ;
V_2 -> V_490 ( V_2 ) ;
if ( V_2 -> V_562 )
F_262 ( V_2 , V_599 , V_600 ) ;
V_33 -> V_108 = F_18 ( V_4 ) -> V_159 ;
V_33 -> V_380 = F_154 ( V_46 -> V_63 ) << V_33 -> V_52 . V_384 ;
F_355 ( V_33 , F_18 ( V_4 ) -> V_80 ) ;
if ( V_33 -> V_52 . V_451 )
V_33 -> V_68 -= V_466 ;
if ( V_338 ) {
F_193 ( V_2 ) ;
} else
F_344 ( V_2 ) ;
F_57 ( V_2 ) ;
V_33 -> V_597 = V_79 ;
F_44 ( V_2 ) ;
F_365 ( V_33 ) ;
break;
case V_486 : {
struct V_29 * V_30 ;
int V_628 ;
if ( V_338 ) {
if ( ! V_624 )
return 1 ;
F_364 ( V_2 , V_338 , false ) ;
F_193 ( V_2 ) ;
}
if ( V_33 -> V_108 != V_33 -> V_629 )
break;
F_258 ( V_2 , V_487 ) ;
V_2 -> V_479 |= V_630 ;
V_30 = F_12 ( V_2 ) ;
if ( V_30 )
F_234 ( V_30 ) ;
if ( ! F_254 ( V_2 , V_477 ) ) {
V_2 -> V_490 ( V_2 ) ;
break;
}
if ( V_33 -> V_631 < 0 ||
( F_18 ( V_4 ) -> V_95 != F_18 ( V_4 ) -> V_80 &&
F_55 ( F_18 ( V_4 ) -> V_95 - V_46 -> V_626 , V_33 -> V_93 ) ) ) {
F_255 ( V_2 ) ;
F_70 ( F_71 ( V_2 ) , V_632 ) ;
return 1 ;
}
V_628 = F_366 ( V_2 ) ;
if ( V_628 > V_633 ) {
F_346 ( V_2 , V_628 - V_633 ) ;
} else if ( V_46 -> V_626 || F_305 ( V_2 ) ) {
F_346 ( V_2 , V_628 ) ;
} else {
F_259 ( V_2 , V_487 , V_628 ) ;
goto V_578;
}
break;
}
case V_484 :
if ( V_33 -> V_108 == V_33 -> V_629 ) {
F_259 ( V_2 , V_488 , 0 ) ;
goto V_578;
}
break;
case V_485 :
if ( V_33 -> V_108 == V_33 -> V_629 ) {
F_367 ( V_2 ) ;
F_255 ( V_2 ) ;
goto V_578;
}
break;
}
F_334 ( V_2 , V_4 , V_46 ) ;
switch ( V_2 -> V_469 ) {
case V_473 :
case V_484 :
case V_485 :
if ( ! F_48 ( F_18 ( V_4 ) -> V_80 , V_33 -> V_93 ) )
break;
case V_486 :
case V_487 :
if ( V_2 -> V_479 & V_480 ) {
if ( F_18 ( V_4 ) -> V_95 != F_18 ( V_4 ) -> V_80 &&
F_55 ( F_18 ( V_4 ) -> V_95 - V_46 -> V_626 , V_33 -> V_93 ) ) {
F_70 ( F_71 ( V_2 ) , V_632 ) ;
F_252 ( V_2 ) ;
return 1 ;
}
}
case V_483 :
F_303 ( V_2 , V_4 ) ;
V_623 = 1 ;
break;
}
if ( V_2 -> V_469 != V_475 ) {
F_325 ( V_2 ) ;
F_330 ( V_2 ) ;
}
if ( ! V_623 ) {
V_578:
F_275 ( V_2 , V_4 ) ;
}
return 0 ;
}
static inline void F_368 ( struct V_337 * V_338 , T_11 V_634 , int V_635 )
{
struct V_636 * V_637 = F_369 ( V_338 ) ;
if ( V_635 == V_275 )
F_370 ( L_21 ,
& V_637 -> V_638 , V_634 ) ;
#if F_156 ( V_278 )
else if ( V_635 == V_279 )
F_370 ( L_22 ,
& V_637 -> V_639 , V_634 ) ;
#endif
}
static void F_371 ( struct V_337 * V_338 ,
const struct V_3 * V_4 ,
const struct V_1 * V_640 ,
const struct V_29 * V_30 )
{
const struct V_15 * V_46 = F_6 ( V_4 ) ;
const struct V_229 * V_229 = F_71 ( V_640 ) ;
bool V_641 = V_46 -> V_47 && V_46 -> V_37 ;
bool V_642 , V_643 ;
T_1 V_644 ;
if ( ! V_641 )
return;
V_642 = ! F_372 ( F_18 ( V_4 ) -> V_39 ) ;
V_644 = F_373 ( V_30 , V_645 ) ;
V_643 = V_229 -> V_241 . V_646 || V_644 ;
if ( ( ! V_642 && V_643 ) || F_19 ( V_640 ) ||
( V_644 & V_647 ) )
F_369 ( V_338 ) -> V_643 = 1 ;
}
static void F_374 ( struct V_337 * V_338 ,
const struct V_431 * V_52 ,
struct V_3 * V_4 , const struct V_1 * V_2 )
{
struct V_636 * V_637 = F_369 ( V_338 ) ;
V_338 -> V_648 = 0 ;
V_338 -> V_649 = 0 ;
F_189 ( V_338 ) -> V_650 = F_18 ( V_4 ) -> V_80 ;
F_189 ( V_338 ) -> V_93 = F_18 ( V_4 ) -> V_80 + 1 ;
F_190 ( & F_189 ( V_338 ) -> V_340 ) ;
F_189 ( V_338 ) -> V_387 = 0 ;
V_338 -> V_69 = V_52 -> V_53 ;
V_338 -> V_396 = V_52 -> V_269 ? V_52 -> V_397 : 0 ;
V_637 -> V_451 = V_52 -> V_451 ;
V_637 -> V_123 = V_52 -> V_123 ;
V_637 -> V_384 = V_52 -> V_384 ;
V_637 -> V_447 = V_52 -> V_447 ;
V_637 -> V_228 = 0 ;
V_637 -> V_643 = 0 ;
V_637 -> V_651 = F_6 ( V_4 ) -> V_652 ;
V_637 -> V_653 = F_154 ( F_6 ( V_4 ) -> V_654 ) ;
V_637 -> V_655 = F_375 ( V_2 , V_4 ) ;
}
struct V_337 * F_376 ( const struct V_656 * V_657 ,
struct V_1 * V_658 ,
bool V_659 )
{
struct V_337 * V_338 = F_377 ( V_657 , V_658 ,
V_659 ) ;
if ( V_338 ) {
struct V_636 * V_637 = F_369 ( V_338 ) ;
F_378 ( V_637 , V_401 ) ;
V_637 -> V_605 = NULL ;
#if F_156 ( V_278 )
V_637 -> V_660 = NULL ;
#endif
F_379 ( & V_637 -> V_661 , 0 ) ;
V_637 -> V_662 = V_663 ;
F_380 ( & V_637 -> V_664 , F_71 ( V_658 ) ) ;
V_637 -> V_665 = V_658 -> V_274 ;
}
return V_338 ;
}
static bool F_381 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const char * V_666 )
{
struct V_667 * V_668 = & F_2 ( V_2 ) -> V_619 ;
const char * V_271 = L_23 ;
bool V_669 = false ;
struct V_229 * V_229 = F_71 ( V_2 ) ;
#ifdef F_382
if ( V_229 -> V_241 . V_670 ) {
V_271 = L_24 ;
V_669 = true ;
F_383 ( F_71 ( V_2 ) , V_671 ) ;
} else
#endif
F_383 ( F_71 ( V_2 ) , V_672 ) ;
if ( ! V_668 -> V_673 &&
V_229 -> V_241 . V_670 != 2 &&
F_384 ( & V_668 -> V_673 , 1 ) == 0 )
F_385 ( L_25 ,
V_666 , F_154 ( F_6 ( V_4 ) -> V_654 ) , V_271 ) ;
return V_669 ;
}
static void F_386 ( const struct V_1 * V_2 ,
struct V_337 * V_338 ,
const struct V_3 * V_4 )
{
if ( F_7 ( V_2 ) -> V_674 ) {
T_1 V_10 = F_387 ( V_4 ) + F_388 ( V_4 ) ;
T_1 * V_552 ;
V_552 = F_389 ( V_10 + sizeof( T_1 ) , V_169 ) ;
if ( V_552 ) {
V_552 [ 0 ] = V_10 ;
memcpy ( & V_552 [ 1 ] , F_390 ( V_4 ) , V_10 ) ;
V_338 -> V_675 = V_552 ;
}
}
}
int F_391 ( struct V_656 * V_676 ,
const struct V_677 * V_678 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_425 V_426 = { . V_10 = - 1 } ;
T_3 V_679 = F_18 ( V_4 ) -> V_680 ;
struct V_431 V_681 ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_229 * V_229 = F_71 ( V_2 ) ;
struct V_1 * V_682 = NULL ;
struct V_29 * V_30 = NULL ;
struct V_337 * V_338 ;
bool V_669 = false ;
struct V_683 V_684 ;
if ( ( V_229 -> V_241 . V_670 == 2 ||
F_392 ( V_2 ) ) && ! V_679 ) {
V_669 = F_381 ( V_2 , V_4 , V_676 -> V_685 ) ;
if ( ! V_669 )
goto V_542;
}
if ( F_393 ( V_2 ) && F_394 ( V_2 ) > 1 ) {
F_70 ( F_71 ( V_2 ) , V_686 ) ;
goto V_542;
}
V_338 = F_376 ( V_676 , V_2 , ! V_669 ) ;
if ( ! V_338 )
goto V_542;
F_189 ( V_338 ) -> V_687 = V_678 ;
F_350 ( & V_681 ) ;
V_681 . V_53 = V_678 -> V_53 ;
V_681 . V_443 = V_33 -> V_52 . V_443 ;
F_238 ( V_4 , & V_681 , 0 , V_669 ? NULL : & V_426 ) ;
if ( V_669 && ! V_681 . V_269 )
F_350 ( & V_681 ) ;
V_681 . V_451 = V_681 . V_269 ;
F_374 ( V_338 , & V_681 , V_4 , V_2 ) ;
F_369 ( V_338 ) -> V_688 = F_395 ( V_2 , V_4 ) ;
V_678 -> V_689 ( V_338 , V_2 , V_4 ) ;
if ( F_396 ( V_2 , V_4 , V_338 ) )
goto V_690;
if ( ! V_669 && ! V_679 ) {
if ( V_691 . V_692 ) {
bool V_693 ;
V_30 = V_678 -> V_694 ( V_2 , & V_684 , V_338 , & V_693 ) ;
if ( V_30 && V_693 &&
! F_397 ( V_338 , V_30 , true ,
V_681 . V_269 ) ) {
F_70 ( F_71 ( V_2 ) , V_695 ) ;
goto V_696;
}
}
else if ( ! V_229 -> V_241 . V_670 &&
( V_697 - F_398 ( V_2 ) <
( V_697 >> 2 ) ) &&
! F_397 ( V_338 , V_30 , false ,
V_681 . V_269 ) ) {
F_368 ( V_338 , F_154 ( F_6 ( V_4 ) -> V_652 ) ,
V_676 -> V_635 ) ;
goto V_696;
}
V_679 = V_678 -> V_698 ( V_4 ) ;
}
if ( ! V_30 ) {
V_30 = V_678 -> V_694 ( V_2 , & V_684 , V_338 , NULL ) ;
if ( ! V_30 )
goto V_690;
}
F_371 ( V_338 , V_4 , V_2 , V_30 ) ;
if ( V_669 ) {
V_679 = F_399 ( V_678 , V_2 , V_4 , & V_338 -> V_69 ) ;
V_338 -> V_649 = V_681 . V_451 ;
if ( ! V_681 . V_451 )
F_369 ( V_338 ) -> V_643 = 0 ;
}
F_189 ( V_338 ) -> V_699 = V_679 ;
F_189 ( V_338 ) -> V_700 = F_400 () ;
F_401 ( V_338 , V_2 , V_30 ) ;
if ( ! V_669 ) {
F_386 ( V_2 , V_338 , V_4 ) ;
V_682 = F_402 ( V_2 , V_4 , V_338 , & V_426 , V_30 ) ;
}
if ( V_682 ) {
V_678 -> V_701 ( V_682 , V_30 , & V_684 , V_338 ,
& V_426 , V_702 ) ;
F_403 ( V_2 , V_338 , V_682 ) ;
V_2 -> V_543 ( V_2 ) ;
F_404 ( V_682 ) ;
F_405 ( V_682 ) ;
} else {
F_189 ( V_338 ) -> V_703 = false ;
if ( ! V_669 )
F_406 ( V_2 , V_338 , V_704 ) ;
V_678 -> V_701 ( V_2 , V_30 , & V_684 , V_338 , & V_426 ,
! V_669 ? V_705 :
V_706 ) ;
if ( V_669 ) {
F_407 ( V_338 ) ;
return 0 ;
}
}
F_408 ( V_338 ) ;
return 0 ;
V_696:
F_409 ( V_30 ) ;
V_690:
F_407 ( V_338 ) ;
V_542:
F_410 ( V_2 ) ;
return 0 ;
}
