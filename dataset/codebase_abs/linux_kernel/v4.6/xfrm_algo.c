static inline int F_1 ( void )
{
return F_2 ( V_1 ) ;
}
static inline int F_3 ( void )
{
return F_2 ( V_2 ) ;
}
static inline int F_4 ( void )
{
return F_2 ( V_3 ) ;
}
static struct V_4 * F_5 (
const struct V_5 * V_6 ,
int F_6 ( const struct V_4 * V_7 , const void * V_8 ) ,
const void * V_8 , int V_9 )
{
struct V_4 * V_10 = V_6 -> V_11 ;
int V_12 , V_13 ;
for ( V_12 = 0 ; V_12 < V_6 -> V_14 ; V_12 ++ ) {
if ( ! F_6 ( V_10 + V_12 , V_8 ) )
continue;
if ( V_10 [ V_12 ] . V_15 )
return & V_10 [ V_12 ] ;
if ( ! V_9 )
break;
V_13 = F_7 ( V_10 [ V_12 ] . V_16 , V_6 -> type ,
V_6 -> V_17 ) ;
if ( ! V_13 )
break;
V_10 [ V_12 ] . V_15 = V_13 ;
return & V_10 [ V_12 ] ;
}
return NULL ;
}
static int F_8 ( const struct V_4 * V_7 ,
const void * V_8 )
{
return V_7 -> V_18 . V_19 == ( unsigned long ) V_8 ;
}
struct V_4 * F_9 ( int V_20 )
{
return F_5 ( & V_21 , F_8 ,
( void * ) ( unsigned long ) V_20 , 1 ) ;
}
struct V_4 * F_10 ( int V_20 )
{
return F_5 ( & V_22 , F_8 ,
( void * ) ( unsigned long ) V_20 , 1 ) ;
}
struct V_4 * F_11 ( int V_20 )
{
return F_5 ( & V_23 , F_8 ,
( void * ) ( unsigned long ) V_20 , 1 ) ;
}
static int F_12 ( const struct V_4 * V_7 ,
const void * V_8 )
{
const char * V_16 = V_8 ;
return V_16 && ( ! strcmp ( V_16 , V_7 -> V_16 ) ||
( V_7 -> V_24 && ! strcmp ( V_16 , V_7 -> V_24 ) ) ) ;
}
struct V_4 * F_13 ( const char * V_16 , int V_9 )
{
return F_5 ( & V_21 , F_12 , V_16 ,
V_9 ) ;
}
struct V_4 * F_14 ( const char * V_16 , int V_9 )
{
return F_5 ( & V_22 , F_12 , V_16 ,
V_9 ) ;
}
struct V_4 * F_15 ( const char * V_16 , int V_9 )
{
return F_5 ( & V_23 , F_12 , V_16 ,
V_9 ) ;
}
static int F_16 ( const struct V_4 * V_7 ,
const void * V_8 )
{
const struct V_25 * V_26 = V_8 ;
const char * V_16 = V_26 -> V_16 ;
return V_26 -> V_27 == V_7 -> V_28 . V_26 . V_29 && V_16 &&
! strcmp ( V_16 , V_7 -> V_16 ) ;
}
struct V_4 * F_17 ( const char * V_16 , int V_30 , int V_9 )
{
struct V_25 V_8 = {
. V_16 = V_16 ,
. V_27 = V_30 ,
} ;
return F_5 ( & V_31 , F_16 , & V_8 ,
V_9 ) ;
}
struct V_4 * F_18 ( unsigned int V_32 )
{
if ( V_32 >= F_1 () )
return NULL ;
return & V_1 [ V_32 ] ;
}
struct V_4 * F_19 ( unsigned int V_32 )
{
if ( V_32 >= F_3 () )
return NULL ;
return & V_2 [ V_32 ] ;
}
void F_20 ( void )
{
int V_12 , V_13 ;
F_21 ( F_22 () ) ;
for ( V_12 = 0 ; V_12 < F_1 () ; V_12 ++ ) {
V_13 = F_23 ( V_1 [ V_12 ] . V_16 , 0 , 0 ) ;
if ( V_1 [ V_12 ] . V_15 != V_13 )
V_1 [ V_12 ] . V_15 = V_13 ;
}
for ( V_12 = 0 ; V_12 < F_3 () ; V_12 ++ ) {
V_13 = F_24 ( V_2 [ V_12 ] . V_16 , 0 , 0 ) ;
if ( V_2 [ V_12 ] . V_15 != V_13 )
V_2 [ V_12 ] . V_15 = V_13 ;
}
for ( V_12 = 0 ; V_12 < F_4 () ; V_12 ++ ) {
V_13 = F_25 ( V_3 [ V_12 ] . V_16 , 0 ,
V_33 ) ;
if ( V_3 [ V_12 ] . V_15 != V_13 )
V_3 [ V_12 ] . V_15 = V_13 ;
}
}
int F_26 ( void )
{
int V_12 , V_34 ;
for ( V_12 = 0 , V_34 = 0 ; V_12 < F_1 () ; V_12 ++ )
if ( V_1 [ V_12 ] . V_15 && V_1 [ V_12 ] . V_35 )
V_34 ++ ;
return V_34 ;
}
int F_27 ( void )
{
int V_12 , V_34 ;
for ( V_12 = 0 , V_34 = 0 ; V_12 < F_3 () ; V_12 ++ )
if ( V_2 [ V_12 ] . V_15 && V_2 [ V_12 ] . V_35 )
V_34 ++ ;
return V_34 ;
}
