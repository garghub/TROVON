static T_1 F_1 ( struct V_1 * V_2 )
{
return ( T_1 ) F_2 ( V_3 + V_4 ) ;
}
static int T_2 F_3 ( void )
{
if ( ! F_4 () )
return - V_5 ;
if ( ! F_5 ( V_3 + V_4 ,
V_6 ,
L_1 ) ) {
F_6 (KERN_WARNING NAME L_2 ) ;
return - V_5 ;
}
F_7 ( V_7 | ( V_8 ? V_9 : 0 ) ,
V_3 + V_10 ) ;
if ( V_8 ) {
V_11 . V_12 = V_13 ;
V_11 . V_14 = F_8 ( ( V_15 + V_16 ) * 27 ,
V_11 . V_12 ) ;
} else {
V_11 . V_12 = V_17 ;
V_11 . V_14 = F_8 ( V_15 + V_16 ,
V_11 . V_12 ) ;
}
F_6 ( V_18 L_3 ,
V_8 ? L_4 : L_5 , V_16 ) ;
return F_9 ( & V_11 ) ;
}
