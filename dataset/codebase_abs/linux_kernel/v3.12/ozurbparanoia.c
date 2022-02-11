void F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
if ( V_4 < V_5 ) {
V_6 [ V_4 ++ ] = V_1 ;
F_3 ( V_7 , L_1 , V_4 , V_1 ) ;
} else {
F_3 ( V_7 , L_2 ) ;
}
F_4 ( & V_3 , V_2 ) ;
}
int F_5 ( struct V_1 * V_1 )
{
unsigned long V_2 ;
int V_8 ;
int V_9 = - 1 ;
F_2 ( & V_3 , V_2 ) ;
for ( V_8 = 0 ; V_8 < V_4 ; V_8 ++ ) {
if ( V_6 [ V_8 ] == V_1 ) {
V_9 = 0 ;
if ( -- V_4 > V_8 )
memcpy ( & V_6 [ V_8 ] , & V_6 [ V_8 + 1 ] ,
( V_4 - V_8 ) * sizeof( struct V_1 * ) ) ;
F_3 ( V_7 , L_3 , V_4 , V_1 ) ;
}
}
F_4 ( & V_3 , V_2 ) ;
return V_9 ;
}
