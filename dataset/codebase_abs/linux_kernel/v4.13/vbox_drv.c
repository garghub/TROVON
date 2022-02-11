static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
return F_2 ( V_2 , V_4 , & V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
F_5 ( V_7 ) ;
}
static int F_6 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
F_7 ( V_7 ) ;
F_8 ( V_7 -> V_2 ) ;
F_9 ( & V_9 -> V_11 -> V_12 , true ) ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
F_11 ( V_7 ) ;
F_12 ( V_7 ) ;
F_9 ( & V_9 -> V_11 -> V_12 , false ) ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 )
{
int V_13 ;
if ( F_14 ( V_7 -> V_2 ) )
return - V_14 ;
V_13 = F_10 ( V_7 ) ;
if ( V_13 )
return V_13 ;
F_15 ( V_7 ) ;
return 0 ;
}
static int F_16 ( struct V_15 * V_7 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
struct V_6 * V_16 = F_4 ( V_2 ) ;
int error ;
error = F_6 ( V_16 ) ;
if ( error )
return error ;
F_18 ( V_2 ) ;
F_19 ( V_2 , V_17 ) ;
return 0 ;
}
static int F_20 ( struct V_15 * V_7 )
{
struct V_6 * V_16 = F_4 ( F_17 ( V_7 ) ) ;
return F_13 ( V_16 ) ;
}
static int F_21 ( struct V_15 * V_7 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
struct V_6 * V_16 = F_4 ( V_2 ) ;
if ( ! V_16 || ! V_16 -> V_10 )
return - V_18 ;
return F_6 ( V_16 ) ;
}
static int F_22 ( struct V_15 * V_7 )
{
struct V_6 * V_16 = F_4 ( F_17 ( V_7 ) ) ;
return F_10 ( V_16 ) ;
}
static int F_23 ( struct V_15 * V_7 )
{
struct V_6 * V_16 = F_4 ( F_17 ( V_7 ) ) ;
return F_6 ( V_16 ) ;
}
static int F_24 ( struct V_6 * V_7 ,
struct V_19 * V_20 , bool V_21 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
V_9 -> V_22 = false ;
F_25 ( & V_9 -> V_23 ) ;
F_26 ( V_9 ) ;
F_27 ( & V_9 -> V_23 ) ;
return 0 ;
}
static void F_28 ( struct V_6 * V_7 , struct V_19 * V_20 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
V_9 -> V_22 = false ;
F_25 ( & V_9 -> V_23 ) ;
F_26 ( V_9 ) ;
F_27 ( & V_9 -> V_23 ) ;
}
static int T_1 F_29 ( void )
{
#ifdef F_30
if ( F_31 () && V_24 == - 1 )
return - V_25 ;
#endif
if ( V_24 == 0 )
return - V_25 ;
return F_32 ( & V_5 , & V_26 ) ;
}
static void T_2 F_33 ( void )
{
F_34 ( & V_5 , & V_26 ) ;
}
