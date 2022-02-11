static struct V_1 *
F_1 ( struct V_2 * V_2 , struct V_1 * V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
unsigned int V_6 , V_7 , V_8 ;
V_7 = V_3 -> V_9 - V_4 ;
V_6 = V_4 - V_3 -> V_9 ;
if ( F_2 ( V_6 , V_7 ) > V_5 - V_4 - 1 ) {
V_7 = V_5 - V_4 - 1 ;
V_3 = F_3 ( V_2 ) ;
}
if ( F_2 ( V_6 , V_7 ) > V_4 && V_7 > V_4 ) {
V_6 = V_4 ;
V_3 = F_4 ( V_2 ) ;
}
if ( V_6 < V_7 )
for ( V_8 = 0 ; V_8 < V_6 ; V_8 ++ )
V_3 = F_5 ( V_3 ) ;
else
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
V_3 = F_6 ( V_3 ) ;
return V_3 ;
}
static int
F_7 ( struct V_2 * V_2 ,
const struct V_10 * V_11 )
{
const struct V_12 * V_13 = & V_11 -> V_14 . V_15 [ 0 ] ;
if ( V_13 -> type != V_16 ) {
F_8 ( L_1 ,
V_13 -> type , V_13 -> V_17 ) ;
return - V_18 ;
}
if ( V_2 -> V_19 != V_20 &&
V_13 -> V_17 != 0 && ( V_13 -> V_17 & ~ 0U ) != ~ 0U ) {
F_8 ( L_1 ,
V_13 -> type , V_13 -> V_17 ) ;
return - V_18 ;
}
if ( V_2 -> V_19 == V_20 && V_13 -> V_17 <= V_21 &&
V_13 -> V_17 != V_22 && V_13 -> V_17 != V_23 &&
V_13 -> V_17 != V_24 ) {
F_8 ( L_1 ,
V_13 -> type , V_13 -> V_17 ) ;
return - V_18 ;
}
return 0 ;
}
static int
F_9 ( struct V_2 * V_2 ,
const struct V_10 * V_11 , T_1 V_25 )
{
if ( V_11 -> V_14 . V_15 [ V_25 ] . type != V_26 )
return - V_18 ;
return 0 ;
}
static int
F_10 ( struct V_10 * V_11 , int V_4 , int V_27 )
{
struct V_28 * V_29 = V_11 -> V_30 ;
struct V_1 * V_3 = V_29 -> V_3 ;
V_3 = F_1 ( V_29 -> V_31 , V_3 , V_4 , V_11 -> V_31 -> V_32 ) ;
V_29 -> V_3 = V_3 ;
if ( V_3 -> V_33 . V_34 == V_35 ||
V_3 -> V_33 . V_36 == V_35 ) {
F_11 ( L_2 ) ;
return - V_18 ;
}
if ( V_3 -> V_33 . V_34 >= V_37 ||
V_3 -> V_33 . V_36 >= V_37 ) {
F_11 ( L_3 ) ;
return - V_18 ;
}
if ( V_3 -> V_33 . V_38 == ( V_39 | V_40 ) )
return F_7 ( V_29 -> V_31 , V_11 ) ;
if ( ( V_3 -> V_33 . V_38 & ~ V_41 ) == ( V_42 | V_43 ) )
return F_9 ( V_29 -> V_31 , V_11 ,
V_3 -> V_33 . V_34 ) ;
if ( ( V_3 -> V_33 . V_38 & ~ V_41 ) == ( V_44 | V_43 ) )
return F_9 ( V_29 -> V_31 , V_11 ,
V_3 -> V_33 . V_36 ) ;
return 0 ;
}
int F_12 ( struct V_2 * V_2 , struct V_45 * V_31 )
{
struct V_28 * V_29 ;
int V_46 ;
V_29 = F_13 ( sizeof( * V_29 ) , V_47 ) ;
if ( ! V_29 )
return - V_48 ;
V_29 -> V_31 = V_2 ;
V_29 -> V_3 = F_4 ( V_2 ) ;
V_46 = F_14 ( V_31 , & V_49 , V_29 ) ;
F_15 ( V_29 ) ;
return V_46 ;
}
