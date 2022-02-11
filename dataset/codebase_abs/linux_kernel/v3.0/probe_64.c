static int F_1 ( int V_1 , int V_2 )
{
return F_2 () >> V_2 ;
}
void T_1 F_3 ( void )
{
struct V_3 * * V_4 ;
F_4 () ;
for ( V_4 = V_5 ; V_4 < V_6 ; V_4 ++ ) {
if ( ( * V_4 ) -> V_7 && ( * V_4 ) -> V_7 () ) {
if ( V_3 != * V_4 ) {
V_3 = * V_4 ;
F_5 ( L_1 ,
V_3 -> V_8 ) ;
}
break;
}
}
if ( F_6 () ) {
V_3 -> V_9 = F_1 ;
}
}
void F_7 ( int V_10 )
{
F_8 ( V_11 , V_10 , V_12 ) ;
}
int T_1 F_9 ( char * V_13 , char * V_14 )
{
struct V_3 * * V_4 ;
for ( V_4 = V_5 ; V_4 < V_6 ; V_4 ++ ) {
if ( ( * V_4 ) -> V_15 ( V_13 , V_14 ) ) {
if ( V_3 != * V_4 ) {
V_3 = * V_4 ;
F_5 ( L_2 ,
V_3 -> V_8 ) ;
}
return 1 ;
}
}
return 0 ;
}
