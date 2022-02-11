static void F_1 ( T_1 * V_1 )
{
V_1 -> V_2 [ V_3 ] |= 0x4000 ;
}
static int T_2 F_2 ( struct V_4 * V_5 , const struct V_6 * V_2 )
{
const struct V_7 * V_8 = & V_9 [ V_2 -> V_10 ] ;
int V_11 = - V_12 ;
if ( V_2 -> V_10 == 0 && V_13 == 0 )
goto V_14;
switch ( V_5 -> V_15 ) {
case V_16 :
if ( V_5 -> V_17 == V_18 &&
! ( F_3 ( V_5 -> V_19 ) & 1 ) )
goto V_14;
break;
case V_20 :
if ( V_5 -> V_17 == V_21 &&
! ( F_3 ( V_5 -> V_19 ) & 1 ) )
goto V_14;
break;
case V_22 :
if ( V_5 -> V_17 != V_23 &&
F_3 ( V_5 -> V_19 ) != 1 )
goto V_14;
break;
case V_24 :
if ( V_5 -> V_17 == V_25 &&
( V_5 -> V_26 >> 8 ) != V_27 )
goto V_14;
break;
}
if ( V_5 -> V_15 != V_22 ) {
T_3 V_28 ;
F_4 ( V_5 , V_29 , & V_28 ) ;
if ( ! ( V_28 & V_30 ) ) {
F_5 ( V_31 L_1
L_2 , V_8 -> V_32 , F_6 ( V_5 ) ) ;
goto V_14;
}
}
V_11 = F_7 ( V_5 , V_8 , NULL ) ;
V_14:
return V_11 ;
}
static int T_4 F_8 ( void )
{
return F_9 ( & V_33 ) ;
}
static void T_5 F_10 ( void )
{
F_11 ( & V_33 ) ;
}
