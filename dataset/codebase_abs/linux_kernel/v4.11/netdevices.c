int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 = 0 ;
ASSERT ( V_3 > 0 ) ;
F_2 () ;
F_3 (&init_net, dev) {
if ( V_6 -> type == V_10 && ! V_4 )
continue;
V_8 = F_4 ( V_6 ) ;
if ( ! V_8 )
continue;
F_5 (idev) {
V_2 [ V_9 ] . V_11 . V_12 = V_13 -> V_14 ;
V_2 [ V_9 ] . V_15 . V_12 = V_13 -> V_16 ;
V_2 [ V_9 ] . V_17 = V_6 -> V_17 ;
V_9 ++ ;
if ( V_9 >= V_3 )
goto V_18;
} F_6 ( V_8 ) ;
}
V_18:
F_7 () ;
return V_9 ;
}
