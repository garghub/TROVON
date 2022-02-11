static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 , struct V_1 , V_5 ) ;
}
static inline struct V_6 *
F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return V_7 -> V_8 ;
}
static int F_5 ( struct V_9 * V_10 ,
struct V_11 * V_12 , struct V_13 * V_14 )
{
int V_15 = F_6 ( V_14 ) / V_16 ;
int V_17 =
F_7 ( V_12 , L_1 ) ;
if ( V_15 != V_17 ) {
F_8 ( V_10 , L_2 ,
V_15 , V_17 ) ;
return - V_18 ;
} else {
return 0 ;
}
}
static int F_9 ( struct V_19 * V_20 )
{
struct V_6 * V_21 = F_10 ( V_20 ) ;
struct V_22 * V_23 ;
struct V_1 * V_7 ;
int V_24 = 0 ;
if ( ! V_21 ) {
F_8 ( & V_20 -> V_10 , L_3 , V_25 ) ;
return - V_26 ;
}
F_11 (pos, &priv->bank_list) {
V_7 = F_12 ( V_23 , struct V_1 , V_27 ) ;
V_24 = F_13 ( & V_7 -> V_5 ) ;
if ( V_24 )
F_8 ( & V_20 -> V_10 , L_4 ) ;
}
return V_24 ;
}
static int F_14 ( struct V_2 * V_3 ,
const struct V_28 * V_29 , T_1 * V_30 )
{
struct V_6 * V_21 = F_4 ( V_3 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_31 ;
if ( V_3 -> V_32 != 2 ) {
F_15 ( 1 ) ;
return - V_18 ;
}
if ( F_15 ( V_29 -> V_33 < V_3 -> V_32 ) )
return - V_18 ;
V_31 = V_29 -> args [ 0 ] - ( V_3 -> V_34 - V_21 -> V_35 ) ;
if ( V_31 >= V_3 -> V_36 )
return - V_18 ;
if ( F_16 ( V_31 >= V_7 -> V_37 ) ) {
F_17 ( & V_21 -> V_20 -> V_10 ,
L_5 ,
V_29 -> args [ 0 ] ) ;
}
if ( V_30 )
* V_30 = V_29 -> args [ 1 ] ;
return V_31 ;
}
static int F_18 ( struct V_19 * V_20 )
{
struct V_9 * V_10 = & V_20 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_38 ;
void T_2 * V_39 ;
struct V_6 * V_21 ;
struct V_13 * V_14 ;
struct V_40 * V_41 ;
const T_3 * V_42 ;
T_1 V_43 ;
int V_44 ;
static int V_35 ;
V_21 = F_19 ( V_10 , sizeof( * V_21 ) , V_45 ) ;
if ( ! V_21 )
return - V_46 ;
F_20 ( V_20 , V_21 ) ;
F_21 ( & V_21 -> V_47 ) ;
V_14 = F_22 ( V_20 , V_48 , 0 ) ;
V_39 = F_23 ( V_10 , V_14 ) ;
if ( F_24 ( V_39 ) )
return F_25 ( V_39 ) ;
V_21 -> V_35 = V_35 ;
V_21 -> V_39 = V_39 ;
V_21 -> V_20 = V_20 ;
if ( F_5 ( V_10 , V_12 , V_14 ) )
return - V_18 ;
F_26 (np, L_1 , prop, p,
bank_width) {
struct V_1 * V_7 ;
struct V_4 * V_5 ;
struct V_2 * V_3 ;
V_7 = F_19 ( V_10 , sizeof( * V_7 ) , V_45 ) ;
if ( ! V_7 ) {
V_44 = - V_46 ;
goto V_49;
}
V_7 -> V_8 = V_21 ;
V_7 -> V_50 = V_21 -> V_17 ;
if ( V_43 <= 0 || V_43 > V_51 ) {
F_8 ( V_10 , L_6 , V_43 ) ;
goto V_49;
} else {
V_7 -> V_37 = V_43 ;
}
V_5 = & V_7 -> V_5 ;
V_44 = F_27 ( V_5 , V_10 , 4 ,
V_39 + F_28 ( V_7 -> V_50 ) ,
NULL , NULL , NULL ,
V_39 + F_29 ( V_7 -> V_50 ) , 0 ) ;
if ( V_44 ) {
F_8 ( V_10 , L_7 ) ;
goto V_49;
}
V_3 = & V_5 -> V_3 ;
V_3 -> V_38 = V_12 ;
V_3 -> V_52 = V_53 ;
V_3 -> V_54 = V_12 -> V_55 ;
V_3 -> V_34 = V_35 ;
V_3 -> V_32 = 2 ;
V_3 -> V_56 = F_14 ;
V_3 -> V_36 = V_51 ;
V_44 = F_30 ( V_3 ) ;
if ( V_44 ) {
F_8 ( V_10 , L_8 ,
V_7 -> V_50 ) ;
goto V_49;
}
V_35 += V_3 -> V_36 ;
F_31 ( V_10 , L_9 , V_7 -> V_50 ,
V_3 -> V_34 , V_3 -> V_36 , V_7 -> V_37 ) ;
F_32 ( & V_7 -> V_27 , & V_21 -> V_47 ) ;
V_21 -> V_17 ++ ;
}
F_33 ( V_10 , L_10 ,
V_21 -> V_17 , V_21 -> V_35 , V_35 - 1 ) ;
return 0 ;
V_49:
( void ) F_9 ( V_20 ) ;
return V_44 ;
}
