static T_1 T_2 F_1 ( void )
{
return V_1 ? F_2 ( V_1 ) : 0 ;
}
static void F_3 ( struct V_2 * V_3 )
{
unsigned long long V_4 ;
T_3 V_5 ;
struct V_2 * V_6 = & V_7 ;
V_8 = V_9 ;
V_9 = V_1 ? F_2 ( V_1 ) : 0 ;
V_5 = V_9 - V_8 ;
V_4 = F_4 ( V_5 , V_10 , V_11 ) ;
F_5 ( V_6 , V_4 ) ;
* V_3 = * V_6 ;
}
int T_4 F_6 ( void T_5 * V_12 )
{
int V_13 ;
if ( F_2 ( V_12 + V_14 ) &
V_15 )
V_1 = V_12 + V_16 ;
else
V_1 = V_12 + V_17 ;
F_7 ( & V_10 , & V_11 ,
32768 , V_18 , 120000 ) ;
V_13 = F_8 ( V_1 , L_1 , 32768 ,
250 , 32 , V_19 ) ;
if ( V_13 ) {
F_9 ( L_2 ) ;
return V_13 ;
}
F_10 ( F_1 , 32 , 32768 ) ;
F_11 ( NULL , F_3 ) ;
F_12 ( L_3 ) ;
return 0 ;
}
