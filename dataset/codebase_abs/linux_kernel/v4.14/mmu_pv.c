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
static void F_11 ( const struct V_8 * V_9 )
{
struct V_10 V_11 ;
struct V_8 * V_12 ;
V_11 = F_12 ( V_13 , sizeof( * V_12 ) ) ;
if ( V_11 . V_14 != NULL ) {
V_11 . V_14 -> args [ 1 ] ++ ;
} else {
V_11 = F_13 ( sizeof( * V_12 ) ) ;
F_14 ( V_11 . V_14 , V_11 . args , 1 , NULL , V_15 ) ;
}
V_12 = V_11 . args ;
* V_12 = * V_9 ;
}
static void F_15 ( const struct V_16 * V_17 )
{
struct V_10 V_11 ;
struct V_16 * V_12 ;
V_11 = F_12 ( V_18 , sizeof( * V_12 ) ) ;
if ( V_11 . V_14 != NULL ) {
V_11 . V_14 -> args [ 1 ] ++ ;
} else {
V_11 = F_13 ( sizeof( * V_12 ) ) ;
F_16 ( V_11 . V_14 , V_11 . args , 1 , NULL , V_15 ) ;
}
V_12 = V_11 . args ;
* V_12 = * V_17 ;
}
static void F_17 ( T_2 * V_6 , T_2 V_19 )
{
struct V_8 V_12 ;
F_18 () ;
F_19 () ;
V_12 . V_6 = F_20 ( V_6 ) . V_20 ;
V_12 . V_19 = F_21 ( V_19 ) ;
F_11 ( & V_12 ) ;
F_22 ( V_21 ) ;
F_23 () ;
}
static void F_24 ( T_2 * V_6 , T_2 V_19 )
{
F_25 ( V_6 , V_19 ) ;
if ( ! F_8 ( V_6 ) ) {
* V_6 = V_19 ;
return;
}
F_17 ( V_6 , V_19 ) ;
}
void F_26 ( unsigned long V_1 , unsigned long V_22 , T_3 V_23 )
{
F_27 ( V_1 , F_28 ( V_22 , V_23 ) ) ;
}
static bool F_29 ( T_1 * V_24 , T_1 V_25 )
{
struct V_8 V_12 ;
if ( F_30 () != V_21 )
return false ;
F_19 () ;
V_12 . V_6 = F_31 ( V_24 ) . V_20 | V_26 ;
V_12 . V_19 = F_32 ( V_25 ) ;
F_11 ( & V_12 ) ;
F_22 ( V_21 ) ;
return true ;
}
static inline void F_33 ( T_1 * V_24 , T_1 V_25 )
{
if ( ! F_29 ( V_24 , V_25 ) ) {
struct V_8 V_12 ;
V_12 . V_6 = F_31 ( V_24 ) . V_20 | V_26 ;
V_12 . V_19 = F_32 ( V_25 ) ;
F_34 ( & V_12 , 1 , NULL , V_15 ) ;
}
}
static void F_35 ( T_1 * V_24 , T_1 V_25 )
{
F_36 ( V_24 , V_25 ) ;
F_33 ( V_24 , V_25 ) ;
}
static void F_37 ( struct V_27 * V_28 , unsigned long V_29 ,
T_1 * V_24 , T_1 V_25 )
{
F_38 ( V_28 , V_29 , V_24 , V_25 ) ;
F_33 ( V_24 , V_25 ) ;
}
T_1 F_39 ( struct V_27 * V_28 ,
unsigned long V_29 , T_1 * V_24 )
{
F_40 ( V_28 , V_29 , V_24 , * V_24 ) ;
return * V_24 ;
}
void F_41 ( struct V_27 * V_28 , unsigned long V_29 ,
T_1 * V_24 , T_1 V_2 )
{
struct V_8 V_12 ;
F_42 ( V_28 , V_29 , V_24 , V_2 ) ;
F_19 () ;
V_12 . V_6 = F_31 ( V_24 ) . V_20 | V_30 ;
V_12 . V_19 = F_32 ( V_2 ) ;
F_11 ( & V_12 ) ;
F_22 ( V_21 ) ;
}
static T_4 F_43 ( T_4 V_19 )
{
if ( V_19 & V_31 ) {
unsigned long V_22 = ( V_19 & V_32 ) >> V_33 ;
unsigned long V_34 = F_44 ( V_22 ) ;
T_4 V_23 = V_19 & V_35 ;
if ( F_45 ( V_34 == ~ 0 ) )
V_19 = V_23 & ~ V_31 ;
else
V_19 = ( ( T_4 ) V_34 << V_33 ) | V_23 ;
}
return V_19 ;
}
static T_4 F_46 ( T_4 V_19 )
{
if ( V_19 & V_31 ) {
unsigned long V_34 = ( V_19 & V_32 ) >> V_33 ;
T_4 V_23 = V_19 & V_35 ;
unsigned long V_22 ;
V_22 = F_47 ( V_34 ) ;
if ( F_45 ( V_22 == V_36 ) ) {
V_22 = 0 ;
V_23 = 0 ;
} else
V_22 &= ~ ( V_37 | V_38 ) ;
V_19 = ( ( T_4 ) V_22 << V_33 ) | V_23 ;
}
return V_19 ;
}
T_5 T_4 F_48 ( T_1 V_2 )
{
T_4 V_25 = V_2 . V_2 ;
return F_43 ( V_25 ) ;
}
T_5 T_6 F_49 ( T_7 V_39 )
{
return F_43 ( V_39 . V_39 ) ;
}
T_5 T_1 F_50 ( T_4 V_2 )
{
V_2 = F_46 ( V_2 ) ;
return F_51 ( V_2 ) ;
}
T_5 T_7 F_52 ( T_6 V_39 )
{
V_39 = F_46 ( V_39 ) ;
return F_53 ( V_39 ) ;
}
T_5 T_8 F_54 ( T_2 V_40 )
{
return F_43 ( V_40 . V_40 ) ;
}
static void F_55 ( T_9 * V_6 , T_9 V_19 )
{
struct V_8 V_12 ;
F_18 () ;
F_19 () ;
V_12 . V_6 = F_20 ( V_6 ) . V_20 ;
V_12 . V_19 = F_56 ( V_19 ) ;
F_11 ( & V_12 ) ;
F_22 ( V_21 ) ;
F_23 () ;
}
static void F_57 ( T_9 * V_6 , T_9 V_19 )
{
F_58 ( V_6 , V_19 ) ;
if ( ! F_8 ( V_6 ) ) {
* V_6 = V_19 ;
return;
}
F_55 ( V_6 , V_19 ) ;
}
static void F_59 ( T_1 * V_24 , T_1 V_2 )
{
F_60 ( V_24 , V_2 ) ;
F_61 ( ( V_41 * ) V_24 , F_62 ( V_2 ) ) ;
}
static void F_63 ( struct V_27 * V_28 , unsigned long V_29 , T_1 * V_24 )
{
F_64 ( V_28 , V_29 , V_24 ) ;
if ( ! F_29 ( V_24 , F_51 ( 0 ) ) )
F_65 ( V_28 , V_29 , V_24 ) ;
}
static void F_66 ( T_2 * V_42 )
{
F_67 ( V_42 ) ;
F_68 ( V_42 , F_69 ( 0 ) ) ;
}
T_5 T_2 F_70 ( T_8 V_40 )
{
V_40 = F_46 ( V_40 ) ;
return F_71 ( V_40 ) ;
}
T_5 T_10 F_72 ( T_9 V_43 )
{
return F_43 ( V_43 . V_43 ) ;
}
T_5 T_9 F_73 ( T_10 V_43 )
{
V_43 = F_46 ( V_43 ) ;
return F_74 ( V_43 ) ;
}
static T_7 * F_75 ( T_7 * V_39 )
{
T_7 * V_44 = ( T_7 * ) ( ( ( unsigned long ) V_39 ) & V_45 ) ;
unsigned V_46 = V_39 - V_44 ;
T_7 * V_47 = NULL ;
if ( V_46 < F_76 ( V_48 ) ) {
struct V_7 * V_7 = F_9 ( V_44 ) ;
V_47 = ( T_7 * ) V_7 -> V_49 ;
if ( V_47 )
V_47 += V_46 ;
}
return V_47 ;
}
static void F_77 ( T_11 * V_6 , T_11 V_19 )
{
struct V_8 V_12 ;
V_12 . V_6 = F_31 ( V_6 ) . V_20 ;
V_12 . V_19 = F_78 ( V_19 ) ;
F_11 ( & V_12 ) ;
}
static void T_12 F_79 ( T_11 * V_6 , T_11 V_19 )
{
F_18 () ;
F_19 () ;
F_77 ( V_6 , V_19 ) ;
F_22 ( V_21 ) ;
F_23 () ;
}
static void F_80 ( T_11 * V_6 , T_11 V_19 )
{
T_7 * V_47 = F_75 ( ( T_7 * ) V_6 ) ;
T_7 V_50 ;
F_81 ( V_6 , ( T_11 * ) V_47 , V_19 ) ;
if ( ! F_8 ( V_6 ) ) {
* V_6 = V_19 ;
if ( V_47 ) {
F_82 ( F_8 ( V_47 ) ) ;
V_50 . V_39 = F_78 ( V_19 ) ;
* V_47 = V_50 ;
}
return;
}
F_19 () ;
F_77 ( V_6 , V_19 ) ;
if ( V_47 )
F_77 ( ( T_11 * ) V_47 , V_19 ) ;
F_22 ( V_21 ) ;
}
static int F_83 ( struct V_27 * V_28 , T_2 * V_40 ,
int (* F_84)( struct V_27 * V_28 , struct V_7 * , enum V_51 ) ,
bool V_52 , unsigned long V_53 )
{
int V_54 , V_55 , V_56 = 0 ;
V_55 = V_52 ? F_85 ( V_53 ) + 1 : V_57 ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
if ( ! F_86 ( V_40 [ V_54 ] ) )
V_56 |= (* F_84)( V_28 , F_87 ( V_40 [ V_54 ] ) , V_58 ) ;
}
return V_56 ;
}
static int F_88 ( struct V_27 * V_28 , T_9 * V_43 ,
int (* F_84)( struct V_27 * V_28 , struct V_7 * , enum V_51 ) ,
bool V_52 , unsigned long V_53 )
{
int V_54 , V_55 , V_56 = 0 ;
V_55 = V_52 ? F_89 ( V_53 ) + 1 : V_59 ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
T_2 * V_40 ;
if ( F_90 ( V_43 [ V_54 ] ) )
continue;
V_40 = F_91 ( & V_43 [ V_54 ] , 0 ) ;
if ( V_57 > 1 )
V_56 |= (* F_84)( V_28 , F_9 ( V_40 ) , V_60 ) ;
V_56 |= F_83 ( V_28 , V_40 , F_84 ,
V_52 && V_54 == V_55 - 1 , V_53 ) ;
}
return V_56 ;
}
static int F_92 ( struct V_27 * V_28 , T_11 * V_61 ,
int (* F_84)( struct V_27 * V_28 , struct V_7 * , enum V_51 ) ,
bool V_52 , unsigned long V_53 )
{
int V_54 , V_55 , V_56 = 0 ;
V_55 = V_52 ? F_93 ( V_53 ) + 1 : V_62 ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
T_9 * V_43 ;
if ( F_94 ( V_61 [ V_54 ] ) )
continue;
V_43 = F_95 ( & V_61 [ V_54 ] , 0 ) ;
if ( V_59 > 1 )
V_56 |= (* F_84)( V_28 , F_9 ( V_43 ) , V_63 ) ;
V_56 |= F_88 ( V_28 , V_43 , F_84 ,
V_52 && V_54 == V_55 - 1 , V_53 ) ;
}
return V_56 ;
}
static int F_96 ( struct V_27 * V_28 , T_7 * V_39 ,
int (* F_84)( struct V_27 * V_28 , struct V_7 * ,
enum V_51 ) ,
unsigned long V_53 )
{
int V_54 , V_55 , V_56 = 0 ;
unsigned V_64 , V_65 ;
V_53 -- ;
F_97 ( V_53 >= V_66 ) ;
V_64 = F_76 ( V_48 ) ;
V_65 = F_76 ( V_67 ) ;
V_55 = F_76 ( V_53 ) + 1 ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
T_11 * V_61 ;
if ( V_54 >= V_64 && V_54 < V_65 )
continue;
if ( F_98 ( V_39 [ V_54 ] ) )
continue;
V_61 = F_99 ( & V_39 [ V_54 ] , 0 ) ;
if ( V_62 > 1 )
V_56 |= (* F_84)( V_28 , F_9 ( V_61 ) , V_68 ) ;
V_56 |= F_92 ( V_28 , V_61 , F_84 , V_54 == V_55 - 1 , V_53 ) ;
}
V_56 |= (* F_84)( V_28 , F_9 ( V_39 ) , V_69 ) ;
return V_56 ;
}
static int F_100 ( struct V_27 * V_28 ,
int (* F_84)( struct V_27 * V_28 , struct V_7 * ,
enum V_51 ) ,
unsigned long V_53 )
{
return F_96 ( V_28 , V_28 -> V_39 , F_84 , V_53 ) ;
}
static T_13 * F_101 ( struct V_7 * V_7 , struct V_27 * V_28 )
{
T_13 * V_70 = NULL ;
#if V_71
V_70 = F_102 ( V_7 ) ;
F_103 ( V_70 , & V_28 -> V_72 ) ;
#endif
return V_70 ;
}
static void F_104 ( void * V_73 )
{
T_13 * V_70 = V_73 ;
F_105 ( V_70 ) ;
}
static void F_106 ( unsigned V_5 , unsigned long V_34 )
{
struct V_16 V_17 ;
V_17 . V_74 = V_5 ;
V_17 . V_75 . V_22 = F_107 ( V_34 ) ;
F_15 ( & V_17 ) ;
}
static int F_108 ( struct V_27 * V_28 , struct V_7 * V_7 ,
enum V_51 V_5 )
{
unsigned V_76 = F_109 ( V_7 ) ;
int V_56 ;
if ( V_76 )
V_56 = 0 ;
else if ( F_110 ( V_7 ) )
V_56 = 1 ;
else {
void * V_77 = F_111 ( V_7 ) ;
unsigned long V_34 = F_112 ( V_7 ) ;
struct V_10 V_11 = F_13 ( 0 ) ;
T_13 * V_70 ;
V_56 = 0 ;
V_70 = NULL ;
if ( V_5 == V_58 )
V_70 = F_101 ( V_7 , V_28 ) ;
F_113 ( V_11 . V_14 , ( unsigned long ) V_77 ,
F_114 ( V_34 , V_78 ) ,
V_5 == V_69 ? V_79 : 0 ) ;
if ( V_70 ) {
F_106 ( V_80 , V_34 ) ;
F_115 ( F_104 , V_70 ) ;
}
}
return V_56 ;
}
static void F_116 ( struct V_27 * V_28 , T_7 * V_39 )
{
F_117 ( V_28 , V_39 ) ;
F_19 () ;
if ( F_96 ( V_28 , V_39 , F_108 , V_48 ) ) {
F_22 ( 0 ) ;
F_118 () ;
F_19 () ;
}
#ifdef F_119
{
T_7 * V_81 = F_75 ( V_39 ) ;
F_106 ( V_82 , F_120 ( F_121 ( V_39 ) ) ) ;
if ( V_81 ) {
F_108 ( V_28 , F_9 ( V_81 ) , V_69 ) ;
F_106 ( V_82 ,
F_120 ( F_121 ( V_81 ) ) ) ;
}
}
#else
#ifdef F_122
F_108 ( V_28 , V_44 ( V_39 [ F_76 ( V_83 ) ] ) ,
V_60 ) ;
#endif
F_106 ( V_84 , F_120 ( F_121 ( V_39 ) ) ) ;
#endif
F_22 ( 0 ) ;
}
static void F_123 ( struct V_27 * V_28 )
{
F_116 ( V_28 , V_28 -> V_39 ) ;
}
void F_124 ( void )
{
struct V_7 * V_7 ;
F_125 ( & V_85 ) ;
F_126 (page, &pgd_list, lru) {
if ( ! F_10 ( V_7 ) ) {
F_116 ( & V_86 , ( T_7 * ) F_127 ( V_7 ) ) ;
F_128 ( V_7 ) ;
}
}
F_105 ( & V_85 ) ;
}
static int T_12 F_129 ( struct V_27 * V_28 , struct V_7 * V_7 ,
enum V_51 V_5 )
{
F_130 ( V_7 ) ;
return 0 ;
}
static void T_12 F_131 ( void )
{
F_100 ( & V_86 , F_129 , V_66 ) ;
}
static int F_132 ( struct V_27 * V_28 , struct V_7 * V_7 ,
enum V_51 V_5 )
{
unsigned V_76 = F_133 ( V_7 ) ;
if ( V_76 && ! F_110 ( V_7 ) ) {
void * V_77 = F_111 ( V_7 ) ;
unsigned long V_34 = F_112 ( V_7 ) ;
T_13 * V_70 = NULL ;
struct V_10 V_11 ;
if ( V_5 == V_58 ) {
V_70 = F_101 ( V_7 , V_28 ) ;
if ( V_70 )
F_106 ( V_87 , V_34 ) ;
}
V_11 = F_13 ( 0 ) ;
F_113 ( V_11 . V_14 , ( unsigned long ) V_77 ,
F_114 ( V_34 , V_88 ) ,
V_5 == V_69 ? V_79 : 0 ) ;
if ( V_70 ) {
F_115 ( F_104 , V_70 ) ;
}
}
return 0 ;
}
static void F_134 ( struct V_27 * V_28 , T_7 * V_39 )
{
F_135 ( V_28 , V_39 ) ;
F_19 () ;
F_106 ( V_87 , F_120 ( F_121 ( V_39 ) ) ) ;
#ifdef F_119
{
T_7 * V_81 = F_75 ( V_39 ) ;
if ( V_81 ) {
F_106 ( V_87 ,
F_120 ( F_121 ( V_81 ) ) ) ;
F_132 ( V_28 , F_9 ( V_81 ) , V_69 ) ;
}
}
#endif
#ifdef F_122
F_132 ( V_28 , V_44 ( V_39 [ F_76 ( V_83 ) ] ) ,
V_60 ) ;
#endif
F_96 ( V_28 , V_39 , F_132 , V_48 ) ;
F_22 ( 0 ) ;
}
static void F_136 ( struct V_27 * V_28 )
{
F_134 ( V_28 , V_28 -> V_39 ) ;
}
void F_137 ( void )
{
struct V_7 * V_7 ;
F_125 ( & V_85 ) ;
F_126 (page, &pgd_list, lru) {
if ( F_138 ( V_7 ) ) {
F_97 ( ! F_10 ( V_7 ) ) ;
F_134 ( & V_86 , ( T_7 * ) F_127 ( V_7 ) ) ;
F_139 ( V_7 ) ;
}
}
F_105 ( & V_85 ) ;
}
static void F_140 ( struct V_27 * V_89 , struct V_27 * V_90 )
{
F_125 ( & V_90 -> V_72 ) ;
F_123 ( V_90 ) ;
F_105 ( & V_90 -> V_72 ) ;
}
static void F_141 ( struct V_27 * V_91 , struct V_27 * V_28 )
{
F_125 ( & V_28 -> V_72 ) ;
F_123 ( V_28 ) ;
F_105 ( & V_28 -> V_72 ) ;
}
static void F_142 ( void * V_92 )
{
struct V_27 * V_28 = V_92 ;
if ( F_143 ( V_93 . V_94 ) == V_28 )
F_144 ( F_145 () ) ;
if ( F_143 ( V_95 ) == F_121 ( V_28 -> V_39 ) )
F_146 () ;
}
static void F_147 ( struct V_27 * V_28 )
{
T_14 V_96 ;
unsigned V_97 ;
F_142 ( V_28 ) ;
if ( ! F_148 ( & V_96 , V_98 ) ) {
F_149 (cpu) {
if ( F_150 ( V_95 , V_97 ) != F_121 ( V_28 -> V_39 ) )
continue;
F_151 ( V_97 , F_142 , V_28 , 1 ) ;
}
return;
}
F_152 ( V_96 ) ;
F_149 (cpu) {
if ( F_150 ( V_95 , V_97 ) == F_121 ( V_28 -> V_39 ) )
F_153 ( V_97 , V_96 ) ;
}
F_154 ( V_96 , F_142 , V_28 , 1 ) ;
F_155 ( V_96 ) ;
}
static void F_147 ( struct V_27 * V_28 )
{
F_142 ( V_28 ) ;
}
static void F_156 ( struct V_27 * V_28 )
{
F_157 () ;
F_147 ( V_28 ) ;
F_158 () ;
F_125 ( & V_28 -> V_72 ) ;
if ( F_8 ( V_28 -> V_39 ) )
F_136 ( V_28 ) ;
F_105 ( & V_28 -> V_72 ) ;
}
static void T_12 F_159 ( unsigned V_74 , unsigned long V_34 )
{
struct V_16 V_17 ;
V_17 . V_74 = V_74 ;
V_17 . V_75 . V_22 = F_107 ( V_34 ) ;
if ( F_160 ( & V_17 , 1 , NULL , V_15 ) )
F_5 () ;
}
static void T_12 F_161 ( unsigned long V_1 ,
unsigned long V_99 )
{
unsigned long V_100 = F_162 ( ( unsigned long ) V_101 , V_102 ) - 1 ;
T_2 * V_40 = V_103 + F_85 ( V_1 ) ;
for (; V_1 <= V_99 && ( V_40 < ( V_103 + V_57 ) ) ;
V_40 ++ , V_1 += V_102 ) {
if ( F_86 ( * V_40 ) )
continue;
if ( V_1 < ( unsigned long ) V_104 || V_1 > V_100 )
F_68 ( V_40 , F_69 ( 0 ) ) ;
}
F_146 () ;
}
static void T_12 F_163 ( unsigned long V_105 , unsigned long V_106 )
{
void * V_1 = F_164 ( V_105 ) ;
void * V_99 = V_1 + V_106 ;
for (; V_1 < V_99 ; V_1 += V_107 )
F_6 ( V_1 ) ;
F_165 ( V_105 , V_106 ) ;
}
static void T_12 F_166 ( void * V_108 , bool V_109 )
{
unsigned long V_110 = F_121 ( V_108 ) & V_111 ;
if ( V_109 )
F_159 ( V_87 , F_120 ( V_110 ) ) ;
F_167 ( F_9 ( F_164 ( V_110 ) ) ) ;
F_163 ( V_110 , V_107 ) ;
}
static void T_12 F_168 ( T_2 * V_40 , bool V_109 )
{
unsigned long V_110 ;
T_1 * V_112 ;
int V_54 ;
if ( F_169 ( * V_40 ) ) {
V_110 = F_170 ( * V_40 ) & V_111 ;
F_163 ( V_110 , V_102 ) ;
return;
}
V_112 = F_171 ( V_40 , 0 ) ;
for ( V_54 = 0 ; V_54 < V_113 ; V_54 ++ ) {
if ( F_172 ( V_112 [ V_54 ] ) )
continue;
V_110 = F_173 ( V_112 [ V_54 ] ) << V_33 ;
F_163 ( V_110 , V_107 ) ;
}
F_68 ( V_40 , F_69 ( 0 ) ) ;
F_166 ( V_112 , V_109 ) ;
}
static void T_12 F_174 ( T_9 * V_43 , bool V_109 )
{
unsigned long V_110 ;
T_2 * V_114 ;
int V_54 ;
if ( F_175 ( * V_43 ) ) {
V_110 = F_176 ( * V_43 ) & V_111 ;
F_163 ( V_110 , V_115 ) ;
return;
}
V_114 = F_91 ( V_43 , 0 ) ;
for ( V_54 = 0 ; V_54 < V_57 ; V_54 ++ ) {
if ( F_86 ( V_114 [ V_54 ] ) )
continue;
F_168 ( V_114 + V_54 , V_109 ) ;
}
F_177 ( V_43 , F_178 ( 0 ) ) ;
F_166 ( V_114 , V_109 ) ;
}
static void T_12 F_179 ( T_11 * V_61 , bool V_109 )
{
unsigned long V_110 ;
T_9 * V_116 ;
int V_54 ;
if ( F_180 ( * V_61 ) ) {
V_110 = F_181 ( * V_61 ) & V_111 ;
F_163 ( V_110 , V_117 ) ;
return;
}
V_116 = F_95 ( V_61 , 0 ) ;
for ( V_54 = 0 ; V_54 < V_59 ; V_54 ++ ) {
if ( F_90 ( V_116 [ V_54 ] ) )
continue;
F_174 ( V_116 + V_54 , V_109 ) ;
}
F_182 ( V_61 , F_183 ( 0 ) ) ;
F_166 ( V_116 , V_109 ) ;
}
static void T_12 F_184 ( unsigned long V_1 )
{
T_7 * V_39 ;
T_11 * V_61 ;
unsigned int V_54 ;
bool V_109 ;
V_109 = ( V_1 == 2 * V_118 ) ;
V_1 &= V_119 ;
V_39 = F_185 ( V_1 ) ;
V_61 = F_99 ( V_39 , 0 ) ;
for ( V_54 = 0 ; V_54 < V_62 ; V_54 ++ ) {
if ( F_94 ( V_61 [ V_54 ] ) )
continue;
F_179 ( V_61 + V_54 , V_109 ) ;
}
if ( F_186 ( V_120 ) ) {
F_187 ( V_39 , F_188 ( 0 ) ) ;
F_166 ( V_61 , V_109 ) ;
}
}
static void T_12 F_189 ( void )
{
unsigned long V_106 ;
unsigned long V_29 ;
V_106 = F_190 ( V_121 -> V_122 * sizeof( unsigned long ) ) ;
if ( ( unsigned long ) V_123 == V_121 -> V_124 )
return;
memset ( ( void * ) V_121 -> V_124 , 0xff , V_106 ) ;
V_29 = V_121 -> V_124 ;
V_106 = F_162 ( V_106 , V_102 ) ;
if ( V_29 >= V_125 ) {
F_161 ( V_29 , V_29 + V_106 ) ;
V_106 = F_190 ( V_121 -> V_122 *
sizeof( unsigned long ) ) ;
F_165 ( F_121 ( V_29 ) , V_106 ) ;
} else {
F_184 ( V_29 ) ;
}
}
static void T_12 F_191 ( void )
{
unsigned long V_106 ;
unsigned long V_29 ;
V_29 = V_121 -> V_126 ;
V_106 = V_121 -> V_127 * V_107 ;
F_161 ( V_29 , F_162 ( V_29 + V_106 , V_102 * 2 ) ) ;
V_121 -> V_126 = ( unsigned long ) F_164 ( F_121 ( V_121 -> V_126 ) ) ;
}
static void T_12 F_192 ( void )
{
F_193 () ;
#ifdef F_119
F_189 () ;
F_191 () ;
#endif
V_121 -> V_124 = ( unsigned long ) V_123 ;
}
static void T_12 F_194 ( void )
{
F_195 () ;
F_196 () ;
F_192 () ;
F_197 () ;
F_198 () ;
F_199 () ;
}
static void F_200 ( unsigned long V_128 )
{
F_143 ( V_129 ) -> V_130 . V_128 = V_128 ;
}
static unsigned long F_201 ( void )
{
return F_143 ( V_129 ) -> V_130 . V_128 ;
}
unsigned long F_202 ( void )
{
return F_143 ( V_131 . V_130 . V_128 ) ;
}
static void F_203 ( void )
{
struct V_16 * V_17 ;
struct V_10 V_11 ;
F_204 ( 0 ) ;
F_18 () ;
V_11 = F_205 ( sizeof( * V_17 ) ) ;
V_17 = V_11 . args ;
V_17 -> V_74 = V_132 ;
F_16 ( V_11 . V_14 , V_17 , 1 , NULL , V_15 ) ;
F_22 ( V_21 ) ;
F_23 () ;
}
static void F_206 ( unsigned long V_29 )
{
struct V_16 * V_17 ;
struct V_10 V_11 ;
F_207 ( V_29 ) ;
F_18 () ;
V_11 = F_205 ( sizeof( * V_17 ) ) ;
V_17 = V_11 . args ;
V_17 -> V_74 = V_133 ;
V_17 -> V_75 . V_134 = V_29 & V_45 ;
F_16 ( V_11 . V_14 , V_17 , 1 , NULL , V_15 ) ;
F_22 ( V_21 ) ;
F_23 () ;
}
static void F_208 ( const struct V_135 * V_136 ,
const struct V_137 * V_92 )
{
struct {
struct V_16 V_17 ;
#ifdef F_209
F_210 ( V_96 , V_138 ) ;
#else
F_210 ( V_96 , V_139 ) ;
#endif
} * args ;
struct V_10 V_11 ;
F_211 ( V_136 , V_92 -> V_28 , V_92 -> V_140 , V_92 -> V_141 ) ;
if ( F_212 ( V_136 ) )
return;
V_11 = F_205 ( sizeof( * args ) ) ;
args = V_11 . args ;
args -> V_17 . V_142 . V_143 = F_213 ( args -> V_96 ) ;
F_214 ( F_213 ( args -> V_96 ) , V_136 , V_144 ) ;
F_215 ( F_145 () , F_213 ( args -> V_96 ) ) ;
args -> V_17 . V_74 = V_145 ;
if ( V_92 -> V_141 != V_146 &&
( V_92 -> V_141 - V_92 -> V_140 ) <= V_107 ) {
args -> V_17 . V_74 = V_147 ;
args -> V_17 . V_75 . V_134 = V_92 -> V_140 ;
}
F_16 ( V_11 . V_14 , & args -> V_17 , 1 , NULL , V_15 ) ;
F_22 ( V_21 ) ;
}
static unsigned long F_216 ( void )
{
return F_143 ( V_148 ) ;
}
static void F_217 ( void * V_73 )
{
F_218 ( V_95 , ( unsigned long ) V_73 ) ;
}
static void F_219 ( bool V_149 , unsigned long V_150 )
{
struct V_16 V_17 ;
unsigned long V_22 ;
F_220 ( V_149 , V_150 ) ;
if ( V_150 )
V_22 = F_107 ( F_120 ( V_150 ) ) ;
else
V_22 = 0 ;
F_82 ( V_22 == 0 && V_149 ) ;
V_17 . V_74 = V_149 ? V_151 : V_152 ;
V_17 . V_75 . V_22 = V_22 ;
F_15 ( & V_17 ) ;
if ( V_149 ) {
F_218 ( V_148 , V_150 ) ;
F_115 ( F_217 , ( void * ) V_150 ) ;
}
}
static void F_221 ( unsigned long V_150 )
{
F_97 ( F_222 () ) ;
F_19 () ;
F_218 ( V_148 , V_150 ) ;
F_219 ( true , V_150 ) ;
#ifdef F_119
{
T_7 * V_81 = F_75 ( F_164 ( V_150 ) ) ;
if ( V_81 )
F_219 ( false , F_121 ( V_81 ) ) ;
else
F_219 ( false , 0 ) ;
}
#endif
F_22 ( V_153 ) ;
}
static void T_12 F_223 ( unsigned long V_150 )
{
F_97 ( F_222 () ) ;
F_19 () ;
F_218 ( V_148 , V_150 ) ;
F_219 ( true , V_150 ) ;
F_22 ( V_153 ) ;
}
static int F_224 ( struct V_27 * V_28 )
{
T_7 * V_39 = V_28 -> V_39 ;
int V_154 = 0 ;
F_97 ( F_10 ( F_9 ( V_39 ) ) ) ;
#ifdef F_119
{
struct V_7 * V_7 = F_9 ( V_39 ) ;
T_7 * V_81 ;
F_97 ( V_7 -> V_49 != 0 ) ;
V_154 = - V_155 ;
V_81 = ( T_7 * ) F_225 ( V_156 | V_157 ) ;
V_7 -> V_49 = ( unsigned long ) V_81 ;
if ( V_81 != NULL ) {
#ifdef F_226
V_81 [ F_76 ( V_158 ) ] =
F_188 ( F_121 ( V_159 ) | V_160 ) ;
#endif
V_154 = 0 ;
}
F_97 ( F_10 ( F_9 ( F_75 ( V_39 ) ) ) ) ;
}
#endif
return V_154 ;
}
static void F_227 ( struct V_27 * V_28 , T_7 * V_39 )
{
#ifdef F_119
T_7 * V_81 = F_75 ( V_39 ) ;
if ( V_81 )
F_228 ( ( unsigned long ) V_81 ) ;
#endif
}
T_5 T_1 F_229 ( T_4 V_2 )
{
#ifdef F_119
unsigned long V_34 ;
V_34 = ( V_2 & V_32 ) >> V_33 ;
if ( V_121 -> V_124 < V_125 &&
V_34 >= V_121 -> V_161 &&
V_34 < V_121 -> V_161 + V_121 -> V_162 )
V_2 &= ~ V_163 ;
#endif
V_2 = F_46 ( V_2 ) ;
return F_51 ( V_2 ) ;
}
static void T_12 F_230 ( T_1 * V_24 , T_1 V_2 )
{
#ifdef F_231
if ( F_232 ( V_2 ) != V_36
&& F_32 ( * V_24 ) & V_31 )
V_2 = F_233 ( ( ( F_32 ( * V_24 ) & V_163 ) | ~ V_163 ) &
F_32 ( V_2 ) ) ;
#endif
F_234 ( V_24 , V_2 ) ;
}
static void T_12 F_235 ( struct V_27 * V_28 , unsigned long V_34 )
{
#ifdef F_236
F_97 ( V_164 ) ;
#endif
F_1 ( F_164 ( F_237 ( V_34 ) ) ) ;
F_159 ( V_80 , V_34 ) ;
}
static void T_12 F_238 ( struct V_27 * V_28 , unsigned long V_34 )
{
#ifdef F_236
F_97 ( V_164 ) ;
#endif
F_1 ( F_164 ( F_237 ( V_34 ) ) ) ;
}
static void T_12 F_239 ( unsigned long V_34 )
{
F_159 ( V_87 , V_34 ) ;
F_6 ( F_164 ( F_237 ( V_34 ) ) ) ;
}
static void T_12 F_240 ( unsigned long V_34 )
{
F_6 ( F_164 ( F_237 ( V_34 ) ) ) ;
}
static inline void F_241 ( unsigned V_74 , unsigned long V_34 )
{
struct V_10 V_11 ;
struct V_16 * V_17 ;
V_11 = F_13 ( sizeof( * V_17 ) ) ;
V_17 = V_11 . args ;
V_17 -> V_74 = V_74 ;
V_17 -> V_75 . V_22 = F_107 ( V_34 ) ;
F_16 ( V_11 . V_14 , V_11 . args , 1 , NULL , V_15 ) ;
}
static inline void F_242 ( unsigned long V_34 , T_3 V_165 )
{
struct V_10 V_11 ;
unsigned long V_29 = ( unsigned long ) F_164 ( V_34 << V_33 ) ;
V_11 = F_13 ( 0 ) ;
F_113 ( V_11 . V_14 , ( unsigned long ) V_29 ,
F_114 ( V_34 , V_165 ) , 0 ) ;
}
static inline void F_243 ( struct V_27 * V_28 , unsigned long V_34 ,
unsigned V_5 )
{
bool V_166 = F_10 ( F_9 ( V_28 -> V_39 ) ) ;
F_244 ( V_28 , V_34 , V_5 , V_166 ) ;
if ( V_166 ) {
struct V_7 * V_7 = F_245 ( V_34 ) ;
F_130 ( V_7 ) ;
if ( ! F_110 ( V_7 ) ) {
F_19 () ;
F_242 ( V_34 , V_78 ) ;
if ( V_5 == V_58 && V_71 )
F_241 ( V_80 , V_34 ) ;
F_22 ( V_21 ) ;
} else {
F_118 () ;
}
}
}
static void F_246 ( struct V_27 * V_28 , unsigned long V_34 )
{
F_243 ( V_28 , V_34 , V_58 ) ;
}
static void F_247 ( struct V_27 * V_28 , unsigned long V_34 )
{
F_243 ( V_28 , V_34 , V_60 ) ;
}
static inline void F_248 ( unsigned long V_34 , unsigned V_5 )
{
struct V_7 * V_7 = F_245 ( V_34 ) ;
bool V_166 = F_10 ( V_7 ) ;
F_249 ( V_34 , V_5 , V_166 ) ;
if ( V_166 ) {
if ( ! F_110 ( V_7 ) ) {
F_19 () ;
if ( V_5 == V_58 && V_71 )
F_241 ( V_87 , V_34 ) ;
F_242 ( V_34 , V_88 ) ;
F_22 ( V_21 ) ;
}
F_167 ( V_7 ) ;
}
}
static void F_250 ( unsigned long V_34 )
{
F_248 ( V_34 , V_58 ) ;
}
static void F_251 ( unsigned long V_34 )
{
F_248 ( V_34 , V_60 ) ;
}
static void F_252 ( struct V_27 * V_28 , unsigned long V_34 )
{
F_243 ( V_28 , V_34 , V_63 ) ;
}
static void F_253 ( unsigned long V_34 )
{
F_248 ( V_34 , V_63 ) ;
}
void T_12 F_254 ( void )
{
#ifdef F_231
unsigned long V_167 = V_168 ;
struct V_169 V_170 ;
if ( F_255 ( V_171 , & V_170 ) == 0 )
V_167 = V_170 . V_172 ;
F_256 ( - V_167 ) ;
#endif
}
static void * T_12 F_257 ( T_15 V_105 )
{
#ifdef F_119
return ( void * ) ( V_105 + V_125 ) ;
#else
return F_164 ( V_105 ) ;
#endif
}
static unsigned long T_12 F_258 ( T_15 V_20 )
{
T_15 V_105 ;
V_20 &= V_32 ;
V_105 = F_44 ( V_20 >> V_33 ) << V_33 ;
return V_105 ;
}
static void * T_12 F_259 ( T_15 V_20 )
{
return F_257 ( F_258 ( V_20 ) ) ;
}
static void T_12 F_260 ( void * V_29 , T_3 V_165 ,
unsigned long V_23 )
{
unsigned long V_34 = F_121 ( V_29 ) >> V_33 ;
T_1 V_2 = F_114 ( V_34 , V_165 ) ;
if ( F_4 ( ( unsigned long ) V_29 , V_2 , V_23 ) )
F_5 () ;
}
static void T_12 F_261 ( void * V_29 , T_3 V_165 )
{
return F_260 ( V_29 , V_165 , V_173 ) ;
}
static void T_12 F_262 ( T_2 * V_40 , unsigned long V_174 )
{
unsigned V_175 , V_176 ;
unsigned V_177 ;
unsigned long V_34 ;
V_178 = F_263 ( sizeof( T_1 ) * V_179 ,
V_107 ) ;
V_177 = 0 ;
V_34 = 0 ;
for ( V_175 = 0 ; V_175 < V_57 && V_34 < V_174 ; V_175 ++ ) {
T_1 * V_180 ;
if ( F_264 ( V_40 [ V_175 ] ) )
V_180 = F_259 ( V_40 [ V_175 ] . V_40 ) ;
else {
if ( V_177 == V_179 )
break;
V_180 = & V_178 [ V_177 ] ;
V_177 += V_113 ;
V_40 [ V_175 ] = F_69 ( F_121 ( V_180 ) | V_160 ) ;
}
for ( V_176 = 0 ; V_176 < V_113 ; V_176 ++ , V_34 ++ ) {
T_1 V_2 ;
if ( V_34 > V_181 )
V_181 = V_34 ;
if ( ! F_172 ( V_180 [ V_176 ] ) )
continue;
V_2 = F_114 ( V_34 , V_182 ) ;
V_180 [ V_176 ] = V_2 ;
}
}
for ( V_176 = 0 ; V_176 < V_177 ; V_176 += V_113 )
F_261 ( & V_178 [ V_176 ] , V_78 ) ;
F_261 ( V_40 , V_78 ) ;
}
void T_12 F_265 ( void )
{
struct V_183 V_184 ;
if ( F_266 ( V_185 , & V_184 ) == 0 ) {
V_186 = ( unsigned long * ) V_184 . V_187 ;
V_188 = V_184 . V_189 + 1 ;
} else {
V_188 = V_190 ;
}
#ifdef F_231
F_82 ( ( V_186 + ( V_188 - 1 ) )
< V_186 ) ;
#endif
}
static void T_12 F_267 ( void * V_73 )
{
T_1 * V_2 = V_73 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_113 ; V_54 ++ )
V_2 [ V_54 ] = F_50 ( V_2 [ V_54 ] . V_2 ) ;
}
static void T_12 F_268 ( unsigned long * V_126 , unsigned long * V_191 ,
unsigned long V_29 )
{
if ( * V_126 == F_120 ( F_121 ( V_29 ) ) ) {
F_260 ( ( void * ) V_29 , V_88 , V_192 ) ;
F_269 ( ( void * ) V_29 ) ;
( * V_126 ) ++ ;
}
if ( * V_191 == F_120 ( F_121 ( V_29 ) ) ) {
F_260 ( ( void * ) V_29 , V_88 , V_192 ) ;
F_269 ( ( void * ) V_29 ) ;
( * V_191 ) -- ;
}
}
void T_12 F_270 ( T_7 * V_39 , unsigned long V_174 )
{
T_9 * V_193 ;
T_2 * V_194 ;
unsigned long V_29 [ 3 ] ;
unsigned long V_126 , V_191 ;
unsigned V_54 ;
if ( V_121 -> V_124 < V_125 )
V_181 = V_121 -> V_161 ;
else
V_181 = F_120 ( F_121 ( V_121 -> V_124 ) ) ;
V_126 = F_120 ( F_121 ( V_121 -> V_126 ) ) ;
V_191 = V_126 + V_121 -> V_127 ;
V_195 [ 0 ] = F_188 ( 0 ) ;
F_267 ( V_195 ) ;
F_267 ( V_196 ) ;
F_267 ( V_197 ) ;
F_267 ( V_198 ) ;
V_193 = F_259 ( V_39 [ F_76 ( V_125 ) ] . V_39 ) ;
V_194 = F_259 ( V_193 [ F_89 ( V_125 ) ] . V_43 ) ;
V_29 [ 0 ] = ( unsigned long ) V_39 ;
V_29 [ 1 ] = ( unsigned long ) V_193 ;
V_29 [ 2 ] = ( unsigned long ) V_194 ;
F_271 ( V_199 , V_194 ) ;
F_271 ( V_103 , V_194 ) ;
V_54 = F_76 ( V_121 -> V_124 ) ;
if ( V_54 && V_54 < F_76 ( V_125 ) )
V_195 [ V_54 ] = ( ( T_7 * ) V_121 -> V_126 ) [ V_54 ] ;
F_261 ( V_195 , V_78 ) ;
F_261 ( V_196 , V_78 ) ;
F_261 ( V_197 , V_78 ) ;
F_261 ( V_159 , V_78 ) ;
F_261 ( V_199 , V_78 ) ;
F_261 ( V_103 , V_78 ) ;
F_261 ( V_198 , V_78 ) ;
F_261 ( V_200 , V_78 ) ;
F_159 ( V_82 ,
F_120 ( F_272 ( V_195 ) ) ) ;
F_159 ( V_87 , F_120 ( F_121 ( V_39 ) ) ) ;
F_19 () ;
F_219 ( true , F_121 ( V_195 ) ) ;
F_22 ( V_153 ) ;
for ( V_54 = 0 ; V_54 < F_273 ( V_29 ) ; V_54 ++ )
F_268 ( & V_126 , & V_191 , V_29 [ V_54 ] ) ;
V_201 = F_237 ( V_126 ) ;
V_202 = ( V_191 - V_126 ) * V_107 ;
F_274 ( V_201 , V_202 ) ;
V_121 = (struct V_203 * ) F_164 ( F_121 ( V_121 ) ) ;
}
static unsigned long T_12 F_275 ( T_15 V_29 )
{
unsigned long * V_1 ;
unsigned long V_19 ;
V_1 = F_276 ( V_29 , sizeof( V_19 ) ) ;
V_19 = * V_1 ;
F_277 ( V_1 , sizeof( V_19 ) ) ;
return V_19 ;
}
static T_15 T_12 F_278 ( unsigned long V_1 )
{
T_15 V_110 ;
T_7 V_39 ;
T_9 V_43 ;
T_2 V_40 ;
T_1 V_2 ;
V_110 = F_279 () ;
V_39 = F_53 ( F_275 ( V_110 + F_76 ( V_1 ) *
sizeof( V_39 ) ) ) ;
if ( ! F_280 ( V_39 ) )
return 0 ;
V_110 = V_50 ( V_39 ) & V_32 ;
V_43 = F_74 ( F_275 ( V_110 + F_89 ( V_1 ) *
sizeof( V_43 ) ) ) ;
if ( ! F_281 ( V_43 ) )
return 0 ;
V_110 = F_176 ( V_43 ) & V_32 ;
if ( F_175 ( V_43 ) )
return V_110 + ( V_1 & ~ V_204 ) ;
V_40 = F_71 ( F_275 ( V_110 + F_85 ( V_1 ) *
sizeof( V_40 ) ) ) ;
if ( ! F_264 ( V_40 ) )
return 0 ;
V_110 = F_170 ( V_40 ) & V_32 ;
if ( F_169 ( V_40 ) )
return V_110 + ( V_1 & ~ V_119 ) ;
V_2 = F_51 ( F_275 ( V_110 + F_282 ( V_1 ) *
sizeof( V_2 ) ) ) ;
if ( ! F_283 ( V_2 ) )
return 0 ;
V_110 = F_173 ( V_2 ) << V_33 ;
return V_110 | ( V_1 & ~ V_45 ) ;
}
void T_12 F_284 ( void )
{
T_15 V_106 , V_205 , V_206 , V_207 , V_208 , V_209 ;
unsigned long V_210 , V_211 , V_212 , V_34 , V_213 ;
int V_214 , V_215 , V_216 , V_217 , V_218 , V_219 , V_220 , V_221 , V_222 , V_223 ;
T_1 * V_77 ;
T_2 * V_40 ;
T_9 * V_43 ;
T_11 * V_61 = NULL ;
T_7 * V_39 ;
unsigned long * V_224 ;
int V_225 ;
V_106 = F_190 ( V_121 -> V_122 * sizeof( unsigned long ) ) ;
V_214 = F_162 ( V_106 , V_107 ) >> V_33 ;
V_215 = F_162 ( V_106 , V_102 ) >> V_226 ;
V_216 = F_162 ( V_106 , V_115 ) >> V_227 ;
V_217 = F_162 ( V_106 , V_117 ) >> V_228 ;
if ( V_62 > 1 )
V_218 = F_162 ( V_106 , V_118 ) >> V_229 ;
else
V_218 = 0 ;
V_212 = V_214 + V_215 + V_216 + V_217 + V_218 ;
V_205 = F_285 ( F_237 ( V_212 ) ) ;
if ( ! V_205 ) {
F_286 ( L_1 ) ;
F_5 () ;
}
V_209 = V_205 ;
V_208 = V_209 + F_237 ( V_218 ) ;
V_207 = V_208 + F_237 ( V_217 ) ;
V_206 = V_207 + F_237 ( V_216 ) ;
V_210 = F_120 ( V_206 ) + V_215 ;
V_39 = F_164 ( F_279 () ) ;
V_224 = ( unsigned long * ) ( 2 * V_118 ) ;
V_223 = 0 ;
V_225 = V_217 ;
do {
if ( V_218 > 0 ) {
V_61 = F_287 ( V_209 , V_107 ) ;
F_269 ( V_61 ) ;
V_217 = F_288 ( V_225 , V_62 ) ;
}
for ( V_222 = 0 ; V_222 < V_217 ; V_222 ++ ) {
V_43 = F_287 ( V_208 , V_107 ) ;
F_269 ( V_43 ) ;
for ( V_221 = 0 ; V_221 < F_288 ( V_216 , V_59 ) ;
V_221 ++ ) {
V_40 = F_287 ( V_207 , V_107 ) ;
F_269 ( V_40 ) ;
for ( V_220 = 0 ; V_220 < F_288 ( V_215 , V_57 ) ;
V_220 ++ ) {
V_77 = F_287 ( V_206 , V_107 ) ;
F_269 ( V_77 ) ;
for ( V_219 = 0 ;
V_219 < F_288 ( V_214 , V_113 ) ;
V_219 ++ ) {
F_289 ( V_77 + V_219 ,
F_114 ( V_210 , V_88 ) ) ;
V_210 ++ ;
}
V_214 -= V_113 ;
F_277 ( V_77 , V_107 ) ;
F_1 ( F_164 ( V_206 ) ) ;
F_159 ( V_80 ,
F_120 ( V_206 ) ) ;
F_68 ( V_40 + V_220 ,
F_69 ( V_160 | V_206 ) ) ;
V_206 += V_107 ;
}
V_215 -= V_57 ;
F_277 ( V_40 , V_107 ) ;
F_1 ( F_164 ( V_207 ) ) ;
F_159 ( V_230 ,
F_120 ( V_207 ) ) ;
F_177 ( V_43 + V_221 , F_178 ( V_160 | V_207 ) ) ;
V_207 += V_107 ;
}
V_216 -= V_59 ;
F_277 ( V_43 , V_107 ) ;
F_1 ( F_164 ( V_208 ) ) ;
F_159 ( V_84 , F_120 ( V_208 ) ) ;
if ( V_218 > 0 )
F_182 ( V_61 + V_222 , F_183 ( V_160 | V_208 ) ) ;
else
F_187 ( V_39 + 2 + V_222 , F_188 ( V_160 | V_208 ) ) ;
V_208 += V_107 ;
}
if ( V_218 > 0 ) {
V_225 -= V_62 ;
F_277 ( V_61 , V_107 ) ;
F_1 ( F_164 ( V_209 ) ) ;
F_159 ( V_82 , F_120 ( V_209 ) ) ;
F_187 ( V_39 + 2 + V_223 , F_188 ( V_160 | V_209 ) ) ;
V_209 += V_107 ;
}
} while ( ++ V_223 < V_218 );
memcpy ( V_224 , V_123 , V_106 ) ;
V_123 = V_224 ;
V_210 = F_120 ( F_278 ( V_121 -> V_124 ) ) ;
F_97 ( ! V_210 ) ;
V_211 = V_210 + F_120 ( V_106 ) ;
if ( V_121 -> V_124 < V_125 ) {
V_34 = V_121 -> V_161 ;
V_213 = V_121 -> V_161 +
V_121 -> V_162 ;
F_187 ( V_39 + 1 , F_188 ( 0 ) ) ;
} else {
V_34 = V_210 ;
V_213 = V_211 ;
}
F_165 ( F_237 ( V_34 ) , V_107 * ( V_213 - V_34 ) ) ;
while ( V_34 < V_213 ) {
if ( V_34 == V_210 ) {
V_34 = V_211 ;
continue;
}
F_6 ( F_164 ( F_237 ( V_34 ) ) ) ;
V_34 ++ ;
}
V_121 -> V_124 = ( unsigned long ) V_123 ;
V_121 -> V_161 = F_120 ( V_205 ) ;
V_121 -> V_162 = V_212 ;
}
static void T_12 F_223 ( unsigned long V_150 )
{
unsigned long V_34 = F_120 ( F_121 ( V_231 ) ) ;
F_97 ( F_279 () != F_121 ( V_232 ) ) ;
F_97 ( V_150 != F_121 ( V_231 ) ) ;
V_233 =
F_263 ( sizeof( T_2 ) * V_57 , V_107 ) ;
F_271 ( V_233 , V_234 ) ;
V_231 [ V_235 ] =
F_188 ( F_121 ( V_233 ) | V_31 ) ;
F_261 ( V_233 , V_78 ) ;
F_261 ( V_231 , V_78 ) ;
F_221 ( V_150 ) ;
F_159 ( V_84 , V_34 ) ;
F_159 ( V_87 ,
F_120 ( F_121 ( V_232 ) ) ) ;
F_261 ( V_232 , V_88 ) ;
F_261 ( V_234 , V_88 ) ;
V_236 . V_237 = & F_221 ;
}
static T_15 T_12 F_290 ( T_2 * V_40 )
{
T_15 V_126 , V_105 ;
unsigned V_175 ;
V_126 = F_288 ( F_121 ( V_121 -> V_126 ) , F_121 ( V_40 ) ) ;
for ( V_175 = 0 ; V_175 < V_57 ; V_175 ++ )
if ( F_264 ( V_40 [ V_175 ] ) && ! F_169 ( V_40 [ V_175 ] ) ) {
V_105 = F_258 ( V_40 [ V_175 ] . V_40 ) ;
V_126 = F_288 ( V_126 , V_105 ) ;
}
return V_126 ;
}
void T_12 F_270 ( T_7 * V_39 , unsigned long V_174 )
{
T_2 * V_238 ;
V_238 = F_259 ( V_39 [ V_235 ] . V_39 ) ;
V_201 = F_290 ( V_238 ) ;
V_202 = V_121 -> V_127 * V_107 ;
V_234 =
F_263 ( sizeof( T_2 ) * V_57 , V_107 ) ;
V_181 = F_120 ( V_201 + V_202 + 512 * 1024 ) ;
F_271 ( V_234 , V_238 ) ;
F_262 ( V_234 , V_174 ) ;
F_271 ( V_232 , V_39 ) ;
V_232 [ V_235 ] =
F_188 ( F_121 ( V_234 ) | V_31 ) ;
F_261 ( V_234 , V_78 ) ;
F_261 ( V_232 , V_78 ) ;
F_261 ( V_239 , V_78 ) ;
F_159 ( V_87 , F_120 ( F_121 ( V_39 ) ) ) ;
F_159 ( V_84 ,
F_120 ( F_121 ( V_232 ) ) ) ;
F_221 ( F_121 ( V_232 ) ) ;
F_274 ( V_201 , V_202 ) ;
}
void T_12 F_291 ( void )
{
T_15 V_105 ;
F_274 ( F_121 ( V_121 ) , V_107 ) ;
if ( V_121 -> V_240 ) {
V_105 = F_237 ( F_44 ( V_121 -> V_240 ) ) ;
F_274 ( V_105 , V_107 ) ;
}
if ( ! F_292 () ) {
V_105 = F_237 ( F_44 ( V_121 -> V_241 . V_242 . V_22 ) ) ;
F_274 ( V_105 , V_107 ) ;
}
}
void T_12 F_293 ( void )
{
if ( F_294 ( V_201 , V_202 ) ) {
F_286 ( L_2 ) ;
F_5 () ;
}
}
static void F_295 ( unsigned V_243 , T_15 V_244 , T_3 V_165 )
{
T_1 V_2 ;
V_244 >>= V_33 ;
switch ( V_243 ) {
case V_245 ... V_246 :
case V_247 :
#ifdef F_231
case V_248 :
# ifdef F_296
case V_249 ... V_250 :
# endif
#elif F_297 ( F_226 )
case V_251 :
#endif
case V_252 :
case V_253 :
case V_254 ... V_255 :
V_2 = F_114 ( V_244 , V_165 ) ;
break;
#ifdef F_298
case V_256 :
V_2 = F_114 ( F_120 ( F_121 ( V_257 ) ) , V_88 ) ;
break;
#endif
#ifdef F_299
case V_258 ... V_259 :
V_2 = F_114 ( F_120 ( F_121 ( V_257 ) ) , V_88 ) ;
break;
#endif
case V_260 :
V_2 = F_28 ( V_244 , V_165 ) ;
break;
default:
V_2 = F_28 ( V_244 , V_165 ) ;
break;
}
F_300 ( V_243 , V_2 ) ;
#ifdef F_226
if ( V_243 == V_251 ) {
unsigned long V_1 = F_301 ( V_243 ) ;
F_302 ( V_159 , V_1 , V_2 ) ;
}
#endif
}
static void T_12 F_196 ( void )
{
V_236 . F_289 = F_35 ;
V_236 . F_68 = F_24 ;
V_236 . F_177 = F_57 ;
#if V_261 >= 4
V_236 . F_182 = F_80 ;
#endif
V_236 . V_262 = F_246 ;
V_236 . V_263 = F_247 ;
V_236 . V_264 = F_250 ;
V_236 . V_265 = F_251 ;
#if V_261 >= 4
V_236 . V_266 = F_252 ;
V_236 . V_267 = F_253 ;
#endif
V_236 . V_268 = F_303 ( F_50 ) ;
#ifdef F_119
V_236 . V_237 = & F_221 ;
F_130 ( F_9 ( V_159 ) ) ;
#endif
F_131 () ;
}
static void F_304 ( void )
{
F_18 () ;
F_146 () ;
F_305 () ;
F_23 () ;
}
void T_12 F_306 ( void )
{
V_269 . V_270 . V_271 = F_194 ;
V_236 = V_272 ;
memset ( V_257 , 0xff , V_107 ) ;
}
static void F_307 ( unsigned long V_1 , unsigned int V_273 ,
unsigned long * V_274 ,
unsigned long * V_275 )
{
int V_54 ;
struct V_10 V_11 ;
F_19 () ;
for ( V_54 = 0 ; V_54 < ( 1UL << V_273 ) ; V_54 ++ , V_1 += V_107 ) {
V_11 = F_13 ( 0 ) ;
if ( V_274 )
V_274 [ V_54 ] = F_308 ( V_1 ) ;
F_113 ( V_11 . V_14 , V_1 , V_276 , 0 ) ;
F_309 ( F_310 ( V_1 ) , V_36 ) ;
if ( V_275 )
V_275 [ V_54 ] = F_310 ( V_1 ) ;
}
F_22 ( 0 ) ;
}
static void F_311 ( unsigned long V_1 , int V_273 ,
unsigned long * V_277 ,
unsigned long V_278 )
{
unsigned V_54 , V_53 ;
unsigned long V_22 ;
F_19 () ;
V_53 = 1u << V_273 ;
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ , V_1 += V_107 ) {
struct V_10 V_11 ;
unsigned V_23 ;
V_11 = F_13 ( 0 ) ;
if ( V_277 )
V_22 = V_277 [ V_54 ] ;
else
V_22 = V_278 + V_54 ;
if ( V_54 < ( V_53 - 1 ) )
V_23 = 0 ;
else {
if ( V_273 == 0 )
V_23 = V_192 | V_279 ;
else
V_23 = V_79 | V_279 ;
}
F_113 ( V_11 . V_14 , V_1 ,
F_28 ( V_22 , V_88 ) , V_23 ) ;
F_312 ( F_310 ( V_1 ) , V_22 ) ;
}
F_22 ( 0 ) ;
}
static int F_313 ( unsigned long V_280 , unsigned int V_281 ,
unsigned long * V_282 ,
unsigned long V_283 ,
unsigned int V_284 ,
unsigned long * V_285 ,
unsigned int V_286 )
{
long V_287 ;
int V_288 ;
struct V_289 V_290 = {
. V_291 = {
. V_292 = V_280 ,
. V_293 = V_281 ,
. V_294 = V_282 ,
. V_295 = V_15
} ,
. V_296 = {
. V_292 = V_283 ,
. V_293 = V_284 ,
. V_294 = V_285 ,
. V_286 = V_286 ,
. V_295 = V_15
}
} ;
F_97 ( V_280 << V_281 != V_283 << V_284 ) ;
V_287 = F_266 ( V_297 , & V_290 ) ;
V_288 = ( V_290 . V_298 == V_280 ) ;
F_97 ( ! V_288 && ( ( V_290 . V_298 != 0 ) || ( V_287 == 0 ) ) ) ;
F_97 ( V_288 && ( V_287 != 0 ) ) ;
return V_288 ;
}
int F_314 ( T_15 V_299 , unsigned int V_273 ,
unsigned int V_286 ,
T_16 * V_300 )
{
unsigned long * V_274 = V_301 , V_302 ;
unsigned long V_23 ;
int V_288 ;
unsigned long V_303 = ( unsigned long ) F_315 ( V_299 ) ;
if ( F_45 ( V_273 > V_304 ) )
return - V_155 ;
memset ( ( void * ) V_303 , 0 , V_107 << V_273 ) ;
F_316 ( & V_305 , V_23 ) ;
F_307 ( V_303 , V_273 , V_274 , NULL ) ;
V_302 = F_310 ( V_303 ) ;
V_288 = F_313 ( 1UL << V_273 , 0 , V_274 ,
1 , V_273 , & V_302 ,
V_286 ) ;
if ( V_288 )
F_311 ( V_303 , V_273 , NULL , V_302 ) ;
else
F_311 ( V_303 , V_273 , V_274 , 0 ) ;
F_317 ( & V_305 , V_23 ) ;
* V_300 = F_31 ( V_303 ) . V_20 ;
return V_288 ? 0 : - V_155 ;
}
void F_318 ( T_15 V_299 , unsigned int V_273 )
{
unsigned long * V_275 = V_301 , V_306 ;
unsigned long V_23 ;
int V_288 ;
unsigned long V_303 ;
if ( F_45 ( V_273 > V_304 ) )
return;
V_303 = ( unsigned long ) F_315 ( V_299 ) ;
memset ( ( void * ) V_303 , 0 , V_107 << V_273 ) ;
F_316 ( & V_305 , V_23 ) ;
V_306 = F_308 ( V_303 ) ;
F_307 ( V_303 , V_273 , NULL , V_275 ) ;
V_288 = F_313 ( 1 , V_273 , & V_306 , 1UL << V_273 ,
0 , V_275 , 0 ) ;
if ( V_288 )
F_311 ( V_303 , V_273 , V_275 , 0 ) ;
else
F_311 ( V_303 , V_273 , NULL , V_306 ) ;
F_317 ( & V_305 , V_23 ) ;
}
T_15 F_319 ( void )
{
if ( F_320 () )
return F_31 ( V_307 ) . V_20 ;
else
return F_121 ( V_307 ) ;
}
