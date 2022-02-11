static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
return & V_5 -> V_6 -> V_7 ;
}
static int F_2 ( struct V_1 * V_8 )
{
return & V_9 -> V_4 -> V_6 -> V_7 == V_8 ;
}
static int F_3 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_14 * V_14 = F_4 ( V_11 -> V_8 , struct V_14 , V_7 ) ;
T_1 V_15 = F_5 ( V_14 -> V_16 , 0 ) ;
T_2 V_17 = F_6 ( V_14 -> V_16 , 0 ) ;
if ( F_7 ( V_14 -> V_16 , V_18 ) ||
F_8 ( V_15 , F_9 () ) ) {
int V_19 = ( V_13 -> V_19 >> 6 ) & 7 ;
return ( V_19 << 6 ) | ( V_19 << 3 ) | V_19 ;
}
if ( F_10 ( V_17 ) ) {
int V_19 = ( V_13 -> V_19 >> 3 ) & 7 ;
return ( V_19 << 3 ) | V_19 ;
}
return V_13 -> V_19 ;
}
static int T_3 F_11 ( struct V_14 * V_14 )
{
F_12 ( & V_14 -> V_7 , & V_20 , F_2 ) ;
return 0 ;
}
static void T_4 F_13 ( struct V_14 * V_14 )
{
F_14 ( & V_14 -> V_7 ) ;
}
T_5 int F_15 ( void )
{
static struct V_12 V_21 [ 1 ] ;
int V_22 = - V_23 ;
V_24 = F_16 ( L_1 , V_21 ) ;
if ( ! V_24 )
goto V_25;
V_22 = F_17 ( & V_26 ) ;
if ( V_22 )
goto V_27;
F_18 ( & V_20 ) ;
V_25:
return V_22 ;
V_27:
F_19 ( V_24 ) ;
V_24 = NULL ;
goto V_25;
}
struct V_10 * F_20 ( struct V_14 * V_14 ,
const char * V_28 , struct V_12 * V_13 )
{
return F_21 ( & V_14 -> V_7 , V_28 , V_13 ) ;
}
void F_22 ( struct V_10 * V_29 )
{
F_19 ( V_29 ) ;
}
