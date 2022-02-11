int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
if ( ! V_5 )
F_2 ( L_1 , V_3 ) ;
V_4 = V_5 ( V_2 , V_3 ) ;
return V_4 ;
}
T_1 F_3 ( T_1 V_6 )
{
return F_4 ( & V_5 , NULL , V_6 ) ;
}
void F_5 ( void )
{
V_5 = NULL ;
}
unsigned long
F_6 ( void )
{
unsigned long V_7 ;
V_7 = F_7 ( V_8 ) ;
V_7 |= F_7 ( V_9 ) << V_10 ;
return V_7 ;
}
void
F_8 ( unsigned long V_7 )
{
F_9 ( V_8 , V_7 ) ;
F_9 ( V_9 , V_7 >> V_10 ) ;
}
static inline unsigned long long F_10 ( void )
{
unsigned long long V_11 = 1ULL << V_12 ;
V_11 |= 1ULL << V_13 ;
return V_11 ;
}
void F_11 ( void )
{
F_12 ( F_10 () ) ;
}
void F_13 ( void )
{
F_14 ( F_10 () ) ;
}
