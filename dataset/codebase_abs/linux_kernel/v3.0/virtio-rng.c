static void F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 , & V_3 ) )
return;
F_3 ( & V_4 ) ;
}
static void F_4 ( T_1 * V_5 , T_2 V_6 )
{
struct V_7 V_8 ;
F_5 ( & V_8 , V_5 , V_6 ) ;
if ( F_6 ( V_2 , & V_8 , 0 , 1 , V_5 ) < 0 )
F_7 () ;
F_8 ( V_2 ) ;
}
static int F_9 ( struct V_9 * V_10 , void * V_5 , T_2 V_6 , bool V_11 )
{
if ( ! V_12 ) {
V_12 = true ;
F_10 ( & V_4 ) ;
F_4 ( V_5 , V_6 ) ;
}
if ( ! V_11 )
return 0 ;
F_11 ( & V_4 ) ;
V_12 = false ;
return V_3 ;
}
static void F_12 ( struct V_9 * V_10 )
{
if ( V_12 )
F_11 ( & V_4 ) ;
}
static int F_13 ( struct V_13 * V_14 )
{
int V_15 ;
V_2 = F_14 ( V_14 , F_1 , L_1 ) ;
if ( F_15 ( V_2 ) )
return F_16 ( V_2 ) ;
V_15 = F_17 ( & V_16 ) ;
if ( V_15 ) {
V_14 -> V_17 -> V_18 ( V_14 ) ;
return V_15 ;
}
return 0 ;
}
static void T_3 F_18 ( struct V_13 * V_14 )
{
V_14 -> V_17 -> V_19 ( V_14 ) ;
F_19 ( & V_16 ) ;
V_14 -> V_17 -> V_18 ( V_14 ) ;
}
static int T_4 F_20 ( void )
{
return F_21 ( & V_20 ) ;
}
static void T_5 F_22 ( void )
{
F_23 ( & V_20 ) ;
}
