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
if ( F_6 ( V_2 , & V_8 , 0 , 1 , V_5 , V_9 ) < 0 )
F_7 () ;
F_8 ( V_2 ) ;
}
static int F_9 ( struct V_10 * V_11 , void * V_5 , T_2 V_6 , bool V_12 )
{
int V_13 ;
if ( ! V_14 ) {
V_14 = true ;
F_10 ( & V_4 ) ;
F_4 ( V_5 , V_6 ) ;
}
if ( ! V_12 )
return 0 ;
V_13 = F_11 ( & V_4 ) ;
if ( V_13 < 0 )
return V_13 ;
V_14 = false ;
return V_3 ;
}
static void F_12 ( struct V_10 * V_11 )
{
if ( V_14 )
F_13 ( & V_4 ) ;
}
static int F_14 ( struct V_15 * V_16 )
{
int V_17 ;
V_2 = F_15 ( V_16 , F_1 , L_1 ) ;
if ( F_16 ( V_2 ) )
return F_17 ( V_2 ) ;
V_17 = F_18 ( & V_18 ) ;
if ( V_17 ) {
V_16 -> V_19 -> V_20 ( V_16 ) ;
return V_17 ;
}
return 0 ;
}
static void F_19 ( struct V_15 * V_16 )
{
V_16 -> V_19 -> V_21 ( V_16 ) ;
V_14 = false ;
F_20 ( & V_18 ) ;
V_16 -> V_19 -> V_20 ( V_16 ) ;
}
static int F_21 ( struct V_15 * V_16 )
{
return F_14 ( V_16 ) ;
}
static void T_3 F_22 ( struct V_15 * V_16 )
{
F_19 ( V_16 ) ;
}
static int F_23 ( struct V_15 * V_16 )
{
F_19 ( V_16 ) ;
return 0 ;
}
static int F_24 ( struct V_15 * V_16 )
{
return F_14 ( V_16 ) ;
}
static int T_4 F_25 ( void )
{
return F_26 ( & V_22 ) ;
}
static void T_5 F_27 ( void )
{
F_28 ( & V_22 ) ;
}
