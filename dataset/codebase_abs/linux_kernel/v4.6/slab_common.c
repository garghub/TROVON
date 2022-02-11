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
V_15 &= V_52 ;
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
if ( V_15 & V_53 )
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
struct V_54 * V_55 , bool * V_56 )
{
if ( F_59 ( V_4 ) != 0 )
return - V_57 ;
if ( V_4 -> V_15 & V_58 )
* V_56 = true ;
F_60 ( & V_4 -> V_19 , V_55 ) ;
return 0 ;
}
static void F_61 ( struct V_54 * V_55 , bool V_56 )
{
struct V_3 * V_4 , * V_59 ;
if ( V_56 )
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
static char V_60 [ V_61 + 1 ] ;
struct V_62 * V_63 = & V_22 -> V_63 ;
struct V_24 * V_25 ;
struct V_3 * V_4 = NULL ;
char * V_50 ;
int V_64 ;
F_44 () ;
F_45 () ;
F_27 ( & V_32 ) ;
if ( V_22 -> V_65 != V_66 )
goto V_51;
V_64 = F_68 ( V_22 ) ;
V_25 = F_22 ( V_23 -> V_17 . V_20 ,
F_23 ( & V_32 ) ) ;
if ( V_25 -> V_33 [ V_64 ] )
goto V_51;
F_69 ( V_63 -> V_67 , V_60 , sizeof( V_60 ) ) ;
V_50 = F_70 ( V_27 , L_5 , V_23 -> V_6 ,
V_63 -> V_68 , V_60 ) ;
if ( ! V_50 )
goto V_51;
V_4 = F_38 ( V_50 , V_23 -> V_5 ,
V_23 -> V_7 , V_23 -> V_40 ,
V_23 -> V_15 , V_23 -> V_38 ,
V_22 , V_23 ) ;
if ( F_49 ( V_4 ) ) {
F_11 ( V_50 ) ;
goto V_51;
}
F_41 ( & V_4 -> V_17 . V_19 , & V_23 -> V_17 . V_19 ) ;
F_71 () ;
V_25 -> V_33 [ V_64 ] = V_4 ;
V_51:
F_28 ( & V_32 ) ;
F_53 () ;
F_54 () ;
}
void F_72 ( struct V_21 * V_22 )
{
int V_64 ;
struct V_24 * V_25 ;
struct V_3 * V_4 , * V_69 ;
V_64 = F_68 ( V_22 ) ;
F_44 () ;
F_45 () ;
F_27 ( & V_32 ) ;
F_6 (s, &slab_caches, list) {
if ( ! V_18 ( V_4 ) )
continue;
V_25 = F_22 ( V_4 -> V_17 . V_20 ,
F_23 ( & V_32 ) ) ;
V_69 = V_25 -> V_33 [ V_64 ] ;
if ( ! V_69 )
continue;
F_73 ( V_69 , true ) ;
V_25 -> V_33 [ V_64 ] = NULL ;
}
F_28 ( & V_32 ) ;
F_53 () ;
F_54 () ;
}
static int F_74 ( struct V_3 * V_4 ,
struct V_54 * V_55 , bool * V_56 )
{
F_75 ( V_18 ( V_4 ) ) ;
if ( F_58 ( V_4 , V_55 , V_56 ) )
return - V_57 ;
F_76 ( & V_4 -> V_17 . V_19 ) ;
return 0 ;
}
void F_77 ( struct V_21 * V_22 )
{
F_78 ( V_55 ) ;
bool V_56 = false ;
struct V_3 * V_4 , * V_59 ;
F_44 () ;
F_45 () ;
F_27 ( & V_32 ) ;
F_63 (s, s2, &slab_caches, list) {
if ( V_18 ( V_4 ) || V_4 -> V_17 . V_22 != V_22 )
continue;
F_75 ( F_74 ( V_4 , & V_55 , & V_56 ) ) ;
}
F_28 ( & V_32 ) ;
F_53 () ;
F_54 () ;
F_61 ( & V_55 , V_56 ) ;
}
static int F_79 ( struct V_3 * V_4 ,
struct V_54 * V_55 , bool * V_56 )
{
struct V_24 * V_25 ;
struct V_3 * V_69 , * V_70 ;
F_78 ( V_71 ) ;
int V_14 ;
F_75 ( ! V_18 ( V_4 ) ) ;
V_25 = F_22 ( V_4 -> V_17 . V_20 ,
F_23 ( & V_32 ) ) ;
F_80 (i) {
V_69 = V_25 -> V_33 [ V_14 ] ;
if ( ! V_69 )
continue;
if ( F_74 ( V_69 , V_55 , V_56 ) )
F_60 ( & V_69 -> V_17 . V_19 , & V_71 ) ;
else
V_25 -> V_33 [ V_14 ] = NULL ;
}
F_63 (c, c2, &s->memcg_params.list,
memcg_params.list)
F_74 ( V_69 , V_55 , V_56 ) ;
F_81 ( & V_71 , & V_4 -> V_17 . V_19 ) ;
if ( ! F_82 ( & V_4 -> V_17 . V_19 ) )
return - V_57 ;
return 0 ;
}
static inline int F_79 ( struct V_3 * V_4 ,
struct V_54 * V_55 , bool * V_56 )
{
return 0 ;
}
void F_66 ( struct V_3 * V_4 )
{
F_83 ( V_4 ) ;
F_19 ( V_4 ) ;
F_51 ( V_4 -> V_6 ) ;
F_10 ( V_3 , V_4 ) ;
}
void F_84 ( struct V_3 * V_4 )
{
F_78 ( V_55 ) ;
bool V_56 = false ;
int V_46 ;
if ( F_85 ( ! V_4 ) )
return;
F_44 () ;
F_45 () ;
F_27 ( & V_32 ) ;
V_4 -> V_39 -- ;
if ( V_4 -> V_39 )
goto V_51;
V_46 = F_79 ( V_4 , & V_55 , & V_56 ) ;
if ( ! V_46 )
V_46 = F_58 ( V_4 , & V_55 , & V_56 ) ;
if ( V_46 ) {
F_5 ( L_6 ,
V_4 -> V_6 ) ;
F_57 () ;
}
V_51:
F_28 ( & V_32 ) ;
F_53 () ;
F_54 () ;
F_61 ( & V_55 , V_56 ) ;
}
int F_86 ( struct V_3 * V_72 )
{
int V_36 ;
F_44 () ;
F_45 () ;
V_36 = F_73 ( V_72 , false ) ;
F_53 () ;
F_54 () ;
return V_36 ;
}
bool F_87 ( void )
{
return V_73 >= V_74 ;
}
void T_1 F_88 ( struct V_3 * V_4 , const char * V_6 , T_2 V_7 ,
unsigned long V_15 )
{
int V_46 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_7 = V_4 -> V_5 = V_7 ;
V_4 -> V_40 = F_32 ( V_15 , V_75 , V_7 ) ;
F_14 ( V_4 ) ;
V_46 = F_40 ( V_4 , V_15 ) ;
if ( V_46 )
F_55 ( L_7 ,
V_6 , V_7 , V_46 ) ;
V_4 -> V_39 = - 1 ;
}
struct V_3 * T_1 F_89 ( const char * V_6 , T_2 V_7 ,
unsigned long V_15 )
{
struct V_3 * V_4 = F_39 ( V_3 , V_76 ) ;
if ( ! V_4 )
F_55 ( L_8 , V_6 ) ;
F_88 ( V_4 , V_6 , V_7 , V_15 ) ;
F_41 ( & V_4 -> V_19 , & V_49 ) ;
V_4 -> V_39 = 1 ;
return V_4 ;
}
static inline int F_90 ( T_2 V_77 )
{
return ( V_77 - 1 ) / 8 ;
}
struct V_3 * F_91 ( T_2 V_7 , T_3 V_15 )
{
int V_78 ;
if ( F_85 ( V_7 > V_8 ) ) {
F_92 ( ! ( V_15 & V_79 ) ) ;
return NULL ;
}
if ( V_7 <= 192 ) {
if ( ! V_7 )
return V_80 ;
V_78 = V_81 [ F_90 ( V_7 ) ] ;
} else
V_78 = F_93 ( V_7 - 1 ) ;
#ifdef F_94
if ( F_85 ( ( V_15 & V_82 ) ) )
return V_83 [ V_78 ] ;
#endif
return V_84 [ V_78 ] ;
}
void T_1 F_95 ( void )
{
int V_14 ;
F_96 ( V_85 > 256 ||
( V_85 & ( V_85 - 1 ) ) ) ;
for ( V_14 = 8 ; V_14 < V_85 ; V_14 += 8 ) {
int V_86 = F_90 ( V_14 ) ;
if ( V_86 >= F_97 ( V_81 ) )
break;
V_81 [ V_86 ] = V_87 ;
}
if ( V_85 >= 64 ) {
for ( V_14 = 64 + 8 ; V_14 <= 96 ; V_14 += 8 )
V_81 [ F_90 ( V_14 ) ] = 7 ;
}
if ( V_85 >= 128 ) {
for ( V_14 = 128 + 8 ; V_14 <= 192 ; V_14 += 8 )
V_81 [ F_90 ( V_14 ) ] = 8 ;
}
}
static void T_1 F_98 ( int V_64 , unsigned long V_15 )
{
V_84 [ V_64 ] = F_89 ( V_88 [ V_64 ] . V_6 ,
V_88 [ V_64 ] . V_7 , V_15 ) ;
}
void T_1 F_99 ( unsigned long V_15 )
{
int V_14 ;
for ( V_14 = V_87 ; V_14 <= V_89 ; V_14 ++ ) {
if ( ! V_84 [ V_14 ] )
F_98 ( V_14 , V_15 ) ;
if ( V_85 <= 32 && ! V_84 [ 1 ] && V_14 == 6 )
F_98 ( 1 , V_15 ) ;
if ( V_85 <= 64 && ! V_84 [ 2 ] && V_14 == 7 )
F_98 ( 2 , V_15 ) ;
}
V_73 = V_74 ;
#ifdef F_94
for ( V_14 = 0 ; V_14 <= V_89 ; V_14 ++ ) {
struct V_3 * V_4 = V_84 [ V_14 ] ;
if ( V_4 ) {
int V_7 = F_100 ( V_14 ) ;
char * V_90 = F_70 ( V_76 ,
L_9 , V_7 ) ;
F_75 ( ! V_90 ) ;
V_83 [ V_14 ] = F_89 ( V_90 ,
V_7 , V_91 | V_15 ) ;
}
}
#endif
}
void * F_101 ( T_2 V_7 , T_3 V_15 , unsigned int V_92 )
{
void * V_36 ;
struct V_93 * V_93 ;
V_15 |= V_94 ;
V_93 = F_102 ( V_15 , V_92 ) ;
V_36 = V_93 ? F_103 ( V_93 ) : NULL ;
F_104 ( V_36 , V_7 , 1 , V_15 ) ;
F_105 ( V_36 , V_7 , V_15 ) ;
return V_36 ;
}
void * F_106 ( T_2 V_7 , T_3 V_15 , unsigned int V_92 )
{
void * V_36 = F_101 ( V_7 , V_15 , V_92 ) ;
F_107 ( V_95 , V_36 , V_7 , V_96 << V_92 , V_15 ) ;
return V_36 ;
}
static void F_108 ( struct V_97 * V_98 )
{
#ifdef F_109
F_110 ( V_98 , L_10 ) ;
#else
F_110 ( V_98 , L_11 ) ;
#endif
F_110 ( V_98 , L_12 ) ;
F_110 ( V_98 , L_13 ) ;
F_110 ( V_98 , L_14 ) ;
#ifdef F_109
F_110 ( V_98 , L_15 ) ;
F_110 ( V_98 , L_16 ) ;
#endif
F_111 ( V_98 , '\n' ) ;
}
void * F_112 ( struct V_97 * V_98 , T_4 * V_99 )
{
F_27 ( & V_32 ) ;
return F_113 ( & V_49 , * V_99 ) ;
}
void * F_114 ( struct V_97 * V_98 , void * V_13 , T_4 * V_99 )
{
return F_115 ( V_13 , & V_49 , V_99 ) ;
}
void F_116 ( struct V_97 * V_98 , void * V_13 )
{
F_28 ( & V_32 ) ;
}
static void
F_117 ( struct V_3 * V_4 , struct V_100 * V_101 )
{
struct V_3 * V_69 ;
struct V_100 V_102 ;
if ( ! V_18 ( V_4 ) )
return;
F_118 (c, s) {
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
F_119 ( V_69 , & V_102 ) ;
V_101 -> V_103 += V_102 . V_103 ;
V_101 -> V_104 += V_102 . V_104 ;
V_101 -> V_105 += V_102 . V_105 ;
V_101 -> V_106 += V_102 . V_106 ;
V_101 -> V_107 += V_102 . V_107 ;
}
}
static void F_120 ( struct V_3 * V_4 , struct V_97 * V_98 )
{
struct V_100 V_102 ;
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
F_119 ( V_4 , & V_102 ) ;
F_117 ( V_4 , & V_102 ) ;
F_121 ( V_98 , L_17 ,
V_50 ( V_4 ) , V_102 . V_106 , V_102 . V_107 , V_4 -> V_7 ,
V_102 . V_108 , ( 1 << V_102 . V_109 ) ) ;
F_121 ( V_98 , L_18 ,
V_102 . V_110 , V_102 . V_111 , V_102 . V_112 ) ;
F_121 ( V_98 , L_19 ,
V_102 . V_103 , V_102 . V_104 , V_102 . V_105 ) ;
F_122 ( V_98 , V_4 ) ;
F_111 ( V_98 , '\n' ) ;
}
static int F_123 ( struct V_97 * V_98 , void * V_13 )
{
struct V_3 * V_4 = F_124 ( V_13 , struct V_3 , V_19 ) ;
if ( V_13 == V_49 . V_113 )
F_108 ( V_98 ) ;
if ( V_18 ( V_4 ) )
F_120 ( V_4 , V_98 ) ;
return 0 ;
}
int F_125 ( struct V_97 * V_98 , void * V_13 )
{
struct V_3 * V_4 = F_124 ( V_13 , struct V_3 , V_19 ) ;
struct V_21 * V_22 = F_126 ( F_127 ( V_98 ) ) ;
if ( V_13 == V_49 . V_113 )
F_108 ( V_98 ) ;
if ( ! V_18 ( V_4 ) && V_4 -> V_17 . V_22 == V_22 )
F_120 ( V_4 , V_98 ) ;
return 0 ;
}
static int F_128 ( struct V_114 * V_114 , struct V_115 * V_115 )
{
return F_129 ( V_115 , & V_116 ) ;
}
static int T_1 F_130 ( void )
{
F_131 ( L_20 , V_117 , NULL ,
& V_118 ) ;
return 0 ;
}
static T_5 void * F_132 ( const void * V_13 , T_2 V_119 ,
T_3 V_15 )
{
void * V_36 ;
T_2 V_120 = 0 ;
if ( V_13 )
V_120 = F_133 ( V_13 ) ;
if ( V_120 >= V_119 ) {
F_134 ( ( void * ) V_13 , V_119 , V_15 ) ;
return ( void * ) V_13 ;
}
V_36 = F_135 ( V_119 , V_15 ) ;
if ( V_36 && V_13 )
memcpy ( V_36 , V_13 , V_120 ) ;
return V_36 ;
}
void * F_136 ( const void * V_13 , T_2 V_119 , T_3 V_15 )
{
if ( F_85 ( ! V_119 ) )
return V_80 ;
return F_132 ( V_13 , V_119 , V_15 ) ;
}
void * F_137 ( const void * V_13 , T_2 V_119 , T_3 V_15 )
{
void * V_36 ;
if ( F_85 ( ! V_119 ) ) {
F_11 ( V_13 ) ;
return V_80 ;
}
V_36 = F_132 ( V_13 , V_119 , V_15 ) ;
if ( V_36 && V_13 != V_36 )
F_11 ( V_13 ) ;
return V_36 ;
}
void F_138 ( const void * V_13 )
{
T_2 V_120 ;
void * V_121 = ( void * ) V_13 ;
if ( F_85 ( F_139 ( V_121 ) ) )
return;
V_120 = F_133 ( V_121 ) ;
memset ( V_121 , 0 , V_120 ) ;
F_11 ( V_121 ) ;
}
