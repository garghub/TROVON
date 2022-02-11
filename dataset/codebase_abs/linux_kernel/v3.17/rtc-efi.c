static inline int
F_1 ( T_1 * V_1 )
{
return F_2 ( V_1 -> V_2 , V_1 -> V_3 - 1 , V_1 -> V_4 ) ;
}
static int
F_3 ( T_1 * V_1 )
{
int V_5 ;
int V_6 = 0 ;
if ( V_1 -> V_4 < V_7 ) {
F_4 ( L_1 F_5 ( V_7 ) L_2 ) ;
return - 1 ;
}
for ( V_5 = V_7 ; V_5 < V_1 -> V_4 ; V_5 ++ )
V_6 += 365 + ( F_6 ( V_5 ) ? 1 : 0 ) ;
V_6 += F_1 ( V_1 ) ;
return ( V_6 + 4 ) % 7 ;
}
static void
F_7 ( struct V_8 * V_9 , T_1 * V_1 )
{
V_1 -> V_4 = V_9 -> V_10 + 1900 ;
V_1 -> V_3 = V_9 -> V_11 + 1 ;
V_1 -> V_2 = V_9 -> V_12 ;
V_1 -> V_13 = V_9 -> V_14 ;
V_1 -> V_15 = V_9 -> V_16 ;
V_1 -> V_17 = V_9 -> V_18 ;
V_1 -> V_19 = 0 ;
V_1 -> V_20 = V_9 -> V_21 ? V_22 : 0 ;
V_1 -> V_23 = V_24 ;
}
static bool
F_8 ( T_1 * V_1 , struct V_8 * V_9 )
{
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
if ( V_1 -> V_17 >= 60 )
return false ;
V_9 -> V_18 = V_1 -> V_17 ;
if ( V_1 -> V_15 >= 60 )
return false ;
V_9 -> V_16 = V_1 -> V_15 ;
if ( V_1 -> V_13 >= 24 )
return false ;
V_9 -> V_14 = V_1 -> V_13 ;
if ( ! V_1 -> V_2 || V_1 -> V_2 > 31 )
return false ;
V_9 -> V_12 = V_1 -> V_2 ;
if ( ! V_1 -> V_3 || V_1 -> V_3 > 12 )
return false ;
V_9 -> V_11 = V_1 -> V_3 - 1 ;
V_9 -> V_10 = V_1 -> V_4 - 1900 ;
V_9 -> V_25 = F_3 ( V_1 ) ;
if ( V_9 -> V_25 < 0 )
return false ;
V_9 -> V_26 = F_1 ( V_1 ) ;
switch ( V_1 -> V_20 & V_22 ) {
case V_22 :
V_9 -> V_21 = 1 ;
break;
case V_27 :
V_9 -> V_21 = 0 ;
break;
default:
V_9 -> V_21 = - 1 ;
}
return true ;
}
static int F_9 ( struct V_28 * V_29 , struct V_30 * V_31 )
{
T_1 V_1 ;
T_2 V_32 ;
V_32 = V_33 . V_34 ( ( V_35 * ) & V_31 -> V_36 ,
( V_35 * ) & V_31 -> V_37 , & V_1 ) ;
if ( V_32 != V_38 )
return - V_39 ;
if ( ! F_8 ( & V_1 , & V_31 -> time ) )
return - V_40 ;
return F_10 ( & V_31 -> time ) ;
}
static int F_11 ( struct V_28 * V_29 , struct V_30 * V_31 )
{
T_1 V_1 ;
T_2 V_32 ;
F_7 ( & V_31 -> time , & V_1 ) ;
V_32 = V_33 . V_41 ( ( V_35 ) V_31 -> V_36 , & V_1 ) ;
F_12 ( V_29 , L_3 , ( int ) V_32 ) ;
return V_32 == V_38 ? 0 : - V_39 ;
}
static int F_13 ( struct V_28 * V_29 , struct V_8 * V_42 )
{
T_2 V_32 ;
T_1 V_1 ;
T_3 V_43 ;
V_32 = V_33 . V_44 ( & V_1 , & V_43 ) ;
if ( V_32 != V_38 ) {
F_14 ( V_29 , L_4 ) ;
return - V_39 ;
}
if ( ! F_8 ( & V_1 , V_42 ) )
return - V_40 ;
return F_10 ( V_42 ) ;
}
static int F_15 ( struct V_28 * V_29 , struct V_8 * V_42 )
{
T_2 V_32 ;
T_1 V_1 ;
F_7 ( V_42 , & V_1 ) ;
V_32 = V_33 . V_45 ( & V_1 ) ;
return V_32 == V_38 ? 0 : - V_39 ;
}
static int T_4 F_16 ( struct V_46 * V_29 )
{
struct V_47 * V_48 ;
V_48 = F_17 ( & V_29 -> V_29 , L_5 , & V_49 ,
V_50 ) ;
if ( F_18 ( V_48 ) )
return F_19 ( V_48 ) ;
F_20 ( V_29 , V_48 ) ;
return 0 ;
}
