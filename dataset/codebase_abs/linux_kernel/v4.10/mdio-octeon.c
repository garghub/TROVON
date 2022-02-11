static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_5 ;
struct V_6 * V_7 ;
T_1 V_8 ;
T_1 V_9 ;
union V_10 V_11 ;
int V_12 = - V_13 ;
V_5 = F_2 ( & V_2 -> V_14 , sizeof( * V_4 ) ) ;
if ( ! V_5 )
return - V_15 ;
V_7 = F_3 ( V_2 , V_16 , 0 ) ;
if ( V_7 == NULL ) {
F_4 ( & V_2 -> V_14 , L_1 ) ;
return - V_17 ;
}
V_4 = V_5 -> V_18 ;
V_4 -> V_5 = V_5 ;
V_8 = V_7 -> V_19 ;
V_9 = F_5 ( V_7 ) ;
if ( ! F_6 ( & V_2 -> V_14 , V_8 , V_9 ,
V_7 -> V_20 ) ) {
F_4 ( & V_2 -> V_14 , L_2 ) ;
return - V_17 ;
}
V_4 -> V_21 =
( V_22 ) F_7 ( & V_2 -> V_14 , V_8 , V_9 ) ;
if ( ! V_4 -> V_21 ) {
F_4 ( & V_2 -> V_14 , L_3 ) ;
return - V_15 ;
}
V_11 . V_22 = 0 ;
V_11 . V_23 . V_24 = 1 ;
F_8 ( V_11 . V_22 , V_4 -> V_21 + V_25 ) ;
V_4 -> V_5 -> V_20 = V_26 ;
snprintf ( V_4 -> V_5 -> V_27 , V_28 , L_4 , V_4 -> V_21 ) ;
V_4 -> V_5 -> V_29 = & V_2 -> V_14 ;
V_4 -> V_5 -> V_30 = V_31 ;
V_4 -> V_5 -> V_32 = V_33 ;
F_9 ( V_2 , V_4 ) ;
V_12 = F_10 ( V_4 -> V_5 , V_2 -> V_14 . V_34 ) ;
if ( V_12 )
goto V_35;
F_11 ( & V_2 -> V_14 , L_5 ) ;
return 0 ;
V_35:
F_12 ( V_4 -> V_5 ) ;
V_11 . V_22 = 0 ;
F_8 ( V_11 . V_22 , V_4 -> V_21 + V_25 ) ;
return V_12 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
union V_10 V_11 ;
V_4 = F_14 ( V_2 ) ;
F_15 ( V_4 -> V_5 ) ;
F_12 ( V_4 -> V_5 ) ;
V_11 . V_22 = 0 ;
F_8 ( V_11 . V_22 , V_4 -> V_21 + V_25 ) ;
return 0 ;
}
void F_16 ( void )
{
}
