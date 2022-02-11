void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
F_3 ( V_2 ) ;
if ( V_4 -> V_6 . V_7 )
V_4 -> V_6 . V_7 ( V_2 ) ;
}
void F_4 ( struct V_8 * V_5 )
{
struct V_1 * V_2 , * V_9 ;
struct V_8 * V_10 ;
F_5 (child_bus, &bus->children, node)
F_4 ( V_10 ) ;
F_6 ( L_1 ,
F_7 ( V_5 ) , V_5 -> V_11 ) ;
F_8 (dev, tmp, &bus->devices, bus_list) {
F_6 ( L_2 , F_9 ( V_2 ) ) ;
F_10 ( V_2 ) ;
}
}
void F_11 ( struct V_8 * V_5 )
{
int V_12 , V_13 , V_14 , V_15 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_16 * V_17 = F_12 ( V_5 ) ;
F_13 ( F_14 ( V_17 ) ) ;
V_4 = F_2 ( V_5 ) ;
V_13 = V_18 ;
if ( V_4 -> V_6 . V_19 )
V_13 = V_4 -> V_6 . V_19 ( V_5 ) ;
if ( V_13 == V_20 ) {
F_15 ( V_17 , V_5 ) ;
} else if ( V_13 == V_18 ) {
V_12 = F_16 ( F_14 ( V_17 -> V_21 ) -> V_22 ) ;
F_17 ( V_5 , F_18 ( V_12 , 0 ) ) ;
F_19 ( V_5 ) ;
V_15 = V_5 -> V_23 . V_24 ;
for ( V_14 = 0 ; V_14 < 2 ; V_14 ++ ) {
F_5 (dev, &bus->devices, bus_list) {
if ( F_20 ( V_2 ) )
V_15 = F_21 ( V_5 , V_2 ,
V_15 , V_14 ) ;
}
}
}
F_22 ( V_5 ) ;
}
