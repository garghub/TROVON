static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned int V_7 = V_4 -> V_8 [ 1 ] ;
unsigned int V_9 = V_4 -> V_8 [ 2 ] ;
int V_10 ;
V_6 = F_2 ( V_2 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_11 ;
V_10 = F_3 ( V_2 , V_4 -> V_8 [ 0 ] , 0x20 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_4 ( V_2 , V_7 , 0 ) ;
if ( V_10 )
return V_10 ;
if ( V_2 -> V_7 )
F_5 ( V_2 , V_9 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_12 ;
if ( V_6 )
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
}
