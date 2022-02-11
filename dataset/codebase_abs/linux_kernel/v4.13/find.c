unsigned long F_1 ( const unsigned long * V_1 , unsigned long V_2 )
{
const unsigned long * V_3 = V_1 ;
unsigned long V_4 = 0 ;
unsigned long V_5 ;
while ( V_2 & ~ ( V_6 - 1 ) ) {
if ( ( V_5 = * ( V_3 ++ ) ) )
goto V_7;
V_4 += V_6 ;
V_2 -= V_6 ;
}
if ( ! V_2 )
return V_4 ;
V_5 = ( * V_3 ) & ( ~ 0UL << ( V_6 - V_2 ) ) ;
if ( ! V_5 )
return V_4 + V_2 ;
V_7:
return V_4 + ( F_2 ( V_5 ) ^ ( V_6 - 1 ) ) ;
}
unsigned long F_3 ( const unsigned long * V_1 , unsigned long V_2 ,
unsigned long V_8 )
{
const unsigned long * V_3 = V_1 + ( V_8 / V_6 ) ;
unsigned long V_4 = V_8 & ~ ( V_6 - 1 ) ;
unsigned long V_5 ;
if ( V_8 >= V_2 )
return V_2 ;
V_2 -= V_4 ;
V_8 %= V_6 ;
if ( V_8 ) {
V_5 = * ( V_3 ++ ) ;
V_5 &= ( ~ 0UL >> V_8 ) ;
if ( V_2 < V_6 )
goto V_9;
if ( V_5 )
goto V_10;
V_2 -= V_6 ;
V_4 += V_6 ;
}
while ( V_2 & ~ ( V_6 - 1 ) ) {
if ( ( V_5 = * ( V_3 ++ ) ) )
goto V_10;
V_4 += V_6 ;
V_2 -= V_6 ;
}
if ( ! V_2 )
return V_4 ;
V_5 = * V_3 ;
V_9:
V_5 &= ( ~ 0UL << ( V_6 - V_2 ) ) ;
if ( ! V_5 )
return V_4 + V_2 ;
V_10:
return V_4 + ( F_2 ( V_5 ) ^ ( V_6 - 1 ) ) ;
}
