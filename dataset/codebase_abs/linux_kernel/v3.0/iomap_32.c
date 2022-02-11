static int F_1 ( T_1 V_1 , unsigned long V_2 )
{
#if ! F_2 ( V_3 ) && F_2 ( V_4 )
if ( V_1 + V_2 > 0x100000000ULL )
return 0 ;
#endif
return 1 ;
}
int F_3 ( T_1 V_1 , unsigned long V_2 , T_2 * V_5 )
{
unsigned long V_6 = V_7 ;
int V_8 ;
if ( ! F_1 ( V_1 , V_2 ) )
return - V_9 ;
V_8 = F_4 ( V_1 , V_1 + V_2 , & V_6 ) ;
if ( V_8 )
return V_8 ;
* V_5 = F_5 ( V_10 | V_6 ) ;
return 0 ;
}
void F_6 ( T_1 V_1 , unsigned long V_2 )
{
F_7 ( V_1 , V_1 + V_2 ) ;
}
void * F_8 ( unsigned long V_11 , T_2 V_5 )
{
unsigned long V_12 ;
int V_13 , type ;
F_9 () ;
type = F_10 () ;
V_13 = type + V_14 * F_11 () ;
V_12 = F_12 ( V_15 + V_13 ) ;
F_13 ( V_16 - V_13 , F_14 ( V_11 , V_5 ) ) ;
F_15 () ;
return ( void * ) V_12 ;
}
void T_3 *
F_16 ( unsigned long V_11 , T_2 V_5 )
{
if ( ! V_17 && F_17 ( V_5 ) == F_17 ( V_18 ) )
V_5 = V_19 ;
return ( void V_20 T_3 * ) F_8 ( V_11 , V_5 ) ;
}
void
F_18 ( void T_3 * V_21 )
{
unsigned long V_12 = ( unsigned long ) V_21 & V_22 ;
if ( V_12 >= F_12 ( V_23 ) &&
V_12 <= F_12 ( V_15 ) ) {
int V_13 , type ;
type = F_19 () ;
V_13 = type + V_14 * F_11 () ;
#ifdef F_20
F_21 ( V_12 != F_12 ( V_15 + V_13 ) ) ;
#endif
F_22 ( V_16 - V_13 , V_12 ) ;
F_23 () ;
}
F_24 () ;
}
