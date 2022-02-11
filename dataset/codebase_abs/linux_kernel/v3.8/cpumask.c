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
int F_7 ( int V_4 , const struct V_6 * V_7 ,
const struct V_6 * V_8 )
{
while ( ( V_4 = F_8 ( V_4 , V_7 ) ) < V_5 )
if ( F_9 ( V_4 , V_8 ) )
break;
return V_4 ;
}
int F_10 ( const struct V_6 * V_9 , unsigned int V_10 )
{
unsigned int V_11 ;
F_11 ( V_10 ) ;
F_12 (i, mask)
if ( V_11 != V_10 )
break;
return V_11 ;
}
bool F_13 ( T_2 * V_9 , T_3 V_12 , int V_13 )
{
* V_9 = F_14 ( F_15 () , V_12 , V_13 ) ;
#ifdef F_16
if ( ! * V_9 ) {
F_17 ( V_14 L_1 ) ;
F_18 () ;
}
#endif
if ( * V_9 ) {
unsigned char * V_15 = ( unsigned char * ) F_19 ( * V_9 ) ;
unsigned int V_16 ;
V_16 = F_20 ( V_2 - V_17 ) * sizeof( long ) ;
memset ( V_15 + F_15 () - V_16 , 0 , V_16 ) ;
}
return * V_9 != NULL ;
}
bool F_21 ( T_2 * V_9 , T_3 V_12 , int V_13 )
{
return F_13 ( V_9 , V_12 | V_18 , V_13 ) ;
}
bool F_22 ( T_2 * V_9 , T_3 V_12 )
{
return F_13 ( V_9 , V_12 , V_19 ) ;
}
bool F_23 ( T_2 * V_9 , T_3 V_12 )
{
return F_22 ( V_9 , V_12 | V_18 ) ;
}
void T_4 F_24 ( T_2 * V_9 )
{
* V_9 = F_25 ( F_15 () ) ;
}
void F_26 ( T_2 V_9 )
{
F_27 ( V_9 ) ;
}
void T_4 F_28 ( T_2 V_9 )
{
F_29 ( F_30 ( V_9 ) , F_15 () ) ;
}
