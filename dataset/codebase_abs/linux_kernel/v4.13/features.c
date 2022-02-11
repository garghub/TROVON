void F_1 ( void )
{
struct V_1 V_2 ;
int V_3 , V_4 ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
V_2 . V_6 = V_3 ;
if ( F_2 ( V_7 , & V_2 ) < 0 )
break;
for ( V_4 = 0 ; V_4 < 32 ; V_4 ++ )
V_8 [ V_3 * 32 + V_4 ] = ! ! ( V_2 . V_9 & 1 << V_4 ) ;
}
}
