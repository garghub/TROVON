static int F_1 ( T_1 T_2 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = F_2 () ;
int V_5 ;
T_1 V_6 ;
T_3 V_7 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_8 ; V_5 ++ ) {
V_7 = V_2 -> V_9 [ V_5 ] ;
V_6 = ( T_1 ) F_3 ( V_4 , V_7 ) ;
if ( F_4 ( V_6 , V_1 + V_5 ) )
return - V_10 ;
}
return 0 ;
}
static int F_5 ( struct V_2 * V_2 , T_1 T_2 * V_1 )
{
struct V_3 * V_4 = F_2 () ;
int V_5 ;
T_1 V_6 ;
T_3 V_7 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_8 ; V_5 ++ ) {
if ( F_6 ( V_6 , V_1 + V_5 ) )
return - V_10 ;
V_7 = F_7 ( V_4 , ( V_11 ) V_6 ) ;
if ( ! F_8 ( V_7 ) )
return - V_12 ;
V_2 -> V_9 [ V_5 ] = V_7 ;
}
return 0 ;
}
static int F_9 ( struct V_13 T_2 * V_14 , struct V_15 * V_16 )
{
struct V_13 V_17 ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_18 = F_10 ( V_16 -> V_19 ) ;
V_17 . V_20 = V_16 -> V_21 ;
V_17 . V_22 = ( V_23 ) V_16 -> V_21 ;
V_17 . V_24 = V_16 -> V_25 ;
V_17 . V_26 = ( unsigned int ) V_16 -> V_27 ;
V_17 . V_28 = F_11 ( F_2 () , V_16 -> V_29 ) ;
V_17 . V_30 = F_3 ( F_2 () , V_16 -> V_9 ) ;
V_17 . V_31 = F_10 ( V_16 -> V_32 ) ;
V_17 . V_33 = V_16 -> V_34 ;
V_17 . V_35 = ( V_23 ) V_16 -> V_36 ;
V_17 . V_37 = ( V_23 ) V_16 -> V_38 ;
V_17 . V_39 = ( V_23 ) V_16 -> V_40 . V_41 ;
V_17 . V_42 = ( V_23 ) V_16 -> V_43 . V_41 ;
V_17 . V_44 = ( V_23 ) V_16 -> ctime . V_41 ;
return F_12 ( V_14 , & V_17 , sizeof( V_17 ) ) ? - V_10 : 0 ;
}
