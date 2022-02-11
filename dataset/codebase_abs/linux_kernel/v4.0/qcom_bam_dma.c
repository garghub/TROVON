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
V_20 -> V_43 = F_13 ( V_7 -> V_44 , V_31 ,
& V_20 -> V_28 , V_45 ) ;
if ( ! V_20 -> V_43 ) {
F_14 ( V_7 -> V_44 , L_1 ) ;
return - V_46 ;
}
return 0 ;
}
static void F_15 ( struct V_2 * V_5 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
T_2 V_27 ;
unsigned long V_47 ;
F_16 ( F_17 ( V_5 ) ) ;
if ( V_20 -> V_48 ) {
F_14 ( V_20 -> V_7 -> V_44 , L_2 ) ;
return;
}
F_18 ( & V_20 -> V_4 . V_21 , V_47 ) ;
F_4 ( V_20 ) ;
F_19 ( & V_20 -> V_4 . V_21 , V_47 ) ;
F_20 ( V_7 -> V_44 , V_31 , V_20 -> V_43 ,
V_20 -> V_28 ) ;
V_20 -> V_43 = NULL ;
V_27 = F_10 ( F_3 ( V_7 , 0 , V_35 ) ) ;
V_27 &= ~ F_11 ( V_20 -> V_22 ) ;
F_6 ( V_27 , F_3 ( V_7 , 0 , V_35 ) ) ;
F_6 ( 0 , F_3 ( V_7 , V_20 -> V_22 , V_34 ) ) ;
}
static int F_21 ( struct V_2 * V_5 ,
struct V_49 * V_50 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
unsigned long V_51 ;
F_18 ( & V_20 -> V_4 . V_21 , V_51 ) ;
memcpy ( & V_20 -> V_52 , V_50 , sizeof( * V_50 ) ) ;
V_20 -> V_53 = 1 ;
F_19 ( & V_20 -> V_4 . V_21 , V_51 ) ;
return 0 ;
}
static struct V_54 * F_22 ( struct V_2 * V_5 ,
struct V_55 * V_56 , unsigned int V_57 ,
enum V_25 V_58 , unsigned long V_47 ,
void * V_59 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
struct V_60 * V_61 ;
struct V_55 * V_62 ;
T_2 V_63 ;
struct V_29 * V_64 ;
unsigned int V_65 = 0 ;
if ( ! F_23 ( V_58 ) ) {
F_14 ( V_7 -> V_44 , L_3 ) ;
return NULL ;
}
F_24 (sgl, sg, sg_len, i)
V_65 += F_25 ( F_26 ( V_62 ) , V_66 ) ;
V_61 = F_27 ( sizeof( * V_61 ) +
( V_65 * sizeof( struct V_29 ) ) , V_67 ) ;
if ( ! V_61 )
goto V_68;
if ( V_47 & V_69 )
V_61 -> V_47 |= V_70 ;
if ( V_47 & V_71 )
V_61 -> V_47 |= V_72 ;
else
V_61 -> V_47 |= V_73 ;
V_61 -> V_74 = V_65 ;
V_61 -> V_75 = V_61 -> V_64 ;
V_61 -> V_26 = V_58 ;
V_64 = V_61 -> V_64 ;
F_24 (sgl, sg, sg_len, i) {
unsigned int V_76 = F_26 ( V_62 ) ;
unsigned int V_77 = 0 ;
do {
V_64 -> V_78 = F_28 ( V_62 ) + V_77 ;
if ( V_76 > V_66 ) {
V_64 -> V_79 = V_66 ;
V_76 -= V_66 ;
V_77 += V_66 ;
} else {
V_64 -> V_79 = V_76 ;
V_76 = 0 ;
}
V_61 -> V_80 += V_64 -> V_79 ;
V_64 ++ ;
} while ( V_76 > 0 );
}
return F_29 ( & V_20 -> V_4 , & V_61 -> V_81 , V_47 ) ;
V_68:
F_30 ( V_61 ) ;
return NULL ;
}
static int F_31 ( struct V_2 * V_5 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
unsigned long V_51 ;
F_32 ( V_41 ) ;
F_18 ( & V_20 -> V_4 . V_21 , V_51 ) ;
if ( V_20 -> V_48 ) {
F_33 ( & V_20 -> V_48 -> V_81 . V_82 , & V_20 -> V_4 . V_83 ) ;
V_20 -> V_48 = NULL ;
}
F_34 ( & V_20 -> V_4 , & V_41 ) ;
F_19 ( & V_20 -> V_4 . V_21 , V_51 ) ;
F_35 ( & V_20 -> V_4 , & V_41 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_5 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
unsigned long V_51 ;
F_18 ( & V_20 -> V_4 . V_21 , V_51 ) ;
F_6 ( 1 , F_3 ( V_7 , V_20 -> V_22 , V_84 ) ) ;
V_20 -> V_85 = 1 ;
F_19 ( & V_20 -> V_4 . V_21 , V_51 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_5 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
unsigned long V_51 ;
F_18 ( & V_20 -> V_4 . V_21 , V_51 ) ;
F_6 ( 0 , F_3 ( V_7 , V_20 -> V_22 , V_84 ) ) ;
V_20 -> V_85 = 0 ;
F_19 ( & V_20 -> V_4 . V_21 , V_51 ) ;
return 0 ;
}
static T_2 F_38 ( struct V_6 * V_7 )
{
T_2 V_63 , V_86 , V_87 ;
unsigned long V_47 ;
struct V_60 * V_61 ;
V_86 = F_10 ( F_3 ( V_7 , 0 , V_88 ) ) ;
if ( ! ( V_86 & V_89 ) )
return V_86 ;
for ( V_63 = 0 ; V_63 < V_7 -> V_90 ; V_63 ++ ) {
struct V_1 * V_20 = & V_7 -> V_91 [ V_63 ] ;
if ( ! ( V_86 & F_11 ( V_63 ) ) )
continue;
V_87 = F_10 ( F_3 ( V_7 , V_63 , V_92 ) ) ;
F_6 ( V_87 , F_3 ( V_7 , V_63 , V_93 ) ) ;
F_18 ( & V_20 -> V_4 . V_21 , V_47 ) ;
V_61 = V_20 -> V_48 ;
if ( V_61 ) {
V_61 -> V_74 -= V_61 -> V_94 ;
V_61 -> V_75 += V_61 -> V_94 ;
V_20 -> V_48 = NULL ;
V_20 -> V_41 += V_61 -> V_94 ;
V_20 -> V_41 %= V_95 ;
if ( ! V_61 -> V_74 )
F_39 ( & V_61 -> V_81 ) ;
else
F_33 ( & V_61 -> V_81 . V_82 ,
& V_20 -> V_4 . V_83 ) ;
}
F_19 ( & V_20 -> V_4 . V_21 , V_47 ) ;
}
return V_86 ;
}
static T_3 F_40 ( int V_96 , void * V_97 )
{
struct V_6 * V_7 = V_97 ;
T_2 V_98 = 0 , V_86 = 0 ;
V_86 |= F_38 ( V_7 ) ;
if ( V_86 & V_89 )
F_41 ( & V_7 -> V_99 ) ;
if ( V_86 & V_100 )
V_98 = F_10 ( F_3 ( V_7 , 0 , V_101 ) ) ;
F_42 () ;
F_6 ( V_98 , F_3 ( V_7 , 0 , V_102 ) ) ;
return V_103 ;
}
static enum V_104 F_43 ( struct V_2 * V_5 , T_4 V_105 ,
struct V_106 * V_107 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
struct V_108 * V_81 ;
int V_109 ;
T_5 V_110 = 0 ;
unsigned int V_63 ;
unsigned long V_47 ;
V_109 = F_44 ( V_5 , V_105 , V_107 ) ;
if ( V_109 == V_111 )
return V_109 ;
if ( ! V_107 )
return V_20 -> V_85 ? V_112 : V_109 ;
F_18 ( & V_20 -> V_4 . V_21 , V_47 ) ;
V_81 = F_45 ( & V_20 -> V_4 , V_105 ) ;
if ( V_81 )
V_110 = F_2 ( V_81 , struct V_60 , V_81 ) -> V_80 ;
else if ( V_20 -> V_48 && V_20 -> V_48 -> V_81 . V_113 . V_105 == V_105 )
for ( V_63 = 0 ; V_63 < V_20 -> V_48 -> V_74 ; V_63 ++ )
V_110 += V_20 -> V_48 -> V_75 [ V_63 ] . V_79 ;
F_19 ( & V_20 -> V_4 . V_21 , V_47 ) ;
F_46 ( V_107 , V_110 ) ;
if ( V_109 == V_114 && V_20 -> V_85 )
V_109 = V_112 ;
return V_109 ;
}
static void F_47 ( struct V_1 * V_20 ,
enum V_25 V_26 )
{
struct V_6 * V_7 = V_20 -> V_7 ;
T_2 V_115 ;
if ( V_26 == V_38 )
V_115 = V_20 -> V_52 . V_116 ;
else
V_115 = V_20 -> V_52 . V_117 ;
F_6 ( V_115 , F_3 ( V_7 , 0 , V_118 ) ) ;
V_20 -> V_53 = 0 ;
}
static void F_48 ( struct V_1 * V_20 )
{
struct V_108 * V_81 = F_49 ( & V_20 -> V_4 ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
struct V_60 * V_61 ;
struct V_29 * V_64 ;
struct V_29 * V_119 = F_50 ( V_20 -> V_43 ,
sizeof( struct V_29 ) ) ;
F_5 ( & V_20 -> V_4 . V_21 ) ;
if ( ! V_81 )
return;
F_51 ( & V_81 -> V_82 ) ;
V_61 = F_2 ( V_81 , struct V_60 , V_81 ) ;
V_20 -> V_48 = V_61 ;
if ( ! V_20 -> V_24 )
F_8 ( V_20 , V_61 -> V_26 ) ;
if ( V_20 -> V_53 )
F_47 ( V_20 , V_61 -> V_26 ) ;
V_64 = V_20 -> V_48 -> V_75 ;
if ( V_61 -> V_74 > V_95 )
V_61 -> V_94 = V_95 ;
else
V_61 -> V_94 = V_61 -> V_74 ;
if ( V_61 -> V_74 == V_61 -> V_94 )
V_64 [ V_61 -> V_94 - 1 ] . V_47 = V_61 -> V_47 ;
else
V_64 [ V_61 -> V_94 - 1 ] . V_47 |= V_73 ;
if ( V_20 -> V_42 + V_61 -> V_94 > V_95 ) {
T_2 V_120 = V_95 - V_20 -> V_42 ;
memcpy ( & V_119 [ V_20 -> V_42 ] , V_64 ,
V_120 * sizeof( struct V_29 ) ) ;
memcpy ( V_119 , & V_64 [ V_120 ] , ( V_61 -> V_94 - V_120 ) *
sizeof( struct V_29 ) ) ;
} else {
memcpy ( & V_119 [ V_20 -> V_42 ] , V_64 ,
V_61 -> V_94 * sizeof( struct V_29 ) ) ;
}
V_20 -> V_42 += V_61 -> V_94 ;
V_20 -> V_42 %= V_95 ;
F_7 () ;
F_6 ( V_20 -> V_42 * sizeof( struct V_29 ) ,
F_3 ( V_7 , V_20 -> V_22 , V_121 ) ) ;
}
static void F_52 ( unsigned long V_97 )
{
struct V_6 * V_7 = (struct V_6 * ) V_97 ;
struct V_1 * V_20 ;
unsigned long V_47 ;
unsigned int V_63 ;
for ( V_63 = 0 ; V_63 < V_7 -> V_90 ; V_63 ++ ) {
V_20 = & V_7 -> V_91 [ V_63 ] ;
F_18 ( & V_20 -> V_4 . V_21 , V_47 ) ;
if ( ! F_53 ( & V_20 -> V_4 . V_83 ) && ! V_20 -> V_48 )
F_48 ( V_20 ) ;
F_19 ( & V_20 -> V_4 . V_21 , V_47 ) ;
}
}
static void F_54 ( struct V_2 * V_5 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
unsigned long V_47 ;
F_18 ( & V_20 -> V_4 . V_21 , V_47 ) ;
if ( F_55 ( & V_20 -> V_4 ) && ! V_20 -> V_48 )
F_48 ( V_20 ) ;
F_19 ( & V_20 -> V_4 . V_21 , V_47 ) ;
}
static void F_56 ( struct V_108 * V_81 )
{
struct V_60 * V_61 = F_2 ( V_81 ,
struct V_60 , V_81 ) ;
F_30 ( V_61 ) ;
}
static struct V_2 * F_57 ( struct V_122 * V_123 ,
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
return F_58 ( & ( V_7 -> V_91 [ V_127 ] . V_4 . V_5 ) ) ;
}
static int F_59 ( struct V_6 * V_7 )
{
T_2 V_27 ;
V_27 = F_10 ( F_3 ( V_7 , 0 , V_129 ) ) >> V_130 ;
V_27 &= V_131 ;
if ( V_7 -> V_19 >= V_27 )
return - V_132 ;
V_27 = F_10 ( F_3 ( V_7 , 0 , V_133 ) ) ;
V_7 -> V_90 = V_27 & V_134 ;
V_27 = F_10 ( F_3 ( V_7 , 0 , V_135 ) ) ;
V_27 |= V_136 ;
F_6 ( V_27 , F_3 ( V_7 , 0 , V_135 ) ) ;
V_27 &= ~ V_136 ;
F_6 ( V_27 , F_3 ( V_7 , 0 , V_135 ) ) ;
F_7 () ;
V_27 |= V_137 ;
F_6 ( V_27 , F_3 ( V_7 , 0 , V_135 ) ) ;
F_6 ( V_138 ,
F_3 ( V_7 , 0 , V_118 ) ) ;
F_6 ( V_139 , F_3 ( V_7 , 0 , V_140 ) ) ;
F_6 ( V_141 | V_142 ,
F_3 ( V_7 , 0 , V_143 ) ) ;
F_6 ( V_144 , F_3 ( V_7 , 0 , V_35 ) ) ;
return 0 ;
}
static void F_60 ( struct V_6 * V_7 , struct V_1 * V_20 ,
T_2 V_145 )
{
V_20 -> V_22 = V_145 ;
V_20 -> V_7 = V_7 ;
F_61 ( & V_20 -> V_4 , & V_7 -> V_3 ) ;
V_20 -> V_4 . V_146 = F_56 ;
}
static int F_62 ( struct V_147 * V_148 )
{
struct V_6 * V_7 ;
const struct V_149 * V_150 ;
struct V_151 * V_152 ;
int V_109 , V_63 ;
V_7 = F_63 ( & V_148 -> V_44 , sizeof( * V_7 ) , V_45 ) ;
if ( ! V_7 )
return - V_46 ;
V_7 -> V_44 = & V_148 -> V_44 ;
V_150 = F_64 ( V_153 , V_148 -> V_44 . V_154 ) ;
if ( ! V_150 ) {
F_14 ( & V_148 -> V_44 , L_4 ) ;
return - V_155 ;
}
V_7 -> V_13 = V_150 -> V_97 ;
V_152 = F_65 ( V_148 , V_156 , 0 ) ;
V_7 -> V_14 = F_66 ( & V_148 -> V_44 , V_152 ) ;
if ( F_67 ( V_7 -> V_14 ) )
return F_68 ( V_7 -> V_14 ) ;
V_7 -> V_96 = F_69 ( V_148 , 0 ) ;
if ( V_7 -> V_96 < 0 )
return V_7 -> V_96 ;
V_109 = F_70 ( V_148 -> V_44 . V_154 , L_5 , & V_7 -> V_19 ) ;
if ( V_109 ) {
F_14 ( V_7 -> V_44 , L_6 ) ;
return V_109 ;
}
V_7 -> V_157 = F_71 ( V_7 -> V_44 , L_7 ) ;
if ( F_67 ( V_7 -> V_157 ) )
return F_68 ( V_7 -> V_157 ) ;
V_109 = F_72 ( V_7 -> V_157 ) ;
if ( V_109 ) {
F_14 ( V_7 -> V_44 , L_8 ) ;
return V_109 ;
}
V_109 = F_59 ( V_7 ) ;
if ( V_109 )
goto V_158;
F_73 ( & V_7 -> V_99 , F_52 , ( unsigned long ) V_7 ) ;
V_7 -> V_91 = F_74 ( V_7 -> V_44 , V_7 -> V_90 ,
sizeof( * V_7 -> V_91 ) , V_45 ) ;
if ( ! V_7 -> V_91 ) {
V_109 = - V_46 ;
goto V_158;
}
F_75 ( & V_7 -> V_3 . V_91 ) ;
for ( V_63 = 0 ; V_63 < V_7 -> V_90 ; V_63 ++ )
F_60 ( V_7 , & V_7 -> V_91 [ V_63 ] , V_63 ) ;
V_109 = F_76 ( V_7 -> V_44 , V_7 -> V_96 , F_40 ,
V_159 , L_9 , V_7 ) ;
if ( V_109 )
goto V_158;
V_7 -> V_3 . V_44 = V_7 -> V_44 ;
V_7 -> V_3 . V_44 -> V_160 = & V_7 -> V_160 ;
V_109 = F_77 ( V_7 -> V_3 . V_44 , V_66 ) ;
if ( V_109 ) {
F_14 ( V_7 -> V_44 , L_10 ) ;
goto V_158;
}
F_78 ( V_148 , V_7 ) ;
F_79 ( V_7 -> V_3 . V_161 ) ;
F_80 ( V_162 , V_7 -> V_3 . V_161 ) ;
V_7 -> V_3 . V_163 = F_11 ( V_38 ) | F_11 ( V_164 ) ;
V_7 -> V_3 . V_165 = V_166 ;
V_7 -> V_3 . V_167 = V_168 ;
V_7 -> V_3 . V_169 = V_168 ;
V_7 -> V_3 . V_170 = F_12 ;
V_7 -> V_3 . V_171 = F_15 ;
V_7 -> V_3 . V_172 = F_22 ;
V_7 -> V_3 . V_173 = F_21 ;
V_7 -> V_3 . V_174 = F_36 ;
V_7 -> V_3 . V_175 = F_37 ;
V_7 -> V_3 . V_176 = F_31 ;
V_7 -> V_3 . V_177 = F_54 ;
V_7 -> V_3 . V_178 = F_43 ;
V_7 -> V_3 . V_44 = V_7 -> V_44 ;
V_109 = F_81 ( & V_7 -> V_3 ) ;
if ( V_109 ) {
F_14 ( V_7 -> V_44 , L_11 ) ;
goto V_158;
}
V_109 = F_82 ( V_148 -> V_44 . V_154 , F_57 ,
& V_7 -> V_3 ) ;
if ( V_109 )
goto V_179;
return 0 ;
V_179:
F_83 ( & V_7 -> V_3 ) ;
V_158:
F_84 ( V_7 -> V_157 ) ;
return V_109 ;
}
static int F_85 ( struct V_147 * V_148 )
{
struct V_6 * V_7 = F_86 ( V_148 ) ;
T_2 V_63 ;
F_87 ( V_148 -> V_44 . V_154 ) ;
F_83 ( & V_7 -> V_3 ) ;
F_6 ( 0 , F_3 ( V_7 , 0 , V_35 ) ) ;
F_88 ( V_7 -> V_44 , V_7 -> V_96 , V_7 ) ;
for ( V_63 = 0 ; V_63 < V_7 -> V_90 ; V_63 ++ ) {
F_31 ( & V_7 -> V_91 [ V_63 ] . V_4 . V_5 ) ;
F_89 ( & V_7 -> V_91 [ V_63 ] . V_4 . V_99 ) ;
F_20 ( V_7 -> V_44 , V_31 ,
V_7 -> V_91 [ V_63 ] . V_43 ,
V_7 -> V_91 [ V_63 ] . V_28 ) ;
}
F_89 ( & V_7 -> V_99 ) ;
F_84 ( V_7 -> V_157 ) ;
return 0 ;
}
