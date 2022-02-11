static void
F_1 ( T_1 * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
T_2 * V_4 = & V_3 -> V_4 ;
F_2 ( V_4 -> V_5 ) ;
F_3 ( V_4 -> V_6 ) ;
F_3 ( V_4 -> V_7 ) ;
if ( V_1 -> V_8 ) {
F_3 ( ( V_9 ) V_1 -> V_8 ) ;
}
}
static T_3
F_4 ( const T_1 * V_1 , const T_3 V_10 )
{
const struct V_2 * V_3 = ( const struct V_2 * ) V_1 ;
const T_1 * V_11 = ( const T_1 * ) V_3 -> V_4 . V_5 -> V_12 ;
return F_5 ( V_11 , V_10 ) ;
}
static const T_4 *
F_6 ( T_1 * V_1 , T_3 V_13 , T_3 V_14 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
T_3 V_15 , V_16 ;
T_2 * V_4 ;
T_1 * V_17 = NULL ;
T_3 V_18 ;
T_5 * V_19 ;
V_4 = & V_3 -> V_4 ;
V_16 = F_7 ( V_4 -> V_5 ) ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
if ( V_13 <= V_4 -> V_7 [ V_15 ] ) {
V_19 = F_8 ( V_4 -> V_5 , V_15 ) ;
V_17 = ( T_1 * ) V_19 -> V_12 ;
break;
}
}
if ( ! V_17 ) {
F_9 ( V_13 == V_1 -> V_20 && V_14 == 0 ) ;
return L_1 ;
}
V_18 = V_13 - V_4 -> V_6 [ V_15 ] ;
if ( F_10 ( V_17 , V_18 , V_14 ) ) {
F_9 ( ! V_1 -> V_8 ) ;
return F_11 ( V_17 , V_18 , V_14 ) ;
}
else {
void * V_8 = F_12 ( V_1 -> V_20 ) ;
F_13 ( V_1 , V_8 , 0 , V_1 -> V_20 ) ;
V_1 -> V_8 = ( const T_4 * ) V_8 ;
return V_1 -> V_8 + V_13 ;
}
F_14 () ;
}
static void *
F_15 ( T_1 * V_1 , void * V_21 , T_3 V_13 , T_3 V_14 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
T_4 * V_22 = ( T_4 * ) V_21 ;
T_3 V_15 , V_16 ;
T_2 * V_4 ;
T_1 * V_17 = NULL ;
T_3 V_18 , V_23 ;
T_5 * V_19 ;
V_4 = & V_3 -> V_4 ;
V_16 = F_7 ( V_4 -> V_5 ) ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
if ( V_13 <= V_4 -> V_7 [ V_15 ] ) {
V_19 = F_8 ( V_4 -> V_5 , V_15 ) ;
V_17 = ( T_1 * ) V_19 -> V_12 ;
break;
}
}
if ( ! V_17 ) {
F_9 ( V_13 == V_1 -> V_20 && V_14 == 0 ) ;
return V_22 ;
}
V_18 = V_13 - V_4 -> V_6 [ V_15 ] ;
if ( F_10 ( V_17 , V_18 , V_14 ) ) {
F_9 ( ! V_1 -> V_8 ) ;
return F_13 ( V_17 , V_22 , V_18 , V_14 ) ;
}
else {
V_23 = F_16 ( V_17 , V_18 ) ;
F_9 ( V_23 > 0 ) ;
F_13 ( V_17 , V_22 , V_18 , V_23 ) ;
V_13 += V_23 ;
V_14 -= V_23 ;
if ( V_14 > 0 ) {
F_15 ( V_1 , V_22 + V_23 , V_13 , V_14 ) ;
}
return V_22 ;
}
F_14 () ;
}
T_1 *
F_17 ( void )
{
T_1 * V_1 = F_18 ( & V_24 ) ;
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
T_2 * V_4 = & V_3 -> V_4 ;
V_4 -> V_5 = NULL ;
V_4 -> V_6 = NULL ;
V_4 -> V_7 = NULL ;
return V_1 ;
}
void
F_19 ( T_1 * V_1 , T_1 * V_11 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
T_2 * V_4 ;
F_9 ( V_1 && ! V_1 -> V_25 ) ;
F_9 ( V_1 -> V_26 == & V_24 ) ;
F_9 ( V_11 -> V_20 ) ;
V_4 = & V_3 -> V_4 ;
V_4 -> V_5 = F_20 ( V_4 -> V_5 , V_11 ) ;
}
void
F_21 ( T_1 * V_1 , T_1 * V_11 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
T_2 * V_4 ;
F_9 ( V_1 && ! V_1 -> V_25 ) ;
F_9 ( V_1 -> V_26 == & V_24 ) ;
F_9 ( V_11 -> V_20 ) ;
V_4 = & V_3 -> V_4 ;
V_4 -> V_5 = F_22 ( V_4 -> V_5 , V_11 ) ;
}
void
F_23 ( T_1 * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
T_5 * V_19 ;
T_3 V_16 ;
T_1 * V_17 ;
T_2 * V_4 ;
int V_15 = 0 ;
F_9 ( V_1 && ! V_1 -> V_25 ) ;
F_9 ( V_1 -> V_26 == & V_24 ) ;
F_9 ( V_1 -> V_20 == 0 ) ;
F_9 ( V_1 -> V_27 == 0 ) ;
V_4 = & V_3 -> V_4 ;
V_16 = F_7 ( V_4 -> V_5 ) ;
F_9 ( V_16 ) ;
V_4 -> V_6 = F_24 ( T_3 , V_16 ) ;
V_4 -> V_7 = F_24 ( T_3 , V_16 ) ;
for ( V_19 = V_4 -> V_5 ; V_19 != NULL ; V_19 = V_19 -> V_28 ) {
F_9 ( ( T_3 ) V_15 < V_16 ) ;
V_17 = ( T_1 * ) V_19 -> V_12 ;
V_4 -> V_6 [ V_15 ] = V_1 -> V_20 ;
V_1 -> V_20 += V_17 -> V_20 ;
V_1 -> V_27 += V_17 -> V_27 ;
V_4 -> V_7 [ V_15 ] = V_1 -> V_20 - 1 ;
V_15 ++ ;
}
F_9 ( V_4 -> V_5 ) ;
F_25 ( ( T_1 * ) V_4 -> V_5 -> V_12 , V_1 ) ;
V_1 -> V_25 = TRUE ;
V_1 -> V_29 = V_1 ;
}
