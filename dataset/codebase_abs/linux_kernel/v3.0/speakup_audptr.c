static void F_1 ( struct V_1 * V_2 )
{
int V_3 = V_4 ;
while ( F_2 () ) {
if ( ! -- V_3 )
break;
F_3 ( 1 ) ;
}
F_4 ( V_5 , V_6 . V_7 ) ;
F_5 ( V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned char V_9 = 0 ;
char V_10 [ 40 ] = L_1 ;
F_7 ( V_2 , L_2 ) ;
V_10 [ V_9 ] = F_8 () ;
if ( V_10 [ V_9 ] == 'A' ) {
do {
V_10 [ ++ V_9 ] = F_8 () ;
} while ( V_10 [ V_9 ] != '\n' && V_9 < 32 );
V_10 [ ++ V_9 ] = 0x00 ;
}
if ( V_10 [ 0 ] == 'A' )
F_9 ( L_3 , V_2 -> V_11 , V_10 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
V_12 = F_11 ( V_2 ) ;
if ( V_12 == 0 )
F_6 ( V_2 ) ;
V_2 -> V_13 = ! V_12 ;
return 0 ;
}
static int T_1 F_12 ( void )
{
return F_13 ( & V_14 ) ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_14 ) ;
}
