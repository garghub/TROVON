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
F_16 ( F_17 ( V_5 ) ) ;
if ( V_20 -> V_49 ) {
F_14 ( V_20 -> V_7 -> V_44 , L_2 ) ;
return;
}
F_18 ( & V_20 -> V_4 . V_21 , V_48 ) ;
F_4 ( V_20 ) ;
F_19 ( & V_20 -> V_4 . V_21 , V_48 ) ;
F_20 ( V_7 -> V_44 , V_45 , V_20 -> V_43 ,
V_20 -> V_28 ) ;
V_20 -> V_43 = NULL ;
V_27 = F_10 ( F_3 ( V_7 , 0 , V_35 ) ) ;
V_27 &= ~ F_11 ( V_20 -> V_22 ) ;
F_6 ( V_27 , F_3 ( V_7 , 0 , V_35 ) ) ;
F_6 ( 0 , F_3 ( V_7 , V_20 -> V_22 , V_34 ) ) ;
}
static int F_21 ( struct V_2 * V_5 ,
struct V_50 * V_51 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
unsigned long V_52 ;
F_18 ( & V_20 -> V_4 . V_21 , V_52 ) ;
memcpy ( & V_20 -> V_53 , V_51 , sizeof( * V_51 ) ) ;
V_20 -> V_54 = 1 ;
F_19 ( & V_20 -> V_4 . V_21 , V_52 ) ;
return 0 ;
}
static struct V_55 * F_22 ( struct V_2 * V_5 ,
struct V_56 * V_57 , unsigned int V_58 ,
enum V_25 V_59 , unsigned long V_48 ,
void * V_60 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
struct V_61 * V_62 ;
struct V_56 * V_63 ;
T_2 V_64 ;
struct V_29 * V_65 ;
unsigned int V_66 = 0 ;
if ( ! F_23 ( V_59 ) ) {
F_14 ( V_7 -> V_44 , L_3 ) ;
return NULL ;
}
F_24 (sgl, sg, sg_len, i)
V_66 += F_25 ( F_26 ( V_63 ) , V_31 ) ;
V_62 = F_27 ( sizeof( * V_62 ) +
( V_66 * sizeof( struct V_29 ) ) , V_67 ) ;
if ( ! V_62 )
goto V_68;
if ( V_48 & V_69 )
V_62 -> V_48 |= V_70 ;
if ( V_48 & V_71 )
V_62 -> V_48 |= V_72 ;
else
V_62 -> V_48 |= V_73 ;
V_62 -> V_74 = V_66 ;
V_62 -> V_75 = V_62 -> V_65 ;
V_62 -> V_26 = V_59 ;
V_65 = V_62 -> V_65 ;
F_24 (sgl, sg, sg_len, i) {
unsigned int V_76 = F_26 ( V_63 ) ;
unsigned int V_77 = 0 ;
do {
V_65 -> V_78 = F_28 ( F_29 ( V_63 ) +
V_77 ) ;
if ( V_76 > V_31 ) {
V_65 -> V_79 = F_30 ( V_31 ) ;
V_76 -= V_31 ;
V_77 += V_31 ;
} else {
V_65 -> V_79 = F_30 ( V_76 ) ;
V_76 = 0 ;
}
V_62 -> V_80 += V_65 -> V_79 ;
V_65 ++ ;
} while ( V_76 > 0 );
}
return F_31 ( & V_20 -> V_4 , & V_62 -> V_81 , V_48 ) ;
V_68:
F_32 ( V_62 ) ;
return NULL ;
}
static int F_33 ( struct V_2 * V_5 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
unsigned long V_52 ;
F_34 ( V_41 ) ;
F_18 ( & V_20 -> V_4 . V_21 , V_52 ) ;
if ( V_20 -> V_49 ) {
F_35 ( & V_20 -> V_49 -> V_81 . V_82 , & V_20 -> V_4 . V_83 ) ;
V_20 -> V_49 = NULL ;
}
F_36 ( & V_20 -> V_4 , & V_41 ) ;
F_19 ( & V_20 -> V_4 . V_21 , V_52 ) ;
F_37 ( & V_20 -> V_4 , & V_41 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_5 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
unsigned long V_52 ;
F_18 ( & V_20 -> V_4 . V_21 , V_52 ) ;
F_6 ( 1 , F_3 ( V_7 , V_20 -> V_22 , V_84 ) ) ;
V_20 -> V_85 = 1 ;
F_19 ( & V_20 -> V_4 . V_21 , V_52 ) ;
return 0 ;
}
static int F_39 ( struct V_2 * V_5 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
unsigned long V_52 ;
F_18 ( & V_20 -> V_4 . V_21 , V_52 ) ;
F_6 ( 0 , F_3 ( V_7 , V_20 -> V_22 , V_84 ) ) ;
V_20 -> V_85 = 0 ;
F_19 ( & V_20 -> V_4 . V_21 , V_52 ) ;
return 0 ;
}
static T_2 F_40 ( struct V_6 * V_7 )
{
T_2 V_64 , V_86 , V_87 ;
unsigned long V_48 ;
struct V_61 * V_62 ;
V_86 = F_10 ( F_3 ( V_7 , 0 , V_88 ) ) ;
if ( ! ( V_86 & V_89 ) )
return V_86 ;
for ( V_64 = 0 ; V_64 < V_7 -> V_90 ; V_64 ++ ) {
struct V_1 * V_20 = & V_7 -> V_91 [ V_64 ] ;
if ( ! ( V_86 & F_11 ( V_64 ) ) )
continue;
V_87 = F_10 ( F_3 ( V_7 , V_64 , V_92 ) ) ;
F_6 ( V_87 , F_3 ( V_7 , V_64 , V_93 ) ) ;
F_18 ( & V_20 -> V_4 . V_21 , V_48 ) ;
V_62 = V_20 -> V_49 ;
if ( V_62 ) {
V_62 -> V_74 -= V_62 -> V_94 ;
V_62 -> V_75 += V_62 -> V_94 ;
V_20 -> V_49 = NULL ;
V_20 -> V_41 += V_62 -> V_94 ;
V_20 -> V_41 %= V_95 ;
if ( ! V_62 -> V_74 )
F_41 ( & V_62 -> V_81 ) ;
else
F_35 ( & V_62 -> V_81 . V_82 ,
& V_20 -> V_4 . V_83 ) ;
}
F_19 ( & V_20 -> V_4 . V_21 , V_48 ) ;
}
return V_86 ;
}
static T_3 F_42 ( int V_96 , void * V_97 )
{
struct V_6 * V_7 = V_97 ;
T_2 V_98 = 0 , V_86 = 0 ;
V_86 |= F_40 ( V_7 ) ;
if ( V_86 & V_89 )
F_43 ( & V_7 -> V_99 ) ;
if ( V_86 & V_100 ) {
V_98 = F_10 ( F_3 ( V_7 , 0 , V_101 ) ) ;
F_44 () ;
F_6 ( V_98 , F_3 ( V_7 , 0 , V_102 ) ) ;
}
return V_103 ;
}
static enum V_104 F_45 ( struct V_2 * V_5 , T_4 V_105 ,
struct V_106 * V_107 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
struct V_108 * V_81 ;
int V_109 ;
T_5 V_110 = 0 ;
unsigned int V_64 ;
unsigned long V_48 ;
V_109 = F_46 ( V_5 , V_105 , V_107 ) ;
if ( V_109 == V_111 )
return V_109 ;
if ( ! V_107 )
return V_20 -> V_85 ? V_112 : V_109 ;
F_18 ( & V_20 -> V_4 . V_21 , V_48 ) ;
V_81 = F_47 ( & V_20 -> V_4 , V_105 ) ;
if ( V_81 )
V_110 = F_2 ( V_81 , struct V_61 , V_81 ) -> V_80 ;
else if ( V_20 -> V_49 && V_20 -> V_49 -> V_81 . V_113 . V_105 == V_105 )
for ( V_64 = 0 ; V_64 < V_20 -> V_49 -> V_74 ; V_64 ++ )
V_110 += V_20 -> V_49 -> V_75 [ V_64 ] . V_79 ;
F_19 ( & V_20 -> V_4 . V_21 , V_48 ) ;
F_48 ( V_107 , V_110 ) ;
if ( V_109 == V_114 && V_20 -> V_85 )
V_109 = V_112 ;
return V_109 ;
}
static void F_49 ( struct V_1 * V_20 ,
enum V_25 V_26 )
{
struct V_6 * V_7 = V_20 -> V_7 ;
T_2 V_115 ;
if ( V_26 == V_38 )
V_115 = V_20 -> V_53 . V_116 ;
else
V_115 = V_20 -> V_53 . V_117 ;
F_6 ( V_115 , F_3 ( V_7 , 0 , V_118 ) ) ;
V_20 -> V_54 = 0 ;
}
static void F_50 ( struct V_1 * V_20 )
{
struct V_108 * V_81 = F_51 ( & V_20 -> V_4 ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
struct V_61 * V_62 ;
struct V_29 * V_65 ;
struct V_29 * V_119 = F_52 ( V_20 -> V_43 ,
sizeof( struct V_29 ) ) ;
F_5 ( & V_20 -> V_4 . V_21 ) ;
if ( ! V_81 )
return;
F_53 ( & V_81 -> V_82 ) ;
V_62 = F_2 ( V_81 , struct V_61 , V_81 ) ;
V_20 -> V_49 = V_62 ;
if ( ! V_20 -> V_24 )
F_8 ( V_20 , V_62 -> V_26 ) ;
if ( V_20 -> V_54 )
F_49 ( V_20 , V_62 -> V_26 ) ;
V_65 = V_20 -> V_49 -> V_75 ;
if ( V_62 -> V_74 > V_95 )
V_62 -> V_94 = V_95 ;
else
V_62 -> V_94 = V_62 -> V_74 ;
if ( V_62 -> V_74 == V_62 -> V_94 )
V_65 [ V_62 -> V_94 - 1 ] . V_48 =
F_30 ( V_62 -> V_48 ) ;
else
V_65 [ V_62 -> V_94 - 1 ] . V_48 |=
F_30 ( V_73 ) ;
if ( V_20 -> V_42 + V_62 -> V_94 > V_95 ) {
T_2 V_120 = V_95 - V_20 -> V_42 ;
memcpy ( & V_119 [ V_20 -> V_42 ] , V_65 ,
V_120 * sizeof( struct V_29 ) ) ;
memcpy ( V_119 , & V_65 [ V_120 ] , ( V_62 -> V_94 - V_120 ) *
sizeof( struct V_29 ) ) ;
} else {
memcpy ( & V_119 [ V_20 -> V_42 ] , V_65 ,
V_62 -> V_94 * sizeof( struct V_29 ) ) ;
}
V_20 -> V_42 += V_62 -> V_94 ;
V_20 -> V_42 %= V_95 ;
F_7 () ;
F_6 ( V_20 -> V_42 * sizeof( struct V_29 ) ,
F_3 ( V_7 , V_20 -> V_22 , V_121 ) ) ;
}
static void F_54 ( unsigned long V_97 )
{
struct V_6 * V_7 = (struct V_6 * ) V_97 ;
struct V_1 * V_20 ;
unsigned long V_48 ;
unsigned int V_64 ;
for ( V_64 = 0 ; V_64 < V_7 -> V_90 ; V_64 ++ ) {
V_20 = & V_7 -> V_91 [ V_64 ] ;
F_18 ( & V_20 -> V_4 . V_21 , V_48 ) ;
if ( ! F_55 ( & V_20 -> V_4 . V_83 ) && ! V_20 -> V_49 )
F_50 ( V_20 ) ;
F_19 ( & V_20 -> V_4 . V_21 , V_48 ) ;
}
}
static void F_56 ( struct V_2 * V_5 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
unsigned long V_48 ;
F_18 ( & V_20 -> V_4 . V_21 , V_48 ) ;
if ( F_57 ( & V_20 -> V_4 ) && ! V_20 -> V_49 )
F_50 ( V_20 ) ;
F_19 ( & V_20 -> V_4 . V_21 , V_48 ) ;
}
static void F_58 ( struct V_108 * V_81 )
{
struct V_61 * V_62 = F_2 ( V_81 ,
struct V_61 , V_81 ) ;
F_32 ( V_62 ) ;
}
static struct V_2 * F_59 ( struct V_122 * V_123 ,
struct V_124 * V_125 )
{
struct V_6 * V_7 = F_2 ( V_125 -> V_126 ,
struct V_6 , V_3 ) ;
unsigned int V_127 ;
if ( V_123 -> V_128 != 1 )
return NULL ;
V_127 = V_123 -> args [ 0 ] ;
if ( V_127 >= V_7 -> V_90 )
return NULL ;
return F_60 ( & ( V_7 -> V_91 [ V_127 ] . V_4 . V_5 ) ) ;
}
static int F_61 ( struct V_6 * V_7 )
{
T_2 V_27 ;
V_27 = F_10 ( F_3 ( V_7 , 0 , V_129 ) ) >> V_130 ;
V_27 &= V_131 ;
if ( V_7 -> V_19 >= V_27 )
return - V_132 ;
V_27 = F_10 ( F_3 ( V_7 , 0 , V_133 ) ) ;
V_7 -> V_90 = V_27 & V_134 ;
if ( V_7 -> V_135 )
return 0 ;
V_27 = F_10 ( F_3 ( V_7 , 0 , V_136 ) ) ;
V_27 |= V_137 ;
F_6 ( V_27 , F_3 ( V_7 , 0 , V_136 ) ) ;
V_27 &= ~ V_137 ;
F_6 ( V_27 , F_3 ( V_7 , 0 , V_136 ) ) ;
F_7 () ;
V_27 |= V_138 ;
F_6 ( V_27 , F_3 ( V_7 , 0 , V_136 ) ) ;
F_6 ( V_139 ,
F_3 ( V_7 , 0 , V_118 ) ) ;
F_6 ( V_140 , F_3 ( V_7 , 0 , V_141 ) ) ;
F_6 ( V_142 | V_143 ,
F_3 ( V_7 , 0 , V_144 ) ) ;
F_6 ( V_145 , F_3 ( V_7 , 0 , V_35 ) ) ;
return 0 ;
}
static void F_62 ( struct V_6 * V_7 , struct V_1 * V_20 ,
T_2 V_146 )
{
V_20 -> V_22 = V_146 ;
V_20 -> V_7 = V_7 ;
F_63 ( & V_20 -> V_4 , & V_7 -> V_3 ) ;
V_20 -> V_4 . V_147 = F_58 ;
}
static int F_64 ( struct V_148 * V_149 )
{
struct V_6 * V_7 ;
const struct V_150 * V_151 ;
struct V_152 * V_153 ;
int V_109 , V_64 ;
V_7 = F_65 ( & V_149 -> V_44 , sizeof( * V_7 ) , V_46 ) ;
if ( ! V_7 )
return - V_47 ;
V_7 -> V_44 = & V_149 -> V_44 ;
V_151 = F_66 ( V_154 , V_149 -> V_44 . V_155 ) ;
if ( ! V_151 ) {
F_14 ( & V_149 -> V_44 , L_4 ) ;
return - V_156 ;
}
V_7 -> V_13 = V_151 -> V_97 ;
V_153 = F_67 ( V_149 , V_157 , 0 ) ;
V_7 -> V_14 = F_68 ( & V_149 -> V_44 , V_153 ) ;
if ( F_69 ( V_7 -> V_14 ) )
return F_70 ( V_7 -> V_14 ) ;
V_7 -> V_96 = F_71 ( V_149 , 0 ) ;
if ( V_7 -> V_96 < 0 )
return V_7 -> V_96 ;
V_109 = F_72 ( V_149 -> V_44 . V_155 , L_5 , & V_7 -> V_19 ) ;
if ( V_109 ) {
F_14 ( V_7 -> V_44 , L_6 ) ;
return V_109 ;
}
V_7 -> V_135 = F_73 ( V_149 -> V_44 . V_155 ,
L_7 ) ;
V_7 -> V_158 = F_74 ( V_7 -> V_44 , L_8 ) ;
if ( F_69 ( V_7 -> V_158 ) )
return F_70 ( V_7 -> V_158 ) ;
V_109 = F_75 ( V_7 -> V_158 ) ;
if ( V_109 ) {
F_14 ( V_7 -> V_44 , L_9 ) ;
return V_109 ;
}
V_109 = F_61 ( V_7 ) ;
if ( V_109 )
goto V_159;
F_76 ( & V_7 -> V_99 , F_54 , ( unsigned long ) V_7 ) ;
V_7 -> V_91 = F_77 ( V_7 -> V_44 , V_7 -> V_90 ,
sizeof( * V_7 -> V_91 ) , V_46 ) ;
if ( ! V_7 -> V_91 ) {
V_109 = - V_47 ;
goto V_160;
}
F_78 ( & V_7 -> V_3 . V_91 ) ;
for ( V_64 = 0 ; V_64 < V_7 -> V_90 ; V_64 ++ )
F_62 ( V_7 , & V_7 -> V_91 [ V_64 ] , V_64 ) ;
V_109 = F_79 ( V_7 -> V_44 , V_7 -> V_96 , F_42 ,
V_161 , L_10 , V_7 ) ;
if ( V_109 )
goto V_162;
V_7 -> V_3 . V_44 = V_7 -> V_44 ;
V_7 -> V_3 . V_44 -> V_163 = & V_7 -> V_163 ;
V_109 = F_80 ( V_7 -> V_3 . V_44 , V_31 ) ;
if ( V_109 ) {
F_14 ( V_7 -> V_44 , L_11 ) ;
goto V_162;
}
F_81 ( V_149 , V_7 ) ;
F_82 ( V_7 -> V_3 . V_164 ) ;
F_83 ( V_165 , V_7 -> V_3 . V_164 ) ;
V_7 -> V_3 . V_166 = F_11 ( V_38 ) | F_11 ( V_167 ) ;
V_7 -> V_3 . V_168 = V_169 ;
V_7 -> V_3 . V_170 = V_171 ;
V_7 -> V_3 . V_172 = V_171 ;
V_7 -> V_3 . V_173 = F_12 ;
V_7 -> V_3 . V_174 = F_15 ;
V_7 -> V_3 . V_175 = F_22 ;
V_7 -> V_3 . V_176 = F_21 ;
V_7 -> V_3 . V_177 = F_38 ;
V_7 -> V_3 . V_178 = F_39 ;
V_7 -> V_3 . V_179 = F_33 ;
V_7 -> V_3 . V_180 = F_56 ;
V_7 -> V_3 . V_181 = F_45 ;
V_7 -> V_3 . V_44 = V_7 -> V_44 ;
V_109 = F_84 ( & V_7 -> V_3 ) ;
if ( V_109 ) {
F_14 ( V_7 -> V_44 , L_12 ) ;
goto V_162;
}
V_109 = F_85 ( V_149 -> V_44 . V_155 , F_59 ,
& V_7 -> V_3 ) ;
if ( V_109 )
goto V_182;
return 0 ;
V_182:
F_86 ( & V_7 -> V_3 ) ;
V_162:
for ( V_64 = 0 ; V_64 < V_7 -> V_90 ; V_64 ++ )
F_87 ( & V_7 -> V_91 [ V_64 ] . V_4 . V_99 ) ;
V_160:
F_87 ( & V_7 -> V_99 ) ;
V_159:
F_88 ( V_7 -> V_158 ) ;
return V_109 ;
}
static int F_89 ( struct V_148 * V_149 )
{
struct V_6 * V_7 = F_90 ( V_149 ) ;
T_2 V_64 ;
F_91 ( V_149 -> V_44 . V_155 ) ;
F_86 ( & V_7 -> V_3 ) ;
F_6 ( 0 , F_3 ( V_7 , 0 , V_35 ) ) ;
F_92 ( V_7 -> V_44 , V_7 -> V_96 , V_7 ) ;
for ( V_64 = 0 ; V_64 < V_7 -> V_90 ; V_64 ++ ) {
F_33 ( & V_7 -> V_91 [ V_64 ] . V_4 . V_5 ) ;
F_87 ( & V_7 -> V_91 [ V_64 ] . V_4 . V_99 ) ;
if ( ! V_7 -> V_91 [ V_64 ] . V_43 )
continue;
F_20 ( V_7 -> V_44 , V_45 ,
V_7 -> V_91 [ V_64 ] . V_43 ,
V_7 -> V_91 [ V_64 ] . V_28 ) ;
}
F_87 ( & V_7 -> V_99 ) ;
F_88 ( V_7 -> V_158 ) ;
return 0 ;
}
