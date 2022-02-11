static T_1 F_1 ( T_2 V_1 , T_3 V_2 ,
void * V_3 , void * * V_4 )
{
* ( bool * ) V_3 = true ;
return V_5 ;
}
struct V_6 * F_2 ( struct V_6 * V_7 )
{
struct V_6 * V_8 ;
bool V_9 = false ;
for ( V_8 = V_7 ; V_8 -> V_10 [ 0 ] ; V_8 ++ )
if ( F_3 ( F_4 ( V_8 -> V_10 ,
F_1 ,
& V_9 , NULL ) ) && V_9 )
return V_8 ;
return NULL ;
}
