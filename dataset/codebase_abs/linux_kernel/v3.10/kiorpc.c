void T_1 * F_1 ( int V_1 , T_2 V_2 ,
unsigned long V_3 )
{
T_3 V_4 , V_5 = { 0 } ;
unsigned long V_6 ;
int V_7 ;
V_7 = F_2 ( V_1 , & V_4 ) ;
if ( V_7 ) {
F_3 ( L_1 , V_7 ) ;
return NULL ;
}
V_7 = F_4 ( V_1 , V_2 , V_3 ) ;
if ( V_7 ) {
F_3 ( L_2 , V_7 ) ;
return NULL ;
}
V_5 = F_5 ( V_5 , F_6 ( V_4 ) ) ;
V_6 = F_7 ( V_4 ) + F_8 ( V_2 ) ;
return F_9 ( F_10 ( V_6 ) , V_3 , V_5 ) ;
}
