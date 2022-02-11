static struct V_1 * F_1 ( int V_2 , const char * V_3 )
{
struct V_1 * log ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
if ( V_6 [ V_2 ] [ V_4 ] == NULL )
continue;
log = F_2 ( V_6 [ V_2 ] [ V_4 ] ,
F_3 ( & V_7 ) ) ;
if ( ! strncasecmp ( V_3 , log -> V_8 , strlen ( log -> V_8 ) ) )
return log ;
}
return NULL ;
}
void F_4 ( struct V_9 * V_9 , T_1 V_2 , const struct V_1 * V_10 )
{
const struct V_1 * log ;
if ( V_2 == V_11 )
return;
F_5 ( & V_7 ) ;
log = F_2 ( V_9 -> V_12 . V_13 [ V_2 ] ,
F_3 ( & V_7 ) ) ;
if ( log == NULL )
F_6 ( V_9 -> V_12 . V_13 [ V_2 ] , V_10 ) ;
F_7 ( & V_7 ) ;
}
void F_8 ( struct V_9 * V_9 , const struct V_1 * V_10 )
{
int V_4 ;
const struct V_1 * log ;
F_5 ( & V_7 ) ;
for ( V_4 = 0 ; V_4 < V_14 ; V_4 ++ ) {
log = F_2 ( V_9 -> V_12 . V_13 [ V_4 ] ,
F_3 ( & V_7 ) ) ;
if ( log == V_10 )
F_9 ( V_9 -> V_12 . V_13 [ V_4 ] , NULL ) ;
}
F_7 ( & V_7 ) ;
F_10 () ;
}
int F_11 ( T_1 V_2 , struct V_1 * V_10 )
{
int V_4 ;
if ( V_2 >= F_12 ( V_15 . V_12 . V_13 ) )
return - V_16 ;
F_5 ( & V_7 ) ;
if ( V_2 == V_11 ) {
for ( V_4 = V_11 ; V_4 < V_14 ; V_4 ++ )
F_6 ( V_6 [ V_4 ] [ V_10 -> type ] , V_10 ) ;
} else {
F_6 ( V_6 [ V_2 ] [ V_10 -> type ] , V_10 ) ;
}
F_7 ( & V_7 ) ;
return 0 ;
}
void F_13 ( struct V_1 * V_10 )
{
int V_4 ;
F_5 ( & V_7 ) ;
for ( V_4 = 0 ; V_4 < V_14 ; V_4 ++ )
F_9 ( V_6 [ V_4 ] [ V_10 -> type ] , NULL ) ;
F_7 ( & V_7 ) ;
}
int F_14 ( struct V_9 * V_9 , T_1 V_2 ,
const struct V_1 * V_10 )
{
if ( V_2 >= F_12 ( V_9 -> V_12 . V_13 ) )
return - V_16 ;
F_5 ( & V_7 ) ;
if ( F_1 ( V_2 , V_10 -> V_8 ) == NULL ) {
F_7 ( & V_7 ) ;
return - V_17 ;
}
F_6 ( V_9 -> V_12 . V_13 [ V_2 ] , V_10 ) ;
F_7 ( & V_7 ) ;
return 0 ;
}
void F_15 ( struct V_9 * V_9 , T_1 V_2 )
{
if ( V_2 >= F_12 ( V_9 -> V_12 . V_13 ) )
return;
F_5 ( & V_7 ) ;
F_9 ( V_9 -> V_12 . V_13 [ V_2 ] , NULL ) ;
F_7 ( & V_7 ) ;
}
void F_16 ( int V_2 , enum V_18 type )
{
if ( V_6 [ V_2 ] [ type ] == NULL )
F_17 ( L_1 , V_2 , type ) ;
}
int F_18 ( int V_2 , enum V_18 type )
{
struct V_1 * V_10 ;
int V_19 = - V_17 ;
V_10 = V_6 [ V_2 ] [ type ] ;
if ( V_10 == NULL )
F_17 ( L_1 , V_2 , type ) ;
F_19 () ;
V_10 = F_20 ( V_6 [ V_2 ] [ type ] ) ;
if ( V_10 == NULL )
goto V_20;
if ( V_10 && F_21 ( V_10 -> V_21 ) )
V_19 = 0 ;
V_20:
F_22 () ;
return V_19 ;
}
void F_23 ( int V_2 , enum V_18 type )
{
struct V_1 * V_10 ;
F_24 ( V_6 [ V_2 ] [ type ] == NULL ) ;
F_19 () ;
V_10 = F_20 ( V_6 [ V_2 ] [ type ] ) ;
F_25 ( V_10 -> V_21 ) ;
F_22 () ;
}
void F_26 ( struct V_9 * V_9 ,
T_1 V_2 ,
unsigned int V_22 ,
const struct V_23 * V_24 ,
const struct V_25 * V_26 ,
const struct V_25 * V_20 ,
const struct V_27 * V_28 ,
const char * V_29 , ... )
{
T_2 args ;
char V_30 [ V_31 ] ;
const struct V_1 * V_10 ;
F_19 () ;
if ( V_28 != NULL )
V_10 = F_20 ( V_6 [ V_2 ] [ V_28 -> type ] ) ;
else
V_10 = F_20 ( V_9 -> V_12 . V_13 [ V_2 ] ) ;
if ( V_10 ) {
va_start ( args , V_29 ) ;
vsnprintf ( V_30 , sizeof( V_30 ) , V_29 , args ) ;
va_end ( args ) ;
V_10 -> V_32 ( V_9 , V_2 , V_22 , V_24 , V_26 , V_20 , V_28 , V_30 ) ;
}
F_22 () ;
}
int F_27 ( struct V_33 * V_34 , const char * V_35 , ... )
{
T_2 args ;
int V_36 ;
if ( F_28 ( V_34 -> V_37 < V_38 ) ) {
va_start ( args , V_35 ) ;
V_36 = vsnprintf ( V_34 -> V_39 + V_34 -> V_37 , V_38 - V_34 -> V_37 , V_35 , args ) ;
va_end ( args ) ;
if ( F_28 ( V_34 -> V_37 + V_36 < V_38 ) ) {
V_34 -> V_37 += V_36 ;
return 0 ;
}
}
V_34 -> V_37 = V_38 ;
F_29 (KERN_ERR KBUILD_MODNAME L_2 ) ;
return - 1 ;
}
struct V_33 * F_30 ( void )
{
struct V_33 * V_34 = F_31 ( sizeof( * V_34 ) , V_40 ) ;
if ( F_32 ( ! V_34 ) ) {
F_33 () ;
do {
V_34 = F_34 ( & V_41 , NULL ) ;
} while ( ! V_34 );
}
V_34 -> V_37 = 0 ;
return V_34 ;
}
void F_35 ( struct V_33 * V_34 )
{
V_34 -> V_39 [ V_34 -> V_37 ] = 0 ;
F_36 ( L_3 , V_34 -> V_39 ) ;
if ( F_28 ( V_34 != & V_42 ) )
F_37 ( V_34 ) ;
else {
V_41 = V_34 ;
F_38 () ;
}
}
static void * F_39 ( struct V_43 * V_44 , T_3 * V_45 )
{
struct V_9 * V_9 = F_40 ( V_44 ) ;
F_5 ( & V_7 ) ;
if ( * V_45 >= F_12 ( V_9 -> V_12 . V_13 ) )
return NULL ;
return V_45 ;
}
static void * F_41 ( struct V_43 * V_46 , void * V_47 , T_3 * V_45 )
{
struct V_9 * V_9 = F_40 ( V_46 ) ;
( * V_45 ) ++ ;
if ( * V_45 >= F_12 ( V_9 -> V_12 . V_13 ) )
return NULL ;
return V_45 ;
}
static void F_42 ( struct V_43 * V_46 , void * V_47 )
{
F_7 ( & V_7 ) ;
}
static int F_43 ( struct V_43 * V_46 , void * V_47 )
{
T_3 * V_45 = V_47 ;
const struct V_1 * V_10 ;
int V_4 , V_19 ;
struct V_9 * V_9 = F_40 ( V_46 ) ;
V_10 = F_2 ( V_9 -> V_12 . V_13 [ * V_45 ] ,
F_3 ( & V_7 ) ) ;
if ( ! V_10 )
V_19 = F_44 ( V_46 , L_4 , * V_45 ) ;
else
V_19 = F_44 ( V_46 , L_5 , * V_45 , V_10 -> V_8 ) ;
if ( V_19 < 0 )
return V_19 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
if ( V_6 [ * V_45 ] [ V_4 ] == NULL )
continue;
V_10 = F_2 ( V_6 [ * V_45 ] [ V_4 ] ,
F_3 ( & V_7 ) ) ;
V_19 = F_44 ( V_46 , L_6 , V_10 -> V_8 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_4 == 0 && V_6 [ * V_45 ] [ V_4 + 1 ] != NULL ) {
V_19 = F_44 ( V_46 , L_7 ) ;
if ( V_19 < 0 )
return V_19 ;
}
}
return F_44 ( V_46 , L_8 ) ;
}
static int F_45 ( struct V_48 * V_48 , struct V_49 * V_49 )
{
return F_46 ( V_48 , V_49 , & V_50 ,
sizeof( struct V_51 ) ) ;
}
static int F_47 ( struct V_52 * V_53 , int V_54 ,
void T_4 * V_55 , T_5 * V_56 , T_3 * V_57 )
{
const struct V_1 * V_10 ;
char V_39 [ V_58 ] ;
T_5 V_59 = * V_56 ;
int V_60 = 0 ;
int V_61 = ( unsigned long ) V_53 -> V_62 ;
struct V_9 * V_9 = V_63 -> V_64 -> V_65 ;
if ( V_54 ) {
if ( V_59 > sizeof( V_39 ) )
V_59 = sizeof( V_39 ) ;
if ( F_48 ( V_39 , V_55 , V_59 ) )
return - V_66 ;
if ( ! strcmp ( V_39 , L_9 ) ) {
F_15 ( V_9 , V_61 ) ;
return 0 ;
}
F_5 ( & V_7 ) ;
V_10 = F_1 ( V_61 , V_39 ) ;
if ( V_10 == NULL ) {
F_7 ( & V_7 ) ;
return - V_17 ;
}
F_6 ( V_9 -> V_12 . V_13 [ V_61 ] , V_10 ) ;
F_7 ( & V_7 ) ;
} else {
F_5 ( & V_7 ) ;
V_10 = F_2 ( V_9 -> V_12 . V_13 [ V_61 ] ,
F_3 ( & V_7 ) ) ;
if ( ! V_10 )
V_53 -> V_67 = L_9 ;
else
V_53 -> V_67 = V_10 -> V_8 ;
V_60 = F_49 ( V_53 , V_54 , V_55 , V_56 , V_57 ) ;
F_7 ( & V_7 ) ;
}
return V_60 ;
}
static int F_50 ( struct V_9 * V_9 )
{
int V_4 ;
struct V_52 * V_53 ;
V_53 = V_68 ;
if ( ! F_51 ( V_9 , & V_15 ) ) {
V_53 = F_52 ( V_68 ,
sizeof( V_68 ) ,
V_69 ) ;
if ( ! V_53 )
goto V_70;
} else {
for ( V_4 = V_11 ; V_4 < V_14 ; V_4 ++ ) {
snprintf ( V_71 [ V_4 ] ,
3 , L_10 , V_4 ) ;
V_68 [ V_4 ] . V_72 =
V_71 [ V_4 ] ;
V_68 [ V_4 ] . V_67 = NULL ;
V_68 [ V_4 ] . V_73 =
V_58 * sizeof( char ) ;
V_68 [ V_4 ] . V_74 = 0644 ;
V_68 [ V_4 ] . V_75 =
F_47 ;
V_68 [ V_4 ] . V_62 =
( void * ) ( unsigned long ) V_4 ;
}
}
V_9 -> V_12 . V_76 = F_53 ( V_9 ,
L_11 ,
V_53 ) ;
if ( ! V_9 -> V_12 . V_76 )
goto V_77;
return 0 ;
V_77:
if ( ! F_51 ( V_9 , & V_15 ) )
F_37 ( V_53 ) ;
V_70:
return - V_78 ;
}
static void F_54 ( struct V_9 * V_9 )
{
struct V_52 * V_53 ;
V_53 = V_9 -> V_12 . V_76 -> V_79 ;
F_55 ( V_9 -> V_12 . V_76 ) ;
if ( ! F_51 ( V_9 , & V_15 ) )
F_37 ( V_53 ) ;
}
static int F_50 ( struct V_9 * V_9 )
{
return 0 ;
}
static void F_54 ( struct V_9 * V_9 )
{
}
static int T_6 F_56 ( struct V_9 * V_9 )
{
int V_19 = - V_78 ;
#ifdef F_57
if ( ! F_58 ( L_12 , V_80 ,
V_9 -> V_12 . V_81 , & V_82 ) )
return V_19 ;
#endif
V_19 = F_50 ( V_9 ) ;
if ( V_19 < 0 )
goto V_83;
return 0 ;
V_83:
#ifdef F_57
F_59 ( L_12 , V_9 -> V_12 . V_81 ) ;
#endif
return V_19 ;
}
static void T_7 F_60 ( struct V_9 * V_9 )
{
F_54 ( V_9 ) ;
#ifdef F_57
F_59 ( L_12 , V_9 -> V_12 . V_81 ) ;
#endif
}
int T_8 F_61 ( void )
{
return F_62 ( & V_84 ) ;
}
