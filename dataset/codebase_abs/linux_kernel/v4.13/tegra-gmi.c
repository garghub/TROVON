static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_5 , L_1 , V_3 ) ;
return V_3 ;
}
F_4 ( V_2 -> V_6 ) ;
F_5 ( 2000 , 4000 ) ;
F_6 ( V_2 -> V_6 ) ;
F_7 ( V_2 -> V_7 , V_2 -> V_8 + V_9 ) ;
F_7 ( V_2 -> V_10 , V_2 -> V_8 + V_11 ) ;
V_2 -> V_12 |= V_13 ;
F_7 ( V_2 -> V_12 , V_2 -> V_8 + V_14 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
T_1 V_15 ;
V_15 = F_9 ( V_2 -> V_8 + V_14 ) ;
V_15 &= ~ V_13 ;
F_7 ( V_15 , V_2 -> V_8 + V_14 ) ;
F_4 ( V_2 -> V_6 ) ;
F_10 ( V_2 -> V_4 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
T_1 V_18 , V_19 [ 4 ] ;
int V_3 ;
V_17 = F_12 ( V_2 -> V_5 -> V_20 , NULL ) ;
if ( ! V_17 ) {
F_3 ( V_2 -> V_5 , L_2 ) ;
return - V_21 ;
}
if ( F_13 ( V_2 -> V_5 -> V_20 ) > 1 )
F_14 ( V_2 -> V_5 , L_3 ) ;
if ( F_15 ( V_17 , L_4 ) )
V_2 -> V_12 |= V_22 ;
if ( F_15 ( V_17 , L_5 ) )
V_2 -> V_12 |= V_23 ;
if ( F_15 ( V_17 , L_6 ) )
V_2 -> V_12 |= V_24 ;
if ( F_15 ( V_17 , L_7 ) )
V_2 -> V_12 |= V_25 ;
if ( F_15 ( V_17 , L_8 ) )
V_2 -> V_12 |= V_26 ;
if ( F_15 ( V_17 , L_9 ) )
V_2 -> V_12 |= V_27 ;
if ( F_15 ( V_17 , L_10 ) )
V_2 -> V_12 |= V_28 ;
V_3 = F_16 ( V_17 , L_11 , V_19 , 4 ) ;
if ( V_3 < 0 ) {
if ( V_3 == - V_29 ) {
F_3 ( V_2 -> V_5 ,
L_12 ) ;
goto V_30;
}
V_3 = F_17 ( V_17 , L_13 , & V_18 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_5 ,
L_14 ) ;
goto V_30;
}
} else {
V_18 = V_19 [ 1 ] ;
}
if ( V_18 >= V_31 ) {
F_3 ( V_2 -> V_5 , L_15 , V_18 ) ;
V_3 = - V_32 ;
goto V_30;
}
V_2 -> V_12 |= F_18 ( V_18 ) ;
if ( ! F_17 ( V_17 , L_16 , & V_18 ) )
V_2 -> V_7 |= F_19 ( V_18 ) ;
else
V_2 -> V_7 |= F_19 ( 1 ) ;
if ( ! F_17 ( V_17 , L_17 , & V_18 ) )
V_2 -> V_7 |= F_20 ( V_18 ) ;
else
V_2 -> V_7 |= F_20 ( 1 ) ;
if ( ! F_17 ( V_17 , L_18 , & V_18 ) )
V_2 -> V_7 |= F_21 ( V_18 ) ;
else
V_2 -> V_7 |= F_21 ( 1 ) ;
if ( ! F_17 ( V_17 , L_19 , & V_18 ) )
V_2 -> V_7 |= F_22 ( V_18 ) ;
else
V_2 -> V_7 |= F_22 ( 4 ) ;
if ( ! F_17 ( V_17 , L_20 , & V_18 ) )
V_2 -> V_10 |= F_23 ( V_18 ) ;
else
V_2 -> V_10 |= F_23 ( 1 ) ;
if ( ! F_17 ( V_17 , L_21 , & V_18 ) )
V_2 -> V_10 |= F_24 ( V_18 ) ;
else
V_2 -> V_10 |= F_24 ( 1 ) ;
if ( ! F_17 ( V_17 , L_22 , & V_18 ) )
V_2 -> V_10 |= F_25 ( V_18 ) ;
else
V_2 -> V_10 |= F_25 ( 3 ) ;
V_30:
F_26 ( V_17 ) ;
return V_3 ;
}
static int F_27 ( struct V_33 * V_34 )
{
struct V_35 * V_5 = & V_34 -> V_5 ;
struct V_1 * V_2 ;
struct V_36 * V_37 ;
int V_3 ;
V_2 = F_28 ( V_5 , sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 )
return - V_39 ;
V_2 -> V_5 = V_5 ;
V_37 = F_29 ( V_34 , V_40 , 0 ) ;
V_2 -> V_8 = F_30 ( V_5 , V_37 ) ;
if ( F_31 ( V_2 -> V_8 ) )
return F_32 ( V_2 -> V_8 ) ;
V_2 -> V_4 = F_33 ( V_5 , L_23 ) ;
if ( F_31 ( V_2 -> V_4 ) ) {
F_3 ( V_5 , L_24 ) ;
return F_32 ( V_2 -> V_4 ) ;
}
V_2 -> V_6 = F_34 ( V_5 , L_23 ) ;
if ( F_31 ( V_2 -> V_6 ) ) {
F_3 ( V_5 , L_25 ) ;
return F_32 ( V_2 -> V_6 ) ;
}
V_3 = F_11 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_35 ( V_5 -> V_20 , NULL , V_5 ) ;
if ( V_3 < 0 ) {
F_3 ( V_5 , L_26 ) ;
F_8 ( V_2 ) ;
return V_3 ;
}
F_36 ( V_34 , V_2 ) ;
return 0 ;
}
static int F_37 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_38 ( V_34 ) ;
F_39 ( V_2 -> V_5 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
