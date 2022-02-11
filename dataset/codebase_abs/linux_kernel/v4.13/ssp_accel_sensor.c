static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 ,
int * V_6 , long V_7 )
{
T_1 V_8 ;
struct V_9 * V_10 = F_2 ( V_2 -> V_11 . V_12 -> V_12 ) ;
switch ( V_7 ) {
case V_13 :
V_8 = F_3 ( V_10 , V_14 ) ;
F_4 ( V_8 , V_5 , V_6 ) ;
return V_15 ;
default:
break;
}
return - V_16 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int V_5 ,
int V_6 , long V_7 )
{
int V_17 ;
struct V_9 * V_10 = F_2 ( V_2 -> V_11 . V_12 -> V_12 ) ;
switch ( V_7 ) {
case V_13 :
V_17 = F_6 ( V_5 , V_6 ) ;
V_17 = F_7 ( V_10 , V_14 , V_17 ) ;
if ( V_17 < 0 )
F_8 ( & V_2 -> V_11 , L_1 ) ;
return V_17 ;
default:
break;
}
return - V_16 ;
}
static int F_9 ( struct V_1 * V_2 , void * V_18 ,
T_2 V_19 )
{
return F_10 ( V_2 , V_18 , V_20 ,
V_19 ) ;
}
static int F_11 ( struct V_21 * V_22 )
{
int V_17 ;
struct V_1 * V_2 ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
V_2 = F_12 ( & V_22 -> V_11 , sizeof( * V_24 ) ) ;
if ( ! V_2 )
return - V_27 ;
V_24 = F_13 ( V_2 ) ;
V_24 -> V_28 = F_9 ;
V_24 -> type = V_14 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_11 . V_12 = & V_22 -> V_11 ;
V_2 -> V_11 . V_31 = V_22 -> V_11 . V_31 ;
V_2 -> V_32 = & V_33 ;
V_2 -> V_34 = V_35 ;
V_2 -> V_36 = V_37 ;
V_2 -> V_38 = F_14 ( V_37 ) ;
V_2 -> V_39 = V_40 ;
V_26 = F_15 ( & V_22 -> V_11 ) ;
if ( ! V_26 )
return - V_27 ;
F_16 ( V_2 , V_26 ) ;
V_2 -> V_41 = & V_42 ;
F_17 ( V_22 , V_2 ) ;
V_17 = F_18 ( & V_22 -> V_11 , V_2 ) ;
if ( V_17 < 0 )
return V_17 ;
F_19 ( V_2 , V_14 ) ;
return 0 ;
}
