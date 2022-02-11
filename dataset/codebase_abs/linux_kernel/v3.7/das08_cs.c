static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
unsigned long V_8 ;
struct V_9 * V_10 = V_11 ;
V_7 = F_3 ( V_2 , sizeof( struct V_12 ) ) ;
if ( V_7 < 0 )
return V_7 ;
F_4 ( V_2 -> V_13 , L_1 ) ;
if ( V_6 -> V_14 == V_15 ) {
if ( V_10 == NULL ) {
F_5 ( V_2 -> V_13 , L_2 ) ;
return - V_16 ;
}
V_8 = V_10 -> V_17 [ 0 ] -> V_18 ;
} else {
F_5 ( V_2 -> V_13 ,
L_3 ) ;
return - V_19 ;
}
return F_6 ( V_2 , V_8 ) ;
}
static int F_7 ( struct V_9 * V_20 ,
void * V_21 )
{
if ( V_20 -> V_22 == 0 )
return - V_19 ;
return F_8 ( V_20 ) ;
}
static int F_9 ( struct V_9 * V_10 )
{
int V_7 ;
V_10 -> V_23 |= V_24 | V_25 ;
V_7 = F_10 ( V_10 , F_7 , NULL ) ;
if ( V_7 )
goto V_26;
if ( ! V_10 -> V_27 )
goto V_26;
V_7 = F_11 ( V_10 ) ;
if ( V_7 )
goto V_26;
V_11 = V_10 ;
return 0 ;
V_26:
F_12 ( V_10 ) ;
return V_7 ;
}
static void F_13 ( struct V_9 * V_10 )
{
F_12 ( V_10 ) ;
V_11 = NULL ;
}
static int T_1 F_14 ( void )
{
int V_7 ;
V_7 = F_15 ( & V_28 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_16 ( & V_29 ) ;
if ( V_7 < 0 ) {
F_17 ( & V_28 ) ;
return V_7 ;
}
return 0 ;
}
static void T_2 F_18 ( void )
{
F_19 ( & V_29 ) ;
F_17 ( & V_28 ) ;
}
