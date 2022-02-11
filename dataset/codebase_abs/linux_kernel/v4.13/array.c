static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char * V_5 ;
T_1 V_6 ;
char V_7 [ sizeof( V_4 -> V_8 ) ] ;
int V_9 ;
F_2 ( V_7 , V_4 ) ;
F_3 ( V_2 , L_1 ) ;
V_6 = F_4 ( V_2 , & V_5 ) ;
V_9 = F_5 ( V_7 , V_5 , V_6 , V_10 | V_11 , L_2 ) ;
F_6 ( V_2 , V_9 < V_6 ? V_9 : - 1 ) ;
F_7 ( V_2 , '\n' ) ;
}
static inline const char * F_8 ( struct V_3 * V_12 )
{
unsigned int V_13 = ( V_12 -> V_13 | V_12 -> V_14 ) & V_15 ;
if ( V_12 -> V_13 == V_16 )
V_13 = V_17 ;
F_9 ( 1 + F_10 ( V_15 ) != F_11 ( V_18 ) - 1 ) ;
return V_18 [ F_12 ( V_13 ) ] ;
}
static inline int F_13 ( struct V_3 * V_12 )
{
struct V_19 * V_20 ;
int V_21 = - V_22 ;
F_14 ( V_12 ) ;
V_20 = V_12 -> V_20 ;
if ( V_20 )
V_21 = V_20 -> V_21 ;
F_15 ( V_12 ) ;
return V_21 ;
}
static inline void F_16 ( struct V_1 * V_2 , struct V_23 * V_24 ,
struct V_25 * V_25 , struct V_3 * V_4 )
{
struct V_26 * V_27 = F_17 ( V_2 ) ;
struct V_28 * V_28 ;
int V_29 , V_21 ;
struct V_3 * V_30 ;
const struct V_31 * V_31 ;
T_2 V_32 , V_33 = 0 , V_34 , V_35 ;
unsigned int V_36 = 0 ;
F_18 () ;
V_32 = F_19 ( V_4 ) ?
F_20 ( F_21 ( V_4 -> V_37 ) , V_24 ) : 0 ;
V_30 = F_22 ( V_4 ) ;
if ( V_30 )
V_33 = F_23 ( V_30 , V_24 ) ;
V_34 = F_20 ( V_4 , V_24 ) ;
V_35 = F_24 ( V_4 ) ;
V_31 = F_25 ( V_4 ) ;
V_21 = F_13 ( V_4 ) ;
if ( V_21 >= 0 )
F_26 ( V_2 , L_3 , V_21 ) ;
F_14 ( V_4 ) ;
if ( V_4 -> V_38 )
V_36 = F_27 ( V_4 -> V_38 ) -> V_36 ;
F_15 ( V_4 ) ;
F_28 () ;
F_26 ( V_2 , L_4 , F_8 ( V_4 ) ) ;
F_29 ( V_2 , L_5 , V_34 ) ;
F_29 ( V_2 , L_6 , V_35 ) ;
F_29 ( V_2 , L_7 , F_30 ( V_25 , V_24 ) ) ;
F_29 ( V_2 , L_8 , V_32 ) ;
F_29 ( V_2 , L_9 , V_33 ) ;
F_29 ( V_2 , L_10 , F_31 ( V_27 , V_31 -> V_39 ) ) ;
F_29 ( V_2 , L_11 , F_31 ( V_27 , V_31 -> V_40 ) ) ;
F_29 ( V_2 , L_11 , F_31 ( V_27 , V_31 -> V_41 ) ) ;
F_29 ( V_2 , L_11 , F_31 ( V_27 , V_31 -> V_42 ) ) ;
F_29 ( V_2 , L_12 , F_32 ( V_27 , V_31 -> V_43 ) ) ;
F_29 ( V_2 , L_11 , F_32 ( V_27 , V_31 -> V_44 ) ) ;
F_29 ( V_2 , L_11 , F_32 ( V_27 , V_31 -> V_45 ) ) ;
F_29 ( V_2 , L_11 , F_32 ( V_27 , V_31 -> V_46 ) ) ;
F_29 ( V_2 , L_13 , V_36 ) ;
F_3 ( V_2 , L_14 ) ;
V_28 = V_31 -> V_28 ;
for ( V_29 = 0 ; V_29 < V_28 -> V_47 ; V_29 ++ )
F_29 ( V_2 , V_29 ? L_15 : L_16 ,
F_32 ( V_27 , V_28 -> V_43 [ V_29 ] ) ) ;
F_33 ( V_31 ) ;
F_7 ( V_2 , ' ' ) ;
#ifdef F_34
F_3 ( V_2 , L_17 ) ;
for ( V_29 = V_24 -> V_48 ; V_29 <= V_25 -> V_48 ; V_29 ++ )
F_29 ( V_2 , L_11 , F_20 ( V_4 , V_25 -> V_49 [ V_29 ] . V_24 ) ) ;
F_3 ( V_2 , L_18 ) ;
for ( V_29 = V_24 -> V_48 ; V_29 <= V_25 -> V_48 ; V_29 ++ )
F_29 ( V_2 , L_11 , F_23 ( V_4 , V_25 -> V_49 [ V_29 ] . V_24 ) ) ;
F_3 ( V_2 , L_19 ) ;
for ( V_29 = V_24 -> V_48 ; V_29 <= V_25 -> V_48 ; V_29 ++ )
F_29 ( V_2 , L_11 , F_35 ( V_4 , V_25 -> V_49 [ V_29 ] . V_24 ) ) ;
F_3 ( V_2 , L_20 ) ;
for ( V_29 = V_24 -> V_48 ; V_29 <= V_25 -> V_48 ; V_29 ++ )
F_29 ( V_2 , L_11 , F_36 ( V_4 , V_25 -> V_49 [ V_29 ] . V_24 ) ) ;
#endif
F_7 ( V_2 , '\n' ) ;
}
void F_37 ( struct V_1 * V_2 , const char * V_50 ,
T_3 * V_51 )
{
int V_52 ;
F_3 ( V_2 , V_50 ) ;
V_52 = V_53 ;
do {
int V_54 = 0 ;
V_52 -= 4 ;
if ( F_38 ( V_51 , V_52 + 1 ) ) V_54 |= 1 ;
if ( F_38 ( V_51 , V_52 + 2 ) ) V_54 |= 2 ;
if ( F_38 ( V_51 , V_52 + 3 ) ) V_54 |= 4 ;
if ( F_38 ( V_51 , V_52 + 4 ) ) V_54 |= 8 ;
F_7 ( V_2 , V_55 [ V_54 ] ) ;
} while ( V_52 >= 4 );
F_7 ( V_2 , '\n' ) ;
}
static void F_39 ( struct V_3 * V_4 , T_3 * V_56 ,
T_3 * V_57 )
{
struct V_58 * V_59 ;
int V_52 ;
V_59 = V_4 -> V_60 -> V_61 ;
for ( V_52 = 1 ; V_52 <= V_53 ; ++ V_52 , ++ V_59 ) {
if ( V_59 -> V_62 . V_63 == V_64 )
F_40 ( V_56 , V_52 ) ;
else if ( V_59 -> V_62 . V_63 != V_65 )
F_40 ( V_57 , V_52 ) ;
}
}
static inline void F_41 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_66 ;
T_3 V_67 , V_68 , V_69 , V_70 , V_71 ;
int V_72 = 0 ;
unsigned long V_73 = 0 ;
unsigned long V_74 = 0 ;
F_42 ( & V_67 ) ;
F_42 ( & V_68 ) ;
F_42 ( & V_69 ) ;
F_42 ( & V_70 ) ;
F_42 ( & V_71 ) ;
if ( F_43 ( V_4 , & V_66 ) ) {
V_67 = V_4 -> V_67 . signal ;
V_68 = V_4 -> signal -> V_75 . signal ;
V_69 = V_4 -> V_69 ;
F_39 ( V_4 , & V_70 , & V_71 ) ;
V_72 = F_44 ( V_4 ) ;
F_18 () ;
V_73 = F_45 ( & F_46 ( V_4 ) -> V_76 -> V_77 ) ;
F_28 () ;
V_74 = F_47 ( V_4 , V_78 ) ;
F_48 ( V_4 , & V_66 ) ;
}
F_29 ( V_2 , L_21 , V_72 ) ;
F_29 ( V_2 , L_22 , V_73 ) ;
F_29 ( V_2 , L_23 , V_74 ) ;
F_37 ( V_2 , L_24 , & V_67 ) ;
F_37 ( V_2 , L_25 , & V_68 ) ;
F_37 ( V_2 , L_26 , & V_69 ) ;
F_37 ( V_2 , L_27 , & V_70 ) ;
F_37 ( V_2 , L_28 , & V_71 ) ;
}
static void F_49 ( struct V_1 * V_2 , const char * V_50 ,
T_4 * V_79 )
{
unsigned V_80 ;
F_3 ( V_2 , V_50 ) ;
F_50 (__capi) {
F_26 ( V_2 , L_29 ,
V_79 -> V_81 [ V_82 - V_80 ] ) ;
}
F_7 ( V_2 , '\n' ) ;
}
static inline void F_51 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_31 * V_31 ;
T_4 V_83 , V_84 , V_85 ,
V_86 , V_87 ;
F_18 () ;
V_31 = F_46 ( V_4 ) ;
V_83 = V_31 -> V_83 ;
V_84 = V_31 -> V_84 ;
V_85 = V_31 -> V_85 ;
V_86 = V_31 -> V_86 ;
V_87 = V_31 -> V_87 ;
F_28 () ;
F_49 ( V_2 , L_30 , & V_83 ) ;
F_49 ( V_2 , L_31 , & V_84 ) ;
F_49 ( V_2 , L_32 , & V_85 ) ;
F_49 ( V_2 , L_33 , & V_86 ) ;
F_49 ( V_2 , L_34 , & V_87 ) ;
}
static inline void F_52 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_29 ( V_2 , L_35 , F_53 ( V_4 ) ) ;
#ifdef F_54
F_29 ( V_2 , L_36 , V_4 -> V_88 . V_89 ) ;
#endif
F_7 ( V_2 , '\n' ) ;
}
static inline void F_55 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_29 ( V_2 , L_37 , V_4 -> V_90 ) ;
F_29 ( V_2 , L_38 , V_4 -> V_91 ) ;
F_7 ( V_2 , '\n' ) ;
}
static void F_56 ( struct V_1 * V_2 , struct V_3 * V_92 )
{
F_26 ( V_2 , L_39 ,
F_57 ( & V_92 -> V_93 ) ) ;
F_26 ( V_2 , L_40 ,
F_57 ( & V_92 -> V_93 ) ) ;
}
int F_58 ( struct V_1 * V_2 , struct V_23 * V_24 ,
struct V_25 * V_25 , struct V_3 * V_92 )
{
struct V_94 * V_95 = F_59 ( V_92 ) ;
F_1 ( V_2 , V_92 ) ;
F_16 ( V_2 , V_24 , V_25 , V_92 ) ;
if ( V_95 ) {
F_60 ( V_2 , V_95 ) ;
F_61 ( V_95 ) ;
}
F_41 ( V_2 , V_92 ) ;
F_51 ( V_2 , V_92 ) ;
F_52 ( V_2 , V_92 ) ;
F_56 ( V_2 , V_92 ) ;
F_62 ( V_2 , V_92 ) ;
F_55 ( V_2 , V_92 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , struct V_23 * V_24 ,
struct V_25 * V_25 , struct V_3 * V_92 , int V_96 )
{
unsigned long V_97 , V_98 , V_99 , V_100 = 0 ;
int V_101 , V_102 ;
int V_103 = - 1 , V_104 = 0 ;
T_3 V_105 , V_106 ;
char V_13 ;
T_2 V_32 = 0 , V_107 = - 1 , V_108 = - 1 ;
int V_72 = 0 ;
int V_109 ;
struct V_94 * V_95 ;
unsigned long long V_110 ;
unsigned long V_111 = 0 , V_112 = 0 ;
unsigned long V_113 = 0 , V_114 = 0 ;
T_5 V_115 , V_116 , V_117 , V_118 ;
T_5 V_119 , V_120 ;
unsigned long V_121 = 0 ;
char V_7 [ sizeof( V_92 -> V_8 ) ] ;
unsigned long V_66 ;
V_13 = * F_8 ( V_92 ) ;
V_97 = V_98 = V_99 = 0 ;
V_109 = F_64 ( V_92 , V_122 | V_123 ) ;
V_95 = F_59 ( V_92 ) ;
if ( V_95 ) {
V_97 = F_65 ( V_95 ) ;
}
F_2 ( V_7 , V_92 ) ;
F_42 ( & V_105 ) ;
F_42 ( & V_106 ) ;
V_115 = V_116 = V_117 = V_118 = 0 ;
V_119 = V_120 = 0 ;
if ( F_43 ( V_92 , & V_66 ) ) {
struct V_124 * V_125 = V_92 -> signal ;
if ( V_125 -> V_126 ) {
struct V_25 * V_127 = F_66 ( V_125 -> V_126 ) ;
V_103 = F_30 ( V_127 , V_24 ) ;
F_67 ( V_127 ) ;
V_104 = F_68 ( F_69 ( V_125 -> V_126 ) ) ;
}
V_72 = F_44 ( V_92 ) ;
F_39 ( V_92 , & V_105 , & V_106 ) ;
V_111 = V_125 -> V_111 ;
V_112 = V_125 -> V_112 ;
V_115 = V_125 -> V_115 ;
V_116 = V_125 -> V_116 ;
V_119 = V_125 -> V_119 ;
V_121 = F_70 ( V_125 -> V_128 [ V_129 ] . V_130 ) ;
if ( V_96 ) {
struct V_3 * V_131 = V_92 ;
do {
V_113 += V_131 -> V_113 ;
V_114 += V_131 -> V_114 ;
V_120 += F_71 ( V_131 ) ;
} while_each_thread(task, t) ;
V_113 += V_125 -> V_113 ;
V_114 += V_125 -> V_114 ;
F_72 ( V_92 , & V_117 , & V_118 ) ;
V_120 += V_125 -> V_120 ;
}
V_108 = F_36 ( V_92 , V_24 ) ;
V_32 = F_20 ( V_92 -> V_37 , V_24 ) ;
V_107 = F_35 ( V_92 , V_24 ) ;
F_48 ( V_92 , & V_66 ) ;
}
int F_73 ( struct V_1 * V_2 , struct V_23 * V_24 ,
struct V_25 * V_25 , struct V_3 * V_92 )
{
return F_63 ( V_2 , V_24 , V_25 , V_92 , 1 ) ;
}
int F_74 ( struct V_1 * V_2 , struct V_23 * V_24 ,
struct V_25 * V_25 , struct V_3 * V_92 )
{
unsigned long V_6 = 0 , V_132 = 0 , V_133 = 0 , V_134 = 0 , V_135 = 0 ;
struct V_94 * V_95 = F_59 ( V_92 ) ;
if ( V_95 ) {
V_6 = F_75 ( V_95 , & V_133 , & V_134 , & V_135 , & V_132 ) ;
F_61 ( V_95 ) ;
}
F_29 ( V_2 , L_16 , V_6 ) ;
F_29 ( V_2 , L_15 , V_132 ) ;
F_29 ( V_2 , L_15 , V_133 ) ;
F_29 ( V_2 , L_15 , V_134 ) ;
F_29 ( V_2 , L_15 , 0 ) ;
F_29 ( V_2 , L_15 , V_135 ) ;
F_29 ( V_2 , L_15 , 0 ) ;
F_7 ( V_2 , '\n' ) ;
return 0 ;
}
static struct V_25 *
F_76 ( struct V_136 * V_136 , struct V_25 * V_137 , T_6 V_138 )
{
struct V_3 * V_139 , * V_92 ;
struct V_25 * V_25 = NULL ;
F_77 ( & V_140 ) ;
V_139 = F_78 ( F_79 ( V_136 ) , V_141 ) ;
if ( ! V_139 )
goto V_142;
if ( V_137 ) {
V_92 = F_78 ( V_137 , V_141 ) ;
if ( V_92 && V_92 -> V_37 == V_139 &&
! ( F_80 ( & V_92 -> V_143 ) ) ) {
if ( F_81 ( & V_92 -> V_143 , & V_139 -> V_144 ) )
goto V_142;
V_92 = F_82 ( & V_92 -> V_143 ,
struct V_3 , V_143 ) ;
V_25 = F_83 ( F_84 ( V_92 ) ) ;
goto V_142;
}
}
F_85 (task, &start->children, sibling) {
if ( V_138 -- == 0 ) {
V_25 = F_83 ( F_84 ( V_92 ) ) ;
break;
}
}
V_142:
F_86 ( & V_140 ) ;
return V_25 ;
}
static int F_87 ( struct V_1 * V_145 , void * V_146 )
{
struct V_136 * V_136 = V_145 -> V_147 ;
T_2 V_25 ;
V_25 = F_30 ( V_146 , V_136 -> V_148 -> V_149 ) ;
F_26 ( V_145 , L_41 , V_25 ) ;
return 0 ;
}
static void * F_88 ( struct V_1 * V_145 , T_6 * V_138 )
{
return F_76 ( V_145 -> V_147 , NULL , * V_138 ) ;
}
static void * F_89 ( struct V_1 * V_145 , void * V_146 , T_6 * V_138 )
{
struct V_25 * V_25 ;
V_25 = F_76 ( V_145 -> V_147 , V_146 , * V_138 + 1 ) ;
F_67 ( V_146 ) ;
++ * V_138 ;
return V_25 ;
}
static void F_90 ( struct V_1 * V_145 , void * V_146 )
{
F_67 ( V_146 ) ;
}
static int F_91 ( struct V_136 * V_136 , struct V_150 * V_150 )
{
struct V_1 * V_2 ;
int V_9 ;
V_9 = F_92 ( V_150 , & V_151 ) ;
if ( V_9 )
return V_9 ;
V_2 = V_150 -> V_152 ;
V_2 -> V_147 = V_136 ;
return V_9 ;
}
int F_93 ( struct V_136 * V_136 , struct V_150 * V_150 )
{
F_94 ( V_136 , V_150 ) ;
return 0 ;
}
