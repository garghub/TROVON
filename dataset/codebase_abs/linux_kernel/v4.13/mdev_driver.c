static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 ;
V_5 = F_2 () ;
if ( F_3 ( V_5 ) )
return F_4 ( V_5 ) ;
V_3 = F_5 ( V_5 , & V_2 -> V_6 ) ;
if ( ! V_3 )
F_6 ( & V_2 -> V_6 , L_1 ,
F_7 ( V_5 ) ) ;
F_8 ( V_5 ) ;
return V_3 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_6 ) ;
F_6 ( & V_2 -> V_6 , L_2 ) ;
}
static int F_11 ( struct V_7 * V_6 )
{
struct V_8 * V_9 = F_12 ( V_6 -> V_10 ) ;
struct V_1 * V_2 = F_13 ( V_6 ) ;
int V_3 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( V_9 && V_9 -> V_11 ) {
V_3 = V_9 -> V_11 ( V_6 ) ;
if ( V_3 )
F_9 ( V_2 ) ;
}
return V_3 ;
}
static int F_14 ( struct V_7 * V_6 )
{
struct V_8 * V_9 = F_12 ( V_6 -> V_10 ) ;
struct V_1 * V_2 = F_13 ( V_6 ) ;
if ( V_9 && V_9 -> remove )
V_9 -> remove ( V_6 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
int F_15 ( struct V_8 * V_9 , struct V_12 * V_13 )
{
V_9 -> V_10 . V_14 = V_9 -> V_14 ;
V_9 -> V_10 . V_15 = & V_16 ;
V_9 -> V_10 . V_13 = V_13 ;
return F_16 ( & V_9 -> V_10 ) ;
}
void F_17 ( struct V_8 * V_9 )
{
F_18 ( & V_9 -> V_10 ) ;
}
int F_19 ( void )
{
return F_20 ( & V_16 ) ;
}
void F_21 ( void )
{
F_22 ( & V_16 ) ;
}
