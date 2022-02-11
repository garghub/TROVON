T_1 F_1 ( unsigned long V_1 , char * V_2 ,
T_2 V_3 , unsigned long V_4 , int V_5 )
{
void * V_6 ;
if ( ! V_3 )
return 0 ;
V_6 = F_2 ( V_1 ) ;
if ( ! V_5 ) {
memcpy ( V_2 , ( V_6 + V_4 ) , V_3 ) ;
F_3 ( V_6 ) ;
} else {
if ( ! V_7 ) {
F_4 ( L_1 ) ;
return - V_8 ;
}
F_5 ( V_7 , V_6 ) ;
F_3 ( V_6 ) ;
if ( F_6 ( V_2 , ( V_7 + V_4 ) , V_3 ) )
return - V_8 ;
}
return V_3 ;
}
static int T_3 F_7 ( void )
{
int V_9 = 0 ;
V_7 = F_8 ( V_10 , V_11 ) ;
if ( ! V_7 ) {
F_4 ( L_2 ) ;
V_9 = - V_12 ;
}
return V_9 ;
}
