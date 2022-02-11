static void F_1 ( void )
{
V_1 . V_2 = V_3 ;
V_1 . V_4 = 3 ;
V_5 . V_6 = V_7 ;
V_5 . V_8 = V_9 ;
V_10 [ V_11 ] = & V_12 . V_13 ;
V_10 [ V_14 ] = & V_15 ;
V_10 [ V_16 ] =
& V_17 . V_13 ;
V_10 [ V_18 ] =
& V_19 . V_13 ;
}
static int F_2 ( struct V_20 * V_21 )
{
struct V_22 * V_22 ;
struct V_23 * V_24 = & V_21 -> V_24 ;
bool V_25 ;
const struct V_26 * V_27 ;
V_27 = F_3 ( V_28 , V_24 ) ;
if ( ! V_27 )
return - V_29 ;
V_25 = ! ! ( V_27 -> V_30 ) ;
if ( V_25 )
F_1 () ;
V_22 = F_4 ( V_24 , L_1 , NULL , V_31 , 19200000 ) ;
if ( F_5 ( V_22 ) )
return F_6 ( V_22 ) ;
V_22 = F_4 ( V_24 , L_2 , NULL ,
V_31 , 32768 ) ;
if ( F_5 ( V_22 ) )
return F_6 ( V_22 ) ;
return F_7 ( V_21 , & V_32 ) ;
}
static int T_1 F_8 ( void )
{
return F_9 ( & V_33 ) ;
}
static void T_2 F_10 ( void )
{
F_11 ( & V_33 ) ;
}
