static void
F_1 ( const void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
if( ! V_1 ) {
return;
}
printf ( L_1 V_3 L_2 V_3 L_3 V_3 L_4 , V_2 -> V_4 , V_2 -> V_5 , V_2 -> V_6 ) ;
}
static void
F_2 ( T_2 * V_7 )
{
T_1 * V_2 ;
T_1 * V_8 ;
T_1 * V_9 ;
T_3 V_10 = 0 ;
if( ! V_7 ) {
return ;
}
V_2 = ( T_1 * ) V_7 -> V_11 ;
V_8 = ( V_7 -> V_12 ) ? ( T_1 * ) ( V_7 -> V_12 -> V_11 ) : NULL ;
V_9 = ( V_7 -> V_13 ) ? ( T_1 * ) ( V_7 -> V_13 -> V_11 ) : NULL ;
V_10 = V_2 -> V_6 ;
if( V_9 ) {
V_10 = F_3 ( V_10 , V_9 -> V_6 ) ;
}
if( V_8 ) {
V_10 = F_3 ( V_10 , V_8 -> V_6 ) ;
}
if( V_2 -> V_6 != V_10 ) {
V_2 -> V_6 = V_10 ;
F_2 ( V_7 -> V_14 ) ;
}
}
T_4
F_4 ( const T_1 * V_15 , const T_1 * V_16 )
{
return ( V_15 -> V_4 <= V_16 -> V_5 && V_16 -> V_4 <= V_15 -> V_5 ) ;
}
T_5 *
F_5 ( T_6 * V_17 )
{
T_5 * V_18 = F_6 ( V_17 ) ;
V_18 -> V_19 = & F_2 ;
return V_18 ;
}
T_4
F_7 ( T_5 * V_18 )
{
return F_8 ( V_18 ) ;
}
static int
F_9 ( const T_1 * V_20 , const T_1 * V_21 )
{
if( V_20 -> V_4 == V_21 -> V_4 ) {
return 0 ;
}
else if( V_20 -> V_4 < V_21 -> V_4 ) {
return - 1 ;
}
else {
return 1 ;
}
}
void
F_10 ( T_5 * V_18 , const T_3 V_4 , const T_3 V_5 , void * V_22 )
{
T_2 * V_7 ;
T_1 * V_2 = ( T_1 * ) F_11 ( V_18 -> V_17 , T_1 ) ;
F_12 ( V_4 <= V_5 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_5 ;
V_7 = F_13 ( V_18 , V_2 , V_22 , ( V_23 ) F_9 ) ;
F_2 ( V_7 ) ;
}
static void
F_14 ( T_2 * V_7 , T_1 V_24 , T_7 * V_25 )
{
const T_1 * V_26 ;
if( ! V_7 ) {
return;
}
V_26 = ( T_1 * ) V_7 -> V_11 ;
if( V_24 . V_4 > V_26 -> V_6 ) {
return;
}
if( F_4 ( V_26 , & V_24 ) ) {
F_15 ( V_25 , V_7 -> V_22 ) ;
}
F_14 ( V_7 -> V_12 , V_24 , V_25 ) ;
F_14 ( V_7 -> V_13 , V_24 , V_25 ) ;
}
T_7 *
F_16 ( T_5 * V_18 , T_6 * V_17 , T_3 V_4 , T_3 V_5 )
{
T_7 * V_25 = NULL ;
T_1 V_24 = { V_4 , V_5 , 0 } ;
V_25 = F_17 ( V_17 ) ;
F_14 ( V_18 -> V_27 , V_24 , V_25 ) ;
return V_25 ;
}
void
F_18 ( T_8 * V_18 )
{
F_19 ( V_18 , & F_1 , NULL ) ;
}
