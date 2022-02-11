static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_4 ) ;
if ( ! V_5 )
F_3 ( V_2 , L_1 ) ;
return 0 ;
}
static int F_4 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_3 * V_4 = F_6 ( V_7 -> V_8 . V_9 ) ;
T_1 V_10 ;
int V_5 ;
V_2 -> V_11 = V_7 -> V_12 ;
switch ( V_4 -> V_13 ) {
case V_14 :
if ( V_4 -> V_15 == 0x01b5 ) {
#ifdef F_7
V_2 -> V_16 = 1 ;
#else
F_8 ( V_2 ,
L_2 ) ;
#endif
}
break;
case V_17 :
switch ( V_4 -> V_15 ) {
case 0x003c :
case 0x005b :
case 0x00d8 :
case 0x00e8 :
if ( F_9 ( V_4 ,
F_10 ( 31 ) ) < 0 )
F_8 ( V_2 , L_3
L_4 ) ;
break;
case 0x0068 :
if ( V_4 -> V_18 < 0xa4 )
V_2 -> V_19 = 1 ;
break;
}
break;
case V_20 :
if ( V_4 -> V_15 == V_21 )
V_7 -> V_22 = 1 ;
break;
case V_23 :
if ( V_4 -> V_15 == V_24 )
V_7 -> V_22 = 1 ;
break;
case V_25 :
if ( F_11 () )
V_2 -> V_26 = 1 ;
if ( V_4 -> V_15 == 0x7463 ) {
F_12 ( V_2 , L_5 ) ;
V_5 = - V_27 ;
goto V_28;
}
if ( V_4 -> V_15 == 0x7808 ) {
V_2 -> V_29 = 1 ;
F_12 ( V_2 , L_6 ) ;
}
break;
case V_30 :
if ( V_4 -> V_15 == 0x3104 && ( V_4 -> V_18 & 0xf0 ) == 0x60 ) {
T_2 V_31 ;
F_13 ( V_4 , 0x4b , & V_31 ) ;
if ( V_31 & 0x20 )
break;
F_14 ( V_4 , 0x4b , V_31 | 0x20 ) ;
}
break;
case V_32 :
if ( F_11 () )
V_2 -> V_26 = 1 ;
if ( V_4 -> V_15 == 0x4396 ) {
V_2 -> V_29 = 1 ;
F_12 ( V_2 , L_6 ) ;
}
if ( ( V_4 -> V_15 == 0x4386 || V_4 -> V_15 == 0x4396 ) &&
F_15 () ) {
T_2 V_31 ;
F_12 ( V_2 , L_7 ) ;
F_13 ( V_4 , 0x53 , & V_31 ) ;
F_14 ( V_4 , 0x53 , V_31 | ( 1 << 3 ) ) ;
}
break;
case V_33 :
F_12 ( V_2 , L_8 ) ;
V_2 -> V_34 = 1 ;
break;
}
V_10 = F_16 ( V_4 , V_35 ) ;
if ( V_10 ) {
F_17 ( V_4 , V_10 , & V_10 ) ;
V_10 >>= 16 ;
if ( ( ( V_10 >> 13 ) & 7 ) == 1 ) {
T_1 V_36 = F_18 ( V_2 ,
& V_2 -> V_11 -> V_36 ) ;
V_10 &= 0x1fff ;
V_2 -> V_37 = V_7 -> V_12 + V_10 ;
V_10 = F_18 ( V_2 , & V_2 -> V_37 -> V_38 ) ;
F_12 ( V_2 , L_9 ,
F_19 ( V_36 ) ,
( V_10 & V_39 ) ? L_10 : L_11 ) ;
if ( ! ( V_10 & V_39 ) )
V_2 -> V_37 = NULL ;
}
}
V_5 = F_20 ( V_7 ) ;
if ( V_5 )
return V_5 ;
switch ( V_4 -> V_13 ) {
case V_40 :
V_2 -> V_41 = 0 ;
break;
case V_20 :
V_2 -> V_41 = 0 ;
break;
case V_17 :
switch ( V_4 -> V_15 ) {
case 0x0d9d :
F_12 ( V_2 , L_12 ) ;
V_2 -> V_42 = 0 ;
V_2 -> V_43 &= ~ V_44 ;
break;
}
break;
}
V_10 = F_21 ( V_2 -> V_36 ) * F_22 ( V_2 -> V_36 ) ;
V_10 &= 0x0f ;
if ( V_10 && F_23 ( V_2 -> V_36 ) > V_10 ) {
F_3 ( V_2 , L_13
L_14 ,
F_21 ( V_2 -> V_36 ) ,
F_22 ( V_2 -> V_36 ) ,
F_23 ( V_2 -> V_36 ) ) ;
switch ( V_4 -> V_13 ) {
case 0x17a0 :
V_10 |= ( V_2 -> V_36 & ~ 0xf ) ;
V_2 -> V_36 = V_10 ;
break;
case V_17 :
break;
}
}
if ( V_4 -> V_13 == V_45
&& V_4 -> V_15 == V_46 )
;
else
F_13 ( V_4 , 0x60 , & V_2 -> V_47 ) ;
if ( ! F_24 ( & V_4 -> V_48 ) ) {
T_3 V_49 ;
F_25 ( V_4 , 0x62 , & V_49 ) ;
if ( V_49 & 0x0001 ) {
F_26 ( & V_4 -> V_48 , L_15 ) ;
F_27 ( & V_4 -> V_48 , 1 ) ;
}
}
#ifdef F_28
if ( V_2 -> V_19 && F_24 ( & V_4 -> V_48 ) )
F_8 ( V_2 , L_16 ) ;
#endif
V_5 = F_1 ( V_2 , V_4 ) ;
V_28:
return V_5 ;
}
static int F_29 ( struct V_6 * V_7 , bool V_50 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_3 * V_4 = F_6 ( V_7 -> V_8 . V_9 ) ;
if ( F_30 ( V_7 , V_50 ) != 0 )
( void ) F_1 ( V_2 , V_4 ) ;
return 0 ;
}
static int T_4 F_31 ( void )
{
if ( F_32 () )
return - V_51 ;
F_33 ( L_17 V_52 L_18 , V_53 ) ;
F_34 ( & V_54 , & V_55 ) ;
V_54 . V_56 = V_57 ;
V_54 . V_58 = F_29 ;
return F_35 ( & V_59 ) ;
}
static void T_5 F_36 ( void )
{
F_37 ( & V_59 ) ;
}
