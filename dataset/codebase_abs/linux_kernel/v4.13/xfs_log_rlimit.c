STATIC int
F_1 (
struct V_1 * V_2 )
{
int V_3 ;
int V_4 ;
V_3 = F_2 ( V_2 -> V_5 -> V_6 ) -
V_7 - 1 ;
V_4 = F_3 ( V_2 , V_8 ) ;
V_4 += F_4 ( V_2 , V_3 ) ;
V_4 += F_5 ( V_2 , V_3 , V_8 ) ;
return F_6 ( V_2 ) -> V_9 . V_10 +
F_6 ( V_2 ) -> V_11 . V_10 * V_4 ;
}
STATIC void
F_7 (
struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_12 * V_14 ;
struct V_12 * V_15 ;
int V_16 = 0 ;
int V_17 ;
V_17 = F_1 ( V_2 ) ;
V_14 = (struct V_12 * ) F_6 ( V_2 ) ;
V_15 = (struct V_12 * ) ( F_6 ( V_2 ) + 1 ) ;
for (; V_14 < V_15 ; V_14 ++ ) {
int V_18 = V_14 -> V_19 > 1 ?
V_14 -> V_10 * V_14 -> V_19 :
V_14 -> V_10 ;
if ( V_16 < V_18 ) {
V_16 = V_18 ;
* V_13 = * V_14 ;
}
}
if ( V_17 > V_16 ) {
* V_13 = F_6 ( V_2 ) -> V_9 ;
V_13 -> V_10 = V_17 ;
}
}
int
F_8 (
struct V_1 * V_2 )
{
struct V_12 V_20 = { 0 } ;
int V_21 ;
int V_22 = 0 ;
int V_23 = 0 ;
F_7 ( V_2 , & V_20 ) ;
V_21 = F_9 ( V_2 , V_20 . V_10 ) ;
if ( V_20 . V_19 > 1 )
V_21 *= V_20 . V_19 ;
if ( F_10 ( & V_2 -> V_24 ) && V_2 -> V_24 . V_25 > 1 )
V_23 = F_11 ( V_2 -> V_24 . V_25 ) ;
if ( V_23 ) {
V_22 = F_12 ( F_11 ( V_21 ) , V_23 ) +
2 * V_23 ;
} else
V_22 = F_11 ( V_21 ) + 2 * V_26 ;
V_22 *= V_27 ;
return F_13 ( V_2 , V_22 ) ;
}
