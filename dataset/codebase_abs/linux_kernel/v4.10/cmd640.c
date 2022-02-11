static void F_1 ( T_1 V_1 , T_2 V_2 )
{
F_2 ( ( V_1 & 0xfc ) | V_3 , 0xcf8 ) ;
F_3 ( V_2 , ( V_1 & 3 ) | 0xcfc ) ;
}
static T_2 F_4 ( T_1 V_1 )
{
F_2 ( ( V_1 & 0xfc ) | V_3 , 0xcf8 ) ;
return F_5 ( ( V_1 & 3 ) | 0xcfc ) ;
}
static void F_6 ( T_1 V_1 , T_2 V_2 )
{
F_3 ( 0x10 , 0xcf8 ) ;
F_3 ( V_2 , V_3 + V_1 ) ;
F_3 ( 0 , 0xcf8 ) ;
}
static T_2 F_7 ( T_1 V_1 )
{
T_2 V_4 ;
F_3 ( 0x10 , 0xcf8 ) ;
V_4 = F_5 ( V_3 + V_1 ) ;
F_3 ( 0 , 0xcf8 ) ;
return V_4 ;
}
static void F_8 ( T_1 V_1 , T_2 V_2 )
{
F_3 ( V_1 , V_3 ) ;
F_3 ( V_2 , V_3 + 4 ) ;
}
static T_2 F_9 ( T_1 V_1 )
{
F_3 ( V_1 , V_3 ) ;
return F_5 ( V_3 + 4 ) ;
}
static T_2 F_10 ( T_1 V_1 )
{
unsigned long V_5 ;
T_2 V_4 ;
F_11 ( & V_6 , V_5 ) ;
V_4 = F_12 ( V_1 ) ;
F_13 ( & V_6 , V_5 ) ;
return V_4 ;
}
static void F_14 ( T_1 V_1 , T_2 V_2 )
{
unsigned long V_5 ;
F_11 ( & V_6 , V_5 ) ;
F_15 ( V_1 , V_2 ) ;
F_13 ( & V_6 , V_5 ) ;
}
static int T_3 F_16 ( void )
{
const T_2 V_7 [ 4 ] = { 0x95 , 0x10 , 0x40 , 0x06 } ;
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
if ( F_10 ( V_8 ) != V_7 [ V_8 ] )
return 0 ;
}
#ifdef F_17
if ( ( F_10 ( V_9 ) & V_10 ) == 0 ) {
F_18 ( L_1 ) ;
return 0 ;
}
#endif
return 1 ;
}
static int T_3 F_19 ( void )
{
F_12 = F_4 ;
F_15 = F_1 ;
for ( V_3 = 0x80000000 ;
V_3 <= 0x8000f800 ;
V_3 += 0x800 ) {
if ( F_16 () )
return 1 ;
}
return 0 ;
}
static int T_3 F_20 ( void )
{
F_12 = F_7 ;
F_15 = F_6 ;
for ( V_3 = 0xc000 ; V_3 <= 0xcf00 ; V_3 += 0x100 ) {
if ( F_16 () )
return 1 ;
}
return 0 ;
}
static int T_3 F_21 ( void )
{
T_2 V_4 ;
F_12 = F_9 ;
F_15 = F_8 ;
V_3 = 0x178 ;
V_4 = F_10 ( V_11 ) ;
if ( V_4 == 0xff || V_4 == 0x00 || ( V_4 & V_12 ) ) {
V_3 = 0x78 ;
V_4 = F_10 ( V_11 ) ;
if ( V_4 == 0xff || V_4 == 0x00 || ! ( V_4 & V_12 ) )
return 0 ;
}
return 1 ;
}
static int T_3 F_22 ( void )
{
unsigned long V_5 ;
F_11 ( & V_6 , V_5 ) ;
F_3 ( 0x0a , 0x176 ) ;
F_23 ( 100 ) ;
if ( ( F_5 ( 0x176 ) & 0x1f ) != 0x0a ) {
F_3 ( 0x1a , 0x176 ) ;
F_23 ( 100 ) ;
if ( ( F_5 ( 0x176 ) & 0x1f ) != 0x1a ) {
F_13 ( & V_6 , V_5 ) ;
return 0 ;
}
}
F_13 ( & V_6 , V_5 ) ;
return 1 ;
}
static void F_24 ( void )
{
unsigned int V_1 = V_13 ? 0x50 : 0x00 ;
F_18 ( L_2 ) ;
for (; V_1 <= 0x59 ; V_1 ++ ) {
if ( ! ( V_1 & 0x0f ) )
F_18 ( L_3 , V_1 ) ;
F_18 ( L_4 , F_10 ( V_1 ) ) ;
}
F_18 ( L_5 ) ;
}
static void F_25 ( T_4 * V_14 , int V_15 )
{
if ( V_15 ) {
#if V_16
V_14 -> V_17 |= V_18 ;
V_14 -> V_17 &= ~ V_19 ;
#endif
V_14 -> V_17 &= ~ V_20 ;
} else {
V_14 -> V_17 &= ~ V_18 ;
V_14 -> V_17 |= V_20 ;
V_14 -> V_21 = 0 ;
}
}
static void T_3 F_26 ( T_4 * V_14 , unsigned int V_22 )
{
T_2 V_4 = F_10 ( V_23 [ V_22 ] ) ;
F_25 ( V_14 , ( V_4 & V_24 [ V_22 ] ) ? 0 : 1 ) ;
}
static void F_27 ( T_4 * V_14 , unsigned int V_22 , int V_15 )
{
unsigned long V_5 ;
int V_1 = V_23 [ V_22 ] ;
T_2 V_4 ;
F_11 ( & V_6 , V_5 ) ;
V_4 = F_12 ( V_1 ) ;
F_25 ( V_14 , V_15 ) ;
if ( V_15 )
V_4 &= ~ V_24 [ V_22 ] ;
else
V_4 |= V_24 [ V_22 ] ;
F_15 ( V_1 , V_4 ) ;
F_13 ( & V_6 , V_5 ) ;
}
static void F_28 ( unsigned int V_22 )
{
T_2 V_25 , V_26 ;
V_25 = V_27 [ V_22 ] ;
if ( V_25 == 1 )
++ V_25 ;
V_26 = V_28 [ V_22 ] ;
if ( V_25 > 3 && V_26 == 1 )
++ V_26 ;
if ( V_29 > 1 )
V_26 += 1 ;
F_18 ( L_6 , V_30 [ V_22 ] , V_25 , V_26 ) ;
}
static inline T_2 F_29 ( T_2 V_31 , T_2 V_32 )
{
return ( ( V_31 & 0x0f ) << 4 ) | ( V_32 & 0x0f ) ;
}
static void F_30 ( T_4 * V_14 , unsigned int V_22 )
{
unsigned long V_5 ;
T_2 V_33 = V_30 [ V_22 ] ;
T_2 V_25 = V_27 [ V_22 ] ;
T_2 V_26 = V_28 [ V_22 ] ;
if ( V_22 > 1 ) {
T_4 * V_34 = F_31 ( V_14 ) ;
unsigned int V_35 = V_22 ^ 1 ;
if ( V_34 ) {
if ( V_33 < V_30 [ V_35 ] )
V_33 = V_30 [ V_35 ] ;
if ( V_25 < V_27 [ V_35 ] )
V_25 = V_27 [ V_35 ] ;
if ( V_26 < V_28 [ V_35 ] )
V_26 = V_28 [ V_35 ] ;
}
}
switch ( V_33 ) {
case 4 : V_33 = 0x00 ; break;
case 3 : V_33 = 0x80 ; break;
case 1 :
case 2 : V_33 = 0x40 ; break;
default: V_33 = 0xc0 ;
}
F_11 ( & V_6 , V_5 ) ;
V_33 |= F_12 ( V_36 [ V_22 ] ) & 0x3f ;
F_15 ( V_36 [ V_22 ] , V_33 ) ;
F_15 ( V_37 [ V_22 ] , F_29 ( V_25 , V_26 ) ) ;
F_13 ( & V_6 , V_5 ) ;
}
static void F_32 ( T_4 * V_14 , unsigned int V_22 ,
T_2 V_38 , unsigned int V_39 )
{
struct V_40 * V_41 ;
int V_42 , V_43 , V_44 , V_45 ;
T_2 V_33 , V_25 , V_26 , V_46 , V_47 ;
int V_48 ;
if ( V_13 )
V_48 = V_49 ? V_49 : 50 ;
else
V_48 = V_50 ? V_50 : 33 ;
if ( V_38 > 5 )
V_38 = 5 ;
V_41 = F_33 ( V_51 + V_38 ) ;
V_42 = V_41 -> V_52 ;
V_43 = V_41 -> V_53 ;
V_44 = V_39 - ( V_42 + V_43 ) ;
V_45 = 1000 / V_48 ;
V_47 = F_34 ( V_39 , V_45 ) ;
V_33 = F_34 ( V_42 , V_45 ) ;
V_25 = F_34 ( V_43 , V_45 ) ;
if ( V_25 < 2 )
V_25 = 2 ;
V_26 = F_34 ( V_44 , V_45 ) ;
V_46 = V_47 - ( V_33 + V_25 ) ;
if ( V_46 > V_26 )
V_26 = V_46 ;
if ( V_26 < 2 )
V_26 = 2 ;
if ( V_26 > 17 ) {
V_25 += V_26 - 17 ;
V_26 = 17 ;
}
if ( V_25 > 16 )
V_25 = 16 ;
if ( V_29 > 1 )
V_26 -= 1 ;
if ( V_26 > 16 )
V_26 = 16 ;
V_30 [ V_22 ] = V_33 ;
V_27 [ V_22 ] = V_25 ;
V_28 [ V_22 ] = V_26 ;
F_30 ( V_14 , V_22 ) ;
}
static void F_35 ( T_5 * V_54 , T_4 * V_14 )
{
unsigned int V_22 = 0 , V_39 ;
const T_2 V_55 = V_14 -> V_38 - V_51 ;
T_2 V_4 ;
switch ( V_55 ) {
case 6 :
case 7 :
V_4 = F_10 ( V_56 ) & ~ 0x27 ;
if ( V_55 & 1 )
V_4 |= 0x27 ;
F_14 ( V_56 , V_4 ) ;
F_18 ( L_7 ,
V_14 -> V_57 , ( V_55 & 1 ) ? L_8 : L_9 ) ;
return;
case 8 :
case 9 :
F_27 ( V_14 , V_22 , V_55 & 1 ) ;
F_18 ( L_10 ,
V_14 -> V_57 , ( V_55 & 1 ) ? L_8 : L_9 ) ;
return;
}
V_39 = F_36 ( V_14 , V_55 ) ;
F_32 ( V_14 , V_22 , V_55 , V_39 ) ;
F_18 ( L_11 ,
V_14 -> V_57 , V_55 , V_39 ) ;
F_28 ( V_22 ) ;
}
static void T_3 F_37 ( T_4 * V_14 )
{
unsigned int V_8 = V_14 -> V_54 -> V_58 * 2 + ( V_14 -> V_59 & 1 ) ;
#ifdef F_38
V_30 [ V_8 ] = 4 ;
V_27 [ V_8 ] = 16 ;
V_28 [ V_8 ] = 16 ;
F_30 ( V_14 , V_8 ) ;
F_27 ( V_14 , V_8 , 0 ) ;
F_18 (KERN_INFO DRV_NAME L_12 , i) ;
#else
F_26 ( V_14 , V_8 ) ;
F_18 (KERN_INFO DRV_NAME L_13 ,
i, (drive->dev_flags & IDE_DFLAG_NO_IO_32BIT) ? L_14 : L_15 ) ;
#endif
}
static int F_39 ( T_5 * V_54 )
{
int V_60 = V_54 -> V_58 ? V_61 : V_11 ;
T_2 V_62 = V_54 -> V_58 ? V_63 :
V_64 ;
T_2 V_65 = F_10 ( V_60 ) ;
return ( V_65 & V_62 ) ? 1 : 0 ;
}
static int F_40 ( void )
{
unsigned long V_5 ;
T_6 V_66 ;
F_11 ( & V_6 , V_5 ) ;
F_41 ( 0x01 , 0xCFB ) ;
V_66 = F_42 ( 0xCF8 ) ;
F_43 ( 0x80000000 , 0xCF8 ) ;
if ( F_42 ( 0xCF8 ) == 0x80000000 ) {
F_43 ( V_66 , 0xCF8 ) ;
F_13 ( & V_6 , V_5 ) ;
return 1 ;
}
F_43 ( V_66 , 0xCF8 ) ;
F_13 ( & V_6 , V_5 ) ;
return 0 ;
}
static int F_44 ( void )
{
unsigned long V_5 ;
F_11 ( & V_6 , V_5 ) ;
F_41 ( 0x00 , 0xCFB ) ;
F_41 ( 0x00 , 0xCF8 ) ;
F_41 ( 0x00 , 0xCFA ) ;
if ( F_45 ( 0xCF8 ) == 0x00 && F_45 ( 0xCF8 ) == 0x00 ) {
F_13 ( & V_6 , V_5 ) ;
return 1 ;
}
F_13 ( & V_6 , V_5 ) ;
return 0 ;
}
static int T_3 F_46 ( unsigned long V_67 , unsigned long V_68 )
{
if ( ! F_47 ( V_67 , 8 , V_69 ) ) {
F_18 ( V_70 L_16 ,
V_69 , V_67 , V_67 + 7 ) ;
return - V_71 ;
}
if ( ! F_47 ( V_68 , 1 , V_69 ) ) {
F_18 ( V_70 L_17 ,
V_69 , V_68 ) ;
F_48 ( V_67 , 8 ) ;
return - V_71 ;
}
return 0 ;
}
static int T_3 F_49 ( void )
{
int V_72 = 0 , V_73 ;
const char * V_74 , * V_75 ;
T_2 V_4 , V_76 ;
struct V_77 V_78 [ 2 ] , * V_79 [ 2 ] ;
if ( V_13 && F_21 () ) {
V_74 = L_18 ;
} else {
V_13 = 0 ;
if ( F_40 () && F_19 () )
V_74 = L_19 ;
else if ( F_44 () && F_20 () )
V_74 = L_20 ;
else
return 0 ;
}
F_14 ( 0x5b , 0xbd ) ;
if ( F_10 ( 0x5b ) != 0xbd ) {
F_18 ( V_70 L_21 ) ;
return 0 ;
}
F_14 ( 0x5b , 0 ) ;
#ifdef F_50
F_24 () ;
#endif
V_76 = F_10 ( V_11 ) ;
V_29 = V_76 & V_80 ;
if ( V_29 == 0 ) {
F_18 ( L_22 , V_29 ) ;
return 0 ;
}
V_73 = F_46 ( 0x1f0 , 0x3f6 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_46 ( 0x170 , 0x376 ) ;
if ( V_73 ) {
F_48 ( 0x3f6 , 1 ) ;
F_48 ( 0x1f0 , 8 ) ;
return V_73 ;
}
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
F_51 ( & V_78 [ 0 ] , 0x1f0 , 0x3f6 ) ;
V_78 [ 0 ] . V_81 = 14 ;
F_51 ( & V_78 [ 1 ] , 0x170 , 0x376 ) ;
V_78 [ 1 ] . V_81 = 15 ;
F_18 ( V_82 L_23
L_5 , 'a' + V_29 - 1 , V_74 , V_76 ) ;
V_79 [ 0 ] = & V_78 [ 0 ] ;
F_14 ( V_83 , 0 ) ;
F_14 ( V_84 , 0x40 ) ;
V_4 = F_10 ( V_56 ) ;
if ( F_22 () ) {
if ( ( V_4 & V_85 ) ) {
V_72 = 1 ;
V_75 = L_24 ;
} else if ( V_13 ) {
V_72 = 1 ;
V_75 = L_25 ;
} else
V_75 = L_26 ;
} else {
F_14 ( V_56 , V_4 ^ V_85 ) ;
if ( F_22 () ) {
V_72 = 1 ;
V_75 = L_27 ;
} else {
F_14 ( V_56 , V_4 ) ;
V_75 = L_28 ;
}
}
if ( V_72 )
V_79 [ 1 ] = & V_78 [ 1 ] ;
F_18 ( V_82 L_29 ,
V_72 ? L_30 : L_31 , V_75 ) ;
#ifdef F_50
F_24 () ;
#endif
return F_52 ( & V_86 , V_79 , V_72 ? 2 : 1 ,
NULL ) ;
}
