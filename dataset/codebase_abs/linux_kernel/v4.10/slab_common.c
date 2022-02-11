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
V_4 -> V_17 . V_18 = true ;
F_15 ( & V_4 -> V_17 . V_19 ) ;
F_16 ( V_4 -> V_17 . V_20 , NULL ) ;
}
static int F_17 ( struct V_3 * V_4 ,
struct V_21 * V_22 , struct V_3 * V_23 )
{
struct V_24 * V_25 ;
if ( V_22 ) {
V_4 -> V_17 . V_18 = false ;
V_4 -> V_17 . V_22 = V_22 ;
V_4 -> V_17 . V_23 = V_23 ;
return 0 ;
}
F_14 ( V_4 ) ;
if ( ! V_26 )
return 0 ;
V_25 = F_18 ( sizeof( struct V_24 ) +
V_26 * sizeof( void * ) ,
V_27 ) ;
if ( ! V_25 )
return - V_28 ;
F_16 ( V_4 -> V_17 . V_20 , V_25 ) ;
return 0 ;
}
static void F_19 ( struct V_3 * V_4 )
{
if ( V_18 ( V_4 ) )
F_11 ( F_20 ( V_4 -> V_17 . V_20 ) ) ;
}
static int F_21 ( struct V_3 * V_4 , int V_29 )
{
struct V_24 * V_30 , * V_31 ;
if ( ! V_18 ( V_4 ) )
return 0 ;
V_31 = F_18 ( sizeof( struct V_24 ) +
V_29 * sizeof( void * ) , V_27 ) ;
if ( ! V_31 )
return - V_28 ;
V_30 = F_22 ( V_4 -> V_17 . V_20 ,
F_23 ( & V_32 ) ) ;
if ( V_30 )
memcpy ( V_31 -> V_33 , V_30 -> V_33 ,
V_26 * sizeof( void * ) ) ;
F_24 ( V_4 -> V_17 . V_20 , V_31 ) ;
if ( V_30 )
F_25 ( V_30 , V_34 ) ;
return 0 ;
}
int F_26 ( int V_35 )
{
struct V_3 * V_4 ;
int V_36 = 0 ;
F_27 ( & V_32 ) ;
F_6 (s, &slab_caches, list) {
V_36 = F_21 ( V_4 , V_35 ) ;
if ( V_36 )
break;
}
F_28 ( & V_32 ) ;
return V_36 ;
}
static inline int F_17 ( struct V_3 * V_4 ,
struct V_21 * V_22 , struct V_3 * V_23 )
{
return 0 ;
}
static inline void F_19 ( struct V_3 * V_4 )
{
}
int F_29 ( struct V_3 * V_4 )
{
if ( V_2 || ( V_4 -> V_15 & V_37 ) )
return 1 ;
if ( ! V_18 ( V_4 ) )
return 1 ;
if ( V_4 -> V_38 )
return 1 ;
if ( V_4 -> V_39 < 0 )
return 1 ;
return 0 ;
}
struct V_3 * F_30 ( T_2 V_7 , T_2 V_40 ,
unsigned long V_15 , const char * V_6 , void (* V_38)( void * ) )
{
struct V_3 * V_4 ;
if ( V_2 || ( V_15 & V_37 ) )
return NULL ;
if ( V_38 )
return NULL ;
V_7 = F_31 ( V_7 , sizeof( void * ) ) ;
V_40 = F_32 ( V_15 , V_40 , V_7 ) ;
V_7 = F_31 ( V_7 , V_40 ) ;
V_15 = F_33 ( V_7 , V_15 , V_6 , NULL ) ;
F_34 (s, &slab_caches, list) {
if ( F_29 ( V_4 ) )
continue;
if ( V_7 > V_4 -> V_7 )
continue;
if ( ( V_15 & V_41 ) != ( V_4 -> V_15 & V_41 ) )
continue;
if ( ( V_4 -> V_7 & ~ ( V_40 - 1 ) ) != V_4 -> V_7 )
continue;
if ( V_4 -> V_7 - V_7 >= sizeof( void * ) )
continue;
if ( F_35 ( V_42 ) && V_40 &&
( V_40 > V_4 -> V_40 || V_4 -> V_40 % V_40 ) )
continue;
return V_4 ;
}
return NULL ;
}
unsigned long F_32 ( unsigned long V_15 ,
unsigned long V_40 , unsigned long V_7 )
{
if ( V_15 & V_43 ) {
unsigned long V_44 = F_36 () ;
while ( V_7 <= V_44 / 2 )
V_44 /= 2 ;
V_40 = F_37 ( V_40 , V_44 ) ;
}
if ( V_40 < V_45 )
V_40 = V_45 ;
return F_31 ( V_40 , sizeof( void * ) ) ;
}
static struct V_3 * F_38 ( const char * V_6 ,
T_2 V_5 , T_2 V_7 , T_2 V_40 ,
unsigned long V_15 , void (* V_38)( void * ) ,
struct V_21 * V_22 , struct V_3 * V_23 )
{
struct V_3 * V_4 ;
int V_46 ;
V_46 = - V_28 ;
V_4 = F_39 ( V_3 , V_27 ) ;
if ( ! V_4 )
goto V_47;
V_4 -> V_6 = V_6 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_40 = V_40 ;
V_4 -> V_38 = V_38 ;
V_46 = F_17 ( V_4 , V_22 , V_23 ) ;
if ( V_46 )
goto V_48;
V_46 = F_40 ( V_4 , V_15 ) ;
if ( V_46 )
goto V_48;
V_4 -> V_39 = 1 ;
F_41 ( & V_4 -> V_19 , & V_49 ) ;
V_47:
if ( V_46 )
return F_42 ( V_46 ) ;
return V_4 ;
V_48:
F_19 ( V_4 ) ;
F_10 ( V_3 , V_4 ) ;
goto V_47;
}
struct V_3 *
F_43 ( const char * V_6 , T_2 V_7 , T_2 V_40 ,
unsigned long V_15 , void (* V_38)( void * ) )
{
struct V_3 * V_4 = NULL ;
const char * V_50 ;
int V_46 ;
F_44 () ;
F_45 () ;
F_46 () ;
F_27 ( & V_32 ) ;
V_46 = F_3 ( V_6 , V_7 ) ;
if ( V_46 ) {
goto V_51;
}
if ( V_15 & ~ V_52 ) {
V_46 = - V_9 ;
goto V_51;
}
V_15 &= V_53 ;
V_4 = F_47 ( V_6 , V_7 , V_40 , V_15 , V_38 ) ;
if ( V_4 )
goto V_51;
V_50 = F_48 ( V_6 , V_27 ) ;
if ( ! V_50 ) {
V_46 = - V_28 ;
goto V_51;
}
V_4 = F_38 ( V_50 , V_7 , V_7 ,
F_32 ( V_15 , V_40 , V_7 ) ,
V_15 , V_38 , NULL , NULL ) ;
if ( F_49 ( V_4 ) ) {
V_46 = F_50 ( V_4 ) ;
F_51 ( V_50 ) ;
}
V_51:
F_28 ( & V_32 ) ;
F_52 () ;
F_53 () ;
F_54 () ;
if ( V_46 ) {
if ( V_15 & V_54 )
F_55 ( L_3 ,
V_6 , V_46 ) ;
else {
F_56 ( L_4 ,
V_6 , V_46 ) ;
F_57 () ;
}
return NULL ;
}
return V_4 ;
}
static int F_58 ( struct V_3 * V_4 ,
struct V_55 * V_56 , bool * V_57 )
{
if ( F_59 ( V_4 ) != 0 )
return - V_58 ;
if ( V_4 -> V_15 & V_59 )
* V_57 = true ;
F_60 ( & V_4 -> V_19 , V_56 ) ;
return 0 ;
}
static void F_61 ( struct V_55 * V_56 , bool V_57 )
{
struct V_3 * V_4 , * V_60 ;
if ( V_57 )
F_62 () ;
F_63 (s, s2, release, list) {
#ifdef F_64
F_65 ( V_4 ) ;
#else
F_66 ( V_4 ) ;
#endif
}
}
void F_67 ( struct V_21 * V_22 ,
struct V_3 * V_23 )
{
static char V_61 [ V_62 + 1 ] ;
struct V_63 * V_64 = & V_22 -> V_64 ;
struct V_24 * V_25 ;
struct V_3 * V_4 = NULL ;
char * V_50 ;
int V_65 ;
F_44 () ;
F_45 () ;
F_27 ( & V_32 ) ;
if ( V_22 -> V_66 != V_67 )
goto V_51;
V_65 = F_68 ( V_22 ) ;
V_25 = F_22 ( V_23 -> V_17 . V_20 ,
F_23 ( & V_32 ) ) ;
if ( V_25 -> V_33 [ V_65 ] )
goto V_51;
F_69 ( V_64 -> V_68 , V_61 , sizeof( V_61 ) ) ;
V_50 = F_70 ( V_27 , L_5 , V_23 -> V_6 ,
V_64 -> V_69 , V_61 ) ;
if ( ! V_50 )
goto V_51;
V_4 = F_38 ( V_50 , V_23 -> V_5 ,
V_23 -> V_7 , V_23 -> V_40 ,
V_23 -> V_15 & V_53 ,
V_23 -> V_38 , V_22 , V_23 ) ;
if ( F_49 ( V_4 ) ) {
F_11 ( V_50 ) ;
goto V_51;
}
F_41 ( & V_4 -> V_17 . V_19 , & V_23 -> V_17 . V_19 ) ;
F_71 () ;
V_25 -> V_33 [ V_65 ] = V_4 ;
V_51:
F_28 ( & V_32 ) ;
F_53 () ;
F_54 () ;
}
void F_72 ( struct V_21 * V_22 )
{
int V_65 ;
struct V_24 * V_25 ;
struct V_3 * V_4 , * V_70 ;
V_65 = F_68 ( V_22 ) ;
F_44 () ;
F_45 () ;
#ifdef F_73
F_27 ( & V_32 ) ;
F_6 (s, &slab_caches, list) {
V_70 = V_18 ( V_4 ) ? F_74 ( V_4 , V_65 ) : NULL ;
if ( V_70 ) {
V_70 -> V_71 = 0 ;
V_70 -> V_72 = 0 ;
}
}
F_28 ( & V_32 ) ;
F_75 () ;
#endif
F_27 ( & V_32 ) ;
F_6 (s, &slab_caches, list) {
if ( ! V_18 ( V_4 ) )
continue;
V_25 = F_22 ( V_4 -> V_17 . V_20 ,
F_23 ( & V_32 ) ) ;
V_70 = V_25 -> V_33 [ V_65 ] ;
if ( ! V_70 )
continue;
F_76 ( V_70 ) ;
V_25 -> V_33 [ V_65 ] = NULL ;
}
F_28 ( & V_32 ) ;
F_53 () ;
F_54 () ;
}
static int F_77 ( struct V_3 * V_4 ,
struct V_55 * V_56 , bool * V_57 )
{
F_78 ( V_18 ( V_4 ) ) ;
if ( F_58 ( V_4 , V_56 , V_57 ) )
return - V_58 ;
F_79 ( & V_4 -> V_17 . V_19 ) ;
return 0 ;
}
void F_80 ( struct V_21 * V_22 )
{
F_81 ( V_56 ) ;
bool V_57 = false ;
struct V_3 * V_4 , * V_60 ;
F_44 () ;
F_45 () ;
F_27 ( & V_32 ) ;
F_63 (s, s2, &slab_caches, list) {
if ( V_18 ( V_4 ) || V_4 -> V_17 . V_22 != V_22 )
continue;
F_78 ( F_77 ( V_4 , & V_56 , & V_57 ) ) ;
}
F_28 ( & V_32 ) ;
F_53 () ;
F_54 () ;
F_61 ( & V_56 , V_57 ) ;
}
static int F_82 ( struct V_3 * V_4 ,
struct V_55 * V_56 , bool * V_57 )
{
struct V_24 * V_25 ;
struct V_3 * V_70 , * V_73 ;
F_81 ( V_74 ) ;
int V_14 ;
F_78 ( ! V_18 ( V_4 ) ) ;
V_25 = F_22 ( V_4 -> V_17 . V_20 ,
F_23 ( & V_32 ) ) ;
F_83 (i) {
V_70 = V_25 -> V_33 [ V_14 ] ;
if ( ! V_70 )
continue;
if ( F_77 ( V_70 , V_56 , V_57 ) )
F_60 ( & V_70 -> V_17 . V_19 , & V_74 ) ;
else
V_25 -> V_33 [ V_14 ] = NULL ;
}
F_63 (c, c2, &s->memcg_params.list,
memcg_params.list)
F_77 ( V_70 , V_56 , V_57 ) ;
F_84 ( & V_74 , & V_4 -> V_17 . V_19 ) ;
if ( ! F_85 ( & V_4 -> V_17 . V_19 ) )
return - V_58 ;
return 0 ;
}
static inline int F_82 ( struct V_3 * V_4 ,
struct V_55 * V_56 , bool * V_57 )
{
return 0 ;
}
void F_66 ( struct V_3 * V_4 )
{
F_86 ( V_4 ) ;
F_19 ( V_4 ) ;
F_51 ( V_4 -> V_6 ) ;
F_10 ( V_3 , V_4 ) ;
}
void F_87 ( struct V_3 * V_4 )
{
F_81 ( V_56 ) ;
bool V_57 = false ;
int V_46 ;
if ( F_88 ( ! V_4 ) )
return;
F_44 () ;
F_45 () ;
F_89 ( V_4 ) ;
F_27 ( & V_32 ) ;
V_4 -> V_39 -- ;
if ( V_4 -> V_39 )
goto V_51;
V_46 = F_82 ( V_4 , & V_56 , & V_57 ) ;
if ( ! V_46 )
V_46 = F_58 ( V_4 , & V_56 , & V_57 ) ;
if ( V_46 ) {
F_5 ( L_6 ,
V_4 -> V_6 ) ;
F_57 () ;
}
V_51:
F_28 ( & V_32 ) ;
F_53 () ;
F_54 () ;
F_61 ( & V_56 , V_57 ) ;
}
int F_90 ( struct V_3 * V_75 )
{
int V_36 ;
F_44 () ;
F_45 () ;
F_91 ( V_75 ) ;
V_36 = F_76 ( V_75 ) ;
F_53 () ;
F_54 () ;
return V_36 ;
}
bool F_92 ( void )
{
return V_76 >= V_77 ;
}
void T_1 F_93 ( struct V_3 * V_4 , const char * V_6 , T_2 V_7 ,
unsigned long V_15 )
{
int V_46 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_7 = V_4 -> V_5 = V_7 ;
V_4 -> V_40 = F_32 ( V_15 , V_78 , V_7 ) ;
F_14 ( V_4 ) ;
V_46 = F_40 ( V_4 , V_15 ) ;
if ( V_46 )
F_55 ( L_7 ,
V_6 , V_7 , V_46 ) ;
V_4 -> V_39 = - 1 ;
}
struct V_3 * T_1 F_94 ( const char * V_6 , T_2 V_7 ,
unsigned long V_15 )
{
struct V_3 * V_4 = F_39 ( V_3 , V_79 ) ;
if ( ! V_4 )
F_55 ( L_8 , V_6 ) ;
F_93 ( V_4 , V_6 , V_7 , V_15 ) ;
F_41 ( & V_4 -> V_19 , & V_49 ) ;
V_4 -> V_39 = 1 ;
return V_4 ;
}
static inline int F_95 ( T_2 V_80 )
{
return ( V_80 - 1 ) / 8 ;
}
struct V_3 * F_96 ( T_2 V_7 , T_3 V_15 )
{
int V_81 ;
if ( F_88 ( V_7 > V_8 ) ) {
F_97 ( ! ( V_15 & V_82 ) ) ;
return NULL ;
}
if ( V_7 <= 192 ) {
if ( ! V_7 )
return V_83 ;
V_81 = V_84 [ F_95 ( V_7 ) ] ;
} else
V_81 = F_98 ( V_7 - 1 ) ;
#ifdef F_99
if ( F_88 ( ( V_15 & V_85 ) ) )
return V_86 [ V_81 ] ;
#endif
return V_87 [ V_81 ] ;
}
void T_1 F_100 ( void )
{
int V_14 ;
F_101 ( V_88 > 256 ||
( V_88 & ( V_88 - 1 ) ) ) ;
for ( V_14 = 8 ; V_14 < V_88 ; V_14 += 8 ) {
int V_89 = F_95 ( V_14 ) ;
if ( V_89 >= F_102 ( V_84 ) )
break;
V_84 [ V_89 ] = V_90 ;
}
if ( V_88 >= 64 ) {
for ( V_14 = 64 + 8 ; V_14 <= 96 ; V_14 += 8 )
V_84 [ F_95 ( V_14 ) ] = 7 ;
}
if ( V_88 >= 128 ) {
for ( V_14 = 128 + 8 ; V_14 <= 192 ; V_14 += 8 )
V_84 [ F_95 ( V_14 ) ] = 8 ;
}
}
static void T_1 F_103 ( int V_65 , unsigned long V_15 )
{
V_87 [ V_65 ] = F_94 ( V_91 [ V_65 ] . V_6 ,
V_91 [ V_65 ] . V_7 , V_15 ) ;
}
void T_1 F_104 ( unsigned long V_15 )
{
int V_14 ;
for ( V_14 = V_90 ; V_14 <= V_92 ; V_14 ++ ) {
if ( ! V_87 [ V_14 ] )
F_103 ( V_14 , V_15 ) ;
if ( V_88 <= 32 && ! V_87 [ 1 ] && V_14 == 6 )
F_103 ( 1 , V_15 ) ;
if ( V_88 <= 64 && ! V_87 [ 2 ] && V_14 == 7 )
F_103 ( 2 , V_15 ) ;
}
V_76 = V_77 ;
#ifdef F_99
for ( V_14 = 0 ; V_14 <= V_92 ; V_14 ++ ) {
struct V_3 * V_4 = V_87 [ V_14 ] ;
if ( V_4 ) {
int V_7 = F_105 ( V_14 ) ;
char * V_93 = F_70 ( V_79 ,
L_9 , V_7 ) ;
F_78 ( ! V_93 ) ;
V_86 [ V_14 ] = F_94 ( V_93 ,
V_7 , V_94 | V_15 ) ;
}
}
#endif
}
void * F_106 ( T_2 V_7 , T_3 V_15 , unsigned int V_95 )
{
void * V_36 ;
struct V_96 * V_96 ;
V_15 |= V_97 ;
V_96 = F_107 ( V_15 , V_95 ) ;
V_36 = V_96 ? F_108 ( V_96 ) : NULL ;
F_109 ( V_36 , V_7 , 1 , V_15 ) ;
F_110 ( V_36 , V_7 , V_15 ) ;
return V_36 ;
}
void * F_111 ( T_2 V_7 , T_3 V_15 , unsigned int V_95 )
{
void * V_36 = F_106 ( V_7 , V_15 , V_95 ) ;
F_112 ( V_98 , V_36 , V_7 , V_99 << V_95 , V_15 ) ;
return V_36 ;
}
static void F_113 ( struct V_100 * V_101 , unsigned int * V_19 ,
T_2 V_102 )
{
T_2 V_14 ;
unsigned int rand ;
for ( V_14 = 0 ; V_14 < V_102 ; V_14 ++ )
V_19 [ V_14 ] = V_14 ;
for ( V_14 = V_102 - 1 ; V_14 > 0 ; V_14 -- ) {
rand = F_114 ( V_101 ) ;
rand %= ( V_14 + 1 ) ;
F_115 ( V_19 [ V_14 ] , V_19 [ rand ] ) ;
}
}
int F_116 ( struct V_3 * V_75 , unsigned int V_102 ,
T_3 V_103 )
{
struct V_100 V_101 ;
if ( V_102 < 2 || V_75 -> V_104 )
return 0 ;
V_75 -> V_104 = F_117 ( V_102 , sizeof( unsigned int ) , V_103 ) ;
if ( ! V_75 -> V_104 )
return - V_28 ;
F_118 ( & V_101 , F_119 () ) ;
F_113 ( & V_101 , V_75 -> V_104 , V_102 ) ;
return 0 ;
}
void F_120 ( struct V_3 * V_75 )
{
F_11 ( V_75 -> V_104 ) ;
V_75 -> V_104 = NULL ;
}
static void F_121 ( struct V_105 * V_106 )
{
#ifdef F_122
F_123 ( V_106 , L_10 ) ;
#else
F_123 ( V_106 , L_11 ) ;
#endif
F_123 ( V_106 , L_12 ) ;
F_123 ( V_106 , L_13 ) ;
F_123 ( V_106 , L_14 ) ;
#ifdef F_122
F_123 ( V_106 , L_15 ) ;
F_123 ( V_106 , L_16 ) ;
#endif
F_124 ( V_106 , '\n' ) ;
}
void * F_125 ( struct V_105 * V_106 , T_4 * V_107 )
{
F_27 ( & V_32 ) ;
return F_126 ( & V_49 , * V_107 ) ;
}
void * F_127 ( struct V_105 * V_106 , void * V_13 , T_4 * V_107 )
{
return F_128 ( V_13 , & V_49 , V_107 ) ;
}
void F_129 ( struct V_105 * V_106 , void * V_13 )
{
F_28 ( & V_32 ) ;
}
static void
F_130 ( struct V_3 * V_4 , struct V_108 * V_109 )
{
struct V_3 * V_70 ;
struct V_108 V_110 ;
if ( ! V_18 ( V_4 ) )
return;
F_131 (c, s) {
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
F_132 ( V_70 , & V_110 ) ;
V_109 -> V_111 += V_110 . V_111 ;
V_109 -> V_112 += V_110 . V_112 ;
V_109 -> V_113 += V_110 . V_113 ;
V_109 -> V_114 += V_110 . V_114 ;
V_109 -> V_115 += V_110 . V_115 ;
}
}
static void F_133 ( struct V_3 * V_4 , struct V_105 * V_106 )
{
struct V_108 V_110 ;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
F_132 ( V_4 , & V_110 ) ;
F_130 ( V_4 , & V_110 ) ;
F_134 ( V_106 , L_17 ,
V_50 ( V_4 ) , V_110 . V_114 , V_110 . V_115 , V_4 -> V_7 ,
V_110 . V_116 , ( 1 << V_110 . V_117 ) ) ;
F_134 ( V_106 , L_18 ,
V_110 . V_118 , V_110 . V_119 , V_110 . V_120 ) ;
F_134 ( V_106 , L_19 ,
V_110 . V_111 , V_110 . V_112 , V_110 . V_113 ) ;
F_135 ( V_106 , V_4 ) ;
F_124 ( V_106 , '\n' ) ;
}
static int F_136 ( struct V_105 * V_106 , void * V_13 )
{
struct V_3 * V_4 = F_137 ( V_13 , struct V_3 , V_19 ) ;
if ( V_13 == V_49 . V_121 )
F_121 ( V_106 ) ;
if ( V_18 ( V_4 ) )
F_133 ( V_4 , V_106 ) ;
return 0 ;
}
int F_138 ( struct V_105 * V_106 , void * V_13 )
{
struct V_3 * V_4 = F_137 ( V_13 , struct V_3 , V_19 ) ;
struct V_21 * V_22 = F_139 ( F_140 ( V_106 ) ) ;
if ( V_13 == V_49 . V_121 )
F_121 ( V_106 ) ;
if ( ! V_18 ( V_4 ) && V_4 -> V_17 . V_22 == V_22 )
F_133 ( V_4 , V_106 ) ;
return 0 ;
}
static int F_141 ( struct V_122 * V_122 , struct V_123 * V_123 )
{
return F_142 ( V_123 , & V_124 ) ;
}
static int T_1 F_143 ( void )
{
F_144 ( L_20 , V_125 , NULL ,
& V_126 ) ;
return 0 ;
}
static T_5 void * F_145 ( const void * V_13 , T_2 V_127 ,
T_3 V_15 )
{
void * V_36 ;
T_2 V_128 = 0 ;
if ( V_13 )
V_128 = F_146 ( V_13 ) ;
if ( V_128 >= V_127 ) {
F_147 ( ( void * ) V_13 , V_127 , V_15 ) ;
return ( void * ) V_13 ;
}
V_36 = F_148 ( V_127 , V_15 ) ;
if ( V_36 && V_13 )
memcpy ( V_36 , V_13 , V_128 ) ;
return V_36 ;
}
void * F_149 ( const void * V_13 , T_2 V_127 , T_3 V_15 )
{
if ( F_88 ( ! V_127 ) )
return V_83 ;
return F_145 ( V_13 , V_127 , V_15 ) ;
}
void * F_150 ( const void * V_13 , T_2 V_127 , T_3 V_15 )
{
void * V_36 ;
if ( F_88 ( ! V_127 ) ) {
F_11 ( V_13 ) ;
return V_83 ;
}
V_36 = F_145 ( V_13 , V_127 , V_15 ) ;
if ( V_36 && V_13 != V_36 )
F_11 ( V_13 ) ;
return V_36 ;
}
void F_151 ( const void * V_13 )
{
T_2 V_128 ;
void * V_129 = ( void * ) V_13 ;
if ( F_88 ( F_152 ( V_129 ) ) )
return;
V_128 = F_146 ( V_129 ) ;
memset ( V_129 , 0 , V_128 ) ;
F_11 ( V_129 ) ;
}
