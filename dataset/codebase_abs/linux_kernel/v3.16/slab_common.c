static int F_1 ( const char * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = NULL ;
if ( ! V_1 || F_2 () || V_2 < sizeof( void * ) ||
V_2 > V_5 ) {
F_3 ( L_1 , V_1 ) ;
return - V_6 ;
}
F_4 (s, &slab_caches, list) {
char V_7 ;
int V_8 ;
V_8 = F_5 ( V_4 -> V_1 , V_7 ) ;
if ( V_8 ) {
F_3 ( L_2 ,
V_4 -> V_9 ) ;
continue;
}
#if ! F_6 ( V_10 )
if ( ! strcmp ( V_4 -> V_1 , V_1 ) ) {
F_3 ( L_3 ,
V_11 , V_1 ) ;
F_7 () ;
V_4 = NULL ;
return - V_6 ;
}
#endif
}
F_8 ( strchr ( V_1 , ' ' ) ) ;
return 0 ;
}
static inline int F_1 ( const char * V_1 , T_1 V_2 )
{
return 0 ;
}
int F_9 ( int V_12 )
{
struct V_3 * V_4 ;
int V_13 = 0 ;
F_10 ( & V_14 ) ;
F_4 (s, &slab_caches, list) {
if ( ! F_11 ( V_4 ) )
continue;
V_13 = F_12 ( V_4 , V_12 ) ;
if ( V_13 )
goto V_15;
}
F_13 ( V_12 ) ;
V_15:
F_14 ( & V_14 ) ;
return V_13 ;
}
unsigned long F_15 ( unsigned long V_16 ,
unsigned long V_17 , unsigned long V_2 )
{
if ( V_16 & V_18 ) {
unsigned long V_19 = F_16 () ;
while ( V_2 <= V_19 / 2 )
V_19 /= 2 ;
V_17 = F_17 ( V_17 , V_19 ) ;
}
if ( V_17 < V_20 )
V_17 = V_20 ;
return F_18 ( V_17 , sizeof( void * ) ) ;
}
static struct V_3 *
F_19 ( char * V_1 , T_1 V_9 , T_1 V_2 , T_1 V_17 ,
unsigned long V_16 , void (* F_20)( void * ) ,
struct V_21 * V_22 , struct V_3 * V_23 )
{
struct V_3 * V_4 ;
int V_24 ;
V_24 = - V_25 ;
V_4 = F_21 ( V_3 , V_26 ) ;
if ( ! V_4 )
goto V_15;
V_4 -> V_1 = V_1 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_17 = V_17 ;
V_4 -> F_20 = F_20 ;
V_24 = F_22 ( V_22 , V_4 , V_23 ) ;
if ( V_24 )
goto V_27;
V_24 = F_23 ( V_4 , V_16 ) ;
if ( V_24 )
goto V_27;
V_4 -> V_28 = 1 ;
F_24 ( & V_4 -> V_29 , & V_30 ) ;
V_15:
if ( V_24 )
return F_25 ( V_24 ) ;
return V_4 ;
V_27:
F_26 ( V_4 ) ;
F_27 ( V_4 ) ;
goto V_15;
}
struct V_3 *
F_28 ( const char * V_1 , T_1 V_2 , T_1 V_17 ,
unsigned long V_16 , void (* F_20)( void * ) )
{
struct V_3 * V_4 ;
char * V_31 ;
int V_24 ;
F_29 () ;
F_30 () ;
F_10 ( & V_14 ) ;
V_24 = F_1 ( V_1 , V_2 ) ;
if ( V_24 )
goto V_32;
V_16 &= V_33 ;
V_4 = F_31 ( V_1 , V_2 , V_17 , V_16 , F_20 ) ;
if ( V_4 )
goto V_32;
V_31 = F_32 ( V_1 , V_26 ) ;
if ( ! V_31 ) {
V_24 = - V_25 ;
goto V_32;
}
V_4 = F_19 ( V_31 , V_2 , V_2 ,
F_15 ( V_16 , V_17 , V_2 ) ,
V_16 , F_20 , NULL , NULL ) ;
if ( F_33 ( V_4 ) ) {
V_24 = F_34 ( V_4 ) ;
F_27 ( V_31 ) ;
}
V_32:
F_14 ( & V_14 ) ;
F_35 () ;
F_36 () ;
if ( V_24 ) {
if ( V_16 & V_34 )
F_37 ( L_4 ,
V_1 , V_24 ) ;
else {
F_38 ( V_35 L_5 ,
V_1 , V_24 ) ;
F_7 () ;
}
return NULL ;
}
return V_4 ;
}
struct V_3 * F_39 ( struct V_21 * V_22 ,
struct V_3 * V_23 ,
const char * V_36 )
{
struct V_3 * V_4 = NULL ;
char * V_31 ;
F_29 () ;
F_30 () ;
F_10 ( & V_14 ) ;
V_31 = F_40 ( V_26 , L_6 , V_23 -> V_1 ,
F_41 ( V_22 ) , V_36 ) ;
if ( ! V_31 )
goto V_32;
V_4 = F_19 ( V_31 , V_23 -> V_9 ,
V_23 -> V_2 , V_23 -> V_17 ,
V_23 -> V_16 , V_23 -> F_20 ,
V_22 , V_23 ) ;
if ( F_33 ( V_4 ) ) {
F_27 ( V_31 ) ;
V_4 = NULL ;
}
V_32:
F_14 ( & V_14 ) ;
F_35 () ;
F_36 () ;
return V_4 ;
}
static int F_42 ( struct V_3 * V_4 )
{
int V_37 ;
if ( ! V_4 -> V_38 ||
! V_4 -> V_38 -> F_11 )
return 0 ;
F_14 ( & V_14 ) ;
V_37 = F_43 ( V_4 ) ;
F_10 ( & V_14 ) ;
return V_37 ;
}
static int F_42 ( struct V_3 * V_4 )
{
return 0 ;
}
void F_44 ( struct V_3 * V_4 )
{
F_27 ( V_4 -> V_1 ) ;
F_45 ( V_3 , V_4 ) ;
}
void F_46 ( struct V_3 * V_4 )
{
F_29 () ;
F_30 () ;
F_10 ( & V_14 ) ;
V_4 -> V_28 -- ;
if ( V_4 -> V_28 )
goto V_32;
if ( F_42 ( V_4 ) != 0 )
goto V_32;
if ( F_47 ( V_4 ) != 0 ) {
F_38 ( V_39 L_7
L_8 , V_4 -> V_1 ) ;
F_7 () ;
goto V_32;
}
F_48 ( & V_4 -> V_29 ) ;
F_14 ( & V_14 ) ;
if ( V_4 -> V_16 & V_40 )
F_49 () ;
F_26 ( V_4 ) ;
#ifdef F_50
F_51 ( V_4 ) ;
#else
F_44 ( V_4 ) ;
#endif
goto V_15;
V_32:
F_14 ( & V_14 ) ;
V_15:
F_35 () ;
F_36 () ;
}
int F_52 ( struct V_3 * V_41 )
{
int V_13 ;
F_29 () ;
F_30 () ;
V_13 = F_53 ( V_41 ) ;
F_35 () ;
F_36 () ;
return V_13 ;
}
int F_54 ( void )
{
return V_42 >= V_43 ;
}
void T_2 F_55 ( struct V_3 * V_4 , const char * V_1 , T_1 V_2 ,
unsigned long V_16 )
{
int V_24 ;
V_4 -> V_1 = V_1 ;
V_4 -> V_2 = V_4 -> V_9 = V_2 ;
V_4 -> V_17 = F_15 ( V_16 , V_44 , V_2 ) ;
V_24 = F_23 ( V_4 , V_16 ) ;
if ( V_24 )
F_37 ( L_9 ,
V_1 , V_2 , V_24 ) ;
V_4 -> V_28 = - 1 ;
}
struct V_3 * T_2 F_56 ( const char * V_1 , T_1 V_2 ,
unsigned long V_16 )
{
struct V_3 * V_4 = F_21 ( V_3 , V_45 ) ;
if ( ! V_4 )
F_37 ( L_10 , V_1 ) ;
F_55 ( V_4 , V_1 , V_2 , V_16 ) ;
F_24 ( & V_4 -> V_29 , & V_30 ) ;
V_4 -> V_28 = 1 ;
return V_4 ;
}
static inline int F_57 ( T_1 V_46 )
{
return ( V_46 - 1 ) / 8 ;
}
struct V_3 * F_58 ( T_1 V_2 , T_3 V_16 )
{
int V_47 ;
if ( F_59 ( V_2 > V_5 ) ) {
F_60 ( ! ( V_16 & V_48 ) ) ;
return NULL ;
}
if ( V_2 <= 192 ) {
if ( ! V_2 )
return V_49 ;
V_47 = V_50 [ F_57 ( V_2 ) ] ;
} else
V_47 = F_61 ( V_2 - 1 ) ;
#ifdef F_62
if ( F_59 ( ( V_16 & V_51 ) ) )
return V_52 [ V_47 ] ;
#endif
return V_53 [ V_47 ] ;
}
void T_2 F_63 ( unsigned long V_16 )
{
int V_54 ;
F_64 ( V_55 > 256 ||
( V_55 & ( V_55 - 1 ) ) ) ;
for ( V_54 = 8 ; V_54 < V_55 ; V_54 += 8 ) {
int V_56 = F_57 ( V_54 ) ;
if ( V_56 >= F_65 ( V_50 ) )
break;
V_50 [ V_56 ] = V_57 ;
}
if ( V_55 >= 64 ) {
for ( V_54 = 64 + 8 ; V_54 <= 96 ; V_54 += 8 )
V_50 [ F_57 ( V_54 ) ] = 7 ;
}
if ( V_55 >= 128 ) {
for ( V_54 = 128 + 8 ; V_54 <= 192 ; V_54 += 8 )
V_50 [ F_57 ( V_54 ) ] = 8 ;
}
for ( V_54 = V_57 ; V_54 <= V_58 ; V_54 ++ ) {
if ( ! V_53 [ V_54 ] ) {
V_53 [ V_54 ] = F_56 ( NULL ,
1 << V_54 , V_16 ) ;
}
if ( V_55 <= 32 && ! V_53 [ 1 ] && V_54 == 6 )
V_53 [ 1 ] = F_56 ( NULL , 96 , V_16 ) ;
if ( V_55 <= 64 && ! V_53 [ 2 ] && V_54 == 7 )
V_53 [ 2 ] = F_56 ( NULL , 192 , V_16 ) ;
}
V_42 = V_43 ;
for ( V_54 = 0 ; V_54 <= V_58 ; V_54 ++ ) {
struct V_3 * V_4 = V_53 [ V_54 ] ;
char * V_59 ;
if ( V_4 ) {
V_59 = F_40 ( V_45 , L_11 , F_66 ( V_54 ) ) ;
F_67 ( ! V_59 ) ;
V_4 -> V_1 = V_59 ;
}
}
#ifdef F_62
for ( V_54 = 0 ; V_54 <= V_58 ; V_54 ++ ) {
struct V_3 * V_4 = V_53 [ V_54 ] ;
if ( V_4 ) {
int V_2 = F_66 ( V_54 ) ;
char * V_59 = F_40 ( V_45 ,
L_12 , V_2 ) ;
F_67 ( ! V_59 ) ;
V_52 [ V_54 ] = F_56 ( V_59 ,
V_2 , V_60 | V_16 ) ;
}
}
#endif
}
void * F_68 ( T_1 V_2 , T_3 V_16 , unsigned int V_61 )
{
void * V_13 ;
struct V_62 * V_62 ;
V_16 |= V_63 ;
V_62 = F_69 ( V_16 , V_61 ) ;
V_13 = V_62 ? F_70 ( V_62 ) : NULL ;
F_71 ( V_13 , V_2 , 1 , V_16 ) ;
return V_13 ;
}
void * F_72 ( T_1 V_2 , T_3 V_16 , unsigned int V_61 )
{
void * V_13 = F_68 ( V_2 , V_16 , V_61 ) ;
F_73 ( V_64 , V_13 , V_2 , V_65 << V_61 , V_16 ) ;
return V_13 ;
}
void F_74 ( struct V_66 * V_67 )
{
#ifdef F_75
F_76 ( V_67 , L_13 ) ;
#else
F_76 ( V_67 , L_14 ) ;
#endif
F_76 ( V_67 , L_15
L_16 ) ;
F_76 ( V_67 , L_17 ) ;
F_76 ( V_67 , L_18 ) ;
#ifdef F_75
F_76 ( V_67 , L_19
L_20 ) ;
F_76 ( V_67 , L_21 ) ;
#endif
F_77 ( V_67 , '\n' ) ;
}
static void * F_78 ( struct V_66 * V_67 , T_4 * V_68 )
{
T_4 V_59 = * V_68 ;
F_10 ( & V_14 ) ;
if ( ! V_59 )
F_74 ( V_67 ) ;
return F_79 ( & V_30 , * V_68 ) ;
}
void * F_80 ( struct V_66 * V_67 , void * V_69 , T_4 * V_68 )
{
return F_81 ( V_69 , & V_30 , V_68 ) ;
}
void F_82 ( struct V_66 * V_67 , void * V_69 )
{
F_14 ( & V_14 ) ;
}
static void
F_83 ( struct V_3 * V_4 , struct V_70 * V_71 )
{
struct V_3 * V_72 ;
struct V_70 V_73 ;
int V_54 ;
if ( ! F_11 ( V_4 ) )
return;
F_84 (i) {
V_72 = F_85 ( V_4 , V_54 ) ;
if ( ! V_72 )
continue;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
F_86 ( V_72 , & V_73 ) ;
V_71 -> V_74 += V_73 . V_74 ;
V_71 -> V_75 += V_73 . V_75 ;
V_71 -> V_76 += V_73 . V_76 ;
V_71 -> V_77 += V_73 . V_77 ;
V_71 -> V_78 += V_73 . V_78 ;
}
}
int F_87 ( struct V_3 * V_4 , struct V_66 * V_67 )
{
struct V_70 V_73 ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
F_86 ( V_4 , & V_73 ) ;
F_83 ( V_4 , & V_73 ) ;
F_88 ( V_67 , L_22 ,
V_31 ( V_4 ) , V_73 . V_77 , V_73 . V_78 , V_4 -> V_2 ,
V_73 . V_79 , ( 1 << V_73 . V_80 ) ) ;
F_88 ( V_67 , L_23 ,
V_73 . V_81 , V_73 . V_82 , V_73 . V_83 ) ;
F_88 ( V_67 , L_24 ,
V_73 . V_74 , V_73 . V_75 , V_73 . V_76 ) ;
F_89 ( V_67 , V_4 ) ;
F_77 ( V_67 , '\n' ) ;
return 0 ;
}
static int F_90 ( struct V_66 * V_67 , void * V_69 )
{
struct V_3 * V_4 = F_91 ( V_69 , struct V_3 , V_29 ) ;
if ( ! F_11 ( V_4 ) )
return 0 ;
return F_87 ( V_4 , V_67 ) ;
}
static int F_92 ( struct V_84 * V_84 , struct V_85 * V_85 )
{
return F_93 ( V_85 , & V_86 ) ;
}
static int T_2 F_94 ( void )
{
F_95 ( L_25 , V_87 , NULL ,
& V_88 ) ;
return 0 ;
}
