static unsigned int F_1 ( void * V_1 ,
struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
unsigned int V_6 ;
struct V_7 V_8 ;
T_1 V_9 ;
T_2 V_10 , V_11 ;
T_3 V_12 ;
const struct V_13 * V_14 ;
int V_15 ;
if ( V_3 -> V_16 < sizeof( struct V_13 ) ||
F_2 ( V_3 ) < sizeof( struct V_13 ) )
return V_17 ;
F_3 ( & V_8 , V_3 , V_5 ) ;
V_9 = V_3 -> V_9 ;
V_14 = F_4 ( V_3 ) ;
V_10 = V_14 -> V_10 ;
V_11 = V_14 -> V_11 ;
V_12 = V_14 -> V_12 ;
V_6 = F_5 ( & V_8 , V_1 ) ;
if ( V_6 != V_18 && V_6 != V_19 ) {
V_14 = F_4 ( V_3 ) ;
if ( V_14 -> V_10 != V_10 ||
V_14 -> V_11 != V_11 ||
V_3 -> V_9 != V_9 ||
V_14 -> V_12 != V_12 ) {
V_15 = F_6 ( V_5 -> V_20 , V_3 , V_21 ) ;
if ( V_15 < 0 )
V_6 = F_7 ( V_15 ) ;
}
}
return V_6 ;
}
static int T_4 F_8 ( void )
{
return F_9 ( & V_22 ) ;
}
static void T_5 F_10 ( void )
{
F_11 ( & V_22 ) ;
}
