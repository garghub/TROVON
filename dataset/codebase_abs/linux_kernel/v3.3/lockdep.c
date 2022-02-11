static int F_1 ( void )
{
F_2 ( & V_1 ) ;
if ( ! V_2 ) {
F_3 ( & V_1 ) ;
return 0 ;
}
V_3 -> V_4 ++ ;
return 1 ;
}
static inline int F_4 ( void )
{
if ( V_2 && ! F_5 ( & V_1 ) ) {
return F_6 ( 1 ) ;
}
V_3 -> V_4 -- ;
F_3 ( & V_1 ) ;
return 0 ;
}
static inline int F_7 ( void )
{
int V_5 = F_8 () ;
F_3 ( & V_1 ) ;
return V_5 ;
}
static inline struct V_6 * F_9 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_9 ) {
F_6 ( 1 ) ;
return NULL ;
}
return V_10 + V_8 -> V_9 - 1 ;
}
static inline T_1 F_10 ( void )
{
return F_11 () ;
}
static int F_12 ( unsigned long V_11 [] , unsigned long V_12 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
if ( V_11 [ V_13 ] == 0 ) {
V_11 [ V_13 ] = V_12 ;
break;
}
if ( V_11 [ V_13 ] == V_12 )
break;
}
return V_13 ;
}
static void F_13 ( struct V_15 * V_16 , T_1 time )
{
if ( time > V_16 -> V_17 )
V_16 -> V_17 = time ;
if ( time < V_16 -> V_18 || ! V_16 -> V_19 )
V_16 -> V_18 = time ;
V_16 -> V_20 += time ;
V_16 -> V_19 ++ ;
}
static inline void F_14 ( struct V_15 * V_21 , struct V_15 * V_22 )
{
if ( ! V_21 -> V_19 )
return;
if ( V_21 -> V_17 > V_22 -> V_17 )
V_22 -> V_17 = V_21 -> V_17 ;
if ( V_21 -> V_18 < V_22 -> V_18 || ! V_22 -> V_19 )
V_22 -> V_18 = V_21 -> V_18 ;
V_22 -> V_20 += V_21 -> V_20 ;
V_22 -> V_19 += V_21 -> V_19 ;
}
struct V_23 F_15 ( struct V_6 * V_24 )
{
struct V_23 V_25 ;
int V_26 , V_13 ;
memset ( & V_25 , 0 , sizeof( struct V_23 ) ) ;
F_16 (cpu) {
struct V_23 * V_27 =
& F_17 ( V_28 , V_26 ) [ V_24 - V_10 ] ;
for ( V_13 = 0 ; V_13 < F_18 ( V_25 . V_29 ) ; V_13 ++ )
V_25 . V_29 [ V_13 ] += V_27 -> V_29 [ V_13 ] ;
for ( V_13 = 0 ; V_13 < F_18 ( V_25 . V_30 ) ; V_13 ++ )
V_25 . V_30 [ V_13 ] += V_27 -> V_30 [ V_13 ] ;
F_14 ( & V_27 -> V_31 , & V_25 . V_31 ) ;
F_14 ( & V_27 -> V_32 , & V_25 . V_32 ) ;
F_14 ( & V_27 -> V_33 , & V_25 . V_33 ) ;
F_14 ( & V_27 -> V_34 , & V_25 . V_34 ) ;
for ( V_13 = 0 ; V_13 < F_18 ( V_25 . V_35 ) ; V_13 ++ )
V_25 . V_35 [ V_13 ] += V_27 -> V_35 [ V_13 ] ;
}
return V_25 ;
}
void F_19 ( struct V_6 * V_24 )
{
int V_26 ;
F_16 (cpu) {
struct V_23 * V_36 =
& F_17 ( V_28 , V_26 ) [ V_24 - V_10 ] ;
memset ( V_36 , 0 , sizeof( struct V_23 ) ) ;
}
memset ( V_24 -> V_29 , 0 , sizeof( V_24 -> V_29 ) ) ;
memset ( V_24 -> V_30 , 0 , sizeof( V_24 -> V_30 ) ) ;
}
static struct V_23 * F_20 ( struct V_6 * V_24 )
{
return & F_21 ( V_28 ) [ V_24 - V_10 ] ;
}
static void F_22 ( struct V_23 * V_25 )
{
F_23 ( V_28 ) ;
}
static void F_24 ( struct V_7 * V_8 )
{
struct V_23 * V_25 ;
T_1 V_37 ;
if ( ! V_38 )
return;
V_37 = F_10 () - V_8 -> V_39 ;
V_25 = F_20 ( F_9 ( V_8 ) ) ;
if ( V_8 -> V_40 )
F_13 ( & V_25 -> V_33 , V_37 ) ;
else
F_13 ( & V_25 -> V_34 , V_37 ) ;
F_22 ( V_25 ) ;
}
static inline void F_24 ( struct V_7 * V_8 )
{
}
void F_25 ( void )
{
V_3 -> V_4 ++ ;
}
void F_26 ( void )
{
V_3 -> V_4 -- ;
}
static int F_27 ( struct V_6 * V_24 )
{
#if 0
if (class->name_version == 1 &&
!strcmp(class->name, "lockname"))
return 1;
if (class->name_version == 1 &&
!strcmp(class->name, "&struct->lockfield"))
return 1;
#endif
return 0 ;
}
static int F_28 ( struct V_6 * V_24 )
{
#if V_41
return F_27 ( V_24 ) ;
#endif
return 0 ;
}
static int F_29 ( struct V_42 * V_43 )
{
V_43 -> V_44 = 0 ;
V_43 -> V_45 = V_46 - V_47 ;
V_43 -> V_48 = V_42 + V_47 ;
V_43 -> V_49 = 3 ;
F_30 ( V_43 ) ;
if ( V_43 -> V_44 != 0 &&
V_43 -> V_48 [ V_43 -> V_44 - 1 ] == V_50 )
V_43 -> V_44 -- ;
V_43 -> V_45 = V_43 -> V_44 ;
V_47 += V_43 -> V_44 ;
if ( V_47 >= V_46 - 1 ) {
if ( ! F_7 () )
return 0 ;
F_31 ( L_1 ) ;
F_31 ( L_2 ) ;
F_32 () ;
return 0 ;
}
return 1 ;
}
const char * F_33 ( struct V_51 * V_52 , char * V_53 )
{
return F_34 ( ( unsigned long ) V_52 , NULL , NULL , NULL , V_53 ) ;
}
static inline unsigned long F_35 ( enum V_54 V_55 )
{
return 1UL << V_55 ;
}
static char F_36 ( struct V_6 * V_24 , enum V_54 V_55 )
{
char V_56 = '.' ;
if ( V_24 -> V_57 & F_35 ( V_55 + 2 ) )
V_56 = '+' ;
if ( V_24 -> V_57 & F_35 ( V_55 ) ) {
V_56 = '-' ;
if ( V_24 -> V_57 & F_35 ( V_55 + 2 ) )
V_56 = '?' ;
}
return V_56 ;
}
void F_37 ( struct V_6 * V_24 , char V_58 [ V_59 ] )
{
int V_13 = 0 ;
#define F_38 ( T_2 ) \
usage[i++] = get_usage_char(class, LOCK_USED_IN_##__STATE); \
usage[i++] = get_usage_char(class, LOCK_USED_IN_##__STATE##_READ);
#include "lockdep_states.h"
#undef F_38
V_58 [ V_13 ] = '\0' ;
}
static void F_39 ( struct V_6 * V_24 )
{
char V_53 [ V_60 ] ;
const char * V_61 ;
V_61 = V_24 -> V_61 ;
if ( ! V_61 ) {
V_61 = F_33 ( V_24 -> V_52 , V_53 ) ;
F_31 ( L_3 , V_61 ) ;
} else {
F_31 ( L_3 , V_61 ) ;
if ( V_24 -> V_62 > 1 )
F_31 ( L_4 , V_24 -> V_62 ) ;
if ( V_24 -> V_63 )
F_31 ( L_5 , V_24 -> V_63 ) ;
}
}
static void F_40 ( struct V_6 * V_24 )
{
char V_58 [ V_59 ] ;
F_37 ( V_24 , V_58 ) ;
F_31 ( L_6 ) ;
F_39 ( V_24 ) ;
F_31 ( L_7 , V_58 ) ;
}
static void F_41 ( struct V_64 * V_65 )
{
const char * V_61 ;
char V_53 [ V_60 ] ;
V_61 = V_65 -> V_61 ;
if ( ! V_61 )
V_61 = F_33 ( V_65 -> V_52 -> V_66 , V_53 ) ;
F_31 ( L_3 , V_61 ) ;
}
static void F_42 ( struct V_7 * V_8 )
{
F_40 ( F_9 ( V_8 ) ) ;
F_31 ( L_8 ) ;
F_43 ( V_8 -> V_67 ) ;
}
static void F_44 ( struct V_68 * V_69 )
{
int V_13 , V_70 = V_69 -> V_71 ;
if ( ! V_70 ) {
F_31 ( L_9 , V_69 -> V_72 , F_45 ( V_69 ) ) ;
return;
}
F_31 ( L_10 ,
V_70 , V_70 > 1 ? L_11 : L_12 , V_69 -> V_72 , F_45 ( V_69 ) ) ;
for ( V_13 = 0 ; V_13 < V_70 ; V_13 ++ ) {
F_31 ( L_13 , V_13 ) ;
F_42 ( V_69 -> V_73 + V_13 ) ;
}
}
static void F_46 ( void )
{
F_31 ( L_14 , F_47 () -> V_74 ,
( int ) strcspn ( F_47 () -> V_75 , L_15 ) ,
F_47 () -> V_75 ,
F_48 () ) ;
}
static int F_49 ( struct V_6 * V_24 )
{
#if V_76
return F_27 ( V_24 ) ;
#endif
return 0 ;
}
static int F_50 ( void * V_77 )
{
unsigned long V_78 = ( unsigned long ) & V_79 ,
V_80 = ( unsigned long ) & V_81 ,
V_82 = ( unsigned long ) V_77 ;
if ( ( V_82 >= V_78 ) && ( V_82 < V_80 ) )
return 1 ;
if ( F_51 ( V_82 ) )
return 1 ;
if ( F_52 ( V_82 ) )
return 1 ;
return F_53 ( V_82 ) || F_54 ( V_82 ) ;
}
static int F_55 ( struct V_6 * V_83 )
{
struct V_6 * V_24 ;
int V_84 = 0 ;
if ( ! V_83 -> V_61 )
return 0 ;
F_56 (class, &all_lock_classes, lock_entry) {
if ( V_83 -> V_52 - V_83 -> V_63 == V_24 -> V_52 )
return V_24 -> V_62 ;
if ( V_24 -> V_61 && ! strcmp ( V_24 -> V_61 , V_83 -> V_61 ) )
V_84 = V_17 ( V_84 , V_24 -> V_62 ) ;
}
return V_84 + 1 ;
}
static inline struct V_6 *
F_57 ( struct V_64 * V_65 , unsigned int V_63 )
{
struct V_51 * V_52 ;
struct V_85 * V_86 ;
struct V_6 * V_24 ;
#ifdef F_58
if ( F_59 ( ! V_87 ) ) {
F_60 () ;
V_88 = 1 ;
V_89 = V_65 -> V_61 ;
F_30 ( & V_90 ) ;
}
#endif
if ( F_59 ( V_63 >= V_91 ) ) {
F_8 () ;
F_31 ( V_92
L_16 , V_63 ) ;
F_31 ( V_92
L_2 ) ;
F_32 () ;
return NULL ;
}
if ( F_59 ( ! V_65 -> V_52 ) )
V_65 -> V_52 = ( void * ) V_65 ;
F_61 ( sizeof( struct V_93 ) >
sizeof( struct V_64 ) ) ;
V_52 = V_65 -> V_52 -> V_66 + V_63 ;
V_86 = F_62 ( V_52 ) ;
F_56 (class, hash_head, hash_entry) {
if ( V_24 -> V_52 == V_52 ) {
F_63 ( V_24 -> V_61 != V_65 -> V_61 ) ;
return V_24 ;
}
}
return NULL ;
}
static inline struct V_6 *
F_64 ( struct V_64 * V_65 , unsigned int V_63 , int V_94 )
{
struct V_51 * V_52 ;
struct V_85 * V_86 ;
struct V_6 * V_24 ;
unsigned long V_95 ;
V_24 = F_57 ( V_65 , V_63 ) ;
if ( F_65 ( V_24 ) )
goto V_96;
if ( ! F_50 ( V_65 -> V_52 ) ) {
F_8 () ;
F_31 ( L_17 ) ;
F_31 ( L_18 ) ;
F_31 ( L_2 ) ;
F_32 () ;
return NULL ;
}
V_52 = V_65 -> V_52 -> V_66 + V_63 ;
V_86 = F_62 ( V_52 ) ;
F_66 ( V_95 ) ;
if ( ! F_1 () ) {
F_67 ( V_95 ) ;
return NULL ;
}
F_56 (class, hash_head, hash_entry)
if ( V_24 -> V_52 == V_52 )
goto V_97;
if ( V_98 >= V_99 ) {
if ( ! F_7 () ) {
F_67 ( V_95 ) ;
return NULL ;
}
F_67 ( V_95 ) ;
F_31 ( L_19 ) ;
F_31 ( L_2 ) ;
F_32 () ;
return NULL ;
}
V_24 = V_10 + V_98 ++ ;
F_68 ( V_100 ) ;
V_24 -> V_52 = V_52 ;
V_24 -> V_61 = V_65 -> V_61 ;
V_24 -> V_63 = V_63 ;
F_69 ( & V_24 -> V_101 ) ;
F_69 ( & V_24 -> V_102 ) ;
F_69 ( & V_24 -> V_103 ) ;
V_24 -> V_62 = F_55 ( V_24 ) ;
F_70 ( & V_24 -> V_104 , V_86 ) ;
F_70 ( & V_24 -> V_101 , & V_105 ) ;
if ( F_28 ( V_24 ) ) {
F_4 () ;
F_67 ( V_95 ) ;
F_31 ( L_20 , V_24 -> V_52 , V_24 -> V_61 ) ;
if ( V_24 -> V_62 > 1 )
F_31 ( L_4 , V_24 -> V_62 ) ;
F_31 ( L_21 ) ;
F_32 () ;
F_66 ( V_95 ) ;
if ( ! F_1 () ) {
F_67 ( V_95 ) ;
return NULL ;
}
}
V_97:
F_4 () ;
F_67 ( V_95 ) ;
V_96:
if ( ! V_63 || V_94 )
V_65 -> V_106 [ 0 ] = V_24 ;
else if ( V_63 < V_107 )
V_65 -> V_106 [ V_63 ] = V_24 ;
if ( F_6 ( V_24 -> V_63 != V_63 ) )
return NULL ;
return V_24 ;
}
static struct V_108 * F_71 ( void )
{
if ( V_109 >= V_110 ) {
if ( ! F_7 () )
return NULL ;
F_31 ( L_22 ) ;
F_31 ( L_2 ) ;
F_32 () ;
return NULL ;
}
return V_111 + V_109 ++ ;
}
static int F_72 ( struct V_6 * V_24 , struct V_6 * V_112 ,
struct V_85 * V_113 , unsigned long V_12 ,
int V_114 , struct V_42 * V_43 )
{
struct V_108 * V_115 ;
V_115 = F_71 () ;
if ( ! V_115 )
return 0 ;
V_115 -> V_24 = V_112 ;
V_115 -> V_114 = V_114 ;
V_115 -> V_43 = * V_43 ;
F_70 ( & V_115 -> V_115 , V_113 ) ;
return 1 ;
}
static inline void F_73 ( struct V_116 * V_117 )
{
V_117 -> V_118 = V_117 -> V_119 = 0 ;
V_120 ++ ;
}
static inline int F_74 ( struct V_116 * V_117 )
{
return ( V_117 -> V_118 == V_117 -> V_119 ) ;
}
static inline int F_75 ( struct V_116 * V_117 )
{
return ( ( V_117 -> V_119 + 1 ) & V_121 ) == V_117 -> V_118 ;
}
static inline int F_76 ( struct V_116 * V_117 , unsigned long V_122 )
{
if ( F_75 ( V_117 ) )
return - 1 ;
V_117 -> V_123 [ V_117 -> V_119 ] = V_122 ;
V_117 -> V_119 = ( V_117 -> V_119 + 1 ) & V_121 ;
return 0 ;
}
static inline int F_77 ( struct V_116 * V_117 , unsigned long * V_122 )
{
if ( F_74 ( V_117 ) )
return - 1 ;
* V_122 = V_117 -> V_123 [ V_117 -> V_118 ] ;
V_117 -> V_118 = ( V_117 -> V_118 + 1 ) & V_121 ;
return 0 ;
}
static inline unsigned int F_78 ( struct V_116 * V_117 )
{
return ( V_117 -> V_119 - V_117 -> V_118 ) & V_121 ;
}
static inline void F_79 ( struct V_108 * V_65 ,
struct V_108 * V_124 )
{
unsigned long V_19 ;
V_19 = V_65 - V_111 ;
F_80 ( V_19 >= V_109 ) ;
V_65 -> V_124 = V_124 ;
V_65 -> V_24 -> V_125 = V_120 ;
}
static inline unsigned long F_81 ( struct V_108 * V_65 )
{
unsigned long V_19 ;
V_19 = V_65 - V_111 ;
F_80 ( V_19 >= V_109 ) ;
return V_65 -> V_24 -> V_125 == V_120 ;
}
static inline struct V_108 * F_82 ( struct V_108 * V_126 )
{
return V_126 -> V_124 ;
}
static inline int F_83 ( struct V_108 * V_126 )
{
int V_70 = 0 ;
struct V_108 * V_124 ;
while ( ( V_124 = F_82 ( V_126 ) ) ) {
V_126 = V_124 ;
V_70 ++ ;
}
return V_70 ;
}
static int F_84 ( struct V_108 * V_127 ,
void * V_128 ,
int (* F_85)( struct V_108 * V_115 , void * V_128 ) ,
struct V_108 * * V_129 ,
int V_130 )
{
struct V_108 * V_115 ;
struct V_85 * V_113 ;
struct V_116 * V_117 = & V_131 ;
int V_5 = 1 ;
if ( F_85 ( V_127 , V_128 ) ) {
* V_129 = V_127 ;
V_5 = 0 ;
goto exit;
}
if ( V_130 )
V_113 = & V_127 -> V_24 -> V_103 ;
else
V_113 = & V_127 -> V_24 -> V_102 ;
if ( F_86 ( V_113 ) )
goto exit;
F_73 ( V_117 ) ;
F_76 ( V_117 , ( unsigned long ) V_127 ) ;
while ( ! F_74 ( V_117 ) ) {
struct V_108 * V_65 ;
F_77 ( V_117 , ( unsigned long * ) & V_65 ) ;
if ( ! V_65 -> V_24 ) {
V_5 = - 2 ;
goto exit;
}
if ( V_130 )
V_113 = & V_65 -> V_24 -> V_103 ;
else
V_113 = & V_65 -> V_24 -> V_102 ;
F_56 (entry, head, entry) {
if ( ! F_81 ( V_115 ) ) {
unsigned int V_132 ;
F_79 ( V_115 , V_65 ) ;
if ( F_85 ( V_115 , V_128 ) ) {
* V_129 = V_115 ;
V_5 = 0 ;
goto exit;
}
if ( F_76 ( V_117 , ( unsigned long ) V_115 ) ) {
V_5 = - 1 ;
goto exit;
}
V_132 = F_78 ( V_117 ) ;
if ( V_133 < V_132 )
V_133 = V_132 ;
}
}
}
exit:
return V_5 ;
}
static inline int F_87 ( struct V_108 * V_134 ,
void * V_128 ,
int (* F_85)( struct V_108 * V_115 , void * V_128 ) ,
struct V_108 * * V_129 )
{
return F_84 ( V_134 , V_128 , F_85 , V_129 , 1 ) ;
}
static inline int F_88 ( struct V_108 * V_134 ,
void * V_128 ,
int (* F_85)( struct V_108 * V_115 , void * V_128 ) ,
struct V_108 * * V_129 )
{
return F_84 ( V_134 , V_128 , F_85 , V_129 , 0 ) ;
}
static T_3 int
F_89 ( struct V_108 * V_135 , int V_70 )
{
if ( V_136 )
return 0 ;
F_31 ( L_23 , V_70 ) ;
F_40 ( V_135 -> V_24 ) ;
F_31 ( L_24 ) ;
F_90 ( & V_135 -> V_43 , 6 ) ;
return 0 ;
}
static void
F_91 ( struct V_7 * V_21 ,
struct V_7 * V_137 ,
struct V_108 * V_138 )
{
struct V_6 * V_139 = F_9 ( V_21 ) ;
struct V_6 * V_135 = F_9 ( V_137 ) ;
struct V_6 * V_124 = V_138 -> V_24 ;
if ( V_124 != V_139 ) {
F_31 ( L_25 ) ;
F_39 ( V_139 ) ;
F_31 ( L_26 ) ;
F_39 ( V_124 ) ;
F_31 ( L_26 ) ;
F_39 ( V_135 ) ;
F_31 ( L_27 ) ;
}
F_31 ( L_28 ) ;
F_31 ( L_29 ) ;
F_31 ( L_30 ) ;
F_31 ( L_31 ) ;
F_39 ( V_135 ) ;
F_31 ( L_32 ) ;
F_31 ( L_33 ) ;
F_39 ( V_124 ) ;
F_31 ( L_32 ) ;
F_31 ( L_33 ) ;
F_39 ( V_135 ) ;
F_31 ( L_32 ) ;
F_31 ( L_31 ) ;
F_39 ( V_139 ) ;
F_31 ( L_32 ) ;
F_31 ( L_34 ) ;
}
static T_3 int
F_92 ( struct V_108 * V_115 , unsigned int V_70 ,
struct V_7 * V_140 ,
struct V_7 * V_141 )
{
struct V_68 * V_69 = V_3 ;
if ( V_136 )
return 0 ;
F_31 ( L_21 ) ;
F_31 ( L_35 ) ;
F_31 ( L_36 ) ;
F_46 () ;
F_31 ( L_37 ) ;
F_31 ( L_38 ,
V_69 -> V_72 , F_45 ( V_69 ) ) ;
F_42 ( V_140 ) ;
F_31 ( L_39 ) ;
F_42 ( V_141 ) ;
F_31 ( L_40 ) ;
F_31 ( L_41 ) ;
F_89 ( V_115 , V_70 ) ;
return 0 ;
}
static inline int F_93 ( struct V_108 * V_115 , void * V_128 )
{
return V_115 -> V_24 == V_128 ;
}
static T_3 int F_94 ( struct V_108 * V_112 ,
struct V_108 * V_135 ,
struct V_7 * V_140 ,
struct V_7 * V_141 )
{
struct V_68 * V_69 = V_3 ;
struct V_108 * V_124 ;
struct V_108 * V_142 ;
int V_70 ;
if ( ! F_7 () || V_136 )
return 0 ;
if ( ! F_29 ( & V_112 -> V_43 ) )
return 0 ;
V_70 = F_83 ( V_135 ) ;
F_92 ( V_135 , V_70 , V_140 , V_141 ) ;
V_124 = F_82 ( V_135 ) ;
V_142 = V_124 ;
while ( V_124 ) {
F_89 ( V_124 , -- V_70 ) ;
V_124 = F_82 ( V_124 ) ;
}
F_31 ( L_42 ) ;
F_91 ( V_140 , V_141 ,
V_142 ) ;
F_44 ( V_69 ) ;
F_31 ( L_43 ) ;
F_32 () ;
return 0 ;
}
static T_3 int F_95 ( int V_5 )
{
if ( ! F_7 () )
return 0 ;
F_96 ( 1 , L_44 , V_5 ) ;
return 0 ;
}
static int F_97 ( struct V_108 * V_115 , void * V_128 )
{
( * ( unsigned long * ) V_128 ) ++ ;
return 0 ;
}
unsigned long F_98 ( struct V_108 * V_112 )
{
unsigned long V_84 = 0 ;
struct V_108 * V_143 ( V_129 ) ;
F_87 ( V_112 , ( void * ) & V_84 , F_97 , & V_129 ) ;
return V_84 ;
}
unsigned long F_99 ( struct V_6 * V_24 )
{
unsigned long V_5 , V_95 ;
struct V_108 V_112 ;
V_112 . V_124 = NULL ;
V_112 . V_24 = V_24 ;
F_100 ( V_95 ) ;
F_2 ( & V_1 ) ;
V_5 = F_98 ( & V_112 ) ;
F_3 ( & V_1 ) ;
F_101 ( V_95 ) ;
return V_5 ;
}
unsigned long F_102 ( struct V_108 * V_112 )
{
unsigned long V_84 = 0 ;
struct V_108 * V_143 ( V_129 ) ;
F_88 ( V_112 , ( void * ) & V_84 , F_97 , & V_129 ) ;
return V_84 ;
}
unsigned long F_103 ( struct V_6 * V_24 )
{
unsigned long V_5 , V_95 ;
struct V_108 V_112 ;
V_112 . V_124 = NULL ;
V_112 . V_24 = V_24 ;
F_100 ( V_95 ) ;
F_2 ( & V_1 ) ;
V_5 = F_102 ( & V_112 ) ;
F_3 ( & V_1 ) ;
F_101 ( V_95 ) ;
return V_5 ;
}
static T_3 int
F_104 ( struct V_108 * V_144 , struct V_6 * V_135 ,
struct V_108 * * V_129 )
{
int V_145 ;
F_68 ( V_146 ) ;
V_145 = F_87 ( V_144 , V_135 , F_93 , V_129 ) ;
return V_145 ;
}
static inline int F_105 ( struct V_108 * V_115 , void * V_55 )
{
return V_115 -> V_24 -> V_57 & ( 1 << (enum V_54 ) V_55 ) ;
}
static int
F_106 ( struct V_108 * V_144 , enum V_54 V_55 ,
struct V_108 * * V_129 )
{
int V_145 ;
F_68 ( V_147 ) ;
V_145 = F_87 ( V_144 , ( void * ) V_55 , F_105 , V_129 ) ;
return V_145 ;
}
static int
F_107 ( struct V_108 * V_144 , enum V_54 V_55 ,
struct V_108 * * V_129 )
{
int V_145 ;
F_68 ( V_148 ) ;
V_145 = F_88 ( V_144 , ( void * ) V_55 , F_105 , V_129 ) ;
return V_145 ;
}
static void F_108 ( struct V_6 * V_24 , int V_70 )
{
int V_55 ;
F_31 ( L_45 , V_70 , L_12 ) ;
F_40 ( V_24 ) ;
F_31 ( L_46 , V_24 -> V_149 ) ;
F_31 ( L_47 ) ;
for ( V_55 = 0 ; V_55 < V_150 ; V_55 ++ ) {
if ( V_24 -> V_57 & ( 1 << V_55 ) ) {
int V_151 = V_70 ;
V_151 += F_31 ( L_48 , V_70 , L_12 , V_152 [ V_55 ] ) ;
V_151 += F_31 ( L_49 ) ;
F_90 ( V_24 -> V_153 + V_55 , V_151 ) ;
}
}
F_31 ( L_50 , V_70 , L_12 ) ;
F_31 ( L_51 , V_70 , L_12 ) ;
F_43 ( ( unsigned long ) V_24 -> V_52 ) ;
}
static void T_4
F_109 ( struct V_108 * V_154 ,
struct V_108 * V_144 )
{
struct V_108 * V_115 = V_154 ;
int V_70 ;
V_70 = F_83 ( V_154 ) ;
do {
F_108 ( V_115 -> V_24 , V_70 ) ;
F_31 ( L_52 , V_70 , L_12 ) ;
F_90 ( & V_115 -> V_43 , 2 ) ;
F_31 ( L_21 ) ;
if ( V_70 == 0 && ( V_115 != V_144 ) ) {
F_31 ( L_53 , V_155 ) ;
break;
}
V_115 = F_82 ( V_115 ) ;
V_70 -- ;
} while ( V_115 && ( V_70 >= 0 ) );
return;
}
static void
F_110 ( struct V_108 * V_156 ,
struct V_108 * V_157 ,
struct V_6 * V_158 ,
struct V_6 * V_159 )
{
struct V_6 * V_160 = V_156 -> V_24 ;
struct V_6 * V_161 = V_157 -> V_24 ;
struct V_6 * V_162 = V_158 ;
if ( V_162 == V_160 )
V_162 = V_159 ;
if ( V_162 != V_161 ) {
F_31 ( L_25 ) ;
F_39 ( V_160 ) ;
F_31 ( L_26 ) ;
F_39 ( V_162 ) ;
F_31 ( L_26 ) ;
F_39 ( V_161 ) ;
F_31 ( L_27 ) ;
}
F_31 ( L_54 ) ;
F_31 ( L_29 ) ;
F_31 ( L_30 ) ;
F_31 ( L_31 ) ;
F_39 ( V_161 ) ;
F_31 ( L_32 ) ;
F_31 ( L_55 ) ;
F_31 ( L_33 ) ;
F_39 ( V_160 ) ;
F_31 ( L_32 ) ;
F_31 ( L_33 ) ;
F_39 ( V_162 ) ;
F_31 ( L_32 ) ;
F_31 ( L_56 ) ;
F_31 ( L_57 ) ;
F_39 ( V_160 ) ;
F_31 ( L_32 ) ;
F_31 ( L_34 ) ;
}
static int
F_111 ( struct V_68 * V_69 ,
struct V_108 * V_163 ,
struct V_108 * V_164 ,
struct V_108 * V_165 ,
struct V_108 * V_166 ,
struct V_7 * V_167 ,
struct V_7 * V_168 ,
enum V_54 V_169 ,
enum V_54 V_170 ,
const char * V_171 )
{
if ( ! F_7 () || V_136 )
return 0 ;
F_31 ( L_21 ) ;
F_31 ( L_35 ) ;
F_31 ( L_58 ,
V_171 , V_171 ) ;
F_46 () ;
F_31 ( L_59 ) ;
F_31 ( L_60 ,
V_69 -> V_72 , F_45 ( V_69 ) ,
V_69 -> V_172 , F_112 () >> V_173 ,
V_69 -> V_174 , F_113 () >> V_175 ,
V_69 -> V_176 ,
V_69 -> V_177 ) ;
F_42 ( V_168 ) ;
F_31 ( L_61 ) ;
F_42 ( V_167 ) ;
F_31 ( L_62 ) ;
F_40 ( F_9 ( V_167 ) ) ;
F_31 ( L_63 ) ;
F_40 ( F_9 ( V_168 ) ) ;
F_31 ( L_21 ) ;
F_31 ( L_64 ,
V_171 ) ;
F_40 ( V_165 -> V_24 ) ;
F_31 ( L_65 , V_171 ) ;
F_90 ( V_165 -> V_24 -> V_153 + V_169 , 1 ) ;
F_31 ( L_66 , V_171 ) ;
F_40 ( V_166 -> V_24 ) ;
F_31 ( L_67 , V_171 ) ;
F_31 ( L_68 ) ;
F_90 ( V_166 -> V_24 -> V_153 + V_170 , 1 ) ;
F_31 ( L_42 ) ;
F_110 ( V_165 , V_166 ,
F_9 ( V_167 ) , F_9 ( V_168 ) ) ;
F_44 ( V_69 ) ;
F_31 ( L_69 , V_171 ) ;
F_31 ( L_70 ) ;
if ( ! F_29 ( & V_163 -> V_43 ) )
return 0 ;
F_109 ( V_165 , V_163 ) ;
F_31 ( L_71 ) ;
F_31 ( L_72 , V_171 ) ;
if ( ! F_29 ( & V_164 -> V_43 ) )
return 0 ;
F_109 ( V_166 , V_164 ) ;
F_31 ( L_43 ) ;
F_32 () ;
return 0 ;
}
static int
F_114 ( struct V_68 * V_69 , struct V_7 * V_167 ,
struct V_7 * V_168 , enum V_54 V_178 ,
enum V_54 V_179 , const char * V_171 )
{
int V_5 ;
struct V_108 V_112 , V_180 ;
struct V_108 * V_143 ( V_129 ) ;
struct V_108 * V_143 ( V_181 ) ;
V_112 . V_124 = NULL ;
V_112 . V_24 = F_9 ( V_167 ) ;
V_5 = F_107 ( & V_112 , V_178 , & V_129 ) ;
if ( V_5 < 0 )
return F_95 ( V_5 ) ;
if ( V_5 == 1 )
return V_5 ;
V_180 . V_124 = NULL ;
V_180 . V_24 = F_9 ( V_168 ) ;
V_5 = F_106 ( & V_180 , V_179 , & V_181 ) ;
if ( V_5 < 0 )
return F_95 ( V_5 ) ;
if ( V_5 == 1 )
return V_5 ;
return F_111 ( V_69 , & V_112 , & V_180 ,
V_129 , V_181 ,
V_167 , V_168 ,
V_178 , V_179 , V_171 ) ;
}
static inline const char * F_115 ( enum V_54 V_55 )
{
return ( V_55 & 1 ) ? V_182 [ V_55 >> 2 ] : V_183 [ V_55 >> 2 ] ;
}
static int F_116 ( int V_184 )
{
int V_185 = V_184 & ~ 3 ;
int V_186 = V_184 & 2 ;
return V_185 | ( V_186 ^ 2 ) ;
}
static int F_117 ( struct V_68 * V_69 , struct V_7 * V_167 ,
struct V_7 * V_168 , enum V_54 V_55 )
{
if ( ! F_114 ( V_69 , V_167 , V_168 , V_55 ,
F_116 ( V_55 ) , F_115 ( V_55 ) ) )
return 0 ;
V_55 ++ ;
if ( ! F_114 ( V_69 , V_167 , V_168 , V_55 ,
F_116 ( V_55 ) , F_115 ( V_55 ) ) )
return 0 ;
return 1 ;
}
static int
F_118 ( struct V_68 * V_69 , struct V_7 * V_167 ,
struct V_7 * V_168 )
{
#define F_38 ( T_2 ) \
if (!check_irq_usage(curr, prev, next, LOCK_USED_IN_##__STATE)) \
return 0;
#include "lockdep_states.h"
#undef F_38
return 1 ;
}
static void F_119 ( void )
{
if ( V_3 -> V_172 )
V_187 ++ ;
else {
if ( V_3 -> V_174 )
V_188 ++ ;
else
V_189 ++ ;
}
}
static inline int
F_118 ( struct V_68 * V_69 , struct V_7 * V_167 ,
struct V_7 * V_168 )
{
return 1 ;
}
static inline void F_119 ( void )
{
V_189 ++ ;
}
static void
F_120 ( struct V_7 * V_190 ,
struct V_7 * V_191 )
{
struct V_6 * V_168 = F_9 ( V_190 ) ;
struct V_6 * V_167 = F_9 ( V_191 ) ;
F_31 ( L_28 ) ;
F_31 ( L_73 ) ;
F_31 ( L_74 ) ;
F_31 ( L_31 ) ;
F_39 ( V_167 ) ;
F_31 ( L_32 ) ;
F_31 ( L_31 ) ;
F_39 ( V_168 ) ;
F_31 ( L_32 ) ;
F_31 ( L_34 ) ;
F_31 ( L_75 ) ;
}
static int
F_121 ( struct V_68 * V_69 , struct V_7 * V_167 ,
struct V_7 * V_168 )
{
if ( ! F_7 () || V_136 )
return 0 ;
F_31 ( L_21 ) ;
F_31 ( L_76 ) ;
F_31 ( L_77 ) ;
F_46 () ;
F_31 ( L_78 ) ;
F_31 ( L_38 ,
V_69 -> V_72 , F_45 ( V_69 ) ) ;
F_42 ( V_168 ) ;
F_31 ( L_39 ) ;
F_42 ( V_167 ) ;
F_31 ( L_79 ) ;
F_120 ( V_168 , V_167 ) ;
F_44 ( V_69 ) ;
F_31 ( L_43 ) ;
F_32 () ;
return 0 ;
}
static int
F_122 ( struct V_68 * V_69 , struct V_7 * V_168 ,
struct V_64 * V_192 , int V_40 )
{
struct V_7 * V_167 ;
struct V_7 * V_193 = NULL ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_69 -> V_71 ; V_13 ++ ) {
V_167 = V_69 -> V_73 + V_13 ;
if ( V_167 -> V_194 == V_168 -> V_195 )
V_193 = V_167 ;
if ( F_9 ( V_167 ) != F_9 ( V_168 ) )
continue;
if ( ( V_40 == 2 ) && V_167 -> V_40 )
return 2 ;
if ( V_193 )
return 2 ;
return F_121 ( V_69 , V_167 , V_168 ) ;
}
return 1 ;
}
static int
F_123 ( struct V_68 * V_69 , struct V_7 * V_167 ,
struct V_7 * V_168 , int V_114 , int V_196 )
{
struct V_108 * V_115 ;
int V_5 ;
struct V_108 V_112 ;
struct V_108 * V_143 ( V_129 ) ;
static struct V_42 V_43 ;
V_112 . V_24 = F_9 ( V_168 ) ;
V_112 . V_124 = NULL ;
V_5 = F_104 ( & V_112 , F_9 ( V_167 ) , & V_129 ) ;
if ( F_59 ( ! V_5 ) )
return F_94 ( & V_112 , V_129 , V_168 , V_167 ) ;
else if ( F_59 ( V_5 < 0 ) )
return F_95 ( V_5 ) ;
if ( ! F_118 ( V_69 , V_167 , V_168 ) )
return 0 ;
if ( V_168 -> V_40 == 2 || V_167 -> V_40 == 2 )
return 1 ;
F_56 (entry, &hlock_class(prev)->locks_after, entry) {
if ( V_115 -> V_24 == F_9 ( V_168 ) ) {
if ( V_114 == 1 )
V_115 -> V_114 = 1 ;
return 2 ;
}
}
if ( ! V_196 && ! F_29 ( & V_43 ) )
return 0 ;
V_5 = F_72 ( F_9 ( V_167 ) , F_9 ( V_168 ) ,
& F_9 ( V_167 ) -> V_103 ,
V_168 -> V_67 , V_114 , & V_43 ) ;
if ( ! V_5 )
return 0 ;
V_5 = F_72 ( F_9 ( V_168 ) , F_9 ( V_167 ) ,
& F_9 ( V_168 ) -> V_102 ,
V_168 -> V_67 , V_114 , & V_43 ) ;
if ( ! V_5 )
return 0 ;
if ( F_28 ( F_9 ( V_167 ) ) || F_28 ( F_9 ( V_168 ) ) ) {
F_4 () ;
F_31 ( L_80 ) ;
F_40 ( F_9 ( V_167 ) ) ;
F_31 ( L_81 ) ;
F_40 ( F_9 ( V_168 ) ) ;
F_31 ( L_21 ) ;
F_32 () ;
return F_1 () ;
}
return 1 ;
}
static int
F_124 ( struct V_68 * V_69 , struct V_7 * V_168 )
{
int V_70 = V_69 -> V_71 ;
int V_196 = 0 ;
struct V_7 * V_8 ;
if ( ! V_70 )
goto V_197;
if ( V_69 -> V_73 [ V_70 ] . V_198 !=
V_69 -> V_73 [ V_70 - 1 ] . V_198 )
goto V_197;
for (; ; ) {
int V_114 = V_69 -> V_71 - V_70 + 1 ;
V_8 = V_69 -> V_73 + V_70 - 1 ;
if ( V_8 -> V_40 != 2 ) {
if ( ! F_123 ( V_69 , V_8 , V_168 ,
V_114 , V_196 ) )
return 0 ;
if ( ! V_8 -> V_199 )
break;
}
V_70 -- ;
if ( ! V_70 )
break;
if ( V_69 -> V_73 [ V_70 ] . V_198 !=
V_69 -> V_73 [ V_70 - 1 ] . V_198 )
break;
V_196 = 1 ;
}
return 1 ;
V_197:
if ( ! F_7 () )
return 0 ;
F_80 ( 1 ) ;
return 0 ;
}
struct V_6 * F_125 ( struct V_200 * V_201 , int V_13 )
{
return V_10 + V_202 [ V_201 -> V_203 + V_13 ] ;
}
static inline int F_126 ( struct V_68 * V_69 ,
struct V_7 * V_8 ,
T_1 V_204 )
{
struct V_6 * V_24 = F_9 ( V_8 ) ;
struct V_85 * V_86 = F_127 ( V_204 ) ;
struct V_200 * V_201 ;
struct V_7 * V_205 , * V_206 ;
int V_13 , V_207 ;
if ( F_6 ( ! F_128 () ) )
return 0 ;
F_56 (chain, hash_head, entry) {
if ( V_201 -> V_204 == V_204 ) {
V_208:
F_68 ( V_209 ) ;
if ( F_49 ( V_24 ) )
F_31 ( L_82
L_83 ,
( unsigned long long ) V_204 ,
V_24 -> V_52 , V_24 -> V_61 ) ;
return 0 ;
}
}
if ( F_49 ( V_24 ) )
F_31 ( L_84 ,
( unsigned long long ) V_204 , V_24 -> V_52 , V_24 -> V_61 ) ;
if ( ! F_1 () )
return 0 ;
F_56 (chain, hash_head, entry) {
if ( V_201 -> V_204 == V_204 ) {
F_4 () ;
goto V_208;
}
}
if ( F_59 ( V_210 >= V_211 ) ) {
if ( ! F_7 () )
return 0 ;
F_31 ( L_85 ) ;
F_31 ( L_2 ) ;
F_32 () ;
return 0 ;
}
V_201 = V_212 + V_210 ++ ;
V_201 -> V_204 = V_204 ;
V_201 -> V_198 = V_8 -> V_198 ;
V_206 = V_8 ;
for ( V_13 = V_69 -> V_71 - 1 ; V_13 >= 0 ; V_13 -- ) {
V_205 = V_69 -> V_73 + V_13 ;
if ( V_205 -> V_198 != V_206 -> V_198 )
break;
V_206 = V_8 ;
}
V_13 ++ ;
V_201 -> V_70 = V_69 -> V_71 + 1 - V_13 ;
if ( F_65 ( V_213 + V_201 -> V_70 <= V_214 ) ) {
V_201 -> V_203 = V_213 ;
V_213 += V_201 -> V_70 ;
for ( V_207 = 0 ; V_207 < V_201 -> V_70 - 1 ; V_207 ++ , V_13 ++ ) {
int V_215 = V_69 -> V_73 [ V_13 ] . V_9 - 1 ;
V_202 [ V_201 -> V_203 + V_207 ] = V_215 ;
}
V_202 [ V_201 -> V_203 + V_207 ] = V_24 - V_10 ;
}
F_70 ( & V_201 -> V_115 , V_86 ) ;
F_68 ( V_216 ) ;
F_119 () ;
return 1 ;
}
static int F_129 ( struct V_68 * V_69 , struct V_64 * V_65 ,
struct V_7 * V_8 , int V_217 , T_1 V_204 )
{
if ( ! V_8 -> V_199 && ( V_8 -> V_218 == 2 ) &&
F_126 ( V_69 , V_8 , V_204 ) ) {
int V_5 = F_122 ( V_69 , V_8 , V_65 , V_8 -> V_40 ) ;
if ( ! V_5 )
return 0 ;
if ( V_5 == 2 )
V_8 -> V_40 = 2 ;
if ( ! V_217 && V_5 != 2 )
if ( ! F_124 ( V_69 , V_8 ) )
return 0 ;
F_4 () ;
} else
if ( F_59 ( ! V_2 ) )
return 0 ;
return 1 ;
}
static inline int F_129 ( struct V_68 * V_69 ,
struct V_64 * V_65 , struct V_7 * V_8 ,
int V_217 , T_1 V_204 )
{
return 1 ;
}
static void F_130 ( struct V_68 * V_69 )
{
#ifdef F_58
struct V_7 * V_8 , * V_219 = NULL ;
unsigned int V_13 , V_220 ;
T_1 V_204 = 0 ;
for ( V_13 = 0 ; V_13 < V_69 -> V_71 ; V_13 ++ ) {
V_8 = V_69 -> V_73 + V_13 ;
if ( V_204 != V_8 -> V_221 ) {
F_8 () ;
F_96 ( 1 , L_86 ,
V_69 -> V_71 , V_13 ,
( unsigned long long ) V_204 ,
( unsigned long long ) V_8 -> V_221 ) ;
return;
}
V_220 = V_8 -> V_9 - 1 ;
if ( F_6 ( V_220 >= V_99 ) )
return;
if ( V_219 && ( V_219 -> V_198 !=
V_8 -> V_198 ) )
V_204 = 0 ;
V_204 = F_131 ( V_204 , V_220 ) ;
V_219 = V_8 ;
}
if ( V_204 != V_69 -> V_222 ) {
F_8 () ;
F_96 ( 1 , L_87 ,
V_69 -> V_71 , V_13 ,
( unsigned long long ) V_204 ,
( unsigned long long ) V_69 -> V_222 ) ;
}
#endif
}
static void
F_132 ( struct V_7 * V_65 )
{
struct V_6 * V_24 = F_9 ( V_65 ) ;
F_31 ( L_28 ) ;
F_31 ( L_73 ) ;
F_31 ( L_74 ) ;
F_31 ( L_31 ) ;
F_39 ( V_24 ) ;
F_31 ( L_32 ) ;
F_31 ( L_56 ) ;
F_31 ( L_57 ) ;
F_39 ( V_24 ) ;
F_31 ( L_32 ) ;
F_31 ( L_34 ) ;
}
static int
F_133 ( struct V_68 * V_69 , struct V_7 * V_112 ,
enum V_54 V_223 , enum V_54 V_184 )
{
if ( ! F_7 () || V_136 )
return 0 ;
F_31 ( L_21 ) ;
F_31 ( L_88 ) ;
F_31 ( L_89 ) ;
F_46 () ;
F_31 ( L_90 ) ;
F_31 ( L_91 ,
V_152 [ V_223 ] , V_152 [ V_184 ] ) ;
F_31 ( L_92 ,
V_69 -> V_72 , F_45 ( V_69 ) ,
F_134 ( V_69 ) , F_112 () >> V_173 ,
F_135 ( V_69 ) , F_113 () >> V_175 ,
F_136 ( V_69 ) ,
F_137 ( V_69 ) ) ;
F_42 ( V_112 ) ;
F_31 ( L_93 , V_152 [ V_223 ] ) ;
F_90 ( F_9 ( V_112 ) -> V_153 + V_223 , 1 ) ;
F_138 ( V_69 ) ;
F_31 ( L_79 ) ;
F_132 ( V_112 ) ;
F_44 ( V_69 ) ;
F_31 ( L_43 ) ;
F_32 () ;
return 0 ;
}
static inline int
F_139 ( struct V_68 * V_69 , struct V_7 * V_112 ,
enum V_54 V_184 , enum V_54 V_224 )
{
if ( F_59 ( F_9 ( V_112 ) -> V_57 & ( 1 << V_224 ) ) )
return F_133 ( V_69 , V_112 , V_224 , V_184 ) ;
return 1 ;
}
static int
F_140 ( struct V_68 * V_69 ,
struct V_108 * V_144 , struct V_108 * V_225 ,
struct V_7 * V_112 , int V_226 ,
const char * V_171 )
{
struct V_108 * V_115 = V_225 ;
struct V_108 * V_227 = NULL ;
int V_70 ;
if ( ! F_7 () || V_136 )
return 0 ;
F_31 ( L_21 ) ;
F_31 ( L_94 ) ;
F_31 ( L_95 ) ;
F_46 () ;
F_31 ( L_96 ) ;
F_31 ( L_97 ,
V_69 -> V_72 , F_45 ( V_69 ) ) ;
F_42 ( V_112 ) ;
if ( V_226 )
F_31 ( L_98 , V_171 ) ;
else
F_31 ( L_99 , V_171 ) ;
F_40 ( V_225 -> V_24 ) ;
F_31 ( L_100 ) ;
F_31 ( L_79 ) ;
V_70 = F_83 ( V_225 ) ;
do {
if ( V_70 == 0 && ( V_115 != V_144 ) ) {
F_31 ( L_53 , V_155 ) ;
break;
}
V_227 = V_115 ;
V_115 = F_82 ( V_115 ) ;
V_70 -- ;
} while ( V_115 && V_115 != V_144 && ( V_70 >= 0 ) );
if ( V_226 )
F_110 ( V_144 , V_225 ,
V_227 ? V_227 -> V_24 : V_144 -> V_24 , V_225 -> V_24 ) ;
else
F_110 ( V_225 , V_144 ,
V_227 ? V_227 -> V_24 : V_225 -> V_24 , V_144 -> V_24 ) ;
F_44 ( V_69 ) ;
F_31 ( L_101 ) ;
if ( ! F_29 ( & V_144 -> V_43 ) )
return 0 ;
F_109 ( V_225 , V_144 ) ;
F_31 ( L_43 ) ;
F_32 () ;
return 0 ;
}
static int
F_141 ( struct V_68 * V_69 , struct V_7 * V_112 ,
enum V_54 V_55 , const char * V_171 )
{
int V_5 ;
struct V_108 V_144 ;
struct V_108 * V_143 ( V_129 ) ;
V_144 . V_124 = NULL ;
V_144 . V_24 = F_9 ( V_112 ) ;
V_5 = F_106 ( & V_144 , V_55 , & V_129 ) ;
if ( V_5 < 0 )
return F_95 ( V_5 ) ;
if ( V_5 == 1 )
return V_5 ;
return F_140 ( V_69 , & V_144 , V_129 ,
V_112 , 1 , V_171 ) ;
}
static int
F_142 ( struct V_68 * V_69 , struct V_7 * V_112 ,
enum V_54 V_55 , const char * V_171 )
{
int V_5 ;
struct V_108 V_144 ;
struct V_108 * V_143 ( V_129 ) ;
V_144 . V_124 = NULL ;
V_144 . V_24 = F_9 ( V_112 ) ;
V_5 = F_107 ( & V_144 , V_55 , & V_129 ) ;
if ( V_5 < 0 )
return F_95 ( V_5 ) ;
if ( V_5 == 1 )
return V_5 ;
return F_140 ( V_69 , & V_144 , V_129 ,
V_112 , 0 , V_171 ) ;
}
void F_138 ( struct V_68 * V_69 )
{
F_31 ( L_102 , V_69 -> V_228 ) ;
F_31 ( L_103 , V_69 -> V_229 ) ;
F_43 ( V_69 -> V_230 ) ;
F_31 ( L_104 , V_69 -> V_231 ) ;
F_43 ( V_69 -> V_232 ) ;
F_31 ( L_105 , V_69 -> V_233 ) ;
F_43 ( V_69 -> V_234 ) ;
F_31 ( L_106 , V_69 -> V_235 ) ;
F_43 ( V_69 -> V_236 ) ;
}
static int F_143 ( struct V_6 * V_24 )
{
#if V_237
return F_27 ( V_24 ) ;
#endif
return 0 ;
}
static int F_144 ( struct V_6 * V_24 )
{
#if V_238
return F_27 ( V_24 ) ;
#endif
return 0 ;
}
static int F_145 ( struct V_6 * V_24 )
{
#if V_239
return F_27 ( V_24 ) ;
#endif
return 0 ;
}
static inline int F_146 ( enum V_54 V_55 ,
struct V_6 * V_24 )
{
return V_240 [ V_55 >> 2 ] ( V_24 ) ;
}
static int
F_147 ( struct V_68 * V_69 , struct V_7 * V_112 ,
enum V_54 V_184 )
{
int V_241 = F_116 ( V_184 ) ;
int V_40 = V_184 & 1 ;
int V_186 = V_184 & 2 ;
T_5 V_58 = V_186 ?
F_142 : F_141 ;
if ( ! F_139 ( V_69 , V_112 , V_184 , V_241 ) )
return 0 ;
if ( ( ! V_40 || ! V_186 || V_242 ) &&
! V_58 ( V_69 , V_112 , V_241 , F_115 ( V_184 & ~ 1 ) ) )
return 0 ;
if ( ! V_40 ) {
if ( ! F_139 ( V_69 , V_112 , V_184 , V_241 + 1 ) )
return 0 ;
if ( V_242 &&
! V_58 ( V_69 , V_112 , V_241 + 1 ,
F_115 ( V_184 + 1 ) ) )
return 0 ;
}
if ( F_146 ( V_184 , F_9 ( V_112 ) ) )
return 2 ;
return 1 ;
}
static int
F_148 ( struct V_68 * V_69 , enum V_243 V_244 )
{
enum V_54 V_245 ;
struct V_7 * V_8 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_69 -> V_71 ; V_13 ++ ) {
V_8 = V_69 -> V_73 + V_13 ;
V_245 = 2 + ( V_244 << 2 ) ;
if ( V_8 -> V_40 )
V_245 += 1 ;
F_149 ( V_245 >= V_150 ) ;
if ( F_9 ( V_8 ) -> V_52 == V_246 . V_66 )
continue;
if ( ! F_150 ( V_69 , V_8 , V_245 ) )
return 0 ;
}
return 1 ;
}
static void F_151 ( unsigned long V_12 )
{
struct V_68 * V_69 = V_3 ;
V_69 -> V_176 = 1 ;
if ( ! F_148 ( V_69 , V_247 ) )
return;
if ( V_69 -> V_177 )
if ( ! F_148 ( V_69 , V_248 ) )
return;
V_69 -> V_230 = V_12 ;
V_69 -> V_229 = ++ V_69 -> V_228 ;
F_68 ( V_249 ) ;
}
void F_152 ( unsigned long V_12 )
{
F_153 ( V_250 , V_12 ) ;
if ( F_59 ( ! V_2 || V_3 -> V_4 ) )
return;
if ( F_59 ( V_3 -> V_176 ) ) {
F_154 ( V_251 ) ;
return;
}
if ( F_6 ( ! F_128 () ) )
return;
if ( F_6 ( F_59 ( V_252 ) ) )
return;
if ( F_6 ( V_3 -> V_172 ) )
return;
V_3 -> V_4 = 1 ;
F_151 ( V_12 ) ;
V_3 -> V_4 = 0 ;
}
void F_155 ( void )
{
F_152 ( V_250 ) ;
}
void F_156 ( unsigned long V_12 )
{
struct V_68 * V_69 = V_3 ;
F_157 ( V_250 , V_12 ) ;
if ( F_59 ( ! V_2 || V_3 -> V_4 ) )
return;
if ( F_6 ( ! F_128 () ) )
return;
if ( V_69 -> V_176 ) {
V_69 -> V_176 = 0 ;
V_69 -> V_232 = V_12 ;
V_69 -> V_231 = ++ V_69 -> V_228 ;
F_68 ( V_253 ) ;
} else
F_68 ( V_254 ) ;
}
void F_158 ( void )
{
F_156 ( V_250 ) ;
}
void F_159 ( unsigned long V_12 )
{
struct V_68 * V_69 = V_3 ;
if ( F_59 ( ! V_2 || V_3 -> V_4 ) )
return;
if ( F_6 ( ! F_128 () ) )
return;
if ( V_69 -> V_177 ) {
F_68 ( V_255 ) ;
return;
}
V_3 -> V_4 = 1 ;
V_69 -> V_177 = 1 ;
V_69 -> V_234 = V_12 ;
V_69 -> V_233 = ++ V_69 -> V_228 ;
F_68 ( V_256 ) ;
if ( V_69 -> V_176 )
F_148 ( V_69 , V_248 ) ;
V_3 -> V_4 = 0 ;
}
void F_160 ( unsigned long V_12 )
{
struct V_68 * V_69 = V_3 ;
if ( F_59 ( ! V_2 || V_3 -> V_4 ) )
return;
if ( F_6 ( ! F_128 () ) )
return;
if ( V_69 -> V_177 ) {
V_69 -> V_177 = 0 ;
V_69 -> V_236 = V_12 ;
V_69 -> V_235 = ++ V_69 -> V_228 ;
F_68 ( V_257 ) ;
F_6 ( ! F_113 () ) ;
} else
F_68 ( V_258 ) ;
}
static void F_161 ( T_6 V_259 , unsigned long V_95 )
{
struct V_68 * V_69 = V_3 ;
if ( F_59 ( ! V_2 ) )
return;
if ( ! ( V_259 & V_260 ) )
return;
if ( ( V_69 -> V_95 & V_261 ) && ! ( V_259 & V_262 ) )
return;
if ( ! ( V_259 & V_263 ) )
return;
if ( F_6 ( F_162 ( V_95 ) ) )
return;
F_148 ( V_69 , V_264 ) ;
}
void F_163 ( T_6 V_259 )
{
unsigned long V_95 ;
if ( F_59 ( V_3 -> V_4 ) )
return;
F_66 ( V_95 ) ;
F_164 ( V_95 ) ;
V_3 -> V_4 = 1 ;
F_161 ( V_259 , V_95 ) ;
V_3 -> V_4 = 0 ;
F_67 ( V_95 ) ;
}
static int F_165 ( struct V_68 * V_69 , struct V_7 * V_8 )
{
if ( ! V_8 -> V_199 ) {
if ( V_8 -> V_40 ) {
if ( V_69 -> V_172 )
if ( ! F_150 ( V_69 , V_8 ,
V_265 ) )
return 0 ;
if ( V_69 -> V_174 )
if ( ! F_150 ( V_69 , V_8 ,
V_266 ) )
return 0 ;
} else {
if ( V_69 -> V_172 )
if ( ! F_150 ( V_69 , V_8 , V_267 ) )
return 0 ;
if ( V_69 -> V_174 )
if ( ! F_150 ( V_69 , V_8 , V_268 ) )
return 0 ;
}
}
if ( ! V_8 -> V_269 ) {
if ( V_8 -> V_40 ) {
if ( ! F_150 ( V_69 , V_8 ,
V_270 ) )
return 0 ;
if ( V_69 -> V_177 )
if ( ! F_150 ( V_69 , V_8 ,
V_271 ) )
return 0 ;
} else {
if ( ! F_150 ( V_69 , V_8 ,
V_272 ) )
return 0 ;
if ( V_69 -> V_177 )
if ( ! F_150 ( V_69 , V_8 ,
V_273 ) )
return 0 ;
}
}
if ( ! V_8 -> V_199 && ( V_69 -> V_274 & V_263 ) ) {
if ( V_8 -> V_40 ) {
if ( ! F_150 ( V_69 , V_8 , V_275 ) )
return 0 ;
} else {
if ( ! F_150 ( V_69 , V_8 , V_276 ) )
return 0 ;
}
}
return 1 ;
}
static int F_166 ( struct V_68 * V_69 ,
struct V_7 * V_8 )
{
unsigned int V_70 = V_69 -> V_71 ;
V_8 -> V_198 = 2 * ( V_69 -> V_172 ? 1 : 0 ) +
V_69 -> V_174 ;
if ( V_70 ) {
struct V_7 * V_219 ;
V_219 = V_69 -> V_73 + V_70 - 1 ;
if ( V_219 -> V_198 != V_8 -> V_198 )
return 1 ;
}
return 0 ;
}
static inline
int F_147 ( struct V_68 * V_69 , struct V_7 * V_112 ,
enum V_54 V_184 )
{
F_80 ( 1 ) ;
return 1 ;
}
static inline int F_165 ( struct V_68 * V_69 ,
struct V_7 * V_8 )
{
return 1 ;
}
static inline int F_166 ( struct V_68 * V_69 ,
struct V_7 * V_8 )
{
return 0 ;
}
void F_163 ( T_6 V_259 )
{
}
static int F_150 ( struct V_68 * V_69 , struct V_7 * V_112 ,
enum V_54 V_184 )
{
unsigned int V_277 = 1 << V_184 , V_5 = 1 ;
if ( F_65 ( F_9 ( V_112 ) -> V_57 & V_277 ) )
return 1 ;
if ( ! F_1 () )
return 0 ;
if ( F_59 ( F_9 ( V_112 ) -> V_57 & V_277 ) ) {
F_4 () ;
return 1 ;
}
F_9 ( V_112 ) -> V_57 |= V_277 ;
if ( ! F_29 ( F_9 ( V_112 ) -> V_153 + V_184 ) )
return 0 ;
switch ( V_184 ) {
#define F_38 ( T_2 ) \
case LOCK_USED_IN_##__STATE: \
case LOCK_USED_IN_##__STATE##_READ: \
case LOCK_ENABLED_##__STATE: \
case LOCK_ENABLED_##__STATE##_READ:
#include "lockdep_states.h"
#undef F_38
V_5 = F_147 ( V_69 , V_112 , V_184 ) ;
if ( ! V_5 )
return 0 ;
break;
case V_278 :
F_167 ( V_100 ) ;
break;
default:
if ( ! F_7 () )
return 0 ;
F_80 ( 1 ) ;
return 0 ;
}
F_4 () ;
if ( V_5 == 2 ) {
F_31 ( L_107 , V_152 [ V_184 ] ) ;
F_42 ( V_112 ) ;
F_138 ( V_69 ) ;
F_32 () ;
}
return V_5 ;
}
void F_168 ( struct V_64 * V_65 , const char * V_61 ,
struct V_93 * V_52 , int V_63 )
{
int V_13 ;
F_169 ( V_65 , sizeof( * V_65 ) ) ;
for ( V_13 = 0 ; V_13 < V_107 ; V_13 ++ )
V_65 -> V_106 [ V_13 ] = NULL ;
#ifdef F_170
V_65 -> V_26 = F_171 () ;
#endif
if ( F_6 ( ! V_61 ) ) {
V_65 -> V_61 = L_108 ;
return;
}
V_65 -> V_61 = V_61 ;
if ( F_6 ( ! V_52 ) )
return;
if ( ! F_50 ( V_52 ) ) {
F_31 ( L_109 , V_52 ) ;
F_6 ( 1 ) ;
return;
}
V_65 -> V_52 = V_52 ;
if ( F_59 ( ! V_2 ) )
return;
if ( V_63 )
F_64 ( V_65 , V_63 , 1 ) ;
}
static int F_172 ( struct V_64 * V_65 , unsigned int V_63 ,
int V_199 , int V_40 , int V_218 , int V_269 ,
struct V_64 * V_195 , unsigned long V_12 ,
int V_279 )
{
struct V_68 * V_69 = V_3 ;
struct V_6 * V_24 = NULL ;
struct V_7 * V_8 ;
unsigned int V_70 , V_220 ;
int V_217 = 0 ;
int V_9 ;
T_1 V_204 ;
if ( ! V_280 )
V_218 = 1 ;
if ( F_59 ( ! V_2 ) )
return 0 ;
if ( F_6 ( ! F_128 () ) )
return 0 ;
if ( V_65 -> V_52 == & V_246 )
V_218 = 1 ;
if ( V_63 < V_107 )
V_24 = V_65 -> V_106 [ V_63 ] ;
if ( F_59 ( ! V_24 ) ) {
V_24 = F_64 ( V_65 , V_63 , 0 ) ;
if ( ! V_24 )
return 0 ;
}
F_173 ( ( V_281 * ) & V_24 -> V_149 ) ;
if ( F_49 ( V_24 ) ) {
F_31 ( L_110 , V_24 -> V_52 , V_24 -> V_61 ) ;
if ( V_24 -> V_62 > 1 )
F_31 ( L_4 , V_24 -> V_62 ) ;
F_31 ( L_21 ) ;
F_32 () ;
}
V_70 = V_69 -> V_71 ;
if ( F_6 ( V_70 >= V_282 ) )
return 0 ;
V_9 = V_24 - V_10 + 1 ;
if ( V_70 ) {
V_8 = V_69 -> V_73 + V_70 - 1 ;
if ( V_8 -> V_9 == V_9 && V_195 ) {
if ( V_8 -> V_279 )
V_8 -> V_279 ++ ;
else
V_8 -> V_279 = 2 ;
return 1 ;
}
}
V_8 = V_69 -> V_73 + V_70 ;
if ( F_6 ( ! V_24 ) )
return 0 ;
V_8 -> V_9 = V_9 ;
V_8 -> V_67 = V_12 ;
V_8 -> V_194 = V_65 ;
V_8 -> V_195 = V_195 ;
V_8 -> V_199 = V_199 ;
V_8 -> V_40 = V_40 ;
V_8 -> V_218 = V_218 ;
V_8 -> V_269 = ! ! V_269 ;
V_8 -> V_279 = V_279 ;
#ifdef F_170
V_8 -> V_283 = 0 ;
V_8 -> V_39 = F_10 () ;
#endif
if ( V_218 == 2 && ! F_165 ( V_69 , V_8 ) )
return 0 ;
if ( ! F_150 ( V_69 , V_8 , V_278 ) )
return 0 ;
V_220 = V_24 - V_10 ;
if ( F_6 ( V_220 >= V_99 ) )
return 0 ;
V_204 = V_69 -> V_222 ;
if ( ! V_70 ) {
if ( F_6 ( V_204 != 0 ) )
return 0 ;
V_217 = 1 ;
}
V_8 -> V_221 = V_204 ;
if ( F_166 ( V_69 , V_8 ) ) {
V_204 = 0 ;
V_217 = 1 ;
}
V_204 = F_131 ( V_204 , V_220 ) ;
if ( ! F_129 ( V_69 , V_65 , V_8 , V_217 , V_204 ) )
return 0 ;
V_69 -> V_222 = V_204 ;
V_69 -> V_71 ++ ;
F_130 ( V_69 ) ;
#ifdef F_58
if ( F_59 ( ! V_2 ) )
return 0 ;
#endif
if ( F_59 ( V_69 -> V_71 >= V_282 ) ) {
F_8 () ;
F_31 ( L_111 ) ;
F_31 ( L_2 ) ;
F_32 () ;
return 0 ;
}
if ( F_59 ( V_69 -> V_71 > V_284 ) )
V_284 = V_69 -> V_71 ;
return 1 ;
}
static int
F_174 ( struct V_68 * V_69 , struct V_64 * V_65 ,
unsigned long V_12 )
{
if ( ! F_8 () )
return 0 ;
if ( V_136 )
return 0 ;
F_31 ( L_21 ) ;
F_31 ( L_112 ) ;
F_31 ( L_113 ) ;
F_46 () ;
F_31 ( L_114 ) ;
F_31 ( L_115 ,
V_69 -> V_72 , F_45 ( V_69 ) ) ;
F_41 ( V_65 ) ;
F_31 ( L_116 ) ;
F_43 ( V_12 ) ;
F_31 ( L_117 ) ;
F_31 ( L_79 ) ;
F_44 ( V_69 ) ;
F_31 ( L_43 ) ;
F_32 () ;
return 0 ;
}
static int F_175 ( struct V_68 * V_69 , struct V_64 * V_65 ,
unsigned long V_12 )
{
if ( F_59 ( ! V_2 ) )
return 0 ;
if ( F_6 ( ! F_128 () ) )
return 0 ;
if ( V_69 -> V_71 <= 0 )
return F_174 ( V_69 , V_65 , V_12 ) ;
return 1 ;
}
static int F_176 ( struct V_7 * V_8 , struct V_64 * V_65 )
{
if ( V_8 -> V_194 == V_65 )
return 1 ;
if ( V_8 -> V_279 ) {
struct V_6 * V_24 = V_65 -> V_106 [ 0 ] ;
if ( ! V_24 )
V_24 = F_57 ( V_65 , 0 ) ;
if ( ! V_24 )
return 0 ;
if ( F_6 ( ! V_8 -> V_195 ) )
return 0 ;
if ( V_8 -> V_9 == V_24 - V_10 + 1 )
return 1 ;
}
return 0 ;
}
static int
F_177 ( struct V_64 * V_65 , const char * V_61 ,
struct V_93 * V_52 , unsigned int V_63 ,
unsigned long V_12 )
{
struct V_68 * V_69 = V_3 ;
struct V_7 * V_8 , * V_219 ;
struct V_6 * V_24 ;
unsigned int V_70 ;
int V_13 ;
V_70 = V_69 -> V_71 ;
if ( F_6 ( ! V_70 ) )
return 0 ;
V_219 = NULL ;
for ( V_13 = V_70 - 1 ; V_13 >= 0 ; V_13 -- ) {
V_8 = V_69 -> V_73 + V_13 ;
if ( V_219 && V_219 -> V_198 != V_8 -> V_198 )
break;
if ( F_176 ( V_8 , V_65 ) )
goto V_285;
V_219 = V_8 ;
}
return F_174 ( V_69 , V_65 , V_12 ) ;
V_285:
F_168 ( V_65 , V_61 , V_52 , 0 ) ;
V_24 = F_64 ( V_65 , V_63 , 0 ) ;
V_8 -> V_9 = V_24 - V_10 + 1 ;
V_69 -> V_71 = V_13 ;
V_69 -> V_222 = V_8 -> V_221 ;
for (; V_13 < V_70 ; V_13 ++ ) {
V_8 = V_69 -> V_73 + V_13 ;
if ( ! F_172 ( V_8 -> V_194 ,
F_9 ( V_8 ) -> V_63 , V_8 -> V_199 ,
V_8 -> V_40 , V_8 -> V_218 , V_8 -> V_269 ,
V_8 -> V_195 , V_8 -> V_67 ,
V_8 -> V_279 ) )
return 0 ;
}
if ( F_6 ( V_69 -> V_71 != V_70 ) )
return 0 ;
return 1 ;
}
static int
F_178 ( struct V_68 * V_69 ,
struct V_64 * V_65 , unsigned long V_12 )
{
struct V_7 * V_8 , * V_219 ;
unsigned int V_70 ;
int V_13 ;
V_70 = V_69 -> V_71 ;
if ( F_6 ( ! V_70 ) )
return 0 ;
V_219 = NULL ;
for ( V_13 = V_70 - 1 ; V_13 >= 0 ; V_13 -- ) {
V_8 = V_69 -> V_73 + V_13 ;
if ( V_219 && V_219 -> V_198 != V_8 -> V_198 )
break;
if ( F_176 ( V_8 , V_65 ) )
goto V_285;
V_219 = V_8 ;
}
return F_174 ( V_69 , V_65 , V_12 ) ;
V_285:
if ( V_8 -> V_194 == V_65 )
F_24 ( V_8 ) ;
if ( V_8 -> V_279 ) {
V_8 -> V_279 -- ;
if ( V_8 -> V_279 ) {
return 1 ;
}
}
V_69 -> V_71 = V_13 ;
V_69 -> V_222 = V_8 -> V_221 ;
for ( V_13 ++ ; V_13 < V_70 ; V_13 ++ ) {
V_8 = V_69 -> V_73 + V_13 ;
if ( ! F_172 ( V_8 -> V_194 ,
F_9 ( V_8 ) -> V_63 , V_8 -> V_199 ,
V_8 -> V_40 , V_8 -> V_218 , V_8 -> V_269 ,
V_8 -> V_195 , V_8 -> V_67 ,
V_8 -> V_279 ) )
return 0 ;
}
if ( F_6 ( V_69 -> V_71 != V_70 - 1 ) )
return 0 ;
return 1 ;
}
static int F_179 ( struct V_68 * V_69 ,
struct V_64 * V_65 , unsigned long V_12 )
{
struct V_7 * V_8 ;
unsigned int V_70 ;
V_70 = V_69 -> V_71 - 1 ;
V_8 = V_69 -> V_73 + V_70 ;
if ( V_8 -> V_194 != V_65 || V_8 -> V_279 )
return F_178 ( V_69 , V_65 , V_12 ) ;
V_69 -> V_71 -- ;
if ( F_6 ( ! V_70 && ( V_8 -> V_221 != 0 ) ) )
return 0 ;
V_69 -> V_222 = V_8 -> V_221 ;
F_24 ( V_8 ) ;
#ifdef F_58
V_8 -> V_221 = 0 ;
V_8 -> V_9 = 0 ;
V_8 -> V_67 = 0 ;
V_8 -> V_198 = 0 ;
#endif
return 1 ;
}
static void
F_180 ( struct V_64 * V_65 , int V_286 , unsigned long V_12 )
{
struct V_68 * V_69 = V_3 ;
if ( ! F_175 ( V_69 , V_65 , V_12 ) )
return;
if ( V_286 ) {
if ( ! F_179 ( V_69 , V_65 , V_12 ) )
return;
} else {
if ( ! F_178 ( V_69 , V_65 , V_12 ) )
return;
}
F_130 ( V_69 ) ;
}
static int F_181 ( struct V_64 * V_65 )
{
struct V_68 * V_69 = V_3 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_69 -> V_71 ; V_13 ++ ) {
struct V_7 * V_8 = V_69 -> V_73 + V_13 ;
if ( F_176 ( V_8 , V_65 ) )
return 1 ;
}
return 0 ;
}
static void F_164 ( unsigned long V_95 )
{
#if F_182 ( V_287 ) && F_182 ( F_58 ) && \
F_182 ( V_288 )
if ( ! V_2 )
return;
if ( F_162 ( V_95 ) ) {
if ( F_6 ( V_3 -> V_176 ) ) {
F_31 ( L_118 ) ;
}
} else {
if ( F_6 ( ! V_3 -> V_176 ) ) {
F_31 ( L_119 ) ;
}
}
if ( ! F_112 () ) {
if ( F_113 () ) {
F_6 ( V_3 -> V_177 ) ;
} else {
F_6 ( ! V_3 -> V_177 ) ;
}
}
if ( ! V_2 )
F_138 ( V_3 ) ;
#endif
}
void F_183 ( struct V_64 * V_65 , const char * V_61 ,
struct V_93 * V_52 , unsigned int V_63 ,
unsigned long V_12 )
{
unsigned long V_95 ;
if ( F_59 ( V_3 -> V_4 ) )
return;
F_66 ( V_95 ) ;
V_3 -> V_4 = 1 ;
F_164 ( V_95 ) ;
if ( F_177 ( V_65 , V_61 , V_52 , V_63 , V_12 ) )
F_130 ( V_3 ) ;
V_3 -> V_4 = 0 ;
F_67 ( V_95 ) ;
}
void F_184 ( struct V_64 * V_65 , unsigned int V_63 ,
int V_199 , int V_40 , int V_218 ,
struct V_64 * V_195 , unsigned long V_12 )
{
unsigned long V_95 ;
if ( F_59 ( V_3 -> V_4 ) )
return;
F_66 ( V_95 ) ;
F_164 ( V_95 ) ;
V_3 -> V_4 = 1 ;
F_185 ( V_65 , V_63 , V_199 , V_40 , V_218 , V_195 , V_12 ) ;
F_172 ( V_65 , V_63 , V_199 , V_40 , V_218 ,
F_162 ( V_95 ) , V_195 , V_12 , 0 ) ;
V_3 -> V_4 = 0 ;
F_67 ( V_95 ) ;
}
void F_186 ( struct V_64 * V_65 , int V_286 ,
unsigned long V_12 )
{
unsigned long V_95 ;
if ( F_59 ( V_3 -> V_4 ) )
return;
F_66 ( V_95 ) ;
F_164 ( V_95 ) ;
V_3 -> V_4 = 1 ;
F_187 ( V_65 , V_12 ) ;
F_180 ( V_65 , V_286 , V_12 ) ;
V_3 -> V_4 = 0 ;
F_67 ( V_95 ) ;
}
int F_188 ( struct V_64 * V_65 )
{
unsigned long V_95 ;
int V_5 = 0 ;
if ( F_59 ( V_3 -> V_4 ) )
return 1 ;
F_66 ( V_95 ) ;
F_164 ( V_95 ) ;
V_3 -> V_4 = 1 ;
V_5 = F_181 ( V_65 ) ;
V_3 -> V_4 = 0 ;
F_67 ( V_95 ) ;
return V_5 ;
}
void F_189 ( T_6 V_259 )
{
V_3 -> V_274 = V_259 ;
}
void F_190 ( void )
{
V_3 -> V_274 = 0 ;
}
static int
F_191 ( struct V_68 * V_69 , struct V_64 * V_65 ,
unsigned long V_12 )
{
if ( ! F_8 () )
return 0 ;
if ( V_136 )
return 0 ;
F_31 ( L_21 ) ;
F_31 ( L_88 ) ;
F_31 ( L_120 ) ;
F_46 () ;
F_31 ( L_90 ) ;
F_31 ( L_121 ,
V_69 -> V_72 , F_45 ( V_69 ) ) ;
F_41 ( V_65 ) ;
F_31 ( L_116 ) ;
F_43 ( V_12 ) ;
F_31 ( L_122 ) ;
F_31 ( L_79 ) ;
F_44 ( V_69 ) ;
F_31 ( L_43 ) ;
F_32 () ;
return 0 ;
}
static void
F_192 ( struct V_64 * V_65 , unsigned long V_12 )
{
struct V_68 * V_69 = V_3 ;
struct V_7 * V_8 , * V_219 ;
struct V_23 * V_25 ;
unsigned int V_70 ;
int V_13 , V_29 , V_30 ;
V_70 = V_69 -> V_71 ;
if ( F_6 ( ! V_70 ) )
return;
V_219 = NULL ;
for ( V_13 = V_70 - 1 ; V_13 >= 0 ; V_13 -- ) {
V_8 = V_69 -> V_73 + V_13 ;
if ( V_219 && V_219 -> V_198 != V_8 -> V_198 )
break;
if ( F_176 ( V_8 , V_65 ) )
goto V_285;
V_219 = V_8 ;
}
F_191 ( V_69 , V_65 , V_12 ) ;
return;
V_285:
if ( V_8 -> V_194 != V_65 )
return;
V_8 -> V_283 = F_10 () ;
V_29 = F_12 ( F_9 ( V_8 ) -> V_29 , V_12 ) ;
V_30 = F_12 ( F_9 ( V_8 ) -> V_30 ,
V_65 -> V_12 ) ;
V_25 = F_20 ( F_9 ( V_8 ) ) ;
if ( V_29 < V_14 )
V_25 -> V_29 [ V_29 ] ++ ;
if ( V_30 < V_14 )
V_25 -> V_30 [ V_30 ] ++ ;
if ( V_65 -> V_26 != F_193 () )
V_25 -> V_35 [ V_289 + ! ! V_8 -> V_40 ] ++ ;
F_22 ( V_25 ) ;
}
static void
F_194 ( struct V_64 * V_65 , unsigned long V_12 )
{
struct V_68 * V_69 = V_3 ;
struct V_7 * V_8 , * V_219 ;
struct V_23 * V_25 ;
unsigned int V_70 ;
T_1 V_290 , V_291 = 0 ;
int V_13 , V_26 ;
V_70 = V_69 -> V_71 ;
if ( F_6 ( ! V_70 ) )
return;
V_219 = NULL ;
for ( V_13 = V_70 - 1 ; V_13 >= 0 ; V_13 -- ) {
V_8 = V_69 -> V_73 + V_13 ;
if ( V_219 && V_219 -> V_198 != V_8 -> V_198 )
break;
if ( F_176 ( V_8 , V_65 ) )
goto V_285;
V_219 = V_8 ;
}
F_191 ( V_69 , V_65 , V_292 ) ;
return;
V_285:
if ( V_8 -> V_194 != V_65 )
return;
V_26 = F_193 () ;
if ( V_8 -> V_283 ) {
V_290 = F_10 () ;
V_291 = V_290 - V_8 -> V_283 ;
V_8 -> V_39 = V_290 ;
}
F_195 ( V_65 , V_12 ) ;
V_25 = F_20 ( F_9 ( V_8 ) ) ;
if ( V_291 ) {
if ( V_8 -> V_40 )
F_13 ( & V_25 -> V_31 , V_291 ) ;
else
F_13 ( & V_25 -> V_32 , V_291 ) ;
}
if ( V_65 -> V_26 != V_26 )
V_25 -> V_35 [ V_293 + ! ! V_8 -> V_40 ] ++ ;
F_22 ( V_25 ) ;
V_65 -> V_26 = V_26 ;
V_65 -> V_12 = V_12 ;
}
void F_196 ( struct V_64 * V_65 , unsigned long V_12 )
{
unsigned long V_95 ;
if ( F_59 ( ! V_38 ) )
return;
if ( F_59 ( V_3 -> V_4 ) )
return;
F_66 ( V_95 ) ;
F_164 ( V_95 ) ;
V_3 -> V_4 = 1 ;
F_197 ( V_65 , V_12 ) ;
F_192 ( V_65 , V_12 ) ;
V_3 -> V_4 = 0 ;
F_67 ( V_95 ) ;
}
void F_198 ( struct V_64 * V_65 , unsigned long V_12 )
{
unsigned long V_95 ;
if ( F_59 ( ! V_38 ) )
return;
if ( F_59 ( V_3 -> V_4 ) )
return;
F_66 ( V_95 ) ;
F_164 ( V_95 ) ;
V_3 -> V_4 = 1 ;
F_194 ( V_65 , V_12 ) ;
V_3 -> V_4 = 0 ;
F_67 ( V_95 ) ;
}
void F_199 ( void )
{
unsigned long V_95 ;
int V_13 ;
F_66 ( V_95 ) ;
V_3 -> V_222 = 0 ;
V_3 -> V_71 = 0 ;
V_3 -> V_4 = 0 ;
memset ( V_3 -> V_73 , 0 , V_282 * sizeof( struct V_7 ) ) ;
V_187 = 0 ;
V_188 = 0 ;
V_189 = 0 ;
V_2 = 1 ;
for ( V_13 = 0 ; V_13 < V_294 ; V_13 ++ )
F_69 ( V_295 + V_13 ) ;
F_67 ( V_95 ) ;
}
static void F_200 ( struct V_6 * V_24 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_109 ; V_13 ++ ) {
if ( V_111 [ V_13 ] . V_24 == V_24 )
F_201 ( & V_111 [ V_13 ] . V_115 ) ;
}
F_201 ( & V_24 -> V_104 ) ;
F_201 ( & V_24 -> V_101 ) ;
V_24 -> V_52 = NULL ;
}
static inline int F_202 ( const void * V_82 , void * V_78 , unsigned long V_296 )
{
return V_82 >= V_78 && V_82 < V_78 + V_296 ;
}
void F_203 ( void * V_78 , unsigned long V_296 )
{
struct V_6 * V_24 , * V_168 ;
struct V_85 * V_113 ;
unsigned long V_95 ;
int V_13 ;
int V_297 ;
F_66 ( V_95 ) ;
V_297 = F_1 () ;
for ( V_13 = 0 ; V_13 < V_298 ; V_13 ++ ) {
V_113 = V_299 + V_13 ;
if ( F_86 ( V_113 ) )
continue;
F_204 (class, next, head, hash_entry) {
if ( F_202 ( V_24 -> V_52 , V_78 , V_296 ) )
F_200 ( V_24 ) ;
else if ( F_202 ( V_24 -> V_61 , V_78 , V_296 ) )
F_200 ( V_24 ) ;
}
}
if ( V_297 )
F_4 () ;
F_67 ( V_95 ) ;
}
void F_205 ( struct V_64 * V_65 )
{
struct V_6 * V_24 , * V_168 ;
struct V_85 * V_113 ;
unsigned long V_95 ;
int V_13 , V_207 ;
int V_297 ;
F_66 ( V_95 ) ;
for ( V_207 = 0 ; V_207 < V_91 ; V_207 ++ ) {
V_24 = F_57 ( V_65 , V_207 ) ;
if ( V_24 )
F_200 ( V_24 ) ;
}
V_297 = F_1 () ;
for ( V_13 = 0 ; V_13 < V_298 ; V_13 ++ ) {
V_113 = V_299 + V_13 ;
if ( F_86 ( V_113 ) )
continue;
F_204 (class, next, head, hash_entry) {
int F_85 = 0 ;
for ( V_207 = 0 ; V_207 < V_107 ; V_207 ++ )
F_85 |= V_24 == V_65 -> V_106 [ V_207 ] ;
if ( F_59 ( F_85 ) ) {
if ( F_7 () ) {
F_80 ( 1 ) ;
}
goto V_300;
}
}
}
if ( V_297 )
F_4 () ;
V_300:
F_67 ( V_95 ) ;
}
void F_60 ( void )
{
int V_13 ;
if ( V_87 )
return;
for ( V_13 = 0 ; V_13 < V_298 ; V_13 ++ )
F_69 ( V_299 + V_13 ) ;
for ( V_13 = 0 ; V_13 < V_294 ; V_13 ++ )
F_69 ( V_295 + V_13 ) ;
V_87 = 1 ;
}
void T_7 F_206 ( void )
{
F_31 ( L_123 ) ;
F_31 ( L_124 , V_91 ) ;
F_31 ( L_125 , V_282 ) ;
F_31 ( L_126 , V_99 ) ;
F_31 ( L_127 , V_298 ) ;
F_31 ( L_128 , V_110 ) ;
F_31 ( L_129 , V_211 ) ;
F_31 ( L_130 , V_294 ) ;
F_31 ( L_131 ,
( sizeof( struct V_6 ) * V_99 +
sizeof( struct V_85 ) * V_298 +
sizeof( struct V_108 ) * V_110 +
sizeof( struct V_200 ) * V_211 +
sizeof( struct V_85 ) * V_294
#ifdef V_287
+ sizeof( struct V_116 )
#endif
) / 1024
) ;
F_31 ( L_132 ,
sizeof( struct V_7 ) * V_282 ) ;
#ifdef F_58
if ( V_88 ) {
F_31 ( L_133
L_134 , V_89 ) ;
F_31 ( L_135 ) ;
F_90 ( & V_90 , 0 ) ;
}
#endif
}
static void
F_207 ( struct V_68 * V_69 , const void * V_301 ,
const void * V_302 , struct V_7 * V_8 )
{
if ( ! F_8 () )
return;
if ( V_136 )
return;
F_31 ( L_21 ) ;
F_31 ( L_136 ) ;
F_31 ( L_137 ) ;
F_46 () ;
F_31 ( L_138 ) ;
F_31 ( L_139 ,
V_69 -> V_72 , F_45 ( V_69 ) , V_301 , V_302 - 1 ) ;
F_42 ( V_8 ) ;
F_44 ( V_69 ) ;
F_31 ( L_43 ) ;
F_32 () ;
}
static inline int F_208 ( const void * V_301 , unsigned long V_303 ,
const void * V_304 , unsigned long V_305 )
{
return V_304 + V_305 <= V_301 ||
V_301 + V_303 <= V_304 ;
}
void F_209 ( const void * V_301 , unsigned long V_303 )
{
struct V_68 * V_69 = V_3 ;
struct V_7 * V_8 ;
unsigned long V_95 ;
int V_13 ;
if ( F_59 ( ! V_2 ) )
return;
F_100 ( V_95 ) ;
for ( V_13 = 0 ; V_13 < V_69 -> V_71 ; V_13 ++ ) {
V_8 = V_69 -> V_73 + V_13 ;
if ( F_208 ( V_301 , V_303 , V_8 -> V_194 ,
sizeof( * V_8 -> V_194 ) ) )
continue;
F_207 ( V_69 , V_301 , V_301 + V_303 , V_8 ) ;
break;
}
F_101 ( V_95 ) ;
}
static void F_210 ( struct V_68 * V_69 )
{
if ( ! F_8 () )
return;
if ( V_136 )
return;
F_31 ( L_21 ) ;
F_31 ( L_112 ) ;
F_31 ( L_140 ) ;
F_46 () ;
F_31 ( L_114 ) ;
F_31 ( L_141 ,
V_69 -> V_72 , F_45 ( V_69 ) ) ;
F_44 ( V_69 ) ;
F_31 ( L_43 ) ;
F_32 () ;
}
void F_211 ( struct V_68 * V_306 )
{
if ( F_59 ( V_306 -> V_71 > 0 ) )
F_210 ( V_306 ) ;
}
void F_212 ( void )
{
struct V_68 * V_307 , * V_308 ;
int V_84 = 10 ;
int V_309 = 1 ;
if ( F_59 ( ! V_2 ) ) {
F_31 ( L_142 ) ;
return;
}
F_31 ( L_143 ) ;
V_310:
if ( ! F_213 ( & V_311 ) ) {
if ( V_84 == 10 )
F_31 ( L_144 ) ;
if ( V_84 ) {
V_84 -- ;
F_31 ( L_145 , 10 - V_84 ) ;
F_214 ( 200 ) ;
goto V_310;
}
F_31 ( L_146 ) ;
V_309 = 0 ;
} else {
if ( V_84 != 10 )
F_31 ( V_312 L_147 ) ;
}
F_215 (g, p) {
if ( V_308 -> V_185 == V_313 && V_308 != V_3 )
continue;
if ( V_308 -> V_71 )
F_44 ( V_308 ) ;
if ( ! V_309 )
if ( F_213 ( & V_311 ) )
V_309 = 1 ;
} F_216 ( V_307 , V_308 ) ;
F_31 ( L_21 ) ;
F_31 ( L_148 ) ;
if ( V_309 )
F_217 ( & V_311 ) ;
}
void F_218 ( struct V_68 * V_306 )
{
if ( F_59 ( ! V_2 ) ) {
F_31 ( L_142 ) ;
return;
}
F_44 ( V_306 ) ;
}
void F_219 ( void )
{
struct V_68 * V_69 = V_3 ;
if ( F_59 ( V_69 -> V_71 ) ) {
if ( ! F_8 () )
return;
F_31 ( L_21 ) ;
F_31 ( L_149 ) ;
F_31 ( L_150 ) ;
F_46 () ;
F_31 ( L_151 ) ;
F_31 ( L_152 ,
V_69 -> V_72 , V_69 -> V_314 ) ;
F_44 ( V_69 ) ;
}
}
void F_220 ( const char * V_315 , const int line , const char * V_316 )
{
struct V_68 * V_69 = V_3 ;
#ifndef F_221
if ( ! F_8 () )
return;
#endif
F_31 ( L_21 ) ;
F_31 ( L_153 ) ;
F_31 ( L_154 ) ;
F_46 () ;
F_31 ( L_155 ) ;
F_31 ( L_156 , V_315 , line , V_316 ) ;
F_31 ( L_42 ) ;
F_31 ( L_157 , V_317 , V_2 ) ;
if ( F_222 () )
F_31 ( L_158 ) ;
F_44 ( V_69 ) ;
F_31 ( L_43 ) ;
F_32 () ;
}
