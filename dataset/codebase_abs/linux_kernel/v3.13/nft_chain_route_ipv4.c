static unsigned int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_2)( struct V_3 * ) )
{
unsigned int V_8 ;
struct V_9 V_10 ;
T_1 V_11 ;
T_2 V_12 , V_13 ;
T_3 V_14 ;
const struct V_15 * V_16 ;
if ( V_4 -> V_17 < sizeof( struct V_15 ) ||
F_3 ( V_4 ) < sizeof( struct V_15 ) )
return V_18 ;
F_4 ( & V_10 , V_2 , V_4 , V_6 , V_7 ) ;
V_11 = V_4 -> V_11 ;
V_16 = F_5 ( V_4 ) ;
V_12 = V_16 -> V_12 ;
V_13 = V_16 -> V_13 ;
V_14 = V_16 -> V_14 ;
V_8 = F_6 ( & V_10 , V_2 ) ;
if ( V_8 != V_19 && V_8 != V_20 ) {
V_16 = F_5 ( V_4 ) ;
if ( V_16 -> V_12 != V_12 ||
V_16 -> V_13 != V_13 ||
V_4 -> V_11 != V_11 ||
V_16 -> V_14 != V_14 )
if ( F_7 ( V_4 , V_21 ) )
V_8 = V_19 ;
}
return V_8 ;
}
static int T_4 F_8 ( void )
{
return F_9 ( & V_22 ) ;
}
static void T_5 F_10 ( void )
{
F_11 ( & V_22 ) ;
}
