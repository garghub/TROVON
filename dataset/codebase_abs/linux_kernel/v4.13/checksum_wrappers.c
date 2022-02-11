T_1 F_1 ( const void T_2 * V_1 , void * V_2 ,
int V_3 , T_1 V_4 , int * V_5 )
{
unsigned int V_6 ;
F_2 () ;
* V_5 = 0 ;
if ( ! V_3 ) {
V_6 = 0 ;
goto V_7;
}
if ( F_3 ( ( V_3 < 0 ) || ! F_4 ( V_8 , V_1 , V_3 ) ) ) {
* V_5 = - V_9 ;
V_6 = ( V_10 unsigned int ) V_4 ;
goto V_7;
}
V_6 = F_5 ( ( void V_10 * ) V_1 , V_2 ,
V_3 , V_4 , V_5 , NULL ) ;
if ( F_3 ( * V_5 ) ) {
int V_11 = F_6 ( V_2 , V_1 , V_3 ) ;
if ( V_11 ) {
memset ( V_2 + V_3 - V_11 , 0 , V_11 ) ;
* V_5 = - V_9 ;
} else {
* V_5 = 0 ;
}
V_6 = F_7 ( V_2 , V_3 , V_4 ) ;
}
V_7:
return ( V_10 T_1 ) V_6 ;
}
T_1 F_8 ( const void * V_1 , void T_2 * V_2 , int V_3 ,
T_1 V_4 , int * V_5 )
{
unsigned int V_6 ;
F_2 () ;
* V_5 = 0 ;
if ( ! V_3 ) {
V_6 = 0 ;
goto V_7;
}
if ( F_3 ( ( V_3 < 0 ) || ! F_4 ( V_12 , V_2 , V_3 ) ) ) {
* V_5 = - V_9 ;
V_6 = - 1 ;
goto V_7;
}
V_6 = F_5 ( V_1 , ( void V_10 * ) V_2 ,
V_3 , V_4 , NULL , V_5 ) ;
if ( F_3 ( * V_5 ) ) {
V_6 = F_7 ( V_1 , V_3 , V_4 ) ;
if ( F_9 ( V_2 , V_1 , V_3 ) ) {
* V_5 = - V_9 ;
V_6 = - 1 ;
}
}
V_7:
return ( V_10 T_1 ) V_6 ;
}
