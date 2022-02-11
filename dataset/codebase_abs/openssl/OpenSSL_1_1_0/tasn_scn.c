T_1 * F_1 ( int (* F_2) ( T_1 * V_1 ) )
{
T_1 * V_2 = F_3 ( sizeof( * V_2 ) ) ;
if ( V_2 == NULL ) {
F_4 ( V_3 , V_4 ) ;
return NULL ;
}
V_2 -> F_2 = F_2 ;
return V_2 ;
}
void F_5 ( T_1 * V_5 )
{
F_6 ( V_5 ) ;
}
const T_2 * F_7 ( T_1 * V_5 )
{
return V_5 -> V_6 ;
}
const T_3 * F_8 ( T_1 * V_5 )
{
return V_5 -> V_7 ;
}
unsigned long F_9 ( T_1 * V_5 )
{
return V_5 -> V_8 ;
}
void F_10 ( T_1 * V_5 , void * V_9 )
{
V_5 -> V_10 = V_9 ;
}
void * F_11 ( T_1 * V_5 )
{
return V_5 -> V_10 ;
}
