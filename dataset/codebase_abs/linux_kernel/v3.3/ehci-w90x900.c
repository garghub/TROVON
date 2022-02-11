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
V_6 -> V_21 = F_4 ( V_10 ) ;
if ( ! F_5 ( V_6 -> V_19 , V_6 -> V_21 , V_22 ) ) {
V_11 = - V_23 ;
goto V_24;
}
V_6 -> V_25 = F_6 ( V_6 -> V_19 , V_6 -> V_21 ) ;
if ( V_6 -> V_25 == NULL ) {
V_11 = - V_26 ;
goto V_27;
}
V_8 = F_7 ( V_6 ) ;
V_8 -> V_28 = V_6 -> V_25 ;
V_8 -> V_25 = V_6 -> V_25 +
F_8 ( V_8 , F_9 ( V_8 , & V_8 -> V_28 -> V_29 ) ) ;
V_13 = F_10 ( V_8 -> V_25 + V_30 ) ;
V_13 |= V_31 ;
F_11 ( V_13 , V_8 -> V_25 + V_30 ) ;
V_13 = F_10 ( V_8 -> V_25 + V_32 ) ;
V_13 |= V_31 ;
F_11 ( V_13 , V_8 -> V_25 + V_32 ) ;
V_8 -> V_33 = F_9 ( V_8 , & V_8 -> V_28 -> V_33 ) ;
V_8 -> V_34 = 0x20 ;
V_12 = F_12 ( V_4 , 0 ) ;
if ( V_12 < 0 )
goto V_35;
F_13 ( V_8 ) ;
V_11 = F_14 ( V_6 , V_12 , V_36 ) ;
if ( V_11 != 0 )
goto V_35;
F_15 ( V_8 , 1 , & V_8 -> V_25 -> V_37 ) ;
return V_11 ;
V_35:
F_16 ( V_6 -> V_25 ) ;
V_27:
F_17 ( V_6 -> V_19 , V_6 -> V_21 ) ;
V_24:
F_18 ( V_6 ) ;
V_16:
return V_11 ;
}
static
void F_19 ( struct V_5 * V_6 , struct V_3 * V_4 )
{
F_20 ( V_6 ) ;
F_16 ( V_6 -> V_25 ) ;
F_17 ( V_6 -> V_19 , V_6 -> V_21 ) ;
F_18 ( V_6 ) ;
}
static int T_1 F_21 ( struct V_3 * V_4 )
{
if ( F_22 () )
return - V_38 ;
return F_1 ( & V_39 , V_4 ) ;
}
static int T_2 F_23 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_24 ( V_4 ) ;
F_19 ( V_6 , V_4 ) ;
return 0 ;
}
