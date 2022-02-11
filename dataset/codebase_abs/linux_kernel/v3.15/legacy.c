static void F_1 ( void )
{
int V_1 ;
if ( V_2 <= 0 || V_2 > 0xff )
return;
F_2 ( L_1 ) ;
for ( V_1 = 0 ; V_1 <= V_2 ; V_1 ++ )
F_3 ( V_1 ) ;
}
int T_1 F_4 ( void )
{
if ( ! V_3 ) {
F_5 ( L_2 ) ;
return 0 ;
}
F_5 ( L_3 ) ;
F_6 ( 0 ) ;
return 0 ;
}
void F_3 ( int V_4 )
{
int V_5 ;
T_2 V_6 ;
if ( F_7 ( 0 , V_4 ) )
return;
for ( V_5 = 0 ; V_5 < 256 ; V_5 += 8 ) {
if ( ! F_8 ( 0 , V_4 , V_5 , V_7 , 2 , & V_6 ) &&
V_6 != 0x0000 && V_6 != 0xffff ) {
F_2 ( L_4 , V_4 , V_5 , V_6 ) ;
F_5 ( V_8 L_5 , V_4 ) ;
F_6 ( V_4 ) ;
return;
}
}
}
int T_1 F_9 ( void )
{
if ( V_9 . V_10 . V_11 () )
F_4 () ;
F_1 () ;
V_9 . V_10 . V_12 () ;
F_10 () ;
return 0 ;
}
