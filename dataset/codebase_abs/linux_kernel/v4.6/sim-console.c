static void F_1 ( struct V_1 * V_2 , const char * V_3 , unsigned V_4 )
{
register const int T_1 V_5 ( L_1 ) = 1 ;
register const char * T_2 V_5 ( L_2 ) = V_3 ;
register const unsigned T_3 V_5 ( L_3 ) = V_4 ;
__asm__(".byte 0x5e,0x00,0x00,0xc7\n\t"
: : "g"(fd), "g"(_ptr), "g"(_len));
}
static int T_4 F_2 ( struct V_6 * V_7 , const char * V_8 )
{
V_7 -> V_2 -> V_9 = F_1 ;
return 0 ;
}
