static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_5 )
{
int V_6 = 0 ;
V_5 |= V_4 -> V_7 ;
if ( ! V_6 && V_5 )
V_6 = F_2 ( V_2 , V_5 ) ;
if ( V_6 == - V_8 ) {
F_3 ( V_2 -> V_9 , L_1 ) ;
V_6 = 0 ;
}
if ( ! V_6 && V_4 -> V_10 )
V_6 = F_4 ( V_2 , 0 , V_4 -> V_10 , 0 ) ;
return V_6 ;
}
static int F_5 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_6 ( V_12 ) ;
struct V_1 * V_15 = V_12 -> V_16 ;
struct V_1 * V_17 = V_12 -> V_18 ;
unsigned int V_5 = V_14 -> V_5 ;
int V_6 ;
V_6 = F_1 ( V_15 , & V_14 -> V_16 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_1 ( V_17 , & V_14 -> V_18 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_7 ( struct V_19 * V_20 )
{
struct V_13 * V_21 = V_20 -> V_9 . V_22 ;
struct V_23 * V_9 = & V_20 -> V_9 ;
if ( ! V_21 ) {
F_8 ( V_9 , L_2 ) ;
return - V_24 ;
}
if ( ! V_21 -> V_25 ||
! V_21 -> V_26 ||
! V_21 -> V_15 ||
! V_21 -> V_27 ||
! V_21 -> V_18 . V_25 ||
! V_21 -> V_16 . V_25 ) {
F_8 ( V_9 , L_3 ) ;
return - V_24 ;
}
V_21 -> V_28 . V_25 = V_21 -> V_25 ;
V_21 -> V_28 . V_29 = V_21 -> V_25 ;
V_21 -> V_28 . V_30 = V_21 -> V_18 . V_25 ;
V_21 -> V_28 . V_31 = V_21 -> V_27 ;
V_21 -> V_28 . V_32 = V_21 -> V_15 ;
V_21 -> V_28 . V_33 = V_21 -> V_16 . V_25 ;
V_21 -> V_28 . V_34 = F_5 ;
V_21 -> V_35 . V_25 = V_21 -> V_26 ;
V_21 -> V_35 . V_36 = V_37 ;
V_21 -> V_35 . V_38 = & V_21 -> V_28 ;
V_21 -> V_35 . V_39 = 1 ;
V_21 -> V_35 . V_9 = & V_20 -> V_9 ;
return F_9 ( & V_21 -> V_35 ) ;
}
static int F_10 ( struct V_19 * V_20 )
{
struct V_13 * V_21 = V_20 -> V_9 . V_22 ;
return F_11 ( & V_21 -> V_35 ) ;
}
