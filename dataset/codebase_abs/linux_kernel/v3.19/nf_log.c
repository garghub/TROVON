static struct V_1 * F_1 ( int V_2 , const char * V_3 )
{
struct V_1 * log ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
if ( V_6 [ V_2 ] [ V_4 ] == NULL )
continue;
log = F_2 ( V_6 [ V_2 ] [ V_4 ] ) ;
if ( ! strncasecmp ( V_3 , log -> V_7 , strlen ( log -> V_7 ) ) )
return log ;
}
return NULL ;
}
void F_3 ( struct V_8 * V_8 , T_1 V_2 , const struct V_1 * V_9 )
{
const struct V_1 * log ;
if ( V_2 == V_10 )
return;
F_4 ( & V_11 ) ;
log = F_2 ( V_8 -> V_12 . V_13 [ V_2 ] ) ;
if ( log == NULL )
F_5 ( V_8 -> V_12 . V_13 [ V_2 ] , V_9 ) ;
F_6 ( & V_11 ) ;
}
void F_7 ( struct V_8 * V_8 , const struct V_1 * V_9 )
{
int V_4 ;
const struct V_1 * log ;
F_4 ( & V_11 ) ;
for ( V_4 = 0 ; V_4 < V_14 ; V_4 ++ ) {
log = F_2 ( V_8 -> V_12 . V_13 [ V_4 ] ) ;
if ( log == V_9 )
F_8 ( V_8 -> V_12 . V_13 [ V_4 ] , NULL ) ;
}
F_6 ( & V_11 ) ;
F_9 () ;
}
int F_10 ( T_1 V_2 , struct V_1 * V_9 )
{
int V_4 ;
int V_15 = 0 ;
if ( V_2 >= F_11 ( V_16 . V_12 . V_13 ) )
return - V_17 ;
F_4 ( & V_11 ) ;
if ( V_2 == V_10 ) {
for ( V_4 = V_10 ; V_4 < V_14 ; V_4 ++ ) {
if ( F_12 ( V_6 [ V_4 ] [ V_9 -> type ] ) ) {
V_15 = - V_18 ;
goto V_19;
}
}
for ( V_4 = V_10 ; V_4 < V_14 ; V_4 ++ )
F_5 ( V_6 [ V_4 ] [ V_9 -> type ] , V_9 ) ;
} else {
if ( F_12 ( V_6 [ V_2 ] [ V_9 -> type ] ) ) {
V_15 = - V_18 ;
goto V_19;
}
F_5 ( V_6 [ V_2 ] [ V_9 -> type ] , V_9 ) ;
}
V_19:
F_6 ( & V_11 ) ;
return V_15 ;
}
void F_13 ( struct V_1 * V_9 )
{
int V_4 ;
F_4 ( & V_11 ) ;
for ( V_4 = 0 ; V_4 < V_14 ; V_4 ++ )
F_8 ( V_6 [ V_4 ] [ V_9 -> type ] , NULL ) ;
F_6 ( & V_11 ) ;
}
int F_14 ( struct V_8 * V_8 , T_1 V_2 ,
const struct V_1 * V_9 )
{
if ( V_2 >= F_11 ( V_8 -> V_12 . V_13 ) )
return - V_17 ;
F_4 ( & V_11 ) ;
if ( F_1 ( V_2 , V_9 -> V_7 ) == NULL ) {
F_6 ( & V_11 ) ;
return - V_20 ;
}
F_5 ( V_8 -> V_12 . V_13 [ V_2 ] , V_9 ) ;
F_6 ( & V_11 ) ;
return 0 ;
}
void F_15 ( struct V_8 * V_8 , T_1 V_2 )
{
if ( V_2 >= F_11 ( V_8 -> V_12 . V_13 ) )
return;
F_4 ( & V_11 ) ;
F_8 ( V_8 -> V_12 . V_13 [ V_2 ] , NULL ) ;
F_6 ( & V_11 ) ;
}
void F_16 ( int V_2 , enum V_21 type )
{
if ( V_6 [ V_2 ] [ type ] == NULL )
F_17 ( L_1 , V_2 , type ) ;
}
int F_18 ( int V_2 , enum V_21 type )
{
struct V_1 * V_9 ;
int V_15 = - V_20 ;
if ( F_12 ( V_6 [ V_2 ] [ type ] ) == NULL )
F_17 ( L_1 , V_2 , type ) ;
F_19 () ;
V_9 = F_20 ( V_6 [ V_2 ] [ type ] ) ;
if ( V_9 == NULL )
goto V_22;
if ( V_9 && F_21 ( V_9 -> V_23 ) )
V_15 = 0 ;
V_22:
F_22 () ;
return V_15 ;
}
void F_23 ( int V_2 , enum V_21 type )
{
struct V_1 * V_9 ;
F_24 ( V_6 [ V_2 ] [ type ] == NULL ) ;
F_19 () ;
V_9 = F_20 ( V_6 [ V_2 ] [ type ] ) ;
F_25 ( V_9 -> V_23 ) ;
F_22 () ;
}
void F_26 ( struct V_8 * V_8 ,
T_1 V_2 ,
unsigned int V_24 ,
const struct V_25 * V_26 ,
const struct V_27 * V_28 ,
const struct V_27 * V_22 ,
const struct V_29 * V_30 ,
const char * V_31 , ... )
{
T_2 args ;
char V_32 [ V_33 ] ;
const struct V_1 * V_9 ;
F_19 () ;
if ( V_30 != NULL )
V_9 = F_20 ( V_6 [ V_2 ] [ V_30 -> type ] ) ;
else
V_9 = F_20 ( V_8 -> V_12 . V_13 [ V_2 ] ) ;
if ( V_9 ) {
va_start ( args , V_31 ) ;
vsnprintf ( V_32 , sizeof( V_32 ) , V_31 , args ) ;
va_end ( args ) ;
V_9 -> V_34 ( V_8 , V_2 , V_24 , V_26 , V_28 , V_22 , V_30 , V_32 ) ;
}
F_22 () ;
}
int F_27 ( struct V_35 * V_36 , const char * V_37 , ... )
{
T_2 args ;
int V_38 ;
if ( F_28 ( V_36 -> V_39 < V_40 ) ) {
va_start ( args , V_37 ) ;
V_38 = vsnprintf ( V_36 -> V_41 + V_36 -> V_39 , V_40 - V_36 -> V_39 , V_37 , args ) ;
va_end ( args ) ;
if ( F_28 ( V_36 -> V_39 + V_38 < V_40 ) ) {
V_36 -> V_39 += V_38 ;
return 0 ;
}
}
V_36 -> V_39 = V_40 ;
F_29 (KERN_ERR KBUILD_MODNAME L_2 ) ;
return - 1 ;
}
struct V_35 * F_30 ( void )
{
struct V_35 * V_36 = F_31 ( sizeof( * V_36 ) , V_42 ) ;
if ( F_32 ( ! V_36 ) ) {
F_33 () ;
do {
V_36 = F_34 ( & V_43 , NULL ) ;
} while ( ! V_36 );
}
V_36 -> V_39 = 0 ;
return V_36 ;
}
void F_35 ( struct V_35 * V_36 )
{
V_36 -> V_41 [ V_36 -> V_39 ] = 0 ;
F_36 ( L_3 , V_36 -> V_41 ) ;
if ( F_28 ( V_36 != & V_44 ) )
F_37 ( V_36 ) ;
else {
V_43 = V_36 ;
F_38 () ;
}
}
static void * F_39 ( struct V_45 * V_46 , T_3 * V_47 )
{
struct V_8 * V_8 = F_40 ( V_46 ) ;
F_4 ( & V_11 ) ;
if ( * V_47 >= F_11 ( V_8 -> V_12 . V_13 ) )
return NULL ;
return V_47 ;
}
static void * F_41 ( struct V_45 * V_48 , void * V_49 , T_3 * V_47 )
{
struct V_8 * V_8 = F_40 ( V_48 ) ;
( * V_47 ) ++ ;
if ( * V_47 >= F_11 ( V_8 -> V_12 . V_13 ) )
return NULL ;
return V_47 ;
}
static void F_42 ( struct V_45 * V_48 , void * V_49 )
{
F_6 ( & V_11 ) ;
}
static int F_43 ( struct V_45 * V_48 , void * V_49 )
{
T_3 * V_47 = V_49 ;
const struct V_1 * V_9 ;
int V_4 ;
struct V_8 * V_8 = F_40 ( V_48 ) ;
V_9 = F_2 ( V_8 -> V_12 . V_13 [ * V_47 ] ) ;
if ( ! V_9 )
F_44 ( V_48 , L_4 , * V_47 ) ;
else
F_44 ( V_48 , L_5 , * V_47 , V_9 -> V_7 ) ;
if ( F_45 ( V_48 ) )
return - V_50 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
if ( V_6 [ * V_47 ] [ V_4 ] == NULL )
continue;
V_9 = F_2 ( V_6 [ * V_47 ] [ V_4 ] ) ;
F_44 ( V_48 , L_6 , V_9 -> V_7 ) ;
if ( V_4 == 0 && V_6 [ * V_47 ] [ V_4 + 1 ] != NULL )
F_44 ( V_48 , L_7 ) ;
if ( F_45 ( V_48 ) )
return - V_50 ;
}
F_44 ( V_48 , L_8 ) ;
if ( F_45 ( V_48 ) )
return - V_50 ;
return 0 ;
}
static int F_46 ( struct V_51 * V_51 , struct V_52 * V_52 )
{
return F_47 ( V_51 , V_52 , & V_53 ,
sizeof( struct V_54 ) ) ;
}
static int F_48 ( struct V_55 * V_56 , int V_57 ,
void T_4 * V_58 , T_5 * V_59 , T_3 * V_60 )
{
const struct V_1 * V_9 ;
char V_41 [ V_61 ] ;
T_5 V_62 = * V_59 ;
int V_63 = 0 ;
int V_64 = ( unsigned long ) V_56 -> V_65 ;
struct V_8 * V_8 = V_66 -> V_67 -> V_68 ;
if ( V_57 ) {
if ( V_62 > sizeof( V_41 ) )
V_62 = sizeof( V_41 ) ;
if ( F_49 ( V_41 , V_58 , V_62 ) )
return - V_69 ;
if ( ! strcmp ( V_41 , L_9 ) ) {
F_15 ( V_8 , V_64 ) ;
return 0 ;
}
F_4 ( & V_11 ) ;
V_9 = F_1 ( V_64 , V_41 ) ;
if ( V_9 == NULL ) {
F_6 ( & V_11 ) ;
return - V_20 ;
}
F_5 ( V_8 -> V_12 . V_13 [ V_64 ] , V_9 ) ;
F_6 ( & V_11 ) ;
} else {
F_4 ( & V_11 ) ;
V_9 = F_2 ( V_8 -> V_12 . V_13 [ V_64 ] ) ;
if ( ! V_9 )
V_56 -> V_70 = L_9 ;
else
V_56 -> V_70 = V_9 -> V_7 ;
V_63 = F_50 ( V_56 , V_57 , V_58 , V_59 , V_60 ) ;
F_6 ( & V_11 ) ;
}
return V_63 ;
}
static int F_51 ( struct V_8 * V_8 )
{
int V_4 ;
struct V_55 * V_56 ;
V_56 = V_71 ;
if ( ! F_52 ( V_8 , & V_16 ) ) {
V_56 = F_53 ( V_71 ,
sizeof( V_71 ) ,
V_72 ) ;
if ( ! V_56 )
goto V_73;
} else {
for ( V_4 = V_10 ; V_4 < V_14 ; V_4 ++ ) {
snprintf ( V_74 [ V_4 ] ,
3 , L_10 , V_4 ) ;
V_71 [ V_4 ] . V_75 =
V_74 [ V_4 ] ;
V_71 [ V_4 ] . V_70 = NULL ;
V_71 [ V_4 ] . V_76 =
V_61 * sizeof( char ) ;
V_71 [ V_4 ] . V_77 = 0644 ;
V_71 [ V_4 ] . V_78 =
F_48 ;
V_71 [ V_4 ] . V_65 =
( void * ) ( unsigned long ) V_4 ;
}
}
V_8 -> V_12 . V_79 = F_54 ( V_8 ,
L_11 ,
V_56 ) ;
if ( ! V_8 -> V_12 . V_79 )
goto V_80;
return 0 ;
V_80:
if ( ! F_52 ( V_8 , & V_16 ) )
F_37 ( V_56 ) ;
V_73:
return - V_81 ;
}
static void F_55 ( struct V_8 * V_8 )
{
struct V_55 * V_56 ;
V_56 = V_8 -> V_12 . V_79 -> V_82 ;
F_56 ( V_8 -> V_12 . V_79 ) ;
if ( ! F_52 ( V_8 , & V_16 ) )
F_37 ( V_56 ) ;
}
static int F_51 ( struct V_8 * V_8 )
{
return 0 ;
}
static void F_55 ( struct V_8 * V_8 )
{
}
static int T_6 F_57 ( struct V_8 * V_8 )
{
int V_15 = - V_81 ;
#ifdef F_58
if ( ! F_59 ( L_12 , V_83 ,
V_8 -> V_12 . V_84 , & V_85 ) )
return V_15 ;
#endif
V_15 = F_51 ( V_8 ) ;
if ( V_15 < 0 )
goto V_86;
return 0 ;
V_86:
#ifdef F_58
F_60 ( L_12 , V_8 -> V_12 . V_84 ) ;
#endif
return V_15 ;
}
static void T_7 F_61 ( struct V_8 * V_8 )
{
F_55 ( V_8 ) ;
#ifdef F_58
F_60 ( L_12 , V_8 -> V_12 . V_84 ) ;
#endif
}
int T_8 F_62 ( void )
{
return F_63 ( & V_87 ) ;
}
