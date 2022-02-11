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
struct V_12 V_13 = { 0 } ;
if ( V_4 ) {
V_10 = F_3 ( V_4 ) ;
V_13 = V_12 ( V_10 ) ;
V_11 = V_14 * V_10 ;
}
if ( V_7 > V_11 )
return NULL ;
V_9 = F_4 ( sizeof( struct V_1 ) , V_8 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_4 = V_4 ;
V_9 -> V_5 = V_7 ;
V_9 -> V_10 = V_10 ;
V_9 -> V_13 = V_13 ;
if ( F_1 ( V_9 ) && ! ( V_8 & V_15 ) )
memset ( & V_9 -> V_16 [ 0 ] , V_17 ,
V_6 ) ;
return V_9 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_18 )
{
return F_6 ( V_18 , V_2 -> V_13 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
int V_19 ;
if ( F_1 ( V_2 ) )
return;
for ( V_19 = 0 ; V_19 < V_14 ; V_19 ++ )
F_8 ( V_2 -> V_16 [ V_19 ] ) ;
}
void F_9 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
}
static unsigned int F_10 ( struct V_1 * V_2 ,
unsigned int V_18 ,
unsigned int V_19 )
{
unsigned int V_20 ;
V_20 = V_18 - V_19 * V_2 -> V_10 ;
return V_20 * V_2 -> V_4 ;
}
static struct V_21 *
F_11 ( struct V_1 * V_2 , int V_19 , T_1 V_8 )
{
struct V_21 * V_22 = V_2 -> V_16 [ V_19 ] ;
if ( ! V_22 ) {
V_22 = F_12 ( sizeof( struct V_21 ) , V_8 ) ;
if ( ! V_22 )
return NULL ;
if ( ! ( V_8 & V_15 ) )
memset ( V_22 , V_17 ,
sizeof( struct V_21 ) ) ;
V_2 -> V_16 [ V_19 ] = V_22 ;
}
return V_22 ;
}
int F_13 ( struct V_1 * V_2 , unsigned int V_18 , void * V_23 ,
T_1 V_8 )
{
int V_19 = 0 ;
struct V_21 * V_22 ;
void * V_24 ;
if ( V_18 >= V_2 -> V_5 )
return - V_25 ;
if ( ! V_2 -> V_4 )
return 0 ;
if ( F_1 ( V_2 ) )
V_22 = (struct V_21 * ) & V_2 -> V_16 [ 0 ] ;
else {
V_19 = F_5 ( V_2 , V_18 ) ;
V_22 = F_11 ( V_2 , V_19 , V_8 ) ;
if ( ! V_22 )
return - V_26 ;
}
V_24 = & V_22 -> V_27 [ F_10 ( V_2 , V_18 , V_19 ) ] ;
memcpy ( V_24 , V_23 , V_2 -> V_4 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , unsigned int V_18 )
{
int V_19 = 0 ;
struct V_21 * V_22 ;
void * V_24 ;
if ( V_18 >= V_2 -> V_5 )
return - V_25 ;
if ( ! V_2 -> V_4 )
return 0 ;
if ( F_1 ( V_2 ) )
V_22 = (struct V_21 * ) & V_2 -> V_16 [ 0 ] ;
else {
V_19 = F_5 ( V_2 , V_18 ) ;
V_22 = V_2 -> V_16 [ V_19 ] ;
if ( ! V_22 )
return - V_28 ;
}
V_24 = & V_22 -> V_27 [ F_10 ( V_2 , V_18 , V_19 ) ] ;
memset ( V_24 , V_17 , V_2 -> V_4 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , unsigned int V_29 ,
unsigned int V_30 , T_1 V_8 )
{
int V_31 ;
int V_32 ;
int V_19 ;
unsigned int V_33 ;
struct V_21 * V_22 ;
if ( ! V_29 && ! V_30 )
return 0 ;
if ( V_29 >= V_2 -> V_5 )
return - V_25 ;
if ( ! V_30 )
return 0 ;
V_33 = V_29 + V_30 - 1 ;
if ( V_33 >= V_2 -> V_5 )
return - V_25 ;
if ( ! V_2 -> V_4 )
return 0 ;
if ( F_1 ( V_2 ) )
return 0 ;
V_31 = F_5 ( V_2 , V_29 ) ;
V_32 = F_5 ( V_2 , V_33 ) ;
for ( V_19 = V_31 ; V_19 <= V_32 ; V_19 ++ ) {
V_22 = F_11 ( V_2 , V_19 , V_8 ) ;
if ( ! V_22 )
return - V_26 ;
}
return 0 ;
}
void * F_16 ( struct V_1 * V_2 , unsigned int V_18 )
{
int V_19 = 0 ;
struct V_21 * V_22 ;
if ( ! V_2 -> V_4 )
return NULL ;
if ( V_18 >= V_2 -> V_5 )
return NULL ;
if ( F_1 ( V_2 ) )
V_22 = (struct V_21 * ) & V_2 -> V_16 [ 0 ] ;
else {
V_19 = F_5 ( V_2 , V_18 ) ;
V_22 = V_2 -> V_16 [ V_19 ] ;
if ( ! V_22 )
return NULL ;
}
return & V_22 -> V_27 [ F_10 ( V_2 , V_18 , V_19 ) ] ;
}
void * F_17 ( struct V_1 * V_2 , unsigned int V_18 )
{
void * * V_34 ;
V_34 = F_16 ( V_2 , V_18 ) ;
if ( ! V_34 )
return NULL ;
return * V_34 ;
}
static int F_18 ( struct V_21 * V_22 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < sizeof( struct V_21 ) ; V_35 ++ )
if ( V_22 -> V_27 [ V_35 ] != V_17 )
return 0 ;
return 1 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
int V_19 ;
int V_9 = 0 ;
if ( ! V_2 -> V_5 || ! V_2 -> V_4 )
return 0 ;
if ( F_1 ( V_2 ) )
return V_9 ;
for ( V_19 = 0 ; V_19 < V_14 ; V_19 ++ ) {
V_22 = V_2 -> V_16 [ V_19 ] ;
if ( ! V_22 )
continue;
if ( F_18 ( V_22 ) ) {
V_2 -> V_16 [ V_19 ] = NULL ;
F_8 ( V_22 ) ;
V_9 ++ ;
}
}
return V_9 ;
}
