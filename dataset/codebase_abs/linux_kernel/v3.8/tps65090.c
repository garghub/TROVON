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
struct V_13 * V_13 ;
int V_14 ;
if ( ! V_11 ) {
F_3 ( & V_7 -> V_2 , L_1 ) ;
return - V_15 ;
}
V_13 = F_4 ( & V_7 -> V_2 , sizeof( * V_13 ) , V_16 ) ;
if ( ! V_13 ) {
F_3 ( & V_7 -> V_2 , L_2 ) ;
return - V_17 ;
}
V_13 -> V_2 = & V_7 -> V_2 ;
F_5 ( V_7 , V_13 ) ;
V_13 -> V_18 = F_6 ( V_7 , & V_19 ) ;
if ( F_7 ( V_13 -> V_18 ) ) {
V_14 = F_8 ( V_13 -> V_18 ) ;
F_3 ( & V_7 -> V_2 , L_3 , V_14 ) ;
return V_14 ;
}
if ( V_7 -> V_20 ) {
V_14 = F_9 ( V_13 -> V_18 , V_7 -> V_20 ,
V_21 | V_22 , V_11 -> V_23 ,
& V_24 , & V_13 -> V_25 ) ;
if ( V_14 ) {
F_3 ( & V_7 -> V_2 ,
L_4 , V_14 ) ;
return V_14 ;
}
}
V_14 = F_10 ( V_13 -> V_2 , - 1 , V_26 ,
F_11 ( V_26 ) , NULL ,
F_12 ( V_13 -> V_25 ) , NULL ) ;
if ( V_14 ) {
F_3 ( & V_7 -> V_2 , L_5 ,
V_14 ) ;
goto V_27;
}
return 0 ;
V_27:
if ( V_7 -> V_20 )
F_13 ( V_7 -> V_20 , V_13 -> V_25 ) ;
return V_14 ;
}
static int F_14 ( struct V_6 * V_7 )
{
struct V_13 * V_13 = F_15 ( V_7 ) ;
F_16 ( V_13 -> V_2 ) ;
if ( V_7 -> V_20 )
F_13 ( V_7 -> V_20 , V_13 -> V_25 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_18 ( V_2 ) ;
if ( V_7 -> V_20 )
F_19 ( V_7 -> V_20 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_18 ( V_2 ) ;
if ( V_7 -> V_20 )
F_21 ( V_7 -> V_20 ) ;
return 0 ;
}
static int T_1 F_22 ( void )
{
return F_23 ( & V_28 ) ;
}
static void T_2 F_24 ( void )
{
F_25 ( & V_28 ) ;
}
