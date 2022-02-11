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
int F_7 ( int V_1 , const struct V_2 * V_6 , int V_9 , bool V_10 )
{
int V_11 ;
V_12:
V_11 = F_2 ( V_1 , V_6 ) ;
if ( V_10 && V_1 < V_9 && V_11 >= V_9 ) {
return V_13 ;
} else if ( V_11 >= V_13 ) {
V_10 = true ;
V_1 = - 1 ;
goto V_12;
}
return V_11 ;
}
bool F_8 ( T_1 * V_6 , T_2 V_14 , int V_15 )
{
* V_6 = F_9 ( F_10 () , V_14 , V_15 ) ;
#ifdef F_11
if ( ! * V_6 ) {
F_12 ( V_16 L_1 ) ;
F_13 () ;
}
#endif
return * V_6 != NULL ;
}
bool F_14 ( T_1 * V_6 , T_2 V_14 , int V_15 )
{
return F_8 ( V_6 , V_14 | V_17 , V_15 ) ;
}
bool F_15 ( T_1 * V_6 , T_2 V_14 )
{
return F_8 ( V_6 , V_14 , V_18 ) ;
}
bool F_16 ( T_1 * V_6 , T_2 V_14 )
{
return F_15 ( V_6 , V_14 | V_17 ) ;
}
void T_3 F_17 ( T_1 * V_6 )
{
* V_6 = F_18 ( F_10 () , 0 ) ;
}
void F_19 ( T_1 V_6 )
{
F_20 ( V_6 ) ;
}
void T_3 F_21 ( T_1 V_6 )
{
F_22 ( F_23 ( V_6 ) , F_10 () ) ;
}
unsigned int F_24 ( unsigned int V_8 , int V_15 )
{
int V_7 ;
V_8 %= F_25 () ;
if ( V_15 == - 1 ) {
F_6 (cpu, cpu_online_mask)
if ( V_8 -- == 0 )
return V_7 ;
} else {
F_26 (cpu, cpumask_of_node(node), cpu_online_mask)
if ( V_8 -- == 0 )
return V_7 ;
F_6 (cpu, cpu_online_mask) {
if ( F_3 ( V_7 , F_27 ( V_15 ) ) )
continue;
if ( V_8 -- == 0 )
return V_7 ;
}
}
F_28 () ;
}
