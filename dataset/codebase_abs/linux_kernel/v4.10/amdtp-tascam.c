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
const T_3 * V_22 ;
V_18 = V_5 -> V_9 ;
V_22 = ( void * ) V_17 -> V_23 +
F_5 ( V_17 , V_2 -> V_24 ) ;
V_19 = V_17 -> V_25 - V_2 -> V_24 ;
for ( V_20 = 0 ; V_20 < V_15 ; ++ V_20 ) {
for ( V_21 = 0 ; V_21 < V_18 ; ++ V_21 ) {
V_14 [ V_21 ] = F_6 ( * V_22 << 16 ) ;
V_22 ++ ;
}
V_14 += V_2 -> V_26 ;
if ( -- V_19 == 0 )
V_22 = ( void * ) V_17 -> V_23 ;
}
}
static void F_8 ( struct V_1 * V_2 ,
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
* V_27 = F_9 ( V_14 [ V_21 ] ) ;
V_27 ++ ;
}
V_14 += V_2 -> V_26 ;
if ( -- V_19 == 0 )
V_27 = ( void * ) V_17 -> V_23 ;
}
}
static void F_10 ( struct V_1 * V_2 , T_1 * V_14 ,
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
int F_11 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
int V_29 ;
V_29 = F_12 ( V_17 , 0 , 32 , 24 ) ;
if ( V_29 < 0 )
return V_29 ;
return F_13 ( V_2 , V_17 ) ;
}
void F_14 ( struct V_1 * V_2 , T_4 V_30 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( F_15 ( F_16 ( V_2 ) ) )
return;
switch ( V_30 ) {
default:
F_15 ( 1 ) ;
case V_31 :
if ( V_2 -> V_10 == V_32 ) {
V_5 -> V_33 = F_7 ;
break;
}
F_15 ( 1 ) ;
case V_34 :
if ( V_2 -> V_10 == V_32 )
V_5 -> V_33 = F_4 ;
else
V_5 -> V_33 = F_8 ;
break;
}
}
static unsigned int F_17 ( struct V_1 * V_2 ,
T_1 * V_14 ,
unsigned int V_28 ,
unsigned int * V_35 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_12 * V_13 ;
V_13 = F_18 ( V_2 -> V_13 ) ;
if ( V_28 > 0 && V_13 )
V_5 -> V_33 ( V_2 , V_13 , V_14 , V_28 ) ;
return V_28 ;
}
static unsigned int F_19 ( struct V_1 * V_2 ,
T_1 * V_14 ,
unsigned int V_28 ,
unsigned int * V_35 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_12 * V_13 ;
* V_35 = 0x0000 ;
V_13 = F_18 ( V_2 -> V_13 ) ;
if ( V_13 )
V_5 -> V_33 ( V_2 , V_13 , V_14 , V_28 ) ;
else
F_10 ( V_2 , V_14 , V_28 ) ;
return V_28 ;
}
int F_20 ( struct V_1 * V_2 , struct V_36 * V_37 ,
enum V_38 V_39 , unsigned int V_9 )
{
T_5 V_40 ;
struct V_4 * V_5 ;
unsigned int V_41 ;
int V_29 ;
if ( V_39 == V_11 ) {
V_41 = V_42 ;
V_40 = F_17 ;
} else {
V_41 = V_43 ;
V_40 = F_19 ;
}
V_29 = F_21 ( V_2 , V_37 , V_39 ,
V_44 | V_45 , V_41 ,
V_40 , sizeof( struct V_4 ) ) ;
if ( V_29 < 0 )
return 0 ;
V_2 -> V_46 = 0x00 ;
V_5 = V_2 -> V_6 ;
V_5 -> V_9 = V_9 ;
return 0 ;
}
