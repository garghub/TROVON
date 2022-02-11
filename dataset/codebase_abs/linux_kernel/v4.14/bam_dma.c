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
if ( V_48 & V_80 )
V_67 -> V_48 |= F_31 ( V_81 ) ;
V_67 -> V_82 = F_32 ( F_33 ( V_65 ) +
V_79 ) ;
if ( V_78 > V_31 ) {
V_67 -> V_83 = F_31 ( V_31 ) ;
V_78 -= V_31 ;
V_79 += V_31 ;
} else {
V_67 -> V_83 = F_31 ( V_78 ) ;
V_78 = 0 ;
}
V_64 -> V_84 += V_67 -> V_83 ;
V_67 ++ ;
} while ( V_78 > 0 );
}
return F_34 ( & V_20 -> V_4 , & V_64 -> V_85 , V_48 ) ;
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
F_38 ( & V_20 -> V_50 -> V_85 . V_86 , & V_20 -> V_4 . V_87 ) ;
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
F_6 ( 1 , F_3 ( V_7 , V_20 -> V_22 , V_88 ) ) ;
V_20 -> V_89 = 1 ;
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
F_6 ( 0 , F_3 ( V_7 , V_20 -> V_22 , V_88 ) ) ;
V_20 -> V_89 = 0 ;
F_20 ( & V_20 -> V_4 . V_21 , V_54 ) ;
F_22 ( V_7 -> V_44 ) ;
F_23 ( V_7 -> V_44 ) ;
return 0 ;
}
static T_2 F_43 ( struct V_6 * V_7 )
{
T_2 V_66 , V_90 , V_91 ;
unsigned long V_48 ;
struct V_63 * V_64 ;
V_90 = F_10 ( F_3 ( V_7 , 0 , V_92 ) ) ;
if ( ! ( V_90 & V_93 ) )
return V_90 ;
for ( V_66 = 0 ; V_66 < V_7 -> V_94 ; V_66 ++ ) {
struct V_1 * V_20 = & V_7 -> V_95 [ V_66 ] ;
if ( ! ( V_90 & F_11 ( V_66 ) ) )
continue;
V_91 = F_10 ( F_3 ( V_7 , V_66 , V_96 ) ) ;
F_6 ( V_91 , F_3 ( V_7 , V_66 , V_97 ) ) ;
F_19 ( & V_20 -> V_4 . V_21 , V_48 ) ;
V_64 = V_20 -> V_50 ;
if ( V_64 ) {
V_64 -> V_76 -= V_64 -> V_98 ;
V_64 -> V_77 += V_64 -> V_98 ;
V_20 -> V_50 = NULL ;
V_20 -> V_41 += V_64 -> V_98 ;
V_20 -> V_41 %= V_99 ;
if ( ! V_64 -> V_76 )
F_44 ( & V_64 -> V_85 ) ;
else
F_38 ( & V_64 -> V_85 . V_86 ,
& V_20 -> V_4 . V_87 ) ;
}
F_20 ( & V_20 -> V_4 . V_21 , V_48 ) ;
}
return V_90 ;
}
static T_3 F_45 ( int V_100 , void * V_101 )
{
struct V_6 * V_7 = V_101 ;
T_2 V_102 = 0 , V_90 = 0 ;
int V_49 ;
V_90 |= F_43 ( V_7 ) ;
if ( V_90 & V_93 )
F_46 ( & V_7 -> V_103 ) ;
V_49 = F_16 ( V_7 -> V_44 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_90 & V_104 ) {
V_102 = F_10 ( F_3 ( V_7 , 0 , V_105 ) ) ;
F_47 () ;
F_6 ( V_102 , F_3 ( V_7 , 0 , V_106 ) ) ;
}
F_22 ( V_7 -> V_44 ) ;
F_23 ( V_7 -> V_44 ) ;
return V_107 ;
}
static enum V_108 F_48 ( struct V_2 * V_5 , T_4 V_109 ,
struct V_110 * V_111 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
struct V_112 * V_85 ;
int V_49 ;
T_5 V_113 = 0 ;
unsigned int V_66 ;
unsigned long V_48 ;
V_49 = F_49 ( V_5 , V_109 , V_111 ) ;
if ( V_49 == V_114 )
return V_49 ;
if ( ! V_111 )
return V_20 -> V_89 ? V_115 : V_49 ;
F_19 ( & V_20 -> V_4 . V_21 , V_48 ) ;
V_85 = F_50 ( & V_20 -> V_4 , V_109 ) ;
if ( V_85 )
V_113 = F_2 ( V_85 , struct V_63 , V_85 ) -> V_84 ;
else if ( V_20 -> V_50 && V_20 -> V_50 -> V_85 . V_116 . V_109 == V_109 )
for ( V_66 = 0 ; V_66 < V_20 -> V_50 -> V_76 ; V_66 ++ )
V_113 += V_20 -> V_50 -> V_77 [ V_66 ] . V_83 ;
F_20 ( & V_20 -> V_4 . V_21 , V_48 ) ;
F_51 ( V_111 , V_113 ) ;
if ( V_49 == V_117 && V_20 -> V_89 )
V_49 = V_115 ;
return V_49 ;
}
static void F_52 ( struct V_1 * V_20 ,
enum V_25 V_26 )
{
struct V_6 * V_7 = V_20 -> V_7 ;
T_2 V_118 ;
if ( V_26 == V_38 )
V_118 = V_20 -> V_55 . V_119 ;
else
V_118 = V_20 -> V_55 . V_120 ;
F_6 ( V_118 , F_3 ( V_7 , 0 , V_121 ) ) ;
V_20 -> V_56 = 0 ;
}
static void F_53 ( struct V_1 * V_20 )
{
struct V_112 * V_85 = F_54 ( & V_20 -> V_4 ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
struct V_63 * V_64 ;
struct V_29 * V_67 ;
struct V_29 * V_122 = F_55 ( V_20 -> V_43 ,
sizeof( struct V_29 ) ) ;
int V_49 ;
F_5 ( & V_20 -> V_4 . V_21 ) ;
if ( ! V_85 )
return;
F_56 ( & V_85 -> V_86 ) ;
V_64 = F_2 ( V_85 , struct V_63 , V_85 ) ;
V_20 -> V_50 = V_64 ;
V_49 = F_16 ( V_7 -> V_44 ) ;
if ( V_49 < 0 )
return;
if ( ! V_20 -> V_24 )
F_8 ( V_20 , V_64 -> V_26 ) ;
if ( V_20 -> V_56 )
F_52 ( V_20 , V_64 -> V_26 ) ;
V_67 = V_20 -> V_50 -> V_77 ;
if ( V_64 -> V_76 > V_99 )
V_64 -> V_98 = V_99 ;
else
V_64 -> V_98 = V_64 -> V_76 ;
if ( V_64 -> V_76 == V_64 -> V_98 )
V_67 [ V_64 -> V_98 - 1 ] . V_48 |=
F_31 ( V_64 -> V_48 ) ;
else
V_67 [ V_64 -> V_98 - 1 ] . V_48 |=
F_31 ( V_75 ) ;
if ( V_20 -> V_42 + V_64 -> V_98 > V_99 ) {
T_2 V_123 = V_99 - V_20 -> V_42 ;
memcpy ( & V_122 [ V_20 -> V_42 ] , V_67 ,
V_123 * sizeof( struct V_29 ) ) ;
memcpy ( V_122 , & V_67 [ V_123 ] , ( V_64 -> V_98 - V_123 ) *
sizeof( struct V_29 ) ) ;
} else {
memcpy ( & V_122 [ V_20 -> V_42 ] , V_67 ,
V_64 -> V_98 * sizeof( struct V_29 ) ) ;
}
V_20 -> V_42 += V_64 -> V_98 ;
V_20 -> V_42 %= V_99 ;
F_7 () ;
F_6 ( V_20 -> V_42 * sizeof( struct V_29 ) ,
F_3 ( V_7 , V_20 -> V_22 , V_124 ) ) ;
F_22 ( V_7 -> V_44 ) ;
F_23 ( V_7 -> V_44 ) ;
}
static void F_57 ( unsigned long V_101 )
{
struct V_6 * V_7 = (struct V_6 * ) V_101 ;
struct V_1 * V_20 ;
unsigned long V_48 ;
unsigned int V_66 ;
for ( V_66 = 0 ; V_66 < V_7 -> V_94 ; V_66 ++ ) {
V_20 = & V_7 -> V_95 [ V_66 ] ;
F_19 ( & V_20 -> V_4 . V_21 , V_48 ) ;
if ( ! F_58 ( & V_20 -> V_4 . V_87 ) && ! V_20 -> V_50 )
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
static void F_61 ( struct V_112 * V_85 )
{
struct V_63 * V_64 = F_2 ( V_85 ,
struct V_63 , V_85 ) ;
F_35 ( V_64 ) ;
}
static struct V_2 * F_62 ( struct V_125 * V_126 ,
struct V_127 * V_128 )
{
struct V_6 * V_7 = F_2 ( V_128 -> V_129 ,
struct V_6 , V_3 ) ;
unsigned int V_130 ;
if ( V_126 -> V_131 != 1 )
return NULL ;
V_130 = V_126 -> args [ 0 ] ;
if ( V_130 >= V_7 -> V_94 )
return NULL ;
return F_63 ( & ( V_7 -> V_95 [ V_130 ] . V_4 . V_5 ) ) ;
}
static int F_64 ( struct V_6 * V_7 )
{
T_2 V_27 ;
V_27 = F_10 ( F_3 ( V_7 , 0 , V_132 ) ) >> V_133 ;
V_27 &= V_134 ;
if ( V_7 -> V_19 >= V_27 )
return - V_135 ;
V_27 = F_10 ( F_3 ( V_7 , 0 , V_136 ) ) ;
V_7 -> V_94 = V_27 & V_137 ;
if ( V_7 -> V_138 )
return 0 ;
V_27 = F_10 ( F_3 ( V_7 , 0 , V_139 ) ) ;
V_27 |= V_140 ;
F_6 ( V_27 , F_3 ( V_7 , 0 , V_139 ) ) ;
V_27 &= ~ V_140 ;
F_6 ( V_27 , F_3 ( V_7 , 0 , V_139 ) ) ;
F_7 () ;
V_27 |= V_141 ;
F_6 ( V_27 , F_3 ( V_7 , 0 , V_139 ) ) ;
F_6 ( V_142 ,
F_3 ( V_7 , 0 , V_121 ) ) ;
F_6 ( V_143 , F_3 ( V_7 , 0 , V_144 ) ) ;
F_6 ( V_145 | V_146 ,
F_3 ( V_7 , 0 , V_147 ) ) ;
F_6 ( V_148 , F_3 ( V_7 , 0 , V_35 ) ) ;
return 0 ;
}
static void F_65 ( struct V_6 * V_7 , struct V_1 * V_20 ,
T_2 V_149 )
{
V_20 -> V_22 = V_149 ;
V_20 -> V_7 = V_7 ;
F_66 ( & V_20 -> V_4 , & V_7 -> V_3 ) ;
V_20 -> V_4 . V_150 = F_61 ;
}
static int F_67 ( struct V_151 * V_152 )
{
struct V_6 * V_7 ;
const struct V_153 * V_154 ;
struct V_155 * V_156 ;
int V_49 , V_66 ;
V_7 = F_68 ( & V_152 -> V_44 , sizeof( * V_7 ) , V_46 ) ;
if ( ! V_7 )
return - V_47 ;
V_7 -> V_44 = & V_152 -> V_44 ;
V_154 = F_69 ( V_157 , V_152 -> V_44 . V_158 ) ;
if ( ! V_154 ) {
F_14 ( & V_152 -> V_44 , L_4 ) ;
return - V_159 ;
}
V_7 -> V_13 = V_154 -> V_101 ;
V_156 = F_70 ( V_152 , V_160 , 0 ) ;
V_7 -> V_14 = F_71 ( & V_152 -> V_44 , V_156 ) ;
if ( F_72 ( V_7 -> V_14 ) )
return F_73 ( V_7 -> V_14 ) ;
V_7 -> V_100 = F_74 ( V_152 , 0 ) ;
if ( V_7 -> V_100 < 0 )
return V_7 -> V_100 ;
V_49 = F_75 ( V_152 -> V_44 . V_158 , L_5 , & V_7 -> V_19 ) ;
if ( V_49 ) {
F_14 ( V_7 -> V_44 , L_6 ) ;
return V_49 ;
}
V_7 -> V_138 = F_76 ( V_152 -> V_44 . V_158 ,
L_7 ) ;
V_7 -> V_161 = F_77 ( V_7 -> V_44 , L_8 ) ;
if ( F_72 ( V_7 -> V_161 ) )
return F_73 ( V_7 -> V_161 ) ;
V_49 = F_78 ( V_7 -> V_161 ) ;
if ( V_49 ) {
F_14 ( V_7 -> V_44 , L_9 ) ;
return V_49 ;
}
V_49 = F_64 ( V_7 ) ;
if ( V_49 )
goto V_162;
F_79 ( & V_7 -> V_103 , F_57 , ( unsigned long ) V_7 ) ;
V_7 -> V_95 = F_80 ( V_7 -> V_44 , V_7 -> V_94 ,
sizeof( * V_7 -> V_95 ) , V_46 ) ;
if ( ! V_7 -> V_95 ) {
V_49 = - V_47 ;
goto V_163;
}
F_81 ( & V_7 -> V_3 . V_95 ) ;
for ( V_66 = 0 ; V_66 < V_7 -> V_94 ; V_66 ++ )
F_65 ( V_7 , & V_7 -> V_95 [ V_66 ] , V_66 ) ;
V_49 = F_82 ( V_7 -> V_44 , V_7 -> V_100 , F_45 ,
V_164 , L_10 , V_7 ) ;
if ( V_49 )
goto V_165;
V_7 -> V_3 . V_44 = V_7 -> V_44 ;
V_7 -> V_3 . V_44 -> V_166 = & V_7 -> V_166 ;
V_49 = F_83 ( V_7 -> V_3 . V_44 , V_31 ) ;
if ( V_49 ) {
F_14 ( V_7 -> V_44 , L_11 ) ;
goto V_165;
}
F_84 ( V_152 , V_7 ) ;
F_85 ( V_7 -> V_3 . V_167 ) ;
F_86 ( V_168 , V_7 -> V_3 . V_167 ) ;
V_7 -> V_3 . V_169 = F_11 ( V_38 ) | F_11 ( V_170 ) ;
V_7 -> V_3 . V_171 = V_172 ;
V_7 -> V_3 . V_173 = V_174 ;
V_7 -> V_3 . V_175 = V_174 ;
V_7 -> V_3 . V_176 = F_12 ;
V_7 -> V_3 . V_177 = F_15 ;
V_7 -> V_3 . V_178 = F_25 ;
V_7 -> V_3 . V_179 = F_24 ;
V_7 -> V_3 . V_180 = F_41 ;
V_7 -> V_3 . V_181 = F_42 ;
V_7 -> V_3 . V_182 = F_36 ;
V_7 -> V_3 . V_183 = F_59 ;
V_7 -> V_3 . V_184 = F_48 ;
V_7 -> V_3 . V_44 = V_7 -> V_44 ;
V_49 = F_87 ( & V_7 -> V_3 ) ;
if ( V_49 ) {
F_14 ( V_7 -> V_44 , L_12 ) ;
goto V_165;
}
V_49 = F_88 ( V_152 -> V_44 . V_158 , F_62 ,
& V_7 -> V_3 ) ;
if ( V_49 )
goto V_185;
F_89 ( & V_152 -> V_44 ) ;
F_90 ( & V_152 -> V_44 , V_186 ) ;
F_91 ( & V_152 -> V_44 ) ;
F_22 ( & V_152 -> V_44 ) ;
F_92 ( & V_152 -> V_44 ) ;
F_93 ( & V_152 -> V_44 ) ;
return 0 ;
V_185:
F_94 ( & V_7 -> V_3 ) ;
V_165:
for ( V_66 = 0 ; V_66 < V_7 -> V_94 ; V_66 ++ )
F_95 ( & V_7 -> V_95 [ V_66 ] . V_4 . V_103 ) ;
V_163:
F_95 ( & V_7 -> V_103 ) ;
V_162:
F_96 ( V_7 -> V_161 ) ;
return V_49 ;
}
static int F_97 ( struct V_151 * V_152 )
{
struct V_6 * V_7 = F_98 ( V_152 ) ;
T_2 V_66 ;
F_99 ( & V_152 -> V_44 ) ;
F_100 ( V_152 -> V_44 . V_158 ) ;
F_94 ( & V_7 -> V_3 ) ;
F_6 ( 0 , F_3 ( V_7 , 0 , V_35 ) ) ;
F_101 ( V_7 -> V_44 , V_7 -> V_100 , V_7 ) ;
for ( V_66 = 0 ; V_66 < V_7 -> V_94 ; V_66 ++ ) {
F_36 ( & V_7 -> V_95 [ V_66 ] . V_4 . V_5 ) ;
F_95 ( & V_7 -> V_95 [ V_66 ] . V_4 . V_103 ) ;
if ( ! V_7 -> V_95 [ V_66 ] . V_43 )
continue;
F_21 ( V_7 -> V_44 , V_45 ,
V_7 -> V_95 [ V_66 ] . V_43 ,
V_7 -> V_95 [ V_66 ] . V_28 ) ;
}
F_95 ( & V_7 -> V_103 ) ;
F_96 ( V_7 -> V_161 ) ;
return 0 ;
}
static int T_6 F_102 ( struct V_187 * V_44 )
{
struct V_6 * V_7 = F_103 ( V_44 ) ;
F_104 ( V_7 -> V_161 ) ;
return 0 ;
}
static int T_6 F_105 ( struct V_187 * V_44 )
{
struct V_6 * V_7 = F_103 ( V_44 ) ;
int V_49 ;
V_49 = F_106 ( V_7 -> V_161 ) ;
if ( V_49 < 0 ) {
F_14 ( V_44 , L_13 , V_49 ) ;
return V_49 ;
}
return 0 ;
}
static int T_6 F_107 ( struct V_187 * V_44 )
{
struct V_6 * V_7 = F_103 ( V_44 ) ;
F_99 ( V_44 ) ;
F_108 ( V_7 -> V_161 ) ;
return 0 ;
}
static int T_6 F_109 ( struct V_187 * V_44 )
{
struct V_6 * V_7 = F_103 ( V_44 ) ;
int V_49 ;
V_49 = F_110 ( V_7 -> V_161 ) ;
if ( V_49 )
return V_49 ;
F_111 ( V_44 ) ;
return 0 ;
}
