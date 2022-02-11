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
void F_9 ( struct V_3 * V_4 , T_2 V_12 , void * * V_13 )
{
T_2 V_14 ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ ) {
if ( V_4 )
F_10 ( V_4 , V_13 [ V_14 ] ) ;
else
F_11 ( V_13 [ V_14 ] ) ;
}
}
int F_12 ( struct V_3 * V_4 , T_3 V_15 , T_2 V_12 ,
void * * V_13 )
{
T_2 V_14 ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ ) {
void * V_16 = V_13 [ V_14 ] = F_13 ( V_4 , V_15 ) ;
if ( ! V_16 ) {
F_9 ( V_4 , V_14 , V_13 ) ;
return 0 ;
}
}
return V_14 ;
}
void F_14 ( struct V_3 * V_4 )
{
V_4 -> V_17 . V_18 = NULL ;
F_15 ( V_4 -> V_17 . V_19 , NULL ) ;
F_16 ( & V_4 -> V_17 . V_20 ) ;
}
static int F_17 ( struct V_3 * V_4 ,
struct V_21 * V_22 , struct V_3 * V_18 )
{
struct V_23 * V_24 ;
if ( V_18 ) {
V_4 -> V_17 . V_18 = V_18 ;
V_4 -> V_17 . V_22 = V_22 ;
F_16 ( & V_4 -> V_17 . V_25 ) ;
F_16 ( & V_4 -> V_17 . V_26 ) ;
return 0 ;
}
F_14 ( V_4 ) ;
if ( ! V_27 )
return 0 ;
V_24 = F_18 ( sizeof( struct V_23 ) +
V_27 * sizeof( void * ) ,
V_28 ) ;
if ( ! V_24 )
return - V_29 ;
F_15 ( V_4 -> V_17 . V_19 , V_24 ) ;
return 0 ;
}
static void F_19 ( struct V_3 * V_4 )
{
if ( F_20 ( V_4 ) )
F_11 ( F_21 ( V_4 -> V_17 . V_19 ) ) ;
}
static int F_22 ( struct V_3 * V_4 , int V_30 )
{
struct V_23 * V_31 , * V_32 ;
V_32 = F_18 ( sizeof( struct V_23 ) +
V_30 * sizeof( void * ) , V_28 ) ;
if ( ! V_32 )
return - V_29 ;
V_31 = F_23 ( V_4 -> V_17 . V_19 ,
F_24 ( & V_33 ) ) ;
if ( V_31 )
memcpy ( V_32 -> V_34 , V_31 -> V_34 ,
V_27 * sizeof( void * ) ) ;
F_25 ( V_4 -> V_17 . V_19 , V_32 ) ;
if ( V_31 )
F_26 ( V_31 , V_35 ) ;
return 0 ;
}
int F_27 ( int V_36 )
{
struct V_3 * V_4 ;
int V_37 = 0 ;
F_28 ( & V_33 ) ;
F_6 (s, &slab_root_caches, root_caches_node) {
V_37 = F_22 ( V_4 , V_36 ) ;
if ( V_37 )
break;
}
F_29 ( & V_33 ) ;
return V_37 ;
}
void F_30 ( struct V_3 * V_4 )
{
if ( F_20 ( V_4 ) ) {
F_31 ( & V_4 -> V_38 , & V_39 ) ;
} else {
F_31 ( & V_4 -> V_17 . V_25 ,
& V_4 -> V_17 . V_18 -> V_17 . V_20 ) ;
F_31 ( & V_4 -> V_17 . V_26 ,
& V_4 -> V_17 . V_22 -> V_40 ) ;
}
}
static void F_32 ( struct V_3 * V_4 )
{
if ( F_20 ( V_4 ) ) {
F_33 ( & V_4 -> V_38 ) ;
} else {
F_33 ( & V_4 -> V_17 . V_25 ) ;
F_33 ( & V_4 -> V_17 . V_26 ) ;
}
}
static inline int F_17 ( struct V_3 * V_4 ,
struct V_21 * V_22 , struct V_3 * V_18 )
{
return 0 ;
}
static inline void F_19 ( struct V_3 * V_4 )
{
}
static inline void F_32 ( struct V_3 * V_4 )
{
}
int F_34 ( struct V_3 * V_4 )
{
if ( V_2 || ( V_4 -> V_15 & V_41 ) )
return 1 ;
if ( ! F_20 ( V_4 ) )
return 1 ;
if ( V_4 -> V_42 )
return 1 ;
if ( V_4 -> V_43 < 0 )
return 1 ;
return 0 ;
}
struct V_3 * F_35 ( T_2 V_7 , T_2 V_44 ,
unsigned long V_15 , const char * V_6 , void (* V_42)( void * ) )
{
struct V_3 * V_4 ;
if ( V_2 )
return NULL ;
if ( V_42 )
return NULL ;
V_7 = F_36 ( V_7 , sizeof( void * ) ) ;
V_44 = F_37 ( V_15 , V_44 , V_7 ) ;
V_7 = F_36 ( V_7 , V_44 ) ;
V_15 = F_38 ( V_7 , V_15 , V_6 , NULL ) ;
if ( V_15 & V_41 )
return NULL ;
F_39 (s, &slab_root_caches, root_caches_node) {
if ( F_34 ( V_4 ) )
continue;
if ( V_7 > V_4 -> V_7 )
continue;
if ( ( V_15 & V_45 ) != ( V_4 -> V_15 & V_45 ) )
continue;
if ( ( V_4 -> V_7 & ~ ( V_44 - 1 ) ) != V_4 -> V_7 )
continue;
if ( V_4 -> V_7 - V_7 >= sizeof( void * ) )
continue;
if ( F_40 ( V_46 ) && V_44 &&
( V_44 > V_4 -> V_44 || V_4 -> V_44 % V_44 ) )
continue;
return V_4 ;
}
return NULL ;
}
unsigned long F_37 ( unsigned long V_15 ,
unsigned long V_44 , unsigned long V_7 )
{
if ( V_15 & V_47 ) {
unsigned long V_48 = F_41 () ;
while ( V_7 <= V_48 / 2 )
V_48 /= 2 ;
V_44 = F_42 ( V_44 , V_48 ) ;
}
if ( V_44 < V_49 )
V_44 = V_49 ;
return F_36 ( V_44 , sizeof( void * ) ) ;
}
static struct V_3 * F_43 ( const char * V_6 ,
T_2 V_5 , T_2 V_7 , T_2 V_44 ,
unsigned long V_15 , void (* V_42)( void * ) ,
struct V_21 * V_22 , struct V_3 * V_18 )
{
struct V_3 * V_4 ;
int V_50 ;
V_50 = - V_29 ;
V_4 = F_44 ( V_3 , V_28 ) ;
if ( ! V_4 )
goto V_51;
V_4 -> V_6 = V_6 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_44 = V_44 ;
V_4 -> V_42 = V_42 ;
V_50 = F_17 ( V_4 , V_22 , V_18 ) ;
if ( V_50 )
goto V_52;
V_50 = F_45 ( V_4 , V_15 ) ;
if ( V_50 )
goto V_52;
V_4 -> V_43 = 1 ;
F_31 ( & V_4 -> V_53 , & V_54 ) ;
F_30 ( V_4 ) ;
V_51:
if ( V_50 )
return F_46 ( V_50 ) ;
return V_4 ;
V_52:
F_19 ( V_4 ) ;
F_10 ( V_3 , V_4 ) ;
goto V_51;
}
struct V_3 *
F_47 ( const char * V_6 , T_2 V_7 , T_2 V_44 ,
unsigned long V_15 , void (* V_42)( void * ) )
{
struct V_3 * V_4 = NULL ;
const char * V_55 ;
int V_50 ;
F_48 () ;
F_49 () ;
F_50 () ;
F_28 ( & V_33 ) ;
V_50 = F_3 ( V_6 , V_7 ) ;
if ( V_50 ) {
goto V_56;
}
if ( V_15 & ~ V_57 ) {
V_50 = - V_9 ;
goto V_56;
}
V_15 &= V_58 ;
V_4 = F_51 ( V_6 , V_7 , V_44 , V_15 , V_42 ) ;
if ( V_4 )
goto V_56;
V_55 = F_52 ( V_6 , V_28 ) ;
if ( ! V_55 ) {
V_50 = - V_29 ;
goto V_56;
}
V_4 = F_43 ( V_55 , V_7 , V_7 ,
F_37 ( V_15 , V_44 , V_7 ) ,
V_15 , V_42 , NULL , NULL ) ;
if ( F_53 ( V_4 ) ) {
V_50 = F_54 ( V_4 ) ;
F_55 ( V_55 ) ;
}
V_56:
F_29 ( & V_33 ) ;
F_56 () ;
F_57 () ;
F_58 () ;
if ( V_50 ) {
if ( V_15 & V_59 )
F_59 ( L_3 ,
V_6 , V_50 ) ;
else {
F_60 ( L_4 ,
V_6 , V_50 ) ;
F_61 () ;
}
return NULL ;
}
return V_4 ;
}
static void F_62 ( struct V_60 * V_61 )
{
F_63 ( V_62 ) ;
struct V_3 * V_4 , * V_63 ;
F_28 ( & V_33 ) ;
F_64 ( & V_64 , & V_62 ) ;
F_29 ( & V_33 ) ;
if ( F_65 ( & V_62 ) )
return;
F_66 () ;
F_67 (s, s2, &to_destroy, list) {
#ifdef F_68
F_69 ( V_4 ) ;
#else
F_70 ( V_4 ) ;
#endif
}
}
static int F_71 ( struct V_3 * V_4 )
{
F_72 ( V_4 ) ;
if ( F_73 ( V_4 ) != 0 )
return - V_65 ;
F_32 ( V_4 ) ;
F_33 ( & V_4 -> V_53 ) ;
if ( V_4 -> V_15 & V_66 ) {
F_74 ( & V_4 -> V_53 , & V_64 ) ;
F_75 ( & V_67 ) ;
} else {
#ifdef F_68
F_69 ( V_4 ) ;
#else
F_70 ( V_4 ) ;
#endif
}
return 0 ;
}
void F_76 ( struct V_21 * V_22 ,
struct V_3 * V_18 )
{
static char V_68 [ V_69 + 1 ] ;
struct V_70 * V_71 = & V_22 -> V_71 ;
struct V_23 * V_24 ;
struct V_3 * V_4 = NULL ;
char * V_55 ;
int V_72 ;
F_48 () ;
F_49 () ;
F_28 ( & V_33 ) ;
if ( V_22 -> V_73 != V_74 )
goto V_56;
V_72 = F_77 ( V_22 ) ;
V_24 = F_23 ( V_18 -> V_17 . V_19 ,
F_24 ( & V_33 ) ) ;
if ( V_24 -> V_34 [ V_72 ] )
goto V_56;
F_78 ( V_71 -> V_75 , V_68 , sizeof( V_68 ) ) ;
V_55 = F_79 ( V_28 , L_5 , V_18 -> V_6 ,
V_71 -> V_76 , V_68 ) ;
if ( ! V_55 )
goto V_56;
V_4 = F_43 ( V_55 , V_18 -> V_5 ,
V_18 -> V_7 , V_18 -> V_44 ,
V_18 -> V_15 & V_58 ,
V_18 -> V_42 , V_22 , V_18 ) ;
if ( F_53 ( V_4 ) ) {
F_11 ( V_55 ) ;
goto V_56;
}
F_80 () ;
V_24 -> V_34 [ V_72 ] = V_4 ;
V_56:
F_29 ( & V_33 ) ;
F_57 () ;
F_58 () ;
}
static void F_81 ( struct V_60 * V_61 )
{
struct V_3 * V_4 = F_82 ( V_61 , struct V_3 ,
V_17 . V_77 ) ;
F_48 () ;
F_49 () ;
F_28 ( & V_33 ) ;
V_4 -> V_17 . V_78 ( V_4 ) ;
F_29 ( & V_33 ) ;
F_57 () ;
F_58 () ;
F_83 ( & V_4 -> V_17 . V_22 -> V_71 ) ;
}
static void F_84 ( struct V_79 * V_80 )
{
struct V_3 * V_4 = F_82 ( V_80 , struct V_3 ,
V_17 . V_81 ) ;
F_85 ( & V_4 -> V_17 . V_77 , F_81 ) ;
F_86 ( V_82 , & V_4 -> V_17 . V_77 ) ;
}
void F_87 ( struct V_3 * V_4 ,
void (* V_78)( struct V_3 * ) )
{
if ( F_88 ( F_20 ( V_4 ) ) ||
F_88 ( V_4 -> V_17 . V_78 ) )
return;
F_89 ( & V_4 -> V_17 . V_22 -> V_71 ) ;
V_4 -> V_17 . V_78 = V_78 ;
F_90 ( & V_4 -> V_17 . V_81 , F_84 ) ;
}
void F_91 ( struct V_21 * V_22 )
{
int V_72 ;
struct V_23 * V_24 ;
struct V_3 * V_4 , * V_83 ;
V_72 = F_77 ( V_22 ) ;
F_48 () ;
F_49 () ;
F_28 ( & V_33 ) ;
F_6 (s, &slab_root_caches, root_caches_node) {
V_24 = F_23 ( V_4 -> V_17 . V_19 ,
F_24 ( & V_33 ) ) ;
V_83 = V_24 -> V_34 [ V_72 ] ;
if ( ! V_83 )
continue;
F_92 ( V_83 ) ;
V_24 -> V_34 [ V_72 ] = NULL ;
}
F_29 ( & V_33 ) ;
F_57 () ;
F_58 () ;
}
void F_93 ( struct V_21 * V_22 )
{
struct V_3 * V_4 , * V_63 ;
F_48 () ;
F_49 () ;
F_28 ( & V_33 ) ;
F_67 (s, s2, &memcg->kmem_caches,
memcg_params.kmem_caches_node) {
F_94 ( F_71 ( V_4 ) ) ;
}
F_29 ( & V_33 ) ;
F_57 () ;
F_58 () ;
}
static int F_95 ( struct V_3 * V_4 )
{
struct V_23 * V_24 ;
struct V_3 * V_83 , * V_84 ;
F_63 ( V_85 ) ;
int V_14 ;
F_94 ( ! F_20 ( V_4 ) ) ;
V_24 = F_23 ( V_4 -> V_17 . V_19 ,
F_24 ( & V_33 ) ) ;
F_96 (i) {
V_83 = V_24 -> V_34 [ V_14 ] ;
if ( ! V_83 )
continue;
if ( F_71 ( V_83 ) )
F_97 ( & V_83 -> V_17 . V_25 , & V_85 ) ;
else
V_24 -> V_34 [ V_14 ] = NULL ;
}
F_67 (c, c2, &s->memcg_params.children,
memcg_params.children_node)
F_71 ( V_83 ) ;
F_98 ( & V_85 , & V_4 -> V_17 . V_20 ) ;
if ( ! F_65 ( & V_4 -> V_17 . V_20 ) )
return - V_65 ;
return 0 ;
}
static inline int F_95 ( struct V_3 * V_4 )
{
return 0 ;
}
void F_70 ( struct V_3 * V_4 )
{
F_99 ( V_4 ) ;
F_19 ( V_4 ) ;
F_55 ( V_4 -> V_6 ) ;
F_10 ( V_3 , V_4 ) ;
}
void F_100 ( struct V_3 * V_4 )
{
int V_50 ;
if ( F_101 ( ! V_4 ) )
return;
F_48 () ;
F_49 () ;
F_28 ( & V_33 ) ;
V_4 -> V_43 -- ;
if ( V_4 -> V_43 )
goto V_56;
V_50 = F_95 ( V_4 ) ;
if ( ! V_50 )
V_50 = F_71 ( V_4 ) ;
if ( V_50 ) {
F_5 ( L_6 ,
V_4 -> V_6 ) ;
F_61 () ;
}
V_56:
F_29 ( & V_33 ) ;
F_57 () ;
F_58 () ;
}
int F_102 ( struct V_3 * V_86 )
{
int V_37 ;
F_48 () ;
F_49 () ;
F_103 ( V_86 ) ;
V_37 = F_104 ( V_86 ) ;
F_57 () ;
F_58 () ;
return V_37 ;
}
bool F_105 ( void )
{
return V_87 >= V_88 ;
}
void T_1 F_106 ( struct V_3 * V_4 , const char * V_6 , T_2 V_7 ,
unsigned long V_15 )
{
int V_50 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_7 = V_4 -> V_5 = V_7 ;
V_4 -> V_44 = F_37 ( V_15 , V_89 , V_7 ) ;
F_14 ( V_4 ) ;
V_50 = F_45 ( V_4 , V_15 ) ;
if ( V_50 )
F_59 ( L_7 ,
V_6 , V_7 , V_50 ) ;
V_4 -> V_43 = - 1 ;
}
struct V_3 * T_1 F_107 ( const char * V_6 , T_2 V_7 ,
unsigned long V_15 )
{
struct V_3 * V_4 = F_44 ( V_3 , V_90 ) ;
if ( ! V_4 )
F_59 ( L_8 , V_6 ) ;
F_106 ( V_4 , V_6 , V_7 , V_15 ) ;
F_31 ( & V_4 -> V_53 , & V_54 ) ;
F_30 ( V_4 ) ;
V_4 -> V_43 = 1 ;
return V_4 ;
}
static inline int F_108 ( T_2 V_91 )
{
return ( V_91 - 1 ) / 8 ;
}
struct V_3 * F_109 ( T_2 V_7 , T_3 V_15 )
{
int V_92 ;
if ( F_101 ( V_7 > V_8 ) ) {
F_88 ( ! ( V_15 & V_93 ) ) ;
return NULL ;
}
if ( V_7 <= 192 ) {
if ( ! V_7 )
return V_94 ;
V_92 = V_95 [ F_108 ( V_7 ) ] ;
} else
V_92 = F_110 ( V_7 - 1 ) ;
#ifdef F_111
if ( F_101 ( ( V_15 & V_96 ) ) )
return V_97 [ V_92 ] ;
#endif
return V_98 [ V_92 ] ;
}
void T_1 F_112 ( void )
{
int V_14 ;
F_113 ( V_99 > 256 ||
( V_99 & ( V_99 - 1 ) ) ) ;
for ( V_14 = 8 ; V_14 < V_99 ; V_14 += 8 ) {
int V_100 = F_108 ( V_14 ) ;
if ( V_100 >= F_114 ( V_95 ) )
break;
V_95 [ V_100 ] = V_101 ;
}
if ( V_99 >= 64 ) {
for ( V_14 = 64 + 8 ; V_14 <= 96 ; V_14 += 8 )
V_95 [ F_108 ( V_14 ) ] = 7 ;
}
if ( V_99 >= 128 ) {
for ( V_14 = 128 + 8 ; V_14 <= 192 ; V_14 += 8 )
V_95 [ F_108 ( V_14 ) ] = 8 ;
}
}
static void T_1 F_115 ( int V_72 , unsigned long V_15 )
{
V_98 [ V_72 ] = F_107 ( V_102 [ V_72 ] . V_6 ,
V_102 [ V_72 ] . V_7 , V_15 ) ;
}
void T_1 F_116 ( unsigned long V_15 )
{
int V_14 ;
for ( V_14 = V_101 ; V_14 <= V_103 ; V_14 ++ ) {
if ( ! V_98 [ V_14 ] )
F_115 ( V_14 , V_15 ) ;
if ( V_99 <= 32 && ! V_98 [ 1 ] && V_14 == 6 )
F_115 ( 1 , V_15 ) ;
if ( V_99 <= 64 && ! V_98 [ 2 ] && V_14 == 7 )
F_115 ( 2 , V_15 ) ;
}
V_87 = V_88 ;
#ifdef F_111
for ( V_14 = 0 ; V_14 <= V_103 ; V_14 ++ ) {
struct V_3 * V_4 = V_98 [ V_14 ] ;
if ( V_4 ) {
int V_7 = F_117 ( V_14 ) ;
char * V_104 = F_79 ( V_90 ,
L_9 , V_7 ) ;
F_94 ( ! V_104 ) ;
V_97 [ V_14 ] = F_107 ( V_104 ,
V_7 , V_105 | V_15 ) ;
}
}
#endif
}
void * F_118 ( T_2 V_7 , T_3 V_15 , unsigned int V_106 )
{
void * V_37 ;
struct V_107 * V_107 ;
V_15 |= V_108 ;
V_107 = F_119 ( V_15 , V_106 ) ;
V_37 = V_107 ? F_120 ( V_107 ) : NULL ;
F_121 ( V_37 , V_7 , 1 , V_15 ) ;
F_122 ( V_37 , V_7 , V_15 ) ;
return V_37 ;
}
void * F_123 ( T_2 V_7 , T_3 V_15 , unsigned int V_106 )
{
void * V_37 = F_118 ( V_7 , V_15 , V_106 ) ;
F_124 ( V_109 , V_37 , V_7 , V_110 << V_106 , V_15 ) ;
return V_37 ;
}
static void F_125 ( struct V_111 * V_112 , unsigned int * V_53 ,
T_2 V_113 )
{
T_2 V_14 ;
unsigned int rand ;
for ( V_14 = 0 ; V_14 < V_113 ; V_14 ++ )
V_53 [ V_14 ] = V_14 ;
for ( V_14 = V_113 - 1 ; V_14 > 0 ; V_14 -- ) {
rand = F_126 ( V_112 ) ;
rand %= ( V_14 + 1 ) ;
F_127 ( V_53 [ V_14 ] , V_53 [ rand ] ) ;
}
}
int F_128 ( struct V_3 * V_86 , unsigned int V_113 ,
T_3 V_114 )
{
struct V_111 V_112 ;
if ( V_113 < 2 || V_86 -> V_115 )
return 0 ;
V_86 -> V_115 = F_129 ( V_113 , sizeof( unsigned int ) , V_114 ) ;
if ( ! V_86 -> V_115 )
return - V_29 ;
F_130 ( & V_112 , F_131 () ) ;
F_125 ( & V_112 , V_86 -> V_115 , V_113 ) ;
return 0 ;
}
void F_132 ( struct V_3 * V_86 )
{
F_11 ( V_86 -> V_115 ) ;
V_86 -> V_115 = NULL ;
}
static void F_133 ( struct V_116 * V_117 )
{
#ifdef F_134
F_135 ( V_117 , L_10 ) ;
#else
F_135 ( V_117 , L_11 ) ;
#endif
F_135 ( V_117 , L_12 ) ;
F_135 ( V_117 , L_13 ) ;
F_135 ( V_117 , L_14 ) ;
#ifdef F_134
F_135 ( V_117 , L_15 ) ;
F_135 ( V_117 , L_16 ) ;
#endif
F_136 ( V_117 , '\n' ) ;
}
void * F_137 ( struct V_116 * V_117 , T_4 * V_118 )
{
F_28 ( & V_33 ) ;
return F_138 ( & V_39 , * V_118 ) ;
}
void * F_139 ( struct V_116 * V_117 , void * V_13 , T_4 * V_118 )
{
return F_140 ( V_13 , & V_39 , V_118 ) ;
}
void F_141 ( struct V_116 * V_117 , void * V_13 )
{
F_29 ( & V_33 ) ;
}
static void
F_142 ( struct V_3 * V_4 , struct V_119 * V_120 )
{
struct V_3 * V_83 ;
struct V_119 V_121 ;
if ( ! F_20 ( V_4 ) )
return;
F_143 (c, s) {
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
F_144 ( V_83 , & V_121 ) ;
V_120 -> V_122 += V_121 . V_122 ;
V_120 -> V_123 += V_121 . V_123 ;
V_120 -> V_124 += V_121 . V_124 ;
V_120 -> V_125 += V_121 . V_125 ;
V_120 -> V_126 += V_121 . V_126 ;
}
}
static void F_145 ( struct V_3 * V_4 , struct V_116 * V_117 )
{
struct V_119 V_121 ;
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
F_144 ( V_4 , & V_121 ) ;
F_142 ( V_4 , & V_121 ) ;
F_146 ( V_117 , L_17 ,
V_55 ( V_4 ) , V_121 . V_125 , V_121 . V_126 , V_4 -> V_7 ,
V_121 . V_127 , ( 1 << V_121 . V_128 ) ) ;
F_146 ( V_117 , L_18 ,
V_121 . V_129 , V_121 . V_130 , V_121 . V_131 ) ;
F_146 ( V_117 , L_19 ,
V_121 . V_122 , V_121 . V_123 , V_121 . V_124 ) ;
F_147 ( V_117 , V_4 ) ;
F_136 ( V_117 , '\n' ) ;
}
static int F_148 ( struct V_116 * V_117 , void * V_13 )
{
struct V_3 * V_4 = F_149 ( V_13 , struct V_3 , V_38 ) ;
if ( V_13 == V_39 . V_132 )
F_133 ( V_117 ) ;
F_145 ( V_4 , V_117 ) ;
return 0 ;
}
void * F_150 ( struct V_116 * V_117 , T_4 * V_118 )
{
struct V_21 * V_22 = F_151 ( F_152 ( V_117 ) ) ;
F_28 ( & V_33 ) ;
return F_138 ( & V_22 -> V_40 , * V_118 ) ;
}
void * F_153 ( struct V_116 * V_117 , void * V_13 , T_4 * V_118 )
{
struct V_21 * V_22 = F_151 ( F_152 ( V_117 ) ) ;
return F_140 ( V_13 , & V_22 -> V_40 , V_118 ) ;
}
void F_154 ( struct V_116 * V_117 , void * V_13 )
{
F_29 ( & V_33 ) ;
}
int F_155 ( struct V_116 * V_117 , void * V_13 )
{
struct V_3 * V_4 = F_149 ( V_13 , struct V_3 ,
V_17 . V_26 ) ;
struct V_21 * V_22 = F_151 ( F_152 ( V_117 ) ) ;
if ( V_13 == V_22 -> V_40 . V_132 )
F_133 ( V_117 ) ;
F_145 ( V_4 , V_117 ) ;
return 0 ;
}
static int F_156 ( struct V_133 * V_133 , struct V_134 * V_134 )
{
return F_157 ( V_134 , & V_135 ) ;
}
static int T_1 F_158 ( void )
{
F_159 ( L_20 , V_136 , NULL ,
& V_137 ) ;
return 0 ;
}
static T_5 void * F_160 ( const void * V_13 , T_2 V_138 ,
T_3 V_15 )
{
void * V_37 ;
T_2 V_139 = 0 ;
if ( V_13 )
V_139 = F_161 ( V_13 ) ;
if ( V_139 >= V_138 ) {
F_162 ( ( void * ) V_13 , V_138 , V_15 ) ;
return ( void * ) V_13 ;
}
V_37 = F_163 ( V_138 , V_15 ) ;
if ( V_37 && V_13 )
memcpy ( V_37 , V_13 , V_139 ) ;
return V_37 ;
}
void * F_164 ( const void * V_13 , T_2 V_138 , T_3 V_15 )
{
if ( F_101 ( ! V_138 ) )
return V_94 ;
return F_160 ( V_13 , V_138 , V_15 ) ;
}
void * F_165 ( const void * V_13 , T_2 V_138 , T_3 V_15 )
{
void * V_37 ;
if ( F_101 ( ! V_138 ) ) {
F_11 ( V_13 ) ;
return V_94 ;
}
V_37 = F_160 ( V_13 , V_138 , V_15 ) ;
if ( V_37 && V_13 != V_37 )
F_11 ( V_13 ) ;
return V_37 ;
}
void F_166 ( const void * V_13 )
{
T_2 V_139 ;
void * V_140 = ( void * ) V_13 ;
if ( F_101 ( F_167 ( V_140 ) ) )
return;
V_139 = F_161 ( V_140 ) ;
memset ( V_140 , 0 , V_139 ) ;
F_11 ( V_140 ) ;
}
