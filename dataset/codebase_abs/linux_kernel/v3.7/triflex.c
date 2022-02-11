static void F_1 ( T_1 * V_1 , T_2 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 -> V_4 ) ;
T_3 V_5 = 0 ;
T_4 V_6 = 0 ;
T_5 V_7 = V_1 -> V_8 ? 0x74 : 0x70 , V_9 = V_2 -> V_10 & 1 ;
F_3 ( V_4 , V_7 , & V_5 ) ;
switch ( V_2 -> V_11 ) {
case V_12 :
V_6 = 0x0103 ;
break;
case V_13 :
V_6 = 0x0203 ;
break;
case V_14 :
V_6 = 0x0808 ;
break;
case V_15 :
case V_16 :
case V_17 :
V_6 = 0x0f0f ;
break;
case V_18 :
V_6 = 0x0202 ;
break;
case V_19 :
V_6 = 0x0204 ;
break;
case V_20 :
V_6 = 0x0404 ;
break;
case V_21 :
V_6 = 0x0508 ;
break;
case V_22 :
V_6 = 0x0808 ;
break;
}
V_5 &= ~ ( 0xFFFF << ( 16 * V_9 ) ) ;
V_5 |= ( V_6 << ( 16 * V_9 ) ) ;
F_4 ( V_4 , V_7 , V_5 ) ;
}
static void F_5 ( T_1 * V_1 , T_2 * V_2 )
{
V_2 -> V_11 = V_2 -> V_23 ;
F_1 ( V_1 , V_2 ) ;
}
static int T_6 F_6 ( struct V_3 * V_4 ,
const struct V_24 * V_25 )
{
return F_7 ( V_4 , & V_26 , NULL ) ;
}
static int F_8 ( struct V_3 * V_4 , T_7 V_27 )
{
F_9 ( V_4 ) ;
return 0 ;
}
static int T_8 F_10 ( void )
{
return F_11 ( & V_28 ) ;
}
static void T_9 F_12 ( void )
{
F_13 ( & V_28 ) ;
}
