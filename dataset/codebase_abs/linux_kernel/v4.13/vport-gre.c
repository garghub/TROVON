static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 -> V_5 ) ;
struct V_6 * V_7 ;
struct V_1 * V_1 ;
int V_8 ;
V_1 = F_3 ( 0 , & V_9 , V_3 ) ;
if ( F_4 ( V_1 ) )
return V_1 ;
F_5 () ;
V_7 = F_6 ( V_4 , V_3 -> V_10 , V_11 ) ;
if ( F_4 ( V_7 ) ) {
F_7 () ;
F_8 ( V_1 ) ;
return F_9 ( V_7 ) ;
}
V_8 = F_10 ( V_7 , V_7 -> V_12 | V_13 ) ;
if ( V_8 < 0 ) {
F_11 ( V_7 ) ;
F_7 () ;
F_8 ( V_1 ) ;
return F_12 ( V_8 ) ;
}
F_7 () ;
return V_1 ;
}
static struct V_1 * F_13 ( const struct V_2 * V_3 )
{
struct V_1 * V_1 ;
V_1 = F_1 ( V_3 ) ;
if ( F_4 ( V_1 ) )
return V_1 ;
return F_14 ( V_1 , V_3 -> V_10 ) ;
}
static int T_1 F_15 ( void )
{
return F_16 ( & V_9 ) ;
}
static void T_2 F_17 ( void )
{
F_18 ( & V_9 ) ;
}
