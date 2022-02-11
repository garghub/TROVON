T_1 * F_1 ( void )
{
T_1 * V_1 =
( T_1 * ) F_2 ( sizeof( T_1 ) ) ;
if ( V_1 )
memset ( V_1 , 0 , sizeof( T_1 ) ) ;
else
F_3 ( V_2 , V_3 ) ;
return V_1 ;
}
void F_4 ( T_1 * V_1 )
{
F_5 ( V_1 != NULL ) ;
memset ( V_1 , 0 , sizeof( T_1 ) ) ;
}
void F_6 ( T_1 * V_1 )
{
if ( ! V_1 ) return;
F_7 ( V_1 ) ;
F_8 ( V_1 ) ;
}
void F_7 ( T_1 * V_1 )
{
if ( ! V_1 ) return;
F_9 ( V_1 -> V_4 ) ;
F_10 ( V_1 -> V_5 , V_6 ) ;
F_11 ( V_1 -> V_7 ) ;
F_12 ( V_1 -> V_8 ) ;
F_8 ( V_1 -> V_9 ) ;
F_13 ( V_1 -> V_10 ) ;
F_14 ( V_1 -> V_11 ) ;
F_15 ( V_1 -> V_12 ) ;
F_4 ( V_1 ) ;
}
T_1 * F_16 ( T_2 * V_13 , T_1 * V_1 )
{
T_1 * V_14 = V_1 ;
T_3 * V_7 ;
T_4 * V_9 ;
T_5 * V_8 ;
T_6 * V_15 ;
const T_7 * V_11 ;
F_5 ( V_13 != NULL ) ;
if ( V_14 )
F_7 ( V_14 ) ;
else
if ( ! ( V_14 = F_1 () ) ) return NULL ;
V_14 -> V_16 = V_17 & ~ ( V_18 | V_19 ) ;
if ( ( V_7 = F_17 ( V_13 ) ) != NULL )
{
if ( ! ( V_14 -> V_7 = F_18 ( V_7 ) ) ) goto V_20;
}
else
V_14 -> V_16 &= ~ V_21 ;
V_9 = F_19 ( V_13 ) ;
V_8 = F_20 ( V_9 ) ;
if ( ! ( V_14 -> V_8 = F_21 ( V_8 ) ) ) goto V_20;
V_15 = F_22 ( V_9 ) ;
V_14 -> V_22 = F_23 ( V_15 ) ;
if ( ! ( V_14 -> V_9 = F_2 ( V_14 -> V_22 ) ) ) goto V_20;
memcpy ( V_14 -> V_9 , F_24 ( V_15 ) , V_14 -> V_22 ) ;
if ( ( V_11 = F_25 ( V_13 ) ) != NULL )
{
if ( ! ( V_14 -> V_11 = F_26 ( V_11 ) ) ) goto V_20;
}
else
V_14 -> V_16 &= ~ V_23 ;
return V_14 ;
V_20:
if ( V_1 )
F_7 ( V_1 ) ;
else
F_6 ( V_14 ) ;
return NULL ;
}
