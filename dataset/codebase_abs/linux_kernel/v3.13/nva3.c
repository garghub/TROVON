static int
F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
int V_9 = F_2 ( V_2 , V_3 , V_5 , V_6 , V_7 , V_8 ) ;
if ( V_9 == 0 ) {
struct V_10 * V_11 = ( void * ) * V_8 ;
V_9 = F_3 ( & V_11 -> V_12 , L_1 , 0 , 0 , 0 , 0 ,
V_13 ) ;
if ( V_9 )
return V_9 ;
V_11 -> V_12 . V_14 = 3 ;
}
return V_9 ;
}
