int F_1 ( const char * V_1 ,
const char * const * V_2 ,
const char * const * V_3 )
{
register long T_1 V_4 ( L_1 ) = V_5 ;
register long T_2 V_4 ( L_2 ) = ( long ) V_1 ;
register long T_3 V_4 ( L_3 ) = ( long ) V_2 ;
register long T_4 V_4 ( L_4 ) = ( long ) V_3 ;
asm volatile("scall"
: "=r"(sc1)
: "r"(scno), "0"(sc1), "r"(sc2), "r"(sc3)
: "cc", "memory");
return T_2 ;
}
