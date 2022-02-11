static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
V_7 = F_2 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_6 = F_3 ( & V_2 -> V_8 , sizeof( struct V_5 ) , V_9 ) ;
if ( ! V_6 )
return - V_10 ;
V_6 -> V_11 = V_2 -> V_11 ;
V_6 -> V_12 = V_13 ;
V_6 -> V_8 = & V_2 -> V_8 ;
V_6 -> V_14 = & V_15 ;
V_7 = F_4 ( V_2 , 1 << V_16 , F_5 ( V_2 ) ) ;
if ( V_7 )
return V_7 ;
V_6 -> V_17 = F_6 ( V_2 ) [ V_16 ] ;
F_7 ( V_2 ) ;
V_7 = F_8 ( V_6 ) ;
if ( V_7 )
return V_7 ;
F_9 ( V_2 , V_6 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_11 ( V_2 ) ;
F_12 ( V_6 ) ;
}
