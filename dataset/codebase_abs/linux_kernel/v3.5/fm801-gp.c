static int F_1 ( struct V_1 * V_1 , int * V_2 , int * V_3 )
{
unsigned short V_4 ;
V_4 = F_2 ( V_1 -> V_5 + 2 ) ;
* V_3 = ( ~ V_4 >> 14 ) & 0x03 ;
V_2 [ 0 ] = ( V_4 == 0xffff ) ? - 1 : ( ( V_4 & 0x1fff ) << 5 ) ;
V_4 = F_2 ( V_1 -> V_5 + 4 ) ;
V_2 [ 1 ] = ( V_4 == 0xffff ) ? - 1 : ( ( V_4 & 0x1fff ) << 5 ) ;
V_4 = F_2 ( V_1 -> V_5 + 6 ) ;
* V_3 |= ( ( ~ V_4 >> 14 ) & 0x03 ) << 2 ;
V_2 [ 2 ] = ( V_4 == 0xffff ) ? - 1 : ( ( V_4 & 0x1fff ) << 5 ) ;
V_4 = F_2 ( V_1 -> V_5 + 8 ) ;
V_2 [ 3 ] = ( V_4 == 0xffff ) ? - 1 : ( ( V_4 & 0x1fff ) << 5 ) ;
F_3 ( 0xff , V_1 -> V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , int V_6 )
{
switch ( V_6 ) {
#ifdef F_5
case V_7 :
return 0 ;
#endif
case V_8 :
return 0 ;
default:
return - 1 ;
}
return 0 ;
}
static int T_1 F_6 ( struct V_9 * V_10 , const struct V_11 * V_12 )
{
struct V_13 * V_14 ;
struct V_1 * V_15 ;
int error ;
V_14 = F_7 ( sizeof( struct V_13 ) , V_16 ) ;
V_15 = F_8 () ;
if ( ! V_14 || ! V_15 ) {
F_9 ( V_17 L_1 ) ;
error = - V_18 ;
goto V_19;
}
error = F_10 ( V_10 ) ;
if ( error )
goto V_19;
V_15 -> V_20 = F_4 ;
#ifdef F_5
V_15 -> V_21 = F_1 ;
#endif
F_11 ( V_15 , L_2 ) ;
F_12 ( V_15 , L_3 , F_13 ( V_10 ) ) ;
V_15 -> V_22 . V_23 = & V_10 -> V_22 ;
V_15 -> V_5 = F_14 ( V_10 , 0 ) ;
V_14 -> V_1 = V_15 ;
V_14 -> V_24 = F_15 ( V_15 -> V_5 , 0x10 , L_4 ) ;
if ( ! V_14 -> V_24 ) {
F_9 ( V_25 L_5 ,
V_15 -> V_5 , V_15 -> V_5 + 0x0f ) ;
error = - V_26 ;
goto V_27;
}
F_16 ( V_10 , V_14 ) ;
F_17 ( 0x60 , V_15 -> V_5 + 0x0d ) ;
F_18 ( V_15 ) ;
return 0 ;
V_27:
F_19 ( V_10 ) ;
V_19:
F_20 ( V_15 ) ;
F_21 ( V_14 ) ;
return error ;
}
static void T_2 F_22 ( struct V_9 * V_10 )
{
struct V_13 * V_14 = F_23 ( V_10 ) ;
F_24 ( V_14 -> V_1 ) ;
F_25 ( V_14 -> V_24 ) ;
F_21 ( V_14 ) ;
F_19 ( V_10 ) ;
}
