static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
int V_5 ;
const struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_8 ;
V_8 = F_3 ( & V_2 -> V_9 , sizeof( struct V_8 ) , V_10 ) ;
if ( ! V_8 )
return - V_11 ;
V_2 -> V_12 = V_13 | V_14 ;
V_2 -> V_15 = 8 ;
F_4 ( V_2 ) ;
V_8 -> V_9 = & V_2 -> V_9 ;
V_8 -> V_16 = V_2 -> V_17 ;
F_5 ( V_2 , V_8 ) ;
V_4 = V_18 ;
V_4 . V_19 = 1 ;
V_8 -> V_20 = F_6 ( V_2 , & V_4 ) ;
if ( F_7 ( V_8 -> V_20 ) ) {
V_5 = F_8 ( V_8 -> V_20 ) ;
F_9 ( & V_2 -> V_9 , L_1 ,
V_5 ) ;
return V_5 ;
}
V_5 = F_10 ( V_8 , V_7 -> V_21 ) ;
if ( V_5 != 0 )
return V_5 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_12 ( V_2 ) ;
F_13 ( V_8 ) ;
return 0 ;
}
static int T_1 F_14 ( void )
{
int V_5 ;
V_5 = F_15 ( & V_22 ) ;
if ( V_5 != 0 ) {
F_16 ( L_2 , V_5 ) ;
return V_5 ;
}
return 0 ;
}
static void T_2 F_17 ( void )
{
F_18 ( & V_22 ) ;
}
