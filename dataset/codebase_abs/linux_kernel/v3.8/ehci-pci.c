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
struct V_3 * V_10 ;
T_1 V_11 ;
T_2 V_12 ;
int V_5 ;
V_2 -> V_13 = V_7 -> V_14 ;
switch ( V_4 -> V_15 ) {
case V_16 :
if ( V_4 -> V_17 == 0x01b5 ) {
#ifdef F_7
V_2 -> V_18 = 1 ;
#else
F_8 ( V_2 ,
L_2 ) ;
#endif
}
break;
case V_19 :
switch ( V_4 -> V_17 ) {
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
if ( V_4 -> V_20 < 0xa4 )
V_2 -> V_21 = 1 ;
break;
}
break;
case V_22 :
if ( V_4 -> V_17 == V_23 )
V_7 -> V_24 = 1 ;
break;
case V_25 :
if ( V_4 -> V_17 == V_26 )
V_7 -> V_24 = 1 ;
break;
case V_27 :
if ( F_11 () )
V_2 -> V_28 = 1 ;
if ( V_4 -> V_17 == 0x7463 ) {
F_12 ( V_2 , L_5 ) ;
V_5 = - V_29 ;
goto V_30;
}
if ( V_4 -> V_17 == 0x7808 ) {
V_2 -> V_31 = 1 ;
F_12 ( V_2 , L_6 ) ;
}
break;
case V_32 :
if ( V_4 -> V_17 == 0x3104 && ( V_4 -> V_20 & 0xf0 ) == 0x60 ) {
T_1 V_33 ;
F_13 ( V_4 , 0x4b , & V_33 ) ;
if ( V_33 & 0x20 )
break;
F_14 ( V_4 , 0x4b , V_33 | 0x20 ) ;
}
break;
case V_34 :
if ( F_11 () )
V_2 -> V_28 = 1 ;
if ( V_4 -> V_17 == 0x4396 ) {
V_2 -> V_31 = 1 ;
F_12 ( V_2 , L_6 ) ;
}
if ( ( V_4 -> V_17 == 0x4386 ) || ( V_4 -> V_17 == 0x4396 ) ) {
V_10 = F_15 ( V_34 ,
V_35 ,
NULL ) ;
if ( ! V_10 )
break;
V_11 = V_10 -> V_20 ;
if ( ( V_4 -> V_17 == 0x4386 ) || ( V_11 == 0x3a )
|| ( V_11 == 0x3b ) ) {
T_1 V_33 ;
F_12 ( V_2 , L_7
L_8 ) ;
F_13 ( V_4 , 0x53 , & V_33 ) ;
F_14 ( V_4 , 0x53 , V_33 | ( 1 << 3 ) ) ;
}
F_16 ( V_10 ) ;
}
break;
case V_36 :
F_12 ( V_2 , L_9 ) ;
V_2 -> V_37 = 1 ;
break;
}
V_12 = F_17 ( V_4 , V_38 ) ;
if ( V_12 ) {
F_18 ( V_4 , V_12 , & V_12 ) ;
V_12 >>= 16 ;
if ( ( ( V_12 >> 13 ) & 7 ) == 1 ) {
T_2 V_39 = F_19 ( V_2 ,
& V_2 -> V_13 -> V_39 ) ;
V_12 &= 0x1fff ;
V_2 -> V_40 = V_7 -> V_14 + V_12 ;
V_12 = F_19 ( V_2 , & V_2 -> V_40 -> V_41 ) ;
F_12 ( V_2 , L_10 ,
F_20 ( V_39 ) ,
( V_12 & V_42 ) ? L_11 : L_12 ) ;
if ( ! ( V_12 & V_42 ) )
V_2 -> V_40 = NULL ;
}
}
V_5 = F_21 ( V_7 ) ;
if ( V_5 )
return V_5 ;
switch ( V_4 -> V_15 ) {
case V_43 :
V_2 -> V_44 = 0 ;
break;
case V_22 :
V_2 -> V_44 = 0 ;
break;
case V_19 :
switch ( V_4 -> V_17 ) {
case 0x0d9d :
F_12 ( V_2 , L_13 ) ;
V_2 -> V_45 = 0 ;
V_2 -> V_46 &= ~ V_47 ;
break;
}
break;
}
V_12 = F_22 ( V_2 -> V_39 ) * F_23 ( V_2 -> V_39 ) ;
V_12 &= 0x0f ;
if ( V_12 && F_24 ( V_2 -> V_39 ) > V_12 ) {
F_3 ( V_2 , L_14
L_15 ,
F_22 ( V_2 -> V_39 ) ,
F_23 ( V_2 -> V_39 ) ,
F_24 ( V_2 -> V_39 ) ) ;
switch ( V_4 -> V_15 ) {
case 0x17a0 :
V_12 |= ( V_2 -> V_39 & ~ 0xf ) ;
V_2 -> V_39 = V_12 ;
break;
case V_19 :
break;
}
}
if ( V_4 -> V_15 == V_48
&& V_4 -> V_17 == V_49 )
;
else
F_13 ( V_4 , 0x60 , & V_2 -> V_50 ) ;
if ( ! F_25 ( & V_4 -> V_51 ) ) {
T_3 V_52 ;
F_26 ( V_4 , 0x62 , & V_52 ) ;
if ( V_52 & 0x0001 ) {
F_27 ( & V_4 -> V_51 , L_16 ) ;
F_28 ( & V_4 -> V_51 , 1 ) ;
}
}
#ifdef F_29
if ( V_2 -> V_21 && F_25 ( & V_4 -> V_51 ) )
F_8 ( V_2 , L_17 ) ;
#endif
V_5 = F_1 ( V_2 , V_4 ) ;
V_30:
return V_5 ;
}
static bool F_30 ( struct V_3 * V_4 )
{
return V_4 -> V_53 == V_54 &&
V_4 -> V_15 == V_22 &&
( V_4 -> V_17 == 0x1E26 ||
V_4 -> V_17 == 0x8C2D ||
V_4 -> V_17 == 0x8C26 ||
V_4 -> V_17 == 0x9C26 ) ;
}
static void F_31 ( void )
{
struct V_3 * V_55 = NULL ;
F_32 (companion) {
if ( ! F_33 ( V_55 ) )
continue;
F_34 ( V_55 ) ;
return;
}
}
static int F_35 ( struct V_6 * V_7 , bool V_56 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_3 * V_4 = F_6 ( V_7 -> V_8 . V_9 ) ;
if ( F_30 ( V_4 ) )
F_31 () ;
if ( F_36 ( V_7 , V_56 ) != 0 )
( void ) F_1 ( V_2 , V_4 ) ;
return 0 ;
}
static int T_4 F_37 ( void )
{
if ( F_38 () )
return - V_57 ;
F_39 ( L_18 V_58 L_19 , V_59 ) ;
F_40 ( & V_60 , & V_61 ) ;
V_60 . V_62 = V_63 ;
V_60 . V_64 = F_35 ;
return F_41 ( & V_65 ) ;
}
static void T_5 F_42 ( void )
{
F_43 ( & V_65 ) ;
}
