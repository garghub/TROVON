struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_1 ;
int V_3 ;
int V_4 ;
V_3 = ( V_2 + V_5 - 1 ) / V_5 ;
V_3 = V_3 ? : 1 ;
V_1 = F_2 ( sizeof( * V_1 ) + V_3 * sizeof( V_6 * ) , V_7 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_8 = V_2 ;
V_1 -> V_3 = V_3 ;
F_3 ( & V_1 -> V_9 , 1 ) ;
if ( V_2 <= V_10 )
V_1 -> V_11 [ 0 ] = V_1 -> V_12 ;
else {
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_6 * V_13 ;
V_13 = ( void * ) F_4 ( V_7 ) ;
if ( ! V_13 )
goto V_14;
V_1 -> V_11 [ V_4 ] = V_13 ;
}
}
return V_1 ;
V_14:
while ( -- V_4 >= 0 ) {
F_5 ( ( unsigned long ) V_1 -> V_11 [ V_4 ] ) ;
}
F_6 ( V_1 ) ;
return NULL ;
}
void F_7 ( struct V_1 * V_1 )
{
if ( V_1 -> V_11 [ 0 ] != V_1 -> V_12 ) {
int V_4 ;
for ( V_4 = 0 ; V_4 < V_1 -> V_3 ; V_4 ++ )
F_5 ( ( unsigned long ) V_1 -> V_11 [ V_4 ] ) ;
}
F_6 ( V_1 ) ;
}
static int F_8 ( V_6 T_1 * V_15 ,
const struct V_1 * V_1 )
{
int V_4 ;
unsigned int V_16 = V_1 -> V_8 ;
for ( V_4 = 0 ; V_4 < V_1 -> V_3 ; V_4 ++ ) {
unsigned int V_17 = F_9 ( V_5 , V_16 ) ;
unsigned int V_18 = V_17 * sizeof( * V_15 ) ;
if ( F_10 ( V_15 , V_1 -> V_11 [ V_4 ] , V_18 ) )
return - V_19 ;
V_15 += V_5 ;
V_16 -= V_17 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_1 ,
V_6 T_1 * V_15 )
{
int V_4 ;
unsigned int V_16 = V_1 -> V_8 ;
for ( V_4 = 0 ; V_4 < V_1 -> V_3 ; V_4 ++ ) {
unsigned int V_17 = F_9 ( V_5 , V_16 ) ;
unsigned int V_18 = V_17 * sizeof( * V_15 ) ;
if ( F_12 ( V_1 -> V_11 [ V_4 ] , V_15 , V_18 ) )
return - V_19 ;
V_15 += V_5 ;
V_16 -= V_17 ;
}
return 0 ;
}
static void F_13 ( struct V_1 * V_1 )
{
int V_20 , V_21 , V_22 ;
int V_2 = V_1 -> V_8 ;
for ( V_22 = 1 ; V_22 < V_2 ; V_22 = 3 * V_22 + 1 )
;
V_22 /= 3 ;
while ( V_22 ) {
V_21 = V_2 - V_22 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
int V_23 = V_20 ;
int V_24 = V_23 + V_22 ;
V_6 V_25 = F_14 ( V_1 , V_24 ) ;
while ( V_23 >= 0 && F_14 ( V_1 , V_23 ) > V_25 ) {
F_14 ( V_1 , V_24 ) =
F_14 ( V_1 , V_23 ) ;
V_24 = V_23 ;
V_23 -= V_22 ;
}
F_14 ( V_1 , V_24 ) = V_25 ;
}
V_22 /= 3 ;
}
}
int F_15 ( const struct V_1 * V_1 , V_6 V_26 )
{
unsigned int V_23 , V_24 ;
if ( ! V_1 )
return 0 ;
V_23 = 0 ;
V_24 = V_1 -> V_8 ;
while ( V_23 < V_24 ) {
unsigned int V_27 = ( V_23 + V_24 ) / 2 ;
if ( V_26 > F_14 ( V_1 , V_27 ) )
V_23 = V_27 + 1 ;
else if ( V_26 < F_14 ( V_1 , V_27 ) )
V_24 = V_27 ;
else
return 1 ;
}
return 0 ;
}
int F_16 ( struct V_28 * V_29 , struct V_1 * V_1 )
{
F_17 ( V_29 -> V_1 ) ;
F_13 ( V_1 ) ;
F_18 ( V_1 ) ;
V_29 -> V_1 = V_1 ;
return 0 ;
}
int F_19 ( struct V_1 * V_1 )
{
struct V_28 * V_29 ;
int V_30 ;
V_29 = F_20 () ;
if ( ! V_29 )
return - V_31 ;
V_30 = F_16 ( V_29 , V_1 ) ;
if ( V_30 < 0 ) {
F_21 ( V_29 ) ;
return V_30 ;
}
return F_22 ( V_29 ) ;
}
int F_23 ( V_6 V_26 )
{
const struct V_28 * V_28 = F_24 () ;
int V_32 = 1 ;
if ( V_26 != V_28 -> V_33 )
V_32 = F_15 ( V_28 -> V_1 , V_26 ) ;
return V_32 ;
}
int F_25 ( V_6 V_26 )
{
const struct V_28 * V_28 = F_24 () ;
int V_32 = 1 ;
if ( V_26 != V_28 -> V_34 )
V_32 = F_15 ( V_28 -> V_1 , V_26 ) ;
return V_32 ;
}
