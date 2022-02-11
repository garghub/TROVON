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
int F_3 ( struct V_8 * V_8 , T_1 V_2 , const struct V_1 * V_9 )
{
const struct V_1 * log ;
if ( V_2 == V_10 || V_2 >= F_4 ( V_8 -> V_11 . V_12 ) )
return - V_13 ;
F_5 ( & V_14 ) ;
log = F_2 ( V_8 -> V_11 . V_12 [ V_2 ] ) ;
if ( log == NULL )
F_6 ( V_8 -> V_11 . V_12 [ V_2 ] , V_9 ) ;
F_7 ( & V_14 ) ;
return 0 ;
}
void F_8 ( struct V_8 * V_8 , const struct V_1 * V_9 )
{
int V_4 ;
const struct V_1 * log ;
F_5 ( & V_14 ) ;
for ( V_4 = 0 ; V_4 < V_15 ; V_4 ++ ) {
log = F_2 ( V_8 -> V_11 . V_12 [ V_4 ] ) ;
if ( log == V_9 )
F_9 ( V_8 -> V_11 . V_12 [ V_4 ] , NULL ) ;
}
F_7 ( & V_14 ) ;
}
int F_10 ( T_1 V_2 , struct V_1 * V_9 )
{
int V_4 ;
int V_16 = 0 ;
if ( V_2 >= F_4 ( V_17 . V_11 . V_12 ) )
return - V_18 ;
F_5 ( & V_14 ) ;
if ( V_2 == V_10 ) {
for ( V_4 = V_10 ; V_4 < V_15 ; V_4 ++ ) {
if ( F_11 ( V_6 [ V_4 ] [ V_9 -> type ] ) ) {
V_16 = - V_19 ;
goto V_20;
}
}
for ( V_4 = V_10 ; V_4 < V_15 ; V_4 ++ )
F_6 ( V_6 [ V_4 ] [ V_9 -> type ] , V_9 ) ;
} else {
if ( F_11 ( V_6 [ V_2 ] [ V_9 -> type ] ) ) {
V_16 = - V_19 ;
goto V_20;
}
F_6 ( V_6 [ V_2 ] [ V_9 -> type ] , V_9 ) ;
}
V_20:
F_7 ( & V_14 ) ;
return V_16 ;
}
void F_12 ( struct V_1 * V_9 )
{
const struct V_1 * log ;
int V_4 ;
F_5 ( & V_14 ) ;
for ( V_4 = 0 ; V_4 < V_15 ; V_4 ++ ) {
log = F_2 ( V_6 [ V_4 ] [ V_9 -> type ] ) ;
if ( log == V_9 )
F_9 ( V_6 [ V_4 ] [ V_9 -> type ] , NULL ) ;
}
F_7 ( & V_14 ) ;
F_13 () ;
}
int F_14 ( struct V_8 * V_8 , T_1 V_2 ,
const struct V_1 * V_9 )
{
if ( V_2 >= F_4 ( V_8 -> V_11 . V_12 ) )
return - V_18 ;
F_5 ( & V_14 ) ;
if ( F_1 ( V_2 , V_9 -> V_7 ) == NULL ) {
F_7 ( & V_14 ) ;
return - V_21 ;
}
F_6 ( V_8 -> V_11 . V_12 [ V_2 ] , V_9 ) ;
F_7 ( & V_14 ) ;
return 0 ;
}
void F_15 ( struct V_8 * V_8 , T_1 V_2 )
{
if ( V_2 >= F_4 ( V_8 -> V_11 . V_12 ) )
return;
F_5 ( & V_14 ) ;
F_9 ( V_8 -> V_11 . V_12 [ V_2 ] , NULL ) ;
F_7 ( & V_14 ) ;
}
void F_16 ( int V_2 , enum V_22 type )
{
if ( V_6 [ V_2 ] [ type ] == NULL )
F_17 ( L_1 , V_2 , type ) ;
}
int F_18 ( int V_2 , enum V_22 type )
{
struct V_1 * V_9 ;
int V_16 = - V_21 ;
if ( V_2 == V_23 ) {
V_16 = F_18 ( V_24 , type ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_18 ( V_25 , type ) ;
if ( V_16 < 0 ) {
F_19 ( V_24 , type ) ;
return V_16 ;
}
return 0 ;
}
if ( F_11 ( V_6 [ V_2 ] [ type ] ) == NULL )
F_17 ( L_1 , V_2 , type ) ;
F_20 () ;
V_9 = F_21 ( V_6 [ V_2 ] [ type ] ) ;
if ( V_9 == NULL )
goto V_26;
if ( F_22 ( V_9 -> V_27 ) )
V_16 = 0 ;
V_26:
F_23 () ;
return V_16 ;
}
void F_19 ( int V_2 , enum V_22 type )
{
struct V_1 * V_9 ;
if ( V_2 == V_23 ) {
F_19 ( V_24 , type ) ;
F_19 ( V_25 , type ) ;
return;
}
F_24 ( V_6 [ V_2 ] [ type ] == NULL ) ;
F_20 () ;
V_9 = F_21 ( V_6 [ V_2 ] [ type ] ) ;
F_25 ( V_9 -> V_27 ) ;
F_23 () ;
}
void F_26 ( struct V_8 * V_8 ,
T_1 V_2 ,
unsigned int V_28 ,
const struct V_29 * V_30 ,
const struct V_31 * V_32 ,
const struct V_31 * V_26 ,
const struct V_33 * V_34 ,
const char * V_35 , ... )
{
T_2 args ;
char V_36 [ V_37 ] ;
const struct V_1 * V_9 ;
F_20 () ;
if ( V_34 != NULL )
V_9 = F_21 ( V_6 [ V_2 ] [ V_34 -> type ] ) ;
else
V_9 = F_21 ( V_8 -> V_11 . V_12 [ V_2 ] ) ;
if ( V_9 ) {
va_start ( args , V_35 ) ;
vsnprintf ( V_36 , sizeof( V_36 ) , V_35 , args ) ;
va_end ( args ) ;
V_9 -> V_38 ( V_8 , V_2 , V_28 , V_30 , V_32 , V_26 , V_34 , V_36 ) ;
}
F_23 () ;
}
void F_27 ( struct V_8 * V_8 ,
T_1 V_2 ,
unsigned int V_28 ,
const struct V_29 * V_30 ,
const struct V_31 * V_32 ,
const struct V_31 * V_26 ,
const struct V_33 * V_34 , const char * V_35 , ... )
{
T_2 args ;
char V_36 [ V_37 ] ;
const struct V_1 * V_9 ;
F_20 () ;
V_9 = F_21 ( V_8 -> V_11 . V_12 [ V_2 ] ) ;
if ( V_9 ) {
va_start ( args , V_35 ) ;
vsnprintf ( V_36 , sizeof( V_36 ) , V_35 , args ) ;
va_end ( args ) ;
V_9 -> V_38 ( V_8 , V_2 , V_28 , V_30 , V_32 , V_26 , V_34 , V_36 ) ;
}
F_23 () ;
}
int F_28 ( struct V_39 * V_40 , const char * V_41 , ... )
{
T_2 args ;
int V_42 ;
if ( F_29 ( V_40 -> V_43 < V_44 ) ) {
va_start ( args , V_41 ) ;
V_42 = vsnprintf ( V_40 -> V_45 + V_40 -> V_43 , V_44 - V_40 -> V_43 , V_41 , args ) ;
va_end ( args ) ;
if ( F_29 ( V_40 -> V_43 + V_42 < V_44 ) ) {
V_40 -> V_43 += V_42 ;
return 0 ;
}
}
V_40 -> V_43 = V_44 ;
F_30 (KERN_ERR KBUILD_MODNAME L_2 ) ;
return - 1 ;
}
struct V_39 * F_31 ( void )
{
struct V_39 * V_40 = F_32 ( sizeof( * V_40 ) , V_46 ) ;
if ( F_33 ( ! V_40 ) ) {
F_34 () ;
do {
V_40 = F_35 ( & V_47 , NULL ) ;
} while ( ! V_40 );
}
V_40 -> V_43 = 0 ;
return V_40 ;
}
void F_36 ( struct V_39 * V_40 )
{
V_40 -> V_45 [ V_40 -> V_43 ] = 0 ;
F_37 ( L_3 , V_40 -> V_45 ) ;
if ( F_29 ( V_40 != & V_48 ) )
F_38 ( V_40 ) ;
else {
V_47 = V_40 ;
F_39 () ;
}
}
static void * F_40 ( struct V_49 * V_50 , T_3 * V_51 )
{
struct V_8 * V_8 = F_41 ( V_50 ) ;
F_5 ( & V_14 ) ;
if ( * V_51 >= F_4 ( V_8 -> V_11 . V_12 ) )
return NULL ;
return V_51 ;
}
static void * F_42 ( struct V_49 * V_52 , void * V_53 , T_3 * V_51 )
{
struct V_8 * V_8 = F_41 ( V_52 ) ;
( * V_51 ) ++ ;
if ( * V_51 >= F_4 ( V_8 -> V_11 . V_12 ) )
return NULL ;
return V_51 ;
}
static void F_43 ( struct V_49 * V_52 , void * V_53 )
{
F_7 ( & V_14 ) ;
}
static int F_44 ( struct V_49 * V_52 , void * V_53 )
{
T_3 * V_51 = V_53 ;
const struct V_1 * V_9 ;
int V_4 ;
struct V_8 * V_8 = F_41 ( V_52 ) ;
V_9 = F_2 ( V_8 -> V_11 . V_12 [ * V_51 ] ) ;
if ( ! V_9 )
F_45 ( V_52 , L_4 , * V_51 ) ;
else
F_45 ( V_52 , L_5 , * V_51 , V_9 -> V_7 ) ;
if ( F_46 ( V_52 ) )
return - V_54 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
if ( V_6 [ * V_51 ] [ V_4 ] == NULL )
continue;
V_9 = F_2 ( V_6 [ * V_51 ] [ V_4 ] ) ;
F_45 ( V_52 , L_6 , V_9 -> V_7 ) ;
if ( V_4 == 0 && V_6 [ * V_51 ] [ V_4 + 1 ] != NULL )
F_47 ( V_52 , L_7 ) ;
if ( F_46 ( V_52 ) )
return - V_54 ;
}
F_47 ( V_52 , L_8 ) ;
if ( F_46 ( V_52 ) )
return - V_54 ;
return 0 ;
}
static int F_48 ( struct V_55 * V_55 , struct V_56 * V_56 )
{
return F_49 ( V_55 , V_56 , & V_57 ,
sizeof( struct V_58 ) ) ;
}
static int F_50 ( struct V_59 * V_60 , int V_61 ,
void T_4 * V_62 , T_5 * V_63 , T_3 * V_64 )
{
const struct V_1 * V_9 ;
char V_45 [ V_65 ] ;
int V_66 = 0 ;
int V_67 = ( unsigned long ) V_60 -> V_68 ;
struct V_8 * V_8 = V_60 -> V_69 ;
if ( V_61 ) {
struct V_59 V_70 = * V_60 ;
V_70 . V_71 = V_45 ;
V_66 = F_51 ( & V_70 , V_61 , V_62 , V_63 , V_64 ) ;
if ( V_66 )
return V_66 ;
if ( ! strcmp ( V_45 , L_9 ) ) {
F_15 ( V_8 , V_67 ) ;
return 0 ;
}
F_5 ( & V_14 ) ;
V_9 = F_1 ( V_67 , V_45 ) ;
if ( V_9 == NULL ) {
F_7 ( & V_14 ) ;
return - V_21 ;
}
F_6 ( V_8 -> V_11 . V_12 [ V_67 ] , V_9 ) ;
F_7 ( & V_14 ) ;
} else {
F_5 ( & V_14 ) ;
V_9 = F_2 ( V_8 -> V_11 . V_12 [ V_67 ] ) ;
if ( ! V_9 )
V_60 -> V_71 = L_9 ;
else
V_60 -> V_71 = V_9 -> V_7 ;
V_66 = F_51 ( V_60 , V_61 , V_62 , V_63 , V_64 ) ;
F_7 ( & V_14 ) ;
}
return V_66 ;
}
static int F_52 ( struct V_8 * V_8 )
{
int V_4 ;
struct V_59 * V_60 ;
V_60 = V_72 ;
if ( ! F_53 ( V_8 , & V_17 ) ) {
V_60 = F_54 ( V_72 ,
sizeof( V_72 ) ,
V_73 ) ;
if ( ! V_60 )
goto V_74;
} else {
for ( V_4 = V_10 ; V_4 < V_15 ; V_4 ++ ) {
snprintf ( V_75 [ V_4 ] ,
3 , L_10 , V_4 ) ;
V_72 [ V_4 ] . V_76 =
V_75 [ V_4 ] ;
V_72 [ V_4 ] . V_77 = V_65 ;
V_72 [ V_4 ] . V_78 = 0644 ;
V_72 [ V_4 ] . V_79 =
F_50 ;
V_72 [ V_4 ] . V_68 =
( void * ) ( unsigned long ) V_4 ;
}
V_80 = F_55 ( V_8 , L_11 ,
V_81 ) ;
if ( ! V_80 )
goto V_82;
}
for ( V_4 = V_10 ; V_4 < V_15 ; V_4 ++ )
V_60 [ V_4 ] . V_69 = V_8 ;
V_8 -> V_11 . V_83 = F_55 ( V_8 ,
L_12 ,
V_60 ) ;
if ( ! V_8 -> V_11 . V_83 )
goto V_84;
return 0 ;
V_84:
if ( ! F_53 ( V_8 , & V_17 ) )
F_38 ( V_60 ) ;
else
F_56 ( V_80 ) ;
V_82:
V_74:
return - V_85 ;
}
static void F_57 ( struct V_8 * V_8 )
{
struct V_59 * V_60 ;
V_60 = V_8 -> V_11 . V_83 -> V_86 ;
F_56 ( V_8 -> V_11 . V_83 ) ;
if ( ! F_53 ( V_8 , & V_17 ) )
F_38 ( V_60 ) ;
else
F_56 ( V_80 ) ;
}
static int F_52 ( struct V_8 * V_8 )
{
return 0 ;
}
static void F_57 ( struct V_8 * V_8 )
{
}
static int T_6 F_58 ( struct V_8 * V_8 )
{
int V_16 = - V_85 ;
#ifdef F_59
if ( ! F_60 ( L_13 , V_87 ,
V_8 -> V_11 . V_88 , & V_89 ) )
return V_16 ;
#endif
V_16 = F_52 ( V_8 ) ;
if ( V_16 < 0 )
goto V_90;
return 0 ;
V_90:
#ifdef F_59
F_61 ( L_13 , V_8 -> V_11 . V_88 ) ;
#endif
return V_16 ;
}
static void T_7 F_62 ( struct V_8 * V_8 )
{
F_57 ( V_8 ) ;
#ifdef F_59
F_61 ( L_13 , V_8 -> V_11 . V_88 ) ;
#endif
}
int T_8 F_63 ( void )
{
return F_64 ( & V_91 ) ;
}
