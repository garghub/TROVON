static int T_1 F_1 ( char * V_1 )
{
if ( V_1 )
V_2 = ( F_2 ( V_1 , & V_1 ) >> V_3 ) - 1 ;
return 1 ;
}
T_2 F_3 ( unsigned long V_4 , char * V_5 ,
T_3 V_6 , unsigned long V_7 , int V_8 )
{
void * V_9 ;
if ( ! V_6 )
return 0 ;
V_9 = F_4 ( V_4 ) ;
if ( ! V_8 ) {
memcpy ( V_5 , ( V_9 + V_7 ) , V_6 ) ;
F_5 ( V_9 ) ;
} else {
if ( ! V_10 ) {
F_6 ( L_1 ) ;
return - V_11 ;
}
F_7 ( V_10 , V_9 ) ;
F_5 ( V_9 ) ;
if ( F_8 ( V_5 , ( V_10 + V_7 ) , V_6 ) )
return - V_11 ;
}
return V_6 ;
}
static int T_1 F_9 ( void )
{
int V_12 = 0 ;
V_10 = F_10 ( V_13 , V_14 ) ;
if ( ! V_10 ) {
F_6 ( L_2 ) ;
V_12 = - V_15 ;
}
return V_12 ;
}
