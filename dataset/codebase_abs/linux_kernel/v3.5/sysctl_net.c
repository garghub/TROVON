static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
return & V_5 -> V_6 -> V_7 ;
}
static int F_2 ( struct V_1 * V_8 )
{
return & V_9 -> V_4 -> V_6 -> V_7 == V_8 ;
}
static int F_3 ( struct V_2 * V_3 ,
struct V_4 * V_4 ,
struct V_10 * V_11 )
{
if ( F_4 ( V_12 ) ) {
int V_13 = ( V_11 -> V_13 >> 6 ) & 7 ;
return ( V_13 << 6 ) | ( V_13 << 3 ) | V_13 ;
}
return V_11 -> V_13 ;
}
static int T_1 F_5 ( struct V_14 * V_14 )
{
F_6 ( & V_14 -> V_7 , & V_15 , F_2 ) ;
return 0 ;
}
static void T_2 F_7 ( struct V_14 * V_14 )
{
F_8 ( & V_14 -> V_7 ) ;
}
T_3 int F_9 ( void )
{
static struct V_10 V_16 [ 1 ] ;
int V_17 = - V_18 ;
V_19 = F_10 ( L_1 , V_16 ) ;
if ( ! V_19 )
goto V_20;
V_17 = F_11 ( & V_21 ) ;
if ( V_17 )
goto V_20;
F_12 ( & V_15 ) ;
V_20:
return V_17 ;
}
struct V_22 * F_13 ( struct V_14 * V_14 ,
const char * V_23 , struct V_10 * V_11 )
{
return F_14 ( & V_14 -> V_7 , V_23 , V_11 ) ;
}
void F_15 ( struct V_22 * V_24 )
{
F_16 ( V_24 ) ;
}
