static int F_1 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_9 -> V_8 ;
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
static int F_14 ( struct V_1 * V_2 , unsigned V_19 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_20 ;
if ( V_19 >= V_2 -> V_21 )
return - V_13 ;
F_9 ( & V_2 -> V_16 ) ;
V_20 = F_10 ( V_6 -> V_17 + V_22 ) ;
if ( F_15 ( V_2 , V_19 ) )
V_20 |= F_6 ( V_19 ) ;
else
V_20 &= ~ F_6 ( V_19 ) ;
F_11 ( V_20 , V_6 -> V_17 + V_22 ) ;
F_13 ( & V_2 -> V_16 ) ;
return 0 ;
}
static int F_16 ( struct V_23 * V_9 ,
const struct V_24 * V_25 )
{
struct V_5 * V_5 ;
struct V_7 * V_8 = & V_9 -> V_8 ;
int V_26 ;
V_5 = F_17 ( V_8 , sizeof( struct V_5 ) ,
V_27 ) ;
if ( ! V_5 )
return - V_28 ;
V_5 -> V_29 = F_18 ( V_9 , F_19 ( V_8 ) ) ;
if ( F_20 ( V_5 -> V_29 ) ) {
F_4 ( V_8 , L_2 ) ;
return F_21 ( V_5 -> V_29 ) ;
}
V_5 -> V_17 = F_22 ( V_5 -> V_29 -> V_30 ,
F_23 ( V_5 -> V_29 ) ) ;
if ( V_5 -> V_17 == NULL ) {
V_26 = - V_31 ;
goto V_32;
}
V_5 -> V_9 = V_9 ;
F_24 ( V_9 , V_5 ) ;
V_26 = F_25 ( & V_5 -> V_2 , & V_9 -> V_8 , 4 ,
V_5 -> V_17 + V_33 ,
V_5 -> V_17 + V_34 ,
NULL ,
V_5 -> V_17 + V_35 ,
NULL , 0 ) ;
if ( V_26 )
goto V_36;
V_5 -> V_2 . V_37 = F_1 ;
V_5 -> V_2 . V_38 = F_14 ;
V_26 = F_26 ( & V_5 -> V_2 , V_5 ) ;
if ( V_26 ) {
F_4 ( V_8 , L_3 ) ;
goto V_36;
}
F_27 ( V_8 , L_4 ) ;
return 0 ;
V_36:
F_28 ( V_5 -> V_17 ) ;
V_32:
F_29 ( V_5 -> V_29 ) ;
return V_26 ;
}
static void F_30 ( struct V_23 * V_9 )
{
struct V_5 * V_5 = F_31 ( V_9 ) ;
F_32 ( & V_5 -> V_2 ) ;
F_28 ( V_5 -> V_17 ) ;
F_29 ( V_5 -> V_29 ) ;
}
