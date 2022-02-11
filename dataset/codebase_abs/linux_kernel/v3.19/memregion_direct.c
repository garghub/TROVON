struct V_1 *
F_1 ( T_1 V_2 , T_2 V_3 )
{
struct V_1 * V_4 = NULL ;
struct V_1 * V_1 = F_2 ( sizeof( * V_1 ) ,
V_5 | V_6 ) ;
if ( V_1 == NULL ) {
F_3 ( L_1 ) ;
return NULL ;
}
V_1 -> V_2 = V_2 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_7 = FALSE ;
if ( ! F_4 ( V_1 ) ) {
V_4 = NULL ;
goto V_8;
}
V_4 = V_1 ;
V_8:
if ( V_4 == NULL ) {
F_5 ( V_1 ) ;
V_1 = NULL ;
}
return V_4 ;
}
struct V_1 *
F_6 ( struct V_1 * V_9 , T_2 V_10 ,
T_2 V_3 )
{
struct V_1 * V_1 = NULL ;
if ( V_9 == NULL ) {
F_3 ( L_2 , V_11 ) ;
return NULL ;
}
if ( V_9 -> V_12 == NULL ) {
F_3 ( L_3 , V_11 ) ;
return NULL ;
}
if ( ( V_10 >= V_9 -> V_3 ) ||
( ( V_10 + V_3 ) >= V_9 -> V_3 ) ) {
F_3 ( L_4 ,
V_11 , V_10 , V_3 ) ;
return NULL ;
}
V_1 = F_2 ( sizeof( * V_1 ) , V_5 | V_6 ) ;
if ( V_1 == NULL ) {
F_3 ( L_5 , V_11 ) ;
return NULL ;
}
V_1 -> V_2 = V_9 -> V_2 + V_10 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_12 = ( ( V_13 V_14 * ) ( V_9 -> V_12 ) ) + V_10 ;
V_1 -> V_15 = FALSE ;
V_1 -> V_7 = TRUE ;
return V_1 ;
}
static BOOL
F_4 ( struct V_1 * V_1 )
{
T_2 V_2 = ( T_2 ) ( V_1 -> V_2 ) ;
T_2 V_3 = V_1 -> V_3 ;
V_1 -> V_15 = FALSE ;
if ( ! F_7 ( V_2 , V_3 , V_16 ) )
F_3 ( L_6 ,
V_2 , V_3 ) ;
else
V_1 -> V_15 = TRUE ;
V_1 -> V_12 = F_8 ( V_2 , V_3 ) ;
if ( V_1 -> V_12 == NULL ) {
F_3 ( L_7 ,
V_2 , V_3 ) ;
return FALSE ;
}
return TRUE ;
}
static void
F_9 ( struct V_1 * V_1 )
{
if ( V_1 -> V_12 != NULL ) {
F_10 ( V_1 -> V_12 ) ;
V_1 -> V_12 = NULL ;
}
if ( V_1 -> V_15 ) {
F_11 ( ( T_2 ) ( V_1 -> V_2 ) ,
V_1 -> V_3 ) ;
V_1 -> V_15 = FALSE ;
}
}
T_1
F_12 ( struct V_1 * V_1 )
{
return V_1 -> V_2 ;
}
T_2
F_13 ( struct V_1 * V_1 )
{
return V_1 -> V_3 ;
}
void V_14 *
F_14 ( struct V_1 * V_1 )
{
return V_1 -> V_12 ;
}
int
F_15 ( struct V_1 * V_1 , T_2 V_17 )
{
if ( V_17 == V_1 -> V_3 )
return 0 ;
if ( V_1 -> V_7 )
V_1 -> V_3 = V_17 ;
else {
F_9 ( V_1 ) ;
V_1 -> V_3 = V_17 ;
if ( ! F_4 ( V_1 ) )
return - 1 ;
}
return 0 ;
}
static int
F_16 ( BOOL V_18 ,
struct V_1 * V_1 , T_2 V_10 ,
void * V_19 , T_2 V_3 )
{
if ( V_10 + V_3 > V_1 -> V_3 ) {
F_3 ( L_8 ) ;
return - V_20 ;
}
if ( V_18 )
F_17 ( V_1 -> V_12 + V_10 , V_19 , V_3 ) ;
else
F_18 ( V_19 , V_1 -> V_12 + V_10 , V_3 ) ;
return 0 ;
}
int
F_19 ( struct V_1 * V_1 , T_2 V_10 , void * V_21 ,
T_2 V_3 )
{
return F_16 ( FALSE , V_1 , V_10 , V_21 , V_3 ) ;
}
int
F_20 ( struct V_1 * V_1 , T_2 V_10 , void * V_22 ,
T_2 V_3 )
{
return F_16 ( TRUE , V_1 , V_10 , V_22 , V_3 ) ;
}
void
F_5 ( struct V_1 * V_1 )
{
if ( V_1 == NULL )
return;
if ( ! V_1 -> V_7 )
F_9 ( V_1 ) ;
F_21 ( V_1 ) ;
}
