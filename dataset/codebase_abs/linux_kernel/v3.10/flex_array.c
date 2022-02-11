static inline int F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 * V_2 -> V_5 ;
if ( V_3 <= V_6 )
return 1 ;
return 0 ;
}
struct V_1 * F_2 ( int V_4 , unsigned int V_7 ,
T_1 V_8 )
{
struct V_1 * V_9 ;
int V_10 = 0 ;
int V_11 = 0 ;
int V_12 = 0 ;
if ( V_4 ) {
V_10 = F_3 ( V_4 ) ;
V_11 = F_4 ( V_10 ) ;
V_12 = V_13 * V_10 ;
}
if ( V_7 > V_12 )
return NULL ;
V_9 = F_5 ( sizeof( struct V_1 ) , V_8 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_4 = V_4 ;
V_9 -> V_5 = V_7 ;
V_9 -> V_10 = V_10 ;
V_9 -> V_11 = V_11 ;
if ( F_1 ( V_9 ) && ! ( V_8 & V_14 ) )
memset ( & V_9 -> V_15 [ 0 ] , V_16 ,
V_6 ) ;
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_17 )
{
return F_7 ( V_17 , V_2 -> V_11 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
int V_18 ;
if ( F_1 ( V_2 ) )
return;
for ( V_18 = 0 ; V_18 < V_13 ; V_18 ++ )
F_9 ( V_2 -> V_15 [ V_18 ] ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
}
static unsigned int F_11 ( struct V_1 * V_2 ,
unsigned int V_17 ,
unsigned int V_18 )
{
unsigned int V_19 ;
V_19 = V_17 - V_18 * V_2 -> V_10 ;
return V_19 * V_2 -> V_4 ;
}
static struct V_20 *
F_12 ( struct V_1 * V_2 , int V_18 , T_1 V_8 )
{
struct V_20 * V_21 = V_2 -> V_15 [ V_18 ] ;
if ( ! V_21 ) {
V_21 = F_13 ( sizeof( struct V_20 ) , V_8 ) ;
if ( ! V_21 )
return NULL ;
if ( ! ( V_8 & V_14 ) )
memset ( V_21 , V_16 ,
sizeof( struct V_20 ) ) ;
V_2 -> V_15 [ V_18 ] = V_21 ;
}
return V_21 ;
}
int F_14 ( struct V_1 * V_2 , unsigned int V_17 , void * V_22 ,
T_1 V_8 )
{
int V_18 = 0 ;
struct V_20 * V_21 ;
void * V_23 ;
if ( V_17 >= V_2 -> V_5 )
return - V_24 ;
if ( ! V_2 -> V_4 )
return 0 ;
if ( F_1 ( V_2 ) )
V_21 = (struct V_20 * ) & V_2 -> V_15 [ 0 ] ;
else {
V_18 = F_6 ( V_2 , V_17 ) ;
V_21 = F_12 ( V_2 , V_18 , V_8 ) ;
if ( ! V_21 )
return - V_25 ;
}
V_23 = & V_21 -> V_26 [ F_11 ( V_2 , V_17 , V_18 ) ] ;
memcpy ( V_23 , V_22 , V_2 -> V_4 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , unsigned int V_17 )
{
int V_18 = 0 ;
struct V_20 * V_21 ;
void * V_23 ;
if ( V_17 >= V_2 -> V_5 )
return - V_24 ;
if ( ! V_2 -> V_4 )
return 0 ;
if ( F_1 ( V_2 ) )
V_21 = (struct V_20 * ) & V_2 -> V_15 [ 0 ] ;
else {
V_18 = F_6 ( V_2 , V_17 ) ;
V_21 = V_2 -> V_15 [ V_18 ] ;
if ( ! V_21 )
return - V_27 ;
}
V_23 = & V_21 -> V_26 [ F_11 ( V_2 , V_17 , V_18 ) ] ;
memset ( V_23 , V_16 , V_2 -> V_4 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , unsigned int V_28 ,
unsigned int V_29 , T_1 V_8 )
{
int V_30 ;
int V_31 ;
int V_18 ;
unsigned int V_32 ;
struct V_20 * V_21 ;
if ( ! V_28 && ! V_29 )
return 0 ;
if ( V_28 >= V_2 -> V_5 )
return - V_24 ;
if ( ! V_29 )
return 0 ;
V_32 = V_28 + V_29 - 1 ;
if ( V_32 >= V_2 -> V_5 )
return - V_24 ;
if ( ! V_2 -> V_4 )
return 0 ;
if ( F_1 ( V_2 ) )
return 0 ;
V_30 = F_6 ( V_2 , V_28 ) ;
V_31 = F_6 ( V_2 , V_32 ) ;
for ( V_18 = V_30 ; V_18 <= V_31 ; V_18 ++ ) {
V_21 = F_12 ( V_2 , V_18 , V_8 ) ;
if ( ! V_21 )
return - V_25 ;
}
return 0 ;
}
void * F_17 ( struct V_1 * V_2 , unsigned int V_17 )
{
int V_18 = 0 ;
struct V_20 * V_21 ;
if ( ! V_2 -> V_4 )
return NULL ;
if ( V_17 >= V_2 -> V_5 )
return NULL ;
if ( F_1 ( V_2 ) )
V_21 = (struct V_20 * ) & V_2 -> V_15 [ 0 ] ;
else {
V_18 = F_6 ( V_2 , V_17 ) ;
V_21 = V_2 -> V_15 [ V_18 ] ;
if ( ! V_21 )
return NULL ;
}
return & V_21 -> V_26 [ F_11 ( V_2 , V_17 , V_18 ) ] ;
}
void * F_18 ( struct V_1 * V_2 , unsigned int V_17 )
{
void * * V_33 ;
V_33 = F_17 ( V_2 , V_17 ) ;
if ( ! V_33 )
return NULL ;
return * V_33 ;
}
static int F_19 ( struct V_20 * V_21 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < sizeof( struct V_20 ) ; V_34 ++ )
if ( V_21 -> V_26 [ V_34 ] != V_16 )
return 0 ;
return 1 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
int V_18 ;
int V_9 = 0 ;
if ( ! V_2 -> V_5 || ! V_2 -> V_4 )
return 0 ;
if ( F_1 ( V_2 ) )
return V_9 ;
for ( V_18 = 0 ; V_18 < V_13 ; V_18 ++ ) {
V_21 = V_2 -> V_15 [ V_18 ] ;
if ( ! V_21 )
continue;
if ( F_19 ( V_21 ) ) {
V_2 -> V_15 [ V_18 ] = NULL ;
F_9 ( V_21 ) ;
V_9 ++ ;
}
}
return V_9 ;
}
