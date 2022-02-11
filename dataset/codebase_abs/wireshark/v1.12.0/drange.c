T_1 *
F_1 ( void )
{
T_1 * V_1 ;
V_1 = F_2 ( T_1 , 1 ) ;
V_1 -> V_2 = 0 ;
V_1 -> V_3 = 0 ;
V_1 -> V_4 = 0 ;
V_1 -> V_5 = V_6 ;
return V_1 ;
}
static T_1 *
F_3 ( T_1 * V_7 )
{
T_1 * V_1 ;
if ( ! V_7 )
return NULL ;
V_1 = F_2 ( T_1 , 1 ) ;
V_1 -> V_2 = V_7 -> V_2 ;
V_1 -> V_3 = V_7 -> V_3 ;
V_1 -> V_4 = V_7 -> V_4 ;
V_1 -> V_5 = V_7 -> V_5 ;
return V_1 ;
}
void
F_4 ( T_1 * V_8 )
{
F_5 ( V_8 ) ;
}
T_2
F_6 ( T_1 * V_8 )
{
F_7 ( V_8 -> V_5 != V_6 ) ;
return V_8 -> V_2 ;
}
T_2
F_8 ( T_1 * V_8 )
{
F_7 ( V_8 -> V_5 == V_9 ) ;
return V_8 -> V_3 ;
}
T_2
F_9 ( T_1 * V_8 )
{
F_7 ( V_8 -> V_5 == V_10 ) ;
return V_8 -> V_4 ;
}
T_3
F_10 ( T_1 * V_8 )
{
F_7 ( V_8 -> V_5 != V_6 ) ;
return V_8 -> V_5 ;
}
void
F_11 ( T_1 * V_8 , T_2 V_11 )
{
V_8 -> V_2 = V_11 ;
}
void
F_12 ( T_1 * V_8 , T_2 V_3 )
{
V_8 -> V_3 = V_3 ;
V_8 -> V_5 = V_9 ;
}
void
F_13 ( T_1 * V_8 , T_2 V_11 )
{
V_8 -> V_4 = V_11 ;
V_8 -> V_5 = V_10 ;
}
void
F_14 ( T_1 * V_8 )
{
V_8 -> V_5 = V_12 ;
}
T_4 *
F_15 ( void )
{
T_4 * V_13 ;
V_13 = F_2 ( T_4 , 1 ) ;
V_13 -> V_14 = NULL ;
V_13 -> V_15 = TRUE ;
V_13 -> V_16 = 0 ;
V_13 -> V_17 = V_18 ;
V_13 -> V_19 = V_20 ;
return V_13 ;
}
static void
F_16 ( T_5 V_21 , T_5 V_22 )
{
T_1 * V_8 = ( T_1 * ) V_21 ;
T_4 * V_23 = ( T_4 * ) V_22 ;
F_17 ( V_23 , V_8 ) ;
}
T_4 *
F_18 ( T_6 * V_24 )
{
T_4 * V_13 ;
V_13 = F_15 () ;
F_19 ( V_24 , F_16 , V_13 ) ;
return V_13 ;
}
T_4 *
F_20 ( T_4 * V_7 )
{
T_4 * V_13 ;
T_6 * V_25 ;
if ( ! V_7 )
return NULL ;
V_13 = F_15 () ;
for ( V_25 = V_7 -> V_14 ; V_25 ; V_25 = V_25 -> V_26 ) {
T_1 * V_8 = ( T_1 * ) V_25 -> V_21 ;
F_17 ( V_13 , F_3 ( V_8 ) ) ;
}
return V_13 ;
}
static void
F_21 ( T_5 V_21 , T_5 T_7 V_27 )
{
F_5 ( V_21 ) ;
}
void
F_22 ( T_4 * V_23 )
{
F_23 ( V_23 -> V_14 ) ;
F_5 ( V_23 ) ;
}
void
F_23 ( T_6 * V_24 )
{
F_19 ( V_24 , F_21 , NULL ) ;
}
T_8 F_24 ( T_4 * V_23 ) { return V_23 -> V_15 ; }
T_2 F_25 ( T_4 * V_23 ) { return V_23 -> V_16 ; }
T_2 F_26 ( T_4 * V_23 ) { return V_23 -> V_17 ; }
T_2 F_27 ( T_4 * V_23 ) { return V_23 -> V_19 ; }
static void
F_28 ( T_4 * V_23 , T_1 * V_8 )
{
if( V_8 -> V_5 == V_12 ) {
V_23 -> V_15 = FALSE ;
}
else if( V_23 -> V_15 ) {
V_23 -> V_16 += V_8 -> V_3 ;
}
if( V_8 -> V_2 < V_23 -> V_17 ) {
V_23 -> V_17 = V_8 -> V_2 ;
}
if( V_8 -> V_2 > V_23 -> V_19 ) {
V_23 -> V_19 = V_8 -> V_2 ;
}
}
void
F_29 ( T_4 * V_23 , T_1 * V_8 )
{
if( V_8 != NULL ) {
V_23 -> V_14 = F_30 ( V_23 -> V_14 , V_8 ) ;
F_28 ( V_23 , V_8 ) ;
}
}
void
F_17 ( T_4 * V_23 , T_1 * V_8 )
{
if( V_8 != NULL ) {
V_23 -> V_14 = F_31 ( V_23 -> V_14 , V_8 ) ;
F_28 ( V_23 , V_8 ) ;
}
}
void
F_32 ( T_4 * V_23 , T_9 V_28 , T_5 V_29 )
{
F_19 ( V_23 -> V_14 , V_28 , V_29 ) ;
}
