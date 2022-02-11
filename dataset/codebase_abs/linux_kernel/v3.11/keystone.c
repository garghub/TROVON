static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( F_3 ( ! V_2 ) )
F_4 ( L_2 ) ;
V_3 = F_5 ( V_2 , 0 ) ;
if ( F_3 ( ! V_3 ) )
F_4 ( L_3 ) ;
F_6 ( NULL , V_4 , NULL , NULL ) ;
}
void F_7 ( enum V_5 V_6 , const char * V_7 )
{
T_2 V_8 ;
F_8 ( ! V_3 ) ;
V_8 = F_9 ( V_3 ) ;
V_8 &= V_9 ;
V_8 |= V_10 ;
F_10 ( V_8 , V_3 ) ;
V_8 = F_9 ( V_3 ) ;
V_8 &= ~ V_11 ;
F_10 ( V_8 , V_3 ) ;
}
