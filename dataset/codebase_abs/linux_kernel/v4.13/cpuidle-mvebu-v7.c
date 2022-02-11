static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
int V_6 ;
bool V_7 = false ;
F_2 () ;
if ( V_4 -> V_8 [ V_5 ] . V_9 & V_10 )
V_7 = true ;
V_6 = F_3 ( V_7 ) ;
F_4 () ;
if ( V_6 )
return V_6 ;
return V_5 ;
}
static int F_5 ( struct V_11 * V_12 )
{
const struct V_13 * V_14 = V_12 -> V_15 ;
if ( ! V_14 )
return - V_16 ;
F_3 = V_12 -> V_2 . V_17 ;
return F_6 ( (struct V_3 * ) V_14 -> V_18 , NULL ) ;
}
