int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_8 )
{
struct V_9 * exp ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_3 ( V_2 ) ;
struct V_14 * V_15 ;
struct V_16 * V_17 = F_4 ( V_5 ) ;
T_1 V_18 = 0 ;
if ( V_2 -> V_19 == NULL )
goto V_20;
if ( V_13 == NULL || ! ( V_13 -> V_21 & V_22 ) )
goto V_20;
if ( F_5 ( V_7 ) != V_23 )
goto V_20;
F_6 () ;
V_15 = F_7 ( V_13 -> V_24 . V_25 ) ;
if ( V_15 != NULL ) {
F_8 (in_dev) {
if ( V_26 -> V_27 == V_11 -> V_28 ) {
V_18 = V_26 -> V_29 ;
break;
}
} F_9 ( V_15 ) ;
}
F_10 () ;
if ( V_18 == 0 )
goto V_20;
exp = F_11 ( V_5 ) ;
if ( exp == NULL )
goto V_20;
exp -> V_30 = V_5 -> V_31 [ V_32 ] . V_30 ;
exp -> V_30 . V_33 . V_34 . V_35 . V_36 = V_17 -> V_37 -> V_30 . V_33 . V_34 . V_35 . V_36 ;
exp -> V_18 . V_33 . V_38 . V_39 = V_18 ;
exp -> V_18 . V_33 . V_34 . V_35 . V_36 = F_12 ( 0xFFFF ) ;
exp -> V_40 = NULL ;
exp -> V_41 = V_42 ;
exp -> V_43 = V_44 ;
exp -> V_37 = NULL ;
F_13 ( exp ) ;
F_14 ( exp ) ;
F_15 ( V_5 , V_2 , V_8 * V_45 ) ;
V_20:
return V_46 ;
}
