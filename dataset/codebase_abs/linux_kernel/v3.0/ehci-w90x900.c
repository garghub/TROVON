static int T_1 F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 = 0 , V_12 ;
unsigned long V_13 ;
V_10 = F_2 ( V_4 , V_14 , 0 ) ;
if ( ! V_10 ) {
V_11 = - V_15 ;
goto V_16;
}
V_6 = F_3 ( V_2 , & V_4 -> V_17 , L_1 ) ;
if ( ! V_6 ) {
V_11 = - V_18 ;
goto V_16;
}
V_6 -> V_19 = V_10 -> V_20 ;
V_6 -> V_21 = V_10 -> V_22 - V_10 -> V_20 + 1 ;
if ( ! F_4 ( V_6 -> V_19 , V_6 -> V_21 , V_23 ) ) {
V_11 = - V_24 ;
goto V_25;
}
V_6 -> V_26 = F_5 ( V_6 -> V_19 , V_6 -> V_21 ) ;
if ( V_6 -> V_26 == NULL ) {
V_11 = - V_27 ;
goto V_28;
}
V_8 = F_6 ( V_6 ) ;
V_8 -> V_29 = V_6 -> V_26 ;
V_8 -> V_26 = V_6 -> V_26 +
F_7 ( V_8 , F_8 ( V_8 , & V_8 -> V_29 -> V_30 ) ) ;
V_13 = F_9 ( V_8 -> V_26 + V_31 ) ;
V_13 |= V_32 ;
F_10 ( V_13 , V_8 -> V_26 + V_31 ) ;
V_13 = F_9 ( V_8 -> V_26 + V_33 ) ;
V_13 |= V_32 ;
F_10 ( V_13 , V_8 -> V_26 + V_33 ) ;
V_8 -> V_34 = F_8 ( V_8 , & V_8 -> V_29 -> V_34 ) ;
V_8 -> V_35 = 0x20 ;
V_12 = F_11 ( V_4 , 0 ) ;
if ( V_12 < 0 )
goto V_36;
V_11 = F_12 ( V_6 , V_12 , V_37 ) ;
if ( V_11 != 0 )
goto V_36;
F_13 ( V_8 , 1 , & V_8 -> V_26 -> V_38 ) ;
return V_11 ;
V_36:
F_14 ( V_6 -> V_26 ) ;
V_28:
F_15 ( V_6 -> V_19 , V_6 -> V_21 ) ;
V_25:
F_16 ( V_6 ) ;
V_16:
return V_11 ;
}
static
void F_17 ( struct V_5 * V_6 , struct V_3 * V_4 )
{
F_18 ( V_6 ) ;
F_14 ( V_6 -> V_26 ) ;
F_15 ( V_6 -> V_19 , V_6 -> V_21 ) ;
F_16 ( V_6 ) ;
}
static int T_1 F_19 ( struct V_3 * V_4 )
{
if ( F_20 () )
return - V_39 ;
return F_1 ( & V_40 , V_4 ) ;
}
static int T_2 F_21 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_22 ( V_4 ) ;
F_17 ( V_6 , V_4 ) ;
return 0 ;
}
