static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_5 )
{
int V_6 = 0 ;
V_5 |= V_4 -> V_7 ;
if ( ! V_6 && V_5 )
V_6 = F_2 ( V_2 , V_5 ) ;
if ( ! V_6 && V_4 -> V_8 )
V_6 = F_3 ( V_2 , 0 , V_4 -> V_8 , 0 ) ;
return V_6 ;
}
static int F_4 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_1 * V_13 = V_10 -> V_14 ;
struct V_1 * V_15 = V_10 -> V_16 ;
unsigned int V_5 = V_12 -> V_5 ;
int V_6 ;
V_6 = F_1 ( V_13 , & V_12 -> V_14 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_1 ( V_15 , & V_12 -> V_16 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_6 ( struct V_17 * V_18 )
{
struct V_11 * V_19 = V_18 -> V_20 . V_21 ;
struct V_22 * V_20 = & V_18 -> V_20 ;
if ( ! V_19 ) {
F_7 ( V_20 , L_1 ) ;
return - V_23 ;
}
if ( ! V_19 -> V_24 ||
! V_19 -> V_25 ||
! V_19 -> V_13 ||
! V_19 -> V_26 ||
! V_19 -> V_16 . V_24 ||
! V_19 -> V_14 . V_24 ) {
F_7 ( V_20 , L_2 ) ;
return - V_23 ;
}
V_19 -> V_27 . V_24 = V_19 -> V_24 ;
V_19 -> V_27 . V_28 = V_19 -> V_24 ;
V_19 -> V_27 . V_29 = V_19 -> V_16 . V_24 ;
V_19 -> V_27 . V_30 = V_19 -> V_26 ;
V_19 -> V_27 . V_31 = V_19 -> V_13 ;
V_19 -> V_27 . V_32 = V_19 -> V_14 . V_24 ;
V_19 -> V_27 . V_33 = F_4 ;
V_19 -> V_34 . V_24 = V_19 -> V_25 ;
V_19 -> V_34 . V_35 = V_36 ;
V_19 -> V_34 . V_37 = & V_19 -> V_27 ;
V_19 -> V_34 . V_38 = 1 ;
V_19 -> V_34 . V_20 = & V_18 -> V_20 ;
return F_8 ( & V_19 -> V_34 ) ;
}
static int F_9 ( struct V_17 * V_18 )
{
struct V_11 * V_19 = V_18 -> V_20 . V_21 ;
return F_10 ( & V_19 -> V_34 ) ;
}
