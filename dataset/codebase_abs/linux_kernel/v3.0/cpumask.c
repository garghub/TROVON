int F_1 ( const T_1 * V_1 )
{
return F_2 ( int , V_2 , F_3 ( V_1 -> V_3 , V_2 ) ) ;
}
int F_4 ( int V_4 , const T_1 * V_1 )
{
return F_2 ( int , V_2 , F_5 ( V_1 -> V_3 , V_2 , V_4 + 1 ) ) ;
}
int F_6 ( int V_4 , const T_1 * V_1 )
{
return F_2 ( int , V_5 ,
F_5 ( V_1 -> V_3 , V_5 , V_4 + 1 ) ) ;
}
int F_7 ( const T_1 * V_6 )
{
int V_7 ;
F_8 (cpu, *mask) {
if ( F_9 ( V_7 ) )
break;
}
return V_7 ;
}
int F_10 ( int V_4 , const struct V_8 * V_9 ,
const struct V_8 * V_10 )
{
while ( ( V_4 = F_11 ( V_4 , V_9 ) ) < V_5 )
if ( F_12 ( V_4 , V_10 ) )
break;
return V_4 ;
}
int F_13 ( const struct V_8 * V_6 , unsigned int V_7 )
{
unsigned int V_11 ;
F_14 ( V_7 ) ;
F_15 (i, mask)
if ( V_11 != V_7 )
break;
return V_11 ;
}
bool F_16 ( T_2 * V_6 , T_3 V_12 , int V_13 )
{
* V_6 = F_17 ( F_18 () , V_12 , V_13 ) ;
#ifdef F_19
if ( ! * V_6 ) {
F_20 ( V_14 L_1 ) ;
F_21 () ;
}
#endif
if ( * V_6 ) {
unsigned char * V_15 = ( unsigned char * ) F_22 ( * V_6 ) ;
unsigned int V_16 ;
V_16 = F_23 ( V_2 - V_17 ) * sizeof( long ) ;
memset ( V_15 + F_18 () - V_16 , 0 , V_16 ) ;
}
return * V_6 != NULL ;
}
bool F_24 ( T_2 * V_6 , T_3 V_12 , int V_13 )
{
return F_16 ( V_6 , V_12 | V_18 , V_13 ) ;
}
bool F_25 ( T_2 * V_6 , T_3 V_12 )
{
return F_16 ( V_6 , V_12 , F_26 () ) ;
}
bool F_27 ( T_2 * V_6 , T_3 V_12 )
{
return F_25 ( V_6 , V_12 | V_18 ) ;
}
void T_4 F_28 ( T_2 * V_6 )
{
* V_6 = F_29 ( F_18 () ) ;
}
void F_30 ( T_2 V_6 )
{
F_31 ( V_6 ) ;
}
void T_4 F_32 ( T_2 V_6 )
{
F_33 ( ( unsigned long ) V_6 , F_18 () ) ;
}
