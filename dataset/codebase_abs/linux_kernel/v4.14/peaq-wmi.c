static void F_1 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
T_1 V_5 ;
T_2 V_6 = 0 ;
struct V_7 V_8 = { sizeof( V_6 ) , & V_6 } ;
struct V_7 V_9 = { sizeof( V_4 ) , & V_4 } ;
V_5 = F_2 ( V_10 , 0 ,
V_11 ,
& V_8 , & V_9 ) ;
if ( F_3 ( V_5 ) )
return;
if ( V_4 . type != V_12 ) {
F_4 ( & V_13 -> V_8 -> V_2 ,
L_1 ) ;
return;
}
if ( V_14 && V_14 -- )
return;
if ( V_4 . integer . V_15 ) {
F_5 ( V_13 -> V_8 , V_16 , V_17 , 1 ) ;
F_6 ( V_13 -> V_8 ) ;
F_5 ( V_13 -> V_8 , V_16 , V_17 , 0 ) ;
F_6 ( V_13 -> V_8 ) ;
V_14 = F_7 ( 1u ,
V_18 / V_13 -> V_19 ) ;
}
}
static int T_3 F_8 ( void )
{
if ( ! F_9 ( V_10 ) )
return - V_20 ;
V_13 = F_10 () ;
if ( ! V_13 )
return - V_21 ;
V_13 -> V_22 = F_1 ;
V_13 -> V_19 = V_23 ;
V_13 -> V_24 = V_25 ;
V_13 -> V_8 -> V_26 = L_2 ;
V_13 -> V_8 -> V_27 = L_3 ;
V_13 -> V_8 -> V_28 . V_29 = V_30 ;
F_11 ( V_13 -> V_8 , V_16 , V_17 ) ;
return F_12 ( V_13 ) ;
}
static void T_4 F_13 ( void )
{
if ( ! F_9 ( V_10 ) )
return;
F_14 ( V_13 ) ;
}
