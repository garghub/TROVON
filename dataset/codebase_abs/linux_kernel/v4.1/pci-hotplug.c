void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
void F_3 ( struct V_3 * V_4 )
{
struct V_1 * V_2 , * V_5 ;
struct V_3 * V_6 ;
F_4 (child_bus, &bus->children, node)
F_3 ( V_6 ) ;
F_5 ( L_1 ,
F_6 ( V_4 ) , V_4 -> V_7 ) ;
F_7 (dev, tmp, &bus->devices, bus_list) {
F_5 ( L_2 , F_8 ( V_2 ) ) ;
F_9 ( V_2 ) ;
}
}
void F_10 ( struct V_3 * V_4 )
{
int V_8 , V_9 , V_10 , V_11 ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
struct V_14 * V_15 = F_11 ( V_4 ) ;
F_12 ( F_13 ( V_15 ) ) ;
V_13 = F_14 ( V_4 ) ;
V_9 = V_16 ;
if ( V_13 -> V_17 . V_18 )
V_9 = V_13 -> V_17 . V_18 ( V_4 ) ;
if ( V_9 == V_19 ) {
F_15 ( V_15 , V_4 ) ;
} else if ( V_9 == V_16 ) {
V_8 = F_16 ( F_13 ( V_15 -> V_20 ) -> V_21 ) ;
F_17 ( V_4 , F_18 ( V_8 , 0 ) ) ;
F_19 ( V_4 ) ;
V_11 = V_4 -> V_22 . V_23 ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
F_4 (dev, &bus->devices, bus_list) {
if ( F_20 ( V_2 ) )
V_11 = F_21 ( V_4 , V_2 ,
V_11 , V_10 ) ;
}
}
}
F_22 ( V_4 ) ;
}
