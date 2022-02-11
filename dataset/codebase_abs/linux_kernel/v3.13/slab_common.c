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
int V_25 = 0 ;
F_21 () ;
F_10 ( & V_17 ) ;
if ( ! F_1 ( V_2 , V_3 , V_4 ) == 0 )
goto V_26;
V_19 &= V_27 ;
V_6 = F_22 ( V_2 , V_3 , V_4 , V_20 , V_19 , F_20 ) ;
if ( V_6 )
goto V_26;
V_6 = F_23 ( V_5 , V_28 ) ;
if ( V_6 ) {
V_6 -> V_11 = V_6 -> V_4 = V_4 ;
V_6 -> V_20 = F_15 ( V_19 , V_20 , V_4 ) ;
V_6 -> F_20 = F_20 ;
if ( F_24 ( V_2 , V_6 , V_24 ) ) {
F_25 ( V_5 , V_6 ) ;
V_25 = - V_29 ;
goto V_26;
}
V_6 -> V_3 = F_26 ( V_3 , V_28 ) ;
if ( ! V_6 -> V_3 ) {
F_25 ( V_5 , V_6 ) ;
V_25 = - V_29 ;
goto V_26;
}
V_25 = F_27 ( V_6 , V_19 ) ;
if ( ! V_25 ) {
V_6 -> V_30 = 1 ;
F_28 ( & V_6 -> V_31 , & V_32 ) ;
F_29 ( V_2 , V_6 ) ;
} else {
F_30 ( V_6 -> V_3 ) ;
F_25 ( V_5 , V_6 ) ;
}
} else
V_25 = - V_29 ;
V_26:
F_14 ( & V_17 ) ;
F_31 () ;
if ( V_25 ) {
if ( V_19 & V_33 )
F_32 ( L_4 ,
V_3 , V_25 ) ;
else {
F_33 ( V_34 L_5 ,
V_3 , V_25 ) ;
F_7 () ;
}
return NULL ;
}
return V_6 ;
}
struct V_5 *
F_34 ( const char * V_3 , T_1 V_4 , T_1 V_20 ,
unsigned long V_19 , void (* F_20)( void * ) )
{
return F_19 ( NULL , V_3 , V_4 , V_20 , V_19 , F_20 , NULL ) ;
}
void F_35 ( struct V_5 * V_6 )
{
F_36 ( V_6 ) ;
F_21 () ;
F_10 ( & V_17 ) ;
V_6 -> V_30 -- ;
if ( ! V_6 -> V_30 ) {
F_37 ( & V_6 -> V_31 ) ;
if ( ! F_38 ( V_6 ) ) {
F_14 ( & V_17 ) ;
if ( V_6 -> V_19 & V_35 )
F_39 () ;
F_40 ( V_6 ) ;
F_30 ( V_6 -> V_3 ) ;
F_25 ( V_5 , V_6 ) ;
} else {
F_28 ( & V_6 -> V_31 , & V_32 ) ;
F_14 ( & V_17 ) ;
F_33 ( V_36 L_6 ,
V_6 -> V_3 ) ;
F_7 () ;
}
} else {
F_14 ( & V_17 ) ;
}
F_31 () ;
}
int F_41 ( void )
{
return V_37 >= V_38 ;
}
void T_2 F_42 ( struct V_5 * V_6 , const char * V_3 , T_1 V_4 ,
unsigned long V_19 )
{
int V_25 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_4 = V_6 -> V_11 = V_4 ;
V_6 -> V_20 = F_15 ( V_19 , V_39 , V_4 ) ;
V_25 = F_27 ( V_6 , V_19 ) ;
if ( V_25 )
F_32 ( L_7 ,
V_3 , V_4 , V_25 ) ;
V_6 -> V_30 = - 1 ;
}
struct V_5 * T_2 F_43 ( const char * V_3 , T_1 V_4 ,
unsigned long V_19 )
{
struct V_5 * V_6 = F_23 ( V_5 , V_40 ) ;
if ( ! V_6 )
F_32 ( L_8 , V_3 ) ;
F_42 ( V_6 , V_3 , V_4 , V_19 ) ;
F_28 ( & V_6 -> V_31 , & V_32 ) ;
V_6 -> V_30 = 1 ;
return V_6 ;
}
static inline int F_44 ( T_1 V_41 )
{
return ( V_41 - 1 ) / 8 ;
}
struct V_5 * F_45 ( T_1 V_4 , T_3 V_19 )
{
int V_42 ;
if ( F_46 ( V_4 > V_7 ) ) {
F_47 ( ! ( V_19 & V_43 ) ) ;
return NULL ;
}
if ( V_4 <= 192 ) {
if ( ! V_4 )
return V_44 ;
V_42 = V_45 [ F_44 ( V_4 ) ] ;
} else
V_42 = F_48 ( V_4 - 1 ) ;
#ifdef F_49
if ( F_46 ( ( V_19 & V_46 ) ) )
return V_47 [ V_42 ] ;
#endif
return V_48 [ V_42 ] ;
}
void T_2 F_50 ( unsigned long V_19 )
{
int V_49 ;
F_51 ( V_50 > 256 ||
( V_50 & ( V_50 - 1 ) ) ) ;
for ( V_49 = 8 ; V_49 < V_50 ; V_49 += 8 ) {
int V_51 = F_44 ( V_49 ) ;
if ( V_51 >= F_52 ( V_45 ) )
break;
V_45 [ V_51 ] = V_52 ;
}
if ( V_50 >= 64 ) {
for ( V_49 = 64 + 8 ; V_49 <= 96 ; V_49 += 8 )
V_45 [ F_44 ( V_49 ) ] = 7 ;
}
if ( V_50 >= 128 ) {
for ( V_49 = 128 + 8 ; V_49 <= 192 ; V_49 += 8 )
V_45 [ F_44 ( V_49 ) ] = 8 ;
}
for ( V_49 = V_52 ; V_49 <= V_53 ; V_49 ++ ) {
if ( ! V_48 [ V_49 ] ) {
V_48 [ V_49 ] = F_43 ( NULL ,
1 << V_49 , V_19 ) ;
}
if ( V_50 <= 32 && ! V_48 [ 1 ] && V_49 == 6 )
V_48 [ 1 ] = F_43 ( NULL , 96 , V_19 ) ;
if ( V_50 <= 64 && ! V_48 [ 2 ] && V_49 == 7 )
V_48 [ 2 ] = F_43 ( NULL , 192 , V_19 ) ;
}
V_37 = V_38 ;
for ( V_49 = 0 ; V_49 <= V_53 ; V_49 ++ ) {
struct V_5 * V_6 = V_48 [ V_49 ] ;
char * V_54 ;
if ( V_6 ) {
V_54 = F_53 ( V_40 , L_9 , F_54 ( V_49 ) ) ;
F_55 ( ! V_54 ) ;
V_6 -> V_3 = V_54 ;
}
}
#ifdef F_49
for ( V_49 = 0 ; V_49 <= V_53 ; V_49 ++ ) {
struct V_5 * V_6 = V_48 [ V_49 ] ;
if ( V_6 ) {
int V_4 = F_54 ( V_49 ) ;
char * V_54 = F_53 ( V_40 ,
L_10 , V_4 ) ;
F_55 ( ! V_54 ) ;
V_47 [ V_49 ] = F_43 ( V_54 ,
V_4 , V_55 | V_19 ) ;
}
}
#endif
}
void * F_56 ( T_1 V_4 , T_3 V_19 , unsigned int V_56 )
{
void * V_16 = F_57 ( V_4 , V_19 , V_56 ) ;
F_58 ( V_57 , V_16 , V_4 , V_58 << V_56 , V_19 ) ;
return V_16 ;
}
void F_59 ( struct V_59 * V_60 )
{
#ifdef F_60
F_61 ( V_60 , L_11 ) ;
#else
F_61 ( V_60 , L_12 ) ;
#endif
F_61 ( V_60 , L_13
L_14 ) ;
F_61 ( V_60 , L_15 ) ;
F_61 ( V_60 , L_16 ) ;
#ifdef F_60
F_61 ( V_60 , L_17
L_18 ) ;
F_61 ( V_60 , L_19 ) ;
#endif
F_62 ( V_60 , '\n' ) ;
}
static void * F_63 ( struct V_59 * V_60 , T_4 * V_61 )
{
T_4 V_54 = * V_61 ;
F_10 ( & V_17 ) ;
if ( ! V_54 )
F_59 ( V_60 ) ;
return F_64 ( & V_32 , * V_61 ) ;
}
void * F_65 ( struct V_59 * V_60 , void * V_62 , T_4 * V_61 )
{
return F_66 ( V_62 , & V_32 , V_61 ) ;
}
void F_67 ( struct V_59 * V_60 , void * V_62 )
{
F_14 ( & V_17 ) ;
}
static void
F_68 ( struct V_5 * V_6 , struct V_63 * V_64 )
{
struct V_5 * V_65 ;
struct V_63 V_66 ;
int V_49 ;
if ( ! F_11 ( V_6 ) )
return;
F_69 (i) {
V_65 = F_70 ( V_6 , V_49 ) ;
if ( ! V_65 )
continue;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
F_71 ( V_65 , & V_66 ) ;
V_64 -> V_67 += V_66 . V_67 ;
V_64 -> V_68 += V_66 . V_68 ;
V_64 -> V_69 += V_66 . V_69 ;
V_64 -> V_70 += V_66 . V_70 ;
V_64 -> V_71 += V_66 . V_71 ;
}
}
int F_72 ( struct V_5 * V_6 , struct V_59 * V_60 )
{
struct V_63 V_66 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
F_71 ( V_6 , & V_66 ) ;
F_68 ( V_6 , & V_66 ) ;
F_73 ( V_60 , L_20 ,
F_74 ( V_6 ) , V_66 . V_70 , V_66 . V_71 , V_6 -> V_4 ,
V_66 . V_72 , ( 1 << V_66 . V_73 ) ) ;
F_73 ( V_60 , L_21 ,
V_66 . V_74 , V_66 . V_75 , V_66 . V_76 ) ;
F_73 ( V_60 , L_22 ,
V_66 . V_67 , V_66 . V_68 , V_66 . V_69 ) ;
F_75 ( V_60 , V_6 ) ;
F_62 ( V_60 , '\n' ) ;
return 0 ;
}
static int F_76 ( struct V_59 * V_60 , void * V_62 )
{
struct V_5 * V_6 = F_77 ( V_62 , struct V_5 , V_31 ) ;
if ( ! F_11 ( V_6 ) )
return 0 ;
return F_72 ( V_6 , V_60 ) ;
}
static int F_78 ( struct V_77 * V_77 , struct V_78 * V_78 )
{
return F_79 ( V_78 , & V_79 ) ;
}
static int T_2 F_80 ( void )
{
F_81 ( L_23 , V_80 , NULL ,
& V_81 ) ;
return 0 ;
}
