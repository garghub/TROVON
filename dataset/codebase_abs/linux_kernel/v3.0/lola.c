static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int V_5 ,
unsigned int V_6 )
{
unsigned long V_7 ;
int V_8 = - V_9 ;
V_2 -> V_10 = V_3 ;
V_2 -> V_11 = V_4 ;
V_2 -> V_12 = V_5 ;
V_2 -> V_13 = V_6 ;
V_5 |= ( V_3 << 20 ) | ( V_4 << 8 ) ;
F_2 ( & V_2 -> V_14 , V_7 ) ;
if ( V_2 -> V_15 . V_16 < V_17 - 1 ) {
unsigned int V_18 = V_2 -> V_19 . V_18 + 1 ;
V_18 %= V_17 ;
V_2 -> V_19 . V_18 = V_18 ;
V_2 -> V_19 . V_20 [ V_18 * 2 ] = F_3 ( V_5 ) ;
V_2 -> V_19 . V_20 [ V_18 * 2 + 1 ] = F_3 ( V_6 ) ;
F_4 ( V_2 , V_21 , V_22 , V_18 ) ;
V_2 -> V_15 . V_16 ++ ;
F_5 () ;
V_8 = 0 ;
}
F_6 ( & V_2 -> V_14 , V_7 ) ;
return V_8 ;
}
static void F_7 ( struct V_1 * V_2 , unsigned int V_23 ,
unsigned int V_24 )
{
F_8 ( V_2 , V_23 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned int V_25 , V_18 ;
T_1 V_23 , V_24 ;
V_18 = F_10 ( V_2 , V_21 , V_26 ) ;
if ( V_18 == V_2 -> V_15 . V_18 )
return;
V_2 -> V_15 . V_18 = V_18 ;
while ( V_2 -> V_15 . V_25 != V_18 ) {
V_2 -> V_15 . V_25 ++ ;
V_2 -> V_15 . V_25 %= V_17 ;
V_25 = V_2 -> V_15 . V_25 << 1 ;
V_24 = F_11 ( V_2 -> V_15 . V_20 [ V_25 + 1 ] ) ;
V_23 = F_11 ( V_2 -> V_15 . V_20 [ V_25 ] ) ;
if ( V_24 & V_27 )
F_7 ( V_2 , V_23 , V_24 ) ;
else if ( V_2 -> V_15 . V_16 ) {
V_2 -> V_23 = V_23 ;
V_2 -> V_24 = V_24 ;
F_5 () ;
V_2 -> V_15 . V_16 -- ;
}
}
}
static int F_12 ( struct V_1 * V_2 , unsigned int * V_28 ,
unsigned int * V_29 )
{
unsigned long V_30 ;
V_31:
V_30 = V_32 + F_13 ( 1000 ) ;
for (; ; ) {
if ( V_2 -> V_33 ) {
F_14 ( & V_2 -> V_14 ) ;
F_9 ( V_2 ) ;
F_15 ( & V_2 -> V_14 ) ;
}
if ( ! V_2 -> V_15 . V_16 ) {
* V_28 = V_2 -> V_23 ;
if ( V_29 )
* V_29 = V_2 -> V_24 ;
F_16 ( L_1 ,
V_2 -> V_23 , V_2 -> V_24 ) ;
if ( V_2 -> V_24 & V_34 ) {
F_17 (KERN_WARNING SFX L_2
L_3 ,
chip->last_cmd_nid,
chip->last_verb, chip->last_data,
chip->last_extdata) ;
return - V_9 ;
}
return 0 ;
}
if ( F_18 ( V_32 , V_30 ) )
break;
F_19 ( 20 ) ;
F_20 () ;
}
F_17 (KERN_WARNING SFX L_4 ) ;
if ( ! V_2 -> V_33 ) {
F_17 (KERN_WARNING SFX L_5 ) ;
V_2 -> V_33 = 1 ;
goto V_31;
}
return - V_9 ;
}
int F_21 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 , unsigned int V_6 )
{
F_16 ( L_6 ,
V_3 , V_4 , V_5 , V_6 ) ;
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
int F_22 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 , unsigned int V_6 ,
unsigned int * V_28 , unsigned int * V_29 )
{
int V_35 ;
F_16 ( L_7 ,
V_3 , V_4 , V_5 , V_6 ) ;
V_35 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_12 ( V_2 , V_28 , V_29 ) ;
return V_35 ;
}
int F_23 ( struct V_1 * V_2 )
{
unsigned int V_36 ;
return F_12 ( V_2 , & V_36 , NULL ) ;
}
static T_2 F_24 ( int V_37 , void * V_38 )
{
struct V_1 * V_2 = V_38 ;
unsigned int V_39 , V_40 , V_41 , V_42 ;
int V_43 = 0 ;
int V_44 ;
V_39 = V_40 = V_41 = V_42 = 0 ;
F_25 ( & V_2 -> V_14 ) ;
for (; ; ) {
unsigned int V_45 , V_46 , V_47 ;
unsigned int V_48 ;
V_45 = F_26 ( V_2 , V_49 , V_50 ) ;
if ( ! V_45 || V_45 == - 1 )
break;
V_46 = F_26 ( V_2 , V_49 , V_51 ) ;
V_47 = F_26 ( V_2 , V_49 , V_52 ) ;
for ( V_44 = 0 ; V_46 && V_44 < V_2 -> V_53 [ V_54 ] . V_55 ; V_44 ++ ) {
if ( ! ( V_46 & ( 1 << V_44 ) ) )
continue;
V_46 &= ~ ( 1 << V_44 ) ;
V_48 = F_27 ( V_2 , V_44 , V_56 ) ;
if ( V_48 & V_57 )
V_41 |= ( 1 << V_44 ) ;
if ( V_48 & V_58 )
V_39 |= ( 1 << V_44 ) ;
F_28 ( V_2 , V_44 , V_56 , V_48 ) ;
}
for ( V_44 = 0 ; V_47 && V_44 < V_2 -> V_53 [ V_59 ] . V_55 ; V_44 ++ ) {
if ( ! ( V_47 & ( 1 << V_44 ) ) )
continue;
V_47 &= ~ ( 1 << V_44 ) ;
V_48 = F_27 ( V_2 , V_44 + V_60 , V_56 ) ;
if ( V_48 & V_57 )
V_42 |= ( 1 << V_44 ) ;
if ( V_48 & V_58 )
V_40 |= ( 1 << V_44 ) ;
F_28 ( V_2 , V_44 + V_60 , V_56 , V_48 ) ;
}
if ( V_45 & V_61 ) {
unsigned char V_62 ;
V_62 = F_29 ( V_2 , V_21 , V_63 ) ;
V_62 &= V_64 ;
if ( V_62 )
F_30 ( V_2 , V_21 , V_63 , V_62 ) ;
V_62 = F_29 ( V_2 , V_21 , V_65 ) ;
V_62 &= V_66 ;
if ( V_62 )
F_30 ( V_2 , V_21 , V_65 , V_62 ) ;
F_9 ( V_2 ) ;
}
if ( V_45 & ( V_67 | V_68 ) ) {
F_31 ( V_2 , V_49 , V_50 ,
( V_45 & ( V_67 | V_68 ) ) ) ;
}
V_43 = 1 ;
}
F_32 ( & V_2 -> V_14 ) ;
F_33 ( V_2 , & V_2 -> V_53 [ V_54 ] , V_39 ) ;
F_33 ( V_2 , & V_2 -> V_53 [ V_59 ] , V_40 ) ;
return F_34 ( V_43 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
unsigned int V_69 = F_26 ( V_2 , V_21 , V_70 ) ;
unsigned long V_71 ;
if ( V_69 ) {
F_31 ( V_2 , V_49 , V_72 , 0 ) ;
return 0 ;
}
V_2 -> V_73 = 1 ;
F_31 ( V_2 , V_21 , V_70 , V_74 ) ;
V_71 = V_32 + F_13 ( 200 ) ;
do {
F_36 ( 1 ) ;
V_69 = F_26 ( V_2 , V_21 , V_70 ) ;
if ( V_69 )
break;
} while ( F_37 ( V_32 , V_71 ) );
if ( ! V_69 ) {
F_17 (KERN_ERR SFX L_8 ) ;
return - V_9 ;
}
return 0 ;
}
static void F_38 ( struct V_1 * V_2 )
{
unsigned int V_28 ;
V_28 = ( 1 << V_2 -> V_53 [ V_59 ] . V_55 ) - 1 ;
F_31 ( V_2 , V_49 , V_75 , V_28 ) ;
V_28 = ( 1 << V_2 -> V_53 [ V_54 ] . V_55 ) - 1 ;
F_31 ( V_2 , V_49 , V_76 , V_28 ) ;
V_28 = V_77 | V_61 | V_67 |
V_68 ;
F_31 ( V_2 , V_49 , V_78 , V_28 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_31 ( V_2 , V_49 , V_78 , 0 ) ;
F_31 ( V_2 , V_49 , V_76 , 0 ) ;
F_31 ( V_2 , V_49 , V_75 , 0 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_35 ;
unsigned char V_36 ;
unsigned long V_71 ;
V_35 = F_41 ( V_79 ,
F_42 ( V_2 -> V_80 ) ,
V_81 , & V_2 -> V_82 ) ;
if ( V_35 < 0 )
return V_35 ;
V_2 -> V_19 . V_83 = V_2 -> V_82 . V_83 ;
V_2 -> V_19 . V_20 = ( T_1 * ) V_2 -> V_82 . V_84 ;
V_2 -> V_15 . V_83 = V_2 -> V_82 . V_83 + 2048 ;
V_2 -> V_15 . V_20 = ( T_1 * ) ( V_2 -> V_82 . V_84 + 2048 ) ;
F_30 ( V_2 , V_21 , V_85 , 0 ) ;
F_30 ( V_2 , V_21 , V_86 , 0 ) ;
V_71 = V_32 + F_13 ( 200 ) ;
do {
if ( ! F_29 ( V_2 , V_21 , V_85 ) &&
! F_29 ( V_2 , V_21 , V_86 ) )
break;
F_36 ( 1 ) ;
} while ( F_37 ( V_32 , V_71 ) );
F_31 ( V_2 , V_21 , V_87 , ( T_1 ) V_2 -> V_19 . V_83 ) ;
F_31 ( V_2 , V_21 , V_88 , F_43 ( V_2 -> V_19 . V_83 ) ) ;
F_30 ( V_2 , V_21 , V_89 , 0x02 ) ;
F_4 ( V_2 , V_21 , V_22 , 0 ) ;
F_4 ( V_2 , V_21 , V_90 , V_91 ) ;
F_30 ( V_2 , V_21 , V_86 , V_92 ) ;
V_36 = F_29 ( V_2 , V_21 , V_65 ) & V_66 ;
if ( V_36 )
F_30 ( V_2 , V_21 , V_65 , V_36 ) ;
V_2 -> V_19 . V_18 = 0 ;
F_31 ( V_2 , V_21 , V_93 , ( T_1 ) V_2 -> V_15 . V_83 ) ;
F_31 ( V_2 , V_21 , V_94 , F_43 ( V_2 -> V_15 . V_83 ) ) ;
F_30 ( V_2 , V_21 , V_95 , 0x02 ) ;
F_4 ( V_2 , V_21 , V_26 , V_91 ) ;
F_4 ( V_2 , V_21 , V_96 , 1 ) ;
F_30 ( V_2 , V_21 , V_85 , V_92 | V_97 ) ;
V_36 = F_29 ( V_2 , V_21 , V_63 ) & V_64 ;
if ( V_36 )
F_30 ( V_2 , V_21 , V_63 , V_36 ) ;
V_2 -> V_15 . V_25 = V_2 -> V_15 . V_16 = 0 ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_30 ( V_2 , V_21 , V_85 , 0 ) ;
F_30 ( V_2 , V_21 , V_86 , 0 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_46 ( V_2 , V_2 -> V_98 , true ) ;
F_47 ( V_2 , V_2 -> clock . V_99 ) ;
F_48 ( V_2 ) ;
F_49 ( V_2 , V_54 , false ) ;
F_50 ( V_2 , V_2 -> V_100 , false ) ;
F_49 ( V_2 , V_59 , false ) ;
}
static int T_3 F_51 ( struct V_1 * V_2 )
{
unsigned int V_28 ;
int V_3 , V_35 ;
V_35 = F_52 ( V_2 , 0 , V_101 , & V_28 ) ;
if ( V_35 < 0 ) {
F_17 (KERN_ERR SFX L_9 ) ;
return V_35 ;
}
V_28 >>= 16 ;
if ( V_28 != 0x1369 ) {
F_17 (KERN_ERR SFX L_10 , val) ;
return - V_102 ;
}
V_35 = F_52 ( V_2 , 1 , V_103 , & V_28 ) ;
if ( V_35 < 0 ) {
F_17 (KERN_ERR SFX L_11 , nid) ;
return V_35 ;
}
if ( V_28 != 1 ) {
F_17 (KERN_ERR SFX L_12 , val) ;
return - V_102 ;
}
V_35 = F_52 ( V_2 , 1 , V_104 , & V_28 ) ;
if ( V_35 < 0 ) {
F_17 (KERN_ERR SFX L_13 ) ;
return V_35 ;
}
V_2 -> V_105 = V_28 ;
V_2 -> V_106 [ V_54 ] . V_107 = F_53 ( V_2 -> V_105 ) ;
V_2 -> V_106 [ V_59 ] . V_107 = F_54 ( V_2 -> V_105 ) ;
F_55 ( V_108 L_14 ,
V_2 -> V_105 ,
V_2 -> V_106 [ V_54 ] . V_107 , V_2 -> V_106 [ V_59 ] . V_107 ) ;
if ( V_2 -> V_106 [ V_54 ] . V_107 > V_109 ||
V_2 -> V_106 [ V_59 ] . V_107 > V_109 ) {
F_17 (KERN_ERR SFX L_15 , val) ;
return - V_102 ;
}
V_3 = 0x02 ;
V_35 = F_56 ( V_2 , V_54 , & V_3 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_56 ( V_2 , V_59 , & V_3 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_57 ( V_2 , V_54 , & V_3 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_57 ( V_2 , V_59 , & V_3 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( F_58 ( V_2 -> V_105 ) ) {
V_35 = F_59 ( V_2 , V_3 ) ;
if ( V_35 < 0 )
return V_35 ;
V_3 ++ ;
}
if ( F_60 ( V_2 -> V_105 ) ) {
V_35 = F_61 ( V_2 , V_3 ) ;
if ( V_35 < 0 )
return V_35 ;
V_3 ++ ;
}
V_35 = F_48 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( ! V_2 -> V_73 ) {
F_45 ( V_2 ) ;
V_2 -> V_73 = 1 ;
} else {
if ( V_2 -> V_98 != V_110 )
F_46 ( V_2 , V_2 -> V_98 , true ) ;
}
return 0 ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_44 ( V_2 ) ;
F_39 ( V_2 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
if ( V_2 -> V_111 )
F_62 ( V_2 ) ;
F_64 ( V_2 ) ;
F_65 ( V_2 ) ;
if ( V_2 -> V_37 >= 0 )
F_66 ( V_2 -> V_37 , ( void * ) V_2 ) ;
if ( V_2 -> V_112 [ 0 ] . V_113 )
F_67 ( V_2 -> V_112 [ 0 ] . V_113 ) ;
if ( V_2 -> V_112 [ 1 ] . V_113 )
F_67 ( V_2 -> V_112 [ 1 ] . V_113 ) ;
if ( V_2 -> V_82 . V_84 )
F_68 ( & V_2 -> V_82 ) ;
F_69 ( V_2 -> V_80 ) ;
F_70 ( V_2 -> V_80 ) ;
F_71 ( V_2 ) ;
}
static int F_72 ( struct V_114 * V_115 )
{
F_63 ( V_115 -> V_116 ) ;
return 0 ;
}
static int T_3 F_73 ( struct V_117 * V_118 , struct V_119 * V_80 ,
int V_120 , struct V_1 * * V_121 )
{
struct V_1 * V_2 ;
int V_35 ;
unsigned int V_122 ;
static struct V_123 V_124 = {
. V_125 = F_72 ,
} ;
* V_121 = NULL ;
V_35 = F_74 ( V_80 ) ;
if ( V_35 < 0 )
return V_35 ;
V_2 = F_75 ( sizeof( * V_2 ) , V_126 ) ;
if ( ! V_2 ) {
F_76 (KERN_ERR SFX L_16 ) ;
F_70 ( V_80 ) ;
return - V_127 ;
}
F_77 ( & V_2 -> V_14 ) ;
F_78 ( & V_2 -> V_128 ) ;
V_2 -> V_118 = V_118 ;
V_2 -> V_80 = V_80 ;
V_2 -> V_37 = - 1 ;
V_2 -> V_98 = V_98 [ V_120 ] ;
switch ( V_2 -> V_98 ) {
case 8 :
V_2 -> V_129 = 48000 ;
break;
case 16 :
V_2 -> V_129 = 96000 ;
break;
case 32 :
V_2 -> V_129 = 192000 ;
break;
default:
F_76 (KERN_WARNING SFX
L_17 ,
chip->granularity, LOLA_GRANULARITY_MAX) ;
V_2 -> V_98 = V_130 ;
V_2 -> V_129 = 192000 ;
break;
}
V_2 -> V_131 = V_131 [ V_120 ] ;
if ( V_2 -> V_131 > V_2 -> V_129 ) {
F_76 (KERN_WARNING SFX
L_18 ,
chip->sample_rate_min) ;
V_2 -> V_131 = 16000 ;
}
V_35 = F_79 ( V_80 , V_132 ) ;
if ( V_35 < 0 ) {
F_71 ( V_2 ) ;
F_70 ( V_80 ) ;
return V_35 ;
}
V_2 -> V_112 [ 0 ] . V_83 = F_80 ( V_80 , 0 ) ;
V_2 -> V_112 [ 0 ] . V_113 = F_81 ( V_80 , 0 ) ;
V_2 -> V_112 [ 1 ] . V_83 = F_80 ( V_80 , 2 ) ;
V_2 -> V_112 [ 1 ] . V_113 = F_81 ( V_80 , 2 ) ;
if ( ! V_2 -> V_112 [ 0 ] . V_113 || ! V_2 -> V_112 [ 1 ] . V_113 ) {
F_76 (KERN_ERR SFX L_19 ) ;
V_35 = - V_133 ;
goto V_134;
}
F_82 ( V_80 ) ;
V_35 = F_35 ( V_2 ) ;
if ( V_35 < 0 )
goto V_134;
if ( F_83 ( V_80 -> V_37 , F_24 , V_135 ,
V_132 , V_2 ) ) {
F_17 (KERN_ERR SFX L_20 , pci->irq) ;
V_35 = - V_136 ;
goto V_134;
}
V_2 -> V_37 = V_80 -> V_37 ;
F_84 ( V_2 -> V_37 ) ;
V_122 = F_26 ( V_2 , V_49 , V_137 ) ;
V_2 -> V_53 [ V_54 ] . V_55 = ( V_122 >> 0 ) & 0x3ff ;
V_2 -> V_53 [ V_59 ] . V_55 = ( V_122 >> 10 ) & 0x3ff ;
V_2 -> V_138 = ( V_122 >> 24 ) & 0xff ;
F_55 ( V_108 L_21 ,
V_2 -> V_53 [ V_54 ] . V_55 , V_2 -> V_53 [ V_59 ] . V_55 ,
V_2 -> V_138 ) ;
if ( V_2 -> V_53 [ V_54 ] . V_55 > V_60 ||
V_2 -> V_53 [ V_59 ] . V_55 > V_139 ||
( ! V_2 -> V_53 [ V_54 ] . V_55 &&
! V_2 -> V_53 [ V_59 ] . V_55 ) ) {
F_17 (KERN_ERR SFX L_22 , dever) ;
V_35 = - V_102 ;
goto V_134;
}
V_35 = F_40 ( V_2 ) ;
if ( V_35 < 0 )
goto V_134;
V_35 = F_85 ( V_118 , V_140 , V_2 , & V_124 ) ;
if ( V_35 < 0 ) {
F_76 (KERN_ERR SFX L_23 ) ;
goto V_134;
}
strcpy ( V_118 -> V_141 , L_24 ) ;
F_86 ( V_118 -> V_142 , L_25 , sizeof( V_118 -> V_142 ) ) ;
snprintf ( V_118 -> V_143 , sizeof( V_118 -> V_143 ) ,
L_26 ,
V_118 -> V_142 , V_2 -> V_112 [ 0 ] . V_83 , V_2 -> V_37 ) ;
strcpy ( V_118 -> V_144 , V_118 -> V_142 ) ;
F_38 ( V_2 ) ;
V_2 -> V_111 = 1 ;
* V_121 = V_2 ;
return 0 ;
V_134:
F_63 ( V_2 ) ;
return V_35 ;
}
static int T_3 F_87 ( struct V_119 * V_80 ,
const struct V_145 * V_146 )
{
static int V_120 ;
struct V_117 * V_118 ;
struct V_1 * V_2 ;
int V_35 ;
if ( V_120 >= V_147 )
return - V_148 ;
if ( ! V_149 [ V_120 ] ) {
V_120 ++ ;
return - V_150 ;
}
V_35 = F_88 ( V_151 [ V_120 ] , V_152 [ V_120 ] , V_153 , 0 , & V_118 ) ;
if ( V_35 < 0 ) {
F_76 (KERN_ERR SFX L_27 ) ;
return V_35 ;
}
F_89 ( V_118 , & V_80 -> V_120 ) ;
V_35 = F_73 ( V_118 , V_80 , V_120 , & V_2 ) ;
if ( V_35 < 0 )
goto V_154;
V_118 -> V_155 = V_2 ;
V_35 = F_51 ( V_2 ) ;
if ( V_35 < 0 )
goto V_154;
V_35 = F_90 ( V_2 ) ;
if ( V_35 < 0 )
goto V_154;
V_35 = F_91 ( V_2 ) ;
if ( V_35 < 0 )
goto V_154;
F_92 ( V_2 ) ;
V_35 = F_93 ( V_118 ) ;
if ( V_35 < 0 )
goto V_154;
F_94 ( V_80 , V_118 ) ;
V_120 ++ ;
return V_35 ;
V_154:
F_95 ( V_118 ) ;
return V_35 ;
}
static void T_4 F_96 ( struct V_119 * V_80 )
{
F_95 ( F_97 ( V_80 ) ) ;
F_94 ( V_80 , NULL ) ;
}
static int T_5 F_98 ( void )
{
return F_99 ( & V_141 ) ;
}
static void T_6 F_100 ( void )
{
F_101 ( & V_141 ) ;
}
