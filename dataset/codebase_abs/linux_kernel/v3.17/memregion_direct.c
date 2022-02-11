T_1 *
F_1 ( T_2 V_1 , T_3 V_2 )
{
T_1 * V_3 = NULL ;
T_1 * V_4 = F_2 ( sizeof( T_1 ) ,
V_5 | V_6 ) ;
if ( V_4 == NULL ) {
F_3 ( L_1 ) ;
return NULL ;
}
V_4 -> V_1 = V_1 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_7 = FALSE ;
if ( ! F_4 ( V_4 ) ) {
V_3 = NULL ;
goto V_8;
}
V_3 = V_4 ;
V_8:
if ( V_3 == NULL ) {
if ( V_4 != NULL ) {
F_5 ( V_4 ) ;
V_4 = NULL ;
}
}
return V_3 ;
}
T_1 *
F_6 ( T_1 * V_9 , T_3 V_10 , T_3 V_2 )
{
T_1 * V_4 = NULL ;
if ( V_9 == NULL ) {
F_3 ( L_2 , V_11 ) ;
return NULL ;
}
if ( V_9 -> V_12 == NULL ) {
F_3 ( L_3 , V_11 ) ;
return NULL ;
}
if ( ( V_10 >= V_9 -> V_2 ) ||
( ( V_10 + V_2 ) >= V_9 -> V_2 ) ) {
F_3 ( L_4 ,
V_11 , V_10 , V_2 ) ;
return NULL ;
}
V_4 = F_2 ( sizeof( T_1 ) , V_5 | V_6 ) ;
if ( V_4 == NULL ) {
F_3 ( L_5 , V_11 ) ;
return NULL ;
}
V_4 -> V_1 = V_9 -> V_1 + V_10 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_12 = ( ( V_13 V_14 * ) ( V_9 -> V_12 ) ) + V_10 ;
V_4 -> V_15 = FALSE ;
V_4 -> V_7 = TRUE ;
return V_4 ;
}
static BOOL
F_4 ( T_1 * V_4 )
{
T_3 V_1 = ( T_3 ) ( V_4 -> V_1 ) ;
T_3 V_2 = V_4 -> V_2 ;
V_4 -> V_15 = FALSE ;
if ( ! F_7 ( V_1 , V_2 , V_16 ) )
F_3 ( L_6 , V_1 , V_2 ) ;
else
V_4 -> V_15 = TRUE ;
V_4 -> V_12 = F_8 ( V_1 , V_2 ) ;
if ( V_4 -> V_12 == NULL ) {
F_3 ( L_7 ,
V_1 , V_2 ) ;
return FALSE ;
}
return TRUE ;
}
static void
F_9 ( T_1 * V_4 )
{
if ( V_4 -> V_12 != NULL ) {
F_10 ( V_4 -> V_12 ) ;
V_4 -> V_12 = NULL ;
}
if ( V_4 -> V_15 ) {
F_11 ( ( T_3 ) ( V_4 -> V_1 ) ,
V_4 -> V_2 ) ;
V_4 -> V_15 = FALSE ;
}
}
T_2
F_12 ( T_1 * V_4 )
{
return V_4 -> V_1 ;
}
T_3
F_13 ( T_1 * V_4 )
{
return V_4 -> V_2 ;
}
void V_14 *
F_14 ( T_1 * V_4 )
{
return V_4 -> V_12 ;
}
int
F_15 ( T_1 * V_4 , T_3 V_17 )
{
if ( V_17 == V_4 -> V_2 )
return 0 ;
if ( V_4 -> V_7 )
V_4 -> V_2 = V_17 ;
else {
F_9 ( V_4 ) ;
V_4 -> V_2 = V_17 ;
if ( ! F_4 ( V_4 ) )
return - 1 ;
}
return 0 ;
}
static int
F_16 ( BOOL V_18 ,
T_1 * V_4 , T_3 V_10 ,
void * V_19 , T_3 V_2 )
{
if ( V_10 + V_2 > V_4 -> V_2 ) {
F_3 ( L_8 ) ;
return - V_20 ;
}
if ( V_18 )
F_17 ( V_4 -> V_12 + V_10 , V_19 , V_2 ) ;
else
F_18 ( V_19 , V_4 -> V_12 + V_10 , V_2 ) ;
return 0 ;
}
int
F_19 ( T_1 * V_4 , T_3 V_10 , void * V_21 ,
T_3 V_2 )
{
return F_16 ( FALSE , V_4 , V_10 , V_21 , V_2 ) ;
}
int
F_20 ( T_1 * V_4 , T_3 V_10 , void * V_22 ,
T_3 V_2 )
{
return F_16 ( TRUE , V_4 , V_10 , V_22 , V_2 ) ;
}
void
F_5 ( T_1 * V_4 )
{
if ( V_4 == NULL )
return;
if ( ! V_4 -> V_7 )
F_9 ( V_4 ) ;
F_21 ( V_4 ) ;
}
