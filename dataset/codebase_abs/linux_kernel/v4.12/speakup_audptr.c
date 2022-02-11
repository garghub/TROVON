static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 -> V_4 ( V_5 ) ;
V_2 -> V_3 -> V_6 ( V_2 , V_7 ) ;
}
static void F_2 ( struct V_1 * V_2 )
{
unsigned char V_8 = 0 ;
char V_9 [ 40 ] = L_1 ;
V_2 -> V_10 ( V_2 , L_2 ) ;
V_9 [ V_8 ] = F_3 () ;
if ( V_9 [ V_8 ] == 'A' ) {
do {
V_9 [ ++ V_8 ] = F_3 () ;
} while ( V_9 [ V_8 ] != '\n' && V_8 < 32 );
V_9 [ ++ V_8 ] = 0x00 ;
}
if ( V_9 [ 0 ] == 'A' )
F_4 ( L_3 , V_2 -> V_11 , V_9 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_6 ( V_2 ) ;
if ( V_12 == 0 )
F_2 ( V_2 ) ;
V_2 -> V_13 = ! V_12 ;
return 0 ;
}
