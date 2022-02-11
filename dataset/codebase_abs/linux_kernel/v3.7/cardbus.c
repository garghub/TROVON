static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
F_2 (dev, &bus->devices, bus_list) {
T_1 V_6 ;
F_3 ( V_5 , V_7 , & V_6 ) ;
if ( V_6 ) {
V_5 -> V_3 = V_3 ;
F_4 ( V_5 , V_8 , V_5 -> V_3 ) ;
}
F_5 ( V_5 ) ;
if ( V_5 -> V_9 )
F_1 ( V_5 -> V_9 , V_3 ) ;
}
}
int T_2 F_6 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 -> V_9 ;
struct V_4 * V_5 ;
unsigned int V_13 , V_14 ;
V_11 -> V_15 = F_7 ( V_2 , F_8 ( 0 , 0 ) ) ;
F_9 ( V_2 ) ;
V_13 = V_2 -> V_16 . V_17 ;
for ( V_14 = 0 ; V_14 < 2 ; V_14 ++ )
F_2 (dev, &bus->devices, bus_list)
if ( V_5 -> V_18 == V_19 ||
V_5 -> V_18 == V_20 )
V_13 = F_10 ( V_2 , V_5 , V_13 , V_14 ) ;
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
F_1 ( V_2 , V_11 -> V_21 ) ;
if ( V_11 -> V_22 )
V_11 -> V_22 ( V_11 , V_2 ) ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
void F_15 ( struct V_10 * V_11 )
{
struct V_4 * V_23 , * V_5 , * V_24 ;
struct V_1 * V_2 ;
V_23 = V_11 -> V_12 ;
if ( ! V_23 )
return;
V_2 = V_23 -> V_9 ;
if ( ! V_2 )
return;
F_16 (dev, tmp, &bus->devices, bus_list)
F_17 ( V_5 ) ;
}
