static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
if ( ( V_5 = F_2 ( V_2 ) ) ) {
F_3 ( V_6 L_1 ,
F_4 ( V_2 ) ) ;
return V_5 ;
}
V_7 . V_8 = & V_2 -> V_8 ;
V_7 . V_9 = V_2 -> V_10 -> V_11 [ 0 ] ;
V_7 . V_12 = V_2 -> V_10 -> V_11 [ 0 ] -> V_13 ;
V_7 . V_14 = V_15 ;
V_7 . V_16 = V_2 -> V_16 ;
F_5 ( V_7 . V_8 , & V_7 ) ;
if ( F_6 ( & V_7 ) ) {
F_3 ( V_6 L_2 ) ;
return - 1 ;
}
return 0 ;
}
static int T_1 F_7 ( void )
{
return F_8 ( & V_17 ) ;
}
