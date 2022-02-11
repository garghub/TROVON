static int F_1 ( struct V_1 * V_1 ,
struct V_2 T_1 * V_3 )
{
struct V_4 V_5 ;
if ( F_2 ( & V_5 . V_6 , & V_3 -> V_6 , sizeof( V_5 . V_6 ) ) ||
F_3 ( V_5 . V_7 , & V_3 -> V_7 ) ||
F_3 ( V_5 . V_8 , & V_3 -> V_8 ) )
return - V_9 ;
return F_4 ( & V_5 ) ;
}
static int F_5 ( struct V_1 * V_1 ,
struct V_10 T_1 * V_11 )
{
struct V_12 * V_13 ;
struct V_10 V_14 ;
struct V_15 * V_16 ;
V_13 = V_1 -> V_17 ;
if ( F_6 ( ! V_13 -> V_18 ) )
return - V_19 ;
V_16 = V_13 -> V_18 -> V_20 ;
if ( F_6 ( ! V_16 ) )
return - V_19 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_21 = V_16 -> V_21 ? V_16 -> V_21 -> V_22 : - 1 ;
if ( V_16 -> V_23 . V_24 & V_25 )
V_14 . V_24 |= V_26 ;
F_7 ( V_14 . V_27 , V_16 -> V_27 , sizeof( V_14 . V_27 ) ) ;
F_7 ( V_14 . V_28 , V_16 -> V_28 , sizeof( V_14 . V_28 ) ) ;
V_14 . V_29 = V_16 -> V_23 . V_29 ;
if ( F_8 ( V_11 , & V_14 , sizeof( * V_11 ) ) )
return - V_9 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_1 ,
struct V_30 T_1 * V_31 )
{
struct V_12 * V_13 ;
struct V_30 V_32 ;
V_13 = V_1 -> V_17 ;
if ( F_6 ( ! V_13 -> V_18 ) )
return - V_19 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_33 . V_34 = V_13 -> V_33 . V_34 ;
V_32 . V_33 . V_35 = V_13 -> V_33 . V_35 ;
V_32 . V_29 = F_10 ( V_13 -> V_18 ) ;
V_32 . V_36 = V_13 -> V_18 -> V_36 ;
V_32 . V_37 = V_13 -> V_37 ;
F_11 ( & V_13 -> V_38 ) ;
V_32 . V_39 = V_13 -> V_40 ;
F_12 ( & V_13 -> V_38 ) ;
if ( F_8 ( V_31 , & V_32 , sizeof( V_32 ) ) )
return - V_9 ;
return 0 ;
}
static long F_13 ( struct V_1 * V_1 , unsigned int V_41 ,
unsigned long V_42 )
{
void T_1 * V_43 = F_14 ( V_42 ) ;
switch ( V_41 ) {
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
return F_15 ( V_1 , V_41 , ( unsigned long ) V_43 ) ;
case V_59 :
return F_1 ( V_1 , V_43 ) ;
case V_60 :
return F_5 ( V_1 , V_43 ) ;
case V_61 :
return F_9 ( V_1 , V_43 ) ;
#ifdef F_16
case V_62 :
return F_17 ( V_1 , V_43 ) ;
#endif
}
return - V_63 ;
}
static long F_18 ( struct V_1 * V_1 , unsigned int V_41 ,
unsigned long V_42 )
{
struct V_12 * V_13 = V_1 -> V_17 ;
long V_64 ;
F_19 ( & V_13 -> V_65 ) ;
V_64 = F_13 ( V_1 , V_41 , V_42 ) ;
F_20 ( & V_13 -> V_65 ) ;
return V_64 ;
}
