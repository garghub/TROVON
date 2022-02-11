int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
int V_6 ;
F_2 ( V_2 , V_7 , V_3 , V_3 ) ;
V_4 = V_8 + V_9 ;
while ( 1 ) {
V_6 = F_3 ( V_2 , V_10 , & V_5 ) ;
if ( V_6 )
return V_6 ;
if ( ( V_5 & V_3 ) == V_3 )
break;
F_4 () ;
if ( F_5 ( V_8 , V_4 ) )
return - V_11 ;
}
return 0 ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
int V_6 ;
F_2 ( V_2 , V_7 , V_3 , 0 ) ;
V_4 = V_8 + V_9 ;
while ( 1 ) {
T_1 V_5 ;
V_6 = F_3 ( V_2 , V_10 , & V_5 ) ;
if ( V_6 )
return V_6 ;
if ( ! ( V_5 & V_3 ) )
break;
F_4 () ;
if ( F_5 ( V_8 , V_4 ) )
return - V_11 ;
}
return 0 ;
}
