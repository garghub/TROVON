static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
const struct V_9 * V_10 ;
if ( ! V_8 -> V_11 )
return 0 ;
for ( V_10 = V_8 -> V_11 ; V_10 -> V_12 ; V_10 ++ ) {
if ( V_10 -> V_12 != V_6 -> V_12 )
continue;
if ( V_10 -> V_13 == V_14 ||
V_10 -> V_13 == V_6 -> V_13 )
return 1 ;
}
return 0 ;
}
static int F_4 ( void )
{
return F_5 ( & V_15 ) ;
}
static void F_6 ( void )
{
F_7 ( & V_15 ) ;
}
