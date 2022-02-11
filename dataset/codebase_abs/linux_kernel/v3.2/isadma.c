void F_1 ( unsigned long V_1 ,
unsigned long V_2 , unsigned int V_3 ,
unsigned short V_4 )
{
unsigned long V_5 ;
V_5 = F_2 () ;
F_3 ( V_1 ) ;
F_4 ( V_1 ) ;
F_5 ( V_1 , V_4 ) ;
F_6 ( V_1 , V_2 ) ;
F_7 ( V_1 , V_3 ) ;
if ( ! ( V_4 & V_6 ) )
F_8 ( V_1 ) ;
F_9 ( V_5 ) ;
}
void F_10 ( unsigned long V_1 )
{
unsigned long V_5 ;
V_5 = F_2 () ;
F_4 ( V_1 ) ;
F_3 ( V_1 ) ;
F_9 ( V_5 ) ;
}
unsigned int F_11 ( unsigned long V_1 , unsigned int V_3 )
{
unsigned long V_5 ;
unsigned int V_7 , V_8 ;
V_5 = F_2 () ;
F_4 ( V_1 ) ;
if ( ! V_9 )
F_3 ( V_1 ) ;
V_7 = F_12 ( V_1 ) ;
V_8 = F_12 ( V_1 ) ;
if ( ! V_9 )
F_8 ( V_1 ) ;
F_9 ( V_5 ) ;
if ( F_13 ( V_7 < V_8 ) )
V_7 = V_8 ;
#ifdef F_14
if ( V_7 > V_3 )
F_15 ( V_10 L_1 , V_7 , V_1 , V_3 ) ;
#endif
if ( V_7 >= V_3 || V_7 == 0 )
return 0 ;
else
return V_3 - V_7 ;
}
