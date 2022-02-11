unsigned long F_1 ( void * V_1 )
{
register long T_1 V_2 ( L_1 ) ;
register long T_2 V_2 ( L_2 ) ;
long V_3 = ( long ) V_1 , V_4 ;
long V_5 ;
if ( T_1 >= ( long ) V_6 && T_1 < ( long ) V_7 )
V_5 = F_2 ( T_1 ) ;
#ifdef F_3
else if ( ( long long ) T_1 >= ( long long ) F_4 ( 0 , 0 ) &&
( long long ) T_1 < ( long long ) F_4 ( 8 , 0 ) )
V_5 = F_4 ( V_8 ,
F_5 ( ( long long ) T_1 ) ) ;
#endif
else {
F_6 () ;
V_5 = T_1 ;
}
if ( V_3 >= ( long ) V_6 && V_3 < ( long ) V_7 )
V_4 = F_2 ( V_3 ) ;
#ifdef F_3
else if ( ( long long ) V_3 >= ( long long ) F_4 ( 0 , 0 ) &&
( long long ) V_3 < ( long long ) F_4 ( 8 , 0 ) )
V_4 = F_4 ( V_8 ,
F_5 ( ( long long ) V_3 ) ) ;
#endif
else {
F_6 () ;
V_4 = V_3 ;
}
__asm__ __volatile__ (
" move $16, $sp\n"
" move $sp, %1\n"
" jalr %2\n"
" move $sp, $16"
: "=r" (ret)
: "r" (usp), "r" (ufunc)
: "$16", "$31");
return T_2 ;
}
