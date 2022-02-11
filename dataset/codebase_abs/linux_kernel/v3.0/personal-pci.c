static int T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
unsigned char line ;
F_2 ( V_2 , V_5 , & line ) ;
if ( line > 0x40 && line <= 0x5f ) {
return V_6 [ ( line & 0x1f ) - 8 ] ;
} else if ( line == 0 ) {
return 0 ;
} else
return V_6 [ ( line - 1 ) & 3 ] ;
}
static int T_1 F_3 ( void )
{
if ( F_4 () )
F_5 ( & V_7 ) ;
return 0 ;
}
