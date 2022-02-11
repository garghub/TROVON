static int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( NULL , V_3 ) ;
if ( ! V_2 ) {
F_3 ( L_1 ) ;
return - V_4 ;
}
V_5 = F_4 ( V_2 , 0 ) ;
if ( ! V_5 )
F_5 ( L_2 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_7 ( struct V_6 * V_7 )
{
T_2 V_8 ;
if ( F_8 ( V_7 -> V_9 , L_3 , & V_8 ) )
return - V_10 ;
F_9 ( & V_11 ) ;
if ( F_10 ( V_7 -> V_9 , L_4 ) ) {
F_11 ( F_12 ( V_5 + ( V_8 / 32 ) * 4 ) | V_8 ,
V_5 + ( V_8 / 32 ) * 4 ) ;
F_13 ( 10 ) ;
F_11 ( F_12 ( V_5 + ( V_8 / 32 ) * 4 ) & ~ V_8 ,
V_5 + ( V_8 / 32 ) * 4 ) ;
} else {
F_11 ( V_8 , V_5 + ( V_8 / 32 ) * 8 ) ;
F_13 ( 10 ) ;
F_11 ( V_8 , V_5 + ( V_8 / 32 ) * 8 + 4 ) ;
}
F_14 ( & V_11 ) ;
return 0 ;
}
void F_15 ( enum V_12 V_13 , const char * V_14 )
{
F_11 ( V_15 , V_5 ) ;
}
