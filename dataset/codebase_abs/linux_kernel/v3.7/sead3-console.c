static inline unsigned int F_1 ( int V_1 , unsigned int V_2 )
{
return F_2 ( F_3 ( V_2 , V_1 ) ) & 0xff ;
}
static inline void F_4 ( int V_1 , int V_3 , unsigned int V_2 )
{
F_5 ( V_3 , F_3 ( V_2 , V_1 ) ) ;
}
void T_1 F_6 ( char V_4 )
{
V_5 = V_4 ;
}
int F_7 ( char V_6 )
{
unsigned int V_2 ;
V_2 = V_5 ? V_7 : V_8 ;
while ( ( F_1 ( V_9 , V_2 ) & V_10 ) == 0 )
;
F_4 ( V_11 , V_6 , V_2 ) ;
return 1 ;
}
