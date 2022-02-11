static inline unsigned int F_1 ( int V_1 )
{
return F_2 ( 0x3f8 + V_1 ) ;
}
static inline void F_3 ( int V_1 , int V_2 )
{
F_4 ( V_2 , 0x3f8 + V_1 ) ;
}
void T_1 F_5 ( char V_3 )
{
while ( ( F_1 ( V_4 ) & V_5 ) == 0 )
;
F_3 ( V_6 , V_3 ) ;
}
