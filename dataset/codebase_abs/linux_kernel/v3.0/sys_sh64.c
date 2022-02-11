int F_1 ( const char * V_1 ,
const char * const V_2 [] ,
const char * const V_3 [] )
{
register unsigned long T_1 V_4 ( L_1 ) = ( ( 0x13 << 16 ) | V_5 ) ;
register unsigned long T_2 V_4 ( L_2 ) = ( unsigned long ) V_1 ;
register unsigned long T_3 V_4 ( L_3 ) = ( unsigned long ) V_2 ;
register unsigned long T_4 V_4 ( L_4 ) = ( unsigned long ) V_3 ;
__asm__ __volatile__ ("trapa %1 !\t\t\t execve(%2,%3,%4)"
: "=r" (__sc0)
: "r" (__sc0), "r" (__sc2), "r" (__sc3), "r" (__sc4) );
__asm__ __volatile__ ("!dummy %0 %1 %2 %3"
: : "r" (__sc0), "r" (__sc2), "r" (__sc3), "r" (__sc4) : "memory");
return T_1 ;
}
