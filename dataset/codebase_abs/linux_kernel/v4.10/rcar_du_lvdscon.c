static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 ;
V_6 = F_3 ( V_2 -> V_7 ) ;
if ( V_6 == NULL )
return 0 ;
V_6 -> type = V_8 | V_9 ;
F_4 ( & V_4 -> V_10 . V_6 , V_6 ) ;
F_5 ( V_2 , V_6 ) ;
return 1 ;
}
int F_6 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const struct V_15 * V_16 )
{
struct V_17 * V_18 = F_7 ( V_14 ) ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_19 V_20 ;
int V_21 ;
V_4 = F_8 ( V_12 -> V_7 , sizeof( * V_4 ) , V_22 ) ;
if ( V_4 == NULL )
return - V_23 ;
V_21 = F_9 ( V_16 , L_1 , & V_20 ) ;
if ( V_21 < 0 )
return V_21 ;
F_10 ( & V_20 , & V_4 -> V_10 . V_6 ) ;
F_11 ( V_16 , L_2 , & V_4 -> V_10 . V_24 ) ;
F_11 ( V_16 , L_3 , & V_4 -> V_10 . V_25 ) ;
V_2 = & V_4 -> V_2 . V_2 ;
V_2 -> V_26 . V_24 = V_4 -> V_10 . V_24 ;
V_2 -> V_26 . V_25 = V_4 -> V_10 . V_25 ;
V_21 = F_12 ( V_12 -> V_27 , V_2 , & V_28 ,
V_29 ) ;
if ( V_21 < 0 )
return V_21 ;
F_13 ( V_2 , & V_30 ) ;
V_2 -> V_31 = V_32 ;
F_14 ( & V_2 -> V_33 ,
V_12 -> V_27 -> V_34 . V_35 , V_32 ) ;
V_21 = F_15 ( V_2 , V_18 ) ;
if ( V_21 < 0 )
return V_21 ;
V_4 -> V_2 . V_18 = V_14 ;
return 0 ;
}
