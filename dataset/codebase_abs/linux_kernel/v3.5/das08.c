static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 , V_9 ;
int V_10 ;
int V_11 ;
int V_12 , V_13 ;
V_10 = F_2 ( V_6 -> V_14 ) ;
V_11 = F_3 ( V_6 -> V_14 ) ;
F_4 ( V_2 -> V_15 + V_16 ) ;
F_4 ( V_2 -> V_15 + V_17 ) ;
F_5 ( & V_2 -> V_18 ) ;
V_19 -> V_20 &= ~ V_21 ;
V_19 -> V_20 |= F_6 ( V_10 ) ;
F_7 ( V_19 -> V_20 , V_2 -> V_15 + V_22 ) ;
F_8 ( & V_2 -> V_18 ) ;
if ( V_4 -> V_23 -> V_24 > 1 ) {
V_11 = F_3 ( V_6 -> V_14 ) ;
F_7 ( V_19 -> V_25 [ V_11 ] ,
V_2 -> V_15 + V_26 ) ;
}
for ( V_9 = 0 ; V_9 < V_6 -> V_9 ; V_9 ++ ) {
if ( V_27 -> V_28 == 16 )
if ( F_4 ( V_2 -> V_15 + V_17 ) & 0x80 )
F_9 ( V_29 L_1 ) ;
F_10 ( 0 , V_2 -> V_15 + V_30 ) ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ ) {
if ( ! ( F_4 ( V_2 -> V_15 + V_32 ) & V_33 ) )
break;
}
if ( V_8 == V_31 ) {
F_9 ( V_34 L_2 ) ;
return - V_35 ;
}
V_13 = F_4 ( V_2 -> V_15 + V_17 ) ;
V_12 = F_4 ( V_2 -> V_15 + V_16 ) ;
if ( V_27 -> V_36 == V_37 ) {
V_7 [ V_9 ] = ( V_12 >> 4 ) | ( V_13 << 4 ) ;
} else if ( V_27 -> V_36 == V_38 ) {
V_7 [ V_9 ] = ( V_13 << 8 ) + V_12 ;
} else if ( V_27 -> V_36 == V_39 ) {
if ( V_13 & 0x80 )
V_7 [ V_9 ] = ( 1 << 15 ) | V_12 | ( ( V_13 & 0x7f ) << 8 ) ;
else
V_7 [ V_9 ] = ( 1 << 15 ) - ( V_12 | ( V_13 & 0x7f ) << 8 ) ;
} else {
F_11 ( V_2 , L_3 ) ;
return - 1 ;
}
}
return V_9 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 0 ] = 0 ;
V_7 [ 1 ] = F_13 ( F_4 ( V_2 -> V_15 + V_32 ) ) ;
return 2 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_40 ;
V_40 = ( V_19 -> V_20 >> 4 ) & 0xf ;
V_40 &= ~ V_7 [ 0 ] ;
V_40 |= V_7 [ 0 ] & V_7 [ 1 ] ;
F_5 ( & V_2 -> V_18 ) ;
V_19 -> V_20 &= ~ V_41 ;
V_19 -> V_20 |= F_15 ( V_40 ) ;
F_7 ( V_19 -> V_20 , V_2 -> V_15 + V_22 ) ;
F_8 ( & V_2 -> V_18 ) ;
V_7 [ 1 ] = V_40 ;
return 2 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 0 ] = 0 ;
V_7 [ 1 ] = F_4 ( V_2 -> V_15 + V_42 ) ;
return 2 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_19 -> V_43 &= ~ V_7 [ 0 ] ;
V_19 -> V_43 |= V_7 [ 0 ] & V_7 [ 1 ] ;
F_7 ( V_19 -> V_43 , V_2 -> V_15 + V_42 ) ;
V_7 [ 1 ] = V_19 -> V_43 ;
return 2 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_9 ;
int V_12 , V_13 ;
int V_10 ;
V_12 = V_7 [ 0 ] & 0xff ;
V_13 = ( V_7 [ 0 ] >> 8 ) & 0xf ;
V_10 = F_2 ( V_6 -> V_14 ) ;
for ( V_9 = 0 ; V_9 < V_6 -> V_9 ; V_9 ++ ) {
#if 0
outb(lsb, dev->iobase + devpriv->ao_offset_lsb[chan]);
outb(msb, dev->iobase + devpriv->ao_offset_msb[chan]);
#else
F_7 ( V_12 , V_2 -> V_15 + F_19 ( V_10 ) ) ;
F_7 ( V_13 , V_2 -> V_15 + F_20 ( V_10 ) ) ;
#endif
F_4 ( V_2 -> V_15 + V_42 ) ;
}
return V_9 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_9 ;
int V_12 , V_13 ;
int V_10 ;
V_12 = V_7 [ 0 ] & 0xff ;
V_13 = ( V_7 [ 0 ] >> 8 ) & 0xf ;
V_10 = F_2 ( V_6 -> V_14 ) ;
for ( V_9 = 0 ; V_9 < V_6 -> V_9 ; V_9 ++ ) {
#if 0
outb(lsb, dev->iobase + devpriv->ao_offset_lsb[chan]);
outb(msb, dev->iobase + devpriv->ao_offset_msb[chan]);
#else
F_7 ( V_12 , V_2 -> V_15 + F_22 ( V_10 ) ) ;
F_7 ( V_13 , V_2 -> V_15 + F_23 ( V_10 ) ) ;
#endif
F_4 ( V_2 -> V_15 + V_44 ) ;
}
return V_9 ;
}
static unsigned int F_24 ( unsigned int V_45 , int V_10 )
{
unsigned int V_13 , V_12 ;
F_7 ( V_10 << 6 , V_45 + V_46 ) ;
V_45 += V_10 ;
V_12 = F_4 ( V_45 ) ;
V_13 = F_4 ( V_45 ) ;
return V_12 | ( V_13 << 8 ) ;
}
static void F_25 ( unsigned int V_45 , int V_10 ,
unsigned int V_47 )
{
unsigned int V_13 , V_12 ;
V_12 = V_47 & 0xFF ;
V_13 = V_47 >> 8 ;
V_45 += V_10 ;
F_7 ( V_12 , V_45 ) ;
F_7 ( V_13 , V_45 ) ;
}
static unsigned int F_26 ( struct V_48 * V_49 , int V_50 )
{
int V_10 = V_49 -> V_51 [ V_50 ] ;
return F_24 ( V_49 -> V_15 , V_10 ) ;
}
static void F_27 ( struct V_48 * V_49 , int V_50 ,
unsigned int V_47 )
{
int V_10 = V_49 -> V_51 [ V_50 ] ;
F_25 ( V_49 -> V_15 , V_10 , V_47 ) ;
}
static void F_28 ( struct V_48 * V_49 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < 3 ; ++ V_8 )
F_29 ( V_49 -> V_15 , V_8 , V_49 -> V_52 [ V_8 ] ) ;
}
static void F_29 ( unsigned int V_45 , int V_50 ,
unsigned int V_52 )
{
F_7 ( ( V_50 << 6 ) | 0x30 | ( V_52 & 0x0F ) , V_45 + V_46 ) ;
}
static void F_30 ( struct V_48 * V_49 , int V_50 ,
unsigned int V_52 )
{
int V_10 = V_49 -> V_51 [ V_50 ] ;
V_49 -> V_52 [ V_10 ] = V_52 ;
return F_29 ( V_49 -> V_15 , V_10 , V_52 ) ;
}
static unsigned int F_31 ( unsigned int V_45 , int V_50 )
{
F_7 ( 0xE0 | ( 2 << V_50 ) , V_45 + V_46 ) ;
return F_4 ( V_45 + V_50 ) ;
}
static unsigned int F_32 ( struct V_48 * V_49 , int V_50 )
{
int V_10 = V_49 -> V_51 [ V_50 ] ;
return F_31 ( V_49 -> V_15 , V_10 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_10 = V_6 -> V_14 ;
V_7 [ 0 ] = F_26 ( & V_19 -> V_53 , V_10 ) ;
return 1 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_10 = V_6 -> V_14 ;
F_27 ( & V_19 -> V_53 , V_10 , V_7 [ 0 ] ) ;
return 1 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_10 = V_6 -> V_14 ;
if ( V_6 -> V_9 != 2 )
return - V_54 ;
switch ( V_7 [ 0 ] ) {
case V_55 :
F_30 ( & V_19 -> V_53 , V_10 , V_7 [ 1 ] ) ;
break;
case V_56 :
V_7 [ 1 ] = F_32 ( & V_19 -> V_53 , V_10 ) ;
break;
default:
return - V_54 ;
break;
}
return 2 ;
}
int F_36 ( struct V_1 * V_2 , unsigned long V_15 )
{
struct V_3 * V_4 ;
int V_57 ;
if ( ( V_27 -> V_58 != V_59 ) && ( V_27 -> V_58 != V_60 ) ) {
F_9 ( V_29 L_4 , V_15 ) ;
if ( ! F_37 ( V_15 , V_27 -> V_61 , V_62 ) ) {
F_9 ( V_34 L_5 ) ;
return - V_63 ;
}
}
V_2 -> V_15 = V_15 ;
V_2 -> V_64 = V_27 -> V_65 ;
V_57 = F_38 ( V_2 , 6 ) ;
if ( V_57 < 0 )
return V_57 ;
V_4 = V_2 -> V_66 + 0 ;
if ( V_27 -> V_67 ) {
V_4 -> type = V_68 ;
V_4 -> V_69 = V_70 | V_71 ;
V_4 -> V_72 = 8 ;
V_4 -> V_73 = ( 1 << V_27 -> V_28 ) - 1 ;
V_4 -> V_23 = V_74 [ V_27 -> V_75 ] ;
V_4 -> V_76 = V_27 -> V_67 ;
V_19 -> V_25 = V_77 [ V_27 -> V_75 ] ;
} else {
V_4 -> type = V_78 ;
}
V_4 = V_2 -> V_66 + 1 ;
if ( V_27 -> V_79 ) {
V_4 -> type = V_80 ;
V_4 -> V_69 = V_81 ;
V_4 -> V_72 = 2 ;
V_4 -> V_73 = ( 1 << V_27 -> V_82 ) - 1 ;
V_4 -> V_23 = & V_83 ;
V_4 -> V_84 = V_27 -> V_79 ;
} else {
V_4 -> type = V_78 ;
}
V_4 = V_2 -> V_66 + 2 ;
if ( V_27 -> V_85 ) {
V_4 -> type = V_86 ;
V_4 -> V_69 = V_70 ;
V_4 -> V_72 = ( V_27 -> V_85 == F_12 ) ? 3 : 8 ;
V_4 -> V_73 = 1 ;
V_4 -> V_23 = & V_87 ;
V_4 -> V_88 = V_27 -> V_85 ;
} else {
V_4 -> type = V_78 ;
}
V_4 = V_2 -> V_66 + 3 ;
if ( V_27 -> V_89 ) {
V_4 -> type = V_90 ;
V_4 -> V_69 = V_81 | V_70 ;
V_4 -> V_72 = V_27 -> V_91 ;
V_4 -> V_73 = 1 ;
V_4 -> V_23 = & V_87 ;
V_4 -> V_88 = V_27 -> V_89 ;
} else {
V_4 -> type = V_78 ;
}
V_4 = V_2 -> V_66 + 4 ;
if ( V_27 -> V_92 != 0 ) {
F_39 ( V_2 , V_4 , NULL , ( unsigned long ) ( V_2 -> V_15 +
V_27 ->
V_92 ) ) ;
} else {
V_4 -> type = V_78 ;
}
V_4 = V_2 -> V_66 + 5 ;
if ( V_27 -> V_93 != 0 ) {
V_4 -> type = V_94 ;
V_4 -> V_69 = V_81 | V_70 ;
V_4 -> V_72 = 3 ;
V_4 -> V_73 = 0xFFFF ;
V_4 -> V_76 = F_33 ;
V_4 -> V_84 = F_34 ;
V_4 -> V_95 = F_35 ;
V_19 -> V_53 . V_96 = 3 ;
V_19 -> V_53 . V_51 [ 0 ] = 0 ;
V_19 -> V_53 . V_51 [ 1 ] = 1 ;
V_19 -> V_53 . V_51 [ 2 ] = 2 ;
V_19 -> V_53 . V_15 = V_15 + V_27 -> V_93 ;
V_19 -> V_53 . V_52 [ 0 ] =
V_19 -> V_53 . V_52 [ 1 ] =
V_19 -> V_53 . V_52 [ 2 ] = V_97 | V_98 ;
F_28 ( & V_19 -> V_53 ) ;
} else {
V_4 -> type = V_78 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_99 * V_100 )
{
int V_57 ;
unsigned long V_15 ;
#ifdef F_41
unsigned long V_101 = 0 ;
struct V_102 * V_103 = NULL ;
#endif
V_57 = F_42 ( V_2 , sizeof( struct V_104 ) ) ;
if ( V_57 < 0 )
return V_57 ;
F_9 ( V_29 L_6 , V_2 -> V_105 ) ;
#ifdef F_41
if ( V_27 -> V_58 == V_60 ) {
if ( V_100 -> V_106 [ 0 ] || V_100 -> V_106 [ 1 ] ) {
F_9 ( L_7 ,
V_100 -> V_106 [ 0 ] , V_100 -> V_106 [ 1 ] ) ;
}
F_9 ( L_8 ) ;
F_43 (pdev) {
if ( V_103 -> V_107 == V_108
&& V_103 -> V_109 == V_110 ) {
if ( V_100 -> V_106 [ 0 ] || V_100 -> V_106 [ 1 ] ) {
if ( V_103 -> V_111 -> V_112 == V_100 -> V_106 [ 0 ]
&& F_44 ( V_103 -> V_113 ) ==
V_100 -> V_106 [ 1 ] ) {
break;
}
} else {
break;
}
}
}
if ( ! V_103 ) {
F_9 ( V_34 L_9 ) ;
return - V_63 ;
}
V_19 -> V_103 = V_103 ;
if ( F_45 ( V_103 , V_62 ) ) {
F_9 ( V_34 L_10
L_11 ) ;
return - V_63 ;
}
V_101 = F_46 ( V_103 , 1 ) ;
V_15 = F_46 ( V_103 , 2 ) ;
F_9 ( V_29 L_12 ,
V_101 , V_15 ) ;
V_19 -> V_101 = V_101 ;
#if 0
outb(CNTRL_INTR | CNTRL_DIR, pci_iobase + CNTRL);
outw(INTR1_ENABLE | PCI_INTR_ENABLE, pci_iobase + INTCSR);
#endif
} else
#endif
{
V_15 = V_100 -> V_106 [ 0 ] ;
}
F_9 ( V_29 L_8 ) ;
return F_36 ( V_2 , V_15 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_66 )
F_48 ( V_2 , V_2 -> V_66 + 4 ) ;
if ( ( V_27 -> V_58 != V_59 ) && ( V_27 -> V_58 != V_60 ) ) {
if ( V_2 -> V_15 )
F_49 ( V_2 -> V_15 , V_27 -> V_61 ) ;
}
#ifdef F_41
if ( V_19 ) {
if ( V_19 -> V_103 ) {
if ( V_19 -> V_101 )
F_50 ( V_19 -> V_103 ) ;
F_51 ( V_19 -> V_103 ) ;
}
}
#endif
}
static int T_1 F_52 ( struct V_102 * V_2 ,
const struct V_114 * V_115 )
{
return F_53 ( V_2 , & V_116 ) ;
}
static void T_2 F_54 ( struct V_102 * V_2 )
{
F_55 ( V_2 ) ;
}
static int T_3 F_56 ( void )
{
int V_117 = 0 ;
#ifdef F_57
V_117 = F_58 ( & V_116 ) ;
if ( V_117 < 0 )
return V_117 ;
#endif
#ifdef F_41
V_118 . V_65 = ( char * ) V_116 . V_119 ;
V_117 = F_59 ( & V_118 ) ;
#endif
return V_117 ;
}
static void T_4 F_60 ( void )
{
#ifdef F_41
F_61 ( & V_118 ) ;
#endif
#ifdef F_57
F_62 ( & V_116 ) ;
#endif
}
