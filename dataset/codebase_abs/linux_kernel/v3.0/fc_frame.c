T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 error ;
const T_2 * V_4 ;
unsigned int V_5 ;
F_2 ( ! F_3 ( V_2 ) ) ;
F_4 ( V_2 ) &= ~ V_6 ;
V_5 = ( F_5 ( V_2 ) + 3 ) & ~ 3 ;
V_4 = ( const T_2 * ) F_6 ( V_2 ) ;
V_3 = ~ F_7 ( ~ 0 , V_4 , V_5 ) ;
error = V_3 ^ F_8 ( V_2 ) ;
return error ;
}
struct V_1 * F_9 ( T_3 V_5 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
F_2 ( ( V_5 % sizeof( T_1 ) ) != 0 ) ;
V_5 += sizeof( struct V_9 ) ;
V_8 = F_10 ( V_5 + V_10 + V_11 +
V_12 , V_13 ) ;
if ( ! V_8 )
return NULL ;
F_11 ( V_8 , V_12 + V_10 ) ;
V_2 = (struct V_1 * ) V_8 ;
F_12 ( V_2 ) ;
F_13 ( V_8 , V_5 ) ;
return V_2 ;
}
struct V_1 * F_14 ( struct V_14 * V_15 , T_3 V_16 )
{
struct V_1 * V_2 ;
T_3 V_17 ;
V_17 = V_16 % 4 ;
if ( V_17 != 0 )
V_17 = 4 - V_17 ;
V_2 = F_9 ( V_16 + V_17 ) ;
if ( V_2 ) {
memset ( ( char * ) F_6 ( V_2 ) + V_16 , 0 , V_17 ) ;
F_15 ( F_16 ( V_2 ) ,
V_16 + sizeof( struct V_9 ) ) ;
}
return V_2 ;
}
