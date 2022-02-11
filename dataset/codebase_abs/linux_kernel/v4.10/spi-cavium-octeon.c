static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
void T_1 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_10 = - V_11 ;
V_7 = F_2 ( & V_2 -> V_12 , sizeof( struct V_8 ) ) ;
if ( ! V_7 )
return - V_13 ;
V_9 = F_3 ( V_7 ) ;
F_4 ( V_2 , V_7 ) ;
V_4 = F_5 ( V_2 , V_14 , 0 ) ;
V_5 = F_6 ( & V_2 -> V_12 , V_4 ) ;
if ( F_7 ( V_5 ) ) {
V_10 = F_8 ( V_5 ) ;
goto V_15;
}
V_9 -> V_16 = V_5 ;
V_9 -> V_17 = F_9 () ;
V_9 -> V_18 . V_19 = 0 ;
V_9 -> V_18 . V_20 = 0x08 ;
V_9 -> V_18 . V_21 = 0x10 ;
V_9 -> V_18 . V_22 = 0x80 ;
V_7 -> V_23 = 4 ;
V_7 -> V_24 = V_25 |
V_26 |
V_27 |
V_28 |
V_29 ;
V_7 -> V_30 = V_31 ;
V_7 -> V_32 = F_10 ( 8 ) ;
V_7 -> V_33 = V_34 ;
V_7 -> V_12 . V_35 = V_2 -> V_12 . V_35 ;
V_10 = F_11 ( & V_2 -> V_12 , V_7 ) ;
if ( V_10 ) {
F_12 ( & V_2 -> V_12 , L_1 , V_10 ) ;
goto V_15;
}
F_13 ( & V_2 -> V_12 , L_2 ) ;
return 0 ;
V_15:
F_14 ( V_7 ) ;
return V_10 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_16 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_17 ( 0 , V_9 -> V_16 + F_18 ( V_9 ) ) ;
return 0 ;
}
