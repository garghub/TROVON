static inline void F_1 ( unsigned char V_1 [ 6 ] )
{
int V_2 ;
for( V_2 = 0 ; V_2 < 6 ; V_2 ++ )
V_1 [ V_2 ] = F_2 ( V_1 [ V_2 ] ) ;
}
static T_1 F_3 ( int V_3 , void * V_4 )
{
T_1 V_5 ;
unsigned long V_6 ;
F_4 ( V_6 ) ;
V_5 = F_5 ( V_3 , V_4 ) ;
F_6 ( V_6 ) ;
return V_5 ;
}
static int F_7 ( struct V_7 * V_8 )
{
int V_9 ;
V_9 = F_8 ( V_8 -> V_3 , F_5 , V_10 ,
L_1 , V_8 ) ;
if ( V_9 ) {
F_9 ( V_11 L_2 ,
V_8 -> V_12 , V_8 -> V_3 ) ;
goto V_13;
}
if ( V_8 -> V_3 == V_14 ) {
V_9 = F_8 ( V_15 , F_3 ,
V_10 , L_1 , V_8 ) ;
if ( V_9 ) {
F_9 ( V_11 L_2 ,
V_8 -> V_12 , V_15 ) ;
goto V_16;
}
}
V_9 = F_10 ( V_8 ) ;
if ( V_9 )
goto V_17;
return 0 ;
V_17:
if ( V_8 -> V_3 == V_14 )
F_11 ( V_15 , V_8 ) ;
V_16:
F_11 ( V_8 -> V_3 , V_8 ) ;
V_13:
return V_9 ;
}
static int F_12 ( struct V_7 * V_8 )
{
int V_13 ;
V_13 = F_13 ( V_8 ) ;
F_11 ( V_8 -> V_3 , V_8 ) ;
if ( V_8 -> V_3 == V_14 )
F_11 ( V_15 , V_8 ) ;
return V_13 ;
}
static int T_2 F_14 ( struct V_7 * V_8 )
{
struct V_18 * V_19 = F_15 ( V_8 ) ;
if ( ( V_19 -> V_20 = F_16 ( V_19 -> V_21 ,
V_22 * F_17 ( V_19 -> V_23 ) ,
& V_19 -> V_24 , V_25 ) ) == NULL ) {
F_9 ( V_11 L_3 ,
F_18 ( V_19 -> V_21 ) ) ;
return - V_26 ;
}
V_19 -> V_27 = V_19 -> V_20 ;
V_19 -> V_28 = V_19 -> V_27 + ( V_29
* F_17 ( V_19 -> V_23 ) ) ;
V_19 -> V_30 = V_19 -> V_28 + ( V_31 * V_32
* F_17 ( V_19 -> V_23 ) ) ;
V_19 -> V_33 = V_19 -> V_30 + ( V_34 * V_35
* F_17 ( V_19 -> V_23 ) ) ;
V_19 -> V_36 = V_19 -> V_24 ;
V_19 -> V_37 = V_19 -> V_36 + ( V_29
* F_17 ( V_19 -> V_23 ) ) ;
V_19 -> V_38 = V_19 -> V_37 + ( V_31 * V_32
* F_17 ( V_19 -> V_23 ) ) ;
V_19 -> V_39 = V_19 -> V_38 + ( V_34 * V_35
* F_17 ( V_19 -> V_23 ) ) ;
V_8 -> V_40 = & V_41 ;
V_8 -> V_42 = V_43 ;
F_19 ( V_44 , 0xffff ) ;
F_19 ( V_45 , 0xffff ) ;
F_19 ( V_46 , 0xffff ) ;
return 0 ;
}
static void T_2 F_20 ( struct V_7 * V_8 )
{
struct V_18 * V_19 = F_15 ( V_8 ) ;
const int V_47 = V_48 ;
unsigned short V_49 ;
if ( F_21 ( ( void * ) V_47 ) ) {
int V_2 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ )
V_8 -> V_50 [ V_2 ] = F_22 ( V_2 ) ;
if ( ! F_23 ( V_8 -> V_50 ) )
return;
F_1 ( V_8 -> V_50 ) ;
if ( ! F_23 ( V_8 -> V_50 ) )
return;
F_9 ( V_51 L_4
L_5 ) ;
} else {
F_9 ( V_51 L_6
L_7 ) ;
}
F_19 ( V_52 , V_53 ) ;
F_19 ( V_54 , 15 ) ;
V_49 = F_24 ( V_55 ) ;
V_8 -> V_50 [ 5 ] = V_49 >> 8 ;
V_8 -> V_50 [ 4 ] = V_49 & 0xff ;
V_49 = F_24 ( V_56 ) ;
V_8 -> V_50 [ 3 ] = V_49 >> 8 ;
V_8 -> V_50 [ 2 ] = V_49 & 0xff ;
V_49 = F_24 ( V_57 ) ;
V_8 -> V_50 [ 1 ] = V_49 >> 8 ;
V_8 -> V_50 [ 0 ] = V_49 & 0xff ;
if ( ! F_23 ( V_8 -> V_50 ) )
return;
F_9 ( V_51 L_8
L_9 ) ;
F_25 ( V_8 -> V_50 ) ;
}
static int T_2 F_26 ( struct V_7 * V_8 )
{
struct V_18 * V_19 = F_15 ( V_8 ) ;
int V_58 ;
int V_59 = 0 ;
if ( ! V_60 )
return - V_61 ;
F_9 ( V_62 L_10 ) ;
if ( V_63 -> V_64 == V_65 ||
V_63 -> V_64 == V_66 ||
V_63 -> V_64 == V_67 ||
V_63 -> V_64 == V_68 ) {
unsigned long V_6 ;
int V_69 ;
F_4 ( V_6 ) ;
V_69 = F_21 ( ( void * ) V_70 ) ;
F_6 ( V_6 ) ;
if ( ! V_69 ) {
F_9 ( L_11 ) ;
return - V_61 ;
}
V_59 = 1 ;
}
F_9 ( L_12 ) ;
V_8 -> V_71 = V_70 ;
if ( V_72 )
V_8 -> V_3 = V_14 ;
else
V_8 -> V_3 = V_15 ;
if ( ! V_73 ) {
F_9 ( V_62 L_13 , V_74 ) ;
V_73 = 1 ;
}
F_9 ( V_62 L_14 ,
F_18 ( V_19 -> V_21 ) , V_8 -> V_71 ) ;
if ( V_63 -> V_64 == V_75 ) {
V_19 -> V_76 = 0 ;
V_19 -> V_23 = V_77 ;
V_58 = F_24 ( V_78 ) ;
} else if ( V_59 ) {
V_19 -> V_76 = 2 ;
V_19 -> V_23 = V_77 ;
V_58 = F_24 ( V_78 ) ;
if ( V_58 == 0x0004 || V_58 == 0x0006 || V_58 == 0x0100 || V_58 == 0x0101 )
V_19 -> V_23 = V_79 ;
else {
V_19 -> V_23 = V_77 ;
V_19 -> V_76 = 0 ;
V_58 = F_24 ( V_78 ) ;
}
} else {
V_19 -> V_76 = 2 ;
V_19 -> V_23 = V_79 ;
V_58 = F_24 ( V_78 ) ;
}
F_9 ( V_62
L_15 ,
F_18 ( V_19 -> V_21 ) , V_58 , V_19 -> V_23 ? 32 : 16 , V_19 -> V_76 ) ;
#if 0
printk(KERN_INFO "%s: DCR: 0x%04x, DCR2: 0x%04x\n", dev_name(lp->device),
SONIC_READ(SONIC_DCR) & 0xffff, SONIC_READ(SONIC_DCR2) & 0xffff);
#endif
F_19 ( V_52 , V_53 ) ;
F_19 ( V_80 , V_81 | V_82 |
V_83 | V_84 |
( V_19 -> V_23 ? V_85 : 0 ) ) ;
F_19 ( V_86 , 0 ) ;
F_19 ( V_87 , 0 ) ;
F_19 ( V_88 , 0x7fff ) ;
F_20 ( V_8 ) ;
return F_14 ( V_8 ) ;
}
static int T_2 F_27 ( struct V_7 * V_8 ,
unsigned long V_47 ,
int V_89 )
{
int V_2 ;
for( V_2 = 0 ; V_2 < 6 ; V_2 ++ )
V_8 -> V_50 [ V_2 ] = F_22 ( V_2 ) ;
if ( V_89 != V_90 )
F_1 ( V_8 -> V_50 ) ;
return 0 ;
}
static int T_2 F_28 ( struct V_91 * V_92 )
{
if ( V_92 -> V_93 == V_94 &&
V_92 -> V_95 == V_96 )
return V_97 ;
if ( V_92 -> V_93 == V_98 &&
V_92 -> V_95 == V_99 ) {
if ( strstr ( V_92 -> V_100 -> V_12 , L_16 ) )
return V_101 ;
else
return V_102 ;
}
if ( V_92 -> V_93 == V_103 &&
V_92 -> V_95 == V_104 )
return V_90 ;
if ( V_92 -> V_93 == V_105 &&
V_92 -> V_95 == 0 ) {
return V_106 ;
}
return - 1 ;
}
static int T_2 F_29 ( struct V_7 * V_8 )
{
static int V_107 ;
struct V_91 * V_92 = NULL ;
struct V_18 * V_19 = F_15 ( V_8 ) ;
unsigned long V_71 , V_47 ;
T_3 V_108 ;
int V_89 = - 1 ;
int V_76 , V_23 ;
while ( ( V_92 = F_30 ( V_109 ,
V_110 , V_92 ) ) != NULL )
{
if ( V_107 & ( 1 << V_92 -> V_100 -> V_111 ) )
continue;
V_107 |= 1 << V_92 -> V_100 -> V_111 ;
if ( ( V_89 = F_28 ( V_92 ) ) != - 1 )
break;
}
if ( V_92 == NULL )
return - V_61 ;
switch ( V_89 ) {
case V_101 :
V_71 = V_92 -> V_100 -> V_112 + V_113 ;
V_47 = V_92 -> V_100 -> V_112 + V_114 ;
V_108 = V_81 | V_115 | V_83 |
V_84 ;
V_76 = 2 ;
V_23 = V_79 ;
break;
case V_102 :
V_71 = V_92 -> V_100 -> V_112 + V_116 ;
V_47 = V_92 -> V_100 -> V_112 + V_117 ;
V_108 = V_82 | V_83 | V_84 ;
V_76 = 0 ;
V_23 = V_79 ;
break;
case V_106 :
V_71 = V_92 -> V_100 -> V_112 + V_116 ;
V_47 = V_92 -> V_100 -> V_112 + V_117 ;
V_108 = V_81 | V_83 | V_84 |
V_118 | V_82 ;
V_76 = 0 ;
V_23 = V_77 ;
break;
case V_97 :
V_71 = V_92 -> V_100 -> V_112 + V_116 ;
V_47 = V_92 -> V_100 -> V_112 + V_119 ;
V_108 = V_83 | V_84 |
V_118 | V_82 ;
V_76 = 0 ;
V_23 = V_77 ;
break;
case V_90 :
V_71 = V_92 -> V_100 -> V_112 + V_120 ;
V_47 = V_92 -> V_100 -> V_112 + V_121 ;
V_108 = V_82 |
V_83 | V_84 | V_118 ;
V_76 = 0 ;
V_23 = V_77 ;
break;
default:
F_9 ( V_11 L_17 , V_89 ) ;
return - V_61 ;
}
V_8 -> V_71 = V_71 ;
V_19 -> V_76 = V_76 ;
V_19 -> V_23 = V_23 ;
V_8 -> V_3 = F_31 ( V_92 -> V_100 -> V_111 ) ;
if ( ! V_73 ) {
F_9 ( V_62 L_13 , V_74 ) ;
V_73 = 1 ;
}
F_9 ( V_62 L_18 ,
F_18 ( V_19 -> V_21 ) , V_92 -> V_100 -> V_12 , V_92 -> V_100 -> V_111 ) ;
F_9 ( V_62 L_15 ,
F_18 ( V_19 -> V_21 ) , F_24 ( V_78 ) , V_23 ? 32 : 16 , V_76 ) ;
#if 0
printk(KERN_INFO "%s: DCR: 0x%04x, DCR2: 0x%04x\n", dev_name(lp->device),
SONIC_READ(SONIC_DCR) & 0xffff, SONIC_READ(SONIC_DCR2) & 0xffff);
#endif
F_19 ( V_52 , V_53 ) ;
F_19 ( V_80 , V_108 | ( V_23 ? V_85 : 0 ) ) ;
F_19 ( V_86 , 0 ) ;
F_19 ( V_87 , 0 ) ;
F_19 ( V_88 , 0x7fff ) ;
if ( F_27 ( V_8 , V_47 , V_89 ) != 0 )
return - V_61 ;
return F_14 ( V_8 ) ;
}
static int T_2 F_32 ( struct V_122 * V_123 )
{
struct V_7 * V_8 ;
struct V_18 * V_19 ;
int V_13 ;
V_8 = F_33 ( sizeof( struct V_18 ) ) ;
if ( ! V_8 )
return - V_26 ;
V_19 = F_15 ( V_8 ) ;
V_19 -> V_21 = & V_123 -> V_8 ;
F_34 ( V_8 , & V_123 -> V_8 ) ;
F_35 ( V_123 , V_8 ) ;
V_13 = F_26 ( V_8 ) ;
if ( V_13 == 0 )
goto V_124;
if ( V_13 != - V_61 )
goto V_125;
V_13 = F_29 ( V_8 ) ;
if ( V_13 )
goto V_125;
V_124:
V_13 = F_36 ( V_8 ) ;
if ( V_13 )
goto V_125;
F_9 ( L_19 , V_8 -> V_12 , V_8 -> V_50 , V_8 -> V_3 ) ;
return 0 ;
V_125:
F_37 ( V_8 ) ;
return V_13 ;
}
static int T_4 F_38 ( struct V_122 * V_123 )
{
struct V_7 * V_8 = F_39 ( V_123 ) ;
struct V_18 * V_19 = F_15 ( V_8 ) ;
F_40 ( V_8 ) ;
F_41 ( V_19 -> V_21 , V_22 * F_17 ( V_19 -> V_23 ) ,
V_19 -> V_20 , V_19 -> V_24 ) ;
F_37 ( V_8 ) ;
return 0 ;
}
static int T_5 F_42 ( void )
{
return F_43 ( & V_126 ) ;
}
static void T_6 F_44 ( void )
{
F_45 ( & V_126 ) ;
}
