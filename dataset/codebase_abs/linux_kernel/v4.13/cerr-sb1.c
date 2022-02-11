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
F_15 ( V_38 , F_8 ( V_39 ) ) ;
F_2 ( L_26 ) ;
#endif
F_2 ( L_27 ,
( F_16 () >> 25 ) & 0x7 ) ;
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
if ( F_17 ( V_31 ) ) {
if ( ( ( V_35 & V_40 ) != ( V_31 & V_40 ) ) &&
( ( V_35 & V_40 ) != ( ( V_31 & V_40 ) - 4 ) ) )
F_2 ( L_31 ) ;
else {
V_36 = F_18 ( V_31 & V_40 ,
( V_31 & V_41 ) != 0 ) ;
if ( ! ( V_36 & V_31 ) )
F_2 ( L_32 ) ;
}
}
}
if ( V_30 & V_3 ) {
F_2 ( L_33 , V_32 ) ;
F_4 ( V_32 ) ;
if ( F_19 ( V_32 ) ) {
F_2 ( L_34 , V_37 ) ;
if ( ! F_20 ( V_32 ) ) {
V_36 = F_21 ( V_37 & V_40 ,
( V_32 & V_42 ) != 0 ) ;
if ( ! ( V_36 & V_32 ) )
F_2 ( L_35 ) ;
} else {
if ( ( V_37 & V_40 ) != ( V_32 & V_40 ) )
F_2 ( L_36 ) ;
else {
V_36 = F_21 ( V_32 & V_40 ,
( V_32 & V_42 ) != 0 ) ;
if ( ! ( V_36 & V_32 ) )
F_2 ( L_37 ) ;
}
}
}
}
F_5 () ;
#ifdef F_22
while ( 1 )
;
#else
F_23 ( L_38 ) ;
#endif
}
static char F_24 ( T_2 V_43 , int V_44 , int V_45 )
{
char V_46 = 0 ;
int V_47 ;
V_43 >>= V_45 ;
for ( V_47 = V_44 - V_45 ; V_47 >= 0 ; V_47 -- ) {
if ( V_43 & 0x1 )
V_46 = ! V_46 ;
V_43 >>= 1 ;
}
return V_46 ;
}
static unsigned char F_25 ( T_1 V_48 )
{
int V_47 , V_49 ;
char V_46 = 0 ;
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
char V_50 = 0 ;
for ( V_47 = 0 ; V_47 < 8 ; V_47 ++ ) {
if ( V_48 & 0x80000000 )
V_50 = ! V_50 ;
V_48 <<= 1 ;
}
V_46 <<= 1 ;
V_46 |= V_50 ;
}
return V_46 ;
}
static T_1 F_18 ( unsigned short V_51 , int V_52 )
{
unsigned short V_53 ;
int V_54 ;
T_1 V_55 , V_56 , V_57 ;
unsigned long long V_58 , V_59 ;
T_2 V_60 ;
T_4 V_61 ;
int V_36 = 0 ;
F_2 ( L_39 , V_51 ) ;
for ( V_53 = 0 ; V_53 < 4 ; V_53 ++ ) {
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
V_58 = ( ( unsigned long long ) V_57 << 32 ) | V_56 ;
if ( V_53 == 0 ) {
V_61 = ( V_55 >> 14 ) & 0xff ;
F_2 ( L_40 ,
( ( V_51 >> 5 ) & 0x3 ) ,
( ( V_51 >> 7 ) & 0x3f ) ,
( V_61 & 0x3 ) ,
( ( V_61 >> 2 ) & 0x3 ) ,
( ( V_61 >> 4 ) & 0x3 ) ,
( ( V_61 >> 6 ) & 0x3 ) ) ;
}
V_59 = ( V_58 & 0xC0000FFFFFFFE000ULL ) | V_51 ;
if ( ( V_58 & ( 1 << 31 ) ) && ( ( ( V_58 >> 62 ) & 0x3 ) == 3 ) )
V_59 |= 0x3FFFF00000000000ULL ;
V_54 = ( ( V_55 >> 29 ) & 1 ) ;
if ( V_54 ) {
V_60 = V_58 & 0xfff3ff ;
if ( ( ( V_58 >> 10 ) & 1 ) ^ F_24 ( V_60 , 23 , 0 ) ) {
F_2 ( L_41 ) ;
V_36 |= V_6 ;
}
if ( ( ( V_58 >> 11 ) & 1 ) ^ F_24 ( V_58 , 63 , 24 ) ) {
F_2 ( L_42 ) ;
V_36 |= V_6 ;
}
}
if ( V_54 ^ ( ( V_55 >> 27 ) & 1 ) ) {
F_2 ( L_43 ) ;
V_36 |= V_6 ;
}
F_2 ( L_44 ,
V_53 , V_59 , V_54 , V_55 , V_58 ) ;
if ( V_52 ) {
T_1 V_62 , V_63 , V_64 ;
T_4 V_65 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < 4 ; V_66 ++ ) {
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
V_65 = ( V_62 >> 8 ) & 0xff ;
if ( ( ( V_62 >> 16 ) & 1 ) != ( T_1 ) F_24 ( V_65 , 7 , 0 ) ) {
F_2 ( L_45 ) ;
V_36 |= V_7 ;
}
if ( ( ( V_62 >> 4 ) & 0xf ) ^ F_25 ( V_63 ) ) {
F_2 ( L_46 ) ;
V_36 |= V_7 ;
}
if ( ( V_62 & 0xf ) ^ F_25 ( V_64 ) ) {
F_2 ( L_47 ) ;
V_36 |= V_7 ;
}
F_2 ( L_48 , V_62 , V_63 , V_64 ) ;
}
F_2 ( L_5 ) ;
}
}
return V_36 ;
}
static T_4 F_26 ( T_2 V_43 )
{
T_2 V_67 ;
T_1 V_68 ;
T_4 V_69 ;
int V_47 ;
V_69 = 0 ;
for ( V_47 = 7 ; V_47 >= 0 ; V_47 -- )
{
V_69 <<= 1 ;
V_67 = V_43 & V_70 [ V_47 ] ;
V_68 = ( T_1 ) ( V_67 >> 32 ) ;
V_69 ^= ( V_46 [ V_68 >> 24 ] ^ V_46 [ ( V_68 >> 16 ) & 0xFF ]
^ V_46 [ ( V_68 >> 8 ) & 0xFF ] ^ V_46 [ V_68 & 0xFF ] ) ;
V_68 = ( T_1 ) ( V_67 & 0xFFFFFFFF ) ;
V_69 ^= ( V_46 [ V_68 >> 24 ] ^ V_46 [ ( V_68 >> 16 ) & 0xFF ]
^ V_46 [ ( V_68 >> 8 ) & 0xFF ] ^ V_46 [ V_68 & 0xFF ] ) ;
}
return V_69 ;
}
static char * F_27 ( unsigned char V_71 )
{
struct V_72 * V_73 = V_74 ;
while ( V_73 -> V_1 != 0xff ) {
if ( V_73 -> V_1 == V_71 )
break;
V_73 ++ ;
}
return V_73 -> V_75 ;
}
static T_1 F_21 ( unsigned short V_51 , int V_52 )
{
int V_54 , V_53 ;
unsigned char V_71 ;
T_1 V_55 , V_56 , V_57 ;
unsigned long long V_58 , V_76 ;
T_4 V_77 , V_61 ;
int V_36 = 0 ;
F_2 ( L_49 , V_51 ) ;
for ( V_53 = 0 ; V_53 < 4 ; V_53 ++ ) {
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
V_58 = ( ( unsigned long long ) V_57 << 32 ) | V_56 ;
V_76 = ( V_58 & 0xFFFFFFE000ULL ) | V_51 ;
if ( V_53 == 0 ) {
V_61 = ( V_55 >> 14 ) & 0xff ;
F_2 ( L_40 ,
( ( V_51 >> 11 ) & 0x2 ) | ( ( V_51 >> 5 ) & 1 ) ,
( ( V_51 >> 6 ) & 0x3f ) ,
( V_61 & 0x3 ) ,
( ( V_61 >> 2 ) & 0x3 ) ,
( ( V_61 >> 4 ) & 0x3 ) ,
( ( V_61 >> 6 ) & 0x3 ) ) ;
}
V_71 = ( V_55 >> 25 ) & 0x1f ;
V_54 = F_28 ( V_71 ) ;
F_2 ( L_50 ,
V_53 , V_76 , F_27 ( V_71 ) , V_71 , V_55 , V_58 ) ;
if ( V_54 ) {
if ( ( ( V_58 >> 11 ) & 1 ) ^ F_24 ( V_58 , 39 , 26 ) ) {
F_2 ( L_51 ) ;
V_36 |= V_18 ;
}
if ( ( ( V_58 >> 10 ) & 1 ) ^ F_24 ( V_58 , 25 , 13 ) ) {
F_2 ( L_52 ) ;
V_36 |= V_18 ;
}
} else {
V_36 |= V_17 ;
}
if ( V_52 ) {
T_1 V_78 , V_79 , V_62 ;
unsigned long long V_80 ;
int V_66 ;
char V_81 = 0 ;
for ( V_66 = 0 ; V_66 < 4 ; V_66 ++ ) {
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
V_80 = ( ( unsigned long long ) V_78 << 32 ) | V_79 ;
V_77 = F_26 ( V_80 ) ;
if ( V_77 != V_62 ) {
int V_82 ;
V_81 |= 1 << ( 3 - V_66 ) ;
V_77 ^= V_62 ;
V_82 = F_29 ( V_77 ) ;
V_36 |= ( V_82 == 1 ) ? V_19 : V_20 ;
}
F_2 ( L_53 , V_62 , V_80 ) ;
}
F_2 ( L_5 ) ;
if ( V_81 )
F_2 ( L_54 ,
! ! ( V_81 & 8 ) , ! ! ( V_81 & 4 ) ,
! ! ( V_81 & 2 ) , ! ! ( V_81 & 1 ) ) ;
}
}
return V_36 ;
}
