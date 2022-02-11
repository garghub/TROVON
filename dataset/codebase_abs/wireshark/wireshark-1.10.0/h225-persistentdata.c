static T_1 F_1 ( T_2 V_1 , T_2 V_2 )
{
const T_3 * V_3 = ( const T_3 * ) V_1 ;
const T_3 * V_4 = ( const T_3 * ) V_2 ;
return ( V_3 -> V_5 == V_4 -> V_5 &&
V_3 -> V_6 == V_4 -> V_6 ) ;
}
static T_4 F_2 ( T_2 V_7 )
{
const T_3 * V_8 = ( const T_3 * ) V_7 ;
return V_8 -> V_5 + F_3 ( V_8 -> V_6 ) ;
}
T_5 * F_4 ( T_3 * V_9 , int V_10 )
{
T_5 * V_11 = NULL ;
V_11 = ( T_5 * ) F_5 ( V_12 [ V_10 ] , V_9 ) ;
return V_11 ;
}
T_5 * F_6 ( T_3 * V_9 , T_6 * V_13 , T_7 * V_14 , int V_10 )
{
T_3 * V_15 ;
T_5 * V_11 = NULL ;
V_15 = F_7 ( T_3 ) ;
V_15 -> V_5 = V_9 -> V_5 ;
V_15 -> V_6 = V_9 -> V_6 ;
V_11 = F_7 ( T_5 ) ;
V_11 -> V_16 = V_13 -> V_17 -> V_18 ;
V_11 -> V_19 = 0 ;
V_11 -> V_20 = V_9 -> V_5 ;
V_11 -> V_21 = FALSE ;
V_11 -> V_22 = NULL ;
V_11 -> V_23 = V_13 -> V_17 -> V_24 ;
V_11 -> V_14 = * V_14 ;
F_8 ( V_12 [ V_10 ] , V_15 , V_11 ) ;
return V_11 ;
}
T_5 * F_9 ( T_5 * V_25 , T_6 * V_13 , T_7 * V_14 , int V_10 V_26 )
{
T_5 * V_11 = NULL ;
V_11 = F_7 ( T_5 ) ;
V_11 -> V_16 = V_13 -> V_17 -> V_18 ;
V_11 -> V_19 = 0 ;
V_11 -> V_20 = V_25 -> V_20 ;
V_11 -> V_21 = FALSE ;
V_11 -> V_22 = NULL ;
V_11 -> V_23 = V_13 -> V_17 -> V_24 ;
V_11 -> V_14 = * V_14 ;
V_25 -> V_22 = V_11 ;
return V_11 ;
}
void
F_10 ( void )
{
int V_27 ;
for( V_27 = 0 ; V_27 < 7 ; V_27 ++ ) {
if ( V_12 [ V_27 ] != NULL ) {
F_11 ( V_12 [ V_27 ] ) ;
V_12 [ V_27 ] = NULL ;
}
}
for( V_27 = 0 ; V_27 < 7 ; V_27 ++ ) {
V_12 [ V_27 ] = F_12 ( F_2 , F_1 ) ;
}
}
