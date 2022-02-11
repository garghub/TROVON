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
struct V_28 * V_94 ;
V_94 = F_146 ( V_95 . V_94 ) ;
if ( V_94 == V_29 && F_146 ( V_95 . V_96 ) != V_97 )
F_147 ( F_148 () ) ;
if ( F_146 ( V_98 ) == F_124 ( V_29 -> V_40 ) )
F_149 ( V_99 ) ;
}
static void F_150 ( struct V_28 * V_29 )
{
T_14 V_100 ;
unsigned V_101 ;
if ( V_102 -> V_94 == V_29 ) {
if ( V_102 -> V_29 == V_29 )
F_149 ( V_99 ) ;
else
F_147 ( F_148 () ) ;
}
if ( ! F_151 ( & V_100 , V_103 ) ) {
F_152 (cpu) {
if ( ! F_153 ( V_101 , F_154 ( V_29 ) )
&& F_155 ( V_98 , V_101 ) != F_124 ( V_29 -> V_40 ) )
continue;
F_156 ( V_101 , F_145 , V_29 , 1 ) ;
}
return;
}
F_157 ( V_100 , F_154 ( V_29 ) ) ;
F_152 (cpu) {
if ( F_155 ( V_98 , V_101 ) == F_124 ( V_29 -> V_40 ) )
F_158 ( V_101 , V_100 ) ;
}
if ( ! F_159 ( V_100 ) )
F_160 ( V_100 , F_145 , V_29 , 1 ) ;
F_161 ( V_100 ) ;
}
static void F_150 ( struct V_28 * V_29 )
{
if ( V_102 -> V_94 == V_29 )
F_149 ( V_99 ) ;
}
static void F_162 ( struct V_28 * V_29 )
{
F_163 () ;
F_150 ( V_29 ) ;
F_164 () ;
F_128 ( & V_29 -> V_73 ) ;
if ( F_8 ( V_29 -> V_40 ) )
F_139 ( V_29 ) ;
F_108 ( & V_29 -> V_73 ) ;
}
static void T_12 F_165 ( unsigned V_75 , unsigned long V_35 )
{
struct V_22 V_23 ;
V_23 . V_75 = V_75 ;
V_23 . V_76 . V_25 = F_110 ( V_35 ) ;
if ( F_166 ( & V_23 , 1 , NULL , V_21 ) )
F_5 () ;
}
static void T_12 F_167 ( unsigned long V_1 ,
unsigned long V_104 )
{
unsigned long V_105 = F_168 ( ( unsigned long ) V_106 , V_107 ) - 1 ;
T_2 * V_41 = V_108 + F_88 ( V_1 ) ;
for (; V_1 <= V_104 && ( V_41 < ( V_108 + V_58 ) ) ;
V_41 ++ , V_1 += V_107 ) {
if ( F_89 ( * V_41 ) )
continue;
if ( V_1 < ( unsigned long ) V_109 || V_1 > V_105 )
F_71 ( V_41 , F_72 ( 0 ) ) ;
}
F_169 () ;
}
static void T_12 F_170 ( unsigned long V_110 , unsigned long V_111 )
{
void * V_1 = F_171 ( V_110 ) ;
void * V_104 = V_1 + V_111 ;
for (; V_1 < V_104 ; V_1 += V_112 )
F_6 ( V_1 ) ;
F_172 ( V_110 , V_111 ) ;
}
static void T_12 F_173 ( void * V_113 , bool V_114 )
{
unsigned long V_115 = F_124 ( V_113 ) & V_116 ;
if ( V_114 )
F_165 ( V_88 , F_123 ( V_115 ) ) ;
F_174 ( F_9 ( F_171 ( V_115 ) ) ) ;
F_170 ( V_115 , V_112 ) ;
}
static void T_12 F_175 ( T_2 * V_41 , bool V_114 )
{
unsigned long V_115 ;
T_1 * V_117 ;
int V_55 ;
if ( F_176 ( * V_41 ) ) {
V_115 = F_177 ( * V_41 ) & V_116 ;
F_170 ( V_115 , V_107 ) ;
return;
}
V_117 = F_178 ( V_41 , 0 ) ;
for ( V_55 = 0 ; V_55 < V_118 ; V_55 ++ ) {
if ( F_179 ( V_117 [ V_55 ] ) )
continue;
V_115 = F_180 ( V_117 [ V_55 ] ) << V_34 ;
F_170 ( V_115 , V_112 ) ;
}
F_71 ( V_41 , F_72 ( 0 ) ) ;
F_173 ( V_117 , V_114 ) ;
}
static void T_12 F_181 ( T_9 * V_44 , bool V_114 )
{
unsigned long V_115 ;
T_2 * V_119 ;
int V_55 ;
if ( F_182 ( * V_44 ) ) {
V_115 = F_183 ( * V_44 ) & V_116 ;
F_170 ( V_115 , V_120 ) ;
return;
}
V_119 = F_94 ( V_44 , 0 ) ;
for ( V_55 = 0 ; V_55 < V_58 ; V_55 ++ ) {
if ( F_89 ( V_119 [ V_55 ] ) )
continue;
F_175 ( V_119 + V_55 , V_114 ) ;
}
F_184 ( V_44 , F_185 ( 0 ) ) ;
F_173 ( V_119 , V_114 ) ;
}
static void T_12 F_186 ( T_11 * V_62 , bool V_114 )
{
unsigned long V_115 ;
T_9 * V_121 ;
int V_55 ;
if ( F_187 ( * V_62 ) ) {
V_115 = F_188 ( * V_62 ) & V_116 ;
F_170 ( V_115 , V_122 ) ;
return;
}
V_121 = F_98 ( V_62 , 0 ) ;
for ( V_55 = 0 ; V_55 < V_60 ; V_55 ++ ) {
if ( F_93 ( V_121 [ V_55 ] ) )
continue;
F_181 ( V_121 + V_55 , V_114 ) ;
}
F_189 ( V_62 , F_190 ( 0 ) ) ;
F_173 ( V_121 , V_114 ) ;
}
static void T_12 F_191 ( unsigned long V_1 )
{
T_7 * V_40 ;
T_11 * V_62 ;
unsigned int V_55 ;
bool V_114 ;
V_114 = ( V_1 == 2 * V_123 ) ;
V_1 &= V_124 ;
V_40 = F_192 ( V_1 ) ;
V_62 = F_102 ( V_40 , 0 ) ;
for ( V_55 = 0 ; V_55 < V_63 ; V_55 ++ ) {
if ( F_97 ( V_62 [ V_55 ] ) )
continue;
F_186 ( V_62 + V_55 , V_114 ) ;
}
if ( F_193 ( V_125 ) ) {
F_194 ( V_40 , F_195 ( 0 ) ) ;
F_173 ( V_62 , V_114 ) ;
}
}
static void T_12 F_196 ( void )
{
unsigned long V_111 ;
unsigned long V_30 ;
V_111 = F_197 ( V_126 -> V_127 * sizeof( unsigned long ) ) ;
if ( ( unsigned long ) V_128 == V_126 -> V_129 )
return;
memset ( ( void * ) V_126 -> V_129 , 0xff , V_111 ) ;
V_30 = V_126 -> V_129 ;
V_111 = F_168 ( V_111 , V_107 ) ;
if ( V_30 >= V_130 ) {
F_167 ( V_30 , V_30 + V_111 ) ;
V_111 = F_197 ( V_126 -> V_127 *
sizeof( unsigned long ) ) ;
F_172 ( F_124 ( V_30 ) , V_111 ) ;
} else {
F_191 ( V_30 ) ;
}
}
static void T_12 F_198 ( void )
{
unsigned long V_111 ;
unsigned long V_30 ;
V_30 = V_126 -> V_131 ;
V_111 = F_168 ( V_126 -> V_132 * V_112 , V_107 ) ;
F_167 ( V_30 , V_30 + V_111 ) ;
V_126 -> V_131 = ( unsigned long ) F_171 ( F_124 ( V_126 -> V_131 ) ) ;
#ifdef F_199
F_167 ( V_133 , F_168 ( V_133 , V_120 ) - 1 ) ;
#endif
}
static void T_12 F_200 ( void )
{
F_201 () ;
#ifdef F_122
F_196 () ;
F_198 () ;
#endif
V_126 -> V_129 = ( unsigned long ) V_128 ;
}
static void T_12 F_202 ( void )
{
F_203 () ;
F_204 () ;
F_200 () ;
F_205 () ;
F_206 () ;
F_207 () ;
}
static void F_208 ( unsigned long V_134 )
{
F_146 ( V_135 ) -> V_136 . V_134 = V_134 ;
}
static unsigned long F_209 ( void )
{
return F_146 ( V_135 ) -> V_136 . V_134 ;
}
unsigned long F_210 ( void )
{
return F_146 ( V_137 . V_136 . V_134 ) ;
}
static void F_211 ( void )
{
struct V_22 * V_23 ;
struct V_11 V_12 ;
F_212 ( 0 ) ;
F_24 () ;
V_12 = F_13 ( sizeof( * V_23 ) ) ;
V_23 = V_12 . args ;
V_23 -> V_75 = V_138 ;
F_22 ( V_12 . V_17 , V_23 , 1 , NULL , V_21 ) ;
F_17 ( V_18 ) ;
F_28 () ;
}
static void F_213 ( unsigned long V_30 )
{
struct V_22 * V_23 ;
struct V_11 V_12 ;
F_214 ( V_30 ) ;
F_24 () ;
V_12 = F_13 ( sizeof( * V_23 ) ) ;
V_23 = V_12 . args ;
V_23 -> V_75 = V_139 ;
V_23 -> V_76 . V_140 = V_30 & V_46 ;
F_22 ( V_12 . V_17 , V_23 , 1 , NULL , V_21 ) ;
F_17 ( V_18 ) ;
F_28 () ;
}
static void F_215 ( const struct V_141 * V_142 ,
struct V_28 * V_29 , unsigned long V_143 ,
unsigned long V_144 )
{
struct {
struct V_22 V_23 ;
#ifdef F_216
F_217 ( V_100 , V_145 ) ;
#else
F_217 ( V_100 , V_146 ) ;
#endif
} * args ;
struct V_11 V_12 ;
F_218 ( V_142 , V_29 , V_143 , V_144 ) ;
if ( F_159 ( V_142 ) )
return;
V_12 = F_13 ( sizeof( * args ) ) ;
args = V_12 . args ;
args -> V_23 . V_147 . V_148 = F_219 ( args -> V_100 ) ;
F_220 ( F_219 ( args -> V_100 ) , V_142 , V_149 ) ;
F_221 ( F_148 () , F_219 ( args -> V_100 ) ) ;
args -> V_23 . V_75 = V_150 ;
if ( V_144 != V_151 && ( V_144 - V_143 ) <= V_112 ) {
args -> V_23 . V_75 = V_152 ;
args -> V_23 . V_76 . V_140 = V_143 ;
}
F_22 ( V_12 . V_17 , & args -> V_23 , 1 , NULL , V_21 ) ;
F_17 ( V_18 ) ;
}
static unsigned long F_222 ( void )
{
return F_146 ( V_153 ) ;
}
static void F_223 ( void * V_74 )
{
F_224 ( V_98 , ( unsigned long ) V_74 ) ;
}
static void F_225 ( bool V_154 , unsigned long V_155 )
{
struct V_22 V_23 ;
unsigned long V_25 ;
F_226 ( V_154 , V_155 ) ;
if ( V_155 )
V_25 = F_110 ( F_123 ( V_155 ) ) ;
else
V_25 = 0 ;
F_85 ( V_25 == 0 && V_154 ) ;
V_23 . V_75 = V_154 ? V_156 : V_157 ;
V_23 . V_76 . V_25 = V_25 ;
F_21 ( & V_23 ) ;
if ( V_154 ) {
F_224 ( V_153 , V_155 ) ;
F_118 ( F_223 , ( void * ) V_155 ) ;
}
}
static void F_227 ( unsigned long V_155 )
{
F_100 ( F_228 () ) ;
F_25 () ;
F_224 ( V_153 , V_155 ) ;
F_225 ( true , V_155 ) ;
#ifdef F_122
{
T_7 * V_82 = F_78 ( F_171 ( V_155 ) ) ;
if ( V_82 )
F_225 ( false , F_124 ( V_82 ) ) ;
else
F_225 ( false , 0 ) ;
}
#endif
F_17 ( V_158 ) ;
}
static void T_12 F_229 ( unsigned long V_155 )
{
F_100 ( F_228 () ) ;
F_25 () ;
F_224 ( V_153 , V_155 ) ;
F_225 ( true , V_155 ) ;
F_17 ( V_158 ) ;
}
static int F_230 ( struct V_28 * V_29 )
{
T_7 * V_40 = V_29 -> V_40 ;
int V_159 = 0 ;
F_100 ( F_10 ( F_9 ( V_40 ) ) ) ;
#ifdef F_122
{
struct V_7 * V_7 = F_9 ( V_40 ) ;
T_7 * V_82 ;
F_100 ( V_7 -> V_50 != 0 ) ;
V_159 = - V_160 ;
V_82 = ( T_7 * ) F_231 ( V_161 | V_162 ) ;
V_7 -> V_50 = ( unsigned long ) V_82 ;
if ( V_82 != NULL ) {
#ifdef F_232
V_82 [ F_79 ( V_163 ) ] =
F_195 ( F_124 ( V_164 ) | V_165 ) ;
#endif
V_159 = 0 ;
}
F_100 ( F_10 ( F_9 ( F_78 ( V_40 ) ) ) ) ;
}
#endif
return V_159 ;
}
static void F_233 ( struct V_28 * V_29 , T_7 * V_40 )
{
#ifdef F_122
T_7 * V_82 = F_78 ( V_40 ) ;
if ( V_82 )
F_234 ( ( unsigned long ) V_82 ) ;
#endif
}
T_5 T_1 F_235 ( T_4 V_2 )
{
#ifdef F_122
unsigned long V_35 ;
V_35 = ( V_2 & V_33 ) >> V_34 ;
if ( V_126 -> V_129 < V_130 &&
V_35 >= V_126 -> V_166 &&
V_35 < V_126 -> V_166 + V_126 -> V_167 )
V_2 &= ~ V_168 ;
#endif
V_2 = F_49 ( V_2 ) ;
return F_54 ( V_2 ) ;
}
static void T_12 F_236 ( T_1 * V_8 , T_1 V_2 )
{
#ifdef F_237
if ( F_238 ( V_2 ) != V_37
&& F_15 ( * V_8 ) & V_32 )
V_2 = F_239 ( ( ( F_15 ( * V_8 ) & V_168 ) | ~ V_168 ) &
F_15 ( V_2 ) ) ;
#endif
F_240 ( V_8 , V_2 ) ;
}
static void T_12 F_241 ( struct V_28 * V_29 , unsigned long V_35 )
{
#ifdef F_242
F_100 ( V_169 ) ;
#endif
F_1 ( F_171 ( F_243 ( V_35 ) ) ) ;
F_165 ( V_81 , V_35 ) ;
}
static void T_12 F_244 ( struct V_28 * V_29 , unsigned long V_35 )
{
#ifdef F_242
F_100 ( V_169 ) ;
#endif
F_1 ( F_171 ( F_243 ( V_35 ) ) ) ;
}
static void T_12 F_245 ( unsigned long V_35 )
{
F_165 ( V_88 , V_35 ) ;
F_6 ( F_171 ( F_243 ( V_35 ) ) ) ;
}
static void T_12 F_246 ( unsigned long V_35 )
{
F_6 ( F_171 ( F_243 ( V_35 ) ) ) ;
}
static inline void F_247 ( unsigned V_75 , unsigned long V_35 )
{
struct V_11 V_12 ;
struct V_22 * V_23 ;
V_12 = F_20 ( sizeof( * V_23 ) ) ;
V_23 = V_12 . args ;
V_23 -> V_75 = V_75 ;
V_23 -> V_76 . V_25 = F_110 ( V_35 ) ;
F_22 ( V_12 . V_17 , V_12 . args , 1 , NULL , V_21 ) ;
}
static inline void F_248 ( unsigned long V_35 , T_3 V_170 )
{
struct V_11 V_12 ;
unsigned long V_30 = ( unsigned long ) F_171 ( V_35 << V_34 ) ;
V_12 = F_20 ( 0 ) ;
F_116 ( V_12 . V_17 , ( unsigned long ) V_30 ,
F_117 ( V_35 , V_170 ) , 0 ) ;
}
static inline void F_249 ( struct V_28 * V_29 , unsigned long V_35 ,
unsigned V_5 )
{
bool V_171 = F_10 ( F_9 ( V_29 -> V_40 ) ) ;
F_250 ( V_29 , V_35 , V_5 , V_171 ) ;
if ( V_171 ) {
struct V_7 * V_7 = F_251 ( V_35 ) ;
F_133 ( V_7 ) ;
if ( ! F_113 ( V_7 ) ) {
F_25 () ;
F_248 ( V_35 , V_79 ) ;
if ( V_5 == V_59 && V_72 )
F_247 ( V_81 , V_35 ) ;
F_17 ( V_18 ) ;
} else {
F_121 () ;
}
}
}
static void F_252 ( struct V_28 * V_29 , unsigned long V_35 )
{
F_249 ( V_29 , V_35 , V_59 ) ;
}
static void F_253 ( struct V_28 * V_29 , unsigned long V_35 )
{
F_249 ( V_29 , V_35 , V_61 ) ;
}
static inline void F_254 ( unsigned long V_35 , unsigned V_5 )
{
struct V_7 * V_7 = F_251 ( V_35 ) ;
bool V_171 = F_10 ( V_7 ) ;
F_255 ( V_35 , V_5 , V_171 ) ;
if ( V_171 ) {
if ( ! F_113 ( V_7 ) ) {
F_25 () ;
if ( V_5 == V_59 && V_72 )
F_247 ( V_88 , V_35 ) ;
F_248 ( V_35 , V_89 ) ;
F_17 ( V_18 ) ;
}
F_174 ( V_7 ) ;
}
}
static void F_256 ( unsigned long V_35 )
{
F_254 ( V_35 , V_59 ) ;
}
static void F_257 ( unsigned long V_35 )
{
F_254 ( V_35 , V_61 ) ;
}
static void F_258 ( struct V_28 * V_29 , unsigned long V_35 )
{
F_249 ( V_29 , V_35 , V_64 ) ;
}
static void F_259 ( unsigned long V_35 )
{
F_254 ( V_35 , V_64 ) ;
}
void T_12 F_260 ( void )
{
#ifdef F_237
unsigned long V_172 = V_173 ;
struct V_174 V_175 ;
if ( F_261 ( V_176 , & V_175 ) == 0 )
V_172 = V_175 . V_177 ;
F_262 ( - V_172 ) ;
#endif
}
static void * T_12 F_263 ( T_15 V_110 )
{
#ifdef F_122
return ( void * ) ( V_110 + V_130 ) ;
#else
return F_171 ( V_110 ) ;
#endif
}
static unsigned long T_12 F_264 ( T_15 V_15 )
{
T_15 V_110 ;
V_15 &= V_33 ;
V_110 = F_47 ( V_15 >> V_34 ) << V_34 ;
return V_110 ;
}
static void * T_12 F_265 ( T_15 V_15 )
{
return F_263 ( F_264 ( V_15 ) ) ;
}
static void T_12 F_266 ( void * V_30 , T_3 V_170 ,
unsigned long V_26 )
{
unsigned long V_35 = F_124 ( V_30 ) >> V_34 ;
T_1 V_2 = F_117 ( V_35 , V_170 ) ;
if ( F_4 ( ( unsigned long ) V_30 , V_2 , V_26 ) )
F_5 () ;
}
static void T_12 F_267 ( void * V_30 , T_3 V_170 )
{
return F_266 ( V_30 , V_170 , V_178 ) ;
}
static void T_12 F_268 ( T_2 * V_41 , unsigned long V_179 )
{
unsigned V_180 , V_181 ;
unsigned V_182 ;
unsigned long V_35 ;
V_183 = F_269 ( sizeof( T_1 ) * V_184 ,
V_112 ) ;
V_182 = 0 ;
V_35 = 0 ;
for ( V_180 = 0 ; V_180 < V_58 && V_35 < V_179 ; V_180 ++ ) {
T_1 * V_185 ;
if ( F_270 ( V_41 [ V_180 ] ) )
V_185 = F_265 ( V_41 [ V_180 ] . V_41 ) ;
else {
if ( V_182 == V_184 )
break;
V_185 = & V_183 [ V_182 ] ;
V_182 += V_118 ;
V_41 [ V_180 ] = F_72 ( F_124 ( V_185 ) | V_165 ) ;
}
for ( V_181 = 0 ; V_181 < V_118 ; V_181 ++ , V_35 ++ ) {
T_1 V_2 ;
if ( V_35 > V_186 )
V_186 = V_35 ;
if ( ! F_179 ( V_185 [ V_181 ] ) )
continue;
V_2 = F_117 ( V_35 , V_187 ) ;
V_185 [ V_181 ] = V_2 ;
}
}
for ( V_181 = 0 ; V_181 < V_182 ; V_181 += V_118 )
F_267 ( & V_183 [ V_181 ] , V_79 ) ;
F_267 ( V_41 , V_79 ) ;
}
void T_12 F_271 ( void )
{
struct V_188 V_189 ;
if ( F_272 ( V_190 , & V_189 ) == 0 ) {
V_191 = ( unsigned long * ) V_189 . V_192 ;
V_193 = V_189 . V_194 + 1 ;
} else {
V_193 = V_195 ;
}
#ifdef F_237
F_85 ( ( V_191 + ( V_193 - 1 ) )
< V_191 ) ;
#endif
}
static void T_12 F_273 ( void * V_74 )
{
T_1 * V_2 = V_74 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_118 ; V_55 ++ )
V_2 [ V_55 ] = F_53 ( V_2 [ V_55 ] . V_2 ) ;
}
static void T_12 F_274 ( unsigned long * V_131 , unsigned long * V_196 ,
unsigned long V_30 )
{
if ( * V_131 == F_123 ( F_124 ( V_30 ) ) ) {
F_266 ( ( void * ) V_30 , V_89 , V_197 ) ;
F_275 ( ( void * ) V_30 ) ;
( * V_131 ) ++ ;
}
if ( * V_196 == F_123 ( F_124 ( V_30 ) ) ) {
F_266 ( ( void * ) V_30 , V_89 , V_197 ) ;
F_275 ( ( void * ) V_30 ) ;
( * V_196 ) -- ;
}
}
void T_12 F_276 ( T_7 * V_40 , unsigned long V_179 )
{
T_9 * V_198 ;
T_2 * V_199 ;
unsigned long V_30 [ 3 ] ;
unsigned long V_131 , V_196 ;
unsigned V_55 ;
if ( V_126 -> V_129 < V_130 )
V_186 = V_126 -> V_166 ;
else
V_186 = F_123 ( F_124 ( V_126 -> V_129 ) ) ;
V_131 = F_123 ( F_124 ( V_126 -> V_131 ) ) ;
V_196 = V_131 + V_126 -> V_132 ;
V_200 [ 0 ] = F_195 ( 0 ) ;
F_273 ( V_200 ) ;
F_273 ( V_201 ) ;
F_273 ( V_202 ) ;
F_273 ( V_203 ) ;
V_198 = F_265 ( V_40 [ F_79 ( V_130 ) ] . V_40 ) ;
V_199 = F_265 ( V_198 [ F_92 ( V_130 ) ] . V_44 ) ;
V_30 [ 0 ] = ( unsigned long ) V_40 ;
V_30 [ 1 ] = ( unsigned long ) V_198 ;
V_30 [ 2 ] = ( unsigned long ) V_199 ;
F_277 ( V_204 , V_199 ) ;
F_277 ( V_108 , V_199 ) ;
V_55 = F_79 ( V_126 -> V_129 ) ;
if ( V_55 && V_55 < F_79 ( V_130 ) )
V_200 [ V_55 ] = ( ( T_7 * ) V_126 -> V_131 ) [ V_55 ] ;
F_267 ( V_200 , V_79 ) ;
F_267 ( V_201 , V_79 ) ;
F_267 ( V_202 , V_79 ) ;
F_267 ( V_164 , V_79 ) ;
F_267 ( V_204 , V_79 ) ;
F_267 ( V_108 , V_79 ) ;
F_267 ( V_203 , V_79 ) ;
F_267 ( V_205 , V_79 ) ;
F_165 ( V_83 ,
F_123 ( F_278 ( V_200 ) ) ) ;
F_165 ( V_88 , F_123 ( F_124 ( V_40 ) ) ) ;
F_25 () ;
F_225 ( true , F_124 ( V_200 ) ) ;
F_17 ( V_158 ) ;
for ( V_55 = 0 ; V_55 < F_279 ( V_30 ) ; V_55 ++ )
F_274 ( & V_131 , & V_196 , V_30 [ V_55 ] ) ;
V_206 = F_243 ( V_131 ) ;
V_207 = ( V_196 - V_131 ) * V_112 ;
F_280 ( V_206 , V_207 ) ;
V_126 = (struct V_208 * ) F_171 ( F_124 ( V_126 ) ) ;
}
static unsigned long T_12 F_281 ( T_15 V_30 )
{
unsigned long * V_1 ;
unsigned long V_16 ;
V_1 = F_282 ( V_30 , sizeof( V_16 ) ) ;
V_16 = * V_1 ;
F_283 ( V_1 , sizeof( V_16 ) ) ;
return V_16 ;
}
static T_15 T_12 F_284 ( unsigned long V_1 )
{
T_15 V_115 ;
T_7 V_40 ;
T_9 V_44 ;
T_2 V_41 ;
T_1 V_2 ;
V_115 = F_285 () ;
V_40 = F_56 ( F_281 ( V_115 + F_79 ( V_1 ) *
sizeof( V_40 ) ) ) ;
if ( ! F_286 ( V_40 ) )
return 0 ;
V_115 = V_51 ( V_40 ) & V_33 ;
V_44 = F_77 ( F_281 ( V_115 + F_92 ( V_1 ) *
sizeof( V_44 ) ) ) ;
if ( ! F_287 ( V_44 ) )
return 0 ;
V_115 = F_183 ( V_44 ) & V_33 ;
if ( F_182 ( V_44 ) )
return V_115 + ( V_1 & ~ V_209 ) ;
V_41 = F_74 ( F_281 ( V_115 + F_88 ( V_1 ) *
sizeof( V_41 ) ) ) ;
if ( ! F_270 ( V_41 ) )
return 0 ;
V_115 = F_177 ( V_41 ) & V_33 ;
if ( F_176 ( V_41 ) )
return V_115 + ( V_1 & ~ V_124 ) ;
V_2 = F_54 ( F_281 ( V_115 + F_288 ( V_1 ) *
sizeof( V_2 ) ) ) ;
if ( ! F_289 ( V_2 ) )
return 0 ;
V_115 = F_180 ( V_2 ) << V_34 ;
return V_115 | ( V_1 & ~ V_46 ) ;
}
void T_12 F_290 ( void )
{
T_15 V_111 , V_210 , V_211 , V_212 , V_213 , V_214 ;
unsigned long V_215 , V_216 , V_217 , V_35 , V_218 ;
int V_219 , V_220 , V_221 , V_222 , V_223 , V_224 , V_225 , V_226 , V_227 , V_228 ;
T_1 * V_78 ;
T_2 * V_41 ;
T_9 * V_44 ;
T_11 * V_62 = NULL ;
T_7 * V_40 ;
unsigned long * V_229 ;
int V_230 ;
V_111 = F_197 ( V_126 -> V_127 * sizeof( unsigned long ) ) ;
V_219 = F_168 ( V_111 , V_112 ) >> V_34 ;
V_220 = F_168 ( V_111 , V_107 ) >> V_231 ;
V_221 = F_168 ( V_111 , V_120 ) >> V_232 ;
V_222 = F_168 ( V_111 , V_122 ) >> V_233 ;
if ( V_63 > 1 )
V_223 = F_168 ( V_111 , V_123 ) >> V_234 ;
else
V_223 = 0 ;
V_217 = V_219 + V_220 + V_221 + V_222 + V_223 ;
V_210 = F_291 ( F_243 ( V_217 ) ) ;
if ( ! V_210 ) {
F_292 ( L_1 ) ;
F_5 () ;
}
V_214 = V_210 ;
V_213 = V_214 + F_243 ( V_223 ) ;
V_212 = V_213 + F_243 ( V_222 ) ;
V_211 = V_212 + F_243 ( V_221 ) ;
V_215 = F_123 ( V_211 ) + V_220 ;
V_40 = F_171 ( F_285 () ) ;
V_229 = ( unsigned long * ) ( 2 * V_123 ) ;
V_228 = 0 ;
V_230 = V_222 ;
do {
if ( V_223 > 0 ) {
V_62 = F_293 ( V_214 , V_112 ) ;
F_275 ( V_62 ) ;
V_222 = F_294 ( V_230 , V_63 ) ;
}
for ( V_227 = 0 ; V_227 < V_222 ; V_227 ++ ) {
V_44 = F_293 ( V_213 , V_112 ) ;
F_275 ( V_44 ) ;
for ( V_226 = 0 ; V_226 < F_294 ( V_221 , V_60 ) ;
V_226 ++ ) {
V_41 = F_293 ( V_212 , V_112 ) ;
F_275 ( V_41 ) ;
for ( V_225 = 0 ; V_225 < F_294 ( V_220 , V_58 ) ;
V_225 ++ ) {
V_78 = F_293 ( V_211 , V_112 ) ;
F_275 ( V_78 ) ;
for ( V_224 = 0 ;
V_224 < F_294 ( V_219 , V_118 ) ;
V_224 ++ ) {
F_295 ( V_78 + V_224 ,
F_117 ( V_215 , V_89 ) ) ;
V_215 ++ ;
}
V_219 -= V_118 ;
F_283 ( V_78 , V_112 ) ;
F_1 ( F_171 ( V_211 ) ) ;
F_165 ( V_81 ,
F_123 ( V_211 ) ) ;
F_71 ( V_41 + V_225 ,
F_72 ( V_165 | V_211 ) ) ;
V_211 += V_112 ;
}
V_220 -= V_58 ;
F_283 ( V_41 , V_112 ) ;
F_1 ( F_171 ( V_212 ) ) ;
F_165 ( V_235 ,
F_123 ( V_212 ) ) ;
F_184 ( V_44 + V_226 , F_185 ( V_165 | V_212 ) ) ;
V_212 += V_112 ;
}
V_221 -= V_60 ;
F_283 ( V_44 , V_112 ) ;
F_1 ( F_171 ( V_213 ) ) ;
F_165 ( V_85 , F_123 ( V_213 ) ) ;
if ( V_223 > 0 )
F_189 ( V_62 + V_227 , F_190 ( V_165 | V_213 ) ) ;
else
F_194 ( V_40 + 2 + V_227 , F_195 ( V_165 | V_213 ) ) ;
V_213 += V_112 ;
}
if ( V_223 > 0 ) {
V_230 -= V_63 ;
F_283 ( V_62 , V_112 ) ;
F_1 ( F_171 ( V_214 ) ) ;
F_165 ( V_83 , F_123 ( V_214 ) ) ;
F_194 ( V_40 + 2 + V_228 , F_195 ( V_165 | V_214 ) ) ;
V_214 += V_112 ;
}
} while ( ++ V_228 < V_223 );
memcpy ( V_229 , V_128 , V_111 ) ;
V_128 = V_229 ;
V_215 = F_123 ( F_284 ( V_126 -> V_129 ) ) ;
F_100 ( ! V_215 ) ;
V_216 = V_215 + F_123 ( V_111 ) ;
if ( V_126 -> V_129 < V_130 ) {
V_35 = V_126 -> V_166 ;
V_218 = V_126 -> V_166 +
V_126 -> V_167 ;
F_194 ( V_40 + 1 , F_195 ( 0 ) ) ;
} else {
V_35 = V_215 ;
V_218 = V_216 ;
}
F_172 ( F_243 ( V_35 ) , V_112 * ( V_218 - V_35 ) ) ;
while ( V_35 < V_218 ) {
if ( V_35 == V_215 ) {
V_35 = V_216 ;
continue;
}
F_6 ( F_171 ( F_243 ( V_35 ) ) ) ;
V_35 ++ ;
}
V_126 -> V_129 = ( unsigned long ) V_128 ;
V_126 -> V_166 = F_123 ( V_210 ) ;
V_126 -> V_167 = V_217 ;
}
static void T_12 F_229 ( unsigned long V_155 )
{
unsigned long V_35 = F_123 ( F_124 ( V_99 ) ) ;
F_100 ( F_285 () != F_124 ( V_236 ) ) ;
F_100 ( V_155 != F_124 ( V_99 ) ) ;
V_237 =
F_269 ( sizeof( T_2 ) * V_58 , V_112 ) ;
F_277 ( V_237 , V_238 ) ;
V_99 [ V_239 ] =
F_195 ( F_124 ( V_237 ) | V_32 ) ;
F_267 ( V_237 , V_79 ) ;
F_267 ( V_99 , V_79 ) ;
F_227 ( V_155 ) ;
F_165 ( V_85 , V_35 ) ;
F_165 ( V_88 ,
F_123 ( F_124 ( V_236 ) ) ) ;
F_267 ( V_236 , V_89 ) ;
F_267 ( V_238 , V_89 ) ;
V_240 . V_241 = & F_227 ;
}
static T_15 F_296 ( T_2 * V_41 )
{
T_15 V_131 , V_110 ;
unsigned V_180 ;
V_131 = F_294 ( F_124 ( V_126 -> V_131 ) , F_124 ( V_41 ) ) ;
for ( V_180 = 0 ; V_180 < V_58 ; V_180 ++ )
if ( F_270 ( V_41 [ V_180 ] ) && ! F_176 ( V_41 [ V_180 ] ) ) {
V_110 = F_264 ( V_41 [ V_180 ] . V_41 ) ;
V_131 = F_294 ( V_131 , V_110 ) ;
}
return V_131 ;
}
void T_12 F_276 ( T_7 * V_40 , unsigned long V_179 )
{
T_2 * V_242 ;
V_242 = F_265 ( V_40 [ V_239 ] . V_40 ) ;
V_206 = F_296 ( V_242 ) ;
V_207 = V_126 -> V_132 * V_112 ;
V_238 =
F_269 ( sizeof( T_2 ) * V_58 , V_112 ) ;
V_186 = F_123 ( V_206 + V_207 + 512 * 1024 ) ;
F_277 ( V_238 , V_242 ) ;
F_268 ( V_238 , V_179 ) ;
F_277 ( V_236 , V_40 ) ;
V_236 [ V_239 ] =
F_195 ( F_124 ( V_238 ) | V_32 ) ;
F_267 ( V_238 , V_79 ) ;
F_267 ( V_236 , V_79 ) ;
F_267 ( V_243 , V_79 ) ;
F_165 ( V_88 , F_123 ( F_124 ( V_40 ) ) ) ;
F_165 ( V_85 ,
F_123 ( F_124 ( V_236 ) ) ) ;
F_227 ( F_124 ( V_236 ) ) ;
F_280 ( V_206 , V_207 ) ;
}
void T_12 F_297 ( void )
{
T_15 V_110 ;
F_280 ( F_124 ( V_126 ) , V_112 ) ;
if ( V_126 -> V_244 ) {
V_110 = F_243 ( F_47 ( V_126 -> V_244 ) ) ;
F_280 ( V_110 , V_112 ) ;
}
if ( ! F_298 () ) {
V_110 = F_243 ( F_47 ( V_126 -> V_245 . V_246 . V_25 ) ) ;
F_280 ( V_110 , V_112 ) ;
}
}
void T_12 F_299 ( void )
{
if ( F_300 ( V_206 , V_207 ) ) {
F_292 ( L_2 ) ;
F_5 () ;
}
}
static void F_301 ( unsigned V_247 , T_15 V_248 , T_3 V_170 )
{
T_1 V_2 ;
V_248 >>= V_34 ;
switch ( V_247 ) {
case V_249 ... V_250 :
case V_251 :
#ifdef F_237
case V_252 :
# ifdef F_302
case V_253 ... V_254 :
# endif
#elif F_303 ( F_232 )
case V_255 :
#endif
case V_256 :
case V_257 :
case V_258 ... V_259 :
V_2 = F_117 ( V_248 , V_170 ) ;
break;
#ifdef F_304
case V_260 :
V_2 = F_117 ( F_123 ( F_124 ( V_261 ) ) , V_89 ) ;
break;
#endif
#ifdef F_305
case V_262 ... V_263 :
V_2 = F_117 ( F_123 ( F_124 ( V_261 ) ) , V_89 ) ;
break;
#endif
case V_264 :
V_2 = F_33 ( V_248 , V_170 ) ;
break;
default:
V_2 = F_33 ( V_248 , V_170 ) ;
break;
}
F_306 ( V_247 , V_2 ) ;
#ifdef F_232
if ( V_247 == V_255 ) {
unsigned long V_1 = F_307 ( V_247 ) ;
F_308 ( V_164 , V_1 , V_2 ) ;
}
#endif
}
static void T_12 F_204 ( void )
{
V_240 . F_295 = F_38 ;
V_240 . F_71 = F_29 ;
V_240 . F_184 = F_60 ;
#if V_265 >= 4
V_240 . F_189 = F_83 ;
#endif
V_240 . V_266 = F_252 ;
V_240 . V_267 = F_253 ;
V_240 . V_268 = F_256 ;
V_240 . V_269 = F_257 ;
#if V_265 >= 4
V_240 . V_270 = F_258 ;
V_240 . V_271 = F_259 ;
#endif
V_240 . V_272 = F_309 ( F_53 ) ;
#ifdef F_122
V_240 . V_241 = & F_227 ;
F_133 ( F_9 ( V_164 ) ) ;
#endif
F_134 () ;
}
static void F_310 ( void )
{
F_24 () ;
F_169 () ;
F_311 () ;
F_28 () ;
}
void T_12 F_312 ( void )
{
V_273 . V_274 . V_275 = F_202 ;
V_240 = V_276 ;
memset ( V_261 , 0xff , V_112 ) ;
}
static void F_313 ( unsigned long V_1 , unsigned int V_277 ,
unsigned long * V_278 ,
unsigned long * V_279 )
{
int V_55 ;
struct V_11 V_12 ;
F_25 () ;
for ( V_55 = 0 ; V_55 < ( 1UL << V_277 ) ; V_55 ++ , V_1 += V_112 ) {
V_12 = F_20 ( 0 ) ;
if ( V_278 )
V_278 [ V_55 ] = F_314 ( V_1 ) ;
F_116 ( V_12 . V_17 , V_1 , V_280 , 0 ) ;
F_315 ( F_316 ( V_1 ) , V_37 ) ;
if ( V_279 )
V_279 [ V_55 ] = F_316 ( V_1 ) ;
}
F_17 ( 0 ) ;
}
static void F_317 ( unsigned long V_1 , int V_277 ,
unsigned long * V_281 ,
unsigned long V_282 )
{
unsigned V_55 , V_54 ;
unsigned long V_25 ;
F_25 () ;
V_54 = 1u << V_277 ;
for ( V_55 = 0 ; V_55 < V_54 ; V_55 ++ , V_1 += V_112 ) {
struct V_11 V_12 ;
unsigned V_26 ;
V_12 = F_20 ( 0 ) ;
if ( V_281 )
V_25 = V_281 [ V_55 ] ;
else
V_25 = V_282 + V_55 ;
if ( V_55 < ( V_54 - 1 ) )
V_26 = 0 ;
else {
if ( V_277 == 0 )
V_26 = V_197 | V_283 ;
else
V_26 = V_80 | V_283 ;
}
F_116 ( V_12 . V_17 , V_1 ,
F_33 ( V_25 , V_89 ) , V_26 ) ;
F_318 ( F_316 ( V_1 ) , V_25 ) ;
}
F_17 ( 0 ) ;
}
static int F_319 ( unsigned long V_284 , unsigned int V_285 ,
unsigned long * V_286 ,
unsigned long V_287 ,
unsigned int V_288 ,
unsigned long * V_289 ,
unsigned int V_290 )
{
long V_291 ;
int V_292 ;
struct V_293 V_294 = {
. V_295 = {
. V_296 = V_284 ,
. V_297 = V_285 ,
. V_298 = V_286 ,
. V_10 = V_21
} ,
. V_299 = {
. V_296 = V_287 ,
. V_297 = V_288 ,
. V_298 = V_289 ,
. V_290 = V_290 ,
. V_10 = V_21
}
} ;
F_100 ( V_284 << V_285 != V_287 << V_288 ) ;
V_291 = F_272 ( V_300 , & V_294 ) ;
V_292 = ( V_294 . V_301 == V_284 ) ;
F_100 ( ! V_292 && ( ( V_294 . V_301 != 0 ) || ( V_291 == 0 ) ) ) ;
F_100 ( V_292 && ( V_291 != 0 ) ) ;
return V_292 ;
}
int F_320 ( T_15 V_302 , unsigned int V_277 ,
unsigned int V_290 ,
T_16 * V_303 )
{
unsigned long * V_278 = V_304 , V_305 ;
unsigned long V_26 ;
int V_292 ;
unsigned long V_306 = ( unsigned long ) F_321 ( V_302 ) ;
if ( F_48 ( V_277 > V_307 ) )
return - V_160 ;
memset ( ( void * ) V_306 , 0 , V_112 << V_277 ) ;
F_322 ( & V_308 , V_26 ) ;
F_313 ( V_306 , V_277 , V_278 , NULL ) ;
V_305 = F_316 ( V_306 ) ;
V_292 = F_319 ( 1UL << V_277 , 0 , V_278 ,
1 , V_277 , & V_305 ,
V_290 ) ;
if ( V_292 )
F_317 ( V_306 , V_277 , NULL , V_305 ) ;
else
F_317 ( V_306 , V_277 , V_278 , 0 ) ;
F_323 ( & V_308 , V_26 ) ;
* V_303 = F_14 ( V_306 ) . V_15 ;
return V_292 ? 0 : - V_160 ;
}
void F_324 ( T_15 V_302 , unsigned int V_277 )
{
unsigned long * V_279 = V_304 , V_309 ;
unsigned long V_26 ;
int V_292 ;
unsigned long V_306 ;
if ( F_48 ( V_277 > V_307 ) )
return;
V_306 = ( unsigned long ) F_321 ( V_302 ) ;
memset ( ( void * ) V_306 , 0 , V_112 << V_277 ) ;
F_322 ( & V_308 , V_26 ) ;
V_309 = F_314 ( V_306 ) ;
F_313 ( V_306 , V_277 , NULL , V_279 ) ;
V_292 = F_319 ( 1 , V_277 , & V_309 , 1UL << V_277 ,
0 , V_279 , 0 ) ;
if ( V_292 )
F_317 ( V_306 , V_277 , V_279 , 0 ) ;
else
F_317 ( V_306 , V_277 , NULL , V_309 ) ;
F_323 ( & V_308 , V_26 ) ;
}
T_15 F_325 ( void )
{
if ( F_326 () )
return F_14 ( & V_310 ) . V_15 ;
else
return F_278 ( & V_310 ) ;
}
