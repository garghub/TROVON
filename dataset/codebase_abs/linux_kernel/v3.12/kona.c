void F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 ) {
F_3 ( L_2 ) ;
return;
}
V_3 = F_4 ( V_2 , 0 ) ;
F_5 ( ! V_3 , L_3 ) ;
F_6 ( V_2 ) ;
}
void F_7 ( enum V_4 V_5 , const char * V_6 )
{
T_1 V_7 ;
if ( ! V_3 )
F_8 ( L_4 ) ;
V_7 = F_9 ( V_3 + V_8 ) ;
V_7 &= V_9 | V_10 ;
V_7 |= V_11 | V_12 |
( 0x8 << V_13 ) |
( 0x8 << V_14 ) ;
F_10 ( V_7 , V_3 + V_8 ) ;
while ( 1 )
;
}
