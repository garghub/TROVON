static inline int F_1 ( unsigned long V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
return V_1 ;
case V_20 :
case V_21 :
case V_22 :
return V_1 + 6 ;
case V_23 :
case V_24 :
case V_25 :
case V_26 :
return V_1 + 7 ;
default:
return - V_27 ;
}
}
static int F_2 ( struct V_28 * V_29 ,
unsigned long V_1 )
{
struct V_30 * V_31 ;
T_1 V_32 ;
int V_33 ;
V_31 = F_3 ( V_29 , struct V_30 , V_29 ) ;
V_33 = F_1 ( V_1 ) ;
if ( V_33 < 0 )
return V_33 ;
V_32 = F_4 ( V_33 ) ;
return F_5 ( V_31 -> V_34 , V_35 ,
V_32 , V_32 ) ;
}
static int F_6 ( struct V_28 * V_29 ,
unsigned long V_1 )
{
struct V_30 * V_31 ;
T_1 V_32 ;
int V_33 ;
V_31 = F_3 ( V_29 , struct V_30 , V_29 ) ;
V_33 = F_1 ( V_1 ) ;
if ( V_33 < 0 )
return V_33 ;
V_32 = F_4 ( V_33 ) ;
return F_5 ( V_31 -> V_34 , V_35 ,
V_32 , 0 ) ;
}
static int F_7 ( struct V_36 * V_37 )
{
struct V_30 * V_31 ;
struct V_38 * V_39 = & V_37 -> V_39 ;
struct V_40 * V_41 = V_37 -> V_39 . V_42 ;
V_31 = F_8 ( V_39 , sizeof( * V_31 ) , V_43 ) ;
if ( ! V_31 )
return - V_44 ;
V_31 -> V_34 = F_9 ( V_41 -> V_45 ) ;
if ( F_10 ( V_31 -> V_34 ) )
return F_11 ( V_31 -> V_34 ) ;
V_31 -> V_29 . V_46 = V_47 ;
V_31 -> V_29 . V_48 = V_49 + 1 ;
V_31 -> V_29 . V_50 = & V_51 ;
V_31 -> V_29 . V_42 = V_41 ;
return F_12 ( V_39 , & V_31 -> V_29 ) ;
}
