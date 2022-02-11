static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned short V_4 ;
if ( V_2 -> V_5 == 0xffe00000 ) {
V_4 = F_2 ( V_6 ) ;
V_4 &= ~ 0x03cf ;
if ( ! ( V_3 & V_7 ) )
V_4 |= 0x0340 ;
F_3 ( V_4 , V_6 ) ;
}
}
