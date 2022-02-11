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
static void F_18 ( int V_2 , struct V_21 * V_22 )
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
V_30 . V_31 = ( F_9 () >> 25 ) & 3 ;
break;
}
}
static void F_34 ( void )
{
F_22 ( L_6 , F_33 () ) ;
F_35 ( F_36 () + V_32 / V_33 ) ;
F_37 () ;
F_38 ( V_34 | V_35 | V_36 | V_37 | V_38 ) ;
F_37 () ;
}
static void F_26 ( int V_2 , unsigned int V_39 )
{
F_10 ( F_39 ( V_2 , V_39 == V_40 ) ) ;
}
static T_2 V_17 ( int V_14 , void * V_15 )
{
int V_39 = V_14 - V_18 ;
F_10 ( F_11 ( F_33 () , V_39 ) ) ;
if ( V_39 == 0 )
F_40 () ;
else
F_41 () ;
return V_41 ;
}
static void F_42 ( const struct V_42 * V_43 ,
unsigned int V_39 )
{
unsigned int V_1 ;
F_43 (i, mask)
F_26 ( V_1 , V_39 ) ;
}
static void F_25 ( int V_2 , unsigned int V_39 )
{
unsigned long V_44 ;
F_44 ( & V_45 , V_44 ) ;
F_45 ( V_2 ? V_28 : V_29 ) ;
F_46 ( V_46 , V_2 ) |= V_39 ;
F_37 () ;
F_47 ( & V_45 , V_44 ) ;
}
static T_2 V_16 ( int V_14 , void * V_15 )
{
unsigned long V_44 ;
int V_39 , V_2 = V_14 - V_18 ;
F_44 ( & V_45 , V_44 ) ;
V_39 = F_48 ( V_46 ) ;
F_46 ( V_46 , V_2 ) = 0 ;
F_32 ( V_2 ? V_28 : V_29 ) ;
F_47 ( & V_45 , V_44 ) ;
if ( V_39 & V_47 )
F_40 () ;
if ( V_39 & V_40 )
F_41 () ;
return V_41 ;
}
static void F_49 ( const struct V_42 * V_43 ,
unsigned int V_39 )
{
unsigned int V_1 ;
F_43 (i, mask)
F_25 ( V_1 , V_39 ) ;
}
static int F_50 ( void )
{
unsigned int V_2 = F_33 () ;
if ( V_2 == 0 )
return - V_48 ;
F_22 ( L_7 , V_2 ) ;
F_51 ( V_2 , false ) ;
F_52 () ;
F_53 () ;
F_54 ( V_37 ) ;
F_55 () ;
F_56 ( 0 , ~ 0 ) ;
return 0 ;
}
static void F_57 ( unsigned int V_2 )
{
}
void T_3 F_58 ( void )
{
F_59 () ;
F_60 ( 0 , ~ 0 ) ;
F_32 ( V_49 | V_29 | V_28 ) ;
F_61 (
V_37 | V_36 | V_34 | V_35 | V_38 | V_50 ,
V_34 | V_35 | V_38 | V_50 ) ;
F_62 () ;
__asm__ __volatile__(
" wait\n"
" j bmips_secondary_reentry\n"
: : : "memory");
}
static void F_63 ( unsigned long V_51 , char * V_52 , char * V_53 )
{
memcpy ( ( void * ) V_51 , V_52 , V_53 - V_52 ) ;
F_64 ( V_51 , V_53 - V_52 ) ;
F_56 ( V_51 , V_51 + ( V_53 - V_52 ) ) ;
F_65 () ;
}
static inline void F_66 ( void )
{
F_63 ( V_54 , & V_55 ,
& V_56 ) ;
F_63 ( V_57 , & V_58 ,
& V_59 ) ;
}
static void F_67 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
int V_63 = V_62 -> V_2 & 0x01 ? 16 : 0 ;
T_4 V_43 = ~ ( 0xffff << V_63 ) , V_64 = V_62 -> V_64 >> 16 ;
F_68 () ;
if ( F_33 () > 0 ) {
F_69 ( 0 , & F_67 ,
V_62 , 1 ) ;
} else {
if ( V_62 -> V_2 & 0x02 ) {
F_70 ( 0xa0 , ( V_64 << 16 ) | V_64 ) ;
F_71 ( 0xa0 ) ;
} else {
F_72 ( ( F_73 () & V_43 ) |
( V_64 << V_63 ) ) ;
}
}
F_74 () ;
}
static void F_24 ( int V_2 , T_4 V_64 )
{
struct V_61 V_62 ;
if ( F_2 () == V_8 ) {
V_62 . V_2 = V_2 ;
V_62 . V_64 = V_64 ;
F_67 ( & V_62 ) ;
} else {
void T_5 * V_65 = F_75 () ;
if ( V_2 == 0 )
F_76 ( V_64 , V_65 + V_66 ) ;
else {
if ( F_2 () != V_6 )
return;
F_76 ( V_64 , V_65 + V_67 ) ;
}
}
F_77 () ;
F_78 () ;
}
void V_11 ( void )
{
unsigned long V_68 = V_69 ;
F_79 ( V_69 != V_70 ) ;
switch ( F_2 () ) {
case V_5 :
F_80 ( V_57 - V_70 ,
& V_58 , 0x80 ) ;
F_77 () ;
return;
case V_71 :
case V_6 :
V_68 = 0x80000400 ;
F_24 ( 0 , V_26 ) ;
break;
case V_8 :
V_68 = 0x80001000 ;
F_24 ( 0 , V_26 ) ;
F_81 ( V_68 ) ;
break;
default:
return;
}
V_72 = & F_66 ;
V_69 = V_68 ;
}
T_6 void __weak F_82 ( void )
{
}
void T_1 F_83 ( void )
{
void T_5 T_7 * V_65 = F_75 () ;
T_4 T_7 V_73 ;
switch ( F_2 () ) {
case V_71 :
F_84 ( F_85 ( 22 ) ) ;
F_77 () ;
F_86 ( F_85 ( 22 ) ) ;
F_87 ( F_85 ( 16 ) ) ;
V_73 = F_88 ( V_65 + V_74 ) ;
F_76 ( V_73 | 0x100 , V_74 ) ;
F_88 ( V_65 + V_74 ) ;
V_73 = F_88 ( V_65 + V_74 ) ;
F_76 ( V_73 | 0xf , V_74 ) ;
F_88 ( V_65 + V_74 ) ;
V_73 = F_88 ( V_65 + V_75 ) ;
F_76 ( V_73 | 0x0fff0000 , V_65 + V_75 ) ;
F_88 ( V_65 + V_75 ) ;
break;
case V_6 :
switch ( F_89 () ) {
case 0x2a040 :
case 0x2a042 :
case 0x2a044 :
case 0x2a060 :
V_73 = F_88 ( V_65 + V_76 ) ;
F_76 ( V_73 & ~ 0x07000000 , V_65 + V_76 ) ;
F_88 ( V_65 + V_76 ) ;
}
F_90 ( F_85 ( 21 ) ) ;
F_4 ( F_85 ( 23 ) ) ;
F_28 ( F_85 ( 15 ) ) ;
break;
case V_8 :
F_7 ( F_85 ( 17 ) | F_85 ( 21 ) ) ;
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
F_7 ( F_85 ( 27 ) ) ;
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
