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
static int F_5 ( struct V_20 * V_20 , void * V_14 , int V_21 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 ;
struct V_22 * V_23 = V_14 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
if ( V_21 < sizeof( * V_23 ) || V_21 < ( sizeof( * V_23 ) + V_23 -> V_27 ) )
return - V_28 ;
if ( V_23 -> V_13 > V_23 -> V_16 )
return - V_28 ;
if ( V_23 -> V_13 == V_23 -> V_16 &&
V_23 -> V_15 > V_23 -> V_17 )
return - V_28 ;
V_29:
V_25 = F_6 ( V_23 -> V_30 , ( V_31 * ) V_23 + sizeof( * V_23 ) ,
V_23 -> V_27 , V_32 , V_26 ) ;
if ( V_26 & V_33 )
F_7 () ;
if ( F_8 ( V_25 ) ) {
if ( F_9 ( V_25 ) == - V_34 && ! ( V_26 & V_33 ) ) {
F_10 () ;
V_26 |= V_33 ;
goto V_29;
} else
return F_9 ( V_25 ) ;
} else if ( V_26 & V_33 ) {
F_11 ( V_25 ) ;
return - V_35 ;
}
V_8 = F_12 ( sizeof( * V_8 ) , V_32 ) ;
if ( V_8 == NULL ) {
F_11 ( V_25 ) ;
return - V_36 ;
}
V_8 -> V_15 = V_23 -> V_15 ;
V_8 -> V_17 = V_23 -> V_17 ;
V_8 -> V_13 = V_23 -> V_13 ;
V_8 -> V_16 = V_23 -> V_16 ;
V_8 -> V_18 = V_25 ;
V_4 -> V_37 = sizeof( * V_8 ) ;
V_4 -> V_14 = ( unsigned long ) V_8 ;
return 0 ;
}
static void F_13 ( struct V_3 * V_4 )
{
if ( F_2 ( V_4 ) && F_2 ( V_4 ) -> V_18 )
F_11 ( F_2 ( V_4 ) -> V_18 ) ;
}
static int F_14 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_22 V_23 ;
strncpy ( V_23 . V_30 , V_8 -> V_18 -> V_38 -> V_39 , sizeof( V_23 . V_30 ) - 1 ) ;
V_23 . V_15 = V_8 -> V_15 ;
V_23 . V_17 = V_8 -> V_17 ;
V_23 . V_13 = V_8 -> V_13 ;
V_23 . V_16 = V_8 -> V_16 ;
V_23 . V_27 = F_15 ( V_8 -> V_18 ) ;
V_23 . V_40 = 0 ;
if ( F_16 ( V_2 , sizeof( V_23 ) , & V_23 ) < 0 )
goto V_41;
if ( F_17 ( V_2 , V_23 . V_27 ,
F_18 ( V_8 -> V_18 ) ) < 0 )
goto V_41;
return 0 ;
V_41:
return - 1 ;
}
static int T_1 F_19 ( void )
{
return F_20 ( & V_42 ) ;
}
static void T_2 F_21 ( void )
{
F_22 ( & V_42 ) ;
}
