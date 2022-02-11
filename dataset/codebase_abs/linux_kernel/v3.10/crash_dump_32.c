static inline bool F_1 ( unsigned long V_1 )
{
#ifndef F_2
return F_3 ( F_4 ( V_1 , F_5 ( 0 ) ) ) == V_1 ;
#else
return true ;
#endif
}
T_1 F_6 ( unsigned long V_1 , char * V_2 ,
T_2 V_3 , unsigned long V_4 , int V_5 )
{
void * V_6 ;
if ( ! V_3 )
return 0 ;
if ( ! F_1 ( V_1 ) )
return - V_7 ;
V_6 = F_7 ( V_1 ) ;
if ( ! V_5 ) {
memcpy ( V_2 , ( V_6 + V_4 ) , V_3 ) ;
F_8 ( V_6 ) ;
} else {
if ( ! V_8 ) {
F_9 ( V_9 L_1
L_2 ) ;
F_8 ( V_6 ) ;
return - V_7 ;
}
F_10 ( V_8 , V_6 ) ;
F_8 ( V_6 ) ;
if ( F_11 ( V_2 , ( V_8 + V_4 ) , V_3 ) )
return - V_7 ;
}
return V_3 ;
}
static int T_3 F_12 ( void )
{
int V_10 = 0 ;
V_8 = F_13 ( V_11 , V_12 ) ;
if ( ! V_8 ) {
F_9 ( V_9 L_3
L_4 ) ;
V_10 = - V_13 ;
}
return V_10 ;
}
