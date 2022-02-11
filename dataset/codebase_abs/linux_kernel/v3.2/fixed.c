static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_4 ( V_4 -> V_6 ) ) {
F_5 ( V_4 -> V_6 , V_4 -> V_7 ) ;
V_4 -> V_5 = true ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_4 ( V_4 -> V_6 ) ) {
F_5 ( V_4 -> V_6 , ! V_4 -> V_7 ) ;
V_4 -> V_5 = false ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_8 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_9 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_10 != 0 )
return - V_11 ;
return V_4 -> V_9 ;
}
static int T_1 F_10 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_2 . V_16 ;
struct V_3 * V_17 ;
int V_18 ;
V_17 = F_11 ( sizeof( struct V_3 ) , V_19 ) ;
if ( V_17 == NULL ) {
F_12 ( & V_13 -> V_2 , L_1 ) ;
V_18 = - V_20 ;
goto V_21;
}
V_17 -> V_22 . V_23 = F_13 ( V_15 -> V_24 , V_19 ) ;
if ( V_17 -> V_22 . V_23 == NULL ) {
F_12 ( & V_13 -> V_2 , L_2 ) ;
V_18 = - V_20 ;
goto V_21;
}
V_17 -> V_22 . type = V_25 ;
V_17 -> V_22 . V_26 = V_27 ;
V_17 -> V_22 . V_28 = & V_29 ;
V_17 -> V_22 . V_30 = 1 ;
V_17 -> V_9 = V_15 -> V_9 ;
V_17 -> V_6 = V_15 -> V_6 ;
V_17 -> V_8 = V_15 -> V_8 ;
if ( F_4 ( V_15 -> V_6 ) ) {
V_17 -> V_7 = V_15 -> V_7 ;
if ( ! V_15 -> V_6 )
F_14 ( & V_13 -> V_2 ,
L_3 ) ;
V_18 = F_15 ( V_15 -> V_6 , V_15 -> V_24 ) ;
if ( V_18 ) {
F_12 ( & V_13 -> V_2 ,
L_4 ,
V_15 -> V_6 , V_18 ) ;
goto V_31;
}
V_17 -> V_5 = V_15 -> V_32 ;
V_18 = V_17 -> V_5 ?
V_15 -> V_7 : ! V_15 -> V_7 ;
V_18 = F_16 ( V_15 -> V_6 , V_18 ) ;
if ( V_18 ) {
F_12 ( & V_13 -> V_2 ,
L_5 ,
V_15 -> V_6 , V_18 ) ;
goto V_33;
}
} else {
V_17 -> V_5 = true ;
}
V_17 -> V_2 = F_17 ( & V_17 -> V_22 , & V_13 -> V_2 ,
V_15 -> V_34 , V_17 ) ;
if ( F_18 ( V_17 -> V_2 ) ) {
V_18 = F_19 ( V_17 -> V_2 ) ;
F_12 ( & V_13 -> V_2 , L_6 , V_18 ) ;
goto V_33;
}
F_20 ( V_13 , V_17 ) ;
F_21 ( & V_13 -> V_2 , L_7 , V_17 -> V_22 . V_23 ,
V_17 -> V_9 ) ;
return 0 ;
V_33:
if ( F_4 ( V_15 -> V_6 ) )
F_22 ( V_15 -> V_6 ) ;
V_31:
F_23 ( V_17 -> V_22 . V_23 ) ;
V_21:
F_23 ( V_17 ) ;
return V_18 ;
}
static int T_2 F_24 ( struct V_12 * V_13 )
{
struct V_3 * V_17 = F_25 ( V_13 ) ;
F_26 ( V_17 -> V_2 ) ;
if ( F_4 ( V_17 -> V_6 ) )
F_22 ( V_17 -> V_6 ) ;
F_23 ( V_17 -> V_22 . V_23 ) ;
F_23 ( V_17 ) ;
return 0 ;
}
static int T_3 F_27 ( void )
{
return F_28 ( & V_35 ) ;
}
static void T_4 F_29 ( void )
{
F_30 ( & V_35 ) ;
}
