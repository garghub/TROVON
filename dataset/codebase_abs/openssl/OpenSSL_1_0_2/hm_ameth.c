static int F_1 ( const T_1 * V_1 )
{
return V_2 ;
}
static void F_2 ( T_1 * V_1 )
{
T_2 * V_3 = ( T_2 * ) V_1 -> V_1 . V_4 ;
if ( V_3 ) {
if ( V_3 -> V_5 )
F_3 ( V_3 -> V_5 , V_3 -> V_6 ) ;
F_4 ( V_3 ) ;
}
}
static int F_5 ( T_1 * V_1 , int V_7 , long V_8 , void * V_9 )
{
switch ( V_7 ) {
case V_10 :
* ( int * ) V_9 = V_11 ;
return 1 ;
default:
return - 2 ;
}
}
static int F_6 ( T_1 * V_1 ,
const unsigned char * * V_12 , int V_13 )
{
T_2 * V_3 ;
V_3 = F_7 () ;
if ( ! V_3 || ! F_8 ( V_3 , * V_12 , V_13 ) )
return 0 ;
F_9 ( V_1 , V_14 , V_3 ) ;
return 1 ;
}
static int F_10 ( const T_1 * V_1 , unsigned char * * V_12 )
{
int V_15 ;
T_2 * V_3 = ( T_2 * ) V_1 -> V_1 . V_4 ;
if ( V_12 ) {
if ( ! * V_12 ) {
* V_12 = F_11 ( V_3 -> V_6 ) ;
V_15 = 0 ;
} else
V_15 = 1 ;
memcpy ( * V_12 , V_3 -> V_5 , V_3 -> V_6 ) ;
if ( V_15 )
* V_12 += V_3 -> V_6 ;
}
return V_3 -> V_6 ;
}
