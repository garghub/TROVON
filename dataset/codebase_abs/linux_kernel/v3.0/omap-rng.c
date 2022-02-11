static inline T_1 F_1 ( int V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline void F_3 ( int V_1 , T_1 V_3 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static int F_5 ( struct V_4 * V_5 , int V_6 )
{
int V_7 , V_8 ;
for ( V_8 = 0 ; V_8 < 20 ; V_8 ++ ) {
V_7 = F_1 ( V_9 ) ? 0 : 1 ;
if ( V_7 || ! V_6 )
break;
F_6 ( 10 ) ;
}
return V_7 ;
}
static int F_7 ( struct V_4 * V_5 , T_1 * V_7 )
{
* V_7 = F_1 ( V_10 ) ;
return 4 ;
}
static int T_2 F_8 ( struct V_11 * V_12 )
{
struct V_13 * V_14 ;
int V_15 ;
if ( V_16 )
return - V_17 ;
if ( F_9 () ) {
V_18 = F_10 ( & V_12 -> V_19 , L_1 ) ;
if ( F_11 ( V_18 ) ) {
F_12 ( & V_12 -> V_19 , L_2 ) ;
V_15 = F_13 ( V_18 ) ;
return V_15 ;
} else
F_14 ( V_18 ) ;
}
V_14 = F_15 ( V_12 , V_20 , 0 ) ;
if ( ! V_14 )
return - V_21 ;
if ( ! F_16 ( V_14 -> V_22 , F_17 ( V_14 ) , V_12 -> V_23 ) ) {
V_15 = - V_17 ;
goto V_24;
}
F_18 ( & V_12 -> V_19 , V_14 ) ;
V_2 = F_19 ( V_14 -> V_22 , F_17 ( V_14 ) ) ;
if ( ! V_2 ) {
V_15 = - V_25 ;
goto V_26;
}
V_15 = F_20 ( & V_27 ) ;
if ( V_15 )
goto V_28;
F_21 ( & V_12 -> V_19 , L_3 ,
F_1 ( V_29 ) ) ;
F_3 ( V_30 , 0x1 ) ;
V_16 = V_12 ;
return 0 ;
V_28:
F_22 ( V_2 ) ;
V_2 = NULL ;
V_26:
F_23 ( V_14 -> V_22 , F_17 ( V_14 ) ) ;
V_24:
if ( F_9 () ) {
F_24 ( V_18 ) ;
F_25 ( V_18 ) ;
}
return V_15 ;
}
static int T_3 F_26 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_27 ( & V_12 -> V_19 ) ;
F_28 ( & V_27 ) ;
F_3 ( V_30 , 0x0 ) ;
F_22 ( V_2 ) ;
if ( F_9 () ) {
F_24 ( V_18 ) ;
F_25 ( V_18 ) ;
}
F_23 ( V_14 -> V_22 , F_17 ( V_14 ) ) ;
V_2 = NULL ;
return 0 ;
}
static int F_29 ( struct V_11 * V_12 , T_4 V_31 )
{
F_3 ( V_30 , 0x0 ) ;
return 0 ;
}
static int F_30 ( struct V_11 * V_12 )
{
F_3 ( V_30 , 0x1 ) ;
return 0 ;
}
static int T_5 F_31 ( void )
{
if ( ! F_32 () && ! F_9 () )
return - V_32 ;
return F_33 ( & V_33 ) ;
}
static void T_3 F_34 ( void )
{
F_35 ( & V_33 ) ;
}
