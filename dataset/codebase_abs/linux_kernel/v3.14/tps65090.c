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
struct V_10 * V_11 = F_3 ( & V_7 -> V_2 ) ;
int V_12 = 0 ;
struct V_13 * V_13 ;
int V_14 ;
if ( ! V_11 && ! V_7 -> V_2 . V_15 ) {
F_4 ( & V_7 -> V_2 ,
L_1 ) ;
return - V_16 ;
}
if ( V_11 )
V_12 = V_11 -> V_12 ;
V_13 = F_5 ( & V_7 -> V_2 , sizeof( * V_13 ) , V_17 ) ;
if ( ! V_13 ) {
F_4 ( & V_7 -> V_2 , L_2 ) ;
return - V_18 ;
}
V_13 -> V_2 = & V_7 -> V_2 ;
F_6 ( V_7 , V_13 ) ;
V_13 -> V_19 = F_7 ( V_7 , & V_20 ) ;
if ( F_8 ( V_13 -> V_19 ) ) {
V_14 = F_9 ( V_13 -> V_19 ) ;
F_4 ( & V_7 -> V_2 , L_3 , V_14 ) ;
return V_14 ;
}
if ( V_7 -> V_21 ) {
V_14 = F_10 ( V_13 -> V_19 , V_7 -> V_21 ,
V_22 | V_23 , V_12 ,
& V_24 , & V_13 -> V_25 ) ;
if ( V_14 ) {
F_4 ( & V_7 -> V_2 ,
L_4 , V_14 ) ;
return V_14 ;
}
}
V_14 = F_11 ( V_13 -> V_2 , - 1 , V_26 ,
F_12 ( V_26 ) , NULL ,
0 , F_13 ( V_13 -> V_25 ) ) ;
if ( V_14 ) {
F_4 ( & V_7 -> V_2 , L_5 ,
V_14 ) ;
goto V_27;
}
return 0 ;
V_27:
if ( V_7 -> V_21 )
F_14 ( V_7 -> V_21 , V_13 -> V_25 ) ;
return V_14 ;
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_13 * V_13 = F_16 ( V_7 ) ;
F_17 ( V_13 -> V_2 ) ;
if ( V_7 -> V_21 )
F_14 ( V_7 -> V_21 , V_13 -> V_25 ) ;
return 0 ;
}
static int T_1 F_18 ( void )
{
return F_19 ( & V_28 ) ;
}
static void T_2 F_20 ( void )
{
F_21 ( & V_28 ) ;
}
