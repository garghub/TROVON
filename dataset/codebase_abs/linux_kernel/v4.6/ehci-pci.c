static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 &&
V_2 -> V_5 == V_6 ;
}
static inline bool F_2 ( struct V_1 * V_2 )
{
return ! ! F_3 ( V_7 , V_2 ) ;
}
static int F_4 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_5 ( V_2 ) ;
if ( ! V_10 )
F_6 ( V_9 , L_1 ) ;
if ( F_1 ( V_2 ) ) {
F_7 ( V_9 , V_11 ,
V_9 -> V_12 -> V_13 ) ;
}
return 0 ;
}
static int F_8 ( struct V_14 * V_15 )
{
struct V_8 * V_9 = F_9 ( V_15 ) ;
struct V_1 * V_2 = F_10 ( V_15 -> V_16 . V_17 ) ;
T_1 V_18 ;
int V_10 ;
V_9 -> V_19 = V_15 -> V_12 ;
switch ( V_2 -> V_3 ) {
case V_20 :
if ( V_2 -> V_5 == 0x01b5 ) {
#ifdef F_11
V_9 -> V_21 = 1 ;
#else
F_12 ( V_9 ,
L_2 ) ;
#endif
}
break;
case V_22 :
switch ( V_2 -> V_5 ) {
case 0x003c :
case 0x005b :
case 0x00d8 :
case 0x00e8 :
if ( F_13 ( V_2 ,
F_14 ( 31 ) ) < 0 )
F_12 ( V_9 , L_3
L_4 ) ;
break;
case 0x0068 :
if ( V_2 -> V_23 < 0xa4 )
V_9 -> V_24 = 1 ;
break;
}
break;
case V_4 :
if ( V_2 -> V_5 == V_25 )
V_15 -> V_26 = 1 ;
break;
case V_27 :
if ( V_2 -> V_5 == V_28 )
V_15 -> V_26 = 1 ;
break;
case V_29 :
if ( F_15 () )
V_9 -> V_30 = 1 ;
if ( V_2 -> V_5 == 0x7463 ) {
F_16 ( V_9 , L_5 ) ;
V_10 = - V_31 ;
goto V_32;
}
if ( V_2 -> V_5 == 0x7808 ) {
V_9 -> V_33 = 1 ;
F_16 ( V_9 , L_6 ) ;
}
break;
case V_34 :
if ( V_2 -> V_5 == 0x3104 && ( V_2 -> V_23 & 0xf0 ) == 0x60 ) {
T_2 V_35 ;
F_17 ( V_2 , 0x4b , & V_35 ) ;
if ( V_35 & 0x20 )
break;
F_18 ( V_2 , 0x4b , V_35 | 0x20 ) ;
}
break;
case V_36 :
if ( F_15 () )
V_9 -> V_30 = 1 ;
if ( V_2 -> V_5 == 0x4396 ) {
V_9 -> V_33 = 1 ;
F_16 ( V_9 , L_6 ) ;
}
if ( ( V_2 -> V_5 == 0x4386 || V_2 -> V_5 == 0x4396 ) &&
F_19 () ) {
T_2 V_35 ;
F_16 ( V_9 , L_7 ) ;
F_17 ( V_2 , 0x53 , & V_35 ) ;
F_18 ( V_2 , 0x53 , V_35 | ( 1 << 3 ) ) ;
}
break;
case V_37 :
F_16 ( V_9 , L_8 ) ;
V_9 -> V_38 = 1 ;
break;
}
V_18 = F_20 ( V_2 , V_39 ) ;
if ( V_18 ) {
F_21 ( V_2 , V_18 , & V_18 ) ;
V_18 >>= 16 ;
if ( ( ( V_18 >> 13 ) & 7 ) == 1 ) {
T_1 V_40 = F_22 ( V_9 ,
& V_9 -> V_19 -> V_40 ) ;
V_18 &= 0x1fff ;
V_9 -> V_41 = V_15 -> V_12 + V_18 ;
V_18 = F_22 ( V_9 , & V_9 -> V_41 -> V_42 ) ;
F_16 ( V_9 , L_9 ,
F_23 ( V_40 ) ,
( V_18 & V_43 ) ? L_10 : L_11 ) ;
if ( ! ( V_18 & V_43 ) )
V_9 -> V_41 = NULL ;
}
}
V_10 = F_24 ( V_15 ) ;
if ( V_10 )
return V_10 ;
switch ( V_2 -> V_3 ) {
case V_44 :
V_9 -> V_45 = 0 ;
break;
case V_4 :
V_9 -> V_45 = 0 ;
break;
case V_22 :
switch ( V_2 -> V_5 ) {
case 0x0d9d :
F_16 ( V_9 , L_12 ) ;
V_9 -> V_46 = 0 ;
V_9 -> V_47 &= ~ V_48 ;
break;
}
break;
}
V_18 = F_25 ( V_9 -> V_40 ) * F_26 ( V_9 -> V_40 ) ;
V_18 &= 0x0f ;
if ( V_18 && F_27 ( V_9 -> V_40 ) > V_18 ) {
F_6 ( V_9 , L_13
L_14 ,
F_25 ( V_9 -> V_40 ) ,
F_26 ( V_9 -> V_40 ) ,
F_27 ( V_9 -> V_40 ) ) ;
switch ( V_2 -> V_3 ) {
case 0x17a0 :
V_18 |= ( V_9 -> V_40 & ~ 0xf ) ;
V_9 -> V_40 = V_18 ;
break;
case V_22 :
break;
}
}
if ( V_2 -> V_3 == V_49
&& V_2 -> V_5 == V_50 )
;
else
F_17 ( V_2 , 0x60 , & V_9 -> V_51 ) ;
if ( ! F_28 ( & V_2 -> V_52 ) ) {
T_3 V_53 ;
F_29 ( V_2 , 0x62 , & V_53 ) ;
if ( V_53 & 0x0001 ) {
F_30 ( & V_2 -> V_52 , L_15 ) ;
F_31 ( & V_2 -> V_52 , 1 ) ;
}
}
#ifdef F_32
if ( V_9 -> V_24 && F_28 ( & V_2 -> V_52 ) )
F_12 ( V_9 , L_16 ) ;
#endif
V_10 = F_4 ( V_9 , V_2 ) ;
V_32:
return V_10 ;
}
static int F_33 ( struct V_14 * V_15 , bool V_54 )
{
struct V_8 * V_9 = F_9 ( V_15 ) ;
struct V_1 * V_2 = F_10 ( V_15 -> V_16 . V_17 ) ;
if ( F_34 ( V_15 , V_54 ) != 0 )
( void ) F_4 ( V_9 , V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , const struct V_55 * V_56 )
{
if ( F_2 ( V_2 ) )
return - V_57 ;
return F_36 ( V_2 , V_56 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
}
static int T_4 F_40 ( void )
{
if ( F_41 () )
return - V_57 ;
F_42 ( L_17 V_58 L_18 , V_59 ) ;
F_43 ( & V_60 , & V_61 ) ;
V_60 . V_62 = V_63 ;
V_60 . V_64 = F_33 ;
return F_44 ( & V_65 ) ;
}
static void T_5 F_45 ( void )
{
F_46 ( & V_65 ) ;
}
