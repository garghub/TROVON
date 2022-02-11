static struct V_1 *
F_1 ( struct V_2 * V_3 , int V_4 , T_1 V_5 , int V_6 ,
struct V_7 * V_8 )
{
struct V_9 V_10 [] = {
{
. V_11 = V_5 ,
. V_12 = V_5 + 127 ,
. V_13 = V_14 ,
} ,
{
. V_11 = V_6 ,
. V_12 = V_6 ,
. V_13 = V_15 ,
}
} ;
return F_2 (
V_3 ,
L_1 ,
V_4 ,
V_10 ,
F_3 ( V_10 ) ,
V_8 ,
sizeof( * V_8 ) ) ;
}
void F_4 ( struct V_2 * V_3 , T_1 * V_16 , int V_17 ,
int V_6 , struct V_7 * V_8 )
{
int V_18 = 0 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_17 ; V_19 ++ , V_18 += 32 , V_6 ++ ) {
V_8 -> V_20 = V_18 ;
V_8 -> V_21 = F_5 ( V_18 ) ;
V_8 -> V_22 = 32 ;
F_1 ( V_3 , V_19 , V_16 [ V_19 ] , V_6 , V_8 ) ;
}
}
