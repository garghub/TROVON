static int F_1 ( struct V_1 * V_1 , int V_2 )
{
int V_3 ;
int V_4 ;
V_4 = V_5 [ V_2 ] ;
if ( V_4 < 0 )
return - V_6 ;
for ( V_3 = 0 ; V_3 < V_1 -> V_7 ; V_3 ++ ) {
struct V_8 * V_9 = V_1 -> V_10 [ V_3 ] ;
if ( V_9 -> V_2 == V_4 )
return V_9 -> V_11 ;
}
return - 1 ;
}
int F_2 ( struct V_12 * V_13 , struct V_14 * V_15 ,
T_1 V_16 , struct V_8 * * V_9 ,
struct V_8 * * V_17 )
{
struct V_18 * V_19 = V_13 -> V_20 -> V_21 ;
struct V_1 * V_1 = F_3 ( F_4 ( V_19 -> V_22 ) ) ;
struct V_23 * V_24 = F_5 ( V_13 ) ;
struct V_25 * V_26 ;
int V_3 ;
if ( F_6 ( V_24 ) )
return F_7 ( V_24 ) ;
V_26 = & V_24 -> V_27 ;
for ( V_3 = 0 ; V_3 < V_1 -> V_7 ; V_3 ++ ) {
struct V_8 * V_28 = V_1 -> V_10 [ V_3 ] ;
if ( V_26 -> V_29 [ V_28 -> V_11 ] &&
V_26 -> V_29 [ V_28 -> V_11 ] != V_15 )
continue;
if ( V_16 & ~ V_28 -> V_16 )
continue;
if ( V_17 ) {
int V_30 ;
V_30 = F_1 ( V_1 , V_28 -> V_2 ) ;
if ( V_30 < 0 )
return - V_6 ;
if ( V_26 -> V_29 [ V_30 ] )
continue;
* V_17 = V_1 -> V_10 [ V_30 ] ;
}
if ( ! ( * V_9 ) || V_28 -> V_16 & V_31 )
* V_9 = V_28 ;
}
if ( ! ( * V_9 ) )
return - V_32 ;
if ( V_17 && ! ( * V_17 ) )
return - V_32 ;
F_8 ( L_1 , ( * V_9 ) -> V_2 , V_15 -> V_33 ) ;
V_26 -> V_29 [ ( * V_9 ) -> V_11 ] = V_15 ;
if ( V_17 ) {
F_8 ( L_2 , ( * V_17 ) -> V_2 ,
V_15 -> V_33 ) ;
V_26 -> V_29 [ ( * V_17 ) -> V_11 ] = V_15 ;
}
return 0 ;
}
void F_9 ( struct V_12 * V_13 , struct V_8 * V_9 )
{
struct V_23 * V_24 = F_5 ( V_13 ) ;
struct V_25 * V_26 = & V_24 -> V_27 ;
if ( ! V_9 )
return;
if ( F_10 ( ! V_26 -> V_29 [ V_9 -> V_11 ] ) )
return;
F_8 ( L_3 , V_9 -> V_33 ,
V_26 -> V_29 [ V_9 -> V_11 ] -> V_33 ) ;
V_26 -> V_29 [ V_9 -> V_11 ] = NULL ;
}
void F_11 ( struct V_8 * V_9 )
{
F_12 ( V_9 ) ;
}
struct V_8 * F_13 ( const struct V_34 * V_2 )
{
struct V_8 * V_9 ;
V_9 = F_14 ( sizeof( * V_9 ) , V_35 ) ;
if ( ! V_9 )
return F_15 ( - V_32 ) ;
V_9 -> V_33 = V_36 [ V_2 -> V_37 ] ;
V_9 -> V_2 = V_2 -> V_37 ;
V_9 -> V_16 = V_2 -> V_16 ;
V_9 -> V_38 = V_2 -> V_38 ;
V_9 -> V_39 = V_2 -> V_39 ;
V_9 -> V_40 = F_16 ( V_2 -> V_37 ) ;
return V_9 ;
}
