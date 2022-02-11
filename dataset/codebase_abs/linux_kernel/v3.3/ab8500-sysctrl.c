static inline bool F_1 ( T_1 V_1 )
{
return ( ( V_1 == V_2 ) ||
( V_1 == V_3 ) ) ;
}
int F_2 ( T_2 V_4 , T_1 * V_5 )
{
T_1 V_1 ;
if ( V_6 == NULL )
return - V_7 ;
V_1 = ( V_4 >> 8 ) ;
if ( ! F_1 ( V_1 ) )
return - V_8 ;
return F_3 ( V_6 , V_1 ,
( T_1 ) ( V_4 & 0xFF ) , V_5 ) ;
}
int F_4 ( T_2 V_4 , T_1 V_9 , T_1 V_5 )
{
T_1 V_1 ;
if ( V_6 == NULL )
return - V_7 ;
V_1 = ( V_4 >> 8 ) ;
if ( ! F_1 ( V_1 ) )
return - V_8 ;
return F_5 ( V_6 , V_1 ,
( T_1 ) ( V_4 & 0xFF ) , V_9 , V_5 ) ;
}
static int T_3 F_6 ( struct V_10 * V_11 )
{
V_6 = & V_11 -> V_12 ;
return 0 ;
}
static int T_4 F_7 ( struct V_10 * V_11 )
{
V_6 = NULL ;
return 0 ;
}
static int T_5 F_8 ( void )
{
return F_9 ( & V_13 ) ;
}
