static inline void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
V_2 -> V_5 [ V_3 ] . V_6 . V_7 = 0 ;
V_2 -> V_5 [ V_3 ] . V_6 . V_8 = 0 ;
V_2 -> V_9 = V_4 ;
}
static int F_2 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_1 * V_2 = F_3 ( & V_14 ) ;
struct V_15 * V_16 ;
int V_17 , V_18 = V_2 -> V_9 ;
int V_19 = V_11 -> V_5 [ 0 ] . V_20 & V_21 ? 1 : 0 ;
int V_22 = F_4 ( V_23 ) ;
if ( F_5 ( V_22 == 0 ) ) {
F_1 ( V_2 , V_18 , 0 ) ;
return 0 ;
}
V_16 = & V_2 -> V_5 [ V_18 ] ;
V_17 = F_6 ( V_13 ) - V_11 -> V_5 [ V_18 ] . V_24 ;
if ( V_18 < V_11 -> V_25 - 1 &&
! V_11 -> V_5 [ V_18 + 1 ] . V_26 &&
! V_13 -> V_27 [ V_18 + 1 ] . V_28 &&
V_17 > V_16 -> V_29 . V_30 &&
V_11 -> V_5 [ V_18 + 1 ] . V_24 <= V_22 ) {
V_16 -> V_6 . V_7 ++ ;
V_16 -> V_6 . V_8 = 0 ;
if ( V_16 -> V_6 . V_7 >= V_16 -> V_29 . V_7 ) {
F_1 ( V_2 , V_18 , V_18 + 1 ) ;
return V_18 + 1 ;
}
}
if ( V_18 > V_19 &&
( V_11 -> V_5 [ V_18 ] . V_26 ||
V_13 -> V_27 [ V_18 ] . V_28 ||
V_11 -> V_5 [ V_18 ] . V_24 > V_22 ) ) {
int V_31 ;
for ( V_31 = V_18 - 1 ; V_31 > V_19 ; V_31 -- ) {
if ( V_11 -> V_5 [ V_31 ] . V_24 <= V_22 )
break;
}
F_1 ( V_2 , V_18 , V_31 ) ;
return V_31 ;
}
if ( V_18 > V_19 &&
V_17 < V_16 -> V_29 . V_32 ) {
V_16 -> V_6 . V_8 ++ ;
V_16 -> V_6 . V_7 = 0 ;
if ( V_16 -> V_6 . V_8 >= V_16 -> V_29 . V_8 ) {
F_1 ( V_2 , V_18 , V_18 - 1 ) ;
return V_18 - 1 ;
}
}
return V_18 ;
}
static int F_7 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
int V_31 ;
int V_19 = V_11 -> V_5 [ 0 ] . V_20 & V_21 ? 1 : 0 ;
struct V_1 * V_2 = & F_8 ( V_14 , V_13 -> V_33 ) ;
struct V_15 * V_34 ;
struct V_35 * V_36 ;
V_2 -> V_9 = V_19 ;
for ( V_31 = V_19 ; V_31 < V_11 -> V_25 ; V_31 ++ ) {
V_36 = & V_11 -> V_5 [ V_31 ] ;
V_34 = & V_2 -> V_5 [ V_31 ] ;
V_34 -> V_6 . V_7 = 0 ;
V_34 -> V_6 . V_8 = 0 ;
V_34 -> V_29 . V_7 = V_37 ;
V_34 -> V_29 . V_8 = V_38 ;
if ( V_31 < V_11 -> V_25 - 1 )
V_34 -> V_29 . V_30 = V_36 -> V_24 ;
if ( V_31 > V_19 )
V_34 -> V_29 . V_32 = V_36 -> V_24 ;
}
return 0 ;
}
static void F_9 ( struct V_12 * V_13 , int V_39 )
{
struct V_1 * V_2 = F_3 ( & V_14 ) ;
if ( V_39 > 0 )
V_2 -> V_9 = V_39 ;
}
static int T_1 F_10 ( void )
{
if ( ! V_40 )
V_41 . V_42 = 25 ;
return F_11 ( & V_41 ) ;
}
