static inline void T_1 * F_1 ( unsigned long V_1 )
{
return V_2 + ( V_1 - V_3 ) ;
}
void T_1 * F_2 ( unsigned int V_4 , unsigned long * V_5 )
{
if ( ! V_6 )
return NULL ;
* V_5 = F_3 ( V_6 , V_4 ) ;
F_4 ( L_1 , V_4 , * V_5 ) ;
if ( ! * V_5 )
return NULL ;
return F_1 ( * V_5 ) ;
}
void F_5 ( unsigned long V_7 , unsigned int V_4 )
{
if ( ! V_6 )
return;
F_6 ( V_6 , V_7 , V_4 ) ;
}
int T_2 F_7 ( unsigned long V_8 , unsigned long V_4 )
{
V_3 = V_8 ;
V_6 = F_8 ( V_9 , - 1 ) ;
if ( ! V_6 )
return - V_10 ;
F_9 ( V_6 , V_8 , V_4 , - 1 ) ;
V_2 = F_10 ( V_3 , V_4 ) ;
if ( ! V_2 )
return - V_11 ;
F_4 ( L_2 , V_4 / 1024 , V_2 ) ;
return 0 ;
}
