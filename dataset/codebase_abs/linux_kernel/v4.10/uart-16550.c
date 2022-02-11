static inline unsigned int F_1 ( int V_1 )
{
return * ( ( volatile V_2 * ) F_2 ( V_1 ) ) & 0xFF ;
}
static inline void F_3 ( int V_1 , int V_3 )
{
* ( ( volatile V_2 * ) F_2 ( V_1 ) ) = V_3 & 0xFF ;
}
void putc ( char V_4 )
{
int V_5 = 1000000 ;
while ( ( ( F_1 ( V_6 ) & V_7 ) == 0 ) && ( V_5 -- > 0 ) )
;
F_3 ( V_8 , V_4 ) ;
}
