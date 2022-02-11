static int T_1 F_1 ( void )
{
F_2 ( NULL , V_1 , NULL ) ;
return 0 ;
}
static void T_1 F_3 ( void )
{
const T_2 * V_2 ;
int V_3 ;
V_4 = F_4 ( NULL , NULL , L_1 ) ;
if ( V_4 == NULL ) {
F_5 ( V_5 L_2 ) ;
return;
}
V_6 = F_6 ( V_4 , 0 ) ;
if ( V_6 == NULL ) {
F_5 ( V_5 L_3 ) ;
return;
}
V_2 = F_7 ( V_4 , L_4 , NULL ) ;
if ( V_2 == NULL )
return;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
T_2 V_7 = V_2 [ V_3 ] ;
F_8 ( V_6 + V_8 , V_3 ) ;
F_8 ( V_6 + V_9 , V_7 ) ;
}
F_9 ( V_6 + V_8 ) ;
F_10 () ;
F_8 ( V_6 + V_10 , 0xfe ) ;
}
static void T_1 F_11 ( void )
{
F_3 () ;
F_12 ( V_11 ) ;
}
static int T_1 F_13 ( void )
{
if ( ! F_14 ( L_5 ) )
return 0 ;
return 1 ;
}
