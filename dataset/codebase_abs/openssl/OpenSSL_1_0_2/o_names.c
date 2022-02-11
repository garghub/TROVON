static int F_1 ( const void * V_1 , const void * V_2 )
{
int V_3 ;
const T_1 * V_4 = ( const T_1 * ) V_1 ;
const T_1 * V_5 = ( const T_1 * ) V_2 ;
V_3 = V_4 -> type - V_5 -> type ;
if ( V_3 == 0 ) {
if ( ( V_6 != NULL )
&& ( F_2 ( V_6 ) > V_4 -> type ) ) {
V_3 = F_3 ( V_6 ,
V_4 -> type ) -> F_4 ( V_4 -> V_7 , V_5 -> V_7 ) ;
} else
V_3 = strcmp ( V_4 -> V_7 , V_5 -> V_7 ) ;
}
return ( V_3 ) ;
}
static unsigned long F_5 ( const void * V_1 )
{
unsigned long V_3 ;
const T_1 * V_4 = ( const T_1 * ) V_1 ;
if ( ( V_6 != NULL )
&& ( F_2 ( V_6 ) > V_4 -> type ) ) {
V_3 =
F_3 ( V_6 ,
V_4 -> type ) -> F_6 ( V_4 -> V_7 ) ;
} else {
V_3 = F_7 ( V_4 -> V_7 ) ;
}
V_3 ^= V_4 -> type ;
return ( V_3 ) ;
}
const char * F_8 ( const char * V_7 , int type )
{
T_1 V_8 , * V_3 ;
int V_9 = 0 , V_10 ;
if ( V_7 == NULL )
return ( NULL ) ;
if ( ( V_11 == NULL ) && ! F_9 () )
return ( NULL ) ;
V_10 = type & V_12 ;
type &= ~ V_12 ;
V_8 . V_7 = V_7 ;
V_8 . type = type ;
for (; ; ) {
V_3 = F_10 ( V_11 , & V_8 ) ;
if ( V_3 == NULL )
return ( NULL ) ;
if ( ( V_3 -> V_10 ) && ! V_10 ) {
if ( ++ V_9 > 10 )
return ( NULL ) ;
V_8 . V_7 = V_3 -> V_13 ;
} else {
return ( V_3 -> V_13 ) ;
}
}
}
int F_11 ( const char * V_7 , int type , const char * V_13 )
{
T_1 * V_14 , * V_3 ;
int V_10 ;
if ( ( V_11 == NULL ) && ! F_9 () )
return ( 0 ) ;
V_10 = type & V_12 ;
type &= ~ V_12 ;
V_14 = ( T_1 * ) F_12 ( sizeof( T_1 ) ) ;
if ( V_14 == NULL ) {
return ( 0 ) ;
}
V_14 -> V_7 = V_7 ;
V_14 -> V_10 = V_10 ;
V_14 -> type = type ;
V_14 -> V_13 = V_13 ;
V_3 = F_13 ( V_11 , V_14 ) ;
if ( V_3 != NULL ) {
if ( ( V_6 != NULL )
&& ( F_2 ( V_6 ) > V_3 -> type ) ) {
F_3 ( V_6 ,
V_3 -> type ) -> F_14 ( V_3 -> V_7 , V_3 -> type ,
V_3 -> V_13 ) ;
}
F_15 ( V_3 ) ;
} else {
if ( F_16 ( V_11 ) ) {
return ( 0 ) ;
}
}
return ( 1 ) ;
}
int F_17 ( const char * V_7 , int type )
{
T_1 V_8 , * V_3 ;
if ( V_11 == NULL )
return ( 0 ) ;
type &= ~ V_12 ;
V_8 . V_7 = V_7 ;
V_8 . type = type ;
V_3 = F_18 ( V_11 , & V_8 ) ;
if ( V_3 != NULL ) {
if ( ( V_6 != NULL )
&& ( F_2 ( V_6 ) > V_3 -> type ) ) {
F_3 ( V_6 ,
V_3 -> type ) -> F_14 ( V_3 -> V_7 , V_3 -> type ,
V_3 -> V_13 ) ;
}
F_15 ( V_3 ) ;
return ( 1 ) ;
} else
return ( 0 ) ;
}
static void F_19 ( const T_1 * V_7 , struct V_15 * V_16 )
{
if ( V_7 -> type == V_16 -> type )
V_16 -> V_17 ( V_7 , V_16 -> V_18 ) ;
}
static void F_20 ( const T_1 * V_7 , void * V_19 )
{
struct V_20 * V_16 = V_19 ;
if ( V_7 -> type != V_16 -> type )
return;
V_16 -> V_21 [ V_16 -> V_22 ++ ] = V_7 ;
}
static int F_21 ( const void * V_23 , const void * V_24 )
{
const T_1 * const * V_25 = V_23 ;
const T_1 * const * V_26 = V_24 ;
return strcmp ( ( * V_25 ) -> V_7 , ( * V_26 ) -> V_7 ) ;
}
void F_22 ( int type ,
void (* V_17) ( const T_1 * , void * V_18 ) ,
void * V_18 )
{
struct V_20 V_16 ;
int V_22 ;
V_16 . type = type ;
V_16 . V_21 =
F_12 ( F_23 ( V_11 ) * sizeof * V_16 . V_21 ) ;
V_16 . V_22 = 0 ;
F_24 ( type , F_20 , & V_16 ) ;
qsort ( ( void * ) V_16 . V_21 , V_16 . V_22 , sizeof * V_16 . V_21 , F_21 ) ;
for ( V_22 = 0 ; V_22 < V_16 . V_22 ; ++ V_22 )
V_17 ( V_16 . V_21 [ V_22 ] , V_18 ) ;
F_15 ( ( void * ) V_16 . V_21 ) ;
}
static void F_25 ( T_1 * V_14 )
{
if ( V_14 == NULL )
return;
if ( V_27 < 0 || V_27 == V_14 -> type )
F_17 ( V_14 -> V_7 , V_14 -> type ) ;
}
