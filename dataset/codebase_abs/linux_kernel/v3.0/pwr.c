int F_1 ( const T_1 V_1 , const T_1 V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 = - V_8 ;
struct V_9 * V_10 = NULL ;
T_1 V_11 = 0 ;
T_1 V_12 = V_2 ;
for ( V_10 = (struct V_9 * ) F_2 () ;
V_10 != NULL ;
V_10 =
(struct V_9 * ) F_3 ( ( T_1 ) V_10 ) ) {
if ( F_4 ( V_10 ,
(struct V_5 * * )
& V_6 ) ) {
continue;
}
if ( F_5 ( V_10 ,
(struct V_3 * * )
& V_4 ) ) {
continue;
}
if ( V_1 == V_13 )
V_11 = V_14 ;
else if ( V_1 == V_15 )
V_11 = V_16 ;
else
V_7 = - V_17 ;
if ( V_7 != - V_17 ) {
V_7 = (* V_4 -> V_18 ) ( V_6 ,
V_11 ,
( void * ) & V_12 ) ;
}
}
return V_7 ;
}
int F_6 ( const T_1 V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 = - V_8 ;
struct V_9 * V_10 = NULL ;
T_1 V_12 = V_2 ;
for ( V_10 = (struct V_9 * ) F_2 () ;
V_10 != NULL ;
V_10 = (struct V_9 * ) F_3
( ( T_1 ) V_10 ) ) {
if ( ! ( F_4 ( V_10 ,
(struct V_5
* * ) & V_6 ) ) ) {
if ( ! ( F_5 ( V_10 ,
(struct V_3 * * ) & V_4 ) ) ) {
V_7 =
(* V_4 -> V_18 ) ( V_6 ,
V_19 ,
( void * ) & V_12 ) ;
}
}
}
return V_7 ;
}
int F_7 ( T_2 V_20 , T_1 V_21 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 = - V_8 ;
struct V_9 * V_10 = NULL ;
T_1 V_12 [ 2 ] ;
V_12 [ 0 ] = V_20 ;
V_12 [ 1 ] = V_21 ;
for ( V_10 = (struct V_9 * ) F_2 () ;
V_10 != NULL ;
V_10 = (struct V_9 * ) F_3
( ( T_1 ) V_10 ) ) {
if ( ! ( F_4 ( V_10 ,
(struct V_5
* * ) & V_6 ) ) ) {
if ( ! ( F_5 ( V_10 ,
(struct V_3 * * ) & V_4 ) ) ) {
V_7 =
(* V_4 -> V_18 ) ( V_6 ,
V_22 ,
( void * ) & V_12 ) ;
}
}
}
return V_7 ;
}
int F_8 ( T_2 V_20 , T_1 V_21 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 = - V_8 ;
struct V_9 * V_10 = NULL ;
T_1 V_12 [ 2 ] ;
V_12 [ 0 ] = V_20 ;
V_12 [ 1 ] = V_21 ;
for ( V_10 = (struct V_9 * ) F_2 () ;
V_10 != NULL ;
V_10 = (struct V_9 * ) F_3
( ( T_1 ) V_10 ) ) {
if ( ! ( F_4 ( V_10 ,
(struct V_5
* * ) & V_6 ) ) ) {
if ( ! ( F_5 ( V_10 ,
(struct V_3 * * ) & V_4 ) ) ) {
V_7 =
(* V_4 -> V_18 ) ( V_6 ,
V_23 ,
( void * ) & V_12 ) ;
}
}
}
return V_7 ;
}
