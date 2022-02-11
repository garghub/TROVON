int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_16 ;
V_9 = F_3 ( V_2 -> V_7 , V_4 -> V_17 ) ;
if ( ! V_9 )
return - V_18 ;
V_11 = F_4 ( V_9 ) ;
V_2 -> V_19 = V_11 ;
V_2 -> V_20 ( V_2 ) ;
V_11 -> V_2 = V_2 ;
if ( V_4 -> V_21 > V_22 ) {
V_16 = - V_18 ;
goto V_23;
}
V_16 = F_5 ( V_6 , V_11 , V_4 -> V_24 , V_4 -> V_25 ) ;
if ( V_16 )
goto V_23;
V_13 = F_6 ( V_6 -> V_26 . V_27 , V_28 ) ;
if ( ! V_13 ) {
V_16 = - V_29 ;
goto V_23;
}
V_15 = F_7 ( V_6 ) ;
if ( ! V_15 ) {
V_16 = - V_29 ;
goto V_30;
}
F_8 ( V_13 , V_31 ) ;
V_13 -> V_32 . V_33 = 0 ;
V_13 -> V_34 = V_6 -> V_35 ;
V_13 -> V_36 = V_11 -> V_35 ;
V_13 -> V_37 = V_2 -> V_37 . V_38 . V_39 ;
V_13 -> V_40 = V_2 -> V_37 . V_41 ;
if ( V_4 -> V_42 ) {
V_13 -> V_43 =
F_9 ( V_4 -> V_21 ) ;
memcpy ( & V_13 -> V_42 [ 0 ] , V_4 -> V_42 ,
V_4 -> V_21 ) ;
} else
V_13 -> V_43 = 0 ;
V_16 = F_10 ( V_6 , (union V_44 * ) V_13 ) ;
F_11 ( V_6 , V_15 ) ;
V_30:
F_12 ( V_13 ) ;
V_23:
if ( V_16 ) {
V_2 -> V_19 = NULL ;
V_11 -> V_2 = NULL ;
V_2 -> V_45 ( V_2 ) ;
}
return V_16 ;
}
int F_13 ( struct V_1 * V_2 , int V_46 )
{
struct V_5 * V_6 ;
struct V_47 V_13 ;
struct V_48 * V_49 ;
struct V_14 * V_15 ;
int V_16 ;
V_6 = F_2 ( V_2 -> V_7 ) ;
if ( V_6 == NULL )
return - V_18 ;
V_15 = F_7 ( V_6 ) ;
if ( ! V_15 )
return - V_29 ;
F_8 ( & V_13 , V_50 ) ;
V_13 . V_32 . V_33 = ( V_51 ) ( unsigned long ) V_15 ;
V_13 . V_34 = V_6 -> V_35 ;
V_13 . V_52 = V_2 -> V_52 . V_38 . V_39 ;
V_13 . V_53 = V_2 -> V_52 . V_41 ;
V_13 . V_46 = F_9 ( V_46 ) ;
V_13 . V_54 = ( V_51 ) ( unsigned long ) V_2 ;
F_14 ( V_6 , V_15 ) ;
V_16 = F_10 ( V_6 , (union V_44 * ) & V_13 ) ;
if ( V_16 ) {
F_15 ( V_6 , V_15 ) ;
goto V_23;
}
V_16 = F_16 ( V_6 , V_15 ) ;
if ( V_16 )
goto V_23;
V_49 =
(struct V_48 * ) ( unsigned long ) V_15 -> V_55 ;
if ( ! V_49 ) {
V_16 = - V_29 ;
goto V_30;
}
if ( ( V_16 = F_17 ( V_49 ) ) != 0 )
goto V_30;
V_2 -> V_19 = ( void * ) ( unsigned long ) V_49 -> V_56 ;
F_18 ( V_6 , V_49 ) ;
F_11 ( V_6 , V_15 ) ;
return 0 ;
V_30:
F_18 ( V_6 , V_49 ) ;
V_23:
F_11 ( V_6 , V_15 ) ;
return V_16 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_57 V_13 ;
struct V_58 * V_49 ;
struct V_14 * V_15 ;
int V_16 ;
V_6 = F_2 ( V_2 -> V_7 ) ;
if ( V_6 == NULL )
return - V_18 ;
V_15 = F_7 ( V_6 ) ;
if ( ! V_15 )
return - V_29 ;
F_8 ( & V_13 , V_59 ) ;
V_13 . V_32 . V_33 = ( unsigned long ) V_15 ;
V_13 . V_34 = V_6 -> V_35 ;
V_13 . V_56 = ( V_60 ) ( unsigned long ) V_2 -> V_19 ;
F_14 ( V_6 , V_15 ) ;
V_16 = F_10 ( V_6 , (union V_44 * ) & V_13 ) ;
if ( V_16 ) {
F_15 ( V_6 , V_15 ) ;
goto V_23;
}
V_16 = F_16 ( V_6 , V_15 ) ;
if ( V_16 )
goto V_23;
V_49 = (struct V_58 * ) ( unsigned long ) V_15 -> V_55 ;
if ( ! V_49 ) {
V_16 = - V_29 ;
goto V_23;
}
if ( ( V_16 = F_17 ( V_49 ) ) != 0 )
goto V_30;
V_30:
F_18 ( V_6 , V_49 ) ;
V_23:
F_11 ( V_6 , V_15 ) ;
return V_16 ;
}
int F_20 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
struct V_61 * V_13 ;
struct V_14 * V_15 ;
struct V_62 * V_49 ;
int V_16 ;
V_9 = F_3 ( V_2 -> V_7 , V_4 -> V_17 ) ;
if ( ! V_9 )
return - V_18 ;
V_11 = F_4 ( V_9 ) ;
V_16 = F_5 ( V_6 , V_11 , V_4 -> V_24 , V_4 -> V_25 ) ;
if ( V_16 )
goto V_23;
V_15 = F_7 ( V_6 ) ;
if ( ! V_15 ) {
V_16 = - V_29 ;
goto V_23;
}
V_15 -> V_11 = V_11 ;
V_15 -> V_2 = V_2 ;
V_15 -> V_63 = V_64 ;
V_13 = F_6 ( V_6 -> V_26 . V_27 , V_28 ) ;
if ( ! V_13 ) {
V_16 = - V_29 ;
goto V_30;
}
F_8 ( V_13 , V_65 ) ;
V_13 -> V_32 . V_33 = ( unsigned long ) V_15 ;
V_13 -> V_34 = V_6 -> V_35 ;
V_13 -> V_56 = ( V_60 ) ( unsigned long ) V_2 -> V_19 ;
V_13 -> V_36 = V_11 -> V_35 ;
V_2 -> V_19 = V_11 ;
V_2 -> V_20 ( V_2 ) ;
V_11 -> V_2 = V_2 ;
V_2 -> V_19 = V_11 ;
if ( V_4 -> V_21 > V_22 ) {
V_16 = - V_18 ;
goto V_30;
}
if ( V_4 -> V_42 ) {
V_13 -> V_43 = F_9 ( V_4 -> V_21 ) ;
memcpy ( & V_13 -> V_42 [ 0 ] ,
V_4 -> V_42 , V_4 -> V_21 ) ;
} else
V_13 -> V_43 = 0 ;
F_14 ( V_6 , V_15 ) ;
V_16 = F_10 ( V_6 , (union V_44 * ) V_13 ) ;
if ( V_16 ) {
F_15 ( V_6 , V_15 ) ;
goto V_30;
}
V_16 = F_16 ( V_6 , V_15 ) ;
if ( V_16 )
goto V_30;
V_49 = (struct V_62 * ) ( unsigned long ) V_15 -> V_55 ;
if ( ! V_49 ) {
V_16 = - V_29 ;
goto V_30;
}
V_16 = F_17 ( V_49 ) ;
F_18 ( V_6 , V_49 ) ;
if ( ! V_16 )
F_21 ( V_11 , V_66 ) ;
V_30:
F_12 ( V_13 ) ;
F_11 ( V_6 , V_15 ) ;
V_23:
if ( V_16 ) {
V_2 -> V_19 = NULL ;
V_11 -> V_2 = NULL ;
V_2 -> V_45 ( V_2 ) ;
}
return V_16 ;
}
int F_22 ( struct V_1 * V_2 , const void * V_67 , T_1 V_68 )
{
struct V_5 * V_6 ;
struct V_69 V_13 ;
struct V_14 * V_15 ;
struct V_70 * V_49 ;
int V_16 ;
V_6 = F_2 ( V_2 -> V_7 ) ;
V_15 = F_7 ( V_6 ) ;
if ( ! V_15 )
return - V_29 ;
F_8 ( & V_13 , V_71 ) ;
V_13 . V_32 . V_33 = ( unsigned long ) V_15 ;
V_13 . V_34 = V_6 -> V_35 ;
V_13 . V_56 = ( V_60 ) ( unsigned long ) V_2 -> V_19 ;
F_14 ( V_6 , V_15 ) ;
V_16 = F_10 ( V_6 , (union V_44 * ) & V_13 ) ;
if ( V_16 ) {
F_15 ( V_6 , V_15 ) ;
goto V_23;
}
V_16 = F_16 ( V_6 , V_15 ) ;
if ( V_16 )
goto V_23;
V_49 = (struct V_70 * ) ( unsigned long )
V_15 -> V_55 ;
if ( ! V_49 ) {
V_16 = - V_29 ;
goto V_23;
}
V_16 = F_17 ( V_49 ) ;
F_18 ( V_6 , V_49 ) ;
V_23:
F_11 ( V_6 , V_15 ) ;
return V_16 ;
}
