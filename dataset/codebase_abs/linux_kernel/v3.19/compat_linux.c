static int F_1 ( T_1 T_2 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = F_2 () ;
int V_5 ;
T_1 V_6 ;
T_3 V_7 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_8 ; V_5 ++ ) {
V_7 = F_3 ( V_2 , V_5 ) ;
V_6 = ( T_1 ) F_4 ( V_4 , V_7 ) ;
if ( F_5 ( V_6 , V_1 + V_5 ) )
return - V_9 ;
}
return 0 ;
}
static int F_6 ( struct V_2 * V_2 , T_1 T_2 * V_1 )
{
struct V_3 * V_4 = F_2 () ;
int V_5 ;
T_1 V_6 ;
T_3 V_7 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_8 ; V_5 ++ ) {
if ( F_7 ( V_6 , V_1 + V_5 ) )
return - V_9 ;
V_7 = F_8 ( V_4 , ( V_10 ) V_6 ) ;
if ( ! F_9 ( V_7 ) )
return - V_11 ;
F_3 ( V_2 , V_5 ) = V_7 ;
}
return 0 ;
}
static int F_10 ( struct V_12 T_2 * V_13 , struct V_14 * V_15 )
{
struct V_12 V_16 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_17 = F_11 ( V_15 -> V_18 ) ;
V_16 . V_19 = V_15 -> V_20 ;
V_16 . V_21 = ( V_22 ) V_15 -> V_20 ;
V_16 . V_23 = V_15 -> V_24 ;
V_16 . V_25 = ( unsigned int ) V_15 -> V_26 ;
V_16 . V_27 = F_12 ( F_2 () , V_15 -> V_28 ) ;
V_16 . V_29 = F_4 ( F_2 () , V_15 -> V_30 ) ;
V_16 . V_31 = F_11 ( V_15 -> V_32 ) ;
V_16 . V_33 = V_15 -> V_34 ;
V_16 . V_35 = ( V_22 ) V_15 -> V_36 ;
V_16 . V_37 = ( V_22 ) V_15 -> V_38 ;
V_16 . V_39 = ( V_22 ) V_15 -> V_40 . V_41 ;
V_16 . V_42 = ( V_22 ) V_15 -> V_43 . V_41 ;
V_16 . V_44 = ( V_22 ) V_15 -> ctime . V_41 ;
return F_13 ( V_13 , & V_16 , sizeof( V_16 ) ) ? - V_9 : 0 ;
}
