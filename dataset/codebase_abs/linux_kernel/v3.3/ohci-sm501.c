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
if ( ! F_11 ( V_16 -> V_22 , F_12 ( V_16 ) , V_10 -> V_23 ) ) {
F_6 ( V_4 , L_3 ) ;
V_17 = - V_24 ;
goto V_19;
}
if ( ! F_13 ( V_4 , V_16 -> V_22 ,
V_16 -> V_22 - V_16 -> V_25 -> V_22 ,
F_12 ( V_16 ) ,
V_26 |
V_27 ) ) {
F_6 ( V_4 , L_4 ) ;
V_17 = - V_28 ;
goto V_29;
}
V_15 = F_10 ( V_10 , V_20 , 0 ) ;
if ( V_15 == NULL ) {
F_6 ( V_4 , L_5 ) ;
V_17 = - V_21 ;
goto V_30;
}
V_2 = F_14 ( V_12 , & V_10 -> V_4 , F_15 ( & V_10 -> V_4 ) ) ;
if ( ! V_2 ) {
V_17 = - V_31 ;
goto V_30;
}
V_2 -> V_32 = V_15 -> V_22 ;
V_2 -> V_33 = F_12 ( V_15 ) ;
if ( ! F_11 ( V_2 -> V_32 , V_2 -> V_33 , V_10 -> V_23 ) ) {
F_6 ( V_4 , L_3 ) ;
V_17 = - V_24 ;
goto V_34;
}
V_2 -> V_35 = F_16 ( V_2 -> V_32 , V_2 -> V_33 ) ;
if ( V_2 -> V_35 == NULL ) {
F_6 ( V_4 , L_6 ) ;
V_17 = - V_28 ;
goto V_36;
}
F_17 ( F_3 ( V_2 ) ) ;
V_17 = F_18 ( V_2 , V_18 , V_37 ) ;
if ( V_17 )
goto V_38;
F_19 ( V_4 -> V_25 , V_39 , 1 ) ;
F_20 ( V_4 -> V_25 , V_40 , 1 << 6 , 0 ) ;
return 0 ;
V_38:
F_21 ( V_2 -> V_35 ) ;
V_36:
F_22 ( V_2 -> V_32 , V_2 -> V_33 ) ;
V_34:
F_23 ( V_2 ) ;
V_30:
F_24 ( V_4 ) ;
V_29:
F_22 ( V_16 -> V_22 , F_12 ( V_16 ) ) ;
V_19:
return V_17 ;
}
static int F_25 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_26 ( V_10 ) ;
struct V_14 * V_16 ;
F_27 ( V_2 ) ;
F_22 ( V_2 -> V_32 , V_2 -> V_33 ) ;
F_23 ( V_2 ) ;
F_24 ( & V_10 -> V_4 ) ;
V_16 = F_10 ( V_10 , V_20 , 1 ) ;
if ( V_16 )
F_22 ( V_16 -> V_22 , F_12 ( V_16 ) ) ;
F_20 ( V_10 -> V_4 . V_25 , V_40 , 0 , 1 << 6 ) ;
F_19 ( V_10 -> V_4 . V_25 , V_39 , 0 ) ;
F_28 ( V_10 , NULL ) ;
return 0 ;
}
static int F_29 ( struct V_9 * V_10 , T_1 V_41 )
{
struct V_3 * V_4 = & V_10 -> V_4 ;
struct V_42 * V_43 = F_3 ( F_26 ( V_10 ) ) ;
if ( F_30 ( V_44 , V_43 -> V_45 ) )
F_31 ( 5 ) ;
V_43 -> V_45 = V_44 ;
F_19 ( V_4 -> V_25 , V_39 , 0 ) ;
return 0 ;
}
static int F_32 ( struct V_9 * V_10 )
{
struct V_3 * V_4 = & V_10 -> V_4 ;
struct V_1 * V_2 = F_26 ( V_10 ) ;
struct V_42 * V_43 = F_3 ( V_2 ) ;
if ( F_30 ( V_44 , V_43 -> V_45 ) )
F_31 ( 5 ) ;
V_43 -> V_45 = V_44 ;
F_19 ( V_4 -> V_25 , V_39 , 1 ) ;
F_33 ( V_2 ) ;
return 0 ;
}
