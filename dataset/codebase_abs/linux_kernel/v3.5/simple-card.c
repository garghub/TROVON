static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_8 * V_11 = V_2 -> V_12 ;
unsigned int V_13 = V_6 -> V_14 | V_6 -> V_13 ;
unsigned int V_15 = V_6 -> V_14 | V_6 -> V_15 ;
int V_16 ;
if ( V_15 ) {
V_16 = F_3 ( V_9 , V_15 ) ;
if ( V_16 < 0 )
return V_16 ;
}
if ( V_6 -> V_17 ) {
V_16 = F_4 ( V_9 , 0 , V_6 -> V_17 , 0 ) ;
if ( V_16 < 0 )
return V_16 ;
}
if ( V_13 ) {
V_16 = F_3 ( V_11 , V_13 ) ;
if ( V_16 < 0 )
return V_16 ;
}
return 0 ;
}
static int F_5 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = V_19 -> V_20 . V_21 ;
if ( ! V_4 ) {
F_6 ( & V_19 -> V_20 , L_1 ) ;
return - V_22 ;
}
if ( ! V_4 -> V_23 ||
! V_4 -> V_24 ||
! V_4 -> V_12 ||
! V_4 -> V_9 ||
! V_4 -> V_25 ||
! V_4 -> V_10 ) {
F_6 ( & V_19 -> V_20 , L_2 ) ;
return - V_22 ;
}
V_4 -> V_26 . V_23 = V_4 -> V_23 ;
V_4 -> V_26 . V_27 = V_4 -> V_23 ;
V_4 -> V_26 . V_28 = V_4 -> V_12 ;
V_4 -> V_26 . V_29 = V_4 -> V_25 ;
V_4 -> V_26 . V_30 = V_4 -> V_9 ;
V_4 -> V_26 . V_31 = V_4 -> V_10 ;
if ( V_4 -> V_7 )
V_4 -> V_26 . V_7 = F_1 ;
V_4 -> V_32 . V_23 = V_4 -> V_24 ;
V_4 -> V_32 . V_33 = V_34 ;
V_4 -> V_32 . V_35 = & V_4 -> V_26 ;
V_4 -> V_32 . V_36 = 1 ;
V_4 -> V_32 . V_20 = & V_19 -> V_20 ;
return F_7 ( & V_4 -> V_32 ) ;
}
static int F_8 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = V_19 -> V_20 . V_21 ;
return F_9 ( & V_4 -> V_32 ) ;
}
