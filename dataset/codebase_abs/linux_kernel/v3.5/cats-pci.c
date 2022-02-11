static T_1 F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
return 0 ;
}
static int T_2 F_2 ( const struct V_1 * V_2 , T_1 V_4 , T_1 V_3 )
{
if ( V_2 -> V_5 >= 255 )
return - 1 ;
if ( V_2 -> V_5 >= 128 )
return V_2 -> V_5 & 0x1f ;
if ( V_2 -> V_5 >= 1 && V_2 -> V_5 <= 4 )
return V_6 [ V_2 -> V_5 - 1 ] ;
if ( V_2 -> V_5 != 0 )
F_3 ( L_1 ,
V_2 -> V_7 -> V_8 , V_2 -> V_9 , V_2 -> V_5 ) ;
return - 1 ;
}
static int T_2 F_4 ( void )
{
if ( F_5 () )
F_6 ( & V_10 ) ;
return 0 ;
}
