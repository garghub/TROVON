unsigned int F_1 ( int V_1 , const struct V_2 * V_3 )
{
if ( V_1 != - 1 )
F_2 ( V_1 ) ;
return F_3 ( F_4 ( V_3 ) , V_4 , V_1 + 1 ) ;
}
int F_5 ( int V_1 , const struct V_2 * V_5 ,
const struct V_2 * V_6 )
{
while ( ( V_1 = F_1 ( V_1 , V_5 ) ) < V_7 )
if ( F_6 ( V_1 , V_6 ) )
break;
return V_1 ;
}
int F_7 ( const struct V_2 * V_8 , unsigned int V_9 )
{
unsigned int V_10 ;
F_2 ( V_9 ) ;
F_8 (i, mask)
if ( V_10 != V_9 )
break;
return V_10 ;
}
int F_9 ( int V_1 , const struct V_2 * V_8 , int V_11 , bool V_12 )
{
int V_13 ;
V_14:
V_13 = F_1 ( V_1 , V_8 ) ;
if ( V_12 && V_1 < V_11 && V_13 >= V_11 ) {
return V_4 ;
} else if ( V_13 >= V_4 ) {
V_12 = true ;
V_1 = - 1 ;
goto V_14;
}
return V_13 ;
}
bool F_10 ( T_1 * V_8 , T_2 V_15 , int V_16 )
{
* V_8 = F_11 ( F_12 () , V_15 , V_16 ) ;
#ifdef F_13
if ( ! * V_8 ) {
F_14 ( V_17 L_1 ) ;
F_15 () ;
}
#endif
return * V_8 != NULL ;
}
bool F_16 ( T_1 * V_8 , T_2 V_15 , int V_16 )
{
return F_10 ( V_8 , V_15 | V_18 , V_16 ) ;
}
bool F_17 ( T_1 * V_8 , T_2 V_15 )
{
return F_10 ( V_8 , V_15 , V_19 ) ;
}
bool F_18 ( T_1 * V_8 , T_2 V_15 )
{
return F_17 ( V_8 , V_15 | V_18 ) ;
}
void T_3 F_19 ( T_1 * V_8 )
{
* V_8 = F_20 ( F_12 () , 0 ) ;
}
void F_21 ( T_1 V_8 )
{
F_22 ( V_8 ) ;
}
void T_3 F_23 ( T_1 V_8 )
{
F_24 ( F_25 ( V_8 ) , F_12 () ) ;
}
unsigned int F_26 ( unsigned int V_10 , int V_16 )
{
int V_9 ;
V_10 %= F_27 () ;
if ( V_16 == - 1 ) {
F_8 (cpu, cpu_online_mask)
if ( V_10 -- == 0 )
return V_9 ;
} else {
F_28 (cpu, cpumask_of_node(node), cpu_online_mask)
if ( V_10 -- == 0 )
return V_9 ;
F_8 (cpu, cpu_online_mask) {
if ( F_6 ( V_9 , F_29 ( V_16 ) ) )
continue;
if ( V_10 -- == 0 )
return V_9 ;
}
}
F_30 () ;
}
