static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( ( V_3 == V_4 ) || ( V_3 == V_5 ) )
return true ;
else
return false ;
}
static int F_2 ( struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
struct V_10 * V_11 = V_7 -> V_2 . V_12 ;
int V_13 = 0 ;
struct V_14 * V_14 ;
int V_15 ;
if ( ! V_11 && ! V_7 -> V_2 . V_16 ) {
F_3 ( & V_7 -> V_2 ,
L_1 ) ;
return - V_17 ;
}
if ( V_11 )
V_13 = V_11 -> V_13 ;
V_14 = F_4 ( & V_7 -> V_2 , sizeof( * V_14 ) , V_18 ) ;
if ( ! V_14 ) {
F_3 ( & V_7 -> V_2 , L_2 ) ;
return - V_19 ;
}
V_14 -> V_2 = & V_7 -> V_2 ;
F_5 ( V_7 , V_14 ) ;
V_14 -> V_20 = F_6 ( V_7 , & V_21 ) ;
if ( F_7 ( V_14 -> V_20 ) ) {
V_15 = F_8 ( V_14 -> V_20 ) ;
F_3 ( & V_7 -> V_2 , L_3 , V_15 ) ;
return V_15 ;
}
if ( V_7 -> V_22 ) {
V_15 = F_9 ( V_14 -> V_20 , V_7 -> V_22 ,
V_23 | V_24 , V_13 ,
& V_25 , & V_14 -> V_26 ) ;
if ( V_15 ) {
F_3 ( & V_7 -> V_2 ,
L_4 , V_15 ) ;
return V_15 ;
}
}
V_15 = F_10 ( V_14 -> V_2 , - 1 , V_27 ,
F_11 ( V_27 ) , NULL ,
0 , F_12 ( V_14 -> V_26 ) ) ;
if ( V_15 ) {
F_3 ( & V_7 -> V_2 , L_5 ,
V_15 ) ;
goto V_28;
}
return 0 ;
V_28:
if ( V_7 -> V_22 )
F_13 ( V_7 -> V_22 , V_14 -> V_26 ) ;
return V_15 ;
}
static int F_14 ( struct V_6 * V_7 )
{
struct V_14 * V_14 = F_15 ( V_7 ) ;
F_16 ( V_14 -> V_2 ) ;
if ( V_7 -> V_22 )
F_13 ( V_7 -> V_22 , V_14 -> V_26 ) ;
return 0 ;
}
static int T_1 F_17 ( void )
{
return F_18 ( & V_29 ) ;
}
static void T_2 F_19 ( void )
{
F_20 ( & V_29 ) ;
}
