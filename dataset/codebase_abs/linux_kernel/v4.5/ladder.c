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
int V_19 = F_4 ( V_20 ) ;
if ( F_5 ( V_19 == 0 ) ) {
F_1 ( V_2 , V_18 , 0 ) ;
return 0 ;
}
V_16 = & V_2 -> V_5 [ V_18 ] ;
V_17 = F_6 ( V_13 ) - V_11 -> V_5 [ V_18 ] . V_21 ;
if ( V_18 < V_11 -> V_22 - 1 &&
! V_11 -> V_5 [ V_18 + 1 ] . V_23 &&
! V_13 -> V_24 [ V_18 + 1 ] . V_25 &&
V_17 > V_16 -> V_26 . V_27 &&
V_11 -> V_5 [ V_18 + 1 ] . V_21 <= V_19 ) {
V_16 -> V_6 . V_7 ++ ;
V_16 -> V_6 . V_8 = 0 ;
if ( V_16 -> V_6 . V_7 >= V_16 -> V_26 . V_7 ) {
F_1 ( V_2 , V_18 , V_18 + 1 ) ;
return V_18 + 1 ;
}
}
if ( V_18 > V_28 &&
( V_11 -> V_5 [ V_18 ] . V_23 ||
V_13 -> V_24 [ V_18 ] . V_25 ||
V_11 -> V_5 [ V_18 ] . V_21 > V_19 ) ) {
int V_29 ;
for ( V_29 = V_18 - 1 ; V_29 > V_28 ; V_29 -- ) {
if ( V_11 -> V_5 [ V_29 ] . V_21 <= V_19 )
break;
}
F_1 ( V_2 , V_18 , V_29 ) ;
return V_29 ;
}
if ( V_18 > V_28 &&
V_17 < V_16 -> V_26 . V_30 ) {
V_16 -> V_6 . V_8 ++ ;
V_16 -> V_6 . V_7 = 0 ;
if ( V_16 -> V_6 . V_8 >= V_16 -> V_26 . V_8 ) {
F_1 ( V_2 , V_18 , V_18 - 1 ) ;
return V_18 - 1 ;
}
}
return V_18 ;
}
static int F_7 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
int V_29 ;
struct V_1 * V_2 = & F_8 ( V_14 , V_13 -> V_31 ) ;
struct V_15 * V_32 ;
struct V_33 * V_34 ;
V_2 -> V_9 = V_28 ;
for ( V_29 = V_28 ; V_29 < V_11 -> V_22 ; V_29 ++ ) {
V_34 = & V_11 -> V_5 [ V_29 ] ;
V_32 = & V_2 -> V_5 [ V_29 ] ;
V_32 -> V_6 . V_7 = 0 ;
V_32 -> V_6 . V_8 = 0 ;
V_32 -> V_26 . V_7 = V_35 ;
V_32 -> V_26 . V_8 = V_36 ;
if ( V_29 < V_11 -> V_22 - 1 )
V_32 -> V_26 . V_27 = V_34 -> V_21 ;
if ( V_29 > V_28 )
V_32 -> V_26 . V_30 = V_34 -> V_21 ;
}
return 0 ;
}
static void F_9 ( struct V_12 * V_13 , int V_37 )
{
struct V_1 * V_2 = F_3 ( & V_14 ) ;
if ( V_37 > 0 )
V_2 -> V_9 = V_37 ;
}
static int T_1 F_10 ( void )
{
if ( ! V_38 )
V_39 . V_40 = 25 ;
return F_11 ( & V_39 ) ;
}
