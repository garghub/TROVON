int F_1 ( struct V_1 * V_1 , int * V_2 )
{
int V_3 ;
int V_4 ;
V_3 = F_2 ( V_5 , V_1 -> V_6 , V_2 ) ;
if ( V_3 < 0 ) {
if ( V_3 == - V_7 || V_3 == - V_8 ) {
F_3 ( L_1 ,
V_9 ) ;
V_3 = F_4 ( V_1 -> V_10 , V_11 ,
& V_4 ) ;
if ( V_3 < 0 ) {
F_3 ( L_2 ,
V_9 , V_1 -> V_12 , V_3 ) ;
} else {
V_3 = F_2 ( V_5 ,
V_1 -> V_6 , V_2 ) ;
}
} else if ( V_3 == - V_13 )
F_5 ( L_3 , V_9 ) ;
else
F_6 ( L_4 , V_9 ) ;
}
return V_3 ;
}
int F_7 ( struct V_1 * V_1 )
{
int V_3 , V_14 , V_2 ;
struct V_15 * V_16 ;
struct V_17 * F_5 = V_1 -> V_18 -> F_5 ;
F_5 -> V_19 = V_20 ;
V_1 -> V_2 = V_21 ;
V_3 = F_8 ( V_1 -> V_10 , & V_14 ) ;
if ( V_3 )
return V_3 ;
F_5 -> V_22 = V_14 ;
V_3 = F_1 ( V_1 , & V_2 ) ;
if ( V_3 )
return V_3 ;
V_16 = F_9 ( V_1 -> V_23 ) ;
if ( ! V_16 ) {
F_6 ( L_5 , V_9 , V_1 -> V_23 -> V_24 ) ;
return - V_25 ;
}
F_5 -> V_19 = V_21 ;
V_1 -> V_16 = V_16 ;
V_1 -> V_26 = & V_16 -> V_27 ;
if ( V_2 == V_28 ) {
F_5 -> V_19 = V_29 ;
V_1 -> V_2 = V_29 ;
if ( ! V_1 -> V_23 -> V_30 ) {
F_6 ( L_6 ,
V_9 , V_1 -> V_12 ) ;
return - V_25 ;
}
if ( F_10 ( & V_16 -> V_27 ) )
F_11 ( V_16 ) ;
if ( ! F_10 ( & V_16 -> V_27 ) ) {
F_5 -> V_19 = V_31 ;
V_1 -> V_2 = V_31 ;
}
if ( V_32 ) {
struct V_33 * V_34 ;
F_3 ( L_7 , V_9 , V_1 -> V_23 -> V_24 ) ;
F_12 (dev, &bus->devices, bus_list)
F_3 ( L_8 , F_13 ( V_34 ) ) ;
}
}
return 0 ;
}
