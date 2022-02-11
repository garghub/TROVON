int T_1 F_1 ( void )
{
int V_1 = 0 ;
struct V_2 * * V_3 ;
if ( ! ( V_4 -> V_5 & V_6 ) )
return - V_7 ;
for ( V_3 = V_8 ; * V_3 ; V_3 ++ ) {
V_1 = F_2 ( * V_3 ) ;
F_3 ( V_9 L_1 ,
( * V_3 ) -> V_10 , V_1 ) ;
if ( V_1 ) {
for ( V_3 -- ; V_3 >= V_8 ; V_3 -- )
F_4 ( * V_3 ) ;
break;
}
}
if ( V_1 )
return V_1 ;
V_1 = F_5 ( & V_11 ) ;
if ( V_1 ) {
for ( V_3 = V_8 ; * V_3 ; V_3 ++ )
F_4 ( * V_3 ) ;
}
return V_1 ;
}
void T_2 F_6 ( void )
{
struct V_2 * * V_3 ;
for ( V_3 = V_8 ; * V_3 ; V_3 ++ ) {
F_3 ( V_9 L_2 , ( * V_3 ) -> V_10 ) ;
F_4 ( * V_3 ) ;
}
F_7 ( & V_11 ) ;
}
