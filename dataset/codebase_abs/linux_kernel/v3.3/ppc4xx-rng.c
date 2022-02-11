static int F_1 ( struct V_1 * V_2 , int V_3 )
{
void T_1 * V_4 = ( void T_1 * ) V_2 -> V_5 ;
int V_6 , V_7 , V_8 = 0 ;
for ( V_7 = 0 ; V_7 < 20 ; V_7 ++ ) {
V_6 = ( F_2 ( V_4 + V_9 ) & V_10 ) ;
if ( ! V_6 || ! V_3 ) {
V_8 = 1 ;
break;
}
F_3 ( 10 ) ;
}
return V_8 ;
}
static int F_4 ( struct V_1 * V_2 , T_2 * V_11 )
{
void T_1 * V_4 = ( void T_1 * ) V_2 -> V_5 ;
* V_11 = F_2 ( V_4 + V_12 ) ;
return 4 ;
}
static int F_5 ( int V_13 )
{
struct V_14 * V_15 ;
void T_1 * V_16 ;
int V_17 = 0 ;
T_2 V_18 ;
V_15 = F_6 ( NULL , NULL , L_1 ) ;
if ( ! V_15 )
return - V_19 ;
V_16 = F_7 ( V_15 , 0 ) ;
if ( ! V_16 ) {
V_17 = - V_19 ;
goto V_20;
}
V_18 = F_2 ( V_16 + V_21 ) ;
if ( V_13 )
V_18 |= V_22 ;
else
V_18 = V_18 & ~ V_22 ;
F_8 ( V_16 + V_21 , V_18 ) ;
F_9 ( V_16 ) ;
V_20:
F_10 ( V_15 ) ;
return V_17 ;
}
static int T_3 F_11 ( struct V_23 * V_24 )
{
void T_1 * V_4 ;
int V_17 = 0 ;
V_4 = F_7 ( V_24 -> V_24 . V_25 , 0 ) ;
if ( ! V_4 )
return - V_19 ;
V_17 = F_5 ( 1 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_4 + V_26 , V_27 ) ;
V_28 . V_5 = ( unsigned long ) V_4 ;
V_17 = F_12 ( & V_28 ) ;
return V_17 ;
}
static int T_4 F_13 ( struct V_23 * V_24 )
{
void T_1 * V_4 = ( void T_1 * ) V_28 . V_5 ;
F_14 ( & V_28 ) ;
F_5 ( 0 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
