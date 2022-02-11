static int F_1 ( struct V_1 * V_2 , int V_3 )
{
void T_1 * V_4 = ( void T_1 * ) V_2 -> V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < 20 ; V_6 ++ ) {
int V_7 = ( F_2 ( V_4 + V_8 ) &
V_9 ) >> 8 ;
if ( V_7 || ! V_3 )
return ! ! V_7 ;
F_3 ( 10 ) ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_2 * V_10 )
{
int V_11 ;
T_2 V_12 ;
void T_1 * V_4 = ( void T_1 * ) V_2 -> V_5 ;
* V_10 = F_2 ( V_4 + V_13 ) ;
V_11 = F_2 ( V_4 + V_8 ) & V_14 ;
if ( V_11 ) {
F_5 ( & V_15 -> V_16 , L_1 ) ;
V_12 = F_2 ( V_4 + V_17 ) ;
F_6 ( V_12 | V_18 ,
V_4 + V_17 ) ;
return 0 ;
} else
return 4 ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_2 V_12 , V_19 ;
void T_1 * V_4 = ( void T_1 * ) V_2 -> V_5 ;
V_12 = F_2 ( V_4 + V_17 ) ;
F_6 ( V_12 & ~ V_20 , V_4 + V_17 ) ;
V_19 = F_2 ( V_4 + V_8 ) ;
if ( V_19 & V_21 ) {
F_8 ( & V_15 -> V_16 , L_2 ) ;
return - V_22 ;
}
V_12 = F_2 ( V_4 + V_17 ) ;
F_6 ( V_12 | V_23 , V_4 + V_17 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_2 V_12 ;
void T_1 * V_4 = ( void T_1 * ) V_2 -> V_5 ;
V_12 = F_2 ( V_4 + V_17 ) ;
F_6 ( V_12 & ~ V_23 , V_4 + V_17 ) ;
}
static int T_3 F_10 ( struct V_24 * V_25 )
{
int V_11 = - V_22 ;
struct V_26 * V_26 ;
struct V_27 * V_28 , * V_29 ;
void T_1 * V_4 = NULL ;
if ( V_15 )
return - V_30 ;
V_26 = F_11 ( & V_25 -> V_16 , L_3 ) ;
if ( F_12 ( V_26 ) ) {
F_8 ( & V_25 -> V_16 , L_4 ) ;
V_11 = F_13 ( V_26 ) ;
goto V_31;
}
F_14 ( V_26 ) ;
V_28 = F_15 ( V_25 , V_32 , 0 ) ;
if ( ! V_28 ) {
V_11 = - V_33 ;
goto V_34;
}
V_29 = F_16 ( V_28 -> V_35 , F_17 ( V_28 ) , V_25 -> V_36 ) ;
if ( V_29 == NULL ) {
V_11 = - V_30 ;
goto V_34;
}
V_4 = F_18 ( V_28 -> V_35 , F_17 ( V_28 ) ) ;
if ( ! V_4 ) {
V_11 = - V_37 ;
goto V_38;
}
V_39 . V_5 = ( unsigned long ) V_4 ;
V_11 = F_19 ( & V_39 ) ;
if ( V_11 ) {
F_8 ( & V_25 -> V_16 , L_5 , V_11 ) ;
goto V_40;
}
V_15 = V_25 ;
F_20 ( & V_25 -> V_16 , L_6 ) ;
return 0 ;
V_40:
F_21 ( V_4 ) ;
V_4 = NULL ;
V_38:
F_22 ( V_28 -> V_35 , F_17 ( V_28 ) ) ;
V_34:
F_23 ( V_26 ) ;
F_24 ( V_26 ) ;
V_31:
return V_11 ;
}
static int T_4 F_25 ( struct V_24 * V_25 )
{
struct V_27 * V_28 = F_15 ( V_25 , V_32 , 0 ) ;
void T_1 * V_4 = ( void T_1 * ) V_39 . V_5 ;
struct V_26 * V_26 = F_11 ( & V_25 -> V_16 , L_3 ) ;
F_26 ( & V_39 ) ;
F_21 ( V_4 ) ;
F_22 ( V_28 -> V_35 , F_17 ( V_28 ) ) ;
F_23 ( V_26 ) ;
F_24 ( V_26 ) ;
return 0 ;
}
static int T_3 F_27 ( void )
{
return F_28 ( & V_41 , F_10 ) ;
}
static void T_4 F_29 ( void )
{
F_30 ( & V_41 ) ;
}
