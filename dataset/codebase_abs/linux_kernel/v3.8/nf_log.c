static struct V_1 * F_1 ( int V_2 , const char * V_3 )
{
struct V_1 * V_4 ;
F_2 (t, &nf_loggers_l[pf], list[pf]) {
if ( ! F_3 ( V_3 , V_4 -> V_5 , strlen ( V_4 -> V_5 ) ) )
return V_4 ;
}
return NULL ;
}
int F_4 ( T_1 V_2 , struct V_1 * V_6 )
{
const struct V_1 * V_7 ;
int V_8 ;
if ( V_2 >= F_5 ( V_9 ) )
return - V_10 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_6 -> V_11 ) ; V_8 ++ )
F_6 ( & V_6 -> V_11 [ V_8 ] ) ;
F_7 ( & V_12 ) ;
if ( V_2 == V_13 ) {
for ( V_8 = V_13 ; V_8 < V_14 ; V_8 ++ )
F_8 ( & ( V_6 -> V_11 [ V_8 ] ) , & ( V_15 [ V_8 ] ) ) ;
} else {
F_8 ( & V_6 -> V_11 [ V_2 ] , & V_15 [ V_2 ] ) ;
V_7 = F_9 ( V_9 [ V_2 ] ,
F_10 ( & V_12 ) ) ;
if ( V_7 == NULL )
F_11 ( V_9 [ V_2 ] , V_6 ) ;
}
F_12 ( & V_12 ) ;
return 0 ;
}
void F_13 ( struct V_1 * V_6 )
{
const struct V_1 * V_16 ;
int V_8 ;
F_7 ( & V_12 ) ;
for ( V_8 = 0 ; V_8 < F_5 ( V_9 ) ; V_8 ++ ) {
V_16 = F_9 ( V_9 [ V_8 ] ,
F_10 ( & V_12 ) ) ;
if ( V_16 == V_6 )
F_14 ( V_9 [ V_8 ] , NULL ) ;
F_15 ( & V_6 -> V_11 [ V_8 ] ) ;
}
F_12 ( & V_12 ) ;
F_16 () ;
}
int F_17 ( T_1 V_2 , const struct V_1 * V_6 )
{
if ( V_2 >= F_5 ( V_9 ) )
return - V_10 ;
F_7 ( & V_12 ) ;
if ( F_1 ( V_2 , V_6 -> V_5 ) == NULL ) {
F_12 ( & V_12 ) ;
return - V_17 ;
}
F_11 ( V_9 [ V_2 ] , V_6 ) ;
F_12 ( & V_12 ) ;
return 0 ;
}
void F_18 ( T_1 V_2 )
{
if ( V_2 >= F_5 ( V_9 ) )
return;
F_7 ( & V_12 ) ;
F_14 ( V_9 [ V_2 ] , NULL ) ;
F_12 ( & V_12 ) ;
}
void F_19 ( T_1 V_2 ,
unsigned int V_18 ,
const struct V_19 * V_20 ,
const struct V_21 * V_22 ,
const struct V_21 * V_23 ,
const struct V_24 * V_25 ,
const char * V_26 , ... )
{
T_2 args ;
char V_27 [ V_28 ] ;
const struct V_1 * V_6 ;
F_20 () ;
V_6 = F_21 ( V_9 [ V_2 ] ) ;
if ( V_6 ) {
va_start ( args , V_26 ) ;
vsnprintf ( V_27 , sizeof( V_27 ) , V_26 , args ) ;
va_end ( args ) ;
V_6 -> V_29 ( V_2 , V_18 , V_20 , V_22 , V_23 , V_25 , V_27 ) ;
}
F_22 () ;
}
static void * F_23 ( struct V_30 * V_31 , T_3 * V_32 )
{
F_7 ( & V_12 ) ;
if ( * V_32 >= F_5 ( V_9 ) )
return NULL ;
return V_32 ;
}
static void * F_24 ( struct V_30 * V_33 , void * V_34 , T_3 * V_32 )
{
( * V_32 ) ++ ;
if ( * V_32 >= F_5 ( V_9 ) )
return NULL ;
return V_32 ;
}
static void F_25 ( struct V_30 * V_33 , void * V_34 )
{
F_12 ( & V_12 ) ;
}
static int F_26 ( struct V_30 * V_33 , void * V_34 )
{
T_3 * V_32 = V_34 ;
const struct V_1 * V_6 ;
struct V_1 * V_4 ;
int V_35 ;
V_6 = F_9 ( V_9 [ * V_32 ] ,
F_10 ( & V_12 ) ) ;
if ( ! V_6 )
V_35 = F_27 ( V_33 , L_1 , * V_32 ) ;
else
V_35 = F_27 ( V_33 , L_2 , * V_32 , V_6 -> V_5 ) ;
if ( V_35 < 0 )
return V_35 ;
F_2 (t, &nf_loggers_l[*pos], list[*pos]) {
V_35 = F_27 ( V_33 , L_3 , V_4 -> V_5 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( & V_4 -> V_11 [ * V_32 ] != V_15 [ * V_32 ] . V_36 ) {
V_35 = F_27 ( V_33 , L_4 ) ;
if ( V_35 < 0 )
return V_35 ;
}
}
return F_27 ( V_33 , L_5 ) ;
}
static int F_28 ( struct V_37 * V_37 , struct V_38 * V_38 )
{
return F_29 ( V_38 , & V_39 ) ;
}
static int F_30 ( T_4 * V_40 , int V_41 ,
void T_5 * V_42 , T_6 * V_43 , T_3 * V_44 )
{
const struct V_1 * V_6 ;
char V_45 [ V_46 ] ;
T_6 V_47 = * V_43 ;
int V_48 = 0 ;
int V_49 = ( unsigned long ) V_40 -> V_50 ;
if ( V_41 ) {
if ( V_47 > sizeof( V_45 ) )
V_47 = sizeof( V_45 ) ;
if ( F_31 ( V_45 , V_42 , V_47 ) )
return - V_51 ;
if ( ! strcmp ( V_45 , L_6 ) ) {
F_18 ( V_49 ) ;
return 0 ;
}
F_7 ( & V_12 ) ;
V_6 = F_1 ( V_49 , V_45 ) ;
if ( V_6 == NULL ) {
F_12 ( & V_12 ) ;
return - V_17 ;
}
F_11 ( V_9 [ V_49 ] , V_6 ) ;
F_12 ( & V_12 ) ;
} else {
F_7 ( & V_12 ) ;
V_6 = F_9 ( V_9 [ V_49 ] ,
F_10 ( & V_12 ) ) ;
if ( ! V_6 )
V_40 -> V_52 = L_6 ;
else
V_40 -> V_52 = V_6 -> V_5 ;
V_48 = F_32 ( V_40 , V_41 , V_42 , V_43 , V_44 ) ;
F_12 ( & V_12 ) ;
}
return V_48 ;
}
static T_7 int F_33 ( void )
{
int V_8 ;
for ( V_8 = V_13 ; V_8 < V_14 ; V_8 ++ ) {
snprintf ( V_53 [ V_8 - V_13 ] , 3 , L_7 , V_8 ) ;
V_54 [ V_8 ] . V_55 =
V_53 [ V_8 - V_13 ] ;
V_54 [ V_8 ] . V_52 = NULL ;
V_54 [ V_8 ] . V_56 =
V_46 * sizeof( char ) ;
V_54 [ V_8 ] . V_57 = 0644 ;
V_54 [ V_8 ] . V_58 = F_30 ;
V_54 [ V_8 ] . V_50 = ( void * ) ( unsigned long ) V_8 ;
}
V_59 = F_34 ( & V_60 , L_8 ,
V_54 ) ;
if ( ! V_59 )
return - V_61 ;
return 0 ;
}
static T_7 int F_33 ( void )
{
return 0 ;
}
int T_7 F_35 ( void )
{
int V_8 , V_48 ;
#ifdef F_36
if ( ! F_37 ( L_9 , V_62 ,
V_63 , & V_64 ) )
return - 1 ;
#endif
V_48 = F_33 () ;
if ( V_48 < 0 )
return V_48 ;
for ( V_8 = V_13 ; V_8 < V_14 ; V_8 ++ )
F_6 ( & ( V_15 [ V_8 ] ) ) ;
return 0 ;
}
