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
if ( V_2 && ! F_5 ( & V_1 ) )
return F_6 ( 1 ) ;
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
static int F_39 ( struct V_6 * V_24 )
{
char V_53 [ V_60 ] ;
const char * V_61 ;
V_61 = V_24 -> V_61 ;
if ( ! V_61 )
V_61 = F_33 ( V_24 -> V_52 , V_53 ) ;
return F_31 ( L_3 , V_61 ) ;
}
static void F_40 ( struct V_6 * V_24 )
{
char V_53 [ V_60 ] , V_58 [ V_59 ] ;
const char * V_61 ;
F_37 ( V_24 , V_58 ) ;
V_61 = V_24 -> V_61 ;
if ( ! V_61 ) {
V_61 = F_33 ( V_24 -> V_52 , V_53 ) ;
F_31 ( L_4 , V_61 ) ;
} else {
F_31 ( L_4 , V_61 ) ;
if ( V_24 -> V_62 > 1 )
F_31 ( L_5 , V_24 -> V_62 ) ;
if ( V_24 -> V_63 )
F_31 ( L_6 , V_24 -> V_63 ) ;
}
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
F_47 () -> V_75 ) ;
}
static int F_48 ( struct V_6 * V_24 )
{
#if V_76
return F_27 ( V_24 ) ;
#endif
return 0 ;
}
static int F_49 ( void * V_77 )
{
unsigned long V_78 = ( unsigned long ) & V_79 ,
V_80 = ( unsigned long ) & V_81 ,
V_82 = ( unsigned long ) V_77 ;
if ( ( V_82 >= V_78 ) && ( V_82 < V_80 ) )
return 1 ;
if ( F_50 ( V_82 ) )
return 1 ;
if ( F_51 ( V_82 ) )
return 1 ;
return F_52 ( V_82 ) || F_53 ( V_82 ) ;
}
static int F_54 ( struct V_6 * V_83 )
{
struct V_6 * V_24 ;
int V_84 = 0 ;
if ( ! V_83 -> V_61 )
return 0 ;
F_55 (class, &all_lock_classes, lock_entry) {
if ( V_83 -> V_52 - V_83 -> V_63 == V_24 -> V_52 )
return V_24 -> V_62 ;
if ( V_24 -> V_61 && ! strcmp ( V_24 -> V_61 , V_83 -> V_61 ) )
V_84 = V_17 ( V_84 , V_24 -> V_62 ) ;
}
return V_84 + 1 ;
}
static inline struct V_6 *
F_56 ( struct V_64 * V_65 , unsigned int V_63 )
{
struct V_51 * V_52 ;
struct V_85 * V_86 ;
struct V_6 * V_24 ;
#ifdef F_57
if ( F_58 ( ! V_87 ) ) {
F_59 () ;
V_88 = 1 ;
F_30 ( & V_89 ) ;
}
#endif
if ( F_58 ( V_63 >= V_90 ) ) {
F_8 () ;
F_31 ( V_91
L_16 , V_63 ) ;
F_31 ( V_91
L_2 ) ;
F_32 () ;
return NULL ;
}
if ( F_58 ( ! V_65 -> V_52 ) )
V_65 -> V_52 = ( void * ) V_65 ;
F_60 ( sizeof( struct V_92 ) >
sizeof( struct V_64 ) ) ;
V_52 = V_65 -> V_52 -> V_66 + V_63 ;
V_86 = F_61 ( V_52 ) ;
F_55 (class, hash_head, hash_entry) {
if ( V_24 -> V_52 == V_52 ) {
F_62 ( V_24 -> V_61 != V_65 -> V_61 ) ;
return V_24 ;
}
}
return NULL ;
}
static inline struct V_6 *
F_63 ( struct V_64 * V_65 , unsigned int V_63 , int V_93 )
{
struct V_51 * V_52 ;
struct V_85 * V_86 ;
struct V_6 * V_24 ;
unsigned long V_94 ;
V_24 = F_56 ( V_65 , V_63 ) ;
if ( F_64 ( V_24 ) )
return V_24 ;
if ( ! F_49 ( V_65 -> V_52 ) ) {
F_8 () ;
F_31 ( L_17 ) ;
F_31 ( L_18 ) ;
F_31 ( L_2 ) ;
F_32 () ;
return NULL ;
}
V_52 = V_65 -> V_52 -> V_66 + V_63 ;
V_86 = F_61 ( V_52 ) ;
F_65 ( V_94 ) ;
if ( ! F_1 () ) {
F_66 ( V_94 ) ;
return NULL ;
}
F_55 (class, hash_head, hash_entry)
if ( V_24 -> V_52 == V_52 )
goto V_95;
if ( V_96 >= V_97 ) {
if ( ! F_7 () ) {
F_66 ( V_94 ) ;
return NULL ;
}
F_66 ( V_94 ) ;
F_31 ( L_19 ) ;
F_31 ( L_2 ) ;
F_32 () ;
return NULL ;
}
V_24 = V_10 + V_96 ++ ;
F_67 ( V_98 ) ;
V_24 -> V_52 = V_52 ;
V_24 -> V_61 = V_65 -> V_61 ;
V_24 -> V_63 = V_63 ;
F_68 ( & V_24 -> V_99 ) ;
F_68 ( & V_24 -> V_100 ) ;
F_68 ( & V_24 -> V_101 ) ;
V_24 -> V_62 = F_54 ( V_24 ) ;
F_69 ( & V_24 -> V_102 , V_86 ) ;
F_69 ( & V_24 -> V_99 , & V_103 ) ;
if ( F_28 ( V_24 ) ) {
F_4 () ;
F_66 ( V_94 ) ;
F_31 ( L_20 , V_24 -> V_52 , V_24 -> V_61 ) ;
if ( V_24 -> V_62 > 1 )
F_31 ( L_5 , V_24 -> V_62 ) ;
F_31 ( L_21 ) ;
F_32 () ;
F_65 ( V_94 ) ;
if ( ! F_1 () ) {
F_66 ( V_94 ) ;
return NULL ;
}
}
V_95:
F_4 () ;
F_66 ( V_94 ) ;
if ( ! V_63 || V_93 )
V_65 -> V_104 [ 0 ] = V_24 ;
else if ( V_63 < V_105 )
V_65 -> V_104 [ V_63 ] = V_24 ;
if ( F_6 ( V_24 -> V_63 != V_63 ) )
return NULL ;
return V_24 ;
}
static struct V_106 * F_70 ( void )
{
if ( V_107 >= V_108 ) {
if ( ! F_7 () )
return NULL ;
F_31 ( L_22 ) ;
F_31 ( L_2 ) ;
F_32 () ;
return NULL ;
}
return V_109 + V_107 ++ ;
}
static int F_71 ( struct V_6 * V_24 , struct V_6 * V_110 ,
struct V_85 * V_111 , unsigned long V_12 ,
int V_112 , struct V_42 * V_43 )
{
struct V_106 * V_113 ;
V_113 = F_70 () ;
if ( ! V_113 )
return 0 ;
V_113 -> V_24 = V_110 ;
V_113 -> V_112 = V_112 ;
V_113 -> V_43 = * V_43 ;
F_69 ( & V_113 -> V_113 , V_111 ) ;
return 1 ;
}
static inline void F_72 ( struct V_114 * V_115 )
{
V_115 -> V_116 = V_115 -> V_117 = 0 ;
V_118 ++ ;
}
static inline int F_73 ( struct V_114 * V_115 )
{
return ( V_115 -> V_116 == V_115 -> V_117 ) ;
}
static inline int F_74 ( struct V_114 * V_115 )
{
return ( ( V_115 -> V_117 + 1 ) & V_119 ) == V_115 -> V_116 ;
}
static inline int F_75 ( struct V_114 * V_115 , unsigned long V_120 )
{
if ( F_74 ( V_115 ) )
return - 1 ;
V_115 -> V_121 [ V_115 -> V_117 ] = V_120 ;
V_115 -> V_117 = ( V_115 -> V_117 + 1 ) & V_119 ;
return 0 ;
}
static inline int F_76 ( struct V_114 * V_115 , unsigned long * V_120 )
{
if ( F_73 ( V_115 ) )
return - 1 ;
* V_120 = V_115 -> V_121 [ V_115 -> V_116 ] ;
V_115 -> V_116 = ( V_115 -> V_116 + 1 ) & V_119 ;
return 0 ;
}
static inline unsigned int F_77 ( struct V_114 * V_115 )
{
return ( V_115 -> V_117 - V_115 -> V_116 ) & V_119 ;
}
static inline void F_78 ( struct V_106 * V_65 ,
struct V_106 * V_122 )
{
unsigned long V_19 ;
V_19 = V_65 - V_109 ;
F_79 ( V_19 >= V_107 ) ;
V_65 -> V_122 = V_122 ;
V_65 -> V_24 -> V_123 = V_118 ;
}
static inline unsigned long F_80 ( struct V_106 * V_65 )
{
unsigned long V_19 ;
V_19 = V_65 - V_109 ;
F_79 ( V_19 >= V_107 ) ;
return V_65 -> V_24 -> V_123 == V_118 ;
}
static inline struct V_106 * F_81 ( struct V_106 * V_124 )
{
return V_124 -> V_122 ;
}
static inline int F_82 ( struct V_106 * V_124 )
{
int V_70 = 0 ;
struct V_106 * V_122 ;
while ( ( V_122 = F_81 ( V_124 ) ) ) {
V_124 = V_122 ;
V_70 ++ ;
}
return V_70 ;
}
static int F_83 ( struct V_106 * V_125 ,
void * V_126 ,
int (* F_84)( struct V_106 * V_113 , void * V_126 ) ,
struct V_106 * * V_127 ,
int V_128 )
{
struct V_106 * V_113 ;
struct V_85 * V_111 ;
struct V_114 * V_115 = & V_129 ;
int V_5 = 1 ;
if ( F_84 ( V_125 , V_126 ) ) {
* V_127 = V_125 ;
V_5 = 0 ;
goto exit;
}
if ( V_128 )
V_111 = & V_125 -> V_24 -> V_101 ;
else
V_111 = & V_125 -> V_24 -> V_100 ;
if ( F_85 ( V_111 ) )
goto exit;
F_72 ( V_115 ) ;
F_75 ( V_115 , ( unsigned long ) V_125 ) ;
while ( ! F_73 ( V_115 ) ) {
struct V_106 * V_65 ;
F_76 ( V_115 , ( unsigned long * ) & V_65 ) ;
if ( ! V_65 -> V_24 ) {
V_5 = - 2 ;
goto exit;
}
if ( V_128 )
V_111 = & V_65 -> V_24 -> V_101 ;
else
V_111 = & V_65 -> V_24 -> V_100 ;
F_55 (entry, head, entry) {
if ( ! F_80 ( V_113 ) ) {
unsigned int V_130 ;
F_78 ( V_113 , V_65 ) ;
if ( F_84 ( V_113 , V_126 ) ) {
* V_127 = V_113 ;
V_5 = 0 ;
goto exit;
}
if ( F_75 ( V_115 , ( unsigned long ) V_113 ) ) {
V_5 = - 1 ;
goto exit;
}
V_130 = F_77 ( V_115 ) ;
if ( V_131 < V_130 )
V_131 = V_130 ;
}
}
}
exit:
return V_5 ;
}
static inline int F_86 ( struct V_106 * V_132 ,
void * V_126 ,
int (* F_84)( struct V_106 * V_113 , void * V_126 ) ,
struct V_106 * * V_127 )
{
return F_83 ( V_132 , V_126 , F_84 , V_127 , 1 ) ;
}
static inline int F_87 ( struct V_106 * V_132 ,
void * V_126 ,
int (* F_84)( struct V_106 * V_113 , void * V_126 ) ,
struct V_106 * * V_127 )
{
return F_83 ( V_132 , V_126 , F_84 , V_127 , 0 ) ;
}
static T_3 int
F_88 ( struct V_106 * V_133 , int V_70 )
{
if ( V_134 )
return 0 ;
F_31 ( L_23 , V_70 ) ;
F_40 ( V_133 -> V_24 ) ;
F_31 ( L_24 ) ;
F_89 ( & V_133 -> V_43 , 6 ) ;
return 0 ;
}
static void
F_90 ( struct V_7 * V_21 ,
struct V_7 * V_135 ,
struct V_106 * V_136 )
{
struct V_6 * V_137 = F_9 ( V_21 ) ;
struct V_6 * V_133 = F_9 ( V_135 ) ;
struct V_6 * V_122 = V_136 -> V_24 ;
if ( V_122 != V_137 ) {
F_31 ( L_25 ) ;
F_39 ( V_137 ) ;
F_31 ( L_26 ) ;
F_39 ( V_122 ) ;
F_31 ( L_26 ) ;
F_39 ( V_133 ) ;
F_31 ( L_27 ) ;
}
F_31 ( L_28 ) ;
F_31 ( L_29 ) ;
F_31 ( L_30 ) ;
F_31 ( L_31 ) ;
F_39 ( V_133 ) ;
F_31 ( L_32 ) ;
F_31 ( L_33 ) ;
F_39 ( V_122 ) ;
F_31 ( L_32 ) ;
F_31 ( L_33 ) ;
F_39 ( V_133 ) ;
F_31 ( L_32 ) ;
F_31 ( L_31 ) ;
F_39 ( V_137 ) ;
F_31 ( L_32 ) ;
F_31 ( L_34 ) ;
}
static T_3 int
F_91 ( struct V_106 * V_113 , unsigned int V_70 ,
struct V_7 * V_138 ,
struct V_7 * V_139 )
{
struct V_68 * V_69 = V_3 ;
if ( V_134 )
return 0 ;
F_31 ( L_35 ) ;
F_31 ( L_36 ) ;
F_46 () ;
F_31 ( L_37 ) ;
F_31 ( L_38 ,
V_69 -> V_72 , F_45 ( V_69 ) ) ;
F_42 ( V_138 ) ;
F_31 ( L_39 ) ;
F_42 ( V_139 ) ;
F_31 ( L_40 ) ;
F_31 ( L_41 ) ;
F_88 ( V_113 , V_70 ) ;
return 0 ;
}
static inline int F_92 ( struct V_106 * V_113 , void * V_126 )
{
return V_113 -> V_24 == V_126 ;
}
static T_3 int F_93 ( struct V_106 * V_110 ,
struct V_106 * V_133 ,
struct V_7 * V_138 ,
struct V_7 * V_139 )
{
struct V_68 * V_69 = V_3 ;
struct V_106 * V_122 ;
struct V_106 * V_140 ;
int V_70 ;
if ( ! F_7 () || V_134 )
return 0 ;
if ( ! F_29 ( & V_110 -> V_43 ) )
return 0 ;
V_70 = F_82 ( V_133 ) ;
F_91 ( V_133 , V_70 , V_138 , V_139 ) ;
V_122 = F_81 ( V_133 ) ;
V_140 = V_122 ;
while ( V_122 ) {
F_88 ( V_122 , -- V_70 ) ;
V_122 = F_81 ( V_122 ) ;
}
F_31 ( L_42 ) ;
F_90 ( V_138 , V_139 ,
V_140 ) ;
F_44 ( V_69 ) ;
F_31 ( L_43 ) ;
F_32 () ;
return 0 ;
}
static T_3 int F_94 ( int V_5 )
{
if ( ! F_7 () )
return 0 ;
F_95 ( 1 , L_44 , V_5 ) ;
return 0 ;
}
static int F_96 ( struct V_106 * V_113 , void * V_126 )
{
( * ( unsigned long * ) V_126 ) ++ ;
return 0 ;
}
unsigned long F_97 ( struct V_106 * V_110 )
{
unsigned long V_84 = 0 ;
struct V_106 * V_141 ( V_127 ) ;
F_86 ( V_110 , ( void * ) & V_84 , F_96 , & V_127 ) ;
return V_84 ;
}
unsigned long F_98 ( struct V_6 * V_24 )
{
unsigned long V_5 , V_94 ;
struct V_106 V_110 ;
V_110 . V_122 = NULL ;
V_110 . V_24 = V_24 ;
F_99 ( V_94 ) ;
F_2 ( & V_1 ) ;
V_5 = F_97 ( & V_110 ) ;
F_3 ( & V_1 ) ;
F_100 ( V_94 ) ;
return V_5 ;
}
unsigned long F_101 ( struct V_106 * V_110 )
{
unsigned long V_84 = 0 ;
struct V_106 * V_141 ( V_127 ) ;
F_87 ( V_110 , ( void * ) & V_84 , F_96 , & V_127 ) ;
return V_84 ;
}
unsigned long F_102 ( struct V_6 * V_24 )
{
unsigned long V_5 , V_94 ;
struct V_106 V_110 ;
V_110 . V_122 = NULL ;
V_110 . V_24 = V_24 ;
F_99 ( V_94 ) ;
F_2 ( & V_1 ) ;
V_5 = F_101 ( & V_110 ) ;
F_3 ( & V_1 ) ;
F_100 ( V_94 ) ;
return V_5 ;
}
static T_3 int
F_103 ( struct V_106 * V_142 , struct V_6 * V_133 ,
struct V_106 * * V_127 )
{
int V_143 ;
F_67 ( V_144 ) ;
V_143 = F_86 ( V_142 , V_133 , F_92 , V_127 ) ;
return V_143 ;
}
static inline int F_104 ( struct V_106 * V_113 , void * V_55 )
{
return V_113 -> V_24 -> V_57 & ( 1 << (enum V_54 ) V_55 ) ;
}
static int
F_105 ( struct V_106 * V_142 , enum V_54 V_55 ,
struct V_106 * * V_127 )
{
int V_143 ;
F_67 ( V_145 ) ;
V_143 = F_86 ( V_142 , ( void * ) V_55 , F_104 , V_127 ) ;
return V_143 ;
}
static int
F_106 ( struct V_106 * V_142 , enum V_54 V_55 ,
struct V_106 * * V_127 )
{
int V_143 ;
F_67 ( V_146 ) ;
V_143 = F_87 ( V_142 , ( void * ) V_55 , F_104 , V_127 ) ;
return V_143 ;
}
static void F_107 ( struct V_6 * V_24 , int V_70 )
{
int V_55 ;
F_31 ( L_45 , V_70 , L_12 ) ;
F_40 ( V_24 ) ;
F_31 ( L_46 , V_24 -> V_147 ) ;
F_31 ( L_47 ) ;
for ( V_55 = 0 ; V_55 < V_148 ; V_55 ++ ) {
if ( V_24 -> V_57 & ( 1 << V_55 ) ) {
int V_149 = V_70 ;
V_149 += F_31 ( L_48 , V_70 , L_12 , V_150 [ V_55 ] ) ;
V_149 += F_31 ( L_49 ) ;
F_89 ( V_24 -> V_151 + V_55 , V_149 ) ;
}
}
F_31 ( L_50 , V_70 , L_12 ) ;
F_31 ( L_51 , V_70 , L_12 ) ;
F_43 ( ( unsigned long ) V_24 -> V_52 ) ;
}
static void T_4
F_108 ( struct V_106 * V_152 ,
struct V_106 * V_142 )
{
struct V_106 * V_113 = V_152 ;
int V_70 ;
V_70 = F_82 ( V_152 ) ;
do {
F_107 ( V_113 -> V_24 , V_70 ) ;
F_31 ( L_52 , V_70 , L_12 ) ;
F_89 ( & V_113 -> V_43 , 2 ) ;
F_31 ( L_21 ) ;
if ( V_70 == 0 && ( V_113 != V_142 ) ) {
F_31 ( L_53 , V_153 ) ;
break;
}
V_113 = F_81 ( V_113 ) ;
V_70 -- ;
} while ( V_113 && ( V_70 >= 0 ) );
return;
}
static void
F_109 ( struct V_106 * V_154 ,
struct V_106 * V_155 ,
struct V_6 * V_156 ,
struct V_6 * V_157 )
{
struct V_6 * V_158 = V_154 -> V_24 ;
struct V_6 * V_159 = V_155 -> V_24 ;
struct V_6 * V_160 = V_156 ;
if ( V_160 == V_158 )
V_160 = V_157 ;
if ( V_160 != V_159 ) {
F_31 ( L_25 ) ;
F_39 ( V_158 ) ;
F_31 ( L_26 ) ;
F_39 ( V_160 ) ;
F_31 ( L_26 ) ;
F_39 ( V_159 ) ;
F_31 ( L_27 ) ;
}
F_31 ( L_54 ) ;
F_31 ( L_29 ) ;
F_31 ( L_30 ) ;
F_31 ( L_31 ) ;
F_39 ( V_159 ) ;
F_31 ( L_32 ) ;
F_31 ( L_55 ) ;
F_31 ( L_33 ) ;
F_39 ( V_158 ) ;
F_31 ( L_32 ) ;
F_31 ( L_33 ) ;
F_39 ( V_160 ) ;
F_31 ( L_32 ) ;
F_31 ( L_56 ) ;
F_31 ( L_57 ) ;
F_39 ( V_158 ) ;
F_31 ( L_32 ) ;
F_31 ( L_34 ) ;
}
static int
F_110 ( struct V_68 * V_69 ,
struct V_106 * V_161 ,
struct V_106 * V_162 ,
struct V_106 * V_163 ,
struct V_106 * V_164 ,
struct V_7 * V_165 ,
struct V_7 * V_166 ,
enum V_54 V_167 ,
enum V_54 V_168 ,
const char * V_169 )
{
if ( ! F_7 () || V_134 )
return 0 ;
F_31 ( L_58 ) ;
F_31 ( L_59 ,
V_169 , V_169 ) ;
F_46 () ;
F_31 ( L_60 ) ;
F_31 ( L_61 ,
V_69 -> V_72 , F_45 ( V_69 ) ,
V_69 -> V_170 , F_111 () >> V_171 ,
V_69 -> V_172 , F_112 () >> V_173 ,
V_69 -> V_174 ,
V_69 -> V_175 ) ;
F_42 ( V_166 ) ;
F_31 ( L_62 ) ;
F_42 ( V_165 ) ;
F_31 ( L_63 ) ;
F_40 ( F_9 ( V_165 ) ) ;
F_31 ( L_64 ) ;
F_40 ( F_9 ( V_166 ) ) ;
F_31 ( L_21 ) ;
F_31 ( L_65 ,
V_169 ) ;
F_40 ( V_163 -> V_24 ) ;
F_31 ( L_66 , V_169 ) ;
F_89 ( V_163 -> V_24 -> V_151 + V_167 , 1 ) ;
F_31 ( L_67 , V_169 ) ;
F_40 ( V_164 -> V_24 ) ;
F_31 ( L_68 , V_169 ) ;
F_31 ( L_69 ) ;
F_89 ( V_164 -> V_24 -> V_151 + V_168 , 1 ) ;
F_31 ( L_42 ) ;
F_109 ( V_163 , V_164 ,
F_9 ( V_165 ) , F_9 ( V_166 ) ) ;
F_44 ( V_69 ) ;
F_31 ( L_70 , V_169 ) ;
F_31 ( L_71 ) ;
if ( ! F_29 ( & V_161 -> V_43 ) )
return 0 ;
F_108 ( V_163 , V_161 ) ;
F_31 ( L_72 ) ;
F_31 ( L_73 , V_169 ) ;
if ( ! F_29 ( & V_162 -> V_43 ) )
return 0 ;
F_108 ( V_164 , V_162 ) ;
F_31 ( L_43 ) ;
F_32 () ;
return 0 ;
}
static int
F_113 ( struct V_68 * V_69 , struct V_7 * V_165 ,
struct V_7 * V_166 , enum V_54 V_176 ,
enum V_54 V_177 , const char * V_169 )
{
int V_5 ;
struct V_106 V_110 , V_178 ;
struct V_106 * V_141 ( V_127 ) ;
struct V_106 * V_141 ( V_179 ) ;
V_110 . V_122 = NULL ;
V_110 . V_24 = F_9 ( V_165 ) ;
V_5 = F_106 ( & V_110 , V_176 , & V_127 ) ;
if ( V_5 < 0 )
return F_94 ( V_5 ) ;
if ( V_5 == 1 )
return V_5 ;
V_178 . V_122 = NULL ;
V_178 . V_24 = F_9 ( V_166 ) ;
V_5 = F_105 ( & V_178 , V_177 , & V_179 ) ;
if ( V_5 < 0 )
return F_94 ( V_5 ) ;
if ( V_5 == 1 )
return V_5 ;
return F_110 ( V_69 , & V_110 , & V_178 ,
V_127 , V_179 ,
V_165 , V_166 ,
V_176 , V_177 , V_169 ) ;
}
static inline const char * F_114 ( enum V_54 V_55 )
{
return ( V_55 & 1 ) ? V_180 [ V_55 >> 2 ] : V_181 [ V_55 >> 2 ] ;
}
static int F_115 ( int V_182 )
{
int V_183 = V_182 & ~ 3 ;
int V_184 = V_182 & 2 ;
return V_183 | ( V_184 ^ 2 ) ;
}
static int F_116 ( struct V_68 * V_69 , struct V_7 * V_165 ,
struct V_7 * V_166 , enum V_54 V_55 )
{
if ( ! F_113 ( V_69 , V_165 , V_166 , V_55 ,
F_115 ( V_55 ) , F_114 ( V_55 ) ) )
return 0 ;
V_55 ++ ;
if ( ! F_113 ( V_69 , V_165 , V_166 , V_55 ,
F_115 ( V_55 ) , F_114 ( V_55 ) ) )
return 0 ;
return 1 ;
}
static int
F_117 ( struct V_68 * V_69 , struct V_7 * V_165 ,
struct V_7 * V_166 )
{
#define F_38 ( T_2 ) \
if (!check_irq_usage(curr, prev, next, LOCK_USED_IN_##__STATE)) \
return 0;
#include "lockdep_states.h"
#undef F_38
return 1 ;
}
static void F_118 ( void )
{
if ( V_3 -> V_170 )
V_185 ++ ;
else {
if ( V_3 -> V_172 )
V_186 ++ ;
else
V_187 ++ ;
}
}
static inline int
F_117 ( struct V_68 * V_69 , struct V_7 * V_165 ,
struct V_7 * V_166 )
{
return 1 ;
}
static inline void F_118 ( void )
{
V_187 ++ ;
}
static void
F_119 ( struct V_7 * V_188 ,
struct V_7 * V_189 )
{
struct V_6 * V_166 = F_9 ( V_188 ) ;
struct V_6 * V_165 = F_9 ( V_189 ) ;
F_31 ( L_28 ) ;
F_31 ( L_74 ) ;
F_31 ( L_75 ) ;
F_31 ( L_31 ) ;
F_39 ( V_165 ) ;
F_31 ( L_32 ) ;
F_31 ( L_31 ) ;
F_39 ( V_166 ) ;
F_31 ( L_32 ) ;
F_31 ( L_34 ) ;
F_31 ( L_76 ) ;
}
static int
F_120 ( struct V_68 * V_69 , struct V_7 * V_165 ,
struct V_7 * V_166 )
{
if ( ! F_7 () || V_134 )
return 0 ;
F_31 ( L_77 ) ;
F_31 ( L_78 ) ;
F_46 () ;
F_31 ( L_79 ) ;
F_31 ( L_38 ,
V_69 -> V_72 , F_45 ( V_69 ) ) ;
F_42 ( V_166 ) ;
F_31 ( L_39 ) ;
F_42 ( V_165 ) ;
F_31 ( L_80 ) ;
F_119 ( V_166 , V_165 ) ;
F_44 ( V_69 ) ;
F_31 ( L_43 ) ;
F_32 () ;
return 0 ;
}
static int
F_121 ( struct V_68 * V_69 , struct V_7 * V_166 ,
struct V_64 * V_190 , int V_40 )
{
struct V_7 * V_165 ;
struct V_7 * V_191 = NULL ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_69 -> V_71 ; V_13 ++ ) {
V_165 = V_69 -> V_73 + V_13 ;
if ( V_165 -> V_192 == V_166 -> V_193 )
V_191 = V_165 ;
if ( F_9 ( V_165 ) != F_9 ( V_166 ) )
continue;
if ( ( V_40 == 2 ) && V_165 -> V_40 )
return 2 ;
if ( V_191 )
return 2 ;
return F_120 ( V_69 , V_165 , V_166 ) ;
}
return 1 ;
}
static int
F_122 ( struct V_68 * V_69 , struct V_7 * V_165 ,
struct V_7 * V_166 , int V_112 , int V_194 )
{
struct V_106 * V_113 ;
int V_5 ;
struct V_106 V_110 ;
struct V_106 * V_141 ( V_127 ) ;
static struct V_42 V_43 ;
V_110 . V_24 = F_9 ( V_166 ) ;
V_110 . V_122 = NULL ;
V_5 = F_103 ( & V_110 , F_9 ( V_165 ) , & V_127 ) ;
if ( F_58 ( ! V_5 ) )
return F_93 ( & V_110 , V_127 , V_166 , V_165 ) ;
else if ( F_58 ( V_5 < 0 ) )
return F_94 ( V_5 ) ;
if ( ! F_117 ( V_69 , V_165 , V_166 ) )
return 0 ;
if ( V_166 -> V_40 == 2 || V_165 -> V_40 == 2 )
return 1 ;
F_55 (entry, &hlock_class(prev)->locks_after, entry) {
if ( V_113 -> V_24 == F_9 ( V_166 ) ) {
if ( V_112 == 1 )
V_113 -> V_112 = 1 ;
return 2 ;
}
}
if ( ! V_194 && ! F_29 ( & V_43 ) )
return 0 ;
V_5 = F_71 ( F_9 ( V_165 ) , F_9 ( V_166 ) ,
& F_9 ( V_165 ) -> V_101 ,
V_166 -> V_67 , V_112 , & V_43 ) ;
if ( ! V_5 )
return 0 ;
V_5 = F_71 ( F_9 ( V_166 ) , F_9 ( V_165 ) ,
& F_9 ( V_166 ) -> V_100 ,
V_166 -> V_67 , V_112 , & V_43 ) ;
if ( ! V_5 )
return 0 ;
if ( F_28 ( F_9 ( V_165 ) ) || F_28 ( F_9 ( V_166 ) ) ) {
F_4 () ;
F_31 ( L_81 ) ;
F_40 ( F_9 ( V_165 ) ) ;
F_31 ( L_82 ) ;
F_40 ( F_9 ( V_166 ) ) ;
F_31 ( L_21 ) ;
F_32 () ;
return F_1 () ;
}
return 1 ;
}
static int
F_123 ( struct V_68 * V_69 , struct V_7 * V_166 )
{
int V_70 = V_69 -> V_71 ;
int V_194 = 0 ;
struct V_7 * V_8 ;
if ( ! V_70 )
goto V_195;
if ( V_69 -> V_73 [ V_70 ] . V_196 !=
V_69 -> V_73 [ V_70 - 1 ] . V_196 )
goto V_195;
for (; ; ) {
int V_112 = V_69 -> V_71 - V_70 + 1 ;
V_8 = V_69 -> V_73 + V_70 - 1 ;
if ( V_8 -> V_40 != 2 ) {
if ( ! F_122 ( V_69 , V_8 , V_166 ,
V_112 , V_194 ) )
return 0 ;
if ( ! V_8 -> V_197 )
break;
}
V_70 -- ;
if ( ! V_70 )
break;
if ( V_69 -> V_73 [ V_70 ] . V_196 !=
V_69 -> V_73 [ V_70 - 1 ] . V_196 )
break;
V_194 = 1 ;
}
return 1 ;
V_195:
if ( ! F_7 () )
return 0 ;
F_79 ( 1 ) ;
return 0 ;
}
struct V_6 * F_124 ( struct V_198 * V_199 , int V_13 )
{
return V_10 + V_200 [ V_199 -> V_201 + V_13 ] ;
}
static inline int F_125 ( struct V_68 * V_69 ,
struct V_7 * V_8 ,
T_1 V_202 )
{
struct V_6 * V_24 = F_9 ( V_8 ) ;
struct V_85 * V_86 = F_126 ( V_202 ) ;
struct V_198 * V_199 ;
struct V_7 * V_203 , * V_204 ;
int V_13 , V_205 ;
if ( F_6 ( ! F_127 () ) )
return 0 ;
F_55 (chain, hash_head, entry) {
if ( V_199 -> V_202 == V_202 ) {
V_206:
F_67 ( V_207 ) ;
if ( F_48 ( V_24 ) )
F_31 ( L_83
L_84 ,
( unsigned long long ) V_202 ,
V_24 -> V_52 , V_24 -> V_61 ) ;
return 0 ;
}
}
if ( F_48 ( V_24 ) )
F_31 ( L_85 ,
( unsigned long long ) V_202 , V_24 -> V_52 , V_24 -> V_61 ) ;
if ( ! F_1 () )
return 0 ;
F_55 (chain, hash_head, entry) {
if ( V_199 -> V_202 == V_202 ) {
F_4 () ;
goto V_206;
}
}
if ( F_58 ( V_208 >= V_209 ) ) {
if ( ! F_7 () )
return 0 ;
F_31 ( L_86 ) ;
F_31 ( L_2 ) ;
F_32 () ;
return 0 ;
}
V_199 = V_210 + V_208 ++ ;
V_199 -> V_202 = V_202 ;
V_199 -> V_196 = V_8 -> V_196 ;
V_204 = V_8 ;
for ( V_13 = V_69 -> V_71 - 1 ; V_13 >= 0 ; V_13 -- ) {
V_203 = V_69 -> V_73 + V_13 ;
if ( V_203 -> V_196 != V_204 -> V_196 )
break;
V_204 = V_8 ;
}
V_13 ++ ;
V_199 -> V_70 = V_69 -> V_71 + 1 - V_13 ;
if ( F_64 ( V_211 + V_199 -> V_70 <= V_212 ) ) {
V_199 -> V_201 = V_211 ;
V_211 += V_199 -> V_70 ;
for ( V_205 = 0 ; V_205 < V_199 -> V_70 - 1 ; V_205 ++ , V_13 ++ ) {
int V_213 = V_69 -> V_73 [ V_13 ] . V_9 - 1 ;
V_200 [ V_199 -> V_201 + V_205 ] = V_213 ;
}
V_200 [ V_199 -> V_201 + V_205 ] = V_24 - V_10 ;
}
F_69 ( & V_199 -> V_113 , V_86 ) ;
F_67 ( V_214 ) ;
F_118 () ;
return 1 ;
}
static int F_128 ( struct V_68 * V_69 , struct V_64 * V_65 ,
struct V_7 * V_8 , int V_215 , T_1 V_202 )
{
if ( ! V_8 -> V_197 && ( V_8 -> V_216 == 2 ) &&
F_125 ( V_69 , V_8 , V_202 ) ) {
int V_5 = F_121 ( V_69 , V_8 , V_65 , V_8 -> V_40 ) ;
if ( ! V_5 )
return 0 ;
if ( V_5 == 2 )
V_8 -> V_40 = 2 ;
if ( ! V_215 && V_5 != 2 )
if ( ! F_123 ( V_69 , V_8 ) )
return 0 ;
F_4 () ;
} else
if ( F_58 ( ! V_2 ) )
return 0 ;
return 1 ;
}
static inline int F_128 ( struct V_68 * V_69 ,
struct V_64 * V_65 , struct V_7 * V_8 ,
int V_215 , T_1 V_202 )
{
return 1 ;
}
static void F_129 ( struct V_68 * V_69 )
{
#ifdef F_57
struct V_7 * V_8 , * V_217 = NULL ;
unsigned int V_13 , V_218 ;
T_1 V_202 = 0 ;
for ( V_13 = 0 ; V_13 < V_69 -> V_71 ; V_13 ++ ) {
V_8 = V_69 -> V_73 + V_13 ;
if ( V_202 != V_8 -> V_219 ) {
F_8 () ;
F_95 ( 1 , L_87 ,
V_69 -> V_71 , V_13 ,
( unsigned long long ) V_202 ,
( unsigned long long ) V_8 -> V_219 ) ;
return;
}
V_218 = V_8 -> V_9 - 1 ;
if ( F_6 ( V_218 >= V_97 ) )
return;
if ( V_217 && ( V_217 -> V_196 !=
V_8 -> V_196 ) )
V_202 = 0 ;
V_202 = F_130 ( V_202 , V_218 ) ;
V_217 = V_8 ;
}
if ( V_202 != V_69 -> V_220 ) {
F_8 () ;
F_95 ( 1 , L_88 ,
V_69 -> V_71 , V_13 ,
( unsigned long long ) V_202 ,
( unsigned long long ) V_69 -> V_220 ) ;
}
#endif
}
static void
F_131 ( struct V_7 * V_65 )
{
struct V_6 * V_24 = F_9 ( V_65 ) ;
F_31 ( L_28 ) ;
F_31 ( L_74 ) ;
F_31 ( L_75 ) ;
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
F_132 ( struct V_68 * V_69 , struct V_7 * V_110 ,
enum V_54 V_221 , enum V_54 V_182 )
{
if ( ! F_7 () || V_134 )
return 0 ;
F_31 ( L_89 ) ;
F_31 ( L_90 ) ;
F_46 () ;
F_31 ( L_91 ) ;
F_31 ( L_92 ,
V_150 [ V_221 ] , V_150 [ V_182 ] ) ;
F_31 ( L_93 ,
V_69 -> V_72 , F_45 ( V_69 ) ,
F_133 ( V_69 ) , F_111 () >> V_171 ,
F_134 ( V_69 ) , F_112 () >> V_173 ,
F_135 ( V_69 ) ,
F_136 ( V_69 ) ) ;
F_42 ( V_110 ) ;
F_31 ( L_94 , V_150 [ V_221 ] ) ;
F_89 ( F_9 ( V_110 ) -> V_151 + V_221 , 1 ) ;
F_137 ( V_69 ) ;
F_31 ( L_80 ) ;
F_131 ( V_110 ) ;
F_44 ( V_69 ) ;
F_31 ( L_43 ) ;
F_32 () ;
return 0 ;
}
static inline int
F_138 ( struct V_68 * V_69 , struct V_7 * V_110 ,
enum V_54 V_182 , enum V_54 V_222 )
{
if ( F_58 ( F_9 ( V_110 ) -> V_57 & ( 1 << V_222 ) ) )
return F_132 ( V_69 , V_110 , V_222 , V_182 ) ;
return 1 ;
}
static int
F_139 ( struct V_68 * V_69 ,
struct V_106 * V_142 , struct V_106 * V_223 ,
struct V_7 * V_110 , int V_224 ,
const char * V_169 )
{
struct V_106 * V_113 = V_223 ;
struct V_106 * V_225 = NULL ;
int V_70 ;
if ( ! F_7 () || V_134 )
return 0 ;
F_31 ( L_95 ) ;
F_31 ( L_96 ) ;
F_46 () ;
F_31 ( L_97 ) ;
F_31 ( L_98 ,
V_69 -> V_72 , F_45 ( V_69 ) ) ;
F_42 ( V_110 ) ;
if ( V_224 )
F_31 ( L_99 , V_169 ) ;
else
F_31 ( L_100 , V_169 ) ;
F_40 ( V_223 -> V_24 ) ;
F_31 ( L_101 ) ;
F_31 ( L_80 ) ;
V_70 = F_82 ( V_223 ) ;
do {
if ( V_70 == 0 && ( V_113 != V_142 ) ) {
F_31 ( L_53 , V_153 ) ;
break;
}
V_225 = V_113 ;
V_113 = F_81 ( V_113 ) ;
V_70 -- ;
} while ( V_113 && V_113 != V_142 && ( V_70 >= 0 ) );
if ( V_224 )
F_109 ( V_142 , V_223 ,
V_225 ? V_225 -> V_24 : V_142 -> V_24 , V_223 -> V_24 ) ;
else
F_109 ( V_223 , V_142 ,
V_225 ? V_225 -> V_24 : V_223 -> V_24 , V_142 -> V_24 ) ;
F_44 ( V_69 ) ;
F_31 ( L_102 ) ;
if ( ! F_29 ( & V_142 -> V_43 ) )
return 0 ;
F_108 ( V_223 , V_142 ) ;
F_31 ( L_43 ) ;
F_32 () ;
return 0 ;
}
static int
F_140 ( struct V_68 * V_69 , struct V_7 * V_110 ,
enum V_54 V_55 , const char * V_169 )
{
int V_5 ;
struct V_106 V_142 ;
struct V_106 * V_141 ( V_127 ) ;
V_142 . V_122 = NULL ;
V_142 . V_24 = F_9 ( V_110 ) ;
V_5 = F_105 ( & V_142 , V_55 , & V_127 ) ;
if ( V_5 < 0 )
return F_94 ( V_5 ) ;
if ( V_5 == 1 )
return V_5 ;
return F_139 ( V_69 , & V_142 , V_127 ,
V_110 , 1 , V_169 ) ;
}
static int
F_141 ( struct V_68 * V_69 , struct V_7 * V_110 ,
enum V_54 V_55 , const char * V_169 )
{
int V_5 ;
struct V_106 V_142 ;
struct V_106 * V_141 ( V_127 ) ;
V_142 . V_122 = NULL ;
V_142 . V_24 = F_9 ( V_110 ) ;
V_5 = F_106 ( & V_142 , V_55 , & V_127 ) ;
if ( V_5 < 0 )
return F_94 ( V_5 ) ;
if ( V_5 == 1 )
return V_5 ;
return F_139 ( V_69 , & V_142 , V_127 ,
V_110 , 0 , V_169 ) ;
}
void F_137 ( struct V_68 * V_69 )
{
F_31 ( L_103 , V_69 -> V_226 ) ;
F_31 ( L_104 , V_69 -> V_227 ) ;
F_43 ( V_69 -> V_228 ) ;
F_31 ( L_105 , V_69 -> V_229 ) ;
F_43 ( V_69 -> V_230 ) ;
F_31 ( L_106 , V_69 -> V_231 ) ;
F_43 ( V_69 -> V_232 ) ;
F_31 ( L_107 , V_69 -> V_233 ) ;
F_43 ( V_69 -> V_234 ) ;
}
static int F_142 ( struct V_6 * V_24 )
{
#if V_235
return F_27 ( V_24 ) ;
#endif
return 0 ;
}
static int F_143 ( struct V_6 * V_24 )
{
#if V_236
return F_27 ( V_24 ) ;
#endif
return 0 ;
}
static int F_144 ( struct V_6 * V_24 )
{
#if V_237
return F_27 ( V_24 ) ;
#endif
return 0 ;
}
static inline int F_145 ( enum V_54 V_55 ,
struct V_6 * V_24 )
{
return V_238 [ V_55 >> 2 ] ( V_24 ) ;
}
static int
F_146 ( struct V_68 * V_69 , struct V_7 * V_110 ,
enum V_54 V_182 )
{
int V_239 = F_115 ( V_182 ) ;
int V_40 = V_182 & 1 ;
int V_184 = V_182 & 2 ;
T_5 V_58 = V_184 ?
F_141 : F_140 ;
if ( ! F_138 ( V_69 , V_110 , V_182 , V_239 ) )
return 0 ;
if ( ( ! V_40 || ! V_184 || V_240 ) &&
! V_58 ( V_69 , V_110 , V_239 , F_114 ( V_182 & ~ 1 ) ) )
return 0 ;
if ( ! V_40 ) {
if ( ! F_138 ( V_69 , V_110 , V_182 , V_239 + 1 ) )
return 0 ;
if ( V_240 &&
! V_58 ( V_69 , V_110 , V_239 + 1 ,
F_114 ( V_182 + 1 ) ) )
return 0 ;
}
if ( F_145 ( V_182 , F_9 ( V_110 ) ) )
return 2 ;
return 1 ;
}
static int
F_147 ( struct V_68 * V_69 , enum V_241 V_242 )
{
enum V_54 V_243 ;
struct V_7 * V_8 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_69 -> V_71 ; V_13 ++ ) {
V_8 = V_69 -> V_73 + V_13 ;
V_243 = 2 + ( V_242 << 2 ) ;
if ( V_8 -> V_40 )
V_243 += 1 ;
F_148 ( V_243 >= V_148 ) ;
if ( F_9 ( V_8 ) -> V_52 == V_244 . V_66 )
continue;
if ( ! F_149 ( V_69 , V_8 , V_243 ) )
return 0 ;
}
return 1 ;
}
static void F_150 ( unsigned long V_12 )
{
struct V_68 * V_69 = V_3 ;
V_69 -> V_174 = 1 ;
if ( ! F_147 ( V_69 , V_245 ) )
return;
if ( V_69 -> V_175 )
if ( ! F_147 ( V_69 , V_246 ) )
return;
V_69 -> V_228 = V_12 ;
V_69 -> V_227 = ++ V_69 -> V_226 ;
F_67 ( V_247 ) ;
}
void F_151 ( unsigned long V_12 )
{
F_152 ( V_248 , V_12 ) ;
if ( F_58 ( ! V_2 || V_3 -> V_4 ) )
return;
if ( F_58 ( V_3 -> V_174 ) ) {
F_153 ( V_249 ) ;
return;
}
if ( F_6 ( ! F_127 () ) )
return;
if ( F_6 ( F_58 ( V_250 ) ) )
return;
if ( F_6 ( V_3 -> V_170 ) )
return;
V_3 -> V_4 = 1 ;
F_150 ( V_12 ) ;
V_3 -> V_4 = 0 ;
}
void F_154 ( void )
{
F_151 ( V_248 ) ;
}
void F_155 ( unsigned long V_12 )
{
struct V_68 * V_69 = V_3 ;
F_156 ( V_248 , V_12 ) ;
if ( F_58 ( ! V_2 || V_3 -> V_4 ) )
return;
if ( F_6 ( ! F_127 () ) )
return;
if ( V_69 -> V_174 ) {
V_69 -> V_174 = 0 ;
V_69 -> V_230 = V_12 ;
V_69 -> V_229 = ++ V_69 -> V_226 ;
F_67 ( V_251 ) ;
} else
F_67 ( V_252 ) ;
}
void F_157 ( void )
{
F_155 ( V_248 ) ;
}
void F_158 ( unsigned long V_12 )
{
struct V_68 * V_69 = V_3 ;
if ( F_58 ( ! V_2 || V_3 -> V_4 ) )
return;
if ( F_6 ( ! F_127 () ) )
return;
if ( V_69 -> V_175 ) {
F_67 ( V_253 ) ;
return;
}
V_3 -> V_4 = 1 ;
V_69 -> V_175 = 1 ;
V_69 -> V_232 = V_12 ;
V_69 -> V_231 = ++ V_69 -> V_226 ;
F_67 ( V_254 ) ;
if ( V_69 -> V_174 )
F_147 ( V_69 , V_246 ) ;
V_3 -> V_4 = 0 ;
}
void F_159 ( unsigned long V_12 )
{
struct V_68 * V_69 = V_3 ;
if ( F_58 ( ! V_2 || V_3 -> V_4 ) )
return;
if ( F_6 ( ! F_127 () ) )
return;
if ( V_69 -> V_175 ) {
V_69 -> V_175 = 0 ;
V_69 -> V_234 = V_12 ;
V_69 -> V_233 = ++ V_69 -> V_226 ;
F_67 ( V_255 ) ;
F_6 ( ! F_112 () ) ;
} else
F_67 ( V_256 ) ;
}
static void F_160 ( T_6 V_257 , unsigned long V_94 )
{
struct V_68 * V_69 = V_3 ;
if ( F_58 ( ! V_2 ) )
return;
if ( ! ( V_257 & V_258 ) )
return;
if ( ( V_69 -> V_94 & V_259 ) && ! ( V_257 & V_260 ) )
return;
if ( ! ( V_257 & V_261 ) )
return;
if ( F_6 ( F_161 ( V_94 ) ) )
return;
F_147 ( V_69 , V_262 ) ;
}
void F_162 ( T_6 V_257 )
{
unsigned long V_94 ;
if ( F_58 ( V_3 -> V_4 ) )
return;
F_65 ( V_94 ) ;
F_163 ( V_94 ) ;
V_3 -> V_4 = 1 ;
F_160 ( V_257 , V_94 ) ;
V_3 -> V_4 = 0 ;
F_66 ( V_94 ) ;
}
static int F_164 ( struct V_68 * V_69 , struct V_7 * V_8 )
{
if ( ! V_8 -> V_197 ) {
if ( V_8 -> V_40 ) {
if ( V_69 -> V_170 )
if ( ! F_149 ( V_69 , V_8 ,
V_263 ) )
return 0 ;
if ( V_69 -> V_172 )
if ( ! F_149 ( V_69 , V_8 ,
V_264 ) )
return 0 ;
} else {
if ( V_69 -> V_170 )
if ( ! F_149 ( V_69 , V_8 , V_265 ) )
return 0 ;
if ( V_69 -> V_172 )
if ( ! F_149 ( V_69 , V_8 , V_266 ) )
return 0 ;
}
}
if ( ! V_8 -> V_267 ) {
if ( V_8 -> V_40 ) {
if ( ! F_149 ( V_69 , V_8 ,
V_268 ) )
return 0 ;
if ( V_69 -> V_175 )
if ( ! F_149 ( V_69 , V_8 ,
V_269 ) )
return 0 ;
} else {
if ( ! F_149 ( V_69 , V_8 ,
V_270 ) )
return 0 ;
if ( V_69 -> V_175 )
if ( ! F_149 ( V_69 , V_8 ,
V_271 ) )
return 0 ;
}
}
if ( ! V_8 -> V_197 && ( V_69 -> V_272 & V_261 ) ) {
if ( V_8 -> V_40 ) {
if ( ! F_149 ( V_69 , V_8 , V_273 ) )
return 0 ;
} else {
if ( ! F_149 ( V_69 , V_8 , V_274 ) )
return 0 ;
}
}
return 1 ;
}
static int F_165 ( struct V_68 * V_69 ,
struct V_7 * V_8 )
{
unsigned int V_70 = V_69 -> V_71 ;
V_8 -> V_196 = 2 * ( V_69 -> V_170 ? 1 : 0 ) +
V_69 -> V_172 ;
if ( V_70 ) {
struct V_7 * V_217 ;
V_217 = V_69 -> V_73 + V_70 - 1 ;
if ( V_217 -> V_196 != V_8 -> V_196 )
return 1 ;
}
return 0 ;
}
static inline
int F_146 ( struct V_68 * V_69 , struct V_7 * V_110 ,
enum V_54 V_182 )
{
F_79 ( 1 ) ;
return 1 ;
}
static inline int F_164 ( struct V_68 * V_69 ,
struct V_7 * V_8 )
{
return 1 ;
}
static inline int F_165 ( struct V_68 * V_69 ,
struct V_7 * V_8 )
{
return 0 ;
}
void F_162 ( T_6 V_257 )
{
}
static int F_149 ( struct V_68 * V_69 , struct V_7 * V_110 ,
enum V_54 V_182 )
{
unsigned int V_275 = 1 << V_182 , V_5 = 1 ;
if ( F_64 ( F_9 ( V_110 ) -> V_57 & V_275 ) )
return 1 ;
if ( ! F_1 () )
return 0 ;
if ( F_58 ( F_9 ( V_110 ) -> V_57 & V_275 ) ) {
F_4 () ;
return 1 ;
}
F_9 ( V_110 ) -> V_57 |= V_275 ;
if ( ! F_29 ( F_9 ( V_110 ) -> V_151 + V_182 ) )
return 0 ;
switch ( V_182 ) {
#define F_38 ( T_2 ) \
case LOCK_USED_IN_##__STATE: \
case LOCK_USED_IN_##__STATE##_READ: \
case LOCK_ENABLED_##__STATE: \
case LOCK_ENABLED_##__STATE##_READ:
#include "lockdep_states.h"
#undef F_38
V_5 = F_146 ( V_69 , V_110 , V_182 ) ;
if ( ! V_5 )
return 0 ;
break;
case V_276 :
F_166 ( V_98 ) ;
break;
default:
if ( ! F_7 () )
return 0 ;
F_79 ( 1 ) ;
return 0 ;
}
F_4 () ;
if ( V_5 == 2 ) {
F_31 ( L_108 , V_150 [ V_182 ] ) ;
F_42 ( V_110 ) ;
F_137 ( V_69 ) ;
F_32 () ;
}
return V_5 ;
}
void F_167 ( struct V_64 * V_65 , const char * V_61 ,
struct V_92 * V_52 , int V_63 )
{
memset ( V_65 , 0 , sizeof( * V_65 ) ) ;
#ifdef F_168
V_65 -> V_26 = F_169 () ;
#endif
if ( F_6 ( ! V_61 ) ) {
V_65 -> V_61 = L_109 ;
return;
}
V_65 -> V_61 = V_61 ;
if ( F_6 ( ! V_52 ) )
return;
if ( ! F_49 ( V_52 ) ) {
F_31 ( L_110 , V_52 ) ;
F_6 ( 1 ) ;
return;
}
V_65 -> V_52 = V_52 ;
if ( F_58 ( ! V_2 ) )
return;
if ( V_63 )
F_63 ( V_65 , V_63 , 1 ) ;
}
static int F_170 ( struct V_64 * V_65 , unsigned int V_63 ,
int V_197 , int V_40 , int V_216 , int V_267 ,
struct V_64 * V_193 , unsigned long V_12 ,
int V_277 )
{
struct V_68 * V_69 = V_3 ;
struct V_6 * V_24 = NULL ;
struct V_7 * V_8 ;
unsigned int V_70 , V_218 ;
int V_215 = 0 ;
int V_9 ;
T_1 V_202 ;
if ( ! V_278 )
V_216 = 1 ;
if ( F_58 ( ! V_2 ) )
return 0 ;
if ( F_6 ( ! F_127 () ) )
return 0 ;
if ( V_65 -> V_52 == & V_244 )
V_216 = 1 ;
if ( V_63 < V_105 )
V_24 = V_65 -> V_104 [ V_63 ] ;
if ( F_58 ( ! V_24 ) ) {
V_24 = F_63 ( V_65 , V_63 , 0 ) ;
if ( ! V_24 )
return 0 ;
}
F_171 ( ( V_279 * ) & V_24 -> V_147 ) ;
if ( F_48 ( V_24 ) ) {
F_31 ( L_111 , V_24 -> V_52 , V_24 -> V_61 ) ;
if ( V_24 -> V_62 > 1 )
F_31 ( L_5 , V_24 -> V_62 ) ;
F_31 ( L_21 ) ;
F_32 () ;
}
V_70 = V_69 -> V_71 ;
if ( F_6 ( V_70 >= V_280 ) )
return 0 ;
V_9 = V_24 - V_10 + 1 ;
if ( V_70 ) {
V_8 = V_69 -> V_73 + V_70 - 1 ;
if ( V_8 -> V_9 == V_9 && V_193 ) {
if ( V_8 -> V_277 )
V_8 -> V_277 ++ ;
else
V_8 -> V_277 = 2 ;
return 1 ;
}
}
V_8 = V_69 -> V_73 + V_70 ;
if ( F_6 ( ! V_24 ) )
return 0 ;
V_8 -> V_9 = V_9 ;
V_8 -> V_67 = V_12 ;
V_8 -> V_192 = V_65 ;
V_8 -> V_193 = V_193 ;
V_8 -> V_197 = V_197 ;
V_8 -> V_40 = V_40 ;
V_8 -> V_216 = V_216 ;
V_8 -> V_267 = ! ! V_267 ;
V_8 -> V_277 = V_277 ;
#ifdef F_168
V_8 -> V_281 = 0 ;
V_8 -> V_39 = F_10 () ;
#endif
if ( V_216 == 2 && ! F_164 ( V_69 , V_8 ) )
return 0 ;
if ( ! F_149 ( V_69 , V_8 , V_276 ) )
return 0 ;
V_218 = V_24 - V_10 ;
if ( F_6 ( V_218 >= V_97 ) )
return 0 ;
V_202 = V_69 -> V_220 ;
if ( ! V_70 ) {
if ( F_6 ( V_202 != 0 ) )
return 0 ;
V_215 = 1 ;
}
V_8 -> V_219 = V_202 ;
if ( F_165 ( V_69 , V_8 ) ) {
V_202 = 0 ;
V_215 = 1 ;
}
V_202 = F_130 ( V_202 , V_218 ) ;
if ( ! F_128 ( V_69 , V_65 , V_8 , V_215 , V_202 ) )
return 0 ;
V_69 -> V_220 = V_202 ;
V_69 -> V_71 ++ ;
F_129 ( V_69 ) ;
#ifdef F_57
if ( F_58 ( ! V_2 ) )
return 0 ;
#endif
if ( F_58 ( V_69 -> V_71 >= V_280 ) ) {
F_8 () ;
F_31 ( L_112 ) ;
F_31 ( L_2 ) ;
F_32 () ;
return 0 ;
}
if ( F_58 ( V_69 -> V_71 > V_282 ) )
V_282 = V_69 -> V_71 ;
return 1 ;
}
static int
F_172 ( struct V_68 * V_69 , struct V_64 * V_65 ,
unsigned long V_12 )
{
if ( ! F_8 () )
return 0 ;
if ( V_134 )
return 0 ;
F_31 ( L_113 ) ;
F_31 ( L_114 ) ;
F_31 ( L_115 ) ;
F_31 ( L_116 ,
V_69 -> V_72 , F_45 ( V_69 ) ) ;
F_41 ( V_65 ) ;
F_31 ( L_117 ) ;
F_43 ( V_12 ) ;
F_31 ( L_118 ) ;
F_31 ( L_80 ) ;
F_44 ( V_69 ) ;
F_31 ( L_43 ) ;
F_32 () ;
return 0 ;
}
static int F_173 ( struct V_68 * V_69 , struct V_64 * V_65 ,
unsigned long V_12 )
{
if ( F_58 ( ! V_2 ) )
return 0 ;
if ( F_6 ( ! F_127 () ) )
return 0 ;
if ( V_69 -> V_71 <= 0 )
return F_172 ( V_69 , V_65 , V_12 ) ;
return 1 ;
}
static int F_174 ( struct V_7 * V_8 , struct V_64 * V_65 )
{
if ( V_8 -> V_192 == V_65 )
return 1 ;
if ( V_8 -> V_277 ) {
struct V_6 * V_24 = V_65 -> V_104 [ 0 ] ;
if ( ! V_24 )
V_24 = F_56 ( V_65 , 0 ) ;
if ( ! V_24 )
return 0 ;
if ( F_6 ( ! V_8 -> V_193 ) )
return 0 ;
if ( V_8 -> V_9 == V_24 - V_10 + 1 )
return 1 ;
}
return 0 ;
}
static int
F_175 ( struct V_64 * V_65 , const char * V_61 ,
struct V_92 * V_52 , unsigned int V_63 ,
unsigned long V_12 )
{
struct V_68 * V_69 = V_3 ;
struct V_7 * V_8 , * V_217 ;
struct V_6 * V_24 ;
unsigned int V_70 ;
int V_13 ;
V_70 = V_69 -> V_71 ;
if ( F_6 ( ! V_70 ) )
return 0 ;
V_217 = NULL ;
for ( V_13 = V_70 - 1 ; V_13 >= 0 ; V_13 -- ) {
V_8 = V_69 -> V_73 + V_13 ;
if ( V_217 && V_217 -> V_196 != V_8 -> V_196 )
break;
if ( F_174 ( V_8 , V_65 ) )
goto V_283;
V_217 = V_8 ;
}
return F_172 ( V_69 , V_65 , V_12 ) ;
V_283:
F_167 ( V_65 , V_61 , V_52 , 0 ) ;
V_24 = F_63 ( V_65 , V_63 , 0 ) ;
V_8 -> V_9 = V_24 - V_10 + 1 ;
V_69 -> V_71 = V_13 ;
V_69 -> V_220 = V_8 -> V_219 ;
for (; V_13 < V_70 ; V_13 ++ ) {
V_8 = V_69 -> V_73 + V_13 ;
if ( ! F_170 ( V_8 -> V_192 ,
F_9 ( V_8 ) -> V_63 , V_8 -> V_197 ,
V_8 -> V_40 , V_8 -> V_216 , V_8 -> V_267 ,
V_8 -> V_193 , V_8 -> V_67 ,
V_8 -> V_277 ) )
return 0 ;
}
if ( F_6 ( V_69 -> V_71 != V_70 ) )
return 0 ;
return 1 ;
}
static int
F_176 ( struct V_68 * V_69 ,
struct V_64 * V_65 , unsigned long V_12 )
{
struct V_7 * V_8 , * V_217 ;
unsigned int V_70 ;
int V_13 ;
V_70 = V_69 -> V_71 ;
if ( F_6 ( ! V_70 ) )
return 0 ;
V_217 = NULL ;
for ( V_13 = V_70 - 1 ; V_13 >= 0 ; V_13 -- ) {
V_8 = V_69 -> V_73 + V_13 ;
if ( V_217 && V_217 -> V_196 != V_8 -> V_196 )
break;
if ( F_174 ( V_8 , V_65 ) )
goto V_283;
V_217 = V_8 ;
}
return F_172 ( V_69 , V_65 , V_12 ) ;
V_283:
if ( V_8 -> V_192 == V_65 )
F_24 ( V_8 ) ;
if ( V_8 -> V_277 ) {
V_8 -> V_277 -- ;
if ( V_8 -> V_277 ) {
return 1 ;
}
}
V_69 -> V_71 = V_13 ;
V_69 -> V_220 = V_8 -> V_219 ;
for ( V_13 ++ ; V_13 < V_70 ; V_13 ++ ) {
V_8 = V_69 -> V_73 + V_13 ;
if ( ! F_170 ( V_8 -> V_192 ,
F_9 ( V_8 ) -> V_63 , V_8 -> V_197 ,
V_8 -> V_40 , V_8 -> V_216 , V_8 -> V_267 ,
V_8 -> V_193 , V_8 -> V_67 ,
V_8 -> V_277 ) )
return 0 ;
}
if ( F_6 ( V_69 -> V_71 != V_70 - 1 ) )
return 0 ;
return 1 ;
}
static int F_177 ( struct V_68 * V_69 ,
struct V_64 * V_65 , unsigned long V_12 )
{
struct V_7 * V_8 ;
unsigned int V_70 ;
V_70 = V_69 -> V_71 - 1 ;
V_8 = V_69 -> V_73 + V_70 ;
if ( V_8 -> V_192 != V_65 || V_8 -> V_277 )
return F_176 ( V_69 , V_65 , V_12 ) ;
V_69 -> V_71 -- ;
if ( F_6 ( ! V_70 && ( V_8 -> V_219 != 0 ) ) )
return 0 ;
V_69 -> V_220 = V_8 -> V_219 ;
F_24 ( V_8 ) ;
#ifdef F_57
V_8 -> V_219 = 0 ;
V_8 -> V_9 = 0 ;
V_8 -> V_67 = 0 ;
V_8 -> V_196 = 0 ;
#endif
return 1 ;
}
static void
F_178 ( struct V_64 * V_65 , int V_284 , unsigned long V_12 )
{
struct V_68 * V_69 = V_3 ;
if ( ! F_173 ( V_69 , V_65 , V_12 ) )
return;
if ( V_284 ) {
if ( ! F_177 ( V_69 , V_65 , V_12 ) )
return;
} else {
if ( ! F_176 ( V_69 , V_65 , V_12 ) )
return;
}
F_129 ( V_69 ) ;
}
static int F_179 ( struct V_64 * V_65 )
{
struct V_68 * V_69 = V_3 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_69 -> V_71 ; V_13 ++ ) {
struct V_7 * V_8 = V_69 -> V_73 + V_13 ;
if ( F_174 ( V_8 , V_65 ) )
return 1 ;
}
return 0 ;
}
static void F_163 ( unsigned long V_94 )
{
#if F_180 ( V_285 ) && F_180 ( F_57 ) && \
F_180 ( V_286 )
if ( ! V_2 )
return;
if ( F_161 ( V_94 ) ) {
if ( F_6 ( V_3 -> V_174 ) ) {
F_31 ( L_119 ) ;
}
} else {
if ( F_6 ( ! V_3 -> V_174 ) ) {
F_31 ( L_120 ) ;
}
}
if ( ! F_111 () ) {
if ( F_112 () )
F_6 ( V_3 -> V_175 ) ;
else
F_6 ( ! V_3 -> V_175 ) ;
}
if ( ! V_2 )
F_137 ( V_3 ) ;
#endif
}
void F_181 ( struct V_64 * V_65 , const char * V_61 ,
struct V_92 * V_52 , unsigned int V_63 ,
unsigned long V_12 )
{
unsigned long V_94 ;
if ( F_58 ( V_3 -> V_4 ) )
return;
F_65 ( V_94 ) ;
V_3 -> V_4 = 1 ;
F_163 ( V_94 ) ;
if ( F_175 ( V_65 , V_61 , V_52 , V_63 , V_12 ) )
F_129 ( V_3 ) ;
V_3 -> V_4 = 0 ;
F_66 ( V_94 ) ;
}
void F_182 ( struct V_64 * V_65 , unsigned int V_63 ,
int V_197 , int V_40 , int V_216 ,
struct V_64 * V_193 , unsigned long V_12 )
{
unsigned long V_94 ;
if ( F_58 ( V_3 -> V_4 ) )
return;
F_65 ( V_94 ) ;
F_163 ( V_94 ) ;
V_3 -> V_4 = 1 ;
F_183 ( V_65 , V_63 , V_197 , V_40 , V_216 , V_193 , V_12 ) ;
F_170 ( V_65 , V_63 , V_197 , V_40 , V_216 ,
F_161 ( V_94 ) , V_193 , V_12 , 0 ) ;
V_3 -> V_4 = 0 ;
F_66 ( V_94 ) ;
}
void F_184 ( struct V_64 * V_65 , int V_284 ,
unsigned long V_12 )
{
unsigned long V_94 ;
if ( F_58 ( V_3 -> V_4 ) )
return;
F_65 ( V_94 ) ;
F_163 ( V_94 ) ;
V_3 -> V_4 = 1 ;
F_185 ( V_65 , V_12 ) ;
F_178 ( V_65 , V_284 , V_12 ) ;
V_3 -> V_4 = 0 ;
F_66 ( V_94 ) ;
}
int F_186 ( struct V_64 * V_65 )
{
unsigned long V_94 ;
int V_5 = 0 ;
if ( F_58 ( V_3 -> V_4 ) )
return 1 ;
F_65 ( V_94 ) ;
F_163 ( V_94 ) ;
V_3 -> V_4 = 1 ;
V_5 = F_179 ( V_65 ) ;
V_3 -> V_4 = 0 ;
F_66 ( V_94 ) ;
return V_5 ;
}
void F_187 ( T_6 V_257 )
{
V_3 -> V_272 = V_257 ;
}
void F_188 ( void )
{
V_3 -> V_272 = 0 ;
}
static int
F_189 ( struct V_68 * V_69 , struct V_64 * V_65 ,
unsigned long V_12 )
{
if ( ! F_8 () )
return 0 ;
if ( V_134 )
return 0 ;
F_31 ( L_89 ) ;
F_31 ( L_121 ) ;
F_31 ( L_91 ) ;
F_31 ( L_122 ,
V_69 -> V_72 , F_45 ( V_69 ) ) ;
F_41 ( V_65 ) ;
F_31 ( L_117 ) ;
F_43 ( V_12 ) ;
F_31 ( L_123 ) ;
F_31 ( L_80 ) ;
F_44 ( V_69 ) ;
F_31 ( L_43 ) ;
F_32 () ;
return 0 ;
}
static void
F_190 ( struct V_64 * V_65 , unsigned long V_12 )
{
struct V_68 * V_69 = V_3 ;
struct V_7 * V_8 , * V_217 ;
struct V_23 * V_25 ;
unsigned int V_70 ;
int V_13 , V_29 , V_30 ;
V_70 = V_69 -> V_71 ;
if ( F_6 ( ! V_70 ) )
return;
V_217 = NULL ;
for ( V_13 = V_70 - 1 ; V_13 >= 0 ; V_13 -- ) {
V_8 = V_69 -> V_73 + V_13 ;
if ( V_217 && V_217 -> V_196 != V_8 -> V_196 )
break;
if ( F_174 ( V_8 , V_65 ) )
goto V_283;
V_217 = V_8 ;
}
F_189 ( V_69 , V_65 , V_12 ) ;
return;
V_283:
if ( V_8 -> V_192 != V_65 )
return;
V_8 -> V_281 = F_10 () ;
V_29 = F_12 ( F_9 ( V_8 ) -> V_29 , V_12 ) ;
V_30 = F_12 ( F_9 ( V_8 ) -> V_30 ,
V_65 -> V_12 ) ;
V_25 = F_20 ( F_9 ( V_8 ) ) ;
if ( V_29 < V_14 )
V_25 -> V_29 [ V_29 ] ++ ;
if ( V_30 < V_14 )
V_25 -> V_30 [ V_30 ] ++ ;
if ( V_65 -> V_26 != F_191 () )
V_25 -> V_35 [ V_287 + ! ! V_8 -> V_40 ] ++ ;
F_22 ( V_25 ) ;
}
static void
F_192 ( struct V_64 * V_65 , unsigned long V_12 )
{
struct V_68 * V_69 = V_3 ;
struct V_7 * V_8 , * V_217 ;
struct V_23 * V_25 ;
unsigned int V_70 ;
T_1 V_288 , V_289 = 0 ;
int V_13 , V_26 ;
V_70 = V_69 -> V_71 ;
if ( F_6 ( ! V_70 ) )
return;
V_217 = NULL ;
for ( V_13 = V_70 - 1 ; V_13 >= 0 ; V_13 -- ) {
V_8 = V_69 -> V_73 + V_13 ;
if ( V_217 && V_217 -> V_196 != V_8 -> V_196 )
break;
if ( F_174 ( V_8 , V_65 ) )
goto V_283;
V_217 = V_8 ;
}
F_189 ( V_69 , V_65 , V_290 ) ;
return;
V_283:
if ( V_8 -> V_192 != V_65 )
return;
V_26 = F_191 () ;
if ( V_8 -> V_281 ) {
V_288 = F_10 () ;
V_289 = V_288 - V_8 -> V_281 ;
V_8 -> V_39 = V_288 ;
}
F_193 ( V_65 , V_12 ) ;
V_25 = F_20 ( F_9 ( V_8 ) ) ;
if ( V_289 ) {
if ( V_8 -> V_40 )
F_13 ( & V_25 -> V_31 , V_289 ) ;
else
F_13 ( & V_25 -> V_32 , V_289 ) ;
}
if ( V_65 -> V_26 != V_26 )
V_25 -> V_35 [ V_291 + ! ! V_8 -> V_40 ] ++ ;
F_22 ( V_25 ) ;
V_65 -> V_26 = V_26 ;
V_65 -> V_12 = V_12 ;
}
void F_194 ( struct V_64 * V_65 , unsigned long V_12 )
{
unsigned long V_94 ;
if ( F_58 ( ! V_38 ) )
return;
if ( F_58 ( V_3 -> V_4 ) )
return;
F_65 ( V_94 ) ;
F_163 ( V_94 ) ;
V_3 -> V_4 = 1 ;
F_195 ( V_65 , V_12 ) ;
F_190 ( V_65 , V_12 ) ;
V_3 -> V_4 = 0 ;
F_66 ( V_94 ) ;
}
void F_196 ( struct V_64 * V_65 , unsigned long V_12 )
{
unsigned long V_94 ;
if ( F_58 ( ! V_38 ) )
return;
if ( F_58 ( V_3 -> V_4 ) )
return;
F_65 ( V_94 ) ;
F_163 ( V_94 ) ;
V_3 -> V_4 = 1 ;
F_192 ( V_65 , V_12 ) ;
V_3 -> V_4 = 0 ;
F_66 ( V_94 ) ;
}
void F_197 ( void )
{
unsigned long V_94 ;
int V_13 ;
F_65 ( V_94 ) ;
V_3 -> V_220 = 0 ;
V_3 -> V_71 = 0 ;
V_3 -> V_4 = 0 ;
memset ( V_3 -> V_73 , 0 , V_280 * sizeof( struct V_7 ) ) ;
V_185 = 0 ;
V_186 = 0 ;
V_187 = 0 ;
V_2 = 1 ;
for ( V_13 = 0 ; V_13 < V_292 ; V_13 ++ )
F_68 ( V_293 + V_13 ) ;
F_66 ( V_94 ) ;
}
static void F_198 ( struct V_6 * V_24 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_107 ; V_13 ++ ) {
if ( V_109 [ V_13 ] . V_24 == V_24 )
F_199 ( & V_109 [ V_13 ] . V_113 ) ;
}
F_199 ( & V_24 -> V_102 ) ;
F_199 ( & V_24 -> V_99 ) ;
V_24 -> V_52 = NULL ;
}
static inline int F_200 ( const void * V_82 , void * V_78 , unsigned long V_294 )
{
return V_82 >= V_78 && V_82 < V_78 + V_294 ;
}
void F_201 ( void * V_78 , unsigned long V_294 )
{
struct V_6 * V_24 , * V_166 ;
struct V_85 * V_111 ;
unsigned long V_94 ;
int V_13 ;
int V_295 ;
F_65 ( V_94 ) ;
V_295 = F_1 () ;
for ( V_13 = 0 ; V_13 < V_296 ; V_13 ++ ) {
V_111 = V_297 + V_13 ;
if ( F_85 ( V_111 ) )
continue;
F_202 (class, next, head, hash_entry) {
if ( F_200 ( V_24 -> V_52 , V_78 , V_294 ) )
F_198 ( V_24 ) ;
else if ( F_200 ( V_24 -> V_61 , V_78 , V_294 ) )
F_198 ( V_24 ) ;
}
}
if ( V_295 )
F_4 () ;
F_66 ( V_94 ) ;
}
void F_203 ( struct V_64 * V_65 )
{
struct V_6 * V_24 , * V_166 ;
struct V_85 * V_111 ;
unsigned long V_94 ;
int V_13 , V_205 ;
int V_295 ;
F_65 ( V_94 ) ;
for ( V_205 = 0 ; V_205 < V_90 ; V_205 ++ ) {
V_24 = F_56 ( V_65 , V_205 ) ;
if ( V_24 )
F_198 ( V_24 ) ;
}
V_295 = F_1 () ;
for ( V_13 = 0 ; V_13 < V_296 ; V_13 ++ ) {
V_111 = V_297 + V_13 ;
if ( F_85 ( V_111 ) )
continue;
F_202 (class, next, head, hash_entry) {
int F_84 = 0 ;
for ( V_205 = 0 ; V_205 < V_105 ; V_205 ++ )
F_84 |= V_24 == V_65 -> V_104 [ V_205 ] ;
if ( F_58 ( F_84 ) ) {
if ( F_7 () )
F_79 ( 1 ) ;
goto V_298;
}
}
}
if ( V_295 )
F_4 () ;
V_298:
F_66 ( V_94 ) ;
}
void F_59 ( void )
{
int V_13 ;
if ( V_87 )
return;
for ( V_13 = 0 ; V_13 < V_296 ; V_13 ++ )
F_68 ( V_297 + V_13 ) ;
for ( V_13 = 0 ; V_13 < V_292 ; V_13 ++ )
F_68 ( V_293 + V_13 ) ;
V_87 = 1 ;
}
void T_7 F_204 ( void )
{
F_31 ( L_124 ) ;
F_31 ( L_125 , V_90 ) ;
F_31 ( L_126 , V_280 ) ;
F_31 ( L_127 , V_97 ) ;
F_31 ( L_128 , V_296 ) ;
F_31 ( L_129 , V_108 ) ;
F_31 ( L_130 , V_209 ) ;
F_31 ( L_131 , V_292 ) ;
F_31 ( L_132 ,
( sizeof( struct V_6 ) * V_97 +
sizeof( struct V_85 ) * V_296 +
sizeof( struct V_106 ) * V_108 +
sizeof( struct V_198 ) * V_209 +
sizeof( struct V_85 ) * V_292
#ifdef V_285
+ sizeof( struct V_114 )
#endif
) / 1024
) ;
F_31 ( L_133 ,
sizeof( struct V_7 ) * V_280 ) ;
#ifdef F_57
if ( V_88 ) {
F_31 ( L_134 ) ;
F_31 ( L_135 ) ;
F_89 ( & V_89 , 0 ) ;
}
#endif
}
static void
F_205 ( struct V_68 * V_69 , const void * V_299 ,
const void * V_300 , struct V_7 * V_8 )
{
if ( ! F_8 () )
return;
if ( V_134 )
return;
F_31 ( L_136 ) ;
F_31 ( L_137 ) ;
F_31 ( L_138 ) ;
F_31 ( L_139 ,
V_69 -> V_72 , F_45 ( V_69 ) , V_299 , V_300 - 1 ) ;
F_42 ( V_8 ) ;
F_44 ( V_69 ) ;
F_31 ( L_43 ) ;
F_32 () ;
}
static inline int F_206 ( const void * V_299 , unsigned long V_301 ,
const void * V_302 , unsigned long V_303 )
{
return V_302 + V_303 <= V_299 ||
V_299 + V_301 <= V_302 ;
}
void F_207 ( const void * V_299 , unsigned long V_301 )
{
struct V_68 * V_69 = V_3 ;
struct V_7 * V_8 ;
unsigned long V_94 ;
int V_13 ;
if ( F_58 ( ! V_2 ) )
return;
F_99 ( V_94 ) ;
for ( V_13 = 0 ; V_13 < V_69 -> V_71 ; V_13 ++ ) {
V_8 = V_69 -> V_73 + V_13 ;
if ( F_206 ( V_299 , V_301 , V_8 -> V_192 ,
sizeof( * V_8 -> V_192 ) ) )
continue;
F_205 ( V_69 , V_299 , V_299 + V_301 , V_8 ) ;
break;
}
F_100 ( V_94 ) ;
}
static void F_208 ( struct V_68 * V_69 )
{
if ( ! F_8 () )
return;
if ( V_134 )
return;
F_31 ( L_113 ) ;
F_31 ( L_140 ) ;
F_31 ( L_115 ) ;
F_31 ( L_141 ,
V_69 -> V_72 , F_45 ( V_69 ) ) ;
F_44 ( V_69 ) ;
F_31 ( L_43 ) ;
F_32 () ;
}
void F_209 ( struct V_68 * V_304 )
{
if ( F_58 ( V_304 -> V_71 > 0 ) )
F_208 ( V_304 ) ;
}
void F_210 ( void )
{
struct V_68 * V_305 , * V_306 ;
int V_84 = 10 ;
int V_307 = 1 ;
if ( F_58 ( ! V_2 ) ) {
F_31 ( L_142 ) ;
return;
}
F_31 ( L_143 ) ;
V_308:
if ( ! F_211 ( & V_309 ) ) {
if ( V_84 == 10 )
F_31 ( L_144 ) ;
if ( V_84 ) {
V_84 -- ;
F_31 ( L_145 , 10 - V_84 ) ;
F_212 ( 200 ) ;
goto V_308;
}
F_31 ( L_146 ) ;
V_307 = 0 ;
} else {
if ( V_84 != 10 )
F_31 ( V_310 L_147 ) ;
}
F_213 (g, p) {
if ( V_306 -> V_183 == V_311 && V_306 != V_3 )
continue;
if ( V_306 -> V_71 )
F_44 ( V_306 ) ;
if ( ! V_307 )
if ( F_211 ( & V_309 ) )
V_307 = 1 ;
} F_214 ( V_305 , V_306 ) ;
F_31 ( L_21 ) ;
F_31 ( L_148 ) ;
if ( V_307 )
F_215 ( & V_309 ) ;
}
void F_216 ( struct V_68 * V_304 )
{
if ( F_58 ( ! V_2 ) ) {
F_31 ( L_142 ) ;
return;
}
F_44 ( V_304 ) ;
}
void F_217 ( void )
{
struct V_68 * V_69 = V_3 ;
if ( F_58 ( V_69 -> V_71 ) ) {
if ( ! F_8 () )
return;
F_31 ( L_149 ) ;
F_31 ( L_150 ) ;
F_31 ( L_151 ) ;
F_31 ( L_152 ,
V_69 -> V_72 , V_69 -> V_312 ) ;
F_44 ( V_69 ) ;
}
}
void F_218 ( const char * V_313 , const int line )
{
struct V_68 * V_69 = V_3 ;
#ifndef F_219
if ( ! F_8 () )
return;
#endif
F_31 ( L_153 ) ;
F_31 ( L_154 ) ;
F_31 ( L_155 ) ;
F_31 ( L_156 ,
V_313 , line ) ;
F_31 ( L_42 ) ;
F_31 ( L_157 , V_314 , V_2 ) ;
F_44 ( V_69 ) ;
F_31 ( L_43 ) ;
F_32 () ;
}
