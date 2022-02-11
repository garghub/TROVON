T_1 * F_1 ( const T_2 * V_1 , const T_2 * V_2 , const T_2 * V_3 , T_3 * V_4 )
{
const T_4 * V_5 ;
T_1 * V_6 ;
V_5 = F_2 () ;
V_6 = F_3 ( V_5 ) ;
if ( V_6 == NULL )
return NULL ;
if ( ! F_4 ( V_6 , V_1 , V_2 , V_3 , V_4 ) )
{
unsigned long V_7 ;
V_7 = F_5 () ;
if ( ! ( F_6 ( V_7 ) == V_8 &&
( ( F_7 ( V_7 ) == V_9 ) ||
( F_7 ( V_7 ) == V_10 ) ) ) )
{
F_8 ( V_6 ) ;
return NULL ;
}
F_9 () ;
F_8 ( V_6 ) ;
V_5 = F_10 () ;
V_6 = F_3 ( V_5 ) ;
if ( V_6 == NULL )
return NULL ;
if ( ! F_4 ( V_6 , V_1 , V_2 , V_3 , V_4 ) )
{
F_8 ( V_6 ) ;
return NULL ;
}
}
return V_6 ;
}
T_1 * F_11 ( const T_2 * V_1 , const T_2 * V_2 , const T_2 * V_3 , T_3 * V_4 )
{
const T_4 * V_5 ;
T_1 * V_6 ;
V_5 = F_12 () ;
V_6 = F_3 ( V_5 ) ;
if ( V_6 == NULL )
return NULL ;
if ( ! F_13 ( V_6 , V_1 , V_2 , V_3 , V_4 ) )
{
F_8 ( V_6 ) ;
return NULL ;
}
return V_6 ;
}
