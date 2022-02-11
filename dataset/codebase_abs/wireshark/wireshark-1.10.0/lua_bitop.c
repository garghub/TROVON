static T_1 F_1 ( T_2 * V_1 , int V_2 )
{
T_3 V_3 ;
T_1 V_4 ;
#if V_5 < 502
V_3 . V_6 = F_2 ( V_1 , V_2 ) ;
#else
V_3 . V_6 = F_3 ( V_1 , V_2 ) ;
#endif
#if F_4 ( V_7 )
V_3 . V_6 += 6755399441055744.0 ;
#ifdef F_5
V_4 = ( T_1 ) ( V_3 . V_4 >> 32 ) ;
#else
V_4 = ( T_1 ) V_3 . V_4 ;
#endif
#elif F_4 ( V_8 ) || F_4 ( V_9 ) || \
F_4 ( V_10 ) || F_4 ( V_11 ) || \
F_4 ( V_12 )
if ( sizeof( T_1 ) == sizeof( V_13 ) )
V_4 = V_3 . V_4 ;
else
V_4 = ( T_1 ) ( V_14 ) V_3 . V_6 ;
#elif F_4 ( V_15 )
#error "A 'float' lua_Number type is incompatible with this library"
#else
#error "Unknown number type, check LUA_NUMBER_* in luaconf.h"
#endif
#if V_5 < 502
if ( V_4 == 0 && ! F_6 ( V_1 , V_2 ) ) {
F_7 ( V_1 , V_2 , L_1 ) ;
}
#endif
return V_4 ;
}
static int F_8 ( T_2 * V_1 ) { F_9 (barg(L, 1)) }
static int F_10 ( T_2 * V_1 ) { F_9 (~barg(L, 1)) }
static int F_11 ( T_2 * V_1 )
{
T_1 V_4 = F_1 ( V_1 , 1 ) ;
V_4 = ( V_4 >> 24 ) | ( ( V_4 >> 8 ) & 0xff00 ) | ( ( V_4 & 0xff00 ) << 8 ) | ( V_4 << 24 ) ;
F_9 (b)
}
static int F_12 ( T_2 * V_1 )
{
T_1 V_4 = F_1 ( V_1 , 1 ) ;
V_14 V_6 = F_13 ( V_1 , 2 ) ? 8 : ( V_14 ) F_1 ( V_1 , 2 ) ;
const char * V_16 = L_2 ;
char V_17 [ 8 ] ;
int V_18 ;
if ( V_6 < 0 ) { V_6 = - V_6 ; V_16 = L_3 ; }
if ( V_6 > 8 ) V_6 = 8 ;
for ( V_18 = ( int ) V_6 ; -- V_18 >= 0 ; ) { V_17 [ V_18 ] = V_16 [ V_4 & 15 ] ; V_4 >>= 4 ; }
F_14 ( V_1 , V_17 , ( V_19 ) V_6 ) ;
return 1 ;
}
T_4 int F_15 ( T_2 * V_1 )
{
T_1 V_4 ;
F_16 ( V_1 , ( V_13 ) 1437217655L ) ;
V_4 = F_1 ( V_1 , - 1 ) ;
if ( V_4 != ( T_1 ) 1437217655L || V_20 ) {
const char * V_21 = L_4 ;
#ifdef V_7
#ifdef F_17
if ( V_4 == ( T_1 ) 1610612736L )
V_21 = L_5 ;
#endif
if ( V_4 == ( T_1 ) 1127743488L )
V_21 = L_6 ;
#endif
if ( V_20 )
V_21 = L_7 ;
F_18 ( V_1 , L_8 , V_21 ) ;
}
#if V_5 < 502
F_19 ( V_1 , L_9 , V_22 ) ;
#else
F_20 ( V_1 , V_22 ) ;
#endif
return 1 ;
}
