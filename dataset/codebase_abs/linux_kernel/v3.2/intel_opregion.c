int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 ;
void * V_7 ;
T_1 * V_8 ;
V_4 -> V_8 = NULL ;
F_2 ( V_2 -> V_9 , 0xfc , & V_6 ) ;
if ( V_6 == 0 )
return - V_10 ;
V_7 = F_3 ( V_6 , 8 * 1024 ) ;
if ( ! V_7 )
return - V_11 ;
V_8 = V_7 + 0x01ac ;
V_4 -> V_8 = V_8 ;
V_4 -> V_12 = F_4 ( V_8 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_8 )
F_6 ( V_4 -> V_8 ) ;
return 0 ;
}
