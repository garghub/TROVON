static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 -> V_4 () ;
V_2 -> V_3 -> V_5 ( V_6 ) ;
V_2 -> V_3 -> V_7 ( V_2 , V_8 ) ;
}
static void F_2 ( struct V_1 * V_2 )
{
unsigned char V_9 = 0 ;
char V_10 [ 40 ] = L_1 ;
V_2 -> V_11 ( V_2 , L_2 ) ;
V_10 [ V_9 ] = V_2 -> V_3 -> V_12 () ;
if ( V_10 [ V_9 ] == 'A' ) {
do {
V_10 [ ++ V_9 ] = V_2 -> V_3 -> V_12 () ;
} while ( V_10 [ V_9 ] != '\n' && V_9 < 32 );
V_10 [ ++ V_9 ] = 0x00 ;
}
if ( V_10 [ 0 ] == 'A' )
F_3 ( L_3 , V_2 -> V_13 , V_10 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_14 ;
V_14 = F_5 ( V_2 ) ;
if ( V_14 == 0 )
F_2 ( V_2 ) ;
V_2 -> V_15 = ! V_14 ;
return 0 ;
}
