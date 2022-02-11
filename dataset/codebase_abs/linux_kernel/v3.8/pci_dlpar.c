static struct V_1 *
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_1 * V_5 = NULL ;
struct V_6 * V_7 ;
struct V_3 * V_8 ;
V_8 = F_2 ( V_2 ) ;
if ( V_8 == V_4 )
return V_2 ;
F_3 (tmp, &bus->children) {
V_5 = F_1 ( F_4 ( V_7 ) , V_4 ) ;
if ( V_5 )
break;
} ;
return V_5 ;
}
struct V_1 *
F_5 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_11 ;
if ( ! V_10 || ! V_10 -> V_12 || ! V_10 -> V_12 -> V_2 )
return NULL ;
return F_1 ( V_10 -> V_12 -> V_2 , V_4 ) ;
}
void F_6 ( struct V_1 * V_2 , int V_13 )
{
struct V_14 * V_15 , * V_7 ;
struct V_1 * V_16 ;
F_7 (child_bus, &bus->children, node)
F_6 ( V_16 , V_13 ) ;
F_8 ( L_1 ,
F_9 ( V_2 ) , V_2 -> V_17 ) ;
F_10 (dev, tmp, &bus->devices, bus_list) {
F_8 ( L_2 , F_11 ( V_15 ) ) ;
F_12 ( V_15 , V_13 ) ;
F_13 ( V_15 ) ;
}
}
void F_14 ( struct V_1 * V_2 )
{
F_6 ( V_2 , 1 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
int V_18 , V_19 , V_20 , V_21 , V_22 ;
struct V_14 * V_15 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_16 ( V_4 ) ;
V_20 = V_23 ;
if ( V_24 . V_25 )
V_20 = V_24 . V_25 ( V_2 ) ;
if ( V_20 == V_26 ) {
F_17 ( V_4 , V_2 ) ;
} else if ( V_20 == V_23 ) {
V_18 = F_18 ( F_19 ( V_4 -> V_5 ) -> V_27 ) ;
V_19 = F_20 ( V_2 , F_21 ( V_18 , 0 ) ) ;
if ( ! V_19 )
return;
F_22 ( V_2 ) ;
V_22 = V_2 -> V_28 . V_29 ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ )
F_7 (dev, &bus->devices, bus_list) {
if ( V_15 -> V_30 == V_31 ||
V_15 -> V_30 == V_32 )
V_22 = F_23 ( V_2 , V_15 , V_22 , V_21 ) ;
}
}
F_24 ( V_2 ) ;
}
struct V_33 * F_25 ( struct V_3 * V_4 )
{
struct V_33 * V_12 ;
F_8 ( L_3 , V_4 -> V_34 ) ;
V_12 = F_26 ( V_4 ) ;
if ( ! V_12 )
return NULL ;
F_27 ( V_12 ) ;
F_28 ( V_12 , V_4 , 0 ) ;
F_29 ( V_12 ) ;
F_30 ( V_12 ) ;
if ( V_4 -> V_5 )
F_16 ( V_4 ) ;
F_31 ( V_12 ) ;
F_24 ( V_12 -> V_2 ) ;
return V_12 ;
}
int F_32 ( struct V_33 * V_12 )
{
struct V_1 * V_35 = V_12 -> V_2 ;
struct V_36 * V_37 ;
int V_38 , V_39 ;
F_8 ( L_4 ,
F_9 ( V_35 ) , V_35 -> V_17 ) ;
if ( ! ( F_33 ( & V_35 -> V_40 ) && F_33 ( & V_35 -> V_41 ) ) )
return - V_42 ;
V_37 = & V_12 -> V_43 ;
if ( V_37 -> V_44 & V_45 ) {
V_38 = F_34 ( V_35 ) ;
if ( V_38 ) {
F_35 ( V_46 L_5 ,
V_47 , V_35 -> V_48 ) ;
return 1 ;
}
}
F_36 ( V_35 -> V_49 ) ;
V_12 -> V_2 = NULL ;
F_37 ( V_35 ) ;
if ( V_37 -> V_44 & V_45 )
F_38 ( V_37 ) ;
for ( V_39 = 0 ; V_39 < 3 ; ++ V_39 ) {
V_37 = & V_12 -> V_50 [ V_39 ] ;
if ( ! ( V_37 -> V_44 & V_51 ) )
continue;
F_38 ( V_37 ) ;
}
F_39 ( V_12 ) ;
return 0 ;
}
