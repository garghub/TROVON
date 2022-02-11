static int F_1 ( struct V_1 * V_2 ,
void * V_3 , unsigned long V_4 )
{
unsigned long V_5 = 0 ;
int V_6 = 0 ;
while ( ( V_5 < V_4 ) && ( V_6 < V_2 -> V_7 ) ) {
unsigned long V_8 = ( unsigned long ) V_3 + V_5 ;
unsigned long V_9 ;
int V_10 ;
int V_11 ;
V_10 = V_8 % V_12 ;
V_11 = F_2 ( V_12 - V_10 , V_4 - V_5 ) ;
V_9 = F_3 ( V_8 ) ;
if ( V_9 == ~ 0UL ) {
F_4 ( V_13 L_1 ,
V_14 , V_8 ) ;
return - V_15 ;
}
V_2 -> V_16 [ V_6 ++ ] = V_9 ;
V_5 += V_11 ;
}
if ( V_5 < V_4 ) {
F_4 ( V_13
L_2 ,
V_14 , V_5 , V_4 ) ;
return - V_17 ;
}
while ( V_6 < V_2 -> V_7 )
V_2 -> V_16 [ V_6 ++ ] = V_18 ;
V_2 -> V_19 = V_20 ;
return 0 ;
}
static struct V_1 * F_5 ( T_1 V_21 ,
void * V_3 , unsigned long V_4 )
{
struct V_1 * V_2 ;
unsigned long V_22 = ( unsigned long ) V_3 ;
unsigned long V_23 = V_22 & V_24 ;
unsigned long V_25 = ( V_22 + V_4 ) | ~ V_24 ;
unsigned long V_7 = ( V_25 - V_23 + 1 ) >> V_26 ;
unsigned long V_27 = sizeof( * V_2 ) +
sizeof( V_2 -> V_16 [ 0 ] ) * V_7 ;
if ( sizeof( * V_2 ) > sizeof( void * ) ) {
unsigned long V_28 = F_6 ( V_27 ) ;
V_2 = (struct V_1 * ) F_7 ( V_21 ,
V_28 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_7 =
( ( V_12 << V_28 ) - sizeof( struct V_1 ) ) /
sizeof( * V_2 -> V_16 ) ;
} else {
V_2 = F_8 ( V_27 , V_21 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_7 = V_7 ;
}
return V_2 ;
}
void F_9 ( struct V_29 * V_2 )
{
if ( V_2 && ! ( ( V_30 ) V_2 & V_31 ) ) {
struct V_1 * V_32 = (struct V_1 * ) V_2 ;
if ( sizeof( * V_32 ) > sizeof( void * ) ) {
unsigned long V_27 = sizeof( * V_32 ) +
sizeof( V_32 -> V_16 [ 0 ] ) * V_32 -> V_7 ;
unsigned long V_28 = F_6 ( V_27 ) ;
F_10 ( ( unsigned long ) F_11 ( V_2 ) , V_28 ) ;
} else
F_12 ( F_11 ( V_2 ) ) ;
}
}
static int F_13 ( void * V_3 , unsigned long V_4 ,
struct V_1 * * V_33 , T_1 V_21 )
{
struct V_1 * V_2 ;
int V_34 ;
F_14 ( L_3 , V_14 , V_3 , V_4 ) ;
if ( V_4 == 0 ) {
F_15 ( V_3 != NULL ) ;
* V_33 = NULL ;
return 0 ;
}
F_15 ( V_3 == NULL ) ;
V_2 = F_5 ( V_21 , V_3 , V_4 ) ;
if ( ! V_2 ) {
F_4 ( V_13 L_4 , L_5 ) ;
return - V_35 ;
}
V_34 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_34 ) {
F_4 ( V_13 L_6 , L_7 , V_34 ) ;
F_9 ( (struct V_29 * ) F_16 ( V_2 ) ) ;
return V_34 ;
}
* V_33 = V_2 ;
return 0 ;
}
static struct V_29 * F_17 ( void * V_36 )
{
unsigned long V_9 ;
F_15 ( ! F_18 ( ( unsigned long ) V_36 ) ) ;
V_9 = ( unsigned long ) F_19 ( V_36 ) ;
F_15 ( V_9 & V_31 ) ;
return (struct V_29 * ) ( V_9 | V_31 ) ;
}
static int F_20 ( void * V_3 ,
unsigned long V_4 , struct V_37 * V_38 ,
struct V_1 * * V_33 )
{
int V_34 = 0 ;
struct V_1 * V_2 ;
F_15 ( ( ( unsigned long ) V_38 ) % sizeof( * V_38 ) != 0 ) ;
V_2 = ( void * ) V_38 ;
V_2 -> V_7 = V_39 ;
V_34 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( ! V_34 )
* V_33 = V_2 ;
return V_34 ;
}
struct V_29 * F_21 ( void * V_36 , unsigned long V_4 )
{
int V_34 ;
struct V_1 * V_2 ;
if ( F_18 ( ( unsigned long ) V_36 ) )
return F_17 ( V_36 ) ;
V_34 = F_13 ( V_36 , V_4 , & V_2 , V_40 ) ;
if ( V_34 || V_2 == NULL )
return NULL ;
return F_19 ( V_2 ) ;
}
struct V_29 * F_22 ( void * V_36 , unsigned long V_4 ,
struct V_37 * V_38 )
{
int V_34 ;
struct V_1 * V_2 = NULL ;
if ( F_18 ( ( unsigned long ) V_36 ) )
return F_17 ( V_36 ) ;
V_34 = F_20 ( V_36 , V_4 , V_38 ,
& V_2 ) ;
if ( V_34 )
return NULL ;
return F_19 ( V_2 ) ;
}
