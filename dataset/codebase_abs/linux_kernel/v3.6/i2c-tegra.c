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
static int F_23 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_40 = 0 ;
F_24 ( V_2 -> V_41 ) ;
F_25 ( V_2 -> V_41 ) ;
F_26 ( 2 ) ;
F_27 ( V_2 -> V_41 ) ;
if ( V_2 -> V_6 )
F_22 ( V_2 ) ;
V_3 = V_42 | V_43 |
( 0x2 << V_44 ) ;
F_6 ( V_2 , V_3 , V_45 ) ;
F_6 ( V_2 , 0 , V_12 ) ;
F_28 ( V_2 -> V_41 , V_2 -> V_46 * 8 ) ;
if ( ! V_2 -> V_6 ) {
T_1 V_47 = F_7 ( V_2 , V_48 ) ;
V_47 |= V_49 | V_50 ;
F_6 ( V_2 , V_47 , V_48 ) ;
F_6 ( V_2 , 0xfc , V_51 ) ;
F_6 ( V_2 , 0x00 , V_52 ) ;
}
V_3 = 7 << V_53 |
0 << V_54 ;
F_6 ( V_2 , V_3 , V_16 ) ;
if ( F_14 ( V_2 ) )
V_40 = - V_20 ;
F_29 ( V_2 -> V_41 ) ;
if ( V_2 -> V_55 ) {
V_2 -> V_55 = 0 ;
F_30 ( V_2 -> V_56 ) ;
}
return V_40 ;
}
static T_4 F_31 ( int V_56 , void * V_57 )
{
T_1 V_58 ;
const T_1 V_59 = V_60 | V_61 ;
struct V_1 * V_2 = V_57 ;
V_58 = F_7 ( V_2 , V_62 ) ;
if ( V_58 == 0 ) {
F_16 ( V_2 -> V_19 , L_2 ,
F_7 ( V_2 , V_63 ) ,
F_7 ( V_2 , V_64 ) ,
F_7 ( V_2 , V_45 ) ) ;
V_2 -> V_65 |= V_66 ;
if ( ! V_2 -> V_55 ) {
F_32 ( V_2 -> V_56 ) ;
V_2 -> V_55 = 1 ;
}
goto V_40;
}
if ( F_33 ( V_58 & V_59 ) ) {
if ( V_58 & V_60 )
V_2 -> V_65 |= V_67 ;
if ( V_58 & V_61 )
V_2 -> V_65 |= V_68 ;
goto V_40;
}
if ( V_2 -> V_69 && ( V_58 & V_70 ) ) {
if ( V_2 -> V_25 )
F_18 ( V_2 ) ;
else
F_34 () ;
}
if ( ! V_2 -> V_69 && ( V_58 & V_71 ) ) {
if ( V_2 -> V_25 )
F_20 ( V_2 ) ;
else
F_12 ( V_2 , V_71 ) ;
}
F_6 ( V_2 , V_58 , V_62 ) ;
if ( V_2 -> V_6 )
F_1 ( V_2 , V_72 , V_73 ) ;
if ( V_58 & V_74 ) {
F_19 ( V_2 -> V_25 ) ;
F_35 ( & V_2 -> V_75 ) ;
}
return V_76 ;
V_40:
F_12 ( V_2 , V_60 | V_61 |
V_74 | V_71 |
V_70 ) ;
F_6 ( V_2 , V_58 , V_62 ) ;
if ( V_2 -> V_6 )
F_1 ( V_2 , V_72 , V_73 ) ;
F_35 ( & V_2 -> V_75 ) ;
return V_76 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_77 * V_78 , enum V_79 V_80 )
{
T_1 V_81 ;
T_1 V_11 ;
int V_82 ;
F_14 ( V_2 ) ;
if ( V_78 -> V_9 == 0 )
return - V_83 ;
V_2 -> V_23 = V_78 -> V_22 ;
V_2 -> V_25 = V_78 -> V_9 ;
V_2 -> V_65 = V_84 ;
V_2 -> V_69 = ( V_78 -> V_85 & V_86 ) ;
F_37 ( V_2 -> V_75 ) ;
V_81 = ( 0 << V_87 ) |
V_88 |
( V_2 -> V_89 << V_90 ) |
( 1 << V_91 ) ;
F_6 ( V_2 , V_81 , V_7 ) ;
V_81 = V_78 -> V_9 - 1 ;
F_6 ( V_2 , V_81 , V_7 ) ;
V_81 = V_92 ;
if ( V_80 == V_93 )
V_81 |= V_94 ;
else if ( V_80 == V_95 )
V_81 |= V_96 ;
if ( V_78 -> V_85 & V_97 ) {
V_81 |= V_78 -> V_98 ;
V_81 |= V_99 ;
} else {
V_81 |= V_78 -> V_98 << V_100 ;
}
if ( V_78 -> V_85 & V_101 )
V_81 |= V_102 ;
if ( V_78 -> V_85 & V_86 )
V_81 |= V_103 ;
F_6 ( V_2 , V_81 , V_7 ) ;
if ( ! ( V_78 -> V_85 & V_86 ) )
F_20 ( V_2 ) ;
V_11 = V_60 | V_61 ;
if ( V_78 -> V_85 & V_86 )
V_11 |= V_70 ;
else if ( V_2 -> V_25 )
V_11 |= V_71 ;
F_13 ( V_2 , V_11 ) ;
F_38 ( V_2 -> V_19 , L_3 ,
F_7 ( V_2 , V_12 ) ) ;
V_82 = F_39 ( & V_2 -> V_75 , V_104 ) ;
F_12 ( V_2 , V_11 ) ;
if ( F_40 ( V_82 == 0 ) ) {
F_41 ( V_2 -> V_19 , L_4 ) ;
F_23 ( V_2 ) ;
return - V_20 ;
}
F_38 ( V_2 -> V_19 , L_5 ,
V_82 , F_42 ( & V_2 -> V_75 ) , V_2 -> V_65 ) ;
if ( F_43 ( V_2 -> V_65 == V_84 ) )
return 0 ;
if ( V_2 -> V_65 == V_67 )
F_26 ( F_44 ( 2 * 1000000 , V_2 -> V_46 ) ) ;
F_23 ( V_2 ) ;
if ( V_2 -> V_65 == V_67 ) {
if ( V_78 -> V_85 & V_101 )
return 0 ;
return - V_105 ;
}
return - V_106 ;
}
static int F_45 ( struct V_107 * V_108 , struct V_77 V_109 [] ,
int V_110 )
{
struct V_1 * V_2 = F_46 ( V_108 ) ;
int V_111 ;
int V_82 = 0 ;
if ( V_2 -> V_112 )
return - V_113 ;
F_24 ( V_2 -> V_41 ) ;
for ( V_111 = 0 ; V_111 < V_110 ; V_111 ++ ) {
enum V_79 V_114 = V_115 ;
if ( V_111 < ( V_110 - 1 ) ) {
if ( V_109 [ V_111 + 1 ] . V_85 & V_116 )
V_114 = V_93 ;
else
V_114 = V_95 ;
}
V_82 = F_36 ( V_2 , & V_109 [ V_111 ] , V_114 ) ;
if ( V_82 )
break;
}
F_29 ( V_2 -> V_41 ) ;
return V_82 ? : V_111 ;
}
static T_1 F_47 ( struct V_107 * V_108 )
{
return V_117 | V_118 | V_119 |
V_120 | V_121 ;
}
static int T_5 F_48 ( struct V_122 * V_123 )
{
struct V_1 * V_2 ;
struct V_124 * V_125 = V_123 -> V_19 . V_126 ;
struct V_127 * V_128 ;
struct V_41 * V_41 ;
struct V_41 * V_129 ;
const unsigned int * V_130 ;
void T_6 * V_5 ;
int V_56 ;
int V_82 = 0 ;
V_128 = F_49 ( V_123 , V_131 , 0 ) ;
if ( ! V_128 ) {
F_41 ( & V_123 -> V_19 , L_6 ) ;
return - V_83 ;
}
V_5 = F_50 ( & V_123 -> V_19 , V_128 ) ;
if ( ! V_5 ) {
F_41 ( & V_123 -> V_19 , L_7 ) ;
return - V_132 ;
}
V_128 = F_49 ( V_123 , V_133 , 0 ) ;
if ( ! V_128 ) {
F_41 ( & V_123 -> V_19 , L_8 ) ;
return - V_83 ;
}
V_56 = V_128 -> V_134 ;
V_41 = F_51 ( & V_123 -> V_19 , NULL ) ;
if ( F_52 ( V_41 ) ) {
F_41 ( & V_123 -> V_19 , L_9 ) ;
return F_53 ( V_41 ) ;
}
V_129 = F_51 ( & V_123 -> V_19 , L_10 ) ;
if ( F_52 ( V_129 ) ) {
F_41 ( & V_123 -> V_19 , L_11 ) ;
return F_53 ( V_129 ) ;
}
V_2 = F_54 ( & V_123 -> V_19 , sizeof( * V_2 ) , V_135 ) ;
if ( ! V_2 ) {
F_41 ( & V_123 -> V_19 , L_12 ) ;
return - V_136 ;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_41 = V_41 ;
V_2 -> V_129 = V_129 ;
V_2 -> V_137 . V_138 = & V_139 ;
V_2 -> V_56 = V_56 ;
V_2 -> V_89 = V_123 -> V_140 ;
V_2 -> V_19 = & V_123 -> V_19 ;
V_2 -> V_46 = 100000 ;
if ( V_125 ) {
V_2 -> V_46 = V_125 -> V_46 ;
} else if ( V_2 -> V_19 -> V_141 ) {
V_130 = F_55 ( V_2 -> V_19 -> V_141 ,
L_13 , NULL ) ;
if ( V_130 )
V_2 -> V_46 = F_56 ( V_130 ) ;
}
if ( V_123 -> V_19 . V_141 )
V_2 -> V_6 = F_57 ( V_123 -> V_19 . V_141 ,
L_14 ) ;
else if ( V_123 -> V_140 == 3 )
V_2 -> V_6 = 1 ;
F_58 ( & V_2 -> V_75 ) ;
F_59 ( V_123 , V_2 ) ;
V_82 = F_23 ( V_2 ) ;
if ( V_82 ) {
F_41 ( & V_123 -> V_19 , L_15 ) ;
return V_82 ;
}
V_82 = F_60 ( & V_123 -> V_19 , V_2 -> V_56 ,
F_31 , 0 , V_123 -> V_142 , V_2 ) ;
if ( V_82 ) {
F_41 ( & V_123 -> V_19 , L_16 , V_2 -> V_56 ) ;
return V_82 ;
}
F_24 ( V_2 -> V_129 ) ;
F_61 ( & V_2 -> V_137 , V_2 ) ;
V_2 -> V_137 . V_143 = V_144 ;
V_2 -> V_137 . V_145 = V_146 ;
F_62 ( V_2 -> V_137 . V_142 , L_17 ,
sizeof( V_2 -> V_137 . V_142 ) ) ;
V_2 -> V_137 . V_138 = & V_139 ;
V_2 -> V_137 . V_19 . V_147 = & V_123 -> V_19 ;
V_2 -> V_137 . V_148 = V_123 -> V_140 ;
V_2 -> V_137 . V_19 . V_141 = V_123 -> V_19 . V_141 ;
V_82 = F_63 ( & V_2 -> V_137 ) ;
if ( V_82 ) {
F_41 ( & V_123 -> V_19 , L_18 ) ;
F_29 ( V_2 -> V_129 ) ;
return V_82 ;
}
F_64 ( & V_2 -> V_137 ) ;
return 0 ;
}
static int T_7 F_65 ( struct V_122 * V_123 )
{
struct V_1 * V_2 = F_66 ( V_123 ) ;
F_67 ( & V_2 -> V_137 ) ;
return 0 ;
}
static int F_68 ( struct V_149 * V_19 )
{
struct V_1 * V_2 = F_69 ( V_19 ) ;
F_70 ( & V_2 -> V_137 ) ;
V_2 -> V_112 = true ;
F_71 ( & V_2 -> V_137 ) ;
return 0 ;
}
static int F_72 ( struct V_149 * V_19 )
{
struct V_1 * V_2 = F_69 ( V_19 ) ;
int V_82 ;
F_70 ( & V_2 -> V_137 ) ;
V_82 = F_23 ( V_2 ) ;
if ( V_82 ) {
F_71 ( & V_2 -> V_137 ) ;
return V_82 ;
}
V_2 -> V_112 = false ;
F_71 ( & V_2 -> V_137 ) ;
return 0 ;
}
static int T_8 F_73 ( void )
{
return F_74 ( & V_150 ) ;
}
static void T_9 F_75 ( void )
{
F_76 ( & V_150 ) ;
}
