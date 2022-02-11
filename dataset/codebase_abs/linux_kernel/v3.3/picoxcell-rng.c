static inline T_1 F_1 ( void )
{
return F_2 ( V_1 + V_2 ) ;
}
static inline bool F_3 ( void )
{
return F_1 () & V_3 ;
}
static void F_4 ( void )
{
F_5 ( 0 , V_1 + V_4 ) ;
F_5 ( 0 , V_1 + V_2 ) ;
}
static void F_6 ( void )
{
F_5 ( V_5 , V_1 + V_2 ) ;
F_5 ( V_5 , V_1 + V_4 ) ;
F_4 () ;
}
static int F_7 ( struct V_6 * V_7 , void * V_8 , T_2 V_9 ,
bool V_10 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_12 && F_3 () ; ++ V_11 ) {
if ( ! V_10 )
return 0 ;
F_8 ( 1 ) ;
}
if ( F_1 () & V_13 ) {
F_9 ( V_14 , L_1 ) ;
F_6 () ;
return - V_15 ;
}
if ( V_11 == V_12 )
return 0 ;
* ( T_1 * ) V_8 = F_2 ( V_1 + V_16 ) ;
return sizeof( T_1 ) ;
}
static int F_10 ( struct V_17 * V_18 )
{
int V_19 ;
struct V_20 * V_21 = F_11 ( V_18 , V_22 , 0 ) ;
if ( ! V_21 ) {
F_12 ( & V_18 -> V_23 , L_2 ) ;
return - V_24 ;
}
if ( ! F_13 ( & V_18 -> V_23 , V_21 -> V_25 , F_14 ( V_21 ) ,
L_3 ) ) {
F_12 ( & V_18 -> V_23 , L_4 ) ;
return - V_26 ;
}
V_1 = F_15 ( & V_18 -> V_23 , V_21 -> V_25 , F_14 ( V_21 ) ) ;
if ( ! V_1 ) {
F_12 ( & V_18 -> V_23 , L_5 ) ;
return - V_24 ;
}
V_27 = F_16 ( & V_18 -> V_23 , NULL ) ;
if ( F_17 ( V_27 ) ) {
F_12 ( & V_18 -> V_23 , L_6 ) ;
return F_18 ( V_27 ) ;
}
V_19 = F_19 ( V_27 ) ;
if ( V_19 ) {
F_12 ( & V_18 -> V_23 , L_7 ) ;
goto V_28;
}
F_4 () ;
V_19 = F_20 ( & V_29 ) ;
if ( V_19 )
goto V_30;
V_14 = & V_18 -> V_23 ;
F_21 ( & V_18 -> V_23 , L_8 ) ;
return 0 ;
V_30:
F_22 ( V_27 ) ;
V_28:
F_23 ( V_27 ) ;
return V_19 ;
}
static int T_3 F_24 ( struct V_17 * V_18 )
{
F_25 ( & V_29 ) ;
F_22 ( V_27 ) ;
F_23 ( V_27 ) ;
return 0 ;
}
static int F_26 ( struct V_31 * V_23 )
{
F_22 ( V_27 ) ;
return 0 ;
}
static int F_27 ( struct V_31 * V_23 )
{
return F_19 ( V_27 ) ;
}
