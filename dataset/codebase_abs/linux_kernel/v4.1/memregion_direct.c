struct V_1 *
F_1 ( T_1 V_2 , T_2 V_3 )
{
struct V_1 * V_4 = NULL ;
struct V_1 * V_1 ;
V_1 = F_2 ( sizeof( * V_1 ) , V_5 | V_6 ) ;
if ( V_1 == NULL )
return NULL ;
V_1 -> V_2 = V_2 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_7 = FALSE ;
if ( ! F_3 ( V_1 ) ) {
V_4 = NULL ;
goto V_8;
}
V_4 = V_1 ;
V_8:
if ( V_4 == NULL ) {
F_4 ( V_1 ) ;
V_1 = NULL ;
}
return V_4 ;
}
struct V_1 *
F_5 ( struct V_1 * V_9 , T_2 V_10 ,
T_2 V_3 )
{
struct V_1 * V_1 = NULL ;
if ( V_9 == NULL )
return NULL ;
if ( V_9 -> V_11 == NULL )
return NULL ;
if ( ( V_10 >= V_9 -> V_3 ) ||
( ( V_10 + V_3 ) >= V_9 -> V_3 ) )
return NULL ;
V_1 = F_2 ( sizeof( * V_1 ) , V_5 | V_6 ) ;
if ( V_1 == NULL )
return NULL ;
V_1 -> V_2 = V_9 -> V_2 + V_10 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_11 = ( ( V_12 V_13 * ) ( V_9 -> V_11 ) ) + V_10 ;
V_1 -> V_14 = FALSE ;
V_1 -> V_7 = TRUE ;
return V_1 ;
}
static BOOL
F_3 ( struct V_1 * V_1 )
{
T_2 V_2 = ( T_2 ) ( V_1 -> V_2 ) ;
T_2 V_3 = V_1 -> V_3 ;
V_1 -> V_14 = FALSE ;
if ( F_6 ( V_2 , V_3 , V_15 ) )
V_1 -> V_14 = TRUE ;
V_1 -> V_11 = F_7 ( V_2 , V_3 ) ;
if ( ! V_1 -> V_11 )
return FALSE ;
return TRUE ;
}
static void
F_8 ( struct V_1 * V_1 )
{
if ( V_1 -> V_11 != NULL ) {
F_9 ( V_1 -> V_11 ) ;
V_1 -> V_11 = NULL ;
}
if ( V_1 -> V_14 ) {
F_10 ( ( T_2 ) ( V_1 -> V_2 ) ,
V_1 -> V_3 ) ;
V_1 -> V_14 = FALSE ;
}
}
T_1
F_11 ( struct V_1 * V_1 )
{
return V_1 -> V_2 ;
}
T_2
F_12 ( struct V_1 * V_1 )
{
return V_1 -> V_3 ;
}
void V_13 *
F_13 ( struct V_1 * V_1 )
{
return V_1 -> V_11 ;
}
int
F_14 ( struct V_1 * V_1 , T_2 V_16 )
{
if ( V_16 == V_1 -> V_3 )
return 0 ;
if ( V_1 -> V_7 )
V_1 -> V_3 = V_16 ;
else {
F_8 ( V_1 ) ;
V_1 -> V_3 = V_16 ;
if ( ! F_3 ( V_1 ) )
return - 1 ;
}
return 0 ;
}
static int
F_15 ( BOOL V_17 ,
struct V_1 * V_1 , T_2 V_10 ,
void * V_18 , T_2 V_3 )
{
if ( V_10 + V_3 > V_1 -> V_3 )
return - V_19 ;
if ( V_17 )
F_16 ( V_1 -> V_11 + V_10 , V_18 , V_3 ) ;
else
F_17 ( V_18 , V_1 -> V_11 + V_10 , V_3 ) ;
return 0 ;
}
int
F_18 ( struct V_1 * V_1 , T_2 V_10 , void * V_20 ,
T_2 V_3 )
{
return F_15 ( FALSE , V_1 , V_10 , V_20 , V_3 ) ;
}
int
F_19 ( struct V_1 * V_1 , T_2 V_10 , void * V_21 ,
T_2 V_3 )
{
return F_15 ( TRUE , V_1 , V_10 , V_21 , V_3 ) ;
}
void
F_4 ( struct V_1 * V_1 )
{
if ( V_1 == NULL )
return;
if ( ! V_1 -> V_7 )
F_8 ( V_1 ) ;
F_20 ( V_1 ) ;
}
