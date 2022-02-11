T_1 * F_1 ( const unsigned char * V_1 , int V_2 , T_2 * V_3 )
{
#ifdef F_2
if ( F_3 () && ! ( V_3 -> V_4 -> V_5 & V_6 )
&& ! ( V_3 -> V_5 & V_7 ) ) {
F_4 ( V_8 , V_9 ) ;
return NULL ;
}
#endif
return V_3 -> V_4 -> V_10 ( V_1 , V_2 , V_3 ) ;
}
int F_5 ( T_2 * V_3 , T_3 * V_11 , T_4 * * V_12 , T_4 * * V_13 )
{
#ifdef F_2
if ( F_3 () && ! ( V_3 -> V_4 -> V_5 & V_6 )
&& ! ( V_3 -> V_5 & V_7 ) ) {
F_4 ( V_14 , V_9 ) ;
return 0 ;
}
#endif
return V_3 -> V_4 -> V_15 ( V_3 , V_11 , V_12 , V_13 ) ;
}
T_1 * F_6 ( void )
{
T_1 * V_16 ;
V_16 = F_7 ( sizeof( T_1 ) ) ;
if ( ! V_16 )
return NULL ;
V_16 -> V_17 = NULL ;
V_16 -> V_18 = NULL ;
return V_16 ;
}
void F_8 ( T_1 * V_16 )
{
if ( V_16 ) {
if ( V_16 -> V_17 )
F_9 ( V_16 -> V_17 ) ;
if ( V_16 -> V_18 )
F_9 ( V_16 -> V_18 ) ;
F_10 ( V_16 ) ;
}
}
