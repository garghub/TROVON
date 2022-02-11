void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( sizeof( struct V_4 ) , V_6 ) ;
if ( ! V_5 ) {
F_3 ( V_2 , V_7 , L_1 ,
sizeof( struct V_4 ) ) ;
return;
}
V_2 -> V_5 = V_5 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_8 = F_4 ( V_3 , NULL ) ;
if ( ! V_5 -> V_8 ) {
F_3 ( V_2 , V_7 , L_2 ) ;
return;
}
return;
}
void F_5 ( struct V_4 * V_5 )
{
if ( ! V_5 )
return;
F_6 ( V_5 -> V_8 ) ;
F_7 ( V_5 ) ;
V_5 = NULL ;
}
