static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 1 ;
}
unsigned int F_2 ( struct V_3 * V_4 )
{
return V_4 -> V_5 ;
}
static int F_3 ( const char * V_6 , T_2 V_7 )
{
struct V_3 * V_4 = NULL ;
if ( ! V_6 || F_4 () || V_7 < sizeof( void * ) ||
V_7 > V_8 ) {
F_5 ( L_1 , V_6 ) ;
return - V_9 ;
}
F_6 (s, &slab_caches, list) {
char V_10 ;
int V_11 ;
V_11 = F_7 ( V_4 -> V_6 , V_10 ) ;
if ( V_11 ) {
F_5 ( L_2 ,
V_4 -> V_5 ) ;
continue;
}
}
F_8 ( strchr ( V_6 , ' ' ) ) ;
return 0 ;
}
static inline int F_3 ( const char * V_6 , T_2 V_7 )
{
return 0 ;
}
void F_9 ( struct V_3 * V_4 )
{
V_4 -> V_12 . V_13 = true ;
F_10 ( & V_4 -> V_12 . V_14 ) ;
F_11 ( V_4 -> V_12 . V_15 , NULL ) ;
}
static int F_12 ( struct V_3 * V_4 ,
struct V_16 * V_17 , struct V_3 * V_18 )
{
struct V_19 * V_20 ;
if ( V_17 ) {
V_4 -> V_12 . V_13 = false ;
V_4 -> V_12 . V_17 = V_17 ;
V_4 -> V_12 . V_18 = V_18 ;
return 0 ;
}
F_9 ( V_4 ) ;
if ( ! V_21 )
return 0 ;
V_20 = F_13 ( sizeof( struct V_19 ) +
V_21 * sizeof( void * ) ,
V_22 ) ;
if ( ! V_20 )
return - V_23 ;
F_11 ( V_4 -> V_12 . V_15 , V_20 ) ;
return 0 ;
}
static void F_14 ( struct V_3 * V_4 )
{
if ( V_13 ( V_4 ) )
F_15 ( F_16 ( V_4 -> V_12 . V_15 ) ) ;
}
static int F_17 ( struct V_3 * V_4 , int V_24 )
{
struct V_19 * V_25 , * V_26 ;
if ( ! V_13 ( V_4 ) )
return 0 ;
V_26 = F_13 ( sizeof( struct V_19 ) +
V_24 * sizeof( void * ) , V_22 ) ;
if ( ! V_26 )
return - V_23 ;
V_25 = F_18 ( V_4 -> V_12 . V_15 ,
F_19 ( & V_27 ) ) ;
if ( V_25 )
memcpy ( V_26 -> V_28 , V_25 -> V_28 ,
V_21 * sizeof( void * ) ) ;
F_20 ( V_4 -> V_12 . V_15 , V_26 ) ;
if ( V_25 )
F_21 ( V_25 , V_29 ) ;
return 0 ;
}
int F_22 ( int V_30 )
{
struct V_3 * V_4 ;
int V_31 = 0 ;
F_23 ( & V_27 ) ;
F_6 (s, &slab_caches, list) {
V_31 = F_17 ( V_4 , V_30 ) ;
if ( V_31 )
break;
}
F_24 ( & V_27 ) ;
return V_31 ;
}
static inline int F_12 ( struct V_3 * V_4 ,
struct V_16 * V_17 , struct V_3 * V_18 )
{
return 0 ;
}
static inline void F_14 ( struct V_3 * V_4 )
{
}
int F_25 ( struct V_3 * V_4 )
{
if ( V_2 || ( V_4 -> V_32 & V_33 ) )
return 1 ;
if ( ! V_13 ( V_4 ) )
return 1 ;
if ( V_4 -> V_34 )
return 1 ;
if ( V_4 -> V_35 < 0 )
return 1 ;
return 0 ;
}
struct V_3 * F_26 ( T_2 V_7 , T_2 V_36 ,
unsigned long V_32 , const char * V_6 , void (* V_34)( void * ) )
{
struct V_3 * V_4 ;
if ( V_2 || ( V_32 & V_33 ) )
return NULL ;
if ( V_34 )
return NULL ;
V_7 = F_27 ( V_7 , sizeof( void * ) ) ;
V_36 = F_28 ( V_32 , V_36 , V_7 ) ;
V_7 = F_27 ( V_7 , V_36 ) ;
V_32 = F_29 ( V_7 , V_32 , V_6 , NULL ) ;
F_30 (s, &slab_caches, list) {
if ( F_25 ( V_4 ) )
continue;
if ( V_7 > V_4 -> V_7 )
continue;
if ( ( V_32 & V_37 ) != ( V_4 -> V_32 & V_37 ) )
continue;
if ( ( V_4 -> V_7 & ~ ( V_36 - 1 ) ) != V_4 -> V_7 )
continue;
if ( V_4 -> V_7 - V_7 >= sizeof( void * ) )
continue;
if ( F_31 ( V_38 ) && V_36 &&
( V_36 > V_4 -> V_36 || V_4 -> V_36 % V_36 ) )
continue;
return V_4 ;
}
return NULL ;
}
unsigned long F_28 ( unsigned long V_32 ,
unsigned long V_36 , unsigned long V_7 )
{
if ( V_32 & V_39 ) {
unsigned long V_40 = F_32 () ;
while ( V_7 <= V_40 / 2 )
V_40 /= 2 ;
V_36 = F_33 ( V_36 , V_40 ) ;
}
if ( V_36 < V_41 )
V_36 = V_41 ;
return F_27 ( V_36 , sizeof( void * ) ) ;
}
static struct V_3 *
F_34 ( const char * V_6 , T_2 V_5 , T_2 V_7 ,
T_2 V_36 , unsigned long V_32 , void (* V_34)( void * ) ,
struct V_16 * V_17 , struct V_3 * V_18 )
{
struct V_3 * V_4 ;
int V_42 ;
V_42 = - V_23 ;
V_4 = F_35 ( V_3 , V_22 ) ;
if ( ! V_4 )
goto V_43;
V_4 -> V_6 = V_6 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_36 = V_36 ;
V_4 -> V_34 = V_34 ;
V_42 = F_12 ( V_4 , V_17 , V_18 ) ;
if ( V_42 )
goto V_44;
V_42 = F_36 ( V_4 , V_32 ) ;
if ( V_42 )
goto V_44;
V_4 -> V_35 = 1 ;
F_37 ( & V_4 -> V_14 , & V_45 ) ;
V_43:
if ( V_42 )
return F_38 ( V_42 ) ;
return V_4 ;
V_44:
F_14 ( V_4 ) ;
F_39 ( V_3 , V_4 ) ;
goto V_43;
}
struct V_3 *
F_40 ( const char * V_6 , T_2 V_7 , T_2 V_36 ,
unsigned long V_32 , void (* V_34)( void * ) )
{
struct V_3 * V_4 ;
const char * V_46 ;
int V_42 ;
F_41 () ;
F_42 () ;
F_43 () ;
F_23 ( & V_27 ) ;
V_42 = F_3 ( V_6 , V_7 ) ;
if ( V_42 ) {
V_4 = NULL ;
goto V_47;
}
V_32 &= V_48 ;
V_4 = F_44 ( V_6 , V_7 , V_36 , V_32 , V_34 ) ;
if ( V_4 )
goto V_47;
V_46 = F_45 ( V_6 , V_22 ) ;
if ( ! V_46 ) {
V_42 = - V_23 ;
goto V_47;
}
V_4 = F_34 ( V_46 , V_7 , V_7 ,
F_28 ( V_32 , V_36 , V_7 ) ,
V_32 , V_34 , NULL , NULL ) ;
if ( F_46 ( V_4 ) ) {
V_42 = F_47 ( V_4 ) ;
F_48 ( V_46 ) ;
}
V_47:
F_24 ( & V_27 ) ;
F_49 () ;
F_50 () ;
F_51 () ;
if ( V_42 ) {
if ( V_32 & V_49 )
F_52 ( L_3 ,
V_6 , V_42 ) ;
else {
F_53 ( V_50 L_4 ,
V_6 , V_42 ) ;
F_54 () ;
}
return NULL ;
}
return V_4 ;
}
static int F_55 ( struct V_3 * V_4 ,
struct V_51 * V_52 , bool * V_53 )
{
if ( F_56 ( V_4 ) != 0 ) {
F_53 ( V_54 L_5
L_6 , V_4 -> V_6 ) ;
F_54 () ;
return - V_55 ;
}
if ( V_4 -> V_32 & V_56 )
* V_53 = true ;
#ifdef F_57
if ( ! V_13 ( V_4 ) )
F_58 ( & V_4 -> V_12 . V_14 ) ;
#endif
F_59 ( & V_4 -> V_14 , V_52 ) ;
return 0 ;
}
static void F_60 ( struct V_51 * V_52 ,
bool V_53 )
{
struct V_3 * V_4 , * V_57 ;
if ( V_53 )
F_61 () ;
F_62 (s, s2, release, list) {
#ifdef F_63
F_64 ( V_4 ) ;
#else
F_65 ( V_4 ) ;
#endif
}
}
void F_66 ( struct V_16 * V_17 ,
struct V_3 * V_18 )
{
static char V_58 [ V_59 + 1 ] ;
struct V_60 * V_61 = F_67 ( V_17 ) ;
struct V_19 * V_20 ;
struct V_3 * V_4 = NULL ;
char * V_46 ;
int V_62 ;
F_41 () ;
F_42 () ;
F_23 ( & V_27 ) ;
if ( ! F_68 ( V_17 ) )
goto V_47;
V_62 = F_69 ( V_17 ) ;
V_20 = F_18 ( V_18 -> V_12 . V_15 ,
F_19 ( & V_27 ) ) ;
if ( V_20 -> V_28 [ V_62 ] )
goto V_47;
F_70 ( V_61 -> V_63 , V_58 , sizeof( V_58 ) ) ;
V_46 = F_71 ( V_22 , L_7 , V_18 -> V_6 ,
V_61 -> V_64 , V_58 ) ;
if ( ! V_46 )
goto V_47;
V_4 = F_34 ( V_46 , V_18 -> V_5 ,
V_18 -> V_7 , V_18 -> V_36 ,
V_18 -> V_32 , V_18 -> V_34 ,
V_17 , V_18 ) ;
if ( F_46 ( V_4 ) ) {
F_15 ( V_46 ) ;
goto V_47;
}
F_37 ( & V_4 -> V_12 . V_14 , & V_18 -> V_12 . V_14 ) ;
F_72 () ;
V_20 -> V_28 [ V_62 ] = V_4 ;
V_47:
F_24 ( & V_27 ) ;
F_50 () ;
F_51 () ;
}
void F_73 ( struct V_16 * V_17 )
{
int V_62 ;
struct V_19 * V_20 ;
struct V_3 * V_4 , * V_65 ;
V_62 = F_69 ( V_17 ) ;
F_41 () ;
F_42 () ;
F_23 ( & V_27 ) ;
F_6 (s, &slab_caches, list) {
if ( ! V_13 ( V_4 ) )
continue;
V_20 = F_18 ( V_4 -> V_12 . V_15 ,
F_19 ( & V_27 ) ) ;
V_65 = V_20 -> V_28 [ V_62 ] ;
if ( ! V_65 )
continue;
F_74 ( V_65 , true ) ;
V_20 -> V_28 [ V_62 ] = NULL ;
}
F_24 ( & V_27 ) ;
F_50 () ;
F_51 () ;
}
void F_75 ( struct V_16 * V_17 )
{
F_76 ( V_52 ) ;
bool V_53 = false ;
struct V_3 * V_4 , * V_57 ;
F_41 () ;
F_42 () ;
F_23 ( & V_27 ) ;
F_62 (s, s2, &slab_caches, list) {
if ( V_13 ( V_4 ) || V_4 -> V_12 . V_17 != V_17 )
continue;
F_77 ( F_55 ( V_4 , & V_52 , & V_53 ) ) ;
}
F_24 ( & V_27 ) ;
F_50 () ;
F_51 () ;
F_60 ( & V_52 , V_53 ) ;
}
void F_65 ( struct V_3 * V_4 )
{
F_14 ( V_4 ) ;
F_48 ( V_4 -> V_6 ) ;
F_39 ( V_3 , V_4 ) ;
}
void F_78 ( struct V_3 * V_4 )
{
struct V_3 * V_65 , * V_66 ;
F_76 ( V_52 ) ;
bool V_53 = false ;
bool V_67 = false ;
F_77 ( ! V_13 ( V_4 ) ) ;
F_41 () ;
F_42 () ;
F_23 ( & V_27 ) ;
V_4 -> V_35 -- ;
if ( V_4 -> V_35 )
goto V_47;
F_79 (c, c2, s) {
if ( F_55 ( V_65 , & V_52 , & V_53 ) )
V_67 = true ;
}
if ( ! V_67 )
F_55 ( V_4 , & V_52 , & V_53 ) ;
V_47:
F_24 ( & V_27 ) ;
F_50 () ;
F_51 () ;
F_60 ( & V_52 , V_53 ) ;
}
int F_80 ( struct V_3 * V_68 )
{
int V_31 ;
F_41 () ;
F_42 () ;
V_31 = F_74 ( V_68 , false ) ;
F_50 () ;
F_51 () ;
return V_31 ;
}
int F_81 ( void )
{
return V_69 >= V_70 ;
}
void T_1 F_82 ( struct V_3 * V_4 , const char * V_6 , T_2 V_7 ,
unsigned long V_32 )
{
int V_42 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_7 = V_4 -> V_5 = V_7 ;
V_4 -> V_36 = F_28 ( V_32 , V_71 , V_7 ) ;
F_9 ( V_4 ) ;
V_42 = F_36 ( V_4 , V_32 ) ;
if ( V_42 )
F_52 ( L_8 ,
V_6 , V_7 , V_42 ) ;
V_4 -> V_35 = - 1 ;
}
struct V_3 * T_1 F_83 ( const char * V_6 , T_2 V_7 ,
unsigned long V_32 )
{
struct V_3 * V_4 = F_35 ( V_3 , V_72 ) ;
if ( ! V_4 )
F_52 ( L_9 , V_6 ) ;
F_82 ( V_4 , V_6 , V_7 , V_32 ) ;
F_37 ( & V_4 -> V_14 , & V_45 ) ;
V_4 -> V_35 = 1 ;
return V_4 ;
}
static inline int F_84 ( T_2 V_73 )
{
return ( V_73 - 1 ) / 8 ;
}
struct V_3 * F_85 ( T_2 V_7 , T_3 V_32 )
{
int V_74 ;
if ( F_86 ( V_7 > V_8 ) ) {
F_87 ( ! ( V_32 & V_75 ) ) ;
return NULL ;
}
if ( V_7 <= 192 ) {
if ( ! V_7 )
return V_76 ;
V_74 = V_77 [ F_84 ( V_7 ) ] ;
} else
V_74 = F_88 ( V_7 - 1 ) ;
#ifdef F_89
if ( F_86 ( ( V_32 & V_78 ) ) )
return V_79 [ V_74 ] ;
#endif
return V_80 [ V_74 ] ;
}
void T_1 F_90 ( unsigned long V_32 )
{
int V_81 ;
F_91 ( V_82 > 256 ||
( V_82 & ( V_82 - 1 ) ) ) ;
for ( V_81 = 8 ; V_81 < V_82 ; V_81 += 8 ) {
int V_83 = F_84 ( V_81 ) ;
if ( V_83 >= F_92 ( V_77 ) )
break;
V_77 [ V_83 ] = V_84 ;
}
if ( V_82 >= 64 ) {
for ( V_81 = 64 + 8 ; V_81 <= 96 ; V_81 += 8 )
V_77 [ F_84 ( V_81 ) ] = 7 ;
}
if ( V_82 >= 128 ) {
for ( V_81 = 128 + 8 ; V_81 <= 192 ; V_81 += 8 )
V_77 [ F_84 ( V_81 ) ] = 8 ;
}
for ( V_81 = V_84 ; V_81 <= V_85 ; V_81 ++ ) {
if ( ! V_80 [ V_81 ] ) {
V_80 [ V_81 ] = F_83 ( NULL ,
1 << V_81 , V_32 ) ;
}
if ( V_82 <= 32 && ! V_80 [ 1 ] && V_81 == 6 )
V_80 [ 1 ] = F_83 ( NULL , 96 , V_32 ) ;
if ( V_82 <= 64 && ! V_80 [ 2 ] && V_81 == 7 )
V_80 [ 2 ] = F_83 ( NULL , 192 , V_32 ) ;
}
V_69 = V_70 ;
for ( V_81 = 0 ; V_81 <= V_85 ; V_81 ++ ) {
struct V_3 * V_4 = V_80 [ V_81 ] ;
char * V_86 ;
if ( V_4 ) {
V_86 = F_71 ( V_72 , L_10 , F_93 ( V_81 ) ) ;
F_77 ( ! V_86 ) ;
V_4 -> V_6 = V_86 ;
}
}
#ifdef F_89
for ( V_81 = 0 ; V_81 <= V_85 ; V_81 ++ ) {
struct V_3 * V_4 = V_80 [ V_81 ] ;
if ( V_4 ) {
int V_7 = F_93 ( V_81 ) ;
char * V_86 = F_71 ( V_72 ,
L_11 , V_7 ) ;
F_77 ( ! V_86 ) ;
V_79 [ V_81 ] = F_83 ( V_86 ,
V_7 , V_87 | V_32 ) ;
}
}
#endif
}
void * F_94 ( T_2 V_7 , T_3 V_32 , unsigned int V_88 )
{
void * V_31 ;
struct V_89 * V_89 ;
V_32 |= V_90 ;
V_89 = F_95 ( V_32 , V_88 ) ;
V_31 = V_89 ? F_96 ( V_89 ) : NULL ;
F_97 ( V_31 , V_7 , 1 , V_32 ) ;
F_98 ( V_31 , V_7 ) ;
return V_31 ;
}
void * F_99 ( T_2 V_7 , T_3 V_32 , unsigned int V_88 )
{
void * V_31 = F_94 ( V_7 , V_32 , V_88 ) ;
F_100 ( V_91 , V_31 , V_7 , V_92 << V_88 , V_32 ) ;
return V_31 ;
}
static void F_101 ( struct V_93 * V_94 )
{
#ifdef F_102
F_103 ( V_94 , L_12 ) ;
#else
F_103 ( V_94 , L_13 ) ;
#endif
F_103 ( V_94 , L_14
L_15 ) ;
F_103 ( V_94 , L_16 ) ;
F_103 ( V_94 , L_17 ) ;
#ifdef F_102
F_103 ( V_94 , L_18
L_19 ) ;
F_103 ( V_94 , L_20 ) ;
#endif
F_104 ( V_94 , '\n' ) ;
}
void * F_105 ( struct V_93 * V_94 , T_4 * V_95 )
{
F_23 ( & V_27 ) ;
return F_106 ( & V_45 , * V_95 ) ;
}
void * F_107 ( struct V_93 * V_94 , void * V_96 , T_4 * V_95 )
{
return F_108 ( V_96 , & V_45 , V_95 ) ;
}
void F_109 ( struct V_93 * V_94 , void * V_96 )
{
F_24 ( & V_27 ) ;
}
static void
F_110 ( struct V_3 * V_4 , struct V_97 * V_98 )
{
struct V_3 * V_65 ;
struct V_97 V_99 ;
if ( ! V_13 ( V_4 ) )
return;
F_111 (c, s) {
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
F_112 ( V_65 , & V_99 ) ;
V_98 -> V_100 += V_99 . V_100 ;
V_98 -> V_101 += V_99 . V_101 ;
V_98 -> V_102 += V_99 . V_102 ;
V_98 -> V_103 += V_99 . V_103 ;
V_98 -> V_104 += V_99 . V_104 ;
}
}
static void F_113 ( struct V_3 * V_4 , struct V_93 * V_94 )
{
struct V_97 V_99 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
F_112 ( V_4 , & V_99 ) ;
F_110 ( V_4 , & V_99 ) ;
F_114 ( V_94 , L_21 ,
V_46 ( V_4 ) , V_99 . V_103 , V_99 . V_104 , V_4 -> V_7 ,
V_99 . V_105 , ( 1 << V_99 . V_106 ) ) ;
F_114 ( V_94 , L_22 ,
V_99 . V_107 , V_99 . V_108 , V_99 . V_109 ) ;
F_114 ( V_94 , L_23 ,
V_99 . V_100 , V_99 . V_101 , V_99 . V_102 ) ;
F_115 ( V_94 , V_4 ) ;
F_104 ( V_94 , '\n' ) ;
}
static int F_116 ( struct V_93 * V_94 , void * V_96 )
{
struct V_3 * V_4 = F_117 ( V_96 , struct V_3 , V_14 ) ;
if ( V_96 == V_45 . V_110 )
F_101 ( V_94 ) ;
if ( V_13 ( V_4 ) )
F_113 ( V_4 , V_94 ) ;
return 0 ;
}
int F_118 ( struct V_93 * V_94 , void * V_96 )
{
struct V_3 * V_4 = F_117 ( V_96 , struct V_3 , V_14 ) ;
struct V_16 * V_17 = F_119 ( F_120 ( V_94 ) ) ;
if ( V_96 == V_45 . V_110 )
F_101 ( V_94 ) ;
if ( ! V_13 ( V_4 ) && V_4 -> V_12 . V_17 == V_17 )
F_113 ( V_4 , V_94 ) ;
return 0 ;
}
static int F_121 ( struct V_111 * V_111 , struct V_112 * V_112 )
{
return F_122 ( V_112 , & V_113 ) ;
}
static int T_1 F_123 ( void )
{
F_124 ( L_24 , V_114 , NULL ,
& V_115 ) ;
return 0 ;
}
static T_5 void * F_125 ( const void * V_96 , T_2 V_116 ,
T_3 V_32 )
{
void * V_31 ;
T_2 V_117 = 0 ;
if ( V_96 )
V_117 = F_126 ( V_96 ) ;
if ( V_117 >= V_116 ) {
F_127 ( ( void * ) V_96 , V_116 ) ;
return ( void * ) V_96 ;
}
V_31 = F_128 ( V_116 , V_32 ) ;
if ( V_31 && V_96 )
memcpy ( V_31 , V_96 , V_117 ) ;
return V_31 ;
}
void * F_129 ( const void * V_96 , T_2 V_116 , T_3 V_32 )
{
if ( F_86 ( ! V_116 ) )
return V_76 ;
return F_125 ( V_96 , V_116 , V_32 ) ;
}
void * F_130 ( const void * V_96 , T_2 V_116 , T_3 V_32 )
{
void * V_31 ;
if ( F_86 ( ! V_116 ) ) {
F_15 ( V_96 ) ;
return V_76 ;
}
V_31 = F_125 ( V_96 , V_116 , V_32 ) ;
if ( V_31 && V_96 != V_31 )
F_15 ( V_96 ) ;
return V_31 ;
}
void F_131 ( const void * V_96 )
{
T_2 V_117 ;
void * V_118 = ( void * ) V_96 ;
if ( F_86 ( F_132 ( V_118 ) ) )
return;
V_117 = F_126 ( V_118 ) ;
memset ( V_118 , 0 , V_117 ) ;
F_15 ( V_118 ) ;
}
