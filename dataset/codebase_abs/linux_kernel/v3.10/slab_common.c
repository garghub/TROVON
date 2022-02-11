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
if ( ! V_2 && ! strcmp ( V_6 -> V_3 , V_3 ) ) {
F_3 ( L_3 ,
V_12 , V_3 ) ;
F_6 () ;
V_6 = NULL ;
return - V_8 ;
}
}
F_7 ( strchr ( V_3 , ' ' ) ) ;
return 0 ;
}
static inline int F_1 ( struct V_1 * V_2 ,
const char * V_3 , T_1 V_4 )
{
return 0 ;
}
int F_8 ( int V_13 )
{
struct V_5 * V_6 ;
int V_14 = 0 ;
F_9 ( & V_15 ) ;
F_4 (s, &slab_caches, list) {
if ( ! F_10 ( V_6 ) )
continue;
V_14 = F_11 ( V_6 , V_13 ) ;
if ( V_14 )
goto V_16;
}
F_12 ( V_13 ) ;
V_16:
F_13 ( & V_15 ) ;
return V_14 ;
}
unsigned long F_14 ( unsigned long V_17 ,
unsigned long V_18 , unsigned long V_4 )
{
if ( V_17 & V_19 ) {
unsigned long V_20 = F_15 () ;
while ( V_4 <= V_20 / 2 )
V_20 /= 2 ;
V_18 = F_16 ( V_18 , V_20 ) ;
}
if ( V_18 < V_21 )
V_18 = V_21 ;
return F_17 ( V_18 , sizeof( void * ) ) ;
}
struct V_5 *
F_18 ( struct V_1 * V_2 , const char * V_3 , T_1 V_4 ,
T_1 V_18 , unsigned long V_17 , void (* F_19)( void * ) ,
struct V_5 * V_22 )
{
struct V_5 * V_6 = NULL ;
int V_23 = 0 ;
F_20 () ;
F_9 ( & V_15 ) ;
if ( ! F_1 ( V_2 , V_3 , V_4 ) == 0 )
goto V_24;
V_17 &= V_25 ;
V_6 = F_21 ( V_2 , V_3 , V_4 , V_18 , V_17 , F_19 ) ;
if ( V_6 )
goto V_24;
V_6 = F_22 ( V_5 , V_26 ) ;
if ( V_6 ) {
V_6 -> V_11 = V_6 -> V_4 = V_4 ;
V_6 -> V_18 = F_14 ( V_17 , V_18 , V_4 ) ;
V_6 -> F_19 = F_19 ;
if ( F_23 ( V_2 , V_6 , V_22 ) ) {
F_24 ( V_5 , V_6 ) ;
V_23 = - V_27 ;
goto V_24;
}
V_6 -> V_3 = F_25 ( V_3 , V_26 ) ;
if ( ! V_6 -> V_3 ) {
F_24 ( V_5 , V_6 ) ;
V_23 = - V_27 ;
goto V_24;
}
V_23 = F_26 ( V_6 , V_17 ) ;
if ( ! V_23 ) {
V_6 -> V_28 = 1 ;
F_27 ( & V_6 -> V_29 , & V_30 ) ;
F_28 ( V_2 , V_6 ) ;
} else {
F_29 ( V_6 -> V_3 ) ;
F_24 ( V_5 , V_6 ) ;
}
} else
V_23 = - V_27 ;
V_24:
F_13 ( & V_15 ) ;
F_30 () ;
if ( V_23 ) {
if ( V_17 & V_31 )
F_31 ( L_4 ,
V_3 , V_23 ) ;
else {
F_32 ( V_32 L_5 ,
V_3 , V_23 ) ;
F_6 () ;
}
return NULL ;
}
return V_6 ;
}
struct V_5 *
F_33 ( const char * V_3 , T_1 V_4 , T_1 V_18 ,
unsigned long V_17 , void (* F_19)( void * ) )
{
return F_18 ( NULL , V_3 , V_4 , V_18 , V_17 , F_19 , NULL ) ;
}
void F_34 ( struct V_5 * V_6 )
{
F_35 ( V_6 ) ;
F_20 () ;
F_9 ( & V_15 ) ;
V_6 -> V_28 -- ;
if ( ! V_6 -> V_28 ) {
F_36 ( & V_6 -> V_29 ) ;
if ( ! F_37 ( V_6 ) ) {
F_13 ( & V_15 ) ;
if ( V_6 -> V_17 & V_33 )
F_38 () ;
F_39 ( V_6 ) ;
F_29 ( V_6 -> V_3 ) ;
F_24 ( V_5 , V_6 ) ;
} else {
F_27 ( & V_6 -> V_29 , & V_30 ) ;
F_13 ( & V_15 ) ;
F_32 ( V_34 L_6 ,
V_6 -> V_3 ) ;
F_6 () ;
}
} else {
F_13 ( & V_15 ) ;
}
F_30 () ;
}
int F_40 ( void )
{
return V_35 >= V_36 ;
}
void T_2 F_41 ( struct V_5 * V_6 , const char * V_3 , T_1 V_4 ,
unsigned long V_17 )
{
int V_23 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_4 = V_6 -> V_11 = V_4 ;
V_6 -> V_18 = F_14 ( V_17 , V_37 , V_4 ) ;
V_23 = F_26 ( V_6 , V_17 ) ;
if ( V_23 )
F_31 ( L_7 ,
V_3 , V_4 , V_23 ) ;
V_6 -> V_28 = - 1 ;
}
struct V_5 * T_2 F_42 ( const char * V_3 , T_1 V_4 ,
unsigned long V_17 )
{
struct V_5 * V_6 = F_22 ( V_5 , V_38 ) ;
if ( ! V_6 )
F_31 ( L_8 , V_3 ) ;
F_41 ( V_6 , V_3 , V_4 , V_17 ) ;
F_27 ( & V_6 -> V_29 , & V_30 ) ;
V_6 -> V_28 = 1 ;
return V_6 ;
}
static inline int F_43 ( T_1 V_39 )
{
return ( V_39 - 1 ) / 8 ;
}
struct V_5 * F_44 ( T_1 V_4 , T_3 V_17 )
{
int V_40 ;
if ( V_4 > V_7 ) {
F_45 ( ! ( V_17 & V_41 ) ) ;
return NULL ;
}
if ( V_4 <= 192 ) {
if ( ! V_4 )
return V_42 ;
V_40 = V_43 [ F_43 ( V_4 ) ] ;
} else
V_40 = F_46 ( V_4 - 1 ) ;
#ifdef F_47
if ( F_48 ( ( V_17 & V_44 ) ) )
return V_45 [ V_40 ] ;
#endif
return V_46 [ V_40 ] ;
}
void T_2 F_49 ( unsigned long V_17 )
{
int V_47 ;
F_50 ( V_48 > 256 ||
( V_48 & ( V_48 - 1 ) ) ) ;
for ( V_47 = 8 ; V_47 < V_48 ; V_47 += 8 ) {
int V_49 = F_43 ( V_47 ) ;
if ( V_49 >= F_51 ( V_43 ) )
break;
V_43 [ V_49 ] = V_50 ;
}
if ( V_48 >= 64 ) {
for ( V_47 = 64 + 8 ; V_47 <= 96 ; V_47 += 8 )
V_43 [ F_43 ( V_47 ) ] = 7 ;
}
if ( V_48 >= 128 ) {
for ( V_47 = 128 + 8 ; V_47 <= 192 ; V_47 += 8 )
V_43 [ F_43 ( V_47 ) ] = 8 ;
}
for ( V_47 = V_50 ; V_47 <= V_51 ; V_47 ++ ) {
if ( ! V_46 [ V_47 ] ) {
V_46 [ V_47 ] = F_42 ( NULL ,
1 << V_47 , V_17 ) ;
}
if ( V_48 <= 32 && ! V_46 [ 1 ] && V_47 == 6 )
V_46 [ 1 ] = F_42 ( NULL , 96 , V_17 ) ;
if ( V_48 <= 64 && ! V_46 [ 2 ] && V_47 == 7 )
V_46 [ 2 ] = F_42 ( NULL , 192 , V_17 ) ;
}
V_35 = V_36 ;
for ( V_47 = 0 ; V_47 <= V_51 ; V_47 ++ ) {
struct V_5 * V_6 = V_46 [ V_47 ] ;
char * V_52 ;
if ( V_6 ) {
V_52 = F_52 ( V_38 , L_9 , F_53 ( V_47 ) ) ;
F_54 ( ! V_52 ) ;
V_6 -> V_3 = V_52 ;
}
}
#ifdef F_47
for ( V_47 = 0 ; V_47 <= V_51 ; V_47 ++ ) {
struct V_5 * V_6 = V_46 [ V_47 ] ;
if ( V_6 ) {
int V_4 = F_53 ( V_47 ) ;
char * V_52 = F_52 ( V_38 ,
L_10 , V_4 ) ;
F_54 ( ! V_52 ) ;
V_45 [ V_47 ] = F_42 ( V_52 ,
V_4 , V_53 | V_17 ) ;
}
}
#endif
}
void F_55 ( struct V_54 * V_55 )
{
#ifdef F_56
F_57 ( V_55 , L_11 ) ;
#else
F_57 ( V_55 , L_12 ) ;
#endif
F_57 ( V_55 , L_13
L_14 ) ;
F_57 ( V_55 , L_15 ) ;
F_57 ( V_55 , L_16 ) ;
#ifdef F_56
F_57 ( V_55 , L_17
L_18 ) ;
F_57 ( V_55 , L_19 ) ;
#endif
F_58 ( V_55 , '\n' ) ;
}
static void * F_59 ( struct V_54 * V_55 , T_4 * V_56 )
{
T_4 V_52 = * V_56 ;
F_9 ( & V_15 ) ;
if ( ! V_52 )
F_55 ( V_55 ) ;
return F_60 ( & V_30 , * V_56 ) ;
}
static void * F_61 ( struct V_54 * V_55 , void * V_57 , T_4 * V_56 )
{
return F_62 ( V_57 , & V_30 , V_56 ) ;
}
static void F_63 ( struct V_54 * V_55 , void * V_57 )
{
F_13 ( & V_15 ) ;
}
static void
F_64 ( struct V_5 * V_6 , struct V_58 * V_59 )
{
struct V_5 * V_60 ;
struct V_58 V_61 ;
int V_47 ;
if ( ! F_10 ( V_6 ) )
return;
F_65 (i) {
V_60 = F_66 ( V_6 , V_47 ) ;
if ( ! V_60 )
continue;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
F_67 ( V_60 , & V_61 ) ;
V_59 -> V_62 += V_61 . V_62 ;
V_59 -> V_63 += V_61 . V_63 ;
V_59 -> V_64 += V_61 . V_64 ;
V_59 -> V_65 += V_61 . V_65 ;
V_59 -> V_66 += V_61 . V_66 ;
}
}
int F_68 ( struct V_5 * V_6 , struct V_54 * V_55 )
{
struct V_58 V_61 ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
F_67 ( V_6 , & V_61 ) ;
F_64 ( V_6 , & V_61 ) ;
F_69 ( V_55 , L_20 ,
F_70 ( V_6 ) , V_61 . V_65 , V_61 . V_66 , V_6 -> V_4 ,
V_61 . V_67 , ( 1 << V_61 . V_68 ) ) ;
F_69 ( V_55 , L_21 ,
V_61 . V_69 , V_61 . V_70 , V_61 . V_71 ) ;
F_69 ( V_55 , L_22 ,
V_61 . V_62 , V_61 . V_63 , V_61 . V_64 ) ;
F_71 ( V_55 , V_6 ) ;
F_58 ( V_55 , '\n' ) ;
return 0 ;
}
static int F_72 ( struct V_54 * V_55 , void * V_57 )
{
struct V_5 * V_6 = F_73 ( V_57 , struct V_5 , V_29 ) ;
if ( ! F_10 ( V_6 ) )
return 0 ;
return F_68 ( V_6 , V_55 ) ;
}
static int F_74 ( struct V_72 * V_72 , struct V_73 * V_73 )
{
return F_75 ( V_73 , & V_74 ) ;
}
static int T_2 F_76 ( void )
{
F_77 ( L_23 , V_75 , NULL , & V_76 ) ;
return 0 ;
}
