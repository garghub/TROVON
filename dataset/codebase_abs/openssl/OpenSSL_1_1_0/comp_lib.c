T_1 * F_1 ( T_2 * V_1 )
{
T_1 * V_2 ;
if ( ( V_2 = F_2 ( sizeof( * V_2 ) ) ) == NULL )
return ( NULL ) ;
V_2 -> V_1 = V_1 ;
if ( ( V_2 -> V_1 -> V_3 != NULL ) && ! V_2 -> V_1 -> V_3 ( V_2 ) ) {
F_3 ( V_2 ) ;
V_2 = NULL ;
}
return ( V_2 ) ;
}
const T_2 * F_4 ( const T_1 * V_4 )
{
return V_4 -> V_1 ;
}
int F_5 ( const T_2 * V_1 )
{
return V_1 -> type ;
}
const char * F_6 ( const T_2 * V_1 )
{
return V_1 -> V_5 ;
}
void F_7 ( T_1 * V_4 )
{
if ( V_4 == NULL )
return;
if ( V_4 -> V_1 -> V_6 != NULL )
V_4 -> V_1 -> V_6 ( V_4 ) ;
F_3 ( V_4 ) ;
}
int F_8 ( T_1 * V_4 , unsigned char * V_7 , int V_8 ,
unsigned char * V_9 , int V_10 )
{
int V_2 ;
if ( V_4 -> V_1 -> V_11 == NULL ) {
return ( - 1 ) ;
}
V_2 = V_4 -> V_1 -> V_11 ( V_4 , V_7 , V_8 , V_9 , V_10 ) ;
if ( V_2 > 0 ) {
V_4 -> V_12 += V_10 ;
V_4 -> V_13 += V_2 ;
}
return ( V_2 ) ;
}
int F_9 ( T_1 * V_4 , unsigned char * V_7 , int V_8 ,
unsigned char * V_9 , int V_10 )
{
int V_2 ;
if ( V_4 -> V_1 -> V_14 == NULL ) {
return ( - 1 ) ;
}
V_2 = V_4 -> V_1 -> V_14 ( V_4 , V_7 , V_8 , V_9 , V_10 ) ;
if ( V_2 > 0 ) {
V_4 -> V_15 += V_10 ;
V_4 -> V_16 += V_2 ;
}
return ( V_2 ) ;
}
int F_10 ( const T_1 * V_17 )
{
return V_17 -> V_1 ? V_17 -> V_1 -> type : V_18 ;
}
