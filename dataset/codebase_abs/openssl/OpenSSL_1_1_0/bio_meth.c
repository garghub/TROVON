int F_1 ()
{
static int V_1 = V_2 ;
int V_3 ;
if ( ! F_2 ( & V_4 , V_5 ) ) {
F_3 ( V_6 , V_7 ) ;
return - 1 ;
}
if ( ! F_4 ( & V_1 , 1 , & V_3 , V_8 ) )
return - 1 ;
return V_3 ;
}
T_1 * F_5 ( int type , const char * V_9 )
{
T_1 * V_10 = F_6 ( sizeof( T_1 ) ) ;
if ( V_10 != NULL ) {
V_10 -> type = type ;
V_10 -> V_9 = V_9 ;
}
return V_10 ;
}
void F_7 ( T_1 * V_10 )
{
F_8 ( V_10 ) ;
}
int F_9 ( T_1 * V_10 ,
int (* F_10) ( T_2 * , const char * , int ) )
{
V_10 -> F_10 = F_10 ;
return 1 ;
}
int F_11 ( T_1 * V_10 ,
int (* F_12) ( T_2 * , char * , int ) )
{
V_10 -> F_12 = F_12 ;
return 1 ;
}
int F_13 ( T_1 * V_10 ,
int (* F_14) ( T_2 * , const char * ) )
{
V_10 -> F_14 = F_14 ;
return 1 ;
}
int F_15 ( T_1 * V_10 ,
int (* F_16) ( T_2 * , char * , int ) )
{
V_10 -> F_16 = F_16 ;
return 1 ;
}
int F_17 ( T_1 * V_10 ,
long (* F_18) ( T_2 * , int , long , void * ) )
{
V_10 -> F_18 = F_18 ;
return 1 ;
}
int F_19 ( T_1 * V_10 , int (* F_20) ( T_2 * ) )
{
V_10 -> F_20 = F_20 ;
return 1 ;
}
int F_21 ( T_1 * V_10 , int (* F_22) ( T_2 * ) )
{
V_10 -> F_22 = F_22 ;
return 1 ;
}
int F_23 ( T_1 * V_10 ,
long (* F_24) ( T_2 * , int ,
T_3 * ) )
{
V_10 -> F_24 = F_24 ;
return 1 ;
}
