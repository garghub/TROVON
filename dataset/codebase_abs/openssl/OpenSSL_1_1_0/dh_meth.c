T_1 * F_1 ( const char * V_1 , int V_2 )
{
T_1 * V_3 = F_2 ( sizeof( T_1 ) ) ;
if ( V_3 != NULL ) {
V_3 -> V_1 = F_3 ( V_1 ) ;
if ( V_3 -> V_1 == NULL ) {
F_4 ( V_3 ) ;
F_5 ( V_4 , V_5 ) ;
return NULL ;
}
V_3 -> V_2 = V_2 ;
}
return V_3 ;
}
void F_6 ( T_1 * V_3 )
{
if ( V_3 != NULL ) {
F_4 ( V_3 -> V_1 ) ;
F_4 ( V_3 ) ;
}
}
T_1 * F_7 ( const T_1 * V_3 )
{
T_1 * V_6 ;
V_6 = F_8 ( sizeof( T_1 ) ) ;
if ( V_6 != NULL ) {
memcpy ( V_6 , V_3 , sizeof( * V_3 ) ) ;
V_6 -> V_1 = F_3 ( V_3 -> V_1 ) ;
if ( V_6 -> V_1 == NULL ) {
F_4 ( V_6 ) ;
F_5 ( V_7 , V_5 ) ;
return NULL ;
}
}
return V_6 ;
}
const char * F_9 ( const T_1 * V_3 )
{
return V_3 -> V_1 ;
}
int F_10 ( T_1 * V_3 , const char * V_1 )
{
char * V_8 ;
V_8 = F_3 ( V_1 ) ;
if ( V_8 == NULL ) {
F_5 ( V_9 , V_5 ) ;
return 0 ;
}
F_4 ( V_3 -> V_1 ) ;
V_3 -> V_1 = V_8 ;
return 1 ;
}
int F_11 ( T_1 * V_3 )
{
return V_3 -> V_2 ;
}
int F_12 ( T_1 * V_3 , int V_2 )
{
V_3 -> V_2 = V_2 ;
return 1 ;
}
void * F_13 ( const T_1 * V_3 )
{
return V_3 -> V_10 ;
}
int F_14 ( T_1 * V_3 , void * V_10 )
{
V_3 -> V_10 = V_10 ;
return 1 ;
}
int F_15 ( T_1 * V_3 , int (* F_16) ( T_2 * ) )
{
V_3 -> F_16 = F_16 ;
return 1 ;
}
int F_17 ( T_1 * V_3 ,
int (* F_18) ( unsigned char * V_11 , const T_3 * V_12 , T_2 * V_13 ) )
{
V_3 -> F_18 = F_18 ;
return 1 ;
}
int F_19 ( T_1 * V_3 ,
int (* F_20) ( const T_2 * , T_3 * , const T_3 * , const T_3 * ,
const T_3 * , T_4 * , T_5 * ) )
{
V_3 -> F_20 = F_20 ;
return 1 ;
}
int F_21 ( T_1 * V_3 , int (* F_22)( T_2 * ) )
{
V_3 -> F_22 = F_22 ;
return 1 ;
}
int F_23 ( T_1 * V_3 , int (* F_24) ( T_2 * ) )
{
V_3 -> F_24 = F_24 ;
return 1 ;
}
int F_25 ( T_1 * V_3 ,
int (* F_26) ( T_2 * , int , int , T_6 * ) )
{
V_3 -> F_26 = F_26 ;
return 1 ;
}
