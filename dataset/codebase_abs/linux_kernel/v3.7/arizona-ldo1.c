static T_1 int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_4 . V_5 ) ;
struct V_6 V_7 = { } ;
struct V_8 * V_9 ;
int V_10 ;
V_9 = F_3 ( & V_2 -> V_4 , sizeof( * V_9 ) , V_11 ) ;
if ( V_9 == NULL ) {
F_4 ( & V_2 -> V_4 , L_1 ) ;
return - V_12 ;
}
V_9 -> V_3 = V_3 ;
V_9 -> V_13 = V_14 ;
V_9 -> V_13 . V_15 = & V_9 -> V_16 ;
V_9 -> V_16 . V_16 = L_2 ;
V_9 -> V_16 . V_17 = V_17 ( V_3 -> V_4 ) ;
V_7 . V_4 = V_3 -> V_4 ;
V_7 . V_18 = V_9 ;
V_7 . V_19 = V_3 -> V_19 ;
V_7 . V_20 = V_3 -> V_21 . V_22 ;
if ( V_3 -> V_21 . V_9 )
V_7 . V_13 = V_3 -> V_21 . V_9 ;
else
V_7 . V_13 = & V_9 -> V_13 ;
V_9 -> V_23 = F_5 ( & V_8 , & V_7 ) ;
if ( F_6 ( V_9 -> V_23 ) ) {
V_10 = F_7 ( V_9 -> V_23 ) ;
F_4 ( V_3 -> V_4 , L_3 ,
V_10 ) ;
return V_10 ;
}
F_8 ( V_2 , V_9 ) ;
return 0 ;
}
static T_2 int F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_10 ( V_2 ) ;
F_11 ( V_9 -> V_23 ) ;
return 0 ;
}
