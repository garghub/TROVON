int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_5 ;
T_1 V_6 ;
int V_7 = 0 ;
while ( 1 ) {
V_6 = V_2 -> V_8 ;
F_2 () ;
V_4 -> V_9 = V_2 -> V_9 ;
V_4 -> V_10 = V_2 -> V_10 ;
V_4 -> V_11 = V_2 -> V_11 ;
V_5 = V_2 -> V_5 ;
F_2 () ;
if ( V_2 -> V_8 == V_6 && ! ( V_6 & 1 ) )
break;
if ( ++ V_7 > 10000 ) {
F_3 ( L_1 ) ;
return - V_12 ;
}
}
if ( ! V_5 )
return - V_13 ;
return 0 ;
}
T_2 F_4 ( void )
{
unsigned int V_14 , V_15 ;
asm volatile("rdtsc" : "=a" (low), "=d" (high));
return V_14 | ( ( T_2 ) V_15 ) << 32 ;
}
