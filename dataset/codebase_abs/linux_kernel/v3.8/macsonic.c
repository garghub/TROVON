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
V_9 = F_8 ( V_8 -> V_3 , F_5 , 0 , L_1 , V_8 ) ;
if ( V_9 ) {
F_9 ( V_10 L_2 ,
V_8 -> V_11 , V_8 -> V_3 ) ;
goto V_12;
}
if ( V_8 -> V_3 == V_13 ) {
V_9 = F_8 ( V_14 , F_3 , 0 ,
L_1 , V_8 ) ;
if ( V_9 ) {
F_9 ( V_10 L_2 ,
V_8 -> V_11 , V_14 ) ;
goto V_15;
}
}
V_9 = F_10 ( V_8 ) ;
if ( V_9 )
goto V_16;
return 0 ;
V_16:
if ( V_8 -> V_3 == V_13 )
F_11 ( V_14 , V_8 ) ;
V_15:
F_11 ( V_8 -> V_3 , V_8 ) ;
V_12:
return V_9 ;
}
static int F_12 ( struct V_7 * V_8 )
{
int V_12 ;
V_12 = F_13 ( V_8 ) ;
F_11 ( V_8 -> V_3 , V_8 ) ;
if ( V_8 -> V_3 == V_13 )
F_11 ( V_14 , V_8 ) ;
return V_12 ;
}
static int F_14 ( struct V_7 * V_8 )
{
struct V_17 * V_18 = F_15 ( V_8 ) ;
if ( ( V_18 -> V_19 = F_16 ( V_18 -> V_20 ,
V_21 * F_17 ( V_18 -> V_22 ) ,
& V_18 -> V_23 , V_24 ) ) == NULL ) {
F_9 ( V_10 L_3 ,
F_18 ( V_18 -> V_20 ) ) ;
return - V_25 ;
}
V_18 -> V_26 = V_18 -> V_19 ;
V_18 -> V_27 = V_18 -> V_26 + ( V_28
* F_17 ( V_18 -> V_22 ) ) ;
V_18 -> V_29 = V_18 -> V_27 + ( V_30 * V_31
* F_17 ( V_18 -> V_22 ) ) ;
V_18 -> V_32 = V_18 -> V_29 + ( V_33 * V_34
* F_17 ( V_18 -> V_22 ) ) ;
V_18 -> V_35 = V_18 -> V_23 ;
V_18 -> V_36 = V_18 -> V_35 + ( V_28
* F_17 ( V_18 -> V_22 ) ) ;
V_18 -> V_37 = V_18 -> V_36 + ( V_30 * V_31
* F_17 ( V_18 -> V_22 ) ) ;
V_18 -> V_38 = V_18 -> V_37 + ( V_33 * V_34
* F_17 ( V_18 -> V_22 ) ) ;
V_8 -> V_39 = & V_40 ;
V_8 -> V_41 = V_42 ;
F_19 ( V_43 , 0xffff ) ;
F_19 ( V_44 , 0xffff ) ;
F_19 ( V_45 , 0xffff ) ;
return 0 ;
}
static void F_20 ( struct V_7 * V_8 )
{
struct V_17 * V_18 = F_15 ( V_8 ) ;
const int V_46 = V_47 ;
unsigned short V_48 ;
if ( F_21 ( ( void * ) V_46 ) ) {
int V_2 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ )
V_8 -> V_49 [ V_2 ] = F_22 ( V_2 ) ;
if ( ! F_23 ( V_8 -> V_49 ) )
return;
F_1 ( V_8 -> V_49 ) ;
if ( ! F_23 ( V_8 -> V_49 ) )
return;
F_9 ( V_50 L_4
L_5 ) ;
} else {
F_9 ( V_50 L_6
L_7 ) ;
}
F_19 ( V_51 , V_52 ) ;
F_19 ( V_53 , 15 ) ;
V_48 = F_24 ( V_54 ) ;
V_8 -> V_49 [ 5 ] = V_48 >> 8 ;
V_8 -> V_49 [ 4 ] = V_48 & 0xff ;
V_48 = F_24 ( V_55 ) ;
V_8 -> V_49 [ 3 ] = V_48 >> 8 ;
V_8 -> V_49 [ 2 ] = V_48 & 0xff ;
V_48 = F_24 ( V_56 ) ;
V_8 -> V_49 [ 1 ] = V_48 >> 8 ;
V_8 -> V_49 [ 0 ] = V_48 & 0xff ;
if ( ! F_23 ( V_8 -> V_49 ) )
return;
F_9 ( V_50 L_8
L_9 ) ;
F_25 ( V_8 ) ;
}
static int F_26 ( struct V_7 * V_8 )
{
struct V_17 * V_18 = F_15 ( V_8 ) ;
int V_57 ;
int V_58 = 0 ;
if ( ! V_59 )
return - V_60 ;
F_9 ( V_61 L_10 ) ;
if ( V_62 -> V_63 == V_64 ||
V_62 -> V_63 == V_65 ||
V_62 -> V_63 == V_66 ||
V_62 -> V_63 == V_67 ) {
unsigned long V_6 ;
int V_68 ;
F_4 ( V_6 ) ;
V_68 = F_21 ( ( void * ) V_69 ) ;
F_6 ( V_6 ) ;
if ( ! V_68 ) {
F_9 ( L_11 ) ;
return - V_60 ;
}
V_58 = 1 ;
}
F_9 ( L_12 ) ;
V_8 -> V_70 = V_69 ;
if ( V_71 )
V_8 -> V_3 = V_13 ;
else
V_8 -> V_3 = V_14 ;
if ( ! V_72 ) {
F_9 ( V_61 L_13 , V_73 ) ;
V_72 = 1 ;
}
F_9 ( V_61 L_14 ,
F_18 ( V_18 -> V_20 ) , V_8 -> V_70 ) ;
if ( V_62 -> V_63 == V_74 ) {
V_18 -> V_75 = 0 ;
V_18 -> V_22 = V_76 ;
V_57 = F_24 ( V_77 ) ;
} else if ( V_58 ) {
V_18 -> V_75 = 2 ;
V_18 -> V_22 = V_76 ;
V_57 = F_24 ( V_77 ) ;
if ( V_57 == 0x0004 || V_57 == 0x0006 || V_57 == 0x0100 || V_57 == 0x0101 )
V_18 -> V_22 = V_78 ;
else {
V_18 -> V_22 = V_76 ;
V_18 -> V_75 = 0 ;
V_57 = F_24 ( V_77 ) ;
}
} else {
V_18 -> V_75 = 2 ;
V_18 -> V_22 = V_78 ;
V_57 = F_24 ( V_77 ) ;
}
F_9 ( V_61
L_15 ,
F_18 ( V_18 -> V_20 ) , V_57 , V_18 -> V_22 ? 32 : 16 , V_18 -> V_75 ) ;
#if 0
printk(KERN_INFO "%s: DCR: 0x%04x, DCR2: 0x%04x\n", dev_name(lp->device),
SONIC_READ(SONIC_DCR) & 0xffff, SONIC_READ(SONIC_DCR2) & 0xffff);
#endif
F_19 ( V_51 , V_52 ) ;
F_19 ( V_79 , V_80 | V_81 |
V_82 | V_83 |
( V_18 -> V_22 ? V_84 : 0 ) ) ;
F_19 ( V_85 , 0 ) ;
F_19 ( V_86 , 0 ) ;
F_19 ( V_87 , 0x7fff ) ;
F_20 ( V_8 ) ;
return F_14 ( V_8 ) ;
}
static int F_27 ( struct V_7 * V_8 ,
unsigned long V_46 , int V_88 )
{
int V_2 ;
for( V_2 = 0 ; V_2 < 6 ; V_2 ++ )
V_8 -> V_49 [ V_2 ] = F_22 ( V_2 ) ;
if ( V_88 != V_89 )
F_1 ( V_8 -> V_49 ) ;
return 0 ;
}
static int F_28 ( struct V_90 * V_91 )
{
if ( V_91 -> V_92 == V_93 &&
V_91 -> V_94 == V_95 )
return V_96 ;
if ( V_91 -> V_92 == V_97 &&
V_91 -> V_94 == V_98 ) {
if ( strstr ( V_91 -> V_99 -> V_11 , L_16 ) )
return V_100 ;
else
return V_101 ;
}
if ( V_91 -> V_92 == V_102 &&
V_91 -> V_94 == V_103 )
return V_89 ;
if ( V_91 -> V_92 == V_104 &&
V_91 -> V_94 == 0 ) {
return V_105 ;
}
return - 1 ;
}
static int F_29 ( struct V_7 * V_8 )
{
static int V_106 ;
struct V_90 * V_91 = NULL ;
struct V_17 * V_18 = F_15 ( V_8 ) ;
unsigned long V_70 , V_46 ;
T_2 V_107 ;
int V_88 = - 1 ;
int V_75 , V_22 ;
while ( ( V_91 = F_30 ( V_108 ,
V_109 , V_91 ) ) != NULL )
{
if ( V_106 & ( 1 << V_91 -> V_99 -> V_110 ) )
continue;
V_106 |= 1 << V_91 -> V_99 -> V_110 ;
if ( ( V_88 = F_28 ( V_91 ) ) != - 1 )
break;
}
if ( V_91 == NULL )
return - V_60 ;
switch ( V_88 ) {
case V_100 :
V_70 = V_91 -> V_99 -> V_111 + V_112 ;
V_46 = V_91 -> V_99 -> V_111 + V_113 ;
V_107 = V_80 | V_114 | V_82 |
V_83 ;
V_75 = 2 ;
V_22 = V_78 ;
break;
case V_101 :
V_70 = V_91 -> V_99 -> V_111 + V_115 ;
V_46 = V_91 -> V_99 -> V_111 + V_116 ;
V_107 = V_81 | V_82 | V_83 ;
V_75 = 0 ;
V_22 = V_78 ;
break;
case V_105 :
V_70 = V_91 -> V_99 -> V_111 + V_115 ;
V_46 = V_91 -> V_99 -> V_111 + V_116 ;
V_107 = V_80 | V_82 | V_83 |
V_117 | V_81 ;
V_75 = 0 ;
V_22 = V_76 ;
break;
case V_96 :
V_70 = V_91 -> V_99 -> V_111 + V_115 ;
V_46 = V_91 -> V_99 -> V_111 + V_118 ;
V_107 = V_82 | V_83 |
V_117 | V_81 ;
V_75 = 0 ;
V_22 = V_76 ;
break;
case V_89 :
V_70 = V_91 -> V_99 -> V_111 + V_119 ;
V_46 = V_91 -> V_99 -> V_111 + V_120 ;
V_107 = V_81 |
V_82 | V_83 | V_117 ;
V_75 = 0 ;
V_22 = V_76 ;
break;
default:
F_9 ( V_10 L_17 , V_88 ) ;
return - V_60 ;
}
V_8 -> V_70 = V_70 ;
V_18 -> V_75 = V_75 ;
V_18 -> V_22 = V_22 ;
V_8 -> V_3 = F_31 ( V_91 -> V_99 -> V_110 ) ;
if ( ! V_72 ) {
F_9 ( V_61 L_13 , V_73 ) ;
V_72 = 1 ;
}
F_9 ( V_61 L_18 ,
F_18 ( V_18 -> V_20 ) , V_91 -> V_99 -> V_11 , V_91 -> V_99 -> V_110 ) ;
F_9 ( V_61 L_15 ,
F_18 ( V_18 -> V_20 ) , F_24 ( V_77 ) , V_22 ? 32 : 16 , V_75 ) ;
#if 0
printk(KERN_INFO "%s: DCR: 0x%04x, DCR2: 0x%04x\n", dev_name(lp->device),
SONIC_READ(SONIC_DCR) & 0xffff, SONIC_READ(SONIC_DCR2) & 0xffff);
#endif
F_19 ( V_51 , V_52 ) ;
F_19 ( V_79 , V_107 | ( V_22 ? V_84 : 0 ) ) ;
F_19 ( V_85 , 0 ) ;
F_19 ( V_86 , 0 ) ;
F_19 ( V_87 , 0x7fff ) ;
if ( F_27 ( V_8 , V_46 , V_88 ) != 0 )
return - V_60 ;
return F_14 ( V_8 ) ;
}
static int F_32 ( struct V_121 * V_122 )
{
struct V_7 * V_8 ;
struct V_17 * V_18 ;
int V_12 ;
V_8 = F_33 ( sizeof( struct V_17 ) ) ;
if ( ! V_8 )
return - V_25 ;
V_18 = F_15 ( V_8 ) ;
V_18 -> V_20 = & V_122 -> V_8 ;
F_34 ( V_8 , & V_122 -> V_8 ) ;
F_35 ( V_122 , V_8 ) ;
V_12 = F_26 ( V_8 ) ;
if ( V_12 == 0 )
goto V_123;
if ( V_12 != - V_60 )
goto V_124;
V_12 = F_29 ( V_8 ) ;
if ( V_12 )
goto V_124;
V_123:
V_12 = F_36 ( V_8 ) ;
if ( V_12 )
goto V_124;
F_9 ( L_19 , V_8 -> V_11 , V_8 -> V_49 , V_8 -> V_3 ) ;
return 0 ;
V_124:
F_37 ( V_8 ) ;
return V_12 ;
}
static int F_38 ( struct V_121 * V_122 )
{
struct V_7 * V_8 = F_39 ( V_122 ) ;
struct V_17 * V_18 = F_15 ( V_8 ) ;
F_40 ( V_8 ) ;
F_41 ( V_18 -> V_20 , V_21 * F_17 ( V_18 -> V_22 ) ,
V_18 -> V_19 , V_18 -> V_23 ) ;
F_37 ( V_8 ) ;
return 0 ;
}
