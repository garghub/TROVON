static void T_1 F_1 ( void )
{
F_2 () ;
F_3 ( V_1 , F_4 ( V_1 ) ) ;
}
static void F_5 ( enum V_2 V_3 , const char * V_4 )
{
struct V_5 * V_6 ;
void T_2 * V_7 ;
int V_8 ;
V_6 = F_6 ( NULL , NULL , L_1 ) ;
if ( ! V_6 ) {
F_7 ( L_2 ) ;
return;
}
V_7 = F_8 ( V_6 , 0 ) ;
if ( ! V_7 ) {
F_7 ( L_3 ) ;
return;
}
if ( F_9 ( V_6 , L_4 , & V_8 ) < 0 ) {
F_7 ( L_5 ) ;
return;
}
F_10 ( 0xdeadbeef , V_7 + V_8 ) ;
while ( 1 )
F_11 () ;
}
