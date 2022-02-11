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
}
V_2 -> V_17 = V_7 -> V_18 ;
V_2 -> V_18 = V_7 -> V_18 +
F_9 ( V_2 , F_10 ( V_2 , & V_2 -> V_17 -> V_19 ) ) ;
F_11 ( V_2 , L_3 ) ;
F_12 ( V_2 , L_3 ) ;
switch ( V_4 -> V_13 ) {
case V_20 :
switch ( V_4 -> V_15 ) {
case 0x003c :
case 0x005b :
case 0x00d8 :
case 0x00e8 :
if ( F_13 ( V_4 ,
F_14 ( 31 ) ) < 0 )
F_8 ( V_2 , L_4
L_5 ) ;
break;
}
break;
}
V_2 -> V_21 = F_10 ( V_2 , & V_2 -> V_17 -> V_21 ) ;
V_5 = F_15 ( V_2 ) ;
if ( V_5 )
return V_5 ;
if ( ( V_4 -> V_13 == V_22 && V_4 -> V_15 == 0x7808 ) ||
( V_4 -> V_13 == V_23 && V_4 -> V_15 == 0x4396 ) ) {
V_2 -> V_24 = 1 ;
F_16 ( V_2 , L_6
L_7 ) ;
}
V_5 = F_17 ( V_7 ) ;
if ( V_5 )
return V_5 ;
switch ( V_4 -> V_13 ) {
case V_25 :
V_2 -> V_26 = 0 ;
break;
case V_27 :
V_2 -> V_26 = 0 ;
V_2 -> V_28 = 1 ;
if ( V_4 -> V_15 == 0x27cc ) {
V_2 -> V_29 = 1 ;
F_16 ( V_2 , L_8 ) ;
}
if ( V_4 -> V_15 == 0x0806 || V_4 -> V_15 == 0x0811
|| V_4 -> V_15 == 0x0829 ) {
F_16 ( V_2 , L_9 ) ;
V_2 -> V_30 = 0 ;
}
if ( V_4 -> V_15 == V_31 ) {
V_7 -> V_32 = 1 ;
F_18 ( V_2 ) ;
}
if ( V_4 -> V_33 == V_34 ) {
if ( V_4 -> V_15 == 0x1c26 || V_4 -> V_15 == 0x1c2d ) {
F_16 ( V_2 , L_10 ) ;
V_7 -> V_35 = 1 ;
F_19 ( & V_4 -> V_36 , false ) ;
}
}
break;
case V_37 :
if ( V_4 -> V_15 == V_38 ) {
V_7 -> V_32 = 1 ;
F_18 ( V_2 ) ;
}
break;
case V_22 :
if ( F_20 () )
V_2 -> V_39 = 1 ;
if ( V_4 -> V_15 == 0x7463 ) {
F_16 ( V_2 , L_11 ) ;
V_5 = - V_40 ;
goto V_41;
}
break;
case V_20 :
switch ( V_4 -> V_15 ) {
case 0x0068 :
if ( V_4 -> V_42 < 0xa4 )
V_2 -> V_43 = 1 ;
break;
case 0x0d9d :
F_16 ( V_2 , L_12 ) ;
V_2 -> V_30 = 0 ;
V_2 -> V_44 = 0 ;
V_2 -> V_45 &= ~ V_46 ;
break;
}
break;
case V_47 :
if ( V_4 -> V_15 == 0x3104 && ( V_4 -> V_42 & 0xf0 ) == 0x60 ) {
T_1 V_48 ;
F_21 ( V_4 , 0x4b , & V_48 ) ;
if ( V_48 & 0x20 )
break;
F_22 ( V_4 , 0x4b , V_48 | 0x20 ) ;
}
break;
case V_23 :
if ( F_20 () )
V_2 -> V_39 = 1 ;
if ( ( V_4 -> V_15 == 0x4386 ) || ( V_4 -> V_15 == 0x4396 ) ) {
V_10 = F_23 ( V_23 ,
V_49 ,
NULL ) ;
if ( ! V_10 )
break;
V_11 = V_10 -> V_42 ;
if ( ( V_4 -> V_15 == 0x4386 ) || ( V_11 == 0x3a )
|| ( V_11 == 0x3b ) ) {
T_1 V_48 ;
F_16 ( V_2 , L_13
L_14 ) ;
F_21 ( V_4 , 0x53 , & V_48 ) ;
F_22 ( V_4 , 0x53 , V_48 | ( 1 << 3 ) ) ;
}
F_24 ( V_10 ) ;
}
break;
case V_50 :
F_16 ( V_2 , L_15 ) ;
V_2 -> V_51 = 1 ;
break;
}
V_12 = F_25 ( V_4 , 0x0a ) ;
if ( V_12 ) {
F_26 ( V_4 , V_12 , & V_12 ) ;
V_12 >>= 16 ;
if ( ( V_12 & ( 3 << 13 ) ) == ( 1 << 13 ) ) {
V_12 &= 0x1fff ;
V_2 -> V_52 = F_27 ( V_2 ) -> V_18 + V_12 ;
V_12 = F_10 ( V_2 , & V_2 -> V_52 -> V_53 ) ;
F_16 ( V_2 , L_16 ,
F_28 ( V_2 -> V_21 ) ,
( V_12 & V_54 )
? L_17
: L_18 ) ;
if ( ! ( V_12 & V_54 ) )
V_2 -> V_52 = NULL ;
}
}
F_29 ( V_2 ) ;
V_12 = F_30 ( V_2 -> V_21 ) * F_31 ( V_2 -> V_21 ) ;
V_12 &= 0x0f ;
if ( V_12 && F_32 ( V_2 -> V_21 ) > V_12 ) {
F_3 ( V_2 , L_19
L_20 ,
F_30 ( V_2 -> V_21 ) ,
F_31 ( V_2 -> V_21 ) ,
F_32 ( V_2 -> V_21 ) ) ;
switch ( V_4 -> V_13 ) {
case 0x17a0 :
V_12 |= ( V_2 -> V_21 & ~ 0xf ) ;
V_2 -> V_21 = V_12 ;
break;
case V_20 :
break;
}
}
F_21 ( V_4 , 0x60 , & V_2 -> V_55 ) ;
if ( V_4 -> V_13 == V_56
&& V_4 -> V_15 == V_57 )
V_2 -> V_55 = 0x20 ;
if ( ! F_33 ( & V_4 -> V_36 ) ) {
T_3 V_58 ;
F_34 ( V_4 , 0x62 , & V_58 ) ;
if ( V_58 & 0x0001 ) {
F_35 ( & V_4 -> V_36 , L_21 ) ;
F_19 ( & V_4 -> V_36 , 1 ) ;
}
}
#ifdef F_36
if ( V_2 -> V_43 && F_33 ( & V_4 -> V_36 ) )
F_8 ( V_2 , L_22 ) ;
#endif
F_37 ( V_2 , 1 ) ;
V_5 = F_1 ( V_2 , V_4 ) ;
V_41:
return V_5 ;
}
static int F_38 ( struct V_6 * V_7 , bool V_59 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
unsigned long V_60 ;
int V_61 = 0 ;
if ( F_39 ( V_62 , V_2 -> V_63 ) )
F_40 ( 10 ) ;
F_41 ( V_2 , V_59 ) ;
F_42 ( & V_2 -> V_64 , V_60 ) ;
F_43 ( V_2 , 0 , & V_2 -> V_18 -> V_65 ) ;
( void ) F_10 ( V_2 , & V_2 -> V_18 -> V_65 ) ;
F_44 ( V_66 , & V_7 -> V_60 ) ;
F_45 ( & V_2 -> V_64 , V_60 ) ;
return V_61 ;
}
static bool F_46 ( struct V_3 * V_4 )
{
return V_4 -> V_67 == V_68 &&
V_4 -> V_13 == V_27 &&
V_4 -> V_15 == 0x1E26 ;
}
static void F_47 ( void )
{
struct V_3 * V_69 = NULL ;
F_48 (companion) {
if ( ! F_49 ( V_69 ) )
continue;
F_50 ( V_69 ) ;
return;
}
}
static int F_51 ( struct V_6 * V_7 , bool V_70 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_3 * V_4 = F_6 ( V_7 -> V_8 . V_9 ) ;
if ( F_46 ( V_4 ) )
F_47 () ;
if ( F_39 ( V_62 , V_2 -> V_63 ) )
F_40 ( 100 ) ;
F_52 ( V_66 , & V_7 -> V_60 ) ;
if ( F_10 ( V_2 , & V_2 -> V_18 -> V_71 ) == V_72 &&
! V_70 ) {
int V_73 = V_74 ;
F_53 ( V_2 ) ;
if ( ! V_7 -> V_8 . V_75 -> V_76 )
V_73 &= ~ V_77 ;
F_43 ( V_2 , V_73 , & V_2 -> V_18 -> V_65 ) ;
F_10 ( V_2 , & V_2 -> V_18 -> V_65 ) ;
return 0 ;
}
F_54 ( V_7 -> V_8 . V_75 ) ;
( void ) F_15 ( V_2 ) ;
( void ) F_29 ( V_2 ) ;
( void ) F_1 ( V_2 , V_4 ) ;
F_55 ( & V_2 -> V_64 ) ;
if ( V_2 -> V_78 )
F_56 ( V_2 ) ;
F_57 ( V_2 ) ;
F_58 ( & V_2 -> V_64 ) ;
F_43 ( V_2 , V_2 -> V_45 , & V_2 -> V_18 -> V_45 ) ;
F_43 ( V_2 , V_72 , & V_2 -> V_18 -> V_71 ) ;
F_10 ( V_2 , & V_2 -> V_18 -> V_45 ) ;
F_37 ( V_2 , 1 ) ;
V_2 -> V_79 = V_80 ;
return 0 ;
}
static int F_59 ( struct V_6 * V_7 , struct V_81 * V_82 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
int V_61 = 0 ;
if ( ! V_82 -> V_83 )
V_61 = - 1 ;
if ( V_2 -> V_30 && ! V_82 -> V_83 -> V_83 ) {
V_61 = F_60 ( V_2 , V_82 -> V_84 , V_82 -> V_85 ) ;
if ( ! V_61 )
V_61 = F_61 ( V_2 , V_82 -> V_85 ) ;
}
return V_61 ;
}
