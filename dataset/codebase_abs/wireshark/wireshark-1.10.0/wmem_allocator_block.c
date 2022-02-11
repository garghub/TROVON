static void
F_1 ( T_1 * V_1 )
{
T_2 V_2 = 0 ;
F_2 ( V_1 -> V_3 == 0 ) ;
do {
V_2 += V_1 -> V_4 ;
if ( F_3 ( V_1 ) ) {
F_2 ( V_1 -> V_4 == F_3 ( V_1 ) -> V_3 ) ;
}
V_1 = F_3 ( V_1 ) ;
} while ( V_1 );
F_2 ( V_2 == V_5 ) ;
}
static void
F_4 ( T_3 * V_6 )
{
T_4 V_7 = FALSE ;
T_1 * V_8 ;
T_5 * V_9 ;
if ( V_6 -> V_10 == NULL ) {
V_7 = TRUE ;
}
V_8 = V_6 -> V_11 ;
F_2 ( F_5 ( V_8 ) -> V_3 == NULL ) ;
while ( V_8 ) {
V_9 = F_5 ( V_8 ) ;
if ( V_8 == V_6 -> V_10 ) {
V_7 = TRUE ;
}
F_2 ( V_9 -> V_12 ) ;
if ( V_9 -> V_13 ) {
F_2 ( F_5 ( V_9 -> V_13 ) -> V_3 == V_8 ) ;
}
V_8 = V_9 -> V_13 ;
}
F_2 ( V_7 ) ;
}
void
F_6 ( T_6 * V_6 )
{
T_7 * V_14 ;
T_3 * V_15 ;
F_2 ( V_6 -> type == V_16 ) ;
V_15 = ( T_3 * ) V_6 -> V_17 ;
if ( V_15 -> V_18 == NULL ) {
F_2 ( ! V_15 -> V_11 ) ;
F_2 ( ! V_15 -> V_10 ) ;
return;
}
F_4 ( V_15 ) ;
V_14 = V_15 -> V_18 ;
while ( V_14 ) {
F_1 ( ( T_1 * ) V_14 -> V_19 ) ;
V_14 = V_14 -> V_13 ;
}
}
static void
F_7 ( T_3 * V_6 ,
T_1 * V_1 )
{
T_5 * V_20 ;
F_2 ( ! V_1 -> V_21 ) ;
if ( F_8 ( V_1 ) < sizeof( T_5 ) ) {
return;
}
V_20 = F_5 ( V_1 ) ;
if ( ! V_20 -> V_12 ) {
return;
}
if ( V_20 -> V_3 ) {
F_2 ( F_5 ( V_20 -> V_3 ) -> V_12 ) ;
F_2 ( F_5 ( V_20 -> V_3 ) -> V_13 == V_1 ) ;
F_5 ( V_20 -> V_3 ) -> V_13 = V_20 -> V_13 ;
}
else {
F_2 ( V_6 -> V_11 == V_1 ) ;
V_6 -> V_11 = V_20 -> V_13 ;
}
if ( V_20 -> V_13 ) {
F_2 ( F_5 ( V_20 -> V_13 ) -> V_12 ) ;
F_2 ( F_5 ( V_20 -> V_13 ) -> V_3 == V_1 ) ;
F_5 ( V_20 -> V_13 ) -> V_3 = V_20 -> V_3 ;
}
if ( V_6 -> V_10 == V_1 ) {
V_6 -> V_10 = V_20 -> V_3 ;
}
V_20 -> V_12 = FALSE ;
}
static void
F_9 ( T_3 * V_6 ,
T_1 * V_1 ,
T_1 * V_22 )
{
T_5 * V_20 ;
F_2 ( ! V_1 -> V_21 ) ;
F_2 ( F_8 ( V_1 ) >= sizeof( T_5 ) ) ;
V_20 = F_5 ( V_1 ) ;
F_2 ( ! V_20 -> V_12 ) ;
if ( V_22 == NULL ) {
V_20 -> V_13 = V_6 -> V_11 ;
V_20 -> V_3 = NULL ;
V_6 -> V_11 = V_1 ;
if ( V_20 -> V_13 ) {
F_5 ( V_20 -> V_13 ) -> V_3 = V_1 ;
}
}
else {
V_20 -> V_13 = F_5 ( V_22 ) -> V_13 ;
V_20 -> V_3 = V_22 ;
F_5 ( V_22 ) -> V_13 = V_1 ;
if ( V_20 -> V_13 ) {
F_5 ( V_20 -> V_13 ) -> V_3 = V_1 ;
}
}
V_20 -> V_12 = TRUE ;
}
static void
F_10 ( T_3 * V_6 ,
T_1 * V_1 )
{
F_2 ( ! V_1 -> V_21 ) ;
if ( F_8 ( V_1 ) >= sizeof( T_5 ) ) {
F_2 ( ! F_5 ( V_1 ) -> V_12 ) ;
}
if ( V_1 -> V_4 < V_23 ) {
return;
}
F_9 ( V_6 , V_1 ,
V_6 -> V_10 ) ;
if ( V_1 -> V_4 > V_24 ) {
V_6 -> V_10 = V_1 ;
}
}
static T_1 *
F_11 ( T_3 * V_6 ,
T_1 * V_1 )
{
T_1 * V_14 ;
F_2 ( ! V_1 -> V_21 ) ;
V_14 = F_3 ( V_1 ) ;
if ( V_14 && ! V_14 -> V_21 ) {
F_7 ( V_6 , V_14 ) ;
V_1 -> V_4 += V_14 -> V_4 ;
V_1 -> V_25 = V_14 -> V_25 ;
}
V_14 = F_12 ( V_1 ) ;
if ( V_14 && ! V_14 -> V_21 ) {
F_7 ( V_6 , V_14 ) ;
V_14 -> V_4 += V_1 -> V_4 ;
V_14 -> V_25 = V_1 -> V_25 ;
V_1 = V_14 ;
}
V_14 = F_3 ( V_1 ) ;
if ( V_14 ) {
V_14 -> V_3 = V_1 -> V_4 ;
}
if ( F_8 ( V_1 ) >= sizeof( T_5 ) ) {
F_5 ( V_1 ) -> V_12 = FALSE ;
}
return V_1 ;
}
static void
F_13 ( T_3 * V_6 ,
T_1 * V_1 ,
const T_8 V_26 )
{
T_1 * V_27 ;
T_8 V_28 , V_29 ;
T_4 V_25 ;
F_2 ( ! V_1 -> V_21 ) ;
F_2 ( F_8 ( V_1 ) >= V_26 ) ;
V_28 = F_14 ( V_26 ) ;
if ( V_28 + sizeof( T_1 ) >
F_8 ( V_1 ) ) {
F_7 ( V_6 , V_1 ) ;
return;
}
V_25 = V_1 -> V_25 ;
V_29 = V_1 -> V_4 ;
if ( V_29 < ( sizeof( T_1 ) + V_28 ) +
( sizeof( T_1 ) + sizeof( T_5 ) ) ) {
F_7 ( V_6 , V_1 ) ;
}
V_1 -> V_4 = ( T_2 ) ( V_28 + sizeof( T_1 ) ) ;
V_1 -> V_25 = FALSE ;
V_27 = F_3 ( V_1 ) ;
V_29 -= ( V_28 + sizeof( T_1 ) ) ;
if ( V_29 >= sizeof( T_1 ) + sizeof( T_5 ) ) {
if ( ! F_5 ( V_1 ) -> V_12 ) {
F_5 ( V_27 ) -> V_12 = FALSE ;
}
else {
T_1 * V_3 , * V_13 ;
T_5 * V_30 , * V_31 ;
V_30 = F_5 ( V_1 ) ;
V_31 = F_5 ( V_27 ) ;
V_3 = V_30 -> V_3 ;
V_13 = V_30 -> V_13 ;
V_31 -> V_12 = TRUE ;
V_31 -> V_3 = V_3 ;
V_31 -> V_13 = V_13 ;
if ( V_3 ) F_5 ( V_3 ) -> V_13 = V_27 ;
if ( V_13 ) F_5 ( V_13 ) -> V_3 = V_27 ;
if ( V_6 -> V_11 == V_1 )
V_6 -> V_11 = V_27 ;
if ( V_6 -> V_10 == V_1 )
V_6 -> V_10 = V_27 ;
}
}
V_27 -> V_4 = ( T_2 ) V_29 ;
V_27 -> V_25 = V_25 ;
V_27 -> V_3 = ( T_2 ) ( V_28 + sizeof( T_1 ) ) ;
V_27 -> V_21 = FALSE ;
V_1 = F_3 ( V_27 ) ;
if ( V_1 ) {
V_1 -> V_3 = V_27 -> V_4 ;
}
}
static void
F_15 ( T_3 * V_6 ,
T_1 * V_1 ,
const T_8 V_26 )
{
T_1 * V_27 ;
T_8 V_28 , V_29 ;
T_4 V_25 ;
F_2 ( V_1 -> V_21 ) ;
F_2 ( F_8 ( V_1 ) >= V_26 ) ;
V_28 = F_14 ( V_26 ) ;
if ( V_28 + sizeof( T_1 ) >
F_8 ( V_1 ) ) {
return;
}
V_25 = V_1 -> V_25 ;
V_29 = V_1 -> V_4 ;
V_1 -> V_4 = ( T_2 ) ( V_28 + sizeof( T_1 ) ) ;
V_1 -> V_25 = FALSE ;
V_27 = F_3 ( V_1 ) ;
V_29 -= ( V_28 + sizeof( T_1 ) ) ;
V_27 -> V_4 = ( T_2 ) V_29 ;
V_27 -> V_25 = V_25 ;
V_27 -> V_3 = ( T_2 ) ( V_28 + sizeof( T_1 ) ) ;
V_27 -> V_21 = FALSE ;
V_1 = F_3 ( V_27 ) ;
if ( V_1 ) {
V_1 -> V_3 = V_27 -> V_4 ;
}
V_1 = F_11 ( V_6 , V_27 ) ;
F_2 ( V_1 == V_27 ) ;
F_10 ( V_6 , V_27 ) ;
}
static void
F_16 ( T_3 * V_6 , void * V_32 )
{
T_1 * V_1 ;
V_1 = ( T_1 * ) V_32 ;
V_1 -> V_21 = FALSE ;
V_1 -> V_25 = TRUE ;
V_1 -> V_3 = 0 ;
V_1 -> V_4 = V_5 ;
F_5 ( V_1 ) -> V_12 = FALSE ;
F_9 ( V_6 , V_1 , NULL ) ;
if ( V_6 -> V_10 == NULL ) {
V_6 -> V_10 = V_1 ;
}
}
static void
F_17 ( T_3 * V_6 )
{
void * V_32 ;
V_32 = F_18 ( V_5 ) ;
V_6 -> V_18 = F_19 ( V_6 -> V_18 , V_32 ) ;
F_16 ( V_6 , V_32 ) ;
}
static void *
F_20 ( void * V_17 , const T_8 V_26 )
{
T_3 * V_6 = ( T_3 * ) V_17 ;
T_1 * V_1 ;
F_2 ( V_26 < V_5 - sizeof( T_1 ) ) ;
if ( V_6 -> V_11 == NULL ) {
F_17 ( V_6 ) ;
}
else if ( F_8 ( V_6 -> V_11 ) < V_26 ) {
V_1 = V_6 -> V_11 ;
F_7 ( V_6 , V_1 ) ;
if ( V_6 -> V_11 == NULL ||
F_8 ( V_6 -> V_11 ) < V_26 ) {
F_17 ( V_6 ) ;
}
F_10 ( V_6 , V_1 ) ;
}
V_1 = V_6 -> V_11 ;
F_2 ( V_26 <= F_8 ( V_1 ) ) ;
F_13 ( V_6 , V_1 , V_26 ) ;
F_2 ( V_26 <= F_8 ( V_1 ) ) ;
F_2 ( V_1 != V_6 -> V_11 ) ;
F_2 ( V_1 != V_6 -> V_10 ) ;
V_1 -> V_21 = TRUE ;
return F_21 ( V_1 ) ;
}
static void
F_22 ( void * V_17 , void * V_33 )
{
T_3 * V_6 = ( T_3 * ) V_17 ;
T_1 * V_1 ;
V_1 = F_23 ( V_33 ) ;
F_2 ( V_1 -> V_21 ) ;
V_1 -> V_21 = FALSE ;
V_1 = F_11 ( V_6 , V_1 ) ;
F_10 ( V_6 , V_1 ) ;
}
static void *
F_24 ( void * V_17 , void * V_33 , const T_8 V_26 )
{
T_3 * V_6 = ( T_3 * ) V_17 ;
T_1 * V_1 ;
V_1 = F_23 ( V_33 ) ;
F_2 ( V_1 -> V_21 ) ;
if ( V_26 > F_8 ( V_1 ) ) {
T_1 * V_14 ;
V_14 = F_3 ( V_1 ) ;
if ( V_14 && ( ! V_14 -> V_21 ) &&
( V_26 < F_8 ( V_1 ) + V_14 -> V_4 ) ) {
T_8 V_34 ;
V_34 = V_26 - F_8 ( V_1 ) ;
if ( V_34 < sizeof( T_1 ) ) {
V_34 = 0 ;
}
else {
V_34 -= sizeof( T_1 ) ;
}
F_13 ( V_6 , V_14 , V_34 ) ;
V_1 -> V_4 += V_14 -> V_4 ;
V_1 -> V_25 = V_14 -> V_25 ;
V_14 = F_3 ( V_1 ) ;
if ( V_14 ) {
V_14 -> V_3 = V_1 -> V_4 ;
}
return V_33 ;
}
else {
void * V_35 ;
V_35 = F_20 ( V_17 , V_26 ) ;
memcpy ( V_35 , V_33 , F_8 ( V_1 ) ) ;
F_22 ( V_17 , V_33 ) ;
return V_35 ;
}
}
else if ( V_26 < F_8 ( V_1 ) ) {
F_15 ( V_6 , V_1 , V_26 ) ;
return V_33 ;
}
return V_33 ;
}
static void
F_25 ( void * V_17 )
{
T_3 * V_6 = ( T_3 * ) V_17 ;
T_7 * V_14 ;
V_6 -> V_11 = NULL ;
V_6 -> V_10 = NULL ;
V_14 = V_6 -> V_18 ;
while ( V_14 ) {
F_16 ( V_6 , V_14 -> V_19 ) ;
V_14 = V_14 -> V_13 ;
}
}
static void
F_26 ( void * V_17 )
{
T_3 * V_6 = ( T_3 * ) V_17 ;
T_7 * V_14 , * V_36 = NULL ;
T_1 * V_1 ;
V_14 = V_6 -> V_18 ;
while ( V_14 ) {
V_1 = ( T_1 * ) V_14 -> V_19 ;
if ( ! V_1 -> V_21 && V_1 -> V_25 ) {
F_7 ( V_6 , V_1 ) ;
F_27 ( V_1 ) ;
}
else {
V_36 = F_19 ( V_36 , V_1 ) ;
}
V_14 = V_14 -> V_13 ;
}
F_28 ( V_6 -> V_18 ) ;
V_6 -> V_18 = V_36 ;
}
static void
F_29 ( T_6 * V_6 )
{
T_3 * V_37 ;
V_37 = ( T_3 * ) V_6 -> V_17 ;
F_26 ( V_37 ) ;
F_30 ( T_3 , V_37 ) ;
F_30 ( T_6 , V_6 ) ;
}
T_6 *
F_31 ( void )
{
T_6 * V_6 ;
T_3 * V_38 ;
V_6 = F_32 ( T_6 ) ;
V_38 = F_32 ( T_3 ) ;
V_6 -> V_17 = ( void * ) V_38 ;
V_6 -> V_39 = & F_20 ;
V_6 -> realloc = & F_24 ;
V_6 -> free = & F_22 ;
V_6 -> V_40 = & F_25 ;
V_6 -> V_41 = & F_26 ;
V_6 -> V_42 = & F_29 ;
V_38 -> V_18 = NULL ;
V_38 -> V_11 = NULL ;
V_38 -> V_10 = NULL ;
return V_6 ;
}
