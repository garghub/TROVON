static int F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 ) {
int V_4 ;
V_4 = F_2 ( & V_2 -> V_5 -> V_6 , V_2 -> V_7 ,
F_3 ( & V_2 -> V_5 -> V_6 ) ) ;
if ( V_4 )
return V_4 ;
V_2 -> V_3 = V_2 ;
}
F_4 ( V_2 -> V_7 , ! ( V_2 -> V_8 & V_9 ) ) ;
return 0 ;
}
static int F_5 ( struct V_10 * V_5 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = F_6 ( V_5 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
return F_7 ( V_14 -> V_15 , V_16 , V_17 ,
( V_2 -> V_8 & V_18 ) ?
V_17 : 0 ) ;
}
static int F_8 ( struct V_10 * V_5 ,
struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_13 * V_14 = F_6 ( V_5 ) ;
T_1 V_21 ;
F_9 ( V_14 -> V_22 , V_20 -> V_23 ? : V_2 -> V_24 ) ;
V_14 -> V_25 = V_20 -> V_25 ;
V_14 -> V_26 = V_20 -> V_27 ;
V_14 -> V_28 = ( T_1 * ) V_20 -> V_28 ;
V_14 -> V_29 = ( T_1 * ) V_20 -> V_29 ;
V_21 = V_14 -> V_28 ? * V_14 -> V_28 ++ : 0 ;
F_10 ( V_21 | F_11 ( V_14 -> V_26 ) | V_30 , V_14 -> V_31 ) ;
return 1 ;
}
static T_2 F_12 ( int V_32 , void * V_33 )
{
struct V_10 * V_5 = V_33 ;
struct V_13 * V_14 = F_6 ( V_5 ) ;
T_1 V_21 ;
V_21 = F_13 ( V_14 -> V_31 ) ;
if ( V_14 -> V_29 )
* V_14 -> V_29 ++ = V_21 ;
if ( -- V_14 -> V_25 > 0 ) {
V_21 = V_14 -> V_28 ? * V_14 -> V_28 ++ : 0 ;
F_10 ( V_21 | F_11 ( V_14 -> V_26 ) | V_30 ,
V_14 -> V_31 ) ;
} else
F_14 ( V_5 ) ;
return V_34 ;
}
static int F_15 ( struct V_35 * V_36 )
{
struct V_13 * V_14 ;
struct V_10 * V_5 ;
struct V_37 * V_38 ;
int V_32 , V_4 ;
V_32 = F_16 ( V_36 , 0 ) ;
if ( V_32 < 0 )
return V_32 ;
V_5 = F_17 ( & V_36 -> V_6 , sizeof( * V_14 ) ) ;
if ( ! V_5 )
return - V_39 ;
V_5 -> V_40 = - 1 ;
V_5 -> V_41 = V_18 | V_9 ;
V_5 -> V_42 = F_18 ( 1 , 8 ) ;
V_5 -> V_6 . V_43 = V_36 -> V_6 . V_43 ;
V_5 -> V_44 = F_1 ;
V_5 -> V_45 = F_5 ;
V_5 -> V_46 = F_8 ;
V_14 = F_6 ( V_5 ) ;
V_14 -> V_22 = F_19 ( & V_36 -> V_6 , NULL ) ;
if ( F_20 ( V_14 -> V_22 ) ) {
V_4 = F_21 ( V_14 -> V_22 ) ;
goto V_47;
}
V_14 -> V_15 =
F_22 ( L_1 ) ;
if ( F_20 ( V_14 -> V_15 ) ) {
V_4 = F_21 ( V_14 -> V_15 ) ;
goto V_47;
}
V_38 = F_23 ( V_36 , V_48 , 0 ) ;
V_14 -> V_31 = F_24 ( & V_36 -> V_6 , V_38 ) ;
if ( F_20 ( V_14 -> V_31 ) ) {
V_4 = F_21 ( V_14 -> V_31 ) ;
goto V_47;
}
F_7 ( V_14 -> V_15 , V_16 , V_49 , 0 ) ;
F_25 ( V_14 -> V_31 ) ;
V_4 = F_26 ( & V_36 -> V_6 , V_32 , F_12 , 0 ,
F_3 ( & V_36 -> V_6 ) , V_5 ) ;
if ( V_4 )
goto V_47;
V_4 = F_27 ( & V_36 -> V_6 , V_5 ) ;
if ( ! V_4 )
return 0 ;
V_47:
F_28 ( V_5 ) ;
return V_4 ;
}
