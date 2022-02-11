void F_1 ( struct V_1 * V_2 , int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_7 ;
if ( V_3 == V_8 )
return;
V_7 = ( V_4 & V_9 ) ? 0x02 : 0 ;
if ( V_4 & V_10 )
V_7 |= 0x04 ;
F_3 ( V_3 , V_6 -> V_11 + V_7 ) ;
}
