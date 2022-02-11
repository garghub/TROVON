static struct V_1 * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_1 * V_5 = NULL ;
struct V_1 * V_6 ;
if ( F_2 ( V_2 ) == V_4 )
return V_2 ;
F_3 (tmp, &bus->children, node) {
V_5 = F_1 ( V_6 , V_4 ) ;
if ( V_5 )
break;
}
return V_5 ;
}
struct V_1 * F_4 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_5 ( V_4 ) ;
if ( ! V_8 || ! V_8 -> V_9 || ! V_8 -> V_9 -> V_2 )
return NULL ;
return F_1 ( V_8 -> V_9 -> V_2 , V_4 ) ;
}
void F_6 ( struct V_10 * V_11 )
{
struct V_12 * V_9 = F_7 ( V_11 -> V_2 ) ;
F_8 ( V_11 ) ;
if ( V_9 -> V_13 . V_14 )
V_9 -> V_13 . V_14 ( V_11 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_10 * V_11 , * V_6 ;
struct V_1 * V_15 ;
F_3 (child_bus, &bus->children, node)
F_9 ( V_15 ) ;
F_10 ( L_1 ,
F_11 ( V_2 ) , V_2 -> V_16 ) ;
F_12 (dev, tmp, &bus->devices, bus_list) {
F_10 ( L_2 , F_13 ( V_11 ) ) ;
F_14 ( V_11 ) ;
}
}
void F_15 ( struct V_1 * V_2 )
{
int V_17 , V_18 , V_19 , V_20 ;
struct V_10 * V_11 ;
struct V_12 * V_9 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_16 ( F_5 ( V_4 ) ) ;
V_9 = F_7 ( V_2 ) ;
V_18 = V_21 ;
if ( V_9 -> V_13 . V_22 )
V_18 = V_9 -> V_13 . V_22 ( V_2 ) ;
if ( V_18 == V_23 ) {
F_17 ( V_4 , V_2 ) ;
} else if ( V_18 == V_21 &&
V_4 -> V_5 && F_5 ( V_4 -> V_5 ) ) {
V_17 = F_18 ( F_5 ( V_4 -> V_5 ) -> V_24 ) ;
F_19 ( V_2 , F_20 ( V_17 , 0 ) ) ;
F_21 ( V_2 ) ;
V_20 = V_2 -> V_25 . V_26 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
F_3 (dev, &bus->devices, bus_list) {
if ( F_22 ( V_11 ) )
V_20 = F_23 ( V_2 , V_11 ,
V_20 , V_19 ) ;
}
}
}
F_24 ( V_2 ) ;
}
