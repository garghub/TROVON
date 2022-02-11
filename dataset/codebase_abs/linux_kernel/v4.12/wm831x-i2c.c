static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
const struct V_8 * V_9 ;
struct V_10 * V_10 ;
enum V_11 type ;
int V_12 ;
if ( V_2 -> V_7 . V_13 ) {
V_9 = F_3 ( V_14 , & V_2 -> V_7 ) ;
type = (enum V_11 ) V_9 -> V_15 ;
} else {
type = (enum V_11 ) V_4 -> V_16 ;
}
V_10 = F_4 ( & V_2 -> V_7 , sizeof( struct V_10 ) , V_17 ) ;
if ( V_10 == NULL )
return - V_18 ;
F_5 ( V_2 , V_10 ) ;
V_10 -> V_7 = & V_2 -> V_7 ;
V_10 -> type = type ;
V_10 -> V_19 = F_6 ( V_2 , & V_20 ) ;
if ( F_7 ( V_10 -> V_19 ) ) {
V_12 = F_8 ( V_10 -> V_19 ) ;
F_9 ( V_10 -> V_7 , L_1 ,
V_12 ) ;
return V_12 ;
}
if ( V_6 )
memcpy ( & V_10 -> V_6 , V_6 , sizeof( * V_6 ) ) ;
return F_10 ( V_10 , V_2 -> V_21 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_10 * V_10 = F_12 ( V_2 ) ;
F_13 ( V_10 ) ;
return 0 ;
}
static int F_14 ( struct V_22 * V_7 )
{
struct V_10 * V_10 = F_15 ( V_7 ) ;
return F_16 ( V_10 ) ;
}
static int F_17 ( struct V_22 * V_7 )
{
struct V_10 * V_10 = F_15 ( V_7 ) ;
F_18 ( V_10 ) ;
return 0 ;
}
static int T_1 F_19 ( void )
{
int V_12 ;
V_12 = F_20 ( & V_23 ) ;
if ( V_12 != 0 )
F_21 ( L_2 , V_12 ) ;
return V_12 ;
}
static void T_2 F_22 ( void )
{
F_23 ( & V_23 ) ;
}
