static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
int V_5 ;
T_1 V_6 , V_7 ;
unsigned long V_8 , V_9 ;
struct V_10 * V_11 ;
V_11 = F_2 ( & V_2 -> V_2 , sizeof( * V_11 ) , V_12 ) ;
if ( ! V_11 )
return - V_13 ;
V_5 = F_3 ( V_2 ) ;
if ( V_5 ) {
F_4 ( & V_2 -> V_2 , L_1 ) ;
return V_5 ;
}
if ( V_4 -> V_14 == V_15 ) {
V_7 = F_5 ( V_2 , 0 ) ;
V_9 = F_6 ( V_2 , 1 ) ;
V_6 = F_5 ( V_2 , 1 ) ;
V_8 = F_6 ( V_2 , 1 ) ;
} else {
V_6 = F_5 ( V_2 , 0 ) ;
V_8 = F_6 ( V_2 , 0 ) ;
V_7 = F_5 ( V_2 , 1 ) ;
V_9 = F_6 ( V_2 , 1 ) ;
if ( ! V_9 ) {
V_7 = V_6 + V_8 ;
V_9 = V_8 ;
}
}
F_7 ( V_2 ) ;
V_11 -> V_2 = & V_2 -> V_2 ;
V_11 -> V_16 = V_2 -> V_16 ;
V_11 -> V_17 = & V_18 ;
V_11 -> V_19 . V_20 . V_21 |= V_22 ;
V_11 -> V_23 = 200000000 ;
V_5 = F_8 ( V_2 , V_24 ) ;
if ( V_5 ) {
F_4 ( & V_2 -> V_2 , L_2 ) ;
return V_5 ;
}
V_11 -> V_25 = F_9 ( V_6 , V_8 ) ;
if ( ! V_11 -> V_25 ) {
F_4 ( & V_2 -> V_2 , L_3 ) ;
return - V_13 ;
}
V_11 -> V_26 = F_9 ( V_7 , V_9 ) ;
if ( ! V_11 -> V_26 ) {
F_4 ( & V_2 -> V_2 , L_4 ) ;
V_5 = - V_13 ;
goto V_27;
}
V_5 = F_10 ( V_11 ) ;
if ( V_5 )
goto V_28;
F_11 ( V_2 , V_11 ) ;
return 0 ;
V_28:
F_12 ( V_11 -> V_26 ) ;
V_27:
F_12 ( V_11 -> V_25 ) ;
return V_5 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_14 ( V_2 ) ;
F_15 ( V_11 ) ;
F_12 ( V_11 -> V_25 ) ;
F_12 ( V_11 -> V_26 ) ;
}
