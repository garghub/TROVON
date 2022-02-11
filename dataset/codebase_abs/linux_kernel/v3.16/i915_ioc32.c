static int F_1 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned long V_3 )
{
T_1 V_4 ;
T_2 T_3 * V_5 ;
if ( F_2
( & V_4 , ( void T_3 * ) V_3 , sizeof( V_4 ) ) )
return - V_6 ;
V_5 = F_3 ( sizeof( * V_5 ) ) ;
if ( ! F_4 ( V_7 , V_5 , sizeof( * V_5 ) )
|| F_5 ( V_4 . V_8 , & V_5 -> V_8 )
|| F_5 ( V_4 . V_9 , & V_5 -> V_9 )
|| F_5 ( V_4 . V_10 , & V_5 -> V_10 )
|| F_5 ( V_4 . V_11 , & V_5 -> V_11 )
|| F_5 ( V_4 . V_12 ,
& V_5 -> V_12 )
|| F_5 ( ( int T_3 * ) ( unsigned long ) V_4 . V_13 ,
& V_5 -> V_13 ) )
return - V_6 ;
return F_6 ( V_1 , V_14 ,
( unsigned long ) V_5 ) ;
}
static int F_7 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned long V_3 )
{
T_4 V_15 ;
T_5 T_3 * V_16 ;
if ( F_2
( & V_15 , ( void T_3 * ) V_3 , sizeof( V_15 ) ) )
return - V_6 ;
V_16 = F_3 ( sizeof( * V_16 ) ) ;
if ( ! F_4 ( V_7 , V_16 , sizeof( * V_16 ) )
|| F_5 ( ( int T_3 * ) ( unsigned long ) V_15 . V_17 ,
& V_16 -> V_17 )
|| F_5 ( V_15 . V_18 , & V_16 -> V_18 )
|| F_5 ( V_15 . V_10 , & V_16 -> V_10 )
|| F_5 ( V_15 . V_11 , & V_16 -> V_11 )
|| F_5 ( V_15 . V_12 , & V_16 -> V_12 )
|| F_5 ( ( int T_3 * ) ( unsigned long ) V_15 . V_13 ,
& V_16 -> V_13 ) )
return - V_6 ;
return F_6 ( V_1 , V_19 ,
( unsigned long ) V_16 ) ;
}
static int F_8 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned long V_3 )
{
T_6 V_20 ;
T_7 T_3 * V_21 ;
if ( F_2 ( & V_20 , ( void T_3 * ) V_3 , sizeof( V_20 ) ) )
return - V_6 ;
V_21 = F_3 ( sizeof( * V_21 ) ) ;
if ( ! F_4 ( V_7 , V_21 , sizeof( * V_21 ) )
|| F_5 ( ( int T_3 * ) ( unsigned long ) V_20 . V_22 ,
& V_21 -> V_22 ) )
return - V_6 ;
return F_6 ( V_1 , V_23 ,
( unsigned long ) V_21 ) ;
}
static int F_9 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned long V_3 )
{
T_8 V_20 ;
T_9 T_3 * V_21 ;
if ( F_2 ( & V_20 , ( void T_3 * ) V_3 , sizeof( V_20 ) ) )
return - V_6 ;
V_21 = F_3 ( sizeof( * V_21 ) ) ;
if ( ! F_4 ( V_7 , V_21 , sizeof( * V_21 ) )
|| F_5 ( V_20 . V_24 , & V_21 -> V_24 )
|| F_5 ( ( void T_3 * ) ( unsigned long ) V_20 . V_25 ,
& V_21 -> V_25 ) )
return - V_6 ;
return F_6 ( V_1 , V_26 ,
( unsigned long ) V_21 ) ;
}
static int F_10 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned long V_3 )
{
T_10 V_20 ;
T_11 T_3 * V_21 ;
if ( F_2 ( & V_20 , ( void T_3 * ) V_3 , sizeof( V_20 ) ) )
return - V_6 ;
V_21 = F_3 ( sizeof( * V_21 ) ) ;
if ( ! F_4 ( V_7 , V_21 , sizeof( * V_21 ) )
|| F_5 ( V_20 . V_27 , & V_21 -> V_27 )
|| F_5 ( V_20 . V_28 , & V_21 -> V_28 )
|| F_5 ( V_20 . V_29 , & V_21 -> V_29 )
|| F_5 ( ( void T_3 * ) ( unsigned long ) V_20 . V_30 ,
& V_21 -> V_30 ) )
return - V_6 ;
return F_6 ( V_1 , V_31 ,
( unsigned long ) V_21 ) ;
}
long F_11 ( struct V_1 * V_32 , unsigned int V_2 , unsigned long V_3 )
{
unsigned int V_33 = F_12 ( V_2 ) ;
T_12 * V_34 = NULL ;
int V_35 ;
if ( V_33 < V_36 )
return F_13 ( V_32 , V_2 , V_3 ) ;
if ( V_33 < V_36 + F_14 ( V_37 ) )
V_34 = V_37 [ V_33 - V_36 ] ;
if ( V_34 != NULL )
V_35 = (* V_34) ( V_32 , V_2 , V_3 ) ;
else
V_35 = F_6 ( V_32 , V_2 , V_3 ) ;
return V_35 ;
}
