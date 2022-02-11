static void F_1 ( void )
{
unsigned int V_1 ;
unsigned long V_2 ;
F_2 ( V_2 ) ;
V_1 = F_3 ( V_3 ) ;
V_1 &= ~ V_4 ;
V_1 |= V_5 ;
F_4 ( V_1 , V_3 ) ;
F_5 ( V_2 ) ;
}
int T_1 F_6 ( const char * V_6 , bool V_7 ,
struct V_8 * V_9 )
{
if ( ! V_6 )
V_6 = L_1 ;
snprintf ( V_10 , sizeof( V_10 ) - 1 , L_2 , V_6 ) ;
if ( V_9 )
V_11 = * V_9 ;
if ( V_7 )
V_11 . V_12 = F_1 ;
F_7 ( & V_13 ) ;
F_7 ( & V_14 ) ;
return 0 ;
}
