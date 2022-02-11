static int T_1 F_1 ( const struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
if ( V_2 -> V_5 >= 255 )
return - 1 ;
if ( V_2 -> V_5 >= 128 )
return V_2 -> V_5 & 0x1f ;
if ( V_2 -> V_5 >= 1 && V_2 -> V_5 <= 4 )
return V_6 [ V_2 -> V_5 - 1 ] ;
if ( V_2 -> V_5 != 0 )
F_2 ( L_1 ,
V_2 -> V_7 -> V_8 , V_2 -> V_9 , V_2 -> V_5 ) ;
return - 1 ;
}
static int T_1 F_3 ( void )
{
if ( F_4 () )
F_5 ( & V_10 ) ;
return 0 ;
}
