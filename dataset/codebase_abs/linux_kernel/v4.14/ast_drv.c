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
F_9 () ;
F_10 ( V_7 , 0 ) ;
F_11 () ;
return error ;
}
static int F_16 ( struct V_6 * V_7 )
{
int V_8 ;
if ( F_17 ( V_7 -> V_2 ) )
return - V_9 ;
V_8 = F_12 ( V_7 ) ;
if ( V_8 )
return V_8 ;
F_18 ( V_7 ) ;
return 0 ;
}
static int F_19 ( struct V_10 * V_7 )
{
struct V_1 * V_2 = F_20 ( V_7 ) ;
struct V_6 * V_11 = F_4 ( V_2 ) ;
int error ;
error = F_6 ( V_11 ) ;
if ( error )
return error ;
F_21 ( V_2 ) ;
F_22 ( V_2 , V_12 ) ;
return 0 ;
}
static int F_23 ( struct V_10 * V_7 )
{
struct V_1 * V_2 = F_20 ( V_7 ) ;
struct V_6 * V_11 = F_4 ( V_2 ) ;
return F_16 ( V_11 ) ;
}
static int F_24 ( struct V_10 * V_7 )
{
struct V_1 * V_2 = F_20 ( V_7 ) ;
struct V_6 * V_11 = F_4 ( V_2 ) ;
if ( ! V_11 || ! V_11 -> V_13 )
return - V_14 ;
return F_6 ( V_11 ) ;
}
static int F_25 ( struct V_10 * V_7 )
{
struct V_1 * V_2 = F_20 ( V_7 ) ;
struct V_6 * V_11 = F_4 ( V_2 ) ;
return F_12 ( V_11 ) ;
}
static int F_26 ( struct V_10 * V_7 )
{
struct V_1 * V_2 = F_20 ( V_7 ) ;
struct V_6 * V_11 = F_4 ( V_2 ) ;
return F_6 ( V_11 ) ;
}
static int T_1 F_27 ( void )
{
if ( F_28 () && V_15 == - 1 )
return - V_16 ;
if ( V_15 == 0 )
return - V_16 ;
return F_29 ( & V_17 ) ;
}
static void T_2 F_30 ( void )
{
F_31 ( & V_17 ) ;
}
