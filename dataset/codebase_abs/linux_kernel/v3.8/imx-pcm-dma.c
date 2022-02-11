static bool F_1 ( struct V_1 * V_2 , void * V_3 )
{
if ( ! F_2 ( V_2 ) )
return false ;
V_2 -> V_4 = V_3 ;
return true ;
}
static int F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_12 * V_13 ;
struct V_14 V_15 ;
int V_16 ;
V_13 = F_5 ( V_10 -> V_17 , V_6 ) ;
V_16 = F_6 ( V_6 , V_8 , & V_15 ) ;
if ( V_16 )
return V_16 ;
V_15 . V_18 = false ;
if ( V_6 -> V_19 == V_20 ) {
V_15 . V_21 = V_13 -> V_22 ;
V_15 . V_23 = V_13 -> V_24 ;
} else {
V_15 . V_25 = V_13 -> V_22 ;
V_15 . V_26 = V_13 -> V_24 ;
}
V_16 = F_7 ( V_2 , & V_15 ) ;
if ( V_16 )
return V_16 ;
F_8 ( V_6 , & V_6 -> V_27 ) ;
return 0 ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
struct V_12 * V_13 ;
struct V_28 * V_29 ;
int V_16 ;
F_10 ( V_6 , & V_30 ) ;
V_13 = F_5 ( V_10 -> V_17 , V_6 ) ;
V_29 = F_11 ( sizeof( * V_29 ) , V_31 ) ;
if ( ! V_29 )
return - V_32 ;
V_29 -> V_33 = V_13 -> V_34 ?
V_35 : V_36 ;
V_29 -> V_37 = V_38 ;
V_29 -> V_39 = V_13 -> V_40 ;
V_16 = F_12 ( V_6 , F_1 , V_29 ) ;
if ( V_16 ) {
F_13 ( V_29 ) ;
return V_16 ;
}
F_14 ( V_6 , V_29 ) ;
return 0 ;
}
static int F_15 ( struct V_5 * V_6 )
{
struct V_28 * V_29 = F_16 ( V_6 ) ;
F_17 ( V_6 ) ;
F_13 ( V_29 ) ;
return 0 ;
}
int F_18 ( struct V_41 * V_42 )
{
return F_19 ( & V_42 -> V_43 , & V_44 ) ;
}
