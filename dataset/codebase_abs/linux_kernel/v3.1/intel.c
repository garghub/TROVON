static void T_1 F_1 ( struct V_1 * V_2 )
{
T_2 V_3 ;
if ( V_2 -> V_4 > 6 || ( V_2 -> V_4 == 6 && V_2 -> V_5 >= 0xd ) ) {
F_2 ( V_6 , V_3 ) ;
if ( V_3 & V_7 ) {
V_3 &= ~ V_7 ;
F_3 ( V_6 , V_3 ) ;
V_2 -> V_8 = F_4 ( 0 ) ;
F_5 ( V_2 ) ;
}
}
if ( ( V_2 -> V_4 == 0xf && V_2 -> V_5 >= 0x03 ) ||
( V_2 -> V_4 == 0x6 && V_2 -> V_5 >= 0x0e ) )
F_6 ( V_2 , V_9 ) ;
if ( V_2 -> V_4 == 6 && V_2 -> V_5 == 0x1c && V_2 -> V_10 <= 2 ) {
T_3 V_11 , V_12 ;
F_7 ( V_13 , 0 , 0 ) ;
F_8 () ;
F_9 ( V_13 , V_12 , V_11 ) ;
if ( V_11 < 0x20e ) {
F_10 ( V_14 L_1 ) ;
F_11 ( V_2 , V_15 ) ;
}
}
#ifdef F_12
F_6 ( V_2 , V_16 ) ;
#else
if ( V_2 -> V_4 == 15 && V_2 -> V_17 == 64 )
V_2 -> V_17 = 128 ;
#endif
if ( V_2 -> V_4 == 0xF && V_2 -> V_5 == 0x3
&& ( V_2 -> V_10 == 0x3 || V_2 -> V_10 == 0x4 ) )
V_2 -> V_18 = 36 ;
if ( V_2 -> V_19 & ( 1 << 8 ) ) {
F_6 ( V_2 , V_9 ) ;
F_6 ( V_2 , V_20 ) ;
if ( ! F_13 () )
V_21 = 1 ;
}
if ( V_2 -> V_4 == 6 && V_2 -> V_5 < 15 )
F_11 ( V_2 , V_22 ) ;
#ifdef F_14
if ( V_2 -> V_4 == 15 ) {
F_2 ( V_6 , V_3 ) ;
if ( V_3 & V_23 ) {
F_10 ( V_24 L_2 ) ;
V_3 &= ~ V_23 ;
F_3 ( V_6 , V_3 ) ;
}
}
#endif
if ( V_2 -> V_4 > 6 || ( V_2 -> V_4 == 6 && V_2 -> V_5 >= 0xd ) ) {
F_2 ( V_6 , V_3 ) ;
if ( ! ( V_3 & V_23 ) ) {
F_10 ( V_24 L_3 ) ;
F_15 ( V_25 ) ;
F_15 ( V_26 ) ;
}
}
}
int T_1 F_16 ( void )
{
if ( V_27 . V_28 == V_29 &&
V_27 . V_4 == 6 &&
V_27 . V_5 == 1 &&
V_27 . V_10 < 8 ) {
F_10 ( V_24 L_4 ) ;
return 1 ;
}
return 0 ;
}
static void T_1 F_17 ( void )
{
F_18 ( V_30 , F_19 ( & V_31 ) , V_32 ) ;
V_33 . V_34 = F_20 ( V_30 ) ;
F_21 ( & V_33 ) ;
}
static void T_1 F_22 ( struct V_1 * V_2 )
{
#ifdef F_23
if ( ! V_2 -> V_35 )
return;
if ( V_2 -> V_4 == 5 &&
V_2 -> V_10 >= 1 && V_2 -> V_10 <= 4 &&
V_2 -> V_5 <= 3 ) {
F_24 ( 1 , L_5
L_6 ) ;
}
#endif
}
static void T_1 F_25 ( struct V_1 * V_2 )
{
unsigned long V_36 , V_37 ;
#ifdef F_26
V_2 -> V_38 = 0 ;
if ( ! F_27 () && V_2 -> V_4 == 5 ) {
static int V_39 ;
V_2 -> V_38 = 1 ;
if ( ! V_39 ) {
F_17 () ;
F_10 ( V_40 L_7 ) ;
V_39 = 1 ;
}
}
#endif
if ( ( V_2 -> V_4 << 8 | V_2 -> V_5 << 4 | V_2 -> V_10 ) < 0x633 )
F_11 ( V_2 , V_41 ) ;
if ( ( V_2 -> V_4 == 15 ) && ( V_2 -> V_5 == 1 ) && ( V_2 -> V_10 == 1 ) ) {
F_9 ( V_6 , V_36 , V_37 ) ;
if ( ( V_36 & V_42 ) == 0 ) {
F_10 ( V_24 L_8 ) ;
F_10 ( V_24 L_9 ) ;
V_36 |= V_42 ;
F_7 ( V_6 , V_36 , V_37 ) ;
}
}
if ( V_43 && ( V_2 -> V_4 << 8 | V_2 -> V_5 << 4 ) == 0x520 &&
( V_2 -> V_10 < 0x6 || V_2 -> V_10 == 0xb ) )
F_6 ( V_2 , V_44 ) ;
#ifdef F_28
switch ( V_2 -> V_4 ) {
case 4 :
break;
case 5 :
break;
case 6 :
V_45 . V_46 = 7 ;
break;
case 15 :
V_45 . V_46 = 7 ;
break;
}
#endif
#ifdef F_29
F_30 () ;
#endif
F_22 ( V_2 ) ;
}
static void T_1 F_25 ( struct V_1 * V_2 )
{
}
static void T_1 F_31 ( struct V_1 * V_2 )
{
#ifdef F_32
unsigned V_47 ;
int V_48 = F_33 () ;
V_47 = F_34 ( V_48 ) ;
if ( V_47 == V_49 || ! F_35 ( V_47 ) ) {
V_47 = F_36 ( V_48 ) ;
}
F_37 ( V_48 , V_47 ) ;
#endif
}
static int T_1 F_38 ( struct V_1 * V_2 )
{
unsigned int V_50 , V_51 , V_52 , V_53 ;
if ( V_2 -> V_8 < 4 )
return 1 ;
F_39 ( 4 , 0 , & V_50 , & V_51 , & V_52 , & V_53 ) ;
if ( V_50 & 0x1f )
return ( V_50 >> 26 ) + 1 ;
else
return 1 ;
}
static void T_1 F_40 ( struct V_1 * V_2 )
{
#define F_41 0x00200000
#define F_42 0x00400000
#define F_43 0x80000000
#define F_44 0x00000001
#define F_45 0x00000002
#define F_46 0x00000020
T_3 V_54 , V_55 , V_56 , V_57 ;
F_11 ( V_2 , V_58 ) ;
F_11 ( V_2 , V_59 ) ;
F_11 ( V_2 , V_60 ) ;
F_11 ( V_2 , V_61 ) ;
F_11 ( V_2 , V_62 ) ;
F_9 ( V_63 , V_54 , V_55 ) ;
V_56 = V_55 | V_54 ;
if ( V_56 & F_41 )
F_6 ( V_2 , V_58 ) ;
if ( V_56 & F_42 )
F_6 ( V_2 , V_59 ) ;
if ( V_56 & F_43 ) {
F_9 ( V_64 ,
V_54 , V_55 ) ;
V_57 = V_55 | V_54 ;
if ( ( V_57 & F_44 ) &&
( V_56 & F_41 ) )
F_6 ( V_2 , V_60 ) ;
if ( V_57 & F_45 )
F_6 ( V_2 , V_61 ) ;
if ( V_57 & F_46 )
F_6 ( V_2 , V_62 ) ;
}
}
static void T_1 F_47 ( struct V_1 * V_2 )
{
unsigned int V_65 = 0 ;
F_1 ( V_2 ) ;
F_25 ( V_2 ) ;
F_48 ( V_2 ) ;
V_65 = F_49 ( V_2 ) ;
if ( V_2 -> V_8 > 9 ) {
unsigned V_50 = F_4 ( 10 ) ;
if ( ( V_50 & 0xff ) && ( ( ( V_50 >> 8 ) & 0xff ) > 1 ) )
F_6 ( V_2 , V_66 ) ;
}
if ( V_67 )
F_6 ( V_2 , V_68 ) ;
if ( V_69 ) {
unsigned int V_70 ;
F_9 ( V_6 , V_70 , V_65 ) ;
if ( ! ( V_70 & ( 1 << 11 ) ) )
F_6 ( V_2 , V_71 ) ;
if ( ! ( V_70 & ( 1 << 12 ) ) )
F_6 ( V_2 , V_72 ) ;
}
if ( V_2 -> V_4 == 6 && V_2 -> V_5 == 29 && V_73 )
F_6 ( V_2 , V_74 ) ;
#ifdef F_12
if ( V_2 -> V_4 == 15 )
V_2 -> V_17 = V_2 -> V_75 * 2 ;
if ( V_2 -> V_4 == 6 )
F_6 ( V_2 , V_25 ) ;
#else
if ( V_2 -> V_4 == 6 ) {
char * V_76 = NULL ;
switch ( V_2 -> V_5 ) {
case 5 :
if ( V_65 == 0 )
V_76 = L_10 ;
else if ( V_65 == 256 )
V_76 = L_11 ;
break;
case 6 :
if ( V_65 == 128 )
V_76 = L_12 ;
else if ( V_2 -> V_10 == 0 || V_2 -> V_10 == 5 )
V_76 = L_13 ;
break;
case 8 :
if ( V_65 == 128 )
V_76 = L_14 ;
break;
}
if ( V_76 )
strcpy ( V_2 -> V_77 , V_76 ) ;
}
if ( V_2 -> V_4 == 15 )
F_6 ( V_2 , V_78 ) ;
if ( V_2 -> V_4 == 6 )
F_6 ( V_2 , V_79 ) ;
#endif
if ( ! F_50 ( V_2 , V_80 ) ) {
V_2 -> V_81 = F_38 ( V_2 ) ;
#ifdef F_51
F_52 ( V_2 ) ;
#endif
}
F_31 ( V_2 ) ;
if ( F_50 ( V_2 , V_82 ) )
F_40 ( V_2 ) ;
if ( F_50 ( V_2 , V_83 ) ) {
T_2 V_84 ;
F_2 ( V_85 , V_84 ) ;
if ( ( V_84 & 0xF ) == V_86 ) {
F_53 ( V_14 L_15
L_16
L_17
L_18 ) ;
V_84 = ( V_84 & ~ 0xF ) | V_87 ;
F_3 ( V_85 , V_84 ) ;
}
}
}
static unsigned int T_1 F_54 ( struct V_1 * V_2 , unsigned int V_88 )
{
if ( ( V_2 -> V_4 == 6 ) && ( V_2 -> V_5 == 11 ) && ( V_88 == 0 ) )
V_88 = 256 ;
return V_88 ;
}
