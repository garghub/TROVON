static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
static bool T_1 F_4 ( void )
{
int V_2 ;
unsigned char * V_3 , * V_4 ;
bool V_5 = false ;
V_3 = F_5 ( V_6 , V_7 - 1 ) ;
if ( ! V_3 ) {
F_6 ( V_8 L_1 , V_9 ) ;
return V_5 ;
}
V_4 = V_3 + 0x20 ;
if ( memcmp ( V_4 , L_2 , 7 ) )
goto V_10;
for ( V_2 = 0 ; V_2 < F_3 ( V_11 ) ; V_2 ++ ) {
unsigned char * V_12 = V_3 + V_11 [ V_2 ] . V_13 ;
if ( ! memcmp ( V_12 , V_11 [ V_2 ] . V_14 , V_11 [ V_2 ] . V_15 ) ) {
F_6 ( V_16 L_3 ,
V_9 , V_12 ) ;
V_5 = true ;
break;
}
}
V_10:
F_7 ( V_3 ) ;
return V_5 ;
}
static int T_1 F_8 ( void )
{
if ( ! F_9 () )
return 0 ;
if ( ! F_4 () )
return 0 ;
F_1 () ;
return 0 ;
}
