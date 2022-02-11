static int F_1 ( struct V_1 * V_1 ,
struct V_2 T_1 * V_3 )
{
struct V_4 * V_5 ;
struct V_2 V_6 ;
struct V_7 * V_8 ;
V_5 = V_1 -> V_9 ;
if ( F_2 ( ! V_5 -> V_10 ) )
return - V_11 ;
V_8 = V_5 -> V_10 -> V_12 ;
if ( F_2 ( ! V_8 ) )
return - V_11 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_13 = V_8 -> V_13 ? V_8 -> V_13 -> V_14 : - 1 ;
if ( V_8 -> V_15 . V_16 & V_17 )
V_6 . V_16 |= V_18 ;
F_3 ( V_6 . V_19 , V_8 -> V_19 , sizeof( V_6 . V_19 ) ) ;
F_3 ( V_6 . V_20 , V_8 -> V_20 , sizeof( V_6 . V_20 ) ) ;
V_6 . V_21 = V_8 -> V_15 . V_21 ;
if ( F_4 ( V_3 , & V_6 , sizeof( * V_3 ) ) )
return - V_22 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 ,
struct V_23 T_1 * V_24 )
{
struct V_4 * V_5 ;
struct V_23 V_25 ;
V_5 = V_1 -> V_9 ;
if ( F_2 ( ! V_5 -> V_10 ) )
return - V_11 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_26 . V_27 = V_5 -> V_26 . V_27 ;
V_25 . V_26 . V_28 = V_5 -> V_26 . V_28 ;
V_25 . V_21 = F_6 ( V_5 -> V_10 ) ;
V_25 . V_29 = V_5 -> V_10 -> V_29 ;
V_25 . V_30 = V_5 -> V_30 ;
F_7 ( & V_5 -> V_31 ) ;
V_25 . V_32 = V_5 -> V_33 ;
F_8 ( & V_5 -> V_31 ) ;
if ( F_4 ( V_24 , & V_25 , sizeof( V_25 ) ) )
return - V_22 ;
return 0 ;
}
static long F_9 ( struct V_1 * V_1 , unsigned int V_34 , unsigned long V_35 )
{
void T_1 * V_36 = F_10 ( V_35 ) ;
switch ( V_34 ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
return F_11 ( V_1 , V_34 , ( unsigned long ) V_36 ) ;
case V_53 :
return F_1 ( V_1 , V_36 ) ;
case V_54 :
return F_5 ( V_1 , V_36 ) ;
#ifdef F_12
case V_55 :
return F_13 ( V_1 , V_36 ) ;
#endif
}
return - V_56 ;
}
