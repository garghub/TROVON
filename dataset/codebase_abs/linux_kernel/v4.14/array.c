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
F_9 ( 1 + F_10 ( V_13 ) != F_11 ( V_14 ) ) ;
return V_14 [ F_12 ( V_12 ) ] ;
}
static inline int F_13 ( struct V_3 * V_12 )
{
struct V_15 * V_16 ;
int V_17 = - V_18 ;
F_14 ( V_12 ) ;
V_16 = V_12 -> V_16 ;
if ( V_16 )
V_17 = V_16 -> V_17 ;
F_15 ( V_12 ) ;
return V_17 ;
}
static inline void F_16 ( struct V_1 * V_2 , struct V_19 * V_20 ,
struct V_21 * V_21 , struct V_3 * V_4 )
{
struct V_22 * V_23 = F_17 ( V_2 ) ;
struct V_24 * V_24 ;
int V_25 , V_17 ;
struct V_3 * V_26 ;
const struct V_27 * V_27 ;
T_2 V_28 , V_29 = 0 , V_30 , V_31 ;
unsigned int V_32 = 0 ;
F_18 () ;
V_28 = F_19 ( V_4 ) ?
F_20 ( F_21 ( V_4 -> V_33 ) , V_20 ) : 0 ;
V_26 = F_22 ( V_4 ) ;
if ( V_26 )
V_29 = F_23 ( V_26 , V_20 ) ;
V_30 = F_20 ( V_4 , V_20 ) ;
V_31 = F_24 ( V_4 ) ;
V_27 = F_25 ( V_4 ) ;
V_17 = F_13 ( V_4 ) ;
if ( V_17 >= 0 )
F_26 ( V_2 , L_3 , V_17 ) ;
F_14 ( V_4 ) ;
if ( V_4 -> V_34 )
V_32 = F_27 ( V_4 -> V_34 ) -> V_32 ;
F_15 ( V_4 ) ;
F_28 () ;
F_26 ( V_2 , L_4 , F_8 ( V_4 ) ) ;
F_29 ( V_2 , L_5 , V_30 ) ;
F_29 ( V_2 , L_6 , V_31 ) ;
F_29 ( V_2 , L_7 , F_30 ( V_21 , V_20 ) ) ;
F_29 ( V_2 , L_8 , V_28 ) ;
F_29 ( V_2 , L_9 , V_29 ) ;
F_29 ( V_2 , L_10 , F_31 ( V_23 , V_27 -> V_35 ) ) ;
F_29 ( V_2 , L_11 , F_31 ( V_23 , V_27 -> V_36 ) ) ;
F_29 ( V_2 , L_11 , F_31 ( V_23 , V_27 -> V_37 ) ) ;
F_29 ( V_2 , L_11 , F_31 ( V_23 , V_27 -> V_38 ) ) ;
F_29 ( V_2 , L_12 , F_32 ( V_23 , V_27 -> V_39 ) ) ;
F_29 ( V_2 , L_11 , F_32 ( V_23 , V_27 -> V_40 ) ) ;
F_29 ( V_2 , L_11 , F_32 ( V_23 , V_27 -> V_41 ) ) ;
F_29 ( V_2 , L_11 , F_32 ( V_23 , V_27 -> V_42 ) ) ;
F_29 ( V_2 , L_13 , V_32 ) ;
F_3 ( V_2 , L_14 ) ;
V_24 = V_27 -> V_24 ;
for ( V_25 = 0 ; V_25 < V_24 -> V_43 ; V_25 ++ )
F_29 ( V_2 , V_25 ? L_15 : L_16 ,
F_32 ( V_23 , V_24 -> V_39 [ V_25 ] ) ) ;
F_33 ( V_27 ) ;
F_7 ( V_2 , ' ' ) ;
#ifdef F_34
F_3 ( V_2 , L_17 ) ;
for ( V_25 = V_20 -> V_44 ; V_25 <= V_21 -> V_44 ; V_25 ++ )
F_29 ( V_2 , L_11 , F_20 ( V_4 , V_21 -> V_45 [ V_25 ] . V_20 ) ) ;
F_3 ( V_2 , L_18 ) ;
for ( V_25 = V_20 -> V_44 ; V_25 <= V_21 -> V_44 ; V_25 ++ )
F_29 ( V_2 , L_11 , F_23 ( V_4 , V_21 -> V_45 [ V_25 ] . V_20 ) ) ;
F_3 ( V_2 , L_19 ) ;
for ( V_25 = V_20 -> V_44 ; V_25 <= V_21 -> V_44 ; V_25 ++ )
F_29 ( V_2 , L_11 , F_35 ( V_4 , V_21 -> V_45 [ V_25 ] . V_20 ) ) ;
F_3 ( V_2 , L_20 ) ;
for ( V_25 = V_20 -> V_44 ; V_25 <= V_21 -> V_44 ; V_25 ++ )
F_29 ( V_2 , L_11 , F_36 ( V_4 , V_21 -> V_45 [ V_25 ] . V_20 ) ) ;
#endif
F_7 ( V_2 , '\n' ) ;
}
void F_37 ( struct V_1 * V_2 , const char * V_46 ,
T_3 * V_47 )
{
int V_48 ;
F_3 ( V_2 , V_46 ) ;
V_48 = V_49 ;
do {
int V_50 = 0 ;
V_48 -= 4 ;
if ( F_38 ( V_47 , V_48 + 1 ) ) V_50 |= 1 ;
if ( F_38 ( V_47 , V_48 + 2 ) ) V_50 |= 2 ;
if ( F_38 ( V_47 , V_48 + 3 ) ) V_50 |= 4 ;
if ( F_38 ( V_47 , V_48 + 4 ) ) V_50 |= 8 ;
F_7 ( V_2 , V_51 [ V_50 ] ) ;
} while ( V_48 >= 4 );
F_7 ( V_2 , '\n' ) ;
}
static void F_39 ( struct V_3 * V_4 , T_3 * V_52 ,
T_3 * V_53 )
{
struct V_54 * V_55 ;
int V_48 ;
V_55 = V_4 -> V_56 -> V_57 ;
for ( V_48 = 1 ; V_48 <= V_49 ; ++ V_48 , ++ V_55 ) {
if ( V_55 -> V_58 . V_59 == V_60 )
F_40 ( V_52 , V_48 ) ;
else if ( V_55 -> V_58 . V_59 != V_61 )
F_40 ( V_53 , V_48 ) ;
}
}
static inline void F_41 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_62 ;
T_3 V_63 , V_64 , V_65 , V_66 , V_67 ;
int V_68 = 0 ;
unsigned long V_69 = 0 ;
unsigned long V_70 = 0 ;
F_42 ( & V_63 ) ;
F_42 ( & V_64 ) ;
F_42 ( & V_65 ) ;
F_42 ( & V_66 ) ;
F_42 ( & V_67 ) ;
if ( F_43 ( V_4 , & V_62 ) ) {
V_63 = V_4 -> V_63 . signal ;
V_64 = V_4 -> signal -> V_71 . signal ;
V_65 = V_4 -> V_65 ;
F_39 ( V_4 , & V_66 , & V_67 ) ;
V_68 = F_44 ( V_4 ) ;
F_18 () ;
V_69 = F_45 ( & F_46 ( V_4 ) -> V_72 -> V_73 ) ;
F_28 () ;
V_70 = F_47 ( V_4 , V_74 ) ;
F_48 ( V_4 , & V_62 ) ;
}
F_29 ( V_2 , L_21 , V_68 ) ;
F_29 ( V_2 , L_22 , V_69 ) ;
F_29 ( V_2 , L_23 , V_70 ) ;
F_37 ( V_2 , L_24 , & V_63 ) ;
F_37 ( V_2 , L_25 , & V_64 ) ;
F_37 ( V_2 , L_26 , & V_65 ) ;
F_37 ( V_2 , L_27 , & V_66 ) ;
F_37 ( V_2 , L_28 , & V_67 ) ;
}
static void F_49 ( struct V_1 * V_2 , const char * V_46 ,
T_4 * V_75 )
{
unsigned V_76 ;
F_3 ( V_2 , V_46 ) ;
F_50 (__capi) {
F_26 ( V_2 , L_29 ,
V_75 -> V_77 [ V_78 - V_76 ] ) ;
}
F_7 ( V_2 , '\n' ) ;
}
static inline void F_51 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_27 * V_27 ;
T_4 V_79 , V_80 , V_81 ,
V_82 , V_83 ;
F_18 () ;
V_27 = F_46 ( V_4 ) ;
V_79 = V_27 -> V_79 ;
V_80 = V_27 -> V_80 ;
V_81 = V_27 -> V_81 ;
V_82 = V_27 -> V_82 ;
V_83 = V_27 -> V_83 ;
F_28 () ;
F_49 ( V_2 , L_30 , & V_79 ) ;
F_49 ( V_2 , L_31 , & V_80 ) ;
F_49 ( V_2 , L_32 , & V_81 ) ;
F_49 ( V_2 , L_33 , & V_82 ) ;
F_49 ( V_2 , L_34 , & V_83 ) ;
}
static inline void F_52 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_29 ( V_2 , L_35 , F_53 ( V_4 ) ) ;
#ifdef F_54
F_29 ( V_2 , L_36 , V_4 -> V_84 . V_85 ) ;
#endif
F_7 ( V_2 , '\n' ) ;
}
static inline void F_55 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_29 ( V_2 , L_37 , V_4 -> V_86 ) ;
F_29 ( V_2 , L_38 , V_4 -> V_87 ) ;
F_7 ( V_2 , '\n' ) ;
}
static void F_56 ( struct V_1 * V_2 , struct V_3 * V_88 )
{
F_26 ( V_2 , L_39 ,
F_57 ( & V_88 -> V_89 ) ) ;
F_26 ( V_2 , L_40 ,
F_57 ( & V_88 -> V_89 ) ) ;
}
int F_58 ( struct V_1 * V_2 , struct V_19 * V_20 ,
struct V_21 * V_21 , struct V_3 * V_88 )
{
struct V_90 * V_91 = F_59 ( V_88 ) ;
F_1 ( V_2 , V_88 ) ;
F_16 ( V_2 , V_20 , V_21 , V_88 ) ;
if ( V_91 ) {
F_60 ( V_2 , V_91 ) ;
F_61 ( V_91 ) ;
}
F_41 ( V_2 , V_88 ) ;
F_51 ( V_2 , V_88 ) ;
F_52 ( V_2 , V_88 ) ;
F_56 ( V_2 , V_88 ) ;
F_62 ( V_2 , V_88 ) ;
F_55 ( V_2 , V_88 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , struct V_19 * V_20 ,
struct V_21 * V_21 , struct V_3 * V_88 , int V_92 )
{
unsigned long V_93 , V_94 , V_95 , V_96 = 0 ;
int V_97 , V_98 ;
int V_99 = - 1 , V_100 = 0 ;
T_3 V_101 , V_102 ;
char V_103 ;
T_2 V_28 = 0 , V_104 = - 1 , V_105 = - 1 ;
int V_68 = 0 ;
int V_106 ;
struct V_90 * V_91 ;
unsigned long long V_107 ;
unsigned long V_108 = 0 , V_109 = 0 ;
unsigned long V_110 = 0 , V_111 = 0 ;
T_5 V_112 , V_113 , V_114 , V_115 ;
T_5 V_116 , V_117 ;
unsigned long V_118 = 0 ;
char V_7 [ sizeof( V_88 -> V_8 ) ] ;
unsigned long V_62 ;
V_103 = * F_8 ( V_88 ) ;
V_93 = V_94 = V_95 = 0 ;
V_106 = F_64 ( V_88 , V_119 | V_120 ) ;
V_91 = F_59 ( V_88 ) ;
if ( V_91 ) {
V_93 = F_65 ( V_91 ) ;
if ( V_106 && ( V_88 -> V_62 & V_121 ) ) {
V_94 = F_66 ( V_88 ) ;
V_95 = F_67 ( V_88 ) ;
}
}
F_2 ( V_7 , V_88 ) ;
F_42 ( & V_101 ) ;
F_42 ( & V_102 ) ;
V_112 = V_113 = V_114 = V_115 = 0 ;
V_116 = V_117 = 0 ;
if ( F_43 ( V_88 , & V_62 ) ) {
struct V_122 * V_123 = V_88 -> signal ;
if ( V_123 -> V_124 ) {
struct V_21 * V_125 = F_68 ( V_123 -> V_124 ) ;
V_99 = F_30 ( V_125 , V_20 ) ;
F_69 ( V_125 ) ;
V_100 = F_70 ( F_71 ( V_123 -> V_124 ) ) ;
}
V_68 = F_44 ( V_88 ) ;
F_39 ( V_88 , & V_101 , & V_102 ) ;
V_108 = V_123 -> V_108 ;
V_109 = V_123 -> V_109 ;
V_112 = V_123 -> V_112 ;
V_113 = V_123 -> V_113 ;
V_116 = V_123 -> V_116 ;
V_118 = F_72 ( V_123 -> V_126 [ V_127 ] . V_128 ) ;
if ( V_92 ) {
struct V_3 * V_129 = V_88 ;
do {
V_110 += V_129 -> V_110 ;
V_111 += V_129 -> V_111 ;
V_117 += F_73 ( V_129 ) ;
} while_each_thread(task, t) ;
V_110 += V_123 -> V_110 ;
V_111 += V_123 -> V_111 ;
F_74 ( V_88 , & V_114 , & V_115 ) ;
V_117 += V_123 -> V_117 ;
}
V_105 = F_36 ( V_88 , V_20 ) ;
V_28 = F_20 ( V_88 -> V_33 , V_20 ) ;
V_104 = F_35 ( V_88 , V_20 ) ;
F_48 ( V_88 , & V_62 ) ;
}
int F_75 ( struct V_1 * V_2 , struct V_19 * V_20 ,
struct V_21 * V_21 , struct V_3 * V_88 )
{
return F_63 ( V_2 , V_20 , V_21 , V_88 , 1 ) ;
}
int F_76 ( struct V_1 * V_2 , struct V_19 * V_20 ,
struct V_21 * V_21 , struct V_3 * V_88 )
{
unsigned long V_6 = 0 , V_130 = 0 , V_131 = 0 , V_132 = 0 , V_133 = 0 ;
struct V_90 * V_91 = F_59 ( V_88 ) ;
if ( V_91 ) {
V_6 = F_77 ( V_91 , & V_131 , & V_132 , & V_133 , & V_130 ) ;
F_61 ( V_91 ) ;
}
F_29 ( V_2 , L_16 , V_6 ) ;
F_29 ( V_2 , L_15 , V_130 ) ;
F_29 ( V_2 , L_15 , V_131 ) ;
F_29 ( V_2 , L_15 , V_132 ) ;
F_29 ( V_2 , L_15 , 0 ) ;
F_29 ( V_2 , L_15 , V_133 ) ;
F_29 ( V_2 , L_15 , 0 ) ;
F_7 ( V_2 , '\n' ) ;
return 0 ;
}
static struct V_21 *
F_78 ( struct V_134 * V_134 , struct V_21 * V_135 , T_6 V_136 )
{
struct V_3 * V_137 , * V_88 ;
struct V_21 * V_21 = NULL ;
F_79 ( & V_138 ) ;
V_137 = F_80 ( F_81 ( V_134 ) , V_139 ) ;
if ( ! V_137 )
goto V_140;
if ( V_135 ) {
V_88 = F_80 ( V_135 , V_139 ) ;
if ( V_88 && V_88 -> V_33 == V_137 &&
! ( F_82 ( & V_88 -> V_141 ) ) ) {
if ( F_83 ( & V_88 -> V_141 , & V_137 -> V_142 ) )
goto V_140;
V_88 = F_84 ( & V_88 -> V_141 ,
struct V_3 , V_141 ) ;
V_21 = F_85 ( F_86 ( V_88 ) ) ;
goto V_140;
}
}
F_87 (task, &start->children, sibling) {
if ( V_136 -- == 0 ) {
V_21 = F_85 ( F_86 ( V_88 ) ) ;
break;
}
}
V_140:
F_88 ( & V_138 ) ;
return V_21 ;
}
static int F_89 ( struct V_1 * V_143 , void * V_144 )
{
struct V_134 * V_134 = V_143 -> V_145 ;
T_2 V_21 ;
V_21 = F_30 ( V_144 , V_134 -> V_146 -> V_147 ) ;
F_26 ( V_143 , L_41 , V_21 ) ;
return 0 ;
}
static void * F_90 ( struct V_1 * V_143 , T_6 * V_136 )
{
return F_78 ( V_143 -> V_145 , NULL , * V_136 ) ;
}
static void * F_91 ( struct V_1 * V_143 , void * V_144 , T_6 * V_136 )
{
struct V_21 * V_21 ;
V_21 = F_78 ( V_143 -> V_145 , V_144 , * V_136 + 1 ) ;
F_69 ( V_144 ) ;
++ * V_136 ;
return V_21 ;
}
static void F_92 ( struct V_1 * V_143 , void * V_144 )
{
F_69 ( V_144 ) ;
}
static int F_93 ( struct V_134 * V_134 , struct V_148 * V_148 )
{
struct V_1 * V_2 ;
int V_9 ;
V_9 = F_94 ( V_148 , & V_149 ) ;
if ( V_9 )
return V_9 ;
V_2 = V_148 -> V_150 ;
V_2 -> V_145 = V_134 ;
return V_9 ;
}
int F_95 ( struct V_134 * V_134 , struct V_148 * V_148 )
{
F_96 ( V_134 , V_148 ) ;
return 0 ;
}
