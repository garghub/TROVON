static void F_1 ( void * V_1 , int V_2 )
{
F_2 ( V_2 ? F_3 ( V_3 ) & ~ V_4 : F_3 ( V_3 ) | V_4 , V_3 ) ;
}
static void F_4 ( void * V_1 , int V_2 )
{
F_2 ( V_2 ? F_3 ( V_3 ) & ~ V_5 : F_3 ( V_3 ) | V_5 , V_3 ) ;
}
static int F_5 ( void * V_1 )
{
return ( 0 != ( F_3 ( V_6 ) & V_4 ) ) ;
}
static int F_6 ( void * V_1 )
{
return ( 0 != ( F_3 ( V_6 ) & V_5 ) ) ;
}
static int T_1 F_7 ( struct V_7 * V_8 , const struct V_9 * V_10 )
{
T_2 V_11 ;
T_3 V_12 ;
int V_13 ;
if ( V_14 ) {
F_8 ( & V_8 -> V_8 , L_1 ) ;
return - V_15 ;
}
F_9 ( V_8 , V_16 , & V_12 ) ;
switch ( V_12 ) {
case 0x00 :
V_11 = V_17 ;
break;
case 0x01 :
case 0x10 :
V_11 = V_18 ;
break;
default:
V_11 = V_18 ;
}
F_10 ( V_8 , V_11 , & V_14 ) ;
V_14 &= ( 0xff << 8 ) ;
if ( ! F_11 ( V_3 , V_19 , V_20 . V_21 ) ) {
F_8 ( & V_8 -> V_8 , L_2 , V_3 , V_3 + V_19 ) ;
return - V_15 ;
}
F_2 ( F_3 ( V_3 ) & ~ ( V_5 | V_4 ) , V_3 ) ;
F_2 ( F_3 ( V_22 ) & ~ ( V_5 | V_4 ) , V_22 ) ;
V_23 . V_8 . V_24 = & V_8 -> V_8 ;
V_13 = F_12 ( & V_23 ) ;
if ( V_13 < 0 ) {
F_13 ( V_3 , V_19 ) ;
V_14 = 0 ;
return V_13 ;
}
return 0 ;
}
static void T_4 F_14 ( struct V_7 * V_8 )
{
F_15 ( & V_23 ) ;
F_13 ( V_3 , V_19 ) ;
V_14 = 0 ;
}
static int T_5 F_16 ( void )
{
return F_17 ( & V_20 ) ;
}
static void T_6 F_18 ( void )
{
F_19 ( & V_20 ) ;
}
