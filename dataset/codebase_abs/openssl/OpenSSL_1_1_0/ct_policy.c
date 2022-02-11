T_1 * F_1 ( void )
{
T_1 * V_1 = F_2 ( sizeof( T_1 ) ) ;
if ( V_1 == NULL ) {
F_3 ( V_2 , V_3 ) ;
return NULL ;
}
return V_1 ;
}
void F_4 ( T_1 * V_1 )
{
if ( V_1 == NULL )
return;
F_5 ( V_1 -> V_4 ) ;
F_5 ( V_1 -> V_5 ) ;
F_6 ( V_1 ) ;
}
int F_7 ( T_1 * V_1 , T_2 * V_4 )
{
if ( ! F_8 ( V_4 ) )
return 0 ;
V_1 -> V_4 = V_4 ;
return 1 ;
}
int F_9 ( T_1 * V_1 , T_2 * V_5 )
{
if ( ! F_8 ( V_5 ) )
return 0 ;
V_1 -> V_5 = V_5 ;
return 1 ;
}
void F_10 ( T_1 * V_1 ,
T_3 * V_6 )
{
V_1 -> V_6 = V_6 ;
}
T_2 * F_11 ( const T_1 * V_1 )
{
return V_1 -> V_4 ;
}
T_2 * F_12 ( const T_1 * V_1 )
{
return V_1 -> V_5 ;
}
const T_3 * F_13 ( const T_1 * V_1 )
{
return V_1 -> V_6 ;
}
