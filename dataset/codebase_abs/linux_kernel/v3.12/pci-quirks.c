void F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , 0x50 , & V_4 ) ;
if ( V_3 == 0 )
F_4 ( V_6 , 0x50 , V_4 & 0xfcff ) ;
else
F_4 ( V_6 , 0x50 , V_4 | 0x0300 ) ;
}
int F_5 ( void )
{
T_2 V_7 = 0 ;
unsigned long V_8 ;
struct V_9 V_10 ;
int V_11 ;
F_6 ( & V_12 , V_8 ) ;
if ( V_13 . V_14 > 0 ) {
V_13 . V_14 ++ ;
F_7 ( & V_12 , V_8 ) ;
return V_13 . V_15 ;
}
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
F_7 ( & V_12 , V_8 ) ;
V_10 . V_16 = F_8 ( V_17 , 0x4385 , NULL ) ;
if ( V_10 . V_16 ) {
V_7 = V_10 . V_16 -> V_18 ;
if ( V_7 >= 0x40 )
V_10 . V_19 = 1 ;
else if ( V_7 >= 0x30 && V_7 <= 0x3b )
V_10 . V_19 = 3 ;
} else {
V_10 . V_16 = F_8 ( V_20 ,
0x780b , NULL ) ;
if ( ! V_10 . V_16 ) {
V_11 = 0 ;
goto V_21;
}
V_7 = V_10 . V_16 -> V_18 ;
if ( V_7 >= 0x11 && V_7 <= 0x18 )
V_10 . V_19 = 2 ;
}
if ( V_10 . V_19 == 0 ) {
if ( V_10 . V_16 ) {
F_9 ( V_10 . V_16 ) ;
V_10 . V_16 = NULL ;
}
V_11 = 0 ;
goto V_21;
}
V_10 . V_22 = F_8 ( V_20 , 0x9601 , NULL ) ;
if ( V_10 . V_22 ) {
V_10 . V_23 = 1 ;
} else {
V_10 . V_22 = F_8 ( V_20 , 0x1510 , NULL ) ;
if ( V_10 . V_22 ) {
V_10 . V_23 = 2 ;
} else {
V_10 . V_22 = F_8 ( V_20 ,
0x9600 , NULL ) ;
if ( V_10 . V_22 )
V_10 . V_23 = 3 ;
}
}
V_11 = V_10 . V_15 = 1 ;
F_10 ( V_24 L_1 ) ;
V_21:
F_6 ( & V_12 , V_8 ) ;
if ( V_13 . V_14 > 0 ) {
V_13 . V_14 ++ ;
V_11 = V_13 . V_15 ;
F_7 ( & V_12 , V_8 ) ;
if ( V_10 . V_22 )
F_9 ( V_10 . V_22 ) ;
if ( V_10 . V_16 )
F_9 ( V_10 . V_16 ) ;
} else {
V_10 . V_14 ++ ;
V_13 = V_10 ;
F_7 ( & V_12 , V_8 ) ;
}
return V_11 ;
}
static void F_11 ( int V_25 )
{
T_3 V_26 , V_27 , V_28 , V_29 ;
T_3 V_30 = V_25 ? 0 : 1 ;
unsigned long V_8 ;
F_6 ( & V_12 , V_8 ) ;
if ( V_25 ) {
V_13 . V_31 ++ ;
if ( V_13 . V_31 > 1 ) {
F_7 ( & V_12 , V_8 ) ;
return;
}
} else {
V_13 . V_31 -- ;
if ( V_13 . V_31 > 0 ) {
F_7 ( & V_12 , V_8 ) ;
return;
}
}
if ( V_13 . V_19 == 1 || V_13 . V_19 == 2 ) {
F_12 ( V_32 , 0xcd6 ) ;
V_27 = F_13 ( 0xcd7 ) ;
F_12 ( V_33 , 0xcd6 ) ;
V_28 = F_13 ( 0xcd7 ) ;
V_26 = V_28 << 8 | V_27 ;
F_14 ( 0x30 , F_15 ( V_26 ) ) ;
F_14 ( 0x40 , F_16 ( V_26 ) ) ;
F_14 ( 0x34 , F_15 ( V_26 ) ) ;
V_29 = F_17 ( F_16 ( V_26 ) ) ;
} else if ( V_13 . V_19 == 3 ) {
F_18 ( V_13 . V_16 ,
V_34 , & V_26 ) ;
F_19 ( V_35 , F_15 ( V_26 ) ) ;
F_19 ( 0x40 , F_16 ( V_26 ) ) ;
F_19 ( V_36 , F_15 ( V_26 ) ) ;
V_29 = F_20 ( F_16 ( V_26 ) ) ;
} else {
F_7 ( & V_12 , V_8 ) ;
return;
}
if ( V_25 ) {
V_29 &= ~ 0x08 ;
V_29 |= ( 1 << 4 ) | ( 1 << 9 ) ;
} else {
V_29 |= 0x08 ;
V_29 &= ~ ( ( 1 << 4 ) | ( 1 << 9 ) ) ;
}
F_14 ( V_29 , F_16 ( V_26 ) ) ;
if ( ! V_13 . V_22 ) {
F_7 ( & V_12 , V_8 ) ;
return;
}
if ( V_13 . V_23 == 1 || V_13 . V_23 == 3 ) {
V_26 = V_37 ;
F_21 ( V_13 . V_22 ,
V_38 , V_26 ) ;
F_18 ( V_13 . V_22 ,
V_39 , & V_29 ) ;
V_29 &= ~ ( 1 | ( 1 << 3 ) | ( 1 << 4 ) | ( 1 << 9 ) | ( 1 << 12 ) ) ;
V_29 |= V_30 | ( V_30 << 3 ) | ( V_30 << 12 ) ;
V_29 |= ( ( ! V_30 ) << 4 ) | ( ( ! V_30 ) << 9 ) ;
F_21 ( V_13 . V_22 ,
V_39 , V_29 ) ;
V_26 = V_40 ;
F_21 ( V_13 . V_22 ,
V_38 , V_26 ) ;
F_18 ( V_13 . V_22 ,
V_39 , & V_29 ) ;
V_29 &= ~ ( 1 << 8 ) ;
V_29 |= V_30 << 8 ;
F_21 ( V_13 . V_22 ,
V_39 , V_29 ) ;
} else if ( V_13 . V_23 == 2 ) {
V_26 = V_41 ;
F_21 ( V_13 . V_22 ,
V_38 , V_26 ) ;
F_18 ( V_13 . V_22 ,
V_39 , & V_29 ) ;
if ( V_25 )
V_29 &= ~ ( 0x3f << 7 ) ;
else
V_29 |= 0x3f << 7 ;
F_21 ( V_13 . V_22 ,
V_39 , V_29 ) ;
V_26 = V_42 ;
F_21 ( V_13 . V_22 ,
V_38 , V_26 ) ;
F_18 ( V_13 . V_22 ,
V_39 , & V_29 ) ;
if ( V_25 )
V_29 &= ~ ( 0x3f << 7 ) ;
else
V_29 |= 0x3f << 7 ;
F_21 ( V_13 . V_22 ,
V_39 , V_29 ) ;
}
F_7 ( & V_12 , V_8 ) ;
return;
}
void F_22 ( void )
{
F_11 ( 1 ) ;
}
void F_23 ( void )
{
F_11 ( 0 ) ;
}
void F_24 ( void )
{
struct V_5 * V_43 , * V_44 ;
unsigned long V_8 ;
F_6 ( & V_12 , V_8 ) ;
V_13 . V_14 -- ;
if ( V_13 . V_14 > 0 ) {
F_7 ( & V_12 , V_8 ) ;
return;
}
V_43 = V_13 . V_22 ;
V_44 = V_13 . V_16 ;
V_13 . V_22 = NULL ;
V_13 . V_16 = NULL ;
V_13 . V_23 = 0 ;
V_13 . V_19 = 0 ;
V_13 . V_31 = 0 ;
V_13 . V_15 = 0 ;
F_7 ( & V_12 , V_8 ) ;
if ( V_43 )
F_9 ( V_43 ) ;
if ( V_44 )
F_9 ( V_44 ) ;
}
void F_25 ( struct V_5 * V_6 , unsigned long V_45 )
{
F_4 ( V_6 , V_46 , V_47 ) ;
F_26 ( V_48 , V_45 + V_49 ) ;
F_27 () ;
F_28 ( 5 ) ;
if ( F_29 ( V_45 + V_49 ) & V_48 )
F_30 ( & V_6 -> V_2 , L_2 ) ;
F_26 ( 0 , V_45 + V_50 ) ;
F_26 ( 0 , V_45 + V_49 ) ;
}
int F_31 ( struct V_5 * V_6 , unsigned long V_45 )
{
T_1 V_51 ;
unsigned int V_52 , V_53 ;
F_3 ( V_6 , V_46 , & V_51 ) ;
if ( V_51 & ~ ( V_54 | V_47 ) ) {
F_32 ( & V_6 -> V_2 , L_3 ,
V_55 , V_51 ) ;
goto V_56;
}
V_52 = F_29 ( V_45 + V_49 ) ;
if ( ( V_52 & V_57 ) || ! ( V_52 & V_58 ) ||
! ( V_52 & V_59 ) ) {
F_32 ( & V_6 -> V_2 , L_4 ,
V_55 , V_52 ) ;
goto V_56;
}
V_53 = F_29 ( V_45 + V_50 ) ;
if ( V_53 & ( ~ V_60 ) ) {
F_32 ( & V_6 -> V_2 , L_5 ,
V_55 , V_53 ) ;
goto V_56;
}
return 0 ;
V_56:
F_32 ( & V_6 -> V_2 , L_6 ) ;
F_25 ( V_6 , V_45 ) ;
return 1 ;
}
static inline int F_33 ( struct V_5 * V_6 , unsigned int V_61 )
{
T_1 V_52 ;
return ! F_3 ( V_6 , V_62 , & V_52 ) && ( V_52 & V_61 ) ;
}
static void F_34 ( struct V_5 * V_6 )
{
unsigned long V_45 = 0 ;
int V_63 ;
if ( ! F_35 ( V_6 ) )
return;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ )
if ( ( F_36 ( V_6 , V_63 ) & V_65 ) ) {
V_45 = F_37 ( V_6 , V_63 ) ;
break;
}
if ( V_45 )
F_31 ( V_6 , V_45 ) ;
}
static int F_38 ( struct V_5 * V_6 , int V_66 )
{
return F_37 ( V_6 , V_66 ) && F_39 ( V_6 ) ;
}
static void F_40 ( struct V_5 * V_6 )
{
void T_4 * V_45 ;
T_3 V_67 ;
T_3 V_68 ;
int V_69 ;
if ( ! F_38 ( V_6 , 0 ) )
return;
V_45 = F_41 ( V_6 , 0 ) ;
if ( V_45 == NULL )
return;
V_67 = F_42 ( V_45 + V_70 ) ;
#ifdef F_43
#define F_44 (OHCI_CTRL_RWC | OHCI_CTRL_IR)
#else
#define F_44 OHCI_CTRL_RWC
if ( V_67 & V_71 ) {
int V_72 = 500 ;
F_45 ( V_73 , V_45 + V_74 ) ;
F_45 ( V_75 , V_45 + V_76 ) ;
while ( V_72 > 0 &&
F_42 ( V_45 + V_70 ) & V_71 ) {
V_72 -= 10 ;
F_46 ( 10 ) ;
}
if ( V_72 <= 0 )
F_30 ( & V_6 -> V_2 , L_7
L_8 ,
F_42 ( V_45 + V_70 ) ) ;
}
#endif
F_45 ( ( T_3 ) ~ 0 , V_45 + V_77 ) ;
if ( V_67 & V_78 ) {
F_45 ( V_67 & F_44 , V_45 + V_70 ) ;
F_42 ( V_45 + V_70 ) ;
F_46 ( 50 ) ;
}
V_68 = F_42 ( V_45 + V_79 ) ;
F_45 ( V_80 , V_45 + V_76 ) ;
for ( V_69 = 30 ; V_69 > 0 ; -- V_69 ) {
if ( ( F_42 ( V_45 + V_76 ) & V_80 ) == 0 )
break;
F_28 ( 1 ) ;
}
F_45 ( V_68 , V_45 + V_79 ) ;
F_47 ( V_45 ) ;
}
static void F_48 ( struct V_5 * V_6 ,
void T_4 * V_81 ,
T_3 V_82 , T_2 V_83 )
{
int V_84 = 1 , V_85 = 0 ;
if ( V_6 -> V_86 == 0x8086 && V_6 -> V_1 == 0x283a ) {
if ( F_49 ( V_87 ) )
V_84 = 0 ;
}
if ( V_84 && ( V_82 & V_88 ) ) {
F_32 ( & V_6 -> V_2 , L_9 ) ;
#if 0
pci_read_config_dword(pdev, offset + EHCI_USBLEGCTLSTS, &val);
pci_write_config_dword(pdev, offset + EHCI_USBLEGCTLSTS,
val | EHCI_USBLEGCTLSTS_SOOE);
#endif
F_50 ( V_6 , V_83 + 3 , 1 ) ;
}
if ( V_84 ) {
int V_89 = 1000 ;
while ( ( V_82 & V_88 ) && ( V_89 > 0 ) ) {
V_85 = 1 ;
F_46 ( 10 ) ;
V_89 -= 10 ;
F_18 ( V_6 , V_83 , & V_82 ) ;
}
}
if ( V_82 & V_88 ) {
if ( V_84 )
F_30 ( & V_6 -> V_2 , L_10
L_8 , V_82 ) ;
F_50 ( V_6 , V_83 + 2 , 0 ) ;
}
F_21 ( V_6 , V_83 + V_90 , 0 ) ;
if ( V_85 )
F_45 ( 0 , V_81 + V_91 ) ;
}
static void F_51 ( struct V_5 * V_6 )
{
void T_4 * V_45 , * V_81 ;
T_3 V_92 , V_82 , V_29 ;
T_2 V_83 , V_93 ;
int V_72 , V_94 = 256 / 4 ;
if ( ! F_38 ( V_6 , 0 ) )
return;
V_45 = F_41 ( V_6 , 0 ) ;
if ( V_45 == NULL )
return;
V_93 = F_52 ( V_45 ) ;
V_81 = V_45 + V_93 ;
V_92 = F_42 ( V_45 + V_95 ) ;
V_83 = ( V_92 >> 8 ) & 0xff ;
while ( V_83 && -- V_94 ) {
F_18 ( V_6 , V_83 , & V_82 ) ;
switch ( V_82 & 0xff ) {
case 1 :
F_48 ( V_6 , V_81 , V_82 , V_83 ) ;
break;
case 0 :
V_82 = 0 ;
default:
F_30 ( & V_6 -> V_2 , L_11
L_12 , V_82 & 0xff ) ;
}
V_83 = ( V_82 >> 8 ) & 0xff ;
}
if ( ! V_94 )
F_53 ( V_24 , & V_6 -> V_2 , L_13 ) ;
V_29 = F_42 ( V_81 + V_96 ) ;
if ( ( V_29 & V_97 ) == 0 ) {
V_29 = F_42 ( V_81 + V_98 ) ;
V_29 &= ~ V_99 ;
F_45 ( V_29 , V_81 + V_98 ) ;
V_72 = 2000 ;
do {
F_45 ( 0x3f , V_81 + V_96 ) ;
F_28 ( 100 ) ;
V_72 -= 100 ;
V_29 = F_42 ( V_81 + V_96 ) ;
if ( ( V_29 == ~ ( T_3 ) 0 ) || ( V_29 & V_97 ) ) {
break;
}
} while ( V_72 > 0 );
}
F_45 ( 0 , V_81 + V_100 ) ;
F_45 ( 0x3f , V_81 + V_96 ) ;
F_47 ( V_45 ) ;
}
static int F_54 ( void T_4 * V_101 , T_3 V_61 , T_3 V_102 ,
int V_103 , int V_104 )
{
T_3 V_105 ;
do {
V_105 = F_42 ( V_101 ) ;
V_105 &= V_61 ;
if ( V_105 == V_102 )
return 0 ;
F_28 ( V_104 ) ;
V_103 -= V_104 ;
} while ( V_103 > 0 );
return - V_106 ;
}
void F_55 ( struct V_5 * V_107 )
{
T_3 V_108 ;
bool V_109 = false ;
struct V_5 * V_110 = NULL ;
F_56 (companion) {
if ( V_110 -> V_111 == V_112 &&
V_110 -> V_86 == V_113 ) {
V_109 = true ;
break;
}
}
if ( ! V_109 )
return;
if ( ! F_57 ( V_114 ) ) {
F_30 ( & V_107 -> V_2 ,
L_14
L_15 ) ;
F_30 ( & V_107 -> V_2 ,
L_16 ) ;
F_58 ( V_107 ) ;
return;
}
F_18 ( V_107 , V_115 ,
& V_108 ) ;
F_32 ( & V_107 -> V_2 , L_17 ,
V_108 ) ;
F_21 ( V_107 , V_116 ,
V_108 ) ;
F_18 ( V_107 , V_116 ,
& V_108 ) ;
F_32 ( & V_107 -> V_2 , L_18
L_19 , V_108 ) ;
F_18 ( V_107 , V_117 ,
& V_108 ) ;
F_32 ( & V_107 -> V_2 , L_20 ,
V_108 ) ;
F_21 ( V_107 , V_118 ,
V_108 ) ;
F_18 ( V_107 , V_118 ,
& V_108 ) ;
F_32 ( & V_107 -> V_2 , L_21
L_22 , V_108 ) ;
}
void F_58 ( struct V_5 * V_107 )
{
F_21 ( V_107 , V_116 , 0x0 ) ;
F_21 ( V_107 , V_118 , 0x0 ) ;
}
static void F_59 ( struct V_5 * V_6 )
{
void T_4 * V_45 ;
int V_119 ;
void T_4 * V_81 ;
T_3 V_29 ;
int V_120 ;
int V_121 = F_60 ( V_6 , 0 ) ;
if ( ! F_38 ( V_6 , 0 ) )
return;
V_45 = F_61 ( F_37 ( V_6 , 0 ) , V_121 ) ;
if ( V_45 == NULL )
return;
V_119 = F_62 ( V_45 , V_122 ) ;
do {
if ( ( V_119 + sizeof( V_29 ) ) > V_121 ) {
F_30 ( & V_6 -> V_2 ,
L_23 ) ;
return;
}
if ( ! V_119 )
goto V_123;
V_29 = F_42 ( V_45 + V_119 ) ;
if ( F_63 ( V_29 ) == V_124 )
break;
V_119 = F_62 ( V_45 , V_119 ) ;
} while ( 1 );
if ( V_29 & V_125 ) {
F_45 ( V_29 | V_126 , V_45 + V_119 ) ;
V_120 = F_54 ( V_45 + V_119 , V_125 ,
0 , 5000 , 10 ) ;
if ( V_120 ) {
F_30 ( & V_6 -> V_2 , L_24
L_25 , V_29 ) ;
F_45 ( V_29 & ~ V_125 , V_45 + V_119 ) ;
}
}
V_29 = F_42 ( V_45 + V_119 + V_127 ) ;
V_29 &= V_128 ;
V_29 |= V_129 ;
F_45 ( V_29 , V_45 + V_119 + V_127 ) ;
V_123:
if ( V_6 -> V_86 == V_113 )
F_55 ( V_6 ) ;
V_81 = V_45 + F_64 ( F_42 ( V_45 ) ) ;
V_120 = F_54 ( V_81 + V_130 , V_131 , 0 ,
5000 , 10 ) ;
if ( V_120 ) {
V_29 = F_42 ( V_81 + V_130 ) ;
F_30 ( & V_6 -> V_2 ,
L_26
L_27 , V_29 ) ;
}
V_29 = F_42 ( V_81 + V_132 ) ;
V_29 &= ~ ( V_133 | V_134 ) ;
F_45 ( V_29 , V_81 + V_132 ) ;
V_120 = F_54 ( V_81 + V_130 , V_135 , 1 ,
V_136 , 125 ) ;
if ( V_120 ) {
V_29 = F_42 ( V_81 + V_130 ) ;
F_30 ( & V_6 -> V_2 ,
L_28
L_27 , V_136 , V_29 ) ;
}
F_47 ( V_45 ) ;
}
static void F_65 ( struct V_5 * V_6 )
{
if ( V_6 -> V_86 == 0x184e )
return;
if ( V_6 -> V_111 != V_137 &&
V_6 -> V_111 != V_138 &&
V_6 -> V_111 != V_112 &&
V_6 -> V_111 != V_139 )
return;
if ( F_66 ( V_6 ) < 0 ) {
F_30 ( & V_6 -> V_2 , L_29
L_30 ) ;
return;
}
if ( V_6 -> V_111 == V_137 )
F_34 ( V_6 ) ;
else if ( V_6 -> V_111 == V_138 )
F_40 ( V_6 ) ;
else if ( V_6 -> V_111 == V_112 )
F_51 ( V_6 ) ;
else if ( V_6 -> V_111 == V_139 )
F_59 ( V_6 ) ;
F_67 ( V_6 ) ;
}
