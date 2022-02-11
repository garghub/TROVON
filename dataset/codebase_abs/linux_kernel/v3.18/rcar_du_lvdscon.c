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
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
}
static enum V_11
F_9 ( struct V_1 * V_2 , bool V_12 )
{
return V_13 ;
}
int F_10 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const struct V_18 * V_10 ,
struct V_19 * V_20 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_21 ;
V_4 = F_11 ( V_15 -> V_7 , sizeof( * V_4 ) , V_22 ) ;
if ( V_4 == NULL )
return - V_23 ;
if ( V_10 ) {
V_4 -> V_10 = * V_10 ;
} else {
struct V_24 V_25 ;
V_21 = F_12 ( V_20 , L_1 , & V_25 ) ;
if ( V_21 < 0 )
return V_21 ;
F_13 ( & V_25 , & V_4 -> V_10 . V_6 ) ;
F_14 ( V_20 , L_2 , & V_4 -> V_10 . V_26 ) ;
F_14 ( V_20 , L_3 , & V_4 -> V_10 . V_27 ) ;
}
V_2 = & V_4 -> V_2 . V_2 ;
V_2 -> V_28 . V_26 = V_4 -> V_10 . V_26 ;
V_2 -> V_28 . V_27 = V_4 -> V_10 . V_27 ;
V_21 = F_15 ( V_15 -> V_29 , V_2 , & V_30 ,
V_31 ) ;
if ( V_21 < 0 )
return V_21 ;
F_16 ( V_2 , & V_32 ) ;
V_21 = F_17 ( V_2 ) ;
if ( V_21 < 0 )
return V_21 ;
F_18 ( V_2 , V_33 ) ;
F_19 ( & V_2 -> V_34 ,
V_15 -> V_29 -> V_35 . V_36 , V_33 ) ;
V_21 = F_20 ( V_2 , & V_17 -> V_37 ) ;
if ( V_21 < 0 )
return V_21 ;
V_2 -> V_37 = & V_17 -> V_37 ;
V_4 -> V_2 . V_37 = V_17 ;
return 0 ;
}
