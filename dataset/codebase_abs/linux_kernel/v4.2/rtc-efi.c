static inline int
F_1 ( T_1 * V_1 )
{
return F_2 ( V_1 -> V_2 , V_1 -> V_3 - 1 , V_1 -> V_4 ) ;
}
static int
F_3 ( T_1 * V_1 , int V_5 )
{
int V_6 = V_1 -> V_4 * ( 365 % 7 )
+ ( V_1 -> V_4 - 1 ) / 4
- ( V_1 -> V_4 - 1 ) / 100
+ ( V_1 -> V_4 - 1 ) / 400
+ V_5 ;
return V_6 % 7 ;
}
static void
F_4 ( struct V_7 * V_8 , T_1 * V_1 )
{
V_1 -> V_4 = V_8 -> V_9 + 1900 ;
V_1 -> V_3 = V_8 -> V_10 + 1 ;
V_1 -> V_2 = V_8 -> V_11 ;
V_1 -> V_12 = V_8 -> V_13 ;
V_1 -> V_14 = V_8 -> V_15 ;
V_1 -> V_16 = V_8 -> V_17 ;
V_1 -> V_18 = 0 ;
V_1 -> V_19 = V_8 -> V_20 ? V_21 : 0 ;
V_1 -> V_22 = V_23 ;
}
static bool
F_5 ( T_1 * V_1 , struct V_7 * V_8 )
{
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
if ( V_1 -> V_16 >= 60 )
return false ;
V_8 -> V_17 = V_1 -> V_16 ;
if ( V_1 -> V_14 >= 60 )
return false ;
V_8 -> V_15 = V_1 -> V_14 ;
if ( V_1 -> V_12 >= 24 )
return false ;
V_8 -> V_13 = V_1 -> V_12 ;
if ( ! V_1 -> V_2 || V_1 -> V_2 > 31 )
return false ;
V_8 -> V_11 = V_1 -> V_2 ;
if ( ! V_1 -> V_3 || V_1 -> V_3 > 12 )
return false ;
V_8 -> V_10 = V_1 -> V_3 - 1 ;
if ( V_1 -> V_4 < 1900 || V_1 -> V_4 > 9999 )
return false ;
V_8 -> V_9 = V_1 -> V_4 - 1900 ;
V_8 -> V_24 = F_1 ( V_1 ) ;
V_8 -> V_25 = F_3 ( V_1 , V_8 -> V_24 ) ;
switch ( V_1 -> V_19 & V_21 ) {
case V_21 :
V_8 -> V_20 = 1 ;
break;
case V_26 :
V_8 -> V_20 = 0 ;
break;
default:
V_8 -> V_20 = - 1 ;
}
return true ;
}
static int F_6 ( struct V_27 * V_28 , struct V_29 * V_30 )
{
T_1 V_1 ;
T_2 V_31 ;
V_31 = V_32 . V_33 ( ( V_34 * ) & V_30 -> V_35 ,
( V_34 * ) & V_30 -> V_36 , & V_1 ) ;
if ( V_31 != V_37 )
return - V_38 ;
if ( ! F_5 ( & V_1 , & V_30 -> time ) )
return - V_39 ;
return F_7 ( & V_30 -> time ) ;
}
static int F_8 ( struct V_27 * V_28 , struct V_29 * V_30 )
{
T_1 V_1 ;
T_2 V_31 ;
F_4 ( & V_30 -> time , & V_1 ) ;
V_31 = V_32 . V_40 ( ( V_34 ) V_30 -> V_35 , & V_1 ) ;
F_9 ( V_28 , L_1 , ( int ) V_31 ) ;
return V_31 == V_37 ? 0 : - V_38 ;
}
static int F_10 ( struct V_27 * V_28 , struct V_7 * V_41 )
{
T_2 V_31 ;
T_1 V_1 ;
T_3 V_42 ;
V_31 = V_32 . V_43 ( & V_1 , & V_42 ) ;
if ( V_31 != V_37 ) {
F_11 ( V_28 , L_2 ) ;
return - V_38 ;
}
if ( ! F_5 ( & V_1 , V_41 ) )
return - V_39 ;
return F_7 ( V_41 ) ;
}
static int F_12 ( struct V_27 * V_28 , struct V_7 * V_41 )
{
T_2 V_31 ;
T_1 V_1 ;
F_4 ( V_41 , & V_1 ) ;
V_31 = V_32 . V_44 ( & V_1 ) ;
return V_31 == V_37 ? 0 : - V_38 ;
}
static int T_4 F_13 ( struct V_45 * V_28 )
{
struct V_46 * V_47 ;
V_47 = F_14 ( & V_28 -> V_28 , L_3 , & V_48 ,
V_49 ) ;
if ( F_15 ( V_47 ) )
return F_16 ( V_47 ) ;
V_47 -> V_50 = 1 ;
F_17 ( V_28 , V_47 ) ;
return 0 ;
}
