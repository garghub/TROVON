static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
const struct V_6 * V_7 = F_3 ( V_2 ) ;
const struct V_8 * V_9 ;
struct V_10 * V_10 ;
enum V_11 type ;
int V_12 ;
if ( V_2 -> V_5 . V_13 ) {
V_9 = F_4 ( V_14 , & V_2 -> V_5 ) ;
type = (enum V_11 ) V_9 -> V_15 ;
} else {
type = (enum V_11 ) V_7 -> V_16 ;
}
V_10 = F_5 ( & V_2 -> V_5 , sizeof( struct V_10 ) , V_17 ) ;
if ( V_10 == NULL )
return - V_18 ;
V_2 -> V_19 = V_20 ;
F_6 ( V_2 , V_10 ) ;
V_10 -> V_5 = & V_2 -> V_5 ;
V_10 -> type = type ;
V_10 -> V_21 = F_7 ( V_2 , & V_22 ) ;
if ( F_8 ( V_10 -> V_21 ) ) {
V_12 = F_9 ( V_10 -> V_21 ) ;
F_10 ( V_10 -> V_5 , L_1 ,
V_12 ) ;
return V_12 ;
}
if ( V_4 )
memcpy ( & V_10 -> V_4 , V_4 , sizeof( * V_4 ) ) ;
return F_11 ( V_10 , V_2 -> V_23 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_10 * V_10 = F_13 ( V_2 ) ;
F_14 ( V_10 ) ;
return 0 ;
}
static int F_15 ( struct V_24 * V_5 )
{
struct V_10 * V_10 = F_16 ( V_5 ) ;
return F_17 ( V_10 ) ;
}
static int F_18 ( struct V_24 * V_5 )
{
struct V_10 * V_10 = F_16 ( V_5 ) ;
F_19 ( V_10 ) ;
return 0 ;
}
static int T_1 F_20 ( void )
{
int V_12 ;
V_12 = F_21 ( & V_25 ) ;
if ( V_12 != 0 )
F_22 ( L_2 , V_12 ) ;
return 0 ;
}
static void T_2 F_23 ( void )
{
F_24 ( & V_25 ) ;
}
