static unsigned long F_1 ( const unsigned long * V_1 ,
unsigned long V_2 , unsigned long V_3 , unsigned long V_4 )
{
unsigned long V_5 ;
if ( F_2 ( V_3 >= V_2 ) )
return V_2 ;
V_5 = V_1 [ V_3 / V_6 ] ^ V_4 ;
V_5 &= F_3 ( V_3 ) ;
V_3 = F_4 ( V_3 , V_6 ) ;
while ( ! V_5 ) {
V_3 += V_6 ;
if ( V_3 >= V_2 )
return V_2 ;
V_5 = V_1 [ V_3 / V_6 ] ^ V_4 ;
}
return F_5 ( V_3 + F_6 ( V_5 ) , V_2 ) ;
}
unsigned long F_7 ( const unsigned long * V_1 , unsigned long V_7 ,
unsigned long V_8 )
{
return F_1 ( V_1 , V_7 , V_8 , 0UL ) ;
}
unsigned long F_8 ( const unsigned long * V_1 , unsigned long V_7 )
{
unsigned long V_9 ;
for ( V_9 = 0 ; V_9 * V_6 < V_7 ; V_9 ++ ) {
if ( V_1 [ V_9 ] )
return F_5 ( V_9 * V_6 + F_6 ( V_1 [ V_9 ] ) , V_7 ) ;
}
return V_7 ;
}
unsigned long F_9 ( const unsigned long * V_1 , unsigned long V_7 )
{
unsigned long V_9 ;
for ( V_9 = 0 ; V_9 * V_6 < V_7 ; V_9 ++ ) {
if ( V_1 [ V_9 ] != ~ 0UL )
return F_5 ( V_9 * V_6 + F_10 ( V_1 [ V_9 ] ) , V_7 ) ;
}
return V_7 ;
}
unsigned long F_11 ( const unsigned long * V_1 , unsigned long V_7 ,
unsigned long V_8 )
{
return F_1 ( V_1 , V_7 , V_8 , ~ 0UL ) ;
}
