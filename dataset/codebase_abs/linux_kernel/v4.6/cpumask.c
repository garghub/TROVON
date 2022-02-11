int F_1 ( int V_1 , const struct V_2 * V_3 ,
const struct V_2 * V_4 )
{
while ( ( V_1 = F_2 ( V_1 , V_3 ) ) < V_5 )
if ( F_3 ( V_1 , V_4 ) )
break;
return V_1 ;
}
int F_4 ( const struct V_2 * V_6 , unsigned int V_7 )
{
unsigned int V_8 ;
F_5 ( V_7 ) ;
F_6 (i, mask)
if ( V_8 != V_7 )
break;
return V_8 ;
}
bool F_7 ( T_1 * V_6 , T_2 V_9 , int V_10 )
{
* V_6 = F_8 ( F_9 () , V_9 , V_10 ) ;
#ifdef F_10
if ( ! * V_6 ) {
F_11 ( V_11 L_1 ) ;
F_12 () ;
}
#endif
return * V_6 != NULL ;
}
bool F_13 ( T_1 * V_6 , T_2 V_9 , int V_10 )
{
return F_7 ( V_6 , V_9 | V_12 , V_10 ) ;
}
bool F_14 ( T_1 * V_6 , T_2 V_9 )
{
return F_7 ( V_6 , V_9 , V_13 ) ;
}
bool F_15 ( T_1 * V_6 , T_2 V_9 )
{
return F_14 ( V_6 , V_9 | V_12 ) ;
}
void T_3 F_16 ( T_1 * V_6 )
{
* V_6 = F_17 ( F_9 () , 0 ) ;
}
void F_18 ( T_1 V_6 )
{
F_19 ( V_6 ) ;
}
void T_3 F_20 ( T_1 V_6 )
{
F_21 ( F_22 ( V_6 ) , F_9 () ) ;
}
unsigned int F_23 ( unsigned int V_8 , int V_10 )
{
int V_7 ;
V_8 %= F_24 () ;
if ( V_10 == - 1 ) {
F_6 (cpu, cpu_online_mask)
if ( V_8 -- == 0 )
return V_7 ;
} else {
F_25 (cpu, cpumask_of_node(node), cpu_online_mask)
if ( V_8 -- == 0 )
return V_7 ;
F_6 (cpu, cpu_online_mask) {
if ( F_3 ( V_7 , F_26 ( V_10 ) ) )
continue;
if ( V_8 -- == 0 )
return V_7 ;
}
}
F_27 () ;
}
