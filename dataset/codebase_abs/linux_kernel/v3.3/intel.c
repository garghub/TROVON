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
if ( V_2 -> V_4 >= 6 && ! F_7 ( V_2 , V_10 ) ) {
unsigned V_11 ;
F_8 ( V_12 , 0 , 0 ) ;
F_9 () ;
F_10 ( V_12 , V_11 , V_2 -> V_13 ) ;
}
if ( V_2 -> V_4 == 6 && V_2 -> V_5 == 0x1c && V_2 -> V_14 <= 2 &&
V_2 -> V_13 < 0x20e ) {
F_11 ( V_15 L_1 ) ;
F_12 ( V_2 , V_16 ) ;
}
#ifdef F_13
F_6 ( V_2 , V_17 ) ;
#else
if ( V_2 -> V_4 == 15 && V_2 -> V_18 == 64 )
V_2 -> V_18 = 128 ;
#endif
if ( V_2 -> V_4 == 0xF && V_2 -> V_5 == 0x3
&& ( V_2 -> V_14 == 0x3 || V_2 -> V_14 == 0x4 ) )
V_2 -> V_19 = 36 ;
if ( V_2 -> V_20 & ( 1 << 8 ) ) {
F_6 ( V_2 , V_9 ) ;
F_6 ( V_2 , V_21 ) ;
if ( ! F_14 () )
V_22 = 1 ;
}
if ( V_2 -> V_4 == 6 && V_2 -> V_5 < 15 )
F_12 ( V_2 , V_23 ) ;
#ifdef F_15
if ( V_2 -> V_4 == 15 ) {
F_2 ( V_6 , V_3 ) ;
if ( V_3 & V_24 ) {
F_11 ( V_25 L_2 ) ;
V_3 &= ~ V_24 ;
F_3 ( V_6 , V_3 ) ;
}
}
#endif
if ( V_2 -> V_4 > 6 || ( V_2 -> V_4 == 6 && V_2 -> V_5 >= 0xd ) ) {
F_2 ( V_6 , V_3 ) ;
if ( ! ( V_3 & V_24 ) ) {
F_11 ( V_25 L_3 ) ;
F_16 ( V_26 ) ;
F_16 ( V_27 ) ;
}
}
}
int T_1 F_17 ( void )
{
if ( V_28 . V_29 == V_30 &&
V_28 . V_4 == 6 &&
V_28 . V_5 == 1 &&
V_28 . V_14 < 8 ) {
F_11 ( V_25 L_4 ) ;
return 1 ;
}
return 0 ;
}
static void T_1 F_18 ( void )
{
F_19 ( V_31 , F_20 ( & V_32 ) , V_33 ) ;
V_34 . V_35 = F_21 ( V_31 ) ;
F_22 ( & V_34 ) ;
}
static void T_1 F_23 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_36 )
return;
if ( V_2 -> V_4 == 5 &&
V_2 -> V_14 >= 1 && V_2 -> V_14 <= 4 &&
V_2 -> V_5 <= 3 ) {
F_24 ( 1 , L_5
L_6 ) ;
}
}
static void T_1 F_25 ( struct V_1 * V_2 )
{
unsigned long V_37 , V_38 ;
#ifdef F_26
V_2 -> V_39 = 0 ;
if ( ! F_27 () && V_2 -> V_4 == 5 ) {
static int V_40 ;
V_2 -> V_39 = 1 ;
if ( ! V_40 ) {
F_18 () ;
F_11 ( V_41 L_7 ) ;
V_40 = 1 ;
}
}
#endif
if ( ( V_2 -> V_4 << 8 | V_2 -> V_5 << 4 | V_2 -> V_14 ) < 0x633 )
F_12 ( V_2 , V_42 ) ;
if ( ( V_2 -> V_4 == 15 ) && ( V_2 -> V_5 == 1 ) && ( V_2 -> V_14 == 1 ) ) {
F_10 ( V_6 , V_37 , V_38 ) ;
if ( ( V_37 & V_43 ) == 0 ) {
F_11 ( V_25 L_8 ) ;
F_11 ( V_25 L_9 ) ;
V_37 |= V_43 ;
F_8 ( V_6 , V_37 , V_38 ) ;
}
}
if ( V_44 && ( V_2 -> V_4 << 8 | V_2 -> V_5 << 4 ) == 0x520 &&
( V_2 -> V_14 < 0x6 || V_2 -> V_14 == 0xb ) )
F_6 ( V_2 , V_45 ) ;
#ifdef F_28
switch ( V_2 -> V_4 ) {
case 4 :
break;
case 5 :
break;
case 6 :
V_46 . V_47 = 7 ;
break;
case 15 :
V_46 . V_47 = 7 ;
break;
}
#endif
#ifdef F_29
F_30 () ;
#endif
F_23 ( V_2 ) ;
}
static void T_1 F_25 ( struct V_1 * V_2 )
{
}
static void T_1 F_31 ( struct V_1 * V_2 )
{
#ifdef F_32
unsigned V_48 ;
int V_49 = F_33 () ;
V_48 = F_34 ( V_49 ) ;
if ( V_48 == V_50 || ! F_35 ( V_48 ) ) {
V_48 = F_36 ( V_49 ) ;
}
F_37 ( V_49 , V_48 ) ;
#endif
}
static int T_1 F_38 ( struct V_1 * V_2 )
{
unsigned int V_51 , V_52 , V_53 , V_54 ;
if ( V_2 -> V_8 < 4 )
return 1 ;
F_39 ( 4 , 0 , & V_51 , & V_52 , & V_53 , & V_54 ) ;
if ( V_51 & 0x1f )
return ( V_51 >> 26 ) + 1 ;
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
T_3 V_55 , V_56 , V_57 , V_58 ;
F_12 ( V_2 , V_59 ) ;
F_12 ( V_2 , V_60 ) ;
F_12 ( V_2 , V_61 ) ;
F_12 ( V_2 , V_62 ) ;
F_12 ( V_2 , V_63 ) ;
F_10 ( V_64 , V_55 , V_56 ) ;
V_57 = V_56 | V_55 ;
if ( V_57 & F_41 )
F_6 ( V_2 , V_59 ) ;
if ( V_57 & F_42 )
F_6 ( V_2 , V_60 ) ;
if ( V_57 & F_43 ) {
F_10 ( V_65 ,
V_55 , V_56 ) ;
V_58 = V_56 | V_55 ;
if ( ( V_58 & F_44 ) &&
( V_57 & F_41 ) )
F_6 ( V_2 , V_61 ) ;
if ( V_58 & F_45 )
F_6 ( V_2 , V_62 ) ;
if ( V_58 & F_46 )
F_6 ( V_2 , V_63 ) ;
}
}
static void T_1 F_47 ( struct V_1 * V_2 )
{
unsigned int V_66 = 0 ;
F_1 ( V_2 ) ;
F_25 ( V_2 ) ;
F_48 ( V_2 ) ;
V_66 = F_49 ( V_2 ) ;
if ( V_2 -> V_8 > 9 ) {
unsigned V_51 = F_4 ( 10 ) ;
if ( ( V_51 & 0xff ) && ( ( ( V_51 >> 8 ) & 0xff ) > 1 ) )
F_6 ( V_2 , V_67 ) ;
}
if ( V_68 )
F_6 ( V_2 , V_69 ) ;
if ( V_70 ) {
unsigned int V_71 ;
F_10 ( V_6 , V_71 , V_66 ) ;
if ( ! ( V_71 & ( 1 << 11 ) ) )
F_6 ( V_2 , V_72 ) ;
if ( ! ( V_71 & ( 1 << 12 ) ) )
F_6 ( V_2 , V_73 ) ;
}
if ( V_2 -> V_4 == 6 && V_2 -> V_5 == 29 && V_74 )
F_6 ( V_2 , V_75 ) ;
#ifdef F_13
if ( V_2 -> V_4 == 15 )
V_2 -> V_18 = V_2 -> V_76 * 2 ;
if ( V_2 -> V_4 == 6 )
F_6 ( V_2 , V_26 ) ;
#else
if ( V_2 -> V_4 == 6 ) {
char * V_77 = NULL ;
switch ( V_2 -> V_5 ) {
case 5 :
if ( V_66 == 0 )
V_77 = L_10 ;
else if ( V_66 == 256 )
V_77 = L_11 ;
break;
case 6 :
if ( V_66 == 128 )
V_77 = L_12 ;
else if ( V_2 -> V_14 == 0 || V_2 -> V_14 == 5 )
V_77 = L_13 ;
break;
case 8 :
if ( V_66 == 128 )
V_77 = L_14 ;
break;
}
if ( V_77 )
strcpy ( V_2 -> V_78 , V_77 ) ;
}
if ( V_2 -> V_4 == 15 )
F_6 ( V_2 , V_79 ) ;
if ( V_2 -> V_4 == 6 )
F_6 ( V_2 , V_80 ) ;
#endif
if ( ! F_7 ( V_2 , V_81 ) ) {
V_2 -> V_82 = F_38 ( V_2 ) ;
#ifdef F_50
F_51 ( V_2 ) ;
#endif
}
F_31 ( V_2 ) ;
if ( F_7 ( V_2 , V_83 ) )
F_40 ( V_2 ) ;
if ( F_7 ( V_2 , V_84 ) ) {
T_2 V_85 ;
F_2 ( V_86 , V_85 ) ;
if ( ( V_85 & 0xF ) == V_87 ) {
F_52 ( V_15 L_15
L_16
L_17
L_18 ) ;
V_85 = ( V_85 & ~ 0xF ) | V_88 ;
F_3 ( V_86 , V_85 ) ;
}
}
}
static unsigned int T_1 F_53 ( struct V_1 * V_2 , unsigned int V_89 )
{
if ( ( V_2 -> V_4 == 6 ) && ( V_2 -> V_5 == 11 ) && ( V_89 == 0 ) )
V_89 = 256 ;
return V_89 ;
}
