static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
return F_2 ( V_2 , V_4 , & V_5 ) ;
}
static void
F_3 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
F_5 ( V_7 ) ;
}
static int F_6 ( struct V_6 * V_7 )
{
F_7 ( V_7 ) ;
F_8 ( V_7 -> V_2 ) ;
F_9 () ;
F_10 ( V_7 , 1 ) ;
F_11 () ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 )
{
int error = 0 ;
F_13 ( V_7 ) ;
F_14 ( V_7 ) ;
F_15 ( V_7 ) ;
F_16 ( V_7 ) ;
F_17 ( V_7 ) ;
F_9 () ;
F_10 ( V_7 , 0 ) ;
F_11 () ;
return error ;
}
static int F_18 ( struct V_6 * V_7 )
{
int V_8 ;
if ( F_19 ( V_7 -> V_2 ) )
return - V_9 ;
V_8 = F_12 ( V_7 ) ;
if ( V_8 )
return V_8 ;
F_20 ( V_7 ) ;
return 0 ;
}
static int F_21 ( struct V_10 * V_7 )
{
struct V_1 * V_2 = F_22 ( V_7 ) ;
struct V_6 * V_11 = F_4 ( V_2 ) ;
int error ;
error = F_6 ( V_11 ) ;
if ( error )
return error ;
F_23 ( V_2 ) ;
F_24 ( V_2 , V_12 ) ;
return 0 ;
}
static int F_25 ( struct V_10 * V_7 )
{
struct V_1 * V_2 = F_22 ( V_7 ) ;
struct V_6 * V_11 = F_4 ( V_2 ) ;
return F_18 ( V_11 ) ;
}
static int F_26 ( struct V_10 * V_7 )
{
struct V_1 * V_2 = F_22 ( V_7 ) ;
struct V_6 * V_11 = F_4 ( V_2 ) ;
if ( ! V_11 || ! V_11 -> V_13 )
return - V_14 ;
return F_6 ( V_11 ) ;
}
static int F_27 ( struct V_10 * V_7 )
{
struct V_1 * V_2 = F_22 ( V_7 ) ;
struct V_6 * V_11 = F_4 ( V_2 ) ;
return F_12 ( V_11 ) ;
}
static int F_28 ( struct V_10 * V_7 )
{
struct V_1 * V_2 = F_22 ( V_7 ) ;
struct V_6 * V_11 = F_4 ( V_2 ) ;
return F_6 ( V_11 ) ;
}
static int T_1 F_29 ( void )
{
#ifdef F_30
if ( F_31 () && V_15 == - 1 )
return - V_16 ;
#endif
if ( V_15 == 0 )
return - V_16 ;
return F_32 ( & V_5 , & V_17 ) ;
}
static void T_2 F_33 ( void )
{
F_34 ( & V_5 , & V_17 ) ;
}
