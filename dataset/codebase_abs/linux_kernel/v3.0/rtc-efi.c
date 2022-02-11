static inline int
F_1 ( T_1 * V_1 )
{
return F_2 ( V_1 -> V_2 - 1 , V_1 -> V_3 - 1 , V_1 -> V_4 ) ;
}
static int
F_3 ( T_1 * V_1 )
{
int V_5 ;
int V_6 = 0 ;
if ( V_1 -> V_4 < 1998 ) {
F_4 ( V_7 L_1 ) ;
return - 1 ;
}
for ( V_5 = V_8 ; V_5 < V_1 -> V_4 ; V_5 ++ )
V_6 += 365 + ( F_5 ( V_5 ) ? 1 : 0 ) ;
V_6 += F_1 ( V_1 ) ;
return ( V_6 + 4 ) % 7 ;
}
static void
F_6 ( struct V_9 * V_10 , T_1 * V_1 )
{
V_1 -> V_4 = V_10 -> V_11 + 1900 ;
V_1 -> V_3 = V_10 -> V_12 + 1 ;
V_1 -> V_2 = V_10 -> V_13 ;
V_1 -> V_14 = V_10 -> V_15 ;
V_1 -> V_16 = V_10 -> V_17 ;
V_1 -> V_18 = V_10 -> V_19 ;
V_1 -> V_20 = 0 ;
V_1 -> V_21 = V_10 -> V_22 ? V_23 : 0 ;
V_1 -> V_24 = V_25 ;
}
static void
F_7 ( T_1 * V_1 , struct V_9 * V_10 )
{
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_19 = V_1 -> V_18 ;
V_10 -> V_17 = V_1 -> V_16 ;
V_10 -> V_15 = V_1 -> V_14 ;
V_10 -> V_13 = V_1 -> V_2 ;
V_10 -> V_12 = V_1 -> V_3 - 1 ;
V_10 -> V_11 = V_1 -> V_4 - 1900 ;
V_10 -> V_26 = F_3 ( V_1 ) ;
V_10 -> V_27 = F_1 ( V_1 ) ;
switch ( V_1 -> V_21 & V_23 ) {
case V_23 :
V_10 -> V_22 = 1 ;
break;
case V_28 :
V_10 -> V_22 = 0 ;
break;
default:
V_10 -> V_22 = - 1 ;
}
}
static int F_8 ( struct V_29 * V_30 , struct V_31 * V_32 )
{
T_1 V_1 ;
T_2 V_33 ;
V_33 = V_34 . V_35 ( ( V_36 * ) & V_32 -> V_37 ,
( V_36 * ) & V_32 -> V_38 , & V_1 ) ;
if ( V_33 != V_39 )
return - V_40 ;
F_7 ( & V_1 , & V_32 -> time ) ;
return F_9 ( & V_32 -> time ) ;
}
static int F_10 ( struct V_29 * V_30 , struct V_31 * V_32 )
{
T_1 V_1 ;
T_2 V_33 ;
F_6 ( & V_32 -> time , & V_1 ) ;
V_33 = V_34 . V_41 ( ( V_36 ) V_32 -> V_37 , & V_1 ) ;
F_4 ( V_42 L_2 , ( int ) V_33 ) ;
return V_33 == V_39 ? 0 : - V_40 ;
}
static int F_11 ( struct V_29 * V_30 , struct V_9 * V_43 )
{
T_2 V_33 ;
T_1 V_1 ;
T_3 V_44 ;
V_33 = V_34 . V_45 ( & V_1 , & V_44 ) ;
if ( V_33 != V_39 ) {
F_4 ( V_7 L_3 ) ;
return - V_40 ;
}
F_7 ( & V_1 , V_43 ) ;
return F_9 ( V_43 ) ;
}
static int F_12 ( struct V_29 * V_30 , struct V_9 * V_43 )
{
T_2 V_33 ;
T_1 V_1 ;
F_6 ( V_43 , & V_1 ) ;
V_33 = V_34 . V_46 ( & V_1 ) ;
return V_33 == V_39 ? 0 : - V_40 ;
}
static int T_4 F_13 ( struct V_47 * V_30 )
{
struct V_48 * V_49 ;
V_49 = F_14 ( L_4 , & V_30 -> V_30 , & V_50 ,
V_51 ) ;
if ( F_15 ( V_49 ) )
return F_16 ( V_49 ) ;
F_17 ( V_30 , V_49 ) ;
return 0 ;
}
static int T_5 F_18 ( struct V_47 * V_30 )
{
struct V_48 * V_49 = F_19 ( V_30 ) ;
F_20 ( V_49 ) ;
return 0 ;
}
static int T_4 F_21 ( void )
{
return F_22 ( & V_52 , F_13 ) ;
}
static void T_5 F_23 ( void )
{
F_24 ( & V_52 ) ;
}
