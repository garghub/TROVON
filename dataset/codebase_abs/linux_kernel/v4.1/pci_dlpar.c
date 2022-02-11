static struct V_1 *
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_1 * V_5 = NULL ;
struct V_1 * V_6 ;
struct V_3 * V_7 ;
V_7 = F_2 ( V_2 ) ;
if ( V_7 == V_4 )
return V_2 ;
F_3 (tmp, &bus->children, node) {
V_5 = F_1 ( V_6 , V_4 ) ;
if ( V_5 )
break;
} ;
return V_5 ;
}
struct V_1 *
F_4 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
if ( ! V_9 || ! V_9 -> V_11 || ! V_9 -> V_11 -> V_2 )
return NULL ;
return F_1 ( V_9 -> V_11 -> V_2 , V_4 ) ;
}
struct V_12 * F_5 ( struct V_3 * V_4 )
{
struct V_12 * V_11 ;
F_6 ( L_1 , V_4 -> V_13 ) ;
V_11 = F_7 ( V_4 ) ;
if ( ! V_11 )
return NULL ;
F_8 ( V_11 ) ;
F_9 ( V_11 , V_4 , 0 ) ;
V_11 -> V_14 = V_15 ;
F_10 ( V_11 ) ;
F_11 ( V_11 ) ;
if ( V_4 -> V_5 )
F_12 ( F_13 ( V_4 ) ) ;
F_14 ( V_11 ) ;
F_15 ( V_11 -> V_2 ) ;
return V_11 ;
}
int F_16 ( struct V_12 * V_11 )
{
struct V_1 * V_16 = V_11 -> V_2 ;
struct V_17 * V_18 ;
int V_19 , V_20 ;
F_6 ( L_2 ,
F_17 ( V_16 ) , V_16 -> V_21 ) ;
if ( ! ( F_18 ( & V_16 -> V_22 ) && F_18 ( & V_16 -> V_23 ) ) )
return - V_24 ;
V_18 = & V_11 -> V_25 ;
if ( V_18 -> V_26 & V_27 ) {
V_19 = F_19 ( V_16 ) ;
if ( V_19 ) {
F_20 ( V_28 L_3 ,
V_29 , V_16 -> V_30 ) ;
return 1 ;
}
}
V_11 -> V_2 = NULL ;
F_21 ( V_16 ) ;
F_22 ( V_16 -> V_31 ) ;
if ( V_18 -> V_26 & V_27 )
F_23 ( V_18 ) ;
for ( V_20 = 0 ; V_20 < 3 ; ++ V_20 ) {
V_18 = & V_11 -> V_32 [ V_20 ] ;
if ( ! ( V_18 -> V_26 & V_33 ) )
continue;
F_23 ( V_18 ) ;
}
F_24 ( V_11 ) ;
return 0 ;
}
