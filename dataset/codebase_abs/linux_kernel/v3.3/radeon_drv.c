static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 * V_4 = V_2 -> V_5 ;
if ( ( V_4 -> V_6 & V_7 ) >= V_8 )
return 0 ;
if ( ( V_4 -> V_6 & V_7 ) >= V_9 )
F_2 ( V_10 , 0 ) ;
F_2 ( V_11 , 0 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
T_2 * V_4 = V_2 -> V_5 ;
if ( ( V_4 -> V_6 & V_7 ) >= V_8 )
return 0 ;
if ( ( V_4 -> V_6 & V_7 ) >= V_9 )
F_2 ( V_10 , V_4 -> V_12 ) ;
F_2 ( V_11 , V_4 -> V_13 ) ;
return 0 ;
}
static void F_4 ( struct V_14 * V_15 )
{
struct V_16 * V_17 ;
bool V_18 = false ;
V_17 = F_5 ( 1 ) ;
V_17 -> V_19 [ 0 ] . V_20 = F_6 ( V_15 , 0 ) ;
V_17 -> V_19 [ 0 ] . V_21 = F_7 ( V_15 , 0 ) ;
#ifdef F_8
V_18 = V_15 -> V_22 [ V_23 ] . V_6 & V_24 ;
#endif
F_9 ( V_17 , L_1 , V_18 ) ;
F_10 ( V_17 ) ;
}
static int T_3
F_11 ( struct V_14 * V_15 , const struct V_25 * V_26 )
{
F_4 ( V_15 ) ;
return F_12 ( V_15 , V_26 , & V_27 ) ;
}
static void
F_13 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_14 ( V_15 ) ;
F_15 ( V_2 ) ;
}
static int
F_16 ( struct V_14 * V_15 , T_1 V_3 )
{
struct V_1 * V_2 = F_14 ( V_15 ) ;
return F_17 ( V_2 , V_3 ) ;
}
static int
F_18 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_14 ( V_15 ) ;
return F_19 ( V_2 ) ;
}
static int T_4 F_20 ( void )
{
V_28 = & V_29 ;
V_30 = & V_31 ;
V_28 -> V_32 = V_33 ;
#ifdef F_21
if ( F_22 () && V_34 == - 1 ) {
F_23 ( L_2 ) ;
V_28 = & V_29 ;
V_30 = & V_31 ;
V_28 -> V_35 &= ~ V_36 ;
V_34 = 0 ;
}
#endif
if ( V_34 == - 1 ) {
#ifdef F_24
F_23 ( L_3 ) ;
V_34 = 1 ;
#else
F_23 ( L_4 ) ;
V_34 = 0 ;
#endif
}
if ( V_34 == 1 ) {
F_23 ( L_5 ) ;
V_28 = & V_27 ;
V_30 = & V_37 ;
V_28 -> V_35 |= V_36 ;
V_28 -> V_32 = V_38 ;
F_25 () ;
}
return F_26 ( V_28 , V_30 ) ;
}
static void T_5 F_27 ( void )
{
F_28 ( V_28 , V_30 ) ;
F_29 () ;
}
