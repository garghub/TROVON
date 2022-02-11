T_1
F_1 ( const T_2 * V_1 )
{
return V_1 -> V_2 ;
}
T_3 *
F_2 ( const T_2 * V_1 )
{
return V_1 -> V_3 ;
}
T_3 *
F_3 ( const T_3 * V_4 )
{
return V_4 -> V_5 ;
}
void *
F_4 ( const T_3 * V_4 )
{
return V_4 -> V_6 ;
}
static T_3 * *
F_5 ( T_2 * V_1 , void * V_6 )
{
T_3 * * V_7 ;
V_7 = & ( V_1 -> V_3 ) ;
while ( * V_7 && ( * V_7 ) -> V_6 != V_6 ) {
V_7 = & ( ( * V_7 ) -> V_5 ) ;
}
return V_7 ;
}
void
F_6 ( T_2 * V_1 , void * V_6 )
{
T_3 * V_4 ;
T_3 * * V_8 ;
V_8 = F_5 ( V_1 , V_6 ) ;
V_4 = * V_8 ;
if ( V_4 == NULL ) {
return;
}
* V_8 = V_4 -> V_5 ;
V_1 -> V_2 -- ;
F_7 ( V_1 -> V_9 , V_4 ) ;
}
void
F_8 ( T_2 * V_1 , void * V_6 )
{
T_3 * V_10 ;
V_10 = F_9 ( V_1 -> V_9 , T_3 ) ;
V_10 -> V_6 = V_6 ;
V_10 -> V_5 = V_1 -> V_3 ;
V_1 -> V_3 = V_10 ;
V_1 -> V_2 ++ ;
}
T_2 *
F_10 ( T_4 * V_9 )
{
T_2 * V_1 ;
V_1 = ( T_2 * ) F_11 ( V_9 , sizeof( T_2 ) ) ;
V_1 -> V_2 = 0 ;
V_1 -> V_3 = NULL ;
V_1 -> V_9 = V_9 ;
return V_1 ;
}
