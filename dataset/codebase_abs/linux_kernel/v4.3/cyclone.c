void T_1 F_1 ( void )
{
V_1 = 1 ;
}
static T_2 F_2 ( struct V_2 * V_3 )
{
return ( T_2 ) F_3 ( ( void V_4 * ) V_5 ) ;
}
int T_1 F_4 ( void )
{
T_3 V_4 * V_6 ;
T_3 V_7 ;
T_3 V_8 ;
int V_9 ;
T_4 V_4 * V_10 ;
if ( ! V_1 )
return 0 ;
F_5 ( V_11 L_1 ) ;
V_8 = ( V_12 ) ;
V_6 = F_6 ( V_8 , sizeof( T_3 ) ) ;
if( ! V_6 ) {
F_5 ( V_13 L_2
L_3 ) ;
V_1 = 0 ;
return - V_14 ;
}
V_7 = F_3 ( V_6 ) ;
F_7 ( V_6 ) ;
if( ! V_7 ) {
F_5 ( V_13 L_2
L_4 ) ;
V_1 = 0 ;
return - V_14 ;
}
V_8 = ( V_7 + V_15 ) ;
V_6 = F_6 ( V_8 , sizeof( T_3 ) ) ;
if( ! V_6 ) {
F_5 ( V_13 L_5
L_3 ) ;
V_1 = 0 ;
return - V_14 ;
}
F_8 ( 0x00000001 , V_6 ) ;
F_7 ( V_6 ) ;
V_8 = ( V_7 + V_16 ) ;
V_6 = F_6 ( V_8 , sizeof( T_3 ) ) ;
if( ! V_6 ) {
F_5 ( V_13 L_6
L_3 ) ;
V_1 = 0 ;
return - V_14 ;
}
F_8 ( 0x00000001 , V_6 ) ;
F_7 ( V_6 ) ;
V_8 = ( V_7 + V_17 ) ;
V_10 = F_6 ( V_8 , sizeof( T_4 ) ) ;
if( ! V_10 ) {
F_5 ( V_13 L_7
L_3 ) ;
V_1 = 0 ;
return - V_14 ;
}
for( V_9 = 0 ; V_9 < 3 ; V_9 ++ ) {
T_4 V_18 = F_9 ( V_10 ) ;
int V_19 = 100 ;
while( V_19 -- ) F_10 () ;
if( F_9 ( V_10 ) == V_18 ) {
F_5 ( V_13 L_8
L_9 ) ;
F_7 ( V_10 ) ;
V_10 = NULL ;
V_1 = 0 ;
return - V_14 ;
}
}
V_5 = V_10 ;
V_20 . V_21 . V_22 = V_10 ;
F_11 ( & V_20 , V_23 ) ;
return 0 ;
}
