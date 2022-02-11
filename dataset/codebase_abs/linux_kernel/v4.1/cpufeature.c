void F_1 ( const struct V_1 * V_2 ,
const char * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_2 [ V_4 ] . V_5 ; V_4 ++ ) {
if ( ! V_2 [ V_4 ] . F_2 ( & V_2 [ V_4 ] ) )
continue;
if ( ! F_3 ( V_2 [ V_4 ] . V_6 ) )
F_4 ( L_1 , V_3 , V_2 [ V_4 ] . V_5 ) ;
F_5 ( V_2 [ V_4 ] . V_6 ) ;
}
}
void F_6 ( void )
{
F_1 ( V_7 , L_2 ) ;
}
