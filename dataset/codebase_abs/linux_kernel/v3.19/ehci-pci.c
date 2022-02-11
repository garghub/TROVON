static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 &&
V_2 -> V_5 == V_6 ;
}
static int F_2 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
int V_9 ;
V_9 = F_3 ( V_2 ) ;
if ( ! V_9 )
F_4 ( V_8 , L_1 ) ;
if ( F_1 ( V_2 ) ) {
F_5 ( V_8 , V_10 ,
V_8 -> V_11 -> V_12 ) ;
}
return 0 ;
}
static int F_6 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = F_7 ( V_14 ) ;
struct V_1 * V_2 = F_8 ( V_14 -> V_15 . V_16 ) ;
T_1 V_17 ;
int V_9 ;
V_8 -> V_18 = V_14 -> V_11 ;
switch ( V_2 -> V_3 ) {
case V_19 :
if ( V_2 -> V_5 == 0x01b5 ) {
#ifdef F_9
V_8 -> V_20 = 1 ;
#else
F_10 ( V_8 ,
L_2 ) ;
#endif
}
break;
case V_21 :
switch ( V_2 -> V_5 ) {
case 0x003c :
case 0x005b :
case 0x00d8 :
case 0x00e8 :
if ( F_11 ( V_2 ,
F_12 ( 31 ) ) < 0 )
F_10 ( V_8 , L_3
L_4 ) ;
break;
case 0x0068 :
if ( V_2 -> V_22 < 0xa4 )
V_8 -> V_23 = 1 ;
break;
}
break;
case V_4 :
if ( V_2 -> V_5 == V_24 )
V_14 -> V_25 = 1 ;
break;
case V_26 :
if ( V_2 -> V_5 == V_27 )
V_14 -> V_25 = 1 ;
break;
case V_28 :
if ( F_13 () )
V_8 -> V_29 = 1 ;
if ( V_2 -> V_5 == 0x7463 ) {
F_14 ( V_8 , L_5 ) ;
V_9 = - V_30 ;
goto V_31;
}
if ( V_2 -> V_5 == 0x7808 ) {
V_8 -> V_32 = 1 ;
F_14 ( V_8 , L_6 ) ;
}
break;
case V_33 :
if ( V_2 -> V_5 == 0x3104 && ( V_2 -> V_22 & 0xf0 ) == 0x60 ) {
T_2 V_34 ;
F_15 ( V_2 , 0x4b , & V_34 ) ;
if ( V_34 & 0x20 )
break;
F_16 ( V_2 , 0x4b , V_34 | 0x20 ) ;
}
break;
case V_35 :
if ( F_13 () )
V_8 -> V_29 = 1 ;
if ( V_2 -> V_5 == 0x4396 ) {
V_8 -> V_32 = 1 ;
F_14 ( V_8 , L_6 ) ;
}
if ( ( V_2 -> V_5 == 0x4386 || V_2 -> V_5 == 0x4396 ) &&
F_17 () ) {
T_2 V_34 ;
F_14 ( V_8 , L_7 ) ;
F_15 ( V_2 , 0x53 , & V_34 ) ;
F_16 ( V_2 , 0x53 , V_34 | ( 1 << 3 ) ) ;
}
break;
case V_36 :
F_14 ( V_8 , L_8 ) ;
V_8 -> V_37 = 1 ;
break;
}
V_17 = F_18 ( V_2 , V_38 ) ;
if ( V_17 ) {
F_19 ( V_2 , V_17 , & V_17 ) ;
V_17 >>= 16 ;
if ( ( ( V_17 >> 13 ) & 7 ) == 1 ) {
T_1 V_39 = F_20 ( V_8 ,
& V_8 -> V_18 -> V_39 ) ;
V_17 &= 0x1fff ;
V_8 -> V_40 = V_14 -> V_11 + V_17 ;
V_17 = F_20 ( V_8 , & V_8 -> V_40 -> V_41 ) ;
F_14 ( V_8 , L_9 ,
F_21 ( V_39 ) ,
( V_17 & V_42 ) ? L_10 : L_11 ) ;
if ( ! ( V_17 & V_42 ) )
V_8 -> V_40 = NULL ;
}
}
V_9 = F_22 ( V_14 ) ;
if ( V_9 )
return V_9 ;
switch ( V_2 -> V_3 ) {
case V_43 :
V_8 -> V_44 = 0 ;
break;
case V_4 :
V_8 -> V_44 = 0 ;
break;
case V_21 :
switch ( V_2 -> V_5 ) {
case 0x0d9d :
F_14 ( V_8 , L_12 ) ;
V_8 -> V_45 = 0 ;
V_8 -> V_46 &= ~ V_47 ;
break;
}
break;
}
V_17 = F_23 ( V_8 -> V_39 ) * F_24 ( V_8 -> V_39 ) ;
V_17 &= 0x0f ;
if ( V_17 && F_25 ( V_8 -> V_39 ) > V_17 ) {
F_4 ( V_8 , L_13
L_14 ,
F_23 ( V_8 -> V_39 ) ,
F_24 ( V_8 -> V_39 ) ,
F_25 ( V_8 -> V_39 ) ) ;
switch ( V_2 -> V_3 ) {
case 0x17a0 :
V_17 |= ( V_8 -> V_39 & ~ 0xf ) ;
V_8 -> V_39 = V_17 ;
break;
case V_21 :
break;
}
}
if ( V_2 -> V_3 == V_48
&& V_2 -> V_5 == V_49 )
;
else
F_15 ( V_2 , 0x60 , & V_8 -> V_50 ) ;
if ( ! F_26 ( & V_2 -> V_51 ) ) {
T_3 V_52 ;
F_27 ( V_2 , 0x62 , & V_52 ) ;
if ( V_52 & 0x0001 ) {
F_28 ( & V_2 -> V_51 , L_15 ) ;
F_29 ( & V_2 -> V_51 , 1 ) ;
}
}
#ifdef F_30
if ( V_8 -> V_23 && F_26 ( & V_2 -> V_51 ) )
F_10 ( V_8 , L_16 ) ;
#endif
V_9 = F_2 ( V_8 , V_2 ) ;
V_31:
return V_9 ;
}
static int F_31 ( struct V_13 * V_14 , bool V_53 )
{
struct V_7 * V_8 = F_7 ( V_14 ) ;
struct V_1 * V_2 = F_8 ( V_14 -> V_15 . V_16 ) ;
if ( F_32 ( V_14 , V_53 ) != 0 )
( void ) F_2 ( V_8 , V_2 ) ;
return 0 ;
}
static int T_4 F_33 ( void )
{
if ( F_34 () )
return - V_54 ;
F_35 ( L_17 V_55 L_18 , V_56 ) ;
F_36 ( & V_57 , & V_58 ) ;
V_57 . V_59 = V_60 ;
V_57 . V_61 = F_31 ;
return F_37 ( & V_62 ) ;
}
static void T_5 F_38 ( void )
{
F_39 ( & V_62 ) ;
}
