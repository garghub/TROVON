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
if ( V_2 -> V_16 == V_17 )
return 0 ;
if ( V_13 -> type != V_18 ) {
F_8 ( L_1 ,
V_13 -> type , V_13 -> V_19 ) ;
return - V_20 ;
}
if ( V_2 -> V_16 != V_21 &&
V_13 -> V_19 != 0 && ( V_13 -> V_19 & ~ 0U ) != ~ 0U ) {
F_8 ( L_1 ,
V_13 -> type , V_13 -> V_19 ) ;
return - V_20 ;
}
if ( V_2 -> V_16 == V_21 && V_13 -> V_19 <= V_22 &&
V_13 -> V_19 != V_23 && V_13 -> V_19 != V_24 &&
V_13 -> V_19 != V_25 ) {
F_8 ( L_1 ,
V_13 -> type , V_13 -> V_19 ) ;
return - V_20 ;
}
return 0 ;
}
static int
F_9 ( struct V_2 * V_2 ,
const struct V_10 * V_11 , T_1 V_26 )
{
if ( V_11 -> V_14 . V_15 [ V_26 ] . type != V_27 )
return - V_20 ;
return 0 ;
}
static int
F_10 ( struct V_10 * V_11 , int V_4 , int V_28 )
{
struct V_29 * V_30 = V_11 -> V_31 ;
struct V_1 * V_3 = V_30 -> V_3 ;
V_3 = F_1 ( V_30 -> V_32 , V_3 , V_4 , V_11 -> V_32 -> V_33 ) ;
V_30 -> V_3 = V_3 ;
if ( V_3 -> V_34 . V_35 == V_36 ||
V_3 -> V_34 . V_37 == V_36 ) {
F_11 ( L_2 ) ;
return - V_20 ;
}
if ( V_3 -> V_34 . V_35 >= V_38 ||
V_3 -> V_34 . V_37 >= V_38 ) {
F_11 ( L_3 ) ;
return - V_20 ;
}
if ( V_3 -> V_34 . V_39 == ( V_40 | V_41 ) )
return F_7 ( V_30 -> V_32 , V_11 ) ;
if ( ( V_3 -> V_34 . V_39 & ~ V_42 ) == ( V_43 | V_44 ) )
return F_9 ( V_30 -> V_32 , V_11 ,
V_3 -> V_34 . V_35 ) ;
if ( ( V_3 -> V_34 . V_39 & ~ V_42 ) == ( V_45 | V_44 ) )
return F_9 ( V_30 -> V_32 , V_11 ,
V_3 -> V_34 . V_37 ) ;
return 0 ;
}
int F_12 ( struct V_2 * V_2 , struct V_46 * V_32 )
{
struct V_29 * V_30 ;
int V_47 ;
V_30 = F_13 ( sizeof( * V_30 ) , V_48 ) ;
if ( ! V_30 )
return - V_49 ;
V_30 -> V_32 = V_2 ;
V_30 -> V_3 = F_4 ( V_2 ) ;
V_47 = F_14 ( V_32 , & V_50 , V_30 ) ;
F_15 ( V_30 ) ;
return V_47 ;
}
