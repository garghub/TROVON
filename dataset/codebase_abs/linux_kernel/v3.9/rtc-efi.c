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
F_4 ( L_1 ) ;
return - 1 ;
}
for ( V_5 = V_7 ; V_5 < V_1 -> V_4 ; V_5 ++ )
V_6 += 365 + ( F_5 ( V_5 ) ? 1 : 0 ) ;
V_6 += F_1 ( V_1 ) ;
return ( V_6 + 4 ) % 7 ;
}
static void
F_6 ( struct V_8 * V_9 , T_1 * V_1 )
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
static void
F_7 ( T_1 * V_1 , struct V_8 * V_9 )
{
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_18 = V_1 -> V_17 ;
V_9 -> V_16 = V_1 -> V_15 ;
V_9 -> V_14 = V_1 -> V_13 ;
V_9 -> V_12 = V_1 -> V_2 ;
V_9 -> V_11 = V_1 -> V_3 - 1 ;
V_9 -> V_10 = V_1 -> V_4 - 1900 ;
V_9 -> V_25 = F_3 ( V_1 ) ;
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
}
static int F_8 ( struct V_28 * V_29 , struct V_30 * V_31 )
{
T_1 V_1 ;
T_2 V_32 ;
V_32 = V_33 . V_34 ( ( V_35 * ) & V_31 -> V_36 ,
( V_35 * ) & V_31 -> V_37 , & V_1 ) ;
if ( V_32 != V_38 )
return - V_39 ;
F_7 ( & V_1 , & V_31 -> time ) ;
return F_9 ( & V_31 -> time ) ;
}
static int F_10 ( struct V_28 * V_29 , struct V_30 * V_31 )
{
T_1 V_1 ;
T_2 V_32 ;
F_6 ( & V_31 -> time , & V_1 ) ;
V_32 = V_33 . V_40 ( ( V_35 ) V_31 -> V_36 , & V_1 ) ;
F_11 ( V_29 , L_2 , ( int ) V_32 ) ;
return V_32 == V_38 ? 0 : - V_39 ;
}
static int F_12 ( struct V_28 * V_29 , struct V_8 * V_41 )
{
T_2 V_32 ;
T_1 V_1 ;
T_3 V_42 ;
V_32 = V_33 . V_43 ( & V_1 , & V_42 ) ;
if ( V_32 != V_38 ) {
F_13 ( V_29 , L_3 ) ;
return - V_39 ;
}
F_7 ( & V_1 , V_41 ) ;
return F_9 ( V_41 ) ;
}
static int F_14 ( struct V_28 * V_29 , struct V_8 * V_41 )
{
T_2 V_32 ;
T_1 V_1 ;
F_6 ( V_41 , & V_1 ) ;
V_32 = V_33 . V_44 ( & V_1 ) ;
return V_32 == V_38 ? 0 : - V_39 ;
}
static int T_4 F_15 ( struct V_45 * V_29 )
{
struct V_46 * V_47 ;
V_47 = F_16 ( L_4 , & V_29 -> V_29 , & V_48 ,
V_49 ) ;
if ( F_17 ( V_47 ) )
return F_18 ( V_47 ) ;
F_19 ( V_29 , V_47 ) ;
return 0 ;
}
static int T_5 F_20 ( struct V_45 * V_29 )
{
struct V_46 * V_47 = F_21 ( V_29 ) ;
F_22 ( V_47 ) ;
return 0 ;
}
static int T_4 F_23 ( void )
{
return F_24 ( & V_50 , F_15 ) ;
}
static void T_5 F_25 ( void )
{
F_26 ( & V_50 ) ;
}
