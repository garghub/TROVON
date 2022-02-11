int T_1 F_1 ( void )
{
void * V_1 ;
long long V_2 ;
int V_3 ;
if ( V_4 == NULL )
return 0 ;
V_3 = F_2 ( V_4 , & V_2 ) ;
if ( V_3 )
return 0 ;
if ( V_2 == 0 ) {
F_3 ( V_5 L_1 , V_4 ) ;
return 0 ;
}
V_1 = F_4 ( V_2 ) ;
if ( F_5 ( V_4 , V_1 , V_2 ) == - 1 )
return 0 ;
V_6 = ( unsigned long ) V_1 ;
V_7 = V_6 + V_2 ;
return 0 ;
}
static int T_1 F_6 ( char * line , int * V_8 )
{
V_4 = line ;
return 0 ;
}
static int F_5 ( char * V_9 , void * V_10 , int V_2 )
{
int V_11 , V_12 ;
V_11 = F_7 ( V_9 , F_8 ( F_9 () ) , 0 ) ;
if ( V_11 < 0 ) {
F_3 ( V_5 L_2 , V_9 ,
- V_11 ) ;
return - 1 ;
}
V_12 = F_10 ( V_11 , V_10 , V_2 ) ;
if ( V_12 != V_2 ) {
F_3 ( V_5 L_3
L_4 , V_2 ,
V_9 , - V_12 ) ;
return - 1 ;
}
F_11 ( V_11 ) ;
return 0 ;
}
