static inline struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
if ( ! V_2 )
return F_2 ( - V_4 ) ;
F_3 (pos, &trace_bprintk_fmt_list, list) {
if ( ! strcmp ( V_3 -> V_2 , V_2 ) )
return V_3 ;
}
return NULL ;
}
static
void F_4 ( const char * * V_5 , const char * * V_6 )
{
const char * * V_7 ;
char * V_2 ;
if ( V_5 != V_6 )
F_5 () ;
F_6 ( & V_8 ) ;
for ( V_7 = V_5 ; V_7 < V_6 ; V_7 ++ ) {
struct V_1 * V_9 = F_1 ( * V_7 ) ;
if ( V_9 ) {
if ( ! F_7 ( V_9 ) )
* V_7 = V_9 -> V_2 ;
continue;
}
V_2 = NULL ;
V_9 = F_8 ( sizeof( * V_9 ) , V_10 ) ;
if ( V_9 ) {
V_2 = F_8 ( strlen ( * V_7 ) + 1 , V_10 ) ;
if ( V_2 ) {
F_9 ( & V_9 -> V_11 , & V_12 ) ;
strcpy ( V_2 , * V_7 ) ;
V_9 -> V_2 = V_2 ;
} else
F_10 ( V_9 ) ;
}
* V_7 = V_2 ;
}
F_11 ( & V_8 ) ;
}
static int F_12 ( struct V_13 * V_14 ,
unsigned long V_15 , void * V_16 )
{
struct V_17 * V_18 = V_16 ;
if ( V_18 -> V_19 ) {
const char * * V_5 = V_18 -> V_20 ;
const char * * V_6 = V_5 + V_18 -> V_19 ;
if ( V_15 == V_21 )
F_4 ( V_5 , V_6 ) ;
}
return 0 ;
}
static const char * *
F_13 ( int V_22 , void * V_23 , const char * * V_2 , T_1 * V_3 )
{
struct V_1 * V_24 ;
if ( F_14 ( & V_12 ) )
return NULL ;
if ( ! V_23 || V_22 == * V_3 ) {
struct V_1 * V_25 ;
F_3 (p, &trace_bprintk_fmt_list, list) {
if ( V_22 == * V_3 )
return & V_25 -> V_2 ;
V_22 ++ ;
}
return NULL ;
}
V_24 = F_15 ( V_23 , F_16 ( * V_24 ) , V_2 ) ;
if ( V_24 -> V_11 . V_26 == & V_12 )
return NULL ;
V_24 = F_15 ( V_24 -> V_11 . V_26 , F_16 ( * V_24 ) , V_11 ) ;
return & V_24 -> V_2 ;
}
static void F_17 ( void )
{
F_6 ( & V_8 ) ;
}
static void F_18 ( void )
{
F_11 ( & V_8 ) ;
}
T_2 static int
F_12 ( struct V_13 * V_14 ,
unsigned long V_15 , void * V_16 )
{
return 0 ;
}
static inline const char * *
F_13 ( int V_22 , void * V_23 , const char * * V_2 , T_1 * V_3 )
{
return NULL ;
}
static inline void F_17 ( void ) { }
static inline void F_18 ( void ) { }
void F_19 ( bool V_27 )
{
V_28 = V_27 ;
}
int F_20 ( unsigned long V_29 , const char * V_2 , ... )
{
int V_30 ;
T_3 V_31 ;
if ( F_21 ( ! V_2 ) )
return 0 ;
if ( ! V_28 )
return 0 ;
va_start ( V_31 , V_2 ) ;
V_30 = F_22 ( V_29 , V_2 , V_31 ) ;
va_end ( V_31 ) ;
return V_30 ;
}
int F_23 ( unsigned long V_29 , const char * V_2 , T_3 V_31 )
{
if ( F_21 ( ! V_2 ) )
return 0 ;
if ( ! V_28 )
return 0 ;
return F_22 ( V_29 , V_2 , V_31 ) ;
}
int F_24 ( unsigned long V_29 , const char * V_2 , ... )
{
int V_30 ;
T_3 V_31 ;
if ( ! V_28 )
return 0 ;
va_start ( V_31 , V_2 ) ;
V_30 = F_25 ( V_29 , V_2 , V_31 ) ;
va_end ( V_31 ) ;
return V_30 ;
}
int F_26 ( unsigned long V_29 , const char * V_2 , T_3 V_31 )
{
if ( ! V_28 )
return 0 ;
return F_25 ( V_29 , V_2 , V_31 ) ;
}
static const char * * F_27 ( void * V_23 , T_1 * V_3 )
{
const char * * V_2 = V_23 ;
int V_22 ;
int V_32 ;
V_22 = V_33 - V_34 ;
if ( * V_3 < V_22 )
return V_34 + * V_3 ;
V_32 = V_22 ;
V_22 = V_35 - V_36 ;
if ( * V_3 < V_32 + V_22 )
return V_36 + ( * V_3 - V_32 ) ;
V_22 += V_32 ;
return F_13 ( V_22 , V_23 , V_2 , V_3 ) ;
}
static void *
F_28 ( struct V_37 * V_38 , T_1 * V_3 )
{
F_17 () ;
return F_27 ( NULL , V_3 ) ;
}
static void * F_29 ( struct V_37 * V_38 , void * V_23 , T_1 * V_3 )
{
( * V_3 ) ++ ;
return F_27 ( V_23 , V_3 ) ;
}
static int F_30 ( struct V_37 * V_38 , void * V_23 )
{
const char * * V_2 = V_23 ;
const char * V_39 = * V_2 ;
int V_40 ;
if ( ! * V_2 )
return 0 ;
F_31 ( V_38 , L_1 , * ( unsigned long * ) V_2 ) ;
for ( V_40 = 0 ; V_39 [ V_40 ] ; V_40 ++ ) {
switch ( V_39 [ V_40 ] ) {
case '\n' :
F_32 ( V_38 , L_2 ) ;
break;
case '\t' :
F_32 ( V_38 , L_3 ) ;
break;
case '\\' :
F_33 ( V_38 , '\\' ) ;
break;
case '"' :
F_32 ( V_38 , L_4 ) ;
break;
default:
F_33 ( V_38 , V_39 [ V_40 ] ) ;
}
}
F_32 ( V_38 , L_5 ) ;
return 0 ;
}
static void F_34 ( struct V_37 * V_38 , void * V_25 )
{
F_18 () ;
}
static int
F_35 ( struct V_41 * V_41 , struct V_42 * V_42 )
{
return F_36 ( V_42 , & V_43 ) ;
}
static T_2 int F_37 ( void )
{
struct V_44 * V_45 ;
V_45 = F_38 () ;
if ( F_7 ( V_45 ) )
return 0 ;
F_39 ( L_6 , 0444 , V_45 ,
NULL , & V_46 ) ;
return 0 ;
}
static T_2 int F_40 ( void )
{
return F_41 ( & V_47 ) ;
}
