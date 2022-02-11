static inline void F_1 ( unsigned int * V_1 , unsigned V_2 , unsigned V_3 )
{
unsigned short V_4 ;
int V_5 ;
V_4 = V_2 | ( V_3 << ( 16 - V_6 ) ) ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( V_4 & ( 1 << 15 ) )
F_2 ( F_3 ( V_1 ) | V_7 , V_1 ) ;
else
F_2 ( F_3 ( V_1 ) & ~ V_7 , V_1 ) ;
F_2 ( F_3 ( V_1 ) & ~ V_8 , V_1 ) ;
F_4 () ;
F_2 ( F_3 ( V_1 ) | V_8 , V_1 ) ;
F_4 () ;
V_4 <<= 1 ;
}
F_2 ( F_3 ( V_1 ) & ~ V_7 , V_1 ) ;
}
unsigned short F_5 ( unsigned int * V_1 , int V_3 )
{
unsigned short V_9 = 0 ;
int V_5 ;
F_2 ( F_3 ( V_1 ) & ~ V_10 , V_1 ) ;
F_6 ( V_1 ) ;
F_1 ( V_1 , V_11 , V_3 ) ;
for ( V_5 = 0 ; V_5 < 16 ; V_5 ++ ) {
F_2 ( F_3 ( V_1 ) & ~ V_8 , V_1 ) ;
F_4 () ;
F_2 ( F_3 ( V_1 ) | V_8 , V_1 ) ;
F_4 () ;
V_9 <<= 1 ;
if ( F_3 ( V_1 ) & V_12 )
V_9 |= 1 ;
}
F_7 ( V_1 ) ;
return V_9 ;
}
unsigned short F_8 ( int V_3 )
{
if ( F_9 () )
return F_5 ( & V_13 -> V_14 , V_3 ) ;
else {
unsigned short V_15 ;
V_3 <<= 1 ;
V_15 = V_13 -> V_16 [ V_3 ++ ] & 0xff ;
return ( V_15 << 8 ) | ( V_13 -> V_16 [ V_3 ] & 0xff ) ;
}
}
