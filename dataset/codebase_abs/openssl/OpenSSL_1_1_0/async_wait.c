T_1 * F_1 ( void )
{
return F_2 ( sizeof( T_1 ) ) ;
}
void F_3 ( T_1 * V_1 )
{
struct V_2 * V_3 ;
struct V_2 * V_4 ;
if ( V_1 == NULL )
return;
V_3 = V_1 -> V_5 ;
while ( V_3 != NULL ) {
if ( ! V_3 -> V_6 ) {
if ( V_3 -> V_7 != NULL )
V_3 -> V_7 ( V_1 , V_3 -> V_8 , V_3 -> V_9 , V_3 -> V_10 ) ;
}
V_4 = V_3 -> V_4 ;
F_4 ( V_3 ) ;
V_3 = V_4 ;
}
F_4 ( V_1 ) ;
}
int F_5 ( T_1 * V_1 , const void * V_8 ,
T_2 V_9 , void * V_10 ,
void (* V_7)( T_1 * , const void * ,
T_2 , void * ) )
{
struct V_2 * V_11 ;
V_11 = F_2 ( sizeof *V_11 ) ;
if ( V_11 == NULL )
return 0 ;
V_11 -> V_8 = V_8 ;
V_11 -> V_9 = V_9 ;
V_11 -> V_10 = V_10 ;
V_11 -> V_7 = V_7 ;
V_11 -> V_12 = 1 ;
V_11 -> V_4 = V_1 -> V_5 ;
V_1 -> V_5 = V_11 ;
V_1 -> V_13 ++ ;
return 1 ;
}
int F_6 ( T_1 * V_1 , const void * V_8 ,
T_2 * V_9 , void * * V_10 )
{
struct V_2 * V_3 ;
V_3 = V_1 -> V_5 ;
while ( V_3 != NULL ) {
if ( V_3 -> V_6 ) {
V_3 = V_3 -> V_4 ;
continue;
}
if ( V_3 -> V_8 == V_8 ) {
* V_9 = V_3 -> V_9 ;
* V_10 = V_3 -> V_10 ;
return 1 ;
}
V_3 = V_3 -> V_4 ;
}
return 0 ;
}
int F_7 ( T_1 * V_1 , T_2 * V_9 ,
T_3 * V_14 )
{
struct V_2 * V_3 ;
V_3 = V_1 -> V_5 ;
* V_14 = 0 ;
while ( V_3 != NULL ) {
if ( V_3 -> V_6 ) {
V_3 = V_3 -> V_4 ;
continue;
}
if ( V_9 != NULL ) {
* V_9 = V_3 -> V_9 ;
V_9 ++ ;
}
( * V_14 ) ++ ;
V_3 = V_3 -> V_4 ;
}
return 1 ;
}
int F_8 ( T_1 * V_1 , T_2 * V_15 ,
T_3 * V_16 , T_2 * V_17 ,
T_3 * V_18 )
{
struct V_2 * V_3 ;
* V_16 = V_1 -> V_13 ;
* V_18 = V_1 -> V_19 ;
if ( V_15 == NULL && V_17 == NULL )
return 1 ;
V_3 = V_1 -> V_5 ;
while ( V_3 != NULL ) {
if ( V_3 -> V_6 && ! V_3 -> V_12 && ( V_17 != NULL ) ) {
* V_17 = V_3 -> V_9 ;
V_17 ++ ;
}
if ( V_3 -> V_12 && ! V_3 -> V_6 && ( V_15 != NULL ) ) {
* V_15 = V_3 -> V_9 ;
V_15 ++ ;
}
V_3 = V_3 -> V_4 ;
}
return 1 ;
}
int F_9 ( T_1 * V_1 , const void * V_8 )
{
struct V_2 * V_3 ;
V_3 = V_1 -> V_5 ;
while ( V_3 != NULL ) {
if ( V_3 -> V_6 ) {
V_3 = V_3 -> V_4 ;
continue;
}
if ( V_3 -> V_8 == V_8 ) {
V_3 -> V_6 = 1 ;
V_1 -> V_19 ++ ;
return 1 ;
}
V_3 = V_3 -> V_4 ;
}
return 0 ;
}
void F_10 ( T_1 * V_1 )
{
struct V_2 * V_3 , * V_20 = NULL ;
V_1 -> V_13 = 0 ;
V_1 -> V_19 = 0 ;
V_3 = V_1 -> V_5 ;
while ( V_3 != NULL ) {
if ( V_3 -> V_6 ) {
if ( V_20 == NULL )
V_1 -> V_5 = V_3 -> V_4 ;
else
V_20 -> V_4 = V_3 -> V_4 ;
F_4 ( V_3 ) ;
if ( V_20 == NULL )
V_3 = V_1 -> V_5 ;
else
V_3 = V_20 -> V_4 ;
continue;
}
if ( V_3 -> V_12 ) {
V_3 -> V_12 = 0 ;
}
V_20 = V_3 ;
V_3 = V_3 -> V_4 ;
}
}
