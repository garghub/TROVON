static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 (trig, &trigger_list, next_trig) {
if ( strcmp ( L_1 , V_4 -> V_5 ) )
continue;
if ( V_2 -> V_6 )
F_3 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_7 , & V_4 -> V_8 ) ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_6 = V_4 ;
if ( V_4 -> V_11 )
V_4 -> V_11 ( V_2 ) ;
break;
}
}
static int F_5 ( struct V_12 * V_13 ,
unsigned long V_14 , void * V_15 )
{
struct V_1 * V_2 ;
F_2 (led_cdev, &leds_list, node)
if ( V_2 -> V_16 & V_17 )
F_1 ( V_2 ) ;
return V_18 ;
}
static long F_6 ( int V_19 )
{
F_7 ( V_6 , V_19 ? V_20 : V_21 ) ;
return 0 ;
}
static int T_1 F_8 ( void )
{
F_9 ( & V_22 ,
& V_23 ) ;
F_10 ( L_1 , & V_6 ) ;
V_24 = F_6 ;
return 0 ;
}
