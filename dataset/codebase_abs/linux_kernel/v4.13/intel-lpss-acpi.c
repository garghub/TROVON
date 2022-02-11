static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_5 * V_6 ;
V_6 = F_2 ( V_7 , & V_2 -> V_8 ) ;
if ( ! V_6 )
return - V_9 ;
V_4 = F_3 ( & V_2 -> V_8 , ( void * ) V_6 -> V_10 , sizeof( * V_4 ) ,
V_11 ) ;
if ( ! V_4 )
return - V_12 ;
V_4 -> V_13 = F_4 ( V_2 , V_14 , 0 ) ;
V_4 -> V_15 = F_5 ( V_2 , 0 ) ;
F_6 ( & V_2 -> V_8 ) ;
F_7 ( & V_2 -> V_8 ) ;
return F_8 ( & V_2 -> V_8 , V_4 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_8 ) ;
F_11 ( & V_2 -> V_8 ) ;
return 0 ;
}
