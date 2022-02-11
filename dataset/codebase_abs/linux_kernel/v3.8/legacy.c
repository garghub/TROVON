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
V_4 = F_6 ( 0 ) ;
return 0 ;
}
void F_3 ( int V_5 )
{
int V_6 ;
long V_7 ;
T_2 V_8 ;
if ( F_7 ( 0 , V_5 ) )
return;
V_7 = F_8 ( V_5 ) ;
for ( V_6 = 0 ; V_6 < 256 ; V_6 += 8 ) {
if ( ! F_9 ( 0 , V_5 , V_6 , V_9 , 2 , & V_8 ) &&
V_8 != 0x0000 && V_8 != 0xffff ) {
F_2 ( L_4 , V_5 , V_6 , V_8 ) ;
F_5 ( V_10 L_5 , V_5 ) ;
F_10 ( V_5 , & V_11 , V_7 ) ;
return;
}
}
}
int T_1 F_11 ( void )
{
if ( V_12 . V_13 . V_14 () )
F_4 () ;
F_1 () ;
V_12 . V_13 . V_15 () ;
F_12 () ;
return 0 ;
}
