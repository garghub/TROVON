static int F_1 ( const T_1 * V_1 )
{
return V_2 ;
}
static void F_2 ( T_1 * V_1 )
{
T_2 * V_3 = F_3 ( V_1 ) ;
if ( V_3 ) {
if ( V_3 -> V_4 )
F_4 ( V_3 -> V_4 , V_3 -> V_5 ) ;
F_5 ( V_3 ) ;
}
}
static int F_6 ( T_1 * V_1 , int V_6 , long V_7 , void * V_8 )
{
switch ( V_6 ) {
case V_9 :
* ( int * ) V_8 = V_10 ;
return 1 ;
default:
return - 2 ;
}
}
static int F_7 ( const T_1 * V_11 , const T_1 * V_12 )
{
return F_8 ( F_3 ( V_11 ) , F_3 ( V_12 ) ) ;
}
static int F_9 ( T_1 * V_1 ,
const unsigned char * * V_13 , int V_14 )
{
T_2 * V_3 ;
V_3 = F_10 () ;
if ( V_3 == NULL || ! F_11 ( V_3 , * V_13 , V_14 ) )
goto V_15;
if ( ! F_12 ( V_1 , V_16 , V_3 ) )
goto V_15;
return 1 ;
V_15:
F_5 ( V_3 ) ;
return 0 ;
}
static int F_13 ( const T_1 * V_1 , unsigned char * * V_13 )
{
int V_17 ;
T_2 * V_3 = F_3 ( V_1 ) ;
if ( V_13 ) {
if ( ! * V_13 ) {
* V_13 = F_14 ( V_3 -> V_5 ) ;
if ( * V_13 == NULL )
return - 1 ;
V_17 = 0 ;
} else
V_17 = 1 ;
memcpy ( * V_13 , V_3 -> V_4 , V_3 -> V_5 ) ;
if ( V_17 )
* V_13 += V_3 -> V_5 ;
}
return V_3 -> V_5 ;
}
