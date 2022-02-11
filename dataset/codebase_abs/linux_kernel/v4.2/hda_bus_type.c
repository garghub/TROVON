const struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
if ( V_5 -> V_6 ) {
const struct V_1 * V_7 = V_5 -> V_6 ;
while ( V_7 -> V_8 ) {
if ( V_3 -> V_8 == V_7 -> V_8 &&
( ! V_7 -> V_9 || V_7 -> V_9 == V_3 -> V_10 ) )
return V_7 ;
V_7 ++ ;
}
}
return NULL ;
}
static int F_2 ( struct V_2 * V_11 , struct V_4 * V_5 )
{
if ( F_1 ( V_11 , V_5 ) )
return 1 ;
else
return 0 ;
}
static int F_3 ( struct V_12 * V_11 , struct V_13 * V_5 )
{
struct V_2 * V_3 = F_4 ( V_11 ) ;
struct V_4 * V_14 = F_5 ( V_5 ) ;
if ( V_3 -> type != V_14 -> type )
return 0 ;
if ( V_14 -> V_15 )
return V_14 -> V_15 ( V_3 , V_14 ) ;
else
return F_2 ( V_3 , V_14 ) ;
return 1 ;
}
static int T_1 F_6 ( void )
{
return F_7 ( & V_16 ) ;
}
static void T_2 F_8 ( void )
{
F_9 ( & V_16 ) ;
}
