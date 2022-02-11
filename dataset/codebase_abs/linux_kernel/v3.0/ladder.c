static inline void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
V_2 -> V_5 [ V_3 ] . V_6 . V_7 = 0 ;
V_2 -> V_5 [ V_3 ] . V_6 . V_8 = 0 ;
V_2 -> V_9 = V_4 ;
}
static int F_2 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = & F_3 ( V_12 ) ;
struct V_13 * V_14 ;
int V_15 , V_16 = V_2 -> V_9 ;
int V_17 = F_4 ( V_18 ) ;
if ( F_5 ( V_17 == 0 ) ) {
F_1 ( V_2 , V_16 , 0 ) ;
return 0 ;
}
V_14 = & V_2 -> V_5 [ V_16 ] ;
if ( V_11 -> V_5 [ V_16 ] . V_19 & V_20 )
V_15 = F_6 ( V_11 ) - V_11 -> V_5 [ V_16 ] . V_21 ;
else
V_15 = V_14 -> V_22 . V_23 + 1 ;
if ( V_16 < V_11 -> V_24 - 1 &&
V_15 > V_14 -> V_22 . V_23 &&
V_11 -> V_5 [ V_16 + 1 ] . V_21 <= V_17 ) {
V_14 -> V_6 . V_7 ++ ;
V_14 -> V_6 . V_8 = 0 ;
if ( V_14 -> V_6 . V_7 >= V_14 -> V_22 . V_7 ) {
F_1 ( V_2 , V_16 , V_16 + 1 ) ;
return V_16 + 1 ;
}
}
if ( V_16 > V_25 &&
V_11 -> V_5 [ V_16 ] . V_21 > V_17 ) {
int V_26 ;
for ( V_26 = V_16 - 1 ; V_26 > V_25 ; V_26 -- ) {
if ( V_11 -> V_5 [ V_26 ] . V_21 <= V_17 )
break;
}
F_1 ( V_2 , V_16 , V_26 ) ;
return V_26 ;
}
if ( V_16 > V_25 &&
V_15 < V_14 -> V_22 . V_27 ) {
V_14 -> V_6 . V_8 ++ ;
V_14 -> V_6 . V_7 = 0 ;
if ( V_14 -> V_6 . V_8 >= V_14 -> V_22 . V_8 ) {
F_1 ( V_2 , V_16 , V_16 - 1 ) ;
return V_16 - 1 ;
}
}
return V_16 ;
}
static int F_7 ( struct V_10 * V_11 )
{
int V_26 ;
struct V_1 * V_2 = & F_8 ( V_12 , V_11 -> V_28 ) ;
struct V_13 * V_29 ;
struct V_30 * V_31 ;
V_2 -> V_9 = V_25 ;
for ( V_26 = 0 ; V_26 < V_11 -> V_24 ; V_26 ++ ) {
V_31 = & V_11 -> V_5 [ V_26 ] ;
V_29 = & V_2 -> V_5 [ V_26 ] ;
V_29 -> V_6 . V_7 = 0 ;
V_29 -> V_6 . V_8 = 0 ;
V_29 -> V_22 . V_7 = V_32 ;
V_29 -> V_22 . V_8 = V_33 ;
if ( V_26 < V_11 -> V_24 - 1 )
V_29 -> V_22 . V_23 = V_31 -> V_21 ;
if ( V_26 > 0 )
V_29 -> V_22 . V_27 = V_31 -> V_21 ;
}
return 0 ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_34 ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_34 ) ;
}
