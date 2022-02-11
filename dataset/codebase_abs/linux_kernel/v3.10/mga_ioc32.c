static int F_1 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned long V_3 )
{
T_1 V_4 ;
T_2 T_3 * V_5 ;
int V_6 = 0 , V_7 ;
if ( F_2 ( & V_4 , ( void T_3 * ) V_3 , sizeof( V_4 ) ) )
return - V_8 ;
V_5 = F_3 ( sizeof( * V_5 ) ) ;
if ( ! F_4 ( V_9 , V_5 , sizeof( * V_5 ) )
|| F_5 ( V_4 . V_10 , & V_5 -> V_10 )
|| F_5 ( V_4 . V_11 , & V_5 -> V_11 )
|| F_5 ( V_4 . V_12 , & V_5 -> V_12 )
|| F_5 ( V_4 . V_13 , & V_5 -> V_13 )
|| F_5 ( V_4 . V_14 , & V_5 -> V_14 )
|| F_5 ( V_4 . V_15 , & V_5 -> V_15 )
|| F_5 ( V_4 . V_16 , & V_5 -> V_16 )
|| F_5 ( V_4 . V_17 , & V_5 -> V_17 )
|| F_5 ( V_4 . V_18 , & V_5 -> V_18 )
|| F_5 ( V_4 . V_19 , & V_5 -> V_19 )
|| F_5 ( V_4 . V_20 , & V_5 -> V_20 )
|| F_5 ( V_4 . V_21 , & V_5 -> V_21 )
|| F_5 ( V_4 . V_22 , & V_5 -> V_22 )
|| F_5 ( V_4 . V_23 , & V_5 -> V_23 )
|| F_5 ( V_4 . V_24 , & V_5 -> V_24 )
|| F_5 ( V_4 . V_25 , & V_5 -> V_25 )
|| F_5 ( V_4 . V_26 , & V_5 -> V_26 )
|| F_5 ( V_4 . V_27 , & V_5 -> V_27 )
|| F_5 ( V_4 . V_28 , & V_5 -> V_28 ) )
return - V_8 ;
for ( V_7 = 0 ; V_7 < V_29 ; V_7 ++ ) {
V_6 |=
F_5 ( V_4 . V_30 [ V_7 ] ,
& V_5 -> V_30 [ V_7 ] ) ;
V_6 |=
F_5 ( V_4 . V_31 [ V_7 ] , & V_5 -> V_31 [ V_7 ] ) ;
}
if ( V_6 )
return - V_8 ;
return F_6 ( V_1 , V_32 , ( unsigned long ) V_5 ) ;
}
static int F_7 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned long V_3 )
{
T_4 V_33 ;
T_5 T_3 * V_34 ;
if ( F_2 ( & V_33 , ( void T_3 * ) V_3 , sizeof( V_33 ) ) )
return - V_8 ;
V_34 = F_3 ( sizeof( * V_34 ) ) ;
if ( ! F_4 ( V_9 , V_34 , sizeof( * V_34 ) )
|| F_5 ( V_33 . V_35 , & V_34 -> V_35 )
|| F_5 ( ( void T_3 * ) ( unsigned long ) V_33 . V_36 ,
& V_34 -> V_36 ) )
return - V_8 ;
return F_6 ( V_1 , V_37 , ( unsigned long ) V_34 ) ;
}
static int F_8 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned long V_3 )
{
T_6 V_38 ;
T_7 T_3 * V_39 ;
int V_6 ;
if ( F_2 ( & V_38 , ( void T_3 * ) V_3 ,
sizeof( V_38 ) ) )
return - V_8 ;
V_39 = F_3 ( sizeof( * V_39 ) ) ;
if ( ! F_4 ( V_9 , V_39 , sizeof( * V_39 ) )
|| F_5 ( V_38 . V_40 ,
& V_39 -> V_40 )
|| F_5 ( V_38 . V_31 ,
& V_39 -> V_31 )
|| F_5 ( V_38 . V_41 ,
& V_39 -> V_41 )
|| F_5 ( V_38 . V_42 ,
& V_39 -> V_42 )
|| F_5 ( V_38 . V_43 ,
& V_39 -> V_43 )
|| F_5 ( V_38 . V_44 , & V_39 -> V_44 )
|| F_5 ( V_38 . V_45 , & V_39 -> V_45 ) )
return - V_8 ;
V_6 = F_6 ( V_1 , V_46 ,
( unsigned long ) V_39 ) ;
if ( V_6 )
return V_6 ;
if ( F_9 ( V_38 . V_40 ,
& V_39 -> V_40 )
|| F_9 ( V_38 . V_31 ,
& V_39 -> V_31 )
|| F_9 ( V_38 . V_41 ,
& V_39 -> V_41 )
|| F_9 ( V_38 . V_42 ,
& V_39 -> V_42 )
|| F_9 ( V_38 . V_43 ,
& V_39 -> V_43 )
|| F_9 ( V_38 . V_44 , & V_39 -> V_44 )
|| F_9 ( V_38 . V_45 , & V_39 -> V_45 ) )
return - V_8 ;
if ( F_10 ( ( void T_3 * ) V_3 , & V_38 ,
sizeof( V_38 ) ) )
return - V_8 ;
return 0 ;
}
long F_11 ( struct V_1 * V_47 , unsigned int V_2 , unsigned long V_3 )
{
unsigned int V_48 = F_12 ( V_2 ) ;
T_8 * V_49 = NULL ;
int V_50 ;
if ( V_48 < V_51 )
return F_13 ( V_47 , V_2 , V_3 ) ;
if ( V_48 < V_51 + F_14 ( V_52 ) )
V_49 = V_52 [ V_48 - V_51 ] ;
if ( V_49 != NULL )
V_50 = (* V_49) ( V_47 , V_2 , V_3 ) ;
else
V_50 = F_6 ( V_47 , V_2 , V_3 ) ;
return V_50 ;
}
