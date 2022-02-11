static void F_1 ( enum V_1 V_2 , const char * V_3 )
{
T_1 V_4 ;
void T_2 * V_5 ;
struct V_6 * V_7 ;
V_7 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_7 ) {
F_3 ( L_2 ) ;
return;
}
V_5 = F_4 ( V_7 , 0 ) ;
if ( ! V_5 ) {
F_3 ( L_3 ) ;
return;
}
V_4 = F_5 ( V_5 + V_8 ) ;
V_4 &= V_9 | V_10 ;
V_4 |= V_11 | V_12 |
( 0x15 << V_13 ) |
( 0x8 << V_14 ) ;
F_6 ( V_4 , V_5 + V_8 ) ;
while ( 1 ) ;
}
static void T_3 F_7 ( void )
{
F_8 () ;
}
