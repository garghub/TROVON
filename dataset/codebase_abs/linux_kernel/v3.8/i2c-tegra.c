static void F_1 ( struct V_1 * V_2 , T_1 V_3 , unsigned long V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , unsigned long V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static unsigned long F_5 ( struct V_1 * V_2 ,
unsigned long V_4 )
{
if ( V_2 -> V_6 )
V_4 += ( V_4 >= V_7 ) ? 0x10 : 0x40 ;
return V_4 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned long V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + F_5 ( V_2 , V_4 ) ) ;
if ( V_4 != V_7 )
F_4 ( V_2 -> V_5 + F_5 ( V_2 , V_4 ) ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , unsigned long V_4 )
{
return F_4 ( V_2 -> V_5 + F_5 ( V_2 , V_4 ) ) ;
}
static void F_8 ( struct V_1 * V_2 , void * V_8 ,
unsigned long V_4 , int V_9 )
{
F_9 ( V_2 -> V_5 + F_5 ( V_2 , V_4 ) , V_8 , V_9 ) ;
}
static void F_10 ( struct V_1 * V_2 , void * V_8 ,
unsigned long V_4 , int V_9 )
{
F_11 ( V_2 -> V_5 + F_5 ( V_2 , V_4 ) , V_8 , V_9 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_10 )
{
T_1 V_11 = F_7 ( V_2 , V_12 ) ;
V_11 &= ~ V_10 ;
F_6 ( V_2 , V_11 , V_12 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_10 )
{
T_1 V_11 = F_7 ( V_2 , V_12 ) ;
V_11 |= V_10 ;
F_6 ( V_2 , V_11 , V_12 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
unsigned long V_13 = V_14 + V_15 ;
T_1 V_3 = F_7 ( V_2 , V_16 ) ;
V_3 |= V_17 | V_18 ;
F_6 ( V_2 , V_3 , V_16 ) ;
while ( F_7 ( V_2 , V_16 ) &
( V_17 | V_18 ) ) {
if ( F_15 ( V_14 , V_13 ) ) {
F_16 ( V_2 -> V_19 , L_1 ) ;
return - V_20 ;
}
F_17 ( 1 ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_21 ;
T_2 * V_22 = V_2 -> V_23 ;
T_3 V_24 = V_2 -> V_25 ;
int V_26 ;
V_3 = F_7 ( V_2 , V_27 ) ;
V_21 = ( V_3 & V_28 ) >>
V_29 ;
V_26 = V_24 / V_30 ;
if ( V_26 > V_21 )
V_26 = V_21 ;
F_10 ( V_2 , V_22 , V_31 , V_26 ) ;
V_22 += V_26 * V_30 ;
V_24 -= V_26 * V_30 ;
V_21 -= V_26 ;
if ( V_21 > 0 && V_24 > 0 ) {
F_19 ( V_24 > 3 ) ;
V_3 = F_7 ( V_2 , V_31 ) ;
memcpy ( V_22 , & V_3 , V_24 ) ;
V_24 = 0 ;
V_21 -- ;
}
F_19 ( V_21 > 0 && V_24 > 0 ) ;
V_2 -> V_25 = V_24 ;
V_2 -> V_23 = V_22 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_32 ;
T_2 * V_22 = V_2 -> V_23 ;
T_3 V_24 = V_2 -> V_25 ;
int V_26 ;
V_3 = F_7 ( V_2 , V_27 ) ;
V_32 = ( V_3 & V_33 ) >>
V_34 ;
V_26 = V_24 / V_30 ;
if ( V_26 ) {
if ( V_26 > V_32 )
V_26 = V_32 ;
V_24 -= V_26 * V_30 ;
V_32 -= V_26 ;
V_2 -> V_25 = V_24 ;
V_2 -> V_23 = V_22 +
V_26 * V_30 ;
F_21 () ;
F_8 ( V_2 , V_22 , V_7 , V_26 ) ;
V_22 += V_26 * V_30 ;
}
if ( V_32 > 0 && V_24 > 0 ) {
F_19 ( V_24 > 3 ) ;
memcpy ( & V_3 , V_22 , V_24 ) ;
V_2 -> V_25 = 0 ;
V_2 -> V_23 = NULL ;
F_21 () ;
F_6 ( V_2 , V_3 , V_7 ) ;
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
V_3 = F_3 ( V_2 , V_35 ) ;
V_3 |= V_36 ;
V_3 |= V_37 ;
F_1 ( V_2 , V_3 , V_35 ) ;
V_3 = F_3 ( V_2 , V_38 ) ;
V_3 |= V_39 ;
F_1 ( V_2 , V_3 , V_38 ) ;
}
static inline int F_23 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = F_24 ( V_2 -> V_41 ) ;
if ( V_40 < 0 ) {
F_25 ( V_2 -> V_19 ,
L_2 , V_40 ) ;
return V_40 ;
}
V_40 = F_24 ( V_2 -> V_42 ) ;
if ( V_40 < 0 ) {
F_25 ( V_2 -> V_19 ,
L_3 , V_40 ) ;
F_26 ( V_2 -> V_41 ) ;
}
return V_40 ;
}
static inline void F_27 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_42 ) ;
F_26 ( V_2 -> V_41 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_43 = 0 ;
F_23 ( V_2 ) ;
F_29 ( V_2 -> V_42 ) ;
F_30 ( 2 ) ;
F_31 ( V_2 -> V_42 ) ;
if ( V_2 -> V_6 )
F_22 ( V_2 ) ;
V_3 = V_44 | V_45 |
( 0x2 << V_46 ) ;
F_6 ( V_2 , V_3 , V_47 ) ;
F_6 ( V_2 , 0 , V_12 ) ;
F_32 ( V_2 -> V_42 , V_2 -> V_48 * 8 ) ;
if ( ! V_2 -> V_6 ) {
T_1 V_49 = F_7 ( V_2 , V_50 ) ;
V_49 |= V_51 | V_52 ;
F_6 ( V_2 , V_49 , V_50 ) ;
F_6 ( V_2 , 0xfc , V_53 ) ;
F_6 ( V_2 , 0x00 , V_54 ) ;
}
V_3 = 7 << V_55 |
0 << V_56 ;
F_6 ( V_2 , V_3 , V_16 ) ;
if ( F_14 ( V_2 ) )
V_43 = - V_20 ;
F_27 ( V_2 ) ;
if ( V_2 -> V_57 ) {
V_2 -> V_57 = 0 ;
F_33 ( V_2 -> V_58 ) ;
}
return V_43 ;
}
static T_4 F_34 ( int V_58 , void * V_59 )
{
T_1 V_60 ;
const T_1 V_61 = V_62 | V_63 ;
struct V_1 * V_2 = V_59 ;
V_60 = F_7 ( V_2 , V_64 ) ;
if ( V_60 == 0 ) {
F_16 ( V_2 -> V_19 , L_4 ,
F_7 ( V_2 , V_65 ) ,
F_7 ( V_2 , V_66 ) ,
F_7 ( V_2 , V_47 ) ) ;
V_2 -> V_67 |= V_68 ;
if ( ! V_2 -> V_57 ) {
F_35 ( V_2 -> V_58 ) ;
V_2 -> V_57 = 1 ;
}
goto V_43;
}
if ( F_36 ( V_60 & V_61 ) ) {
if ( V_60 & V_62 )
V_2 -> V_67 |= V_69 ;
if ( V_60 & V_63 )
V_2 -> V_67 |= V_70 ;
goto V_43;
}
if ( V_2 -> V_71 && ( V_60 & V_72 ) ) {
if ( V_2 -> V_25 )
F_18 ( V_2 ) ;
else
F_37 () ;
}
if ( ! V_2 -> V_71 && ( V_60 & V_73 ) ) {
if ( V_2 -> V_25 )
F_20 ( V_2 ) ;
else
F_12 ( V_2 , V_73 ) ;
}
F_6 ( V_2 , V_60 , V_64 ) ;
if ( V_2 -> V_6 )
F_1 ( V_2 , V_74 , V_75 ) ;
if ( V_60 & V_76 ) {
F_19 ( V_2 -> V_25 ) ;
F_38 ( & V_2 -> V_77 ) ;
}
return V_78 ;
V_43:
F_12 ( V_2 , V_62 | V_63 |
V_76 | V_73 |
V_72 ) ;
F_6 ( V_2 , V_60 , V_64 ) ;
if ( V_2 -> V_6 )
F_1 ( V_2 , V_74 , V_75 ) ;
F_38 ( & V_2 -> V_77 ) ;
return V_78 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_79 * V_80 , enum V_81 V_82 )
{
T_1 V_83 ;
T_1 V_11 ;
int V_40 ;
F_14 ( V_2 ) ;
if ( V_80 -> V_9 == 0 )
return - V_84 ;
V_2 -> V_23 = V_80 -> V_22 ;
V_2 -> V_25 = V_80 -> V_9 ;
V_2 -> V_67 = V_85 ;
V_2 -> V_71 = ( V_80 -> V_86 & V_87 ) ;
F_40 ( V_2 -> V_77 ) ;
V_83 = ( 0 << V_88 ) |
V_89 |
( V_2 -> V_90 << V_91 ) |
( 1 << V_92 ) ;
F_6 ( V_2 , V_83 , V_7 ) ;
V_83 = V_80 -> V_9 - 1 ;
F_6 ( V_2 , V_83 , V_7 ) ;
V_83 = V_93 ;
if ( V_82 == V_94 )
V_83 |= V_95 ;
else if ( V_82 == V_96 )
V_83 |= V_97 ;
if ( V_80 -> V_86 & V_98 ) {
V_83 |= V_80 -> V_99 ;
V_83 |= V_100 ;
} else {
V_83 |= V_80 -> V_99 << V_101 ;
}
if ( V_80 -> V_86 & V_102 )
V_83 |= V_103 ;
if ( V_80 -> V_86 & V_87 )
V_83 |= V_104 ;
F_6 ( V_2 , V_83 , V_7 ) ;
if ( ! ( V_80 -> V_86 & V_87 ) )
F_20 ( V_2 ) ;
V_11 = V_62 | V_63 ;
if ( V_80 -> V_86 & V_87 )
V_11 |= V_72 ;
else if ( V_2 -> V_25 )
V_11 |= V_73 ;
F_13 ( V_2 , V_11 ) ;
F_41 ( V_2 -> V_19 , L_5 ,
F_7 ( V_2 , V_12 ) ) ;
V_40 = F_42 ( & V_2 -> V_77 , V_105 ) ;
F_12 ( V_2 , V_11 ) ;
if ( F_43 ( V_40 == 0 ) ) {
F_25 ( V_2 -> V_19 , L_6 ) ;
F_28 ( V_2 ) ;
return - V_20 ;
}
F_41 ( V_2 -> V_19 , L_7 ,
V_40 , F_44 ( & V_2 -> V_77 ) , V_2 -> V_67 ) ;
if ( F_45 ( V_2 -> V_67 == V_85 ) )
return 0 ;
if ( V_2 -> V_67 == V_69 )
F_30 ( F_46 ( 2 * 1000000 , V_2 -> V_48 ) ) ;
F_28 ( V_2 ) ;
if ( V_2 -> V_67 == V_69 ) {
if ( V_80 -> V_86 & V_102 )
return 0 ;
return - V_106 ;
}
return - V_107 ;
}
static int F_47 ( struct V_108 * V_109 , struct V_79 V_110 [] ,
int V_111 )
{
struct V_1 * V_2 = F_48 ( V_109 ) ;
int V_112 ;
int V_40 = 0 ;
if ( V_2 -> V_113 )
return - V_114 ;
F_23 ( V_2 ) ;
for ( V_112 = 0 ; V_112 < V_111 ; V_112 ++ ) {
enum V_81 V_115 = V_116 ;
if ( V_112 < ( V_111 - 1 ) ) {
if ( V_110 [ V_112 + 1 ] . V_86 & V_117 )
V_115 = V_94 ;
else
V_115 = V_96 ;
}
V_40 = F_39 ( V_2 , & V_110 [ V_112 ] , V_115 ) ;
if ( V_40 )
break;
}
F_27 ( V_2 ) ;
return V_40 ? : V_112 ;
}
static T_1 F_49 ( struct V_108 * V_109 )
{
struct V_1 * V_2 = F_48 ( V_109 ) ;
T_1 V_40 = V_118 | V_119 | V_120 |
V_121 ;
if ( V_2 -> V_122 -> V_123 )
V_40 |= V_124 ;
return V_40 ;
}
static int F_50 ( struct V_125 * V_126 )
{
struct V_1 * V_2 ;
struct V_127 * V_128 = V_126 -> V_19 . V_129 ;
struct V_130 * V_131 ;
struct V_132 * V_42 ;
struct V_132 * V_41 ;
const unsigned int * V_133 ;
void T_5 * V_5 ;
int V_58 ;
int V_40 = 0 ;
V_131 = F_51 ( V_126 , V_134 , 0 ) ;
if ( ! V_131 ) {
F_25 ( & V_126 -> V_19 , L_8 ) ;
return - V_84 ;
}
V_5 = F_52 ( & V_126 -> V_19 , V_131 ) ;
if ( ! V_5 ) {
F_25 ( & V_126 -> V_19 , L_9 ) ;
return - V_135 ;
}
V_131 = F_51 ( V_126 , V_136 , 0 ) ;
if ( ! V_131 ) {
F_25 ( & V_126 -> V_19 , L_10 ) ;
return - V_84 ;
}
V_58 = V_131 -> V_137 ;
V_42 = F_53 ( & V_126 -> V_19 , L_11 ) ;
if ( F_54 ( V_42 ) ) {
F_25 ( & V_126 -> V_19 , L_12 ) ;
return F_55 ( V_42 ) ;
}
V_41 = F_53 ( & V_126 -> V_19 , L_13 ) ;
if ( F_54 ( V_41 ) ) {
F_25 ( & V_126 -> V_19 , L_14 ) ;
return F_55 ( V_41 ) ;
}
V_2 = F_56 ( & V_126 -> V_19 , sizeof( * V_2 ) , V_138 ) ;
if ( ! V_2 ) {
F_25 ( & V_126 -> V_19 , L_15 ) ;
return - V_139 ;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_42 = V_42 ;
V_2 -> V_41 = V_41 ;
V_2 -> V_140 . V_141 = & V_142 ;
V_2 -> V_58 = V_58 ;
V_2 -> V_90 = V_126 -> V_143 ;
V_2 -> V_19 = & V_126 -> V_19 ;
V_2 -> V_48 = 100000 ;
if ( V_128 ) {
V_2 -> V_48 = V_128 -> V_48 ;
} else if ( V_2 -> V_19 -> V_144 ) {
V_133 = F_57 ( V_2 -> V_19 -> V_144 ,
L_16 , NULL ) ;
if ( V_133 )
V_2 -> V_48 = F_58 ( V_133 ) ;
}
V_2 -> V_122 = & V_145 ;
if ( V_126 -> V_19 . V_144 ) {
const struct V_146 * V_147 ;
V_147 = F_59 ( F_60 ( V_148 ) ,
& V_126 -> V_19 ) ;
V_2 -> V_122 = V_147 -> V_8 ;
V_2 -> V_6 = F_61 ( V_126 -> V_19 . V_144 ,
L_17 ) ;
} else if ( V_126 -> V_143 == 3 ) {
V_2 -> V_6 = 1 ;
}
F_62 ( & V_2 -> V_77 ) ;
F_63 ( V_126 , V_2 ) ;
V_40 = F_28 ( V_2 ) ;
if ( V_40 ) {
F_25 ( & V_126 -> V_19 , L_18 ) ;
return V_40 ;
}
V_40 = F_64 ( & V_126 -> V_19 , V_2 -> V_58 ,
F_34 , 0 , F_65 ( & V_126 -> V_19 ) , V_2 ) ;
if ( V_40 ) {
F_25 ( & V_126 -> V_19 , L_19 , V_2 -> V_58 ) ;
return V_40 ;
}
F_66 ( & V_2 -> V_140 , V_2 ) ;
V_2 -> V_140 . V_149 = V_150 ;
V_2 -> V_140 . V_151 = V_152 ;
F_67 ( V_2 -> V_140 . V_153 , L_20 ,
sizeof( V_2 -> V_140 . V_153 ) ) ;
V_2 -> V_140 . V_141 = & V_142 ;
V_2 -> V_140 . V_19 . V_154 = & V_126 -> V_19 ;
V_2 -> V_140 . V_155 = V_126 -> V_143 ;
V_2 -> V_140 . V_19 . V_144 = V_126 -> V_19 . V_144 ;
V_40 = F_68 ( & V_2 -> V_140 ) ;
if ( V_40 ) {
F_25 ( & V_126 -> V_19 , L_21 ) ;
return V_40 ;
}
F_69 ( & V_2 -> V_140 ) ;
return 0 ;
}
static int F_70 ( struct V_125 * V_126 )
{
struct V_1 * V_2 = F_71 ( V_126 ) ;
F_72 ( & V_2 -> V_140 ) ;
return 0 ;
}
static int F_73 ( struct V_156 * V_19 )
{
struct V_1 * V_2 = F_74 ( V_19 ) ;
F_75 ( & V_2 -> V_140 ) ;
V_2 -> V_113 = true ;
F_76 ( & V_2 -> V_140 ) ;
return 0 ;
}
static int F_77 ( struct V_156 * V_19 )
{
struct V_1 * V_2 = F_74 ( V_19 ) ;
int V_40 ;
F_75 ( & V_2 -> V_140 ) ;
V_40 = F_28 ( V_2 ) ;
if ( V_40 ) {
F_76 ( & V_2 -> V_140 ) ;
return V_40 ;
}
V_2 -> V_113 = false ;
F_76 ( & V_2 -> V_140 ) ;
return 0 ;
}
static int T_6 F_78 ( void )
{
return F_79 ( & V_157 ) ;
}
static void T_7 F_80 ( void )
{
F_81 ( & V_157 ) ;
}
