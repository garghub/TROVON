static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned short V_4 ;
V_4 = F_2 ( V_5 ) ;
F_3 ( V_4 & 0x0fcf , V_5 ) ;
if ( ! ( V_3 & V_6 ) ) {
V_4 = F_2 ( V_5 ) ;
F_3 ( ( V_4 & 0x0fcf ) | 0x1000 , V_5 ) ;
V_4 = F_4 ( V_7 ) ;
F_5 ( V_4 & 0xbf , V_7 ) ;
}
}
