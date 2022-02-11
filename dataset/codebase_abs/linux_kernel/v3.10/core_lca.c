static int
F_1 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
unsigned long * V_5 )
{
unsigned long V_6 ;
T_1 V_7 = V_2 -> V_8 ;
if ( V_7 == 0 ) {
int V_9 = V_3 >> 3 ;
int V_10 = V_3 & 0x7 ;
if ( V_9 > 12 ) {
return - 1 ;
}
* ( V_11 ) V_12 = 0 ;
V_6 = ( 1 << ( 11 + V_9 ) ) | ( V_10 << 8 ) | V_4 ;
} else {
* ( V_11 ) V_12 = 1 ;
V_6 = ( V_7 << 16 ) | ( V_3 << 8 ) | V_4 ;
}
* V_5 = V_6 ;
return 0 ;
}
static unsigned int
F_2 ( unsigned long V_6 )
{
unsigned long V_13 , V_14 , V_15 ;
unsigned int V_16 ;
F_3 ( V_13 ) ;
V_15 = * ( V_11 ) V_17 ;
* ( V_11 ) V_17 = V_15 ;
F_4 () ;
V_16 = * ( V_18 ) V_6 ;
F_5 () ;
V_15 = * ( V_11 ) V_17 ;
if ( V_15 & V_19 ) {
V_14 = ( ( V_15 >> V_20 )
& V_21 ) ;
if ( V_14 != 1 ) {
F_6 ( L_1 , V_15 ) ;
}
* ( V_11 ) V_17 = V_15 ;
F_4 () ;
F_7 ( 0x7 ) ;
V_16 = 0xffffffff ;
}
F_8 ( V_13 ) ;
return V_16 ;
}
static void
F_9 ( unsigned long V_6 , unsigned int V_16 )
{
unsigned long V_13 , V_14 , V_15 ;
F_3 ( V_13 ) ;
V_15 = * ( V_11 ) V_17 ;
* ( V_11 ) V_17 = V_15 ;
F_4 () ;
* ( V_18 ) V_6 = V_16 ;
F_5 () ;
V_15 = * ( V_11 ) V_17 ;
if ( V_15 & V_19 ) {
V_14 = ( ( V_15 >> V_20 )
& V_21 ) ;
if ( V_14 != 1 ) {
F_6 ( L_2 , V_15 ) ;
}
* ( V_11 ) V_17 = V_15 ;
F_4 () ;
F_7 ( 0x7 ) ;
}
F_8 ( V_13 ) ;
}
static int
F_10 ( struct V_1 * V_7 , unsigned int V_22 , int V_4 ,
int V_23 , T_2 * V_16 )
{
unsigned long V_6 , V_5 ;
long V_24 ;
int V_25 ;
if ( F_1 ( V_7 , V_22 , V_4 , & V_5 ) )
return V_26 ;
V_25 = ( V_4 & 3 ) * 8 ;
V_24 = ( V_23 - 1 ) * 8 ;
V_6 = ( V_5 << 5 ) + V_24 + V_27 ;
* V_16 = F_2 ( V_6 ) >> ( V_25 ) ;
return V_28 ;
}
static int
F_11 ( struct V_1 * V_7 , unsigned int V_22 , int V_4 , int V_23 ,
T_2 V_16 )
{
unsigned long V_6 , V_5 ;
long V_24 ;
if ( F_1 ( V_7 , V_22 , V_4 , & V_5 ) )
return V_26 ;
V_24 = ( V_23 - 1 ) * 8 ;
V_6 = ( V_5 << 5 ) + V_24 + V_27 ;
F_9 ( V_6 , V_16 << ( ( V_4 & 3 ) * 8 ) ) ;
return V_28 ;
}
void
F_12 ( struct V_29 * V_30 , T_3 V_31 , T_3 V_32 )
{
F_13 () ;
* ( V_11 ) V_33 = 0 ;
F_4 () ;
}
void T_4
F_14 ( void )
{
struct V_29 * V_30 ;
V_34 = V_30 = F_15 () ;
V_30 -> V_35 = & V_36 ;
V_30 -> V_37 = & V_38 ;
V_30 -> V_39 = 0 ;
V_30 -> V_40 = V_41 - V_42 ;
V_30 -> V_43 = V_44 - V_42 ;
V_30 -> V_45 = V_46 - V_42 ;
V_30 -> V_47 = 0 ;
V_30 -> V_48 = F_16 ( V_30 , 0x00800000 , 0x00800000 , 0 ) ;
V_30 -> V_49 = NULL ;
V_50 = 0x40000000 ;
V_51 = 0x40000000 ;
* ( V_11 ) V_52 = V_30 -> V_48 -> V_53 | ( 3UL << 32 ) ;
* ( V_11 ) V_54 = ( V_30 -> V_48 -> V_23 - 1 ) & 0xfff00000 ;
* ( V_11 ) V_55 = F_17 ( V_30 -> V_48 -> V_56 ) ;
* ( V_11 ) V_57 = V_50 | ( 2UL << 32 ) ;
* ( V_11 ) V_58 = ( V_51 - 1 ) & 0xfff00000 ;
* ( V_11 ) V_59 = 0 ;
* ( V_11 ) V_60 = 0x80 ;
F_12 ( V_30 , 0 , - 1 ) ;
* ( V_11 ) V_61 = 1UL << 5 ;
if ( V_62 )
V_63 = 0x80000000UL ;
}
static void
F_18 ( unsigned long V_64 , unsigned long V_65 )
{
F_6 ( L_3 ,
( ( V_64 & V_66 ) ? L_4 :
( V_64 & V_67 ) ? L_5 : L_6 ) ,
( V_64 & V_68 ) ? L_7 : L_8 ,
( V_64 & V_69 ) ? L_9 : L_10 ,
( unsigned ) ( V_65 & 0x1ffffff8 ) ) ;
if ( V_64 & V_70 ) {
F_6 ( L_11 ) ;
}
if ( V_64 & V_71 ) {
F_6 ( L_12 ) ;
}
if ( V_64 & V_72 ) {
F_6 ( L_13 ) ;
}
if ( V_64 & V_73 ) {
F_6 ( L_14 ) ;
}
}
static void
F_19 ( T_5 V_15 , T_5 V_74 )
{
static const char * const V_75 [] = {
L_15 , L_16 , L_17 , L_18 ,
L_19 , L_20 , L_21 , L_22 , L_23 ,
L_24 , L_25 , L_26 ,
L_27 , L_28 , L_29 ,
L_30
} ;
static const char * const V_76 [] = {
L_31 , L_32 , L_33 ,
L_34 , L_35 , L_36 ,
L_37 , L_38
} ;
unsigned V_14 = ( V_15 & V_77 ) >> V_78 ;
unsigned V_79 = ( V_15 & V_80 ) >> V_81 ;
F_6 ( L_39
L_40 ,
V_14 > 3 ? L_41 : L_42 , V_75 [ V_79 ] , V_74 , V_76 [ V_14 ] ) ;
if ( V_14 == 5 || V_14 == 6 ) {
F_6 ( L_43 ,
( V_15 & ~ V_82 ) ) ;
}
if ( V_15 & V_83 ) {
F_6 ( L_44 ) ;
}
}
void
F_20 ( unsigned long V_84 , unsigned long V_85 )
{
const char * V_86 ;
union V_87 V_88 ;
V_88 . V_89 = (struct V_90 * ) V_85 ;
F_7 ( F_21 () ) ;
F_6 ( V_91 L_45 ,
V_84 , F_22 () -> V_92 , ( unsigned int ) V_88 . V_89 -> V_14 ) ;
switch ( ( unsigned int ) V_88 . V_89 -> V_14 ) {
case V_93 : V_86 = L_46 ; break;
case V_94 : V_86 = L_47 ; break;
case V_95 : V_86 = L_48 ; break;
case V_96 : V_86 = L_49 ; break;
case V_97 : V_86 = L_50 ; break;
case V_98 : V_86 = L_51 ; break;
case V_99 : V_86 = L_52 ; break;
case V_100 : V_86 = L_53 ; break;
case V_101 : V_86 = L_54 ; break;
case V_102 : V_86 = L_55 ; break;
case V_103 : V_86 = L_56 ; break;
case V_104 : V_86 = L_57 ; break;
case V_105 : V_86 = L_58 ; break;
case V_106 :
default: V_86 = L_59 ; break;
}
switch ( V_88 . V_89 -> V_23 ) {
case sizeof( struct V_107 ) :
F_6 ( V_91
L_60 ,
V_86 , V_88 . V_89 -> V_108 ? L_61 : L_62 ,
V_88 . V_109 -> V_110 ) ;
if ( V_88 . V_109 -> V_64 & V_111 ) {
F_18 ( V_88 . V_109 -> V_64 , V_88 . V_109 -> V_65 ) ;
}
if ( V_88 . V_109 -> V_112 & V_113 ) {
F_19 ( V_88 . V_109 -> V_112 , V_88 . V_109 -> V_114 ) ;
}
break;
case sizeof( struct V_115 ) :
F_6 ( V_91 L_63 ,
V_86 , V_88 . V_89 -> V_108 ? L_61 : L_62 ) ;
F_6 ( V_91
L_64 ,
V_88 . V_116 -> V_117 [ 0 ] , V_88 . V_116 -> V_118 , V_88 . V_116 -> V_110 ) ;
F_6 ( V_91 L_65 , V_88 . V_116 -> V_119 ) ;
if ( V_88 . V_116 -> V_64 & V_111 ) {
F_18 ( V_88 . V_116 -> V_64 , V_88 . V_116 -> V_65 ) ;
}
if ( V_88 . V_116 -> V_112 & V_113 ) {
F_19 ( V_88 . V_116 -> V_112 , V_88 . V_116 -> V_114 ) ;
}
break;
default:
F_6 ( V_91 L_66 , V_88 . V_89 -> V_23 ) ;
}
#ifdef F_23
if ( V_120 > 1 ) {
unsigned long * V_121 = ( unsigned long * ) V_85 ;
long V_122 ;
for ( V_122 = 0 ; V_122 < V_88 . V_89 -> V_23 / sizeof( long ) ; V_122 += 2 ) {
F_6 ( V_91 L_67 ,
V_122 * sizeof( long ) , V_121 [ V_122 ] , V_121 [ V_122 + 1 ] ) ;
}
}
#endif
}
void
F_24 ( void )
{
long V_123 ;
V_123 = V_124 ;
F_6 ( L_68 ) ;
F_6 ( L_69 , F_25 ( V_123 ) ) ;
F_6 ( L_70 , F_26 ( V_123 ) ) ;
F_6 ( L_71 ,
( V_123 & V_125 ) ? L_72 : L_73 ) ;
F_6 ( L_74 ,
( V_123 & V_126 ) ? L_72 : L_73 ) ;
}
int
F_27 ( void )
{
long V_123 ;
V_123 = V_124 ;
return ( F_25 ( V_123 ) ) ;
}
void
F_28 ( int V_127 )
{
long V_123 ;
V_123 = V_124 ;
F_29 ( V_123 , V_127 ) ;
F_30 ( V_123 ) ;
F_4 () ;
}
