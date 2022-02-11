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
void F_6 ( struct V_1 * V_2 )
{
struct V_13 * V_14 , * V_7 ;
struct V_1 * V_15 ;
F_7 (child_bus, &bus->children, node)
F_6 ( V_15 ) ;
F_8 ( L_1 ,
F_9 ( V_2 ) , V_2 -> V_16 ) ;
F_10 (dev, tmp, &bus->devices, bus_list) {
F_8 ( L_2 , F_11 ( V_14 ) ) ;
F_12 ( V_14 ) ;
F_13 ( V_14 ) ;
}
}
void F_14 ( struct V_1 * V_2 )
{
int V_17 , V_18 , V_19 , V_20 , V_21 ;
struct V_13 * V_14 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_15 ( V_4 ) ;
V_19 = V_22 ;
if ( V_23 . V_24 )
V_19 = V_23 . V_24 ( V_2 ) ;
if ( V_19 == V_25 ) {
F_16 ( V_4 , V_2 ) ;
} else if ( V_19 == V_22 ) {
V_17 = F_17 ( F_18 ( V_4 -> V_5 ) -> V_26 ) ;
V_18 = F_19 ( V_2 , F_20 ( V_17 , 0 ) ) ;
if ( ! V_18 )
return;
F_21 ( V_2 ) ;
V_21 = V_2 -> V_27 ;
for ( V_20 = 0 ; V_20 < 2 ; V_20 ++ )
F_7 (dev, &bus->devices, bus_list) {
if ( V_14 -> V_28 == V_29 ||
V_14 -> V_28 == V_30 )
V_21 = F_22 ( V_2 , V_14 , V_21 , V_20 ) ;
}
}
F_23 ( V_2 ) ;
}
struct V_31 * T_1 F_24 ( struct V_3 * V_4 )
{
struct V_31 * V_12 ;
F_8 ( L_3 , V_4 -> V_32 ) ;
V_12 = F_25 ( V_4 ) ;
if ( ! V_12 )
return NULL ;
F_26 ( V_12 ) ;
F_27 ( V_12 , V_4 , 0 ) ;
F_28 ( V_12 ) ;
F_29 ( V_12 ) ;
if ( V_4 -> V_5 )
F_15 ( V_4 ) ;
F_30 ( V_12 ) ;
F_23 ( V_12 -> V_2 ) ;
return V_12 ;
}
int F_31 ( struct V_31 * V_12 )
{
struct V_1 * V_33 = V_12 -> V_2 ;
struct V_34 * V_35 ;
int V_36 , V_37 ;
F_8 ( L_4 ,
F_9 ( V_33 ) , V_33 -> V_16 ) ;
if ( ! ( F_32 ( & V_33 -> V_38 ) && F_32 ( & V_33 -> V_39 ) ) )
return - V_40 ;
V_35 = & V_12 -> V_41 ;
if ( V_35 -> V_42 & V_43 ) {
V_36 = F_33 ( V_33 ) ;
if ( V_36 ) {
F_34 ( V_44 L_5 ,
V_45 , V_33 -> V_46 ) ;
return 1 ;
}
}
F_35 ( V_33 -> V_47 ) ;
V_12 -> V_2 = NULL ;
F_36 ( V_33 ) ;
if ( V_35 -> V_42 & V_43 )
F_37 ( V_35 ) ;
for ( V_37 = 0 ; V_37 < 3 ; ++ V_37 ) {
V_35 = & V_12 -> V_48 [ V_37 ] ;
if ( ! ( V_35 -> V_42 & V_49 ) )
continue;
F_37 ( V_35 ) ;
}
F_38 ( V_12 ) ;
return 0 ;
}
