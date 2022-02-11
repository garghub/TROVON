int F_1 ( struct V_1 * V_2 , char * args )
{
F_2 ( L_1 ,
V_2 -> V_3 ,
V_2 -> V_4 ,
V_2 -> V_5 ,
V_2 -> V_6 ,
V_2 -> V_7 ,
V_2 -> V_8 ,
args ) ;
ASSERT ( V_2 -> V_5 >= 0 &&
V_2 -> V_5 < V_2 -> V_4 &&
V_2 -> V_4 < V_2 -> V_3 &&
V_2 -> V_3 < 100 ) ;
ASSERT ( V_2 -> V_8 >= 0 &&
V_2 -> V_8 < V_2 -> V_7 &&
V_2 -> V_7 < V_2 -> V_6 &&
V_2 -> V_6 < 100 ) ;
if ( * args ) {
F_3 ( L_2 ) ;
return - V_9 ;
}
if ( ! V_2 -> V_10 ) {
F_3 ( L_3 ) ;
return - V_9 ;
}
if ( F_4 ( V_11 , & V_2 -> V_12 ) ) {
F_3 ( L_4 ) ;
return - V_13 ;
}
if ( ! V_2 -> V_14 ) {
V_2 -> V_14 = F_5 ( L_5 , V_15 ) ;
if ( ! V_2 -> V_14 )
return - V_16 ;
}
return F_6 ( V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
struct V_19 V_19 ;
struct V_20 V_21 ;
struct V_22 * V_23 , * V_24 , * V_25 ;
const struct V_26 * V_27 ;
int V_28 ;
F_2 ( L_6 ) ;
V_28 = F_7 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
F_8 ( V_2 , & V_27 ) ;
V_28 = - V_16 ;
V_18 = F_9 ( V_29 , V_15 ) ;
if ( ! V_18 )
goto V_30;
F_10 ( V_18 -> V_31 , == , NULL ) ;
F_11 ( & V_18 -> V_32 , 1 ) ;
V_18 -> type = V_33 ;
F_12 ( L_7 , V_18 ) ;
V_28 = F_13 ( V_2 -> V_10 , V_34 , & V_19 ) ;
if ( V_28 < 0 )
goto V_35;
V_2 -> V_36 = V_19 . V_36 ;
V_25 = V_19 . V_22 ;
V_28 = - V_37 ;
if ( ! V_25 -> V_38 ||
! V_25 -> V_38 -> V_39 -> V_40 ||
! V_25 -> V_38 -> V_39 -> V_41 ||
! V_25 -> V_38 -> V_39 -> V_42 ||
! V_25 -> V_38 -> V_39 -> V_43 ||
! V_25 -> V_44 -> V_45 -> V_46 ||
! V_25 -> V_44 -> V_45 -> V_47 )
goto V_48;
V_28 = - V_49 ;
if ( V_25 -> V_44 -> V_50 & V_51 )
goto V_48;
V_28 = F_14 ( V_2 , V_25 , & V_27 ) ;
if ( V_28 < 0 )
goto V_48;
V_28 = F_15 ( & V_19 , & V_21 ) ;
if ( V_28 < 0 )
goto V_48;
V_28 = - V_52 ;
if ( V_21 . V_53 <= 0 )
goto V_48;
V_28 = - V_37 ;
if ( V_21 . V_53 > V_54 )
goto V_48;
V_2 -> V_55 = V_21 . V_53 ;
V_2 -> V_56 = 0 ;
if ( V_21 . V_53 < V_54 )
V_2 -> V_56 = V_57 - F_16 ( V_21 . V_53 ) ;
F_12 ( L_8 ,
V_2 -> V_55 , V_2 -> V_56 ) ;
F_12 ( L_9 ,
( unsigned long long ) V_21 . V_58 ,
( unsigned long long ) V_21 . V_59 ) ;
F_17 ( V_21 . V_60 , 100 ) ;
V_2 -> V_61 = V_21 . V_60 * V_2 -> V_5 ;
V_2 -> V_62 = V_21 . V_60 * V_2 -> V_4 ;
V_2 -> V_63 = V_21 . V_60 * V_2 -> V_3 ;
F_12 ( L_10 ,
( unsigned long long ) V_2 -> V_63 ,
( unsigned long long ) V_2 -> V_62 ,
( unsigned long long ) V_2 -> V_61 ) ;
V_21 . V_58 >>= V_2 -> V_56 ;
F_17 ( V_21 . V_58 , 100 ) ;
V_2 -> V_64 = V_21 . V_58 * V_2 -> V_8 ;
V_2 -> V_65 = V_21 . V_58 * V_2 -> V_7 ;
V_2 -> V_66 = V_21 . V_58 * V_2 -> V_6 ;
F_12 ( L_11 ,
( unsigned long long ) V_2 -> V_66 ,
( unsigned long long ) V_2 -> V_65 ,
( unsigned long long ) V_2 -> V_64 ) ;
V_24 = F_18 ( V_2 , V_25 , L_12 ) ;
if ( F_19 ( V_24 ) ) {
V_28 = F_20 ( V_24 ) ;
goto V_48;
}
V_18 -> V_22 = V_24 ;
V_18 -> V_67 . V_68 = NULL ;
V_28 = F_21 ( V_18 ) ;
if ( V_28 < 0 )
goto V_48;
V_23 = F_18 ( V_2 , V_25 , L_13 ) ;
if ( F_19 ( V_23 ) ) {
V_28 = F_20 ( V_23 ) ;
goto V_48;
}
V_2 -> V_23 = V_23 ;
F_22 ( & V_2 -> V_2 ,
& V_69 ,
L_14 ,
V_18 -> V_22 -> V_44 -> V_70 ) ;
F_23 ( & V_18 -> V_67 , NULL , & V_2 -> V_2 ) ;
V_28 = F_24 ( & V_2 -> V_2 , & V_18 -> V_67 , V_2 -> V_14 ) ;
if ( V_28 < 0 )
goto V_71;
F_25 ( V_11 , & V_2 -> V_12 ) ;
F_26 ( V_25 ) ;
F_27 ( L_15 , V_2 -> V_2 . V_72 ) ;
F_28 ( V_2 , 0 , 0 ) ;
F_29 ( V_2 , V_27 ) ;
return 0 ;
V_71:
F_26 ( V_2 -> V_23 ) ;
V_2 -> V_23 = NULL ;
V_48:
F_30 ( V_2 -> V_36 ) ;
V_2 -> V_36 = NULL ;
F_26 ( V_18 -> V_22 ) ;
V_18 -> V_22 = NULL ;
F_26 ( V_25 ) ;
V_35:
F_31 ( V_29 , V_18 ) ;
V_30:
F_29 ( V_2 , V_27 ) ;
F_3 ( L_16 , V_28 ) ;
return V_28 ;
}
void F_32 ( struct V_1 * V_2 )
{
F_2 ( L_6 ) ;
if ( F_4 ( V_11 , & V_2 -> V_12 ) ) {
F_27 ( L_17 ,
V_2 -> V_2 . V_72 ) ;
F_33 ( & V_2 -> V_2 ) ;
}
F_26 ( V_2 -> V_23 ) ;
F_30 ( V_2 -> V_36 ) ;
F_34 ( V_2 -> V_10 ) ;
F_34 ( V_2 -> V_73 ) ;
F_34 ( V_2 -> V_14 ) ;
F_35 ( L_6 ) ;
}
