static void T_1 F_1 ( void )
{
int V_1 , V_2 = 1 , V_3 = 0 ;
int V_4 ;
switch ( F_2 () ) {
case V_5 :
case V_6 :
F_3 ( 0x30 ) ;
F_4 ( 0x30000 ) ;
V_3 = ! ! ( F_5 () & ( 1 << 31 ) ) ;
if ( V_3 == 0 )
V_4 = 0x02 ;
else
V_4 = 0x1d ;
F_6 ( 0xf8018000 ,
( V_4 << 27 ) | ( 0x03 << 15 ) ) ;
V_7 = 2 ;
break;
case V_8 :
F_7 ( 0x03 << 22 ) ;
F_8 ( 0x1f << 27 , 0x02 << 27 ) ;
V_7 = ( ( ( F_9 () >> 6 ) & 0x03 ) + 1 ) << 1 ;
for ( V_1 = 0 ; V_1 < V_7 ; V_1 ++ ) {
F_10 ( F_11 ( V_1 , 0 ) ) ;
F_10 ( F_11 ( V_1 , 1 ) ) ;
}
break;
default:
V_7 = 1 ;
}
if ( ! V_9 )
V_7 = 1 ;
if ( ! V_10 )
V_10 = & V_11 ;
V_12 [ V_3 ] = 0 ;
V_13 [ 0 ] = V_3 ;
for ( V_1 = 0 ; V_1 < V_7 ; V_1 ++ ) {
if ( V_1 != V_3 ) {
V_12 [ V_1 ] = V_2 ;
V_13 [ V_2 ] = V_1 ;
V_2 ++ ;
}
F_12 ( V_1 , 1 ) ;
F_13 ( V_1 , 1 ) ;
}
}
static void F_14 ( unsigned int V_7 )
{
T_2 (* F_15)( int V_14 , void * V_15 );
switch ( F_2 () ) {
case V_5 :
case V_6 :
F_15 = V_16 ;
break;
case V_8 :
F_15 = V_17 ;
break;
default:
return;
}
if ( F_16 ( V_18 , F_15 , V_19 ,
L_1 , NULL ) )
F_17 ( L_2 ) ;
if ( F_16 ( V_20 , F_15 , V_19 ,
L_3 , NULL ) )
F_17 ( L_4 ) ;
}
static int F_18 ( int V_2 , struct V_21 * V_22 )
{
V_23 = F_19 ( V_22 ) ;
V_24 = ( unsigned long ) F_20 ( V_22 ) ;
F_21 () ;
F_22 ( L_5 , V_2 ) ;
if ( F_23 ( V_2 , & V_25 ) ) {
F_24 ( V_2 , V_26 ) ;
switch ( F_2 () ) {
case V_5 :
case V_6 :
F_25 ( V_2 , 0 ) ;
break;
case V_8 :
F_26 ( V_2 , 0 ) ;
break;
}
} else {
F_24 ( V_2 , V_27 ) ;
switch ( F_2 () ) {
case V_5 :
case V_6 :
if ( F_27 ( V_2 ) == 1 )
F_28 ( 0x01 ) ;
break;
case V_8 :
F_10 ( F_29 ( V_2 ) ) ;
break;
}
F_30 ( V_2 , & V_25 ) ;
}
return 0 ;
}
static void F_31 ( void )
{
switch ( F_2 () ) {
case V_5 :
case V_6 :
F_32 ( F_33 () ? V_28 : V_29 ) ;
break;
case V_8 :
F_10 ( F_11 ( F_33 () , 0 ) ) ;
F_34 ( & V_30 , ( F_9 () >> 25 ) & 3 ) ;
break;
}
}
static void F_35 ( void )
{
F_22 ( L_6 , F_33 () ) ;
F_36 ( F_37 () + V_31 / V_32 ) ;
F_38 () ;
F_39 ( V_33 | V_34 | V_35 | V_36 | V_37 ) ;
F_38 () ;
}
static void F_26 ( int V_2 , unsigned int V_38 )
{
F_10 ( F_40 ( V_2 , V_38 == V_39 ) ) ;
}
static T_2 V_17 ( int V_14 , void * V_15 )
{
int V_38 = V_14 - V_18 ;
F_10 ( F_11 ( F_33 () , V_38 ) ) ;
if ( V_38 == 0 )
F_41 () ;
else
F_42 () ;
return V_40 ;
}
static void F_43 ( const struct V_41 * V_42 ,
unsigned int V_38 )
{
unsigned int V_1 ;
F_44 (i, mask)
F_26 ( V_1 , V_38 ) ;
}
static void F_25 ( int V_2 , unsigned int V_38 )
{
unsigned long V_43 ;
F_45 ( & V_44 , V_43 ) ;
F_46 ( V_2 ? V_28 : V_29 ) ;
F_47 ( V_45 , V_2 ) |= V_38 ;
F_38 () ;
F_48 ( & V_44 , V_43 ) ;
}
static T_2 V_16 ( int V_14 , void * V_15 )
{
unsigned long V_43 ;
int V_38 , V_2 = V_14 - V_18 ;
F_45 ( & V_44 , V_43 ) ;
V_38 = F_49 ( V_45 ) ;
F_47 ( V_45 , V_2 ) = 0 ;
F_32 ( V_2 ? V_28 : V_29 ) ;
F_48 ( & V_44 , V_43 ) ;
if ( V_38 & V_46 )
F_41 () ;
if ( V_38 & V_39 )
F_42 () ;
return V_40 ;
}
static void F_50 ( const struct V_41 * V_42 ,
unsigned int V_38 )
{
unsigned int V_1 ;
F_44 (i, mask)
F_25 ( V_1 , V_38 ) ;
}
static int F_51 ( void )
{
unsigned int V_2 = F_33 () ;
if ( V_2 == 0 )
return - V_47 ;
F_22 ( L_7 , V_2 ) ;
F_52 ( V_2 , false ) ;
F_53 () ;
F_54 () ;
F_55 ( V_36 ) ;
F_56 () ;
F_57 ( 0 , ~ 0 ) ;
return 0 ;
}
static void F_58 ( unsigned int V_2 )
{
}
void T_3 F_59 ( void )
{
F_60 () ;
F_61 ( 0 , ~ 0 ) ;
F_32 ( V_48 | V_29 | V_28 ) ;
F_62 (
V_36 | V_35 | V_33 | V_34 | V_37 | V_49 ,
V_33 | V_34 | V_37 | V_49 ) ;
F_63 () ;
__asm__ __volatile__(
" wait\n"
" j bmips_secondary_reentry\n"
: : : "memory");
}
static void F_64 ( unsigned long V_50 , char * V_51 , char * V_52 )
{
memcpy ( ( void * ) V_50 , V_51 , V_52 - V_51 ) ;
F_65 ( V_50 , V_52 - V_51 ) ;
F_57 ( V_50 , V_50 + ( V_52 - V_51 ) ) ;
F_66 () ;
}
static inline void F_67 ( void )
{
F_64 ( V_53 , & V_54 ,
& V_55 ) ;
F_64 ( V_56 , & V_57 ,
& V_58 ) ;
}
static void F_68 ( void * V_59 )
{
struct V_60 * V_61 = V_59 ;
int V_62 = V_61 -> V_2 & 0x01 ? 16 : 0 ;
T_4 V_42 = ~ ( 0xffff << V_62 ) , V_63 = V_61 -> V_63 >> 16 ;
F_69 () ;
if ( F_33 () > 0 ) {
F_70 ( 0 , & F_68 ,
V_61 , 1 ) ;
} else {
if ( V_61 -> V_2 & 0x02 ) {
F_71 ( 0xa0 , ( V_63 << 16 ) | V_63 ) ;
F_72 ( 0xa0 ) ;
} else {
F_73 ( ( F_74 () & V_42 ) |
( V_63 << V_62 ) ) ;
}
}
F_75 () ;
}
static void F_24 ( int V_2 , T_4 V_63 )
{
struct V_60 V_61 ;
if ( F_2 () == V_8 ) {
V_61 . V_2 = V_2 ;
V_61 . V_63 = V_63 ;
F_68 ( & V_61 ) ;
} else {
void T_5 * V_64 = F_76 () ;
if ( V_2 == 0 )
F_77 ( V_63 , V_64 + V_65 ) ;
else {
if ( F_2 () != V_6 )
return;
F_77 ( V_63 , V_64 + V_66 ) ;
}
}
F_78 () ;
F_79 () ;
}
void V_11 ( void )
{
unsigned long V_67 = V_68 ;
F_80 ( V_68 != V_69 ) ;
switch ( F_2 () ) {
case V_5 :
F_81 ( V_56 - V_69 ,
& V_57 , 0x80 ) ;
F_78 () ;
return;
case V_70 :
case V_6 :
V_67 = 0x80000400 ;
F_24 ( 0 , V_26 ) ;
break;
case V_8 :
V_67 = 0x80001000 ;
F_24 ( 0 , V_26 ) ;
F_82 ( V_67 ) ;
break;
default:
return;
}
V_71 = & F_67 ;
V_68 = V_67 ;
}
T_6 void __weak F_83 ( void )
{
}
void T_1 F_84 ( void )
{
void T_5 T_7 * V_64 = F_76 () ;
T_4 T_7 V_72 ;
switch ( F_2 () ) {
case V_70 :
F_85 ( F_86 ( 22 ) ) ;
F_78 () ;
F_87 ( F_86 ( 22 ) ) ;
F_88 ( F_86 ( 16 ) ) ;
V_72 = F_89 ( V_64 + V_73 ) ;
F_77 ( V_72 | 0x100 , V_64 + V_73 ) ;
F_89 ( V_64 + V_73 ) ;
V_72 = F_89 ( V_64 + V_73 ) ;
F_77 ( V_72 | 0xf , V_64 + V_73 ) ;
F_89 ( V_64 + V_73 ) ;
V_72 = F_89 ( V_64 + V_74 ) ;
F_77 ( V_72 | 0x0fff0000 , V_64 + V_74 ) ;
F_89 ( V_64 + V_74 ) ;
break;
case V_6 :
switch ( F_90 () ) {
case 0x2a040 :
case 0x2a042 :
case 0x2a044 :
case 0x2a060 :
V_72 = F_89 ( V_64 + V_75 ) ;
F_77 ( V_72 & ~ 0x07000000 , V_64 + V_75 ) ;
F_89 ( V_64 + V_75 ) ;
}
F_91 ( F_86 ( 21 ) ) ;
F_4 ( F_86 ( 23 ) ) ;
F_28 ( F_86 ( 15 ) ) ;
break;
case V_8 :
F_7 ( F_86 ( 17 ) | F_86 ( 21 ) ) ;
__asm__ __volatile__(
" .set noreorder\n"
" li $8, 0x5a455048\n"
" .word 0x4088b00f\n"
" .word 0x4008b008\n"
" li $9, 0x00008000\n"
" or $8, $8, $9\n"
" .word 0x4088b008\n"
" sync\n"
" li $8, 0x0\n"
" .word 0x4088b00f\n"
" .set reorder\n"
: : : "$8", "$9");
F_7 ( F_86 ( 27 ) ) ;
__asm__ __volatile__(
" li $8, 0x5a455048\n"
" .word 0x4088b00f\n"
" nop; nop; nop\n"
" .word 0x4008b008\n"
" lui $9, 0x0100\n"
" or $8, $9\n"
" .word 0x4088b008\n"
: : : "$8", "$9");
break;
}
}
