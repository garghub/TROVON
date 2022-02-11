static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = sizeof( struct V_4 ) + V_2 -> V_5 . V_6 ;
int V_7 ;
V_2 -> V_8 = F_2 ( V_3 * V_2 -> V_5 . V_9 ) ;
if ( ! V_2 -> V_8 )
return - V_10 ;
V_7 = F_3 ( & V_2 -> V_11 ) ;
if ( V_7 )
goto V_12;
F_4 ( & V_2 -> V_11 , V_2 -> V_8 , V_3 ,
V_2 -> V_5 . V_9 ) ;
return 0 ;
V_12:
F_5 ( V_2 -> V_8 ) ;
return V_7 ;
}
static struct V_13 * F_6 ( union V_14 * V_15 )
{
T_1 V_6 = V_15 -> V_6 ;
struct V_1 * V_2 ;
T_2 V_16 , V_17 ;
int V_7 ;
if ( ! F_7 ( V_18 ) )
return F_8 ( - V_19 ) ;
if ( V_15 -> V_20 )
return F_8 ( - V_21 ) ;
if ( V_15 -> V_9 == 0 || V_15 -> V_22 != 4 ||
V_6 < 8 || V_6 % 8 ||
V_6 / 8 > V_23 )
return F_8 ( - V_21 ) ;
V_17 = F_9 ( V_15 -> V_9 ) ;
V_16 = V_17 * sizeof( struct V_4 * ) + sizeof( * V_2 ) ;
if ( V_16 >= V_24 - V_25 )
return F_8 ( - V_26 ) ;
V_2 = F_2 ( V_16 ) ;
if ( ! V_2 )
return F_8 ( - V_10 ) ;
V_7 = - V_26 ;
V_16 += V_17 * ( V_6 + sizeof( struct V_4 ) ) ;
if ( V_16 >= V_24 - V_25 )
goto V_27;
V_2 -> V_5 . V_28 = V_15 -> V_28 ;
V_2 -> V_5 . V_22 = V_15 -> V_22 ;
V_2 -> V_5 . V_6 = V_6 ;
V_2 -> V_5 . V_9 = V_15 -> V_9 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_5 . V_29 = F_10 ( V_16 , V_25 ) >> V_30 ;
V_7 = F_11 ( V_2 -> V_5 . V_29 ) ;
if ( V_7 )
goto V_27;
V_7 = F_12 ( V_23 ) ;
if ( V_7 )
goto V_27;
V_7 = F_1 ( V_2 ) ;
if ( V_7 )
goto V_31;
return & V_2 -> V_5 ;
V_31:
F_13 () ;
V_27:
F_5 ( V_2 ) ;
return F_8 ( V_7 ) ;
}
static void * F_14 ( struct V_13 * V_5 , void * V_32 )
{
return NULL ;
}
int F_15 ( struct V_13 * V_5 , void * V_32 , void * V_33 )
{
struct V_1 * V_2 = F_16 ( V_5 , struct V_1 , V_5 ) ;
struct V_4 * V_34 , * V_35 ;
T_1 V_36 = * ( T_1 * ) V_32 , V_37 ;
if ( F_17 ( V_36 >= V_2 -> V_17 ) )
return - V_38 ;
V_34 = F_18 ( & V_2 -> V_39 [ V_36 ] , NULL ) ;
if ( ! V_34 )
return - V_38 ;
V_37 = V_34 -> V_40 * sizeof( T_2 ) ;
memcpy ( V_33 , V_34 -> V_41 , V_37 ) ;
memset ( V_33 + V_37 , 0 , V_5 -> V_6 - V_37 ) ;
V_35 = F_18 ( & V_2 -> V_39 [ V_36 ] , V_34 ) ;
if ( V_35 )
F_19 ( & V_2 -> V_11 , & V_35 -> V_42 ) ;
return 0 ;
}
static int F_20 ( struct V_13 * V_5 , void * V_32 , void * V_43 )
{
return - V_21 ;
}
static int F_21 ( struct V_13 * V_5 , void * V_32 , void * V_33 ,
T_2 V_20 )
{
return - V_21 ;
}
static int F_22 ( struct V_13 * V_5 , void * V_32 )
{
struct V_1 * V_2 = F_16 ( V_5 , struct V_1 , V_5 ) ;
struct V_4 * V_35 ;
T_1 V_36 = * ( T_1 * ) V_32 ;
if ( F_17 ( V_36 >= V_2 -> V_17 ) )
return - V_26 ;
V_35 = F_18 ( & V_2 -> V_39 [ V_36 ] , NULL ) ;
if ( V_35 ) {
F_19 ( & V_2 -> V_11 , & V_35 -> V_42 ) ;
return 0 ;
} else {
return - V_38 ;
}
}
static void F_23 ( struct V_13 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 , struct V_1 , V_5 ) ;
F_24 () ;
F_5 ( V_2 -> V_8 ) ;
F_25 ( & V_2 -> V_11 ) ;
F_5 ( V_2 ) ;
F_13 () ;
}
static int T_3 F_26 ( void )
{
F_27 ( & V_44 ) ;
return 0 ;
}
