int
F_1 ( void * V_1 , void * V_2 )
{
#if 0
#ifdef F_2
printk("%s: S %p, ea %p: ", __func__, frS, ea);
dump_double(frS);
printk("\n");
#endif
#endif
if ( F_3 ( V_2 , V_1 , sizeof( double ) ) )
return - V_3 ;
return 0 ;
}
