static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_2 V_4 = F_2 ( V_3 ) ;
if ( V_4 == 0 )
return;
F_3 ( 1 , L_1 ,
F_4 ( V_3 ) , V_4 ) ;
F_5 ( V_3 , 0xffffffff ) ;
F_6 ( V_3 ) ;
F_5 ( V_3 , 0xffffffff ) ;
F_6 ( V_3 ) ;
}
static inline void
F_7 ( struct V_1 * V_2 ,
T_3 V_5 ,
T_3 V_6 )
{
T_3 V_4 ;
F_8 ( & V_2 -> V_7 ) ;
F_9 ( V_6 & ~ V_5 ) ;
V_4 = F_2 ( V_8 ) ;
V_4 &= ~ V_5 ;
V_4 |= V_6 ;
F_5 ( V_8 , V_4 ) ;
}
void F_10 ( struct V_1 * V_2 ,
T_3 V_5 ,
T_3 V_6 )
{
F_11 ( & V_2 -> V_7 ) ;
F_7 ( V_2 , V_5 , V_6 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
void F_13 ( struct V_1 * V_2 ,
T_3 V_9 ,
T_3 V_10 )
{
T_3 V_11 ;
F_8 ( & V_2 -> V_7 ) ;
F_9 ( V_10 & ~ V_9 ) ;
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
V_11 = V_2 -> V_12 ;
V_11 &= ~ V_9 ;
V_11 |= ( ~ V_10 & V_9 ) ;
if ( V_11 != V_2 -> V_12 ) {
V_2 -> V_12 = V_11 ;
F_5 ( V_13 , V_2 -> V_12 ) ;
F_6 ( V_13 ) ;
}
}
static void F_15 ( struct V_1 * V_2 ,
T_3 V_9 ,
T_3 V_10 )
{
F_8 ( & V_2 -> V_7 ) ;
F_9 ( V_10 & ~ V_9 ) ;
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
V_2 -> V_14 &= ~ V_9 ;
V_2 -> V_14 |= ( ~ V_10 & V_9 ) ;
F_5 ( V_15 , V_2 -> V_14 ) ;
}
void F_16 ( struct V_1 * V_2 , T_3 V_5 )
{
F_15 ( V_2 , V_5 , V_5 ) ;
F_17 ( V_15 ) ;
}
void F_18 ( struct V_1 * V_2 , T_3 V_5 )
{
F_15 ( V_2 , V_5 , 0 ) ;
}
static T_1 F_19 ( struct V_1 * V_2 )
{
return F_20 ( V_2 ) -> V_16 >= 8 ? F_21 ( 2 ) : V_17 ;
}
static T_1 F_22 ( struct V_1 * V_2 )
{
return F_20 ( V_2 ) -> V_16 >= 8 ? F_23 ( 2 ) : V_18 ;
}
static T_1 F_24 ( struct V_1 * V_2 )
{
return F_20 ( V_2 ) -> V_16 >= 8 ? F_25 ( 2 ) : V_19 ;
}
static void F_26 ( struct V_1 * V_2 ,
T_3 V_9 ,
T_3 V_10 )
{
T_3 V_11 ;
F_9 ( V_10 & ~ V_9 ) ;
F_8 ( & V_2 -> V_7 ) ;
V_11 = V_2 -> V_20 ;
V_11 &= ~ V_9 ;
V_11 |= ( ~ V_10 & V_9 ) ;
if ( V_11 != V_2 -> V_20 ) {
V_2 -> V_20 = V_11 ;
F_5 ( F_22 ( V_2 ) , V_2 -> V_20 ) ;
F_6 ( F_22 ( V_2 ) ) ;
}
}
void F_27 ( struct V_1 * V_2 , T_2 V_5 )
{
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
F_26 ( V_2 , V_5 , V_5 ) ;
}
static void F_28 ( struct V_1 * V_2 , T_2 V_5 )
{
F_26 ( V_2 , V_5 , 0 ) ;
}
void F_29 ( struct V_1 * V_2 , T_2 V_5 )
{
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
F_28 ( V_2 , V_5 ) ;
}
void F_30 ( struct V_1 * V_2 , T_2 V_21 )
{
T_1 V_3 = F_19 ( V_2 ) ;
F_8 ( & V_2 -> V_7 ) ;
F_5 ( V_3 , V_21 ) ;
F_5 ( V_3 , V_21 ) ;
F_6 ( V_3 ) ;
}
void F_31 ( struct V_1 * V_2 , T_2 V_22 )
{
F_8 ( & V_2 -> V_7 ) ;
V_2 -> V_23 |= V_22 ;
F_5 ( F_24 ( V_2 ) , V_2 -> V_23 ) ;
F_27 ( V_2 , V_22 ) ;
}
void F_32 ( struct V_1 * V_2 , T_2 V_24 )
{
F_8 ( & V_2 -> V_7 ) ;
V_2 -> V_23 &= ~ V_24 ;
F_28 ( V_2 , V_24 ) ;
F_5 ( F_24 ( V_2 ) , V_2 -> V_23 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_7 ) ;
F_30 ( V_2 , V_2 -> V_25 ) ;
V_2 -> V_26 . V_27 = 0 ;
F_12 ( & V_2 -> V_7 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
if ( F_35 ( V_2 -> V_26 . V_28 ) )
return;
F_11 ( & V_2 -> V_7 ) ;
F_36 ( V_2 -> V_26 . V_27 ) ;
F_36 ( F_2 ( F_19 ( V_2 ) ) & V_2 -> V_25 ) ;
V_2 -> V_26 . V_28 = true ;
F_31 ( V_2 , V_2 -> V_25 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
T_2 F_37 ( struct V_1 * V_2 , T_2 V_5 )
{
return ( V_5 & ~ V_2 -> V_26 . V_29 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
if ( ! F_35 ( V_2 -> V_26 . V_28 ) )
return;
F_11 ( & V_2 -> V_7 ) ;
V_2 -> V_26 . V_28 = false ;
F_5 ( V_30 , F_37 ( V_2 , ~ 0u ) ) ;
F_32 ( V_2 , V_2 -> V_25 ) ;
F_12 ( & V_2 -> V_7 ) ;
F_39 ( V_2 -> V_31 . V_32 ) ;
F_40 ( & V_2 -> V_26 . V_33 ) ;
F_33 ( V_2 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_7 ) ;
F_30 ( V_2 , V_2 -> V_34 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_7 ) ;
if ( ! V_2 -> V_35 . V_28 ) {
F_36 ( F_2 ( F_19 ( V_2 ) ) &
V_2 -> V_34 ) ;
V_2 -> V_35 . V_28 = true ;
F_31 ( V_2 , V_2 -> V_34 ) ;
}
F_12 ( & V_2 -> V_7 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_7 ) ;
V_2 -> V_35 . V_28 = false ;
F_32 ( V_2 , V_2 -> V_34 ) ;
F_12 ( & V_2 -> V_7 ) ;
F_39 ( V_2 -> V_31 . V_32 ) ;
F_41 ( V_2 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
T_3 V_9 ,
T_3 V_10 )
{
T_3 V_11 ;
T_3 V_36 ;
F_8 ( & V_2 -> V_7 ) ;
F_9 ( V_10 & ~ V_9 ) ;
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
V_36 = F_2 ( V_37 ) ;
V_11 = V_36 ;
V_11 &= ~ V_9 ;
V_11 |= ( ~ V_10 & V_9 ) ;
if ( V_11 != V_36 ) {
F_5 ( V_37 , V_11 ) ;
F_6 ( V_37 ) ;
}
}
void F_45 ( struct V_1 * V_2 ,
enum V_38 V_38 ,
T_3 V_9 ,
T_3 V_10 )
{
T_3 V_11 ;
F_8 ( & V_2 -> V_7 ) ;
F_9 ( V_10 & ~ V_9 ) ;
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
V_11 = V_2 -> V_39 [ V_38 ] ;
V_11 &= ~ V_9 ;
V_11 |= ( ~ V_10 & V_9 ) ;
if ( V_11 != V_2 -> V_39 [ V_38 ] ) {
V_2 -> V_39 [ V_38 ] = V_11 ;
F_5 ( F_46 ( V_38 ) , V_2 -> V_39 [ V_38 ] ) ;
F_6 ( F_46 ( V_38 ) ) ;
}
}
void F_47 ( struct V_1 * V_2 ,
T_3 V_9 ,
T_3 V_10 )
{
T_3 V_40 = F_2 ( V_41 ) ;
V_40 &= ~ V_9 ;
V_40 |= ( ~ V_10 & V_9 ) ;
F_9 ( V_10 & ~ V_9 ) ;
F_8 ( & V_2 -> V_7 ) ;
if ( F_9 ( ! F_14 ( V_2 ) ) )
return;
F_5 ( V_41 , V_40 ) ;
F_6 ( V_41 ) ;
}
static void
F_48 ( struct V_1 * V_2 , enum V_38 V_38 ,
T_2 V_22 , T_2 V_42 )
{
T_1 V_3 = F_49 ( V_38 ) ;
T_2 V_43 = F_2 ( V_3 ) & V_44 ;
F_8 ( & V_2 -> V_7 ) ;
F_9 ( ! F_14 ( V_2 ) ) ;
if ( F_50 ( V_22 & ~ V_44 ||
V_42 & ~ V_45 ,
L_2 ,
F_51 ( V_38 ) , V_22 , V_42 ) )
return;
if ( ( V_43 & V_22 ) == V_22 )
return;
V_2 -> V_46 [ V_38 ] |= V_42 ;
V_43 |= V_22 | V_42 ;
F_5 ( V_3 , V_43 ) ;
F_6 ( V_3 ) ;
}
static void
F_52 ( struct V_1 * V_2 , enum V_38 V_38 ,
T_2 V_22 , T_2 V_42 )
{
T_1 V_3 = F_49 ( V_38 ) ;
T_2 V_43 = F_2 ( V_3 ) & V_44 ;
F_8 ( & V_2 -> V_7 ) ;
F_9 ( ! F_14 ( V_2 ) ) ;
if ( F_50 ( V_22 & ~ V_44 ||
V_42 & ~ V_45 ,
L_2 ,
F_51 ( V_38 ) , V_22 , V_42 ) )
return;
if ( ( V_43 & V_22 ) == 0 )
return;
V_2 -> V_46 [ V_38 ] &= ~ V_42 ;
V_43 &= ~ V_22 ;
F_5 ( V_3 , V_43 ) ;
F_6 ( V_3 ) ;
}
static T_2 F_53 ( struct V_47 * V_48 , T_2 V_42 )
{
T_2 V_22 = V_42 << 16 ;
if ( F_36 ( V_42 & V_49 ) )
return 0 ;
if ( F_36 ( V_42 & V_50 ) )
return 0 ;
V_22 &= ~ ( V_51 |
V_52 |
V_53 ) ;
if ( V_42 & V_54 )
V_22 |= V_52 ;
if ( V_42 & V_55 )
V_22 |= V_53 ;
return V_22 ;
}
void
F_54 ( struct V_1 * V_2 , enum V_38 V_38 ,
T_2 V_42 )
{
T_2 V_22 ;
if ( F_55 ( V_2 ) || F_56 ( V_2 ) )
V_22 = F_53 ( & V_2 -> V_31 ,
V_42 ) ;
else
V_22 = V_42 << 16 ;
F_48 ( V_2 , V_38 , V_22 , V_42 ) ;
}
void
F_57 ( struct V_1 * V_2 , enum V_38 V_38 ,
T_2 V_42 )
{
T_2 V_22 ;
if ( F_55 ( V_2 ) || F_56 ( V_2 ) )
V_22 = F_53 ( & V_2 -> V_31 ,
V_42 ) ;
else
V_22 = V_42 << 16 ;
F_52 ( V_2 , V_38 , V_22 , V_42 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_56 . V_57 || ! F_59 ( V_2 ) )
return;
F_11 ( & V_2 -> V_7 ) ;
F_54 ( V_2 , V_58 , V_59 ) ;
if ( F_60 ( V_2 ) >= 4 )
F_54 ( V_2 , V_60 ,
V_59 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
static T_2 F_61 ( struct V_47 * V_48 , unsigned int V_38 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_1 V_61 , V_62 ;
T_2 V_63 , V_64 , V_65 , V_66 , V_67 , V_68 , V_69 ;
struct V_70 * V_70 = F_63 ( V_2 ,
V_38 ) ;
const struct V_71 * V_72 = & V_70 -> V_73 . V_74 ;
V_69 = V_72 -> V_75 ;
V_68 = V_72 -> V_76 ;
V_67 = V_72 -> V_77 ;
if ( V_72 -> V_78 & V_79 )
V_67 = F_64 ( V_67 , 2 ) ;
V_67 *= V_69 ;
V_67 -= V_69 - V_68 ;
V_61 = F_65 ( V_38 ) ;
V_62 = F_66 ( V_38 ) ;
do {
V_63 = F_2 ( V_61 ) & V_80 ;
V_65 = F_2 ( V_62 ) ;
V_64 = F_2 ( V_61 ) & V_80 ;
} while ( V_63 != V_64 );
V_63 >>= V_81 ;
V_66 = V_65 & V_82 ;
V_65 >>= V_83 ;
return ( ( ( V_63 << 8 ) | V_65 ) + ( V_66 >= V_67 ) ) & 0xffffff ;
}
static T_2 F_67 ( struct V_47 * V_48 , unsigned int V_38 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
return F_2 ( F_68 ( V_38 ) ) ;
}
static int F_69 ( struct V_70 * V_84 )
{
struct V_47 * V_48 = V_84 -> V_73 . V_48 ;
struct V_1 * V_2 = F_62 ( V_48 ) ;
const struct V_71 * V_72 = & V_84 -> V_73 . V_74 ;
enum V_38 V_38 = V_84 -> V_38 ;
int V_85 , V_86 ;
V_86 = V_72 -> V_87 ;
if ( V_72 -> V_78 & V_79 )
V_86 /= 2 ;
if ( F_70 ( V_2 ) )
V_85 = F_71 ( F_72 ( V_38 ) ) & V_88 ;
else
V_85 = F_71 ( F_72 ( V_38 ) ) & V_89 ;
if ( F_73 ( V_2 ) && ! V_85 ) {
int V_90 , V_91 ;
for ( V_90 = 0 ; V_90 < 100 ; V_90 ++ ) {
F_74 ( 1 ) ;
V_91 = F_75 ( V_2 , F_72 ( V_38 ) ) &
V_89 ;
if ( V_91 != V_85 ) {
V_85 = V_91 ;
break;
}
}
}
return ( V_85 + V_84 -> V_92 ) % V_86 ;
}
static int F_76 ( struct V_47 * V_48 , unsigned int V_38 ,
unsigned int V_78 , int * V_93 , int * V_94 ,
T_4 * V_95 , T_4 * V_96 ,
const struct V_71 * V_72 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
struct V_70 * V_70 = F_63 ( V_2 ,
V_38 ) ;
int V_85 ;
int V_67 , V_97 , V_68 , V_69 , V_86 ;
bool V_98 = true ;
int V_99 = 0 ;
unsigned long V_100 ;
if ( F_9 ( ! V_72 -> V_101 ) ) {
F_77 ( L_3
L_4 , F_51 ( V_38 ) ) ;
return 0 ;
}
V_69 = V_72 -> V_75 ;
V_68 = V_72 -> V_76 ;
V_86 = V_72 -> V_87 ;
V_67 = V_72 -> V_77 ;
V_97 = V_72 -> V_102 ;
if ( V_72 -> V_78 & V_79 ) {
V_67 = F_64 ( V_67 , 2 ) ;
V_97 /= 2 ;
V_86 /= 2 ;
}
V_99 |= V_103 | V_104 ;
F_78 ( & V_2 -> V_105 . V_106 , V_100 ) ;
if ( V_95 )
* V_95 = F_79 () ;
if ( F_70 ( V_2 ) || F_80 ( V_2 ) || F_60 ( V_2 ) >= 5 ) {
V_85 = F_69 ( V_70 ) ;
} else {
V_85 = ( F_71 ( F_66 ( V_38 ) ) & V_82 ) >> V_107 ;
V_67 *= V_69 ;
V_97 *= V_69 ;
V_86 *= V_69 ;
if ( V_85 >= V_86 )
V_85 = V_86 - 1 ;
V_85 = ( V_85 + V_69 - V_68 ) % V_86 ;
}
if ( V_96 )
* V_96 = F_79 () ;
F_81 ( & V_2 -> V_105 . V_106 , V_100 ) ;
V_98 = V_85 >= V_67 && V_85 < V_97 ;
if ( V_85 >= V_67 )
V_85 -= V_97 ;
else
V_85 += V_86 - V_97 ;
if ( F_70 ( V_2 ) || F_80 ( V_2 ) || F_60 ( V_2 ) >= 5 ) {
* V_93 = V_85 ;
* V_94 = 0 ;
} else {
* V_93 = V_85 / V_69 ;
* V_94 = V_85 - ( * V_93 * V_69 ) ;
}
if ( V_98 )
V_99 |= V_108 ;
return V_99 ;
}
int F_82 ( struct V_70 * V_84 )
{
struct V_1 * V_2 = F_62 ( V_84 -> V_73 . V_48 ) ;
unsigned long V_100 ;
int V_85 ;
F_78 ( & V_2 -> V_105 . V_106 , V_100 ) ;
V_85 = F_69 ( V_84 ) ;
F_81 ( & V_2 -> V_105 . V_106 , V_100 ) ;
return V_85 ;
}
static int F_83 ( struct V_47 * V_48 , unsigned int V_38 ,
int * V_109 ,
struct V_110 * V_111 ,
unsigned V_78 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
struct V_70 * V_84 ;
if ( V_38 >= F_20 ( V_2 ) -> V_112 ) {
F_84 ( L_5 , V_38 ) ;
return - V_113 ;
}
V_84 = F_63 ( V_2 , V_38 ) ;
if ( V_84 == NULL ) {
F_84 ( L_5 , V_38 ) ;
return - V_113 ;
}
if ( ! V_84 -> V_73 . V_74 . V_101 ) {
F_85 ( L_6 , V_38 ) ;
return - V_114 ;
}
return F_86 ( V_48 , V_38 , V_109 ,
V_111 , V_78 ,
& V_84 -> V_73 . V_74 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
T_2 V_115 , V_116 , V_117 , V_118 ;
T_5 V_119 ;
F_88 ( & V_120 ) ;
F_89 ( V_121 , F_2 ( V_121 ) ) ;
V_119 = V_2 -> V_122 . V_123 ;
F_89 ( V_121 , V_124 ) ;
V_115 = F_2 ( V_125 ) ;
V_116 = F_2 ( V_126 ) ;
V_117 = F_2 ( V_127 ) ;
V_118 = F_2 ( V_128 ) ;
if ( V_115 > V_117 ) {
if ( V_2 -> V_122 . V_123 != V_2 -> V_122 . V_129 )
V_119 = V_2 -> V_122 . V_123 - 1 ;
if ( V_119 < V_2 -> V_122 . V_129 )
V_119 = V_2 -> V_122 . V_129 ;
} else if ( V_116 < V_118 ) {
if ( V_2 -> V_122 . V_123 != V_2 -> V_122 . V_130 )
V_119 = V_2 -> V_122 . V_123 + 1 ;
if ( V_119 > V_2 -> V_122 . V_130 )
V_119 = V_2 -> V_122 . V_130 ;
}
if ( F_90 ( V_2 , V_119 ) )
V_2 -> V_122 . V_123 = V_119 ;
F_91 ( & V_120 ) ;
return;
}
static void F_92 ( struct V_131 * V_132 )
{
F_93 ( V_132 -> V_133 . V_134 , true ) ;
if ( F_94 ( V_132 ) )
F_95 ( V_132 ) ;
}
static void F_96 ( struct V_1 * V_2 ,
struct V_135 * V_136 )
{
V_136 -> V_137 = F_97 ( V_2 , V_138 ) ;
V_136 -> V_139 = F_2 ( V_140 ) ;
V_136 -> V_141 = F_2 ( V_142 ) ;
}
void F_98 ( struct V_1 * V_2 )
{
memset ( & V_2 -> V_26 . V_136 , 0 , sizeof( V_2 -> V_26 . V_136 ) ) ;
}
static T_2 F_99 ( struct V_1 * V_2 , T_2 V_27 )
{
const struct V_135 * V_143 = & V_2 -> V_26 . V_136 ;
struct V_135 V_144 ;
T_2 V_145 = 0 ;
if ( ( V_27 & V_146 ) == 0 )
return 0 ;
F_96 ( V_2 , & V_144 ) ;
if ( V_144 . V_137 == 0 )
return 0 ;
if ( V_143 -> V_137 ) {
T_6 time , V_147 ;
unsigned int V_148 ;
V_148 = V_149 * 100 ;
if ( F_2 ( V_150 ) & V_151 )
V_148 <<= 8 ;
time = V_144 . V_137 - V_143 -> V_137 ;
time *= V_2 -> V_152 ;
V_147 = V_144 . V_139 - V_143 -> V_139 ;
V_147 += V_144 . V_141 - V_143 -> V_141 ;
V_147 *= V_148 ;
if ( V_147 > time * V_2 -> V_26 . V_153 )
V_145 = V_154 ;
else if ( V_147 < time * V_2 -> V_26 . V_155 )
V_145 = V_156 ;
}
V_2 -> V_26 . V_136 = V_144 ;
return V_145 ;
}
static bool F_100 ( struct V_1 * V_2 )
{
struct V_131 * V_132 ;
enum V_157 V_158 ;
F_101 (engine, dev_priv, id)
if ( F_102 ( V_132 ) )
return true ;
return false ;
}
static void F_103 ( struct V_159 * V_33 )
{
struct V_1 * V_2 =
F_104 ( V_33 , struct V_1 , V_26 . V_33 ) ;
bool V_160 ;
int V_119 , V_161 , V_162 , V_163 ;
T_2 V_27 ;
F_11 ( & V_2 -> V_7 ) ;
if ( ! V_2 -> V_26 . V_28 ) {
F_12 ( & V_2 -> V_7 ) ;
return;
}
V_27 = V_2 -> V_26 . V_27 ;
V_2 -> V_26 . V_27 = 0 ;
F_27 ( V_2 , V_2 -> V_25 ) ;
V_160 = V_2 -> V_26 . V_160 ;
V_2 -> V_26 . V_160 = false ;
F_12 ( & V_2 -> V_7 ) ;
F_9 ( V_27 & ~ V_2 -> V_25 ) ;
if ( ( V_27 & V_2 -> V_25 ) == 0 && ! V_160 )
return;
F_105 ( & V_2 -> V_26 . V_164 ) ;
V_27 |= F_99 ( V_2 , V_27 ) ;
V_161 = V_2 -> V_26 . V_165 ;
V_119 = V_2 -> V_26 . V_166 ;
V_162 = V_2 -> V_26 . V_167 ;
V_163 = V_2 -> V_26 . V_168 ;
if ( V_160 || F_100 ( V_2 ) )
V_163 = V_2 -> V_26 . V_169 ;
if ( V_160 && V_119 < V_2 -> V_26 . V_170 ) {
V_119 = V_2 -> V_26 . V_170 ;
V_161 = 0 ;
} else if ( V_27 & V_154 ) {
if ( V_161 > 0 )
V_161 *= 2 ;
else
V_161 = F_56 ( V_2 ) ? 2 : 1 ;
if ( V_119 >= V_2 -> V_26 . V_168 )
V_161 = 0 ;
if ( V_119 < V_2 -> V_26 . V_171 - V_161 ) {
V_119 = V_2 -> V_26 . V_171 ;
V_161 = 0 ;
}
} else if ( V_160 || F_100 ( V_2 ) ) {
V_161 = 0 ;
} else if ( V_27 & V_172 ) {
if ( V_2 -> V_26 . V_166 > V_2 -> V_26 . V_171 )
V_119 = V_2 -> V_26 . V_171 ;
else
V_119 = V_2 -> V_26 . V_167 ;
V_161 = 0 ;
} else if ( V_27 & V_156 ) {
if ( V_161 < 0 )
V_161 *= 2 ;
else
V_161 = F_56 ( V_2 ) ? - 2 : - 1 ;
if ( V_119 <= V_2 -> V_26 . V_167 )
V_161 = 0 ;
} else {
V_161 = 0 ;
}
V_2 -> V_26 . V_165 = V_161 ;
V_119 += V_161 ;
V_119 = F_106 ( int , V_119 , V_162 , V_163 ) ;
F_107 ( V_2 , V_119 ) ;
F_108 ( & V_2 -> V_26 . V_164 ) ;
}
static void F_109 ( struct V_159 * V_33 )
{
struct V_1 * V_2 =
F_104 ( V_33 , struct V_1 , V_173 . V_174 ) ;
T_2 V_175 , V_176 , V_177 , V_178 ;
char * V_179 [ 6 ] ;
T_3 V_180 ;
T_7 V_181 = 0 ;
F_105 ( & V_2 -> V_31 . V_182 ) ;
if ( F_9 ( ! V_2 -> V_173 . V_183 ) )
goto V_184;
V_180 = F_2 ( V_185 ) ;
F_5 ( V_185 , V_180 & ~ V_186 ) ;
F_6 ( V_185 ) ;
while ( ( V_181 = F_110 ( V_2 -> V_173 . V_183 ) ) != 0 ) {
T_1 V_3 ;
V_181 -- ;
if ( F_36 ( V_181 >= F_111 ( V_2 ) ) )
break;
V_2 -> V_173 . V_183 &= ~ ( 1 << V_181 ) ;
V_3 = F_112 ( V_181 ) ;
V_175 = F_2 ( V_3 ) ;
V_176 = F_113 ( V_175 ) ;
V_177 = F_114 ( V_175 ) ;
V_178 = F_115 ( V_175 ) ;
F_5 ( V_3 , V_187 | V_188 ) ;
F_6 ( V_3 ) ;
V_179 [ 0 ] = V_189 L_7 ;
V_179 [ 1 ] = F_116 ( V_190 , L_8 , V_176 ) ;
V_179 [ 2 ] = F_116 ( V_190 , L_9 , V_177 ) ;
V_179 [ 3 ] = F_116 ( V_190 , L_10 , V_178 ) ;
V_179 [ 4 ] = F_116 ( V_190 , L_11 , V_181 ) ;
V_179 [ 5 ] = NULL ;
F_117 ( & V_2 -> V_31 . V_191 -> V_192 -> V_193 ,
V_194 , V_179 ) ;
F_118 ( L_12 ,
V_181 , V_176 , V_177 , V_178 ) ;
F_119 ( V_179 [ 4 ] ) ;
F_119 ( V_179 [ 3 ] ) ;
F_119 ( V_179 [ 2 ] ) ;
F_119 ( V_179 [ 1 ] ) ;
}
F_5 ( V_185 , V_180 ) ;
V_184:
F_9 ( V_2 -> V_173 . V_183 ) ;
F_11 ( & V_2 -> V_7 ) ;
F_16 ( V_2 , F_120 ( V_2 ) ) ;
F_12 ( & V_2 -> V_7 ) ;
F_108 ( & V_2 -> V_31 . V_182 ) ;
}
static void F_121 ( struct V_1 * V_2 ,
T_2 V_195 )
{
if ( ! F_122 ( V_2 ) )
return;
F_88 ( & V_2 -> V_7 ) ;
F_18 ( V_2 , F_120 ( V_2 ) ) ;
F_91 ( & V_2 -> V_7 ) ;
V_195 &= F_120 ( V_2 ) ;
if ( V_195 & V_196 )
V_2 -> V_173 . V_183 |= 1 << 1 ;
if ( V_195 & V_197 )
V_2 -> V_173 . V_183 |= 1 << 0 ;
F_123 ( V_2 -> V_198 , & V_2 -> V_173 . V_174 ) ;
}
static void F_124 ( struct V_1 * V_2 ,
T_2 V_199 )
{
if ( V_199 & V_200 )
F_92 ( V_2 -> V_132 [ V_201 ] ) ;
if ( V_199 & V_202 )
F_92 ( V_2 -> V_132 [ V_203 ] ) ;
}
static void F_125 ( struct V_1 * V_2 ,
T_2 V_199 )
{
if ( V_199 & V_200 )
F_92 ( V_2 -> V_132 [ V_201 ] ) ;
if ( V_199 & V_204 )
F_92 ( V_2 -> V_132 [ V_203 ] ) ;
if ( V_199 & V_205 )
F_92 ( V_2 -> V_132 [ V_206 ] ) ;
if ( V_199 & ( V_207 |
V_208 |
V_209 ) )
F_118 ( L_13 , V_199 ) ;
if ( V_199 & F_120 ( V_2 ) )
F_121 ( V_2 , V_199 ) ;
}
static T_8 void
F_126 ( struct V_131 * V_132 , T_2 V_195 , int V_210 )
{
if ( V_195 & ( V_200 << V_210 ) )
F_92 ( V_132 ) ;
if ( V_195 & ( V_211 << V_210 ) )
F_127 ( & V_132 -> V_212 ) ;
}
static T_9 F_128 ( struct V_1 * V_2 ,
T_2 V_213 ,
T_2 V_199 [ 4 ] )
{
T_9 V_99 = V_214 ;
if ( V_213 & ( V_215 | V_216 ) ) {
V_199 [ 0 ] = F_71 ( F_21 ( 0 ) ) ;
if ( V_199 [ 0 ] ) {
F_129 ( F_21 ( 0 ) , V_199 [ 0 ] ) ;
V_99 = V_217 ;
} else
F_84 ( L_14 ) ;
}
if ( V_213 & ( V_218 | V_219 ) ) {
V_199 [ 1 ] = F_71 ( F_21 ( 1 ) ) ;
if ( V_199 [ 1 ] ) {
F_129 ( F_21 ( 1 ) , V_199 [ 1 ] ) ;
V_99 = V_217 ;
} else
F_84 ( L_15 ) ;
}
if ( V_213 & V_220 ) {
V_199 [ 3 ] = F_71 ( F_21 ( 3 ) ) ;
if ( V_199 [ 3 ] ) {
F_129 ( F_21 ( 3 ) , V_199 [ 3 ] ) ;
V_99 = V_217 ;
} else
F_84 ( L_16 ) ;
}
if ( V_213 & ( V_221 | V_222 ) ) {
V_199 [ 2 ] = F_71 ( F_21 ( 2 ) ) ;
if ( V_199 [ 2 ] & ( V_2 -> V_25 |
V_2 -> V_34 ) ) {
F_129 ( F_21 ( 2 ) ,
V_199 [ 2 ] & ( V_2 -> V_25 |
V_2 -> V_34 ) ) ;
V_99 = V_217 ;
} else
F_84 ( L_17 ) ;
}
return V_99 ;
}
static void F_130 ( struct V_1 * V_2 ,
T_2 V_199 [ 4 ] )
{
if ( V_199 [ 0 ] ) {
F_126 ( V_2 -> V_132 [ V_201 ] ,
V_199 [ 0 ] , V_223 ) ;
F_126 ( V_2 -> V_132 [ V_206 ] ,
V_199 [ 0 ] , V_224 ) ;
}
if ( V_199 [ 1 ] ) {
F_126 ( V_2 -> V_132 [ V_203 ] ,
V_199 [ 1 ] , V_225 ) ;
F_126 ( V_2 -> V_132 [ V_226 ] ,
V_199 [ 1 ] , V_227 ) ;
}
if ( V_199 [ 3 ] )
F_126 ( V_2 -> V_132 [ V_228 ] ,
V_199 [ 3 ] , V_229 ) ;
if ( V_199 [ 2 ] & V_2 -> V_25 )
F_131 ( V_2 , V_199 [ 2 ] ) ;
if ( V_199 [ 2 ] & V_2 -> V_34 )
F_132 ( V_2 , V_199 [ 2 ] ) ;
}
static bool F_133 ( enum V_230 V_230 , T_2 V_4 )
{
switch ( V_230 ) {
case V_231 :
return V_4 & V_232 ;
case V_233 :
return V_4 & V_234 ;
case V_235 :
return V_4 & V_236 ;
default:
return false ;
}
}
static bool F_134 ( enum V_230 V_230 , T_2 V_4 )
{
switch ( V_230 ) {
case V_237 :
return V_4 & V_238 ;
default:
return false ;
}
}
static bool F_135 ( enum V_230 V_230 , T_2 V_4 )
{
switch ( V_230 ) {
case V_231 :
return V_4 & V_232 ;
case V_233 :
return V_4 & V_234 ;
case V_235 :
return V_4 & V_236 ;
case V_239 :
return V_4 & V_240 ;
default:
return false ;
}
}
static bool F_136 ( enum V_230 V_230 , T_2 V_4 )
{
switch ( V_230 ) {
case V_231 :
return V_4 & V_241 ;
default:
return false ;
}
}
static bool F_137 ( enum V_230 V_230 , T_2 V_4 )
{
switch ( V_230 ) {
case V_233 :
return V_4 & V_234 ;
case V_235 :
return V_4 & V_236 ;
case V_239 :
return V_4 & V_240 ;
default:
return false ;
}
}
static bool F_138 ( enum V_230 V_230 , T_2 V_4 )
{
switch ( V_230 ) {
case V_233 :
return V_4 & V_242 ;
case V_235 :
return V_4 & V_243 ;
case V_239 :
return V_4 & V_244 ;
default:
return false ;
}
}
static void F_139 ( T_2 * V_245 , T_2 * V_246 ,
T_2 V_247 , T_2 V_248 ,
const T_2 V_249 [ V_250 ] ,
bool F_140 ( enum V_230 V_230 , T_2 V_4 ) )
{
enum V_230 V_230 ;
int V_90 ;
F_141 (i) {
if ( ( V_249 [ V_90 ] & V_247 ) == 0 )
continue;
* V_245 |= F_142 ( V_90 ) ;
if ( ! F_143 ( V_90 , & V_230 ) )
continue;
if ( F_140 ( V_230 , V_248 ) )
* V_246 |= F_142 ( V_90 ) ;
}
F_77 ( L_18 ,
V_247 , V_248 , * V_245 ) ;
}
static void F_144 ( struct V_1 * V_2 )
{
F_145 ( & V_2 -> V_251 ) ;
}
static void F_146 ( struct V_1 * V_2 )
{
F_145 ( & V_2 -> V_251 ) ;
}
static void F_147 ( struct V_1 * V_2 ,
enum V_38 V_38 ,
T_3 V_252 , T_3 V_253 ,
T_3 V_254 , T_3 V_255 ,
T_3 V_256 )
{
struct V_257 * V_258 = & V_2 -> V_258 [ V_38 ] ;
struct V_259 * V_260 ;
struct V_70 * V_84 = F_63 ( V_2 , V_38 ) ;
struct V_261 * V_262 = V_2 -> V_31 . V_262 ;
T_3 V_263 [ 5 ] ;
int V_264 , V_265 ;
F_88 ( & V_258 -> V_106 ) ;
if ( V_258 -> V_266 ) {
if ( ! V_258 -> V_267 ) {
F_91 ( & V_258 -> V_106 ) ;
F_85 ( L_19 ) ;
return;
}
V_264 = V_258 -> V_264 ;
V_265 = V_258 -> V_265 ;
if ( F_148 ( V_264 , V_265 , V_268 ) < 1 ) {
F_91 ( & V_258 -> V_106 ) ;
F_84 ( L_20 ) ;
return;
}
V_260 = & V_258 -> V_267 [ V_264 ] ;
V_260 -> V_269 = V_262 -> V_270 ( & V_2 -> V_31 , V_38 ) ;
V_260 -> V_271 [ 0 ] = V_252 ;
V_260 -> V_271 [ 1 ] = V_253 ;
V_260 -> V_271 [ 2 ] = V_254 ;
V_260 -> V_271 [ 3 ] = V_255 ;
V_260 -> V_271 [ 4 ] = V_256 ;
V_264 = ( V_264 + 1 ) & ( V_268 - 1 ) ;
V_258 -> V_264 = V_264 ;
F_91 ( & V_258 -> V_106 ) ;
F_149 ( & V_258 -> V_198 ) ;
} else {
if ( V_258 -> V_272 == 0 ||
( F_56 ( V_2 ) && V_258 -> V_272 == 1 ) ) {
V_258 -> V_272 ++ ;
F_91 ( & V_258 -> V_106 ) ;
return;
}
F_91 ( & V_258 -> V_106 ) ;
V_263 [ 0 ] = V_252 ;
V_263 [ 1 ] = V_253 ;
V_263 [ 2 ] = V_254 ;
V_263 [ 3 ] = V_255 ;
V_263 [ 4 ] = V_256 ;
F_150 ( & V_84 -> V_73 , true ,
F_151 ( & V_84 -> V_73 ) ,
V_263 ) ;
}
}
static inline void
F_147 ( struct V_1 * V_2 ,
enum V_38 V_38 ,
T_3 V_252 , T_3 V_253 ,
T_3 V_254 , T_3 V_255 ,
T_3 V_256 ) {}
static void F_152 ( struct V_1 * V_2 ,
enum V_38 V_38 )
{
F_147 ( V_2 , V_38 ,
F_2 ( F_153 ( V_38 ) ) ,
0 , 0 , 0 , 0 ) ;
}
static void F_154 ( struct V_1 * V_2 ,
enum V_38 V_38 )
{
F_147 ( V_2 , V_38 ,
F_2 ( F_153 ( V_38 ) ) ,
F_2 ( F_155 ( V_38 ) ) ,
F_2 ( F_156 ( V_38 ) ) ,
F_2 ( F_157 ( V_38 ) ) ,
F_2 ( F_158 ( V_38 ) ) ) ;
}
static void F_159 ( struct V_1 * V_2 ,
enum V_38 V_38 )
{
T_3 V_273 , V_274 ;
if ( F_60 ( V_2 ) >= 3 )
V_273 = F_2 ( F_160 ( V_38 ) ) ;
else
V_273 = 0 ;
if ( F_60 ( V_2 ) >= 5 || F_80 ( V_2 ) )
V_274 = F_2 ( F_161 ( V_38 ) ) ;
else
V_274 = 0 ;
F_147 ( V_2 , V_38 ,
F_2 ( F_162 ( V_38 ) ) ,
F_2 ( F_163 ( V_38 ) ) ,
F_2 ( F_164 ( V_38 ) ) ,
V_273 , V_274 ) ;
}
static void F_131 ( struct V_1 * V_2 , T_2 V_27 )
{
if ( V_27 & V_2 -> V_25 ) {
F_88 ( & V_2 -> V_7 ) ;
F_29 ( V_2 , V_27 & V_2 -> V_25 ) ;
if ( V_2 -> V_26 . V_28 ) {
V_2 -> V_26 . V_27 |= V_27 & V_2 -> V_25 ;
F_165 ( & V_2 -> V_26 . V_33 ) ;
}
F_91 ( & V_2 -> V_7 ) ;
}
if ( F_20 ( V_2 ) -> V_16 >= 8 )
return;
if ( F_166 ( V_2 ) ) {
if ( V_27 & V_275 )
F_92 ( V_2 -> V_132 [ V_228 ] ) ;
if ( V_27 & V_276 )
F_118 ( L_21 , V_27 ) ;
}
}
static void F_132 ( struct V_1 * V_2 , T_2 V_199 )
{
if ( V_199 & V_277 ) {
T_2 V_278 , V_279 ;
V_278 = F_2 ( F_167 ( 15 ) ) ;
V_279 = V_278 & ( V_280 |
V_281 ) ;
if ( V_279 ) {
F_5 ( F_167 ( 15 ) , V_278 & ~ V_279 ) ;
F_123 ( V_2 -> V_35 . log . V_282 ,
& V_2 -> V_35 . log . V_283 ) ;
V_2 -> V_35 . log . V_284 ++ ;
} else {
}
}
}
static bool F_168 ( struct V_1 * V_2 ,
enum V_38 V_38 )
{
bool V_99 ;
V_99 = F_169 ( & V_2 -> V_31 , V_38 ) ;
if ( V_99 )
F_170 ( V_2 , V_38 ) ;
return V_99 ;
}
static void F_171 ( struct V_1 * V_2 ,
T_2 V_195 , T_2 V_285 [ V_286 ] )
{
int V_38 ;
F_88 ( & V_2 -> V_7 ) ;
if ( ! V_2 -> V_287 ) {
F_91 ( & V_2 -> V_7 ) ;
return;
}
F_172 (dev_priv, pipe) {
T_1 V_3 ;
T_2 V_5 , V_288 = 0 ;
V_5 = V_51 ;
switch ( V_38 ) {
case V_60 :
V_288 = V_289 ;
break;
case V_58 :
V_288 = V_290 ;
break;
case V_291 :
V_288 = V_292 ;
break;
}
if ( V_195 & V_288 )
V_5 |= V_2 -> V_46 [ V_38 ] ;
if ( ! V_5 )
continue;
V_3 = F_49 ( V_38 ) ;
V_5 |= V_44 ;
V_285 [ V_38 ] = F_2 ( V_3 ) & V_5 ;
if ( V_285 [ V_38 ] & ( V_51 |
V_45 ) )
F_5 ( V_3 , V_285 [ V_38 ] ) ;
}
F_91 ( & V_2 -> V_7 ) ;
}
static void F_173 ( struct V_1 * V_2 ,
T_2 V_285 [ V_286 ] )
{
enum V_38 V_38 ;
F_172 (dev_priv, pipe) {
if ( V_285 [ V_38 ] & V_293 &&
F_168 ( V_2 , V_38 ) )
F_174 ( V_2 , V_38 ) ;
if ( V_285 [ V_38 ] & V_294 )
F_175 ( V_2 , V_38 ) ;
if ( V_285 [ V_38 ] & V_295 )
F_159 ( V_2 , V_38 ) ;
if ( V_285 [ V_38 ] & V_51 )
F_176 ( V_2 , V_38 ) ;
}
if ( V_285 [ 0 ] & V_296 )
F_144 ( V_2 ) ;
}
static T_2 F_177 ( struct V_1 * V_2 )
{
T_2 V_297 = F_2 ( V_298 ) ;
if ( V_297 )
F_5 ( V_298 , V_297 ) ;
return V_297 ;
}
static void F_178 ( struct V_1 * V_2 ,
T_2 V_297 )
{
T_2 V_245 = 0 , V_246 = 0 ;
if ( F_80 ( V_2 ) || F_55 ( V_2 ) ||
F_56 ( V_2 ) ) {
T_2 V_247 = V_297 & V_299 ;
if ( V_247 ) {
F_139 ( & V_245 , & V_246 , V_247 ,
V_247 , V_300 ,
F_138 ) ;
F_179 ( V_2 , V_245 , V_246 ) ;
}
if ( V_297 & V_301 )
F_146 ( V_2 ) ;
} else {
T_2 V_247 = V_297 & V_302 ;
if ( V_247 ) {
F_139 ( & V_245 , & V_246 , V_247 ,
V_247 , V_303 ,
F_138 ) ;
F_179 ( V_2 , V_245 , V_246 ) ;
}
}
}
static T_9 F_180 ( int V_32 , void * V_304 )
{
struct V_47 * V_48 = V_304 ;
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_9 V_99 = V_214 ;
if ( ! F_14 ( V_2 ) )
return V_214 ;
F_181 ( V_2 ) ;
do {
T_2 V_195 , V_199 , V_27 ;
T_2 V_285 [ V_286 ] = {} ;
T_2 V_297 = 0 ;
T_2 V_305 = 0 ;
V_199 = F_2 ( V_306 ) ;
V_27 = F_2 ( V_17 ) ;
V_195 = F_2 ( V_307 ) ;
if ( V_199 == 0 && V_27 == 0 && V_195 == 0 )
break;
V_99 = V_217 ;
F_5 ( V_308 , 0 ) ;
V_305 = F_2 ( V_309 ) ;
F_5 ( V_309 , 0 ) ;
if ( V_199 )
F_5 ( V_306 , V_199 ) ;
if ( V_27 )
F_5 ( V_17 , V_27 ) ;
if ( V_195 & V_310 )
V_297 = F_177 ( V_2 ) ;
F_171 ( V_2 , V_195 , V_285 ) ;
if ( V_195 & ( V_311 |
V_312 ) )
F_182 ( V_2 ) ;
if ( V_195 )
F_5 ( V_307 , V_195 ) ;
F_5 ( V_309 , V_305 ) ;
F_5 ( V_308 , V_313 ) ;
F_6 ( V_308 ) ;
if ( V_199 )
F_125 ( V_2 , V_199 ) ;
if ( V_27 )
F_131 ( V_2 , V_27 ) ;
if ( V_297 )
F_178 ( V_2 , V_297 ) ;
F_173 ( V_2 , V_285 ) ;
} while ( 0 );
F_183 ( V_2 ) ;
return V_99 ;
}
static T_9 F_184 ( int V_32 , void * V_304 )
{
struct V_47 * V_48 = V_304 ;
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_9 V_99 = V_214 ;
if ( ! F_14 ( V_2 ) )
return V_214 ;
F_181 ( V_2 ) ;
do {
T_2 V_213 , V_195 ;
T_2 V_199 [ 4 ] = {} ;
T_2 V_285 [ V_286 ] = {} ;
T_2 V_297 = 0 ;
T_2 V_305 = 0 ;
V_213 = F_2 ( V_314 ) & ~ V_315 ;
V_195 = F_2 ( V_307 ) ;
if ( V_213 == 0 && V_195 == 0 )
break;
V_99 = V_217 ;
F_5 ( V_314 , 0 ) ;
V_305 = F_2 ( V_309 ) ;
F_5 ( V_309 , 0 ) ;
F_128 ( V_2 , V_213 , V_199 ) ;
if ( V_195 & V_310 )
V_297 = F_177 ( V_2 ) ;
F_171 ( V_2 , V_195 , V_285 ) ;
if ( V_195 & ( V_311 |
V_312 |
V_316 ) )
F_182 ( V_2 ) ;
if ( V_195 )
F_5 ( V_307 , V_195 ) ;
F_5 ( V_309 , V_305 ) ;
F_5 ( V_314 , V_315 ) ;
F_6 ( V_314 ) ;
F_130 ( V_2 , V_199 ) ;
if ( V_297 )
F_178 ( V_2 , V_297 ) ;
F_173 ( V_2 , V_285 ) ;
} while ( 0 );
F_183 ( V_2 ) ;
return V_99 ;
}
static void F_185 ( struct V_1 * V_2 ,
T_2 V_247 ,
const T_2 V_249 [ V_250 ] )
{
T_2 V_248 , V_245 = 0 , V_246 = 0 ;
V_248 = F_2 ( V_317 ) ;
if ( ! V_247 ) {
T_2 V_5 = V_318 |
V_319 |
V_320 |
V_321 ;
V_248 &= ~ V_5 ;
}
F_5 ( V_317 , V_248 ) ;
if ( ! V_247 )
return;
F_139 ( & V_245 , & V_246 , V_247 ,
V_248 , V_249 ,
F_137 ) ;
F_179 ( V_2 , V_245 , V_246 ) ;
}
static void F_186 ( struct V_1 * V_2 , T_2 V_322 )
{
int V_38 ;
T_2 V_247 = V_322 & V_323 ;
F_185 ( V_2 , V_247 , V_324 ) ;
if ( V_322 & V_325 ) {
int V_230 = F_110 ( ( V_322 & V_325 ) >>
V_326 ) ;
F_77 ( L_22 ,
F_187 ( V_230 ) ) ;
}
if ( V_322 & V_327 )
F_146 ( V_2 ) ;
if ( V_322 & V_328 )
F_144 ( V_2 ) ;
if ( V_322 & V_329 )
F_77 ( L_23 ) ;
if ( V_322 & V_330 )
F_77 ( L_24 ) ;
if ( V_322 & V_331 )
F_84 ( L_25 ) ;
if ( V_322 & V_332 )
F_172 (dev_priv, pipe)
F_77 ( L_26 ,
F_51 ( V_38 ) ,
F_2 ( F_188 ( V_38 ) ) ) ;
if ( V_322 & ( V_333 | V_334 ) )
F_77 ( L_27 ) ;
if ( V_322 & ( V_335 | V_336 ) )
F_77 ( L_28 ) ;
if ( V_322 & V_337 )
F_189 ( V_2 , V_338 ) ;
if ( V_322 & V_339 )
F_189 ( V_2 , V_340 ) ;
}
static void F_190 ( struct V_1 * V_2 )
{
T_2 V_341 = F_2 ( V_342 ) ;
enum V_38 V_38 ;
if ( V_341 & V_343 )
F_84 ( L_29 ) ;
F_172 (dev_priv, pipe) {
if ( V_341 & F_191 ( V_38 ) )
F_176 ( V_2 , V_38 ) ;
if ( V_341 & F_192 ( V_38 ) ) {
if ( F_193 ( V_2 ) )
F_154 ( V_2 , V_38 ) ;
else
F_152 ( V_2 , V_38 ) ;
}
}
F_5 ( V_342 , V_341 ) ;
}
static void F_194 ( struct V_1 * V_2 )
{
T_2 V_344 = F_2 ( V_345 ) ;
if ( V_344 & V_346 )
F_84 ( L_25 ) ;
if ( V_344 & V_347 )
F_189 ( V_2 , V_338 ) ;
if ( V_344 & V_348 )
F_189 ( V_2 , V_340 ) ;
if ( V_344 & V_349 )
F_189 ( V_2 , V_350 ) ;
F_5 ( V_345 , V_344 ) ;
}
static void F_195 ( struct V_1 * V_2 , T_2 V_322 )
{
int V_38 ;
T_2 V_247 = V_322 & V_351 ;
F_185 ( V_2 , V_247 , V_352 ) ;
if ( V_322 & V_353 ) {
int V_230 = F_110 ( ( V_322 & V_353 ) >>
V_354 ) ;
F_77 ( L_30 ,
F_187 ( V_230 ) ) ;
}
if ( V_322 & V_355 )
F_146 ( V_2 ) ;
if ( V_322 & V_356 )
F_144 ( V_2 ) ;
if ( V_322 & V_357 )
F_77 ( L_31 ) ;
if ( V_322 & V_358 )
F_77 ( L_32 ) ;
if ( V_322 & V_359 )
F_172 (dev_priv, pipe)
F_77 ( L_26 ,
F_51 ( V_38 ) ,
F_2 ( F_188 ( V_38 ) ) ) ;
if ( V_322 & V_360 )
F_194 ( V_2 ) ;
}
static void F_196 ( struct V_1 * V_2 , T_2 V_322 )
{
T_2 V_247 = V_322 & V_361 &
~ V_362 ;
T_2 V_363 = V_322 & V_362 ;
T_2 V_245 = 0 , V_246 = 0 ;
if ( V_247 ) {
T_2 V_248 ;
V_248 = F_2 ( V_317 ) ;
F_5 ( V_317 , V_248 ) ;
F_139 ( & V_245 , & V_246 , V_247 ,
V_248 , V_364 ,
F_135 ) ;
}
if ( V_363 ) {
T_2 V_248 ;
V_248 = F_2 ( V_365 ) ;
F_5 ( V_365 , V_248 ) ;
F_139 ( & V_245 , & V_246 , V_363 ,
V_248 , V_364 ,
F_134 ) ;
}
if ( V_245 )
F_179 ( V_2 , V_245 , V_246 ) ;
if ( V_322 & V_356 )
F_144 ( V_2 ) ;
}
static void F_197 ( struct V_1 * V_2 ,
T_2 V_247 ,
const T_2 V_249 [ V_250 ] )
{
T_2 V_248 , V_245 = 0 , V_246 = 0 ;
V_248 = F_2 ( V_366 ) ;
F_5 ( V_366 , V_248 ) ;
F_139 ( & V_245 , & V_246 , V_247 ,
V_248 , V_249 ,
F_136 ) ;
F_179 ( V_2 , V_245 , V_246 ) ;
}
static void F_198 ( struct V_1 * V_2 ,
T_2 V_367 )
{
enum V_38 V_38 ;
T_2 V_247 = V_367 & V_368 ;
if ( V_247 )
F_197 ( V_2 , V_247 , V_369 ) ;
if ( V_367 & V_370 )
F_146 ( V_2 ) ;
if ( V_367 & V_371 )
F_199 ( V_2 ) ;
if ( V_367 & V_372 )
F_84 ( L_29 ) ;
F_172 (dev_priv, pipe) {
if ( V_367 & F_200 ( V_38 ) &&
F_168 ( V_2 , V_38 ) )
F_174 ( V_2 , V_38 ) ;
if ( V_367 & F_201 ( V_38 ) )
F_176 ( V_2 , V_38 ) ;
if ( V_367 & F_202 ( V_38 ) )
F_159 ( V_2 , V_38 ) ;
if ( V_367 & F_203 ( V_38 ) )
F_175 ( V_2 , V_38 ) ;
}
if ( V_367 & V_373 ) {
T_2 V_322 = F_2 ( V_374 ) ;
if ( F_204 ( V_2 ) )
F_195 ( V_2 , V_322 ) ;
else
F_186 ( V_2 , V_322 ) ;
F_5 ( V_374 , V_322 ) ;
}
if ( F_205 ( V_2 ) && V_367 & V_375 )
F_87 ( V_2 ) ;
}
static void F_206 ( struct V_1 * V_2 ,
T_2 V_367 )
{
enum V_38 V_38 ;
T_2 V_247 = V_367 & V_376 ;
if ( V_247 )
F_197 ( V_2 , V_247 , V_377 ) ;
if ( V_367 & V_378 )
F_190 ( V_2 ) ;
if ( V_367 & V_379 )
F_146 ( V_2 ) ;
if ( V_367 & V_380 )
F_199 ( V_2 ) ;
F_172 (dev_priv, pipe) {
if ( V_367 & ( F_207 ( V_38 ) ) &&
F_168 ( V_2 , V_38 ) )
F_174 ( V_2 , V_38 ) ;
if ( V_367 & F_208 ( V_38 ) )
F_175 ( V_2 , V_38 ) ;
}
if ( ! F_209 ( V_2 ) && ( V_367 & V_381 ) ) {
T_2 V_322 = F_2 ( V_374 ) ;
F_195 ( V_2 , V_322 ) ;
F_5 ( V_374 , V_322 ) ;
}
}
static T_9 F_210 ( int V_32 , void * V_304 )
{
struct V_47 * V_48 = V_304 ;
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_2 V_367 , V_199 , V_382 , V_383 = 0 ;
T_9 V_99 = V_214 ;
if ( ! F_14 ( V_2 ) )
return V_214 ;
F_181 ( V_2 ) ;
V_382 = F_2 ( V_384 ) ;
F_5 ( V_384 , V_382 & ~ V_385 ) ;
F_6 ( V_384 ) ;
if ( ! F_209 ( V_2 ) ) {
V_383 = F_2 ( V_386 ) ;
F_5 ( V_386 , 0 ) ;
F_6 ( V_386 ) ;
}
V_199 = F_2 ( V_306 ) ;
if ( V_199 ) {
F_5 ( V_306 , V_199 ) ;
V_99 = V_217 ;
if ( F_60 ( V_2 ) >= 6 )
F_125 ( V_2 , V_199 ) ;
else
F_124 ( V_2 , V_199 ) ;
}
V_367 = F_2 ( V_387 ) ;
if ( V_367 ) {
F_5 ( V_387 , V_367 ) ;
V_99 = V_217 ;
if ( F_60 ( V_2 ) >= 7 )
F_206 ( V_2 , V_367 ) ;
else
F_198 ( V_2 , V_367 ) ;
}
if ( F_60 ( V_2 ) >= 6 ) {
T_2 V_27 = F_2 ( V_17 ) ;
if ( V_27 ) {
F_5 ( V_17 , V_27 ) ;
V_99 = V_217 ;
F_131 ( V_2 , V_27 ) ;
}
}
F_5 ( V_384 , V_382 ) ;
F_6 ( V_384 ) ;
if ( ! F_209 ( V_2 ) ) {
F_5 ( V_386 , V_383 ) ;
F_6 ( V_386 ) ;
}
F_183 ( V_2 ) ;
return V_99 ;
}
static void F_211 ( struct V_1 * V_2 ,
T_2 V_247 ,
const T_2 V_249 [ V_250 ] )
{
T_2 V_248 , V_245 = 0 , V_246 = 0 ;
V_248 = F_2 ( V_317 ) ;
F_5 ( V_317 , V_248 ) ;
F_139 ( & V_245 , & V_246 , V_247 ,
V_248 , V_249 ,
F_133 ) ;
F_179 ( V_2 , V_245 , V_246 ) ;
}
static T_9
F_212 ( struct V_1 * V_2 , T_2 V_213 )
{
T_9 V_99 = V_214 ;
T_2 V_195 ;
enum V_38 V_38 ;
if ( V_213 & V_388 ) {
V_195 = F_2 ( V_389 ) ;
if ( V_195 ) {
F_5 ( V_389 , V_195 ) ;
V_99 = V_217 ;
if ( V_195 & V_390 )
F_199 ( V_2 ) ;
else
F_84 ( L_33 ) ;
}
else
F_84 ( L_34 ) ;
}
if ( V_213 & V_391 ) {
V_195 = F_2 ( V_392 ) ;
if ( V_195 ) {
T_2 V_393 ;
bool V_394 = false ;
F_5 ( V_392 , V_195 ) ;
V_99 = V_217 ;
V_393 = V_395 ;
if ( F_20 ( V_2 ) -> V_16 >= 9 )
V_393 |= V_396 |
V_397 |
V_398 ;
if ( V_195 & V_393 ) {
F_146 ( V_2 ) ;
V_394 = true ;
}
if ( F_213 ( V_2 ) ) {
V_393 = V_195 & V_399 ;
if ( V_393 ) {
F_211 ( V_2 , V_393 ,
V_400 ) ;
V_394 = true ;
}
} else if ( F_214 ( V_2 ) ) {
V_393 = V_195 & V_401 ;
if ( V_393 ) {
F_197 ( V_2 ,
V_393 , V_402 ) ;
V_394 = true ;
}
}
if ( F_213 ( V_2 ) && ( V_195 & V_403 ) ) {
F_144 ( V_2 ) ;
V_394 = true ;
}
if ( ! V_394 )
F_84 ( L_35 ) ;
}
else
F_84 ( L_36 ) ;
}
F_172 (dev_priv, pipe) {
T_2 V_404 , V_405 ;
if ( ! ( V_213 & F_215 ( V_38 ) ) )
continue;
V_195 = F_2 ( F_216 ( V_38 ) ) ;
if ( ! V_195 ) {
F_84 ( L_37 ) ;
continue;
}
V_99 = V_217 ;
F_5 ( F_216 ( V_38 ) , V_195 ) ;
if ( V_195 & V_406 &&
F_168 ( V_2 , V_38 ) )
F_174 ( V_2 , V_38 ) ;
V_404 = V_195 ;
if ( F_20 ( V_2 ) -> V_16 >= 9 )
V_404 &= V_407 ;
else
V_404 &= V_408 ;
if ( V_404 )
F_175 ( V_2 , V_38 ) ;
if ( V_195 & V_409 )
F_152 ( V_2 , V_38 ) ;
if ( V_195 & V_410 )
F_176 ( V_2 , V_38 ) ;
V_405 = V_195 ;
if ( F_20 ( V_2 ) -> V_16 >= 9 )
V_405 &= V_411 ;
else
V_405 &= V_412 ;
if ( V_405 )
F_84 ( L_38 ,
F_51 ( V_38 ) ,
V_405 ) ;
}
if ( F_217 ( V_2 ) && ! F_209 ( V_2 ) &&
V_213 & V_413 ) {
V_195 = F_2 ( V_374 ) ;
if ( V_195 ) {
F_5 ( V_374 , V_195 ) ;
V_99 = V_217 ;
if ( F_218 ( V_2 ) || F_219 ( V_2 ) )
F_196 ( V_2 , V_195 ) ;
else
F_195 ( V_2 , V_195 ) ;
} else {
F_77 ( L_39 ) ;
}
}
return V_99 ;
}
static T_9 F_220 ( int V_32 , void * V_304 )
{
struct V_47 * V_48 = V_304 ;
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_2 V_213 ;
T_2 V_199 [ 4 ] = {} ;
T_9 V_99 ;
if ( ! F_14 ( V_2 ) )
return V_214 ;
V_213 = F_71 ( V_314 ) ;
V_213 &= ~ V_315 ;
if ( ! V_213 )
return V_214 ;
F_129 ( V_314 , 0 ) ;
F_181 ( V_2 ) ;
V_99 = F_128 ( V_2 , V_213 , V_199 ) ;
F_130 ( V_2 , V_199 ) ;
V_99 |= F_212 ( V_2 , V_213 ) ;
F_129 ( V_314 , V_315 ) ;
F_17 ( V_314 ) ;
F_183 ( V_2 ) ;
return V_99 ;
}
static void F_221 ( struct V_1 * V_2 )
{
F_145 ( & V_2 -> V_414 . V_415 ) ;
F_145 ( & V_2 -> V_416 ) ;
}
static void F_222 ( struct V_1 * V_2 )
{
struct V_417 * V_193 = & V_2 -> V_31 . V_191 -> V_192 -> V_193 ;
char * V_418 [] = { V_419 L_7 , NULL } ;
char * V_420 [] = { V_421 L_7 , NULL } ;
char * V_422 [] = { V_419 L_40 , NULL } ;
F_117 ( V_193 , V_194 , V_418 ) ;
F_77 ( L_41 ) ;
F_117 ( V_193 , V_194 , V_420 ) ;
F_223 ( V_2 ) ;
F_224 ( V_2 ) ;
do {
if ( F_225 ( & V_2 -> V_31 . V_182 ) ) {
F_226 ( V_2 ) ;
F_108 ( & V_2 -> V_31 . V_182 ) ;
}
} while ( F_227 ( & V_2 -> V_414 . V_78 ,
V_423 ,
V_424 ,
V_425 ) );
F_228 ( V_2 ) ;
F_229 ( V_2 ) ;
if ( ! F_230 ( V_426 , & V_2 -> V_414 . V_78 ) )
F_117 ( V_193 ,
V_194 , V_422 ) ;
F_145 ( & V_2 -> V_414 . V_427 ) ;
}
static inline void
F_231 ( struct V_1 * V_2 ,
struct V_428 * V_429 )
{
int V_181 ;
int V_430 ;
F_232 ( L_42 , V_429 -> V_429 ) ;
if ( F_60 ( V_2 ) <= 3 )
return;
F_232 ( L_43 , V_429 -> V_431 ) ;
if ( F_60 ( V_2 ) <= 6 )
return;
F_233 (dev_priv, slice, subslice)
F_232 ( L_44 ,
V_181 , V_430 , V_429 -> V_432 [ V_181 ] [ V_430 ] ) ;
F_233 (dev_priv, slice, subslice)
F_232 ( L_45 ,
V_181 , V_430 , V_429 -> V_176 [ V_181 ] [ V_430 ] ) ;
}
static void F_234 ( struct V_1 * V_2 )
{
T_2 V_433 ;
if ( ! F_70 ( V_2 ) )
F_5 ( V_434 , F_2 ( V_434 ) ) ;
if ( F_60 ( V_2 ) < 4 )
F_5 ( V_435 , F_2 ( V_435 ) ) ;
else
F_5 ( V_436 , F_2 ( V_436 ) ) ;
F_5 ( V_437 , F_2 ( V_437 ) ) ;
V_433 = F_2 ( V_437 ) ;
if ( V_433 ) {
F_77 ( L_46 , V_433 ) ;
F_5 ( V_438 , F_2 ( V_438 ) | V_433 ) ;
F_5 ( V_439 , V_440 ) ;
}
}
void F_235 ( struct V_1 * V_2 ,
T_2 V_441 ,
const char * V_442 , ... )
{
T_10 args ;
char V_443 [ 80 ] ;
va_start ( args , V_442 ) ;
F_236 ( V_443 , sizeof( V_443 ) , V_442 , args ) ;
va_end ( args ) ;
F_237 ( V_2 , V_441 , V_443 ) ;
F_234 ( V_2 ) ;
if ( ! V_441 )
return;
if ( F_238 ( V_423 ,
& V_2 -> V_414 . V_78 ) )
return;
F_221 ( V_2 ) ;
F_222 ( V_2 ) ;
}
static int F_239 ( struct V_47 * V_48 , unsigned int V_38 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
unsigned long V_100 ;
F_78 ( & V_2 -> V_7 , V_100 ) ;
F_54 ( V_2 , V_38 , V_444 ) ;
F_81 ( & V_2 -> V_7 , V_100 ) ;
return 0 ;
}
static int F_240 ( struct V_47 * V_48 , unsigned int V_38 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
unsigned long V_100 ;
F_78 ( & V_2 -> V_7 , V_100 ) ;
F_54 ( V_2 , V_38 ,
V_293 ) ;
F_81 ( & V_2 -> V_7 , V_100 ) ;
return 0 ;
}
static int F_241 ( struct V_47 * V_48 , unsigned int V_38 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
unsigned long V_100 ;
T_3 V_445 = F_60 ( V_2 ) >= 7 ?
F_207 ( V_38 ) : F_200 ( V_38 ) ;
F_78 ( & V_2 -> V_7 , V_100 ) ;
F_242 ( V_2 , V_445 ) ;
F_81 ( & V_2 -> V_7 , V_100 ) ;
return 0 ;
}
static int F_243 ( struct V_47 * V_48 , unsigned int V_38 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
unsigned long V_100 ;
F_78 ( & V_2 -> V_7 , V_100 ) ;
F_244 ( V_2 , V_38 , V_406 ) ;
F_81 ( & V_2 -> V_7 , V_100 ) ;
return 0 ;
}
static void F_245 ( struct V_47 * V_48 , unsigned int V_38 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
unsigned long V_100 ;
F_78 ( & V_2 -> V_7 , V_100 ) ;
F_57 ( V_2 , V_38 , V_444 ) ;
F_81 ( & V_2 -> V_7 , V_100 ) ;
}
static void F_246 ( struct V_47 * V_48 , unsigned int V_38 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
unsigned long V_100 ;
F_78 ( & V_2 -> V_7 , V_100 ) ;
F_57 ( V_2 , V_38 ,
V_293 ) ;
F_81 ( & V_2 -> V_7 , V_100 ) ;
}
static void F_247 ( struct V_47 * V_48 , unsigned int V_38 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
unsigned long V_100 ;
T_3 V_445 = F_60 ( V_2 ) >= 7 ?
F_207 ( V_38 ) : F_200 ( V_38 ) ;
F_78 ( & V_2 -> V_7 , V_100 ) ;
F_248 ( V_2 , V_445 ) ;
F_81 ( & V_2 -> V_7 , V_100 ) ;
}
static void F_249 ( struct V_47 * V_48 , unsigned int V_38 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
unsigned long V_100 ;
F_78 ( & V_2 -> V_7 , V_100 ) ;
F_250 ( V_2 , V_38 , V_406 ) ;
F_81 ( & V_2 -> V_7 , V_100 ) ;
}
static void F_251 ( struct V_1 * V_2 )
{
if ( F_209 ( V_2 ) )
return;
F_252 ( V_446 ) ;
if ( F_204 ( V_2 ) || F_253 ( V_2 ) )
F_5 ( V_345 , 0xffffffff ) ;
}
static void F_254 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
if ( F_209 ( V_2 ) )
return;
F_9 ( F_2 ( V_386 ) != 0 ) ;
F_5 ( V_386 , 0xffffffff ) ;
F_6 ( V_386 ) ;
}
static void F_255 ( struct V_1 * V_2 )
{
F_252 ( V_447 ) ;
if ( F_60 ( V_2 ) >= 6 )
F_252 ( V_448 ) ;
}
static void F_256 ( struct V_1 * V_2 )
{
enum V_38 V_38 ;
if ( F_56 ( V_2 ) )
F_5 ( V_449 , V_450 ) ;
else
F_5 ( V_449 , V_451 ) ;
F_7 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_298 , F_2 ( V_298 ) ) ;
F_172 (dev_priv, pipe) {
F_5 ( F_49 ( V_38 ) ,
V_51 |
V_45 ) ;
V_2 -> V_46 [ V_38 ] = 0 ;
}
F_252 ( V_452 ) ;
V_2 -> V_12 = ~ 0 ;
}
static void F_257 ( struct V_1 * V_2 )
{
T_2 V_453 ;
T_2 V_22 ;
enum V_38 V_38 ;
T_2 V_4 ;
V_453 = V_294 |
V_295 ;
F_54 ( V_2 , V_60 , V_296 ) ;
F_172 (dev_priv, pipe)
F_54 ( V_2 , V_38 , V_453 ) ;
V_22 = V_310 |
V_289 |
V_290 ;
if ( F_56 ( V_2 ) )
V_22 |= V_292 ;
F_9 ( V_2 -> V_12 != ~ 0 ) ;
V_4 = ( V_311 |
V_312 |
V_316 ) ;
V_22 |= V_4 ;
V_2 -> V_12 = ~ V_22 ;
F_258 ( V_452 , V_2 -> V_12 , V_22 ) ;
}
static void F_259 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
F_5 ( V_454 , 0xffffffff ) ;
F_252 ( V_455 ) ;
if ( F_260 ( V_2 ) )
F_5 ( V_342 , 0xffffffff ) ;
F_255 ( V_2 ) ;
F_251 ( V_2 ) ;
}
static void F_261 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
F_5 ( V_308 , 0 ) ;
F_6 ( V_308 ) ;
F_255 ( V_2 ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_287 )
F_256 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
static void F_262 ( struct V_1 * V_2 )
{
F_263 ( V_447 , 0 ) ;
F_263 ( V_447 , 1 ) ;
F_263 ( V_447 , 2 ) ;
F_263 ( V_447 , 3 ) ;
}
static void F_264 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
int V_38 ;
F_5 ( V_314 , 0 ) ;
F_6 ( V_314 ) ;
F_262 ( V_2 ) ;
F_172 (dev_priv, pipe)
if ( F_265 ( V_2 ,
F_266 ( V_38 ) ) )
F_263 ( V_456 , V_38 ) ;
F_252 ( V_457 ) ;
F_252 ( V_458 ) ;
F_252 ( V_459 ) ;
if ( F_217 ( V_2 ) )
F_251 ( V_2 ) ;
}
void F_267 ( struct V_1 * V_2 ,
unsigned int V_460 )
{
T_3 V_461 = V_406 | V_410 ;
enum V_38 V_38 ;
F_11 ( & V_2 -> V_7 ) ;
F_268 (dev_priv, pipe, pipe_mask)
F_269 ( V_456 , V_38 ,
V_2 -> V_39 [ V_38 ] ,
~ V_2 -> V_39 [ V_38 ] | V_461 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
void F_270 ( struct V_1 * V_2 ,
unsigned int V_460 )
{
enum V_38 V_38 ;
F_11 ( & V_2 -> V_7 ) ;
F_268 (dev_priv, pipe, pipe_mask)
F_263 ( V_456 , V_38 ) ;
F_12 ( & V_2 -> V_7 ) ;
F_39 ( V_2 -> V_31 . V_32 ) ;
}
static void F_271 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
F_5 ( V_314 , 0 ) ;
F_6 ( V_314 ) ;
F_262 ( V_2 ) ;
F_252 ( V_459 ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_287 )
F_256 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
static T_2 F_272 ( struct V_1 * V_2 ,
const T_2 V_249 [ V_250 ] )
{
struct V_462 * V_463 ;
T_2 V_464 = 0 ;
F_273 (&dev_priv->drm, encoder)
if ( V_2 -> V_465 . V_466 [ V_463 -> V_467 ] . V_468 == V_469 )
V_464 |= V_249 [ V_463 -> V_467 ] ;
return V_464 ;
}
static void F_274 ( struct V_1 * V_2 )
{
T_2 V_470 , V_465 , V_464 ;
if ( F_275 ( V_2 ) ) {
V_470 = V_323 ;
V_464 = F_272 ( V_2 , V_324 ) ;
} else {
V_470 = V_351 ;
V_464 = F_272 ( V_2 , V_352 ) ;
}
F_47 ( V_2 , V_470 , V_464 ) ;
V_465 = F_2 ( V_317 ) ;
V_465 &= ~ ( V_471 | V_472 | V_473 ) ;
V_465 |= V_474 | V_475 ;
V_465 |= V_476 | V_477 ;
V_465 |= V_478 | V_479 ;
if ( F_276 ( V_2 ) )
V_465 |= V_480 ;
F_5 ( V_317 , V_465 ) ;
}
static void F_277 ( struct V_1 * V_2 )
{
T_2 V_465 ;
V_465 = F_2 ( V_317 ) ;
V_465 |= V_480 |
V_478 |
V_476 |
V_474 ;
F_5 ( V_317 , V_465 ) ;
V_465 = F_2 ( V_365 ) ;
V_465 |= V_481 ;
F_5 ( V_365 , V_465 ) ;
}
static void F_278 ( struct V_1 * V_2 )
{
T_2 V_470 , V_464 ;
V_470 = V_361 ;
V_464 = F_272 ( V_2 , V_364 ) ;
F_47 ( V_2 , V_470 , V_464 ) ;
F_277 ( V_2 ) ;
}
static void F_279 ( struct V_1 * V_2 )
{
T_2 V_470 , V_465 , V_464 ;
if ( F_60 ( V_2 ) >= 8 ) {
V_470 = V_401 ;
V_464 = F_272 ( V_2 , V_402 ) ;
F_44 ( V_2 , V_470 , V_464 ) ;
} else if ( F_60 ( V_2 ) >= 7 ) {
V_470 = V_376 ;
V_464 = F_272 ( V_2 , V_377 ) ;
F_13 ( V_2 , V_470 , V_464 ) ;
} else {
V_470 = V_368 ;
V_464 = F_272 ( V_2 , V_369 ) ;
F_13 ( V_2 , V_470 , V_464 ) ;
}
V_465 = F_2 ( V_366 ) ;
V_465 &= ~ V_482 ;
V_465 |= V_483 | V_484 ;
F_5 ( V_366 , V_465 ) ;
F_274 ( V_2 ) ;
}
static void F_280 ( struct V_1 * V_2 ,
T_2 V_464 )
{
T_2 V_465 ;
V_465 = F_2 ( V_317 ) ;
V_465 |= V_480 |
V_478 |
V_476 ;
F_85 ( L_47 ,
V_465 , V_464 ) ;
V_465 &= ~ V_485 ;
if ( ( V_464 & V_486 ) &&
F_281 ( V_2 , V_231 ) )
V_465 |= V_487 ;
if ( ( V_464 & V_488 ) &&
F_281 ( V_2 , V_233 ) )
V_465 |= V_489 ;
if ( ( V_464 & V_490 ) &&
F_281 ( V_2 , V_235 ) )
V_465 |= V_491 ;
F_5 ( V_317 , V_465 ) ;
}
static void F_282 ( struct V_1 * V_2 )
{
F_280 ( V_2 , V_399 ) ;
}
static void F_283 ( struct V_1 * V_2 )
{
T_2 V_470 , V_464 ;
V_464 = F_272 ( V_2 , V_400 ) ;
V_470 = V_399 ;
F_44 ( V_2 , V_470 , V_464 ) ;
F_280 ( V_2 , V_464 ) ;
}
static void F_284 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_2 V_5 ;
if ( F_209 ( V_2 ) )
return;
if ( F_275 ( V_2 ) )
V_5 = V_328 | V_327 | V_331 ;
else
V_5 = V_356 | V_355 ;
F_1 ( V_2 , V_374 ) ;
F_5 ( V_41 , ~ V_5 ) ;
if ( F_275 ( V_2 ) || F_204 ( V_2 ) ||
F_253 ( V_2 ) )
;
else
F_277 ( V_2 ) ;
}
static void F_285 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_2 V_492 , V_493 ;
V_492 = V_493 = 0 ;
V_2 -> V_14 = ~ 0 ;
if ( F_122 ( V_2 ) ) {
V_2 -> V_14 = ~ F_120 ( V_2 ) ;
V_493 |= F_120 ( V_2 ) ;
}
V_493 |= V_200 ;
if ( F_205 ( V_2 ) ) {
V_493 |= V_202 ;
} else {
V_493 |= V_205 | V_204 ;
}
F_258 ( V_447 , V_2 -> V_14 , V_493 ) ;
if ( F_60 ( V_2 ) >= 6 ) {
if ( F_166 ( V_2 ) ) {
V_492 |= V_275 ;
V_2 -> V_23 |= V_275 ;
}
V_2 -> V_20 = 0xffffffff ;
F_258 ( V_448 , V_2 -> V_20 , V_492 ) ;
}
}
static int F_286 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_2 V_494 , V_495 ;
if ( F_60 ( V_2 ) >= 7 ) {
V_494 = ( V_385 | V_380 |
V_381 | V_496 |
V_497 |
V_498 | V_379 ) ;
V_495 = ( V_499 | V_500 |
V_501 | V_378 |
V_376 ) ;
} else {
V_494 = ( V_385 | V_371 | V_373 |
V_502 | V_503 |
V_370 |
V_504 | V_505 |
V_372 ) ;
V_495 = ( V_506 | V_507 | V_375 |
V_508 | V_509 |
V_368 ) ;
}
V_2 -> V_12 = ~ V_494 ;
F_5 ( V_454 , 0xeffe ) ;
F_254 ( V_48 ) ;
F_258 ( V_455 , V_2 -> V_12 , V_494 | V_495 ) ;
F_285 ( V_48 ) ;
F_284 ( V_48 ) ;
if ( F_287 ( V_2 ) ) {
F_11 ( & V_2 -> V_7 ) ;
F_242 ( V_2 , V_375 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
return 0 ;
}
void F_288 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_287 )
return;
V_2 -> V_287 = true ;
if ( F_14 ( V_2 ) ) {
F_256 ( V_2 ) ;
F_257 ( V_2 ) ;
}
}
void F_289 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_7 ) ;
if ( ! V_2 -> V_287 )
return;
V_2 -> V_287 = false ;
if ( F_14 ( V_2 ) )
F_256 ( V_2 ) ;
}
static int F_290 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
F_285 ( V_48 ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_287 )
F_257 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
F_5 ( V_308 , V_313 ) ;
F_6 ( V_308 ) ;
return 0 ;
}
static void F_291 ( struct V_1 * V_2 )
{
T_3 V_510 [] = {
V_200 << V_223 |
V_211 << V_223 |
V_200 << V_224 |
V_211 << V_224 ,
V_200 << V_225 |
V_211 << V_225 |
V_200 << V_227 |
V_211 << V_227 ,
0 ,
V_200 << V_229 |
V_211 << V_229
} ;
if ( F_122 ( V_2 ) )
V_510 [ 0 ] |= V_197 ;
V_2 -> V_23 = 0x0 ;
V_2 -> V_20 = ~ V_2 -> V_23 ;
F_269 ( V_447 , 0 , ~ V_510 [ 0 ] , V_510 [ 0 ] ) ;
F_269 ( V_447 , 1 , ~ V_510 [ 1 ] , V_510 [ 1 ] ) ;
F_269 ( V_447 , 2 , V_2 -> V_20 , V_2 -> V_23 ) ;
F_269 ( V_447 , 3 , ~ V_510 [ 3 ] , V_510 [ 3 ] ) ;
}
static void F_292 ( struct V_1 * V_2 )
{
T_3 V_511 = V_409 ;
T_3 V_512 ;
T_2 V_513 = V_395 ;
T_2 V_514 ;
T_2 V_515 = V_390 ;
enum V_38 V_38 ;
if ( F_20 ( V_2 ) -> V_16 >= 9 ) {
V_511 |= V_407 |
V_411 ;
V_513 |= V_396 | V_397 |
V_398 ;
if ( F_213 ( V_2 ) )
V_513 |= V_403 ;
} else {
V_511 |= V_408 |
V_412 ;
}
V_512 = V_511 | V_406 |
V_410 ;
V_514 = V_513 ;
if ( F_213 ( V_2 ) )
V_514 |= V_399 ;
else if ( F_214 ( V_2 ) )
V_514 |= V_401 ;
V_2 -> V_39 [ V_60 ] = ~ V_511 ;
V_2 -> V_39 [ V_58 ] = ~ V_511 ;
V_2 -> V_39 [ V_291 ] = ~ V_511 ;
F_172 (dev_priv, pipe)
if ( F_265 ( V_2 ,
F_266 ( V_38 ) ) )
F_269 ( V_456 , V_38 ,
V_2 -> V_39 [ V_38 ] ,
V_512 ) ;
F_258 ( V_457 , ~ V_513 , V_514 ) ;
F_258 ( V_458 , ~ V_515 , V_515 ) ;
if ( F_213 ( V_2 ) )
F_282 ( V_2 ) ;
}
static int F_293 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
if ( F_217 ( V_2 ) )
F_254 ( V_48 ) ;
F_291 ( V_2 ) ;
F_292 ( V_2 ) ;
if ( F_217 ( V_2 ) )
F_284 ( V_48 ) ;
F_5 ( V_314 , V_315 ) ;
F_6 ( V_314 ) ;
return 0 ;
}
static int F_294 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
F_291 ( V_2 ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_287 )
F_257 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
F_5 ( V_314 , V_315 ) ;
F_6 ( V_314 ) ;
return 0 ;
}
static void F_295 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
if ( ! V_2 )
return;
F_264 ( V_48 ) ;
}
static void F_296 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
if ( ! V_2 )
return;
F_5 ( V_308 , 0 ) ;
F_6 ( V_308 ) ;
F_255 ( V_2 ) ;
F_5 ( V_454 , 0xffffffff ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_287 )
F_256 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
static void F_297 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
if ( ! V_2 )
return;
F_5 ( V_314 , 0 ) ;
F_6 ( V_314 ) ;
F_262 ( V_2 ) ;
F_252 ( V_459 ) ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_287 )
F_256 ( V_2 ) ;
F_12 ( & V_2 -> V_7 ) ;
}
static void F_298 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
if ( ! V_2 )
return;
F_259 ( V_48 ) ;
}
static void F_299 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
int V_38 ;
F_172 (dev_priv, pipe)
F_5 ( F_49 ( V_38 ) , 0 ) ;
F_89 ( V_516 , 0xffff ) ;
F_89 ( V_517 , 0x0 ) ;
F_300 ( V_517 ) ;
}
static int F_301 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
F_89 ( V_438 ,
~ ( V_518 | V_519 ) ) ;
V_2 -> V_12 =
~ ( V_289 |
V_290 |
V_520 |
V_521 ) ;
F_89 ( V_516 , V_2 -> V_12 ) ;
F_89 ( V_517 ,
V_289 |
V_290 |
V_522 ) ;
F_300 ( V_517 ) ;
F_11 ( & V_2 -> V_7 ) ;
F_54 ( V_2 , V_60 , V_295 ) ;
F_54 ( V_2 , V_58 , V_295 ) ;
F_12 ( & V_2 -> V_7 ) ;
return 0 ;
}
static bool F_302 ( struct V_1 * V_2 ,
int V_523 , int V_38 , T_2 V_195 )
{
T_11 V_524 = F_303 ( V_523 ) ;
if ( ! F_168 ( V_2 , V_38 ) )
return false ;
if ( ( V_195 & V_524 ) == 0 )
goto V_525;
if ( F_304 ( V_526 ) & V_524 )
goto V_525;
F_175 ( V_2 , V_38 ) ;
return true ;
V_525:
F_174 ( V_2 , V_38 ) ;
return false ;
}
static T_9 F_305 ( int V_32 , void * V_304 )
{
struct V_47 * V_48 = V_304 ;
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_11 V_195 , V_527 ;
T_2 V_285 [ 2 ] ;
int V_38 ;
T_11 V_528 =
V_520 |
V_521 ;
T_9 V_99 ;
if ( ! F_14 ( V_2 ) )
return V_214 ;
F_181 ( V_2 ) ;
V_99 = V_214 ;
V_195 = F_304 ( V_439 ) ;
if ( V_195 == 0 )
goto V_184;
while ( V_195 & ~ V_528 ) {
F_88 ( & V_2 -> V_7 ) ;
if ( V_195 & V_440 )
F_118 ( L_48 , V_195 ) ;
F_172 (dev_priv, pipe) {
T_1 V_3 = F_49 ( V_38 ) ;
V_285 [ V_38 ] = F_2 ( V_3 ) ;
if ( V_285 [ V_38 ] & 0x8000ffff )
F_5 ( V_3 , V_285 [ V_38 ] ) ;
}
F_91 ( & V_2 -> V_7 ) ;
F_89 ( V_439 , V_195 & ~ V_528 ) ;
V_527 = F_304 ( V_439 ) ;
if ( V_195 & V_522 )
F_92 ( V_2 -> V_132 [ V_201 ] ) ;
F_172 (dev_priv, pipe) {
int V_523 = V_38 ;
if ( F_306 ( V_2 ) )
V_523 = ! V_523 ;
if ( V_285 [ V_38 ] & V_444 &&
F_302 ( V_2 , V_523 , V_38 , V_195 ) )
V_528 &= ~ F_303 ( V_523 ) ;
if ( V_285 [ V_38 ] & V_295 )
F_159 ( V_2 , V_38 ) ;
if ( V_285 [ V_38 ] & V_51 )
F_176 ( V_2 ,
V_38 ) ;
}
V_195 = V_527 ;
}
V_99 = V_217 ;
V_184:
F_183 ( V_2 ) ;
return V_99 ;
}
static void F_307 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
int V_38 ;
F_172 (dev_priv, pipe) {
F_5 ( F_49 ( V_38 ) , 0 ) ;
F_5 ( F_49 ( V_38 ) , F_2 ( F_49 ( V_38 ) ) ) ;
}
F_89 ( V_516 , 0xffff ) ;
F_89 ( V_517 , 0x0 ) ;
F_89 ( V_439 , F_304 ( V_439 ) ) ;
}
static void F_308 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
int V_38 ;
if ( F_309 ( V_2 ) ) {
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_298 , F_2 ( V_298 ) ) ;
}
F_89 ( V_454 , 0xeffe ) ;
F_172 (dev_priv, pipe)
F_5 ( F_49 ( V_38 ) , 0 ) ;
F_5 ( V_516 , 0xffffffff ) ;
F_5 ( V_517 , 0x0 ) ;
F_6 ( V_517 ) ;
}
static int F_310 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_2 V_22 ;
F_5 ( V_438 , ~ ( V_518 | V_519 ) ) ;
V_2 -> V_12 =
~ ( V_529 |
V_289 |
V_290 |
V_520 |
V_521 ) ;
V_22 =
V_529 |
V_289 |
V_290 |
V_522 ;
if ( F_309 ( V_2 ) ) {
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_6 ( V_8 ) ;
V_22 |= V_310 ;
V_2 -> V_12 &= ~ V_310 ;
}
F_5 ( V_516 , V_2 -> V_12 ) ;
F_5 ( V_517 , V_22 ) ;
F_6 ( V_517 ) ;
F_58 ( V_2 ) ;
F_11 ( & V_2 -> V_7 ) ;
F_54 ( V_2 , V_60 , V_295 ) ;
F_54 ( V_2 , V_58 , V_295 ) ;
F_12 ( & V_2 -> V_7 ) ;
return 0 ;
}
static bool F_311 ( struct V_1 * V_2 ,
int V_523 , int V_38 , T_2 V_195 )
{
T_2 V_524 = F_303 ( V_523 ) ;
if ( ! F_168 ( V_2 , V_38 ) )
return false ;
if ( ( V_195 & V_524 ) == 0 )
goto V_525;
if ( F_2 ( V_526 ) & V_524 )
goto V_525;
F_175 ( V_2 , V_38 ) ;
return true ;
V_525:
F_174 ( V_2 , V_38 ) ;
return false ;
}
static T_9 F_312 ( int V_32 , void * V_304 )
{
struct V_47 * V_48 = V_304 ;
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_2 V_195 , V_527 , V_285 [ V_286 ] ;
T_2 V_528 =
V_520 |
V_521 ;
int V_38 , V_99 = V_214 ;
if ( ! F_14 ( V_2 ) )
return V_214 ;
F_181 ( V_2 ) ;
V_195 = F_2 ( V_439 ) ;
do {
bool V_530 = ( V_195 & ~ V_528 ) != 0 ;
bool V_531 = false ;
F_88 ( & V_2 -> V_7 ) ;
if ( V_195 & V_440 )
F_118 ( L_48 , V_195 ) ;
F_172 (dev_priv, pipe) {
T_1 V_3 = F_49 ( V_38 ) ;
V_285 [ V_38 ] = F_2 ( V_3 ) ;
if ( V_285 [ V_38 ] & 0x8000ffff ) {
F_5 ( V_3 , V_285 [ V_38 ] ) ;
V_530 = true ;
}
}
F_91 ( & V_2 -> V_7 ) ;
if ( ! V_530 )
break;
if ( F_309 ( V_2 ) &&
V_195 & V_310 ) {
T_2 V_297 = F_177 ( V_2 ) ;
if ( V_297 )
F_178 ( V_2 , V_297 ) ;
}
F_5 ( V_439 , V_195 & ~ V_528 ) ;
V_527 = F_2 ( V_439 ) ;
if ( V_195 & V_522 )
F_92 ( V_2 -> V_132 [ V_201 ] ) ;
F_172 (dev_priv, pipe) {
int V_523 = V_38 ;
if ( F_306 ( V_2 ) )
V_523 = ! V_523 ;
if ( V_285 [ V_38 ] & V_444 &&
F_311 ( V_2 , V_523 , V_38 , V_195 ) )
V_528 &= ~ F_303 ( V_523 ) ;
if ( V_285 [ V_38 ] & V_59 )
V_531 = true ;
if ( V_285 [ V_38 ] & V_295 )
F_159 ( V_2 , V_38 ) ;
if ( V_285 [ V_38 ] & V_51 )
F_176 ( V_2 ,
V_38 ) ;
}
if ( V_531 || ( V_195 & V_529 ) )
F_199 ( V_2 ) ;
V_99 = V_217 ;
V_195 = V_527 ;
} while ( V_195 & ~ V_528 );
F_183 ( V_2 ) ;
return V_99 ;
}
static void F_313 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
int V_38 ;
if ( F_309 ( V_2 ) ) {
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_298 , F_2 ( V_298 ) ) ;
}
F_89 ( V_454 , 0xffff ) ;
F_172 (dev_priv, pipe) {
F_5 ( F_49 ( V_38 ) , 0 ) ;
F_5 ( F_49 ( V_38 ) , F_2 ( F_49 ( V_38 ) ) ) ;
}
F_5 ( V_516 , 0xffffffff ) ;
F_5 ( V_517 , 0x0 ) ;
F_5 ( V_439 , F_2 ( V_439 ) ) ;
}
static void F_314 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
int V_38 ;
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_298 , F_2 ( V_298 ) ) ;
F_5 ( V_454 , 0xeffe ) ;
F_172 (dev_priv, pipe)
F_5 ( F_49 ( V_38 ) , 0 ) ;
F_5 ( V_516 , 0xffffffff ) ;
F_5 ( V_517 , 0x0 ) ;
F_6 ( V_517 ) ;
}
static int F_315 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_2 V_22 ;
T_2 V_532 ;
V_2 -> V_12 = ~ ( V_529 |
V_310 |
V_289 |
V_290 |
V_520 |
V_521 |
V_440 ) ;
V_22 = ~ V_2 -> V_12 ;
V_22 &= ~ ( V_520 |
V_521 ) ;
V_22 |= V_522 ;
if ( F_80 ( V_2 ) )
V_22 |= V_533 ;
F_11 ( & V_2 -> V_7 ) ;
F_54 ( V_2 , V_60 , V_296 ) ;
F_54 ( V_2 , V_60 , V_295 ) ;
F_54 ( V_2 , V_58 , V_295 ) ;
F_12 ( & V_2 -> V_7 ) ;
if ( F_80 ( V_2 ) ) {
V_532 = ~ ( V_534 |
V_535 |
V_536 |
V_519 ) ;
} else {
V_532 = ~ ( V_518 |
V_519 ) ;
}
F_5 ( V_438 , V_532 ) ;
F_5 ( V_516 , V_2 -> V_12 ) ;
F_5 ( V_517 , V_22 ) ;
F_6 ( V_517 ) ;
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_6 ( V_8 ) ;
F_58 ( V_2 ) ;
return 0 ;
}
static void F_316 ( struct V_1 * V_2 )
{
T_2 V_537 ;
F_8 ( & V_2 -> V_7 ) ;
V_537 = F_272 ( V_2 , V_538 ) ;
if ( F_80 ( V_2 ) )
V_537 |= V_539 ;
V_537 |= V_540 ;
F_7 ( V_2 ,
V_541 |
V_542 |
V_539 ,
V_537 ) ;
}
static T_9 F_317 ( int V_32 , void * V_304 )
{
struct V_47 * V_48 = V_304 ;
struct V_1 * V_2 = F_62 ( V_48 ) ;
T_2 V_195 , V_527 ;
T_2 V_285 [ V_286 ] ;
int V_99 = V_214 , V_38 ;
T_2 V_528 =
V_520 |
V_521 ;
if ( ! F_14 ( V_2 ) )
return V_214 ;
F_181 ( V_2 ) ;
V_195 = F_2 ( V_439 ) ;
for (; ; ) {
bool V_530 = ( V_195 & ~ V_528 ) != 0 ;
bool V_531 = false ;
F_88 ( & V_2 -> V_7 ) ;
if ( V_195 & V_440 )
F_118 ( L_48 , V_195 ) ;
F_172 (dev_priv, pipe) {
T_1 V_3 = F_49 ( V_38 ) ;
V_285 [ V_38 ] = F_2 ( V_3 ) ;
if ( V_285 [ V_38 ] & 0x8000ffff ) {
F_5 ( V_3 , V_285 [ V_38 ] ) ;
V_530 = true ;
}
}
F_91 ( & V_2 -> V_7 ) ;
if ( ! V_530 )
break;
V_99 = V_217 ;
if ( V_195 & V_310 ) {
T_2 V_297 = F_177 ( V_2 ) ;
if ( V_297 )
F_178 ( V_2 , V_297 ) ;
}
F_5 ( V_439 , V_195 & ~ V_528 ) ;
V_527 = F_2 ( V_439 ) ;
if ( V_195 & V_522 )
F_92 ( V_2 -> V_132 [ V_201 ] ) ;
if ( V_195 & V_533 )
F_92 ( V_2 -> V_132 [ V_203 ] ) ;
F_172 (dev_priv, pipe) {
if ( V_285 [ V_38 ] & V_293 &&
F_311 ( V_2 , V_38 , V_38 , V_195 ) )
V_528 &= ~ F_303 ( V_38 ) ;
if ( V_285 [ V_38 ] & V_59 )
V_531 = true ;
if ( V_285 [ V_38 ] & V_295 )
F_159 ( V_2 , V_38 ) ;
if ( V_285 [ V_38 ] & V_51 )
F_176 ( V_2 , V_38 ) ;
}
if ( V_531 || ( V_195 & V_529 ) )
F_199 ( V_2 ) ;
if ( V_285 [ 0 ] & V_296 )
F_144 ( V_2 ) ;
V_195 = V_527 ;
}
F_183 ( V_2 ) ;
return V_99 ;
}
static void F_318 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_62 ( V_48 ) ;
int V_38 ;
if ( ! V_2 )
return;
F_10 ( V_2 , 0xffffffff , 0 ) ;
F_5 ( V_298 , F_2 ( V_298 ) ) ;
F_5 ( V_454 , 0xffffffff ) ;
F_172 (dev_priv, pipe)
F_5 ( F_49 ( V_38 ) , 0 ) ;
F_5 ( V_516 , 0xffffffff ) ;
F_5 ( V_517 , 0x0 ) ;
F_172 (dev_priv, pipe)
F_5 ( F_49 ( V_38 ) ,
F_2 ( F_49 ( V_38 ) ) & 0x8000ffff ) ;
F_5 ( V_439 , F_2 ( V_439 ) ) ;
}
void F_319 ( struct V_1 * V_2 )
{
struct V_47 * V_48 = & V_2 -> V_31 ;
F_320 ( V_2 ) ;
F_321 ( & V_2 -> V_26 . V_33 , F_103 ) ;
F_321 ( & V_2 -> V_173 . V_174 , F_109 ) ;
if ( F_322 ( V_2 ) )
V_2 -> V_34 = V_277 ;
if ( F_55 ( V_2 ) )
V_2 -> V_25 = V_146 ;
else
V_2 -> V_25 = V_543 ;
V_2 -> V_26 . V_29 = 0 ;
if ( F_20 ( V_2 ) -> V_16 <= 7 && ! F_323 ( V_2 ) )
V_2 -> V_26 . V_29 |= V_146 ;
if ( F_20 ( V_2 ) -> V_16 >= 8 )
V_2 -> V_26 . V_29 |= V_544 ;
if ( F_70 ( V_2 ) ) {
V_48 -> V_545 = 0 ;
V_48 -> V_262 -> V_270 = V_546 ;
} else if ( F_80 ( V_2 ) || F_20 ( V_2 ) -> V_16 >= 5 ) {
V_48 -> V_545 = 0xffffffff ;
V_48 -> V_262 -> V_270 = F_67 ;
} else {
V_48 -> V_262 -> V_270 = F_61 ;
V_48 -> V_545 = 0xffffff ;
}
if ( ! F_70 ( V_2 ) )
V_48 -> V_547 = true ;
V_2 -> V_287 = true ;
if ( F_55 ( V_2 ) || F_56 ( V_2 ) )
V_2 -> V_287 = false ;
V_48 -> V_262 -> V_548 = F_83 ;
V_48 -> V_262 -> V_549 = F_76 ;
if ( F_56 ( V_2 ) ) {
V_48 -> V_262 -> V_550 = F_184 ;
V_48 -> V_262 -> V_551 = F_271 ;
V_48 -> V_262 -> V_552 = F_294 ;
V_48 -> V_262 -> V_553 = F_297 ;
V_48 -> V_262 -> V_554 = F_240 ;
V_48 -> V_262 -> V_555 = F_246 ;
V_2 -> V_556 . V_557 = F_316 ;
} else if ( F_55 ( V_2 ) ) {
V_48 -> V_262 -> V_550 = F_180 ;
V_48 -> V_262 -> V_551 = F_261 ;
V_48 -> V_262 -> V_552 = F_290 ;
V_48 -> V_262 -> V_553 = F_296 ;
V_48 -> V_262 -> V_554 = F_240 ;
V_48 -> V_262 -> V_555 = F_246 ;
V_2 -> V_556 . V_557 = F_316 ;
} else if ( F_20 ( V_2 ) -> V_16 >= 8 ) {
V_48 -> V_262 -> V_550 = F_220 ;
V_48 -> V_262 -> V_551 = F_264 ;
V_48 -> V_262 -> V_552 = F_293 ;
V_48 -> V_262 -> V_553 = F_295 ;
V_48 -> V_262 -> V_554 = F_243 ;
V_48 -> V_262 -> V_555 = F_249 ;
if ( F_213 ( V_2 ) )
V_2 -> V_556 . V_557 = F_283 ;
else if ( F_218 ( V_2 ) || F_219 ( V_2 ) )
V_2 -> V_556 . V_557 = F_278 ;
else
V_2 -> V_556 . V_557 = F_279 ;
} else if ( F_217 ( V_2 ) ) {
V_48 -> V_262 -> V_550 = F_210 ;
V_48 -> V_262 -> V_551 = F_259 ;
V_48 -> V_262 -> V_552 = F_286 ;
V_48 -> V_262 -> V_553 = F_298 ;
V_48 -> V_262 -> V_554 = F_241 ;
V_48 -> V_262 -> V_555 = F_247 ;
V_2 -> V_556 . V_557 = F_279 ;
} else {
if ( F_70 ( V_2 ) ) {
V_48 -> V_262 -> V_551 = F_299 ;
V_48 -> V_262 -> V_552 = F_301 ;
V_48 -> V_262 -> V_550 = F_305 ;
V_48 -> V_262 -> V_553 = F_307 ;
V_48 -> V_262 -> V_554 = F_239 ;
V_48 -> V_262 -> V_555 = F_245 ;
} else if ( F_324 ( V_2 ) ) {
V_48 -> V_262 -> V_551 = F_308 ;
V_48 -> V_262 -> V_552 = F_310 ;
V_48 -> V_262 -> V_553 = F_313 ;
V_48 -> V_262 -> V_550 = F_312 ;
V_48 -> V_262 -> V_554 = F_239 ;
V_48 -> V_262 -> V_555 = F_245 ;
} else {
V_48 -> V_262 -> V_551 = F_314 ;
V_48 -> V_262 -> V_552 = F_315 ;
V_48 -> V_262 -> V_553 = F_318 ;
V_48 -> V_262 -> V_550 = F_317 ;
V_48 -> V_262 -> V_554 = F_240 ;
V_48 -> V_262 -> V_555 = F_246 ;
}
if ( F_309 ( V_2 ) )
V_2 -> V_556 . V_557 = F_316 ;
}
}
int F_325 ( struct V_1 * V_2 )
{
V_2 -> V_558 . V_559 = true ;
return F_326 ( & V_2 -> V_31 , V_2 -> V_31 . V_560 -> V_32 ) ;
}
void F_327 ( struct V_1 * V_2 )
{
F_328 ( & V_2 -> V_31 ) ;
F_329 ( V_2 ) ;
V_2 -> V_558 . V_559 = false ;
}
void F_330 ( struct V_1 * V_2 )
{
V_2 -> V_31 . V_262 -> V_553 ( & V_2 -> V_31 ) ;
V_2 -> V_558 . V_559 = false ;
F_39 ( V_2 -> V_31 . V_32 ) ;
}
void F_331 ( struct V_1 * V_2 )
{
V_2 -> V_558 . V_559 = true ;
V_2 -> V_31 . V_262 -> V_551 ( & V_2 -> V_31 ) ;
V_2 -> V_31 . V_262 -> V_552 ( & V_2 -> V_31 ) ;
}
