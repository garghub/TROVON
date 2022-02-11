static void F_1 ( unsigned char V_1 , char V_2 )
{
if ( V_1 < 0x72 ) {
V_1 = V_3 [ V_1 ] ;
if ( V_1 == V_4 ) {
F_2 ( V_5 , V_1 , 1 ) ;
F_2 ( V_5 , V_1 , 0 ) ;
F_3 ( V_5 ) ;
} else {
F_2 ( V_5 , V_1 , V_2 ) ;
F_3 ( V_5 ) ;
}
} else
F_4 ( V_6 L_1 , V_1 ) ;
return;
}
static int T_1 F_5 ( void )
{
int V_7 , error ;
if ( ! V_8 || ! F_6 ( V_9 ) )
return - V_10 ;
error = F_7 () ;
if ( error )
return error ;
V_5 = F_8 () ;
if ( ! V_5 )
return - V_11 ;
V_5 -> V_12 = L_2 ;
V_5 -> V_13 = L_3 ;
V_5 -> V_14 . V_15 = V_16 ;
V_5 -> V_14 . V_17 = 0x0001 ;
V_5 -> V_14 . V_18 = 0x0001 ;
V_5 -> V_14 . V_19 = 0x0100 ;
V_5 -> V_20 [ 0 ] = F_9 ( V_21 ) | F_9 ( V_22 ) ;
V_5 -> V_23 = V_3 ;
V_5 -> V_24 = sizeof( unsigned char ) ;
V_5 -> V_25 = F_10 ( V_3 ) ;
for ( V_7 = 1 ; V_7 < 0x72 ; V_7 ++ ) {
F_11 ( V_3 [ V_7 ] , V_5 -> V_26 ) ;
}
error = F_12 ( V_5 ) ;
if ( error ) {
F_13 ( V_5 ) ;
return error ;
}
V_27 = F_1 ;
return 0 ;
}
static void T_2 F_14 ( void )
{
V_27 = NULL ;
F_15 ( V_5 ) ;
}
