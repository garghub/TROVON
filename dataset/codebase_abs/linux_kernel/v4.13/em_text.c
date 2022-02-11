static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_9 , V_10 ;
V_9 = F_3 ( V_2 , V_8 -> V_11 ) - V_2 -> V_12 ;
V_9 += V_8 -> V_13 ;
V_10 = F_3 ( V_2 , V_8 -> V_14 ) - V_2 -> V_12 ;
V_10 += V_8 -> V_15 ;
return F_4 ( V_2 , V_9 , V_10 , V_8 -> V_16 ) != V_17 ;
}
static int F_5 ( struct V_18 * V_18 , void * V_12 , int V_19 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 ;
struct V_20 * V_21 = V_12 ;
struct V_22 * V_23 ;
int V_24 = 0 ;
if ( V_19 < sizeof( * V_21 ) || V_19 < ( sizeof( * V_21 ) + V_21 -> V_25 ) )
return - V_26 ;
if ( V_21 -> V_11 > V_21 -> V_14 )
return - V_26 ;
if ( V_21 -> V_11 == V_21 -> V_14 &&
V_21 -> V_13 > V_21 -> V_15 )
return - V_26 ;
V_27:
V_23 = F_6 ( V_21 -> V_28 , ( V_29 * ) V_21 + sizeof( * V_21 ) ,
V_21 -> V_25 , V_30 , V_24 ) ;
if ( V_24 & V_31 )
F_7 () ;
if ( F_8 ( V_23 ) ) {
if ( F_9 ( V_23 ) == - V_32 && ! ( V_24 & V_31 ) ) {
F_10 () ;
V_24 |= V_31 ;
goto V_27;
} else
return F_9 ( V_23 ) ;
} else if ( V_24 & V_31 ) {
F_11 ( V_23 ) ;
return - V_33 ;
}
V_8 = F_12 ( sizeof( * V_8 ) , V_30 ) ;
if ( V_8 == NULL ) {
F_11 ( V_23 ) ;
return - V_34 ;
}
V_8 -> V_13 = V_21 -> V_13 ;
V_8 -> V_15 = V_21 -> V_15 ;
V_8 -> V_11 = V_21 -> V_11 ;
V_8 -> V_14 = V_21 -> V_14 ;
V_8 -> V_16 = V_23 ;
V_4 -> V_35 = sizeof( * V_8 ) ;
V_4 -> V_12 = ( unsigned long ) V_8 ;
return 0 ;
}
static void F_13 ( struct V_3 * V_4 )
{
if ( F_2 ( V_4 ) && F_2 ( V_4 ) -> V_16 )
F_11 ( F_2 ( V_4 ) -> V_16 ) ;
}
static int F_14 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_20 V_21 ;
strncpy ( V_21 . V_28 , V_8 -> V_16 -> V_36 -> V_37 , sizeof( V_21 . V_28 ) - 1 ) ;
V_21 . V_13 = V_8 -> V_13 ;
V_21 . V_15 = V_8 -> V_15 ;
V_21 . V_11 = V_8 -> V_11 ;
V_21 . V_14 = V_8 -> V_14 ;
V_21 . V_25 = F_15 ( V_8 -> V_16 ) ;
V_21 . V_38 = 0 ;
if ( F_16 ( V_2 , sizeof( V_21 ) , & V_21 ) < 0 )
goto V_39;
if ( F_17 ( V_2 , V_21 . V_25 ,
F_18 ( V_8 -> V_16 ) ) < 0 )
goto V_39;
return 0 ;
V_39:
return - 1 ;
}
static int T_1 F_19 ( void )
{
return F_20 ( & V_40 ) ;
}
static void T_2 F_21 ( void )
{
F_22 ( & V_40 ) ;
}
