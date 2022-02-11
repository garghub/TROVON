static int F_1 ( T_1 V_1 )
{
return 4 ;
}
static int F_2 ( T_1 V_1 , T_2 V_2 , void * V_3 )
{
return 0 ;
}
void T_3 F_3 ( struct V_4 * V_5 )
{
struct V_4 * V_6 ;
V_6 = F_4 ( V_5 , sizeof( struct V_4 ) ,
& V_7 ) ;
if ( ! V_6 -> V_8 )
V_6 -> V_8 = F_2 ;
if ( ! V_6 -> V_9 )
V_6 -> V_9 = F_1 ;
}
