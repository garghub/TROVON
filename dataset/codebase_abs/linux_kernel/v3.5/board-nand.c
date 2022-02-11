void F_1 ( struct V_1 * V_2 , int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_8 ;
if ( V_3 == V_9 )
return;
V_8 = ( V_4 & V_10 ) ? 0x02 : 0 ;
if ( V_4 & V_11 )
V_8 |= 0x04 ;
F_2 ( V_3 , V_6 -> V_12 + V_8 ) ;
}
