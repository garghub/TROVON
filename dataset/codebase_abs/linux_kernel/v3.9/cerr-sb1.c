static inline void F_1 ( unsigned int V_1 )
{
if ( V_1 & V_2 )
F_2 ( L_1 ) ;
if ( V_1 & V_3 )
F_2 ( L_2 ) ;
if ( V_1 & V_4 )
F_2 ( L_3 ) ;
if ( V_1 & V_5 )
F_2 ( L_4 ) ;
F_2 ( L_5 ) ;
}
static inline void F_3 ( unsigned int V_1 )
{
if ( V_1 & V_6 )
F_2 ( L_6 ) ;
if ( V_1 & V_7 )
F_2 ( L_7 ) ;
if ( V_1 & V_8 )
F_2 ( L_8 ) ;
F_2 ( L_5 ) ;
}
static inline void F_4 ( unsigned int V_1 )
{
switch ( V_1 & V_9 ) {
case V_10 :
F_2 ( L_9 ) ;
break;
case V_11 :
F_2 ( L_10 ) ;
break;
case V_12 :
F_2 ( L_11 ) ;
break;
case V_13 :
F_2 ( L_12 ) ;
break;
case V_14 :
F_2 ( L_13 ) ;
break;
default:
F_2 ( L_14 ) ;
break;
}
if ( ! ( V_1 & V_15 ) )
F_2 ( L_15 ) ;
else {
if ( V_1 & V_16 )
F_2 ( L_16 ) ;
if ( V_1 & V_17 )
F_2 ( L_17 ) ;
if ( V_1 & V_18 )
F_2 ( L_18 ) ;
if ( V_1 & V_19 )
F_2 ( L_19 ) ;
if ( V_1 & V_20 )
F_2 ( L_20 ) ;
if ( V_1 & V_21 )
F_2 ( L_8 ) ;
}
F_2 ( L_5 ) ;
}
static void F_5 ( void )
{
T_1 V_22 , V_23 , V_24 ;
#ifdef F_6
T_2 V_25 ;
#endif
V_22 = F_7 ( F_8 ( V_26 ) ) ;
if ( V_22 & ~ ( 1UL << 31 ) ) {
V_23 = F_7 ( F_8 ( V_27 ) ) ;
#ifdef F_6
V_25 = F_9 ( F_8 ( V_28 ) ) ;
#endif
V_24 = F_7 ( F_8 ( V_29 ) ) ;
F_2 ( L_21 , V_23 , V_24 ) ;
F_2 ( L_22 ) ;
F_2 ( L_23 ,
( unsigned int ) ( F_10 ( V_22 ) & 0x3f ) ,
( int ) ( F_10 ( V_22 ) >> 6 ) ,
( int ) F_11 ( V_22 ) ,
( int ) F_12 ( V_22 ) ) ;
#ifdef F_6
F_2 ( L_24 , V_25 ) ;
#endif
} else {
F_2 ( L_25 ) ;
}
}
T_3 void F_13 ( void )
{
T_1 V_30 , V_31 , V_32 , V_33 , V_34 , V_35 , V_36 ;
unsigned long long V_37 ;
#ifdef F_14
#if F_15 ( V_38 ) || F_15 ( V_39 )
F_16 ( V_40 , F_8 ( V_41 ) ) ;
#else
F_16 ( V_42 , F_8 ( V_41 ) ) ;
#endif
F_2 ( L_26 ) ;
#endif
F_2 ( L_27 ,
( F_17 () >> 25 ) & 0x7 ) ;
__asm__ __volatile__ (
" .set push\n\t"
" .set mips64\n\t"
" .set noat\n\t"
" mfc0 %0, $26\n\t"
" mfc0 %1, $27\n\t"
" mfc0 %2, $27, 1\n\t"
" dmfc0 $1, $27, 3\n\t"
" dsrl32 %3, $1, 0 \n\t"
" sll %4, $1, 0 \n\t"
" mfc0 %5, $30\n\t"
" .set pop"
: "=r" (errctl), "=r" (cerr_i), "=r" (cerr_d),
"=r" (dpahi), "=r" (dpalo), "=r" (eepc));
V_37 = ( ( ( T_2 ) V_34 ) << 32 ) | V_33 ;
F_2 ( L_28 , V_35 ) ;
F_2 ( L_29 , V_30 ) ;
F_1 ( V_30 ) ;
if ( V_30 & V_4 ) {
F_2 ( L_30 , V_31 ) ;
F_3 ( V_31 ) ;
if ( F_18 ( V_31 ) ) {
if ( ( ( V_35 & V_43 ) != ( V_31 & V_43 ) ) &&
( ( V_35 & V_43 ) != ( ( V_31 & V_43 ) - 4 ) ) )
F_2 ( L_31 ) ;
else {
V_36 = F_19 ( V_31 & V_43 ,
( V_31 & V_44 ) != 0 ) ;
if ( ! ( V_36 & V_31 ) )
F_2 ( L_32 ) ;
}
}
}
if ( V_30 & V_3 ) {
F_2 ( L_33 , V_32 ) ;
F_4 ( V_32 ) ;
if ( F_20 ( V_32 ) ) {
F_2 ( L_34 , V_37 ) ;
if ( ! F_21 ( V_32 ) ) {
V_36 = F_22 ( V_37 & V_43 ,
( V_32 & V_45 ) != 0 ) ;
if ( ! ( V_36 & V_32 ) )
F_2 ( L_35 ) ;
} else {
if ( ( V_37 & V_43 ) != ( V_32 & V_43 ) )
F_2 ( L_36 ) ;
else {
V_36 = F_22 ( V_32 & V_43 ,
( V_32 & V_45 ) != 0 ) ;
if ( ! ( V_36 & V_32 ) )
F_2 ( L_37 ) ;
}
}
}
}
F_5 () ;
#ifdef F_23
while ( 1 )
;
#else
F_24 ( L_38 ) ;
#endif
}
static char F_25 ( T_2 V_46 , int V_47 , int V_48 )
{
char V_49 = 0 ;
int V_50 ;
V_46 >>= V_48 ;
for ( V_50 = V_47 - V_48 ; V_50 >= 0 ; V_50 -- ) {
if ( V_46 & 0x1 )
V_49 = ! V_49 ;
V_46 >>= 1 ;
}
return V_49 ;
}
static unsigned char F_26 ( T_1 V_51 )
{
int V_50 , V_52 ;
char V_49 = 0 ;
for ( V_52 = 0 ; V_52 < 4 ; V_52 ++ ) {
char V_53 = 0 ;
for ( V_50 = 0 ; V_50 < 8 ; V_50 ++ ) {
if ( V_51 & 0x80000000 )
V_53 = ! V_53 ;
V_51 <<= 1 ;
}
V_49 <<= 1 ;
V_49 |= V_53 ;
}
return V_49 ;
}
static T_1 F_19 ( unsigned short V_54 , int V_55 )
{
unsigned short V_56 ;
int V_57 ;
T_1 V_58 , V_59 , V_60 ;
unsigned long long V_61 , V_62 ;
T_2 V_63 ;
T_4 V_64 ;
int V_36 = 0 ;
F_2 ( L_39 , V_54 ) ;
for ( V_56 = 0 ; V_56 < 4 ; V_56 ++ ) {
__asm__ __volatile__ (
" .set push \n\t"
" .set noreorder \n\t"
" .set mips64 \n\t"
" .set noat \n\t"
" cache 4, 0(%3) \n\t"
" mfc0 %0, $29 \n\t"
" dmfc0 $1, $28 \n\t"
" dsrl32 %1, $1, 0 \n\t"
" sll %2, $1, 0 \n\t"
" .set pop"
: "=r" (taghi), "=r" (taglohi), "=r" (taglolo)
: "r" ((way << 13) | addr));
V_61 = ( ( unsigned long long ) V_60 << 32 ) | V_59 ;
if ( V_56 == 0 ) {
V_64 = ( V_58 >> 14 ) & 0xff ;
F_2 ( L_40 ,
( ( V_54 >> 5 ) & 0x3 ) ,
( ( V_54 >> 7 ) & 0x3f ) ,
( V_64 & 0x3 ) ,
( ( V_64 >> 2 ) & 0x3 ) ,
( ( V_64 >> 4 ) & 0x3 ) ,
( ( V_64 >> 6 ) & 0x3 ) ) ;
}
V_62 = ( V_61 & 0xC0000FFFFFFFE000ULL ) | V_54 ;
if ( ( V_61 & ( 1 << 31 ) ) && ( ( ( V_61 >> 62 ) & 0x3 ) == 3 ) )
V_62 |= 0x3FFFF00000000000ULL ;
V_57 = ( ( V_58 >> 29 ) & 1 ) ;
if ( V_57 ) {
V_63 = V_61 & 0xfff3ff ;
if ( ( ( V_61 >> 10 ) & 1 ) ^ F_25 ( V_63 , 23 , 0 ) ) {
F_2 ( L_41 ) ;
V_36 |= V_6 ;
}
if ( ( ( V_61 >> 11 ) & 1 ) ^ F_25 ( V_61 , 63 , 24 ) ) {
F_2 ( L_42 ) ;
V_36 |= V_6 ;
}
}
if ( V_57 ^ ( ( V_58 >> 27 ) & 1 ) ) {
F_2 ( L_43 ) ;
V_36 |= V_6 ;
}
F_2 ( L_44 ,
V_56 , V_62 , V_57 , V_58 , V_61 ) ;
if ( V_55 ) {
T_1 V_65 , V_66 , V_67 ;
T_4 V_68 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < 4 ; V_69 ++ ) {
__asm__ __volatile__ (
" .set push\n\t"
" .set noreorder\n\t"
" .set mips64\n\t"
" .set noat\n\t"
" cache 6, 0(%3) \n\t"
" mfc0 %0, $29, 1\n\t"
" dmfc0 $1, $28, 1\n\t"
" dsrl32 %1, $1, 0 \n\t"
" sll %2, $1, 0 \n\t"
" .set pop \n"
: "=r" (datahi), "=r" (insta), "=r" (instb)
: "r" ((way << 13) | addr | (offset << 3)));
V_68 = ( V_65 >> 8 ) & 0xff ;
if ( ( ( V_65 >> 16 ) & 1 ) != ( T_1 ) F_25 ( V_68 , 7 , 0 ) ) {
F_2 ( L_45 ) ;
V_36 |= V_7 ;
}
if ( ( ( V_65 >> 4 ) & 0xf ) ^ F_26 ( V_66 ) ) {
F_2 ( L_46 ) ;
V_36 |= V_7 ;
}
if ( ( V_65 & 0xf ) ^ F_26 ( V_67 ) ) {
F_2 ( L_47 ) ;
V_36 |= V_7 ;
}
F_2 ( L_48 , V_65 , V_66 , V_67 ) ;
}
F_2 ( L_5 ) ;
}
}
return V_36 ;
}
static T_4 F_27 ( T_2 V_46 )
{
T_2 V_70 ;
T_1 V_71 ;
T_4 V_72 ;
int V_50 ;
V_72 = 0 ;
for ( V_50 = 7 ; V_50 >= 0 ; V_50 -- )
{
V_72 <<= 1 ;
V_70 = V_46 & V_73 [ V_50 ] ;
V_71 = ( T_1 ) ( V_70 >> 32 ) ;
V_72 ^= ( V_49 [ V_71 >> 24 ] ^ V_49 [ ( V_71 >> 16 ) & 0xFF ]
^ V_49 [ ( V_71 >> 8 ) & 0xFF ] ^ V_49 [ V_71 & 0xFF ] ) ;
V_71 = ( T_1 ) ( V_70 & 0xFFFFFFFF ) ;
V_72 ^= ( V_49 [ V_71 >> 24 ] ^ V_49 [ ( V_71 >> 16 ) & 0xFF ]
^ V_49 [ ( V_71 >> 8 ) & 0xFF ] ^ V_49 [ V_71 & 0xFF ] ) ;
}
return V_72 ;
}
static char * F_28 ( unsigned char V_74 )
{
struct V_75 * V_76 = V_77 ;
while ( V_76 -> V_1 != 0xff ) {
if ( V_76 -> V_1 == V_74 )
break;
V_76 ++ ;
}
return V_76 -> V_78 ;
}
static T_1 F_22 ( unsigned short V_54 , int V_55 )
{
int V_57 , V_56 ;
unsigned char V_74 ;
T_1 V_58 , V_59 , V_60 ;
unsigned long long V_61 , V_79 ;
T_4 V_80 , V_64 ;
int V_36 = 0 ;
F_2 ( L_49 , V_54 ) ;
for ( V_56 = 0 ; V_56 < 4 ; V_56 ++ ) {
__asm__ __volatile__ (
" .set push\n\t"
" .set noreorder\n\t"
" .set mips64\n\t"
" .set noat\n\t"
" cache 5, 0(%3)\n\t"
" mfc0 %0, $29, 2\n\t"
" dmfc0 $1, $28, 2\n\t"
" dsrl32 %1, $1, 0\n\t"
" sll %2, $1, 0\n\t"
" .set pop"
: "=r" (taghi), "=r" (taglohi), "=r" (taglolo)
: "r" ((way << 13) | addr));
V_61 = ( ( unsigned long long ) V_60 << 32 ) | V_59 ;
V_79 = ( V_61 & 0xFFFFFFE000ULL ) | V_54 ;
if ( V_56 == 0 ) {
V_64 = ( V_58 >> 14 ) & 0xff ;
F_2 ( L_40 ,
( ( V_54 >> 11 ) & 0x2 ) | ( ( V_54 >> 5 ) & 1 ) ,
( ( V_54 >> 6 ) & 0x3f ) ,
( V_64 & 0x3 ) ,
( ( V_64 >> 2 ) & 0x3 ) ,
( ( V_64 >> 4 ) & 0x3 ) ,
( ( V_64 >> 6 ) & 0x3 ) ) ;
}
V_74 = ( V_58 >> 25 ) & 0x1f ;
V_57 = F_29 ( V_74 ) ;
F_2 ( L_50 ,
V_56 , V_79 , F_28 ( V_74 ) , V_74 , V_58 , V_61 ) ;
if ( V_57 ) {
if ( ( ( V_61 >> 11 ) & 1 ) ^ F_25 ( V_61 , 39 , 26 ) ) {
F_2 ( L_51 ) ;
V_36 |= V_18 ;
}
if ( ( ( V_61 >> 10 ) & 1 ) ^ F_25 ( V_61 , 25 , 13 ) ) {
F_2 ( L_52 ) ;
V_36 |= V_18 ;
}
} else {
V_36 |= V_17 ;
}
if ( V_55 ) {
T_1 V_81 , V_82 , V_65 ;
unsigned long long V_83 ;
int V_69 ;
char V_84 = 0 ;
for ( V_69 = 0 ; V_69 < 4 ; V_69 ++ ) {
__asm__ __volatile__ (
" .set push\n\t"
" .set noreorder\n\t"
" .set mips64\n\t"
" .set noat\n\t"
" cache 7, 0(%3)\n\t"
" mfc0 %0, $29, 3\n\t"
" dmfc0 $1, $28, 3\n\t"
" dsrl32 %1, $1, 0 \n\t"
" sll %2, $1, 0 \n\t"
" .set pop"
: "=r" (datahi), "=r" (datalohi), "=r" (datalolo)
: "r" ((way << 13) | addr | (offset << 3)));
V_83 = ( ( unsigned long long ) V_81 << 32 ) | V_82 ;
V_80 = F_27 ( V_83 ) ;
if ( V_80 != V_65 ) {
int V_85 ;
V_84 |= 1 << ( 3 - V_69 ) ;
V_80 ^= V_65 ;
V_85 = F_30 ( V_80 ) ;
V_36 |= ( V_85 == 1 ) ? V_19 : V_20 ;
}
F_2 ( L_53 , V_65 , V_83 ) ;
}
F_2 ( L_5 ) ;
if ( V_84 )
F_2 ( L_54 ,
! ! ( V_84 & 8 ) , ! ! ( V_84 & 4 ) ,
! ! ( V_84 & 2 ) , ! ! ( V_84 & 1 ) ) ;
}
}
return V_36 ;
}
