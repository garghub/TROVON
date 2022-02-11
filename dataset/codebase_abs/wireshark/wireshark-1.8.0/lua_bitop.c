static T_1 F_1 ( T_2 * V_1 , int V_2 )
{
T_3 V_3 ;
T_1 V_4 ;
V_3 . V_5 = F_2 ( V_1 , V_2 ) ;
#if F_3 ( V_6 )
V_3 . V_5 += 6755399441055744.0 ;
#ifdef F_4
V_4 = ( T_1 ) ( V_3 . V_4 >> 32 ) ;
#else
V_4 = ( T_1 ) V_3 . V_4 ;
#endif
#elif F_3 ( V_7 ) || F_3 ( V_8 ) || \
F_3 ( V_9 ) || F_3 ( V_10 ) || \
F_3 ( V_11 )
if ( sizeof( T_1 ) == sizeof( V_12 ) )
V_4 = V_3 . V_4 ;
else
V_4 = ( T_1 ) ( V_13 ) V_3 . V_5 ;
#elif F_3 ( V_14 )
#error "A 'float' lua_Number type is incompatible with this library"
#else
#error "Unknown number type, check LUA_NUMBER_* in luaconf.h"
#endif
if ( V_4 == 0 && ! F_5 ( V_1 , V_2 ) )
F_6 ( V_1 , V_2 , L_1 ) ;
return V_4 ;
}
static int F_7 ( T_2 * V_1 ) { F_8 (barg(L, 1)) }
static int F_9 ( T_2 * V_1 ) { F_8 (~barg(L, 1)) }
static int F_10 ( T_2 * V_1 )
{
T_1 V_4 = F_1 ( V_1 , 1 ) ;
V_4 = ( V_4 >> 24 ) | ( ( V_4 >> 8 ) & 0xff00 ) | ( ( V_4 & 0xff00 ) << 8 ) | ( V_4 << 24 ) ;
F_8 (b)
}
static int F_11 ( T_2 * V_1 )
{
T_1 V_4 = F_1 ( V_1 , 1 ) ;
V_13 V_5 = F_12 ( V_1 , 2 ) ? 8 : ( V_13 ) F_1 ( V_1 , 2 ) ;
const char * V_15 = L_2 ;
char V_16 [ 8 ] ;
int V_17 ;
if ( V_5 < 0 ) { V_5 = - V_5 ; V_15 = L_3 ; }
if ( V_5 > 8 ) V_5 = 8 ;
for ( V_17 = ( int ) V_5 ; -- V_17 >= 0 ; ) { V_16 [ V_17 ] = V_15 [ V_4 & 15 ] ; V_4 >>= 4 ; }
F_13 ( V_1 , V_16 , ( V_18 ) V_5 ) ;
return 1 ;
}
T_4 int F_14 ( T_2 * V_1 )
{
T_1 V_4 ;
F_15 ( V_1 , ( V_12 ) 1437217655L ) ;
V_4 = F_1 ( V_1 , - 1 ) ;
if ( V_4 != ( T_1 ) 1437217655L || V_19 ) {
const char * V_20 = L_4 ;
#ifdef V_6
#ifdef F_16
if ( V_4 == ( T_1 ) 1610612736L )
V_20 = L_5 ;
#endif
if ( V_4 == ( T_1 ) 1127743488L )
V_20 = L_6 ;
#endif
if ( V_19 )
V_20 = L_7 ;
F_17 ( V_1 , L_8 , V_20 ) ;
}
F_18 ( V_1 , L_9 , V_21 ) ;
return 1 ;
}
