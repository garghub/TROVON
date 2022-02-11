static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_5 ) ;
F_3 ( F_4 ( V_5 -> V_6 [ V_3 ] ) , V_5 -> V_7 ) ;
return 0 ;
}
static int F_5 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
void T_1 * V_7 ;
int V_12 , V_13 ;
struct V_14 * V_15 = & V_9 -> V_15 ;
struct V_4 * V_16 ;
V_16 = F_6 ( V_15 , sizeof( * V_16 ) , V_17 ) ;
if ( ! V_16 )
return - V_18 ;
V_11 = F_7 ( V_9 , V_19 , 0 ) ;
V_7 = F_8 ( V_15 , V_11 ) ;
if ( F_9 ( V_7 ) )
return F_10 ( V_7 ) ;
V_16 -> V_7 = V_7 ;
V_16 -> V_6 = V_20 ;
V_16 -> V_5 . V_21 = & V_22 ;
V_16 -> V_5 . V_23 = F_11 ( V_20 ) ;
V_16 -> V_5 . V_24 = V_15 -> V_24 ;
V_12 = F_12 ( V_15 , & V_16 -> V_5 ) ;
for ( V_13 = 0 ; V_13 < V_25 . V_26 ; V_13 ++ ) {
V_27 [ V_13 ] -> V_28 = V_7 ;
V_12 = F_13 ( V_15 ,
V_25 . V_29 [ V_13 ] ) ;
if ( V_12 )
return V_12 ;
}
return F_14 ( V_15 -> V_24 , V_30 ,
& V_25 ) ;
}
