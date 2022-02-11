static bool
F_1 ( const struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 ) ;
return ( V_3 & V_2 -> V_5 ) == V_2 -> V_6 ;
}
void F_3 ( const struct V_1 * V_7 ,
const char * V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_7 [ V_9 ] . V_10 ; V_9 ++ ) {
if ( ! V_7 [ V_9 ] . F_4 ( & V_7 [ V_9 ] ) )
continue;
if ( ! F_5 ( V_7 [ V_9 ] . V_11 ) )
F_6 ( L_1 , V_8 , V_7 [ V_9 ] . V_10 ) ;
F_7 ( V_7 [ V_9 ] . V_11 ) ;
}
}
void F_8 ( void )
{
F_3 ( V_12 , L_2 ) ;
}
