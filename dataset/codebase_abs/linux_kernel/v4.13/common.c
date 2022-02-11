void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
static void F_4 ( T_2 line , T_3 V_2 )
{
if ( V_2 == V_3 )
* V_4 |= ( 1 << line ) ;
else
* V_4 &= ~ ( 1 << line ) ;
}
static void F_5 ( T_2 line , int * V_5 )
{
* V_5 = ( * V_6 >> line ) & 0x1 ;
}
static void F_6 ( T_2 line , int V_5 )
{
if ( V_5 == V_7 )
* V_8 |= ( 1 << line ) ;
else if ( V_5 == V_9 )
* V_8 &= ~ ( 1 << line ) ;
}
static int F_7 ( struct V_10 * V_11 , unsigned V_12 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < 32 ; V_13 ++ ) {
if ( V_14 [ V_13 ] == V_12 )
return V_13 ;
}
return - V_15 ;
}
static int F_8 ( struct V_16 * V_17 , unsigned int type )
{
int line = V_14 [ V_17 -> V_13 ] ;
T_3 V_18 ;
enum V_19 V_20 ;
volatile T_3 * V_21 ;
if ( line < 0 )
return - V_15 ;
switch ( type ) {
case V_22 :
V_18 = V_23 ;
V_20 = V_24 ;
break;
case V_25 :
V_18 = V_26 ;
V_20 = V_24 ;
break;
case V_27 :
V_18 = V_28 ;
V_20 = V_24 ;
break;
case V_29 :
V_18 = V_30 ;
V_20 = V_31 ;
break;
case V_32 :
V_18 = V_33 ;
V_20 = V_31 ;
break;
default:
return - V_15 ;
}
if ( V_20 == V_24 )
V_34 |= ( 1 << V_17 -> V_13 ) ;
else
V_34 &= ~ ( 1 << V_17 -> V_13 ) ;
if ( line >= 8 ) {
line -= 8 ;
V_21 = V_35 ;
} else {
V_21 = V_36 ;
}
* V_21 &= ~ ( V_37 <<
( line * V_38 ) ) ;
* V_39 = ( 1 << line ) ;
* V_21 |= ( V_18 << ( line * V_38 ) ) ;
F_4 ( V_14 [ V_17 -> V_13 ] , V_3 ) ;
return 0 ;
}
static void F_9 ( struct V_16 * V_17 )
{
if ( ( F_10 () || F_11 () ) && V_17 -> V_13 >= 32 )
* V_40 &= ~ ( 1 << ( V_17 -> V_13 - 32 ) ) ;
else
* V_41 &= ~ ( 1 << V_17 -> V_13 ) ;
}
static void F_12 ( struct V_16 * V_17 )
{
int line = ( V_17 -> V_13 < 32 ) ? V_14 [ V_17 -> V_13 ] : - 1 ;
if ( line >= 0 )
* V_39 = ( 1 << line ) ;
}
static void F_13 ( struct V_16 * V_17 )
{
if ( ! ( V_34 & ( 1 << V_17 -> V_13 ) ) )
F_12 ( V_17 ) ;
if ( ( F_10 () || F_11 () ) && V_17 -> V_13 >= 32 )
* V_40 |= ( 1 << ( V_17 -> V_13 - 32 ) ) ;
else
* V_41 |= ( 1 << V_17 -> V_13 ) ;
}
void T_1 F_14 ( void )
{
int V_42 = 0 ;
F_15 ( true ) ;
* V_43 = 0x0 ;
* V_41 = 0x0 ;
if ( F_10 () || F_11 () ) {
* V_44 = 0x00 ;
* V_40 = 0x00 ;
}
for( V_42 = 0 ; V_42 < V_45 ; V_42 ++ ) {
F_16 ( V_42 , & V_46 ,
V_47 ) ;
F_17 ( V_42 , V_48 ) ;
}
}
static T_4 F_18 ( int V_13 , void * V_49 )
{
struct V_50 * V_51 = V_49 ;
* V_52 = V_53 ;
V_51 -> V_54 ( V_51 ) ;
return V_55 ;
}
void T_1 F_19 ( void )
{
* V_56 = 0 ;
* V_52 = V_53 ;
* V_57 = 0 ;
F_20 ( V_58 , & V_59 ) ;
F_21 () ;
F_22 () ;
}
void T_1 F_23 ( struct V_60 * V_61 )
{
memcpy ( & V_62 , V_61 , sizeof *V_61 ) ;
}
static int F_24 ( struct V_10 * V_11 , unsigned V_12 )
{
F_4 ( V_12 , V_3 ) ;
return 0 ;
}
static int F_25 ( struct V_10 * V_11 , unsigned V_12 ,
int V_63 )
{
F_6 ( V_12 , V_63 ) ;
F_4 ( V_12 , V_64 ) ;
return 0 ;
}
static int F_26 ( struct V_10 * V_11 , unsigned V_12 )
{
int V_5 ;
F_5 ( V_12 , & V_5 ) ;
return V_5 ;
}
static void F_27 ( struct V_10 * V_11 , unsigned V_12 ,
int V_5 )
{
F_6 ( V_12 , V_5 ) ;
}
void T_1 F_28 ( void )
{
V_65 = V_66 ;
F_29 ( V_67 , F_3 ( V_67 ) ) ;
F_30 ( & V_68 , NULL ) ;
if ( F_10 () ) {
int V_69 ;
F_29 ( V_70 ,
F_3 ( V_70 ) ) ;
for ( V_69 = 0 ; V_69 < 7 ; V_69 ++ ) {
if( ( * ( F_31 ( 0x4 * V_69 ) ) & 0x200 ) ) {
V_65 = V_71 ;
break;
}
}
}
F_32 ( L_1 ,
V_65 >> 20 ) ;
}
static T_5 T_6 F_33 ( void )
{
return * V_57 ;
}
static T_5 F_34 ( struct V_72 * V_73 )
{
return * V_57 ;
}
static void T_1 F_21 ( void )
{
F_35 ( F_33 , 32 , V_74 ) ;
F_36 ( NULL , L_2 , V_74 , 200 , 32 ,
F_34 ) ;
}
static int F_37 ( unsigned long V_51 ,
struct V_50 * V_75 )
{
unsigned long V_76 = * V_56 & V_77 ;
* V_56 = ( V_51 & ~ V_77 ) | V_76 ;
return 0 ;
}
static int F_38 ( struct V_50 * V_51 )
{
unsigned long V_76 = * V_56 & V_77 ;
unsigned long V_78 = * V_56 & ~ V_77 ;
V_76 &= ~ V_79 ;
* V_56 = V_78 | V_76 ;
return 0 ;
}
static int F_39 ( struct V_50 * V_51 )
{
unsigned long V_76 = V_79 | V_80 ;
unsigned long V_78 = 0 ;
* V_56 = V_78 | V_76 ;
return 0 ;
}
static int F_40 ( struct V_50 * V_51 )
{
unsigned long V_76 = V_79 ;
unsigned long V_78 = V_81 & ~ V_77 ;
* V_56 = V_78 | V_76 ;
return 0 ;
}
static int F_41 ( struct V_50 * V_51 )
{
unsigned long V_76 = * V_56 & V_77 ;
unsigned long V_78 = * V_56 & ~ V_77 ;
V_76 |= V_79 ;
* V_56 = V_78 | V_76 ;
return 0 ;
}
static void T_1 F_22 ( void )
{
V_82 . V_83 = F_42 ( 0 ) ;
F_43 ( & V_82 , V_84 ,
0xf , 0xfffffffe ) ;
}
void F_44 ( enum V_85 V_86 , const char * V_87 )
{
if ( V_86 == V_88 ) {
F_45 ( 0 ) ;
} else {
* V_89 = V_90 ;
* V_91 = 0 ;
* V_92 = V_93 | V_94 ;
}
}
static int F_46 ( struct V_95 * V_96 , T_7 V_97 , T_8 V_98 )
{
return ( V_97 + V_98 ) > V_99 ;
}
static int F_47 ( struct V_95 * V_96 )
{
if ( F_48 ( V_96 ) )
F_49 ( V_96 ) ;
return 0 ;
}
static int F_50 ( struct V_95 * V_96 )
{
V_96 -> V_100 = & V_96 -> V_101 ;
#ifdef F_51
if ( F_48 ( V_96 ) ) {
V_96 -> V_101 = F_52 ( 28 ) ;
F_53 ( V_96 , 2048 , 4096 , F_46 ) ;
return 0 ;
}
#endif
V_96 -> V_101 = F_52 ( 32 ) ;
return 0 ;
}
int F_54 ( struct V_95 * V_96 , T_5 V_102 )
{
if ( F_48 ( V_96 ) )
V_102 &= F_52 ( 28 ) ;
if ( ( V_102 & F_52 ( 28 ) ) == F_52 ( 28 ) ) {
V_96 -> V_101 = V_102 ;
return 0 ;
}
return - V_103 ;
}
static void T_9 * F_55 ( T_10 V_104 , T_8 V_98 ,
unsigned int V_105 , void * V_106 )
{
if ( ! F_56 ( V_104 ) )
return F_57 ( V_104 , V_98 , V_105 , V_106 ) ;
return ( void T_9 * ) V_104 ;
}
static void F_58 ( volatile void T_9 * V_104 )
{
if ( ! F_56 ( ( V_107 T_3 ) V_104 ) )
F_59 ( V_104 ) ;
}
void T_1 F_60 ( void )
{
V_108 = F_50 ;
#ifdef F_51
V_109 = F_47 ;
#endif
#ifdef F_61
V_110 = F_55 ;
V_111 = F_58 ;
#endif
}
