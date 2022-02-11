static void F_1 ( struct V_1 * V_2 )
{
unsigned char * V_3 , V_4 ;
unsigned char V_5 [ 50 ] , V_6 [ 20 ] ;
V_2 -> V_7 ( V_2 , L_1 ) ;
for ( V_4 = 0 ; V_4 < 50 ; V_4 ++ ) {
V_5 [ V_4 ] = V_2 -> V_8 -> V_9 () ;
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
F_2 ( L_2 , V_2 -> V_10 , V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_11 = 0 ;
V_11 = F_4 ( V_2 ) ;
if ( V_11 == 0 )
F_1 ( V_2 ) ;
V_2 -> V_12 = ! V_11 ;
return V_11 ;
}
