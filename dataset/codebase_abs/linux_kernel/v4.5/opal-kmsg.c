static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
int V_5 ;
T_1 V_6 ;
if ( V_4 != V_7 )
return;
if ( F_2 ( V_8 ) ) {
V_6 = F_3 ( 0 ) ;
if ( V_6 == V_9 || V_6 == V_10 )
return;
while ( F_3 ( 0 ) != V_11 ) ;
} else {
F_4 ( V_12 L_1 ) ;
for ( V_5 = 0 ; V_5 < 1024 ; V_5 ++ ) {
F_5 ( NULL ) ;
}
}
}
void T_2 F_6 ( void )
{
int V_13 ;
V_13 = F_7 ( & V_14 ) ;
if ( V_13 != 0 )
F_8 ( L_2 , V_13 ) ;
}
