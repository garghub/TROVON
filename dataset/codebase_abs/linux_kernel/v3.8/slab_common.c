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
void F_43 ( struct V_39 * V_40 )
{
#ifdef F_44
F_45 ( V_40 , L_9 ) ;
#else
F_45 ( V_40 , L_10 ) ;
#endif
F_45 ( V_40 , L_11
L_12 ) ;
F_45 ( V_40 , L_13 ) ;
F_45 ( V_40 , L_14 ) ;
#ifdef F_44
F_45 ( V_40 , L_15
L_16 ) ;
F_45 ( V_40 , L_17 ) ;
#endif
F_46 ( V_40 , '\n' ) ;
}
static void * F_47 ( struct V_39 * V_40 , T_3 * V_41 )
{
T_3 V_42 = * V_41 ;
F_9 ( & V_15 ) ;
if ( ! V_42 )
F_43 ( V_40 ) ;
return F_48 ( & V_30 , * V_41 ) ;
}
static void * F_49 ( struct V_39 * V_40 , void * V_43 , T_3 * V_41 )
{
return F_50 ( V_43 , & V_30 , V_41 ) ;
}
static void F_51 ( struct V_39 * V_40 , void * V_43 )
{
F_13 ( & V_15 ) ;
}
static void
F_52 ( struct V_5 * V_6 , struct V_44 * V_45 )
{
struct V_5 * V_46 ;
struct V_44 V_47 ;
int V_48 ;
if ( ! F_10 ( V_6 ) )
return;
F_53 (i) {
V_46 = F_54 ( V_6 , V_48 ) ;
if ( ! V_46 )
continue;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
F_55 ( V_46 , & V_47 ) ;
V_45 -> V_49 += V_47 . V_49 ;
V_45 -> V_50 += V_47 . V_50 ;
V_45 -> V_51 += V_47 . V_51 ;
V_45 -> V_52 += V_47 . V_52 ;
V_45 -> V_53 += V_47 . V_53 ;
}
}
int F_56 ( struct V_5 * V_6 , struct V_39 * V_40 )
{
struct V_44 V_47 ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
F_55 ( V_6 , & V_47 ) ;
F_52 ( V_6 , & V_47 ) ;
F_57 ( V_40 , L_18 ,
F_58 ( V_6 ) , V_47 . V_52 , V_47 . V_53 , V_6 -> V_4 ,
V_47 . V_54 , ( 1 << V_47 . V_55 ) ) ;
F_57 ( V_40 , L_19 ,
V_47 . V_56 , V_47 . V_57 , V_47 . V_58 ) ;
F_57 ( V_40 , L_20 ,
V_47 . V_49 , V_47 . V_50 , V_47 . V_51 ) ;
F_59 ( V_40 , V_6 ) ;
F_46 ( V_40 , '\n' ) ;
return 0 ;
}
static int F_60 ( struct V_39 * V_40 , void * V_43 )
{
struct V_5 * V_6 = F_61 ( V_43 , struct V_5 , V_29 ) ;
if ( ! F_10 ( V_6 ) )
return 0 ;
return F_56 ( V_6 , V_40 ) ;
}
static int F_62 ( struct V_59 * V_59 , struct V_60 * V_60 )
{
return F_63 ( V_60 , & V_61 ) ;
}
static int T_2 F_64 ( void )
{
F_65 ( L_21 , V_62 , NULL , & V_63 ) ;
return 0 ;
}
