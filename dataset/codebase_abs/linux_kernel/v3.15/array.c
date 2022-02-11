static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
char * V_6 , * V_7 ;
char * V_8 ;
char V_9 [ sizeof( V_4 -> V_10 ) ] ;
F_2 ( V_9 , V_4 ) ;
F_3 ( V_2 , L_1 ) ;
V_7 = V_2 -> V_6 + V_2 -> V_11 ;
V_6 = V_2 -> V_6 + V_2 -> V_12 ;
V_8 = V_9 ;
V_5 = sizeof( V_9 ) ;
while ( V_5 && ( V_6 < V_7 ) ) {
unsigned char V_13 = * V_8 ;
V_8 ++ ;
V_5 -- ;
* V_6 = V_13 ;
if ( ! V_13 )
break;
if ( V_13 == '\\' ) {
V_6 ++ ;
if ( V_6 < V_7 )
* V_6 ++ = V_13 ;
continue;
}
if ( V_13 == '\n' ) {
* V_6 ++ = '\\' ;
if ( V_6 < V_7 )
* V_6 ++ = 'n' ;
continue;
}
V_6 ++ ;
}
V_2 -> V_12 = V_6 - V_2 -> V_6 ;
F_4 ( V_2 , '\n' ) ;
}
static inline const char * F_5 ( struct V_3 * V_14 )
{
unsigned int V_15 = ( V_14 -> V_15 | V_14 -> V_16 ) & V_17 ;
F_6 ( 1 + F_7 ( V_17 ) != F_8 ( V_18 ) - 1 ) ;
return V_18 [ F_9 ( V_15 ) ] ;
}
static inline void F_10 ( struct V_1 * V_2 , struct V_19 * V_20 ,
struct V_21 * V_21 , struct V_3 * V_4 )
{
struct V_22 * V_23 = F_11 ( V_2 ) ;
struct V_24 * V_24 ;
int V_25 ;
struct V_26 * V_27 = NULL ;
const struct V_28 * V_28 ;
T_1 V_29 , V_30 ;
F_12 () ;
V_29 = F_13 ( V_4 ) ?
F_14 ( F_15 ( V_4 -> V_31 ) , V_20 ) : 0 ;
V_30 = 0 ;
if ( F_13 ( V_4 ) ) {
struct V_3 * V_32 = F_16 ( V_4 ) ;
if ( V_32 )
V_30 = F_17 ( V_32 , V_20 ) ;
}
V_28 = F_18 ( V_4 ) ;
F_19 ( V_2 ,
L_2
L_3
L_4
L_5
L_6
L_7
L_8
L_9 ,
F_5 ( V_4 ) ,
F_14 ( V_4 , V_20 ) ,
F_20 ( V_4 ) ,
F_21 ( V_21 , V_20 ) ,
V_29 , V_30 ,
F_22 ( V_23 , V_28 -> V_33 ) ,
F_22 ( V_23 , V_28 -> V_34 ) ,
F_22 ( V_23 , V_28 -> V_35 ) ,
F_22 ( V_23 , V_28 -> V_36 ) ,
F_23 ( V_23 , V_28 -> V_37 ) ,
F_23 ( V_23 , V_28 -> V_38 ) ,
F_23 ( V_23 , V_28 -> V_39 ) ,
F_23 ( V_23 , V_28 -> V_40 ) ) ;
F_24 ( V_4 ) ;
if ( V_4 -> V_41 )
V_27 = F_25 ( V_4 -> V_41 ) ;
F_19 ( V_2 ,
L_10
L_11 ,
V_27 ? V_27 -> V_42 : 0 ) ;
F_26 () ;
V_24 = V_28 -> V_24 ;
F_27 ( V_4 ) ;
for ( V_25 = 0 ; V_25 < V_24 -> V_43 ; V_25 ++ )
F_19 ( V_2 , L_12 ,
F_23 ( V_23 , F_28 ( V_24 , V_25 ) ) ) ;
F_29 ( V_28 ) ;
F_4 ( V_2 , '\n' ) ;
}
void F_30 ( struct V_1 * V_2 , const char * V_44 ,
T_2 * V_45 )
{
int V_5 ;
F_3 ( V_2 , V_44 ) ;
V_5 = V_46 ;
do {
int V_47 = 0 ;
V_5 -= 4 ;
if ( F_31 ( V_45 , V_5 + 1 ) ) V_47 |= 1 ;
if ( F_31 ( V_45 , V_5 + 2 ) ) V_47 |= 2 ;
if ( F_31 ( V_45 , V_5 + 3 ) ) V_47 |= 4 ;
if ( F_31 ( V_45 , V_5 + 4 ) ) V_47 |= 8 ;
F_19 ( V_2 , L_13 , V_47 ) ;
} while ( V_5 >= 4 );
F_4 ( V_2 , '\n' ) ;
}
static void F_32 ( struct V_3 * V_4 , T_2 * V_48 ,
T_2 * V_49 )
{
struct V_50 * V_51 ;
int V_5 ;
V_51 = V_4 -> V_52 -> V_53 ;
for ( V_5 = 1 ; V_5 <= V_46 ; ++ V_5 , ++ V_51 ) {
if ( V_51 -> V_54 . V_55 == V_56 )
F_33 ( V_48 , V_5 ) ;
else if ( V_51 -> V_54 . V_55 != V_57 )
F_33 ( V_49 , V_5 ) ;
}
}
static inline void F_34 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_58 ;
T_2 V_59 , V_60 , V_61 , V_62 , V_63 ;
int V_64 = 0 ;
unsigned long V_65 = 0 ;
unsigned long V_66 = 0 ;
F_35 ( & V_59 ) ;
F_35 ( & V_60 ) ;
F_35 ( & V_61 ) ;
F_35 ( & V_62 ) ;
F_35 ( & V_63 ) ;
if ( F_36 ( V_4 , & V_58 ) ) {
V_59 = V_4 -> V_59 . signal ;
V_60 = V_4 -> signal -> V_67 . signal ;
V_61 = V_4 -> V_61 ;
F_32 ( V_4 , & V_62 , & V_63 ) ;
V_64 = F_37 ( V_4 ) ;
F_12 () ;
V_65 = F_38 ( & F_39 ( V_4 ) -> V_68 -> V_69 ) ;
F_26 () ;
V_66 = F_40 ( V_4 , V_70 ) ;
F_41 ( V_4 , & V_58 ) ;
}
F_19 ( V_2 , L_14 , V_64 ) ;
F_19 ( V_2 , L_15 , V_65 , V_66 ) ;
F_30 ( V_2 , L_16 , & V_59 ) ;
F_30 ( V_2 , L_17 , & V_60 ) ;
F_30 ( V_2 , L_18 , & V_61 ) ;
F_30 ( V_2 , L_19 , & V_62 ) ;
F_30 ( V_2 , L_20 , & V_63 ) ;
}
static void F_42 ( struct V_1 * V_2 , const char * V_44 ,
T_3 * V_71 )
{
unsigned V_72 ;
F_3 ( V_2 , V_44 ) ;
F_43 (__capi) {
F_19 ( V_2 , L_21 ,
V_71 -> V_73 [ ( V_74 - 1 ) - V_72 ] ) ;
}
F_4 ( V_2 , '\n' ) ;
}
static inline void F_44 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_28 * V_28 ;
T_3 V_75 , V_76 , V_77 , V_78 ;
F_12 () ;
V_28 = F_39 ( V_4 ) ;
V_75 = V_28 -> V_75 ;
V_76 = V_28 -> V_76 ;
V_77 = V_28 -> V_77 ;
V_78 = V_28 -> V_78 ;
F_26 () ;
F_45 ( V_75 ) ;
F_45 ( V_76 ) ;
F_45 ( V_77 ) ;
F_45 ( V_78 ) ;
F_42 ( V_2 , L_22 , & V_75 ) ;
F_42 ( V_2 , L_23 , & V_76 ) ;
F_42 ( V_2 , L_24 , & V_77 ) ;
F_42 ( V_2 , L_25 , & V_78 ) ;
}
static inline void F_46 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
#ifdef F_47
F_19 ( V_2 , L_26 , V_4 -> V_79 . V_80 ) ;
#endif
}
static inline void F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_19 ( V_2 , L_27
L_28 ,
V_4 -> V_81 ,
V_4 -> V_82 ) ;
}
static void F_49 ( struct V_1 * V_2 , struct V_3 * V_83 )
{
F_3 ( V_2 , L_29 ) ;
F_50 ( V_2 , & V_83 -> V_84 ) ;
F_4 ( V_2 , '\n' ) ;
F_3 ( V_2 , L_30 ) ;
F_51 ( V_2 , & V_83 -> V_84 ) ;
F_4 ( V_2 , '\n' ) ;
}
int F_52 ( struct V_1 * V_2 , struct V_19 * V_20 ,
struct V_21 * V_21 , struct V_3 * V_83 )
{
struct V_85 * V_86 = F_53 ( V_83 ) ;
F_1 ( V_2 , V_83 ) ;
F_10 ( V_2 , V_20 , V_21 , V_83 ) ;
if ( V_86 ) {
F_54 ( V_2 , V_86 ) ;
F_55 ( V_86 ) ;
}
F_34 ( V_2 , V_83 ) ;
F_44 ( V_2 , V_83 ) ;
F_46 ( V_2 , V_83 ) ;
F_49 ( V_2 , V_83 ) ;
F_56 ( V_2 , V_83 ) ;
F_48 ( V_2 , V_83 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_19 * V_20 ,
struct V_21 * V_21 , struct V_3 * V_83 , int V_87 )
{
unsigned long V_88 , V_89 , V_90 , V_91 = ~ 0UL ;
int V_92 , V_93 ;
int V_94 = - 1 , V_95 = 0 ;
T_2 V_96 , V_97 ;
char V_15 ;
T_1 V_29 = 0 , V_98 = - 1 , V_99 = - 1 ;
int V_64 = 0 ;
int V_100 ;
struct V_85 * V_86 ;
unsigned long long V_101 ;
unsigned long V_102 = 0 , V_103 = 0 ;
unsigned long V_104 = 0 , V_105 = 0 ;
T_4 V_106 , V_107 , V_108 , V_109 ;
T_4 V_110 , V_111 ;
unsigned long V_112 = 0 ;
char V_9 [ sizeof( V_83 -> V_10 ) ] ;
unsigned long V_58 ;
V_15 = * F_5 ( V_83 ) ;
V_88 = V_89 = V_90 = 0 ;
V_100 = F_58 ( V_83 , V_113 | V_114 ) ;
V_86 = F_53 ( V_83 ) ;
if ( V_86 ) {
V_88 = F_59 ( V_86 ) ;
if ( V_100 ) {
V_89 = F_60 ( V_83 ) ;
V_90 = F_61 ( V_83 ) ;
}
}
F_2 ( V_9 , V_83 ) ;
F_35 ( & V_96 ) ;
F_35 ( & V_97 ) ;
V_106 = V_107 = V_108 = V_109 = 0 ;
V_110 = V_111 = 0 ;
if ( F_36 ( V_83 , & V_58 ) ) {
struct V_115 * V_116 = V_83 -> signal ;
if ( V_116 -> V_117 ) {
struct V_21 * V_118 = F_62 ( V_116 -> V_117 ) ;
V_94 = F_21 ( V_118 , V_20 ) ;
F_63 ( V_118 ) ;
V_95 = F_64 ( F_65 ( V_116 -> V_117 ) ) ;
}
V_64 = F_37 ( V_83 ) ;
F_32 ( V_83 , & V_96 , & V_97 ) ;
V_102 = V_116 -> V_102 ;
V_103 = V_116 -> V_103 ;
V_106 = V_116 -> V_106 ;
V_107 = V_116 -> V_107 ;
V_110 = V_116 -> V_110 ;
V_112 = F_66 ( V_116 -> V_119 [ V_120 ] . V_121 ) ;
if ( V_87 ) {
struct V_3 * V_122 = V_83 ;
do {
V_104 += V_122 -> V_104 ;
V_105 += V_122 -> V_105 ;
V_111 += F_67 ( V_122 ) ;
} while_each_thread(task, t) ;
V_104 += V_116 -> V_104 ;
V_105 += V_116 -> V_105 ;
F_68 ( V_83 , & V_108 , & V_109 ) ;
V_111 += V_116 -> V_111 ;
}
V_99 = F_69 ( V_83 , V_20 ) ;
V_29 = F_14 ( V_83 -> V_31 , V_20 ) ;
V_98 = F_70 ( V_83 , V_20 ) ;
F_41 ( V_83 , & V_58 ) ;
}
int F_71 ( struct V_1 * V_2 , struct V_19 * V_20 ,
struct V_21 * V_21 , struct V_3 * V_83 )
{
return F_57 ( V_2 , V_20 , V_21 , V_83 , 1 ) ;
}
int F_72 ( struct V_1 * V_2 , struct V_19 * V_20 ,
struct V_21 * V_21 , struct V_3 * V_83 )
{
unsigned long V_11 = 0 , V_123 = 0 , V_124 = 0 , V_125 = 0 , V_126 = 0 ;
struct V_85 * V_86 = F_53 ( V_83 ) ;
if ( V_86 ) {
V_11 = F_73 ( V_86 , & V_124 , & V_125 , & V_126 , & V_123 ) ;
F_55 ( V_86 ) ;
}
F_74 ( V_2 , 0 , V_11 ) ;
F_74 ( V_2 , ' ' , V_123 ) ;
F_74 ( V_2 , ' ' , V_124 ) ;
F_74 ( V_2 , ' ' , V_125 ) ;
F_74 ( V_2 , ' ' , 0 ) ;
F_74 ( V_2 , ' ' , V_126 ) ;
F_74 ( V_2 , ' ' , 0 ) ;
F_4 ( V_2 , '\n' ) ;
return 0 ;
}
static struct V_21 *
F_75 ( struct V_127 * V_127 , struct V_21 * V_128 , T_5 V_129 )
{
struct V_3 * V_130 , * V_83 ;
struct V_21 * V_21 = NULL ;
F_76 ( & V_131 ) ;
V_130 = F_77 ( F_78 ( V_127 ) , V_132 ) ;
if ( ! V_130 )
goto V_133;
if ( V_128 ) {
V_83 = F_77 ( V_128 , V_132 ) ;
if ( V_83 && V_83 -> V_31 == V_130 &&
! ( F_79 ( & V_83 -> V_134 ) ) ) {
if ( F_80 ( & V_83 -> V_134 , & V_130 -> V_135 ) )
goto V_133;
V_83 = F_81 ( & V_83 -> V_134 ,
struct V_3 , V_134 ) ;
V_21 = F_82 ( F_83 ( V_83 ) ) ;
goto V_133;
}
}
F_84 (task, &start->children, sibling) {
if ( V_129 -- == 0 ) {
V_21 = F_82 ( F_83 ( V_83 ) ) ;
break;
}
}
V_133:
F_85 ( & V_131 ) ;
return V_21 ;
}
static int F_86 ( struct V_1 * V_136 , void * V_137 )
{
struct V_127 * V_127 = V_136 -> V_138 ;
T_1 V_21 ;
V_21 = F_21 ( V_137 , V_127 -> V_139 -> V_140 ) ;
return F_19 ( V_136 , L_12 , V_21 ) ;
}
static void * F_87 ( struct V_1 * V_136 , T_5 * V_129 )
{
return F_75 ( V_136 -> V_138 , NULL , * V_129 ) ;
}
static void * F_88 ( struct V_1 * V_136 , void * V_137 , T_5 * V_129 )
{
struct V_21 * V_21 ;
V_21 = F_75 ( V_136 -> V_138 , V_137 , * V_129 + 1 ) ;
F_63 ( V_137 ) ;
++ * V_129 ;
return V_21 ;
}
static void F_89 ( struct V_1 * V_136 , void * V_137 )
{
F_63 ( V_137 ) ;
}
static int F_90 ( struct V_127 * V_127 , struct V_141 * V_141 )
{
struct V_1 * V_2 ;
int V_142 ;
V_142 = F_91 ( V_141 , & V_143 ) ;
if ( V_142 )
return V_142 ;
V_2 = V_141 -> V_144 ;
V_2 -> V_138 = V_127 ;
return V_142 ;
}
int F_92 ( struct V_127 * V_127 , struct V_141 * V_141 )
{
F_93 ( V_127 , V_141 ) ;
return 0 ;
}
