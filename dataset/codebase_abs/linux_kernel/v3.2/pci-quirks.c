int F_1 ( void )
{
T_1 V_1 = 0 ;
unsigned long V_2 ;
struct V_3 V_4 ;
int V_5 ;
F_2 ( & V_6 , V_2 ) ;
if ( V_7 . V_8 > 0 ) {
V_7 . V_8 ++ ;
F_3 ( & V_6 , V_2 ) ;
return V_7 . V_9 ;
}
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
F_3 ( & V_6 , V_2 ) ;
V_4 . V_10 = F_4 ( V_11 , 0x4385 , NULL ) ;
if ( V_4 . V_10 ) {
V_1 = V_4 . V_10 -> V_12 ;
if ( V_1 >= 0x40 )
V_4 . V_13 = 1 ;
else if ( V_1 >= 0x30 && V_1 <= 0x3b )
V_4 . V_13 = 3 ;
} else {
V_4 . V_10 = F_4 ( V_14 ,
0x780b , NULL ) ;
if ( ! V_4 . V_10 ) {
V_5 = 0 ;
goto V_15;
}
V_1 = V_4 . V_10 -> V_12 ;
if ( V_1 >= 0x11 && V_1 <= 0x18 )
V_4 . V_13 = 2 ;
}
if ( V_4 . V_13 == 0 ) {
if ( V_4 . V_10 ) {
F_5 ( V_4 . V_10 ) ;
V_4 . V_10 = NULL ;
}
V_5 = 0 ;
goto V_15;
}
V_4 . V_16 = F_4 ( V_14 , 0x9601 , NULL ) ;
if ( V_4 . V_16 ) {
V_4 . V_17 = 1 ;
} else {
V_4 . V_16 = F_4 ( V_14 , 0x1510 , NULL ) ;
if ( V_4 . V_16 ) {
V_4 . V_17 = 2 ;
} else {
V_4 . V_16 = F_4 ( V_14 ,
0x9600 , NULL ) ;
if ( V_4 . V_16 )
V_4 . V_17 = 3 ;
}
}
V_5 = V_4 . V_9 = 1 ;
F_6 ( V_18 L_1 ) ;
V_15:
F_2 ( & V_6 , V_2 ) ;
if ( V_7 . V_8 > 0 ) {
V_7 . V_8 ++ ;
V_5 = V_7 . V_9 ;
F_3 ( & V_6 , V_2 ) ;
if ( V_4 . V_16 )
F_5 ( V_4 . V_16 ) ;
if ( V_4 . V_10 )
F_5 ( V_4 . V_10 ) ;
} else {
V_4 . V_8 ++ ;
V_7 = V_4 ;
F_3 ( & V_6 , V_2 ) ;
}
return V_5 ;
}
static void F_7 ( int V_19 )
{
T_2 V_20 , V_21 , V_22 , V_23 ;
T_2 V_24 = V_19 ? 0 : 1 ;
unsigned long V_2 ;
F_2 ( & V_6 , V_2 ) ;
if ( V_19 ) {
V_7 . V_25 ++ ;
if ( V_7 . V_25 > 1 ) {
F_3 ( & V_6 , V_2 ) ;
return;
}
} else {
V_7 . V_25 -- ;
if ( V_7 . V_25 > 0 ) {
F_3 ( & V_6 , V_2 ) ;
return;
}
}
if ( V_7 . V_13 == 1 || V_7 . V_13 == 2 ) {
F_8 ( V_26 , 0xcd6 ) ;
V_21 = F_9 ( 0xcd7 ) ;
F_8 ( V_27 , 0xcd6 ) ;
V_22 = F_9 ( 0xcd7 ) ;
V_20 = V_22 << 8 | V_21 ;
F_10 ( 0x30 , F_11 ( V_20 ) ) ;
F_10 ( 0x40 , F_12 ( V_20 ) ) ;
F_10 ( 0x34 , F_11 ( V_20 ) ) ;
V_23 = F_13 ( F_12 ( V_20 ) ) ;
} else if ( V_7 . V_13 == 3 ) {
F_14 ( V_7 . V_10 ,
V_28 , & V_20 ) ;
F_15 ( V_29 , F_11 ( V_20 ) ) ;
F_15 ( 0x40 , F_12 ( V_20 ) ) ;
F_15 ( V_30 , F_11 ( V_20 ) ) ;
V_23 = F_16 ( F_12 ( V_20 ) ) ;
} else {
F_3 ( & V_6 , V_2 ) ;
return;
}
if ( V_19 ) {
V_23 &= ~ 0x08 ;
V_23 |= ( 1 << 4 ) | ( 1 << 9 ) ;
} else {
V_23 |= 0x08 ;
V_23 &= ~ ( ( 1 << 4 ) | ( 1 << 9 ) ) ;
}
F_10 ( V_23 , F_12 ( V_20 ) ) ;
if ( ! V_7 . V_16 ) {
F_3 ( & V_6 , V_2 ) ;
return;
}
if ( V_7 . V_17 == 1 || V_7 . V_17 == 3 ) {
V_20 = V_31 ;
F_17 ( V_7 . V_16 ,
V_32 , V_20 ) ;
F_14 ( V_7 . V_16 ,
V_33 , & V_23 ) ;
V_23 &= ~ ( 1 | ( 1 << 3 ) | ( 1 << 4 ) | ( 1 << 9 ) | ( 1 << 12 ) ) ;
V_23 |= V_24 | ( V_24 << 3 ) | ( V_24 << 12 ) ;
V_23 |= ( ( ! V_24 ) << 4 ) | ( ( ! V_24 ) << 9 ) ;
F_17 ( V_7 . V_16 ,
V_33 , V_23 ) ;
V_20 = V_34 ;
F_17 ( V_7 . V_16 ,
V_32 , V_20 ) ;
F_14 ( V_7 . V_16 ,
V_33 , & V_23 ) ;
V_23 &= ~ ( 1 << 8 ) ;
V_23 |= V_24 << 8 ;
F_17 ( V_7 . V_16 ,
V_33 , V_23 ) ;
} else if ( V_7 . V_17 == 2 ) {
V_20 = V_35 ;
F_17 ( V_7 . V_16 ,
V_32 , V_20 ) ;
F_14 ( V_7 . V_16 ,
V_33 , & V_23 ) ;
if ( V_19 )
V_23 &= ~ ( 0x3f << 7 ) ;
else
V_23 |= 0x3f << 7 ;
F_17 ( V_7 . V_16 ,
V_33 , V_23 ) ;
V_20 = V_36 ;
F_17 ( V_7 . V_16 ,
V_32 , V_20 ) ;
F_14 ( V_7 . V_16 ,
V_33 , & V_23 ) ;
if ( V_19 )
V_23 &= ~ ( 0x3f << 7 ) ;
else
V_23 |= 0x3f << 7 ;
F_17 ( V_7 . V_16 ,
V_33 , V_23 ) ;
}
F_3 ( & V_6 , V_2 ) ;
return;
}
void F_18 ( void )
{
F_7 ( 1 ) ;
}
void F_19 ( void )
{
F_7 ( 0 ) ;
}
void F_20 ( void )
{
struct V_37 * V_38 , * V_39 ;
unsigned long V_2 ;
F_2 ( & V_6 , V_2 ) ;
V_7 . V_8 -- ;
if ( V_7 . V_8 > 0 ) {
F_3 ( & V_6 , V_2 ) ;
return;
}
V_38 = V_7 . V_16 ;
V_39 = V_7 . V_10 ;
V_7 . V_16 = NULL ;
V_7 . V_10 = NULL ;
V_7 . V_17 = 0 ;
V_7 . V_13 = 0 ;
V_7 . V_25 = 0 ;
V_7 . V_9 = 0 ;
F_3 ( & V_6 , V_2 ) ;
if ( V_38 )
F_5 ( V_38 ) ;
if ( V_39 )
F_5 ( V_39 ) ;
}
void F_21 ( struct V_37 * V_40 , unsigned long V_41 )
{
F_22 ( V_40 , V_42 , V_43 ) ;
F_23 ( V_44 , V_41 + V_45 ) ;
F_24 () ;
F_25 ( 5 ) ;
if ( F_26 ( V_41 + V_45 ) & V_44 )
F_27 ( & V_40 -> V_46 , L_2 ) ;
F_23 ( 0 , V_41 + V_47 ) ;
F_23 ( 0 , V_41 + V_45 ) ;
}
int F_28 ( struct V_37 * V_40 , unsigned long V_41 )
{
T_3 V_48 ;
unsigned int V_49 , V_50 ;
F_29 ( V_40 , V_42 , & V_48 ) ;
if ( V_48 & ~ ( V_51 | V_43 ) ) {
F_30 ( & V_40 -> V_46 , L_3 ,
V_52 , V_48 ) ;
goto V_53;
}
V_49 = F_26 ( V_41 + V_45 ) ;
if ( ( V_49 & V_54 ) || ! ( V_49 & V_55 ) ||
! ( V_49 & V_56 ) ) {
F_30 ( & V_40 -> V_46 , L_4 ,
V_52 , V_49 ) ;
goto V_53;
}
V_50 = F_26 ( V_41 + V_47 ) ;
if ( V_50 & ( ~ V_57 ) ) {
F_30 ( & V_40 -> V_46 , L_5 ,
V_52 , V_50 ) ;
goto V_53;
}
return 0 ;
V_53:
F_30 ( & V_40 -> V_46 , L_6 ) ;
F_21 ( V_40 , V_41 ) ;
return 1 ;
}
static inline int F_31 ( struct V_37 * V_40 , unsigned int V_58 )
{
T_3 V_49 ;
return ! F_29 ( V_40 , V_59 , & V_49 ) && ( V_49 & V_58 ) ;
}
static void T_4 F_32 ( struct V_37 * V_40 )
{
unsigned long V_41 = 0 ;
int V_60 ;
if ( ! F_33 ( V_40 ) )
return;
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ )
if ( ( F_34 ( V_40 , V_60 ) & V_62 ) ) {
V_41 = F_35 ( V_40 , V_60 ) ;
break;
}
if ( V_41 )
F_28 ( V_40 , V_41 ) ;
}
static int T_4 F_36 ( struct V_37 * V_40 , int V_63 )
{
return F_35 ( V_40 , V_63 ) && F_37 ( V_40 ) ;
}
static void T_4 F_38 ( struct V_37 * V_40 )
{
void T_5 * V_41 ;
T_2 V_64 ;
T_2 V_65 ;
int V_66 ;
if ( ! F_36 ( V_40 , 0 ) )
return;
V_41 = F_39 ( V_40 , 0 ) ;
if ( V_41 == NULL )
return;
V_64 = F_40 ( V_41 + V_67 ) ;
#ifdef F_41
#define F_42 (OHCI_CTRL_RWC | OHCI_CTRL_IR)
#else
#define F_42 OHCI_CTRL_RWC
if ( V_64 & V_68 ) {
int V_69 = 500 ;
F_43 ( V_70 , V_41 + V_71 ) ;
F_43 ( V_72 , V_41 + V_73 ) ;
while ( V_69 > 0 &&
F_40 ( V_41 + V_67 ) & V_68 ) {
V_69 -= 10 ;
F_44 ( 10 ) ;
}
if ( V_69 <= 0 )
F_27 ( & V_40 -> V_46 , L_7
L_8 ,
F_40 ( V_41 + V_67 ) ) ;
}
#endif
F_43 ( ( T_2 ) ~ 0 , V_41 + V_74 ) ;
if ( V_64 & V_75 ) {
F_43 ( V_64 & F_42 , V_41 + V_67 ) ;
F_40 ( V_41 + V_67 ) ;
F_44 ( 50 ) ;
}
V_65 = F_40 ( V_41 + V_76 ) ;
F_43 ( V_77 , V_41 + V_73 ) ;
for ( V_66 = 30 ; V_66 > 0 ; -- V_66 ) {
if ( ( F_40 ( V_41 + V_73 ) & V_77 ) == 0 )
break;
F_25 ( 1 ) ;
}
F_43 ( V_65 , V_41 + V_76 ) ;
F_45 ( V_41 ) ;
}
static void T_4 F_46 ( struct V_37 * V_40 ,
void T_5 * V_78 ,
T_2 V_79 , T_1 V_80 )
{
int V_81 = 1 , V_82 = 0 ;
if ( V_40 -> V_83 == 0x8086 && V_40 -> V_84 == 0x283a ) {
if ( F_47 ( V_85 ) )
V_81 = 0 ;
}
if ( V_81 && ( V_79 & V_86 ) ) {
F_30 ( & V_40 -> V_46 , L_9 ) ;
#if 0
pci_read_config_dword(pdev, offset + EHCI_USBLEGCTLSTS, &val);
pci_write_config_dword(pdev, offset + EHCI_USBLEGCTLSTS,
val | EHCI_USBLEGCTLSTS_SOOE);
#endif
F_48 ( V_40 , V_80 + 3 , 1 ) ;
}
if ( V_81 ) {
int V_87 = 1000 ;
while ( ( V_79 & V_86 ) && ( V_87 > 0 ) ) {
V_82 = 1 ;
F_44 ( 10 ) ;
V_87 -= 10 ;
F_14 ( V_40 , V_80 , & V_79 ) ;
}
}
if ( V_79 & V_86 ) {
if ( V_81 )
F_27 ( & V_40 -> V_46 , L_10
L_8 , V_79 ) ;
F_48 ( V_40 , V_80 + 2 , 0 ) ;
}
F_17 ( V_40 , V_80 + V_88 , 0 ) ;
if ( V_82 )
F_43 ( 0 , V_78 + V_89 ) ;
}
static void T_4 F_49 ( struct V_37 * V_40 )
{
void T_5 * V_41 , * V_78 ;
T_2 V_90 , V_79 , V_23 ;
T_1 V_80 , V_91 ;
int V_69 , V_92 = 256 / 4 ;
if ( ! F_36 ( V_40 , 0 ) )
return;
V_41 = F_39 ( V_40 , 0 ) ;
if ( V_41 == NULL )
return;
V_91 = F_50 ( V_41 ) ;
V_78 = V_41 + V_91 ;
V_90 = F_40 ( V_41 + V_93 ) ;
V_80 = ( V_90 >> 8 ) & 0xff ;
while ( V_80 && -- V_92 ) {
F_14 ( V_40 , V_80 , & V_79 ) ;
switch ( V_79 & 0xff ) {
case 1 :
F_46 ( V_40 , V_78 , V_79 , V_80 ) ;
break;
case 0 :
V_79 = 0 ;
default:
F_27 ( & V_40 -> V_46 , L_11
L_12 , V_79 & 0xff ) ;
}
V_80 = ( V_79 >> 8 ) & 0xff ;
}
if ( ! V_92 )
F_51 ( V_18 , & V_40 -> V_46 , L_13 ) ;
V_23 = F_40 ( V_78 + V_94 ) ;
if ( ( V_23 & V_95 ) == 0 ) {
V_23 = F_40 ( V_78 + V_96 ) ;
V_23 &= ~ V_97 ;
F_43 ( V_23 , V_78 + V_96 ) ;
V_69 = 2000 ;
do {
F_43 ( 0x3f , V_78 + V_94 ) ;
F_25 ( 100 ) ;
V_69 -= 100 ;
V_23 = F_40 ( V_78 + V_94 ) ;
if ( ( V_23 == ~ ( T_2 ) 0 ) || ( V_23 & V_95 ) ) {
break;
}
} while ( V_69 > 0 );
}
F_43 ( 0 , V_78 + V_98 ) ;
F_43 ( 0x3f , V_78 + V_94 ) ;
F_45 ( V_41 ) ;
}
static int F_52 ( void T_5 * V_99 , T_2 V_58 , T_2 V_100 ,
int V_101 , int V_102 )
{
T_2 V_103 ;
do {
V_103 = F_40 ( V_99 ) ;
V_103 &= V_58 ;
if ( V_103 == V_100 )
return 0 ;
F_25 ( V_102 ) ;
V_101 -= V_102 ;
} while ( V_101 > 0 );
return - V_104 ;
}
bool F_53 ( struct V_37 * V_40 )
{
return V_40 -> V_105 == V_106 &&
V_40 -> V_83 == V_107 &&
V_40 -> V_84 == V_108 ;
}
void F_54 ( struct V_37 * V_109 )
{
T_2 V_110 ;
V_110 = 0xffffffff ;
F_17 ( V_109 , V_111 ,
F_55 ( V_110 ) ) ;
F_14 ( V_109 , V_111 ,
& V_110 ) ;
F_30 ( & V_109 -> V_46 , L_14
L_15 , V_110 ) ;
V_110 = 0xffffffff ;
F_17 ( V_109 , V_112 ,
F_55 ( V_110 ) ) ;
F_14 ( V_109 , V_112 ,
& V_110 ) ;
F_30 ( & V_109 -> V_46 , L_16
L_17 , V_110 ) ;
}
static void T_4 F_56 ( struct V_37 * V_40 )
{
void T_5 * V_41 ;
int V_113 ;
void T_5 * V_78 ;
T_2 V_23 ;
int V_114 ;
if ( ! F_36 ( V_40 , 0 ) )
return;
V_41 = F_57 ( F_35 ( V_40 , 0 ) ,
F_58 ( V_40 , 0 ) ) ;
if ( V_41 == NULL )
return;
V_113 = F_59 ( V_41 , V_115 ) ;
do {
if ( ! V_113 )
goto V_116;
V_23 = F_40 ( V_41 + V_113 ) ;
if ( F_60 ( V_23 ) == V_117 )
break;
V_113 = F_59 ( V_41 , V_113 ) ;
} while ( 1 );
if ( V_23 & V_118 ) {
F_43 ( V_23 | V_119 , V_41 + V_113 ) ;
V_114 = F_52 ( V_41 + V_113 , V_118 ,
0 , 5000 , 10 ) ;
if ( V_114 ) {
F_27 ( & V_40 -> V_46 , L_18
L_19 , V_23 ) ;
F_43 ( V_23 & ~ V_118 , V_41 + V_113 ) ;
}
}
F_43 ( V_120 ,
V_41 + V_113 + V_121 ) ;
if ( F_53 ( V_40 ) )
F_54 ( V_40 ) ;
V_116:
V_78 = V_41 + F_61 ( F_40 ( V_41 ) ) ;
V_114 = F_52 ( V_78 + V_122 , V_123 , 0 ,
5000 , 10 ) ;
if ( V_114 ) {
V_23 = F_40 ( V_78 + V_122 ) ;
F_27 ( & V_40 -> V_46 ,
L_20
L_21 , V_23 ) ;
}
V_23 = F_40 ( V_78 + V_124 ) ;
V_23 &= ~ ( V_125 | V_126 ) ;
F_43 ( V_23 , V_78 + V_124 ) ;
V_114 = F_52 ( V_78 + V_122 , V_127 , 1 ,
V_128 , 125 ) ;
if ( V_114 ) {
V_23 = F_40 ( V_78 + V_122 ) ;
F_27 ( & V_40 -> V_46 ,
L_22
L_21 , V_128 , V_23 ) ;
}
F_45 ( V_41 ) ;
}
static void T_4 F_62 ( struct V_37 * V_40 )
{
if ( V_40 -> V_105 == V_129 )
F_32 ( V_40 ) ;
else if ( V_40 -> V_105 == V_130 )
F_38 ( V_40 ) ;
else if ( V_40 -> V_105 == V_131 )
F_49 ( V_40 ) ;
else if ( V_40 -> V_105 == V_106 )
F_56 ( V_40 ) ;
}
