static inline unsigned int F_1 ( int V_1 )
{
return F_2 ( F_3 ( V_1 ) ) ;
}
static inline void F_4 ( int V_1 , int V_2 )
{
F_5 ( V_2 , F_3 ( V_1 ) ) ;
}
int F_6 ( char V_3 )
{
while ( ( F_1 ( V_4 ) & V_5 ) == 0 )
;
F_4 ( V_6 , V_3 ) ;
return 1 ;
}
