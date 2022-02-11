static T_1 F_1 ( struct V_1 * V_2 )
{
return ( T_1 ) F_2 ( V_3 ) ;
}
static int T_2 F_3 ( void )
{
unsigned long V_4 ;
unsigned long V_5 ;
T_3 T_4 * volatile V_6 ;
T_3 T_4 * V_7 ;
int V_8 ;
if ( ! V_9 )
return - V_10 ;
F_4 ( V_11 L_1 ) ;
V_5 = V_12 ;
V_7 = F_5 ( V_5 , sizeof( V_7 ) ) ;
if ( ! V_7 ) {
F_4 ( V_13 L_2 ) ;
return - V_10 ;
}
V_4 = F_2 ( V_7 ) ;
F_6 ( V_7 ) ;
if ( ! V_4 ) {
F_4 ( V_13 L_3 ) ;
return - V_10 ;
}
V_5 = V_4 + V_14 ;
V_7 = F_5 ( V_5 , sizeof( V_7 ) ) ;
if ( ! V_7 ) {
F_4 ( V_13 L_4 ) ;
return - V_10 ;
}
F_7 ( 0x00000001 , V_7 ) ;
F_6 ( V_7 ) ;
V_5 = V_4 + V_15 ;
V_7 = F_5 ( V_5 , sizeof( V_7 ) ) ;
if ( ! V_7 ) {
F_4 ( V_13 L_5 ) ;
return - V_10 ;
}
F_7 ( 0x00000001 , V_7 ) ;
F_6 ( V_7 ) ;
V_5 = V_4 + V_16 ;
V_6 = F_5 ( V_5 , sizeof( V_17 ) ) ;
if ( ! V_6 ) {
F_4 ( V_13 L_6 ) ;
return - V_10 ;
}
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ ) {
T_3 V_18 = F_2 ( V_6 ) ;
int V_19 = 100 ;
while ( V_19 -- )
F_8 () ;
if ( F_2 ( V_6 ) == V_18 ) {
F_4 ( V_13 L_7 ) ;
F_6 ( V_6 ) ;
V_6 = NULL ;
return - V_10 ;
}
}
V_3 = V_6 ;
return F_9 ( & V_20 ,
V_21 ) ;
}
