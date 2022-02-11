static unsigned int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 , V_8 = 0 , V_9 , V_10 = V_4 -> V_11 ;
const T_1 * V_12 ;
const int V_13 = V_2 -> V_14 & V_15 ;
for (; ; ) {
V_9 = V_2 -> V_16 ( V_10 , & V_12 , V_2 , V_4 ) ;
if ( F_3 ( V_9 == 0 ) )
break;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
while ( V_8 > 0 && V_6 -> V_17 [ V_8 ]
!= ( V_13 ? toupper ( V_12 [ V_7 ] ) : V_12 [ V_7 ] ) )
V_8 = V_6 -> V_18 [ V_8 - 1 ] ;
if ( V_6 -> V_17 [ V_8 ]
== ( V_13 ? toupper ( V_12 [ V_7 ] ) : V_12 [ V_7 ] ) )
V_8 ++ ;
if ( F_3 ( V_8 == V_6 -> V_19 ) ) {
V_4 -> V_11 = V_10 + V_7 + 1 ;
return V_4 -> V_11 - V_6 -> V_19 ;
}
}
V_10 += V_9 ;
}
return V_20 ;
}
static inline void F_4 ( const T_1 * V_17 , unsigned int V_21 ,
unsigned int * V_18 , int V_14 )
{
unsigned int V_22 , V_8 ;
const T_1 V_13 = V_14 & V_15 ;
for ( V_22 = 0 , V_8 = 1 ; V_8 < V_21 ; V_8 ++ ) {
while ( V_22 > 0 && ( V_13 ? toupper ( V_17 [ V_22 ] ) : V_17 [ V_22 ] )
!= ( V_13 ? toupper ( V_17 [ V_8 ] ) : V_17 [ V_8 ] ) )
V_22 = V_18 [ V_22 - 1 ] ;
if ( ( V_13 ? toupper ( V_17 [ V_22 ] ) : V_17 [ V_22 ] )
== ( V_13 ? toupper ( V_17 [ V_8 ] ) : V_17 [ V_8 ] ) )
V_22 ++ ;
V_18 [ V_8 ] = V_22 ;
}
}
static struct V_1 * F_5 ( const void * V_17 , unsigned int V_21 ,
T_2 V_23 , int V_14 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
int V_7 ;
unsigned int V_24 = V_21 * sizeof( unsigned int ) ;
T_3 V_25 = sizeof( * V_6 ) + V_21 + V_24 ;
V_2 = F_6 ( V_25 , V_23 ) ;
if ( F_7 ( V_2 ) )
return V_2 ;
V_2 -> V_14 = V_14 ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_19 = V_21 ;
F_4 ( V_17 , V_21 , V_6 -> V_18 , V_14 ) ;
V_6 -> V_17 = ( T_1 * ) V_6 -> V_18 + V_24 ;
if ( V_14 & V_15 )
for ( V_7 = 0 ; V_7 < V_21 ; V_7 ++ )
V_6 -> V_17 [ V_7 ] = toupper ( ( ( T_1 * ) V_17 ) [ V_7 ] ) ;
else
memcpy ( V_6 -> V_17 , V_17 , V_21 ) ;
return V_2 ;
}
static void * F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_17 ;
}
static unsigned int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_19 ;
}
static int T_4 F_10 ( void )
{
return F_11 ( & V_26 ) ;
}
static void T_5 F_12 ( void )
{
F_13 ( & V_26 ) ;
}
