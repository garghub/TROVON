int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
if ( V_5 . V_6 & V_7 ) {
F_2 ( L_1 ) ;
return - V_8 ;
}
return F_3 ( V_2 , V_3 , V_4 ) ;
}
int F_4 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 , T_1 V_9 )
{
if ( V_5 . V_6 & V_7 ) {
F_2 ( L_1 ) ;
return - V_8 ;
}
return F_5 ( V_2 , V_3 , V_4 ,
V_9 ) ;
}
void T_2 F_6 ( void )
{
struct V_10 * V_11 ;
struct V_10 * V_12 ;
V_11 = F_7 ( NULL , L_2 ) ;
F_8 ( V_11 , V_13 ) ;
F_9 ( V_11 ) ;
V_12 = F_7 ( NULL , L_3 ) ;
F_9 ( V_12 ) ;
F_8 ( V_12 , V_13 ) ;
F_10 ( V_12 ) ;
F_10 ( V_11 ) ;
return;
}
static int T_2 F_11 ( void )
{
int V_14 ;
if ( ! F_12 () )
return 0 ;
V_14 = F_13 ( L_4 ) ;
if ( ! V_14 )
F_14 ( L_5 , L_6 , L_7 ) ;
return V_14 ;
}
