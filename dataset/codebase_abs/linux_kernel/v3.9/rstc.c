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
T_2 V_7 ;
if ( F_7 ( V_6 -> V_8 , L_3 , & V_7 ) )
return - V_9 ;
F_8 ( & V_10 ) ;
if ( F_9 ( V_6 -> V_8 , L_4 ) ) {
F_10 ( F_11 ( V_4 + ( V_7 / 32 ) * 4 ) | V_7 ,
V_4 + ( V_7 / 32 ) * 4 ) ;
F_12 ( 10 ) ;
F_10 ( F_11 ( V_4 + ( V_7 / 32 ) * 4 ) & ~ V_7 ,
V_4 + ( V_7 / 32 ) * 4 ) ;
} else {
F_10 ( V_7 , V_4 + ( V_7 / 32 ) * 8 ) ;
F_12 ( 10 ) ;
F_10 ( V_7 , V_4 + ( V_7 / 32 ) * 8 + 4 ) ;
}
F_13 ( & V_10 ) ;
return 0 ;
}
void F_14 ( char V_11 , const char * V_12 )
{
F_10 ( V_13 , V_4 ) ;
}
