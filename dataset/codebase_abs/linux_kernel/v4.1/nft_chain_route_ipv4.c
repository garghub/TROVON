static unsigned int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
unsigned int V_7 ;
struct V_8 V_9 ;
T_1 V_10 ;
T_2 V_11 , V_12 ;
T_3 V_13 ;
const struct V_14 * V_15 ;
if ( V_4 -> V_16 < sizeof( struct V_14 ) ||
F_2 ( V_4 ) < sizeof( struct V_14 ) )
return V_17 ;
F_3 ( & V_9 , V_2 , V_4 , V_6 ) ;
V_10 = V_4 -> V_10 ;
V_15 = F_4 ( V_4 ) ;
V_11 = V_15 -> V_11 ;
V_12 = V_15 -> V_12 ;
V_13 = V_15 -> V_13 ;
V_7 = F_5 ( & V_9 , V_2 ) ;
if ( V_7 != V_18 && V_7 != V_19 ) {
V_15 = F_4 ( V_4 ) ;
if ( V_15 -> V_11 != V_11 ||
V_15 -> V_12 != V_12 ||
V_4 -> V_10 != V_10 ||
V_15 -> V_13 != V_13 )
if ( F_6 ( V_4 , V_20 ) )
V_7 = V_18 ;
}
return V_7 ;
}
static int T_4 F_7 ( void )
{
return F_8 ( & V_21 ) ;
}
static void T_5 F_9 ( void )
{
F_10 ( & V_21 ) ;
}
