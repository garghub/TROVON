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
V_2 -> V_23 = 1 ;
if ( V_4 -> V_17 == V_24 )
V_7 -> V_25 = 1 ;
break;
case V_26 :
if ( V_4 -> V_17 == V_27 )
V_7 -> V_25 = 1 ;
break;
case V_28 :
if ( F_11 () )
V_2 -> V_29 = 1 ;
if ( V_4 -> V_17 == 0x7463 ) {
F_12 ( V_2 , L_5 ) ;
V_5 = - V_30 ;
goto V_31;
}
if ( V_4 -> V_17 == 0x7808 ) {
V_2 -> V_32 = 1 ;
F_12 ( V_2 , L_6 ) ;
}
break;
case V_33 :
if ( V_4 -> V_17 == 0x3104 && ( V_4 -> V_20 & 0xf0 ) == 0x60 ) {
T_1 V_34 ;
F_13 ( V_4 , 0x4b , & V_34 ) ;
if ( V_34 & 0x20 )
break;
F_14 ( V_4 , 0x4b , V_34 | 0x20 ) ;
}
break;
case V_35 :
if ( F_11 () )
V_2 -> V_29 = 1 ;
if ( V_4 -> V_17 == 0x4396 ) {
V_2 -> V_32 = 1 ;
F_12 ( V_2 , L_6 ) ;
}
if ( ( V_4 -> V_17 == 0x4386 ) || ( V_4 -> V_17 == 0x4396 ) ) {
V_10 = F_15 ( V_35 ,
V_36 ,
NULL ) ;
if ( ! V_10 )
break;
V_11 = V_10 -> V_20 ;
if ( ( V_4 -> V_17 == 0x4386 ) || ( V_11 == 0x3a )
|| ( V_11 == 0x3b ) ) {
T_1 V_34 ;
F_12 ( V_2 , L_7
L_8 ) ;
F_13 ( V_4 , 0x53 , & V_34 ) ;
F_14 ( V_4 , 0x53 , V_34 | ( 1 << 3 ) ) ;
}
F_16 ( V_10 ) ;
}
break;
case V_37 :
F_12 ( V_2 , L_9 ) ;
V_2 -> V_38 = 1 ;
break;
}
V_5 = F_17 ( V_7 ) ;
if ( V_5 )
return V_5 ;
switch ( V_4 -> V_15 ) {
case V_39 :
V_2 -> V_40 = 0 ;
break;
case V_22 :
V_2 -> V_40 = 0 ;
if ( V_4 -> V_17 == 0x0806 || V_4 -> V_17 == 0x0811
|| V_4 -> V_17 == 0x0829 ) {
F_12 ( V_2 , L_10 ) ;
V_2 -> V_41 = 0 ;
}
break;
case V_19 :
switch ( V_4 -> V_17 ) {
case 0x0d9d :
F_12 ( V_2 , L_11 ) ;
V_2 -> V_41 = 0 ;
V_2 -> V_42 = 0 ;
V_2 -> V_43 &= ~ V_44 ;
break;
}
break;
}
V_12 = F_18 ( V_4 , 0x0a ) ;
if ( V_12 ) {
F_19 ( V_4 , V_12 , & V_12 ) ;
V_12 >>= 16 ;
if ( ( V_12 & ( 3 << 13 ) ) == ( 1 << 13 ) ) {
V_12 &= 0x1fff ;
V_2 -> V_45 = V_7 -> V_14 + V_12 ;
V_12 = F_20 ( V_2 , & V_2 -> V_45 -> V_46 ) ;
F_12 ( V_2 , L_12 ,
F_21 ( V_2 -> V_47 ) ,
( V_12 & V_48 )
? L_13
: L_14 ) ;
if ( ! ( V_12 & V_48 ) )
V_2 -> V_45 = NULL ;
}
}
V_12 = F_22 ( V_2 -> V_47 ) * F_23 ( V_2 -> V_47 ) ;
V_12 &= 0x0f ;
if ( V_12 && F_24 ( V_2 -> V_47 ) > V_12 ) {
F_3 ( V_2 , L_15
L_16 ,
F_22 ( V_2 -> V_47 ) ,
F_23 ( V_2 -> V_47 ) ,
F_24 ( V_2 -> V_47 ) ) ;
switch ( V_4 -> V_15 ) {
case 0x17a0 :
V_12 |= ( V_2 -> V_47 & ~ 0xf ) ;
V_2 -> V_47 = V_12 ;
break;
case V_19 :
break;
}
}
if ( V_4 -> V_15 == V_49
&& V_4 -> V_17 == V_50 )
;
else
F_13 ( V_4 , 0x60 , & V_2 -> V_51 ) ;
if ( ! F_25 ( & V_4 -> V_52 ) ) {
T_3 V_53 ;
F_26 ( V_4 , 0x62 , & V_53 ) ;
if ( V_53 & 0x0001 ) {
F_27 ( & V_4 -> V_52 , L_17 ) ;
F_28 ( & V_4 -> V_52 , 1 ) ;
}
}
#ifdef F_29
if ( V_2 -> V_21 && F_25 ( & V_4 -> V_52 ) )
F_8 ( V_2 , L_18 ) ;
#endif
F_30 ( V_2 , 1 ) ;
V_5 = F_1 ( V_2 , V_4 ) ;
V_31:
return V_5 ;
}
static int F_31 ( struct V_6 * V_7 , bool V_54 )
{
return F_32 ( V_7 , V_54 ) ;
}
static bool F_33 ( struct V_3 * V_4 )
{
return V_4 -> V_55 == V_56 &&
V_4 -> V_15 == V_22 &&
( V_4 -> V_17 == 0x1E26 ||
V_4 -> V_17 == 0x8C2D ||
V_4 -> V_17 == 0x8C26 ) ;
}
static void F_34 ( void )
{
struct V_3 * V_57 = NULL ;
F_35 (companion) {
if ( ! F_36 ( V_57 ) )
continue;
F_37 ( V_57 ) ;
return;
}
}
static int F_38 ( struct V_6 * V_7 , bool V_58 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_3 * V_4 = F_6 ( V_7 -> V_8 . V_9 ) ;
if ( F_33 ( V_4 ) )
F_34 () ;
if ( F_39 ( V_7 , V_58 ) != 0 )
( void ) F_1 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_40 ( struct V_6 * V_7 , struct V_59 * V_60 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
int V_61 = 0 ;
if ( ! V_60 -> V_62 )
V_61 = - 1 ;
if ( V_2 -> V_41 && ! V_60 -> V_62 -> V_62 ) {
V_61 = F_41 ( V_2 , V_60 -> V_63 , V_60 -> V_64 ) ;
if ( ! V_61 )
V_61 = F_42 ( V_2 , V_60 -> V_64 ) ;
}
return V_61 ;
}
