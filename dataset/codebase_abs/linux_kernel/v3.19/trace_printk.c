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
if ( V_4 != V_5 )
F_4 () ;
F_5 ( & V_7 ) ;
for ( V_6 = V_4 ; V_6 < V_5 ; V_6 ++ ) {
struct V_1 * V_8 = F_1 ( * V_6 ) ;
if ( V_8 ) {
* V_6 = V_8 -> V_2 ;
continue;
}
V_2 = NULL ;
V_8 = F_6 ( sizeof( * V_8 ) , V_9 ) ;
if ( V_8 ) {
V_2 = F_6 ( strlen ( * V_6 ) + 1 , V_9 ) ;
if ( V_2 ) {
F_7 ( & V_8 -> V_10 , & V_11 ) ;
strcpy ( V_2 , * V_6 ) ;
V_8 -> V_2 = V_2 ;
} else
F_8 ( V_8 ) ;
}
* V_6 = V_2 ;
}
F_9 ( & V_7 ) ;
}
static int F_10 ( struct V_12 * V_13 ,
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
F_11 ( int V_21 , void * V_22 , const char * * V_2 , T_1 * V_3 )
{
struct V_1 * V_23 ;
if ( F_12 ( & V_11 ) )
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
V_23 = F_13 ( V_22 , F_14 ( * V_23 ) , V_2 ) ;
if ( V_23 -> V_10 . V_25 == & V_11 )
return NULL ;
V_23 = F_13 ( V_23 -> V_10 . V_25 , F_14 ( * V_23 ) , V_10 ) ;
return & V_23 -> V_2 ;
}
static void F_15 ( void )
{
F_5 ( & V_7 ) ;
}
static void F_16 ( void )
{
F_9 ( & V_7 ) ;
}
T_2 static int
F_10 ( struct V_12 * V_13 ,
unsigned long V_14 , void * V_15 )
{
return 0 ;
}
static inline const char * *
F_11 ( int V_21 , void * V_22 , const char * * V_2 , T_1 * V_3 )
{
return NULL ;
}
static inline void F_15 ( void ) { }
static inline void F_16 ( void ) { }
int F_17 ( unsigned long V_26 , const char * V_2 , ... )
{
int V_27 ;
T_3 V_28 ;
if ( F_18 ( ! V_2 ) )
return 0 ;
if ( ! ( V_29 & V_30 ) )
return 0 ;
va_start ( V_28 , V_2 ) ;
V_27 = F_19 ( V_26 , V_2 , V_28 ) ;
va_end ( V_28 ) ;
return V_27 ;
}
int F_20 ( unsigned long V_26 , const char * V_2 , T_3 V_28 )
{
if ( F_18 ( ! V_2 ) )
return 0 ;
if ( ! ( V_29 & V_30 ) )
return 0 ;
return F_19 ( V_26 , V_2 , V_28 ) ;
}
int F_21 ( unsigned long V_26 , const char * V_2 , ... )
{
int V_27 ;
T_3 V_28 ;
if ( ! ( V_29 & V_30 ) )
return 0 ;
va_start ( V_28 , V_2 ) ;
V_27 = F_22 ( V_26 , V_2 , V_28 ) ;
va_end ( V_28 ) ;
return V_27 ;
}
int F_23 ( unsigned long V_26 , const char * V_2 , T_3 V_28 )
{
if ( ! ( V_29 & V_30 ) )
return 0 ;
return F_22 ( V_26 , V_2 , V_28 ) ;
}
static const char * * F_24 ( void * V_22 , T_1 * V_3 )
{
const char * * V_2 = V_22 ;
int V_21 ;
int V_31 ;
V_21 = V_32 - V_33 ;
if ( * V_3 < V_21 )
return V_33 + * V_3 ;
V_31 = V_21 ;
V_21 = V_34 - V_35 ;
if ( * V_3 < V_31 + V_21 )
return V_35 + ( * V_3 - V_31 ) ;
return F_11 ( V_21 , V_22 , V_2 , V_3 ) ;
}
static void *
F_25 ( struct V_36 * V_37 , T_1 * V_3 )
{
F_15 () ;
return F_24 ( NULL , V_3 ) ;
}
static void * F_26 ( struct V_36 * V_37 , void * V_22 , T_1 * V_3 )
{
( * V_3 ) ++ ;
return F_24 ( V_22 , V_3 ) ;
}
static int F_27 ( struct V_36 * V_37 , void * V_22 )
{
const char * * V_2 = V_22 ;
const char * V_38 = * V_2 ;
int V_39 ;
F_28 ( V_37 , L_1 , * ( unsigned long * ) V_2 ) ;
for ( V_39 = 0 ; V_38 [ V_39 ] ; V_39 ++ ) {
switch ( V_38 [ V_39 ] ) {
case '\n' :
F_29 ( V_37 , L_2 ) ;
break;
case '\t' :
F_29 ( V_37 , L_3 ) ;
break;
case '\\' :
F_30 ( V_37 , '\\' ) ;
break;
case '"' :
F_29 ( V_37 , L_4 ) ;
break;
default:
F_30 ( V_37 , V_38 [ V_39 ] ) ;
}
}
F_29 ( V_37 , L_5 ) ;
return 0 ;
}
static void F_31 ( struct V_36 * V_37 , void * V_24 )
{
F_16 () ;
}
static int
F_32 ( struct V_40 * V_40 , struct V_41 * V_41 )
{
return F_33 ( V_41 , & V_42 ) ;
}
static T_2 int F_34 ( void )
{
struct V_43 * V_44 ;
V_44 = F_35 () ;
if ( ! V_44 )
return 0 ;
F_36 ( L_6 , 0444 , V_44 ,
NULL , & V_45 ) ;
return 0 ;
}
static T_2 int F_37 ( void )
{
return F_38 ( & V_46 ) ;
}
