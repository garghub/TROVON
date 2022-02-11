void
F_1 ( const struct V_1 * V_2 )
{
T_1 * V_3 = ( T_1 * ) V_2 ;
F_2 ( L_1 , V_4 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] , V_3 [ 3 ] ) ;
}
static inline T_1
F_3 ( const struct V_1 * V_2 )
{
unsigned char * V_5 = ( unsigned char * ) V_2 -> V_6 ;
unsigned int V_7 = V_8 ;
T_1 V_9 = 0 ;
while ( V_7 -- ) {
V_9 *= 37 ;
V_9 += * V_5 ++ ;
}
return V_9 & V_10 ;
}
static struct V_11 *
F_4 ( const struct V_12 * V_13 ,
const struct V_14 * V_15 , const struct V_1 * V_2 ,
long V_16 )
{
struct V_11 * V_17 ;
struct V_18 * V_19 ;
F_5 (d, n, &nfs4_deviceid_cache[hash], node)
if ( V_17 -> V_13 == V_13 && V_17 -> V_14 == V_15 &&
! memcmp ( & V_17 -> V_20 , V_2 , sizeof( * V_2 ) ) ) {
if ( F_6 ( & V_17 -> V_21 ) )
return V_17 ;
else
continue;
}
return NULL ;
}
struct V_11 *
F_7 ( const struct V_12 * V_13 ,
const struct V_14 * V_15 , const struct V_1 * V_2 ,
long V_16 )
{
struct V_11 * V_17 ;
F_8 () ;
V_17 = F_4 ( V_13 , V_15 , V_2 , V_16 ) ;
if ( V_17 && ! F_9 ( & V_17 -> V_21 ) )
V_17 = NULL ;
F_10 () ;
return V_17 ;
}
struct V_11 *
F_11 ( const struct V_12 * V_13 ,
const struct V_14 * V_15 , const struct V_1 * V_2 )
{
return F_7 ( V_13 , V_15 , V_2 , F_3 ( V_2 ) ) ;
}
struct V_11 *
F_12 ( const struct V_12 * V_13 ,
const struct V_14 * V_15 , const struct V_1 * V_2 )
{
struct V_11 * V_17 ;
F_13 ( & V_22 ) ;
F_8 () ;
V_17 = F_4 ( V_13 , V_15 , V_2 , F_3 ( V_2 ) ) ;
F_10 () ;
if ( ! V_17 ) {
F_14 ( & V_22 ) ;
return NULL ;
}
F_15 ( & V_17 -> V_23 ) ;
F_14 ( & V_22 ) ;
F_16 () ;
if ( F_17 ( & V_17 -> V_21 ) )
return V_17 ;
return NULL ;
}
void
F_18 ( const struct V_12 * V_13 ,
const struct V_14 * V_15 , const struct V_1 * V_2 )
{
struct V_11 * V_17 ;
V_17 = F_12 ( V_13 , V_15 , V_2 ) ;
if ( ! V_17 )
return;
V_17 -> V_13 -> V_24 ( V_17 ) ;
}
void
F_19 ( struct V_11 * V_17 ,
const struct V_12 * V_13 ,
const struct V_14 * V_14 ,
const struct V_1 * V_2 )
{
F_20 ( & V_17 -> V_23 ) ;
F_20 ( & V_17 -> V_25 ) ;
V_17 -> V_13 = V_13 ;
V_17 -> V_14 = V_14 ;
V_17 -> V_20 = * V_2 ;
F_21 ( & V_17 -> V_21 , 1 ) ;
}
struct V_11 *
F_22 ( struct V_11 * V_26 )
{
struct V_11 * V_17 ;
long V_16 ;
F_13 ( & V_22 ) ;
V_16 = F_3 ( & V_26 -> V_20 ) ;
V_17 = F_7 ( V_26 -> V_13 , V_26 -> V_14 , & V_26 -> V_20 , V_16 ) ;
if ( V_17 ) {
F_14 ( & V_22 ) ;
return V_17 ;
}
F_23 ( & V_26 -> V_23 , & V_27 [ V_16 ] ) ;
F_14 ( & V_22 ) ;
F_24 ( & V_26 -> V_21 ) ;
return V_26 ;
}
bool
F_25 ( struct V_11 * V_17 )
{
if ( ! F_26 ( & V_17 -> V_21 , & V_22 ) )
return false ;
F_15 ( & V_17 -> V_23 ) ;
F_14 ( & V_22 ) ;
F_16 () ;
V_17 -> V_13 -> V_24 ( V_17 ) ;
return true ;
}
static void
F_27 ( const struct V_14 * V_15 , long V_16 )
{
struct V_11 * V_17 ;
struct V_18 * V_19 ;
F_28 ( V_28 ) ;
F_13 ( & V_22 ) ;
F_8 () ;
F_5 (d, n, &nfs4_deviceid_cache[hash], node)
if ( V_17 -> V_14 == V_15 && F_6 ( & V_17 -> V_21 ) ) {
F_15 ( & V_17 -> V_23 ) ;
F_29 ( & V_17 -> V_25 , & V_28 ) ;
}
F_10 () ;
F_14 ( & V_22 ) ;
if ( F_30 ( & V_28 ) )
return;
F_16 () ;
while ( ! F_30 ( & V_28 ) ) {
V_17 = F_31 ( V_28 . V_29 , struct V_11 , V_25 ) ;
F_32 ( & V_17 -> V_25 ) ;
if ( F_17 ( & V_17 -> V_21 ) )
V_17 -> V_13 -> V_24 ( V_17 ) ;
}
}
void
F_33 ( const struct V_14 * V_15 )
{
long V_30 ;
if ( ! ( V_15 -> V_31 & V_32 ) )
return;
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ )
F_27 ( V_15 , V_30 ) ;
}
