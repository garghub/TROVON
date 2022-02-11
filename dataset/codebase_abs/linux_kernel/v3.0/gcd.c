unsigned long F_1 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long V_3 ;
if ( V_1 < V_2 )
F_2 ( V_1 , V_2 ) ;
while ( ( V_3 = V_1 % V_2 ) != 0 ) {
V_1 = V_2 ;
V_2 = V_3 ;
}
return V_2 ;
}
