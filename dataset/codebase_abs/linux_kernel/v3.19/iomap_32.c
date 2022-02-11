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
enum V_6 V_7 = V_8 ;
int V_9 ;
if ( ! F_1 ( V_1 , V_2 ) )
return - V_10 ;
V_9 = F_4 ( V_1 , V_1 + V_2 , & V_7 ) ;
if ( V_9 )
return V_9 ;
* V_5 = F_5 ( V_11 | F_6 ( V_7 ) ) ;
return 0 ;
}
void F_7 ( T_1 V_1 , unsigned long V_2 )
{
F_8 ( V_1 , V_1 + V_2 ) ;
}
void * F_9 ( unsigned long V_12 , T_2 V_5 )
{
unsigned long V_13 ;
int V_14 , type ;
F_10 () ;
type = F_11 () ;
V_14 = type + V_15 * F_12 () ;
V_13 = F_13 ( V_16 + V_14 ) ;
F_14 ( V_17 - V_14 , F_15 ( V_12 , V_5 ) ) ;
F_16 () ;
return ( void * ) V_13 ;
}
void T_3 *
F_17 ( unsigned long V_12 , T_2 V_5 )
{
if ( ! V_18 && F_18 ( V_5 ) ==
( V_11 | F_6 ( V_8 ) ) )
V_5 = F_5 ( V_11 |
F_6 ( V_19 ) ) ;
return ( void V_20 T_3 * ) F_9 ( V_12 , V_5 ) ;
}
void
F_19 ( void T_3 * V_21 )
{
unsigned long V_13 = ( unsigned long ) V_21 & V_22 ;
if ( V_13 >= F_13 ( V_23 ) &&
V_13 <= F_13 ( V_16 ) ) {
int V_14 , type ;
type = F_20 () ;
V_14 = type + V_15 * F_12 () ;
#ifdef F_21
F_22 ( V_13 != F_13 ( V_16 + V_14 ) ) ;
#endif
F_23 ( V_17 - V_14 , V_13 ) ;
F_24 () ;
}
F_25 () ;
}
