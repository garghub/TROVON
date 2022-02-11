static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_9 , V_10 ;
struct V_11 V_12 ;
V_9 = F_3 ( V_2 , V_8 -> V_13 ) - V_2 -> V_14 ;
V_9 += V_8 -> V_15 ;
V_10 = F_3 ( V_2 , V_8 -> V_16 ) - V_2 -> V_14 ;
V_10 += V_8 -> V_17 ;
return F_4 ( V_2 , V_9 , V_10 , V_8 -> V_18 , & V_12 ) != V_19 ;
}
static int F_5 ( struct V_20 * V_21 , void * V_14 , int V_22 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 ;
struct V_23 * V_24 = V_14 ;
struct V_25 * V_26 ;
int V_27 = 0 ;
if ( V_22 < sizeof( * V_24 ) || V_22 < ( sizeof( * V_24 ) + V_24 -> V_28 ) )
return - V_29 ;
if ( V_24 -> V_13 > V_24 -> V_16 )
return - V_29 ;
if ( V_24 -> V_13 == V_24 -> V_16 &&
V_24 -> V_15 > V_24 -> V_17 )
return - V_29 ;
V_30:
V_26 = F_6 ( V_24 -> V_31 , ( V_32 * ) V_24 + sizeof( * V_24 ) ,
V_24 -> V_28 , V_33 , V_27 ) ;
if ( V_27 & V_34 )
F_7 () ;
if ( F_8 ( V_26 ) ) {
if ( F_9 ( V_26 ) == - V_35 && ! ( V_27 & V_34 ) ) {
F_10 () ;
V_27 |= V_34 ;
goto V_30;
} else
return F_9 ( V_26 ) ;
} else if ( V_27 & V_34 ) {
F_11 ( V_26 ) ;
return - V_36 ;
}
V_8 = F_12 ( sizeof( * V_8 ) , V_33 ) ;
if ( V_8 == NULL ) {
F_11 ( V_26 ) ;
return - V_37 ;
}
V_8 -> V_15 = V_24 -> V_15 ;
V_8 -> V_17 = V_24 -> V_17 ;
V_8 -> V_13 = V_24 -> V_13 ;
V_8 -> V_16 = V_24 -> V_16 ;
V_8 -> V_18 = V_26 ;
V_4 -> V_38 = sizeof( * V_8 ) ;
V_4 -> V_14 = ( unsigned long ) V_8 ;
return 0 ;
}
static void F_13 ( struct V_20 * V_21 , struct V_3 * V_4 )
{
if ( F_2 ( V_4 ) && F_2 ( V_4 ) -> V_18 )
F_11 ( F_2 ( V_4 ) -> V_18 ) ;
}
static int F_14 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_23 V_24 ;
strncpy ( V_24 . V_31 , V_8 -> V_18 -> V_39 -> V_40 , sizeof( V_24 . V_31 ) - 1 ) ;
V_24 . V_15 = V_8 -> V_15 ;
V_24 . V_17 = V_8 -> V_17 ;
V_24 . V_13 = V_8 -> V_13 ;
V_24 . V_16 = V_8 -> V_16 ;
V_24 . V_28 = F_15 ( V_8 -> V_18 ) ;
V_24 . V_41 = 0 ;
if ( F_16 ( V_2 , sizeof( V_24 ) , & V_24 ) < 0 )
goto V_42;
if ( F_17 ( V_2 , V_24 . V_28 ,
F_18 ( V_8 -> V_18 ) ) < 0 )
goto V_42;
return 0 ;
V_42:
return - 1 ;
}
static int T_1 F_19 ( void )
{
return F_20 ( & V_43 ) ;
}
static void T_2 F_21 ( void )
{
F_22 ( & V_43 ) ;
}
