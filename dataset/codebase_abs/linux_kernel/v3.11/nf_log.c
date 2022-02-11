static struct V_1 * F_1 ( int V_2 , const char * V_3 )
{
struct V_1 * V_4 ;
F_2 (t, &nf_loggers_l[pf], list[pf]) {
if ( ! F_3 ( V_3 , V_4 -> V_5 , strlen ( V_4 -> V_5 ) ) )
return V_4 ;
}
return NULL ;
}
void F_4 ( struct V_6 * V_6 , T_1 V_2 , const struct V_1 * V_7 )
{
const struct V_1 * log ;
if ( V_2 == V_8 )
return;
F_5 ( & V_9 ) ;
log = F_6 ( V_6 -> V_10 . V_11 [ V_2 ] ,
F_7 ( & V_9 ) ) ;
if ( log == NULL )
F_8 ( V_6 -> V_10 . V_11 [ V_2 ] , V_7 ) ;
F_9 ( & V_9 ) ;
}
void F_10 ( struct V_6 * V_6 , const struct V_1 * V_7 )
{
int V_12 ;
const struct V_1 * log ;
F_5 ( & V_9 ) ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
log = F_6 ( V_6 -> V_10 . V_11 [ V_12 ] ,
F_7 ( & V_9 ) ) ;
if ( log == V_7 )
F_11 ( V_6 -> V_10 . V_11 [ V_12 ] , NULL ) ;
}
F_9 ( & V_9 ) ;
F_12 () ;
}
int F_13 ( T_1 V_2 , struct V_1 * V_7 )
{
int V_12 ;
if ( V_2 >= F_14 ( V_14 . V_10 . V_11 ) )
return - V_15 ;
for ( V_12 = 0 ; V_12 < F_14 ( V_7 -> V_16 ) ; V_12 ++ )
F_15 ( & V_7 -> V_16 [ V_12 ] ) ;
F_5 ( & V_9 ) ;
if ( V_2 == V_8 ) {
for ( V_12 = V_8 ; V_12 < V_13 ; V_12 ++ )
F_16 ( & ( V_7 -> V_16 [ V_12 ] ) , & ( V_17 [ V_12 ] ) ) ;
} else {
F_16 ( & V_7 -> V_16 [ V_2 ] , & V_17 [ V_2 ] ) ;
}
F_9 ( & V_9 ) ;
return 0 ;
}
void F_17 ( struct V_1 * V_7 )
{
int V_12 ;
F_5 ( & V_9 ) ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
F_18 ( & V_7 -> V_16 [ V_12 ] ) ;
F_9 ( & V_9 ) ;
}
int F_19 ( struct V_6 * V_6 , T_1 V_2 ,
const struct V_1 * V_7 )
{
if ( V_2 >= F_14 ( V_6 -> V_10 . V_11 ) )
return - V_15 ;
F_5 ( & V_9 ) ;
if ( F_1 ( V_2 , V_7 -> V_5 ) == NULL ) {
F_9 ( & V_9 ) ;
return - V_18 ;
}
F_8 ( V_6 -> V_10 . V_11 [ V_2 ] , V_7 ) ;
F_9 ( & V_9 ) ;
return 0 ;
}
void F_20 ( struct V_6 * V_6 , T_1 V_2 )
{
if ( V_2 >= F_14 ( V_6 -> V_10 . V_11 ) )
return;
F_5 ( & V_9 ) ;
F_11 ( V_6 -> V_10 . V_11 [ V_2 ] , NULL ) ;
F_9 ( & V_9 ) ;
}
void F_21 ( struct V_6 * V_6 ,
T_1 V_2 ,
unsigned int V_19 ,
const struct V_20 * V_21 ,
const struct V_22 * V_23 ,
const struct V_22 * V_24 ,
const struct V_25 * V_26 ,
const char * V_27 , ... )
{
T_2 args ;
char V_28 [ V_29 ] ;
const struct V_1 * V_7 ;
F_22 () ;
V_7 = F_23 ( V_6 -> V_10 . V_11 [ V_2 ] ) ;
if ( V_7 ) {
va_start ( args , V_27 ) ;
vsnprintf ( V_28 , sizeof( V_28 ) , V_27 , args ) ;
va_end ( args ) ;
V_7 -> V_30 ( V_6 , V_2 , V_19 , V_21 , V_23 , V_24 , V_26 , V_28 ) ;
}
F_24 () ;
}
static void * F_25 ( struct V_31 * V_32 , T_3 * V_33 )
{
struct V_6 * V_6 = F_26 ( V_32 ) ;
F_5 ( & V_9 ) ;
if ( * V_33 >= F_14 ( V_6 -> V_10 . V_11 ) )
return NULL ;
return V_33 ;
}
static void * F_27 ( struct V_31 * V_34 , void * V_35 , T_3 * V_33 )
{
struct V_6 * V_6 = F_26 ( V_34 ) ;
( * V_33 ) ++ ;
if ( * V_33 >= F_14 ( V_6 -> V_10 . V_11 ) )
return NULL ;
return V_33 ;
}
static void F_28 ( struct V_31 * V_34 , void * V_35 )
{
F_9 ( & V_9 ) ;
}
static int F_29 ( struct V_31 * V_34 , void * V_35 )
{
T_3 * V_33 = V_35 ;
const struct V_1 * V_7 ;
struct V_1 * V_4 ;
int V_36 ;
struct V_6 * V_6 = F_26 ( V_34 ) ;
V_7 = F_6 ( V_6 -> V_10 . V_11 [ * V_33 ] ,
F_7 ( & V_9 ) ) ;
if ( ! V_7 )
V_36 = F_30 ( V_34 , L_1 , * V_33 ) ;
else
V_36 = F_30 ( V_34 , L_2 , * V_33 , V_7 -> V_5 ) ;
if ( V_36 < 0 )
return V_36 ;
F_2 (t, &nf_loggers_l[*pos], list[*pos]) {
V_36 = F_30 ( V_34 , L_3 , V_4 -> V_5 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( & V_4 -> V_16 [ * V_33 ] != V_17 [ * V_33 ] . V_37 ) {
V_36 = F_30 ( V_34 , L_4 ) ;
if ( V_36 < 0 )
return V_36 ;
}
}
return F_30 ( V_34 , L_5 ) ;
}
static int F_31 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
return F_32 ( V_38 , V_39 , & V_40 ,
sizeof( struct V_41 ) ) ;
}
static int F_33 ( struct V_42 * V_43 , int V_44 ,
void T_4 * V_45 , T_5 * V_46 , T_3 * V_47 )
{
const struct V_1 * V_7 ;
char V_48 [ V_49 ] ;
T_5 V_50 = * V_46 ;
int V_51 = 0 ;
int V_52 = ( unsigned long ) V_43 -> V_53 ;
struct V_6 * V_6 = V_54 -> V_55 -> V_56 ;
if ( V_44 ) {
if ( V_50 > sizeof( V_48 ) )
V_50 = sizeof( V_48 ) ;
if ( F_34 ( V_48 , V_45 , V_50 ) )
return - V_57 ;
if ( ! strcmp ( V_48 , L_6 ) ) {
F_20 ( V_6 , V_52 ) ;
return 0 ;
}
F_5 ( & V_9 ) ;
V_7 = F_1 ( V_52 , V_48 ) ;
if ( V_7 == NULL ) {
F_9 ( & V_9 ) ;
return - V_18 ;
}
F_8 ( V_6 -> V_10 . V_11 [ V_52 ] , V_7 ) ;
F_9 ( & V_9 ) ;
} else {
F_5 ( & V_9 ) ;
V_7 = F_6 ( V_6 -> V_10 . V_11 [ V_52 ] ,
F_7 ( & V_9 ) ) ;
if ( ! V_7 )
V_43 -> V_58 = L_6 ;
else
V_43 -> V_58 = V_7 -> V_5 ;
V_51 = F_35 ( V_43 , V_44 , V_45 , V_46 , V_47 ) ;
F_9 ( & V_9 ) ;
}
return V_51 ;
}
static int F_36 ( struct V_6 * V_6 )
{
int V_12 ;
struct V_42 * V_43 ;
V_43 = V_59 ;
if ( ! F_37 ( V_6 , & V_14 ) ) {
V_43 = F_38 ( V_59 ,
sizeof( V_59 ) ,
V_60 ) ;
if ( ! V_43 )
goto V_61;
} else {
for ( V_12 = V_8 ; V_12 < V_13 ; V_12 ++ ) {
snprintf ( V_62 [ V_12 ] ,
3 , L_7 , V_12 ) ;
V_59 [ V_12 ] . V_63 =
V_62 [ V_12 ] ;
V_59 [ V_12 ] . V_58 = NULL ;
V_59 [ V_12 ] . V_64 =
V_49 * sizeof( char ) ;
V_59 [ V_12 ] . V_65 = 0644 ;
V_59 [ V_12 ] . V_66 =
F_33 ;
V_59 [ V_12 ] . V_53 =
( void * ) ( unsigned long ) V_12 ;
}
}
V_6 -> V_10 . V_67 = F_39 ( V_6 ,
L_8 ,
V_43 ) ;
if ( ! V_6 -> V_10 . V_67 )
goto V_68;
return 0 ;
V_68:
if ( ! F_37 ( V_6 , & V_14 ) )
F_40 ( V_43 ) ;
V_61:
return - V_69 ;
}
static void F_41 ( struct V_6 * V_6 )
{
struct V_42 * V_43 ;
V_43 = V_6 -> V_10 . V_67 -> V_70 ;
F_42 ( V_6 -> V_10 . V_67 ) ;
if ( ! F_37 ( V_6 , & V_14 ) )
F_40 ( V_43 ) ;
}
static int F_36 ( struct V_6 * V_6 )
{
return 0 ;
}
static void F_41 ( struct V_6 * V_6 )
{
}
static int T_6 F_43 ( struct V_6 * V_6 )
{
int V_36 = - V_69 ;
#ifdef F_44
if ( ! F_45 ( L_9 , V_71 ,
V_6 -> V_10 . V_72 , & V_73 ) )
return V_36 ;
#endif
V_36 = F_36 ( V_6 ) ;
if ( V_36 < 0 )
goto V_74;
return 0 ;
V_74:
#ifdef F_44
F_46 ( L_9 , V_6 -> V_10 . V_72 ) ;
#endif
return V_36 ;
}
static void T_7 F_47 ( struct V_6 * V_6 )
{
F_41 ( V_6 ) ;
#ifdef F_44
F_46 ( L_9 , V_6 -> V_10 . V_72 ) ;
#endif
}
int T_8 F_48 ( void )
{
int V_12 , V_36 ;
V_36 = F_49 ( & V_75 ) ;
if ( V_36 < 0 )
return V_36 ;
for ( V_12 = V_8 ; V_12 < V_13 ; V_12 ++ )
F_15 ( & ( V_17 [ V_12 ] ) ) ;
return 0 ;
}
