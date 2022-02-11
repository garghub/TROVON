const struct V_1 * T_1 F_1 ( const char * V_2 )
{
const struct V_1 * * V_3 = V_4 ;
while ( * V_3 ) {
if ( ! strcmp ( V_2 , ( * V_3 ) -> V_2 ) )
return * V_3 ;
V_3 ++ ;
}
return NULL ;
}
int T_1 F_2 ( struct V_5 * V_6 , int V_7 )
{
const char * V_8 = F_3 ( V_6 , L_1 , NULL ) ;
if ( ! V_8 ) {
if ( V_7 != 0 )
F_4 ( L_2 ,
V_6 -> V_9 ) ;
return - V_10 ;
}
V_11 [ V_7 ] = F_1 ( V_8 ) ;
if ( ! V_11 [ V_7 ] ) {
F_5 ( L_3 ,
V_6 -> V_9 , V_8 ) ;
return - V_12 ;
}
return 0 ;
}
void T_1 F_6 ( void )
{
struct V_5 * V_6 = F_7 ( 0 , NULL ) ;
if ( ! V_6 ) {
F_4 ( L_4 ) ;
return;
}
F_2 ( V_6 , 0 ) ;
}
