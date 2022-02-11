void T_1 F_1 ( void )
{
struct V_1 * * V_2 ;
F_2 () ;
for ( V_2 = V_3 ; V_2 < V_4 ; V_2 ++ ) {
if ( ( * V_2 ) -> V_5 && ( * V_2 ) -> V_5 () ) {
if ( V_1 != * V_2 ) {
V_1 = * V_2 ;
F_3 ( L_1 ,
V_1 -> V_6 ) ;
}
break;
}
}
if ( V_7 . V_8 )
V_7 . V_8 () ;
}
void F_4 ( int V_9 )
{
F_5 ( V_10 , V_9 , V_11 ) ;
}
int T_1 F_6 ( char * V_12 , char * V_13 )
{
struct V_1 * * V_2 ;
for ( V_2 = V_3 ; V_2 < V_4 ; V_2 ++ ) {
if ( ( * V_2 ) -> V_14 ( V_12 , V_13 ) ) {
if ( V_1 != * V_2 ) {
V_1 = * V_2 ;
F_3 ( L_2 ,
V_1 -> V_6 ) ;
}
return 1 ;
}
}
return 0 ;
}
