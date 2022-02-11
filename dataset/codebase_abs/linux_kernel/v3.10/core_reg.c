void F_1 ( int V_1 , int V_2 , int V_3 , unsigned int V_4 )
{
unsigned long V_5 ;
if ( V_1 == V_6 ) {
void T_1 * V_7 = F_2 ( V_3 , V_2 ) ;
F_3 ( V_4 , V_7 ) ;
return;
}
F_4 ( V_5 ) ;
while ( ! ( F_5 ( V_8 ) & V_9 ) )
F_6 ( 10 ) ;
F_3 ( V_4 , V_10 ) ;
V_4 = F_7 ( V_1 ) | F_8 ( V_2 ) | F_9 ( V_3 ) ;
F_3 ( V_4 , V_8 ) ;
while ( ! ( F_5 ( V_8 ) & V_9 ) )
F_6 ( 10 ) ;
F_10 ( V_5 ) ;
}
unsigned int F_11 ( int V_1 , int V_2 , int V_3 )
{
unsigned long V_5 ;
unsigned int V_4 ;
if ( V_1 == V_6 ) {
void T_1 * V_7 = F_2 ( V_3 , V_2 ) ;
V_4 = F_5 ( V_7 ) ;
return V_4 ;
}
F_4 ( V_5 ) ;
while ( ! ( F_5 ( V_8 ) & V_9 ) )
F_6 ( 10 ) ;
V_4 = ( F_7 ( V_1 ) | F_8 ( V_2 ) | F_9 ( V_3 ) |
V_11 ) ;
F_3 ( V_4 , V_8 ) ;
while ( ! ( F_5 ( V_8 ) & V_9 ) )
F_6 ( 10 ) ;
V_4 = F_5 ( V_10 ) ;
F_10 ( V_5 ) ;
return V_4 ;
}
