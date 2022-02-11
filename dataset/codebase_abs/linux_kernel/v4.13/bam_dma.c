static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_5 ) ;
}
static inline void T_1 * F_3 ( struct V_6 * V_7 , T_2 V_8 ,
enum V_9 V_10 )
{
const struct V_11 V_12 = V_7 -> V_13 [ V_10 ] ;
return V_7 -> V_14 + V_12 . V_15 +
V_12 . V_16 * V_8 +
V_12 . V_17 * V_8 +
V_12 . V_18 * V_7 -> V_19 ;
}
static void F_4 ( struct V_1 * V_20 )
{
struct V_6 * V_7 = V_20 -> V_7 ;
F_5 ( & V_20 -> V_4 . V_21 ) ;
F_6 ( 1 , F_3 ( V_7 , V_20 -> V_22 , V_23 ) ) ;
F_6 ( 0 , F_3 ( V_7 , V_20 -> V_22 , V_23 ) ) ;
F_7 () ;
V_20 -> V_24 = 0 ;
}
static void F_8 ( struct V_1 * V_20 ,
enum V_25 V_26 )
{
struct V_6 * V_7 = V_20 -> V_7 ;
T_2 V_27 ;
F_4 ( V_20 ) ;
F_6 ( F_9 ( V_20 -> V_28 , sizeof( struct V_29 ) ) ,
F_3 ( V_7 , V_20 -> V_22 , V_30 ) ) ;
F_6 ( V_31 ,
F_3 ( V_7 , V_20 -> V_22 , V_32 ) ) ;
F_6 ( V_33 ,
F_3 ( V_7 , V_20 -> V_22 , V_34 ) ) ;
V_27 = F_10 ( F_3 ( V_7 , 0 , V_35 ) ) ;
V_27 |= F_11 ( V_20 -> V_22 ) ;
F_6 ( V_27 , F_3 ( V_7 , 0 , V_35 ) ) ;
F_7 () ;
V_27 = V_36 | V_37 ;
if ( V_26 == V_38 )
V_27 |= V_39 ;
F_6 ( V_27 , F_3 ( V_7 , V_20 -> V_22 , V_40 ) ) ;
V_20 -> V_24 = 1 ;
V_20 -> V_41 = 0 ;
V_20 -> V_42 = 0 ;
}
static int F_12 ( struct V_2 * V_5 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
if ( V_20 -> V_43 )
return 0 ;
V_20 -> V_43 = F_13 ( V_7 -> V_44 , V_45 ,
& V_20 -> V_28 , V_46 ) ;
if ( ! V_20 -> V_43 ) {
F_14 ( V_7 -> V_44 , L_1 ) ;
return - V_47 ;
}
return 0 ;
}
static void F_15 ( struct V_2 * V_5 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
T_2 V_27 ;
unsigned long V_48 ;
int V_49 ;
V_49 = F_16 ( V_7 -> V_44 ) ;
if ( V_49 < 0 )
return;
F_17 ( F_18 ( V_5 ) ) ;
if ( V_20 -> V_50 ) {
F_14 ( V_20 -> V_7 -> V_44 , L_2 ) ;
goto V_51;
}
F_19 ( & V_20 -> V_4 . V_21 , V_48 ) ;
F_4 ( V_20 ) ;
F_20 ( & V_20 -> V_4 . V_21 , V_48 ) ;
F_21 ( V_7 -> V_44 , V_45 , V_20 -> V_43 ,
V_20 -> V_28 ) ;
V_20 -> V_43 = NULL ;
V_27 = F_10 ( F_3 ( V_7 , 0 , V_35 ) ) ;
V_27 &= ~ F_11 ( V_20 -> V_22 ) ;
F_6 ( V_27 , F_3 ( V_7 , 0 , V_35 ) ) ;
F_6 ( 0 , F_3 ( V_7 , V_20 -> V_22 , V_34 ) ) ;
V_51:
F_22 ( V_7 -> V_44 ) ;
F_23 ( V_7 -> V_44 ) ;
}
static int F_24 ( struct V_2 * V_5 ,
struct V_52 * V_53 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
unsigned long V_54 ;
F_19 ( & V_20 -> V_4 . V_21 , V_54 ) ;
memcpy ( & V_20 -> V_55 , V_53 , sizeof( * V_53 ) ) ;
V_20 -> V_56 = 1 ;
F_20 ( & V_20 -> V_4 . V_21 , V_54 ) ;
return 0 ;
}
static struct V_57 * F_25 ( struct V_2 * V_5 ,
struct V_58 * V_59 , unsigned int V_60 ,
enum V_25 V_61 , unsigned long V_48 ,
void * V_62 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
struct V_63 * V_64 ;
struct V_58 * V_65 ;
T_2 V_66 ;
struct V_29 * V_67 ;
unsigned int V_68 = 0 ;
if ( ! F_26 ( V_61 ) ) {
F_14 ( V_7 -> V_44 , L_3 ) ;
return NULL ;
}
F_27 (sgl, sg, sg_len, i)
V_68 += F_28 ( F_29 ( V_65 ) , V_31 ) ;
V_64 = F_30 ( sizeof( * V_64 ) +
( V_68 * sizeof( struct V_29 ) ) , V_69 ) ;
if ( ! V_64 )
goto V_70;
if ( V_48 & V_71 )
V_64 -> V_48 |= V_72 ;
if ( V_48 & V_73 )
V_64 -> V_48 |= V_74 ;
else
V_64 -> V_48 |= V_75 ;
V_64 -> V_76 = V_68 ;
V_64 -> V_77 = V_64 -> V_67 ;
V_64 -> V_26 = V_61 ;
V_67 = V_64 -> V_67 ;
F_27 (sgl, sg, sg_len, i) {
unsigned int V_78 = F_29 ( V_65 ) ;
unsigned int V_79 = 0 ;
do {
V_67 -> V_80 = F_31 ( F_32 ( V_65 ) +
V_79 ) ;
if ( V_78 > V_31 ) {
V_67 -> V_81 = F_33 ( V_31 ) ;
V_78 -= V_31 ;
V_79 += V_31 ;
} else {
V_67 -> V_81 = F_33 ( V_78 ) ;
V_78 = 0 ;
}
V_64 -> V_82 += V_67 -> V_81 ;
V_67 ++ ;
} while ( V_78 > 0 );
}
return F_34 ( & V_20 -> V_4 , & V_64 -> V_83 , V_48 ) ;
V_70:
F_35 ( V_64 ) ;
return NULL ;
}
static int F_36 ( struct V_2 * V_5 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
unsigned long V_54 ;
F_37 ( V_41 ) ;
F_19 ( & V_20 -> V_4 . V_21 , V_54 ) ;
if ( V_20 -> V_50 ) {
F_38 ( & V_20 -> V_50 -> V_83 . V_84 , & V_20 -> V_4 . V_85 ) ;
V_20 -> V_50 = NULL ;
}
F_39 ( & V_20 -> V_4 , & V_41 ) ;
F_20 ( & V_20 -> V_4 . V_21 , V_54 ) ;
F_40 ( & V_20 -> V_4 , & V_41 ) ;
return 0 ;
}
static int F_41 ( struct V_2 * V_5 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
unsigned long V_54 ;
int V_49 ;
V_49 = F_16 ( V_7 -> V_44 ) ;
if ( V_49 < 0 )
return V_49 ;
F_19 ( & V_20 -> V_4 . V_21 , V_54 ) ;
F_6 ( 1 , F_3 ( V_7 , V_20 -> V_22 , V_86 ) ) ;
V_20 -> V_87 = 1 ;
F_20 ( & V_20 -> V_4 . V_21 , V_54 ) ;
F_22 ( V_7 -> V_44 ) ;
F_23 ( V_7 -> V_44 ) ;
return 0 ;
}
static int F_42 ( struct V_2 * V_5 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
unsigned long V_54 ;
int V_49 ;
V_49 = F_16 ( V_7 -> V_44 ) ;
if ( V_49 < 0 )
return V_49 ;
F_19 ( & V_20 -> V_4 . V_21 , V_54 ) ;
F_6 ( 0 , F_3 ( V_7 , V_20 -> V_22 , V_86 ) ) ;
V_20 -> V_87 = 0 ;
F_20 ( & V_20 -> V_4 . V_21 , V_54 ) ;
F_22 ( V_7 -> V_44 ) ;
F_23 ( V_7 -> V_44 ) ;
return 0 ;
}
static T_2 F_43 ( struct V_6 * V_7 )
{
T_2 V_66 , V_88 , V_89 ;
unsigned long V_48 ;
struct V_63 * V_64 ;
V_88 = F_10 ( F_3 ( V_7 , 0 , V_90 ) ) ;
if ( ! ( V_88 & V_91 ) )
return V_88 ;
for ( V_66 = 0 ; V_66 < V_7 -> V_92 ; V_66 ++ ) {
struct V_1 * V_20 = & V_7 -> V_93 [ V_66 ] ;
if ( ! ( V_88 & F_11 ( V_66 ) ) )
continue;
V_89 = F_10 ( F_3 ( V_7 , V_66 , V_94 ) ) ;
F_6 ( V_89 , F_3 ( V_7 , V_66 , V_95 ) ) ;
F_19 ( & V_20 -> V_4 . V_21 , V_48 ) ;
V_64 = V_20 -> V_50 ;
if ( V_64 ) {
V_64 -> V_76 -= V_64 -> V_96 ;
V_64 -> V_77 += V_64 -> V_96 ;
V_20 -> V_50 = NULL ;
V_20 -> V_41 += V_64 -> V_96 ;
V_20 -> V_41 %= V_97 ;
if ( ! V_64 -> V_76 )
F_44 ( & V_64 -> V_83 ) ;
else
F_38 ( & V_64 -> V_83 . V_84 ,
& V_20 -> V_4 . V_85 ) ;
}
F_20 ( & V_20 -> V_4 . V_21 , V_48 ) ;
}
return V_88 ;
}
static T_3 F_45 ( int V_98 , void * V_99 )
{
struct V_6 * V_7 = V_99 ;
T_2 V_100 = 0 , V_88 = 0 ;
int V_49 ;
V_88 |= F_43 ( V_7 ) ;
if ( V_88 & V_91 )
F_46 ( & V_7 -> V_101 ) ;
V_49 = F_16 ( V_7 -> V_44 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_88 & V_102 ) {
V_100 = F_10 ( F_3 ( V_7 , 0 , V_103 ) ) ;
F_47 () ;
F_6 ( V_100 , F_3 ( V_7 , 0 , V_104 ) ) ;
}
F_22 ( V_7 -> V_44 ) ;
F_23 ( V_7 -> V_44 ) ;
return V_105 ;
}
static enum V_106 F_48 ( struct V_2 * V_5 , T_4 V_107 ,
struct V_108 * V_109 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
struct V_110 * V_83 ;
int V_49 ;
T_5 V_111 = 0 ;
unsigned int V_66 ;
unsigned long V_48 ;
V_49 = F_49 ( V_5 , V_107 , V_109 ) ;
if ( V_49 == V_112 )
return V_49 ;
if ( ! V_109 )
return V_20 -> V_87 ? V_113 : V_49 ;
F_19 ( & V_20 -> V_4 . V_21 , V_48 ) ;
V_83 = F_50 ( & V_20 -> V_4 , V_107 ) ;
if ( V_83 )
V_111 = F_2 ( V_83 , struct V_63 , V_83 ) -> V_82 ;
else if ( V_20 -> V_50 && V_20 -> V_50 -> V_83 . V_114 . V_107 == V_107 )
for ( V_66 = 0 ; V_66 < V_20 -> V_50 -> V_76 ; V_66 ++ )
V_111 += V_20 -> V_50 -> V_77 [ V_66 ] . V_81 ;
F_20 ( & V_20 -> V_4 . V_21 , V_48 ) ;
F_51 ( V_109 , V_111 ) ;
if ( V_49 == V_115 && V_20 -> V_87 )
V_49 = V_113 ;
return V_49 ;
}
static void F_52 ( struct V_1 * V_20 ,
enum V_25 V_26 )
{
struct V_6 * V_7 = V_20 -> V_7 ;
T_2 V_116 ;
if ( V_26 == V_38 )
V_116 = V_20 -> V_55 . V_117 ;
else
V_116 = V_20 -> V_55 . V_118 ;
F_6 ( V_116 , F_3 ( V_7 , 0 , V_119 ) ) ;
V_20 -> V_56 = 0 ;
}
static void F_53 ( struct V_1 * V_20 )
{
struct V_110 * V_83 = F_54 ( & V_20 -> V_4 ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
struct V_63 * V_64 ;
struct V_29 * V_67 ;
struct V_29 * V_120 = F_55 ( V_20 -> V_43 ,
sizeof( struct V_29 ) ) ;
int V_49 ;
F_5 ( & V_20 -> V_4 . V_21 ) ;
if ( ! V_83 )
return;
F_56 ( & V_83 -> V_84 ) ;
V_64 = F_2 ( V_83 , struct V_63 , V_83 ) ;
V_20 -> V_50 = V_64 ;
V_49 = F_16 ( V_7 -> V_44 ) ;
if ( V_49 < 0 )
return;
if ( ! V_20 -> V_24 )
F_8 ( V_20 , V_64 -> V_26 ) ;
if ( V_20 -> V_56 )
F_52 ( V_20 , V_64 -> V_26 ) ;
V_67 = V_20 -> V_50 -> V_77 ;
if ( V_64 -> V_76 > V_97 )
V_64 -> V_96 = V_97 ;
else
V_64 -> V_96 = V_64 -> V_76 ;
if ( V_64 -> V_76 == V_64 -> V_96 )
V_67 [ V_64 -> V_96 - 1 ] . V_48 =
F_33 ( V_64 -> V_48 ) ;
else
V_67 [ V_64 -> V_96 - 1 ] . V_48 |=
F_33 ( V_75 ) ;
if ( V_20 -> V_42 + V_64 -> V_96 > V_97 ) {
T_2 V_121 = V_97 - V_20 -> V_42 ;
memcpy ( & V_120 [ V_20 -> V_42 ] , V_67 ,
V_121 * sizeof( struct V_29 ) ) ;
memcpy ( V_120 , & V_67 [ V_121 ] , ( V_64 -> V_96 - V_121 ) *
sizeof( struct V_29 ) ) ;
} else {
memcpy ( & V_120 [ V_20 -> V_42 ] , V_67 ,
V_64 -> V_96 * sizeof( struct V_29 ) ) ;
}
V_20 -> V_42 += V_64 -> V_96 ;
V_20 -> V_42 %= V_97 ;
F_7 () ;
F_6 ( V_20 -> V_42 * sizeof( struct V_29 ) ,
F_3 ( V_7 , V_20 -> V_22 , V_122 ) ) ;
F_22 ( V_7 -> V_44 ) ;
F_23 ( V_7 -> V_44 ) ;
}
static void F_57 ( unsigned long V_99 )
{
struct V_6 * V_7 = (struct V_6 * ) V_99 ;
struct V_1 * V_20 ;
unsigned long V_48 ;
unsigned int V_66 ;
for ( V_66 = 0 ; V_66 < V_7 -> V_92 ; V_66 ++ ) {
V_20 = & V_7 -> V_93 [ V_66 ] ;
F_19 ( & V_20 -> V_4 . V_21 , V_48 ) ;
if ( ! F_58 ( & V_20 -> V_4 . V_85 ) && ! V_20 -> V_50 )
F_53 ( V_20 ) ;
F_20 ( & V_20 -> V_4 . V_21 , V_48 ) ;
}
}
static void F_59 ( struct V_2 * V_5 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
unsigned long V_48 ;
F_19 ( & V_20 -> V_4 . V_21 , V_48 ) ;
if ( F_60 ( & V_20 -> V_4 ) && ! V_20 -> V_50 )
F_53 ( V_20 ) ;
F_20 ( & V_20 -> V_4 . V_21 , V_48 ) ;
}
static void F_61 ( struct V_110 * V_83 )
{
struct V_63 * V_64 = F_2 ( V_83 ,
struct V_63 , V_83 ) ;
F_35 ( V_64 ) ;
}
static struct V_2 * F_62 ( struct V_123 * V_124 ,
struct V_125 * V_126 )
{
struct V_6 * V_7 = F_2 ( V_126 -> V_127 ,
struct V_6 , V_3 ) ;
unsigned int V_128 ;
if ( V_124 -> V_129 != 1 )
return NULL ;
V_128 = V_124 -> args [ 0 ] ;
if ( V_128 >= V_7 -> V_92 )
return NULL ;
return F_63 ( & ( V_7 -> V_93 [ V_128 ] . V_4 . V_5 ) ) ;
}
static int F_64 ( struct V_6 * V_7 )
{
T_2 V_27 ;
V_27 = F_10 ( F_3 ( V_7 , 0 , V_130 ) ) >> V_131 ;
V_27 &= V_132 ;
if ( V_7 -> V_19 >= V_27 )
return - V_133 ;
V_27 = F_10 ( F_3 ( V_7 , 0 , V_134 ) ) ;
V_7 -> V_92 = V_27 & V_135 ;
if ( V_7 -> V_136 )
return 0 ;
V_27 = F_10 ( F_3 ( V_7 , 0 , V_137 ) ) ;
V_27 |= V_138 ;
F_6 ( V_27 , F_3 ( V_7 , 0 , V_137 ) ) ;
V_27 &= ~ V_138 ;
F_6 ( V_27 , F_3 ( V_7 , 0 , V_137 ) ) ;
F_7 () ;
V_27 |= V_139 ;
F_6 ( V_27 , F_3 ( V_7 , 0 , V_137 ) ) ;
F_6 ( V_140 ,
F_3 ( V_7 , 0 , V_119 ) ) ;
F_6 ( V_141 , F_3 ( V_7 , 0 , V_142 ) ) ;
F_6 ( V_143 | V_144 ,
F_3 ( V_7 , 0 , V_145 ) ) ;
F_6 ( V_146 , F_3 ( V_7 , 0 , V_35 ) ) ;
return 0 ;
}
static void F_65 ( struct V_6 * V_7 , struct V_1 * V_20 ,
T_2 V_147 )
{
V_20 -> V_22 = V_147 ;
V_20 -> V_7 = V_7 ;
F_66 ( & V_20 -> V_4 , & V_7 -> V_3 ) ;
V_20 -> V_4 . V_148 = F_61 ;
}
static int F_67 ( struct V_149 * V_150 )
{
struct V_6 * V_7 ;
const struct V_151 * V_152 ;
struct V_153 * V_154 ;
int V_49 , V_66 ;
V_7 = F_68 ( & V_150 -> V_44 , sizeof( * V_7 ) , V_46 ) ;
if ( ! V_7 )
return - V_47 ;
V_7 -> V_44 = & V_150 -> V_44 ;
V_152 = F_69 ( V_155 , V_150 -> V_44 . V_156 ) ;
if ( ! V_152 ) {
F_14 ( & V_150 -> V_44 , L_4 ) ;
return - V_157 ;
}
V_7 -> V_13 = V_152 -> V_99 ;
V_154 = F_70 ( V_150 , V_158 , 0 ) ;
V_7 -> V_14 = F_71 ( & V_150 -> V_44 , V_154 ) ;
if ( F_72 ( V_7 -> V_14 ) )
return F_73 ( V_7 -> V_14 ) ;
V_7 -> V_98 = F_74 ( V_150 , 0 ) ;
if ( V_7 -> V_98 < 0 )
return V_7 -> V_98 ;
V_49 = F_75 ( V_150 -> V_44 . V_156 , L_5 , & V_7 -> V_19 ) ;
if ( V_49 ) {
F_14 ( V_7 -> V_44 , L_6 ) ;
return V_49 ;
}
V_7 -> V_136 = F_76 ( V_150 -> V_44 . V_156 ,
L_7 ) ;
V_7 -> V_159 = F_77 ( V_7 -> V_44 , L_8 ) ;
if ( F_72 ( V_7 -> V_159 ) )
return F_73 ( V_7 -> V_159 ) ;
V_49 = F_78 ( V_7 -> V_159 ) ;
if ( V_49 ) {
F_14 ( V_7 -> V_44 , L_9 ) ;
return V_49 ;
}
V_49 = F_64 ( V_7 ) ;
if ( V_49 )
goto V_160;
F_79 ( & V_7 -> V_101 , F_57 , ( unsigned long ) V_7 ) ;
V_7 -> V_93 = F_80 ( V_7 -> V_44 , V_7 -> V_92 ,
sizeof( * V_7 -> V_93 ) , V_46 ) ;
if ( ! V_7 -> V_93 ) {
V_49 = - V_47 ;
goto V_161;
}
F_81 ( & V_7 -> V_3 . V_93 ) ;
for ( V_66 = 0 ; V_66 < V_7 -> V_92 ; V_66 ++ )
F_65 ( V_7 , & V_7 -> V_93 [ V_66 ] , V_66 ) ;
V_49 = F_82 ( V_7 -> V_44 , V_7 -> V_98 , F_45 ,
V_162 , L_10 , V_7 ) ;
if ( V_49 )
goto V_163;
V_7 -> V_3 . V_44 = V_7 -> V_44 ;
V_7 -> V_3 . V_44 -> V_164 = & V_7 -> V_164 ;
V_49 = F_83 ( V_7 -> V_3 . V_44 , V_31 ) ;
if ( V_49 ) {
F_14 ( V_7 -> V_44 , L_11 ) ;
goto V_163;
}
F_84 ( V_150 , V_7 ) ;
F_85 ( V_7 -> V_3 . V_165 ) ;
F_86 ( V_166 , V_7 -> V_3 . V_165 ) ;
V_7 -> V_3 . V_167 = F_11 ( V_38 ) | F_11 ( V_168 ) ;
V_7 -> V_3 . V_169 = V_170 ;
V_7 -> V_3 . V_171 = V_172 ;
V_7 -> V_3 . V_173 = V_172 ;
V_7 -> V_3 . V_174 = F_12 ;
V_7 -> V_3 . V_175 = F_15 ;
V_7 -> V_3 . V_176 = F_25 ;
V_7 -> V_3 . V_177 = F_24 ;
V_7 -> V_3 . V_178 = F_41 ;
V_7 -> V_3 . V_179 = F_42 ;
V_7 -> V_3 . V_180 = F_36 ;
V_7 -> V_3 . V_181 = F_59 ;
V_7 -> V_3 . V_182 = F_48 ;
V_7 -> V_3 . V_44 = V_7 -> V_44 ;
V_49 = F_87 ( & V_7 -> V_3 ) ;
if ( V_49 ) {
F_14 ( V_7 -> V_44 , L_12 ) ;
goto V_163;
}
V_49 = F_88 ( V_150 -> V_44 . V_156 , F_62 ,
& V_7 -> V_3 ) ;
if ( V_49 )
goto V_183;
F_89 ( & V_150 -> V_44 ) ;
F_90 ( & V_150 -> V_44 , V_184 ) ;
F_91 ( & V_150 -> V_44 ) ;
F_22 ( & V_150 -> V_44 ) ;
F_92 ( & V_150 -> V_44 ) ;
F_93 ( & V_150 -> V_44 ) ;
return 0 ;
V_183:
F_94 ( & V_7 -> V_3 ) ;
V_163:
for ( V_66 = 0 ; V_66 < V_7 -> V_92 ; V_66 ++ )
F_95 ( & V_7 -> V_93 [ V_66 ] . V_4 . V_101 ) ;
V_161:
F_95 ( & V_7 -> V_101 ) ;
V_160:
F_96 ( V_7 -> V_159 ) ;
return V_49 ;
}
static int F_97 ( struct V_149 * V_150 )
{
struct V_6 * V_7 = F_98 ( V_150 ) ;
T_2 V_66 ;
F_99 ( & V_150 -> V_44 ) ;
F_100 ( V_150 -> V_44 . V_156 ) ;
F_94 ( & V_7 -> V_3 ) ;
F_6 ( 0 , F_3 ( V_7 , 0 , V_35 ) ) ;
F_101 ( V_7 -> V_44 , V_7 -> V_98 , V_7 ) ;
for ( V_66 = 0 ; V_66 < V_7 -> V_92 ; V_66 ++ ) {
F_36 ( & V_7 -> V_93 [ V_66 ] . V_4 . V_5 ) ;
F_95 ( & V_7 -> V_93 [ V_66 ] . V_4 . V_101 ) ;
if ( ! V_7 -> V_93 [ V_66 ] . V_43 )
continue;
F_21 ( V_7 -> V_44 , V_45 ,
V_7 -> V_93 [ V_66 ] . V_43 ,
V_7 -> V_93 [ V_66 ] . V_28 ) ;
}
F_95 ( & V_7 -> V_101 ) ;
F_96 ( V_7 -> V_159 ) ;
return 0 ;
}
static int T_6 F_102 ( struct V_185 * V_44 )
{
struct V_6 * V_7 = F_103 ( V_44 ) ;
F_104 ( V_7 -> V_159 ) ;
return 0 ;
}
static int T_6 F_105 ( struct V_185 * V_44 )
{
struct V_6 * V_7 = F_103 ( V_44 ) ;
int V_49 ;
V_49 = F_106 ( V_7 -> V_159 ) ;
if ( V_49 < 0 ) {
F_14 ( V_44 , L_13 , V_49 ) ;
return V_49 ;
}
return 0 ;
}
static int T_6 F_107 ( struct V_185 * V_44 )
{
struct V_6 * V_7 = F_103 ( V_44 ) ;
F_99 ( V_44 ) ;
F_108 ( V_7 -> V_159 ) ;
return 0 ;
}
static int T_6 F_109 ( struct V_185 * V_44 )
{
struct V_6 * V_7 = F_103 ( V_44 ) ;
int V_49 ;
V_49 = F_110 ( V_7 -> V_159 ) ;
if ( V_49 )
return V_49 ;
F_111 ( V_44 ) ;
return 0 ;
}
