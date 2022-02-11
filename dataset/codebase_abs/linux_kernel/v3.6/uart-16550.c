static inline unsigned int F_1 ( int V_1 )
{
return * ( ( char * ) F_2 ( V_1 ) ) ;
}
static inline void F_3 ( int V_1 , int V_2 )
{
* ( ( char * ) F_2 ( V_1 ) ) = V_2 ;
}
void putc ( char V_3 )
{
int V_4 = 1024 ;
while ( ( ( F_1 ( V_5 ) & V_6 ) == 0 ) && ( V_4 -- > 0 ) )
;
F_3 ( V_7 , V_3 ) ;
}
