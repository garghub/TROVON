static int
F_1 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
unsigned long * V_5 , unsigned char * V_6 )
{
unsigned long V_7 ;
T_1 V_8 = V_2 -> V_9 ;
F_2 ( ( L_1
L_2 ,
V_8 , V_3 , V_4 , V_5 , V_6 ) ) ;
if ( V_8 == 0 ) {
int V_10 = V_3 >> 3 ;
if ( V_10 > 8 ) {
F_2 ( ( L_3 ,
V_10 ) ) ;
return - 1 ;
}
* V_6 = 0 ;
V_7 = ( 0x0800L << V_10 ) | ( ( V_3 & 7 ) << 8 ) | ( V_4 ) ;
} else {
* V_6 = 1 ;
V_7 = ( V_8 << 16 ) | ( V_3 << 8 ) | ( V_4 ) ;
}
* V_5 = V_7 ;
F_2 ( ( L_4 , V_7 ) ) ;
return 0 ;
}
static unsigned int
F_3 ( unsigned long V_7 , unsigned char V_6 )
{
unsigned int V_11 , V_12 , V_13 ;
unsigned long V_14 = 0 ;
V_12 = F_4 () ;
F_2 ( ( L_5 , V_7 , V_6 ) ) ;
if ( V_6 ) {
V_14 = * ( V_15 ) V_16 & ~ 0xc0000000UL ;
* ( V_15 ) V_16 = 0x40000000UL | V_14 ;
F_5 () ;
}
F_5 () ;
F_6 () ;
F_7 ( V_12 ) = 1 ;
F_8 ( V_12 ) = 0 ;
V_17 |= ( 1 << V_12 ) ;
F_5 () ;
V_11 = * ( V_18 ) V_7 ;
F_5 () ;
F_5 () ;
F_9 ( 100 ) ;
if ( ( V_13 = F_8 ( V_12 ) ) ) {
F_8 ( V_12 ) = 0 ;
V_19 |= ( 1 << V_12 ) ;
V_11 = 0xffffffffU ;
F_5 () ;
}
F_7 ( V_12 ) = 0 ;
V_17 = 0 ;
F_5 () ;
if ( V_6 ) {
* ( V_15 ) V_16 = V_14 ;
F_5 () ;
}
return V_11 ;
}
static void
F_10 ( unsigned long V_7 , unsigned int V_11 , unsigned char V_6 )
{
unsigned int V_12 , V_13 ;
unsigned long V_14 = 0 ;
V_12 = F_4 () ;
if ( V_6 ) {
V_14 = * ( V_15 ) V_16 & ~ 0xc0000000UL ;
* ( V_15 ) V_16 = V_14 | 0x40000000UL ;
F_5 () ;
}
F_5 () ;
F_6 () ;
F_7 ( V_12 ) = 1 ;
F_8 ( V_12 ) = 0 ;
V_17 |= ( 1 << V_12 ) ;
F_5 () ;
* ( V_18 ) V_7 = V_11 ;
F_5 () ;
F_5 () ;
F_9 ( 100 ) ;
if ( ( V_13 = F_8 ( V_12 ) ) ) {
F_8 ( V_12 ) = 0 ;
V_19 |= ( 1 << V_12 ) ;
F_5 () ;
}
F_7 ( V_12 ) = 0 ;
V_17 = 0 ;
F_5 () ;
if ( V_6 ) {
* ( V_15 ) V_16 = V_14 ;
F_5 () ;
}
}
static int
F_11 ( struct V_1 * V_8 , unsigned int V_20 , int V_4 ,
int V_21 , T_2 * V_11 )
{
unsigned long V_7 , V_5 ;
unsigned char V_6 ;
int V_22 ;
long V_23 ;
if ( F_1 ( V_8 , V_20 , V_4 , & V_5 , & V_6 ) )
return V_24 ;
V_23 = ( V_21 - 1 ) * 8 ;
V_22 = ( V_4 & 3 ) * 8 ;
V_7 = ( V_5 << 5 ) + V_23 + V_25 ;
* V_11 = F_3 ( V_7 , V_6 ) >> ( V_22 ) ;
return V_26 ;
}
static int
F_12 ( struct V_1 * V_8 , unsigned int V_20 , int V_4 , int V_21 ,
T_2 V_11 )
{
unsigned long V_7 , V_5 ;
unsigned char V_6 ;
long V_23 ;
if ( F_1 ( V_8 , V_20 , V_4 , & V_5 , & V_6 ) )
return V_24 ;
V_23 = ( V_21 - 1 ) * 8 ;
V_7 = ( V_5 << 5 ) + V_23 + V_25 ;
F_10 ( V_7 , V_11 << ( ( V_4 & 3 ) * 8 ) , V_6 ) ;
return V_26 ;
}
static void T_3
F_13 ( unsigned long V_27 , unsigned long V_28 )
{
unsigned long V_29 ;
V_30 = V_27 ;
V_31 = V_28 ;
V_29 = ( V_27 & 0xfff00000UL ) | ( ( V_27 + V_28 - 1 ) >> 20 ) ;
* ( V_15 ) V_32 = V_29 | 0x80000UL ;
V_29 = ( V_28 - 1 ) & 0xfff00000UL ;
* ( V_15 ) V_33 = V_29 ;
* ( V_15 ) V_34 = 0 ;
#if V_35
F_14 ( L_6 ,
V_36 , * ( V_15 ) V_32 , * ( V_15 ) V_33 , * ( V_15 ) V_34 ) ;
#endif
}
static void T_3
F_15 ( struct V_37 * V_38 ,
unsigned long V_27 ,
unsigned long V_28 )
{
unsigned long V_29 ;
V_38 -> V_39 = F_16 ( V_38 , V_27 , V_28 , 0 ) ;
V_38 -> V_40 = NULL ;
V_29 = ( V_27 & 0xfff00000UL ) | ( ( V_27 + V_28 - 1 ) >> 20 ) ;
* ( V_15 ) V_41 = V_29 | 0xc0000UL ;
V_29 = ( V_28 - 1 ) & 0xfff00000UL ;
* ( V_15 ) V_42 = V_29 ;
* ( V_15 ) V_43 = F_17 ( V_38 -> V_39 -> V_44 ) >> 1 ;
F_5 () ;
F_18 ( V_38 , 0 , - 1 ) ;
#if V_35
F_14 ( L_7 ,
V_36 , * ( V_15 ) V_41 , * ( V_15 ) V_42 , * ( V_15 ) V_43 ) ;
#endif
}
static void T_3
F_19 ( void )
{
#if V_45
F_14 ( L_8 , V_36 , V_46 ) ;
F_14 ( L_9 , V_36 , * ( V_15 ) V_47 ) ;
F_14 ( L_10 , V_36 , * ( V_15 ) V_16 ) ;
F_14 ( L_11 , V_36 , * ( V_15 ) V_48 ) ;
F_14 ( L_12 , V_36 , * ( V_15 ) V_49 ) ;
F_14 ( L_13 , V_36 ,
* ( V_15 ) V_32 , * ( V_15 ) V_33 , * ( V_15 ) V_34 ) ;
F_14 ( L_14 , V_36 ,
* ( V_15 ) V_41 , * ( V_15 ) V_42 , * ( V_15 ) V_43 ) ;
#endif
V_50 . V_51 [ 0 ] . V_52 = * ( V_15 ) V_32 ;
V_50 . V_51 [ 0 ] . V_53 = * ( V_15 ) V_33 ;
V_50 . V_51 [ 0 ] . V_54 = * ( V_15 ) V_34 ;
V_50 . V_51 [ 1 ] . V_52 = * ( V_15 ) V_41 ;
V_50 . V_51 [ 1 ] . V_53 = * ( V_15 ) V_42 ;
V_50 . V_51 [ 1 ] . V_54 = * ( V_15 ) V_43 ;
V_50 . V_55 = V_46 ;
V_50 . V_56 = * ( V_15 ) V_47 ;
V_50 . V_57 = * ( V_15 ) V_16 ;
V_50 . V_58 = * ( V_15 ) V_48 ;
V_50 . V_59 = * ( V_15 ) V_49 ;
}
void T_3
F_20 ( void )
{
struct V_37 * V_38 ;
struct V_60 * V_61 ;
unsigned long V_29 ;
unsigned int V_62 ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ ) {
F_7 ( V_62 ) = 0 ;
F_8 ( V_62 ) = 0 ;
}
V_17 = 0 ;
V_19 = 0 ;
V_29 = * ( V_15 ) V_64 ;
if ( ! ( V_29 & ( 0x1UL << 26 ) ) ) {
F_14 ( L_15 ,
V_29 ) ;
* ( V_15 ) V_64 = V_29 | ( 0x1UL << 26 ) ;
F_5 () ;
* ( V_15 ) V_64 ;
}
F_19 () ;
V_65 = V_38 = F_21 () ;
V_38 -> V_66 = & V_67 ;
V_61 = F_22 () ;
V_61 -> V_68 = 0 ;
V_61 -> V_69 = V_70 ;
V_61 -> V_71 = V_72 ;
if ( F_23 ( & V_73 , V_61 ) < 0 )
F_14 ( V_74 L_16 ) ;
V_38 -> V_75 = V_61 ;
V_38 -> V_76 = 0 ;
V_38 -> V_77 = V_78 - V_79 ;
V_38 -> V_80 = V_81 - V_79 ;
V_38 -> V_82 = V_83 - V_79 ;
V_38 -> V_84 = 0 ;
F_13 ( V_85 , V_86 ) ;
F_15 ( V_38 , V_87 , V_88 ) ;
* ( V_15 ) V_49 = 0x0 ;
* ( V_15 ) V_89 = 0 ; F_5 () ;
* ( V_15 ) V_47 = 0 ; F_5 () ;
* ( V_15 ) V_16 = 0 ; F_5 () ;
* ( V_15 ) V_48 = 0 ; F_5 () ;
}
void
F_24 ( int V_90 )
{
* ( V_15 ) V_32 = V_50 . V_51 [ 0 ] . V_52 ;
* ( V_15 ) V_33 = V_50 . V_51 [ 0 ] . V_53 ;
* ( V_15 ) V_34 = V_50 . V_51 [ 0 ] . V_54 ;
* ( V_15 ) V_41 = V_50 . V_51 [ 1 ] . V_52 ;
* ( V_15 ) V_42 = V_50 . V_51 [ 1 ] . V_53 ;
* ( V_15 ) V_43 = V_50 . V_51 [ 1 ] . V_54 ;
F_5 () ;
* ( V_15 ) V_89 = V_46 ;
* ( V_15 ) V_47 = V_50 . V_56 ;
* ( V_15 ) V_16 = V_50 . V_57 ;
* ( V_15 ) V_48 = V_50 . V_58 ;
* ( V_15 ) V_49 = V_50 . V_59 ;
F_5 () ;
* ( V_15 ) V_49 ;
}
void
F_18 ( struct V_37 * V_38 , T_4 V_68 , T_4 V_69 )
{
unsigned long V_91 ;
V_91 = * ( V_15 ) V_64 ;
* ( V_15 ) V_64 = V_91 | ( 0x1UL << 28 ) ;
F_5 () ;
* ( V_15 ) V_64 ;
* ( V_15 ) V_64 = V_91 & ~ ( 0x1UL << 28 ) ;
F_5 () ;
* ( V_15 ) V_64 ;
}
static void
F_25 ( int V_12 )
{
struct V_92 * V_93 ;
V_93 = (struct V_92 * ) F_26 ( V_12 ) ;
V_93 -> V_94 &= ~ V_95 ;
V_93 -> V_96 |= V_93 -> V_96 ;
V_93 -> V_97 |= V_93 -> V_97 ;
V_93 -> V_98 |= V_93 -> V_98 ;
V_93 -> V_99 |= V_93 -> V_99 ;
* ( V_15 ) V_100 |= * ( V_15 ) V_100 ;
* ( V_15 ) V_101 |= * ( V_15 ) V_101 ;
F_5 () ;
F_5 () ;
}
void
F_27 ( unsigned long V_102 , unsigned long V_103 )
{
int V_12 = F_4 () ;
#ifdef F_28
struct V_104 * V_105 = (struct V_104 * ) V_103 ;
#endif
F_5 () ;
F_5 () ;
F_6 () ;
F_25 ( V_12 ) ;
F_29 ( 0x7 ) ;
F_5 () ;
if ( ! F_7 ( V_12 ) && V_17 ) {
#ifdef F_28
if ( V_106 > 1 ) {
F_14 ( L_17
L_18
L_19 , V_12 , V_17 ,
( unsigned int ) V_105 -> V_107 ) ;
}
#endif
return;
}
if ( ! F_7 ( V_12 ) && ! V_17 ) {
if ( V_19 & ( 1 << V_12 ) ) {
#ifdef F_28
if ( V_106 > 1 ) {
F_14 ( L_20
L_21 ,
V_12 , V_19 ,
( unsigned int ) V_105 -> V_107 ) ;
}
#endif
V_19 = 0 ;
F_5 () ;
return;
} else {
V_19 = 0 ;
F_5 () ;
}
}
#ifdef F_28
if ( V_106 > 1 ) {
F_14 ( L_22
L_23 ,
( F_7 ( V_12 ) ? L_24 : L_25 ) , V_12 ,
V_19 , V_17 ,
( unsigned int ) V_105 -> V_107 ) ;
}
#endif
F_30 ( V_102 , V_103 , L_26 , F_7 ( V_12 ) ) ;
}
