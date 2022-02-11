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
static enum V_11
F_6 ( struct V_1 * V_2 , bool V_12 )
{
return V_13 ;
}
int F_7 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 = F_8 ( V_17 ) ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_22 V_23 ;
int V_24 ;
V_4 = F_9 ( V_15 -> V_7 , sizeof( * V_4 ) , V_25 ) ;
if ( V_4 == NULL )
return - V_26 ;
V_24 = F_10 ( V_19 , L_1 , & V_23 ) ;
if ( V_24 < 0 )
return V_24 ;
F_11 ( & V_23 , & V_4 -> V_10 . V_6 ) ;
F_12 ( V_19 , L_2 , & V_4 -> V_10 . V_27 ) ;
F_12 ( V_19 , L_3 , & V_4 -> V_10 . V_28 ) ;
V_2 = & V_4 -> V_2 . V_2 ;
V_2 -> V_29 . V_27 = V_4 -> V_10 . V_27 ;
V_2 -> V_29 . V_28 = V_4 -> V_10 . V_28 ;
V_24 = F_13 ( V_15 -> V_30 , V_2 , & V_31 ,
V_32 ) ;
if ( V_24 < 0 )
return V_24 ;
F_14 ( V_2 , & V_33 ) ;
V_2 -> V_34 = V_35 ;
F_15 ( & V_2 -> V_36 ,
V_15 -> V_30 -> V_37 . V_38 , V_35 ) ;
V_24 = F_16 ( V_2 , V_21 ) ;
if ( V_24 < 0 )
return V_24 ;
V_4 -> V_2 . V_21 = V_17 ;
return 0 ;
}
