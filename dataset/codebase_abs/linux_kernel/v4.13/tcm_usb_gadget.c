static int F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_3 ) )
F_3 ( V_3 ) ;
return 0 ;
}
static int F_4 ( struct V_4 * V_5 )
{
int V_6 ;
V_3 = F_5 ( V_7 ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
V_6 = F_8 ( V_5 , V_3 ) ;
if ( V_6 < 0 ) {
F_3 ( V_3 ) ;
return V_6 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_10 ( V_2 , V_9 ) ;
if ( V_8 )
return V_8 ;
V_10 . V_11 =
V_9 [ V_12 ] . V_13 ;
V_10 . V_14 = V_9 [ V_15 ] . V_13 ;
V_10 . V_16 =
V_9 [ V_17 ] . V_13 ;
V_18 . V_19 =
V_9 [ V_20 ] . V_13 ;
V_8 = F_11 ( V_2 , & V_18 , F_4 ) ;
if ( V_8 )
return V_8 ;
F_12 ( V_2 , & V_21 ) ;
return 0 ;
}
static int F_13 ( struct V_22 * V_23 )
{
return F_14 ( & V_24 ) ;
}
static void F_15 ( struct V_22 * V_23 )
{
F_16 ( & V_24 ) ;
}
static int T_1 F_17 ( void )
{
struct V_25 * V_26 ;
V_7 = F_18 ( L_1 ) ;
if ( F_6 ( V_7 ) )
return F_7 ( V_7 ) ;
V_26 = F_19 ( V_7 , struct V_25 , V_27 ) ;
F_20 ( & V_26 -> V_28 ) ;
V_26 -> V_29 = F_13 ;
V_26 -> V_30 = F_15 ;
V_26 -> V_31 = V_32 ;
V_26 -> V_33 = true ;
V_26 -> V_34 = true ;
F_21 ( & V_26 -> V_28 ) ;
V_7 -> V_35 ( V_7 , L_2 ) ;
return 0 ;
}
static void T_2 F_22 ( void )
{
if ( ! F_2 ( V_7 ) )
F_23 ( V_7 ) ;
}
