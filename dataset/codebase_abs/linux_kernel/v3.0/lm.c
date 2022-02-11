static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return 1 ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_7 * V_8 = F_4 ( V_2 -> V_9 ) ;
return V_8 -> V_10 ( V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_7 * V_8 = F_4 ( V_2 -> V_9 ) ;
if ( V_8 -> remove )
V_8 -> remove ( V_6 ) ;
return 0 ;
}
static int T_1 F_6 ( void )
{
return F_7 ( & V_11 ) ;
}
int F_8 ( struct V_7 * V_4 )
{
V_4 -> V_4 . V_12 = & V_11 ;
return F_9 ( & V_4 -> V_4 ) ;
}
void F_10 ( struct V_7 * V_4 )
{
F_11 ( & V_4 -> V_4 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_13 = F_3 ( V_2 ) ;
F_13 ( V_13 ) ;
}
int F_14 ( struct V_5 * V_2 )
{
int V_14 ;
V_2 -> V_2 . V_15 = F_12 ;
V_2 -> V_2 . V_12 = & V_11 ;
V_14 = F_15 ( & V_2 -> V_2 , L_1 , V_2 -> V_16 ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_17 . V_18 = F_16 ( & V_2 -> V_2 ) ;
V_14 = F_17 ( & V_19 , & V_2 -> V_17 ) ;
if ( V_14 == 0 ) {
V_14 = F_18 ( & V_2 -> V_2 ) ;
if ( V_14 )
F_19 ( & V_2 -> V_17 ) ;
}
return V_14 ;
}
