static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
int V_13 , V_14 ;
int V_15 ;
int V_16 ;
int V_17 , V_18 ;
V_15 = F_3 ( V_6 -> V_19 ) ;
V_16 = F_4 ( V_6 -> V_19 ) ;
F_5 ( V_2 -> V_20 + V_21 ) ;
F_5 ( V_2 -> V_20 + V_22 ) ;
F_6 ( & V_2 -> V_23 ) ;
V_11 -> V_24 &= ~ V_25 ;
V_11 -> V_24 |= F_7 ( V_15 ) ;
F_8 ( V_11 -> V_24 , V_2 -> V_20 + V_26 ) ;
F_9 ( & V_2 -> V_23 ) ;
if ( V_4 -> V_27 -> V_28 > 1 ) {
V_16 = F_4 ( V_6 -> V_19 ) ;
F_8 ( V_11 -> V_29 [ V_16 ] ,
V_2 -> V_20 + V_30 ) ;
}
for ( V_14 = 0 ; V_14 < V_6 -> V_14 ; V_14 ++ ) {
if ( V_9 -> V_31 == 16 )
if ( F_5 ( V_2 -> V_20 + V_22 ) & 0x80 )
F_10 ( V_2 -> V_32 , L_1 ) ;
F_11 ( 0 , V_2 -> V_20 + V_33 ) ;
for ( V_13 = 0 ; V_13 < V_34 ; V_13 ++ ) {
if ( ! ( F_5 ( V_2 -> V_20 + V_35 ) & V_36 ) )
break;
}
if ( V_13 == V_34 ) {
F_12 ( V_2 -> V_32 , L_2 ) ;
return - V_37 ;
}
V_18 = F_5 ( V_2 -> V_20 + V_22 ) ;
V_17 = F_5 ( V_2 -> V_20 + V_21 ) ;
if ( V_9 -> V_38 == V_39 ) {
V_7 [ V_14 ] = ( V_17 >> 4 ) | ( V_18 << 4 ) ;
} else if ( V_9 -> V_38 == V_40 ) {
V_7 [ V_14 ] = ( V_18 << 8 ) + V_17 ;
} else if ( V_9 -> V_38 == V_41 ) {
if ( V_18 & 0x80 )
V_7 [ V_14 ] = ( 1 << 15 ) | V_17 | ( ( V_18 & 0x7f ) << 8 ) ;
else
V_7 [ V_14 ] = ( 1 << 15 ) - ( V_17 | ( V_18 & 0x7f ) << 8 ) ;
} else {
F_13 ( V_2 , L_3 ) ;
return - 1 ;
}
}
return V_14 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 0 ] = 0 ;
V_7 [ 1 ] = F_15 ( F_5 ( V_2 -> V_20 + V_35 ) ) ;
return V_6 -> V_14 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
int V_42 ;
V_42 = ( V_11 -> V_24 >> 4 ) & 0xf ;
V_42 &= ~ V_7 [ 0 ] ;
V_42 |= V_7 [ 0 ] & V_7 [ 1 ] ;
F_6 ( & V_2 -> V_23 ) ;
V_11 -> V_24 &= ~ V_43 ;
V_11 -> V_24 |= F_17 ( V_42 ) ;
F_8 ( V_11 -> V_24 , V_2 -> V_20 + V_26 ) ;
F_9 ( & V_2 -> V_23 ) ;
V_7 [ 1 ] = V_42 ;
return V_6 -> V_14 ;
}
static int T_1
F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 0 ] = 0 ;
V_7 [ 1 ] = F_5 ( V_2 -> V_20 + V_44 ) ;
return V_6 -> V_14 ;
}
static int T_1
F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
V_11 -> V_45 &= ~ V_7 [ 0 ] ;
V_11 -> V_45 |= V_7 [ 0 ] & V_7 [ 1 ] ;
F_8 ( V_11 -> V_45 , V_2 -> V_20 + V_44 ) ;
V_7 [ 1 ] = V_11 -> V_45 ;
return V_6 -> V_14 ;
}
static int T_1
F_20 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_14 ;
int V_17 , V_18 ;
int V_15 ;
V_17 = V_7 [ 0 ] & 0xff ;
V_18 = ( V_7 [ 0 ] >> 8 ) & 0xff ;
V_15 = F_3 ( V_6 -> V_19 ) ;
for ( V_14 = 0 ; V_14 < V_6 -> V_14 ; V_14 ++ ) {
#if 0
outb(lsb, dev->iobase + devpriv->ao_offset_lsb[chan]);
outb(msb, dev->iobase + devpriv->ao_offset_msb[chan]);
#else
F_8 ( V_17 , V_2 -> V_20 + F_21 ( V_15 ) ) ;
F_8 ( V_18 , V_2 -> V_20 + F_22 ( V_15 ) ) ;
#endif
F_5 ( V_2 -> V_20 + V_44 ) ;
}
return V_14 ;
}
static int T_1
F_23 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_14 ;
int V_17 , V_18 ;
int V_15 ;
V_17 = V_7 [ 0 ] & 0xff ;
V_18 = ( V_7 [ 0 ] >> 8 ) & 0xf ;
V_15 = F_3 ( V_6 -> V_19 ) ;
for ( V_14 = 0 ; V_14 < V_6 -> V_14 ; V_14 ++ ) {
#if 0
outb(lsb, dev->iobase + devpriv->ao_offset_lsb[chan]);
outb(msb, dev->iobase + devpriv->ao_offset_msb[chan]);
#else
F_8 ( V_17 , V_2 -> V_20 + F_24 ( V_15 ) ) ;
F_8 ( V_18 , V_2 -> V_20 + F_25 ( V_15 ) ) ;
#endif
F_5 ( V_2 -> V_20 + V_46 ) ;
}
return V_14 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned int V_47 = V_48 | V_49 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < 3 ; ++ V_13 )
F_27 ( V_11 -> V_50 , 0 , V_13 , V_47 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
int V_15 = V_6 -> V_19 ;
V_7 [ 0 ] = F_29 ( V_11 -> V_50 , 0 , V_15 ) ;
return 1 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
int V_15 = V_6 -> V_19 ;
F_31 ( V_11 -> V_50 , 0 , V_15 , V_7 [ 0 ] ) ;
return 1 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
int V_15 = V_6 -> V_19 ;
if ( V_6 -> V_14 != 2 )
return - V_51 ;
switch ( V_7 [ 0 ] ) {
case V_52 :
F_27 ( V_11 -> V_50 , 0 , V_15 , V_7 [ 1 ] ) ;
break;
case V_53 :
V_7 [ 1 ] = F_33 ( V_11 -> V_50 , 0 , V_15 ) ;
break;
default:
return - V_51 ;
break;
}
return 2 ;
}
int F_34 ( struct V_1 * V_2 , unsigned long V_20 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_3 * V_4 ;
int V_54 ;
V_2 -> V_20 = V_20 ;
V_2 -> V_55 = V_9 -> V_56 ;
V_54 = F_35 ( V_2 , 6 ) ;
if ( V_54 )
return V_54 ;
V_4 = V_2 -> V_57 + 0 ;
if ( V_9 -> V_58 ) {
V_4 -> type = V_59 ;
V_4 -> V_60 = V_61 | V_62 ;
V_4 -> V_63 = 8 ;
V_4 -> V_64 = ( 1 << V_9 -> V_31 ) - 1 ;
V_4 -> V_27 = V_65 [ V_9 -> V_66 ] ;
V_4 -> V_67 = V_9 -> V_58 ;
V_11 -> V_29 = V_68 [ V_9 -> V_66 ] ;
} else {
V_4 -> type = V_69 ;
}
V_4 = V_2 -> V_57 + 1 ;
if ( V_9 -> V_70 ) {
V_4 -> type = V_71 ;
V_4 -> V_60 = V_72 ;
V_4 -> V_63 = 2 ;
V_4 -> V_64 = ( 1 << V_9 -> V_73 ) - 1 ;
V_4 -> V_27 = & V_74 ;
V_4 -> V_75 = V_9 -> V_70 ;
} else {
V_4 -> type = V_69 ;
}
V_4 = V_2 -> V_57 + 2 ;
if ( V_9 -> V_76 ) {
V_4 -> type = V_77 ;
V_4 -> V_60 = V_61 ;
V_4 -> V_63 = ( V_9 -> V_76 == F_14 ) ? 3 : 8 ;
V_4 -> V_64 = 1 ;
V_4 -> V_27 = & V_78 ;
V_4 -> V_79 = V_9 -> V_76 ;
} else {
V_4 -> type = V_69 ;
}
V_4 = V_2 -> V_57 + 3 ;
if ( V_9 -> V_80 ) {
V_4 -> type = V_81 ;
V_4 -> V_60 = V_72 | V_61 ;
V_4 -> V_63 = V_9 -> V_82 ;
V_4 -> V_64 = 1 ;
V_4 -> V_27 = & V_78 ;
V_4 -> V_79 = V_9 -> V_80 ;
} else {
V_4 -> type = V_69 ;
}
V_4 = V_2 -> V_57 + 4 ;
if ( V_9 -> V_83 != 0 ) {
F_36 ( V_2 , V_4 , NULL , ( unsigned long ) ( V_2 -> V_20 +
V_9 ->
V_83 ) ) ;
} else {
V_4 -> type = V_69 ;
}
V_4 = V_2 -> V_57 + 5 ;
if ( V_9 -> V_84 != 0 ) {
V_4 -> type = V_85 ;
V_4 -> V_60 = V_72 | V_61 ;
V_4 -> V_63 = 3 ;
V_4 -> V_64 = 0xFFFF ;
V_4 -> V_67 = F_28 ;
V_4 -> V_75 = F_30 ;
V_4 -> V_86 = F_32 ;
V_11 -> V_50 = V_20 + V_9 -> V_84 ;
F_26 ( V_2 ) ;
} else {
V_4 -> type = V_69 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_87 * V_88 )
{
unsigned long V_20 ;
unsigned long V_89 ;
struct V_10 * V_11 = V_2 -> V_12 ;
if ( ! F_38 ( V_90 ) )
return - V_51 ;
V_11 -> V_88 = V_88 ;
if ( F_39 ( V_88 , V_2 -> V_91 -> V_92 ) ) {
F_12 ( V_2 -> V_32 ,
L_4 ) ;
return - V_93 ;
}
V_89 = F_40 ( V_88 , 1 ) ;
V_20 = F_40 ( V_88 , 2 ) ;
F_10 ( V_2 -> V_32 , L_5 ,
V_89 , V_20 ) ;
V_11 -> V_89 = V_89 ;
#if 0
outb(CNTRL_INTR | CNTRL_DIR, pci_iobase + CNTRL);
outw(INTR1_ENABLE | PCI_INTR_ENABLE, pci_iobase + INTCSR);
#endif
return F_34 ( V_2 , V_20 ) ;
}
static const struct V_8 *
F_41 ( struct V_87 * V_88 )
{
#if V_94
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < F_42 ( V_95 ) ; V_13 ++ )
if ( V_95 [ V_13 ] . V_96 == V_97 &&
V_88 -> V_98 == V_95 [ V_13 ] . V_99 )
return & V_95 [ V_13 ] ;
#endif
return NULL ;
}
static int T_2 T_1
F_43 ( struct V_1 * V_2 , struct V_87 * V_88 )
{
int V_54 ;
if ( ! F_38 ( V_90 ) )
return - V_51 ;
V_54 = F_44 ( V_2 , sizeof( struct V_10 ) ) ;
if ( V_54 < 0 )
return V_54 ;
F_10 ( V_2 -> V_32 , L_6 , F_45 ( V_88 ) ) ;
V_2 -> V_100 = F_41 ( V_88 ) ;
if ( V_2 -> V_100 == NULL ) {
F_12 ( V_2 -> V_32 , L_7 ) ;
return - V_51 ;
}
F_46 ( V_88 ) ;
return F_37 ( V_2 , V_88 ) ;
}
static struct V_87 * F_47 ( struct V_1 * V_2 ,
int V_101 , int V_102 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_87 * V_88 ;
unsigned int V_103 ;
if ( V_101 || V_102 )
F_48 ( V_2 -> V_32 , L_8 ,
V_9 -> V_56 , V_101 , V_102 ) ;
else
F_48 ( V_2 -> V_32 , L_9 ,
V_9 -> V_56 ) ;
V_103 = V_9 -> V_99 ;
V_88 = NULL ;
F_49 (pdev) {
if ( ( V_101 || V_102 ) &&
( V_101 != V_88 -> V_101 -> V_104 || V_102 != F_50 ( V_88 -> V_105 ) ) )
continue;
if ( V_88 -> V_106 != V_107 )
continue;
if ( V_103 == V_108 ) {
const struct V_8 * V_109 ;
V_109 = F_41 ( V_88 ) ;
if ( V_109 == NULL )
continue;
V_2 -> V_100 = V_9 = V_109 ;
} else {
if ( V_88 -> V_98 != V_103 )
continue;
}
F_10 ( V_2 -> V_32 , L_10 ,
V_9 -> V_56 , F_45 ( V_88 ) ) ;
return V_88 ;
}
if ( V_101 || V_102 )
F_12 ( V_2 -> V_32 ,
L_11 ,
V_9 -> V_56 , V_101 , V_102 ) ;
else
F_12 ( V_2 -> V_32 , L_12 ,
V_9 -> V_56 ) ;
return NULL ;
}
static int T_1
F_51 ( struct V_1 * V_2 , struct V_110 * V_111 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 ;
int V_54 ;
unsigned long V_20 ;
V_54 = F_44 ( V_2 , sizeof( struct V_10 ) ) ;
if ( V_54 < 0 )
return V_54 ;
V_11 = V_2 -> V_12 ;
F_10 ( V_2 -> V_32 , L_13 ) ;
if ( F_38 ( V_90 ) && V_9 -> V_96 == V_97 ) {
struct V_87 * V_88 ;
V_88 = F_47 ( V_2 , V_111 -> V_112 [ 0 ] , V_111 -> V_112 [ 1 ] ) ;
if ( V_88 == NULL )
return - V_93 ;
return F_37 ( V_2 , V_88 ) ;
} else if ( F_38 ( V_113 ) &&
( V_9 -> V_96 == V_114 || V_9 -> V_96 == V_115 ) ) {
V_20 = V_111 -> V_112 [ 0 ] ;
F_10 ( V_2 -> V_32 , L_14 , V_20 ) ;
if ( ! F_52 ( V_20 , V_9 -> V_116 , V_117 ) ) {
F_12 ( V_2 -> V_32 , L_15 ) ;
return - V_93 ;
}
return F_34 ( V_2 , V_20 ) ;
} else
return - V_93 ;
}
void F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_57 )
F_54 ( V_2 , V_2 -> V_57 + 4 ) ;
}
static void T_1 F_55 ( struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
F_53 ( V_2 ) ;
if ( F_38 ( V_113 ) &&
( V_9 -> V_96 == V_114 || V_9 -> V_96 == V_115 ) ) {
if ( V_2 -> V_20 )
F_56 ( V_2 -> V_20 , V_9 -> V_116 ) ;
} else if ( F_38 ( V_90 ) &&
V_9 -> V_96 == V_97 ) {
if ( V_11 && V_11 -> V_88 ) {
if ( V_11 -> V_89 )
F_57 ( V_11 -> V_88 ) ;
F_58 ( V_11 -> V_88 ) ;
}
}
}
static int T_2 F_59 ( struct V_87 * V_2 ,
const struct V_118 * V_119 )
{
return F_60 ( V_2 , & V_120 ) ;
}
static void T_3 F_61 ( struct V_87 * V_2 )
{
F_62 ( V_2 ) ;
}
static int T_4 F_63 ( void )
{
return 0 ;
}
static void T_5 F_64 ( void )
{
}
