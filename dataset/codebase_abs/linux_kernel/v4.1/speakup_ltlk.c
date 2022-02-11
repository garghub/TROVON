static void F_1 ( struct V_1 * V_2 )
{
unsigned char * V_3 , V_4 ;
unsigned char V_5 [ 50 ] , V_6 [ 20 ] ;
F_2 ( V_2 , L_1 ) ;
for ( V_4 = 0 ; V_4 < 50 ; V_4 ++ ) {
V_5 [ V_4 ] = F_3 () ;
if ( V_4 > 2 && V_5 [ V_4 ] == 0x7f )
break;
}
V_3 = V_5 + 2 ;
for ( V_4 = 0 ; * V_3 != '\r' ; V_3 ++ ) {
V_6 [ V_4 ] = * V_3 ;
if ( ++ V_4 >= 19 )
break;
}
V_6 [ V_4 ] = 0 ;
F_4 ( L_2 , V_2 -> V_7 , V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
V_8 = F_6 ( V_2 ) ;
if ( V_8 == 0 )
F_1 ( V_2 ) ;
V_2 -> V_9 = ! V_8 ;
return V_8 ;
}
