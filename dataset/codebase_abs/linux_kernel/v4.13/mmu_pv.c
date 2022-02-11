void F_1 ( void * V_1 )
{
T_1 * V_2 , V_3 ;
unsigned long V_4 = ( unsigned long ) V_1 ;
unsigned int V_5 ;
V_2 = F_2 ( V_4 , & V_5 ) ;
if ( V_2 == NULL )
return;
V_3 = F_3 ( * V_2 ) ;
if ( F_4 ( V_4 , V_3 , 0 ) )
F_5 () ;
}
void F_6 ( void * V_1 )
{
T_1 * V_2 , V_3 ;
unsigned long V_4 = ( unsigned long ) V_1 ;
unsigned int V_5 ;
V_2 = F_2 ( V_4 , & V_5 ) ;
if ( V_2 == NULL )
return;
V_3 = F_7 ( * V_2 ) ;
if ( F_4 ( V_4 , V_3 , 0 ) )
F_5 () ;
}
static bool F_8 ( void * V_6 )
{
struct V_7 * V_7 = F_9 ( V_6 ) ;
return F_10 ( V_7 ) ;
}
void F_11 ( T_1 * V_8 , T_1 V_9 , unsigned V_10 )
{
struct V_11 V_12 ;
struct V_13 * V_14 ;
F_12 ( V_8 , V_9 , V_10 ) ;
V_12 = F_13 ( sizeof( * V_14 ) ) ;
V_14 = V_12 . args ;
V_14 -> V_6 = F_14 ( V_8 ) . V_15 ;
V_14 -> V_16 = F_15 ( V_9 ) ;
F_16 ( V_12 . V_17 , V_12 . args , 1 , NULL , V_10 ) ;
F_17 ( V_18 ) ;
}
static void F_18 ( const struct V_13 * V_19 )
{
struct V_11 V_12 ;
struct V_13 * V_14 ;
V_12 = F_19 ( V_20 , sizeof( * V_14 ) ) ;
if ( V_12 . V_17 != NULL ) {
V_12 . V_17 -> args [ 1 ] ++ ;
} else {
V_12 = F_20 ( sizeof( * V_14 ) ) ;
F_16 ( V_12 . V_17 , V_12 . args , 1 , NULL , V_21 ) ;
}
V_14 = V_12 . args ;
* V_14 = * V_19 ;
}
static void F_21 ( const struct V_22 * V_23 )
{
struct V_11 V_12 ;
struct V_22 * V_14 ;
V_12 = F_19 ( V_24 , sizeof( * V_14 ) ) ;
if ( V_12 . V_17 != NULL ) {
V_12 . V_17 -> args [ 1 ] ++ ;
} else {
V_12 = F_20 ( sizeof( * V_14 ) ) ;
F_22 ( V_12 . V_17 , V_12 . args , 1 , NULL , V_21 ) ;
}
V_14 = V_12 . args ;
* V_14 = * V_23 ;
}
static void F_23 ( T_2 * V_6 , T_2 V_16 )
{
struct V_13 V_14 ;
F_24 () ;
F_25 () ;
V_14 . V_6 = F_26 ( V_6 ) . V_15 ;
V_14 . V_16 = F_27 ( V_16 ) ;
F_18 ( & V_14 ) ;
F_17 ( V_18 ) ;
F_28 () ;
}
static void F_29 ( T_2 * V_6 , T_2 V_16 )
{
F_30 ( V_6 , V_16 ) ;
if ( ! F_8 ( V_6 ) ) {
* V_6 = V_16 ;
return;
}
F_23 ( V_6 , V_16 ) ;
}
void F_31 ( unsigned long V_1 , unsigned long V_25 , T_3 V_26 )
{
F_32 ( V_1 , F_33 ( V_25 , V_26 ) ) ;
}
static bool F_34 ( T_1 * V_8 , T_1 V_9 )
{
struct V_13 V_14 ;
if ( F_35 () != V_18 )
return false ;
F_25 () ;
V_14 . V_6 = F_14 ( V_8 ) . V_15 | V_27 ;
V_14 . V_16 = F_15 ( V_9 ) ;
F_18 ( & V_14 ) ;
F_17 ( V_18 ) ;
return true ;
}
static inline void F_36 ( T_1 * V_8 , T_1 V_9 )
{
if ( ! F_34 ( V_8 , V_9 ) ) {
struct V_13 V_14 ;
V_14 . V_6 = F_14 ( V_8 ) . V_15 | V_27 ;
V_14 . V_16 = F_15 ( V_9 ) ;
F_37 ( & V_14 , 1 , NULL , V_21 ) ;
}
}
static void F_38 ( T_1 * V_8 , T_1 V_9 )
{
F_39 ( V_8 , V_9 ) ;
F_36 ( V_8 , V_9 ) ;
}
static void F_40 ( struct V_28 * V_29 , unsigned long V_30 ,
T_1 * V_8 , T_1 V_9 )
{
F_41 ( V_29 , V_30 , V_8 , V_9 ) ;
F_36 ( V_8 , V_9 ) ;
}
T_1 F_42 ( struct V_28 * V_29 ,
unsigned long V_30 , T_1 * V_8 )
{
F_43 ( V_29 , V_30 , V_8 , * V_8 ) ;
return * V_8 ;
}
void F_44 ( struct V_28 * V_29 , unsigned long V_30 ,
T_1 * V_8 , T_1 V_2 )
{
struct V_13 V_14 ;
F_45 ( V_29 , V_30 , V_8 , V_2 ) ;
F_25 () ;
V_14 . V_6 = F_14 ( V_8 ) . V_15 | V_31 ;
V_14 . V_16 = F_15 ( V_2 ) ;
F_18 ( & V_14 ) ;
F_17 ( V_18 ) ;
}
static T_4 F_46 ( T_4 V_16 )
{
if ( V_16 & V_32 ) {
unsigned long V_25 = ( V_16 & V_33 ) >> V_34 ;
unsigned long V_35 = F_47 ( V_25 ) ;
T_4 V_26 = V_16 & V_36 ;
if ( F_48 ( V_35 == ~ 0 ) )
V_16 = V_26 & ~ V_32 ;
else
V_16 = ( ( T_4 ) V_35 << V_34 ) | V_26 ;
}
return V_16 ;
}
static T_4 F_49 ( T_4 V_16 )
{
if ( V_16 & V_32 ) {
unsigned long V_35 = ( V_16 & V_33 ) >> V_34 ;
T_4 V_26 = V_16 & V_36 ;
unsigned long V_25 ;
V_25 = F_50 ( V_35 ) ;
if ( F_48 ( V_25 == V_37 ) ) {
V_25 = 0 ;
V_26 = 0 ;
} else
V_25 &= ~ ( V_38 | V_39 ) ;
V_16 = ( ( T_4 ) V_25 << V_34 ) | V_26 ;
}
return V_16 ;
}
T_5 T_4 F_51 ( T_1 V_2 )
{
T_4 V_9 = V_2 . V_2 ;
return F_46 ( V_9 ) ;
}
T_5 T_6 F_52 ( T_7 V_40 )
{
return F_46 ( V_40 . V_40 ) ;
}
T_5 T_1 F_53 ( T_4 V_2 )
{
V_2 = F_49 ( V_2 ) ;
return F_54 ( V_2 ) ;
}
T_5 T_7 F_55 ( T_6 V_40 )
{
V_40 = F_49 ( V_40 ) ;
return F_56 ( V_40 ) ;
}
T_5 T_8 F_57 ( T_2 V_41 )
{
return F_46 ( V_41 . V_41 ) ;
}
static void F_58 ( T_9 * V_6 , T_9 V_16 )
{
struct V_13 V_14 ;
F_24 () ;
F_25 () ;
V_14 . V_6 = F_26 ( V_6 ) . V_15 ;
V_14 . V_16 = F_59 ( V_16 ) ;
F_18 ( & V_14 ) ;
F_17 ( V_18 ) ;
F_28 () ;
}
static void F_60 ( T_9 * V_6 , T_9 V_16 )
{
F_61 ( V_6 , V_16 ) ;
if ( ! F_8 ( V_6 ) ) {
* V_6 = V_16 ;
return;
}
F_58 ( V_6 , V_16 ) ;
}
static void F_62 ( T_1 * V_8 , T_1 V_2 )
{
F_63 ( V_8 , V_2 ) ;
F_64 ( ( V_42 * ) V_8 , F_65 ( V_2 ) ) ;
}
static void F_66 ( struct V_28 * V_29 , unsigned long V_30 , T_1 * V_8 )
{
F_67 ( V_29 , V_30 , V_8 ) ;
if ( ! F_34 ( V_8 , F_54 ( 0 ) ) )
F_68 ( V_29 , V_30 , V_8 ) ;
}
static void F_69 ( T_2 * V_43 )
{
F_70 ( V_43 ) ;
F_71 ( V_43 , F_72 ( 0 ) ) ;
}
T_5 T_2 F_73 ( T_8 V_41 )
{
V_41 = F_49 ( V_41 ) ;
return F_74 ( V_41 ) ;
}
T_5 T_10 F_75 ( T_9 V_44 )
{
return F_46 ( V_44 . V_44 ) ;
}
T_5 T_9 F_76 ( T_10 V_44 )
{
V_44 = F_49 ( V_44 ) ;
return F_77 ( V_44 ) ;
}
static T_7 * F_78 ( T_7 * V_40 )
{
T_7 * V_45 = ( T_7 * ) ( ( ( unsigned long ) V_40 ) & V_46 ) ;
unsigned V_47 = V_40 - V_45 ;
T_7 * V_48 = NULL ;
if ( V_47 < F_79 ( V_49 ) ) {
struct V_7 * V_7 = F_9 ( V_45 ) ;
V_48 = ( T_7 * ) V_7 -> V_50 ;
if ( V_48 )
V_48 += V_47 ;
}
return V_48 ;
}
static void F_80 ( T_11 * V_6 , T_11 V_16 )
{
struct V_13 V_14 ;
V_14 . V_6 = F_14 ( V_6 ) . V_15 ;
V_14 . V_16 = F_81 ( V_16 ) ;
F_18 ( & V_14 ) ;
}
static void T_12 F_82 ( T_11 * V_6 , T_11 V_16 )
{
F_24 () ;
F_25 () ;
F_80 ( V_6 , V_16 ) ;
F_17 ( V_18 ) ;
F_28 () ;
}
static void F_83 ( T_11 * V_6 , T_11 V_16 )
{
T_7 * V_48 = F_78 ( ( T_7 * ) V_6 ) ;
T_7 V_51 ;
F_84 ( V_6 , ( T_11 * ) V_48 , V_16 ) ;
if ( ! F_8 ( V_6 ) ) {
* V_6 = V_16 ;
if ( V_48 ) {
F_85 ( F_8 ( V_48 ) ) ;
V_51 . V_40 = F_81 ( V_16 ) ;
* V_48 = V_51 ;
}
return;
}
F_25 () ;
F_80 ( V_6 , V_16 ) ;
if ( V_48 )
F_80 ( ( T_11 * ) V_48 , V_16 ) ;
F_17 ( V_18 ) ;
}
static int F_86 ( struct V_28 * V_29 , T_2 * V_41 ,
int (* F_87)( struct V_28 * V_29 , struct V_7 * , enum V_52 ) ,
bool V_53 , unsigned long V_54 )
{
int V_55 , V_56 , V_57 = 0 ;
V_56 = V_53 ? F_88 ( V_54 ) + 1 : V_58 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
if ( ! F_89 ( V_41 [ V_55 ] ) )
V_57 |= (* F_87)( V_29 , F_90 ( V_41 [ V_55 ] ) , V_59 ) ;
}
return V_57 ;
}
static int F_91 ( struct V_28 * V_29 , T_9 * V_44 ,
int (* F_87)( struct V_28 * V_29 , struct V_7 * , enum V_52 ) ,
bool V_53 , unsigned long V_54 )
{
int V_55 , V_56 , V_57 = 0 ;
V_56 = V_53 ? F_92 ( V_54 ) + 1 : V_60 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
T_2 * V_41 ;
if ( F_93 ( V_44 [ V_55 ] ) )
continue;
V_41 = F_94 ( & V_44 [ V_55 ] , 0 ) ;
if ( V_58 > 1 )
V_57 |= (* F_87)( V_29 , F_9 ( V_41 ) , V_61 ) ;
V_57 |= F_86 ( V_29 , V_41 , F_87 ,
V_53 && V_55 == V_56 - 1 , V_54 ) ;
}
return V_57 ;
}
static int F_95 ( struct V_28 * V_29 , T_11 * V_62 ,
int (* F_87)( struct V_28 * V_29 , struct V_7 * , enum V_52 ) ,
bool V_53 , unsigned long V_54 )
{
int V_55 , V_56 , V_57 = 0 ;
V_56 = V_53 ? F_96 ( V_54 ) + 1 : V_63 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
T_9 * V_44 ;
if ( F_97 ( V_62 [ V_55 ] ) )
continue;
V_44 = F_98 ( & V_62 [ V_55 ] , 0 ) ;
if ( V_60 > 1 )
V_57 |= (* F_87)( V_29 , F_9 ( V_44 ) , V_64 ) ;
V_57 |= F_91 ( V_29 , V_44 , F_87 ,
V_53 && V_55 == V_56 - 1 , V_54 ) ;
}
return V_57 ;
}
static int F_99 ( struct V_28 * V_29 , T_7 * V_40 ,
int (* F_87)( struct V_28 * V_29 , struct V_7 * ,
enum V_52 ) ,
unsigned long V_54 )
{
int V_55 , V_56 , V_57 = 0 ;
unsigned V_65 , V_66 ;
V_54 -- ;
F_100 ( V_54 >= V_67 ) ;
V_65 = F_79 ( V_49 ) ;
V_66 = F_79 ( V_68 ) ;
V_56 = F_79 ( V_54 ) + 1 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
T_11 * V_62 ;
if ( V_55 >= V_65 && V_55 < V_66 )
continue;
if ( F_101 ( V_40 [ V_55 ] ) )
continue;
V_62 = F_102 ( & V_40 [ V_55 ] , 0 ) ;
if ( V_63 > 1 )
V_57 |= (* F_87)( V_29 , F_9 ( V_62 ) , V_69 ) ;
V_57 |= F_95 ( V_29 , V_62 , F_87 , V_55 == V_56 - 1 , V_54 ) ;
}
V_57 |= (* F_87)( V_29 , F_9 ( V_40 ) , V_70 ) ;
return V_57 ;
}
static int F_103 ( struct V_28 * V_29 ,
int (* F_87)( struct V_28 * V_29 , struct V_7 * ,
enum V_52 ) ,
unsigned long V_54 )
{
return F_99 ( V_29 , V_29 -> V_40 , F_87 , V_54 ) ;
}
static T_13 * F_104 ( struct V_7 * V_7 , struct V_28 * V_29 )
{
T_13 * V_71 = NULL ;
#if V_72
V_71 = F_105 ( V_7 ) ;
F_106 ( V_71 , & V_29 -> V_73 ) ;
#endif
return V_71 ;
}
static void F_107 ( void * V_74 )
{
T_13 * V_71 = V_74 ;
F_108 ( V_71 ) ;
}
static void F_109 ( unsigned V_5 , unsigned long V_35 )
{
struct V_22 V_23 ;
V_23 . V_75 = V_5 ;
V_23 . V_76 . V_25 = F_110 ( V_35 ) ;
F_21 ( & V_23 ) ;
}
static int F_111 ( struct V_28 * V_29 , struct V_7 * V_7 ,
enum V_52 V_5 )
{
unsigned V_77 = F_112 ( V_7 ) ;
int V_57 ;
if ( V_77 )
V_57 = 0 ;
else if ( F_113 ( V_7 ) )
V_57 = 1 ;
else {
void * V_78 = F_114 ( V_7 ) ;
unsigned long V_35 = F_115 ( V_7 ) ;
struct V_11 V_12 = F_20 ( 0 ) ;
T_13 * V_71 ;
V_57 = 0 ;
V_71 = NULL ;
if ( V_5 == V_59 )
V_71 = F_104 ( V_7 , V_29 ) ;
F_116 ( V_12 . V_17 , ( unsigned long ) V_78 ,
F_117 ( V_35 , V_79 ) ,
V_5 == V_70 ? V_80 : 0 ) ;
if ( V_71 ) {
F_109 ( V_81 , V_35 ) ;
F_118 ( F_107 , V_71 ) ;
}
}
return V_57 ;
}
static void F_119 ( struct V_28 * V_29 , T_7 * V_40 )
{
F_120 ( V_29 , V_40 ) ;
F_25 () ;
if ( F_99 ( V_29 , V_40 , F_111 , V_49 ) ) {
F_17 ( 0 ) ;
F_121 () ;
F_25 () ;
}
#ifdef F_122
{
T_7 * V_82 = F_78 ( V_40 ) ;
F_109 ( V_83 , F_123 ( F_124 ( V_40 ) ) ) ;
if ( V_82 ) {
F_111 ( V_29 , F_9 ( V_82 ) , V_70 ) ;
F_109 ( V_83 ,
F_123 ( F_124 ( V_82 ) ) ) ;
}
}
#else
#ifdef F_125
F_111 ( V_29 , V_45 ( V_40 [ F_79 ( V_84 ) ] ) ,
V_61 ) ;
#endif
F_109 ( V_85 , F_123 ( F_124 ( V_40 ) ) ) ;
#endif
F_17 ( 0 ) ;
}
static void F_126 ( struct V_28 * V_29 )
{
F_119 ( V_29 , V_29 -> V_40 ) ;
}
void F_127 ( void )
{
struct V_7 * V_7 ;
F_128 ( & V_86 ) ;
F_129 (page, &pgd_list, lru) {
if ( ! F_10 ( V_7 ) ) {
F_119 ( & V_87 , ( T_7 * ) F_130 ( V_7 ) ) ;
F_131 ( V_7 ) ;
}
}
F_108 ( & V_86 ) ;
}
static int T_12 F_132 ( struct V_28 * V_29 , struct V_7 * V_7 ,
enum V_52 V_5 )
{
F_133 ( V_7 ) ;
return 0 ;
}
static void T_12 F_134 ( void )
{
F_103 ( & V_87 , F_132 , V_67 ) ;
}
static int F_135 ( struct V_28 * V_29 , struct V_7 * V_7 ,
enum V_52 V_5 )
{
unsigned V_77 = F_136 ( V_7 ) ;
if ( V_77 && ! F_113 ( V_7 ) ) {
void * V_78 = F_114 ( V_7 ) ;
unsigned long V_35 = F_115 ( V_7 ) ;
T_13 * V_71 = NULL ;
struct V_11 V_12 ;
if ( V_5 == V_59 ) {
V_71 = F_104 ( V_7 , V_29 ) ;
if ( V_71 )
F_109 ( V_88 , V_35 ) ;
}
V_12 = F_20 ( 0 ) ;
F_116 ( V_12 . V_17 , ( unsigned long ) V_78 ,
F_117 ( V_35 , V_89 ) ,
V_5 == V_70 ? V_80 : 0 ) ;
if ( V_71 ) {
F_118 ( F_107 , V_71 ) ;
}
}
return 0 ;
}
static void F_137 ( struct V_28 * V_29 , T_7 * V_40 )
{
F_138 ( V_29 , V_40 ) ;
F_25 () ;
F_109 ( V_88 , F_123 ( F_124 ( V_40 ) ) ) ;
#ifdef F_122
{
T_7 * V_82 = F_78 ( V_40 ) ;
if ( V_82 ) {
F_109 ( V_88 ,
F_123 ( F_124 ( V_82 ) ) ) ;
F_135 ( V_29 , F_9 ( V_82 ) , V_70 ) ;
}
}
#endif
#ifdef F_125
F_135 ( V_29 , V_45 ( V_40 [ F_79 ( V_84 ) ] ) ,
V_61 ) ;
#endif
F_99 ( V_29 , V_40 , F_135 , V_49 ) ;
F_17 ( 0 ) ;
}
static void F_139 ( struct V_28 * V_29 )
{
F_137 ( V_29 , V_29 -> V_40 ) ;
}
void F_140 ( void )
{
struct V_7 * V_7 ;
F_128 ( & V_86 ) ;
F_129 (page, &pgd_list, lru) {
if ( F_141 ( V_7 ) ) {
F_100 ( ! F_10 ( V_7 ) ) ;
F_137 ( & V_87 , ( T_7 * ) F_130 ( V_7 ) ) ;
F_142 ( V_7 ) ;
}
}
F_108 ( & V_86 ) ;
}
static void F_143 ( struct V_28 * V_90 , struct V_28 * V_91 )
{
F_128 ( & V_91 -> V_73 ) ;
F_126 ( V_91 ) ;
F_108 ( & V_91 -> V_73 ) ;
}
static void F_144 ( struct V_28 * V_92 , struct V_28 * V_29 )
{
F_128 ( & V_29 -> V_73 ) ;
F_126 ( V_29 ) ;
F_108 ( & V_29 -> V_73 ) ;
}
static void F_145 ( void * V_93 )
{
struct V_28 * V_29 = V_93 ;
if ( F_146 ( V_94 . V_95 ) == V_29 )
F_147 ( F_148 () ) ;
if ( F_146 ( V_96 ) == F_124 ( V_29 -> V_40 ) )
F_149 () ;
}
static void F_150 ( struct V_28 * V_29 )
{
T_14 V_97 ;
unsigned V_98 ;
F_145 ( V_29 ) ;
if ( ! F_151 ( & V_97 , V_99 ) ) {
F_152 (cpu) {
if ( ! F_153 ( V_98 , F_154 ( V_29 ) )
&& F_155 ( V_96 , V_98 ) != F_124 ( V_29 -> V_40 ) )
continue;
F_156 ( V_98 , F_145 , V_29 , 1 ) ;
}
return;
}
F_157 ( V_97 , F_154 ( V_29 ) ) ;
F_152 (cpu) {
if ( F_155 ( V_96 , V_98 ) == F_124 ( V_29 -> V_40 ) )
F_158 ( V_98 , V_97 ) ;
}
F_159 ( V_97 , F_145 , V_29 , 1 ) ;
F_160 ( V_97 ) ;
}
static void F_150 ( struct V_28 * V_29 )
{
F_145 ( V_29 ) ;
}
static void F_161 ( struct V_28 * V_29 )
{
F_162 () ;
F_150 ( V_29 ) ;
F_163 () ;
F_128 ( & V_29 -> V_73 ) ;
if ( F_8 ( V_29 -> V_40 ) )
F_139 ( V_29 ) ;
F_108 ( & V_29 -> V_73 ) ;
}
static void T_12 F_164 ( unsigned V_75 , unsigned long V_35 )
{
struct V_22 V_23 ;
V_23 . V_75 = V_75 ;
V_23 . V_76 . V_25 = F_110 ( V_35 ) ;
if ( F_165 ( & V_23 , 1 , NULL , V_21 ) )
F_5 () ;
}
static void T_12 F_166 ( unsigned long V_1 ,
unsigned long V_100 )
{
unsigned long V_101 = F_167 ( ( unsigned long ) V_102 , V_103 ) - 1 ;
T_2 * V_41 = V_104 + F_88 ( V_1 ) ;
for (; V_1 <= V_100 && ( V_41 < ( V_104 + V_58 ) ) ;
V_41 ++ , V_1 += V_103 ) {
if ( F_89 ( * V_41 ) )
continue;
if ( V_1 < ( unsigned long ) V_105 || V_1 > V_101 )
F_71 ( V_41 , F_72 ( 0 ) ) ;
}
F_149 () ;
}
static void T_12 F_168 ( unsigned long V_106 , unsigned long V_107 )
{
void * V_1 = F_169 ( V_106 ) ;
void * V_100 = V_1 + V_107 ;
for (; V_1 < V_100 ; V_1 += V_108 )
F_6 ( V_1 ) ;
F_170 ( V_106 , V_107 ) ;
}
static void T_12 F_171 ( void * V_109 , bool V_110 )
{
unsigned long V_111 = F_124 ( V_109 ) & V_112 ;
if ( V_110 )
F_164 ( V_88 , F_123 ( V_111 ) ) ;
F_172 ( F_9 ( F_169 ( V_111 ) ) ) ;
F_168 ( V_111 , V_108 ) ;
}
static void T_12 F_173 ( T_2 * V_41 , bool V_110 )
{
unsigned long V_111 ;
T_1 * V_113 ;
int V_55 ;
if ( F_174 ( * V_41 ) ) {
V_111 = F_175 ( * V_41 ) & V_112 ;
F_168 ( V_111 , V_103 ) ;
return;
}
V_113 = F_176 ( V_41 , 0 ) ;
for ( V_55 = 0 ; V_55 < V_114 ; V_55 ++ ) {
if ( F_177 ( V_113 [ V_55 ] ) )
continue;
V_111 = F_178 ( V_113 [ V_55 ] ) << V_34 ;
F_168 ( V_111 , V_108 ) ;
}
F_71 ( V_41 , F_72 ( 0 ) ) ;
F_171 ( V_113 , V_110 ) ;
}
static void T_12 F_179 ( T_9 * V_44 , bool V_110 )
{
unsigned long V_111 ;
T_2 * V_115 ;
int V_55 ;
if ( F_180 ( * V_44 ) ) {
V_111 = F_181 ( * V_44 ) & V_112 ;
F_168 ( V_111 , V_116 ) ;
return;
}
V_115 = F_94 ( V_44 , 0 ) ;
for ( V_55 = 0 ; V_55 < V_58 ; V_55 ++ ) {
if ( F_89 ( V_115 [ V_55 ] ) )
continue;
F_173 ( V_115 + V_55 , V_110 ) ;
}
F_182 ( V_44 , F_183 ( 0 ) ) ;
F_171 ( V_115 , V_110 ) ;
}
static void T_12 F_184 ( T_11 * V_62 , bool V_110 )
{
unsigned long V_111 ;
T_9 * V_117 ;
int V_55 ;
if ( F_185 ( * V_62 ) ) {
V_111 = F_186 ( * V_62 ) & V_112 ;
F_168 ( V_111 , V_118 ) ;
return;
}
V_117 = F_98 ( V_62 , 0 ) ;
for ( V_55 = 0 ; V_55 < V_60 ; V_55 ++ ) {
if ( F_93 ( V_117 [ V_55 ] ) )
continue;
F_179 ( V_117 + V_55 , V_110 ) ;
}
F_187 ( V_62 , F_188 ( 0 ) ) ;
F_171 ( V_117 , V_110 ) ;
}
static void T_12 F_189 ( unsigned long V_1 )
{
T_7 * V_40 ;
T_11 * V_62 ;
unsigned int V_55 ;
bool V_110 ;
V_110 = ( V_1 == 2 * V_119 ) ;
V_1 &= V_120 ;
V_40 = F_190 ( V_1 ) ;
V_62 = F_102 ( V_40 , 0 ) ;
for ( V_55 = 0 ; V_55 < V_63 ; V_55 ++ ) {
if ( F_97 ( V_62 [ V_55 ] ) )
continue;
F_184 ( V_62 + V_55 , V_110 ) ;
}
if ( F_191 ( V_121 ) ) {
F_192 ( V_40 , F_193 ( 0 ) ) ;
F_171 ( V_62 , V_110 ) ;
}
}
static void T_12 F_194 ( void )
{
unsigned long V_107 ;
unsigned long V_30 ;
V_107 = F_195 ( V_122 -> V_123 * sizeof( unsigned long ) ) ;
if ( ( unsigned long ) V_124 == V_122 -> V_125 )
return;
memset ( ( void * ) V_122 -> V_125 , 0xff , V_107 ) ;
V_30 = V_122 -> V_125 ;
V_107 = F_167 ( V_107 , V_103 ) ;
if ( V_30 >= V_126 ) {
F_166 ( V_30 , V_30 + V_107 ) ;
V_107 = F_195 ( V_122 -> V_123 *
sizeof( unsigned long ) ) ;
F_170 ( F_124 ( V_30 ) , V_107 ) ;
} else {
F_189 ( V_30 ) ;
}
}
static void T_12 F_196 ( void )
{
unsigned long V_107 ;
unsigned long V_30 ;
V_30 = V_122 -> V_127 ;
V_107 = F_167 ( V_122 -> V_128 * V_108 , V_103 ) ;
F_166 ( V_30 , V_30 + V_107 ) ;
V_122 -> V_127 = ( unsigned long ) F_169 ( F_124 ( V_122 -> V_127 ) ) ;
#ifdef F_197
F_166 ( V_129 , F_167 ( V_129 , V_116 ) - 1 ) ;
#endif
}
static void T_12 F_198 ( void )
{
F_199 () ;
#ifdef F_122
F_194 () ;
F_196 () ;
#endif
V_122 -> V_125 = ( unsigned long ) V_124 ;
}
static void T_12 F_200 ( void )
{
F_201 () ;
F_202 () ;
F_198 () ;
F_203 () ;
F_204 () ;
F_205 () ;
}
static void F_206 ( unsigned long V_130 )
{
F_146 ( V_131 ) -> V_132 . V_130 = V_130 ;
}
static unsigned long F_207 ( void )
{
return F_146 ( V_131 ) -> V_132 . V_130 ;
}
unsigned long F_208 ( void )
{
return F_146 ( V_133 . V_132 . V_130 ) ;
}
static void F_209 ( void )
{
struct V_22 * V_23 ;
struct V_11 V_12 ;
F_210 ( 0 ) ;
F_24 () ;
V_12 = F_13 ( sizeof( * V_23 ) ) ;
V_23 = V_12 . args ;
V_23 -> V_75 = V_134 ;
F_22 ( V_12 . V_17 , V_23 , 1 , NULL , V_21 ) ;
F_17 ( V_18 ) ;
F_28 () ;
}
static void F_211 ( unsigned long V_30 )
{
struct V_22 * V_23 ;
struct V_11 V_12 ;
F_212 ( V_30 ) ;
F_24 () ;
V_12 = F_13 ( sizeof( * V_23 ) ) ;
V_23 = V_12 . args ;
V_23 -> V_75 = V_135 ;
V_23 -> V_76 . V_136 = V_30 & V_46 ;
F_22 ( V_12 . V_17 , V_23 , 1 , NULL , V_21 ) ;
F_17 ( V_18 ) ;
F_28 () ;
}
static void F_213 ( const struct V_137 * V_138 ,
const struct V_139 * V_93 )
{
struct {
struct V_22 V_23 ;
#ifdef F_214
F_215 ( V_97 , V_140 ) ;
#else
F_215 ( V_97 , V_141 ) ;
#endif
} * args ;
struct V_11 V_12 ;
F_216 ( V_138 , V_93 -> V_29 , V_93 -> V_142 , V_93 -> V_143 ) ;
if ( F_217 ( V_138 ) )
return;
V_12 = F_13 ( sizeof( * args ) ) ;
args = V_12 . args ;
args -> V_23 . V_144 . V_145 = F_218 ( args -> V_97 ) ;
F_219 ( F_218 ( args -> V_97 ) , V_138 , V_146 ) ;
F_220 ( F_148 () , F_218 ( args -> V_97 ) ) ;
args -> V_23 . V_75 = V_147 ;
if ( V_93 -> V_143 != V_148 &&
( V_93 -> V_143 - V_93 -> V_142 ) <= V_108 ) {
args -> V_23 . V_75 = V_149 ;
args -> V_23 . V_76 . V_136 = V_93 -> V_142 ;
}
F_22 ( V_12 . V_17 , & args -> V_23 , 1 , NULL , V_21 ) ;
F_17 ( V_18 ) ;
}
static unsigned long F_221 ( void )
{
return F_146 ( V_150 ) ;
}
static void F_222 ( void * V_74 )
{
F_223 ( V_96 , ( unsigned long ) V_74 ) ;
}
static void F_224 ( bool V_151 , unsigned long V_152 )
{
struct V_22 V_23 ;
unsigned long V_25 ;
F_225 ( V_151 , V_152 ) ;
if ( V_152 )
V_25 = F_110 ( F_123 ( V_152 ) ) ;
else
V_25 = 0 ;
F_85 ( V_25 == 0 && V_151 ) ;
V_23 . V_75 = V_151 ? V_153 : V_154 ;
V_23 . V_76 . V_25 = V_25 ;
F_21 ( & V_23 ) ;
if ( V_151 ) {
F_223 ( V_150 , V_152 ) ;
F_118 ( F_222 , ( void * ) V_152 ) ;
}
}
static void F_226 ( unsigned long V_152 )
{
F_100 ( F_227 () ) ;
F_25 () ;
F_223 ( V_150 , V_152 ) ;
F_224 ( true , V_152 ) ;
#ifdef F_122
{
T_7 * V_82 = F_78 ( F_169 ( V_152 ) ) ;
if ( V_82 )
F_224 ( false , F_124 ( V_82 ) ) ;
else
F_224 ( false , 0 ) ;
}
#endif
F_17 ( V_155 ) ;
}
static void T_12 F_228 ( unsigned long V_152 )
{
F_100 ( F_227 () ) ;
F_25 () ;
F_223 ( V_150 , V_152 ) ;
F_224 ( true , V_152 ) ;
F_17 ( V_155 ) ;
}
static int F_229 ( struct V_28 * V_29 )
{
T_7 * V_40 = V_29 -> V_40 ;
int V_156 = 0 ;
F_100 ( F_10 ( F_9 ( V_40 ) ) ) ;
#ifdef F_122
{
struct V_7 * V_7 = F_9 ( V_40 ) ;
T_7 * V_82 ;
F_100 ( V_7 -> V_50 != 0 ) ;
V_156 = - V_157 ;
V_82 = ( T_7 * ) F_230 ( V_158 | V_159 ) ;
V_7 -> V_50 = ( unsigned long ) V_82 ;
if ( V_82 != NULL ) {
#ifdef F_231
V_82 [ F_79 ( V_160 ) ] =
F_193 ( F_124 ( V_161 ) | V_162 ) ;
#endif
V_156 = 0 ;
}
F_100 ( F_10 ( F_9 ( F_78 ( V_40 ) ) ) ) ;
}
#endif
return V_156 ;
}
static void F_232 ( struct V_28 * V_29 , T_7 * V_40 )
{
#ifdef F_122
T_7 * V_82 = F_78 ( V_40 ) ;
if ( V_82 )
F_233 ( ( unsigned long ) V_82 ) ;
#endif
}
T_5 T_1 F_234 ( T_4 V_2 )
{
#ifdef F_122
unsigned long V_35 ;
V_35 = ( V_2 & V_33 ) >> V_34 ;
if ( V_122 -> V_125 < V_126 &&
V_35 >= V_122 -> V_163 &&
V_35 < V_122 -> V_163 + V_122 -> V_164 )
V_2 &= ~ V_165 ;
#endif
V_2 = F_49 ( V_2 ) ;
return F_54 ( V_2 ) ;
}
static void T_12 F_235 ( T_1 * V_8 , T_1 V_2 )
{
#ifdef F_236
if ( F_237 ( V_2 ) != V_37
&& F_15 ( * V_8 ) & V_32 )
V_2 = F_238 ( ( ( F_15 ( * V_8 ) & V_165 ) | ~ V_165 ) &
F_15 ( V_2 ) ) ;
#endif
F_239 ( V_8 , V_2 ) ;
}
static void T_12 F_240 ( struct V_28 * V_29 , unsigned long V_35 )
{
#ifdef F_241
F_100 ( V_166 ) ;
#endif
F_1 ( F_169 ( F_242 ( V_35 ) ) ) ;
F_164 ( V_81 , V_35 ) ;
}
static void T_12 F_243 ( struct V_28 * V_29 , unsigned long V_35 )
{
#ifdef F_241
F_100 ( V_166 ) ;
#endif
F_1 ( F_169 ( F_242 ( V_35 ) ) ) ;
}
static void T_12 F_244 ( unsigned long V_35 )
{
F_164 ( V_88 , V_35 ) ;
F_6 ( F_169 ( F_242 ( V_35 ) ) ) ;
}
static void T_12 F_245 ( unsigned long V_35 )
{
F_6 ( F_169 ( F_242 ( V_35 ) ) ) ;
}
static inline void F_246 ( unsigned V_75 , unsigned long V_35 )
{
struct V_11 V_12 ;
struct V_22 * V_23 ;
V_12 = F_20 ( sizeof( * V_23 ) ) ;
V_23 = V_12 . args ;
V_23 -> V_75 = V_75 ;
V_23 -> V_76 . V_25 = F_110 ( V_35 ) ;
F_22 ( V_12 . V_17 , V_12 . args , 1 , NULL , V_21 ) ;
}
static inline void F_247 ( unsigned long V_35 , T_3 V_167 )
{
struct V_11 V_12 ;
unsigned long V_30 = ( unsigned long ) F_169 ( V_35 << V_34 ) ;
V_12 = F_20 ( 0 ) ;
F_116 ( V_12 . V_17 , ( unsigned long ) V_30 ,
F_117 ( V_35 , V_167 ) , 0 ) ;
}
static inline void F_248 ( struct V_28 * V_29 , unsigned long V_35 ,
unsigned V_5 )
{
bool V_168 = F_10 ( F_9 ( V_29 -> V_40 ) ) ;
F_249 ( V_29 , V_35 , V_5 , V_168 ) ;
if ( V_168 ) {
struct V_7 * V_7 = F_250 ( V_35 ) ;
F_133 ( V_7 ) ;
if ( ! F_113 ( V_7 ) ) {
F_25 () ;
F_247 ( V_35 , V_79 ) ;
if ( V_5 == V_59 && V_72 )
F_246 ( V_81 , V_35 ) ;
F_17 ( V_18 ) ;
} else {
F_121 () ;
}
}
}
static void F_251 ( struct V_28 * V_29 , unsigned long V_35 )
{
F_248 ( V_29 , V_35 , V_59 ) ;
}
static void F_252 ( struct V_28 * V_29 , unsigned long V_35 )
{
F_248 ( V_29 , V_35 , V_61 ) ;
}
static inline void F_253 ( unsigned long V_35 , unsigned V_5 )
{
struct V_7 * V_7 = F_250 ( V_35 ) ;
bool V_168 = F_10 ( V_7 ) ;
F_254 ( V_35 , V_5 , V_168 ) ;
if ( V_168 ) {
if ( ! F_113 ( V_7 ) ) {
F_25 () ;
if ( V_5 == V_59 && V_72 )
F_246 ( V_88 , V_35 ) ;
F_247 ( V_35 , V_89 ) ;
F_17 ( V_18 ) ;
}
F_172 ( V_7 ) ;
}
}
static void F_255 ( unsigned long V_35 )
{
F_253 ( V_35 , V_59 ) ;
}
static void F_256 ( unsigned long V_35 )
{
F_253 ( V_35 , V_61 ) ;
}
static void F_257 ( struct V_28 * V_29 , unsigned long V_35 )
{
F_248 ( V_29 , V_35 , V_64 ) ;
}
static void F_258 ( unsigned long V_35 )
{
F_253 ( V_35 , V_64 ) ;
}
void T_12 F_259 ( void )
{
#ifdef F_236
unsigned long V_169 = V_170 ;
struct V_171 V_172 ;
if ( F_260 ( V_173 , & V_172 ) == 0 )
V_169 = V_172 . V_174 ;
F_261 ( - V_169 ) ;
#endif
}
static void * T_12 F_262 ( T_15 V_106 )
{
#ifdef F_122
return ( void * ) ( V_106 + V_126 ) ;
#else
return F_169 ( V_106 ) ;
#endif
}
static unsigned long T_12 F_263 ( T_15 V_15 )
{
T_15 V_106 ;
V_15 &= V_33 ;
V_106 = F_47 ( V_15 >> V_34 ) << V_34 ;
return V_106 ;
}
static void * T_12 F_264 ( T_15 V_15 )
{
return F_262 ( F_263 ( V_15 ) ) ;
}
static void T_12 F_265 ( void * V_30 , T_3 V_167 ,
unsigned long V_26 )
{
unsigned long V_35 = F_124 ( V_30 ) >> V_34 ;
T_1 V_2 = F_117 ( V_35 , V_167 ) ;
if ( F_4 ( ( unsigned long ) V_30 , V_2 , V_26 ) )
F_5 () ;
}
static void T_12 F_266 ( void * V_30 , T_3 V_167 )
{
return F_265 ( V_30 , V_167 , V_175 ) ;
}
static void T_12 F_267 ( T_2 * V_41 , unsigned long V_176 )
{
unsigned V_177 , V_178 ;
unsigned V_179 ;
unsigned long V_35 ;
V_180 = F_268 ( sizeof( T_1 ) * V_181 ,
V_108 ) ;
V_179 = 0 ;
V_35 = 0 ;
for ( V_177 = 0 ; V_177 < V_58 && V_35 < V_176 ; V_177 ++ ) {
T_1 * V_182 ;
if ( F_269 ( V_41 [ V_177 ] ) )
V_182 = F_264 ( V_41 [ V_177 ] . V_41 ) ;
else {
if ( V_179 == V_181 )
break;
V_182 = & V_180 [ V_179 ] ;
V_179 += V_114 ;
V_41 [ V_177 ] = F_72 ( F_124 ( V_182 ) | V_162 ) ;
}
for ( V_178 = 0 ; V_178 < V_114 ; V_178 ++ , V_35 ++ ) {
T_1 V_2 ;
if ( V_35 > V_183 )
V_183 = V_35 ;
if ( ! F_177 ( V_182 [ V_178 ] ) )
continue;
V_2 = F_117 ( V_35 , V_184 ) ;
V_182 [ V_178 ] = V_2 ;
}
}
for ( V_178 = 0 ; V_178 < V_179 ; V_178 += V_114 )
F_266 ( & V_180 [ V_178 ] , V_79 ) ;
F_266 ( V_41 , V_79 ) ;
}
void T_12 F_270 ( void )
{
struct V_185 V_186 ;
if ( F_271 ( V_187 , & V_186 ) == 0 ) {
V_188 = ( unsigned long * ) V_186 . V_189 ;
V_190 = V_186 . V_191 + 1 ;
} else {
V_190 = V_192 ;
}
#ifdef F_236
F_85 ( ( V_188 + ( V_190 - 1 ) )
< V_188 ) ;
#endif
}
static void T_12 F_272 ( void * V_74 )
{
T_1 * V_2 = V_74 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_114 ; V_55 ++ )
V_2 [ V_55 ] = F_53 ( V_2 [ V_55 ] . V_2 ) ;
}
static void T_12 F_273 ( unsigned long * V_127 , unsigned long * V_193 ,
unsigned long V_30 )
{
if ( * V_127 == F_123 ( F_124 ( V_30 ) ) ) {
F_265 ( ( void * ) V_30 , V_89 , V_194 ) ;
F_274 ( ( void * ) V_30 ) ;
( * V_127 ) ++ ;
}
if ( * V_193 == F_123 ( F_124 ( V_30 ) ) ) {
F_265 ( ( void * ) V_30 , V_89 , V_194 ) ;
F_274 ( ( void * ) V_30 ) ;
( * V_193 ) -- ;
}
}
void T_12 F_275 ( T_7 * V_40 , unsigned long V_176 )
{
T_9 * V_195 ;
T_2 * V_196 ;
unsigned long V_30 [ 3 ] ;
unsigned long V_127 , V_193 ;
unsigned V_55 ;
if ( V_122 -> V_125 < V_126 )
V_183 = V_122 -> V_163 ;
else
V_183 = F_123 ( F_124 ( V_122 -> V_125 ) ) ;
V_127 = F_123 ( F_124 ( V_122 -> V_127 ) ) ;
V_193 = V_127 + V_122 -> V_128 ;
V_197 [ 0 ] = F_193 ( 0 ) ;
F_272 ( V_197 ) ;
F_272 ( V_198 ) ;
F_272 ( V_199 ) ;
F_272 ( V_200 ) ;
V_195 = F_264 ( V_40 [ F_79 ( V_126 ) ] . V_40 ) ;
V_196 = F_264 ( V_195 [ F_92 ( V_126 ) ] . V_44 ) ;
V_30 [ 0 ] = ( unsigned long ) V_40 ;
V_30 [ 1 ] = ( unsigned long ) V_195 ;
V_30 [ 2 ] = ( unsigned long ) V_196 ;
F_276 ( V_201 , V_196 ) ;
F_276 ( V_104 , V_196 ) ;
V_55 = F_79 ( V_122 -> V_125 ) ;
if ( V_55 && V_55 < F_79 ( V_126 ) )
V_197 [ V_55 ] = ( ( T_7 * ) V_122 -> V_127 ) [ V_55 ] ;
F_266 ( V_197 , V_79 ) ;
F_266 ( V_198 , V_79 ) ;
F_266 ( V_199 , V_79 ) ;
F_266 ( V_161 , V_79 ) ;
F_266 ( V_201 , V_79 ) ;
F_266 ( V_104 , V_79 ) ;
F_266 ( V_200 , V_79 ) ;
F_266 ( V_202 , V_79 ) ;
F_164 ( V_83 ,
F_123 ( F_277 ( V_197 ) ) ) ;
F_164 ( V_88 , F_123 ( F_124 ( V_40 ) ) ) ;
F_25 () ;
F_224 ( true , F_124 ( V_197 ) ) ;
F_17 ( V_155 ) ;
for ( V_55 = 0 ; V_55 < F_278 ( V_30 ) ; V_55 ++ )
F_273 ( & V_127 , & V_193 , V_30 [ V_55 ] ) ;
V_203 = F_242 ( V_127 ) ;
V_204 = ( V_193 - V_127 ) * V_108 ;
F_279 ( V_203 , V_204 ) ;
V_122 = (struct V_205 * ) F_169 ( F_124 ( V_122 ) ) ;
}
static unsigned long T_12 F_280 ( T_15 V_30 )
{
unsigned long * V_1 ;
unsigned long V_16 ;
V_1 = F_281 ( V_30 , sizeof( V_16 ) ) ;
V_16 = * V_1 ;
F_282 ( V_1 , sizeof( V_16 ) ) ;
return V_16 ;
}
static T_15 T_12 F_283 ( unsigned long V_1 )
{
T_15 V_111 ;
T_7 V_40 ;
T_9 V_44 ;
T_2 V_41 ;
T_1 V_2 ;
V_111 = F_284 () ;
V_40 = F_56 ( F_280 ( V_111 + F_79 ( V_1 ) *
sizeof( V_40 ) ) ) ;
if ( ! F_285 ( V_40 ) )
return 0 ;
V_111 = V_51 ( V_40 ) & V_33 ;
V_44 = F_77 ( F_280 ( V_111 + F_92 ( V_1 ) *
sizeof( V_44 ) ) ) ;
if ( ! F_286 ( V_44 ) )
return 0 ;
V_111 = F_181 ( V_44 ) & V_33 ;
if ( F_180 ( V_44 ) )
return V_111 + ( V_1 & ~ V_206 ) ;
V_41 = F_74 ( F_280 ( V_111 + F_88 ( V_1 ) *
sizeof( V_41 ) ) ) ;
if ( ! F_269 ( V_41 ) )
return 0 ;
V_111 = F_175 ( V_41 ) & V_33 ;
if ( F_174 ( V_41 ) )
return V_111 + ( V_1 & ~ V_120 ) ;
V_2 = F_54 ( F_280 ( V_111 + F_287 ( V_1 ) *
sizeof( V_2 ) ) ) ;
if ( ! F_288 ( V_2 ) )
return 0 ;
V_111 = F_178 ( V_2 ) << V_34 ;
return V_111 | ( V_1 & ~ V_46 ) ;
}
void T_12 F_289 ( void )
{
T_15 V_107 , V_207 , V_208 , V_209 , V_210 , V_211 ;
unsigned long V_212 , V_213 , V_214 , V_35 , V_215 ;
int V_216 , V_217 , V_218 , V_219 , V_220 , V_221 , V_222 , V_223 , V_224 , V_225 ;
T_1 * V_78 ;
T_2 * V_41 ;
T_9 * V_44 ;
T_11 * V_62 = NULL ;
T_7 * V_40 ;
unsigned long * V_226 ;
int V_227 ;
V_107 = F_195 ( V_122 -> V_123 * sizeof( unsigned long ) ) ;
V_216 = F_167 ( V_107 , V_108 ) >> V_34 ;
V_217 = F_167 ( V_107 , V_103 ) >> V_228 ;
V_218 = F_167 ( V_107 , V_116 ) >> V_229 ;
V_219 = F_167 ( V_107 , V_118 ) >> V_230 ;
if ( V_63 > 1 )
V_220 = F_167 ( V_107 , V_119 ) >> V_231 ;
else
V_220 = 0 ;
V_214 = V_216 + V_217 + V_218 + V_219 + V_220 ;
V_207 = F_290 ( F_242 ( V_214 ) ) ;
if ( ! V_207 ) {
F_291 ( L_1 ) ;
F_5 () ;
}
V_211 = V_207 ;
V_210 = V_211 + F_242 ( V_220 ) ;
V_209 = V_210 + F_242 ( V_219 ) ;
V_208 = V_209 + F_242 ( V_218 ) ;
V_212 = F_123 ( V_208 ) + V_217 ;
V_40 = F_169 ( F_284 () ) ;
V_226 = ( unsigned long * ) ( 2 * V_119 ) ;
V_225 = 0 ;
V_227 = V_219 ;
do {
if ( V_220 > 0 ) {
V_62 = F_292 ( V_211 , V_108 ) ;
F_274 ( V_62 ) ;
V_219 = F_293 ( V_227 , V_63 ) ;
}
for ( V_224 = 0 ; V_224 < V_219 ; V_224 ++ ) {
V_44 = F_292 ( V_210 , V_108 ) ;
F_274 ( V_44 ) ;
for ( V_223 = 0 ; V_223 < F_293 ( V_218 , V_60 ) ;
V_223 ++ ) {
V_41 = F_292 ( V_209 , V_108 ) ;
F_274 ( V_41 ) ;
for ( V_222 = 0 ; V_222 < F_293 ( V_217 , V_58 ) ;
V_222 ++ ) {
V_78 = F_292 ( V_208 , V_108 ) ;
F_274 ( V_78 ) ;
for ( V_221 = 0 ;
V_221 < F_293 ( V_216 , V_114 ) ;
V_221 ++ ) {
F_294 ( V_78 + V_221 ,
F_117 ( V_212 , V_89 ) ) ;
V_212 ++ ;
}
V_216 -= V_114 ;
F_282 ( V_78 , V_108 ) ;
F_1 ( F_169 ( V_208 ) ) ;
F_164 ( V_81 ,
F_123 ( V_208 ) ) ;
F_71 ( V_41 + V_222 ,
F_72 ( V_162 | V_208 ) ) ;
V_208 += V_108 ;
}
V_217 -= V_58 ;
F_282 ( V_41 , V_108 ) ;
F_1 ( F_169 ( V_209 ) ) ;
F_164 ( V_232 ,
F_123 ( V_209 ) ) ;
F_182 ( V_44 + V_223 , F_183 ( V_162 | V_209 ) ) ;
V_209 += V_108 ;
}
V_218 -= V_60 ;
F_282 ( V_44 , V_108 ) ;
F_1 ( F_169 ( V_210 ) ) ;
F_164 ( V_85 , F_123 ( V_210 ) ) ;
if ( V_220 > 0 )
F_187 ( V_62 + V_224 , F_188 ( V_162 | V_210 ) ) ;
else
F_192 ( V_40 + 2 + V_224 , F_193 ( V_162 | V_210 ) ) ;
V_210 += V_108 ;
}
if ( V_220 > 0 ) {
V_227 -= V_63 ;
F_282 ( V_62 , V_108 ) ;
F_1 ( F_169 ( V_211 ) ) ;
F_164 ( V_83 , F_123 ( V_211 ) ) ;
F_192 ( V_40 + 2 + V_225 , F_193 ( V_162 | V_211 ) ) ;
V_211 += V_108 ;
}
} while ( ++ V_225 < V_220 );
memcpy ( V_226 , V_124 , V_107 ) ;
V_124 = V_226 ;
V_212 = F_123 ( F_283 ( V_122 -> V_125 ) ) ;
F_100 ( ! V_212 ) ;
V_213 = V_212 + F_123 ( V_107 ) ;
if ( V_122 -> V_125 < V_126 ) {
V_35 = V_122 -> V_163 ;
V_215 = V_122 -> V_163 +
V_122 -> V_164 ;
F_192 ( V_40 + 1 , F_193 ( 0 ) ) ;
} else {
V_35 = V_212 ;
V_215 = V_213 ;
}
F_170 ( F_242 ( V_35 ) , V_108 * ( V_215 - V_35 ) ) ;
while ( V_35 < V_215 ) {
if ( V_35 == V_212 ) {
V_35 = V_213 ;
continue;
}
F_6 ( F_169 ( F_242 ( V_35 ) ) ) ;
V_35 ++ ;
}
V_122 -> V_125 = ( unsigned long ) V_124 ;
V_122 -> V_163 = F_123 ( V_207 ) ;
V_122 -> V_164 = V_214 ;
}
static void T_12 F_228 ( unsigned long V_152 )
{
unsigned long V_35 = F_123 ( F_124 ( V_233 ) ) ;
F_100 ( F_284 () != F_124 ( V_234 ) ) ;
F_100 ( V_152 != F_124 ( V_233 ) ) ;
V_235 =
F_268 ( sizeof( T_2 ) * V_58 , V_108 ) ;
F_276 ( V_235 , V_236 ) ;
V_233 [ V_237 ] =
F_193 ( F_124 ( V_235 ) | V_32 ) ;
F_266 ( V_235 , V_79 ) ;
F_266 ( V_233 , V_79 ) ;
F_226 ( V_152 ) ;
F_164 ( V_85 , V_35 ) ;
F_164 ( V_88 ,
F_123 ( F_124 ( V_234 ) ) ) ;
F_266 ( V_234 , V_89 ) ;
F_266 ( V_236 , V_89 ) ;
V_238 . V_239 = & F_226 ;
}
static T_15 F_295 ( T_2 * V_41 )
{
T_15 V_127 , V_106 ;
unsigned V_177 ;
V_127 = F_293 ( F_124 ( V_122 -> V_127 ) , F_124 ( V_41 ) ) ;
for ( V_177 = 0 ; V_177 < V_58 ; V_177 ++ )
if ( F_269 ( V_41 [ V_177 ] ) && ! F_174 ( V_41 [ V_177 ] ) ) {
V_106 = F_263 ( V_41 [ V_177 ] . V_41 ) ;
V_127 = F_293 ( V_127 , V_106 ) ;
}
return V_127 ;
}
void T_12 F_275 ( T_7 * V_40 , unsigned long V_176 )
{
T_2 * V_240 ;
V_240 = F_264 ( V_40 [ V_237 ] . V_40 ) ;
V_203 = F_295 ( V_240 ) ;
V_204 = V_122 -> V_128 * V_108 ;
V_236 =
F_268 ( sizeof( T_2 ) * V_58 , V_108 ) ;
V_183 = F_123 ( V_203 + V_204 + 512 * 1024 ) ;
F_276 ( V_236 , V_240 ) ;
F_267 ( V_236 , V_176 ) ;
F_276 ( V_234 , V_40 ) ;
V_234 [ V_237 ] =
F_193 ( F_124 ( V_236 ) | V_32 ) ;
F_266 ( V_236 , V_79 ) ;
F_266 ( V_234 , V_79 ) ;
F_266 ( V_241 , V_79 ) ;
F_164 ( V_88 , F_123 ( F_124 ( V_40 ) ) ) ;
F_164 ( V_85 ,
F_123 ( F_124 ( V_234 ) ) ) ;
F_226 ( F_124 ( V_234 ) ) ;
F_279 ( V_203 , V_204 ) ;
}
void T_12 F_296 ( void )
{
T_15 V_106 ;
F_279 ( F_124 ( V_122 ) , V_108 ) ;
if ( V_122 -> V_242 ) {
V_106 = F_242 ( F_47 ( V_122 -> V_242 ) ) ;
F_279 ( V_106 , V_108 ) ;
}
if ( ! F_297 () ) {
V_106 = F_242 ( F_47 ( V_122 -> V_243 . V_244 . V_25 ) ) ;
F_279 ( V_106 , V_108 ) ;
}
}
void T_12 F_298 ( void )
{
if ( F_299 ( V_203 , V_204 ) ) {
F_291 ( L_2 ) ;
F_5 () ;
}
}
static void F_300 ( unsigned V_245 , T_15 V_246 , T_3 V_167 )
{
T_1 V_2 ;
V_246 >>= V_34 ;
switch ( V_245 ) {
case V_247 ... V_248 :
case V_249 :
#ifdef F_236
case V_250 :
# ifdef F_301
case V_251 ... V_252 :
# endif
#elif F_302 ( F_231 )
case V_253 :
#endif
case V_254 :
case V_255 :
case V_256 ... V_257 :
V_2 = F_117 ( V_246 , V_167 ) ;
break;
#ifdef F_303
case V_258 :
V_2 = F_117 ( F_123 ( F_124 ( V_259 ) ) , V_89 ) ;
break;
#endif
#ifdef F_304
case V_260 ... V_261 :
V_2 = F_117 ( F_123 ( F_124 ( V_259 ) ) , V_89 ) ;
break;
#endif
case V_262 :
V_2 = F_33 ( V_246 , V_167 ) ;
break;
default:
V_2 = F_33 ( V_246 , V_167 ) ;
break;
}
F_305 ( V_245 , V_2 ) ;
#ifdef F_231
if ( V_245 == V_253 ) {
unsigned long V_1 = F_306 ( V_245 ) ;
F_307 ( V_161 , V_1 , V_2 ) ;
}
#endif
}
static void T_12 F_202 ( void )
{
V_238 . F_294 = F_38 ;
V_238 . F_71 = F_29 ;
V_238 . F_182 = F_60 ;
#if V_263 >= 4
V_238 . F_187 = F_83 ;
#endif
V_238 . V_264 = F_251 ;
V_238 . V_265 = F_252 ;
V_238 . V_266 = F_255 ;
V_238 . V_267 = F_256 ;
#if V_263 >= 4
V_238 . V_268 = F_257 ;
V_238 . V_269 = F_258 ;
#endif
V_238 . V_270 = F_308 ( F_53 ) ;
#ifdef F_122
V_238 . V_239 = & F_226 ;
F_133 ( F_9 ( V_161 ) ) ;
#endif
F_134 () ;
}
static void F_309 ( void )
{
F_24 () ;
F_149 () ;
F_310 () ;
F_28 () ;
}
void T_12 F_311 ( void )
{
V_271 . V_272 . V_273 = F_200 ;
V_238 = V_274 ;
memset ( V_259 , 0xff , V_108 ) ;
}
static void F_312 ( unsigned long V_1 , unsigned int V_275 ,
unsigned long * V_276 ,
unsigned long * V_277 )
{
int V_55 ;
struct V_11 V_12 ;
F_25 () ;
for ( V_55 = 0 ; V_55 < ( 1UL << V_275 ) ; V_55 ++ , V_1 += V_108 ) {
V_12 = F_20 ( 0 ) ;
if ( V_276 )
V_276 [ V_55 ] = F_313 ( V_1 ) ;
F_116 ( V_12 . V_17 , V_1 , V_278 , 0 ) ;
F_314 ( F_315 ( V_1 ) , V_37 ) ;
if ( V_277 )
V_277 [ V_55 ] = F_315 ( V_1 ) ;
}
F_17 ( 0 ) ;
}
static void F_316 ( unsigned long V_1 , int V_275 ,
unsigned long * V_279 ,
unsigned long V_280 )
{
unsigned V_55 , V_54 ;
unsigned long V_25 ;
F_25 () ;
V_54 = 1u << V_275 ;
for ( V_55 = 0 ; V_55 < V_54 ; V_55 ++ , V_1 += V_108 ) {
struct V_11 V_12 ;
unsigned V_26 ;
V_12 = F_20 ( 0 ) ;
if ( V_279 )
V_25 = V_279 [ V_55 ] ;
else
V_25 = V_280 + V_55 ;
if ( V_55 < ( V_54 - 1 ) )
V_26 = 0 ;
else {
if ( V_275 == 0 )
V_26 = V_194 | V_281 ;
else
V_26 = V_80 | V_281 ;
}
F_116 ( V_12 . V_17 , V_1 ,
F_33 ( V_25 , V_89 ) , V_26 ) ;
F_317 ( F_315 ( V_1 ) , V_25 ) ;
}
F_17 ( 0 ) ;
}
static int F_318 ( unsigned long V_282 , unsigned int V_283 ,
unsigned long * V_284 ,
unsigned long V_285 ,
unsigned int V_286 ,
unsigned long * V_287 ,
unsigned int V_288 )
{
long V_289 ;
int V_290 ;
struct V_291 V_292 = {
. V_293 = {
. V_294 = V_282 ,
. V_295 = V_283 ,
. V_296 = V_284 ,
. V_10 = V_21
} ,
. V_297 = {
. V_294 = V_285 ,
. V_295 = V_286 ,
. V_296 = V_287 ,
. V_288 = V_288 ,
. V_10 = V_21
}
} ;
F_100 ( V_282 << V_283 != V_285 << V_286 ) ;
V_289 = F_271 ( V_298 , & V_292 ) ;
V_290 = ( V_292 . V_299 == V_282 ) ;
F_100 ( ! V_290 && ( ( V_292 . V_299 != 0 ) || ( V_289 == 0 ) ) ) ;
F_100 ( V_290 && ( V_289 != 0 ) ) ;
return V_290 ;
}
int F_319 ( T_15 V_300 , unsigned int V_275 ,
unsigned int V_288 ,
T_16 * V_301 )
{
unsigned long * V_276 = V_302 , V_303 ;
unsigned long V_26 ;
int V_290 ;
unsigned long V_304 = ( unsigned long ) F_320 ( V_300 ) ;
if ( F_48 ( V_275 > V_305 ) )
return - V_157 ;
memset ( ( void * ) V_304 , 0 , V_108 << V_275 ) ;
F_321 ( & V_306 , V_26 ) ;
F_312 ( V_304 , V_275 , V_276 , NULL ) ;
V_303 = F_315 ( V_304 ) ;
V_290 = F_318 ( 1UL << V_275 , 0 , V_276 ,
1 , V_275 , & V_303 ,
V_288 ) ;
if ( V_290 )
F_316 ( V_304 , V_275 , NULL , V_303 ) ;
else
F_316 ( V_304 , V_275 , V_276 , 0 ) ;
F_322 ( & V_306 , V_26 ) ;
* V_301 = F_14 ( V_304 ) . V_15 ;
return V_290 ? 0 : - V_157 ;
}
void F_323 ( T_15 V_300 , unsigned int V_275 )
{
unsigned long * V_277 = V_302 , V_307 ;
unsigned long V_26 ;
int V_290 ;
unsigned long V_304 ;
if ( F_48 ( V_275 > V_305 ) )
return;
V_304 = ( unsigned long ) F_320 ( V_300 ) ;
memset ( ( void * ) V_304 , 0 , V_108 << V_275 ) ;
F_321 ( & V_306 , V_26 ) ;
V_307 = F_313 ( V_304 ) ;
F_312 ( V_304 , V_275 , NULL , V_277 ) ;
V_290 = F_318 ( 1 , V_275 , & V_307 , 1UL << V_275 ,
0 , V_277 , 0 ) ;
if ( V_290 )
F_316 ( V_304 , V_275 , V_277 , 0 ) ;
else
F_316 ( V_304 , V_275 , NULL , V_307 ) ;
F_322 ( & V_306 , V_26 ) ;
}
T_15 F_324 ( void )
{
if ( F_325 () )
return F_14 ( V_308 ) . V_15 ;
else
return F_124 ( V_308 ) ;
}
