static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
T_1 V_5 = 0 , V_6 = 0 ;
if ( V_2 -> V_4 < V_3 || V_2 -> V_3 > V_4 )
return;
if ( V_2 -> V_3 < V_3 )
V_5 = V_3 - V_2 -> V_3 ;
if ( V_2 -> V_4 > V_4 )
V_6 = V_2 -> V_4 - V_4 ;
if ( V_5 > V_6 )
V_2 -> V_4 = V_3 - 1 ;
else
V_2 -> V_3 = V_4 + 1 ;
}
static void F_2 ( struct V_1 * V_7 )
{
int V_8 ;
struct V_9 * V_10 ;
for ( V_8 = 0 ; V_8 < V_11 . V_12 ; V_8 ++ ) {
V_10 = & V_11 . V_13 [ V_8 ] ;
F_1 ( V_7 , V_10 -> V_14 ,
V_10 -> V_14 + V_10 -> V_15 - 1 ) ;
}
}
void F_3 ( struct V_1 * V_7 )
{
if ( V_7 -> V_16 & V_17 ) {
if ( V_7 -> V_3 < V_18 )
V_7 -> V_3 = V_18 ;
F_1 ( V_7 , V_19 , V_20 ) ;
F_2 ( V_7 ) ;
}
}
