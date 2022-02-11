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
F_5 (d, &nfs4_deviceid_cache[hash], node)
if ( V_17 -> V_13 == V_13 && V_17 -> V_14 == V_15 &&
! memcmp ( & V_17 -> V_18 , V_2 , sizeof( * V_2 ) ) ) {
if ( F_6 ( & V_17 -> V_19 ) )
return V_17 ;
else
continue;
}
return NULL ;
}
static struct V_11 *
F_7 ( const struct V_12 * V_13 ,
const struct V_14 * V_15 , const struct V_1 * V_2 ,
long V_16 )
{
struct V_11 * V_17 ;
F_8 () ;
V_17 = F_4 ( V_13 , V_15 , V_2 , V_16 ) ;
if ( V_17 != NULL )
F_9 ( & V_17 -> V_19 ) ;
F_10 () ;
return V_17 ;
}
struct V_11 *
F_11 ( const struct V_12 * V_13 ,
const struct V_14 * V_15 , const struct V_1 * V_2 )
{
return F_7 ( V_13 , V_15 , V_2 , F_3 ( V_2 ) ) ;
}
void
F_12 ( const struct V_12 * V_13 ,
const struct V_14 * V_15 , const struct V_1 * V_2 )
{
struct V_11 * V_17 ;
F_13 ( & V_20 ) ;
F_8 () ;
V_17 = F_4 ( V_13 , V_15 , V_2 , F_3 ( V_2 ) ) ;
F_10 () ;
if ( ! V_17 ) {
F_14 ( & V_20 ) ;
return;
}
F_15 ( & V_17 -> V_21 ) ;
F_14 ( & V_20 ) ;
F_16 () ;
if ( F_17 ( & V_17 -> V_19 ) )
V_17 -> V_13 -> V_22 ( V_17 ) ;
}
void
F_18 ( struct V_11 * V_17 ,
const struct V_12 * V_13 ,
const struct V_14 * V_14 ,
const struct V_1 * V_2 )
{
F_19 ( & V_17 -> V_21 ) ;
F_19 ( & V_17 -> V_23 ) ;
V_17 -> V_13 = V_13 ;
V_17 -> V_14 = V_14 ;
V_17 -> V_24 = 0 ;
V_17 -> V_18 = * V_2 ;
F_20 ( & V_17 -> V_19 , 1 ) ;
}
struct V_11 *
F_21 ( struct V_11 * V_25 )
{
struct V_11 * V_17 ;
long V_16 ;
F_13 ( & V_20 ) ;
V_16 = F_3 ( & V_25 -> V_18 ) ;
V_17 = F_7 ( V_25 -> V_13 , V_25 -> V_14 , & V_25 -> V_18 , V_16 ) ;
if ( V_17 ) {
F_14 ( & V_20 ) ;
return V_17 ;
}
F_22 ( & V_25 -> V_21 , & V_26 [ V_16 ] ) ;
F_14 ( & V_20 ) ;
F_9 ( & V_25 -> V_19 ) ;
return V_25 ;
}
bool
F_23 ( struct V_11 * V_17 )
{
if ( ! F_17 ( & V_17 -> V_19 ) )
return false ;
V_17 -> V_13 -> V_22 ( V_17 ) ;
return true ;
}
void
F_24 ( struct V_11 * V_21 )
{
V_21 -> V_27 = V_28 ;
F_25 ( V_29 , & V_21 -> V_24 ) ;
}
bool
F_26 ( struct V_11 * V_21 )
{
if ( F_27 ( V_29 , & V_21 -> V_24 ) ) {
unsigned long V_30 , V_31 ;
V_31 = V_28 ;
V_30 = V_31 - V_32 ;
if ( F_28 ( V_21 -> V_27 , V_30 , V_31 ) )
return true ;
F_29 ( V_29 , & V_21 -> V_24 ) ;
}
return false ;
}
static void
F_30 ( const struct V_14 * V_15 , long V_16 )
{
struct V_11 * V_17 ;
F_31 ( V_33 ) ;
F_13 ( & V_20 ) ;
F_8 () ;
F_5 (d, &nfs4_deviceid_cache[hash], node)
if ( V_17 -> V_14 == V_15 && F_6 ( & V_17 -> V_19 ) ) {
F_15 ( & V_17 -> V_21 ) ;
F_32 ( & V_17 -> V_23 , & V_33 ) ;
}
F_10 () ;
F_14 ( & V_20 ) ;
if ( F_33 ( & V_33 ) )
return;
F_16 () ;
while ( ! F_33 ( & V_33 ) ) {
V_17 = F_34 ( V_33 . V_34 , struct V_11 , V_23 ) ;
F_35 ( & V_17 -> V_23 ) ;
if ( F_17 ( & V_17 -> V_19 ) )
V_17 -> V_13 -> V_22 ( V_17 ) ;
}
}
void
F_36 ( const struct V_14 * V_15 )
{
long V_35 ;
if ( ! ( V_15 -> V_36 & V_37 ) )
return;
for ( V_35 = 0 ; V_35 < V_38 ; V_35 ++ )
F_30 ( V_15 , V_35 ) ;
}
void
F_37 ( struct V_14 * V_15 )
{
struct V_11 * V_17 ;
int V_39 ;
F_8 () ;
for ( V_39 = 0 ; V_39 < V_38 ; V_39 ++ ) {
F_5 (d, &nfs4_deviceid_cache[i], node)
if ( V_17 -> V_14 == V_15 )
F_25 ( V_40 , & V_17 -> V_24 ) ;
}
F_10 () ;
}
