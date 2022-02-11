static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
unsigned long V_9 ;
struct V_10 * V_11 = V_12 ;
V_8 = F_3 ( sizeof( * V_8 ) , V_13 ) ;
if ( ! V_8 )
return - V_14 ;
V_2 -> V_15 = V_8 ;
F_4 ( V_2 -> V_16 , L_1 ) ;
if ( V_6 -> V_17 == V_18 ) {
if ( V_11 == NULL ) {
F_5 ( V_2 -> V_16 , L_2 ) ;
return - V_19 ;
}
V_9 = V_11 -> V_20 [ 0 ] -> V_21 ;
} else {
F_5 ( V_2 -> V_16 ,
L_3 ) ;
return - V_22 ;
}
return F_6 ( V_2 , V_9 ) ;
}
static int F_7 ( struct V_10 * V_23 ,
void * V_24 )
{
if ( V_23 -> V_25 == 0 )
return - V_22 ;
return F_8 ( V_23 ) ;
}
static int F_9 ( struct V_10 * V_11 )
{
int V_26 ;
V_11 -> V_27 |= V_28 | V_29 ;
V_26 = F_10 ( V_11 , F_7 , NULL ) ;
if ( V_26 )
goto V_30;
if ( ! V_11 -> V_31 )
goto V_30;
V_26 = F_11 ( V_11 ) ;
if ( V_26 )
goto V_30;
V_12 = V_11 ;
return 0 ;
V_30:
F_12 ( V_11 ) ;
return V_26 ;
}
static void F_13 ( struct V_10 * V_11 )
{
F_12 ( V_11 ) ;
V_12 = NULL ;
}
static int T_1 F_14 ( void )
{
int V_26 ;
V_26 = F_15 ( & V_32 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_16 ( & V_33 ) ;
if ( V_26 < 0 ) {
F_17 ( & V_32 ) ;
return V_26 ;
}
return 0 ;
}
static void T_2 F_18 ( void )
{
F_19 ( & V_33 ) ;
F_17 ( & V_32 ) ;
}
