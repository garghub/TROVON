static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
void T_1 * V_4 = ( void T_1 * ) V_2 -> V_5 ;
V_3 = ( ( F_2 ( V_4 + V_6 ) &
V_7 ) >> 8 ) ;
return V_3 > 0 ? 1 : 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_2 * V_8 )
{
int V_9 ;
T_2 V_10 ;
void T_1 * V_4 = ( void T_1 * ) V_2 -> V_5 ;
* V_8 = F_2 ( V_4 + V_11 ) ;
V_9 = F_2 ( V_4 + V_6 ) & V_12 ;
if ( V_9 ) {
F_4 ( & V_13 -> V_14 , L_1 ) ;
V_10 = F_2 ( V_4 + V_15 ) ;
F_5 ( V_10 | V_16 ,
V_4 + V_15 ) ;
return 0 ;
} else
return 4 ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_2 V_10 , V_17 ;
void T_1 * V_4 = ( void T_1 * ) V_2 -> V_5 ;
V_10 = F_2 ( V_4 + V_15 ) ;
F_5 ( V_10 & ~ V_18 , V_4 + V_15 ) ;
V_17 = F_2 ( V_4 + V_6 ) ;
if ( V_17 & V_19 ) {
F_7 ( & V_13 -> V_14 , L_2 ) ;
return - V_20 ;
}
V_10 = F_2 ( V_4 + V_15 ) ;
F_5 ( V_10 | V_21 , V_4 + V_15 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
T_2 V_10 ;
void T_1 * V_4 = ( void T_1 * ) V_2 -> V_5 ;
V_10 = F_2 ( V_4 + V_15 ) ;
F_5 ( V_10 & ~ V_21 , V_4 + V_15 ) ;
}
static int T_3 F_9 ( struct V_22 * V_23 )
{
int V_9 = - V_20 ;
struct V_24 * V_24 ;
struct V_25 * V_26 , * V_27 ;
void T_1 * V_4 = NULL ;
if ( V_13 )
return - V_28 ;
V_24 = F_10 ( & V_23 -> V_14 , L_3 ) ;
if ( F_11 ( V_24 ) ) {
F_7 ( & V_23 -> V_14 , L_4 ) ;
V_9 = F_12 ( V_24 ) ;
goto V_29;
}
F_13 ( V_24 ) ;
V_26 = F_14 ( V_23 , V_30 , 0 ) ;
if ( ! V_26 ) {
V_9 = - V_31 ;
goto V_32;
}
V_27 = F_15 ( V_26 -> V_33 , F_16 ( V_26 ) , V_23 -> V_34 ) ;
if ( V_27 == NULL ) {
V_9 = - V_28 ;
goto V_32;
}
V_4 = F_17 ( V_26 -> V_33 , F_16 ( V_26 ) ) ;
if ( ! V_4 ) {
V_9 = - V_35 ;
goto V_36;
}
V_37 . V_5 = ( unsigned long ) V_4 ;
V_9 = F_18 ( & V_37 ) ;
if ( V_9 ) {
F_7 ( & V_23 -> V_14 , L_5 , V_9 ) ;
goto V_38;
}
V_13 = V_23 ;
F_19 ( & V_23 -> V_14 , L_6 ) ;
return 0 ;
V_38:
F_20 ( V_4 ) ;
V_4 = NULL ;
V_36:
F_21 ( V_26 -> V_33 , F_16 ( V_26 ) ) ;
V_32:
F_22 ( V_24 ) ;
F_23 ( V_24 ) ;
V_29:
return V_9 ;
}
static int T_4 F_24 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = F_14 ( V_23 , V_30 , 0 ) ;
void T_1 * V_4 = ( void T_1 * ) V_37 . V_5 ;
struct V_24 * V_24 = F_10 ( & V_23 -> V_14 , L_3 ) ;
F_25 ( & V_37 ) ;
F_20 ( V_4 ) ;
F_21 ( V_26 -> V_33 , F_16 ( V_26 ) ) ;
F_22 ( V_24 ) ;
F_23 ( V_24 ) ;
return 0 ;
}
static int T_3 F_26 ( void )
{
return F_27 ( & V_39 , F_9 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_39 ) ;
}
