static int T_1 F_1 ( char * V_1 )
{
V_2 = true ;
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
F_21 ( F_22 ( V_4 -> V_17 . V_19 ) ) ;
}
static void F_23 ( struct V_30 * V_31 )
{
struct V_23 * V_32 ;
V_32 = F_24 ( V_31 , struct V_23 , V_31 ) ;
F_21 ( V_32 ) ;
}
static int F_25 ( struct V_3 * V_4 , int V_33 )
{
struct V_23 * V_32 , * V_34 ;
V_34 = F_18 ( sizeof( struct V_23 ) +
V_33 * sizeof( void * ) , V_28 ) ;
if ( ! V_34 )
return - V_29 ;
V_32 = F_26 ( V_4 -> V_17 . V_19 ,
F_27 ( & V_35 ) ) ;
if ( V_32 )
memcpy ( V_34 -> V_36 , V_32 -> V_36 ,
V_27 * sizeof( void * ) ) ;
F_28 ( V_4 -> V_17 . V_19 , V_34 ) ;
if ( V_32 )
F_29 ( & V_32 -> V_31 , F_23 ) ;
return 0 ;
}
int F_30 ( int V_37 )
{
struct V_3 * V_4 ;
int V_38 = 0 ;
F_31 ( & V_35 ) ;
F_6 (s, &slab_root_caches, root_caches_node) {
V_38 = F_25 ( V_4 , V_37 ) ;
if ( V_38 )
break;
}
F_32 ( & V_35 ) ;
return V_38 ;
}
void F_33 ( struct V_3 * V_4 )
{
if ( F_20 ( V_4 ) ) {
F_34 ( & V_4 -> V_39 , & V_40 ) ;
} else {
F_34 ( & V_4 -> V_17 . V_25 ,
& V_4 -> V_17 . V_18 -> V_17 . V_20 ) ;
F_34 ( & V_4 -> V_17 . V_26 ,
& V_4 -> V_17 . V_22 -> V_41 ) ;
}
}
static void F_35 ( struct V_3 * V_4 )
{
if ( F_20 ( V_4 ) ) {
F_36 ( & V_4 -> V_39 ) ;
} else {
F_36 ( & V_4 -> V_17 . V_25 ) ;
F_36 ( & V_4 -> V_17 . V_26 ) ;
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
static inline void F_35 ( struct V_3 * V_4 )
{
}
int F_37 ( struct V_3 * V_4 )
{
if ( V_2 || ( V_4 -> V_15 & V_42 ) )
return 1 ;
if ( ! F_20 ( V_4 ) )
return 1 ;
if ( V_4 -> V_43 )
return 1 ;
if ( V_4 -> V_44 < 0 )
return 1 ;
return 0 ;
}
struct V_3 * F_38 ( T_2 V_7 , T_2 V_45 ,
unsigned long V_15 , const char * V_6 , void (* V_43)( void * ) )
{
struct V_3 * V_4 ;
if ( V_2 )
return NULL ;
if ( V_43 )
return NULL ;
V_7 = F_39 ( V_7 , sizeof( void * ) ) ;
V_45 = F_40 ( V_15 , V_45 , V_7 ) ;
V_7 = F_39 ( V_7 , V_45 ) ;
V_15 = F_41 ( V_7 , V_15 , V_6 , NULL ) ;
if ( V_15 & V_42 )
return NULL ;
F_42 (s, &slab_root_caches, root_caches_node) {
if ( F_37 ( V_4 ) )
continue;
if ( V_7 > V_4 -> V_7 )
continue;
if ( ( V_15 & V_46 ) != ( V_4 -> V_15 & V_46 ) )
continue;
if ( ( V_4 -> V_7 & ~ ( V_45 - 1 ) ) != V_4 -> V_7 )
continue;
if ( V_4 -> V_7 - V_7 >= sizeof( void * ) )
continue;
if ( F_43 ( V_47 ) && V_45 &&
( V_45 > V_4 -> V_45 || V_4 -> V_45 % V_45 ) )
continue;
return V_4 ;
}
return NULL ;
}
unsigned long F_40 ( unsigned long V_15 ,
unsigned long V_45 , unsigned long V_7 )
{
if ( V_15 & V_48 ) {
unsigned long V_49 = F_44 () ;
while ( V_7 <= V_49 / 2 )
V_49 /= 2 ;
V_45 = F_45 ( V_45 , V_49 ) ;
}
if ( V_45 < V_50 )
V_45 = V_50 ;
return F_39 ( V_45 , sizeof( void * ) ) ;
}
static struct V_3 * F_46 ( const char * V_6 ,
T_2 V_5 , T_2 V_7 , T_2 V_45 ,
unsigned long V_15 , void (* V_43)( void * ) ,
struct V_21 * V_22 , struct V_3 * V_18 )
{
struct V_3 * V_4 ;
int V_51 ;
V_51 = - V_29 ;
V_4 = F_47 ( V_3 , V_28 ) ;
if ( ! V_4 )
goto V_52;
V_4 -> V_6 = V_6 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_45 = V_45 ;
V_4 -> V_43 = V_43 ;
V_51 = F_17 ( V_4 , V_22 , V_18 ) ;
if ( V_51 )
goto V_53;
V_51 = F_48 ( V_4 , V_15 ) ;
if ( V_51 )
goto V_53;
V_4 -> V_44 = 1 ;
F_34 ( & V_4 -> V_54 , & V_55 ) ;
F_33 ( V_4 ) ;
V_52:
if ( V_51 )
return F_49 ( V_51 ) ;
return V_4 ;
V_53:
F_19 ( V_4 ) ;
F_10 ( V_3 , V_4 ) ;
goto V_52;
}
struct V_3 *
F_50 ( const char * V_6 , T_2 V_7 , T_2 V_45 ,
unsigned long V_15 , void (* V_43)( void * ) )
{
struct V_3 * V_4 = NULL ;
const char * V_56 ;
int V_51 ;
F_51 () ;
F_52 () ;
F_53 () ;
F_31 ( & V_35 ) ;
V_51 = F_3 ( V_6 , V_7 ) ;
if ( V_51 ) {
goto V_57;
}
if ( V_15 & ~ V_58 ) {
V_51 = - V_9 ;
goto V_57;
}
V_15 &= V_59 ;
V_4 = F_54 ( V_6 , V_7 , V_45 , V_15 , V_43 ) ;
if ( V_4 )
goto V_57;
V_56 = F_55 ( V_6 , V_28 ) ;
if ( ! V_56 ) {
V_51 = - V_29 ;
goto V_57;
}
V_4 = F_46 ( V_56 , V_7 , V_7 ,
F_40 ( V_15 , V_45 , V_7 ) ,
V_15 , V_43 , NULL , NULL ) ;
if ( F_56 ( V_4 ) ) {
V_51 = F_57 ( V_4 ) ;
F_58 ( V_56 ) ;
}
V_57:
F_32 ( & V_35 ) ;
F_59 () ;
F_60 () ;
F_61 () ;
if ( V_51 ) {
if ( V_15 & V_60 )
F_62 ( L_3 ,
V_6 , V_51 ) ;
else {
F_63 ( L_4 ,
V_6 , V_51 ) ;
F_64 () ;
}
return NULL ;
}
return V_4 ;
}
static void F_65 ( struct V_61 * V_62 )
{
F_66 ( V_63 ) ;
struct V_3 * V_4 , * V_64 ;
F_31 ( & V_35 ) ;
F_67 ( & V_65 , & V_63 ) ;
F_32 ( & V_35 ) ;
if ( F_68 ( & V_63 ) )
return;
F_69 () ;
F_70 (s, s2, &to_destroy, list) {
#ifdef F_71
F_72 ( V_4 ) ;
#else
F_73 ( V_4 ) ;
#endif
}
}
static int F_74 ( struct V_3 * V_4 )
{
F_75 ( V_4 ) ;
if ( F_76 ( V_4 ) != 0 )
return - V_66 ;
F_35 ( V_4 ) ;
F_36 ( & V_4 -> V_54 ) ;
if ( V_4 -> V_15 & V_67 ) {
F_77 ( & V_4 -> V_54 , & V_65 ) ;
F_78 ( & V_68 ) ;
} else {
#ifdef F_71
F_72 ( V_4 ) ;
#else
F_73 ( V_4 ) ;
#endif
}
return 0 ;
}
void F_79 ( struct V_21 * V_22 ,
struct V_3 * V_18 )
{
static char V_69 [ V_70 + 1 ] ;
struct V_71 * V_72 = & V_22 -> V_72 ;
struct V_23 * V_24 ;
struct V_3 * V_4 = NULL ;
char * V_56 ;
int V_73 ;
F_51 () ;
F_52 () ;
F_31 ( & V_35 ) ;
if ( V_22 -> V_74 != V_75 )
goto V_57;
V_73 = F_80 ( V_22 ) ;
V_24 = F_26 ( V_18 -> V_17 . V_19 ,
F_27 ( & V_35 ) ) ;
if ( V_24 -> V_36 [ V_73 ] )
goto V_57;
F_81 ( V_72 -> V_76 , V_69 , sizeof( V_69 ) ) ;
V_56 = F_82 ( V_28 , L_5 , V_18 -> V_6 ,
V_72 -> V_77 , V_69 ) ;
if ( ! V_56 )
goto V_57;
V_4 = F_46 ( V_56 , V_18 -> V_5 ,
V_18 -> V_7 , V_18 -> V_45 ,
V_18 -> V_15 & V_59 ,
V_18 -> V_43 , V_22 , V_18 ) ;
if ( F_56 ( V_4 ) ) {
F_11 ( V_56 ) ;
goto V_57;
}
F_83 () ;
V_24 -> V_36 [ V_73 ] = V_4 ;
V_57:
F_32 ( & V_35 ) ;
F_60 () ;
F_61 () ;
}
static void F_84 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = F_24 ( V_62 , struct V_3 ,
V_17 . V_78 ) ;
F_51 () ;
F_52 () ;
F_31 ( & V_35 ) ;
V_4 -> V_17 . V_79 ( V_4 ) ;
F_32 ( & V_35 ) ;
F_60 () ;
F_61 () ;
F_85 ( & V_4 -> V_17 . V_22 -> V_72 ) ;
}
static void F_86 ( struct V_30 * V_80 )
{
struct V_3 * V_4 = F_24 ( V_80 , struct V_3 ,
V_17 . V_81 ) ;
F_87 ( & V_4 -> V_17 . V_78 , F_84 ) ;
F_88 ( V_82 , & V_4 -> V_17 . V_78 ) ;
}
void F_89 ( struct V_3 * V_4 ,
void (* V_79)( struct V_3 * ) )
{
if ( F_90 ( F_20 ( V_4 ) ) ||
F_90 ( V_4 -> V_17 . V_79 ) )
return;
F_91 ( & V_4 -> V_17 . V_22 -> V_72 ) ;
V_4 -> V_17 . V_79 = V_79 ;
F_92 ( & V_4 -> V_17 . V_81 , F_86 ) ;
}
void F_93 ( struct V_21 * V_22 )
{
int V_73 ;
struct V_23 * V_24 ;
struct V_3 * V_4 , * V_83 ;
V_73 = F_80 ( V_22 ) ;
F_51 () ;
F_52 () ;
F_31 ( & V_35 ) ;
F_6 (s, &slab_root_caches, root_caches_node) {
V_24 = F_26 ( V_4 -> V_17 . V_19 ,
F_27 ( & V_35 ) ) ;
V_83 = V_24 -> V_36 [ V_73 ] ;
if ( ! V_83 )
continue;
F_94 ( V_83 ) ;
V_24 -> V_36 [ V_73 ] = NULL ;
}
F_32 ( & V_35 ) ;
F_60 () ;
F_61 () ;
}
void F_95 ( struct V_21 * V_22 )
{
struct V_3 * V_4 , * V_64 ;
F_51 () ;
F_52 () ;
F_31 ( & V_35 ) ;
F_70 (s, s2, &memcg->kmem_caches,
memcg_params.kmem_caches_node) {
F_96 ( F_74 ( V_4 ) ) ;
}
F_32 ( & V_35 ) ;
F_60 () ;
F_61 () ;
}
static int F_97 ( struct V_3 * V_4 )
{
struct V_23 * V_24 ;
struct V_3 * V_83 , * V_84 ;
F_66 ( V_85 ) ;
int V_14 ;
F_96 ( ! F_20 ( V_4 ) ) ;
V_24 = F_26 ( V_4 -> V_17 . V_19 ,
F_27 ( & V_35 ) ) ;
F_98 (i) {
V_83 = V_24 -> V_36 [ V_14 ] ;
if ( ! V_83 )
continue;
if ( F_74 ( V_83 ) )
F_99 ( & V_83 -> V_17 . V_25 , & V_85 ) ;
else
V_24 -> V_36 [ V_14 ] = NULL ;
}
F_70 (c, c2, &s->memcg_params.children,
memcg_params.children_node)
F_74 ( V_83 ) ;
F_100 ( & V_85 , & V_4 -> V_17 . V_20 ) ;
if ( ! F_68 ( & V_4 -> V_17 . V_20 ) )
return - V_66 ;
return 0 ;
}
static inline int F_97 ( struct V_3 * V_4 )
{
return 0 ;
}
void F_73 ( struct V_3 * V_4 )
{
F_101 ( V_4 ) ;
F_19 ( V_4 ) ;
F_58 ( V_4 -> V_6 ) ;
F_10 ( V_3 , V_4 ) ;
}
void F_102 ( struct V_3 * V_4 )
{
int V_51 ;
if ( F_103 ( ! V_4 ) )
return;
F_51 () ;
F_52 () ;
F_31 ( & V_35 ) ;
V_4 -> V_44 -- ;
if ( V_4 -> V_44 )
goto V_57;
V_51 = F_97 ( V_4 ) ;
if ( ! V_51 )
V_51 = F_74 ( V_4 ) ;
if ( V_51 ) {
F_5 ( L_6 ,
V_4 -> V_6 ) ;
F_64 () ;
}
V_57:
F_32 ( & V_35 ) ;
F_60 () ;
F_61 () ;
}
int F_104 ( struct V_3 * V_86 )
{
int V_38 ;
F_51 () ;
F_52 () ;
F_105 ( V_86 ) ;
V_38 = F_106 ( V_86 ) ;
F_60 () ;
F_61 () ;
return V_38 ;
}
bool F_107 ( void )
{
return V_87 >= V_88 ;
}
void T_1 F_108 ( struct V_3 * V_4 , const char * V_6 , T_2 V_7 ,
unsigned long V_15 )
{
int V_51 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_7 = V_4 -> V_5 = V_7 ;
V_4 -> V_45 = F_40 ( V_15 , V_89 , V_7 ) ;
F_14 ( V_4 ) ;
V_51 = F_48 ( V_4 , V_15 ) ;
if ( V_51 )
F_62 ( L_7 ,
V_6 , V_7 , V_51 ) ;
V_4 -> V_44 = - 1 ;
}
struct V_3 * T_1 F_109 ( const char * V_6 , T_2 V_7 ,
unsigned long V_15 )
{
struct V_3 * V_4 = F_47 ( V_3 , V_90 ) ;
if ( ! V_4 )
F_62 ( L_8 , V_6 ) ;
F_108 ( V_4 , V_6 , V_7 , V_15 ) ;
F_34 ( & V_4 -> V_54 , & V_55 ) ;
F_33 ( V_4 ) ;
V_4 -> V_44 = 1 ;
return V_4 ;
}
static inline int F_110 ( T_2 V_91 )
{
return ( V_91 - 1 ) / 8 ;
}
struct V_3 * F_111 ( T_2 V_7 , T_3 V_15 )
{
int V_92 ;
if ( F_103 ( V_7 > V_8 ) ) {
F_90 ( ! ( V_15 & V_93 ) ) ;
return NULL ;
}
if ( V_7 <= 192 ) {
if ( ! V_7 )
return V_94 ;
V_92 = V_95 [ F_110 ( V_7 ) ] ;
} else
V_92 = F_112 ( V_7 - 1 ) ;
#ifdef F_113
if ( F_103 ( ( V_15 & V_96 ) ) )
return V_97 [ V_92 ] ;
#endif
return V_98 [ V_92 ] ;
}
void T_1 F_114 ( void )
{
int V_14 ;
F_115 ( V_99 > 256 ||
( V_99 & ( V_99 - 1 ) ) ) ;
for ( V_14 = 8 ; V_14 < V_99 ; V_14 += 8 ) {
int V_100 = F_110 ( V_14 ) ;
if ( V_100 >= F_116 ( V_95 ) )
break;
V_95 [ V_100 ] = V_101 ;
}
if ( V_99 >= 64 ) {
for ( V_14 = 64 + 8 ; V_14 <= 96 ; V_14 += 8 )
V_95 [ F_110 ( V_14 ) ] = 7 ;
}
if ( V_99 >= 128 ) {
for ( V_14 = 128 + 8 ; V_14 <= 192 ; V_14 += 8 )
V_95 [ F_110 ( V_14 ) ] = 8 ;
}
}
static void T_1 F_117 ( int V_73 , unsigned long V_15 )
{
V_98 [ V_73 ] = F_109 ( V_102 [ V_73 ] . V_6 ,
V_102 [ V_73 ] . V_7 , V_15 ) ;
}
void T_1 F_118 ( unsigned long V_15 )
{
int V_14 ;
for ( V_14 = V_101 ; V_14 <= V_103 ; V_14 ++ ) {
if ( ! V_98 [ V_14 ] )
F_117 ( V_14 , V_15 ) ;
if ( V_99 <= 32 && ! V_98 [ 1 ] && V_14 == 6 )
F_117 ( 1 , V_15 ) ;
if ( V_99 <= 64 && ! V_98 [ 2 ] && V_14 == 7 )
F_117 ( 2 , V_15 ) ;
}
V_87 = V_88 ;
#ifdef F_113
for ( V_14 = 0 ; V_14 <= V_103 ; V_14 ++ ) {
struct V_3 * V_4 = V_98 [ V_14 ] ;
if ( V_4 ) {
int V_7 = F_119 ( V_14 ) ;
char * V_104 = F_82 ( V_90 ,
L_9 , V_7 ) ;
F_96 ( ! V_104 ) ;
V_97 [ V_14 ] = F_109 ( V_104 ,
V_7 , V_105 | V_15 ) ;
}
}
#endif
}
void * F_120 ( T_2 V_7 , T_3 V_15 , unsigned int V_106 )
{
void * V_38 ;
struct V_107 * V_107 ;
V_15 |= V_108 ;
V_107 = F_121 ( V_15 , V_106 ) ;
V_38 = V_107 ? F_122 ( V_107 ) : NULL ;
F_123 ( V_38 , V_7 , 1 , V_15 ) ;
F_124 ( V_38 , V_7 , V_15 ) ;
return V_38 ;
}
void * F_125 ( T_2 V_7 , T_3 V_15 , unsigned int V_106 )
{
void * V_38 = F_120 ( V_7 , V_15 , V_106 ) ;
F_126 ( V_109 , V_38 , V_7 , V_110 << V_106 , V_15 ) ;
return V_38 ;
}
static void F_127 ( struct V_111 * V_112 , unsigned int * V_54 ,
T_2 V_113 )
{
T_2 V_14 ;
unsigned int rand ;
for ( V_14 = 0 ; V_14 < V_113 ; V_14 ++ )
V_54 [ V_14 ] = V_14 ;
for ( V_14 = V_113 - 1 ; V_14 > 0 ; V_14 -- ) {
rand = F_128 ( V_112 ) ;
rand %= ( V_14 + 1 ) ;
F_129 ( V_54 [ V_14 ] , V_54 [ rand ] ) ;
}
}
int F_130 ( struct V_3 * V_86 , unsigned int V_113 ,
T_3 V_114 )
{
struct V_111 V_112 ;
if ( V_113 < 2 || V_86 -> V_115 )
return 0 ;
V_86 -> V_115 = F_131 ( V_113 , sizeof( unsigned int ) , V_114 ) ;
if ( ! V_86 -> V_115 )
return - V_29 ;
F_132 ( & V_112 , F_133 () ) ;
F_127 ( & V_112 , V_86 -> V_115 , V_113 ) ;
return 0 ;
}
void F_134 ( struct V_3 * V_86 )
{
F_11 ( V_86 -> V_115 ) ;
V_86 -> V_115 = NULL ;
}
static void F_135 ( struct V_116 * V_117 )
{
#ifdef F_136
F_137 ( V_117 , L_10 ) ;
#else
F_137 ( V_117 , L_11 ) ;
#endif
F_137 ( V_117 , L_12 ) ;
F_137 ( V_117 , L_13 ) ;
F_137 ( V_117 , L_14 ) ;
#ifdef F_136
F_137 ( V_117 , L_15 ) ;
F_137 ( V_117 , L_16 ) ;
#endif
F_138 ( V_117 , '\n' ) ;
}
void * F_139 ( struct V_116 * V_117 , T_4 * V_118 )
{
F_31 ( & V_35 ) ;
return F_140 ( & V_40 , * V_118 ) ;
}
void * F_141 ( struct V_116 * V_117 , void * V_13 , T_4 * V_118 )
{
return F_142 ( V_13 , & V_40 , V_118 ) ;
}
void F_143 ( struct V_116 * V_117 , void * V_13 )
{
F_32 ( & V_35 ) ;
}
static void
F_144 ( struct V_3 * V_4 , struct V_119 * V_120 )
{
struct V_3 * V_83 ;
struct V_119 V_121 ;
if ( ! F_20 ( V_4 ) )
return;
F_145 (c, s) {
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
F_146 ( V_83 , & V_121 ) ;
V_120 -> V_122 += V_121 . V_122 ;
V_120 -> V_123 += V_121 . V_123 ;
V_120 -> V_124 += V_121 . V_124 ;
V_120 -> V_125 += V_121 . V_125 ;
V_120 -> V_126 += V_121 . V_126 ;
}
}
static void F_147 ( struct V_3 * V_4 , struct V_116 * V_117 )
{
struct V_119 V_121 ;
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
F_146 ( V_4 , & V_121 ) ;
F_144 ( V_4 , & V_121 ) ;
F_148 ( V_117 , L_17 ,
V_56 ( V_4 ) , V_121 . V_125 , V_121 . V_126 , V_4 -> V_7 ,
V_121 . V_127 , ( 1 << V_121 . V_128 ) ) ;
F_148 ( V_117 , L_18 ,
V_121 . V_129 , V_121 . V_130 , V_121 . V_131 ) ;
F_148 ( V_117 , L_19 ,
V_121 . V_122 , V_121 . V_123 , V_121 . V_124 ) ;
F_149 ( V_117 , V_4 ) ;
F_138 ( V_117 , '\n' ) ;
}
static int F_150 ( struct V_116 * V_117 , void * V_13 )
{
struct V_3 * V_4 = F_151 ( V_13 , struct V_3 , V_39 ) ;
if ( V_13 == V_40 . V_132 )
F_135 ( V_117 ) ;
F_147 ( V_4 , V_117 ) ;
return 0 ;
}
void * F_152 ( struct V_116 * V_117 , T_4 * V_118 )
{
struct V_21 * V_22 = F_153 ( F_154 ( V_117 ) ) ;
F_31 ( & V_35 ) ;
return F_140 ( & V_22 -> V_41 , * V_118 ) ;
}
void * F_155 ( struct V_116 * V_117 , void * V_13 , T_4 * V_118 )
{
struct V_21 * V_22 = F_153 ( F_154 ( V_117 ) ) ;
return F_142 ( V_13 , & V_22 -> V_41 , V_118 ) ;
}
void F_156 ( struct V_116 * V_117 , void * V_13 )
{
F_32 ( & V_35 ) ;
}
int F_157 ( struct V_116 * V_117 , void * V_13 )
{
struct V_3 * V_4 = F_151 ( V_13 , struct V_3 ,
V_17 . V_26 ) ;
struct V_21 * V_22 = F_153 ( F_154 ( V_117 ) ) ;
if ( V_13 == V_22 -> V_41 . V_132 )
F_135 ( V_117 ) ;
F_147 ( V_4 , V_117 ) ;
return 0 ;
}
static int F_158 ( struct V_133 * V_133 , struct V_134 * V_134 )
{
return F_159 ( V_134 , & V_135 ) ;
}
static int T_1 F_160 ( void )
{
F_161 ( L_20 , V_136 , NULL ,
& V_137 ) ;
return 0 ;
}
static T_5 void * F_162 ( const void * V_13 , T_2 V_138 ,
T_3 V_15 )
{
void * V_38 ;
T_2 V_139 = 0 ;
if ( V_13 )
V_139 = F_163 ( V_13 ) ;
if ( V_139 >= V_138 ) {
F_164 ( ( void * ) V_13 , V_138 , V_15 ) ;
return ( void * ) V_13 ;
}
V_38 = F_165 ( V_138 , V_15 ) ;
if ( V_38 && V_13 )
memcpy ( V_38 , V_13 , V_139 ) ;
return V_38 ;
}
void * F_166 ( const void * V_13 , T_2 V_138 , T_3 V_15 )
{
if ( F_103 ( ! V_138 ) )
return V_94 ;
return F_162 ( V_13 , V_138 , V_15 ) ;
}
void * F_167 ( const void * V_13 , T_2 V_138 , T_3 V_15 )
{
void * V_38 ;
if ( F_103 ( ! V_138 ) ) {
F_11 ( V_13 ) ;
return V_94 ;
}
V_38 = F_162 ( V_13 , V_138 , V_15 ) ;
if ( V_38 && V_13 != V_38 )
F_11 ( V_13 ) ;
return V_38 ;
}
void F_168 ( const void * V_13 )
{
T_2 V_139 ;
void * V_140 = ( void * ) V_13 ;
if ( F_103 ( F_169 ( V_140 ) ) )
return;
V_139 = F_163 ( V_140 ) ;
memset ( V_140 , 0 , V_139 ) ;
F_11 ( V_140 ) ;
}
