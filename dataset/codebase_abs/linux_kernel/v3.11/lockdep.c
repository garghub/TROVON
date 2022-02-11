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
static void F_29 ( const char * V_42 )
{
F_30 ( V_43 L_1 , V_42 ) ;
F_30 ( V_43 L_2 ) ;
F_30 ( V_43 L_3 ) ;
}
static int F_31 ( struct V_44 * V_45 )
{
V_45 -> V_46 = 0 ;
V_45 -> V_47 = V_48 - V_49 ;
V_45 -> V_50 = V_44 + V_49 ;
V_45 -> V_51 = 3 ;
F_32 ( V_45 ) ;
if ( V_45 -> V_46 != 0 &&
V_45 -> V_50 [ V_45 -> V_46 - 1 ] == V_52 )
V_45 -> V_46 -- ;
V_45 -> V_47 = V_45 -> V_46 ;
V_49 += V_45 -> V_46 ;
if ( V_49 >= V_48 - 1 ) {
if ( ! F_7 () )
return 0 ;
F_29 ( L_4 ) ;
F_33 () ;
return 0 ;
}
return 1 ;
}
const char * F_34 ( struct V_53 * V_54 , char * V_55 )
{
return F_35 ( ( unsigned long ) V_54 , NULL , NULL , NULL , V_55 ) ;
}
static inline unsigned long F_36 ( enum V_56 V_57 )
{
return 1UL << V_57 ;
}
static char F_37 ( struct V_6 * V_24 , enum V_56 V_57 )
{
char V_58 = '.' ;
if ( V_24 -> V_59 & F_36 ( V_57 + 2 ) )
V_58 = '+' ;
if ( V_24 -> V_59 & F_36 ( V_57 ) ) {
V_58 = '-' ;
if ( V_24 -> V_59 & F_36 ( V_57 + 2 ) )
V_58 = '?' ;
}
return V_58 ;
}
void F_38 ( struct V_6 * V_24 , char V_60 [ V_61 ] )
{
int V_13 = 0 ;
#define F_39 ( T_2 ) \
usage[i++] = get_usage_char(class, LOCK_USED_IN_##__STATE); \
usage[i++] = get_usage_char(class, LOCK_USED_IN_##__STATE##_READ);
#include "lockdep_states.h"
#undef F_39
V_60 [ V_13 ] = '\0' ;
}
static void F_40 ( struct V_6 * V_24 )
{
char V_55 [ V_62 ] ;
const char * V_63 ;
V_63 = V_24 -> V_63 ;
if ( ! V_63 ) {
V_63 = F_34 ( V_24 -> V_54 , V_55 ) ;
F_30 ( L_5 , V_63 ) ;
} else {
F_30 ( L_5 , V_63 ) ;
if ( V_24 -> V_64 > 1 )
F_30 ( L_6 , V_24 -> V_64 ) ;
if ( V_24 -> V_65 )
F_30 ( L_7 , V_24 -> V_65 ) ;
}
}
static void F_41 ( struct V_6 * V_24 )
{
char V_60 [ V_61 ] ;
F_38 ( V_24 , V_60 ) ;
F_30 ( L_8 ) ;
F_40 ( V_24 ) ;
F_30 ( L_9 , V_60 ) ;
}
static void F_42 ( struct V_66 * V_67 )
{
const char * V_63 ;
char V_55 [ V_62 ] ;
V_63 = V_67 -> V_63 ;
if ( ! V_63 )
V_63 = F_34 ( V_67 -> V_54 -> V_68 , V_55 ) ;
F_30 ( L_5 , V_63 ) ;
}
static void F_43 ( struct V_7 * V_8 )
{
F_41 ( F_9 ( V_8 ) ) ;
F_30 ( L_10 ) ;
F_44 ( V_8 -> V_69 ) ;
}
static void F_45 ( struct V_70 * V_71 )
{
int V_13 , V_72 = V_71 -> V_73 ;
if ( ! V_72 ) {
F_30 ( L_11 , V_71 -> V_74 , F_46 ( V_71 ) ) ;
return;
}
F_30 ( L_12 ,
V_72 , V_72 > 1 ? L_13 : L_14 , V_71 -> V_74 , F_46 ( V_71 ) ) ;
for ( V_13 = 0 ; V_13 < V_72 ; V_13 ++ ) {
F_30 ( L_15 , V_13 ) ;
F_43 ( V_71 -> V_75 + V_13 ) ;
}
}
static void F_47 ( void )
{
F_30 ( L_16 , F_48 () -> V_76 ,
( int ) strcspn ( F_48 () -> V_77 , L_17 ) ,
F_48 () -> V_77 ,
F_49 () ) ;
}
static int F_50 ( struct V_6 * V_24 )
{
#if V_78
return F_27 ( V_24 ) ;
#endif
return 0 ;
}
static int F_51 ( void * V_79 )
{
unsigned long V_80 = ( unsigned long ) & V_81 ,
V_82 = ( unsigned long ) & V_83 ,
V_84 = ( unsigned long ) V_79 ;
if ( ( V_84 >= V_80 ) && ( V_84 < V_82 ) )
return 1 ;
if ( F_52 ( V_84 ) )
return 1 ;
if ( F_53 ( V_84 ) )
return 1 ;
return F_54 ( V_84 ) || F_55 ( V_84 ) ;
}
static int F_56 ( struct V_6 * V_85 )
{
struct V_6 * V_24 ;
int V_86 = 0 ;
if ( ! V_85 -> V_63 )
return 0 ;
F_57 (class, &all_lock_classes, lock_entry) {
if ( V_85 -> V_54 - V_85 -> V_65 == V_24 -> V_54 )
return V_24 -> V_64 ;
if ( V_24 -> V_63 && ! strcmp ( V_24 -> V_63 , V_85 -> V_63 ) )
V_86 = V_17 ( V_86 , V_24 -> V_64 ) ;
}
return V_86 + 1 ;
}
static inline struct V_6 *
F_58 ( struct V_66 * V_67 , unsigned int V_65 )
{
struct V_53 * V_54 ;
struct V_87 * V_88 ;
struct V_6 * V_24 ;
#ifdef F_59
if ( F_60 ( ! V_89 ) ) {
F_61 () ;
V_90 = 1 ;
V_91 = V_67 -> V_63 ;
F_32 ( & V_92 ) ;
}
#endif
if ( F_60 ( V_65 >= V_93 ) ) {
F_8 () ;
F_30 ( V_94
L_18 , V_65 ) ;
F_30 ( V_94
L_2 ) ;
F_33 () ;
return NULL ;
}
if ( F_60 ( ! V_67 -> V_54 ) )
V_67 -> V_54 = ( void * ) V_67 ;
F_62 ( sizeof( struct V_95 ) >
sizeof( struct V_66 ) ) ;
V_54 = V_67 -> V_54 -> V_68 + V_65 ;
V_88 = F_63 ( V_54 ) ;
F_57 (class, hash_head, hash_entry) {
if ( V_24 -> V_54 == V_54 ) {
F_64 ( V_24 -> V_63 != V_67 -> V_63 ) ;
return V_24 ;
}
}
return NULL ;
}
static inline struct V_6 *
F_65 ( struct V_66 * V_67 , unsigned int V_65 , int V_96 )
{
struct V_53 * V_54 ;
struct V_87 * V_88 ;
struct V_6 * V_24 ;
unsigned long V_97 ;
V_24 = F_58 ( V_67 , V_65 ) ;
if ( F_66 ( V_24 ) )
goto V_98;
if ( ! F_51 ( V_67 -> V_54 ) ) {
F_8 () ;
F_30 ( L_19 ) ;
F_30 ( L_20 ) ;
F_30 ( L_2 ) ;
F_33 () ;
return NULL ;
}
V_54 = V_67 -> V_54 -> V_68 + V_65 ;
V_88 = F_63 ( V_54 ) ;
F_67 ( V_97 ) ;
if ( ! F_1 () ) {
F_68 ( V_97 ) ;
return NULL ;
}
F_57 (class, hash_head, hash_entry)
if ( V_24 -> V_54 == V_54 )
goto V_99;
if ( V_100 >= V_101 ) {
if ( ! F_7 () ) {
F_68 ( V_97 ) ;
return NULL ;
}
F_68 ( V_97 ) ;
F_29 ( L_21 ) ;
F_33 () ;
return NULL ;
}
V_24 = V_10 + V_100 ++ ;
F_69 ( V_102 ) ;
V_24 -> V_54 = V_54 ;
V_24 -> V_63 = V_67 -> V_63 ;
V_24 -> V_65 = V_65 ;
F_70 ( & V_24 -> V_103 ) ;
F_70 ( & V_24 -> V_104 ) ;
F_70 ( & V_24 -> V_105 ) ;
V_24 -> V_64 = F_56 ( V_24 ) ;
F_71 ( & V_24 -> V_106 , V_88 ) ;
F_71 ( & V_24 -> V_103 , & V_107 ) ;
if ( F_28 ( V_24 ) ) {
F_4 () ;
F_68 ( V_97 ) ;
F_30 ( L_22 , V_24 -> V_54 , V_24 -> V_63 ) ;
if ( V_24 -> V_64 > 1 )
F_30 ( L_6 , V_24 -> V_64 ) ;
F_30 ( L_23 ) ;
F_33 () ;
F_67 ( V_97 ) ;
if ( ! F_1 () ) {
F_68 ( V_97 ) ;
return NULL ;
}
}
V_99:
F_4 () ;
F_68 ( V_97 ) ;
V_98:
if ( ! V_65 || V_96 )
V_67 -> V_108 [ 0 ] = V_24 ;
else if ( V_65 < V_109 )
V_67 -> V_108 [ V_65 ] = V_24 ;
if ( F_6 ( V_24 -> V_65 != V_65 ) )
return NULL ;
return V_24 ;
}
static struct V_110 * F_72 ( void )
{
if ( V_111 >= V_112 ) {
if ( ! F_7 () )
return NULL ;
F_29 ( L_24 ) ;
F_33 () ;
return NULL ;
}
return V_113 + V_111 ++ ;
}
static int F_73 ( struct V_6 * V_24 , struct V_6 * V_114 ,
struct V_87 * V_115 , unsigned long V_12 ,
int V_116 , struct V_44 * V_45 )
{
struct V_110 * V_117 ;
V_117 = F_72 () ;
if ( ! V_117 )
return 0 ;
V_117 -> V_24 = V_114 ;
V_117 -> V_116 = V_116 ;
V_117 -> V_45 = * V_45 ;
F_71 ( & V_117 -> V_117 , V_115 ) ;
return 1 ;
}
static inline void F_74 ( struct V_118 * V_119 )
{
V_119 -> V_120 = V_119 -> V_121 = 0 ;
V_122 ++ ;
}
static inline int F_75 ( struct V_118 * V_119 )
{
return ( V_119 -> V_120 == V_119 -> V_121 ) ;
}
static inline int F_76 ( struct V_118 * V_119 )
{
return ( ( V_119 -> V_121 + 1 ) & V_123 ) == V_119 -> V_120 ;
}
static inline int F_77 ( struct V_118 * V_119 , unsigned long V_124 )
{
if ( F_76 ( V_119 ) )
return - 1 ;
V_119 -> V_125 [ V_119 -> V_121 ] = V_124 ;
V_119 -> V_121 = ( V_119 -> V_121 + 1 ) & V_123 ;
return 0 ;
}
static inline int F_78 ( struct V_118 * V_119 , unsigned long * V_124 )
{
if ( F_75 ( V_119 ) )
return - 1 ;
* V_124 = V_119 -> V_125 [ V_119 -> V_120 ] ;
V_119 -> V_120 = ( V_119 -> V_120 + 1 ) & V_123 ;
return 0 ;
}
static inline unsigned int F_79 ( struct V_118 * V_119 )
{
return ( V_119 -> V_121 - V_119 -> V_120 ) & V_123 ;
}
static inline void F_80 ( struct V_110 * V_67 ,
struct V_110 * V_126 )
{
unsigned long V_19 ;
V_19 = V_67 - V_113 ;
F_81 ( V_19 >= V_111 ) ;
V_67 -> V_126 = V_126 ;
V_67 -> V_24 -> V_127 = V_122 ;
}
static inline unsigned long F_82 ( struct V_110 * V_67 )
{
unsigned long V_19 ;
V_19 = V_67 - V_113 ;
F_81 ( V_19 >= V_111 ) ;
return V_67 -> V_24 -> V_127 == V_122 ;
}
static inline struct V_110 * F_83 ( struct V_110 * V_128 )
{
return V_128 -> V_126 ;
}
static inline int F_84 ( struct V_110 * V_128 )
{
int V_72 = 0 ;
struct V_110 * V_126 ;
while ( ( V_126 = F_83 ( V_128 ) ) ) {
V_128 = V_126 ;
V_72 ++ ;
}
return V_72 ;
}
static int F_85 ( struct V_110 * V_129 ,
void * V_130 ,
int (* F_86)( struct V_110 * V_117 , void * V_130 ) ,
struct V_110 * * V_131 ,
int V_132 )
{
struct V_110 * V_117 ;
struct V_87 * V_115 ;
struct V_118 * V_119 = & V_133 ;
int V_5 = 1 ;
if ( F_86 ( V_129 , V_130 ) ) {
* V_131 = V_129 ;
V_5 = 0 ;
goto exit;
}
if ( V_132 )
V_115 = & V_129 -> V_24 -> V_105 ;
else
V_115 = & V_129 -> V_24 -> V_104 ;
if ( F_87 ( V_115 ) )
goto exit;
F_74 ( V_119 ) ;
F_77 ( V_119 , ( unsigned long ) V_129 ) ;
while ( ! F_75 ( V_119 ) ) {
struct V_110 * V_67 ;
F_78 ( V_119 , ( unsigned long * ) & V_67 ) ;
if ( ! V_67 -> V_24 ) {
V_5 = - 2 ;
goto exit;
}
if ( V_132 )
V_115 = & V_67 -> V_24 -> V_105 ;
else
V_115 = & V_67 -> V_24 -> V_104 ;
F_57 (entry, head, entry) {
if ( ! F_82 ( V_117 ) ) {
unsigned int V_134 ;
F_80 ( V_117 , V_67 ) ;
if ( F_86 ( V_117 , V_130 ) ) {
* V_131 = V_117 ;
V_5 = 0 ;
goto exit;
}
if ( F_77 ( V_119 , ( unsigned long ) V_117 ) ) {
V_5 = - 1 ;
goto exit;
}
V_134 = F_79 ( V_119 ) ;
if ( V_135 < V_134 )
V_135 = V_134 ;
}
}
}
exit:
return V_5 ;
}
static inline int F_88 ( struct V_110 * V_136 ,
void * V_130 ,
int (* F_86)( struct V_110 * V_117 , void * V_130 ) ,
struct V_110 * * V_131 )
{
return F_85 ( V_136 , V_130 , F_86 , V_131 , 1 ) ;
}
static inline int F_89 ( struct V_110 * V_136 ,
void * V_130 ,
int (* F_86)( struct V_110 * V_117 , void * V_130 ) ,
struct V_110 * * V_131 )
{
return F_85 ( V_136 , V_130 , F_86 , V_131 , 0 ) ;
}
static T_3 int
F_90 ( struct V_110 * V_137 , int V_72 )
{
if ( V_138 )
return 0 ;
F_30 ( L_25 , V_72 ) ;
F_41 ( V_137 -> V_24 ) ;
F_30 ( L_26 ) ;
F_91 ( & V_137 -> V_45 , 6 ) ;
return 0 ;
}
static void
F_92 ( struct V_7 * V_21 ,
struct V_7 * V_139 ,
struct V_110 * V_140 )
{
struct V_6 * V_141 = F_9 ( V_21 ) ;
struct V_6 * V_137 = F_9 ( V_139 ) ;
struct V_6 * V_126 = V_140 -> V_24 ;
if ( V_126 != V_141 ) {
F_30 ( L_27 ) ;
F_40 ( V_141 ) ;
F_30 ( L_28 ) ;
F_40 ( V_126 ) ;
F_30 ( L_28 ) ;
F_40 ( V_137 ) ;
F_30 ( L_29 ) ;
}
F_30 ( L_30 ) ;
F_30 ( L_31 ) ;
F_30 ( L_32 ) ;
F_30 ( L_33 ) ;
F_40 ( V_137 ) ;
F_30 ( L_34 ) ;
F_30 ( L_35 ) ;
F_40 ( V_126 ) ;
F_30 ( L_34 ) ;
F_30 ( L_35 ) ;
F_40 ( V_137 ) ;
F_30 ( L_34 ) ;
F_30 ( L_33 ) ;
F_40 ( V_141 ) ;
F_30 ( L_34 ) ;
F_30 ( L_36 ) ;
}
static T_3 int
F_93 ( struct V_110 * V_117 , unsigned int V_72 ,
struct V_7 * V_142 ,
struct V_7 * V_143 )
{
struct V_70 * V_71 = V_3 ;
if ( V_138 )
return 0 ;
F_30 ( L_23 ) ;
F_30 ( L_37 ) ;
F_30 ( L_38 ) ;
F_47 () ;
F_30 ( L_39 ) ;
F_30 ( L_40 ,
V_71 -> V_74 , F_46 ( V_71 ) ) ;
F_43 ( V_142 ) ;
F_30 ( L_41 ) ;
F_43 ( V_143 ) ;
F_30 ( L_42 ) ;
F_30 ( L_43 ) ;
F_90 ( V_117 , V_72 ) ;
return 0 ;
}
static inline int F_94 ( struct V_110 * V_117 , void * V_130 )
{
return V_117 -> V_24 == V_130 ;
}
static T_3 int F_95 ( struct V_110 * V_114 ,
struct V_110 * V_137 ,
struct V_7 * V_142 ,
struct V_7 * V_143 )
{
struct V_70 * V_71 = V_3 ;
struct V_110 * V_126 ;
struct V_110 * V_144 ;
int V_72 ;
if ( ! F_7 () || V_138 )
return 0 ;
if ( ! F_31 ( & V_114 -> V_45 ) )
return 0 ;
V_72 = F_84 ( V_137 ) ;
F_93 ( V_137 , V_72 , V_142 , V_143 ) ;
V_126 = F_83 ( V_137 ) ;
V_144 = V_126 ;
while ( V_126 ) {
F_90 ( V_126 , -- V_72 ) ;
V_126 = F_83 ( V_126 ) ;
}
F_30 ( L_44 ) ;
F_92 ( V_142 , V_143 ,
V_144 ) ;
F_45 ( V_71 ) ;
F_30 ( L_45 ) ;
F_33 () ;
return 0 ;
}
static T_3 int F_96 ( int V_5 )
{
if ( ! F_7 () )
return 0 ;
F_97 ( 1 , L_46 , V_5 ) ;
return 0 ;
}
static int F_98 ( struct V_110 * V_117 , void * V_130 )
{
( * ( unsigned long * ) V_130 ) ++ ;
return 0 ;
}
unsigned long F_99 ( struct V_110 * V_114 )
{
unsigned long V_86 = 0 ;
struct V_110 * V_145 ( V_131 ) ;
F_88 ( V_114 , ( void * ) & V_86 , F_98 , & V_131 ) ;
return V_86 ;
}
unsigned long F_100 ( struct V_6 * V_24 )
{
unsigned long V_5 , V_97 ;
struct V_110 V_114 ;
V_114 . V_126 = NULL ;
V_114 . V_24 = V_24 ;
F_101 ( V_97 ) ;
F_2 ( & V_1 ) ;
V_5 = F_99 ( & V_114 ) ;
F_3 ( & V_1 ) ;
F_102 ( V_97 ) ;
return V_5 ;
}
unsigned long F_103 ( struct V_110 * V_114 )
{
unsigned long V_86 = 0 ;
struct V_110 * V_145 ( V_131 ) ;
F_89 ( V_114 , ( void * ) & V_86 , F_98 , & V_131 ) ;
return V_86 ;
}
unsigned long F_104 ( struct V_6 * V_24 )
{
unsigned long V_5 , V_97 ;
struct V_110 V_114 ;
V_114 . V_126 = NULL ;
V_114 . V_24 = V_24 ;
F_101 ( V_97 ) ;
F_2 ( & V_1 ) ;
V_5 = F_103 ( & V_114 ) ;
F_3 ( & V_1 ) ;
F_102 ( V_97 ) ;
return V_5 ;
}
static T_3 int
F_105 ( struct V_110 * V_146 , struct V_6 * V_137 ,
struct V_110 * * V_131 )
{
int V_147 ;
F_69 ( V_148 ) ;
V_147 = F_88 ( V_146 , V_137 , F_94 , V_131 ) ;
return V_147 ;
}
static inline int F_106 ( struct V_110 * V_117 , void * V_57 )
{
return V_117 -> V_24 -> V_59 & ( 1 << (enum V_56 ) V_57 ) ;
}
static int
F_107 ( struct V_110 * V_146 , enum V_56 V_57 ,
struct V_110 * * V_131 )
{
int V_147 ;
F_69 ( V_149 ) ;
V_147 = F_88 ( V_146 , ( void * ) V_57 , F_106 , V_131 ) ;
return V_147 ;
}
static int
F_108 ( struct V_110 * V_146 , enum V_56 V_57 ,
struct V_110 * * V_131 )
{
int V_147 ;
F_69 ( V_150 ) ;
V_147 = F_89 ( V_146 , ( void * ) V_57 , F_106 , V_131 ) ;
return V_147 ;
}
static void F_109 ( struct V_6 * V_24 , int V_72 )
{
int V_57 ;
F_30 ( L_47 , V_72 , L_14 ) ;
F_41 ( V_24 ) ;
F_30 ( L_48 , V_24 -> V_151 ) ;
F_30 ( L_49 ) ;
for ( V_57 = 0 ; V_57 < V_152 ; V_57 ++ ) {
if ( V_24 -> V_59 & ( 1 << V_57 ) ) {
int V_153 = V_72 ;
V_153 += F_30 ( L_50 , V_72 , L_14 , V_154 [ V_57 ] ) ;
V_153 += F_30 ( L_51 ) ;
F_91 ( V_24 -> V_155 + V_57 , V_153 ) ;
}
}
F_30 ( L_52 , V_72 , L_14 ) ;
F_30 ( L_53 , V_72 , L_14 ) ;
F_44 ( ( unsigned long ) V_24 -> V_54 ) ;
}
static void T_4
F_110 ( struct V_110 * V_156 ,
struct V_110 * V_146 )
{
struct V_110 * V_117 = V_156 ;
int V_72 ;
V_72 = F_84 ( V_156 ) ;
do {
F_109 ( V_117 -> V_24 , V_72 ) ;
F_30 ( L_54 , V_72 , L_14 ) ;
F_91 ( & V_117 -> V_45 , 2 ) ;
F_30 ( L_23 ) ;
if ( V_72 == 0 && ( V_117 != V_146 ) ) {
F_30 ( L_55 , V_157 ) ;
break;
}
V_117 = F_83 ( V_117 ) ;
V_72 -- ;
} while ( V_117 && ( V_72 >= 0 ) );
return;
}
static void
F_111 ( struct V_110 * V_158 ,
struct V_110 * V_159 ,
struct V_6 * V_160 ,
struct V_6 * V_161 )
{
struct V_6 * V_162 = V_158 -> V_24 ;
struct V_6 * V_163 = V_159 -> V_24 ;
struct V_6 * V_164 = V_160 ;
if ( V_164 == V_162 )
V_164 = V_161 ;
if ( V_164 != V_163 ) {
F_30 ( L_27 ) ;
F_40 ( V_162 ) ;
F_30 ( L_28 ) ;
F_40 ( V_164 ) ;
F_30 ( L_28 ) ;
F_40 ( V_163 ) ;
F_30 ( L_29 ) ;
}
F_30 ( L_56 ) ;
F_30 ( L_31 ) ;
F_30 ( L_32 ) ;
F_30 ( L_33 ) ;
F_40 ( V_163 ) ;
F_30 ( L_34 ) ;
F_30 ( L_57 ) ;
F_30 ( L_35 ) ;
F_40 ( V_162 ) ;
F_30 ( L_34 ) ;
F_30 ( L_35 ) ;
F_40 ( V_164 ) ;
F_30 ( L_34 ) ;
F_30 ( L_58 ) ;
F_30 ( L_59 ) ;
F_40 ( V_162 ) ;
F_30 ( L_34 ) ;
F_30 ( L_36 ) ;
}
static int
F_112 ( struct V_70 * V_71 ,
struct V_110 * V_165 ,
struct V_110 * V_166 ,
struct V_110 * V_167 ,
struct V_110 * V_168 ,
struct V_7 * V_169 ,
struct V_7 * V_170 ,
enum V_56 V_171 ,
enum V_56 V_172 ,
const char * V_173 )
{
if ( ! F_7 () || V_138 )
return 0 ;
F_30 ( L_23 ) ;
F_30 ( L_37 ) ;
F_30 ( L_60 ,
V_173 , V_173 ) ;
F_47 () ;
F_30 ( L_61 ) ;
F_30 ( L_62 ,
V_71 -> V_74 , F_46 ( V_71 ) ,
V_71 -> V_174 , F_113 () >> V_175 ,
V_71 -> V_176 , F_114 () >> V_177 ,
V_71 -> V_178 ,
V_71 -> V_179 ) ;
F_43 ( V_170 ) ;
F_30 ( L_63 ) ;
F_43 ( V_169 ) ;
F_30 ( L_64 ) ;
F_41 ( F_9 ( V_169 ) ) ;
F_30 ( L_65 ) ;
F_41 ( F_9 ( V_170 ) ) ;
F_30 ( L_23 ) ;
F_30 ( L_66 ,
V_173 ) ;
F_41 ( V_167 -> V_24 ) ;
F_30 ( L_67 , V_173 ) ;
F_91 ( V_167 -> V_24 -> V_155 + V_171 , 1 ) ;
F_30 ( L_68 , V_173 ) ;
F_41 ( V_168 -> V_24 ) ;
F_30 ( L_69 , V_173 ) ;
F_30 ( L_70 ) ;
F_91 ( V_168 -> V_24 -> V_155 + V_172 , 1 ) ;
F_30 ( L_44 ) ;
F_111 ( V_167 , V_168 ,
F_9 ( V_169 ) , F_9 ( V_170 ) ) ;
F_45 ( V_71 ) ;
F_30 ( L_71 , V_173 ) ;
F_30 ( L_72 ) ;
if ( ! F_31 ( & V_165 -> V_45 ) )
return 0 ;
F_110 ( V_167 , V_165 ) ;
F_30 ( L_73 ) ;
F_30 ( L_74 , V_173 ) ;
if ( ! F_31 ( & V_166 -> V_45 ) )
return 0 ;
F_110 ( V_168 , V_166 ) ;
F_30 ( L_45 ) ;
F_33 () ;
return 0 ;
}
static int
F_115 ( struct V_70 * V_71 , struct V_7 * V_169 ,
struct V_7 * V_170 , enum V_56 V_180 ,
enum V_56 V_181 , const char * V_173 )
{
int V_5 ;
struct V_110 V_114 , V_182 ;
struct V_110 * V_145 ( V_131 ) ;
struct V_110 * V_145 ( V_183 ) ;
V_114 . V_126 = NULL ;
V_114 . V_24 = F_9 ( V_169 ) ;
V_5 = F_108 ( & V_114 , V_180 , & V_131 ) ;
if ( V_5 < 0 )
return F_96 ( V_5 ) ;
if ( V_5 == 1 )
return V_5 ;
V_182 . V_126 = NULL ;
V_182 . V_24 = F_9 ( V_170 ) ;
V_5 = F_107 ( & V_182 , V_181 , & V_183 ) ;
if ( V_5 < 0 )
return F_96 ( V_5 ) ;
if ( V_5 == 1 )
return V_5 ;
return F_112 ( V_71 , & V_114 , & V_182 ,
V_131 , V_183 ,
V_169 , V_170 ,
V_180 , V_181 , V_173 ) ;
}
static inline const char * F_116 ( enum V_56 V_57 )
{
return ( V_57 & 1 ) ? V_184 [ V_57 >> 2 ] : V_185 [ V_57 >> 2 ] ;
}
static int F_117 ( int V_186 )
{
int V_187 = V_186 & ~ 3 ;
int V_188 = V_186 & 2 ;
return V_187 | ( V_188 ^ 2 ) ;
}
static int F_118 ( struct V_70 * V_71 , struct V_7 * V_169 ,
struct V_7 * V_170 , enum V_56 V_57 )
{
if ( ! F_115 ( V_71 , V_169 , V_170 , V_57 ,
F_117 ( V_57 ) , F_116 ( V_57 ) ) )
return 0 ;
V_57 ++ ;
if ( ! F_115 ( V_71 , V_169 , V_170 , V_57 ,
F_117 ( V_57 ) , F_116 ( V_57 ) ) )
return 0 ;
return 1 ;
}
static int
F_119 ( struct V_70 * V_71 , struct V_7 * V_169 ,
struct V_7 * V_170 )
{
#define F_39 ( T_2 ) \
if (!check_irq_usage(curr, prev, next, LOCK_USED_IN_##__STATE)) \
return 0;
#include "lockdep_states.h"
#undef F_39
return 1 ;
}
static void F_120 ( void )
{
if ( V_3 -> V_174 )
V_189 ++ ;
else {
if ( V_3 -> V_176 )
V_190 ++ ;
else
V_191 ++ ;
}
}
static inline int
F_119 ( struct V_70 * V_71 , struct V_7 * V_169 ,
struct V_7 * V_170 )
{
return 1 ;
}
static inline void F_120 ( void )
{
V_191 ++ ;
}
static void
F_121 ( struct V_7 * V_192 ,
struct V_7 * V_193 )
{
struct V_6 * V_170 = F_9 ( V_192 ) ;
struct V_6 * V_169 = F_9 ( V_193 ) ;
F_30 ( L_30 ) ;
F_30 ( L_75 ) ;
F_30 ( L_76 ) ;
F_30 ( L_33 ) ;
F_40 ( V_169 ) ;
F_30 ( L_34 ) ;
F_30 ( L_33 ) ;
F_40 ( V_170 ) ;
F_30 ( L_34 ) ;
F_30 ( L_36 ) ;
F_30 ( L_77 ) ;
}
static int
F_122 ( struct V_70 * V_71 , struct V_7 * V_169 ,
struct V_7 * V_170 )
{
if ( ! F_7 () || V_138 )
return 0 ;
F_30 ( L_23 ) ;
F_30 ( L_78 ) ;
F_30 ( L_79 ) ;
F_47 () ;
F_30 ( L_80 ) ;
F_30 ( L_40 ,
V_71 -> V_74 , F_46 ( V_71 ) ) ;
F_43 ( V_170 ) ;
F_30 ( L_41 ) ;
F_43 ( V_169 ) ;
F_30 ( L_81 ) ;
F_121 ( V_170 , V_169 ) ;
F_45 ( V_71 ) ;
F_30 ( L_45 ) ;
F_33 () ;
return 0 ;
}
static int
F_123 ( struct V_70 * V_71 , struct V_7 * V_170 ,
struct V_66 * V_194 , int V_40 )
{
struct V_7 * V_169 ;
struct V_7 * V_195 = NULL ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_71 -> V_73 ; V_13 ++ ) {
V_169 = V_71 -> V_75 + V_13 ;
if ( V_169 -> V_196 == V_170 -> V_197 )
V_195 = V_169 ;
if ( F_9 ( V_169 ) != F_9 ( V_170 ) )
continue;
if ( ( V_40 == 2 ) && V_169 -> V_40 )
return 2 ;
if ( V_195 )
return 2 ;
return F_122 ( V_71 , V_169 , V_170 ) ;
}
return 1 ;
}
static int
F_124 ( struct V_70 * V_71 , struct V_7 * V_169 ,
struct V_7 * V_170 , int V_116 , int V_198 )
{
struct V_110 * V_117 ;
int V_5 ;
struct V_110 V_114 ;
struct V_110 * V_145 ( V_131 ) ;
static struct V_44 V_45 ;
V_114 . V_24 = F_9 ( V_170 ) ;
V_114 . V_126 = NULL ;
V_5 = F_105 ( & V_114 , F_9 ( V_169 ) , & V_131 ) ;
if ( F_60 ( ! V_5 ) )
return F_95 ( & V_114 , V_131 , V_170 , V_169 ) ;
else if ( F_60 ( V_5 < 0 ) )
return F_96 ( V_5 ) ;
if ( ! F_119 ( V_71 , V_169 , V_170 ) )
return 0 ;
if ( V_170 -> V_40 == 2 || V_169 -> V_40 == 2 )
return 1 ;
F_57 (entry, &hlock_class(prev)->locks_after, entry) {
if ( V_117 -> V_24 == F_9 ( V_170 ) ) {
if ( V_116 == 1 )
V_117 -> V_116 = 1 ;
return 2 ;
}
}
if ( ! V_198 && ! F_31 ( & V_45 ) )
return 0 ;
V_5 = F_73 ( F_9 ( V_169 ) , F_9 ( V_170 ) ,
& F_9 ( V_169 ) -> V_105 ,
V_170 -> V_69 , V_116 , & V_45 ) ;
if ( ! V_5 )
return 0 ;
V_5 = F_73 ( F_9 ( V_170 ) , F_9 ( V_169 ) ,
& F_9 ( V_170 ) -> V_104 ,
V_170 -> V_69 , V_116 , & V_45 ) ;
if ( ! V_5 )
return 0 ;
if ( F_28 ( F_9 ( V_169 ) ) || F_28 ( F_9 ( V_170 ) ) ) {
F_4 () ;
F_30 ( L_82 ) ;
F_41 ( F_9 ( V_169 ) ) ;
F_30 ( L_83 ) ;
F_41 ( F_9 ( V_170 ) ) ;
F_30 ( L_23 ) ;
F_33 () ;
return F_1 () ;
}
return 1 ;
}
static int
F_125 ( struct V_70 * V_71 , struct V_7 * V_170 )
{
int V_72 = V_71 -> V_73 ;
int V_198 = 0 ;
struct V_7 * V_8 ;
if ( ! V_72 )
goto V_199;
if ( V_71 -> V_75 [ V_72 ] . V_200 !=
V_71 -> V_75 [ V_72 - 1 ] . V_200 )
goto V_199;
for (; ; ) {
int V_116 = V_71 -> V_73 - V_72 + 1 ;
V_8 = V_71 -> V_75 + V_72 - 1 ;
if ( V_8 -> V_40 != 2 ) {
if ( ! F_124 ( V_71 , V_8 , V_170 ,
V_116 , V_198 ) )
return 0 ;
if ( ! V_8 -> V_201 )
break;
}
V_72 -- ;
if ( ! V_72 )
break;
if ( V_71 -> V_75 [ V_72 ] . V_200 !=
V_71 -> V_75 [ V_72 - 1 ] . V_200 )
break;
V_198 = 1 ;
}
return 1 ;
V_199:
if ( ! F_7 () )
return 0 ;
F_81 ( 1 ) ;
return 0 ;
}
struct V_6 * F_126 ( struct V_202 * V_203 , int V_13 )
{
return V_10 + V_204 [ V_203 -> V_205 + V_13 ] ;
}
static inline int F_127 ( struct V_70 * V_71 ,
struct V_7 * V_8 ,
T_1 V_206 )
{
struct V_6 * V_24 = F_9 ( V_8 ) ;
struct V_87 * V_88 = F_128 ( V_206 ) ;
struct V_202 * V_203 ;
struct V_7 * V_207 ;
int V_13 , V_208 ;
if ( F_6 ( ! F_129 () ) )
return 0 ;
F_57 (chain, hash_head, entry) {
if ( V_203 -> V_206 == V_206 ) {
V_209:
F_69 ( V_210 ) ;
if ( F_50 ( V_24 ) )
F_30 ( L_84
L_85 ,
( unsigned long long ) V_206 ,
V_24 -> V_54 , V_24 -> V_63 ) ;
return 0 ;
}
}
if ( F_50 ( V_24 ) )
F_30 ( L_86 ,
( unsigned long long ) V_206 , V_24 -> V_54 , V_24 -> V_63 ) ;
if ( ! F_1 () )
return 0 ;
F_57 (chain, hash_head, entry) {
if ( V_203 -> V_206 == V_206 ) {
F_4 () ;
goto V_209;
}
}
if ( F_60 ( V_211 >= V_212 ) ) {
if ( ! F_7 () )
return 0 ;
F_29 ( L_87 ) ;
F_33 () ;
return 0 ;
}
V_203 = V_213 + V_211 ++ ;
V_203 -> V_206 = V_206 ;
V_203 -> V_200 = V_8 -> V_200 ;
for ( V_13 = V_71 -> V_73 - 1 ; V_13 >= 0 ; V_13 -- ) {
V_207 = V_71 -> V_75 + V_13 ;
if ( V_207 -> V_200 != V_8 -> V_200 )
break;
}
V_13 ++ ;
V_203 -> V_72 = V_71 -> V_73 + 1 - V_13 ;
if ( F_66 ( V_214 + V_203 -> V_72 <= V_215 ) ) {
V_203 -> V_205 = V_214 ;
V_214 += V_203 -> V_72 ;
for ( V_208 = 0 ; V_208 < V_203 -> V_72 - 1 ; V_208 ++ , V_13 ++ ) {
int V_216 = V_71 -> V_75 [ V_13 ] . V_9 - 1 ;
V_204 [ V_203 -> V_205 + V_208 ] = V_216 ;
}
V_204 [ V_203 -> V_205 + V_208 ] = V_24 - V_10 ;
}
F_71 ( & V_203 -> V_117 , V_88 ) ;
F_69 ( V_217 ) ;
F_120 () ;
return 1 ;
}
static int F_130 ( struct V_70 * V_71 , struct V_66 * V_67 ,
struct V_7 * V_8 , int V_218 , T_1 V_206 )
{
if ( ! V_8 -> V_201 && ( V_8 -> V_219 == 2 ) &&
F_127 ( V_71 , V_8 , V_206 ) ) {
int V_5 = F_123 ( V_71 , V_8 , V_67 , V_8 -> V_40 ) ;
if ( ! V_5 )
return 0 ;
if ( V_5 == 2 )
V_8 -> V_40 = 2 ;
if ( ! V_218 && V_5 != 2 )
if ( ! F_125 ( V_71 , V_8 ) )
return 0 ;
F_4 () ;
} else
if ( F_60 ( ! V_2 ) )
return 0 ;
return 1 ;
}
static inline int F_130 ( struct V_70 * V_71 ,
struct V_66 * V_67 , struct V_7 * V_8 ,
int V_218 , T_1 V_206 )
{
return 1 ;
}
static void F_131 ( struct V_70 * V_71 )
{
#ifdef F_59
struct V_7 * V_8 , * V_220 = NULL ;
unsigned int V_13 , V_221 ;
T_1 V_206 = 0 ;
for ( V_13 = 0 ; V_13 < V_71 -> V_73 ; V_13 ++ ) {
V_8 = V_71 -> V_75 + V_13 ;
if ( V_206 != V_8 -> V_222 ) {
F_8 () ;
F_97 ( 1 , L_88 ,
V_71 -> V_73 , V_13 ,
( unsigned long long ) V_206 ,
( unsigned long long ) V_8 -> V_222 ) ;
return;
}
V_221 = V_8 -> V_9 - 1 ;
if ( F_6 ( V_221 >= V_101 ) )
return;
if ( V_220 && ( V_220 -> V_200 !=
V_8 -> V_200 ) )
V_206 = 0 ;
V_206 = F_132 ( V_206 , V_221 ) ;
V_220 = V_8 ;
}
if ( V_206 != V_71 -> V_223 ) {
F_8 () ;
F_97 ( 1 , L_89 ,
V_71 -> V_73 , V_13 ,
( unsigned long long ) V_206 ,
( unsigned long long ) V_71 -> V_223 ) ;
}
#endif
}
static void
F_133 ( struct V_7 * V_67 )
{
struct V_6 * V_24 = F_9 ( V_67 ) ;
F_30 ( L_30 ) ;
F_30 ( L_75 ) ;
F_30 ( L_76 ) ;
F_30 ( L_33 ) ;
F_40 ( V_24 ) ;
F_30 ( L_34 ) ;
F_30 ( L_58 ) ;
F_30 ( L_59 ) ;
F_40 ( V_24 ) ;
F_30 ( L_34 ) ;
F_30 ( L_36 ) ;
}
static int
F_134 ( struct V_70 * V_71 , struct V_7 * V_114 ,
enum V_56 V_224 , enum V_56 V_186 )
{
if ( ! F_7 () || V_138 )
return 0 ;
F_30 ( L_23 ) ;
F_30 ( L_90 ) ;
F_30 ( L_91 ) ;
F_47 () ;
F_30 ( L_92 ) ;
F_30 ( L_93 ,
V_154 [ V_224 ] , V_154 [ V_186 ] ) ;
F_30 ( L_94 ,
V_71 -> V_74 , F_46 ( V_71 ) ,
F_135 ( V_71 ) , F_113 () >> V_175 ,
F_136 ( V_71 ) , F_114 () >> V_177 ,
F_137 ( V_71 ) ,
F_138 ( V_71 ) ) ;
F_43 ( V_114 ) ;
F_30 ( L_95 , V_154 [ V_224 ] ) ;
F_91 ( F_9 ( V_114 ) -> V_155 + V_224 , 1 ) ;
F_139 ( V_71 ) ;
F_30 ( L_81 ) ;
F_133 ( V_114 ) ;
F_45 ( V_71 ) ;
F_30 ( L_45 ) ;
F_33 () ;
return 0 ;
}
static inline int
F_140 ( struct V_70 * V_71 , struct V_7 * V_114 ,
enum V_56 V_186 , enum V_56 V_225 )
{
if ( F_60 ( F_9 ( V_114 ) -> V_59 & ( 1 << V_225 ) ) )
return F_134 ( V_71 , V_114 , V_225 , V_186 ) ;
return 1 ;
}
static int
F_141 ( struct V_70 * V_71 ,
struct V_110 * V_146 , struct V_110 * V_226 ,
struct V_7 * V_114 , int V_227 ,
const char * V_173 )
{
struct V_110 * V_117 = V_226 ;
struct V_110 * V_228 = NULL ;
int V_72 ;
if ( ! F_7 () || V_138 )
return 0 ;
F_30 ( L_23 ) ;
F_30 ( L_96 ) ;
F_30 ( L_97 ) ;
F_47 () ;
F_30 ( L_98 ) ;
F_30 ( L_99 ,
V_71 -> V_74 , F_46 ( V_71 ) ) ;
F_43 ( V_114 ) ;
if ( V_227 )
F_30 ( L_100 , V_173 ) ;
else
F_30 ( L_101 , V_173 ) ;
F_41 ( V_226 -> V_24 ) ;
F_30 ( L_102 ) ;
F_30 ( L_81 ) ;
V_72 = F_84 ( V_226 ) ;
do {
if ( V_72 == 0 && ( V_117 != V_146 ) ) {
F_30 ( L_55 , V_157 ) ;
break;
}
V_228 = V_117 ;
V_117 = F_83 ( V_117 ) ;
V_72 -- ;
} while ( V_117 && V_117 != V_146 && ( V_72 >= 0 ) );
if ( V_227 )
F_111 ( V_146 , V_226 ,
V_228 ? V_228 -> V_24 : V_146 -> V_24 , V_226 -> V_24 ) ;
else
F_111 ( V_226 , V_146 ,
V_228 ? V_228 -> V_24 : V_226 -> V_24 , V_146 -> V_24 ) ;
F_45 ( V_71 ) ;
F_30 ( L_103 ) ;
if ( ! F_31 ( & V_146 -> V_45 ) )
return 0 ;
F_110 ( V_226 , V_146 ) ;
F_30 ( L_45 ) ;
F_33 () ;
return 0 ;
}
static int
F_142 ( struct V_70 * V_71 , struct V_7 * V_114 ,
enum V_56 V_57 , const char * V_173 )
{
int V_5 ;
struct V_110 V_146 ;
struct V_110 * V_145 ( V_131 ) ;
V_146 . V_126 = NULL ;
V_146 . V_24 = F_9 ( V_114 ) ;
V_5 = F_107 ( & V_146 , V_57 , & V_131 ) ;
if ( V_5 < 0 )
return F_96 ( V_5 ) ;
if ( V_5 == 1 )
return V_5 ;
return F_141 ( V_71 , & V_146 , V_131 ,
V_114 , 1 , V_173 ) ;
}
static int
F_143 ( struct V_70 * V_71 , struct V_7 * V_114 ,
enum V_56 V_57 , const char * V_173 )
{
int V_5 ;
struct V_110 V_146 ;
struct V_110 * V_145 ( V_131 ) ;
V_146 . V_126 = NULL ;
V_146 . V_24 = F_9 ( V_114 ) ;
V_5 = F_108 ( & V_146 , V_57 , & V_131 ) ;
if ( V_5 < 0 )
return F_96 ( V_5 ) ;
if ( V_5 == 1 )
return V_5 ;
return F_141 ( V_71 , & V_146 , V_131 ,
V_114 , 0 , V_173 ) ;
}
void F_139 ( struct V_70 * V_71 )
{
F_30 ( L_104 , V_71 -> V_229 ) ;
F_30 ( L_105 , V_71 -> V_230 ) ;
F_44 ( V_71 -> V_231 ) ;
F_30 ( L_106 , V_71 -> V_232 ) ;
F_44 ( V_71 -> V_233 ) ;
F_30 ( L_107 , V_71 -> V_234 ) ;
F_44 ( V_71 -> V_235 ) ;
F_30 ( L_108 , V_71 -> V_236 ) ;
F_44 ( V_71 -> V_237 ) ;
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
static int F_146 ( struct V_6 * V_24 )
{
#if V_240
return F_27 ( V_24 ) ;
#endif
return 0 ;
}
static inline int F_147 ( enum V_56 V_57 ,
struct V_6 * V_24 )
{
return V_241 [ V_57 >> 2 ] ( V_24 ) ;
}
static int
F_148 ( struct V_70 * V_71 , struct V_7 * V_114 ,
enum V_56 V_186 )
{
int V_242 = F_117 ( V_186 ) ;
int V_40 = V_186 & 1 ;
int V_188 = V_186 & 2 ;
T_5 V_60 = V_188 ?
F_143 : F_142 ;
if ( ! F_140 ( V_71 , V_114 , V_186 , V_242 ) )
return 0 ;
if ( ( ! V_40 || ! V_188 || V_243 ) &&
! V_60 ( V_71 , V_114 , V_242 , F_116 ( V_186 & ~ 1 ) ) )
return 0 ;
if ( ! V_40 ) {
if ( ! F_140 ( V_71 , V_114 , V_186 , V_242 + 1 ) )
return 0 ;
if ( V_243 &&
! V_60 ( V_71 , V_114 , V_242 + 1 ,
F_116 ( V_186 + 1 ) ) )
return 0 ;
}
if ( F_147 ( V_186 , F_9 ( V_114 ) ) )
return 2 ;
return 1 ;
}
static int
F_149 ( struct V_70 * V_71 , enum V_244 V_245 )
{
enum V_56 V_246 ;
struct V_7 * V_8 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_71 -> V_73 ; V_13 ++ ) {
V_8 = V_71 -> V_75 + V_13 ;
V_246 = 2 + ( V_245 << 2 ) ;
if ( V_8 -> V_40 )
V_246 += 1 ;
F_150 ( V_246 >= V_152 ) ;
if ( F_9 ( V_8 ) -> V_54 == V_247 . V_68 )
continue;
if ( ! F_151 ( V_71 , V_8 , V_246 ) )
return 0 ;
}
return 1 ;
}
static void F_152 ( unsigned long V_12 )
{
struct V_70 * V_71 = V_3 ;
V_71 -> V_178 = 1 ;
if ( ! F_149 ( V_71 , V_248 ) )
return;
if ( V_71 -> V_179 )
if ( ! F_149 ( V_71 , V_249 ) )
return;
V_71 -> V_231 = V_12 ;
V_71 -> V_230 = ++ V_71 -> V_229 ;
F_69 ( V_250 ) ;
}
void F_153 ( unsigned long V_12 )
{
F_154 ( V_251 , V_12 ) ;
if ( F_60 ( ! V_2 || V_3 -> V_4 ) )
return;
if ( F_60 ( V_3 -> V_178 ) ) {
F_155 ( V_252 ) ;
return;
}
if ( F_6 ( ! F_129 () ) )
return;
if ( F_6 ( F_60 ( V_253 ) ) )
return;
if ( F_6 ( V_3 -> V_174 ) )
return;
V_3 -> V_4 = 1 ;
F_152 ( V_12 ) ;
V_3 -> V_4 = 0 ;
}
void F_156 ( void )
{
F_153 ( V_251 ) ;
}
void F_157 ( unsigned long V_12 )
{
struct V_70 * V_71 = V_3 ;
F_158 ( V_251 , V_12 ) ;
if ( F_60 ( ! V_2 || V_3 -> V_4 ) )
return;
if ( F_6 ( ! F_129 () ) )
return;
if ( V_71 -> V_178 ) {
V_71 -> V_178 = 0 ;
V_71 -> V_233 = V_12 ;
V_71 -> V_232 = ++ V_71 -> V_229 ;
F_69 ( V_254 ) ;
} else
F_69 ( V_255 ) ;
}
void F_159 ( void )
{
F_157 ( V_251 ) ;
}
void F_160 ( unsigned long V_12 )
{
struct V_70 * V_71 = V_3 ;
if ( F_60 ( ! V_2 || V_3 -> V_4 ) )
return;
if ( F_6 ( ! F_129 () ) )
return;
if ( V_71 -> V_179 ) {
F_69 ( V_256 ) ;
return;
}
V_3 -> V_4 = 1 ;
V_71 -> V_179 = 1 ;
V_71 -> V_235 = V_12 ;
V_71 -> V_234 = ++ V_71 -> V_229 ;
F_69 ( V_257 ) ;
if ( V_71 -> V_178 )
F_149 ( V_71 , V_249 ) ;
V_3 -> V_4 = 0 ;
}
void F_161 ( unsigned long V_12 )
{
struct V_70 * V_71 = V_3 ;
if ( F_60 ( ! V_2 || V_3 -> V_4 ) )
return;
if ( F_6 ( ! F_129 () ) )
return;
if ( V_71 -> V_179 ) {
V_71 -> V_179 = 0 ;
V_71 -> V_237 = V_12 ;
V_71 -> V_236 = ++ V_71 -> V_229 ;
F_69 ( V_258 ) ;
F_6 ( ! F_114 () ) ;
} else
F_69 ( V_259 ) ;
}
static void F_162 ( T_6 V_260 , unsigned long V_97 )
{
struct V_70 * V_71 = V_3 ;
if ( F_60 ( ! V_2 ) )
return;
if ( ! ( V_260 & V_261 ) )
return;
if ( ( V_71 -> V_97 & V_262 ) && ! ( V_260 & V_263 ) )
return;
if ( ! ( V_260 & V_264 ) )
return;
if ( F_6 ( F_163 ( V_97 ) ) )
return;
F_149 ( V_71 , V_265 ) ;
}
void F_164 ( T_6 V_260 )
{
unsigned long V_97 ;
if ( F_60 ( V_3 -> V_4 ) )
return;
F_67 ( V_97 ) ;
F_165 ( V_97 ) ;
V_3 -> V_4 = 1 ;
F_162 ( V_260 , V_97 ) ;
V_3 -> V_4 = 0 ;
F_68 ( V_97 ) ;
}
static int F_166 ( struct V_70 * V_71 , struct V_7 * V_8 )
{
if ( ! V_8 -> V_201 ) {
if ( V_8 -> V_40 ) {
if ( V_71 -> V_174 )
if ( ! F_151 ( V_71 , V_8 ,
V_266 ) )
return 0 ;
if ( V_71 -> V_176 )
if ( ! F_151 ( V_71 , V_8 ,
V_267 ) )
return 0 ;
} else {
if ( V_71 -> V_174 )
if ( ! F_151 ( V_71 , V_8 , V_268 ) )
return 0 ;
if ( V_71 -> V_176 )
if ( ! F_151 ( V_71 , V_8 , V_269 ) )
return 0 ;
}
}
if ( ! V_8 -> V_270 ) {
if ( V_8 -> V_40 ) {
if ( ! F_151 ( V_71 , V_8 ,
V_271 ) )
return 0 ;
if ( V_71 -> V_179 )
if ( ! F_151 ( V_71 , V_8 ,
V_272 ) )
return 0 ;
} else {
if ( ! F_151 ( V_71 , V_8 ,
V_273 ) )
return 0 ;
if ( V_71 -> V_179 )
if ( ! F_151 ( V_71 , V_8 ,
V_274 ) )
return 0 ;
}
}
if ( ! V_8 -> V_201 && ( V_71 -> V_275 & V_264 ) ) {
if ( V_8 -> V_40 ) {
if ( ! F_151 ( V_71 , V_8 , V_276 ) )
return 0 ;
} else {
if ( ! F_151 ( V_71 , V_8 , V_277 ) )
return 0 ;
}
}
return 1 ;
}
static int F_167 ( struct V_70 * V_71 ,
struct V_7 * V_8 )
{
unsigned int V_72 = V_71 -> V_73 ;
V_8 -> V_200 = 2 * ( V_71 -> V_174 ? 1 : 0 ) +
V_71 -> V_176 ;
if ( V_72 ) {
struct V_7 * V_220 ;
V_220 = V_71 -> V_75 + V_72 - 1 ;
if ( V_220 -> V_200 != V_8 -> V_200 )
return 1 ;
}
return 0 ;
}
static inline
int F_148 ( struct V_70 * V_71 , struct V_7 * V_114 ,
enum V_56 V_186 )
{
F_81 ( 1 ) ;
return 1 ;
}
static inline int F_166 ( struct V_70 * V_71 ,
struct V_7 * V_8 )
{
return 1 ;
}
static inline int F_167 ( struct V_70 * V_71 ,
struct V_7 * V_8 )
{
return 0 ;
}
void F_164 ( T_6 V_260 )
{
}
static int F_151 ( struct V_70 * V_71 , struct V_7 * V_114 ,
enum V_56 V_186 )
{
unsigned int V_278 = 1 << V_186 , V_5 = 1 ;
if ( F_66 ( F_9 ( V_114 ) -> V_59 & V_278 ) )
return 1 ;
if ( ! F_1 () )
return 0 ;
if ( F_60 ( F_9 ( V_114 ) -> V_59 & V_278 ) ) {
F_4 () ;
return 1 ;
}
F_9 ( V_114 ) -> V_59 |= V_278 ;
if ( ! F_31 ( F_9 ( V_114 ) -> V_155 + V_186 ) )
return 0 ;
switch ( V_186 ) {
#define F_39 ( T_2 ) \
case LOCK_USED_IN_##__STATE: \
case LOCK_USED_IN_##__STATE##_READ: \
case LOCK_ENABLED_##__STATE: \
case LOCK_ENABLED_##__STATE##_READ:
#include "lockdep_states.h"
#undef F_39
V_5 = F_148 ( V_71 , V_114 , V_186 ) ;
if ( ! V_5 )
return 0 ;
break;
case V_279 :
F_168 ( V_102 ) ;
break;
default:
if ( ! F_7 () )
return 0 ;
F_81 ( 1 ) ;
return 0 ;
}
F_4 () ;
if ( V_5 == 2 ) {
F_30 ( L_109 , V_154 [ V_186 ] ) ;
F_43 ( V_114 ) ;
F_139 ( V_71 ) ;
F_33 () ;
}
return V_5 ;
}
void F_169 ( struct V_66 * V_67 , const char * V_63 ,
struct V_95 * V_54 , int V_65 )
{
int V_13 ;
F_170 ( V_67 , sizeof( * V_67 ) ) ;
for ( V_13 = 0 ; V_13 < V_109 ; V_13 ++ )
V_67 -> V_108 [ V_13 ] = NULL ;
#ifdef F_171
V_67 -> V_26 = F_172 () ;
#endif
if ( F_6 ( ! V_63 ) ) {
V_67 -> V_63 = L_110 ;
return;
}
V_67 -> V_63 = V_63 ;
if ( F_6 ( ! V_54 ) )
return;
if ( ! F_51 ( V_54 ) ) {
F_30 ( L_111 , V_54 ) ;
F_6 ( 1 ) ;
return;
}
V_67 -> V_54 = V_54 ;
if ( F_60 ( ! V_2 ) )
return;
if ( V_65 )
F_65 ( V_67 , V_65 , 1 ) ;
}
static int
F_173 ( struct V_70 * V_71 ,
struct V_7 * V_8 ,
unsigned long V_12 )
{
if ( ! F_8 () )
return 0 ;
if ( V_138 )
return 0 ;
F_30 ( L_23 ) ;
F_30 ( L_112 ) ;
F_30 ( L_113 ) ;
F_47 () ;
F_30 ( L_114 ) ;
F_30 ( L_115 , V_71 -> V_74 , F_46 ( V_71 ) ) ;
F_43 ( V_8 ) ;
F_30 ( L_116 ) ;
F_30 ( L_1 , V_8 -> V_197 -> V_63 ) ;
F_30 ( L_45 ) ;
F_33 () ;
F_30 ( L_81 ) ;
F_45 ( V_71 ) ;
F_30 ( L_45 ) ;
F_33 () ;
return 0 ;
}
static int F_174 ( struct V_66 * V_67 , unsigned int V_65 ,
int V_201 , int V_40 , int V_219 , int V_270 ,
struct V_66 * V_197 , unsigned long V_12 ,
int V_280 )
{
struct V_70 * V_71 = V_3 ;
struct V_6 * V_24 = NULL ;
struct V_7 * V_8 ;
unsigned int V_72 , V_221 ;
int V_218 = 0 ;
int V_9 ;
T_1 V_206 ;
if ( ! V_281 )
V_219 = 1 ;
if ( F_60 ( ! V_2 ) )
return 0 ;
if ( F_6 ( ! F_129 () ) )
return 0 ;
if ( V_67 -> V_54 == & V_247 )
V_219 = 1 ;
if ( V_65 < V_109 )
V_24 = V_67 -> V_108 [ V_65 ] ;
if ( F_60 ( ! V_24 ) ) {
V_24 = F_65 ( V_67 , V_65 , 0 ) ;
if ( ! V_24 )
return 0 ;
}
F_175 ( ( V_282 * ) & V_24 -> V_151 ) ;
if ( F_50 ( V_24 ) ) {
F_30 ( L_117 , V_24 -> V_54 , V_24 -> V_63 ) ;
if ( V_24 -> V_64 > 1 )
F_30 ( L_6 , V_24 -> V_64 ) ;
F_30 ( L_23 ) ;
F_33 () ;
}
V_72 = V_71 -> V_73 ;
if ( F_6 ( V_72 >= V_283 ) )
return 0 ;
V_9 = V_24 - V_10 + 1 ;
if ( V_72 ) {
V_8 = V_71 -> V_75 + V_72 - 1 ;
if ( V_8 -> V_9 == V_9 && V_197 ) {
if ( V_8 -> V_280 )
V_8 -> V_280 ++ ;
else
V_8 -> V_280 = 2 ;
return 1 ;
}
}
V_8 = V_71 -> V_75 + V_72 ;
if ( F_6 ( ! V_24 ) )
return 0 ;
V_8 -> V_9 = V_9 ;
V_8 -> V_69 = V_12 ;
V_8 -> V_196 = V_67 ;
V_8 -> V_197 = V_197 ;
V_8 -> V_201 = V_201 ;
V_8 -> V_40 = V_40 ;
V_8 -> V_219 = V_219 ;
V_8 -> V_270 = ! ! V_270 ;
V_8 -> V_280 = V_280 ;
#ifdef F_171
V_8 -> V_284 = 0 ;
V_8 -> V_39 = F_10 () ;
#endif
if ( V_219 == 2 && ! F_166 ( V_71 , V_8 ) )
return 0 ;
if ( ! F_151 ( V_71 , V_8 , V_279 ) )
return 0 ;
V_221 = V_24 - V_10 ;
if ( F_6 ( V_221 >= V_101 ) )
return 0 ;
V_206 = V_71 -> V_223 ;
if ( ! V_72 ) {
if ( F_6 ( V_206 != 0 ) )
return 0 ;
V_218 = 1 ;
}
V_8 -> V_222 = V_206 ;
if ( F_167 ( V_71 , V_8 ) ) {
V_206 = 0 ;
V_218 = 1 ;
}
V_206 = F_132 ( V_206 , V_221 ) ;
if ( V_197 && ! F_176 ( V_197 ) )
return F_173 ( V_71 , V_8 , V_12 ) ;
if ( ! F_130 ( V_71 , V_67 , V_8 , V_218 , V_206 ) )
return 0 ;
V_71 -> V_223 = V_206 ;
V_71 -> V_73 ++ ;
F_131 ( V_71 ) ;
#ifdef F_59
if ( F_60 ( ! V_2 ) )
return 0 ;
#endif
if ( F_60 ( V_71 -> V_73 >= V_283 ) ) {
F_8 () ;
F_29 ( L_118 ) ;
F_30 ( V_43 L_119 ,
V_71 -> V_73 , V_283 ) ;
F_45 ( V_3 ) ;
F_177 () ;
F_33 () ;
return 0 ;
}
if ( F_60 ( V_71 -> V_73 > V_285 ) )
V_285 = V_71 -> V_73 ;
return 1 ;
}
static int
F_178 ( struct V_70 * V_71 , struct V_66 * V_67 ,
unsigned long V_12 )
{
if ( ! F_8 () )
return 0 ;
if ( V_138 )
return 0 ;
F_30 ( L_23 ) ;
F_30 ( L_120 ) ;
F_30 ( L_121 ) ;
F_47 () ;
F_30 ( L_122 ) ;
F_30 ( L_123 ,
V_71 -> V_74 , F_46 ( V_71 ) ) ;
F_42 ( V_67 ) ;
F_30 ( L_124 ) ;
F_44 ( V_12 ) ;
F_30 ( L_125 ) ;
F_30 ( L_81 ) ;
F_45 ( V_71 ) ;
F_30 ( L_45 ) ;
F_33 () ;
return 0 ;
}
static int F_179 ( struct V_70 * V_71 , struct V_66 * V_67 ,
unsigned long V_12 )
{
if ( F_60 ( ! V_2 ) )
return 0 ;
if ( F_6 ( ! F_129 () ) )
return 0 ;
if ( V_71 -> V_73 <= 0 )
return F_178 ( V_71 , V_67 , V_12 ) ;
return 1 ;
}
static int F_180 ( struct V_7 * V_8 , struct V_66 * V_67 )
{
if ( V_8 -> V_196 == V_67 )
return 1 ;
if ( V_8 -> V_280 ) {
struct V_6 * V_24 = V_67 -> V_108 [ 0 ] ;
if ( ! V_24 )
V_24 = F_58 ( V_67 , 0 ) ;
if ( ! V_24 )
return 0 ;
if ( F_6 ( ! V_8 -> V_197 ) )
return 0 ;
if ( V_8 -> V_9 == V_24 - V_10 + 1 )
return 1 ;
}
return 0 ;
}
static int
F_181 ( struct V_66 * V_67 , const char * V_63 ,
struct V_95 * V_54 , unsigned int V_65 ,
unsigned long V_12 )
{
struct V_70 * V_71 = V_3 ;
struct V_7 * V_8 , * V_220 ;
struct V_6 * V_24 ;
unsigned int V_72 ;
int V_13 ;
V_72 = V_71 -> V_73 ;
if ( F_6 ( ! V_72 ) )
return 0 ;
V_220 = NULL ;
for ( V_13 = V_72 - 1 ; V_13 >= 0 ; V_13 -- ) {
V_8 = V_71 -> V_75 + V_13 ;
if ( V_220 && V_220 -> V_200 != V_8 -> V_200 )
break;
if ( F_180 ( V_8 , V_67 ) )
goto V_286;
V_220 = V_8 ;
}
return F_178 ( V_71 , V_67 , V_12 ) ;
V_286:
F_169 ( V_67 , V_63 , V_54 , 0 ) ;
V_24 = F_65 ( V_67 , V_65 , 0 ) ;
V_8 -> V_9 = V_24 - V_10 + 1 ;
V_71 -> V_73 = V_13 ;
V_71 -> V_223 = V_8 -> V_222 ;
for (; V_13 < V_72 ; V_13 ++ ) {
V_8 = V_71 -> V_75 + V_13 ;
if ( ! F_174 ( V_8 -> V_196 ,
F_9 ( V_8 ) -> V_65 , V_8 -> V_201 ,
V_8 -> V_40 , V_8 -> V_219 , V_8 -> V_270 ,
V_8 -> V_197 , V_8 -> V_69 ,
V_8 -> V_280 ) )
return 0 ;
}
if ( F_6 ( V_71 -> V_73 != V_72 ) )
return 0 ;
return 1 ;
}
static int
F_182 ( struct V_70 * V_71 ,
struct V_66 * V_67 , unsigned long V_12 )
{
struct V_7 * V_8 , * V_220 ;
unsigned int V_72 ;
int V_13 ;
V_72 = V_71 -> V_73 ;
if ( F_6 ( ! V_72 ) )
return 0 ;
V_220 = NULL ;
for ( V_13 = V_72 - 1 ; V_13 >= 0 ; V_13 -- ) {
V_8 = V_71 -> V_75 + V_13 ;
if ( V_220 && V_220 -> V_200 != V_8 -> V_200 )
break;
if ( F_180 ( V_8 , V_67 ) )
goto V_286;
V_220 = V_8 ;
}
return F_178 ( V_71 , V_67 , V_12 ) ;
V_286:
if ( V_8 -> V_196 == V_67 )
F_24 ( V_8 ) ;
if ( V_8 -> V_280 ) {
V_8 -> V_280 -- ;
if ( V_8 -> V_280 ) {
return 1 ;
}
}
V_71 -> V_73 = V_13 ;
V_71 -> V_223 = V_8 -> V_222 ;
for ( V_13 ++ ; V_13 < V_72 ; V_13 ++ ) {
V_8 = V_71 -> V_75 + V_13 ;
if ( ! F_174 ( V_8 -> V_196 ,
F_9 ( V_8 ) -> V_65 , V_8 -> V_201 ,
V_8 -> V_40 , V_8 -> V_219 , V_8 -> V_270 ,
V_8 -> V_197 , V_8 -> V_69 ,
V_8 -> V_280 ) )
return 0 ;
}
if ( F_6 ( V_71 -> V_73 != V_72 - 1 ) )
return 0 ;
return 1 ;
}
static int F_183 ( struct V_70 * V_71 ,
struct V_66 * V_67 , unsigned long V_12 )
{
struct V_7 * V_8 ;
unsigned int V_72 ;
V_72 = V_71 -> V_73 - 1 ;
V_8 = V_71 -> V_75 + V_72 ;
if ( V_8 -> V_196 != V_67 || V_8 -> V_280 )
return F_182 ( V_71 , V_67 , V_12 ) ;
V_71 -> V_73 -- ;
if ( F_6 ( ! V_72 && ( V_8 -> V_222 != 0 ) ) )
return 0 ;
V_71 -> V_223 = V_8 -> V_222 ;
F_24 ( V_8 ) ;
#ifdef F_59
V_8 -> V_222 = 0 ;
V_8 -> V_9 = 0 ;
V_8 -> V_69 = 0 ;
V_8 -> V_200 = 0 ;
#endif
return 1 ;
}
static void
F_184 ( struct V_66 * V_67 , int V_287 , unsigned long V_12 )
{
struct V_70 * V_71 = V_3 ;
if ( ! F_179 ( V_71 , V_67 , V_12 ) )
return;
if ( V_287 ) {
if ( ! F_183 ( V_71 , V_67 , V_12 ) )
return;
} else {
if ( ! F_182 ( V_71 , V_67 , V_12 ) )
return;
}
F_131 ( V_71 ) ;
}
static int F_176 ( struct V_66 * V_67 )
{
struct V_70 * V_71 = V_3 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_71 -> V_73 ; V_13 ++ ) {
struct V_7 * V_8 = V_71 -> V_75 + V_13 ;
if ( F_180 ( V_8 , V_67 ) )
return 1 ;
}
return 0 ;
}
static void F_165 ( unsigned long V_97 )
{
#if F_185 ( V_288 ) && F_185 ( F_59 ) && \
F_185 ( V_289 )
if ( ! V_2 )
return;
if ( F_163 ( V_97 ) ) {
if ( F_6 ( V_3 -> V_178 ) ) {
F_30 ( L_126 ) ;
}
} else {
if ( F_6 ( ! V_3 -> V_178 ) ) {
F_30 ( L_127 ) ;
}
}
if ( ! F_113 () ) {
if ( F_114 () ) {
F_6 ( V_3 -> V_179 ) ;
} else {
F_6 ( ! V_3 -> V_179 ) ;
}
}
if ( ! V_2 )
F_139 ( V_3 ) ;
#endif
}
void F_186 ( struct V_66 * V_67 , const char * V_63 ,
struct V_95 * V_54 , unsigned int V_65 ,
unsigned long V_12 )
{
unsigned long V_97 ;
if ( F_60 ( V_3 -> V_4 ) )
return;
F_67 ( V_97 ) ;
V_3 -> V_4 = 1 ;
F_165 ( V_97 ) ;
if ( F_181 ( V_67 , V_63 , V_54 , V_65 , V_12 ) )
F_131 ( V_3 ) ;
V_3 -> V_4 = 0 ;
F_68 ( V_97 ) ;
}
void F_187 ( struct V_66 * V_67 , unsigned int V_65 ,
int V_201 , int V_40 , int V_219 ,
struct V_66 * V_197 , unsigned long V_12 )
{
unsigned long V_97 ;
if ( F_60 ( V_3 -> V_4 ) )
return;
F_67 ( V_97 ) ;
F_165 ( V_97 ) ;
V_3 -> V_4 = 1 ;
F_188 ( V_67 , V_65 , V_201 , V_40 , V_219 , V_197 , V_12 ) ;
F_174 ( V_67 , V_65 , V_201 , V_40 , V_219 ,
F_163 ( V_97 ) , V_197 , V_12 , 0 ) ;
V_3 -> V_4 = 0 ;
F_68 ( V_97 ) ;
}
void F_189 ( struct V_66 * V_67 , int V_287 ,
unsigned long V_12 )
{
unsigned long V_97 ;
if ( F_60 ( V_3 -> V_4 ) )
return;
F_67 ( V_97 ) ;
F_165 ( V_97 ) ;
V_3 -> V_4 = 1 ;
F_190 ( V_67 , V_12 ) ;
F_184 ( V_67 , V_287 , V_12 ) ;
V_3 -> V_4 = 0 ;
F_68 ( V_97 ) ;
}
int F_191 ( struct V_66 * V_67 )
{
unsigned long V_97 ;
int V_5 = 0 ;
if ( F_60 ( V_3 -> V_4 ) )
return 1 ;
F_67 ( V_97 ) ;
F_165 ( V_97 ) ;
V_3 -> V_4 = 1 ;
V_5 = F_176 ( V_67 ) ;
V_3 -> V_4 = 0 ;
F_68 ( V_97 ) ;
return V_5 ;
}
void F_192 ( T_6 V_260 )
{
V_3 -> V_275 = V_260 ;
}
void F_193 ( void )
{
V_3 -> V_275 = 0 ;
}
static int
F_194 ( struct V_70 * V_71 , struct V_66 * V_67 ,
unsigned long V_12 )
{
if ( ! F_8 () )
return 0 ;
if ( V_138 )
return 0 ;
F_30 ( L_23 ) ;
F_30 ( L_90 ) ;
F_30 ( L_128 ) ;
F_47 () ;
F_30 ( L_92 ) ;
F_30 ( L_129 ,
V_71 -> V_74 , F_46 ( V_71 ) ) ;
F_42 ( V_67 ) ;
F_30 ( L_124 ) ;
F_44 ( V_12 ) ;
F_30 ( L_130 ) ;
F_30 ( L_81 ) ;
F_45 ( V_71 ) ;
F_30 ( L_45 ) ;
F_33 () ;
return 0 ;
}
static void
F_195 ( struct V_66 * V_67 , unsigned long V_12 )
{
struct V_70 * V_71 = V_3 ;
struct V_7 * V_8 , * V_220 ;
struct V_23 * V_25 ;
unsigned int V_72 ;
int V_13 , V_29 , V_30 ;
V_72 = V_71 -> V_73 ;
if ( F_6 ( ! V_72 ) )
return;
V_220 = NULL ;
for ( V_13 = V_72 - 1 ; V_13 >= 0 ; V_13 -- ) {
V_8 = V_71 -> V_75 + V_13 ;
if ( V_220 && V_220 -> V_200 != V_8 -> V_200 )
break;
if ( F_180 ( V_8 , V_67 ) )
goto V_286;
V_220 = V_8 ;
}
F_194 ( V_71 , V_67 , V_12 ) ;
return;
V_286:
if ( V_8 -> V_196 != V_67 )
return;
V_8 -> V_284 = F_10 () ;
V_29 = F_12 ( F_9 ( V_8 ) -> V_29 , V_12 ) ;
V_30 = F_12 ( F_9 ( V_8 ) -> V_30 ,
V_67 -> V_12 ) ;
V_25 = F_20 ( F_9 ( V_8 ) ) ;
if ( V_29 < V_14 )
V_25 -> V_29 [ V_29 ] ++ ;
if ( V_30 < V_14 )
V_25 -> V_30 [ V_30 ] ++ ;
if ( V_67 -> V_26 != F_196 () )
V_25 -> V_35 [ V_290 + ! ! V_8 -> V_40 ] ++ ;
F_22 ( V_25 ) ;
}
static void
F_197 ( struct V_66 * V_67 , unsigned long V_12 )
{
struct V_70 * V_71 = V_3 ;
struct V_7 * V_8 , * V_220 ;
struct V_23 * V_25 ;
unsigned int V_72 ;
T_1 V_291 , V_292 = 0 ;
int V_13 , V_26 ;
V_72 = V_71 -> V_73 ;
if ( F_6 ( ! V_72 ) )
return;
V_220 = NULL ;
for ( V_13 = V_72 - 1 ; V_13 >= 0 ; V_13 -- ) {
V_8 = V_71 -> V_75 + V_13 ;
if ( V_220 && V_220 -> V_200 != V_8 -> V_200 )
break;
if ( F_180 ( V_8 , V_67 ) )
goto V_286;
V_220 = V_8 ;
}
F_194 ( V_71 , V_67 , V_293 ) ;
return;
V_286:
if ( V_8 -> V_196 != V_67 )
return;
V_26 = F_196 () ;
if ( V_8 -> V_284 ) {
V_291 = F_10 () ;
V_292 = V_291 - V_8 -> V_284 ;
V_8 -> V_39 = V_291 ;
}
F_198 ( V_67 , V_12 ) ;
V_25 = F_20 ( F_9 ( V_8 ) ) ;
if ( V_292 ) {
if ( V_8 -> V_40 )
F_13 ( & V_25 -> V_31 , V_292 ) ;
else
F_13 ( & V_25 -> V_32 , V_292 ) ;
}
if ( V_67 -> V_26 != V_26 )
V_25 -> V_35 [ V_294 + ! ! V_8 -> V_40 ] ++ ;
F_22 ( V_25 ) ;
V_67 -> V_26 = V_26 ;
V_67 -> V_12 = V_12 ;
}
void F_199 ( struct V_66 * V_67 , unsigned long V_12 )
{
unsigned long V_97 ;
if ( F_60 ( ! V_38 ) )
return;
if ( F_60 ( V_3 -> V_4 ) )
return;
F_67 ( V_97 ) ;
F_165 ( V_97 ) ;
V_3 -> V_4 = 1 ;
F_200 ( V_67 , V_12 ) ;
F_195 ( V_67 , V_12 ) ;
V_3 -> V_4 = 0 ;
F_68 ( V_97 ) ;
}
void F_201 ( struct V_66 * V_67 , unsigned long V_12 )
{
unsigned long V_97 ;
if ( F_60 ( ! V_38 ) )
return;
if ( F_60 ( V_3 -> V_4 ) )
return;
F_67 ( V_97 ) ;
F_165 ( V_97 ) ;
V_3 -> V_4 = 1 ;
F_197 ( V_67 , V_12 ) ;
V_3 -> V_4 = 0 ;
F_68 ( V_97 ) ;
}
void F_202 ( void )
{
unsigned long V_97 ;
int V_13 ;
F_67 ( V_97 ) ;
V_3 -> V_223 = 0 ;
V_3 -> V_73 = 0 ;
V_3 -> V_4 = 0 ;
memset ( V_3 -> V_75 , 0 , V_283 * sizeof( struct V_7 ) ) ;
V_189 = 0 ;
V_190 = 0 ;
V_191 = 0 ;
V_2 = 1 ;
for ( V_13 = 0 ; V_13 < V_295 ; V_13 ++ )
F_70 ( V_296 + V_13 ) ;
F_68 ( V_97 ) ;
}
static void F_203 ( struct V_6 * V_24 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_111 ; V_13 ++ ) {
if ( V_113 [ V_13 ] . V_24 == V_24 )
F_204 ( & V_113 [ V_13 ] . V_117 ) ;
}
F_204 ( & V_24 -> V_106 ) ;
F_204 ( & V_24 -> V_103 ) ;
V_24 -> V_54 = NULL ;
}
static inline int F_205 ( const void * V_84 , void * V_80 , unsigned long V_297 )
{
return V_84 >= V_80 && V_84 < V_80 + V_297 ;
}
void F_206 ( void * V_80 , unsigned long V_297 )
{
struct V_6 * V_24 , * V_170 ;
struct V_87 * V_115 ;
unsigned long V_97 ;
int V_13 ;
int V_298 ;
F_67 ( V_97 ) ;
V_298 = F_1 () ;
for ( V_13 = 0 ; V_13 < V_299 ; V_13 ++ ) {
V_115 = V_300 + V_13 ;
if ( F_87 ( V_115 ) )
continue;
F_207 (class, next, head, hash_entry) {
if ( F_205 ( V_24 -> V_54 , V_80 , V_297 ) )
F_203 ( V_24 ) ;
else if ( F_205 ( V_24 -> V_63 , V_80 , V_297 ) )
F_203 ( V_24 ) ;
}
}
if ( V_298 )
F_4 () ;
F_68 ( V_97 ) ;
}
void F_208 ( struct V_66 * V_67 )
{
struct V_6 * V_24 , * V_170 ;
struct V_87 * V_115 ;
unsigned long V_97 ;
int V_13 , V_208 ;
int V_298 ;
F_67 ( V_97 ) ;
for ( V_208 = 0 ; V_208 < V_93 ; V_208 ++ ) {
V_24 = F_58 ( V_67 , V_208 ) ;
if ( V_24 )
F_203 ( V_24 ) ;
}
V_298 = F_1 () ;
for ( V_13 = 0 ; V_13 < V_299 ; V_13 ++ ) {
V_115 = V_300 + V_13 ;
if ( F_87 ( V_115 ) )
continue;
F_207 (class, next, head, hash_entry) {
int F_86 = 0 ;
for ( V_208 = 0 ; V_208 < V_109 ; V_208 ++ )
F_86 |= V_24 == V_67 -> V_108 [ V_208 ] ;
if ( F_60 ( F_86 ) ) {
if ( F_7 () ) {
F_81 ( 1 ) ;
}
goto V_301;
}
}
}
if ( V_298 )
F_4 () ;
V_301:
F_68 ( V_97 ) ;
}
void F_61 ( void )
{
int V_13 ;
if ( V_89 )
return;
for ( V_13 = 0 ; V_13 < V_299 ; V_13 ++ )
F_70 ( V_300 + V_13 ) ;
for ( V_13 = 0 ; V_13 < V_295 ; V_13 ++ )
F_70 ( V_296 + V_13 ) ;
V_89 = 1 ;
}
void T_7 F_209 ( void )
{
F_30 ( L_131 ) ;
F_30 ( L_132 , V_93 ) ;
F_30 ( L_133 , V_283 ) ;
F_30 ( L_134 , V_101 ) ;
F_30 ( L_135 , V_299 ) ;
F_30 ( L_136 , V_112 ) ;
F_30 ( L_137 , V_212 ) ;
F_30 ( L_138 , V_295 ) ;
F_30 ( L_139 ,
( sizeof( struct V_6 ) * V_101 +
sizeof( struct V_87 ) * V_299 +
sizeof( struct V_110 ) * V_112 +
sizeof( struct V_202 ) * V_212 +
sizeof( struct V_87 ) * V_295
#ifdef V_288
+ sizeof( struct V_118 )
#endif
) / 1024
) ;
F_30 ( L_140 ,
sizeof( struct V_7 ) * V_283 ) ;
#ifdef F_59
if ( V_90 ) {
F_30 ( L_141
L_142 , V_91 ) ;
F_30 ( L_143 ) ;
F_91 ( & V_92 , 0 ) ;
}
#endif
}
static void
F_210 ( struct V_70 * V_71 , const void * V_302 ,
const void * V_303 , struct V_7 * V_8 )
{
if ( ! F_8 () )
return;
if ( V_138 )
return;
F_30 ( L_23 ) ;
F_30 ( L_144 ) ;
F_30 ( L_145 ) ;
F_47 () ;
F_30 ( L_146 ) ;
F_30 ( L_147 ,
V_71 -> V_74 , F_46 ( V_71 ) , V_302 , V_303 - 1 ) ;
F_43 ( V_8 ) ;
F_45 ( V_71 ) ;
F_30 ( L_45 ) ;
F_33 () ;
}
static inline int F_211 ( const void * V_302 , unsigned long V_304 ,
const void * V_305 , unsigned long V_306 )
{
return V_305 + V_306 <= V_302 ||
V_302 + V_304 <= V_305 ;
}
void F_212 ( const void * V_302 , unsigned long V_304 )
{
struct V_70 * V_71 = V_3 ;
struct V_7 * V_8 ;
unsigned long V_97 ;
int V_13 ;
if ( F_60 ( ! V_2 ) )
return;
F_101 ( V_97 ) ;
for ( V_13 = 0 ; V_13 < V_71 -> V_73 ; V_13 ++ ) {
V_8 = V_71 -> V_75 + V_13 ;
if ( F_211 ( V_302 , V_304 , V_8 -> V_196 ,
sizeof( * V_8 -> V_196 ) ) )
continue;
F_210 ( V_71 , V_302 , V_302 + V_304 , V_8 ) ;
break;
}
F_102 ( V_97 ) ;
}
static void F_213 ( void )
{
if ( ! F_8 () )
return;
if ( V_138 )
return;
F_30 ( L_23 ) ;
F_30 ( L_120 ) ;
F_30 ( L_148 ,
V_3 -> V_74 , F_46 ( V_3 ) ) ;
F_47 () ;
F_30 ( L_122 ) ;
F_45 ( V_3 ) ;
F_30 ( L_45 ) ;
F_33 () ;
}
void F_214 ( void )
{
if ( F_60 ( V_3 -> V_73 > 0 ) )
F_213 () ;
}
void F_177 ( void )
{
struct V_70 * V_307 , * V_308 ;
int V_86 = 10 ;
int V_309 = 1 ;
if ( F_60 ( ! V_2 ) ) {
F_30 ( L_149 ) ;
return;
}
F_30 ( L_150 ) ;
V_310:
if ( ! F_215 ( & V_311 ) ) {
if ( V_86 == 10 )
F_30 ( L_151 ) ;
if ( V_86 ) {
V_86 -- ;
F_30 ( L_152 , 10 - V_86 ) ;
F_216 ( 200 ) ;
goto V_310;
}
F_30 ( L_153 ) ;
V_309 = 0 ;
} else {
if ( V_86 != 10 )
F_30 ( V_312 L_154 ) ;
}
F_217 (g, p) {
if ( V_308 -> V_187 == V_313 && V_308 != V_3 )
continue;
if ( V_308 -> V_73 )
F_45 ( V_308 ) ;
if ( ! V_309 )
if ( F_215 ( & V_311 ) )
V_309 = 1 ;
} F_218 ( V_307 , V_308 ) ;
F_30 ( L_23 ) ;
F_30 ( L_155 ) ;
if ( V_309 )
F_219 ( & V_311 ) ;
}
void F_220 ( struct V_70 * V_314 )
{
if ( F_60 ( ! V_2 ) ) {
F_30 ( L_149 ) ;
return;
}
F_45 ( V_314 ) ;
}
void F_221 ( void )
{
struct V_70 * V_71 = V_3 ;
if ( F_60 ( V_71 -> V_73 ) ) {
if ( ! F_8 () )
return;
F_30 ( L_23 ) ;
F_30 ( L_156 ) ;
F_30 ( L_157 ) ;
F_47 () ;
F_30 ( L_158 ) ;
F_30 ( L_159 ,
V_71 -> V_74 , V_71 -> V_315 ) ;
F_45 ( V_71 ) ;
}
}
void F_222 ( const char * V_316 , const int line , const char * V_317 )
{
struct V_70 * V_71 = V_3 ;
#ifndef F_223
if ( ! F_8 () )
return;
#endif
F_30 ( L_23 ) ;
F_30 ( L_160 ) ;
F_30 ( L_161 ) ;
F_47 () ;
F_30 ( L_162 ) ;
F_30 ( L_163 , V_316 , line , V_317 ) ;
F_30 ( L_44 ) ;
F_30 ( L_164 ,
! F_224 ()
? L_165
: F_225 ()
? L_166
: L_14 ,
V_318 , V_2 ) ;
if ( F_225 () )
F_30 ( L_167 ) ;
F_45 ( V_71 ) ;
F_30 ( L_45 ) ;
F_33 () ;
}
