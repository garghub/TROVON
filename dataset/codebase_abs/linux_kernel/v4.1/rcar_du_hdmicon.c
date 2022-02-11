static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
if ( V_8 -> V_9 == NULL )
return 0 ;
return V_8 -> V_9 ( V_6 , V_2 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
if ( V_8 -> V_12 == NULL )
return V_13 ;
return V_8 -> V_12 ( V_6 , V_11 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
}
static enum V_14
F_9 ( struct V_1 * V_2 , bool V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_6 ) ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
if ( V_8 -> V_16 == NULL )
return V_17 ;
return V_8 -> V_16 ( V_6 , V_2 ) ;
}
int F_10 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_5 * V_6 = F_3 ( V_21 ) ;
struct V_3 * V_22 ;
struct V_1 * V_2 ;
int V_23 ;
V_22 = F_11 ( V_19 -> V_24 , sizeof( * V_22 ) , V_25 ) ;
if ( V_22 == NULL )
return - V_26 ;
V_2 = & V_22 -> V_2 ;
V_2 -> V_27 . V_28 = 0 ;
V_2 -> V_27 . V_29 = 0 ;
V_2 -> V_30 = true ;
V_2 -> V_31 = V_32 ;
V_23 = F_12 ( V_19 -> V_33 , V_2 , & V_34 ,
V_35 ) ;
if ( V_23 < 0 )
return V_23 ;
F_13 ( V_2 , & V_36 ) ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 < 0 )
return V_23 ;
V_2 -> V_37 = V_38 ;
F_15 ( & V_2 -> V_39 ,
V_19 -> V_33 -> V_40 . V_41 , V_38 ) ;
V_23 = F_16 ( V_2 , V_6 ) ;
if ( V_23 < 0 )
return V_23 ;
V_22 -> V_6 = V_21 ;
return 0 ;
}
