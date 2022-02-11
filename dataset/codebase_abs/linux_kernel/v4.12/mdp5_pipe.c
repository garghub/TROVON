struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 , T_1 V_6 , T_1 V_7 )
{
struct V_8 * V_9 = V_3 -> V_10 -> V_11 ;
struct V_12 * V_12 = F_2 ( F_3 ( V_9 -> V_13 ) ) ;
struct V_14 * V_15 ;
struct V_16 * V_17 , * V_18 ;
struct V_1 * V_19 = NULL ;
int V_20 ;
V_15 = F_4 ( V_3 ) ;
if ( F_5 ( V_15 ) )
return F_6 ( V_15 ) ;
V_17 = & V_12 -> V_15 -> V_19 ;
V_18 = & V_15 -> V_19 ;
for ( V_20 = 0 ; V_20 < V_12 -> V_21 ; V_20 ++ ) {
struct V_1 * V_22 = V_12 -> V_23 [ V_20 ] ;
if ( V_18 -> V_24 [ V_22 -> V_25 ] ||
V_17 -> V_24 [ V_22 -> V_25 ] )
continue;
if ( V_6 & ~ V_22 -> V_6 )
continue;
if ( V_22 -> V_6 & V_26 &&
V_5 -> type != V_27 )
continue;
if ( ! V_19 || ( F_7 ( V_22 -> V_6 & ~ V_6 ) <
F_7 ( V_19 -> V_6 & ~ V_6 ) ) )
V_19 = V_22 ;
}
if ( ! V_19 )
return F_8 ( - V_28 ) ;
if ( V_12 -> V_29 ) {
int V_30 ;
F_9 ( L_1 , V_19 -> V_31 ) ;
V_30 = F_10 ( V_12 -> V_29 , & V_15 -> V_29 ,
V_19 -> V_32 , V_7 ) ;
if ( V_30 )
return F_8 ( - V_28 ) ;
V_19 -> V_7 = V_7 ;
}
F_9 ( L_2 ,
V_19 -> V_31 , V_5 -> V_31 , V_6 ) ;
V_18 -> V_24 [ V_19 -> V_25 ] = V_5 ;
return V_19 ;
}
void F_11 ( struct V_2 * V_3 , struct V_1 * V_19 )
{
struct V_8 * V_9 = V_3 -> V_10 -> V_11 ;
struct V_12 * V_12 = F_2 ( F_3 ( V_9 -> V_13 ) ) ;
struct V_14 * V_15 = F_4 ( V_3 ) ;
struct V_16 * V_18 = & V_15 -> V_19 ;
if ( ! V_19 )
return;
if ( F_12 ( ! V_18 -> V_24 [ V_19 -> V_25 ] ) )
return;
F_9 ( L_3 , V_19 -> V_31 ,
V_18 -> V_24 [ V_19 -> V_25 ] -> V_31 ) ;
if ( V_12 -> V_29 ) {
F_9 ( L_4 , V_19 -> V_31 ) ;
F_13 ( V_12 -> V_29 , & V_15 -> V_29 , V_19 -> V_32 ) ;
}
V_18 -> V_24 [ V_19 -> V_25 ] = NULL ;
}
void F_14 ( struct V_1 * V_19 )
{
F_15 ( V_19 ) ;
}
struct V_1 * F_16 ( enum V_33 V_32 ,
T_1 V_34 , T_1 V_6 )
{
struct V_1 * V_19 ;
V_19 = F_17 ( sizeof( * V_19 ) , V_35 ) ;
if ( ! V_19 )
return F_8 ( - V_28 ) ;
V_19 -> V_31 = F_18 ( V_32 ) ;
V_19 -> V_32 = V_32 ;
V_19 -> V_34 = V_34 ;
V_19 -> V_6 = V_6 ;
V_19 -> V_36 = F_19 ( V_32 ) ;
return V_19 ;
}
