static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = sizeof( struct V_4 ) + V_2 -> V_5 . V_6 ;
int V_7 ;
V_2 -> V_8 = F_2 ( V_3 * V_2 -> V_5 . V_9 ,
V_2 -> V_5 . V_10 ) ;
if ( ! V_2 -> V_8 )
return - V_11 ;
V_7 = F_3 ( & V_2 -> V_12 ) ;
if ( V_7 )
goto V_13;
F_4 ( & V_2 -> V_12 , V_2 -> V_8 , V_3 ,
V_2 -> V_5 . V_9 ) ;
return 0 ;
V_13:
F_5 ( V_2 -> V_8 ) ;
return V_7 ;
}
static struct V_14 * F_6 ( union V_15 * V_16 )
{
T_1 V_6 = V_16 -> V_6 ;
struct V_1 * V_2 ;
T_2 V_17 , V_18 ;
int V_7 ;
if ( ! F_7 ( V_19 ) )
return F_8 ( - V_20 ) ;
if ( V_16 -> V_21 & ~ V_22 )
return F_8 ( - V_23 ) ;
if ( V_16 -> V_9 == 0 || V_16 -> V_24 != 4 ||
V_6 < 8 || V_6 % 8 ||
V_6 / 8 > V_25 )
return F_8 ( - V_23 ) ;
V_18 = F_9 ( V_16 -> V_9 ) ;
V_17 = V_18 * sizeof( struct V_4 * ) + sizeof( * V_2 ) ;
if ( V_17 >= V_26 - V_27 )
return F_8 ( - V_28 ) ;
V_2 = F_2 ( V_17 , F_10 ( V_16 ) ) ;
if ( ! V_2 )
return F_8 ( - V_11 ) ;
V_7 = - V_28 ;
V_17 += V_18 * ( V_6 + sizeof( struct V_4 ) ) ;
if ( V_17 >= V_26 - V_27 )
goto V_29;
V_2 -> V_5 . V_30 = V_16 -> V_30 ;
V_2 -> V_5 . V_24 = V_16 -> V_24 ;
V_2 -> V_5 . V_6 = V_6 ;
V_2 -> V_5 . V_9 = V_16 -> V_9 ;
V_2 -> V_5 . V_21 = V_16 -> V_21 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_5 . V_31 = F_11 ( V_17 , V_27 ) >> V_32 ;
V_2 -> V_5 . V_10 = F_10 ( V_16 ) ;
V_7 = F_12 ( V_2 -> V_5 . V_31 ) ;
if ( V_7 )
goto V_29;
V_7 = F_13 ( V_25 ) ;
if ( V_7 )
goto V_29;
V_7 = F_1 ( V_2 ) ;
if ( V_7 )
goto V_33;
return & V_2 -> V_5 ;
V_33:
F_14 () ;
V_29:
F_5 ( V_2 ) ;
return F_8 ( V_7 ) ;
}
static void * F_15 ( struct V_14 * V_5 , void * V_34 )
{
return NULL ;
}
int F_16 ( struct V_14 * V_5 , void * V_34 , void * V_35 )
{
struct V_1 * V_2 = F_17 ( V_5 , struct V_1 , V_5 ) ;
struct V_4 * V_36 , * V_37 ;
T_1 V_38 = * ( T_1 * ) V_34 , V_39 ;
if ( F_18 ( V_38 >= V_2 -> V_18 ) )
return - V_40 ;
V_36 = F_19 ( & V_2 -> V_41 [ V_38 ] , NULL ) ;
if ( ! V_36 )
return - V_40 ;
V_39 = V_36 -> V_42 * sizeof( T_2 ) ;
memcpy ( V_35 , V_36 -> V_43 , V_39 ) ;
memset ( V_35 + V_39 , 0 , V_5 -> V_6 - V_39 ) ;
V_37 = F_19 ( & V_2 -> V_41 [ V_38 ] , V_36 ) ;
if ( V_37 )
F_20 ( & V_2 -> V_12 , & V_37 -> V_44 ) ;
return 0 ;
}
static int F_21 ( struct V_14 * V_5 , void * V_34 , void * V_45 )
{
return - V_23 ;
}
static int F_22 ( struct V_14 * V_5 , void * V_34 , void * V_35 ,
T_2 V_21 )
{
return - V_23 ;
}
static int F_23 ( struct V_14 * V_5 , void * V_34 )
{
struct V_1 * V_2 = F_17 ( V_5 , struct V_1 , V_5 ) ;
struct V_4 * V_37 ;
T_1 V_38 = * ( T_1 * ) V_34 ;
if ( F_18 ( V_38 >= V_2 -> V_18 ) )
return - V_28 ;
V_37 = F_19 ( & V_2 -> V_41 [ V_38 ] , NULL ) ;
if ( V_37 ) {
F_20 ( & V_2 -> V_12 , & V_37 -> V_44 ) ;
return 0 ;
} else {
return - V_40 ;
}
}
static void F_24 ( struct V_14 * V_5 )
{
struct V_1 * V_2 = F_17 ( V_5 , struct V_1 , V_5 ) ;
F_25 () ;
F_5 ( V_2 -> V_8 ) ;
F_26 ( & V_2 -> V_12 ) ;
F_5 ( V_2 ) ;
F_14 () ;
}
