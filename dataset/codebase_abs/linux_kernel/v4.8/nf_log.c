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
const struct V_1 * log ;
int V_4 ;
F_4 ( & V_11 ) ;
for ( V_4 = 0 ; V_4 < V_14 ; V_4 ++ ) {
log = F_2 ( V_6 [ V_4 ] [ V_9 -> type ] ) ;
if ( log == V_9 )
F_8 ( V_6 [ V_4 ] [ V_9 -> type ] , NULL ) ;
}
F_6 ( & V_11 ) ;
F_9 () ;
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
if ( V_2 == V_22 ) {
V_15 = F_18 ( V_23 , type ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_18 ( V_24 , type ) ;
if ( V_15 < 0 ) {
F_19 ( V_23 , type ) ;
return V_15 ;
}
return 0 ;
}
if ( F_12 ( V_6 [ V_2 ] [ type ] ) == NULL )
F_17 ( L_1 , V_2 , type ) ;
F_20 () ;
V_9 = F_21 ( V_6 [ V_2 ] [ type ] ) ;
if ( V_9 == NULL )
goto V_25;
if ( F_22 ( V_9 -> V_26 ) )
V_15 = 0 ;
V_25:
F_23 () ;
return V_15 ;
}
void F_19 ( int V_2 , enum V_21 type )
{
struct V_1 * V_9 ;
if ( V_2 == V_22 ) {
F_19 ( V_23 , type ) ;
F_19 ( V_24 , type ) ;
return;
}
F_24 ( V_6 [ V_2 ] [ type ] == NULL ) ;
F_20 () ;
V_9 = F_21 ( V_6 [ V_2 ] [ type ] ) ;
F_25 ( V_9 -> V_26 ) ;
F_23 () ;
}
void F_26 ( struct V_8 * V_8 ,
T_1 V_2 ,
unsigned int V_27 ,
const struct V_28 * V_29 ,
const struct V_30 * V_31 ,
const struct V_30 * V_25 ,
const struct V_32 * V_33 ,
const char * V_34 , ... )
{
T_2 args ;
char V_35 [ V_36 ] ;
const struct V_1 * V_9 ;
F_20 () ;
if ( V_33 != NULL )
V_9 = F_21 ( V_6 [ V_2 ] [ V_33 -> type ] ) ;
else
V_9 = F_21 ( V_8 -> V_12 . V_13 [ V_2 ] ) ;
if ( V_9 ) {
va_start ( args , V_34 ) ;
vsnprintf ( V_35 , sizeof( V_35 ) , V_34 , args ) ;
va_end ( args ) ;
V_9 -> V_37 ( V_8 , V_2 , V_27 , V_29 , V_31 , V_25 , V_33 , V_35 ) ;
}
F_23 () ;
}
void F_27 ( struct V_8 * V_8 ,
T_1 V_2 ,
unsigned int V_27 ,
const struct V_28 * V_29 ,
const struct V_30 * V_31 ,
const struct V_30 * V_25 ,
const struct V_32 * V_33 , const char * V_34 , ... )
{
T_2 args ;
char V_35 [ V_36 ] ;
const struct V_1 * V_9 ;
F_20 () ;
V_9 = F_21 ( V_8 -> V_12 . V_13 [ V_2 ] ) ;
if ( V_9 ) {
va_start ( args , V_34 ) ;
vsnprintf ( V_35 , sizeof( V_35 ) , V_34 , args ) ;
va_end ( args ) ;
V_9 -> V_37 ( V_8 , V_2 , V_27 , V_29 , V_31 , V_25 , V_33 , V_35 ) ;
}
F_23 () ;
}
int F_28 ( struct V_38 * V_39 , const char * V_40 , ... )
{
T_2 args ;
int V_41 ;
if ( F_29 ( V_39 -> V_42 < V_43 ) ) {
va_start ( args , V_40 ) ;
V_41 = vsnprintf ( V_39 -> V_44 + V_39 -> V_42 , V_43 - V_39 -> V_42 , V_40 , args ) ;
va_end ( args ) ;
if ( F_29 ( V_39 -> V_42 + V_41 < V_43 ) ) {
V_39 -> V_42 += V_41 ;
return 0 ;
}
}
V_39 -> V_42 = V_43 ;
F_30 (KERN_ERR KBUILD_MODNAME L_2 ) ;
return - 1 ;
}
struct V_38 * F_31 ( void )
{
struct V_38 * V_39 = F_32 ( sizeof( * V_39 ) , V_45 ) ;
if ( F_33 ( ! V_39 ) ) {
F_34 () ;
do {
V_39 = F_35 ( & V_46 , NULL ) ;
} while ( ! V_39 );
}
V_39 -> V_42 = 0 ;
return V_39 ;
}
void F_36 ( struct V_38 * V_39 )
{
V_39 -> V_44 [ V_39 -> V_42 ] = 0 ;
F_37 ( L_3 , V_39 -> V_44 ) ;
if ( F_29 ( V_39 != & V_47 ) )
F_38 ( V_39 ) ;
else {
V_46 = V_39 ;
F_39 () ;
}
}
static void * F_40 ( struct V_48 * V_49 , T_3 * V_50 )
{
struct V_8 * V_8 = F_41 ( V_49 ) ;
F_4 ( & V_11 ) ;
if ( * V_50 >= F_11 ( V_8 -> V_12 . V_13 ) )
return NULL ;
return V_50 ;
}
static void * F_42 ( struct V_48 * V_51 , void * V_52 , T_3 * V_50 )
{
struct V_8 * V_8 = F_41 ( V_51 ) ;
( * V_50 ) ++ ;
if ( * V_50 >= F_11 ( V_8 -> V_12 . V_13 ) )
return NULL ;
return V_50 ;
}
static void F_43 ( struct V_48 * V_51 , void * V_52 )
{
F_6 ( & V_11 ) ;
}
static int F_44 ( struct V_48 * V_51 , void * V_52 )
{
T_3 * V_50 = V_52 ;
const struct V_1 * V_9 ;
int V_4 ;
struct V_8 * V_8 = F_41 ( V_51 ) ;
V_9 = F_2 ( V_8 -> V_12 . V_13 [ * V_50 ] ) ;
if ( ! V_9 )
F_45 ( V_51 , L_4 , * V_50 ) ;
else
F_45 ( V_51 , L_5 , * V_50 , V_9 -> V_7 ) ;
if ( F_46 ( V_51 ) )
return - V_53 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
if ( V_6 [ * V_50 ] [ V_4 ] == NULL )
continue;
V_9 = F_2 ( V_6 [ * V_50 ] [ V_4 ] ) ;
F_45 ( V_51 , L_6 , V_9 -> V_7 ) ;
if ( V_4 == 0 && V_6 [ * V_50 ] [ V_4 + 1 ] != NULL )
F_45 ( V_51 , L_7 ) ;
if ( F_46 ( V_51 ) )
return - V_53 ;
}
F_45 ( V_51 , L_8 ) ;
if ( F_46 ( V_51 ) )
return - V_53 ;
return 0 ;
}
static int F_47 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_48 ( V_54 , V_55 , & V_56 ,
sizeof( struct V_57 ) ) ;
}
static int F_49 ( struct V_58 * V_59 , int V_60 ,
void T_4 * V_61 , T_5 * V_62 , T_3 * V_63 )
{
const struct V_1 * V_9 ;
char V_44 [ V_64 ] ;
int V_65 = 0 ;
int V_66 = ( unsigned long ) V_59 -> V_67 ;
struct V_8 * V_8 = V_68 -> V_69 -> V_70 ;
if ( V_60 ) {
struct V_58 V_71 = * V_59 ;
V_71 . V_72 = V_44 ;
V_65 = F_50 ( & V_71 , V_60 , V_61 , V_62 , V_63 ) ;
if ( V_65 )
return V_65 ;
if ( ! strcmp ( V_44 , L_9 ) ) {
F_15 ( V_8 , V_66 ) ;
return 0 ;
}
F_4 ( & V_11 ) ;
V_9 = F_1 ( V_66 , V_44 ) ;
if ( V_9 == NULL ) {
F_6 ( & V_11 ) ;
return - V_20 ;
}
F_5 ( V_8 -> V_12 . V_13 [ V_66 ] , V_9 ) ;
F_6 ( & V_11 ) ;
} else {
F_4 ( & V_11 ) ;
V_9 = F_2 ( V_8 -> V_12 . V_13 [ V_66 ] ) ;
if ( ! V_9 )
V_59 -> V_72 = L_9 ;
else
V_59 -> V_72 = V_9 -> V_7 ;
V_65 = F_50 ( V_59 , V_60 , V_61 , V_62 , V_63 ) ;
F_6 ( & V_11 ) ;
}
return V_65 ;
}
static int F_51 ( struct V_8 * V_8 )
{
int V_4 ;
struct V_58 * V_59 ;
V_59 = V_73 ;
if ( ! F_52 ( V_8 , & V_16 ) ) {
V_59 = F_53 ( V_73 ,
sizeof( V_73 ) ,
V_74 ) ;
if ( ! V_59 )
goto V_75;
} else {
for ( V_4 = V_10 ; V_4 < V_14 ; V_4 ++ ) {
snprintf ( V_76 [ V_4 ] ,
3 , L_10 , V_4 ) ;
V_73 [ V_4 ] . V_77 =
V_76 [ V_4 ] ;
V_73 [ V_4 ] . V_72 = NULL ;
V_73 [ V_4 ] . V_78 = V_64 ;
V_73 [ V_4 ] . V_79 = 0644 ;
V_73 [ V_4 ] . V_80 =
F_49 ;
V_73 [ V_4 ] . V_67 =
( void * ) ( unsigned long ) V_4 ;
}
}
V_8 -> V_12 . V_81 = F_54 ( V_8 ,
L_11 ,
V_59 ) ;
if ( ! V_8 -> V_12 . V_81 )
goto V_82;
return 0 ;
V_82:
if ( ! F_52 ( V_8 , & V_16 ) )
F_38 ( V_59 ) ;
V_75:
return - V_83 ;
}
static void F_55 ( struct V_8 * V_8 )
{
struct V_58 * V_59 ;
V_59 = V_8 -> V_12 . V_81 -> V_84 ;
F_56 ( V_8 -> V_12 . V_81 ) ;
if ( ! F_52 ( V_8 , & V_16 ) )
F_38 ( V_59 ) ;
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
int V_15 = - V_83 ;
#ifdef F_58
if ( ! F_59 ( L_12 , V_85 ,
V_8 -> V_12 . V_86 , & V_87 ) )
return V_15 ;
#endif
V_15 = F_51 ( V_8 ) ;
if ( V_15 < 0 )
goto V_88;
return 0 ;
V_88:
#ifdef F_58
F_60 ( L_12 , V_8 -> V_12 . V_86 ) ;
#endif
return V_15 ;
}
static void T_7 F_61 ( struct V_8 * V_8 )
{
F_55 ( V_8 ) ;
#ifdef F_58
F_60 ( L_12 , V_8 -> V_12 . V_86 ) ;
#endif
}
int T_8 F_62 ( void )
{
return F_63 ( & V_89 ) ;
}
