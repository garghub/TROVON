T_1
F_1 ( T_2 * V_1 , T_3 * * V_2 , T_4 * V_3 , unsigned * V_4 , unsigned * V_5 )
{
unsigned int V_6 ;
const T_5 * V_7 ;
T_6 * V_8 ;
T_3 * V_9 = NULL ;
T_1 V_10 ;
T_1 V_11 = 0 ;
if ( ( V_1 -> V_12 == NULL ) || ( V_1 -> V_13 -> V_14 == 0 ) ) {
return 0 ;
}
V_6 = V_1 -> V_13 -> V_15 ;
V_8 = ( T_6 * ) F_2 ( V_3 , F_3 ( V_6 ) ) ;
if ( ! V_8 ) {
V_8 = F_4 ( T_6 , 1 ) ;
V_8 -> V_16 = NULL ;
V_8 -> V_17 = NULL ;
if ( V_1 -> V_13 -> V_18 && F_5 ( V_1 -> V_13 -> V_18 ) ) {
V_7 = V_1 -> V_13 -> V_18 ;
} else {
V_7 = F_6 ( V_6 , & V_19 ) ;
}
if ( V_7 ) {
V_8 -> V_16 = F_5 ( V_7 ) ;
if ( V_8 -> V_16 )
V_8 -> V_17 = F_7 ( V_8 -> V_16 ) ;
}
F_8 ( V_3 , F_3 ( V_6 ) , V_8 ) ;
}
if ( V_8 -> V_16 ) {
V_10 = F_9 ( V_8 -> V_16 , V_8 -> V_17 , V_1 -> V_12 , V_1 -> V_13 -> V_14 , NULL , NULL ) ;
V_9 = ( T_3 * ) F_10 ( V_10 ) ;
V_11 = F_9 ( V_8 -> V_16 , V_8 -> V_17 , V_1 -> V_12 , V_1 -> V_13 -> V_14 , V_9 , & V_10 ) ;
* V_2 = V_9 ;
if ( V_4 ) {
* V_4 = F_11 ( V_8 -> V_16 , V_8 -> V_17 ) ;
}
if ( V_5 ) {
* V_5 = F_12 ( V_8 -> V_16 , V_8 -> V_17 ) ;
}
return V_11 ;
}
* V_2 = NULL ;
return 0 ;
}
static void
F_13 ( T_7 V_20 )
{
T_6 * V_21 = ( T_6 * ) V_20 ;
if ( V_21 -> V_16 )
F_14 ( V_21 -> V_16 , V_21 -> V_17 ) ;
F_15 ( V_20 ) ;
}
T_4 * F_16 ( void )
{
return F_17 ( V_22 , V_23 , NULL , F_13 ) ;
}
