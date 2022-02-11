T_1 * F_1 ( const T_2 * V_1 , const T_2 * V_2 , const T_2 * V_3 , T_3 * V_4 )
{
const T_4 * V_5 ;
T_1 * V_6 ;
#if F_2 ( V_7 )
V_5 = F_3 () ;
#else
V_5 = F_4 () ;
#endif
V_6 = F_5 ( V_5 ) ;
if ( V_6 == NULL )
return NULL ;
if ( ! F_6 ( V_6 , V_1 , V_2 , V_3 , V_4 ) )
{
unsigned long V_8 ;
V_8 = F_7 () ;
if ( ! ( F_8 ( V_8 ) == V_9 &&
( ( F_9 ( V_8 ) == V_10 ) ||
( F_9 ( V_8 ) == V_11 ) ) ) )
{
F_10 ( V_6 ) ;
return NULL ;
}
F_11 () ;
F_10 ( V_6 ) ;
V_5 = F_3 () ;
V_6 = F_5 ( V_5 ) ;
if ( V_6 == NULL )
return NULL ;
if ( ! F_6 ( V_6 , V_1 , V_2 , V_3 , V_4 ) )
{
F_10 ( V_6 ) ;
return NULL ;
}
}
return V_6 ;
}
T_1 * F_12 ( const T_2 * V_1 , const T_2 * V_2 , const T_2 * V_3 , T_3 * V_4 )
{
const T_4 * V_5 ;
T_1 * V_6 ;
V_5 = F_13 () ;
V_6 = F_5 ( V_5 ) ;
if ( V_6 == NULL )
return NULL ;
if ( ! F_14 ( V_6 , V_1 , V_2 , V_3 , V_4 ) )
{
F_10 ( V_6 ) ;
return NULL ;
}
return V_6 ;
}
