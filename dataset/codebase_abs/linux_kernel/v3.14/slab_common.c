static int F_1 ( struct V_1 * V_2 , const char * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = NULL ;
if ( ! V_3 || F_2 () || V_4 < sizeof( void * ) ||
V_4 > V_7 ) {
F_3 ( L_1 , V_3 ) ;
return - V_8 ;
}
F_4 (s, &slab_caches, list) {
char V_9 ;
int V_10 ;
V_10 = F_5 ( V_6 -> V_3 , V_9 ) ;
if ( V_10 ) {
F_3 ( L_2 ,
V_6 -> V_11 ) ;
continue;
}
#if ! F_6 ( V_12 ) || ! F_6 ( V_13 )
if ( ! V_2 && ! strcmp ( V_6 -> V_3 , V_3 ) ) {
F_3 ( L_3 ,
V_14 , V_3 ) ;
F_7 () ;
V_6 = NULL ;
return - V_8 ;
}
#endif
}
F_8 ( strchr ( V_3 , ' ' ) ) ;
return 0 ;
}
static inline int F_1 ( struct V_1 * V_2 ,
const char * V_3 , T_1 V_4 )
{
return 0 ;
}
int F_9 ( int V_15 )
{
struct V_5 * V_6 ;
int V_16 = 0 ;
F_10 ( & V_17 ) ;
F_4 (s, &slab_caches, list) {
if ( ! F_11 ( V_6 ) )
continue;
V_16 = F_12 ( V_6 , V_15 ) ;
if ( V_16 )
goto V_18;
}
F_13 ( V_15 ) ;
V_18:
F_14 ( & V_17 ) ;
return V_16 ;
}
unsigned long F_15 ( unsigned long V_19 ,
unsigned long V_20 , unsigned long V_4 )
{
if ( V_19 & V_21 ) {
unsigned long V_22 = F_16 () ;
while ( V_4 <= V_22 / 2 )
V_22 /= 2 ;
V_20 = F_17 ( V_20 , V_22 ) ;
}
if ( V_20 < V_23 )
V_20 = V_23 ;
return F_18 ( V_20 , sizeof( void * ) ) ;
}
struct V_5 *
F_19 ( struct V_1 * V_2 , const char * V_3 , T_1 V_4 ,
T_1 V_20 , unsigned long V_19 , void (* F_20)( void * ) ,
struct V_5 * V_24 )
{
struct V_5 * V_6 = NULL ;
int V_25 ;
F_21 () ;
F_10 ( & V_17 ) ;
V_25 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_25 )
goto V_26;
if ( V_2 ) {
if ( F_22 ( V_24 , F_23 ( V_2 ) ) )
goto V_26;
}
V_19 &= V_27 ;
V_6 = F_24 ( V_2 , V_3 , V_4 , V_20 , V_19 , F_20 ) ;
if ( V_6 )
goto V_26;
V_25 = - V_28 ;
V_6 = F_25 ( V_5 , V_29 ) ;
if ( ! V_6 )
goto V_26;
V_6 -> V_11 = V_6 -> V_4 = V_4 ;
V_6 -> V_20 = F_15 ( V_19 , V_20 , V_4 ) ;
V_6 -> F_20 = F_20 ;
V_6 -> V_3 = F_26 ( V_3 , V_29 ) ;
if ( ! V_6 -> V_3 )
goto V_30;
V_25 = F_27 ( V_2 , V_6 , V_24 ) ;
if ( V_25 )
goto V_30;
V_25 = F_28 ( V_6 , V_19 ) ;
if ( V_25 )
goto V_30;
V_6 -> V_31 = 1 ;
F_29 ( & V_6 -> V_32 , & V_33 ) ;
F_30 ( V_6 ) ;
V_26:
F_14 ( & V_17 ) ;
F_31 () ;
if ( V_25 ) {
if ( ! V_2 )
return NULL ;
if ( V_19 & V_34 )
F_32 ( L_4 ,
V_3 , V_25 ) ;
else {
F_33 ( V_35 L_5 ,
V_3 , V_25 ) ;
F_7 () ;
}
return NULL ;
}
return V_6 ;
V_30:
F_34 ( V_6 ) ;
F_35 ( V_6 -> V_3 ) ;
F_36 ( V_5 , V_6 ) ;
goto V_26;
}
struct V_5 *
F_37 ( const char * V_3 , T_1 V_4 , T_1 V_20 ,
unsigned long V_19 , void (* F_20)( void * ) )
{
return F_19 ( NULL , V_3 , V_4 , V_20 , V_19 , F_20 , NULL ) ;
}
void F_38 ( struct V_5 * V_6 )
{
F_39 ( V_6 ) ;
F_21 () ;
F_10 ( & V_17 ) ;
V_6 -> V_31 -- ;
if ( ! V_6 -> V_31 ) {
F_40 ( & V_6 -> V_32 ) ;
if ( ! F_41 ( V_6 ) ) {
F_42 ( V_6 ) ;
F_14 ( & V_17 ) ;
if ( V_6 -> V_19 & V_36 )
F_43 () ;
F_34 ( V_6 ) ;
F_35 ( V_6 -> V_3 ) ;
F_36 ( V_5 , V_6 ) ;
} else {
F_29 ( & V_6 -> V_32 , & V_33 ) ;
F_14 ( & V_17 ) ;
F_33 ( V_37 L_6 ,
V_6 -> V_3 ) ;
F_7 () ;
}
} else {
F_14 ( & V_17 ) ;
}
F_31 () ;
}
int F_44 ( void )
{
return V_38 >= V_39 ;
}
void T_2 F_45 ( struct V_5 * V_6 , const char * V_3 , T_1 V_4 ,
unsigned long V_19 )
{
int V_25 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_4 = V_6 -> V_11 = V_4 ;
V_6 -> V_20 = F_15 ( V_19 , V_40 , V_4 ) ;
V_25 = F_28 ( V_6 , V_19 ) ;
if ( V_25 )
F_32 ( L_7 ,
V_3 , V_4 , V_25 ) ;
V_6 -> V_31 = - 1 ;
}
struct V_5 * T_2 F_46 ( const char * V_3 , T_1 V_4 ,
unsigned long V_19 )
{
struct V_5 * V_6 = F_25 ( V_5 , V_41 ) ;
if ( ! V_6 )
F_32 ( L_8 , V_3 ) ;
F_45 ( V_6 , V_3 , V_4 , V_19 ) ;
F_29 ( & V_6 -> V_32 , & V_33 ) ;
V_6 -> V_31 = 1 ;
return V_6 ;
}
static inline int F_47 ( T_1 V_42 )
{
return ( V_42 - 1 ) / 8 ;
}
struct V_5 * F_48 ( T_1 V_4 , T_3 V_19 )
{
int V_43 ;
if ( F_49 ( V_4 > V_7 ) ) {
F_50 ( ! ( V_19 & V_44 ) ) ;
return NULL ;
}
if ( V_4 <= 192 ) {
if ( ! V_4 )
return V_45 ;
V_43 = V_46 [ F_47 ( V_4 ) ] ;
} else
V_43 = F_51 ( V_4 - 1 ) ;
#ifdef F_52
if ( F_49 ( ( V_19 & V_47 ) ) )
return V_48 [ V_43 ] ;
#endif
return V_49 [ V_43 ] ;
}
void T_2 F_53 ( unsigned long V_19 )
{
int V_50 ;
F_54 ( V_51 > 256 ||
( V_51 & ( V_51 - 1 ) ) ) ;
for ( V_50 = 8 ; V_50 < V_51 ; V_50 += 8 ) {
int V_52 = F_47 ( V_50 ) ;
if ( V_52 >= F_55 ( V_46 ) )
break;
V_46 [ V_52 ] = V_53 ;
}
if ( V_51 >= 64 ) {
for ( V_50 = 64 + 8 ; V_50 <= 96 ; V_50 += 8 )
V_46 [ F_47 ( V_50 ) ] = 7 ;
}
if ( V_51 >= 128 ) {
for ( V_50 = 128 + 8 ; V_50 <= 192 ; V_50 += 8 )
V_46 [ F_47 ( V_50 ) ] = 8 ;
}
for ( V_50 = V_53 ; V_50 <= V_54 ; V_50 ++ ) {
if ( ! V_49 [ V_50 ] ) {
V_49 [ V_50 ] = F_46 ( NULL ,
1 << V_50 , V_19 ) ;
}
if ( V_51 <= 32 && ! V_49 [ 1 ] && V_50 == 6 )
V_49 [ 1 ] = F_46 ( NULL , 96 , V_19 ) ;
if ( V_51 <= 64 && ! V_49 [ 2 ] && V_50 == 7 )
V_49 [ 2 ] = F_46 ( NULL , 192 , V_19 ) ;
}
V_38 = V_39 ;
for ( V_50 = 0 ; V_50 <= V_54 ; V_50 ++ ) {
struct V_5 * V_6 = V_49 [ V_50 ] ;
char * V_55 ;
if ( V_6 ) {
V_55 = F_56 ( V_41 , L_9 , F_57 ( V_50 ) ) ;
F_58 ( ! V_55 ) ;
V_6 -> V_3 = V_55 ;
}
}
#ifdef F_52
for ( V_50 = 0 ; V_50 <= V_54 ; V_50 ++ ) {
struct V_5 * V_6 = V_49 [ V_50 ] ;
if ( V_6 ) {
int V_4 = F_57 ( V_50 ) ;
char * V_55 = F_56 ( V_41 ,
L_10 , V_4 ) ;
F_58 ( ! V_55 ) ;
V_48 [ V_50 ] = F_46 ( V_55 ,
V_4 , V_56 | V_19 ) ;
}
}
#endif
}
void * F_59 ( T_1 V_4 , T_3 V_19 , unsigned int V_57 )
{
void * V_16 = F_60 ( V_4 , V_19 , V_57 ) ;
F_61 ( V_58 , V_16 , V_4 , V_59 << V_57 , V_19 ) ;
return V_16 ;
}
void F_62 ( struct V_60 * V_61 )
{
#ifdef F_63
F_64 ( V_61 , L_11 ) ;
#else
F_64 ( V_61 , L_12 ) ;
#endif
F_64 ( V_61 , L_13
L_14 ) ;
F_64 ( V_61 , L_15 ) ;
F_64 ( V_61 , L_16 ) ;
#ifdef F_63
F_64 ( V_61 , L_17
L_18 ) ;
F_64 ( V_61 , L_19 ) ;
#endif
F_65 ( V_61 , '\n' ) ;
}
static void * F_66 ( struct V_60 * V_61 , T_4 * V_62 )
{
T_4 V_55 = * V_62 ;
F_10 ( & V_17 ) ;
if ( ! V_55 )
F_62 ( V_61 ) ;
return F_67 ( & V_33 , * V_62 ) ;
}
void * F_68 ( struct V_60 * V_61 , void * V_63 , T_4 * V_62 )
{
return F_69 ( V_63 , & V_33 , V_62 ) ;
}
void F_70 ( struct V_60 * V_61 , void * V_63 )
{
F_14 ( & V_17 ) ;
}
static void
F_71 ( struct V_5 * V_6 , struct V_64 * V_65 )
{
struct V_5 * V_66 ;
struct V_64 V_67 ;
int V_50 ;
if ( ! F_11 ( V_6 ) )
return;
F_72 (i) {
V_66 = F_22 ( V_6 , V_50 ) ;
if ( ! V_66 )
continue;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
F_73 ( V_66 , & V_67 ) ;
V_65 -> V_68 += V_67 . V_68 ;
V_65 -> V_69 += V_67 . V_69 ;
V_65 -> V_70 += V_67 . V_70 ;
V_65 -> V_71 += V_67 . V_71 ;
V_65 -> V_72 += V_67 . V_72 ;
}
}
int F_74 ( struct V_5 * V_6 , struct V_60 * V_61 )
{
struct V_64 V_67 ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
F_73 ( V_6 , & V_67 ) ;
F_71 ( V_6 , & V_67 ) ;
F_75 ( V_61 , L_20 ,
F_76 ( V_6 ) , V_67 . V_71 , V_67 . V_72 , V_6 -> V_4 ,
V_67 . V_73 , ( 1 << V_67 . V_74 ) ) ;
F_75 ( V_61 , L_21 ,
V_67 . V_75 , V_67 . V_76 , V_67 . V_77 ) ;
F_75 ( V_61 , L_22 ,
V_67 . V_68 , V_67 . V_69 , V_67 . V_70 ) ;
F_77 ( V_61 , V_6 ) ;
F_65 ( V_61 , '\n' ) ;
return 0 ;
}
static int F_78 ( struct V_60 * V_61 , void * V_63 )
{
struct V_5 * V_6 = F_79 ( V_63 , struct V_5 , V_32 ) ;
if ( ! F_11 ( V_6 ) )
return 0 ;
return F_74 ( V_6 , V_61 ) ;
}
static int F_80 ( struct V_78 * V_78 , struct V_79 * V_79 )
{
return F_81 ( V_79 , & V_80 ) ;
}
static int T_2 F_82 ( void )
{
F_83 ( L_23 , V_81 , NULL ,
& V_82 ) ;
return 0 ;
}
