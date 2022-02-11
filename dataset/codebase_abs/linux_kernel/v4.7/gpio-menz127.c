static int F_1 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_10 ;
T_1 V_11 , V_12 ;
if ( ! F_3 ( V_4 ) ) {
F_4 ( V_8 , L_1 , V_4 ) ;
return - V_13 ;
}
if ( V_4 > 0 ) {
V_10 = F_5 ( V_4 ) - 1 ;
if ( V_10 && ( V_4 & F_6 ( V_10 - 1 ) ) )
V_4 = F_7 ( V_4 , V_14 ) ;
else
V_4 = F_8 ( V_4 , V_14 ) ;
if ( V_4 > V_15 )
V_4 = V_15 ;
V_4 /= 50 ;
}
F_9 ( & V_2 -> V_16 ) ;
V_11 = F_10 ( V_6 -> V_17 + V_18 ) ;
if ( V_4 == 0 ) {
V_11 &= ~ F_6 ( V_3 ) ;
V_12 = 0 ;
} else {
V_11 |= F_6 ( V_3 ) ;
V_12 = V_4 ;
}
F_11 ( V_11 , V_6 -> V_17 + V_18 ) ;
F_11 ( V_12 , V_6 -> V_17 + F_12 ( V_3 ) ) ;
F_13 ( & V_2 -> V_16 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned V_19 ,
enum V_20 V_21 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_22 ;
if ( V_21 != V_23 &&
V_21 != V_24 )
return - V_25 ;
F_9 ( & V_2 -> V_16 ) ;
V_22 = F_10 ( V_6 -> V_17 + V_26 ) ;
if ( V_21 == V_23 )
V_22 |= F_6 ( V_19 ) ;
else
V_22 &= ~ F_6 ( V_19 ) ;
F_11 ( V_22 , V_6 -> V_17 + V_26 ) ;
F_13 ( & V_2 -> V_16 ) ;
return 0 ;
}
static int F_15 ( struct V_27 * V_28 ,
const struct V_29 * V_30 )
{
struct V_5 * V_5 ;
struct V_7 * V_8 = & V_28 -> V_8 ;
int V_31 ;
V_5 = F_16 ( V_8 , sizeof( struct V_5 ) ,
V_32 ) ;
if ( ! V_5 )
return - V_33 ;
V_5 -> V_34 = F_17 ( V_28 , F_18 ( V_8 ) ) ;
if ( F_19 ( V_5 -> V_34 ) ) {
F_4 ( V_8 , L_2 ) ;
return F_20 ( V_5 -> V_34 ) ;
}
V_5 -> V_17 = F_21 ( V_5 -> V_34 -> V_35 ,
F_22 ( V_5 -> V_34 ) ) ;
if ( V_5 -> V_17 == NULL ) {
V_31 = - V_36 ;
goto V_37;
}
F_23 ( V_28 , V_5 ) ;
V_31 = F_24 ( & V_5 -> V_2 , & V_28 -> V_8 , 4 ,
V_5 -> V_17 + V_38 ,
V_5 -> V_17 + V_39 ,
NULL ,
V_5 -> V_17 + V_40 ,
NULL , 0 ) ;
if ( V_31 )
goto V_41;
V_5 -> V_2 . V_42 = F_1 ;
V_5 -> V_2 . V_43 = F_14 ;
V_31 = F_25 ( & V_5 -> V_2 , V_5 ) ;
if ( V_31 ) {
F_4 ( V_8 , L_3 ) ;
goto V_41;
}
F_26 ( V_8 , L_4 ) ;
return 0 ;
V_41:
F_27 ( V_5 -> V_17 ) ;
V_37:
F_28 ( V_5 -> V_34 ) ;
return V_31 ;
}
static void F_29 ( struct V_27 * V_28 )
{
struct V_5 * V_5 = F_30 ( V_28 ) ;
F_31 ( & V_5 -> V_2 ) ;
F_27 ( V_5 -> V_17 ) ;
F_28 ( V_5 -> V_34 ) ;
}
