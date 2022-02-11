static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( F_3 ( V_2 ) ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
int V_7 ;
V_7 = F_5 ( F_3 ( V_2 ) ) ;
if ( V_7 < 0 ) {
F_6 ( V_4 , L_1 , V_2 -> V_5 . V_8 ) ;
F_7 ( V_2 ) ;
}
return V_7 ;
}
static int F_8 ( struct V_9 * V_10 )
{
const struct V_11 * V_12 = & V_13 ;
struct V_3 * V_4 = & V_10 -> V_4 ;
struct V_14 * V_15 , * V_16 ;
int V_17 , V_18 ;
struct V_1 * V_2 = NULL ;
V_18 = V_17 = F_9 ( V_10 , 0 ) ;
if ( V_17 < 0 )
goto V_19;
V_16 = F_10 ( V_10 , V_20 , 1 ) ;
if ( V_16 == NULL ) {
F_6 ( V_4 , L_2 ) ;
V_17 = - V_21 ;
goto V_19;
}
if ( ! F_11 ( V_16 -> V_22 , V_16 -> V_23 - V_16 -> V_22 + 1 ,
V_10 -> V_24 ) ) {
F_6 ( V_4 , L_3 ) ;
V_17 = - V_25 ;
goto V_19;
}
if ( ! F_12 ( V_4 , V_16 -> V_22 ,
V_16 -> V_22 - V_16 -> V_26 -> V_22 ,
( V_16 -> V_23 - V_16 -> V_22 ) + 1 ,
V_27 |
V_28 ) ) {
F_6 ( V_4 , L_4 ) ;
V_17 = - V_29 ;
goto V_30;
}
V_15 = F_10 ( V_10 , V_20 , 0 ) ;
if ( V_15 == NULL ) {
F_6 ( V_4 , L_5 ) ;
V_17 = - V_21 ;
goto V_31;
}
V_2 = F_13 ( V_12 , & V_10 -> V_4 , F_14 ( & V_10 -> V_4 ) ) ;
if ( ! V_2 ) {
V_17 = - V_32 ;
goto V_31;
}
V_2 -> V_33 = V_15 -> V_22 ;
V_2 -> V_34 = V_15 -> V_23 - V_15 -> V_22 + 1 ;
if ( ! F_11 ( V_2 -> V_33 , V_2 -> V_34 , V_10 -> V_24 ) ) {
F_6 ( V_4 , L_3 ) ;
V_17 = - V_25 ;
goto V_35;
}
V_2 -> V_36 = F_15 ( V_2 -> V_33 , V_2 -> V_34 ) ;
if ( V_2 -> V_36 == NULL ) {
F_6 ( V_4 , L_6 ) ;
V_17 = - V_29 ;
goto V_37;
}
F_16 ( F_3 ( V_2 ) ) ;
V_17 = F_17 ( V_2 , V_18 , V_38 | V_39 ) ;
if ( V_17 )
goto V_40;
F_18 ( V_4 -> V_26 , V_41 , 1 ) ;
F_19 ( V_4 -> V_26 , V_42 , 1 << 6 , 0 ) ;
return 0 ;
V_40:
F_20 ( V_2 -> V_36 ) ;
V_37:
F_21 ( V_2 -> V_33 , V_2 -> V_34 ) ;
V_35:
F_22 ( V_2 ) ;
V_31:
F_23 ( V_4 ) ;
V_30:
F_21 ( V_16 -> V_22 , V_16 -> V_23 - V_16 -> V_22 + 1 ) ;
V_19:
return V_17 ;
}
static int F_24 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_25 ( V_10 ) ;
struct V_14 * V_16 ;
F_26 ( V_2 ) ;
F_21 ( V_2 -> V_33 , V_2 -> V_34 ) ;
F_22 ( V_2 ) ;
F_23 ( & V_10 -> V_4 ) ;
V_16 = F_10 ( V_10 , V_20 , 1 ) ;
if ( V_16 )
F_21 ( V_16 -> V_22 , V_16 -> V_23 - V_16 -> V_22 + 1 ) ;
F_19 ( V_10 -> V_4 . V_26 , V_42 , 0 , 1 << 6 ) ;
F_18 ( V_10 -> V_4 . V_26 , V_41 , 0 ) ;
F_27 ( V_10 , NULL ) ;
return 0 ;
}
static int F_28 ( struct V_9 * V_10 , T_1 V_43 )
{
struct V_3 * V_4 = & V_10 -> V_4 ;
struct V_44 * V_45 = F_3 ( F_25 ( V_10 ) ) ;
if ( F_29 ( V_46 , V_45 -> V_47 ) )
F_30 ( 5 ) ;
V_45 -> V_47 = V_46 ;
F_18 ( V_4 -> V_26 , V_41 , 0 ) ;
F_31 ( V_45 ) -> V_48 = V_49 ;
return 0 ;
}
static int F_32 ( struct V_9 * V_10 )
{
struct V_3 * V_4 = & V_10 -> V_4 ;
struct V_1 * V_2 = F_25 ( V_10 ) ;
struct V_44 * V_45 = F_3 ( V_2 ) ;
if ( F_29 ( V_46 , V_45 -> V_47 ) )
F_30 ( 5 ) ;
V_45 -> V_47 = V_46 ;
F_18 ( V_4 -> V_26 , V_41 , 1 ) ;
F_33 ( V_2 ) ;
return 0 ;
}
