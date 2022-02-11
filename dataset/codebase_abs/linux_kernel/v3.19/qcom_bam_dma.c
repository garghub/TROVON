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
static void F_21 ( struct V_1 * V_20 ,
struct V_49 * V_50 )
{
memcpy ( & V_20 -> V_51 , V_50 , sizeof( * V_50 ) ) ;
V_20 -> V_52 = 1 ;
}
static struct V_53 * F_22 ( struct V_2 * V_5 ,
struct V_54 * V_55 , unsigned int V_56 ,
enum V_25 V_57 , unsigned long V_47 ,
void * V_58 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
struct V_59 * V_60 ;
struct V_54 * V_61 ;
T_2 V_62 ;
struct V_29 * V_63 ;
unsigned int V_64 = 0 ;
if ( ! F_23 ( V_57 ) ) {
F_14 ( V_7 -> V_44 , L_3 ) ;
return NULL ;
}
F_24 (sgl, sg, sg_len, i)
V_64 += F_25 ( F_26 ( V_61 ) , V_65 ) ;
V_60 = F_27 ( sizeof( * V_60 ) +
( V_64 * sizeof( struct V_29 ) ) , V_66 ) ;
if ( ! V_60 )
goto V_67;
if ( V_47 & V_68 )
V_60 -> V_47 |= V_69 ;
if ( V_47 & V_70 )
V_60 -> V_47 |= V_71 ;
else
V_60 -> V_47 |= V_72 ;
V_60 -> V_73 = V_64 ;
V_60 -> V_74 = V_60 -> V_63 ;
V_60 -> V_26 = V_57 ;
V_63 = V_60 -> V_63 ;
F_24 (sgl, sg, sg_len, i) {
unsigned int V_75 = F_26 ( V_61 ) ;
unsigned int V_76 = 0 ;
do {
V_63 -> V_77 = F_28 ( V_61 ) + V_76 ;
if ( V_75 > V_65 ) {
V_63 -> V_78 = V_65 ;
V_75 -= V_65 ;
V_76 += V_65 ;
} else {
V_63 -> V_78 = V_75 ;
V_75 = 0 ;
}
V_60 -> V_79 += V_63 -> V_78 ;
V_63 ++ ;
} while ( V_75 > 0 );
}
return F_29 ( & V_20 -> V_4 , & V_60 -> V_80 , V_47 ) ;
V_67:
F_30 ( V_60 ) ;
return NULL ;
}
static void F_31 ( struct V_1 * V_20 )
{
unsigned long V_81 ;
F_32 ( V_41 ) ;
F_18 ( & V_20 -> V_4 . V_21 , V_81 ) ;
if ( V_20 -> V_48 ) {
F_33 ( & V_20 -> V_48 -> V_80 . V_82 , & V_20 -> V_4 . V_83 ) ;
V_20 -> V_48 = NULL ;
}
F_34 ( & V_20 -> V_4 , & V_41 ) ;
F_19 ( & V_20 -> V_4 . V_21 , V_81 ) ;
F_35 ( & V_20 -> V_4 , & V_41 ) ;
}
static int F_36 ( struct V_2 * V_5 , enum V_84 V_85 ,
unsigned long V_86 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
int V_87 = 0 ;
unsigned long V_81 ;
switch ( V_85 ) {
case V_88 :
F_18 ( & V_20 -> V_4 . V_21 , V_81 ) ;
F_6 ( 1 , F_3 ( V_7 , V_20 -> V_22 , V_89 ) ) ;
V_20 -> V_90 = 1 ;
F_19 ( & V_20 -> V_4 . V_21 , V_81 ) ;
break;
case V_91 :
F_18 ( & V_20 -> V_4 . V_21 , V_81 ) ;
F_6 ( 0 , F_3 ( V_7 , V_20 -> V_22 , V_89 ) ) ;
V_20 -> V_90 = 0 ;
F_19 ( & V_20 -> V_4 . V_21 , V_81 ) ;
break;
case V_92 :
F_31 ( V_20 ) ;
break;
case V_93 :
F_18 ( & V_20 -> V_4 . V_21 , V_81 ) ;
F_21 ( V_20 , (struct V_49 * ) V_86 ) ;
F_19 ( & V_20 -> V_4 . V_21 , V_81 ) ;
break;
default:
V_87 = - V_94 ;
break;
}
return V_87 ;
}
static T_2 F_37 ( struct V_6 * V_7 )
{
T_2 V_62 , V_95 , V_96 ;
unsigned long V_47 ;
struct V_59 * V_60 ;
V_95 = F_10 ( F_3 ( V_7 , 0 , V_97 ) ) ;
if ( ! ( V_95 & V_98 ) )
return V_95 ;
for ( V_62 = 0 ; V_62 < V_7 -> V_99 ; V_62 ++ ) {
struct V_1 * V_20 = & V_7 -> V_100 [ V_62 ] ;
if ( ! ( V_95 & F_11 ( V_62 ) ) )
continue;
V_96 = F_10 ( F_3 ( V_7 , V_62 , V_101 ) ) ;
F_6 ( V_96 , F_3 ( V_7 , V_62 , V_102 ) ) ;
F_18 ( & V_20 -> V_4 . V_21 , V_47 ) ;
V_60 = V_20 -> V_48 ;
if ( V_60 ) {
V_60 -> V_73 -= V_60 -> V_103 ;
V_60 -> V_74 += V_60 -> V_103 ;
V_20 -> V_48 = NULL ;
V_20 -> V_41 += V_60 -> V_103 ;
V_20 -> V_41 %= V_104 ;
if ( ! V_60 -> V_73 )
F_38 ( & V_60 -> V_80 ) ;
else
F_33 ( & V_60 -> V_80 . V_82 ,
& V_20 -> V_4 . V_83 ) ;
}
F_19 ( & V_20 -> V_4 . V_21 , V_47 ) ;
}
return V_95 ;
}
static T_3 F_39 ( int V_105 , void * V_106 )
{
struct V_6 * V_7 = V_106 ;
T_2 V_107 = 0 , V_95 = 0 ;
V_95 |= F_37 ( V_7 ) ;
if ( V_95 & V_98 )
F_40 ( & V_7 -> V_108 ) ;
if ( V_95 & V_109 )
V_107 = F_10 ( F_3 ( V_7 , 0 , V_110 ) ) ;
F_41 () ;
F_6 ( V_107 , F_3 ( V_7 , 0 , V_111 ) ) ;
return V_112 ;
}
static enum V_113 F_42 ( struct V_2 * V_5 , T_4 V_114 ,
struct V_115 * V_116 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
struct V_117 * V_80 ;
int V_87 ;
T_5 V_118 = 0 ;
unsigned int V_62 ;
unsigned long V_47 ;
V_87 = F_43 ( V_5 , V_114 , V_116 ) ;
if ( V_87 == V_119 )
return V_87 ;
if ( ! V_116 )
return V_20 -> V_90 ? V_120 : V_87 ;
F_18 ( & V_20 -> V_4 . V_21 , V_47 ) ;
V_80 = F_44 ( & V_20 -> V_4 , V_114 ) ;
if ( V_80 )
V_118 = F_2 ( V_80 , struct V_59 , V_80 ) -> V_79 ;
else if ( V_20 -> V_48 && V_20 -> V_48 -> V_80 . V_121 . V_114 == V_114 )
for ( V_62 = 0 ; V_62 < V_20 -> V_48 -> V_73 ; V_62 ++ )
V_118 += V_20 -> V_48 -> V_74 [ V_62 ] . V_78 ;
F_19 ( & V_20 -> V_4 . V_21 , V_47 ) ;
F_45 ( V_116 , V_118 ) ;
if ( V_87 == V_122 && V_20 -> V_90 )
V_87 = V_120 ;
return V_87 ;
}
static void F_46 ( struct V_1 * V_20 ,
enum V_25 V_26 )
{
struct V_6 * V_7 = V_20 -> V_7 ;
T_2 V_123 ;
if ( V_26 == V_38 )
V_123 = V_20 -> V_51 . V_124 ;
else
V_123 = V_20 -> V_51 . V_125 ;
F_6 ( V_123 , F_3 ( V_7 , 0 , V_126 ) ) ;
V_20 -> V_52 = 0 ;
}
static void F_47 ( struct V_1 * V_20 )
{
struct V_117 * V_80 = F_48 ( & V_20 -> V_4 ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
struct V_59 * V_60 ;
struct V_29 * V_63 ;
struct V_29 * V_127 = F_49 ( V_20 -> V_43 ,
sizeof( struct V_29 ) ) ;
F_5 ( & V_20 -> V_4 . V_21 ) ;
if ( ! V_80 )
return;
F_50 ( & V_80 -> V_82 ) ;
V_60 = F_2 ( V_80 , struct V_59 , V_80 ) ;
V_20 -> V_48 = V_60 ;
if ( ! V_20 -> V_24 )
F_8 ( V_20 , V_60 -> V_26 ) ;
if ( V_20 -> V_52 )
F_46 ( V_20 , V_60 -> V_26 ) ;
V_63 = V_20 -> V_48 -> V_74 ;
if ( V_60 -> V_73 > V_104 )
V_60 -> V_103 = V_104 ;
else
V_60 -> V_103 = V_60 -> V_73 ;
if ( V_60 -> V_73 == V_60 -> V_103 )
V_63 [ V_60 -> V_103 - 1 ] . V_47 = V_60 -> V_47 ;
else
V_63 [ V_60 -> V_103 - 1 ] . V_47 |= V_72 ;
if ( V_20 -> V_42 + V_60 -> V_103 > V_104 ) {
T_2 V_128 = V_104 - V_20 -> V_42 ;
memcpy ( & V_127 [ V_20 -> V_42 ] , V_63 ,
V_128 * sizeof( struct V_29 ) ) ;
memcpy ( V_127 , & V_63 [ V_128 ] , ( V_60 -> V_103 - V_128 ) *
sizeof( struct V_29 ) ) ;
} else {
memcpy ( & V_127 [ V_20 -> V_42 ] , V_63 ,
V_60 -> V_103 * sizeof( struct V_29 ) ) ;
}
V_20 -> V_42 += V_60 -> V_103 ;
V_20 -> V_42 %= V_104 ;
F_7 () ;
F_6 ( V_20 -> V_42 * sizeof( struct V_29 ) ,
F_3 ( V_7 , V_20 -> V_22 , V_129 ) ) ;
}
static void F_51 ( unsigned long V_106 )
{
struct V_6 * V_7 = (struct V_6 * ) V_106 ;
struct V_1 * V_20 ;
unsigned long V_47 ;
unsigned int V_62 ;
for ( V_62 = 0 ; V_62 < V_7 -> V_99 ; V_62 ++ ) {
V_20 = & V_7 -> V_100 [ V_62 ] ;
F_18 ( & V_20 -> V_4 . V_21 , V_47 ) ;
if ( ! F_52 ( & V_20 -> V_4 . V_83 ) && ! V_20 -> V_48 )
F_47 ( V_20 ) ;
F_19 ( & V_20 -> V_4 . V_21 , V_47 ) ;
}
}
static void F_53 ( struct V_2 * V_5 )
{
struct V_1 * V_20 = F_1 ( V_5 ) ;
unsigned long V_47 ;
F_18 ( & V_20 -> V_4 . V_21 , V_47 ) ;
if ( F_54 ( & V_20 -> V_4 ) && ! V_20 -> V_48 )
F_47 ( V_20 ) ;
F_19 ( & V_20 -> V_4 . V_21 , V_47 ) ;
}
static void F_55 ( struct V_117 * V_80 )
{
struct V_59 * V_60 = F_2 ( V_80 ,
struct V_59 , V_80 ) ;
F_30 ( V_60 ) ;
}
static struct V_2 * F_56 ( struct V_130 * V_131 ,
struct V_132 * V_133 )
{
struct V_6 * V_7 = F_2 ( V_133 -> V_134 ,
struct V_6 , V_3 ) ;
unsigned int V_135 ;
if ( V_131 -> V_136 != 1 )
return NULL ;
V_135 = V_131 -> args [ 0 ] ;
if ( V_135 >= V_7 -> V_99 )
return NULL ;
return F_57 ( & ( V_7 -> V_100 [ V_135 ] . V_4 . V_5 ) ) ;
}
static int F_58 ( struct V_6 * V_7 )
{
T_2 V_27 ;
V_27 = F_10 ( F_3 ( V_7 , 0 , V_137 ) ) >> V_138 ;
V_27 &= V_139 ;
if ( V_7 -> V_19 >= V_27 )
return - V_140 ;
V_27 = F_10 ( F_3 ( V_7 , 0 , V_141 ) ) ;
V_7 -> V_99 = V_27 & V_142 ;
V_27 = F_10 ( F_3 ( V_7 , 0 , V_143 ) ) ;
V_27 |= V_144 ;
F_6 ( V_27 , F_3 ( V_7 , 0 , V_143 ) ) ;
V_27 &= ~ V_144 ;
F_6 ( V_27 , F_3 ( V_7 , 0 , V_143 ) ) ;
F_7 () ;
V_27 |= V_145 ;
F_6 ( V_27 , F_3 ( V_7 , 0 , V_143 ) ) ;
F_6 ( V_146 ,
F_3 ( V_7 , 0 , V_126 ) ) ;
F_6 ( V_147 , F_3 ( V_7 , 0 , V_148 ) ) ;
F_6 ( V_149 | V_150 ,
F_3 ( V_7 , 0 , V_151 ) ) ;
F_6 ( V_152 , F_3 ( V_7 , 0 , V_35 ) ) ;
return 0 ;
}
static void F_59 ( struct V_6 * V_7 , struct V_1 * V_20 ,
T_2 V_153 )
{
V_20 -> V_22 = V_153 ;
V_20 -> V_7 = V_7 ;
F_60 ( & V_20 -> V_4 , & V_7 -> V_3 ) ;
V_20 -> V_4 . V_154 = F_55 ;
}
static int F_61 ( struct V_155 * V_156 )
{
struct V_6 * V_7 ;
const struct V_157 * V_158 ;
struct V_159 * V_160 ;
int V_87 , V_62 ;
V_7 = F_62 ( & V_156 -> V_44 , sizeof( * V_7 ) , V_45 ) ;
if ( ! V_7 )
return - V_46 ;
V_7 -> V_44 = & V_156 -> V_44 ;
V_158 = F_63 ( V_161 , V_156 -> V_44 . V_162 ) ;
if ( ! V_158 ) {
F_14 ( & V_156 -> V_44 , L_4 ) ;
return - V_163 ;
}
V_7 -> V_13 = V_158 -> V_106 ;
V_160 = F_64 ( V_156 , V_164 , 0 ) ;
V_7 -> V_14 = F_65 ( & V_156 -> V_44 , V_160 ) ;
if ( F_66 ( V_7 -> V_14 ) )
return F_67 ( V_7 -> V_14 ) ;
V_7 -> V_105 = F_68 ( V_156 , 0 ) ;
if ( V_7 -> V_105 < 0 )
return V_7 -> V_105 ;
V_87 = F_69 ( V_156 -> V_44 . V_162 , L_5 , & V_7 -> V_19 ) ;
if ( V_87 ) {
F_14 ( V_7 -> V_44 , L_6 ) ;
return V_87 ;
}
V_7 -> V_165 = F_70 ( V_7 -> V_44 , L_7 ) ;
if ( F_66 ( V_7 -> V_165 ) )
return F_67 ( V_7 -> V_165 ) ;
V_87 = F_71 ( V_7 -> V_165 ) ;
if ( V_87 ) {
F_14 ( V_7 -> V_44 , L_8 ) ;
return V_87 ;
}
V_87 = F_58 ( V_7 ) ;
if ( V_87 )
goto V_166;
F_72 ( & V_7 -> V_108 , F_51 , ( unsigned long ) V_7 ) ;
V_7 -> V_100 = F_73 ( V_7 -> V_44 , V_7 -> V_99 ,
sizeof( * V_7 -> V_100 ) , V_45 ) ;
if ( ! V_7 -> V_100 ) {
V_87 = - V_46 ;
goto V_166;
}
F_74 ( & V_7 -> V_3 . V_100 ) ;
for ( V_62 = 0 ; V_62 < V_7 -> V_99 ; V_62 ++ )
F_59 ( V_7 , & V_7 -> V_100 [ V_62 ] , V_62 ) ;
V_87 = F_75 ( V_7 -> V_44 , V_7 -> V_105 , F_39 ,
V_167 , L_9 , V_7 ) ;
if ( V_87 )
goto V_166;
V_7 -> V_3 . V_44 = V_7 -> V_44 ;
V_7 -> V_3 . V_44 -> V_168 = & V_7 -> V_168 ;
V_87 = F_76 ( V_7 -> V_3 . V_44 , V_65 ) ;
if ( V_87 ) {
F_14 ( V_7 -> V_44 , L_10 ) ;
goto V_166;
}
F_77 ( V_156 , V_7 ) ;
F_78 ( V_7 -> V_3 . V_169 ) ;
F_79 ( V_170 , V_7 -> V_3 . V_169 ) ;
V_7 -> V_3 . V_171 = F_12 ;
V_7 -> V_3 . V_172 = F_15 ;
V_7 -> V_3 . V_173 = F_22 ;
V_7 -> V_3 . V_174 = F_36 ;
V_7 -> V_3 . V_175 = F_53 ;
V_7 -> V_3 . V_176 = F_42 ;
V_7 -> V_3 . V_44 = V_7 -> V_44 ;
V_87 = F_80 ( & V_7 -> V_3 ) ;
if ( V_87 ) {
F_14 ( V_7 -> V_44 , L_11 ) ;
goto V_166;
}
V_87 = F_81 ( V_156 -> V_44 . V_162 , F_56 ,
& V_7 -> V_3 ) ;
if ( V_87 )
goto V_177;
return 0 ;
V_177:
F_82 ( & V_7 -> V_3 ) ;
V_166:
F_83 ( V_7 -> V_165 ) ;
return V_87 ;
}
static int F_84 ( struct V_155 * V_156 )
{
struct V_6 * V_7 = F_85 ( V_156 ) ;
T_2 V_62 ;
F_86 ( V_156 -> V_44 . V_162 ) ;
F_82 ( & V_7 -> V_3 ) ;
F_6 ( 0 , F_3 ( V_7 , 0 , V_35 ) ) ;
F_87 ( V_7 -> V_44 , V_7 -> V_105 , V_7 ) ;
for ( V_62 = 0 ; V_62 < V_7 -> V_99 ; V_62 ++ ) {
F_31 ( & V_7 -> V_100 [ V_62 ] ) ;
F_88 ( & V_7 -> V_100 [ V_62 ] . V_4 . V_108 ) ;
F_20 ( V_7 -> V_44 , V_31 ,
V_7 -> V_100 [ V_62 ] . V_43 ,
V_7 -> V_100 [ V_62 ] . V_28 ) ;
}
F_88 ( & V_7 -> V_108 ) ;
F_83 ( V_7 -> V_165 ) ;
return 0 ;
}
