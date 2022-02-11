int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_8 ;
if ( F_2 ( V_2 ) )
return - V_9 ;
V_6 -> V_4 = V_4 ;
V_8 = V_4 ;
return F_3 ( V_2 , V_3 , V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
T_1 * V_12 , unsigned int V_13 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_14 * V_15 = V_11 -> V_15 ;
unsigned int V_16 , V_17 , V_18 , V_19 ;
const T_2 * V_20 ;
V_16 = V_6 -> V_4 ;
V_20 = ( void * ) V_15 -> V_21 +
F_5 ( V_15 , V_2 -> V_22 ) ;
V_17 = V_15 -> V_23 - V_2 -> V_22 ;
for ( V_18 = 0 ; V_18 < V_13 ; ++ V_18 ) {
for ( V_19 = 0 ; V_19 < V_16 ; ++ V_19 ) {
V_12 [ V_19 ] = F_6 ( * V_20 ) ;
V_20 ++ ;
}
V_12 += V_2 -> V_24 ;
if ( -- V_17 == 0 )
V_20 = ( void * ) V_15 -> V_21 ;
}
}
static void F_7 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
T_1 * V_12 , unsigned int V_13 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_14 * V_15 = V_11 -> V_15 ;
unsigned int V_16 , V_17 , V_18 , V_19 ;
T_2 * V_25 ;
V_16 = V_6 -> V_4 ;
V_25 = ( void * ) V_15 -> V_21 +
F_5 ( V_15 , V_2 -> V_22 ) ;
V_17 = V_15 -> V_23 - V_2 -> V_22 ;
for ( V_18 = 0 ; V_18 < V_13 ; ++ V_18 ) {
for ( V_19 = 0 ; V_19 < V_16 ; ++ V_19 ) {
* V_25 = F_8 ( V_12 [ V_19 ] ) & 0xffffff00 ;
V_25 ++ ;
}
V_12 += V_2 -> V_24 ;
if ( -- V_17 == 0 )
V_25 = ( void * ) V_15 -> V_21 ;
}
}
static void F_9 ( struct V_1 * V_2 ,
T_1 * V_12 , unsigned int V_13 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_18 , V_19 , V_16 = V_6 -> V_4 ;
for ( V_18 = 0 ; V_18 < V_13 ; ++ V_18 ) {
for ( V_19 = 0 ; V_19 < V_16 ; ++ V_19 )
V_12 [ V_19 ] = F_6 ( 0x00000000 ) ;
V_12 += V_2 -> V_24 ;
}
}
int F_10 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
int V_26 ;
V_26 = F_11 ( V_15 , 0 , 32 , 24 ) ;
if ( V_26 < 0 )
return V_26 ;
return F_12 ( V_2 , V_15 ) ;
}
static unsigned int F_13 ( struct V_1 * V_2 ,
T_3 * V_12 ,
unsigned int V_27 ,
unsigned int * V_28 )
{
struct V_10 * V_11 = F_14 ( V_2 -> V_11 ) ;
unsigned int V_29 ;
if ( V_11 ) {
F_4 ( V_2 , V_11 , ( T_1 * ) V_12 , V_27 ) ;
V_29 = V_27 ;
} else {
F_9 ( V_2 , ( T_1 * ) V_12 , V_27 ) ;
V_29 = 0 ;
}
return V_29 ;
}
static unsigned int F_15 ( struct V_1 * V_2 ,
T_3 * V_12 ,
unsigned int V_27 ,
unsigned int * V_28 )
{
struct V_10 * V_11 = F_14 ( V_2 -> V_11 ) ;
unsigned int V_29 ;
if ( V_11 ) {
F_7 ( V_2 , V_11 , ( T_1 * ) V_12 , V_27 ) ;
V_29 = V_27 ;
} else {
V_29 = 0 ;
}
return V_29 ;
}
int F_16 ( struct V_1 * V_2 , struct V_30 * V_31 ,
enum V_32 V_33 )
{
T_4 V_34 ;
if ( V_33 == V_35 )
V_34 = F_15 ;
else
V_34 = F_13 ;
return F_17 ( V_2 , V_31 , V_33 , V_36 , 0 ,
V_34 , sizeof( struct V_5 ) ) ;
}
