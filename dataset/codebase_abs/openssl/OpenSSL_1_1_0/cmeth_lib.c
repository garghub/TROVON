T_1 * F_1 ( int V_1 , int V_2 , int V_3 )
{
T_1 * V_4 = F_2 ( sizeof( T_1 ) ) ;
if ( V_4 != NULL ) {
V_4 -> V_5 = V_1 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_3 = V_3 ;
}
return V_4 ;
}
T_1 * F_3 ( const T_1 * V_4 )
{
T_1 * V_6 = F_1 ( V_4 -> V_5 , V_4 -> V_2 ,
V_4 -> V_3 ) ;
if ( V_6 != NULL )
memcpy ( V_6 , V_4 , sizeof( * V_6 ) ) ;
return V_6 ;
}
void F_4 ( T_1 * V_4 )
{
F_5 ( V_4 ) ;
}
int F_6 ( T_1 * V_4 , int V_7 )
{
V_4 -> V_7 = V_7 ;
return 1 ;
}
int F_7 ( T_1 * V_4 , unsigned long V_8 )
{
V_4 -> V_8 = V_8 ;
return 1 ;
}
int F_8 ( T_1 * V_4 , int V_9 )
{
V_4 -> V_9 = V_9 ;
return 1 ;
}
int F_9 ( T_1 * V_4 ,
int (* F_10) ( T_2 * V_10 ,
const unsigned char * V_11 ,
const unsigned char * V_12 ,
int V_13 ) )
{
V_4 -> F_10 = F_10 ;
return 1 ;
}
int F_11 ( T_1 * V_4 ,
int (* F_12) ( T_2 * V_10 ,
unsigned char * V_14 ,
const unsigned char * V_15 ,
T_3 V_16 ) )
{
V_4 -> F_12 = F_12 ;
return 1 ;
}
int F_13 ( T_1 * V_4 ,
int (* F_14) ( T_2 * ) )
{
V_4 -> F_14 = F_14 ;
return 1 ;
}
int F_15 ( T_1 * V_4 ,
int (* F_16) ( T_2 * ,
T_4 * ) )
{
V_4 -> F_16 = F_16 ;
return 1 ;
}
int F_17 ( T_1 * V_4 ,
int (* F_18) ( T_2 * ,
T_4 * ) )
{
V_4 -> F_18 = F_18 ;
return 1 ;
}
int F_19 ( T_1 * V_4 ,
int (* F_20) ( T_2 * , int type ,
int V_17 , void * V_18 ) )
{
V_4 -> F_20 = F_20 ;
return 1 ;
}
