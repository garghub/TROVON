int F_1 ( T_1 * V_1 , T_2 V_2 )
{
struct V_3 * V_4 ;
int V_5 = - V_6 ;
F_2 ( V_2 != V_7 ) ;
F_3 () ;
V_4 = F_4 ( & V_8 , V_9 ) ;
if ( V_4 ) {
memcpy ( V_1 , V_4 -> V_10 , V_2 ) ;
V_5 = 0 ;
}
F_5 () ;
return V_5 ;
}
int F_6 ( struct V_11 * V_12 , T_2 V_13 ,
bool V_14 )
{
struct V_3 * V_4 ;
struct V_15 * V_16 ;
int V_17 = 0 ;
ASSERT ( V_13 > 0 ) ;
F_3 () ;
F_7 (&init_net, dev) {
if ( V_4 -> type == V_18 && ! V_14 )
continue;
V_16 = F_8 ( V_4 ) ;
if ( ! V_16 )
continue;
F_9 (idev) {
V_12 [ V_17 ] . V_19 . V_20 = V_21 -> V_22 ;
V_12 [ V_17 ] . V_23 . V_20 = V_21 -> V_24 ;
V_12 [ V_17 ] . V_25 = V_4 -> V_25 ;
V_17 ++ ;
if ( V_17 >= V_13 )
goto V_26;
} F_10 ( V_16 ) ;
}
V_26:
F_5 () ;
return V_17 ;
}
