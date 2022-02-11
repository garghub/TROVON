static int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
return F_2 ( V_4 , V_2 ) ;
}
static int F_3 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_6 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
return F_4 ( V_4 , V_2 , V_6 ) ;
}
static int F_5 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_7 , T_1 * V_8 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
return F_6 ( V_4 , V_2 , V_7 , V_8 ) ;
}
static int F_7 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_7 ,
const T_1 * V_8 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
return F_8 ( V_4 , V_2 , V_7 , V_8 ) ;
}
static int
F_9 ( struct V_3 * V_4 , const struct V_9 * V_10 )
{
enum V_11 V_12 ;
const struct V_13 * V_14 ;
V_15 . V_16 = ( void * ) V_10 ;
V_15 . V_17 = V_4 -> V_17 ;
V_15 . V_5 = V_4 ;
V_15 . V_18 = & V_4 -> V_18 ;
V_14 = F_10 ( V_19 , & V_4 -> V_18 ) ;
if ( ! V_14 ) {
F_11 ( & V_4 -> V_18 , L_1 ) ;
V_12 = V_10 -> V_20 ;
} else
V_12 = (enum V_11 ) V_14 -> V_16 ;
return F_12 ( & V_15 , V_12 ) ;
}
static int F_13 ( struct V_3 * V_4 )
{
struct V_1 * V_1 = F_14 ( & V_4 -> V_18 ) ;
return F_15 ( V_1 ) ;
}
static int T_2 F_16 ( void )
{
return F_17 ( & V_21 ) ;
}
static void T_3 F_18 ( void )
{
F_19 ( & V_21 ) ;
}
