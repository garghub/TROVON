static inline struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
F_2 (pos, &trace_bprintk_fmt_list, list) {
if ( ! strcmp ( V_3 -> V_2 , V_2 ) )
return V_3 ;
}
return NULL ;
}
static
void F_3 ( const char * * V_4 , const char * * V_5 )
{
const char * * V_6 ;
char * V_2 ;
F_4 ( & V_7 ) ;
for ( V_6 = V_4 ; V_6 < V_5 ; V_6 ++ ) {
struct V_1 * V_8 = F_1 ( * V_6 ) ;
if ( V_8 ) {
* V_6 = V_8 -> V_2 ;
continue;
}
V_2 = NULL ;
V_8 = F_5 ( sizeof( * V_8 ) , V_9 ) ;
if ( V_8 ) {
V_2 = F_5 ( strlen ( * V_6 ) + 1 , V_9 ) ;
if ( V_2 ) {
F_6 ( & V_8 -> V_10 , & V_11 ) ;
strcpy ( V_2 , * V_6 ) ;
V_8 -> V_2 = V_2 ;
} else
F_7 ( V_8 ) ;
}
* V_6 = V_2 ;
}
F_8 ( & V_7 ) ;
}
static int F_9 ( struct V_12 * V_13 ,
unsigned long V_14 , void * V_15 )
{
struct V_16 * V_17 = V_15 ;
if ( V_17 -> V_18 ) {
const char * * V_4 = V_17 -> V_19 ;
const char * * V_5 = V_4 + V_17 -> V_18 ;
if ( V_14 == V_20 )
F_3 ( V_4 , V_5 ) ;
}
return 0 ;
}
static const char * *
F_10 ( int V_21 , void * V_22 , const char * * V_2 , T_1 * V_3 )
{
struct V_1 * V_23 ;
if ( F_11 ( & V_11 ) )
return NULL ;
if ( ! V_22 || V_21 == * V_3 ) {
struct V_1 * V_24 ;
F_2 (p, &trace_bprintk_fmt_list, list) {
if ( V_21 == * V_3 )
return & V_24 -> V_2 ;
V_21 ++ ;
}
return NULL ;
}
V_23 = F_12 ( V_22 , F_13 ( * V_23 ) , V_2 ) ;
if ( V_23 -> V_10 . V_25 == & V_11 )
return NULL ;
V_23 = F_12 ( V_23 -> V_10 . V_25 , F_13 ( * V_23 ) , V_10 ) ;
return & V_23 -> V_2 ;
}
static void F_14 ( void )
{
F_4 ( & V_7 ) ;
}
static void F_15 ( void )
{
F_8 ( & V_7 ) ;
}
T_2 static int
F_9 ( struct V_12 * V_13 ,
unsigned long V_14 , void * V_15 )
{
return 0 ;
}
static inline const char * *
F_10 ( int V_21 , void * V_22 , const char * * V_2 , T_1 * V_3 )
{
return NULL ;
}
static inline void F_14 ( void ) { }
static inline void F_15 ( void ) { }
int F_16 ( unsigned long V_26 , const char * V_2 , ... )
{
int V_27 ;
T_3 V_28 ;
if ( F_17 ( ! V_2 ) )
return 0 ;
if ( ! ( V_29 & V_30 ) )
return 0 ;
va_start ( V_28 , V_2 ) ;
V_27 = F_18 ( V_26 , V_2 , V_28 ) ;
va_end ( V_28 ) ;
return V_27 ;
}
int F_19 ( unsigned long V_26 , const char * V_2 , T_3 V_28 )
{
if ( F_17 ( ! V_2 ) )
return 0 ;
if ( ! ( V_29 & V_30 ) )
return 0 ;
return F_18 ( V_26 , V_2 , V_28 ) ;
}
int F_20 ( unsigned long V_26 , const char * V_2 , ... )
{
int V_27 ;
T_3 V_28 ;
if ( ! ( V_29 & V_30 ) )
return 0 ;
va_start ( V_28 , V_2 ) ;
V_27 = F_21 ( V_26 , V_2 , V_28 ) ;
va_end ( V_28 ) ;
return V_27 ;
}
int F_22 ( unsigned long V_26 , const char * V_2 , T_3 V_28 )
{
if ( ! ( V_29 & V_30 ) )
return 0 ;
return F_21 ( V_26 , V_2 , V_28 ) ;
}
static const char * * F_23 ( void * V_22 , T_1 * V_3 )
{
const char * * V_2 = V_22 ;
int V_21 ;
V_21 = V_31 - V_32 ;
if ( * V_3 < V_21 )
return V_32 + * V_3 ;
return F_10 ( V_21 , V_22 , V_2 , V_3 ) ;
}
static void *
F_24 ( struct V_33 * V_34 , T_1 * V_3 )
{
F_14 () ;
return F_23 ( NULL , V_3 ) ;
}
static void * F_25 ( struct V_33 * V_34 , void * V_22 , T_1 * V_3 )
{
( * V_3 ) ++ ;
return F_23 ( V_22 , V_3 ) ;
}
static int F_26 ( struct V_33 * V_34 , void * V_22 )
{
const char * * V_2 = V_22 ;
const char * V_35 = * V_2 ;
int V_36 ;
F_27 ( V_34 , L_1 , * ( unsigned long * ) V_2 ) ;
for ( V_36 = 0 ; V_35 [ V_36 ] ; V_36 ++ ) {
switch ( V_35 [ V_36 ] ) {
case '\n' :
F_28 ( V_34 , L_2 ) ;
break;
case '\t' :
F_28 ( V_34 , L_3 ) ;
break;
case '\\' :
F_28 ( V_34 , L_4 ) ;
break;
case '"' :
F_28 ( V_34 , L_5 ) ;
break;
default:
F_29 ( V_34 , V_35 [ V_36 ] ) ;
}
}
F_28 ( V_34 , L_6 ) ;
return 0 ;
}
static void F_30 ( struct V_33 * V_34 , void * V_24 )
{
F_15 () ;
}
static int
F_31 ( struct V_37 * V_37 , struct V_38 * V_38 )
{
return F_32 ( V_38 , & V_39 ) ;
}
static T_2 int F_33 ( void )
{
struct V_40 * V_41 ;
V_41 = F_34 () ;
if ( ! V_41 )
return 0 ;
F_35 ( L_7 , 0444 , V_41 ,
NULL , & V_42 ) ;
return 0 ;
}
static T_2 int F_36 ( void )
{
return F_37 ( & V_43 ) ;
}
