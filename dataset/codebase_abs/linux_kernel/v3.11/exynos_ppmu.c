void F_1 ( void T_1 * V_1 )
{
F_2 ( V_2 | V_3 , V_1 ) ;
F_2 ( V_4 |
V_5 |
V_6 |
V_7 |
V_8 ,
V_1 + V_9 ) ;
}
void F_3 ( void T_1 * V_1 , unsigned int V_10 ,
unsigned int V_11 )
{
F_2 ( V_11 , V_1 + F_4 ( V_10 ) ) ;
}
void F_5 ( void T_1 * V_1 )
{
F_2 ( V_12 , V_1 ) ;
}
void F_6 ( void T_1 * V_1 )
{
F_2 ( V_13 , V_1 ) ;
}
unsigned int F_7 ( void T_1 * V_1 , unsigned int V_10 )
{
unsigned int V_14 ;
if ( V_10 == V_15 )
V_14 = ( ( F_8 ( V_1 + F_9 ( V_10 ) ) << 8 ) |
F_8 ( V_1 + F_9 ( V_10 + 1 ) ) ) ;
else
V_14 = F_8 ( V_1 + F_9 ( V_10 ) ) ;
return V_14 ;
}
