int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_7 ;
if ( F_2 ( V_2 ) )
return - V_8 ;
V_7 = V_5 -> V_9 ;
if ( V_2 -> V_10 == V_11 )
V_7 += 2 ;
return F_3 ( V_2 , V_3 , V_7 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
T_1 * V_14 , unsigned int V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_16 * V_17 = V_13 -> V_17 ;
unsigned int V_18 , V_19 , V_20 , V_21 ;
const T_2 * V_22 ;
V_18 = V_5 -> V_9 ;
V_22 = ( void * ) V_17 -> V_23 +
F_5 ( V_17 , V_2 -> V_24 ) ;
V_19 = V_17 -> V_25 - V_2 -> V_24 ;
for ( V_20 = 0 ; V_20 < V_15 ; ++ V_20 ) {
for ( V_21 = 0 ; V_21 < V_18 ; ++ V_21 ) {
V_14 [ V_21 ] = F_6 ( * V_22 ) ;
V_22 ++ ;
}
V_14 += V_2 -> V_26 ;
if ( -- V_19 == 0 )
V_22 = ( void * ) V_17 -> V_23 ;
}
}
static void F_7 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
T_1 * V_14 , unsigned int V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_16 * V_17 = V_13 -> V_17 ;
unsigned int V_18 , V_19 , V_20 , V_21 ;
T_2 * V_27 ;
V_18 = V_5 -> V_9 ;
V_27 = ( void * ) V_17 -> V_23 +
F_5 ( V_17 , V_2 -> V_24 ) ;
V_19 = V_17 -> V_25 - V_2 -> V_24 ;
V_14 += 1 ;
for ( V_20 = 0 ; V_20 < V_15 ; ++ V_20 ) {
for ( V_21 = 0 ; V_21 < V_18 ; ++ V_21 ) {
* V_27 = F_8 ( V_14 [ V_21 ] ) ;
V_27 ++ ;
}
V_14 += V_2 -> V_26 ;
if ( -- V_19 == 0 )
V_27 = ( void * ) V_17 -> V_23 ;
}
}
static void F_9 ( struct V_1 * V_2 , T_1 * V_14 ,
unsigned int V_28 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_18 , V_20 , V_21 ;
V_18 = V_5 -> V_9 ;
for ( V_20 = 0 ; V_20 < V_28 ; ++ V_20 ) {
for ( V_21 = 0 ; V_21 < V_18 ; ++ V_21 )
V_14 [ V_21 ] = 0x00000000 ;
V_14 += V_2 -> V_26 ;
}
}
int F_10 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
int V_29 ;
V_29 = F_11 ( V_17 , 0 , 32 , 24 ) ;
if ( V_29 < 0 )
return V_29 ;
return F_12 ( V_2 , V_17 ) ;
}
static unsigned int F_13 ( struct V_1 * V_2 ,
T_1 * V_14 ,
unsigned int V_28 ,
unsigned int * V_30 )
{
struct V_12 * V_13 ;
V_13 = F_14 ( V_2 -> V_13 ) ;
if ( V_28 > 0 && V_13 )
F_7 ( V_2 , V_13 , V_14 , V_28 ) ;
return V_28 ;
}
static unsigned int F_15 ( struct V_1 * V_2 ,
T_1 * V_14 ,
unsigned int V_28 ,
unsigned int * V_30 )
{
struct V_12 * V_13 ;
* V_30 = 0x0000 ;
V_13 = F_14 ( V_2 -> V_13 ) ;
if ( V_13 )
F_4 ( V_2 , V_13 , V_14 , V_28 ) ;
else
F_9 ( V_2 , V_14 , V_28 ) ;
return V_28 ;
}
int F_16 ( struct V_1 * V_2 , struct V_31 * V_32 ,
enum V_33 V_34 , unsigned int V_9 )
{
T_3 V_35 ;
struct V_4 * V_5 ;
unsigned int V_36 ;
int V_29 ;
if ( V_34 == V_11 ) {
V_36 = V_37 ;
V_35 = F_13 ;
} else {
V_36 = V_38 ;
V_35 = F_15 ;
}
V_29 = F_17 ( V_2 , V_32 , V_34 ,
V_39 | V_40 , V_36 ,
V_35 , sizeof( struct V_4 ) ) ;
if ( V_29 < 0 )
return 0 ;
V_2 -> V_41 = 0x00 ;
V_5 = V_2 -> V_6 ;
V_5 -> V_9 = V_9 ;
return 0 ;
}
