static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
bool V_5 = false ;
V_4 = F_2 ( 1 ) ;
if ( ! V_4 )
return - V_6 ;
V_4 -> V_7 [ 0 ] . V_8 = F_3 ( V_2 , 0 ) ;
V_4 -> V_7 [ 0 ] . V_9 = F_4 ( V_2 , 0 ) ;
#ifdef F_5
V_5 = V_2 -> V_10 [ V_11 ] . V_12 & V_13 ;
#endif
F_6 ( V_4 , L_1 , V_5 ) ;
F_7 ( V_4 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
const struct V_14 * V_15 )
{
int V_16 ;
V_16 = F_1 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return F_9 ( V_2 , V_15 , & V_17 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_11 ( V_2 ) ;
F_12 ( V_19 ) ;
}
static int F_13 ( struct V_20 * V_19 )
{
struct V_1 * V_2 = F_14 ( V_19 ) ;
struct V_18 * V_21 = F_11 ( V_2 ) ;
struct V_22 * V_23 = V_21 -> V_24 ;
F_15 ( V_21 ) ;
if ( V_23 -> V_25 . V_26 ) {
F_16 () ;
F_17 ( & V_23 -> V_25 . V_26 -> V_27 , 1 ) ;
F_18 () ;
}
return 0 ;
}
static int F_19 ( struct V_20 * V_19 )
{
struct V_1 * V_2 = F_14 ( V_19 ) ;
struct V_18 * V_21 = F_11 ( V_2 ) ;
struct V_22 * V_23 = V_21 -> V_24 ;
F_20 ( V_21 ) ;
if ( V_23 -> V_25 . V_26 ) {
F_16 () ;
F_17 ( & V_23 -> V_25 . V_26 -> V_27 , 0 ) ;
F_18 () ;
}
F_21 ( V_21 ) ;
return 0 ;
}
static int T_1 F_22 ( void )
{
if ( F_23 () && V_28 == - 1 )
return - V_29 ;
if ( V_28 == 0 )
return - V_29 ;
return F_24 ( & V_17 , & V_30 ) ;
}
static void T_2 F_25 ( void )
{
F_26 ( & V_17 , & V_30 ) ;
}
