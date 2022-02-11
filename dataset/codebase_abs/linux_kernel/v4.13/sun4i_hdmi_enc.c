static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 ,
V_3 ) ;
}
static inline struct V_1 *
F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_1 ,
V_5 ) ;
}
static int F_4 ( struct V_1 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 V_10 ;
T_1 V_11 [ 17 ] ;
int V_12 , V_13 ;
V_13 = F_5 ( & V_10 , V_8 ) ;
if ( V_13 < 0 ) {
F_6 ( L_1 ) ;
return V_13 ;
}
V_13 = F_7 ( & V_10 , V_11 , sizeof( V_11 ) ) ;
if ( V_13 < 0 ) {
F_6 ( L_2 ) ;
return V_13 ;
}
for ( V_12 = 0 ; V_12 < sizeof( V_11 ) ; V_12 ++ )
F_8 ( V_11 [ V_12 ] , V_6 -> V_14 + F_9 ( V_12 ) ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_7 * V_8 = & V_16 -> V_8 ;
if ( V_8 -> V_19 & V_20 )
return - V_21 ;
return 0 ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_22 * V_23 = F_12 ( V_3 -> V_23 ) ;
struct V_24 * V_25 = V_23 -> V_25 ;
T_2 V_26 ;
F_13 ( L_3 ) ;
V_26 = F_14 ( V_6 -> V_14 + V_27 ) ;
V_26 &= ~ V_28 ;
F_15 ( V_26 , V_6 -> V_14 + V_27 ) ;
F_16 ( V_25 , 1 ) ;
}
static void F_17 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = & V_3 -> V_23 -> V_29 -> V_30 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_22 * V_23 = F_12 ( V_3 -> V_23 ) ;
struct V_24 * V_25 = V_23 -> V_25 ;
T_2 V_26 = 0 ;
F_13 ( L_4 ) ;
F_18 ( V_25 , 1 ) ;
F_4 ( V_6 , V_8 ) ;
V_26 |= F_19 ( 0 , V_31 ) ;
V_26 |= F_19 ( 1 , V_32 ) ;
F_15 ( V_26 , V_6 -> V_14 + F_20 ( 0 ) ) ;
V_26 = V_28 ;
if ( V_6 -> V_33 )
V_26 |= V_34 ;
F_15 ( V_26 , V_6 -> V_14 + V_27 ) ;
}
static void F_21 ( struct V_2 * V_3 ,
struct V_7 * V_8 ,
struct V_7 * V_30 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_22 * V_23 = F_12 ( V_3 -> V_23 ) ;
struct V_24 * V_25 = V_23 -> V_25 ;
unsigned int V_35 , V_36 ;
T_2 V_26 ;
F_22 ( V_25 , V_8 ) ;
F_23 ( V_25 , 1 , V_3 ) ;
F_24 ( V_25 -> V_37 , V_8 -> V_38 * 1000 ) ;
F_24 ( V_6 -> V_39 , V_8 -> V_38 * 1000 ) ;
F_24 ( V_6 -> V_40 , V_8 -> V_38 * 1000 ) ;
F_15 ( V_41 ,
V_6 -> V_14 + V_42 ) ;
F_15 ( F_25 ( V_8 -> V_43 ) |
F_26 ( V_8 -> V_44 ) ,
V_6 -> V_14 + V_45 ) ;
V_35 = V_8 -> V_46 - V_8 -> V_47 ;
V_36 = V_8 -> V_48 - V_8 -> V_49 ;
F_15 ( F_25 ( V_35 ) | F_26 ( V_36 ) ,
V_6 -> V_14 + V_50 ) ;
V_35 = V_8 -> V_47 - V_8 -> V_43 ;
V_36 = V_8 -> V_49 - V_8 -> V_44 ;
F_15 ( F_25 ( V_35 ) | F_26 ( V_36 ) ,
V_6 -> V_14 + V_51 ) ;
V_35 = V_8 -> V_52 - V_8 -> V_47 ;
V_36 = V_8 -> V_53 - V_8 -> V_49 ;
F_15 ( F_25 ( V_35 ) | F_26 ( V_36 ) ,
V_6 -> V_14 + V_54 ) ;
V_26 = V_55 ;
if ( V_8 -> V_19 & V_56 )
V_26 |= V_57 ;
if ( V_8 -> V_19 & V_58 )
V_26 |= V_59 ;
F_15 ( V_26 , V_6 -> V_14 + V_60 ) ;
}
static int F_27 ( struct V_1 * V_6 ,
unsigned int V_61 , unsigned int V_62 ,
T_1 * V_63 , unsigned int V_64 )
{
unsigned long V_65 ;
int V_12 ;
V_65 = F_14 ( V_6 -> V_14 + V_66 ) ;
V_65 &= ~ V_67 ;
F_15 ( V_65 | V_68 ,
V_6 -> V_14 + V_66 ) ;
F_15 ( F_28 ( V_62 >> 8 ) |
F_29 ( V_69 << 1 ) |
F_30 ( V_62 ) |
F_31 ( V_70 ) ,
V_6 -> V_14 + V_71 ) ;
V_65 = F_14 ( V_6 -> V_14 + V_72 ) ;
F_15 ( V_65 | V_73 ,
V_6 -> V_14 + V_72 ) ;
F_15 ( V_64 , V_6 -> V_14 + V_74 ) ;
F_15 ( V_75 ,
V_6 -> V_14 + V_76 ) ;
V_65 = F_14 ( V_6 -> V_14 + V_66 ) ;
F_15 ( V_65 | V_77 ,
V_6 -> V_14 + V_66 ) ;
if ( F_32 ( V_6 -> V_14 + V_66 , V_65 ,
! ( V_65 & V_77 ) ,
100 , 100000 ) )
return - V_78 ;
for ( V_12 = 0 ; V_12 < V_64 ; V_12 ++ )
V_63 [ V_12 ] = F_33 ( V_6 -> V_14 + V_79 ) ;
return 0 ;
}
static int F_34 ( void * V_80 , T_1 * V_63 , unsigned int V_61 ,
T_3 V_81 )
{
struct V_1 * V_6 = V_80 ;
int V_82 = 2 , V_12 ;
do {
for ( V_12 = 0 ; V_12 < V_81 ; V_12 += V_83 ) {
unsigned char V_62 = V_61 * V_84 + V_12 ;
unsigned int V_64 = F_35 ( ( unsigned int ) V_83 ,
V_81 - V_12 ) ;
int V_13 ;
V_13 = F_27 ( V_6 , V_61 , V_62 ,
V_63 + V_12 , V_64 ) ;
if ( V_13 )
return V_13 ;
}
} while ( ! F_36 ( V_63 , V_61 , true , NULL ) && ( V_82 -- ) );
return 0 ;
}
static int F_37 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
unsigned long V_65 ;
struct V_85 * V_85 ;
int V_13 ;
F_15 ( V_86 | V_87 ,
V_6 -> V_14 + V_66 ) ;
if ( F_32 ( V_6 -> V_14 + V_66 , V_65 ,
! ( V_65 & V_87 ) ,
100 , 2000 ) )
return - V_78 ;
F_15 ( V_88 |
V_89 ,
V_6 -> V_14 + V_90 ) ;
F_38 ( V_6 -> V_91 ) ;
F_24 ( V_6 -> V_91 , 100000 ) ;
V_85 = F_39 ( V_5 , F_34 , V_6 ) ;
if ( ! V_85 )
return 0 ;
V_6 -> V_33 = F_40 ( V_85 ) ;
F_13 ( L_5 ,
V_6 -> V_33 ? L_6 : L_7 ) ;
F_41 ( V_5 , V_85 ) ;
V_13 = F_42 ( V_5 , V_85 ) ;
F_43 ( V_85 ) ;
F_44 ( V_6 -> V_91 ) ;
return V_13 ;
}
static enum V_92
F_45 ( struct V_4 * V_5 , bool V_93 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
unsigned long V_65 ;
if ( F_32 ( V_6 -> V_14 + V_94 , V_65 ,
V_65 & V_95 ,
0 , 500000 ) )
return V_96 ;
return V_97 ;
}
static int F_46 ( struct V_98 * V_99 , struct V_98 * V_100 ,
void * V_80 )
{
struct V_101 * V_102 = F_47 ( V_99 ) ;
struct V_103 * V_104 = V_80 ;
struct V_105 * V_106 = V_104 -> V_107 ;
struct V_1 * V_6 ;
struct V_108 * V_109 ;
T_2 V_65 ;
int V_13 ;
V_6 = F_48 ( V_99 , sizeof( * V_6 ) , V_110 ) ;
if ( ! V_6 )
return - V_111 ;
F_49 ( V_99 , V_6 ) ;
V_6 -> V_99 = V_99 ;
V_6 -> V_106 = V_106 ;
V_109 = F_50 ( V_102 , V_112 , 0 ) ;
V_6 -> V_14 = F_51 ( V_99 , V_109 ) ;
if ( F_52 ( V_6 -> V_14 ) ) {
F_53 ( V_99 , L_8 ) ;
return F_54 ( V_6 -> V_14 ) ;
}
V_6 -> V_113 = F_55 ( V_99 , L_9 ) ;
if ( F_52 ( V_6 -> V_113 ) ) {
F_53 ( V_99 , L_10 ) ;
return F_54 ( V_6 -> V_113 ) ;
}
F_38 ( V_6 -> V_113 ) ;
V_6 -> V_39 = F_55 ( V_99 , L_11 ) ;
if ( F_52 ( V_6 -> V_39 ) ) {
F_53 ( V_99 , L_12 ) ;
return F_54 ( V_6 -> V_39 ) ;
}
F_38 ( V_6 -> V_39 ) ;
V_6 -> V_114 = F_55 ( V_99 , L_13 ) ;
if ( F_52 ( V_6 -> V_114 ) ) {
F_53 ( V_99 , L_14 ) ;
return F_54 ( V_6 -> V_114 ) ;
}
V_6 -> V_115 = F_55 ( V_99 , L_15 ) ;
if ( F_52 ( V_6 -> V_115 ) ) {
F_53 ( V_99 , L_16 ) ;
return F_54 ( V_6 -> V_115 ) ;
}
V_13 = F_56 ( V_6 ) ;
if ( V_13 ) {
F_53 ( V_99 , L_17 ) ;
return V_13 ;
}
F_15 ( V_116 , V_6 -> V_14 + V_117 ) ;
F_15 ( V_118 | V_119 |
V_120 | V_121 |
V_122 | V_123 |
V_124 | V_125 ,
V_6 -> V_14 + V_126 ) ;
V_65 = F_14 ( V_6 -> V_14 + V_127 ) ;
V_65 &= V_128 ;
V_65 |= F_57 ( 6 ) |
F_58 ( 2 ) |
V_129 |
V_130 |
V_131 |
V_132 |
V_133 |
V_134 ;
F_15 ( V_65 , V_6 -> V_14 + V_127 ) ;
V_65 = F_14 ( V_6 -> V_14 + V_135 ) ;
V_65 &= V_136 ;
V_65 |= F_59 ( 8 ) | F_60 ( 7 ) |
F_61 ( 15 ) | F_62 ( 7 ) |
F_63 ( 4 ) | V_137 |
V_138 | V_139 |
V_140 | V_141 |
V_142 ;
F_15 ( V_65 , V_6 -> V_14 + V_135 ) ;
V_13 = F_64 ( V_6 , V_6 -> V_40 ) ;
if ( V_13 ) {
F_53 ( V_99 , L_18 ) ;
return V_13 ;
}
F_65 ( & V_6 -> V_3 ,
& V_143 ) ;
V_13 = F_66 ( V_104 ,
& V_6 -> V_3 ,
& V_144 ,
V_145 ,
NULL ) ;
if ( V_13 ) {
F_53 ( V_99 , L_19 ) ;
return V_13 ;
}
V_6 -> V_3 . V_146 = F_67 ( V_104 ,
V_99 -> V_147 ) ;
if ( ! V_6 -> V_3 . V_146 )
return - V_148 ;
F_68 ( & V_6 -> V_5 ,
& V_149 ) ;
V_13 = F_69 ( V_104 , & V_6 -> V_5 ,
& V_150 ,
V_151 ) ;
if ( V_13 ) {
F_53 ( V_99 ,
L_20 ) ;
goto V_152;
}
V_6 -> V_5 . V_153 = V_154 |
V_155 ;
F_70 ( & V_6 -> V_5 , & V_6 -> V_3 ) ;
return 0 ;
V_152:
F_71 ( & V_6 -> V_3 ) ;
return V_13 ;
}
static void F_72 ( struct V_98 * V_99 , struct V_98 * V_100 ,
void * V_80 )
{
struct V_1 * V_6 = F_73 ( V_99 ) ;
F_74 ( & V_6 -> V_5 ) ;
F_71 ( & V_6 -> V_3 ) ;
}
static int F_75 ( struct V_101 * V_102 )
{
return F_76 ( & V_102 -> V_99 , & V_156 ) ;
}
static int F_77 ( struct V_101 * V_102 )
{
F_78 ( & V_102 -> V_99 , & V_156 ) ;
return 0 ;
}
