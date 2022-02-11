static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
V_7 = F_2 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_6 = F_3 ( & V_2 -> V_8 , ( void * ) V_4 -> V_9 , sizeof( * V_6 ) ,
V_10 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_12 = & V_2 -> V_13 [ 0 ] ;
V_6 -> V_14 = V_2 -> V_14 ;
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
V_7 = F_6 ( & V_2 -> V_8 , V_6 ) ;
if ( V_7 )
return V_7 ;
F_7 ( & V_2 -> V_8 ) ;
F_8 ( & V_2 -> V_8 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_8 ) ;
F_11 ( & V_2 -> V_8 ) ;
F_12 ( & V_2 -> V_8 ) ;
}
