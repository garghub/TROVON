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
struct V_13 * F_6 ( struct V_3 * V_4 )
{
struct V_13 * V_12 ;
F_7 ( L_1 , V_4 -> V_14 ) ;
V_12 = F_8 ( V_4 ) ;
if ( ! V_12 )
return NULL ;
F_9 ( V_12 ) ;
F_10 ( V_12 , V_4 , 0 ) ;
F_11 ( V_12 ) ;
F_12 ( V_12 ) ;
if ( V_4 -> V_5 )
F_13 ( V_4 ) ;
F_14 ( V_12 ) ;
F_15 ( V_12 -> V_2 ) ;
return V_12 ;
}
int F_16 ( struct V_13 * V_12 )
{
struct V_1 * V_15 = V_12 -> V_2 ;
struct V_16 * V_17 ;
int V_18 , V_19 ;
F_7 ( L_2 ,
F_17 ( V_15 ) , V_15 -> V_20 ) ;
if ( ! ( F_18 ( & V_15 -> V_21 ) && F_18 ( & V_15 -> V_22 ) ) )
return - V_23 ;
V_17 = & V_12 -> V_24 ;
if ( V_17 -> V_25 & V_26 ) {
V_18 = F_19 ( V_15 ) ;
if ( V_18 ) {
F_20 ( V_27 L_3 ,
V_28 , V_15 -> V_29 ) ;
return 1 ;
}
}
F_21 ( V_15 -> V_30 ) ;
V_12 -> V_2 = NULL ;
F_22 ( V_15 ) ;
if ( V_17 -> V_25 & V_26 )
F_23 ( V_17 ) ;
for ( V_19 = 0 ; V_19 < 3 ; ++ V_19 ) {
V_17 = & V_12 -> V_31 [ V_19 ] ;
if ( ! ( V_17 -> V_25 & V_32 ) )
continue;
F_23 ( V_17 ) ;
}
F_24 ( V_12 ) ;
return 0 ;
}
