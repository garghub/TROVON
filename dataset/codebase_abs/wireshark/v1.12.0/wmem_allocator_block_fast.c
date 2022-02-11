static inline void
F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
V_2 = ( T_2 * ) F_2 ( NULL , V_3 ) ;
V_2 -> V_4 = V_5 ;
V_2 -> V_6 = V_1 -> V_7 ;
V_1 -> V_7 = V_2 ;
}
static void *
F_3 ( void * V_8 , const T_3 V_9 )
{
T_1 * V_1 = ( T_1 * ) V_8 ;
T_4 * V_10 ;
T_5 V_11 ;
if ( V_9 > V_12 ) {
T_6 * V_2 ;
V_2 = ( T_6 * ) F_2 ( NULL ,
V_9 + V_13 + V_14 ) ;
V_2 -> V_6 = V_1 -> V_15 ;
V_2 -> V_16 = NULL ;
V_1 -> V_15 = V_2 ;
V_10 = ( ( T_4 * ) ( ( V_17 * ) ( V_2 ) + V_13 ) ) ;
V_10 -> V_18 = V_19 ;
return F_4 ( V_10 ) ;
}
V_11 = ( T_5 ) ( F_5 ( V_9 ) + V_14 ) ;
if ( ! V_1 -> V_7 ||
( V_3 - V_1 -> V_7 -> V_4 ) < V_11 ) {
F_1 ( V_1 ) ;
}
V_10 = ( T_4 * ) ( ( V_17 * ) V_1 -> V_7 + V_1 -> V_7 -> V_4 ) ;
V_10 -> V_18 = ( V_20 ) V_9 ;
V_1 -> V_7 -> V_4 += V_11 ;
return F_4 ( V_10 ) ;
}
static void
F_6 ( void * V_8 V_21 , void * T_7 V_21 )
{
}
static void *
F_7 ( void * V_8 , void * T_7 , const T_3 V_9 )
{
T_4 * V_10 ;
V_10 = F_8 ( T_7 ) ;
if ( V_10 -> V_18 == V_19 ) {
T_6 * V_2 ;
V_2 = ( ( T_6 * ) ( ( V_17 * ) ( V_10 ) - V_13 ) ) ;
V_2 = ( T_6 * ) F_9 ( NULL , V_2 ,
V_9 + V_13 + V_14 ) ;
if ( V_2 -> V_16 ) {
V_2 -> V_16 -> V_6 = V_2 ;
}
else {
T_1 * V_1 = ( T_1 * ) V_8 ;
V_1 -> V_15 = V_2 ;
}
if ( V_2 -> V_6 ) {
V_2 -> V_6 -> V_16 = V_2 ;
}
return ( ( void * ) ( ( V_17 * ) ( V_2 ) + V_13 + V_14 ) ) ;
}
else if ( V_10 -> V_18 < V_9 ) {
void * V_22 ;
V_22 = F_3 ( V_8 , V_9 ) ;
memcpy ( V_22 , T_7 , V_10 -> V_18 ) ;
return V_22 ;
}
return T_7 ;
}
static void
F_10 ( void * V_8 )
{
T_1 * V_1 = ( T_1 * ) V_8 ;
T_2 * V_23 , * V_24 ;
T_6 * V_25 , * V_26 ;
V_23 = V_1 -> V_7 ;
if ( V_23 ) {
V_23 -> V_4 = V_5 ;
V_24 = V_23 -> V_6 ;
V_23 -> V_6 = NULL ;
V_23 = V_24 ;
}
while ( V_23 ) {
V_24 = V_23 -> V_6 ;
F_11 ( NULL , V_23 ) ;
V_23 = V_24 ;
}
V_25 = V_1 -> V_15 ;
while ( V_25 ) {
V_26 = V_25 -> V_6 ;
F_11 ( NULL , V_25 ) ;
V_25 = V_26 ;
}
V_1 -> V_15 = NULL ;
}
static void
F_12 ( void * V_8 V_21 )
{
}
static void
F_13 ( void * V_8 )
{
T_1 * V_1 = ( T_1 * ) V_8 ;
F_11 ( NULL , V_1 -> V_7 ) ;
F_11 ( NULL , V_8 ) ;
}
void
F_14 ( T_8 * V_1 )
{
T_1 * V_27 ;
V_27 = F_15 ( NULL , T_1 ) ;
V_1 -> V_28 = & F_3 ;
V_1 -> realloc = & F_7 ;
V_1 -> free = & F_6 ;
V_1 -> V_29 = & F_10 ;
V_1 -> V_30 = & F_12 ;
V_1 -> V_31 = & F_13 ;
V_1 -> V_8 = ( void * ) V_27 ;
V_27 -> V_7 = NULL ;
V_27 -> V_15 = NULL ;
}
