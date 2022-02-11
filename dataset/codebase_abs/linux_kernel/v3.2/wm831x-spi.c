static int T_1 F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 ;
enum V_6 type ;
int V_7 ;
type = (enum V_6 ) V_4 -> V_8 ;
V_5 = F_3 ( sizeof( struct V_5 ) , V_9 ) ;
if ( V_5 == NULL )
return - V_10 ;
V_2 -> V_11 = 16 ;
V_2 -> V_12 = V_13 ;
F_4 ( & V_2 -> V_14 , V_5 ) ;
V_5 -> V_14 = & V_2 -> V_14 ;
V_5 -> V_15 = F_5 ( V_2 , & V_16 ) ;
if ( F_6 ( V_5 -> V_15 ) ) {
V_7 = F_7 ( V_5 -> V_15 ) ;
F_8 ( V_5 -> V_14 , L_1 ,
V_7 ) ;
F_9 ( V_5 ) ;
return V_7 ;
}
return F_10 ( V_5 , type , V_2 -> V_17 ) ;
}
static int T_2 F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_12 ( & V_2 -> V_14 ) ;
F_13 ( V_5 ) ;
return 0 ;
}
static int F_14 ( struct V_18 * V_14 )
{
struct V_5 * V_5 = F_12 ( V_14 ) ;
return F_15 ( V_5 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_12 ( & V_2 -> V_14 ) ;
F_17 ( V_5 ) ;
}
static int T_3 F_18 ( void )
{
int V_7 ;
V_7 = F_19 ( & V_19 ) ;
if ( V_7 != 0 )
F_20 ( L_2 , V_7 ) ;
return 0 ;
}
static void T_4 F_21 ( void )
{
F_22 ( & V_19 ) ;
}
