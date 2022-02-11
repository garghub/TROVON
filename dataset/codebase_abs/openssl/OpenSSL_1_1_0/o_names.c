static int F_1 ( const char * V_1 , const char * V_2 )
{
return strcmp ( V_1 , V_2 ) ;
}
int F_2 ( void )
{
if ( V_3 != NULL )
return ( 1 ) ;
F_3 ( V_4 ) ;
V_3 = F_4 ( V_5 , V_6 ) ;
F_3 ( V_7 ) ;
return ( V_3 != NULL ) ;
}
static int V_6 ( const T_1 * V_1 , const T_1 * V_2 )
{
int V_8 ;
V_8 = V_1 -> type - V_2 -> type ;
if ( V_8 == 0 ) {
if ( ( V_9 != NULL )
&& ( F_5 ( V_9 ) > V_1 -> type ) ) {
V_8 = F_6 ( V_9 ,
V_1 -> type ) -> F_7 ( V_1 -> V_10 , V_2 -> V_10 ) ;
} else
V_8 = strcmp ( V_1 -> V_10 , V_2 -> V_10 ) ;
}
return ( V_8 ) ;
}
static unsigned long V_5 ( const T_1 * V_1 )
{
unsigned long V_8 ;
if ( ( V_9 != NULL )
&& ( F_5 ( V_9 ) > V_1 -> type ) ) {
V_8 =
F_6 ( V_9 ,
V_1 -> type ) -> F_8 ( V_1 -> V_10 ) ;
} else {
V_8 = F_9 ( V_1 -> V_10 ) ;
}
V_8 ^= V_1 -> type ;
return ( V_8 ) ;
}
const char * F_10 ( const char * V_10 , int type )
{
T_1 V_11 , * V_8 ;
int V_12 = 0 , V_13 ;
if ( V_10 == NULL )
return ( NULL ) ;
if ( ( V_3 == NULL ) && ! F_2 () )
return ( NULL ) ;
V_13 = type & V_14 ;
type &= ~ V_14 ;
V_11 . V_10 = V_10 ;
V_11 . type = type ;
for (; ; ) {
V_8 = F_11 ( V_3 , & V_11 ) ;
if ( V_8 == NULL )
return ( NULL ) ;
if ( ( V_8 -> V_13 ) && ! V_13 ) {
if ( ++ V_12 > 10 )
return ( NULL ) ;
V_11 . V_10 = V_8 -> V_15 ;
} else {
return ( V_8 -> V_15 ) ;
}
}
}
int F_12 ( const char * V_10 , int type , const char * V_15 )
{
T_1 * V_16 , * V_8 ;
int V_13 ;
if ( ( V_3 == NULL ) && ! F_2 () )
return ( 0 ) ;
V_13 = type & V_14 ;
type &= ~ V_14 ;
V_16 = F_13 ( sizeof( * V_16 ) ) ;
if ( V_16 == NULL ) {
return 0 ;
}
V_16 -> V_10 = V_10 ;
V_16 -> V_13 = V_13 ;
V_16 -> type = type ;
V_16 -> V_15 = V_15 ;
V_8 = F_14 ( V_3 , V_16 ) ;
if ( V_8 != NULL ) {
if ( ( V_9 != NULL )
&& ( F_5 ( V_9 ) > V_8 -> type ) ) {
F_6 ( V_9 ,
V_8 -> type ) -> F_15 ( V_8 -> V_10 , V_8 -> type ,
V_8 -> V_15 ) ;
}
F_16 ( V_8 ) ;
} else {
if ( F_17 ( V_3 ) ) {
F_16 ( V_16 ) ;
return 0 ;
}
}
return 1 ;
}
int F_18 ( const char * V_10 , int type )
{
T_1 V_11 , * V_8 ;
if ( V_3 == NULL )
return ( 0 ) ;
type &= ~ V_14 ;
V_11 . V_10 = V_10 ;
V_11 . type = type ;
V_8 = F_19 ( V_3 , & V_11 ) ;
if ( V_8 != NULL ) {
if ( ( V_9 != NULL )
&& ( F_5 ( V_9 ) > V_8 -> type ) ) {
F_6 ( V_9 ,
V_8 -> type ) -> F_15 ( V_8 -> V_10 , V_8 -> type ,
V_8 -> V_15 ) ;
}
F_16 ( V_8 ) ;
return ( 1 ) ;
} else
return ( 0 ) ;
}
static void F_20 ( const T_1 * V_10 , T_2 * V_17 )
{
if ( V_10 -> type == V_17 -> type )
V_17 -> V_18 ( V_10 , V_17 -> V_19 ) ;
}
void F_21 ( int type , void (* V_18) ( const T_1 * , void * V_19 ) ,
void * V_19 )
{
T_2 V_17 ;
V_17 . type = type ;
V_17 . V_18 = V_18 ;
V_17 . V_19 = V_19 ;
F_22 ( V_3 , F_20 , & V_17 ) ;
}
static void F_23 ( const T_1 * V_10 , void * V_20 )
{
struct V_21 * V_17 = V_20 ;
if ( V_10 -> type != V_17 -> type )
return;
V_17 -> V_22 [ V_17 -> V_23 ++ ] = V_10 ;
}
static int F_24 ( const void * V_24 , const void * V_25 )
{
const T_1 * const * V_26 = V_24 ;
const T_1 * const * V_27 = V_25 ;
return strcmp ( ( * V_26 ) -> V_10 , ( * V_27 ) -> V_10 ) ;
}
void F_25 ( int type ,
void (* V_18) ( const T_1 * , void * V_19 ) ,
void * V_19 )
{
struct V_21 V_17 ;
int V_23 ;
V_17 . type = type ;
V_17 . V_22 =
F_13 ( sizeof( * V_17 . V_22 ) * F_26 ( V_3 ) ) ;
if ( V_17 . V_22 != NULL ) {
V_17 . V_23 = 0 ;
F_21 ( type , F_23 , & V_17 ) ;
qsort ( ( void * ) V_17 . V_22 , V_17 . V_23 , sizeof( * V_17 . V_22 ) , F_24 ) ;
for ( V_23 = 0 ; V_23 < V_17 . V_23 ; ++ V_23 )
V_18 ( V_17 . V_22 [ V_23 ] , V_19 ) ;
F_16 ( ( void * ) V_17 . V_22 ) ;
}
}
static void F_27 ( T_1 * V_16 )
{
if ( V_16 == NULL )
return;
if ( V_28 < 0 || V_28 == V_16 -> type )
F_18 ( V_16 -> V_10 , V_16 -> type ) ;
}
static void F_28 ( T_3 * V_29 )
{
F_16 ( V_29 ) ;
}
void F_29 ( int type )
{
unsigned long V_30 ;
if ( V_3 == NULL )
return;
V_28 = type ;
V_30 = F_30 ( V_3 ) ;
F_31 ( V_3 , 0 ) ;
F_32 ( V_3 , F_27 ) ;
if ( type < 0 ) {
F_33 ( V_3 ) ;
F_34 ( V_9 , F_28 ) ;
V_3 = NULL ;
V_9 = NULL ;
} else
F_31 ( V_3 , V_30 ) ;
}
