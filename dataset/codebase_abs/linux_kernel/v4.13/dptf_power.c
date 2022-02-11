static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 ;
unsigned long long V_6 ;
int V_7 ;
V_4 = F_2 ( & ( V_2 -> V_8 ) ) ;
if ( ! V_4 )
return - V_9 ;
V_5 = F_3 ( V_4 -> V_10 , L_1 , NULL , & V_6 ) ;
if ( F_4 ( V_5 ) )
return - V_9 ;
if ( V_6 != 0x11 )
return - V_9 ;
V_7 = F_5 ( & V_2 -> V_8 . V_11 ,
& V_12 ) ;
if ( V_7 )
return V_7 ;
F_6 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_8 . V_11 , & V_12 ) ;
return 0 ;
}
