static int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( NULL , V_3 ) ;
if ( ! V_2 )
F_3 ( L_1 ) ;
V_4 = F_4 ( V_2 , 0 ) ;
if ( ! V_4 )
F_3 ( L_2 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
int F_6 ( struct V_5 * V_6 )
{
const unsigned int * V_7 = F_7 ( V_6 -> V_8 , L_3 , NULL ) ;
unsigned int V_9 ;
if ( ! V_7 )
return - V_10 ;
V_9 = F_8 ( V_7 ) ;
F_9 ( & V_11 ) ;
F_10 ( F_11 ( V_4 + ( V_9 / 32 ) * 4 ) | V_9 ,
V_4 + ( V_9 / 32 ) * 4 ) ;
F_12 ( 10 ) ;
F_10 ( F_11 ( V_4 + ( V_9 / 32 ) * 4 ) & ~ V_9 ,
V_4 + ( V_9 / 32 ) * 4 ) ;
F_13 ( & V_11 ) ;
return 0 ;
}
void F_14 ( char V_12 , const char * V_13 )
{
F_10 ( V_14 , V_4 ) ;
}
