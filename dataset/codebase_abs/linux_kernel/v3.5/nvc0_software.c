T_1
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 [ V_7 ] ;
return V_5 -> V_8 [ V_3 ] . V_9 ;
}
static int
F_2 ( struct V_1 * V_2 , int V_10 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_16 * V_17 = F_3 ( V_12 , V_7 ) ;
struct V_4 * V_5 ;
int V_18 = 0 , V_19 ;
V_5 = F_4 ( sizeof( * V_5 ) , V_20 ) ;
if ( ! V_5 )
return - V_21 ;
F_5 ( & V_5 -> V_22 ) ;
V_2 -> V_6 [ V_10 ] = V_5 ;
for ( V_19 = 0 ; ! V_18 && V_19 < V_12 -> V_23 . V_24 ; V_19 ++ ) {
struct V_25 * V_26 ;
if ( V_14 -> V_27 >= V_28 )
V_26 = F_6 ( V_12 , V_19 ) ;
else
V_26 = F_7 ( V_12 ) -> V_3 [ V_19 ] . V_29 . V_26 ;
V_18 = F_8 ( V_26 , V_2 -> V_30 , & V_5 -> V_8 [ V_19 ] ) ;
}
if ( V_18 )
V_17 -> V_22 . V_22 . V_31 ( V_2 , V_10 ) ;
return V_18 ;
}
static void
F_9 ( struct V_1 * V_2 , int V_10 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_4 * V_5 = V_2 -> V_6 [ V_10 ] ;
int V_19 ;
if ( V_14 -> V_27 >= V_28 ) {
for ( V_19 = 0 ; V_19 < V_12 -> V_23 . V_24 ; V_19 ++ ) {
struct V_25 * V_26 = F_6 ( V_12 , V_19 ) ;
F_10 ( V_26 , & V_5 -> V_8 [ V_19 ] ) ;
}
} else
if ( V_14 -> V_27 >= V_32 ) {
struct F_7 * V_33 = F_7 ( V_12 ) ;
for ( V_19 = 0 ; V_19 < V_12 -> V_23 . V_24 ; V_19 ++ ) {
struct V_34 * V_35 = & V_33 -> V_3 [ V_19 ] ;
F_10 ( V_35 -> V_29 . V_26 , & V_5 -> V_8 [ V_19 ] ) ;
}
}
V_2 -> V_6 [ V_10 ] = NULL ;
F_11 ( V_5 ) ;
}
static int
F_12 ( struct V_1 * V_2 , int V_10 ,
T_2 V_36 , T_3 V_37 )
{
return 0 ;
}
static int
F_13 ( struct V_11 * V_12 , int V_10 )
{
return 0 ;
}
static int
F_14 ( struct V_11 * V_12 , int V_10 , bool V_38 )
{
return 0 ;
}
static void
F_15 ( struct V_11 * V_12 , int V_10 )
{
struct V_16 * V_17 = F_3 ( V_12 , V_10 ) ;
F_16 ( V_12 , V_39 ) ;
F_11 ( V_17 ) ;
}
int
F_17 ( struct V_11 * V_12 )
{
struct V_16 * V_17 = F_4 ( sizeof( * V_17 ) , V_20 ) ;
if ( ! V_17 )
return - V_21 ;
V_17 -> V_22 . V_22 . V_40 = F_15 ;
V_17 -> V_22 . V_22 . V_41 = F_13 ;
V_17 -> V_22 . V_22 . V_42 = F_14 ;
V_17 -> V_22 . V_22 . V_43 = F_2 ;
V_17 -> V_22 . V_22 . V_31 = F_9 ;
V_17 -> V_22 . V_22 . V_44 = F_12 ;
F_18 ( & V_17 -> V_22 ) ;
F_19 ( V_12 , V_39 , & V_17 -> V_22 . V_22 ) ;
F_20 ( V_12 , 0x906e , V_39 ) ;
return 0 ;
}
