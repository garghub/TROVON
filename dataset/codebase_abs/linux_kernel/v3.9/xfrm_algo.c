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
static inline int F_5 ( void )
{
return F_2 ( V_4 ) ;
}
static struct V_5 * F_6 (
const struct V_6 * V_7 ,
int F_7 ( const struct V_5 * V_8 , const void * V_9 ) ,
const void * V_9 , int V_10 )
{
struct V_5 * V_11 = V_7 -> V_12 ;
int V_13 , V_14 ;
for ( V_13 = 0 ; V_13 < V_7 -> V_15 ; V_13 ++ ) {
if ( ! F_7 ( V_11 + V_13 , V_9 ) )
continue;
if ( V_11 [ V_13 ] . V_16 )
return & V_11 [ V_13 ] ;
if ( ! V_10 )
break;
V_14 = F_8 ( V_11 [ V_13 ] . V_17 , V_7 -> type ,
V_7 -> V_18 ) ;
if ( ! V_14 )
break;
V_11 [ V_13 ] . V_16 = V_14 ;
return & V_11 [ V_13 ] ;
}
return NULL ;
}
static int F_9 ( const struct V_5 * V_8 ,
const void * V_9 )
{
return V_8 -> V_19 . V_20 == ( unsigned long ) V_9 ;
}
struct V_5 * F_10 ( int V_21 )
{
return F_6 ( & V_22 , F_9 ,
( void * ) ( unsigned long ) V_21 , 1 ) ;
}
struct V_5 * F_11 ( int V_21 )
{
return F_6 ( & V_23 , F_9 ,
( void * ) ( unsigned long ) V_21 , 1 ) ;
}
struct V_5 * F_12 ( int V_21 )
{
return F_6 ( & V_24 , F_9 ,
( void * ) ( unsigned long ) V_21 , 1 ) ;
}
static int F_13 ( const struct V_5 * V_8 ,
const void * V_9 )
{
const char * V_17 = V_9 ;
return V_17 && ( ! strcmp ( V_17 , V_8 -> V_17 ) ||
( V_8 -> V_25 && ! strcmp ( V_17 , V_8 -> V_25 ) ) ) ;
}
struct V_5 * F_14 ( const char * V_17 , int V_10 )
{
return F_6 ( & V_22 , F_13 , V_17 ,
V_10 ) ;
}
struct V_5 * F_15 ( const char * V_17 , int V_10 )
{
return F_6 ( & V_23 , F_13 , V_17 ,
V_10 ) ;
}
struct V_5 * F_16 ( const char * V_17 , int V_10 )
{
return F_6 ( & V_24 , F_13 , V_17 ,
V_10 ) ;
}
static int F_17 ( const struct V_5 * V_8 ,
const void * V_9 )
{
const struct V_26 * V_27 = V_9 ;
const char * V_17 = V_27 -> V_17 ;
return V_27 -> V_28 == V_8 -> V_29 . V_27 . V_30 && V_17 &&
! strcmp ( V_17 , V_8 -> V_17 ) ;
}
struct V_5 * F_18 ( const char * V_17 , int V_31 , int V_10 )
{
struct V_26 V_9 = {
. V_17 = V_17 ,
. V_28 = V_31 ,
} ;
return F_6 ( & V_32 , F_17 , & V_9 ,
V_10 ) ;
}
struct V_5 * F_19 ( unsigned int V_33 )
{
if ( V_33 >= F_3 () )
return NULL ;
return & V_2 [ V_33 ] ;
}
struct V_5 * F_20 ( unsigned int V_33 )
{
if ( V_33 >= F_4 () )
return NULL ;
return & V_3 [ V_33 ] ;
}
void F_21 ( void )
{
int V_13 , V_14 ;
F_22 ( F_23 () ) ;
for ( V_13 = 0 ; V_13 < F_3 () ; V_13 ++ ) {
V_14 = F_24 ( V_2 [ V_13 ] . V_17 , 0 ,
V_34 ) ;
if ( V_2 [ V_13 ] . V_16 != V_14 )
V_2 [ V_13 ] . V_16 = V_14 ;
}
for ( V_13 = 0 ; V_13 < F_4 () ; V_13 ++ ) {
V_14 = F_25 ( V_3 [ V_13 ] . V_17 , 0 , 0 ) ;
if ( V_3 [ V_13 ] . V_16 != V_14 )
V_3 [ V_13 ] . V_16 = V_14 ;
}
for ( V_13 = 0 ; V_13 < F_5 () ; V_13 ++ ) {
V_14 = F_26 ( V_4 [ V_13 ] . V_17 , 0 ,
V_34 ) ;
if ( V_4 [ V_13 ] . V_16 != V_14 )
V_4 [ V_13 ] . V_16 = V_14 ;
}
}
int F_27 ( void )
{
int V_13 , V_35 ;
for ( V_13 = 0 , V_35 = 0 ; V_13 < F_3 () ; V_13 ++ )
if ( V_2 [ V_13 ] . V_16 && V_2 [ V_13 ] . V_36 )
V_35 ++ ;
return V_35 ;
}
int F_28 ( void )
{
int V_13 , V_35 ;
for ( V_13 = 0 , V_35 = 0 ; V_13 < F_4 () ; V_13 ++ )
if ( V_3 [ V_13 ] . V_16 && V_3 [ V_13 ] . V_36 )
V_35 ++ ;
return V_35 ;
}
void * F_29 ( struct V_37 * V_38 , struct V_37 * V_39 , int V_40 )
{
if ( V_39 != V_38 ) {
V_38 -> V_41 += V_40 ;
V_38 -> V_40 += V_40 ;
}
return F_30 ( V_39 , V_40 ) ;
}
