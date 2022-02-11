static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 , V_3 ) ;
if ( V_3 == V_5 ) {
if ( V_2 -> V_6 -> V_7 > V_8 ) {
V_2 -> V_9 -> V_10 . V_11 =
F_3 ( V_8 + V_12 ) ;
V_2 -> V_6 -> V_7 = V_8 ;
}
}
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_13 )
{
if ( ! V_13 ) {
F_5 ( V_2 -> V_14 . V_15 ) ;
return 0 ;
}
V_2 -> V_16 = V_2 -> V_14 . V_15 = F_6 ( V_2 -> V_17 , V_13 ) ;
if ( V_2 -> V_16 == NULL )
return - 1 ;
V_2 -> V_18 = & V_2 -> V_14 . V_15 -> V_18 ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
V_2 -> V_19 . V_20 = F_4 ;
V_2 -> V_19 . V_21 = F_1 ;
return F_8 ( V_2 ) ;
}
