static void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static int T_1 F_3 ( void )
{
int V_2 ;
unsigned char * V_3 , * V_4 ;
if ( ! F_4 () )
return 0 ;
V_3 = F_5 ( 0xffff0000 , 0xffff ) ;
if ( ! V_3 ) {
F_6 ( V_5 L_1 ) ;
return 0 ;
}
V_4 = V_3 + 0x20 ;
if ( strncmp ( V_4 , L_2 , 7 ) )
goto V_6;
for ( V_2 = 0 ; V_2 < F_7 ( V_7 ) ; V_2 ++ ) {
unsigned char * V_8 = V_3 + V_7 [ V_2 ] . V_9 ;
if ( strncmp ( V_8 , V_7 [ V_2 ] . V_10 , V_7 [ V_2 ] . V_11 ) == 0 ) {
F_6 ( V_5 L_3 , V_8 , V_4 ) ;
if ( V_7 [ V_2 ] . V_12 )
V_7 [ V_2 ] . V_12 () ;
break;
}
}
V_6:
F_8 ( V_3 ) ;
return 0 ;
}
