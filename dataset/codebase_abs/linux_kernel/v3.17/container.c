static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
struct V_3 * V_6 ;
F_3 (child, &adev->children, node)
if ( ! F_4 ( V_6 , false ) )
return - V_7 ;
return 0 ;
}
static void F_5 ( struct V_8 * V_5 )
{
F_6 ( F_7 ( V_5 ) ) ;
}
static int F_8 ( struct V_3 * V_4 ,
const struct V_9 * V_10 )
{
struct V_1 * V_2 ;
struct V_8 * V_5 ;
int V_11 ;
if ( V_4 -> V_12 . V_13 )
return 0 ;
V_2 = F_9 ( sizeof( * V_2 ) , V_14 ) ;
if ( ! V_2 )
return - V_15 ;
V_2 -> V_16 = F_1 ;
V_5 = & V_2 -> V_5 ;
V_5 -> V_17 = & V_18 ;
F_10 ( V_5 , L_1 , F_11 ( & V_4 -> V_5 ) ) ;
F_12 ( V_5 , V_4 ) ;
V_5 -> V_19 = F_5 ;
V_11 = F_13 ( V_5 ) ;
if ( V_11 ) {
F_14 ( V_5 ) ;
return V_11 ;
}
V_4 -> V_20 = V_5 ;
return 1 ;
}
static void F_15 ( struct V_3 * V_4 )
{
struct V_8 * V_5 = F_16 ( V_4 ) ;
V_4 -> V_20 = NULL ;
if ( V_5 )
F_17 ( V_5 ) ;
}
static void F_18 ( struct V_3 * V_4 )
{
struct V_8 * V_5 = F_16 ( V_4 ) ;
F_19 ( & V_5 -> V_21 , V_22 ) ;
}
void T_1 F_20 ( void )
{
F_21 ( & V_23 ) ;
}
void T_1 F_20 ( void )
{
F_22 ( & V_23 , L_2 ) ;
}
