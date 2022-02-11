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
#if ! F_6 ( V_10 ) || ! F_6 ( V_11 )
if ( ! strcmp ( V_4 -> V_1 , V_1 ) ) {
F_3 ( L_3 ,
V_12 , V_1 ) ;
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
int F_9 ( int V_13 )
{
struct V_3 * V_4 ;
int V_14 = 0 ;
F_10 ( & V_15 ) ;
F_4 (s, &slab_caches, list) {
if ( ! F_11 ( V_4 ) )
continue;
V_14 = F_12 ( V_4 , V_13 ) ;
if ( V_14 )
goto V_16;
}
F_13 ( V_13 ) ;
V_16:
F_14 ( & V_15 ) ;
return V_14 ;
}
unsigned long F_15 ( unsigned long V_17 ,
unsigned long V_18 , unsigned long V_2 )
{
if ( V_17 & V_19 ) {
unsigned long V_20 = F_16 () ;
while ( V_2 <= V_20 / 2 )
V_20 /= 2 ;
V_18 = F_17 ( V_18 , V_20 ) ;
}
if ( V_18 < V_21 )
V_18 = V_21 ;
return F_18 ( V_18 , sizeof( void * ) ) ;
}
static struct V_3 *
F_19 ( char * V_1 , T_1 V_9 , T_1 V_2 , T_1 V_18 ,
unsigned long V_17 , void (* F_20)( void * ) ,
struct V_22 * V_23 , struct V_3 * V_24 )
{
struct V_3 * V_4 ;
int V_25 ;
V_25 = - V_26 ;
V_4 = F_21 ( V_3 , V_27 ) ;
if ( ! V_4 )
goto V_16;
V_4 -> V_1 = V_1 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_18 = V_18 ;
V_4 -> F_20 = F_20 ;
V_25 = F_22 ( V_23 , V_4 , V_24 ) ;
if ( V_25 )
goto V_28;
V_25 = F_23 ( V_4 , V_17 ) ;
if ( V_25 )
goto V_28;
V_4 -> V_29 = 1 ;
F_24 ( & V_4 -> V_30 , & V_31 ) ;
F_25 ( V_4 ) ;
V_16:
if ( V_25 )
return F_26 ( V_25 ) ;
return V_4 ;
V_28:
F_27 ( V_4 ) ;
F_28 ( V_4 ) ;
goto V_16;
}
struct V_3 *
F_29 ( const char * V_1 , T_1 V_2 , T_1 V_18 ,
unsigned long V_17 , void (* F_20)( void * ) )
{
struct V_3 * V_4 ;
char * V_32 ;
int V_25 ;
F_30 () ;
F_10 ( & V_15 ) ;
V_25 = F_1 ( V_1 , V_2 ) ;
if ( V_25 )
goto V_33;
V_17 &= V_34 ;
V_4 = F_31 ( V_1 , V_2 , V_18 , V_17 , F_20 ) ;
if ( V_4 )
goto V_33;
V_32 = F_32 ( V_1 , V_27 ) ;
if ( ! V_32 ) {
V_25 = - V_26 ;
goto V_33;
}
V_4 = F_19 ( V_32 , V_2 , V_2 ,
F_15 ( V_17 , V_18 , V_2 ) ,
V_17 , F_20 , NULL , NULL ) ;
if ( F_33 ( V_4 ) ) {
V_25 = F_34 ( V_4 ) ;
F_28 ( V_32 ) ;
}
V_33:
F_14 ( & V_15 ) ;
F_35 () ;
if ( V_25 ) {
if ( V_17 & V_35 )
F_36 ( L_4 ,
V_1 , V_25 ) ;
else {
F_37 ( V_36 L_5 ,
V_1 , V_25 ) ;
F_7 () ;
}
return NULL ;
}
return V_4 ;
}
void F_38 ( struct V_22 * V_23 , struct V_3 * V_24 )
{
struct V_3 * V_4 ;
char * V_32 ;
F_30 () ;
F_10 ( & V_15 ) ;
if ( F_39 ( V_24 , F_40 ( V_23 ) ) )
goto V_33;
V_32 = F_41 ( V_23 , V_24 ) ;
if ( ! V_32 )
goto V_33;
V_4 = F_19 ( V_32 , V_24 -> V_9 ,
V_24 -> V_2 , V_24 -> V_18 ,
V_24 -> V_17 , V_24 -> F_20 ,
V_23 , V_24 ) ;
if ( F_33 ( V_4 ) ) {
F_28 ( V_32 ) ;
goto V_33;
}
V_4 -> V_37 |= V_38 ;
V_33:
F_14 ( & V_15 ) ;
F_35 () ;
}
static int F_42 ( struct V_3 * V_4 )
{
int V_39 ;
if ( ! V_4 -> V_40 ||
! V_4 -> V_40 -> F_11 )
return 0 ;
F_14 ( & V_15 ) ;
V_39 = F_43 ( V_4 ) ;
F_10 ( & V_15 ) ;
return V_39 ;
}
static int F_42 ( struct V_3 * V_4 )
{
return 0 ;
}
void F_44 ( struct V_3 * V_4 )
{
F_28 ( V_4 -> V_1 ) ;
F_45 ( V_3 , V_4 ) ;
}
void F_46 ( struct V_3 * V_4 )
{
F_30 () ;
F_10 ( & V_15 ) ;
V_4 -> V_29 -- ;
if ( V_4 -> V_29 )
goto V_33;
if ( F_42 ( V_4 ) != 0 )
goto V_33;
F_47 ( & V_4 -> V_30 ) ;
F_48 ( V_4 ) ;
if ( F_49 ( V_4 ) != 0 ) {
F_24 ( & V_4 -> V_30 , & V_31 ) ;
F_25 ( V_4 ) ;
F_37 ( V_41 L_6
L_7 , V_4 -> V_1 ) ;
F_7 () ;
goto V_33;
}
F_14 ( & V_15 ) ;
if ( V_4 -> V_17 & V_42 )
F_50 () ;
F_27 ( V_4 ) ;
#ifdef F_51
F_52 ( V_4 ) ;
#else
F_44 ( V_4 ) ;
#endif
goto V_43;
V_33:
F_14 ( & V_15 ) ;
V_43:
F_35 () ;
}
int F_53 ( void )
{
return V_44 >= V_45 ;
}
void T_2 F_54 ( struct V_3 * V_4 , const char * V_1 , T_1 V_2 ,
unsigned long V_17 )
{
int V_25 ;
V_4 -> V_1 = V_1 ;
V_4 -> V_2 = V_4 -> V_9 = V_2 ;
V_4 -> V_18 = F_15 ( V_17 , V_46 , V_2 ) ;
V_25 = F_23 ( V_4 , V_17 ) ;
if ( V_25 )
F_36 ( L_8 ,
V_1 , V_2 , V_25 ) ;
V_4 -> V_29 = - 1 ;
}
struct V_3 * T_2 F_55 ( const char * V_1 , T_1 V_2 ,
unsigned long V_17 )
{
struct V_3 * V_4 = F_21 ( V_3 , V_47 ) ;
if ( ! V_4 )
F_36 ( L_9 , V_1 ) ;
F_54 ( V_4 , V_1 , V_2 , V_17 ) ;
F_24 ( & V_4 -> V_30 , & V_31 ) ;
V_4 -> V_29 = 1 ;
return V_4 ;
}
static inline int F_56 ( T_1 V_48 )
{
return ( V_48 - 1 ) / 8 ;
}
struct V_3 * F_57 ( T_1 V_2 , T_3 V_17 )
{
int V_49 ;
if ( F_58 ( V_2 > V_5 ) ) {
F_59 ( ! ( V_17 & V_50 ) ) ;
return NULL ;
}
if ( V_2 <= 192 ) {
if ( ! V_2 )
return V_51 ;
V_49 = V_52 [ F_56 ( V_2 ) ] ;
} else
V_49 = F_60 ( V_2 - 1 ) ;
#ifdef F_61
if ( F_58 ( ( V_17 & V_53 ) ) )
return V_54 [ V_49 ] ;
#endif
return V_55 [ V_49 ] ;
}
void T_2 F_62 ( unsigned long V_17 )
{
int V_56 ;
F_63 ( V_57 > 256 ||
( V_57 & ( V_57 - 1 ) ) ) ;
for ( V_56 = 8 ; V_56 < V_57 ; V_56 += 8 ) {
int V_58 = F_56 ( V_56 ) ;
if ( V_58 >= F_64 ( V_52 ) )
break;
V_52 [ V_58 ] = V_59 ;
}
if ( V_57 >= 64 ) {
for ( V_56 = 64 + 8 ; V_56 <= 96 ; V_56 += 8 )
V_52 [ F_56 ( V_56 ) ] = 7 ;
}
if ( V_57 >= 128 ) {
for ( V_56 = 128 + 8 ; V_56 <= 192 ; V_56 += 8 )
V_52 [ F_56 ( V_56 ) ] = 8 ;
}
for ( V_56 = V_59 ; V_56 <= V_60 ; V_56 ++ ) {
if ( ! V_55 [ V_56 ] ) {
V_55 [ V_56 ] = F_55 ( NULL ,
1 << V_56 , V_17 ) ;
}
if ( V_57 <= 32 && ! V_55 [ 1 ] && V_56 == 6 )
V_55 [ 1 ] = F_55 ( NULL , 96 , V_17 ) ;
if ( V_57 <= 64 && ! V_55 [ 2 ] && V_56 == 7 )
V_55 [ 2 ] = F_55 ( NULL , 192 , V_17 ) ;
}
V_44 = V_45 ;
for ( V_56 = 0 ; V_56 <= V_60 ; V_56 ++ ) {
struct V_3 * V_4 = V_55 [ V_56 ] ;
char * V_61 ;
if ( V_4 ) {
V_61 = F_65 ( V_47 , L_10 , F_66 ( V_56 ) ) ;
F_67 ( ! V_61 ) ;
V_4 -> V_1 = V_61 ;
}
}
#ifdef F_61
for ( V_56 = 0 ; V_56 <= V_60 ; V_56 ++ ) {
struct V_3 * V_4 = V_55 [ V_56 ] ;
if ( V_4 ) {
int V_2 = F_66 ( V_56 ) ;
char * V_61 = F_65 ( V_47 ,
L_11 , V_2 ) ;
F_67 ( ! V_61 ) ;
V_54 [ V_56 ] = F_55 ( V_61 ,
V_2 , V_62 | V_17 ) ;
}
}
#endif
}
void * F_68 ( T_1 V_2 , T_3 V_17 , unsigned int V_63 )
{
void * V_14 = F_69 ( V_2 , V_17 , V_63 ) ;
F_70 ( V_64 , V_14 , V_2 , V_65 << V_63 , V_17 ) ;
return V_14 ;
}
void F_71 ( struct V_66 * V_67 )
{
#ifdef F_72
F_73 ( V_67 , L_12 ) ;
#else
F_73 ( V_67 , L_13 ) ;
#endif
F_73 ( V_67 , L_14
L_15 ) ;
F_73 ( V_67 , L_16 ) ;
F_73 ( V_67 , L_17 ) ;
#ifdef F_72
F_73 ( V_67 , L_18
L_19 ) ;
F_73 ( V_67 , L_20 ) ;
#endif
F_74 ( V_67 , '\n' ) ;
}
static void * F_75 ( struct V_66 * V_67 , T_4 * V_68 )
{
T_4 V_61 = * V_68 ;
F_10 ( & V_15 ) ;
if ( ! V_61 )
F_71 ( V_67 ) ;
return F_76 ( & V_31 , * V_68 ) ;
}
void * F_77 ( struct V_66 * V_67 , void * V_69 , T_4 * V_68 )
{
return F_78 ( V_69 , & V_31 , V_68 ) ;
}
void F_79 ( struct V_66 * V_67 , void * V_69 )
{
F_14 ( & V_15 ) ;
}
static void
F_80 ( struct V_3 * V_4 , struct V_70 * V_71 )
{
struct V_3 * V_72 ;
struct V_70 V_73 ;
int V_56 ;
if ( ! F_11 ( V_4 ) )
return;
F_81 (i) {
V_72 = F_39 ( V_4 , V_56 ) ;
if ( ! V_72 )
continue;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
F_82 ( V_72 , & V_73 ) ;
V_71 -> V_74 += V_73 . V_74 ;
V_71 -> V_75 += V_73 . V_75 ;
V_71 -> V_76 += V_73 . V_76 ;
V_71 -> V_77 += V_73 . V_77 ;
V_71 -> V_78 += V_73 . V_78 ;
}
}
int F_83 ( struct V_3 * V_4 , struct V_66 * V_67 )
{
struct V_70 V_73 ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
F_82 ( V_4 , & V_73 ) ;
F_80 ( V_4 , & V_73 ) ;
F_84 ( V_67 , L_21 ,
V_32 ( V_4 ) , V_73 . V_77 , V_73 . V_78 , V_4 -> V_2 ,
V_73 . V_79 , ( 1 << V_73 . V_80 ) ) ;
F_84 ( V_67 , L_22 ,
V_73 . V_81 , V_73 . V_82 , V_73 . V_83 ) ;
F_84 ( V_67 , L_23 ,
V_73 . V_74 , V_73 . V_75 , V_73 . V_76 ) ;
F_85 ( V_67 , V_4 ) ;
F_74 ( V_67 , '\n' ) ;
return 0 ;
}
static int F_86 ( struct V_66 * V_67 , void * V_69 )
{
struct V_3 * V_4 = F_87 ( V_69 , struct V_3 , V_30 ) ;
if ( ! F_11 ( V_4 ) )
return 0 ;
return F_83 ( V_4 , V_67 ) ;
}
static int F_88 ( struct V_84 * V_84 , struct V_85 * V_85 )
{
return F_89 ( V_85 , & V_86 ) ;
}
static int T_2 F_90 ( void )
{
F_91 ( L_24 , V_87 , NULL ,
& V_88 ) ;
return 0 ;
}
